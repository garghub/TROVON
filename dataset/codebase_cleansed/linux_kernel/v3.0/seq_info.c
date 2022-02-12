static struct snd_info_entry * __init
create_info_entry(char *name, void (*read)(struct snd_info_entry *,
struct snd_info_buffer *))
{
struct snd_info_entry *entry;
entry = snd_info_create_module_entry(THIS_MODULE, name, snd_seq_root);
if (entry == NULL)
return NULL;
entry->content = SNDRV_INFO_CONTENT_TEXT;
entry->c.text.read = read;
if (snd_info_register(entry) < 0) {
snd_info_free_entry(entry);
return NULL;
}
return entry;
}
int __init snd_seq_info_init(void)
{
queues_entry = create_info_entry("queues",
snd_seq_info_queues_read);
clients_entry = create_info_entry("clients",
snd_seq_info_clients_read);
timer_entry = create_info_entry("timer", snd_seq_info_timer_read);
return 0;
}
int __exit snd_seq_info_done(void)
{
snd_info_free_entry(queues_entry);
snd_info_free_entry(clients_entry);
snd_info_free_entry(timer_entry);
return 0;
}
