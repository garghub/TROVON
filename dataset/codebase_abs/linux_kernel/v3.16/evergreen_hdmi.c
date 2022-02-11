static void F_1 ( struct V_1 * V_2 , T_1 clock )
{
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_5 * V_6 = V_4 -> V_7 ;
struct V_8 V_9 = F_2 ( clock ) ;
struct V_10 * V_10 = F_3 ( V_2 ) ;
struct V_11 * V_12 = V_10 -> V_13 ;
T_1 V_14 = V_12 -> V_15 -> V_14 ;
F_4 ( V_16 + V_14 , F_5 ( V_9 . V_17 ) ) ;
F_4 ( V_18 + V_14 , V_9 . V_19 ) ;
F_4 ( V_20 + V_14 , F_6 ( V_9 . V_21 ) ) ;
F_4 ( V_22 + V_14 , V_9 . V_23 ) ;
F_4 ( V_24 + V_14 , F_7 ( V_9 . V_25 ) ) ;
F_4 ( V_26 + V_14 , V_9 . V_27 ) ;
}
static void F_8 ( struct V_1 * V_2 ,
struct V_28 * V_29 )
{
struct V_5 * V_6 = V_2 -> V_4 -> V_7 ;
struct V_30 * V_31 ;
struct V_32 * V_32 = NULL ;
T_2 V_33 = 0 ;
F_9 (connector, &encoder->dev->mode_config.connector_list, head) {
if ( V_31 -> V_2 == V_2 ) {
V_32 = F_10 ( V_31 ) ;
break;
}
}
if ( ! V_32 ) {
F_11 ( L_1 ) ;
return;
}
if ( V_29 -> V_34 & V_35 ) {
if ( V_31 -> V_36 [ 1 ] )
V_33 = F_12 ( V_31 -> V_37 [ 1 ] ) |
F_13 ( V_31 -> V_38 [ 1 ] ) ;
else
V_33 = F_12 ( 255 ) | F_13 ( 255 ) ;
} else {
if ( V_31 -> V_36 [ 0 ] )
V_33 = F_12 ( V_31 -> V_37 [ 0 ] ) |
F_13 ( V_31 -> V_38 [ 0 ] ) ;
else
V_33 = F_12 ( 255 ) | F_13 ( 255 ) ;
}
F_4 ( V_39 , V_33 ) ;
}
static void F_14 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = V_2 -> V_4 -> V_7 ;
struct V_30 * V_31 ;
struct V_32 * V_32 = NULL ;
T_2 V_33 ;
T_3 * V_40 ;
int V_41 ;
F_9 (connector, &encoder->dev->mode_config.connector_list, head) {
if ( V_31 -> V_2 == V_2 ) {
V_32 = F_10 ( V_31 ) ;
break;
}
}
if ( ! V_32 ) {
F_11 ( L_1 ) ;
return;
}
V_41 = F_15 ( V_32 -> V_42 , & V_40 ) ;
if ( V_41 <= 0 ) {
F_11 ( L_2 , V_41 ) ;
return;
}
V_33 = F_16 ( V_43 ) ;
V_33 &= ~ ( V_44 | V_45 ) ;
V_33 |= V_46 ;
if ( V_41 )
V_33 |= F_17 ( V_40 [ 0 ] ) ;
else
V_33 |= F_17 ( 5 ) ;
F_4 ( V_43 , V_33 ) ;
F_18 ( V_40 ) ;
}
static void F_19 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = V_2 -> V_4 -> V_7 ;
struct V_30 * V_31 ;
struct V_32 * V_32 = NULL ;
struct V_47 * V_48 ;
int V_49 , V_41 ;
static const T_4 V_50 [] [ 2 ] = {
{ V_51 , V_52 } ,
{ V_53 , V_54 } ,
{ V_55 , V_56 } ,
{ V_57 , V_58 } ,
{ V_59 , V_60 } ,
{ V_61 , V_62 } ,
{ V_63 , V_64 } ,
{ V_65 , V_66 } ,
{ V_67 , V_68 } ,
{ V_69 , V_70 } ,
{ V_71 , V_72 } ,
{ V_73 , V_74 } ,
} ;
F_9 (connector, &encoder->dev->mode_config.connector_list, head) {
if ( V_31 -> V_2 == V_2 ) {
V_32 = F_10 ( V_31 ) ;
break;
}
}
if ( ! V_32 ) {
F_11 ( L_1 ) ;
return;
}
V_41 = F_20 ( V_32 -> V_42 , & V_48 ) ;
if ( V_41 <= 0 ) {
F_11 ( L_3 , V_41 ) ;
return;
}
F_21 ( ! V_48 ) ;
for ( V_49 = 0 ; V_49 < F_22 ( V_50 ) ; V_49 ++ ) {
T_2 V_75 = 0 ;
T_3 V_76 = 0 ;
int V_77 = - 1 ;
int V_78 ;
for ( V_78 = 0 ; V_78 < V_41 ; V_78 ++ ) {
struct V_47 * V_79 = & V_48 [ V_78 ] ;
if ( V_79 -> V_80 == V_50 [ V_49 ] [ 1 ] ) {
if ( V_79 -> V_81 > V_77 ) {
V_75 = F_23 ( V_79 -> V_81 ) |
F_24 ( V_79 -> V_82 ) |
F_25 ( V_79 -> V_83 ) ;
V_77 = V_79 -> V_81 ;
}
if ( V_79 -> V_80 == V_52 )
V_76 |= V_79 -> V_83 ;
else
break;
}
}
V_75 |= F_26 ( V_76 ) ;
F_4 ( V_50 [ V_49 ] [ 0 ] , V_75 ) ;
}
F_18 ( V_48 ) ;
}
static void F_27 ( struct V_1 * V_2 ,
void * V_84 , T_5 V_85 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_5 * V_6 = V_4 -> V_7 ;
struct V_10 * V_10 = F_3 ( V_2 ) ;
struct V_11 * V_12 = V_10 -> V_13 ;
T_1 V_14 = V_12 -> V_15 -> V_14 ;
T_6 * V_86 = V_84 + 3 ;
T_6 * V_87 = V_84 ;
F_4 ( V_88 + V_14 ,
V_86 [ 0x0 ] | ( V_86 [ 0x1 ] << 8 ) | ( V_86 [ 0x2 ] << 16 ) | ( V_86 [ 0x3 ] << 24 ) ) ;
F_4 ( V_89 + V_14 ,
V_86 [ 0x4 ] | ( V_86 [ 0x5 ] << 8 ) | ( V_86 [ 0x6 ] << 16 ) | ( V_86 [ 0x7 ] << 24 ) ) ;
F_4 ( V_90 + V_14 ,
V_86 [ 0x8 ] | ( V_86 [ 0x9 ] << 8 ) | ( V_86 [ 0xA ] << 16 ) | ( V_86 [ 0xB ] << 24 ) ) ;
F_4 ( V_91 + V_14 ,
V_86 [ 0xC ] | ( V_86 [ 0xD ] << 8 ) | ( V_87 [ 1 ] << 24 ) ) ;
}
static void F_28 ( struct V_1 * V_2 , T_2 clock )
{
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_5 * V_6 = V_4 -> V_7 ;
struct V_10 * V_10 = F_3 ( V_2 ) ;
struct V_11 * V_12 = V_10 -> V_13 ;
struct V_92 * V_92 = F_29 ( V_2 -> V_93 ) ;
T_2 V_94 = 24000 ;
T_2 V_95 = clock / V_94 ;
T_2 V_96 ;
T_2 V_97 = clock ;
T_2 V_98 ;
T_2 V_99 ;
if ( ! V_12 || ! V_12 -> V_15 )
return;
if ( F_30 ( V_6 ) ) {
V_96 = 24 * 1000 ;
} else {
if ( V_95 >= 8 ) {
V_96 = 192 * 1000 ;
V_98 = 3 ;
} else if ( V_95 >= 4 ) {
V_96 = 96 * 1000 ;
V_98 = 2 ;
} else if ( V_95 >= 2 ) {
V_96 = 48 * 1000 ;
V_98 = 1 ;
} else {
V_96 = 24 * 1000 ;
V_98 = 0 ;
}
V_99 = F_16 ( V_100 ) & ~ V_101 ;
V_99 |= F_31 ( V_98 ) ;
F_4 ( V_100 , V_99 ) ;
}
F_4 ( V_102 , F_32 ( V_92 -> V_103 ) ) ;
F_4 ( V_104 , V_96 ) ;
F_4 ( V_105 , V_97 ) ;
}
void F_33 ( struct V_1 * V_2 , struct V_28 * V_29 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_5 * V_6 = V_4 -> V_7 ;
struct V_10 * V_10 = F_3 ( V_2 ) ;
struct V_11 * V_12 = V_10 -> V_13 ;
struct V_30 * V_31 = F_34 ( V_2 ) ;
T_3 V_84 [ V_106 + V_107 ] ;
struct V_108 V_86 ;
T_1 V_14 ;
T_7 V_109 ;
T_1 V_110 ;
int V_111 = 8 ;
if ( ! V_12 || ! V_12 -> V_15 )
return;
if ( ! V_12 -> V_15 -> V_112 )
return;
V_14 = V_12 -> V_15 -> V_14 ;
if ( V_2 -> V_93 ) {
struct V_92 * V_92 = F_29 ( V_2 -> V_93 ) ;
V_111 = V_92 -> V_111 ;
}
if ( F_30 ( V_6 ) ) {
V_12 -> V_15 -> V_113 = F_35 ( V_6 ) ;
F_36 ( V_6 , V_12 -> V_15 -> V_113 , false ) ;
} else {
V_12 -> V_15 -> V_113 = F_37 ( V_6 ) ;
F_38 ( V_6 , V_12 -> V_15 -> V_113 , false ) ;
}
F_28 ( V_2 , V_29 -> clock ) ;
F_4 ( V_114 + V_14 ,
V_115 ) ;
F_4 ( V_116 + V_14 , 0x1000 ) ;
V_110 = F_16 ( V_117 + V_14 ) ;
V_110 &= ~ V_118 ;
V_110 &= ~ V_119 ;
switch ( V_111 ) {
case 0 :
case 6 :
case 8 :
case 16 :
default:
F_39 ( L_4 ,
V_31 -> V_120 , V_111 ) ;
break;
case 10 :
V_110 |= V_118 ;
V_110 |= F_40 ( V_121 ) ;
F_39 ( L_5 ,
V_31 -> V_120 ) ;
break;
case 12 :
V_110 |= V_118 ;
V_110 |= F_40 ( V_122 ) ;
F_39 ( L_6 ,
V_31 -> V_120 ) ;
break;
}
F_4 ( V_117 + V_14 , V_110 ) ;
F_4 ( V_114 + V_14 ,
V_115 |
V_123 |
V_124 ) ;
F_4 ( V_125 + V_14 ,
V_126 |
V_127 ) ;
F_4 ( V_128 + V_14 ,
V_129 ) ;
F_4 ( V_130 + V_14 ,
F_41 ( 2 ) ) ;
F_4 ( V_131 + V_14 , 0 ) ;
F_4 ( V_132 + V_14 ,
F_42 ( 1 ) |
F_43 ( 3 ) ) ;
F_4 ( V_133 + V_14 ,
V_134 ) ;
if ( V_111 > 8 )
F_4 ( V_135 + V_14 ,
V_136 ) ;
else
F_4 ( V_135 + V_14 ,
V_137 |
V_136 ) ;
F_1 ( V_2 , V_29 -> clock ) ;
F_4 ( V_138 + V_14 ,
F_44 ( 1 ) ) ;
F_4 ( V_139 + V_14 ,
F_45 ( 2 ) ) ;
F_4 ( V_140 + V_14 ,
F_46 ( 3 ) |
F_47 ( 4 ) |
F_48 ( 5 ) |
F_49 ( 6 ) |
F_50 ( 7 ) |
F_51 ( 8 ) ) ;
if ( F_30 ( V_6 ) ) {
F_52 ( V_2 ) ;
} else {
F_14 ( V_2 ) ;
}
F_4 ( V_141 + V_14 ,
F_53 ( 0xff ) ) ;
if ( F_30 ( V_6 ) ) {
F_54 ( V_2 ) ;
F_55 ( V_2 ) ;
F_56 ( V_2 , V_29 ) ;
} else {
F_19 ( V_2 ) ;
F_8 ( V_2 , V_29 ) ;
}
V_109 = F_57 ( & V_86 , V_29 ) ;
if ( V_109 < 0 ) {
F_11 ( L_7 , V_109 ) ;
return;
}
V_109 = F_58 ( & V_86 , V_84 , sizeof( V_84 ) ) ;
if ( V_109 < 0 ) {
F_11 ( L_8 , V_109 ) ;
return;
}
F_27 ( V_2 , V_84 , sizeof( V_84 ) ) ;
F_59 ( V_125 + V_14 ,
V_142 |
V_143 ) ;
F_60 ( V_130 + V_14 ,
F_61 ( 2 ) ,
~ V_144 ) ;
F_59 ( V_133 + V_14 ,
V_145 ) ;
F_4 ( V_146 + V_14 , 0x00FFFFFF ) ;
F_4 ( V_147 + V_14 , 0x007FFFFF ) ;
F_4 ( V_148 + V_14 , 0x00000001 ) ;
F_4 ( V_149 + V_14 , 0x00000001 ) ;
if ( F_30 ( V_6 ) )
F_36 ( V_6 , V_12 -> V_15 -> V_113 , true ) ;
else
F_38 ( V_6 , V_12 -> V_15 -> V_113 , true ) ;
}
void F_62 ( struct V_1 * V_2 , bool V_150 )
{
struct V_10 * V_10 = F_3 ( V_2 ) ;
struct V_11 * V_12 = V_10 -> V_13 ;
if ( ! V_12 || ! V_12 -> V_15 )
return;
if ( V_150 && V_12 -> V_15 -> V_112 )
return;
if ( ! V_150 && ! V_12 -> V_15 -> V_112 )
return;
V_12 -> V_15 -> V_112 = V_150 ;
F_39 ( L_9 ,
V_150 ? L_10 : L_11 , V_12 -> V_15 -> V_14 , V_10 -> V_151 ) ;
}
