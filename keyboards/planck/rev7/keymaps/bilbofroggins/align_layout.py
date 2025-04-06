import re

def align_line(line):
    # Only process lines with keycodes, not comments or blanks
    if not line.strip() or line.strip().startswith('//'):
        return line

    parts = re.split(r'(\s*,\s*)', line)  # Split by commas but keep them
    keys = parts[::2]  # every other part is a key
    commas = parts[1::2] + ['']  # every other part is a comma (plus last empty)

    # Find max width for each column
    max_lengths = []
    for key in keys:
        key = key.strip()
        while len(max_lengths) < len(keys):
            max_lengths.append(0)
        col = keys.index(key)
        max_lengths[col] = max(max_lengths[col], len(key))

    # Rebuild the line with aligned keys
    out = ''
    for i, key in enumerate(keys):
        key = key.strip().ljust(max_lengths[i])
        out += key
        if i < len(commas):
            out += commas[i]
    return out

def align_block(block):
    return '\n'.join(align_line(line) for line in block.splitlines())

# Example usage:
if __name__ == "__main__":
    input_file = "keymap.c"
    output_file = "keymap_aligned.c"

    with open(input_file, "r") as f:
        content = f.read()

    # This assumes your layout blocks start with LAYOUT_planck_2x2u(
    blocks = re.split(r'(LAYOUT_planck_2x2u\()', content)
    new_content = blocks[0]

    for i in range(1, len(blocks), 2):
        new_content += blocks[i]
        # split at the next closing paren
        closing = blocks[i+1].find(')')
        block = blocks[i+1][:closing]
        rest = blocks[i+1][closing:]

        aligned = align_block(block)
        new_content += aligned + rest

    with open(output_file, "w") as f:
        f.write(new_content)