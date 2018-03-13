This is a very simple context-free grammar string generator. If you feed it a file
describing your grammar, it will generate a string built on your grammar!

The syntax for the grammar files are as follows:

* Rules start with an underscore: `_`
* Clauses are separated with a vertical bar `|`
* Rules must end with a semicolon `;`

Example:

```
_greeting = hello
          | hola
          | bonjour
          | salutations
          | _shout
          ;

_shout    = ah!
          ;
```

The whitespace formatting is not required, but it does make it easier to read.

## Usage

Once the program is built, run it and pass in the path to the grammar file that you want to run.

Example:

`./gencfg greeting.txt`
