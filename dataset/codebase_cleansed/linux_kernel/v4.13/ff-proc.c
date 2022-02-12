static void proc_dump_clock_config(struct snd_info_entry *entry,
struct snd_info_buffer *buffer)
{
struct snd_ff *ff = entry->private_data;
ff->spec->protocol->dump_clock_config(ff, buffer);
}
static void proc_dump_sync_status(struct snd_info_entry *entry,
struct snd_info_buffer *buffer)
{
struct snd_ff *ff = entry->private_data;
ff->spec->protocol->dump_sync_status(ff, buffer);
}
static void add_node(struct snd_ff *ff, struct snd_info_entry *root,
const char *name,
void (*op)(struct snd_info_entry *e,
struct snd_info_buffer *b))
{
struct snd_info_entry *entry;
entry = snd_info_create_card_entry(ff->card, name, root);
if (entry == NULL)
return;
snd_info_set_text_ops(entry, ff, op);
if (snd_info_register(entry) < 0)
snd_info_free_entry(entry);
}
void snd_ff_proc_init(struct snd_ff *ff)
{
struct snd_info_entry *root;
root = snd_info_create_card_entry(ff->card, "firewire",
ff->card->proc_root);
if (root == NULL)
return;
root->mode = S_IFDIR | S_IRUGO | S_IXUGO;
if (snd_info_register(root) < 0) {
snd_info_free_entry(root);
return;
}
add_node(ff, root, "clock-config", proc_dump_clock_config);
add_node(ff, root, "sync-status", proc_dump_sync_status);
}
