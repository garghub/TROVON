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
V_3 -> V_78 = F_24 ( V_79 , & V_3 -> V_65 , V_7 ) ;
if ( ! V_3 -> V_78 ) {
F_25 ( V_7 -> V_24 , L_8 ) ;
return - V_80 ;
}
V_72 . V_71 = V_3 -> V_65 . V_71 ;
F_26 ( V_7 -> V_27 -> V_65 . V_81 . V_82 [ 0 ] ,
V_7 -> V_10 + V_83 ) ;
return 0 ;
}
static struct V_2 * F_27 ( unsigned type )
{
struct V_1 * V_3 ;
if ( type != V_84 )
return NULL ;
V_3 = F_28 ( sizeof( * V_3 ) , V_85 ) ;
if ( ! V_3 )
return NULL ;
if ( F_29 ( & V_3 -> V_4 ) ) {
F_30 ( V_3 ) ;
return NULL ;
}
V_3 -> V_4 . V_86 . V_87 = 0 ;
V_3 -> V_4 . V_86 . V_88 = F_31 ( 32 ) ;
V_3 -> V_4 . V_86 . V_89 = true ;
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
struct V_50 * V_90 = V_24 -> V_58 . V_59 ;
struct V_6 * V_7 ;
int V_21 ;
if ( ! V_90 )
return - V_91 ;
V_7 = F_35 ( V_90 -> V_92 ) ;
if ( ! V_7 -> V_27 ) {
V_7 -> V_27 = V_3 ;
V_21 = F_22 ( V_7 ) ;
if ( V_21 ) {
V_7 -> V_27 = NULL ;
return V_21 ;
}
} else if ( V_7 -> V_27 != V_3 ) {
F_25 ( V_24 , L_9 ) ;
return - V_93 ;
}
F_16 ( V_7 , V_24 , true ) ;
return 0 ;
}
static void F_36 ( struct V_2 * V_4 ,
struct V_48 * V_24 )
{
struct V_50 * V_90 = V_24 -> V_58 . V_59 ;
struct V_6 * V_7 ;
if ( ! V_90 )
return;
V_7 = F_35 ( V_90 -> V_92 ) ;
F_16 ( V_7 , V_24 , false ) ;
}
static int F_37 ( struct V_2 * V_4 , unsigned long V_14 ,
T_4 V_94 , T_1 V_15 , int V_95 )
{
struct V_1 * V_3 = F_1 ( V_4 ) ;
unsigned long V_96 ;
int V_21 ;
F_38 ( & V_3 -> V_64 , V_96 ) ;
V_21 = V_3 -> V_78 -> V_97 ( V_3 -> V_78 , V_14 , V_94 , V_15 , V_95 ) ;
F_39 ( & V_3 -> V_64 , V_96 ) ;
return V_21 ;
}
static T_1 F_40 ( struct V_2 * V_4 ,
unsigned long V_14 , T_1 V_15 )
{
struct V_1 * V_3 = F_1 ( V_4 ) ;
unsigned long V_96 ;
T_1 V_98 ;
F_38 ( & V_3 -> V_64 , V_96 ) ;
V_98 = V_3 -> V_78 -> V_99 ( V_3 -> V_78 , V_14 , V_15 ) ;
F_39 ( & V_3 -> V_64 , V_96 ) ;
return V_98 ;
}
static T_4 F_41 ( struct V_2 * V_4 ,
T_5 V_14 )
{
struct V_1 * V_3 = F_1 ( V_4 ) ;
unsigned long V_96 ;
T_4 V_100 ;
F_38 ( & V_3 -> V_64 , V_96 ) ;
V_100 = V_3 -> V_78 -> V_101 ( V_3 -> V_78 , V_14 ) ;
F_39 ( & V_3 -> V_64 , V_96 ) ;
return V_100 ;
}
static int F_42 ( struct V_48 * V_24 )
{
struct V_102 * V_103 ;
if ( ! V_24 -> V_58 . V_59 )
return - V_91 ;
V_103 = F_43 ( V_24 ) ;
if ( F_44 ( V_103 ) )
return F_45 ( V_103 ) ;
F_46 ( V_103 ) ;
return 0 ;
}
static void F_47 ( struct V_48 * V_24 )
{
struct V_50 * V_51 , * V_52 , * V_53 ;
V_51 = V_24 -> V_58 . V_59 ;
if ( ! V_51 )
return;
F_17 (cur, next, &head->client, client) {
F_48 ( & V_52 -> V_104 ) ;
F_30 ( V_52 ) ;
}
F_30 ( V_51 ) ;
V_24 -> V_58 . V_59 = NULL ;
F_49 ( V_24 ) ;
}
static struct V_102 * F_50 ( struct V_48 * V_24 )
{
struct V_6 * V_7 ;
struct V_50 * V_90 ;
V_90 = V_24 -> V_58 . V_59 ;
if ( ! V_90 )
return F_51 ( - V_91 ) ;
V_7 = F_35 ( V_90 -> V_92 ) ;
if ( ! V_7 -> V_105 ) {
V_7 -> V_105 = F_52 () ;
if ( F_44 ( V_7 -> V_105 ) )
F_25 ( V_24 , L_10 ) ;
}
return V_7 -> V_105 ;
}
static int F_53 ( struct V_48 * V_24 , struct V_106 * args )
{
struct V_50 * V_51 , * V_90 , * V_53 ;
struct V_107 * V_108 ;
if ( args -> V_109 != 1 ) {
F_25 ( V_24 , L_11 ,
args -> V_109 ) ;
return - V_80 ;
}
if ( ! V_24 -> V_58 . V_59 ) {
V_108 = F_54 ( args -> V_110 ) ;
F_55 ( args -> V_110 ) ;
if ( F_56 ( ! V_108 ) )
return - V_80 ;
V_51 = F_28 ( sizeof( * V_51 ) , V_85 ) ;
if ( ! V_51 )
return - V_111 ;
V_24 -> V_58 . V_59 = V_51 ;
F_57 ( & V_51 -> V_104 ) ;
V_51 -> V_92 = & V_108 -> V_24 ;
} else {
V_51 = V_24 -> V_58 . V_59 ;
}
V_90 = F_28 ( sizeof( * V_90 ) , V_85 ) ;
if ( ! V_90 )
goto V_112;
V_90 -> V_60 = args -> args [ 0 ] ;
F_58 ( & V_90 -> V_104 , & V_51 -> V_104 ) ;
return 0 ;
V_112:
F_17 (priv, next, &head->client, client)
F_30 ( V_90 ) ;
F_30 ( V_51 ) ;
V_24 -> V_58 . V_59 = NULL ;
return - V_111 ;
}
static int F_59 ( const struct V_6 * V_7 )
{
T_2 V_29 ;
int V_21 ;
V_21 = F_60 ( V_7 -> V_113 ) ;
if ( V_21 ) {
F_25 ( V_7 -> V_24 , L_12 , V_21 ) ;
return V_21 ;
}
V_29 = V_114 |
F_61 ( 2 ) ;
F_4 ( V_29 , V_7 -> V_10 + V_115 ) ;
V_29 = V_116 |
V_117 |
V_118 |
V_119 |
V_120 |
V_121 ;
F_4 ( V_29 , V_7 -> V_10 + V_45 ) ;
V_29 = V_122 |
V_123 |
V_124 |
V_125 |
V_126 |
V_127 |
V_128 ;
F_4 ( V_29 , V_7 -> V_10 + V_129 ) ;
F_4 ( F_62 ( V_7 -> V_130 ) ,
V_7 -> V_10 + V_131 ) ;
F_4 ( 0 , V_7 -> V_10 + V_132 ) ;
F_4 ( 0 , V_7 -> V_10 + V_133 ) ;
if ( F_63 ( V_7 -> V_24 , V_7 -> V_25 , F_10 , 0 ,
F_64 ( V_7 -> V_24 ) , ( void * ) V_7 ) ) {
F_4 ( 0 , V_7 -> V_10 + V_83 ) ;
F_65 ( V_7 -> V_113 ) ;
F_25 ( V_7 -> V_24 , L_13 , V_7 -> V_25 ) ;
return - V_91 ;
}
return 0 ;
}
static int F_66 ( struct V_48 * V_24 , void * V_7 )
{
return V_24 -> V_134 == V_7 ;
}
static int F_67 ( struct V_48 * V_24 )
{
struct V_6 * V_7 = F_35 ( V_24 ) ;
return F_68 ( V_24 , & V_7 -> V_61 ) ;
}
static void F_69 ( struct V_48 * V_24 )
{
struct V_6 * V_7 = F_35 ( V_24 ) ;
F_70 ( V_24 , & V_7 -> V_61 ) ;
}
static int F_71 ( struct V_107 * V_135 )
{
struct V_6 * V_7 ;
struct V_48 * V_24 = & V_135 -> V_24 ;
struct V_136 * V_137 ;
struct V_138 * V_139 = NULL ;
void * V_140 ;
int V_141 , V_142 , V_21 ;
V_7 = F_72 ( V_24 , sizeof( * V_7 ) , V_85 ) ;
if ( ! V_7 )
return - V_111 ;
V_7 -> V_24 = V_24 ;
V_140 = F_72 ( V_24 , V_143 * 2 , V_85 ) ;
if ( ! V_140 )
return - V_111 ;
V_7 -> V_130 = F_73 ( F_74 ( V_140 ) , V_143 ) ;
V_137 = F_75 ( V_135 , V_144 , 0 ) ;
V_7 -> V_10 = F_76 ( V_24 , V_137 ) ;
if ( F_44 ( V_7 -> V_10 ) )
return F_45 ( V_7 -> V_10 ) ;
V_7 -> V_25 = F_77 ( V_135 , 0 ) ;
if ( V_7 -> V_25 < 0 )
return V_7 -> V_25 ;
V_7 -> V_113 = F_78 ( V_24 , L_14 ) ;
if ( F_44 ( V_7 -> V_113 ) )
return F_45 ( V_7 -> V_113 ) ;
V_142 = F_79 ( V_24 -> V_134 ,
L_15 , NULL ) ;
if ( V_142 < 0 )
return V_142 ;
V_7 -> V_61 . V_142 = V_142 ;
for ( V_141 = 0 ; V_141 < V_142 ; V_141 ++ ) {
struct V_145 * V_146 ;
struct V_107 * V_147 ;
V_146 = F_80 ( V_24 -> V_134 , L_15 , V_141 ) ;
if ( ! V_146 )
return - V_80 ;
if ( ! F_81 ( V_146 ) )
continue;
V_147 = F_54 ( V_146 ) ;
F_55 ( V_146 ) ;
if ( ! V_147 ) {
V_147 = F_82 (
V_146 , NULL ,
V_148 . V_149 ) ;
if ( ! V_147 )
return - V_150 ;
}
V_7 -> V_61 . V_62 [ V_141 ] . V_24 = & V_147 -> V_24 ;
F_83 ( V_24 , & V_139 , F_66 , V_146 ) ;
}
F_84 ( V_135 , V_7 ) ;
V_21 = F_59 ( V_7 ) ;
if ( V_21 )
return V_21 ;
if ( ! F_85 ( & V_148 ) )
F_86 ( & V_148 , & V_72 ) ;
return F_87 ( V_24 , & V_151 , V_139 ) ;
}
static int F_88 ( struct V_107 * V_135 )
{
struct V_6 * V_7 = F_89 ( V_135 ) ;
if ( F_85 ( & V_148 ) )
F_86 ( & V_148 , NULL ) ;
F_90 ( V_7 -> V_27 -> V_78 ) ;
F_65 ( V_7 -> V_113 ) ;
F_91 ( & V_135 -> V_24 , V_7 -> V_25 , V_7 ) ;
F_92 ( & V_135 -> V_24 , & V_151 ) ;
return 0 ;
}
static int T_6 F_93 ( struct V_48 * V_24 )
{
struct V_6 * V_7 = F_35 ( V_24 ) ;
struct V_152 * V_153 = & V_7 -> V_153 ;
void T_7 * V_10 = V_7 -> V_10 ;
V_153 -> V_154 = F_11 ( V_10 +
V_133 ) ;
V_153 -> V_155 = F_11 ( V_10 + V_132 ) ;
V_153 -> V_156 = F_11 ( V_10 + V_115 ) ;
V_153 -> V_157 = F_11 ( V_10 + V_45 ) ;
V_153 -> V_158 = F_11 ( V_10 + V_129 ) ;
return 0 ;
}
static int T_6 F_94 ( struct V_48 * V_24 )
{
struct V_6 * V_7 = F_35 ( V_24 ) ;
struct V_152 * V_153 = & V_7 -> V_153 ;
void T_7 * V_10 = V_7 -> V_10 ;
F_4 ( V_7 -> V_27 -> V_65 . V_81 . V_82 [ 0 ] ,
V_10 + V_83 ) ;
F_4 ( V_153 -> V_154 ,
V_10 + V_133 ) ;
F_4 ( V_153 -> V_155 , V_10 + V_132 ) ;
F_4 ( V_153 -> V_156 , V_10 + V_115 ) ;
F_4 ( V_153 -> V_157 , V_10 + V_45 ) ;
F_4 ( V_153 -> V_158 , V_10 + V_129 ) ;
F_4 ( F_62 ( V_7 -> V_130 ) ,
V_10 + V_131 ) ;
return 0 ;
}
static int F_95 ( struct V_145 * V_110 )
{
int V_21 ;
struct V_107 * V_135 ;
V_135 = F_82 ( V_110 , NULL , V_148 . V_149 ) ;
if ( ! V_135 )
return - V_111 ;
V_21 = F_96 ( & V_159 ) ;
if ( V_21 ) {
F_97 ( L_16 , V_160 ) ;
return V_21 ;
}
F_98 ( V_110 , & V_72 ) ;
return 0 ;
}
