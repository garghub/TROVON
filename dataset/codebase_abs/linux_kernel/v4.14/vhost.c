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
V_2 -> V_61 = false ;
V_2 -> V_62 = 0 ;
V_2 -> V_63 = false ;
V_2 -> V_64 = - 1ull ;
V_2 -> V_7 = NULL ;
V_2 -> V_65 = 0 ;
V_2 -> V_66 = NULL ;
V_2 -> V_67 = NULL ;
V_2 -> error = NULL ;
V_2 -> V_68 = NULL ;
V_2 -> V_69 = NULL ;
V_2 -> V_70 = NULL ;
V_2 -> V_71 = NULL ;
F_11 ( V_2 ) ;
F_1 ( V_2 ) ;
V_2 -> V_72 = 0 ;
V_2 -> V_73 = NULL ;
V_2 -> V_74 = NULL ;
F_38 ( V_2 ) ;
}
static int F_41 ( void * V_75 )
{
struct V_38 * V_39 = V_75 ;
struct V_19 * V_20 , * V_76 ;
struct V_77 * V_45 ;
T_7 V_78 = F_42 () ;
F_43 ( V_79 ) ;
F_44 ( V_39 -> V_80 ) ;
for (; ; ) {
F_45 ( V_81 ) ;
if ( F_46 () ) {
F_47 ( V_82 ) ;
break;
}
V_45 = F_48 ( & V_39 -> V_46 ) ;
if ( ! V_45 )
F_49 () ;
V_45 = F_50 ( V_45 ) ;
F_51 () ;
F_52 (work, work_next, node, node) {
F_20 ( V_35 , & V_20 -> V_36 ) ;
F_47 ( V_82 ) ;
V_20 -> V_34 ( V_20 ) ;
if ( F_53 () )
F_49 () ;
}
}
F_54 ( V_39 -> V_80 ) ;
F_43 ( V_78 ) ;
return 0 ;
}
static void F_55 ( struct V_1 * V_2 )
{
F_56 ( V_2 -> V_83 ) ;
V_2 -> V_83 = NULL ;
F_56 ( V_2 -> log ) ;
V_2 -> log = NULL ;
F_56 ( V_2 -> V_84 ) ;
V_2 -> V_84 = NULL ;
}
static long F_57 ( struct V_38 * V_39 )
{
struct V_1 * V_2 ;
int V_51 ;
for ( V_51 = 0 ; V_51 < V_39 -> V_52 ; ++ V_51 ) {
V_2 = V_39 -> V_53 [ V_51 ] ;
V_2 -> V_83 = F_58 ( sizeof * V_2 -> V_83 * V_85 ,
V_86 ) ;
V_2 -> log = F_58 ( sizeof * V_2 -> log * V_85 , V_86 ) ;
V_2 -> V_84 = F_58 ( sizeof * V_2 -> V_84 * V_85 , V_86 ) ;
if ( ! V_2 -> V_83 || ! V_2 -> log || ! V_2 -> V_84 )
goto V_87;
}
return 0 ;
V_87:
for (; V_51 >= 0 ; -- V_51 )
F_55 ( V_39 -> V_53 [ V_51 ] ) ;
return - V_88 ;
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
F_61 ( & V_39 -> V_89 ) ;
V_39 -> V_71 = NULL ;
V_39 -> V_90 = NULL ;
V_39 -> V_73 = NULL ;
V_39 -> V_74 = NULL ;
V_39 -> V_80 = NULL ;
V_39 -> V_44 = NULL ;
F_62 ( & V_39 -> V_46 ) ;
F_21 ( & V_39 -> V_29 ) ;
F_63 ( & V_39 -> V_91 ) ;
F_63 ( & V_39 -> V_92 ) ;
F_64 ( & V_39 -> V_93 ) ;
for ( V_51 = 0 ; V_51 < V_39 -> V_52 ; ++ V_51 ) {
V_2 = V_39 -> V_53 [ V_51 ] ;
V_2 -> log = NULL ;
V_2 -> V_83 = NULL ;
V_2 -> V_84 = NULL ;
V_2 -> V_39 = V_39 ;
F_61 ( & V_2 -> V_89 ) ;
F_40 ( V_39 , V_2 ) ;
if ( V_2 -> V_94 )
F_22 ( & V_2 -> V_27 , V_2 -> V_94 ,
V_95 , V_39 ) ;
}
}
long F_65 ( struct V_38 * V_39 )
{
return V_39 -> V_80 == V_96 -> V_80 ? 0 : - V_97 ;
}
static void F_66 ( struct V_19 * V_20 )
{
struct V_98 * V_6 ;
V_6 = F_13 ( V_20 , struct V_98 , V_20 ) ;
V_6 -> V_40 = F_67 ( V_6 -> V_99 , V_96 ) ;
}
static int F_68 ( struct V_38 * V_39 )
{
struct V_98 V_100 ;
V_100 . V_99 = V_96 ;
F_19 ( & V_100 . V_20 , F_66 ) ;
F_30 ( V_39 , & V_100 . V_20 ) ;
F_28 ( V_39 , & V_100 . V_20 ) ;
return V_100 . V_40 ;
}
bool F_69 ( struct V_38 * V_39 )
{
return V_39 -> V_80 ;
}
long F_70 ( struct V_38 * V_39 )
{
struct V_101 * V_44 ;
int V_102 ;
if ( F_69 ( V_39 ) ) {
V_102 = - V_8 ;
goto V_103;
}
V_39 -> V_80 = F_71 ( V_96 ) ;
V_44 = F_72 ( F_41 , V_39 , L_1 , V_96 -> V_104 ) ;
if ( F_73 ( V_44 ) ) {
V_102 = F_74 ( V_44 ) ;
goto V_105;
}
V_39 -> V_44 = V_44 ;
F_35 ( V_44 ) ;
V_102 = F_68 ( V_39 ) ;
if ( V_102 )
goto V_106;
V_102 = F_57 ( V_39 ) ;
if ( V_102 )
goto V_106;
return 0 ;
V_106:
F_75 ( V_44 ) ;
V_39 -> V_44 = NULL ;
V_105:
if ( V_39 -> V_80 )
F_76 ( V_39 -> V_80 ) ;
V_39 -> V_80 = NULL ;
V_103:
return V_102 ;
}
struct V_107 * F_77 ( void )
{
return F_78 ( sizeof( struct V_107 ) , V_86 ) ;
}
void F_79 ( struct V_38 * V_39 , struct V_107 * V_73 )
{
int V_51 ;
F_80 ( V_39 , true ) ;
F_63 ( & V_73 -> V_108 ) ;
V_39 -> V_73 = V_73 ;
for ( V_51 = 0 ; V_51 < V_39 -> V_52 ; ++ V_51 )
V_39 -> V_53 [ V_51 ] -> V_73 = V_73 ;
}
void F_81 ( struct V_38 * V_39 )
{
int V_51 ;
for ( V_51 = 0 ; V_51 < V_39 -> V_52 ; ++ V_51 ) {
if ( V_39 -> V_53 [ V_51 ] -> V_68 && V_39 -> V_53 [ V_51 ] -> V_94 ) {
F_27 ( & V_39 -> V_53 [ V_51 ] -> V_27 ) ;
F_32 ( & V_39 -> V_53 [ V_51 ] -> V_27 ) ;
}
}
}
static void F_82 ( struct V_107 * V_73 ,
struct V_109 * V_45 )
{
F_83 ( V_45 , & V_73 -> V_110 ) ;
F_84 ( & V_45 -> V_111 ) ;
F_56 ( V_45 ) ;
V_73 -> V_112 -- ;
}
static void F_85 ( struct V_107 * V_73 )
{
struct V_109 * V_45 , * V_113 ;
if ( ! V_73 )
return;
F_86 (node, tmp, &umem->umem_list, link)
F_82 ( V_73 , V_45 ) ;
F_87 ( V_73 ) ;
}
static void F_88 ( struct V_38 * V_39 )
{
struct V_114 * V_45 , * V_115 ;
F_89 ( & V_39 -> V_93 ) ;
F_86 (node, n, &dev->read_list, node) {
F_84 ( & V_45 -> V_45 ) ;
F_56 ( V_45 ) ;
}
F_86 (node, n, &dev->pending_list, node) {
F_84 ( & V_45 -> V_45 ) ;
F_56 ( V_45 ) ;
}
F_90 ( & V_39 -> V_93 ) ;
}
void F_80 ( struct V_38 * V_39 , bool V_116 )
{
int V_51 ;
for ( V_51 = 0 ; V_51 < V_39 -> V_52 ; ++ V_51 ) {
if ( V_39 -> V_53 [ V_51 ] -> V_67 )
F_91 ( V_39 -> V_53 [ V_51 ] -> V_67 ) ;
if ( V_39 -> V_53 [ V_51 ] -> error )
F_92 ( V_39 -> V_53 [ V_51 ] -> error ) ;
if ( V_39 -> V_53 [ V_51 ] -> V_68 )
F_92 ( V_39 -> V_53 [ V_51 ] -> V_68 ) ;
if ( V_39 -> V_53 [ V_51 ] -> V_69 )
F_91 ( V_39 -> V_53 [ V_51 ] -> V_69 ) ;
if ( V_39 -> V_53 [ V_51 ] -> V_70 )
F_92 ( V_39 -> V_53 [ V_51 ] -> V_70 ) ;
F_40 ( V_39 , V_39 -> V_53 [ V_51 ] ) ;
}
F_59 ( V_39 ) ;
if ( V_39 -> V_71 )
F_91 ( V_39 -> V_71 ) ;
V_39 -> V_71 = NULL ;
if ( V_39 -> V_90 )
F_92 ( V_39 -> V_90 ) ;
V_39 -> V_90 = NULL ;
F_85 ( V_39 -> V_73 ) ;
V_39 -> V_73 = NULL ;
F_85 ( V_39 -> V_74 ) ;
V_39 -> V_74 = NULL ;
F_88 ( V_39 ) ;
F_93 ( & V_39 -> V_29 , V_95 | V_117 ) ;
F_94 ( ! F_37 ( & V_39 -> V_46 ) ) ;
if ( V_39 -> V_44 ) {
F_75 ( V_39 -> V_44 ) ;
V_39 -> V_44 = NULL ;
}
if ( V_39 -> V_80 )
F_76 ( V_39 -> V_80 ) ;
V_39 -> V_80 = NULL ;
}
static int F_95 ( void T_1 * V_66 , T_8 V_118 , unsigned long V_119 )
{
T_8 V_120 = V_118 / V_121 / 8 ;
if ( V_120 > V_122 - ( unsigned long ) V_66 ||
V_120 + ( unsigned long ) V_66 > V_122 )
return 0 ;
return F_96 ( V_123 , V_66 + V_120 ,
( V_119 + V_121 * 8 - 1 ) / V_121 / 8 ) ;
}
static bool F_97 ( T_8 V_124 , T_8 V_125 )
{
return V_124 > V_122 || V_125 > V_122 || V_124 > V_122 - V_125 ;
}
static int F_98 ( void T_1 * V_66 , struct V_107 * V_73 ,
int V_126 )
{
struct V_109 * V_45 ;
if ( ! V_73 )
return 0 ;
F_99 (node, &umem->umem_list, link) {
unsigned long V_120 = V_45 -> V_127 ;
if ( F_97 ( V_45 -> V_127 , V_45 -> V_125 ) )
return 0 ;
if ( ! F_96 ( V_123 , ( void T_1 * ) V_120 ,
V_45 -> V_125 ) )
return 0 ;
else if ( V_126 && ! F_95 ( V_66 ,
V_45 -> V_128 ,
V_45 -> V_125 ) )
return 0 ;
}
return 1 ;
}
static inline void T_1 * F_100 ( struct V_1 * V_2 ,
T_8 V_118 , unsigned int V_125 ,
int type )
{
const struct V_109 * V_45 = V_2 -> V_49 [ type ] ;
if ( ! V_45 )
return NULL ;
return ( void * ) ( V_129 ) ( V_45 -> V_127 + V_118 - V_45 -> V_128 ) ;
}
static int F_101 ( struct V_38 * V_50 , struct V_107 * V_73 ,
int V_126 )
{
int V_51 ;
for ( V_51 = 0 ; V_51 < V_50 -> V_52 ; ++ V_51 ) {
int V_130 ;
bool log ;
F_102 ( & V_50 -> V_53 [ V_51 ] -> V_89 ) ;
log = V_126 || F_10 ( V_50 -> V_53 [ V_51 ] , V_131 ) ;
if ( V_50 -> V_53 [ V_51 ] -> V_7 )
V_130 = F_98 ( V_50 -> V_53 [ V_51 ] -> V_66 ,
V_73 , log ) ;
else
V_130 = 1 ;
F_103 ( & V_50 -> V_53 [ V_51 ] -> V_89 ) ;
if ( ! V_130 )
return 0 ;
}
return 1 ;
}
static int F_104 ( struct V_1 * V_2 , void T_1 * V_132 ,
const void * V_133 , unsigned V_125 )
{
int V_40 ;
if ( ! V_2 -> V_74 )
return F_105 ( V_132 , V_133 , V_125 ) ;
else {
struct V_134 V_135 ;
void T_1 * V_124 = F_100 ( V_2 ,
( T_8 ) ( V_129 ) V_132 , V_125 ,
V_136 ) ;
if ( V_124 )
return F_105 ( V_124 , V_133 , V_125 ) ;
V_40 = F_106 ( V_2 , ( T_8 ) ( V_129 ) V_132 , V_125 , V_2 -> V_137 ,
F_107 ( V_2 -> V_137 ) ,
V_138 ) ;
if ( V_40 < 0 )
goto V_139;
F_108 ( & V_135 , V_140 , V_2 -> V_137 , V_40 , V_125 ) ;
V_40 = F_109 ( V_133 , V_125 , & V_135 ) ;
if ( V_40 == V_125 )
V_40 = 0 ;
}
V_139:
return V_40 ;
}
static int F_110 ( struct V_1 * V_2 , void * V_132 ,
void T_1 * V_133 , unsigned V_125 )
{
int V_40 ;
if ( ! V_2 -> V_74 )
return F_111 ( V_132 , V_133 , V_125 ) ;
else {
void T_1 * V_124 = F_100 ( V_2 ,
( T_8 ) ( V_129 ) V_133 , V_125 ,
V_136 ) ;
struct V_134 V_141 ;
if ( V_124 )
return F_111 ( V_132 , V_124 , V_125 ) ;
V_40 = F_106 ( V_2 , ( T_8 ) ( V_129 ) V_133 , V_125 , V_2 -> V_137 ,
F_107 ( V_2 -> V_137 ) ,
V_142 ) ;
if ( V_40 < 0 ) {
F_112 ( V_2 , L_2
L_3 , V_133 ,
( unsigned long long ) V_125 ) ;
goto V_139;
}
F_108 ( & V_141 , V_143 , V_2 -> V_137 , V_40 , V_125 ) ;
V_40 = F_113 ( V_132 , V_125 , & V_141 ) ;
if ( V_40 == V_125 )
V_40 = 0 ;
}
V_139:
return V_40 ;
}
static void T_1 * F_114 ( struct V_1 * V_2 ,
void T_1 * V_118 , unsigned int V_125 ,
int type )
{
int V_40 ;
V_40 = F_106 ( V_2 , ( T_8 ) ( V_129 ) V_118 , V_125 , V_2 -> V_137 ,
F_107 ( V_2 -> V_137 ) ,
V_142 ) ;
if ( V_40 < 0 ) {
F_112 ( V_2 , L_2
L_3 , V_118 ,
( unsigned long long ) V_125 ) ;
return NULL ;
}
if ( V_40 != 1 || V_2 -> V_137 [ 0 ] . V_144 != V_125 ) {
F_112 ( V_2 , L_4
L_3 , V_118 ,
( unsigned long long ) V_125 ) ;
return NULL ;
}
return V_2 -> V_137 [ 0 ] . V_145 ;
}
static inline void T_1 * F_115 ( struct V_1 * V_2 ,
void * V_118 , unsigned int V_125 ,
int type )
{
void T_1 * V_124 = F_100 ( V_2 ,
( T_8 ) ( V_129 ) V_118 , V_125 , type ) ;
if ( V_124 )
return V_124 ;
return F_114 ( V_2 , V_118 , V_125 , type ) ;
}
static void F_116 ( struct V_38 * V_50 )
{
int V_51 = 0 ;
for ( V_51 = 0 ; V_51 < V_50 -> V_52 ; ++ V_51 )
F_102 ( & V_50 -> V_53 [ V_51 ] -> V_89 ) ;
}
static void F_117 ( struct V_38 * V_50 )
{
int V_51 = 0 ;
for ( V_51 = 0 ; V_51 < V_50 -> V_52 ; ++ V_51 )
F_103 ( & V_50 -> V_53 [ V_51 ] -> V_89 ) ;
}
static int F_118 ( struct V_107 * V_73 ,
T_8 V_128 , T_8 V_125 , T_8 V_146 ,
T_8 V_127 , int V_147 )
{
struct V_109 * V_113 , * V_45 = F_58 ( sizeof( * V_45 ) , V_148 ) ;
if ( ! V_45 )
return - V_88 ;
if ( V_73 -> V_112 == V_149 ) {
V_113 = F_119 ( & V_73 -> V_108 , F_120 ( * V_113 ) , V_111 ) ;
F_82 ( V_73 , V_113 ) ;
}
V_45 -> V_128 = V_128 ;
V_45 -> V_125 = V_125 ;
V_45 -> V_150 = V_146 ;
V_45 -> V_127 = V_127 ;
V_45 -> V_147 = V_147 ;
F_63 ( & V_45 -> V_111 ) ;
F_121 ( & V_45 -> V_111 , & V_73 -> V_108 ) ;
F_122 ( V_45 , & V_73 -> V_110 ) ;
V_73 -> V_112 ++ ;
return 0 ;
}
static void F_123 ( struct V_107 * V_73 ,
T_8 V_128 , T_8 V_146 )
{
struct V_109 * V_45 ;
while ( ( V_45 = F_124 ( & V_73 -> V_110 ,
V_128 , V_146 ) ) )
F_82 ( V_73 , V_45 ) ;
}
static void F_125 ( struct V_38 * V_50 ,
struct V_151 * V_152 )
{
struct V_114 * V_45 , * V_115 ;
F_89 ( & V_50 -> V_93 ) ;
F_86 (node, n, &d->pending_list, node) {
struct V_151 * V_153 = & V_45 -> V_152 . V_74 ;
if ( V_152 -> V_154 <= V_153 -> V_154 &&
V_152 -> V_154 + V_152 -> V_125 - 1 > V_153 -> V_154 &&
V_153 -> type == V_155 ) {
F_18 ( & V_45 -> V_2 -> V_27 ) ;
F_84 ( & V_45 -> V_45 ) ;
F_56 ( V_45 ) ;
}
}
F_90 ( & V_50 -> V_93 ) ;
}
static int F_126 ( T_8 V_124 , T_8 V_125 , int V_156 )
{
unsigned long V_120 = V_124 ;
if ( F_97 ( V_124 , V_125 ) )
return - V_9 ;
if ( ( V_156 & V_142 ) &&
! F_96 ( V_157 , ( void T_1 * ) V_120 , V_125 ) )
return - V_9 ;
if ( ( V_156 & V_138 ) &&
! F_96 ( V_123 , ( void T_1 * ) V_120 , V_125 ) )
return - V_9 ;
return 0 ;
}
static int F_127 ( struct V_38 * V_39 ,
struct V_151 * V_152 )
{
int V_40 = 0 ;
F_116 ( V_39 ) ;
switch ( V_152 -> type ) {
case V_158 :
if ( ! V_39 -> V_74 ) {
V_40 = - V_9 ;
break;
}
if ( F_126 ( V_152 -> V_124 , V_152 -> V_125 , V_152 -> V_147 ) ) {
V_40 = - V_9 ;
break;
}
F_39 ( V_39 ) ;
if ( F_118 ( V_39 -> V_74 , V_152 -> V_154 , V_152 -> V_125 ,
V_152 -> V_154 + V_152 -> V_125 - 1 ,
V_152 -> V_124 , V_152 -> V_147 ) ) {
V_40 = - V_88 ;
break;
}
F_125 ( V_39 , V_152 ) ;
break;
case V_159 :
F_39 ( V_39 ) ;
F_123 ( V_39 -> V_74 , V_152 -> V_154 ,
V_152 -> V_154 + V_152 -> V_125 - 1 ) ;
break;
default:
V_40 = - V_13 ;
break;
}
F_117 ( V_39 ) ;
return V_40 ;
}
T_9 F_128 ( struct V_38 * V_39 ,
struct V_134 * V_133 )
{
struct V_114 V_45 ;
unsigned V_125 = sizeof( struct V_160 ) ;
T_10 V_40 ;
int V_102 ;
if ( F_129 ( V_133 ) < V_125 )
return 0 ;
V_40 = F_113 ( & V_45 . V_152 , V_125 , V_133 ) ;
if ( V_40 != V_125 )
goto V_37;
switch ( V_45 . V_152 . type ) {
case V_161 :
V_102 = F_127 ( V_39 , & V_45 . V_152 . V_74 ) ;
if ( V_102 )
V_40 = V_102 ;
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
if ( ! F_132 ( & V_39 -> V_91 ) )
V_33 |= V_95 | V_117 ;
return V_33 ;
}
T_9 F_133 ( struct V_38 * V_39 , struct V_134 * V_132 ,
int V_162 )
{
F_134 ( V_29 ) ;
struct V_114 * V_45 ;
T_9 V_40 = 0 ;
unsigned V_125 = sizeof( struct V_160 ) ;
if ( F_129 ( V_132 ) < V_125 )
return 0 ;
while ( 1 ) {
if ( ! V_162 )
F_135 ( & V_39 -> V_29 , & V_29 ,
V_81 ) ;
V_45 = F_136 ( V_39 , & V_39 -> V_91 ) ;
if ( V_45 )
break;
if ( V_162 ) {
V_40 = - V_163 ;
break;
}
if ( F_137 ( V_96 ) ) {
V_40 = - V_164 ;
break;
}
if ( ! V_39 -> V_74 ) {
V_40 = - V_165 ;
break;
}
F_49 () ;
}
if ( ! V_162 )
F_138 ( & V_39 -> V_29 , & V_29 ) ;
if ( V_45 ) {
V_40 = F_109 ( & V_45 -> V_152 , V_125 , V_132 ) ;
if ( V_40 != V_125 || V_45 -> V_152 . type != V_155 ) {
F_56 ( V_45 ) ;
return V_40 ;
}
F_139 ( V_39 , & V_39 -> V_92 , V_45 ) ;
}
return V_40 ;
}
static int F_140 ( struct V_1 * V_2 , T_8 V_154 , int V_156 )
{
struct V_38 * V_39 = V_2 -> V_39 ;
struct V_114 * V_45 ;
struct V_151 * V_152 ;
V_45 = F_141 ( V_2 , V_155 ) ;
if ( ! V_45 )
return - V_88 ;
V_152 = & V_45 -> V_152 . V_74 ;
V_152 -> type = V_155 ;
V_152 -> V_154 = V_154 ;
V_152 -> V_147 = V_156 ;
F_139 ( V_39 , & V_39 -> V_91 , V_45 ) ;
return 0 ;
}
static int F_142 ( struct V_1 * V_2 , unsigned int V_10 ,
struct V_166 T_1 * V_54 ,
struct V_167 T_1 * V_55 ,
struct V_168 T_1 * V_56 )
{
T_10 V_6 = F_10 ( V_2 , V_169 ) ? 2 : 0 ;
return F_96 ( V_157 , V_54 , V_10 * sizeof *V_54 ) &&
F_96 ( V_157 , V_55 ,
sizeof *V_55 + V_10 * sizeof * V_55 -> V_170 + V_6 ) &&
F_96 ( V_123 , V_56 ,
sizeof *V_56 + V_10 * sizeof * V_56 -> V_170 + V_6 ) ;
}
static void F_143 ( struct V_1 * V_2 ,
const struct V_109 * V_45 ,
int type )
{
int V_156 = ( type == V_171 ) ?
V_138 : V_142 ;
if ( F_144 ( V_45 -> V_147 & V_156 ) )
V_2 -> V_49 [ type ] = V_45 ;
}
static int F_145 ( struct V_1 * V_2 ,
int V_156 , T_8 V_118 , T_8 V_172 , int type )
{
const struct V_109 * V_45 ;
struct V_107 * V_73 = V_2 -> V_74 ;
T_8 V_6 = 0 , V_125 , V_173 = V_118 ;
if ( F_100 ( V_2 , V_118 , V_172 , type ) )
return true ;
while ( V_172 > V_6 ) {
V_45 = F_124 ( & V_73 -> V_110 ,
V_118 ,
V_118 + V_172 - 1 ) ;
if ( V_45 == NULL || V_45 -> V_128 > V_118 ) {
F_140 ( V_2 , V_118 , V_156 ) ;
return false ;
} else if ( ! ( V_45 -> V_147 & V_156 ) ) {
return false ;
}
V_125 = V_45 -> V_125 - V_118 + V_45 -> V_128 ;
if ( V_173 == V_118 && V_125 >= V_172 )
F_143 ( V_2 , V_45 , type ) ;
V_6 += V_125 ;
V_118 += V_125 ;
}
return true ;
}
int F_146 ( struct V_1 * V_2 )
{
T_10 V_6 = F_10 ( V_2 , V_169 ) ? 2 : 0 ;
unsigned int V_10 = V_2 -> V_10 ;
if ( ! V_2 -> V_74 )
return 1 ;
return F_145 ( V_2 , V_142 , ( T_8 ) ( V_129 ) V_2 -> V_54 ,
V_10 * sizeof( * V_2 -> V_54 ) , V_136 ) &&
F_145 ( V_2 , V_142 , ( T_8 ) ( V_129 ) V_2 -> V_55 ,
sizeof * V_2 -> V_55 +
V_10 * sizeof( * V_2 -> V_55 -> V_170 ) + V_6 ,
V_174 ) &&
F_145 ( V_2 , V_138 , ( T_8 ) ( V_129 ) V_2 -> V_56 ,
sizeof * V_2 -> V_56 +
V_10 * sizeof( * V_2 -> V_56 -> V_170 ) + V_6 ,
V_171 ) ;
}
int F_147 ( struct V_38 * V_39 )
{
return F_101 ( V_39 , V_39 -> V_73 , 1 ) ;
}
static int F_148 ( struct V_1 * V_2 ,
void T_1 * V_66 )
{
T_10 V_6 = F_10 ( V_2 , V_169 ) ? 2 : 0 ;
return F_98 ( V_66 , V_2 -> V_73 ,
F_10 ( V_2 , V_131 ) ) &&
( ! V_2 -> V_63 || F_95 ( V_66 , V_2 -> V_64 ,
sizeof * V_2 -> V_56 +
V_2 -> V_10 * sizeof * V_2 -> V_56 -> V_170 + V_6 ) ) ;
}
int F_149 ( struct V_1 * V_2 )
{
if ( V_2 -> V_74 ) {
return 1 ;
}
return F_142 ( V_2 , V_2 -> V_10 , V_2 -> V_54 , V_2 -> V_55 , V_2 -> V_56 ) &&
F_148 ( V_2 , V_2 -> V_66 ) ;
}
static struct V_107 * F_150 ( void )
{
struct V_107 * V_73 = F_78 ( sizeof( * V_73 ) , V_86 ) ;
if ( ! V_73 )
return NULL ;
V_73 -> V_110 = V_175 ;
V_73 -> V_112 = 0 ;
F_63 ( & V_73 -> V_108 ) ;
return V_73 ;
}
static long F_151 ( struct V_38 * V_50 , struct V_176 T_1 * V_177 )
{
struct V_176 V_178 , * V_179 ;
struct V_180 * V_181 ;
struct V_107 * V_182 , * V_183 ;
unsigned long V_125 = F_152 ( struct V_176 , V_184 ) ;
int V_51 ;
if ( F_6 ( & V_178 , V_177 , V_125 ) )
return - V_9 ;
if ( V_178 . V_185 )
return - V_186 ;
if ( V_178 . V_187 > V_188 )
return - V_189 ;
V_179 = F_78 ( V_125 + V_178 . V_187 * sizeof( * V_177 -> V_184 ) , V_86 ) ;
if ( ! V_179 )
return - V_88 ;
memcpy ( V_179 , & V_178 , V_125 ) ;
if ( F_6 ( V_179 -> V_184 , V_177 -> V_184 ,
V_178 . V_187 * sizeof * V_177 -> V_184 ) ) {
F_87 ( V_179 ) ;
return - V_9 ;
}
V_182 = F_150 () ;
if ( ! V_182 ) {
F_87 ( V_179 ) ;
return - V_88 ;
}
for ( V_181 = V_179 -> V_184 ;
V_181 < V_179 -> V_184 + V_178 . V_187 ;
V_181 ++ ) {
if ( F_118 ( V_182 ,
V_181 -> V_190 ,
V_181 -> V_191 ,
V_181 -> V_190 +
V_181 -> V_191 - 1 ,
V_181 -> V_127 ,
V_192 ) )
goto V_102;
}
if ( ! F_101 ( V_50 , V_182 , 0 ) )
goto V_102;
V_183 = V_50 -> V_73 ;
V_50 -> V_73 = V_182 ;
for ( V_51 = 0 ; V_51 < V_50 -> V_52 ; ++ V_51 ) {
F_102 ( & V_50 -> V_53 [ V_51 ] -> V_89 ) ;
V_50 -> V_53 [ V_51 ] -> V_73 = V_182 ;
F_103 ( & V_50 -> V_53 [ V_51 ] -> V_89 ) ;
}
F_87 ( V_179 ) ;
F_85 ( V_183 ) ;
return 0 ;
V_102:
F_85 ( V_182 ) ;
F_87 ( V_179 ) ;
return - V_9 ;
}
long F_153 ( struct V_38 * V_50 , int V_193 , void T_1 * V_4 )
{
struct V_23 * V_194 , * V_195 = NULL ;
bool V_196 = false , V_197 = false ;
struct V_198 * V_199 = NULL ;
T_2 T_1 * V_200 = V_4 ;
struct V_1 * V_2 ;
struct V_5 V_6 ;
struct V_201 V_141 ;
struct V_202 V_120 ;
T_2 V_14 ;
long V_203 ;
V_203 = F_154 ( V_14 , V_200 ) ;
if ( V_203 < 0 )
return V_203 ;
if ( V_14 >= V_50 -> V_52 )
return - V_204 ;
V_2 = V_50 -> V_53 [ V_14 ] ;
F_102 ( & V_2 -> V_89 ) ;
switch ( V_193 ) {
case V_205 :
if ( V_2 -> V_7 ) {
V_203 = - V_8 ;
break;
}
if ( F_6 ( & V_6 , V_4 , sizeof V_6 ) ) {
V_203 = - V_9 ;
break;
}
if ( ! V_6 . V_10 || V_6 . V_10 > 0xffff || ( V_6 . V_10 & ( V_6 . V_10 - 1 ) ) ) {
V_203 = - V_13 ;
break;
}
V_2 -> V_10 = V_6 . V_10 ;
break;
case V_206 :
if ( V_2 -> V_7 ) {
V_203 = - V_8 ;
break;
}
if ( F_6 ( & V_6 , V_4 , sizeof V_6 ) ) {
V_203 = - V_9 ;
break;
}
if ( V_6 . V_10 > 0xffff ) {
V_203 = - V_13 ;
break;
}
V_2 -> V_57 = V_6 . V_10 ;
V_2 -> V_58 = V_2 -> V_57 ;
break;
case V_207 :
V_6 . V_15 = V_14 ;
V_6 . V_10 = V_2 -> V_57 ;
if ( F_8 ( V_4 , & V_6 , sizeof V_6 ) )
V_203 = - V_9 ;
break;
case V_208 :
if ( F_6 ( & V_120 , V_4 , sizeof V_120 ) ) {
V_203 = - V_9 ;
break;
}
if ( V_120 . V_36 & ~ ( 0x1 << V_209 ) ) {
V_203 = - V_186 ;
break;
}
if ( ( T_8 ) ( unsigned long ) V_120 . V_210 != V_120 . V_210 ||
( T_8 ) ( unsigned long ) V_120 . V_211 != V_120 . V_211 ||
( T_8 ) ( unsigned long ) V_120 . V_212 != V_120 . V_212 ) {
V_203 = - V_9 ;
break;
}
F_155 ( V_213 * V_2 -> V_55 > V_214 ) ;
F_155 ( V_213 * V_2 -> V_56 > V_215 ) ;
if ( ( V_120 . V_212 & ( V_214 - 1 ) ) ||
( V_120 . V_211 & ( V_215 - 1 ) ) ||
( V_120 . V_216 & ( V_215 - 1 ) ) ) {
V_203 = - V_13 ;
break;
}
if ( V_2 -> V_7 ) {
if ( ! F_142 ( V_2 , V_2 -> V_10 ,
( void T_1 * ) ( unsigned long ) V_120 . V_210 ,
( void T_1 * ) ( unsigned long ) V_120 . V_212 ,
( void T_1 * ) ( unsigned long ) V_120 . V_211 ) ) {
V_203 = - V_13 ;
break;
}
if ( ( V_120 . V_36 & ( 0x1 << V_209 ) ) &&
! F_95 ( V_2 -> V_66 , V_120 . V_216 ,
sizeof * V_2 -> V_56 +
V_2 -> V_10 * sizeof * V_2 -> V_56 -> V_170 ) ) {
V_203 = - V_13 ;
break;
}
}
V_2 -> V_63 = ! ! ( V_120 . V_36 & ( 0x1 << V_209 ) ) ;
V_2 -> V_54 = ( void T_1 * ) ( unsigned long ) V_120 . V_210 ;
V_2 -> V_55 = ( void T_1 * ) ( unsigned long ) V_120 . V_212 ;
V_2 -> V_64 = V_120 . V_216 ;
V_2 -> V_56 = ( void T_1 * ) ( unsigned long ) V_120 . V_211 ;
break;
case V_217 :
if ( F_6 ( & V_141 , V_4 , sizeof V_141 ) ) {
V_203 = - V_9 ;
break;
}
V_194 = V_141 . V_218 == - 1 ? NULL : F_156 ( V_141 . V_218 ) ;
if ( F_73 ( V_194 ) ) {
V_203 = F_74 ( V_194 ) ;
break;
}
if ( V_194 != V_2 -> V_68 ) {
V_197 = ( V_195 = V_2 -> V_68 ) != NULL ;
V_196 = ( V_2 -> V_68 = V_194 ) != NULL ;
} else
V_195 = V_194 ;
break;
case V_219 :
if ( F_6 ( & V_141 , V_4 , sizeof V_141 ) ) {
V_203 = - V_9 ;
break;
}
V_194 = V_141 . V_218 == - 1 ? NULL : F_156 ( V_141 . V_218 ) ;
if ( F_73 ( V_194 ) ) {
V_203 = F_74 ( V_194 ) ;
break;
}
if ( V_194 != V_2 -> V_70 ) {
V_195 = V_2 -> V_70 ;
V_199 = V_2 -> V_69 ;
V_2 -> V_70 = V_194 ;
V_2 -> V_69 = V_194 ?
F_157 ( V_194 ) : NULL ;
} else
V_195 = V_194 ;
break;
case V_220 :
if ( F_6 ( & V_141 , V_4 , sizeof V_141 ) ) {
V_203 = - V_9 ;
break;
}
V_194 = V_141 . V_218 == - 1 ? NULL : F_156 ( V_141 . V_218 ) ;
if ( F_73 ( V_194 ) ) {
V_203 = F_74 ( V_194 ) ;
break;
}
if ( V_194 != V_2 -> error ) {
V_195 = V_2 -> error ;
V_2 -> error = V_194 ;
V_199 = V_2 -> V_67 ;
V_2 -> V_67 = V_194 ?
F_157 ( V_194 ) : NULL ;
} else
V_195 = V_194 ;
break;
case V_221 :
V_203 = F_5 ( V_2 , V_4 ) ;
break;
case V_222 :
V_203 = F_7 ( V_2 , V_14 , V_4 ) ;
break;
case V_223 :
if ( F_6 ( & V_6 , V_4 , sizeof( V_6 ) ) ) {
V_203 = - V_9 ;
break;
}
V_2 -> V_72 = V_6 . V_10 ;
break;
case V_224 :
V_6 . V_15 = V_14 ;
V_6 . V_10 = V_2 -> V_72 ;
if ( F_8 ( V_4 , & V_6 , sizeof( V_6 ) ) )
V_203 = - V_9 ;
break;
default:
V_203 = - V_18 ;
}
if ( V_197 && V_2 -> V_94 )
F_27 ( & V_2 -> V_27 ) ;
if ( V_199 )
F_91 ( V_199 ) ;
if ( V_195 )
F_92 ( V_195 ) ;
if ( V_196 && V_2 -> V_94 )
V_203 = F_25 ( & V_2 -> V_27 , V_2 -> V_68 ) ;
F_103 ( & V_2 -> V_89 ) ;
if ( V_197 && V_2 -> V_94 )
F_32 ( & V_2 -> V_27 ) ;
return V_203 ;
}
int F_158 ( struct V_38 * V_50 , bool V_225 )
{
struct V_107 * V_226 , * V_227 ;
int V_51 ;
V_226 = F_150 () ;
if ( ! V_226 )
return - V_88 ;
V_227 = V_50 -> V_74 ;
V_50 -> V_74 = V_226 ;
for ( V_51 = 0 ; V_51 < V_50 -> V_52 ; ++ V_51 ) {
F_102 ( & V_50 -> V_53 [ V_51 ] -> V_89 ) ;
V_50 -> V_53 [ V_51 ] -> V_74 = V_226 ;
F_103 ( & V_50 -> V_53 [ V_51 ] -> V_89 ) ;
}
F_85 ( V_227 ) ;
return 0 ;
}
long F_159 ( struct V_38 * V_50 , unsigned int V_193 , void T_1 * V_4 )
{
struct V_23 * V_194 , * V_195 = NULL ;
struct V_198 * V_199 = NULL ;
T_8 V_228 ;
long V_203 ;
int V_51 , V_218 ;
if ( V_193 == V_229 ) {
V_203 = F_70 ( V_50 ) ;
goto V_37;
}
V_203 = F_65 ( V_50 ) ;
if ( V_203 )
goto V_37;
switch ( V_193 ) {
case V_230 :
V_203 = F_151 ( V_50 , V_4 ) ;
break;
case V_231 :
if ( F_6 ( & V_228 , V_4 , sizeof V_228 ) ) {
V_203 = - V_9 ;
break;
}
if ( ( T_8 ) ( unsigned long ) V_228 != V_228 ) {
V_203 = - V_9 ;
break;
}
for ( V_51 = 0 ; V_51 < V_50 -> V_52 ; ++ V_51 ) {
struct V_1 * V_2 ;
void T_1 * V_232 = ( void T_1 * ) ( unsigned long ) V_228 ;
V_2 = V_50 -> V_53 [ V_51 ] ;
F_102 ( & V_2 -> V_89 ) ;
if ( V_2 -> V_7 && ! F_148 ( V_2 , V_232 ) )
V_203 = - V_9 ;
else
V_2 -> V_66 = V_232 ;
F_103 ( & V_2 -> V_89 ) ;
}
break;
case V_233 :
V_203 = F_154 ( V_218 , ( int T_1 * ) V_4 ) ;
if ( V_203 < 0 )
break;
V_194 = V_218 == - 1 ? NULL : F_156 ( V_218 ) ;
if ( F_73 ( V_194 ) ) {
V_203 = F_74 ( V_194 ) ;
break;
}
if ( V_194 != V_50 -> V_90 ) {
V_195 = V_50 -> V_90 ;
V_50 -> V_90 = V_194 ;
V_199 = V_50 -> V_71 ;
V_50 -> V_71 = V_194 ?
F_157 ( V_194 ) : NULL ;
} else
V_195 = V_194 ;
for ( V_51 = 0 ; V_51 < V_50 -> V_52 ; ++ V_51 ) {
F_102 ( & V_50 -> V_53 [ V_51 ] -> V_89 ) ;
V_50 -> V_53 [ V_51 ] -> V_71 = V_50 -> V_71 ;
F_103 ( & V_50 -> V_53 [ V_51 ] -> V_89 ) ;
}
if ( V_199 )
F_91 ( V_199 ) ;
if ( V_195 )
F_92 ( V_195 ) ;
break;
default:
V_203 = - V_18 ;
break;
}
V_37:
return V_203 ;
}
static int F_160 ( int V_234 , void T_1 * V_118 )
{
unsigned long log = ( unsigned long ) V_118 ;
struct V_235 * V_235 ;
void * V_232 ;
int V_236 = V_234 + ( log % V_237 ) * 8 ;
int V_203 ;
V_203 = F_161 ( log , 1 , 1 , & V_235 ) ;
if ( V_203 < 0 )
return V_203 ;
F_162 ( V_203 != 1 ) ;
V_232 = F_163 ( V_235 ) ;
F_164 ( V_236 , V_232 ) ;
F_165 ( V_232 ) ;
F_166 ( V_235 ) ;
F_167 ( V_235 ) ;
return 0 ;
}
static int F_168 ( void T_1 * V_66 ,
T_8 V_238 , T_8 V_239 )
{
T_8 V_240 = V_238 / V_121 ;
int V_203 ;
if ( ! V_239 )
return 0 ;
V_239 += V_238 % V_121 ;
for (; ; ) {
T_8 V_232 = ( T_8 ) ( unsigned long ) V_66 ;
T_8 log = V_232 + V_240 / 8 ;
int V_236 = V_240 % 8 ;
if ( ( T_8 ) ( unsigned long ) log != log )
return - V_9 ;
V_203 = F_160 ( V_236 , ( void T_1 * ) ( unsigned long ) log ) ;
if ( V_203 < 0 )
return V_203 ;
if ( V_239 <= V_121 )
break;
V_239 -= V_121 ;
V_240 += 1 ;
}
return V_203 ;
}
int F_169 ( struct V_1 * V_2 , struct V_241 * log ,
unsigned int V_242 , T_8 V_172 )
{
int V_51 , V_203 ;
F_51 () ;
for ( V_51 = 0 ; V_51 < V_242 ; ++ V_51 ) {
T_8 V_243 = F_170 ( log [ V_51 ] . V_172 , V_172 ) ;
V_203 = F_168 ( V_2 -> V_66 , log [ V_51 ] . V_118 , V_243 ) ;
if ( V_203 < 0 )
return V_203 ;
V_172 -= V_243 ;
if ( ! V_172 ) {
if ( V_2 -> V_71 )
F_171 ( V_2 -> V_71 , 1 ) ;
return 0 ;
}
}
F_172 () ;
return 0 ;
}
static int F_173 ( struct V_1 * V_2 )
{
void T_1 * V_56 ;
if ( F_174 ( V_2 , F_175 ( V_2 , V_2 -> V_62 ) ,
& V_2 -> V_56 -> V_36 ) < 0 )
return - V_9 ;
if ( F_176 ( V_2 -> V_63 ) ) {
F_51 () ;
V_56 = & V_2 -> V_56 -> V_36 ;
F_168 ( V_2 -> V_66 , V_2 -> V_64 +
( V_56 - ( void T_1 * ) V_2 -> V_56 ) ,
sizeof V_2 -> V_56 -> V_36 ) ;
if ( V_2 -> V_71 )
F_171 ( V_2 -> V_71 , 1 ) ;
}
return 0 ;
}
static int F_177 ( struct V_1 * V_2 , T_11 V_244 )
{
if ( F_174 ( V_2 , F_175 ( V_2 , V_2 -> V_58 ) ,
F_178 ( V_2 ) ) )
return - V_9 ;
if ( F_176 ( V_2 -> V_63 ) ) {
void T_1 * V_56 ;
F_51 () ;
V_56 = F_178 ( V_2 ) ;
F_168 ( V_2 -> V_66 , V_2 -> V_64 +
( V_56 - ( void T_1 * ) V_2 -> V_56 ) ,
sizeof * F_178 ( V_2 ) ) ;
if ( V_2 -> V_71 )
F_171 ( V_2 -> V_71 , 1 ) ;
}
return 0 ;
}
int F_179 ( struct V_1 * V_2 )
{
T_12 V_59 ;
int V_203 ;
bool V_16 = V_2 -> V_16 ;
if ( ! V_2 -> V_7 )
return 0 ;
F_9 ( V_2 ) ;
V_203 = F_173 ( V_2 ) ;
if ( V_203 )
goto V_102;
V_2 -> V_61 = false ;
if ( ! V_2 -> V_74 &&
! F_96 ( V_157 , & V_2 -> V_56 -> V_14 , sizeof V_2 -> V_56 -> V_14 ) ) {
V_203 = - V_9 ;
goto V_102;
}
V_203 = F_180 ( V_2 , V_59 , & V_2 -> V_56 -> V_14 ) ;
if ( V_203 ) {
F_112 ( V_2 , L_5 ,
& V_2 -> V_56 -> V_14 ) ;
goto V_102;
}
V_2 -> V_59 = F_181 ( V_2 , V_59 ) ;
return 0 ;
V_102:
V_2 -> V_16 = V_16 ;
return V_203 ;
}
static int F_106 ( struct V_1 * V_2 , T_8 V_118 , T_2 V_172 ,
struct V_245 V_246 [] , int V_247 , int V_156 )
{
const struct V_109 * V_45 ;
struct V_38 * V_39 = V_2 -> V_39 ;
struct V_107 * V_73 = V_39 -> V_74 ? V_39 -> V_74 : V_39 -> V_73 ;
struct V_245 * V_248 ;
T_8 V_6 = 0 ;
int V_40 = 0 ;
while ( ( T_8 ) V_172 > V_6 ) {
T_8 V_125 ;
if ( F_176 ( V_40 >= V_247 ) ) {
V_40 = - V_204 ;
break;
}
V_45 = F_124 ( & V_73 -> V_110 ,
V_118 , V_118 + V_172 - 1 ) ;
if ( V_45 == NULL || V_45 -> V_128 > V_118 ) {
if ( V_73 != V_39 -> V_74 ) {
V_40 = - V_9 ;
break;
}
V_40 = - V_163 ;
break;
} else if ( ! ( V_45 -> V_147 & V_156 ) ) {
V_40 = - V_97 ;
break;
}
V_248 = V_246 + V_40 ;
V_125 = V_45 -> V_125 - V_118 + V_45 -> V_128 ;
V_248 -> V_144 = F_170 ( ( T_8 ) V_172 - V_6 , V_125 ) ;
V_248 -> V_145 = ( void T_1 * ) ( unsigned long )
( V_45 -> V_127 + V_118 - V_45 -> V_128 ) ;
V_6 += V_125 ;
V_118 += V_125 ;
++ V_40 ;
}
if ( V_40 == - V_163 )
F_140 ( V_2 , V_118 , V_156 ) ;
return V_40 ;
}
static unsigned F_182 ( struct V_1 * V_2 , struct V_166 * V_54 )
{
unsigned int V_249 ;
if ( ! ( V_54 -> V_36 & F_175 ( V_2 , V_250 ) ) )
return - 1U ;
V_249 = F_181 ( V_2 , V_54 -> V_249 ) ;
F_183 () ;
return V_249 ;
}
static int F_184 ( struct V_1 * V_2 ,
struct V_245 V_246 [] , unsigned int V_247 ,
unsigned int * V_251 , unsigned int * V_252 ,
struct V_241 * log , unsigned int * V_242 ,
struct V_166 * V_83 )
{
struct V_166 V_54 ;
unsigned int V_51 = 0 , V_253 , V_254 = 0 ;
T_2 V_172 = F_185 ( V_2 , V_83 -> V_172 ) ;
struct V_134 V_133 ;
int V_40 , V_156 ;
if ( F_176 ( V_172 % sizeof V_54 ) ) {
F_112 ( V_2 , L_6
L_7 ,
( unsigned long long ) V_172 ,
sizeof V_54 ) ;
return - V_13 ;
}
V_40 = F_106 ( V_2 , F_186 ( V_2 , V_83 -> V_118 ) , V_172 , V_2 -> V_83 ,
V_85 , V_142 ) ;
if ( F_176 ( V_40 < 0 ) ) {
if ( V_40 != - V_163 )
F_112 ( V_2 , L_8 , V_40 ) ;
return V_40 ;
}
F_108 ( & V_133 , V_143 , V_2 -> V_83 , V_40 , V_172 ) ;
F_183 () ;
V_253 = V_172 / sizeof V_54 ;
if ( F_176 ( V_253 > V_255 + 1 ) ) {
F_112 ( V_2 , L_9 ,
V_83 -> V_172 ) ;
return - V_189 ;
}
do {
unsigned V_256 = * V_252 + * V_251 ;
if ( F_176 ( ++ V_254 > V_253 ) ) {
F_112 ( V_2 , L_10
L_11 ,
V_51 , V_253 ) ;
return - V_13 ;
}
if ( F_176 ( ! F_187 ( & V_54 , sizeof( V_54 ) , & V_133 ) ) ) {
F_112 ( V_2 , L_12 ,
V_51 , ( T_10 ) F_186 ( V_2 , V_83 -> V_118 ) + V_51 * sizeof V_54 ) ;
return - V_13 ;
}
if ( F_176 ( V_54 . V_36 & F_175 ( V_2 , V_257 ) ) ) {
F_112 ( V_2 , L_13 ,
V_51 , ( T_10 ) F_186 ( V_2 , V_83 -> V_118 ) + V_51 * sizeof V_54 ) ;
return - V_13 ;
}
if ( V_54 . V_36 & F_175 ( V_2 , V_258 ) )
V_156 = V_138 ;
else
V_156 = V_142 ;
V_40 = F_106 ( V_2 , F_186 ( V_2 , V_54 . V_118 ) ,
F_185 ( V_2 , V_54 . V_172 ) , V_246 + V_256 ,
V_247 - V_256 , V_156 ) ;
if ( F_176 ( V_40 < 0 ) ) {
if ( V_40 != - V_163 )
F_112 ( V_2 , L_14 ,
V_40 , V_51 ) ;
return V_40 ;
}
if ( V_156 == V_138 ) {
* V_252 += V_40 ;
if ( F_176 ( log ) ) {
log [ * V_242 ] . V_118 = F_186 ( V_2 , V_54 . V_118 ) ;
log [ * V_242 ] . V_172 = F_185 ( V_2 , V_54 . V_172 ) ;
++ * V_242 ;
}
} else {
if ( F_176 ( * V_252 ) ) {
F_112 ( V_2 , L_15
L_16 , V_51 ) ;
return - V_13 ;
}
* V_251 += V_40 ;
}
} while ( ( V_51 = F_182 ( V_2 , & V_54 ) ) != - 1 );
return 0 ;
}
int F_188 ( struct V_1 * V_2 ,
struct V_245 V_246 [] , unsigned int V_247 ,
unsigned int * V_251 , unsigned int * V_252 ,
struct V_241 * log , unsigned int * V_242 )
{
struct V_166 V_54 ;
unsigned int V_51 , V_259 , V_254 = 0 ;
T_11 V_57 ;
T_12 V_58 ;
T_12 V_260 ;
int V_40 , V_156 ;
V_57 = V_2 -> V_57 ;
if ( V_2 -> V_58 == V_2 -> V_57 ) {
if ( F_176 ( F_189 ( V_2 , V_58 , & V_2 -> V_55 -> V_14 ) ) ) {
F_112 ( V_2 , L_17 ,
& V_2 -> V_55 -> V_14 ) ;
return - V_9 ;
}
V_2 -> V_58 = F_181 ( V_2 , V_58 ) ;
if ( F_176 ( ( T_11 ) ( V_2 -> V_58 - V_57 ) > V_2 -> V_10 ) ) {
F_112 ( V_2 , L_18 ,
V_57 , V_2 -> V_58 ) ;
return - V_9 ;
}
if ( V_2 -> V_58 == V_57 )
return V_2 -> V_10 ;
F_190 () ;
}
if ( F_176 ( F_189 ( V_2 , V_260 ,
& V_2 -> V_55 -> V_170 [ V_57 & ( V_2 -> V_10 - 1 ) ] ) ) ) {
F_112 ( V_2 , L_19 ,
V_57 ,
& V_2 -> V_55 -> V_170 [ V_57 % V_2 -> V_10 ] ) ;
return - V_9 ;
}
V_259 = F_181 ( V_2 , V_260 ) ;
if ( F_176 ( V_259 >= V_2 -> V_10 ) ) {
F_112 ( V_2 , L_20 ,
V_259 , V_2 -> V_10 ) ;
return - V_13 ;
}
* V_251 = * V_252 = 0 ;
if ( F_176 ( log ) )
* V_242 = 0 ;
V_51 = V_259 ;
do {
unsigned V_256 = * V_252 + * V_251 ;
if ( F_176 ( V_51 >= V_2 -> V_10 ) ) {
F_112 ( V_2 , L_21 ,
V_51 , V_2 -> V_10 , V_259 ) ;
return - V_13 ;
}
if ( F_176 ( ++ V_254 > V_2 -> V_10 ) ) {
F_112 ( V_2 , L_10
L_22 ,
V_51 , V_2 -> V_10 , V_259 ) ;
return - V_13 ;
}
V_40 = F_110 ( V_2 , & V_54 , V_2 -> V_54 + V_51 ,
sizeof V_54 ) ;
if ( F_176 ( V_40 ) ) {
F_112 ( V_2 , L_23 ,
V_51 , V_2 -> V_54 + V_51 ) ;
return - V_9 ;
}
if ( V_54 . V_36 & F_175 ( V_2 , V_257 ) ) {
V_40 = F_184 ( V_2 , V_246 , V_247 ,
V_251 , V_252 ,
log , V_242 , & V_54 ) ;
if ( F_176 ( V_40 < 0 ) ) {
if ( V_40 != - V_163 )
F_112 ( V_2 , L_24
L_25 , V_51 ) ;
return V_40 ;
}
continue;
}
if ( V_54 . V_36 & F_175 ( V_2 , V_258 ) )
V_156 = V_138 ;
else
V_156 = V_142 ;
V_40 = F_106 ( V_2 , F_186 ( V_2 , V_54 . V_118 ) ,
F_185 ( V_2 , V_54 . V_172 ) , V_246 + V_256 ,
V_247 - V_256 , V_156 ) ;
if ( F_176 ( V_40 < 0 ) ) {
if ( V_40 != - V_163 )
F_112 ( V_2 , L_26 ,
V_40 , V_51 ) ;
return V_40 ;
}
if ( V_156 == V_138 ) {
* V_252 += V_40 ;
if ( F_176 ( log ) ) {
log [ * V_242 ] . V_118 = F_186 ( V_2 , V_54 . V_118 ) ;
log [ * V_242 ] . V_172 = F_185 ( V_2 , V_54 . V_172 ) ;
++ * V_242 ;
}
} else {
if ( F_176 ( * V_252 ) ) {
F_112 ( V_2 , L_27
L_28 , V_51 ) ;
return - V_13 ;
}
* V_251 += V_40 ;
}
} while ( ( V_51 = F_182 ( V_2 , & V_54 ) ) != - 1 );
V_2 -> V_57 ++ ;
F_162 ( ! ( V_2 -> V_62 & V_261 ) ) ;
return V_259 ;
}
void F_191 ( struct V_1 * V_2 , int V_115 )
{
V_2 -> V_57 -= V_115 ;
}
int F_192 ( struct V_1 * V_2 , unsigned int V_259 , int V_172 )
{
struct V_262 V_84 = {
F_193 ( V_2 , V_259 ) ,
F_193 (vq, len)
} ;
return F_194 ( V_2 , & V_84 , 1 ) ;
}
static int F_195 ( struct V_1 * V_2 ,
struct V_262 * V_84 ,
unsigned V_253 )
{
struct V_262 T_1 * V_56 ;
T_11 V_263 , V_264 ;
int V_128 ;
V_128 = V_2 -> V_59 & ( V_2 -> V_10 - 1 ) ;
V_56 = V_2 -> V_56 -> V_170 + V_128 ;
if ( V_253 == 1 ) {
if ( F_174 ( V_2 , V_84 [ 0 ] . V_265 , & V_56 -> V_265 ) ) {
F_112 ( V_2 , L_29 ) ;
return - V_9 ;
}
if ( F_174 ( V_2 , V_84 [ 0 ] . V_172 , & V_56 -> V_172 ) ) {
F_112 ( V_2 , L_30 ) ;
return - V_9 ;
}
} else if ( F_104 ( V_2 , V_56 , V_84 , V_253 * sizeof *V_56 ) ) {
F_112 ( V_2 , L_31 ) ;
return - V_9 ;
}
if ( F_176 ( V_2 -> V_63 ) ) {
F_51 () ;
F_168 ( V_2 -> V_66 ,
V_2 -> V_64 +
( ( void T_1 * ) V_56 - ( void T_1 * ) V_2 -> V_56 ) ,
V_253 * sizeof *V_56 ) ;
}
V_263 = V_2 -> V_59 ;
V_264 = ( V_2 -> V_59 += V_253 ) ;
if ( F_176 ( ( T_11 ) ( V_264 - V_2 -> V_60 ) < ( T_11 ) ( V_264 - V_263 ) ) )
V_2 -> V_61 = false ;
return 0 ;
}
int F_194 ( struct V_1 * V_2 , struct V_262 * V_84 ,
unsigned V_253 )
{
int V_128 , V_115 , V_203 ;
V_128 = V_2 -> V_59 & ( V_2 -> V_10 - 1 ) ;
V_115 = V_2 -> V_10 - V_128 ;
if ( V_115 < V_253 ) {
V_203 = F_195 ( V_2 , V_84 , V_115 ) ;
if ( V_203 < 0 )
return V_203 ;
V_84 += V_115 ;
V_253 -= V_115 ;
}
V_203 = F_195 ( V_2 , V_84 , V_253 ) ;
F_51 () ;
if ( F_174 ( V_2 , F_175 ( V_2 , V_2 -> V_59 ) ,
& V_2 -> V_56 -> V_14 ) ) {
F_112 ( V_2 , L_32 ) ;
return - V_9 ;
}
if ( F_176 ( V_2 -> V_63 ) ) {
F_168 ( V_2 -> V_66 ,
V_2 -> V_64 + F_152 ( struct V_168 , V_14 ) ,
sizeof V_2 -> V_56 -> V_14 ) ;
if ( V_2 -> V_71 )
F_171 ( V_2 -> V_71 , 1 ) ;
}
return V_203 ;
}
static bool F_196 ( struct V_38 * V_39 , struct V_1 * V_2 )
{
T_13 V_263 , V_264 ;
T_12 V_266 ;
bool V_267 ;
F_197 () ;
if ( F_10 ( V_2 , V_268 ) &&
F_176 ( V_2 -> V_58 == V_2 -> V_57 ) )
return true ;
if ( ! F_10 ( V_2 , V_169 ) ) {
T_12 V_36 ;
if ( F_189 ( V_2 , V_36 , & V_2 -> V_55 -> V_36 ) ) {
F_112 ( V_2 , L_33 ) ;
return true ;
}
return ! ( V_36 & F_175 ( V_2 , V_269 ) ) ;
}
V_263 = V_2 -> V_60 ;
V_267 = V_2 -> V_61 ;
V_264 = V_2 -> V_60 = V_2 -> V_59 ;
V_2 -> V_61 = true ;
if ( F_176 ( ! V_267 ) )
return true ;
if ( F_189 ( V_2 , V_266 , F_198 ( V_2 ) ) ) {
F_112 ( V_2 , L_34 ) ;
return true ;
}
return F_199 ( F_181 ( V_2 , V_266 ) , V_264 , V_263 ) ;
}
void F_200 ( struct V_38 * V_39 , struct V_1 * V_2 )
{
if ( V_2 -> V_69 && F_196 ( V_39 , V_2 ) )
F_171 ( V_2 -> V_69 , 1 ) ;
}
void F_201 ( struct V_38 * V_39 ,
struct V_1 * V_2 ,
unsigned int V_259 , int V_172 )
{
F_192 ( V_2 , V_259 , V_172 ) ;
F_200 ( V_39 , V_2 ) ;
}
void F_202 ( struct V_38 * V_39 ,
struct V_1 * V_2 ,
struct V_262 * V_84 , unsigned V_253 )
{
F_194 ( V_2 , V_84 , V_253 ) ;
F_200 ( V_39 , V_2 ) ;
}
bool F_203 ( struct V_38 * V_39 , struct V_1 * V_2 )
{
T_12 V_58 ;
int V_203 ;
if ( V_2 -> V_58 != V_2 -> V_57 )
return false ;
V_203 = F_189 ( V_2 , V_58 , & V_2 -> V_55 -> V_14 ) ;
if ( F_176 ( V_203 ) )
return false ;
V_2 -> V_58 = F_181 ( V_2 , V_58 ) ;
return V_2 -> V_58 == V_2 -> V_57 ;
}
bool F_204 ( struct V_38 * V_39 , struct V_1 * V_2 )
{
T_12 V_58 ;
int V_203 ;
if ( ! ( V_2 -> V_62 & V_261 ) )
return false ;
V_2 -> V_62 &= ~ V_261 ;
if ( ! F_10 ( V_2 , V_169 ) ) {
V_203 = F_173 ( V_2 ) ;
if ( V_203 ) {
F_112 ( V_2 , L_35 ,
& V_2 -> V_56 -> V_36 , V_203 ) ;
return false ;
}
} else {
V_203 = F_177 ( V_2 , V_2 -> V_58 ) ;
if ( V_203 ) {
F_112 ( V_2 , L_36 ,
F_178 ( V_2 ) , V_203 ) ;
return false ;
}
}
F_197 () ;
V_203 = F_189 ( V_2 , V_58 , & V_2 -> V_55 -> V_14 ) ;
if ( V_203 ) {
F_112 ( V_2 , L_37 ,
& V_2 -> V_55 -> V_14 , V_203 ) ;
return false ;
}
return F_181 ( V_2 , V_58 ) != V_2 -> V_58 ;
}
void F_205 ( struct V_38 * V_39 , struct V_1 * V_2 )
{
int V_203 ;
if ( V_2 -> V_62 & V_261 )
return;
V_2 -> V_62 |= V_261 ;
if ( ! F_10 ( V_2 , V_169 ) ) {
V_203 = F_173 ( V_2 ) ;
if ( V_203 )
F_112 ( V_2 , L_35 ,
& V_2 -> V_56 -> V_36 , V_203 ) ;
}
}
struct V_114 * F_141 ( struct V_1 * V_2 , int type )
{
struct V_114 * V_45 = F_58 ( sizeof *V_45 , V_86 ) ;
if ( ! V_45 )
return NULL ;
V_45 -> V_2 = V_2 ;
V_45 -> V_152 . type = type ;
return V_45 ;
}
void F_139 ( struct V_38 * V_39 , struct V_270 * V_259 ,
struct V_114 * V_45 )
{
F_89 ( & V_39 -> V_93 ) ;
F_121 ( & V_45 -> V_45 , V_259 ) ;
F_90 ( & V_39 -> V_93 ) ;
F_93 ( & V_39 -> V_29 , V_95 | V_117 ) ;
}
struct V_114 * F_136 ( struct V_38 * V_39 ,
struct V_270 * V_259 )
{
struct V_114 * V_45 = NULL ;
F_89 ( & V_39 -> V_93 ) ;
if ( ! F_132 ( V_259 ) ) {
V_45 = F_119 ( V_259 , struct V_114 ,
V_45 ) ;
F_84 ( & V_45 -> V_45 ) ;
}
F_90 ( & V_39 -> V_93 ) ;
return V_45 ;
}
static int T_14 F_206 ( void )
{
return 0 ;
}
static void T_15 F_207 ( void )
{
}
