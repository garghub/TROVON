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
static unsigned long F_43 ( struct V_4 * V_5 ,
enum V_43 V_44 )
{
unsigned long V_45 = 0 ;
int V_46 ;
F_44 (cpu)
V_45 += F_45 ( V_5 -> V_47 -> V_48 [ V_44 ] , V_46 ) ;
return V_45 ;
}
static void F_46 ( struct V_4 * V_5 ,
struct V_11 * V_11 ,
bool V_49 , int V_36 )
{
if ( F_47 ( V_11 ) )
F_48 ( V_5 -> V_47 -> V_50 [ V_51 ] , V_36 ) ;
else {
F_48 ( V_5 -> V_47 -> V_50 [ V_52 ] , V_36 ) ;
if ( F_49 ( V_11 ) )
F_48 ( V_5 -> V_47 -> V_50 [ V_53 ] , V_36 ) ;
}
if ( V_49 ) {
F_50 ( ! F_51 ( V_11 ) , V_11 ) ;
F_48 ( V_5 -> V_47 -> V_50 [ V_54 ] , V_36 ) ;
}
if ( V_36 > 0 )
F_52 ( V_5 -> V_47 -> V_48 [ V_55 ] ) ;
else {
F_52 ( V_5 -> V_47 -> V_48 [ V_56 ] ) ;
V_36 = - V_36 ;
}
F_48 ( V_5 -> V_47 -> V_57 , V_36 ) ;
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
if ( ( long ) ( V_66 - V_45 ) < 0 ) {
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
unsigned long V_50 ;
unsigned long V_115 ;
V_50 = F_32 ( & V_5 -> V_37 ) ;
V_115 = F_14 ( V_5 -> V_37 . V_115 ) ;
if ( V_50 < V_115 )
V_114 = V_115 - V_50 ;
if ( F_1 () ) {
V_50 = F_32 ( & V_5 -> V_116 ) ;
V_115 = F_14 ( V_5 -> V_116 . V_115 ) ;
if ( V_50 <= V_115 )
V_114 = F_98 ( V_114 , V_115 - V_50 ) ;
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
for ( V_100 = 0 ; V_100 < F_113 ( V_129 ) ; V_100 ++ ) {
if ( V_129 [ V_100 ] == V_130 && ! V_2 )
continue;
F_111 ( L_11 , V_131 [ V_100 ] ,
F_112 ( F_114 ( V_89 , V_129 [ V_100 ] ) ) ) ;
}
for ( V_100 = 0 ; V_100 < V_132 ; V_100 ++ )
F_111 ( L_11 , V_133 [ V_100 ] ,
F_112 ( F_60 ( V_89 , F_58 ( V_100 ) ) ) ) ;
F_111 ( L_5 ) ;
}
}
static int F_115 ( struct V_4 * V_5 )
{
int V_134 = 0 ;
struct V_4 * V_89 ;
F_85 (iter, memcg)
V_134 ++ ;
return V_134 ;
}
unsigned long F_116 ( struct V_4 * V_5 )
{
unsigned long V_115 ;
V_115 = V_5 -> V_37 . V_115 ;
if ( F_117 ( V_5 ) ) {
unsigned long V_135 ;
unsigned long V_136 ;
V_135 = V_5 -> V_116 . V_115 ;
V_136 = V_5 -> V_137 . V_115 ;
V_136 = F_98 ( V_136 , ( unsigned long ) V_138 ) ;
V_115 = F_98 ( V_115 + V_136 , V_135 ) ;
}
return V_115 ;
}
static bool F_118 ( struct V_4 * V_5 , T_3 V_139 ,
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
F_119 ( & V_145 ) ;
V_103 = F_120 ( & V_142 ) ;
F_121 ( & V_145 ) ;
return V_103 ;
}
static bool F_122 ( struct V_4 * V_5 ,
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
static void F_123 ( struct V_4 * V_5 )
{
int V_17 ;
if ( ! F_124 ( & V_5 -> V_77 ) )
return;
if ( F_125 ( & V_5 -> V_149 ) > 1 )
return;
V_5 -> V_150 = V_151 [ V_152 ] ;
F_126 (nid, node_states[N_MEMORY]) {
if ( ! F_122 ( V_5 , V_17 , false ) )
F_127 ( V_17 , V_5 -> V_150 ) ;
}
F_128 ( & V_5 -> V_77 , 0 ) ;
F_128 ( & V_5 -> V_149 , 0 ) ;
}
int F_129 ( struct V_4 * V_5 )
{
int V_153 ;
F_123 ( V_5 ) ;
V_153 = V_5 -> V_154 ;
V_153 = F_130 ( V_153 , V_5 -> V_150 ) ;
if ( F_66 ( V_153 == V_76 ) )
V_153 = F_131 () ;
V_5 -> V_154 = V_153 ;
return V_153 ;
}
int F_129 ( struct V_4 * V_5 )
{
return 0 ;
}
static int F_132 ( struct V_4 * V_155 ,
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
V_158 += F_133 ( V_157 , V_139 , false ,
V_93 , & V_160 ) ;
* V_156 += V_160 ;
if ( ! F_31 ( V_155 ) )
break;
}
F_80 ( V_155 , V_157 ) ;
return V_158 ;
}
static bool F_134 ( struct V_4 * V_5 )
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
F_135 ( & V_164 , 0 , 1 , V_165 ) ;
F_101 ( & V_163 ) ;
return ! V_162 ;
}
static void F_136 ( struct V_4 * V_5 )
{
struct V_4 * V_89 ;
F_100 ( & V_163 ) ;
F_137 ( & V_164 , 1 , V_165 ) ;
F_85 (iter, memcg)
V_89 -> V_145 = false ;
F_101 ( & V_163 ) ;
}
static void F_138 ( struct V_4 * V_5 )
{
struct V_4 * V_89 ;
F_100 ( & V_163 ) ;
F_85 (iter, memcg)
V_89 -> V_166 ++ ;
F_101 ( & V_163 ) ;
}
static void F_139 ( struct V_4 * V_5 )
{
struct V_4 * V_89 ;
F_100 ( & V_163 ) ;
F_85 (iter, memcg)
if ( V_89 -> V_166 > 0 )
V_89 -> V_166 -- ;
F_101 ( & V_163 ) ;
}
static int F_140 ( T_5 * V_123 ,
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
return F_141 ( V_123 , V_167 , V_168 , V_102 ) ;
}
static void F_142 ( struct V_4 * V_5 )
{
if ( V_5 && V_5 -> V_166 )
F_143 ( & V_172 , V_173 , 0 , V_5 ) ;
}
static void F_144 ( struct V_4 * V_5 , T_3 V_174 , int V_140 )
{
if ( ! V_122 -> V_175 )
return;
F_95 ( & V_5 -> V_9 ) ;
V_122 -> V_176 = V_5 ;
V_122 -> V_177 = V_174 ;
V_122 -> V_178 = V_140 ;
}
bool F_145 ( bool V_179 )
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
V_180 . V_123 . V_183 = F_140 ;
V_180 . V_123 . V_184 = V_122 ;
F_146 ( & V_180 . V_123 . V_185 ) ;
F_104 ( & V_172 , & V_180 . V_123 , V_186 ) ;
F_138 ( V_5 ) ;
V_181 = F_134 ( V_5 ) ;
if ( V_181 )
F_147 ( V_5 ) ;
if ( V_181 && ! V_5 -> V_187 ) {
F_139 ( V_5 ) ;
F_106 ( & V_172 , & V_180 . V_123 ) ;
F_118 ( V_5 , V_122 -> V_177 ,
V_122 -> V_178 ) ;
} else {
F_105 () ;
F_139 ( V_5 ) ;
F_106 ( & V_172 , & V_180 . V_123 ) ;
}
if ( V_181 ) {
F_136 ( V_5 ) ;
F_142 ( V_5 ) ;
}
V_182:
V_122 -> V_176 = NULL ;
F_79 ( & V_5 -> V_9 ) ;
return true ;
}
struct V_4 * F_148 ( struct V_11 * V_11 )
{
struct V_4 * V_5 ;
unsigned long V_13 ;
F_13 () ;
if ( F_75 () )
return NULL ;
V_188:
V_5 = V_11 -> V_4 ;
if ( F_66 ( ! V_5 ) )
return NULL ;
if ( F_124 ( & V_5 -> V_189 ) <= 0 )
return V_5 ;
F_29 ( & V_5 -> V_190 , V_13 ) ;
if ( V_5 != V_11 -> V_4 ) {
F_30 ( & V_5 -> V_190 , V_13 ) ;
goto V_188;
}
V_5 -> V_191 = V_122 ;
V_5 -> V_192 = V_13 ;
return V_5 ;
}
void F_149 ( struct V_4 * V_5 )
{
if ( V_5 && V_5 -> V_191 == V_122 ) {
unsigned long V_13 = V_5 -> V_192 ;
V_5 -> V_191 = NULL ;
V_5 -> V_192 = 0 ;
F_30 ( & V_5 -> V_190 , V_13 ) ;
}
F_17 () ;
}
void F_150 ( struct V_11 * V_11 )
{
F_149 ( V_11 -> V_4 ) ;
}
static bool F_151 ( struct V_4 * V_5 , unsigned int V_36 )
{
struct V_193 * V_194 ;
unsigned long V_13 ;
bool V_103 = false ;
if ( V_36 > V_195 )
return V_103 ;
F_152 ( V_13 ) ;
V_194 = F_153 ( & V_196 ) ;
if ( V_5 == V_194 -> V_197 && V_194 -> V_36 >= V_36 ) {
V_194 -> V_36 -= V_36 ;
V_103 = true ;
}
F_154 ( V_13 ) ;
return V_103 ;
}
static void F_155 ( struct V_193 * V_194 )
{
struct V_4 * V_198 = V_194 -> V_197 ;
if ( V_194 -> V_36 ) {
F_156 ( & V_198 -> V_37 , V_194 -> V_36 ) ;
if ( F_1 () )
F_156 ( & V_198 -> V_116 , V_194 -> V_36 ) ;
F_157 ( & V_198 -> V_9 , V_194 -> V_36 ) ;
V_194 -> V_36 = 0 ;
}
V_194 -> V_197 = NULL ;
}
static void F_158 ( struct V_199 * V_200 )
{
struct V_193 * V_194 ;
unsigned long V_13 ;
F_152 ( V_13 ) ;
V_194 = F_153 ( & V_196 ) ;
F_155 ( V_194 ) ;
F_159 ( V_201 , & V_194 -> V_13 ) ;
F_154 ( V_13 ) ;
}
static void F_160 ( struct V_4 * V_5 , unsigned int V_36 )
{
struct V_193 * V_194 ;
unsigned long V_13 ;
F_152 ( V_13 ) ;
V_194 = F_153 ( & V_196 ) ;
if ( V_194 -> V_197 != V_5 ) {
F_155 ( V_194 ) ;
V_194 -> V_197 = V_5 ;
}
V_194 -> V_36 += V_36 ;
F_154 ( V_13 ) ;
}
static void F_161 ( struct V_4 * V_155 )
{
int V_46 , V_202 ;
if ( ! F_162 ( & V_203 ) )
return;
F_163 () ;
V_202 = F_164 () ;
F_165 (cpu) {
struct V_193 * V_194 = & F_45 ( V_196 , V_46 ) ;
struct V_4 * V_5 ;
V_5 = V_194 -> V_197 ;
if ( ! V_5 || ! V_194 -> V_36 )
continue;
if ( ! F_96 ( V_5 , V_155 ) )
continue;
if ( ! F_166 ( V_201 , & V_194 -> V_13 ) ) {
if ( V_46 == V_202 )
F_158 ( & V_194 -> V_204 ) ;
else
F_167 ( V_46 , & V_194 -> V_204 ) ;
}
}
F_168 () ;
F_169 () ;
F_121 ( & V_203 ) ;
}
static int F_170 ( unsigned int V_46 )
{
struct V_193 * V_194 ;
V_194 = & F_45 ( V_196 , V_46 ) ;
F_155 ( V_194 ) ;
return 0 ;
}
static void F_171 ( struct V_4 * V_5 ,
unsigned int V_36 ,
T_3 V_139 )
{
do {
if ( F_32 ( & V_5 -> V_37 ) <= V_5 -> V_205 )
continue;
F_172 ( V_5 , V_206 ) ;
F_173 ( V_5 , V_36 , V_139 , true ) ;
} while ( ( V_5 = F_15 ( V_5 ) ) );
}
static void F_174 ( struct V_199 * V_204 )
{
struct V_4 * V_5 ;
V_5 = F_5 ( V_204 , struct V_4 , V_207 ) ;
F_171 ( V_5 , V_195 , V_208 ) ;
}
void F_175 ( void )
{
unsigned int V_36 = V_122 -> V_209 ;
struct V_4 * V_5 ;
if ( F_176 ( ! V_36 ) )
return;
V_5 = F_72 ( V_122 -> V_81 ) ;
F_171 ( V_5 , V_36 , V_208 ) ;
F_79 ( & V_5 -> V_9 ) ;
V_122 -> V_209 = 0 ;
}
static int F_177 ( struct V_4 * V_5 , T_3 V_139 ,
unsigned int V_36 )
{
unsigned int V_210 = F_178 ( V_195 , V_36 ) ;
int V_211 = V_212 ;
struct V_4 * V_213 ;
struct V_214 * V_215 ;
unsigned long V_216 ;
bool V_217 = true ;
bool V_218 = false ;
if ( F_6 ( V_5 ) )
return 0 ;
V_41:
if ( F_151 ( V_5 , V_36 ) )
return 0 ;
if ( ! F_1 () ||
F_179 ( & V_5 -> V_116 , V_210 , & V_215 ) ) {
if ( F_179 ( & V_5 -> V_37 , V_210 , & V_215 ) )
goto V_219;
if ( F_1 () )
F_156 ( & V_5 -> V_116 , V_210 ) ;
V_213 = F_180 ( V_215 , V_37 ) ;
} else {
V_213 = F_180 ( V_215 , V_116 ) ;
V_217 = false ;
}
if ( V_210 > V_36 ) {
V_210 = V_36 ;
goto V_41;
}
if ( F_66 ( F_181 ( V_220 ) ||
F_182 ( V_122 ) ||
V_122 -> V_13 & V_221 ) )
goto V_222;
if ( F_66 ( V_122 -> V_13 & V_223 ) )
goto V_222;
if ( F_66 ( F_183 ( V_122 ) ) )
goto V_224;
if ( ! F_184 ( V_139 ) )
goto V_224;
F_172 ( V_213 , V_225 ) ;
V_216 = F_173 ( V_213 , V_36 ,
V_139 , V_217 ) ;
if ( F_97 ( V_213 ) >= V_36 )
goto V_41;
if ( ! V_218 ) {
F_161 ( V_213 ) ;
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
if ( F_182 ( V_122 ) )
goto V_222;
F_172 ( V_213 , V_229 ) ;
F_144 ( V_213 , V_139 ,
F_185 ( V_36 * V_230 ) ) ;
V_224:
if ( ! ( V_139 & V_228 ) )
return - V_231 ;
V_222:
F_186 ( & V_5 -> V_37 , V_36 ) ;
if ( F_1 () )
F_186 ( & V_5 -> V_116 , V_36 ) ;
F_187 ( & V_5 -> V_9 , V_36 ) ;
return 0 ;
V_219:
F_187 ( & V_5 -> V_9 , V_210 ) ;
if ( V_210 > V_36 )
F_160 ( V_5 , V_210 - V_36 ) ;
do {
if ( F_32 ( & V_5 -> V_37 ) > V_5 -> V_205 ) {
if ( F_188 () ) {
F_189 ( & V_5 -> V_207 ) ;
break;
}
V_122 -> V_209 += V_210 ;
F_190 ( V_122 ) ;
break;
}
} while ( ( V_5 = F_15 ( V_5 ) ) );
return 0 ;
}
static void F_191 ( struct V_4 * V_5 , unsigned int V_36 )
{
if ( F_6 ( V_5 ) )
return;
F_156 ( & V_5 -> V_37 , V_36 ) ;
if ( F_1 () )
F_156 ( & V_5 -> V_116 , V_36 ) ;
F_157 ( & V_5 -> V_9 , V_36 ) ;
}
static void F_192 ( struct V_11 * V_11 , int * V_232 )
{
struct V_233 * V_233 = F_193 ( V_11 ) ;
F_41 ( F_194 ( V_233 ) ) ;
if ( F_195 ( V_11 ) ) {
struct V_59 * V_59 ;
V_59 = F_89 ( V_11 , V_233 -> V_234 ) ;
F_196 ( V_11 ) ;
F_197 ( V_11 , V_59 , F_198 ( V_11 ) ) ;
* V_232 = 1 ;
} else
* V_232 = 0 ;
}
static void F_199 ( struct V_11 * V_11 , int V_232 )
{
struct V_233 * V_233 = F_193 ( V_11 ) ;
if ( V_232 ) {
struct V_59 * V_59 ;
V_59 = F_89 ( V_11 , V_233 -> V_234 ) ;
F_50 ( F_195 ( V_11 ) , V_11 ) ;
F_200 ( V_11 ) ;
F_201 ( V_11 , V_59 , F_198 ( V_11 ) ) ;
}
F_42 ( F_194 ( V_233 ) ) ;
}
static void F_202 ( struct V_11 * V_11 , struct V_4 * V_5 ,
bool V_235 )
{
int V_232 ;
F_50 ( V_11 -> V_4 , V_11 ) ;
if ( V_235 )
F_192 ( V_11 , & V_232 ) ;
V_11 -> V_4 = V_5 ;
if ( V_235 )
F_199 ( V_11 , V_232 ) ;
}
static int F_203 ( void )
{
int V_236 , V_110 ;
int V_237 ;
V_236 = F_204 ( & V_238 ,
0 , V_239 , V_208 ) ;
if ( V_236 < 0 )
return V_236 ;
if ( V_236 < V_240 )
return V_236 ;
F_205 ( & V_10 ) ;
V_110 = 2 * ( V_236 + 1 ) ;
if ( V_110 < V_241 )
V_110 = V_241 ;
else if ( V_110 > V_239 )
V_110 = V_239 ;
V_237 = F_206 ( V_110 ) ;
if ( ! V_237 )
V_237 = F_207 ( V_110 ) ;
if ( ! V_237 )
V_240 = V_110 ;
F_208 ( & V_10 ) ;
if ( V_237 ) {
F_209 ( & V_238 , V_236 ) ;
return V_237 ;
}
return V_236 ;
}
static void F_210 ( int V_236 )
{
F_209 ( & V_238 , V_236 ) ;
}
static void F_211 ( struct V_199 * V_242 )
{
struct V_243 * V_244 =
F_5 ( V_242 , struct V_243 , V_204 ) ;
struct V_4 * V_5 = V_244 -> V_5 ;
struct V_245 * V_246 = V_244 -> V_246 ;
F_212 ( V_5 , V_246 ) ;
F_79 ( & V_5 -> V_9 ) ;
F_213 ( V_244 ) ;
}
static void F_214 ( struct V_4 * V_5 ,
struct V_245 * V_246 )
{
struct V_243 * V_244 ;
V_244 = F_215 ( sizeof( * V_244 ) , V_247 ) ;
if ( ! V_244 )
return;
F_95 ( & V_5 -> V_9 ) ;
V_244 -> V_5 = V_5 ;
V_244 -> V_246 = V_246 ;
F_216 ( & V_244 -> V_204 , F_211 ) ;
F_217 ( V_248 , & V_244 -> V_204 ) ;
}
static void F_218 ( struct V_4 * V_5 ,
struct V_245 * V_246 )
{
V_122 -> V_249 = 1 ;
F_214 ( V_5 , V_246 ) ;
V_122 -> V_249 = 0 ;
}
static inline bool F_219 ( void )
{
if ( F_188 () || ! V_122 -> V_81 || ( V_122 -> V_13 & V_250 ) )
return true ;
return false ;
}
struct V_245 * F_220 ( struct V_245 * V_246 )
{
struct V_4 * V_5 ;
struct V_245 * V_251 ;
int V_252 ;
F_56 ( ! F_221 ( V_246 ) ) ;
if ( F_219 () )
return V_246 ;
if ( V_122 -> V_249 )
return V_246 ;
V_5 = F_72 ( V_122 -> V_81 ) ;
V_252 = F_14 ( V_5 -> V_252 ) ;
if ( V_252 < 0 )
goto V_92;
V_251 = F_222 ( V_246 , V_252 ) ;
if ( F_176 ( V_251 ) )
return V_251 ;
F_218 ( V_5 , V_246 ) ;
V_92:
F_79 ( & V_5 -> V_9 ) ;
return V_246 ;
}
void F_223 ( struct V_245 * V_246 )
{
if ( ! F_221 ( V_246 ) )
F_79 ( & V_246 -> V_253 . V_5 -> V_9 ) ;
}
int F_224 ( struct V_11 * V_11 , T_3 V_254 , int V_140 ,
struct V_4 * V_5 )
{
unsigned int V_36 = 1 << V_140 ;
struct V_214 * V_215 ;
int V_103 ;
V_103 = F_177 ( V_5 , V_254 , V_36 ) ;
if ( V_103 )
return V_103 ;
if ( ! F_2 ( V_1 ) &&
! F_179 ( & V_5 -> V_128 , V_36 , & V_215 ) ) {
F_191 ( V_5 , V_36 ) ;
return - V_231 ;
}
V_11 -> V_4 = V_5 ;
return 0 ;
}
int F_225 ( struct V_11 * V_11 , T_3 V_254 , int V_140 )
{
struct V_4 * V_5 ;
int V_103 = 0 ;
if ( F_219 () )
return 0 ;
V_5 = F_72 ( V_122 -> V_81 ) ;
if ( ! F_6 ( V_5 ) ) {
V_103 = F_224 ( V_11 , V_254 , V_140 , V_5 ) ;
if ( ! V_103 )
F_226 ( V_11 ) ;
}
F_79 ( & V_5 -> V_9 ) ;
return V_103 ;
}
void F_227 ( struct V_11 * V_11 , int V_140 )
{
struct V_4 * V_5 = V_11 -> V_4 ;
unsigned int V_36 = 1 << V_140 ;
if ( ! V_5 )
return;
F_50 ( F_6 ( V_5 ) , V_11 ) ;
if ( ! F_2 ( V_1 ) )
F_156 ( & V_5 -> V_128 , V_36 ) ;
F_156 ( & V_5 -> V_37 , V_36 ) ;
if ( F_1 () )
F_156 ( & V_5 -> V_116 , V_36 ) ;
V_11 -> V_4 = NULL ;
if ( F_228 ( V_11 ) )
F_229 ( V_11 ) ;
F_157 ( & V_5 -> V_9 , V_36 ) ;
}
void F_230 ( struct V_11 * V_255 )
{
int V_100 ;
if ( F_75 () )
return;
for ( V_100 = 1 ; V_100 < V_256 ; V_100 ++ )
V_255 [ V_100 ] . V_4 = V_255 -> V_4 ;
F_231 ( V_255 -> V_4 -> V_47 -> V_50 [ V_54 ] ,
V_256 ) ;
}
static void F_232 ( struct V_4 * V_5 ,
int V_257 )
{
F_233 ( V_5 -> V_47 -> V_50 [ V_130 ] , V_257 ) ;
}
static int F_234 ( T_6 V_185 ,
struct V_4 * V_117 , struct V_4 * V_118 )
{
unsigned short V_258 , V_259 ;
V_258 = F_235 ( V_117 ) ;
V_259 = F_235 ( V_118 ) ;
if ( F_236 ( V_185 , V_258 , V_259 ) == V_258 ) {
F_232 ( V_117 , - 1 ) ;
F_232 ( V_118 , 1 ) ;
return 0 ;
}
return - V_260 ;
}
static inline int F_234 ( T_6 V_185 ,
struct V_4 * V_117 , struct V_4 * V_118 )
{
return - V_260 ;
}
static int F_237 ( struct V_4 * V_5 ,
unsigned long V_115 )
{
unsigned long V_261 ;
unsigned long V_262 ;
bool V_263 = false ;
int V_264 ;
int V_103 ;
V_264 = V_212 *
F_115 ( V_5 ) ;
V_262 = F_32 ( & V_5 -> V_37 ) ;
do {
if ( F_238 ( V_122 ) ) {
V_103 = - V_265 ;
break;
}
F_119 ( & V_266 ) ;
if ( V_115 > V_5 -> V_116 . V_115 ) {
F_121 ( & V_266 ) ;
V_103 = - V_260 ;
break;
}
if ( V_115 > V_5 -> V_37 . V_115 )
V_263 = true ;
V_103 = F_239 ( & V_5 -> V_37 , V_115 ) ;
F_121 ( & V_266 ) ;
if ( ! V_103 )
break;
F_173 ( V_5 , 1 , V_208 , true ) ;
V_261 = F_32 ( & V_5 -> V_37 ) ;
if ( V_261 >= V_262 )
V_264 -- ;
else
V_262 = V_261 ;
} while ( V_264 );
if ( ! V_103 && V_263 )
F_142 ( V_5 ) ;
return V_103 ;
}
static int F_240 ( struct V_4 * V_5 ,
unsigned long V_115 )
{
unsigned long V_261 ;
unsigned long V_262 ;
bool V_263 = false ;
int V_264 ;
int V_103 ;
V_264 = V_212 *
F_115 ( V_5 ) ;
V_262 = F_32 ( & V_5 -> V_116 ) ;
do {
if ( F_238 ( V_122 ) ) {
V_103 = - V_265 ;
break;
}
F_119 ( & V_266 ) ;
if ( V_115 < V_5 -> V_37 . V_115 ) {
F_121 ( & V_266 ) ;
V_103 = - V_260 ;
break;
}
if ( V_115 > V_5 -> V_116 . V_115 )
V_263 = true ;
V_103 = F_239 ( & V_5 -> V_116 , V_115 ) ;
F_121 ( & V_266 ) ;
if ( ! V_103 )
break;
F_173 ( V_5 , 1 , V_208 , false ) ;
V_261 = F_32 ( & V_5 -> V_116 ) ;
if ( V_261 >= V_262 )
V_264 -- ;
else
V_262 = V_261 ;
} while ( V_264 );
if ( ! V_103 && V_263 )
F_142 ( V_5 ) ;
return V_103 ;
}
unsigned long F_241 ( T_4 * V_93 , int V_140 ,
T_3 V_139 ,
unsigned long * V_156 )
{
unsigned long V_216 = 0 ;
struct V_16 * V_22 , * V_267 = NULL ;
unsigned long V_268 ;
int V_159 = 0 ;
struct V_19 * V_23 ;
unsigned long V_39 ;
unsigned long V_160 ;
if ( V_140 > 0 )
return 0 ;
V_23 = F_20 ( V_93 -> V_94 ) ;
if ( ! V_23 || F_242 ( & V_23 -> V_27 ) )
return 0 ;
do {
if ( V_267 )
V_22 = V_267 ;
else
V_22 = F_40 ( V_23 ) ;
if ( ! V_22 )
break;
V_160 = 0 ;
V_268 = F_132 ( V_22 -> V_5 , V_93 ,
V_139 , & V_160 ) ;
V_216 += V_268 ;
* V_156 += V_160 ;
F_41 ( & V_23 -> V_35 ) ;
F_26 ( V_22 , V_23 ) ;
V_267 = NULL ;
if ( ! V_268 )
V_267 = F_37 ( V_23 ) ;
V_39 = F_31 ( V_22 -> V_5 ) ;
F_22 ( V_22 , V_23 , V_39 ) ;
F_42 ( & V_23 -> V_35 ) ;
F_79 ( & V_22 -> V_5 -> V_9 ) ;
V_159 ++ ;
if ( ! V_216 &&
( V_267 == NULL ||
V_159 > V_269 ) )
break;
} while ( ! V_216 );
if ( V_267 )
F_79 ( & V_267 -> V_5 -> V_9 ) ;
return V_216 ;
}
static inline bool F_243 ( struct V_4 * V_5 )
{
bool V_103 ;
F_13 () ;
V_103 = F_244 ( NULL , & V_5 -> V_9 ) ;
F_17 () ;
return V_103 ;
}
static int F_245 ( struct V_4 * V_5 )
{
int V_211 = V_212 ;
F_246 () ;
while ( V_211 && F_32 ( & V_5 -> V_37 ) ) {
int V_270 ;
if ( F_238 ( V_122 ) )
return - V_265 ;
V_270 = F_173 ( V_5 , 1 ,
V_208 , true ) ;
if ( ! V_270 ) {
V_211 -- ;
F_247 ( V_271 , V_272 / 10 ) ;
}
}
return 0 ;
}
static T_7 F_248 ( struct V_273 * V_274 ,
char * V_275 , T_8 V_276 ,
T_9 V_277 )
{
struct V_4 * V_5 = F_70 ( F_249 ( V_274 ) ) ;
if ( F_6 ( V_5 ) )
return - V_260 ;
return F_245 ( V_5 ) ? : V_276 ;
}
static V_126 F_250 ( struct V_7 * V_9 ,
struct V_278 * V_279 )
{
return F_70 ( V_9 ) -> V_91 ;
}
static int F_251 ( struct V_7 * V_9 ,
struct V_278 * V_279 , V_126 V_45 )
{
int V_280 = 0 ;
struct V_4 * V_5 = F_70 ( V_9 ) ;
struct V_4 * V_281 = F_70 ( V_5 -> V_9 . V_28 ) ;
if ( V_5 -> V_91 == V_45 )
return 0 ;
if ( ( ! V_281 || ! V_281 -> V_91 ) &&
( V_45 == 1 || V_45 == 0 ) ) {
if ( ! F_243 ( V_5 ) )
V_5 -> V_91 = V_45 ;
else
V_280 = - V_282 ;
} else
V_280 = - V_260 ;
return V_280 ;
}
static void F_252 ( struct V_4 * V_5 , unsigned long * V_47 )
{
struct V_4 * V_89 ;
int V_100 ;
memset ( V_47 , 0 , sizeof( * V_47 ) * V_283 ) ;
F_85 (iter, memcg) {
for ( V_100 = 0 ; V_100 < V_283 ; V_100 ++ )
V_47 [ V_100 ] += F_114 ( V_89 , V_100 ) ;
}
}
static void F_253 ( struct V_4 * V_5 , unsigned long * V_48 )
{
struct V_4 * V_89 ;
int V_100 ;
memset ( V_48 , 0 , sizeof( * V_48 ) * V_284 ) ;
F_85 (iter, memcg) {
for ( V_100 = 0 ; V_100 < V_284 ; V_100 ++ )
V_48 [ V_100 ] += F_43 ( V_89 , V_100 ) ;
}
}
static unsigned long F_254 ( struct V_4 * V_5 , bool V_137 )
{
unsigned long V_45 = 0 ;
if ( F_6 ( V_5 ) ) {
struct V_4 * V_89 ;
F_85 (iter, memcg) {
V_45 += F_114 ( V_89 , V_52 ) ;
V_45 += F_114 ( V_89 , V_51 ) ;
if ( V_137 )
V_45 += F_114 ( V_89 , V_130 ) ;
}
} else {
if ( ! V_137 )
V_45 = F_32 ( & V_5 -> V_37 ) ;
else
V_45 = F_32 ( & V_5 -> V_116 ) ;
}
return V_45 ;
}
static V_126 F_255 ( struct V_7 * V_9 ,
struct V_278 * V_279 )
{
struct V_4 * V_5 = F_70 ( V_9 ) ;
struct V_214 * V_215 ;
switch ( F_256 ( V_279 -> V_184 ) ) {
case V_285 :
V_215 = & V_5 -> V_37 ;
break;
case V_286 :
V_215 = & V_5 -> V_116 ;
break;
case V_287 :
V_215 = & V_5 -> V_128 ;
break;
case V_288 :
V_215 = & V_5 -> V_289 ;
break;
default:
F_257 () ;
}
switch ( F_258 ( V_279 -> V_184 ) ) {
case V_290 :
if ( V_215 == & V_5 -> V_37 )
return ( V_126 ) F_254 ( V_5 , false ) * V_230 ;
if ( V_215 == & V_5 -> V_116 )
return ( V_126 ) F_254 ( V_5 , true ) * V_230 ;
return ( V_126 ) F_32 ( V_215 ) * V_230 ;
case V_291 :
return ( V_126 ) V_215 -> V_115 * V_230 ;
case V_292 :
return ( V_126 ) V_215 -> V_293 * V_230 ;
case V_294 :
return V_215 -> V_127 ;
case V_295 :
return ( V_126 ) V_5 -> V_38 * V_230 ;
default:
F_257 () ;
}
}
static int F_259 ( struct V_4 * V_5 )
{
int V_296 ;
if ( V_297 )
return 0 ;
F_84 ( V_5 -> V_252 >= 0 ) ;
F_84 ( V_5 -> V_298 ) ;
V_296 = F_203 () ;
if ( V_296 < 0 )
return V_296 ;
F_260 ( & V_299 ) ;
V_5 -> V_252 = V_296 ;
V_5 -> V_298 = V_300 ;
F_146 ( & V_5 -> V_301 ) ;
return 0 ;
}
static void F_261 ( struct V_4 * V_5 )
{
struct V_7 * V_9 ;
struct V_4 * V_28 , * V_302 ;
int V_252 ;
if ( V_5 -> V_298 != V_300 )
return;
V_5 -> V_298 = V_303 ;
F_262 ( V_5 ) ;
V_252 = V_5 -> V_252 ;
F_84 ( V_252 < 0 ) ;
V_28 = F_15 ( V_5 ) ;
if ( ! V_28 )
V_28 = V_6 ;
F_13 () ;
F_263 (css, &memcg->css) {
V_302 = F_70 ( V_9 ) ;
F_84 ( V_302 -> V_252 != V_252 ) ;
V_302 -> V_252 = V_28 -> V_252 ;
if ( ! V_5 -> V_91 )
break;
}
F_17 () ;
F_264 ( V_252 , V_28 -> V_252 ) ;
F_210 ( V_252 ) ;
}
static void F_265 ( struct V_4 * V_5 )
{
if ( F_66 ( V_5 -> V_298 == V_300 ) )
F_261 ( V_5 ) ;
if ( V_5 -> V_298 == V_303 ) {
F_266 ( V_5 ) ;
F_267 ( & V_299 ) ;
F_268 ( F_32 ( & V_5 -> V_128 ) ) ;
}
}
static int F_259 ( struct V_4 * V_5 )
{
return 0 ;
}
static void F_261 ( struct V_4 * V_5 )
{
}
static void F_265 ( struct V_4 * V_5 )
{
}
static int F_269 ( struct V_4 * V_5 ,
unsigned long V_115 )
{
int V_103 ;
F_119 ( & V_266 ) ;
V_103 = F_239 ( & V_5 -> V_128 , V_115 ) ;
F_121 ( & V_266 ) ;
return V_103 ;
}
static int F_270 ( struct V_4 * V_5 , unsigned long V_115 )
{
int V_103 ;
F_119 ( & V_266 ) ;
V_103 = F_239 ( & V_5 -> V_289 , V_115 ) ;
if ( V_103 )
goto V_92;
if ( ! V_5 -> V_304 ) {
F_260 ( & V_305 ) ;
V_5 -> V_304 = true ;
}
V_92:
F_121 ( & V_266 ) ;
return V_103 ;
}
static T_7 F_271 ( struct V_273 * V_274 ,
char * V_275 , T_8 V_276 , T_9 V_277 )
{
struct V_4 * V_5 = F_70 ( F_249 ( V_274 ) ) ;
unsigned long V_36 ;
int V_103 ;
V_275 = F_272 ( V_275 ) ;
V_103 = F_273 ( V_275 , L_12 , & V_36 ) ;
if ( V_103 )
return V_103 ;
switch ( F_258 ( F_274 ( V_274 ) -> V_184 ) ) {
case V_291 :
if ( F_6 ( V_5 ) ) {
V_103 = - V_260 ;
break;
}
switch ( F_256 ( F_274 ( V_274 ) -> V_184 ) ) {
case V_285 :
V_103 = F_237 ( V_5 , V_36 ) ;
break;
case V_286 :
V_103 = F_240 ( V_5 , V_36 ) ;
break;
case V_287 :
V_103 = F_269 ( V_5 , V_36 ) ;
break;
case V_288 :
V_103 = F_270 ( V_5 , V_36 ) ;
break;
}
break;
case V_295 :
V_5 -> V_38 = V_36 ;
V_103 = 0 ;
break;
}
return V_103 ? : V_276 ;
}
static T_7 F_275 ( struct V_273 * V_274 , char * V_275 ,
T_8 V_276 , T_9 V_277 )
{
struct V_4 * V_5 = F_70 ( F_249 ( V_274 ) ) ;
struct V_214 * V_215 ;
switch ( F_256 ( F_274 ( V_274 ) -> V_184 ) ) {
case V_285 :
V_215 = & V_5 -> V_37 ;
break;
case V_286 :
V_215 = & V_5 -> V_116 ;
break;
case V_287 :
V_215 = & V_5 -> V_128 ;
break;
case V_288 :
V_215 = & V_5 -> V_289 ;
break;
default:
F_257 () ;
}
switch ( F_258 ( F_274 ( V_274 ) -> V_184 ) ) {
case V_292 :
F_276 ( V_215 ) ;
break;
case V_294 :
V_215 -> V_127 = 0 ;
break;
default:
F_257 () ;
}
return V_276 ;
}
static V_126 F_277 ( struct V_7 * V_9 ,
struct V_278 * V_279 )
{
return F_70 ( V_9 ) -> V_306 ;
}
static int F_278 ( struct V_7 * V_9 ,
struct V_278 * V_279 , V_126 V_45 )
{
struct V_4 * V_5 = F_70 ( V_9 ) ;
if ( V_45 & ~ V_307 )
return - V_260 ;
V_5 -> V_306 = V_45 ;
return 0 ;
}
static int F_278 ( struct V_7 * V_9 ,
struct V_278 * V_279 , V_126 V_45 )
{
return - V_308 ;
}
static int F_279 ( struct V_309 * V_310 , void * V_311 )
{
struct V_312 {
const char * V_313 ;
unsigned int V_58 ;
};
static const struct V_312 V_314 [] = {
{ L_13 , V_315 } ,
{ L_14 , V_147 } ,
{ L_15 , V_148 } ,
{ L_16 , F_58 (LRU_UNEVICTABLE) } ,
} ;
const struct V_312 * V_47 ;
int V_17 ;
unsigned long V_60 ;
struct V_4 * V_5 = F_70 ( F_280 ( V_310 ) ) ;
for ( V_47 = V_314 ; V_47 < V_314 + F_113 ( V_314 ) ; V_47 ++ ) {
V_60 = F_60 ( V_5 , V_47 -> V_58 ) ;
F_281 ( V_310 , L_17 , V_47 -> V_313 , V_60 ) ;
F_61 (nid, N_MEMORY) {
V_60 = F_53 ( V_5 , V_17 ,
V_47 -> V_58 ) ;
F_281 ( V_310 , L_18 , V_17 , V_60 ) ;
}
F_282 ( V_310 , '\n' ) ;
}
for ( V_47 = V_314 ; V_47 < V_314 + F_113 ( V_314 ) ; V_47 ++ ) {
struct V_4 * V_89 ;
V_60 = 0 ;
F_85 (iter, memcg)
V_60 += F_60 ( V_89 , V_47 -> V_58 ) ;
F_281 ( V_310 , L_19 , V_47 -> V_313 , V_60 ) ;
F_61 (nid, N_MEMORY) {
V_60 = 0 ;
F_85 (iter, memcg)
V_60 += F_53 (
V_89 , V_17 , V_47 -> V_58 ) ;
F_281 ( V_310 , L_18 , V_17 , V_60 ) ;
}
F_282 ( V_310 , '\n' ) ;
}
return 0 ;
}
static int F_283 ( struct V_309 * V_310 , void * V_311 )
{
struct V_4 * V_5 = F_70 ( F_280 ( V_310 ) ) ;
unsigned long V_37 , V_116 ;
struct V_4 * V_316 ;
unsigned int V_100 ;
F_284 ( F_113 ( V_131 ) != F_113 ( V_129 ) ) ;
F_284 ( F_113 ( V_133 ) != V_132 ) ;
for ( V_100 = 0 ; V_100 < F_113 ( V_129 ) ; V_100 ++ ) {
if ( V_129 [ V_100 ] == V_130 && ! F_1 () )
continue;
F_281 ( V_310 , L_20 , V_131 [ V_100 ] ,
F_114 ( V_5 , V_129 [ V_100 ] ) *
V_230 ) ;
}
for ( V_100 = 0 ; V_100 < F_113 ( V_317 ) ; V_100 ++ )
F_281 ( V_310 , L_20 , V_318 [ V_100 ] ,
F_43 ( V_5 , V_317 [ V_100 ] ) ) ;
for ( V_100 = 0 ; V_100 < V_132 ; V_100 ++ )
F_281 ( V_310 , L_20 , V_133 [ V_100 ] ,
F_60 ( V_5 , F_58 ( V_100 ) ) * V_230 ) ;
V_37 = V_116 = V_319 ;
for ( V_316 = V_5 ; V_316 ; V_316 = F_15 ( V_316 ) ) {
V_37 = F_98 ( V_37 , V_316 -> V_37 . V_115 ) ;
V_116 = F_98 ( V_116 , V_316 -> V_116 . V_115 ) ;
}
F_281 ( V_310 , L_21 ,
( V_126 ) V_37 * V_230 ) ;
if ( F_1 () )
F_281 ( V_310 , L_22 ,
( V_126 ) V_116 * V_230 ) ;
for ( V_100 = 0 ; V_100 < F_113 ( V_129 ) ; V_100 ++ ) {
unsigned long long V_45 = 0 ;
if ( V_129 [ V_100 ] == V_130 && ! F_1 () )
continue;
F_85 (mi, memcg)
V_45 += F_114 ( V_316 , V_129 [ V_100 ] ) *
V_230 ;
F_281 ( V_310 , L_23 , V_131 [ V_100 ] , V_45 ) ;
}
for ( V_100 = 0 ; V_100 < F_113 ( V_317 ) ; V_100 ++ ) {
unsigned long long V_45 = 0 ;
F_85 (mi, memcg)
V_45 += F_43 ( V_316 , V_317 [ V_100 ] ) ;
F_281 ( V_310 , L_23 , V_318 [ V_100 ] , V_45 ) ;
}
for ( V_100 = 0 ; V_100 < V_132 ; V_100 ++ ) {
unsigned long long V_45 = 0 ;
F_85 (mi, memcg)
V_45 += F_60 ( V_316 , F_58 ( V_100 ) ) * V_230 ;
F_281 ( V_310 , L_23 , V_133 [ V_100 ] , V_45 ) ;
}
#ifdef F_285
{
T_4 * V_93 ;
struct V_16 * V_22 ;
struct V_320 * V_321 ;
unsigned long V_322 [ 2 ] = { 0 , 0 } ;
unsigned long V_323 [ 2 ] = { 0 , 0 } ;
F_286 (pgdat) {
V_22 = F_36 ( V_5 , V_93 -> V_94 ) ;
V_321 = & V_22 -> V_59 . V_324 ;
V_322 [ 0 ] += V_321 -> V_322 [ 0 ] ;
V_322 [ 1 ] += V_321 -> V_322 [ 1 ] ;
V_323 [ 0 ] += V_321 -> V_323 [ 0 ] ;
V_323 [ 1 ] += V_321 -> V_323 [ 1 ] ;
}
F_281 ( V_310 , L_24 , V_322 [ 0 ] ) ;
F_281 ( V_310 , L_25 , V_322 [ 1 ] ) ;
F_281 ( V_310 , L_26 , V_323 [ 0 ] ) ;
F_281 ( V_310 , L_27 , V_323 [ 1 ] ) ;
}
#endif
return 0 ;
}
static V_126 F_287 ( struct V_7 * V_9 ,
struct V_278 * V_279 )
{
struct V_4 * V_5 = F_70 ( V_9 ) ;
return F_117 ( V_5 ) ;
}
static int F_288 ( struct V_7 * V_9 ,
struct V_278 * V_279 , V_126 V_45 )
{
struct V_4 * V_5 = F_70 ( V_9 ) ;
if ( V_45 > 100 )
return - V_260 ;
if ( V_9 -> V_28 )
V_5 -> V_325 = V_45 ;
else
V_326 = V_45 ;
return 0 ;
}
static void F_289 ( struct V_4 * V_5 , bool V_137 )
{
struct V_327 * V_328 ;
unsigned long V_329 ;
int V_100 ;
F_13 () ;
if ( ! V_137 )
V_328 = F_73 ( V_5 -> V_330 . V_331 ) ;
else
V_328 = F_73 ( V_5 -> V_332 . V_331 ) ;
if ( ! V_328 )
goto V_120;
V_329 = F_254 ( V_5 , V_137 ) ;
V_100 = V_328 -> V_333 ;
for (; V_100 >= 0 && F_66 ( V_328 -> V_334 [ V_100 ] . V_335 > V_329 ) ; V_100 -- )
F_290 ( V_328 -> V_334 [ V_100 ] . V_336 , 1 ) ;
V_100 ++ ;
for (; V_100 < V_328 -> V_110 && F_66 ( V_328 -> V_334 [ V_100 ] . V_335 <= V_329 ) ; V_100 ++ )
F_290 ( V_328 -> V_334 [ V_100 ] . V_336 , 1 ) ;
V_328 -> V_333 = V_100 - 1 ;
V_120:
F_17 () ;
}
static void F_67 ( struct V_4 * V_5 )
{
while ( V_5 ) {
F_289 ( V_5 , false ) ;
if ( F_1 () )
F_289 ( V_5 , true ) ;
V_5 = F_15 ( V_5 ) ;
}
}
static int F_291 ( const void * V_337 , const void * V_338 )
{
const struct F_67 * V_339 = V_337 ;
const struct F_67 * V_340 = V_338 ;
if ( V_339 -> V_335 > V_340 -> V_335 )
return 1 ;
if ( V_339 -> V_335 < V_340 -> V_335 )
return - 1 ;
return 0 ;
}
static int F_292 ( struct V_4 * V_5 )
{
struct V_341 * V_342 ;
F_100 ( & V_163 ) ;
F_293 (ev, &memcg->oom_notify, list)
F_290 ( V_342 -> V_336 , 1 ) ;
F_101 ( & V_163 ) ;
return 0 ;
}
static void F_147 ( struct V_4 * V_5 )
{
struct V_4 * V_89 ;
F_85 (iter, memcg)
F_292 ( V_89 ) ;
}
static int F_294 ( struct V_4 * V_5 ,
struct V_343 * V_336 , const char * args , enum V_344 type )
{
struct V_345 * V_330 ;
struct V_327 * V_346 ;
unsigned long V_335 ;
unsigned long V_329 ;
int V_100 , V_110 , V_103 ;
V_103 = F_273 ( args , L_12 , & V_335 ) ;
if ( V_103 )
return V_103 ;
F_119 ( & V_5 -> V_347 ) ;
if ( type == V_285 ) {
V_330 = & V_5 -> V_330 ;
V_329 = F_254 ( V_5 , false ) ;
} else if ( type == V_286 ) {
V_330 = & V_5 -> V_332 ;
V_329 = F_254 ( V_5 , true ) ;
} else
F_257 () ;
if ( V_330 -> V_331 )
F_289 ( V_5 , type == V_286 ) ;
V_110 = V_330 -> V_331 ? V_330 -> V_331 -> V_110 + 1 : 1 ;
V_346 = F_215 ( sizeof( * V_346 ) + V_110 * sizeof( struct F_67 ) ,
V_208 ) ;
if ( ! V_346 ) {
V_103 = - V_231 ;
goto V_120;
}
V_346 -> V_110 = V_110 ;
if ( V_330 -> V_331 ) {
memcpy ( V_346 -> V_334 , V_330 -> V_331 -> V_334 , ( V_110 - 1 ) *
sizeof( struct F_67 ) ) ;
}
V_346 -> V_334 [ V_110 - 1 ] . V_336 = V_336 ;
V_346 -> V_334 [ V_110 - 1 ] . V_335 = V_335 ;
F_295 ( V_346 -> V_334 , V_110 , sizeof( struct F_67 ) ,
F_291 , NULL ) ;
V_346 -> V_333 = - 1 ;
for ( V_100 = 0 ; V_100 < V_110 ; V_100 ++ ) {
if ( V_346 -> V_334 [ V_100 ] . V_335 <= V_329 ) {
++ V_346 -> V_333 ;
} else
break;
}
F_213 ( V_330 -> V_348 ) ;
V_330 -> V_348 = V_330 -> V_331 ;
F_296 ( V_330 -> V_331 , V_346 ) ;
F_297 () ;
V_120:
F_121 ( & V_5 -> V_347 ) ;
return V_103 ;
}
static int F_298 ( struct V_4 * V_5 ,
struct V_343 * V_336 , const char * args )
{
return F_294 ( V_5 , V_336 , args , V_285 ) ;
}
static int F_299 ( struct V_4 * V_5 ,
struct V_343 * V_336 , const char * args )
{
return F_294 ( V_5 , V_336 , args , V_286 ) ;
}
static void F_300 ( struct V_4 * V_5 ,
struct V_343 * V_336 , enum V_344 type )
{
struct V_345 * V_330 ;
struct V_327 * V_346 ;
unsigned long V_329 ;
int V_100 , V_349 , V_110 ;
F_119 ( & V_5 -> V_347 ) ;
if ( type == V_285 ) {
V_330 = & V_5 -> V_330 ;
V_329 = F_254 ( V_5 , false ) ;
} else if ( type == V_286 ) {
V_330 = & V_5 -> V_332 ;
V_329 = F_254 ( V_5 , true ) ;
} else
F_257 () ;
if ( ! V_330 -> V_331 )
goto V_120;
F_289 ( V_5 , type == V_286 ) ;
V_110 = 0 ;
for ( V_100 = 0 ; V_100 < V_330 -> V_331 -> V_110 ; V_100 ++ ) {
if ( V_330 -> V_331 -> V_334 [ V_100 ] . V_336 != V_336 )
V_110 ++ ;
}
V_346 = V_330 -> V_348 ;
if ( ! V_110 ) {
F_213 ( V_346 ) ;
V_346 = NULL ;
goto V_350;
}
V_346 -> V_110 = V_110 ;
V_346 -> V_333 = - 1 ;
for ( V_100 = 0 , V_349 = 0 ; V_100 < V_330 -> V_331 -> V_110 ; V_100 ++ ) {
if ( V_330 -> V_331 -> V_334 [ V_100 ] . V_336 == V_336 )
continue;
V_346 -> V_334 [ V_349 ] = V_330 -> V_331 -> V_334 [ V_100 ] ;
if ( V_346 -> V_334 [ V_349 ] . V_335 <= V_329 ) {
++ V_346 -> V_333 ;
}
V_349 ++ ;
}
V_350:
V_330 -> V_348 = V_330 -> V_331 ;
F_296 ( V_330 -> V_331 , V_346 ) ;
F_297 () ;
if ( ! V_346 ) {
F_213 ( V_330 -> V_348 ) ;
V_330 -> V_348 = NULL ;
}
V_120:
F_121 ( & V_5 -> V_347 ) ;
}
static void F_301 ( struct V_4 * V_5 ,
struct V_343 * V_336 )
{
return F_300 ( V_5 , V_336 , V_285 ) ;
}
static void F_302 ( struct V_4 * V_5 ,
struct V_343 * V_336 )
{
return F_300 ( V_5 , V_336 , V_286 ) ;
}
static int F_303 ( struct V_4 * V_5 ,
struct V_343 * V_336 , const char * args )
{
struct V_341 * V_44 ;
V_44 = F_215 ( sizeof( * V_44 ) , V_208 ) ;
if ( ! V_44 )
return - V_231 ;
F_100 ( & V_163 ) ;
V_44 -> V_336 = V_336 ;
F_304 ( & V_44 -> V_351 , & V_5 -> V_352 ) ;
if ( V_5 -> V_166 )
F_290 ( V_336 , 1 ) ;
F_101 ( & V_163 ) ;
return 0 ;
}
static void F_305 ( struct V_4 * V_5 ,
struct V_343 * V_336 )
{
struct V_341 * V_342 , * V_353 ;
F_100 ( & V_163 ) ;
F_306 (ev, tmp, &memcg->oom_notify, list) {
if ( V_342 -> V_336 == V_336 ) {
F_307 ( & V_342 -> V_351 ) ;
F_213 ( V_342 ) ;
}
}
F_101 ( & V_163 ) ;
}
static int F_308 ( struct V_309 * V_354 , void * V_311 )
{
struct V_4 * V_5 = F_70 ( F_280 ( V_354 ) ) ;
F_281 ( V_354 , L_28 , V_5 -> V_187 ) ;
F_281 ( V_354 , L_29 , ( bool ) V_5 -> V_166 ) ;
F_281 ( V_354 , L_30 , F_43 ( V_5 , V_355 ) ) ;
return 0 ;
}
static int F_309 ( struct V_7 * V_9 ,
struct V_278 * V_279 , V_126 V_45 )
{
struct V_4 * V_5 = F_70 ( V_9 ) ;
if ( ! V_9 -> V_28 || ! ( ( V_45 == 0 ) || ( V_45 == 1 ) ) )
return - V_260 ;
V_5 -> V_187 = V_45 ;
if ( ! V_45 )
F_142 ( V_5 ) ;
return 0 ;
}
struct V_356 * F_310 ( struct V_4 * V_5 )
{
return & V_5 -> V_357 ;
}
static int F_311 ( struct V_4 * V_5 , T_3 V_254 )
{
return F_312 ( & V_5 -> V_358 , V_254 ) ;
}
static void F_313 ( struct V_4 * V_5 )
{
F_314 ( & V_5 -> V_358 ) ;
}
static void F_315 ( struct V_4 * V_5 )
{
F_316 ( & V_5 -> V_358 ) ;
}
struct V_359 * F_317 ( struct V_360 * V_361 )
{
struct V_4 * V_5 = F_70 ( V_361 -> V_362 ) ;
if ( ! V_5 -> V_9 . V_28 )
return NULL ;
return & V_5 -> V_358 ;
}
void F_318 ( struct V_360 * V_361 , unsigned long * V_363 ,
unsigned long * V_364 , unsigned long * V_365 ,
unsigned long * V_366 )
{
struct V_4 * V_5 = F_70 ( V_361 -> V_362 ) ;
struct V_4 * V_28 ;
* V_365 = F_114 ( V_5 , V_367 ) ;
* V_366 = F_114 ( V_5 , V_368 ) ;
* V_363 = F_60 ( V_5 , ( 1 << V_369 ) |
( 1 << V_370 ) ) ;
* V_364 = V_319 ;
while ( ( V_28 = F_15 ( V_5 ) ) ) {
unsigned long V_371 = F_98 ( V_5 -> V_37 . V_115 , V_5 -> V_205 ) ;
unsigned long V_372 = F_32 ( & V_5 -> V_37 ) ;
* V_364 = F_98 ( * V_364 , V_371 - F_98 ( V_371 , V_372 ) ) ;
V_5 = V_28 ;
}
}
static int F_311 ( struct V_4 * V_5 , T_3 V_254 )
{
return 0 ;
}
static void F_313 ( struct V_4 * V_5 )
{
}
static void F_315 ( struct V_4 * V_5 )
{
}
static void F_319 ( struct V_199 * V_204 )
{
struct F_172 * V_44 =
F_5 ( V_204 , struct F_172 , remove ) ;
struct V_4 * V_5 = V_44 -> V_5 ;
F_320 ( V_44 -> V_373 , & V_44 -> V_123 ) ;
V_44 -> V_374 ( V_5 , V_44 -> V_336 ) ;
F_290 ( V_44 -> V_336 , 1 ) ;
F_321 ( V_44 -> V_336 ) ;
F_213 ( V_44 ) ;
F_79 ( & V_5 -> V_9 ) ;
}
static int F_322 ( T_5 * V_123 , unsigned V_167 ,
int V_168 , void * V_375 )
{
struct F_172 * V_44 =
F_5 ( V_123 , struct F_172 , V_123 ) ;
struct V_4 * V_5 = V_44 -> V_5 ;
unsigned long V_13 = ( unsigned long ) V_375 ;
if ( V_13 & V_376 ) {
F_100 ( & V_5 -> V_377 ) ;
if ( ! F_323 ( & V_44 -> V_351 ) ) {
F_324 ( & V_44 -> V_351 ) ;
F_189 ( & V_44 -> remove ) ;
}
F_101 ( & V_5 -> V_377 ) ;
}
return 0 ;
}
static void F_325 ( struct V_378 * V_378 ,
T_10 * V_373 , T_11 * V_379 )
{
struct F_172 * V_44 =
F_5 ( V_379 , struct F_172 , V_379 ) ;
V_44 -> V_373 = V_373 ;
F_326 ( V_373 , & V_44 -> V_123 ) ;
}
static T_7 F_327 ( struct V_273 * V_274 ,
char * V_275 , T_8 V_276 , T_9 V_277 )
{
struct V_7 * V_9 = F_249 ( V_274 ) ;
struct V_4 * V_5 = F_70 ( V_9 ) ;
struct F_172 * V_44 ;
struct V_7 * V_380 ;
unsigned int V_381 , V_382 ;
struct V_383 V_384 ;
struct V_383 V_385 ;
const char * V_313 ;
char * V_386 ;
int V_103 ;
V_275 = F_272 ( V_275 ) ;
V_381 = F_328 ( V_275 , & V_386 , 10 ) ;
if ( * V_386 != ' ' )
return - V_260 ;
V_275 = V_386 + 1 ;
V_382 = F_328 ( V_275 , & V_386 , 10 ) ;
if ( ( * V_386 != ' ' ) && ( * V_386 != '\0' ) )
return - V_260 ;
V_275 = V_386 + 1 ;
V_44 = F_329 ( sizeof( * V_44 ) , V_208 ) ;
if ( ! V_44 )
return - V_231 ;
V_44 -> V_5 = V_5 ;
F_146 ( & V_44 -> V_351 ) ;
F_330 ( & V_44 -> V_379 , F_325 ) ;
F_331 ( & V_44 -> V_123 , F_322 ) ;
F_216 ( & V_44 -> remove , F_319 ) ;
V_384 = F_332 ( V_381 ) ;
if ( ! V_384 . V_378 ) {
V_103 = - V_387 ;
goto V_388;
}
V_44 -> V_336 = F_333 ( V_384 . V_378 ) ;
if ( F_334 ( V_44 -> V_336 ) ) {
V_103 = F_335 ( V_44 -> V_336 ) ;
goto V_389;
}
V_385 = F_332 ( V_382 ) ;
if ( ! V_385 . V_378 ) {
V_103 = - V_387 ;
goto V_390;
}
V_103 = F_336 ( F_337 ( V_385 . V_378 ) , V_391 ) ;
if ( V_103 < 0 )
goto V_392;
V_313 = V_385 . V_378 -> V_393 . V_394 -> V_395 . V_313 ;
if ( ! strcmp ( V_313 , L_31 ) ) {
V_44 -> V_396 = F_298 ;
V_44 -> V_374 = F_301 ;
} else if ( ! strcmp ( V_313 , L_32 ) ) {
V_44 -> V_396 = F_303 ;
V_44 -> V_374 = F_305 ;
} else if ( ! strcmp ( V_313 , L_33 ) ) {
V_44 -> V_396 = V_397 ;
V_44 -> V_374 = V_398 ;
} else if ( ! strcmp ( V_313 , L_34 ) ) {
V_44 -> V_396 = F_299 ;
V_44 -> V_374 = F_302 ;
} else {
V_103 = - V_260 ;
goto V_392;
}
V_380 = F_338 ( V_385 . V_378 -> V_393 . V_394 -> V_399 ,
& V_1 ) ;
V_103 = - V_260 ;
if ( F_334 ( V_380 ) )
goto V_392;
if ( V_380 != V_9 ) {
F_79 ( V_380 ) ;
goto V_392;
}
V_103 = V_44 -> V_396 ( V_5 , V_44 -> V_336 , V_275 ) ;
if ( V_103 )
goto V_400;
V_384 . V_378 -> V_401 -> V_402 ( V_384 . V_378 , & V_44 -> V_379 ) ;
F_100 ( & V_5 -> V_377 ) ;
F_304 ( & V_44 -> V_351 , & V_5 -> V_403 ) ;
F_101 ( & V_5 -> V_377 ) ;
F_339 ( V_385 ) ;
F_339 ( V_384 ) ;
return V_276 ;
V_400:
F_79 ( V_9 ) ;
V_392:
F_339 ( V_385 ) ;
V_390:
F_321 ( V_44 -> V_336 ) ;
V_389:
F_339 ( V_384 ) ;
V_388:
F_213 ( V_44 ) ;
return V_103 ;
}
static void F_340 ( struct V_4 * V_5 , unsigned int V_404 )
{
F_56 ( F_124 ( & V_5 -> V_236 . V_405 ) <= 0 ) ;
F_341 ( V_404 , & V_5 -> V_236 . V_405 ) ;
}
static void F_342 ( struct V_4 * V_5 , unsigned int V_404 )
{
F_56 ( F_124 ( & V_5 -> V_236 . V_405 ) < V_404 ) ;
if ( F_343 ( V_404 , & V_5 -> V_236 . V_405 ) ) {
F_344 ( & V_406 , V_5 -> V_236 . V_236 ) ;
V_5 -> V_236 . V_236 = 0 ;
F_79 ( & V_5 -> V_9 ) ;
}
}
static inline void F_345 ( struct V_4 * V_5 )
{
F_340 ( V_5 , 1 ) ;
}
static inline void F_346 ( struct V_4 * V_5 )
{
F_342 ( V_5 , 1 ) ;
}
struct V_4 * F_347 ( unsigned short V_236 )
{
F_348 ( ! F_349 () ) ;
return F_350 ( & V_406 , V_236 ) ;
}
static int F_351 ( struct V_4 * V_5 , int V_153 )
{
struct V_16 * V_407 ;
int V_353 = V_153 ;
if ( ! F_352 ( V_153 , V_408 ) )
V_353 = - 1 ;
V_407 = F_353 ( sizeof( * V_407 ) , V_208 , V_353 ) ;
if ( ! V_407 )
return 1 ;
V_407 -> V_409 = F_354 ( struct V_409 ) ;
if ( ! V_407 -> V_409 ) {
F_213 ( V_407 ) ;
return 1 ;
}
F_355 ( & V_407 -> V_59 ) ;
V_407 -> V_31 = 0 ;
V_407 -> V_30 = false ;
V_407 -> V_5 = V_5 ;
V_5 -> V_18 [ V_153 ] = V_407 ;
return 0 ;
}
static void F_356 ( struct V_4 * V_5 , int V_153 )
{
struct V_16 * V_407 = V_5 -> V_18 [ V_153 ] ;
F_357 ( V_407 -> V_409 ) ;
F_213 ( V_407 ) ;
}
static void F_358 ( struct V_4 * V_5 )
{
int V_153 ;
F_35 (node)
F_356 ( V_5 , V_153 ) ;
F_357 ( V_5 -> V_47 ) ;
F_213 ( V_5 ) ;
}
static void F_359 ( struct V_4 * V_5 )
{
F_313 ( V_5 ) ;
F_358 ( V_5 ) ;
}
static struct V_4 * F_360 ( void )
{
struct V_4 * V_5 ;
T_8 V_110 ;
int V_153 ;
V_110 = sizeof( struct V_4 ) ;
V_110 += V_63 * sizeof( struct V_16 * ) ;
V_5 = F_329 ( V_110 , V_208 ) ;
if ( ! V_5 )
return NULL ;
V_5 -> V_236 . V_236 = F_361 ( & V_406 , NULL ,
1 , V_410 ,
V_208 ) ;
if ( V_5 -> V_236 . V_236 < 0 )
goto V_411;
V_5 -> V_47 = F_354 ( struct V_412 ) ;
if ( ! V_5 -> V_47 )
goto V_411;
F_35 (node)
if ( F_351 ( V_5 , V_153 ) )
goto V_411;
if ( F_311 ( V_5 , V_208 ) )
goto V_411;
F_216 ( & V_5 -> V_207 , F_174 ) ;
V_5 -> V_154 = V_76 ;
F_146 ( & V_5 -> V_352 ) ;
F_362 ( & V_5 -> V_347 ) ;
F_363 ( & V_5 -> V_190 ) ;
F_364 ( & V_5 -> V_3 ) ;
F_146 ( & V_5 -> V_403 ) ;
F_363 ( & V_5 -> V_377 ) ;
V_5 -> V_413 = V_414 ;
#ifndef F_365
V_5 -> V_252 = - 1 ;
#endif
#ifdef F_366
F_146 ( & V_5 -> V_357 ) ;
#endif
F_367 ( & V_406 , V_5 , V_5 -> V_236 . V_236 ) ;
return V_5 ;
V_411:
if ( V_5 -> V_236 . V_236 > 0 )
F_344 ( & V_406 , V_5 -> V_236 . V_236 ) ;
F_358 ( V_5 ) ;
return NULL ;
}
static struct V_7 * T_12
F_368 ( struct V_7 * V_415 )
{
struct V_4 * V_28 = F_70 ( V_415 ) ;
struct V_4 * V_5 ;
long error = - V_231 ;
V_5 = F_360 () ;
if ( ! V_5 )
return F_369 ( error ) ;
V_5 -> V_205 = V_319 ;
V_5 -> V_38 = V_319 ;
if ( V_28 ) {
V_5 -> V_325 = F_117 ( V_28 ) ;
V_5 -> V_187 = V_28 -> V_187 ;
}
if ( V_28 && V_28 -> V_91 ) {
V_5 -> V_91 = true ;
F_370 ( & V_5 -> V_37 , & V_28 -> V_37 ) ;
F_370 ( & V_5 -> V_137 , & V_28 -> V_137 ) ;
F_370 ( & V_5 -> V_116 , & V_28 -> V_116 ) ;
F_370 ( & V_5 -> V_128 , & V_28 -> V_128 ) ;
F_370 ( & V_5 -> V_289 , & V_28 -> V_289 ) ;
} else {
F_370 ( & V_5 -> V_37 , NULL ) ;
F_370 ( & V_5 -> V_137 , NULL ) ;
F_370 ( & V_5 -> V_116 , NULL ) ;
F_370 ( & V_5 -> V_128 , NULL ) ;
F_370 ( & V_5 -> V_289 , NULL ) ;
if ( V_28 != V_6 )
V_1 . V_416 = true ;
}
if ( ! V_28 ) {
V_6 = V_5 ;
return & V_5 -> V_9 ;
}
error = F_259 ( V_5 ) ;
if ( error )
goto V_411;
if ( F_2 ( V_1 ) && ! V_417 )
F_260 ( & V_305 ) ;
return & V_5 -> V_9 ;
V_411:
F_359 ( V_5 ) ;
return F_369 ( - V_231 ) ;
}
static int F_371 ( struct V_7 * V_9 )
{
struct V_4 * V_5 = F_70 ( V_9 ) ;
F_128 ( & V_5 -> V_236 . V_405 , 1 ) ;
F_95 ( V_9 ) ;
return 0 ;
}
static void F_372 ( struct V_7 * V_9 )
{
struct V_4 * V_5 = F_70 ( V_9 ) ;
struct F_172 * V_44 , * V_353 ;
F_100 ( & V_5 -> V_377 ) ;
F_306 (event, tmp, &memcg->event_list, list) {
F_324 ( & V_44 -> V_351 ) ;
F_189 ( & V_44 -> remove ) ;
}
F_101 ( & V_5 -> V_377 ) ;
F_261 ( V_5 ) ;
F_373 ( V_5 ) ;
F_346 ( V_5 ) ;
}
static void F_374 ( struct V_7 * V_9 )
{
struct V_4 * V_5 = F_70 ( V_9 ) ;
F_81 ( V_5 ) ;
}
static void F_375 ( struct V_7 * V_9 )
{
struct V_4 * V_5 = F_70 ( V_9 ) ;
if ( F_2 ( V_1 ) && ! V_417 )
F_267 ( & V_305 ) ;
if ( ! F_2 ( V_1 ) && V_5 -> V_304 )
F_267 ( & V_305 ) ;
F_376 ( & V_5 -> V_3 ) ;
F_377 ( & V_5 -> V_207 ) ;
F_34 ( V_5 ) ;
F_265 ( V_5 ) ;
F_359 ( V_5 ) ;
}
static void F_378 ( struct V_7 * V_9 )
{
struct V_4 * V_5 = F_70 ( V_9 ) ;
F_239 ( & V_5 -> V_37 , V_319 ) ;
F_239 ( & V_5 -> V_137 , V_319 ) ;
F_239 ( & V_5 -> V_116 , V_319 ) ;
F_239 ( & V_5 -> V_128 , V_319 ) ;
F_239 ( & V_5 -> V_289 , V_319 ) ;
V_5 -> V_418 = 0 ;
V_5 -> V_205 = V_319 ;
V_5 -> V_38 = V_319 ;
F_315 ( V_5 ) ;
}
static int F_379 ( unsigned long V_50 )
{
int V_103 ;
V_103 = F_177 ( V_119 . V_118 , V_208 & ~ V_419 , V_50 ) ;
if ( ! V_103 ) {
V_119 . V_420 += V_50 ;
return V_103 ;
}
while ( V_50 -- ) {
V_103 = F_177 ( V_119 . V_118 , V_208 | V_226 , 1 ) ;
if ( V_103 )
return V_103 ;
V_119 . V_420 ++ ;
F_380 () ;
}
return 0 ;
}
static struct V_11 * F_381 ( struct V_421 * V_422 ,
unsigned long V_423 , T_13 V_424 )
{
struct V_11 * V_11 = F_382 ( V_422 , V_423 , V_424 ) ;
if ( ! V_11 || ! F_383 ( V_11 ) )
return NULL ;
if ( F_47 ( V_11 ) ) {
if ( ! ( V_119 . V_13 & V_425 ) )
return NULL ;
} else {
if ( ! ( V_119 . V_13 & V_426 ) )
return NULL ;
}
if ( ! F_384 ( V_11 ) )
return NULL ;
return V_11 ;
}
static struct V_11 * F_385 ( struct V_421 * V_422 ,
T_13 V_424 , T_6 * V_185 )
{
struct V_11 * V_11 = NULL ;
T_6 V_427 = F_386 ( V_424 ) ;
if ( ! ( V_119 . V_13 & V_425 ) || F_387 ( V_427 ) )
return NULL ;
V_11 = F_388 ( F_389 ( V_427 ) , F_390 ( V_427 ) ) ;
if ( F_1 () )
V_185 -> V_45 = V_427 . V_45 ;
return V_11 ;
}
static struct V_11 * F_385 ( struct V_421 * V_422 ,
T_13 V_424 , T_6 * V_185 )
{
return NULL ;
}
static struct V_11 * F_391 ( struct V_421 * V_422 ,
unsigned long V_423 , T_13 V_424 , T_6 * V_185 )
{
struct V_11 * V_11 = NULL ;
struct V_428 * V_429 ;
T_14 V_430 ;
if ( ! V_422 -> V_431 )
return NULL ;
if ( ! ( V_119 . V_13 & V_426 ) )
return NULL ;
V_429 = V_422 -> V_431 -> V_432 ;
V_430 = F_392 ( V_422 , V_423 ) ;
#ifdef F_393
if ( F_394 ( V_429 ) ) {
V_11 = F_395 ( V_429 , V_430 ) ;
if ( F_396 ( V_11 ) ) {
T_6 V_433 = F_397 ( V_11 ) ;
if ( F_1 () )
* V_185 = V_433 ;
V_11 = F_388 ( F_389 ( V_433 ) ,
F_390 ( V_433 ) ) ;
}
} else
V_11 = F_388 ( V_429 , V_430 ) ;
#else
V_11 = F_388 ( V_429 , V_430 ) ;
#endif
return V_11 ;
}
static int F_398 ( struct V_11 * V_11 ,
bool V_49 ,
struct V_4 * V_117 ,
struct V_4 * V_118 )
{
unsigned long V_13 ;
unsigned int V_36 = V_49 ? F_399 ( V_11 ) : 1 ;
int V_103 ;
bool V_434 ;
F_56 ( V_117 == V_118 ) ;
F_50 ( F_195 ( V_11 ) , V_11 ) ;
F_56 ( V_49 && ! F_51 ( V_11 ) ) ;
V_103 = - V_282 ;
if ( ! F_400 ( V_11 ) )
goto V_92;
V_103 = - V_260 ;
if ( V_11 -> V_4 != V_117 )
goto V_97;
V_434 = F_47 ( V_11 ) ;
F_29 ( & V_117 -> V_190 , V_13 ) ;
if ( ! V_434 && F_383 ( V_11 ) ) {
F_231 ( V_117 -> V_47 -> V_50 [ V_435 ] , V_36 ) ;
F_48 ( V_118 -> V_47 -> V_50 [ V_435 ] , V_36 ) ;
}
if ( ! V_434 && F_401 ( V_11 ) ) {
struct V_428 * V_429 = F_402 ( V_11 ) ;
if ( F_403 ( V_429 ) ) {
F_231 ( V_117 -> V_47 -> V_50 [ V_367 ] ,
V_36 ) ;
F_48 ( V_118 -> V_47 -> V_50 [ V_367 ] ,
V_36 ) ;
}
}
if ( F_404 ( V_11 ) ) {
F_231 ( V_117 -> V_47 -> V_50 [ V_368 ] , V_36 ) ;
F_48 ( V_118 -> V_47 -> V_50 [ V_368 ] , V_36 ) ;
}
V_11 -> V_4 = V_118 ;
F_30 ( & V_117 -> V_190 , V_13 ) ;
V_103 = 0 ;
F_405 () ;
F_46 ( V_118 , V_11 , V_49 , V_36 ) ;
F_65 ( V_118 , V_11 ) ;
F_46 ( V_117 , V_11 , V_49 , - V_36 ) ;
F_65 ( V_117 , V_11 ) ;
F_406 () ;
V_97:
F_407 ( V_11 ) ;
V_92:
return V_103 ;
}
static enum V_436 F_408 ( struct V_421 * V_422 ,
unsigned long V_423 , T_13 V_424 , union V_437 * V_65 )
{
struct V_11 * V_11 = NULL ;
enum V_436 V_103 = V_438 ;
T_6 V_427 = { . V_45 = 0 } ;
if ( F_409 ( V_424 ) )
V_11 = F_381 ( V_422 , V_423 , V_424 ) ;
else if ( F_410 ( V_424 ) )
V_11 = F_385 ( V_422 , V_424 , & V_427 ) ;
else if ( F_411 ( V_424 ) )
V_11 = F_391 ( V_422 , V_423 , V_424 , & V_427 ) ;
if ( ! V_11 && ! V_427 . V_45 )
return V_103 ;
if ( V_11 ) {
if ( V_11 -> V_4 == V_119 . V_117 ) {
V_103 = V_439 ;
if ( V_65 )
V_65 -> V_11 = V_11 ;
}
if ( ! V_103 || ! V_65 )
F_412 ( V_11 ) ;
}
if ( V_427 . V_45 && ! V_103 &&
F_235 ( V_119 . V_117 ) == F_413 ( V_427 ) ) {
V_103 = V_440 ;
if ( V_65 )
V_65 -> V_427 = V_427 ;
}
return V_103 ;
}
static enum V_436 F_414 ( struct V_421 * V_422 ,
unsigned long V_423 , T_15 V_441 , union V_437 * V_65 )
{
struct V_11 * V_11 = NULL ;
enum V_436 V_103 = V_438 ;
V_11 = F_415 ( V_441 ) ;
F_50 ( ! V_11 || ! F_416 ( V_11 ) , V_11 ) ;
if ( ! ( V_119 . V_13 & V_425 ) )
return V_103 ;
if ( V_11 -> V_4 == V_119 . V_117 ) {
V_103 = V_439 ;
if ( V_65 ) {
F_417 ( V_11 ) ;
V_65 -> V_11 = V_11 ;
}
}
return V_103 ;
}
static inline enum V_436 F_414 ( struct V_421 * V_422 ,
unsigned long V_423 , T_15 V_441 , union V_437 * V_65 )
{
return V_438 ;
}
static int F_418 ( T_15 * V_441 ,
unsigned long V_423 , unsigned long V_442 ,
struct V_443 * V_444 )
{
struct V_421 * V_422 = V_444 -> V_422 ;
T_13 * V_445 ;
T_16 * V_446 ;
V_446 = F_419 ( V_441 , V_422 ) ;
if ( V_446 ) {
if ( F_414 ( V_422 , V_423 , * V_441 , NULL ) == V_439 )
V_119 . V_420 += V_256 ;
F_101 ( V_446 ) ;
return 0 ;
}
if ( F_420 ( V_441 ) )
return 0 ;
V_445 = F_421 ( V_422 -> V_447 , V_441 , V_423 , & V_446 ) ;
for (; V_423 != V_442 ; V_445 ++ , V_423 += V_230 )
if ( F_408 ( V_422 , V_423 , * V_445 , NULL ) )
V_119 . V_420 ++ ;
F_422 ( V_445 - 1 , V_446 ) ;
F_380 () ;
return 0 ;
}
static unsigned long F_423 ( struct V_80 * V_81 )
{
unsigned long V_420 ;
struct V_443 V_448 = {
. V_449 = F_418 ,
. V_81 = V_81 ,
} ;
F_8 ( & V_81 -> V_450 ) ;
F_424 ( 0 , V_81 -> V_451 ,
& V_448 ) ;
F_10 ( & V_81 -> V_450 ) ;
V_420 = V_119 . V_420 ;
V_119 . V_420 = 0 ;
return V_420 ;
}
static int F_425 ( struct V_80 * V_81 )
{
unsigned long V_420 = F_423 ( V_81 ) ;
F_56 ( V_119 . V_121 ) ;
V_119 . V_121 = V_122 ;
return F_379 ( V_420 ) ;
}
static void F_426 ( void )
{
struct V_4 * V_117 = V_119 . V_117 ;
struct V_4 * V_118 = V_119 . V_118 ;
if ( V_119 . V_420 ) {
F_191 ( V_119 . V_118 , V_119 . V_420 ) ;
V_119 . V_420 = 0 ;
}
if ( V_119 . V_452 ) {
F_191 ( V_119 . V_117 , V_119 . V_452 ) ;
V_119 . V_452 = 0 ;
}
if ( V_119 . V_453 ) {
if ( ! F_6 ( V_119 . V_117 ) )
F_156 ( & V_119 . V_117 -> V_116 , V_119 . V_453 ) ;
F_342 ( V_119 . V_117 , V_119 . V_453 ) ;
if ( ! F_6 ( V_119 . V_118 ) )
F_156 ( & V_119 . V_118 -> V_37 , V_119 . V_453 ) ;
F_340 ( V_119 . V_118 , V_119 . V_453 ) ;
F_157 ( & V_119 . V_118 -> V_9 , V_119 . V_453 ) ;
V_119 . V_453 = 0 ;
}
F_142 ( V_117 ) ;
F_142 ( V_118 ) ;
F_427 ( & V_119 . V_124 ) ;
}
static void F_428 ( void )
{
struct V_80 * V_81 = V_119 . V_81 ;
V_119 . V_121 = NULL ;
F_426 () ;
F_100 ( & V_119 . V_35 ) ;
V_119 . V_117 = NULL ;
V_119 . V_118 = NULL ;
V_119 . V_81 = NULL ;
F_101 ( & V_119 . V_35 ) ;
F_429 ( V_81 ) ;
}
static int F_430 ( struct V_454 * V_455 )
{
struct V_7 * V_9 ;
struct V_4 * V_5 = NULL ;
struct V_4 * V_117 ;
struct V_78 * V_456 , * V_26 ;
struct V_80 * V_81 ;
unsigned long V_457 ;
int V_103 = 0 ;
if ( F_2 ( V_1 ) )
return 0 ;
V_26 = NULL ;
F_431 (leader, css, tset) {
F_348 ( V_26 ) ;
V_26 = V_456 ;
V_5 = F_70 ( V_9 ) ;
}
if ( ! V_26 )
return 0 ;
V_457 = F_14 ( V_5 -> V_306 ) ;
if ( ! V_457 )
return 0 ;
V_117 = F_69 ( V_26 ) ;
F_56 ( V_117 == V_5 ) ;
V_81 = F_432 ( V_26 ) ;
if ( ! V_81 )
return 0 ;
if ( V_81 -> V_82 == V_26 ) {
F_56 ( V_119 . V_117 ) ;
F_56 ( V_119 . V_118 ) ;
F_56 ( V_119 . V_420 ) ;
F_56 ( V_119 . V_452 ) ;
F_56 ( V_119 . V_453 ) ;
F_100 ( & V_119 . V_35 ) ;
V_119 . V_81 = V_81 ;
V_119 . V_117 = V_117 ;
V_119 . V_118 = V_5 ;
V_119 . V_13 = V_457 ;
F_101 ( & V_119 . V_35 ) ;
V_103 = F_425 ( V_81 ) ;
if ( V_103 )
F_428 () ;
} else {
F_429 ( V_81 ) ;
}
return V_103 ;
}
static void F_433 ( struct V_454 * V_455 )
{
if ( V_119 . V_118 )
F_428 () ;
}
static int F_434 ( T_15 * V_441 ,
unsigned long V_423 , unsigned long V_442 ,
struct V_443 * V_444 )
{
int V_103 = 0 ;
struct V_421 * V_422 = V_444 -> V_422 ;
T_13 * V_445 ;
T_16 * V_446 ;
enum V_436 V_458 ;
union V_437 V_65 ;
struct V_11 * V_11 ;
V_446 = F_419 ( V_441 , V_422 ) ;
if ( V_446 ) {
if ( V_119 . V_420 < V_256 ) {
F_101 ( V_446 ) ;
return 0 ;
}
V_458 = F_414 ( V_422 , V_423 , * V_441 , & V_65 ) ;
if ( V_458 == V_439 ) {
V_11 = V_65 . V_11 ;
if ( ! F_435 ( V_11 ) ) {
if ( ! F_398 ( V_11 , true ,
V_119 . V_117 , V_119 . V_118 ) ) {
V_119 . V_420 -= V_256 ;
V_119 . V_452 += V_256 ;
}
F_436 ( V_11 ) ;
}
F_412 ( V_11 ) ;
}
F_101 ( V_446 ) ;
return 0 ;
}
if ( F_420 ( V_441 ) )
return 0 ;
V_41:
V_445 = F_421 ( V_422 -> V_447 , V_441 , V_423 , & V_446 ) ;
for (; V_423 != V_442 ; V_423 += V_230 ) {
T_13 V_424 = * ( V_445 ++ ) ;
T_6 V_427 ;
if ( ! V_119 . V_420 )
break;
switch ( F_408 ( V_422 , V_423 , V_424 , & V_65 ) ) {
case V_439 :
V_11 = V_65 . V_11 ;
if ( F_437 ( V_11 ) )
goto V_459;
if ( F_435 ( V_11 ) )
goto V_459;
if ( ! F_398 ( V_11 , false ,
V_119 . V_117 , V_119 . V_118 ) ) {
V_119 . V_420 -- ;
V_119 . V_452 ++ ;
}
F_436 ( V_11 ) ;
V_459:
F_412 ( V_11 ) ;
break;
case V_440 :
V_427 = V_65 . V_427 ;
if ( ! F_234 ( V_427 , V_119 . V_117 , V_119 . V_118 ) ) {
V_119 . V_420 -- ;
V_119 . V_453 ++ ;
}
break;
default:
break;
}
}
F_422 ( V_445 - 1 , V_446 ) ;
F_380 () ;
if ( V_423 != V_442 ) {
V_103 = F_379 ( 1 ) ;
if ( ! V_103 )
goto V_41;
}
return V_103 ;
}
static void F_438 ( void )
{
struct V_443 V_460 = {
. V_449 = F_434 ,
. V_81 = V_119 . V_81 ,
} ;
F_246 () ;
F_68 ( & V_119 . V_117 -> V_189 ) ;
F_297 () ;
V_41:
if ( F_66 ( ! F_439 ( & V_119 . V_81 -> V_450 ) ) ) {
F_426 () ;
F_380 () ;
goto V_41;
}
F_424 ( 0 , V_119 . V_81 -> V_451 , & V_460 ) ;
F_10 ( & V_119 . V_81 -> V_450 ) ;
F_440 ( & V_119 . V_117 -> V_189 ) ;
}
static void F_441 ( void )
{
if ( V_119 . V_118 ) {
F_438 () ;
F_428 () ;
}
}
static int F_430 ( struct V_454 * V_455 )
{
return 0 ;
}
static void F_433 ( struct V_454 * V_455 )
{
}
static void F_441 ( void )
{
}
static void F_442 ( struct V_7 * V_461 )
{
if ( F_2 ( V_1 ) )
V_6 -> V_91 = true ;
else
V_6 -> V_91 = false ;
}
static V_126 F_443 ( struct V_7 * V_9 ,
struct V_278 * V_279 )
{
struct V_4 * V_5 = F_70 ( V_9 ) ;
return ( V_126 ) F_32 ( & V_5 -> V_37 ) * V_230 ;
}
static int F_444 ( struct V_309 * V_310 , void * V_311 )
{
struct V_4 * V_5 = F_70 ( F_280 ( V_310 ) ) ;
unsigned long V_418 = F_14 ( V_5 -> V_418 ) ;
if ( V_418 == V_319 )
F_445 ( V_310 , L_35 ) ;
else
F_281 ( V_310 , L_36 , ( V_126 ) V_418 * V_230 ) ;
return 0 ;
}
static T_7 F_446 ( struct V_273 * V_274 ,
char * V_275 , T_8 V_276 , T_9 V_277 )
{
struct V_4 * V_5 = F_70 ( F_249 ( V_274 ) ) ;
unsigned long V_418 ;
int V_237 ;
V_275 = F_272 ( V_275 ) ;
V_237 = F_273 ( V_275 , L_37 , & V_418 ) ;
if ( V_237 )
return V_237 ;
V_5 -> V_418 = V_418 ;
return V_276 ;
}
static int F_447 ( struct V_309 * V_310 , void * V_311 )
{
struct V_4 * V_5 = F_70 ( F_280 ( V_310 ) ) ;
unsigned long V_205 = F_14 ( V_5 -> V_205 ) ;
if ( V_205 == V_319 )
F_445 ( V_310 , L_35 ) ;
else
F_281 ( V_310 , L_36 , ( V_126 ) V_205 * V_230 ) ;
return 0 ;
}
static T_7 F_448 ( struct V_273 * V_274 ,
char * V_275 , T_8 V_276 , T_9 V_277 )
{
struct V_4 * V_5 = F_70 ( F_249 ( V_274 ) ) ;
unsigned long V_36 ;
unsigned long V_205 ;
int V_237 ;
V_275 = F_272 ( V_275 ) ;
V_237 = F_273 ( V_275 , L_37 , & V_205 ) ;
if ( V_237 )
return V_237 ;
V_5 -> V_205 = V_205 ;
V_36 = F_32 ( & V_5 -> V_37 ) ;
if ( V_36 > V_205 )
F_173 ( V_5 , V_36 - V_205 ,
V_208 , true ) ;
F_315 ( V_5 ) ;
return V_276 ;
}
static int F_449 ( struct V_309 * V_310 , void * V_311 )
{
struct V_4 * V_5 = F_70 ( F_280 ( V_310 ) ) ;
unsigned long F_178 = F_14 ( V_5 -> V_37 . V_115 ) ;
if ( F_178 == V_319 )
F_445 ( V_310 , L_35 ) ;
else
F_281 ( V_310 , L_36 , ( V_126 ) F_178 * V_230 ) ;
return 0 ;
}
static T_7 F_450 ( struct V_273 * V_274 ,
char * V_275 , T_8 V_276 , T_9 V_277 )
{
struct V_4 * V_5 = F_70 ( F_249 ( V_274 ) ) ;
unsigned int V_462 = V_212 ;
bool V_218 = false ;
unsigned long F_178 ;
int V_237 ;
V_275 = F_272 ( V_275 ) ;
V_237 = F_273 ( V_275 , L_37 , & F_178 ) ;
if ( V_237 )
return V_237 ;
F_451 ( & V_5 -> V_37 . V_115 , F_178 ) ;
for (; ; ) {
unsigned long V_36 = F_32 ( & V_5 -> V_37 ) ;
if ( V_36 <= F_178 )
break;
if ( F_238 ( V_122 ) ) {
V_237 = - V_265 ;
break;
}
if ( ! V_218 ) {
F_161 ( V_5 ) ;
V_218 = true ;
continue;
}
if ( V_462 ) {
if ( ! F_173 ( V_5 , V_36 - F_178 ,
V_208 , true ) )
V_462 -- ;
continue;
}
F_172 ( V_5 , V_229 ) ;
if ( ! F_118 ( V_5 , V_208 , 0 ) )
break;
}
F_315 ( V_5 ) ;
return V_276 ;
}
static int F_452 ( struct V_309 * V_310 , void * V_311 )
{
struct V_4 * V_5 = F_70 ( F_280 ( V_310 ) ) ;
F_281 ( V_310 , L_38 , F_43 ( V_5 , V_463 ) ) ;
F_281 ( V_310 , L_39 , F_43 ( V_5 , V_206 ) ) ;
F_281 ( V_310 , L_40 , F_43 ( V_5 , V_225 ) ) ;
F_281 ( V_310 , L_41 , F_43 ( V_5 , V_229 ) ) ;
F_281 ( V_310 , L_30 , F_43 ( V_5 , V_355 ) ) ;
return 0 ;
}
static int F_453 ( struct V_309 * V_310 , void * V_311 )
{
struct V_4 * V_5 = F_70 ( F_280 ( V_310 ) ) ;
unsigned long V_47 [ V_283 ] ;
unsigned long V_48 [ V_284 ] ;
int V_100 ;
F_252 ( V_5 , V_47 ) ;
F_253 ( V_5 , V_48 ) ;
F_281 ( V_310 , L_42 ,
( V_126 ) V_47 [ V_51 ] * V_230 ) ;
F_281 ( V_310 , L_43 ,
( V_126 ) V_47 [ V_52 ] * V_230 ) ;
F_281 ( V_310 , L_44 ,
( V_126 ) V_47 [ V_464 ] * 1024 ) ;
F_281 ( V_310 , L_45 ,
( V_126 ) ( V_47 [ V_465 ] +
V_47 [ V_466 ] ) * V_230 ) ;
F_281 ( V_310 , L_46 ,
( V_126 ) V_47 [ V_467 ] * V_230 ) ;
F_281 ( V_310 , L_47 ,
( V_126 ) V_47 [ V_53 ] * V_230 ) ;
F_281 ( V_310 , L_48 ,
( V_126 ) V_47 [ V_435 ] * V_230 ) ;
F_281 ( V_310 , L_49 ,
( V_126 ) V_47 [ V_367 ] * V_230 ) ;
F_281 ( V_310 , L_50 ,
( V_126 ) V_47 [ V_368 ] * V_230 ) ;
for ( V_100 = 0 ; V_100 < V_132 ; V_100 ++ ) {
struct V_4 * V_316 ;
unsigned long V_45 = 0 ;
F_85 (mi, memcg)
V_45 += F_60 ( V_316 , F_58 ( V_100 ) ) ;
F_281 ( V_310 , L_51 ,
V_133 [ V_100 ] , ( V_126 ) V_45 * V_230 ) ;
}
F_281 ( V_310 , L_52 ,
( V_126 ) V_47 [ V_465 ] * V_230 ) ;
F_281 ( V_310 , L_53 ,
( V_126 ) V_47 [ V_466 ] * V_230 ) ;
F_281 ( V_310 , L_54 , V_48 [ V_468 ] ) ;
F_281 ( V_310 , L_55 , V_48 [ V_469 ] ) ;
F_281 ( V_310 , L_56 , V_48 [ V_470 ] ) ;
F_281 ( V_310 , L_57 , V_48 [ V_471 ] +
V_48 [ V_472 ] ) ;
F_281 ( V_310 , L_58 , V_48 [ V_473 ] +
V_48 [ V_474 ] ) ;
F_281 ( V_310 , L_59 , V_48 [ V_475 ] ) ;
F_281 ( V_310 , L_60 , V_48 [ V_476 ] ) ;
F_281 ( V_310 , L_61 , V_48 [ V_477 ] ) ;
F_281 ( V_310 , L_62 , V_48 [ V_478 ] ) ;
F_281 ( V_310 , L_63 ,
V_47 [ V_479 ] ) ;
F_281 ( V_310 , L_64 ,
V_47 [ V_480 ] ) ;
F_281 ( V_310 , L_65 ,
V_47 [ V_481 ] ) ;
return 0 ;
}
bool F_454 ( struct V_4 * V_83 , struct V_4 * V_5 )
{
if ( F_75 () )
return false ;
if ( ! V_83 )
V_83 = V_6 ;
if ( V_5 == V_83 )
return false ;
for (; V_5 != V_83 ; V_5 = F_15 ( V_5 ) ) {
if ( F_32 ( & V_5 -> V_37 ) >= V_5 -> V_418 )
return false ;
}
return true ;
}
int F_455 ( struct V_11 * V_11 , struct V_80 * V_81 ,
T_3 V_139 , struct V_4 * * V_482 ,
bool V_49 )
{
struct V_4 * V_5 = NULL ;
unsigned int V_36 = V_49 ? F_399 ( V_11 ) : 1 ;
int V_103 = 0 ;
if ( F_75 () )
goto V_92;
if ( F_456 ( V_11 ) ) {
F_50 ( ! F_457 ( V_11 ) , V_11 ) ;
if ( V_11 -> V_4 )
goto V_92;
if ( V_2 ) {
T_6 V_427 = { . V_45 = F_458 ( V_11 ) , } ;
unsigned short V_236 = F_413 ( V_427 ) ;
F_13 () ;
V_5 = F_347 ( V_236 ) ;
if ( V_5 && ! F_39 ( & V_5 -> V_9 ) )
V_5 = NULL ;
F_17 () ;
}
}
if ( ! V_5 )
V_5 = F_72 ( V_81 ) ;
V_103 = F_177 ( V_5 , V_139 , V_36 ) ;
F_79 ( & V_5 -> V_9 ) ;
V_92:
* V_482 = V_5 ;
return V_103 ;
}
void F_459 ( struct V_11 * V_11 , struct V_4 * V_5 ,
bool V_235 , bool V_49 )
{
unsigned int V_36 = V_49 ? F_399 ( V_11 ) : 1 ;
F_50 ( ! V_11 -> V_429 , V_11 ) ;
F_50 ( F_195 ( V_11 ) && ! V_235 , V_11 ) ;
if ( F_75 () )
return;
if ( ! V_5 )
return;
F_202 ( V_11 , V_5 , V_235 ) ;
F_405 () ;
F_46 ( V_5 , V_11 , V_49 , V_36 ) ;
F_65 ( V_5 , V_11 ) ;
F_406 () ;
if ( F_1 () && F_456 ( V_11 ) ) {
T_6 V_185 = { . V_45 = F_458 (page) } ;
F_460 ( V_185 , V_36 ) ;
}
}
void F_461 ( struct V_11 * V_11 , struct V_4 * V_5 ,
bool V_49 )
{
unsigned int V_36 = V_49 ? F_399 ( V_11 ) : 1 ;
if ( F_75 () )
return;
if ( ! V_5 )
return;
F_191 ( V_5 , V_36 ) ;
}
static void F_462 ( struct V_4 * V_5 , unsigned long V_483 ,
unsigned long V_484 , unsigned long V_485 ,
unsigned long V_486 , unsigned long V_487 ,
unsigned long V_488 , struct V_11 * V_489 )
{
unsigned long V_36 = V_484 + V_485 + V_486 ;
unsigned long V_13 ;
if ( ! F_6 ( V_5 ) ) {
F_156 ( & V_5 -> V_37 , V_36 ) ;
if ( F_1 () )
F_156 ( & V_5 -> V_116 , V_36 ) ;
if ( ! F_2 ( V_1 ) && V_486 )
F_156 ( & V_5 -> V_128 , V_486 ) ;
F_142 ( V_5 ) ;
}
F_152 ( V_13 ) ;
F_231 ( V_5 -> V_47 -> V_50 [ V_51 ] , V_484 ) ;
F_231 ( V_5 -> V_47 -> V_50 [ V_52 ] , V_485 ) ;
F_231 ( V_5 -> V_47 -> V_50 [ V_54 ] , V_487 ) ;
F_231 ( V_5 -> V_47 -> V_50 [ V_53 ] , V_488 ) ;
F_48 ( V_5 -> V_47 -> V_48 [ V_56 ] , V_483 ) ;
F_48 ( V_5 -> V_47 -> V_57 , V_36 ) ;
F_65 ( V_5 , V_489 ) ;
F_154 ( V_13 ) ;
if ( ! F_6 ( V_5 ) )
F_157 ( & V_5 -> V_9 , V_36 ) ;
}
static void F_463 ( struct V_356 * V_490 )
{
struct V_4 * V_5 = NULL ;
unsigned long V_488 = 0 ;
unsigned long V_484 = 0 ;
unsigned long V_485 = 0 ;
unsigned long V_487 = 0 ;
unsigned long V_486 = 0 ;
unsigned long V_483 = 0 ;
struct V_356 * V_66 ;
struct V_11 * V_11 ;
V_66 = V_490 -> V_66 ;
do {
V_11 = F_464 ( V_66 , struct V_11 , V_62 ) ;
V_66 = V_11 -> V_62 . V_66 ;
F_50 ( F_195 ( V_11 ) , V_11 ) ;
F_50 ( ! F_465 ( V_11 ) && F_466 ( V_11 ) , V_11 ) ;
if ( ! V_11 -> V_4 )
continue;
if ( V_5 != V_11 -> V_4 ) {
if ( V_5 ) {
F_462 ( V_5 , V_483 , V_484 , V_485 ,
V_486 , V_487 , V_488 , V_11 ) ;
V_483 = V_484 = V_485 = V_486 = 0 ;
V_487 = V_488 = 0 ;
}
V_5 = V_11 -> V_4 ;
}
if ( ! F_228 ( V_11 ) ) {
unsigned int V_36 = 1 ;
if ( F_51 ( V_11 ) ) {
V_36 <<= F_467 ( V_11 ) ;
V_487 += V_36 ;
}
if ( F_47 ( V_11 ) )
V_484 += V_36 ;
else {
V_485 += V_36 ;
if ( F_49 ( V_11 ) )
V_488 += V_36 ;
}
V_483 ++ ;
} else {
V_486 += 1 << F_467 ( V_11 ) ;
F_229 ( V_11 ) ;
}
V_11 -> V_4 = NULL ;
} while ( V_66 != V_490 );
if ( V_5 )
F_462 ( V_5 , V_483 , V_484 , V_485 ,
V_486 , V_487 , V_488 , V_11 ) ;
}
void F_468 ( struct V_11 * V_11 )
{
if ( F_75 () )
return;
if ( ! V_11 -> V_4 )
return;
F_146 ( & V_11 -> V_62 ) ;
F_463 ( & V_11 -> V_62 ) ;
}
void F_469 ( struct V_356 * V_490 )
{
if ( F_75 () )
return;
if ( ! F_323 ( V_490 ) )
F_463 ( V_490 ) ;
}
void F_470 ( struct V_11 * V_491 , struct V_11 * V_492 )
{
struct V_4 * V_5 ;
unsigned int V_36 ;
bool V_49 ;
unsigned long V_13 ;
F_50 ( ! F_457 ( V_491 ) , V_491 ) ;
F_50 ( ! F_457 ( V_492 ) , V_492 ) ;
F_50 ( F_47 ( V_491 ) != F_47 ( V_492 ) , V_492 ) ;
F_50 ( F_51 ( V_491 ) != F_51 ( V_492 ) ,
V_492 ) ;
if ( F_75 () )
return;
if ( V_492 -> V_4 )
return;
V_5 = V_491 -> V_4 ;
if ( ! V_5 )
return;
V_49 = F_51 ( V_492 ) ;
V_36 = V_49 ? F_399 ( V_492 ) : 1 ;
F_186 ( & V_5 -> V_37 , V_36 ) ;
if ( F_1 () )
F_186 ( & V_5 -> V_116 , V_36 ) ;
F_187 ( & V_5 -> V_9 , V_36 ) ;
F_202 ( V_492 , V_5 , false ) ;
F_152 ( V_13 ) ;
F_46 ( V_5 , V_492 , V_49 , V_36 ) ;
F_65 ( V_5 , V_492 ) ;
F_154 ( V_13 ) ;
}
void F_471 ( struct V_493 * V_494 )
{
struct V_4 * V_5 ;
if ( ! V_495 )
return;
if ( V_494 -> V_496 ) {
F_84 ( F_6 ( V_494 -> V_496 ) ) ;
F_95 ( & V_494 -> V_496 -> V_9 ) ;
return;
}
F_13 () ;
V_5 = F_69 ( V_122 ) ;
if ( V_5 == V_6 )
goto V_92;
if ( ! F_2 ( V_1 ) && ! V_5 -> V_304 )
goto V_92;
if ( F_39 ( & V_5 -> V_9 ) )
V_494 -> V_496 = V_5 ;
V_92:
F_17 () ;
}
void F_472 ( struct V_493 * V_494 )
{
if ( V_494 -> V_496 )
F_79 ( & V_494 -> V_496 -> V_9 ) ;
}
bool F_473 ( struct V_4 * V_5 , unsigned int V_36 )
{
T_3 V_139 = V_208 ;
if ( ! F_2 ( V_1 ) ) {
struct V_214 * V_411 ;
if ( F_179 ( & V_5 -> V_289 , V_36 , & V_411 ) ) {
V_5 -> V_497 = 0 ;
return true ;
}
F_186 ( & V_5 -> V_289 , V_36 ) ;
V_5 -> V_497 = 1 ;
return false ;
}
if ( F_474 () )
V_139 = V_247 ;
F_233 ( V_5 -> V_47 -> V_50 [ V_467 ] , V_36 ) ;
if ( F_177 ( V_5 , V_139 , V_36 ) == 0 )
return true ;
F_177 ( V_5 , V_139 | V_228 , V_36 ) ;
return false ;
}
void F_475 ( struct V_4 * V_5 , unsigned int V_36 )
{
if ( ! F_2 ( V_1 ) ) {
F_156 ( & V_5 -> V_289 , V_36 ) ;
return;
}
F_476 ( V_5 -> V_47 -> V_50 [ V_467 ] , V_36 ) ;
F_156 ( & V_5 -> V_37 , V_36 ) ;
F_157 ( & V_5 -> V_9 , V_36 ) ;
}
static int T_17 F_477 ( char * V_498 )
{
char * V_499 ;
while ( ( V_499 = F_478 ( & V_498 , L_66 ) ) != NULL ) {
if ( ! * V_499 )
continue;
if ( ! strcmp ( V_499 , L_67 ) )
V_417 = true ;
if ( ! strcmp ( V_499 , L_68 ) )
V_297 = true ;
}
return 0 ;
}
static int T_17 F_479 ( void )
{
int V_46 , V_153 ;
#ifndef F_365
V_248 = F_480 ( L_69 , 0 , 1 ) ;
F_84 ( ! V_248 ) ;
#endif
F_481 ( V_500 , L_70 , NULL ,
F_170 ) ;
F_44 (cpu)
F_216 ( & F_482 ( & V_196 , V_46 ) -> V_204 ,
F_158 ) ;
F_35 (node) {
struct V_19 * V_501 ;
V_501 = F_353 ( sizeof( * V_501 ) , V_208 ,
F_483 ( V_153 ) ? V_153 : V_502 ) ;
V_501 -> V_27 = V_503 ;
F_363 ( & V_501 -> V_35 ) ;
V_20 . V_21 [ V_153 ] = V_501 ;
}
return 0 ;
}
static struct V_4 * F_484 ( struct V_4 * V_5 )
{
while ( ! F_485 ( & V_5 -> V_236 . V_405 ) ) {
if ( F_348 ( V_5 == V_6 ) ) {
F_56 ( 1 ) ;
break;
}
V_5 = F_15 ( V_5 ) ;
if ( ! V_5 )
V_5 = V_6 ;
}
return V_5 ;
}
void F_486 ( struct V_11 * V_11 , T_6 V_185 )
{
struct V_4 * V_5 , * V_504 ;
unsigned short V_505 ;
F_50 ( F_195 ( V_11 ) , V_11 ) ;
F_50 ( F_466 ( V_11 ) , V_11 ) ;
if ( ! F_1 () )
return;
V_5 = V_11 -> V_4 ;
if ( ! V_5 )
return;
V_504 = F_484 ( V_5 ) ;
V_505 = F_487 ( V_185 , F_235 ( V_504 ) , 1 ) ;
F_50 ( V_505 , V_11 ) ;
F_232 ( V_504 , 1 ) ;
V_11 -> V_4 = NULL ;
if ( ! F_6 ( V_5 ) )
F_156 ( & V_5 -> V_37 , 1 ) ;
if ( V_5 != V_504 ) {
if ( ! F_6 ( V_504 ) )
F_186 ( & V_504 -> V_116 , 1 ) ;
F_156 ( & V_5 -> V_116 , 1 ) ;
}
F_56 ( ! F_488 () ) ;
F_46 ( V_5 , V_11 , false , - 1 ) ;
F_65 ( V_5 , V_11 ) ;
if ( ! F_6 ( V_5 ) )
F_79 ( & V_5 -> V_9 ) ;
}
int F_489 ( struct V_11 * V_11 , T_6 V_185 )
{
unsigned int V_36 = F_399 ( V_11 ) ;
struct V_214 * V_215 ;
struct V_4 * V_5 ;
unsigned short V_505 ;
if ( ! F_2 ( V_1 ) || ! V_2 )
return 0 ;
V_5 = V_11 -> V_4 ;
if ( ! V_5 )
return 0 ;
V_5 = F_484 ( V_5 ) ;
if ( ! F_6 ( V_5 ) &&
! F_179 ( & V_5 -> V_137 , V_36 , & V_215 ) ) {
F_346 ( V_5 ) ;
return - V_231 ;
}
if ( V_36 > 1 )
F_340 ( V_5 , V_36 - 1 ) ;
V_505 = F_487 ( V_185 , F_235 ( V_5 ) , V_36 ) ;
F_50 ( V_505 , V_11 ) ;
F_232 ( V_5 , V_36 ) ;
return 0 ;
}
void F_460 ( T_6 V_185 , unsigned int V_36 )
{
struct V_4 * V_5 ;
unsigned short V_236 ;
if ( ! V_2 )
return;
V_236 = F_487 ( V_185 , 0 , V_36 ) ;
F_13 () ;
V_5 = F_347 ( V_236 ) ;
if ( V_5 ) {
if ( ! F_6 ( V_5 ) ) {
if ( F_2 ( V_1 ) )
F_156 ( & V_5 -> V_137 , V_36 ) ;
else
F_156 ( & V_5 -> V_116 , V_36 ) ;
}
F_232 ( V_5 , - V_36 ) ;
F_342 ( V_5 , V_36 ) ;
}
F_17 () ;
}
long F_490 ( struct V_4 * V_5 )
{
long V_506 = F_491 () ;
if ( ! V_2 || ! F_2 ( V_1 ) )
return V_506 ;
for (; V_5 != V_6 ; V_5 = F_15 ( V_5 ) )
V_506 = F_492 ( long , V_506 ,
F_14 ( V_5 -> V_137 . V_115 ) -
F_32 ( & V_5 -> V_137 ) ) ;
return V_506 ;
}
bool F_493 ( struct V_11 * V_11 )
{
struct V_4 * V_5 ;
F_50 ( ! F_457 ( V_11 ) , V_11 ) ;
if ( F_494 () )
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
static int T_17 F_495 ( char * V_498 )
{
if ( ! strcmp ( V_498 , L_71 ) )
V_507 = 1 ;
else if ( ! strcmp ( V_498 , L_72 ) )
V_507 = 0 ;
return 1 ;
}
static V_126 F_496 ( struct V_7 * V_9 ,
struct V_278 * V_279 )
{
struct V_4 * V_5 = F_70 ( V_9 ) ;
return ( V_126 ) F_32 ( & V_5 -> V_137 ) * V_230 ;
}
static int F_497 ( struct V_309 * V_310 , void * V_311 )
{
struct V_4 * V_5 = F_70 ( F_280 ( V_310 ) ) ;
unsigned long F_178 = F_14 ( V_5 -> V_137 . V_115 ) ;
if ( F_178 == V_319 )
F_445 ( V_310 , L_35 ) ;
else
F_281 ( V_310 , L_36 , ( V_126 ) F_178 * V_230 ) ;
return 0 ;
}
static T_7 F_498 ( struct V_273 * V_274 ,
char * V_275 , T_8 V_276 , T_9 V_277 )
{
struct V_4 * V_5 = F_70 ( F_249 ( V_274 ) ) ;
unsigned long F_178 ;
int V_237 ;
V_275 = F_272 ( V_275 ) ;
V_237 = F_273 ( V_275 , L_37 , & F_178 ) ;
if ( V_237 )
return V_237 ;
F_119 ( & V_266 ) ;
V_237 = F_239 ( & V_5 -> V_137 , F_178 ) ;
F_121 ( & V_266 ) ;
if ( V_237 )
return V_237 ;
return V_276 ;
}
static int T_17 F_499 ( void )
{
if ( ! F_75 () && V_507 ) {
V_2 = 1 ;
F_268 ( F_500 ( & V_1 ,
V_508 ) ) ;
F_268 ( F_501 ( & V_1 ,
V_509 ) ) ;
}
return 0 ;
}
