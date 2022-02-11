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
if ( ! V_23 )
return;
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
if ( V_23 )
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
struct V_59 * V_59 = F_54 ( F_55 ( V_17 ) , V_5 ) ;
unsigned long V_60 = 0 ;
enum V_61 V_62 ;
F_56 ( ( unsigned ) V_17 >= V_63 ) ;
F_57 (lru) {
if ( ! ( F_58 ( V_62 ) & V_58 ) )
continue;
V_60 += F_59 ( V_59 , V_62 ) ;
}
return V_60 ;
}
static unsigned long F_60 ( struct V_4 * V_5 ,
unsigned int V_58 )
{
unsigned long V_60 = 0 ;
int V_17 ;
F_61 (nid, N_MEMORY)
V_60 += F_53 ( V_5 , V_17 , V_58 ) ;
return V_60 ;
}
static bool F_62 ( struct V_4 * V_5 ,
enum V_64 V_65 )
{
unsigned long V_45 , V_66 ;
V_45 = F_63 ( V_5 -> V_47 -> V_57 ) ;
V_66 = F_63 ( V_5 -> V_47 -> V_67 [ V_65 ] ) ;
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
F_64 ( V_5 -> V_47 -> V_67 [ V_65 ] , V_66 ) ;
return true ;
}
return false ;
}
static void F_65 ( struct V_4 * V_5 , struct V_11 * V_11 )
{
if ( F_66 ( F_62 ( V_5 ,
V_68 ) ) ) {
bool V_74 ;
bool T_2 V_75 ;
V_74 = F_62 ( V_5 ,
V_70 ) ;
#if V_76 > 1
T_2 = F_62 ( V_5 ,
V_72 ) ;
#endif
F_67 ( V_5 ) ;
if ( F_66 ( V_74 ) )
F_33 ( V_5 , V_11 ) ;
#if V_76 > 1
if ( F_66 ( T_2 ) )
F_68 ( & V_5 -> V_77 ) ;
#endif
}
}
struct V_4 * F_69 ( struct V_78 * V_26 )
{
if ( F_66 ( ! V_26 ) )
return NULL ;
return F_70 ( F_71 ( V_26 , V_79 ) ) ;
}
static struct V_4 * F_72 ( struct V_80 * V_81 )
{
struct V_4 * V_5 = NULL ;
F_13 () ;
do {
if ( F_66 ( ! V_81 ) )
V_5 = V_6 ;
else {
V_5 = F_69 ( F_73 ( V_81 -> V_82 ) ) ;
if ( F_66 ( ! V_5 ) )
V_5 = V_6 ;
}
} while ( ! F_39 ( & V_5 -> V_9 ) );
F_17 () ;
return V_5 ;
}
struct V_4 * F_74 ( struct V_4 * V_83 ,
struct V_4 * V_84 ,
struct V_85 * V_86 )
{
struct V_87 * V_88 ( V_89 ) ;
struct V_7 * V_9 = NULL ;
struct V_4 * V_5 = NULL ;
struct V_4 * V_90 = NULL ;
if ( F_75 () )
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
if ( ! V_90 || F_76 ( & V_90 -> V_9 ) )
break;
( void ) F_77 ( & V_89 -> V_98 , V_90 , NULL ) ;
}
}
if ( V_90 )
V_9 = & V_90 -> V_9 ;
for (; ; ) {
V_9 = F_78 ( V_9 , & V_83 -> V_9 ) ;
if ( ! V_9 ) {
if ( ! V_84 )
continue;
break;
}
V_5 = F_70 ( V_9 ) ;
if ( V_9 == & V_83 -> V_9 )
break;
if ( F_76 ( V_9 ) )
break;
V_5 = NULL ;
}
if ( V_86 ) {
( void ) F_77 ( & V_89 -> V_98 , V_90 , V_5 ) ;
if ( V_90 )
F_79 ( & V_90 -> V_9 ) ;
if ( ! V_5 )
V_89 -> V_96 ++ ;
else if ( ! V_84 )
V_86 -> V_96 = V_89 -> V_96 ;
}
V_97:
F_17 () ;
V_92:
if ( V_84 && V_84 != V_83 )
F_79 ( & V_84 -> V_9 ) ;
return V_5 ;
}
void F_80 ( struct V_4 * V_83 ,
struct V_4 * V_84 )
{
if ( ! V_83 )
V_83 = V_6 ;
if ( V_84 && V_84 != V_83 )
F_79 ( & V_84 -> V_9 ) ;
}
static void F_81 ( struct V_4 * V_99 )
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
F_77 ( & V_89 -> V_98 ,
V_99 , NULL ) ;
}
}
}
}
int F_82 ( struct V_4 * V_5 ,
int (* F_83)( struct V_78 * , void * ) , void * V_102 )
{
struct V_4 * V_89 ;
int V_103 = 0 ;
F_84 ( V_5 == V_6 ) ;
F_85 (iter, memcg) {
struct V_104 V_105 ;
struct V_78 * V_106 ;
F_86 ( & V_89 -> V_9 , & V_105 ) ;
while ( ! V_103 && ( V_106 = F_87 ( & V_105 ) ) )
V_103 = F_83 ( V_106 , V_102 ) ;
F_88 ( & V_105 ) ;
if ( V_103 ) {
F_80 ( V_5 , V_89 ) ;
break;
}
}
return V_103 ;
}
struct V_59 * F_89 ( struct V_11 * V_11 , struct V_107 * V_93 )
{
struct V_16 * V_22 ;
struct V_4 * V_5 ;
struct V_59 * V_59 ;
if ( F_75 () ) {
V_59 = & V_93 -> V_59 ;
goto V_92;
}
V_5 = V_11 -> V_4 ;
if ( ! V_5 )
V_5 = V_6 ;
V_22 = F_18 ( V_5 , V_11 ) ;
V_59 = & V_22 -> V_59 ;
V_92:
if ( F_66 ( V_59 -> V_93 != V_93 ) )
V_59 -> V_93 = V_93 ;
return V_59 ;
}
void F_90 ( struct V_59 * V_59 , enum V_61 V_62 ,
int V_108 , int V_36 )
{
struct V_16 * V_22 ;
unsigned long * V_109 ;
long V_110 ;
if ( F_75 () )
return;
V_22 = F_5 ( V_59 , struct V_16 , V_59 ) ;
V_109 = & V_22 -> V_111 [ V_108 ] [ V_62 ] ;
if ( V_36 < 0 )
* V_109 += V_36 ;
V_110 = * V_109 ;
if ( F_91 ( V_110 < 0 ,
L_1 ,
V_112 , V_59 , V_62 , V_36 , V_110 ) ) {
F_56 ( 1 ) ;
* V_109 = 0 ;
}
if ( V_36 > 0 )
* V_109 += V_36 ;
}
bool F_92 ( struct V_78 * V_106 , struct V_4 * V_5 )
{
struct V_4 * V_113 ;
struct V_78 * V_26 ;
bool V_103 ;
V_26 = F_93 ( V_106 ) ;
if ( V_26 ) {
V_113 = F_72 ( V_26 -> V_81 ) ;
F_94 ( V_26 ) ;
} else {
F_13 () ;
V_113 = F_69 ( V_106 ) ;
F_95 ( & V_113 -> V_9 ) ;
F_17 () ;
}
V_103 = F_96 ( V_113 , V_5 ) ;
F_79 ( & V_113 -> V_9 ) ;
return V_103 ;
}
static unsigned long F_97 ( struct V_4 * V_5 )
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
V_114 = F_98 ( V_114 , V_115 - V_48 ) ;
else
V_114 = 0 ;
}
return V_114 ;
}
static bool F_99 ( struct V_4 * V_5 )
{
struct V_4 * V_117 ;
struct V_4 * V_118 ;
bool V_103 = false ;
F_100 ( & V_119 . V_35 ) ;
V_117 = V_119 . V_117 ;
V_118 = V_119 . V_118 ;
if ( ! V_117 )
goto V_120;
V_103 = F_96 ( V_117 , V_5 ) ||
F_96 ( V_118 , V_5 ) ;
V_120:
F_101 ( & V_119 . V_35 ) ;
return V_103 ;
}
static bool F_102 ( struct V_4 * V_5 )
{
if ( V_119 . V_121 && V_122 != V_119 . V_121 ) {
if ( F_99 ( V_5 ) ) {
F_103 ( V_123 ) ;
F_104 ( & V_119 . V_124 , & V_123 , V_125 ) ;
if ( V_119 . V_121 )
F_105 () ;
F_106 ( & V_119 . V_124 , & V_123 ) ;
return true ;
}
}
return false ;
}
void F_107 ( struct V_4 * V_5 , struct V_78 * V_26 )
{
struct V_4 * V_89 ;
unsigned int V_100 ;
F_13 () ;
if ( V_26 ) {
F_108 ( L_2 ) ;
F_109 ( F_110 ( V_26 , V_79 ) ) ;
F_111 ( L_3 ) ;
} else {
F_108 ( L_4 ) ;
}
F_109 ( V_5 -> V_9 . V_15 ) ;
F_111 ( L_5 ) ;
F_17 () ;
F_108 ( L_6 ,
F_112 ( ( V_126 ) F_32 ( & V_5 -> V_37 ) ) ,
F_112 ( ( V_126 ) V_5 -> V_37 . V_115 ) , V_5 -> V_37 . V_127 ) ;
F_108 ( L_7 ,
F_112 ( ( V_126 ) F_32 ( & V_5 -> V_116 ) ) ,
F_112 ( ( V_126 ) V_5 -> V_116 . V_115 ) , V_5 -> V_116 . V_127 ) ;
F_108 ( L_8 ,
F_112 ( ( V_126 ) F_32 ( & V_5 -> V_128 ) ) ,
F_112 ( ( V_126 ) V_5 -> V_128 . V_115 ) , V_5 -> V_128 . V_127 ) ;
F_85 (iter, memcg) {
F_108 ( L_9 ) ;
F_109 ( V_89 -> V_9 . V_15 ) ;
F_111 ( L_10 ) ;
for ( V_100 = 0 ; V_100 < V_129 ; V_100 ++ ) {
if ( V_100 == V_130 && ! V_2 )
continue;
F_111 ( L_11 , V_131 [ V_100 ] ,
F_112 ( F_43 ( V_89 , V_100 ) ) ) ;
}
for ( V_100 = 0 ; V_100 < V_132 ; V_100 ++ )
F_111 ( L_11 , V_133 [ V_100 ] ,
F_112 ( F_60 ( V_89 , F_58 ( V_100 ) ) ) ) ;
F_111 ( L_5 ) ;
}
}
static int F_113 ( struct V_4 * V_5 )
{
int V_134 = 0 ;
struct V_4 * V_89 ;
F_85 (iter, memcg)
V_134 ++ ;
return V_134 ;
}
unsigned long F_114 ( struct V_4 * V_5 )
{
unsigned long V_115 ;
V_115 = V_5 -> V_37 . V_115 ;
if ( F_115 ( V_5 ) ) {
unsigned long V_135 ;
unsigned long V_136 ;
V_135 = V_5 -> V_116 . V_115 ;
V_136 = V_5 -> V_137 . V_115 ;
V_136 = F_98 ( V_136 , ( unsigned long ) V_138 ) ;
V_115 = F_98 ( V_115 + V_136 , V_135 ) ;
}
return V_115 ;
}
static bool F_116 ( struct V_4 * V_5 , T_3 V_139 ,
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
F_117 ( & V_145 ) ;
V_103 = F_118 ( & V_142 ) ;
F_119 ( & V_145 ) ;
return V_103 ;
}
static bool F_120 ( struct V_4 * V_5 ,
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
static void F_121 ( struct V_4 * V_5 )
{
int V_17 ;
if ( ! F_122 ( & V_5 -> V_77 ) )
return;
if ( F_123 ( & V_5 -> V_149 ) > 1 )
return;
V_5 -> V_150 = V_151 [ V_152 ] ;
F_124 (nid, node_states[N_MEMORY]) {
if ( ! F_120 ( V_5 , V_17 , false ) )
F_125 ( V_17 , V_5 -> V_150 ) ;
}
F_126 ( & V_5 -> V_77 , 0 ) ;
F_126 ( & V_5 -> V_149 , 0 ) ;
}
int F_127 ( struct V_4 * V_5 )
{
int V_153 ;
F_121 ( V_5 ) ;
V_153 = V_5 -> V_154 ;
V_153 = F_128 ( V_153 , V_5 -> V_150 ) ;
if ( F_66 ( V_153 == V_76 ) )
V_153 = F_129 () ;
V_5 -> V_154 = V_153 ;
return V_153 ;
}
int F_127 ( struct V_4 * V_5 )
{
return 0 ;
}
static int F_130 ( struct V_4 * V_155 ,
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
V_157 = F_74 ( V_155 , V_157 , & V_86 ) ;
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
V_158 += F_131 ( V_157 , V_139 , false ,
V_93 , & V_160 ) ;
* V_156 += V_160 ;
if ( ! F_31 ( V_155 ) )
break;
}
F_80 ( V_155 , V_157 ) ;
return V_158 ;
}
static bool F_132 ( struct V_4 * V_5 )
{
struct V_4 * V_89 , * V_162 = NULL ;
F_100 ( & V_163 ) ;
F_85 (iter, memcg) {
if ( V_89 -> V_145 ) {
V_162 = V_89 ;
F_80 ( V_5 , V_89 ) ;
break;
} else
V_89 -> V_145 = true ;
}
if ( V_162 ) {
F_85 (iter, memcg) {
if ( V_89 == V_162 ) {
F_80 ( V_5 , V_89 ) ;
break;
}
V_89 -> V_145 = false ;
}
} else
F_133 ( & V_164 , 0 , 1 , V_165 ) ;
F_101 ( & V_163 ) ;
return ! V_162 ;
}
static void F_134 ( struct V_4 * V_5 )
{
struct V_4 * V_89 ;
F_100 ( & V_163 ) ;
F_135 ( & V_164 , 1 , V_165 ) ;
F_85 (iter, memcg)
V_89 -> V_145 = false ;
F_101 ( & V_163 ) ;
}
static void F_136 ( struct V_4 * V_5 )
{
struct V_4 * V_89 ;
F_100 ( & V_163 ) ;
F_85 (iter, memcg)
V_89 -> V_166 ++ ;
F_101 ( & V_163 ) ;
}
static void F_137 ( struct V_4 * V_5 )
{
struct V_4 * V_89 ;
F_100 ( & V_163 ) ;
F_85 (iter, memcg)
if ( V_89 -> V_166 > 0 )
V_89 -> V_166 -- ;
F_101 ( & V_163 ) ;
}
static int F_138 ( T_5 * V_123 ,
unsigned V_167 , int V_168 , void * V_102 )
{
struct V_4 * V_169 = (struct V_4 * ) V_102 ;
struct V_4 * V_170 ;
struct V_171 * V_171 ;
V_171 = F_5 ( V_123 , struct V_171 , V_123 ) ;
V_170 = V_171 -> V_5 ;
if ( ! F_96 ( V_169 , V_170 ) &&
! F_96 ( V_170 , V_169 ) )
return 0 ;
return F_139 ( V_123 , V_167 , V_168 , V_102 ) ;
}
static void F_140 ( struct V_4 * V_5 )
{
if ( V_5 && V_5 -> V_166 )
F_141 ( & V_172 , V_173 , 0 , V_5 ) ;
}
static void F_142 ( struct V_4 * V_5 , T_3 V_174 , int V_140 )
{
if ( ! V_122 -> V_175 )
return;
F_95 ( & V_5 -> V_9 ) ;
V_122 -> V_176 = V_5 ;
V_122 -> V_177 = V_174 ;
V_122 -> V_178 = V_140 ;
}
bool F_143 ( bool V_179 )
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
V_180 . V_123 . V_183 = F_138 ;
V_180 . V_123 . V_184 = V_122 ;
F_144 ( & V_180 . V_123 . V_185 ) ;
F_104 ( & V_172 , & V_180 . V_123 , V_186 ) ;
F_136 ( V_5 ) ;
V_181 = F_132 ( V_5 ) ;
if ( V_181 )
F_145 ( V_5 ) ;
if ( V_181 && ! V_5 -> V_187 ) {
F_137 ( V_5 ) ;
F_106 ( & V_172 , & V_180 . V_123 ) ;
F_116 ( V_5 , V_122 -> V_177 ,
V_122 -> V_178 ) ;
} else {
F_105 () ;
F_137 ( V_5 ) ;
F_106 ( & V_172 , & V_180 . V_123 ) ;
}
if ( V_181 ) {
F_134 ( V_5 ) ;
F_140 ( V_5 ) ;
}
V_182:
V_122 -> V_176 = NULL ;
F_79 ( & V_5 -> V_9 ) ;
return true ;
}
void F_146 ( struct V_11 * V_11 )
{
struct V_4 * V_5 ;
unsigned long V_13 ;
F_13 () ;
if ( F_75 () )
return;
V_188:
V_5 = V_11 -> V_4 ;
if ( F_66 ( ! V_5 ) )
return;
if ( F_122 ( & V_5 -> V_189 ) <= 0 )
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
void F_147 ( struct V_11 * V_11 )
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
static bool F_148 ( struct V_4 * V_5 , unsigned int V_36 )
{
struct V_193 * V_194 ;
unsigned long V_13 ;
bool V_103 = false ;
if ( V_36 > V_195 )
return V_103 ;
F_149 ( V_13 ) ;
V_194 = F_150 ( & V_196 ) ;
if ( V_5 == V_194 -> V_197 && V_194 -> V_36 >= V_36 ) {
V_194 -> V_36 -= V_36 ;
V_103 = true ;
}
F_151 ( V_13 ) ;
return V_103 ;
}
static void F_152 ( struct V_193 * V_194 )
{
struct V_4 * V_198 = V_194 -> V_197 ;
if ( V_194 -> V_36 ) {
F_153 ( & V_198 -> V_37 , V_194 -> V_36 ) ;
if ( F_1 () )
F_153 ( & V_198 -> V_116 , V_194 -> V_36 ) ;
F_154 ( & V_198 -> V_9 , V_194 -> V_36 ) ;
V_194 -> V_36 = 0 ;
}
V_194 -> V_197 = NULL ;
}
static void F_155 ( struct V_199 * V_200 )
{
struct V_193 * V_194 ;
unsigned long V_13 ;
F_149 ( V_13 ) ;
V_194 = F_150 ( & V_196 ) ;
F_152 ( V_194 ) ;
F_156 ( V_201 , & V_194 -> V_13 ) ;
F_151 ( V_13 ) ;
}
static void F_157 ( struct V_4 * V_5 , unsigned int V_36 )
{
struct V_193 * V_194 ;
unsigned long V_13 ;
F_149 ( V_13 ) ;
V_194 = F_150 ( & V_196 ) ;
if ( V_194 -> V_197 != V_5 ) {
F_152 ( V_194 ) ;
V_194 -> V_197 = V_5 ;
}
V_194 -> V_36 += V_36 ;
F_151 ( V_13 ) ;
}
static void F_158 ( struct V_4 * V_155 )
{
int V_46 , V_202 ;
if ( ! F_159 ( & V_203 ) )
return;
F_160 () ;
V_202 = F_161 () ;
F_162 (cpu) {
struct V_193 * V_194 = & F_45 ( V_196 , V_46 ) ;
struct V_4 * V_5 ;
V_5 = V_194 -> V_197 ;
if ( ! V_5 || ! V_194 -> V_36 )
continue;
if ( ! F_96 ( V_5 , V_155 ) )
continue;
if ( ! F_163 ( V_201 , & V_194 -> V_13 ) ) {
if ( V_46 == V_202 )
F_155 ( & V_194 -> V_204 ) ;
else
F_164 ( V_46 , & V_194 -> V_204 ) ;
}
}
F_165 () ;
F_166 () ;
F_119 ( & V_203 ) ;
}
static int F_167 ( unsigned int V_46 )
{
struct V_193 * V_194 ;
V_194 = & F_45 ( V_196 , V_46 ) ;
F_152 ( V_194 ) ;
return 0 ;
}
static void F_168 ( struct V_4 * V_5 ,
unsigned int V_36 ,
T_3 V_139 )
{
do {
if ( F_32 ( & V_5 -> V_37 ) <= V_5 -> V_205 )
continue;
F_169 ( V_5 , V_206 , 1 ) ;
F_170 ( V_5 , V_36 , V_139 , true ) ;
} while ( ( V_5 = F_15 ( V_5 ) ) );
}
static void F_171 ( struct V_199 * V_204 )
{
struct V_4 * V_5 ;
V_5 = F_5 ( V_204 , struct V_4 , V_207 ) ;
F_168 ( V_5 , V_195 , V_208 ) ;
}
void F_172 ( void )
{
unsigned int V_36 = V_122 -> V_209 ;
struct V_4 * V_5 ;
if ( F_173 ( ! V_36 ) )
return;
V_5 = F_72 ( V_122 -> V_81 ) ;
F_168 ( V_5 , V_36 , V_208 ) ;
F_79 ( & V_5 -> V_9 ) ;
V_122 -> V_209 = 0 ;
}
static int F_174 ( struct V_4 * V_5 , T_3 V_139 ,
unsigned int V_36 )
{
unsigned int V_210 = F_175 ( V_195 , V_36 ) ;
int V_211 = V_212 ;
struct V_4 * V_213 ;
struct V_214 * V_215 ;
unsigned long V_216 ;
bool V_217 = true ;
bool V_218 = false ;
if ( F_6 ( V_5 ) )
return 0 ;
V_41:
if ( F_148 ( V_5 , V_36 ) )
return 0 ;
if ( ! F_1 () ||
F_176 ( & V_5 -> V_116 , V_210 , & V_215 ) ) {
if ( F_176 ( & V_5 -> V_37 , V_210 , & V_215 ) )
goto V_219;
if ( F_1 () )
F_153 ( & V_5 -> V_116 , V_210 ) ;
V_213 = F_177 ( V_215 , V_37 ) ;
} else {
V_213 = F_177 ( V_215 , V_116 ) ;
V_217 = false ;
}
if ( V_210 > V_36 ) {
V_210 = V_36 ;
goto V_41;
}
if ( F_66 ( F_178 ( V_220 ) ||
F_179 ( V_122 ) ||
V_122 -> V_13 & V_221 ) )
goto V_222;
if ( F_66 ( V_122 -> V_13 & V_223 ) )
goto V_222;
if ( F_66 ( F_180 ( V_122 ) ) )
goto V_224;
if ( ! F_181 ( V_139 ) )
goto V_224;
F_169 ( V_213 , V_225 , 1 ) ;
V_216 = F_170 ( V_213 , V_36 ,
V_139 , V_217 ) ;
if ( F_97 ( V_213 ) >= V_36 )
goto V_41;
if ( ! V_218 ) {
F_158 ( V_213 ) ;
V_218 = true ;
goto V_41;
}
if ( V_139 & V_226 )
goto V_224;
if ( V_216 && V_36 <= ( 1 << V_227 ) )
goto V_41;
if ( F_102 ( V_213 ) )
goto V_41;
if ( V_211 -- )
goto V_41;
if ( V_139 & V_228 )
goto V_222;
if ( F_179 ( V_122 ) )
goto V_222;
F_169 ( V_213 , V_229 , 1 ) ;
F_142 ( V_213 , V_139 ,
F_182 ( V_36 * V_230 ) ) ;
V_224:
if ( ! ( V_139 & V_228 ) )
return - V_231 ;
V_222:
F_183 ( & V_5 -> V_37 , V_36 ) ;
if ( F_1 () )
F_183 ( & V_5 -> V_116 , V_36 ) ;
F_184 ( & V_5 -> V_9 , V_36 ) ;
return 0 ;
V_219:
F_184 ( & V_5 -> V_9 , V_210 ) ;
if ( V_210 > V_36 )
F_157 ( V_5 , V_210 - V_36 ) ;
do {
if ( F_32 ( & V_5 -> V_37 ) > V_5 -> V_205 ) {
if ( F_185 () ) {
F_186 ( & V_5 -> V_207 ) ;
break;
}
V_122 -> V_209 += V_210 ;
F_187 ( V_122 ) ;
break;
}
} while ( ( V_5 = F_15 ( V_5 ) ) );
return 0 ;
}
static void F_188 ( struct V_4 * V_5 , unsigned int V_36 )
{
if ( F_6 ( V_5 ) )
return;
F_153 ( & V_5 -> V_37 , V_36 ) ;
if ( F_1 () )
F_153 ( & V_5 -> V_116 , V_36 ) ;
F_154 ( & V_5 -> V_9 , V_36 ) ;
}
static void F_189 ( struct V_11 * V_11 , int * V_232 )
{
struct V_233 * V_233 = F_190 ( V_11 ) ;
F_41 ( F_191 ( V_233 ) ) ;
if ( F_192 ( V_11 ) ) {
struct V_59 * V_59 ;
V_59 = F_89 ( V_11 , V_233 -> V_234 ) ;
F_193 ( V_11 ) ;
F_194 ( V_11 , V_59 , F_195 ( V_11 ) ) ;
* V_232 = 1 ;
} else
* V_232 = 0 ;
}
static void F_196 ( struct V_11 * V_11 , int V_232 )
{
struct V_233 * V_233 = F_190 ( V_11 ) ;
if ( V_232 ) {
struct V_59 * V_59 ;
V_59 = F_89 ( V_11 , V_233 -> V_234 ) ;
F_50 ( F_192 ( V_11 ) , V_11 ) ;
F_197 ( V_11 ) ;
F_198 ( V_11 , V_59 , F_195 ( V_11 ) ) ;
}
F_42 ( F_191 ( V_233 ) ) ;
}
static void F_199 ( struct V_11 * V_11 , struct V_4 * V_5 ,
bool V_235 )
{
int V_232 ;
F_50 ( V_11 -> V_4 , V_11 ) ;
if ( V_235 )
F_189 ( V_11 , & V_232 ) ;
V_11 -> V_4 = V_5 ;
if ( V_235 )
F_196 ( V_11 , V_232 ) ;
}
static int F_200 ( void )
{
int V_236 , V_110 ;
int V_237 ;
V_236 = F_201 ( & V_238 ,
0 , V_239 , V_208 ) ;
if ( V_236 < 0 )
return V_236 ;
if ( V_236 < V_240 )
return V_236 ;
F_202 ( & V_10 ) ;
V_110 = 2 * ( V_236 + 1 ) ;
if ( V_110 < V_241 )
V_110 = V_241 ;
else if ( V_110 > V_239 )
V_110 = V_239 ;
V_237 = F_203 ( V_110 ) ;
if ( ! V_237 )
V_237 = F_204 ( V_110 ) ;
if ( ! V_237 )
V_240 = V_110 ;
F_205 ( & V_10 ) ;
if ( V_237 ) {
F_206 ( & V_238 , V_236 ) ;
return V_237 ;
}
return V_236 ;
}
static void F_207 ( int V_236 )
{
F_206 ( & V_238 , V_236 ) ;
}
static void F_208 ( struct V_199 * V_242 )
{
struct V_243 * V_244 =
F_5 ( V_242 , struct V_243 , V_204 ) ;
struct V_4 * V_5 = V_244 -> V_5 ;
struct V_245 * V_246 = V_244 -> V_246 ;
F_209 ( V_5 , V_246 ) ;
F_79 ( & V_5 -> V_9 ) ;
F_210 ( V_244 ) ;
}
static void F_211 ( struct V_4 * V_5 ,
struct V_245 * V_246 )
{
struct V_243 * V_244 ;
V_244 = F_212 ( sizeof( * V_244 ) , V_247 ) ;
if ( ! V_244 )
return;
F_95 ( & V_5 -> V_9 ) ;
V_244 -> V_5 = V_5 ;
V_244 -> V_246 = V_246 ;
F_213 ( & V_244 -> V_204 , F_208 ) ;
F_214 ( V_248 , & V_244 -> V_204 ) ;
}
static void F_215 ( struct V_4 * V_5 ,
struct V_245 * V_246 )
{
V_122 -> V_249 = 1 ;
F_211 ( V_5 , V_246 ) ;
V_122 -> V_249 = 0 ;
}
static inline bool F_216 ( void )
{
if ( F_185 () || ! V_122 -> V_81 || ( V_122 -> V_13 & V_250 ) )
return true ;
return false ;
}
struct V_245 * F_217 ( struct V_245 * V_246 )
{
struct V_4 * V_5 ;
struct V_245 * V_251 ;
int V_252 ;
F_56 ( ! F_218 ( V_246 ) ) ;
if ( F_216 () )
return V_246 ;
if ( V_122 -> V_249 )
return V_246 ;
V_5 = F_72 ( V_122 -> V_81 ) ;
V_252 = F_14 ( V_5 -> V_252 ) ;
if ( V_252 < 0 )
goto V_92;
V_251 = F_219 ( V_246 , V_252 ) ;
if ( F_173 ( V_251 ) )
return V_251 ;
F_215 ( V_5 , V_246 ) ;
V_92:
F_79 ( & V_5 -> V_9 ) ;
return V_246 ;
}
void F_220 ( struct V_245 * V_246 )
{
if ( ! F_218 ( V_246 ) )
F_79 ( & V_246 -> V_253 . V_5 -> V_9 ) ;
}
int F_221 ( struct V_11 * V_11 , T_3 V_254 , int V_140 ,
struct V_4 * V_5 )
{
unsigned int V_36 = 1 << V_140 ;
struct V_214 * V_215 ;
int V_103 ;
V_103 = F_174 ( V_5 , V_254 , V_36 ) ;
if ( V_103 )
return V_103 ;
if ( ! F_2 ( V_1 ) &&
! F_176 ( & V_5 -> V_128 , V_36 , & V_215 ) ) {
F_188 ( V_5 , V_36 ) ;
return - V_231 ;
}
V_11 -> V_4 = V_5 ;
return 0 ;
}
int F_222 ( struct V_11 * V_11 , T_3 V_254 , int V_140 )
{
struct V_4 * V_5 ;
int V_103 = 0 ;
if ( F_216 () )
return 0 ;
V_5 = F_72 ( V_122 -> V_81 ) ;
if ( ! F_6 ( V_5 ) ) {
V_103 = F_221 ( V_11 , V_254 , V_140 , V_5 ) ;
if ( ! V_103 )
F_223 ( V_11 ) ;
}
F_79 ( & V_5 -> V_9 ) ;
return V_103 ;
}
void F_224 ( struct V_11 * V_11 , int V_140 )
{
struct V_4 * V_5 = V_11 -> V_4 ;
unsigned int V_36 = 1 << V_140 ;
if ( ! V_5 )
return;
F_50 ( F_6 ( V_5 ) , V_11 ) ;
if ( ! F_2 ( V_1 ) )
F_153 ( & V_5 -> V_128 , V_36 ) ;
F_153 ( & V_5 -> V_37 , V_36 ) ;
if ( F_1 () )
F_153 ( & V_5 -> V_116 , V_36 ) ;
V_11 -> V_4 = NULL ;
if ( F_225 ( V_11 ) )
F_226 ( V_11 ) ;
F_154 ( & V_5 -> V_9 , V_36 ) ;
}
void F_227 ( struct V_11 * V_255 )
{
int V_100 ;
if ( F_75 () )
return;
for ( V_100 = 1 ; V_100 < V_256 ; V_100 ++ )
V_255 [ V_100 ] . V_4 = V_255 -> V_4 ;
F_228 ( V_255 -> V_4 -> V_47 -> V_48 [ V_54 ] ,
V_256 ) ;
}
static void F_229 ( struct V_4 * V_5 ,
bool V_257 )
{
int V_45 = ( V_257 ) ? 1 : - 1 ;
F_230 ( V_5 -> V_47 -> V_48 [ V_130 ] , V_45 ) ;
}
static int F_231 ( T_6 V_258 ,
struct V_4 * V_117 , struct V_4 * V_118 )
{
unsigned short V_259 , V_260 ;
V_259 = F_232 ( V_117 ) ;
V_260 = F_232 ( V_118 ) ;
if ( F_233 ( V_258 , V_259 , V_260 ) == V_259 ) {
F_229 ( V_117 , false ) ;
F_229 ( V_118 , true ) ;
return 0 ;
}
return - V_261 ;
}
static inline int F_231 ( T_6 V_258 ,
struct V_4 * V_117 , struct V_4 * V_118 )
{
return - V_261 ;
}
static int F_234 ( struct V_4 * V_5 ,
unsigned long V_115 )
{
unsigned long V_262 ;
unsigned long V_263 ;
bool V_264 = false ;
int V_265 ;
int V_103 ;
V_265 = V_212 *
F_113 ( V_5 ) ;
V_263 = F_32 ( & V_5 -> V_37 ) ;
do {
if ( F_235 ( V_122 ) ) {
V_103 = - V_266 ;
break;
}
F_117 ( & V_267 ) ;
if ( V_115 > V_5 -> V_116 . V_115 ) {
F_119 ( & V_267 ) ;
V_103 = - V_261 ;
break;
}
if ( V_115 > V_5 -> V_37 . V_115 )
V_264 = true ;
V_103 = F_236 ( & V_5 -> V_37 , V_115 ) ;
F_119 ( & V_267 ) ;
if ( ! V_103 )
break;
F_170 ( V_5 , 1 , V_208 , true ) ;
V_262 = F_32 ( & V_5 -> V_37 ) ;
if ( V_262 >= V_263 )
V_265 -- ;
else
V_263 = V_262 ;
} while ( V_265 );
if ( ! V_103 && V_264 )
F_140 ( V_5 ) ;
return V_103 ;
}
static int F_237 ( struct V_4 * V_5 ,
unsigned long V_115 )
{
unsigned long V_262 ;
unsigned long V_263 ;
bool V_264 = false ;
int V_265 ;
int V_103 ;
V_265 = V_212 *
F_113 ( V_5 ) ;
V_263 = F_32 ( & V_5 -> V_116 ) ;
do {
if ( F_235 ( V_122 ) ) {
V_103 = - V_266 ;
break;
}
F_117 ( & V_267 ) ;
if ( V_115 < V_5 -> V_37 . V_115 ) {
F_119 ( & V_267 ) ;
V_103 = - V_261 ;
break;
}
if ( V_115 > V_5 -> V_116 . V_115 )
V_264 = true ;
V_103 = F_236 ( & V_5 -> V_116 , V_115 ) ;
F_119 ( & V_267 ) ;
if ( ! V_103 )
break;
F_170 ( V_5 , 1 , V_208 , false ) ;
V_262 = F_32 ( & V_5 -> V_116 ) ;
if ( V_262 >= V_263 )
V_265 -- ;
else
V_263 = V_262 ;
} while ( V_265 );
if ( ! V_103 && V_264 )
F_140 ( V_5 ) ;
return V_103 ;
}
unsigned long F_238 ( T_4 * V_93 , int V_140 ,
T_3 V_139 ,
unsigned long * V_156 )
{
unsigned long V_216 = 0 ;
struct V_16 * V_22 , * V_268 = NULL ;
unsigned long V_269 ;
int V_159 = 0 ;
struct V_19 * V_23 ;
unsigned long V_39 ;
unsigned long V_160 ;
if ( V_140 > 0 )
return 0 ;
V_23 = F_20 ( V_93 -> V_94 ) ;
if ( ! V_23 || F_239 ( & V_23 -> V_27 ) )
return 0 ;
do {
if ( V_268 )
V_22 = V_268 ;
else
V_22 = F_40 ( V_23 ) ;
if ( ! V_22 )
break;
V_160 = 0 ;
V_269 = F_130 ( V_22 -> V_5 , V_93 ,
V_139 , & V_160 ) ;
V_216 += V_269 ;
* V_156 += V_160 ;
F_41 ( & V_23 -> V_35 ) ;
F_26 ( V_22 , V_23 ) ;
V_268 = NULL ;
if ( ! V_269 )
V_268 = F_37 ( V_23 ) ;
V_39 = F_31 ( V_22 -> V_5 ) ;
F_22 ( V_22 , V_23 , V_39 ) ;
F_42 ( & V_23 -> V_35 ) ;
F_79 ( & V_22 -> V_5 -> V_9 ) ;
V_159 ++ ;
if ( ! V_216 &&
( V_268 == NULL ||
V_159 > V_270 ) )
break;
} while ( ! V_216 );
if ( V_268 )
F_79 ( & V_268 -> V_5 -> V_9 ) ;
return V_216 ;
}
static inline bool F_240 ( struct V_4 * V_5 )
{
bool V_103 ;
F_13 () ;
V_103 = F_241 ( NULL , & V_5 -> V_9 ) ;
F_17 () ;
return V_103 ;
}
static int F_242 ( struct V_4 * V_5 )
{
int V_211 = V_212 ;
F_243 () ;
while ( V_211 && F_32 ( & V_5 -> V_37 ) ) {
int V_271 ;
if ( F_235 ( V_122 ) )
return - V_266 ;
V_271 = F_170 ( V_5 , 1 ,
V_208 , true ) ;
if ( ! V_271 ) {
V_211 -- ;
F_244 ( V_272 , V_273 / 10 ) ;
}
}
return 0 ;
}
static T_7 F_245 ( struct V_274 * V_275 ,
char * V_276 , T_8 V_277 ,
T_9 V_278 )
{
struct V_4 * V_5 = F_70 ( F_246 ( V_275 ) ) ;
if ( F_6 ( V_5 ) )
return - V_261 ;
return F_242 ( V_5 ) ? : V_277 ;
}
static V_126 F_247 ( struct V_7 * V_9 ,
struct V_279 * V_280 )
{
return F_70 ( V_9 ) -> V_91 ;
}
static int F_248 ( struct V_7 * V_9 ,
struct V_279 * V_280 , V_126 V_45 )
{
int V_281 = 0 ;
struct V_4 * V_5 = F_70 ( V_9 ) ;
struct V_4 * V_282 = F_70 ( V_5 -> V_9 . V_28 ) ;
if ( V_5 -> V_91 == V_45 )
return 0 ;
if ( ( ! V_282 || ! V_282 -> V_91 ) &&
( V_45 == 1 || V_45 == 0 ) ) {
if ( ! F_240 ( V_5 ) )
V_5 -> V_91 = V_45 ;
else
V_281 = - V_283 ;
} else
V_281 = - V_261 ;
return V_281 ;
}
static void F_249 ( struct V_4 * V_5 , unsigned long * V_47 )
{
struct V_4 * V_89 ;
int V_100 ;
memset ( V_47 , 0 , sizeof( * V_47 ) * V_284 ) ;
F_85 (iter, memcg) {
for ( V_100 = 0 ; V_100 < V_284 ; V_100 ++ )
V_47 [ V_100 ] += F_43 ( V_89 , V_100 ) ;
}
}
static void F_250 ( struct V_4 * V_5 , unsigned long * V_50 )
{
struct V_4 * V_89 ;
int V_100 ;
memset ( V_50 , 0 , sizeof( * V_50 ) * V_285 ) ;
F_85 (iter, memcg) {
for ( V_100 = 0 ; V_100 < V_285 ; V_100 ++ )
V_50 [ V_100 ] += F_46 ( V_89 , V_100 ) ;
}
}
static unsigned long F_251 ( struct V_4 * V_5 , bool V_137 )
{
unsigned long V_45 = 0 ;
if ( F_6 ( V_5 ) ) {
struct V_4 * V_89 ;
F_85 (iter, memcg) {
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
static V_126 F_252 ( struct V_7 * V_9 ,
struct V_279 * V_280 )
{
struct V_4 * V_5 = F_70 ( V_9 ) ;
struct V_214 * V_215 ;
switch ( F_253 ( V_280 -> V_184 ) ) {
case V_286 :
V_215 = & V_5 -> V_37 ;
break;
case V_287 :
V_215 = & V_5 -> V_116 ;
break;
case V_288 :
V_215 = & V_5 -> V_128 ;
break;
case V_289 :
V_215 = & V_5 -> V_290 ;
break;
default:
F_254 () ;
}
switch ( F_255 ( V_280 -> V_184 ) ) {
case V_291 :
if ( V_215 == & V_5 -> V_37 )
return ( V_126 ) F_251 ( V_5 , false ) * V_230 ;
if ( V_215 == & V_5 -> V_116 )
return ( V_126 ) F_251 ( V_5 , true ) * V_230 ;
return ( V_126 ) F_32 ( V_215 ) * V_230 ;
case V_292 :
return ( V_126 ) V_215 -> V_115 * V_230 ;
case V_293 :
return ( V_126 ) V_215 -> V_294 * V_230 ;
case V_295 :
return V_215 -> V_127 ;
case V_296 :
return ( V_126 ) V_5 -> V_38 * V_230 ;
default:
F_254 () ;
}
}
static int F_256 ( struct V_4 * V_5 )
{
int V_297 ;
if ( V_298 )
return 0 ;
F_84 ( V_5 -> V_252 >= 0 ) ;
F_84 ( V_5 -> V_299 ) ;
V_297 = F_200 () ;
if ( V_297 < 0 )
return V_297 ;
F_257 ( & V_300 ) ;
V_5 -> V_252 = V_297 ;
V_5 -> V_299 = V_301 ;
F_144 ( & V_5 -> V_302 ) ;
return 0 ;
}
static void F_258 ( struct V_4 * V_5 )
{
struct V_7 * V_9 ;
struct V_4 * V_28 , * V_303 ;
int V_252 ;
if ( V_5 -> V_299 != V_301 )
return;
V_5 -> V_299 = V_304 ;
F_259 ( V_5 ) ;
V_252 = V_5 -> V_252 ;
F_84 ( V_252 < 0 ) ;
V_28 = F_15 ( V_5 ) ;
if ( ! V_28 )
V_28 = V_6 ;
F_13 () ;
F_260 (css, &memcg->css) {
V_303 = F_70 ( V_9 ) ;
F_84 ( V_303 -> V_252 != V_252 ) ;
V_303 -> V_252 = V_28 -> V_252 ;
if ( ! V_5 -> V_91 )
break;
}
F_17 () ;
F_261 ( V_252 , V_28 -> V_252 ) ;
F_207 ( V_252 ) ;
}
static void F_262 ( struct V_4 * V_5 )
{
if ( F_66 ( V_5 -> V_299 == V_301 ) )
F_258 ( V_5 ) ;
if ( V_5 -> V_299 == V_304 ) {
F_263 ( V_5 ) ;
F_264 ( & V_300 ) ;
F_265 ( F_32 ( & V_5 -> V_128 ) ) ;
}
}
static int F_256 ( struct V_4 * V_5 )
{
return 0 ;
}
static void F_258 ( struct V_4 * V_5 )
{
}
static void F_262 ( struct V_4 * V_5 )
{
}
static int F_266 ( struct V_4 * V_5 ,
unsigned long V_115 )
{
int V_103 ;
F_117 ( & V_267 ) ;
V_103 = F_236 ( & V_5 -> V_128 , V_115 ) ;
F_119 ( & V_267 ) ;
return V_103 ;
}
static int F_267 ( struct V_4 * V_5 , unsigned long V_115 )
{
int V_103 ;
F_117 ( & V_267 ) ;
V_103 = F_236 ( & V_5 -> V_290 , V_115 ) ;
if ( V_103 )
goto V_92;
if ( ! V_5 -> V_305 ) {
F_257 ( & V_306 ) ;
V_5 -> V_305 = true ;
}
V_92:
F_119 ( & V_267 ) ;
return V_103 ;
}
static T_7 F_268 ( struct V_274 * V_275 ,
char * V_276 , T_8 V_277 , T_9 V_278 )
{
struct V_4 * V_5 = F_70 ( F_246 ( V_275 ) ) ;
unsigned long V_36 ;
int V_103 ;
V_276 = F_269 ( V_276 ) ;
V_103 = F_270 ( V_276 , L_12 , & V_36 ) ;
if ( V_103 )
return V_103 ;
switch ( F_255 ( F_271 ( V_275 ) -> V_184 ) ) {
case V_292 :
if ( F_6 ( V_5 ) ) {
V_103 = - V_261 ;
break;
}
switch ( F_253 ( F_271 ( V_275 ) -> V_184 ) ) {
case V_286 :
V_103 = F_234 ( V_5 , V_36 ) ;
break;
case V_287 :
V_103 = F_237 ( V_5 , V_36 ) ;
break;
case V_288 :
V_103 = F_266 ( V_5 , V_36 ) ;
break;
case V_289 :
V_103 = F_267 ( V_5 , V_36 ) ;
break;
}
break;
case V_296 :
V_5 -> V_38 = V_36 ;
V_103 = 0 ;
break;
}
return V_103 ? : V_277 ;
}
static T_7 F_272 ( struct V_274 * V_275 , char * V_276 ,
T_8 V_277 , T_9 V_278 )
{
struct V_4 * V_5 = F_70 ( F_246 ( V_275 ) ) ;
struct V_214 * V_215 ;
switch ( F_253 ( F_271 ( V_275 ) -> V_184 ) ) {
case V_286 :
V_215 = & V_5 -> V_37 ;
break;
case V_287 :
V_215 = & V_5 -> V_116 ;
break;
case V_288 :
V_215 = & V_5 -> V_128 ;
break;
case V_289 :
V_215 = & V_5 -> V_290 ;
break;
default:
F_254 () ;
}
switch ( F_255 ( F_271 ( V_275 ) -> V_184 ) ) {
case V_293 :
F_273 ( V_215 ) ;
break;
case V_295 :
V_215 -> V_127 = 0 ;
break;
default:
F_254 () ;
}
return V_277 ;
}
static V_126 F_274 ( struct V_7 * V_9 ,
struct V_279 * V_280 )
{
return F_70 ( V_9 ) -> V_307 ;
}
static int F_275 ( struct V_7 * V_9 ,
struct V_279 * V_280 , V_126 V_45 )
{
struct V_4 * V_5 = F_70 ( V_9 ) ;
if ( V_45 & ~ V_308 )
return - V_261 ;
V_5 -> V_307 = V_45 ;
return 0 ;
}
static int F_275 ( struct V_7 * V_9 ,
struct V_279 * V_280 , V_126 V_45 )
{
return - V_309 ;
}
static int F_276 ( struct V_310 * V_311 , void * V_312 )
{
struct V_313 {
const char * V_314 ;
unsigned int V_58 ;
};
static const struct V_313 V_315 [] = {
{ L_13 , V_316 } ,
{ L_14 , V_147 } ,
{ L_15 , V_148 } ,
{ L_16 , F_58 (LRU_UNEVICTABLE) } ,
} ;
const struct V_313 * V_47 ;
int V_17 ;
unsigned long V_60 ;
struct V_4 * V_5 = F_70 ( F_277 ( V_311 ) ) ;
for ( V_47 = V_315 ; V_47 < V_315 + F_278 ( V_315 ) ; V_47 ++ ) {
V_60 = F_60 ( V_5 , V_47 -> V_58 ) ;
F_279 ( V_311 , L_17 , V_47 -> V_314 , V_60 ) ;
F_61 (nid, N_MEMORY) {
V_60 = F_53 ( V_5 , V_17 ,
V_47 -> V_58 ) ;
F_279 ( V_311 , L_18 , V_17 , V_60 ) ;
}
F_280 ( V_311 , '\n' ) ;
}
for ( V_47 = V_315 ; V_47 < V_315 + F_278 ( V_315 ) ; V_47 ++ ) {
struct V_4 * V_89 ;
V_60 = 0 ;
F_85 (iter, memcg)
V_60 += F_60 ( V_89 , V_47 -> V_58 ) ;
F_279 ( V_311 , L_19 , V_47 -> V_314 , V_60 ) ;
F_61 (nid, N_MEMORY) {
V_60 = 0 ;
F_85 (iter, memcg)
V_60 += F_53 (
V_89 , V_17 , V_47 -> V_58 ) ;
F_279 ( V_311 , L_18 , V_17 , V_60 ) ;
}
F_280 ( V_311 , '\n' ) ;
}
return 0 ;
}
static int F_281 ( struct V_310 * V_311 , void * V_312 )
{
struct V_4 * V_5 = F_70 ( F_277 ( V_311 ) ) ;
unsigned long V_37 , V_116 ;
struct V_4 * V_317 ;
unsigned int V_100 ;
F_282 ( F_278 ( V_131 ) !=
V_129 ) ;
F_282 ( F_278 ( V_318 ) !=
V_319 ) ;
F_282 ( F_278 ( V_133 ) != V_132 ) ;
for ( V_100 = 0 ; V_100 < V_129 ; V_100 ++ ) {
if ( V_100 == V_130 && ! F_1 () )
continue;
F_279 ( V_311 , L_20 , V_131 [ V_100 ] ,
F_43 ( V_5 , V_100 ) * V_230 ) ;
}
for ( V_100 = 0 ; V_100 < V_319 ; V_100 ++ )
F_279 ( V_311 , L_20 , V_318 [ V_100 ] ,
F_46 ( V_5 , V_100 ) ) ;
for ( V_100 = 0 ; V_100 < V_132 ; V_100 ++ )
F_279 ( V_311 , L_20 , V_133 [ V_100 ] ,
F_60 ( V_5 , F_58 ( V_100 ) ) * V_230 ) ;
V_37 = V_116 = V_320 ;
for ( V_317 = V_5 ; V_317 ; V_317 = F_15 ( V_317 ) ) {
V_37 = F_98 ( V_37 , V_317 -> V_37 . V_115 ) ;
V_116 = F_98 ( V_116 , V_317 -> V_116 . V_115 ) ;
}
F_279 ( V_311 , L_21 ,
( V_126 ) V_37 * V_230 ) ;
if ( F_1 () )
F_279 ( V_311 , L_22 ,
( V_126 ) V_116 * V_230 ) ;
for ( V_100 = 0 ; V_100 < V_129 ; V_100 ++ ) {
unsigned long long V_45 = 0 ;
if ( V_100 == V_130 && ! F_1 () )
continue;
F_85 (mi, memcg)
V_45 += F_43 ( V_317 , V_100 ) * V_230 ;
F_279 ( V_311 , L_23 , V_131 [ V_100 ] , V_45 ) ;
}
for ( V_100 = 0 ; V_100 < V_319 ; V_100 ++ ) {
unsigned long long V_45 = 0 ;
F_85 (mi, memcg)
V_45 += F_46 ( V_317 , V_100 ) ;
F_279 ( V_311 , L_23 ,
V_318 [ V_100 ] , V_45 ) ;
}
for ( V_100 = 0 ; V_100 < V_132 ; V_100 ++ ) {
unsigned long long V_45 = 0 ;
F_85 (mi, memcg)
V_45 += F_60 ( V_317 , F_58 ( V_100 ) ) * V_230 ;
F_279 ( V_311 , L_23 , V_133 [ V_100 ] , V_45 ) ;
}
#ifdef F_283
{
T_4 * V_93 ;
struct V_16 * V_22 ;
struct V_321 * V_322 ;
unsigned long V_323 [ 2 ] = { 0 , 0 } ;
unsigned long V_324 [ 2 ] = { 0 , 0 } ;
F_284 (pgdat) {
V_22 = F_36 ( V_5 , V_93 -> V_94 ) ;
V_322 = & V_22 -> V_59 . V_325 ;
V_323 [ 0 ] += V_322 -> V_323 [ 0 ] ;
V_323 [ 1 ] += V_322 -> V_323 [ 1 ] ;
V_324 [ 0 ] += V_322 -> V_324 [ 0 ] ;
V_324 [ 1 ] += V_322 -> V_324 [ 1 ] ;
}
F_279 ( V_311 , L_24 , V_323 [ 0 ] ) ;
F_279 ( V_311 , L_25 , V_323 [ 1 ] ) ;
F_279 ( V_311 , L_26 , V_324 [ 0 ] ) ;
F_279 ( V_311 , L_27 , V_324 [ 1 ] ) ;
}
#endif
return 0 ;
}
static V_126 F_285 ( struct V_7 * V_9 ,
struct V_279 * V_280 )
{
struct V_4 * V_5 = F_70 ( V_9 ) ;
return F_115 ( V_5 ) ;
}
static int F_286 ( struct V_7 * V_9 ,
struct V_279 * V_280 , V_126 V_45 )
{
struct V_4 * V_5 = F_70 ( V_9 ) ;
if ( V_45 > 100 )
return - V_261 ;
if ( V_9 -> V_28 )
V_5 -> V_326 = V_45 ;
else
V_327 = V_45 ;
return 0 ;
}
static void F_287 ( struct V_4 * V_5 , bool V_137 )
{
struct V_328 * V_329 ;
unsigned long V_330 ;
int V_100 ;
F_13 () ;
if ( ! V_137 )
V_329 = F_73 ( V_5 -> V_331 . V_332 ) ;
else
V_329 = F_73 ( V_5 -> V_333 . V_332 ) ;
if ( ! V_329 )
goto V_120;
V_330 = F_251 ( V_5 , V_137 ) ;
V_100 = V_329 -> V_334 ;
for (; V_100 >= 0 && F_66 ( V_329 -> V_335 [ V_100 ] . V_336 > V_330 ) ; V_100 -- )
F_288 ( V_329 -> V_335 [ V_100 ] . V_337 , 1 ) ;
V_100 ++ ;
for (; V_100 < V_329 -> V_110 && F_66 ( V_329 -> V_335 [ V_100 ] . V_336 <= V_330 ) ; V_100 ++ )
F_288 ( V_329 -> V_335 [ V_100 ] . V_337 , 1 ) ;
V_329 -> V_334 = V_100 - 1 ;
V_120:
F_17 () ;
}
static void F_67 ( struct V_4 * V_5 )
{
while ( V_5 ) {
F_287 ( V_5 , false ) ;
if ( F_1 () )
F_287 ( V_5 , true ) ;
V_5 = F_15 ( V_5 ) ;
}
}
static int F_289 ( const void * V_338 , const void * V_339 )
{
const struct F_67 * V_340 = V_338 ;
const struct F_67 * V_341 = V_339 ;
if ( V_340 -> V_336 > V_341 -> V_336 )
return 1 ;
if ( V_340 -> V_336 < V_341 -> V_336 )
return - 1 ;
return 0 ;
}
static int F_290 ( struct V_4 * V_5 )
{
struct V_342 * V_343 ;
F_100 ( & V_163 ) ;
F_291 (ev, &memcg->oom_notify, list)
F_288 ( V_343 -> V_337 , 1 ) ;
F_101 ( & V_163 ) ;
return 0 ;
}
static void F_145 ( struct V_4 * V_5 )
{
struct V_4 * V_89 ;
F_85 (iter, memcg)
F_290 ( V_89 ) ;
}
static int F_292 ( struct V_4 * V_5 ,
struct V_344 * V_337 , const char * args , enum V_345 type )
{
struct V_346 * V_331 ;
struct V_328 * V_347 ;
unsigned long V_336 ;
unsigned long V_330 ;
int V_100 , V_110 , V_103 ;
V_103 = F_270 ( args , L_12 , & V_336 ) ;
if ( V_103 )
return V_103 ;
F_117 ( & V_5 -> V_348 ) ;
if ( type == V_286 ) {
V_331 = & V_5 -> V_331 ;
V_330 = F_251 ( V_5 , false ) ;
} else if ( type == V_287 ) {
V_331 = & V_5 -> V_333 ;
V_330 = F_251 ( V_5 , true ) ;
} else
F_254 () ;
if ( V_331 -> V_332 )
F_287 ( V_5 , type == V_287 ) ;
V_110 = V_331 -> V_332 ? V_331 -> V_332 -> V_110 + 1 : 1 ;
V_347 = F_212 ( sizeof( * V_347 ) + V_110 * sizeof( struct F_67 ) ,
V_208 ) ;
if ( ! V_347 ) {
V_103 = - V_231 ;
goto V_120;
}
V_347 -> V_110 = V_110 ;
if ( V_331 -> V_332 ) {
memcpy ( V_347 -> V_335 , V_331 -> V_332 -> V_335 , ( V_110 - 1 ) *
sizeof( struct F_67 ) ) ;
}
V_347 -> V_335 [ V_110 - 1 ] . V_337 = V_337 ;
V_347 -> V_335 [ V_110 - 1 ] . V_336 = V_336 ;
F_293 ( V_347 -> V_335 , V_110 , sizeof( struct F_67 ) ,
F_289 , NULL ) ;
V_347 -> V_334 = - 1 ;
for ( V_100 = 0 ; V_100 < V_110 ; V_100 ++ ) {
if ( V_347 -> V_335 [ V_100 ] . V_336 <= V_330 ) {
++ V_347 -> V_334 ;
} else
break;
}
F_210 ( V_331 -> V_349 ) ;
V_331 -> V_349 = V_331 -> V_332 ;
F_294 ( V_331 -> V_332 , V_347 ) ;
F_295 () ;
V_120:
F_119 ( & V_5 -> V_348 ) ;
return V_103 ;
}
static int F_296 ( struct V_4 * V_5 ,
struct V_344 * V_337 , const char * args )
{
return F_292 ( V_5 , V_337 , args , V_286 ) ;
}
static int F_297 ( struct V_4 * V_5 ,
struct V_344 * V_337 , const char * args )
{
return F_292 ( V_5 , V_337 , args , V_287 ) ;
}
static void F_298 ( struct V_4 * V_5 ,
struct V_344 * V_337 , enum V_345 type )
{
struct V_346 * V_331 ;
struct V_328 * V_347 ;
unsigned long V_330 ;
int V_100 , V_350 , V_110 ;
F_117 ( & V_5 -> V_348 ) ;
if ( type == V_286 ) {
V_331 = & V_5 -> V_331 ;
V_330 = F_251 ( V_5 , false ) ;
} else if ( type == V_287 ) {
V_331 = & V_5 -> V_333 ;
V_330 = F_251 ( V_5 , true ) ;
} else
F_254 () ;
if ( ! V_331 -> V_332 )
goto V_120;
F_287 ( V_5 , type == V_287 ) ;
V_110 = 0 ;
for ( V_100 = 0 ; V_100 < V_331 -> V_332 -> V_110 ; V_100 ++ ) {
if ( V_331 -> V_332 -> V_335 [ V_100 ] . V_337 != V_337 )
V_110 ++ ;
}
V_347 = V_331 -> V_349 ;
if ( ! V_110 ) {
F_210 ( V_347 ) ;
V_347 = NULL ;
goto V_351;
}
V_347 -> V_110 = V_110 ;
V_347 -> V_334 = - 1 ;
for ( V_100 = 0 , V_350 = 0 ; V_100 < V_331 -> V_332 -> V_110 ; V_100 ++ ) {
if ( V_331 -> V_332 -> V_335 [ V_100 ] . V_337 == V_337 )
continue;
V_347 -> V_335 [ V_350 ] = V_331 -> V_332 -> V_335 [ V_100 ] ;
if ( V_347 -> V_335 [ V_350 ] . V_336 <= V_330 ) {
++ V_347 -> V_334 ;
}
V_350 ++ ;
}
V_351:
V_331 -> V_349 = V_331 -> V_332 ;
F_294 ( V_331 -> V_332 , V_347 ) ;
F_295 () ;
if ( ! V_347 ) {
F_210 ( V_331 -> V_349 ) ;
V_331 -> V_349 = NULL ;
}
V_120:
F_119 ( & V_5 -> V_348 ) ;
}
static void F_299 ( struct V_4 * V_5 ,
struct V_344 * V_337 )
{
return F_298 ( V_5 , V_337 , V_286 ) ;
}
static void F_300 ( struct V_4 * V_5 ,
struct V_344 * V_337 )
{
return F_298 ( V_5 , V_337 , V_287 ) ;
}
static int F_301 ( struct V_4 * V_5 ,
struct V_344 * V_337 , const char * args )
{
struct V_342 * V_352 ;
V_352 = F_212 ( sizeof( * V_352 ) , V_208 ) ;
if ( ! V_352 )
return - V_231 ;
F_100 ( & V_163 ) ;
V_352 -> V_337 = V_337 ;
F_302 ( & V_352 -> V_353 , & V_5 -> V_354 ) ;
if ( V_5 -> V_166 )
F_288 ( V_337 , 1 ) ;
F_101 ( & V_163 ) ;
return 0 ;
}
static void F_303 ( struct V_4 * V_5 ,
struct V_344 * V_337 )
{
struct V_342 * V_343 , * V_355 ;
F_100 ( & V_163 ) ;
F_304 (ev, tmp, &memcg->oom_notify, list) {
if ( V_343 -> V_337 == V_337 ) {
F_305 ( & V_343 -> V_353 ) ;
F_210 ( V_343 ) ;
}
}
F_101 ( & V_163 ) ;
}
static int F_306 ( struct V_310 * V_356 , void * V_312 )
{
struct V_4 * V_5 = F_70 ( F_277 ( V_356 ) ) ;
F_279 ( V_356 , L_28 , V_5 -> V_187 ) ;
F_279 ( V_356 , L_29 , ( bool ) V_5 -> V_166 ) ;
return 0 ;
}
static int F_307 ( struct V_7 * V_9 ,
struct V_279 * V_280 , V_126 V_45 )
{
struct V_4 * V_5 = F_70 ( V_9 ) ;
if ( ! V_9 -> V_28 || ! ( ( V_45 == 0 ) || ( V_45 == 1 ) ) )
return - V_261 ;
V_5 -> V_187 = V_45 ;
if ( ! V_45 )
F_140 ( V_5 ) ;
return 0 ;
}
struct V_357 * F_308 ( struct V_4 * V_5 )
{
return & V_5 -> V_358 ;
}
static int F_309 ( struct V_4 * V_5 , T_3 V_254 )
{
return F_310 ( & V_5 -> V_359 , V_254 ) ;
}
static void F_311 ( struct V_4 * V_5 )
{
F_312 ( & V_5 -> V_359 ) ;
}
static void F_313 ( struct V_4 * V_5 )
{
F_314 ( & V_5 -> V_359 ) ;
}
struct V_360 * F_315 ( struct V_361 * V_362 )
{
struct V_4 * V_5 = F_70 ( V_362 -> V_363 ) ;
if ( ! V_5 -> V_9 . V_28 )
return NULL ;
return & V_5 -> V_359 ;
}
void F_316 ( struct V_361 * V_362 , unsigned long * V_364 ,
unsigned long * V_365 , unsigned long * V_366 ,
unsigned long * V_367 )
{
struct V_4 * V_5 = F_70 ( V_362 -> V_363 ) ;
struct V_4 * V_28 ;
* V_366 = F_43 ( V_5 , V_368 ) ;
* V_367 = F_43 ( V_5 , V_369 ) ;
* V_364 = F_60 ( V_5 , ( 1 << V_370 ) |
( 1 << V_371 ) ) ;
* V_365 = V_320 ;
while ( ( V_28 = F_15 ( V_5 ) ) ) {
unsigned long V_372 = F_98 ( V_5 -> V_37 . V_115 , V_5 -> V_205 ) ;
unsigned long V_373 = F_32 ( & V_5 -> V_37 ) ;
* V_365 = F_98 ( * V_365 , V_372 - F_98 ( V_372 , V_373 ) ) ;
V_5 = V_28 ;
}
}
static int F_309 ( struct V_4 * V_5 , T_3 V_254 )
{
return 0 ;
}
static void F_311 ( struct V_4 * V_5 )
{
}
static void F_313 ( struct V_4 * V_5 )
{
}
static void F_317 ( struct V_199 * V_204 )
{
struct V_374 * V_352 =
F_5 ( V_204 , struct V_374 , remove ) ;
struct V_4 * V_5 = V_352 -> V_5 ;
F_318 ( V_352 -> V_375 , & V_352 -> V_123 ) ;
V_352 -> V_376 ( V_5 , V_352 -> V_337 ) ;
F_288 ( V_352 -> V_337 , 1 ) ;
F_319 ( V_352 -> V_337 ) ;
F_210 ( V_352 ) ;
F_79 ( & V_5 -> V_9 ) ;
}
static int F_320 ( T_5 * V_123 , unsigned V_167 ,
int V_168 , void * V_377 )
{
struct V_374 * V_352 =
F_5 ( V_123 , struct V_374 , V_123 ) ;
struct V_4 * V_5 = V_352 -> V_5 ;
unsigned long V_13 = ( unsigned long ) V_377 ;
if ( V_13 & V_378 ) {
F_100 ( & V_5 -> V_379 ) ;
if ( ! F_321 ( & V_352 -> V_353 ) ) {
F_322 ( & V_352 -> V_353 ) ;
F_186 ( & V_352 -> remove ) ;
}
F_101 ( & V_5 -> V_379 ) ;
}
return 0 ;
}
static void F_323 ( struct V_380 * V_380 ,
T_10 * V_375 , T_11 * V_381 )
{
struct V_374 * V_352 =
F_5 ( V_381 , struct V_374 , V_381 ) ;
V_352 -> V_375 = V_375 ;
F_324 ( V_375 , & V_352 -> V_123 ) ;
}
static T_7 F_325 ( struct V_274 * V_275 ,
char * V_276 , T_8 V_277 , T_9 V_278 )
{
struct V_7 * V_9 = F_246 ( V_275 ) ;
struct V_4 * V_5 = F_70 ( V_9 ) ;
struct V_374 * V_352 ;
struct V_7 * V_382 ;
unsigned int V_383 , V_384 ;
struct V_385 V_386 ;
struct V_385 V_387 ;
const char * V_314 ;
char * V_388 ;
int V_103 ;
V_276 = F_269 ( V_276 ) ;
V_383 = F_326 ( V_276 , & V_388 , 10 ) ;
if ( * V_388 != ' ' )
return - V_261 ;
V_276 = V_388 + 1 ;
V_384 = F_326 ( V_276 , & V_388 , 10 ) ;
if ( ( * V_388 != ' ' ) && ( * V_388 != '\0' ) )
return - V_261 ;
V_276 = V_388 + 1 ;
V_352 = F_327 ( sizeof( * V_352 ) , V_208 ) ;
if ( ! V_352 )
return - V_231 ;
V_352 -> V_5 = V_5 ;
F_144 ( & V_352 -> V_353 ) ;
F_328 ( & V_352 -> V_381 , F_323 ) ;
F_329 ( & V_352 -> V_123 , F_320 ) ;
F_213 ( & V_352 -> remove , F_317 ) ;
V_386 = F_330 ( V_383 ) ;
if ( ! V_386 . V_380 ) {
V_103 = - V_389 ;
goto V_390;
}
V_352 -> V_337 = F_331 ( V_386 . V_380 ) ;
if ( F_332 ( V_352 -> V_337 ) ) {
V_103 = F_333 ( V_352 -> V_337 ) ;
goto V_391;
}
V_387 = F_330 ( V_384 ) ;
if ( ! V_387 . V_380 ) {
V_103 = - V_389 ;
goto V_392;
}
V_103 = F_334 ( F_335 ( V_387 . V_380 ) , V_393 ) ;
if ( V_103 < 0 )
goto V_394;
V_314 = V_387 . V_380 -> V_395 . V_396 -> V_397 . V_314 ;
if ( ! strcmp ( V_314 , L_30 ) ) {
V_352 -> V_398 = F_296 ;
V_352 -> V_376 = F_299 ;
} else if ( ! strcmp ( V_314 , L_31 ) ) {
V_352 -> V_398 = F_301 ;
V_352 -> V_376 = F_303 ;
} else if ( ! strcmp ( V_314 , L_32 ) ) {
V_352 -> V_398 = V_399 ;
V_352 -> V_376 = V_400 ;
} else if ( ! strcmp ( V_314 , L_33 ) ) {
V_352 -> V_398 = F_297 ;
V_352 -> V_376 = F_300 ;
} else {
V_103 = - V_261 ;
goto V_394;
}
V_382 = F_336 ( V_387 . V_380 -> V_395 . V_396 -> V_401 ,
& V_1 ) ;
V_103 = - V_261 ;
if ( F_332 ( V_382 ) )
goto V_394;
if ( V_382 != V_9 ) {
F_79 ( V_382 ) ;
goto V_394;
}
V_103 = V_352 -> V_398 ( V_5 , V_352 -> V_337 , V_276 ) ;
if ( V_103 )
goto V_402;
V_386 . V_380 -> V_403 -> V_404 ( V_386 . V_380 , & V_352 -> V_381 ) ;
F_100 ( & V_5 -> V_379 ) ;
F_302 ( & V_352 -> V_353 , & V_5 -> V_405 ) ;
F_101 ( & V_5 -> V_379 ) ;
F_337 ( V_387 ) ;
F_337 ( V_386 ) ;
return V_277 ;
V_402:
F_79 ( V_9 ) ;
V_394:
F_337 ( V_387 ) ;
V_392:
F_319 ( V_352 -> V_337 ) ;
V_391:
F_337 ( V_386 ) ;
V_390:
F_210 ( V_352 ) ;
return V_103 ;
}
static void F_338 ( struct V_4 * V_5 , unsigned int V_406 )
{
F_56 ( F_122 ( & V_5 -> V_236 . V_407 ) <= 0 ) ;
F_339 ( V_406 , & V_5 -> V_236 . V_407 ) ;
}
static void F_340 ( struct V_4 * V_5 , unsigned int V_406 )
{
F_56 ( F_122 ( & V_5 -> V_236 . V_407 ) < V_406 ) ;
if ( F_341 ( V_406 , & V_5 -> V_236 . V_407 ) ) {
F_342 ( & V_408 , V_5 -> V_236 . V_236 ) ;
V_5 -> V_236 . V_236 = 0 ;
F_79 ( & V_5 -> V_9 ) ;
}
}
static inline void F_343 ( struct V_4 * V_5 )
{
F_338 ( V_5 , 1 ) ;
}
static inline void F_344 ( struct V_4 * V_5 )
{
F_340 ( V_5 , 1 ) ;
}
struct V_4 * F_345 ( unsigned short V_236 )
{
F_346 ( ! F_347 () ) ;
return F_348 ( & V_408 , V_236 ) ;
}
static int F_349 ( struct V_4 * V_5 , int V_153 )
{
struct V_16 * V_409 ;
int V_355 = V_153 ;
if ( ! F_350 ( V_153 , V_410 ) )
V_355 = - 1 ;
V_409 = F_351 ( sizeof( * V_409 ) , V_208 , V_355 ) ;
if ( ! V_409 )
return 1 ;
F_352 ( & V_409 -> V_59 ) ;
V_409 -> V_31 = 0 ;
V_409 -> V_30 = false ;
V_409 -> V_5 = V_5 ;
V_5 -> V_18 [ V_153 ] = V_409 ;
return 0 ;
}
static void F_353 ( struct V_4 * V_5 , int V_153 )
{
F_210 ( V_5 -> V_18 [ V_153 ] ) ;
}
static void F_354 ( struct V_4 * V_5 )
{
int V_153 ;
F_35 (node)
F_353 ( V_5 , V_153 ) ;
F_355 ( V_5 -> V_47 ) ;
F_210 ( V_5 ) ;
}
static void F_356 ( struct V_4 * V_5 )
{
F_311 ( V_5 ) ;
F_354 ( V_5 ) ;
}
static struct V_4 * F_357 ( void )
{
struct V_4 * V_5 ;
T_8 V_110 ;
int V_153 ;
V_110 = sizeof( struct V_4 ) ;
V_110 += V_63 * sizeof( struct V_16 * ) ;
V_5 = F_327 ( V_110 , V_208 ) ;
if ( ! V_5 )
return NULL ;
V_5 -> V_236 . V_236 = F_358 ( & V_408 , NULL ,
1 , V_411 ,
V_208 ) ;
if ( V_5 -> V_236 . V_236 < 0 )
goto V_412;
V_5 -> V_47 = F_359 ( struct V_413 ) ;
if ( ! V_5 -> V_47 )
goto V_412;
F_35 (node)
if ( F_349 ( V_5 , V_153 ) )
goto V_412;
if ( F_309 ( V_5 , V_208 ) )
goto V_412;
F_213 ( & V_5 -> V_207 , F_171 ) ;
V_5 -> V_154 = V_76 ;
F_144 ( & V_5 -> V_354 ) ;
F_360 ( & V_5 -> V_348 ) ;
F_361 ( & V_5 -> V_190 ) ;
F_362 ( & V_5 -> V_3 ) ;
F_144 ( & V_5 -> V_405 ) ;
F_361 ( & V_5 -> V_379 ) ;
V_5 -> V_414 = V_415 ;
#ifndef F_363
V_5 -> V_252 = - 1 ;
#endif
#ifdef F_364
F_144 ( & V_5 -> V_358 ) ;
#endif
F_365 ( & V_408 , V_5 , V_5 -> V_236 . V_236 ) ;
return V_5 ;
V_412:
if ( V_5 -> V_236 . V_236 > 0 )
F_342 ( & V_408 , V_5 -> V_236 . V_236 ) ;
F_354 ( V_5 ) ;
return NULL ;
}
static struct V_7 * T_12
F_366 ( struct V_7 * V_416 )
{
struct V_4 * V_28 = F_70 ( V_416 ) ;
struct V_4 * V_5 ;
long error = - V_231 ;
V_5 = F_357 () ;
if ( ! V_5 )
return F_367 ( error ) ;
V_5 -> V_205 = V_320 ;
V_5 -> V_38 = V_320 ;
if ( V_28 ) {
V_5 -> V_326 = F_115 ( V_28 ) ;
V_5 -> V_187 = V_28 -> V_187 ;
}
if ( V_28 && V_28 -> V_91 ) {
V_5 -> V_91 = true ;
F_368 ( & V_5 -> V_37 , & V_28 -> V_37 ) ;
F_368 ( & V_5 -> V_137 , & V_28 -> V_137 ) ;
F_368 ( & V_5 -> V_116 , & V_28 -> V_116 ) ;
F_368 ( & V_5 -> V_128 , & V_28 -> V_128 ) ;
F_368 ( & V_5 -> V_290 , & V_28 -> V_290 ) ;
} else {
F_368 ( & V_5 -> V_37 , NULL ) ;
F_368 ( & V_5 -> V_137 , NULL ) ;
F_368 ( & V_5 -> V_116 , NULL ) ;
F_368 ( & V_5 -> V_128 , NULL ) ;
F_368 ( & V_5 -> V_290 , NULL ) ;
if ( V_28 != V_6 )
V_1 . V_417 = true ;
}
if ( ! V_28 ) {
V_6 = V_5 ;
return & V_5 -> V_9 ;
}
error = F_256 ( V_5 ) ;
if ( error )
goto V_412;
if ( F_2 ( V_1 ) && ! V_418 )
F_257 ( & V_306 ) ;
return & V_5 -> V_9 ;
V_412:
F_356 ( V_5 ) ;
return F_367 ( - V_231 ) ;
}
static int F_369 ( struct V_7 * V_9 )
{
struct V_4 * V_5 = F_70 ( V_9 ) ;
F_126 ( & V_5 -> V_236 . V_407 , 1 ) ;
F_95 ( V_9 ) ;
return 0 ;
}
static void F_370 ( struct V_7 * V_9 )
{
struct V_4 * V_5 = F_70 ( V_9 ) ;
struct V_374 * V_352 , * V_355 ;
F_100 ( & V_5 -> V_379 ) ;
F_304 (event, tmp, &memcg->event_list, list) {
F_322 ( & V_352 -> V_353 ) ;
F_186 ( & V_352 -> remove ) ;
}
F_101 ( & V_5 -> V_379 ) ;
F_258 ( V_5 ) ;
F_371 ( V_5 ) ;
F_344 ( V_5 ) ;
}
static void F_372 ( struct V_7 * V_9 )
{
struct V_4 * V_5 = F_70 ( V_9 ) ;
F_81 ( V_5 ) ;
}
static void F_373 ( struct V_7 * V_9 )
{
struct V_4 * V_5 = F_70 ( V_9 ) ;
if ( F_2 ( V_1 ) && ! V_418 )
F_264 ( & V_306 ) ;
if ( ! F_2 ( V_1 ) && V_5 -> V_305 )
F_264 ( & V_306 ) ;
F_374 ( & V_5 -> V_3 ) ;
F_375 ( & V_5 -> V_207 ) ;
F_34 ( V_5 ) ;
F_262 ( V_5 ) ;
F_356 ( V_5 ) ;
}
static void F_376 ( struct V_7 * V_9 )
{
struct V_4 * V_5 = F_70 ( V_9 ) ;
F_236 ( & V_5 -> V_37 , V_320 ) ;
F_236 ( & V_5 -> V_137 , V_320 ) ;
F_236 ( & V_5 -> V_116 , V_320 ) ;
F_236 ( & V_5 -> V_128 , V_320 ) ;
F_236 ( & V_5 -> V_290 , V_320 ) ;
V_5 -> V_419 = 0 ;
V_5 -> V_205 = V_320 ;
V_5 -> V_38 = V_320 ;
F_313 ( V_5 ) ;
}
static int F_377 ( unsigned long V_48 )
{
int V_103 ;
V_103 = F_174 ( V_119 . V_118 , V_208 & ~ V_420 , V_48 ) ;
if ( ! V_103 ) {
V_119 . V_421 += V_48 ;
return V_103 ;
}
while ( V_48 -- ) {
V_103 = F_174 ( V_119 . V_118 , V_208 | V_226 , 1 ) ;
if ( V_103 )
return V_103 ;
V_119 . V_421 ++ ;
F_378 () ;
}
return 0 ;
}
static struct V_11 * F_379 ( struct V_422 * V_423 ,
unsigned long V_424 , T_13 V_425 )
{
struct V_11 * V_11 = F_380 ( V_423 , V_424 , V_425 ) ;
if ( ! V_11 || ! F_381 ( V_11 ) )
return NULL ;
if ( F_48 ( V_11 ) ) {
if ( ! ( V_119 . V_13 & V_426 ) )
return NULL ;
} else {
if ( ! ( V_119 . V_13 & V_427 ) )
return NULL ;
}
if ( ! F_382 ( V_11 ) )
return NULL ;
return V_11 ;
}
static struct V_11 * F_383 ( struct V_422 * V_423 ,
T_13 V_425 , T_6 * V_258 )
{
struct V_11 * V_11 = NULL ;
T_6 V_428 = F_384 ( V_425 ) ;
if ( ! ( V_119 . V_13 & V_426 ) || F_385 ( V_428 ) )
return NULL ;
V_11 = F_386 ( F_387 ( V_428 ) , F_388 ( V_428 ) ) ;
if ( F_1 () )
V_258 -> V_45 = V_428 . V_45 ;
return V_11 ;
}
static struct V_11 * F_383 ( struct V_422 * V_423 ,
T_13 V_425 , T_6 * V_258 )
{
return NULL ;
}
static struct V_11 * F_389 ( struct V_422 * V_423 ,
unsigned long V_424 , T_13 V_425 , T_6 * V_258 )
{
struct V_11 * V_11 = NULL ;
struct V_429 * V_430 ;
T_14 V_431 ;
if ( ! V_423 -> V_432 )
return NULL ;
if ( ! ( V_119 . V_13 & V_427 ) )
return NULL ;
V_430 = V_423 -> V_432 -> V_433 ;
V_431 = F_390 ( V_423 , V_424 ) ;
#ifdef F_391
if ( F_392 ( V_430 ) ) {
V_11 = F_393 ( V_430 , V_431 ) ;
if ( F_394 ( V_11 ) ) {
T_6 V_434 = F_395 ( V_11 ) ;
if ( F_1 () )
* V_258 = V_434 ;
V_11 = F_386 ( F_387 ( V_434 ) ,
F_388 ( V_434 ) ) ;
}
} else
V_11 = F_386 ( V_430 , V_431 ) ;
#else
V_11 = F_386 ( V_430 , V_431 ) ;
#endif
return V_11 ;
}
static int F_396 ( struct V_11 * V_11 ,
bool V_51 ,
struct V_4 * V_117 ,
struct V_4 * V_118 )
{
unsigned long V_13 ;
unsigned int V_36 = V_51 ? F_397 ( V_11 ) : 1 ;
int V_103 ;
bool V_435 ;
F_56 ( V_117 == V_118 ) ;
F_50 ( F_192 ( V_11 ) , V_11 ) ;
F_56 ( V_51 && ! F_51 ( V_11 ) ) ;
V_103 = - V_283 ;
if ( ! F_398 ( V_11 ) )
goto V_92;
V_103 = - V_261 ;
if ( V_11 -> V_4 != V_117 )
goto V_97;
V_435 = F_48 ( V_11 ) ;
F_29 ( & V_117 -> V_190 , V_13 ) ;
if ( ! V_435 && F_381 ( V_11 ) ) {
F_228 ( V_117 -> V_47 -> V_48 [ V_436 ] ,
V_36 ) ;
F_49 ( V_118 -> V_47 -> V_48 [ V_436 ] ,
V_36 ) ;
}
if ( ! V_435 && F_399 ( V_11 ) ) {
struct V_429 * V_430 = F_400 ( V_11 ) ;
if ( F_401 ( V_430 ) ) {
F_228 ( V_117 -> V_47 -> V_48 [ V_368 ] ,
V_36 ) ;
F_49 ( V_118 -> V_47 -> V_48 [ V_368 ] ,
V_36 ) ;
}
}
if ( F_402 ( V_11 ) ) {
F_228 ( V_117 -> V_47 -> V_48 [ V_369 ] ,
V_36 ) ;
F_49 ( V_118 -> V_47 -> V_48 [ V_369 ] ,
V_36 ) ;
}
V_11 -> V_4 = V_118 ;
F_30 ( & V_117 -> V_190 , V_13 ) ;
V_103 = 0 ;
F_403 () ;
F_47 ( V_118 , V_11 , V_51 , V_36 ) ;
F_65 ( V_118 , V_11 ) ;
F_47 ( V_117 , V_11 , V_51 , - V_36 ) ;
F_65 ( V_117 , V_11 ) ;
F_404 () ;
V_97:
F_405 ( V_11 ) ;
V_92:
return V_103 ;
}
static enum V_437 F_406 ( struct V_422 * V_423 ,
unsigned long V_424 , T_13 V_425 , union V_438 * V_65 )
{
struct V_11 * V_11 = NULL ;
enum V_437 V_103 = V_439 ;
T_6 V_428 = { . V_45 = 0 } ;
if ( F_407 ( V_425 ) )
V_11 = F_379 ( V_423 , V_424 , V_425 ) ;
else if ( F_408 ( V_425 ) )
V_11 = F_383 ( V_423 , V_425 , & V_428 ) ;
else if ( F_409 ( V_425 ) )
V_11 = F_389 ( V_423 , V_424 , V_425 , & V_428 ) ;
if ( ! V_11 && ! V_428 . V_45 )
return V_103 ;
if ( V_11 ) {
if ( V_11 -> V_4 == V_119 . V_117 ) {
V_103 = V_440 ;
if ( V_65 )
V_65 -> V_11 = V_11 ;
}
if ( ! V_103 || ! V_65 )
F_410 ( V_11 ) ;
}
if ( V_428 . V_45 && ! V_103 &&
F_232 ( V_119 . V_117 ) == F_411 ( V_428 ) ) {
V_103 = V_441 ;
if ( V_65 )
V_65 -> V_428 = V_428 ;
}
return V_103 ;
}
static enum V_437 F_412 ( struct V_422 * V_423 ,
unsigned long V_424 , T_15 V_442 , union V_438 * V_65 )
{
struct V_11 * V_11 = NULL ;
enum V_437 V_103 = V_439 ;
V_11 = F_413 ( V_442 ) ;
F_50 ( ! V_11 || ! F_414 ( V_11 ) , V_11 ) ;
if ( ! ( V_119 . V_13 & V_426 ) )
return V_103 ;
if ( V_11 -> V_4 == V_119 . V_117 ) {
V_103 = V_440 ;
if ( V_65 ) {
F_415 ( V_11 ) ;
V_65 -> V_11 = V_11 ;
}
}
return V_103 ;
}
static inline enum V_437 F_412 ( struct V_422 * V_423 ,
unsigned long V_424 , T_15 V_442 , union V_438 * V_65 )
{
return V_439 ;
}
static int F_416 ( T_15 * V_442 ,
unsigned long V_424 , unsigned long V_443 ,
struct V_444 * V_445 )
{
struct V_422 * V_423 = V_445 -> V_423 ;
T_13 * V_446 ;
T_16 * V_447 ;
V_447 = F_417 ( V_442 , V_423 ) ;
if ( V_447 ) {
if ( F_412 ( V_423 , V_424 , * V_442 , NULL ) == V_440 )
V_119 . V_421 += V_256 ;
F_101 ( V_447 ) ;
return 0 ;
}
if ( F_418 ( V_442 ) )
return 0 ;
V_446 = F_419 ( V_423 -> V_448 , V_442 , V_424 , & V_447 ) ;
for (; V_424 != V_443 ; V_446 ++ , V_424 += V_230 )
if ( F_406 ( V_423 , V_424 , * V_446 , NULL ) )
V_119 . V_421 ++ ;
F_420 ( V_446 - 1 , V_447 ) ;
F_378 () ;
return 0 ;
}
static unsigned long F_421 ( struct V_80 * V_81 )
{
unsigned long V_421 ;
struct V_444 V_449 = {
. V_450 = F_416 ,
. V_81 = V_81 ,
} ;
F_8 ( & V_81 -> V_451 ) ;
F_422 ( 0 , V_81 -> V_452 ,
& V_449 ) ;
F_10 ( & V_81 -> V_451 ) ;
V_421 = V_119 . V_421 ;
V_119 . V_421 = 0 ;
return V_421 ;
}
static int F_423 ( struct V_80 * V_81 )
{
unsigned long V_421 = F_421 ( V_81 ) ;
F_56 ( V_119 . V_121 ) ;
V_119 . V_121 = V_122 ;
return F_377 ( V_421 ) ;
}
static void F_424 ( void )
{
struct V_4 * V_117 = V_119 . V_117 ;
struct V_4 * V_118 = V_119 . V_118 ;
if ( V_119 . V_421 ) {
F_188 ( V_119 . V_118 , V_119 . V_421 ) ;
V_119 . V_421 = 0 ;
}
if ( V_119 . V_453 ) {
F_188 ( V_119 . V_117 , V_119 . V_453 ) ;
V_119 . V_453 = 0 ;
}
if ( V_119 . V_454 ) {
if ( ! F_6 ( V_119 . V_117 ) )
F_153 ( & V_119 . V_117 -> V_116 , V_119 . V_454 ) ;
F_340 ( V_119 . V_117 , V_119 . V_454 ) ;
if ( ! F_6 ( V_119 . V_118 ) )
F_153 ( & V_119 . V_118 -> V_37 , V_119 . V_454 ) ;
F_338 ( V_119 . V_118 , V_119 . V_454 ) ;
F_154 ( & V_119 . V_118 -> V_9 , V_119 . V_454 ) ;
V_119 . V_454 = 0 ;
}
F_140 ( V_117 ) ;
F_140 ( V_118 ) ;
F_425 ( & V_119 . V_124 ) ;
}
static void F_426 ( void )
{
struct V_80 * V_81 = V_119 . V_81 ;
V_119 . V_121 = NULL ;
F_424 () ;
F_100 ( & V_119 . V_35 ) ;
V_119 . V_117 = NULL ;
V_119 . V_118 = NULL ;
V_119 . V_81 = NULL ;
F_101 ( & V_119 . V_35 ) ;
F_427 ( V_81 ) ;
}
static int F_428 ( struct V_455 * V_456 )
{
struct V_7 * V_9 ;
struct V_4 * V_5 = NULL ;
struct V_4 * V_117 ;
struct V_78 * V_457 , * V_26 ;
struct V_80 * V_81 ;
unsigned long V_458 ;
int V_103 = 0 ;
if ( F_2 ( V_1 ) )
return 0 ;
V_26 = NULL ;
F_429 (leader, css, tset) {
F_346 ( V_26 ) ;
V_26 = V_457 ;
V_5 = F_70 ( V_9 ) ;
}
if ( ! V_26 )
return 0 ;
V_458 = F_14 ( V_5 -> V_307 ) ;
if ( ! V_458 )
return 0 ;
V_117 = F_69 ( V_26 ) ;
F_56 ( V_117 == V_5 ) ;
V_81 = F_430 ( V_26 ) ;
if ( ! V_81 )
return 0 ;
if ( V_81 -> V_82 == V_26 ) {
F_56 ( V_119 . V_117 ) ;
F_56 ( V_119 . V_118 ) ;
F_56 ( V_119 . V_421 ) ;
F_56 ( V_119 . V_453 ) ;
F_56 ( V_119 . V_454 ) ;
F_100 ( & V_119 . V_35 ) ;
V_119 . V_81 = V_81 ;
V_119 . V_117 = V_117 ;
V_119 . V_118 = V_5 ;
V_119 . V_13 = V_458 ;
F_101 ( & V_119 . V_35 ) ;
V_103 = F_423 ( V_81 ) ;
if ( V_103 )
F_426 () ;
} else {
F_427 ( V_81 ) ;
}
return V_103 ;
}
static void F_431 ( struct V_455 * V_456 )
{
if ( V_119 . V_118 )
F_426 () ;
}
static int F_432 ( T_15 * V_442 ,
unsigned long V_424 , unsigned long V_443 ,
struct V_444 * V_445 )
{
int V_103 = 0 ;
struct V_422 * V_423 = V_445 -> V_423 ;
T_13 * V_446 ;
T_16 * V_447 ;
enum V_437 V_459 ;
union V_438 V_65 ;
struct V_11 * V_11 ;
V_447 = F_417 ( V_442 , V_423 ) ;
if ( V_447 ) {
if ( V_119 . V_421 < V_256 ) {
F_101 ( V_447 ) ;
return 0 ;
}
V_459 = F_412 ( V_423 , V_424 , * V_442 , & V_65 ) ;
if ( V_459 == V_440 ) {
V_11 = V_65 . V_11 ;
if ( ! F_433 ( V_11 ) ) {
if ( ! F_396 ( V_11 , true ,
V_119 . V_117 , V_119 . V_118 ) ) {
V_119 . V_421 -= V_256 ;
V_119 . V_453 += V_256 ;
}
F_434 ( V_11 ) ;
}
F_410 ( V_11 ) ;
}
F_101 ( V_447 ) ;
return 0 ;
}
if ( F_418 ( V_442 ) )
return 0 ;
V_41:
V_446 = F_419 ( V_423 -> V_448 , V_442 , V_424 , & V_447 ) ;
for (; V_424 != V_443 ; V_424 += V_230 ) {
T_13 V_425 = * ( V_446 ++ ) ;
T_6 V_428 ;
if ( ! V_119 . V_421 )
break;
switch ( F_406 ( V_423 , V_424 , V_425 , & V_65 ) ) {
case V_440 :
V_11 = V_65 . V_11 ;
if ( F_435 ( V_11 ) )
goto V_460;
if ( F_433 ( V_11 ) )
goto V_460;
if ( ! F_396 ( V_11 , false ,
V_119 . V_117 , V_119 . V_118 ) ) {
V_119 . V_421 -- ;
V_119 . V_453 ++ ;
}
F_434 ( V_11 ) ;
V_460:
F_410 ( V_11 ) ;
break;
case V_441 :
V_428 = V_65 . V_428 ;
if ( ! F_231 ( V_428 , V_119 . V_117 , V_119 . V_118 ) ) {
V_119 . V_421 -- ;
V_119 . V_454 ++ ;
}
break;
default:
break;
}
}
F_420 ( V_446 - 1 , V_447 ) ;
F_378 () ;
if ( V_424 != V_443 ) {
V_103 = F_377 ( 1 ) ;
if ( ! V_103 )
goto V_41;
}
return V_103 ;
}
static void F_436 ( void )
{
struct V_444 V_461 = {
. V_450 = F_432 ,
. V_81 = V_119 . V_81 ,
} ;
F_243 () ;
F_68 ( & V_119 . V_117 -> V_189 ) ;
F_295 () ;
V_41:
if ( F_66 ( ! F_437 ( & V_119 . V_81 -> V_451 ) ) ) {
F_424 () ;
F_378 () ;
goto V_41;
}
F_422 ( 0 , V_119 . V_81 -> V_452 , & V_461 ) ;
F_10 ( & V_119 . V_81 -> V_451 ) ;
F_438 ( & V_119 . V_117 -> V_189 ) ;
}
static void F_439 ( void )
{
if ( V_119 . V_118 ) {
F_436 () ;
F_426 () ;
}
}
static int F_428 ( struct V_455 * V_456 )
{
return 0 ;
}
static void F_431 ( struct V_455 * V_456 )
{
}
static void F_439 ( void )
{
}
static void F_440 ( struct V_7 * V_462 )
{
if ( F_2 ( V_1 ) )
V_6 -> V_91 = true ;
else
V_6 -> V_91 = false ;
}
static V_126 F_441 ( struct V_7 * V_9 ,
struct V_279 * V_280 )
{
struct V_4 * V_5 = F_70 ( V_9 ) ;
return ( V_126 ) F_32 ( & V_5 -> V_37 ) * V_230 ;
}
static int F_442 ( struct V_310 * V_311 , void * V_312 )
{
struct V_4 * V_5 = F_70 ( F_277 ( V_311 ) ) ;
unsigned long V_419 = F_14 ( V_5 -> V_419 ) ;
if ( V_419 == V_320 )
F_443 ( V_311 , L_34 ) ;
else
F_279 ( V_311 , L_35 , ( V_126 ) V_419 * V_230 ) ;
return 0 ;
}
static T_7 F_444 ( struct V_274 * V_275 ,
char * V_276 , T_8 V_277 , T_9 V_278 )
{
struct V_4 * V_5 = F_70 ( F_246 ( V_275 ) ) ;
unsigned long V_419 ;
int V_237 ;
V_276 = F_269 ( V_276 ) ;
V_237 = F_270 ( V_276 , L_36 , & V_419 ) ;
if ( V_237 )
return V_237 ;
V_5 -> V_419 = V_419 ;
return V_277 ;
}
static int F_445 ( struct V_310 * V_311 , void * V_312 )
{
struct V_4 * V_5 = F_70 ( F_277 ( V_311 ) ) ;
unsigned long V_205 = F_14 ( V_5 -> V_205 ) ;
if ( V_205 == V_320 )
F_443 ( V_311 , L_34 ) ;
else
F_279 ( V_311 , L_35 , ( V_126 ) V_205 * V_230 ) ;
return 0 ;
}
static T_7 F_446 ( struct V_274 * V_275 ,
char * V_276 , T_8 V_277 , T_9 V_278 )
{
struct V_4 * V_5 = F_70 ( F_246 ( V_275 ) ) ;
unsigned long V_36 ;
unsigned long V_205 ;
int V_237 ;
V_276 = F_269 ( V_276 ) ;
V_237 = F_270 ( V_276 , L_36 , & V_205 ) ;
if ( V_237 )
return V_237 ;
V_5 -> V_205 = V_205 ;
V_36 = F_32 ( & V_5 -> V_37 ) ;
if ( V_36 > V_205 )
F_170 ( V_5 , V_36 - V_205 ,
V_208 , true ) ;
F_313 ( V_5 ) ;
return V_277 ;
}
static int F_447 ( struct V_310 * V_311 , void * V_312 )
{
struct V_4 * V_5 = F_70 ( F_277 ( V_311 ) ) ;
unsigned long F_175 = F_14 ( V_5 -> V_37 . V_115 ) ;
if ( F_175 == V_320 )
F_443 ( V_311 , L_34 ) ;
else
F_279 ( V_311 , L_35 , ( V_126 ) F_175 * V_230 ) ;
return 0 ;
}
static T_7 F_448 ( struct V_274 * V_275 ,
char * V_276 , T_8 V_277 , T_9 V_278 )
{
struct V_4 * V_5 = F_70 ( F_246 ( V_275 ) ) ;
unsigned int V_463 = V_212 ;
bool V_218 = false ;
unsigned long F_175 ;
int V_237 ;
V_276 = F_269 ( V_276 ) ;
V_237 = F_270 ( V_276 , L_36 , & F_175 ) ;
if ( V_237 )
return V_237 ;
F_449 ( & V_5 -> V_37 . V_115 , F_175 ) ;
for (; ; ) {
unsigned long V_36 = F_32 ( & V_5 -> V_37 ) ;
if ( V_36 <= F_175 )
break;
if ( F_235 ( V_122 ) ) {
V_237 = - V_266 ;
break;
}
if ( ! V_218 ) {
F_158 ( V_5 ) ;
V_218 = true ;
continue;
}
if ( V_463 ) {
if ( ! F_170 ( V_5 , V_36 - F_175 ,
V_208 , true ) )
V_463 -- ;
continue;
}
F_169 ( V_5 , V_229 , 1 ) ;
if ( ! F_116 ( V_5 , V_208 , 0 ) )
break;
}
F_313 ( V_5 ) ;
return V_277 ;
}
static int F_450 ( struct V_310 * V_311 , void * V_312 )
{
struct V_4 * V_5 = F_70 ( F_277 ( V_311 ) ) ;
F_279 ( V_311 , L_37 , F_46 ( V_5 , V_464 ) ) ;
F_279 ( V_311 , L_38 , F_46 ( V_5 , V_206 ) ) ;
F_279 ( V_311 , L_39 , F_46 ( V_5 , V_225 ) ) ;
F_279 ( V_311 , L_40 , F_46 ( V_5 , V_229 ) ) ;
return 0 ;
}
static int F_451 ( struct V_310 * V_311 , void * V_312 )
{
struct V_4 * V_5 = F_70 ( F_277 ( V_311 ) ) ;
unsigned long V_47 [ V_284 ] ;
unsigned long V_50 [ V_285 ] ;
int V_100 ;
F_249 ( V_5 , V_47 ) ;
F_250 ( V_5 , V_50 ) ;
F_279 ( V_311 , L_41 ,
( V_126 ) V_47 [ V_52 ] * V_230 ) ;
F_279 ( V_311 , L_42 ,
( V_126 ) V_47 [ V_53 ] * V_230 ) ;
F_279 ( V_311 , L_43 ,
( V_126 ) V_47 [ V_465 ] * 1024 ) ;
F_279 ( V_311 , L_44 ,
( V_126 ) ( V_47 [ V_466 ] +
V_47 [ V_467 ] ) * V_230 ) ;
F_279 ( V_311 , L_45 ,
( V_126 ) V_47 [ V_468 ] * V_230 ) ;
F_279 ( V_311 , L_46 ,
( V_126 ) V_47 [ V_436 ] * V_230 ) ;
F_279 ( V_311 , L_47 ,
( V_126 ) V_47 [ V_368 ] * V_230 ) ;
F_279 ( V_311 , L_48 ,
( V_126 ) V_47 [ V_369 ] * V_230 ) ;
for ( V_100 = 0 ; V_100 < V_132 ; V_100 ++ ) {
struct V_4 * V_317 ;
unsigned long V_45 = 0 ;
F_85 (mi, memcg)
V_45 += F_60 ( V_317 , F_58 ( V_100 ) ) ;
F_279 ( V_311 , L_49 ,
V_133 [ V_100 ] , ( V_126 ) V_45 * V_230 ) ;
}
F_279 ( V_311 , L_50 ,
( V_126 ) V_47 [ V_466 ] * V_230 ) ;
F_279 ( V_311 , L_51 ,
( V_126 ) V_47 [ V_467 ] * V_230 ) ;
F_279 ( V_311 , L_52 ,
V_50 [ V_469 ] ) ;
F_279 ( V_311 , L_53 ,
V_50 [ V_470 ] ) ;
return 0 ;
}
bool F_452 ( struct V_4 * V_83 , struct V_4 * V_5 )
{
if ( F_75 () )
return false ;
if ( V_5 == V_6 )
return false ;
if ( F_32 ( & V_5 -> V_37 ) >= V_5 -> V_419 )
return false ;
while ( V_5 != V_83 ) {
V_5 = F_15 ( V_5 ) ;
if ( V_5 == V_6 )
break;
if ( F_32 ( & V_5 -> V_37 ) >= V_5 -> V_419 )
return false ;
}
return true ;
}
int F_453 ( struct V_11 * V_11 , struct V_80 * V_81 ,
T_3 V_139 , struct V_4 * * V_471 ,
bool V_51 )
{
struct V_4 * V_5 = NULL ;
unsigned int V_36 = V_51 ? F_397 ( V_11 ) : 1 ;
int V_103 = 0 ;
if ( F_75 () )
goto V_92;
if ( F_454 ( V_11 ) ) {
F_50 ( ! F_455 ( V_11 ) , V_11 ) ;
if ( V_11 -> V_4 )
goto V_92;
if ( V_2 ) {
T_6 V_428 = { . V_45 = F_456 ( V_11 ) , } ;
unsigned short V_236 = F_411 ( V_428 ) ;
F_13 () ;
V_5 = F_345 ( V_236 ) ;
if ( V_5 && ! F_39 ( & V_5 -> V_9 ) )
V_5 = NULL ;
F_17 () ;
}
}
if ( ! V_5 )
V_5 = F_72 ( V_81 ) ;
V_103 = F_174 ( V_5 , V_139 , V_36 ) ;
F_79 ( & V_5 -> V_9 ) ;
V_92:
* V_471 = V_5 ;
return V_103 ;
}
void F_457 ( struct V_11 * V_11 , struct V_4 * V_5 ,
bool V_235 , bool V_51 )
{
unsigned int V_36 = V_51 ? F_397 ( V_11 ) : 1 ;
F_50 ( ! V_11 -> V_430 , V_11 ) ;
F_50 ( F_192 ( V_11 ) && ! V_235 , V_11 ) ;
if ( F_75 () )
return;
if ( ! V_5 )
return;
F_199 ( V_11 , V_5 , V_235 ) ;
F_403 () ;
F_47 ( V_5 , V_11 , V_51 , V_36 ) ;
F_65 ( V_5 , V_11 ) ;
F_404 () ;
if ( F_1 () && F_454 ( V_11 ) ) {
T_6 V_258 = { . V_45 = F_456 (page) } ;
F_458 ( V_258 ) ;
}
}
void F_459 ( struct V_11 * V_11 , struct V_4 * V_5 ,
bool V_51 )
{
unsigned int V_36 = V_51 ? F_397 ( V_11 ) : 1 ;
if ( F_75 () )
return;
if ( ! V_5 )
return;
F_188 ( V_5 , V_36 ) ;
}
static void F_460 ( struct V_4 * V_5 , unsigned long V_472 ,
unsigned long V_473 , unsigned long V_474 ,
unsigned long V_475 , unsigned long V_476 ,
struct V_11 * V_477 )
{
unsigned long V_36 = V_473 + V_474 + V_476 ;
unsigned long V_13 ;
if ( ! F_6 ( V_5 ) ) {
F_153 ( & V_5 -> V_37 , V_36 ) ;
if ( F_1 () )
F_153 ( & V_5 -> V_116 , V_36 ) ;
if ( ! F_2 ( V_1 ) && V_476 )
F_153 ( & V_5 -> V_128 , V_476 ) ;
F_140 ( V_5 ) ;
}
F_149 ( V_13 ) ;
F_228 ( V_5 -> V_47 -> V_48 [ V_52 ] , V_473 ) ;
F_228 ( V_5 -> V_47 -> V_48 [ V_53 ] , V_474 ) ;
F_228 ( V_5 -> V_47 -> V_48 [ V_54 ] , V_475 ) ;
F_49 ( V_5 -> V_47 -> V_50 [ V_56 ] , V_472 ) ;
F_49 ( V_5 -> V_47 -> V_57 , V_36 ) ;
F_65 ( V_5 , V_477 ) ;
F_151 ( V_13 ) ;
if ( ! F_6 ( V_5 ) )
F_154 ( & V_5 -> V_9 , V_36 ) ;
}
static void F_461 ( struct V_357 * V_478 )
{
struct V_4 * V_5 = NULL ;
unsigned long V_473 = 0 ;
unsigned long V_474 = 0 ;
unsigned long V_475 = 0 ;
unsigned long V_476 = 0 ;
unsigned long V_472 = 0 ;
struct V_357 * V_66 ;
struct V_11 * V_11 ;
V_66 = V_478 -> V_66 ;
do {
V_11 = F_462 ( V_66 , struct V_11 , V_62 ) ;
V_66 = V_11 -> V_62 . V_66 ;
F_50 ( F_192 ( V_11 ) , V_11 ) ;
F_50 ( F_463 ( V_11 ) , V_11 ) ;
if ( ! V_11 -> V_4 )
continue;
if ( V_5 != V_11 -> V_4 ) {
if ( V_5 ) {
F_460 ( V_5 , V_472 , V_473 , V_474 ,
V_475 , V_476 , V_11 ) ;
V_472 = V_473 = V_474 =
V_475 = V_476 = 0 ;
}
V_5 = V_11 -> V_4 ;
}
if ( ! F_225 ( V_11 ) ) {
unsigned int V_36 = 1 ;
if ( F_51 ( V_11 ) ) {
V_36 <<= F_464 ( V_11 ) ;
V_475 += V_36 ;
}
if ( F_48 ( V_11 ) )
V_473 += V_36 ;
else
V_474 += V_36 ;
V_472 ++ ;
} else {
V_476 += 1 << F_464 ( V_11 ) ;
F_226 ( V_11 ) ;
}
V_11 -> V_4 = NULL ;
} while ( V_66 != V_478 );
if ( V_5 )
F_460 ( V_5 , V_472 , V_473 , V_474 ,
V_475 , V_476 , V_11 ) ;
}
void F_465 ( struct V_11 * V_11 )
{
if ( F_75 () )
return;
if ( ! V_11 -> V_4 )
return;
F_144 ( & V_11 -> V_62 ) ;
F_461 ( & V_11 -> V_62 ) ;
}
void F_466 ( struct V_357 * V_478 )
{
if ( F_75 () )
return;
if ( ! F_321 ( V_478 ) )
F_461 ( V_478 ) ;
}
void F_467 ( struct V_11 * V_479 , struct V_11 * V_480 )
{
struct V_4 * V_5 ;
unsigned int V_36 ;
bool V_51 ;
unsigned long V_13 ;
F_50 ( ! F_455 ( V_479 ) , V_479 ) ;
F_50 ( ! F_455 ( V_480 ) , V_480 ) ;
F_50 ( F_48 ( V_479 ) != F_48 ( V_480 ) , V_480 ) ;
F_50 ( F_51 ( V_479 ) != F_51 ( V_480 ) ,
V_480 ) ;
if ( F_75 () )
return;
if ( V_480 -> V_4 )
return;
V_5 = V_479 -> V_4 ;
if ( ! V_5 )
return;
V_51 = F_51 ( V_480 ) ;
V_36 = V_51 ? F_397 ( V_480 ) : 1 ;
F_183 ( & V_5 -> V_37 , V_36 ) ;
if ( F_1 () )
F_183 ( & V_5 -> V_116 , V_36 ) ;
F_184 ( & V_5 -> V_9 , V_36 ) ;
F_199 ( V_480 , V_5 , false ) ;
F_149 ( V_13 ) ;
F_47 ( V_5 , V_480 , V_51 , V_36 ) ;
F_65 ( V_5 , V_480 ) ;
F_151 ( V_13 ) ;
}
void F_468 ( struct V_481 * V_482 )
{
struct V_4 * V_5 ;
if ( ! V_483 )
return;
if ( V_482 -> V_484 ) {
F_84 ( F_6 ( V_482 -> V_484 ) ) ;
F_95 ( & V_482 -> V_484 -> V_9 ) ;
return;
}
F_13 () ;
V_5 = F_69 ( V_122 ) ;
if ( V_5 == V_6 )
goto V_92;
if ( ! F_2 ( V_1 ) && ! V_5 -> V_305 )
goto V_92;
if ( F_39 ( & V_5 -> V_9 ) )
V_482 -> V_484 = V_5 ;
V_92:
F_17 () ;
}
void F_469 ( struct V_481 * V_482 )
{
if ( V_482 -> V_484 )
F_79 ( & V_482 -> V_484 -> V_9 ) ;
}
bool F_470 ( struct V_4 * V_5 , unsigned int V_36 )
{
T_3 V_139 = V_208 ;
if ( ! F_2 ( V_1 ) ) {
struct V_214 * V_412 ;
if ( F_176 ( & V_5 -> V_290 , V_36 , & V_412 ) ) {
V_5 -> V_485 = 0 ;
return true ;
}
F_183 ( & V_5 -> V_290 , V_36 ) ;
V_5 -> V_485 = 1 ;
return false ;
}
if ( F_471 () )
V_139 = V_247 ;
F_230 ( V_5 -> V_47 -> V_48 [ V_468 ] , V_36 ) ;
if ( F_174 ( V_5 , V_139 , V_36 ) == 0 )
return true ;
F_174 ( V_5 , V_139 | V_228 , V_36 ) ;
return false ;
}
void F_472 ( struct V_4 * V_5 , unsigned int V_36 )
{
if ( ! F_2 ( V_1 ) ) {
F_153 ( & V_5 -> V_290 , V_36 ) ;
return;
}
F_473 ( V_5 -> V_47 -> V_48 [ V_468 ] , V_36 ) ;
F_153 ( & V_5 -> V_37 , V_36 ) ;
F_154 ( & V_5 -> V_9 , V_36 ) ;
}
static int T_17 F_474 ( char * V_486 )
{
char * V_487 ;
while ( ( V_487 = F_475 ( & V_486 , L_54 ) ) != NULL ) {
if ( ! * V_487 )
continue;
if ( ! strcmp ( V_487 , L_55 ) )
V_418 = true ;
if ( ! strcmp ( V_487 , L_56 ) )
V_298 = true ;
}
return 0 ;
}
static int T_17 F_476 ( void )
{
int V_46 , V_153 ;
#ifndef F_363
V_248 = F_477 ( L_57 , 0 , 1 ) ;
F_84 ( ! V_248 ) ;
#endif
F_478 ( V_488 , L_58 , NULL ,
F_167 ) ;
F_44 (cpu)
F_213 ( & F_479 ( & V_196 , V_46 ) -> V_204 ,
F_155 ) ;
F_35 (node) {
struct V_19 * V_489 ;
V_489 = F_351 ( sizeof( * V_489 ) , V_208 ,
F_480 ( V_153 ) ? V_153 : V_490 ) ;
V_489 -> V_27 = V_491 ;
F_361 ( & V_489 -> V_35 ) ;
V_20 . V_21 [ V_153 ] = V_489 ;
}
return 0 ;
}
static struct V_4 * F_481 ( struct V_4 * V_5 )
{
while ( ! F_482 ( & V_5 -> V_236 . V_407 ) ) {
if ( F_346 ( V_5 == V_6 ) ) {
F_56 ( 1 ) ;
break;
}
V_5 = F_15 ( V_5 ) ;
if ( ! V_5 )
V_5 = V_6 ;
}
return V_5 ;
}
void F_483 ( struct V_11 * V_11 , T_6 V_258 )
{
struct V_4 * V_5 , * V_492 ;
unsigned short V_493 ;
F_50 ( F_192 ( V_11 ) , V_11 ) ;
F_50 ( F_463 ( V_11 ) , V_11 ) ;
if ( ! F_1 () )
return;
V_5 = V_11 -> V_4 ;
if ( ! V_5 )
return;
V_492 = F_481 ( V_5 ) ;
V_493 = F_484 ( V_258 , F_232 ( V_492 ) ) ;
F_50 ( V_493 , V_11 ) ;
F_229 ( V_492 , true ) ;
V_11 -> V_4 = NULL ;
if ( ! F_6 ( V_5 ) )
F_153 ( & V_5 -> V_37 , 1 ) ;
if ( V_5 != V_492 ) {
if ( ! F_6 ( V_492 ) )
F_183 ( & V_492 -> V_116 , 1 ) ;
F_153 ( & V_5 -> V_116 , 1 ) ;
}
F_56 ( ! F_485 () ) ;
F_47 ( V_5 , V_11 , false , - 1 ) ;
F_65 ( V_5 , V_11 ) ;
if ( ! F_6 ( V_5 ) )
F_79 ( & V_5 -> V_9 ) ;
}
int F_486 ( struct V_11 * V_11 , T_6 V_258 )
{
struct V_4 * V_5 ;
struct V_214 * V_215 ;
unsigned short V_493 ;
if ( ! F_2 ( V_1 ) || ! V_2 )
return 0 ;
V_5 = V_11 -> V_4 ;
if ( ! V_5 )
return 0 ;
V_5 = F_481 ( V_5 ) ;
if ( ! F_6 ( V_5 ) &&
! F_176 ( & V_5 -> V_137 , 1 , & V_215 ) ) {
F_344 ( V_5 ) ;
return - V_231 ;
}
V_493 = F_484 ( V_258 , F_232 ( V_5 ) ) ;
F_50 ( V_493 , V_11 ) ;
F_229 ( V_5 , true ) ;
return 0 ;
}
void F_458 ( T_6 V_258 )
{
struct V_4 * V_5 ;
unsigned short V_236 ;
if ( ! V_2 )
return;
V_236 = F_484 ( V_258 , 0 ) ;
F_13 () ;
V_5 = F_345 ( V_236 ) ;
if ( V_5 ) {
if ( ! F_6 ( V_5 ) ) {
if ( F_2 ( V_1 ) )
F_153 ( & V_5 -> V_137 , 1 ) ;
else
F_153 ( & V_5 -> V_116 , 1 ) ;
}
F_229 ( V_5 , false ) ;
F_344 ( V_5 ) ;
}
F_17 () ;
}
long F_487 ( struct V_4 * V_5 )
{
long V_494 = F_488 () ;
if ( ! V_2 || ! F_2 ( V_1 ) )
return V_494 ;
for (; V_5 != V_6 ; V_5 = F_15 ( V_5 ) )
V_494 = F_489 ( long , V_494 ,
F_14 ( V_5 -> V_137 . V_115 ) -
F_32 ( & V_5 -> V_137 ) ) ;
return V_494 ;
}
bool F_490 ( struct V_11 * V_11 )
{
struct V_4 * V_5 ;
F_50 ( ! F_455 ( V_11 ) , V_11 ) ;
if ( F_491 () )
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
static int T_17 F_492 ( char * V_486 )
{
if ( ! strcmp ( V_486 , L_59 ) )
V_495 = 1 ;
else if ( ! strcmp ( V_486 , L_60 ) )
V_495 = 0 ;
return 1 ;
}
static V_126 F_493 ( struct V_7 * V_9 ,
struct V_279 * V_280 )
{
struct V_4 * V_5 = F_70 ( V_9 ) ;
return ( V_126 ) F_32 ( & V_5 -> V_137 ) * V_230 ;
}
static int F_494 ( struct V_310 * V_311 , void * V_312 )
{
struct V_4 * V_5 = F_70 ( F_277 ( V_311 ) ) ;
unsigned long F_175 = F_14 ( V_5 -> V_137 . V_115 ) ;
if ( F_175 == V_320 )
F_443 ( V_311 , L_34 ) ;
else
F_279 ( V_311 , L_35 , ( V_126 ) F_175 * V_230 ) ;
return 0 ;
}
static T_7 F_495 ( struct V_274 * V_275 ,
char * V_276 , T_8 V_277 , T_9 V_278 )
{
struct V_4 * V_5 = F_70 ( F_246 ( V_275 ) ) ;
unsigned long F_175 ;
int V_237 ;
V_276 = F_269 ( V_276 ) ;
V_237 = F_270 ( V_276 , L_36 , & F_175 ) ;
if ( V_237 )
return V_237 ;
F_117 ( & V_267 ) ;
V_237 = F_236 ( & V_5 -> V_137 , F_175 ) ;
F_119 ( & V_267 ) ;
if ( V_237 )
return V_237 ;
return V_277 ;
}
static int T_17 F_496 ( void )
{
if ( ! F_75 () && V_495 ) {
V_2 = 1 ;
F_265 ( F_497 ( & V_1 ,
V_496 ) ) ;
F_265 ( F_498 ( & V_1 ,
V_497 ) ) ;
}
return 0 ;
}
