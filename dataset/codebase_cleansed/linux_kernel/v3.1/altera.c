static int altera_check_stack(int stack_ptr, int count, int *status)
{
if (stack_ptr < count) {
*status = -EOVERFLOW;
return 0;
}
return 1;
}
static void altera_export_int(char *key, s32 value)
{
dprintk("Export: key = \"%s\", value = %d\n", key, value);
}
static void altera_export_bool_array(char *key, u8 *data, s32 count)
{
char string[HEX_LINE_CHARS + 1];
s32 i, offset;
u32 size, line, lines, linebits, value, j, k;
if (count > HEX_LINE_BITS) {
dprintk("Export: key = \"%s\", %d bits, value = HEX\n",
key, count);
lines = (count + (HEX_LINE_BITS - 1)) / HEX_LINE_BITS;
for (line = 0; line < lines; ++line) {
if (line < (lines - 1)) {
linebits = HEX_LINE_BITS;
size = HEX_LINE_CHARS;
offset = count - ((line + 1) * HEX_LINE_BITS);
} else {
linebits =
count - ((lines - 1) * HEX_LINE_BITS);
size = (linebits + 3) / 4;
offset = 0L;
}
string[size] = '\0';
j = size - 1;
value = 0;
for (k = 0; k < linebits; ++k) {
i = k + offset;
if (data[i >> 3] & (1 << (i & 7)))
value |= (1 << (i & 3));
if ((i & 3) == 3) {
sprintf(&string[j], "%1x", value);
value = 0;
--j;
}
}
if ((k & 3) > 0)
sprintf(&string[j], "%1x", value);
dprintk("%s\n", string);
}
} else {
size = (count + 3) / 4;
string[size] = '\0';
j = size - 1;
value = 0;
for (i = 0; i < count; ++i) {
if (data[i >> 3] & (1 << (i & 7)))
value |= (1 << (i & 3));
if ((i & 3) == 3) {
sprintf(&string[j], "%1x", value);
value = 0;
--j;
}
}
if ((i & 3) > 0)
sprintf(&string[j], "%1x", value);
dprintk("Export: key = \"%s\", %d bits, value = HEX %s\n",
key, count, string);
}
}
static int altera_execute(struct altera_state *astate,
u8 *p,
s32 program_size,
s32 *error_address,
int *exit_code,
int *format_version)
{
struct altera_config *aconf = astate->config;
char *msg_buff = astate->msg_buff;
long *stack = astate->stack;
int status = 0;
u32 first_word = 0L;
u32 action_table = 0L;
u32 proc_table = 0L;
u32 str_table = 0L;
u32 sym_table = 0L;
u32 data_sect = 0L;
u32 code_sect = 0L;
u32 debug_sect = 0L;
u32 action_count = 0L;
u32 proc_count = 0L;
u32 sym_count = 0L;
long *vars = NULL;
s32 *var_size = NULL;
char *attrs = NULL;
u8 *proc_attributes = NULL;
u32 pc;
u32 opcode_address;
u32 args[3];
u32 opcode;
u32 name_id;
u8 charbuf[4];
long long_tmp;
u32 variable_id;
u8 *charptr_tmp;
u8 *charptr_tmp2;
long *longptr_tmp;
int version = 0;
int delta = 0;
int stack_ptr = 0;
u32 arg_count;
int done = 0;
int bad_opcode = 0;
u32 count;
u32 index;
u32 index2;
s32 long_count;
s32 long_idx;
s32 long_idx2;
u32 i;
u32 j;
u32 uncomp_size;
u32 offset;
u32 value;
int current_proc = 0;
int reverse;
char *name;
dprintk("%s\n", __func__);
if (program_size > 52L) {
first_word = get_unaligned_be32(&p[0]);
version = (first_word & 1L);
*format_version = version + 1;
delta = version * 8;
action_table = get_unaligned_be32(&p[4]);
proc_table = get_unaligned_be32(&p[8]);
str_table = get_unaligned_be32(&p[4 + delta]);
sym_table = get_unaligned_be32(&p[16 + delta]);
data_sect = get_unaligned_be32(&p[20 + delta]);
code_sect = get_unaligned_be32(&p[24 + delta]);
debug_sect = get_unaligned_be32(&p[28 + delta]);
action_count = get_unaligned_be32(&p[40 + delta]);
proc_count = get_unaligned_be32(&p[44 + delta]);
sym_count = get_unaligned_be32(&p[48 + (2 * delta)]);
}
if ((first_word != 0x4A414D00L) && (first_word != 0x4A414D01L)) {
done = 1;
status = -EIO;
goto exit_done;
}
if (sym_count <= 0)
goto exit_done;
vars = kzalloc(sym_count * sizeof(long), GFP_KERNEL);
if (vars == NULL)
status = -ENOMEM;
if (status == 0) {
var_size = kzalloc(sym_count * sizeof(s32), GFP_KERNEL);
if (var_size == NULL)
status = -ENOMEM;
}
if (status == 0) {
attrs = kzalloc(sym_count, GFP_KERNEL);
if (attrs == NULL)
status = -ENOMEM;
}
if ((status == 0) && (version > 0)) {
proc_attributes = kzalloc(proc_count, GFP_KERNEL);
if (proc_attributes == NULL)
status = -ENOMEM;
}
if (status != 0)
goto exit_done;
delta = version * 2;
for (i = 0; i < sym_count; ++i) {
offset = (sym_table + ((11 + delta) * i));
value = get_unaligned_be32(&p[offset + 3 + delta]);
attrs[i] = p[offset];
attrs[i] &= 0x7f;
var_size[i] = get_unaligned_be32(&p[offset + 7 + delta]);
if ((attrs[i] & 0x0c) == 0x04)
vars[i] = value;
else if ((attrs[i] & 0x1e) == 0x0e) {
uncomp_size = get_unaligned_le32(&p[data_sect + value]);
vars[i] = (long)kzalloc(uncomp_size, GFP_KERNEL);
if (vars[i] == 0L)
status = -ENOMEM;
else {
attrs[i] |= 0x80;
if (altera_shrink(&p[data_sect + value],
var_size[i],
(u8 *)vars[i],
uncomp_size,
version) != uncomp_size)
status = -EIO;
else
var_size[i] = uncomp_size * 8L;
}
} else if ((attrs[i] & 0x1e) == 0x0c) {
vars[i] = value + data_sect + (long)p;
} else if ((attrs[i] & 0x1c) == 0x1c) {
vars[i] = value + data_sect;
} else if ((attrs[i] & 0x0c) == 0x08) {
attrs[i] |= 0x80;
if (var_size[i] > 0) {
u32 size;
if (attrs[i] & 0x10)
size = (var_size[i] * sizeof(s32));
else
size = ((var_size[i] + 7L) / 8L);
vars[i] = (long)kzalloc(size, GFP_KERNEL);
if (vars[i] == 0) {
status = -ENOMEM;
} else {
for (j = 0; j < size; ++j)
((u8 *)(vars[i]))[j] = 0;
}
} else
vars[i] = 0;
} else
vars[i] = 0;
}
exit_done:
if (status != 0)
done = 1;
altera_jinit(astate);
pc = code_sect;
msg_buff[0] = '\0';
if (version > 0) {
if (aconf->action == NULL) {
status = -EINVAL;
done = 1;
} else {
int action_found = 0;
for (i = 0; (i < action_count) && !action_found; ++i) {
name_id = get_unaligned_be32(&p[action_table +
(12 * i)]);
name = &p[str_table + name_id];
if (strnicmp(aconf->action, name, strlen(name)) == 0) {
action_found = 1;
current_proc =
get_unaligned_be32(&p[action_table +
(12 * i) + 8]);
}
}
if (!action_found) {
status = -EINVAL;
done = 1;
}
}
if (status == 0) {
int first_time = 1;
i = current_proc;
while ((i != 0) || first_time) {
first_time = 0;
proc_attributes[i] =
(p[proc_table +
(13 * i) + 8] &
0x03);
i = get_unaligned_be32(&p[proc_table +
(13 * i) + 4]);
}
i = current_proc;
while ((i != 0) &&
((proc_attributes[i] == 1) ||
((proc_attributes[i] & 0xc0) == 0x40))) {
i = get_unaligned_be32(&p[proc_table +
(13 * i) + 4]);
}
if ((i != 0) || ((i == 0) && (current_proc == 0) &&
((proc_attributes[0] != 1) &&
((proc_attributes[0] & 0xc0) != 0x40)))) {
current_proc = i;
pc = code_sect +
get_unaligned_be32(&p[proc_table +
(13 * i) + 9]);
if ((pc < code_sect) || (pc >= debug_sect))
status = -ERANGE;
} else
done = 1;
}
}
msg_buff[0] = '\0';
while (!done) {
opcode = (p[pc] & 0xff);
opcode_address = pc;
++pc;
if (debug > 1)
printk("opcode: %02x\n", opcode);
arg_count = (opcode >> 6) & 3;
for (i = 0; i < arg_count; ++i) {
args[i] = get_unaligned_be32(&p[pc]);
pc += 4;
}
switch (opcode) {
case OP_NOP:
break;
case OP_DUP:
if (altera_check_stack(stack_ptr, 1, &status)) {
stack[stack_ptr] = stack[stack_ptr - 1];
++stack_ptr;
}
break;
case OP_SWP:
if (altera_check_stack(stack_ptr, 2, &status)) {
long_tmp = stack[stack_ptr - 2];
stack[stack_ptr - 2] = stack[stack_ptr - 1];
stack[stack_ptr - 1] = long_tmp;
}
break;
case OP_ADD:
if (altera_check_stack(stack_ptr, 2, &status)) {
--stack_ptr;
stack[stack_ptr - 1] += stack[stack_ptr];
}
break;
case OP_SUB:
if (altera_check_stack(stack_ptr, 2, &status)) {
--stack_ptr;
stack[stack_ptr - 1] -= stack[stack_ptr];
}
break;
case OP_MULT:
if (altera_check_stack(stack_ptr, 2, &status)) {
--stack_ptr;
stack[stack_ptr - 1] *= stack[stack_ptr];
}
break;
case OP_DIV:
if (altera_check_stack(stack_ptr, 2, &status)) {
--stack_ptr;
stack[stack_ptr - 1] /= stack[stack_ptr];
}
break;
case OP_MOD:
if (altera_check_stack(stack_ptr, 2, &status)) {
--stack_ptr;
stack[stack_ptr - 1] %= stack[stack_ptr];
}
break;
case OP_SHL:
if (altera_check_stack(stack_ptr, 2, &status)) {
--stack_ptr;
stack[stack_ptr - 1] <<= stack[stack_ptr];
}
break;
case OP_SHR:
if (altera_check_stack(stack_ptr, 2, &status)) {
--stack_ptr;
stack[stack_ptr - 1] >>= stack[stack_ptr];
}
break;
case OP_NOT:
if (altera_check_stack(stack_ptr, 1, &status))
stack[stack_ptr - 1] ^= (-1L);
break;
case OP_AND:
if (altera_check_stack(stack_ptr, 2, &status)) {
--stack_ptr;
stack[stack_ptr - 1] &= stack[stack_ptr];
}
break;
case OP_OR:
if (altera_check_stack(stack_ptr, 2, &status)) {
--stack_ptr;
stack[stack_ptr - 1] |= stack[stack_ptr];
}
break;
case OP_XOR:
if (altera_check_stack(stack_ptr, 2, &status)) {
--stack_ptr;
stack[stack_ptr - 1] ^= stack[stack_ptr];
}
break;
case OP_INV:
if (!altera_check_stack(stack_ptr, 1, &status))
break;
stack[stack_ptr - 1] = stack[stack_ptr - 1] ? 0L : 1L;
break;
case OP_GT:
if (!altera_check_stack(stack_ptr, 2, &status))
break;
--stack_ptr;
stack[stack_ptr - 1] =
(stack[stack_ptr - 1] > stack[stack_ptr]) ?
1L : 0L;
break;
case OP_LT:
if (!altera_check_stack(stack_ptr, 2, &status))
break;
--stack_ptr;
stack[stack_ptr - 1] =
(stack[stack_ptr - 1] < stack[stack_ptr]) ?
1L : 0L;
break;
case OP_RET:
if ((version > 0) && (stack_ptr == 0)) {
i = get_unaligned_be32(&p[proc_table +
(13 * current_proc) + 4]);
while ((i != 0) &&
((proc_attributes[i] == 1) ||
((proc_attributes[i] & 0xc0) == 0x40)))
i = get_unaligned_be32(&p[proc_table +
(13 * i) + 4]);
if (i == 0) {
done = 1;
*exit_code = 0;
} else {
current_proc = i;
pc = code_sect + get_unaligned_be32(
&p[proc_table +
(13 * i) + 9]);
if ((pc < code_sect) ||
(pc >= debug_sect))
status = -ERANGE;
}
} else
if (altera_check_stack(stack_ptr, 1, &status)) {
pc = stack[--stack_ptr] + code_sect;
if ((pc <= code_sect) ||
(pc >= debug_sect))
status = -ERANGE;
}
break;
case OP_CMPS:
if (altera_check_stack(stack_ptr, 4, &status)) {
s32 a = stack[--stack_ptr];
s32 b = stack[--stack_ptr];
long_tmp = stack[--stack_ptr];
count = stack[stack_ptr - 1];
if ((count < 1) || (count > 32))
status = -ERANGE;
else {
long_tmp &= ((-1L) >> (32 - count));
stack[stack_ptr - 1] =
((a & long_tmp) == (b & long_tmp))
? 1L : 0L;
}
}
break;
case OP_PINT:
if (!altera_check_stack(stack_ptr, 1, &status))
break;
sprintf(&msg_buff[strlen(msg_buff)],
"%ld", stack[--stack_ptr]);
break;
case OP_PRNT:
if (debug)
printk(msg_buff, "\n");
msg_buff[0] = '\0';
break;
case OP_DSS:
if (!altera_check_stack(stack_ptr, 2, &status))
break;
long_tmp = stack[--stack_ptr];
count = stack[--stack_ptr];
put_unaligned_le32(long_tmp, &charbuf[0]);
status = altera_drscan(astate, count, charbuf, 0);
break;
case OP_DSSC:
if (!altera_check_stack(stack_ptr, 2, &status))
break;
long_tmp = stack[--stack_ptr];
count = stack[stack_ptr - 1];
put_unaligned_le32(long_tmp, &charbuf[0]);
status = altera_swap_dr(astate, count, charbuf,
0, charbuf, 0);
stack[stack_ptr - 1] = get_unaligned_le32(&charbuf[0]);
break;
case OP_ISS:
if (!altera_check_stack(stack_ptr, 2, &status))
break;
long_tmp = stack[--stack_ptr];
count = stack[--stack_ptr];
put_unaligned_le32(long_tmp, &charbuf[0]);
status = altera_irscan(astate, count, charbuf, 0);
break;
case OP_ISSC:
if (!altera_check_stack(stack_ptr, 2, &status))
break;
long_tmp = stack[--stack_ptr];
count = stack[stack_ptr - 1];
put_unaligned_le32(long_tmp, &charbuf[0]);
status = altera_swap_ir(astate, count, charbuf,
0, charbuf, 0);
stack[stack_ptr - 1] = get_unaligned_le32(&charbuf[0]);
break;
case OP_DPR:
if (!altera_check_stack(stack_ptr, 1, &status))
break;
count = stack[--stack_ptr];
status = altera_set_dr_pre(&astate->js, count, 0, NULL);
break;
case OP_DPRL:
if (!altera_check_stack(stack_ptr, 2, &status))
break;
count = stack[--stack_ptr];
long_tmp = stack[--stack_ptr];
put_unaligned_le32(long_tmp, &charbuf[0]);
status = altera_set_dr_pre(&astate->js, count, 0,
charbuf);
break;
case OP_DPO:
if (altera_check_stack(stack_ptr, 1, &status)) {
count = stack[--stack_ptr];
status = altera_set_dr_post(&astate->js, count,
0, NULL);
}
break;
case OP_DPOL:
if (!altera_check_stack(stack_ptr, 2, &status))
break;
count = stack[--stack_ptr];
long_tmp = stack[--stack_ptr];
put_unaligned_le32(long_tmp, &charbuf[0]);
status = altera_set_dr_post(&astate->js, count, 0,
charbuf);
break;
case OP_IPR:
if (altera_check_stack(stack_ptr, 1, &status)) {
count = stack[--stack_ptr];
status = altera_set_ir_pre(&astate->js, count,
0, NULL);
}
break;
case OP_IPRL:
if (altera_check_stack(stack_ptr, 2, &status)) {
count = stack[--stack_ptr];
long_tmp = stack[--stack_ptr];
put_unaligned_le32(long_tmp, &charbuf[0]);
status = altera_set_ir_pre(&astate->js, count,
0, charbuf);
}
break;
case OP_IPO:
if (altera_check_stack(stack_ptr, 1, &status)) {
count = stack[--stack_ptr];
status = altera_set_ir_post(&astate->js, count,
0, NULL);
}
break;
case OP_IPOL:
if (!altera_check_stack(stack_ptr, 2, &status))
break;
count = stack[--stack_ptr];
long_tmp = stack[--stack_ptr];
put_unaligned_le32(long_tmp, &charbuf[0]);
status = altera_set_ir_post(&astate->js, count, 0,
charbuf);
break;
case OP_PCHR:
if (altera_check_stack(stack_ptr, 1, &status)) {
u8 ch;
count = strlen(msg_buff);
ch = (char) stack[--stack_ptr];
if ((ch < 1) || (ch > 127)) {
ch = 127;
}
msg_buff[count] = ch;
msg_buff[count + 1] = '\0';
}
break;
case OP_EXIT:
if (altera_check_stack(stack_ptr, 1, &status))
*exit_code = stack[--stack_ptr];
done = 1;
break;
case OP_EQU:
if (!altera_check_stack(stack_ptr, 2, &status))
break;
--stack_ptr;
stack[stack_ptr - 1] =
(stack[stack_ptr - 1] == stack[stack_ptr]) ?
1L : 0L;
break;
case OP_POPT:
if (altera_check_stack(stack_ptr, 1, &status))
--stack_ptr;
break;
case OP_ABS:
if (!altera_check_stack(stack_ptr, 1, &status))
break;
if (stack[stack_ptr - 1] < 0)
stack[stack_ptr - 1] = 0 - stack[stack_ptr - 1];
break;
case OP_BCH0:
if (altera_check_stack(stack_ptr, 2, &status)) {
long_tmp = stack[stack_ptr - 2];
stack[stack_ptr - 2] = stack[stack_ptr - 1];
stack[stack_ptr - 1] = long_tmp;
}
index = 7 + 1;
if (altera_check_stack(stack_ptr, index, &status)) {
long_tmp = stack[stack_ptr - index];
stack[stack_ptr - index] = stack[stack_ptr - 1];
stack[stack_ptr - 1] = long_tmp;
}
if (altera_check_stack(stack_ptr, 2, &status)) {
long_tmp = stack[stack_ptr - 2];
stack[stack_ptr - 2] = stack[stack_ptr - 1];
stack[stack_ptr - 1] = long_tmp;
}
index = 6 + 1;
if (altera_check_stack(stack_ptr, index, &status)) {
long_tmp = stack[stack_ptr - index];
stack[stack_ptr - index] = stack[stack_ptr - 1];
stack[stack_ptr - 1] = long_tmp;
}
index = 8 + 1;
if (altera_check_stack(stack_ptr, index, &status)) {
stack[stack_ptr] = stack[stack_ptr - index];
++stack_ptr;
}
index = 2 + 1;
if (altera_check_stack(stack_ptr, index, &status)) {
long_tmp = stack[stack_ptr - index];
stack[stack_ptr - index] = stack[stack_ptr - 1];
stack[stack_ptr - 1] = long_tmp;
}
if (altera_check_stack(stack_ptr, 2, &status)) {
long_tmp = stack[stack_ptr - 2];
stack[stack_ptr - 2] = stack[stack_ptr - 1];
stack[stack_ptr - 1] = long_tmp;
}
index = 6 + 1;
if (altera_check_stack(stack_ptr, index, &status)) {
stack[stack_ptr] = stack[stack_ptr - index];
++stack_ptr;
}
index = 6 + 1;
if (altera_check_stack(stack_ptr, index, &status)) {
stack[stack_ptr] = stack[stack_ptr - index];
++stack_ptr;
}
break;
case OP_PSH0:
stack[stack_ptr++] = 0;
break;
case OP_PSHL:
stack[stack_ptr++] = (s32) args[0];
break;
case OP_PSHV:
stack[stack_ptr++] = vars[args[0]];
break;
case OP_JMP:
pc = args[0] + code_sect;
if ((pc < code_sect) || (pc >= debug_sect))
status = -ERANGE;
break;
case OP_CALL:
stack[stack_ptr++] = pc;
pc = args[0] + code_sect;
if ((pc < code_sect) || (pc >= debug_sect))
status = -ERANGE;
break;
case OP_NEXT:
if (altera_check_stack(stack_ptr, 3, &status)) {
s32 step = stack[stack_ptr - 1];
s32 end = stack[stack_ptr - 2];
s32 top = stack[stack_ptr - 3];
s32 iterator = vars[args[0]];
int break_out = 0;
if (step < 0) {
if (iterator <= end)
break_out = 1;
} else if (iterator >= end)
break_out = 1;
if (break_out) {
stack_ptr -= 3;
} else {
vars[args[0]] = iterator + step;
pc = top + code_sect;
if ((pc < code_sect) ||
(pc >= debug_sect))
status = -ERANGE;
}
}
break;
case OP_PSTR:
count = strlen(msg_buff);
strlcpy(&msg_buff[count],
&p[str_table + args[0]],
ALTERA_MESSAGE_LENGTH - count);
break;
case OP_SINT:
status = altera_goto_jstate(astate, args[0]);
break;
case OP_ST:
status = altera_goto_jstate(astate, args[0]);
break;
case OP_ISTP:
status = altera_set_irstop(&astate->js, args[0]);
break;
case OP_DSTP:
status = altera_set_drstop(&astate->js, args[0]);
break;
case OP_SWPN:
index = (args[0]) + 1;
if (altera_check_stack(stack_ptr, index, &status)) {
long_tmp = stack[stack_ptr - index];
stack[stack_ptr - index] = stack[stack_ptr - 1];
stack[stack_ptr - 1] = long_tmp;
}
break;
case OP_DUPN:
index = (args[0]) + 1;
if (altera_check_stack(stack_ptr, index, &status)) {
stack[stack_ptr] = stack[stack_ptr - index];
++stack_ptr;
}
break;
case OP_POPV:
if (altera_check_stack(stack_ptr, 1, &status))
vars[args[0]] = stack[--stack_ptr];
break;
case OP_POPE:
if (!altera_check_stack(stack_ptr, 2, &status))
break;
variable_id = args[0];
if ((version > 0) &&
((attrs[variable_id] & 0x9c) == 0x1c)) {
count = var_size[variable_id];
long_tmp = vars[variable_id];
longptr_tmp = kzalloc(count * sizeof(long),
GFP_KERNEL);
vars[variable_id] = (long)longptr_tmp;
if (vars[variable_id] == 0) {
status = -ENOMEM;
break;
}
for (i = 0; i < count; ++i) {
longptr_tmp[i] =
get_unaligned_be32(&p[long_tmp]);
long_tmp += sizeof(long);
}
attrs[variable_id] |= 0x80;
attrs[variable_id] &= ~0x04;
attrs[variable_id] |= 0x01;
}
if ((attrs[variable_id] & 0x1c) != 0x18)
status = -ERANGE;
else {
longptr_tmp = (long *)vars[variable_id];
index = stack[--stack_ptr];
longptr_tmp[index] = stack[--stack_ptr];
}
break;
case OP_POPA:
if (!altera_check_stack(stack_ptr, 3, &status))
break;
variable_id = args[0];
if ((version > 0) &&
((attrs[variable_id] & 0x9c) == 0x0c)) {
long_tmp =
(var_size[variable_id] + 7L) >> 3L;
charptr_tmp2 = (u8 *)vars[variable_id];
charptr_tmp =
kzalloc(long_tmp, GFP_KERNEL);
vars[variable_id] = (long)charptr_tmp;
if (vars[variable_id] == 0) {
status = -ENOMEM;
break;
}
for (long_idx = 0L;
long_idx < long_tmp;
++long_idx) {
charptr_tmp[long_idx] = 0;
}
for (long_idx = 0L;
long_idx < var_size[variable_id];
++long_idx) {
long_idx2 = long_idx;
if (charptr_tmp2[long_idx2 >> 3] &
(1 << (long_idx2 & 7))) {
charptr_tmp[long_idx >> 3] |=
(1 << (long_idx & 7));
}
}
attrs[variable_id] |= 0x80;
attrs[variable_id] &= ~0x04;
attrs[variable_id] |= 0x01;
}
if ((attrs[variable_id] & 0x1c) != 0x08) {
status = -ERANGE;
break;
}
charptr_tmp = (u8 *)vars[variable_id];
long_count = stack[--stack_ptr];
long_idx = stack[--stack_ptr];
reverse = 0;
if (version > 0) {
if (long_idx > long_count) {
reverse = 1;
long_tmp = long_count;
long_count = 1 + long_idx -
long_count;
long_idx = long_tmp;
status = -ERANGE;
break;
} else
long_count = 1 + long_count -
long_idx;
}
long_tmp = stack[--stack_ptr];
if (long_count < 1) {
status = -ERANGE;
break;
}
for (i = 0; i < long_count; ++i) {
if (long_tmp & (1L << (s32) i))
charptr_tmp[long_idx >> 3L] |=
(1L << (long_idx & 7L));
else
charptr_tmp[long_idx >> 3L] &=
~(1L << (long_idx & 7L));
++long_idx;
}
break;
case OP_JMPZ:
if (altera_check_stack(stack_ptr, 1, &status)) {
if (stack[--stack_ptr] == 0) {
pc = args[0] + code_sect;
if ((pc < code_sect) ||
(pc >= debug_sect))
status = -ERANGE;
}
}
break;
case OP_DS:
case OP_IS:
if (!altera_check_stack(stack_ptr, 2, &status))
break;
long_idx = stack[--stack_ptr];
long_count = stack[--stack_ptr];
reverse = 0;
if (version > 0) {
long_tmp = long_count;
long_count = stack[--stack_ptr];
if (long_idx > long_tmp) {
reverse = 1;
long_idx = long_tmp;
}
}
charptr_tmp = (u8 *)vars[args[0]];
if (reverse) {
charptr_tmp2 = charptr_tmp;
charptr_tmp = kzalloc((long_count >> 3) + 1,
GFP_KERNEL);
if (charptr_tmp == NULL) {
status = -ENOMEM;
break;
}
long_tmp = long_idx + long_count - 1;
long_idx2 = 0;
while (long_idx2 < long_count) {
if (charptr_tmp2[long_tmp >> 3] &
(1 << (long_tmp & 7)))
charptr_tmp[long_idx2 >> 3] |=
(1 << (long_idx2 & 7));
else
charptr_tmp[long_idx2 >> 3] &=
~(1 << (long_idx2 & 7));
--long_tmp;
++long_idx2;
}
}
if (opcode == 0x51)
status = altera_drscan(astate, long_count,
charptr_tmp, long_idx);
else
status = altera_irscan(astate, long_count,
charptr_tmp, long_idx);
if (reverse)
kfree(charptr_tmp);
break;
case OP_DPRA:
if (!altera_check_stack(stack_ptr, 2, &status))
break;
index = stack[--stack_ptr];
count = stack[--stack_ptr];
if (version > 0)
count = 1 + count - index;
charptr_tmp = (u8 *)vars[args[0]];
status = altera_set_dr_pre(&astate->js, count, index,
charptr_tmp);
break;
case OP_DPOA:
if (!altera_check_stack(stack_ptr, 2, &status))
break;
index = stack[--stack_ptr];
count = stack[--stack_ptr];
if (version > 0)
count = 1 + count - index;
charptr_tmp = (u8 *)vars[args[0]];
status = altera_set_dr_post(&astate->js, count, index,
charptr_tmp);
break;
case OP_IPRA:
if (!altera_check_stack(stack_ptr, 2, &status))
break;
index = stack[--stack_ptr];
count = stack[--stack_ptr];
if (version > 0)
count = 1 + count - index;
charptr_tmp = (u8 *)vars[args[0]];
status = altera_set_ir_pre(&astate->js, count, index,
charptr_tmp);
break;
case OP_IPOA:
if (!altera_check_stack(stack_ptr, 2, &status))
break;
index = stack[--stack_ptr];
count = stack[--stack_ptr];
if (version > 0)
count = 1 + count - index;
charptr_tmp = (u8 *)vars[args[0]];
status = altera_set_ir_post(&astate->js, count, index,
charptr_tmp);
break;
case OP_EXPT:
if (altera_check_stack(stack_ptr, 1, &status)) {
name = &p[str_table + args[0]];
long_tmp = stack[--stack_ptr];
altera_export_int(name, long_tmp);
}
break;
case OP_PSHE:
if (!altera_check_stack(stack_ptr, 1, &status))
break;
variable_id = args[0];
index = stack[stack_ptr - 1];
if ((attrs[variable_id] & 0x1f) == 0x19) {
longptr_tmp = (long *)vars[variable_id];
stack[stack_ptr - 1] = longptr_tmp[index];
} else if ((attrs[variable_id] & 0x1f) == 0x1c) {
long_tmp = vars[variable_id] +
(index * sizeof(long));
stack[stack_ptr - 1] =
get_unaligned_be32(&p[long_tmp]);
} else
status = -ERANGE;
break;
case OP_PSHA:
if (!altera_check_stack(stack_ptr, 2, &status))
break;
variable_id = args[0];
if ((attrs[variable_id] & 0x18) != 0x08) {
status = -ERANGE;
break;
}
charptr_tmp = (u8 *)vars[variable_id];
count = stack[--stack_ptr];
index = stack[stack_ptr - 1];
if (version > 0)
count = 1 + count - index;
if ((count < 1) || (count > 32)) {
status = -ERANGE;
break;
}
long_tmp = 0L;
for (i = 0; i < count; ++i)
if (charptr_tmp[(i + index) >> 3] &
(1 << ((i + index) & 7)))
long_tmp |= (1L << i);
stack[stack_ptr - 1] = long_tmp;
break;
case OP_DYNA:
if (!altera_check_stack(stack_ptr, 1, &status))
break;
variable_id = args[0];
long_tmp = stack[--stack_ptr];
if (long_tmp > var_size[variable_id]) {
var_size[variable_id] = long_tmp;
if (attrs[variable_id] & 0x10)
long_tmp *= sizeof(long);
else
long_tmp = (long_tmp + 7) >> 3;
if (attrs[variable_id] & 0x80) {
kfree((void *)vars[variable_id]);
vars[variable_id] = 0;
}
vars[variable_id] = (long)
kzalloc(long_tmp, GFP_KERNEL);
if (vars[variable_id] == 0) {
status = -ENOMEM;
break;
}
attrs[variable_id] |= 0x80;
count = ((var_size[variable_id] + 7L) /
8L);
charptr_tmp = (u8 *)(vars[variable_id]);
for (index = 0; index < count; ++index)
charptr_tmp[index] = 0;
}
break;
case OP_EXPV:
if (!altera_check_stack(stack_ptr, 3, &status))
break;
if (version == 0) {
bad_opcode = 1;
break;
}
name = &p[str_table + args[0]];
variable_id = stack[--stack_ptr];
long_idx = stack[--stack_ptr];
long_idx2 = stack[--stack_ptr];
if (long_idx > long_idx2) {
status = -ERANGE;
break;
}
long_count = 1 + long_idx2 - long_idx;
charptr_tmp = (u8 *)vars[variable_id];
charptr_tmp2 = NULL;
if ((long_idx & 7L) != 0) {
s32 k = long_idx;
charptr_tmp2 =
kzalloc(((long_count + 7L) / 8L),
GFP_KERNEL);
if (charptr_tmp2 == NULL) {
status = -ENOMEM;
break;
}
for (i = 0; i < long_count; ++i) {
if (charptr_tmp[k >> 3] &
(1 << (k & 7)))
charptr_tmp2[i >> 3] |=
(1 << (i & 7));
else
charptr_tmp2[i >> 3] &=
~(1 << (i & 7));
++k;
}
charptr_tmp = charptr_tmp2;
} else if (long_idx != 0)
charptr_tmp = &charptr_tmp[long_idx >> 3];
altera_export_bool_array(name, charptr_tmp,
long_count);
if ((long_idx & 7L) != 0)
kfree(charptr_tmp2);
break;
case OP_COPY: {
s32 copy_count;
s32 copy_index;
s32 copy_index2;
s32 destleft;
s32 src_count;
s32 dest_count;
int src_reverse = 0;
int dest_reverse = 0;
if (!altera_check_stack(stack_ptr, 3, &status))
break;
copy_count = stack[--stack_ptr];
copy_index = stack[--stack_ptr];
copy_index2 = stack[--stack_ptr];
reverse = 0;
if (version > 0) {
destleft = stack[--stack_ptr];
if (copy_count > copy_index) {
src_reverse = 1;
reverse = 1;
src_count = 1 + copy_count - copy_index;
} else {
src_count = 1 + copy_index - copy_count;
copy_index = copy_count;
}
if (copy_index2 > destleft) {
dest_reverse = 1;
reverse = !reverse;
dest_count = 1 + copy_index2 - destleft;
copy_index2 = destleft;
} else
dest_count = 1 + destleft - copy_index2;
copy_count = (src_count < dest_count) ?
src_count : dest_count;
if ((src_reverse || dest_reverse) &&
(src_count != dest_count))
status = -ERANGE;
}
count = copy_count;
index = copy_index;
index2 = copy_index2;
variable_id = args[1];
if ((version > 0) &&
((attrs[variable_id] & 0x9c) == 0x0c)) {
long_tmp =
(var_size[variable_id] + 7L) >> 3L;
charptr_tmp2 = (u8 *)vars[variable_id];
charptr_tmp =
kzalloc(long_tmp, GFP_KERNEL);
vars[variable_id] = (long)charptr_tmp;
if (vars[variable_id] == 0) {
status = -ENOMEM;
break;
}
for (long_idx = 0L; long_idx < long_tmp;
++long_idx)
charptr_tmp[long_idx] = 0;
for (long_idx = 0L;
long_idx < var_size[variable_id];
++long_idx) {
long_idx2 = long_idx;
if (charptr_tmp2[long_idx2 >> 3] &
(1 << (long_idx2 & 7)))
charptr_tmp[long_idx >> 3] |=
(1 << (long_idx & 7));
}
attrs[variable_id] |= 0x80;
attrs[variable_id] &= ~0x04;
attrs[variable_id] |= 0x01;
}
charptr_tmp = (u8 *)vars[args[1]];
charptr_tmp2 = (u8 *)vars[args[0]];
if ((attrs[args[1]] & 0x1c) != 0x08) {
status = -ERANGE;
break;
}
if (count < 1) {
status = -ERANGE;
break;
}
if (reverse)
index2 += (count - 1);
for (i = 0; i < count; ++i) {
if (charptr_tmp2[index >> 3] &
(1 << (index & 7)))
charptr_tmp[index2 >> 3] |=
(1 << (index2 & 7));
else
charptr_tmp[index2 >> 3] &=
~(1 << (index2 & 7));
++index;
if (reverse)
--index2;
else
++index2;
}
break;
}
case OP_DSC:
case OP_ISC: {
s32 scan_right, scan_left;
s32 capture_count = 0;
s32 scan_count = 0;
s32 capture_index;
s32 scan_index;
if (!altera_check_stack(stack_ptr, 3, &status))
break;
capture_index = stack[--stack_ptr];
scan_index = stack[--stack_ptr];
if (version > 0) {
scan_right = stack[--stack_ptr];
scan_left = stack[--stack_ptr];
capture_count = 1 + scan_index - capture_index;
scan_count = 1 + scan_left - scan_right;
scan_index = scan_right;
}
long_count = stack[--stack_ptr];
variable_id = args[1];
if ((version > 0) &&
((attrs[variable_id] & 0x9c) == 0x0c)) {
long_tmp =
(var_size[variable_id] + 7L) >> 3L;
charptr_tmp2 = (u8 *)vars[variable_id];
charptr_tmp =
kzalloc(long_tmp, GFP_KERNEL);
vars[variable_id] = (long)charptr_tmp;
if (vars[variable_id] == 0) {
status = -ENOMEM;
break;
}
for (long_idx = 0L; long_idx < long_tmp;
++long_idx)
charptr_tmp[long_idx] = 0;
for (long_idx = 0L;
long_idx < var_size[variable_id];
++long_idx) {
long_idx2 = long_idx;
if (charptr_tmp2[long_idx2 >> 3] &
(1 << (long_idx2 & 7)))
charptr_tmp[long_idx >> 3] |=
(1 << (long_idx & 7));
}
attrs[variable_id] |= 0x80;
attrs[variable_id] &= ~0x04;
attrs[variable_id] |= 0x01;
}
charptr_tmp = (u8 *)vars[args[0]];
charptr_tmp2 = (u8 *)vars[args[1]];
if ((version > 0) &&
((long_count > capture_count) ||
(long_count > scan_count))) {
status = -ERANGE;
break;
}
if ((attrs[args[1]] & 0x1c) != 0x08) {
status = -ERANGE;
break;
}
if (status == 0) {
if (opcode == 0x82)
status = altera_swap_dr(astate,
long_count,
charptr_tmp,
scan_index,
charptr_tmp2,
capture_index);
else
status = altera_swap_ir(astate,
long_count,
charptr_tmp,
scan_index,
charptr_tmp2,
capture_index);
}
break;
}
case OP_WAIT:
if (!altera_check_stack(stack_ptr, 2, &status))
break;
long_tmp = stack[--stack_ptr];
if (long_tmp != 0L)
status = altera_wait_cycles(astate, long_tmp,
args[0]);
long_tmp = stack[--stack_ptr];
if ((status == 0) && (long_tmp != 0L))
status = altera_wait_msecs(astate,
long_tmp,
args[0]);
if ((status == 0) && (args[1] != args[0]))
status = altera_goto_jstate(astate,
args[1]);
if (version > 0) {
--stack_ptr;
--stack_ptr;
}
break;
case OP_CMPA: {
s32 a, b;
u8 *source1 = (u8 *)vars[args[0]];
u8 *source2 = (u8 *)vars[args[1]];
u8 *mask = (u8 *)vars[args[2]];
u32 index1;
u32 index2;
u32 mask_index;
if (!altera_check_stack(stack_ptr, 4, &status))
break;
index1 = stack[--stack_ptr];
index2 = stack[--stack_ptr];
mask_index = stack[--stack_ptr];
long_count = stack[--stack_ptr];
if (version > 0) {
s32 mask_right = stack[--stack_ptr];
s32 mask_left = stack[--stack_ptr];
a = 1 + index2 - index1;
b = 1 + long_count - mask_index;
a = (a < b) ? a : b;
b = 1 + mask_left - mask_right;
a = (a < b) ? a : b;
index2 = mask_index;
mask_index = mask_right;
long_count = a;
}
long_tmp = 1L;
if (long_count < 1)
status = -ERANGE;
else {
count = long_count;
for (i = 0; i < count; ++i) {
if (mask[mask_index >> 3] &
(1 << (mask_index & 7))) {
a = source1[index1 >> 3] &
(1 << (index1 & 7))
? 1 : 0;
b = source2[index2 >> 3] &
(1 << (index2 & 7))
? 1 : 0;
if (a != b)
long_tmp = 0L;
}
++index1;
++index2;
++mask_index;
}
}
stack[stack_ptr++] = long_tmp;
break;
}
default:
bad_opcode = 1;
break;
}
if (bad_opcode)
status = -ENOSYS;
if ((stack_ptr < 0) || (stack_ptr >= ALTERA_STACK_SIZE))
status = -EOVERFLOW;
if (status != 0) {
done = 1;
*error_address = (s32)(opcode_address - code_sect);
}
}
altera_free_buffers(astate);
if ((attrs != NULL) && (vars != NULL))
for (i = 0; i < sym_count; ++i)
if (attrs[i] & 0x80)
kfree((void *)vars[i]);
kfree(vars);
kfree(var_size);
kfree(attrs);
kfree(proc_attributes);
return status;
}
static int altera_get_note(u8 *p, s32 program_size,
s32 *offset, char *key, char *value, int length)
{
int status = -ENODATA;
u32 note_strings = 0L;
u32 note_table = 0L;
u32 note_count = 0L;
u32 first_word = 0L;
int version = 0;
int delta = 0;
char *key_ptr;
char *value_ptr;
int i;
if (program_size > 52L) {
first_word = get_unaligned_be32(&p[0]);
version = (first_word & 1L);
delta = version * 8;
note_strings = get_unaligned_be32(&p[8 + delta]);
note_table = get_unaligned_be32(&p[12 + delta]);
note_count = get_unaligned_be32(&p[44 + (2 * delta)]);
}
if ((first_word != 0x4A414D00L) && (first_word != 0x4A414D01L))
return -EIO;
if (note_count <= 0L)
return status;
if (offset == NULL) {
for (i = 0; (i < note_count) &&
(status != 0); ++i) {
key_ptr = &p[note_strings +
get_unaligned_be32(
&p[note_table + (8 * i)])];
if ((strnicmp(key, key_ptr, strlen(key_ptr)) == 0) &&
(key != NULL)) {
status = 0;
value_ptr = &p[note_strings +
get_unaligned_be32(
&p[note_table + (8 * i) + 4])];
if (value != NULL)
strlcpy(value, value_ptr, length);
}
}
} else {
i = *offset;
if ((i >= 0) && (i < note_count)) {
status = 0;
if (key != NULL)
strlcpy(key, &p[note_strings +
get_unaligned_be32(
&p[note_table + (8 * i)])],
length);
if (value != NULL)
strlcpy(value, &p[note_strings +
get_unaligned_be32(
&p[note_table + (8 * i) + 4])],
length);
*offset = i + 1;
}
}
return status;
}
static int altera_check_crc(u8 *p, s32 program_size)
{
int status = 0;
u16 local_expected = 0,
local_actual = 0,
shift_reg = 0xffff;
int bit, feedback;
u8 databyte;
u32 i;
u32 crc_section = 0L;
u32 first_word = 0L;
int version = 0;
int delta = 0;
if (program_size > 52L) {
first_word = get_unaligned_be32(&p[0]);
version = (first_word & 1L);
delta = version * 8;
crc_section = get_unaligned_be32(&p[32 + delta]);
}
if ((first_word != 0x4A414D00L) && (first_word != 0x4A414D01L))
status = -EIO;
if (crc_section >= program_size)
status = -EIO;
if (status == 0) {
local_expected = (u16)get_unaligned_be16(&p[crc_section]);
for (i = 0; i < crc_section; ++i) {
databyte = p[i];
for (bit = 0; bit < 8; bit++) {
feedback = (databyte ^ shift_reg) & 0x01;
shift_reg >>= 1;
if (feedback)
shift_reg ^= 0x8408;
databyte >>= 1;
}
}
local_actual = (u16)~shift_reg;
if (local_expected != local_actual)
status = -EILSEQ;
}
if (debug || status) {
switch (status) {
case 0:
printk(KERN_INFO "%s: CRC matched: %04x\n", __func__,
local_actual);
break;
case -EILSEQ:
printk(KERN_ERR "%s: CRC mismatch: expected %04x, "
"actual %04x\n", __func__, local_expected,
local_actual);
break;
case -ENODATA:
printk(KERN_ERR "%s: expected CRC not found, "
"actual CRC = %04x\n", __func__,
local_actual);
break;
case -EIO:
printk(KERN_ERR "%s: error: format isn't "
"recognized.\n", __func__);
break;
default:
printk(KERN_ERR "%s: CRC function returned error "
"code %d\n", __func__, status);
break;
}
}
return status;
}
static int altera_get_file_info(u8 *p,
s32 program_size,
int *format_version,
int *action_count,
int *procedure_count)
{
int status = -EIO;
u32 first_word = 0;
int version = 0;
if (program_size <= 52L)
return status;
first_word = get_unaligned_be32(&p[0]);
if ((first_word == 0x4A414D00L) || (first_word == 0x4A414D01L)) {
status = 0;
version = (first_word & 1L);
*format_version = version + 1;
if (version > 0) {
*action_count = get_unaligned_be32(&p[48]);
*procedure_count = get_unaligned_be32(&p[52]);
}
}
return status;
}
static int altera_get_act_info(u8 *p,
s32 program_size,
int index,
char **name,
char **description,
struct altera_procinfo **proc_list)
{
int status = -EIO;
struct altera_procinfo *procptr = NULL;
struct altera_procinfo *tmpptr = NULL;
u32 first_word = 0L;
u32 action_table = 0L;
u32 proc_table = 0L;
u32 str_table = 0L;
u32 note_strings = 0L;
u32 action_count = 0L;
u32 proc_count = 0L;
u32 act_name_id = 0L;
u32 act_desc_id = 0L;
u32 act_proc_id = 0L;
u32 act_proc_name = 0L;
u8 act_proc_attribute = 0;
if (program_size <= 52L)
return status;
first_word = get_unaligned_be32(&p[0]);
if (first_word != 0x4A414D01L)
return status;
action_table = get_unaligned_be32(&p[4]);
proc_table = get_unaligned_be32(&p[8]);
str_table = get_unaligned_be32(&p[12]);
note_strings = get_unaligned_be32(&p[16]);
action_count = get_unaligned_be32(&p[48]);
proc_count = get_unaligned_be32(&p[52]);
if (index >= action_count)
return status;
act_name_id = get_unaligned_be32(&p[action_table + (12 * index)]);
act_desc_id = get_unaligned_be32(&p[action_table + (12 * index) + 4]);
act_proc_id = get_unaligned_be32(&p[action_table + (12 * index) + 8]);
*name = &p[str_table + act_name_id];
if (act_desc_id < (note_strings - str_table))
*description = &p[str_table + act_desc_id];
do {
act_proc_name = get_unaligned_be32(
&p[proc_table + (13 * act_proc_id)]);
act_proc_attribute =
(p[proc_table + (13 * act_proc_id) + 8] & 0x03);
procptr = (struct altera_procinfo *)
kzalloc(sizeof(struct altera_procinfo),
GFP_KERNEL);
if (procptr == NULL)
status = -ENOMEM;
else {
procptr->name = &p[str_table + act_proc_name];
procptr->attrs = act_proc_attribute;
procptr->next = NULL;
if (*proc_list == NULL)
*proc_list = procptr;
else {
tmpptr = *proc_list;
while (tmpptr->next != NULL)
tmpptr = tmpptr->next;
tmpptr->next = procptr;
}
}
act_proc_id = get_unaligned_be32(
&p[proc_table + (13 * act_proc_id) + 4]);
} while ((act_proc_id != 0) && (act_proc_id < proc_count));
return status;
}
int altera_init(struct altera_config *config, const struct firmware *fw)
{
struct altera_state *astate = NULL;
struct altera_procinfo *proc_list = NULL;
struct altera_procinfo *procptr = NULL;
char *key = NULL;
char *value = NULL;
char *action_name = NULL;
char *description = NULL;
int exec_result = 0;
int exit_code = 0;
int format_version = 0;
int action_count = 0;
int procedure_count = 0;
int index = 0;
s32 offset = 0L;
s32 error_address = 0L;
int retval = 0;
key = kzalloc(33, GFP_KERNEL);
if (!key) {
retval = -ENOMEM;
goto out;
}
value = kzalloc(257, GFP_KERNEL);
if (!value) {
retval = -ENOMEM;
goto free_key;
}
astate = kzalloc(sizeof(struct altera_state), GFP_KERNEL);
if (!astate) {
retval = -ENOMEM;
goto free_value;
}
astate->config = config;
if (!astate->config->jtag_io) {
dprintk(KERN_INFO "%s: using byteblaster!\n", __func__);
astate->config->jtag_io = netup_jtag_io_lpt;
}
altera_check_crc((u8 *)fw->data, fw->size);
if (debug) {
altera_get_file_info((u8 *)fw->data, fw->size, &format_version,
&action_count, &procedure_count);
printk(KERN_INFO "%s: File format is %s ByteCode format\n",
__func__, (format_version == 2) ? "Jam STAPL" :
"pre-standardized Jam 1.1");
while (altera_get_note((u8 *)fw->data, fw->size,
&offset, key, value, 256) == 0)
printk(KERN_INFO "%s: NOTE \"%s\" = \"%s\"\n",
__func__, key, value);
}
if (debug && (format_version == 2) && (action_count > 0)) {
printk(KERN_INFO "%s: Actions available:\n", __func__);
for (index = 0; index < action_count; ++index) {
altera_get_act_info((u8 *)fw->data, fw->size,
index, &action_name,
&description,
&proc_list);
if (description == NULL)
printk(KERN_INFO "%s: %s\n",
__func__,
action_name);
else
printk(KERN_INFO "%s: %s \"%s\"\n",
__func__,
action_name,
description);
procptr = proc_list;
while (procptr != NULL) {
if (procptr->attrs != 0)
printk(KERN_INFO "%s: %s (%s)\n",
__func__,
procptr->name,
(procptr->attrs == 1) ?
"optional" : "recommended");
proc_list = procptr->next;
kfree(procptr);
procptr = proc_list;
}
}
printk(KERN_INFO "\n");
}
exec_result = altera_execute(astate, (u8 *)fw->data, fw->size,
&error_address, &exit_code, &format_version);
if (exit_code)
exec_result = -EREMOTEIO;
if ((format_version == 2) && (exec_result == -EINVAL)) {
if (astate->config->action == NULL)
printk(KERN_ERR "%s: error: no action specified for "
"Jam STAPL file.\nprogram terminated.\n",
__func__);
else
printk(KERN_ERR "%s: error: action \"%s\""
" is not supported "
"for this Jam STAPL file.\n"
"Program terminated.\n", __func__,
astate->config->action);
} else if (exec_result)
printk(KERN_ERR "%s: error %d\n", __func__, exec_result);
kfree(astate);
free_value:
kfree(value);
free_key:
kfree(key);
out:
return retval;
}
