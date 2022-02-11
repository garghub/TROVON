static void F_1 ( T_1 clock , int * V_1 , int V_2 , int V_3 )
{
if ( * V_1 == 0 )
* V_1 = clock * V_2 / ( 128 * V_3 ) * 1000 ;
F_2 ( L_1 ,
V_2 , * V_1 , V_3 ) ;
}
struct V_4 F_3 ( T_1 clock )
{
struct V_4 V_5 ;
T_2 V_6 ;
for ( V_6 = 0 ; V_7 [ V_6 ] . clock != clock &&
V_7 [ V_6 ] . clock != 0 ; V_6 ++ )
;
V_5 = V_7 [ V_6 ] ;
F_1 ( clock , & V_5 . V_8 , V_5 . V_9 , 32000 ) ;
F_1 ( clock , & V_5 . V_10 , V_5 . V_11 , 44100 ) ;
F_1 ( clock , & V_5 . V_12 , V_5 . V_13 , 48000 ) ;
return V_5 ;
}
static void F_4 ( struct V_14 * V_15 , T_1 clock )
{
struct V_16 * V_17 = V_15 -> V_17 ;
struct V_18 * V_19 = V_17 -> V_20 ;
struct V_4 V_21 = F_3 ( clock ) ;
struct V_22 * V_22 = F_5 ( V_15 ) ;
struct V_23 * V_24 = V_22 -> V_25 ;
T_1 V_26 = V_24 -> V_27 -> V_26 ;
F_6 ( V_28 + V_26 , F_7 ( V_21 . V_8 ) ) ;
F_6 ( V_29 + V_26 , V_21 . V_9 ) ;
F_6 ( V_30 + V_26 , F_8 ( V_21 . V_10 ) ) ;
F_6 ( V_31 + V_26 , V_21 . V_11 ) ;
F_6 ( V_32 + V_26 , F_9 ( V_21 . V_12 ) ) ;
F_6 ( V_33 + V_26 , V_21 . V_13 ) ;
}
static void F_10 ( struct V_14 * V_15 ,
void * V_34 , T_3 V_35 )
{
struct V_16 * V_17 = V_15 -> V_17 ;
struct V_18 * V_19 = V_17 -> V_20 ;
struct V_22 * V_22 = F_5 ( V_15 ) ;
struct V_23 * V_24 = V_22 -> V_25 ;
T_1 V_26 = V_24 -> V_27 -> V_26 ;
T_4 * V_36 = V_34 + 3 ;
T_4 * V_37 = V_34 ;
F_6 ( V_38 + V_26 ,
V_36 [ 0x0 ] | ( V_36 [ 0x1 ] << 8 ) | ( V_36 [ 0x2 ] << 16 ) | ( V_36 [ 0x3 ] << 24 ) ) ;
F_6 ( V_39 + V_26 ,
V_36 [ 0x4 ] | ( V_36 [ 0x5 ] << 8 ) | ( V_36 [ 0x6 ] << 16 ) | ( V_36 [ 0x7 ] << 24 ) ) ;
F_6 ( V_40 + V_26 ,
V_36 [ 0x8 ] | ( V_36 [ 0x9 ] << 8 ) | ( V_36 [ 0xA ] << 16 ) | ( V_36 [ 0xB ] << 24 ) ) ;
F_6 ( V_41 + V_26 ,
V_36 [ 0xC ] | ( V_36 [ 0xD ] << 8 ) | ( V_37 [ 1 ] << 24 ) ) ;
}
static void F_11 ( struct V_14 * V_15 ,
const void * V_34 , T_3 V_35 )
{
struct V_16 * V_17 = V_15 -> V_17 ;
struct V_18 * V_19 = V_17 -> V_20 ;
struct V_22 * V_22 = F_5 ( V_15 ) ;
struct V_23 * V_24 = V_22 -> V_25 ;
T_1 V_26 = V_24 -> V_27 -> V_26 ;
const T_2 * V_36 = V_34 + 3 ;
F_6 ( V_42 + V_26 ,
V_36 [ 0x0 ] | ( V_36 [ 0x1 ] << 8 ) | ( V_36 [ 0x2 ] << 16 ) | ( V_36 [ 0x3 ] << 24 ) ) ;
F_6 ( V_43 + V_26 ,
V_36 [ 0x4 ] | ( V_36 [ 0x5 ] << 8 ) | ( V_36 [ 0x6 ] << 16 ) | ( V_36 [ 0x8 ] << 24 ) ) ;
}
static bool F_12 ( struct V_14 * V_15 )
{
struct V_16 * V_17 = V_15 -> V_17 ;
struct V_18 * V_19 = V_17 -> V_20 ;
struct V_22 * V_22 = F_5 ( V_15 ) ;
struct V_23 * V_24 = V_22 -> V_25 ;
T_1 V_26 = V_24 -> V_27 -> V_26 ;
return ( F_13 ( V_44 + V_26 ) & 0x10 ) != 0 ;
}
int F_14 ( struct V_14 * V_15 )
{
struct V_22 * V_22 = F_5 ( V_15 ) ;
struct V_23 * V_24 = V_22 -> V_25 ;
int V_45 , V_46 ;
if ( ! V_24 -> V_27 || ! V_24 -> V_27 -> V_47 )
return 0 ;
V_45 = F_12 ( V_15 ) ;
V_46 = V_24 -> V_27 -> V_48 != V_45 ;
V_24 -> V_27 -> V_48 = V_45 ;
return V_46 ;
}
static void F_15 ( struct V_14 * V_15 )
{
struct V_16 * V_17 = V_15 -> V_17 ;
struct V_18 * V_19 = V_17 -> V_20 ;
struct V_22 * V_22 = F_5 ( V_15 ) ;
struct V_23 * V_24 = V_22 -> V_25 ;
T_1 V_26 = V_24 -> V_27 -> V_26 ;
bool V_49 = false ;
T_5 V_50 ;
if ( ! V_49 ||
F_12 ( V_15 ) )
V_50 = 0 ;
else
V_50 = V_51 ;
F_16 ( V_52 + V_26 ,
V_50 , ~ V_51 ) ;
}
void F_17 ( struct V_14 * V_15 , T_5 clock )
{
struct V_16 * V_17 = V_15 -> V_17 ;
struct V_18 * V_19 = V_17 -> V_20 ;
struct V_22 * V_22 = F_5 ( V_15 ) ;
struct V_23 * V_24 = V_22 -> V_25 ;
T_5 V_53 = 24000 ;
T_5 V_54 = clock / V_53 ;
T_5 V_55 ;
T_5 V_56 = clock ;
T_5 V_57 ;
T_5 V_58 ;
if ( ! V_24 || ! V_24 -> V_27 )
return;
if ( V_54 >= 8 ) {
V_55 = 192 * 1000 ;
V_57 = 3 ;
} else if ( V_54 >= 4 ) {
V_55 = 96 * 1000 ;
V_57 = 2 ;
} else if ( V_54 >= 2 ) {
V_55 = 48 * 1000 ;
V_57 = 1 ;
} else {
V_55 = 24 * 1000 ;
V_57 = 0 ;
}
if ( F_18 ( V_19 ) ) {
if ( V_24 -> V_59 == 0 ) {
V_58 = F_13 ( V_60 ) & ~ V_61 ;
V_58 |= F_19 ( V_57 ) ;
F_6 ( V_60 , V_58 ) ;
F_6 ( V_62 , V_55 ) ;
F_6 ( V_63 , V_56 ) ;
F_6 ( V_64 , 0 ) ;
} else {
V_58 = F_13 ( V_65 ) & ~ V_61 ;
V_58 |= F_19 ( V_57 ) ;
F_6 ( V_65 , V_58 ) ;
F_6 ( V_66 , V_55 ) ;
F_6 ( V_67 , V_56 ) ;
F_6 ( V_64 , 1 ) ;
}
} else {
F_6 ( V_68 , F_20 ( V_53 / 10 ) |
F_21 ( clock / 10 ) ) ;
}
}
void F_22 ( struct V_14 * V_15 , struct V_69 * V_70 )
{
struct V_16 * V_17 = V_15 -> V_17 ;
struct V_18 * V_19 = V_17 -> V_20 ;
struct V_22 * V_22 = F_5 ( V_15 ) ;
struct V_23 * V_24 = V_22 -> V_25 ;
T_2 V_34 [ V_71 + V_72 ] ;
struct V_73 V_36 ;
T_1 V_26 ;
T_6 V_74 ;
if ( ! V_24 || ! V_24 -> V_27 )
return;
if ( ! V_24 -> V_27 -> V_47 )
return;
V_26 = V_24 -> V_27 -> V_26 ;
F_17 ( V_15 , V_70 -> clock ) ;
F_6 ( V_75 + V_26 ,
V_76 ) ;
F_6 ( V_77 + V_26 , 0x1000 ) ;
if ( F_23 ( V_19 ) ) {
F_6 ( V_52 + V_26 ,
F_24 ( 1 ) |
F_25 ( 3 ) ) ;
F_6 ( V_78 + V_26 ,
V_79 |
V_80 ) ;
} else {
F_6 ( V_52 + V_26 ,
V_81 |
F_24 ( 1 ) |
F_25 ( 3 ) |
V_82 ) ;
}
F_6 ( V_83 + V_26 ,
V_84 |
V_85 ) ;
F_6 ( V_75 + V_26 ,
V_76 |
V_86 |
V_87 ) ;
F_6 ( V_88 + V_26 ,
V_89 |
V_90 |
V_91 |
V_92 ) ;
F_6 ( V_93 + V_26 ,
F_26 ( 2 ) |
F_27 ( 2 ) ) ;
F_6 ( V_94 + V_26 , 0 ) ;
V_74 = F_28 ( & V_36 , V_70 ) ;
if ( V_74 < 0 ) {
F_29 ( L_2 , V_74 ) ;
return;
}
V_74 = F_30 ( & V_36 , V_34 , sizeof( V_34 ) ) ;
if ( V_74 < 0 ) {
F_29 ( L_3 , V_74 ) ;
return;
}
F_10 ( V_15 , V_34 , sizeof( V_34 ) ) ;
F_4 ( V_15 , V_70 -> clock ) ;
F_6 ( V_95 + V_26 , 0x00FFFFFF ) ;
F_6 ( V_96 + V_26 , 0x007FFFFF ) ;
F_6 ( V_97 + V_26 , 0x00000001 ) ;
F_6 ( V_98 + V_26 , 0x00000001 ) ;
F_15 ( V_15 ) ;
}
void F_31 ( struct V_14 * V_15 )
{
struct V_16 * V_17 = V_15 -> V_17 ;
struct V_18 * V_19 = V_17 -> V_20 ;
struct V_22 * V_22 = F_5 ( V_15 ) ;
struct V_23 * V_24 = V_22 -> V_25 ;
struct V_99 V_100 = F_32 ( V_19 ) ;
T_4 V_34 [ V_71 + V_101 ] ;
struct V_102 V_36 ;
T_1 V_26 ;
T_1 V_103 ;
T_6 V_74 ;
if ( ! V_24 -> V_27 || ! V_24 -> V_27 -> V_47 )
return;
V_26 = V_24 -> V_27 -> V_26 ;
F_2 ( L_4 ,
F_12 ( V_15 ) ? L_5 : L_6 ,
V_100 . V_104 , V_100 . V_105 , V_100 . V_106 ) ;
F_2 ( L_7 ,
( int ) V_100 . V_107 , ( int ) V_100 . V_108 ) ;
V_103 = 0 ;
if ( V_100 . V_107 & V_109 )
V_103 |= 1 << 0 ;
if ( V_100 . V_107 & V_110 )
V_103 |= 1 << 1 ;
if ( V_100 . V_107 & V_111 )
V_103 |= 1 << 2 ;
if ( V_100 . V_107 & V_112 )
V_103 |= 1 << 3 ;
V_103 |= F_33 ( V_100 . V_108 ) ;
switch ( V_100 . V_105 ) {
case 32000 :
V_103 |= F_34 ( 0x3 ) ;
break;
case 44100 :
V_103 |= F_34 ( 0x0 ) ;
break;
case 48000 :
V_103 |= F_34 ( 0x2 ) ;
break;
case 88200 :
V_103 |= F_34 ( 0x8 ) ;
break;
case 96000 :
V_103 |= F_34 ( 0xa ) ;
break;
case 176400 :
V_103 |= F_34 ( 0xc ) ;
break;
case 192000 :
V_103 |= F_34 ( 0xe ) ;
break;
}
F_6 ( V_113 + V_26 , V_103 ) ;
V_103 = 0 ;
switch ( V_100 . V_106 ) {
case 16 :
V_103 |= F_35 ( 0x2 ) ;
break;
case 20 :
V_103 |= F_35 ( 0x3 ) ;
break;
case 24 :
V_103 |= F_35 ( 0xb ) ;
break;
}
if ( V_100 . V_107 & V_114 )
V_103 |= 0x5 << 16 ;
F_16 ( V_115 + V_26 , V_103 , ~ 0x5000f ) ;
V_74 = F_36 ( & V_36 ) ;
if ( V_74 < 0 ) {
F_29 ( L_8 ) ;
return;
}
V_36 . V_104 = V_100 . V_104 ;
V_74 = F_37 ( & V_36 , V_34 , sizeof( V_34 ) ) ;
if ( V_74 < 0 ) {
F_29 ( L_9 ) ;
return;
}
F_11 ( V_15 , V_34 , sizeof( V_34 ) ) ;
F_15 ( V_15 ) ;
}
void F_38 ( struct V_14 * V_15 , bool V_116 )
{
struct V_16 * V_17 = V_15 -> V_17 ;
struct V_18 * V_19 = V_17 -> V_20 ;
struct V_22 * V_22 = F_5 ( V_15 ) ;
struct V_23 * V_24 = V_22 -> V_25 ;
T_5 V_117 = V_118 ;
if ( ! V_24 || ! V_24 -> V_27 )
return;
if ( V_116 && V_24 -> V_27 -> V_47 )
return;
if ( ! V_116 && ! V_24 -> V_27 -> V_47 )
return;
if ( ! F_18 ( V_19 ) ) {
if ( V_116 )
V_117 |= V_119 ;
switch ( V_22 -> V_120 ) {
case V_121 :
if ( V_116 ) {
F_39 ( V_122 , V_123 ) ;
V_117 |= F_40 ( V_124 ) ;
} else {
F_41 ( V_122 , ~ V_123 ) ;
}
break;
case V_125 :
if ( V_116 ) {
F_39 ( V_126 , V_127 ) ;
V_117 |= F_40 ( V_128 ) ;
} else {
F_41 ( V_126 , ~ V_127 ) ;
}
break;
case V_129 :
if ( V_116 ) {
F_39 ( V_130 , V_131 ) ;
V_117 |= F_40 ( V_132 ) ;
} else {
F_41 ( V_130 , ~ V_131 ) ;
}
break;
case V_133 :
if ( V_116 )
V_117 |= F_40 ( V_134 ) ;
break;
default:
F_42 ( V_19 -> V_17 , L_10 ,
V_22 -> V_120 ) ;
break;
}
F_6 ( V_135 + V_24 -> V_27 -> V_26 , V_117 ) ;
}
if ( V_19 -> V_136 . V_137 ) {
if ( V_116 )
F_43 ( V_19 , V_24 -> V_27 -> V_138 ) ;
else
F_44 ( V_19 , V_24 -> V_27 -> V_138 ) ;
}
V_24 -> V_27 -> V_47 = V_116 ;
F_2 ( L_11 ,
V_116 ? L_12 : L_13 , V_24 -> V_27 -> V_26 , V_22 -> V_120 ) ;
}
