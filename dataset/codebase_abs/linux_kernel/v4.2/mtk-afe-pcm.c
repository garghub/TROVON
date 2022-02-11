static T_1 F_1
( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_6 * V_7 = F_2 ( V_4 -> V_8 ) ;
struct V_9 * V_10 = & V_7 -> V_10 [ V_4 -> V_11 -> V_12 ] ;
return F_3 ( V_2 -> V_13 , V_10 -> V_14 ) ;
}
static int F_4 ( struct V_3 * V_4 )
{
T_2 V_15 ;
struct V_16 * V_17 = V_4 -> V_17 -> V_16 ;
struct V_18 * V_19 = V_4 -> V_19 ;
V_15 = V_20 . V_21 ;
return F_5 ( V_19 , V_22 ,
V_17 -> V_23 , V_15 , V_15 ) ;
}
static void F_6 ( struct V_18 * V_19 )
{
F_7 ( V_19 ) ;
}
static int F_8 ( unsigned int V_24 )
{
int V_25 ;
for ( V_25 = 0 ; V_25 < F_9 ( V_26 ) ; V_25 ++ )
if ( V_26 [ V_25 ] . V_27 == V_24 )
return V_26 [ V_25 ] . V_28 ;
return - V_29 ;
}
static int F_10 ( struct V_6 * V_7 , unsigned int V_27 )
{
unsigned int V_30 ;
int V_31 = F_8 ( V_27 ) ;
if ( V_31 < 0 )
return - V_29 ;
F_11 ( V_7 -> V_32 , V_33 , 0x1 , 0x1 ) ;
V_30 = V_34 |
F_12 ( V_31 ) |
V_35 ;
F_11 ( V_7 -> V_32 , V_36 , ~ V_37 , V_30 ) ;
V_30 = V_38 |
F_13 ( V_31 ) |
V_39 ;
F_11 ( V_7 -> V_32 , V_40 , ~ V_41 , V_30 ) ;
return 0 ;
}
static void F_14 ( struct V_6 * V_7 , bool V_42 )
{
unsigned int V_30 ;
F_15 ( V_7 -> V_32 , V_36 , & V_30 ) ;
if ( ! ! ( V_30 & V_37 ) == V_42 )
return;
F_11 ( V_7 -> V_32 , V_43 , 0x4 , 0x4 ) ;
F_11 ( V_7 -> V_32 , V_36 , 0x1 , V_42 ) ;
F_11 ( V_7 -> V_32 , V_40 , 0x1 , V_42 ) ;
F_16 ( 1 ) ;
F_11 ( V_7 -> V_32 , V_43 , 0x4 , 0 ) ;
}
static int F_17 ( struct V_6 * V_7 ,
struct V_44 * V_45 , struct V_44 * V_46 )
{
int V_47 ;
if ( V_45 ) {
V_47 = F_18 ( V_45 ) ;
if ( V_47 ) {
F_19 ( V_7 -> V_23 , L_1 ) ;
return V_47 ;
}
F_11 ( V_7 -> V_32 , V_48 ,
V_49 | V_50 , 0 ) ;
}
if ( V_46 ) {
V_47 = F_18 ( V_46 ) ;
if ( V_47 ) {
F_19 ( V_7 -> V_23 , L_2 ) ;
return V_47 ;
}
}
return 0 ;
}
static int F_20 ( struct V_6 * V_7 ,
struct V_44 * V_45 , unsigned int V_51 ,
struct V_44 * V_46 , unsigned int V_52 )
{
int V_47 ;
if ( V_45 ) {
V_47 = F_21 ( V_45 , V_51 ) ;
if ( V_47 ) {
F_19 ( V_7 -> V_23 , L_3 ) ;
return V_47 ;
}
}
if ( V_46 ) {
V_47 = F_21 ( V_46 , V_52 ) ;
if ( V_47 ) {
F_19 ( V_7 -> V_23 , L_4 ) ;
return V_47 ;
}
}
return 0 ;
}
static void F_22 ( struct V_6 * V_7 ,
struct V_44 * V_45 , struct V_44 * V_46 )
{
if ( V_45 ) {
F_11 ( V_7 -> V_32 , V_48 ,
V_49 | V_50 ,
V_49 | V_50 ) ;
F_23 ( V_45 ) ;
}
if ( V_46 )
F_23 ( V_46 ) ;
}
static int F_24 ( struct V_1 * V_2 ,
struct V_53 * V_54 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_6 * V_7 = F_2 ( V_4 -> V_8 ) ;
if ( V_54 -> V_55 )
return 0 ;
F_17 ( V_7 , V_7 -> V_56 [ V_57 ] , NULL ) ;
return 0 ;
}
static void F_25 ( struct V_1 * V_2 ,
struct V_53 * V_54 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_6 * V_7 = F_2 ( V_4 -> V_8 ) ;
if ( V_54 -> V_55 )
return;
F_14 ( V_7 , false ) ;
F_22 ( V_7 , V_7 -> V_56 [ V_57 ] , NULL ) ;
F_11 ( V_7 -> V_32 , V_58 , 0x1 , 0 ) ;
}
static int F_26 ( struct V_1 * V_2 ,
struct V_53 * V_54 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_59 * const V_13 = V_2 -> V_13 ;
struct V_6 * V_7 = F_2 ( V_4 -> V_8 ) ;
int V_47 ;
F_20 ( V_7 ,
V_7 -> V_56 [ V_57 ] , V_13 -> V_27 * 256 ,
NULL , 0 ) ;
V_47 = F_10 ( V_7 , V_2 -> V_13 -> V_27 ) ;
if ( V_47 )
return V_47 ;
F_14 ( V_7 , true ) ;
return 0 ;
}
static int F_27 ( struct V_1 * V_2 ,
struct V_53 * V_54 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_6 * V_7 = F_2 ( V_4 -> V_8 ) ;
if ( V_54 -> V_55 )
return 0 ;
F_17 ( V_7 , V_7 -> V_56 [ V_60 ] ,
V_7 -> V_56 [ V_61 ] ) ;
return 0 ;
}
static void F_28 ( struct V_1 * V_2 ,
struct V_53 * V_54 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_6 * V_7 = F_2 ( V_4 -> V_8 ) ;
if ( V_54 -> V_55 )
return;
F_22 ( V_7 , V_7 -> V_56 [ V_60 ] ,
V_7 -> V_56 [ V_61 ] ) ;
F_11 ( V_7 -> V_32 , V_58 , 0x1 , 0 ) ;
}
static int F_29 ( struct V_1 * V_2 ,
struct V_53 * V_54 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_59 * const V_13 = V_2 -> V_13 ;
struct V_6 * V_7 = F_2 ( V_4 -> V_8 ) ;
unsigned int V_30 ;
F_20 ( V_7 ,
V_7 -> V_56 [ V_60 ] , V_13 -> V_27 * 128 ,
V_7 -> V_56 [ V_61 ] ,
V_13 -> V_27 * V_13 -> V_62 * 32 ) ;
V_30 = V_63 |
V_64 |
V_65 |
V_66 |
V_67 |
F_30 ( 32 ) ;
F_11 ( V_7 -> V_32 , V_68 , ~ V_69 , V_30 ) ;
switch ( V_13 -> V_62 ) {
case 1 :
case 2 :
V_30 = V_70 ;
V_30 |= ( V_71 << 4 ) ;
V_30 |= ( V_71 << 8 ) ;
V_30 |= ( V_71 << 12 ) ;
break;
case 3 :
case 4 :
V_30 = V_70 ;
V_30 |= ( V_72 << 4 ) ;
V_30 |= ( V_71 << 8 ) ;
V_30 |= ( V_71 << 12 ) ;
break;
case 5 :
case 6 :
V_30 = V_70 ;
V_30 |= ( V_72 << 4 ) ;
V_30 |= ( V_73 << 8 ) ;
V_30 |= ( V_71 << 12 ) ;
break;
case 7 :
case 8 :
V_30 = V_70 ;
V_30 |= ( V_72 << 4 ) ;
V_30 |= ( V_73 << 8 ) ;
V_30 |= ( V_74 << 12 ) ;
break;
default:
V_30 = 0 ;
}
F_11 ( V_7 -> V_32 , V_75 , 0x0000ffff , V_30 ) ;
F_11 ( V_7 -> V_32 , V_76 ,
0x000000f0 , V_13 -> V_62 << 4 ) ;
return 0 ;
}
static int F_31 ( struct V_1 * V_2 , int V_77 ,
struct V_53 * V_54 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_6 * V_7 = F_2 ( V_4 -> V_8 ) ;
F_32 ( V_7 -> V_23 , L_5 , V_78 , V_77 , V_54 -> V_79 ) ;
switch ( V_77 ) {
case V_80 :
case V_81 :
F_11 ( V_7 -> V_32 , V_48 ,
V_82 | V_83 , 0 ) ;
F_33 ( V_7 -> V_32 , V_84 ,
V_85 | V_86 |
V_87 | V_88 |
V_89 | V_90 |
V_91 | V_92 ) ;
F_11 ( V_7 -> V_32 , V_76 , 0x1 , 0x1 ) ;
F_11 ( V_7 -> V_32 , V_68 , 0x1 , 0x1 ) ;
return 0 ;
case V_93 :
case V_94 :
F_11 ( V_7 -> V_32 , V_68 , 0x1 , 0 ) ;
F_11 ( V_7 -> V_32 , V_76 , 0x1 , 0 ) ;
F_11 ( V_7 -> V_32 , V_48 ,
V_82 | V_83 ,
V_82 | V_83 ) ;
return 0 ;
default:
return - V_29 ;
}
}
static int F_34 ( struct V_1 * V_2 ,
struct V_53 * V_54 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_6 * V_7 = F_2 ( V_4 -> V_8 ) ;
struct V_59 * V_13 = V_2 -> V_13 ;
struct V_9 * V_10 = & V_7 -> V_10 [ V_4 -> V_11 -> V_12 ] ;
int V_47 ;
V_10 -> V_2 = V_2 ;
F_35 ( V_2 , & V_20 ) ;
V_47 = F_36 ( V_13 ,
V_95 ) ;
if ( V_47 < 0 )
F_19 ( V_7 -> V_23 , L_6 ) ;
return V_47 ;
}
static void F_37 ( struct V_1 * V_2 ,
struct V_53 * V_54 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_6 * V_7 = F_2 ( V_4 -> V_8 ) ;
struct V_9 * V_10 = & V_7 -> V_10 [ V_4 -> V_11 -> V_12 ] ;
V_10 -> V_2 = NULL ;
}
static int F_38 ( struct V_1 * V_2 ,
struct V_96 * V_97 ,
struct V_53 * V_54 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_6 * V_7 = F_2 ( V_4 -> V_8 ) ;
struct V_9 * V_10 = & V_7 -> V_10 [ V_4 -> V_11 -> V_12 ] ;
int V_47 ;
F_39 ( V_7 -> V_23 ,
L_7 ,
V_78 , F_40 ( V_97 ) , F_41 ( V_97 ) ,
F_42 ( V_97 ) ) ;
V_47 = F_43 ( V_2 , F_44 ( V_97 ) ) ;
if ( V_47 < 0 )
return V_47 ;
V_10 -> V_98 = V_2 -> V_13 -> V_99 ;
V_10 -> V_100 = V_2 -> V_13 -> V_101 ;
V_10 -> V_14 = 0 ;
F_33 ( V_7 -> V_32 ,
V_10 -> V_102 -> V_103 , V_10 -> V_98 ) ;
F_33 ( V_7 -> V_32 ,
V_10 -> V_102 -> V_103 + V_104 ,
V_10 -> V_98 + V_10 -> V_100 - 1 ) ;
if ( V_10 -> V_102 -> V_105 >= 0 ) {
unsigned int V_106 = ( F_42 ( V_97 ) == 1 ) ? 1 : 0 ;
F_11 ( V_7 -> V_32 , V_107 ,
1 << V_10 -> V_102 -> V_105 ,
V_106 << V_10 -> V_102 -> V_105 ) ;
}
if ( V_10 -> V_102 -> V_108 < 0 )
return 0 ;
if ( V_10 -> V_102 -> V_12 == V_109 ||
V_10 -> V_102 -> V_12 == V_110 ) {
unsigned int V_30 ;
switch ( F_41 ( V_97 ) ) {
case 8000 :
V_30 = 0 ;
break;
case 16000 :
V_30 = 1 ;
break;
case 32000 :
V_30 = 2 ;
break;
default:
return - V_29 ;
}
if ( V_10 -> V_102 -> V_12 == V_109 )
F_11 ( V_7 -> V_32 , V_58 ,
0x3 << V_10 -> V_102 -> V_108 ,
V_30 << V_10 -> V_102 -> V_108 ) ;
else
F_11 ( V_7 -> V_32 , V_107 ,
0x3 << V_10 -> V_102 -> V_108 ,
V_30 << V_10 -> V_102 -> V_108 ) ;
} else {
int V_31 = F_8 ( F_41 ( V_97 ) ) ;
if ( V_31 < 0 )
return - V_29 ;
F_11 ( V_7 -> V_32 , V_107 ,
0xf << V_10 -> V_102 -> V_108 ,
V_31 << V_10 -> V_102 -> V_108 ) ;
}
return 0 ;
}
static int F_45 ( struct V_1 * V_2 ,
struct V_53 * V_54 )
{
return F_46 ( V_2 ) ;
}
static int F_47 ( struct V_1 * V_2 ,
struct V_53 * V_54 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_6 * V_7 = F_2 ( V_4 -> V_8 ) ;
F_11 ( V_7 -> V_32 , V_58 , 0x1 , 0x1 ) ;
return 0 ;
}
static int F_48 ( struct V_1 * V_2 , int V_77 ,
struct V_53 * V_54 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_59 * const V_13 = V_2 -> V_13 ;
struct V_6 * V_7 = F_2 ( V_4 -> V_8 ) ;
struct V_9 * V_10 = & V_7 -> V_10 [ V_4 -> V_11 -> V_12 ] ;
unsigned int V_111 = V_13 -> V_112 ;
F_32 ( V_7 -> V_23 , L_8 , V_78 , V_10 -> V_102 -> V_79 , V_77 ) ;
switch ( V_77 ) {
case V_80 :
case V_81 :
if ( V_10 -> V_102 -> V_113 >= 0 )
F_11 ( V_7 -> V_32 , V_58 ,
1 << V_10 -> V_102 -> V_113 ,
1 << V_10 -> V_102 -> V_113 ) ;
F_11 ( V_7 -> V_32 ,
V_10 -> V_102 -> V_114 ,
0x3ffff << V_10 -> V_102 -> V_115 ,
V_111 << V_10 -> V_102 -> V_115 ) ;
if ( V_10 -> V_102 -> V_116 >= 0 ) {
int V_31 = F_8 ( V_13 -> V_27 ) ;
if ( V_31 < 0 )
return - V_29 ;
F_11 ( V_7 -> V_32 ,
V_117 ,
0xf << V_10 -> V_102 -> V_116 ,
V_31 << V_10 -> V_102 -> V_116 ) ;
}
F_11 ( V_7 -> V_32 , V_117 ,
1 << V_10 -> V_102 -> V_118 ,
1 << V_10 -> V_102 -> V_118 ) ;
return 0 ;
case V_93 :
case V_94 :
if ( V_10 -> V_102 -> V_113 >= 0 )
F_11 ( V_7 -> V_32 , V_58 ,
1 << V_10 -> V_102 -> V_113 , 0 ) ;
F_11 ( V_7 -> V_32 , V_117 ,
1 << V_10 -> V_102 -> V_118 ,
0 << V_10 -> V_102 -> V_118 ) ;
F_33 ( V_7 -> V_32 , V_119 ,
1 << V_10 -> V_102 -> V_120 ) ;
V_10 -> V_14 = 0 ;
return 0 ;
default:
return - V_29 ;
}
}
static T_3 F_49 ( int V_121 , void * V_122 )
{
struct V_6 * V_7 = V_122 ;
unsigned int V_123 , V_14 ;
int V_25 , V_47 ;
V_47 = F_15 ( V_7 -> V_32 , V_124 , & V_123 ) ;
if ( V_47 ) {
F_19 ( V_7 -> V_23 , L_9 , V_78 ) ;
V_123 = V_125 ;
goto V_126;
}
for ( V_25 = 0 ; V_25 < V_127 ; V_25 ++ ) {
struct V_9 * V_10 = & V_7 -> V_10 [ V_25 ] ;
if ( ! ( V_123 & ( 1 << V_10 -> V_102 -> V_120 ) ) )
continue;
V_47 = F_15 ( V_7 -> V_32 , V_10 -> V_102 -> V_128 ,
& V_14 ) ;
if ( V_47 || V_14 == 0 ) {
F_19 ( V_7 -> V_23 , L_10 , V_78 ) ;
V_14 = V_10 -> V_98 ;
}
V_10 -> V_14 = V_14 - V_10 -> V_98 ;
F_50 ( V_10 -> V_2 ) ;
}
V_126:
F_33 ( V_7 -> V_32 , V_119 , V_123 & V_125 ) ;
return V_129 ;
}
static int F_51 ( struct V_130 * V_23 )
{
struct V_6 * V_7 = F_52 ( V_23 ) ;
F_11 ( V_7 -> V_32 , V_48 ,
V_131 , V_131 ) ;
F_23 ( V_7 -> V_56 [ V_132 ] ) ;
F_23 ( V_7 -> V_56 [ V_133 ] ) ;
F_23 ( V_7 -> V_56 [ V_134 ] ) ;
F_23 ( V_7 -> V_56 [ V_135 ] ) ;
F_23 ( V_7 -> V_56 [ V_136 ] ) ;
return 0 ;
}
static int F_53 ( struct V_130 * V_23 )
{
struct V_6 * V_7 = F_52 ( V_23 ) ;
int V_47 ;
V_47 = F_18 ( V_7 -> V_56 [ V_136 ] ) ;
if ( V_47 )
return V_47 ;
V_47 = F_18 ( V_7 -> V_56 [ V_135 ] ) ;
if ( V_47 )
goto V_137;
V_47 = F_18 ( V_7 -> V_56 [ V_134 ] ) ;
if ( V_47 )
goto V_138;
V_47 = F_18 ( V_7 -> V_56 [ V_132 ] ) ;
if ( V_47 )
goto V_139;
V_47 = F_18 ( V_7 -> V_56 [ V_133 ] ) ;
if ( V_47 )
goto V_140;
F_11 ( V_7 -> V_32 , V_48 , V_131 , 0 ) ;
F_11 ( V_7 -> V_32 , V_141 ,
V_142 | V_143 , 0 ) ;
F_11 ( V_7 -> V_32 , V_144 , 0xff , 0xff ) ;
return 0 ;
V_140:
F_23 ( V_7 -> V_56 [ V_132 ] ) ;
V_139:
F_23 ( V_7 -> V_56 [ V_134 ] ) ;
V_138:
F_23 ( V_7 -> V_56 [ V_135 ] ) ;
V_137:
F_23 ( V_7 -> V_56 [ V_136 ] ) ;
return V_47 ;
}
static int F_54 ( struct V_6 * V_7 )
{
T_2 V_25 ;
for ( V_25 = 0 ; V_25 < F_9 ( V_145 ) ; V_25 ++ ) {
V_7 -> V_56 [ V_25 ] = F_55 ( V_7 -> V_23 , V_145 [ V_25 ] ) ;
if ( F_56 ( V_7 -> V_56 [ V_25 ] ) ) {
F_19 ( V_7 -> V_23 , L_11 ,
V_78 , V_145 [ V_25 ] ) ;
return F_57 ( V_7 -> V_56 [ V_25 ] ) ;
}
}
F_21 ( V_7 -> V_56 [ V_132 ] , 22579200 ) ;
F_21 ( V_7 -> V_56 [ V_133 ] , 24576000 ) ;
return 0 ;
}
static int F_58 ( struct V_146 * V_147 )
{
int V_47 , V_25 ;
unsigned int V_148 ;
struct V_6 * V_7 ;
struct V_149 * V_150 ;
V_7 = F_59 ( & V_147 -> V_23 , sizeof( * V_7 ) , V_151 ) ;
if ( ! V_7 )
return - V_152 ;
V_7 -> V_23 = & V_147 -> V_23 ;
V_148 = F_60 ( V_147 , 0 ) ;
if ( ! V_148 ) {
F_19 ( V_7 -> V_23 , L_12 , V_7 -> V_23 -> V_153 -> V_79 ) ;
return - V_154 ;
}
V_47 = F_61 ( V_7 -> V_23 , V_148 , F_49 ,
0 , L_13 , ( void * ) V_7 ) ;
if ( V_47 ) {
F_19 ( V_7 -> V_23 , L_14 ) ;
return V_47 ;
}
V_150 = F_62 ( V_147 , V_155 , 0 ) ;
V_7 -> V_156 = F_63 ( & V_147 -> V_23 , V_150 ) ;
if ( F_56 ( V_7 -> V_156 ) )
return F_57 ( V_7 -> V_156 ) ;
V_7 -> V_32 = F_64 ( & V_147 -> V_23 , V_7 -> V_156 ,
& V_157 ) ;
if ( F_56 ( V_7 -> V_32 ) )
return F_57 ( V_7 -> V_32 ) ;
V_47 = F_54 ( V_7 ) ;
if ( V_47 ) {
F_19 ( V_7 -> V_23 , L_15 ) ;
return V_47 ;
}
for ( V_25 = 0 ; V_25 < V_127 ; V_25 ++ )
V_7 -> V_10 [ V_25 ] . V_102 = & V_158 [ V_25 ] ;
F_65 ( V_147 , V_7 ) ;
F_66 ( & V_147 -> V_23 ) ;
if ( ! F_67 ( & V_147 -> V_23 ) ) {
V_47 = F_53 ( & V_147 -> V_23 ) ;
if ( V_47 )
goto V_159;
}
V_47 = F_68 ( & V_147 -> V_23 , & V_160 ) ;
if ( V_47 )
goto V_159;
V_47 = F_69 ( & V_147 -> V_23 ,
& V_161 ,
V_162 ,
F_9 ( V_162 ) ) ;
if ( V_47 )
goto V_163;
V_47 = F_69 ( & V_147 -> V_23 ,
& V_164 ,
V_165 ,
F_9 ( V_165 ) ) ;
if ( V_47 )
goto V_166;
F_32 ( & V_147 -> V_23 , L_16 ) ;
return 0 ;
V_166:
F_70 ( & V_147 -> V_23 ) ;
V_163:
F_71 ( & V_147 -> V_23 ) ;
V_159:
F_72 ( & V_147 -> V_23 ) ;
return V_47 ;
}
static int F_73 ( struct V_146 * V_147 )
{
F_72 ( & V_147 -> V_23 ) ;
if ( ! F_74 ( & V_147 -> V_23 ) )
F_51 ( & V_147 -> V_23 ) ;
F_70 ( & V_147 -> V_23 ) ;
F_71 ( & V_147 -> V_23 ) ;
return 0 ;
}
