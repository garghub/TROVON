static const struct tilegx_opcode *
find_opcode(tilegx_bundle_bits bits, const unsigned short *table)
{
int index = 0;
while (1)
{
unsigned short bitspec = table[index];
unsigned int bitfield =
((unsigned int)(bits >> (bitspec & 63))) & (bitspec >> 6);
unsigned short next = table[index + 1 + bitfield];
if (next <= TILEGX_OPC_NONE)
return &tilegx_opcodes[next];
index = next - TILEGX_OPC_NONE;
}
}
int
parse_insn_tilegx(tilegx_bundle_bits bits,
unsigned long long pc,
struct tilegx_decoded_instruction
decoded[TILEGX_MAX_INSTRUCTIONS_PER_BUNDLE])
{
int num_instructions = 0;
int pipe;
int min_pipe, max_pipe;
if ((bits & TILEGX_BUNDLE_MODE_MASK) == 0)
{
min_pipe = TILEGX_PIPELINE_X0;
max_pipe = TILEGX_PIPELINE_X1;
}
else
{
min_pipe = TILEGX_PIPELINE_Y0;
max_pipe = TILEGX_PIPELINE_Y2;
}
for (pipe = min_pipe; pipe <= max_pipe; pipe++)
{
const struct tilegx_opcode *opc;
struct tilegx_decoded_instruction *d;
int i;
d = &decoded[num_instructions++];
opc = find_opcode (bits, tilegx_bundle_decoder_fsms[pipe]);
d->opcode = opc;
for (i = 0; i < opc->num_operands; i++)
{
const struct tilegx_operand *op =
&tilegx_operands[opc->operands[pipe][i]];
int raw_opval = op->extract (bits);
long long opval;
if (op->is_signed)
{
int shift = (int)((sizeof(int) * 8) - op->num_bits);
raw_opval = (raw_opval << shift) >> shift;
}
if (op->type == TILEGX_OP_TYPE_ADDRESS)
opval = (raw_opval * TILEGX_BUNDLE_SIZE_IN_BYTES) + pc;
else
opval = raw_opval;
d->operands[i] = op;
d->operand_values[i] = opval;
}
}
return num_instructions;
}
