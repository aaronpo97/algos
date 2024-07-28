# Programming Challenge: Left-Handed Typing Word Generator

### Objective

Create a program that filters and generates words which can be typed using only the left-hand keys on a standard QWERTY keyboard.

### Left-Hand Keys

On a standard QWERTY keyboard, the keys that can be typed using only the left hand, assuming proper form are:

```
Q, W, E, R, T, A, S, D, F, G, Z, X, C, V, B
```

### Task Description

1. **Input**: Use the word list available at [this link](https://raw.githubusercontent.com/dwyl/english-words/master/words.txt).
2. **Processing**: Implement a function that verifies if each word in the list can be composed using only the left-hand keys.
3. **Output**: Produce and display a list of words that can be typed with the left hand.

### Example

Words like "tree," "read," and "bad" should be included, while words like "hello" and "right" should be excluded.

### Implementation Tips

- Handle case sensitivity appropriately.
- Consider the dataset size and focus on optimizing the checking process to efficiently handle a large number of words.
