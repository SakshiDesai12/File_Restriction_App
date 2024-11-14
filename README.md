# File_Restriction_App

## Objective

The File Restriction App is designed to monitor clipboard activity on Windows, specifically restricting copy-paste operations for files located in a specified "root" directory. This prevents any files within this directory from being pasted outside it, enforcing data security within the defined directory.

## Technologies Used
- **Programming Language**: C++
- **Operating System**: Windows 11
- **Libraries**: Windows API (for clipboard and system-level monitoring)

## Features
- Monitors clipboard activity to detect file copy operations.
- Restricts pasting of files outside a designated "root" directory.
- Displays console messages to indicate allowed and restricted actions.

## Setup Instructions

### 1. Prerequisites
- **C++ Compiler**: MinGW (recommended) or Visual Studio.
- **VS Code (optional)**: If using Visual Studio Code, install the **C/C++** extension by Microsoft for better code support.
  
### 2. Clone the Repository
   ```bash
   git clone https://github.com/yourusername/FileRestrictionApp.git
   cd FileRestrictionApp
   ```

### 3. Build and Run
#### Using Command Prompt or VS Code Terminal:
1. **Compile the code**:
   ```bash
   g++ -g main.cpp -o main.exe
   ```

2. **Run the executable**:
   ```bash
   .\main.exe
   ```

The program will start monitoring clipboard activity and restrict file copy-paste operations according to the code logic.

## Usage Guide

1. **Copy a File Inside the Root Directory**:
   - Right-click a file in the designated root directory (e.g., `C:\ProtectedRoot`) and select **Copy**.

2. **Attempt to Paste Outside the Root Directory**:
   - Go to any other directory and try to **Paste** the copied file.
   - If the paste location is outside the root directory, the program will clear the clipboard, preventing the paste operation, and display a restriction message.

3. **Expected Console Output**:
   - If a file is within the root directory, the console will allow copying and display a message.
   - If a file is outside the root directory, you should see an output like:
     ```
     Copying outside of the root directory is restricted!
     ```

## Evaluation Criteria
This project demonstrates:
- **System Hooks Usage**: Intercepts clipboard activity using Windows API.
- **Clipboard Monitoring**: Regularly checks clipboard content and restricts unauthorized file transfer.
- **Code Structure**: Clear, modular code with checks for security and smooth system operation.

## Assumptions and Limitations
- The "root" directory is set to `C:\ProtectedRoot`. Modify this path in the code if necessary.
- The program currently monitors text-based clipboard content and basic file paths.
- Tested only on Windows 11, as required by the assignment.

## Additional Information
### Safety Considerations
- The program uses Windows API for clipboard access, so it requires appropriate permissions. Running as Administrator might be necessary if access is restricted.

### Future Enhancements
- Expanding clipboard monitoring to handle complex file formats.
- Adding background service functionality for consistent monitoring.

---

Save this as `README.md` in your GitHub repository, and it should meet the requirements specified. Let me know if you need any further customization!
