static void F_1 ( struct V_1 * V_2 , void * V_3 )
{
struct V_4 * V_5 = V_3 ;
if ( V_5 ) {
F_2 ( & V_5 -> V_6 ) ;
F_3 ( & V_5 -> V_7 ) ;
}
}
static int F_4 ( struct V_8 * V_9 ,
unsigned int V_10 ,
unsigned int V_11 ,
unsigned int V_12 )
{
struct V_13 V_14 ;
struct V_15 * V_16 = V_9 -> V_16 ;
struct V_4 * V_5 = V_16 -> V_3 ;
V_12 += V_10 & 31 ;
V_10 &= ~ 31 ;
memset ( & V_14 , 0 , sizeof( V_14 ) ) ;
V_14 . V_17 = V_18 ;
if ( F_5 ( V_16 -> V_19 ) )
V_14 . V_17 |= V_20 ;
if ( F_6 ( V_16 -> V_19 ) == 16 )
V_14 . V_17 |= V_21 ;
V_14 . V_11 = V_11 & ~ 31 ;
V_14 . V_22 = V_16 -> V_23 + V_10 ;
V_14 . V_24 = V_16 -> V_25 + V_10 ;
V_14 . V_12 = V_12 ;
V_14 . V_3 = V_5 ;
V_14 . V_26 = F_1 ;
if ( ! F_7 ( V_5 -> V_2 , & V_14 , 0 , 0 ) )
F_8 ( & V_5 -> V_6 ) ;
return 0 ;
}
static void F_9 ( struct V_8 * V_9 )
{
struct V_15 * V_16 = V_9 -> V_16 ;
struct V_4 * V_5 = V_16 -> V_3 ;
struct V_1 * V_2 = V_5 -> V_2 ;
unsigned long V_27 ;
unsigned char V_28 , V_29 ;
unsigned short V_30 ;
unsigned int V_31 , V_32 , V_33 ;
unsigned short V_34 ;
unsigned char V_35 ;
unsigned int V_36 ;
F_10 ( & V_5 -> V_37 , V_27 ) ;
if ( V_5 -> V_27 & V_38 ) {
F_11 ( & V_5 -> V_37 , V_27 ) ;
return;
}
V_5 -> V_27 |= V_38 ;
V_5 -> V_39 = 0 ;
F_11 ( & V_5 -> V_37 , V_27 ) ;
V_30 = F_12 ( V_2 , V_16 -> V_30 << 4 ) ;
V_28 = F_6 ( V_16 -> V_19 ) == 16 ? 0x24 : 0x20 ;
V_29 = 0x24 ;
if ( V_5 -> V_40 == 1 ) {
V_28 |= 0x08 ;
V_29 &= ~ 0x04 ;
}
for ( V_36 = 0 ; V_36 < V_5 -> V_41 ; V_36 ++ ) {
V_32 = V_5 -> V_42 + V_36 * ( V_5 -> V_43 / V_16 -> V_44 ) ;
V_31 = V_32 + ( V_5 -> V_45 * V_5 -> V_46 ) / V_16 -> V_44 ;
V_33 = V_31 + ( V_5 -> V_46 / V_16 -> V_44 ) ;
V_33 -= F_6 ( V_16 -> V_19 ) == 16 ? 2 : 1 ;
V_35 = V_16 -> V_44 == 2 ? ( ! V_36 ? 1 : 14 ) : 8 ;
V_34 = ! V_36 ? V_2 -> V_47 . V_48 : V_2 -> V_47 . V_49 ;
F_10 ( & V_2 -> V_50 , V_27 ) ;
F_13 ( V_2 , V_5 -> V_51 [ V_36 ] -> V_52 ) ;
F_14 ( V_2 , V_53 , V_35 ) ;
F_15 ( V_2 , V_54 , V_30 ) ;
F_16 ( V_2 , V_55 , V_32 << 4 , V_28 & 4 ) ;
F_16 ( V_2 , V_56 , V_33 << 4 , V_28 & 4 ) ;
F_16 ( V_2 , V_57 , V_31 << 4 , V_28 & 4 ) ;
F_15 ( V_2 , V_58 , V_59 << 4 ) ;
F_14 ( V_2 , V_60 , 0x2f ) ;
F_14 ( V_2 , V_61 , V_62 ) ;
F_14 ( V_2 , V_63 , V_34 >> 8 ) ;
F_14 ( V_2 , V_64 , V_29 ) ;
if ( ! V_2 -> V_47 . V_65 ) {
F_17 ( V_2 ) ;
F_14 ( V_2 , V_64 , V_29 ) ;
}
F_11 ( & V_2 -> V_50 , V_27 ) ;
}
F_10 ( & V_2 -> V_50 , V_27 ) ;
for ( V_36 = 0 ; V_36 < V_5 -> V_41 ; V_36 ++ ) {
F_13 ( V_2 , V_5 -> V_51 [ V_36 ] -> V_52 ) ;
if ( V_2 -> V_47 . V_65 )
F_14 ( V_2 , V_66 , 0x00 ) ;
F_14 ( V_2 , V_67 , V_28 ) ;
V_28 &= ~ 0x20 ;
}
V_28 |= 0x20 ;
if ( ! V_2 -> V_47 . V_65 ) {
F_17 ( V_2 ) ;
for ( V_36 = 0 ; V_36 < V_5 -> V_41 ; V_36 ++ ) {
F_13 ( V_2 , V_5 -> V_51 [ V_36 ] -> V_52 ) ;
F_14 ( V_2 , V_67 , V_28 ) ;
V_28 &= ~ 0x20 ;
}
}
F_11 ( & V_2 -> V_50 , V_27 ) ;
}
static void F_18 ( struct V_1 * V_2 ,
struct V_68 * V_69 )
{
struct V_4 * V_5 ;
struct V_15 * V_16 ;
unsigned char V_28 , V_29 ;
unsigned int V_70 ;
unsigned int V_33 , V_71 ;
if ( ! V_69 -> V_3 ) {
F_19 ( L_1 ) ;
F_20 ( V_2 , V_69 -> V_52 ) ;
return;
}
V_5 = V_69 -> V_3 ;
if ( V_5 == NULL ) {
F_19 ( L_1 ) ;
F_20 ( V_2 , V_69 -> V_52 ) ;
return;
}
V_2 = V_5 -> V_2 ;
V_16 = V_5 -> V_9 -> V_16 ;
F_21 ( & V_2 -> V_50 ) ;
F_13 ( V_2 , V_69 -> V_52 ) ;
V_28 = F_22 ( V_2 , V_67 ) & ~ 0x8b ;
V_29 = ( F_22 ( V_2 , V_64 ) & ~ 0xa4 ) | 0x03 ;
#if 0
snd_gf1_select_voice(gus, pvoice->number);
printk(KERN_DEBUG "position = 0x%x\n",
(snd_gf1_read_addr(gus, SNDRV_GF1_VA_CURRENT, voice_ctrl & 4) >> 4));
snd_gf1_select_voice(gus, pcmp->pvoices[1]->number);
printk(KERN_DEBUG "position = 0x%x\n",
(snd_gf1_read_addr(gus, SNDRV_GF1_VA_CURRENT, voice_ctrl & 4) >> 4));
snd_gf1_select_voice(gus, pvoice->number);
#endif
V_5 -> V_45 ++ ;
V_5 -> V_45 %= V_5 -> V_40 ;
if ( V_5 -> V_45 + 1 >= V_5 -> V_40 ) {
V_28 |= 0x08 ;
} else {
V_29 |= 0x04 ;
}
V_33 = V_5 -> V_42 + ( ( ( V_5 -> V_45 + 1 ) * V_5 -> V_46 ) / V_16 -> V_44 ) ;
V_33 -= V_28 & 4 ? 2 : 1 ;
V_71 = V_5 -> V_43 / V_16 -> V_44 ;
V_28 |= 0x20 ;
if ( ! V_5 -> V_39 ) {
V_29 |= 0x20 ;
V_29 &= ~ 0x03 ;
}
for ( V_70 = 0 ; V_70 < V_5 -> V_41 ; V_70 ++ , V_33 += V_71 ) {
F_13 ( V_2 , V_5 -> V_51 [ V_70 ] -> V_52 ) ;
F_16 ( V_2 , V_56 , V_33 << 4 , V_28 & 4 ) ;
F_14 ( V_2 , V_67 , V_28 ) ;
F_14 ( V_2 , V_64 , V_29 ) ;
V_28 &= ~ 0x20 ;
}
if ( ! V_2 -> V_47 . V_65 ) {
F_17 ( V_2 ) ;
V_28 |= 0x20 ;
for ( V_70 = 0 ; V_70 < V_5 -> V_41 ; V_70 ++ ) {
F_13 ( V_2 , V_5 -> V_51 [ V_70 ] -> V_52 ) ;
F_14 ( V_2 , V_67 , V_28 ) ;
F_14 ( V_2 , V_64 , V_29 ) ;
V_28 &= ~ 0x20 ;
}
}
F_23 ( & V_2 -> V_50 ) ;
F_24 ( V_5 -> V_9 ) ;
#if 0
if ((runtime->flags & SNDRV_PCM_FLG_MMAP) &&
*runtime->state == SNDRV_PCM_STATE_RUNNING) {
end = pcmp->bpos * pcmp->block_size;
if (runtime->channels > 1) {
snd_gf1_pcm_block_change(pcmp->substream, end, pcmp->memory + (end / 2), pcmp->block_size / 2);
snd_gf1_pcm_block_change(pcmp->substream, end + (pcmp->block_size / 2), pcmp->memory + (pcmp->dma_size / 2) + (end / 2), pcmp->block_size / 2);
} else {
snd_gf1_pcm_block_change(pcmp->substream, end, pcmp->memory + end, pcmp->block_size);
}
}
#endif
}
static void F_25 ( struct V_1 * V_2 ,
struct V_68 * V_69 )
{
unsigned short V_34 ;
int V_72 ;
struct V_4 * V_5 = V_69 -> V_3 ;
F_21 ( & V_2 -> V_50 ) ;
F_13 ( V_2 , V_69 -> V_52 ) ;
F_26 ( V_2 , V_64 ) ;
F_23 ( & V_2 -> V_50 ) ;
if ( V_5 == NULL )
return;
if ( ! ( V_5 -> V_27 & V_38 ) )
return;
V_72 = V_5 -> V_51 [ 0 ] == V_69 ? 0 : 1 ;
if ( V_5 -> V_9 == NULL )
return;
V_34 = ! V_72 ? V_2 -> V_47 . V_48 : V_2 -> V_47 . V_49 ;
F_21 ( & V_2 -> V_50 ) ;
F_13 ( V_2 , V_69 -> V_52 ) ;
F_15 ( V_2 , V_58 , V_34 ) ;
V_5 -> V_39 = 1 ;
F_23 ( & V_2 -> V_50 ) ;
}
static void F_27 ( struct V_1 * V_2 )
{
}
static int F_28 ( struct V_1 * V_2 , unsigned char * V_73 ,
unsigned int V_74 , unsigned int V_12 ,
int V_75 , int V_76 )
{
unsigned int V_77 ;
unsigned long V_27 ;
while ( V_12 > 0 ) {
V_77 = V_12 ;
if ( V_77 > 512 )
V_77 = 512 ;
V_12 -= V_77 ;
if ( V_2 -> V_78 ) {
F_10 ( & V_2 -> V_50 , V_27 ) ;
F_14 ( V_2 , V_79 , 0x01 | ( V_76 ? 0x08 : 0x00 ) ) ;
F_29 ( V_2 , V_74 ) ;
if ( V_75 ) {
F_30 ( V_80 , F_31 ( V_2 , V_81 ) ) ;
F_32 ( F_31 ( V_2 , V_82 ) , V_73 , V_77 >> 1 ) ;
} else {
F_33 ( F_31 ( V_2 , V_83 ) , V_73 , V_77 ) ;
}
F_11 ( & V_2 -> V_50 , V_27 ) ;
V_73 += 512 ;
V_74 += 512 ;
} else {
V_76 = V_76 ? 0x80 : 0x00 ;
if ( V_75 ) {
V_77 >>= 1 ;
while ( V_77 -- ) {
F_34 ( V_2 , V_74 ++ , * V_73 ++ ) ;
F_34 ( V_2 , V_74 ++ , * V_73 ++ ^ V_76 ) ;
}
} else {
while ( V_77 -- )
F_34 ( V_2 , V_74 ++ , * V_73 ++ ^ V_76 ) ;
}
}
if ( V_12 > 0 && ! F_35 () ) {
F_36 ( 1 ) ;
if ( F_37 ( V_84 ) )
return - V_85 ;
}
}
return 0 ;
}
static int F_38 ( struct V_4 * V_5 , int V_36 , unsigned int V_74 ,
unsigned int V_77 )
{
unsigned int V_45 = V_74 + ( V_36 * ( V_5 -> V_43 / 2 ) ) ;
if ( F_39 ( V_45 > V_5 -> V_43 ) )
return - V_86 ;
if ( F_39 ( V_45 + V_77 > V_5 -> V_43 ) )
return - V_86 ;
return V_45 ;
}
static int F_40 ( struct V_8 * V_9 ,
unsigned int V_45 , unsigned int V_77 )
{
struct V_15 * V_16 = V_9 -> V_16 ;
struct V_4 * V_5 = V_16 -> V_3 ;
struct V_1 * V_2 = V_5 -> V_2 ;
int V_75 , V_76 ;
if ( V_77 > 32 )
return F_4 ( V_9 , V_45 ,
V_5 -> V_42 + V_45 , V_77 ) ;
V_75 = ( F_6 ( V_16 -> V_19 ) == 16 ) ;
V_76 = F_5 ( V_16 -> V_19 ) ;
return F_28 ( V_2 , V_16 -> V_23 + V_45 ,
V_5 -> V_42 + V_45 , V_77 , V_75 , V_76 ) ;
}
static int F_41 ( struct V_8 * V_9 ,
int V_36 , unsigned long V_74 ,
void T_1 * V_87 , unsigned long V_12 )
{
struct V_15 * V_16 = V_9 -> V_16 ;
struct V_4 * V_5 = V_16 -> V_3 ;
unsigned int V_77 = V_12 ;
int V_45 ;
V_45 = F_38 ( V_5 , V_36 , V_74 , V_77 ) ;
if ( V_45 < 0 )
return V_74 ;
if ( F_42 ( V_16 -> V_23 + V_45 , V_87 , V_77 ) )
return - V_88 ;
return F_40 ( V_9 , V_45 , V_77 ) ;
}
static int F_43 ( struct V_8 * V_9 ,
int V_36 , unsigned long V_74 ,
void * V_87 , unsigned long V_12 )
{
struct V_15 * V_16 = V_9 -> V_16 ;
struct V_4 * V_5 = V_16 -> V_3 ;
unsigned int V_77 = V_12 ;
int V_45 ;
V_45 = F_38 ( V_5 , V_36 , V_74 , V_77 ) ;
if ( V_45 < 0 )
return V_74 ;
memcpy ( V_16 -> V_23 + V_45 , V_87 , V_77 ) ;
return F_40 ( V_9 , V_45 , V_77 ) ;
}
static int F_44 ( struct V_8 * V_9 ,
int V_36 , unsigned long V_74 ,
unsigned long V_12 )
{
struct V_15 * V_16 = V_9 -> V_16 ;
struct V_4 * V_5 = V_16 -> V_3 ;
unsigned int V_77 = V_12 ;
int V_45 ;
V_45 = F_38 ( V_5 , V_36 , V_74 , V_77 ) ;
if ( V_45 < 0 )
return V_74 ;
F_45 ( V_16 -> V_19 , V_16 -> V_23 + V_45 ,
F_46 ( V_16 , V_12 ) ) ;
return F_40 ( V_9 , V_45 , V_77 ) ;
}
static int F_47 ( struct V_8 * V_9 ,
struct V_89 * V_90 )
{
struct V_1 * V_2 = F_48 ( V_9 ) ;
struct V_15 * V_16 = V_9 -> V_16 ;
struct V_4 * V_5 = V_16 -> V_3 ;
int V_91 ;
if ( ( V_91 = F_49 ( V_9 , F_50 ( V_90 ) ) ) < 0 )
return V_91 ;
if ( V_91 > 0 ) {
struct V_92 * V_14 ;
if ( V_5 -> V_42 > 0 ) {
F_51 ( & V_2 -> V_47 . V_93 , V_5 -> V_42 ) ;
V_5 -> V_42 = 0 ;
}
if ( ( V_14 = F_52 ( & V_2 -> V_47 . V_93 ,
V_94 ,
L_2 ,
V_16 -> V_95 , 1 , 32 ,
NULL ) ) == NULL )
return - V_96 ;
V_5 -> V_42 = V_14 -> V_97 ;
}
V_5 -> V_41 = F_53 ( V_90 ) ;
if ( V_5 -> V_51 [ 0 ] == NULL ) {
if ( ( V_5 -> V_51 [ 0 ] = F_54 ( V_5 -> V_2 , V_98 , 0 , 0 ) ) == NULL )
return - V_96 ;
V_5 -> V_51 [ 0 ] -> V_99 = F_18 ;
V_5 -> V_51 [ 0 ] -> V_100 = F_25 ;
V_5 -> V_51 [ 0 ] -> V_101 = F_27 ;
V_5 -> V_51 [ 0 ] -> V_3 = V_5 ;
}
if ( V_5 -> V_41 > 1 && V_5 -> V_51 [ 1 ] == NULL ) {
if ( ( V_5 -> V_51 [ 1 ] = F_54 ( V_5 -> V_2 , V_98 , 0 , 0 ) ) == NULL )
return - V_96 ;
V_5 -> V_51 [ 1 ] -> V_99 = F_18 ;
V_5 -> V_51 [ 1 ] -> V_100 = F_25 ;
V_5 -> V_51 [ 1 ] -> V_101 = F_27 ;
V_5 -> V_51 [ 1 ] -> V_3 = V_5 ;
} else if ( V_5 -> V_41 == 1 ) {
if ( V_5 -> V_51 [ 1 ] ) {
F_55 ( V_5 -> V_2 , V_5 -> V_51 [ 1 ] ) ;
V_5 -> V_51 [ 1 ] = NULL ;
}
}
return 0 ;
}
static int F_56 ( struct V_8 * V_9 )
{
struct V_15 * V_16 = V_9 -> V_16 ;
struct V_4 * V_5 = V_16 -> V_3 ;
F_57 ( V_9 ) ;
if ( V_5 -> V_51 [ 0 ] ) {
F_55 ( V_5 -> V_2 , V_5 -> V_51 [ 0 ] ) ;
V_5 -> V_51 [ 0 ] = NULL ;
}
if ( V_5 -> V_51 [ 1 ] ) {
F_55 ( V_5 -> V_2 , V_5 -> V_51 [ 1 ] ) ;
V_5 -> V_51 [ 1 ] = NULL ;
}
if ( V_5 -> V_42 > 0 ) {
F_51 ( & V_5 -> V_2 -> V_47 . V_93 , V_5 -> V_42 ) ;
V_5 -> V_42 = 0 ;
}
return 0 ;
}
static int F_58 ( struct V_8 * V_9 )
{
struct V_15 * V_16 = V_9 -> V_16 ;
struct V_4 * V_5 = V_16 -> V_3 ;
V_5 -> V_45 = 0 ;
V_5 -> V_43 = F_59 ( V_9 ) ;
V_5 -> V_46 = F_60 ( V_9 ) ;
V_5 -> V_40 = V_5 -> V_43 / V_5 -> V_46 ;
return 0 ;
}
static int F_61 ( struct V_8 * V_9 ,
int V_17 )
{
struct V_1 * V_2 = F_48 ( V_9 ) ;
struct V_15 * V_16 = V_9 -> V_16 ;
struct V_4 * V_5 = V_16 -> V_3 ;
int V_36 ;
if ( V_17 == V_102 ) {
F_9 ( V_9 ) ;
} else if ( V_17 == V_103 ) {
F_21 ( & V_5 -> V_37 ) ;
V_5 -> V_27 &= ~ V_38 ;
F_23 ( & V_5 -> V_37 ) ;
V_36 = V_5 -> V_51 [ 0 ] -> V_52 ;
F_62 ( V_2 , V_36 , V_36 ) ;
if ( V_5 -> V_51 [ 1 ] ) {
V_36 = V_5 -> V_51 [ 1 ] -> V_52 ;
F_62 ( V_2 , V_36 , V_36 ) ;
}
} else {
return - V_104 ;
}
return 0 ;
}
static T_2 F_63 ( struct V_8 * V_9 )
{
struct V_1 * V_2 = F_48 ( V_9 ) ;
struct V_15 * V_16 = V_9 -> V_16 ;
struct V_4 * V_5 = V_16 -> V_3 ;
unsigned int V_74 ;
unsigned char V_28 ;
V_74 = 0 ;
F_21 ( & V_2 -> V_50 ) ;
if ( V_5 -> V_27 & V_38 ) {
F_13 ( V_2 , V_5 -> V_51 [ 0 ] -> V_52 ) ;
V_28 = F_22 ( V_2 , V_67 ) ;
V_74 = ( F_64 ( V_2 , V_57 , V_28 & 4 ) >> 4 ) - V_5 -> V_42 ;
if ( V_9 -> V_16 -> V_44 > 1 )
V_74 <<= 1 ;
V_74 = F_65 ( V_16 , V_74 ) ;
}
F_23 ( & V_2 -> V_50 ) ;
return V_74 ;
}
static int F_66 ( struct V_8 * V_9 ,
struct V_89 * V_90 )
{
struct V_1 * V_2 = F_48 ( V_9 ) ;
V_2 -> V_105 = F_50 ( V_90 ) ;
V_2 -> V_106 = F_67 ( V_90 ) ;
V_2 -> V_107 = 0 ;
V_2 -> V_47 . V_108 = 0x21 ;
if ( F_53 ( V_90 ) > 1 )
V_2 -> V_47 . V_108 |= 2 ;
if ( V_2 -> V_47 . V_109 > 3 )
V_2 -> V_47 . V_108 |= 4 ;
if ( F_5 ( F_68 ( V_90 ) ) )
V_2 -> V_47 . V_108 |= 0x80 ;
return F_49 ( V_9 , F_50 ( V_90 ) ) ;
}
static int F_69 ( struct V_8 * V_9 )
{
return F_57 ( V_9 ) ;
}
static int F_70 ( struct V_8 * V_9 )
{
struct V_1 * V_2 = F_48 ( V_9 ) ;
struct V_15 * V_16 = V_9 -> V_16 ;
F_71 ( V_2 , V_110 , V_16 -> V_111 - 2 ) ;
F_71 ( V_2 , V_112 , 0 ) ;
F_72 ( V_2 , V_112 ) ;
F_73 ( V_2 -> V_47 . V_109 , V_16 -> V_25 , V_2 -> V_106 , V_113 ) ;
return 0 ;
}
static int F_74 ( struct V_8 * V_9 ,
int V_17 )
{
struct V_1 * V_2 = F_48 ( V_9 ) ;
int V_114 ;
if ( V_17 == V_102 ) {
V_114 = V_2 -> V_47 . V_108 ;
} else if ( V_17 == V_103 ) {
V_114 = 0 ;
} else {
return - V_104 ;
}
F_21 ( & V_2 -> V_50 ) ;
F_14 ( V_2 , V_112 , V_114 ) ;
F_75 ( V_2 , V_112 ) ;
F_23 ( & V_2 -> V_50 ) ;
return 0 ;
}
static T_2 F_76 ( struct V_8 * V_9 )
{
struct V_1 * V_2 = F_48 ( V_9 ) ;
int V_74 = F_77 ( V_2 -> V_47 . V_109 , V_2 -> V_106 ) ;
V_74 = F_65 ( V_9 -> V_16 , ( V_2 -> V_107 + V_74 ) % V_2 -> V_105 ) ;
return V_74 ;
}
static void F_78 ( struct V_1 * V_2 )
{
F_71 ( V_2 , V_112 , 0 ) ;
F_72 ( V_2 , V_112 ) ;
if ( V_2 -> V_115 != NULL ) {
F_70 ( V_2 -> V_115 ) ;
F_74 ( V_2 -> V_115 , V_102 ) ;
V_2 -> V_107 += V_2 -> V_106 ;
F_24 ( V_2 -> V_115 ) ;
}
}
static void F_79 ( struct V_15 * V_16 )
{
F_80 ( V_16 -> V_3 ) ;
}
static int F_81 ( struct V_8 * V_9 )
{
struct V_4 * V_5 ;
struct V_1 * V_2 = F_48 ( V_9 ) ;
struct V_15 * V_16 = V_9 -> V_16 ;
int V_91 ;
V_5 = F_82 ( sizeof( * V_5 ) , V_116 ) ;
if ( V_5 == NULL )
return - V_96 ;
V_5 -> V_2 = V_2 ;
F_83 ( & V_5 -> V_37 ) ;
F_84 ( & V_5 -> V_7 ) ;
F_85 ( & V_5 -> V_6 , 0 ) ;
V_16 -> V_3 = V_5 ;
V_16 -> V_117 = F_79 ;
#if 0
printk(KERN_DEBUG "playback.buffer = 0x%lx, gf1.pcm_buffer = 0x%lx\n",
(long) pcm->playback.buffer, (long) gus->gf1.pcm_buffer);
#endif
if ( ( V_91 = F_86 ( V_2 ) ) < 0 )
return V_91 ;
V_5 -> V_27 = V_118 ;
V_5 -> V_9 = V_9 ;
V_16 -> V_119 = V_120 ;
F_87 ( V_2 -> V_47 . V_121 , & V_16 -> V_119 . V_122 ) ;
F_87 ( V_2 -> V_47 . V_121 , & V_16 -> V_119 . V_123 ) ;
F_88 ( V_16 , 0 , V_124 , 64 ) ;
return 0 ;
}
static int F_89 ( struct V_8 * V_9 )
{
struct V_1 * V_2 = F_48 ( V_9 ) ;
struct V_15 * V_16 = V_9 -> V_16 ;
struct V_4 * V_5 = V_16 -> V_3 ;
if ( ! F_90 ( V_5 -> V_7 , ( F_91 ( & V_5 -> V_6 ) <= 0 ) , 2 * V_125 ) )
F_92 ( V_126 L_3 ) ;
F_93 ( V_2 ) ;
return 0 ;
}
static int F_94 ( struct V_8 * V_9 )
{
struct V_15 * V_16 = V_9 -> V_16 ;
struct V_1 * V_2 = F_48 ( V_9 ) ;
V_2 -> V_47 . V_127 = F_78 ;
V_2 -> V_115 = V_9 ;
V_9 -> V_16 -> V_119 = V_128 ;
F_87 ( V_2 -> V_47 . V_109 , & V_16 -> V_119 . V_122 ) ;
F_87 ( V_2 -> V_47 . V_109 , & V_16 -> V_119 . V_123 ) ;
F_95 ( V_16 , 0 , V_129 ,
& V_130 ) ;
return 0 ;
}
static int F_96 ( struct V_8 * V_9 )
{
struct V_1 * V_2 = F_48 ( V_9 ) ;
V_2 -> V_115 = NULL ;
F_97 ( V_2 , V_131 ) ;
return 0 ;
}
static int F_98 ( struct V_132 * V_133 , struct V_134 * V_135 )
{
V_135 -> type = V_136 ;
V_135 -> V_12 = 2 ;
V_135 -> V_137 . integer . V_138 = 0 ;
V_135 -> V_137 . integer . V_139 = 127 ;
return 0 ;
}
static int F_99 ( struct V_132 * V_133 , struct V_140 * V_141 )
{
struct V_1 * V_2 = F_100 ( V_133 ) ;
unsigned long V_27 ;
F_10 ( & V_2 -> V_142 , V_27 ) ;
V_141 -> V_137 . integer . V_137 [ 0 ] = V_2 -> V_47 . V_143 ;
V_141 -> V_137 . integer . V_137 [ 1 ] = V_2 -> V_47 . V_144 ;
F_11 ( & V_2 -> V_142 , V_27 ) ;
return 0 ;
}
static int F_101 ( struct V_132 * V_133 , struct V_140 * V_141 )
{
struct V_1 * V_2 = F_100 ( V_133 ) ;
unsigned long V_27 ;
int V_145 ;
unsigned int V_70 ;
unsigned short V_146 , V_147 , V_34 ;
struct V_4 * V_5 ;
struct V_68 * V_69 ;
V_146 = V_141 -> V_137 . integer . V_137 [ 0 ] & 127 ;
V_147 = V_141 -> V_137 . integer . V_137 [ 1 ] & 127 ;
F_10 ( & V_2 -> V_142 , V_27 ) ;
V_145 = V_146 != V_2 -> V_47 . V_143 ||
V_147 != V_2 -> V_47 . V_144 ;
V_2 -> V_47 . V_143 = V_146 ;
V_2 -> V_47 . V_144 = V_147 ;
V_2 -> V_47 . V_48 = F_102 ( V_146 << 9 ) << 4 ;
V_2 -> V_47 . V_49 = F_102 ( V_147 << 9 ) << 4 ;
F_11 ( & V_2 -> V_142 , V_27 ) ;
F_10 ( & V_2 -> V_148 , V_27 ) ;
for ( V_70 = 0 ; V_70 < 32 ; V_70 ++ ) {
V_69 = & V_2 -> V_47 . V_41 [ V_70 ] ;
if ( ! V_69 -> V_149 )
continue;
V_5 = V_69 -> V_3 ;
if ( ! ( V_5 -> V_27 & V_38 ) )
continue;
F_21 ( & V_2 -> V_50 ) ;
F_13 ( V_2 , V_69 -> V_52 ) ;
F_26 ( V_2 , V_64 ) ;
V_34 = V_69 == V_5 -> V_51 [ 0 ] ? V_2 -> V_47 . V_48 : V_2 -> V_47 . V_49 ;
F_15 ( V_2 , V_58 , V_34 ) ;
V_5 -> V_39 = 1 ;
F_23 ( & V_2 -> V_50 ) ;
}
F_11 ( & V_2 -> V_148 , V_27 ) ;
return V_145 ;
}
int F_103 ( struct V_1 * V_2 , int V_150 , int V_151 )
{
struct V_152 * V_153 ;
struct V_132 * V_154 ;
struct V_155 * V_149 ;
struct V_8 * V_9 ;
int V_156 , V_91 ;
V_153 = V_2 -> V_153 ;
V_156 = ! V_2 -> V_78 && ! V_2 -> V_157 && ! V_2 -> V_158 ? 1 : 0 ;
V_91 = F_104 ( V_153 ,
V_2 -> V_78 ? L_4 : L_5 ,
V_150 ,
V_2 -> V_47 . V_159 / 2 ,
V_156 ,
& V_149 ) ;
if ( V_91 < 0 )
return V_91 ;
V_149 -> V_3 = V_2 ;
F_105 ( V_149 , V_160 , & V_161 ) ;
for ( V_9 = V_149 -> V_162 [ V_160 ] . V_9 ; V_9 ; V_9 = V_9 -> V_163 )
F_106 ( V_9 , V_164 ,
F_107 () ,
64 * 1024 , V_2 -> V_47 . V_121 > 3 ? 128 * 1024 : 64 * 1024 ) ;
V_149 -> V_165 = 0 ;
V_149 -> V_166 = V_167 ;
if ( V_156 ) {
F_105 ( V_149 , V_168 , & V_169 ) ;
if ( V_2 -> V_47 . V_109 == V_2 -> V_47 . V_121 )
V_149 -> V_165 |= V_170 ;
F_106 ( V_149 -> V_162 [ V_168 ] . V_9 ,
V_164 , F_107 () ,
64 * 1024 , V_2 -> V_47 . V_109 > 3 ? 128 * 1024 : 64 * 1024 ) ;
}
strcpy ( V_149 -> V_171 , V_149 -> V_172 ) ;
if ( V_2 -> V_78 ) {
sprintf ( V_149 -> V_171 + strlen ( V_149 -> V_171 ) , L_6 , V_2 -> V_173 + 'A' ) ;
}
strcat ( V_149 -> V_171 , L_7 ) ;
V_2 -> V_149 = V_149 ;
if ( V_2 -> V_174 )
V_154 = F_108 ( & V_175 , V_2 ) ;
else
V_154 = F_108 ( & V_176 , V_2 ) ;
if ( ( V_91 = F_109 ( V_153 , V_154 ) ) < 0 )
return V_91 ;
V_154 -> V_172 . V_177 = V_151 ;
return 0 ;
}
