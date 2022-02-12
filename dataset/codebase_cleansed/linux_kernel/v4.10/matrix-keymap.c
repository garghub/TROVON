static bool matrix_keypad_map_key(struct input_dev *input_dev,
unsigned int rows, unsigned int cols,
unsigned int row_shift, unsigned int key)
{
unsigned short *keymap = input_dev->keycode;
unsigned int row = KEY_ROW(key);
unsigned int col = KEY_COL(key);
unsigned short code = KEY_VAL(key);
if (row >= rows || col >= cols) {
dev_err(input_dev->dev.parent,
"%s: invalid keymap entry 0x%x (row: %d, col: %d, rows: %d, cols: %d)\n",
__func__, key, row, col, rows, cols);
return false;
}
keymap[MATRIX_SCAN_CODE(row, col, row_shift)] = code;
__set_bit(code, input_dev->keybit);
return true;
}
int matrix_keypad_parse_of_params(struct device *dev,
unsigned int *rows, unsigned int *cols)
{
struct device_node *np = dev->of_node;
if (!np) {
dev_err(dev, "missing DT data");
return -EINVAL;
}
of_property_read_u32(np, "keypad,num-rows", rows);
of_property_read_u32(np, "keypad,num-columns", cols);
if (!*rows || !*cols) {
dev_err(dev, "number of keypad rows/columns not specified\n");
return -EINVAL;
}
return 0;
}
static int matrix_keypad_parse_of_keymap(const char *propname,
unsigned int rows, unsigned int cols,
struct input_dev *input_dev)
{
struct device *dev = input_dev->dev.parent;
struct device_node *np = dev->of_node;
unsigned int row_shift = get_count_order(cols);
unsigned int max_keys = rows << row_shift;
unsigned int proplen, i, size;
const __be32 *prop;
if (!np)
return -ENOENT;
if (!propname)
propname = "linux,keymap";
prop = of_get_property(np, propname, &proplen);
if (!prop) {
dev_err(dev, "OF: %s property not defined in %s\n",
propname, np->full_name);
return -ENOENT;
}
if (proplen % sizeof(u32)) {
dev_err(dev, "OF: Malformed keycode property %s in %s\n",
propname, np->full_name);
return -EINVAL;
}
size = proplen / sizeof(u32);
if (size > max_keys) {
dev_err(dev, "OF: %s size overflow\n", propname);
return -EINVAL;
}
for (i = 0; i < size; i++) {
unsigned int key = be32_to_cpup(prop + i);
if (!matrix_keypad_map_key(input_dev, rows, cols,
row_shift, key))
return -EINVAL;
}
return 0;
}
static int matrix_keypad_parse_of_keymap(const char *propname,
unsigned int rows, unsigned int cols,
struct input_dev *input_dev)
{
return -ENOSYS;
}
int matrix_keypad_build_keymap(const struct matrix_keymap_data *keymap_data,
const char *keymap_name,
unsigned int rows, unsigned int cols,
unsigned short *keymap,
struct input_dev *input_dev)
{
unsigned int row_shift = get_count_order(cols);
size_t max_keys = rows << row_shift;
int i;
int error;
if (WARN_ON(!input_dev->dev.parent))
return -EINVAL;
if (!keymap) {
keymap = devm_kzalloc(input_dev->dev.parent,
max_keys * sizeof(*keymap),
GFP_KERNEL);
if (!keymap) {
dev_err(input_dev->dev.parent,
"Unable to allocate memory for keymap");
return -ENOMEM;
}
}
input_dev->keycode = keymap;
input_dev->keycodesize = sizeof(*keymap);
input_dev->keycodemax = max_keys;
__set_bit(EV_KEY, input_dev->evbit);
if (keymap_data) {
for (i = 0; i < keymap_data->keymap_size; i++) {
unsigned int key = keymap_data->keymap[i];
if (!matrix_keypad_map_key(input_dev, rows, cols,
row_shift, key))
return -EINVAL;
}
} else {
error = matrix_keypad_parse_of_keymap(keymap_name, rows, cols,
input_dev);
if (error)
return error;
}
__clear_bit(KEY_RESERVED, input_dev->keybit);
return 0;
}
