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
V_36 [ 0x0 ] += 2 ;
F_6 ( V_37 + V_26 ,
V_36 [ 0x0 ] | ( V_36 [ 0x1 ] << 8 ) | ( V_36 [ 0x2 ] << 16 ) | ( V_36 [ 0x3 ] << 24 ) ) ;
F_6 ( V_38 + V_26 ,
V_36 [ 0x4 ] | ( V_36 [ 0x5 ] << 8 ) | ( V_36 [ 0x6 ] << 16 ) | ( V_36 [ 0x7 ] << 24 ) ) ;
F_6 ( V_39 + V_26 ,
V_36 [ 0x8 ] | ( V_36 [ 0x9 ] << 8 ) | ( V_36 [ 0xA ] << 16 ) | ( V_36 [ 0xB ] << 24 ) ) ;
F_6 ( V_40 + V_26 ,
V_36 [ 0xC ] | ( V_36 [ 0xD ] << 8 ) ) ;
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
F_6 ( V_41 + V_26 ,
V_36 [ 0x0 ] | ( V_36 [ 0x1 ] << 8 ) | ( V_36 [ 0x2 ] << 16 ) | ( V_36 [ 0x3 ] << 24 ) ) ;
F_6 ( V_42 + V_26 ,
V_36 [ 0x4 ] | ( V_36 [ 0x5 ] << 8 ) | ( V_36 [ 0x6 ] << 16 ) | ( V_36 [ 0x8 ] << 24 ) ) ;
}
static bool F_12 ( struct V_14 * V_15 )
{
struct V_16 * V_17 = V_15 -> V_17 ;
struct V_18 * V_19 = V_17 -> V_20 ;
struct V_22 * V_22 = F_5 ( V_15 ) ;
struct V_23 * V_24 = V_22 -> V_25 ;
T_1 V_26 = V_24 -> V_27 -> V_26 ;
return ( F_13 ( V_43 + V_26 ) & 0x10 ) != 0 ;
}
int F_14 ( struct V_14 * V_15 )
{
struct V_22 * V_22 = F_5 ( V_15 ) ;
struct V_23 * V_24 = V_22 -> V_25 ;
int V_44 , V_45 ;
if ( ! V_24 -> V_27 || ! V_24 -> V_27 -> V_46 )
return 0 ;
V_44 = F_12 ( V_15 ) ;
V_45 = V_24 -> V_27 -> V_47 != V_44 ;
V_24 -> V_27 -> V_47 = V_44 ;
return V_45 ;
}
static void F_15 ( struct V_14 * V_15 )
{
struct V_16 * V_17 = V_15 -> V_17 ;
struct V_18 * V_19 = V_17 -> V_20 ;
struct V_22 * V_22 = F_5 ( V_15 ) ;
struct V_23 * V_24 = V_22 -> V_25 ;
T_1 V_26 = V_24 -> V_27 -> V_26 ;
bool V_48 = false ;
T_5 V_49 ;
if ( ! V_48 ||
F_12 ( V_15 ) )
V_49 = 0 ;
else
V_49 = V_50 ;
F_16 ( V_51 + V_26 ,
V_49 , ~ V_50 ) ;
}
void F_17 ( struct V_14 * V_15 , T_5 clock )
{
struct V_16 * V_17 = V_15 -> V_17 ;
struct V_18 * V_19 = V_17 -> V_20 ;
struct V_22 * V_22 = F_5 ( V_15 ) ;
struct V_23 * V_24 = V_22 -> V_25 ;
T_5 V_52 = 24000 ;
if ( ! V_24 || ! V_24 -> V_27 )
return;
if ( F_18 ( V_19 ) ) {
F_6 ( V_53 , V_52 * 100 ) ;
F_6 ( V_54 , clock * 100 ) ;
F_6 ( V_55 , 0 ) ;
} else {
F_6 ( V_56 , F_19 ( V_52 / 10 ) |
F_20 ( clock / 10 ) ) ;
}
}
void F_21 ( struct V_14 * V_15 , struct V_57 * V_58 )
{
struct V_16 * V_17 = V_15 -> V_17 ;
struct V_18 * V_19 = V_17 -> V_20 ;
struct V_22 * V_22 = F_5 ( V_15 ) ;
struct V_23 * V_24 = V_22 -> V_25 ;
T_2 V_34 [ V_59 + V_60 ] ;
struct V_61 V_36 ;
T_1 V_26 ;
T_6 V_62 ;
if ( ! V_24 -> V_27 -> V_46 )
return;
V_26 = V_24 -> V_27 -> V_26 ;
F_17 ( V_15 , V_58 -> clock ) ;
F_6 ( V_63 + V_26 ,
V_64 ) ;
F_6 ( V_65 + V_26 , 0x1000 ) ;
if ( F_22 ( V_19 ) ) {
F_6 ( V_51 + V_26 ,
F_23 ( 1 ) |
F_24 ( 3 ) ) ;
F_6 ( V_66 + V_26 ,
V_67 |
V_68 ) ;
} else {
F_6 ( V_51 + V_26 ,
V_69 |
F_23 ( 1 ) |
F_24 ( 3 ) |
V_70 ) ;
}
F_6 ( V_71 + V_26 ,
V_72 |
V_73 ) ;
F_6 ( V_63 + V_26 ,
V_64 |
V_74 |
V_75 ) ;
F_6 ( V_76 + V_26 ,
V_77 |
V_78 |
V_79 |
V_80 ) ;
F_6 ( V_81 + V_26 ,
F_25 ( 2 ) |
F_26 ( 2 ) ) ;
F_6 ( V_82 + V_26 , 0 ) ;
V_62 = F_27 ( & V_36 , V_58 ) ;
if ( V_62 < 0 ) {
F_28 ( L_2 , V_62 ) ;
return;
}
V_62 = F_29 ( & V_36 , V_34 , sizeof( V_34 ) ) ;
if ( V_62 < 0 ) {
F_28 ( L_3 , V_62 ) ;
return;
}
F_10 ( V_15 , V_34 , sizeof( V_34 ) ) ;
F_4 ( V_15 , V_58 -> clock ) ;
F_6 ( V_83 + V_26 , 0x00FFFFFF ) ;
F_6 ( V_84 + V_26 , 0x007FFFFF ) ;
F_6 ( V_85 + V_26 , 0x00000001 ) ;
F_6 ( V_86 + V_26 , 0x00000001 ) ;
F_15 ( V_15 ) ;
}
void F_30 ( struct V_14 * V_15 )
{
struct V_16 * V_17 = V_15 -> V_17 ;
struct V_18 * V_19 = V_17 -> V_20 ;
struct V_22 * V_22 = F_5 ( V_15 ) ;
struct V_23 * V_24 = V_22 -> V_25 ;
struct V_87 V_88 = F_31 ( V_19 ) ;
T_4 V_34 [ V_59 + V_89 ] ;
struct V_90 V_36 ;
T_1 V_26 ;
T_1 V_91 ;
T_6 V_62 ;
if ( ! V_24 -> V_27 || ! V_24 -> V_27 -> V_46 )
return;
V_26 = V_24 -> V_27 -> V_26 ;
F_2 ( L_4 ,
F_12 ( V_15 ) ? L_5 : L_6 ,
V_88 . V_92 , V_88 . V_93 , V_88 . V_94 ) ;
F_2 ( L_7 ,
( int ) V_88 . V_95 , ( int ) V_88 . V_96 ) ;
V_91 = 0 ;
if ( V_88 . V_95 & V_97 )
V_91 |= 1 << 0 ;
if ( V_88 . V_95 & V_98 )
V_91 |= 1 << 1 ;
if ( V_88 . V_95 & V_99 )
V_91 |= 1 << 2 ;
if ( V_88 . V_95 & V_100 )
V_91 |= 1 << 3 ;
V_91 |= F_32 ( V_88 . V_96 ) ;
switch ( V_88 . V_93 ) {
case 32000 :
V_91 |= F_33 ( 0x3 ) ;
break;
case 44100 :
V_91 |= F_33 ( 0x0 ) ;
break;
case 48000 :
V_91 |= F_33 ( 0x2 ) ;
break;
case 88200 :
V_91 |= F_33 ( 0x8 ) ;
break;
case 96000 :
V_91 |= F_33 ( 0xa ) ;
break;
case 176400 :
V_91 |= F_33 ( 0xc ) ;
break;
case 192000 :
V_91 |= F_33 ( 0xe ) ;
break;
}
F_6 ( V_101 + V_26 , V_91 ) ;
V_91 = 0 ;
switch ( V_88 . V_94 ) {
case 16 :
V_91 |= F_34 ( 0x2 ) ;
break;
case 20 :
V_91 |= F_34 ( 0x3 ) ;
break;
case 24 :
V_91 |= F_34 ( 0xb ) ;
break;
}
if ( V_88 . V_95 & V_102 )
V_91 |= 0x5 << 16 ;
F_16 ( V_103 + V_26 , V_91 , ~ 0x5000f ) ;
V_62 = F_35 ( & V_36 ) ;
if ( V_62 < 0 ) {
F_28 ( L_8 ) ;
return;
}
V_36 . V_92 = V_88 . V_92 ;
V_62 = F_36 ( & V_36 , V_34 , sizeof( V_34 ) ) ;
if ( V_62 < 0 ) {
F_28 ( L_9 ) ;
return;
}
F_11 ( V_15 , V_34 , sizeof( V_34 ) ) ;
F_15 ( V_15 ) ;
}
void F_37 ( struct V_14 * V_15 , bool V_104 )
{
struct V_16 * V_17 = V_15 -> V_17 ;
struct V_18 * V_19 = V_17 -> V_20 ;
struct V_22 * V_22 = F_5 ( V_15 ) ;
struct V_23 * V_24 = V_22 -> V_25 ;
T_5 V_105 = V_106 ;
if ( V_104 && V_24 -> V_27 -> V_46 )
return;
if ( ! V_104 && ! V_24 -> V_27 -> V_46 )
return;
if ( ! F_18 ( V_19 ) ) {
if ( V_104 )
V_105 |= V_107 ;
switch ( V_22 -> V_108 ) {
case V_109 :
if ( V_104 ) {
F_38 ( V_110 , V_111 ) ;
V_105 |= F_39 ( V_112 ) ;
} else {
F_40 ( V_110 , ~ V_111 ) ;
}
break;
case V_113 :
if ( V_104 ) {
F_38 ( V_114 , V_115 ) ;
V_105 |= F_39 ( V_116 ) ;
} else {
F_40 ( V_114 , ~ V_115 ) ;
}
break;
case V_117 :
if ( V_104 ) {
F_38 ( V_118 , V_119 ) ;
V_105 |= F_39 ( V_120 ) ;
} else {
F_40 ( V_118 , ~ V_119 ) ;
}
break;
case V_121 :
if ( V_104 )
V_105 |= F_39 ( V_122 ) ;
break;
default:
F_41 ( V_19 -> V_17 , L_10 ,
V_22 -> V_108 ) ;
break;
}
F_6 ( V_123 + V_24 -> V_27 -> V_26 , V_105 ) ;
}
if ( V_19 -> V_124 . V_125 ) {
if ( V_104 )
F_42 ( V_19 , V_24 -> V_27 -> V_126 ) ;
else
F_43 ( V_19 , V_24 -> V_27 -> V_126 ) ;
}
V_24 -> V_27 -> V_46 = V_104 ;
F_2 ( L_11 ,
V_104 ? L_12 : L_13 , V_24 -> V_27 -> V_26 , V_22 -> V_108 ) ;
}
