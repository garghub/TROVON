static void F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
T_1 V_5 )
{
T_2 V_6 = F_2 ( V_7 ) ;
if ( ! V_4 )
return;
if ( V_5 ) {
V_6 |= V_8 ;
if ( V_5 & 1 )
V_6 |= V_9 ;
if ( V_5 & 2 )
V_6 |= V_10 ;
if ( V_5 & 4 )
V_6 |= V_11 ;
if ( V_5 & 8 )
V_6 |= V_12 ;
} else {
V_6 &= ~ ( V_8 |
V_9 |
V_10 |
V_11 |
V_12 ) ;
}
F_3 ( V_7 , V_6 ) ;
}
static void F_4 ( struct V_13 * V_14 , T_3 clock )
{
struct V_15 * V_16 = V_14 -> V_16 ;
struct V_1 * V_2 = V_16 -> V_17 ;
struct V_18 V_19 = F_5 ( clock ) ;
struct V_20 * V_20 = F_6 ( V_14 ) ;
struct V_21 * V_22 = V_20 -> V_23 ;
T_3 V_24 = V_22 -> V_25 -> V_24 ;
F_3 ( V_26 + V_24 , F_7 ( V_19 . V_27 ) ) ;
F_3 ( V_28 + V_24 , V_19 . V_29 ) ;
F_3 ( V_30 + V_24 , F_8 ( V_19 . V_31 ) ) ;
F_3 ( V_32 + V_24 , V_19 . V_33 ) ;
F_3 ( V_34 + V_24 , F_9 ( V_19 . V_35 ) ) ;
F_3 ( V_36 + V_24 , V_19 . V_37 ) ;
}
static void F_10 ( struct V_13 * V_14 ,
struct V_38 * V_39 )
{
struct V_1 * V_2 = V_14 -> V_16 -> V_17 ;
struct V_40 * V_41 ;
struct V_42 * V_42 = NULL ;
T_2 V_6 = 0 ;
F_11 (connector, &encoder->dev->mode_config.connector_list, head) {
if ( V_41 -> V_14 == V_14 ) {
V_42 = F_12 ( V_41 ) ;
break;
}
}
if ( ! V_42 ) {
F_13 ( L_1 ) ;
return;
}
if ( V_39 -> V_43 & V_44 ) {
if ( V_41 -> V_45 [ 1 ] )
V_6 = F_14 ( V_41 -> V_46 [ 1 ] ) |
F_15 ( V_41 -> V_47 [ 1 ] ) ;
else
V_6 = F_14 ( 255 ) | F_15 ( 255 ) ;
} else {
if ( V_41 -> V_45 [ 0 ] )
V_6 = F_14 ( V_41 -> V_46 [ 0 ] ) |
F_15 ( V_41 -> V_47 [ 0 ] ) ;
else
V_6 = F_14 ( 255 ) | F_15 ( 255 ) ;
}
F_3 ( V_48 , V_6 ) ;
}
static void F_16 ( struct V_13 * V_14 )
{
struct V_1 * V_2 = V_14 -> V_16 -> V_17 ;
struct V_40 * V_41 ;
struct V_42 * V_42 = NULL ;
T_2 V_6 ;
T_1 * V_49 = NULL ;
int V_50 ;
F_11 (connector, &encoder->dev->mode_config.connector_list, head) {
if ( V_41 -> V_14 == V_14 ) {
V_42 = F_12 ( V_41 ) ;
break;
}
}
if ( ! V_42 ) {
F_13 ( L_1 ) ;
return;
}
V_50 = F_17 ( F_18 ( V_41 ) , & V_49 ) ;
if ( V_50 < 0 ) {
F_19 ( L_2 , V_50 ) ;
V_50 = 0 ;
}
V_6 = F_2 ( V_51 ) ;
V_6 &= ~ ( V_52 | V_53 ) ;
V_6 |= V_54 ;
if ( V_50 )
V_6 |= F_20 ( V_49 [ 0 ] ) ;
else
V_6 |= F_20 ( 5 ) ;
F_3 ( V_51 , V_6 ) ;
F_21 ( V_49 ) ;
}
static void F_22 ( struct V_13 * V_14 )
{
struct V_1 * V_2 = V_14 -> V_16 -> V_17 ;
struct V_40 * V_41 ;
struct V_42 * V_42 = NULL ;
struct V_55 * V_56 ;
int V_57 , V_50 ;
static const T_4 V_58 [] [ 2 ] = {
{ V_59 , V_60 } ,
{ V_61 , V_62 } ,
{ V_63 , V_64 } ,
{ V_65 , V_66 } ,
{ V_67 , V_68 } ,
{ V_69 , V_70 } ,
{ V_71 , V_72 } ,
{ V_73 , V_74 } ,
{ V_75 , V_76 } ,
{ V_77 , V_78 } ,
{ V_79 , V_80 } ,
{ V_81 , V_82 } ,
} ;
F_11 (connector, &encoder->dev->mode_config.connector_list, head) {
if ( V_41 -> V_14 == V_14 ) {
V_42 = F_12 ( V_41 ) ;
break;
}
}
if ( ! V_42 ) {
F_13 ( L_1 ) ;
return;
}
V_50 = F_23 ( F_18 ( V_41 ) , & V_56 ) ;
if ( V_50 <= 0 ) {
F_13 ( L_3 , V_50 ) ;
return;
}
F_24 ( ! V_56 ) ;
for ( V_57 = 0 ; V_57 < F_25 ( V_58 ) ; V_57 ++ ) {
T_2 V_83 = 0 ;
T_1 V_84 = 0 ;
int V_85 = - 1 ;
int V_86 ;
for ( V_86 = 0 ; V_86 < V_50 ; V_86 ++ ) {
struct V_55 * V_87 = & V_56 [ V_86 ] ;
if ( V_87 -> V_88 == V_58 [ V_57 ] [ 1 ] ) {
if ( V_87 -> V_89 > V_85 ) {
V_83 = F_26 ( V_87 -> V_89 ) |
F_27 ( V_87 -> V_90 ) |
F_28 ( V_87 -> V_91 ) ;
V_85 = V_87 -> V_89 ;
}
if ( V_87 -> V_88 == V_60 )
V_84 |= V_87 -> V_91 ;
else
break;
}
}
V_83 |= F_29 ( V_84 ) ;
F_3 ( V_58 [ V_57 ] [ 0 ] , V_83 ) ;
}
F_21 ( V_56 ) ;
}
static void F_30 ( struct V_13 * V_14 ,
void * V_92 , T_5 V_93 )
{
struct V_15 * V_16 = V_14 -> V_16 ;
struct V_1 * V_2 = V_16 -> V_17 ;
struct V_20 * V_20 = F_6 ( V_14 ) ;
struct V_21 * V_22 = V_20 -> V_23 ;
T_3 V_24 = V_22 -> V_25 -> V_24 ;
T_6 * V_94 = V_92 + 3 ;
T_6 * V_95 = V_92 ;
F_3 ( V_96 + V_24 ,
V_94 [ 0x0 ] | ( V_94 [ 0x1 ] << 8 ) | ( V_94 [ 0x2 ] << 16 ) | ( V_94 [ 0x3 ] << 24 ) ) ;
F_3 ( V_97 + V_24 ,
V_94 [ 0x4 ] | ( V_94 [ 0x5 ] << 8 ) | ( V_94 [ 0x6 ] << 16 ) | ( V_94 [ 0x7 ] << 24 ) ) ;
F_3 ( V_98 + V_24 ,
V_94 [ 0x8 ] | ( V_94 [ 0x9 ] << 8 ) | ( V_94 [ 0xA ] << 16 ) | ( V_94 [ 0xB ] << 24 ) ) ;
F_3 ( V_99 + V_24 ,
V_94 [ 0xC ] | ( V_94 [ 0xD ] << 8 ) | ( V_95 [ 1 ] << 24 ) ) ;
}
static void F_31 ( struct V_13 * V_14 , T_2 clock )
{
struct V_15 * V_16 = V_14 -> V_16 ;
struct V_1 * V_2 = V_16 -> V_17 ;
struct V_20 * V_20 = F_6 ( V_14 ) ;
struct V_21 * V_22 = V_20 -> V_23 ;
struct V_100 * V_100 = F_32 ( V_14 -> V_101 ) ;
T_2 V_102 = 24000 ;
T_2 V_103 = clock / V_102 ;
T_2 V_104 ;
T_2 V_105 = clock ;
T_2 V_106 ;
T_2 V_107 ;
if ( ! V_22 || ! V_22 -> V_25 )
return;
if ( F_33 ( V_2 ) ) {
V_104 = 24 * 1000 ;
} else {
if ( V_103 >= 8 ) {
V_104 = 192 * 1000 ;
V_106 = 3 ;
} else if ( V_103 >= 4 ) {
V_104 = 96 * 1000 ;
V_106 = 2 ;
} else if ( V_103 >= 2 ) {
V_104 = 48 * 1000 ;
V_106 = 1 ;
} else {
V_104 = 24 * 1000 ;
V_106 = 0 ;
}
V_107 = F_2 ( V_108 ) & ~ V_109 ;
V_107 |= F_34 ( V_106 ) ;
F_3 ( V_108 , V_107 ) ;
}
F_3 ( V_110 , F_35 ( V_100 -> V_111 ) ) ;
F_3 ( V_112 , V_104 ) ;
F_3 ( V_113 , V_105 ) ;
}
void F_36 ( struct V_13 * V_14 , struct V_38 * V_39 )
{
struct V_15 * V_16 = V_14 -> V_16 ;
struct V_1 * V_2 = V_16 -> V_17 ;
struct V_20 * V_20 = F_6 ( V_14 ) ;
struct V_21 * V_22 = V_20 -> V_23 ;
struct V_40 * V_41 = F_37 ( V_14 ) ;
T_1 V_92 [ V_114 + V_115 ] ;
struct V_116 V_94 ;
T_3 V_24 ;
T_7 V_117 ;
T_3 V_118 ;
int V_119 = 8 ;
if ( ! V_22 || ! V_22 -> V_25 )
return;
if ( ! V_22 -> V_25 -> V_120 )
return;
V_24 = V_22 -> V_25 -> V_24 ;
if ( V_14 -> V_101 ) {
struct V_100 * V_100 = F_32 ( V_14 -> V_101 ) ;
V_119 = V_100 -> V_119 ;
}
if ( F_33 ( V_2 ) ) {
V_22 -> V_25 -> V_4 = F_38 ( V_2 ) ;
F_39 ( V_2 , V_22 -> V_25 -> V_4 , 0 ) ;
} else {
V_22 -> V_25 -> V_4 = F_40 ( V_2 ) ;
F_1 ( V_2 , V_22 -> V_25 -> V_4 , 0 ) ;
}
F_31 ( V_14 , V_39 -> clock ) ;
F_3 ( V_121 + V_24 ,
V_122 ) ;
F_3 ( V_123 + V_24 , 0x1000 ) ;
V_118 = F_2 ( V_124 + V_24 ) ;
V_118 &= ~ V_125 ;
V_118 &= ~ V_126 ;
switch ( V_119 ) {
case 0 :
case 6 :
case 8 :
case 16 :
default:
F_19 ( L_4 ,
V_41 -> V_127 , V_119 ) ;
break;
case 10 :
V_118 |= V_125 ;
V_118 |= F_41 ( V_128 ) ;
F_19 ( L_5 ,
V_41 -> V_127 ) ;
break;
case 12 :
V_118 |= V_125 ;
V_118 |= F_41 ( V_129 ) ;
F_19 ( L_6 ,
V_41 -> V_127 ) ;
break;
}
F_3 ( V_124 + V_24 , V_118 ) ;
F_3 ( V_121 + V_24 ,
V_122 |
V_130 |
V_131 ) ;
F_3 ( V_132 + V_24 ,
V_133 |
V_134 ) ;
F_3 ( V_135 + V_24 ,
V_136 ) ;
F_3 ( V_137 + V_24 ,
F_42 ( 2 ) ) ;
F_3 ( V_138 + V_24 , 0 ) ;
F_3 ( V_139 + V_24 ,
F_43 ( 1 ) |
F_44 ( 3 ) ) ;
F_3 ( V_140 + V_24 ,
V_141 ) ;
if ( V_119 > 8 )
F_3 ( V_142 + V_24 ,
V_143 ) ;
else
F_3 ( V_142 + V_24 ,
V_144 |
V_143 ) ;
F_4 ( V_14 , V_39 -> clock ) ;
F_3 ( V_145 + V_24 ,
F_45 ( 1 ) ) ;
F_3 ( V_146 + V_24 ,
F_46 ( 2 ) ) ;
F_3 ( V_147 + V_24 ,
F_47 ( 3 ) |
F_48 ( 4 ) |
F_49 ( 5 ) |
F_50 ( 6 ) |
F_51 ( 7 ) |
F_52 ( 8 ) ) ;
if ( F_33 ( V_2 ) ) {
F_53 ( V_14 ) ;
} else {
F_16 ( V_14 ) ;
}
F_3 ( V_148 + V_24 ,
F_54 ( 0xff ) ) ;
if ( F_33 ( V_2 ) ) {
F_55 ( V_14 ) ;
F_56 ( V_14 ) ;
F_57 ( V_14 , V_39 ) ;
} else {
F_22 ( V_14 ) ;
F_10 ( V_14 , V_39 ) ;
}
V_117 = F_58 ( & V_94 , V_39 ) ;
if ( V_117 < 0 ) {
F_13 ( L_7 , V_117 ) ;
return;
}
V_117 = F_59 ( & V_94 , V_92 , sizeof( V_92 ) ) ;
if ( V_117 < 0 ) {
F_13 ( L_8 , V_117 ) ;
return;
}
F_30 ( V_14 , V_92 , sizeof( V_92 ) ) ;
F_60 ( V_132 + V_24 ,
V_149 |
V_150 ) ;
F_61 ( V_137 + V_24 ,
F_62 ( 2 ) ,
~ V_151 ) ;
F_60 ( V_140 + V_24 ,
V_152 ) ;
F_3 ( V_153 + V_24 , 0x00FFFFFF ) ;
F_3 ( V_154 + V_24 , 0x007FFFFF ) ;
F_3 ( V_155 + V_24 , 0x00000001 ) ;
F_3 ( V_156 + V_24 , 0x00000001 ) ;
if ( F_33 ( V_2 ) )
F_39 ( V_2 , V_22 -> V_25 -> V_4 , 1 ) ;
else
F_1 ( V_2 , V_22 -> V_25 -> V_4 , 0xf ) ;
}
void F_63 ( struct V_13 * V_14 , bool V_157 )
{
struct V_15 * V_16 = V_14 -> V_16 ;
struct V_1 * V_2 = V_16 -> V_17 ;
struct V_20 * V_20 = F_6 ( V_14 ) ;
struct V_21 * V_22 = V_20 -> V_23 ;
if ( ! V_22 || ! V_22 -> V_25 )
return;
if ( V_157 && V_22 -> V_25 -> V_120 )
return;
if ( ! V_157 && ! V_22 -> V_25 -> V_120 )
return;
if ( ! V_157 && V_22 -> V_25 -> V_4 ) {
if ( F_33 ( V_2 ) )
F_39 ( V_2 , V_22 -> V_25 -> V_4 , 0 ) ;
else
F_1 ( V_2 , V_22 -> V_25 -> V_4 , 0 ) ;
V_22 -> V_25 -> V_4 = NULL ;
}
V_22 -> V_25 -> V_120 = V_157 ;
F_19 ( L_9 ,
V_157 ? L_10 : L_11 , V_22 -> V_25 -> V_24 , V_20 -> V_158 ) ;
}
