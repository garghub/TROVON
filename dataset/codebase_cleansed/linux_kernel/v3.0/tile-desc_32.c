const struct tile_opcode *
find_opcode(tile_bundle_bits bits, tile_pipeline pipe)
{
const unsigned short *table = tile_bundle_decoder_fsms[pipe];
int index = 0;
while (1)
{
unsigned short bitspec = table[index];
unsigned int bitfield =
((unsigned int)(bits >> (bitspec & 63))) & (bitspec >> 6);
unsigned short next = table[index + 1 + bitfield];
if (next <= TILE_OPC_NONE)
return &tile_opcodes[next];
index = next - TILE_OPC_NONE;
}
}
int
parse_insn_tile(tile_bundle_bits bits,
unsigned int pc,
struct tile_decoded_instruction
decoded[TILE_MAX_INSTRUCTIONS_PER_BUNDLE])
{
int num_instructions = 0;
int pipe;
int min_pipe, max_pipe;
if ((bits & TILE_BUNDLE_Y_ENCODING_MASK) == 0)
{
min_pipe = TILE_PIPELINE_X0;
max_pipe = TILE_PIPELINE_X1;
}
else
{
min_pipe = TILE_PIPELINE_Y0;
max_pipe = TILE_PIPELINE_Y2;
}
for (pipe = min_pipe; pipe <= max_pipe; pipe++)
{
const struct tile_opcode *opc;
struct tile_decoded_instruction *d;
int i;
d = &decoded[num_instructions++];
opc = find_opcode (bits, (tile_pipeline)pipe);
d->opcode = opc;
for (i = 0; i < opc->num_operands; i++)
{
const struct tile_operand *op =
&tile_operands[opc->operands[pipe][i]];
int opval = op->extract (bits);
if (op->is_signed)
{
int shift = (int)((sizeof(int) * 8) - op->num_bits);
opval = (opval << shift) >> shift;
}
if (op->type == TILE_OP_TYPE_ADDRESS)
{
opval *= TILE_BUNDLE_SIZE_IN_BYTES;
opval += (int)pc;
}
d->operands[i] = op;
d->operand_values[i] = opval;
}
}
return num_instructions;
}
