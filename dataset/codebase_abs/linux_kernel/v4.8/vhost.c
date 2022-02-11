static void F_1 ( struct V_1 * V_2 )
{
V_2 -> V_3 = ! F_2 () ;
}
static void F_3 ( struct V_1 * V_2 )
{
V_2 -> V_3 = true ;
}
static void F_4 ( struct V_1 * V_2 )
{
V_2 -> V_3 = false ;
}
static long F_5 ( struct V_1 * V_2 , int T_1 * V_4 )
{
struct V_5 V_6 ;
if ( V_2 -> V_7 )
return - V_8 ;
if ( F_6 ( & V_6 , V_4 , sizeof( V_6 ) ) )
return - V_9 ;
if ( V_6 . V_10 != V_11 &&
V_6 . V_10 != V_12 )
return - V_13 ;
if ( V_6 . V_10 == V_12 )
F_3 ( V_2 ) ;
else
F_4 ( V_2 ) ;
return 0 ;
}
static long F_7 ( struct V_1 * V_2 , T_2 V_14 ,
int T_1 * V_4 )
{
struct V_5 V_6 = {
. V_15 = V_14 ,
. V_10 = V_2 -> V_3
} ;
if ( F_8 ( V_4 , & V_6 , sizeof( V_6 ) ) )
return - V_9 ;
return 0 ;
}
static void F_9 ( struct V_1 * V_2 )
{
V_2 -> V_16 = F_10 ( V_2 , V_17 ) || ! V_2 -> V_3 ;
}
static void F_1 ( struct V_1 * V_2 )
{
}
static long F_5 ( struct V_1 * V_2 , int T_1 * V_4 )
{
return - V_18 ;
}
static long F_7 ( struct V_1 * V_2 , T_2 V_14 ,
int T_1 * V_4 )
{
return - V_18 ;
}
static void F_9 ( struct V_1 * V_2 )
{
if ( F_10 ( V_2 , V_17 ) )
V_2 -> V_16 = true ;
}
static void F_11 ( struct V_1 * V_2 )
{
V_2 -> V_16 = F_2 () ;
}
static void F_12 ( struct V_19 * V_20 )
{
struct V_21 * V_6 ;
V_6 = F_13 ( V_20 , struct V_21 , V_20 ) ;
F_14 ( & V_6 -> V_22 ) ;
}
static void F_15 ( struct V_23 * V_23 , T_3 * V_24 ,
T_4 * V_25 )
{
struct V_26 * V_27 ;
V_27 = F_13 ( V_25 , struct V_26 , V_28 ) ;
V_27 -> V_24 = V_24 ;
F_16 ( V_24 , & V_27 -> V_29 ) ;
}
static int F_17 ( T_5 * V_29 , unsigned V_30 , int V_31 ,
void * V_32 )
{
struct V_26 * V_27 = F_13 ( V_29 , struct V_26 , V_29 ) ;
if ( ! ( ( unsigned long ) V_32 & V_27 -> V_33 ) )
return 0 ;
F_18 ( V_27 ) ;
return 0 ;
}
void F_19 ( struct V_19 * V_20 , T_6 V_34 )
{
F_20 ( V_35 , & V_20 -> V_36 ) ;
V_20 -> V_34 = V_34 ;
F_21 ( & V_20 -> V_37 ) ;
}
void F_22 ( struct V_26 * V_27 , T_6 V_34 ,
unsigned long V_33 , struct V_38 * V_39 )
{
F_23 ( & V_27 -> V_29 , F_17 ) ;
F_24 ( & V_27 -> V_28 , F_15 ) ;
V_27 -> V_33 = V_33 ;
V_27 -> V_39 = V_39 ;
V_27 -> V_24 = NULL ;
F_19 ( & V_27 -> V_20 , V_34 ) ;
}
int F_25 ( struct V_26 * V_27 , struct V_23 * V_23 )
{
unsigned long V_33 ;
int V_40 = 0 ;
if ( V_27 -> V_24 )
return 0 ;
V_33 = V_23 -> V_41 -> V_27 ( V_23 , & V_27 -> V_28 ) ;
if ( V_33 )
F_17 ( & V_27 -> V_29 , 0 , 0 , ( void * ) V_33 ) ;
if ( V_33 & V_42 ) {
if ( V_27 -> V_24 )
F_26 ( V_27 -> V_24 , & V_27 -> V_29 ) ;
V_40 = - V_13 ;
}
return V_40 ;
}
void F_27 ( struct V_26 * V_27 )
{
if ( V_27 -> V_24 ) {
F_26 ( V_27 -> V_24 , & V_27 -> V_29 ) ;
V_27 -> V_24 = NULL ;
}
}
void F_28 ( struct V_38 * V_39 , struct V_19 * V_20 )
{
struct V_21 V_43 ;
if ( V_39 -> V_44 ) {
F_29 ( & V_43 . V_22 ) ;
F_19 ( & V_43 . V_20 , F_12 ) ;
F_30 ( V_39 , & V_43 . V_20 ) ;
F_31 ( & V_43 . V_22 ) ;
}
}
void F_32 ( struct V_26 * V_27 )
{
F_28 ( V_27 -> V_39 , & V_27 -> V_20 ) ;
}
void F_30 ( struct V_38 * V_39 , struct V_19 * V_20 )
{
if ( ! V_39 -> V_44 )
return;
if ( ! F_33 ( V_35 , & V_20 -> V_36 ) ) {
F_34 () ;
F_35 ( & V_20 -> V_45 , & V_39 -> V_46 ) ;
F_36 ( V_39 -> V_44 ) ;
}
}
bool F_37 ( struct V_38 * V_39 )
{
return ! F_38 ( & V_39 -> V_46 ) ;
}
void F_18 ( struct V_26 * V_27 )
{
F_30 ( V_27 -> V_39 , & V_27 -> V_20 ) ;
}
static void F_39 ( struct V_38 * V_39 ,
struct V_1 * V_2 )
{
V_2 -> V_10 = 1 ;
V_2 -> V_47 = NULL ;
V_2 -> V_48 = NULL ;
V_2 -> V_49 = NULL ;
V_2 -> V_50 = 0 ;
V_2 -> V_51 = 0 ;
V_2 -> V_52 = 0 ;
V_2 -> V_53 = 0 ;
V_2 -> V_54 = false ;
V_2 -> V_55 = 0 ;
V_2 -> V_56 = false ;
V_2 -> V_57 = - 1ull ;
V_2 -> V_7 = NULL ;
V_2 -> V_58 = 0 ;
V_2 -> V_59 = NULL ;
V_2 -> V_60 = NULL ;
V_2 -> error = NULL ;
V_2 -> V_61 = NULL ;
V_2 -> V_62 = NULL ;
V_2 -> V_63 = NULL ;
V_2 -> V_64 = NULL ;
F_11 ( V_2 ) ;
F_1 ( V_2 ) ;
V_2 -> V_65 = 0 ;
V_2 -> V_66 = NULL ;
V_2 -> V_67 = NULL ;
}
static int F_40 ( void * V_68 )
{
struct V_38 * V_39 = V_68 ;
struct V_19 * V_20 , * V_69 ;
struct V_70 * V_45 ;
T_7 V_71 = F_41 () ;
F_42 ( V_72 ) ;
F_43 ( V_39 -> V_73 ) ;
for (; ; ) {
F_44 ( V_74 ) ;
if ( F_45 () ) {
F_46 ( V_75 ) ;
break;
}
V_45 = F_47 ( & V_39 -> V_46 ) ;
if ( ! V_45 )
F_48 () ;
V_45 = F_49 ( V_45 ) ;
F_50 () ;
F_51 (work, work_next, node, node) {
F_20 ( V_35 , & V_20 -> V_36 ) ;
F_46 ( V_75 ) ;
V_20 -> V_34 ( V_20 ) ;
if ( F_52 () )
F_48 () ;
}
}
F_53 ( V_39 -> V_73 ) ;
F_42 ( V_71 ) ;
return 0 ;
}
static void F_54 ( struct V_1 * V_2 )
{
F_55 ( V_2 -> V_76 ) ;
V_2 -> V_76 = NULL ;
F_55 ( V_2 -> log ) ;
V_2 -> log = NULL ;
F_55 ( V_2 -> V_77 ) ;
V_2 -> V_77 = NULL ;
}
static long F_56 ( struct V_38 * V_39 )
{
struct V_1 * V_2 ;
int V_78 ;
for ( V_78 = 0 ; V_78 < V_39 -> V_79 ; ++ V_78 ) {
V_2 = V_39 -> V_80 [ V_78 ] ;
V_2 -> V_76 = F_57 ( sizeof * V_2 -> V_76 * V_81 ,
V_82 ) ;
V_2 -> log = F_57 ( sizeof * V_2 -> log * V_81 , V_82 ) ;
V_2 -> V_77 = F_57 ( sizeof * V_2 -> V_77 * V_81 , V_82 ) ;
if ( ! V_2 -> V_76 || ! V_2 -> log || ! V_2 -> V_77 )
goto V_83;
}
return 0 ;
V_83:
for (; V_78 >= 0 ; -- V_78 )
F_54 ( V_39 -> V_80 [ V_78 ] ) ;
return - V_84 ;
}
static void F_58 ( struct V_38 * V_39 )
{
int V_78 ;
for ( V_78 = 0 ; V_78 < V_39 -> V_79 ; ++ V_78 )
F_54 ( V_39 -> V_80 [ V_78 ] ) ;
}
void F_59 ( struct V_38 * V_39 ,
struct V_1 * * V_80 , int V_79 )
{
struct V_1 * V_2 ;
int V_78 ;
V_39 -> V_80 = V_80 ;
V_39 -> V_79 = V_79 ;
F_60 ( & V_39 -> V_85 ) ;
V_39 -> V_64 = NULL ;
V_39 -> V_86 = NULL ;
V_39 -> V_66 = NULL ;
V_39 -> V_67 = NULL ;
V_39 -> V_73 = NULL ;
V_39 -> V_44 = NULL ;
F_61 ( & V_39 -> V_46 ) ;
F_21 ( & V_39 -> V_29 ) ;
F_62 ( & V_39 -> V_87 ) ;
F_62 ( & V_39 -> V_88 ) ;
F_63 ( & V_39 -> V_89 ) ;
for ( V_78 = 0 ; V_78 < V_39 -> V_79 ; ++ V_78 ) {
V_2 = V_39 -> V_80 [ V_78 ] ;
V_2 -> log = NULL ;
V_2 -> V_76 = NULL ;
V_2 -> V_77 = NULL ;
V_2 -> V_39 = V_39 ;
F_60 ( & V_2 -> V_85 ) ;
F_39 ( V_39 , V_2 ) ;
if ( V_2 -> V_90 )
F_22 ( & V_2 -> V_27 , V_2 -> V_90 ,
V_91 , V_39 ) ;
}
}
long F_64 ( struct V_38 * V_39 )
{
return V_39 -> V_73 == V_92 -> V_73 ? 0 : - V_93 ;
}
static void F_65 ( struct V_19 * V_20 )
{
struct V_94 * V_6 ;
V_6 = F_13 ( V_20 , struct V_94 , V_20 ) ;
V_6 -> V_40 = F_66 ( V_6 -> V_95 , V_92 ) ;
}
static int F_67 ( struct V_38 * V_39 )
{
struct V_94 V_96 ;
V_96 . V_95 = V_92 ;
F_19 ( & V_96 . V_20 , F_65 ) ;
F_30 ( V_39 , & V_96 . V_20 ) ;
F_28 ( V_39 , & V_96 . V_20 ) ;
return V_96 . V_40 ;
}
bool F_68 ( struct V_38 * V_39 )
{
return V_39 -> V_73 ;
}
long F_69 ( struct V_38 * V_39 )
{
struct V_97 * V_44 ;
int V_98 ;
if ( F_68 ( V_39 ) ) {
V_98 = - V_8 ;
goto V_99;
}
V_39 -> V_73 = F_70 ( V_92 ) ;
V_44 = F_71 ( F_40 , V_39 , L_1 , V_92 -> V_100 ) ;
if ( F_72 ( V_44 ) ) {
V_98 = F_73 ( V_44 ) ;
goto V_101;
}
V_39 -> V_44 = V_44 ;
F_36 ( V_44 ) ;
V_98 = F_67 ( V_39 ) ;
if ( V_98 )
goto V_102;
V_98 = F_56 ( V_39 ) ;
if ( V_98 )
goto V_102;
return 0 ;
V_102:
F_74 ( V_44 ) ;
V_39 -> V_44 = NULL ;
V_101:
if ( V_39 -> V_73 )
F_75 ( V_39 -> V_73 ) ;
V_39 -> V_73 = NULL ;
V_99:
return V_98 ;
}
static void * F_76 ( unsigned long V_103 )
{
void * V_104 = F_77 ( V_103 , V_82 | V_105 | V_106 ) ;
if ( ! V_104 )
V_104 = F_78 ( V_103 ) ;
return V_104 ;
}
struct V_107 * F_79 ( void )
{
return F_76 ( sizeof( struct V_107 ) ) ;
}
void F_80 ( struct V_38 * V_39 , struct V_107 * V_66 )
{
int V_78 ;
F_81 ( V_39 , true ) ;
F_62 ( & V_66 -> V_108 ) ;
V_39 -> V_66 = V_66 ;
for ( V_78 = 0 ; V_78 < V_39 -> V_79 ; ++ V_78 )
V_39 -> V_80 [ V_78 ] -> V_66 = V_66 ;
}
void F_82 ( struct V_38 * V_39 )
{
int V_78 ;
for ( V_78 = 0 ; V_78 < V_39 -> V_79 ; ++ V_78 ) {
if ( V_39 -> V_80 [ V_78 ] -> V_61 && V_39 -> V_80 [ V_78 ] -> V_90 ) {
F_27 ( & V_39 -> V_80 [ V_78 ] -> V_27 ) ;
F_32 ( & V_39 -> V_80 [ V_78 ] -> V_27 ) ;
}
}
}
static void F_83 ( struct V_107 * V_66 ,
struct V_109 * V_45 )
{
F_84 ( V_45 , & V_66 -> V_110 ) ;
F_85 ( & V_45 -> V_111 ) ;
F_55 ( V_45 ) ;
V_66 -> V_112 -- ;
}
static void F_86 ( struct V_107 * V_66 )
{
struct V_109 * V_45 , * V_113 ;
if ( ! V_66 )
return;
F_87 (node, tmp, &umem->umem_list, link)
F_83 ( V_66 , V_45 ) ;
F_88 ( V_66 ) ;
}
static void F_89 ( struct V_38 * V_39 )
{
struct V_114 * V_45 , * V_104 ;
F_90 ( & V_39 -> V_89 ) ;
F_87 (node, n, &dev->read_list, node) {
F_85 ( & V_45 -> V_45 ) ;
F_55 ( V_45 ) ;
}
F_87 (node, n, &dev->pending_list, node) {
F_85 ( & V_45 -> V_45 ) ;
F_55 ( V_45 ) ;
}
F_91 ( & V_39 -> V_89 ) ;
}
void F_81 ( struct V_38 * V_39 , bool V_115 )
{
int V_78 ;
for ( V_78 = 0 ; V_78 < V_39 -> V_79 ; ++ V_78 ) {
if ( V_39 -> V_80 [ V_78 ] -> V_60 )
F_92 ( V_39 -> V_80 [ V_78 ] -> V_60 ) ;
if ( V_39 -> V_80 [ V_78 ] -> error )
F_93 ( V_39 -> V_80 [ V_78 ] -> error ) ;
if ( V_39 -> V_80 [ V_78 ] -> V_61 )
F_93 ( V_39 -> V_80 [ V_78 ] -> V_61 ) ;
if ( V_39 -> V_80 [ V_78 ] -> V_62 )
F_92 ( V_39 -> V_80 [ V_78 ] -> V_62 ) ;
if ( V_39 -> V_80 [ V_78 ] -> V_63 )
F_93 ( V_39 -> V_80 [ V_78 ] -> V_63 ) ;
F_39 ( V_39 , V_39 -> V_80 [ V_78 ] ) ;
}
F_58 ( V_39 ) ;
if ( V_39 -> V_64 )
F_92 ( V_39 -> V_64 ) ;
V_39 -> V_64 = NULL ;
if ( V_39 -> V_86 )
F_93 ( V_39 -> V_86 ) ;
V_39 -> V_86 = NULL ;
F_86 ( V_39 -> V_66 ) ;
V_39 -> V_66 = NULL ;
F_86 ( V_39 -> V_67 ) ;
V_39 -> V_67 = NULL ;
F_89 ( V_39 ) ;
F_94 ( & V_39 -> V_29 , V_91 | V_116 ) ;
F_95 ( ! F_38 ( & V_39 -> V_46 ) ) ;
if ( V_39 -> V_44 ) {
F_74 ( V_39 -> V_44 ) ;
V_39 -> V_44 = NULL ;
}
if ( V_39 -> V_73 )
F_75 ( V_39 -> V_73 ) ;
V_39 -> V_73 = NULL ;
}
static int F_96 ( void T_1 * V_59 , T_8 V_117 , unsigned long V_118 )
{
T_8 V_119 = V_117 / V_120 / 8 ;
if ( V_119 > V_121 - ( unsigned long ) V_59 ||
V_119 + ( unsigned long ) V_59 > V_121 )
return 0 ;
return F_97 ( V_122 , V_59 + V_119 ,
( V_118 + V_120 * 8 - 1 ) / V_120 / 8 ) ;
}
static bool F_98 ( T_8 V_123 , T_8 V_103 )
{
return V_123 > V_121 || V_103 > V_121 || V_123 > V_121 - V_103 ;
}
static int F_99 ( void T_1 * V_59 , struct V_107 * V_66 ,
int V_124 )
{
struct V_109 * V_45 ;
if ( ! V_66 )
return 0 ;
F_100 (node, &umem->umem_list, link) {
unsigned long V_119 = V_45 -> V_125 ;
if ( F_98 ( V_45 -> V_125 , V_45 -> V_103 ) )
return 0 ;
if ( ! F_97 ( V_122 , ( void T_1 * ) V_119 ,
V_45 -> V_103 ) )
return 0 ;
else if ( V_124 && ! F_96 ( V_59 ,
V_45 -> V_126 ,
V_45 -> V_103 ) )
return 0 ;
}
return 1 ;
}
static int F_101 ( struct V_38 * V_127 , struct V_107 * V_66 ,
int V_124 )
{
int V_78 ;
for ( V_78 = 0 ; V_78 < V_127 -> V_79 ; ++ V_78 ) {
int V_128 ;
bool log ;
F_102 ( & V_127 -> V_80 [ V_78 ] -> V_85 ) ;
log = V_124 || F_10 ( V_127 -> V_80 [ V_78 ] , V_129 ) ;
if ( V_127 -> V_80 [ V_78 ] -> V_7 )
V_128 = F_99 ( V_127 -> V_80 [ V_78 ] -> V_59 ,
V_66 , log ) ;
else
V_128 = 1 ;
F_103 ( & V_127 -> V_80 [ V_78 ] -> V_85 ) ;
if ( ! V_128 )
return 0 ;
}
return 1 ;
}
static int F_104 ( struct V_1 * V_2 , void * V_130 ,
const void * V_131 , unsigned V_103 )
{
int V_40 ;
if ( ! V_2 -> V_67 )
return F_105 ( V_130 , V_131 , V_103 ) ;
else {
struct V_132 V_133 ;
V_40 = F_106 ( V_2 , ( T_8 ) ( V_134 ) V_130 , V_103 , V_2 -> V_135 ,
F_107 ( V_2 -> V_135 ) ,
V_136 ) ;
if ( V_40 < 0 )
goto V_137;
F_108 ( & V_133 , V_138 , V_2 -> V_135 , V_40 , V_103 ) ;
V_40 = F_109 ( V_131 , V_103 , & V_133 ) ;
if ( V_40 == V_103 )
V_40 = 0 ;
}
V_137:
return V_40 ;
}
static int F_110 ( struct V_1 * V_2 , void * V_130 ,
void * V_131 , unsigned V_103 )
{
int V_40 ;
if ( ! V_2 -> V_67 )
return F_111 ( V_130 , V_131 , V_103 ) ;
else {
struct V_132 V_139 ;
V_40 = F_106 ( V_2 , ( T_8 ) ( V_134 ) V_131 , V_103 , V_2 -> V_135 ,
F_107 ( V_2 -> V_135 ) ,
V_140 ) ;
if ( V_40 < 0 ) {
F_112 ( V_2 , L_2
L_3 , V_131 ,
( unsigned long long ) V_103 ) ;
goto V_137;
}
F_108 ( & V_139 , V_141 , V_2 -> V_135 , V_40 , V_103 ) ;
V_40 = F_113 ( V_130 , V_103 , & V_139 ) ;
if ( V_40 == V_103 )
V_40 = 0 ;
}
V_137:
return V_40 ;
}
static void T_1 * F_114 ( struct V_1 * V_2 ,
void * V_117 , unsigned V_103 )
{
int V_40 ;
V_40 = F_106 ( V_2 , ( T_8 ) ( V_134 ) V_117 , V_103 , V_2 -> V_135 ,
F_107 ( V_2 -> V_135 ) ,
V_140 ) ;
if ( V_40 < 0 ) {
F_112 ( V_2 , L_2
L_3 , V_117 ,
( unsigned long long ) V_103 ) ;
return NULL ;
}
if ( V_40 != 1 || V_2 -> V_135 [ 0 ] . V_142 != V_103 ) {
F_112 ( V_2 , L_4
L_3 , V_117 ,
( unsigned long long ) V_103 ) ;
return NULL ;
}
return V_2 -> V_135 [ 0 ] . V_143 ;
}
static void F_115 ( struct V_38 * V_127 )
{
int V_78 = 0 ;
for ( V_78 = 0 ; V_78 < V_127 -> V_79 ; ++ V_78 )
F_102 ( & V_127 -> V_80 [ V_78 ] -> V_85 ) ;
}
static void F_116 ( struct V_38 * V_127 )
{
int V_78 = 0 ;
for ( V_78 = 0 ; V_78 < V_127 -> V_79 ; ++ V_78 )
F_103 ( & V_127 -> V_80 [ V_78 ] -> V_85 ) ;
}
static int F_117 ( struct V_107 * V_66 ,
T_8 V_126 , T_8 V_103 , T_8 V_144 ,
T_8 V_125 , int V_145 )
{
struct V_109 * V_113 , * V_45 = F_57 ( sizeof( * V_45 ) , V_146 ) ;
if ( ! V_45 )
return - V_84 ;
if ( V_66 -> V_112 == V_147 ) {
V_113 = F_118 ( & V_66 -> V_108 , F_119 ( * V_113 ) , V_111 ) ;
F_83 ( V_66 , V_113 ) ;
}
V_45 -> V_126 = V_126 ;
V_45 -> V_103 = V_103 ;
V_45 -> V_148 = V_144 ;
V_45 -> V_125 = V_125 ;
V_45 -> V_145 = V_145 ;
F_62 ( & V_45 -> V_111 ) ;
F_120 ( & V_45 -> V_111 , & V_66 -> V_108 ) ;
F_121 ( V_45 , & V_66 -> V_110 ) ;
V_66 -> V_112 ++ ;
return 0 ;
}
static void F_122 ( struct V_107 * V_66 ,
T_8 V_126 , T_8 V_144 )
{
struct V_109 * V_45 ;
while ( ( V_45 = F_123 ( & V_66 -> V_110 ,
V_126 , V_144 ) ) )
F_83 ( V_66 , V_45 ) ;
}
static void F_124 ( struct V_38 * V_127 ,
struct V_149 * V_150 )
{
struct V_114 * V_45 , * V_104 ;
F_90 ( & V_127 -> V_89 ) ;
F_87 (node, n, &d->pending_list, node) {
struct V_149 * V_151 = & V_45 -> V_150 . V_67 ;
if ( V_150 -> V_152 <= V_151 -> V_152 &&
V_150 -> V_152 + V_150 -> V_103 - 1 > V_151 -> V_152 &&
V_151 -> type == V_153 ) {
F_18 ( & V_45 -> V_2 -> V_27 ) ;
F_85 ( & V_45 -> V_45 ) ;
F_55 ( V_45 ) ;
}
}
F_91 ( & V_127 -> V_89 ) ;
}
static int F_125 ( T_8 V_123 , T_8 V_103 , int V_154 )
{
unsigned long V_119 = V_123 ;
if ( F_98 ( V_123 , V_103 ) )
return - V_9 ;
if ( ( V_154 & V_140 ) &&
! F_97 ( V_155 , ( void T_1 * ) V_119 , V_103 ) )
return - V_9 ;
if ( ( V_154 & V_136 ) &&
! F_97 ( V_122 , ( void T_1 * ) V_119 , V_103 ) )
return - V_9 ;
return 0 ;
}
int F_126 ( struct V_38 * V_39 ,
struct V_149 * V_150 )
{
int V_40 = 0 ;
F_115 ( V_39 ) ;
switch ( V_150 -> type ) {
case V_156 :
if ( ! V_39 -> V_67 ) {
V_40 = - V_9 ;
break;
}
if ( F_125 ( V_150 -> V_123 , V_150 -> V_103 , V_150 -> V_145 ) ) {
V_40 = - V_9 ;
break;
}
if ( F_117 ( V_39 -> V_67 , V_150 -> V_152 , V_150 -> V_103 ,
V_150 -> V_152 + V_150 -> V_103 - 1 ,
V_150 -> V_123 , V_150 -> V_145 ) ) {
V_40 = - V_84 ;
break;
}
F_124 ( V_39 , V_150 ) ;
break;
case V_157 :
F_122 ( V_39 -> V_67 , V_150 -> V_152 ,
V_150 -> V_152 + V_150 -> V_103 - 1 ) ;
break;
default:
V_40 = - V_13 ;
break;
}
F_116 ( V_39 ) ;
return V_40 ;
}
T_9 F_127 ( struct V_38 * V_39 ,
struct V_132 * V_131 )
{
struct V_114 V_45 ;
unsigned V_103 = sizeof( struct V_158 ) ;
T_10 V_40 ;
int V_98 ;
if ( F_128 ( V_131 ) < V_103 )
return 0 ;
V_40 = F_113 ( & V_45 . V_150 , V_103 , V_131 ) ;
if ( V_40 != V_103 )
goto V_37;
switch ( V_45 . V_150 . type ) {
case V_159 :
V_98 = F_126 ( V_39 , & V_45 . V_150 . V_67 ) ;
if ( V_98 )
V_40 = V_98 ;
break;
default:
V_40 = - V_13 ;
break;
}
V_37:
return V_40 ;
}
unsigned int F_129 ( struct V_23 * V_23 , struct V_38 * V_39 ,
T_4 * V_29 )
{
unsigned int V_33 = 0 ;
F_130 ( V_23 , & V_39 -> V_29 , V_29 ) ;
if ( ! F_131 ( & V_39 -> V_87 ) )
V_33 |= V_91 | V_116 ;
return V_33 ;
}
T_9 F_132 ( struct V_38 * V_39 , struct V_132 * V_130 ,
int V_160 )
{
F_133 ( V_29 ) ;
struct V_114 * V_45 ;
T_9 V_40 = 0 ;
unsigned V_103 = sizeof( struct V_158 ) ;
if ( F_128 ( V_130 ) < V_103 )
return 0 ;
while ( 1 ) {
if ( ! V_160 )
F_134 ( & V_39 -> V_29 , & V_29 ,
V_74 ) ;
V_45 = F_135 ( V_39 , & V_39 -> V_87 ) ;
if ( V_45 )
break;
if ( V_160 ) {
V_40 = - V_161 ;
break;
}
if ( F_136 ( V_92 ) ) {
V_40 = - V_162 ;
break;
}
if ( ! V_39 -> V_67 ) {
V_40 = - V_163 ;
break;
}
F_48 () ;
}
if ( ! V_160 )
F_137 ( & V_39 -> V_29 , & V_29 ) ;
if ( V_45 ) {
V_40 = F_109 ( & V_45 -> V_150 , V_103 , V_130 ) ;
if ( V_40 != V_103 || V_45 -> V_150 . type != V_153 ) {
F_55 ( V_45 ) ;
return V_40 ;
}
F_138 ( V_39 , & V_39 -> V_88 , V_45 ) ;
}
return V_40 ;
}
static int F_139 ( struct V_1 * V_2 , T_8 V_152 , int V_154 )
{
struct V_38 * V_39 = V_2 -> V_39 ;
struct V_114 * V_45 ;
struct V_149 * V_150 ;
V_45 = F_140 ( V_2 , V_153 ) ;
if ( ! V_45 )
return - V_84 ;
V_150 = & V_45 -> V_150 . V_67 ;
V_150 -> type = V_153 ;
V_150 -> V_152 = V_152 ;
V_150 -> V_145 = V_154 ;
F_138 ( V_39 , & V_39 -> V_87 , V_45 ) ;
return 0 ;
}
static int F_141 ( struct V_1 * V_2 , unsigned int V_10 ,
struct V_164 T_1 * V_47 ,
struct V_165 T_1 * V_48 ,
struct V_166 T_1 * V_49 )
{
T_10 V_6 = F_10 ( V_2 , V_167 ) ? 2 : 0 ;
return F_97 ( V_155 , V_47 , V_10 * sizeof *V_47 ) &&
F_97 ( V_155 , V_48 ,
sizeof *V_48 + V_10 * sizeof * V_48 -> V_168 + V_6 ) &&
F_97 ( V_122 , V_49 ,
sizeof *V_49 + V_10 * sizeof * V_49 -> V_168 + V_6 ) ;
}
static int F_142 ( struct V_1 * V_2 ,
int V_154 , T_8 V_117 , T_8 V_169 )
{
const struct V_109 * V_45 ;
struct V_107 * V_66 = V_2 -> V_67 ;
T_8 V_6 = 0 , V_103 ;
while ( V_169 > V_6 ) {
V_45 = F_123 ( & V_66 -> V_110 ,
V_117 ,
V_117 + V_169 - 1 ) ;
if ( V_45 == NULL || V_45 -> V_126 > V_117 ) {
F_139 ( V_2 , V_117 , V_154 ) ;
return false ;
} else if ( ! ( V_45 -> V_145 & V_154 ) ) {
return false ;
}
V_103 = V_45 -> V_103 - V_117 + V_45 -> V_126 ;
V_6 += V_103 ;
V_117 += V_103 ;
}
return true ;
}
int F_143 ( struct V_1 * V_2 )
{
T_10 V_6 = F_10 ( V_2 , V_167 ) ? 2 : 0 ;
unsigned int V_10 = V_2 -> V_10 ;
if ( ! V_2 -> V_67 )
return 1 ;
return F_142 ( V_2 , V_140 , ( T_8 ) ( V_134 ) V_2 -> V_47 ,
V_10 * sizeof * V_2 -> V_47 ) &&
F_142 ( V_2 , V_140 , ( T_8 ) ( V_134 ) V_2 -> V_48 ,
sizeof * V_2 -> V_48 +
V_10 * sizeof * V_2 -> V_48 -> V_168 + V_6 ) &&
F_142 ( V_2 , V_136 , ( T_8 ) ( V_134 ) V_2 -> V_49 ,
sizeof * V_2 -> V_49 +
V_10 * sizeof * V_2 -> V_49 -> V_168 + V_6 ) ;
}
int F_144 ( struct V_38 * V_39 )
{
return F_101 ( V_39 , V_39 -> V_66 , 1 ) ;
}
static int F_145 ( struct V_1 * V_2 ,
void T_1 * V_59 )
{
T_10 V_6 = F_10 ( V_2 , V_167 ) ? 2 : 0 ;
return F_99 ( V_59 , V_2 -> V_66 ,
F_10 ( V_2 , V_129 ) ) &&
( ! V_2 -> V_56 || F_96 ( V_59 , V_2 -> V_57 ,
sizeof * V_2 -> V_49 +
V_2 -> V_10 * sizeof * V_2 -> V_49 -> V_168 + V_6 ) ) ;
}
int F_146 ( struct V_1 * V_2 )
{
if ( V_2 -> V_67 ) {
return 1 ;
}
return F_141 ( V_2 , V_2 -> V_10 , V_2 -> V_47 , V_2 -> V_48 , V_2 -> V_49 ) &&
F_145 ( V_2 , V_2 -> V_59 ) ;
}
static struct V_107 * F_147 ( void )
{
struct V_107 * V_66 = F_76 ( sizeof( * V_66 ) ) ;
if ( ! V_66 )
return NULL ;
V_66 -> V_110 = V_170 ;
V_66 -> V_112 = 0 ;
F_62 ( & V_66 -> V_108 ) ;
return V_66 ;
}
static long F_148 ( struct V_38 * V_127 , struct V_171 T_1 * V_172 )
{
struct V_171 V_173 , * V_174 ;
struct V_175 * V_176 ;
struct V_107 * V_177 , * V_178 ;
unsigned long V_103 = F_149 ( struct V_171 , V_179 ) ;
int V_78 ;
if ( F_6 ( & V_173 , V_172 , V_103 ) )
return - V_9 ;
if ( V_173 . V_180 )
return - V_181 ;
if ( V_173 . V_182 > V_183 )
return - V_184 ;
V_174 = F_76 ( V_103 + V_173 . V_182 * sizeof( * V_172 -> V_179 ) ) ;
if ( ! V_174 )
return - V_84 ;
memcpy ( V_174 , & V_173 , V_103 ) ;
if ( F_6 ( V_174 -> V_179 , V_172 -> V_179 ,
V_173 . V_182 * sizeof * V_172 -> V_179 ) ) {
F_88 ( V_174 ) ;
return - V_9 ;
}
V_177 = F_147 () ;
if ( ! V_177 ) {
F_88 ( V_174 ) ;
return - V_84 ;
}
for ( V_176 = V_174 -> V_179 ;
V_176 < V_174 -> V_179 + V_173 . V_182 ;
V_176 ++ ) {
if ( F_117 ( V_177 ,
V_176 -> V_185 ,
V_176 -> V_186 ,
V_176 -> V_185 +
V_176 -> V_186 - 1 ,
V_176 -> V_125 ,
V_187 ) )
goto V_98;
}
if ( ! F_101 ( V_127 , V_177 , 0 ) )
goto V_98;
V_178 = V_127 -> V_66 ;
V_127 -> V_66 = V_177 ;
for ( V_78 = 0 ; V_78 < V_127 -> V_79 ; ++ V_78 ) {
F_102 ( & V_127 -> V_80 [ V_78 ] -> V_85 ) ;
V_127 -> V_80 [ V_78 ] -> V_66 = V_177 ;
F_103 ( & V_127 -> V_80 [ V_78 ] -> V_85 ) ;
}
F_88 ( V_174 ) ;
F_86 ( V_178 ) ;
return 0 ;
V_98:
F_86 ( V_177 ) ;
F_88 ( V_174 ) ;
return - V_9 ;
}
long F_150 ( struct V_38 * V_127 , int V_188 , void T_1 * V_4 )
{
struct V_23 * V_189 , * V_190 = NULL ;
bool V_191 = false , V_192 = false ;
struct V_193 * V_194 = NULL ;
T_2 T_1 * V_195 = V_4 ;
struct V_1 * V_2 ;
struct V_5 V_6 ;
struct V_196 V_139 ;
struct V_197 V_119 ;
T_2 V_14 ;
long V_198 ;
V_198 = F_151 ( V_14 , V_195 ) ;
if ( V_198 < 0 )
return V_198 ;
if ( V_14 >= V_127 -> V_79 )
return - V_199 ;
V_2 = V_127 -> V_80 [ V_14 ] ;
F_102 ( & V_2 -> V_85 ) ;
switch ( V_188 ) {
case V_200 :
if ( V_2 -> V_7 ) {
V_198 = - V_8 ;
break;
}
if ( F_6 ( & V_6 , V_4 , sizeof V_6 ) ) {
V_198 = - V_9 ;
break;
}
if ( ! V_6 . V_10 || V_6 . V_10 > 0xffff || ( V_6 . V_10 & ( V_6 . V_10 - 1 ) ) ) {
V_198 = - V_13 ;
break;
}
V_2 -> V_10 = V_6 . V_10 ;
break;
case V_201 :
if ( V_2 -> V_7 ) {
V_198 = - V_8 ;
break;
}
if ( F_6 ( & V_6 , V_4 , sizeof V_6 ) ) {
V_198 = - V_9 ;
break;
}
if ( V_6 . V_10 > 0xffff ) {
V_198 = - V_13 ;
break;
}
V_2 -> V_50 = V_6 . V_10 ;
V_2 -> V_51 = V_2 -> V_50 ;
break;
case V_202 :
V_6 . V_15 = V_14 ;
V_6 . V_10 = V_2 -> V_50 ;
if ( F_8 ( V_4 , & V_6 , sizeof V_6 ) )
V_198 = - V_9 ;
break;
case V_203 :
if ( F_6 ( & V_119 , V_4 , sizeof V_119 ) ) {
V_198 = - V_9 ;
break;
}
if ( V_119 . V_36 & ~ ( 0x1 << V_204 ) ) {
V_198 = - V_181 ;
break;
}
if ( ( T_8 ) ( unsigned long ) V_119 . V_205 != V_119 . V_205 ||
( T_8 ) ( unsigned long ) V_119 . V_206 != V_119 . V_206 ||
( T_8 ) ( unsigned long ) V_119 . V_207 != V_119 . V_207 ) {
V_198 = - V_9 ;
break;
}
F_152 ( V_208 * V_2 -> V_48 > V_209 ) ;
F_152 ( V_208 * V_2 -> V_49 > V_210 ) ;
if ( ( V_119 . V_207 & ( V_209 - 1 ) ) ||
( V_119 . V_206 & ( V_210 - 1 ) ) ||
( V_119 . V_211 & ( V_210 - 1 ) ) ) {
V_198 = - V_13 ;
break;
}
if ( V_2 -> V_7 ) {
if ( ! F_141 ( V_2 , V_2 -> V_10 ,
( void T_1 * ) ( unsigned long ) V_119 . V_205 ,
( void T_1 * ) ( unsigned long ) V_119 . V_207 ,
( void T_1 * ) ( unsigned long ) V_119 . V_206 ) ) {
V_198 = - V_13 ;
break;
}
if ( ( V_119 . V_36 & ( 0x1 << V_204 ) ) &&
! F_96 ( V_2 -> V_59 , V_119 . V_211 ,
sizeof * V_2 -> V_49 +
V_2 -> V_10 * sizeof * V_2 -> V_49 -> V_168 ) ) {
V_198 = - V_13 ;
break;
}
}
V_2 -> V_56 = ! ! ( V_119 . V_36 & ( 0x1 << V_204 ) ) ;
V_2 -> V_47 = ( void T_1 * ) ( unsigned long ) V_119 . V_205 ;
V_2 -> V_48 = ( void T_1 * ) ( unsigned long ) V_119 . V_207 ;
V_2 -> V_57 = V_119 . V_211 ;
V_2 -> V_49 = ( void T_1 * ) ( unsigned long ) V_119 . V_206 ;
break;
case V_212 :
if ( F_6 ( & V_139 , V_4 , sizeof V_139 ) ) {
V_198 = - V_9 ;
break;
}
V_189 = V_139 . V_213 == - 1 ? NULL : F_153 ( V_139 . V_213 ) ;
if ( F_72 ( V_189 ) ) {
V_198 = F_73 ( V_189 ) ;
break;
}
if ( V_189 != V_2 -> V_61 ) {
V_192 = ( V_190 = V_2 -> V_61 ) != NULL ;
V_191 = ( V_2 -> V_61 = V_189 ) != NULL ;
} else
V_190 = V_189 ;
break;
case V_214 :
if ( F_6 ( & V_139 , V_4 , sizeof V_139 ) ) {
V_198 = - V_9 ;
break;
}
V_189 = V_139 . V_213 == - 1 ? NULL : F_153 ( V_139 . V_213 ) ;
if ( F_72 ( V_189 ) ) {
V_198 = F_73 ( V_189 ) ;
break;
}
if ( V_189 != V_2 -> V_63 ) {
V_190 = V_2 -> V_63 ;
V_194 = V_2 -> V_62 ;
V_2 -> V_63 = V_189 ;
V_2 -> V_62 = V_189 ?
F_154 ( V_189 ) : NULL ;
} else
V_190 = V_189 ;
break;
case V_215 :
if ( F_6 ( & V_139 , V_4 , sizeof V_139 ) ) {
V_198 = - V_9 ;
break;
}
V_189 = V_139 . V_213 == - 1 ? NULL : F_153 ( V_139 . V_213 ) ;
if ( F_72 ( V_189 ) ) {
V_198 = F_73 ( V_189 ) ;
break;
}
if ( V_189 != V_2 -> error ) {
V_190 = V_2 -> error ;
V_2 -> error = V_189 ;
V_194 = V_2 -> V_60 ;
V_2 -> V_60 = V_189 ?
F_154 ( V_189 ) : NULL ;
} else
V_190 = V_189 ;
break;
case V_216 :
V_198 = F_5 ( V_2 , V_4 ) ;
break;
case V_217 :
V_198 = F_7 ( V_2 , V_14 , V_4 ) ;
break;
case V_218 :
if ( F_6 ( & V_6 , V_4 , sizeof( V_6 ) ) ) {
V_198 = - V_9 ;
break;
}
V_2 -> V_65 = V_6 . V_10 ;
break;
case V_219 :
V_6 . V_15 = V_14 ;
V_6 . V_10 = V_2 -> V_65 ;
if ( F_8 ( V_4 , & V_6 , sizeof( V_6 ) ) )
V_198 = - V_9 ;
break;
default:
V_198 = - V_18 ;
}
if ( V_192 && V_2 -> V_90 )
F_27 ( & V_2 -> V_27 ) ;
if ( V_194 )
F_92 ( V_194 ) ;
if ( V_190 )
F_93 ( V_190 ) ;
if ( V_191 && V_2 -> V_90 )
V_198 = F_25 ( & V_2 -> V_27 , V_2 -> V_61 ) ;
F_103 ( & V_2 -> V_85 ) ;
if ( V_192 && V_2 -> V_90 )
F_32 ( & V_2 -> V_27 ) ;
return V_198 ;
}
int F_155 ( struct V_38 * V_127 , bool V_220 )
{
struct V_107 * V_221 , * V_222 ;
int V_78 ;
V_221 = F_147 () ;
if ( ! V_221 )
return - V_84 ;
V_222 = V_127 -> V_67 ;
V_127 -> V_67 = V_221 ;
for ( V_78 = 0 ; V_78 < V_127 -> V_79 ; ++ V_78 ) {
F_102 ( & V_127 -> V_80 [ V_78 ] -> V_85 ) ;
V_127 -> V_80 [ V_78 ] -> V_67 = V_221 ;
F_103 ( & V_127 -> V_80 [ V_78 ] -> V_85 ) ;
}
F_86 ( V_222 ) ;
return 0 ;
}
long F_156 ( struct V_38 * V_127 , unsigned int V_188 , void T_1 * V_4 )
{
struct V_23 * V_189 , * V_190 = NULL ;
struct V_193 * V_194 = NULL ;
T_8 V_223 ;
long V_198 ;
int V_78 , V_213 ;
if ( V_188 == V_224 ) {
V_198 = F_69 ( V_127 ) ;
goto V_37;
}
V_198 = F_64 ( V_127 ) ;
if ( V_198 )
goto V_37;
switch ( V_188 ) {
case V_225 :
V_198 = F_148 ( V_127 , V_4 ) ;
break;
case V_226 :
if ( F_6 ( & V_223 , V_4 , sizeof V_223 ) ) {
V_198 = - V_9 ;
break;
}
if ( ( T_8 ) ( unsigned long ) V_223 != V_223 ) {
V_198 = - V_9 ;
break;
}
for ( V_78 = 0 ; V_78 < V_127 -> V_79 ; ++ V_78 ) {
struct V_1 * V_2 ;
void T_1 * V_227 = ( void T_1 * ) ( unsigned long ) V_223 ;
V_2 = V_127 -> V_80 [ V_78 ] ;
F_102 ( & V_2 -> V_85 ) ;
if ( V_2 -> V_7 && ! F_145 ( V_2 , V_227 ) )
V_198 = - V_9 ;
else
V_2 -> V_59 = V_227 ;
F_103 ( & V_2 -> V_85 ) ;
}
break;
case V_228 :
V_198 = F_151 ( V_213 , ( int T_1 * ) V_4 ) ;
if ( V_198 < 0 )
break;
V_189 = V_213 == - 1 ? NULL : F_153 ( V_213 ) ;
if ( F_72 ( V_189 ) ) {
V_198 = F_73 ( V_189 ) ;
break;
}
if ( V_189 != V_127 -> V_86 ) {
V_190 = V_127 -> V_86 ;
V_127 -> V_86 = V_189 ;
V_194 = V_127 -> V_64 ;
V_127 -> V_64 = V_189 ?
F_154 ( V_189 ) : NULL ;
} else
V_190 = V_189 ;
for ( V_78 = 0 ; V_78 < V_127 -> V_79 ; ++ V_78 ) {
F_102 ( & V_127 -> V_80 [ V_78 ] -> V_85 ) ;
V_127 -> V_80 [ V_78 ] -> V_64 = V_127 -> V_64 ;
F_103 ( & V_127 -> V_80 [ V_78 ] -> V_85 ) ;
}
if ( V_194 )
F_92 ( V_194 ) ;
if ( V_190 )
F_93 ( V_190 ) ;
break;
default:
V_198 = - V_18 ;
break;
}
V_37:
return V_198 ;
}
static int F_157 ( int V_229 , void T_1 * V_117 )
{
unsigned long log = ( unsigned long ) V_117 ;
struct V_230 * V_230 ;
void * V_227 ;
int V_231 = V_229 + ( log % V_232 ) * 8 ;
int V_198 ;
V_198 = F_158 ( log , 1 , 1 , & V_230 ) ;
if ( V_198 < 0 )
return V_198 ;
F_159 ( V_198 != 1 ) ;
V_227 = F_160 ( V_230 ) ;
F_161 ( V_231 , V_227 ) ;
F_162 ( V_227 ) ;
F_163 ( V_230 ) ;
F_164 ( V_230 ) ;
return 0 ;
}
static int F_165 ( void T_1 * V_59 ,
T_8 V_233 , T_8 V_234 )
{
T_8 V_235 = V_233 / V_120 ;
int V_198 ;
if ( ! V_234 )
return 0 ;
V_234 += V_233 % V_120 ;
for (; ; ) {
T_8 V_227 = ( T_8 ) ( unsigned long ) V_59 ;
T_8 log = V_227 + V_235 / 8 ;
int V_231 = V_235 % 8 ;
if ( ( T_8 ) ( unsigned long ) log != log )
return - V_9 ;
V_198 = F_157 ( V_231 , ( void T_1 * ) ( unsigned long ) log ) ;
if ( V_198 < 0 )
return V_198 ;
if ( V_234 <= V_120 )
break;
V_234 -= V_120 ;
V_235 += 1 ;
}
return V_198 ;
}
int F_166 ( struct V_1 * V_2 , struct V_236 * log ,
unsigned int V_237 , T_8 V_169 )
{
int V_78 , V_198 ;
F_50 () ;
for ( V_78 = 0 ; V_78 < V_237 ; ++ V_78 ) {
T_8 V_238 = F_167 ( log [ V_78 ] . V_169 , V_169 ) ;
V_198 = F_165 ( V_2 -> V_59 , log [ V_78 ] . V_117 , V_238 ) ;
if ( V_198 < 0 )
return V_198 ;
V_169 -= V_238 ;
if ( ! V_169 ) {
if ( V_2 -> V_64 )
F_168 ( V_2 -> V_64 , 1 ) ;
return 0 ;
}
}
F_169 () ;
return 0 ;
}
static int F_170 ( struct V_1 * V_2 )
{
void T_1 * V_49 ;
if ( F_171 ( V_2 , F_172 ( V_2 , V_2 -> V_55 ) ,
& V_2 -> V_49 -> V_36 ) < 0 )
return - V_9 ;
if ( F_173 ( V_2 -> V_56 ) ) {
F_50 () ;
V_49 = & V_2 -> V_49 -> V_36 ;
F_165 ( V_2 -> V_59 , V_2 -> V_57 +
( V_49 - ( void T_1 * ) V_2 -> V_49 ) ,
sizeof V_2 -> V_49 -> V_36 ) ;
if ( V_2 -> V_64 )
F_168 ( V_2 -> V_64 , 1 ) ;
}
return 0 ;
}
static int F_174 ( struct V_1 * V_2 , T_11 V_239 )
{
if ( F_171 ( V_2 , F_172 ( V_2 , V_2 -> V_51 ) ,
F_175 ( V_2 ) ) )
return - V_9 ;
if ( F_173 ( V_2 -> V_56 ) ) {
void T_1 * V_49 ;
F_50 () ;
V_49 = F_175 ( V_2 ) ;
F_165 ( V_2 -> V_59 , V_2 -> V_57 +
( V_49 - ( void T_1 * ) V_2 -> V_49 ) ,
sizeof * F_175 ( V_2 ) ) ;
if ( V_2 -> V_64 )
F_168 ( V_2 -> V_64 , 1 ) ;
}
return 0 ;
}
int F_176 ( struct V_1 * V_2 )
{
T_12 V_52 ;
int V_198 ;
bool V_16 = V_2 -> V_16 ;
if ( ! V_2 -> V_7 ) {
F_11 ( V_2 ) ;
return 0 ;
}
F_9 ( V_2 ) ;
V_198 = F_170 ( V_2 ) ;
if ( V_198 )
goto V_98;
V_2 -> V_54 = false ;
if ( ! V_2 -> V_67 &&
! F_97 ( V_155 , & V_2 -> V_49 -> V_14 , sizeof V_2 -> V_49 -> V_14 ) ) {
V_198 = - V_9 ;
goto V_98;
}
V_198 = F_177 ( V_2 , V_52 , & V_2 -> V_49 -> V_14 ) ;
if ( V_198 ) {
F_112 ( V_2 , L_5 ,
& V_2 -> V_49 -> V_14 ) ;
goto V_98;
}
V_2 -> V_52 = F_178 ( V_2 , V_52 ) ;
return 0 ;
V_98:
V_2 -> V_16 = V_16 ;
return V_198 ;
}
static int F_106 ( struct V_1 * V_2 , T_8 V_117 , T_2 V_169 ,
struct V_240 V_241 [] , int V_242 , int V_154 )
{
const struct V_109 * V_45 ;
struct V_38 * V_39 = V_2 -> V_39 ;
struct V_107 * V_66 = V_39 -> V_67 ? V_39 -> V_67 : V_39 -> V_66 ;
struct V_240 * V_243 ;
T_8 V_6 = 0 ;
int V_40 = 0 ;
while ( ( T_8 ) V_169 > V_6 ) {
T_8 V_103 ;
if ( F_173 ( V_40 >= V_242 ) ) {
V_40 = - V_199 ;
break;
}
V_45 = F_123 ( & V_66 -> V_110 ,
V_117 , V_117 + V_169 - 1 ) ;
if ( V_45 == NULL || V_45 -> V_126 > V_117 ) {
if ( V_66 != V_39 -> V_67 ) {
V_40 = - V_9 ;
break;
}
V_40 = - V_161 ;
break;
} else if ( ! ( V_45 -> V_145 & V_154 ) ) {
V_40 = - V_93 ;
break;
}
V_243 = V_241 + V_40 ;
V_103 = V_45 -> V_103 - V_117 + V_45 -> V_126 ;
V_243 -> V_142 = F_167 ( ( T_8 ) V_169 - V_6 , V_103 ) ;
V_243 -> V_143 = ( void T_1 * ) ( unsigned long )
( V_45 -> V_125 + V_117 - V_45 -> V_126 ) ;
V_6 += V_103 ;
V_117 += V_103 ;
++ V_40 ;
}
if ( V_40 == - V_161 )
F_139 ( V_2 , V_117 , V_154 ) ;
return V_40 ;
}
static unsigned F_179 ( struct V_1 * V_2 , struct V_164 * V_47 )
{
unsigned int V_244 ;
if ( ! ( V_47 -> V_36 & F_172 ( V_2 , V_245 ) ) )
return - 1U ;
V_244 = F_178 ( V_2 , V_47 -> V_244 ) ;
F_180 () ;
return V_244 ;
}
static int F_181 ( struct V_1 * V_2 ,
struct V_240 V_241 [] , unsigned int V_242 ,
unsigned int * V_246 , unsigned int * V_247 ,
struct V_236 * log , unsigned int * V_237 ,
struct V_164 * V_76 )
{
struct V_164 V_47 ;
unsigned int V_78 = 0 , V_248 , V_249 = 0 ;
T_2 V_169 = F_182 ( V_2 , V_76 -> V_169 ) ;
struct V_132 V_131 ;
int V_40 , V_154 ;
if ( F_173 ( V_169 % sizeof V_47 ) ) {
F_112 ( V_2 , L_6
L_7 ,
( unsigned long long ) V_169 ,
sizeof V_47 ) ;
return - V_13 ;
}
V_40 = F_106 ( V_2 , F_183 ( V_2 , V_76 -> V_117 ) , V_169 , V_2 -> V_76 ,
V_81 , V_140 ) ;
if ( F_173 ( V_40 < 0 ) ) {
if ( V_40 != - V_161 )
F_112 ( V_2 , L_8 , V_40 ) ;
return V_40 ;
}
F_108 ( & V_131 , V_141 , V_2 -> V_76 , V_40 , V_169 ) ;
F_180 () ;
V_248 = V_169 / sizeof V_47 ;
if ( F_173 ( V_248 > V_250 + 1 ) ) {
F_112 ( V_2 , L_9 ,
V_76 -> V_169 ) ;
return - V_184 ;
}
do {
unsigned V_251 = * V_247 + * V_246 ;
if ( F_173 ( ++ V_249 > V_248 ) ) {
F_112 ( V_2 , L_10
L_11 ,
V_78 , V_248 ) ;
return - V_13 ;
}
if ( F_173 ( F_113 ( & V_47 , sizeof( V_47 ) , & V_131 ) !=
sizeof( V_47 ) ) ) {
F_112 ( V_2 , L_12 ,
V_78 , ( T_10 ) F_183 ( V_2 , V_76 -> V_117 ) + V_78 * sizeof V_47 ) ;
return - V_13 ;
}
if ( F_173 ( V_47 . V_36 & F_172 ( V_2 , V_252 ) ) ) {
F_112 ( V_2 , L_13 ,
V_78 , ( T_10 ) F_183 ( V_2 , V_76 -> V_117 ) + V_78 * sizeof V_47 ) ;
return - V_13 ;
}
if ( V_47 . V_36 & F_172 ( V_2 , V_253 ) )
V_154 = V_136 ;
else
V_154 = V_140 ;
V_40 = F_106 ( V_2 , F_183 ( V_2 , V_47 . V_117 ) ,
F_182 ( V_2 , V_47 . V_169 ) , V_241 + V_251 ,
V_242 - V_251 , V_154 ) ;
if ( F_173 ( V_40 < 0 ) ) {
if ( V_40 != - V_161 )
F_112 ( V_2 , L_14 ,
V_40 , V_78 ) ;
return V_40 ;
}
if ( V_154 == V_136 ) {
* V_247 += V_40 ;
if ( F_173 ( log ) ) {
log [ * V_237 ] . V_117 = F_183 ( V_2 , V_47 . V_117 ) ;
log [ * V_237 ] . V_169 = F_182 ( V_2 , V_47 . V_169 ) ;
++ * V_237 ;
}
} else {
if ( F_173 ( * V_247 ) ) {
F_112 ( V_2 , L_15
L_16 , V_78 ) ;
return - V_13 ;
}
* V_246 += V_40 ;
}
} while ( ( V_78 = F_179 ( V_2 , & V_47 ) ) != - 1 );
return 0 ;
}
int F_184 ( struct V_1 * V_2 ,
struct V_240 V_241 [] , unsigned int V_242 ,
unsigned int * V_246 , unsigned int * V_247 ,
struct V_236 * log , unsigned int * V_237 )
{
struct V_164 V_47 ;
unsigned int V_78 , V_254 , V_249 = 0 ;
T_11 V_50 ;
T_12 V_51 ;
T_12 V_255 ;
int V_40 , V_154 ;
V_50 = V_2 -> V_50 ;
if ( F_173 ( F_177 ( V_2 , V_51 , & V_2 -> V_48 -> V_14 ) ) ) {
F_112 ( V_2 , L_17 ,
& V_2 -> V_48 -> V_14 ) ;
return - V_9 ;
}
V_2 -> V_51 = F_178 ( V_2 , V_51 ) ;
if ( F_173 ( ( T_11 ) ( V_2 -> V_51 - V_50 ) > V_2 -> V_10 ) ) {
F_112 ( V_2 , L_18 ,
V_50 , V_2 -> V_51 ) ;
return - V_9 ;
}
if ( V_2 -> V_51 == V_50 )
return V_2 -> V_10 ;
F_185 () ;
if ( F_173 ( F_177 ( V_2 , V_255 ,
& V_2 -> V_48 -> V_168 [ V_50 & ( V_2 -> V_10 - 1 ) ] ) ) ) {
F_112 ( V_2 , L_19 ,
V_50 ,
& V_2 -> V_48 -> V_168 [ V_50 % V_2 -> V_10 ] ) ;
return - V_9 ;
}
V_254 = F_178 ( V_2 , V_255 ) ;
if ( F_173 ( V_254 >= V_2 -> V_10 ) ) {
F_112 ( V_2 , L_20 ,
V_254 , V_2 -> V_10 ) ;
return - V_13 ;
}
* V_246 = * V_247 = 0 ;
if ( F_173 ( log ) )
* V_237 = 0 ;
V_78 = V_254 ;
do {
unsigned V_251 = * V_247 + * V_246 ;
if ( F_173 ( V_78 >= V_2 -> V_10 ) ) {
F_112 ( V_2 , L_21 ,
V_78 , V_2 -> V_10 , V_254 ) ;
return - V_13 ;
}
if ( F_173 ( ++ V_249 > V_2 -> V_10 ) ) {
F_112 ( V_2 , L_10
L_22 ,
V_78 , V_2 -> V_10 , V_254 ) ;
return - V_13 ;
}
V_40 = F_110 ( V_2 , & V_47 , V_2 -> V_47 + V_78 ,
sizeof V_47 ) ;
if ( F_173 ( V_40 ) ) {
F_112 ( V_2 , L_23 ,
V_78 , V_2 -> V_47 + V_78 ) ;
return - V_9 ;
}
if ( V_47 . V_36 & F_172 ( V_2 , V_252 ) ) {
V_40 = F_181 ( V_2 , V_241 , V_242 ,
V_246 , V_247 ,
log , V_237 , & V_47 ) ;
if ( F_173 ( V_40 < 0 ) ) {
if ( V_40 != - V_161 )
F_112 ( V_2 , L_24
L_25 , V_78 ) ;
return V_40 ;
}
continue;
}
if ( V_47 . V_36 & F_172 ( V_2 , V_253 ) )
V_154 = V_136 ;
else
V_154 = V_140 ;
V_40 = F_106 ( V_2 , F_183 ( V_2 , V_47 . V_117 ) ,
F_182 ( V_2 , V_47 . V_169 ) , V_241 + V_251 ,
V_242 - V_251 , V_154 ) ;
if ( F_173 ( V_40 < 0 ) ) {
if ( V_40 != - V_161 )
F_112 ( V_2 , L_26 ,
V_40 , V_78 ) ;
return V_40 ;
}
if ( V_154 == V_136 ) {
* V_247 += V_40 ;
if ( F_173 ( log ) ) {
log [ * V_237 ] . V_117 = F_183 ( V_2 , V_47 . V_117 ) ;
log [ * V_237 ] . V_169 = F_182 ( V_2 , V_47 . V_169 ) ;
++ * V_237 ;
}
} else {
if ( F_173 ( * V_247 ) ) {
F_112 ( V_2 , L_27
L_28 , V_78 ) ;
return - V_13 ;
}
* V_246 += V_40 ;
}
} while ( ( V_78 = F_179 ( V_2 , & V_47 ) ) != - 1 );
V_2 -> V_50 ++ ;
F_159 ( ! ( V_2 -> V_55 & V_256 ) ) ;
return V_254 ;
}
void F_186 ( struct V_1 * V_2 , int V_104 )
{
V_2 -> V_50 -= V_104 ;
}
int F_187 ( struct V_1 * V_2 , unsigned int V_254 , int V_169 )
{
struct V_257 V_77 = {
F_188 ( V_2 , V_254 ) ,
F_188 (vq, len)
} ;
return F_189 ( V_2 , & V_77 , 1 ) ;
}
static int F_190 ( struct V_1 * V_2 ,
struct V_257 * V_77 ,
unsigned V_248 )
{
struct V_257 T_1 * V_49 ;
T_11 V_258 , V_259 ;
int V_126 ;
V_126 = V_2 -> V_52 & ( V_2 -> V_10 - 1 ) ;
V_49 = V_2 -> V_49 -> V_168 + V_126 ;
if ( V_248 == 1 ) {
if ( F_171 ( V_2 , V_77 [ 0 ] . V_260 , & V_49 -> V_260 ) ) {
F_112 ( V_2 , L_29 ) ;
return - V_9 ;
}
if ( F_171 ( V_2 , V_77 [ 0 ] . V_169 , & V_49 -> V_169 ) ) {
F_112 ( V_2 , L_30 ) ;
return - V_9 ;
}
} else if ( F_104 ( V_2 , V_49 , V_77 , V_248 * sizeof *V_49 ) ) {
F_112 ( V_2 , L_31 ) ;
return - V_9 ;
}
if ( F_173 ( V_2 -> V_56 ) ) {
F_50 () ;
F_165 ( V_2 -> V_59 ,
V_2 -> V_57 +
( ( void T_1 * ) V_49 - ( void T_1 * ) V_2 -> V_49 ) ,
V_248 * sizeof *V_49 ) ;
}
V_258 = V_2 -> V_52 ;
V_259 = ( V_2 -> V_52 += V_248 ) ;
if ( F_173 ( ( T_11 ) ( V_259 - V_2 -> V_53 ) < ( T_11 ) ( V_259 - V_258 ) ) )
V_2 -> V_54 = false ;
return 0 ;
}
int F_189 ( struct V_1 * V_2 , struct V_257 * V_77 ,
unsigned V_248 )
{
int V_126 , V_104 , V_198 ;
V_126 = V_2 -> V_52 & ( V_2 -> V_10 - 1 ) ;
V_104 = V_2 -> V_10 - V_126 ;
if ( V_104 < V_248 ) {
V_198 = F_190 ( V_2 , V_77 , V_104 ) ;
if ( V_198 < 0 )
return V_198 ;
V_77 += V_104 ;
V_248 -= V_104 ;
}
V_198 = F_190 ( V_2 , V_77 , V_248 ) ;
F_50 () ;
if ( F_171 ( V_2 , F_172 ( V_2 , V_2 -> V_52 ) ,
& V_2 -> V_49 -> V_14 ) ) {
F_112 ( V_2 , L_32 ) ;
return - V_9 ;
}
if ( F_173 ( V_2 -> V_56 ) ) {
F_165 ( V_2 -> V_59 ,
V_2 -> V_57 + F_149 ( struct V_166 , V_14 ) ,
sizeof V_2 -> V_49 -> V_14 ) ;
if ( V_2 -> V_64 )
F_168 ( V_2 -> V_64 , 1 ) ;
}
return V_198 ;
}
static bool F_191 ( struct V_38 * V_39 , struct V_1 * V_2 )
{
T_13 V_258 , V_259 ;
T_12 V_261 ;
bool V_262 ;
F_34 () ;
if ( F_10 ( V_2 , V_263 ) &&
F_173 ( V_2 -> V_51 == V_2 -> V_50 ) )
return true ;
if ( ! F_10 ( V_2 , V_167 ) ) {
T_12 V_36 ;
if ( F_177 ( V_2 , V_36 , & V_2 -> V_48 -> V_36 ) ) {
F_112 ( V_2 , L_33 ) ;
return true ;
}
return ! ( V_36 & F_172 ( V_2 , V_264 ) ) ;
}
V_258 = V_2 -> V_53 ;
V_262 = V_2 -> V_54 ;
V_259 = V_2 -> V_53 = V_2 -> V_52 ;
V_2 -> V_54 = true ;
if ( F_173 ( ! V_262 ) )
return true ;
if ( F_177 ( V_2 , V_261 , F_192 ( V_2 ) ) ) {
F_112 ( V_2 , L_34 ) ;
return true ;
}
return F_193 ( F_178 ( V_2 , V_261 ) , V_259 , V_258 ) ;
}
void F_194 ( struct V_38 * V_39 , struct V_1 * V_2 )
{
if ( V_2 -> V_62 && F_191 ( V_39 , V_2 ) )
F_168 ( V_2 -> V_62 , 1 ) ;
}
void F_195 ( struct V_38 * V_39 ,
struct V_1 * V_2 ,
unsigned int V_254 , int V_169 )
{
F_187 ( V_2 , V_254 , V_169 ) ;
F_194 ( V_39 , V_2 ) ;
}
void F_196 ( struct V_38 * V_39 ,
struct V_1 * V_2 ,
struct V_257 * V_77 , unsigned V_248 )
{
F_189 ( V_2 , V_77 , V_248 ) ;
F_194 ( V_39 , V_2 ) ;
}
bool F_197 ( struct V_38 * V_39 , struct V_1 * V_2 )
{
T_12 V_51 ;
int V_198 ;
V_198 = F_177 ( V_2 , V_51 , & V_2 -> V_48 -> V_14 ) ;
if ( V_198 )
return false ;
return F_178 ( V_2 , V_51 ) == V_2 -> V_51 ;
}
bool F_198 ( struct V_38 * V_39 , struct V_1 * V_2 )
{
T_12 V_51 ;
int V_198 ;
if ( ! ( V_2 -> V_55 & V_256 ) )
return false ;
V_2 -> V_55 &= ~ V_256 ;
if ( ! F_10 ( V_2 , V_167 ) ) {
V_198 = F_170 ( V_2 ) ;
if ( V_198 ) {
F_112 ( V_2 , L_35 ,
& V_2 -> V_49 -> V_36 , V_198 ) ;
return false ;
}
} else {
V_198 = F_174 ( V_2 , V_2 -> V_51 ) ;
if ( V_198 ) {
F_112 ( V_2 , L_36 ,
F_175 ( V_2 ) , V_198 ) ;
return false ;
}
}
F_34 () ;
V_198 = F_177 ( V_2 , V_51 , & V_2 -> V_48 -> V_14 ) ;
if ( V_198 ) {
F_112 ( V_2 , L_37 ,
& V_2 -> V_48 -> V_14 , V_198 ) ;
return false ;
}
return F_178 ( V_2 , V_51 ) != V_2 -> V_51 ;
}
void F_199 ( struct V_38 * V_39 , struct V_1 * V_2 )
{
int V_198 ;
if ( V_2 -> V_55 & V_256 )
return;
V_2 -> V_55 |= V_256 ;
if ( ! F_10 ( V_2 , V_167 ) ) {
V_198 = F_170 ( V_2 ) ;
if ( V_198 )
F_112 ( V_2 , L_35 ,
& V_2 -> V_49 -> V_36 , V_198 ) ;
}
}
struct V_114 * F_140 ( struct V_1 * V_2 , int type )
{
struct V_114 * V_45 = F_57 ( sizeof *V_45 , V_82 ) ;
if ( ! V_45 )
return NULL ;
V_45 -> V_2 = V_2 ;
V_45 -> V_150 . type = type ;
return V_45 ;
}
void F_138 ( struct V_38 * V_39 , struct V_265 * V_254 ,
struct V_114 * V_45 )
{
F_90 ( & V_39 -> V_89 ) ;
F_120 ( & V_45 -> V_45 , V_254 ) ;
F_91 ( & V_39 -> V_89 ) ;
F_94 ( & V_39 -> V_29 , V_91 | V_116 ) ;
}
struct V_114 * F_135 ( struct V_38 * V_39 ,
struct V_265 * V_254 )
{
struct V_114 * V_45 = NULL ;
F_90 ( & V_39 -> V_89 ) ;
if ( ! F_131 ( V_254 ) ) {
V_45 = F_118 ( V_254 , struct V_114 ,
V_45 ) ;
F_85 ( & V_45 -> V_45 ) ;
}
F_91 ( & V_39 -> V_89 ) ;
return V_45 ;
}
static int T_14 F_200 ( void )
{
return 0 ;
}
static void T_15 F_201 ( void )
{
}
