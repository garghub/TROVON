static int awg_generate_instr(enum opcode opcode,
long int arg,
long int mux_sel,
long int data_en,
struct awg_code_generation_params *fwparams)
{
u32 instruction = 0;
u32 mux = (mux_sel << 8) & 0x1ff;
u32 data_enable = (data_en << 9) & 0x2ff;
long int arg_tmp = arg;
while (arg_tmp > 0) {
arg = arg_tmp;
if (fwparams->instruction_offset >= AWG_MAX_INST) {
DRM_ERROR("too many number of instructions\n");
return -EINVAL;
}
switch (opcode) {
case SKIP:
arg--;
arg_tmp--;
if (arg < 0) {
return 0;
}
if (arg == 0) {
opcode = SET;
break;
}
mux = 0;
data_enable = 0;
arg &= AWG_MAX_ARG;
break;
case REPEAT:
case REPLAY:
if (arg == 0) {
return 0;
}
mux = 0;
data_enable = 0;
arg &= AWG_MAX_ARG;
break;
case JUMP:
mux = 0;
data_enable = 0;
arg |= 0x40;
arg &= AWG_MAX_ARG;
break;
case STOP:
arg = 0;
break;
case SET:
case RPTSET:
case RPLSET:
case HOLD:
arg &= (0x0ff);
break;
default:
DRM_ERROR("instruction %d does not exist\n", opcode);
return -EINVAL;
}
arg_tmp = arg_tmp - arg;
arg = ((arg + mux) + data_enable);
instruction = ((opcode) << AWG_OPCODE_OFFSET) | arg;
fwparams->ram_code[fwparams->instruction_offset] =
instruction & (0x3fff);
fwparams->instruction_offset++;
}
return 0;
}
static int awg_generate_line_signal(
struct awg_code_generation_params *fwparams,
struct awg_timing *timing)
{
long int val;
int ret = 0;
if (timing->trailing_pixels > 0) {
val = timing->blanking_level;
ret |= awg_generate_instr(RPLSET, val, 0, 0, fwparams);
val = timing->trailing_pixels - 1 + AWG_DELAY;
ret |= awg_generate_instr(SKIP, val, 0, 0, fwparams);
}
val = timing->blanking_level;
ret |= awg_generate_instr((timing->trailing_pixels > 0) ? SET : RPLSET,
val, 0, 1, fwparams);
if (timing->blanking_pixels > 0) {
val = timing->active_pixels - 1;
ret |= awg_generate_instr(SKIP, val, 0, 1, fwparams);
val = timing->blanking_level;
ret |= awg_generate_instr(SET, val, 0, 0, fwparams);
}
return ret;
}
int sti_awg_generate_code_data_enable_mode(
struct awg_code_generation_params *fwparams,
struct awg_timing *timing)
{
long int val, tmp_val;
int ret = 0;
if (timing->trailing_lines > 0) {
val = timing->blanking_level;
ret |= awg_generate_instr(RPLSET, val, 0, 0, fwparams);
val = timing->trailing_lines - 1;
ret |= awg_generate_instr(REPLAY, val, 0, 0, fwparams);
}
tmp_val = timing->active_lines - 1;
while (tmp_val > 0) {
ret |= awg_generate_line_signal(fwparams, timing);
ret |= awg_generate_instr(REPLAY,
min_t(int, AWG_MAX_ARG, tmp_val),
0, 0, fwparams);
tmp_val -= AWG_MAX_ARG;
}
if (timing->blanking_lines > 0) {
val = timing->blanking_level;
ret |= awg_generate_instr(RPLSET, val, 0, 0, fwparams);
val = timing->blanking_lines - 1;
ret |= awg_generate_instr(REPLAY, val, 0, 0, fwparams);
}
return ret;
}
