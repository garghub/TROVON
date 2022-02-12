static int __init alsa_sound_last_init(void)
{
int idx, ok = 0;
printk(KERN_INFO "ALSA device list:\n");
for (idx = 0; idx < SNDRV_CARDS; idx++)
if (snd_cards[idx] != NULL) {
printk(KERN_INFO " #%i: %s\n", idx, snd_cards[idx]->longname);
ok++;
}
if (ok == 0)
printk(KERN_INFO " No soundcards found.\n");
return 0;
}
