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
F_6 ( V_4 -> V_2 ) ;
V_21 = F_11 ( V_17 , V_4 -> V_23 ) ;
if ( V_21 )
V_19 -> V_22 -- ;
return V_21 ;
}
static void F_12 ( struct V_3 * V_4 )
{
F_13 ( V_4 -> V_17 , V_4 -> V_23 ) ;
}
static T_1 F_14 ( struct V_3 * V_4 ,
const struct V_24 * V_25 )
{
unsigned long V_26 = V_25 -> V_27 * V_25 -> V_28 * V_25 -> V_29 ;
T_1 V_30 ;
V_30 = F_15 ( F_16 ( V_4 -> V_31 ) , V_26 ) ;
return ( V_30 < 0x100 ) ? V_30 : 0xff ;
}
static void F_17 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_24 * V_25 = & V_2 -> V_32 . V_15 -> V_33 ;
T_1 V_12 , V_30 ;
if ( V_4 -> V_5 )
return;
if ( V_25 -> V_27 == 0 || V_25 -> V_28 == 0 )
return;
if ( ! V_4 -> V_34 ) {
int V_35 , V_36 , V_37 , V_38 , V_39 , V_40 ;
V_35 = V_25 -> V_41 - V_25 -> V_42 ;
V_36 = V_25 -> V_43 - V_25 -> V_41 ;
V_37 = V_25 -> V_42 - V_25 -> V_44 ;
V_12 = F_18 ( V_36 - 1 ) | F_19 ( V_37 - 1 ) ;
F_9 ( V_12 , V_4 -> V_13 + V_45 ) ;
V_12 = F_20 ( V_35 - 1 ) ;
F_9 ( V_12 , V_4 -> V_13 + V_46 ) ;
V_38 = V_25 -> V_47 - V_25 -> V_48 ;
V_39 = V_25 -> V_49 - V_25 -> V_47 ;
V_40 = V_25 -> V_48 - V_25 -> V_50 ;
V_12 = F_21 ( V_39 - 1 ) | F_22 ( V_40 - 1 ) ;
F_9 ( V_12 , V_4 -> V_13 + V_51 ) ;
V_12 = F_23 ( V_38 - 1 ) ;
F_9 ( V_12 , V_4 -> V_13 + V_52 ) ;
}
V_12 = F_24 ( V_25 -> V_53 - 1 ) |
F_25 ( V_25 -> V_54 - 1 ) ;
F_9 ( V_12 , V_4 -> V_13 + V_55 ) ;
F_9 ( V_25 -> V_53 - 1 , V_4 -> V_13 + V_56 ) ;
V_12 = V_57 | V_58 ;
F_9 ( V_12 , V_4 -> V_13 + V_59 ) ;
V_30 = F_14 ( V_4 , V_25 ) ;
if ( V_30 > 1 ) {
V_12 = F_26 ( V_30 - 1 ) ;
F_9 ( V_12 , V_4 -> V_13 + V_60 ) ;
F_9 ( V_12 , V_4 -> V_13 + V_61 ) ;
}
V_12 = F_7 ( V_4 -> V_13 + V_62 ) ;
V_12 |= V_63 ;
F_9 ( V_12 , V_4 -> V_13 + V_62 ) ;
}
static int F_27 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
T_1 V_12 ;
if ( V_4 -> V_5 )
return - V_64 ;
if ( ! F_28 ( 0 , & V_4 -> V_65 ) ) {
V_12 = F_7 ( V_4 -> V_13 + V_66 ) ;
V_12 |= V_67 ;
if ( ! V_4 -> V_34 ) {
V_12 |= V_68 ;
V_12 &= ~ V_69 ;
V_12 |= V_70 ;
}
F_9 ( V_12 , V_4 -> V_13 + V_66 ) ;
}
return 0 ;
}
static void F_29 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
T_1 V_12 ;
if ( V_4 -> V_5 )
return;
if ( F_30 ( 0 , & V_4 -> V_65 ) ) {
V_12 = F_7 ( V_4 -> V_13 + V_66 ) ;
V_12 &= ~ V_67 ;
if ( ! V_4 -> V_34 )
V_12 &= ~ V_68 ;
F_9 ( V_12 , V_4 -> V_13 + V_66 ) ;
}
}
static void F_31 ( struct V_3 * V_4 , unsigned int V_9 ,
struct V_71 * V_72 )
{
unsigned long V_12 ;
int V_73 ;
V_12 = F_7 ( V_4 -> V_13 + F_8 ( V_9 ) ) ;
V_12 &= ~ V_74 ;
switch ( V_72 -> V_75 ) {
case V_76 :
V_12 |= V_77 ;
V_12 |= V_78 ;
break;
case V_79 :
V_12 |= V_80 ;
V_12 |= V_78 ;
break;
case V_81 :
V_12 |= V_82 ;
V_12 |= V_78 ;
break;
case V_83 :
V_12 |= V_84 ;
V_12 |= V_78 ;
break;
case V_85 :
V_12 |= V_86 ;
V_12 |= V_78 ;
break;
case V_87 :
V_12 |= V_88 | V_89 |
V_90 ;
V_12 |= V_78 ;
break;
case V_91 :
V_12 |= V_92 | V_89 |
V_90 ;
V_12 |= V_78 ;
break;
case V_93 :
V_12 |= V_94 | V_89 |
V_90 ;
V_12 |= V_78 ;
break;
case V_95 :
V_12 |= V_96 | V_89 |
V_90 ;
V_12 |= V_78 ;
break;
default:
F_5 ( L_3 ) ;
V_12 |= V_80 ;
V_12 |= V_78 ;
break;
}
F_5 ( L_4 , V_72 -> V_97 ) ;
V_73 = ( V_72 -> V_98 [ 0 ] / ( V_72 -> V_97 >> 3 ) ) - V_72 -> V_99 ;
if ( V_72 -> V_99 + V_73 < V_100 ) {
V_12 &= ~ V_101 ;
V_12 |= V_102 ;
}
F_9 ( V_12 , V_4 -> V_13 + F_8 ( V_9 ) ) ;
}
static void F_32 ( struct V_3 * V_4 , unsigned int V_9 )
{
unsigned int V_103 = 0 , V_104 = 0 ;
V_103 = ~ ( V_105 | V_106 |
V_107 ) | F_33 ( 0 ) ;
V_104 = F_34 ( 0xffffffff ) ;
F_9 ( V_103 , V_4 -> V_13 + F_35 ( V_9 ) ) ;
F_9 ( V_104 , V_4 -> V_13 + F_36 ( V_9 ) ) ;
}
static void F_37 ( struct V_3 * V_4 ,
unsigned int V_9 , bool V_108 )
{
T_1 V_109 , V_12 ;
V_109 = F_38 ( V_9 ) ;
V_12 = F_7 ( V_4 -> V_13 + V_110 ) ;
if ( V_108 )
V_12 |= V_109 ;
else
V_12 &= ~ V_109 ;
F_9 ( V_12 , V_4 -> V_13 + V_110 ) ;
}
static void F_39 ( struct V_1 * V_2 ,
struct V_111 * V_112 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
if ( V_4 -> V_5 )
return;
F_37 ( V_4 , V_112 -> V_113 , true ) ;
}
static void F_40 ( struct V_1 * V_2 ,
struct V_111 * V_112 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_24 * V_25 = & V_2 -> V_32 . V_15 -> V_33 ;
struct V_114 * V_15 = V_112 -> V_32 . V_15 ;
int V_73 ;
unsigned long V_12 , V_115 ;
unsigned int V_116 ;
unsigned int V_117 ;
unsigned int V_9 = V_112 -> V_113 ;
unsigned int V_118 = V_15 -> V_72 -> V_97 >> 3 ;
unsigned int V_119 = V_15 -> V_72 -> V_98 [ 0 ] ;
if ( V_4 -> V_5 )
return;
V_12 = ( unsigned long ) V_112 -> V_120 [ 0 ] ;
F_9 ( V_12 , V_4 -> V_13 + F_41 ( V_9 ) ) ;
V_73 = ( V_119 / V_118 ) - V_15 -> V_72 -> V_99 ;
F_9 ( V_15 -> V_72 -> V_99 + V_73 , V_4 -> V_13 + F_42 ( V_9 ) ) ;
F_9 ( V_15 -> V_72 -> V_121 , V_4 -> V_13 + F_43 ( V_9 ) ) ;
F_9 ( V_112 -> V_122 , V_4 -> V_13 + F_44 ( V_9 ) ) ;
F_9 ( V_112 -> V_123 , V_4 -> V_13 + F_45 ( V_9 ) ) ;
F_5 ( L_5 ,
( unsigned long ) V_12 ) ;
F_5 ( L_6 ,
V_112 -> V_124 , V_112 -> V_125 ) ;
if ( ( V_112 -> V_126 + V_112 -> V_124 ) > V_25 -> V_54 )
V_112 -> V_126 = V_25 -> V_54 - V_112 -> V_124 ;
if ( ( V_112 -> V_127 + V_112 -> V_125 ) > V_25 -> V_53 )
V_112 -> V_127 = V_25 -> V_53 - V_112 -> V_125 ;
V_12 = F_46 ( V_112 -> V_126 ) |
F_47 ( V_112 -> V_127 ) ;
F_9 ( V_12 , V_4 -> V_13 + F_48 ( V_9 ) ) ;
V_116 = V_112 -> V_126 + V_112 -> V_124 ;
if ( V_116 )
V_116 -- ;
V_117 = V_112 -> V_127 + V_112 -> V_125 ;
if ( V_117 )
V_117 -- ;
V_12 = F_49 ( V_116 ) | F_50 ( V_117 ) ;
F_9 ( V_12 , V_4 -> V_13 + F_51 ( V_9 ) ) ;
F_5 ( L_7 ,
V_112 -> V_126 , V_112 -> V_127 , V_116 , V_117 ) ;
V_115 = F_52 ( 0x0 ) |
F_53 ( 0x0 ) |
F_54 ( 0x0 ) ;
F_9 ( V_115 , V_4 -> V_13 + F_55 ( V_9 ) ) ;
V_115 = F_56 ( 0xff ) |
F_57 ( 0xff ) |
F_58 ( 0xff ) ;
F_9 ( V_115 , V_4 -> V_13 + F_59 ( V_9 ) ) ;
F_31 ( V_4 , V_9 , V_15 -> V_72 ) ;
if ( V_9 != 0 )
F_32 ( V_4 , V_9 ) ;
V_12 = F_7 ( V_4 -> V_13 + F_8 ( V_9 ) ) ;
V_12 |= V_128 ;
V_12 |= V_14 ;
F_9 ( V_12 , V_4 -> V_13 + F_8 ( V_9 ) ) ;
F_37 ( V_4 , V_9 , false ) ;
V_12 = F_7 ( V_4 -> V_13 + V_62 ) ;
V_12 |= V_63 ;
F_9 ( V_12 , V_4 -> V_13 + V_62 ) ;
}
static void F_60 ( struct V_1 * V_2 ,
struct V_111 * V_112 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
unsigned int V_9 = V_112 -> V_113 ;
T_1 V_12 ;
if ( V_4 -> V_5 )
return;
F_37 ( V_4 , V_9 , true ) ;
V_12 = F_7 ( V_4 -> V_13 + F_8 ( V_9 ) ) ;
V_12 &= ~ V_14 ;
F_9 ( V_12 , V_4 -> V_13 + F_8 ( V_9 ) ) ;
V_12 = F_7 ( V_4 -> V_13 + V_62 ) ;
V_12 |= V_63 ;
F_9 ( V_12 , V_4 -> V_13 + V_62 ) ;
}
static void F_61 ( struct V_1 * V_2 ,
struct V_111 * V_112 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
if ( V_4 -> V_5 )
return;
F_37 ( V_4 , V_112 -> V_113 , false ) ;
}
static void F_62 ( struct V_3 * V_4 )
{
T_1 V_12 ;
F_9 ( V_129 , V_4 -> V_13 + V_59 ) ;
V_12 = V_130 ;
if ( ! V_4 -> V_34 )
V_12 |= V_131 ;
F_9 ( V_12 , V_4 -> V_13 + V_132 ) ;
F_9 ( V_133 | V_134 , V_4 -> V_13 + V_135 ) ;
if ( ! V_4 -> V_34 )
F_9 ( V_136 , V_4 -> V_13 + F_63 ( 0 ) ) ;
}
static void F_64 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
int V_21 ;
if ( ! V_4 -> V_5 )
return;
V_4 -> V_5 = false ;
F_65 ( V_4 -> V_23 ) ;
V_21 = F_66 ( V_4 -> V_137 ) ;
if ( V_21 < 0 ) {
F_67 ( L_8 , V_21 ) ;
return;
}
V_21 = F_66 ( V_4 -> V_138 ) ;
if ( V_21 < 0 ) {
F_67 ( L_9 , V_21 ) ;
return;
}
V_21 = F_66 ( V_4 -> V_139 ) ;
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
if ( F_30 ( 0 , & V_4 -> V_65 ) )
F_27 ( V_4 -> V_2 ) ;
F_17 ( V_4 -> V_2 ) ;
}
static void F_68 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
int V_140 ;
if ( V_4 -> V_5 )
return;
for ( V_140 = 0 ; V_140 < V_11 ; V_140 ++ )
F_60 ( V_2 , & V_4 -> V_141 [ V_140 ] ) ;
F_69 ( V_4 -> V_31 ) ;
F_69 ( V_4 -> V_139 ) ;
F_69 ( V_4 -> V_138 ) ;
F_69 ( V_4 -> V_137 ) ;
F_70 ( V_4 -> V_23 ) ;
V_4 -> V_5 = true ;
}
static T_2 F_71 ( int V_142 , void * V_143 )
{
struct V_3 * V_4 = (struct V_3 * ) V_143 ;
T_1 V_12 , V_144 ;
int V_9 ;
V_12 = F_7 ( V_4 -> V_13 + V_145 ) ;
V_144 = V_4 -> V_34 ? V_146 : V_147 ;
if ( V_12 & V_144 )
F_9 ( V_144 , V_4 -> V_13 + V_145 ) ;
if ( V_4 -> V_22 < 0 || ! V_4 -> V_17 )
goto V_148;
if ( ! V_4 -> V_34 ) {
F_72 ( & V_4 -> V_2 -> V_32 ) ;
for ( V_9 = 0 ; V_9 < V_11 ; V_9 ++ ) {
struct V_111 * V_112 = & V_4 -> V_141 [ V_9 ] ;
if ( ! V_112 -> V_149 )
continue;
F_73 ( V_4 -> V_2 , V_112 ) ;
}
if ( F_4 ( & V_4 -> V_6 ) ) {
F_2 ( & V_4 -> V_6 , 0 ) ;
F_74 ( & V_4 -> V_7 ) ;
}
}
V_148:
return V_150 ;
}
static int F_75 ( struct V_151 * V_23 , struct V_151 * V_152 , void * V_153 )
{
struct V_3 * V_4 = F_76 ( V_23 ) ;
struct V_16 * V_17 = V_153 ;
struct V_111 * V_154 ;
enum V_155 type ;
unsigned int V_113 ;
int V_21 ;
V_21 = F_10 ( V_4 , V_17 ) ;
if ( V_21 ) {
F_67 ( L_12 ) ;
return V_21 ;
}
for ( V_113 = 0 ; V_113 < V_11 ; V_113 ++ ) {
type = F_77 ( V_113 , V_156 ) ;
V_21 = F_78 ( V_17 , & V_4 -> V_141 [ V_113 ] ,
1 << V_4 -> V_22 , type , V_157 ,
F_79 ( V_157 ) , V_113 ) ;
if ( V_21 )
return V_21 ;
}
V_154 = & V_4 -> V_141 [ V_158 ] ;
V_4 -> V_2 = F_80 ( V_17 , & V_154 -> V_32 ,
V_4 -> V_22 , V_159 ,
& V_160 , V_4 ) ;
if ( F_81 ( V_4 -> V_2 ) ) {
F_12 ( V_4 ) ;
return F_82 ( V_4 -> V_2 ) ;
}
if ( V_4 -> V_161 )
F_83 ( V_17 , V_4 -> V_161 ) ;
return 0 ;
}
static void F_84 ( struct V_151 * V_23 , struct V_151 * V_152 ,
void * V_153 )
{
struct V_3 * V_4 = F_76 ( V_23 ) ;
F_68 ( V_4 -> V_2 ) ;
if ( V_4 -> V_161 )
F_85 ( V_4 -> V_161 ) ;
F_12 ( V_4 ) ;
}
static int F_86 ( struct V_162 * V_163 )
{
struct V_151 * V_23 = & V_163 -> V_23 ;
struct V_3 * V_4 ;
struct V_164 * V_165 ;
struct V_166 * V_167 ;
int V_21 ;
if ( ! V_23 -> V_168 )
return - V_169 ;
V_4 = F_87 ( V_23 , sizeof( * V_4 ) , V_170 ) ;
if ( ! V_4 )
return - V_171 ;
V_4 -> V_23 = V_23 ;
V_4 -> V_5 = true ;
V_165 = F_88 ( V_23 -> V_168 , L_13 ) ;
if ( V_165 )
V_4 -> V_34 = true ;
F_89 ( V_165 ) ;
V_4 -> V_13 = F_90 ( V_23 -> V_168 , 0 ) ;
if ( ! V_4 -> V_13 )
return - V_171 ;
V_4 -> V_137 = F_91 ( V_23 , L_14 ) ;
if ( F_81 ( V_4 -> V_137 ) ) {
F_92 ( V_23 , L_15 ) ;
V_21 = F_82 ( V_4 -> V_137 ) ;
goto V_172;
}
V_4 -> V_138 = F_91 ( V_23 , L_16 ) ;
if ( F_81 ( V_4 -> V_138 ) ) {
F_92 ( V_23 , L_17 ) ;
V_21 = F_82 ( V_4 -> V_138 ) ;
goto V_172;
}
V_4 -> V_139 = F_91 ( V_23 , L_18 ) ;
if ( F_81 ( V_4 -> V_139 ) ) {
F_92 ( V_23 , L_19 ) ;
V_21 = F_82 ( V_4 -> V_139 ) ;
goto V_172;
}
V_4 -> V_31 = F_91 ( V_23 , L_20 ) ;
if ( F_81 ( V_4 -> V_31 ) ) {
F_92 ( V_23 , L_21 ) ;
V_21 = F_82 ( V_4 -> V_31 ) ;
goto V_172;
}
V_167 = F_93 ( V_163 , V_173 ,
V_4 -> V_34 ? L_22 : L_23 ) ;
if ( ! V_167 ) {
F_92 ( V_23 , L_24 ) ;
V_21 = - V_174 ;
goto V_172;
}
V_21 = F_94 ( V_23 , V_167 -> V_175 , F_71 ,
0 , L_25 , V_4 ) ;
if ( V_21 ) {
F_92 ( V_23 , L_24 ) ;
goto V_172;
}
F_95 ( & V_4 -> V_7 ) ;
F_2 ( & V_4 -> V_6 , 0 ) ;
F_96 ( V_163 , V_4 ) ;
V_4 -> V_161 = F_97 ( V_23 ) ;
if ( F_81 ( V_4 -> V_161 ) ) {
V_21 = F_82 ( V_4 -> V_161 ) ;
goto V_172;
}
F_98 ( V_23 ) ;
V_21 = F_99 ( V_23 , & V_176 ) ;
if ( V_21 )
goto V_177;
return V_21 ;
V_177:
F_100 ( V_23 ) ;
V_172:
F_101 ( V_4 -> V_13 ) ;
return V_21 ;
}
static int F_102 ( struct V_162 * V_163 )
{
struct V_3 * V_4 = F_76 ( & V_163 -> V_23 ) ;
F_100 ( & V_163 -> V_23 ) ;
F_101 ( V_4 -> V_13 ) ;
F_103 ( & V_163 -> V_23 , & V_176 ) ;
return 0 ;
}
