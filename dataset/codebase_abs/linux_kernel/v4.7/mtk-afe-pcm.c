static T_1 F_1
( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_6 * V_7 = F_2 ( V_4 -> V_8 ) ;
struct V_9 * V_10 = & V_7 -> V_10 [ V_4 -> V_11 -> V_12 ] ;
unsigned int V_13 ;
int V_14 ;
V_14 = F_3 ( V_7 -> V_15 , V_10 -> V_16 -> V_17 , & V_13 ) ;
if ( V_14 || V_13 == 0 ) {
F_4 ( V_7 -> V_18 , L_1 , V_19 ) ;
V_13 = V_10 -> V_20 ;
}
return F_5 ( V_2 -> V_21 ,
V_13 - V_10 -> V_20 ) ;
}
static int F_6 ( struct V_3 * V_4 )
{
T_2 V_22 ;
struct V_23 * V_24 = V_4 -> V_24 -> V_23 ;
struct V_25 * V_26 = V_4 -> V_26 ;
V_22 = V_27 . V_28 ;
return F_7 ( V_26 , V_29 ,
V_24 -> V_18 , V_22 , V_22 ) ;
}
static void F_8 ( struct V_25 * V_26 )
{
F_9 ( V_26 ) ;
}
static int F_10 ( unsigned int V_30 )
{
int V_31 ;
for ( V_31 = 0 ; V_31 < F_11 ( V_32 ) ; V_31 ++ )
if ( V_32 [ V_31 ] . V_33 == V_30 )
return V_32 [ V_31 ] . V_34 ;
return - V_35 ;
}
static int F_12 ( struct V_6 * V_7 , unsigned int V_33 )
{
unsigned int V_36 ;
int V_37 = F_10 ( V_33 ) ;
if ( V_37 < 0 )
return - V_35 ;
F_13 ( V_7 -> V_15 , V_38 , 0x1 , 0x1 ) ;
F_13 ( V_7 -> V_15 , V_39 , 0x1 , 0x1 ) ;
V_36 = V_40 |
F_14 ( V_37 ) |
V_41 ;
F_13 ( V_7 -> V_15 , V_42 , ~ V_43 , V_36 ) ;
V_36 = V_44 |
F_15 ( V_37 ) |
V_45 ;
F_13 ( V_7 -> V_15 , V_46 , ~ V_47 , V_36 ) ;
return 0 ;
}
static void F_16 ( struct V_6 * V_7 , bool V_48 )
{
unsigned int V_36 ;
F_3 ( V_7 -> V_15 , V_42 , & V_36 ) ;
if ( ! ! ( V_36 & V_43 ) == V_48 )
return;
F_13 ( V_7 -> V_15 , V_42 , 0x1 , V_48 ) ;
F_13 ( V_7 -> V_15 , V_46 , 0x1 , V_48 ) ;
}
static int F_17 ( struct V_6 * V_7 ,
struct V_49 * V_50 , struct V_49 * V_51 )
{
int V_14 ;
if ( V_50 ) {
V_14 = F_18 ( V_50 ) ;
if ( V_14 ) {
F_4 ( V_7 -> V_18 , L_2 ) ;
return V_14 ;
}
}
if ( V_51 ) {
V_14 = F_18 ( V_51 ) ;
if ( V_14 ) {
F_4 ( V_7 -> V_18 , L_3 ) ;
return V_14 ;
}
}
return 0 ;
}
static int F_19 ( struct V_6 * V_7 ,
struct V_49 * V_50 , unsigned int V_52 ,
struct V_49 * V_51 , unsigned int V_53 )
{
int V_14 ;
if ( V_50 ) {
V_14 = F_20 ( V_50 , V_52 ) ;
if ( V_14 ) {
F_4 ( V_7 -> V_18 , L_4 ) ;
return V_14 ;
}
}
if ( V_51 ) {
V_14 = F_20 ( V_51 , V_53 ) ;
if ( V_14 ) {
F_4 ( V_7 -> V_18 , L_5 ) ;
return V_14 ;
}
}
return 0 ;
}
static void F_21 ( struct V_6 * V_7 ,
struct V_49 * V_50 , struct V_49 * V_51 )
{
if ( V_50 )
F_22 ( V_50 ) ;
if ( V_51 )
F_22 ( V_51 ) ;
}
static int F_23 ( struct V_1 * V_2 ,
struct V_54 * V_55 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_6 * V_7 = F_2 ( V_4 -> V_8 ) ;
if ( V_55 -> V_56 )
return 0 ;
F_17 ( V_7 , V_7 -> V_57 [ V_58 ] , NULL ) ;
F_17 ( V_7 , V_7 -> V_57 [ V_59 ] , NULL ) ;
F_13 ( V_7 -> V_15 , V_60 ,
V_61 | V_62 , 0 ) ;
return 0 ;
}
static void F_24 ( struct V_1 * V_2 ,
struct V_54 * V_55 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_6 * V_7 = F_2 ( V_4 -> V_8 ) ;
if ( V_55 -> V_56 )
return;
F_16 ( V_7 , false ) ;
F_13 ( V_7 -> V_15 , V_60 ,
V_61 | V_62 ,
V_61 | V_62 ) ;
F_21 ( V_7 , V_7 -> V_57 [ V_58 ] , NULL ) ;
F_21 ( V_7 , V_7 -> V_57 [ V_59 ] , NULL ) ;
}
static int F_25 ( struct V_1 * V_2 ,
struct V_54 * V_55 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_63 * const V_21 = V_2 -> V_21 ;
struct V_6 * V_7 = F_2 ( V_4 -> V_8 ) ;
int V_14 ;
F_19 ( V_7 ,
V_7 -> V_57 [ V_58 ] , V_21 -> V_33 * 256 ,
NULL , 0 ) ;
F_19 ( V_7 ,
V_7 -> V_57 [ V_59 ] , V_21 -> V_33 * 256 ,
NULL , 0 ) ;
V_14 = F_12 ( V_7 , V_2 -> V_21 -> V_33 ) ;
if ( V_14 )
return V_14 ;
F_16 ( V_7 , true ) ;
return 0 ;
}
static int F_26 ( struct V_1 * V_2 ,
struct V_54 * V_55 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_6 * V_7 = F_2 ( V_4 -> V_8 ) ;
if ( V_55 -> V_56 )
return 0 ;
F_17 ( V_7 , V_7 -> V_57 [ V_64 ] ,
V_7 -> V_57 [ V_65 ] ) ;
return 0 ;
}
static void F_27 ( struct V_1 * V_2 ,
struct V_54 * V_55 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_6 * V_7 = F_2 ( V_4 -> V_8 ) ;
if ( V_55 -> V_56 )
return;
F_21 ( V_7 , V_7 -> V_57 [ V_64 ] ,
V_7 -> V_57 [ V_65 ] ) ;
}
static int F_28 ( struct V_1 * V_2 ,
struct V_54 * V_55 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_63 * const V_21 = V_2 -> V_21 ;
struct V_6 * V_7 = F_2 ( V_4 -> V_8 ) ;
unsigned int V_36 ;
F_19 ( V_7 ,
V_7 -> V_57 [ V_64 ] , V_21 -> V_33 * 128 ,
V_7 -> V_57 [ V_65 ] ,
V_21 -> V_33 * V_21 -> V_66 * 32 ) ;
V_36 = V_67 |
V_68 |
V_69 |
V_70 |
V_71 |
V_72 |
F_29 ( 32 ) ;
F_13 ( V_7 -> V_15 , V_73 , ~ V_74 , V_36 ) ;
switch ( V_21 -> V_66 ) {
case 1 :
case 2 :
V_36 = V_75 ;
V_36 |= ( V_76 << 4 ) ;
V_36 |= ( V_76 << 8 ) ;
V_36 |= ( V_76 << 12 ) ;
break;
case 3 :
case 4 :
V_36 = V_75 ;
V_36 |= ( V_77 << 4 ) ;
V_36 |= ( V_76 << 8 ) ;
V_36 |= ( V_76 << 12 ) ;
break;
case 5 :
case 6 :
V_36 = V_75 ;
V_36 |= ( V_77 << 4 ) ;
V_36 |= ( V_78 << 8 ) ;
V_36 |= ( V_76 << 12 ) ;
break;
case 7 :
case 8 :
V_36 = V_75 ;
V_36 |= ( V_77 << 4 ) ;
V_36 |= ( V_78 << 8 ) ;
V_36 |= ( V_79 << 12 ) ;
break;
default:
V_36 = 0 ;
}
F_13 ( V_7 -> V_15 , V_80 , 0x0000ffff , V_36 ) ;
F_13 ( V_7 -> V_15 , V_81 ,
0x000000f0 , V_21 -> V_66 << 4 ) ;
return 0 ;
}
static int F_30 ( struct V_1 * V_2 , int V_82 ,
struct V_54 * V_55 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_6 * V_7 = F_2 ( V_4 -> V_8 ) ;
F_31 ( V_7 -> V_18 , L_6 , V_19 , V_82 , V_55 -> V_83 ) ;
switch ( V_82 ) {
case V_84 :
case V_85 :
F_13 ( V_7 -> V_15 , V_60 ,
V_86 | V_87 , 0 ) ;
F_32 ( V_7 -> V_15 , V_88 ,
V_89 | V_90 |
V_91 | V_92 |
V_93 | V_94 |
V_95 | V_96 ) ;
F_13 ( V_7 -> V_15 , V_81 , 0x1 , 0x1 ) ;
F_13 ( V_7 -> V_15 , V_73 , 0x1 , 0x1 ) ;
return 0 ;
case V_97 :
case V_98 :
F_13 ( V_7 -> V_15 , V_73 , 0x1 , 0 ) ;
F_13 ( V_7 -> V_15 , V_81 , 0x1 , 0 ) ;
F_13 ( V_7 -> V_15 , V_60 ,
V_86 | V_87 ,
V_86 | V_87 ) ;
return 0 ;
default:
return - V_35 ;
}
}
static int F_33 ( struct V_1 * V_2 ,
struct V_54 * V_55 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_6 * V_7 = F_2 ( V_4 -> V_8 ) ;
struct V_63 * V_21 = V_2 -> V_21 ;
struct V_9 * V_10 = & V_7 -> V_10 [ V_4 -> V_11 -> V_12 ] ;
int V_14 ;
V_10 -> V_2 = V_2 ;
F_34 ( V_2 , & V_27 ) ;
if ( V_2 -> V_99 == V_100 ) {
V_14 = F_35 ( V_21 ,
V_101 ,
3 ,
V_27 . V_102 ) ;
if ( V_14 < 0 ) {
F_4 ( V_7 -> V_18 , L_7 ) ;
return V_14 ;
}
}
V_14 = F_36 ( V_21 ,
V_101 ) ;
if ( V_14 < 0 )
F_4 ( V_7 -> V_18 , L_8 ) ;
return V_14 ;
}
static void F_37 ( struct V_1 * V_2 ,
struct V_54 * V_55 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_6 * V_7 = F_2 ( V_4 -> V_8 ) ;
struct V_9 * V_10 = & V_7 -> V_10 [ V_4 -> V_11 -> V_12 ] ;
V_10 -> V_2 = NULL ;
}
static int F_38 ( struct V_1 * V_2 ,
struct V_103 * V_104 ,
struct V_54 * V_55 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_6 * V_7 = F_2 ( V_4 -> V_8 ) ;
struct V_9 * V_10 = & V_7 -> V_10 [ V_4 -> V_11 -> V_12 ] ;
int V_105 = 0 ;
int V_14 ;
F_39 ( V_7 -> V_18 ,
L_9 ,
V_19 , F_40 ( V_104 ) , F_41 ( V_104 ) ,
F_42 ( V_104 ) ) ;
V_14 = F_43 ( V_2 , F_44 ( V_104 ) ) ;
if ( V_14 < 0 )
return V_14 ;
V_105 = F_45 ( V_2 -> V_21 -> V_106 ) ? 1 : 0 ;
V_10 -> V_20 = F_46 ( V_2 -> V_21 -> V_106 ) ;
V_10 -> V_107 = V_2 -> V_21 -> V_108 ;
F_32 ( V_7 -> V_15 ,
V_10 -> V_16 -> V_109 , V_10 -> V_20 ) ;
F_32 ( V_7 -> V_15 ,
V_10 -> V_16 -> V_109 + V_110 ,
V_10 -> V_20 + V_10 -> V_107 - 1 ) ;
F_13 ( V_7 -> V_15 , V_111 ,
1 << V_10 -> V_16 -> V_112 ,
V_105 << V_10 -> V_16 -> V_112 ) ;
if ( V_10 -> V_16 -> V_113 >= 0 ) {
unsigned int V_114 = ( F_42 ( V_104 ) == 1 ) ? 1 : 0 ;
F_13 ( V_7 -> V_15 , V_115 ,
1 << V_10 -> V_16 -> V_113 ,
V_114 << V_10 -> V_16 -> V_113 ) ;
}
if ( V_10 -> V_16 -> V_116 < 0 )
return 0 ;
if ( V_10 -> V_16 -> V_12 == V_117 ||
V_10 -> V_16 -> V_12 == V_118 ) {
unsigned int V_36 ;
switch ( F_41 ( V_104 ) ) {
case 8000 :
V_36 = 0 ;
break;
case 16000 :
V_36 = 1 ;
break;
case 32000 :
V_36 = 2 ;
break;
default:
return - V_35 ;
}
if ( V_10 -> V_16 -> V_12 == V_117 )
F_13 ( V_7 -> V_15 , V_119 ,
0x3 << V_10 -> V_16 -> V_116 ,
V_36 << V_10 -> V_16 -> V_116 ) ;
else
F_13 ( V_7 -> V_15 , V_115 ,
0x3 << V_10 -> V_16 -> V_116 ,
V_36 << V_10 -> V_16 -> V_116 ) ;
} else {
int V_37 = F_10 ( F_41 ( V_104 ) ) ;
if ( V_37 < 0 )
return - V_35 ;
F_13 ( V_7 -> V_15 , V_115 ,
0xf << V_10 -> V_16 -> V_116 ,
V_37 << V_10 -> V_16 -> V_116 ) ;
}
return 0 ;
}
static int F_47 ( struct V_1 * V_2 ,
struct V_54 * V_55 )
{
return F_48 ( V_2 ) ;
}
static int F_49 ( struct V_1 * V_2 , int V_82 ,
struct V_54 * V_55 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_63 * const V_21 = V_2 -> V_21 ;
struct V_6 * V_7 = F_2 ( V_4 -> V_8 ) ;
struct V_9 * V_10 = & V_7 -> V_10 [ V_4 -> V_11 -> V_12 ] ;
unsigned int V_120 = V_21 -> V_121 ;
F_31 ( V_7 -> V_18 , L_10 , V_19 , V_10 -> V_16 -> V_83 , V_82 ) ;
switch ( V_82 ) {
case V_84 :
case V_85 :
if ( V_10 -> V_16 -> V_122 >= 0 )
F_13 ( V_7 -> V_15 , V_119 ,
1 << V_10 -> V_16 -> V_122 ,
1 << V_10 -> V_16 -> V_122 ) ;
F_13 ( V_7 -> V_15 ,
V_10 -> V_16 -> V_123 ,
0x3ffff << V_10 -> V_16 -> V_124 ,
V_120 << V_10 -> V_16 -> V_124 ) ;
if ( V_10 -> V_16 -> V_125 >= 0 ) {
int V_37 = F_10 ( V_21 -> V_33 ) ;
if ( V_37 < 0 )
return - V_35 ;
F_13 ( V_7 -> V_15 ,
V_126 ,
0xf << V_10 -> V_16 -> V_125 ,
V_37 << V_10 -> V_16 -> V_125 ) ;
}
F_13 ( V_7 -> V_15 , V_126 ,
1 << V_10 -> V_16 -> V_127 ,
1 << V_10 -> V_16 -> V_127 ) ;
return 0 ;
case V_97 :
case V_98 :
if ( V_10 -> V_16 -> V_122 >= 0 )
F_13 ( V_7 -> V_15 , V_119 ,
1 << V_10 -> V_16 -> V_122 , 0 ) ;
F_13 ( V_7 -> V_15 , V_126 ,
1 << V_10 -> V_16 -> V_127 ,
0 << V_10 -> V_16 -> V_127 ) ;
F_32 ( V_7 -> V_15 , V_128 ,
1 << V_10 -> V_16 -> V_129 ) ;
return 0 ;
default:
return - V_35 ;
}
}
static int F_50 ( struct V_54 * V_55 )
{
struct V_6 * V_7 = F_51 ( V_55 ) ;
int V_31 ;
F_39 ( V_7 -> V_18 , L_11 , V_19 ) ;
if ( F_52 ( V_7 -> V_18 ) || V_7 -> V_130 )
return 0 ;
for ( V_31 = 0 ; V_31 < F_11 ( V_131 ) ; V_31 ++ )
F_3 ( V_7 -> V_15 , V_131 [ V_31 ] ,
& V_7 -> V_132 [ V_31 ] ) ;
V_7 -> V_130 = true ;
F_53 ( V_7 -> V_18 ) ;
return 0 ;
}
static int F_54 ( struct V_54 * V_55 )
{
struct V_6 * V_7 = F_51 ( V_55 ) ;
int V_31 = 0 ;
F_39 ( V_7 -> V_18 , L_11 , V_19 ) ;
if ( F_52 ( V_7 -> V_18 ) || ! V_7 -> V_130 )
return 0 ;
F_55 ( V_7 -> V_18 ) ;
for ( V_31 = 0 ; V_31 < F_11 ( V_131 ) ; V_31 ++ )
F_32 ( V_7 -> V_15 , V_131 [ V_31 ] ,
V_7 -> V_132 [ V_31 ] ) ;
V_7 -> V_130 = false ;
return 0 ;
}
static T_3 F_56 ( int V_133 , void * V_134 )
{
struct V_6 * V_7 = V_134 ;
unsigned int V_135 ;
int V_31 , V_14 ;
V_14 = F_3 ( V_7 -> V_15 , V_136 , & V_135 ) ;
if ( V_14 ) {
F_4 ( V_7 -> V_18 , L_12 , V_19 ) ;
V_135 = V_137 ;
goto V_138;
}
for ( V_31 = 0 ; V_31 < V_139 ; V_31 ++ ) {
struct V_9 * V_10 = & V_7 -> V_10 [ V_31 ] ;
if ( ! ( V_135 & ( 1 << V_10 -> V_16 -> V_129 ) ) )
continue;
F_57 ( V_10 -> V_2 ) ;
}
V_138:
F_32 ( V_7 -> V_15 , V_128 , V_135 & V_137 ) ;
return V_140 ;
}
static int F_53 ( struct V_141 * V_18 )
{
struct V_6 * V_7 = F_58 ( V_18 ) ;
F_13 ( V_7 -> V_15 , V_119 , 0x1 , 0 ) ;
F_13 ( V_7 -> V_15 , V_60 ,
V_142 , V_142 ) ;
F_22 ( V_7 -> V_57 [ V_143 ] ) ;
F_22 ( V_7 -> V_57 [ V_144 ] ) ;
F_22 ( V_7 -> V_57 [ V_145 ] ) ;
F_22 ( V_7 -> V_57 [ V_146 ] ) ;
F_22 ( V_7 -> V_57 [ V_147 ] ) ;
return 0 ;
}
static int F_55 ( struct V_141 * V_18 )
{
struct V_6 * V_7 = F_58 ( V_18 ) ;
int V_14 ;
V_14 = F_18 ( V_7 -> V_57 [ V_147 ] ) ;
if ( V_14 )
return V_14 ;
V_14 = F_18 ( V_7 -> V_57 [ V_146 ] ) ;
if ( V_14 )
goto V_148;
V_14 = F_18 ( V_7 -> V_57 [ V_145 ] ) ;
if ( V_14 )
goto V_149;
V_14 = F_18 ( V_7 -> V_57 [ V_143 ] ) ;
if ( V_14 )
goto V_150;
V_14 = F_18 ( V_7 -> V_57 [ V_144 ] ) ;
if ( V_14 )
goto V_151;
F_13 ( V_7 -> V_15 , V_60 , V_142 , 0 ) ;
F_13 ( V_7 -> V_15 , V_152 ,
V_153 | V_154 , 0 ) ;
F_13 ( V_7 -> V_15 , V_155 , 0xff , 0xff ) ;
F_13 ( V_7 -> V_15 , V_119 , 0x1 , 0x1 ) ;
return 0 ;
V_151:
F_22 ( V_7 -> V_57 [ V_143 ] ) ;
V_150:
F_22 ( V_7 -> V_57 [ V_145 ] ) ;
V_149:
F_22 ( V_7 -> V_57 [ V_146 ] ) ;
V_148:
F_22 ( V_7 -> V_57 [ V_147 ] ) ;
return V_14 ;
}
static int F_59 ( struct V_6 * V_7 )
{
T_2 V_31 ;
for ( V_31 = 0 ; V_31 < F_11 ( V_156 ) ; V_31 ++ ) {
V_7 -> V_57 [ V_31 ] = F_60 ( V_7 -> V_18 , V_156 [ V_31 ] ) ;
if ( F_61 ( V_7 -> V_57 [ V_31 ] ) ) {
F_4 ( V_7 -> V_18 , L_13 ,
V_19 , V_156 [ V_31 ] ) ;
return F_62 ( V_7 -> V_57 [ V_31 ] ) ;
}
}
F_20 ( V_7 -> V_57 [ V_143 ] , 22579200 ) ;
F_20 ( V_7 -> V_57 [ V_144 ] , 24576000 ) ;
return 0 ;
}
static int F_63 ( struct V_157 * V_158 )
{
int V_14 , V_31 ;
unsigned int V_159 ;
struct V_6 * V_7 ;
struct V_160 * V_161 ;
V_14 = F_64 ( & V_158 -> V_18 , F_65 ( 33 ) ) ;
if ( V_14 )
return V_14 ;
V_7 = F_66 ( & V_158 -> V_18 , sizeof( * V_7 ) , V_162 ) ;
if ( ! V_7 )
return - V_163 ;
V_7 -> V_18 = & V_158 -> V_18 ;
V_159 = F_67 ( V_158 , 0 ) ;
if ( ! V_159 ) {
F_4 ( V_7 -> V_18 , L_14 , V_7 -> V_18 -> V_164 -> V_83 ) ;
return - V_165 ;
}
V_14 = F_68 ( V_7 -> V_18 , V_159 , F_56 ,
0 , L_15 , ( void * ) V_7 ) ;
if ( V_14 ) {
F_4 ( V_7 -> V_18 , L_16 ) ;
return V_14 ;
}
V_161 = F_69 ( V_158 , V_166 , 0 ) ;
V_7 -> V_167 = F_70 ( & V_158 -> V_18 , V_161 ) ;
if ( F_61 ( V_7 -> V_167 ) )
return F_62 ( V_7 -> V_167 ) ;
V_7 -> V_15 = F_71 ( & V_158 -> V_18 , V_7 -> V_167 ,
& V_168 ) ;
if ( F_61 ( V_7 -> V_15 ) )
return F_62 ( V_7 -> V_15 ) ;
V_14 = F_59 ( V_7 ) ;
if ( V_14 ) {
F_4 ( V_7 -> V_18 , L_17 ) ;
return V_14 ;
}
for ( V_31 = 0 ; V_31 < V_139 ; V_31 ++ )
V_7 -> V_10 [ V_31 ] . V_16 = & V_169 [ V_31 ] ;
F_72 ( V_158 , V_7 ) ;
F_73 ( & V_158 -> V_18 ) ;
if ( ! F_74 ( & V_158 -> V_18 ) ) {
V_14 = F_55 ( & V_158 -> V_18 ) ;
if ( V_14 )
goto V_170;
}
V_14 = F_75 ( & V_158 -> V_18 , & V_171 ) ;
if ( V_14 )
goto V_170;
V_14 = F_76 ( & V_158 -> V_18 ,
& V_172 ,
V_173 ,
F_11 ( V_173 ) ) ;
if ( V_14 )
goto V_174;
V_14 = F_76 ( & V_158 -> V_18 ,
& V_175 ,
V_176 ,
F_11 ( V_176 ) ) ;
if ( V_14 )
goto V_177;
F_31 ( & V_158 -> V_18 , L_18 ) ;
return 0 ;
V_177:
F_77 ( & V_158 -> V_18 ) ;
V_174:
F_78 ( & V_158 -> V_18 ) ;
V_170:
F_79 ( & V_158 -> V_18 ) ;
return V_14 ;
}
static int F_80 ( struct V_157 * V_158 )
{
F_79 ( & V_158 -> V_18 ) ;
if ( ! F_52 ( & V_158 -> V_18 ) )
F_53 ( & V_158 -> V_18 ) ;
F_77 ( & V_158 -> V_18 ) ;
F_78 ( & V_158 -> V_18 ) ;
return 0 ;
}
