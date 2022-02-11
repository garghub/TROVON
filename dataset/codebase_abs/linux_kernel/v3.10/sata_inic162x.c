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
if ( F_8 ( V_17 >= F_9 ( V_21 ) ) )
return - V_22 ;
* V_18 = F_10 ( V_19 + V_21 [ V_17 ] * 4 ) ;
if ( V_17 == V_23 )
* V_18 &= ~ V_24 ;
return 0 ;
}
static int F_11 ( struct V_15 * V_16 , unsigned V_17 , T_2 V_18 )
{
void T_1 * V_19 = F_1 ( V_16 -> V_2 ) + V_20 ;
if ( F_8 ( V_17 >= F_9 ( V_21 ) ) )
return - V_22 ;
F_12 ( V_18 , V_19 + V_21 [ V_17 ] * 4 ) ;
return 0 ;
}
static void F_13 ( struct V_1 * V_2 )
{
void T_1 * V_10 = F_1 ( V_2 ) ;
F_14 ( V_10 + V_25 ) ;
F_14 ( V_10 + V_26 ) ;
F_5 ( 0 , V_10 + V_12 ) ;
}
static void F_15 ( struct V_1 * V_2 , T_3 V_27 , T_4 V_28 )
{
struct V_29 * V_30 = & V_2 -> V_16 . V_31 ;
struct V_32 * V_33 = V_2 -> V_6 ;
struct V_34 * V_35 = & V_33 -> V_36 -> V_35 ;
bool V_37 = false ;
F_16 ( V_30 ) ;
F_17 ( V_30 , L_1 ,
V_27 , V_28 ) ;
F_13 ( V_2 ) ;
if ( V_27 & ( V_38 | V_39 ) ) {
F_17 ( V_30 , L_2 ) ;
F_18 ( V_30 ) ;
V_37 = true ;
}
if ( V_28 & V_40 ) {
F_17 ( V_30 , L_3 ) ;
V_37 = true ;
}
if ( V_28 & V_41 ) {
F_17 ( V_30 , L_4 ) ;
if ( V_35 -> V_42 & V_43 ) {
F_19 ( V_30 , L_5 ) ;
V_30 -> V_44 |= V_45 ;
V_37 = true ;
}
if ( V_35 -> V_42 & V_46 )
V_30 -> V_44 |= V_47 ;
if ( V_35 -> V_42 & V_48 ) {
F_19 ( V_30 , L_6 ) ;
V_30 -> V_44 |= V_49 ;
V_37 = true ;
}
if ( V_35 -> V_42 &
( V_50 | V_51 ) ) {
F_19 ( V_30 , L_7 ) ;
V_30 -> V_44 |= V_49 ;
V_37 = true ;
}
}
if ( V_37 )
F_20 ( V_2 ) ;
else
F_21 ( V_2 ) ;
}
static void F_22 ( struct V_1 * V_2 )
{
void T_1 * V_10 = F_1 ( V_2 ) ;
struct V_52 * V_53 = F_23 ( V_2 , V_2 -> V_16 . V_54 ) ;
T_3 V_27 ;
T_4 V_28 ;
V_27 = F_14 ( V_10 + V_14 ) ;
F_6 ( V_27 , V_10 + V_14 ) ;
V_28 = F_3 ( V_10 + V_55 ) ;
if ( F_8 ( ( V_27 & V_56 ) || ( V_28 & V_57 ) ) )
F_15 ( V_2 , V_27 , V_28 ) ;
if ( F_8 ( ! V_53 ) )
goto V_58;
if ( F_24 ( V_28 & V_59 ) ) {
F_13 ( V_2 ) ;
if ( F_8 ( F_14 ( V_10 + V_60 ) &
( V_61 | V_62 ) ) )
V_53 -> V_44 |= V_47 ;
F_25 ( V_53 ) ;
return;
}
V_58:
F_26 ( V_2 , L_8 ,
V_53 ? V_53 -> V_63 . V_64 : 0xff , V_27 , V_28 ) ;
}
static T_5 F_27 ( int V_65 , void * V_66 )
{
struct V_67 * V_5 = V_66 ;
struct V_3 * V_4 = V_5 -> V_6 ;
T_4 V_68 ;
int V_69 , V_70 = 0 ;
V_68 = F_3 ( V_4 -> V_7 + V_71 ) ;
if ( F_8 ( ! ( V_68 & V_72 ) ) )
goto V_73;
F_28 ( & V_5 -> V_74 ) ;
for ( V_69 = 0 ; V_69 < V_75 ; V_69 ++ )
if ( V_68 & ( V_76 << V_69 ) ) {
F_22 ( V_5 -> V_77 [ V_69 ] ) ;
V_70 ++ ;
}
F_29 ( & V_5 -> V_74 ) ;
V_73:
return F_30 ( V_70 ) ;
}
static int F_31 ( struct V_52 * V_53 )
{
if ( F_32 ( V_53 -> V_78 [ 0 ] ) == V_79 )
return 0 ;
return 1 ;
}
static void F_33 ( struct V_80 * V_81 , struct V_52 * V_53 )
{
struct V_82 * V_83 ;
unsigned int V_84 ;
T_3 V_85 = 0 ;
if ( V_53 -> V_63 . V_85 & V_86 )
V_85 |= V_87 ;
if ( F_34 ( V_53 -> V_63 . V_88 ) )
V_85 |= V_89 ;
F_35 (qc->sg, sg, qc->n_elem, si) {
V_81 -> V_90 = F_36 ( F_37 ( V_83 ) ) ;
V_81 -> V_91 = F_38 ( F_39 ( V_83 ) ) ;
V_81 -> V_85 = V_85 ;
V_81 ++ ;
}
F_40 ( ! V_84 ) ;
V_81 [ - 1 ] . V_85 |= V_92 ;
}
static void F_41 ( struct V_52 * V_53 )
{
struct V_32 * V_33 = V_53 -> V_2 -> V_6 ;
struct V_93 * V_36 = V_33 -> V_36 ;
struct V_34 * V_35 = & V_36 -> V_35 ;
struct V_80 * V_81 = V_36 -> V_81 ;
bool V_94 = F_42 ( V_53 -> V_63 . V_88 ) ;
bool V_95 = F_43 ( V_53 -> V_63 . V_88 ) ;
unsigned int V_96 = 0 ;
F_44 ( L_9 ) ;
if ( V_94 )
V_96 = V_53 -> V_97 -> V_96 ;
memset ( V_36 , 0 , sizeof( struct V_93 ) ) ;
V_35 -> V_98 = V_99 | V_100 ;
if ( V_94 || V_95 )
V_35 -> V_98 |= V_101 ;
V_35 -> V_91 = F_36 ( V_53 -> V_102 + V_96 ) ;
V_35 -> V_81 = F_36 ( V_33 -> V_103 + F_45 ( struct V_93 , V_81 ) ) ;
V_35 -> V_104 = V_53 -> V_63 . V_104 ;
V_35 -> V_105 = V_53 -> V_63 . V_105 ;
V_35 -> V_106 = V_53 -> V_63 . V_106 ;
V_35 -> V_107 = V_53 -> V_63 . V_107 ;
V_35 -> V_108 = V_53 -> V_63 . V_108 ;
V_35 -> V_109 = V_53 -> V_63 . V_109 ;
if ( V_53 -> V_63 . V_85 & V_110 ) {
V_35 -> V_111 = V_53 -> V_63 . V_111 ;
V_35 -> V_112 = V_53 -> V_63 . V_112 ;
V_35 -> V_113 = V_53 -> V_63 . V_113 ;
V_35 -> V_114 = V_53 -> V_63 . V_114 ;
V_35 -> V_115 = V_53 -> V_63 . V_115 ;
}
V_35 -> V_64 = V_53 -> V_63 . V_64 ;
if ( V_94 ) {
memcpy ( V_36 -> V_78 , V_53 -> V_78 , V_116 ) ;
V_81 -> V_90 = F_36 ( V_33 -> V_103 +
F_45 ( struct V_93 , V_78 ) ) ;
V_81 -> V_91 = F_38 ( V_96 ) ;
V_81 -> V_85 = V_117 | V_87 ;
if ( ! V_95 )
V_81 -> V_85 |= V_92 ;
V_81 ++ ;
}
if ( V_95 )
F_33 ( V_81 , V_53 ) ;
V_33 -> V_118 [ 0 ] = V_33 -> V_103 ;
}
static unsigned int F_46 ( struct V_52 * V_53 )
{
struct V_1 * V_2 = V_53 -> V_2 ;
void T_1 * V_10 = F_1 ( V_2 ) ;
F_5 ( V_119 | V_120 , V_10 + V_121 ) ;
F_5 ( V_122 , V_10 + V_12 ) ;
F_6 ( 0 , V_10 + V_123 ) ;
return 0 ;
}
static void F_47 ( struct V_1 * V_2 , struct V_124 * V_63 )
{
void T_1 * V_10 = F_1 ( V_2 ) ;
V_63 -> V_105 = F_14 ( V_10 + V_125 ) ;
V_63 -> V_106 = F_14 ( V_10 + V_126 ) ;
V_63 -> V_107 = F_14 ( V_10 + V_127 ) ;
V_63 -> V_108 = F_14 ( V_10 + V_128 ) ;
V_63 -> V_109 = F_14 ( V_10 + V_129 ) ;
V_63 -> V_104 = F_14 ( V_10 + V_130 ) ;
V_63 -> V_64 = F_14 ( V_10 + V_60 ) ;
}
static bool F_48 ( struct V_52 * V_53 )
{
struct V_124 * V_131 = & V_53 -> V_132 ;
struct V_124 V_63 ;
F_47 ( V_53 -> V_2 , & V_63 ) ;
if ( ! ( V_63 . V_64 & V_62 ) )
return false ;
V_131 -> V_64 = V_63 . V_64 ;
V_131 -> V_105 = V_63 . V_105 ;
return true ;
}
static void F_49 ( struct V_1 * V_2 )
{
void T_1 * V_10 = F_1 ( V_2 ) ;
F_6 ( V_133 , V_10 + V_134 ) ;
F_6 ( 0xff , V_10 + V_14 ) ;
}
static void F_50 ( struct V_1 * V_2 )
{
void T_1 * V_10 = F_1 ( V_2 ) ;
F_6 ( 0xff , V_10 + V_14 ) ;
F_6 ( V_135 , V_10 + V_134 ) ;
}
static int F_51 ( struct V_15 * V_16 )
{
void T_1 * V_10 = F_1 ( V_16 -> V_2 ) ;
return F_52 ( F_14 ( V_10 + V_60 ) ) ;
}
static int F_53 ( struct V_15 * V_16 , unsigned int * V_136 ,
unsigned long V_137 )
{
struct V_1 * V_2 = V_16 -> V_2 ;
void T_1 * V_10 = F_1 ( V_2 ) ;
void T_1 * V_11 = V_10 + V_12 ;
const unsigned long * V_138 = F_54 ( & V_16 -> V_139 ) ;
int V_140 ;
F_2 ( V_10 ) ;
F_5 ( V_141 , V_11 ) ;
F_3 ( V_11 ) ;
F_55 ( V_2 , 1 ) ;
F_5 ( 0 , V_11 ) ;
V_140 = F_56 ( V_16 , V_138 , V_137 ) ;
if ( V_140 ) {
F_57 ( V_16 ,
L_10 ,
V_140 ) ;
return V_140 ;
}
* V_136 = V_142 ;
if ( F_58 ( V_16 ) ) {
struct V_124 V_63 ;
V_140 = F_59 ( V_16 , V_137 , F_51 ) ;
if ( V_140 ) {
F_57 ( V_16 ,
L_11 ,
V_140 ) ;
return V_140 ;
}
F_47 ( V_2 , & V_63 ) ;
* V_136 = F_60 ( & V_63 ) ;
}
return 0 ;
}
static void F_61 ( struct V_1 * V_2 )
{
void T_1 * V_10 = F_1 ( V_2 ) ;
F_2 ( V_10 ) ;
F_62 ( V_2 ) ;
}
static void F_63 ( struct V_52 * V_53 )
{
if ( V_53 -> V_85 & V_143 )
F_2 ( F_1 ( V_53 -> V_2 ) ) ;
}
static void F_64 ( struct V_1 * V_2 )
{
void T_1 * V_10 = F_1 ( V_2 ) ;
struct V_32 * V_33 = V_2 -> V_6 ;
memset ( V_33 -> V_36 , 0 , sizeof( struct V_93 ) ) ;
memset ( V_33 -> V_118 , 0 , V_144 ) ;
F_12 ( V_33 -> V_145 , V_10 + V_146 ) ;
}
static int F_65 ( struct V_1 * V_2 )
{
F_64 ( V_2 ) ;
return 0 ;
}
static int F_66 ( struct V_1 * V_2 )
{
struct V_104 * V_97 = V_2 -> V_5 -> V_97 ;
struct V_32 * V_33 ;
V_33 = F_67 ( V_97 , sizeof( * V_33 ) , V_147 ) ;
if ( ! V_33 )
return - V_148 ;
V_2 -> V_6 = V_33 ;
V_33 -> V_36 = F_68 ( V_97 , sizeof( struct V_93 ) ,
& V_33 -> V_103 , V_147 ) ;
if ( ! V_33 -> V_36 )
return - V_148 ;
V_33 -> V_118 = F_68 ( V_97 , V_144 ,
& V_33 -> V_145 , V_147 ) ;
if ( ! V_33 -> V_118 )
return - V_148 ;
F_64 ( V_2 ) ;
return 0 ;
}
static int F_69 ( void T_1 * V_7 , T_4 V_149 )
{
int V_69 ;
T_4 V_18 ;
V_149 &= ~ V_150 ;
F_5 ( V_149 | V_151 , V_7 + V_121 ) ;
F_3 ( V_7 + V_121 ) ;
for ( V_69 = 0 ; V_69 < 10 ; V_69 ++ ) {
F_4 ( 1 ) ;
V_18 = F_3 ( V_7 + V_121 ) ;
if ( ! ( V_18 & V_151 ) )
break;
}
if ( V_18 & V_151 )
return - V_152 ;
for ( V_69 = 0 ; V_69 < V_75 ; V_69 ++ ) {
void T_1 * V_10 = V_7 + V_69 * V_9 ;
F_6 ( 0xff , V_10 + V_134 ) ;
F_2 ( V_10 ) ;
}
F_5 ( V_149 & ~ V_153 , V_7 + V_121 ) ;
V_18 = F_3 ( V_7 + V_154 ) ;
V_18 &= ~ ( V_76 | V_155 ) ;
F_5 ( V_18 , V_7 + V_154 ) ;
return 0 ;
}
static int F_70 ( struct V_156 * V_157 )
{
struct V_67 * V_5 = F_71 ( & V_157 -> V_97 ) ;
struct V_3 * V_4 = V_5 -> V_6 ;
int V_140 ;
V_140 = F_72 ( V_157 ) ;
if ( V_140 )
return V_140 ;
if ( V_157 -> V_97 . V_158 . V_159 . V_160 == V_161 ) {
V_140 = F_69 ( V_4 -> V_7 , V_4 -> V_162 ) ;
if ( V_140 )
return V_140 ;
}
F_73 ( V_5 ) ;
return 0 ;
}
static int F_74 ( struct V_156 * V_157 , const struct V_163 * V_164 )
{
const struct V_165 * V_166 [] = { & V_167 , NULL } ;
struct V_67 * V_5 ;
struct V_3 * V_4 ;
void T_1 * const * V_168 ;
int V_169 ;
int V_69 , V_140 ;
F_75 ( & V_157 -> V_97 , V_170 ) ;
V_5 = F_76 ( & V_157 -> V_97 , V_166 , V_75 ) ;
V_4 = F_67 ( & V_157 -> V_97 , sizeof( * V_4 ) , V_147 ) ;
if ( ! V_5 || ! V_4 )
return - V_148 ;
V_5 -> V_6 = V_4 ;
V_140 = F_77 ( V_157 ) ;
if ( V_140 )
return V_140 ;
if ( F_78 ( V_157 , V_171 ) & V_172 )
V_169 = V_171 ;
else
V_169 = V_173 ;
V_140 = F_79 ( V_157 , 1 << V_169 , V_174 ) ;
if ( V_140 )
return V_140 ;
V_5 -> V_168 = V_168 = F_80 ( V_157 ) ;
V_4 -> V_7 = V_168 [ V_169 ] ;
V_4 -> V_162 = F_3 ( V_4 -> V_7 + V_121 ) ;
for ( V_69 = 0 ; V_69 < V_75 ; V_69 ++ ) {
struct V_1 * V_2 = V_5 -> V_77 [ V_69 ] ;
F_81 ( V_2 , V_169 , - 1 , L_12 ) ;
F_81 ( V_2 , V_169 , V_69 * V_9 , L_13 ) ;
}
V_140 = F_82 ( V_157 , F_83 ( 32 ) ) ;
if ( V_140 ) {
F_84 ( & V_157 -> V_97 , L_14 ) ;
return V_140 ;
}
V_140 = F_85 ( V_157 , F_83 ( 32 ) ) ;
if ( V_140 ) {
F_84 ( & V_157 -> V_97 , L_15 ) ;
return V_140 ;
}
V_140 = F_86 ( V_157 , 65536 - 512 ) ;
if ( V_140 ) {
F_84 ( & V_157 -> V_97 , L_16 ) ;
return V_140 ;
}
V_140 = F_69 ( V_4 -> V_7 , V_4 -> V_162 ) ;
if ( V_140 ) {
F_84 ( & V_157 -> V_97 , L_17 ) ;
return V_140 ;
}
F_87 ( V_157 ) ;
return F_88 ( V_5 , V_157 -> V_65 , F_27 , V_175 ,
& V_176 ) ;
}
