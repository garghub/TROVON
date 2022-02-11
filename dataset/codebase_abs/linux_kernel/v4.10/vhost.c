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
static void F_38 ( struct V_38 * V_39 ,
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
V_2 -> V_54 = 0 ;
V_2 -> V_55 = false ;
V_2 -> V_56 = 0 ;
V_2 -> V_57 = false ;
V_2 -> V_58 = - 1ull ;
V_2 -> V_7 = NULL ;
V_2 -> V_59 = 0 ;
V_2 -> V_60 = NULL ;
V_2 -> V_61 = NULL ;
V_2 -> error = NULL ;
V_2 -> V_62 = NULL ;
V_2 -> V_63 = NULL ;
V_2 -> V_64 = NULL ;
V_2 -> V_65 = NULL ;
F_11 ( V_2 ) ;
F_1 ( V_2 ) ;
V_2 -> V_66 = 0 ;
V_2 -> V_67 = NULL ;
V_2 -> V_68 = NULL ;
}
static int F_39 ( void * V_69 )
{
struct V_38 * V_39 = V_69 ;
struct V_19 * V_20 , * V_70 ;
struct V_71 * V_45 ;
T_7 V_72 = F_40 () ;
F_41 ( V_73 ) ;
F_42 ( V_39 -> V_74 ) ;
for (; ; ) {
F_43 ( V_75 ) ;
if ( F_44 () ) {
F_45 ( V_76 ) ;
break;
}
V_45 = F_46 ( & V_39 -> V_46 ) ;
if ( ! V_45 )
F_47 () ;
V_45 = F_48 ( V_45 ) ;
F_49 () ;
F_50 (work, work_next, node, node) {
F_20 ( V_35 , & V_20 -> V_36 ) ;
F_45 ( V_76 ) ;
V_20 -> V_34 ( V_20 ) ;
if ( F_51 () )
F_47 () ;
}
}
F_52 ( V_39 -> V_74 ) ;
F_41 ( V_72 ) ;
return 0 ;
}
static void F_53 ( struct V_1 * V_2 )
{
F_54 ( V_2 -> V_77 ) ;
V_2 -> V_77 = NULL ;
F_54 ( V_2 -> log ) ;
V_2 -> log = NULL ;
F_54 ( V_2 -> V_78 ) ;
V_2 -> V_78 = NULL ;
}
static long F_55 ( struct V_38 * V_39 )
{
struct V_1 * V_2 ;
int V_79 ;
for ( V_79 = 0 ; V_79 < V_39 -> V_80 ; ++ V_79 ) {
V_2 = V_39 -> V_81 [ V_79 ] ;
V_2 -> V_77 = F_56 ( sizeof * V_2 -> V_77 * V_82 ,
V_83 ) ;
V_2 -> log = F_56 ( sizeof * V_2 -> log * V_82 , V_83 ) ;
V_2 -> V_78 = F_56 ( sizeof * V_2 -> V_78 * V_82 , V_83 ) ;
if ( ! V_2 -> V_77 || ! V_2 -> log || ! V_2 -> V_78 )
goto V_84;
}
return 0 ;
V_84:
for (; V_79 >= 0 ; -- V_79 )
F_53 ( V_39 -> V_81 [ V_79 ] ) ;
return - V_85 ;
}
static void F_57 ( struct V_38 * V_39 )
{
int V_79 ;
for ( V_79 = 0 ; V_79 < V_39 -> V_80 ; ++ V_79 )
F_53 ( V_39 -> V_81 [ V_79 ] ) ;
}
void F_58 ( struct V_38 * V_39 ,
struct V_1 * * V_81 , int V_80 )
{
struct V_1 * V_2 ;
int V_79 ;
V_39 -> V_81 = V_81 ;
V_39 -> V_80 = V_80 ;
F_59 ( & V_39 -> V_86 ) ;
V_39 -> V_65 = NULL ;
V_39 -> V_87 = NULL ;
V_39 -> V_67 = NULL ;
V_39 -> V_68 = NULL ;
V_39 -> V_74 = NULL ;
V_39 -> V_44 = NULL ;
F_60 ( & V_39 -> V_46 ) ;
F_21 ( & V_39 -> V_29 ) ;
F_61 ( & V_39 -> V_88 ) ;
F_61 ( & V_39 -> V_89 ) ;
F_62 ( & V_39 -> V_90 ) ;
for ( V_79 = 0 ; V_79 < V_39 -> V_80 ; ++ V_79 ) {
V_2 = V_39 -> V_81 [ V_79 ] ;
V_2 -> log = NULL ;
V_2 -> V_77 = NULL ;
V_2 -> V_78 = NULL ;
V_2 -> V_39 = V_39 ;
F_59 ( & V_2 -> V_86 ) ;
F_38 ( V_39 , V_2 ) ;
if ( V_2 -> V_91 )
F_22 ( & V_2 -> V_27 , V_2 -> V_91 ,
V_92 , V_39 ) ;
}
}
long F_63 ( struct V_38 * V_39 )
{
return V_39 -> V_74 == V_93 -> V_74 ? 0 : - V_94 ;
}
static void F_64 ( struct V_19 * V_20 )
{
struct V_95 * V_6 ;
V_6 = F_13 ( V_20 , struct V_95 , V_20 ) ;
V_6 -> V_40 = F_65 ( V_6 -> V_96 , V_93 ) ;
}
static int F_66 ( struct V_38 * V_39 )
{
struct V_95 V_97 ;
V_97 . V_96 = V_93 ;
F_19 ( & V_97 . V_20 , F_64 ) ;
F_30 ( V_39 , & V_97 . V_20 ) ;
F_28 ( V_39 , & V_97 . V_20 ) ;
return V_97 . V_40 ;
}
bool F_67 ( struct V_38 * V_39 )
{
return V_39 -> V_74 ;
}
long F_68 ( struct V_38 * V_39 )
{
struct V_98 * V_44 ;
int V_99 ;
if ( F_67 ( V_39 ) ) {
V_99 = - V_8 ;
goto V_100;
}
V_39 -> V_74 = F_69 ( V_93 ) ;
V_44 = F_70 ( F_39 , V_39 , L_1 , V_93 -> V_101 ) ;
if ( F_71 ( V_44 ) ) {
V_99 = F_72 ( V_44 ) ;
goto V_102;
}
V_39 -> V_44 = V_44 ;
F_35 ( V_44 ) ;
V_99 = F_66 ( V_39 ) ;
if ( V_99 )
goto V_103;
V_99 = F_55 ( V_39 ) ;
if ( V_99 )
goto V_103;
return 0 ;
V_103:
F_73 ( V_44 ) ;
V_39 -> V_44 = NULL ;
V_102:
if ( V_39 -> V_74 )
F_74 ( V_39 -> V_74 ) ;
V_39 -> V_74 = NULL ;
V_100:
return V_99 ;
}
static void * F_75 ( unsigned long V_104 )
{
void * V_105 = F_76 ( V_104 , V_83 | V_106 | V_107 ) ;
if ( ! V_105 )
V_105 = F_77 ( V_104 ) ;
return V_105 ;
}
struct V_108 * F_78 ( void )
{
return F_75 ( sizeof( struct V_108 ) ) ;
}
void F_79 ( struct V_38 * V_39 , struct V_108 * V_67 )
{
int V_79 ;
F_80 ( V_39 , true ) ;
F_61 ( & V_67 -> V_109 ) ;
V_39 -> V_67 = V_67 ;
for ( V_79 = 0 ; V_79 < V_39 -> V_80 ; ++ V_79 )
V_39 -> V_81 [ V_79 ] -> V_67 = V_67 ;
}
void F_81 ( struct V_38 * V_39 )
{
int V_79 ;
for ( V_79 = 0 ; V_79 < V_39 -> V_80 ; ++ V_79 ) {
if ( V_39 -> V_81 [ V_79 ] -> V_62 && V_39 -> V_81 [ V_79 ] -> V_91 ) {
F_27 ( & V_39 -> V_81 [ V_79 ] -> V_27 ) ;
F_32 ( & V_39 -> V_81 [ V_79 ] -> V_27 ) ;
}
}
}
static void F_82 ( struct V_108 * V_67 ,
struct V_110 * V_45 )
{
F_83 ( V_45 , & V_67 -> V_111 ) ;
F_84 ( & V_45 -> V_112 ) ;
F_54 ( V_45 ) ;
V_67 -> V_113 -- ;
}
static void F_85 ( struct V_108 * V_67 )
{
struct V_110 * V_45 , * V_114 ;
if ( ! V_67 )
return;
F_86 (node, tmp, &umem->umem_list, link)
F_82 ( V_67 , V_45 ) ;
F_87 ( V_67 ) ;
}
static void F_88 ( struct V_38 * V_39 )
{
struct V_115 * V_45 , * V_105 ;
F_89 ( & V_39 -> V_90 ) ;
F_86 (node, n, &dev->read_list, node) {
F_84 ( & V_45 -> V_45 ) ;
F_54 ( V_45 ) ;
}
F_86 (node, n, &dev->pending_list, node) {
F_84 ( & V_45 -> V_45 ) ;
F_54 ( V_45 ) ;
}
F_90 ( & V_39 -> V_90 ) ;
}
void F_80 ( struct V_38 * V_39 , bool V_116 )
{
int V_79 ;
for ( V_79 = 0 ; V_79 < V_39 -> V_80 ; ++ V_79 ) {
if ( V_39 -> V_81 [ V_79 ] -> V_61 )
F_91 ( V_39 -> V_81 [ V_79 ] -> V_61 ) ;
if ( V_39 -> V_81 [ V_79 ] -> error )
F_92 ( V_39 -> V_81 [ V_79 ] -> error ) ;
if ( V_39 -> V_81 [ V_79 ] -> V_62 )
F_92 ( V_39 -> V_81 [ V_79 ] -> V_62 ) ;
if ( V_39 -> V_81 [ V_79 ] -> V_63 )
F_91 ( V_39 -> V_81 [ V_79 ] -> V_63 ) ;
if ( V_39 -> V_81 [ V_79 ] -> V_64 )
F_92 ( V_39 -> V_81 [ V_79 ] -> V_64 ) ;
F_38 ( V_39 , V_39 -> V_81 [ V_79 ] ) ;
}
F_57 ( V_39 ) ;
if ( V_39 -> V_65 )
F_91 ( V_39 -> V_65 ) ;
V_39 -> V_65 = NULL ;
if ( V_39 -> V_87 )
F_92 ( V_39 -> V_87 ) ;
V_39 -> V_87 = NULL ;
F_85 ( V_39 -> V_67 ) ;
V_39 -> V_67 = NULL ;
F_85 ( V_39 -> V_68 ) ;
V_39 -> V_68 = NULL ;
F_88 ( V_39 ) ;
F_93 ( & V_39 -> V_29 , V_92 | V_117 ) ;
F_94 ( ! F_37 ( & V_39 -> V_46 ) ) ;
if ( V_39 -> V_44 ) {
F_73 ( V_39 -> V_44 ) ;
V_39 -> V_44 = NULL ;
}
if ( V_39 -> V_74 )
F_74 ( V_39 -> V_74 ) ;
V_39 -> V_74 = NULL ;
}
static int F_95 ( void T_1 * V_60 , T_8 V_118 , unsigned long V_119 )
{
T_8 V_120 = V_118 / V_121 / 8 ;
if ( V_120 > V_122 - ( unsigned long ) V_60 ||
V_120 + ( unsigned long ) V_60 > V_122 )
return 0 ;
return F_96 ( V_123 , V_60 + V_120 ,
( V_119 + V_121 * 8 - 1 ) / V_121 / 8 ) ;
}
static bool F_97 ( T_8 V_124 , T_8 V_104 )
{
return V_124 > V_122 || V_104 > V_122 || V_124 > V_122 - V_104 ;
}
static int F_98 ( void T_1 * V_60 , struct V_108 * V_67 ,
int V_125 )
{
struct V_110 * V_45 ;
if ( ! V_67 )
return 0 ;
F_99 (node, &umem->umem_list, link) {
unsigned long V_120 = V_45 -> V_126 ;
if ( F_97 ( V_45 -> V_126 , V_45 -> V_104 ) )
return 0 ;
if ( ! F_96 ( V_123 , ( void T_1 * ) V_120 ,
V_45 -> V_104 ) )
return 0 ;
else if ( V_125 && ! F_95 ( V_60 ,
V_45 -> V_127 ,
V_45 -> V_104 ) )
return 0 ;
}
return 1 ;
}
static int F_100 ( struct V_38 * V_128 , struct V_108 * V_67 ,
int V_125 )
{
int V_79 ;
for ( V_79 = 0 ; V_79 < V_128 -> V_80 ; ++ V_79 ) {
int V_129 ;
bool log ;
F_101 ( & V_128 -> V_81 [ V_79 ] -> V_86 ) ;
log = V_125 || F_10 ( V_128 -> V_81 [ V_79 ] , V_130 ) ;
if ( V_128 -> V_81 [ V_79 ] -> V_7 )
V_129 = F_98 ( V_128 -> V_81 [ V_79 ] -> V_60 ,
V_67 , log ) ;
else
V_129 = 1 ;
F_102 ( & V_128 -> V_81 [ V_79 ] -> V_86 ) ;
if ( ! V_129 )
return 0 ;
}
return 1 ;
}
static int F_103 ( struct V_1 * V_2 , void T_1 * V_131 ,
const void * V_132 , unsigned V_104 )
{
int V_40 ;
if ( ! V_2 -> V_68 )
return F_104 ( V_131 , V_132 , V_104 ) ;
else {
struct V_133 V_134 ;
V_40 = F_105 ( V_2 , ( T_8 ) ( V_135 ) V_131 , V_104 , V_2 -> V_136 ,
F_106 ( V_2 -> V_136 ) ,
V_137 ) ;
if ( V_40 < 0 )
goto V_138;
F_107 ( & V_134 , V_139 , V_2 -> V_136 , V_40 , V_104 ) ;
V_40 = F_108 ( V_132 , V_104 , & V_134 ) ;
if ( V_40 == V_104 )
V_40 = 0 ;
}
V_138:
return V_40 ;
}
static int F_109 ( struct V_1 * V_2 , void * V_131 ,
void T_1 * V_132 , unsigned V_104 )
{
int V_40 ;
if ( ! V_2 -> V_68 )
return F_110 ( V_131 , V_132 , V_104 ) ;
else {
struct V_133 V_140 ;
V_40 = F_105 ( V_2 , ( T_8 ) ( V_135 ) V_132 , V_104 , V_2 -> V_136 ,
F_106 ( V_2 -> V_136 ) ,
V_141 ) ;
if ( V_40 < 0 ) {
F_111 ( V_2 , L_2
L_3 , V_132 ,
( unsigned long long ) V_104 ) ;
goto V_138;
}
F_107 ( & V_140 , V_142 , V_2 -> V_136 , V_40 , V_104 ) ;
V_40 = F_112 ( V_131 , V_104 , & V_140 ) ;
if ( V_40 == V_104 )
V_40 = 0 ;
}
V_138:
return V_40 ;
}
static void T_1 * F_113 ( struct V_1 * V_2 ,
void T_1 * V_118 , unsigned V_104 )
{
int V_40 ;
V_40 = F_105 ( V_2 , ( T_8 ) ( V_135 ) V_118 , V_104 , V_2 -> V_136 ,
F_106 ( V_2 -> V_136 ) ,
V_141 ) ;
if ( V_40 < 0 ) {
F_111 ( V_2 , L_2
L_3 , V_118 ,
( unsigned long long ) V_104 ) ;
return NULL ;
}
if ( V_40 != 1 || V_2 -> V_136 [ 0 ] . V_143 != V_104 ) {
F_111 ( V_2 , L_4
L_3 , V_118 ,
( unsigned long long ) V_104 ) ;
return NULL ;
}
return V_2 -> V_136 [ 0 ] . V_144 ;
}
static void F_114 ( struct V_38 * V_128 )
{
int V_79 = 0 ;
for ( V_79 = 0 ; V_79 < V_128 -> V_80 ; ++ V_79 )
F_101 ( & V_128 -> V_81 [ V_79 ] -> V_86 ) ;
}
static void F_115 ( struct V_38 * V_128 )
{
int V_79 = 0 ;
for ( V_79 = 0 ; V_79 < V_128 -> V_80 ; ++ V_79 )
F_102 ( & V_128 -> V_81 [ V_79 ] -> V_86 ) ;
}
static int F_116 ( struct V_108 * V_67 ,
T_8 V_127 , T_8 V_104 , T_8 V_145 ,
T_8 V_126 , int V_146 )
{
struct V_110 * V_114 , * V_45 = F_56 ( sizeof( * V_45 ) , V_147 ) ;
if ( ! V_45 )
return - V_85 ;
if ( V_67 -> V_113 == V_148 ) {
V_114 = F_117 ( & V_67 -> V_109 , F_118 ( * V_114 ) , V_112 ) ;
F_82 ( V_67 , V_114 ) ;
}
V_45 -> V_127 = V_127 ;
V_45 -> V_104 = V_104 ;
V_45 -> V_149 = V_145 ;
V_45 -> V_126 = V_126 ;
V_45 -> V_146 = V_146 ;
F_61 ( & V_45 -> V_112 ) ;
F_119 ( & V_45 -> V_112 , & V_67 -> V_109 ) ;
F_120 ( V_45 , & V_67 -> V_111 ) ;
V_67 -> V_113 ++ ;
return 0 ;
}
static void F_121 ( struct V_108 * V_67 ,
T_8 V_127 , T_8 V_145 )
{
struct V_110 * V_45 ;
while ( ( V_45 = F_122 ( & V_67 -> V_111 ,
V_127 , V_145 ) ) )
F_82 ( V_67 , V_45 ) ;
}
static void F_123 ( struct V_38 * V_128 ,
struct V_150 * V_151 )
{
struct V_115 * V_45 , * V_105 ;
F_89 ( & V_128 -> V_90 ) ;
F_86 (node, n, &d->pending_list, node) {
struct V_150 * V_152 = & V_45 -> V_151 . V_68 ;
if ( V_151 -> V_153 <= V_152 -> V_153 &&
V_151 -> V_153 + V_151 -> V_104 - 1 > V_152 -> V_153 &&
V_152 -> type == V_154 ) {
F_18 ( & V_45 -> V_2 -> V_27 ) ;
F_84 ( & V_45 -> V_45 ) ;
F_54 ( V_45 ) ;
}
}
F_90 ( & V_128 -> V_90 ) ;
}
static int F_124 ( T_8 V_124 , T_8 V_104 , int V_155 )
{
unsigned long V_120 = V_124 ;
if ( F_97 ( V_124 , V_104 ) )
return - V_9 ;
if ( ( V_155 & V_141 ) &&
! F_96 ( V_156 , ( void T_1 * ) V_120 , V_104 ) )
return - V_9 ;
if ( ( V_155 & V_137 ) &&
! F_96 ( V_123 , ( void T_1 * ) V_120 , V_104 ) )
return - V_9 ;
return 0 ;
}
static int F_125 ( struct V_38 * V_39 ,
struct V_150 * V_151 )
{
int V_40 = 0 ;
F_114 ( V_39 ) ;
switch ( V_151 -> type ) {
case V_157 :
if ( ! V_39 -> V_68 ) {
V_40 = - V_9 ;
break;
}
if ( F_124 ( V_151 -> V_124 , V_151 -> V_104 , V_151 -> V_146 ) ) {
V_40 = - V_9 ;
break;
}
if ( F_116 ( V_39 -> V_68 , V_151 -> V_153 , V_151 -> V_104 ,
V_151 -> V_153 + V_151 -> V_104 - 1 ,
V_151 -> V_124 , V_151 -> V_146 ) ) {
V_40 = - V_85 ;
break;
}
F_123 ( V_39 , V_151 ) ;
break;
case V_158 :
F_121 ( V_39 -> V_68 , V_151 -> V_153 ,
V_151 -> V_153 + V_151 -> V_104 - 1 ) ;
break;
default:
V_40 = - V_13 ;
break;
}
F_115 ( V_39 ) ;
return V_40 ;
}
T_9 F_126 ( struct V_38 * V_39 ,
struct V_133 * V_132 )
{
struct V_115 V_45 ;
unsigned V_104 = sizeof( struct V_159 ) ;
T_10 V_40 ;
int V_99 ;
if ( F_127 ( V_132 ) < V_104 )
return 0 ;
V_40 = F_112 ( & V_45 . V_151 , V_104 , V_132 ) ;
if ( V_40 != V_104 )
goto V_37;
switch ( V_45 . V_151 . type ) {
case V_160 :
V_99 = F_125 ( V_39 , & V_45 . V_151 . V_68 ) ;
if ( V_99 )
V_40 = V_99 ;
break;
default:
V_40 = - V_13 ;
break;
}
V_37:
return V_40 ;
}
unsigned int F_128 ( struct V_23 * V_23 , struct V_38 * V_39 ,
T_4 * V_29 )
{
unsigned int V_33 = 0 ;
F_129 ( V_23 , & V_39 -> V_29 , V_29 ) ;
if ( ! F_130 ( & V_39 -> V_88 ) )
V_33 |= V_92 | V_117 ;
return V_33 ;
}
T_9 F_131 ( struct V_38 * V_39 , struct V_133 * V_131 ,
int V_161 )
{
F_132 ( V_29 ) ;
struct V_115 * V_45 ;
T_9 V_40 = 0 ;
unsigned V_104 = sizeof( struct V_159 ) ;
if ( F_127 ( V_131 ) < V_104 )
return 0 ;
while ( 1 ) {
if ( ! V_161 )
F_133 ( & V_39 -> V_29 , & V_29 ,
V_75 ) ;
V_45 = F_134 ( V_39 , & V_39 -> V_88 ) ;
if ( V_45 )
break;
if ( V_161 ) {
V_40 = - V_162 ;
break;
}
if ( F_135 ( V_93 ) ) {
V_40 = - V_163 ;
break;
}
if ( ! V_39 -> V_68 ) {
V_40 = - V_164 ;
break;
}
F_47 () ;
}
if ( ! V_161 )
F_136 ( & V_39 -> V_29 , & V_29 ) ;
if ( V_45 ) {
V_40 = F_108 ( & V_45 -> V_151 , V_104 , V_131 ) ;
if ( V_40 != V_104 || V_45 -> V_151 . type != V_154 ) {
F_54 ( V_45 ) ;
return V_40 ;
}
F_137 ( V_39 , & V_39 -> V_89 , V_45 ) ;
}
return V_40 ;
}
static int F_138 ( struct V_1 * V_2 , T_8 V_153 , int V_155 )
{
struct V_38 * V_39 = V_2 -> V_39 ;
struct V_115 * V_45 ;
struct V_150 * V_151 ;
V_45 = F_139 ( V_2 , V_154 ) ;
if ( ! V_45 )
return - V_85 ;
V_151 = & V_45 -> V_151 . V_68 ;
V_151 -> type = V_154 ;
V_151 -> V_153 = V_153 ;
V_151 -> V_146 = V_155 ;
F_137 ( V_39 , & V_39 -> V_88 , V_45 ) ;
return 0 ;
}
static int F_140 ( struct V_1 * V_2 , unsigned int V_10 ,
struct V_165 T_1 * V_47 ,
struct V_166 T_1 * V_48 ,
struct V_167 T_1 * V_49 )
{
T_10 V_6 = F_10 ( V_2 , V_168 ) ? 2 : 0 ;
return F_96 ( V_156 , V_47 , V_10 * sizeof *V_47 ) &&
F_96 ( V_156 , V_48 ,
sizeof *V_48 + V_10 * sizeof * V_48 -> V_169 + V_6 ) &&
F_96 ( V_123 , V_49 ,
sizeof *V_49 + V_10 * sizeof * V_49 -> V_169 + V_6 ) ;
}
static int F_141 ( struct V_1 * V_2 ,
int V_155 , T_8 V_118 , T_8 V_170 )
{
const struct V_110 * V_45 ;
struct V_108 * V_67 = V_2 -> V_68 ;
T_8 V_6 = 0 , V_104 ;
while ( V_170 > V_6 ) {
V_45 = F_122 ( & V_67 -> V_111 ,
V_118 ,
V_118 + V_170 - 1 ) ;
if ( V_45 == NULL || V_45 -> V_127 > V_118 ) {
F_138 ( V_2 , V_118 , V_155 ) ;
return false ;
} else if ( ! ( V_45 -> V_146 & V_155 ) ) {
return false ;
}
V_104 = V_45 -> V_104 - V_118 + V_45 -> V_127 ;
V_6 += V_104 ;
V_118 += V_104 ;
}
return true ;
}
int F_142 ( struct V_1 * V_2 )
{
T_10 V_6 = F_10 ( V_2 , V_168 ) ? 2 : 0 ;
unsigned int V_10 = V_2 -> V_10 ;
if ( ! V_2 -> V_68 )
return 1 ;
return F_141 ( V_2 , V_141 , ( T_8 ) ( V_135 ) V_2 -> V_47 ,
V_10 * sizeof * V_2 -> V_47 ) &&
F_141 ( V_2 , V_141 , ( T_8 ) ( V_135 ) V_2 -> V_48 ,
sizeof * V_2 -> V_48 +
V_10 * sizeof * V_2 -> V_48 -> V_169 + V_6 ) &&
F_141 ( V_2 , V_137 , ( T_8 ) ( V_135 ) V_2 -> V_49 ,
sizeof * V_2 -> V_49 +
V_10 * sizeof * V_2 -> V_49 -> V_169 + V_6 ) ;
}
int F_143 ( struct V_38 * V_39 )
{
return F_100 ( V_39 , V_39 -> V_67 , 1 ) ;
}
static int F_144 ( struct V_1 * V_2 ,
void T_1 * V_60 )
{
T_10 V_6 = F_10 ( V_2 , V_168 ) ? 2 : 0 ;
return F_98 ( V_60 , V_2 -> V_67 ,
F_10 ( V_2 , V_130 ) ) &&
( ! V_2 -> V_57 || F_95 ( V_60 , V_2 -> V_58 ,
sizeof * V_2 -> V_49 +
V_2 -> V_10 * sizeof * V_2 -> V_49 -> V_169 + V_6 ) ) ;
}
int F_145 ( struct V_1 * V_2 )
{
if ( V_2 -> V_68 ) {
return 1 ;
}
return F_140 ( V_2 , V_2 -> V_10 , V_2 -> V_47 , V_2 -> V_48 , V_2 -> V_49 ) &&
F_144 ( V_2 , V_2 -> V_60 ) ;
}
static struct V_108 * F_146 ( void )
{
struct V_108 * V_67 = F_75 ( sizeof( * V_67 ) ) ;
if ( ! V_67 )
return NULL ;
V_67 -> V_111 = V_171 ;
V_67 -> V_113 = 0 ;
F_61 ( & V_67 -> V_109 ) ;
return V_67 ;
}
static long F_147 ( struct V_38 * V_128 , struct V_172 T_1 * V_173 )
{
struct V_172 V_174 , * V_175 ;
struct V_176 * V_177 ;
struct V_108 * V_178 , * V_179 ;
unsigned long V_104 = F_148 ( struct V_172 , V_180 ) ;
int V_79 ;
if ( F_6 ( & V_174 , V_173 , V_104 ) )
return - V_9 ;
if ( V_174 . V_181 )
return - V_182 ;
if ( V_174 . V_183 > V_184 )
return - V_185 ;
V_175 = F_75 ( V_104 + V_174 . V_183 * sizeof( * V_173 -> V_180 ) ) ;
if ( ! V_175 )
return - V_85 ;
memcpy ( V_175 , & V_174 , V_104 ) ;
if ( F_6 ( V_175 -> V_180 , V_173 -> V_180 ,
V_174 . V_183 * sizeof * V_173 -> V_180 ) ) {
F_87 ( V_175 ) ;
return - V_9 ;
}
V_178 = F_146 () ;
if ( ! V_178 ) {
F_87 ( V_175 ) ;
return - V_85 ;
}
for ( V_177 = V_175 -> V_180 ;
V_177 < V_175 -> V_180 + V_174 . V_183 ;
V_177 ++ ) {
if ( F_116 ( V_178 ,
V_177 -> V_186 ,
V_177 -> V_187 ,
V_177 -> V_186 +
V_177 -> V_187 - 1 ,
V_177 -> V_126 ,
V_188 ) )
goto V_99;
}
if ( ! F_100 ( V_128 , V_178 , 0 ) )
goto V_99;
V_179 = V_128 -> V_67 ;
V_128 -> V_67 = V_178 ;
for ( V_79 = 0 ; V_79 < V_128 -> V_80 ; ++ V_79 ) {
F_101 ( & V_128 -> V_81 [ V_79 ] -> V_86 ) ;
V_128 -> V_81 [ V_79 ] -> V_67 = V_178 ;
F_102 ( & V_128 -> V_81 [ V_79 ] -> V_86 ) ;
}
F_87 ( V_175 ) ;
F_85 ( V_179 ) ;
return 0 ;
V_99:
F_85 ( V_178 ) ;
F_87 ( V_175 ) ;
return - V_9 ;
}
long F_149 ( struct V_38 * V_128 , int V_189 , void T_1 * V_4 )
{
struct V_23 * V_190 , * V_191 = NULL ;
bool V_192 = false , V_193 = false ;
struct V_194 * V_195 = NULL ;
T_2 T_1 * V_196 = V_4 ;
struct V_1 * V_2 ;
struct V_5 V_6 ;
struct V_197 V_140 ;
struct V_198 V_120 ;
T_2 V_14 ;
long V_199 ;
V_199 = F_150 ( V_14 , V_196 ) ;
if ( V_199 < 0 )
return V_199 ;
if ( V_14 >= V_128 -> V_80 )
return - V_200 ;
V_2 = V_128 -> V_81 [ V_14 ] ;
F_101 ( & V_2 -> V_86 ) ;
switch ( V_189 ) {
case V_201 :
if ( V_2 -> V_7 ) {
V_199 = - V_8 ;
break;
}
if ( F_6 ( & V_6 , V_4 , sizeof V_6 ) ) {
V_199 = - V_9 ;
break;
}
if ( ! V_6 . V_10 || V_6 . V_10 > 0xffff || ( V_6 . V_10 & ( V_6 . V_10 - 1 ) ) ) {
V_199 = - V_13 ;
break;
}
V_2 -> V_10 = V_6 . V_10 ;
break;
case V_202 :
if ( V_2 -> V_7 ) {
V_199 = - V_8 ;
break;
}
if ( F_6 ( & V_6 , V_4 , sizeof V_6 ) ) {
V_199 = - V_9 ;
break;
}
if ( V_6 . V_10 > 0xffff ) {
V_199 = - V_13 ;
break;
}
V_2 -> V_50 = V_2 -> V_51 = V_6 . V_10 ;
V_2 -> V_52 = V_2 -> V_50 ;
break;
case V_203 :
V_6 . V_15 = V_14 ;
V_6 . V_10 = V_2 -> V_50 ;
if ( F_8 ( V_4 , & V_6 , sizeof V_6 ) )
V_199 = - V_9 ;
break;
case V_204 :
if ( F_6 ( & V_120 , V_4 , sizeof V_120 ) ) {
V_199 = - V_9 ;
break;
}
if ( V_120 . V_36 & ~ ( 0x1 << V_205 ) ) {
V_199 = - V_182 ;
break;
}
if ( ( T_8 ) ( unsigned long ) V_120 . V_206 != V_120 . V_206 ||
( T_8 ) ( unsigned long ) V_120 . V_207 != V_120 . V_207 ||
( T_8 ) ( unsigned long ) V_120 . V_208 != V_120 . V_208 ) {
V_199 = - V_9 ;
break;
}
F_151 ( V_209 * V_2 -> V_48 > V_210 ) ;
F_151 ( V_209 * V_2 -> V_49 > V_211 ) ;
if ( ( V_120 . V_208 & ( V_210 - 1 ) ) ||
( V_120 . V_207 & ( V_211 - 1 ) ) ||
( V_120 . V_212 & ( V_211 - 1 ) ) ) {
V_199 = - V_13 ;
break;
}
if ( V_2 -> V_7 ) {
if ( ! F_140 ( V_2 , V_2 -> V_10 ,
( void T_1 * ) ( unsigned long ) V_120 . V_206 ,
( void T_1 * ) ( unsigned long ) V_120 . V_208 ,
( void T_1 * ) ( unsigned long ) V_120 . V_207 ) ) {
V_199 = - V_13 ;
break;
}
if ( ( V_120 . V_36 & ( 0x1 << V_205 ) ) &&
! F_95 ( V_2 -> V_60 , V_120 . V_212 ,
sizeof * V_2 -> V_49 +
V_2 -> V_10 * sizeof * V_2 -> V_49 -> V_169 ) ) {
V_199 = - V_13 ;
break;
}
}
V_2 -> V_57 = ! ! ( V_120 . V_36 & ( 0x1 << V_205 ) ) ;
V_2 -> V_47 = ( void T_1 * ) ( unsigned long ) V_120 . V_206 ;
V_2 -> V_48 = ( void T_1 * ) ( unsigned long ) V_120 . V_208 ;
V_2 -> V_58 = V_120 . V_212 ;
V_2 -> V_49 = ( void T_1 * ) ( unsigned long ) V_120 . V_207 ;
break;
case V_213 :
if ( F_6 ( & V_140 , V_4 , sizeof V_140 ) ) {
V_199 = - V_9 ;
break;
}
V_190 = V_140 . V_214 == - 1 ? NULL : F_152 ( V_140 . V_214 ) ;
if ( F_71 ( V_190 ) ) {
V_199 = F_72 ( V_190 ) ;
break;
}
if ( V_190 != V_2 -> V_62 ) {
V_193 = ( V_191 = V_2 -> V_62 ) != NULL ;
V_192 = ( V_2 -> V_62 = V_190 ) != NULL ;
} else
V_191 = V_190 ;
break;
case V_215 :
if ( F_6 ( & V_140 , V_4 , sizeof V_140 ) ) {
V_199 = - V_9 ;
break;
}
V_190 = V_140 . V_214 == - 1 ? NULL : F_152 ( V_140 . V_214 ) ;
if ( F_71 ( V_190 ) ) {
V_199 = F_72 ( V_190 ) ;
break;
}
if ( V_190 != V_2 -> V_64 ) {
V_191 = V_2 -> V_64 ;
V_195 = V_2 -> V_63 ;
V_2 -> V_64 = V_190 ;
V_2 -> V_63 = V_190 ?
F_153 ( V_190 ) : NULL ;
} else
V_191 = V_190 ;
break;
case V_216 :
if ( F_6 ( & V_140 , V_4 , sizeof V_140 ) ) {
V_199 = - V_9 ;
break;
}
V_190 = V_140 . V_214 == - 1 ? NULL : F_152 ( V_140 . V_214 ) ;
if ( F_71 ( V_190 ) ) {
V_199 = F_72 ( V_190 ) ;
break;
}
if ( V_190 != V_2 -> error ) {
V_191 = V_2 -> error ;
V_2 -> error = V_190 ;
V_195 = V_2 -> V_61 ;
V_2 -> V_61 = V_190 ?
F_153 ( V_190 ) : NULL ;
} else
V_191 = V_190 ;
break;
case V_217 :
V_199 = F_5 ( V_2 , V_4 ) ;
break;
case V_218 :
V_199 = F_7 ( V_2 , V_14 , V_4 ) ;
break;
case V_219 :
if ( F_6 ( & V_6 , V_4 , sizeof( V_6 ) ) ) {
V_199 = - V_9 ;
break;
}
V_2 -> V_66 = V_6 . V_10 ;
break;
case V_220 :
V_6 . V_15 = V_14 ;
V_6 . V_10 = V_2 -> V_66 ;
if ( F_8 ( V_4 , & V_6 , sizeof( V_6 ) ) )
V_199 = - V_9 ;
break;
default:
V_199 = - V_18 ;
}
if ( V_193 && V_2 -> V_91 )
F_27 ( & V_2 -> V_27 ) ;
if ( V_195 )
F_91 ( V_195 ) ;
if ( V_191 )
F_92 ( V_191 ) ;
if ( V_192 && V_2 -> V_91 )
V_199 = F_25 ( & V_2 -> V_27 , V_2 -> V_62 ) ;
F_102 ( & V_2 -> V_86 ) ;
if ( V_193 && V_2 -> V_91 )
F_32 ( & V_2 -> V_27 ) ;
return V_199 ;
}
int F_154 ( struct V_38 * V_128 , bool V_221 )
{
struct V_108 * V_222 , * V_223 ;
int V_79 ;
V_222 = F_146 () ;
if ( ! V_222 )
return - V_85 ;
V_223 = V_128 -> V_68 ;
V_128 -> V_68 = V_222 ;
for ( V_79 = 0 ; V_79 < V_128 -> V_80 ; ++ V_79 ) {
F_101 ( & V_128 -> V_81 [ V_79 ] -> V_86 ) ;
V_128 -> V_81 [ V_79 ] -> V_68 = V_222 ;
F_102 ( & V_128 -> V_81 [ V_79 ] -> V_86 ) ;
}
F_85 ( V_223 ) ;
return 0 ;
}
long F_155 ( struct V_38 * V_128 , unsigned int V_189 , void T_1 * V_4 )
{
struct V_23 * V_190 , * V_191 = NULL ;
struct V_194 * V_195 = NULL ;
T_8 V_224 ;
long V_199 ;
int V_79 , V_214 ;
if ( V_189 == V_225 ) {
V_199 = F_68 ( V_128 ) ;
goto V_37;
}
V_199 = F_63 ( V_128 ) ;
if ( V_199 )
goto V_37;
switch ( V_189 ) {
case V_226 :
V_199 = F_147 ( V_128 , V_4 ) ;
break;
case V_227 :
if ( F_6 ( & V_224 , V_4 , sizeof V_224 ) ) {
V_199 = - V_9 ;
break;
}
if ( ( T_8 ) ( unsigned long ) V_224 != V_224 ) {
V_199 = - V_9 ;
break;
}
for ( V_79 = 0 ; V_79 < V_128 -> V_80 ; ++ V_79 ) {
struct V_1 * V_2 ;
void T_1 * V_228 = ( void T_1 * ) ( unsigned long ) V_224 ;
V_2 = V_128 -> V_81 [ V_79 ] ;
F_101 ( & V_2 -> V_86 ) ;
if ( V_2 -> V_7 && ! F_144 ( V_2 , V_228 ) )
V_199 = - V_9 ;
else
V_2 -> V_60 = V_228 ;
F_102 ( & V_2 -> V_86 ) ;
}
break;
case V_229 :
V_199 = F_150 ( V_214 , ( int T_1 * ) V_4 ) ;
if ( V_199 < 0 )
break;
V_190 = V_214 == - 1 ? NULL : F_152 ( V_214 ) ;
if ( F_71 ( V_190 ) ) {
V_199 = F_72 ( V_190 ) ;
break;
}
if ( V_190 != V_128 -> V_87 ) {
V_191 = V_128 -> V_87 ;
V_128 -> V_87 = V_190 ;
V_195 = V_128 -> V_65 ;
V_128 -> V_65 = V_190 ?
F_153 ( V_190 ) : NULL ;
} else
V_191 = V_190 ;
for ( V_79 = 0 ; V_79 < V_128 -> V_80 ; ++ V_79 ) {
F_101 ( & V_128 -> V_81 [ V_79 ] -> V_86 ) ;
V_128 -> V_81 [ V_79 ] -> V_65 = V_128 -> V_65 ;
F_102 ( & V_128 -> V_81 [ V_79 ] -> V_86 ) ;
}
if ( V_195 )
F_91 ( V_195 ) ;
if ( V_191 )
F_92 ( V_191 ) ;
break;
default:
V_199 = - V_18 ;
break;
}
V_37:
return V_199 ;
}
static int F_156 ( int V_230 , void T_1 * V_118 )
{
unsigned long log = ( unsigned long ) V_118 ;
struct V_231 * V_231 ;
void * V_228 ;
int V_232 = V_230 + ( log % V_233 ) * 8 ;
int V_199 ;
V_199 = F_157 ( log , 1 , 1 , & V_231 ) ;
if ( V_199 < 0 )
return V_199 ;
F_158 ( V_199 != 1 ) ;
V_228 = F_159 ( V_231 ) ;
F_160 ( V_232 , V_228 ) ;
F_161 ( V_228 ) ;
F_162 ( V_231 ) ;
F_163 ( V_231 ) ;
return 0 ;
}
static int F_164 ( void T_1 * V_60 ,
T_8 V_234 , T_8 V_235 )
{
T_8 V_236 = V_234 / V_121 ;
int V_199 ;
if ( ! V_235 )
return 0 ;
V_235 += V_234 % V_121 ;
for (; ; ) {
T_8 V_228 = ( T_8 ) ( unsigned long ) V_60 ;
T_8 log = V_228 + V_236 / 8 ;
int V_232 = V_236 % 8 ;
if ( ( T_8 ) ( unsigned long ) log != log )
return - V_9 ;
V_199 = F_156 ( V_232 , ( void T_1 * ) ( unsigned long ) log ) ;
if ( V_199 < 0 )
return V_199 ;
if ( V_235 <= V_121 )
break;
V_235 -= V_121 ;
V_236 += 1 ;
}
return V_199 ;
}
int F_165 ( struct V_1 * V_2 , struct V_237 * log ,
unsigned int V_238 , T_8 V_170 )
{
int V_79 , V_199 ;
F_49 () ;
for ( V_79 = 0 ; V_79 < V_238 ; ++ V_79 ) {
T_8 V_239 = F_166 ( log [ V_79 ] . V_170 , V_170 ) ;
V_199 = F_164 ( V_2 -> V_60 , log [ V_79 ] . V_118 , V_239 ) ;
if ( V_199 < 0 )
return V_199 ;
V_170 -= V_239 ;
if ( ! V_170 ) {
if ( V_2 -> V_65 )
F_167 ( V_2 -> V_65 , 1 ) ;
return 0 ;
}
}
F_168 () ;
return 0 ;
}
static int F_169 ( struct V_1 * V_2 )
{
void T_1 * V_49 ;
if ( F_170 ( V_2 , F_171 ( V_2 , V_2 -> V_56 ) ,
& V_2 -> V_49 -> V_36 ) < 0 )
return - V_9 ;
if ( F_172 ( V_2 -> V_57 ) ) {
F_49 () ;
V_49 = & V_2 -> V_49 -> V_36 ;
F_164 ( V_2 -> V_60 , V_2 -> V_58 +
( V_49 - ( void T_1 * ) V_2 -> V_49 ) ,
sizeof V_2 -> V_49 -> V_36 ) ;
if ( V_2 -> V_65 )
F_167 ( V_2 -> V_65 , 1 ) ;
}
return 0 ;
}
static int F_173 ( struct V_1 * V_2 , T_11 V_240 )
{
if ( F_170 ( V_2 , F_171 ( V_2 , V_2 -> V_52 ) ,
F_174 ( V_2 ) ) )
return - V_9 ;
if ( F_172 ( V_2 -> V_57 ) ) {
void T_1 * V_49 ;
F_49 () ;
V_49 = F_174 ( V_2 ) ;
F_164 ( V_2 -> V_60 , V_2 -> V_58 +
( V_49 - ( void T_1 * ) V_2 -> V_49 ) ,
sizeof * F_174 ( V_2 ) ) ;
if ( V_2 -> V_65 )
F_167 ( V_2 -> V_65 , 1 ) ;
}
return 0 ;
}
int F_175 ( struct V_1 * V_2 )
{
T_12 V_53 ;
int V_199 ;
bool V_16 = V_2 -> V_16 ;
if ( ! V_2 -> V_7 )
return 0 ;
F_9 ( V_2 ) ;
V_199 = F_169 ( V_2 ) ;
if ( V_199 )
goto V_99;
V_2 -> V_55 = false ;
if ( ! V_2 -> V_68 &&
! F_96 ( V_156 , & V_2 -> V_49 -> V_14 , sizeof V_2 -> V_49 -> V_14 ) ) {
V_199 = - V_9 ;
goto V_99;
}
V_199 = F_176 ( V_2 , V_53 , & V_2 -> V_49 -> V_14 ) ;
if ( V_199 ) {
F_111 ( V_2 , L_5 ,
& V_2 -> V_49 -> V_14 ) ;
goto V_99;
}
V_2 -> V_53 = F_177 ( V_2 , V_53 ) ;
return 0 ;
V_99:
V_2 -> V_16 = V_16 ;
return V_199 ;
}
static int F_105 ( struct V_1 * V_2 , T_8 V_118 , T_2 V_170 ,
struct V_241 V_242 [] , int V_243 , int V_155 )
{
const struct V_110 * V_45 ;
struct V_38 * V_39 = V_2 -> V_39 ;
struct V_108 * V_67 = V_39 -> V_68 ? V_39 -> V_68 : V_39 -> V_67 ;
struct V_241 * V_244 ;
T_8 V_6 = 0 ;
int V_40 = 0 ;
while ( ( T_8 ) V_170 > V_6 ) {
T_8 V_104 ;
if ( F_172 ( V_40 >= V_243 ) ) {
V_40 = - V_200 ;
break;
}
V_45 = F_122 ( & V_67 -> V_111 ,
V_118 , V_118 + V_170 - 1 ) ;
if ( V_45 == NULL || V_45 -> V_127 > V_118 ) {
if ( V_67 != V_39 -> V_68 ) {
V_40 = - V_9 ;
break;
}
V_40 = - V_162 ;
break;
} else if ( ! ( V_45 -> V_146 & V_155 ) ) {
V_40 = - V_94 ;
break;
}
V_244 = V_242 + V_40 ;
V_104 = V_45 -> V_104 - V_118 + V_45 -> V_127 ;
V_244 -> V_143 = F_166 ( ( T_8 ) V_170 - V_6 , V_104 ) ;
V_244 -> V_144 = ( void T_1 * ) ( unsigned long )
( V_45 -> V_126 + V_118 - V_45 -> V_127 ) ;
V_6 += V_104 ;
V_118 += V_104 ;
++ V_40 ;
}
if ( V_40 == - V_162 )
F_138 ( V_2 , V_118 , V_155 ) ;
return V_40 ;
}
static unsigned F_178 ( struct V_1 * V_2 , struct V_165 * V_47 )
{
unsigned int V_245 ;
if ( ! ( V_47 -> V_36 & F_171 ( V_2 , V_246 ) ) )
return - 1U ;
V_245 = F_177 ( V_2 , V_47 -> V_245 ) ;
F_179 () ;
return V_245 ;
}
static int F_180 ( struct V_1 * V_2 ,
struct V_241 V_242 [] , unsigned int V_243 ,
unsigned int * V_247 , unsigned int * V_248 ,
struct V_237 * log , unsigned int * V_238 ,
struct V_165 * V_77 )
{
struct V_165 V_47 ;
unsigned int V_79 = 0 , V_249 , V_250 = 0 ;
T_2 V_170 = F_181 ( V_2 , V_77 -> V_170 ) ;
struct V_133 V_132 ;
int V_40 , V_155 ;
if ( F_172 ( V_170 % sizeof V_47 ) ) {
F_111 ( V_2 , L_6
L_7 ,
( unsigned long long ) V_170 ,
sizeof V_47 ) ;
return - V_13 ;
}
V_40 = F_105 ( V_2 , F_182 ( V_2 , V_77 -> V_118 ) , V_170 , V_2 -> V_77 ,
V_82 , V_141 ) ;
if ( F_172 ( V_40 < 0 ) ) {
if ( V_40 != - V_162 )
F_111 ( V_2 , L_8 , V_40 ) ;
return V_40 ;
}
F_107 ( & V_132 , V_142 , V_2 -> V_77 , V_40 , V_170 ) ;
F_179 () ;
V_249 = V_170 / sizeof V_47 ;
if ( F_172 ( V_249 > V_251 + 1 ) ) {
F_111 ( V_2 , L_9 ,
V_77 -> V_170 ) ;
return - V_185 ;
}
do {
unsigned V_252 = * V_248 + * V_247 ;
if ( F_172 ( ++ V_250 > V_249 ) ) {
F_111 ( V_2 , L_10
L_11 ,
V_79 , V_249 ) ;
return - V_13 ;
}
if ( F_172 ( ! F_183 ( & V_47 , sizeof( V_47 ) , & V_132 ) ) ) {
F_111 ( V_2 , L_12 ,
V_79 , ( T_10 ) F_182 ( V_2 , V_77 -> V_118 ) + V_79 * sizeof V_47 ) ;
return - V_13 ;
}
if ( F_172 ( V_47 . V_36 & F_171 ( V_2 , V_253 ) ) ) {
F_111 ( V_2 , L_13 ,
V_79 , ( T_10 ) F_182 ( V_2 , V_77 -> V_118 ) + V_79 * sizeof V_47 ) ;
return - V_13 ;
}
if ( V_47 . V_36 & F_171 ( V_2 , V_254 ) )
V_155 = V_137 ;
else
V_155 = V_141 ;
V_40 = F_105 ( V_2 , F_182 ( V_2 , V_47 . V_118 ) ,
F_181 ( V_2 , V_47 . V_170 ) , V_242 + V_252 ,
V_243 - V_252 , V_155 ) ;
if ( F_172 ( V_40 < 0 ) ) {
if ( V_40 != - V_162 )
F_111 ( V_2 , L_14 ,
V_40 , V_79 ) ;
return V_40 ;
}
if ( V_155 == V_137 ) {
* V_248 += V_40 ;
if ( F_172 ( log ) ) {
log [ * V_238 ] . V_118 = F_182 ( V_2 , V_47 . V_118 ) ;
log [ * V_238 ] . V_170 = F_181 ( V_2 , V_47 . V_170 ) ;
++ * V_238 ;
}
} else {
if ( F_172 ( * V_248 ) ) {
F_111 ( V_2 , L_15
L_16 , V_79 ) ;
return - V_13 ;
}
* V_247 += V_40 ;
}
} while ( ( V_79 = F_178 ( V_2 , & V_47 ) ) != - 1 );
return 0 ;
}
int F_184 ( struct V_1 * V_2 ,
struct V_241 V_242 [] , unsigned int V_243 ,
unsigned int * V_247 , unsigned int * V_248 ,
struct V_237 * log , unsigned int * V_238 )
{
struct V_165 V_47 ;
unsigned int V_79 , V_255 , V_250 = 0 ;
T_11 V_50 ;
T_12 V_52 ;
T_12 V_256 ;
int V_40 , V_155 ;
V_50 = V_2 -> V_50 ;
if ( F_172 ( F_176 ( V_2 , V_52 , & V_2 -> V_48 -> V_14 ) ) ) {
F_111 ( V_2 , L_17 ,
& V_2 -> V_48 -> V_14 ) ;
return - V_9 ;
}
V_2 -> V_52 = F_177 ( V_2 , V_52 ) ;
if ( F_172 ( ( T_11 ) ( V_2 -> V_52 - V_50 ) > V_2 -> V_10 ) ) {
F_111 ( V_2 , L_18 ,
V_50 , V_2 -> V_52 ) ;
return - V_9 ;
}
if ( V_2 -> V_52 == V_50 )
return V_2 -> V_10 ;
F_185 () ;
if ( F_172 ( F_176 ( V_2 , V_256 ,
& V_2 -> V_48 -> V_169 [ V_50 & ( V_2 -> V_10 - 1 ) ] ) ) ) {
F_111 ( V_2 , L_19 ,
V_50 ,
& V_2 -> V_48 -> V_169 [ V_50 % V_2 -> V_10 ] ) ;
return - V_9 ;
}
V_255 = F_177 ( V_2 , V_256 ) ;
if ( F_172 ( V_255 >= V_2 -> V_10 ) ) {
F_111 ( V_2 , L_20 ,
V_255 , V_2 -> V_10 ) ;
return - V_13 ;
}
* V_247 = * V_248 = 0 ;
if ( F_172 ( log ) )
* V_238 = 0 ;
V_79 = V_255 ;
do {
unsigned V_252 = * V_248 + * V_247 ;
if ( F_172 ( V_79 >= V_2 -> V_10 ) ) {
F_111 ( V_2 , L_21 ,
V_79 , V_2 -> V_10 , V_255 ) ;
return - V_13 ;
}
if ( F_172 ( ++ V_250 > V_2 -> V_10 ) ) {
F_111 ( V_2 , L_10
L_22 ,
V_79 , V_2 -> V_10 , V_255 ) ;
return - V_13 ;
}
V_40 = F_109 ( V_2 , & V_47 , V_2 -> V_47 + V_79 ,
sizeof V_47 ) ;
if ( F_172 ( V_40 ) ) {
F_111 ( V_2 , L_23 ,
V_79 , V_2 -> V_47 + V_79 ) ;
return - V_9 ;
}
if ( V_47 . V_36 & F_171 ( V_2 , V_253 ) ) {
V_40 = F_180 ( V_2 , V_242 , V_243 ,
V_247 , V_248 ,
log , V_238 , & V_47 ) ;
if ( F_172 ( V_40 < 0 ) ) {
if ( V_40 != - V_162 )
F_111 ( V_2 , L_24
L_25 , V_79 ) ;
return V_40 ;
}
continue;
}
if ( V_47 . V_36 & F_171 ( V_2 , V_254 ) )
V_155 = V_137 ;
else
V_155 = V_141 ;
V_40 = F_105 ( V_2 , F_182 ( V_2 , V_47 . V_118 ) ,
F_181 ( V_2 , V_47 . V_170 ) , V_242 + V_252 ,
V_243 - V_252 , V_155 ) ;
if ( F_172 ( V_40 < 0 ) ) {
if ( V_40 != - V_162 )
F_111 ( V_2 , L_26 ,
V_40 , V_79 ) ;
return V_40 ;
}
if ( V_155 == V_137 ) {
* V_248 += V_40 ;
if ( F_172 ( log ) ) {
log [ * V_238 ] . V_118 = F_182 ( V_2 , V_47 . V_118 ) ;
log [ * V_238 ] . V_170 = F_181 ( V_2 , V_47 . V_170 ) ;
++ * V_238 ;
}
} else {
if ( F_172 ( * V_248 ) ) {
F_111 ( V_2 , L_27
L_28 , V_79 ) ;
return - V_13 ;
}
* V_247 += V_40 ;
}
} while ( ( V_79 = F_178 ( V_2 , & V_47 ) ) != - 1 );
V_2 -> V_50 ++ ;
F_158 ( ! ( V_2 -> V_56 & V_257 ) ) ;
return V_255 ;
}
void F_186 ( struct V_1 * V_2 , int V_105 )
{
V_2 -> V_50 -= V_105 ;
}
int F_187 ( struct V_1 * V_2 , unsigned int V_255 , int V_170 )
{
struct V_258 V_78 = {
F_188 ( V_2 , V_255 ) ,
F_188 (vq, len)
} ;
return F_189 ( V_2 , & V_78 , 1 ) ;
}
static int F_190 ( struct V_1 * V_2 ,
struct V_258 * V_78 ,
unsigned V_249 )
{
struct V_258 T_1 * V_49 ;
T_11 V_259 , V_260 ;
int V_127 ;
V_127 = V_2 -> V_53 & ( V_2 -> V_10 - 1 ) ;
V_49 = V_2 -> V_49 -> V_169 + V_127 ;
if ( V_249 == 1 ) {
if ( F_170 ( V_2 , V_78 [ 0 ] . V_261 , & V_49 -> V_261 ) ) {
F_111 ( V_2 , L_29 ) ;
return - V_9 ;
}
if ( F_170 ( V_2 , V_78 [ 0 ] . V_170 , & V_49 -> V_170 ) ) {
F_111 ( V_2 , L_30 ) ;
return - V_9 ;
}
} else if ( F_103 ( V_2 , V_49 , V_78 , V_249 * sizeof *V_49 ) ) {
F_111 ( V_2 , L_31 ) ;
return - V_9 ;
}
if ( F_172 ( V_2 -> V_57 ) ) {
F_49 () ;
F_164 ( V_2 -> V_60 ,
V_2 -> V_58 +
( ( void T_1 * ) V_49 - ( void T_1 * ) V_2 -> V_49 ) ,
V_249 * sizeof *V_49 ) ;
}
V_259 = V_2 -> V_53 ;
V_260 = ( V_2 -> V_53 += V_249 ) ;
if ( F_172 ( ( T_11 ) ( V_260 - V_2 -> V_54 ) < ( T_11 ) ( V_260 - V_259 ) ) )
V_2 -> V_55 = false ;
return 0 ;
}
int F_189 ( struct V_1 * V_2 , struct V_258 * V_78 ,
unsigned V_249 )
{
int V_127 , V_105 , V_199 ;
V_127 = V_2 -> V_53 & ( V_2 -> V_10 - 1 ) ;
V_105 = V_2 -> V_10 - V_127 ;
if ( V_105 < V_249 ) {
V_199 = F_190 ( V_2 , V_78 , V_105 ) ;
if ( V_199 < 0 )
return V_199 ;
V_78 += V_105 ;
V_249 -= V_105 ;
}
V_199 = F_190 ( V_2 , V_78 , V_249 ) ;
F_49 () ;
if ( F_170 ( V_2 , F_171 ( V_2 , V_2 -> V_53 ) ,
& V_2 -> V_49 -> V_14 ) ) {
F_111 ( V_2 , L_32 ) ;
return - V_9 ;
}
if ( F_172 ( V_2 -> V_57 ) ) {
F_164 ( V_2 -> V_60 ,
V_2 -> V_58 + F_148 ( struct V_167 , V_14 ) ,
sizeof V_2 -> V_49 -> V_14 ) ;
if ( V_2 -> V_65 )
F_167 ( V_2 -> V_65 , 1 ) ;
}
return V_199 ;
}
static bool F_191 ( struct V_38 * V_39 , struct V_1 * V_2 )
{
T_13 V_259 , V_260 ;
T_12 V_262 ;
bool V_263 ;
if ( F_10 ( V_2 , V_264 ) &&
F_172 ( V_2 -> V_52 == V_2 -> V_50 ) )
return true ;
if ( ! F_10 ( V_2 , V_168 ) ) {
T_12 V_36 ;
F_192 () ;
if ( F_176 ( V_2 , V_36 , & V_2 -> V_48 -> V_36 ) ) {
F_111 ( V_2 , L_33 ) ;
return true ;
}
return ! ( V_36 & F_171 ( V_2 , V_265 ) ) ;
}
V_259 = V_2 -> V_54 ;
V_263 = V_2 -> V_55 ;
V_260 = V_2 -> V_54 = V_2 -> V_53 ;
V_2 -> V_55 = true ;
if ( F_172 ( ! V_263 ) )
return true ;
if ( F_193 ( V_2 -> V_51 , V_260 + V_2 -> V_10 , V_260 ) &&
! F_193 ( V_2 -> V_51 , V_260 , V_259 ) )
return false ;
F_192 () ;
if ( F_176 ( V_2 , V_262 , F_194 ( V_2 ) ) ) {
F_111 ( V_2 , L_34 ) ;
return true ;
}
V_2 -> V_51 = F_177 ( V_2 , V_262 ) ;
return F_193 ( V_2 -> V_51 , V_260 , V_259 ) ;
}
void F_195 ( struct V_38 * V_39 , struct V_1 * V_2 )
{
if ( V_2 -> V_63 && F_191 ( V_39 , V_2 ) )
F_167 ( V_2 -> V_63 , 1 ) ;
}
void F_196 ( struct V_38 * V_39 ,
struct V_1 * V_2 ,
unsigned int V_255 , int V_170 )
{
F_187 ( V_2 , V_255 , V_170 ) ;
F_195 ( V_39 , V_2 ) ;
}
void F_197 ( struct V_38 * V_39 ,
struct V_1 * V_2 ,
struct V_258 * V_78 , unsigned V_249 )
{
F_189 ( V_2 , V_78 , V_249 ) ;
F_195 ( V_39 , V_2 ) ;
}
bool F_198 ( struct V_38 * V_39 , struct V_1 * V_2 )
{
T_12 V_52 ;
int V_199 ;
V_199 = F_176 ( V_2 , V_52 , & V_2 -> V_48 -> V_14 ) ;
if ( V_199 )
return false ;
return F_177 ( V_2 , V_52 ) == V_2 -> V_52 ;
}
bool F_199 ( struct V_38 * V_39 , struct V_1 * V_2 )
{
T_12 V_52 ;
int V_199 ;
if ( ! ( V_2 -> V_56 & V_257 ) )
return false ;
V_2 -> V_56 &= ~ V_257 ;
if ( ! F_10 ( V_2 , V_168 ) ) {
V_199 = F_169 ( V_2 ) ;
if ( V_199 ) {
F_111 ( V_2 , L_35 ,
& V_2 -> V_49 -> V_36 , V_199 ) ;
return false ;
}
} else {
V_199 = F_173 ( V_2 , V_2 -> V_52 ) ;
if ( V_199 ) {
F_111 ( V_2 , L_36 ,
F_174 ( V_2 ) , V_199 ) ;
return false ;
}
}
F_192 () ;
V_199 = F_176 ( V_2 , V_52 , & V_2 -> V_48 -> V_14 ) ;
if ( V_199 ) {
F_111 ( V_2 , L_37 ,
& V_2 -> V_48 -> V_14 , V_199 ) ;
return false ;
}
return F_177 ( V_2 , V_52 ) != V_2 -> V_52 ;
}
void F_200 ( struct V_38 * V_39 , struct V_1 * V_2 )
{
int V_199 ;
if ( V_2 -> V_56 & V_257 )
return;
V_2 -> V_56 |= V_257 ;
if ( ! F_10 ( V_2 , V_168 ) ) {
V_199 = F_169 ( V_2 ) ;
if ( V_199 )
F_111 ( V_2 , L_35 ,
& V_2 -> V_49 -> V_36 , V_199 ) ;
}
}
struct V_115 * F_139 ( struct V_1 * V_2 , int type )
{
struct V_115 * V_45 = F_56 ( sizeof *V_45 , V_83 ) ;
if ( ! V_45 )
return NULL ;
V_45 -> V_2 = V_2 ;
V_45 -> V_151 . type = type ;
return V_45 ;
}
void F_137 ( struct V_38 * V_39 , struct V_266 * V_255 ,
struct V_115 * V_45 )
{
F_89 ( & V_39 -> V_90 ) ;
F_119 ( & V_45 -> V_45 , V_255 ) ;
F_90 ( & V_39 -> V_90 ) ;
F_93 ( & V_39 -> V_29 , V_92 | V_117 ) ;
}
struct V_115 * F_134 ( struct V_38 * V_39 ,
struct V_266 * V_255 )
{
struct V_115 * V_45 = NULL ;
F_89 ( & V_39 -> V_90 ) ;
if ( ! F_130 ( V_255 ) ) {
V_45 = F_117 ( V_255 , struct V_115 ,
V_45 ) ;
F_84 ( & V_45 -> V_45 ) ;
}
F_90 ( & V_39 -> V_90 ) ;
return V_45 ;
}
static int T_14 F_201 ( void )
{
return 0 ;
}
static void T_15 F_202 ( void )
{
}
