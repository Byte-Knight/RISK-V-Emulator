# RISC-V Emulator

This repository contains a custom implementation of a RISC-V instruction set emulator, built to decode, execute, and test RISC-V instructions. It includes features for instruction parsing, execution, memory management, and testing.

## Features

- **Instruction Decoding**: Handles multiple instruction formats (R-type, I-type, S-type, SB-type, U-type, UJ-type).
- **Instruction Execution**: Implements various operations, including arithmetic, logical, and memory instructions.
- **Custom SLT Instruction**: Adds support for a custom load-modify-store instruction (`lsgt`) with opcode `0x2a`.
- **Memory Management**: Allocates memory dynamically and provides utilities for loading and storing values.
- **Error Handling**: Detects and handles invalid instructions, reads, and writes.
- **Testing Framework**: Includes unit tests for key utilities and instruction parsing.
- **Shell Script Automation**: Automates build and testing with `run.sh`.
- **Driver Script**: Validates the emulator using `driver.py`, which executes predefined test cases and compares results.
- **Trace Validation**: Ensures output correctness with `part2_tester.py`.

## File Structure

### Source Code

- **`part1.c`**: Decodes instructions and prints their formats.
- **`part2.c`**: Executes instructions and handles CPU state updates.
- **`riscv.c`**: Main entry point for the emulator, including initialization, argument parsing, and execution loop.
- **`utils.c`**: Implements utility functions for instruction parsing and memory operations.
- **`compare.py`**: Compares two files for differences, used to validate test outputs.

### Headers

- **`riscv.h`**: Function declarations for instruction decoding and execution.
- **`utils.h`**: Utility function declarations and macros for formatting.
- **`types.h`**: Defines data types, processor structure, and instruction format.

### Tests

- **`test_utils.c`**: Unit tests for instruction parsing and utility functions using the CUnit framework.
- **`part2_tester.py`**: Validates trace output against reference data to ensure execution correctness.

### Scripts

- **`run.sh`**: Automates the build process and test execution.
- **`install-cunit.sh`**: Installs the CUnit testing framework.
- **`driver.py`**: Executes and grades the emulator's performance on various test cases.

### Documentation

- **`DisassembleFlowchart.pdf`**: Provides a visual guide to RISC-V instruction disassembly.

## Prerequisites

- C Compiler (e.g., GCC)
- CUnit testing framework
- Python (for running the driver and comparison scripts)
- Make (for build automation)

## Setup and Usage

### Build the Emulator

```bash
make riscv
```

### Run the Emulator

To execute a program:

```bash
./riscv <executable_file>
```

Additional options:

- `-d`: Disassemble instructions.
- `-r`: Print register dump.
- `-i`: Interactive mode (step through execution).
- `-s <data_file>`: Load data from a file.
- `-a <arg1,arg2,...>`: Initialize register arguments.

### Run Tests

Compile and execute tests using `run.sh`:

```bash
bash run.sh
```

### Install CUnit

To install the CUnit testing framework:

```bash
bash install-cunit.sh
```

### Examples

To run a program in interactive mode with a register dump:

```bash
./riscv -i -r program.bin
```

To load a program and disassemble it:

```bash
./riscv -d program.bin
```

## Custom SLT Instruction

The custom instruction `lsgt` performs a load-modify-store operation. It compares a register value with memory and conditionally updates the destination register.

- **Opcode**: `0x2a`
- **Funct3**: `0x4`
- **Funct7**: `0x0`

## Testing

The testing framework ensures the correctness of key utilities and instruction parsing. To extend tests, add cases in `test_utils.c` and recompile. Additionally, use `driver.py` and `part2_tester.py` to validate trace outputs against reference implementations.

## Contributions

Contributions are welcome! Feel free to submit issues or pull requests to improve the emulator.

## License

This project is licensed under the MIT License.

## Acknowledgements

This emulator project was developed as part of a self-initiated effort to understand RISC-V architecture and instruction set implementation. It serves as a showcase of skills in low-level programming and systems design.

