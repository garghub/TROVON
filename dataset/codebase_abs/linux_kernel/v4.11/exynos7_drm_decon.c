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
if ( V_10 )
F_1 ( V_4 -> V_2 ) ;
}
static int F_10 ( struct V_3 * V_4 ,
struct V_15 * V_16 )
{
struct V_17 * V_18 = V_16 -> V_19 ;
int V_20 ;
V_4 -> V_16 = V_16 ;
V_4 -> V_21 = V_18 -> V_21 ++ ;
F_6 ( V_4 -> V_2 ) ;
V_20 = F_11 ( V_16 , V_4 -> V_22 ) ;
if ( V_20 )
V_18 -> V_21 -- ;
return V_20 ;
}
static void F_12 ( struct V_3 * V_4 )
{
F_13 ( V_4 -> V_16 , V_4 -> V_22 ) ;
}
static T_1 F_14 ( struct V_3 * V_4 ,
const struct V_23 * V_24 )
{
unsigned long V_25 = V_24 -> V_26 * V_24 -> V_27 * V_24 -> V_28 ;
T_1 V_29 ;
V_29 = F_15 ( F_16 ( V_4 -> V_30 ) , V_25 ) ;
return ( V_29 < 0x100 ) ? V_29 : 0xff ;
}
static void F_17 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_23 * V_24 = & V_2 -> V_31 . V_32 -> V_33 ;
T_1 V_12 , V_29 ;
if ( V_4 -> V_5 )
return;
if ( V_24 -> V_26 == 0 || V_24 -> V_27 == 0 )
return;
if ( ! V_4 -> V_34 ) {
int V_35 , V_36 , V_37 , V_38 , V_39 , V_40 ;
V_35 = V_24 -> V_41 - V_24 -> V_42 ;
V_36 = V_24 -> V_43 - V_24 -> V_41 ;
V_37 = V_24 -> V_42 - V_24 -> V_44 ;
V_12 = F_18 ( V_36 - 1 ) | F_19 ( V_37 - 1 ) ;
F_9 ( V_12 , V_4 -> V_13 + V_45 ) ;
V_12 = F_20 ( V_35 - 1 ) ;
F_9 ( V_12 , V_4 -> V_13 + V_46 ) ;
V_38 = V_24 -> V_47 - V_24 -> V_48 ;
V_39 = V_24 -> V_49 - V_24 -> V_47 ;
V_40 = V_24 -> V_48 - V_24 -> V_50 ;
V_12 = F_21 ( V_39 - 1 ) | F_22 ( V_40 - 1 ) ;
F_9 ( V_12 , V_4 -> V_13 + V_51 ) ;
V_12 = F_23 ( V_38 - 1 ) ;
F_9 ( V_12 , V_4 -> V_13 + V_52 ) ;
}
V_12 = F_24 ( V_24 -> V_53 - 1 ) |
F_25 ( V_24 -> V_54 - 1 ) ;
F_9 ( V_12 , V_4 -> V_13 + V_55 ) ;
F_9 ( V_24 -> V_53 - 1 , V_4 -> V_13 + V_56 ) ;
V_12 = V_57 | V_58 ;
F_9 ( V_12 , V_4 -> V_13 + V_59 ) ;
V_29 = F_14 ( V_4 , V_24 ) ;
if ( V_29 > 1 ) {
V_12 = F_26 ( V_29 - 1 ) ;
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
switch ( V_72 -> V_75 -> V_75 ) {
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
F_5 ( L_4 , V_72 -> V_75 -> V_97 [ 0 ] * 8 ) ;
V_73 = ( V_72 -> V_98 [ 0 ] / V_72 -> V_75 -> V_97 [ 0 ] ) - V_72 -> V_99 ;
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
static void F_39 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
int V_111 ;
if ( V_4 -> V_5 )
return;
for ( V_111 = 0 ; V_111 < V_11 ; V_111 ++ )
F_37 ( V_4 , V_111 , true ) ;
}
static void F_40 ( struct V_1 * V_2 ,
struct V_112 * V_113 )
{
struct V_114 * V_32 =
F_41 ( V_113 -> V_31 . V_32 ) ;
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_71 * V_72 = V_32 -> V_31 . V_72 ;
int V_73 ;
unsigned long V_12 , V_115 ;
unsigned int V_116 ;
unsigned int V_117 ;
unsigned int V_9 = V_113 -> V_118 ;
unsigned int V_119 = V_72 -> V_75 -> V_97 [ 0 ] ;
unsigned int V_120 = V_72 -> V_98 [ 0 ] ;
if ( V_4 -> V_5 )
return;
V_12 = ( unsigned long ) F_42 ( V_72 , 0 ) ;
F_9 ( V_12 , V_4 -> V_13 + F_43 ( V_9 ) ) ;
V_73 = ( V_120 / V_119 ) - V_72 -> V_99 ;
F_9 ( V_72 -> V_99 + V_73 , V_4 -> V_13 + F_44 ( V_9 ) ) ;
F_9 ( V_72 -> V_121 , V_4 -> V_13 + F_45 ( V_9 ) ) ;
F_9 ( V_32 -> V_122 . V_123 , V_4 -> V_13 + F_46 ( V_9 ) ) ;
F_9 ( V_32 -> V_122 . V_124 , V_4 -> V_13 + F_47 ( V_9 ) ) ;
F_5 ( L_5 ,
( unsigned long ) V_12 ) ;
F_5 ( L_6 ,
V_32 -> V_2 . V_125 , V_32 -> V_2 . V_126 ) ;
V_12 = F_48 ( V_32 -> V_2 . V_123 ) |
F_49 ( V_32 -> V_2 . V_124 ) ;
F_9 ( V_12 , V_4 -> V_13 + F_50 ( V_9 ) ) ;
V_116 = V_32 -> V_2 . V_123 + V_32 -> V_2 . V_125 ;
if ( V_116 )
V_116 -- ;
V_117 = V_32 -> V_2 . V_124 + V_32 -> V_2 . V_126 ;
if ( V_117 )
V_117 -- ;
V_12 = F_51 ( V_116 ) | F_52 ( V_117 ) ;
F_9 ( V_12 , V_4 -> V_13 + F_53 ( V_9 ) ) ;
F_5 ( L_7 ,
V_32 -> V_2 . V_123 , V_32 -> V_2 . V_124 , V_116 , V_117 ) ;
V_115 = F_54 ( 0x0 ) |
F_55 ( 0x0 ) |
F_56 ( 0x0 ) ;
F_9 ( V_115 , V_4 -> V_13 + F_57 ( V_9 ) ) ;
V_115 = F_58 ( 0xff ) |
F_59 ( 0xff ) |
F_60 ( 0xff ) ;
F_9 ( V_115 , V_4 -> V_13 + F_61 ( V_9 ) ) ;
F_31 ( V_4 , V_9 , V_72 ) ;
if ( V_9 != 0 )
F_32 ( V_4 , V_9 ) ;
V_12 = F_7 ( V_4 -> V_13 + F_8 ( V_9 ) ) ;
V_12 |= V_127 ;
V_12 |= V_14 ;
F_9 ( V_12 , V_4 -> V_13 + F_8 ( V_9 ) ) ;
F_37 ( V_4 , V_9 , false ) ;
V_12 = F_7 ( V_4 -> V_13 + V_62 ) ;
V_12 |= V_63 ;
F_9 ( V_12 , V_4 -> V_13 + V_62 ) ;
}
static void F_62 ( struct V_1 * V_2 ,
struct V_112 * V_113 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
unsigned int V_9 = V_113 -> V_118 ;
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
static void F_63 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
int V_111 ;
if ( V_4 -> V_5 )
return;
for ( V_111 = 0 ; V_111 < V_11 ; V_111 ++ )
F_37 ( V_4 , V_111 , false ) ;
F_64 ( V_2 ) ;
}
static void F_65 ( struct V_3 * V_4 )
{
T_1 V_12 ;
F_9 ( V_128 , V_4 -> V_13 + V_59 ) ;
V_12 = V_129 ;
if ( ! V_4 -> V_34 )
V_12 |= V_130 ;
F_9 ( V_12 , V_4 -> V_13 + V_131 ) ;
F_9 ( V_132 | V_133 , V_4 -> V_13 + V_134 ) ;
if ( ! V_4 -> V_34 )
F_9 ( V_135 , V_4 -> V_13 + F_66 ( 0 ) ) ;
}
static void F_67 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
if ( ! V_4 -> V_5 )
return;
F_68 ( V_4 -> V_22 ) ;
F_65 ( V_4 ) ;
if ( F_30 ( 0 , & V_4 -> V_65 ) )
F_27 ( V_4 -> V_2 ) ;
F_17 ( V_4 -> V_2 ) ;
V_4 -> V_5 = false ;
}
static void F_69 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
int V_111 ;
if ( V_4 -> V_5 )
return;
for ( V_111 = 0 ; V_111 < V_11 ; V_111 ++ )
F_62 ( V_2 , & V_4 -> V_136 [ V_111 ] ) ;
F_70 ( V_4 -> V_22 ) ;
V_4 -> V_5 = true ;
}
static T_2 F_71 ( int V_137 , void * V_138 )
{
struct V_3 * V_4 = (struct V_3 * ) V_138 ;
T_1 V_12 , V_139 ;
V_12 = F_7 ( V_4 -> V_13 + V_140 ) ;
V_139 = V_4 -> V_34 ? V_141 : V_142 ;
if ( V_12 & V_139 )
F_9 ( V_139 , V_4 -> V_13 + V_140 ) ;
if ( V_4 -> V_21 < 0 || ! V_4 -> V_16 )
goto V_143;
if ( ! V_4 -> V_34 ) {
F_72 ( & V_4 -> V_2 -> V_31 ) ;
if ( F_4 ( & V_4 -> V_6 ) ) {
F_2 ( & V_4 -> V_6 , 0 ) ;
F_73 ( & V_4 -> V_7 ) ;
}
}
V_143:
return V_144 ;
}
static int F_74 ( struct V_145 * V_22 , struct V_145 * V_146 , void * V_147 )
{
struct V_3 * V_4 = F_75 ( V_22 ) ;
struct V_15 * V_16 = V_147 ;
struct V_112 * V_148 ;
unsigned int V_111 ;
int V_20 ;
V_20 = F_10 ( V_4 , V_16 ) ;
if ( V_20 ) {
F_76 ( L_8 ) ;
return V_20 ;
}
for ( V_111 = 0 ; V_111 < V_11 ; V_111 ++ ) {
V_4 -> V_149 [ V_111 ] . V_150 = V_151 ;
V_4 -> V_149 [ V_111 ] . V_152 = F_77 ( V_151 ) ;
V_4 -> V_149 [ V_111 ] . V_153 = V_111 ;
V_4 -> V_149 [ V_111 ] . type = V_154 [ V_111 ] ;
V_20 = F_78 ( V_16 , & V_4 -> V_136 [ V_111 ] , V_111 ,
1 << V_4 -> V_21 , & V_4 -> V_149 [ V_111 ] ) ;
if ( V_20 )
return V_20 ;
}
V_148 = & V_4 -> V_136 [ V_155 ] ;
V_4 -> V_2 = F_79 ( V_16 , & V_148 -> V_31 ,
V_4 -> V_21 , V_156 ,
& V_157 , V_4 ) ;
if ( F_80 ( V_4 -> V_2 ) ) {
F_12 ( V_4 ) ;
return F_81 ( V_4 -> V_2 ) ;
}
if ( V_4 -> V_158 )
F_82 ( V_16 , V_4 -> V_158 ) ;
return 0 ;
}
static void F_83 ( struct V_145 * V_22 , struct V_145 * V_146 ,
void * V_147 )
{
struct V_3 * V_4 = F_75 ( V_22 ) ;
F_69 ( V_4 -> V_2 ) ;
if ( V_4 -> V_158 )
F_84 ( V_4 -> V_158 ) ;
F_12 ( V_4 ) ;
}
static int F_85 ( struct V_159 * V_160 )
{
struct V_145 * V_22 = & V_160 -> V_22 ;
struct V_3 * V_4 ;
struct V_161 * V_162 ;
struct V_163 * V_164 ;
int V_20 ;
if ( ! V_22 -> V_165 )
return - V_166 ;
V_4 = F_86 ( V_22 , sizeof( * V_4 ) , V_167 ) ;
if ( ! V_4 )
return - V_168 ;
V_4 -> V_22 = V_22 ;
V_4 -> V_5 = true ;
V_162 = F_87 ( V_22 -> V_165 , L_9 ) ;
if ( V_162 )
V_4 -> V_34 = true ;
F_88 ( V_162 ) ;
V_4 -> V_13 = F_89 ( V_22 -> V_165 , 0 ) ;
if ( ! V_4 -> V_13 )
return - V_168 ;
V_4 -> V_169 = F_90 ( V_22 , L_10 ) ;
if ( F_80 ( V_4 -> V_169 ) ) {
F_91 ( V_22 , L_11 ) ;
V_20 = F_81 ( V_4 -> V_169 ) ;
goto V_170;
}
V_4 -> V_171 = F_90 ( V_22 , L_12 ) ;
if ( F_80 ( V_4 -> V_171 ) ) {
F_91 ( V_22 , L_13 ) ;
V_20 = F_81 ( V_4 -> V_171 ) ;
goto V_170;
}
V_4 -> V_172 = F_90 ( V_22 , L_14 ) ;
if ( F_80 ( V_4 -> V_172 ) ) {
F_91 ( V_22 , L_15 ) ;
V_20 = F_81 ( V_4 -> V_172 ) ;
goto V_170;
}
V_4 -> V_30 = F_90 ( V_22 , L_16 ) ;
if ( F_80 ( V_4 -> V_30 ) ) {
F_91 ( V_22 , L_17 ) ;
V_20 = F_81 ( V_4 -> V_30 ) ;
goto V_170;
}
V_164 = F_92 ( V_160 , V_173 ,
V_4 -> V_34 ? L_18 : L_19 ) ;
if ( ! V_164 ) {
F_91 ( V_22 , L_20 ) ;
V_20 = - V_174 ;
goto V_170;
}
V_20 = F_93 ( V_22 , V_164 -> V_175 , F_71 ,
0 , L_21 , V_4 ) ;
if ( V_20 ) {
F_91 ( V_22 , L_20 ) ;
goto V_170;
}
F_94 ( & V_4 -> V_7 ) ;
F_2 ( & V_4 -> V_6 , 0 ) ;
F_95 ( V_160 , V_4 ) ;
V_4 -> V_158 = F_96 ( V_22 ) ;
if ( F_80 ( V_4 -> V_158 ) ) {
V_20 = F_81 ( V_4 -> V_158 ) ;
goto V_170;
}
F_97 ( V_22 ) ;
V_20 = F_98 ( V_22 , & V_176 ) ;
if ( V_20 )
goto V_177;
return V_20 ;
V_177:
F_99 ( V_22 ) ;
V_170:
F_100 ( V_4 -> V_13 ) ;
return V_20 ;
}
static int F_101 ( struct V_159 * V_160 )
{
struct V_3 * V_4 = F_75 ( & V_160 -> V_22 ) ;
F_99 ( & V_160 -> V_22 ) ;
F_100 ( V_4 -> V_13 ) ;
F_102 ( & V_160 -> V_22 , & V_176 ) ;
return 0 ;
}
static int F_103 ( struct V_145 * V_22 )
{
struct V_3 * V_4 = F_75 ( V_22 ) ;
F_104 ( V_4 -> V_30 ) ;
F_104 ( V_4 -> V_172 ) ;
F_104 ( V_4 -> V_171 ) ;
F_104 ( V_4 -> V_169 ) ;
return 0 ;
}
static int F_105 ( struct V_145 * V_22 )
{
struct V_3 * V_4 = F_75 ( V_22 ) ;
int V_20 ;
V_20 = F_106 ( V_4 -> V_169 ) ;
if ( V_20 < 0 ) {
F_76 ( L_22 , V_20 ) ;
return V_20 ;
}
V_20 = F_106 ( V_4 -> V_171 ) ;
if ( V_20 < 0 ) {
F_76 ( L_23 , V_20 ) ;
return V_20 ;
}
V_20 = F_106 ( V_4 -> V_172 ) ;
if ( V_20 < 0 ) {
F_76 ( L_24 , V_20 ) ;
return V_20 ;
}
V_20 = F_106 ( V_4 -> V_30 ) ;
if ( V_20 < 0 ) {
F_76 ( L_25 , V_20 ) ;
return V_20 ;
}
return 0 ;
}
