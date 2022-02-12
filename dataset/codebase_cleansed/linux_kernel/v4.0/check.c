static struct parsed_partitions *allocate_partitions(struct gendisk *hd)
{
struct parsed_partitions *state;
int nr;
state = kzalloc(sizeof(*state), GFP_KERNEL);
if (!state)
return NULL;
nr = disk_max_parts(hd);
state->parts = vzalloc(nr * sizeof(state->parts[0]));
if (!state->parts) {
kfree(state);
return NULL;
}
state->limit = nr;
return state;
}
void free_partitions(struct parsed_partitions *state)
{
vfree(state->parts);
kfree(state);
}
struct parsed_partitions *
check_partition(struct gendisk *hd, struct block_device *bdev)
{
struct parsed_partitions *state;
int i, res, err;
state = allocate_partitions(hd);
if (!state)
return NULL;
state->pp_buf = (char *)__get_free_page(GFP_KERNEL);
if (!state->pp_buf) {
free_partitions(state);
return NULL;
}
state->pp_buf[0] = '\0';
state->bdev = bdev;
disk_name(hd, 0, state->name);
snprintf(state->pp_buf, PAGE_SIZE, " %s:", state->name);
if (isdigit(state->name[strlen(state->name)-1]))
sprintf(state->name, "p");
i = res = err = 0;
while (!res && check_part[i]) {
memset(state->parts, 0, state->limit * sizeof(state->parts[0]));
res = check_part[i++](state);
if (res < 0) {
err = res;
res = 0;
}
}
if (res > 0) {
printk(KERN_INFO "%s", state->pp_buf);
free_page((unsigned long)state->pp_buf);
return state;
}
if (state->access_beyond_eod)
err = -ENOSPC;
if (err)
res = err;
if (res) {
if (warn_no_part)
strlcat(state->pp_buf,
" unable to read partition table\n", PAGE_SIZE);
printk(KERN_INFO "%s", state->pp_buf);
}
free_page((unsigned long)state->pp_buf);
free_partitions(state);
return ERR_PTR(res);
}
