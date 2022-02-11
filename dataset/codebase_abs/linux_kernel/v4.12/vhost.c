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
struct V_108 * F_77 ( void )
{
return F_78 ( sizeof( struct V_108 ) , V_87 ) ;
}
void F_79 ( struct V_38 * V_39 , struct V_108 * V_74 )
{
int V_51 ;
F_80 ( V_39 , true ) ;
F_63 ( & V_74 -> V_109 ) ;
V_39 -> V_74 = V_74 ;
for ( V_51 = 0 ; V_51 < V_39 -> V_52 ; ++ V_51 )
V_39 -> V_53 [ V_51 ] -> V_74 = V_74 ;
}
void F_81 ( struct V_38 * V_39 )
{
int V_51 ;
for ( V_51 = 0 ; V_51 < V_39 -> V_52 ; ++ V_51 ) {
if ( V_39 -> V_53 [ V_51 ] -> V_69 && V_39 -> V_53 [ V_51 ] -> V_95 ) {
F_27 ( & V_39 -> V_53 [ V_51 ] -> V_27 ) ;
F_32 ( & V_39 -> V_53 [ V_51 ] -> V_27 ) ;
}
}
}
static void F_82 ( struct V_108 * V_74 ,
struct V_110 * V_45 )
{
F_83 ( V_45 , & V_74 -> V_111 ) ;
F_84 ( & V_45 -> V_112 ) ;
F_56 ( V_45 ) ;
V_74 -> V_113 -- ;
}
static void F_85 ( struct V_108 * V_74 )
{
struct V_110 * V_45 , * V_114 ;
if ( ! V_74 )
return;
F_86 (node, tmp, &umem->umem_list, link)
F_82 ( V_74 , V_45 ) ;
F_87 ( V_74 ) ;
}
static void F_88 ( struct V_38 * V_39 )
{
struct V_115 * V_45 , * V_116 ;
F_89 ( & V_39 -> V_94 ) ;
F_86 (node, n, &dev->read_list, node) {
F_84 ( & V_45 -> V_45 ) ;
F_56 ( V_45 ) ;
}
F_86 (node, n, &dev->pending_list, node) {
F_84 ( & V_45 -> V_45 ) ;
F_56 ( V_45 ) ;
}
F_90 ( & V_39 -> V_94 ) ;
}
void F_80 ( struct V_38 * V_39 , bool V_117 )
{
int V_51 ;
for ( V_51 = 0 ; V_51 < V_39 -> V_52 ; ++ V_51 ) {
if ( V_39 -> V_53 [ V_51 ] -> V_68 )
F_91 ( V_39 -> V_53 [ V_51 ] -> V_68 ) ;
if ( V_39 -> V_53 [ V_51 ] -> error )
F_92 ( V_39 -> V_53 [ V_51 ] -> error ) ;
if ( V_39 -> V_53 [ V_51 ] -> V_69 )
F_92 ( V_39 -> V_53 [ V_51 ] -> V_69 ) ;
if ( V_39 -> V_53 [ V_51 ] -> V_70 )
F_91 ( V_39 -> V_53 [ V_51 ] -> V_70 ) ;
if ( V_39 -> V_53 [ V_51 ] -> V_71 )
F_92 ( V_39 -> V_53 [ V_51 ] -> V_71 ) ;
F_40 ( V_39 , V_39 -> V_53 [ V_51 ] ) ;
}
F_59 ( V_39 ) ;
if ( V_39 -> V_72 )
F_91 ( V_39 -> V_72 ) ;
V_39 -> V_72 = NULL ;
if ( V_39 -> V_91 )
F_92 ( V_39 -> V_91 ) ;
V_39 -> V_91 = NULL ;
F_85 ( V_39 -> V_74 ) ;
V_39 -> V_74 = NULL ;
F_85 ( V_39 -> V_75 ) ;
V_39 -> V_75 = NULL ;
F_88 ( V_39 ) ;
F_93 ( & V_39 -> V_29 , V_96 | V_118 ) ;
F_94 ( ! F_37 ( & V_39 -> V_46 ) ) ;
if ( V_39 -> V_44 ) {
F_75 ( V_39 -> V_44 ) ;
V_39 -> V_44 = NULL ;
}
if ( V_39 -> V_81 )
F_76 ( V_39 -> V_81 ) ;
V_39 -> V_81 = NULL ;
}
static int F_95 ( void T_1 * V_67 , T_8 V_119 , unsigned long V_120 )
{
T_8 V_121 = V_119 / V_122 / 8 ;
if ( V_121 > V_123 - ( unsigned long ) V_67 ||
V_121 + ( unsigned long ) V_67 > V_123 )
return 0 ;
return F_96 ( V_124 , V_67 + V_121 ,
( V_120 + V_122 * 8 - 1 ) / V_122 / 8 ) ;
}
static bool F_97 ( T_8 V_125 , T_8 V_126 )
{
return V_125 > V_123 || V_126 > V_123 || V_125 > V_123 - V_126 ;
}
static int F_98 ( void T_1 * V_67 , struct V_108 * V_74 ,
int V_127 )
{
struct V_110 * V_45 ;
if ( ! V_74 )
return 0 ;
F_99 (node, &umem->umem_list, link) {
unsigned long V_121 = V_45 -> V_128 ;
if ( F_97 ( V_45 -> V_128 , V_45 -> V_126 ) )
return 0 ;
if ( ! F_96 ( V_124 , ( void T_1 * ) V_121 ,
V_45 -> V_126 ) )
return 0 ;
else if ( V_127 && ! F_95 ( V_67 ,
V_45 -> V_129 ,
V_45 -> V_126 ) )
return 0 ;
}
return 1 ;
}
static inline void T_1 * F_100 ( struct V_1 * V_2 ,
T_8 V_119 , unsigned int V_126 ,
int type )
{
const struct V_110 * V_45 = V_2 -> V_49 [ type ] ;
if ( ! V_45 )
return NULL ;
return ( void * ) ( V_130 ) ( V_45 -> V_128 + V_119 - V_45 -> V_129 ) ;
}
static int F_101 ( struct V_38 * V_50 , struct V_108 * V_74 ,
int V_127 )
{
int V_51 ;
for ( V_51 = 0 ; V_51 < V_50 -> V_52 ; ++ V_51 ) {
int V_131 ;
bool log ;
F_102 ( & V_50 -> V_53 [ V_51 ] -> V_90 ) ;
log = V_127 || F_10 ( V_50 -> V_53 [ V_51 ] , V_132 ) ;
if ( V_50 -> V_53 [ V_51 ] -> V_7 )
V_131 = F_98 ( V_50 -> V_53 [ V_51 ] -> V_67 ,
V_74 , log ) ;
else
V_131 = 1 ;
F_103 ( & V_50 -> V_53 [ V_51 ] -> V_90 ) ;
if ( ! V_131 )
return 0 ;
}
return 1 ;
}
static int F_104 ( struct V_1 * V_2 , void T_1 * V_133 ,
const void * V_134 , unsigned V_126 )
{
int V_40 ;
if ( ! V_2 -> V_75 )
return F_105 ( V_133 , V_134 , V_126 ) ;
else {
struct V_135 V_136 ;
void T_1 * V_125 = F_100 ( V_2 ,
( T_8 ) ( V_130 ) V_133 , V_126 ,
V_137 ) ;
if ( V_125 )
return F_105 ( V_125 , V_134 , V_126 ) ;
V_40 = F_106 ( V_2 , ( T_8 ) ( V_130 ) V_133 , V_126 , V_2 -> V_138 ,
F_107 ( V_2 -> V_138 ) ,
V_139 ) ;
if ( V_40 < 0 )
goto V_140;
F_108 ( & V_136 , V_141 , V_2 -> V_138 , V_40 , V_126 ) ;
V_40 = F_109 ( V_134 , V_126 , & V_136 ) ;
if ( V_40 == V_126 )
V_40 = 0 ;
}
V_140:
return V_40 ;
}
static int F_110 ( struct V_1 * V_2 , void * V_133 ,
void T_1 * V_134 , unsigned V_126 )
{
int V_40 ;
if ( ! V_2 -> V_75 )
return F_111 ( V_133 , V_134 , V_126 ) ;
else {
void T_1 * V_125 = F_100 ( V_2 ,
( T_8 ) ( V_130 ) V_134 , V_126 ,
V_137 ) ;
struct V_135 V_142 ;
if ( V_125 )
return F_111 ( V_133 , V_125 , V_126 ) ;
V_40 = F_106 ( V_2 , ( T_8 ) ( V_130 ) V_134 , V_126 , V_2 -> V_138 ,
F_107 ( V_2 -> V_138 ) ,
V_143 ) ;
if ( V_40 < 0 ) {
F_112 ( V_2 , L_2
L_3 , V_134 ,
( unsigned long long ) V_126 ) ;
goto V_140;
}
F_108 ( & V_142 , V_144 , V_2 -> V_138 , V_40 , V_126 ) ;
V_40 = F_113 ( V_133 , V_126 , & V_142 ) ;
if ( V_40 == V_126 )
V_40 = 0 ;
}
V_140:
return V_40 ;
}
static void T_1 * F_114 ( struct V_1 * V_2 ,
void T_1 * V_119 , unsigned int V_126 ,
int type )
{
int V_40 ;
V_40 = F_106 ( V_2 , ( T_8 ) ( V_130 ) V_119 , V_126 , V_2 -> V_138 ,
F_107 ( V_2 -> V_138 ) ,
V_143 ) ;
if ( V_40 < 0 ) {
F_112 ( V_2 , L_2
L_3 , V_119 ,
( unsigned long long ) V_126 ) ;
return NULL ;
}
if ( V_40 != 1 || V_2 -> V_138 [ 0 ] . V_145 != V_126 ) {
F_112 ( V_2 , L_4
L_3 , V_119 ,
( unsigned long long ) V_126 ) ;
return NULL ;
}
return V_2 -> V_138 [ 0 ] . V_146 ;
}
static inline void T_1 * F_115 ( struct V_1 * V_2 ,
void * V_119 , unsigned int V_126 ,
int type )
{
void T_1 * V_125 = F_100 ( V_2 ,
( T_8 ) ( V_130 ) V_119 , V_126 , type ) ;
if ( V_125 )
return V_125 ;
return F_114 ( V_2 , V_119 , V_126 , type ) ;
}
static void F_116 ( struct V_38 * V_50 )
{
int V_51 = 0 ;
for ( V_51 = 0 ; V_51 < V_50 -> V_52 ; ++ V_51 )
F_102 ( & V_50 -> V_53 [ V_51 ] -> V_90 ) ;
}
static void F_117 ( struct V_38 * V_50 )
{
int V_51 = 0 ;
for ( V_51 = 0 ; V_51 < V_50 -> V_52 ; ++ V_51 )
F_103 ( & V_50 -> V_53 [ V_51 ] -> V_90 ) ;
}
static int F_118 ( struct V_108 * V_74 ,
T_8 V_129 , T_8 V_126 , T_8 V_147 ,
T_8 V_128 , int V_148 )
{
struct V_110 * V_114 , * V_45 = F_58 ( sizeof( * V_45 ) , V_149 ) ;
if ( ! V_45 )
return - V_89 ;
if ( V_74 -> V_113 == V_150 ) {
V_114 = F_119 ( & V_74 -> V_109 , F_120 ( * V_114 ) , V_112 ) ;
F_82 ( V_74 , V_114 ) ;
}
V_45 -> V_129 = V_129 ;
V_45 -> V_126 = V_126 ;
V_45 -> V_151 = V_147 ;
V_45 -> V_128 = V_128 ;
V_45 -> V_148 = V_148 ;
F_63 ( & V_45 -> V_112 ) ;
F_121 ( & V_45 -> V_112 , & V_74 -> V_109 ) ;
F_122 ( V_45 , & V_74 -> V_111 ) ;
V_74 -> V_113 ++ ;
return 0 ;
}
static void F_123 ( struct V_108 * V_74 ,
T_8 V_129 , T_8 V_147 )
{
struct V_110 * V_45 ;
while ( ( V_45 = F_124 ( & V_74 -> V_111 ,
V_129 , V_147 ) ) )
F_82 ( V_74 , V_45 ) ;
}
static void F_125 ( struct V_38 * V_50 ,
struct V_152 * V_153 )
{
struct V_115 * V_45 , * V_116 ;
F_89 ( & V_50 -> V_94 ) ;
F_86 (node, n, &d->pending_list, node) {
struct V_152 * V_154 = & V_45 -> V_153 . V_75 ;
if ( V_153 -> V_155 <= V_154 -> V_155 &&
V_153 -> V_155 + V_153 -> V_126 - 1 > V_154 -> V_155 &&
V_154 -> type == V_156 ) {
F_18 ( & V_45 -> V_2 -> V_27 ) ;
F_84 ( & V_45 -> V_45 ) ;
F_56 ( V_45 ) ;
}
}
F_90 ( & V_50 -> V_94 ) ;
}
static int F_126 ( T_8 V_125 , T_8 V_126 , int V_157 )
{
unsigned long V_121 = V_125 ;
if ( F_97 ( V_125 , V_126 ) )
return - V_9 ;
if ( ( V_157 & V_143 ) &&
! F_96 ( V_158 , ( void T_1 * ) V_121 , V_126 ) )
return - V_9 ;
if ( ( V_157 & V_139 ) &&
! F_96 ( V_124 , ( void T_1 * ) V_121 , V_126 ) )
return - V_9 ;
return 0 ;
}
static int F_127 ( struct V_38 * V_39 ,
struct V_152 * V_153 )
{
int V_40 = 0 ;
F_116 ( V_39 ) ;
switch ( V_153 -> type ) {
case V_159 :
if ( ! V_39 -> V_75 ) {
V_40 = - V_9 ;
break;
}
if ( F_126 ( V_153 -> V_125 , V_153 -> V_126 , V_153 -> V_148 ) ) {
V_40 = - V_9 ;
break;
}
F_39 ( V_39 ) ;
if ( F_118 ( V_39 -> V_75 , V_153 -> V_155 , V_153 -> V_126 ,
V_153 -> V_155 + V_153 -> V_126 - 1 ,
V_153 -> V_125 , V_153 -> V_148 ) ) {
V_40 = - V_89 ;
break;
}
F_125 ( V_39 , V_153 ) ;
break;
case V_160 :
F_39 ( V_39 ) ;
F_123 ( V_39 -> V_75 , V_153 -> V_155 ,
V_153 -> V_155 + V_153 -> V_126 - 1 ) ;
break;
default:
V_40 = - V_13 ;
break;
}
F_117 ( V_39 ) ;
return V_40 ;
}
T_9 F_128 ( struct V_38 * V_39 ,
struct V_135 * V_134 )
{
struct V_115 V_45 ;
unsigned V_126 = sizeof( struct V_161 ) ;
T_10 V_40 ;
int V_103 ;
if ( F_129 ( V_134 ) < V_126 )
return 0 ;
V_40 = F_113 ( & V_45 . V_153 , V_126 , V_134 ) ;
if ( V_40 != V_126 )
goto V_37;
switch ( V_45 . V_153 . type ) {
case V_162 :
V_103 = F_127 ( V_39 , & V_45 . V_153 . V_75 ) ;
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
unsigned int F_130 ( struct V_23 * V_23 , struct V_38 * V_39 ,
T_4 * V_29 )
{
unsigned int V_33 = 0 ;
F_131 ( V_23 , & V_39 -> V_29 , V_29 ) ;
if ( ! F_132 ( & V_39 -> V_92 ) )
V_33 |= V_96 | V_118 ;
return V_33 ;
}
T_9 F_133 ( struct V_38 * V_39 , struct V_135 * V_133 ,
int V_163 )
{
F_134 ( V_29 ) ;
struct V_115 * V_45 ;
T_9 V_40 = 0 ;
unsigned V_126 = sizeof( struct V_161 ) ;
if ( F_129 ( V_133 ) < V_126 )
return 0 ;
while ( 1 ) {
if ( ! V_163 )
F_135 ( & V_39 -> V_29 , & V_29 ,
V_82 ) ;
V_45 = F_136 ( V_39 , & V_39 -> V_92 ) ;
if ( V_45 )
break;
if ( V_163 ) {
V_40 = - V_164 ;
break;
}
if ( F_137 ( V_97 ) ) {
V_40 = - V_165 ;
break;
}
if ( ! V_39 -> V_75 ) {
V_40 = - V_166 ;
break;
}
F_49 () ;
}
if ( ! V_163 )
F_138 ( & V_39 -> V_29 , & V_29 ) ;
if ( V_45 ) {
V_40 = F_109 ( & V_45 -> V_153 , V_126 , V_133 ) ;
if ( V_40 != V_126 || V_45 -> V_153 . type != V_156 ) {
F_56 ( V_45 ) ;
return V_40 ;
}
F_139 ( V_39 , & V_39 -> V_93 , V_45 ) ;
}
return V_40 ;
}
static int F_140 ( struct V_1 * V_2 , T_8 V_155 , int V_157 )
{
struct V_38 * V_39 = V_2 -> V_39 ;
struct V_115 * V_45 ;
struct V_152 * V_153 ;
V_45 = F_141 ( V_2 , V_156 ) ;
if ( ! V_45 )
return - V_89 ;
V_153 = & V_45 -> V_153 . V_75 ;
V_153 -> type = V_156 ;
V_153 -> V_155 = V_155 ;
V_153 -> V_148 = V_157 ;
F_139 ( V_39 , & V_39 -> V_92 , V_45 ) ;
return 0 ;
}
static int F_142 ( struct V_1 * V_2 , unsigned int V_10 ,
struct V_167 T_1 * V_54 ,
struct V_168 T_1 * V_55 ,
struct V_169 T_1 * V_56 )
{
T_10 V_6 = F_10 ( V_2 , V_170 ) ? 2 : 0 ;
return F_96 ( V_158 , V_54 , V_10 * sizeof *V_54 ) &&
F_96 ( V_158 , V_55 ,
sizeof *V_55 + V_10 * sizeof * V_55 -> V_171 + V_6 ) &&
F_96 ( V_124 , V_56 ,
sizeof *V_56 + V_10 * sizeof * V_56 -> V_171 + V_6 ) ;
}
static void F_143 ( struct V_1 * V_2 ,
const struct V_110 * V_45 ,
int type )
{
int V_157 = ( type == V_172 ) ?
V_139 : V_143 ;
if ( F_144 ( V_45 -> V_148 & V_157 ) )
V_2 -> V_49 [ type ] = V_45 ;
}
static int F_145 ( struct V_1 * V_2 ,
int V_157 , T_8 V_119 , T_8 V_173 , int type )
{
const struct V_110 * V_45 ;
struct V_108 * V_74 = V_2 -> V_75 ;
T_8 V_6 = 0 , V_126 , V_174 = V_119 ;
if ( F_100 ( V_2 , V_119 , V_173 , type ) )
return true ;
while ( V_173 > V_6 ) {
V_45 = F_124 ( & V_74 -> V_111 ,
V_119 ,
V_119 + V_173 - 1 ) ;
if ( V_45 == NULL || V_45 -> V_129 > V_119 ) {
F_140 ( V_2 , V_119 , V_157 ) ;
return false ;
} else if ( ! ( V_45 -> V_148 & V_157 ) ) {
return false ;
}
V_126 = V_45 -> V_126 - V_119 + V_45 -> V_129 ;
if ( V_174 == V_119 && V_126 >= V_173 )
F_143 ( V_2 , V_45 , type ) ;
V_6 += V_126 ;
V_119 += V_126 ;
}
return true ;
}
int F_146 ( struct V_1 * V_2 )
{
T_10 V_6 = F_10 ( V_2 , V_170 ) ? 2 : 0 ;
unsigned int V_10 = V_2 -> V_10 ;
if ( ! V_2 -> V_75 )
return 1 ;
return F_145 ( V_2 , V_143 , ( T_8 ) ( V_130 ) V_2 -> V_54 ,
V_10 * sizeof( * V_2 -> V_54 ) , V_137 ) &&
F_145 ( V_2 , V_143 , ( T_8 ) ( V_130 ) V_2 -> V_55 ,
sizeof * V_2 -> V_55 +
V_10 * sizeof( * V_2 -> V_55 -> V_171 ) + V_6 ,
V_175 ) &&
F_145 ( V_2 , V_139 , ( T_8 ) ( V_130 ) V_2 -> V_56 ,
sizeof * V_2 -> V_56 +
V_10 * sizeof( * V_2 -> V_56 -> V_171 ) + V_6 ,
V_172 ) ;
}
int F_147 ( struct V_38 * V_39 )
{
return F_101 ( V_39 , V_39 -> V_74 , 1 ) ;
}
static int F_148 ( struct V_1 * V_2 ,
void T_1 * V_67 )
{
T_10 V_6 = F_10 ( V_2 , V_170 ) ? 2 : 0 ;
return F_98 ( V_67 , V_2 -> V_74 ,
F_10 ( V_2 , V_132 ) ) &&
( ! V_2 -> V_64 || F_95 ( V_67 , V_2 -> V_65 ,
sizeof * V_2 -> V_56 +
V_2 -> V_10 * sizeof * V_2 -> V_56 -> V_171 + V_6 ) ) ;
}
int F_149 ( struct V_1 * V_2 )
{
if ( V_2 -> V_75 ) {
return 1 ;
}
return F_142 ( V_2 , V_2 -> V_10 , V_2 -> V_54 , V_2 -> V_55 , V_2 -> V_56 ) &&
F_148 ( V_2 , V_2 -> V_67 ) ;
}
static struct V_108 * F_150 ( void )
{
struct V_108 * V_74 = F_78 ( sizeof( * V_74 ) , V_87 ) ;
if ( ! V_74 )
return NULL ;
V_74 -> V_111 = V_176 ;
V_74 -> V_113 = 0 ;
F_63 ( & V_74 -> V_109 ) ;
return V_74 ;
}
static long F_151 ( struct V_38 * V_50 , struct V_177 T_1 * V_178 )
{
struct V_177 V_179 , * V_180 ;
struct V_181 * V_182 ;
struct V_108 * V_183 , * V_184 ;
unsigned long V_126 = F_152 ( struct V_177 , V_185 ) ;
int V_51 ;
if ( F_6 ( & V_179 , V_178 , V_126 ) )
return - V_9 ;
if ( V_179 . V_186 )
return - V_187 ;
if ( V_179 . V_188 > V_189 )
return - V_190 ;
V_180 = F_78 ( V_126 + V_179 . V_188 * sizeof( * V_178 -> V_185 ) , V_87 ) ;
if ( ! V_180 )
return - V_89 ;
memcpy ( V_180 , & V_179 , V_126 ) ;
if ( F_6 ( V_180 -> V_185 , V_178 -> V_185 ,
V_179 . V_188 * sizeof * V_178 -> V_185 ) ) {
F_87 ( V_180 ) ;
return - V_9 ;
}
V_183 = F_150 () ;
if ( ! V_183 ) {
F_87 ( V_180 ) ;
return - V_89 ;
}
for ( V_182 = V_180 -> V_185 ;
V_182 < V_180 -> V_185 + V_179 . V_188 ;
V_182 ++ ) {
if ( F_118 ( V_183 ,
V_182 -> V_191 ,
V_182 -> V_192 ,
V_182 -> V_191 +
V_182 -> V_192 - 1 ,
V_182 -> V_128 ,
V_193 ) )
goto V_103;
}
if ( ! F_101 ( V_50 , V_183 , 0 ) )
goto V_103;
V_184 = V_50 -> V_74 ;
V_50 -> V_74 = V_183 ;
for ( V_51 = 0 ; V_51 < V_50 -> V_52 ; ++ V_51 ) {
F_102 ( & V_50 -> V_53 [ V_51 ] -> V_90 ) ;
V_50 -> V_53 [ V_51 ] -> V_74 = V_183 ;
F_103 ( & V_50 -> V_53 [ V_51 ] -> V_90 ) ;
}
F_87 ( V_180 ) ;
F_85 ( V_184 ) ;
return 0 ;
V_103:
F_85 ( V_183 ) ;
F_87 ( V_180 ) ;
return - V_9 ;
}
long F_153 ( struct V_38 * V_50 , int V_194 , void T_1 * V_4 )
{
struct V_23 * V_195 , * V_196 = NULL ;
bool V_197 = false , V_198 = false ;
struct V_199 * V_200 = NULL ;
T_2 T_1 * V_201 = V_4 ;
struct V_1 * V_2 ;
struct V_5 V_6 ;
struct V_202 V_142 ;
struct V_203 V_121 ;
T_2 V_14 ;
long V_204 ;
V_204 = F_154 ( V_14 , V_201 ) ;
if ( V_204 < 0 )
return V_204 ;
if ( V_14 >= V_50 -> V_52 )
return - V_205 ;
V_2 = V_50 -> V_53 [ V_14 ] ;
F_102 ( & V_2 -> V_90 ) ;
switch ( V_194 ) {
case V_206 :
if ( V_2 -> V_7 ) {
V_204 = - V_8 ;
break;
}
if ( F_6 ( & V_6 , V_4 , sizeof V_6 ) ) {
V_204 = - V_9 ;
break;
}
if ( ! V_6 . V_10 || V_6 . V_10 > 0xffff || ( V_6 . V_10 & ( V_6 . V_10 - 1 ) ) ) {
V_204 = - V_13 ;
break;
}
V_2 -> V_10 = V_6 . V_10 ;
break;
case V_207 :
if ( V_2 -> V_7 ) {
V_204 = - V_8 ;
break;
}
if ( F_6 ( & V_6 , V_4 , sizeof V_6 ) ) {
V_204 = - V_9 ;
break;
}
if ( V_6 . V_10 > 0xffff ) {
V_204 = - V_13 ;
break;
}
V_2 -> V_57 = V_2 -> V_58 = V_6 . V_10 ;
V_2 -> V_59 = V_2 -> V_57 ;
break;
case V_208 :
V_6 . V_15 = V_14 ;
V_6 . V_10 = V_2 -> V_57 ;
if ( F_8 ( V_4 , & V_6 , sizeof V_6 ) )
V_204 = - V_9 ;
break;
case V_209 :
if ( F_6 ( & V_121 , V_4 , sizeof V_121 ) ) {
V_204 = - V_9 ;
break;
}
if ( V_121 . V_36 & ~ ( 0x1 << V_210 ) ) {
V_204 = - V_187 ;
break;
}
if ( ( T_8 ) ( unsigned long ) V_121 . V_211 != V_121 . V_211 ||
( T_8 ) ( unsigned long ) V_121 . V_212 != V_121 . V_212 ||
( T_8 ) ( unsigned long ) V_121 . V_213 != V_121 . V_213 ) {
V_204 = - V_9 ;
break;
}
F_155 ( V_214 * V_2 -> V_55 > V_215 ) ;
F_155 ( V_214 * V_2 -> V_56 > V_216 ) ;
if ( ( V_121 . V_213 & ( V_215 - 1 ) ) ||
( V_121 . V_212 & ( V_216 - 1 ) ) ||
( V_121 . V_217 & ( V_216 - 1 ) ) ) {
V_204 = - V_13 ;
break;
}
if ( V_2 -> V_7 ) {
if ( ! F_142 ( V_2 , V_2 -> V_10 ,
( void T_1 * ) ( unsigned long ) V_121 . V_211 ,
( void T_1 * ) ( unsigned long ) V_121 . V_213 ,
( void T_1 * ) ( unsigned long ) V_121 . V_212 ) ) {
V_204 = - V_13 ;
break;
}
if ( ( V_121 . V_36 & ( 0x1 << V_210 ) ) &&
! F_95 ( V_2 -> V_67 , V_121 . V_217 ,
sizeof * V_2 -> V_56 +
V_2 -> V_10 * sizeof * V_2 -> V_56 -> V_171 ) ) {
V_204 = - V_13 ;
break;
}
}
V_2 -> V_64 = ! ! ( V_121 . V_36 & ( 0x1 << V_210 ) ) ;
V_2 -> V_54 = ( void T_1 * ) ( unsigned long ) V_121 . V_211 ;
V_2 -> V_55 = ( void T_1 * ) ( unsigned long ) V_121 . V_213 ;
V_2 -> V_65 = V_121 . V_217 ;
V_2 -> V_56 = ( void T_1 * ) ( unsigned long ) V_121 . V_212 ;
break;
case V_218 :
if ( F_6 ( & V_142 , V_4 , sizeof V_142 ) ) {
V_204 = - V_9 ;
break;
}
V_195 = V_142 . V_219 == - 1 ? NULL : F_156 ( V_142 . V_219 ) ;
if ( F_73 ( V_195 ) ) {
V_204 = F_74 ( V_195 ) ;
break;
}
if ( V_195 != V_2 -> V_69 ) {
V_198 = ( V_196 = V_2 -> V_69 ) != NULL ;
V_197 = ( V_2 -> V_69 = V_195 ) != NULL ;
} else
V_196 = V_195 ;
break;
case V_220 :
if ( F_6 ( & V_142 , V_4 , sizeof V_142 ) ) {
V_204 = - V_9 ;
break;
}
V_195 = V_142 . V_219 == - 1 ? NULL : F_156 ( V_142 . V_219 ) ;
if ( F_73 ( V_195 ) ) {
V_204 = F_74 ( V_195 ) ;
break;
}
if ( V_195 != V_2 -> V_71 ) {
V_196 = V_2 -> V_71 ;
V_200 = V_2 -> V_70 ;
V_2 -> V_71 = V_195 ;
V_2 -> V_70 = V_195 ?
F_157 ( V_195 ) : NULL ;
} else
V_196 = V_195 ;
break;
case V_221 :
if ( F_6 ( & V_142 , V_4 , sizeof V_142 ) ) {
V_204 = - V_9 ;
break;
}
V_195 = V_142 . V_219 == - 1 ? NULL : F_156 ( V_142 . V_219 ) ;
if ( F_73 ( V_195 ) ) {
V_204 = F_74 ( V_195 ) ;
break;
}
if ( V_195 != V_2 -> error ) {
V_196 = V_2 -> error ;
V_2 -> error = V_195 ;
V_200 = V_2 -> V_68 ;
V_2 -> V_68 = V_195 ?
F_157 ( V_195 ) : NULL ;
} else
V_196 = V_195 ;
break;
case V_222 :
V_204 = F_5 ( V_2 , V_4 ) ;
break;
case V_223 :
V_204 = F_7 ( V_2 , V_14 , V_4 ) ;
break;
case V_224 :
if ( F_6 ( & V_6 , V_4 , sizeof( V_6 ) ) ) {
V_204 = - V_9 ;
break;
}
V_2 -> V_73 = V_6 . V_10 ;
break;
case V_225 :
V_6 . V_15 = V_14 ;
V_6 . V_10 = V_2 -> V_73 ;
if ( F_8 ( V_4 , & V_6 , sizeof( V_6 ) ) )
V_204 = - V_9 ;
break;
default:
V_204 = - V_18 ;
}
if ( V_198 && V_2 -> V_95 )
F_27 ( & V_2 -> V_27 ) ;
if ( V_200 )
F_91 ( V_200 ) ;
if ( V_196 )
F_92 ( V_196 ) ;
if ( V_197 && V_2 -> V_95 )
V_204 = F_25 ( & V_2 -> V_27 , V_2 -> V_69 ) ;
F_103 ( & V_2 -> V_90 ) ;
if ( V_198 && V_2 -> V_95 )
F_32 ( & V_2 -> V_27 ) ;
return V_204 ;
}
int F_158 ( struct V_38 * V_50 , bool V_226 )
{
struct V_108 * V_227 , * V_228 ;
int V_51 ;
V_227 = F_150 () ;
if ( ! V_227 )
return - V_89 ;
V_228 = V_50 -> V_75 ;
V_50 -> V_75 = V_227 ;
for ( V_51 = 0 ; V_51 < V_50 -> V_52 ; ++ V_51 ) {
F_102 ( & V_50 -> V_53 [ V_51 ] -> V_90 ) ;
V_50 -> V_53 [ V_51 ] -> V_75 = V_227 ;
F_103 ( & V_50 -> V_53 [ V_51 ] -> V_90 ) ;
}
F_85 ( V_228 ) ;
return 0 ;
}
long F_159 ( struct V_38 * V_50 , unsigned int V_194 , void T_1 * V_4 )
{
struct V_23 * V_195 , * V_196 = NULL ;
struct V_199 * V_200 = NULL ;
T_8 V_229 ;
long V_204 ;
int V_51 , V_219 ;
if ( V_194 == V_230 ) {
V_204 = F_70 ( V_50 ) ;
goto V_37;
}
V_204 = F_65 ( V_50 ) ;
if ( V_204 )
goto V_37;
switch ( V_194 ) {
case V_231 :
V_204 = F_151 ( V_50 , V_4 ) ;
break;
case V_232 :
if ( F_6 ( & V_229 , V_4 , sizeof V_229 ) ) {
V_204 = - V_9 ;
break;
}
if ( ( T_8 ) ( unsigned long ) V_229 != V_229 ) {
V_204 = - V_9 ;
break;
}
for ( V_51 = 0 ; V_51 < V_50 -> V_52 ; ++ V_51 ) {
struct V_1 * V_2 ;
void T_1 * V_233 = ( void T_1 * ) ( unsigned long ) V_229 ;
V_2 = V_50 -> V_53 [ V_51 ] ;
F_102 ( & V_2 -> V_90 ) ;
if ( V_2 -> V_7 && ! F_148 ( V_2 , V_233 ) )
V_204 = - V_9 ;
else
V_2 -> V_67 = V_233 ;
F_103 ( & V_2 -> V_90 ) ;
}
break;
case V_234 :
V_204 = F_154 ( V_219 , ( int T_1 * ) V_4 ) ;
if ( V_204 < 0 )
break;
V_195 = V_219 == - 1 ? NULL : F_156 ( V_219 ) ;
if ( F_73 ( V_195 ) ) {
V_204 = F_74 ( V_195 ) ;
break;
}
if ( V_195 != V_50 -> V_91 ) {
V_196 = V_50 -> V_91 ;
V_50 -> V_91 = V_195 ;
V_200 = V_50 -> V_72 ;
V_50 -> V_72 = V_195 ?
F_157 ( V_195 ) : NULL ;
} else
V_196 = V_195 ;
for ( V_51 = 0 ; V_51 < V_50 -> V_52 ; ++ V_51 ) {
F_102 ( & V_50 -> V_53 [ V_51 ] -> V_90 ) ;
V_50 -> V_53 [ V_51 ] -> V_72 = V_50 -> V_72 ;
F_103 ( & V_50 -> V_53 [ V_51 ] -> V_90 ) ;
}
if ( V_200 )
F_91 ( V_200 ) ;
if ( V_196 )
F_92 ( V_196 ) ;
break;
default:
V_204 = - V_18 ;
break;
}
V_37:
return V_204 ;
}
static int F_160 ( int V_235 , void T_1 * V_119 )
{
unsigned long log = ( unsigned long ) V_119 ;
struct V_236 * V_236 ;
void * V_233 ;
int V_237 = V_235 + ( log % V_238 ) * 8 ;
int V_204 ;
V_204 = F_161 ( log , 1 , 1 , & V_236 ) ;
if ( V_204 < 0 )
return V_204 ;
F_162 ( V_204 != 1 ) ;
V_233 = F_163 ( V_236 ) ;
F_164 ( V_237 , V_233 ) ;
F_165 ( V_233 ) ;
F_166 ( V_236 ) ;
F_167 ( V_236 ) ;
return 0 ;
}
static int F_168 ( void T_1 * V_67 ,
T_8 V_239 , T_8 V_240 )
{
T_8 V_241 = V_239 / V_122 ;
int V_204 ;
if ( ! V_240 )
return 0 ;
V_240 += V_239 % V_122 ;
for (; ; ) {
T_8 V_233 = ( T_8 ) ( unsigned long ) V_67 ;
T_8 log = V_233 + V_241 / 8 ;
int V_237 = V_241 % 8 ;
if ( ( T_8 ) ( unsigned long ) log != log )
return - V_9 ;
V_204 = F_160 ( V_237 , ( void T_1 * ) ( unsigned long ) log ) ;
if ( V_204 < 0 )
return V_204 ;
if ( V_240 <= V_122 )
break;
V_240 -= V_122 ;
V_241 += 1 ;
}
return V_204 ;
}
int F_169 ( struct V_1 * V_2 , struct V_242 * log ,
unsigned int V_243 , T_8 V_173 )
{
int V_51 , V_204 ;
F_51 () ;
for ( V_51 = 0 ; V_51 < V_243 ; ++ V_51 ) {
T_8 V_244 = F_170 ( log [ V_51 ] . V_173 , V_173 ) ;
V_204 = F_168 ( V_2 -> V_67 , log [ V_51 ] . V_119 , V_244 ) ;
if ( V_204 < 0 )
return V_204 ;
V_173 -= V_244 ;
if ( ! V_173 ) {
if ( V_2 -> V_72 )
F_171 ( V_2 -> V_72 , 1 ) ;
return 0 ;
}
}
F_172 () ;
return 0 ;
}
static int F_173 ( struct V_1 * V_2 )
{
void T_1 * V_56 ;
if ( F_174 ( V_2 , F_175 ( V_2 , V_2 -> V_63 ) ,
& V_2 -> V_56 -> V_36 ) < 0 )
return - V_9 ;
if ( F_176 ( V_2 -> V_64 ) ) {
F_51 () ;
V_56 = & V_2 -> V_56 -> V_36 ;
F_168 ( V_2 -> V_67 , V_2 -> V_65 +
( V_56 - ( void T_1 * ) V_2 -> V_56 ) ,
sizeof V_2 -> V_56 -> V_36 ) ;
if ( V_2 -> V_72 )
F_171 ( V_2 -> V_72 , 1 ) ;
}
return 0 ;
}
static int F_177 ( struct V_1 * V_2 , T_11 V_245 )
{
if ( F_174 ( V_2 , F_175 ( V_2 , V_2 -> V_59 ) ,
F_178 ( V_2 ) ) )
return - V_9 ;
if ( F_176 ( V_2 -> V_64 ) ) {
void T_1 * V_56 ;
F_51 () ;
V_56 = F_178 ( V_2 ) ;
F_168 ( V_2 -> V_67 , V_2 -> V_65 +
( V_56 - ( void T_1 * ) V_2 -> V_56 ) ,
sizeof * F_178 ( V_2 ) ) ;
if ( V_2 -> V_72 )
F_171 ( V_2 -> V_72 , 1 ) ;
}
return 0 ;
}
int F_179 ( struct V_1 * V_2 )
{
T_12 V_60 ;
int V_204 ;
bool V_16 = V_2 -> V_16 ;
if ( ! V_2 -> V_7 )
return 0 ;
F_9 ( V_2 ) ;
V_204 = F_173 ( V_2 ) ;
if ( V_204 )
goto V_103;
V_2 -> V_62 = false ;
if ( ! V_2 -> V_75 &&
! F_96 ( V_158 , & V_2 -> V_56 -> V_14 , sizeof V_2 -> V_56 -> V_14 ) ) {
V_204 = - V_9 ;
goto V_103;
}
V_204 = F_180 ( V_2 , V_60 , & V_2 -> V_56 -> V_14 ) ;
if ( V_204 ) {
F_112 ( V_2 , L_5 ,
& V_2 -> V_56 -> V_14 ) ;
goto V_103;
}
V_2 -> V_60 = F_181 ( V_2 , V_60 ) ;
return 0 ;
V_103:
V_2 -> V_16 = V_16 ;
return V_204 ;
}
static int F_106 ( struct V_1 * V_2 , T_8 V_119 , T_2 V_173 ,
struct V_246 V_247 [] , int V_248 , int V_157 )
{
const struct V_110 * V_45 ;
struct V_38 * V_39 = V_2 -> V_39 ;
struct V_108 * V_74 = V_39 -> V_75 ? V_39 -> V_75 : V_39 -> V_74 ;
struct V_246 * V_249 ;
T_8 V_6 = 0 ;
int V_40 = 0 ;
while ( ( T_8 ) V_173 > V_6 ) {
T_8 V_126 ;
if ( F_176 ( V_40 >= V_248 ) ) {
V_40 = - V_205 ;
break;
}
V_45 = F_124 ( & V_74 -> V_111 ,
V_119 , V_119 + V_173 - 1 ) ;
if ( V_45 == NULL || V_45 -> V_129 > V_119 ) {
if ( V_74 != V_39 -> V_75 ) {
V_40 = - V_9 ;
break;
}
V_40 = - V_164 ;
break;
} else if ( ! ( V_45 -> V_148 & V_157 ) ) {
V_40 = - V_98 ;
break;
}
V_249 = V_247 + V_40 ;
V_126 = V_45 -> V_126 - V_119 + V_45 -> V_129 ;
V_249 -> V_145 = F_170 ( ( T_8 ) V_173 - V_6 , V_126 ) ;
V_249 -> V_146 = ( void T_1 * ) ( unsigned long )
( V_45 -> V_128 + V_119 - V_45 -> V_129 ) ;
V_6 += V_126 ;
V_119 += V_126 ;
++ V_40 ;
}
if ( V_40 == - V_164 )
F_140 ( V_2 , V_119 , V_157 ) ;
return V_40 ;
}
static unsigned F_182 ( struct V_1 * V_2 , struct V_167 * V_54 )
{
unsigned int V_250 ;
if ( ! ( V_54 -> V_36 & F_175 ( V_2 , V_251 ) ) )
return - 1U ;
V_250 = F_181 ( V_2 , V_54 -> V_250 ) ;
F_183 () ;
return V_250 ;
}
static int F_184 ( struct V_1 * V_2 ,
struct V_246 V_247 [] , unsigned int V_248 ,
unsigned int * V_252 , unsigned int * V_253 ,
struct V_242 * log , unsigned int * V_243 ,
struct V_167 * V_84 )
{
struct V_167 V_54 ;
unsigned int V_51 = 0 , V_254 , V_255 = 0 ;
T_2 V_173 = F_185 ( V_2 , V_84 -> V_173 ) ;
struct V_135 V_134 ;
int V_40 , V_157 ;
if ( F_176 ( V_173 % sizeof V_54 ) ) {
F_112 ( V_2 , L_6
L_7 ,
( unsigned long long ) V_173 ,
sizeof V_54 ) ;
return - V_13 ;
}
V_40 = F_106 ( V_2 , F_186 ( V_2 , V_84 -> V_119 ) , V_173 , V_2 -> V_84 ,
V_86 , V_143 ) ;
if ( F_176 ( V_40 < 0 ) ) {
if ( V_40 != - V_164 )
F_112 ( V_2 , L_8 , V_40 ) ;
return V_40 ;
}
F_108 ( & V_134 , V_144 , V_2 -> V_84 , V_40 , V_173 ) ;
F_183 () ;
V_254 = V_173 / sizeof V_54 ;
if ( F_176 ( V_254 > V_256 + 1 ) ) {
F_112 ( V_2 , L_9 ,
V_84 -> V_173 ) ;
return - V_190 ;
}
do {
unsigned V_257 = * V_253 + * V_252 ;
if ( F_176 ( ++ V_255 > V_254 ) ) {
F_112 ( V_2 , L_10
L_11 ,
V_51 , V_254 ) ;
return - V_13 ;
}
if ( F_176 ( ! F_187 ( & V_54 , sizeof( V_54 ) , & V_134 ) ) ) {
F_112 ( V_2 , L_12 ,
V_51 , ( T_10 ) F_186 ( V_2 , V_84 -> V_119 ) + V_51 * sizeof V_54 ) ;
return - V_13 ;
}
if ( F_176 ( V_54 . V_36 & F_175 ( V_2 , V_258 ) ) ) {
F_112 ( V_2 , L_13 ,
V_51 , ( T_10 ) F_186 ( V_2 , V_84 -> V_119 ) + V_51 * sizeof V_54 ) ;
return - V_13 ;
}
if ( V_54 . V_36 & F_175 ( V_2 , V_259 ) )
V_157 = V_139 ;
else
V_157 = V_143 ;
V_40 = F_106 ( V_2 , F_186 ( V_2 , V_54 . V_119 ) ,
F_185 ( V_2 , V_54 . V_173 ) , V_247 + V_257 ,
V_248 - V_257 , V_157 ) ;
if ( F_176 ( V_40 < 0 ) ) {
if ( V_40 != - V_164 )
F_112 ( V_2 , L_14 ,
V_40 , V_51 ) ;
return V_40 ;
}
if ( V_157 == V_139 ) {
* V_253 += V_40 ;
if ( F_176 ( log ) ) {
log [ * V_243 ] . V_119 = F_186 ( V_2 , V_54 . V_119 ) ;
log [ * V_243 ] . V_173 = F_185 ( V_2 , V_54 . V_173 ) ;
++ * V_243 ;
}
} else {
if ( F_176 ( * V_253 ) ) {
F_112 ( V_2 , L_15
L_16 , V_51 ) ;
return - V_13 ;
}
* V_252 += V_40 ;
}
} while ( ( V_51 = F_182 ( V_2 , & V_54 ) ) != - 1 );
return 0 ;
}
int F_188 ( struct V_1 * V_2 ,
struct V_246 V_247 [] , unsigned int V_248 ,
unsigned int * V_252 , unsigned int * V_253 ,
struct V_242 * log , unsigned int * V_243 )
{
struct V_167 V_54 ;
unsigned int V_51 , V_260 , V_255 = 0 ;
T_11 V_57 ;
T_12 V_59 ;
T_12 V_261 ;
int V_40 , V_157 ;
V_57 = V_2 -> V_57 ;
if ( V_2 -> V_59 == V_2 -> V_57 ) {
if ( F_176 ( F_189 ( V_2 , V_59 , & V_2 -> V_55 -> V_14 ) ) ) {
F_112 ( V_2 , L_17 ,
& V_2 -> V_55 -> V_14 ) ;
return - V_9 ;
}
V_2 -> V_59 = F_181 ( V_2 , V_59 ) ;
if ( F_176 ( ( T_11 ) ( V_2 -> V_59 - V_57 ) > V_2 -> V_10 ) ) {
F_112 ( V_2 , L_18 ,
V_57 , V_2 -> V_59 ) ;
return - V_9 ;
}
if ( V_2 -> V_59 == V_57 )
return V_2 -> V_10 ;
F_190 () ;
}
if ( F_176 ( F_189 ( V_2 , V_261 ,
& V_2 -> V_55 -> V_171 [ V_57 & ( V_2 -> V_10 - 1 ) ] ) ) ) {
F_112 ( V_2 , L_19 ,
V_57 ,
& V_2 -> V_55 -> V_171 [ V_57 % V_2 -> V_10 ] ) ;
return - V_9 ;
}
V_260 = F_181 ( V_2 , V_261 ) ;
if ( F_176 ( V_260 >= V_2 -> V_10 ) ) {
F_112 ( V_2 , L_20 ,
V_260 , V_2 -> V_10 ) ;
return - V_13 ;
}
* V_252 = * V_253 = 0 ;
if ( F_176 ( log ) )
* V_243 = 0 ;
V_51 = V_260 ;
do {
unsigned V_257 = * V_253 + * V_252 ;
if ( F_176 ( V_51 >= V_2 -> V_10 ) ) {
F_112 ( V_2 , L_21 ,
V_51 , V_2 -> V_10 , V_260 ) ;
return - V_13 ;
}
if ( F_176 ( ++ V_255 > V_2 -> V_10 ) ) {
F_112 ( V_2 , L_10
L_22 ,
V_51 , V_2 -> V_10 , V_260 ) ;
return - V_13 ;
}
V_40 = F_110 ( V_2 , & V_54 , V_2 -> V_54 + V_51 ,
sizeof V_54 ) ;
if ( F_176 ( V_40 ) ) {
F_112 ( V_2 , L_23 ,
V_51 , V_2 -> V_54 + V_51 ) ;
return - V_9 ;
}
if ( V_54 . V_36 & F_175 ( V_2 , V_258 ) ) {
V_40 = F_184 ( V_2 , V_247 , V_248 ,
V_252 , V_253 ,
log , V_243 , & V_54 ) ;
if ( F_176 ( V_40 < 0 ) ) {
if ( V_40 != - V_164 )
F_112 ( V_2 , L_24
L_25 , V_51 ) ;
return V_40 ;
}
continue;
}
if ( V_54 . V_36 & F_175 ( V_2 , V_259 ) )
V_157 = V_139 ;
else
V_157 = V_143 ;
V_40 = F_106 ( V_2 , F_186 ( V_2 , V_54 . V_119 ) ,
F_185 ( V_2 , V_54 . V_173 ) , V_247 + V_257 ,
V_248 - V_257 , V_157 ) ;
if ( F_176 ( V_40 < 0 ) ) {
if ( V_40 != - V_164 )
F_112 ( V_2 , L_26 ,
V_40 , V_51 ) ;
return V_40 ;
}
if ( V_157 == V_139 ) {
* V_253 += V_40 ;
if ( F_176 ( log ) ) {
log [ * V_243 ] . V_119 = F_186 ( V_2 , V_54 . V_119 ) ;
log [ * V_243 ] . V_173 = F_185 ( V_2 , V_54 . V_173 ) ;
++ * V_243 ;
}
} else {
if ( F_176 ( * V_253 ) ) {
F_112 ( V_2 , L_27
L_28 , V_51 ) ;
return - V_13 ;
}
* V_252 += V_40 ;
}
} while ( ( V_51 = F_182 ( V_2 , & V_54 ) ) != - 1 );
V_2 -> V_57 ++ ;
F_162 ( ! ( V_2 -> V_63 & V_262 ) ) ;
return V_260 ;
}
void F_191 ( struct V_1 * V_2 , int V_116 )
{
V_2 -> V_57 -= V_116 ;
}
int F_192 ( struct V_1 * V_2 , unsigned int V_260 , int V_173 )
{
struct V_263 V_85 = {
F_193 ( V_2 , V_260 ) ,
F_193 (vq, len)
} ;
return F_194 ( V_2 , & V_85 , 1 ) ;
}
static int F_195 ( struct V_1 * V_2 ,
struct V_263 * V_85 ,
unsigned V_254 )
{
struct V_263 T_1 * V_56 ;
T_11 V_264 , V_265 ;
int V_129 ;
V_129 = V_2 -> V_60 & ( V_2 -> V_10 - 1 ) ;
V_56 = V_2 -> V_56 -> V_171 + V_129 ;
if ( V_254 == 1 ) {
if ( F_174 ( V_2 , V_85 [ 0 ] . V_266 , & V_56 -> V_266 ) ) {
F_112 ( V_2 , L_29 ) ;
return - V_9 ;
}
if ( F_174 ( V_2 , V_85 [ 0 ] . V_173 , & V_56 -> V_173 ) ) {
F_112 ( V_2 , L_30 ) ;
return - V_9 ;
}
} else if ( F_104 ( V_2 , V_56 , V_85 , V_254 * sizeof *V_56 ) ) {
F_112 ( V_2 , L_31 ) ;
return - V_9 ;
}
if ( F_176 ( V_2 -> V_64 ) ) {
F_51 () ;
F_168 ( V_2 -> V_67 ,
V_2 -> V_65 +
( ( void T_1 * ) V_56 - ( void T_1 * ) V_2 -> V_56 ) ,
V_254 * sizeof *V_56 ) ;
}
V_264 = V_2 -> V_60 ;
V_265 = ( V_2 -> V_60 += V_254 ) ;
if ( F_176 ( ( T_11 ) ( V_265 - V_2 -> V_61 ) < ( T_11 ) ( V_265 - V_264 ) ) )
V_2 -> V_62 = false ;
return 0 ;
}
int F_194 ( struct V_1 * V_2 , struct V_263 * V_85 ,
unsigned V_254 )
{
int V_129 , V_116 , V_204 ;
V_129 = V_2 -> V_60 & ( V_2 -> V_10 - 1 ) ;
V_116 = V_2 -> V_10 - V_129 ;
if ( V_116 < V_254 ) {
V_204 = F_195 ( V_2 , V_85 , V_116 ) ;
if ( V_204 < 0 )
return V_204 ;
V_85 += V_116 ;
V_254 -= V_116 ;
}
V_204 = F_195 ( V_2 , V_85 , V_254 ) ;
F_51 () ;
if ( F_174 ( V_2 , F_175 ( V_2 , V_2 -> V_60 ) ,
& V_2 -> V_56 -> V_14 ) ) {
F_112 ( V_2 , L_32 ) ;
return - V_9 ;
}
if ( F_176 ( V_2 -> V_64 ) ) {
F_168 ( V_2 -> V_67 ,
V_2 -> V_65 + F_152 ( struct V_169 , V_14 ) ,
sizeof V_2 -> V_56 -> V_14 ) ;
if ( V_2 -> V_72 )
F_171 ( V_2 -> V_72 , 1 ) ;
}
return V_204 ;
}
static bool F_196 ( struct V_38 * V_39 , struct V_1 * V_2 )
{
T_13 V_264 , V_265 ;
T_12 V_267 ;
bool V_268 ;
if ( F_10 ( V_2 , V_269 ) &&
F_176 ( V_2 -> V_59 == V_2 -> V_57 ) )
return true ;
if ( ! F_10 ( V_2 , V_170 ) ) {
T_12 V_36 ;
F_197 () ;
if ( F_189 ( V_2 , V_36 , & V_2 -> V_55 -> V_36 ) ) {
F_112 ( V_2 , L_33 ) ;
return true ;
}
return ! ( V_36 & F_175 ( V_2 , V_270 ) ) ;
}
V_264 = V_2 -> V_61 ;
V_268 = V_2 -> V_62 ;
V_265 = V_2 -> V_61 = V_2 -> V_60 ;
V_2 -> V_62 = true ;
if ( F_176 ( ! V_268 ) )
return true ;
if ( F_198 ( V_2 -> V_58 , V_265 + V_2 -> V_10 , V_265 ) &&
! F_198 ( V_2 -> V_58 , V_265 , V_264 ) )
return false ;
F_197 () ;
if ( F_189 ( V_2 , V_267 , F_199 ( V_2 ) ) ) {
F_112 ( V_2 , L_34 ) ;
return true ;
}
V_2 -> V_58 = F_181 ( V_2 , V_267 ) ;
return F_198 ( V_2 -> V_58 , V_265 , V_264 ) ;
}
void F_200 ( struct V_38 * V_39 , struct V_1 * V_2 )
{
if ( V_2 -> V_70 && F_196 ( V_39 , V_2 ) )
F_171 ( V_2 -> V_70 , 1 ) ;
}
void F_201 ( struct V_38 * V_39 ,
struct V_1 * V_2 ,
unsigned int V_260 , int V_173 )
{
F_192 ( V_2 , V_260 , V_173 ) ;
F_200 ( V_39 , V_2 ) ;
}
void F_202 ( struct V_38 * V_39 ,
struct V_1 * V_2 ,
struct V_263 * V_85 , unsigned V_254 )
{
F_194 ( V_2 , V_85 , V_254 ) ;
F_200 ( V_39 , V_2 ) ;
}
bool F_203 ( struct V_38 * V_39 , struct V_1 * V_2 )
{
T_12 V_59 ;
int V_204 ;
if ( V_2 -> V_59 != V_2 -> V_57 )
return false ;
V_204 = F_189 ( V_2 , V_59 , & V_2 -> V_55 -> V_14 ) ;
if ( F_176 ( V_204 ) )
return false ;
V_2 -> V_59 = F_181 ( V_2 , V_59 ) ;
return V_2 -> V_59 == V_2 -> V_57 ;
}
bool F_204 ( struct V_38 * V_39 , struct V_1 * V_2 )
{
T_12 V_59 ;
int V_204 ;
if ( ! ( V_2 -> V_63 & V_262 ) )
return false ;
V_2 -> V_63 &= ~ V_262 ;
if ( ! F_10 ( V_2 , V_170 ) ) {
V_204 = F_173 ( V_2 ) ;
if ( V_204 ) {
F_112 ( V_2 , L_35 ,
& V_2 -> V_56 -> V_36 , V_204 ) ;
return false ;
}
} else {
V_204 = F_177 ( V_2 , V_2 -> V_59 ) ;
if ( V_204 ) {
F_112 ( V_2 , L_36 ,
F_178 ( V_2 ) , V_204 ) ;
return false ;
}
}
F_197 () ;
V_204 = F_189 ( V_2 , V_59 , & V_2 -> V_55 -> V_14 ) ;
if ( V_204 ) {
F_112 ( V_2 , L_37 ,
& V_2 -> V_55 -> V_14 , V_204 ) ;
return false ;
}
return F_181 ( V_2 , V_59 ) != V_2 -> V_59 ;
}
void F_205 ( struct V_38 * V_39 , struct V_1 * V_2 )
{
int V_204 ;
if ( V_2 -> V_63 & V_262 )
return;
V_2 -> V_63 |= V_262 ;
if ( ! F_10 ( V_2 , V_170 ) ) {
V_204 = F_173 ( V_2 ) ;
if ( V_204 )
F_112 ( V_2 , L_35 ,
& V_2 -> V_56 -> V_36 , V_204 ) ;
}
}
struct V_115 * F_141 ( struct V_1 * V_2 , int type )
{
struct V_115 * V_45 = F_58 ( sizeof *V_45 , V_87 ) ;
if ( ! V_45 )
return NULL ;
V_45 -> V_2 = V_2 ;
V_45 -> V_153 . type = type ;
return V_45 ;
}
void F_139 ( struct V_38 * V_39 , struct V_271 * V_260 ,
struct V_115 * V_45 )
{
F_89 ( & V_39 -> V_94 ) ;
F_121 ( & V_45 -> V_45 , V_260 ) ;
F_90 ( & V_39 -> V_94 ) ;
F_93 ( & V_39 -> V_29 , V_96 | V_118 ) ;
}
struct V_115 * F_136 ( struct V_38 * V_39 ,
struct V_271 * V_260 )
{
struct V_115 * V_45 = NULL ;
F_89 ( & V_39 -> V_94 ) ;
if ( ! F_132 ( V_260 ) ) {
V_45 = F_119 ( V_260 , struct V_115 ,
V_45 ) ;
F_84 ( & V_45 -> V_45 ) ;
}
F_90 ( & V_39 -> V_94 ) ;
return V_45 ;
}
static int T_14 F_206 ( void )
{
return 0 ;
}
static void T_15 F_207 ( void )
{
}
