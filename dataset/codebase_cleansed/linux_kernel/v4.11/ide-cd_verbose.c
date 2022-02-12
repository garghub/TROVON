void ide_cd_log_error(const char *name, struct request *failed_command,
struct request_sense *sense)
{
if (sense->sense_key == UNIT_ATTENTION ||
(sense->sense_key == NOT_READY && (sense->asc == 4 ||
sense->asc == 0x3a)))
return;
printk(KERN_ERR "%s: error code: 0x%02x sense_key: 0x%02x "
"asc: 0x%02x ascq: 0x%02x\n",
name, sense->error_code, sense->sense_key,
sense->asc, sense->ascq);
}
void ide_cd_log_error(const char *name, struct request *failed_command,
struct request_sense *sense)
{
int i;
const char *s = "bad sense key!";
char buf[80];
printk(KERN_ERR "ATAPI device %s:\n", name);
if (sense->error_code == 0x70)
printk(KERN_CONT " Error: ");
else if (sense->error_code == 0x71)
printk(" Deferred Error: ");
else if (sense->error_code == 0x7f)
printk(KERN_CONT " Vendor-specific Error: ");
else
printk(KERN_CONT " Unknown Error Type: ");
if (sense->sense_key < ARRAY_SIZE(sense_key_texts))
s = sense_key_texts[sense->sense_key];
printk(KERN_CONT "%s -- (Sense key=0x%02x)\n", s, sense->sense_key);
if (sense->asc == 0x40) {
sprintf(buf, "Diagnostic failure on component 0x%02x",
sense->ascq);
s = buf;
} else {
int lo = 0, mid, hi = ARRAY_SIZE(sense_data_texts);
unsigned long key = (sense->sense_key << 16);
key |= (sense->asc << 8);
if (!(sense->ascq >= 0x80 && sense->ascq <= 0xdd))
key |= sense->ascq;
s = NULL;
while (hi > lo) {
mid = (lo + hi) / 2;
if (sense_data_texts[mid].asc_ascq == key ||
sense_data_texts[mid].asc_ascq == (0xff0000|key)) {
s = sense_data_texts[mid].text;
break;
} else if (sense_data_texts[mid].asc_ascq > key)
hi = mid;
else
lo = mid + 1;
}
}
if (s == NULL) {
if (sense->asc > 0x80)
s = "(vendor-specific error)";
else
s = "(reserved error code)";
}
printk(KERN_ERR " %s -- (asc=0x%02x, ascq=0x%02x)\n",
s, sense->asc, sense->ascq);
if (failed_command != NULL) {
int lo = 0, mid, hi = ARRAY_SIZE(packet_command_texts);
s = NULL;
while (hi > lo) {
mid = (lo + hi) / 2;
if (packet_command_texts[mid].packet_command ==
scsi_req(failed_command)->cmd[0]) {
s = packet_command_texts[mid].text;
break;
}
if (packet_command_texts[mid].packet_command >
scsi_req(failed_command)->cmd[0])
hi = mid;
else
lo = mid + 1;
}
printk(KERN_ERR " The failed \"%s\" packet command "
"was: \n \"", s);
for (i = 0; i < BLK_MAX_CDB; i++)
printk(KERN_CONT "%02x ", scsi_req(failed_command)->cmd[i]);
printk(KERN_CONT "\"\n");
}
if (sense->sense_key == NOT_READY && (sense->sks[0] & 0x80)) {
int progress = (sense->sks[1] << 8 | sense->sks[2]) * 100;
printk(KERN_ERR " Command is %02d%% complete\n",
progress / 0xffff);
}
if (sense->sense_key == ILLEGAL_REQUEST &&
(sense->sks[0] & 0x80) != 0) {
printk(KERN_ERR " Error in %s byte %d",
(sense->sks[0] & 0x40) != 0 ?
"command packet" : "command data",
(sense->sks[1] << 8) + sense->sks[2]);
if ((sense->sks[0] & 0x40) != 0)
printk(KERN_CONT " bit %d", sense->sks[0] & 0x07);
printk(KERN_CONT "\n");
}
}
