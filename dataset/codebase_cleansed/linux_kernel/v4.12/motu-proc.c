static void proc_read_clock(struct snd_info_entry *entry,
struct snd_info_buffer *buffer)
{
struct snd_motu *motu = entry->private_data;
const struct snd_motu_protocol *const protocol = motu->spec->protocol;
unsigned int rate;
enum snd_motu_clock_source source;
if (protocol->get_clock_rate(motu, &rate) < 0)
return;
if (protocol->get_clock_source(motu, &source) < 0)
return;
snd_iprintf(buffer, "Rate:\t%d\n", rate);
snd_iprintf(buffer, "Source:\t%s\n", clock_names[source]);
}
static void proc_read_format(struct snd_info_entry *entry,
struct snd_info_buffer *buffer)
{
struct snd_motu *motu = entry->private_data;
const struct snd_motu_protocol *const protocol = motu->spec->protocol;
unsigned int mode;
struct snd_motu_packet_format *formats;
int i;
if (protocol->cache_packet_formats(motu) < 0)
return;
snd_iprintf(buffer, "tx:\tmsg\tfixed\tdiffered\n");
for (i = 0; i < SND_MOTU_CLOCK_RATE_COUNT; ++i) {
mode = i >> 1;
formats = &motu->tx_packet_formats;
snd_iprintf(buffer,
"%u:\t%u\t%u\t%u\n",
snd_motu_clock_rates[i],
formats->msg_chunks,
formats->fixed_part_pcm_chunks[mode],
formats->differed_part_pcm_chunks[mode]);
}
snd_iprintf(buffer, "rx:\tmsg\tfixed\tdiffered\n");
for (i = 0; i < SND_MOTU_CLOCK_RATE_COUNT; ++i) {
mode = i >> 1;
formats = &motu->rx_packet_formats;
snd_iprintf(buffer,
"%u:\t%u\t%u\t%u\n",
snd_motu_clock_rates[i],
formats->msg_chunks,
formats->fixed_part_pcm_chunks[mode],
formats->differed_part_pcm_chunks[mode]);
}
}
static void add_node(struct snd_motu *motu, struct snd_info_entry *root,
const char *name,
void (*op)(struct snd_info_entry *e,
struct snd_info_buffer *b))
{
struct snd_info_entry *entry;
entry = snd_info_create_card_entry(motu->card, name, root);
if (entry == NULL)
return;
snd_info_set_text_ops(entry, motu, op);
if (snd_info_register(entry) < 0)
snd_info_free_entry(entry);
}
void snd_motu_proc_init(struct snd_motu *motu)
{
struct snd_info_entry *root;
root = snd_info_create_card_entry(motu->card, "firewire",
motu->card->proc_root);
if (root == NULL)
return;
root->mode = S_IFDIR | S_IRUGO | S_IXUGO;
if (snd_info_register(root) < 0) {
snd_info_free_entry(root);
return;
}
add_node(motu, root, "clock", proc_read_clock);
add_node(motu, root, "format", proc_read_format);
}
