static inline u16 i8254(void)
{
u16 status, timer;
do {
outb(I8254_PORT_CONTROL,
I8254_CMD_READBACK | I8254_SELECT_COUNTER0);
status = inb(I8254_PORT_COUNTER0);
timer = inb(I8254_PORT_COUNTER0);
timer |= inb(I8254_PORT_COUNTER0) << 8;
} while (status & I8254_STATUS_NOTREADY);
return timer;
}
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
static unsigned long get_random_boot(void)
{
unsigned long hash = 0;
hash = rotate_xor(hash, build_str, sizeof(build_str));
hash = rotate_xor(hash, boot_params, sizeof(*boot_params));
return hash;
}
static unsigned long get_random_long(const char *purpose)
{
#ifdef CONFIG_X86_64
const unsigned long mix_const = 0x5d6008cbf3848dd3UL;
#else
const unsigned long mix_const = 0x3f39e593UL;
#endif
unsigned long raw, random = get_random_boot();
bool use_i8254 = true;
debug_putstr(purpose);
debug_putstr(" KASLR using");
if (has_cpuflag(X86_FEATURE_RDRAND)) {
debug_putstr(" RDRAND");
if (rdrand_long(&raw)) {
random ^= raw;
use_i8254 = false;
}
}
if (has_cpuflag(X86_FEATURE_TSC)) {
debug_putstr(" RDTSC");
raw = rdtsc();
random ^= raw;
use_i8254 = false;
}
if (use_i8254) {
debug_putstr(" i8254");
random ^= i8254();
}
asm("mul %3"
: "=a" (random), "=d" (raw)
: "a" (random), "rm" (mix_const));
random += raw;
debug_putstr("...\n");
return random;
}
static bool mem_contains(struct mem_vector *region, struct mem_vector *item)
{
if (item->start < region->start)
return false;
if (item->start + item->size > region->start + region->size)
return false;
return true;
}
static bool mem_overlaps(struct mem_vector *one, struct mem_vector *two)
{
if (one->start + one->size <= two->start)
return false;
if (one->start >= two->start + two->size)
return false;
return true;
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
static void slots_append(unsigned long addr)
{
if (slot_max >= KERNEL_IMAGE_SIZE / CONFIG_PHYSICAL_ALIGN)
return;
slots[slot_max++] = addr;
}
static unsigned long slots_fetch_random(void)
{
if (slot_max == 0)
return 0;
return slots[get_random_long("Physical") % slot_max];
}
static void process_e820_entry(struct e820entry *entry,
unsigned long minimum,
unsigned long image_size)
{
struct mem_vector region, img, overlap;
if (entry->type != E820_RAM)
return;
if (entry->addr >= KERNEL_IMAGE_SIZE)
return;
if (entry->addr + entry->size < minimum)
return;
region.start = entry->addr;
region.size = entry->size;
if (region.start < minimum)
region.start = minimum;
region.start = ALIGN(region.start, CONFIG_PHYSICAL_ALIGN);
if (region.start > entry->addr + entry->size)
return;
region.size -= region.start - entry->addr;
if (region.start + region.size > KERNEL_IMAGE_SIZE)
region.size = KERNEL_IMAGE_SIZE - region.start;
for (img.start = region.start, img.size = image_size ;
mem_contains(&region, &img) ;
img.start += CONFIG_PHYSICAL_ALIGN) {
if (mem_avoid_overlap(&img, &overlap))
continue;
slots_append(img.start);
}
}
static unsigned long find_random_phys_addr(unsigned long minimum,
unsigned long image_size)
{
int i;
unsigned long addr;
minimum = ALIGN(minimum, CONFIG_PHYSICAL_ALIGN);
for (i = 0; i < boot_params->e820_entries; i++) {
process_e820_entry(&boot_params->e820_map[i], minimum,
image_size);
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
random_addr = get_random_long("Virtual") % slots;
return random_addr * CONFIG_PHYSICAL_ALIGN + minimum;
}
unsigned char *choose_random_location(unsigned long input,
unsigned long input_size,
unsigned long output,
unsigned long output_size)
{
unsigned long choice = output;
unsigned long random_addr;
#ifdef CONFIG_HIBERNATION
if (!cmdline_find_option_bool("kaslr")) {
warn("KASLR disabled: 'kaslr' not on cmdline (hibernation selected).");
goto out;
}
#else
if (cmdline_find_option_bool("nokaslr")) {
warn("KASLR disabled: 'nokaslr' on cmdline.");
goto out;
}
#endif
boot_params->hdr.loadflags |= KASLR_FLAG;
mem_avoid_init(input, input_size, output);
random_addr = find_random_phys_addr(output, output_size);
if (!random_addr) {
warn("KASLR disabled: could not find suitable E820 region!");
goto out;
}
if (random_addr < choice)
goto out;
choice = random_addr;
add_identity_map(choice, output_size);
finalize_identity_maps();
out:
return (unsigned char *)choice;
}
