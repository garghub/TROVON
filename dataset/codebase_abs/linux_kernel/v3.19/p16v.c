static void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
if ( V_4 ) {
F_2 ( V_4 ) ;
}
}
static int F_3 ( struct V_6 * V_7 , int V_8 )
{
struct V_9 * V_10 = F_4 ( V_7 ) ;
struct V_11 * V_12 = & ( V_10 -> V_13 [ V_8 ] ) ;
struct V_3 * V_4 ;
struct V_1 * V_2 = V_7 -> V_2 ;
int V_14 ;
V_4 = F_5 ( sizeof( * V_4 ) , V_15 ) ;
if ( V_4 == NULL )
return - V_16 ;
V_4 -> V_10 = V_10 ;
V_4 -> V_7 = V_7 ;
V_2 -> V_5 = V_4 ;
V_2 -> V_17 = F_1 ;
V_2 -> V_18 = V_19 ;
V_12 -> V_10 = V_10 ;
V_12 -> V_20 = V_8 ;
V_12 -> V_21 = 1 ;
#if 0
dev_dbg(emu->card->dev,
"p16v: open channel_id=%d, channel=%p, use=0x%x\n",
channel_id, channel, channel->use);
dev_dbg(emu->card->dev, "open:channel_id=%d, chip=%p, channel=%p\n",
channel_id, chip, channel);
#endif
V_12 -> V_4 = V_4 ;
if ( ( V_14 = F_6 ( V_2 , V_22 ) ) < 0 )
return V_14 ;
V_2 -> V_23 . V_24 [ 0 ] = V_7 -> V_25 -> V_26 -> V_20 ;
V_2 -> V_23 . V_24 [ 1 ] = 'P' ;
V_2 -> V_23 . V_24 [ 2 ] = 16 ;
V_2 -> V_23 . V_24 [ 3 ] = 'V' ;
return 0 ;
}
static int F_7 ( struct V_6 * V_7 , int V_8 )
{
struct V_9 * V_10 = F_4 ( V_7 ) ;
struct V_11 * V_12 = & ( V_10 -> V_27 ) ;
struct V_3 * V_4 ;
struct V_1 * V_2 = V_7 -> V_2 ;
int V_14 ;
V_4 = F_5 ( sizeof( * V_4 ) , V_15 ) ;
if ( V_4 == NULL )
return - V_16 ;
V_4 -> V_10 = V_10 ;
V_4 -> V_7 = V_7 ;
V_2 -> V_5 = V_4 ;
V_2 -> V_17 = F_1 ;
V_2 -> V_18 = V_28 ;
V_12 -> V_10 = V_10 ;
V_12 -> V_20 = V_8 ;
V_12 -> V_21 = 1 ;
#if 0
dev_dbg(emu->card->dev,
"p16v: open channel_id=%d, channel=%p, use=0x%x\n",
channel_id, channel, channel->use);
dev_dbg(emu->card->dev, "open:channel_id=%d, chip=%p, channel=%p\n",
channel_id, chip, channel);
#endif
V_12 -> V_4 = V_4 ;
if ( ( V_14 = F_6 ( V_2 , V_22 ) ) < 0 )
return V_14 ;
return 0 ;
}
static int F_8 ( struct V_6 * V_7 )
{
struct V_9 * V_10 = F_4 ( V_7 ) ;
V_10 -> V_13 [ V_7 -> V_25 -> V_29 - V_10 -> V_30 ] . V_21 = 0 ;
return 0 ;
}
static int F_9 ( struct V_6 * V_7 )
{
struct V_9 * V_10 = F_4 ( V_7 ) ;
V_10 -> V_27 . V_21 = 0 ;
return 0 ;
}
static int F_10 ( struct V_6 * V_7 )
{
return F_3 ( V_7 , V_31 ) ;
}
static int F_11 ( struct V_6 * V_7 )
{
return F_7 ( V_7 , 0 ) ;
}
static int F_12 ( struct V_6 * V_7 ,
struct V_32 * V_33 )
{
int V_34 ;
V_34 = F_13 ( V_7 ,
F_14 ( V_33 ) ) ;
return V_34 ;
}
static int F_15 ( struct V_6 * V_7 ,
struct V_32 * V_33 )
{
int V_34 ;
V_34 = F_13 ( V_7 ,
F_14 ( V_33 ) ) ;
return V_34 ;
}
static int F_16 ( struct V_6 * V_7 )
{
int V_34 ;
V_34 = F_17 ( V_7 ) ;
return V_34 ;
}
static int F_18 ( struct V_6 * V_7 )
{
int V_34 ;
V_34 = F_17 ( V_7 ) ;
return V_34 ;
}
static int F_19 ( struct V_6 * V_7 )
{
struct V_9 * V_10 = F_4 ( V_7 ) ;
struct V_1 * V_2 = V_7 -> V_2 ;
int V_12 = V_7 -> V_25 -> V_29 - V_10 -> V_30 ;
T_1 * V_35 = ( T_1 * ) ( V_10 -> V_36 . V_37 + ( 8 * 16 * V_12 ) ) ;
T_1 V_38 = F_20 ( V_2 , V_2 -> V_39 ) ;
int V_40 ;
T_1 V_41 ;
#if 0
dev_dbg(emu->card->dev,
"prepare:channel_number=%d, rate=%d, "
"format=0x%x, channels=%d, buffer_size=%ld, "
"period_size=%ld, periods=%u, frames_to_bytes=%d\n",
channel, runtime->rate, runtime->format, runtime->channels,
runtime->buffer_size, runtime->period_size,
runtime->periods, frames_to_bytes(runtime, 1));
dev_dbg(emu->card->dev,
"dma_addr=%x, dma_area=%p, table_base=%p\n",
runtime->dma_addr, runtime->dma_area, table_base);
dev_dbg(emu->card->dev,
"dma_addr=%x, dma_area=%p, dma_bytes(size)=%x\n",
emu->p16v_buffer.addr, emu->p16v_buffer.area,
emu->p16v_buffer.bytes);
#endif
V_41 = F_21 ( V_10 , V_42 , V_12 ) ;
switch ( V_2 -> V_43 ) {
case 44100 :
F_22 ( V_10 , V_42 , V_12 , ( V_41 & ~ 0xe0e0 ) | 0x8080 ) ;
break;
case 96000 :
F_22 ( V_10 , V_42 , V_12 , ( V_41 & ~ 0xe0e0 ) | 0x4040 ) ;
break;
case 192000 :
F_22 ( V_10 , V_42 , V_12 , ( V_41 & ~ 0xe0e0 ) | 0x2020 ) ;
break;
case 48000 :
default:
F_22 ( V_10 , V_42 , V_12 , ( V_41 & ~ 0xe0e0 ) | 0x0000 ) ;
break;
}
for( V_40 = 0 ; V_40 < V_2 -> V_44 ; V_40 ++ ) {
V_35 [ V_40 * 2 ] = V_2 -> V_45 + ( V_40 * V_38 ) ;
V_35 [ ( V_40 * 2 ) + 1 ] = V_38 << 16 ;
}
F_23 ( V_10 , V_46 , V_12 , V_10 -> V_36 . V_47 + ( 8 * 16 * V_12 ) ) ;
F_23 ( V_10 , V_48 , V_12 , ( V_2 -> V_44 - 1 ) << 19 ) ;
F_23 ( V_10 , V_49 , V_12 , 0 ) ;
F_23 ( V_10 , V_50 , V_12 , V_2 -> V_45 ) ;
F_23 ( V_10 , V_51 , V_12 , 0 ) ;
F_23 ( V_10 , V_52 , V_12 , 0 ) ;
F_23 ( V_10 , 0x07 , V_12 , 0x0 ) ;
F_23 ( V_10 , 0x08 , V_12 , 0 ) ;
return 0 ;
}
static int F_24 ( struct V_6 * V_7 )
{
struct V_9 * V_10 = F_4 ( V_7 ) ;
struct V_1 * V_2 = V_7 -> V_2 ;
int V_12 = V_7 -> V_25 -> V_29 - V_10 -> V_30 ;
T_1 V_41 ;
V_41 = F_21 ( V_10 , V_42 , V_12 ) ;
switch ( V_2 -> V_43 ) {
case 44100 :
F_22 ( V_10 , V_42 , V_12 , ( V_41 & ~ 0x0e00 ) | 0x0800 ) ;
break;
case 96000 :
F_22 ( V_10 , V_42 , V_12 , ( V_41 & ~ 0x0e00 ) | 0x0400 ) ;
break;
case 192000 :
F_22 ( V_10 , V_42 , V_12 , ( V_41 & ~ 0x0e00 ) | 0x0200 ) ;
break;
case 48000 :
default:
F_22 ( V_10 , V_42 , V_12 , ( V_41 & ~ 0x0e00 ) | 0x0000 ) ;
break;
}
F_23 ( V_10 , 0x13 , V_12 , 0 ) ;
F_23 ( V_10 , V_53 , V_12 , V_2 -> V_45 ) ;
F_23 ( V_10 , V_54 , V_12 , F_20 ( V_2 , V_2 -> V_55 ) << 16 ) ;
F_23 ( V_10 , V_56 , V_12 , 0 ) ;
return 0 ;
}
static void F_25 ( struct V_9 * V_10 , unsigned int V_57 )
{
unsigned long V_58 ;
unsigned int V_59 ;
F_26 ( & V_10 -> V_60 , V_58 ) ;
V_59 = F_27 ( V_10 -> V_61 + V_62 ) | V_57 ;
F_28 ( V_59 , V_10 -> V_61 + V_62 ) ;
F_29 ( & V_10 -> V_60 , V_58 ) ;
}
static void F_30 ( struct V_9 * V_10 , unsigned int V_57 )
{
unsigned long V_58 ;
unsigned int V_63 ;
F_26 ( & V_10 -> V_60 , V_58 ) ;
V_63 = F_27 ( V_10 -> V_61 + V_62 ) & ( ~ V_57 ) ;
F_28 ( V_63 , V_10 -> V_61 + V_62 ) ;
F_29 ( & V_10 -> V_60 , V_58 ) ;
}
static int F_31 ( struct V_6 * V_7 ,
int V_64 )
{
struct V_9 * V_10 = F_4 ( V_7 ) ;
struct V_1 * V_2 ;
struct V_3 * V_4 ;
int V_12 ;
int V_34 = 0 ;
struct V_6 * V_65 ;
T_1 V_66 = 0 ;
T_1 V_67 = 0 ;
int V_68 = 0 ;
switch ( V_64 ) {
case V_69 :
V_68 = 1 ;
break;
case V_70 :
default:
V_68 = 0 ;
break;
}
F_32 (s, substream) {
if ( F_4 ( V_65 ) != V_10 ||
V_65 -> V_71 != V_72 )
continue;
V_2 = V_65 -> V_2 ;
V_4 = V_2 -> V_5 ;
V_12 = V_7 -> V_25 -> V_29 - V_10 -> V_30 ;
V_4 -> V_68 = V_68 ;
V_66 |= ( 0x1 << V_12 ) ;
V_67 |= ( V_73 << V_12 ) ;
F_33 ( V_65 , V_7 ) ;
}
switch ( V_64 ) {
case V_69 :
F_25 ( V_10 , V_67 ) ;
F_23 ( V_10 , V_74 , 0 , F_34 ( V_10 , V_74 , 0 ) | ( V_66 ) ) ;
break;
case V_70 :
F_23 ( V_10 , V_74 , 0 , F_34 ( V_10 , V_74 , 0 ) & ~ ( V_66 ) ) ;
F_30 ( V_10 , V_67 ) ;
break;
default:
V_34 = - V_75 ;
break;
}
return V_34 ;
}
static int F_35 ( struct V_6 * V_7 ,
int V_64 )
{
struct V_9 * V_10 = F_4 ( V_7 ) ;
struct V_1 * V_2 = V_7 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
int V_12 = 0 ;
int V_34 = 0 ;
T_1 V_67 = V_76 | V_77 ;
switch ( V_64 ) {
case V_69 :
F_25 ( V_10 , V_67 ) ;
F_23 ( V_10 , V_74 , 0 , F_34 ( V_10 , V_74 , 0 ) | ( 0x100 << V_12 ) ) ;
V_4 -> V_68 = 1 ;
break;
case V_70 :
F_23 ( V_10 , V_74 , 0 , F_34 ( V_10 , V_74 , 0 ) & ~ ( 0x100 << V_12 ) ) ;
F_30 ( V_10 , V_67 ) ;
V_4 -> V_68 = 0 ;
break;
default:
V_34 = - V_75 ;
break;
}
return V_34 ;
}
static T_2
F_36 ( struct V_6 * V_7 )
{
struct V_9 * V_10 = F_4 ( V_7 ) ;
struct V_1 * V_2 = V_7 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
T_2 V_78 , V_79 , V_80 , V_81 , V_82 = 0 ;
int V_12 = V_7 -> V_25 -> V_29 - V_10 -> V_30 ;
if ( ! V_4 -> V_68 )
return 0 ;
V_81 = F_34 ( V_10 , V_49 , V_12 ) ;
V_79 = F_34 ( V_10 , V_52 , V_12 ) ;
V_82 = F_34 ( V_10 , V_49 , V_12 ) ;
if ( V_81 != V_82 ) V_79 = F_34 ( V_10 , V_52 , V_12 ) ;
V_80 = F_37 ( V_2 , V_79 ) ;
V_80 += ( V_82 >> 3 ) * V_2 -> V_39 ;
V_78 = V_80 ;
if ( V_78 >= V_2 -> V_55 )
V_78 -= V_2 -> V_55 ;
return V_78 ;
}
static T_2
F_38 ( struct V_6 * V_7 )
{
struct V_9 * V_10 = F_4 ( V_7 ) ;
struct V_1 * V_2 = V_7 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
T_2 V_78 , V_79 , V_80 = 0 ;
int V_12 = 0 ;
if ( ! V_4 -> V_68 )
return 0 ;
V_79 = F_34 ( V_10 , V_56 , V_12 ) ;
V_80 = F_37 ( V_2 , V_79 ) ;
V_78 = V_80 ;
if ( V_78 >= V_2 -> V_55 ) {
V_78 -= V_2 -> V_55 ;
F_39 ( V_10 -> V_26 -> V_83 , L_1 ) ;
}
return V_78 ;
}
int F_40 ( struct V_9 * V_84 )
{
if ( V_84 -> V_36 . V_37 ) {
F_41 ( & V_84 -> V_36 ) ;
}
return 0 ;
}
int F_42 ( struct V_9 * V_10 , int V_29 , struct V_85 * * V_86 )
{
struct V_85 * V_25 ;
struct V_6 * V_7 ;
int V_14 ;
int V_87 = 1 ;
V_10 -> V_30 = V_29 ;
if ( V_86 )
* V_86 = NULL ;
if ( ( V_14 = F_43 ( V_10 -> V_26 , L_2 , V_29 , 1 , V_87 , & V_25 ) ) < 0 )
return V_14 ;
V_25 -> V_5 = V_10 ;
F_44 ( V_25 , V_72 , & V_88 ) ;
F_44 ( V_25 , V_89 , & V_90 ) ;
V_25 -> V_91 = 0 ;
V_25 -> V_92 = V_93 ;
strcpy ( V_25 -> V_94 , L_2 ) ;
V_10 -> V_95 = V_25 ;
for( V_7 = V_25 -> V_96 [ V_72 ] . V_7 ;
V_7 ;
V_7 = V_7 -> V_97 ) {
if ( ( V_14 = F_45 ( V_7 ,
V_98 ,
F_46 ( V_10 -> V_99 ) ,
( ( 65536 - 64 ) * 8 ) , ( ( 65536 - 64 ) * 8 ) ) ) < 0 )
return V_14 ;
}
for ( V_7 = V_25 -> V_96 [ V_89 ] . V_7 ;
V_7 ;
V_7 = V_7 -> V_97 ) {
if ( ( V_14 = F_45 ( V_7 ,
V_98 ,
F_46 ( V_10 -> V_99 ) ,
65536 - 64 , 65536 - 64 ) ) < 0 )
return V_14 ;
}
if ( V_86 )
* V_86 = V_25 ;
return 0 ;
}
static int F_47 ( struct V_100 * V_101 ,
struct V_102 * V_103 )
{
V_103 -> type = V_104 ;
V_103 -> V_105 = 2 ;
V_103 -> V_106 . integer . V_107 = 0 ;
V_103 -> V_106 . integer . V_108 = 255 ;
return 0 ;
}
static int F_48 ( struct V_100 * V_101 ,
struct V_109 * V_110 )
{
struct V_9 * V_10 = F_49 ( V_101 ) ;
int V_111 = ( V_101 -> V_112 >> 8 ) & 0xff ;
int V_113 = V_101 -> V_112 & 0xff ;
T_1 V_106 ;
V_106 = F_34 ( V_10 , V_113 , V_111 ) ;
if ( V_111 ) {
V_110 -> V_106 . integer . V_106 [ 0 ] = 0xff - ( ( V_106 >> 24 ) & 0xff ) ;
V_110 -> V_106 . integer . V_106 [ 1 ] = 0xff - ( ( V_106 >> 16 ) & 0xff ) ;
} else {
V_110 -> V_106 . integer . V_106 [ 0 ] = 0xff - ( ( V_106 >> 8 ) & 0xff ) ;
V_110 -> V_106 . integer . V_106 [ 1 ] = 0xff - ( ( V_106 >> 0 ) & 0xff ) ;
}
return 0 ;
}
static int F_50 ( struct V_100 * V_101 ,
struct V_109 * V_110 )
{
struct V_9 * V_10 = F_49 ( V_101 ) ;
int V_111 = ( V_101 -> V_112 >> 8 ) & 0xff ;
int V_113 = V_101 -> V_112 & 0xff ;
T_1 V_106 , V_114 ;
V_114 = V_106 = F_34 ( V_10 , V_113 , 0 ) ;
if ( V_111 == 1 ) {
V_106 &= 0xffff ;
V_106 |= ( ( 0xff - V_110 -> V_106 . integer . V_106 [ 0 ] ) << 24 ) |
( ( 0xff - V_110 -> V_106 . integer . V_106 [ 1 ] ) << 16 ) ;
} else {
V_106 &= 0xffff0000 ;
V_106 |= ( ( 0xff - V_110 -> V_106 . integer . V_106 [ 0 ] ) << 8 ) |
( ( 0xff - V_110 -> V_106 . integer . V_106 [ 1 ] ) ) ;
}
if ( V_106 != V_114 ) {
F_23 ( V_10 , V_113 , 0 , V_106 ) ;
return 1 ;
}
return 0 ;
}
static int F_51 ( struct V_100 * V_101 ,
struct V_102 * V_103 )
{
static const char * const V_115 [ 8 ] = {
L_3 , L_4 , L_5 , L_6 , L_7 ,
L_8 , L_9 , L_10
} ;
return F_52 ( V_103 , 1 , 8 , V_115 ) ;
}
static int F_53 ( struct V_100 * V_101 ,
struct V_109 * V_110 )
{
struct V_9 * V_10 = F_49 ( V_101 ) ;
V_110 -> V_106 . V_116 . V_117 [ 0 ] = V_10 -> V_118 ;
return 0 ;
}
static int F_54 ( struct V_100 * V_101 ,
struct V_109 * V_110 )
{
struct V_9 * V_10 = F_49 ( V_101 ) ;
unsigned int V_119 ;
int V_120 = 0 ;
T_1 V_121 ;
T_1 V_122 ;
V_119 = V_110 -> V_106 . V_116 . V_117 [ 0 ] ;
if ( V_119 > 7 )
return - V_75 ;
V_120 = ( V_10 -> V_118 != V_119 ) ;
if ( V_120 ) {
V_10 -> V_118 = V_119 ;
V_122 = ( V_119 << 28 ) | ( V_119 << 24 ) | ( V_119 << 20 ) | ( V_119 << 16 ) ;
V_121 = F_34 ( V_10 , V_74 , 0 ) & 0xffff ;
F_23 ( V_10 , V_74 , 0 , V_122 | V_121 ) ;
}
return V_120 ;
}
static int F_55 ( struct V_100 * V_101 ,
struct V_102 * V_103 )
{
static const char * const V_115 [ 4 ] = { L_11 , L_12 , L_13 , L_14 , } ;
return F_52 ( V_103 , 1 , 4 , V_115 ) ;
}
static int F_56 ( struct V_100 * V_101 ,
struct V_109 * V_110 )
{
struct V_9 * V_10 = F_49 ( V_101 ) ;
V_110 -> V_106 . V_116 . V_117 [ 0 ] = V_10 -> V_123 ;
return 0 ;
}
static int F_57 ( struct V_100 * V_101 ,
struct V_109 * V_110 )
{
struct V_9 * V_10 = F_49 ( V_101 ) ;
unsigned int V_119 ;
int V_120 = 0 ;
T_1 V_41 ;
V_119 = V_110 -> V_106 . V_116 . V_117 [ 0 ] ;
if ( V_119 > 3 )
return - V_75 ;
V_120 = ( V_10 -> V_123 != V_119 ) ;
if ( V_120 ) {
V_10 -> V_123 = V_119 ;
V_41 = F_34 ( V_10 , V_124 , 0 ) & 0xfffc ;
F_23 ( V_10 , V_124 , 0 , V_41 | V_119 ) ;
}
return V_120 ;
}
int F_58 ( struct V_9 * V_10 )
{
int V_40 , V_14 ;
struct V_125 * V_26 = V_10 -> V_26 ;
for ( V_40 = 0 ; V_40 < F_59 ( V_126 ) ; V_40 ++ ) {
if ( ( V_14 = F_60 ( V_26 , F_61 ( & V_126 [ V_40 ] ,
V_10 ) ) ) < 0 )
return V_14 ;
}
return 0 ;
}
int F_62 ( struct V_9 * V_10 )
{
V_10 -> V_127 = F_63 ( V_128 * 4 * 0x80 ) ;
if ( ! V_10 -> V_127 )
return - V_16 ;
return 0 ;
}
void F_64 ( struct V_9 * V_10 )
{
F_65 ( V_10 -> V_127 ) ;
}
void F_66 ( struct V_9 * V_10 )
{
int V_40 , V_129 ;
unsigned int * V_119 ;
V_119 = V_10 -> V_127 ;
for ( V_129 = 0 ; V_129 < V_128 ; V_129 ++ )
for ( V_40 = 0 ; V_40 < 0x80 ; V_40 ++ , V_119 ++ )
* V_119 = F_34 ( V_10 , V_40 , V_129 ) ;
}
void F_67 ( struct V_9 * V_10 )
{
int V_40 , V_129 ;
unsigned int * V_119 ;
V_119 = V_10 -> V_127 ;
for ( V_129 = 0 ; V_129 < V_128 ; V_129 ++ )
for ( V_40 = 0 ; V_40 < 0x80 ; V_40 ++ , V_119 ++ )
F_23 ( V_10 , V_40 , V_129 , * V_119 ) ;
}
