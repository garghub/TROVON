static void T_1 * F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 -> V_6 ;
return V_4 -> V_7 + V_2 -> V_8 * V_9 ;
}
static void F_2 ( void T_1 * V_10 )
{
void T_1 * V_11 = V_10 + V_12 ;
F_3 ( V_11 ) ;
F_4 ( 1 ) ;
F_5 ( V_13 , V_11 ) ;
F_3 ( V_11 ) ;
F_4 ( 1 ) ;
F_5 ( 0 , V_11 ) ;
F_6 ( 0xff , V_10 + V_14 ) ;
}
static int F_7 ( struct V_15 * V_16 , unsigned V_17 , T_2 * V_18 )
{
void T_1 * V_19 = F_1 ( V_16 -> V_2 ) + V_20 ;
void T_1 * V_21 ;
if ( F_8 ( V_17 >= F_9 ( V_22 ) ) )
return - V_23 ;
V_21 = V_19 + V_22 [ V_17 ] * 4 ;
* V_18 = F_10 ( V_19 + V_22 [ V_17 ] * 4 ) ;
if ( V_17 == V_24 )
* V_18 &= ~ V_25 ;
return 0 ;
}
static int F_11 ( struct V_15 * V_16 , unsigned V_17 , T_2 V_18 )
{
void T_1 * V_19 = F_1 ( V_16 -> V_2 ) + V_20 ;
if ( F_8 ( V_17 >= F_9 ( V_22 ) ) )
return - V_23 ;
F_12 ( V_18 , V_19 + V_22 [ V_17 ] * 4 ) ;
return 0 ;
}
static void F_13 ( struct V_1 * V_2 )
{
void T_1 * V_10 = F_1 ( V_2 ) ;
F_14 ( V_10 + V_26 ) ;
F_14 ( V_10 + V_27 ) ;
F_5 ( 0 , V_10 + V_12 ) ;
}
static void F_15 ( struct V_1 * V_2 , T_3 V_28 , T_4 V_29 )
{
struct V_30 * V_31 = & V_2 -> V_16 . V_32 ;
struct V_33 * V_34 = V_2 -> V_6 ;
struct V_35 * V_36 = & V_34 -> V_37 -> V_36 ;
bool V_38 = false ;
F_16 ( V_31 ) ;
F_17 ( V_31 , L_1 ,
V_28 , V_29 ) ;
F_13 ( V_2 ) ;
if ( V_28 & ( V_39 | V_40 ) ) {
F_17 ( V_31 , L_2 ) ;
F_18 ( V_31 ) ;
V_38 = true ;
}
if ( V_29 & V_41 ) {
F_17 ( V_31 , L_3 ) ;
V_38 = true ;
}
if ( V_29 & V_42 ) {
F_17 ( V_31 , L_4 ) ;
if ( V_36 -> V_43 & V_44 ) {
F_19 ( V_31 , L_5 ) ;
V_31 -> V_45 |= V_46 ;
V_38 = true ;
}
if ( V_36 -> V_43 & V_47 )
V_31 -> V_45 |= V_48 ;
if ( V_36 -> V_43 & V_49 ) {
F_19 ( V_31 , L_6 ) ;
V_31 -> V_45 |= V_50 ;
V_38 = true ;
}
if ( V_36 -> V_43 &
( V_51 | V_52 ) ) {
F_19 ( V_31 , L_7 ) ;
V_31 -> V_45 |= V_50 ;
V_38 = true ;
}
}
if ( V_38 )
F_20 ( V_2 ) ;
else
F_21 ( V_2 ) ;
}
static void F_22 ( struct V_1 * V_2 )
{
void T_1 * V_10 = F_1 ( V_2 ) ;
struct V_53 * V_54 = F_23 ( V_2 , V_2 -> V_16 . V_55 ) ;
T_3 V_28 ;
T_4 V_29 ;
V_28 = F_14 ( V_10 + V_14 ) ;
F_6 ( V_28 , V_10 + V_14 ) ;
V_29 = F_3 ( V_10 + V_56 ) ;
if ( F_8 ( ( V_28 & V_57 ) || ( V_29 & V_58 ) ) )
F_15 ( V_2 , V_28 , V_29 ) ;
if ( F_8 ( ! V_54 ) )
goto V_59;
if ( F_24 ( V_29 & V_60 ) ) {
F_13 ( V_2 ) ;
if ( F_8 ( F_14 ( V_10 + V_61 ) &
( V_62 | V_63 ) ) )
V_54 -> V_45 |= V_48 ;
F_25 ( V_54 ) ;
return;
}
V_59:
F_26 ( V_2 , V_64 , L_8
L_9 ,
V_54 ? V_54 -> V_65 . V_66 : 0xff , V_28 , V_29 ) ;
}
static T_5 F_27 ( int V_67 , void * V_68 )
{
struct V_69 * V_5 = V_68 ;
struct V_3 * V_4 = V_5 -> V_6 ;
T_4 V_70 ;
int V_71 , V_72 = 0 ;
V_70 = F_3 ( V_4 -> V_7 + V_73 ) ;
if ( F_8 ( ! ( V_70 & V_74 ) ) )
goto V_75;
F_28 ( & V_5 -> V_76 ) ;
for ( V_71 = 0 ; V_71 < V_77 ; V_71 ++ )
if ( V_70 & ( V_78 << V_71 ) ) {
F_22 ( V_5 -> V_79 [ V_71 ] ) ;
V_72 ++ ;
}
F_29 ( & V_5 -> V_76 ) ;
V_75:
return F_30 ( V_72 ) ;
}
static int F_31 ( struct V_53 * V_54 )
{
if ( F_32 ( V_54 -> V_80 [ 0 ] ) == V_81 )
return 0 ;
return 1 ;
}
static void F_33 ( struct V_82 * V_83 , struct V_53 * V_54 )
{
struct V_84 * V_85 ;
unsigned int V_86 ;
T_3 V_87 = 0 ;
if ( V_54 -> V_65 . V_87 & V_88 )
V_87 |= V_89 ;
if ( F_34 ( V_54 -> V_65 . V_90 ) )
V_87 |= V_91 ;
F_35 (qc->sg, sg, qc->n_elem, si) {
V_83 -> V_92 = F_36 ( F_37 ( V_85 ) ) ;
V_83 -> V_93 = F_38 ( F_39 ( V_85 ) ) ;
V_83 -> V_87 = V_87 ;
V_83 ++ ;
}
F_40 ( ! V_86 ) ;
V_83 [ - 1 ] . V_87 |= V_94 ;
}
static void F_41 ( struct V_53 * V_54 )
{
struct V_33 * V_34 = V_54 -> V_2 -> V_6 ;
struct V_95 * V_37 = V_34 -> V_37 ;
struct V_35 * V_36 = & V_37 -> V_36 ;
struct V_82 * V_83 = V_37 -> V_83 ;
bool V_96 = F_42 ( V_54 -> V_65 . V_90 ) ;
bool V_97 = F_43 ( V_54 -> V_65 . V_90 ) ;
unsigned int V_98 = 0 ;
F_44 ( L_10 ) ;
if ( V_96 )
V_98 = V_54 -> V_99 -> V_98 ;
memset ( V_37 , 0 , sizeof( struct V_95 ) ) ;
V_36 -> V_100 = V_101 | V_102 ;
if ( V_96 || V_97 )
V_36 -> V_100 |= V_103 ;
V_36 -> V_93 = F_36 ( V_54 -> V_104 + V_98 ) ;
V_36 -> V_83 = F_36 ( V_34 -> V_105 + F_45 ( struct V_95 , V_83 ) ) ;
V_36 -> V_106 = V_54 -> V_65 . V_106 ;
V_36 -> V_107 = V_54 -> V_65 . V_107 ;
V_36 -> V_108 = V_54 -> V_65 . V_108 ;
V_36 -> V_109 = V_54 -> V_65 . V_109 ;
V_36 -> V_110 = V_54 -> V_65 . V_110 ;
V_36 -> V_111 = V_54 -> V_65 . V_111 ;
if ( V_54 -> V_65 . V_87 & V_112 ) {
V_36 -> V_113 = V_54 -> V_65 . V_113 ;
V_36 -> V_114 = V_54 -> V_65 . V_114 ;
V_36 -> V_115 = V_54 -> V_65 . V_115 ;
V_36 -> V_116 = V_54 -> V_65 . V_116 ;
V_36 -> V_117 = V_54 -> V_65 . V_117 ;
}
V_36 -> V_66 = V_54 -> V_65 . V_66 ;
if ( V_96 ) {
memcpy ( V_37 -> V_80 , V_54 -> V_80 , V_118 ) ;
V_83 -> V_92 = F_36 ( V_34 -> V_105 +
F_45 ( struct V_95 , V_80 ) ) ;
V_83 -> V_93 = F_38 ( V_98 ) ;
V_83 -> V_87 = V_119 | V_89 ;
if ( ! V_97 )
V_83 -> V_87 |= V_94 ;
V_83 ++ ;
}
if ( V_97 )
F_33 ( V_83 , V_54 ) ;
V_34 -> V_120 [ 0 ] = V_34 -> V_105 ;
}
static unsigned int F_46 ( struct V_53 * V_54 )
{
struct V_1 * V_2 = V_54 -> V_2 ;
void T_1 * V_10 = F_1 ( V_2 ) ;
F_5 ( V_121 | V_122 , V_10 + V_123 ) ;
F_5 ( V_124 , V_10 + V_12 ) ;
F_6 ( 0 , V_10 + V_125 ) ;
return 0 ;
}
static void F_47 ( struct V_1 * V_2 , struct V_126 * V_65 )
{
void T_1 * V_10 = F_1 ( V_2 ) ;
V_65 -> V_107 = F_14 ( V_10 + V_127 ) ;
V_65 -> V_108 = F_14 ( V_10 + V_128 ) ;
V_65 -> V_109 = F_14 ( V_10 + V_129 ) ;
V_65 -> V_110 = F_14 ( V_10 + V_130 ) ;
V_65 -> V_111 = F_14 ( V_10 + V_131 ) ;
V_65 -> V_106 = F_14 ( V_10 + V_132 ) ;
V_65 -> V_66 = F_14 ( V_10 + V_61 ) ;
}
static bool F_48 ( struct V_53 * V_54 )
{
struct V_126 * V_133 = & V_54 -> V_134 ;
struct V_126 V_65 ;
F_47 ( V_54 -> V_2 , & V_65 ) ;
if ( ! ( V_65 . V_66 & V_63 ) )
return false ;
V_133 -> V_66 = V_65 . V_66 ;
V_133 -> V_107 = V_65 . V_107 ;
return true ;
}
static void F_49 ( struct V_1 * V_2 )
{
void T_1 * V_10 = F_1 ( V_2 ) ;
F_6 ( V_135 , V_10 + V_136 ) ;
F_6 ( 0xff , V_10 + V_14 ) ;
}
static void F_50 ( struct V_1 * V_2 )
{
void T_1 * V_10 = F_1 ( V_2 ) ;
F_6 ( 0xff , V_10 + V_14 ) ;
F_6 ( V_137 , V_10 + V_136 ) ;
}
static int F_51 ( struct V_15 * V_16 )
{
void T_1 * V_10 = F_1 ( V_16 -> V_2 ) ;
return F_52 ( F_14 ( V_10 + V_61 ) ) ;
}
static int F_53 ( struct V_15 * V_16 , unsigned int * V_138 ,
unsigned long V_139 )
{
struct V_1 * V_2 = V_16 -> V_2 ;
void T_1 * V_10 = F_1 ( V_2 ) ;
void T_1 * V_11 = V_10 + V_12 ;
const unsigned long * V_140 = F_54 ( & V_16 -> V_141 ) ;
int V_142 ;
F_2 ( V_10 ) ;
F_5 ( V_143 , V_11 ) ;
F_3 ( V_11 ) ;
F_55 ( V_2 , 1 ) ;
F_5 ( 0 , V_11 ) ;
V_142 = F_56 ( V_16 , V_140 , V_139 ) ;
if ( V_142 ) {
F_57 ( V_16 , V_64 , L_11
L_12 , V_142 ) ;
return V_142 ;
}
* V_138 = V_144 ;
if ( F_58 ( V_16 ) ) {
struct V_126 V_65 ;
V_142 = F_59 ( V_16 , V_139 , F_51 ) ;
if ( V_142 ) {
F_57 ( V_16 , V_64 , L_13
L_14 , V_142 ) ;
return V_142 ;
}
F_47 ( V_2 , & V_65 ) ;
* V_138 = F_60 ( & V_65 ) ;
}
return 0 ;
}
static void F_61 ( struct V_1 * V_2 )
{
void T_1 * V_10 = F_1 ( V_2 ) ;
F_2 ( V_10 ) ;
F_62 ( V_2 ) ;
}
static void F_63 ( struct V_53 * V_54 )
{
if ( V_54 -> V_87 & V_145 )
F_2 ( F_1 ( V_54 -> V_2 ) ) ;
}
static void F_64 ( struct V_1 * V_2 )
{
void T_1 * V_10 = F_1 ( V_2 ) ;
struct V_33 * V_34 = V_2 -> V_6 ;
memset ( V_34 -> V_37 , 0 , sizeof( struct V_95 ) ) ;
memset ( V_34 -> V_120 , 0 , V_146 ) ;
F_12 ( V_34 -> V_147 , V_10 + V_148 ) ;
}
static int F_65 ( struct V_1 * V_2 )
{
F_64 ( V_2 ) ;
return 0 ;
}
static int F_66 ( struct V_1 * V_2 )
{
struct V_106 * V_99 = V_2 -> V_5 -> V_99 ;
struct V_33 * V_34 ;
V_34 = F_67 ( V_99 , sizeof( * V_34 ) , V_149 ) ;
if ( ! V_34 )
return - V_150 ;
V_2 -> V_6 = V_34 ;
V_34 -> V_37 = F_68 ( V_99 , sizeof( struct V_95 ) ,
& V_34 -> V_105 , V_149 ) ;
if ( ! V_34 -> V_37 )
return - V_150 ;
V_34 -> V_120 = F_68 ( V_99 , V_146 ,
& V_34 -> V_147 , V_149 ) ;
if ( ! V_34 -> V_120 )
return - V_150 ;
F_64 ( V_2 ) ;
return 0 ;
}
static int F_69 ( void T_1 * V_7 , T_4 V_151 )
{
int V_71 ;
T_4 V_18 ;
V_151 &= ~ V_152 ;
F_5 ( V_151 | V_153 , V_7 + V_123 ) ;
F_3 ( V_7 + V_123 ) ;
for ( V_71 = 0 ; V_71 < 10 ; V_71 ++ ) {
F_4 ( 1 ) ;
V_18 = F_3 ( V_7 + V_123 ) ;
if ( ! ( V_18 & V_153 ) )
break;
}
if ( V_18 & V_153 )
return - V_154 ;
for ( V_71 = 0 ; V_71 < V_77 ; V_71 ++ ) {
void T_1 * V_10 = V_7 + V_71 * V_9 ;
F_6 ( 0xff , V_10 + V_136 ) ;
F_2 ( V_10 ) ;
}
F_5 ( V_151 & ~ V_155 , V_7 + V_123 ) ;
V_18 = F_3 ( V_7 + V_156 ) ;
V_18 &= ~ ( V_78 | V_157 ) ;
F_5 ( V_18 , V_7 + V_156 ) ;
return 0 ;
}
static int F_70 ( struct V_158 * V_159 )
{
struct V_69 * V_5 = F_71 ( & V_159 -> V_99 ) ;
struct V_3 * V_4 = V_5 -> V_6 ;
int V_142 ;
V_142 = F_72 ( V_159 ) ;
if ( V_142 )
return V_142 ;
if ( V_159 -> V_99 . V_160 . V_161 . V_162 == V_163 ) {
V_142 = F_69 ( V_4 -> V_7 , V_4 -> V_164 ) ;
if ( V_142 )
return V_142 ;
}
F_73 ( V_5 ) ;
return 0 ;
}
static int F_74 ( struct V_158 * V_159 , const struct V_165 * V_166 )
{
static int V_167 ;
const struct V_168 * V_169 [] = { & V_170 , NULL } ;
struct V_69 * V_5 ;
struct V_3 * V_4 ;
void T_1 * const * V_171 ;
int V_172 ;
int V_71 , V_142 ;
if ( ! V_167 ++ )
F_75 ( V_173 , & V_159 -> V_99 , L_15 V_174 L_16 ) ;
V_5 = F_76 ( & V_159 -> V_99 , V_169 , V_77 ) ;
V_4 = F_67 ( & V_159 -> V_99 , sizeof( * V_4 ) , V_149 ) ;
if ( ! V_5 || ! V_4 )
return - V_150 ;
V_5 -> V_6 = V_4 ;
V_142 = F_77 ( V_159 ) ;
if ( V_142 )
return V_142 ;
if ( F_78 ( V_159 , V_175 ) & V_176 )
V_172 = V_175 ;
else
V_172 = V_177 ;
V_142 = F_79 ( V_159 , 1 << V_172 , V_178 ) ;
if ( V_142 )
return V_142 ;
V_5 -> V_171 = V_171 = F_80 ( V_159 ) ;
V_4 -> V_7 = V_171 [ V_172 ] ;
V_4 -> V_164 = F_3 ( V_4 -> V_7 + V_123 ) ;
for ( V_71 = 0 ; V_71 < V_77 ; V_71 ++ ) {
struct V_1 * V_2 = V_5 -> V_79 [ V_71 ] ;
F_81 ( V_2 , V_172 , - 1 , L_17 ) ;
F_81 ( V_2 , V_172 , V_71 * V_9 , L_18 ) ;
}
V_142 = F_82 ( V_159 , F_83 ( 32 ) ) ;
if ( V_142 ) {
F_75 ( V_179 , & V_159 -> V_99 ,
L_19 ) ;
return V_142 ;
}
V_142 = F_84 ( V_159 , F_83 ( 32 ) ) ;
if ( V_142 ) {
F_75 ( V_179 , & V_159 -> V_99 ,
L_20 ) ;
return V_142 ;
}
V_142 = F_85 ( V_159 , 65536 - 512 ) ;
if ( V_142 ) {
F_75 ( V_179 , & V_159 -> V_99 ,
L_21 ) ;
return V_142 ;
}
V_142 = F_69 ( V_4 -> V_7 , V_4 -> V_164 ) ;
if ( V_142 ) {
F_75 ( V_179 , & V_159 -> V_99 ,
L_22 ) ;
return V_142 ;
}
F_86 ( V_159 ) ;
return F_87 ( V_5 , V_159 -> V_67 , F_27 , V_180 ,
& V_181 ) ;
}
static int T_6 F_88 ( void )
{
return F_89 ( & V_182 ) ;
}
static void T_7 F_90 ( void )
{
F_91 ( & V_182 ) ;
}
