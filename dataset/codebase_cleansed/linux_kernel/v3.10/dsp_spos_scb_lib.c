static void remove_symbol (struct snd_cs46xx * chip, struct dsp_symbol_entry * symbol)
{
struct dsp_spos_instance * ins = chip->dsp_spos_instance;
int symbol_index = (int)(symbol - ins->symbol_table.symbols);
if (snd_BUG_ON(ins->symbol_table.nsymbols <= 0))
return;
if (snd_BUG_ON(symbol_index < 0 ||
symbol_index >= ins->symbol_table.nsymbols))
return;
ins->symbol_table.symbols[symbol_index].deleted = 1;
if (symbol_index < ins->symbol_table.highest_frag_index) {
ins->symbol_table.highest_frag_index = symbol_index;
}
if (symbol_index == ins->symbol_table.nsymbols - 1)
ins->symbol_table.nsymbols --;
if (ins->symbol_table.highest_frag_index > ins->symbol_table.nsymbols) {
ins->symbol_table.highest_frag_index = ins->symbol_table.nsymbols;
}
}
static void cs46xx_dsp_proc_scb_info_read (struct snd_info_entry *entry,
struct snd_info_buffer *buffer)
{
struct proc_scb_info * scb_info = entry->private_data;
struct dsp_scb_descriptor * scb = scb_info->scb_desc;
struct dsp_spos_instance * ins;
struct snd_cs46xx *chip = scb_info->chip;
int j,col;
void __iomem *dst = chip->region.idx[1].remap_addr + DSP_PARAMETER_BYTE_OFFSET;
ins = chip->dsp_spos_instance;
mutex_lock(&chip->spos_mutex);
snd_iprintf(buffer,"%04x %s:\n",scb->address,scb->scb_name);
for (col = 0,j = 0;j < 0x10; j++,col++) {
if (col == 4) {
snd_iprintf(buffer,"\n");
col = 0;
}
snd_iprintf(buffer,"%08x ",readl(dst + (scb->address + j) * sizeof(u32)));
}
snd_iprintf(buffer,"\n");
if (scb->parent_scb_ptr != NULL) {
snd_iprintf(buffer,"parent [%s:%04x] ",
scb->parent_scb_ptr->scb_name,
scb->parent_scb_ptr->address);
} else snd_iprintf(buffer,"parent [none] ");
snd_iprintf(buffer,"sub_list_ptr [%s:%04x]\nnext_scb_ptr [%s:%04x] task_entry [%s:%04x]\n",
scb->sub_list_ptr->scb_name,
scb->sub_list_ptr->address,
scb->next_scb_ptr->scb_name,
scb->next_scb_ptr->address,
scb->task_entry->symbol_name,
scb->task_entry->address);
snd_iprintf(buffer,"index [%d] ref_count [%d]\n",scb->index,scb->ref_count);
mutex_unlock(&chip->spos_mutex);
}
static void _dsp_unlink_scb (struct snd_cs46xx *chip, struct dsp_scb_descriptor * scb)
{
struct dsp_spos_instance * ins = chip->dsp_spos_instance;
if ( scb->parent_scb_ptr ) {
if (snd_BUG_ON(scb->parent_scb_ptr->sub_list_ptr != scb &&
scb->parent_scb_ptr->next_scb_ptr != scb))
return;
if (scb->parent_scb_ptr->sub_list_ptr == scb) {
if (scb->next_scb_ptr == ins->the_null_scb) {
scb->parent_scb_ptr->sub_list_ptr = scb->sub_list_ptr;
if (scb->sub_list_ptr != ins->the_null_scb) {
scb->sub_list_ptr->parent_scb_ptr = scb->parent_scb_ptr;
}
scb->sub_list_ptr = ins->the_null_scb;
} else {
scb->parent_scb_ptr->sub_list_ptr = scb->next_scb_ptr;
if (scb->next_scb_ptr != ins->the_null_scb) {
scb->next_scb_ptr->parent_scb_ptr = scb->parent_scb_ptr;
}
scb->next_scb_ptr = ins->the_null_scb;
}
} else {
scb->parent_scb_ptr->next_scb_ptr = scb->next_scb_ptr;
if (scb->next_scb_ptr != ins->the_null_scb) {
scb->next_scb_ptr->parent_scb_ptr = scb->parent_scb_ptr;
}
scb->next_scb_ptr = ins->the_null_scb;
}
cs46xx_dsp_spos_update_scb(chip,scb->parent_scb_ptr);
cs46xx_dsp_spos_update_scb(chip,scb);
scb->parent_scb_ptr = NULL;
}
}
static void _dsp_clear_sample_buffer (struct snd_cs46xx *chip, u32 sample_buffer_addr,
int dword_count)
{
void __iomem *dst = chip->region.idx[2].remap_addr + sample_buffer_addr;
int i;
for (i = 0; i < dword_count ; ++i ) {
writel(0, dst);
dst += 4;
}
}
void cs46xx_dsp_remove_scb (struct snd_cs46xx *chip, struct dsp_scb_descriptor * scb)
{
struct dsp_spos_instance * ins = chip->dsp_spos_instance;
unsigned long flags;
if (snd_BUG_ON(scb->index < 0 ||
scb->index >= ins->nscb ||
(ins->scbs + scb->index) != scb))
return;
#if 0
if (snd_BUG_ON(scb->sub_list_ptr != ins->the_null_scb ||
scb->next_scb_ptr != ins->the_null_scb))
goto _end;
#endif
spin_lock_irqsave(&chip->reg_lock, flags);
_dsp_unlink_scb (chip,scb);
spin_unlock_irqrestore(&chip->reg_lock, flags);
cs46xx_dsp_proc_free_scb_desc(scb);
if (snd_BUG_ON(!scb->scb_symbol))
return;
remove_symbol (chip,scb->scb_symbol);
ins->scbs[scb->index].deleted = 1;
#ifdef CONFIG_PM_SLEEP
kfree(ins->scbs[scb->index].data);
ins->scbs[scb->index].data = NULL;
#endif
if (scb->index < ins->scb_highest_frag_index)
ins->scb_highest_frag_index = scb->index;
if (scb->index == ins->nscb - 1) {
ins->nscb --;
}
if (ins->scb_highest_frag_index > ins->nscb) {
ins->scb_highest_frag_index = ins->nscb;
}
#if 0
for(i = scb->index + 1;i < ins->nscb; ++i) {
ins->scbs[i - 1].index = i - 1;
}
#endif
}
void cs46xx_dsp_proc_free_scb_desc (struct dsp_scb_descriptor * scb)
{
if (scb->proc_info) {
struct proc_scb_info * scb_info = scb->proc_info->private_data;
snd_printdd("cs46xx_dsp_proc_free_scb_desc: freeing %s\n",scb->scb_name);
snd_info_free_entry(scb->proc_info);
scb->proc_info = NULL;
kfree (scb_info);
}
}
void cs46xx_dsp_proc_register_scb_desc (struct snd_cs46xx *chip,
struct dsp_scb_descriptor * scb)
{
struct dsp_spos_instance * ins = chip->dsp_spos_instance;
struct snd_info_entry * entry;
struct proc_scb_info * scb_info;
if (ins->snd_card != NULL && ins->proc_dsp_dir != NULL &&
scb->proc_info == NULL) {
if ((entry = snd_info_create_card_entry(ins->snd_card, scb->scb_name,
ins->proc_dsp_dir)) != NULL) {
scb_info = kmalloc(sizeof(struct proc_scb_info), GFP_KERNEL);
if (!scb_info) {
snd_info_free_entry(entry);
entry = NULL;
goto out;
}
scb_info->chip = chip;
scb_info->scb_desc = scb;
entry->content = SNDRV_INFO_CONTENT_TEXT;
entry->private_data = scb_info;
entry->mode = S_IFREG | S_IRUGO | S_IWUSR;
entry->c.text.read = cs46xx_dsp_proc_scb_info_read;
if (snd_info_register(entry) < 0) {
snd_info_free_entry(entry);
kfree (scb_info);
entry = NULL;
}
}
out:
scb->proc_info = entry;
}
}
static struct dsp_scb_descriptor *
_dsp_create_generic_scb (struct snd_cs46xx *chip, char * name, u32 * scb_data, u32 dest,
struct dsp_symbol_entry * task_entry,
struct dsp_scb_descriptor * parent_scb,
int scb_child_type)
{
struct dsp_spos_instance * ins = chip->dsp_spos_instance;
struct dsp_scb_descriptor * scb;
unsigned long flags;
if (snd_BUG_ON(!ins->the_null_scb))
return NULL;
scb_data[SCBsubListPtr] =
(ins->the_null_scb->address << 0x10) | ins->the_null_scb->address;
scb_data[SCBfuncEntryPtr] &= 0xFFFF0000;
scb_data[SCBfuncEntryPtr] |= task_entry->address;
snd_printdd("dsp_spos: creating SCB <%s>\n",name);
scb = cs46xx_dsp_create_scb(chip,name,scb_data,dest);
scb->sub_list_ptr = ins->the_null_scb;
scb->next_scb_ptr = ins->the_null_scb;
scb->parent_scb_ptr = parent_scb;
scb->task_entry = task_entry;
if (scb->parent_scb_ptr) {
#if 0
printk ("scb->parent_scb_ptr = %s\n",scb->parent_scb_ptr->scb_name);
printk ("scb->parent_scb_ptr->next_scb_ptr = %s\n",scb->parent_scb_ptr->next_scb_ptr->scb_name);
printk ("scb->parent_scb_ptr->sub_list_ptr = %s\n",scb->parent_scb_ptr->sub_list_ptr->scb_name);
#endif
if (scb_child_type == SCB_ON_PARENT_NEXT_SCB) {
if (snd_BUG_ON(scb->parent_scb_ptr->next_scb_ptr !=
ins->the_null_scb))
return NULL;
scb->parent_scb_ptr->next_scb_ptr = scb;
} else if (scb_child_type == SCB_ON_PARENT_SUBLIST_SCB) {
if (snd_BUG_ON(scb->parent_scb_ptr->sub_list_ptr !=
ins->the_null_scb))
return NULL;
scb->parent_scb_ptr->sub_list_ptr = scb;
} else {
snd_BUG();
}
spin_lock_irqsave(&chip->reg_lock, flags);
cs46xx_dsp_spos_update_scb(chip,scb->parent_scb_ptr);
spin_unlock_irqrestore(&chip->reg_lock, flags);
}
cs46xx_dsp_proc_register_scb_desc (chip,scb);
return scb;
}
static struct dsp_scb_descriptor *
cs46xx_dsp_create_generic_scb (struct snd_cs46xx *chip, char * name, u32 * scb_data,
u32 dest, char * task_entry_name,
struct dsp_scb_descriptor * parent_scb,
int scb_child_type)
{
struct dsp_symbol_entry * task_entry;
task_entry = cs46xx_dsp_lookup_symbol (chip,task_entry_name,
SYMBOL_CODE);
if (task_entry == NULL) {
snd_printk (KERN_ERR "dsp_spos: symbol %s not found\n",task_entry_name);
return NULL;
}
return _dsp_create_generic_scb (chip,name,scb_data,dest,task_entry,
parent_scb,scb_child_type);
}
struct dsp_scb_descriptor *
cs46xx_dsp_create_timing_master_scb (struct snd_cs46xx *chip)
{
struct dsp_scb_descriptor * scb;
struct dsp_timing_master_scb timing_master_scb = {
{ 0,
0,
0,
0
},
{ 0,
0,
0,
0,
0
},
0,0,
0,NULL_SCB_ADDR,
0,0,
0,0,
0x0001,0x8000,
0x0001,0x0000,
0x00060000
};
scb = cs46xx_dsp_create_generic_scb(chip,"TimingMasterSCBInst",(u32 *)&timing_master_scb,
TIMINGMASTER_SCB_ADDR,
"TIMINGMASTER",NULL,SCB_NO_PARENT);
return scb;
}
struct dsp_scb_descriptor *
cs46xx_dsp_create_codec_out_scb(struct snd_cs46xx * chip, char * codec_name,
u16 channel_disp, u16 fifo_addr, u16 child_scb_addr,
u32 dest, struct dsp_scb_descriptor * parent_scb,
int scb_child_type)
{
struct dsp_scb_descriptor * scb;
struct dsp_codec_output_scb codec_out_scb = {
{ 0,
0,
0,
0
},
{
0,
0,
0,
0,
0
},
0,0,
0,NULL_SCB_ADDR,
0,
0,
channel_disp,fifo_addr,
0x0000,0x0080,
0,child_scb_addr
};
scb = cs46xx_dsp_create_generic_scb(chip,codec_name,(u32 *)&codec_out_scb,
dest,"S16_CODECOUTPUTTASK",parent_scb,
scb_child_type);
return scb;
}
struct dsp_scb_descriptor *
cs46xx_dsp_create_codec_in_scb(struct snd_cs46xx * chip, char * codec_name,
u16 channel_disp, u16 fifo_addr, u16 sample_buffer_addr,
u32 dest, struct dsp_scb_descriptor * parent_scb,
int scb_child_type)
{
struct dsp_scb_descriptor * scb;
struct dsp_codec_input_scb codec_input_scb = {
{ 0,
0,
0,
0
},
{
0,
0,
0,
0,
0
},
#if 0
SyncIOSCB,NULL_SCB_ADDR
#else
0 , 0,
#endif
0,0,
RSCONFIG_SAMPLE_16STEREO + RSCONFIG_MODULO_64,
sample_buffer_addr << 0x10,
channel_disp,fifo_addr,
0x0000,0x0000,
0x80008000
};
scb = cs46xx_dsp_create_generic_scb(chip,codec_name,(u32 *)&codec_input_scb,
dest,"S16_CODECINPUTTASK",parent_scb,
scb_child_type);
return scb;
}
static struct dsp_scb_descriptor *
cs46xx_dsp_create_pcm_reader_scb(struct snd_cs46xx * chip, char * scb_name,
u16 sample_buffer_addr, u32 dest,
int virtual_channel, u32 playback_hw_addr,
struct dsp_scb_descriptor * parent_scb,
int scb_child_type)
{
struct dsp_spos_instance * ins = chip->dsp_spos_instance;
struct dsp_scb_descriptor * scb;
struct dsp_generic_scb pcm_reader_scb = {
{ DMA_RQ_C1_SOURCE_ON_HOST +
DMA_RQ_C1_SOURCE_MOD1024 +
DMA_RQ_C1_DEST_MOD32 +
DMA_RQ_C1_WRITEBACK_SRC_FLAG +
DMA_RQ_C1_WRITEBACK_DEST_FLAG +
15,
DMA_RQ_C2_AC_NONE +
DMA_RQ_C2_SIGNAL_SOURCE_PINGPONG +
virtual_channel,
playback_hw_addr,
DMA_RQ_SD_SP_SAMPLE_ADDR +
sample_buffer_addr
},
{
0,
0,
0,
0,
0
},
NULL_SCB_ADDR,NULL_SCB_ADDR,
0,NULL_SCB_ADDR,
RSCONFIG_DMA_ENABLE +
(19 << RSCONFIG_MAX_DMA_SIZE_SHIFT) +
((dest >> 4) << RSCONFIG_STREAM_NUM_SHIFT) +
RSCONFIG_SAMPLE_16STEREO +
RSCONFIG_MODULO_32,
(sample_buffer_addr << 0x10),
0,
{
0xffff,0xffff,
0xffff,0xffff
}
};
if (ins->null_algorithm == NULL) {
ins->null_algorithm = cs46xx_dsp_lookup_symbol (chip,"NULLALGORITHM",
SYMBOL_CODE);
if (ins->null_algorithm == NULL) {
snd_printk (KERN_ERR "dsp_spos: symbol NULLALGORITHM not found\n");
return NULL;
}
}
scb = _dsp_create_generic_scb(chip,scb_name,(u32 *)&pcm_reader_scb,
dest,ins->null_algorithm,parent_scb,
scb_child_type);
return scb;
}
struct dsp_scb_descriptor *
cs46xx_dsp_create_src_task_scb(struct snd_cs46xx * chip, char * scb_name,
int rate,
u16 src_buffer_addr,
u16 src_delay_buffer_addr, u32 dest,
struct dsp_scb_descriptor * parent_scb,
int scb_child_type,
int pass_through)
{
struct dsp_spos_instance * ins = chip->dsp_spos_instance;
struct dsp_scb_descriptor * scb;
unsigned int tmp1, tmp2;
unsigned int phiIncr;
unsigned int correctionPerGOF, correctionPerSec;
snd_printdd( "dsp_spos: setting %s rate to %u\n",scb_name,rate);
tmp1 = rate << 16;
phiIncr = tmp1 / 48000;
tmp1 -= phiIncr * 48000;
tmp1 <<= 10;
phiIncr <<= 10;
tmp2 = tmp1 / 48000;
phiIncr += tmp2;
tmp1 -= tmp2 * 48000;
correctionPerGOF = tmp1 / GOF_PER_SEC;
tmp1 -= correctionPerGOF * GOF_PER_SEC;
correctionPerSec = tmp1;
{
struct dsp_src_task_scb src_task_scb = {
0x0028,0x00c8,
0x5555,0x0000,
0x0000,0x0000,
src_buffer_addr,1,
correctionPerGOF,correctionPerSec,
RSCONFIG_SAMPLE_16STEREO + RSCONFIG_MODULO_32,
0x0000,src_delay_buffer_addr,
0x0,
0x080,(src_delay_buffer_addr + (24 * 4)),
0,0,
0,0,
RSCONFIG_SAMPLE_16STEREO + RSCONFIG_MODULO_8,
src_buffer_addr << 0x10,
phiIncr,
{
0xffff - ins->dac_volume_right,0xffff - ins->dac_volume_left,
0xffff - ins->dac_volume_right,0xffff - ins->dac_volume_left
}
};
if (ins->s16_up == NULL) {
ins->s16_up = cs46xx_dsp_lookup_symbol (chip,"S16_UPSRC",
SYMBOL_CODE);
if (ins->s16_up == NULL) {
snd_printk (KERN_ERR "dsp_spos: symbol S16_UPSRC not found\n");
return NULL;
}
}
_dsp_clear_sample_buffer (chip,src_buffer_addr,8);
_dsp_clear_sample_buffer (chip,src_delay_buffer_addr,32);
if (pass_through) {
snd_BUG_ON(rate != 48000);
scb = cs46xx_dsp_create_generic_scb(chip,scb_name,(u32 *)&src_task_scb,
dest,"DMAREADER",parent_scb,
scb_child_type);
} else {
scb = _dsp_create_generic_scb(chip,scb_name,(u32 *)&src_task_scb,
dest,ins->s16_up,parent_scb,
scb_child_type);
}
}
return scb;
}
struct dsp_scb_descriptor *
cs46xx_dsp_create_mix_only_scb(struct snd_cs46xx * chip, char * scb_name,
u16 mix_buffer_addr, u32 dest,
struct dsp_scb_descriptor * parent_scb,
int scb_child_type)
{
struct dsp_scb_descriptor * scb;
struct dsp_mix_only_scb master_mix_scb = {
{ 0,
0,
mix_buffer_addr,
0
},
{
0,
0,
0,
0,
0x00000080
},
0,0,
0,0,
RSCONFIG_SAMPLE_16STEREO + RSCONFIG_MODULO_32,
(mix_buffer_addr + (16 * 4)) << 0x10,
0,
{
0x8000,0x8000,
0x8000,0x8000
}
};
scb = cs46xx_dsp_create_generic_scb(chip,scb_name,(u32 *)&master_mix_scb,
dest,"S16_MIX",parent_scb,
scb_child_type);
return scb;
}
struct dsp_scb_descriptor *
cs46xx_dsp_create_mix_to_ostream_scb(struct snd_cs46xx * chip, char * scb_name,
u16 mix_buffer_addr, u16 writeback_spb, u32 dest,
struct dsp_scb_descriptor * parent_scb,
int scb_child_type)
{
struct dsp_scb_descriptor * scb;
struct dsp_mix2_ostream_scb mix2_ostream_scb = {
{
DMA_RQ_C1_SOURCE_MOD64 +
DMA_RQ_C1_DEST_ON_HOST +
DMA_RQ_C1_DEST_MOD1024 +
DMA_RQ_C1_WRITEBACK_SRC_FLAG +
DMA_RQ_C1_WRITEBACK_DEST_FLAG +
15,
DMA_RQ_C2_AC_NONE +
DMA_RQ_C2_SIGNAL_DEST_PINGPONG +
CS46XX_DSP_CAPTURE_CHANNEL,
DMA_RQ_SD_SP_SAMPLE_ADDR +
mix_buffer_addr,
0x0
},
{ 0, 0, 0, 0, 0, },
0,0,
0,writeback_spb,
RSCONFIG_DMA_ENABLE +
(19 << RSCONFIG_MAX_DMA_SIZE_SHIFT) +
((dest >> 4) << RSCONFIG_STREAM_NUM_SHIFT) +
RSCONFIG_DMA_TO_HOST +
RSCONFIG_SAMPLE_16STEREO +
RSCONFIG_MODULO_64,
(mix_buffer_addr + (32 * 4)) << 0x10,
1,0,
0x0001,0x0080,
0xFFFF,0
};
scb = cs46xx_dsp_create_generic_scb(chip,scb_name,(u32 *)&mix2_ostream_scb,
dest,"S16_MIX_TO_OSTREAM",parent_scb,
scb_child_type);
return scb;
}
struct dsp_scb_descriptor *
cs46xx_dsp_create_vari_decimate_scb(struct snd_cs46xx * chip,char * scb_name,
u16 vari_buffer_addr0,
u16 vari_buffer_addr1,
u32 dest,
struct dsp_scb_descriptor * parent_scb,
int scb_child_type)
{
struct dsp_scb_descriptor * scb;
struct dsp_vari_decimate_scb vari_decimate_scb = {
0x0028,0x00c8,
0x5555,0x0000,
0x0000,0x0000,
vari_buffer_addr0,vari_buffer_addr1,
0x0028,0x00c8,
RSCONFIG_SAMPLE_16STEREO + RSCONFIG_MODULO_256,
0xFF800000,
0,
0x0080,vari_buffer_addr1 + (25 * 4),
0,0,
0,0,
RSCONFIG_SAMPLE_16STEREO + RSCONFIG_MODULO_8,
vari_buffer_addr0 << 0x10,
0x04000000,
{
0x8000,0x8000,
0xFFFF,0xFFFF
}
};
scb = cs46xx_dsp_create_generic_scb(chip,scb_name,(u32 *)&vari_decimate_scb,
dest,"VARIDECIMATE",parent_scb,
scb_child_type);
return scb;
}
static struct dsp_scb_descriptor *
cs46xx_dsp_create_pcm_serial_input_scb(struct snd_cs46xx * chip, char * scb_name, u32 dest,
struct dsp_scb_descriptor * input_scb,
struct dsp_scb_descriptor * parent_scb,
int scb_child_type)
{
struct dsp_scb_descriptor * scb;
struct dsp_pcm_serial_input_scb pcm_serial_input_scb = {
{ 0,
0,
0,
0
},
{
0,
0,
0,
0,
0
},
0,0,
0,0,
RSCONFIG_SAMPLE_16STEREO + RSCONFIG_MODULO_16,
0,
0,input_scb->address,
{
0x8000,0x8000,
0x8000,0x8000
}
};
scb = cs46xx_dsp_create_generic_scb(chip,scb_name,(u32 *)&pcm_serial_input_scb,
dest,"PCMSERIALINPUTTASK",parent_scb,
scb_child_type);
return scb;
}
static struct dsp_scb_descriptor *
cs46xx_dsp_create_asynch_fg_tx_scb(struct snd_cs46xx * chip, char * scb_name, u32 dest,
u16 hfg_scb_address,
u16 asynch_buffer_address,
struct dsp_scb_descriptor * parent_scb,
int scb_child_type)
{
struct dsp_scb_descriptor * scb;
struct dsp_asynch_fg_tx_scb asynch_fg_tx_scb = {
0xfc00,0x03ff,
0x0058,0x0028,
0,hfg_scb_address,
0,0,
0,
0,0x2aab,
{
0,
0,
0
},
0,0,
0,dest + AFGTxAccumPhi,
RSCONFIG_SAMPLE_16STEREO + RSCONFIG_MODULO_256,
(asynch_buffer_address) << 0x10,
0x18000000,
0x8000,0x8000,
0x8000,0x8000
};
scb = cs46xx_dsp_create_generic_scb(chip,scb_name,(u32 *)&asynch_fg_tx_scb,
dest,"ASYNCHFGTXCODE",parent_scb,
scb_child_type);
return scb;
}
struct dsp_scb_descriptor *
cs46xx_dsp_create_asynch_fg_rx_scb(struct snd_cs46xx * chip, char * scb_name, u32 dest,
u16 hfg_scb_address,
u16 asynch_buffer_address,
struct dsp_scb_descriptor * parent_scb,
int scb_child_type)
{
struct dsp_spos_instance * ins = chip->dsp_spos_instance;
struct dsp_scb_descriptor * scb;
struct dsp_asynch_fg_rx_scb asynch_fg_rx_scb = {
0xfe00,0x01ff,
0x0064,0x001c,
0,hfg_scb_address,
0,0,
{
0,
0,
0,
0,
0
},
0,0,
0,dest,
RSCONFIG_MODULO_128 |
RSCONFIG_SAMPLE_16STEREO,
( (asynch_buffer_address + (16 * 4)) << 0x10),
0x18000000,
0xffff - ins->spdif_input_volume_right,0xffff - ins->spdif_input_volume_left,
0xffff - ins->spdif_input_volume_right,0xffff - ins->spdif_input_volume_left,
};
scb = cs46xx_dsp_create_generic_scb(chip,scb_name,(u32 *)&asynch_fg_rx_scb,
dest,"ASYNCHFGRXCODE",parent_scb,
scb_child_type);
return scb;
}
struct dsp_scb_descriptor *
cs46xx_dsp_create_spio_write_scb(struct snd_cs46xx * chip, char * scb_name, u32 dest,
struct dsp_scb_descriptor * parent_scb,
int scb_child_type)
{
struct dsp_scb_descriptor * scb;
struct dsp_spio_write_scb spio_write_scb = {
0,0,
0,
0,
0,0,
0,
0,
0,0,
{ 0,0 },
0,0,
0,0,
{
0,
0,
0,
0,
0
}
};
scb = cs46xx_dsp_create_generic_scb(chip,scb_name,(u32 *)&spio_write_scb,
dest,"SPIOWRITE",parent_scb,
scb_child_type);
return scb;
}
struct dsp_scb_descriptor *
cs46xx_dsp_create_magic_snoop_scb(struct snd_cs46xx * chip, char * scb_name, u32 dest,
u16 snoop_buffer_address,
struct dsp_scb_descriptor * snoop_scb,
struct dsp_scb_descriptor * parent_scb,
int scb_child_type)
{
struct dsp_scb_descriptor * scb;
struct dsp_magic_snoop_task magic_snoop_scb = {
0,
0,
snoop_buffer_address << 0x10,
0,snoop_scb->address,
0,
0,
0,
0,
0,
0,0,
0,0,
RSCONFIG_SAMPLE_16STEREO + RSCONFIG_MODULO_64,
snoop_buffer_address << 0x10,
0,
{ 0x8000,0x8000,
0xffff,0xffff
}
};
scb = cs46xx_dsp_create_generic_scb(chip,scb_name,(u32 *)&magic_snoop_scb,
dest,"MAGICSNOOPTASK",parent_scb,
scb_child_type);
return scb;
}
static struct dsp_scb_descriptor *
find_next_free_scb (struct snd_cs46xx * chip, struct dsp_scb_descriptor * from)
{
struct dsp_spos_instance * ins = chip->dsp_spos_instance;
struct dsp_scb_descriptor * scb = from;
while (scb->next_scb_ptr != ins->the_null_scb) {
if (snd_BUG_ON(!scb->next_scb_ptr))
return NULL;
scb = scb->next_scb_ptr;
}
return scb;
}
struct dsp_pcm_channel_descriptor *
cs46xx_dsp_create_pcm_channel (struct snd_cs46xx * chip,
u32 sample_rate, void * private_data,
u32 hw_dma_addr,
int pcm_channel_id)
{
struct dsp_spos_instance * ins = chip->dsp_spos_instance;
struct dsp_scb_descriptor * src_scb = NULL, * pcm_scb, * mixer_scb = NULL;
struct dsp_scb_descriptor * src_parent_scb = NULL;
char scb_name[DSP_MAX_SCB_NAME];
int i, pcm_index = -1, insert_point, src_index = -1, pass_through = 0;
unsigned long flags;
switch (pcm_channel_id) {
case DSP_PCM_MAIN_CHANNEL:
mixer_scb = ins->master_mix_scb;
break;
case DSP_PCM_REAR_CHANNEL:
mixer_scb = ins->rear_mix_scb;
break;
case DSP_PCM_CENTER_LFE_CHANNEL:
mixer_scb = ins->center_lfe_mix_scb;
break;
case DSP_PCM_S71_CHANNEL:
snd_BUG();
break;
case DSP_IEC958_CHANNEL:
if (snd_BUG_ON(!ins->asynch_tx_scb))
return NULL;
mixer_scb = ins->asynch_tx_scb;
if (sample_rate == 48000) {
snd_printdd ("IEC958 pass through\n");
pass_through = 1;
}
break;
default:
snd_BUG();
return NULL;
}
if (!sample_rate) sample_rate = 44100;
for (i = 0; i < DSP_MAX_PCM_CHANNELS &&
(pcm_index == -1 || src_scb == NULL); ++i) {
if (i == CS46XX_DSP_CAPTURE_CHANNEL) continue;
if (ins->pcm_channels[i].active) {
if (!src_scb &&
ins->pcm_channels[i].sample_rate == sample_rate &&
ins->pcm_channels[i].mixer_scb == mixer_scb) {
src_scb = ins->pcm_channels[i].src_scb;
ins->pcm_channels[i].src_scb->ref_count ++;
src_index = ins->pcm_channels[i].src_slot;
}
} else if (pcm_index == -1) {
pcm_index = i;
}
}
if (pcm_index == -1) {
snd_printk (KERN_ERR "dsp_spos: no free PCM channel\n");
return NULL;
}
if (src_scb == NULL) {
if (ins->nsrc_scb >= DSP_MAX_SRC_NR) {
snd_printk(KERN_ERR "dsp_spos: to many SRC instances\n!");
return NULL;
}
for (i = 0; i < DSP_MAX_SRC_NR; ++i) {
if (ins->src_scb_slots[i] == 0) {
src_index = i;
ins->src_scb_slots[i] = 1;
break;
}
}
if (snd_BUG_ON(src_index == -1))
return NULL;
if (mixer_scb->sub_list_ptr == ins->the_null_scb) {
src_parent_scb = mixer_scb;
insert_point = SCB_ON_PARENT_SUBLIST_SCB;
} else {
src_parent_scb = find_next_free_scb(chip,mixer_scb->sub_list_ptr);
insert_point = SCB_ON_PARENT_NEXT_SCB;
}
snprintf (scb_name,DSP_MAX_SCB_NAME,"SrcTask_SCB%d",src_index);
snd_printdd( "dsp_spos: creating SRC \"%s\"\n",scb_name);
src_scb = cs46xx_dsp_create_src_task_scb(chip,scb_name,
sample_rate,
src_output_buffer_addr[src_index],
src_delay_buffer_addr[src_index],
0x400 + (src_index * 0x10) ,
src_parent_scb,
insert_point,
pass_through);
if (!src_scb) {
snd_printk (KERN_ERR "dsp_spos: failed to create SRCtaskSCB\n");
return NULL;
}
ins->nsrc_scb ++;
}
snprintf (scb_name,DSP_MAX_SCB_NAME,"PCMReader_SCB%d",pcm_index);
snd_printdd( "dsp_spos: creating PCM \"%s\" (%d)\n",scb_name,
pcm_channel_id);
pcm_scb = cs46xx_dsp_create_pcm_reader_scb(chip,scb_name,
pcm_reader_buffer_addr[pcm_index],
(pcm_index * 0x10) + 0x200,
pcm_index,
hw_dma_addr,
NULL,
0
);
if (!pcm_scb) {
snd_printk (KERN_ERR "dsp_spos: failed to create PCMreaderSCB\n");
return NULL;
}
spin_lock_irqsave(&chip->reg_lock, flags);
ins->pcm_channels[pcm_index].sample_rate = sample_rate;
ins->pcm_channels[pcm_index].pcm_reader_scb = pcm_scb;
ins->pcm_channels[pcm_index].src_scb = src_scb;
ins->pcm_channels[pcm_index].unlinked = 1;
ins->pcm_channels[pcm_index].private_data = private_data;
ins->pcm_channels[pcm_index].src_slot = src_index;
ins->pcm_channels[pcm_index].active = 1;
ins->pcm_channels[pcm_index].pcm_slot = pcm_index;
ins->pcm_channels[pcm_index].mixer_scb = mixer_scb;
ins->npcm_channels ++;
spin_unlock_irqrestore(&chip->reg_lock, flags);
return (ins->pcm_channels + pcm_index);
}
int cs46xx_dsp_pcm_channel_set_period (struct snd_cs46xx * chip,
struct dsp_pcm_channel_descriptor * pcm_channel,
int period_size)
{
u32 temp = snd_cs46xx_peek (chip,pcm_channel->pcm_reader_scb->address << 2);
temp &= ~DMA_RQ_C1_SOURCE_SIZE_MASK;
switch (period_size) {
case 2048:
temp |= DMA_RQ_C1_SOURCE_MOD1024;
break;
case 1024:
temp |= DMA_RQ_C1_SOURCE_MOD512;
break;
case 512:
temp |= DMA_RQ_C1_SOURCE_MOD256;
break;
case 256:
temp |= DMA_RQ_C1_SOURCE_MOD128;
break;
case 128:
temp |= DMA_RQ_C1_SOURCE_MOD64;
break;
case 64:
temp |= DMA_RQ_C1_SOURCE_MOD32;
break;
case 32:
temp |= DMA_RQ_C1_SOURCE_MOD16;
break;
default:
snd_printdd ("period size (%d) not supported by HW\n", period_size);
return -EINVAL;
}
snd_cs46xx_poke (chip,pcm_channel->pcm_reader_scb->address << 2,temp);
return 0;
}
int cs46xx_dsp_pcm_ostream_set_period (struct snd_cs46xx * chip,
int period_size)
{
u32 temp = snd_cs46xx_peek (chip,WRITEBACK_SCB_ADDR << 2);
temp &= ~DMA_RQ_C1_DEST_SIZE_MASK;
switch (period_size) {
case 2048:
temp |= DMA_RQ_C1_DEST_MOD1024;
break;
case 1024:
temp |= DMA_RQ_C1_DEST_MOD512;
break;
case 512:
temp |= DMA_RQ_C1_DEST_MOD256;
break;
case 256:
temp |= DMA_RQ_C1_DEST_MOD128;
break;
case 128:
temp |= DMA_RQ_C1_DEST_MOD64;
break;
case 64:
temp |= DMA_RQ_C1_DEST_MOD32;
break;
case 32:
temp |= DMA_RQ_C1_DEST_MOD16;
break;
default:
snd_printdd ("period size (%d) not supported by HW\n", period_size);
return -EINVAL;
}
snd_cs46xx_poke (chip,WRITEBACK_SCB_ADDR << 2,temp);
return 0;
}
void cs46xx_dsp_destroy_pcm_channel (struct snd_cs46xx * chip,
struct dsp_pcm_channel_descriptor * pcm_channel)
{
struct dsp_spos_instance * ins = chip->dsp_spos_instance;
unsigned long flags;
if (snd_BUG_ON(!pcm_channel->active ||
ins->npcm_channels <= 0 ||
pcm_channel->src_scb->ref_count <= 0))
return;
spin_lock_irqsave(&chip->reg_lock, flags);
pcm_channel->unlinked = 1;
pcm_channel->active = 0;
pcm_channel->private_data = NULL;
pcm_channel->src_scb->ref_count --;
ins->npcm_channels --;
spin_unlock_irqrestore(&chip->reg_lock, flags);
cs46xx_dsp_remove_scb(chip,pcm_channel->pcm_reader_scb);
if (!pcm_channel->src_scb->ref_count) {
cs46xx_dsp_remove_scb(chip,pcm_channel->src_scb);
if (snd_BUG_ON(pcm_channel->src_slot < 0 ||
pcm_channel->src_slot >= DSP_MAX_SRC_NR))
return;
ins->src_scb_slots[pcm_channel->src_slot] = 0;
ins->nsrc_scb --;
}
}
int cs46xx_dsp_pcm_unlink (struct snd_cs46xx * chip,
struct dsp_pcm_channel_descriptor * pcm_channel)
{
unsigned long flags;
if (snd_BUG_ON(!pcm_channel->active ||
chip->dsp_spos_instance->npcm_channels <= 0))
return -EIO;
spin_lock_irqsave(&chip->reg_lock, flags);
if (pcm_channel->unlinked) {
spin_unlock_irqrestore(&chip->reg_lock, flags);
return -EIO;
}
pcm_channel->unlinked = 1;
_dsp_unlink_scb (chip,pcm_channel->pcm_reader_scb);
spin_unlock_irqrestore(&chip->reg_lock, flags);
return 0;
}
int cs46xx_dsp_pcm_link (struct snd_cs46xx * chip,
struct dsp_pcm_channel_descriptor * pcm_channel)
{
struct dsp_spos_instance * ins = chip->dsp_spos_instance;
struct dsp_scb_descriptor * parent_scb;
struct dsp_scb_descriptor * src_scb = pcm_channel->src_scb;
unsigned long flags;
spin_lock_irqsave(&chip->reg_lock, flags);
if (pcm_channel->unlinked == 0) {
spin_unlock_irqrestore(&chip->reg_lock, flags);
return -EIO;
}
parent_scb = src_scb;
if (src_scb->sub_list_ptr != ins->the_null_scb) {
src_scb->sub_list_ptr->parent_scb_ptr = pcm_channel->pcm_reader_scb;
pcm_channel->pcm_reader_scb->next_scb_ptr = src_scb->sub_list_ptr;
}
src_scb->sub_list_ptr = pcm_channel->pcm_reader_scb;
snd_BUG_ON(pcm_channel->pcm_reader_scb->parent_scb_ptr);
pcm_channel->pcm_reader_scb->parent_scb_ptr = parent_scb;
cs46xx_dsp_spos_update_scb(chip,pcm_channel->pcm_reader_scb);
cs46xx_dsp_spos_update_scb(chip,parent_scb);
pcm_channel->unlinked = 0;
spin_unlock_irqrestore(&chip->reg_lock, flags);
return 0;
}
struct dsp_scb_descriptor *
cs46xx_add_record_source (struct snd_cs46xx *chip, struct dsp_scb_descriptor * source,
u16 addr, char * scb_name)
{
struct dsp_spos_instance * ins = chip->dsp_spos_instance;
struct dsp_scb_descriptor * parent;
struct dsp_scb_descriptor * pcm_input;
int insert_point;
if (snd_BUG_ON(!ins->record_mixer_scb))
return NULL;
if (ins->record_mixer_scb->sub_list_ptr != ins->the_null_scb) {
parent = find_next_free_scb (chip,ins->record_mixer_scb->sub_list_ptr);
insert_point = SCB_ON_PARENT_NEXT_SCB;
} else {
parent = ins->record_mixer_scb;
insert_point = SCB_ON_PARENT_SUBLIST_SCB;
}
pcm_input = cs46xx_dsp_create_pcm_serial_input_scb(chip,scb_name,addr,
source, parent,
insert_point);
return pcm_input;
}
int cs46xx_src_unlink(struct snd_cs46xx *chip, struct dsp_scb_descriptor * src)
{
unsigned long flags;
if (snd_BUG_ON(!src->parent_scb_ptr))
return -EINVAL;
cs46xx_dsp_scb_set_volume (chip,src,0,0);
spin_lock_irqsave(&chip->reg_lock, flags);
_dsp_unlink_scb (chip,src);
spin_unlock_irqrestore(&chip->reg_lock, flags);
return 0;
}
int cs46xx_src_link(struct snd_cs46xx *chip, struct dsp_scb_descriptor * src)
{
struct dsp_spos_instance * ins = chip->dsp_spos_instance;
struct dsp_scb_descriptor * parent_scb;
if (snd_BUG_ON(src->parent_scb_ptr))
return -EINVAL;
if (snd_BUG_ON(!ins->master_mix_scb))
return -EINVAL;
if (ins->master_mix_scb->sub_list_ptr != ins->the_null_scb) {
parent_scb = find_next_free_scb (chip,ins->master_mix_scb->sub_list_ptr);
parent_scb->next_scb_ptr = src;
} else {
parent_scb = ins->master_mix_scb;
parent_scb->sub_list_ptr = src;
}
src->parent_scb_ptr = parent_scb;
cs46xx_dsp_spos_update_scb(chip,parent_scb);
return 0;
}
int cs46xx_dsp_enable_spdif_out (struct snd_cs46xx *chip)
{
struct dsp_spos_instance * ins = chip->dsp_spos_instance;
if ( ! (ins->spdif_status_out & DSP_SPDIF_STATUS_HW_ENABLED) ) {
cs46xx_dsp_enable_spdif_hw (chip);
}
if ( ins->spdif_status_out & DSP_SPDIF_STATUS_PLAYBACK_OPEN) {
ins->spdif_status_out |= DSP_SPDIF_STATUS_OUTPUT_ENABLED;
return -EBUSY;
}
if (snd_BUG_ON(ins->asynch_tx_scb))
return -EINVAL;
if (snd_BUG_ON(ins->master_mix_scb->next_scb_ptr !=
ins->the_null_scb))
return -EINVAL;
snd_cs46xx_poke (chip, (ins->ref_snoop_scb->address + 2) << 2,
(OUTPUT_SNOOP_BUFFER + 0x10) << 0x10 );
ins->asynch_tx_scb = cs46xx_dsp_create_asynch_fg_tx_scb(chip,"AsynchFGTxSCB",ASYNCTX_SCB_ADDR,
SPDIFO_SCB_INST,
SPDIFO_IP_OUTPUT_BUFFER1,
ins->master_mix_scb,
SCB_ON_PARENT_NEXT_SCB);
if (!ins->asynch_tx_scb) return -ENOMEM;
ins->spdif_pcm_input_scb = cs46xx_dsp_create_pcm_serial_input_scb(chip,"PCMSerialInput_II",
PCMSERIALINII_SCB_ADDR,
ins->ref_snoop_scb,
ins->asynch_tx_scb,
SCB_ON_PARENT_SUBLIST_SCB);
if (!ins->spdif_pcm_input_scb) return -ENOMEM;
ins->spdif_status_out |= DSP_SPDIF_STATUS_OUTPUT_ENABLED;
return 0;
}
int cs46xx_dsp_disable_spdif_out (struct snd_cs46xx *chip)
{
struct dsp_spos_instance * ins = chip->dsp_spos_instance;
if ( ins->spdif_status_out & DSP_SPDIF_STATUS_PLAYBACK_OPEN) {
ins->spdif_status_out &= ~DSP_SPDIF_STATUS_OUTPUT_ENABLED;
return -EBUSY;
}
if (snd_BUG_ON(!ins->asynch_tx_scb))
return -EINVAL;
if (snd_BUG_ON(!ins->spdif_pcm_input_scb))
return -EINVAL;
if (snd_BUG_ON(ins->master_mix_scb->next_scb_ptr != ins->asynch_tx_scb))
return -EINVAL;
if (snd_BUG_ON(ins->asynch_tx_scb->parent_scb_ptr !=
ins->master_mix_scb))
return -EINVAL;
cs46xx_dsp_remove_scb (chip,ins->spdif_pcm_input_scb);
cs46xx_dsp_remove_scb (chip,ins->asynch_tx_scb);
ins->spdif_pcm_input_scb = NULL;
ins->asynch_tx_scb = NULL;
_dsp_clear_sample_buffer(chip,SPDIFO_IP_OUTPUT_BUFFER1,256);
ins->spdif_status_out &= ~DSP_SPDIF_STATUS_OUTPUT_ENABLED;
return 0;
}
int cs46xx_iec958_pre_open (struct snd_cs46xx *chip)
{
struct dsp_spos_instance * ins = chip->dsp_spos_instance;
if ( ins->spdif_status_out & DSP_SPDIF_STATUS_OUTPUT_ENABLED ) {
cs46xx_dsp_disable_spdif_out (chip);
ins->spdif_status_out |= DSP_SPDIF_STATUS_OUTPUT_ENABLED;
}
if ( !(ins->spdif_status_out & DSP_SPDIF_STATUS_HW_ENABLED) ) {
cs46xx_dsp_enable_spdif_hw (chip);
}
ins->asynch_tx_scb = cs46xx_dsp_create_asynch_fg_tx_scb(chip,"AsynchFGTxSCB",ASYNCTX_SCB_ADDR,
SPDIFO_SCB_INST,
SPDIFO_IP_OUTPUT_BUFFER1,
ins->master_mix_scb,
SCB_ON_PARENT_NEXT_SCB);
cs46xx_poke_via_dsp (chip,SP_SPDOUT_CSUV, ins->spdif_csuv_stream);
ins->spdif_status_out |= DSP_SPDIF_STATUS_PLAYBACK_OPEN;
return 0;
}
int cs46xx_iec958_post_close (struct snd_cs46xx *chip)
{
struct dsp_spos_instance * ins = chip->dsp_spos_instance;
if (snd_BUG_ON(!ins->asynch_tx_scb))
return -EINVAL;
ins->spdif_status_out &= ~DSP_SPDIF_STATUS_PLAYBACK_OPEN;
cs46xx_poke_via_dsp (chip,SP_SPDOUT_CSUV, ins->spdif_csuv_default);
if (ins->spdif_pcm_input_scb != NULL) {
cs46xx_dsp_remove_scb (chip,ins->spdif_pcm_input_scb);
ins->spdif_pcm_input_scb = NULL;
}
cs46xx_dsp_remove_scb (chip,ins->asynch_tx_scb);
ins->asynch_tx_scb = NULL;
_dsp_clear_sample_buffer(chip,SPDIFO_IP_OUTPUT_BUFFER1,256);
if ( ins->spdif_status_out & DSP_SPDIF_STATUS_OUTPUT_ENABLED ) {
cs46xx_dsp_enable_spdif_out (chip);
}
return 0;
}
