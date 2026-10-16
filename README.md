# Vigenère Cipher in C

A command-line Vigenère cipher written in C. It encrypts and decrypts text with a
repeating key and has two modes:

| Mode | What it encrypts | How the key is used |
|------|------------------|---------------------|
| 1: Basic alphabetic | Letters A–Z (and a–z); other characters are left alone | Each key letter's position (A=0 … Z=25) is the shift |
| 2: Advanced ASCII | All printable ASCII characters (32–126) | Each key character's ASCII value is the shift |

The key repeats if the message is longer than the key. The program prints the encrypted
text and then decrypts it again to show the round trip.

## Build and run

```bash
gcc lithuania.c -o vigenere
./vigenere          # on Windows: vigenere.exe
```

Then follow the prompts: enter the text, enter the key (uppercase letters recommended for
basic mode), and choose mode 1 or 2.

## Requirements

- A C compiler (GCC, Clang, or MSVC). The code only uses `stdio.h` and `string.h`.
- No accounts, packages or API keys.

## Notes

- Written as a small exercise during my Erasmus+ semester at Vilniaus kolegija (VIKO), Lithuania.
- The Vigenère cipher is historical and easy to break. It is here to practice string handling
  and modular arithmetic, not for protecting real data.
- Input is limited to 1000 characters (`MAX_TEXT`).
