const struct tilepro_opcode *
find_opcode(tilepro_bundle_bits bits, tilepro_pipeline pipe)
{
const unsigned short *table = tilepro_bundle_decoder_fsms[pipe];
int index = 0;
while (1)
{
unsigned short bitspec = table[index];
unsigned int bitfield =
((unsigned int)(bits >> (bitspec & 63))) & (bitspec >> 6);
unsigned short next = table[index + 1 + bitfield];
if (next <= TILEPRO_OPC_NONE)
return &tilepro_opcodes[next];
index = next - TILEPRO_OPC_NONE;
}
}
int
parse_insn_tilepro(tilepro_bundle_bits bits,
unsigned int pc,
struct tilepro_decoded_instruction
decoded[TILEPRO_MAX_INSTRUCTIONS_PER_BUNDLE])
{
int num_instructions = 0;
int pipe;
int min_pipe, max_pipe;
if ((bits & TILEPRO_BUNDLE_Y_ENCODING_MASK) == 0)
{
min_pipe = TILEPRO_PIPELINE_X0;
max_pipe = TILEPRO_PIPELINE_X1;
}
else
{
min_pipe = TILEPRO_PIPELINE_Y0;
max_pipe = TILEPRO_PIPELINE_Y2;
}
for (pipe = min_pipe; pipe <= max_pipe; pipe++)
{
const struct tilepro_opcode *opc;
struct tilepro_decoded_instruction *d;
int i;
d = &decoded[num_instructions++];
opc = find_opcode (bits, (tilepro_pipeline)pipe);
d->opcode = opc;
for (i = 0; i < opc->num_operands; i++)
{
const struct tilepro_operand *op =
&tilepro_operands[opc->operands[pipe][i]];
int opval = op->extract (bits);
if (op->is_signed)
{
int shift = (int)((sizeof(int) * 8) - op->num_bits);
opval = (opval << shift) >> shift;
}
if (op->type == TILEPRO_OP_TYPE_ADDRESS)
{
opval *= TILEPRO_BUNDLE_SIZE_IN_BYTES;
opval += (int)pc;
}
d->operands[i] = op;
d->operand_values[i] = opval;
}
}
return num_instructions;
}
