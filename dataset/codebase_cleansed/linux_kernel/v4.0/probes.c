int probe_is_prohibited_opcode(u16 *insn)
{
if (!is_known_insn((unsigned char *)insn))
return -EINVAL;
switch (insn[0] >> 8) {
case 0x0c:
case 0x0b:
case 0x83:
case 0x44:
case 0xac:
case 0xad:
return -EINVAL;
case 0xc6:
switch (insn[0] & 0x0f) {
case 0x00:
return -EINVAL;
}
}
switch (insn[0]) {
case 0x0101:
case 0xb25a:
case 0xb240:
case 0xb258:
case 0xb218:
case 0xb228:
case 0xb98d:
case 0xe560:
case 0xe561:
case 0xb2f8:
return -EINVAL;
}
return 0;
}
int probe_get_fixup_type(u16 *insn)
{
int fixup = FIXUP_PSW_NORMAL;
switch (insn[0] >> 8) {
case 0x05:
case 0x0d:
fixup = FIXUP_RETURN_REGISTER;
if ((insn[0] & 0x0f) == 0)
fixup |= FIXUP_BRANCH_NOT_TAKEN;
break;
case 0x06:
case 0x07:
fixup = FIXUP_BRANCH_NOT_TAKEN;
break;
case 0x45:
case 0x4d:
fixup = FIXUP_RETURN_REGISTER;
break;
case 0x47:
case 0x46:
case 0x86:
case 0x87:
fixup = FIXUP_BRANCH_NOT_TAKEN;
break;
case 0x82:
fixup = FIXUP_NOT_REQUIRED;
break;
case 0xb2:
if ((insn[0] & 0xff) == 0xb2)
fixup = FIXUP_NOT_REQUIRED;
break;
case 0xa7:
if ((insn[0] & 0x0f) == 0x05)
fixup |= FIXUP_RETURN_REGISTER;
break;
case 0xc0:
if ((insn[0] & 0x0f) == 0x05)
fixup |= FIXUP_RETURN_REGISTER;
break;
case 0xeb:
switch (insn[2] & 0xff) {
case 0x44:
case 0x45:
fixup = FIXUP_BRANCH_NOT_TAKEN;
break;
}
break;
case 0xe3:
if ((insn[2] & 0xff) == 0x46)
fixup = FIXUP_BRANCH_NOT_TAKEN;
break;
case 0xec:
switch (insn[2] & 0xff) {
case 0xe5:
case 0xe6:
case 0xf6:
case 0xf7:
case 0xfc:
case 0xfd:
case 0xfe:
case 0xff:
fixup = FIXUP_BRANCH_NOT_TAKEN;
break;
}
break;
}
return fixup;
}
int probe_is_insn_relative_long(u16 *insn)
{
switch (insn[0] >> 8) {
case 0xc0:
if ((insn[0] & 0x0f) == 0x00)
return true;
break;
case 0xc4:
switch (insn[0] & 0x0f) {
case 0x02:
case 0x04:
case 0x05:
case 0x06:
case 0x07:
case 0x08:
case 0x0b:
case 0x0c:
case 0x0d:
case 0x0e:
case 0x0f:
return true;
}
break;
case 0xc6:
switch (insn[0] & 0x0f) {
case 0x02:
case 0x04:
case 0x05:
case 0x06:
case 0x07:
case 0x08:
case 0x0a:
case 0x0c:
case 0x0d:
case 0x0e:
case 0x0f:
return true;
}
break;
}
return false;
}
