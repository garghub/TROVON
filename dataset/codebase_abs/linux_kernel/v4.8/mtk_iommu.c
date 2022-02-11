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
struct V_50 * V_51 , * V_52 , * V_53 ;
struct V_54 * V_55 ;
unsigned int V_56 , V_57 ;
V_51 = V_24 -> V_58 . V_59 ;
F_17 (cur, next, &head->client, client) {
V_56 = F_18 ( V_52 -> V_60 ) ;
V_57 = F_19 ( V_52 -> V_60 ) ;
V_55 = & V_7 -> V_61 . V_62 [ V_56 ] ;
F_20 ( V_24 , L_5 ,
V_49 ? L_6 : L_7 , V_57 ) ;
if ( V_49 )
V_55 -> V_63 |= F_21 ( V_57 ) ;
else
V_55 -> V_63 &= ~ F_21 ( V_57 ) ;
}
}
static int F_22 ( struct V_6 * V_7 )
{
struct V_1 * V_3 = V_7 -> V_27 ;
F_23 ( & V_3 -> V_64 ) ;
V_3 -> V_65 = (struct V_66 ) {
. V_67 = V_68 |
V_69 |
V_70 ,
. V_71 = V_72 . V_71 ,
. V_73 = 32 ,
. V_74 = 32 ,
. V_75 = & V_76 ,
. V_77 = V_7 -> V_24 ,
} ;
if ( V_7 -> V_78 )
V_3 -> V_65 . V_67 |= V_79 ;
V_3 -> V_80 = F_24 ( V_81 , & V_3 -> V_65 , V_7 ) ;
if ( ! V_3 -> V_80 ) {
F_25 ( V_7 -> V_24 , L_8 ) ;
return - V_82 ;
}
V_3 -> V_4 . V_71 = V_3 -> V_65 . V_71 ;
F_26 ( V_7 -> V_27 -> V_65 . V_83 . V_84 [ 0 ] ,
V_7 -> V_10 + V_85 ) ;
return 0 ;
}
static struct V_2 * F_27 ( unsigned type )
{
struct V_1 * V_3 ;
if ( type != V_86 )
return NULL ;
V_3 = F_28 ( sizeof( * V_3 ) , V_87 ) ;
if ( ! V_3 )
return NULL ;
if ( F_29 ( & V_3 -> V_4 ) ) {
F_30 ( V_3 ) ;
return NULL ;
}
V_3 -> V_4 . V_88 . V_89 = 0 ;
V_3 -> V_4 . V_88 . V_90 = F_31 ( 32 ) ;
V_3 -> V_4 . V_88 . V_91 = true ;
return & V_3 -> V_4 ;
}
static void F_32 ( struct V_2 * V_4 )
{
F_33 ( V_4 ) ;
F_30 ( F_1 ( V_4 ) ) ;
}
static int F_34 ( struct V_2 * V_4 ,
struct V_48 * V_24 )
{
struct V_1 * V_3 = F_1 ( V_4 ) ;
struct V_50 * V_92 = V_24 -> V_58 . V_59 ;
struct V_6 * V_7 ;
int V_21 ;
if ( ! V_92 )
return - V_93 ;
V_7 = F_35 ( V_92 -> V_94 ) ;
if ( ! V_7 -> V_27 ) {
V_7 -> V_27 = V_3 ;
V_21 = F_22 ( V_7 ) ;
if ( V_21 ) {
V_7 -> V_27 = NULL ;
return V_21 ;
}
} else if ( V_7 -> V_27 != V_3 ) {
F_25 ( V_24 , L_9 ) ;
return - V_95 ;
}
F_16 ( V_7 , V_24 , true ) ;
return 0 ;
}
static void F_36 ( struct V_2 * V_4 ,
struct V_48 * V_24 )
{
struct V_50 * V_92 = V_24 -> V_58 . V_59 ;
struct V_6 * V_7 ;
if ( ! V_92 )
return;
V_7 = F_35 ( V_92 -> V_94 ) ;
F_16 ( V_7 , V_24 , false ) ;
}
static int F_37 ( struct V_2 * V_4 , unsigned long V_14 ,
T_4 V_96 , T_1 V_15 , int V_97 )
{
struct V_1 * V_3 = F_1 ( V_4 ) ;
unsigned long V_98 ;
int V_21 ;
F_38 ( & V_3 -> V_64 , V_98 ) ;
V_21 = V_3 -> V_80 -> V_99 ( V_3 -> V_80 , V_14 , V_96 , V_15 , V_97 ) ;
F_39 ( & V_3 -> V_64 , V_98 ) ;
return V_21 ;
}
static T_1 F_40 ( struct V_2 * V_4 ,
unsigned long V_14 , T_1 V_15 )
{
struct V_1 * V_3 = F_1 ( V_4 ) ;
unsigned long V_98 ;
T_1 V_100 ;
F_38 ( & V_3 -> V_64 , V_98 ) ;
V_100 = V_3 -> V_80 -> V_101 ( V_3 -> V_80 , V_14 , V_15 ) ;
F_39 ( & V_3 -> V_64 , V_98 ) ;
return V_100 ;
}
static T_4 F_41 ( struct V_2 * V_4 ,
T_5 V_14 )
{
struct V_1 * V_3 = F_1 ( V_4 ) ;
unsigned long V_98 ;
T_4 V_102 ;
F_38 ( & V_3 -> V_64 , V_98 ) ;
V_102 = V_3 -> V_80 -> V_103 ( V_3 -> V_80 , V_14 ) ;
F_39 ( & V_3 -> V_64 , V_98 ) ;
return V_102 ;
}
static int F_42 ( struct V_48 * V_24 )
{
struct V_104 * V_105 ;
if ( ! V_24 -> V_58 . V_59 )
return - V_93 ;
V_105 = F_43 ( V_24 ) ;
if ( F_44 ( V_105 ) )
return F_45 ( V_105 ) ;
F_46 ( V_105 ) ;
return 0 ;
}
static void F_47 ( struct V_48 * V_24 )
{
struct V_50 * V_51 , * V_52 , * V_53 ;
V_51 = V_24 -> V_58 . V_59 ;
if ( ! V_51 )
return;
F_17 (cur, next, &head->client, client) {
F_48 ( & V_52 -> V_106 ) ;
F_30 ( V_52 ) ;
}
F_30 ( V_51 ) ;
V_24 -> V_58 . V_59 = NULL ;
F_49 ( V_24 ) ;
}
static struct V_104 * F_50 ( struct V_48 * V_24 )
{
struct V_6 * V_7 ;
struct V_50 * V_92 ;
V_92 = V_24 -> V_58 . V_59 ;
if ( ! V_92 )
return F_51 ( - V_93 ) ;
V_7 = F_35 ( V_92 -> V_94 ) ;
if ( ! V_7 -> V_107 ) {
V_7 -> V_107 = F_52 () ;
if ( F_44 ( V_7 -> V_107 ) )
F_25 ( V_24 , L_10 ) ;
}
return V_7 -> V_107 ;
}
static int F_53 ( struct V_48 * V_24 , struct V_108 * args )
{
struct V_50 * V_51 , * V_92 , * V_53 ;
struct V_109 * V_110 ;
if ( args -> V_111 != 1 ) {
F_25 ( V_24 , L_11 ,
args -> V_111 ) ;
return - V_82 ;
}
if ( ! V_24 -> V_58 . V_59 ) {
V_110 = F_54 ( args -> V_112 ) ;
if ( F_55 ( ! V_110 ) )
return - V_82 ;
V_51 = F_28 ( sizeof( * V_51 ) , V_87 ) ;
if ( ! V_51 )
return - V_113 ;
V_24 -> V_58 . V_59 = V_51 ;
F_56 ( & V_51 -> V_106 ) ;
V_51 -> V_94 = & V_110 -> V_24 ;
} else {
V_51 = V_24 -> V_58 . V_59 ;
}
V_92 = F_28 ( sizeof( * V_92 ) , V_87 ) ;
if ( ! V_92 )
goto V_114;
V_92 -> V_60 = args -> args [ 0 ] ;
F_57 ( & V_92 -> V_106 , & V_51 -> V_106 ) ;
return 0 ;
V_114:
F_17 (priv, next, &head->client, client)
F_30 ( V_92 ) ;
F_30 ( V_51 ) ;
V_24 -> V_58 . V_59 = NULL ;
return - V_113 ;
}
static int F_58 ( const struct V_6 * V_7 )
{
T_2 V_29 ;
int V_21 ;
V_21 = F_59 ( V_7 -> V_115 ) ;
if ( V_21 ) {
F_25 ( V_7 -> V_24 , L_12 , V_21 ) ;
return V_21 ;
}
V_29 = V_116 |
F_60 ( 2 ) ;
F_4 ( V_29 , V_7 -> V_10 + V_117 ) ;
V_29 = V_118 |
V_119 |
V_120 |
V_121 |
V_122 |
V_123 ;
F_4 ( V_29 , V_7 -> V_10 + V_45 ) ;
V_29 = V_124 |
V_125 |
V_126 |
V_127 |
V_128 |
V_129 |
V_130 ;
F_4 ( V_29 , V_7 -> V_10 + V_131 ) ;
F_4 ( F_61 ( V_7 -> V_132 , V_7 -> V_78 ) ,
V_7 -> V_10 + V_133 ) ;
F_4 ( 0 , V_7 -> V_10 + V_134 ) ;
F_4 ( 0 , V_7 -> V_10 + V_135 ) ;
if ( F_62 ( V_7 -> V_24 , V_7 -> V_25 , F_10 , 0 ,
F_63 ( V_7 -> V_24 ) , ( void * ) V_7 ) ) {
F_4 ( 0 , V_7 -> V_10 + V_85 ) ;
F_64 ( V_7 -> V_115 ) ;
F_25 ( V_7 -> V_24 , L_13 , V_7 -> V_25 ) ;
return - V_93 ;
}
return 0 ;
}
static int F_65 ( struct V_109 * V_136 )
{
struct V_6 * V_7 ;
struct V_48 * V_24 = & V_136 -> V_24 ;
struct V_137 * V_138 ;
struct V_139 * V_140 = NULL ;
void * V_141 ;
int V_142 , V_143 , V_21 ;
V_7 = F_66 ( V_24 , sizeof( * V_7 ) , V_87 ) ;
if ( ! V_7 )
return - V_113 ;
V_7 -> V_24 = V_24 ;
V_141 = F_66 ( V_24 , V_144 * 2 , V_87 ) ;
if ( ! V_141 )
return - V_113 ;
V_7 -> V_132 = F_67 ( F_68 ( V_141 ) , V_144 ) ;
V_7 -> V_78 = ! ! ( V_145 > ( 0xffffffffUL >> V_146 ) ) ;
V_138 = F_69 ( V_136 , V_147 , 0 ) ;
V_7 -> V_10 = F_70 ( V_24 , V_138 ) ;
if ( F_44 ( V_7 -> V_10 ) )
return F_45 ( V_7 -> V_10 ) ;
V_7 -> V_25 = F_71 ( V_136 , 0 ) ;
if ( V_7 -> V_25 < 0 )
return V_7 -> V_25 ;
V_7 -> V_115 = F_72 ( V_24 , L_14 ) ;
if ( F_44 ( V_7 -> V_115 ) )
return F_45 ( V_7 -> V_115 ) ;
V_143 = F_73 ( V_24 -> V_148 ,
L_15 , NULL ) ;
if ( V_143 < 0 )
return V_143 ;
V_7 -> V_61 . V_143 = V_143 ;
for ( V_142 = 0 ; V_142 < V_143 ; V_142 ++ ) {
struct V_149 * V_150 ;
struct V_109 * V_151 ;
V_150 = F_74 ( V_24 -> V_148 , L_15 , V_142 ) ;
if ( ! V_150 )
return - V_82 ;
if ( ! F_75 ( V_150 ) )
continue;
V_151 = F_54 ( V_150 ) ;
F_76 ( V_150 ) ;
if ( ! V_151 ) {
V_151 = F_77 (
V_150 , NULL ,
V_152 . V_153 ) ;
if ( ! V_151 )
return - V_154 ;
}
V_7 -> V_61 . V_62 [ V_142 ] . V_24 = & V_151 -> V_24 ;
F_78 ( V_24 , & V_140 , V_155 , V_150 ) ;
}
F_79 ( V_136 , V_7 ) ;
V_21 = F_58 ( V_7 ) ;
if ( V_21 )
return V_21 ;
if ( ! F_80 ( & V_152 ) )
F_81 ( & V_152 , & V_72 ) ;
return F_82 ( V_24 , & V_156 , V_140 ) ;
}
static int F_83 ( struct V_109 * V_136 )
{
struct V_6 * V_7 = F_84 ( V_136 ) ;
if ( F_80 ( & V_152 ) )
F_81 ( & V_152 , NULL ) ;
F_85 ( V_7 -> V_27 -> V_80 ) ;
F_64 ( V_7 -> V_115 ) ;
F_86 ( & V_136 -> V_24 , V_7 -> V_25 , V_7 ) ;
F_87 ( & V_136 -> V_24 , & V_156 ) ;
return 0 ;
}
static int T_6 F_88 ( struct V_48 * V_24 )
{
struct V_6 * V_7 = F_35 ( V_24 ) ;
struct V_157 * V_158 = & V_7 -> V_158 ;
void T_7 * V_10 = V_7 -> V_10 ;
V_158 -> V_159 = F_11 ( V_10 +
V_135 ) ;
V_158 -> V_160 = F_11 ( V_10 + V_134 ) ;
V_158 -> V_161 = F_11 ( V_10 + V_117 ) ;
V_158 -> V_162 = F_11 ( V_10 + V_45 ) ;
V_158 -> V_163 = F_11 ( V_10 + V_131 ) ;
return 0 ;
}
static int T_6 F_89 ( struct V_48 * V_24 )
{
struct V_6 * V_7 = F_35 ( V_24 ) ;
struct V_157 * V_158 = & V_7 -> V_158 ;
void T_7 * V_10 = V_7 -> V_10 ;
F_4 ( V_7 -> V_27 -> V_65 . V_83 . V_84 [ 0 ] ,
V_10 + V_85 ) ;
F_4 ( V_158 -> V_159 ,
V_10 + V_135 ) ;
F_4 ( V_158 -> V_160 , V_10 + V_134 ) ;
F_4 ( V_158 -> V_161 , V_10 + V_117 ) ;
F_4 ( V_158 -> V_162 , V_10 + V_45 ) ;
F_4 ( V_158 -> V_163 , V_10 + V_131 ) ;
F_4 ( F_61 ( V_7 -> V_132 , V_7 -> V_78 ) ,
V_10 + V_133 ) ;
return 0 ;
}
static int F_90 ( struct V_149 * V_112 )
{
int V_21 ;
struct V_109 * V_136 ;
V_136 = F_77 ( V_112 , NULL , V_152 . V_153 ) ;
if ( ! V_136 )
return - V_113 ;
V_21 = F_91 ( & V_164 ) ;
if ( V_21 ) {
F_92 ( L_16 , V_165 ) ;
return V_21 ;
}
F_93 ( V_112 , & V_72 ) ;
return 0 ;
}
