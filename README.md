# Lunch-Combination-Finder

One-line description: A C++ program that generates valid combinations of lunch items using recursive functions and prunes invalid combinations early to enhance performance.

Summary: This C++ program uses recursion to generate all possible combinations of lunch items from predefined categories: sandwiches, snacks, drinks, and desserts. Each combination is represented as a vector of strings. The program defines two recursive functions, `findLunchesNoPrune` and `findLunchesWithPrune`, to explore these combinations without and with pruning invalid combinations based on specified conditions.

**Key Features:**
- **Data Structure Setup:** Lunch items are stored in vectors and indexed by category. The current lunch combination is maintained in a vector called `currentLunch`.
- **Pruning Logic:** The `isValidLunch` function checks if a given combination is valid based on specific rules, such as certain items not being allowed with others.
- **Recursive Combinations:** `findLunchesNoPrune` generates all possible combinations, printing each complete lunch set as a tree structure. `findLunchesWithPrune` optimizes this process by stopping the recursion early if the current combination is invalid.
- **Performance Measurement:** The program measures and compares t
