# CampusFix — University Maintenance System

## Project overview
CampusFix is a menu-driven C++ console application for submitting and managing university maintenance complaints. A student can submit a complaint with a name, category, building/room location and problem description, then use its complaint ID to track progress. The application also provides search, filtering and maintenance reporting. An administrator panel is protected by a PIN and can update complaint status.

## Features
- Submit complaints with an automatically generated ID (starting at 1001).
- Choose Electricity, Furniture, AC / Fan, Projector / Computer, Water Supply, or Other.
- View all saved complaints and track a complaint by ID.
- Search by complaint ID or by a location fragment.
- Filter complaints by Pending, In Progress, or Resolved status.
- Administrator panel to view complaints, update status and generate a maintenance report.
- Count complaints by status and category and identify the most reported category.
- Save complaint records in `complaints.txt` and load them at program startup.
- Validate numeric menu inputs and reject blank text fields.
- Limit storage to 100 complaint records.

## Requirements
- A C++ compiler such as g++ (MinGW on Windows).
- C++11 or later.
- A terminal / command prompt.

## How to compile and run
The submitted `main.cpp` includes `Functions.cpp` directly. Compile **main.cpp only**; do not also list `Functions.cpp` in the compile command.

### Windows (MinGW)
```powershell
g++ -std=c++11 -Wall -Wextra -pedantic main.cpp -o CampusFix.exe
.\CampusFix.exe
```

### Linux / macOS
```bash
g++ -std=c++11 -Wall -Wextra -pedantic main.cpp -o CampusFix
./CampusFix
```
Run the executable from the project directory so it can read and write `complaints.txt`.

## Administrator access
The current source uses the demonstration PIN `1234`, stored in `CampusFix.h`. Change it before using the program outside a classroom demonstration. Three attempts are allowed per administrator-panel entry.

## Data file
`complaints.txt` stores six lines per complaint: ID, student name, category, location, description and status. Keep it beside the executable. One sample record is included.

## Repository contents
- `main.cpp` — main menu and program entry point.
- `CampusFix.h` — complaint structure, constants and function declarations.
- `Functions.cpp` — input, complaint, search, filter, reporting, administrator and file functions.
- `complaints.txt` — sample complaint data.
- `REPORT.pdf` — IEEE-style project report.
- `docs/flowchart.png` — program flowchart.
- `screenshots/` — console output captures from executed sessions.
- `tests/test-cases.md` — five executed test cases and results.
- `AI_DISCLOSURE.md` — disclosure of AI assistance used to prepare this package.

## Current limitations
- Console-based; no graphical interface or online student portal.
- Administrator PIN is hard-coded as plain text and is not secure authentication.
- Text-file storage has no encryption, backup, concurrency handling or database.
- Fixed array supports at most 100 complaints.
- Names and descriptions are single-line text.
- No timestamps, contact details, attachments or status-change history.
- Location search is a case-sensitive substring search.
