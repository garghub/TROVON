static void
move_subword (
hive_uedge *target,
unsigned target_bit,
hive_uedge src,
unsigned src_start,
unsigned src_end)
{
unsigned int start_elem = target_bit / uedge_bits;
unsigned int start_bit = target_bit % uedge_bits;
unsigned subword_width = src_end - src_start;
hive_uedge src_subword = SUBWORD(src, src_start, src_end);
if (subword_width + start_bit > uedge_bits) {
hive_uedge old_val1;
hive_uedge old_val0 = INV_SUBWORD(target[start_elem], start_bit, uedge_bits);
target[start_elem] = old_val0 | (src_subword << start_bit);
old_val1 = INV_SUBWORD(target[start_elem+1], 0, subword_width + start_bit - uedge_bits);
target[start_elem+1] = old_val1 | (src_subword >> ( uedge_bits - start_bit));
} else {
hive_uedge old_val = INV_SUBWORD(target[start_elem], start_bit, start_bit + subword_width);
target[start_elem] = old_val | (src_subword << start_bit);
}
}
static void
hive_sim_wide_unpack(
hive_wide vector,
hive_wide elem,
hive_uint elem_bits,
hive_uint index)
{
unsigned int start_elem = (elem_bits * index) / uedge_bits;
unsigned int start_bit = (elem_bits * index) % uedge_bits;
unsigned int end_elem = (elem_bits * (index + 1) - 1) / uedge_bits;
unsigned int end_bit = ((elem_bits * (index + 1) - 1) % uedge_bits) + 1;
if (elem_bits == uedge_bits) {
elem[0] = vector[index];
} else if (start_elem == end_elem) {
move_subword(elem, 0, vector[start_elem], start_bit, end_bit);
} else {
unsigned int bits_written = 0;
unsigned int i;
move_upper_bits(elem, bits_written, vector[start_elem], start_bit);
bits_written += (64 - start_bit);
for(i = start_elem+1; i < end_elem; i++) {
move_word(elem, bits_written, vector[i]);
bits_written += uedge_bits;
}
move_lower_bits(elem, bits_written , vector[end_elem], end_bit);
}
}
static void
hive_sim_wide_pack(
hive_wide vector,
hive_wide elem,
hive_uint elem_bits,
hive_uint index)
{
unsigned int start_elem = (elem_bits * index) / uedge_bits;
if (elem_bits == uedge_bits) {
vector[start_elem] = elem[0];
} else if (elem_bits > uedge_bits) {
unsigned bits_to_write = elem_bits;
unsigned start_bit = elem_bits * index;
unsigned i = 0;
for(; bits_to_write > uedge_bits; bits_to_write -= uedge_bits, i++, start_bit += uedge_bits) {
move_word(vector, start_bit, elem[i]);
}
move_lower_bits(vector, start_bit, elem[i], bits_to_write);
} else {
move_lower_bits(vector, elem_bits * index, elem[0], elem_bits);
}
}
static void load_vector (
const isp_ID_t ID,
t_vmem_elem *to,
const t_vmem_elem *from)
{
unsigned i;
hive_uedge *data;
unsigned size = sizeof(short)*ISP_NWAY;
VMEM_ARRAY(v, 2*ISP_NWAY);
assert(ISP_BAMEM_BASE[ID] != (hrt_address)-1);
#if !defined(HRT_MEMORY_ACCESS)
ia_css_device_load(ISP_BAMEM_BASE[ID] + (unsigned long)from, &v[0][0], size);
#else
hrt_master_port_load(ISP_BAMEM_BASE[ID] + (unsigned long)from, &v[0][0], size);
#endif
data = (hive_uedge *)v;
for (i = 0; i < ISP_NWAY; i++) {
hive_uedge elem = 0;
hive_sim_wide_unpack(data, &elem, ISP_VEC_ELEMBITS, i);
to[i] = elem;
}
hrt_sleep();
}
static void store_vector (
const isp_ID_t ID,
t_vmem_elem *to,
const t_vmem_elem *from)
{
unsigned i;
unsigned size = sizeof(short)*ISP_NWAY;
VMEM_ARRAY(v, 2*ISP_NWAY);
hive_uedge *data = (hive_uedge *)v;
for (i = 0; i < ISP_NWAY; i++) {
hive_sim_wide_pack(data, (hive_wide)&from[i], ISP_VEC_ELEMBITS, i);
}
assert(ISP_BAMEM_BASE[ID] != (hrt_address)-1);
#if !defined(HRT_MEMORY_ACCESS)
ia_css_device_store(ISP_BAMEM_BASE[ID] + (unsigned long)to, &v, size);
#else
hrt_master_port_store(ISP_BAMEM_BASE[ID] + (unsigned long)to, &v, size);
#endif
hrt_sleep();
}
void isp_vmem_load(
const isp_ID_t ID,
const t_vmem_elem *from,
t_vmem_elem *to,
unsigned elems)
{
unsigned c;
const t_vmem_elem *vp = from;
assert(ID < N_ISP_ID);
assert((unsigned long)from % ISP_VEC_ALIGN == 0);
assert(elems % ISP_NWAY == 0);
for (c = 0; c < elems; c += ISP_NWAY) {
load_vector(ID, &to[c], vp);
vp = (t_vmem_elem *)((char*)vp + ISP_VEC_ALIGN);
}
}
void isp_vmem_store(
const isp_ID_t ID,
t_vmem_elem *to,
const t_vmem_elem *from,
unsigned elems)
{
unsigned c;
t_vmem_elem *vp = to;
assert(ID < N_ISP_ID);
assert((unsigned long)to % ISP_VEC_ALIGN == 0);
assert(elems % ISP_NWAY == 0);
for (c = 0; c < elems; c += ISP_NWAY) {
store_vector (ID, vp, &from[c]);
vp = (t_vmem_elem *)((char*)vp + ISP_VEC_ALIGN);
}
}
void isp_vmem_2d_load (
const isp_ID_t ID,
const t_vmem_elem *from,
t_vmem_elem *to,
unsigned height,
unsigned width,
unsigned stride_to,
unsigned stride_from )
{
unsigned h;
assert(ID < N_ISP_ID);
assert((unsigned long)from % ISP_VEC_ALIGN == 0);
assert(width % ISP_NWAY == 0);
assert(stride_from % ISP_NWAY == 0);
for (h = 0; h < height; h++) {
unsigned c;
const t_vmem_elem *vp = from;
for (c = 0; c < width; c += ISP_NWAY) {
load_vector(ID, &to[stride_to*h + c], vp);
vp = (t_vmem_elem *)((char*)vp + ISP_VEC_ALIGN);
}
from = (const t_vmem_elem *)((const char *)from + stride_from/ISP_NWAY*ISP_VEC_ALIGN);
}
}
void isp_vmem_2d_store (
const isp_ID_t ID,
t_vmem_elem *to,
const t_vmem_elem *from,
unsigned height,
unsigned width,
unsigned stride_to,
unsigned stride_from )
{
unsigned h;
assert(ID < N_ISP_ID);
assert((unsigned long)to % ISP_VEC_ALIGN == 0);
assert(width % ISP_NWAY == 0);
assert(stride_to % ISP_NWAY == 0);
for (h = 0; h < height; h++) {
unsigned c;
t_vmem_elem *vp = to;
for (c = 0; c < width; c += ISP_NWAY) {
store_vector (ID, vp, &from[stride_from*h + c]);
vp = (t_vmem_elem *)((char*)vp + ISP_VEC_ALIGN);
}
to = (t_vmem_elem *)((char *)to + stride_to/ISP_NWAY*ISP_VEC_ALIGN);
}
}
