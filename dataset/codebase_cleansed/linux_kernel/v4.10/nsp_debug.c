static void print_opcodek(unsigned char opcode)
{
const char **table = commands[ group(opcode) ];
switch ((unsigned long) table) {
case RESERVED_GROUP:
printk("%s[%02x] ", reserved, opcode);
break;
case NOTEXT_GROUP:
printk("%s(notext)[%02x] ", unknown, opcode);
break;
case VENDOR_GROUP:
printk("%s[%02x] ", vendor, opcode);
break;
default:
if (table[opcode & 0x1f] != unknown)
printk("%s[%02x] ", table[opcode & 0x1f], opcode);
else
printk("%s[%02x] ", unknown, opcode);
break;
}
}
static void print_commandk (unsigned char *command)
{
int i, s;
printk(KERN_DEBUG);
print_opcodek(command[0]);
if ((command[0] >> 5) == 6 ||
(command[0] >> 5) == 7 ) {
s = 12;
} else {
s = COMMAND_SIZE(command[0]);
}
for ( i = 1; i < s; ++i) {
printk("%02x ", command[i]);
}
switch (s) {
case 6:
printk("LBA=%d len=%d",
(((unsigned int)command[1] & 0x0f) << 16) |
( (unsigned int)command[2] << 8) |
( (unsigned int)command[3] ),
(unsigned int)command[4]
);
break;
case 10:
printk("LBA=%d len=%d",
((unsigned int)command[2] << 24) |
((unsigned int)command[3] << 16) |
((unsigned int)command[4] << 8) |
((unsigned int)command[5] ),
((unsigned int)command[7] << 8) |
((unsigned int)command[8] )
);
break;
case 12:
printk("LBA=%d len=%d",
((unsigned int)command[2] << 24) |
((unsigned int)command[3] << 16) |
((unsigned int)command[4] << 8) |
((unsigned int)command[5] ),
((unsigned int)command[6] << 24) |
((unsigned int)command[7] << 16) |
((unsigned int)command[8] << 8) |
((unsigned int)command[9] )
);
break;
default:
break;
}
printk("\n");
}
static void show_command(struct scsi_cmnd *SCpnt)
{
print_commandk(SCpnt->cmnd);
}
static void show_phase(struct scsi_cmnd *SCpnt)
{
int i = SCpnt->SCp.phase;
char *ph[] = {
"PH_UNDETERMINED",
"PH_ARBSTART",
"PH_SELSTART",
"PH_SELECTED",
"PH_COMMAND",
"PH_DATA",
"PH_STATUS",
"PH_MSG_IN",
"PH_MSG_OUT",
"PH_DISCONNECT",
"PH_RESELECT"
};
if ( i < PH_UNDETERMINED || i > PH_RESELECT ) {
printk(KERN_DEBUG "scsi phase: unknown(%d)\n", i);
return;
}
printk(KERN_DEBUG "scsi phase: %s\n", ph[i]);
return;
}
static void show_busphase(unsigned char stat)
{
switch(stat) {
case BUSPHASE_COMMAND:
printk(KERN_DEBUG "BUSPHASE_COMMAND\n");
break;
case BUSPHASE_MESSAGE_IN:
printk(KERN_DEBUG "BUSPHASE_MESSAGE_IN\n");
break;
case BUSPHASE_MESSAGE_OUT:
printk(KERN_DEBUG "BUSPHASE_MESSAGE_OUT\n");
break;
case BUSPHASE_DATA_IN:
printk(KERN_DEBUG "BUSPHASE_DATA_IN\n");
break;
case BUSPHASE_DATA_OUT:
printk(KERN_DEBUG "BUSPHASE_DATA_OUT\n");
break;
case BUSPHASE_STATUS:
printk(KERN_DEBUG "BUSPHASE_STATUS\n");
break;
case BUSPHASE_SELECT:
printk(KERN_DEBUG "BUSPHASE_SELECT\n");
break;
default:
printk(KERN_DEBUG "BUSPHASE_other\n");
break;
}
}
static void show_message(nsp_hw_data *data)
{
int i;
printk(KERN_DEBUG "msg:");
for(i=0; i < data->MsgLen; i++) {
printk(" %02x", data->MsgBuffer[i]);
}
printk("\n");
}
