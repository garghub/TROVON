static void mvpp2_write(struct mvpp2 *priv, u32 offset, u32 data)
{
writel(data, priv->base + offset);
}
static u32 mvpp2_read(struct mvpp2 *priv, u32 offset)
{
return readl(priv->base + offset);
}
static void mvpp2_txq_inc_get(struct mvpp2_txq_pcpu *txq_pcpu)
{
txq_pcpu->txq_get_index++;
if (txq_pcpu->txq_get_index == txq_pcpu->size)
txq_pcpu->txq_get_index = 0;
}
static void mvpp2_txq_inc_put(struct mvpp2_txq_pcpu *txq_pcpu,
struct sk_buff *skb,
struct mvpp2_tx_desc *tx_desc)
{
txq_pcpu->tx_skb[txq_pcpu->txq_put_index] = skb;
if (skb)
txq_pcpu->tx_buffs[txq_pcpu->txq_put_index] =
tx_desc->buf_phys_addr;
txq_pcpu->txq_put_index++;
if (txq_pcpu->txq_put_index == txq_pcpu->size)
txq_pcpu->txq_put_index = 0;
}
static inline int mvpp2_egress_port(struct mvpp2_port *port)
{
return MVPP2_MAX_TCONT + port->id;
}
static inline int mvpp2_txq_phys(int port, int txq)
{
return (MVPP2_MAX_TCONT + port) * MVPP2_MAX_TXQ + txq;
}
static int mvpp2_prs_hw_write(struct mvpp2 *priv, struct mvpp2_prs_entry *pe)
{
int i;
if (pe->index > MVPP2_PRS_TCAM_SRAM_SIZE - 1)
return -EINVAL;
pe->tcam.word[MVPP2_PRS_TCAM_INV_WORD] &= ~MVPP2_PRS_TCAM_INV_MASK;
mvpp2_write(priv, MVPP2_PRS_TCAM_IDX_REG, pe->index);
for (i = 0; i < MVPP2_PRS_TCAM_WORDS; i++)
mvpp2_write(priv, MVPP2_PRS_TCAM_DATA_REG(i), pe->tcam.word[i]);
mvpp2_write(priv, MVPP2_PRS_SRAM_IDX_REG, pe->index);
for (i = 0; i < MVPP2_PRS_SRAM_WORDS; i++)
mvpp2_write(priv, MVPP2_PRS_SRAM_DATA_REG(i), pe->sram.word[i]);
return 0;
}
static int mvpp2_prs_hw_read(struct mvpp2 *priv, struct mvpp2_prs_entry *pe)
{
int i;
if (pe->index > MVPP2_PRS_TCAM_SRAM_SIZE - 1)
return -EINVAL;
mvpp2_write(priv, MVPP2_PRS_TCAM_IDX_REG, pe->index);
pe->tcam.word[MVPP2_PRS_TCAM_INV_WORD] = mvpp2_read(priv,
MVPP2_PRS_TCAM_DATA_REG(MVPP2_PRS_TCAM_INV_WORD));
if (pe->tcam.word[MVPP2_PRS_TCAM_INV_WORD] & MVPP2_PRS_TCAM_INV_MASK)
return MVPP2_PRS_TCAM_ENTRY_INVALID;
for (i = 0; i < MVPP2_PRS_TCAM_WORDS; i++)
pe->tcam.word[i] = mvpp2_read(priv, MVPP2_PRS_TCAM_DATA_REG(i));
mvpp2_write(priv, MVPP2_PRS_SRAM_IDX_REG, pe->index);
for (i = 0; i < MVPP2_PRS_SRAM_WORDS; i++)
pe->sram.word[i] = mvpp2_read(priv, MVPP2_PRS_SRAM_DATA_REG(i));
return 0;
}
static void mvpp2_prs_hw_inv(struct mvpp2 *priv, int index)
{
mvpp2_write(priv, MVPP2_PRS_TCAM_IDX_REG, index);
mvpp2_write(priv, MVPP2_PRS_TCAM_DATA_REG(MVPP2_PRS_TCAM_INV_WORD),
MVPP2_PRS_TCAM_INV_MASK);
}
static void mvpp2_prs_shadow_set(struct mvpp2 *priv, int index, int lu)
{
priv->prs_shadow[index].valid = true;
priv->prs_shadow[index].lu = lu;
}
static void mvpp2_prs_shadow_ri_set(struct mvpp2 *priv, int index,
unsigned int ri, unsigned int ri_mask)
{
priv->prs_shadow[index].ri_mask = ri_mask;
priv->prs_shadow[index].ri = ri;
}
static void mvpp2_prs_tcam_lu_set(struct mvpp2_prs_entry *pe, unsigned int lu)
{
int enable_off = MVPP2_PRS_TCAM_EN_OFFS(MVPP2_PRS_TCAM_LU_BYTE);
pe->tcam.byte[MVPP2_PRS_TCAM_LU_BYTE] = lu;
pe->tcam.byte[enable_off] = MVPP2_PRS_LU_MASK;
}
static void mvpp2_prs_tcam_port_set(struct mvpp2_prs_entry *pe,
unsigned int port, bool add)
{
int enable_off = MVPP2_PRS_TCAM_EN_OFFS(MVPP2_PRS_TCAM_PORT_BYTE);
if (add)
pe->tcam.byte[enable_off] &= ~(1 << port);
else
pe->tcam.byte[enable_off] |= 1 << port;
}
static void mvpp2_prs_tcam_port_map_set(struct mvpp2_prs_entry *pe,
unsigned int ports)
{
unsigned char port_mask = MVPP2_PRS_PORT_MASK;
int enable_off = MVPP2_PRS_TCAM_EN_OFFS(MVPP2_PRS_TCAM_PORT_BYTE);
pe->tcam.byte[MVPP2_PRS_TCAM_PORT_BYTE] = 0;
pe->tcam.byte[enable_off] &= ~port_mask;
pe->tcam.byte[enable_off] |= ~ports & MVPP2_PRS_PORT_MASK;
}
static unsigned int mvpp2_prs_tcam_port_map_get(struct mvpp2_prs_entry *pe)
{
int enable_off = MVPP2_PRS_TCAM_EN_OFFS(MVPP2_PRS_TCAM_PORT_BYTE);
return ~(pe->tcam.byte[enable_off]) & MVPP2_PRS_PORT_MASK;
}
static void mvpp2_prs_tcam_data_byte_set(struct mvpp2_prs_entry *pe,
unsigned int offs, unsigned char byte,
unsigned char enable)
{
pe->tcam.byte[MVPP2_PRS_TCAM_DATA_BYTE(offs)] = byte;
pe->tcam.byte[MVPP2_PRS_TCAM_DATA_BYTE_EN(offs)] = enable;
}
static void mvpp2_prs_tcam_data_byte_get(struct mvpp2_prs_entry *pe,
unsigned int offs, unsigned char *byte,
unsigned char *enable)
{
*byte = pe->tcam.byte[MVPP2_PRS_TCAM_DATA_BYTE(offs)];
*enable = pe->tcam.byte[MVPP2_PRS_TCAM_DATA_BYTE_EN(offs)];
}
static bool mvpp2_prs_tcam_data_cmp(struct mvpp2_prs_entry *pe, int offs,
u16 data)
{
int off = MVPP2_PRS_TCAM_DATA_BYTE(offs);
u16 tcam_data;
tcam_data = (8 << pe->tcam.byte[off + 1]) | pe->tcam.byte[off];
if (tcam_data != data)
return false;
return true;
}
static void mvpp2_prs_tcam_ai_update(struct mvpp2_prs_entry *pe,
unsigned int bits, unsigned int enable)
{
int i, ai_idx = MVPP2_PRS_TCAM_AI_BYTE;
for (i = 0; i < MVPP2_PRS_AI_BITS; i++) {
if (!(enable & BIT(i)))
continue;
if (bits & BIT(i))
pe->tcam.byte[ai_idx] |= 1 << i;
else
pe->tcam.byte[ai_idx] &= ~(1 << i);
}
pe->tcam.byte[MVPP2_PRS_TCAM_EN_OFFS(ai_idx)] |= enable;
}
static int mvpp2_prs_tcam_ai_get(struct mvpp2_prs_entry *pe)
{
return pe->tcam.byte[MVPP2_PRS_TCAM_AI_BYTE];
}
static void mvpp2_prs_match_etype(struct mvpp2_prs_entry *pe, int offset,
unsigned short ethertype)
{
mvpp2_prs_tcam_data_byte_set(pe, offset + 0, ethertype >> 8, 0xff);
mvpp2_prs_tcam_data_byte_set(pe, offset + 1, ethertype & 0xff, 0xff);
}
static void mvpp2_prs_sram_bits_set(struct mvpp2_prs_entry *pe, int bit_num,
int val)
{
pe->sram.byte[MVPP2_BIT_TO_BYTE(bit_num)] |= (val << (bit_num % 8));
}
static void mvpp2_prs_sram_bits_clear(struct mvpp2_prs_entry *pe, int bit_num,
int val)
{
pe->sram.byte[MVPP2_BIT_TO_BYTE(bit_num)] &= ~(val << (bit_num % 8));
}
static void mvpp2_prs_sram_ri_update(struct mvpp2_prs_entry *pe,
unsigned int bits, unsigned int mask)
{
unsigned int i;
for (i = 0; i < MVPP2_PRS_SRAM_RI_CTRL_BITS; i++) {
int ri_off = MVPP2_PRS_SRAM_RI_OFFS;
if (!(mask & BIT(i)))
continue;
if (bits & BIT(i))
mvpp2_prs_sram_bits_set(pe, ri_off + i, 1);
else
mvpp2_prs_sram_bits_clear(pe, ri_off + i, 1);
mvpp2_prs_sram_bits_set(pe, MVPP2_PRS_SRAM_RI_CTRL_OFFS + i, 1);
}
}
static int mvpp2_prs_sram_ri_get(struct mvpp2_prs_entry *pe)
{
return pe->sram.word[MVPP2_PRS_SRAM_RI_WORD];
}
static void mvpp2_prs_sram_ai_update(struct mvpp2_prs_entry *pe,
unsigned int bits, unsigned int mask)
{
unsigned int i;
int ai_off = MVPP2_PRS_SRAM_AI_OFFS;
for (i = 0; i < MVPP2_PRS_SRAM_AI_CTRL_BITS; i++) {
if (!(mask & BIT(i)))
continue;
if (bits & BIT(i))
mvpp2_prs_sram_bits_set(pe, ai_off + i, 1);
else
mvpp2_prs_sram_bits_clear(pe, ai_off + i, 1);
mvpp2_prs_sram_bits_set(pe, MVPP2_PRS_SRAM_AI_CTRL_OFFS + i, 1);
}
}
static int mvpp2_prs_sram_ai_get(struct mvpp2_prs_entry *pe)
{
u8 bits;
int ai_off = MVPP2_BIT_TO_BYTE(MVPP2_PRS_SRAM_AI_OFFS);
int ai_en_off = ai_off + 1;
int ai_shift = MVPP2_PRS_SRAM_AI_OFFS % 8;
bits = (pe->sram.byte[ai_off] >> ai_shift) |
(pe->sram.byte[ai_en_off] << (8 - ai_shift));
return bits;
}
static void mvpp2_prs_sram_next_lu_set(struct mvpp2_prs_entry *pe,
unsigned int lu)
{
int sram_next_off = MVPP2_PRS_SRAM_NEXT_LU_OFFS;
mvpp2_prs_sram_bits_clear(pe, sram_next_off,
MVPP2_PRS_SRAM_NEXT_LU_MASK);
mvpp2_prs_sram_bits_set(pe, sram_next_off, lu);
}
static void mvpp2_prs_sram_shift_set(struct mvpp2_prs_entry *pe, int shift,
unsigned int op)
{
if (shift < 0) {
mvpp2_prs_sram_bits_set(pe, MVPP2_PRS_SRAM_SHIFT_SIGN_BIT, 1);
shift = 0 - shift;
} else {
mvpp2_prs_sram_bits_clear(pe, MVPP2_PRS_SRAM_SHIFT_SIGN_BIT, 1);
}
pe->sram.byte[MVPP2_BIT_TO_BYTE(MVPP2_PRS_SRAM_SHIFT_OFFS)] =
(unsigned char)shift;
mvpp2_prs_sram_bits_clear(pe, MVPP2_PRS_SRAM_OP_SEL_SHIFT_OFFS,
MVPP2_PRS_SRAM_OP_SEL_SHIFT_MASK);
mvpp2_prs_sram_bits_set(pe, MVPP2_PRS_SRAM_OP_SEL_SHIFT_OFFS, op);
mvpp2_prs_sram_bits_clear(pe, MVPP2_PRS_SRAM_OP_SEL_BASE_OFFS, 1);
}
static void mvpp2_prs_sram_offset_set(struct mvpp2_prs_entry *pe,
unsigned int type, int offset,
unsigned int op)
{
if (offset < 0) {
mvpp2_prs_sram_bits_set(pe, MVPP2_PRS_SRAM_UDF_SIGN_BIT, 1);
offset = 0 - offset;
} else {
mvpp2_prs_sram_bits_clear(pe, MVPP2_PRS_SRAM_UDF_SIGN_BIT, 1);
}
mvpp2_prs_sram_bits_clear(pe, MVPP2_PRS_SRAM_UDF_OFFS,
MVPP2_PRS_SRAM_UDF_MASK);
mvpp2_prs_sram_bits_set(pe, MVPP2_PRS_SRAM_UDF_OFFS, offset);
pe->sram.byte[MVPP2_BIT_TO_BYTE(MVPP2_PRS_SRAM_UDF_OFFS +
MVPP2_PRS_SRAM_UDF_BITS)] &=
~(MVPP2_PRS_SRAM_UDF_MASK >> (8 - (MVPP2_PRS_SRAM_UDF_OFFS % 8)));
pe->sram.byte[MVPP2_BIT_TO_BYTE(MVPP2_PRS_SRAM_UDF_OFFS +
MVPP2_PRS_SRAM_UDF_BITS)] |=
(offset >> (8 - (MVPP2_PRS_SRAM_UDF_OFFS % 8)));
mvpp2_prs_sram_bits_clear(pe, MVPP2_PRS_SRAM_UDF_TYPE_OFFS,
MVPP2_PRS_SRAM_UDF_TYPE_MASK);
mvpp2_prs_sram_bits_set(pe, MVPP2_PRS_SRAM_UDF_TYPE_OFFS, type);
mvpp2_prs_sram_bits_clear(pe, MVPP2_PRS_SRAM_OP_SEL_UDF_OFFS,
MVPP2_PRS_SRAM_OP_SEL_UDF_MASK);
mvpp2_prs_sram_bits_set(pe, MVPP2_PRS_SRAM_OP_SEL_UDF_OFFS, op);
pe->sram.byte[MVPP2_BIT_TO_BYTE(MVPP2_PRS_SRAM_OP_SEL_UDF_OFFS +
MVPP2_PRS_SRAM_OP_SEL_UDF_BITS)] &=
~(MVPP2_PRS_SRAM_OP_SEL_UDF_MASK >>
(8 - (MVPP2_PRS_SRAM_OP_SEL_UDF_OFFS % 8)));
pe->sram.byte[MVPP2_BIT_TO_BYTE(MVPP2_PRS_SRAM_OP_SEL_UDF_OFFS +
MVPP2_PRS_SRAM_OP_SEL_UDF_BITS)] |=
(op >> (8 - (MVPP2_PRS_SRAM_OP_SEL_UDF_OFFS % 8)));
mvpp2_prs_sram_bits_clear(pe, MVPP2_PRS_SRAM_OP_SEL_BASE_OFFS, 1);
}
static struct mvpp2_prs_entry *mvpp2_prs_flow_find(struct mvpp2 *priv, int flow)
{
struct mvpp2_prs_entry *pe;
int tid;
pe = kzalloc(sizeof(*pe), GFP_KERNEL);
if (!pe)
return NULL;
mvpp2_prs_tcam_lu_set(pe, MVPP2_PRS_LU_FLOWS);
for (tid = MVPP2_PRS_TCAM_SRAM_SIZE - 1; tid >= 0; tid--) {
u8 bits;
if (!priv->prs_shadow[tid].valid ||
priv->prs_shadow[tid].lu != MVPP2_PRS_LU_FLOWS)
continue;
pe->index = tid;
mvpp2_prs_hw_read(priv, pe);
bits = mvpp2_prs_sram_ai_get(pe);
if ((bits & MVPP2_PRS_FLOW_ID_MASK) == flow)
return pe;
}
kfree(pe);
return NULL;
}
static int mvpp2_prs_tcam_first_free(struct mvpp2 *priv, unsigned char start,
unsigned char end)
{
int tid;
if (start > end)
swap(start, end);
if (end >= MVPP2_PRS_TCAM_SRAM_SIZE)
end = MVPP2_PRS_TCAM_SRAM_SIZE - 1;
for (tid = start; tid <= end; tid++) {
if (!priv->prs_shadow[tid].valid)
return tid;
}
return -EINVAL;
}
static void mvpp2_prs_mac_drop_all_set(struct mvpp2 *priv, int port, bool add)
{
struct mvpp2_prs_entry pe;
if (priv->prs_shadow[MVPP2_PE_DROP_ALL].valid) {
pe.index = MVPP2_PE_DROP_ALL;
mvpp2_prs_hw_read(priv, &pe);
} else {
memset(&pe, 0, sizeof(struct mvpp2_prs_entry));
mvpp2_prs_tcam_lu_set(&pe, MVPP2_PRS_LU_MAC);
pe.index = MVPP2_PE_DROP_ALL;
mvpp2_prs_sram_ri_update(&pe, MVPP2_PRS_RI_DROP_MASK,
MVPP2_PRS_RI_DROP_MASK);
mvpp2_prs_sram_bits_set(&pe, MVPP2_PRS_SRAM_LU_GEN_BIT, 1);
mvpp2_prs_sram_next_lu_set(&pe, MVPP2_PRS_LU_FLOWS);
mvpp2_prs_shadow_set(priv, pe.index, MVPP2_PRS_LU_MAC);
mvpp2_prs_tcam_port_map_set(&pe, 0);
}
mvpp2_prs_tcam_port_set(&pe, port, add);
mvpp2_prs_hw_write(priv, &pe);
}
static void mvpp2_prs_mac_promisc_set(struct mvpp2 *priv, int port, bool add)
{
struct mvpp2_prs_entry pe;
if (priv->prs_shadow[MVPP2_PE_MAC_PROMISCUOUS].valid) {
pe.index = MVPP2_PE_MAC_PROMISCUOUS;
mvpp2_prs_hw_read(priv, &pe);
} else {
memset(&pe, 0, sizeof(struct mvpp2_prs_entry));
mvpp2_prs_tcam_lu_set(&pe, MVPP2_PRS_LU_MAC);
pe.index = MVPP2_PE_MAC_PROMISCUOUS;
mvpp2_prs_sram_next_lu_set(&pe, MVPP2_PRS_LU_DSA);
mvpp2_prs_sram_ri_update(&pe, MVPP2_PRS_RI_L2_UCAST,
MVPP2_PRS_RI_L2_CAST_MASK);
mvpp2_prs_sram_shift_set(&pe, 2 * ETH_ALEN,
MVPP2_PRS_SRAM_OP_SEL_SHIFT_ADD);
mvpp2_prs_tcam_port_map_set(&pe, 0);
mvpp2_prs_shadow_set(priv, pe.index, MVPP2_PRS_LU_MAC);
}
mvpp2_prs_tcam_port_set(&pe, port, add);
mvpp2_prs_hw_write(priv, &pe);
}
static void mvpp2_prs_mac_multi_set(struct mvpp2 *priv, int port, int index,
bool add)
{
struct mvpp2_prs_entry pe;
unsigned char da_mc;
da_mc = (index == MVPP2_PE_MAC_MC_ALL) ? 0x01 : 0x33;
if (priv->prs_shadow[index].valid) {
pe.index = index;
mvpp2_prs_hw_read(priv, &pe);
} else {
memset(&pe, 0, sizeof(struct mvpp2_prs_entry));
mvpp2_prs_tcam_lu_set(&pe, MVPP2_PRS_LU_MAC);
pe.index = index;
mvpp2_prs_sram_next_lu_set(&pe, MVPP2_PRS_LU_DSA);
mvpp2_prs_sram_ri_update(&pe, MVPP2_PRS_RI_L2_MCAST,
MVPP2_PRS_RI_L2_CAST_MASK);
mvpp2_prs_tcam_data_byte_set(&pe, 0, da_mc, 0xff);
mvpp2_prs_sram_shift_set(&pe, 2 * ETH_ALEN,
MVPP2_PRS_SRAM_OP_SEL_SHIFT_ADD);
mvpp2_prs_tcam_port_map_set(&pe, 0);
mvpp2_prs_shadow_set(priv, pe.index, MVPP2_PRS_LU_MAC);
}
mvpp2_prs_tcam_port_set(&pe, port, add);
mvpp2_prs_hw_write(priv, &pe);
}
static void mvpp2_prs_dsa_tag_set(struct mvpp2 *priv, int port, bool add,
bool tagged, bool extend)
{
struct mvpp2_prs_entry pe;
int tid, shift;
if (extend) {
tid = tagged ? MVPP2_PE_EDSA_TAGGED : MVPP2_PE_EDSA_UNTAGGED;
shift = 8;
} else {
tid = tagged ? MVPP2_PE_DSA_TAGGED : MVPP2_PE_DSA_UNTAGGED;
shift = 4;
}
if (priv->prs_shadow[tid].valid) {
pe.index = tid;
mvpp2_prs_hw_read(priv, &pe);
} else {
memset(&pe, 0, sizeof(struct mvpp2_prs_entry));
mvpp2_prs_tcam_lu_set(&pe, MVPP2_PRS_LU_DSA);
pe.index = tid;
mvpp2_prs_sram_shift_set(&pe, shift,
MVPP2_PRS_SRAM_OP_SEL_SHIFT_ADD);
mvpp2_prs_shadow_set(priv, pe.index, MVPP2_PRS_LU_DSA);
if (tagged) {
mvpp2_prs_tcam_data_byte_set(&pe, 0,
MVPP2_PRS_TCAM_DSA_TAGGED_BIT,
MVPP2_PRS_TCAM_DSA_TAGGED_BIT);
mvpp2_prs_sram_ai_update(&pe, 0,
MVPP2_PRS_SRAM_AI_MASK);
mvpp2_prs_sram_next_lu_set(&pe, MVPP2_PRS_LU_VLAN);
} else {
mvpp2_prs_sram_ri_update(&pe, MVPP2_PRS_RI_VLAN_NONE,
MVPP2_PRS_RI_VLAN_MASK);
mvpp2_prs_sram_next_lu_set(&pe, MVPP2_PRS_LU_L2);
}
mvpp2_prs_tcam_port_map_set(&pe, 0);
}
mvpp2_prs_tcam_port_set(&pe, port, add);
mvpp2_prs_hw_write(priv, &pe);
}
static void mvpp2_prs_dsa_tag_ethertype_set(struct mvpp2 *priv, int port,
bool add, bool tagged, bool extend)
{
struct mvpp2_prs_entry pe;
int tid, shift, port_mask;
if (extend) {
tid = tagged ? MVPP2_PE_ETYPE_EDSA_TAGGED :
MVPP2_PE_ETYPE_EDSA_UNTAGGED;
port_mask = 0;
shift = 8;
} else {
tid = tagged ? MVPP2_PE_ETYPE_DSA_TAGGED :
MVPP2_PE_ETYPE_DSA_UNTAGGED;
port_mask = MVPP2_PRS_PORT_MASK;
shift = 4;
}
if (priv->prs_shadow[tid].valid) {
pe.index = tid;
mvpp2_prs_hw_read(priv, &pe);
} else {
memset(&pe, 0, sizeof(struct mvpp2_prs_entry));
mvpp2_prs_tcam_lu_set(&pe, MVPP2_PRS_LU_DSA);
pe.index = tid;
mvpp2_prs_match_etype(&pe, 0, ETH_P_EDSA);
mvpp2_prs_match_etype(&pe, 2, 0);
mvpp2_prs_sram_ri_update(&pe, MVPP2_PRS_RI_DSA_MASK,
MVPP2_PRS_RI_DSA_MASK);
mvpp2_prs_sram_shift_set(&pe, 2 + MVPP2_ETH_TYPE_LEN + shift,
MVPP2_PRS_SRAM_OP_SEL_SHIFT_ADD);
mvpp2_prs_shadow_set(priv, pe.index, MVPP2_PRS_LU_DSA);
if (tagged) {
mvpp2_prs_tcam_data_byte_set(&pe,
MVPP2_ETH_TYPE_LEN + 2 + 3,
MVPP2_PRS_TCAM_DSA_TAGGED_BIT,
MVPP2_PRS_TCAM_DSA_TAGGED_BIT);
mvpp2_prs_sram_ai_update(&pe, 0,
MVPP2_PRS_SRAM_AI_MASK);
mvpp2_prs_sram_next_lu_set(&pe, MVPP2_PRS_LU_VLAN);
} else {
mvpp2_prs_sram_ri_update(&pe, MVPP2_PRS_RI_VLAN_NONE,
MVPP2_PRS_RI_VLAN_MASK);
mvpp2_prs_sram_next_lu_set(&pe, MVPP2_PRS_LU_L2);
}
mvpp2_prs_tcam_port_map_set(&pe, port_mask);
}
mvpp2_prs_tcam_port_set(&pe, port, add);
mvpp2_prs_hw_write(priv, &pe);
}
static struct mvpp2_prs_entry *mvpp2_prs_vlan_find(struct mvpp2 *priv,
unsigned short tpid, int ai)
{
struct mvpp2_prs_entry *pe;
int tid;
pe = kzalloc(sizeof(*pe), GFP_KERNEL);
if (!pe)
return NULL;
mvpp2_prs_tcam_lu_set(pe, MVPP2_PRS_LU_VLAN);
for (tid = MVPP2_PE_FIRST_FREE_TID;
tid <= MVPP2_PE_LAST_FREE_TID; tid++) {
unsigned int ri_bits, ai_bits;
bool match;
if (!priv->prs_shadow[tid].valid ||
priv->prs_shadow[tid].lu != MVPP2_PRS_LU_VLAN)
continue;
pe->index = tid;
mvpp2_prs_hw_read(priv, pe);
match = mvpp2_prs_tcam_data_cmp(pe, 0, swab16(tpid));
if (!match)
continue;
ri_bits = mvpp2_prs_sram_ri_get(pe);
ri_bits &= MVPP2_PRS_RI_VLAN_MASK;
ai_bits = mvpp2_prs_tcam_ai_get(pe);
ai_bits &= ~MVPP2_PRS_DBL_VLAN_AI_BIT;
if (ai != ai_bits)
continue;
if (ri_bits == MVPP2_PRS_RI_VLAN_SINGLE ||
ri_bits == MVPP2_PRS_RI_VLAN_TRIPLE)
return pe;
}
kfree(pe);
return NULL;
}
static int mvpp2_prs_vlan_add(struct mvpp2 *priv, unsigned short tpid, int ai,
unsigned int port_map)
{
struct mvpp2_prs_entry *pe;
int tid_aux, tid;
int ret = 0;
pe = mvpp2_prs_vlan_find(priv, tpid, ai);
if (!pe) {
tid = mvpp2_prs_tcam_first_free(priv, MVPP2_PE_LAST_FREE_TID,
MVPP2_PE_FIRST_FREE_TID);
if (tid < 0)
return tid;
pe = kzalloc(sizeof(*pe), GFP_KERNEL);
if (!pe)
return -ENOMEM;
for (tid_aux = MVPP2_PE_LAST_FREE_TID;
tid_aux >= MVPP2_PE_FIRST_FREE_TID; tid_aux--) {
unsigned int ri_bits;
if (!priv->prs_shadow[tid_aux].valid ||
priv->prs_shadow[tid_aux].lu != MVPP2_PRS_LU_VLAN)
continue;
pe->index = tid_aux;
mvpp2_prs_hw_read(priv, pe);
ri_bits = mvpp2_prs_sram_ri_get(pe);
if ((ri_bits & MVPP2_PRS_RI_VLAN_MASK) ==
MVPP2_PRS_RI_VLAN_DOUBLE)
break;
}
if (tid <= tid_aux) {
ret = -EINVAL;
goto error;
}
memset(pe, 0 , sizeof(struct mvpp2_prs_entry));
mvpp2_prs_tcam_lu_set(pe, MVPP2_PRS_LU_VLAN);
pe->index = tid;
mvpp2_prs_match_etype(pe, 0, tpid);
mvpp2_prs_sram_next_lu_set(pe, MVPP2_PRS_LU_L2);
mvpp2_prs_sram_shift_set(pe, MVPP2_VLAN_TAG_LEN,
MVPP2_PRS_SRAM_OP_SEL_SHIFT_ADD);
mvpp2_prs_sram_ai_update(pe, 0, MVPP2_PRS_SRAM_AI_MASK);
if (ai == MVPP2_PRS_SINGLE_VLAN_AI) {
mvpp2_prs_sram_ri_update(pe, MVPP2_PRS_RI_VLAN_SINGLE,
MVPP2_PRS_RI_VLAN_MASK);
} else {
ai |= MVPP2_PRS_DBL_VLAN_AI_BIT;
mvpp2_prs_sram_ri_update(pe, MVPP2_PRS_RI_VLAN_TRIPLE,
MVPP2_PRS_RI_VLAN_MASK);
}
mvpp2_prs_tcam_ai_update(pe, ai, MVPP2_PRS_SRAM_AI_MASK);
mvpp2_prs_shadow_set(priv, pe->index, MVPP2_PRS_LU_VLAN);
}
mvpp2_prs_tcam_port_map_set(pe, port_map);
mvpp2_prs_hw_write(priv, pe);
error:
kfree(pe);
return ret;
}
static int mvpp2_prs_double_vlan_ai_free_get(struct mvpp2 *priv)
{
int i;
for (i = 1; i < MVPP2_PRS_DBL_VLANS_MAX; i++) {
if (!priv->prs_double_vlans[i])
return i;
}
return -EINVAL;
}
static struct mvpp2_prs_entry *mvpp2_prs_double_vlan_find(struct mvpp2 *priv,
unsigned short tpid1,
unsigned short tpid2)
{
struct mvpp2_prs_entry *pe;
int tid;
pe = kzalloc(sizeof(*pe), GFP_KERNEL);
if (!pe)
return NULL;
mvpp2_prs_tcam_lu_set(pe, MVPP2_PRS_LU_VLAN);
for (tid = MVPP2_PE_FIRST_FREE_TID;
tid <= MVPP2_PE_LAST_FREE_TID; tid++) {
unsigned int ri_mask;
bool match;
if (!priv->prs_shadow[tid].valid ||
priv->prs_shadow[tid].lu != MVPP2_PRS_LU_VLAN)
continue;
pe->index = tid;
mvpp2_prs_hw_read(priv, pe);
match = mvpp2_prs_tcam_data_cmp(pe, 0, swab16(tpid1))
&& mvpp2_prs_tcam_data_cmp(pe, 4, swab16(tpid2));
if (!match)
continue;
ri_mask = mvpp2_prs_sram_ri_get(pe) & MVPP2_PRS_RI_VLAN_MASK;
if (ri_mask == MVPP2_PRS_RI_VLAN_DOUBLE)
return pe;
}
kfree(pe);
return NULL;
}
static int mvpp2_prs_double_vlan_add(struct mvpp2 *priv, unsigned short tpid1,
unsigned short tpid2,
unsigned int port_map)
{
struct mvpp2_prs_entry *pe;
int tid_aux, tid, ai, ret = 0;
pe = mvpp2_prs_double_vlan_find(priv, tpid1, tpid2);
if (!pe) {
tid = mvpp2_prs_tcam_first_free(priv, MVPP2_PE_FIRST_FREE_TID,
MVPP2_PE_LAST_FREE_TID);
if (tid < 0)
return tid;
pe = kzalloc(sizeof(*pe), GFP_KERNEL);
if (!pe)
return -ENOMEM;
ai = mvpp2_prs_double_vlan_ai_free_get(priv);
if (ai < 0) {
ret = ai;
goto error;
}
for (tid_aux = MVPP2_PE_FIRST_FREE_TID;
tid_aux <= MVPP2_PE_LAST_FREE_TID; tid_aux++) {
unsigned int ri_bits;
if (!priv->prs_shadow[tid_aux].valid ||
priv->prs_shadow[tid_aux].lu != MVPP2_PRS_LU_VLAN)
continue;
pe->index = tid_aux;
mvpp2_prs_hw_read(priv, pe);
ri_bits = mvpp2_prs_sram_ri_get(pe);
ri_bits &= MVPP2_PRS_RI_VLAN_MASK;
if (ri_bits == MVPP2_PRS_RI_VLAN_SINGLE ||
ri_bits == MVPP2_PRS_RI_VLAN_TRIPLE)
break;
}
if (tid >= tid_aux) {
ret = -ERANGE;
goto error;
}
memset(pe, 0, sizeof(struct mvpp2_prs_entry));
mvpp2_prs_tcam_lu_set(pe, MVPP2_PRS_LU_VLAN);
pe->index = tid;
priv->prs_double_vlans[ai] = true;
mvpp2_prs_match_etype(pe, 0, tpid1);
mvpp2_prs_match_etype(pe, 4, tpid2);
mvpp2_prs_sram_next_lu_set(pe, MVPP2_PRS_LU_VLAN);
mvpp2_prs_sram_shift_set(pe, 2 * MVPP2_VLAN_TAG_LEN,
MVPP2_PRS_SRAM_OP_SEL_SHIFT_ADD);
mvpp2_prs_sram_ri_update(pe, MVPP2_PRS_RI_VLAN_DOUBLE,
MVPP2_PRS_RI_VLAN_MASK);
mvpp2_prs_sram_ai_update(pe, ai | MVPP2_PRS_DBL_VLAN_AI_BIT,
MVPP2_PRS_SRAM_AI_MASK);
mvpp2_prs_shadow_set(priv, pe->index, MVPP2_PRS_LU_VLAN);
}
mvpp2_prs_tcam_port_map_set(pe, port_map);
mvpp2_prs_hw_write(priv, pe);
error:
kfree(pe);
return ret;
}
static int mvpp2_prs_ip4_proto(struct mvpp2 *priv, unsigned short proto,
unsigned int ri, unsigned int ri_mask)
{
struct mvpp2_prs_entry pe;
int tid;
if ((proto != IPPROTO_TCP) && (proto != IPPROTO_UDP) &&
(proto != IPPROTO_IGMP))
return -EINVAL;
tid = mvpp2_prs_tcam_first_free(priv, MVPP2_PE_FIRST_FREE_TID,
MVPP2_PE_LAST_FREE_TID);
if (tid < 0)
return tid;
memset(&pe, 0, sizeof(struct mvpp2_prs_entry));
mvpp2_prs_tcam_lu_set(&pe, MVPP2_PRS_LU_IP4);
pe.index = tid;
mvpp2_prs_sram_next_lu_set(&pe, MVPP2_PRS_LU_IP4);
mvpp2_prs_sram_shift_set(&pe, 12, MVPP2_PRS_SRAM_OP_SEL_SHIFT_ADD);
mvpp2_prs_sram_offset_set(&pe, MVPP2_PRS_SRAM_UDF_TYPE_L4,
sizeof(struct iphdr) - 4,
MVPP2_PRS_SRAM_OP_SEL_UDF_ADD);
mvpp2_prs_sram_ai_update(&pe, MVPP2_PRS_IPV4_DIP_AI_BIT,
MVPP2_PRS_IPV4_DIP_AI_BIT);
mvpp2_prs_sram_ri_update(&pe, ri | MVPP2_PRS_RI_IP_FRAG_MASK,
ri_mask | MVPP2_PRS_RI_IP_FRAG_MASK);
mvpp2_prs_tcam_data_byte_set(&pe, 5, proto, MVPP2_PRS_TCAM_PROTO_MASK);
mvpp2_prs_tcam_ai_update(&pe, 0, MVPP2_PRS_IPV4_DIP_AI_BIT);
mvpp2_prs_tcam_port_map_set(&pe, MVPP2_PRS_PORT_MASK);
mvpp2_prs_shadow_set(priv, pe.index, MVPP2_PRS_LU_IP4);
mvpp2_prs_hw_write(priv, &pe);
tid = mvpp2_prs_tcam_first_free(priv, MVPP2_PE_FIRST_FREE_TID,
MVPP2_PE_LAST_FREE_TID);
if (tid < 0)
return tid;
pe.index = tid;
pe.sram.word[MVPP2_PRS_SRAM_RI_WORD] = 0x0;
pe.sram.word[MVPP2_PRS_SRAM_RI_CTRL_WORD] = 0x0;
mvpp2_prs_sram_ri_update(&pe, ri, ri_mask);
mvpp2_prs_tcam_data_byte_set(&pe, 2, 0x00, MVPP2_PRS_TCAM_PROTO_MASK_L);
mvpp2_prs_tcam_data_byte_set(&pe, 3, 0x00, MVPP2_PRS_TCAM_PROTO_MASK);
mvpp2_prs_shadow_set(priv, pe.index, MVPP2_PRS_LU_IP4);
mvpp2_prs_hw_write(priv, &pe);
return 0;
}
static int mvpp2_prs_ip4_cast(struct mvpp2 *priv, unsigned short l3_cast)
{
struct mvpp2_prs_entry pe;
int mask, tid;
tid = mvpp2_prs_tcam_first_free(priv, MVPP2_PE_FIRST_FREE_TID,
MVPP2_PE_LAST_FREE_TID);
if (tid < 0)
return tid;
memset(&pe, 0, sizeof(struct mvpp2_prs_entry));
mvpp2_prs_tcam_lu_set(&pe, MVPP2_PRS_LU_IP4);
pe.index = tid;
switch (l3_cast) {
case MVPP2_PRS_L3_MULTI_CAST:
mvpp2_prs_tcam_data_byte_set(&pe, 0, MVPP2_PRS_IPV4_MC,
MVPP2_PRS_IPV4_MC_MASK);
mvpp2_prs_sram_ri_update(&pe, MVPP2_PRS_RI_L3_MCAST,
MVPP2_PRS_RI_L3_ADDR_MASK);
break;
case MVPP2_PRS_L3_BROAD_CAST:
mask = MVPP2_PRS_IPV4_BC_MASK;
mvpp2_prs_tcam_data_byte_set(&pe, 0, mask, mask);
mvpp2_prs_tcam_data_byte_set(&pe, 1, mask, mask);
mvpp2_prs_tcam_data_byte_set(&pe, 2, mask, mask);
mvpp2_prs_tcam_data_byte_set(&pe, 3, mask, mask);
mvpp2_prs_sram_ri_update(&pe, MVPP2_PRS_RI_L3_BCAST,
MVPP2_PRS_RI_L3_ADDR_MASK);
break;
default:
return -EINVAL;
}
mvpp2_prs_sram_next_lu_set(&pe, MVPP2_PRS_LU_FLOWS);
mvpp2_prs_sram_bits_set(&pe, MVPP2_PRS_SRAM_LU_GEN_BIT, 1);
mvpp2_prs_tcam_ai_update(&pe, MVPP2_PRS_IPV4_DIP_AI_BIT,
MVPP2_PRS_IPV4_DIP_AI_BIT);
mvpp2_prs_tcam_port_map_set(&pe, MVPP2_PRS_PORT_MASK);
mvpp2_prs_shadow_set(priv, pe.index, MVPP2_PRS_LU_IP4);
mvpp2_prs_hw_write(priv, &pe);
return 0;
}
static int mvpp2_prs_ip6_proto(struct mvpp2 *priv, unsigned short proto,
unsigned int ri, unsigned int ri_mask)
{
struct mvpp2_prs_entry pe;
int tid;
if ((proto != IPPROTO_TCP) && (proto != IPPROTO_UDP) &&
(proto != IPPROTO_ICMPV6) && (proto != IPPROTO_IPIP))
return -EINVAL;
tid = mvpp2_prs_tcam_first_free(priv, MVPP2_PE_FIRST_FREE_TID,
MVPP2_PE_LAST_FREE_TID);
if (tid < 0)
return tid;
memset(&pe, 0, sizeof(struct mvpp2_prs_entry));
mvpp2_prs_tcam_lu_set(&pe, MVPP2_PRS_LU_IP6);
pe.index = tid;
mvpp2_prs_sram_next_lu_set(&pe, MVPP2_PRS_LU_FLOWS);
mvpp2_prs_sram_bits_set(&pe, MVPP2_PRS_SRAM_LU_GEN_BIT, 1);
mvpp2_prs_sram_ri_update(&pe, ri, ri_mask);
mvpp2_prs_sram_offset_set(&pe, MVPP2_PRS_SRAM_UDF_TYPE_L4,
sizeof(struct ipv6hdr) - 6,
MVPP2_PRS_SRAM_OP_SEL_UDF_ADD);
mvpp2_prs_tcam_data_byte_set(&pe, 0, proto, MVPP2_PRS_TCAM_PROTO_MASK);
mvpp2_prs_tcam_ai_update(&pe, MVPP2_PRS_IPV6_NO_EXT_AI_BIT,
MVPP2_PRS_IPV6_NO_EXT_AI_BIT);
mvpp2_prs_tcam_port_map_set(&pe, MVPP2_PRS_PORT_MASK);
mvpp2_prs_shadow_set(priv, pe.index, MVPP2_PRS_LU_IP6);
mvpp2_prs_hw_write(priv, &pe);
return 0;
}
static int mvpp2_prs_ip6_cast(struct mvpp2 *priv, unsigned short l3_cast)
{
struct mvpp2_prs_entry pe;
int tid;
if (l3_cast != MVPP2_PRS_L3_MULTI_CAST)
return -EINVAL;
tid = mvpp2_prs_tcam_first_free(priv, MVPP2_PE_FIRST_FREE_TID,
MVPP2_PE_LAST_FREE_TID);
if (tid < 0)
return tid;
memset(&pe, 0, sizeof(struct mvpp2_prs_entry));
mvpp2_prs_tcam_lu_set(&pe, MVPP2_PRS_LU_IP6);
pe.index = tid;
mvpp2_prs_sram_next_lu_set(&pe, MVPP2_PRS_LU_IP6);
mvpp2_prs_sram_ri_update(&pe, MVPP2_PRS_RI_L3_MCAST,
MVPP2_PRS_RI_L3_ADDR_MASK);
mvpp2_prs_sram_ai_update(&pe, MVPP2_PRS_IPV6_NO_EXT_AI_BIT,
MVPP2_PRS_IPV6_NO_EXT_AI_BIT);
mvpp2_prs_sram_shift_set(&pe, -18, MVPP2_PRS_SRAM_OP_SEL_SHIFT_ADD);
mvpp2_prs_tcam_data_byte_set(&pe, 0, MVPP2_PRS_IPV6_MC,
MVPP2_PRS_IPV6_MC_MASK);
mvpp2_prs_tcam_ai_update(&pe, 0, MVPP2_PRS_IPV6_NO_EXT_AI_BIT);
mvpp2_prs_tcam_port_map_set(&pe, MVPP2_PRS_PORT_MASK);
mvpp2_prs_shadow_set(priv, pe.index, MVPP2_PRS_LU_IP6);
mvpp2_prs_hw_write(priv, &pe);
return 0;
}
static void mvpp2_prs_hw_port_init(struct mvpp2 *priv, int port, int lu_first,
int lu_max, int offset)
{
u32 val;
val = mvpp2_read(priv, MVPP2_PRS_INIT_LOOKUP_REG);
val &= ~MVPP2_PRS_PORT_LU_MASK(port);
val |= MVPP2_PRS_PORT_LU_VAL(port, lu_first);
mvpp2_write(priv, MVPP2_PRS_INIT_LOOKUP_REG, val);
val = mvpp2_read(priv, MVPP2_PRS_MAX_LOOP_REG(port));
val &= ~MVPP2_PRS_MAX_LOOP_MASK(port);
val |= MVPP2_PRS_MAX_LOOP_VAL(port, lu_max);
mvpp2_write(priv, MVPP2_PRS_MAX_LOOP_REG(port), val);
val = mvpp2_read(priv, MVPP2_PRS_INIT_OFFS_REG(port));
val &= ~MVPP2_PRS_INIT_OFF_MASK(port);
val |= MVPP2_PRS_INIT_OFF_VAL(port, offset);
mvpp2_write(priv, MVPP2_PRS_INIT_OFFS_REG(port), val);
}
static void mvpp2_prs_def_flow_init(struct mvpp2 *priv)
{
struct mvpp2_prs_entry pe;
int port;
for (port = 0; port < MVPP2_MAX_PORTS; port++) {
memset(&pe, 0, sizeof(struct mvpp2_prs_entry));
mvpp2_prs_tcam_lu_set(&pe, MVPP2_PRS_LU_FLOWS);
pe.index = MVPP2_PE_FIRST_DEFAULT_FLOW - port;
mvpp2_prs_tcam_port_map_set(&pe, 0);
mvpp2_prs_sram_ai_update(&pe, port, MVPP2_PRS_FLOW_ID_MASK);
mvpp2_prs_sram_bits_set(&pe, MVPP2_PRS_SRAM_LU_DONE_BIT, 1);
mvpp2_prs_shadow_set(priv, pe.index, MVPP2_PRS_LU_FLOWS);
mvpp2_prs_hw_write(priv, &pe);
}
}
static void mvpp2_prs_mh_init(struct mvpp2 *priv)
{
struct mvpp2_prs_entry pe;
memset(&pe, 0, sizeof(struct mvpp2_prs_entry));
pe.index = MVPP2_PE_MH_DEFAULT;
mvpp2_prs_tcam_lu_set(&pe, MVPP2_PRS_LU_MH);
mvpp2_prs_sram_shift_set(&pe, MVPP2_MH_SIZE,
MVPP2_PRS_SRAM_OP_SEL_SHIFT_ADD);
mvpp2_prs_sram_next_lu_set(&pe, MVPP2_PRS_LU_MAC);
mvpp2_prs_tcam_port_map_set(&pe, MVPP2_PRS_PORT_MASK);
mvpp2_prs_shadow_set(priv, pe.index, MVPP2_PRS_LU_MH);
mvpp2_prs_hw_write(priv, &pe);
}
static void mvpp2_prs_mac_init(struct mvpp2 *priv)
{
struct mvpp2_prs_entry pe;
memset(&pe, 0, sizeof(struct mvpp2_prs_entry));
pe.index = MVPP2_PE_MAC_NON_PROMISCUOUS;
mvpp2_prs_tcam_lu_set(&pe, MVPP2_PRS_LU_MAC);
mvpp2_prs_sram_ri_update(&pe, MVPP2_PRS_RI_DROP_MASK,
MVPP2_PRS_RI_DROP_MASK);
mvpp2_prs_sram_bits_set(&pe, MVPP2_PRS_SRAM_LU_GEN_BIT, 1);
mvpp2_prs_sram_next_lu_set(&pe, MVPP2_PRS_LU_FLOWS);
mvpp2_prs_tcam_port_map_set(&pe, MVPP2_PRS_PORT_MASK);
mvpp2_prs_shadow_set(priv, pe.index, MVPP2_PRS_LU_MAC);
mvpp2_prs_hw_write(priv, &pe);
mvpp2_prs_mac_drop_all_set(priv, 0, false);
mvpp2_prs_mac_promisc_set(priv, 0, false);
mvpp2_prs_mac_multi_set(priv, MVPP2_PE_MAC_MC_ALL, 0, false);
mvpp2_prs_mac_multi_set(priv, MVPP2_PE_MAC_MC_IP6, 0, false);
}
static void mvpp2_prs_dsa_init(struct mvpp2 *priv)
{
struct mvpp2_prs_entry pe;
mvpp2_prs_dsa_tag_set(priv, 0, false, MVPP2_PRS_UNTAGGED,
MVPP2_PRS_EDSA);
mvpp2_prs_dsa_tag_set(priv, 0, false, MVPP2_PRS_TAGGED, MVPP2_PRS_EDSA);
mvpp2_prs_dsa_tag_set(priv, 0, false, MVPP2_PRS_UNTAGGED,
MVPP2_PRS_DSA);
mvpp2_prs_dsa_tag_set(priv, 0, false, MVPP2_PRS_TAGGED, MVPP2_PRS_DSA);
mvpp2_prs_dsa_tag_ethertype_set(priv, 0, false,
MVPP2_PRS_UNTAGGED, MVPP2_PRS_EDSA);
mvpp2_prs_dsa_tag_ethertype_set(priv, 0, false,
MVPP2_PRS_TAGGED, MVPP2_PRS_EDSA);
mvpp2_prs_dsa_tag_ethertype_set(priv, 0, true,
MVPP2_PRS_UNTAGGED, MVPP2_PRS_DSA);
mvpp2_prs_dsa_tag_ethertype_set(priv, 0, true,
MVPP2_PRS_TAGGED, MVPP2_PRS_DSA);
memset(&pe, 0, sizeof(struct mvpp2_prs_entry));
mvpp2_prs_tcam_lu_set(&pe, MVPP2_PRS_LU_DSA);
pe.index = MVPP2_PE_DSA_DEFAULT;
mvpp2_prs_sram_next_lu_set(&pe, MVPP2_PRS_LU_VLAN);
mvpp2_prs_sram_shift_set(&pe, 0, MVPP2_PRS_SRAM_OP_SEL_SHIFT_ADD);
mvpp2_prs_shadow_set(priv, pe.index, MVPP2_PRS_LU_MAC);
mvpp2_prs_sram_ai_update(&pe, 0, MVPP2_PRS_SRAM_AI_MASK);
mvpp2_prs_tcam_port_map_set(&pe, MVPP2_PRS_PORT_MASK);
mvpp2_prs_hw_write(priv, &pe);
}
static int mvpp2_prs_etype_init(struct mvpp2 *priv)
{
struct mvpp2_prs_entry pe;
int tid;
tid = mvpp2_prs_tcam_first_free(priv, MVPP2_PE_FIRST_FREE_TID,
MVPP2_PE_LAST_FREE_TID);
if (tid < 0)
return tid;
memset(&pe, 0, sizeof(struct mvpp2_prs_entry));
mvpp2_prs_tcam_lu_set(&pe, MVPP2_PRS_LU_L2);
pe.index = tid;
mvpp2_prs_match_etype(&pe, 0, ETH_P_PPP_SES);
mvpp2_prs_sram_shift_set(&pe, MVPP2_PPPOE_HDR_SIZE,
MVPP2_PRS_SRAM_OP_SEL_SHIFT_ADD);
mvpp2_prs_sram_next_lu_set(&pe, MVPP2_PRS_LU_PPPOE);
mvpp2_prs_sram_ri_update(&pe, MVPP2_PRS_RI_PPPOE_MASK,
MVPP2_PRS_RI_PPPOE_MASK);
mvpp2_prs_shadow_set(priv, pe.index, MVPP2_PRS_LU_L2);
priv->prs_shadow[pe.index].udf = MVPP2_PRS_UDF_L2_DEF;
priv->prs_shadow[pe.index].finish = false;
mvpp2_prs_shadow_ri_set(priv, pe.index, MVPP2_PRS_RI_PPPOE_MASK,
MVPP2_PRS_RI_PPPOE_MASK);
mvpp2_prs_hw_write(priv, &pe);
tid = mvpp2_prs_tcam_first_free(priv, MVPP2_PE_FIRST_FREE_TID,
MVPP2_PE_LAST_FREE_TID);
if (tid < 0)
return tid;
memset(&pe, 0, sizeof(struct mvpp2_prs_entry));
mvpp2_prs_tcam_lu_set(&pe, MVPP2_PRS_LU_L2);
pe.index = tid;
mvpp2_prs_match_etype(&pe, 0, ETH_P_ARP);
mvpp2_prs_sram_next_lu_set(&pe, MVPP2_PRS_LU_FLOWS);
mvpp2_prs_sram_bits_set(&pe, MVPP2_PRS_SRAM_LU_GEN_BIT, 1);
mvpp2_prs_sram_ri_update(&pe, MVPP2_PRS_RI_L3_ARP,
MVPP2_PRS_RI_L3_PROTO_MASK);
mvpp2_prs_sram_offset_set(&pe, MVPP2_PRS_SRAM_UDF_TYPE_L3,
MVPP2_ETH_TYPE_LEN,
MVPP2_PRS_SRAM_OP_SEL_UDF_ADD);
mvpp2_prs_shadow_set(priv, pe.index, MVPP2_PRS_LU_L2);
priv->prs_shadow[pe.index].udf = MVPP2_PRS_UDF_L2_DEF;
priv->prs_shadow[pe.index].finish = true;
mvpp2_prs_shadow_ri_set(priv, pe.index, MVPP2_PRS_RI_L3_ARP,
MVPP2_PRS_RI_L3_PROTO_MASK);
mvpp2_prs_hw_write(priv, &pe);
tid = mvpp2_prs_tcam_first_free(priv, MVPP2_PE_FIRST_FREE_TID,
MVPP2_PE_LAST_FREE_TID);
if (tid < 0)
return tid;
memset(&pe, 0, sizeof(struct mvpp2_prs_entry));
mvpp2_prs_tcam_lu_set(&pe, MVPP2_PRS_LU_L2);
pe.index = tid;
mvpp2_prs_match_etype(&pe, 0, MVPP2_IP_LBDT_TYPE);
mvpp2_prs_sram_next_lu_set(&pe, MVPP2_PRS_LU_FLOWS);
mvpp2_prs_sram_bits_set(&pe, MVPP2_PRS_SRAM_LU_GEN_BIT, 1);
mvpp2_prs_sram_ri_update(&pe, MVPP2_PRS_RI_CPU_CODE_RX_SPEC |
MVPP2_PRS_RI_UDF3_RX_SPECIAL,
MVPP2_PRS_RI_CPU_CODE_MASK |
MVPP2_PRS_RI_UDF3_MASK);
mvpp2_prs_sram_offset_set(&pe, MVPP2_PRS_SRAM_UDF_TYPE_L3,
MVPP2_ETH_TYPE_LEN,
MVPP2_PRS_SRAM_OP_SEL_UDF_ADD);
mvpp2_prs_shadow_set(priv, pe.index, MVPP2_PRS_LU_L2);
priv->prs_shadow[pe.index].udf = MVPP2_PRS_UDF_L2_DEF;
priv->prs_shadow[pe.index].finish = true;
mvpp2_prs_shadow_ri_set(priv, pe.index, MVPP2_PRS_RI_CPU_CODE_RX_SPEC |
MVPP2_PRS_RI_UDF3_RX_SPECIAL,
MVPP2_PRS_RI_CPU_CODE_MASK |
MVPP2_PRS_RI_UDF3_MASK);
mvpp2_prs_hw_write(priv, &pe);
tid = mvpp2_prs_tcam_first_free(priv, MVPP2_PE_FIRST_FREE_TID,
MVPP2_PE_LAST_FREE_TID);
if (tid < 0)
return tid;
memset(&pe, 0, sizeof(struct mvpp2_prs_entry));
mvpp2_prs_tcam_lu_set(&pe, MVPP2_PRS_LU_L2);
pe.index = tid;
mvpp2_prs_match_etype(&pe, 0, ETH_P_IP);
mvpp2_prs_tcam_data_byte_set(&pe, MVPP2_ETH_TYPE_LEN,
MVPP2_PRS_IPV4_HEAD | MVPP2_PRS_IPV4_IHL,
MVPP2_PRS_IPV4_HEAD_MASK |
MVPP2_PRS_IPV4_IHL_MASK);
mvpp2_prs_sram_next_lu_set(&pe, MVPP2_PRS_LU_IP4);
mvpp2_prs_sram_ri_update(&pe, MVPP2_PRS_RI_L3_IP4,
MVPP2_PRS_RI_L3_PROTO_MASK);
mvpp2_prs_sram_shift_set(&pe, MVPP2_ETH_TYPE_LEN + 4,
MVPP2_PRS_SRAM_OP_SEL_SHIFT_ADD);
mvpp2_prs_sram_offset_set(&pe, MVPP2_PRS_SRAM_UDF_TYPE_L3,
MVPP2_ETH_TYPE_LEN,
MVPP2_PRS_SRAM_OP_SEL_UDF_ADD);
mvpp2_prs_shadow_set(priv, pe.index, MVPP2_PRS_LU_L2);
priv->prs_shadow[pe.index].udf = MVPP2_PRS_UDF_L2_DEF;
priv->prs_shadow[pe.index].finish = false;
mvpp2_prs_shadow_ri_set(priv, pe.index, MVPP2_PRS_RI_L3_IP4,
MVPP2_PRS_RI_L3_PROTO_MASK);
mvpp2_prs_hw_write(priv, &pe);
tid = mvpp2_prs_tcam_first_free(priv, MVPP2_PE_FIRST_FREE_TID,
MVPP2_PE_LAST_FREE_TID);
if (tid < 0)
return tid;
pe.index = tid;
pe.tcam.byte[MVPP2_PRS_TCAM_DATA_BYTE(MVPP2_ETH_TYPE_LEN)] = 0x0;
pe.tcam.byte[MVPP2_PRS_TCAM_DATA_BYTE_EN(MVPP2_ETH_TYPE_LEN)] = 0x0;
mvpp2_prs_tcam_data_byte_set(&pe, MVPP2_ETH_TYPE_LEN,
MVPP2_PRS_IPV4_HEAD,
MVPP2_PRS_IPV4_HEAD_MASK);
pe.sram.word[MVPP2_PRS_SRAM_RI_WORD] = 0x0;
pe.sram.word[MVPP2_PRS_SRAM_RI_CTRL_WORD] = 0x0;
mvpp2_prs_sram_ri_update(&pe, MVPP2_PRS_RI_L3_IP4_OPT,
MVPP2_PRS_RI_L3_PROTO_MASK);
mvpp2_prs_shadow_set(priv, pe.index, MVPP2_PRS_LU_L2);
priv->prs_shadow[pe.index].udf = MVPP2_PRS_UDF_L2_DEF;
priv->prs_shadow[pe.index].finish = false;
mvpp2_prs_shadow_ri_set(priv, pe.index, MVPP2_PRS_RI_L3_IP4_OPT,
MVPP2_PRS_RI_L3_PROTO_MASK);
mvpp2_prs_hw_write(priv, &pe);
tid = mvpp2_prs_tcam_first_free(priv, MVPP2_PE_FIRST_FREE_TID,
MVPP2_PE_LAST_FREE_TID);
if (tid < 0)
return tid;
memset(&pe, 0, sizeof(struct mvpp2_prs_entry));
mvpp2_prs_tcam_lu_set(&pe, MVPP2_PRS_LU_L2);
pe.index = tid;
mvpp2_prs_match_etype(&pe, 0, ETH_P_IPV6);
mvpp2_prs_sram_shift_set(&pe, MVPP2_ETH_TYPE_LEN + 8 +
MVPP2_MAX_L3_ADDR_SIZE,
MVPP2_PRS_SRAM_OP_SEL_SHIFT_ADD);
mvpp2_prs_sram_next_lu_set(&pe, MVPP2_PRS_LU_IP6);
mvpp2_prs_sram_ri_update(&pe, MVPP2_PRS_RI_L3_IP6,
MVPP2_PRS_RI_L3_PROTO_MASK);
mvpp2_prs_sram_offset_set(&pe, MVPP2_PRS_SRAM_UDF_TYPE_L3,
MVPP2_ETH_TYPE_LEN,
MVPP2_PRS_SRAM_OP_SEL_UDF_ADD);
mvpp2_prs_shadow_set(priv, pe.index, MVPP2_PRS_LU_L2);
priv->prs_shadow[pe.index].udf = MVPP2_PRS_UDF_L2_DEF;
priv->prs_shadow[pe.index].finish = false;
mvpp2_prs_shadow_ri_set(priv, pe.index, MVPP2_PRS_RI_L3_IP6,
MVPP2_PRS_RI_L3_PROTO_MASK);
mvpp2_prs_hw_write(priv, &pe);
memset(&pe, 0, sizeof(struct mvpp2_prs_entry));
mvpp2_prs_tcam_lu_set(&pe, MVPP2_PRS_LU_L2);
pe.index = MVPP2_PE_ETH_TYPE_UN;
mvpp2_prs_tcam_port_map_set(&pe, MVPP2_PRS_PORT_MASK);
mvpp2_prs_sram_bits_set(&pe, MVPP2_PRS_SRAM_LU_GEN_BIT, 1);
mvpp2_prs_sram_next_lu_set(&pe, MVPP2_PRS_LU_FLOWS);
mvpp2_prs_sram_ri_update(&pe, MVPP2_PRS_RI_L3_UN,
MVPP2_PRS_RI_L3_PROTO_MASK);
mvpp2_prs_sram_offset_set(&pe, MVPP2_PRS_SRAM_UDF_TYPE_L3,
MVPP2_ETH_TYPE_LEN,
MVPP2_PRS_SRAM_OP_SEL_UDF_ADD);
mvpp2_prs_shadow_set(priv, pe.index, MVPP2_PRS_LU_L2);
priv->prs_shadow[pe.index].udf = MVPP2_PRS_UDF_L2_DEF;
priv->prs_shadow[pe.index].finish = true;
mvpp2_prs_shadow_ri_set(priv, pe.index, MVPP2_PRS_RI_L3_UN,
MVPP2_PRS_RI_L3_PROTO_MASK);
mvpp2_prs_hw_write(priv, &pe);
return 0;
}
static int mvpp2_prs_vlan_init(struct platform_device *pdev, struct mvpp2 *priv)
{
struct mvpp2_prs_entry pe;
int err;
priv->prs_double_vlans = devm_kcalloc(&pdev->dev, sizeof(bool),
MVPP2_PRS_DBL_VLANS_MAX,
GFP_KERNEL);
if (!priv->prs_double_vlans)
return -ENOMEM;
err = mvpp2_prs_double_vlan_add(priv, ETH_P_8021Q, ETH_P_8021AD,
MVPP2_PRS_PORT_MASK);
if (err)
return err;
err = mvpp2_prs_double_vlan_add(priv, ETH_P_8021Q, ETH_P_8021Q,
MVPP2_PRS_PORT_MASK);
if (err)
return err;
err = mvpp2_prs_vlan_add(priv, ETH_P_8021AD, MVPP2_PRS_SINGLE_VLAN_AI,
MVPP2_PRS_PORT_MASK);
if (err)
return err;
err = mvpp2_prs_vlan_add(priv, ETH_P_8021Q, MVPP2_PRS_SINGLE_VLAN_AI,
MVPP2_PRS_PORT_MASK);
if (err)
return err;
memset(&pe, 0, sizeof(struct mvpp2_prs_entry));
mvpp2_prs_tcam_lu_set(&pe, MVPP2_PRS_LU_VLAN);
pe.index = MVPP2_PE_VLAN_DBL;
mvpp2_prs_sram_next_lu_set(&pe, MVPP2_PRS_LU_L2);
mvpp2_prs_sram_ai_update(&pe, 0, MVPP2_PRS_SRAM_AI_MASK);
mvpp2_prs_sram_ri_update(&pe, MVPP2_PRS_RI_VLAN_DOUBLE,
MVPP2_PRS_RI_VLAN_MASK);
mvpp2_prs_tcam_ai_update(&pe, MVPP2_PRS_DBL_VLAN_AI_BIT,
MVPP2_PRS_DBL_VLAN_AI_BIT);
mvpp2_prs_tcam_port_map_set(&pe, MVPP2_PRS_PORT_MASK);
mvpp2_prs_shadow_set(priv, pe.index, MVPP2_PRS_LU_VLAN);
mvpp2_prs_hw_write(priv, &pe);
memset(&pe, 0, sizeof(struct mvpp2_prs_entry));
mvpp2_prs_tcam_lu_set(&pe, MVPP2_PRS_LU_VLAN);
pe.index = MVPP2_PE_VLAN_NONE;
mvpp2_prs_sram_next_lu_set(&pe, MVPP2_PRS_LU_L2);
mvpp2_prs_sram_ri_update(&pe, MVPP2_PRS_RI_VLAN_NONE,
MVPP2_PRS_RI_VLAN_MASK);
mvpp2_prs_tcam_port_map_set(&pe, MVPP2_PRS_PORT_MASK);
mvpp2_prs_shadow_set(priv, pe.index, MVPP2_PRS_LU_VLAN);
mvpp2_prs_hw_write(priv, &pe);
return 0;
}
static int mvpp2_prs_pppoe_init(struct mvpp2 *priv)
{
struct mvpp2_prs_entry pe;
int tid;
tid = mvpp2_prs_tcam_first_free(priv, MVPP2_PE_FIRST_FREE_TID,
MVPP2_PE_LAST_FREE_TID);
if (tid < 0)
return tid;
memset(&pe, 0, sizeof(struct mvpp2_prs_entry));
mvpp2_prs_tcam_lu_set(&pe, MVPP2_PRS_LU_PPPOE);
pe.index = tid;
mvpp2_prs_match_etype(&pe, 0, PPP_IP);
mvpp2_prs_sram_next_lu_set(&pe, MVPP2_PRS_LU_IP4);
mvpp2_prs_sram_ri_update(&pe, MVPP2_PRS_RI_L3_IP4_OPT,
MVPP2_PRS_RI_L3_PROTO_MASK);
mvpp2_prs_sram_shift_set(&pe, MVPP2_ETH_TYPE_LEN + 4,
MVPP2_PRS_SRAM_OP_SEL_SHIFT_ADD);
mvpp2_prs_sram_offset_set(&pe, MVPP2_PRS_SRAM_UDF_TYPE_L3,
MVPP2_ETH_TYPE_LEN,
MVPP2_PRS_SRAM_OP_SEL_UDF_ADD);
mvpp2_prs_shadow_set(priv, pe.index, MVPP2_PRS_LU_PPPOE);
mvpp2_prs_hw_write(priv, &pe);
tid = mvpp2_prs_tcam_first_free(priv, MVPP2_PE_FIRST_FREE_TID,
MVPP2_PE_LAST_FREE_TID);
if (tid < 0)
return tid;
pe.index = tid;
mvpp2_prs_tcam_data_byte_set(&pe, MVPP2_ETH_TYPE_LEN,
MVPP2_PRS_IPV4_HEAD | MVPP2_PRS_IPV4_IHL,
MVPP2_PRS_IPV4_HEAD_MASK |
MVPP2_PRS_IPV4_IHL_MASK);
pe.sram.word[MVPP2_PRS_SRAM_RI_WORD] = 0x0;
pe.sram.word[MVPP2_PRS_SRAM_RI_CTRL_WORD] = 0x0;
mvpp2_prs_sram_ri_update(&pe, MVPP2_PRS_RI_L3_IP4,
MVPP2_PRS_RI_L3_PROTO_MASK);
mvpp2_prs_shadow_set(priv, pe.index, MVPP2_PRS_LU_PPPOE);
mvpp2_prs_hw_write(priv, &pe);
tid = mvpp2_prs_tcam_first_free(priv, MVPP2_PE_FIRST_FREE_TID,
MVPP2_PE_LAST_FREE_TID);
if (tid < 0)
return tid;
memset(&pe, 0, sizeof(struct mvpp2_prs_entry));
mvpp2_prs_tcam_lu_set(&pe, MVPP2_PRS_LU_PPPOE);
pe.index = tid;
mvpp2_prs_match_etype(&pe, 0, PPP_IPV6);
mvpp2_prs_sram_next_lu_set(&pe, MVPP2_PRS_LU_IP6);
mvpp2_prs_sram_ri_update(&pe, MVPP2_PRS_RI_L3_IP6,
MVPP2_PRS_RI_L3_PROTO_MASK);
mvpp2_prs_sram_shift_set(&pe, MVPP2_ETH_TYPE_LEN + 4,
MVPP2_PRS_SRAM_OP_SEL_SHIFT_ADD);
mvpp2_prs_sram_offset_set(&pe, MVPP2_PRS_SRAM_UDF_TYPE_L3,
MVPP2_ETH_TYPE_LEN,
MVPP2_PRS_SRAM_OP_SEL_UDF_ADD);
mvpp2_prs_shadow_set(priv, pe.index, MVPP2_PRS_LU_PPPOE);
mvpp2_prs_hw_write(priv, &pe);
tid = mvpp2_prs_tcam_first_free(priv, MVPP2_PE_FIRST_FREE_TID,
MVPP2_PE_LAST_FREE_TID);
if (tid < 0)
return tid;
memset(&pe, 0, sizeof(struct mvpp2_prs_entry));
mvpp2_prs_tcam_lu_set(&pe, MVPP2_PRS_LU_PPPOE);
pe.index = tid;
mvpp2_prs_sram_ri_update(&pe, MVPP2_PRS_RI_L3_UN,
MVPP2_PRS_RI_L3_PROTO_MASK);
mvpp2_prs_sram_next_lu_set(&pe, MVPP2_PRS_LU_FLOWS);
mvpp2_prs_sram_bits_set(&pe, MVPP2_PRS_SRAM_LU_GEN_BIT, 1);
mvpp2_prs_sram_offset_set(&pe, MVPP2_PRS_SRAM_UDF_TYPE_L3,
MVPP2_ETH_TYPE_LEN,
MVPP2_PRS_SRAM_OP_SEL_UDF_ADD);
mvpp2_prs_shadow_set(priv, pe.index, MVPP2_PRS_LU_PPPOE);
mvpp2_prs_hw_write(priv, &pe);
return 0;
}
static int mvpp2_prs_ip4_init(struct mvpp2 *priv)
{
struct mvpp2_prs_entry pe;
int err;
err = mvpp2_prs_ip4_proto(priv, IPPROTO_TCP, MVPP2_PRS_RI_L4_TCP,
MVPP2_PRS_RI_L4_PROTO_MASK);
if (err)
return err;
err = mvpp2_prs_ip4_proto(priv, IPPROTO_UDP, MVPP2_PRS_RI_L4_UDP,
MVPP2_PRS_RI_L4_PROTO_MASK);
if (err)
return err;
err = mvpp2_prs_ip4_proto(priv, IPPROTO_IGMP,
MVPP2_PRS_RI_CPU_CODE_RX_SPEC |
MVPP2_PRS_RI_UDF3_RX_SPECIAL,
MVPP2_PRS_RI_CPU_CODE_MASK |
MVPP2_PRS_RI_UDF3_MASK);
if (err)
return err;
err = mvpp2_prs_ip4_cast(priv, MVPP2_PRS_L3_BROAD_CAST);
if (err)
return err;
err = mvpp2_prs_ip4_cast(priv, MVPP2_PRS_L3_MULTI_CAST);
if (err)
return err;
memset(&pe, 0, sizeof(struct mvpp2_prs_entry));
mvpp2_prs_tcam_lu_set(&pe, MVPP2_PRS_LU_IP4);
pe.index = MVPP2_PE_IP4_PROTO_UN;
mvpp2_prs_sram_next_lu_set(&pe, MVPP2_PRS_LU_IP4);
mvpp2_prs_sram_shift_set(&pe, 12, MVPP2_PRS_SRAM_OP_SEL_SHIFT_ADD);
mvpp2_prs_sram_offset_set(&pe, MVPP2_PRS_SRAM_UDF_TYPE_L4,
sizeof(struct iphdr) - 4,
MVPP2_PRS_SRAM_OP_SEL_UDF_ADD);
mvpp2_prs_sram_ai_update(&pe, MVPP2_PRS_IPV4_DIP_AI_BIT,
MVPP2_PRS_IPV4_DIP_AI_BIT);
mvpp2_prs_sram_ri_update(&pe, MVPP2_PRS_RI_L4_OTHER,
MVPP2_PRS_RI_L4_PROTO_MASK);
mvpp2_prs_tcam_ai_update(&pe, 0, MVPP2_PRS_IPV4_DIP_AI_BIT);
mvpp2_prs_tcam_port_map_set(&pe, MVPP2_PRS_PORT_MASK);
mvpp2_prs_shadow_set(priv, pe.index, MVPP2_PRS_LU_IP4);
mvpp2_prs_hw_write(priv, &pe);
memset(&pe, 0, sizeof(struct mvpp2_prs_entry));
mvpp2_prs_tcam_lu_set(&pe, MVPP2_PRS_LU_IP4);
pe.index = MVPP2_PE_IP4_ADDR_UN;
mvpp2_prs_sram_next_lu_set(&pe, MVPP2_PRS_LU_FLOWS);
mvpp2_prs_sram_bits_set(&pe, MVPP2_PRS_SRAM_LU_GEN_BIT, 1);
mvpp2_prs_sram_ri_update(&pe, MVPP2_PRS_RI_L3_UCAST,
MVPP2_PRS_RI_L3_ADDR_MASK);
mvpp2_prs_tcam_ai_update(&pe, MVPP2_PRS_IPV4_DIP_AI_BIT,
MVPP2_PRS_IPV4_DIP_AI_BIT);
mvpp2_prs_tcam_port_map_set(&pe, MVPP2_PRS_PORT_MASK);
mvpp2_prs_shadow_set(priv, pe.index, MVPP2_PRS_LU_IP4);
mvpp2_prs_hw_write(priv, &pe);
return 0;
}
static int mvpp2_prs_ip6_init(struct mvpp2 *priv)
{
struct mvpp2_prs_entry pe;
int tid, err;
err = mvpp2_prs_ip6_proto(priv, IPPROTO_TCP,
MVPP2_PRS_RI_L4_TCP,
MVPP2_PRS_RI_L4_PROTO_MASK);
if (err)
return err;
err = mvpp2_prs_ip6_proto(priv, IPPROTO_UDP,
MVPP2_PRS_RI_L4_UDP,
MVPP2_PRS_RI_L4_PROTO_MASK);
if (err)
return err;
err = mvpp2_prs_ip6_proto(priv, IPPROTO_ICMPV6,
MVPP2_PRS_RI_CPU_CODE_RX_SPEC |
MVPP2_PRS_RI_UDF3_RX_SPECIAL,
MVPP2_PRS_RI_CPU_CODE_MASK |
MVPP2_PRS_RI_UDF3_MASK);
if (err)
return err;
err = mvpp2_prs_ip6_proto(priv, IPPROTO_IPIP,
MVPP2_PRS_RI_UDF7_IP6_LITE,
MVPP2_PRS_RI_UDF7_MASK);
if (err)
return err;
err = mvpp2_prs_ip6_cast(priv, MVPP2_PRS_L3_MULTI_CAST);
if (err)
return err;
tid = mvpp2_prs_tcam_first_free(priv, MVPP2_PE_FIRST_FREE_TID,
MVPP2_PE_LAST_FREE_TID);
if (tid < 0)
return tid;
memset(&pe, 0, sizeof(struct mvpp2_prs_entry));
mvpp2_prs_tcam_lu_set(&pe, MVPP2_PRS_LU_IP6);
pe.index = tid;
mvpp2_prs_sram_next_lu_set(&pe, MVPP2_PRS_LU_FLOWS);
mvpp2_prs_sram_bits_set(&pe, MVPP2_PRS_SRAM_LU_GEN_BIT, 1);
mvpp2_prs_sram_ri_update(&pe, MVPP2_PRS_RI_L3_UN |
MVPP2_PRS_RI_DROP_MASK,
MVPP2_PRS_RI_L3_PROTO_MASK |
MVPP2_PRS_RI_DROP_MASK);
mvpp2_prs_tcam_data_byte_set(&pe, 1, 0x00, MVPP2_PRS_IPV6_HOP_MASK);
mvpp2_prs_tcam_ai_update(&pe, MVPP2_PRS_IPV6_NO_EXT_AI_BIT,
MVPP2_PRS_IPV6_NO_EXT_AI_BIT);
mvpp2_prs_shadow_set(priv, pe.index, MVPP2_PRS_LU_IP4);
mvpp2_prs_hw_write(priv, &pe);
memset(&pe, 0, sizeof(struct mvpp2_prs_entry));
mvpp2_prs_tcam_lu_set(&pe, MVPP2_PRS_LU_IP6);
pe.index = MVPP2_PE_IP6_PROTO_UN;
mvpp2_prs_sram_next_lu_set(&pe, MVPP2_PRS_LU_FLOWS);
mvpp2_prs_sram_bits_set(&pe, MVPP2_PRS_SRAM_LU_GEN_BIT, 1);
mvpp2_prs_sram_ri_update(&pe, MVPP2_PRS_RI_L4_OTHER,
MVPP2_PRS_RI_L4_PROTO_MASK);
mvpp2_prs_sram_offset_set(&pe, MVPP2_PRS_SRAM_UDF_TYPE_L4,
sizeof(struct ipv6hdr) - 4,
MVPP2_PRS_SRAM_OP_SEL_UDF_ADD);
mvpp2_prs_tcam_ai_update(&pe, MVPP2_PRS_IPV6_NO_EXT_AI_BIT,
MVPP2_PRS_IPV6_NO_EXT_AI_BIT);
mvpp2_prs_tcam_port_map_set(&pe, MVPP2_PRS_PORT_MASK);
mvpp2_prs_shadow_set(priv, pe.index, MVPP2_PRS_LU_IP4);
mvpp2_prs_hw_write(priv, &pe);
memset(&pe, 0, sizeof(struct mvpp2_prs_entry));
mvpp2_prs_tcam_lu_set(&pe, MVPP2_PRS_LU_IP6);
pe.index = MVPP2_PE_IP6_EXT_PROTO_UN;
mvpp2_prs_sram_next_lu_set(&pe, MVPP2_PRS_LU_FLOWS);
mvpp2_prs_sram_bits_set(&pe, MVPP2_PRS_SRAM_LU_GEN_BIT, 1);
mvpp2_prs_sram_ri_update(&pe, MVPP2_PRS_RI_L4_OTHER,
MVPP2_PRS_RI_L4_PROTO_MASK);
mvpp2_prs_tcam_ai_update(&pe, MVPP2_PRS_IPV6_EXT_AI_BIT,
MVPP2_PRS_IPV6_EXT_AI_BIT);
mvpp2_prs_tcam_port_map_set(&pe, MVPP2_PRS_PORT_MASK);
mvpp2_prs_shadow_set(priv, pe.index, MVPP2_PRS_LU_IP4);
mvpp2_prs_hw_write(priv, &pe);
memset(&pe, 0, sizeof(struct mvpp2_prs_entry));
mvpp2_prs_tcam_lu_set(&pe, MVPP2_PRS_LU_IP6);
pe.index = MVPP2_PE_IP6_ADDR_UN;
mvpp2_prs_sram_next_lu_set(&pe, MVPP2_PRS_LU_IP6);
mvpp2_prs_sram_ri_update(&pe, MVPP2_PRS_RI_L3_UCAST,
MVPP2_PRS_RI_L3_ADDR_MASK);
mvpp2_prs_sram_ai_update(&pe, MVPP2_PRS_IPV6_NO_EXT_AI_BIT,
MVPP2_PRS_IPV6_NO_EXT_AI_BIT);
mvpp2_prs_sram_shift_set(&pe, -18, MVPP2_PRS_SRAM_OP_SEL_SHIFT_ADD);
mvpp2_prs_tcam_ai_update(&pe, 0, MVPP2_PRS_IPV6_NO_EXT_AI_BIT);
mvpp2_prs_tcam_port_map_set(&pe, MVPP2_PRS_PORT_MASK);
mvpp2_prs_shadow_set(priv, pe.index, MVPP2_PRS_LU_IP6);
mvpp2_prs_hw_write(priv, &pe);
return 0;
}
static int mvpp2_prs_default_init(struct platform_device *pdev,
struct mvpp2 *priv)
{
int err, index, i;
mvpp2_write(priv, MVPP2_PRS_TCAM_CTRL_REG, MVPP2_PRS_TCAM_EN_MASK);
for (index = 0; index < MVPP2_PRS_TCAM_SRAM_SIZE; index++) {
mvpp2_write(priv, MVPP2_PRS_TCAM_IDX_REG, index);
for (i = 0; i < MVPP2_PRS_TCAM_WORDS; i++)
mvpp2_write(priv, MVPP2_PRS_TCAM_DATA_REG(i), 0);
mvpp2_write(priv, MVPP2_PRS_SRAM_IDX_REG, index);
for (i = 0; i < MVPP2_PRS_SRAM_WORDS; i++)
mvpp2_write(priv, MVPP2_PRS_SRAM_DATA_REG(i), 0);
}
for (index = 0; index < MVPP2_PRS_TCAM_SRAM_SIZE; index++)
mvpp2_prs_hw_inv(priv, index);
priv->prs_shadow = devm_kcalloc(&pdev->dev, MVPP2_PRS_TCAM_SRAM_SIZE,
sizeof(struct mvpp2_prs_shadow),
GFP_KERNEL);
if (!priv->prs_shadow)
return -ENOMEM;
for (index = 0; index < MVPP2_MAX_PORTS; index++)
mvpp2_prs_hw_port_init(priv, index, MVPP2_PRS_LU_MH,
MVPP2_PRS_PORT_LU_MAX, 0);
mvpp2_prs_def_flow_init(priv);
mvpp2_prs_mh_init(priv);
mvpp2_prs_mac_init(priv);
mvpp2_prs_dsa_init(priv);
err = mvpp2_prs_etype_init(priv);
if (err)
return err;
err = mvpp2_prs_vlan_init(pdev, priv);
if (err)
return err;
err = mvpp2_prs_pppoe_init(priv);
if (err)
return err;
err = mvpp2_prs_ip6_init(priv);
if (err)
return err;
err = mvpp2_prs_ip4_init(priv);
if (err)
return err;
return 0;
}
static bool mvpp2_prs_mac_range_equals(struct mvpp2_prs_entry *pe,
const u8 *da, unsigned char *mask)
{
unsigned char tcam_byte, tcam_mask;
int index;
for (index = 0; index < ETH_ALEN; index++) {
mvpp2_prs_tcam_data_byte_get(pe, index, &tcam_byte, &tcam_mask);
if (tcam_mask != mask[index])
return false;
if ((tcam_mask & tcam_byte) != (da[index] & mask[index]))
return false;
}
return true;
}
static struct mvpp2_prs_entry *
mvpp2_prs_mac_da_range_find(struct mvpp2 *priv, int pmap, const u8 *da,
unsigned char *mask, int udf_type)
{
struct mvpp2_prs_entry *pe;
int tid;
pe = kzalloc(sizeof(*pe), GFP_KERNEL);
if (!pe)
return NULL;
mvpp2_prs_tcam_lu_set(pe, MVPP2_PRS_LU_MAC);
for (tid = MVPP2_PE_FIRST_FREE_TID;
tid <= MVPP2_PE_LAST_FREE_TID; tid++) {
unsigned int entry_pmap;
if (!priv->prs_shadow[tid].valid ||
(priv->prs_shadow[tid].lu != MVPP2_PRS_LU_MAC) ||
(priv->prs_shadow[tid].udf != udf_type))
continue;
pe->index = tid;
mvpp2_prs_hw_read(priv, pe);
entry_pmap = mvpp2_prs_tcam_port_map_get(pe);
if (mvpp2_prs_mac_range_equals(pe, da, mask) &&
entry_pmap == pmap)
return pe;
}
kfree(pe);
return NULL;
}
static int mvpp2_prs_mac_da_accept(struct mvpp2 *priv, int port,
const u8 *da, bool add)
{
struct mvpp2_prs_entry *pe;
unsigned int pmap, len, ri;
unsigned char mask[ETH_ALEN] = { 0xff, 0xff, 0xff, 0xff, 0xff, 0xff };
int tid;
pe = mvpp2_prs_mac_da_range_find(priv, (1 << port), da, mask,
MVPP2_PRS_UDF_MAC_DEF);
if (!pe) {
if (!add)
return 0;
for (tid = MVPP2_PE_FIRST_FREE_TID;
tid <= MVPP2_PE_LAST_FREE_TID; tid++)
if (priv->prs_shadow[tid].valid &&
(priv->prs_shadow[tid].lu == MVPP2_PRS_LU_MAC) &&
(priv->prs_shadow[tid].udf ==
MVPP2_PRS_UDF_MAC_RANGE))
break;
tid = mvpp2_prs_tcam_first_free(priv, MVPP2_PE_FIRST_FREE_TID,
tid - 1);
if (tid < 0)
return tid;
pe = kzalloc(sizeof(*pe), GFP_KERNEL);
if (!pe)
return -1;
mvpp2_prs_tcam_lu_set(pe, MVPP2_PRS_LU_MAC);
pe->index = tid;
mvpp2_prs_tcam_port_map_set(pe, 0);
}
mvpp2_prs_tcam_port_set(pe, port, add);
pmap = mvpp2_prs_tcam_port_map_get(pe);
if (pmap == 0) {
if (add) {
kfree(pe);
return -1;
}
mvpp2_prs_hw_inv(priv, pe->index);
priv->prs_shadow[pe->index].valid = false;
kfree(pe);
return 0;
}
mvpp2_prs_sram_next_lu_set(pe, MVPP2_PRS_LU_DSA);
len = ETH_ALEN;
while (len--)
mvpp2_prs_tcam_data_byte_set(pe, len, da[len], 0xff);
if (is_broadcast_ether_addr(da))
ri = MVPP2_PRS_RI_L2_BCAST;
else if (is_multicast_ether_addr(da))
ri = MVPP2_PRS_RI_L2_MCAST;
else
ri = MVPP2_PRS_RI_L2_UCAST | MVPP2_PRS_RI_MAC_ME_MASK;
mvpp2_prs_sram_ri_update(pe, ri, MVPP2_PRS_RI_L2_CAST_MASK |
MVPP2_PRS_RI_MAC_ME_MASK);
mvpp2_prs_shadow_ri_set(priv, pe->index, ri, MVPP2_PRS_RI_L2_CAST_MASK |
MVPP2_PRS_RI_MAC_ME_MASK);
mvpp2_prs_sram_shift_set(pe, 2 * ETH_ALEN,
MVPP2_PRS_SRAM_OP_SEL_SHIFT_ADD);
priv->prs_shadow[pe->index].udf = MVPP2_PRS_UDF_MAC_DEF;
mvpp2_prs_shadow_set(priv, pe->index, MVPP2_PRS_LU_MAC);
mvpp2_prs_hw_write(priv, pe);
kfree(pe);
return 0;
}
static int mvpp2_prs_update_mac_da(struct net_device *dev, const u8 *da)
{
struct mvpp2_port *port = netdev_priv(dev);
int err;
err = mvpp2_prs_mac_da_accept(port->priv, port->id, dev->dev_addr,
false);
if (err)
return err;
err = mvpp2_prs_mac_da_accept(port->priv, port->id, da, true);
if (err)
return err;
ether_addr_copy(dev->dev_addr, da);
return 0;
}
static void mvpp2_prs_mcast_del_all(struct mvpp2 *priv, int port)
{
struct mvpp2_prs_entry pe;
int index, tid;
for (tid = MVPP2_PE_FIRST_FREE_TID;
tid <= MVPP2_PE_LAST_FREE_TID; tid++) {
unsigned char da[ETH_ALEN], da_mask[ETH_ALEN];
if (!priv->prs_shadow[tid].valid ||
(priv->prs_shadow[tid].lu != MVPP2_PRS_LU_MAC) ||
(priv->prs_shadow[tid].udf != MVPP2_PRS_UDF_MAC_DEF))
continue;
pe.index = tid;
mvpp2_prs_hw_read(priv, &pe);
for (index = 0; index < ETH_ALEN; index++)
mvpp2_prs_tcam_data_byte_get(&pe, index, &da[index],
&da_mask[index]);
if (is_multicast_ether_addr(da) && !is_broadcast_ether_addr(da))
mvpp2_prs_mac_da_accept(priv, port, da, false);
}
}
static int mvpp2_prs_tag_mode_set(struct mvpp2 *priv, int port, int type)
{
switch (type) {
case MVPP2_TAG_TYPE_EDSA:
mvpp2_prs_dsa_tag_set(priv, port, true,
MVPP2_PRS_TAGGED, MVPP2_PRS_EDSA);
mvpp2_prs_dsa_tag_set(priv, port, true,
MVPP2_PRS_UNTAGGED, MVPP2_PRS_EDSA);
mvpp2_prs_dsa_tag_set(priv, port, false,
MVPP2_PRS_TAGGED, MVPP2_PRS_DSA);
mvpp2_prs_dsa_tag_set(priv, port, false,
MVPP2_PRS_UNTAGGED, MVPP2_PRS_DSA);
break;
case MVPP2_TAG_TYPE_DSA:
mvpp2_prs_dsa_tag_set(priv, port, true,
MVPP2_PRS_TAGGED, MVPP2_PRS_DSA);
mvpp2_prs_dsa_tag_set(priv, port, true,
MVPP2_PRS_UNTAGGED, MVPP2_PRS_DSA);
mvpp2_prs_dsa_tag_set(priv, port, false,
MVPP2_PRS_TAGGED, MVPP2_PRS_EDSA);
mvpp2_prs_dsa_tag_set(priv, port, false,
MVPP2_PRS_UNTAGGED, MVPP2_PRS_EDSA);
break;
case MVPP2_TAG_TYPE_MH:
case MVPP2_TAG_TYPE_NONE:
mvpp2_prs_dsa_tag_set(priv, port, false,
MVPP2_PRS_TAGGED, MVPP2_PRS_DSA);
mvpp2_prs_dsa_tag_set(priv, port, false,
MVPP2_PRS_UNTAGGED, MVPP2_PRS_DSA);
mvpp2_prs_dsa_tag_set(priv, port, false,
MVPP2_PRS_TAGGED, MVPP2_PRS_EDSA);
mvpp2_prs_dsa_tag_set(priv, port, false,
MVPP2_PRS_UNTAGGED, MVPP2_PRS_EDSA);
break;
default:
if ((type < 0) || (type > MVPP2_TAG_TYPE_EDSA))
return -EINVAL;
}
return 0;
}
static int mvpp2_prs_def_flow(struct mvpp2_port *port)
{
struct mvpp2_prs_entry *pe;
int tid;
pe = mvpp2_prs_flow_find(port->priv, port->id);
if (!pe) {
tid = mvpp2_prs_tcam_first_free(port->priv,
MVPP2_PE_LAST_FREE_TID,
MVPP2_PE_FIRST_FREE_TID);
if (tid < 0)
return tid;
pe = kzalloc(sizeof(*pe), GFP_KERNEL);
if (!pe)
return -ENOMEM;
mvpp2_prs_tcam_lu_set(pe, MVPP2_PRS_LU_FLOWS);
pe->index = tid;
mvpp2_prs_sram_ai_update(pe, port->id, MVPP2_PRS_FLOW_ID_MASK);
mvpp2_prs_sram_bits_set(pe, MVPP2_PRS_SRAM_LU_DONE_BIT, 1);
mvpp2_prs_shadow_set(port->priv, pe->index, MVPP2_PRS_LU_FLOWS);
}
mvpp2_prs_tcam_port_map_set(pe, (1 << port->id));
mvpp2_prs_hw_write(port->priv, pe);
kfree(pe);
return 0;
}
static void mvpp2_cls_flow_write(struct mvpp2 *priv,
struct mvpp2_cls_flow_entry *fe)
{
mvpp2_write(priv, MVPP2_CLS_FLOW_INDEX_REG, fe->index);
mvpp2_write(priv, MVPP2_CLS_FLOW_TBL0_REG, fe->data[0]);
mvpp2_write(priv, MVPP2_CLS_FLOW_TBL1_REG, fe->data[1]);
mvpp2_write(priv, MVPP2_CLS_FLOW_TBL2_REG, fe->data[2]);
}
static void mvpp2_cls_lookup_write(struct mvpp2 *priv,
struct mvpp2_cls_lookup_entry *le)
{
u32 val;
val = (le->way << MVPP2_CLS_LKP_INDEX_WAY_OFFS) | le->lkpid;
mvpp2_write(priv, MVPP2_CLS_LKP_INDEX_REG, val);
mvpp2_write(priv, MVPP2_CLS_LKP_TBL_REG, le->data);
}
static void mvpp2_cls_init(struct mvpp2 *priv)
{
struct mvpp2_cls_lookup_entry le;
struct mvpp2_cls_flow_entry fe;
int index;
mvpp2_write(priv, MVPP2_CLS_MODE_REG, MVPP2_CLS_MODE_ACTIVE_MASK);
memset(&fe.data, 0, MVPP2_CLS_FLOWS_TBL_DATA_WORDS);
for (index = 0; index < MVPP2_CLS_FLOWS_TBL_SIZE; index++) {
fe.index = index;
mvpp2_cls_flow_write(priv, &fe);
}
le.data = 0;
for (index = 0; index < MVPP2_CLS_LKP_TBL_SIZE; index++) {
le.lkpid = index;
le.way = 0;
mvpp2_cls_lookup_write(priv, &le);
le.way = 1;
mvpp2_cls_lookup_write(priv, &le);
}
}
static void mvpp2_cls_port_config(struct mvpp2_port *port)
{
struct mvpp2_cls_lookup_entry le;
u32 val;
val = mvpp2_read(port->priv, MVPP2_CLS_PORT_WAY_REG);
val &= ~MVPP2_CLS_PORT_WAY_MASK(port->id);
mvpp2_write(port->priv, MVPP2_CLS_PORT_WAY_REG, val);
le.lkpid = port->id;
le.way = 0;
le.data = 0;
le.data &= ~MVPP2_CLS_LKP_TBL_RXQ_MASK;
le.data |= port->first_rxq;
le.data &= ~MVPP2_CLS_LKP_TBL_LOOKUP_EN_MASK;
mvpp2_cls_lookup_write(port->priv, &le);
}
static void mvpp2_cls_oversize_rxq_set(struct mvpp2_port *port)
{
u32 val;
mvpp2_write(port->priv, MVPP2_CLS_OVERSIZE_RXQ_LOW_REG(port->id),
port->first_rxq & MVPP2_CLS_OVERSIZE_RXQ_LOW_MASK);
mvpp2_write(port->priv, MVPP2_CLS_SWFWD_P2HQ_REG(port->id),
(port->first_rxq >> MVPP2_CLS_OVERSIZE_RXQ_LOW_BITS));
val = mvpp2_read(port->priv, MVPP2_CLS_SWFWD_PCTRL_REG);
val |= MVPP2_CLS_SWFWD_PCTRL_MASK(port->id);
mvpp2_write(port->priv, MVPP2_CLS_SWFWD_PCTRL_REG, val);
}
static int mvpp2_bm_pool_create(struct platform_device *pdev,
struct mvpp2 *priv,
struct mvpp2_bm_pool *bm_pool, int size)
{
int size_bytes;
u32 val;
size_bytes = sizeof(u32) * size;
bm_pool->virt_addr = dma_alloc_coherent(&pdev->dev, size_bytes,
&bm_pool->phys_addr,
GFP_KERNEL);
if (!bm_pool->virt_addr)
return -ENOMEM;
if (!IS_ALIGNED((u32)bm_pool->virt_addr, MVPP2_BM_POOL_PTR_ALIGN)) {
dma_free_coherent(&pdev->dev, size_bytes, bm_pool->virt_addr,
bm_pool->phys_addr);
dev_err(&pdev->dev, "BM pool %d is not %d bytes aligned\n",
bm_pool->id, MVPP2_BM_POOL_PTR_ALIGN);
return -ENOMEM;
}
mvpp2_write(priv, MVPP2_BM_POOL_BASE_REG(bm_pool->id),
bm_pool->phys_addr);
mvpp2_write(priv, MVPP2_BM_POOL_SIZE_REG(bm_pool->id), size);
val = mvpp2_read(priv, MVPP2_BM_POOL_CTRL_REG(bm_pool->id));
val |= MVPP2_BM_START_MASK;
mvpp2_write(priv, MVPP2_BM_POOL_CTRL_REG(bm_pool->id), val);
bm_pool->type = MVPP2_BM_FREE;
bm_pool->size = size;
bm_pool->pkt_size = 0;
bm_pool->buf_num = 0;
atomic_set(&bm_pool->in_use, 0);
return 0;
}
static void mvpp2_bm_pool_bufsize_set(struct mvpp2 *priv,
struct mvpp2_bm_pool *bm_pool,
int buf_size)
{
u32 val;
bm_pool->buf_size = buf_size;
val = ALIGN(buf_size, 1 << MVPP2_POOL_BUF_SIZE_OFFSET);
mvpp2_write(priv, MVPP2_POOL_BUF_SIZE_REG(bm_pool->id), val);
}
static void mvpp2_bm_bufs_free(struct device *dev, struct mvpp2 *priv,
struct mvpp2_bm_pool *bm_pool)
{
int i;
for (i = 0; i < bm_pool->buf_num; i++) {
dma_addr_t buf_phys_addr;
u32 vaddr;
buf_phys_addr = mvpp2_read(priv,
MVPP2_BM_PHY_ALLOC_REG(bm_pool->id));
vaddr = mvpp2_read(priv, MVPP2_BM_VIRT_ALLOC_REG);
dma_unmap_single(dev, buf_phys_addr,
bm_pool->buf_size, DMA_FROM_DEVICE);
if (!vaddr)
break;
dev_kfree_skb_any((struct sk_buff *)vaddr);
}
bm_pool->buf_num -= i;
}
static int mvpp2_bm_pool_destroy(struct platform_device *pdev,
struct mvpp2 *priv,
struct mvpp2_bm_pool *bm_pool)
{
u32 val;
mvpp2_bm_bufs_free(&pdev->dev, priv, bm_pool);
if (bm_pool->buf_num) {
WARN(1, "cannot free all buffers in pool %d\n", bm_pool->id);
return 0;
}
val = mvpp2_read(priv, MVPP2_BM_POOL_CTRL_REG(bm_pool->id));
val |= MVPP2_BM_STOP_MASK;
mvpp2_write(priv, MVPP2_BM_POOL_CTRL_REG(bm_pool->id), val);
dma_free_coherent(&pdev->dev, sizeof(u32) * bm_pool->size,
bm_pool->virt_addr,
bm_pool->phys_addr);
return 0;
}
static int mvpp2_bm_pools_init(struct platform_device *pdev,
struct mvpp2 *priv)
{
int i, err, size;
struct mvpp2_bm_pool *bm_pool;
size = MVPP2_BM_POOL_SIZE_MAX;
for (i = 0; i < MVPP2_BM_POOLS_NUM; i++) {
bm_pool = &priv->bm_pools[i];
bm_pool->id = i;
err = mvpp2_bm_pool_create(pdev, priv, bm_pool, size);
if (err)
goto err_unroll_pools;
mvpp2_bm_pool_bufsize_set(priv, bm_pool, 0);
}
return 0;
err_unroll_pools:
dev_err(&pdev->dev, "failed to create BM pool %d, size %d\n", i, size);
for (i = i - 1; i >= 0; i--)
mvpp2_bm_pool_destroy(pdev, priv, &priv->bm_pools[i]);
return err;
}
static int mvpp2_bm_init(struct platform_device *pdev, struct mvpp2 *priv)
{
int i, err;
for (i = 0; i < MVPP2_BM_POOLS_NUM; i++) {
mvpp2_write(priv, MVPP2_BM_INTR_MASK_REG(i), 0);
mvpp2_write(priv, MVPP2_BM_INTR_CAUSE_REG(i), 0);
}
priv->bm_pools = devm_kcalloc(&pdev->dev, MVPP2_BM_POOLS_NUM,
sizeof(struct mvpp2_bm_pool), GFP_KERNEL);
if (!priv->bm_pools)
return -ENOMEM;
err = mvpp2_bm_pools_init(pdev, priv);
if (err < 0)
return err;
return 0;
}
static void mvpp2_rxq_long_pool_set(struct mvpp2_port *port,
int lrxq, int long_pool)
{
u32 val;
int prxq;
prxq = port->rxqs[lrxq]->id;
val = mvpp2_read(port->priv, MVPP2_RXQ_CONFIG_REG(prxq));
val &= ~MVPP2_RXQ_POOL_LONG_MASK;
val |= ((long_pool << MVPP2_RXQ_POOL_LONG_OFFS) &
MVPP2_RXQ_POOL_LONG_MASK);
mvpp2_write(port->priv, MVPP2_RXQ_CONFIG_REG(prxq), val);
}
static void mvpp2_rxq_short_pool_set(struct mvpp2_port *port,
int lrxq, int short_pool)
{
u32 val;
int prxq;
prxq = port->rxqs[lrxq]->id;
val = mvpp2_read(port->priv, MVPP2_RXQ_CONFIG_REG(prxq));
val &= ~MVPP2_RXQ_POOL_SHORT_MASK;
val |= ((short_pool << MVPP2_RXQ_POOL_SHORT_OFFS) &
MVPP2_RXQ_POOL_SHORT_MASK);
mvpp2_write(port->priv, MVPP2_RXQ_CONFIG_REG(prxq), val);
}
static struct sk_buff *mvpp2_skb_alloc(struct mvpp2_port *port,
struct mvpp2_bm_pool *bm_pool,
dma_addr_t *buf_phys_addr,
gfp_t gfp_mask)
{
struct sk_buff *skb;
dma_addr_t phys_addr;
skb = __dev_alloc_skb(bm_pool->pkt_size, gfp_mask);
if (!skb)
return NULL;
phys_addr = dma_map_single(port->dev->dev.parent, skb->head,
MVPP2_RX_BUF_SIZE(bm_pool->pkt_size),
DMA_FROM_DEVICE);
if (unlikely(dma_mapping_error(port->dev->dev.parent, phys_addr))) {
dev_kfree_skb_any(skb);
return NULL;
}
*buf_phys_addr = phys_addr;
return skb;
}
static inline u32 mvpp2_bm_cookie_pool_set(u32 cookie, int pool)
{
u32 bm;
bm = cookie & ~(0xFF << MVPP2_BM_COOKIE_POOL_OFFS);
bm |= ((pool & 0xFF) << MVPP2_BM_COOKIE_POOL_OFFS);
return bm;
}
static inline int mvpp2_bm_cookie_pool_get(u32 cookie)
{
return (cookie >> MVPP2_BM_COOKIE_POOL_OFFS) & 0xFF;
}
static inline void mvpp2_bm_pool_put(struct mvpp2_port *port, int pool,
u32 buf_phys_addr, u32 buf_virt_addr)
{
mvpp2_write(port->priv, MVPP2_BM_VIRT_RLS_REG, buf_virt_addr);
mvpp2_write(port->priv, MVPP2_BM_PHY_RLS_REG(pool), buf_phys_addr);
}
static void mvpp2_bm_pool_mc_put(struct mvpp2_port *port, int pool,
u32 buf_phys_addr, u32 buf_virt_addr,
int mc_id)
{
u32 val = 0;
val |= (mc_id & MVPP2_BM_MC_ID_MASK);
mvpp2_write(port->priv, MVPP2_BM_MC_RLS_REG, val);
mvpp2_bm_pool_put(port, pool,
buf_phys_addr | MVPP2_BM_PHY_RLS_MC_BUFF_MASK,
buf_virt_addr);
}
static void mvpp2_pool_refill(struct mvpp2_port *port, u32 bm,
u32 phys_addr, u32 cookie)
{
int pool = mvpp2_bm_cookie_pool_get(bm);
mvpp2_bm_pool_put(port, pool, phys_addr, cookie);
}
static int mvpp2_bm_bufs_add(struct mvpp2_port *port,
struct mvpp2_bm_pool *bm_pool, int buf_num)
{
struct sk_buff *skb;
int i, buf_size, total_size;
u32 bm;
dma_addr_t phys_addr;
buf_size = MVPP2_RX_BUF_SIZE(bm_pool->pkt_size);
total_size = MVPP2_RX_TOTAL_SIZE(buf_size);
if (buf_num < 0 ||
(buf_num + bm_pool->buf_num > bm_pool->size)) {
netdev_err(port->dev,
"cannot allocate %d buffers for pool %d\n",
buf_num, bm_pool->id);
return 0;
}
bm = mvpp2_bm_cookie_pool_set(0, bm_pool->id);
for (i = 0; i < buf_num; i++) {
skb = mvpp2_skb_alloc(port, bm_pool, &phys_addr, GFP_KERNEL);
if (!skb)
break;
mvpp2_pool_refill(port, bm, (u32)phys_addr, (u32)skb);
}
bm_pool->buf_num += i;
bm_pool->in_use_thresh = bm_pool->buf_num / 4;
netdev_dbg(port->dev,
"%s pool %d: pkt_size=%4d, buf_size=%4d, total_size=%4d\n",
bm_pool->type == MVPP2_BM_SWF_SHORT ? "short" : " long",
bm_pool->id, bm_pool->pkt_size, buf_size, total_size);
netdev_dbg(port->dev,
"%s pool %d: %d of %d buffers added\n",
bm_pool->type == MVPP2_BM_SWF_SHORT ? "short" : " long",
bm_pool->id, i, buf_num);
return i;
}
static struct mvpp2_bm_pool *
mvpp2_bm_pool_use(struct mvpp2_port *port, int pool, enum mvpp2_bm_type type,
int pkt_size)
{
struct mvpp2_bm_pool *new_pool = &port->priv->bm_pools[pool];
int num;
if (new_pool->type != MVPP2_BM_FREE && new_pool->type != type) {
netdev_err(port->dev, "mixing pool types is forbidden\n");
return NULL;
}
if (new_pool->type == MVPP2_BM_FREE)
new_pool->type = type;
if (((type == MVPP2_BM_SWF_LONG) && (pkt_size > new_pool->pkt_size)) ||
(new_pool->pkt_size == 0)) {
int pkts_num;
pkts_num = new_pool->buf_num;
if (pkts_num == 0)
pkts_num = type == MVPP2_BM_SWF_LONG ?
MVPP2_BM_LONG_BUF_NUM :
MVPP2_BM_SHORT_BUF_NUM;
else
mvpp2_bm_bufs_free(port->dev->dev.parent,
port->priv, new_pool);
new_pool->pkt_size = pkt_size;
num = mvpp2_bm_bufs_add(port, new_pool, pkts_num);
if (num != pkts_num) {
WARN(1, "pool %d: %d of %d allocated\n",
new_pool->id, num, pkts_num);
return NULL;
}
}
mvpp2_bm_pool_bufsize_set(port->priv, new_pool,
MVPP2_RX_BUF_SIZE(new_pool->pkt_size));
return new_pool;
}
static int mvpp2_swf_bm_pool_init(struct mvpp2_port *port)
{
int rxq;
if (!port->pool_long) {
port->pool_long =
mvpp2_bm_pool_use(port, MVPP2_BM_SWF_LONG_POOL(port->id),
MVPP2_BM_SWF_LONG,
port->pkt_size);
if (!port->pool_long)
return -ENOMEM;
port->pool_long->port_map |= (1 << port->id);
for (rxq = 0; rxq < rxq_number; rxq++)
mvpp2_rxq_long_pool_set(port, rxq, port->pool_long->id);
}
if (!port->pool_short) {
port->pool_short =
mvpp2_bm_pool_use(port, MVPP2_BM_SWF_SHORT_POOL,
MVPP2_BM_SWF_SHORT,
MVPP2_BM_SHORT_PKT_SIZE);
if (!port->pool_short)
return -ENOMEM;
port->pool_short->port_map |= (1 << port->id);
for (rxq = 0; rxq < rxq_number; rxq++)
mvpp2_rxq_short_pool_set(port, rxq,
port->pool_short->id);
}
return 0;
}
static int mvpp2_bm_update_mtu(struct net_device *dev, int mtu)
{
struct mvpp2_port *port = netdev_priv(dev);
struct mvpp2_bm_pool *port_pool = port->pool_long;
int num, pkts_num = port_pool->buf_num;
int pkt_size = MVPP2_RX_PKT_SIZE(mtu);
mvpp2_bm_bufs_free(dev->dev.parent, port->priv, port_pool);
if (port_pool->buf_num) {
WARN(1, "cannot free all buffers in pool %d\n", port_pool->id);
return -EIO;
}
port_pool->pkt_size = pkt_size;
num = mvpp2_bm_bufs_add(port, port_pool, pkts_num);
if (num != pkts_num) {
WARN(1, "pool %d: %d of %d allocated\n",
port_pool->id, num, pkts_num);
return -EIO;
}
mvpp2_bm_pool_bufsize_set(port->priv, port_pool,
MVPP2_RX_BUF_SIZE(port_pool->pkt_size));
dev->mtu = mtu;
netdev_update_features(dev);
return 0;
}
static inline void mvpp2_interrupts_enable(struct mvpp2_port *port)
{
int cpu, cpu_mask = 0;
for_each_present_cpu(cpu)
cpu_mask |= 1 << cpu;
mvpp2_write(port->priv, MVPP2_ISR_ENABLE_REG(port->id),
MVPP2_ISR_ENABLE_INTERRUPT(cpu_mask));
}
static inline void mvpp2_interrupts_disable(struct mvpp2_port *port)
{
int cpu, cpu_mask = 0;
for_each_present_cpu(cpu)
cpu_mask |= 1 << cpu;
mvpp2_write(port->priv, MVPP2_ISR_ENABLE_REG(port->id),
MVPP2_ISR_DISABLE_INTERRUPT(cpu_mask));
}
static void mvpp2_interrupts_mask(void *arg)
{
struct mvpp2_port *port = arg;
mvpp2_write(port->priv, MVPP2_ISR_RX_TX_MASK_REG(port->id), 0);
}
static void mvpp2_interrupts_unmask(void *arg)
{
struct mvpp2_port *port = arg;
mvpp2_write(port->priv, MVPP2_ISR_RX_TX_MASK_REG(port->id),
(MVPP2_CAUSE_MISC_SUM_MASK |
MVPP2_CAUSE_RXQ_OCCUP_DESC_ALL_MASK));
}
static void mvpp2_port_mii_set(struct mvpp2_port *port)
{
u32 val;
val = readl(port->base + MVPP2_GMAC_CTRL_2_REG);
switch (port->phy_interface) {
case PHY_INTERFACE_MODE_SGMII:
val |= MVPP2_GMAC_INBAND_AN_MASK;
break;
case PHY_INTERFACE_MODE_RGMII:
val |= MVPP2_GMAC_PORT_RGMII_MASK;
default:
val &= ~MVPP2_GMAC_PCS_ENABLE_MASK;
}
writel(val, port->base + MVPP2_GMAC_CTRL_2_REG);
}
static void mvpp2_port_fc_adv_enable(struct mvpp2_port *port)
{
u32 val;
val = readl(port->base + MVPP2_GMAC_AUTONEG_CONFIG);
val |= MVPP2_GMAC_FC_ADV_EN;
writel(val, port->base + MVPP2_GMAC_AUTONEG_CONFIG);
}
static void mvpp2_port_enable(struct mvpp2_port *port)
{
u32 val;
val = readl(port->base + MVPP2_GMAC_CTRL_0_REG);
val |= MVPP2_GMAC_PORT_EN_MASK;
val |= MVPP2_GMAC_MIB_CNTR_EN_MASK;
writel(val, port->base + MVPP2_GMAC_CTRL_0_REG);
}
static void mvpp2_port_disable(struct mvpp2_port *port)
{
u32 val;
val = readl(port->base + MVPP2_GMAC_CTRL_0_REG);
val &= ~(MVPP2_GMAC_PORT_EN_MASK);
writel(val, port->base + MVPP2_GMAC_CTRL_0_REG);
}
static void mvpp2_port_periodic_xon_disable(struct mvpp2_port *port)
{
u32 val;
val = readl(port->base + MVPP2_GMAC_CTRL_1_REG) &
~MVPP2_GMAC_PERIODIC_XON_EN_MASK;
writel(val, port->base + MVPP2_GMAC_CTRL_1_REG);
}
static void mvpp2_port_loopback_set(struct mvpp2_port *port)
{
u32 val;
val = readl(port->base + MVPP2_GMAC_CTRL_1_REG);
if (port->speed == 1000)
val |= MVPP2_GMAC_GMII_LB_EN_MASK;
else
val &= ~MVPP2_GMAC_GMII_LB_EN_MASK;
if (port->phy_interface == PHY_INTERFACE_MODE_SGMII)
val |= MVPP2_GMAC_PCS_LB_EN_MASK;
else
val &= ~MVPP2_GMAC_PCS_LB_EN_MASK;
writel(val, port->base + MVPP2_GMAC_CTRL_1_REG);
}
static void mvpp2_port_reset(struct mvpp2_port *port)
{
u32 val;
val = readl(port->base + MVPP2_GMAC_CTRL_2_REG) &
~MVPP2_GMAC_PORT_RESET_MASK;
writel(val, port->base + MVPP2_GMAC_CTRL_2_REG);
while (readl(port->base + MVPP2_GMAC_CTRL_2_REG) &
MVPP2_GMAC_PORT_RESET_MASK)
continue;
}
static inline void mvpp2_gmac_max_rx_size_set(struct mvpp2_port *port)
{
u32 val;
val = readl(port->base + MVPP2_GMAC_CTRL_0_REG);
val &= ~MVPP2_GMAC_MAX_RX_SIZE_MASK;
val |= (((port->pkt_size - MVPP2_MH_SIZE) / 2) <<
MVPP2_GMAC_MAX_RX_SIZE_OFFS);
writel(val, port->base + MVPP2_GMAC_CTRL_0_REG);
}
static void mvpp2_defaults_set(struct mvpp2_port *port)
{
int tx_port_num, val, queue, ptxq, lrxq;
if (port->flags & MVPP2_F_LOOPBACK)
mvpp2_port_loopback_set(port);
val = readl(port->base + MVPP2_GMAC_PORT_FIFO_CFG_1_REG);
val &= ~MVPP2_GMAC_TX_FIFO_MIN_TH_ALL_MASK;
val |= MVPP2_GMAC_TX_FIFO_MIN_TH_MASK(64 - 4 - 2);
writel(val, port->base + MVPP2_GMAC_PORT_FIFO_CFG_1_REG);
tx_port_num = mvpp2_egress_port(port);
mvpp2_write(port->priv, MVPP2_TXP_SCHED_PORT_INDEX_REG,
tx_port_num);
mvpp2_write(port->priv, MVPP2_TXP_SCHED_CMD_1_REG, 0);
for (queue = 0; queue < MVPP2_MAX_TXQ; queue++) {
ptxq = mvpp2_txq_phys(port->id, queue);
mvpp2_write(port->priv,
MVPP2_TXQ_SCHED_TOKEN_CNTR_REG(ptxq), 0);
}
mvpp2_write(port->priv, MVPP2_TXP_SCHED_PERIOD_REG,
port->priv->tclk / USEC_PER_SEC);
val = mvpp2_read(port->priv, MVPP2_TXP_SCHED_REFILL_REG);
val &= ~MVPP2_TXP_REFILL_PERIOD_ALL_MASK;
val |= MVPP2_TXP_REFILL_PERIOD_MASK(1);
val |= MVPP2_TXP_REFILL_TOKENS_ALL_MASK;
mvpp2_write(port->priv, MVPP2_TXP_SCHED_REFILL_REG, val);
val = MVPP2_TXP_TOKEN_SIZE_MAX;
mvpp2_write(port->priv, MVPP2_TXP_SCHED_TOKEN_SIZE_REG, val);
mvpp2_write(port->priv, MVPP2_RX_CTRL_REG(port->id),
MVPP2_RX_USE_PSEUDO_FOR_CSUM_MASK |
MVPP2_RX_LOW_LATENCY_PKT_SIZE(256));
for (lrxq = 0; lrxq < rxq_number; lrxq++) {
queue = port->rxqs[lrxq]->id;
val = mvpp2_read(port->priv, MVPP2_RXQ_CONFIG_REG(queue));
val |= MVPP2_SNOOP_PKT_SIZE_MASK |
MVPP2_SNOOP_BUF_HDR_MASK;
mvpp2_write(port->priv, MVPP2_RXQ_CONFIG_REG(queue), val);
}
mvpp2_interrupts_disable(port);
}
static void mvpp2_ingress_enable(struct mvpp2_port *port)
{
u32 val;
int lrxq, queue;
for (lrxq = 0; lrxq < rxq_number; lrxq++) {
queue = port->rxqs[lrxq]->id;
val = mvpp2_read(port->priv, MVPP2_RXQ_CONFIG_REG(queue));
val &= ~MVPP2_RXQ_DISABLE_MASK;
mvpp2_write(port->priv, MVPP2_RXQ_CONFIG_REG(queue), val);
}
}
static void mvpp2_ingress_disable(struct mvpp2_port *port)
{
u32 val;
int lrxq, queue;
for (lrxq = 0; lrxq < rxq_number; lrxq++) {
queue = port->rxqs[lrxq]->id;
val = mvpp2_read(port->priv, MVPP2_RXQ_CONFIG_REG(queue));
val |= MVPP2_RXQ_DISABLE_MASK;
mvpp2_write(port->priv, MVPP2_RXQ_CONFIG_REG(queue), val);
}
}
static void mvpp2_egress_enable(struct mvpp2_port *port)
{
u32 qmap;
int queue;
int tx_port_num = mvpp2_egress_port(port);
qmap = 0;
for (queue = 0; queue < txq_number; queue++) {
struct mvpp2_tx_queue *txq = port->txqs[queue];
if (txq->descs != NULL)
qmap |= (1 << queue);
}
mvpp2_write(port->priv, MVPP2_TXP_SCHED_PORT_INDEX_REG, tx_port_num);
mvpp2_write(port->priv, MVPP2_TXP_SCHED_Q_CMD_REG, qmap);
}
static void mvpp2_egress_disable(struct mvpp2_port *port)
{
u32 reg_data;
int delay;
int tx_port_num = mvpp2_egress_port(port);
mvpp2_write(port->priv, MVPP2_TXP_SCHED_PORT_INDEX_REG, tx_port_num);
reg_data = (mvpp2_read(port->priv, MVPP2_TXP_SCHED_Q_CMD_REG)) &
MVPP2_TXP_SCHED_ENQ_MASK;
if (reg_data != 0)
mvpp2_write(port->priv, MVPP2_TXP_SCHED_Q_CMD_REG,
(reg_data << MVPP2_TXP_SCHED_DISQ_OFFSET));
delay = 0;
do {
if (delay >= MVPP2_TX_DISABLE_TIMEOUT_MSEC) {
netdev_warn(port->dev,
"Tx stop timed out, status=0x%08x\n",
reg_data);
break;
}
mdelay(1);
delay++;
reg_data = mvpp2_read(port->priv, MVPP2_TXP_SCHED_Q_CMD_REG);
} while (reg_data & MVPP2_TXP_SCHED_ENQ_MASK);
}
static inline int
mvpp2_rxq_received(struct mvpp2_port *port, int rxq_id)
{
u32 val = mvpp2_read(port->priv, MVPP2_RXQ_STATUS_REG(rxq_id));
return val & MVPP2_RXQ_OCCUPIED_MASK;
}
static inline void
mvpp2_rxq_status_update(struct mvpp2_port *port, int rxq_id,
int used_count, int free_count)
{
u32 val = used_count | (free_count << MVPP2_RXQ_NUM_NEW_OFFSET);
mvpp2_write(port->priv, MVPP2_RXQ_STATUS_UPDATE_REG(rxq_id), val);
}
static inline struct mvpp2_rx_desc *
mvpp2_rxq_next_desc_get(struct mvpp2_rx_queue *rxq)
{
int rx_desc = rxq->next_desc_to_proc;
rxq->next_desc_to_proc = MVPP2_QUEUE_NEXT_DESC(rxq, rx_desc);
prefetch(rxq->descs + rxq->next_desc_to_proc);
return rxq->descs + rx_desc;
}
static void mvpp2_rxq_offset_set(struct mvpp2_port *port,
int prxq, int offset)
{
u32 val;
offset = offset >> 5;
val = mvpp2_read(port->priv, MVPP2_RXQ_CONFIG_REG(prxq));
val &= ~MVPP2_RXQ_PACKET_OFFSET_MASK;
val |= ((offset << MVPP2_RXQ_PACKET_OFFSET_OFFS) &
MVPP2_RXQ_PACKET_OFFSET_MASK);
mvpp2_write(port->priv, MVPP2_RXQ_CONFIG_REG(prxq), val);
}
static u32 mvpp2_bm_cookie_build(struct mvpp2_rx_desc *rx_desc)
{
int pool = (rx_desc->status & MVPP2_RXD_BM_POOL_ID_MASK) >>
MVPP2_RXD_BM_POOL_ID_OFFS;
int cpu = smp_processor_id();
return ((pool & 0xFF) << MVPP2_BM_COOKIE_POOL_OFFS) |
((cpu & 0xFF) << MVPP2_BM_COOKIE_CPU_OFFS);
}
static int mvpp2_txq_pend_desc_num_get(struct mvpp2_port *port,
struct mvpp2_tx_queue *txq)
{
u32 val;
mvpp2_write(port->priv, MVPP2_TXQ_NUM_REG, txq->id);
val = mvpp2_read(port->priv, MVPP2_TXQ_PENDING_REG);
return val & MVPP2_TXQ_PENDING_MASK;
}
static struct mvpp2_tx_desc *
mvpp2_txq_next_desc_get(struct mvpp2_tx_queue *txq)
{
int tx_desc = txq->next_desc_to_proc;
txq->next_desc_to_proc = MVPP2_QUEUE_NEXT_DESC(txq, tx_desc);
return txq->descs + tx_desc;
}
static void mvpp2_aggr_txq_pend_desc_add(struct mvpp2_port *port, int pending)
{
mvpp2_write(port->priv, MVPP2_AGGR_TXQ_UPDATE_REG, pending);
}
static int mvpp2_aggr_desc_num_check(struct mvpp2 *priv,
struct mvpp2_tx_queue *aggr_txq, int num)
{
if ((aggr_txq->count + num) > aggr_txq->size) {
int cpu = smp_processor_id();
u32 val = mvpp2_read(priv, MVPP2_AGGR_TXQ_STATUS_REG(cpu));
aggr_txq->count = val & MVPP2_AGGR_TXQ_PENDING_MASK;
}
if ((aggr_txq->count + num) > aggr_txq->size)
return -ENOMEM;
return 0;
}
static int mvpp2_txq_alloc_reserved_desc(struct mvpp2 *priv,
struct mvpp2_tx_queue *txq, int num)
{
u32 val;
val = (txq->id << MVPP2_TXQ_RSVD_REQ_Q_OFFSET) | num;
mvpp2_write(priv, MVPP2_TXQ_RSVD_REQ_REG, val);
val = mvpp2_read(priv, MVPP2_TXQ_RSVD_RSLT_REG);
return val & MVPP2_TXQ_RSVD_RSLT_MASK;
}
static int mvpp2_txq_reserved_desc_num_proc(struct mvpp2 *priv,
struct mvpp2_tx_queue *txq,
struct mvpp2_txq_pcpu *txq_pcpu,
int num)
{
int req, cpu, desc_count;
if (txq_pcpu->reserved_num >= num)
return 0;
desc_count = 0;
for_each_present_cpu(cpu) {
struct mvpp2_txq_pcpu *txq_pcpu_aux;
txq_pcpu_aux = per_cpu_ptr(txq->pcpu, cpu);
desc_count += txq_pcpu_aux->count;
desc_count += txq_pcpu_aux->reserved_num;
}
req = max(MVPP2_CPU_DESC_CHUNK, num - txq_pcpu->reserved_num);
desc_count += req;
if (desc_count >
(txq->size - (num_present_cpus() * MVPP2_CPU_DESC_CHUNK)))
return -ENOMEM;
txq_pcpu->reserved_num += mvpp2_txq_alloc_reserved_desc(priv, txq, req);
if (txq_pcpu->reserved_num < num)
return -ENOMEM;
return 0;
}
static void mvpp2_txq_desc_put(struct mvpp2_tx_queue *txq)
{
if (txq->next_desc_to_proc == 0)
txq->next_desc_to_proc = txq->last_desc - 1;
else
txq->next_desc_to_proc--;
}
static u32 mvpp2_txq_desc_csum(int l3_offs, int l3_proto,
int ip_hdr_len, int l4_proto)
{
u32 command;
command = (l3_offs << MVPP2_TXD_L3_OFF_SHIFT);
command |= (ip_hdr_len << MVPP2_TXD_IP_HLEN_SHIFT);
command |= MVPP2_TXD_IP_CSUM_DISABLE;
if (l3_proto == swab16(ETH_P_IP)) {
command &= ~MVPP2_TXD_IP_CSUM_DISABLE;
command &= ~MVPP2_TXD_L3_IP6;
} else {
command |= MVPP2_TXD_L3_IP6;
}
if (l4_proto == IPPROTO_TCP) {
command &= ~MVPP2_TXD_L4_UDP;
command &= ~MVPP2_TXD_L4_CSUM_FRAG;
} else if (l4_proto == IPPROTO_UDP) {
command |= MVPP2_TXD_L4_UDP;
command &= ~MVPP2_TXD_L4_CSUM_FRAG;
} else {
command |= MVPP2_TXD_L4_CSUM_NOT;
}
return command;
}
static inline int mvpp2_txq_sent_desc_proc(struct mvpp2_port *port,
struct mvpp2_tx_queue *txq)
{
u32 val;
val = mvpp2_read(port->priv, MVPP2_TXQ_SENT_REG(txq->id));
return (val & MVPP2_TRANSMITTED_COUNT_MASK) >>
MVPP2_TRANSMITTED_COUNT_OFFSET;
}
static void mvpp2_txq_sent_counter_clear(void *arg)
{
struct mvpp2_port *port = arg;
int queue;
for (queue = 0; queue < txq_number; queue++) {
int id = port->txqs[queue]->id;
mvpp2_read(port->priv, MVPP2_TXQ_SENT_REG(id));
}
}
static void mvpp2_txp_max_tx_size_set(struct mvpp2_port *port)
{
u32 val, size, mtu;
int txq, tx_port_num;
mtu = port->pkt_size * 8;
if (mtu > MVPP2_TXP_MTU_MAX)
mtu = MVPP2_TXP_MTU_MAX;
mtu = 3 * mtu;
tx_port_num = mvpp2_egress_port(port);
mvpp2_write(port->priv, MVPP2_TXP_SCHED_PORT_INDEX_REG, tx_port_num);
val = mvpp2_read(port->priv, MVPP2_TXP_SCHED_MTU_REG);
val &= ~MVPP2_TXP_MTU_MAX;
val |= mtu;
mvpp2_write(port->priv, MVPP2_TXP_SCHED_MTU_REG, val);
val = mvpp2_read(port->priv, MVPP2_TXP_SCHED_TOKEN_SIZE_REG);
size = val & MVPP2_TXP_TOKEN_SIZE_MAX;
if (size < mtu) {
size = mtu;
val &= ~MVPP2_TXP_TOKEN_SIZE_MAX;
val |= size;
mvpp2_write(port->priv, MVPP2_TXP_SCHED_TOKEN_SIZE_REG, val);
}
for (txq = 0; txq < txq_number; txq++) {
val = mvpp2_read(port->priv,
MVPP2_TXQ_SCHED_TOKEN_SIZE_REG(txq));
size = val & MVPP2_TXQ_TOKEN_SIZE_MAX;
if (size < mtu) {
size = mtu;
val &= ~MVPP2_TXQ_TOKEN_SIZE_MAX;
val |= size;
mvpp2_write(port->priv,
MVPP2_TXQ_SCHED_TOKEN_SIZE_REG(txq),
val);
}
}
}
static void mvpp2_rx_pkts_coal_set(struct mvpp2_port *port,
struct mvpp2_rx_queue *rxq, u32 pkts)
{
u32 val;
val = (pkts & MVPP2_OCCUPIED_THRESH_MASK);
mvpp2_write(port->priv, MVPP2_RXQ_NUM_REG, rxq->id);
mvpp2_write(port->priv, MVPP2_RXQ_THRESH_REG, val);
rxq->pkts_coal = pkts;
}
static void mvpp2_rx_time_coal_set(struct mvpp2_port *port,
struct mvpp2_rx_queue *rxq, u32 usec)
{
u32 val;
val = (port->priv->tclk / USEC_PER_SEC) * usec;
mvpp2_write(port->priv, MVPP2_ISR_RX_THRESHOLD_REG(rxq->id), val);
rxq->time_coal = usec;
}
static void mvpp2_txq_bufs_free(struct mvpp2_port *port,
struct mvpp2_tx_queue *txq,
struct mvpp2_txq_pcpu *txq_pcpu, int num)
{
int i;
for (i = 0; i < num; i++) {
dma_addr_t buf_phys_addr =
txq_pcpu->tx_buffs[txq_pcpu->txq_get_index];
struct sk_buff *skb = txq_pcpu->tx_skb[txq_pcpu->txq_get_index];
mvpp2_txq_inc_get(txq_pcpu);
dma_unmap_single(port->dev->dev.parent, buf_phys_addr,
skb_headlen(skb), DMA_TO_DEVICE);
if (!skb)
continue;
dev_kfree_skb_any(skb);
}
}
static inline struct mvpp2_rx_queue *mvpp2_get_rx_queue(struct mvpp2_port *port,
u32 cause)
{
int queue = fls(cause) - 1;
return port->rxqs[queue];
}
static inline struct mvpp2_tx_queue *mvpp2_get_tx_queue(struct mvpp2_port *port,
u32 cause)
{
int queue = fls(cause) - 1;
return port->txqs[queue];
}
static void mvpp2_txq_done(struct mvpp2_port *port, struct mvpp2_tx_queue *txq,
struct mvpp2_txq_pcpu *txq_pcpu)
{
struct netdev_queue *nq = netdev_get_tx_queue(port->dev, txq->log_id);
int tx_done;
if (txq_pcpu->cpu != smp_processor_id())
netdev_err(port->dev, "wrong cpu on the end of Tx processing\n");
tx_done = mvpp2_txq_sent_desc_proc(port, txq);
if (!tx_done)
return;
mvpp2_txq_bufs_free(port, txq, txq_pcpu, tx_done);
txq_pcpu->count -= tx_done;
if (netif_tx_queue_stopped(nq))
if (txq_pcpu->size - txq_pcpu->count >= MAX_SKB_FRAGS + 1)
netif_tx_wake_queue(nq);
}
static unsigned int mvpp2_tx_done(struct mvpp2_port *port, u32 cause)
{
struct mvpp2_tx_queue *txq;
struct mvpp2_txq_pcpu *txq_pcpu;
unsigned int tx_todo = 0;
while (cause) {
txq = mvpp2_get_tx_queue(port, cause);
if (!txq)
break;
txq_pcpu = this_cpu_ptr(txq->pcpu);
if (txq_pcpu->count) {
mvpp2_txq_done(port, txq, txq_pcpu);
tx_todo += txq_pcpu->count;
}
cause &= ~(1 << txq->log_id);
}
return tx_todo;
}
static int mvpp2_aggr_txq_init(struct platform_device *pdev,
struct mvpp2_tx_queue *aggr_txq,
int desc_num, int cpu,
struct mvpp2 *priv)
{
aggr_txq->descs = dma_alloc_coherent(&pdev->dev,
desc_num * MVPP2_DESC_ALIGNED_SIZE,
&aggr_txq->descs_phys, GFP_KERNEL);
if (!aggr_txq->descs)
return -ENOMEM;
BUG_ON(aggr_txq->descs !=
PTR_ALIGN(aggr_txq->descs, MVPP2_CPU_D_CACHE_LINE_SIZE));
aggr_txq->last_desc = aggr_txq->size - 1;
aggr_txq->next_desc_to_proc = mvpp2_read(priv,
MVPP2_AGGR_TXQ_INDEX_REG(cpu));
mvpp2_write(priv, MVPP2_AGGR_TXQ_DESC_ADDR_REG(cpu),
aggr_txq->descs_phys);
mvpp2_write(priv, MVPP2_AGGR_TXQ_DESC_SIZE_REG(cpu), desc_num);
return 0;
}
static int mvpp2_rxq_init(struct mvpp2_port *port,
struct mvpp2_rx_queue *rxq)
{
rxq->size = port->rx_ring_size;
rxq->descs = dma_alloc_coherent(port->dev->dev.parent,
rxq->size * MVPP2_DESC_ALIGNED_SIZE,
&rxq->descs_phys, GFP_KERNEL);
if (!rxq->descs)
return -ENOMEM;
BUG_ON(rxq->descs !=
PTR_ALIGN(rxq->descs, MVPP2_CPU_D_CACHE_LINE_SIZE));
rxq->last_desc = rxq->size - 1;
mvpp2_write(port->priv, MVPP2_RXQ_STATUS_REG(rxq->id), 0);
mvpp2_write(port->priv, MVPP2_RXQ_NUM_REG, rxq->id);
mvpp2_write(port->priv, MVPP2_RXQ_DESC_ADDR_REG, rxq->descs_phys);
mvpp2_write(port->priv, MVPP2_RXQ_DESC_SIZE_REG, rxq->size);
mvpp2_write(port->priv, MVPP2_RXQ_INDEX_REG, 0);
mvpp2_rxq_offset_set(port, rxq->id, NET_SKB_PAD);
mvpp2_rx_pkts_coal_set(port, rxq, rxq->pkts_coal);
mvpp2_rx_time_coal_set(port, rxq, rxq->time_coal);
mvpp2_rxq_status_update(port, rxq->id, 0, rxq->size);
return 0;
}
static void mvpp2_rxq_drop_pkts(struct mvpp2_port *port,
struct mvpp2_rx_queue *rxq)
{
int rx_received, i;
rx_received = mvpp2_rxq_received(port, rxq->id);
if (!rx_received)
return;
for (i = 0; i < rx_received; i++) {
struct mvpp2_rx_desc *rx_desc = mvpp2_rxq_next_desc_get(rxq);
u32 bm = mvpp2_bm_cookie_build(rx_desc);
mvpp2_pool_refill(port, bm, rx_desc->buf_phys_addr,
rx_desc->buf_cookie);
}
mvpp2_rxq_status_update(port, rxq->id, rx_received, rx_received);
}
static void mvpp2_rxq_deinit(struct mvpp2_port *port,
struct mvpp2_rx_queue *rxq)
{
mvpp2_rxq_drop_pkts(port, rxq);
if (rxq->descs)
dma_free_coherent(port->dev->dev.parent,
rxq->size * MVPP2_DESC_ALIGNED_SIZE,
rxq->descs,
rxq->descs_phys);
rxq->descs = NULL;
rxq->last_desc = 0;
rxq->next_desc_to_proc = 0;
rxq->descs_phys = 0;
mvpp2_write(port->priv, MVPP2_RXQ_STATUS_REG(rxq->id), 0);
mvpp2_write(port->priv, MVPP2_RXQ_NUM_REG, rxq->id);
mvpp2_write(port->priv, MVPP2_RXQ_DESC_ADDR_REG, 0);
mvpp2_write(port->priv, MVPP2_RXQ_DESC_SIZE_REG, 0);
}
static int mvpp2_txq_init(struct mvpp2_port *port,
struct mvpp2_tx_queue *txq)
{
u32 val;
int cpu, desc, desc_per_txq, tx_port_num;
struct mvpp2_txq_pcpu *txq_pcpu;
txq->size = port->tx_ring_size;
txq->descs = dma_alloc_coherent(port->dev->dev.parent,
txq->size * MVPP2_DESC_ALIGNED_SIZE,
&txq->descs_phys, GFP_KERNEL);
if (!txq->descs)
return -ENOMEM;
BUG_ON(txq->descs !=
PTR_ALIGN(txq->descs, MVPP2_CPU_D_CACHE_LINE_SIZE));
txq->last_desc = txq->size - 1;
mvpp2_write(port->priv, MVPP2_TXQ_NUM_REG, txq->id);
mvpp2_write(port->priv, MVPP2_TXQ_DESC_ADDR_REG, txq->descs_phys);
mvpp2_write(port->priv, MVPP2_TXQ_DESC_SIZE_REG, txq->size &
MVPP2_TXQ_DESC_SIZE_MASK);
mvpp2_write(port->priv, MVPP2_TXQ_INDEX_REG, 0);
mvpp2_write(port->priv, MVPP2_TXQ_RSVD_CLR_REG,
txq->id << MVPP2_TXQ_RSVD_CLR_OFFSET);
val = mvpp2_read(port->priv, MVPP2_TXQ_PENDING_REG);
val &= ~MVPP2_TXQ_PENDING_MASK;
mvpp2_write(port->priv, MVPP2_TXQ_PENDING_REG, val);
desc_per_txq = 16;
desc = (port->id * MVPP2_MAX_TXQ * desc_per_txq) +
(txq->log_id * desc_per_txq);
mvpp2_write(port->priv, MVPP2_TXQ_PREF_BUF_REG,
MVPP2_PREF_BUF_PTR(desc) | MVPP2_PREF_BUF_SIZE_16 |
MVPP2_PREF_BUF_THRESH(desc_per_txq/2));
tx_port_num = mvpp2_egress_port(port);
mvpp2_write(port->priv, MVPP2_TXP_SCHED_PORT_INDEX_REG, tx_port_num);
val = mvpp2_read(port->priv, MVPP2_TXQ_SCHED_REFILL_REG(txq->log_id));
val &= ~MVPP2_TXQ_REFILL_PERIOD_ALL_MASK;
val |= MVPP2_TXQ_REFILL_PERIOD_MASK(1);
val |= MVPP2_TXQ_REFILL_TOKENS_ALL_MASK;
mvpp2_write(port->priv, MVPP2_TXQ_SCHED_REFILL_REG(txq->log_id), val);
val = MVPP2_TXQ_TOKEN_SIZE_MAX;
mvpp2_write(port->priv, MVPP2_TXQ_SCHED_TOKEN_SIZE_REG(txq->log_id),
val);
for_each_present_cpu(cpu) {
txq_pcpu = per_cpu_ptr(txq->pcpu, cpu);
txq_pcpu->size = txq->size;
txq_pcpu->tx_skb = kmalloc(txq_pcpu->size *
sizeof(*txq_pcpu->tx_skb),
GFP_KERNEL);
if (!txq_pcpu->tx_skb)
goto error;
txq_pcpu->tx_buffs = kmalloc(txq_pcpu->size *
sizeof(dma_addr_t), GFP_KERNEL);
if (!txq_pcpu->tx_buffs)
goto error;
txq_pcpu->count = 0;
txq_pcpu->reserved_num = 0;
txq_pcpu->txq_put_index = 0;
txq_pcpu->txq_get_index = 0;
}
return 0;
error:
for_each_present_cpu(cpu) {
txq_pcpu = per_cpu_ptr(txq->pcpu, cpu);
kfree(txq_pcpu->tx_skb);
kfree(txq_pcpu->tx_buffs);
}
dma_free_coherent(port->dev->dev.parent,
txq->size * MVPP2_DESC_ALIGNED_SIZE,
txq->descs, txq->descs_phys);
return -ENOMEM;
}
static void mvpp2_txq_deinit(struct mvpp2_port *port,
struct mvpp2_tx_queue *txq)
{
struct mvpp2_txq_pcpu *txq_pcpu;
int cpu;
for_each_present_cpu(cpu) {
txq_pcpu = per_cpu_ptr(txq->pcpu, cpu);
kfree(txq_pcpu->tx_skb);
kfree(txq_pcpu->tx_buffs);
}
if (txq->descs)
dma_free_coherent(port->dev->dev.parent,
txq->size * MVPP2_DESC_ALIGNED_SIZE,
txq->descs, txq->descs_phys);
txq->descs = NULL;
txq->last_desc = 0;
txq->next_desc_to_proc = 0;
txq->descs_phys = 0;
mvpp2_write(port->priv, MVPP2_TXQ_SCHED_TOKEN_CNTR_REG(txq->id), 0);
mvpp2_write(port->priv, MVPP2_TXQ_NUM_REG, txq->id);
mvpp2_write(port->priv, MVPP2_TXQ_DESC_ADDR_REG, 0);
mvpp2_write(port->priv, MVPP2_TXQ_DESC_SIZE_REG, 0);
}
static void mvpp2_txq_clean(struct mvpp2_port *port, struct mvpp2_tx_queue *txq)
{
struct mvpp2_txq_pcpu *txq_pcpu;
int delay, pending, cpu;
u32 val;
mvpp2_write(port->priv, MVPP2_TXQ_NUM_REG, txq->id);
val = mvpp2_read(port->priv, MVPP2_TXQ_PREF_BUF_REG);
val |= MVPP2_TXQ_DRAIN_EN_MASK;
mvpp2_write(port->priv, MVPP2_TXQ_PREF_BUF_REG, val);
delay = 0;
do {
if (delay >= MVPP2_TX_PENDING_TIMEOUT_MSEC) {
netdev_warn(port->dev,
"port %d: cleaning queue %d timed out\n",
port->id, txq->log_id);
break;
}
mdelay(1);
delay++;
pending = mvpp2_txq_pend_desc_num_get(port, txq);
} while (pending);
val &= ~MVPP2_TXQ_DRAIN_EN_MASK;
mvpp2_write(port->priv, MVPP2_TXQ_PREF_BUF_REG, val);
for_each_present_cpu(cpu) {
txq_pcpu = per_cpu_ptr(txq->pcpu, cpu);
mvpp2_txq_bufs_free(port, txq, txq_pcpu, txq_pcpu->count);
txq_pcpu->count = 0;
txq_pcpu->txq_put_index = 0;
txq_pcpu->txq_get_index = 0;
}
}
static void mvpp2_cleanup_txqs(struct mvpp2_port *port)
{
struct mvpp2_tx_queue *txq;
int queue;
u32 val;
val = mvpp2_read(port->priv, MVPP2_TX_PORT_FLUSH_REG);
val |= MVPP2_TX_PORT_FLUSH_MASK(port->id);
mvpp2_write(port->priv, MVPP2_TX_PORT_FLUSH_REG, val);
for (queue = 0; queue < txq_number; queue++) {
txq = port->txqs[queue];
mvpp2_txq_clean(port, txq);
mvpp2_txq_deinit(port, txq);
}
on_each_cpu(mvpp2_txq_sent_counter_clear, port, 1);
val &= ~MVPP2_TX_PORT_FLUSH_MASK(port->id);
mvpp2_write(port->priv, MVPP2_TX_PORT_FLUSH_REG, val);
}
static void mvpp2_cleanup_rxqs(struct mvpp2_port *port)
{
int queue;
for (queue = 0; queue < rxq_number; queue++)
mvpp2_rxq_deinit(port, port->rxqs[queue]);
}
static int mvpp2_setup_rxqs(struct mvpp2_port *port)
{
int queue, err;
for (queue = 0; queue < rxq_number; queue++) {
err = mvpp2_rxq_init(port, port->rxqs[queue]);
if (err)
goto err_cleanup;
}
return 0;
err_cleanup:
mvpp2_cleanup_rxqs(port);
return err;
}
static int mvpp2_setup_txqs(struct mvpp2_port *port)
{
struct mvpp2_tx_queue *txq;
int queue, err;
for (queue = 0; queue < txq_number; queue++) {
txq = port->txqs[queue];
err = mvpp2_txq_init(port, txq);
if (err)
goto err_cleanup;
}
on_each_cpu(mvpp2_txq_sent_counter_clear, port, 1);
return 0;
err_cleanup:
mvpp2_cleanup_txqs(port);
return err;
}
static irqreturn_t mvpp2_isr(int irq, void *dev_id)
{
struct mvpp2_port *port = (struct mvpp2_port *)dev_id;
mvpp2_interrupts_disable(port);
napi_schedule(&port->napi);
return IRQ_HANDLED;
}
static void mvpp2_link_event(struct net_device *dev)
{
struct mvpp2_port *port = netdev_priv(dev);
struct phy_device *phydev = port->phy_dev;
int status_change = 0;
u32 val;
if (phydev->link) {
if ((port->speed != phydev->speed) ||
(port->duplex != phydev->duplex)) {
u32 val;
val = readl(port->base + MVPP2_GMAC_AUTONEG_CONFIG);
val &= ~(MVPP2_GMAC_CONFIG_MII_SPEED |
MVPP2_GMAC_CONFIG_GMII_SPEED |
MVPP2_GMAC_CONFIG_FULL_DUPLEX |
MVPP2_GMAC_AN_SPEED_EN |
MVPP2_GMAC_AN_DUPLEX_EN);
if (phydev->duplex)
val |= MVPP2_GMAC_CONFIG_FULL_DUPLEX;
if (phydev->speed == SPEED_1000)
val |= MVPP2_GMAC_CONFIG_GMII_SPEED;
else if (phydev->speed == SPEED_100)
val |= MVPP2_GMAC_CONFIG_MII_SPEED;
writel(val, port->base + MVPP2_GMAC_AUTONEG_CONFIG);
port->duplex = phydev->duplex;
port->speed = phydev->speed;
}
}
if (phydev->link != port->link) {
if (!phydev->link) {
port->duplex = -1;
port->speed = 0;
}
port->link = phydev->link;
status_change = 1;
}
if (status_change) {
if (phydev->link) {
val = readl(port->base + MVPP2_GMAC_AUTONEG_CONFIG);
val |= (MVPP2_GMAC_FORCE_LINK_PASS |
MVPP2_GMAC_FORCE_LINK_DOWN);
writel(val, port->base + MVPP2_GMAC_AUTONEG_CONFIG);
mvpp2_egress_enable(port);
mvpp2_ingress_enable(port);
} else {
mvpp2_ingress_disable(port);
mvpp2_egress_disable(port);
}
phy_print_status(phydev);
}
}
static void mvpp2_timer_set(struct mvpp2_port_pcpu *port_pcpu)
{
ktime_t interval;
if (!port_pcpu->timer_scheduled) {
port_pcpu->timer_scheduled = true;
interval = ktime_set(0, MVPP2_TXDONE_HRTIMER_PERIOD_NS);
hrtimer_start(&port_pcpu->tx_done_timer, interval,
HRTIMER_MODE_REL_PINNED);
}
}
static void mvpp2_tx_proc_cb(unsigned long data)
{
struct net_device *dev = (struct net_device *)data;
struct mvpp2_port *port = netdev_priv(dev);
struct mvpp2_port_pcpu *port_pcpu = this_cpu_ptr(port->pcpu);
unsigned int tx_todo, cause;
if (!netif_running(dev))
return;
port_pcpu->timer_scheduled = false;
cause = (1 << txq_number) - 1;
tx_todo = mvpp2_tx_done(port, cause);
if (tx_todo)
mvpp2_timer_set(port_pcpu);
}
static enum hrtimer_restart mvpp2_hr_timer_cb(struct hrtimer *timer)
{
struct mvpp2_port_pcpu *port_pcpu = container_of(timer,
struct mvpp2_port_pcpu,
tx_done_timer);
tasklet_schedule(&port_pcpu->tx_done_tasklet);
return HRTIMER_NORESTART;
}
static void mvpp2_rx_error(struct mvpp2_port *port,
struct mvpp2_rx_desc *rx_desc)
{
u32 status = rx_desc->status;
switch (status & MVPP2_RXD_ERR_CODE_MASK) {
case MVPP2_RXD_ERR_CRC:
netdev_err(port->dev, "bad rx status %08x (crc error), size=%d\n",
status, rx_desc->data_size);
break;
case MVPP2_RXD_ERR_OVERRUN:
netdev_err(port->dev, "bad rx status %08x (overrun error), size=%d\n",
status, rx_desc->data_size);
break;
case MVPP2_RXD_ERR_RESOURCE:
netdev_err(port->dev, "bad rx status %08x (resource error), size=%d\n",
status, rx_desc->data_size);
break;
}
}
static void mvpp2_rx_csum(struct mvpp2_port *port, u32 status,
struct sk_buff *skb)
{
if (((status & MVPP2_RXD_L3_IP4) &&
!(status & MVPP2_RXD_IP4_HEADER_ERR)) ||
(status & MVPP2_RXD_L3_IP6))
if (((status & MVPP2_RXD_L4_UDP) ||
(status & MVPP2_RXD_L4_TCP)) &&
(status & MVPP2_RXD_L4_CSUM_OK)) {
skb->csum = 0;
skb->ip_summed = CHECKSUM_UNNECESSARY;
return;
}
skb->ip_summed = CHECKSUM_NONE;
}
static int mvpp2_rx_refill(struct mvpp2_port *port,
struct mvpp2_bm_pool *bm_pool,
u32 bm, int is_recycle)
{
struct sk_buff *skb;
dma_addr_t phys_addr;
if (is_recycle &&
(atomic_read(&bm_pool->in_use) < bm_pool->in_use_thresh))
return 0;
skb = mvpp2_skb_alloc(port, bm_pool, &phys_addr, GFP_ATOMIC);
if (!skb)
return -ENOMEM;
mvpp2_pool_refill(port, bm, (u32)phys_addr, (u32)skb);
atomic_dec(&bm_pool->in_use);
return 0;
}
static u32 mvpp2_skb_tx_csum(struct mvpp2_port *port, struct sk_buff *skb)
{
if (skb->ip_summed == CHECKSUM_PARTIAL) {
int ip_hdr_len = 0;
u8 l4_proto;
if (skb->protocol == htons(ETH_P_IP)) {
struct iphdr *ip4h = ip_hdr(skb);
ip_hdr_len = ip4h->ihl;
l4_proto = ip4h->protocol;
} else if (skb->protocol == htons(ETH_P_IPV6)) {
struct ipv6hdr *ip6h = ipv6_hdr(skb);
if (skb_network_header_len(skb) > 0)
ip_hdr_len = (skb_network_header_len(skb) >> 2);
l4_proto = ip6h->nexthdr;
} else {
return MVPP2_TXD_L4_CSUM_NOT;
}
return mvpp2_txq_desc_csum(skb_network_offset(skb),
skb->protocol, ip_hdr_len, l4_proto);
}
return MVPP2_TXD_L4_CSUM_NOT | MVPP2_TXD_IP_CSUM_DISABLE;
}
static void mvpp2_buff_hdr_rx(struct mvpp2_port *port,
struct mvpp2_rx_desc *rx_desc)
{
struct mvpp2_buff_hdr *buff_hdr;
struct sk_buff *skb;
u32 rx_status = rx_desc->status;
u32 buff_phys_addr;
u32 buff_virt_addr;
u32 buff_phys_addr_next;
u32 buff_virt_addr_next;
int mc_id;
int pool_id;
pool_id = (rx_status & MVPP2_RXD_BM_POOL_ID_MASK) >>
MVPP2_RXD_BM_POOL_ID_OFFS;
buff_phys_addr = rx_desc->buf_phys_addr;
buff_virt_addr = rx_desc->buf_cookie;
do {
skb = (struct sk_buff *)buff_virt_addr;
buff_hdr = (struct mvpp2_buff_hdr *)skb->head;
mc_id = MVPP2_B_HDR_INFO_MC_ID(buff_hdr->info);
buff_phys_addr_next = buff_hdr->next_buff_phys_addr;
buff_virt_addr_next = buff_hdr->next_buff_virt_addr;
mvpp2_bm_pool_mc_put(port, pool_id, buff_phys_addr,
buff_virt_addr, mc_id);
buff_phys_addr = buff_phys_addr_next;
buff_virt_addr = buff_virt_addr_next;
} while (!MVPP2_B_HDR_INFO_IS_LAST(buff_hdr->info));
}
static int mvpp2_rx(struct mvpp2_port *port, int rx_todo,
struct mvpp2_rx_queue *rxq)
{
struct net_device *dev = port->dev;
int rx_received;
int rx_done = 0;
u32 rcvd_pkts = 0;
u32 rcvd_bytes = 0;
rx_received = mvpp2_rxq_received(port, rxq->id);
if (rx_todo > rx_received)
rx_todo = rx_received;
while (rx_done < rx_todo) {
struct mvpp2_rx_desc *rx_desc = mvpp2_rxq_next_desc_get(rxq);
struct mvpp2_bm_pool *bm_pool;
struct sk_buff *skb;
dma_addr_t phys_addr;
u32 bm, rx_status;
int pool, rx_bytes, err;
rx_done++;
rx_status = rx_desc->status;
rx_bytes = rx_desc->data_size - MVPP2_MH_SIZE;
phys_addr = rx_desc->buf_phys_addr;
bm = mvpp2_bm_cookie_build(rx_desc);
pool = mvpp2_bm_cookie_pool_get(bm);
bm_pool = &port->priv->bm_pools[pool];
if (rx_status & MVPP2_RXD_BUF_HDR) {
mvpp2_buff_hdr_rx(port, rx_desc);
continue;
}
if (rx_status & MVPP2_RXD_ERR_SUMMARY) {
err_drop_frame:
dev->stats.rx_errors++;
mvpp2_rx_error(port, rx_desc);
mvpp2_pool_refill(port, bm, rx_desc->buf_phys_addr,
rx_desc->buf_cookie);
continue;
}
skb = (struct sk_buff *)rx_desc->buf_cookie;
err = mvpp2_rx_refill(port, bm_pool, bm, 0);
if (err) {
netdev_err(port->dev, "failed to refill BM pools\n");
goto err_drop_frame;
}
dma_unmap_single(dev->dev.parent, phys_addr,
bm_pool->buf_size, DMA_FROM_DEVICE);
rcvd_pkts++;
rcvd_bytes += rx_bytes;
atomic_inc(&bm_pool->in_use);
skb_reserve(skb, MVPP2_MH_SIZE);
skb_put(skb, rx_bytes);
skb->protocol = eth_type_trans(skb, dev);
mvpp2_rx_csum(port, rx_status, skb);
napi_gro_receive(&port->napi, skb);
}
if (rcvd_pkts) {
struct mvpp2_pcpu_stats *stats = this_cpu_ptr(port->stats);
u64_stats_update_begin(&stats->syncp);
stats->rx_packets += rcvd_pkts;
stats->rx_bytes += rcvd_bytes;
u64_stats_update_end(&stats->syncp);
}
wmb();
mvpp2_rxq_status_update(port, rxq->id, rx_done, rx_done);
return rx_todo;
}
static inline void
tx_desc_unmap_put(struct device *dev, struct mvpp2_tx_queue *txq,
struct mvpp2_tx_desc *desc)
{
dma_unmap_single(dev, desc->buf_phys_addr,
desc->data_size, DMA_TO_DEVICE);
mvpp2_txq_desc_put(txq);
}
static int mvpp2_tx_frag_process(struct mvpp2_port *port, struct sk_buff *skb,
struct mvpp2_tx_queue *aggr_txq,
struct mvpp2_tx_queue *txq)
{
struct mvpp2_txq_pcpu *txq_pcpu = this_cpu_ptr(txq->pcpu);
struct mvpp2_tx_desc *tx_desc;
int i;
dma_addr_t buf_phys_addr;
for (i = 0; i < skb_shinfo(skb)->nr_frags; i++) {
skb_frag_t *frag = &skb_shinfo(skb)->frags[i];
void *addr = page_address(frag->page.p) + frag->page_offset;
tx_desc = mvpp2_txq_next_desc_get(aggr_txq);
tx_desc->phys_txq = txq->id;
tx_desc->data_size = frag->size;
buf_phys_addr = dma_map_single(port->dev->dev.parent, addr,
tx_desc->data_size,
DMA_TO_DEVICE);
if (dma_mapping_error(port->dev->dev.parent, buf_phys_addr)) {
mvpp2_txq_desc_put(txq);
goto error;
}
tx_desc->packet_offset = buf_phys_addr & MVPP2_TX_DESC_ALIGN;
tx_desc->buf_phys_addr = buf_phys_addr & (~MVPP2_TX_DESC_ALIGN);
if (i == (skb_shinfo(skb)->nr_frags - 1)) {
tx_desc->command = MVPP2_TXD_L_DESC;
mvpp2_txq_inc_put(txq_pcpu, skb, tx_desc);
} else {
tx_desc->command = 0;
mvpp2_txq_inc_put(txq_pcpu, NULL, tx_desc);
}
}
return 0;
error:
for (i = i - 1; i >= 0; i--) {
tx_desc = txq->descs + i;
tx_desc_unmap_put(port->dev->dev.parent, txq, tx_desc);
}
return -ENOMEM;
}
static int mvpp2_tx(struct sk_buff *skb, struct net_device *dev)
{
struct mvpp2_port *port = netdev_priv(dev);
struct mvpp2_tx_queue *txq, *aggr_txq;
struct mvpp2_txq_pcpu *txq_pcpu;
struct mvpp2_tx_desc *tx_desc;
dma_addr_t buf_phys_addr;
int frags = 0;
u16 txq_id;
u32 tx_cmd;
txq_id = skb_get_queue_mapping(skb);
txq = port->txqs[txq_id];
txq_pcpu = this_cpu_ptr(txq->pcpu);
aggr_txq = &port->priv->aggr_txqs[smp_processor_id()];
frags = skb_shinfo(skb)->nr_frags + 1;
if (mvpp2_aggr_desc_num_check(port->priv, aggr_txq, frags) ||
mvpp2_txq_reserved_desc_num_proc(port->priv, txq,
txq_pcpu, frags)) {
frags = 0;
goto out;
}
tx_desc = mvpp2_txq_next_desc_get(aggr_txq);
tx_desc->phys_txq = txq->id;
tx_desc->data_size = skb_headlen(skb);
buf_phys_addr = dma_map_single(dev->dev.parent, skb->data,
tx_desc->data_size, DMA_TO_DEVICE);
if (unlikely(dma_mapping_error(dev->dev.parent, buf_phys_addr))) {
mvpp2_txq_desc_put(txq);
frags = 0;
goto out;
}
tx_desc->packet_offset = buf_phys_addr & MVPP2_TX_DESC_ALIGN;
tx_desc->buf_phys_addr = buf_phys_addr & ~MVPP2_TX_DESC_ALIGN;
tx_cmd = mvpp2_skb_tx_csum(port, skb);
if (frags == 1) {
tx_cmd |= MVPP2_TXD_F_DESC | MVPP2_TXD_L_DESC;
tx_desc->command = tx_cmd;
mvpp2_txq_inc_put(txq_pcpu, skb, tx_desc);
} else {
tx_cmd |= MVPP2_TXD_F_DESC | MVPP2_TXD_PADDING_DISABLE;
tx_desc->command = tx_cmd;
mvpp2_txq_inc_put(txq_pcpu, NULL, tx_desc);
if (mvpp2_tx_frag_process(port, skb, aggr_txq, txq)) {
tx_desc_unmap_put(port->dev->dev.parent, txq, tx_desc);
frags = 0;
goto out;
}
}
txq_pcpu->reserved_num -= frags;
txq_pcpu->count += frags;
aggr_txq->count += frags;
wmb();
mvpp2_aggr_txq_pend_desc_add(port, frags);
if (txq_pcpu->size - txq_pcpu->count < MAX_SKB_FRAGS + 1) {
struct netdev_queue *nq = netdev_get_tx_queue(dev, txq_id);
netif_tx_stop_queue(nq);
}
out:
if (frags > 0) {
struct mvpp2_pcpu_stats *stats = this_cpu_ptr(port->stats);
u64_stats_update_begin(&stats->syncp);
stats->tx_packets++;
stats->tx_bytes += skb->len;
u64_stats_update_end(&stats->syncp);
} else {
dev->stats.tx_dropped++;
dev_kfree_skb_any(skb);
}
if (txq_pcpu->count >= txq->done_pkts_coal)
mvpp2_txq_done(port, txq, txq_pcpu);
if (txq_pcpu->count <= frags && txq_pcpu->count > 0) {
struct mvpp2_port_pcpu *port_pcpu = this_cpu_ptr(port->pcpu);
mvpp2_timer_set(port_pcpu);
}
return NETDEV_TX_OK;
}
static inline void mvpp2_cause_error(struct net_device *dev, int cause)
{
if (cause & MVPP2_CAUSE_FCS_ERR_MASK)
netdev_err(dev, "FCS error\n");
if (cause & MVPP2_CAUSE_RX_FIFO_OVERRUN_MASK)
netdev_err(dev, "rx fifo overrun error\n");
if (cause & MVPP2_CAUSE_TX_FIFO_UNDERRUN_MASK)
netdev_err(dev, "tx fifo underrun error\n");
}
static int mvpp2_poll(struct napi_struct *napi, int budget)
{
u32 cause_rx_tx, cause_rx, cause_misc;
int rx_done = 0;
struct mvpp2_port *port = netdev_priv(napi->dev);
cause_rx_tx = mvpp2_read(port->priv,
MVPP2_ISR_RX_TX_CAUSE_REG(port->id));
cause_rx_tx &= ~MVPP2_CAUSE_TXQ_OCCUP_DESC_ALL_MASK;
cause_misc = cause_rx_tx & MVPP2_CAUSE_MISC_SUM_MASK;
if (cause_misc) {
mvpp2_cause_error(port->dev, cause_misc);
mvpp2_write(port->priv, MVPP2_ISR_MISC_CAUSE_REG, 0);
mvpp2_write(port->priv, MVPP2_ISR_RX_TX_CAUSE_REG(port->id),
cause_rx_tx & ~MVPP2_CAUSE_MISC_SUM_MASK);
}
cause_rx = cause_rx_tx & MVPP2_CAUSE_RXQ_OCCUP_DESC_ALL_MASK;
cause_rx |= port->pending_cause_rx;
while (cause_rx && budget > 0) {
int count;
struct mvpp2_rx_queue *rxq;
rxq = mvpp2_get_rx_queue(port, cause_rx);
if (!rxq)
break;
count = mvpp2_rx(port, budget, rxq);
rx_done += count;
budget -= count;
if (budget > 0) {
cause_rx &= ~(1 << rxq->logic_rxq);
}
}
if (budget > 0) {
cause_rx = 0;
napi_complete(napi);
mvpp2_interrupts_enable(port);
}
port->pending_cause_rx = cause_rx;
return rx_done;
}
static void mvpp2_start_dev(struct mvpp2_port *port)
{
mvpp2_gmac_max_rx_size_set(port);
mvpp2_txp_max_tx_size_set(port);
napi_enable(&port->napi);
mvpp2_interrupts_enable(port);
mvpp2_port_enable(port);
phy_start(port->phy_dev);
netif_tx_start_all_queues(port->dev);
}
static void mvpp2_stop_dev(struct mvpp2_port *port)
{
mvpp2_ingress_disable(port);
mdelay(10);
mvpp2_interrupts_disable(port);
napi_disable(&port->napi);
netif_carrier_off(port->dev);
netif_tx_stop_all_queues(port->dev);
mvpp2_egress_disable(port);
mvpp2_port_disable(port);
phy_stop(port->phy_dev);
}
static inline int mvpp2_check_mtu_valid(struct net_device *dev, int mtu)
{
if (mtu < 68) {
netdev_err(dev, "cannot change mtu to less than 68\n");
return -EINVAL;
}
if (mtu > 9676) {
netdev_info(dev, "illegal MTU value %d, round to 9676\n", mtu);
mtu = 9676;
}
if (!IS_ALIGNED(MVPP2_RX_PKT_SIZE(mtu), 8)) {
netdev_info(dev, "illegal MTU value %d, round to %d\n", mtu,
ALIGN(MVPP2_RX_PKT_SIZE(mtu), 8));
mtu = ALIGN(MVPP2_RX_PKT_SIZE(mtu), 8);
}
return mtu;
}
static int mvpp2_check_ringparam_valid(struct net_device *dev,
struct ethtool_ringparam *ring)
{
u16 new_rx_pending = ring->rx_pending;
u16 new_tx_pending = ring->tx_pending;
if (ring->rx_pending == 0 || ring->tx_pending == 0)
return -EINVAL;
if (ring->rx_pending > MVPP2_MAX_RXD)
new_rx_pending = MVPP2_MAX_RXD;
else if (!IS_ALIGNED(ring->rx_pending, 16))
new_rx_pending = ALIGN(ring->rx_pending, 16);
if (ring->tx_pending > MVPP2_MAX_TXD)
new_tx_pending = MVPP2_MAX_TXD;
else if (!IS_ALIGNED(ring->tx_pending, 32))
new_tx_pending = ALIGN(ring->tx_pending, 32);
if (ring->rx_pending != new_rx_pending) {
netdev_info(dev, "illegal Rx ring size value %d, round to %d\n",
ring->rx_pending, new_rx_pending);
ring->rx_pending = new_rx_pending;
}
if (ring->tx_pending != new_tx_pending) {
netdev_info(dev, "illegal Tx ring size value %d, round to %d\n",
ring->tx_pending, new_tx_pending);
ring->tx_pending = new_tx_pending;
}
return 0;
}
static void mvpp2_get_mac_address(struct mvpp2_port *port, unsigned char *addr)
{
u32 mac_addr_l, mac_addr_m, mac_addr_h;
mac_addr_l = readl(port->base + MVPP2_GMAC_CTRL_1_REG);
mac_addr_m = readl(port->priv->lms_base + MVPP2_SRC_ADDR_MIDDLE);
mac_addr_h = readl(port->priv->lms_base + MVPP2_SRC_ADDR_HIGH);
addr[0] = (mac_addr_h >> 24) & 0xFF;
addr[1] = (mac_addr_h >> 16) & 0xFF;
addr[2] = (mac_addr_h >> 8) & 0xFF;
addr[3] = mac_addr_h & 0xFF;
addr[4] = mac_addr_m & 0xFF;
addr[5] = (mac_addr_l >> MVPP2_GMAC_SA_LOW_OFFS) & 0xFF;
}
static int mvpp2_phy_connect(struct mvpp2_port *port)
{
struct phy_device *phy_dev;
phy_dev = of_phy_connect(port->dev, port->phy_node, mvpp2_link_event, 0,
port->phy_interface);
if (!phy_dev) {
netdev_err(port->dev, "cannot connect to phy\n");
return -ENODEV;
}
phy_dev->supported &= PHY_GBIT_FEATURES;
phy_dev->advertising = phy_dev->supported;
port->phy_dev = phy_dev;
port->link = 0;
port->duplex = 0;
port->speed = 0;
return 0;
}
static void mvpp2_phy_disconnect(struct mvpp2_port *port)
{
phy_disconnect(port->phy_dev);
port->phy_dev = NULL;
}
static int mvpp2_open(struct net_device *dev)
{
struct mvpp2_port *port = netdev_priv(dev);
unsigned char mac_bcast[ETH_ALEN] = {
0xff, 0xff, 0xff, 0xff, 0xff, 0xff };
int err;
err = mvpp2_prs_mac_da_accept(port->priv, port->id, mac_bcast, true);
if (err) {
netdev_err(dev, "mvpp2_prs_mac_da_accept BC failed\n");
return err;
}
err = mvpp2_prs_mac_da_accept(port->priv, port->id,
dev->dev_addr, true);
if (err) {
netdev_err(dev, "mvpp2_prs_mac_da_accept MC failed\n");
return err;
}
err = mvpp2_prs_tag_mode_set(port->priv, port->id, MVPP2_TAG_TYPE_MH);
if (err) {
netdev_err(dev, "mvpp2_prs_tag_mode_set failed\n");
return err;
}
err = mvpp2_prs_def_flow(port);
if (err) {
netdev_err(dev, "mvpp2_prs_def_flow failed\n");
return err;
}
err = mvpp2_setup_rxqs(port);
if (err) {
netdev_err(port->dev, "cannot allocate Rx queues\n");
return err;
}
err = mvpp2_setup_txqs(port);
if (err) {
netdev_err(port->dev, "cannot allocate Tx queues\n");
goto err_cleanup_rxqs;
}
err = request_irq(port->irq, mvpp2_isr, 0, dev->name, port);
if (err) {
netdev_err(port->dev, "cannot request IRQ %d\n", port->irq);
goto err_cleanup_txqs;
}
netif_carrier_off(port->dev);
err = mvpp2_phy_connect(port);
if (err < 0)
goto err_free_irq;
on_each_cpu(mvpp2_interrupts_unmask, port, 1);
mvpp2_start_dev(port);
return 0;
err_free_irq:
free_irq(port->irq, port);
err_cleanup_txqs:
mvpp2_cleanup_txqs(port);
err_cleanup_rxqs:
mvpp2_cleanup_rxqs(port);
return err;
}
static int mvpp2_stop(struct net_device *dev)
{
struct mvpp2_port *port = netdev_priv(dev);
struct mvpp2_port_pcpu *port_pcpu;
int cpu;
mvpp2_stop_dev(port);
mvpp2_phy_disconnect(port);
on_each_cpu(mvpp2_interrupts_mask, port, 1);
free_irq(port->irq, port);
for_each_present_cpu(cpu) {
port_pcpu = per_cpu_ptr(port->pcpu, cpu);
hrtimer_cancel(&port_pcpu->tx_done_timer);
port_pcpu->timer_scheduled = false;
tasklet_kill(&port_pcpu->tx_done_tasklet);
}
mvpp2_cleanup_rxqs(port);
mvpp2_cleanup_txqs(port);
return 0;
}
static void mvpp2_set_rx_mode(struct net_device *dev)
{
struct mvpp2_port *port = netdev_priv(dev);
struct mvpp2 *priv = port->priv;
struct netdev_hw_addr *ha;
int id = port->id;
bool allmulti = dev->flags & IFF_ALLMULTI;
mvpp2_prs_mac_promisc_set(priv, id, dev->flags & IFF_PROMISC);
mvpp2_prs_mac_multi_set(priv, id, MVPP2_PE_MAC_MC_ALL, allmulti);
mvpp2_prs_mac_multi_set(priv, id, MVPP2_PE_MAC_MC_IP6, allmulti);
mvpp2_prs_mcast_del_all(priv, id);
if (allmulti && !netdev_mc_empty(dev)) {
netdev_for_each_mc_addr(ha, dev)
mvpp2_prs_mac_da_accept(priv, id, ha->addr, true);
}
}
static int mvpp2_set_mac_address(struct net_device *dev, void *p)
{
struct mvpp2_port *port = netdev_priv(dev);
const struct sockaddr *addr = p;
int err;
if (!is_valid_ether_addr(addr->sa_data)) {
err = -EADDRNOTAVAIL;
goto error;
}
if (!netif_running(dev)) {
err = mvpp2_prs_update_mac_da(dev, addr->sa_data);
if (!err)
return 0;
err = mvpp2_prs_update_mac_da(dev, dev->dev_addr);
if (err)
goto error;
}
mvpp2_stop_dev(port);
err = mvpp2_prs_update_mac_da(dev, addr->sa_data);
if (!err)
goto out_start;
err = mvpp2_prs_update_mac_da(dev, dev->dev_addr);
if (err)
goto error;
out_start:
mvpp2_start_dev(port);
mvpp2_egress_enable(port);
mvpp2_ingress_enable(port);
return 0;
error:
netdev_err(dev, "fail to change MAC address\n");
return err;
}
static int mvpp2_change_mtu(struct net_device *dev, int mtu)
{
struct mvpp2_port *port = netdev_priv(dev);
int err;
mtu = mvpp2_check_mtu_valid(dev, mtu);
if (mtu < 0) {
err = mtu;
goto error;
}
if (!netif_running(dev)) {
err = mvpp2_bm_update_mtu(dev, mtu);
if (!err) {
port->pkt_size = MVPP2_RX_PKT_SIZE(mtu);
return 0;
}
err = mvpp2_bm_update_mtu(dev, dev->mtu);
if (err)
goto error;
}
mvpp2_stop_dev(port);
err = mvpp2_bm_update_mtu(dev, mtu);
if (!err) {
port->pkt_size = MVPP2_RX_PKT_SIZE(mtu);
goto out_start;
}
err = mvpp2_bm_update_mtu(dev, dev->mtu);
if (err)
goto error;
out_start:
mvpp2_start_dev(port);
mvpp2_egress_enable(port);
mvpp2_ingress_enable(port);
return 0;
error:
netdev_err(dev, "fail to change MTU\n");
return err;
}
static struct rtnl_link_stats64 *
mvpp2_get_stats64(struct net_device *dev, struct rtnl_link_stats64 *stats)
{
struct mvpp2_port *port = netdev_priv(dev);
unsigned int start;
int cpu;
for_each_possible_cpu(cpu) {
struct mvpp2_pcpu_stats *cpu_stats;
u64 rx_packets;
u64 rx_bytes;
u64 tx_packets;
u64 tx_bytes;
cpu_stats = per_cpu_ptr(port->stats, cpu);
do {
start = u64_stats_fetch_begin_irq(&cpu_stats->syncp);
rx_packets = cpu_stats->rx_packets;
rx_bytes = cpu_stats->rx_bytes;
tx_packets = cpu_stats->tx_packets;
tx_bytes = cpu_stats->tx_bytes;
} while (u64_stats_fetch_retry_irq(&cpu_stats->syncp, start));
stats->rx_packets += rx_packets;
stats->rx_bytes += rx_bytes;
stats->tx_packets += tx_packets;
stats->tx_bytes += tx_bytes;
}
stats->rx_errors = dev->stats.rx_errors;
stats->rx_dropped = dev->stats.rx_dropped;
stats->tx_dropped = dev->stats.tx_dropped;
return stats;
}
static int mvpp2_ioctl(struct net_device *dev, struct ifreq *ifr, int cmd)
{
struct mvpp2_port *port = netdev_priv(dev);
int ret;
if (!port->phy_dev)
return -ENOTSUPP;
ret = phy_mii_ioctl(port->phy_dev, ifr, cmd);
if (!ret)
mvpp2_link_event(dev);
return ret;
}
static int mvpp2_ethtool_get_settings(struct net_device *dev,
struct ethtool_cmd *cmd)
{
struct mvpp2_port *port = netdev_priv(dev);
if (!port->phy_dev)
return -ENODEV;
return phy_ethtool_gset(port->phy_dev, cmd);
}
static int mvpp2_ethtool_set_settings(struct net_device *dev,
struct ethtool_cmd *cmd)
{
struct mvpp2_port *port = netdev_priv(dev);
if (!port->phy_dev)
return -ENODEV;
return phy_ethtool_sset(port->phy_dev, cmd);
}
static int mvpp2_ethtool_set_coalesce(struct net_device *dev,
struct ethtool_coalesce *c)
{
struct mvpp2_port *port = netdev_priv(dev);
int queue;
for (queue = 0; queue < rxq_number; queue++) {
struct mvpp2_rx_queue *rxq = port->rxqs[queue];
rxq->time_coal = c->rx_coalesce_usecs;
rxq->pkts_coal = c->rx_max_coalesced_frames;
mvpp2_rx_pkts_coal_set(port, rxq, rxq->pkts_coal);
mvpp2_rx_time_coal_set(port, rxq, rxq->time_coal);
}
for (queue = 0; queue < txq_number; queue++) {
struct mvpp2_tx_queue *txq = port->txqs[queue];
txq->done_pkts_coal = c->tx_max_coalesced_frames;
}
return 0;
}
static int mvpp2_ethtool_get_coalesce(struct net_device *dev,
struct ethtool_coalesce *c)
{
struct mvpp2_port *port = netdev_priv(dev);
c->rx_coalesce_usecs = port->rxqs[0]->time_coal;
c->rx_max_coalesced_frames = port->rxqs[0]->pkts_coal;
c->tx_max_coalesced_frames = port->txqs[0]->done_pkts_coal;
return 0;
}
static void mvpp2_ethtool_get_drvinfo(struct net_device *dev,
struct ethtool_drvinfo *drvinfo)
{
strlcpy(drvinfo->driver, MVPP2_DRIVER_NAME,
sizeof(drvinfo->driver));
strlcpy(drvinfo->version, MVPP2_DRIVER_VERSION,
sizeof(drvinfo->version));
strlcpy(drvinfo->bus_info, dev_name(&dev->dev),
sizeof(drvinfo->bus_info));
}
static void mvpp2_ethtool_get_ringparam(struct net_device *dev,
struct ethtool_ringparam *ring)
{
struct mvpp2_port *port = netdev_priv(dev);
ring->rx_max_pending = MVPP2_MAX_RXD;
ring->tx_max_pending = MVPP2_MAX_TXD;
ring->rx_pending = port->rx_ring_size;
ring->tx_pending = port->tx_ring_size;
}
static int mvpp2_ethtool_set_ringparam(struct net_device *dev,
struct ethtool_ringparam *ring)
{
struct mvpp2_port *port = netdev_priv(dev);
u16 prev_rx_ring_size = port->rx_ring_size;
u16 prev_tx_ring_size = port->tx_ring_size;
int err;
err = mvpp2_check_ringparam_valid(dev, ring);
if (err)
return err;
if (!netif_running(dev)) {
port->rx_ring_size = ring->rx_pending;
port->tx_ring_size = ring->tx_pending;
return 0;
}
mvpp2_stop_dev(port);
mvpp2_cleanup_rxqs(port);
mvpp2_cleanup_txqs(port);
port->rx_ring_size = ring->rx_pending;
port->tx_ring_size = ring->tx_pending;
err = mvpp2_setup_rxqs(port);
if (err) {
port->rx_ring_size = prev_rx_ring_size;
ring->rx_pending = prev_rx_ring_size;
err = mvpp2_setup_rxqs(port);
if (err)
goto err_out;
}
err = mvpp2_setup_txqs(port);
if (err) {
port->tx_ring_size = prev_tx_ring_size;
ring->tx_pending = prev_tx_ring_size;
err = mvpp2_setup_txqs(port);
if (err)
goto err_clean_rxqs;
}
mvpp2_start_dev(port);
mvpp2_egress_enable(port);
mvpp2_ingress_enable(port);
return 0;
err_clean_rxqs:
mvpp2_cleanup_rxqs(port);
err_out:
netdev_err(dev, "fail to change ring parameters");
return err;
}
static void mvpp2_port_power_up(struct mvpp2_port *port)
{
mvpp2_port_mii_set(port);
mvpp2_port_periodic_xon_disable(port);
mvpp2_port_fc_adv_enable(port);
mvpp2_port_reset(port);
}
static int mvpp2_port_init(struct mvpp2_port *port)
{
struct device *dev = port->dev->dev.parent;
struct mvpp2 *priv = port->priv;
struct mvpp2_txq_pcpu *txq_pcpu;
int queue, cpu, err;
if (port->first_rxq + rxq_number > MVPP2_RXQ_TOTAL_NUM)
return -EINVAL;
mvpp2_egress_disable(port);
mvpp2_port_disable(port);
port->txqs = devm_kcalloc(dev, txq_number, sizeof(*port->txqs),
GFP_KERNEL);
if (!port->txqs)
return -ENOMEM;
for (queue = 0; queue < txq_number; queue++) {
int queue_phy_id = mvpp2_txq_phys(port->id, queue);
struct mvpp2_tx_queue *txq;
txq = devm_kzalloc(dev, sizeof(*txq), GFP_KERNEL);
if (!txq)
return -ENOMEM;
txq->pcpu = alloc_percpu(struct mvpp2_txq_pcpu);
if (!txq->pcpu) {
err = -ENOMEM;
goto err_free_percpu;
}
txq->id = queue_phy_id;
txq->log_id = queue;
txq->done_pkts_coal = MVPP2_TXDONE_COAL_PKTS_THRESH;
for_each_present_cpu(cpu) {
txq_pcpu = per_cpu_ptr(txq->pcpu, cpu);
txq_pcpu->cpu = cpu;
}
port->txqs[queue] = txq;
}
port->rxqs = devm_kcalloc(dev, rxq_number, sizeof(*port->rxqs),
GFP_KERNEL);
if (!port->rxqs) {
err = -ENOMEM;
goto err_free_percpu;
}
for (queue = 0; queue < rxq_number; queue++) {
struct mvpp2_rx_queue *rxq;
rxq = devm_kzalloc(dev, sizeof(*rxq), GFP_KERNEL);
if (!rxq)
goto err_free_percpu;
rxq->id = port->first_rxq + queue;
rxq->port = port->id;
rxq->logic_rxq = queue;
port->rxqs[queue] = rxq;
}
mvpp2_write(priv, MVPP2_ISR_RXQ_GROUP_REG(port->id), rxq_number);
for (queue = 0; queue < rxq_number; queue++) {
struct mvpp2_rx_queue *rxq = port->rxqs[queue];
rxq->size = port->rx_ring_size;
rxq->pkts_coal = MVPP2_RX_COAL_PKTS;
rxq->time_coal = MVPP2_RX_COAL_USEC;
}
mvpp2_ingress_disable(port);
mvpp2_defaults_set(port);
mvpp2_cls_oversize_rxq_set(port);
mvpp2_cls_port_config(port);
port->pkt_size = MVPP2_RX_PKT_SIZE(port->dev->mtu);
err = mvpp2_swf_bm_pool_init(port);
if (err)
goto err_free_percpu;
return 0;
err_free_percpu:
for (queue = 0; queue < txq_number; queue++) {
if (!port->txqs[queue])
continue;
free_percpu(port->txqs[queue]->pcpu);
}
return err;
}
static int mvpp2_port_probe(struct platform_device *pdev,
struct device_node *port_node,
struct mvpp2 *priv,
int *next_first_rxq)
{
struct device_node *phy_node;
struct mvpp2_port *port;
struct mvpp2_port_pcpu *port_pcpu;
struct net_device *dev;
struct resource *res;
const char *dt_mac_addr;
const char *mac_from;
char hw_mac_addr[ETH_ALEN];
u32 id;
int features;
int phy_mode;
int priv_common_regs_num = 2;
int err, i, cpu;
dev = alloc_etherdev_mqs(sizeof(struct mvpp2_port), txq_number,
rxq_number);
if (!dev)
return -ENOMEM;
phy_node = of_parse_phandle(port_node, "phy", 0);
if (!phy_node) {
dev_err(&pdev->dev, "missing phy\n");
err = -ENODEV;
goto err_free_netdev;
}
phy_mode = of_get_phy_mode(port_node);
if (phy_mode < 0) {
dev_err(&pdev->dev, "incorrect phy mode\n");
err = phy_mode;
goto err_free_netdev;
}
if (of_property_read_u32(port_node, "port-id", &id)) {
err = -EINVAL;
dev_err(&pdev->dev, "missing port-id value\n");
goto err_free_netdev;
}
dev->tx_queue_len = MVPP2_MAX_TXD;
dev->watchdog_timeo = 5 * HZ;
dev->netdev_ops = &mvpp2_netdev_ops;
dev->ethtool_ops = &mvpp2_eth_tool_ops;
port = netdev_priv(dev);
port->irq = irq_of_parse_and_map(port_node, 0);
if (port->irq <= 0) {
err = -EINVAL;
goto err_free_netdev;
}
if (of_property_read_bool(port_node, "marvell,loopback"))
port->flags |= MVPP2_F_LOOPBACK;
port->priv = priv;
port->id = id;
port->first_rxq = *next_first_rxq;
port->phy_node = phy_node;
port->phy_interface = phy_mode;
res = platform_get_resource(pdev, IORESOURCE_MEM,
priv_common_regs_num + id);
port->base = devm_ioremap_resource(&pdev->dev, res);
if (IS_ERR(port->base)) {
err = PTR_ERR(port->base);
goto err_free_irq;
}
port->stats = netdev_alloc_pcpu_stats(struct mvpp2_pcpu_stats);
if (!port->stats) {
err = -ENOMEM;
goto err_free_irq;
}
dt_mac_addr = of_get_mac_address(port_node);
if (dt_mac_addr && is_valid_ether_addr(dt_mac_addr)) {
mac_from = "device tree";
ether_addr_copy(dev->dev_addr, dt_mac_addr);
} else {
mvpp2_get_mac_address(port, hw_mac_addr);
if (is_valid_ether_addr(hw_mac_addr)) {
mac_from = "hardware";
ether_addr_copy(dev->dev_addr, hw_mac_addr);
} else {
mac_from = "random";
eth_hw_addr_random(dev);
}
}
port->tx_ring_size = MVPP2_MAX_TXD;
port->rx_ring_size = MVPP2_MAX_RXD;
port->dev = dev;
SET_NETDEV_DEV(dev, &pdev->dev);
err = mvpp2_port_init(port);
if (err < 0) {
dev_err(&pdev->dev, "failed to init port %d\n", id);
goto err_free_stats;
}
mvpp2_port_power_up(port);
port->pcpu = alloc_percpu(struct mvpp2_port_pcpu);
if (!port->pcpu) {
err = -ENOMEM;
goto err_free_txq_pcpu;
}
for_each_present_cpu(cpu) {
port_pcpu = per_cpu_ptr(port->pcpu, cpu);
hrtimer_init(&port_pcpu->tx_done_timer, CLOCK_MONOTONIC,
HRTIMER_MODE_REL_PINNED);
port_pcpu->tx_done_timer.function = mvpp2_hr_timer_cb;
port_pcpu->timer_scheduled = false;
tasklet_init(&port_pcpu->tx_done_tasklet, mvpp2_tx_proc_cb,
(unsigned long)dev);
}
netif_napi_add(dev, &port->napi, mvpp2_poll, NAPI_POLL_WEIGHT);
features = NETIF_F_SG | NETIF_F_IP_CSUM;
dev->features = features | NETIF_F_RXCSUM;
dev->hw_features |= features | NETIF_F_RXCSUM | NETIF_F_GRO;
dev->vlan_features |= features;
err = register_netdev(dev);
if (err < 0) {
dev_err(&pdev->dev, "failed to register netdev\n");
goto err_free_port_pcpu;
}
netdev_info(dev, "Using %s mac address %pM\n", mac_from, dev->dev_addr);
*next_first_rxq += rxq_number;
priv->port_list[id] = port;
return 0;
err_free_port_pcpu:
free_percpu(port->pcpu);
err_free_txq_pcpu:
for (i = 0; i < txq_number; i++)
free_percpu(port->txqs[i]->pcpu);
err_free_stats:
free_percpu(port->stats);
err_free_irq:
irq_dispose_mapping(port->irq);
err_free_netdev:
free_netdev(dev);
return err;
}
static void mvpp2_port_remove(struct mvpp2_port *port)
{
int i;
unregister_netdev(port->dev);
free_percpu(port->pcpu);
free_percpu(port->stats);
for (i = 0; i < txq_number; i++)
free_percpu(port->txqs[i]->pcpu);
irq_dispose_mapping(port->irq);
free_netdev(port->dev);
}
static void mvpp2_conf_mbus_windows(const struct mbus_dram_target_info *dram,
struct mvpp2 *priv)
{
u32 win_enable;
int i;
for (i = 0; i < 6; i++) {
mvpp2_write(priv, MVPP2_WIN_BASE(i), 0);
mvpp2_write(priv, MVPP2_WIN_SIZE(i), 0);
if (i < 4)
mvpp2_write(priv, MVPP2_WIN_REMAP(i), 0);
}
win_enable = 0;
for (i = 0; i < dram->num_cs; i++) {
const struct mbus_dram_window *cs = dram->cs + i;
mvpp2_write(priv, MVPP2_WIN_BASE(i),
(cs->base & 0xffff0000) | (cs->mbus_attr << 8) |
dram->mbus_dram_target_id);
mvpp2_write(priv, MVPP2_WIN_SIZE(i),
(cs->size - 1) & 0xffff0000);
win_enable |= (1 << i);
}
mvpp2_write(priv, MVPP2_BASE_ADDR_ENABLE, win_enable);
}
static void mvpp2_rx_fifo_init(struct mvpp2 *priv)
{
int port;
for (port = 0; port < MVPP2_MAX_PORTS; port++) {
mvpp2_write(priv, MVPP2_RX_DATA_FIFO_SIZE_REG(port),
MVPP2_RX_FIFO_PORT_DATA_SIZE);
mvpp2_write(priv, MVPP2_RX_ATTR_FIFO_SIZE_REG(port),
MVPP2_RX_FIFO_PORT_ATTR_SIZE);
}
mvpp2_write(priv, MVPP2_RX_MIN_PKT_SIZE_REG,
MVPP2_RX_FIFO_PORT_MIN_PKT);
mvpp2_write(priv, MVPP2_RX_FIFO_INIT_REG, 0x1);
}
static int mvpp2_init(struct platform_device *pdev, struct mvpp2 *priv)
{
const struct mbus_dram_target_info *dram_target_info;
int err, i;
u32 val;
if (rxq_number % 4 || (rxq_number > MVPP2_MAX_RXQ) ||
(txq_number > MVPP2_MAX_TXQ)) {
dev_err(&pdev->dev, "invalid queue size parameter\n");
return -EINVAL;
}
dram_target_info = mv_mbus_dram_info();
if (dram_target_info)
mvpp2_conf_mbus_windows(dram_target_info, priv);
val = readl(priv->lms_base + MVPP2_PHY_AN_CFG0_REG);
val |= MVPP2_PHY_AN_STOP_SMI0_MASK;
writel(val, priv->lms_base + MVPP2_PHY_AN_CFG0_REG);
priv->aggr_txqs = devm_kcalloc(&pdev->dev, num_present_cpus(),
sizeof(struct mvpp2_tx_queue),
GFP_KERNEL);
if (!priv->aggr_txqs)
return -ENOMEM;
for_each_present_cpu(i) {
priv->aggr_txqs[i].id = i;
priv->aggr_txqs[i].size = MVPP2_AGGR_TXQ_SIZE;
err = mvpp2_aggr_txq_init(pdev, &priv->aggr_txqs[i],
MVPP2_AGGR_TXQ_SIZE, i, priv);
if (err < 0)
return err;
}
mvpp2_rx_fifo_init(priv);
for (i = 0; i < MVPP2_MAX_PORTS; i++)
mvpp2_write(priv, MVPP2_ISR_RXQ_GROUP_REG(i), rxq_number);
writel(MVPP2_EXT_GLOBAL_CTRL_DEFAULT,
priv->lms_base + MVPP2_MNG_EXTENDED_GLOBAL_CTRL_REG);
mvpp2_write(priv, MVPP2_TX_SNOOP_REG, 0x1);
err = mvpp2_bm_init(pdev, priv);
if (err < 0)
return err;
err = mvpp2_prs_default_init(pdev, priv);
if (err < 0)
return err;
mvpp2_cls_init(priv);
return 0;
}
static int mvpp2_probe(struct platform_device *pdev)
{
struct device_node *dn = pdev->dev.of_node;
struct device_node *port_node;
struct mvpp2 *priv;
struct resource *res;
int port_count, first_rxq;
int err;
priv = devm_kzalloc(&pdev->dev, sizeof(struct mvpp2), GFP_KERNEL);
if (!priv)
return -ENOMEM;
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
priv->base = devm_ioremap_resource(&pdev->dev, res);
if (IS_ERR(priv->base))
return PTR_ERR(priv->base);
res = platform_get_resource(pdev, IORESOURCE_MEM, 1);
priv->lms_base = devm_ioremap_resource(&pdev->dev, res);
if (IS_ERR(priv->lms_base))
return PTR_ERR(priv->lms_base);
priv->pp_clk = devm_clk_get(&pdev->dev, "pp_clk");
if (IS_ERR(priv->pp_clk))
return PTR_ERR(priv->pp_clk);
err = clk_prepare_enable(priv->pp_clk);
if (err < 0)
return err;
priv->gop_clk = devm_clk_get(&pdev->dev, "gop_clk");
if (IS_ERR(priv->gop_clk)) {
err = PTR_ERR(priv->gop_clk);
goto err_pp_clk;
}
err = clk_prepare_enable(priv->gop_clk);
if (err < 0)
goto err_pp_clk;
priv->tclk = clk_get_rate(priv->pp_clk);
err = mvpp2_init(pdev, priv);
if (err < 0) {
dev_err(&pdev->dev, "failed to initialize controller\n");
goto err_gop_clk;
}
port_count = of_get_available_child_count(dn);
if (port_count == 0) {
dev_err(&pdev->dev, "no ports enabled\n");
err = -ENODEV;
goto err_gop_clk;
}
priv->port_list = devm_kcalloc(&pdev->dev, port_count,
sizeof(struct mvpp2_port *),
GFP_KERNEL);
if (!priv->port_list) {
err = -ENOMEM;
goto err_gop_clk;
}
first_rxq = 0;
for_each_available_child_of_node(dn, port_node) {
err = mvpp2_port_probe(pdev, port_node, priv, &first_rxq);
if (err < 0)
goto err_gop_clk;
}
platform_set_drvdata(pdev, priv);
return 0;
err_gop_clk:
clk_disable_unprepare(priv->gop_clk);
err_pp_clk:
clk_disable_unprepare(priv->pp_clk);
return err;
}
static int mvpp2_remove(struct platform_device *pdev)
{
struct mvpp2 *priv = platform_get_drvdata(pdev);
struct device_node *dn = pdev->dev.of_node;
struct device_node *port_node;
int i = 0;
for_each_available_child_of_node(dn, port_node) {
if (priv->port_list[i])
mvpp2_port_remove(priv->port_list[i]);
i++;
}
for (i = 0; i < MVPP2_BM_POOLS_NUM; i++) {
struct mvpp2_bm_pool *bm_pool = &priv->bm_pools[i];
mvpp2_bm_pool_destroy(pdev, priv, bm_pool);
}
for_each_present_cpu(i) {
struct mvpp2_tx_queue *aggr_txq = &priv->aggr_txqs[i];
dma_free_coherent(&pdev->dev,
MVPP2_AGGR_TXQ_SIZE * MVPP2_DESC_ALIGNED_SIZE,
aggr_txq->descs,
aggr_txq->descs_phys);
}
clk_disable_unprepare(priv->pp_clk);
clk_disable_unprepare(priv->gop_clk);
return 0;
}
