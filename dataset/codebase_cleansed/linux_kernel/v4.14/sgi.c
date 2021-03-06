int sgi_partition(struct parsed_partitions *state)
{
int i, csum;
__be32 magic;
int slot = 1;
unsigned int start, blocks;
__be32 *ui, cs;
Sector sect;
struct sgi_disklabel *label;
struct sgi_partition *p;
char b[BDEVNAME_SIZE];
label = read_part_sector(state, 0, &sect);
if (!label)
return -1;
p = &label->partitions[0];
magic = label->magic_mushroom;
if(be32_to_cpu(magic) != SGI_LABEL_MAGIC) {
put_dev_sector(sect);
return 0;
}
ui = ((__be32 *) (label + 1)) - 1;
for(csum = 0; ui >= ((__be32 *) label);) {
cs = *ui--;
csum += be32_to_cpu(cs);
}
if(csum) {
printk(KERN_WARNING "Dev %s SGI disklabel: csum bad, label corrupted\n",
bdevname(state->bdev, b));
put_dev_sector(sect);
return 0;
}
for(i = 0; i < 16; i++, p++) {
blocks = be32_to_cpu(p->num_blocks);
start = be32_to_cpu(p->first_block);
if (blocks) {
put_partition(state, slot, start, blocks);
if (be32_to_cpu(p->type) == LINUX_RAID_PARTITION)
state->parts[slot].flags = ADDPART_FLAG_RAID;
}
slot++;
}
strlcat(state->pp_buf, "\n", PAGE_SIZE);
put_dev_sector(sect);
return 1;
}
