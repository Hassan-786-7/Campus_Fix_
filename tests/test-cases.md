# CampusFix Test Cases and Results

## Test environment
- Compiler: g++ with `-std=c++11 -Wall -Wextra -pedantic`
- Build command: `g++ -std=c++11 -Wall -Wextra -pedantic main.cpp -o CampusFix`
- Initial data: supplied sample complaint ID 1001 (Hassan, Electricity, 403 Block V, Resolved).
- Each test ran in a separate clean temporary copy so tests did not affect one another.

## Executed test cases

| Test | Action / input | Expected result | Actual result | Result |
|---|---|---|---|---|
| T1 | Submit Ayesha Khan's Furniture complaint for Block A Room 12: “Broken chair” | New complaint saved with ID 1002 and Pending status | Success message displayed; ID 1002 assigned; process exited normally | PASS |
| T2 | Track existing complaint ID 1001 | Existing complaint details displayed | Hassan's complaint found and Resolved status displayed | PASS |
| T3 | Open admin panel with PIN 1234; update ID 1001 to In Progress | Status update succeeds | Access granted; success message and “New Status: In Progress” displayed | PASS |
| T4 | Enter an incorrect administrator PIN three times | Access denied after three attempts | Three-attempt limit message displayed; program returned to main menu | PASS |
| T5 | Search by location fragment “403” | Matching complaint at 403 Block V displayed | Complaint ID 1001 and Hassan's 403 Block V record displayed | PASS |

## Overall result
**5 of 5 test cases passed** in the local execution described above. The project compiled without compiler errors or warnings using the command shown. Results may vary if the source, compiler, input data or runtime environment changes.

## Reproduction note
Compile using the command in `README.md`, then repeat the inputs described in the table. Use a fresh copy of `complaints.txt` for each test to reproduce the same starting state.
