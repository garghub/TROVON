static void F_1 ( struct V_1 * V_2 )
{
F_2 ( V_2 , V_2 -> V_3 . V_4 &= ~ 0x20 ) ;
}
static void F_3 ( struct V_1 * V_2 )
{
F_2 ( V_2 , V_2 -> V_3 . V_4 &= ~ 0x80 ) ;
}
static void F_4 ( struct V_1 * V_2 )
{
F_5 ( V_2 , V_5 , V_2 -> V_3 . V_6 &= ~ 4 ) ;
}
static void F_6 ( struct V_1 * V_2 )
{
F_5 ( V_2 , V_5 , V_2 -> V_3 . V_6 &= ~ 8 ) ;
}
static void F_7 ( struct V_1 * V_2 , struct V_7 * V_8 )
{
F_8 ( V_2 , 0x00 ) ;
F_8 ( V_2 , 0x0d ) ;
}
static void F_9 ( struct V_1 * V_2 )
{
F_5 ( V_2 , 0x41 , 0x00 ) ;
}
static void F_10 ( struct V_1 * V_2 )
{
F_5 ( V_2 , 0x49 , 0x00 ) ;
}
void F_11 ( struct V_1 * V_2 , unsigned int V_9 )
{
if ( V_9 & V_10 )
V_2 -> V_3 . V_11 = F_1 ;
if ( V_9 & V_12 )
V_2 -> V_3 . V_13 = F_3 ;
if ( V_9 & V_14 )
V_2 -> V_3 . V_15 = F_4 ;
if ( V_9 & V_16 )
V_2 -> V_3 . V_17 = F_6 ;
if ( V_9 & V_18 ) {
struct V_7 * V_8 ;
V_8 = & V_2 -> V_3 . V_19 [ V_9 & 0xffff ] ;
V_8 -> V_20 =
V_8 -> V_21 = F_7 ;
V_8 -> V_22 = NULL ;
V_8 -> V_23 = NULL ;
}
if ( V_9 & V_24 )
V_2 -> V_3 . V_25 = F_9 ;
if ( V_9 & V_26 )
V_2 -> V_3 . V_27 = F_10 ;
}
static void F_12 ( struct V_1 * V_2 )
{
unsigned long V_28 ;
F_13 ( & V_2 -> V_29 , V_28 ) ;
F_14 ( F_15 ( V_2 , V_30 ) ) ;
F_16 ( V_2 , 0x41 , 0 ) ;
F_16 ( V_2 , 0x45 , 0 ) ;
F_16 ( V_2 , 0x49 , 0 ) ;
F_17 ( & V_2 -> V_29 , V_28 ) ;
}
static void F_18 ( struct V_1 * V_2 )
{
unsigned long V_28 ;
F_13 ( & V_2 -> V_29 , V_28 ) ;
F_19 ( V_2 , 0x41 ) ;
F_19 ( V_2 , 0x49 ) ;
F_14 ( F_15 ( V_2 , V_30 ) ) ;
F_20 ( V_2 , 0x0f ) ;
F_17 ( & V_2 -> V_29 , V_28 ) ;
}
void F_21 ( struct V_1 * V_2 , unsigned short V_8 )
{
unsigned long V_28 ;
F_13 ( & V_2 -> V_29 , V_28 ) ;
F_22 ( V_2 , V_8 ) ;
#if 0
printk(KERN_DEBUG " -%i- smart stop voice - volume = 0x%x\n", voice, snd_gf1_i_read16(gus, SNDRV_GF1_VW_VOLUME));
#endif
F_23 ( V_2 , V_31 ) ;
F_23 ( V_2 , V_32 ) ;
F_17 ( & V_2 -> V_29 , V_28 ) ;
}
void F_24 ( struct V_1 * V_2 , unsigned short V_8 )
{
unsigned long V_28 ;
F_13 ( & V_2 -> V_29 , V_28 ) ;
F_22 ( V_2 , V_8 ) ;
#if 0
printk(KERN_DEBUG " -%i- stop voice - volume = 0x%x\n", voice, snd_gf1_i_read16(gus, SNDRV_GF1_VW_VOLUME));
#endif
F_23 ( V_2 , V_31 ) ;
F_23 ( V_2 , V_32 ) ;
if ( V_2 -> V_3 . V_33 )
F_16 ( V_2 , V_34 , 0 ) ;
F_17 ( & V_2 -> V_29 , V_28 ) ;
#if 0
snd_gf1_lfo_shutdown(gus, voice, ULTRA_LFO_VIBRATO);
snd_gf1_lfo_shutdown(gus, voice, ULTRA_LFO_TREMOLO);
#endif
}
static void F_25 ( struct V_1 * V_2 , unsigned short V_35 ,
unsigned short V_36 )
{
unsigned long V_28 ;
unsigned int V_37 ;
unsigned short V_38 , V_39 ;
V_37 = V_2 -> V_3 . V_40 << 4 ;
for ( V_38 = V_35 ; V_38 <= V_36 ; V_38 ++ ) {
#if 0
if (gus->gf1.syn_voices)
gus->gf1.syn_voices[i].flags = ~VFLG_DYNAMIC;
#endif
F_13 ( & V_2 -> V_29 , V_28 ) ;
F_22 ( V_2 , V_38 ) ;
F_23 ( V_2 , V_31 ) ;
F_23 ( V_2 , V_32 ) ;
if ( V_2 -> V_3 . V_33 )
F_16 ( V_2 , V_41 , V_2 -> V_3 . V_42 ? 0x02 : 0x82 ) ;
V_39 = F_20 ( V_2 , V_31 ) & 0x04 ;
F_26 ( V_2 , V_43 , 0x400 ) ;
F_27 ( V_2 , V_44 , V_37 , V_39 ) ;
F_27 ( V_2 , V_45 , V_37 , V_39 ) ;
F_16 ( V_2 , V_46 , 0 ) ;
F_16 ( V_2 , V_47 , 0 ) ;
F_16 ( V_2 , V_48 , 0 ) ;
F_26 ( V_2 , V_49 , 0 ) ;
F_27 ( V_2 , V_50 , V_37 , V_39 ) ;
F_16 ( V_2 , V_51 , 7 ) ;
if ( V_2 -> V_3 . V_33 ) {
F_16 ( V_2 , V_34 , 0 ) ;
F_26 ( V_2 , V_52 , 0 ) ;
F_26 ( V_2 , V_53 , 0 ) ;
}
F_17 ( & V_2 -> V_29 , V_28 ) ;
#if 0
snd_gf1_lfo_shutdown(gus, i, ULTRA_LFO_VIBRATO);
snd_gf1_lfo_shutdown(gus, i, ULTRA_LFO_TREMOLO);
#endif
}
}
void F_28 ( struct V_1 * V_2 , unsigned short V_35 , unsigned short V_36 )
{
unsigned long V_28 ;
short V_38 , V_54 ;
unsigned short V_55 ;
if ( ! F_29 () ) {
for ( V_38 = V_35 , V_54 = 0 ; V_38 <= V_36 ; V_38 ++ ) {
F_13 ( & V_2 -> V_29 , V_28 ) ;
F_22 ( V_2 , V_38 ) ;
V_55 = F_30 ( V_2 , 9 ) >> 8 ;
if ( V_55 > V_56 ) {
V_54 ++ ;
F_16 ( V_2 , V_48 , 20 ) ;
F_16 ( V_2 , V_46 , V_56 ) ;
F_16 ( V_2 , V_47 , V_55 ) ;
F_16 ( V_2 , V_32 , 0x40 ) ;
if ( V_2 -> V_3 . V_33 ) {
F_31 ( V_2 ) ;
F_16 ( V_2 , V_32 , 0x40 ) ;
}
}
F_17 ( & V_2 -> V_29 , V_28 ) ;
}
F_32 ( 50 ) ;
}
F_25 ( V_2 , V_35 , V_36 ) ;
}
static void F_33 ( struct V_1 * V_2 ,
struct V_7 * V_57 ,
int type , int V_58 , int V_59 )
{
V_57 -> V_60 = 1 ;
switch ( type ) {
case V_61 :
V_2 -> V_3 . V_62 ++ ;
V_57 -> V_63 = 1 ;
break;
case V_64 :
V_57 -> V_65 = 1 ;
V_57 -> V_58 = V_58 ;
V_57 -> V_59 = V_59 ;
break;
case V_66 :
V_57 -> V_67 = 1 ;
V_57 -> V_58 = V_58 ;
V_57 -> V_59 = V_59 ;
break;
}
}
struct V_7 * F_34 ( struct V_1 * V_2 , int type , int V_58 , int V_59 )
{
struct V_7 * V_57 ;
unsigned long V_28 ;
int V_68 ;
F_13 ( & V_2 -> V_69 , V_28 ) ;
if ( type == V_61 ) {
if ( V_2 -> V_3 . V_62 >= V_2 -> V_3 . V_70 ) {
F_17 ( & V_2 -> V_69 , V_28 ) ;
return NULL ;
}
}
for ( V_68 = 0 ; V_68 < 32 ; V_68 ++ ) {
V_57 = & V_2 -> V_3 . V_19 [ V_68 ] ;
if ( ! V_57 -> V_60 ) {
F_33 ( V_2 , V_57 , type , V_58 , V_59 ) ;
F_17 ( & V_2 -> V_69 , V_28 ) ;
return V_57 ;
}
}
for ( V_68 = 0 ; V_68 < 32 ; V_68 ++ ) {
V_57 = & V_2 -> V_3 . V_19 [ V_68 ] ;
if ( V_57 -> V_67 && ! V_57 -> V_58 ) {
F_25 ( V_2 , V_57 -> V_71 , V_57 -> V_71 ) ;
F_33 ( V_2 , V_57 , type , V_58 , V_59 ) ;
F_17 ( & V_2 -> V_69 , V_28 ) ;
return V_57 ;
}
}
F_17 ( & V_2 -> V_69 , V_28 ) ;
return NULL ;
}
void F_35 ( struct V_1 * V_2 , struct V_7 * V_8 )
{
unsigned long V_28 ;
void (* F_36)( struct V_7 * V_8 );
void * V_72 ;
if ( V_8 == NULL || ! V_8 -> V_60 )
return;
F_11 ( V_2 , V_18 | V_8 -> V_71 ) ;
F_25 ( V_2 , V_8 -> V_71 , V_8 -> V_71 ) ;
F_13 ( & V_2 -> V_69 , V_28 ) ;
F_36 = V_8 -> F_36 ;
V_72 = V_8 -> V_72 ;
V_8 -> F_36 = NULL ;
V_8 -> V_72 = NULL ;
if ( V_8 -> V_63 )
V_2 -> V_3 . V_62 -- ;
V_8 -> V_60 = V_8 -> V_63 = 0 ;
V_8 -> V_73 = NULL ;
F_17 ( & V_2 -> V_69 , V_28 ) ;
if ( F_36 )
F_36 ( V_8 ) ;
}
int F_37 ( struct V_1 * V_2 )
{
unsigned long V_28 ;
unsigned int V_38 ;
F_5 ( V_2 , V_74 , 0 ) ;
F_38 ( 160 ) ;
F_5 ( V_2 , V_74 , 1 ) ;
F_38 ( 160 ) ;
F_5 ( V_2 , V_75 , V_2 -> V_76 ) ;
F_11 ( V_2 , V_77 ) ;
for ( V_38 = 0 ; V_38 < 32 ; V_38 ++ ) {
V_2 -> V_3 . V_19 [ V_38 ] . V_71 = V_38 ;
F_11 ( V_2 , V_18 | V_38 ) ;
}
F_2 ( V_2 , 0x03 ) ;
if ( V_2 -> V_3 . V_33 ) {
F_5 ( V_2 , V_78 , F_39 ( V_2 , V_78 ) | 0x01 ) ;
F_5 ( V_2 , V_79 , 0x01 ) ;
}
F_12 ( V_2 ) ;
F_40 ( V_2 ) ;
F_31 ( V_2 ) ;
V_2 -> V_3 . V_40 = V_2 -> V_3 . V_42 > 0 ? 0 : 512 - 8 ;
if ( V_2 -> V_3 . V_33 && V_2 -> V_3 . V_42 ) {
V_2 -> V_3 . V_80 = 1 ;
V_2 -> V_3 . V_40 += 1024 ;
} else {
V_2 -> V_3 . V_81 = 1 ;
}
#if 0
snd_gf1_lfo_init(gus);
#endif
if ( V_2 -> V_3 . V_42 > 0 )
for ( V_38 = 0 ; V_38 < 4 ; V_38 ++ )
F_41 ( V_2 , V_2 -> V_3 . V_40 + V_38 , 0 ) ;
F_12 ( V_2 ) ;
F_25 ( V_2 , 0 , 31 ) ;
F_18 ( V_2 ) ;
F_38 ( 160 ) ;
F_5 ( V_2 , V_74 , 7 ) ;
F_38 ( 160 ) ;
F_5 ( V_2 , V_74 , 7 ) ;
if ( V_2 -> V_3 . V_33 ) {
F_5 ( V_2 , V_78 , F_39 ( V_2 , V_78 ) | 0x01 ) ;
F_5 ( V_2 , V_79 , 0x01 ) ;
}
while ( ( F_42 ( V_2 , V_82 ) & 0xc0 ) != 0xc0 ) ;
F_13 ( & V_2 -> V_29 , V_28 ) ;
F_43 ( V_2 -> V_3 . V_83 = 0 , F_15 ( V_2 , V_84 ) ) ;
F_43 ( V_2 -> V_85 , F_15 ( V_2 , V_86 ) ) ;
F_17 ( & V_2 -> V_29 , V_28 ) ;
F_44 ( V_2 ) ;
F_18 ( V_2 ) ;
F_45 ( V_2 ) ;
F_46 ( V_2 ) ;
#ifdef F_47
F_48 ( V_2 ) ;
#endif
#if 0
if (gus->pnp_flag) {
if (gus->chip.playback_fifo_size > 0)
snd_gf1_i_write16(gus, SNDRV_GF1_GW_FIFO_RECORD_BASE_ADDR, gus->chip.playback_fifo_block->ptr >> 8);
if (gus->chip.record_fifo_size > 0)
snd_gf1_i_write16(gus, SNDRV_GF1_GW_FIFO_PLAY_BASE_ADDR, gus->chip.record_fifo_block->ptr >> 8);
snd_gf1_i_write16(gus, SNDRV_GF1_GW_FIFO_SIZE, gus->chip.interwave_fifo_reg);
}
#endif
return 0 ;
}
int F_49 ( struct V_1 * V_2 )
{
F_5 ( V_2 , V_5 , 0 ) ;
F_28 ( V_2 , 0 , 31 ) ;
F_5 ( V_2 , V_74 , 1 ) ;
F_50 ( V_2 ) ;
F_51 ( V_2 ) ;
#if 0
snd_gf1_lfo_done(gus);
#endif
return 0 ;
}
