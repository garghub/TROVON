static unsigned long rotate_xor(unsigned long hash, const void *area,
size_t size)
{
size_t i;
unsigned long *ptr = (unsigned long *)area;
for (i = 0; i < size / sizeof(hash); i++) {
hash = (hash << ((sizeof(hash) * 8) - 7)) | (hash >> 7);
hash ^= ptr[i];
}
return hash;
}
static unsigned long get_boot_seed(void)
{
unsigned long hash = 0;
hash = rotate_xor(hash, build_str, sizeof(build_str));
hash = rotate_xor(hash, boot_params, sizeof(*boot_params));
return hash;
}
static bool mem_overlaps(struct mem_vector *one, struct mem_vector *two)
{
if (one->start + one->size <= two->start)
return false;
if (one->start >= two->start + two->size)
return false;
return true;
}
static unsigned long long _memparse(const char *ptr, char **retptr)
{
char *endptr;
unsigned long long ret = simple_strtoull(ptr, &endptr, 0);
switch (*endptr) {
case 'E':
case 'e':
ret <<= 10;
case 'P':
case 'p':
ret <<= 10;
case 'T':
case 't':
ret <<= 10;
case 'G':
case 'g':
ret <<= 10;
case 'M':
case 'm':
ret <<= 10;
case 'K':
case 'k':
ret <<= 10;
endptr++;
default:
break;
}
if (retptr)
*retptr = endptr;
return ret;
}
static int
parse_memmap(char *p, unsigned long long *start, unsigned long long *size)
{
char *oldp;
if (!p)
return -EINVAL;
if (!strncmp(p, "exactmap", 8))
return -EINVAL;
oldp = p;
*size = _memparse(p, &p);
if (p == oldp)
return -EINVAL;
switch (*p) {
case '@':
*start = 0;
*size = 0;
return 0;
case '#':
case '$':
case '!':
*start = _memparse(p + 1, &p);
return 0;
}
return -EINVAL;
}
static void mem_avoid_memmap(void)
{
char arg[128];
int rc;
int i;
char *str;
rc = cmdline_find_option("memmap", arg, sizeof(arg));
if (rc <= 0)
return;
i = 0;
str = arg;
while (str && (i < MAX_MEMMAP_REGIONS)) {
int rc;
unsigned long long start, size;
char *k = strchr(str, ',');
if (k)
*k++ = 0;
rc = parse_memmap(str, &start, &size);
if (rc < 0)
break;
str = k;
if (size == 0)
continue;
mem_avoid[MEM_AVOID_MEMMAP_BEGIN + i].start = start;
mem_avoid[MEM_AVOID_MEMMAP_BEGIN + i].size = size;
i++;
}
if ((i >= MAX_MEMMAP_REGIONS) && str)
memmap_too_large = true;
}
static void mem_avoid_init(unsigned long input, unsigned long input_size,
unsigned long output)
{
unsigned long init_size = boot_params->hdr.init_size;
u64 initrd_start, initrd_size;
u64 cmd_line, cmd_line_size;
char *ptr;
mem_avoid[MEM_AVOID_ZO_RANGE].start = input;
mem_avoid[MEM_AVOID_ZO_RANGE].size = (output + init_size) - input;
add_identity_map(mem_avoid[MEM_AVOID_ZO_RANGE].start,
mem_avoid[MEM_AVOID_ZO_RANGE].size);
initrd_start = (u64)boot_params->ext_ramdisk_image << 32;
initrd_start |= boot_params->hdr.ramdisk_image;
initrd_size = (u64)boot_params->ext_ramdisk_size << 32;
initrd_size |= boot_params->hdr.ramdisk_size;
mem_avoid[MEM_AVOID_INITRD].start = initrd_start;
mem_avoid[MEM_AVOID_INITRD].size = initrd_size;
cmd_line = (u64)boot_params->ext_cmd_line_ptr << 32;
cmd_line |= boot_params->hdr.cmd_line_ptr;
ptr = (char *)(unsigned long)cmd_line;
for (cmd_line_size = 0; ptr[cmd_line_size++]; )
;
mem_avoid[MEM_AVOID_CMDLINE].start = cmd_line;
mem_avoid[MEM_AVOID_CMDLINE].size = cmd_line_size;
add_identity_map(mem_avoid[MEM_AVOID_CMDLINE].start,
mem_avoid[MEM_AVOID_CMDLINE].size);
mem_avoid[MEM_AVOID_BOOTPARAMS].start = (unsigned long)boot_params;
mem_avoid[MEM_AVOID_BOOTPARAMS].size = sizeof(*boot_params);
add_identity_map(mem_avoid[MEM_AVOID_BOOTPARAMS].start,
mem_avoid[MEM_AVOID_BOOTPARAMS].size);
mem_avoid_memmap();
#ifdef CONFIG_X86_VERBOSE_BOOTUP
add_identity_map(0, PMD_SIZE);
#endif
}
static bool mem_avoid_overlap(struct mem_vector *img,
struct mem_vector *overlap)
{
int i;
struct setup_data *ptr;
unsigned long earliest = img->start + img->size;
bool is_overlapping = false;
for (i = 0; i < MEM_AVOID_MAX; i++) {
if (mem_overlaps(img, &mem_avoid[i]) &&
mem_avoid[i].start < earliest) {
*overlap = mem_avoid[i];
earliest = overlap->start;
is_overlapping = true;
}
}
ptr = (struct setup_data *)(unsigned long)boot_params->hdr.setup_data;
while (ptr) {
struct mem_vector avoid;
avoid.start = (unsigned long)ptr;
avoid.size = sizeof(*ptr) + ptr->len;
if (mem_overlaps(img, &avoid) && (avoid.start < earliest)) {
*overlap = avoid;
earliest = overlap->start;
is_overlapping = true;
}
ptr = (struct setup_data *)(unsigned long)ptr->next;
}
return is_overlapping;
}
static void store_slot_info(struct mem_vector *region, unsigned long image_size)
{
struct slot_area slot_area;
if (slot_area_index == MAX_SLOT_AREA)
return;
slot_area.addr = region->start;
slot_area.num = (region->size - image_size) /
CONFIG_PHYSICAL_ALIGN + 1;
if (slot_area.num > 0) {
slot_areas[slot_area_index++] = slot_area;
slot_max += slot_area.num;
}
}
static unsigned long slots_fetch_random(void)
{
unsigned long slot;
int i;
if (slot_max == 0)
return 0;
slot = kaslr_get_random_long("Physical") % slot_max;
for (i = 0; i < slot_area_index; i++) {
if (slot >= slot_areas[i].num) {
slot -= slot_areas[i].num;
continue;
}
return slot_areas[i].addr + slot * CONFIG_PHYSICAL_ALIGN;
}
if (i == slot_area_index)
debug_putstr("slots_fetch_random() failed!?\n");
return 0;
}
static void process_e820_entry(struct boot_e820_entry *entry,
unsigned long minimum,
unsigned long image_size)
{
struct mem_vector region, overlap;
struct slot_area slot_area;
unsigned long start_orig;
if (entry->type != E820_TYPE_RAM)
return;
if (IS_ENABLED(CONFIG_X86_32) && entry->addr >= KERNEL_IMAGE_SIZE)
return;
if (entry->addr + entry->size < minimum)
return;
region.start = entry->addr;
region.size = entry->size;
while (slot_area_index < MAX_SLOT_AREA) {
start_orig = region.start;
if (region.start < minimum)
region.start = minimum;
region.start = ALIGN(region.start, CONFIG_PHYSICAL_ALIGN);
if (region.start > entry->addr + entry->size)
return;
region.size -= region.start - start_orig;
if (IS_ENABLED(CONFIG_X86_32) &&
region.start + region.size > KERNEL_IMAGE_SIZE)
region.size = KERNEL_IMAGE_SIZE - region.start;
if (region.size < image_size)
return;
if (!mem_avoid_overlap(&region, &overlap)) {
store_slot_info(&region, image_size);
return;
}
if (overlap.start > region.start + image_size) {
struct mem_vector beginning;
beginning.start = region.start;
beginning.size = overlap.start - region.start;
store_slot_info(&beginning, image_size);
}
if (overlap.start + overlap.size >= region.start + region.size)
return;
region.size -= overlap.start - region.start + overlap.size;
region.start = overlap.start + overlap.size;
}
}
static unsigned long find_random_phys_addr(unsigned long minimum,
unsigned long image_size)
{
int i;
unsigned long addr;
if (memmap_too_large) {
debug_putstr("Aborted e820 scan (more than 4 memmap= args)!\n");
return 0;
}
minimum = ALIGN(minimum, CONFIG_PHYSICAL_ALIGN);
for (i = 0; i < boot_params->e820_entries; i++) {
process_e820_entry(&boot_params->e820_table[i], minimum,
image_size);
if (slot_area_index == MAX_SLOT_AREA) {
debug_putstr("Aborted e820 scan (slot_areas full)!\n");
break;
}
}
return slots_fetch_random();
}
static unsigned long find_random_virt_addr(unsigned long minimum,
unsigned long image_size)
{
unsigned long slots, random_addr;
minimum = ALIGN(minimum, CONFIG_PHYSICAL_ALIGN);
image_size = ALIGN(image_size, CONFIG_PHYSICAL_ALIGN);
slots = (KERNEL_IMAGE_SIZE - minimum - image_size) /
CONFIG_PHYSICAL_ALIGN + 1;
random_addr = kaslr_get_random_long("Virtual") % slots;
return random_addr * CONFIG_PHYSICAL_ALIGN + minimum;
}
void choose_random_location(unsigned long input,
unsigned long input_size,
unsigned long *output,
unsigned long output_size,
unsigned long *virt_addr)
{
unsigned long random_addr, min_addr;
if (cmdline_find_option_bool("nokaslr")) {
warn("KASLR disabled: 'nokaslr' on cmdline.");
return;
}
boot_params->hdr.loadflags |= KASLR_FLAG;
initialize_identity_maps();
mem_avoid_init(input, input_size, *output);
min_addr = min(*output, 512UL << 20);
random_addr = find_random_phys_addr(min_addr, output_size);
if (!random_addr) {
warn("Physical KASLR disabled: no suitable memory region!");
} else {
if (*output != random_addr) {
add_identity_map(random_addr, output_size);
*output = random_addr;
}
finalize_identity_maps();
}
if (IS_ENABLED(CONFIG_X86_64))
random_addr = find_random_virt_addr(LOAD_PHYSICAL_ADDR, output_size);
*virt_addr = random_addr;
}
