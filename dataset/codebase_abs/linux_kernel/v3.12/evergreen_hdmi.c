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
static void F_8 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = V_2 -> V_4 -> V_7 ;
struct V_28 * V_29 ;
struct V_30 * V_30 = NULL ;
T_2 V_31 ;
T_3 * V_32 ;
int V_33 ;
return;
F_9 (connector, &encoder->dev->mode_config.connector_list, head) {
if ( V_29 -> V_2 == V_2 )
V_30 = F_10 ( V_29 ) ;
}
if ( ! V_30 ) {
F_11 ( L_1 ) ;
return;
}
V_33 = F_12 ( V_30 -> V_34 , & V_32 ) ;
if ( V_33 < 0 ) {
F_11 ( L_2 , V_33 ) ;
return;
}
V_31 = F_13 ( V_35 ) ;
V_31 &= ~ ( V_36 | V_37 ) ;
V_31 |= V_38 ;
if ( V_33 )
V_31 |= F_14 ( V_32 [ 0 ] ) ;
else
V_31 |= F_14 ( 5 ) ;
F_4 ( V_35 , V_31 ) ;
F_15 ( V_32 ) ;
}
static void F_16 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = V_2 -> V_4 -> V_7 ;
struct V_28 * V_29 ;
struct V_30 * V_30 = NULL ;
struct V_39 * V_40 ;
int V_41 , V_33 ;
static const T_4 V_42 [] [ 2 ] = {
{ V_43 , V_44 } ,
{ V_45 , V_46 } ,
{ V_47 , V_48 } ,
{ V_49 , V_50 } ,
{ V_51 , V_52 } ,
{ V_53 , V_54 } ,
{ V_55 , V_56 } ,
{ V_57 , V_58 } ,
{ V_59 , V_60 } ,
{ V_61 , V_62 } ,
{ V_63 , V_64 } ,
{ V_65 , V_66 } ,
} ;
F_9 (connector, &encoder->dev->mode_config.connector_list, head) {
if ( V_29 -> V_2 == V_2 )
V_30 = F_10 ( V_29 ) ;
}
if ( ! V_30 ) {
F_11 ( L_1 ) ;
return;
}
V_33 = F_17 ( V_30 -> V_34 , & V_40 ) ;
if ( V_33 < 0 ) {
F_11 ( L_3 , V_33 ) ;
return;
}
F_18 ( ! V_40 ) ;
for ( V_41 = 0 ; V_41 < F_19 ( V_42 ) ; V_41 ++ ) {
T_2 V_67 = 0 ;
int V_68 ;
for ( V_68 = 0 ; V_68 < V_33 ; V_68 ++ ) {
struct V_39 * V_69 = & V_40 [ V_68 ] ;
if ( V_69 -> V_70 == V_42 [ V_41 ] [ 1 ] ) {
V_67 = F_20 ( V_69 -> V_71 ) |
F_21 ( V_69 -> V_72 ) |
F_22 ( V_69 -> V_73 ) ;
if ( V_69 -> V_70 == V_44 )
V_67 |= F_23 ( V_69 -> V_73 ) ;
break;
}
}
F_4 ( V_42 [ V_41 ] [ 0 ] , V_67 ) ;
}
F_15 ( V_40 ) ;
}
static void F_24 ( struct V_1 * V_2 ,
void * V_74 , T_5 V_75 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_5 * V_6 = V_4 -> V_7 ;
struct V_10 * V_10 = F_3 ( V_2 ) ;
struct V_11 * V_12 = V_10 -> V_13 ;
T_1 V_14 = V_12 -> V_15 -> V_14 ;
T_6 * V_76 = V_74 + 3 ;
T_6 * V_77 = V_74 ;
F_4 ( V_78 + V_14 ,
V_76 [ 0x0 ] | ( V_76 [ 0x1 ] << 8 ) | ( V_76 [ 0x2 ] << 16 ) | ( V_76 [ 0x3 ] << 24 ) ) ;
F_4 ( V_79 + V_14 ,
V_76 [ 0x4 ] | ( V_76 [ 0x5 ] << 8 ) | ( V_76 [ 0x6 ] << 16 ) | ( V_76 [ 0x7 ] << 24 ) ) ;
F_4 ( V_80 + V_14 ,
V_76 [ 0x8 ] | ( V_76 [ 0x9 ] << 8 ) | ( V_76 [ 0xA ] << 16 ) | ( V_76 [ 0xB ] << 24 ) ) ;
F_4 ( V_81 + V_14 ,
V_76 [ 0xC ] | ( V_76 [ 0xD ] << 8 ) | ( V_77 [ 1 ] << 24 ) ) ;
}
static void F_25 ( struct V_1 * V_2 , T_2 clock )
{
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_5 * V_6 = V_4 -> V_7 ;
struct V_10 * V_10 = F_3 ( V_2 ) ;
struct V_11 * V_12 = V_10 -> V_13 ;
struct V_82 * V_82 = F_26 ( V_2 -> V_83 ) ;
T_2 V_84 = 24000 ;
T_2 V_85 = clock / V_84 ;
T_2 V_86 ;
T_2 V_87 = clock ;
T_2 V_88 ;
T_2 V_89 ;
if ( ! V_12 || ! V_12 -> V_15 )
return;
if ( F_27 ( V_6 ) ) {
V_86 = 24 * 1000 ;
} else {
if ( V_85 >= 8 ) {
V_86 = 192 * 1000 ;
V_88 = 3 ;
} else if ( V_85 >= 4 ) {
V_86 = 96 * 1000 ;
V_88 = 2 ;
} else if ( V_85 >= 2 ) {
V_86 = 48 * 1000 ;
V_88 = 1 ;
} else {
V_86 = 24 * 1000 ;
V_88 = 0 ;
}
V_89 = F_13 ( V_90 ) & ~ V_91 ;
V_89 |= F_28 ( V_88 ) ;
F_4 ( V_90 , V_89 ) ;
}
F_4 ( V_92 , F_29 ( V_82 -> V_93 ) ) ;
F_4 ( V_94 , V_86 ) ;
F_4 ( V_95 , V_87 ) ;
}
void F_30 ( struct V_1 * V_2 , struct V_96 * V_97 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_5 * V_6 = V_4 -> V_7 ;
struct V_10 * V_10 = F_3 ( V_2 ) ;
struct V_11 * V_12 = V_10 -> V_13 ;
T_3 V_74 [ V_98 + V_99 ] ;
struct V_100 V_76 ;
T_1 V_14 ;
T_7 V_101 ;
if ( ! V_12 || ! V_12 -> V_15 )
return;
if ( ! V_12 -> V_15 -> V_102 )
return;
V_14 = V_12 -> V_15 -> V_14 ;
F_25 ( V_2 , V_97 -> clock ) ;
F_4 ( V_103 + V_14 ,
V_104 ) ;
F_4 ( V_105 + V_14 , 0x1000 ) ;
F_4 ( V_103 + V_14 ,
V_104 |
V_106 |
V_107 ) ;
F_4 ( V_108 + V_14 ,
V_109 |
V_110 ) ;
F_4 ( V_111 + V_14 ,
V_112 ) ;
F_4 ( V_113 + V_14 ,
F_31 ( 2 ) ) ;
F_4 ( V_114 + V_14 , 0 ) ;
F_4 ( V_115 + V_14 ,
F_32 ( 1 ) |
F_33 ( 3 ) ) ;
F_4 ( V_116 + V_14 ,
V_117 ) ;
F_4 ( V_118 + V_14 ,
V_119 |
V_120 ) ;
F_1 ( V_2 , V_97 -> clock ) ;
F_4 ( V_121 + V_14 ,
F_34 ( 1 ) ) ;
F_4 ( V_122 + V_14 ,
F_35 ( 2 ) ) ;
F_4 ( V_123 + V_14 ,
F_36 ( 3 ) |
F_37 ( 4 ) |
F_38 ( 5 ) |
F_39 ( 6 ) |
F_40 ( 7 ) |
F_41 ( 8 ) ) ;
if ( F_27 ( V_6 ) ) {
F_42 ( V_2 ) ;
} else {
F_8 ( V_2 ) ;
}
F_4 ( V_124 + V_14 ,
F_43 ( 0xff ) ) ;
if ( F_27 ( V_6 ) ) {
F_44 ( V_2 ) ;
F_45 ( V_2 ) ;
} else {
F_16 ( V_2 ) ;
}
V_101 = F_46 ( & V_76 , V_97 ) ;
if ( V_101 < 0 ) {
F_11 ( L_4 , V_101 ) ;
return;
}
V_101 = F_47 ( & V_76 , V_74 , sizeof( V_74 ) ) ;
if ( V_101 < 0 ) {
F_11 ( L_5 , V_101 ) ;
return;
}
F_24 ( V_2 , V_74 , sizeof( V_74 ) ) ;
F_48 ( V_108 + V_14 ,
V_125 |
V_126 ) ;
F_49 ( V_113 + V_14 ,
F_50 ( 2 ) ,
~ V_127 ) ;
F_48 ( V_116 + V_14 ,
V_128 ) ;
F_4 ( V_129 + V_14 , 0x00FFFFFF ) ;
F_4 ( V_130 + V_14 , 0x007FFFFF ) ;
F_4 ( V_131 + V_14 , 0x00000001 ) ;
F_4 ( V_132 + V_14 , 0x00000001 ) ;
}
void F_51 ( struct V_1 * V_2 , bool V_133 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_5 * V_6 = V_4 -> V_7 ;
struct V_10 * V_10 = F_3 ( V_2 ) ;
struct V_11 * V_12 = V_10 -> V_13 ;
if ( ! V_12 || ! V_12 -> V_15 )
return;
if ( V_133 && V_12 -> V_15 -> V_102 )
return;
if ( ! V_133 && ! V_12 -> V_15 -> V_102 )
return;
if ( V_133 ) {
if ( F_27 ( V_6 ) )
V_12 -> V_15 -> V_134 = F_52 ( V_6 ) ;
else
V_12 -> V_15 -> V_134 = F_53 ( V_6 ) ;
} else {
V_12 -> V_15 -> V_134 = NULL ;
}
V_12 -> V_15 -> V_102 = V_133 ;
F_54 ( L_6 ,
V_133 ? L_7 : L_8 , V_12 -> V_15 -> V_14 , V_10 -> V_135 ) ;
}
