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
F_26 ( V_2 , L_8 ,
V_54 ? V_54 -> V_64 . V_65 : 0xff , V_28 , V_29 ) ;
}
static T_5 F_27 ( int V_66 , void * V_67 )
{
struct V_68 * V_5 = V_67 ;
struct V_3 * V_4 = V_5 -> V_6 ;
T_4 V_69 ;
int V_70 , V_71 = 0 ;
V_69 = F_3 ( V_4 -> V_7 + V_72 ) ;
if ( F_8 ( ! ( V_69 & V_73 ) ) )
goto V_74;
F_28 ( & V_5 -> V_75 ) ;
for ( V_70 = 0 ; V_70 < V_76 ; V_70 ++ )
if ( V_69 & ( V_77 << V_70 ) ) {
F_22 ( V_5 -> V_78 [ V_70 ] ) ;
V_71 ++ ;
}
F_29 ( & V_5 -> V_75 ) ;
V_74:
return F_30 ( V_71 ) ;
}
static int F_31 ( struct V_53 * V_54 )
{
if ( F_32 ( V_54 -> V_79 [ 0 ] ) == V_80 )
return 0 ;
return 1 ;
}
static void F_33 ( struct V_81 * V_82 , struct V_53 * V_54 )
{
struct V_83 * V_84 ;
unsigned int V_85 ;
T_3 V_86 = 0 ;
if ( V_54 -> V_64 . V_86 & V_87 )
V_86 |= V_88 ;
if ( F_34 ( V_54 -> V_64 . V_89 ) )
V_86 |= V_90 ;
F_35 (qc->sg, sg, qc->n_elem, si) {
V_82 -> V_91 = F_36 ( F_37 ( V_84 ) ) ;
V_82 -> V_92 = F_38 ( F_39 ( V_84 ) ) ;
V_82 -> V_86 = V_86 ;
V_82 ++ ;
}
F_40 ( ! V_85 ) ;
V_82 [ - 1 ] . V_86 |= V_93 ;
}
static void F_41 ( struct V_53 * V_54 )
{
struct V_33 * V_34 = V_54 -> V_2 -> V_6 ;
struct V_94 * V_37 = V_34 -> V_37 ;
struct V_35 * V_36 = & V_37 -> V_36 ;
struct V_81 * V_82 = V_37 -> V_82 ;
bool V_95 = F_42 ( V_54 -> V_64 . V_89 ) ;
bool V_96 = F_43 ( V_54 -> V_64 . V_89 ) ;
unsigned int V_97 = 0 ;
F_44 ( L_9 ) ;
if ( V_95 )
V_97 = V_54 -> V_98 -> V_97 ;
memset ( V_37 , 0 , sizeof( struct V_94 ) ) ;
V_36 -> V_99 = V_100 | V_101 ;
if ( V_95 || V_96 )
V_36 -> V_99 |= V_102 ;
V_36 -> V_92 = F_36 ( V_54 -> V_103 + V_97 ) ;
V_36 -> V_82 = F_36 ( V_34 -> V_104 + F_45 ( struct V_94 , V_82 ) ) ;
V_36 -> V_105 = V_54 -> V_64 . V_105 ;
V_36 -> V_106 = V_54 -> V_64 . V_106 ;
V_36 -> V_107 = V_54 -> V_64 . V_107 ;
V_36 -> V_108 = V_54 -> V_64 . V_108 ;
V_36 -> V_109 = V_54 -> V_64 . V_109 ;
V_36 -> V_110 = V_54 -> V_64 . V_110 ;
if ( V_54 -> V_64 . V_86 & V_111 ) {
V_36 -> V_112 = V_54 -> V_64 . V_112 ;
V_36 -> V_113 = V_54 -> V_64 . V_113 ;
V_36 -> V_114 = V_54 -> V_64 . V_114 ;
V_36 -> V_115 = V_54 -> V_64 . V_115 ;
V_36 -> V_116 = V_54 -> V_64 . V_116 ;
}
V_36 -> V_65 = V_54 -> V_64 . V_65 ;
if ( V_95 ) {
memcpy ( V_37 -> V_79 , V_54 -> V_79 , V_117 ) ;
V_82 -> V_91 = F_36 ( V_34 -> V_104 +
F_45 ( struct V_94 , V_79 ) ) ;
V_82 -> V_92 = F_38 ( V_97 ) ;
V_82 -> V_86 = V_118 | V_88 ;
if ( ! V_96 )
V_82 -> V_86 |= V_93 ;
V_82 ++ ;
}
if ( V_96 )
F_33 ( V_82 , V_54 ) ;
V_34 -> V_119 [ 0 ] = V_34 -> V_104 ;
}
static unsigned int F_46 ( struct V_53 * V_54 )
{
struct V_1 * V_2 = V_54 -> V_2 ;
void T_1 * V_10 = F_1 ( V_2 ) ;
F_5 ( V_120 | V_121 , V_10 + V_122 ) ;
F_5 ( V_123 , V_10 + V_12 ) ;
F_6 ( 0 , V_10 + V_124 ) ;
return 0 ;
}
static void F_47 ( struct V_1 * V_2 , struct V_125 * V_64 )
{
void T_1 * V_10 = F_1 ( V_2 ) ;
V_64 -> V_106 = F_14 ( V_10 + V_126 ) ;
V_64 -> V_107 = F_14 ( V_10 + V_127 ) ;
V_64 -> V_108 = F_14 ( V_10 + V_128 ) ;
V_64 -> V_109 = F_14 ( V_10 + V_129 ) ;
V_64 -> V_110 = F_14 ( V_10 + V_130 ) ;
V_64 -> V_105 = F_14 ( V_10 + V_131 ) ;
V_64 -> V_65 = F_14 ( V_10 + V_61 ) ;
}
static bool F_48 ( struct V_53 * V_54 )
{
struct V_125 * V_132 = & V_54 -> V_133 ;
struct V_125 V_64 ;
F_47 ( V_54 -> V_2 , & V_64 ) ;
if ( ! ( V_64 . V_65 & V_63 ) )
return false ;
V_132 -> V_65 = V_64 . V_65 ;
V_132 -> V_106 = V_64 . V_106 ;
return true ;
}
static void F_49 ( struct V_1 * V_2 )
{
void T_1 * V_10 = F_1 ( V_2 ) ;
F_6 ( V_134 , V_10 + V_135 ) ;
F_6 ( 0xff , V_10 + V_14 ) ;
}
static void F_50 ( struct V_1 * V_2 )
{
void T_1 * V_10 = F_1 ( V_2 ) ;
F_6 ( 0xff , V_10 + V_14 ) ;
F_6 ( V_136 , V_10 + V_135 ) ;
}
static int F_51 ( struct V_15 * V_16 )
{
void T_1 * V_10 = F_1 ( V_16 -> V_2 ) ;
return F_52 ( F_14 ( V_10 + V_61 ) ) ;
}
static int F_53 ( struct V_15 * V_16 , unsigned int * V_137 ,
unsigned long V_138 )
{
struct V_1 * V_2 = V_16 -> V_2 ;
void T_1 * V_10 = F_1 ( V_2 ) ;
void T_1 * V_11 = V_10 + V_12 ;
const unsigned long * V_139 = F_54 ( & V_16 -> V_140 ) ;
int V_141 ;
F_2 ( V_10 ) ;
F_5 ( V_142 , V_11 ) ;
F_3 ( V_11 ) ;
F_55 ( V_2 , 1 ) ;
F_5 ( 0 , V_11 ) ;
V_141 = F_56 ( V_16 , V_139 , V_138 ) ;
if ( V_141 ) {
F_57 ( V_16 ,
L_10 ,
V_141 ) ;
return V_141 ;
}
* V_137 = V_143 ;
if ( F_58 ( V_16 ) ) {
struct V_125 V_64 ;
V_141 = F_59 ( V_16 , V_138 , F_51 ) ;
if ( V_141 ) {
F_57 ( V_16 ,
L_11 ,
V_141 ) ;
return V_141 ;
}
F_47 ( V_2 , & V_64 ) ;
* V_137 = F_60 ( & V_64 ) ;
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
if ( V_54 -> V_86 & V_144 )
F_2 ( F_1 ( V_54 -> V_2 ) ) ;
}
static void F_64 ( struct V_1 * V_2 )
{
void T_1 * V_10 = F_1 ( V_2 ) ;
struct V_33 * V_34 = V_2 -> V_6 ;
memset ( V_34 -> V_37 , 0 , sizeof( struct V_94 ) ) ;
memset ( V_34 -> V_119 , 0 , V_145 ) ;
F_12 ( V_34 -> V_146 , V_10 + V_147 ) ;
}
static int F_65 ( struct V_1 * V_2 )
{
F_64 ( V_2 ) ;
return 0 ;
}
static int F_66 ( struct V_1 * V_2 )
{
struct V_105 * V_98 = V_2 -> V_5 -> V_98 ;
struct V_33 * V_34 ;
V_34 = F_67 ( V_98 , sizeof( * V_34 ) , V_148 ) ;
if ( ! V_34 )
return - V_149 ;
V_2 -> V_6 = V_34 ;
V_34 -> V_37 = F_68 ( V_98 , sizeof( struct V_94 ) ,
& V_34 -> V_104 , V_148 ) ;
if ( ! V_34 -> V_37 )
return - V_149 ;
V_34 -> V_119 = F_68 ( V_98 , V_145 ,
& V_34 -> V_146 , V_148 ) ;
if ( ! V_34 -> V_119 )
return - V_149 ;
F_64 ( V_2 ) ;
return 0 ;
}
static int F_69 ( void T_1 * V_7 , T_4 V_150 )
{
int V_70 ;
T_4 V_18 ;
V_150 &= ~ V_151 ;
F_5 ( V_150 | V_152 , V_7 + V_122 ) ;
F_3 ( V_7 + V_122 ) ;
for ( V_70 = 0 ; V_70 < 10 ; V_70 ++ ) {
F_4 ( 1 ) ;
V_18 = F_3 ( V_7 + V_122 ) ;
if ( ! ( V_18 & V_152 ) )
break;
}
if ( V_18 & V_152 )
return - V_153 ;
for ( V_70 = 0 ; V_70 < V_76 ; V_70 ++ ) {
void T_1 * V_10 = V_7 + V_70 * V_9 ;
F_6 ( 0xff , V_10 + V_135 ) ;
F_2 ( V_10 ) ;
}
F_5 ( V_150 & ~ V_154 , V_7 + V_122 ) ;
V_18 = F_3 ( V_7 + V_155 ) ;
V_18 &= ~ ( V_77 | V_156 ) ;
F_5 ( V_18 , V_7 + V_155 ) ;
return 0 ;
}
static int F_70 ( struct V_157 * V_158 )
{
struct V_68 * V_5 = F_71 ( & V_158 -> V_98 ) ;
struct V_3 * V_4 = V_5 -> V_6 ;
int V_141 ;
V_141 = F_72 ( V_158 ) ;
if ( V_141 )
return V_141 ;
if ( V_158 -> V_98 . V_159 . V_160 . V_161 == V_162 ) {
V_141 = F_69 ( V_4 -> V_7 , V_4 -> V_163 ) ;
if ( V_141 )
return V_141 ;
}
F_73 ( V_5 ) ;
return 0 ;
}
static int F_74 ( struct V_157 * V_158 , const struct V_164 * V_165 )
{
const struct V_166 * V_167 [] = { & V_168 , NULL } ;
struct V_68 * V_5 ;
struct V_3 * V_4 ;
void T_1 * const * V_169 ;
int V_170 ;
int V_70 , V_141 ;
F_75 ( & V_158 -> V_98 , V_171 ) ;
V_5 = F_76 ( & V_158 -> V_98 , V_167 , V_76 ) ;
V_4 = F_67 ( & V_158 -> V_98 , sizeof( * V_4 ) , V_148 ) ;
if ( ! V_5 || ! V_4 )
return - V_149 ;
V_5 -> V_6 = V_4 ;
V_141 = F_77 ( V_158 ) ;
if ( V_141 )
return V_141 ;
if ( F_78 ( V_158 , V_172 ) & V_173 )
V_170 = V_172 ;
else
V_170 = V_174 ;
V_141 = F_79 ( V_158 , 1 << V_170 , V_175 ) ;
if ( V_141 )
return V_141 ;
V_5 -> V_169 = V_169 = F_80 ( V_158 ) ;
V_4 -> V_7 = V_169 [ V_170 ] ;
V_4 -> V_163 = F_3 ( V_4 -> V_7 + V_122 ) ;
for ( V_70 = 0 ; V_70 < V_76 ; V_70 ++ ) {
struct V_1 * V_2 = V_5 -> V_78 [ V_70 ] ;
F_81 ( V_2 , V_170 , - 1 , L_12 ) ;
F_81 ( V_2 , V_170 , V_70 * V_9 , L_13 ) ;
}
V_141 = F_82 ( V_158 , F_83 ( 32 ) ) ;
if ( V_141 ) {
F_84 ( & V_158 -> V_98 , L_14 ) ;
return V_141 ;
}
V_141 = F_85 ( V_158 , F_83 ( 32 ) ) ;
if ( V_141 ) {
F_84 ( & V_158 -> V_98 , L_15 ) ;
return V_141 ;
}
V_141 = F_86 ( V_158 , 65536 - 512 ) ;
if ( V_141 ) {
F_84 ( & V_158 -> V_98 , L_16 ) ;
return V_141 ;
}
V_141 = F_69 ( V_4 -> V_7 , V_4 -> V_163 ) ;
if ( V_141 ) {
F_84 ( & V_158 -> V_98 , L_17 ) ;
return V_141 ;
}
F_87 ( V_158 ) ;
return F_88 ( V_5 , V_158 -> V_66 , F_27 , V_176 ,
& V_177 ) ;
}
static int T_6 F_89 ( void )
{
return F_90 ( & V_178 ) ;
}
static void T_7 F_91 ( void )
{
F_92 ( & V_178 ) ;
}
