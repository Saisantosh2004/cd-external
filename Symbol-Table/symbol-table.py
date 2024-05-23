class SymbolTable:
    def __init__(self):
        self.symbols = {}

    def insert(self, name, type, scope):
        if name in self.symbols:
            print(f"Error: Symbol '{name}' already exists in the symbol table.")
        else:
            self.symbols[name] = {'type': type, 'scope': scope}

    def lookup(self, name):
        if name in self.symbols:
            return self.symbols[name]
        else:
            print(f"Error: Symbol '{name}' not found in the symbol table.")
            return None

    def display(self):
        print("Symbol Table:")
        print("Name\t|\tType\t|\tScope")
        print("-" * 30)
        for name, info in self.symbols.items():
            print(f"{name}\t|\t{info['type']}\t|\t{info['scope']}")


# Create a symbol table instance
symbol_table = SymbolTable()

# Insert symbols
symbol_table.insert('x', 'int', 'global')
symbol_table.insert('y', 'float', 'local')
symbol_table.insert('z', 'char', 'global')

# Lookup symbols
print(symbol_table.lookup('x'))  # Output: {'type': 'int', 'scope': 'global'}
print(symbol_table.lookup('a'))  # Error: Symbol 'a' not found in the symbol table.

# Display symbol table
symbol_table.display()