static void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
if ( V_4 -> V_5 )
return;
F_2 ( & V_4 -> V_6 , 1 ) ;
if ( ! F_3 ( V_4 -> V_7 ,
! F_4 ( & V_4 -> V_6 ) ,
V_8 / 20 ) )
F_5 ( L_1 ) ;
}
static void F_6 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
unsigned int V_9 , V_10 = 0 ;
F_5 ( L_2 , __FILE__ ) ;
for ( V_9 = 0 ; V_9 < V_11 ; V_9 ++ ) {
T_1 V_12 = F_7 ( V_4 -> V_13 + F_8 ( V_9 ) ) ;
if ( V_12 & V_14 ) {
V_12 &= ~ V_14 ;
F_9 ( V_12 , V_4 -> V_13 + F_8 ( V_9 ) ) ;
V_10 = 1 ;
}
}
if ( V_10 ) {
unsigned int V_15 = V_4 -> V_5 ;
V_4 -> V_5 = 0 ;
F_1 ( V_4 -> V_2 ) ;
V_4 -> V_5 = V_15 ;
}
}
static int F_10 ( struct V_3 * V_4 ,
struct V_16 * V_17 )
{
struct V_18 * V_19 = V_17 -> V_20 ;
int V_21 ;
V_4 -> V_17 = V_17 ;
V_4 -> V_22 = V_19 -> V_22 ++ ;
V_21 = F_11 ( V_4 -> V_2 , V_17 , V_4 -> V_23 ) ;
if ( V_21 )
V_19 -> V_22 -- ;
return V_21 ;
}
static void F_12 ( struct V_3 * V_4 )
{
if ( F_13 ( V_4 -> V_17 ) )
F_14 ( V_4 -> V_17 , V_4 -> V_23 ) ;
}
static T_1 F_15 ( struct V_3 * V_4 ,
const struct V_24 * V_25 )
{
unsigned long V_26 = V_25 -> V_27 * V_25 -> V_28 * V_25 -> V_29 ;
T_1 V_30 ;
V_30 = F_16 ( F_17 ( V_4 -> V_31 ) , V_26 ) ;
return ( V_30 < 0x100 ) ? V_30 : 0xff ;
}
static bool F_18 ( struct V_1 * V_2 ,
const struct V_24 * V_25 ,
struct V_24 * V_32 )
{
if ( V_32 -> V_29 == 0 )
V_32 -> V_29 = V_33 ;
return true ;
}
static void F_19 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_24 * V_25 = & V_2 -> V_34 . V_15 -> V_32 ;
T_1 V_12 , V_30 ;
if ( V_4 -> V_5 )
return;
if ( V_25 -> V_27 == 0 || V_25 -> V_28 == 0 )
return;
if ( ! V_4 -> V_35 ) {
int V_36 , V_37 , V_38 , V_39 , V_40 , V_41 ;
V_36 = V_25 -> V_42 - V_25 -> V_43 ;
V_37 = V_25 -> V_44 - V_25 -> V_42 ;
V_38 = V_25 -> V_43 - V_25 -> V_45 ;
V_12 = F_20 ( V_37 - 1 ) | F_21 ( V_38 - 1 ) ;
F_9 ( V_12 , V_4 -> V_13 + V_46 ) ;
V_12 = F_22 ( V_36 - 1 ) ;
F_9 ( V_12 , V_4 -> V_13 + V_47 ) ;
V_39 = V_25 -> V_48 - V_25 -> V_49 ;
V_40 = V_25 -> V_50 - V_25 -> V_48 ;
V_41 = V_25 -> V_49 - V_25 -> V_51 ;
V_12 = F_23 ( V_40 - 1 ) | F_24 ( V_41 - 1 ) ;
F_9 ( V_12 , V_4 -> V_13 + V_52 ) ;
V_12 = F_25 ( V_39 - 1 ) ;
F_9 ( V_12 , V_4 -> V_13 + V_53 ) ;
}
V_12 = F_26 ( V_25 -> V_54 - 1 ) |
F_27 ( V_25 -> V_55 - 1 ) ;
F_9 ( V_12 , V_4 -> V_13 + V_56 ) ;
F_9 ( V_25 -> V_54 - 1 , V_4 -> V_13 + V_57 ) ;
V_12 = V_58 | V_59 ;
F_9 ( V_12 , V_4 -> V_13 + V_60 ) ;
V_30 = F_15 ( V_4 , V_25 ) ;
if ( V_30 > 1 ) {
V_12 = F_28 ( V_30 - 1 ) ;
F_9 ( V_12 , V_4 -> V_13 + V_61 ) ;
F_9 ( V_12 , V_4 -> V_13 + V_62 ) ;
}
V_12 = F_7 ( V_4 -> V_13 + V_63 ) ;
V_12 |= V_64 ;
F_9 ( V_12 , V_4 -> V_13 + V_63 ) ;
}
static int F_29 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
T_1 V_12 ;
if ( V_4 -> V_5 )
return - V_65 ;
if ( ! F_30 ( 0 , & V_4 -> V_66 ) ) {
V_12 = F_7 ( V_4 -> V_13 + V_67 ) ;
V_12 |= V_68 ;
if ( ! V_4 -> V_35 ) {
V_12 |= V_69 ;
V_12 &= ~ V_70 ;
V_12 |= V_71 ;
}
F_9 ( V_12 , V_4 -> V_13 + V_67 ) ;
}
return 0 ;
}
static void F_31 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
T_1 V_12 ;
if ( V_4 -> V_5 )
return;
if ( F_32 ( 0 , & V_4 -> V_66 ) ) {
V_12 = F_7 ( V_4 -> V_13 + V_67 ) ;
V_12 &= ~ V_68 ;
if ( ! V_4 -> V_35 )
V_12 &= ~ V_69 ;
F_9 ( V_12 , V_4 -> V_13 + V_67 ) ;
}
}
static void F_33 ( struct V_3 * V_4 , unsigned int V_9 )
{
struct V_72 * V_73 = & V_4 -> V_74 [ V_9 ] ;
unsigned long V_12 ;
int V_75 ;
V_12 = F_7 ( V_4 -> V_13 + F_8 ( V_9 ) ) ;
V_12 &= ~ V_76 ;
switch ( V_73 -> V_77 ) {
case V_78 :
V_12 |= V_79 ;
V_12 |= V_80 ;
break;
case V_81 :
V_12 |= V_82 ;
V_12 |= V_80 ;
break;
case V_83 :
V_12 |= V_84 ;
V_12 |= V_80 ;
break;
case V_85 :
V_12 |= V_86 ;
V_12 |= V_80 ;
break;
case V_87 :
V_12 |= V_88 ;
V_12 |= V_80 ;
break;
case V_89 :
V_12 |= V_90 | V_91 |
V_92 ;
V_12 |= V_80 ;
break;
case V_93 :
V_12 |= V_94 | V_91 |
V_92 ;
V_12 |= V_80 ;
break;
case V_95 :
V_12 |= V_96 | V_91 |
V_92 ;
V_12 |= V_80 ;
break;
case V_97 :
V_12 |= V_98 | V_91 |
V_92 ;
V_12 |= V_80 ;
break;
default:
F_5 ( L_3 ) ;
V_12 |= V_82 ;
V_12 |= V_80 ;
break;
}
F_5 ( L_4 , V_73 -> V_99 ) ;
V_75 = ( V_73 -> V_100 / ( V_73 -> V_99 >> 3 ) ) - V_73 -> V_101 ;
if ( V_73 -> V_101 + V_75 < V_102 ) {
V_12 &= ~ V_103 ;
V_12 |= V_104 ;
}
F_9 ( V_12 , V_4 -> V_13 + F_8 ( V_9 ) ) ;
}
static void F_34 ( struct V_3 * V_4 , unsigned int V_9 )
{
unsigned int V_105 = 0 , V_106 = 0 ;
V_105 = ~ ( V_107 | V_108 |
V_109 ) | F_35 ( 0 ) ;
V_106 = F_36 ( 0xffffffff ) ;
F_9 ( V_105 , V_4 -> V_13 + F_37 ( V_9 ) ) ;
F_9 ( V_106 , V_4 -> V_13 + F_38 ( V_9 ) ) ;
}
static void F_39 ( struct V_3 * V_4 ,
unsigned int V_9 , bool V_110 )
{
T_1 V_111 , V_12 ;
V_111 = F_40 ( V_9 ) ;
V_12 = F_7 ( V_4 -> V_13 + V_112 ) ;
if ( V_110 )
V_12 |= V_111 ;
else
V_12 &= ~ V_111 ;
F_9 ( V_12 , V_4 -> V_13 + V_112 ) ;
}
static void F_41 ( struct V_1 * V_2 , unsigned int V_9 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_24 * V_25 = & V_2 -> V_34 . V_15 -> V_32 ;
struct V_72 * V_73 ;
int V_75 ;
unsigned long V_12 , V_113 ;
unsigned int V_114 ;
unsigned int V_115 ;
if ( V_4 -> V_5 )
return;
if ( V_9 < 0 || V_9 >= V_11 )
return;
V_73 = & V_4 -> V_74 [ V_9 ] ;
if ( V_4 -> V_5 )
return;
F_39 ( V_4 , V_9 , true ) ;
V_12 = ( unsigned long ) V_73 -> V_116 [ 0 ] ;
F_9 ( V_12 , V_4 -> V_13 + F_42 ( V_9 ) ) ;
V_75 = ( V_73 -> V_100 / ( V_73 -> V_99 >> 3 ) ) - V_73 -> V_101 ;
F_9 ( V_73 -> V_101 + V_75 , V_4 -> V_13 + F_43 ( V_9 ) ) ;
F_9 ( V_73 -> V_117 , V_4 -> V_13 + F_44 ( V_9 ) ) ;
F_9 ( V_73 -> V_118 , V_4 -> V_13 + F_45 ( V_9 ) ) ;
F_9 ( V_73 -> V_119 , V_4 -> V_13 + F_46 ( V_9 ) ) ;
F_5 ( L_5 ,
( unsigned long ) V_12 ) ;
F_5 ( L_6 ,
V_73 -> V_120 , V_73 -> V_121 ) ;
if ( ( V_73 -> V_122 + V_73 -> V_120 ) > V_25 -> V_55 )
V_73 -> V_122 = V_25 -> V_55 - V_73 -> V_120 ;
if ( ( V_73 -> V_123 + V_73 -> V_121 ) > V_25 -> V_54 )
V_73 -> V_123 = V_25 -> V_54 - V_73 -> V_121 ;
V_12 = F_47 ( V_73 -> V_122 ) |
F_48 ( V_73 -> V_123 ) ;
F_9 ( V_12 , V_4 -> V_13 + F_49 ( V_9 ) ) ;
V_114 = V_73 -> V_122 + V_73 -> V_120 ;
if ( V_114 )
V_114 -- ;
V_115 = V_73 -> V_123 + V_73 -> V_121 ;
if ( V_115 )
V_115 -- ;
V_12 = F_50 ( V_114 ) | F_51 ( V_115 ) ;
F_9 ( V_12 , V_4 -> V_13 + F_52 ( V_9 ) ) ;
F_5 ( L_7 ,
V_73 -> V_122 , V_73 -> V_123 , V_114 , V_115 ) ;
V_113 = F_53 ( 0x0 ) |
F_54 ( 0x0 ) |
F_55 ( 0x0 ) ;
F_9 ( V_113 , V_4 -> V_13 + F_56 ( V_9 ) ) ;
V_113 = F_57 ( 0xff ) |
F_58 ( 0xff ) |
F_59 ( 0xff ) ;
F_9 ( V_113 , V_4 -> V_13 + F_60 ( V_9 ) ) ;
F_33 ( V_4 , V_9 ) ;
if ( V_9 != 0 )
F_34 ( V_4 , V_9 ) ;
V_12 = F_7 ( V_4 -> V_13 + F_8 ( V_9 ) ) ;
V_12 |= V_124 ;
V_12 |= V_14 ;
F_9 ( V_12 , V_4 -> V_13 + F_8 ( V_9 ) ) ;
F_39 ( V_4 , V_9 , false ) ;
V_12 = F_7 ( V_4 -> V_13 + V_63 ) ;
V_12 |= V_64 ;
F_9 ( V_12 , V_4 -> V_13 + V_63 ) ;
}
static void F_61 ( struct V_1 * V_2 , unsigned int V_9 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_72 * V_73 ;
T_1 V_12 ;
if ( V_9 < 0 || V_9 >= V_11 )
return;
V_73 = & V_4 -> V_74 [ V_9 ] ;
if ( V_4 -> V_5 )
return;
F_39 ( V_4 , V_9 , true ) ;
V_12 = F_7 ( V_4 -> V_13 + F_8 ( V_9 ) ) ;
V_12 &= ~ V_14 ;
F_9 ( V_12 , V_4 -> V_13 + F_8 ( V_9 ) ) ;
F_39 ( V_4 , V_9 , false ) ;
V_12 = F_7 ( V_4 -> V_13 + V_63 ) ;
V_12 |= V_64 ;
F_9 ( V_12 , V_4 -> V_13 + V_63 ) ;
}
static void F_62 ( struct V_3 * V_4 )
{
T_1 V_12 ;
F_9 ( V_125 , V_4 -> V_13 + V_60 ) ;
V_12 = V_126 ;
if ( ! V_4 -> V_35 )
V_12 |= V_127 ;
F_9 ( V_12 , V_4 -> V_13 + V_128 ) ;
F_9 ( V_129 | V_130 , V_4 -> V_13 + V_131 ) ;
if ( ! V_4 -> V_35 )
F_9 ( V_132 , V_4 -> V_13 + F_63 ( 0 ) ) ;
}
static void F_64 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
int V_21 ;
if ( ! V_4 -> V_5 )
return;
V_4 -> V_5 = false ;
F_65 ( V_4 -> V_23 ) ;
V_21 = F_66 ( V_4 -> V_133 ) ;
if ( V_21 < 0 ) {
F_67 ( L_8 , V_21 ) ;
return;
}
V_21 = F_66 ( V_4 -> V_134 ) ;
if ( V_21 < 0 ) {
F_67 ( L_9 , V_21 ) ;
return;
}
V_21 = F_66 ( V_4 -> V_135 ) ;
if ( V_21 < 0 ) {
F_67 ( L_10 , V_21 ) ;
return;
}
V_21 = F_66 ( V_4 -> V_31 ) ;
if ( V_21 < 0 ) {
F_67 ( L_11 , V_21 ) ;
return;
}
F_62 ( V_4 ) ;
if ( F_32 ( 0 , & V_4 -> V_66 ) )
F_29 ( V_4 -> V_2 ) ;
F_19 ( V_4 -> V_2 ) ;
}
static void F_68 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
int V_136 ;
if ( V_4 -> V_5 )
return;
for ( V_136 = 0 ; V_136 < V_11 ; V_136 ++ )
F_61 ( V_2 , V_136 ) ;
F_69 ( V_4 -> V_31 ) ;
F_69 ( V_4 -> V_135 ) ;
F_69 ( V_4 -> V_134 ) ;
F_69 ( V_4 -> V_133 ) ;
F_70 ( V_4 -> V_23 ) ;
V_4 -> V_5 = true ;
}
static T_2 F_71 ( int V_137 , void * V_138 )
{
struct V_3 * V_4 = (struct V_3 * ) V_138 ;
T_1 V_12 , V_139 ;
V_12 = F_7 ( V_4 -> V_13 + V_140 ) ;
V_139 = V_4 -> V_35 ? V_141 : V_142 ;
if ( V_12 & V_139 )
F_9 ( V_139 , V_4 -> V_13 + V_140 ) ;
if ( V_4 -> V_22 < 0 || ! V_4 -> V_17 )
goto V_143;
if ( ! V_4 -> V_35 ) {
F_72 ( V_4 -> V_17 , V_4 -> V_22 ) ;
F_73 ( V_4 -> V_17 , V_4 -> V_22 ) ;
if ( F_4 ( & V_4 -> V_6 ) ) {
F_2 ( & V_4 -> V_6 , 0 ) ;
F_74 ( & V_4 -> V_7 ) ;
}
}
V_143:
return V_144 ;
}
static int F_75 ( struct V_145 * V_23 , struct V_145 * V_146 , void * V_147 )
{
struct V_3 * V_4 = F_76 ( V_23 ) ;
struct V_16 * V_17 = V_147 ;
struct V_72 * V_148 ;
enum V_149 type ;
unsigned int V_150 ;
int V_21 ;
V_21 = F_10 ( V_4 , V_17 ) ;
if ( V_21 ) {
F_67 ( L_12 ) ;
return V_21 ;
}
for ( V_150 = 0 ; V_150 < V_11 ; V_150 ++ ) {
type = ( V_150 == V_4 -> V_151 ) ? V_152 :
V_153 ;
V_21 = F_77 ( V_17 , & V_4 -> V_74 [ V_150 ] ,
1 << V_4 -> V_22 , type , V_150 ) ;
if ( V_21 )
return V_21 ;
}
V_148 = & V_4 -> V_74 [ V_4 -> V_151 ] ;
V_4 -> V_2 = F_78 ( V_17 , & V_148 -> V_34 ,
V_4 -> V_22 , V_154 ,
& V_155 , V_4 ) ;
if ( F_79 ( V_4 -> V_2 ) ) {
F_12 ( V_4 ) ;
return F_80 ( V_4 -> V_2 ) ;
}
if ( V_4 -> V_156 )
F_81 ( V_17 , V_4 -> V_156 ) ;
return 0 ;
}
static void F_82 ( struct V_145 * V_23 , struct V_145 * V_146 ,
void * V_147 )
{
struct V_3 * V_4 = F_76 ( V_23 ) ;
F_68 ( V_4 -> V_2 ) ;
if ( V_4 -> V_156 )
F_83 ( V_4 -> V_156 ) ;
F_12 ( V_4 ) ;
}
static int F_84 ( struct V_157 * V_158 )
{
struct V_145 * V_23 = & V_158 -> V_23 ;
struct V_3 * V_4 ;
struct V_159 * V_160 ;
struct V_161 * V_162 ;
int V_21 ;
if ( ! V_23 -> V_163 )
return - V_164 ;
V_4 = F_85 ( V_23 , sizeof( * V_4 ) , V_165 ) ;
if ( ! V_4 )
return - V_166 ;
V_4 -> V_23 = V_23 ;
V_4 -> V_5 = true ;
V_160 = F_86 ( V_23 -> V_163 , L_13 ) ;
if ( V_160 )
V_4 -> V_35 = true ;
F_87 ( V_160 ) ;
V_4 -> V_13 = F_88 ( V_23 -> V_163 , 0 ) ;
if ( ! V_4 -> V_13 )
return - V_166 ;
V_4 -> V_133 = F_89 ( V_23 , L_14 ) ;
if ( F_79 ( V_4 -> V_133 ) ) {
F_90 ( V_23 , L_15 ) ;
V_21 = F_80 ( V_4 -> V_133 ) ;
goto V_167;
}
V_4 -> V_134 = F_89 ( V_23 , L_16 ) ;
if ( F_79 ( V_4 -> V_134 ) ) {
F_90 ( V_23 , L_17 ) ;
V_21 = F_80 ( V_4 -> V_134 ) ;
goto V_167;
}
V_4 -> V_135 = F_89 ( V_23 , L_18 ) ;
if ( F_79 ( V_4 -> V_135 ) ) {
F_90 ( V_23 , L_19 ) ;
V_21 = F_80 ( V_4 -> V_135 ) ;
goto V_167;
}
V_4 -> V_31 = F_89 ( V_23 , L_20 ) ;
if ( F_79 ( V_4 -> V_31 ) ) {
F_90 ( V_23 , L_21 ) ;
V_21 = F_80 ( V_4 -> V_31 ) ;
goto V_167;
}
V_162 = F_91 ( V_158 , V_168 ,
V_4 -> V_35 ? L_22 : L_23 ) ;
if ( ! V_162 ) {
F_90 ( V_23 , L_24 ) ;
V_21 = - V_169 ;
goto V_167;
}
V_21 = F_92 ( V_23 , V_162 -> V_170 , F_71 ,
0 , L_25 , V_4 ) ;
if ( V_21 ) {
F_90 ( V_23 , L_24 ) ;
goto V_167;
}
F_93 ( & V_4 -> V_7 ) ;
F_2 ( & V_4 -> V_6 , 0 ) ;
F_94 ( V_158 , V_4 ) ;
V_4 -> V_156 = F_95 ( V_23 ) ;
if ( F_79 ( V_4 -> V_156 ) ) {
V_21 = F_80 ( V_4 -> V_156 ) ;
goto V_167;
}
F_96 ( V_23 ) ;
V_21 = F_97 ( V_23 , & V_171 ) ;
if ( V_21 )
goto V_172;
return V_21 ;
V_172:
F_98 ( V_23 ) ;
V_167:
F_99 ( V_4 -> V_13 ) ;
return V_21 ;
}
static int F_100 ( struct V_157 * V_158 )
{
struct V_3 * V_4 = F_76 ( & V_158 -> V_23 ) ;
F_98 ( & V_158 -> V_23 ) ;
F_99 ( V_4 -> V_13 ) ;
F_101 ( & V_158 -> V_23 , & V_171 ) ;
return 0 ;
}
