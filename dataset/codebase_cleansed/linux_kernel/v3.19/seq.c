static int __init alsa_seq_init(void)
{
int err;
if ((err = client_init_data()) < 0)
goto error;
if ((err = snd_sequencer_memory_init()) < 0)
goto error;
if ((err = snd_seq_queues_init()) < 0)
goto error;
if ((err = snd_sequencer_device_init()) < 0)
goto error;
if ((err = snd_seq_info_init()) < 0)
goto error;
if ((err = snd_seq_system_client_init()) < 0)
goto error;
snd_seq_autoload_init();
error:
return err;
}
static void __exit alsa_seq_exit(void)
{
snd_seq_system_client_done();
snd_seq_info_done();
snd_seq_queues_delete();
snd_sequencer_device_done();
snd_sequencer_memory_done();
snd_seq_autoload_exit();
}
