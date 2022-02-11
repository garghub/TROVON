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
V_7 -> V_21 = true ;
}
static void F_7 ( void * V_5 )
{
struct V_6 * V_7 = V_5 ;
int V_22 ;
T_2 V_23 ;
if ( ! V_7 -> V_21 )
return;
V_22 = F_8 ( V_7 -> V_10 + V_24 , V_23 ,
V_23 != 0 , 10 , 100000 ) ;
if ( V_22 ) {
F_9 ( V_7 -> V_25 ,
L_1 ) ;
F_3 ( V_5 ) ;
}
F_4 ( 0 , V_7 -> V_10 + V_24 ) ;
V_7 -> V_21 = false ;
}
static T_3 F_10 ( int V_26 , void * V_27 )
{
struct V_6 * V_7 = V_27 ;
struct V_1 * V_3 = V_7 -> V_28 ;
T_2 V_29 , V_30 , V_31 , V_32 ;
unsigned int V_33 , V_34 ;
bool V_35 , V_36 ;
V_29 = F_11 ( V_7 -> V_10 + V_37 ) ;
V_31 = F_11 ( V_7 -> V_10 + V_38 ) ;
V_35 = V_31 & V_39 ;
V_36 = V_31 & V_40 ;
V_31 &= V_41 ;
V_32 = F_11 ( V_7 -> V_10 + V_42 ) ;
V_30 = F_11 ( V_7 -> V_10 + V_43 ) ;
V_33 = F_12 ( V_30 ) ;
V_34 = F_13 ( V_30 ) ;
if ( F_14 ( & V_3 -> V_4 , V_7 -> V_25 , V_31 ,
V_36 ? V_44 : V_45 ) ) {
F_15 (
V_7 -> V_25 ,
L_2 ,
V_29 , V_31 , V_32 , V_33 , V_34 ,
V_35 , V_36 ? L_3 : L_4 ) ;
}
V_30 = F_11 ( V_7 -> V_10 + V_46 ) ;
V_30 |= V_47 ;
F_4 ( V_30 , V_7 -> V_10 + V_46 ) ;
F_3 ( V_7 ) ;
return V_48 ;
}
static void F_16 ( struct V_6 * V_7 ,
struct V_49 * V_25 , bool V_50 )
{
struct V_51 * V_52 ;
unsigned int V_53 , V_54 ;
struct V_55 * V_56 = V_25 -> V_55 ;
int V_57 ;
for ( V_57 = 0 ; V_57 < V_56 -> V_58 ; ++ V_57 ) {
V_53 = F_17 ( V_56 -> V_59 [ V_57 ] ) ;
V_54 = F_18 ( V_56 -> V_59 [ V_57 ] ) ;
V_52 = & V_7 -> V_60 . V_61 [ V_53 ] ;
F_19 ( V_25 , L_5 ,
V_50 ? L_6 : L_7 , V_54 ) ;
if ( V_50 )
V_52 -> V_62 |= F_20 ( V_54 ) ;
else
V_52 -> V_62 &= ~ F_20 ( V_54 ) ;
}
}
static int F_21 ( struct V_6 * V_7 )
{
struct V_1 * V_3 = V_7 -> V_28 ;
F_22 ( & V_3 -> V_63 ) ;
V_3 -> V_64 = (struct V_65 ) {
. V_66 = V_67 |
V_68 |
V_69 ,
. V_70 = V_71 . V_70 ,
. V_72 = 32 ,
. V_73 = 32 ,
. V_74 = & V_75 ,
. V_76 = V_7 -> V_25 ,
} ;
if ( V_7 -> V_77 )
V_3 -> V_64 . V_66 |= V_78 ;
V_3 -> V_79 = F_23 ( V_80 , & V_3 -> V_64 , V_7 ) ;
if ( ! V_3 -> V_79 ) {
F_24 ( V_7 -> V_25 , L_8 ) ;
return - V_81 ;
}
V_3 -> V_4 . V_70 = V_3 -> V_64 . V_70 ;
F_25 ( V_7 -> V_28 -> V_64 . V_82 . V_83 [ 0 ] ,
V_7 -> V_10 + V_84 ) ;
return 0 ;
}
static struct V_2 * F_26 ( unsigned type )
{
struct V_1 * V_3 ;
if ( type != V_85 )
return NULL ;
V_3 = F_27 ( sizeof( * V_3 ) , V_86 ) ;
if ( ! V_3 )
return NULL ;
if ( F_28 ( & V_3 -> V_4 ) ) {
F_29 ( V_3 ) ;
return NULL ;
}
V_3 -> V_4 . V_87 . V_88 = 0 ;
V_3 -> V_4 . V_87 . V_89 = F_30 ( 32 ) ;
V_3 -> V_4 . V_87 . V_90 = true ;
return & V_3 -> V_4 ;
}
static void F_31 ( struct V_2 * V_4 )
{
F_32 ( V_4 ) ;
F_29 ( F_1 ( V_4 ) ) ;
}
static int F_33 ( struct V_2 * V_4 ,
struct V_49 * V_25 )
{
struct V_1 * V_3 = F_1 ( V_4 ) ;
struct V_6 * V_7 = V_25 -> V_55 -> V_91 ;
int V_22 ;
if ( ! V_7 )
return - V_92 ;
if ( ! V_7 -> V_28 ) {
V_7 -> V_28 = V_3 ;
V_22 = F_21 ( V_7 ) ;
if ( V_22 ) {
V_7 -> V_28 = NULL ;
return V_22 ;
}
} else if ( V_7 -> V_28 != V_3 ) {
F_24 ( V_25 , L_9 ) ;
return - V_93 ;
}
F_16 ( V_7 , V_25 , true ) ;
return 0 ;
}
static void F_34 ( struct V_2 * V_4 ,
struct V_49 * V_25 )
{
struct V_6 * V_7 = V_25 -> V_55 -> V_91 ;
if ( ! V_7 )
return;
F_16 ( V_7 , V_25 , false ) ;
}
static int F_35 ( struct V_2 * V_4 , unsigned long V_14 ,
T_4 V_94 , T_1 V_15 , int V_95 )
{
struct V_1 * V_3 = F_1 ( V_4 ) ;
unsigned long V_96 ;
int V_22 ;
F_36 ( & V_3 -> V_63 , V_96 ) ;
V_22 = V_3 -> V_79 -> V_97 ( V_3 -> V_79 , V_14 , V_94 , V_15 , V_95 ) ;
F_37 ( & V_3 -> V_63 , V_96 ) ;
return V_22 ;
}
static T_1 F_38 ( struct V_2 * V_4 ,
unsigned long V_14 , T_1 V_15 )
{
struct V_1 * V_3 = F_1 ( V_4 ) ;
unsigned long V_96 ;
T_1 V_98 ;
F_36 ( & V_3 -> V_63 , V_96 ) ;
V_98 = V_3 -> V_79 -> V_99 ( V_3 -> V_79 , V_14 , V_15 ) ;
F_37 ( & V_3 -> V_63 , V_96 ) ;
return V_98 ;
}
static T_4 F_39 ( struct V_2 * V_4 ,
T_5 V_14 )
{
struct V_1 * V_3 = F_1 ( V_4 ) ;
unsigned long V_96 ;
T_4 V_100 ;
F_36 ( & V_3 -> V_63 , V_96 ) ;
V_100 = V_3 -> V_79 -> V_101 ( V_3 -> V_79 , V_14 ) ;
F_37 ( & V_3 -> V_63 , V_96 ) ;
return V_100 ;
}
static int F_40 ( struct V_49 * V_25 )
{
struct V_6 * V_7 ;
struct V_102 * V_103 ;
if ( ! V_25 -> V_55 || V_25 -> V_55 -> V_104 != & V_71 )
return - V_92 ;
V_7 = V_25 -> V_55 -> V_91 ;
F_41 ( & V_7 -> V_105 , V_25 ) ;
V_103 = F_42 ( V_25 ) ;
if ( F_43 ( V_103 ) )
return F_44 ( V_103 ) ;
F_45 ( V_103 ) ;
return 0 ;
}
static void F_46 ( struct V_49 * V_25 )
{
struct V_6 * V_7 ;
if ( ! V_25 -> V_55 || V_25 -> V_55 -> V_104 != & V_71 )
return;
V_7 = V_25 -> V_55 -> V_91 ;
F_47 ( & V_7 -> V_105 , V_25 ) ;
F_48 ( V_25 ) ;
F_49 ( V_25 ) ;
}
static struct V_102 * F_50 ( struct V_49 * V_25 )
{
struct V_6 * V_7 = V_25 -> V_55 -> V_91 ;
if ( ! V_7 )
return F_51 ( - V_92 ) ;
if ( ! V_7 -> V_106 ) {
V_7 -> V_106 = F_52 () ;
if ( F_43 ( V_7 -> V_106 ) )
F_24 ( V_25 , L_10 ) ;
} else {
F_53 ( V_7 -> V_106 ) ;
}
return V_7 -> V_106 ;
}
static int F_54 ( struct V_49 * V_25 , struct V_107 * args )
{
struct V_108 * V_109 ;
if ( args -> V_110 != 1 ) {
F_24 ( V_25 , L_11 ,
args -> V_110 ) ;
return - V_81 ;
}
if ( ! V_25 -> V_55 -> V_91 ) {
V_109 = F_55 ( args -> V_111 ) ;
if ( F_56 ( ! V_109 ) )
return - V_81 ;
V_25 -> V_55 -> V_91 = F_57 ( V_109 ) ;
}
return F_58 ( V_25 , args -> args , 1 ) ;
}
static int F_59 ( const struct V_6 * V_7 )
{
T_2 V_30 ;
int V_22 ;
V_22 = F_60 ( V_7 -> V_112 ) ;
if ( V_22 ) {
F_24 ( V_7 -> V_25 , L_12 , V_22 ) ;
return V_22 ;
}
V_30 = V_113 |
F_61 ( 2 ) ;
F_4 ( V_30 , V_7 -> V_10 + V_114 ) ;
V_30 = V_115 |
V_116 |
V_117 |
V_118 |
V_119 |
V_120 ;
F_4 ( V_30 , V_7 -> V_10 + V_46 ) ;
V_30 = V_121 |
V_122 |
V_123 |
V_124 |
V_125 |
V_126 |
V_127 ;
F_4 ( V_30 , V_7 -> V_10 + V_128 ) ;
F_4 ( F_62 ( V_7 -> V_129 , V_7 -> V_77 ) ,
V_7 -> V_10 + V_130 ) ;
F_4 ( 0 , V_7 -> V_10 + V_131 ) ;
F_4 ( 0 , V_7 -> V_10 + V_132 ) ;
if ( F_63 ( V_7 -> V_25 , V_7 -> V_26 , F_10 , 0 ,
F_64 ( V_7 -> V_25 ) , ( void * ) V_7 ) ) {
F_4 ( 0 , V_7 -> V_10 + V_84 ) ;
F_65 ( V_7 -> V_112 ) ;
F_24 ( V_7 -> V_25 , L_13 , V_7 -> V_26 ) ;
return - V_92 ;
}
return 0 ;
}
static int F_66 ( struct V_108 * V_133 )
{
struct V_6 * V_7 ;
struct V_49 * V_25 = & V_133 -> V_25 ;
struct V_134 * V_135 ;
T_6 V_136 ;
struct V_137 * V_138 = NULL ;
void * V_139 ;
int V_57 , V_140 , V_22 ;
V_7 = F_67 ( V_25 , sizeof( * V_7 ) , V_86 ) ;
if ( ! V_7 )
return - V_141 ;
V_7 -> V_25 = V_25 ;
V_139 = F_67 ( V_25 , V_142 * 2 , V_86 ) ;
if ( ! V_139 )
return - V_141 ;
V_7 -> V_129 = F_68 ( F_69 ( V_139 ) , V_142 ) ;
V_7 -> V_77 = ! ! ( V_143 > ( 0xffffffffUL >> V_144 ) ) ;
V_135 = F_70 ( V_133 , V_145 , 0 ) ;
V_7 -> V_10 = F_71 ( V_25 , V_135 ) ;
if ( F_43 ( V_7 -> V_10 ) )
return F_44 ( V_7 -> V_10 ) ;
V_136 = V_135 -> V_146 ;
V_7 -> V_26 = F_72 ( V_133 , 0 ) ;
if ( V_7 -> V_26 < 0 )
return V_7 -> V_26 ;
V_7 -> V_112 = F_73 ( V_25 , L_14 ) ;
if ( F_43 ( V_7 -> V_112 ) )
return F_44 ( V_7 -> V_112 ) ;
V_140 = F_74 ( V_25 -> V_147 ,
L_15 , NULL ) ;
if ( V_140 < 0 )
return V_140 ;
V_7 -> V_60 . V_140 = V_140 ;
for ( V_57 = 0 ; V_57 < V_140 ; V_57 ++ ) {
struct V_148 * V_149 ;
struct V_108 * V_150 ;
V_149 = F_75 ( V_25 -> V_147 , L_15 , V_57 ) ;
if ( ! V_149 )
return - V_81 ;
if ( ! F_76 ( V_149 ) )
continue;
V_150 = F_55 ( V_149 ) ;
if ( ! V_150 ) {
V_150 = F_77 (
V_149 , NULL ,
V_151 . V_152 ) ;
if ( ! V_150 ) {
F_78 ( V_149 ) ;
return - V_153 ;
}
}
V_7 -> V_60 . V_61 [ V_57 ] . V_25 = & V_150 -> V_25 ;
F_79 ( V_25 , & V_138 , V_154 ,
V_155 , V_149 ) ;
}
F_80 ( V_133 , V_7 ) ;
V_22 = F_59 ( V_7 ) ;
if ( V_22 )
return V_22 ;
V_22 = F_81 ( & V_7 -> V_105 , V_25 , NULL ,
L_16 , & V_136 ) ;
if ( V_22 )
return V_22 ;
F_82 ( & V_7 -> V_105 , & V_71 ) ;
F_83 ( & V_7 -> V_105 , & V_133 -> V_25 . V_147 -> V_156 ) ;
V_22 = F_84 ( & V_7 -> V_105 ) ;
if ( V_22 )
return V_22 ;
if ( ! F_85 ( & V_151 ) )
F_86 ( & V_151 , & V_71 ) ;
return F_87 ( V_25 , & V_157 , V_138 ) ;
}
static int F_88 ( struct V_108 * V_133 )
{
struct V_6 * V_7 = F_57 ( V_133 ) ;
F_89 ( & V_7 -> V_105 ) ;
F_90 ( & V_7 -> V_105 ) ;
if ( F_85 ( & V_151 ) )
F_86 ( & V_151 , NULL ) ;
F_91 ( V_7 -> V_28 -> V_79 ) ;
F_65 ( V_7 -> V_112 ) ;
F_92 ( & V_133 -> V_25 , V_7 -> V_26 , V_7 ) ;
F_93 ( & V_133 -> V_25 , & V_157 ) ;
return 0 ;
}
static int T_7 F_94 ( struct V_49 * V_25 )
{
struct V_6 * V_7 = F_95 ( V_25 ) ;
struct V_158 * V_159 = & V_7 -> V_159 ;
void T_8 * V_10 = V_7 -> V_10 ;
V_159 -> V_160 = F_11 ( V_10 +
V_132 ) ;
V_159 -> V_161 = F_11 ( V_10 + V_131 ) ;
V_159 -> V_162 = F_11 ( V_10 + V_114 ) ;
V_159 -> V_163 = F_11 ( V_10 + V_46 ) ;
V_159 -> V_164 = F_11 ( V_10 + V_128 ) ;
return 0 ;
}
static int T_7 F_96 ( struct V_49 * V_25 )
{
struct V_6 * V_7 = F_95 ( V_25 ) ;
struct V_158 * V_159 = & V_7 -> V_159 ;
void T_8 * V_10 = V_7 -> V_10 ;
F_4 ( V_7 -> V_28 -> V_64 . V_82 . V_83 [ 0 ] ,
V_10 + V_84 ) ;
F_4 ( V_159 -> V_160 ,
V_10 + V_132 ) ;
F_4 ( V_159 -> V_161 , V_10 + V_131 ) ;
F_4 ( V_159 -> V_162 , V_10 + V_114 ) ;
F_4 ( V_159 -> V_163 , V_10 + V_46 ) ;
F_4 ( V_159 -> V_164 , V_10 + V_128 ) ;
F_4 ( F_62 ( V_7 -> V_129 , V_7 -> V_77 ) ,
V_10 + V_130 ) ;
return 0 ;
}
static int F_97 ( struct V_148 * V_111 )
{
int V_22 ;
struct V_108 * V_133 ;
V_133 = F_77 ( V_111 , NULL , V_151 . V_152 ) ;
if ( ! V_133 )
return - V_141 ;
V_22 = F_98 ( & V_165 ) ;
if ( V_22 ) {
F_99 ( L_17 , V_166 ) ;
return V_22 ;
}
return 0 ;
}
