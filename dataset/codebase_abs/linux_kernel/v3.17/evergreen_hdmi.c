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
V_41 = F_15 ( F_16 ( V_31 ) , & V_40 ) ;
if ( V_41 <= 0 ) {
F_11 ( L_2 , V_41 ) ;
return;
}
V_33 = F_17 ( V_42 ) ;
V_33 &= ~ ( V_43 | V_44 ) ;
V_33 |= V_45 ;
if ( V_41 )
V_33 |= F_18 ( V_40 [ 0 ] ) ;
else
V_33 |= F_18 ( 5 ) ;
F_4 ( V_42 , V_33 ) ;
F_19 ( V_40 ) ;
}
static void F_20 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = V_2 -> V_4 -> V_7 ;
struct V_30 * V_31 ;
struct V_32 * V_32 = NULL ;
struct V_46 * V_47 ;
int V_48 , V_41 ;
static const T_4 V_49 [] [ 2 ] = {
{ V_50 , V_51 } ,
{ V_52 , V_53 } ,
{ V_54 , V_55 } ,
{ V_56 , V_57 } ,
{ V_58 , V_59 } ,
{ V_60 , V_61 } ,
{ V_62 , V_63 } ,
{ V_64 , V_65 } ,
{ V_66 , V_67 } ,
{ V_68 , V_69 } ,
{ V_70 , V_71 } ,
{ V_72 , V_73 } ,
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
V_41 = F_21 ( F_16 ( V_31 ) , & V_47 ) ;
if ( V_41 <= 0 ) {
F_11 ( L_3 , V_41 ) ;
return;
}
F_22 ( ! V_47 ) ;
for ( V_48 = 0 ; V_48 < F_23 ( V_49 ) ; V_48 ++ ) {
T_2 V_74 = 0 ;
T_3 V_75 = 0 ;
int V_76 = - 1 ;
int V_77 ;
for ( V_77 = 0 ; V_77 < V_41 ; V_77 ++ ) {
struct V_46 * V_78 = & V_47 [ V_77 ] ;
if ( V_78 -> V_79 == V_49 [ V_48 ] [ 1 ] ) {
if ( V_78 -> V_80 > V_76 ) {
V_74 = F_24 ( V_78 -> V_80 ) |
F_25 ( V_78 -> V_81 ) |
F_26 ( V_78 -> V_82 ) ;
V_76 = V_78 -> V_80 ;
}
if ( V_78 -> V_79 == V_51 )
V_75 |= V_78 -> V_82 ;
else
break;
}
}
V_74 |= F_27 ( V_75 ) ;
F_4 ( V_49 [ V_48 ] [ 0 ] , V_74 ) ;
}
F_19 ( V_47 ) ;
}
static void F_28 ( struct V_1 * V_2 ,
void * V_83 , T_5 V_84 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_5 * V_6 = V_4 -> V_7 ;
struct V_10 * V_10 = F_3 ( V_2 ) ;
struct V_11 * V_12 = V_10 -> V_13 ;
T_1 V_14 = V_12 -> V_15 -> V_14 ;
T_6 * V_85 = V_83 + 3 ;
T_6 * V_86 = V_83 ;
F_4 ( V_87 + V_14 ,
V_85 [ 0x0 ] | ( V_85 [ 0x1 ] << 8 ) | ( V_85 [ 0x2 ] << 16 ) | ( V_85 [ 0x3 ] << 24 ) ) ;
F_4 ( V_88 + V_14 ,
V_85 [ 0x4 ] | ( V_85 [ 0x5 ] << 8 ) | ( V_85 [ 0x6 ] << 16 ) | ( V_85 [ 0x7 ] << 24 ) ) ;
F_4 ( V_89 + V_14 ,
V_85 [ 0x8 ] | ( V_85 [ 0x9 ] << 8 ) | ( V_85 [ 0xA ] << 16 ) | ( V_85 [ 0xB ] << 24 ) ) ;
F_4 ( V_90 + V_14 ,
V_85 [ 0xC ] | ( V_85 [ 0xD ] << 8 ) | ( V_86 [ 1 ] << 24 ) ) ;
}
static void F_29 ( struct V_1 * V_2 , T_2 clock )
{
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_5 * V_6 = V_4 -> V_7 ;
struct V_10 * V_10 = F_3 ( V_2 ) ;
struct V_11 * V_12 = V_10 -> V_13 ;
struct V_91 * V_91 = F_30 ( V_2 -> V_92 ) ;
T_2 V_93 = 24000 ;
T_2 V_94 = clock / V_93 ;
T_2 V_95 ;
T_2 V_96 = clock ;
T_2 V_97 ;
T_2 V_98 ;
if ( ! V_12 || ! V_12 -> V_15 )
return;
if ( F_31 ( V_6 ) ) {
V_95 = 24 * 1000 ;
} else {
if ( V_94 >= 8 ) {
V_95 = 192 * 1000 ;
V_97 = 3 ;
} else if ( V_94 >= 4 ) {
V_95 = 96 * 1000 ;
V_97 = 2 ;
} else if ( V_94 >= 2 ) {
V_95 = 48 * 1000 ;
V_97 = 1 ;
} else {
V_95 = 24 * 1000 ;
V_97 = 0 ;
}
V_98 = F_17 ( V_99 ) & ~ V_100 ;
V_98 |= F_32 ( V_97 ) ;
F_4 ( V_99 , V_98 ) ;
}
F_4 ( V_101 , F_33 ( V_91 -> V_102 ) ) ;
F_4 ( V_103 , V_95 ) ;
F_4 ( V_104 , V_96 ) ;
}
void F_34 ( struct V_1 * V_2 , struct V_28 * V_29 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_5 * V_6 = V_4 -> V_7 ;
struct V_10 * V_10 = F_3 ( V_2 ) ;
struct V_11 * V_12 = V_10 -> V_13 ;
struct V_30 * V_31 = F_35 ( V_2 ) ;
T_3 V_83 [ V_105 + V_106 ] ;
struct V_107 V_85 ;
T_1 V_14 ;
T_7 V_108 ;
T_1 V_109 ;
int V_110 = 8 ;
if ( ! V_12 || ! V_12 -> V_15 )
return;
if ( ! V_12 -> V_15 -> V_111 )
return;
V_14 = V_12 -> V_15 -> V_14 ;
if ( V_2 -> V_92 ) {
struct V_91 * V_91 = F_30 ( V_2 -> V_92 ) ;
V_110 = V_91 -> V_110 ;
}
if ( F_31 ( V_6 ) ) {
V_12 -> V_15 -> V_112 = F_36 ( V_6 ) ;
F_37 ( V_6 , V_12 -> V_15 -> V_112 , false ) ;
} else {
V_12 -> V_15 -> V_112 = F_38 ( V_6 ) ;
F_39 ( V_6 , V_12 -> V_15 -> V_112 , false ) ;
}
F_29 ( V_2 , V_29 -> clock ) ;
F_4 ( V_113 + V_14 ,
V_114 ) ;
F_4 ( V_115 + V_14 , 0x1000 ) ;
V_109 = F_17 ( V_116 + V_14 ) ;
V_109 &= ~ V_117 ;
V_109 &= ~ V_118 ;
switch ( V_110 ) {
case 0 :
case 6 :
case 8 :
case 16 :
default:
F_40 ( L_4 ,
V_31 -> V_119 , V_110 ) ;
break;
case 10 :
V_109 |= V_117 ;
V_109 |= F_41 ( V_120 ) ;
F_40 ( L_5 ,
V_31 -> V_119 ) ;
break;
case 12 :
V_109 |= V_117 ;
V_109 |= F_41 ( V_121 ) ;
F_40 ( L_6 ,
V_31 -> V_119 ) ;
break;
}
F_4 ( V_116 + V_14 , V_109 ) ;
F_4 ( V_113 + V_14 ,
V_114 |
V_122 |
V_123 ) ;
F_4 ( V_124 + V_14 ,
V_125 |
V_126 ) ;
F_4 ( V_127 + V_14 ,
V_128 ) ;
F_4 ( V_129 + V_14 ,
F_42 ( 2 ) ) ;
F_4 ( V_130 + V_14 , 0 ) ;
F_4 ( V_131 + V_14 ,
F_43 ( 1 ) |
F_44 ( 3 ) ) ;
F_4 ( V_132 + V_14 ,
V_133 ) ;
if ( V_110 > 8 )
F_4 ( V_134 + V_14 ,
V_135 ) ;
else
F_4 ( V_134 + V_14 ,
V_136 |
V_135 ) ;
F_1 ( V_2 , V_29 -> clock ) ;
F_4 ( V_137 + V_14 ,
F_45 ( 1 ) ) ;
F_4 ( V_138 + V_14 ,
F_46 ( 2 ) ) ;
F_4 ( V_139 + V_14 ,
F_47 ( 3 ) |
F_48 ( 4 ) |
F_49 ( 5 ) |
F_50 ( 6 ) |
F_51 ( 7 ) |
F_52 ( 8 ) ) ;
if ( F_31 ( V_6 ) ) {
F_53 ( V_2 ) ;
} else {
F_14 ( V_2 ) ;
}
F_4 ( V_140 + V_14 ,
F_54 ( 0xff ) ) ;
if ( F_31 ( V_6 ) ) {
F_55 ( V_2 ) ;
F_56 ( V_2 ) ;
F_57 ( V_2 , V_29 ) ;
} else {
F_20 ( V_2 ) ;
F_8 ( V_2 , V_29 ) ;
}
V_108 = F_58 ( & V_85 , V_29 ) ;
if ( V_108 < 0 ) {
F_11 ( L_7 , V_108 ) ;
return;
}
V_108 = F_59 ( & V_85 , V_83 , sizeof( V_83 ) ) ;
if ( V_108 < 0 ) {
F_11 ( L_8 , V_108 ) ;
return;
}
F_28 ( V_2 , V_83 , sizeof( V_83 ) ) ;
F_60 ( V_124 + V_14 ,
V_141 |
V_142 ) ;
F_61 ( V_129 + V_14 ,
F_62 ( 2 ) ,
~ V_143 ) ;
F_60 ( V_132 + V_14 ,
V_144 ) ;
F_4 ( V_145 + V_14 , 0x00FFFFFF ) ;
F_4 ( V_146 + V_14 , 0x007FFFFF ) ;
F_4 ( V_147 + V_14 , 0x00000001 ) ;
F_4 ( V_148 + V_14 , 0x00000001 ) ;
if ( F_31 ( V_6 ) )
F_37 ( V_6 , V_12 -> V_15 -> V_112 , true ) ;
else
F_39 ( V_6 , V_12 -> V_15 -> V_112 , true ) ;
}
void F_63 ( struct V_1 * V_2 , bool V_149 )
{
struct V_10 * V_10 = F_3 ( V_2 ) ;
struct V_11 * V_12 = V_10 -> V_13 ;
if ( ! V_12 || ! V_12 -> V_15 )
return;
if ( V_149 && V_12 -> V_15 -> V_111 )
return;
if ( ! V_149 && ! V_12 -> V_15 -> V_111 )
return;
V_12 -> V_15 -> V_111 = V_149 ;
F_40 ( L_9 ,
V_149 ? L_10 : L_11 , V_12 -> V_15 -> V_14 , V_10 -> V_150 ) ;
}
