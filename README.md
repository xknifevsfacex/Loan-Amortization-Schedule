# Financial Loan Amortization Calculator

A real-world C++ financial tool that computes monthly loan payments and builds a complete month-by-month amortization schedule. This application showcases object-oriented programming (OOP), mathematical algorithm modeling, structural data vectors, and file export utilities.

## Key Highlights & Concepts Demonstrated

* **File I/O Systems (`std::ofstream`)**: Features an export module that dynamically generates and structures financial data into an external `.csv` file format for integration with Microsoft Excel or Google Sheets.
* **Algorithmic Math & Formatting**: Implements core financial formulas using `<cmath>` functions to accurately process compounding interest rates, alongside `<iomanip>` stream manipulators (`fixed`, `setprecision`) to enforce proper two-decimal currency formatting.
* **Encapsulated Object-Oriented Design**: Utilizes a clean `Loan` class that abstracts core variables (principal, APR, loan term) and manages a relational vector of custom `Payment` structures representing the chronological schedule.

## Tech Stack

* **Language**: C++
* **IDE**: Visual Studio 2026
* **Compiler**: MSVC

## How to Run This Project

1. Open Visual Studio 2026.
2. Go to File > Open > Project/Solution and choose your directory.
3. Press F5 to compile and launch the interactive calculator.

## Sample Visual Flow

```text
*---* Loan Amortization Schedule Calculator *---*

Loan amount: 5000
APR (%): 5.5
Years (3, 5, 7): 3

*-----------* Your Payment Schedule *-----------*

Total interest paid: \$434.21

Month | Payment | Interest | Principal | Balance
-------------------------------------------------
1  | \$150.95  | \$22.92  | \$128.03  | \$4871.97
2  | \$150.95  | \$22.33  | \$128.62  | \$4743.35
...
36  | \$150.95  | \$0.69  | \$150.26  | \$0.00

Save to CSV? (y/n): y
```
