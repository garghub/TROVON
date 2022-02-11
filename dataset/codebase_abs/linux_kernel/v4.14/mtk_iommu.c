static struct V_1 * F_1 ( void )
{
struct V_1 * V_2 ;
F_2 (data)
return V_2 ;
return NULL ;
}
static struct V_3 * F_3 ( struct V_4 * V_5 )
{
return F_4 ( V_5 , struct V_3 , V_6 ) ;
}
static void F_5 ( void * V_7 )
{
struct V_1 * V_2 = V_7 ;
F_2 (data) {
F_6 ( V_8 | V_9 ,
V_2 -> V_10 + V_11 ) ;
F_6 ( V_12 , V_2 -> V_10 + V_13 ) ;
F_7 () ;
}
}
static void F_8 ( unsigned long V_14 , T_1 V_15 ,
T_1 V_16 , bool V_17 ,
void * V_7 )
{
struct V_1 * V_2 = V_7 ;
F_2 (data) {
F_6 ( V_8 | V_9 ,
V_2 -> V_10 + V_11 ) ;
F_6 ( V_14 , V_2 -> V_10 + V_18 ) ;
F_6 ( V_14 + V_15 - 1 ,
V_2 -> V_10 + V_19 ) ;
F_6 ( V_20 ,
V_2 -> V_10 + V_13 ) ;
V_2 -> V_21 = true ;
}
}
static void F_9 ( void * V_7 )
{
struct V_1 * V_2 = V_7 ;
int V_22 ;
T_2 V_23 ;
F_2 (data) {
if ( ! V_2 -> V_21 )
return;
V_22 = F_10 ( V_2 -> V_10 + V_24 ,
V_23 , V_23 != 0 , 10 , 100000 ) ;
if ( V_22 ) {
F_11 ( V_2 -> V_25 ,
L_1 ) ;
F_5 ( V_7 ) ;
}
F_6 ( 0 , V_2 -> V_10 + V_24 ) ;
V_2 -> V_21 = false ;
}
}
static T_3 F_12 ( int V_26 , void * V_27 )
{
struct V_1 * V_2 = V_27 ;
struct V_3 * V_5 = V_2 -> V_28 ;
T_2 V_29 , V_30 , V_31 , V_32 ;
unsigned int V_33 , V_34 ;
bool V_35 , V_36 ;
V_29 = F_13 ( V_2 -> V_10 + V_37 ) ;
V_31 = F_13 ( V_2 -> V_10 + V_38 ) ;
V_35 = V_31 & V_39 ;
V_36 = V_31 & V_40 ;
V_32 = F_13 ( V_2 -> V_10 + V_41 ) ;
V_30 = F_13 ( V_2 -> V_10 + V_42 ) ;
V_33 = F_14 ( V_30 ) ;
V_34 = F_15 ( V_30 ) ;
if ( F_16 ( & V_5 -> V_6 , V_2 -> V_25 , V_31 ,
V_36 ? V_43 : V_44 ) ) {
F_17 (
V_2 -> V_25 ,
L_2 ,
V_29 , V_31 , V_32 , V_33 , V_34 ,
V_35 , V_36 ? L_3 : L_4 ) ;
}
V_30 = F_13 ( V_2 -> V_10 + V_45 ) ;
V_30 |= V_46 ;
F_6 ( V_30 , V_2 -> V_10 + V_45 ) ;
F_5 ( V_2 ) ;
return V_47 ;
}
static void F_18 ( struct V_1 * V_2 ,
struct V_48 * V_25 , bool V_49 )
{
struct V_50 * V_51 ;
unsigned int V_52 , V_53 ;
struct V_54 * V_55 = V_25 -> V_54 ;
int V_56 ;
for ( V_56 = 0 ; V_56 < V_55 -> V_57 ; ++ V_56 ) {
V_52 = F_19 ( V_55 -> V_58 [ V_56 ] ) ;
V_53 = F_20 ( V_55 -> V_58 [ V_56 ] ) ;
V_51 = & V_2 -> V_59 . V_60 [ V_52 ] ;
F_21 ( V_25 , L_5 ,
V_49 ? L_6 : L_7 , V_53 ) ;
if ( V_49 )
V_51 -> V_61 |= F_22 ( V_53 ) ;
else
V_51 -> V_61 &= ~ F_22 ( V_53 ) ;
}
}
static int F_23 ( struct V_3 * V_5 )
{
struct V_1 * V_2 = F_1 () ;
F_24 ( & V_5 -> V_62 ) ;
V_5 -> V_63 = (struct V_64 ) {
. V_65 = V_66 |
V_67 |
V_68 ,
. V_69 = V_70 . V_69 ,
. V_71 = 32 ,
. V_72 = 32 ,
. V_73 = & V_74 ,
. V_75 = V_2 -> V_25 ,
} ;
if ( V_2 -> V_76 )
V_5 -> V_63 . V_65 |= V_77 ;
V_5 -> V_78 = F_25 ( V_79 , & V_5 -> V_63 , V_2 ) ;
if ( ! V_5 -> V_78 ) {
F_26 ( V_2 -> V_25 , L_8 ) ;
return - V_80 ;
}
V_5 -> V_6 . V_69 = V_5 -> V_63 . V_69 ;
return 0 ;
}
static struct V_4 * F_27 ( unsigned type )
{
struct V_3 * V_5 ;
if ( type != V_81 )
return NULL ;
V_5 = F_28 ( sizeof( * V_5 ) , V_82 ) ;
if ( ! V_5 )
return NULL ;
if ( F_29 ( & V_5 -> V_6 ) )
goto V_83;
if ( F_23 ( V_5 ) )
goto V_84;
V_5 -> V_6 . V_85 . V_86 = 0 ;
V_5 -> V_6 . V_85 . V_87 = F_30 ( 32 ) ;
V_5 -> V_6 . V_85 . V_88 = true ;
return & V_5 -> V_6 ;
V_84:
F_31 ( & V_5 -> V_6 ) ;
V_83:
F_32 ( V_5 ) ;
return NULL ;
}
static void F_33 ( struct V_4 * V_6 )
{
struct V_3 * V_5 = F_3 ( V_6 ) ;
F_34 ( V_5 -> V_78 ) ;
F_31 ( V_6 ) ;
F_32 ( F_3 ( V_6 ) ) ;
}
static int F_35 ( struct V_4 * V_6 ,
struct V_48 * V_25 )
{
struct V_3 * V_5 = F_3 ( V_6 ) ;
struct V_1 * V_2 = V_25 -> V_54 -> V_89 ;
if ( ! V_2 )
return - V_90 ;
if ( ! V_2 -> V_28 ) {
V_2 -> V_28 = V_5 ;
F_36 ( V_5 -> V_63 . V_91 . V_92 [ 0 ] ,
V_2 -> V_10 + V_93 ) ;
}
F_18 ( V_2 , V_25 , true ) ;
return 0 ;
}
static void F_37 ( struct V_4 * V_6 ,
struct V_48 * V_25 )
{
struct V_1 * V_2 = V_25 -> V_54 -> V_89 ;
if ( ! V_2 )
return;
F_18 ( V_2 , V_25 , false ) ;
}
static int F_38 ( struct V_4 * V_6 , unsigned long V_14 ,
T_4 V_94 , T_1 V_15 , int V_95 )
{
struct V_3 * V_5 = F_3 ( V_6 ) ;
unsigned long V_96 ;
int V_22 ;
F_39 ( & V_5 -> V_62 , V_96 ) ;
V_22 = V_5 -> V_78 -> V_97 ( V_5 -> V_78 , V_14 , V_94 & F_30 ( 32 ) ,
V_15 , V_95 ) ;
F_40 ( & V_5 -> V_62 , V_96 ) ;
return V_22 ;
}
static T_1 F_41 ( struct V_4 * V_6 ,
unsigned long V_14 , T_1 V_15 )
{
struct V_3 * V_5 = F_3 ( V_6 ) ;
unsigned long V_96 ;
T_1 V_98 ;
F_39 ( & V_5 -> V_62 , V_96 ) ;
V_98 = V_5 -> V_78 -> V_99 ( V_5 -> V_78 , V_14 , V_15 ) ;
F_40 ( & V_5 -> V_62 , V_96 ) ;
return V_98 ;
}
static T_4 F_42 ( struct V_4 * V_6 ,
T_5 V_14 )
{
struct V_3 * V_5 = F_3 ( V_6 ) ;
struct V_1 * V_2 = F_1 () ;
unsigned long V_96 ;
T_4 V_100 ;
F_39 ( & V_5 -> V_62 , V_96 ) ;
V_100 = V_5 -> V_78 -> V_101 ( V_5 -> V_78 , V_14 ) ;
F_40 ( & V_5 -> V_62 , V_96 ) ;
if ( V_2 -> V_76 )
V_100 |= F_43 ( 32 ) ;
return V_100 ;
}
static int F_44 ( struct V_48 * V_25 )
{
struct V_1 * V_2 ;
struct V_102 * V_103 ;
if ( ! V_25 -> V_54 || V_25 -> V_54 -> V_104 != & V_70 )
return - V_90 ;
V_2 = V_25 -> V_54 -> V_89 ;
F_45 ( & V_2 -> V_105 , V_25 ) ;
V_103 = F_46 ( V_25 ) ;
if ( F_47 ( V_103 ) )
return F_48 ( V_103 ) ;
F_49 ( V_103 ) ;
return 0 ;
}
static void F_50 ( struct V_48 * V_25 )
{
struct V_1 * V_2 ;
if ( ! V_25 -> V_54 || V_25 -> V_54 -> V_104 != & V_70 )
return;
V_2 = V_25 -> V_54 -> V_89 ;
F_51 ( & V_2 -> V_105 , V_25 ) ;
F_52 ( V_25 ) ;
F_53 ( V_25 ) ;
}
static struct V_102 * F_54 ( struct V_48 * V_25 )
{
struct V_1 * V_2 = F_1 () ;
if ( ! V_2 )
return F_55 ( - V_90 ) ;
if ( ! V_2 -> V_106 ) {
V_2 -> V_106 = F_56 () ;
if ( F_47 ( V_2 -> V_106 ) )
F_26 ( V_25 , L_9 ) ;
} else {
F_57 ( V_2 -> V_106 ) ;
}
return V_2 -> V_106 ;
}
static int F_58 ( struct V_48 * V_25 , struct V_107 * args )
{
struct V_108 * V_109 ;
if ( args -> V_110 != 1 ) {
F_26 ( V_25 , L_10 ,
args -> V_110 ) ;
return - V_80 ;
}
if ( ! V_25 -> V_54 -> V_89 ) {
V_109 = F_59 ( args -> V_111 ) ;
if ( F_60 ( ! V_109 ) )
return - V_80 ;
V_25 -> V_54 -> V_89 = F_61 ( V_109 ) ;
}
return F_62 ( V_25 , args -> args , 1 ) ;
}
static int F_63 ( const struct V_1 * V_2 )
{
T_2 V_30 ;
int V_22 ;
V_22 = F_64 ( V_2 -> V_112 ) ;
if ( V_22 ) {
F_26 ( V_2 -> V_25 , L_11 , V_22 ) ;
return V_22 ;
}
V_30 = F_65 ( 2 , V_2 ) ;
if ( V_2 -> V_113 == V_114 )
V_30 |= V_115 ;
F_6 ( V_30 , V_2 -> V_10 + V_116 ) ;
V_30 = V_117 |
V_118 |
V_119 |
V_120 |
V_121 |
V_122 ;
F_6 ( V_30 , V_2 -> V_10 + V_45 ) ;
V_30 = V_123 |
V_124 |
V_125 |
V_126 |
V_127 |
V_128 |
V_129 ;
F_6 ( V_30 , V_2 -> V_10 + V_130 ) ;
F_6 ( F_66 ( V_2 -> V_131 , V_2 -> V_76 ) ,
V_2 -> V_10 + V_132 ) ;
if ( V_2 -> V_76 && V_2 -> V_113 != V_114 ) {
V_30 = F_67 ( 7 , 4 ) ;
F_6 ( V_30 , V_2 -> V_10 + V_133 ) ;
}
F_6 ( 0 , V_2 -> V_10 + V_134 ) ;
if ( V_2 -> V_113 == V_114 )
F_6 ( 0 , V_2 -> V_10 + V_135 ) ;
if ( F_68 ( V_2 -> V_25 , V_2 -> V_26 , F_12 , 0 ,
F_69 ( V_2 -> V_25 ) , ( void * ) V_2 ) ) {
F_6 ( 0 , V_2 -> V_10 + V_93 ) ;
F_70 ( V_2 -> V_112 ) ;
F_26 ( V_2 -> V_25 , L_12 , V_2 -> V_26 ) ;
return - V_90 ;
}
return 0 ;
}
static int F_71 ( struct V_108 * V_136 )
{
struct V_1 * V_2 ;
struct V_48 * V_25 = & V_136 -> V_25 ;
struct V_137 * V_138 ;
T_6 V_139 ;
struct V_140 * V_141 = NULL ;
void * V_142 ;
int V_56 , V_143 , V_22 ;
V_2 = F_72 ( V_25 , sizeof( * V_2 ) , V_82 ) ;
if ( ! V_2 )
return - V_144 ;
V_2 -> V_25 = V_25 ;
V_2 -> V_113 = (enum V_145 ) F_73 ( V_25 ) ;
V_142 = F_72 ( V_25 , V_146 * 2 , V_82 ) ;
if ( ! V_142 )
return - V_144 ;
V_2 -> V_131 = F_74 ( F_75 ( V_142 ) , V_146 ) ;
V_2 -> V_76 = ! ! ( V_147 > ( F_43 ( 32 ) >> V_148 ) ) ;
V_138 = F_76 ( V_136 , V_149 , 0 ) ;
V_2 -> V_10 = F_77 ( V_25 , V_138 ) ;
if ( F_47 ( V_2 -> V_10 ) )
return F_48 ( V_2 -> V_10 ) ;
V_139 = V_138 -> V_150 ;
V_2 -> V_26 = F_78 ( V_136 , 0 ) ;
if ( V_2 -> V_26 < 0 )
return V_2 -> V_26 ;
V_2 -> V_112 = F_79 ( V_25 , L_13 ) ;
if ( F_47 ( V_2 -> V_112 ) )
return F_48 ( V_2 -> V_112 ) ;
V_143 = F_80 ( V_25 -> V_151 ,
L_14 , NULL ) ;
if ( V_143 < 0 )
return V_143 ;
V_2 -> V_59 . V_143 = V_143 ;
for ( V_56 = 0 ; V_56 < V_143 ; V_56 ++ ) {
struct V_152 * V_153 ;
struct V_108 * V_154 ;
T_2 V_155 ;
V_153 = F_81 ( V_25 -> V_151 , L_14 , V_56 ) ;
if ( ! V_153 )
return - V_80 ;
if ( ! F_82 ( V_153 ) )
continue;
V_22 = F_83 ( V_153 , L_15 , & V_155 ) ;
if ( V_22 )
V_155 = V_56 ;
V_154 = F_59 ( V_153 ) ;
if ( ! V_154 )
return - V_156 ;
V_2 -> V_59 . V_60 [ V_155 ] . V_25 = & V_154 -> V_25 ;
F_84 ( V_25 , & V_141 , V_157 ,
V_158 , V_153 ) ;
}
F_85 ( V_136 , V_2 ) ;
V_22 = F_63 ( V_2 ) ;
if ( V_22 )
return V_22 ;
V_22 = F_86 ( & V_2 -> V_105 , V_25 , NULL ,
L_16 , & V_139 ) ;
if ( V_22 )
return V_22 ;
F_87 ( & V_2 -> V_105 , & V_70 ) ;
F_88 ( & V_2 -> V_105 , & V_136 -> V_25 . V_151 -> V_159 ) ;
V_22 = F_89 ( & V_2 -> V_105 ) ;
if ( V_22 )
return V_22 ;
F_90 ( & V_2 -> V_160 , & V_161 ) ;
if ( ! F_91 ( & V_162 ) )
F_92 ( & V_162 , & V_70 ) ;
return F_93 ( V_25 , & V_163 , V_141 ) ;
}
static int F_94 ( struct V_108 * V_136 )
{
struct V_1 * V_2 = F_61 ( V_136 ) ;
F_95 ( & V_2 -> V_105 ) ;
F_96 ( & V_2 -> V_105 ) ;
if ( F_91 ( & V_162 ) )
F_92 ( & V_162 , NULL ) ;
F_70 ( V_2 -> V_112 ) ;
F_97 ( & V_136 -> V_25 , V_2 -> V_26 , V_2 ) ;
F_98 ( & V_136 -> V_25 , & V_163 ) ;
return 0 ;
}
static int T_7 F_99 ( struct V_48 * V_25 )
{
struct V_1 * V_2 = F_100 ( V_25 ) ;
struct V_164 * V_165 = & V_2 -> V_165 ;
void T_8 * V_10 = V_2 -> V_10 ;
V_165 -> V_166 = F_13 ( V_10 +
V_135 ) ;
V_165 -> V_167 = F_13 ( V_10 + V_134 ) ;
V_165 -> V_168 = F_13 ( V_10 + V_116 ) ;
V_165 -> V_169 = F_13 ( V_10 + V_45 ) ;
V_165 -> V_170 = F_13 ( V_10 + V_130 ) ;
F_70 ( V_2 -> V_112 ) ;
return 0 ;
}
static int T_7 F_101 ( struct V_48 * V_25 )
{
struct V_1 * V_2 = F_100 ( V_25 ) ;
struct V_164 * V_165 = & V_2 -> V_165 ;
void T_8 * V_10 = V_2 -> V_10 ;
int V_22 ;
V_22 = F_64 ( V_2 -> V_112 ) ;
if ( V_22 ) {
F_26 ( V_2 -> V_25 , L_17 , V_22 ) ;
return V_22 ;
}
F_6 ( V_165 -> V_166 ,
V_10 + V_135 ) ;
F_6 ( V_165 -> V_167 , V_10 + V_134 ) ;
F_6 ( V_165 -> V_168 , V_10 + V_116 ) ;
F_6 ( V_165 -> V_169 , V_10 + V_45 ) ;
F_6 ( V_165 -> V_170 , V_10 + V_130 ) ;
F_6 ( F_66 ( V_2 -> V_131 , V_2 -> V_76 ) ,
V_10 + V_132 ) ;
if ( V_2 -> V_28 )
F_36 ( V_2 -> V_28 -> V_63 . V_91 . V_92 [ 0 ] ,
V_10 + V_93 ) ;
return 0 ;
}
static int T_9 F_102 ( void )
{
int V_22 ;
V_22 = F_103 ( & V_171 ) ;
if ( V_22 != 0 )
F_104 ( L_18 ) ;
return V_22 ;
}
