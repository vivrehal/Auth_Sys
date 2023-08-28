
# Auth_Sys C Program

## Unveiling Auth_Sys: Your Secure Vault for User Magic

Welcome to the world of Auth_Sys, where registering users and guarding passwords become a breeze. Our C program brings a touch of encryption wizardry and a sprinkle of command-line charm to keep your system secure.

## Our Aim: Solid Authentication, Sneaky Passwords

**Goal**: Auth_Sys is your trusty sidekick for local authentication. Our focus? **Authentication and Password Security**. 

## What's Cooking: Specs at a Glance

- **Authenticate**: Register users with usernames and passwords, then greet them with a secure login.
- **Lock & Key**: Secrets stay safe with our custom "vcrypt" encryption. Bit by bit, it guards your passwords with style.

## Meet "vcrypt.h": The Password Magician

- "vcrypt" is our secret recipe. It's a crafty encryption tool custom-made to turn passwords into enigmatic wonders. A sprinkle of bit tricks and a dash of XOR magic – your password is a mystery, even to us!

## How to Weave Your Spell

### Casting the Code: Compiling Auth_Sys and "vcrypt"

```bash
gcc -c vcrypt.c -o vcrypt.o
ar rcs libvcrypt.a vcrypt.o
gcc auth_sys.c -o auth_sys -L. -lvcrypt

./auth_sys
```

### The Ritual: From Registration to Login

1. Enroll with your username and password – let "vcrypt" weave its spell.
2. Return to the realm of Auth_Sys, utter your username and unveil your password's cryptic dance.

## Enhance Your Arsenal: "vcrypt" as a Secret Weapon

1. Brew "vcrypt" essence: `gcc -c vcrypt.c -o vcrypt.o`.
2. Enchant it: `ar rcs libvcrypt.a vcrypt.o`.
3. Enshroud Auth_Sys: `gcc auth_sys.c -o auth_sys -L. -lvcrypt`.

## Join Our Quest: Contribute and Contact

Step into the adventure! Whether you refine our encryption epic or add your chapter, we're here to collaborate.

---

