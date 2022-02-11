static bool F_1 ( void )
{
return ! F_2 ( V_1 ) && V_2 ;
}
struct V_3 * F_3 ( struct V_4 * V_5 )
{
if ( ! V_5 )
V_5 = V_6 ;
return & V_5 -> V_3 ;
}
struct V_7 * F_4 ( struct V_3 * V_8 )
{
return & F_5 ( V_8 , struct V_4 , V_3 ) -> V_9 ;
}
static inline bool F_6 ( struct V_4 * V_5 )
{
return ( V_5 == V_6 ) ;
}
void F_7 ( void )
{
F_8 ( & V_10 ) ;
}
void F_9 ( void )
{
F_10 ( & V_10 ) ;
}
struct V_7 * F_11 ( struct V_11 * V_11 )
{
struct V_4 * V_5 ;
V_5 = V_11 -> V_4 ;
if ( ! V_5 || ! F_2 ( V_1 ) )
V_5 = V_6 ;
return & V_5 -> V_9 ;
}
T_1 F_12 ( struct V_11 * V_11 )
{
struct V_4 * V_5 ;
unsigned long V_12 = 0 ;
F_13 () ;
V_5 = F_14 ( V_11 -> V_4 ) ;
while ( V_5 && ! ( V_5 -> V_9 . V_13 & V_14 ) )
V_5 = F_15 ( V_5 ) ;
if ( V_5 )
V_12 = F_16 ( V_5 -> V_9 . V_15 ) ;
F_17 () ;
return V_12 ;
}
static struct V_16 *
F_18 ( struct V_4 * V_5 , struct V_11 * V_11 )
{
int V_17 = F_19 ( V_11 ) ;
return V_5 -> V_18 [ V_17 ] ;
}
static struct V_19 *
F_20 ( int V_17 )
{
return V_20 . V_21 [ V_17 ] ;
}
static struct V_19 *
F_21 ( struct V_11 * V_11 )
{
int V_17 = F_19 ( V_11 ) ;
return V_20 . V_21 [ V_17 ] ;
}
static void F_22 ( struct V_16 * V_22 ,
struct V_19 * V_23 ,
unsigned long V_24 )
{
struct V_25 * * V_26 = & V_23 -> V_27 . V_25 ;
struct V_25 * V_28 = NULL ;
struct V_16 * V_29 ;
if ( V_22 -> V_30 )
return;
V_22 -> V_31 = V_24 ;
if ( ! V_22 -> V_31 )
return;
while ( * V_26 ) {
V_28 = * V_26 ;
V_29 = F_23 ( V_28 , struct V_16 ,
V_32 ) ;
if ( V_22 -> V_31 < V_29 -> V_31 )
V_26 = & ( * V_26 ) -> V_33 ;
else if ( V_22 -> V_31 >= V_29 -> V_31 )
V_26 = & ( * V_26 ) -> V_34 ;
}
F_24 ( & V_22 -> V_32 , V_28 , V_26 ) ;
F_25 ( & V_22 -> V_32 , & V_23 -> V_27 ) ;
V_22 -> V_30 = true ;
}
static void F_26 ( struct V_16 * V_22 ,
struct V_19 * V_23 )
{
if ( ! V_22 -> V_30 )
return;
F_27 ( & V_22 -> V_32 , & V_23 -> V_27 ) ;
V_22 -> V_30 = false ;
}
static void F_28 ( struct V_16 * V_22 ,
struct V_19 * V_23 )
{
unsigned long V_13 ;
F_29 ( & V_23 -> V_35 , V_13 ) ;
F_26 ( V_22 , V_23 ) ;
F_30 ( & V_23 -> V_35 , V_13 ) ;
}
static unsigned long F_31 ( struct V_4 * V_5 )
{
unsigned long V_36 = F_32 ( & V_5 -> V_37 ) ;
unsigned long V_38 = F_14 ( V_5 -> V_38 ) ;
unsigned long V_39 = 0 ;
if ( V_36 > V_38 )
V_39 = V_36 - V_38 ;
return V_39 ;
}
static void F_33 ( struct V_4 * V_5 , struct V_11 * V_11 )
{
unsigned long V_39 ;
struct V_16 * V_22 ;
struct V_19 * V_23 ;
V_23 = F_21 ( V_11 ) ;
for (; V_5 ; V_5 = F_15 ( V_5 ) ) {
V_22 = F_18 ( V_5 , V_11 ) ;
V_39 = F_31 ( V_5 ) ;
if ( V_39 || V_22 -> V_30 ) {
unsigned long V_13 ;
F_29 ( & V_23 -> V_35 , V_13 ) ;
if ( V_22 -> V_30 )
F_26 ( V_22 , V_23 ) ;
F_22 ( V_22 , V_23 , V_39 ) ;
F_30 ( & V_23 -> V_35 , V_13 ) ;
}
}
}
static void F_34 ( struct V_4 * V_5 )
{
struct V_19 * V_23 ;
struct V_16 * V_22 ;
int V_17 ;
F_35 (nid) {
V_22 = F_36 ( V_5 , V_17 ) ;
V_23 = F_20 ( V_17 ) ;
F_28 ( V_22 , V_23 ) ;
}
}
static struct V_16 *
F_37 ( struct V_19 * V_23 )
{
struct V_25 * V_40 = NULL ;
struct V_16 * V_22 ;
V_41:
V_22 = NULL ;
V_40 = F_38 ( & V_23 -> V_27 ) ;
if ( ! V_40 )
goto V_42;
V_22 = F_23 ( V_40 , struct V_16 , V_32 ) ;
F_26 ( V_22 , V_23 ) ;
if ( ! F_31 ( V_22 -> V_5 ) ||
! F_39 ( & V_22 -> V_5 -> V_9 ) )
goto V_41;
V_42:
return V_22 ;
}
static struct V_16 *
F_40 ( struct V_19 * V_23 )
{
struct V_16 * V_22 ;
F_41 ( & V_23 -> V_35 ) ;
V_22 = F_37 ( V_23 ) ;
F_42 ( & V_23 -> V_35 ) ;
return V_22 ;
}
static unsigned long
F_43 ( struct V_4 * V_5 , enum V_43 V_44 )
{
long V_45 = 0 ;
int V_46 ;
F_44 (cpu)
V_45 += F_45 ( V_5 -> V_47 -> V_48 [ V_44 ] , V_46 ) ;
if ( V_45 < 0 )
V_45 = 0 ;
return V_45 ;
}
static unsigned long F_46 ( struct V_4 * V_5 ,
enum V_49 V_44 )
{
unsigned long V_45 = 0 ;
int V_46 ;
F_44 (cpu)
V_45 += F_45 ( V_5 -> V_47 -> V_50 [ V_44 ] , V_46 ) ;
return V_45 ;
}
static void F_47 ( struct V_4 * V_5 ,
struct V_11 * V_11 ,
bool V_51 , int V_36 )
{
if ( F_48 ( V_11 ) )
F_49 ( V_5 -> V_47 -> V_48 [ V_52 ] ,
V_36 ) ;
else
F_49 ( V_5 -> V_47 -> V_48 [ V_53 ] ,
V_36 ) ;
if ( V_51 ) {
F_50 ( ! F_51 ( V_11 ) , V_11 ) ;
F_49 ( V_5 -> V_47 -> V_48 [ V_54 ] ,
V_36 ) ;
}
if ( V_36 > 0 )
F_52 ( V_5 -> V_47 -> V_50 [ V_55 ] ) ;
else {
F_52 ( V_5 -> V_47 -> V_50 [ V_56 ] ) ;
V_36 = - V_36 ;
}
F_49 ( V_5 -> V_47 -> V_57 , V_36 ) ;
}
unsigned long F_53 ( struct V_4 * V_5 ,
int V_17 , unsigned int V_58 )
{
unsigned long V_59 = 0 ;
struct V_16 * V_22 ;
enum V_60 V_61 ;
F_54 ( ( unsigned ) V_17 >= V_62 ) ;
F_55 (lru) {
if ( ! ( F_56 ( V_61 ) & V_58 ) )
continue;
V_22 = F_36 ( V_5 , V_17 ) ;
V_59 += V_22 -> V_63 [ V_61 ] ;
}
return V_59 ;
}
static unsigned long F_57 ( struct V_4 * V_5 ,
unsigned int V_58 )
{
unsigned long V_59 = 0 ;
int V_17 ;
F_58 (nid, N_MEMORY)
V_59 += F_53 ( V_5 , V_17 , V_58 ) ;
return V_59 ;
}
static bool F_59 ( struct V_4 * V_5 ,
enum V_64 V_65 )
{
unsigned long V_45 , V_66 ;
V_45 = F_60 ( V_5 -> V_47 -> V_57 ) ;
V_66 = F_60 ( V_5 -> V_47 -> V_67 [ V_65 ] ) ;
if ( ( long ) V_66 - ( long ) V_45 < 0 ) {
switch ( V_65 ) {
case V_68 :
V_66 = V_45 + V_69 ;
break;
case V_70 :
V_66 = V_45 + V_71 ;
break;
case V_72 :
V_66 = V_45 + V_73 ;
break;
default:
break;
}
F_61 ( V_5 -> V_47 -> V_67 [ V_65 ] , V_66 ) ;
return true ;
}
return false ;
}
static void F_62 ( struct V_4 * V_5 , struct V_11 * V_11 )
{
if ( F_63 ( F_59 ( V_5 ,
V_68 ) ) ) {
bool V_74 ;
bool T_2 V_75 ;
V_74 = F_59 ( V_5 ,
V_70 ) ;
#if V_76 > 1
T_2 = F_59 ( V_5 ,
V_72 ) ;
#endif
F_64 ( V_5 ) ;
if ( F_63 ( V_74 ) )
F_33 ( V_5 , V_11 ) ;
#if V_76 > 1
if ( F_63 ( T_2 ) )
F_65 ( & V_5 -> V_77 ) ;
#endif
}
}
struct V_4 * F_66 ( struct V_78 * V_26 )
{
if ( F_63 ( ! V_26 ) )
return NULL ;
return F_67 ( F_68 ( V_26 , V_79 ) ) ;
}
static struct V_4 * F_69 ( struct V_80 * V_81 )
{
struct V_4 * V_5 = NULL ;
F_13 () ;
do {
if ( F_63 ( ! V_81 ) )
V_5 = V_6 ;
else {
V_5 = F_66 ( F_70 ( V_81 -> V_82 ) ) ;
if ( F_63 ( ! V_5 ) )
V_5 = V_6 ;
}
} while ( ! F_39 ( & V_5 -> V_9 ) );
F_17 () ;
return V_5 ;
}
struct V_4 * F_71 ( struct V_4 * V_83 ,
struct V_4 * V_84 ,
struct V_85 * V_86 )
{
struct V_87 * V_88 ( V_89 ) ;
struct V_7 * V_9 = NULL ;
struct V_4 * V_5 = NULL ;
struct V_4 * V_90 = NULL ;
if ( F_72 () )
return NULL ;
if ( ! V_83 )
V_83 = V_6 ;
if ( V_84 && ! V_86 )
V_90 = V_84 ;
if ( ! V_83 -> V_91 && V_83 != V_6 ) {
if ( V_84 )
goto V_92;
return V_83 ;
}
F_13 () ;
if ( V_86 ) {
struct V_16 * V_22 ;
V_22 = F_36 ( V_83 , V_86 -> V_93 -> V_94 ) ;
V_89 = & V_22 -> V_89 [ V_86 -> V_95 ] ;
if ( V_84 && V_86 -> V_96 != V_89 -> V_96 )
goto V_97;
while ( 1 ) {
V_90 = F_14 ( V_89 -> V_98 ) ;
if ( ! V_90 || F_73 ( & V_90 -> V_9 ) )
break;
( void ) F_74 ( & V_89 -> V_98 , V_90 , NULL ) ;
}
}
if ( V_90 )
V_9 = & V_90 -> V_9 ;
for (; ; ) {
V_9 = F_75 ( V_9 , & V_83 -> V_9 ) ;
if ( ! V_9 ) {
if ( ! V_84 )
continue;
break;
}
V_5 = F_67 ( V_9 ) ;
if ( V_9 == & V_83 -> V_9 )
break;
if ( F_73 ( V_9 ) )
break;
V_5 = NULL ;
}
if ( V_86 ) {
( void ) F_74 ( & V_89 -> V_98 , V_90 , V_5 ) ;
if ( V_90 )
F_76 ( & V_90 -> V_9 ) ;
if ( ! V_5 )
V_89 -> V_96 ++ ;
else if ( ! V_84 )
V_86 -> V_96 = V_89 -> V_96 ;
}
V_97:
F_17 () ;
V_92:
if ( V_84 && V_84 != V_83 )
F_76 ( & V_84 -> V_9 ) ;
return V_5 ;
}
void F_77 ( struct V_4 * V_83 ,
struct V_4 * V_84 )
{
if ( ! V_83 )
V_83 = V_6 ;
if ( V_84 && V_84 != V_83 )
F_76 ( & V_84 -> V_9 ) ;
}
static void F_78 ( struct V_4 * V_99 )
{
struct V_4 * V_5 = V_99 ;
struct V_87 * V_89 ;
struct V_16 * V_22 ;
int V_17 ;
int V_100 ;
while ( ( V_5 = F_15 ( V_5 ) ) ) {
F_35 (nid) {
V_22 = F_36 ( V_5 , V_17 ) ;
for ( V_100 = 0 ; V_100 <= V_101 ; V_100 ++ ) {
V_89 = & V_22 -> V_89 [ V_100 ] ;
F_74 ( & V_89 -> V_98 ,
V_99 , NULL ) ;
}
}
}
}
int F_79 ( struct V_4 * V_5 ,
int (* F_80)( struct V_78 * , void * ) , void * V_102 )
{
struct V_4 * V_89 ;
int V_103 = 0 ;
F_81 ( V_5 == V_6 ) ;
F_82 (iter, memcg) {
struct V_104 V_105 ;
struct V_78 * V_106 ;
F_83 ( & V_89 -> V_9 , & V_105 ) ;
while ( ! V_103 && ( V_106 = F_84 ( & V_105 ) ) )
V_103 = F_80 ( V_106 , V_102 ) ;
F_85 ( & V_105 ) ;
if ( V_103 ) {
F_77 ( V_5 , V_89 ) ;
break;
}
}
return V_103 ;
}
struct V_107 * F_86 ( struct V_11 * V_11 , struct V_108 * V_93 )
{
struct V_16 * V_22 ;
struct V_4 * V_5 ;
struct V_107 * V_107 ;
if ( F_72 () ) {
V_107 = & V_93 -> V_107 ;
goto V_92;
}
V_5 = V_11 -> V_4 ;
if ( ! V_5 )
V_5 = V_6 ;
V_22 = F_18 ( V_5 , V_11 ) ;
V_107 = & V_22 -> V_107 ;
V_92:
if ( F_63 ( V_107 -> V_93 != V_93 ) )
V_107 -> V_93 = V_93 ;
return V_107 ;
}
void F_87 ( struct V_107 * V_107 , enum V_60 V_61 ,
int V_36 )
{
struct V_16 * V_22 ;
unsigned long * V_63 ;
long V_109 ;
bool V_110 ;
if ( F_72 () )
return;
V_22 = F_5 ( V_107 , struct V_16 , V_107 ) ;
V_63 = V_22 -> V_63 + V_61 ;
V_110 = F_88 ( V_107 -> V_111 + V_61 ) ;
if ( V_36 < 0 )
* V_63 += V_36 ;
V_109 = * V_63 ;
if ( F_89 ( V_109 < 0 || V_110 != ! V_109 ,
L_1 ,
V_112 , V_107 , V_61 , V_36 , V_109 , V_110 ? L_2 : L_3 ) ) {
F_54 ( 1 ) ;
* V_63 = 0 ;
}
if ( V_36 > 0 )
* V_63 += V_36 ;
}
bool F_90 ( struct V_78 * V_106 , struct V_4 * V_5 )
{
struct V_4 * V_113 ;
struct V_78 * V_26 ;
bool V_103 ;
V_26 = F_91 ( V_106 ) ;
if ( V_26 ) {
V_113 = F_69 ( V_26 -> V_81 ) ;
F_92 ( V_26 ) ;
} else {
F_13 () ;
V_113 = F_66 ( V_106 ) ;
F_93 ( & V_113 -> V_9 ) ;
F_17 () ;
}
V_103 = F_94 ( V_113 , V_5 ) ;
F_76 ( & V_113 -> V_9 ) ;
return V_103 ;
}
static unsigned long F_95 ( struct V_4 * V_5 )
{
unsigned long V_114 = 0 ;
unsigned long V_48 ;
unsigned long V_115 ;
V_48 = F_32 ( & V_5 -> V_37 ) ;
V_115 = F_14 ( V_5 -> V_37 . V_115 ) ;
if ( V_48 < V_115 )
V_114 = V_115 - V_48 ;
if ( F_1 () ) {
V_48 = F_32 ( & V_5 -> V_116 ) ;
V_115 = F_14 ( V_5 -> V_116 . V_115 ) ;
if ( V_48 <= V_115 )
V_114 = F_96 ( V_114 , V_115 - V_48 ) ;
else
V_114 = 0 ;
}
return V_114 ;
}
static bool F_97 ( struct V_4 * V_5 )
{
struct V_4 * V_117 ;
struct V_4 * V_118 ;
bool V_103 = false ;
F_98 ( & V_119 . V_35 ) ;
V_117 = V_119 . V_117 ;
V_118 = V_119 . V_118 ;
if ( ! V_117 )
goto V_120;
V_103 = F_94 ( V_117 , V_5 ) ||
F_94 ( V_118 , V_5 ) ;
V_120:
F_99 ( & V_119 . V_35 ) ;
return V_103 ;
}
static bool F_100 ( struct V_4 * V_5 )
{
if ( V_119 . V_121 && V_122 != V_119 . V_121 ) {
if ( F_97 ( V_5 ) ) {
F_101 ( V_123 ) ;
F_102 ( & V_119 . V_124 , & V_123 , V_125 ) ;
if ( V_119 . V_121 )
F_103 () ;
F_104 ( & V_119 . V_124 , & V_123 ) ;
return true ;
}
}
return false ;
}
void F_105 ( struct V_4 * V_5 , struct V_78 * V_26 )
{
struct V_4 * V_89 ;
unsigned int V_100 ;
F_13 () ;
if ( V_26 ) {
F_106 ( L_4 ) ;
F_107 ( F_108 ( V_26 , V_79 ) ) ;
F_109 ( L_5 ) ;
} else {
F_106 ( L_6 ) ;
}
F_107 ( V_5 -> V_9 . V_15 ) ;
F_109 ( L_7 ) ;
F_17 () ;
F_106 ( L_8 ,
F_110 ( ( V_126 ) F_32 ( & V_5 -> V_37 ) ) ,
F_110 ( ( V_126 ) V_5 -> V_37 . V_115 ) , V_5 -> V_37 . V_127 ) ;
F_106 ( L_9 ,
F_110 ( ( V_126 ) F_32 ( & V_5 -> V_116 ) ) ,
F_110 ( ( V_126 ) V_5 -> V_116 . V_115 ) , V_5 -> V_116 . V_127 ) ;
F_106 ( L_10 ,
F_110 ( ( V_126 ) F_32 ( & V_5 -> V_128 ) ) ,
F_110 ( ( V_126 ) V_5 -> V_128 . V_115 ) , V_5 -> V_128 . V_127 ) ;
F_82 (iter, memcg) {
F_106 ( L_11 ) ;
F_107 ( V_89 -> V_9 . V_15 ) ;
F_109 ( L_12 ) ;
for ( V_100 = 0 ; V_100 < V_129 ; V_100 ++ ) {
if ( V_100 == V_130 && ! V_2 )
continue;
F_109 ( L_13 , V_131 [ V_100 ] ,
F_110 ( F_43 ( V_89 , V_100 ) ) ) ;
}
for ( V_100 = 0 ; V_100 < V_132 ; V_100 ++ )
F_109 ( L_13 , V_133 [ V_100 ] ,
F_110 ( F_57 ( V_89 , F_56 ( V_100 ) ) ) ) ;
F_109 ( L_7 ) ;
}
}
static int F_111 ( struct V_4 * V_5 )
{
int V_134 = 0 ;
struct V_4 * V_89 ;
F_82 (iter, memcg)
V_134 ++ ;
return V_134 ;
}
unsigned long F_112 ( struct V_4 * V_5 )
{
unsigned long V_115 ;
V_115 = V_5 -> V_37 . V_115 ;
if ( F_113 ( V_5 ) ) {
unsigned long V_135 ;
unsigned long V_136 ;
V_135 = V_5 -> V_116 . V_115 ;
V_136 = V_5 -> V_137 . V_115 ;
V_136 = F_96 ( V_136 , ( unsigned long ) V_138 ) ;
V_115 = F_96 ( V_115 + V_136 , V_135 ) ;
}
return V_115 ;
}
static bool F_114 ( struct V_4 * V_5 , T_3 V_139 ,
int V_140 )
{
struct V_141 V_142 = {
. V_143 = NULL ,
. V_144 = NULL ,
. V_5 = V_5 ,
. V_139 = V_139 ,
. V_140 = V_140 ,
} ;
bool V_103 ;
F_115 ( & V_145 ) ;
V_103 = F_116 ( & V_142 ) ;
F_117 ( & V_145 ) ;
return V_103 ;
}
static bool F_118 ( struct V_4 * V_5 ,
int V_17 , bool V_146 )
{
if ( F_53 ( V_5 , V_17 , V_147 ) )
return true ;
if ( V_146 || ! V_138 )
return false ;
if ( F_53 ( V_5 , V_17 , V_148 ) )
return true ;
return false ;
}
static void F_119 ( struct V_4 * V_5 )
{
int V_17 ;
if ( ! F_120 ( & V_5 -> V_77 ) )
return;
if ( F_121 ( & V_5 -> V_149 ) > 1 )
return;
V_5 -> V_150 = V_151 [ V_152 ] ;
F_122 (nid, node_states[N_MEMORY]) {
if ( ! F_118 ( V_5 , V_17 , false ) )
F_123 ( V_17 , V_5 -> V_150 ) ;
}
F_124 ( & V_5 -> V_77 , 0 ) ;
F_124 ( & V_5 -> V_149 , 0 ) ;
}
int F_125 ( struct V_4 * V_5 )
{
int V_153 ;
F_119 ( V_5 ) ;
V_153 = V_5 -> V_154 ;
V_153 = F_126 ( V_153 , V_5 -> V_150 ) ;
if ( F_63 ( V_153 == V_76 ) )
V_153 = F_127 () ;
V_5 -> V_154 = V_153 ;
return V_153 ;
}
int F_125 ( struct V_4 * V_5 )
{
return 0 ;
}
static int F_128 ( struct V_4 * V_155 ,
T_4 * V_93 ,
T_3 V_139 ,
unsigned long * V_156 )
{
struct V_4 * V_157 = NULL ;
int V_158 = 0 ;
int V_159 = 0 ;
unsigned long V_39 ;
unsigned long V_160 ;
struct V_85 V_86 = {
. V_93 = V_93 ,
. V_95 = 0 ,
} ;
V_39 = F_31 ( V_155 ) ;
while ( 1 ) {
V_157 = F_71 ( V_155 , V_157 , & V_86 ) ;
if ( ! V_157 ) {
V_159 ++ ;
if ( V_159 >= 2 ) {
if ( ! V_158 )
break;
if ( V_158 >= ( V_39 >> 2 ) ||
( V_159 > V_161 ) )
break;
}
continue;
}
V_158 += F_129 ( V_157 , V_139 , false ,
V_93 , & V_160 ) ;
* V_156 += V_160 ;
if ( ! F_31 ( V_155 ) )
break;
}
F_77 ( V_155 , V_157 ) ;
return V_158 ;
}
static bool F_130 ( struct V_4 * V_5 )
{
struct V_4 * V_89 , * V_162 = NULL ;
F_98 ( & V_163 ) ;
F_82 (iter, memcg) {
if ( V_89 -> V_145 ) {
V_162 = V_89 ;
F_77 ( V_5 , V_89 ) ;
break;
} else
V_89 -> V_145 = true ;
}
if ( V_162 ) {
F_82 (iter, memcg) {
if ( V_89 == V_162 ) {
F_77 ( V_5 , V_89 ) ;
break;
}
V_89 -> V_145 = false ;
}
} else
F_131 ( & V_164 , 0 , 1 , V_165 ) ;
F_99 ( & V_163 ) ;
return ! V_162 ;
}
static void F_132 ( struct V_4 * V_5 )
{
struct V_4 * V_89 ;
F_98 ( & V_163 ) ;
F_133 ( & V_164 , 1 , V_165 ) ;
F_82 (iter, memcg)
V_89 -> V_145 = false ;
F_99 ( & V_163 ) ;
}
static void F_134 ( struct V_4 * V_5 )
{
struct V_4 * V_89 ;
F_98 ( & V_163 ) ;
F_82 (iter, memcg)
V_89 -> V_166 ++ ;
F_99 ( & V_163 ) ;
}
static void F_135 ( struct V_4 * V_5 )
{
struct V_4 * V_89 ;
F_98 ( & V_163 ) ;
F_82 (iter, memcg)
if ( V_89 -> V_166 > 0 )
V_89 -> V_166 -- ;
F_99 ( & V_163 ) ;
}
static int F_136 ( T_5 * V_123 ,
unsigned V_167 , int V_168 , void * V_102 )
{
struct V_4 * V_169 = (struct V_4 * ) V_102 ;
struct V_4 * V_170 ;
struct V_171 * V_171 ;
V_171 = F_5 ( V_123 , struct V_171 , V_123 ) ;
V_170 = V_171 -> V_5 ;
if ( ! F_94 ( V_169 , V_170 ) &&
! F_94 ( V_170 , V_169 ) )
return 0 ;
return F_137 ( V_123 , V_167 , V_168 , V_102 ) ;
}
static void F_138 ( struct V_4 * V_5 )
{
if ( V_5 && V_5 -> V_166 )
F_139 ( & V_172 , V_173 , 0 , V_5 ) ;
}
static void F_140 ( struct V_4 * V_5 , T_3 V_174 , int V_140 )
{
if ( ! V_122 -> V_175 )
return;
F_93 ( & V_5 -> V_9 ) ;
V_122 -> V_176 = V_5 ;
V_122 -> V_177 = V_174 ;
V_122 -> V_178 = V_140 ;
}
bool F_141 ( bool V_179 )
{
struct V_4 * V_5 = V_122 -> V_176 ;
struct V_171 V_180 ;
bool V_181 ;
if ( ! V_5 )
return false ;
if ( ! V_179 )
goto V_182;
V_180 . V_5 = V_5 ;
V_180 . V_123 . V_13 = 0 ;
V_180 . V_123 . V_183 = F_136 ;
V_180 . V_123 . V_184 = V_122 ;
F_142 ( & V_180 . V_123 . V_185 ) ;
F_102 ( & V_172 , & V_180 . V_123 , V_186 ) ;
F_134 ( V_5 ) ;
V_181 = F_130 ( V_5 ) ;
if ( V_181 )
F_143 ( V_5 ) ;
if ( V_181 && ! V_5 -> V_187 ) {
F_135 ( V_5 ) ;
F_104 ( & V_172 , & V_180 . V_123 ) ;
F_114 ( V_5 , V_122 -> V_177 ,
V_122 -> V_178 ) ;
} else {
F_103 () ;
F_135 ( V_5 ) ;
F_104 ( & V_172 , & V_180 . V_123 ) ;
}
if ( V_181 ) {
F_132 ( V_5 ) ;
F_138 ( V_5 ) ;
}
V_182:
V_122 -> V_176 = NULL ;
F_76 ( & V_5 -> V_9 ) ;
return true ;
}
void F_144 ( struct V_11 * V_11 )
{
struct V_4 * V_5 ;
unsigned long V_13 ;
F_13 () ;
if ( F_72 () )
return;
V_188:
V_5 = V_11 -> V_4 ;
if ( F_63 ( ! V_5 ) )
return;
if ( F_120 ( & V_5 -> V_189 ) <= 0 )
return;
F_29 ( & V_5 -> V_190 , V_13 ) ;
if ( V_5 != V_11 -> V_4 ) {
F_30 ( & V_5 -> V_190 , V_13 ) ;
goto V_188;
}
V_5 -> V_191 = V_122 ;
V_5 -> V_192 = V_13 ;
return;
}
void F_145 ( struct V_11 * V_11 )
{
struct V_4 * V_5 = V_11 -> V_4 ;
if ( V_5 && V_5 -> V_191 == V_122 ) {
unsigned long V_13 = V_5 -> V_192 ;
V_5 -> V_191 = NULL ;
V_5 -> V_192 = 0 ;
F_30 ( & V_5 -> V_190 , V_13 ) ;
}
F_17 () ;
}
static bool F_146 ( struct V_4 * V_5 , unsigned int V_36 )
{
struct V_193 * V_194 ;
unsigned long V_13 ;
bool V_103 = false ;
if ( V_36 > V_195 )
return V_103 ;
F_147 ( V_13 ) ;
V_194 = F_148 ( & V_196 ) ;
if ( V_5 == V_194 -> V_197 && V_194 -> V_36 >= V_36 ) {
V_194 -> V_36 -= V_36 ;
V_103 = true ;
}
F_149 ( V_13 ) ;
return V_103 ;
}
static void F_150 ( struct V_193 * V_194 )
{
struct V_4 * V_198 = V_194 -> V_197 ;
if ( V_194 -> V_36 ) {
F_151 ( & V_198 -> V_37 , V_194 -> V_36 ) ;
if ( F_1 () )
F_151 ( & V_198 -> V_116 , V_194 -> V_36 ) ;
F_152 ( & V_198 -> V_9 , V_194 -> V_36 ) ;
V_194 -> V_36 = 0 ;
}
V_194 -> V_197 = NULL ;
}
static void F_153 ( struct V_199 * V_200 )
{
struct V_193 * V_194 ;
unsigned long V_13 ;
F_147 ( V_13 ) ;
V_194 = F_148 ( & V_196 ) ;
F_150 ( V_194 ) ;
F_154 ( V_201 , & V_194 -> V_13 ) ;
F_149 ( V_13 ) ;
}
static void F_155 ( struct V_4 * V_5 , unsigned int V_36 )
{
struct V_193 * V_194 ;
unsigned long V_13 ;
F_147 ( V_13 ) ;
V_194 = F_148 ( & V_196 ) ;
if ( V_194 -> V_197 != V_5 ) {
F_150 ( V_194 ) ;
V_194 -> V_197 = V_5 ;
}
V_194 -> V_36 += V_36 ;
F_149 ( V_13 ) ;
}
static void F_156 ( struct V_4 * V_155 )
{
int V_46 , V_202 ;
if ( ! F_157 ( & V_203 ) )
return;
F_158 () ;
V_202 = F_159 () ;
F_160 (cpu) {
struct V_193 * V_194 = & F_45 ( V_196 , V_46 ) ;
struct V_4 * V_5 ;
V_5 = V_194 -> V_197 ;
if ( ! V_5 || ! V_194 -> V_36 )
continue;
if ( ! F_94 ( V_5 , V_155 ) )
continue;
if ( ! F_161 ( V_201 , & V_194 -> V_13 ) ) {
if ( V_46 == V_202 )
F_153 ( & V_194 -> V_204 ) ;
else
F_162 ( V_46 , & V_194 -> V_204 ) ;
}
}
F_163 () ;
F_164 () ;
F_117 ( & V_203 ) ;
}
static int F_165 ( struct V_205 * V_206 ,
unsigned long V_207 ,
void * V_208 )
{
int V_46 = ( unsigned long ) V_208 ;
struct V_193 * V_194 ;
if ( V_207 == V_209 )
return V_210 ;
if ( V_207 != V_211 && V_207 != V_212 )
return V_210 ;
V_194 = & F_45 ( V_196 , V_46 ) ;
F_150 ( V_194 ) ;
return V_210 ;
}
static void F_166 ( struct V_4 * V_5 ,
unsigned int V_36 ,
T_3 V_139 )
{
do {
if ( F_32 ( & V_5 -> V_37 ) <= V_5 -> V_213 )
continue;
F_167 ( V_5 , V_214 , 1 ) ;
F_168 ( V_5 , V_36 , V_139 , true ) ;
} while ( ( V_5 = F_15 ( V_5 ) ) );
}
static void F_169 ( struct V_199 * V_204 )
{
struct V_4 * V_5 ;
V_5 = F_5 ( V_204 , struct V_4 , V_215 ) ;
F_166 ( V_5 , V_195 , V_216 ) ;
}
void F_170 ( void )
{
unsigned int V_36 = V_122 -> V_217 ;
struct V_4 * V_5 ;
if ( F_171 ( ! V_36 ) )
return;
V_5 = F_69 ( V_122 -> V_81 ) ;
F_166 ( V_5 , V_36 , V_216 ) ;
F_76 ( & V_5 -> V_9 ) ;
V_122 -> V_217 = 0 ;
}
static int F_172 ( struct V_4 * V_5 , T_3 V_139 ,
unsigned int V_36 )
{
unsigned int V_218 = F_173 ( V_195 , V_36 ) ;
int V_219 = V_220 ;
struct V_4 * V_221 ;
struct V_222 * V_223 ;
unsigned long V_224 ;
bool V_225 = true ;
bool V_226 = false ;
if ( F_6 ( V_5 ) )
return 0 ;
V_41:
if ( F_146 ( V_5 , V_36 ) )
return 0 ;
if ( ! F_1 () ||
F_174 ( & V_5 -> V_116 , V_218 , & V_223 ) ) {
if ( F_174 ( & V_5 -> V_37 , V_218 , & V_223 ) )
goto V_227;
if ( F_1 () )
F_151 ( & V_5 -> V_116 , V_218 ) ;
V_221 = F_175 ( V_223 , V_37 ) ;
} else {
V_221 = F_175 ( V_223 , V_116 ) ;
V_225 = false ;
}
if ( V_218 > V_36 ) {
V_218 = V_36 ;
goto V_41;
}
if ( F_63 ( F_176 ( V_228 ) ||
F_177 ( V_122 ) ||
V_122 -> V_13 & V_229 ) )
goto V_230;
if ( F_63 ( V_122 -> V_13 & V_231 ) )
goto V_230;
if ( F_63 ( F_178 ( V_122 ) ) )
goto V_232;
if ( ! F_179 ( V_139 ) )
goto V_232;
F_167 ( V_221 , V_233 , 1 ) ;
V_224 = F_168 ( V_221 , V_36 ,
V_139 , V_225 ) ;
if ( F_95 ( V_221 ) >= V_36 )
goto V_41;
if ( ! V_226 ) {
F_156 ( V_221 ) ;
V_226 = true ;
goto V_41;
}
if ( V_139 & V_234 )
goto V_232;
if ( V_224 && V_36 <= ( 1 << V_235 ) )
goto V_41;
if ( F_100 ( V_221 ) )
goto V_41;
if ( V_219 -- )
goto V_41;
if ( V_139 & V_236 )
goto V_230;
if ( F_177 ( V_122 ) )
goto V_230;
F_167 ( V_221 , V_237 , 1 ) ;
F_140 ( V_221 , V_139 ,
F_180 ( V_36 * V_238 ) ) ;
V_232:
if ( ! ( V_139 & V_236 ) )
return - V_239 ;
V_230:
F_181 ( & V_5 -> V_37 , V_36 ) ;
if ( F_1 () )
F_181 ( & V_5 -> V_116 , V_36 ) ;
F_182 ( & V_5 -> V_9 , V_36 ) ;
return 0 ;
V_227:
F_182 ( & V_5 -> V_9 , V_218 ) ;
if ( V_218 > V_36 )
F_155 ( V_5 , V_218 - V_36 ) ;
do {
if ( F_32 ( & V_5 -> V_37 ) > V_5 -> V_213 ) {
if ( F_183 () ) {
F_184 ( & V_5 -> V_215 ) ;
break;
}
V_122 -> V_217 += V_218 ;
F_185 ( V_122 ) ;
break;
}
} while ( ( V_5 = F_15 ( V_5 ) ) );
return 0 ;
}
static void F_186 ( struct V_4 * V_5 , unsigned int V_36 )
{
if ( F_6 ( V_5 ) )
return;
F_151 ( & V_5 -> V_37 , V_36 ) ;
if ( F_1 () )
F_151 ( & V_5 -> V_116 , V_36 ) ;
F_152 ( & V_5 -> V_9 , V_36 ) ;
}
static void F_187 ( struct V_11 * V_11 , int * V_240 )
{
struct V_241 * V_241 = F_188 ( V_11 ) ;
F_41 ( F_189 ( V_241 ) ) ;
if ( F_190 ( V_11 ) ) {
struct V_107 * V_107 ;
V_107 = F_86 ( V_11 , V_241 -> V_242 ) ;
F_191 ( V_11 ) ;
F_192 ( V_11 , V_107 , F_193 ( V_11 ) ) ;
* V_240 = 1 ;
} else
* V_240 = 0 ;
}
static void F_194 ( struct V_11 * V_11 , int V_240 )
{
struct V_241 * V_241 = F_188 ( V_11 ) ;
if ( V_240 ) {
struct V_107 * V_107 ;
V_107 = F_86 ( V_11 , V_241 -> V_242 ) ;
F_50 ( F_190 ( V_11 ) , V_11 ) ;
F_195 ( V_11 ) ;
F_196 ( V_11 , V_107 , F_193 ( V_11 ) ) ;
}
F_42 ( F_189 ( V_241 ) ) ;
}
static void F_197 ( struct V_11 * V_11 , struct V_4 * V_5 ,
bool V_243 )
{
int V_240 ;
F_50 ( V_11 -> V_4 , V_11 ) ;
if ( V_243 )
F_187 ( V_11 , & V_240 ) ;
V_11 -> V_4 = V_5 ;
if ( V_243 )
F_194 ( V_11 , V_240 ) ;
}
static int F_198 ( void )
{
int V_244 , V_109 ;
int V_245 ;
V_244 = F_199 ( & V_246 ,
0 , V_247 , V_216 ) ;
if ( V_244 < 0 )
return V_244 ;
if ( V_244 < V_248 )
return V_244 ;
F_200 ( & V_10 ) ;
V_109 = 2 * ( V_244 + 1 ) ;
if ( V_109 < V_249 )
V_109 = V_249 ;
else if ( V_109 > V_247 )
V_109 = V_247 ;
V_245 = F_201 ( V_109 ) ;
if ( ! V_245 )
V_245 = F_202 ( V_109 ) ;
if ( ! V_245 )
V_248 = V_109 ;
F_203 ( & V_10 ) ;
if ( V_245 ) {
F_204 ( & V_246 , V_244 ) ;
return V_245 ;
}
return V_244 ;
}
static void F_205 ( int V_244 )
{
F_204 ( & V_246 , V_244 ) ;
}
static void F_206 ( struct V_199 * V_250 )
{
struct V_251 * V_252 =
F_5 ( V_250 , struct V_251 , V_204 ) ;
struct V_4 * V_5 = V_252 -> V_5 ;
struct V_253 * V_254 = V_252 -> V_254 ;
F_207 ( V_5 , V_254 ) ;
F_76 ( & V_5 -> V_9 ) ;
F_208 ( V_252 ) ;
}
static void F_209 ( struct V_4 * V_5 ,
struct V_253 * V_254 )
{
struct V_251 * V_252 ;
V_252 = F_210 ( sizeof( * V_252 ) , V_255 ) ;
if ( ! V_252 )
return;
F_93 ( & V_5 -> V_9 ) ;
V_252 -> V_5 = V_5 ;
V_252 -> V_254 = V_254 ;
F_211 ( & V_252 -> V_204 , F_206 ) ;
F_184 ( & V_252 -> V_204 ) ;
}
static void F_212 ( struct V_4 * V_5 ,
struct V_253 * V_254 )
{
V_122 -> V_256 = 1 ;
F_209 ( V_5 , V_254 ) ;
V_122 -> V_256 = 0 ;
}
static inline bool F_213 ( void )
{
if ( F_183 () || ! V_122 -> V_81 || ( V_122 -> V_13 & V_257 ) )
return true ;
return false ;
}
struct V_253 * F_214 ( struct V_253 * V_254 )
{
struct V_4 * V_5 ;
struct V_253 * V_258 ;
int V_259 ;
F_54 ( ! F_215 ( V_254 ) ) ;
if ( F_213 () )
return V_254 ;
if ( V_122 -> V_256 )
return V_254 ;
V_5 = F_69 ( V_122 -> V_81 ) ;
V_259 = F_14 ( V_5 -> V_259 ) ;
if ( V_259 < 0 )
goto V_92;
V_258 = F_216 ( V_254 , V_259 ) ;
if ( F_171 ( V_258 ) )
return V_258 ;
F_212 ( V_5 , V_254 ) ;
V_92:
F_76 ( & V_5 -> V_9 ) ;
return V_254 ;
}
void F_217 ( struct V_253 * V_254 )
{
if ( ! F_215 ( V_254 ) )
F_76 ( & V_254 -> V_260 . V_5 -> V_9 ) ;
}
int F_218 ( struct V_11 * V_11 , T_3 V_261 , int V_140 ,
struct V_4 * V_5 )
{
unsigned int V_36 = 1 << V_140 ;
struct V_222 * V_223 ;
int V_103 ;
V_103 = F_172 ( V_5 , V_261 , V_36 ) ;
if ( V_103 )
return V_103 ;
if ( ! F_2 ( V_1 ) &&
! F_174 ( & V_5 -> V_128 , V_36 , & V_223 ) ) {
F_186 ( V_5 , V_36 ) ;
return - V_239 ;
}
V_11 -> V_4 = V_5 ;
return 0 ;
}
int F_219 ( struct V_11 * V_11 , T_3 V_261 , int V_140 )
{
struct V_4 * V_5 ;
int V_103 = 0 ;
if ( F_213 () )
return 0 ;
V_5 = F_69 ( V_122 -> V_81 ) ;
if ( ! F_6 ( V_5 ) ) {
V_103 = F_218 ( V_11 , V_261 , V_140 , V_5 ) ;
if ( ! V_103 )
F_220 ( V_11 ) ;
}
F_76 ( & V_5 -> V_9 ) ;
return V_103 ;
}
void F_221 ( struct V_11 * V_11 , int V_140 )
{
struct V_4 * V_5 = V_11 -> V_4 ;
unsigned int V_36 = 1 << V_140 ;
if ( ! V_5 )
return;
F_50 ( F_6 ( V_5 ) , V_11 ) ;
if ( ! F_2 ( V_1 ) )
F_151 ( & V_5 -> V_128 , V_36 ) ;
F_151 ( & V_5 -> V_37 , V_36 ) ;
if ( F_1 () )
F_151 ( & V_5 -> V_116 , V_36 ) ;
V_11 -> V_4 = NULL ;
if ( F_222 ( V_11 ) )
F_223 ( V_11 ) ;
F_152 ( & V_5 -> V_9 , V_36 ) ;
}
void F_224 ( struct V_11 * V_262 )
{
int V_100 ;
if ( F_72 () )
return;
for ( V_100 = 1 ; V_100 < V_263 ; V_100 ++ )
V_262 [ V_100 ] . V_4 = V_262 -> V_4 ;
F_225 ( V_262 -> V_4 -> V_47 -> V_48 [ V_54 ] ,
V_263 ) ;
}
static void F_226 ( struct V_4 * V_5 ,
bool V_264 )
{
int V_45 = ( V_264 ) ? 1 : - 1 ;
F_227 ( V_5 -> V_47 -> V_48 [ V_130 ] , V_45 ) ;
}
static int F_228 ( T_6 V_265 ,
struct V_4 * V_117 , struct V_4 * V_118 )
{
unsigned short V_266 , V_267 ;
V_266 = F_229 ( V_117 ) ;
V_267 = F_229 ( V_118 ) ;
if ( F_230 ( V_265 , V_266 , V_267 ) == V_266 ) {
F_226 ( V_117 , false ) ;
F_226 ( V_118 , true ) ;
return 0 ;
}
return - V_268 ;
}
static inline int F_228 ( T_6 V_265 ,
struct V_4 * V_117 , struct V_4 * V_118 )
{
return - V_268 ;
}
static int F_231 ( struct V_4 * V_5 ,
unsigned long V_115 )
{
unsigned long V_269 ;
unsigned long V_270 ;
bool V_271 = false ;
int V_272 ;
int V_103 ;
V_272 = V_220 *
F_111 ( V_5 ) ;
V_270 = F_32 ( & V_5 -> V_37 ) ;
do {
if ( F_232 ( V_122 ) ) {
V_103 = - V_273 ;
break;
}
F_115 ( & V_274 ) ;
if ( V_115 > V_5 -> V_116 . V_115 ) {
F_117 ( & V_274 ) ;
V_103 = - V_268 ;
break;
}
if ( V_115 > V_5 -> V_37 . V_115 )
V_271 = true ;
V_103 = F_233 ( & V_5 -> V_37 , V_115 ) ;
F_117 ( & V_274 ) ;
if ( ! V_103 )
break;
F_168 ( V_5 , 1 , V_216 , true ) ;
V_269 = F_32 ( & V_5 -> V_37 ) ;
if ( V_269 >= V_270 )
V_272 -- ;
else
V_270 = V_269 ;
} while ( V_272 );
if ( ! V_103 && V_271 )
F_138 ( V_5 ) ;
return V_103 ;
}
static int F_234 ( struct V_4 * V_5 ,
unsigned long V_115 )
{
unsigned long V_269 ;
unsigned long V_270 ;
bool V_271 = false ;
int V_272 ;
int V_103 ;
V_272 = V_220 *
F_111 ( V_5 ) ;
V_270 = F_32 ( & V_5 -> V_116 ) ;
do {
if ( F_232 ( V_122 ) ) {
V_103 = - V_273 ;
break;
}
F_115 ( & V_274 ) ;
if ( V_115 < V_5 -> V_37 . V_115 ) {
F_117 ( & V_274 ) ;
V_103 = - V_268 ;
break;
}
if ( V_115 > V_5 -> V_116 . V_115 )
V_271 = true ;
V_103 = F_233 ( & V_5 -> V_116 , V_115 ) ;
F_117 ( & V_274 ) ;
if ( ! V_103 )
break;
F_168 ( V_5 , 1 , V_216 , false ) ;
V_269 = F_32 ( & V_5 -> V_116 ) ;
if ( V_269 >= V_270 )
V_272 -- ;
else
V_270 = V_269 ;
} while ( V_272 );
if ( ! V_103 && V_271 )
F_138 ( V_5 ) ;
return V_103 ;
}
unsigned long F_235 ( T_4 * V_93 , int V_140 ,
T_3 V_139 ,
unsigned long * V_156 )
{
unsigned long V_224 = 0 ;
struct V_16 * V_22 , * V_275 = NULL ;
unsigned long V_276 ;
int V_159 = 0 ;
struct V_19 * V_23 ;
unsigned long V_39 ;
unsigned long V_160 ;
if ( V_140 > 0 )
return 0 ;
V_23 = F_20 ( V_93 -> V_94 ) ;
if ( F_236 ( & V_23 -> V_27 ) )
return 0 ;
do {
if ( V_275 )
V_22 = V_275 ;
else
V_22 = F_40 ( V_23 ) ;
if ( ! V_22 )
break;
V_160 = 0 ;
V_276 = F_128 ( V_22 -> V_5 , V_93 ,
V_139 , & V_160 ) ;
V_224 += V_276 ;
* V_156 += V_160 ;
F_41 ( & V_23 -> V_35 ) ;
F_26 ( V_22 , V_23 ) ;
V_275 = NULL ;
if ( ! V_276 )
V_275 = F_37 ( V_23 ) ;
V_39 = F_31 ( V_22 -> V_5 ) ;
F_22 ( V_22 , V_23 , V_39 ) ;
F_42 ( & V_23 -> V_35 ) ;
F_76 ( & V_22 -> V_5 -> V_9 ) ;
V_159 ++ ;
if ( ! V_224 &&
( V_275 == NULL ||
V_159 > V_277 ) )
break;
} while ( ! V_224 );
if ( V_275 )
F_76 ( & V_275 -> V_5 -> V_9 ) ;
return V_224 ;
}
static inline bool F_237 ( struct V_4 * V_5 )
{
bool V_103 ;
F_13 () ;
V_103 = F_238 ( NULL , & V_5 -> V_9 ) ;
F_17 () ;
return V_103 ;
}
static int F_239 ( struct V_4 * V_5 )
{
int V_219 = V_220 ;
F_240 () ;
while ( V_219 && F_32 ( & V_5 -> V_37 ) ) {
int V_278 ;
if ( F_232 ( V_122 ) )
return - V_273 ;
V_278 = F_168 ( V_5 , 1 ,
V_216 , true ) ;
if ( ! V_278 ) {
V_219 -- ;
F_241 ( V_279 , V_280 / 10 ) ;
}
}
return 0 ;
}
static T_7 F_242 ( struct V_281 * V_282 ,
char * V_283 , T_8 V_284 ,
T_9 V_285 )
{
struct V_4 * V_5 = F_67 ( F_243 ( V_282 ) ) ;
if ( F_6 ( V_5 ) )
return - V_268 ;
return F_239 ( V_5 ) ? : V_284 ;
}
static V_126 F_244 ( struct V_7 * V_9 ,
struct V_286 * V_287 )
{
return F_67 ( V_9 ) -> V_91 ;
}
static int F_245 ( struct V_7 * V_9 ,
struct V_286 * V_287 , V_126 V_45 )
{
int V_288 = 0 ;
struct V_4 * V_5 = F_67 ( V_9 ) ;
struct V_4 * V_289 = F_67 ( V_5 -> V_9 . V_28 ) ;
if ( V_5 -> V_91 == V_45 )
return 0 ;
if ( ( ! V_289 || ! V_289 -> V_91 ) &&
( V_45 == 1 || V_45 == 0 ) ) {
if ( ! F_237 ( V_5 ) )
V_5 -> V_91 = V_45 ;
else
V_288 = - V_290 ;
} else
V_288 = - V_268 ;
return V_288 ;
}
static void F_246 ( struct V_4 * V_5 , unsigned long * V_47 )
{
struct V_4 * V_89 ;
int V_100 ;
memset ( V_47 , 0 , sizeof( * V_47 ) * V_291 ) ;
F_82 (iter, memcg) {
for ( V_100 = 0 ; V_100 < V_291 ; V_100 ++ )
V_47 [ V_100 ] += F_43 ( V_89 , V_100 ) ;
}
}
static void F_247 ( struct V_4 * V_5 , unsigned long * V_50 )
{
struct V_4 * V_89 ;
int V_100 ;
memset ( V_50 , 0 , sizeof( * V_50 ) * V_292 ) ;
F_82 (iter, memcg) {
for ( V_100 = 0 ; V_100 < V_292 ; V_100 ++ )
V_50 [ V_100 ] += F_46 ( V_89 , V_100 ) ;
}
}
static unsigned long F_248 ( struct V_4 * V_5 , bool V_137 )
{
unsigned long V_45 = 0 ;
if ( F_6 ( V_5 ) ) {
struct V_4 * V_89 ;
F_82 (iter, memcg) {
V_45 += F_43 ( V_89 ,
V_53 ) ;
V_45 += F_43 ( V_89 ,
V_52 ) ;
if ( V_137 )
V_45 += F_43 ( V_89 ,
V_130 ) ;
}
} else {
if ( ! V_137 )
V_45 = F_32 ( & V_5 -> V_37 ) ;
else
V_45 = F_32 ( & V_5 -> V_116 ) ;
}
return V_45 ;
}
static V_126 F_249 ( struct V_7 * V_9 ,
struct V_286 * V_287 )
{
struct V_4 * V_5 = F_67 ( V_9 ) ;
struct V_222 * V_223 ;
switch ( F_250 ( V_287 -> V_184 ) ) {
case V_293 :
V_223 = & V_5 -> V_37 ;
break;
case V_294 :
V_223 = & V_5 -> V_116 ;
break;
case V_295 :
V_223 = & V_5 -> V_128 ;
break;
case V_296 :
V_223 = & V_5 -> V_297 ;
break;
default:
F_251 () ;
}
switch ( F_252 ( V_287 -> V_184 ) ) {
case V_298 :
if ( V_223 == & V_5 -> V_37 )
return ( V_126 ) F_248 ( V_5 , false ) * V_238 ;
if ( V_223 == & V_5 -> V_116 )
return ( V_126 ) F_248 ( V_5 , true ) * V_238 ;
return ( V_126 ) F_32 ( V_223 ) * V_238 ;
case V_299 :
return ( V_126 ) V_223 -> V_115 * V_238 ;
case V_300 :
return ( V_126 ) V_223 -> V_301 * V_238 ;
case V_302 :
return V_223 -> V_127 ;
case V_303 :
return ( V_126 ) V_5 -> V_38 * V_238 ;
default:
F_251 () ;
}
}
static int F_253 ( struct V_4 * V_5 )
{
int V_304 ;
if ( V_305 )
return 0 ;
F_81 ( V_5 -> V_259 >= 0 ) ;
F_81 ( V_5 -> V_306 ) ;
V_304 = F_198 () ;
if ( V_304 < 0 )
return V_304 ;
F_254 ( & V_307 ) ;
V_5 -> V_259 = V_304 ;
V_5 -> V_306 = V_308 ;
return 0 ;
}
static void F_255 ( struct V_4 * V_5 )
{
struct V_7 * V_9 ;
struct V_4 * V_28 , * V_309 ;
int V_259 ;
if ( V_5 -> V_306 != V_308 )
return;
V_5 -> V_306 = V_310 ;
F_256 ( V_5 ) ;
V_259 = V_5 -> V_259 ;
F_81 ( V_259 < 0 ) ;
V_28 = F_15 ( V_5 ) ;
if ( ! V_28 )
V_28 = V_6 ;
F_13 () ;
F_257 (css, &memcg->css) {
V_309 = F_67 ( V_9 ) ;
F_81 ( V_309 -> V_259 != V_259 ) ;
V_309 -> V_259 = V_28 -> V_259 ;
if ( ! V_5 -> V_91 )
break;
}
F_17 () ;
F_258 ( V_259 , V_28 -> V_259 ) ;
F_205 ( V_259 ) ;
}
static void F_259 ( struct V_4 * V_5 )
{
if ( F_63 ( V_5 -> V_306 == V_308 ) )
F_255 ( V_5 ) ;
if ( V_5 -> V_306 == V_310 ) {
F_260 ( V_5 ) ;
F_261 ( & V_307 ) ;
F_262 ( F_32 ( & V_5 -> V_128 ) ) ;
}
}
static int F_253 ( struct V_4 * V_5 )
{
return 0 ;
}
static void F_255 ( struct V_4 * V_5 )
{
}
static void F_259 ( struct V_4 * V_5 )
{
}
static int F_263 ( struct V_4 * V_5 ,
unsigned long V_115 )
{
int V_103 ;
F_115 ( & V_274 ) ;
V_103 = F_233 ( & V_5 -> V_128 , V_115 ) ;
F_117 ( & V_274 ) ;
return V_103 ;
}
static int F_264 ( struct V_4 * V_5 , unsigned long V_115 )
{
int V_103 ;
F_115 ( & V_274 ) ;
V_103 = F_233 ( & V_5 -> V_297 , V_115 ) ;
if ( V_103 )
goto V_92;
if ( ! V_5 -> V_311 ) {
F_254 ( & V_312 ) ;
V_5 -> V_311 = true ;
}
V_92:
F_117 ( & V_274 ) ;
return V_103 ;
}
static T_7 F_265 ( struct V_281 * V_282 ,
char * V_283 , T_8 V_284 , T_9 V_285 )
{
struct V_4 * V_5 = F_67 ( F_243 ( V_282 ) ) ;
unsigned long V_36 ;
int V_103 ;
V_283 = F_266 ( V_283 ) ;
V_103 = F_267 ( V_283 , L_14 , & V_36 ) ;
if ( V_103 )
return V_103 ;
switch ( F_252 ( F_268 ( V_282 ) -> V_184 ) ) {
case V_299 :
if ( F_6 ( V_5 ) ) {
V_103 = - V_268 ;
break;
}
switch ( F_250 ( F_268 ( V_282 ) -> V_184 ) ) {
case V_293 :
V_103 = F_231 ( V_5 , V_36 ) ;
break;
case V_294 :
V_103 = F_234 ( V_5 , V_36 ) ;
break;
case V_295 :
V_103 = F_263 ( V_5 , V_36 ) ;
break;
case V_296 :
V_103 = F_264 ( V_5 , V_36 ) ;
break;
}
break;
case V_303 :
V_5 -> V_38 = V_36 ;
V_103 = 0 ;
break;
}
return V_103 ? : V_284 ;
}
static T_7 F_269 ( struct V_281 * V_282 , char * V_283 ,
T_8 V_284 , T_9 V_285 )
{
struct V_4 * V_5 = F_67 ( F_243 ( V_282 ) ) ;
struct V_222 * V_223 ;
switch ( F_250 ( F_268 ( V_282 ) -> V_184 ) ) {
case V_293 :
V_223 = & V_5 -> V_37 ;
break;
case V_294 :
V_223 = & V_5 -> V_116 ;
break;
case V_295 :
V_223 = & V_5 -> V_128 ;
break;
case V_296 :
V_223 = & V_5 -> V_297 ;
break;
default:
F_251 () ;
}
switch ( F_252 ( F_268 ( V_282 ) -> V_184 ) ) {
case V_300 :
F_270 ( V_223 ) ;
break;
case V_302 :
V_223 -> V_127 = 0 ;
break;
default:
F_251 () ;
}
return V_284 ;
}
static V_126 F_271 ( struct V_7 * V_9 ,
struct V_286 * V_287 )
{
return F_67 ( V_9 ) -> V_313 ;
}
static int F_272 ( struct V_7 * V_9 ,
struct V_286 * V_287 , V_126 V_45 )
{
struct V_4 * V_5 = F_67 ( V_9 ) ;
if ( V_45 & ~ V_314 )
return - V_268 ;
V_5 -> V_313 = V_45 ;
return 0 ;
}
static int F_272 ( struct V_7 * V_9 ,
struct V_286 * V_287 , V_126 V_45 )
{
return - V_315 ;
}
static int F_273 ( struct V_316 * V_317 , void * V_318 )
{
struct V_319 {
const char * V_320 ;
unsigned int V_58 ;
};
static const struct V_319 V_321 [] = {
{ L_15 , V_322 } ,
{ L_16 , V_147 } ,
{ L_17 , V_148 } ,
{ L_18 , F_56 (LRU_UNEVICTABLE) } ,
} ;
const struct V_319 * V_47 ;
int V_17 ;
unsigned long V_59 ;
struct V_4 * V_5 = F_67 ( F_274 ( V_317 ) ) ;
for ( V_47 = V_321 ; V_47 < V_321 + F_275 ( V_321 ) ; V_47 ++ ) {
V_59 = F_57 ( V_5 , V_47 -> V_58 ) ;
F_276 ( V_317 , L_19 , V_47 -> V_320 , V_59 ) ;
F_58 (nid, N_MEMORY) {
V_59 = F_53 ( V_5 , V_17 ,
V_47 -> V_58 ) ;
F_276 ( V_317 , L_20 , V_17 , V_59 ) ;
}
F_277 ( V_317 , '\n' ) ;
}
for ( V_47 = V_321 ; V_47 < V_321 + F_275 ( V_321 ) ; V_47 ++ ) {
struct V_4 * V_89 ;
V_59 = 0 ;
F_82 (iter, memcg)
V_59 += F_57 ( V_89 , V_47 -> V_58 ) ;
F_276 ( V_317 , L_21 , V_47 -> V_320 , V_59 ) ;
F_58 (nid, N_MEMORY) {
V_59 = 0 ;
F_82 (iter, memcg)
V_59 += F_53 (
V_89 , V_17 , V_47 -> V_58 ) ;
F_276 ( V_317 , L_20 , V_17 , V_59 ) ;
}
F_277 ( V_317 , '\n' ) ;
}
return 0 ;
}
static int F_278 ( struct V_316 * V_317 , void * V_318 )
{
struct V_4 * V_5 = F_67 ( F_274 ( V_317 ) ) ;
unsigned long V_37 , V_116 ;
struct V_4 * V_323 ;
unsigned int V_100 ;
F_279 ( F_275 ( V_131 ) !=
V_129 ) ;
F_279 ( F_275 ( V_324 ) !=
V_325 ) ;
F_279 ( F_275 ( V_133 ) != V_132 ) ;
for ( V_100 = 0 ; V_100 < V_129 ; V_100 ++ ) {
if ( V_100 == V_130 && ! F_1 () )
continue;
F_276 ( V_317 , L_22 , V_131 [ V_100 ] ,
F_43 ( V_5 , V_100 ) * V_238 ) ;
}
for ( V_100 = 0 ; V_100 < V_325 ; V_100 ++ )
F_276 ( V_317 , L_22 , V_324 [ V_100 ] ,
F_46 ( V_5 , V_100 ) ) ;
for ( V_100 = 0 ; V_100 < V_132 ; V_100 ++ )
F_276 ( V_317 , L_22 , V_133 [ V_100 ] ,
F_57 ( V_5 , F_56 ( V_100 ) ) * V_238 ) ;
V_37 = V_116 = V_326 ;
for ( V_323 = V_5 ; V_323 ; V_323 = F_15 ( V_323 ) ) {
V_37 = F_96 ( V_37 , V_323 -> V_37 . V_115 ) ;
V_116 = F_96 ( V_116 , V_323 -> V_116 . V_115 ) ;
}
F_276 ( V_317 , L_23 ,
( V_126 ) V_37 * V_238 ) ;
if ( F_1 () )
F_276 ( V_317 , L_24 ,
( V_126 ) V_116 * V_238 ) ;
for ( V_100 = 0 ; V_100 < V_129 ; V_100 ++ ) {
unsigned long long V_45 = 0 ;
if ( V_100 == V_130 && ! F_1 () )
continue;
F_82 (mi, memcg)
V_45 += F_43 ( V_323 , V_100 ) * V_238 ;
F_276 ( V_317 , L_25 , V_131 [ V_100 ] , V_45 ) ;
}
for ( V_100 = 0 ; V_100 < V_325 ; V_100 ++ ) {
unsigned long long V_45 = 0 ;
F_82 (mi, memcg)
V_45 += F_46 ( V_323 , V_100 ) ;
F_276 ( V_317 , L_25 ,
V_324 [ V_100 ] , V_45 ) ;
}
for ( V_100 = 0 ; V_100 < V_132 ; V_100 ++ ) {
unsigned long long V_45 = 0 ;
F_82 (mi, memcg)
V_45 += F_57 ( V_323 , F_56 ( V_100 ) ) * V_238 ;
F_276 ( V_317 , L_25 , V_133 [ V_100 ] , V_45 ) ;
}
#ifdef F_280
{
T_4 * V_93 ;
struct V_16 * V_22 ;
struct V_327 * V_328 ;
unsigned long V_329 [ 2 ] = { 0 , 0 } ;
unsigned long V_330 [ 2 ] = { 0 , 0 } ;
F_281 (pgdat) {
V_22 = F_36 ( V_5 , V_93 -> V_94 ) ;
V_328 = & V_22 -> V_107 . V_331 ;
V_329 [ 0 ] += V_328 -> V_329 [ 0 ] ;
V_329 [ 1 ] += V_328 -> V_329 [ 1 ] ;
V_330 [ 0 ] += V_328 -> V_330 [ 0 ] ;
V_330 [ 1 ] += V_328 -> V_330 [ 1 ] ;
}
F_276 ( V_317 , L_26 , V_329 [ 0 ] ) ;
F_276 ( V_317 , L_27 , V_329 [ 1 ] ) ;
F_276 ( V_317 , L_28 , V_330 [ 0 ] ) ;
F_276 ( V_317 , L_29 , V_330 [ 1 ] ) ;
}
#endif
return 0 ;
}
static V_126 F_282 ( struct V_7 * V_9 ,
struct V_286 * V_287 )
{
struct V_4 * V_5 = F_67 ( V_9 ) ;
return F_113 ( V_5 ) ;
}
static int F_283 ( struct V_7 * V_9 ,
struct V_286 * V_287 , V_126 V_45 )
{
struct V_4 * V_5 = F_67 ( V_9 ) ;
if ( V_45 > 100 )
return - V_268 ;
if ( V_9 -> V_28 )
V_5 -> V_332 = V_45 ;
else
V_333 = V_45 ;
return 0 ;
}
static void F_284 ( struct V_4 * V_5 , bool V_137 )
{
struct V_334 * V_335 ;
unsigned long V_336 ;
int V_100 ;
F_13 () ;
if ( ! V_137 )
V_335 = F_70 ( V_5 -> V_337 . V_338 ) ;
else
V_335 = F_70 ( V_5 -> V_339 . V_338 ) ;
if ( ! V_335 )
goto V_120;
V_336 = F_248 ( V_5 , V_137 ) ;
V_100 = V_335 -> V_340 ;
for (; V_100 >= 0 && F_63 ( V_335 -> V_341 [ V_100 ] . V_342 > V_336 ) ; V_100 -- )
F_285 ( V_335 -> V_341 [ V_100 ] . V_343 , 1 ) ;
V_100 ++ ;
for (; V_100 < V_335 -> V_109 && F_63 ( V_335 -> V_341 [ V_100 ] . V_342 <= V_336 ) ; V_100 ++ )
F_285 ( V_335 -> V_341 [ V_100 ] . V_343 , 1 ) ;
V_335 -> V_340 = V_100 - 1 ;
V_120:
F_17 () ;
}
static void F_64 ( struct V_4 * V_5 )
{
while ( V_5 ) {
F_284 ( V_5 , false ) ;
if ( F_1 () )
F_284 ( V_5 , true ) ;
V_5 = F_15 ( V_5 ) ;
}
}
static int F_286 ( const void * V_344 , const void * V_345 )
{
const struct F_64 * V_346 = V_344 ;
const struct F_64 * V_347 = V_345 ;
if ( V_346 -> V_342 > V_347 -> V_342 )
return 1 ;
if ( V_346 -> V_342 < V_347 -> V_342 )
return - 1 ;
return 0 ;
}
static int F_287 ( struct V_4 * V_5 )
{
struct V_348 * V_349 ;
F_98 ( & V_163 ) ;
F_288 (ev, &memcg->oom_notify, list)
F_285 ( V_349 -> V_343 , 1 ) ;
F_99 ( & V_163 ) ;
return 0 ;
}
static void F_143 ( struct V_4 * V_5 )
{
struct V_4 * V_89 ;
F_82 (iter, memcg)
F_287 ( V_89 ) ;
}
static int F_289 ( struct V_4 * V_5 ,
struct V_350 * V_343 , const char * args , enum V_351 type )
{
struct V_352 * V_337 ;
struct V_334 * V_353 ;
unsigned long V_342 ;
unsigned long V_336 ;
int V_100 , V_109 , V_103 ;
V_103 = F_267 ( args , L_14 , & V_342 ) ;
if ( V_103 )
return V_103 ;
F_115 ( & V_5 -> V_354 ) ;
if ( type == V_293 ) {
V_337 = & V_5 -> V_337 ;
V_336 = F_248 ( V_5 , false ) ;
} else if ( type == V_294 ) {
V_337 = & V_5 -> V_339 ;
V_336 = F_248 ( V_5 , true ) ;
} else
F_251 () ;
if ( V_337 -> V_338 )
F_284 ( V_5 , type == V_294 ) ;
V_109 = V_337 -> V_338 ? V_337 -> V_338 -> V_109 + 1 : 1 ;
V_353 = F_210 ( sizeof( * V_353 ) + V_109 * sizeof( struct F_64 ) ,
V_216 ) ;
if ( ! V_353 ) {
V_103 = - V_239 ;
goto V_120;
}
V_353 -> V_109 = V_109 ;
if ( V_337 -> V_338 ) {
memcpy ( V_353 -> V_341 , V_337 -> V_338 -> V_341 , ( V_109 - 1 ) *
sizeof( struct F_64 ) ) ;
}
V_353 -> V_341 [ V_109 - 1 ] . V_343 = V_343 ;
V_353 -> V_341 [ V_109 - 1 ] . V_342 = V_342 ;
F_290 ( V_353 -> V_341 , V_109 , sizeof( struct F_64 ) ,
F_286 , NULL ) ;
V_353 -> V_340 = - 1 ;
for ( V_100 = 0 ; V_100 < V_109 ; V_100 ++ ) {
if ( V_353 -> V_341 [ V_100 ] . V_342 <= V_336 ) {
++ V_353 -> V_340 ;
} else
break;
}
F_208 ( V_337 -> V_355 ) ;
V_337 -> V_355 = V_337 -> V_338 ;
F_291 ( V_337 -> V_338 , V_353 ) ;
F_292 () ;
V_120:
F_117 ( & V_5 -> V_354 ) ;
return V_103 ;
}
static int F_293 ( struct V_4 * V_5 ,
struct V_350 * V_343 , const char * args )
{
return F_289 ( V_5 , V_343 , args , V_293 ) ;
}
static int F_294 ( struct V_4 * V_5 ,
struct V_350 * V_343 , const char * args )
{
return F_289 ( V_5 , V_343 , args , V_294 ) ;
}
static void F_295 ( struct V_4 * V_5 ,
struct V_350 * V_343 , enum V_351 type )
{
struct V_352 * V_337 ;
struct V_334 * V_353 ;
unsigned long V_336 ;
int V_100 , V_356 , V_109 ;
F_115 ( & V_5 -> V_354 ) ;
if ( type == V_293 ) {
V_337 = & V_5 -> V_337 ;
V_336 = F_248 ( V_5 , false ) ;
} else if ( type == V_294 ) {
V_337 = & V_5 -> V_339 ;
V_336 = F_248 ( V_5 , true ) ;
} else
F_251 () ;
if ( ! V_337 -> V_338 )
goto V_120;
F_284 ( V_5 , type == V_294 ) ;
V_109 = 0 ;
for ( V_100 = 0 ; V_100 < V_337 -> V_338 -> V_109 ; V_100 ++ ) {
if ( V_337 -> V_338 -> V_341 [ V_100 ] . V_343 != V_343 )
V_109 ++ ;
}
V_353 = V_337 -> V_355 ;
if ( ! V_109 ) {
F_208 ( V_353 ) ;
V_353 = NULL ;
goto V_357;
}
V_353 -> V_109 = V_109 ;
V_353 -> V_340 = - 1 ;
for ( V_100 = 0 , V_356 = 0 ; V_100 < V_337 -> V_338 -> V_109 ; V_100 ++ ) {
if ( V_337 -> V_338 -> V_341 [ V_100 ] . V_343 == V_343 )
continue;
V_353 -> V_341 [ V_356 ] = V_337 -> V_338 -> V_341 [ V_100 ] ;
if ( V_353 -> V_341 [ V_356 ] . V_342 <= V_336 ) {
++ V_353 -> V_340 ;
}
V_356 ++ ;
}
V_357:
V_337 -> V_355 = V_337 -> V_338 ;
F_291 ( V_337 -> V_338 , V_353 ) ;
F_292 () ;
if ( ! V_353 ) {
F_208 ( V_337 -> V_355 ) ;
V_337 -> V_355 = NULL ;
}
V_120:
F_117 ( & V_5 -> V_354 ) ;
}
static void F_296 ( struct V_4 * V_5 ,
struct V_350 * V_343 )
{
return F_295 ( V_5 , V_343 , V_293 ) ;
}
static void F_297 ( struct V_4 * V_5 ,
struct V_350 * V_343 )
{
return F_295 ( V_5 , V_343 , V_294 ) ;
}
static int F_298 ( struct V_4 * V_5 ,
struct V_350 * V_343 , const char * args )
{
struct V_348 * V_358 ;
V_358 = F_210 ( sizeof( * V_358 ) , V_216 ) ;
if ( ! V_358 )
return - V_239 ;
F_98 ( & V_163 ) ;
V_358 -> V_343 = V_343 ;
F_299 ( & V_358 -> V_359 , & V_5 -> V_360 ) ;
if ( V_5 -> V_166 )
F_285 ( V_343 , 1 ) ;
F_99 ( & V_163 ) ;
return 0 ;
}
static void F_300 ( struct V_4 * V_5 ,
struct V_350 * V_343 )
{
struct V_348 * V_349 , * V_361 ;
F_98 ( & V_163 ) ;
F_301 (ev, tmp, &memcg->oom_notify, list) {
if ( V_349 -> V_343 == V_343 ) {
F_302 ( & V_349 -> V_359 ) ;
F_208 ( V_349 ) ;
}
}
F_99 ( & V_163 ) ;
}
static int F_303 ( struct V_316 * V_362 , void * V_318 )
{
struct V_4 * V_5 = F_67 ( F_274 ( V_362 ) ) ;
F_276 ( V_362 , L_30 , V_5 -> V_187 ) ;
F_276 ( V_362 , L_31 , ( bool ) V_5 -> V_166 ) ;
return 0 ;
}
static int F_304 ( struct V_7 * V_9 ,
struct V_286 * V_287 , V_126 V_45 )
{
struct V_4 * V_5 = F_67 ( V_9 ) ;
if ( ! V_9 -> V_28 || ! ( ( V_45 == 0 ) || ( V_45 == 1 ) ) )
return - V_268 ;
V_5 -> V_187 = V_45 ;
if ( ! V_45 )
F_138 ( V_5 ) ;
return 0 ;
}
struct V_363 * F_305 ( struct V_4 * V_5 )
{
return & V_5 -> V_364 ;
}
static int F_306 ( struct V_4 * V_5 , T_3 V_261 )
{
return F_307 ( & V_5 -> V_365 , V_261 ) ;
}
static void F_308 ( struct V_4 * V_5 )
{
F_309 ( & V_5 -> V_365 ) ;
}
static void F_310 ( struct V_4 * V_5 )
{
F_311 ( & V_5 -> V_365 ) ;
}
struct V_366 * F_312 ( struct V_367 * V_368 )
{
struct V_4 * V_5 = F_67 ( V_368 -> V_369 ) ;
if ( ! V_5 -> V_9 . V_28 )
return NULL ;
return & V_5 -> V_365 ;
}
void F_313 ( struct V_367 * V_368 , unsigned long * V_370 ,
unsigned long * V_371 , unsigned long * V_372 ,
unsigned long * V_373 )
{
struct V_4 * V_5 = F_67 ( V_368 -> V_369 ) ;
struct V_4 * V_28 ;
* V_372 = F_43 ( V_5 , V_374 ) ;
* V_373 = F_43 ( V_5 , V_375 ) ;
* V_370 = F_57 ( V_5 , ( 1 << V_376 ) |
( 1 << V_377 ) ) ;
* V_371 = V_326 ;
while ( ( V_28 = F_15 ( V_5 ) ) ) {
unsigned long V_378 = F_96 ( V_5 -> V_37 . V_115 , V_5 -> V_213 ) ;
unsigned long V_379 = F_32 ( & V_5 -> V_37 ) ;
* V_371 = F_96 ( * V_371 , V_378 - F_96 ( V_378 , V_379 ) ) ;
V_5 = V_28 ;
}
}
static int F_306 ( struct V_4 * V_5 , T_3 V_261 )
{
return 0 ;
}
static void F_308 ( struct V_4 * V_5 )
{
}
static void F_310 ( struct V_4 * V_5 )
{
}
static void F_314 ( struct V_199 * V_204 )
{
struct V_380 * V_358 =
F_5 ( V_204 , struct V_380 , remove ) ;
struct V_4 * V_5 = V_358 -> V_5 ;
F_315 ( V_358 -> V_381 , & V_358 -> V_123 ) ;
V_358 -> V_382 ( V_5 , V_358 -> V_343 ) ;
F_285 ( V_358 -> V_343 , 1 ) ;
F_316 ( V_358 -> V_343 ) ;
F_208 ( V_358 ) ;
F_76 ( & V_5 -> V_9 ) ;
}
static int F_317 ( T_5 * V_123 , unsigned V_167 ,
int V_168 , void * V_383 )
{
struct V_380 * V_358 =
F_5 ( V_123 , struct V_380 , V_123 ) ;
struct V_4 * V_5 = V_358 -> V_5 ;
unsigned long V_13 = ( unsigned long ) V_383 ;
if ( V_13 & V_384 ) {
F_98 ( & V_5 -> V_385 ) ;
if ( ! F_88 ( & V_358 -> V_359 ) ) {
F_318 ( & V_358 -> V_359 ) ;
F_184 ( & V_358 -> remove ) ;
}
F_99 ( & V_5 -> V_385 ) ;
}
return 0 ;
}
static void F_319 ( struct V_386 * V_386 ,
T_10 * V_381 , T_11 * V_387 )
{
struct V_380 * V_358 =
F_5 ( V_387 , struct V_380 , V_387 ) ;
V_358 -> V_381 = V_381 ;
F_320 ( V_381 , & V_358 -> V_123 ) ;
}
static T_7 F_321 ( struct V_281 * V_282 ,
char * V_283 , T_8 V_284 , T_9 V_285 )
{
struct V_7 * V_9 = F_243 ( V_282 ) ;
struct V_4 * V_5 = F_67 ( V_9 ) ;
struct V_380 * V_358 ;
struct V_7 * V_388 ;
unsigned int V_389 , V_390 ;
struct V_391 V_392 ;
struct V_391 V_393 ;
const char * V_320 ;
char * V_394 ;
int V_103 ;
V_283 = F_266 ( V_283 ) ;
V_389 = F_322 ( V_283 , & V_394 , 10 ) ;
if ( * V_394 != ' ' )
return - V_268 ;
V_283 = V_394 + 1 ;
V_390 = F_322 ( V_283 , & V_394 , 10 ) ;
if ( ( * V_394 != ' ' ) && ( * V_394 != '\0' ) )
return - V_268 ;
V_283 = V_394 + 1 ;
V_358 = F_323 ( sizeof( * V_358 ) , V_216 ) ;
if ( ! V_358 )
return - V_239 ;
V_358 -> V_5 = V_5 ;
F_142 ( & V_358 -> V_359 ) ;
F_324 ( & V_358 -> V_387 , F_319 ) ;
F_325 ( & V_358 -> V_123 , F_317 ) ;
F_211 ( & V_358 -> remove , F_314 ) ;
V_392 = F_326 ( V_389 ) ;
if ( ! V_392 . V_386 ) {
V_103 = - V_395 ;
goto V_396;
}
V_358 -> V_343 = F_327 ( V_392 . V_386 ) ;
if ( F_328 ( V_358 -> V_343 ) ) {
V_103 = F_329 ( V_358 -> V_343 ) ;
goto V_397;
}
V_393 = F_326 ( V_390 ) ;
if ( ! V_393 . V_386 ) {
V_103 = - V_395 ;
goto V_398;
}
V_103 = F_330 ( F_331 ( V_393 . V_386 ) , V_399 ) ;
if ( V_103 < 0 )
goto V_400;
V_320 = V_393 . V_386 -> V_401 . V_402 -> V_403 . V_320 ;
if ( ! strcmp ( V_320 , L_32 ) ) {
V_358 -> V_404 = F_293 ;
V_358 -> V_382 = F_296 ;
} else if ( ! strcmp ( V_320 , L_33 ) ) {
V_358 -> V_404 = F_298 ;
V_358 -> V_382 = F_300 ;
} else if ( ! strcmp ( V_320 , L_34 ) ) {
V_358 -> V_404 = V_405 ;
V_358 -> V_382 = V_406 ;
} else if ( ! strcmp ( V_320 , L_35 ) ) {
V_358 -> V_404 = F_294 ;
V_358 -> V_382 = F_297 ;
} else {
V_103 = - V_268 ;
goto V_400;
}
V_388 = F_332 ( V_393 . V_386 -> V_401 . V_402 -> V_407 ,
& V_1 ) ;
V_103 = - V_268 ;
if ( F_328 ( V_388 ) )
goto V_400;
if ( V_388 != V_9 ) {
F_76 ( V_388 ) ;
goto V_400;
}
V_103 = V_358 -> V_404 ( V_5 , V_358 -> V_343 , V_283 ) ;
if ( V_103 )
goto V_408;
V_392 . V_386 -> V_409 -> V_410 ( V_392 . V_386 , & V_358 -> V_387 ) ;
F_98 ( & V_5 -> V_385 ) ;
F_299 ( & V_358 -> V_359 , & V_5 -> V_411 ) ;
F_99 ( & V_5 -> V_385 ) ;
F_333 ( V_393 ) ;
F_333 ( V_392 ) ;
return V_284 ;
V_408:
F_76 ( V_9 ) ;
V_400:
F_333 ( V_393 ) ;
V_398:
F_316 ( V_358 -> V_343 ) ;
V_397:
F_333 ( V_392 ) ;
V_396:
F_208 ( V_358 ) ;
return V_103 ;
}
static void F_334 ( struct V_4 * V_5 , unsigned int V_412 )
{
F_54 ( F_120 ( & V_5 -> V_244 . V_413 ) <= 0 ) ;
F_335 ( V_412 , & V_5 -> V_244 . V_413 ) ;
}
static void F_336 ( struct V_4 * V_5 , unsigned int V_412 )
{
F_54 ( F_120 ( & V_5 -> V_244 . V_413 ) < V_412 ) ;
if ( F_337 ( V_412 , & V_5 -> V_244 . V_413 ) ) {
F_338 ( & V_414 , V_5 -> V_244 . V_244 ) ;
V_5 -> V_244 . V_244 = 0 ;
F_76 ( & V_5 -> V_9 ) ;
}
}
static inline void F_339 ( struct V_4 * V_5 )
{
F_334 ( V_5 , 1 ) ;
}
static inline void F_340 ( struct V_4 * V_5 )
{
F_336 ( V_5 , 1 ) ;
}
struct V_4 * F_341 ( unsigned short V_244 )
{
F_342 ( ! F_343 () ) ;
return F_344 ( & V_414 , V_244 ) ;
}
static int F_345 ( struct V_4 * V_5 , int V_153 )
{
struct V_16 * V_415 ;
int V_361 = V_153 ;
if ( ! F_346 ( V_153 , V_416 ) )
V_361 = - 1 ;
V_415 = F_347 ( sizeof( * V_415 ) , V_216 , V_361 ) ;
if ( ! V_415 )
return 1 ;
F_348 ( & V_415 -> V_107 ) ;
V_415 -> V_31 = 0 ;
V_415 -> V_30 = false ;
V_415 -> V_5 = V_5 ;
V_5 -> V_18 [ V_153 ] = V_415 ;
return 0 ;
}
static void F_349 ( struct V_4 * V_5 , int V_153 )
{
F_208 ( V_5 -> V_18 [ V_153 ] ) ;
}
static void F_350 ( struct V_4 * V_5 )
{
int V_153 ;
F_308 ( V_5 ) ;
F_35 (node)
F_349 ( V_5 , V_153 ) ;
F_351 ( V_5 -> V_47 ) ;
F_208 ( V_5 ) ;
}
static struct V_4 * F_352 ( void )
{
struct V_4 * V_5 ;
T_8 V_109 ;
int V_153 ;
V_109 = sizeof( struct V_4 ) ;
V_109 += V_62 * sizeof( struct V_16 * ) ;
V_5 = F_323 ( V_109 , V_216 ) ;
if ( ! V_5 )
return NULL ;
V_5 -> V_244 . V_244 = F_353 ( & V_414 , NULL ,
1 , V_417 ,
V_216 ) ;
if ( V_5 -> V_244 . V_244 < 0 )
goto V_418;
V_5 -> V_47 = F_354 ( struct V_419 ) ;
if ( ! V_5 -> V_47 )
goto V_418;
F_35 (node)
if ( F_345 ( V_5 , V_153 ) )
goto V_418;
if ( F_306 ( V_5 , V_216 ) )
goto V_418;
F_211 ( & V_5 -> V_215 , F_169 ) ;
V_5 -> V_154 = V_76 ;
F_142 ( & V_5 -> V_360 ) ;
F_355 ( & V_5 -> V_354 ) ;
F_356 ( & V_5 -> V_190 ) ;
F_357 ( & V_5 -> V_3 ) ;
F_142 ( & V_5 -> V_411 ) ;
F_356 ( & V_5 -> V_385 ) ;
V_5 -> V_420 = V_421 ;
#ifndef F_358
V_5 -> V_259 = - 1 ;
#endif
#ifdef F_359
F_142 ( & V_5 -> V_364 ) ;
#endif
F_360 ( & V_414 , V_5 , V_5 -> V_244 . V_244 ) ;
return V_5 ;
V_418:
if ( V_5 -> V_244 . V_244 > 0 )
F_338 ( & V_414 , V_5 -> V_244 . V_244 ) ;
F_350 ( V_5 ) ;
return NULL ;
}
static struct V_7 * T_12
F_361 ( struct V_7 * V_422 )
{
struct V_4 * V_28 = F_67 ( V_422 ) ;
struct V_4 * V_5 ;
long error = - V_239 ;
V_5 = F_352 () ;
if ( ! V_5 )
return F_362 ( error ) ;
V_5 -> V_213 = V_326 ;
V_5 -> V_38 = V_326 ;
if ( V_28 ) {
V_5 -> V_332 = F_113 ( V_28 ) ;
V_5 -> V_187 = V_28 -> V_187 ;
}
if ( V_28 && V_28 -> V_91 ) {
V_5 -> V_91 = true ;
F_363 ( & V_5 -> V_37 , & V_28 -> V_37 ) ;
F_363 ( & V_5 -> V_137 , & V_28 -> V_137 ) ;
F_363 ( & V_5 -> V_116 , & V_28 -> V_116 ) ;
F_363 ( & V_5 -> V_128 , & V_28 -> V_128 ) ;
F_363 ( & V_5 -> V_297 , & V_28 -> V_297 ) ;
} else {
F_363 ( & V_5 -> V_37 , NULL ) ;
F_363 ( & V_5 -> V_137 , NULL ) ;
F_363 ( & V_5 -> V_116 , NULL ) ;
F_363 ( & V_5 -> V_128 , NULL ) ;
F_363 ( & V_5 -> V_297 , NULL ) ;
if ( V_28 != V_6 )
V_1 . V_423 = true ;
}
if ( ! V_28 ) {
V_6 = V_5 ;
return & V_5 -> V_9 ;
}
error = F_253 ( V_5 ) ;
if ( error )
goto V_418;
if ( F_2 ( V_1 ) && ! V_424 )
F_254 ( & V_312 ) ;
return & V_5 -> V_9 ;
V_418:
F_350 ( V_5 ) ;
return F_362 ( - V_239 ) ;
}
static int F_364 ( struct V_7 * V_9 )
{
struct V_4 * V_5 = F_67 ( V_9 ) ;
F_124 ( & V_5 -> V_244 . V_413 , 1 ) ;
F_93 ( V_9 ) ;
return 0 ;
}
static void F_365 ( struct V_7 * V_9 )
{
struct V_4 * V_5 = F_67 ( V_9 ) ;
struct V_380 * V_358 , * V_361 ;
F_98 ( & V_5 -> V_385 ) ;
F_301 (event, tmp, &memcg->event_list, list) {
F_318 ( & V_358 -> V_359 ) ;
F_184 ( & V_358 -> remove ) ;
}
F_99 ( & V_5 -> V_385 ) ;
F_255 ( V_5 ) ;
F_366 ( V_5 ) ;
F_340 ( V_5 ) ;
}
static void F_367 ( struct V_7 * V_9 )
{
struct V_4 * V_5 = F_67 ( V_9 ) ;
F_78 ( V_5 ) ;
}
static void F_368 ( struct V_7 * V_9 )
{
struct V_4 * V_5 = F_67 ( V_9 ) ;
if ( F_2 ( V_1 ) && ! V_424 )
F_261 ( & V_312 ) ;
if ( ! F_2 ( V_1 ) && V_5 -> V_311 )
F_261 ( & V_312 ) ;
F_369 ( & V_5 -> V_3 ) ;
F_370 ( & V_5 -> V_215 ) ;
F_34 ( V_5 ) ;
F_259 ( V_5 ) ;
F_350 ( V_5 ) ;
}
static void F_371 ( struct V_7 * V_9 )
{
struct V_4 * V_5 = F_67 ( V_9 ) ;
F_233 ( & V_5 -> V_37 , V_326 ) ;
F_233 ( & V_5 -> V_137 , V_326 ) ;
F_233 ( & V_5 -> V_116 , V_326 ) ;
F_233 ( & V_5 -> V_128 , V_326 ) ;
F_233 ( & V_5 -> V_297 , V_326 ) ;
V_5 -> V_425 = 0 ;
V_5 -> V_213 = V_326 ;
V_5 -> V_38 = V_326 ;
F_310 ( V_5 ) ;
}
static int F_372 ( unsigned long V_48 )
{
int V_103 ;
V_103 = F_172 ( V_119 . V_118 , V_216 & ~ V_426 , V_48 ) ;
if ( ! V_103 ) {
V_119 . V_427 += V_48 ;
return V_103 ;
}
while ( V_48 -- ) {
V_103 = F_172 ( V_119 . V_118 , V_216 & ~ V_234 , 1 ) ;
if ( V_103 )
return V_103 ;
V_119 . V_427 ++ ;
F_373 () ;
}
return 0 ;
}
static struct V_11 * F_374 ( struct V_428 * V_429 ,
unsigned long V_430 , T_13 V_431 )
{
struct V_11 * V_11 = F_375 ( V_429 , V_430 , V_431 ) ;
if ( ! V_11 || ! F_376 ( V_11 ) )
return NULL ;
if ( F_48 ( V_11 ) ) {
if ( ! ( V_119 . V_13 & V_432 ) )
return NULL ;
} else {
if ( ! ( V_119 . V_13 & V_433 ) )
return NULL ;
}
if ( ! F_377 ( V_11 ) )
return NULL ;
return V_11 ;
}
static struct V_11 * F_378 ( struct V_428 * V_429 ,
T_13 V_431 , T_6 * V_265 )
{
struct V_11 * V_11 = NULL ;
T_6 V_434 = F_379 ( V_431 ) ;
if ( ! ( V_119 . V_13 & V_432 ) || F_380 ( V_434 ) )
return NULL ;
V_11 = F_381 ( F_382 ( V_434 ) , F_383 ( V_434 ) ) ;
if ( F_1 () )
V_265 -> V_45 = V_434 . V_45 ;
return V_11 ;
}
static struct V_11 * F_378 ( struct V_428 * V_429 ,
T_13 V_431 , T_6 * V_265 )
{
return NULL ;
}
static struct V_11 * F_384 ( struct V_428 * V_429 ,
unsigned long V_430 , T_13 V_431 , T_6 * V_265 )
{
struct V_11 * V_11 = NULL ;
struct V_435 * V_436 ;
T_14 V_437 ;
if ( ! V_429 -> V_438 )
return NULL ;
if ( ! ( V_119 . V_13 & V_433 ) )
return NULL ;
V_436 = V_429 -> V_438 -> V_439 ;
V_437 = F_385 ( V_429 , V_430 ) ;
#ifdef F_386
if ( F_387 ( V_436 ) ) {
V_11 = F_388 ( V_436 , V_437 ) ;
if ( F_389 ( V_11 ) ) {
T_6 V_440 = F_390 ( V_11 ) ;
if ( F_1 () )
* V_265 = V_440 ;
V_11 = F_381 ( F_382 ( V_440 ) ,
F_383 ( V_440 ) ) ;
}
} else
V_11 = F_381 ( V_436 , V_437 ) ;
#else
V_11 = F_381 ( V_436 , V_437 ) ;
#endif
return V_11 ;
}
static int F_391 ( struct V_11 * V_11 ,
bool V_51 ,
struct V_4 * V_117 ,
struct V_4 * V_118 )
{
unsigned long V_13 ;
unsigned int V_36 = V_51 ? F_392 ( V_11 ) : 1 ;
int V_103 ;
bool V_441 ;
F_54 ( V_117 == V_118 ) ;
F_50 ( F_190 ( V_11 ) , V_11 ) ;
F_54 ( V_51 && ! F_51 ( V_11 ) ) ;
V_103 = - V_290 ;
if ( ! F_393 ( V_11 ) )
goto V_92;
V_103 = - V_268 ;
if ( V_11 -> V_4 != V_117 )
goto V_97;
V_441 = F_48 ( V_11 ) ;
F_29 ( & V_117 -> V_190 , V_13 ) ;
if ( ! V_441 && F_376 ( V_11 ) ) {
F_225 ( V_117 -> V_47 -> V_48 [ V_442 ] ,
V_36 ) ;
F_49 ( V_118 -> V_47 -> V_48 [ V_442 ] ,
V_36 ) ;
}
if ( ! V_441 && F_394 ( V_11 ) ) {
struct V_435 * V_436 = F_395 ( V_11 ) ;
if ( F_396 ( V_436 ) ) {
F_225 ( V_117 -> V_47 -> V_48 [ V_374 ] ,
V_36 ) ;
F_49 ( V_118 -> V_47 -> V_48 [ V_374 ] ,
V_36 ) ;
}
}
if ( F_397 ( V_11 ) ) {
F_225 ( V_117 -> V_47 -> V_48 [ V_375 ] ,
V_36 ) ;
F_49 ( V_118 -> V_47 -> V_48 [ V_375 ] ,
V_36 ) ;
}
V_11 -> V_4 = V_118 ;
F_30 ( & V_117 -> V_190 , V_13 ) ;
V_103 = 0 ;
F_398 () ;
F_47 ( V_118 , V_11 , V_51 , V_36 ) ;
F_62 ( V_118 , V_11 ) ;
F_47 ( V_117 , V_11 , V_51 , - V_36 ) ;
F_62 ( V_117 , V_11 ) ;
F_399 () ;
V_97:
F_400 ( V_11 ) ;
V_92:
return V_103 ;
}
static enum V_443 F_401 ( struct V_428 * V_429 ,
unsigned long V_430 , T_13 V_431 , union V_444 * V_65 )
{
struct V_11 * V_11 = NULL ;
enum V_443 V_103 = V_445 ;
T_6 V_434 = { . V_45 = 0 } ;
if ( F_402 ( V_431 ) )
V_11 = F_374 ( V_429 , V_430 , V_431 ) ;
else if ( F_403 ( V_431 ) )
V_11 = F_378 ( V_429 , V_431 , & V_434 ) ;
else if ( F_404 ( V_431 ) )
V_11 = F_384 ( V_429 , V_430 , V_431 , & V_434 ) ;
if ( ! V_11 && ! V_434 . V_45 )
return V_103 ;
if ( V_11 ) {
if ( V_11 -> V_4 == V_119 . V_117 ) {
V_103 = V_446 ;
if ( V_65 )
V_65 -> V_11 = V_11 ;
}
if ( ! V_103 || ! V_65 )
F_405 ( V_11 ) ;
}
if ( V_434 . V_45 && ! V_103 &&
F_229 ( V_119 . V_117 ) == F_406 ( V_434 ) ) {
V_103 = V_447 ;
if ( V_65 )
V_65 -> V_434 = V_434 ;
}
return V_103 ;
}
static enum V_443 F_407 ( struct V_428 * V_429 ,
unsigned long V_430 , T_15 V_448 , union V_444 * V_65 )
{
struct V_11 * V_11 = NULL ;
enum V_443 V_103 = V_445 ;
V_11 = F_408 ( V_448 ) ;
F_50 ( ! V_11 || ! F_409 ( V_11 ) , V_11 ) ;
if ( ! ( V_119 . V_13 & V_432 ) )
return V_103 ;
if ( V_11 -> V_4 == V_119 . V_117 ) {
V_103 = V_446 ;
if ( V_65 ) {
F_410 ( V_11 ) ;
V_65 -> V_11 = V_11 ;
}
}
return V_103 ;
}
static inline enum V_443 F_407 ( struct V_428 * V_429 ,
unsigned long V_430 , T_15 V_448 , union V_444 * V_65 )
{
return V_445 ;
}
static int F_411 ( T_15 * V_448 ,
unsigned long V_430 , unsigned long V_449 ,
struct V_450 * V_451 )
{
struct V_428 * V_429 = V_451 -> V_429 ;
T_13 * V_452 ;
T_16 * V_453 ;
V_453 = F_412 ( V_448 , V_429 ) ;
if ( V_453 ) {
if ( F_407 ( V_429 , V_430 , * V_448 , NULL ) == V_446 )
V_119 . V_427 += V_263 ;
F_99 ( V_453 ) ;
return 0 ;
}
if ( F_413 ( V_448 ) )
return 0 ;
V_452 = F_414 ( V_429 -> V_454 , V_448 , V_430 , & V_453 ) ;
for (; V_430 != V_449 ; V_452 ++ , V_430 += V_238 )
if ( F_401 ( V_429 , V_430 , * V_452 , NULL ) )
V_119 . V_427 ++ ;
F_415 ( V_452 - 1 , V_453 ) ;
F_373 () ;
return 0 ;
}
static unsigned long F_416 ( struct V_80 * V_81 )
{
unsigned long V_427 ;
struct V_450 V_455 = {
. V_456 = F_411 ,
. V_81 = V_81 ,
} ;
F_8 ( & V_81 -> V_457 ) ;
F_417 ( 0 , V_81 -> V_458 ,
& V_455 ) ;
F_10 ( & V_81 -> V_457 ) ;
V_427 = V_119 . V_427 ;
V_119 . V_427 = 0 ;
return V_427 ;
}
static int F_418 ( struct V_80 * V_81 )
{
unsigned long V_427 = F_416 ( V_81 ) ;
F_54 ( V_119 . V_121 ) ;
V_119 . V_121 = V_122 ;
return F_372 ( V_427 ) ;
}
static void F_419 ( void )
{
struct V_4 * V_117 = V_119 . V_117 ;
struct V_4 * V_118 = V_119 . V_118 ;
if ( V_119 . V_427 ) {
F_186 ( V_119 . V_118 , V_119 . V_427 ) ;
V_119 . V_427 = 0 ;
}
if ( V_119 . V_459 ) {
F_186 ( V_119 . V_117 , V_119 . V_459 ) ;
V_119 . V_459 = 0 ;
}
if ( V_119 . V_460 ) {
if ( ! F_6 ( V_119 . V_117 ) )
F_151 ( & V_119 . V_117 -> V_116 , V_119 . V_460 ) ;
F_336 ( V_119 . V_117 , V_119 . V_460 ) ;
if ( ! F_6 ( V_119 . V_118 ) )
F_151 ( & V_119 . V_118 -> V_37 , V_119 . V_460 ) ;
F_334 ( V_119 . V_118 , V_119 . V_460 ) ;
F_152 ( & V_119 . V_118 -> V_9 , V_119 . V_460 ) ;
V_119 . V_460 = 0 ;
}
F_138 ( V_117 ) ;
F_138 ( V_118 ) ;
F_420 ( & V_119 . V_124 ) ;
}
static void F_421 ( void )
{
struct V_80 * V_81 = V_119 . V_81 ;
V_119 . V_121 = NULL ;
F_419 () ;
F_98 ( & V_119 . V_35 ) ;
V_119 . V_117 = NULL ;
V_119 . V_118 = NULL ;
V_119 . V_81 = NULL ;
F_99 ( & V_119 . V_35 ) ;
F_422 ( V_81 ) ;
}
static int F_423 ( struct V_461 * V_462 )
{
struct V_7 * V_9 ;
struct V_4 * V_5 = NULL ;
struct V_4 * V_117 ;
struct V_78 * V_463 , * V_26 ;
struct V_80 * V_81 ;
unsigned long V_464 ;
int V_103 = 0 ;
if ( F_2 ( V_1 ) )
return 0 ;
V_26 = NULL ;
F_424 (leader, css, tset) {
F_342 ( V_26 ) ;
V_26 = V_463 ;
V_5 = F_67 ( V_9 ) ;
}
if ( ! V_26 )
return 0 ;
V_464 = F_14 ( V_5 -> V_313 ) ;
if ( ! V_464 )
return 0 ;
V_117 = F_66 ( V_26 ) ;
F_54 ( V_117 == V_5 ) ;
V_81 = F_425 ( V_26 ) ;
if ( ! V_81 )
return 0 ;
if ( V_81 -> V_82 == V_26 ) {
F_54 ( V_119 . V_117 ) ;
F_54 ( V_119 . V_118 ) ;
F_54 ( V_119 . V_427 ) ;
F_54 ( V_119 . V_459 ) ;
F_54 ( V_119 . V_460 ) ;
F_98 ( & V_119 . V_35 ) ;
V_119 . V_81 = V_81 ;
V_119 . V_117 = V_117 ;
V_119 . V_118 = V_5 ;
V_119 . V_13 = V_464 ;
F_99 ( & V_119 . V_35 ) ;
V_103 = F_418 ( V_81 ) ;
if ( V_103 )
F_421 () ;
} else {
F_422 ( V_81 ) ;
}
return V_103 ;
}
static void F_426 ( struct V_461 * V_462 )
{
if ( V_119 . V_118 )
F_421 () ;
}
static int F_427 ( T_15 * V_448 ,
unsigned long V_430 , unsigned long V_449 ,
struct V_450 * V_451 )
{
int V_103 = 0 ;
struct V_428 * V_429 = V_451 -> V_429 ;
T_13 * V_452 ;
T_16 * V_453 ;
enum V_443 V_465 ;
union V_444 V_65 ;
struct V_11 * V_11 ;
V_453 = F_412 ( V_448 , V_429 ) ;
if ( V_453 ) {
if ( V_119 . V_427 < V_263 ) {
F_99 ( V_453 ) ;
return 0 ;
}
V_465 = F_407 ( V_429 , V_430 , * V_448 , & V_65 ) ;
if ( V_465 == V_446 ) {
V_11 = V_65 . V_11 ;
if ( ! F_428 ( V_11 ) ) {
if ( ! F_391 ( V_11 , true ,
V_119 . V_117 , V_119 . V_118 ) ) {
V_119 . V_427 -= V_263 ;
V_119 . V_459 += V_263 ;
}
F_429 ( V_11 ) ;
}
F_405 ( V_11 ) ;
}
F_99 ( V_453 ) ;
return 0 ;
}
if ( F_413 ( V_448 ) )
return 0 ;
V_41:
V_452 = F_414 ( V_429 -> V_454 , V_448 , V_430 , & V_453 ) ;
for (; V_430 != V_449 ; V_430 += V_238 ) {
T_13 V_431 = * ( V_452 ++ ) ;
T_6 V_434 ;
if ( ! V_119 . V_427 )
break;
switch ( F_401 ( V_429 , V_430 , V_431 , & V_65 ) ) {
case V_446 :
V_11 = V_65 . V_11 ;
if ( F_430 ( V_11 ) )
goto V_466;
if ( F_428 ( V_11 ) )
goto V_466;
if ( ! F_391 ( V_11 , false ,
V_119 . V_117 , V_119 . V_118 ) ) {
V_119 . V_427 -- ;
V_119 . V_459 ++ ;
}
F_429 ( V_11 ) ;
V_466:
F_405 ( V_11 ) ;
break;
case V_447 :
V_434 = V_65 . V_434 ;
if ( ! F_228 ( V_434 , V_119 . V_117 , V_119 . V_118 ) ) {
V_119 . V_427 -- ;
V_119 . V_460 ++ ;
}
break;
default:
break;
}
}
F_415 ( V_452 - 1 , V_453 ) ;
F_373 () ;
if ( V_430 != V_449 ) {
V_103 = F_372 ( 1 ) ;
if ( ! V_103 )
goto V_41;
}
return V_103 ;
}
static void F_431 ( void )
{
struct V_450 V_467 = {
. V_456 = F_427 ,
. V_81 = V_119 . V_81 ,
} ;
F_240 () ;
F_65 ( & V_119 . V_117 -> V_189 ) ;
F_292 () ;
V_41:
if ( F_63 ( ! F_432 ( & V_119 . V_81 -> V_457 ) ) ) {
F_419 () ;
F_373 () ;
goto V_41;
}
F_417 ( 0 , V_119 . V_81 -> V_458 , & V_467 ) ;
F_10 ( & V_119 . V_81 -> V_457 ) ;
F_433 ( & V_119 . V_117 -> V_189 ) ;
}
static void F_434 ( void )
{
if ( V_119 . V_118 ) {
F_431 () ;
F_421 () ;
}
}
static int F_423 ( struct V_461 * V_462 )
{
return 0 ;
}
static void F_426 ( struct V_461 * V_462 )
{
}
static void F_434 ( void )
{
}
static void F_435 ( struct V_7 * V_468 )
{
if ( F_2 ( V_1 ) )
V_6 -> V_91 = true ;
else
V_6 -> V_91 = false ;
}
static V_126 F_436 ( struct V_7 * V_9 ,
struct V_286 * V_287 )
{
struct V_4 * V_5 = F_67 ( V_9 ) ;
return ( V_126 ) F_32 ( & V_5 -> V_37 ) * V_238 ;
}
static int F_437 ( struct V_316 * V_317 , void * V_318 )
{
struct V_4 * V_5 = F_67 ( F_274 ( V_317 ) ) ;
unsigned long V_425 = F_14 ( V_5 -> V_425 ) ;
if ( V_425 == V_326 )
F_438 ( V_317 , L_36 ) ;
else
F_276 ( V_317 , L_37 , ( V_126 ) V_425 * V_238 ) ;
return 0 ;
}
static T_7 F_439 ( struct V_281 * V_282 ,
char * V_283 , T_8 V_284 , T_9 V_285 )
{
struct V_4 * V_5 = F_67 ( F_243 ( V_282 ) ) ;
unsigned long V_425 ;
int V_245 ;
V_283 = F_266 ( V_283 ) ;
V_245 = F_267 ( V_283 , L_38 , & V_425 ) ;
if ( V_245 )
return V_245 ;
V_5 -> V_425 = V_425 ;
return V_284 ;
}
static int F_440 ( struct V_316 * V_317 , void * V_318 )
{
struct V_4 * V_5 = F_67 ( F_274 ( V_317 ) ) ;
unsigned long V_213 = F_14 ( V_5 -> V_213 ) ;
if ( V_213 == V_326 )
F_438 ( V_317 , L_36 ) ;
else
F_276 ( V_317 , L_37 , ( V_126 ) V_213 * V_238 ) ;
return 0 ;
}
static T_7 F_441 ( struct V_281 * V_282 ,
char * V_283 , T_8 V_284 , T_9 V_285 )
{
struct V_4 * V_5 = F_67 ( F_243 ( V_282 ) ) ;
unsigned long V_36 ;
unsigned long V_213 ;
int V_245 ;
V_283 = F_266 ( V_283 ) ;
V_245 = F_267 ( V_283 , L_38 , & V_213 ) ;
if ( V_245 )
return V_245 ;
V_5 -> V_213 = V_213 ;
V_36 = F_32 ( & V_5 -> V_37 ) ;
if ( V_36 > V_213 )
F_168 ( V_5 , V_36 - V_213 ,
V_216 , true ) ;
F_310 ( V_5 ) ;
return V_284 ;
}
static int F_442 ( struct V_316 * V_317 , void * V_318 )
{
struct V_4 * V_5 = F_67 ( F_274 ( V_317 ) ) ;
unsigned long F_173 = F_14 ( V_5 -> V_37 . V_115 ) ;
if ( F_173 == V_326 )
F_438 ( V_317 , L_36 ) ;
else
F_276 ( V_317 , L_37 , ( V_126 ) F_173 * V_238 ) ;
return 0 ;
}
static T_7 F_443 ( struct V_281 * V_282 ,
char * V_283 , T_8 V_284 , T_9 V_285 )
{
struct V_4 * V_5 = F_67 ( F_243 ( V_282 ) ) ;
unsigned int V_469 = V_220 ;
bool V_226 = false ;
unsigned long F_173 ;
int V_245 ;
V_283 = F_266 ( V_283 ) ;
V_245 = F_267 ( V_283 , L_38 , & F_173 ) ;
if ( V_245 )
return V_245 ;
F_444 ( & V_5 -> V_37 . V_115 , F_173 ) ;
for (; ; ) {
unsigned long V_36 = F_32 ( & V_5 -> V_37 ) ;
if ( V_36 <= F_173 )
break;
if ( F_232 ( V_122 ) ) {
V_245 = - V_273 ;
break;
}
if ( ! V_226 ) {
F_156 ( V_5 ) ;
V_226 = true ;
continue;
}
if ( V_469 ) {
if ( ! F_168 ( V_5 , V_36 - F_173 ,
V_216 , true ) )
V_469 -- ;
continue;
}
F_167 ( V_5 , V_237 , 1 ) ;
if ( ! F_114 ( V_5 , V_216 , 0 ) )
break;
}
F_310 ( V_5 ) ;
return V_284 ;
}
static int F_445 ( struct V_316 * V_317 , void * V_318 )
{
struct V_4 * V_5 = F_67 ( F_274 ( V_317 ) ) ;
F_276 ( V_317 , L_39 , F_46 ( V_5 , V_470 ) ) ;
F_276 ( V_317 , L_40 , F_46 ( V_5 , V_214 ) ) ;
F_276 ( V_317 , L_41 , F_46 ( V_5 , V_233 ) ) ;
F_276 ( V_317 , L_42 , F_46 ( V_5 , V_237 ) ) ;
return 0 ;
}
static int F_446 ( struct V_316 * V_317 , void * V_318 )
{
struct V_4 * V_5 = F_67 ( F_274 ( V_317 ) ) ;
unsigned long V_47 [ V_291 ] ;
unsigned long V_50 [ V_292 ] ;
int V_100 ;
F_246 ( V_5 , V_47 ) ;
F_247 ( V_5 , V_50 ) ;
F_276 ( V_317 , L_43 ,
( V_126 ) V_47 [ V_52 ] * V_238 ) ;
F_276 ( V_317 , L_44 ,
( V_126 ) V_47 [ V_53 ] * V_238 ) ;
F_276 ( V_317 , L_45 ,
( V_126 ) V_47 [ V_471 ] * 1024 ) ;
F_276 ( V_317 , L_46 ,
( V_126 ) ( V_47 [ V_472 ] +
V_47 [ V_473 ] ) * V_238 ) ;
F_276 ( V_317 , L_47 ,
( V_126 ) V_47 [ V_474 ] * V_238 ) ;
F_276 ( V_317 , L_48 ,
( V_126 ) V_47 [ V_442 ] * V_238 ) ;
F_276 ( V_317 , L_49 ,
( V_126 ) V_47 [ V_374 ] * V_238 ) ;
F_276 ( V_317 , L_50 ,
( V_126 ) V_47 [ V_375 ] * V_238 ) ;
for ( V_100 = 0 ; V_100 < V_132 ; V_100 ++ ) {
struct V_4 * V_323 ;
unsigned long V_45 = 0 ;
F_82 (mi, memcg)
V_45 += F_57 ( V_323 , F_56 ( V_100 ) ) ;
F_276 ( V_317 , L_51 ,
V_133 [ V_100 ] , ( V_126 ) V_45 * V_238 ) ;
}
F_276 ( V_317 , L_52 ,
( V_126 ) V_47 [ V_472 ] * V_238 ) ;
F_276 ( V_317 , L_53 ,
( V_126 ) V_47 [ V_473 ] * V_238 ) ;
F_276 ( V_317 , L_54 ,
V_50 [ V_475 ] ) ;
F_276 ( V_317 , L_55 ,
V_50 [ V_476 ] ) ;
return 0 ;
}
bool F_447 ( struct V_4 * V_83 , struct V_4 * V_5 )
{
if ( F_72 () )
return false ;
if ( V_5 == V_6 )
return false ;
if ( F_32 ( & V_5 -> V_37 ) >= V_5 -> V_425 )
return false ;
while ( V_5 != V_83 ) {
V_5 = F_15 ( V_5 ) ;
if ( V_5 == V_6 )
break;
if ( F_32 ( & V_5 -> V_37 ) >= V_5 -> V_425 )
return false ;
}
return true ;
}
int F_448 ( struct V_11 * V_11 , struct V_80 * V_81 ,
T_3 V_139 , struct V_4 * * V_477 ,
bool V_51 )
{
struct V_4 * V_5 = NULL ;
unsigned int V_36 = V_51 ? F_392 ( V_11 ) : 1 ;
int V_103 = 0 ;
if ( F_72 () )
goto V_92;
if ( F_449 ( V_11 ) ) {
F_50 ( ! F_450 ( V_11 ) , V_11 ) ;
if ( V_11 -> V_4 )
goto V_92;
if ( V_2 ) {
T_6 V_434 = { . V_45 = F_451 ( V_11 ) , } ;
unsigned short V_244 = F_406 ( V_434 ) ;
F_13 () ;
V_5 = F_341 ( V_244 ) ;
if ( V_5 && ! F_39 ( & V_5 -> V_9 ) )
V_5 = NULL ;
F_17 () ;
}
}
if ( ! V_5 )
V_5 = F_69 ( V_81 ) ;
V_103 = F_172 ( V_5 , V_139 , V_36 ) ;
F_76 ( & V_5 -> V_9 ) ;
V_92:
* V_477 = V_5 ;
return V_103 ;
}
void F_452 ( struct V_11 * V_11 , struct V_4 * V_5 ,
bool V_243 , bool V_51 )
{
unsigned int V_36 = V_51 ? F_392 ( V_11 ) : 1 ;
F_50 ( ! V_11 -> V_436 , V_11 ) ;
F_50 ( F_190 ( V_11 ) && ! V_243 , V_11 ) ;
if ( F_72 () )
return;
if ( ! V_5 )
return;
F_197 ( V_11 , V_5 , V_243 ) ;
F_398 () ;
F_47 ( V_5 , V_11 , V_51 , V_36 ) ;
F_62 ( V_5 , V_11 ) ;
F_399 () ;
if ( F_1 () && F_449 ( V_11 ) ) {
T_6 V_265 = { . V_45 = F_451 (page) } ;
F_453 ( V_265 ) ;
}
}
void F_454 ( struct V_11 * V_11 , struct V_4 * V_5 ,
bool V_51 )
{
unsigned int V_36 = V_51 ? F_392 ( V_11 ) : 1 ;
if ( F_72 () )
return;
if ( ! V_5 )
return;
F_186 ( V_5 , V_36 ) ;
}
static void F_455 ( struct V_4 * V_5 , unsigned long V_478 ,
unsigned long V_479 , unsigned long V_480 ,
unsigned long V_481 , unsigned long V_482 ,
struct V_11 * V_483 )
{
unsigned long V_36 = V_479 + V_480 + V_482 ;
unsigned long V_13 ;
if ( ! F_6 ( V_5 ) ) {
F_151 ( & V_5 -> V_37 , V_36 ) ;
if ( F_1 () )
F_151 ( & V_5 -> V_116 , V_36 ) ;
if ( ! F_2 ( V_1 ) && V_482 )
F_151 ( & V_5 -> V_128 , V_482 ) ;
F_138 ( V_5 ) ;
}
F_147 ( V_13 ) ;
F_225 ( V_5 -> V_47 -> V_48 [ V_52 ] , V_479 ) ;
F_225 ( V_5 -> V_47 -> V_48 [ V_53 ] , V_480 ) ;
F_225 ( V_5 -> V_47 -> V_48 [ V_54 ] , V_481 ) ;
F_49 ( V_5 -> V_47 -> V_50 [ V_56 ] , V_478 ) ;
F_49 ( V_5 -> V_47 -> V_57 , V_36 ) ;
F_62 ( V_5 , V_483 ) ;
F_149 ( V_13 ) ;
if ( ! F_6 ( V_5 ) )
F_152 ( & V_5 -> V_9 , V_36 ) ;
}
static void F_456 ( struct V_363 * V_484 )
{
struct V_4 * V_5 = NULL ;
unsigned long V_479 = 0 ;
unsigned long V_480 = 0 ;
unsigned long V_481 = 0 ;
unsigned long V_482 = 0 ;
unsigned long V_478 = 0 ;
struct V_363 * V_66 ;
struct V_11 * V_11 ;
V_66 = V_484 -> V_66 ;
do {
V_11 = F_457 ( V_66 , struct V_11 , V_61 ) ;
V_66 = V_11 -> V_61 . V_66 ;
F_50 ( F_190 ( V_11 ) , V_11 ) ;
F_50 ( F_458 ( V_11 ) , V_11 ) ;
if ( ! V_11 -> V_4 )
continue;
if ( V_5 != V_11 -> V_4 ) {
if ( V_5 ) {
F_455 ( V_5 , V_478 , V_479 , V_480 ,
V_481 , V_482 , V_11 ) ;
V_478 = V_479 = V_480 =
V_481 = V_482 = 0 ;
}
V_5 = V_11 -> V_4 ;
}
if ( ! F_222 ( V_11 ) ) {
unsigned int V_36 = 1 ;
if ( F_51 ( V_11 ) ) {
V_36 <<= F_459 ( V_11 ) ;
V_481 += V_36 ;
}
if ( F_48 ( V_11 ) )
V_479 += V_36 ;
else
V_480 += V_36 ;
V_478 ++ ;
} else {
V_482 += 1 << F_459 ( V_11 ) ;
F_223 ( V_11 ) ;
}
V_11 -> V_4 = NULL ;
} while ( V_66 != V_484 );
if ( V_5 )
F_455 ( V_5 , V_478 , V_479 , V_480 ,
V_481 , V_482 , V_11 ) ;
}
void F_460 ( struct V_11 * V_11 )
{
if ( F_72 () )
return;
if ( ! V_11 -> V_4 )
return;
F_142 ( & V_11 -> V_61 ) ;
F_456 ( & V_11 -> V_61 ) ;
}
void F_461 ( struct V_363 * V_484 )
{
if ( F_72 () )
return;
if ( ! F_88 ( V_484 ) )
F_456 ( V_484 ) ;
}
void F_462 ( struct V_11 * V_485 , struct V_11 * V_486 )
{
struct V_4 * V_5 ;
unsigned int V_36 ;
bool V_51 ;
unsigned long V_13 ;
F_50 ( ! F_450 ( V_485 ) , V_485 ) ;
F_50 ( ! F_450 ( V_486 ) , V_486 ) ;
F_50 ( F_48 ( V_485 ) != F_48 ( V_486 ) , V_486 ) ;
F_50 ( F_51 ( V_485 ) != F_51 ( V_486 ) ,
V_486 ) ;
if ( F_72 () )
return;
if ( V_486 -> V_4 )
return;
V_5 = V_485 -> V_4 ;
if ( ! V_5 )
return;
V_51 = F_51 ( V_486 ) ;
V_36 = V_51 ? F_392 ( V_486 ) : 1 ;
F_181 ( & V_5 -> V_37 , V_36 ) ;
if ( F_1 () )
F_181 ( & V_5 -> V_116 , V_36 ) ;
F_182 ( & V_5 -> V_9 , V_36 ) ;
F_197 ( V_486 , V_5 , false ) ;
F_147 ( V_13 ) ;
F_47 ( V_5 , V_486 , V_51 , V_36 ) ;
F_62 ( V_5 , V_486 ) ;
F_149 ( V_13 ) ;
}
void F_463 ( struct V_487 * V_488 )
{
struct V_4 * V_5 ;
if ( ! V_489 )
return;
if ( V_488 -> V_490 ) {
F_81 ( F_6 ( V_488 -> V_490 ) ) ;
F_93 ( & V_488 -> V_490 -> V_9 ) ;
return;
}
F_13 () ;
V_5 = F_66 ( V_122 ) ;
if ( V_5 == V_6 )
goto V_92;
if ( ! F_2 ( V_1 ) && ! V_5 -> V_311 )
goto V_92;
if ( F_39 ( & V_5 -> V_9 ) )
V_488 -> V_490 = V_5 ;
V_92:
F_17 () ;
}
void F_464 ( struct V_487 * V_488 )
{
if ( V_488 -> V_490 )
F_76 ( & V_488 -> V_490 -> V_9 ) ;
}
bool F_465 ( struct V_4 * V_5 , unsigned int V_36 )
{
T_3 V_139 = V_216 ;
if ( ! F_2 ( V_1 ) ) {
struct V_222 * V_418 ;
if ( F_174 ( & V_5 -> V_297 , V_36 , & V_418 ) ) {
V_5 -> V_491 = 0 ;
return true ;
}
F_181 ( & V_5 -> V_297 , V_36 ) ;
V_5 -> V_491 = 1 ;
return false ;
}
if ( F_466 () )
V_139 = V_255 ;
F_227 ( V_5 -> V_47 -> V_48 [ V_474 ] , V_36 ) ;
if ( F_172 ( V_5 , V_139 , V_36 ) == 0 )
return true ;
F_172 ( V_5 , V_139 | V_236 , V_36 ) ;
return false ;
}
void F_467 ( struct V_4 * V_5 , unsigned int V_36 )
{
if ( ! F_2 ( V_1 ) ) {
F_151 ( & V_5 -> V_297 , V_36 ) ;
return;
}
F_468 ( V_5 -> V_47 -> V_48 [ V_474 ] , V_36 ) ;
F_151 ( & V_5 -> V_37 , V_36 ) ;
F_152 ( & V_5 -> V_9 , V_36 ) ;
}
static int T_17 F_469 ( char * V_492 )
{
char * V_493 ;
while ( ( V_493 = F_470 ( & V_492 , L_56 ) ) != NULL ) {
if ( ! * V_493 )
continue;
if ( ! strcmp ( V_493 , L_57 ) )
V_424 = true ;
if ( ! strcmp ( V_493 , L_58 ) )
V_305 = true ;
}
return 0 ;
}
static int T_17 F_471 ( void )
{
int V_46 , V_153 ;
F_472 ( F_165 , 0 ) ;
F_44 (cpu)
F_211 ( & F_473 ( & V_196 , V_46 ) -> V_204 ,
F_153 ) ;
F_35 (node) {
struct V_19 * V_494 ;
V_494 = F_347 ( sizeof( * V_494 ) , V_216 ,
F_474 ( V_153 ) ? V_153 : V_495 ) ;
V_494 -> V_27 = V_496 ;
F_356 ( & V_494 -> V_35 ) ;
V_20 . V_21 [ V_153 ] = V_494 ;
}
return 0 ;
}
static struct V_4 * F_475 ( struct V_4 * V_5 )
{
while ( ! F_476 ( & V_5 -> V_244 . V_413 ) ) {
if ( F_342 ( V_5 == V_6 ) ) {
F_54 ( 1 ) ;
break;
}
V_5 = F_15 ( V_5 ) ;
if ( ! V_5 )
V_5 = V_6 ;
}
return V_5 ;
}
void F_477 ( struct V_11 * V_11 , T_6 V_265 )
{
struct V_4 * V_5 , * V_497 ;
unsigned short V_498 ;
F_50 ( F_190 ( V_11 ) , V_11 ) ;
F_50 ( F_458 ( V_11 ) , V_11 ) ;
if ( ! F_1 () )
return;
V_5 = V_11 -> V_4 ;
if ( ! V_5 )
return;
V_497 = F_475 ( V_5 ) ;
V_498 = F_478 ( V_265 , F_229 ( V_497 ) ) ;
F_50 ( V_498 , V_11 ) ;
F_226 ( V_497 , true ) ;
V_11 -> V_4 = NULL ;
if ( ! F_6 ( V_5 ) )
F_151 ( & V_5 -> V_37 , 1 ) ;
if ( V_5 != V_497 ) {
if ( ! F_6 ( V_497 ) )
F_181 ( & V_497 -> V_116 , 1 ) ;
F_151 ( & V_5 -> V_116 , 1 ) ;
}
F_54 ( ! F_479 () ) ;
F_47 ( V_5 , V_11 , false , - 1 ) ;
F_62 ( V_5 , V_11 ) ;
if ( ! F_6 ( V_5 ) )
F_76 ( & V_5 -> V_9 ) ;
}
int F_480 ( struct V_11 * V_11 , T_6 V_265 )
{
struct V_4 * V_5 ;
struct V_222 * V_223 ;
unsigned short V_498 ;
if ( ! F_2 ( V_1 ) || ! V_2 )
return 0 ;
V_5 = V_11 -> V_4 ;
if ( ! V_5 )
return 0 ;
V_5 = F_475 ( V_5 ) ;
if ( ! F_6 ( V_5 ) &&
! F_174 ( & V_5 -> V_137 , 1 , & V_223 ) ) {
F_340 ( V_5 ) ;
return - V_239 ;
}
V_498 = F_478 ( V_265 , F_229 ( V_5 ) ) ;
F_50 ( V_498 , V_11 ) ;
F_226 ( V_5 , true ) ;
return 0 ;
}
void F_453 ( T_6 V_265 )
{
struct V_4 * V_5 ;
unsigned short V_244 ;
if ( ! V_2 )
return;
V_244 = F_478 ( V_265 , 0 ) ;
F_13 () ;
V_5 = F_341 ( V_244 ) ;
if ( V_5 ) {
if ( ! F_6 ( V_5 ) ) {
if ( F_2 ( V_1 ) )
F_151 ( & V_5 -> V_137 , 1 ) ;
else
F_151 ( & V_5 -> V_116 , 1 ) ;
}
F_226 ( V_5 , false ) ;
F_340 ( V_5 ) ;
}
F_17 () ;
}
long F_481 ( struct V_4 * V_5 )
{
long V_499 = F_482 () ;
if ( ! V_2 || ! F_2 ( V_1 ) )
return V_499 ;
for (; V_5 != V_6 ; V_5 = F_15 ( V_5 ) )
V_499 = F_483 ( long , V_499 ,
F_14 ( V_5 -> V_137 . V_115 ) -
F_32 ( & V_5 -> V_137 ) ) ;
return V_499 ;
}
bool F_484 ( struct V_11 * V_11 )
{
struct V_4 * V_5 ;
F_50 ( ! F_450 ( V_11 ) , V_11 ) ;
if ( F_485 () )
return true ;
if ( ! V_2 || ! F_2 ( V_1 ) )
return false ;
V_5 = V_11 -> V_4 ;
if ( ! V_5 )
return false ;
for (; V_5 != V_6 ; V_5 = F_15 ( V_5 ) )
if ( F_32 ( & V_5 -> V_137 ) * 2 >= V_5 -> V_137 . V_115 )
return true ;
return false ;
}
static int T_17 F_486 ( char * V_492 )
{
if ( ! strcmp ( V_492 , L_59 ) )
V_500 = 1 ;
else if ( ! strcmp ( V_492 , L_60 ) )
V_500 = 0 ;
return 1 ;
}
static V_126 F_487 ( struct V_7 * V_9 ,
struct V_286 * V_287 )
{
struct V_4 * V_5 = F_67 ( V_9 ) ;
return ( V_126 ) F_32 ( & V_5 -> V_137 ) * V_238 ;
}
static int F_488 ( struct V_316 * V_317 , void * V_318 )
{
struct V_4 * V_5 = F_67 ( F_274 ( V_317 ) ) ;
unsigned long F_173 = F_14 ( V_5 -> V_137 . V_115 ) ;
if ( F_173 == V_326 )
F_438 ( V_317 , L_36 ) ;
else
F_276 ( V_317 , L_37 , ( V_126 ) F_173 * V_238 ) ;
return 0 ;
}
static T_7 F_489 ( struct V_281 * V_282 ,
char * V_283 , T_8 V_284 , T_9 V_285 )
{
struct V_4 * V_5 = F_67 ( F_243 ( V_282 ) ) ;
unsigned long F_173 ;
int V_245 ;
V_283 = F_266 ( V_283 ) ;
V_245 = F_267 ( V_283 , L_38 , & F_173 ) ;
if ( V_245 )
return V_245 ;
F_115 ( & V_274 ) ;
V_245 = F_233 ( & V_5 -> V_137 , F_173 ) ;
F_117 ( & V_274 ) ;
if ( V_245 )
return V_245 ;
return V_284 ;
}
static int T_17 F_490 ( void )
{
if ( ! F_72 () && V_500 ) {
V_2 = 1 ;
F_262 ( F_491 ( & V_1 ,
V_501 ) ) ;
F_262 ( F_492 ( & V_1 ,
V_502 ) ) ;
}
return 0 ;
}
