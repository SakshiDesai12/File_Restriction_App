#include <windows.h>
#include <iostream>
#include <string>

const std::string ROOT_DIRECTORY = "C:\\Users\\admin\\Desktop\\FileRestrictionApp\\ProtectedRoot"
;

bool IsPathInRoot(const std::string& path) {
    return path.find(ROOT_DIRECTORY) == 0;
}

bool PreventFileCopy(const std::string& sourcePath) {
    if (!IsPathInRoot(sourcePath)) {
        std::cout << "Copying outside of the root directory is restricted!" << std::endl;
        return true;
    }
    
    return false;
}

std::string GetClipboardText() {
    if (!OpenClipboard(nullptr)) return "";

    HANDLE hData = GetClipboardData(CF_TEXT);
    if (hData == nullptr) return "";

    char* pszText = static_cast<char*>(GlobalLock(hData));
    if (pszText == nullptr) return "";

    std::string text(pszText);

    GlobalUnlock(hData);
    CloseClipboard();

    return text;
}

void MonitorClipboard() {
    std::string lastContent;
    while (true) {
        if (IsClipboardFormatAvailable(CF_TEXT)) {
            std::string currentContent = GetClipboardText();
            if (currentContent != lastContent) {
                lastContent = currentContent;
                std::cout << "Clipboard text detected: " << currentContent << std::endl;
                
                if (PreventFileCopy(currentContent)) {
                    OpenClipboard(nullptr);
                    EmptyClipboard();
                    CloseClipboard();
                }
            }
        }
        Sleep(500);
    }
}

int main() {
    std::cout << "Monitoring clipboard for restricted file operations..." << std::endl;
    MonitorClipboard();
    return 0;
}
