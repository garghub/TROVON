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
void F_17 ( struct V_14 * V_15 , struct V_52 * V_53 )
{
struct V_16 * V_17 = V_15 -> V_17 ;
struct V_18 * V_19 = V_17 -> V_20 ;
struct V_22 * V_22 = F_5 ( V_15 ) ;
struct V_23 * V_24 = V_22 -> V_25 ;
T_2 V_34 [ V_54 + V_55 ] ;
struct V_56 V_36 ;
T_1 V_26 ;
T_6 V_57 ;
if ( ! V_24 -> V_27 -> V_46 )
return;
V_26 = V_24 -> V_27 -> V_26 ;
F_18 ( V_15 , V_53 -> clock ) ;
F_6 ( V_58 + V_26 ,
V_59 ) ;
F_6 ( V_60 + V_26 , 0x1000 ) ;
if ( F_19 ( V_19 ) ) {
F_6 ( V_51 + V_26 ,
F_20 ( 1 ) |
F_21 ( 3 ) ) ;
F_6 ( V_61 + V_26 ,
V_62 |
V_63 ) ;
} else {
F_6 ( V_51 + V_26 ,
V_64 |
F_20 ( 1 ) |
F_21 ( 3 ) |
V_65 ) ;
}
F_6 ( V_66 + V_26 ,
V_67 |
V_68 ) ;
F_6 ( V_58 + V_26 ,
V_59 |
V_69 |
V_70 ) ;
F_6 ( V_71 + V_26 ,
V_72 |
V_73 |
V_74 |
V_75 ) ;
F_6 ( V_76 + V_26 ,
F_22 ( 2 ) |
F_23 ( 2 ) ) ;
F_6 ( V_77 + V_26 , 0 ) ;
V_57 = F_24 ( & V_36 , V_53 ) ;
if ( V_57 < 0 ) {
F_25 ( L_2 , V_57 ) ;
return;
}
V_57 = F_26 ( & V_36 , V_34 , sizeof( V_34 ) ) ;
if ( V_57 < 0 ) {
F_25 ( L_3 , V_57 ) ;
return;
}
F_10 ( V_15 , V_34 , sizeof( V_34 ) ) ;
F_4 ( V_15 , V_53 -> clock ) ;
F_6 ( V_78 + V_26 , 0x00FFFFFF ) ;
F_6 ( V_79 + V_26 , 0x007FFFFF ) ;
F_6 ( V_80 + V_26 , 0x00000001 ) ;
F_6 ( V_81 + V_26 , 0x00000001 ) ;
F_15 ( V_15 ) ;
}
void F_27 ( struct V_14 * V_15 )
{
struct V_16 * V_17 = V_15 -> V_17 ;
struct V_18 * V_19 = V_17 -> V_20 ;
struct V_22 * V_22 = F_5 ( V_15 ) ;
struct V_23 * V_24 = V_22 -> V_25 ;
struct V_82 V_83 = F_28 ( V_19 ) ;
T_4 V_34 [ V_54 + V_84 ] ;
struct V_85 V_36 ;
T_1 V_26 ;
T_1 V_86 ;
T_6 V_57 ;
if ( ! V_24 -> V_27 || ! V_24 -> V_27 -> V_46 )
return;
V_26 = V_24 -> V_27 -> V_26 ;
F_2 ( L_4 ,
F_12 ( V_15 ) ? L_5 : L_6 ,
V_83 . V_87 , V_83 . V_88 , V_83 . V_89 ) ;
F_2 ( L_7 ,
( int ) V_83 . V_90 , ( int ) V_83 . V_91 ) ;
V_86 = 0 ;
if ( V_83 . V_90 & V_92 )
V_86 |= 1 << 0 ;
if ( V_83 . V_90 & V_93 )
V_86 |= 1 << 1 ;
if ( V_83 . V_90 & V_94 )
V_86 |= 1 << 2 ;
if ( V_83 . V_90 & V_95 )
V_86 |= 1 << 3 ;
V_86 |= F_29 ( V_83 . V_91 ) ;
switch ( V_83 . V_88 ) {
case 32000 :
V_86 |= F_30 ( 0x3 ) ;
break;
case 44100 :
V_86 |= F_30 ( 0x0 ) ;
break;
case 48000 :
V_86 |= F_30 ( 0x2 ) ;
break;
case 88200 :
V_86 |= F_30 ( 0x8 ) ;
break;
case 96000 :
V_86 |= F_30 ( 0xa ) ;
break;
case 176400 :
V_86 |= F_30 ( 0xc ) ;
break;
case 192000 :
V_86 |= F_30 ( 0xe ) ;
break;
}
F_6 ( V_96 + V_26 , V_86 ) ;
V_86 = 0 ;
switch ( V_83 . V_89 ) {
case 16 :
V_86 |= F_31 ( 0x2 ) ;
break;
case 20 :
V_86 |= F_31 ( 0x3 ) ;
break;
case 24 :
V_86 |= F_31 ( 0xb ) ;
break;
}
if ( V_83 . V_90 & V_97 )
V_86 |= 0x5 << 16 ;
F_16 ( V_98 + V_26 , V_86 , ~ 0x5000f ) ;
V_57 = F_32 ( & V_36 ) ;
if ( V_57 < 0 ) {
F_25 ( L_8 ) ;
return;
}
V_36 . V_87 = V_83 . V_87 ;
V_57 = F_33 ( & V_36 , V_34 , sizeof( V_34 ) ) ;
if ( V_57 < 0 ) {
F_25 ( L_9 ) ;
return;
}
F_11 ( V_15 , V_34 , sizeof( V_34 ) ) ;
F_15 ( V_15 ) ;
}
void F_34 ( struct V_14 * V_15 )
{
struct V_16 * V_17 = V_15 -> V_17 ;
struct V_18 * V_19 = V_17 -> V_20 ;
struct V_22 * V_22 = F_5 ( V_15 ) ;
struct V_23 * V_24 = V_22 -> V_25 ;
T_1 V_26 ;
T_5 V_99 ;
if ( F_35 ( V_19 ) )
return;
if ( V_24 -> V_27 -> V_46 )
return;
V_26 = V_24 -> V_27 -> V_26 ;
if ( V_19 -> V_100 >= V_101 && ! F_36 ( V_19 ) ) {
V_99 = V_102 | V_103 ;
switch ( V_22 -> V_104 ) {
case V_105 :
F_16 ( V_106 , V_107 ,
~ V_107 ) ;
V_99 |= F_37 ( V_108 ) ;
break;
case V_109 :
F_16 ( V_110 , V_111 ,
~ V_111 ) ;
V_99 |= F_37 ( V_112 ) ;
break;
case V_113 :
F_16 ( V_114 , V_115 , ~ V_115 ) ;
V_99 |= F_37 ( V_116 ) ;
break;
case V_117 :
V_99 |= F_37 ( V_118 ) ;
break;
default:
F_38 ( V_19 -> V_17 , L_10 ,
V_22 -> V_104 ) ;
break;
}
F_6 ( V_119 + V_26 , V_99 ) ;
}
if ( V_19 -> V_120 . V_121 ) {
F_39 ( V_19 , V_24 -> V_27 -> V_122 ) ;
}
V_24 -> V_27 -> V_46 = true ;
F_2 ( L_11 ,
V_26 , V_22 -> V_104 ) ;
}
void F_40 ( struct V_14 * V_15 )
{
struct V_16 * V_17 = V_15 -> V_17 ;
struct V_18 * V_19 = V_17 -> V_20 ;
struct V_22 * V_22 = F_5 ( V_15 ) ;
struct V_23 * V_24 = V_22 -> V_25 ;
T_1 V_26 ;
if ( F_35 ( V_19 ) )
return;
if ( ! V_24 || ! V_24 -> V_27 ) {
return;
}
if ( ! V_24 -> V_27 -> V_46 )
return;
V_26 = V_24 -> V_27 -> V_26 ;
F_2 ( L_12 ,
V_26 , V_22 -> V_104 ) ;
F_41 ( V_19 , V_24 -> V_27 -> V_122 ) ;
if ( V_19 -> V_100 >= V_101 && ! F_36 ( V_19 ) ) {
switch ( V_22 -> V_104 ) {
case V_105 :
F_16 ( V_106 , 0 ,
~ V_107 ) ;
break;
case V_109 :
F_16 ( V_110 , 0 ,
~ V_111 ) ;
break;
case V_113 :
F_16 ( V_114 , 0 , ~ V_115 ) ;
break;
case V_117 :
break;
default:
F_38 ( V_19 -> V_17 , L_10 ,
V_22 -> V_104 ) ;
break;
}
F_6 ( V_119 + V_26 , V_102 ) ;
}
V_24 -> V_27 -> V_46 = false ;
}
