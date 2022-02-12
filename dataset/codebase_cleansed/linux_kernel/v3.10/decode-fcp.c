static void
decode_avc(struct link_transaction *t)
{
struct avc_frame *frame =
(struct avc_frame *) t->request->packet.write_block.data;
const struct avc_opcode_info *info;
const char *name;
char buffer[32];
int i;
info = &opcode_info[frame->opcode];
if (info->name == NULL) {
snprintf(buffer, sizeof(buffer),
"(unknown opcode 0x%02x)", frame->opcode);
name = buffer;
} else {
name = info->name;
}
printf("av/c %s, subunit_type=%s, subunit_id=%d, opcode=%s",
ctype_names[frame->ctype], subunit_type_names[frame->subunit_type],
frame->subunit_id, name);
for (i = 0; info->fields[i].name != NULL; i++)
printf(", %s", info->fields[i].name);
printf("\n");
}
int
decode_fcp(struct link_transaction *t)
{
struct avc_frame *frame =
(struct avc_frame *) t->request->packet.write_block.data;
unsigned long long offset =
((unsigned long long) t->request->packet.common.offset_high << 32) |
t->request->packet.common.offset_low;
if (t->request->packet.common.tcode != TCODE_WRITE_BLOCK_REQUEST)
return 0;
if (offset == CSR_FCP_COMMAND || offset == CSR_FCP_RESPONSE) {
switch (frame->cts) {
case 0x00:
decode_avc(t);
break;
case 0x01:
printf("cal fcp frame (cts=0x01)\n");
break;
case 0x02:
printf("ehs fcp frame (cts=0x02)\n");
break;
case 0x03:
printf("havi fcp frame (cts=0x03)\n");
break;
case 0x0e:
printf("vendor specific fcp frame (cts=0x0e)\n");
break;
case 0x0f:
printf("extended cts\n");
break;
default:
printf("reserved fcp frame (ctx=0x%02x)\n", frame->cts);
break;
}
return 1;
}
return 0;
}
