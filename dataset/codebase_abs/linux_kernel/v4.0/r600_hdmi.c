static struct V_1 F_1 ( struct V_2 * V_3 )
{
struct V_1 V_4 ;
T_1 V_5 ;
V_5 = F_2 ( V_6 ) ;
V_4 . V_7 = ( V_5 & 0x7 ) + 1 ;
switch ( ( V_5 & 0xF0 ) >> 4 ) {
case 0x0 :
V_4 . V_8 = 8 ;
break;
case 0x1 :
V_4 . V_8 = 16 ;
break;
case 0x2 :
V_4 . V_8 = 20 ;
break;
case 0x3 :
V_4 . V_8 = 24 ;
break;
case 0x4 :
V_4 . V_8 = 32 ;
break;
default:
F_3 ( V_3 -> V_9 , L_1 ,
( int ) V_5 ) ;
V_4 . V_8 = 16 ;
}
if ( V_5 & 0x4000 )
V_4 . V_10 = 44100 ;
else
V_4 . V_10 = 48000 ;
V_4 . V_10 *= ( ( V_5 >> 11 ) & 0x7 ) + 1 ;
V_4 . V_10 /= ( ( V_5 >> 8 ) & 0x7 ) + 1 ;
V_5 = F_2 ( V_11 ) ;
V_4 . V_12 = V_5 & 0xff ;
V_4 . V_13 = ( V_5 >> 8 ) & 0xff ;
return V_4 ;
}
void F_4 ( struct V_14 * V_15 )
{
struct V_2 * V_3 = F_5 ( V_15 , struct V_2 ,
V_16 ) ;
struct V_17 * V_9 = V_3 -> V_18 ;
struct V_1 V_19 = F_1 ( V_3 ) ;
struct V_20 * V_21 ;
bool V_22 = false ;
if ( V_3 -> V_23 . V_24 [ 0 ] . V_7 != V_19 . V_7 ||
V_3 -> V_23 . V_24 [ 0 ] . V_10 != V_19 . V_10 ||
V_3 -> V_23 . V_24 [ 0 ] . V_8 != V_19 . V_8 ||
V_3 -> V_23 . V_24 [ 0 ] . V_12 != V_19 . V_12 ||
V_3 -> V_23 . V_24 [ 0 ] . V_13 != V_19 . V_13 ) {
V_3 -> V_23 . V_24 [ 0 ] = V_19 ;
V_22 = true ;
}
F_6 (encoder, &dev->mode_config.encoder_list, head) {
if ( ! F_7 ( V_21 ) )
continue;
if ( V_22 || F_8 ( V_21 ) )
F_9 ( V_21 ) ;
}
}
void F_10 ( struct V_2 * V_3 ,
struct V_1 * V_24 ,
T_2 V_25 )
{
T_3 V_26 = F_2 ( V_27 ) ;
if ( ! V_24 )
return;
if ( V_25 ) {
V_26 |= V_28 ;
if ( V_25 & 1 )
V_26 |= V_29 ;
if ( V_25 & 2 )
V_26 |= V_30 ;
if ( V_25 & 4 )
V_26 |= V_31 ;
if ( V_25 & 8 )
V_26 |= V_32 ;
} else {
V_26 &= ~ ( V_28 |
V_29 |
V_30 |
V_31 |
V_32 ) ;
}
F_11 ( V_27 , V_26 ) ;
}
struct V_1 * F_12 ( struct V_2 * V_3 )
{
return & V_3 -> V_23 . V_24 [ 0 ] ;
}
void F_13 ( struct V_20 * V_21 , long V_33 ,
const struct V_34 * V_35 )
{
struct V_17 * V_9 = V_21 -> V_9 ;
struct V_2 * V_3 = V_9 -> V_36 ;
T_1 V_37 = F_14 ( V_3 ) ? V_38 :
V_39 ;
F_15 ( V_37 + V_33 ,
V_40 |
V_41 ,
~ ( V_40 |
V_41 ) ) ;
F_15 ( V_42 + V_33 ,
F_16 ( V_35 -> V_43 ) ,
~ V_44 ) ;
F_15 ( V_45 + V_33 ,
F_17 ( V_35 -> V_46 ) ,
~ V_47 ) ;
F_15 ( V_48 + V_33 ,
F_18 ( V_35 -> V_49 ) ,
~ V_50 ) ;
F_15 ( V_51 + V_33 ,
F_19 ( V_35 -> V_52 ) ,
~ V_53 ) ;
F_15 ( V_54 + V_33 ,
F_20 ( V_35 -> V_55 ) ,
~ V_56 ) ;
F_15 ( V_57 + V_33 ,
F_21 ( V_35 -> V_58 ) ,
~ V_59 ) ;
}
void F_22 ( struct V_2 * V_3 , T_3 V_33 ,
unsigned char * V_60 , T_4 V_61 )
{
T_5 * V_62 = V_60 + 3 ;
F_11 ( V_63 + V_33 ,
V_62 [ 0x0 ] | ( V_62 [ 0x1 ] << 8 ) | ( V_62 [ 0x2 ] << 16 ) | ( V_62 [ 0x3 ] << 24 ) ) ;
F_11 ( V_64 + V_33 ,
V_62 [ 0x4 ] | ( V_62 [ 0x5 ] << 8 ) | ( V_62 [ 0x6 ] << 16 ) | ( V_62 [ 0x7 ] << 24 ) ) ;
F_11 ( V_65 + V_33 ,
V_62 [ 0x8 ] | ( V_62 [ 0x9 ] << 8 ) | ( V_62 [ 0xA ] << 16 ) | ( V_62 [ 0xB ] << 24 ) ) ;
F_11 ( V_66 + V_33 ,
V_62 [ 0xC ] | ( V_62 [ 0xD ] << 8 ) | ( V_60 [ 1 ] << 24 ) ) ;
F_23 ( V_67 + V_33 ,
V_68 |
V_69 ) ;
F_23 ( V_70 + V_33 ,
F_24 ( 2 ) ) ;
}
static void F_25 ( struct V_20 * V_21 ,
const void * V_60 , T_4 V_61 )
{
struct V_17 * V_9 = V_21 -> V_9 ;
struct V_2 * V_3 = V_9 -> V_36 ;
struct V_71 * V_71 = F_26 ( V_21 ) ;
struct V_72 * V_73 = V_71 -> V_74 ;
T_1 V_33 = V_73 -> V_75 -> V_33 ;
const T_2 * V_62 = V_60 + 3 ;
F_11 ( V_76 + V_33 ,
V_62 [ 0x0 ] | ( V_62 [ 0x1 ] << 8 ) | ( V_62 [ 0x2 ] << 16 ) | ( V_62 [ 0x3 ] << 24 ) ) ;
F_11 ( V_77 + V_33 ,
V_62 [ 0x4 ] | ( V_62 [ 0x5 ] << 8 ) | ( V_62 [ 0x6 ] << 16 ) | ( V_62 [ 0x8 ] << 24 ) ) ;
}
static bool F_27 ( struct V_20 * V_21 )
{
struct V_17 * V_9 = V_21 -> V_9 ;
struct V_2 * V_3 = V_9 -> V_36 ;
struct V_71 * V_71 = F_26 ( V_21 ) ;
struct V_72 * V_73 = V_71 -> V_74 ;
T_1 V_33 = V_73 -> V_75 -> V_33 ;
return ( F_2 ( V_78 + V_33 ) & 0x10 ) != 0 ;
}
int F_8 ( struct V_20 * V_21 )
{
struct V_71 * V_71 = F_26 ( V_21 ) ;
struct V_72 * V_73 = V_71 -> V_74 ;
int V_4 , V_79 ;
if ( ! V_73 -> V_75 || ! V_73 -> V_75 -> V_80 )
return 0 ;
V_4 = F_27 ( V_21 ) ;
V_79 = V_73 -> V_75 -> V_81 != V_4 ;
V_73 -> V_75 -> V_81 = V_4 ;
return V_79 ;
}
void F_28 ( struct V_20 * V_21 )
{
struct V_17 * V_9 = V_21 -> V_9 ;
struct V_2 * V_3 = V_9 -> V_36 ;
struct V_71 * V_71 = F_26 ( V_21 ) ;
struct V_72 * V_73 = V_71 -> V_74 ;
T_1 V_33 = V_73 -> V_75 -> V_33 ;
bool V_82 = false ;
T_3 V_5 ;
if ( ! V_82 ||
F_27 ( V_21 ) )
V_5 = 0 ;
else
V_5 = V_83 ;
F_15 ( V_84 + V_33 ,
V_5 , ~ V_83 ) ;
}
void F_29 ( struct V_2 * V_3 ,
struct V_85 * V_86 , unsigned int clock )
{
struct V_71 * V_71 ;
struct V_72 * V_73 ;
if ( ! V_86 )
return;
V_71 = F_26 ( V_86 -> V_21 ) ;
V_73 = V_71 -> V_74 ;
if ( ! V_73 )
return;
if ( V_73 -> V_87 == 0 ) {
F_11 ( V_88 , 24000 * 100 ) ;
F_11 ( V_89 , clock * 100 ) ;
F_11 ( V_90 , 0 ) ;
} else {
F_11 ( V_91 , 24000 * 100 ) ;
F_11 ( V_92 , clock * 100 ) ;
F_11 ( V_90 , 1 ) ;
}
}
void F_30 ( struct V_20 * V_21 , T_3 V_33 )
{
struct V_17 * V_9 = V_21 -> V_9 ;
struct V_2 * V_3 = V_9 -> V_36 ;
F_23 ( V_93 + V_33 ,
V_94 |
V_95 |
V_96 ) ;
}
void F_31 ( struct V_20 * V_21 , T_3 V_33 )
{
struct V_17 * V_9 = V_21 -> V_9 ;
struct V_2 * V_3 = V_9 -> V_36 ;
F_15 ( V_84 + V_33 ,
V_97 |
F_32 ( 1 ) |
F_33 ( 3 ) |
V_98 ,
~ ( V_97 |
V_99 |
V_100 |
V_98 ) ) ;
F_23 ( V_67 + V_33 ,
V_101 |
V_102 ) ;
F_15 ( V_70 + V_33 ,
F_34 ( 2 ) ,
~ V_103 ) ;
F_35 ( V_104 + V_33 ,
~ ( V_105 |
V_106 |
V_107 |
V_108 |
V_109 |
V_110 |
V_111 ) ) ;
F_15 ( V_112 + V_33 ,
F_36 ( 1 ) ,
~ ( V_113 |
V_114 ) ) ;
F_15 ( V_115 + V_33 ,
F_37 ( 2 ) ,
~ V_116 ) ;
}
void F_38 ( struct V_20 * V_21 , T_3 V_33 , bool V_117 )
{
struct V_17 * V_9 = V_21 -> V_9 ;
struct V_2 * V_3 = V_9 -> V_36 ;
if ( V_117 )
F_23 ( V_118 + V_33 , V_119 ) ;
else
F_35 ( V_118 + V_33 , ~ V_119 ) ;
}
void F_9 ( struct V_20 * V_21 )
{
struct V_17 * V_9 = V_21 -> V_9 ;
struct V_2 * V_3 = V_9 -> V_36 ;
struct V_71 * V_71 = F_26 ( V_21 ) ;
struct V_72 * V_73 = V_71 -> V_74 ;
struct V_1 V_23 = F_1 ( V_3 ) ;
T_5 V_60 [ V_120 + V_121 ] ;
struct V_122 V_62 ;
T_1 V_33 ;
T_1 V_5 ;
T_6 V_123 ;
if ( ! V_73 -> V_75 || ! V_73 -> V_75 -> V_80 )
return;
V_33 = V_73 -> V_75 -> V_33 ;
F_39 ( L_2 ,
F_27 ( V_21 ) ? L_3 : L_4 ,
V_23 . V_7 , V_23 . V_10 , V_23 . V_8 ) ;
F_39 ( L_5 ,
( int ) V_23 . V_12 , ( int ) V_23 . V_13 ) ;
V_123 = F_40 ( & V_62 ) ;
if ( V_123 < 0 ) {
F_41 ( L_6 ) ;
return;
}
V_62 . V_7 = V_23 . V_7 ;
V_123 = F_42 ( & V_62 , V_60 , sizeof( V_60 ) ) ;
if ( V_123 < 0 ) {
F_41 ( L_7 ) ;
return;
}
V_5 = F_2 ( V_84 + V_33 ) ;
if ( V_5 & V_83 )
F_11 ( V_84 + V_33 ,
V_5 & ~ V_83 ) ;
F_23 ( V_124 + V_33 ,
V_125 ) ;
F_35 ( V_67 + V_33 ,
~ V_126 ) ;
F_25 ( V_21 , V_60 , sizeof( V_60 ) ) ;
F_23 ( V_67 + V_33 ,
V_127 |
V_102 ) ;
}
void F_43 ( struct V_20 * V_21 , bool V_128 )
{
struct V_17 * V_9 = V_21 -> V_9 ;
struct V_2 * V_3 = V_9 -> V_36 ;
struct V_71 * V_71 = F_26 ( V_21 ) ;
struct V_72 * V_73 = V_71 -> V_74 ;
T_3 V_129 = V_125 ;
if ( ! V_73 || ! V_73 -> V_75 )
return;
if ( ! F_14 ( V_3 ) ) {
if ( V_128 )
V_129 |= V_130 ;
switch ( V_71 -> V_131 ) {
case V_132 :
if ( V_128 ) {
F_23 ( V_133 , V_134 ) ;
V_129 |= F_44 ( V_135 ) ;
} else {
F_35 ( V_133 , ~ V_134 ) ;
}
break;
case V_136 :
if ( V_128 ) {
F_23 ( V_137 , V_138 ) ;
V_129 |= F_44 ( V_139 ) ;
} else {
F_35 ( V_137 , ~ V_138 ) ;
}
break;
case V_140 :
if ( V_128 ) {
F_23 ( V_141 , V_142 ) ;
V_129 |= F_44 ( V_143 ) ;
} else {
F_35 ( V_141 , ~ V_142 ) ;
}
break;
case V_144 :
if ( V_128 )
V_129 |= F_44 ( V_145 ) ;
break;
default:
F_3 ( V_3 -> V_9 , L_8 ,
V_71 -> V_131 ) ;
break;
}
F_11 ( V_124 + V_73 -> V_75 -> V_33 , V_129 ) ;
}
if ( V_3 -> V_146 . V_147 ) {
if ( V_128 )
F_45 ( V_3 , V_73 -> V_75 -> V_148 ) ;
else
F_46 ( V_3 , V_73 -> V_75 -> V_148 ) ;
}
V_73 -> V_75 -> V_80 = V_128 ;
F_39 ( L_9 ,
V_128 ? L_10 : L_11 , V_73 -> V_75 -> V_33 , V_71 -> V_131 ) ;
}
