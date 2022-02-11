static struct V_1 * F_1 ( struct V_2 * V_3 )
{
return F_2 ( V_3 , struct V_1 , V_4 ) ;
}
static void F_3 ( void * V_5 )
{
struct V_6 * V_7 = V_5 ;
F_4 ( V_8 | V_9 , V_7 -> V_10 + V_11 ) ;
F_4 ( V_12 , V_7 -> V_10 + V_13 ) ;
F_5 () ;
}
static void F_6 ( unsigned long V_14 , T_1 V_15 ,
T_1 V_16 , bool V_17 ,
void * V_5 )
{
struct V_6 * V_7 = V_5 ;
F_4 ( V_8 | V_9 , V_7 -> V_10 + V_11 ) ;
F_4 ( V_14 , V_7 -> V_10 + V_18 ) ;
F_4 ( V_14 + V_15 - 1 , V_7 -> V_10 + V_19 ) ;
F_4 ( V_20 , V_7 -> V_10 + V_13 ) ;
}
static void F_7 ( void * V_5 )
{
struct V_6 * V_7 = V_5 ;
int V_21 ;
T_2 V_22 ;
V_21 = F_8 ( V_7 -> V_10 + V_23 , V_22 ,
V_22 != 0 , 10 , 100000 ) ;
if ( V_21 ) {
F_9 ( V_7 -> V_24 ,
L_1 ) ;
F_3 ( V_5 ) ;
}
F_4 ( 0 , V_7 -> V_10 + V_23 ) ;
}
static T_3 F_10 ( int V_25 , void * V_26 )
{
struct V_6 * V_7 = V_26 ;
struct V_1 * V_3 = V_7 -> V_27 ;
T_2 V_28 , V_29 , V_30 , V_31 ;
unsigned int V_32 , V_33 ;
bool V_34 , V_35 ;
V_28 = F_11 ( V_7 -> V_10 + V_36 ) ;
V_30 = F_11 ( V_7 -> V_10 + V_37 ) ;
V_34 = V_30 & V_38 ;
V_35 = V_30 & V_39 ;
V_30 &= V_40 ;
V_31 = F_11 ( V_7 -> V_10 + V_41 ) ;
V_29 = F_11 ( V_7 -> V_10 + V_42 ) ;
V_32 = F_12 ( V_29 ) ;
V_33 = F_13 ( V_29 ) ;
if ( F_14 ( & V_3 -> V_4 , V_7 -> V_24 , V_30 ,
V_35 ? V_43 : V_44 ) ) {
F_15 (
V_7 -> V_24 ,
L_2 ,
V_28 , V_30 , V_31 , V_32 , V_33 ,
V_34 , V_35 ? L_3 : L_4 ) ;
}
V_29 = F_11 ( V_7 -> V_10 + V_45 ) ;
V_29 |= V_46 ;
F_4 ( V_29 , V_7 -> V_10 + V_45 ) ;
F_3 ( V_7 ) ;
return V_47 ;
}
static void F_16 ( struct V_6 * V_7 ,
struct V_48 * V_24 , bool V_49 )
{
struct V_50 * V_51 ;
unsigned int V_52 , V_53 ;
struct V_54 * V_55 = V_24 -> V_54 ;
int V_56 ;
for ( V_56 = 0 ; V_56 < V_55 -> V_57 ; ++ V_56 ) {
V_52 = F_17 ( V_55 -> V_58 [ V_56 ] ) ;
V_53 = F_18 ( V_55 -> V_58 [ V_56 ] ) ;
V_51 = & V_7 -> V_59 . V_60 [ V_52 ] ;
F_19 ( V_24 , L_5 ,
V_49 ? L_6 : L_7 , V_53 ) ;
if ( V_49 )
V_51 -> V_61 |= F_20 ( V_53 ) ;
else
V_51 -> V_61 &= ~ F_20 ( V_53 ) ;
}
}
static int F_21 ( struct V_6 * V_7 )
{
struct V_1 * V_3 = V_7 -> V_27 ;
F_22 ( & V_3 -> V_62 ) ;
V_3 -> V_63 = (struct V_64 ) {
. V_65 = V_66 |
V_67 |
V_68 ,
. V_69 = V_70 . V_69 ,
. V_71 = 32 ,
. V_72 = 32 ,
. V_73 = & V_74 ,
. V_75 = V_7 -> V_24 ,
} ;
if ( V_7 -> V_76 )
V_3 -> V_63 . V_65 |= V_77 ;
V_3 -> V_78 = F_23 ( V_79 , & V_3 -> V_63 , V_7 ) ;
if ( ! V_3 -> V_78 ) {
F_24 ( V_7 -> V_24 , L_8 ) ;
return - V_80 ;
}
V_3 -> V_4 . V_69 = V_3 -> V_63 . V_69 ;
F_25 ( V_7 -> V_27 -> V_63 . V_81 . V_82 [ 0 ] ,
V_7 -> V_10 + V_83 ) ;
return 0 ;
}
static struct V_2 * F_26 ( unsigned type )
{
struct V_1 * V_3 ;
if ( type != V_84 )
return NULL ;
V_3 = F_27 ( sizeof( * V_3 ) , V_85 ) ;
if ( ! V_3 )
return NULL ;
if ( F_28 ( & V_3 -> V_4 ) ) {
F_29 ( V_3 ) ;
return NULL ;
}
V_3 -> V_4 . V_86 . V_87 = 0 ;
V_3 -> V_4 . V_86 . V_88 = F_30 ( 32 ) ;
V_3 -> V_4 . V_86 . V_89 = true ;
return & V_3 -> V_4 ;
}
static void F_31 ( struct V_2 * V_4 )
{
F_32 ( V_4 ) ;
F_29 ( F_1 ( V_4 ) ) ;
}
static int F_33 ( struct V_2 * V_4 ,
struct V_48 * V_24 )
{
struct V_1 * V_3 = F_1 ( V_4 ) ;
struct V_6 * V_7 = V_24 -> V_54 -> V_90 ;
int V_21 ;
if ( ! V_7 )
return - V_91 ;
if ( ! V_7 -> V_27 ) {
V_7 -> V_27 = V_3 ;
V_21 = F_21 ( V_7 ) ;
if ( V_21 ) {
V_7 -> V_27 = NULL ;
return V_21 ;
}
} else if ( V_7 -> V_27 != V_3 ) {
F_24 ( V_24 , L_9 ) ;
return - V_92 ;
}
F_16 ( V_7 , V_24 , true ) ;
return 0 ;
}
static void F_34 ( struct V_2 * V_4 ,
struct V_48 * V_24 )
{
struct V_6 * V_7 = V_24 -> V_54 -> V_90 ;
if ( ! V_7 )
return;
F_16 ( V_7 , V_24 , false ) ;
}
static int F_35 ( struct V_2 * V_4 , unsigned long V_14 ,
T_4 V_93 , T_1 V_15 , int V_94 )
{
struct V_1 * V_3 = F_1 ( V_4 ) ;
unsigned long V_95 ;
int V_21 ;
F_36 ( & V_3 -> V_62 , V_95 ) ;
V_21 = V_3 -> V_78 -> V_96 ( V_3 -> V_78 , V_14 , V_93 , V_15 , V_94 ) ;
F_37 ( & V_3 -> V_62 , V_95 ) ;
return V_21 ;
}
static T_1 F_38 ( struct V_2 * V_4 ,
unsigned long V_14 , T_1 V_15 )
{
struct V_1 * V_3 = F_1 ( V_4 ) ;
unsigned long V_95 ;
T_1 V_97 ;
F_36 ( & V_3 -> V_62 , V_95 ) ;
V_97 = V_3 -> V_78 -> V_98 ( V_3 -> V_78 , V_14 , V_15 ) ;
F_37 ( & V_3 -> V_62 , V_95 ) ;
return V_97 ;
}
static T_4 F_39 ( struct V_2 * V_4 ,
T_5 V_14 )
{
struct V_1 * V_3 = F_1 ( V_4 ) ;
unsigned long V_95 ;
T_4 V_99 ;
F_36 ( & V_3 -> V_62 , V_95 ) ;
V_99 = V_3 -> V_78 -> V_100 ( V_3 -> V_78 , V_14 ) ;
F_37 ( & V_3 -> V_62 , V_95 ) ;
return V_99 ;
}
static int F_40 ( struct V_48 * V_24 )
{
struct V_6 * V_7 ;
struct V_101 * V_102 ;
if ( ! V_24 -> V_54 || V_24 -> V_54 -> V_103 != & V_70 )
return - V_91 ;
V_7 = V_24 -> V_54 -> V_90 ;
F_41 ( & V_7 -> V_104 , V_24 ) ;
V_102 = F_42 ( V_24 ) ;
if ( F_43 ( V_102 ) )
return F_44 ( V_102 ) ;
F_45 ( V_102 ) ;
return 0 ;
}
static void F_46 ( struct V_48 * V_24 )
{
struct V_6 * V_7 ;
if ( ! V_24 -> V_54 || V_24 -> V_54 -> V_103 != & V_70 )
return;
V_7 = V_24 -> V_54 -> V_90 ;
F_47 ( & V_7 -> V_104 , V_24 ) ;
F_48 ( V_24 ) ;
F_49 ( V_24 ) ;
}
static struct V_101 * F_50 ( struct V_48 * V_24 )
{
struct V_6 * V_7 = V_24 -> V_54 -> V_90 ;
if ( ! V_7 )
return F_51 ( - V_91 ) ;
if ( ! V_7 -> V_105 ) {
V_7 -> V_105 = F_52 () ;
if ( F_43 ( V_7 -> V_105 ) )
F_24 ( V_24 , L_10 ) ;
} else {
F_53 ( V_7 -> V_105 ) ;
}
return V_7 -> V_105 ;
}
static int F_54 ( struct V_48 * V_24 , struct V_106 * args )
{
struct V_107 * V_108 ;
if ( args -> V_109 != 1 ) {
F_24 ( V_24 , L_11 ,
args -> V_109 ) ;
return - V_80 ;
}
if ( ! V_24 -> V_54 -> V_90 ) {
V_108 = F_55 ( args -> V_110 ) ;
if ( F_56 ( ! V_108 ) )
return - V_80 ;
V_24 -> V_54 -> V_90 = F_57 ( V_108 ) ;
}
return F_58 ( V_24 , args -> args , 1 ) ;
}
static int F_59 ( const struct V_6 * V_7 )
{
T_2 V_29 ;
int V_21 ;
V_21 = F_60 ( V_7 -> V_111 ) ;
if ( V_21 ) {
F_24 ( V_7 -> V_24 , L_12 , V_21 ) ;
return V_21 ;
}
V_29 = V_112 |
F_61 ( 2 ) ;
F_4 ( V_29 , V_7 -> V_10 + V_113 ) ;
V_29 = V_114 |
V_115 |
V_116 |
V_117 |
V_118 |
V_119 ;
F_4 ( V_29 , V_7 -> V_10 + V_45 ) ;
V_29 = V_120 |
V_121 |
V_122 |
V_123 |
V_124 |
V_125 |
V_126 ;
F_4 ( V_29 , V_7 -> V_10 + V_127 ) ;
F_4 ( F_62 ( V_7 -> V_128 , V_7 -> V_76 ) ,
V_7 -> V_10 + V_129 ) ;
F_4 ( 0 , V_7 -> V_10 + V_130 ) ;
F_4 ( 0 , V_7 -> V_10 + V_131 ) ;
if ( F_63 ( V_7 -> V_24 , V_7 -> V_25 , F_10 , 0 ,
F_64 ( V_7 -> V_24 ) , ( void * ) V_7 ) ) {
F_4 ( 0 , V_7 -> V_10 + V_83 ) ;
F_65 ( V_7 -> V_111 ) ;
F_24 ( V_7 -> V_24 , L_13 , V_7 -> V_25 ) ;
return - V_91 ;
}
return 0 ;
}
static int F_66 ( struct V_107 * V_132 )
{
struct V_6 * V_7 ;
struct V_48 * V_24 = & V_132 -> V_24 ;
struct V_133 * V_134 ;
T_6 V_135 ;
struct V_136 * V_137 = NULL ;
void * V_138 ;
int V_56 , V_139 , V_21 ;
V_7 = F_67 ( V_24 , sizeof( * V_7 ) , V_85 ) ;
if ( ! V_7 )
return - V_140 ;
V_7 -> V_24 = V_24 ;
V_138 = F_67 ( V_24 , V_141 * 2 , V_85 ) ;
if ( ! V_138 )
return - V_140 ;
V_7 -> V_128 = F_68 ( F_69 ( V_138 ) , V_141 ) ;
V_7 -> V_76 = ! ! ( V_142 > ( 0xffffffffUL >> V_143 ) ) ;
V_134 = F_70 ( V_132 , V_144 , 0 ) ;
V_7 -> V_10 = F_71 ( V_24 , V_134 ) ;
if ( F_43 ( V_7 -> V_10 ) )
return F_44 ( V_7 -> V_10 ) ;
V_135 = V_134 -> V_145 ;
V_7 -> V_25 = F_72 ( V_132 , 0 ) ;
if ( V_7 -> V_25 < 0 )
return V_7 -> V_25 ;
V_7 -> V_111 = F_73 ( V_24 , L_14 ) ;
if ( F_43 ( V_7 -> V_111 ) )
return F_44 ( V_7 -> V_111 ) ;
V_139 = F_74 ( V_24 -> V_146 ,
L_15 , NULL ) ;
if ( V_139 < 0 )
return V_139 ;
V_7 -> V_59 . V_139 = V_139 ;
for ( V_56 = 0 ; V_56 < V_139 ; V_56 ++ ) {
struct V_147 * V_148 ;
struct V_107 * V_149 ;
V_148 = F_75 ( V_24 -> V_146 , L_15 , V_56 ) ;
if ( ! V_148 )
return - V_80 ;
if ( ! F_76 ( V_148 ) )
continue;
V_149 = F_55 ( V_148 ) ;
if ( ! V_149 ) {
V_149 = F_77 (
V_148 , NULL ,
V_150 . V_151 ) ;
if ( ! V_149 ) {
F_78 ( V_148 ) ;
return - V_152 ;
}
}
V_7 -> V_59 . V_60 [ V_56 ] . V_24 = & V_149 -> V_24 ;
F_79 ( V_24 , & V_137 , V_153 ,
V_154 , V_148 ) ;
}
F_80 ( V_132 , V_7 ) ;
V_21 = F_59 ( V_7 ) ;
if ( V_21 )
return V_21 ;
V_21 = F_81 ( & V_7 -> V_104 , V_24 , NULL ,
L_16 , & V_135 ) ;
if ( V_21 )
return V_21 ;
F_82 ( & V_7 -> V_104 , & V_70 ) ;
F_83 ( & V_7 -> V_104 , & V_132 -> V_24 . V_146 -> V_155 ) ;
V_21 = F_84 ( & V_7 -> V_104 ) ;
if ( V_21 )
return V_21 ;
if ( ! F_85 ( & V_150 ) )
F_86 ( & V_150 , & V_70 ) ;
return F_87 ( V_24 , & V_156 , V_137 ) ;
}
static int F_88 ( struct V_107 * V_132 )
{
struct V_6 * V_7 = F_57 ( V_132 ) ;
F_89 ( & V_7 -> V_104 ) ;
F_90 ( & V_7 -> V_104 ) ;
if ( F_85 ( & V_150 ) )
F_86 ( & V_150 , NULL ) ;
F_91 ( V_7 -> V_27 -> V_78 ) ;
F_65 ( V_7 -> V_111 ) ;
F_92 ( & V_132 -> V_24 , V_7 -> V_25 , V_7 ) ;
F_93 ( & V_132 -> V_24 , & V_156 ) ;
return 0 ;
}
static int T_7 F_94 ( struct V_48 * V_24 )
{
struct V_6 * V_7 = F_95 ( V_24 ) ;
struct V_157 * V_158 = & V_7 -> V_158 ;
void T_8 * V_10 = V_7 -> V_10 ;
V_158 -> V_159 = F_11 ( V_10 +
V_131 ) ;
V_158 -> V_160 = F_11 ( V_10 + V_130 ) ;
V_158 -> V_161 = F_11 ( V_10 + V_113 ) ;
V_158 -> V_162 = F_11 ( V_10 + V_45 ) ;
V_158 -> V_163 = F_11 ( V_10 + V_127 ) ;
return 0 ;
}
static int T_7 F_96 ( struct V_48 * V_24 )
{
struct V_6 * V_7 = F_95 ( V_24 ) ;
struct V_157 * V_158 = & V_7 -> V_158 ;
void T_8 * V_10 = V_7 -> V_10 ;
F_4 ( V_7 -> V_27 -> V_63 . V_81 . V_82 [ 0 ] ,
V_10 + V_83 ) ;
F_4 ( V_158 -> V_159 ,
V_10 + V_131 ) ;
F_4 ( V_158 -> V_160 , V_10 + V_130 ) ;
F_4 ( V_158 -> V_161 , V_10 + V_113 ) ;
F_4 ( V_158 -> V_162 , V_10 + V_45 ) ;
F_4 ( V_158 -> V_163 , V_10 + V_127 ) ;
F_4 ( F_62 ( V_7 -> V_128 , V_7 -> V_76 ) ,
V_10 + V_129 ) ;
return 0 ;
}
static int F_97 ( struct V_147 * V_110 )
{
int V_21 ;
struct V_107 * V_132 ;
V_132 = F_77 ( V_110 , NULL , V_150 . V_151 ) ;
if ( ! V_132 )
return - V_140 ;
V_21 = F_98 ( & V_164 ) ;
if ( V_21 ) {
F_99 ( L_17 , V_165 ) ;
return V_21 ;
}
return 0 ;
}
