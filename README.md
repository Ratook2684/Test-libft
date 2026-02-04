✨ What they contain:
For EACH function, you have:

📖 Description: What the function does
🎯 PURPOSE: What it's used for
📥 PARAMETERS: What it receives
📤 RETURN: What it returns
⚙️ HOW IT WORKS: How it operates
⚠️ WARNINGS: Points to be aware of (free, NULL, etc.)
💡 EXAMPLES: Concrete tests with expected results

# For required functions
gcc -Wall -Wextra -Werror libft-test.c -L. -lft -o test_libft

./test_libft

# For bonus functions
gcc -Wall -Wextra -Werror main_test_bonus_explique.c -L. -lft -o test_bonus

./test_bonus

Important note: 
⚠️These files can be used after running "make", then place them in the same folder as your output files.
  Make sure that:

  Your libft.h file contains all the prototypes.

  Your libft.a file is properly compiled.
