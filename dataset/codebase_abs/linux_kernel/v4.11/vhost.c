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
V_2 -> V_16 = F_10 ( V_2 , V_17 )
|| F_2 () ;
}
static void F_11 ( struct V_1 * V_2 )
{
F_9 ( V_2 ) ;
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
F_34 ( & V_20 -> V_45 , & V_39 -> V_46 ) ;
F_35 ( V_39 -> V_44 ) ;
}
}
bool F_36 ( struct V_38 * V_39 )
{
return ! F_37 ( & V_39 -> V_46 ) ;
}
void F_18 ( struct V_26 * V_27 )
{
F_30 ( V_27 -> V_39 , & V_27 -> V_20 ) ;
}
static void F_38 ( struct V_1 * V_2 )
{
int V_47 ;
for ( V_47 = 0 ; V_47 < V_48 ; V_47 ++ )
V_2 -> V_49 [ V_47 ] = NULL ;
}
static void F_39 ( struct V_38 * V_50 )
{
int V_51 ;
for ( V_51 = 0 ; V_51 < V_50 -> V_52 ; ++ V_51 )
F_38 ( V_50 -> V_53 [ V_51 ] ) ;
}
static void F_40 ( struct V_38 * V_39 ,
struct V_1 * V_2 )
{
V_2 -> V_10 = 1 ;
V_2 -> V_54 = NULL ;
V_2 -> V_55 = NULL ;
V_2 -> V_56 = NULL ;
V_2 -> V_57 = 0 ;
V_2 -> V_58 = 0 ;
V_2 -> V_59 = 0 ;
V_2 -> V_60 = 0 ;
V_2 -> V_61 = 0 ;
V_2 -> V_62 = false ;
V_2 -> V_63 = 0 ;
V_2 -> V_64 = false ;
V_2 -> V_65 = - 1ull ;
V_2 -> V_7 = NULL ;
V_2 -> V_66 = 0 ;
V_2 -> V_67 = NULL ;
V_2 -> V_68 = NULL ;
V_2 -> error = NULL ;
V_2 -> V_69 = NULL ;
V_2 -> V_70 = NULL ;
V_2 -> V_71 = NULL ;
V_2 -> V_72 = NULL ;
F_11 ( V_2 ) ;
F_1 ( V_2 ) ;
V_2 -> V_73 = 0 ;
V_2 -> V_74 = NULL ;
V_2 -> V_75 = NULL ;
F_38 ( V_2 ) ;
}
static int F_41 ( void * V_76 )
{
struct V_38 * V_39 = V_76 ;
struct V_19 * V_20 , * V_77 ;
struct V_78 * V_45 ;
T_7 V_79 = F_42 () ;
F_43 ( V_80 ) ;
F_44 ( V_39 -> V_81 ) ;
for (; ; ) {
F_45 ( V_82 ) ;
if ( F_46 () ) {
F_47 ( V_83 ) ;
break;
}
V_45 = F_48 ( & V_39 -> V_46 ) ;
if ( ! V_45 )
F_49 () ;
V_45 = F_50 ( V_45 ) ;
F_51 () ;
F_52 (work, work_next, node, node) {
F_20 ( V_35 , & V_20 -> V_36 ) ;
F_47 ( V_83 ) ;
V_20 -> V_34 ( V_20 ) ;
if ( F_53 () )
F_49 () ;
}
}
F_54 ( V_39 -> V_81 ) ;
F_43 ( V_79 ) ;
return 0 ;
}
static void F_55 ( struct V_1 * V_2 )
{
F_56 ( V_2 -> V_84 ) ;
V_2 -> V_84 = NULL ;
F_56 ( V_2 -> log ) ;
V_2 -> log = NULL ;
F_56 ( V_2 -> V_85 ) ;
V_2 -> V_85 = NULL ;
}
static long F_57 ( struct V_38 * V_39 )
{
struct V_1 * V_2 ;
int V_51 ;
for ( V_51 = 0 ; V_51 < V_39 -> V_52 ; ++ V_51 ) {
V_2 = V_39 -> V_53 [ V_51 ] ;
V_2 -> V_84 = F_58 ( sizeof * V_2 -> V_84 * V_86 ,
V_87 ) ;
V_2 -> log = F_58 ( sizeof * V_2 -> log * V_86 , V_87 ) ;
V_2 -> V_85 = F_58 ( sizeof * V_2 -> V_85 * V_86 , V_87 ) ;
if ( ! V_2 -> V_84 || ! V_2 -> log || ! V_2 -> V_85 )
goto V_88;
}
return 0 ;
V_88:
for (; V_51 >= 0 ; -- V_51 )
F_55 ( V_39 -> V_53 [ V_51 ] ) ;
return - V_89 ;
}
static void F_59 ( struct V_38 * V_39 )
{
int V_51 ;
for ( V_51 = 0 ; V_51 < V_39 -> V_52 ; ++ V_51 )
F_55 ( V_39 -> V_53 [ V_51 ] ) ;
}
void F_60 ( struct V_38 * V_39 ,
struct V_1 * * V_53 , int V_52 )
{
struct V_1 * V_2 ;
int V_51 ;
V_39 -> V_53 = V_53 ;
V_39 -> V_52 = V_52 ;
F_61 ( & V_39 -> V_90 ) ;
V_39 -> V_72 = NULL ;
V_39 -> V_91 = NULL ;
V_39 -> V_74 = NULL ;
V_39 -> V_75 = NULL ;
V_39 -> V_81 = NULL ;
V_39 -> V_44 = NULL ;
F_62 ( & V_39 -> V_46 ) ;
F_21 ( & V_39 -> V_29 ) ;
F_63 ( & V_39 -> V_92 ) ;
F_63 ( & V_39 -> V_93 ) ;
F_64 ( & V_39 -> V_94 ) ;
for ( V_51 = 0 ; V_51 < V_39 -> V_52 ; ++ V_51 ) {
V_2 = V_39 -> V_53 [ V_51 ] ;
V_2 -> log = NULL ;
V_2 -> V_84 = NULL ;
V_2 -> V_85 = NULL ;
V_2 -> V_39 = V_39 ;
F_61 ( & V_2 -> V_90 ) ;
F_40 ( V_39 , V_2 ) ;
if ( V_2 -> V_95 )
F_22 ( & V_2 -> V_27 , V_2 -> V_95 ,
V_96 , V_39 ) ;
}
}
long F_65 ( struct V_38 * V_39 )
{
return V_39 -> V_81 == V_97 -> V_81 ? 0 : - V_98 ;
}
static void F_66 ( struct V_19 * V_20 )
{
struct V_99 * V_6 ;
V_6 = F_13 ( V_20 , struct V_99 , V_20 ) ;
V_6 -> V_40 = F_67 ( V_6 -> V_100 , V_97 ) ;
}
static int F_68 ( struct V_38 * V_39 )
{
struct V_99 V_101 ;
V_101 . V_100 = V_97 ;
F_19 ( & V_101 . V_20 , F_66 ) ;
F_30 ( V_39 , & V_101 . V_20 ) ;
F_28 ( V_39 , & V_101 . V_20 ) ;
return V_101 . V_40 ;
}
bool F_69 ( struct V_38 * V_39 )
{
return V_39 -> V_81 ;
}
long F_70 ( struct V_38 * V_39 )
{
struct V_102 * V_44 ;
int V_103 ;
if ( F_69 ( V_39 ) ) {
V_103 = - V_8 ;
goto V_104;
}
V_39 -> V_81 = F_71 ( V_97 ) ;
V_44 = F_72 ( F_41 , V_39 , L_1 , V_97 -> V_105 ) ;
if ( F_73 ( V_44 ) ) {
V_103 = F_74 ( V_44 ) ;
goto V_106;
}
V_39 -> V_44 = V_44 ;
F_35 ( V_44 ) ;
V_103 = F_68 ( V_39 ) ;
if ( V_103 )
goto V_107;
V_103 = F_57 ( V_39 ) ;
if ( V_103 )
goto V_107;
return 0 ;
V_107:
F_75 ( V_44 ) ;
V_39 -> V_44 = NULL ;
V_106:
if ( V_39 -> V_81 )
F_76 ( V_39 -> V_81 ) ;
V_39 -> V_81 = NULL ;
V_104:
return V_103 ;
}
static void * F_77 ( unsigned long V_108 )
{
void * V_109 = F_78 ( V_108 , V_87 | V_110 | V_111 ) ;
if ( ! V_109 )
V_109 = F_79 ( V_108 ) ;
return V_109 ;
}
struct V_112 * F_80 ( void )
{
return F_77 ( sizeof( struct V_112 ) ) ;
}
void F_81 ( struct V_38 * V_39 , struct V_112 * V_74 )
{
int V_51 ;
F_82 ( V_39 , true ) ;
F_63 ( & V_74 -> V_113 ) ;
V_39 -> V_74 = V_74 ;
for ( V_51 = 0 ; V_51 < V_39 -> V_52 ; ++ V_51 )
V_39 -> V_53 [ V_51 ] -> V_74 = V_74 ;
}
void F_83 ( struct V_38 * V_39 )
{
int V_51 ;
for ( V_51 = 0 ; V_51 < V_39 -> V_52 ; ++ V_51 ) {
if ( V_39 -> V_53 [ V_51 ] -> V_69 && V_39 -> V_53 [ V_51 ] -> V_95 ) {
F_27 ( & V_39 -> V_53 [ V_51 ] -> V_27 ) ;
F_32 ( & V_39 -> V_53 [ V_51 ] -> V_27 ) ;
}
}
}
static void F_84 ( struct V_112 * V_74 ,
struct V_114 * V_45 )
{
F_85 ( V_45 , & V_74 -> V_115 ) ;
F_86 ( & V_45 -> V_116 ) ;
F_56 ( V_45 ) ;
V_74 -> V_117 -- ;
}
static void F_87 ( struct V_112 * V_74 )
{
struct V_114 * V_45 , * V_118 ;
if ( ! V_74 )
return;
F_88 (node, tmp, &umem->umem_list, link)
F_84 ( V_74 , V_45 ) ;
F_89 ( V_74 ) ;
}
static void F_90 ( struct V_38 * V_39 )
{
struct V_119 * V_45 , * V_109 ;
F_91 ( & V_39 -> V_94 ) ;
F_88 (node, n, &dev->read_list, node) {
F_86 ( & V_45 -> V_45 ) ;
F_56 ( V_45 ) ;
}
F_88 (node, n, &dev->pending_list, node) {
F_86 ( & V_45 -> V_45 ) ;
F_56 ( V_45 ) ;
}
F_92 ( & V_39 -> V_94 ) ;
}
void F_82 ( struct V_38 * V_39 , bool V_120 )
{
int V_51 ;
for ( V_51 = 0 ; V_51 < V_39 -> V_52 ; ++ V_51 ) {
if ( V_39 -> V_53 [ V_51 ] -> V_68 )
F_93 ( V_39 -> V_53 [ V_51 ] -> V_68 ) ;
if ( V_39 -> V_53 [ V_51 ] -> error )
F_94 ( V_39 -> V_53 [ V_51 ] -> error ) ;
if ( V_39 -> V_53 [ V_51 ] -> V_69 )
F_94 ( V_39 -> V_53 [ V_51 ] -> V_69 ) ;
if ( V_39 -> V_53 [ V_51 ] -> V_70 )
F_93 ( V_39 -> V_53 [ V_51 ] -> V_70 ) ;
if ( V_39 -> V_53 [ V_51 ] -> V_71 )
F_94 ( V_39 -> V_53 [ V_51 ] -> V_71 ) ;
F_40 ( V_39 , V_39 -> V_53 [ V_51 ] ) ;
}
F_59 ( V_39 ) ;
if ( V_39 -> V_72 )
F_93 ( V_39 -> V_72 ) ;
V_39 -> V_72 = NULL ;
if ( V_39 -> V_91 )
F_94 ( V_39 -> V_91 ) ;
V_39 -> V_91 = NULL ;
F_87 ( V_39 -> V_74 ) ;
V_39 -> V_74 = NULL ;
F_87 ( V_39 -> V_75 ) ;
V_39 -> V_75 = NULL ;
F_90 ( V_39 ) ;
F_95 ( & V_39 -> V_29 , V_96 | V_121 ) ;
F_96 ( ! F_37 ( & V_39 -> V_46 ) ) ;
if ( V_39 -> V_44 ) {
F_75 ( V_39 -> V_44 ) ;
V_39 -> V_44 = NULL ;
}
if ( V_39 -> V_81 )
F_76 ( V_39 -> V_81 ) ;
V_39 -> V_81 = NULL ;
}
static int F_97 ( void T_1 * V_67 , T_8 V_122 , unsigned long V_123 )
{
T_8 V_124 = V_122 / V_125 / 8 ;
if ( V_124 > V_126 - ( unsigned long ) V_67 ||
V_124 + ( unsigned long ) V_67 > V_126 )
return 0 ;
return F_98 ( V_127 , V_67 + V_124 ,
( V_123 + V_125 * 8 - 1 ) / V_125 / 8 ) ;
}
static bool F_99 ( T_8 V_128 , T_8 V_108 )
{
return V_128 > V_126 || V_108 > V_126 || V_128 > V_126 - V_108 ;
}
static int F_100 ( void T_1 * V_67 , struct V_112 * V_74 ,
int V_129 )
{
struct V_114 * V_45 ;
if ( ! V_74 )
return 0 ;
F_101 (node, &umem->umem_list, link) {
unsigned long V_124 = V_45 -> V_130 ;
if ( F_99 ( V_45 -> V_130 , V_45 -> V_108 ) )
return 0 ;
if ( ! F_98 ( V_127 , ( void T_1 * ) V_124 ,
V_45 -> V_108 ) )
return 0 ;
else if ( V_129 && ! F_97 ( V_67 ,
V_45 -> V_131 ,
V_45 -> V_108 ) )
return 0 ;
}
return 1 ;
}
static inline void T_1 * F_102 ( struct V_1 * V_2 ,
T_8 V_122 , unsigned int V_108 ,
int type )
{
const struct V_114 * V_45 = V_2 -> V_49 [ type ] ;
if ( ! V_45 )
return NULL ;
return ( void * ) ( V_132 ) ( V_45 -> V_130 + V_122 - V_45 -> V_131 ) ;
}
static int F_103 ( struct V_38 * V_50 , struct V_112 * V_74 ,
int V_129 )
{
int V_51 ;
for ( V_51 = 0 ; V_51 < V_50 -> V_52 ; ++ V_51 ) {
int V_133 ;
bool log ;
F_104 ( & V_50 -> V_53 [ V_51 ] -> V_90 ) ;
log = V_129 || F_10 ( V_50 -> V_53 [ V_51 ] , V_134 ) ;
if ( V_50 -> V_53 [ V_51 ] -> V_7 )
V_133 = F_100 ( V_50 -> V_53 [ V_51 ] -> V_67 ,
V_74 , log ) ;
else
V_133 = 1 ;
F_105 ( & V_50 -> V_53 [ V_51 ] -> V_90 ) ;
if ( ! V_133 )
return 0 ;
}
return 1 ;
}
static int F_106 ( struct V_1 * V_2 , void T_1 * V_135 ,
const void * V_136 , unsigned V_108 )
{
int V_40 ;
if ( ! V_2 -> V_75 )
return F_107 ( V_135 , V_136 , V_108 ) ;
else {
struct V_137 V_138 ;
void T_1 * V_128 = F_102 ( V_2 ,
( T_8 ) ( V_132 ) V_135 , V_108 ,
V_139 ) ;
if ( V_128 )
return F_107 ( V_128 , V_136 , V_108 ) ;
V_40 = F_108 ( V_2 , ( T_8 ) ( V_132 ) V_135 , V_108 , V_2 -> V_140 ,
F_109 ( V_2 -> V_140 ) ,
V_141 ) ;
if ( V_40 < 0 )
goto V_142;
F_110 ( & V_138 , V_143 , V_2 -> V_140 , V_40 , V_108 ) ;
V_40 = F_111 ( V_136 , V_108 , & V_138 ) ;
if ( V_40 == V_108 )
V_40 = 0 ;
}
V_142:
return V_40 ;
}
static int F_112 ( struct V_1 * V_2 , void * V_135 ,
void T_1 * V_136 , unsigned V_108 )
{
int V_40 ;
if ( ! V_2 -> V_75 )
return F_113 ( V_135 , V_136 , V_108 ) ;
else {
void T_1 * V_128 = F_102 ( V_2 ,
( T_8 ) ( V_132 ) V_136 , V_108 ,
V_139 ) ;
struct V_137 V_144 ;
if ( V_128 )
return F_113 ( V_135 , V_128 , V_108 ) ;
V_40 = F_108 ( V_2 , ( T_8 ) ( V_132 ) V_136 , V_108 , V_2 -> V_140 ,
F_109 ( V_2 -> V_140 ) ,
V_145 ) ;
if ( V_40 < 0 ) {
F_114 ( V_2 , L_2
L_3 , V_136 ,
( unsigned long long ) V_108 ) ;
goto V_142;
}
F_110 ( & V_144 , V_146 , V_2 -> V_140 , V_40 , V_108 ) ;
V_40 = F_115 ( V_135 , V_108 , & V_144 ) ;
if ( V_40 == V_108 )
V_40 = 0 ;
}
V_142:
return V_40 ;
}
static void T_1 * F_116 ( struct V_1 * V_2 ,
void T_1 * V_122 , unsigned int V_108 ,
int type )
{
int V_40 ;
V_40 = F_108 ( V_2 , ( T_8 ) ( V_132 ) V_122 , V_108 , V_2 -> V_140 ,
F_109 ( V_2 -> V_140 ) ,
V_145 ) ;
if ( V_40 < 0 ) {
F_114 ( V_2 , L_2
L_3 , V_122 ,
( unsigned long long ) V_108 ) ;
return NULL ;
}
if ( V_40 != 1 || V_2 -> V_140 [ 0 ] . V_147 != V_108 ) {
F_114 ( V_2 , L_4
L_3 , V_122 ,
( unsigned long long ) V_108 ) ;
return NULL ;
}
return V_2 -> V_140 [ 0 ] . V_148 ;
}
static inline void T_1 * F_117 ( struct V_1 * V_2 ,
void * V_122 , unsigned int V_108 ,
int type )
{
void T_1 * V_128 = F_102 ( V_2 ,
( T_8 ) ( V_132 ) V_122 , V_108 , type ) ;
if ( V_128 )
return V_128 ;
return F_116 ( V_2 , V_122 , V_108 , type ) ;
}
static void F_118 ( struct V_38 * V_50 )
{
int V_51 = 0 ;
for ( V_51 = 0 ; V_51 < V_50 -> V_52 ; ++ V_51 )
F_104 ( & V_50 -> V_53 [ V_51 ] -> V_90 ) ;
}
static void F_119 ( struct V_38 * V_50 )
{
int V_51 = 0 ;
for ( V_51 = 0 ; V_51 < V_50 -> V_52 ; ++ V_51 )
F_105 ( & V_50 -> V_53 [ V_51 ] -> V_90 ) ;
}
static int F_120 ( struct V_112 * V_74 ,
T_8 V_131 , T_8 V_108 , T_8 V_149 ,
T_8 V_130 , int V_150 )
{
struct V_114 * V_118 , * V_45 = F_58 ( sizeof( * V_45 ) , V_151 ) ;
if ( ! V_45 )
return - V_89 ;
if ( V_74 -> V_117 == V_152 ) {
V_118 = F_121 ( & V_74 -> V_113 , F_122 ( * V_118 ) , V_116 ) ;
F_84 ( V_74 , V_118 ) ;
}
V_45 -> V_131 = V_131 ;
V_45 -> V_108 = V_108 ;
V_45 -> V_153 = V_149 ;
V_45 -> V_130 = V_130 ;
V_45 -> V_150 = V_150 ;
F_63 ( & V_45 -> V_116 ) ;
F_123 ( & V_45 -> V_116 , & V_74 -> V_113 ) ;
F_124 ( V_45 , & V_74 -> V_115 ) ;
V_74 -> V_117 ++ ;
return 0 ;
}
static void F_125 ( struct V_112 * V_74 ,
T_8 V_131 , T_8 V_149 )
{
struct V_114 * V_45 ;
while ( ( V_45 = F_126 ( & V_74 -> V_115 ,
V_131 , V_149 ) ) )
F_84 ( V_74 , V_45 ) ;
}
static void F_127 ( struct V_38 * V_50 ,
struct V_154 * V_155 )
{
struct V_119 * V_45 , * V_109 ;
F_91 ( & V_50 -> V_94 ) ;
F_88 (node, n, &d->pending_list, node) {
struct V_154 * V_156 = & V_45 -> V_155 . V_75 ;
if ( V_155 -> V_157 <= V_156 -> V_157 &&
V_155 -> V_157 + V_155 -> V_108 - 1 > V_156 -> V_157 &&
V_156 -> type == V_158 ) {
F_18 ( & V_45 -> V_2 -> V_27 ) ;
F_86 ( & V_45 -> V_45 ) ;
F_56 ( V_45 ) ;
}
}
F_92 ( & V_50 -> V_94 ) ;
}
static int F_128 ( T_8 V_128 , T_8 V_108 , int V_159 )
{
unsigned long V_124 = V_128 ;
if ( F_99 ( V_128 , V_108 ) )
return - V_9 ;
if ( ( V_159 & V_145 ) &&
! F_98 ( V_160 , ( void T_1 * ) V_124 , V_108 ) )
return - V_9 ;
if ( ( V_159 & V_141 ) &&
! F_98 ( V_127 , ( void T_1 * ) V_124 , V_108 ) )
return - V_9 ;
return 0 ;
}
static int F_129 ( struct V_38 * V_39 ,
struct V_154 * V_155 )
{
int V_40 = 0 ;
F_118 ( V_39 ) ;
switch ( V_155 -> type ) {
case V_161 :
if ( ! V_39 -> V_75 ) {
V_40 = - V_9 ;
break;
}
if ( F_128 ( V_155 -> V_128 , V_155 -> V_108 , V_155 -> V_150 ) ) {
V_40 = - V_9 ;
break;
}
F_39 ( V_39 ) ;
if ( F_120 ( V_39 -> V_75 , V_155 -> V_157 , V_155 -> V_108 ,
V_155 -> V_157 + V_155 -> V_108 - 1 ,
V_155 -> V_128 , V_155 -> V_150 ) ) {
V_40 = - V_89 ;
break;
}
F_127 ( V_39 , V_155 ) ;
break;
case V_162 :
F_39 ( V_39 ) ;
F_125 ( V_39 -> V_75 , V_155 -> V_157 ,
V_155 -> V_157 + V_155 -> V_108 - 1 ) ;
break;
default:
V_40 = - V_13 ;
break;
}
F_119 ( V_39 ) ;
return V_40 ;
}
T_9 F_130 ( struct V_38 * V_39 ,
struct V_137 * V_136 )
{
struct V_119 V_45 ;
unsigned V_108 = sizeof( struct V_163 ) ;
T_10 V_40 ;
int V_103 ;
if ( F_131 ( V_136 ) < V_108 )
return 0 ;
V_40 = F_115 ( & V_45 . V_155 , V_108 , V_136 ) ;
if ( V_40 != V_108 )
goto V_37;
switch ( V_45 . V_155 . type ) {
case V_164 :
V_103 = F_129 ( V_39 , & V_45 . V_155 . V_75 ) ;
if ( V_103 )
V_40 = V_103 ;
break;
default:
V_40 = - V_13 ;
break;
}
V_37:
return V_40 ;
}
unsigned int F_132 ( struct V_23 * V_23 , struct V_38 * V_39 ,
T_4 * V_29 )
{
unsigned int V_33 = 0 ;
F_133 ( V_23 , & V_39 -> V_29 , V_29 ) ;
if ( ! F_134 ( & V_39 -> V_92 ) )
V_33 |= V_96 | V_121 ;
return V_33 ;
}
T_9 F_135 ( struct V_38 * V_39 , struct V_137 * V_135 ,
int V_165 )
{
F_136 ( V_29 ) ;
struct V_119 * V_45 ;
T_9 V_40 = 0 ;
unsigned V_108 = sizeof( struct V_163 ) ;
if ( F_131 ( V_135 ) < V_108 )
return 0 ;
while ( 1 ) {
if ( ! V_165 )
F_137 ( & V_39 -> V_29 , & V_29 ,
V_82 ) ;
V_45 = F_138 ( V_39 , & V_39 -> V_92 ) ;
if ( V_45 )
break;
if ( V_165 ) {
V_40 = - V_166 ;
break;
}
if ( F_139 ( V_97 ) ) {
V_40 = - V_167 ;
break;
}
if ( ! V_39 -> V_75 ) {
V_40 = - V_168 ;
break;
}
F_49 () ;
}
if ( ! V_165 )
F_140 ( & V_39 -> V_29 , & V_29 ) ;
if ( V_45 ) {
V_40 = F_111 ( & V_45 -> V_155 , V_108 , V_135 ) ;
if ( V_40 != V_108 || V_45 -> V_155 . type != V_158 ) {
F_56 ( V_45 ) ;
return V_40 ;
}
F_141 ( V_39 , & V_39 -> V_93 , V_45 ) ;
}
return V_40 ;
}
static int F_142 ( struct V_1 * V_2 , T_8 V_157 , int V_159 )
{
struct V_38 * V_39 = V_2 -> V_39 ;
struct V_119 * V_45 ;
struct V_154 * V_155 ;
V_45 = F_143 ( V_2 , V_158 ) ;
if ( ! V_45 )
return - V_89 ;
V_155 = & V_45 -> V_155 . V_75 ;
V_155 -> type = V_158 ;
V_155 -> V_157 = V_157 ;
V_155 -> V_150 = V_159 ;
F_141 ( V_39 , & V_39 -> V_92 , V_45 ) ;
return 0 ;
}
static int F_144 ( struct V_1 * V_2 , unsigned int V_10 ,
struct V_169 T_1 * V_54 ,
struct V_170 T_1 * V_55 ,
struct V_171 T_1 * V_56 )
{
T_10 V_6 = F_10 ( V_2 , V_172 ) ? 2 : 0 ;
return F_98 ( V_160 , V_54 , V_10 * sizeof *V_54 ) &&
F_98 ( V_160 , V_55 ,
sizeof *V_55 + V_10 * sizeof * V_55 -> V_173 + V_6 ) &&
F_98 ( V_127 , V_56 ,
sizeof *V_56 + V_10 * sizeof * V_56 -> V_173 + V_6 ) ;
}
static void F_145 ( struct V_1 * V_2 ,
const struct V_114 * V_45 ,
int type )
{
int V_159 = ( type == V_174 ) ?
V_141 : V_145 ;
if ( F_146 ( V_45 -> V_150 & V_159 ) )
V_2 -> V_49 [ type ] = V_45 ;
}
static int F_147 ( struct V_1 * V_2 ,
int V_159 , T_8 V_122 , T_8 V_175 , int type )
{
const struct V_114 * V_45 ;
struct V_112 * V_74 = V_2 -> V_75 ;
T_8 V_6 = 0 , V_108 , V_176 = V_122 ;
if ( F_102 ( V_2 , V_122 , V_175 , type ) )
return true ;
while ( V_175 > V_6 ) {
V_45 = F_126 ( & V_74 -> V_115 ,
V_122 ,
V_122 + V_175 - 1 ) ;
if ( V_45 == NULL || V_45 -> V_131 > V_122 ) {
F_142 ( V_2 , V_122 , V_159 ) ;
return false ;
} else if ( ! ( V_45 -> V_150 & V_159 ) ) {
return false ;
}
V_108 = V_45 -> V_108 - V_122 + V_45 -> V_131 ;
if ( V_176 == V_122 && V_108 >= V_175 )
F_145 ( V_2 , V_45 , type ) ;
V_6 += V_108 ;
V_122 += V_108 ;
}
return true ;
}
int F_148 ( struct V_1 * V_2 )
{
T_10 V_6 = F_10 ( V_2 , V_172 ) ? 2 : 0 ;
unsigned int V_10 = V_2 -> V_10 ;
if ( ! V_2 -> V_75 )
return 1 ;
return F_147 ( V_2 , V_145 , ( T_8 ) ( V_132 ) V_2 -> V_54 ,
V_10 * sizeof( * V_2 -> V_54 ) , V_139 ) &&
F_147 ( V_2 , V_145 , ( T_8 ) ( V_132 ) V_2 -> V_55 ,
sizeof * V_2 -> V_55 +
V_10 * sizeof( * V_2 -> V_55 -> V_173 ) + V_6 ,
V_177 ) &&
F_147 ( V_2 , V_141 , ( T_8 ) ( V_132 ) V_2 -> V_56 ,
sizeof * V_2 -> V_56 +
V_10 * sizeof( * V_2 -> V_56 -> V_173 ) + V_6 ,
V_174 ) ;
}
int F_149 ( struct V_38 * V_39 )
{
return F_103 ( V_39 , V_39 -> V_74 , 1 ) ;
}
static int F_150 ( struct V_1 * V_2 ,
void T_1 * V_67 )
{
T_10 V_6 = F_10 ( V_2 , V_172 ) ? 2 : 0 ;
return F_100 ( V_67 , V_2 -> V_74 ,
F_10 ( V_2 , V_134 ) ) &&
( ! V_2 -> V_64 || F_97 ( V_67 , V_2 -> V_65 ,
sizeof * V_2 -> V_56 +
V_2 -> V_10 * sizeof * V_2 -> V_56 -> V_173 + V_6 ) ) ;
}
int F_151 ( struct V_1 * V_2 )
{
if ( V_2 -> V_75 ) {
return 1 ;
}
return F_144 ( V_2 , V_2 -> V_10 , V_2 -> V_54 , V_2 -> V_55 , V_2 -> V_56 ) &&
F_150 ( V_2 , V_2 -> V_67 ) ;
}
static struct V_112 * F_152 ( void )
{
struct V_112 * V_74 = F_77 ( sizeof( * V_74 ) ) ;
if ( ! V_74 )
return NULL ;
V_74 -> V_115 = V_178 ;
V_74 -> V_117 = 0 ;
F_63 ( & V_74 -> V_113 ) ;
return V_74 ;
}
static long F_153 ( struct V_38 * V_50 , struct V_179 T_1 * V_180 )
{
struct V_179 V_181 , * V_182 ;
struct V_183 * V_184 ;
struct V_112 * V_185 , * V_186 ;
unsigned long V_108 = F_154 ( struct V_179 , V_187 ) ;
int V_51 ;
if ( F_6 ( & V_181 , V_180 , V_108 ) )
return - V_9 ;
if ( V_181 . V_188 )
return - V_189 ;
if ( V_181 . V_190 > V_191 )
return - V_192 ;
V_182 = F_77 ( V_108 + V_181 . V_190 * sizeof( * V_180 -> V_187 ) ) ;
if ( ! V_182 )
return - V_89 ;
memcpy ( V_182 , & V_181 , V_108 ) ;
if ( F_6 ( V_182 -> V_187 , V_180 -> V_187 ,
V_181 . V_190 * sizeof * V_180 -> V_187 ) ) {
F_89 ( V_182 ) ;
return - V_9 ;
}
V_185 = F_152 () ;
if ( ! V_185 ) {
F_89 ( V_182 ) ;
return - V_89 ;
}
for ( V_184 = V_182 -> V_187 ;
V_184 < V_182 -> V_187 + V_181 . V_190 ;
V_184 ++ ) {
if ( F_120 ( V_185 ,
V_184 -> V_193 ,
V_184 -> V_194 ,
V_184 -> V_193 +
V_184 -> V_194 - 1 ,
V_184 -> V_130 ,
V_195 ) )
goto V_103;
}
if ( ! F_103 ( V_50 , V_185 , 0 ) )
goto V_103;
V_186 = V_50 -> V_74 ;
V_50 -> V_74 = V_185 ;
for ( V_51 = 0 ; V_51 < V_50 -> V_52 ; ++ V_51 ) {
F_104 ( & V_50 -> V_53 [ V_51 ] -> V_90 ) ;
V_50 -> V_53 [ V_51 ] -> V_74 = V_185 ;
F_105 ( & V_50 -> V_53 [ V_51 ] -> V_90 ) ;
}
F_89 ( V_182 ) ;
F_87 ( V_186 ) ;
return 0 ;
V_103:
F_87 ( V_185 ) ;
F_89 ( V_182 ) ;
return - V_9 ;
}
long F_155 ( struct V_38 * V_50 , int V_196 , void T_1 * V_4 )
{
struct V_23 * V_197 , * V_198 = NULL ;
bool V_199 = false , V_200 = false ;
struct V_201 * V_202 = NULL ;
T_2 T_1 * V_203 = V_4 ;
struct V_1 * V_2 ;
struct V_5 V_6 ;
struct V_204 V_144 ;
struct V_205 V_124 ;
T_2 V_14 ;
long V_206 ;
V_206 = F_156 ( V_14 , V_203 ) ;
if ( V_206 < 0 )
return V_206 ;
if ( V_14 >= V_50 -> V_52 )
return - V_207 ;
V_2 = V_50 -> V_53 [ V_14 ] ;
F_104 ( & V_2 -> V_90 ) ;
switch ( V_196 ) {
case V_208 :
if ( V_2 -> V_7 ) {
V_206 = - V_8 ;
break;
}
if ( F_6 ( & V_6 , V_4 , sizeof V_6 ) ) {
V_206 = - V_9 ;
break;
}
if ( ! V_6 . V_10 || V_6 . V_10 > 0xffff || ( V_6 . V_10 & ( V_6 . V_10 - 1 ) ) ) {
V_206 = - V_13 ;
break;
}
V_2 -> V_10 = V_6 . V_10 ;
break;
case V_209 :
if ( V_2 -> V_7 ) {
V_206 = - V_8 ;
break;
}
if ( F_6 ( & V_6 , V_4 , sizeof V_6 ) ) {
V_206 = - V_9 ;
break;
}
if ( V_6 . V_10 > 0xffff ) {
V_206 = - V_13 ;
break;
}
V_2 -> V_57 = V_2 -> V_58 = V_6 . V_10 ;
V_2 -> V_59 = V_2 -> V_57 ;
break;
case V_210 :
V_6 . V_15 = V_14 ;
V_6 . V_10 = V_2 -> V_57 ;
if ( F_8 ( V_4 , & V_6 , sizeof V_6 ) )
V_206 = - V_9 ;
break;
case V_211 :
if ( F_6 ( & V_124 , V_4 , sizeof V_124 ) ) {
V_206 = - V_9 ;
break;
}
if ( V_124 . V_36 & ~ ( 0x1 << V_212 ) ) {
V_206 = - V_189 ;
break;
}
if ( ( T_8 ) ( unsigned long ) V_124 . V_213 != V_124 . V_213 ||
( T_8 ) ( unsigned long ) V_124 . V_214 != V_124 . V_214 ||
( T_8 ) ( unsigned long ) V_124 . V_215 != V_124 . V_215 ) {
V_206 = - V_9 ;
break;
}
F_157 ( V_216 * V_2 -> V_55 > V_217 ) ;
F_157 ( V_216 * V_2 -> V_56 > V_218 ) ;
if ( ( V_124 . V_215 & ( V_217 - 1 ) ) ||
( V_124 . V_214 & ( V_218 - 1 ) ) ||
( V_124 . V_219 & ( V_218 - 1 ) ) ) {
V_206 = - V_13 ;
break;
}
if ( V_2 -> V_7 ) {
if ( ! F_144 ( V_2 , V_2 -> V_10 ,
( void T_1 * ) ( unsigned long ) V_124 . V_213 ,
( void T_1 * ) ( unsigned long ) V_124 . V_215 ,
( void T_1 * ) ( unsigned long ) V_124 . V_214 ) ) {
V_206 = - V_13 ;
break;
}
if ( ( V_124 . V_36 & ( 0x1 << V_212 ) ) &&
! F_97 ( V_2 -> V_67 , V_124 . V_219 ,
sizeof * V_2 -> V_56 +
V_2 -> V_10 * sizeof * V_2 -> V_56 -> V_173 ) ) {
V_206 = - V_13 ;
break;
}
}
V_2 -> V_64 = ! ! ( V_124 . V_36 & ( 0x1 << V_212 ) ) ;
V_2 -> V_54 = ( void T_1 * ) ( unsigned long ) V_124 . V_213 ;
V_2 -> V_55 = ( void T_1 * ) ( unsigned long ) V_124 . V_215 ;
V_2 -> V_65 = V_124 . V_219 ;
V_2 -> V_56 = ( void T_1 * ) ( unsigned long ) V_124 . V_214 ;
break;
case V_220 :
if ( F_6 ( & V_144 , V_4 , sizeof V_144 ) ) {
V_206 = - V_9 ;
break;
}
V_197 = V_144 . V_221 == - 1 ? NULL : F_158 ( V_144 . V_221 ) ;
if ( F_73 ( V_197 ) ) {
V_206 = F_74 ( V_197 ) ;
break;
}
if ( V_197 != V_2 -> V_69 ) {
V_200 = ( V_198 = V_2 -> V_69 ) != NULL ;
V_199 = ( V_2 -> V_69 = V_197 ) != NULL ;
} else
V_198 = V_197 ;
break;
case V_222 :
if ( F_6 ( & V_144 , V_4 , sizeof V_144 ) ) {
V_206 = - V_9 ;
break;
}
V_197 = V_144 . V_221 == - 1 ? NULL : F_158 ( V_144 . V_221 ) ;
if ( F_73 ( V_197 ) ) {
V_206 = F_74 ( V_197 ) ;
break;
}
if ( V_197 != V_2 -> V_71 ) {
V_198 = V_2 -> V_71 ;
V_202 = V_2 -> V_70 ;
V_2 -> V_71 = V_197 ;
V_2 -> V_70 = V_197 ?
F_159 ( V_197 ) : NULL ;
} else
V_198 = V_197 ;
break;
case V_223 :
if ( F_6 ( & V_144 , V_4 , sizeof V_144 ) ) {
V_206 = - V_9 ;
break;
}
V_197 = V_144 . V_221 == - 1 ? NULL : F_158 ( V_144 . V_221 ) ;
if ( F_73 ( V_197 ) ) {
V_206 = F_74 ( V_197 ) ;
break;
}
if ( V_197 != V_2 -> error ) {
V_198 = V_2 -> error ;
V_2 -> error = V_197 ;
V_202 = V_2 -> V_68 ;
V_2 -> V_68 = V_197 ?
F_159 ( V_197 ) : NULL ;
} else
V_198 = V_197 ;
break;
case V_224 :
V_206 = F_5 ( V_2 , V_4 ) ;
break;
case V_225 :
V_206 = F_7 ( V_2 , V_14 , V_4 ) ;
break;
case V_226 :
if ( F_6 ( & V_6 , V_4 , sizeof( V_6 ) ) ) {
V_206 = - V_9 ;
break;
}
V_2 -> V_73 = V_6 . V_10 ;
break;
case V_227 :
V_6 . V_15 = V_14 ;
V_6 . V_10 = V_2 -> V_73 ;
if ( F_8 ( V_4 , & V_6 , sizeof( V_6 ) ) )
V_206 = - V_9 ;
break;
default:
V_206 = - V_18 ;
}
if ( V_200 && V_2 -> V_95 )
F_27 ( & V_2 -> V_27 ) ;
if ( V_202 )
F_93 ( V_202 ) ;
if ( V_198 )
F_94 ( V_198 ) ;
if ( V_199 && V_2 -> V_95 )
V_206 = F_25 ( & V_2 -> V_27 , V_2 -> V_69 ) ;
F_105 ( & V_2 -> V_90 ) ;
if ( V_200 && V_2 -> V_95 )
F_32 ( & V_2 -> V_27 ) ;
return V_206 ;
}
int F_160 ( struct V_38 * V_50 , bool V_228 )
{
struct V_112 * V_229 , * V_230 ;
int V_51 ;
V_229 = F_152 () ;
if ( ! V_229 )
return - V_89 ;
V_230 = V_50 -> V_75 ;
V_50 -> V_75 = V_229 ;
for ( V_51 = 0 ; V_51 < V_50 -> V_52 ; ++ V_51 ) {
F_104 ( & V_50 -> V_53 [ V_51 ] -> V_90 ) ;
V_50 -> V_53 [ V_51 ] -> V_75 = V_229 ;
F_105 ( & V_50 -> V_53 [ V_51 ] -> V_90 ) ;
}
F_87 ( V_230 ) ;
return 0 ;
}
long F_161 ( struct V_38 * V_50 , unsigned int V_196 , void T_1 * V_4 )
{
struct V_23 * V_197 , * V_198 = NULL ;
struct V_201 * V_202 = NULL ;
T_8 V_231 ;
long V_206 ;
int V_51 , V_221 ;
if ( V_196 == V_232 ) {
V_206 = F_70 ( V_50 ) ;
goto V_37;
}
V_206 = F_65 ( V_50 ) ;
if ( V_206 )
goto V_37;
switch ( V_196 ) {
case V_233 :
V_206 = F_153 ( V_50 , V_4 ) ;
break;
case V_234 :
if ( F_6 ( & V_231 , V_4 , sizeof V_231 ) ) {
V_206 = - V_9 ;
break;
}
if ( ( T_8 ) ( unsigned long ) V_231 != V_231 ) {
V_206 = - V_9 ;
break;
}
for ( V_51 = 0 ; V_51 < V_50 -> V_52 ; ++ V_51 ) {
struct V_1 * V_2 ;
void T_1 * V_235 = ( void T_1 * ) ( unsigned long ) V_231 ;
V_2 = V_50 -> V_53 [ V_51 ] ;
F_104 ( & V_2 -> V_90 ) ;
if ( V_2 -> V_7 && ! F_150 ( V_2 , V_235 ) )
V_206 = - V_9 ;
else
V_2 -> V_67 = V_235 ;
F_105 ( & V_2 -> V_90 ) ;
}
break;
case V_236 :
V_206 = F_156 ( V_221 , ( int T_1 * ) V_4 ) ;
if ( V_206 < 0 )
break;
V_197 = V_221 == - 1 ? NULL : F_158 ( V_221 ) ;
if ( F_73 ( V_197 ) ) {
V_206 = F_74 ( V_197 ) ;
break;
}
if ( V_197 != V_50 -> V_91 ) {
V_198 = V_50 -> V_91 ;
V_50 -> V_91 = V_197 ;
V_202 = V_50 -> V_72 ;
V_50 -> V_72 = V_197 ?
F_159 ( V_197 ) : NULL ;
} else
V_198 = V_197 ;
for ( V_51 = 0 ; V_51 < V_50 -> V_52 ; ++ V_51 ) {
F_104 ( & V_50 -> V_53 [ V_51 ] -> V_90 ) ;
V_50 -> V_53 [ V_51 ] -> V_72 = V_50 -> V_72 ;
F_105 ( & V_50 -> V_53 [ V_51 ] -> V_90 ) ;
}
if ( V_202 )
F_93 ( V_202 ) ;
if ( V_198 )
F_94 ( V_198 ) ;
break;
default:
V_206 = - V_18 ;
break;
}
V_37:
return V_206 ;
}
static int F_162 ( int V_237 , void T_1 * V_122 )
{
unsigned long log = ( unsigned long ) V_122 ;
struct V_238 * V_238 ;
void * V_235 ;
int V_239 = V_237 + ( log % V_240 ) * 8 ;
int V_206 ;
V_206 = F_163 ( log , 1 , 1 , & V_238 ) ;
if ( V_206 < 0 )
return V_206 ;
F_164 ( V_206 != 1 ) ;
V_235 = F_165 ( V_238 ) ;
F_166 ( V_239 , V_235 ) ;
F_167 ( V_235 ) ;
F_168 ( V_238 ) ;
F_169 ( V_238 ) ;
return 0 ;
}
static int F_170 ( void T_1 * V_67 ,
T_8 V_241 , T_8 V_242 )
{
T_8 V_243 = V_241 / V_125 ;
int V_206 ;
if ( ! V_242 )
return 0 ;
V_242 += V_241 % V_125 ;
for (; ; ) {
T_8 V_235 = ( T_8 ) ( unsigned long ) V_67 ;
T_8 log = V_235 + V_243 / 8 ;
int V_239 = V_243 % 8 ;
if ( ( T_8 ) ( unsigned long ) log != log )
return - V_9 ;
V_206 = F_162 ( V_239 , ( void T_1 * ) ( unsigned long ) log ) ;
if ( V_206 < 0 )
return V_206 ;
if ( V_242 <= V_125 )
break;
V_242 -= V_125 ;
V_243 += 1 ;
}
return V_206 ;
}
int F_171 ( struct V_1 * V_2 , struct V_244 * log ,
unsigned int V_245 , T_8 V_175 )
{
int V_51 , V_206 ;
F_51 () ;
for ( V_51 = 0 ; V_51 < V_245 ; ++ V_51 ) {
T_8 V_246 = F_172 ( log [ V_51 ] . V_175 , V_175 ) ;
V_206 = F_170 ( V_2 -> V_67 , log [ V_51 ] . V_122 , V_246 ) ;
if ( V_206 < 0 )
return V_206 ;
V_175 -= V_246 ;
if ( ! V_175 ) {
if ( V_2 -> V_72 )
F_173 ( V_2 -> V_72 , 1 ) ;
return 0 ;
}
}
F_174 () ;
return 0 ;
}
static int F_175 ( struct V_1 * V_2 )
{
void T_1 * V_56 ;
if ( F_176 ( V_2 , F_177 ( V_2 , V_2 -> V_63 ) ,
& V_2 -> V_56 -> V_36 ) < 0 )
return - V_9 ;
if ( F_178 ( V_2 -> V_64 ) ) {
F_51 () ;
V_56 = & V_2 -> V_56 -> V_36 ;
F_170 ( V_2 -> V_67 , V_2 -> V_65 +
( V_56 - ( void T_1 * ) V_2 -> V_56 ) ,
sizeof V_2 -> V_56 -> V_36 ) ;
if ( V_2 -> V_72 )
F_173 ( V_2 -> V_72 , 1 ) ;
}
return 0 ;
}
static int F_179 ( struct V_1 * V_2 , T_11 V_247 )
{
if ( F_176 ( V_2 , F_177 ( V_2 , V_2 -> V_59 ) ,
F_180 ( V_2 ) ) )
return - V_9 ;
if ( F_178 ( V_2 -> V_64 ) ) {
void T_1 * V_56 ;
F_51 () ;
V_56 = F_180 ( V_2 ) ;
F_170 ( V_2 -> V_67 , V_2 -> V_65 +
( V_56 - ( void T_1 * ) V_2 -> V_56 ) ,
sizeof * F_180 ( V_2 ) ) ;
if ( V_2 -> V_72 )
F_173 ( V_2 -> V_72 , 1 ) ;
}
return 0 ;
}
int F_181 ( struct V_1 * V_2 )
{
T_12 V_60 ;
int V_206 ;
bool V_16 = V_2 -> V_16 ;
if ( ! V_2 -> V_7 )
return 0 ;
F_9 ( V_2 ) ;
V_206 = F_175 ( V_2 ) ;
if ( V_206 )
goto V_103;
V_2 -> V_62 = false ;
if ( ! V_2 -> V_75 &&
! F_98 ( V_160 , & V_2 -> V_56 -> V_14 , sizeof V_2 -> V_56 -> V_14 ) ) {
V_206 = - V_9 ;
goto V_103;
}
V_206 = F_182 ( V_2 , V_60 , & V_2 -> V_56 -> V_14 ) ;
if ( V_206 ) {
F_114 ( V_2 , L_5 ,
& V_2 -> V_56 -> V_14 ) ;
goto V_103;
}
V_2 -> V_60 = F_183 ( V_2 , V_60 ) ;
return 0 ;
V_103:
V_2 -> V_16 = V_16 ;
return V_206 ;
}
static int F_108 ( struct V_1 * V_2 , T_8 V_122 , T_2 V_175 ,
struct V_248 V_249 [] , int V_250 , int V_159 )
{
const struct V_114 * V_45 ;
struct V_38 * V_39 = V_2 -> V_39 ;
struct V_112 * V_74 = V_39 -> V_75 ? V_39 -> V_75 : V_39 -> V_74 ;
struct V_248 * V_251 ;
T_8 V_6 = 0 ;
int V_40 = 0 ;
while ( ( T_8 ) V_175 > V_6 ) {
T_8 V_108 ;
if ( F_178 ( V_40 >= V_250 ) ) {
V_40 = - V_207 ;
break;
}
V_45 = F_126 ( & V_74 -> V_115 ,
V_122 , V_122 + V_175 - 1 ) ;
if ( V_45 == NULL || V_45 -> V_131 > V_122 ) {
if ( V_74 != V_39 -> V_75 ) {
V_40 = - V_9 ;
break;
}
V_40 = - V_166 ;
break;
} else if ( ! ( V_45 -> V_150 & V_159 ) ) {
V_40 = - V_98 ;
break;
}
V_251 = V_249 + V_40 ;
V_108 = V_45 -> V_108 - V_122 + V_45 -> V_131 ;
V_251 -> V_147 = F_172 ( ( T_8 ) V_175 - V_6 , V_108 ) ;
V_251 -> V_148 = ( void T_1 * ) ( unsigned long )
( V_45 -> V_130 + V_122 - V_45 -> V_131 ) ;
V_6 += V_108 ;
V_122 += V_108 ;
++ V_40 ;
}
if ( V_40 == - V_166 )
F_142 ( V_2 , V_122 , V_159 ) ;
return V_40 ;
}
static unsigned F_184 ( struct V_1 * V_2 , struct V_169 * V_54 )
{
unsigned int V_252 ;
if ( ! ( V_54 -> V_36 & F_177 ( V_2 , V_253 ) ) )
return - 1U ;
V_252 = F_183 ( V_2 , V_54 -> V_252 ) ;
F_185 () ;
return V_252 ;
}
static int F_186 ( struct V_1 * V_2 ,
struct V_248 V_249 [] , unsigned int V_250 ,
unsigned int * V_254 , unsigned int * V_255 ,
struct V_244 * log , unsigned int * V_245 ,
struct V_169 * V_84 )
{
struct V_169 V_54 ;
unsigned int V_51 = 0 , V_256 , V_257 = 0 ;
T_2 V_175 = F_187 ( V_2 , V_84 -> V_175 ) ;
struct V_137 V_136 ;
int V_40 , V_159 ;
if ( F_178 ( V_175 % sizeof V_54 ) ) {
F_114 ( V_2 , L_6
L_7 ,
( unsigned long long ) V_175 ,
sizeof V_54 ) ;
return - V_13 ;
}
V_40 = F_108 ( V_2 , F_188 ( V_2 , V_84 -> V_122 ) , V_175 , V_2 -> V_84 ,
V_86 , V_145 ) ;
if ( F_178 ( V_40 < 0 ) ) {
if ( V_40 != - V_166 )
F_114 ( V_2 , L_8 , V_40 ) ;
return V_40 ;
}
F_110 ( & V_136 , V_146 , V_2 -> V_84 , V_40 , V_175 ) ;
F_185 () ;
V_256 = V_175 / sizeof V_54 ;
if ( F_178 ( V_256 > V_258 + 1 ) ) {
F_114 ( V_2 , L_9 ,
V_84 -> V_175 ) ;
return - V_192 ;
}
do {
unsigned V_259 = * V_255 + * V_254 ;
if ( F_178 ( ++ V_257 > V_256 ) ) {
F_114 ( V_2 , L_10
L_11 ,
V_51 , V_256 ) ;
return - V_13 ;
}
if ( F_178 ( ! F_189 ( & V_54 , sizeof( V_54 ) , & V_136 ) ) ) {
F_114 ( V_2 , L_12 ,
V_51 , ( T_10 ) F_188 ( V_2 , V_84 -> V_122 ) + V_51 * sizeof V_54 ) ;
return - V_13 ;
}
if ( F_178 ( V_54 . V_36 & F_177 ( V_2 , V_260 ) ) ) {
F_114 ( V_2 , L_13 ,
V_51 , ( T_10 ) F_188 ( V_2 , V_84 -> V_122 ) + V_51 * sizeof V_54 ) ;
return - V_13 ;
}
if ( V_54 . V_36 & F_177 ( V_2 , V_261 ) )
V_159 = V_141 ;
else
V_159 = V_145 ;
V_40 = F_108 ( V_2 , F_188 ( V_2 , V_54 . V_122 ) ,
F_187 ( V_2 , V_54 . V_175 ) , V_249 + V_259 ,
V_250 - V_259 , V_159 ) ;
if ( F_178 ( V_40 < 0 ) ) {
if ( V_40 != - V_166 )
F_114 ( V_2 , L_14 ,
V_40 , V_51 ) ;
return V_40 ;
}
if ( V_159 == V_141 ) {
* V_255 += V_40 ;
if ( F_178 ( log ) ) {
log [ * V_245 ] . V_122 = F_188 ( V_2 , V_54 . V_122 ) ;
log [ * V_245 ] . V_175 = F_187 ( V_2 , V_54 . V_175 ) ;
++ * V_245 ;
}
} else {
if ( F_178 ( * V_255 ) ) {
F_114 ( V_2 , L_15
L_16 , V_51 ) ;
return - V_13 ;
}
* V_254 += V_40 ;
}
} while ( ( V_51 = F_184 ( V_2 , & V_54 ) ) != - 1 );
return 0 ;
}
int F_190 ( struct V_1 * V_2 ,
struct V_248 V_249 [] , unsigned int V_250 ,
unsigned int * V_254 , unsigned int * V_255 ,
struct V_244 * log , unsigned int * V_245 )
{
struct V_169 V_54 ;
unsigned int V_51 , V_262 , V_257 = 0 ;
T_11 V_57 ;
T_12 V_59 ;
T_12 V_263 ;
int V_40 , V_159 ;
V_57 = V_2 -> V_57 ;
if ( V_2 -> V_59 == V_2 -> V_57 ) {
if ( F_178 ( F_191 ( V_2 , V_59 , & V_2 -> V_55 -> V_14 ) ) ) {
F_114 ( V_2 , L_17 ,
& V_2 -> V_55 -> V_14 ) ;
return - V_9 ;
}
V_2 -> V_59 = F_183 ( V_2 , V_59 ) ;
if ( F_178 ( ( T_11 ) ( V_2 -> V_59 - V_57 ) > V_2 -> V_10 ) ) {
F_114 ( V_2 , L_18 ,
V_57 , V_2 -> V_59 ) ;
return - V_9 ;
}
if ( V_2 -> V_59 == V_57 )
return V_2 -> V_10 ;
F_192 () ;
}
if ( F_178 ( F_191 ( V_2 , V_263 ,
& V_2 -> V_55 -> V_173 [ V_57 & ( V_2 -> V_10 - 1 ) ] ) ) ) {
F_114 ( V_2 , L_19 ,
V_57 ,
& V_2 -> V_55 -> V_173 [ V_57 % V_2 -> V_10 ] ) ;
return - V_9 ;
}
V_262 = F_183 ( V_2 , V_263 ) ;
if ( F_178 ( V_262 >= V_2 -> V_10 ) ) {
F_114 ( V_2 , L_20 ,
V_262 , V_2 -> V_10 ) ;
return - V_13 ;
}
* V_254 = * V_255 = 0 ;
if ( F_178 ( log ) )
* V_245 = 0 ;
V_51 = V_262 ;
do {
unsigned V_259 = * V_255 + * V_254 ;
if ( F_178 ( V_51 >= V_2 -> V_10 ) ) {
F_114 ( V_2 , L_21 ,
V_51 , V_2 -> V_10 , V_262 ) ;
return - V_13 ;
}
if ( F_178 ( ++ V_257 > V_2 -> V_10 ) ) {
F_114 ( V_2 , L_10
L_22 ,
V_51 , V_2 -> V_10 , V_262 ) ;
return - V_13 ;
}
V_40 = F_112 ( V_2 , & V_54 , V_2 -> V_54 + V_51 ,
sizeof V_54 ) ;
if ( F_178 ( V_40 ) ) {
F_114 ( V_2 , L_23 ,
V_51 , V_2 -> V_54 + V_51 ) ;
return - V_9 ;
}
if ( V_54 . V_36 & F_177 ( V_2 , V_260 ) ) {
V_40 = F_186 ( V_2 , V_249 , V_250 ,
V_254 , V_255 ,
log , V_245 , & V_54 ) ;
if ( F_178 ( V_40 < 0 ) ) {
if ( V_40 != - V_166 )
F_114 ( V_2 , L_24
L_25 , V_51 ) ;
return V_40 ;
}
continue;
}
if ( V_54 . V_36 & F_177 ( V_2 , V_261 ) )
V_159 = V_141 ;
else
V_159 = V_145 ;
V_40 = F_108 ( V_2 , F_188 ( V_2 , V_54 . V_122 ) ,
F_187 ( V_2 , V_54 . V_175 ) , V_249 + V_259 ,
V_250 - V_259 , V_159 ) ;
if ( F_178 ( V_40 < 0 ) ) {
if ( V_40 != - V_166 )
F_114 ( V_2 , L_26 ,
V_40 , V_51 ) ;
return V_40 ;
}
if ( V_159 == V_141 ) {
* V_255 += V_40 ;
if ( F_178 ( log ) ) {
log [ * V_245 ] . V_122 = F_188 ( V_2 , V_54 . V_122 ) ;
log [ * V_245 ] . V_175 = F_187 ( V_2 , V_54 . V_175 ) ;
++ * V_245 ;
}
} else {
if ( F_178 ( * V_255 ) ) {
F_114 ( V_2 , L_27
L_28 , V_51 ) ;
return - V_13 ;
}
* V_254 += V_40 ;
}
} while ( ( V_51 = F_184 ( V_2 , & V_54 ) ) != - 1 );
V_2 -> V_57 ++ ;
F_164 ( ! ( V_2 -> V_63 & V_264 ) ) ;
return V_262 ;
}
void F_193 ( struct V_1 * V_2 , int V_109 )
{
V_2 -> V_57 -= V_109 ;
}
int F_194 ( struct V_1 * V_2 , unsigned int V_262 , int V_175 )
{
struct V_265 V_85 = {
F_195 ( V_2 , V_262 ) ,
F_195 (vq, len)
} ;
return F_196 ( V_2 , & V_85 , 1 ) ;
}
static int F_197 ( struct V_1 * V_2 ,
struct V_265 * V_85 ,
unsigned V_256 )
{
struct V_265 T_1 * V_56 ;
T_11 V_266 , V_267 ;
int V_131 ;
V_131 = V_2 -> V_60 & ( V_2 -> V_10 - 1 ) ;
V_56 = V_2 -> V_56 -> V_173 + V_131 ;
if ( V_256 == 1 ) {
if ( F_176 ( V_2 , V_85 [ 0 ] . V_268 , & V_56 -> V_268 ) ) {
F_114 ( V_2 , L_29 ) ;
return - V_9 ;
}
if ( F_176 ( V_2 , V_85 [ 0 ] . V_175 , & V_56 -> V_175 ) ) {
F_114 ( V_2 , L_30 ) ;
return - V_9 ;
}
} else if ( F_106 ( V_2 , V_56 , V_85 , V_256 * sizeof *V_56 ) ) {
F_114 ( V_2 , L_31 ) ;
return - V_9 ;
}
if ( F_178 ( V_2 -> V_64 ) ) {
F_51 () ;
F_170 ( V_2 -> V_67 ,
V_2 -> V_65 +
( ( void T_1 * ) V_56 - ( void T_1 * ) V_2 -> V_56 ) ,
V_256 * sizeof *V_56 ) ;
}
V_266 = V_2 -> V_60 ;
V_267 = ( V_2 -> V_60 += V_256 ) ;
if ( F_178 ( ( T_11 ) ( V_267 - V_2 -> V_61 ) < ( T_11 ) ( V_267 - V_266 ) ) )
V_2 -> V_62 = false ;
return 0 ;
}
int F_196 ( struct V_1 * V_2 , struct V_265 * V_85 ,
unsigned V_256 )
{
int V_131 , V_109 , V_206 ;
V_131 = V_2 -> V_60 & ( V_2 -> V_10 - 1 ) ;
V_109 = V_2 -> V_10 - V_131 ;
if ( V_109 < V_256 ) {
V_206 = F_197 ( V_2 , V_85 , V_109 ) ;
if ( V_206 < 0 )
return V_206 ;
V_85 += V_109 ;
V_256 -= V_109 ;
}
V_206 = F_197 ( V_2 , V_85 , V_256 ) ;
F_51 () ;
if ( F_176 ( V_2 , F_177 ( V_2 , V_2 -> V_60 ) ,
& V_2 -> V_56 -> V_14 ) ) {
F_114 ( V_2 , L_32 ) ;
return - V_9 ;
}
if ( F_178 ( V_2 -> V_64 ) ) {
F_170 ( V_2 -> V_67 ,
V_2 -> V_65 + F_154 ( struct V_171 , V_14 ) ,
sizeof V_2 -> V_56 -> V_14 ) ;
if ( V_2 -> V_72 )
F_173 ( V_2 -> V_72 , 1 ) ;
}
return V_206 ;
}
static bool F_198 ( struct V_38 * V_39 , struct V_1 * V_2 )
{
T_13 V_266 , V_267 ;
T_12 V_269 ;
bool V_270 ;
if ( F_10 ( V_2 , V_271 ) &&
F_178 ( V_2 -> V_59 == V_2 -> V_57 ) )
return true ;
if ( ! F_10 ( V_2 , V_172 ) ) {
T_12 V_36 ;
F_199 () ;
if ( F_191 ( V_2 , V_36 , & V_2 -> V_55 -> V_36 ) ) {
F_114 ( V_2 , L_33 ) ;
return true ;
}
return ! ( V_36 & F_177 ( V_2 , V_272 ) ) ;
}
V_266 = V_2 -> V_61 ;
V_270 = V_2 -> V_62 ;
V_267 = V_2 -> V_61 = V_2 -> V_60 ;
V_2 -> V_62 = true ;
if ( F_178 ( ! V_270 ) )
return true ;
if ( F_200 ( V_2 -> V_58 , V_267 + V_2 -> V_10 , V_267 ) &&
! F_200 ( V_2 -> V_58 , V_267 , V_266 ) )
return false ;
F_199 () ;
if ( F_191 ( V_2 , V_269 , F_201 ( V_2 ) ) ) {
F_114 ( V_2 , L_34 ) ;
return true ;
}
V_2 -> V_58 = F_183 ( V_2 , V_269 ) ;
return F_200 ( V_2 -> V_58 , V_267 , V_266 ) ;
}
void F_202 ( struct V_38 * V_39 , struct V_1 * V_2 )
{
if ( V_2 -> V_70 && F_198 ( V_39 , V_2 ) )
F_173 ( V_2 -> V_70 , 1 ) ;
}
void F_203 ( struct V_38 * V_39 ,
struct V_1 * V_2 ,
unsigned int V_262 , int V_175 )
{
F_194 ( V_2 , V_262 , V_175 ) ;
F_202 ( V_39 , V_2 ) ;
}
void F_204 ( struct V_38 * V_39 ,
struct V_1 * V_2 ,
struct V_265 * V_85 , unsigned V_256 )
{
F_196 ( V_2 , V_85 , V_256 ) ;
F_202 ( V_39 , V_2 ) ;
}
bool F_205 ( struct V_38 * V_39 , struct V_1 * V_2 )
{
T_12 V_59 ;
int V_206 ;
if ( V_2 -> V_59 != V_2 -> V_57 )
return false ;
V_206 = F_191 ( V_2 , V_59 , & V_2 -> V_55 -> V_14 ) ;
if ( F_178 ( V_206 ) )
return false ;
V_2 -> V_59 = F_183 ( V_2 , V_59 ) ;
return V_2 -> V_59 == V_2 -> V_57 ;
}
bool F_206 ( struct V_38 * V_39 , struct V_1 * V_2 )
{
T_12 V_59 ;
int V_206 ;
if ( ! ( V_2 -> V_63 & V_264 ) )
return false ;
V_2 -> V_63 &= ~ V_264 ;
if ( ! F_10 ( V_2 , V_172 ) ) {
V_206 = F_175 ( V_2 ) ;
if ( V_206 ) {
F_114 ( V_2 , L_35 ,
& V_2 -> V_56 -> V_36 , V_206 ) ;
return false ;
}
} else {
V_206 = F_179 ( V_2 , V_2 -> V_59 ) ;
if ( V_206 ) {
F_114 ( V_2 , L_36 ,
F_180 ( V_2 ) , V_206 ) ;
return false ;
}
}
F_199 () ;
V_206 = F_191 ( V_2 , V_59 , & V_2 -> V_55 -> V_14 ) ;
if ( V_206 ) {
F_114 ( V_2 , L_37 ,
& V_2 -> V_55 -> V_14 , V_206 ) ;
return false ;
}
return F_183 ( V_2 , V_59 ) != V_2 -> V_59 ;
}
void F_207 ( struct V_38 * V_39 , struct V_1 * V_2 )
{
int V_206 ;
if ( V_2 -> V_63 & V_264 )
return;
V_2 -> V_63 |= V_264 ;
if ( ! F_10 ( V_2 , V_172 ) ) {
V_206 = F_175 ( V_2 ) ;
if ( V_206 )
F_114 ( V_2 , L_35 ,
& V_2 -> V_56 -> V_36 , V_206 ) ;
}
}
struct V_119 * F_143 ( struct V_1 * V_2 , int type )
{
struct V_119 * V_45 = F_58 ( sizeof *V_45 , V_87 ) ;
if ( ! V_45 )
return NULL ;
V_45 -> V_2 = V_2 ;
V_45 -> V_155 . type = type ;
return V_45 ;
}
void F_141 ( struct V_38 * V_39 , struct V_273 * V_262 ,
struct V_119 * V_45 )
{
F_91 ( & V_39 -> V_94 ) ;
F_123 ( & V_45 -> V_45 , V_262 ) ;
F_92 ( & V_39 -> V_94 ) ;
F_95 ( & V_39 -> V_29 , V_96 | V_121 ) ;
}
struct V_119 * F_138 ( struct V_38 * V_39 ,
struct V_273 * V_262 )
{
struct V_119 * V_45 = NULL ;
F_91 ( & V_39 -> V_94 ) ;
if ( ! F_134 ( V_262 ) ) {
V_45 = F_121 ( V_262 , struct V_119 ,
V_45 ) ;
F_86 ( & V_45 -> V_45 ) ;
}
F_92 ( & V_39 -> V_94 ) ;
return V_45 ;
}
static int T_14 F_208 ( void )
{
return 0 ;
}
static void T_15 F_209 ( void )
{
}
