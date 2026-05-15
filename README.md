# Password Generator

A command-line password generator written in C, built as part of a cybersecurity awareness workshop for the Teen Coding Club.

## What it does

- Lets the user choose which character types to include (lowercase, uppercase, numbers, special characters)
- Generates 1 to 20 passwords at once at any length up to 255 characters
- Rates each password as **Weak**, **Medium**, or **Strong** based on length and character variety
- Uses a time-seeded random number generator across a charset of up to 90 characters

## Why I built it

I founded the Teen Coding Club to get young people interested in technology through hands-on projects. Cybersecurity is one of the topics students care about most but understand the least. I built this tool to give them something real to run, modify, and break — not just read about. After the workshop, 10+ students reported a 90% improvement in their understanding of password security.

## How to run it

You need a C compiler (gcc works).

```bash
gcc password_generator.c -o password_generator
./password_generator
```

On Windows:
```bash
gcc password_generator.c -o password_generator.exe
password_generator.exe
```

## Example output

```
=== Password Generator ===

Include lowercase letters (y/n): y
Include uppercase letters (y/n): y
Include numbers (y/n): y
Include special characters (y/n): y

Enter desired password length (1-255): 16
How many passwords do you want to generate? 3

--- Generated Passwords ---

  Password 1: kR7!mXq2@Lv#9pWs
  Strength: STRONG

  Password 2: 4Tz&bNj8*Yw!3Qhm
  Strength: STRONG

  Password 3: Gx5#pMk1@Rn!7Zcv
  Strength: STRONG

Charset size: 90 characters
```

## What the code covers

- Manual character array construction and bounds checking
- Time-seeded random number generation (`srand` + `time`)
- Input validation and error handling
- Modular functions (`buildCharset`, `checkStrength`, `printStrength`)
- Proper null termination and memory safety

## Tech

`C` `gcc` `command-line`
