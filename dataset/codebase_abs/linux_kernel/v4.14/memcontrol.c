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
bool V_30 = true ;
if ( V_22 -> V_31 )
return;
V_22 -> V_32 = V_24 ;
if ( ! V_22 -> V_32 )
return;
while ( * V_26 ) {
V_28 = * V_26 ;
V_29 = F_23 ( V_28 , struct V_16 ,
V_33 ) ;
if ( V_22 -> V_32 < V_29 -> V_32 ) {
V_26 = & ( * V_26 ) -> V_34 ;
V_30 = false ;
}
else if ( V_22 -> V_32 >= V_29 -> V_32 )
V_26 = & ( * V_26 ) -> V_35 ;
}
if ( V_30 )
V_23 -> V_36 = & V_22 -> V_33 ;
F_24 ( & V_22 -> V_33 , V_28 , V_26 ) ;
F_25 ( & V_22 -> V_33 , & V_23 -> V_27 ) ;
V_22 -> V_31 = true ;
}
static void F_26 ( struct V_16 * V_22 ,
struct V_19 * V_23 )
{
if ( ! V_22 -> V_31 )
return;
if ( & V_22 -> V_33 == V_23 -> V_36 )
V_23 -> V_36 = F_27 ( & V_22 -> V_33 ) ;
F_28 ( & V_22 -> V_33 , & V_23 -> V_27 ) ;
V_22 -> V_31 = false ;
}
static void F_29 ( struct V_16 * V_22 ,
struct V_19 * V_23 )
{
unsigned long V_13 ;
F_30 ( & V_23 -> V_37 , V_13 ) ;
F_26 ( V_22 , V_23 ) ;
F_31 ( & V_23 -> V_37 , V_13 ) ;
}
static unsigned long F_32 ( struct V_4 * V_5 )
{
unsigned long V_38 = F_33 ( & V_5 -> V_39 ) ;
unsigned long V_40 = F_14 ( V_5 -> V_40 ) ;
unsigned long V_41 = 0 ;
if ( V_38 > V_40 )
V_41 = V_38 - V_40 ;
return V_41 ;
}
static void F_34 ( struct V_4 * V_5 , struct V_11 * V_11 )
{
unsigned long V_41 ;
struct V_16 * V_22 ;
struct V_19 * V_23 ;
V_23 = F_21 ( V_11 ) ;
if ( ! V_23 )
return;
for (; V_5 ; V_5 = F_15 ( V_5 ) ) {
V_22 = F_18 ( V_5 , V_11 ) ;
V_41 = F_32 ( V_5 ) ;
if ( V_41 || V_22 -> V_31 ) {
unsigned long V_13 ;
F_30 ( & V_23 -> V_37 , V_13 ) ;
if ( V_22 -> V_31 )
F_26 ( V_22 , V_23 ) ;
F_22 ( V_22 , V_23 , V_41 ) ;
F_31 ( & V_23 -> V_37 , V_13 ) ;
}
}
}
static void F_35 ( struct V_4 * V_5 )
{
struct V_19 * V_23 ;
struct V_16 * V_22 ;
int V_17 ;
F_36 (nid) {
V_22 = F_37 ( V_5 , V_17 ) ;
V_23 = F_20 ( V_17 ) ;
if ( V_23 )
F_29 ( V_22 , V_23 ) ;
}
}
static struct V_16 *
F_38 ( struct V_19 * V_23 )
{
struct V_16 * V_22 ;
V_42:
V_22 = NULL ;
if ( ! V_23 -> V_36 )
goto V_43;
V_22 = F_23 ( V_23 -> V_36 ,
struct V_16 , V_33 ) ;
F_26 ( V_22 , V_23 ) ;
if ( ! F_32 ( V_22 -> V_5 ) ||
! F_39 ( & V_22 -> V_5 -> V_9 ) )
goto V_42;
V_43:
return V_22 ;
}
static struct V_16 *
F_40 ( struct V_19 * V_23 )
{
struct V_16 * V_22 ;
F_41 ( & V_23 -> V_37 ) ;
V_22 = F_38 ( V_23 ) ;
F_42 ( & V_23 -> V_37 ) ;
return V_22 ;
}
static unsigned long F_43 ( struct V_4 * V_5 ,
int V_44 )
{
unsigned long V_45 = 0 ;
int V_46 ;
F_44 (cpu)
V_45 += F_45 ( V_5 -> V_47 -> V_48 [ V_44 ] , V_46 ) ;
return V_45 ;
}
static void F_46 ( struct V_4 * V_5 ,
struct V_11 * V_11 ,
bool V_49 , int V_38 )
{
if ( F_47 ( V_11 ) )
F_48 ( V_5 -> V_47 -> V_50 [ V_51 ] , V_38 ) ;
else {
F_48 ( V_5 -> V_47 -> V_50 [ V_52 ] , V_38 ) ;
if ( F_49 ( V_11 ) )
F_48 ( V_5 -> V_47 -> V_50 [ V_53 ] , V_38 ) ;
}
if ( V_49 ) {
F_50 ( ! F_51 ( V_11 ) , V_11 ) ;
F_48 ( V_5 -> V_47 -> V_50 [ V_54 ] , V_38 ) ;
}
if ( V_38 > 0 )
F_52 ( V_5 -> V_47 -> V_48 [ V_55 ] ) ;
else {
F_52 ( V_5 -> V_47 -> V_48 [ V_56 ] ) ;
V_38 = - V_38 ;
}
F_48 ( V_5 -> V_47 -> V_57 , V_38 ) ;
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
F_34 ( V_5 , V_11 ) ;
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
V_22 = F_37 ( V_83 , V_86 -> V_93 -> V_94 ) ;
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
F_36 (nid) {
V_22 = F_37 ( V_5 , V_17 ) ;
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
F_86 ( & V_89 -> V_9 , 0 , & V_105 ) ;
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
int V_108 , int V_38 )
{
struct V_16 * V_22 ;
unsigned long * V_109 ;
long V_110 ;
if ( F_75 () )
return;
V_22 = F_5 ( V_59 , struct V_16 , V_59 ) ;
V_109 = & V_22 -> V_111 [ V_108 ] [ V_62 ] ;
if ( V_38 < 0 )
* V_109 += V_38 ;
V_110 = * V_109 ;
if ( F_91 ( V_110 < 0 ,
L_1 ,
V_112 , V_59 , V_62 , V_38 , V_110 ) ) {
F_56 ( 1 ) ;
* V_109 = 0 ;
}
if ( V_38 > 0 )
* V_109 += V_38 ;
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
V_50 = F_33 ( & V_5 -> V_39 ) ;
V_115 = F_14 ( V_5 -> V_39 . V_115 ) ;
if ( V_50 < V_115 )
V_114 = V_115 - V_50 ;
if ( F_1 () ) {
V_50 = F_33 ( & V_5 -> V_116 ) ;
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
F_100 ( & V_119 . V_37 ) ;
V_117 = V_119 . V_117 ;
V_118 = V_119 . V_118 ;
if ( ! V_117 )
goto V_120;
V_103 = F_96 ( V_117 , V_5 ) ||
F_96 ( V_118 , V_5 ) ;
V_120:
F_101 ( & V_119 . V_37 ) ;
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
F_112 ( ( V_126 ) F_33 ( & V_5 -> V_39 ) ) ,
F_112 ( ( V_126 ) V_5 -> V_39 . V_115 ) , V_5 -> V_39 . V_127 ) ;
F_108 ( L_7 ,
F_112 ( ( V_126 ) F_33 ( & V_5 -> V_116 ) ) ,
F_112 ( ( V_126 ) V_5 -> V_116 . V_115 ) , V_5 -> V_116 . V_127 ) ;
F_108 ( L_8 ,
F_112 ( ( V_126 ) F_33 ( & V_5 -> V_128 ) ) ,
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
V_115 = V_5 -> V_39 . V_115 ;
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
unsigned long V_41 ;
unsigned long V_160 ;
struct V_85 V_86 = {
. V_93 = V_93 ,
. V_95 = 0 ,
} ;
V_41 = F_32 ( V_155 ) ;
while ( 1 ) {
V_157 = F_74 ( V_155 , V_157 , & V_86 ) ;
if ( ! V_157 ) {
V_159 ++ ;
if ( V_159 >= 2 ) {
if ( ! V_158 )
break;
if ( V_158 >= ( V_41 >> 2 ) ||
( V_159 > V_161 ) )
break;
}
continue;
}
V_158 += F_133 ( V_157 , V_139 , false ,
V_93 , & V_160 ) ;
* V_156 += V_160 ;
if ( ! F_32 ( V_155 ) )
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
F_30 ( & V_5 -> V_190 , V_13 ) ;
if ( V_5 != V_11 -> V_4 ) {
F_31 ( & V_5 -> V_190 , V_13 ) ;
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
F_31 ( & V_5 -> V_190 , V_13 ) ;
}
F_17 () ;
}
void F_150 ( struct V_11 * V_11 )
{
F_149 ( V_11 -> V_4 ) ;
}
static bool F_151 ( struct V_4 * V_5 , unsigned int V_38 )
{
struct V_193 * V_194 ;
unsigned long V_13 ;
bool V_103 = false ;
if ( V_38 > V_195 )
return V_103 ;
F_152 ( V_13 ) ;
V_194 = F_153 ( & V_196 ) ;
if ( V_5 == V_194 -> V_197 && V_194 -> V_38 >= V_38 ) {
V_194 -> V_38 -= V_38 ;
V_103 = true ;
}
F_154 ( V_13 ) ;
return V_103 ;
}
static void F_155 ( struct V_193 * V_194 )
{
struct V_4 * V_198 = V_194 -> V_197 ;
if ( V_194 -> V_38 ) {
F_156 ( & V_198 -> V_39 , V_194 -> V_38 ) ;
if ( F_1 () )
F_156 ( & V_198 -> V_116 , V_194 -> V_38 ) ;
F_157 ( & V_198 -> V_9 , V_194 -> V_38 ) ;
V_194 -> V_38 = 0 ;
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
static void F_160 ( struct V_4 * V_5 , unsigned int V_38 )
{
struct V_193 * V_194 ;
unsigned long V_13 ;
F_152 ( V_13 ) ;
V_194 = F_153 ( & V_196 ) ;
if ( V_194 -> V_197 != V_5 ) {
F_155 ( V_194 ) ;
V_194 -> V_197 = V_5 ;
}
V_194 -> V_38 += V_38 ;
if ( V_194 -> V_38 > V_195 )
F_155 ( V_194 ) ;
F_154 ( V_13 ) ;
}
static void F_161 ( struct V_4 * V_155 )
{
int V_46 , V_202 ;
if ( ! F_162 ( & V_203 ) )
return;
V_202 = F_163 () ;
F_164 (cpu) {
struct V_193 * V_194 = & F_45 ( V_196 , V_46 ) ;
struct V_4 * V_5 ;
V_5 = V_194 -> V_197 ;
if ( ! V_5 || ! V_194 -> V_38 || ! F_76 ( & V_5 -> V_9 ) )
continue;
if ( ! F_96 ( V_5 , V_155 ) ) {
F_79 ( & V_5 -> V_9 ) ;
continue;
}
if ( ! F_165 ( V_201 , & V_194 -> V_13 ) ) {
if ( V_46 == V_202 )
F_158 ( & V_194 -> V_204 ) ;
else
F_166 ( V_46 , & V_194 -> V_204 ) ;
}
F_79 ( & V_5 -> V_9 ) ;
}
F_167 () ;
F_121 ( & V_203 ) ;
}
static int F_168 ( unsigned int V_46 )
{
struct V_193 * V_194 ;
V_194 = & F_45 ( V_196 , V_46 ) ;
F_155 ( V_194 ) ;
return 0 ;
}
static void F_169 ( struct V_4 * V_5 ,
unsigned int V_38 ,
T_3 V_139 )
{
do {
if ( F_33 ( & V_5 -> V_39 ) <= V_5 -> V_205 )
continue;
F_170 ( V_5 , V_206 ) ;
F_171 ( V_5 , V_38 , V_139 , true ) ;
} while ( ( V_5 = F_15 ( V_5 ) ) );
}
static void F_172 ( struct V_199 * V_204 )
{
struct V_4 * V_5 ;
V_5 = F_5 ( V_204 , struct V_4 , V_207 ) ;
F_169 ( V_5 , V_195 , V_208 ) ;
}
void F_173 ( void )
{
unsigned int V_38 = V_122 -> V_209 ;
struct V_4 * V_5 ;
if ( F_174 ( ! V_38 ) )
return;
V_5 = F_72 ( V_122 -> V_81 ) ;
F_169 ( V_5 , V_38 , V_208 ) ;
F_79 ( & V_5 -> V_9 ) ;
V_122 -> V_209 = 0 ;
}
static int F_175 ( struct V_4 * V_5 , T_3 V_139 ,
unsigned int V_38 )
{
unsigned int V_210 = F_176 ( V_195 , V_38 ) ;
int V_211 = V_212 ;
struct V_4 * V_213 ;
struct V_214 * V_215 ;
unsigned long V_216 ;
bool V_217 = true ;
bool V_218 = false ;
if ( F_6 ( V_5 ) )
return 0 ;
V_42:
if ( F_151 ( V_5 , V_38 ) )
return 0 ;
if ( ! F_1 () ||
F_177 ( & V_5 -> V_116 , V_210 , & V_215 ) ) {
if ( F_177 ( & V_5 -> V_39 , V_210 , & V_215 ) )
goto V_219;
if ( F_1 () )
F_156 ( & V_5 -> V_116 , V_210 ) ;
V_213 = F_178 ( V_215 , V_39 ) ;
} else {
V_213 = F_178 ( V_215 , V_116 ) ;
V_217 = false ;
}
if ( V_210 > V_38 ) {
V_210 = V_38 ;
goto V_42;
}
if ( F_66 ( F_179 ( V_122 ) ||
F_180 ( V_122 ) ||
V_122 -> V_13 & V_220 ) )
goto V_221;
if ( F_66 ( V_122 -> V_13 & V_222 ) )
goto V_221;
if ( F_66 ( F_181 ( V_122 ) ) )
goto V_223;
if ( ! F_182 ( V_139 ) )
goto V_223;
F_170 ( V_213 , V_224 ) ;
V_216 = F_171 ( V_213 , V_38 ,
V_139 , V_217 ) ;
if ( F_97 ( V_213 ) >= V_38 )
goto V_42;
if ( ! V_218 ) {
F_161 ( V_213 ) ;
V_218 = true ;
goto V_42;
}
if ( V_139 & V_225 )
goto V_223;
if ( V_216 && V_38 <= ( 1 << V_226 ) )
goto V_42;
if ( F_102 ( V_213 ) )
goto V_42;
if ( V_211 -- )
goto V_42;
if ( V_139 & V_227 )
goto V_221;
if ( F_180 ( V_122 ) )
goto V_221;
F_170 ( V_213 , V_228 ) ;
F_144 ( V_213 , V_139 ,
F_183 ( V_38 * V_229 ) ) ;
V_223:
if ( ! ( V_139 & V_227 ) )
return - V_230 ;
V_221:
F_184 ( & V_5 -> V_39 , V_38 ) ;
if ( F_1 () )
F_184 ( & V_5 -> V_116 , V_38 ) ;
F_185 ( & V_5 -> V_9 , V_38 ) ;
return 0 ;
V_219:
F_185 ( & V_5 -> V_9 , V_210 ) ;
if ( V_210 > V_38 )
F_160 ( V_5 , V_210 - V_38 ) ;
do {
if ( F_33 ( & V_5 -> V_39 ) > V_5 -> V_205 ) {
if ( F_186 () ) {
F_187 ( & V_5 -> V_207 ) ;
break;
}
V_122 -> V_209 += V_210 ;
F_188 ( V_122 ) ;
break;
}
} while ( ( V_5 = F_15 ( V_5 ) ) );
return 0 ;
}
static void F_189 ( struct V_4 * V_5 , unsigned int V_38 )
{
if ( F_6 ( V_5 ) )
return;
F_156 ( & V_5 -> V_39 , V_38 ) ;
if ( F_1 () )
F_156 ( & V_5 -> V_116 , V_38 ) ;
F_157 ( & V_5 -> V_9 , V_38 ) ;
}
static void F_190 ( struct V_11 * V_11 , int * V_231 )
{
struct V_232 * V_232 = F_191 ( V_11 ) ;
F_41 ( F_192 ( V_232 ) ) ;
if ( F_193 ( V_11 ) ) {
struct V_59 * V_59 ;
V_59 = F_89 ( V_11 , V_232 -> V_233 ) ;
F_194 ( V_11 ) ;
F_195 ( V_11 , V_59 , F_196 ( V_11 ) ) ;
* V_231 = 1 ;
} else
* V_231 = 0 ;
}
static void F_197 ( struct V_11 * V_11 , int V_231 )
{
struct V_232 * V_232 = F_191 ( V_11 ) ;
if ( V_231 ) {
struct V_59 * V_59 ;
V_59 = F_89 ( V_11 , V_232 -> V_233 ) ;
F_50 ( F_193 ( V_11 ) , V_11 ) ;
F_198 ( V_11 ) ;
F_199 ( V_11 , V_59 , F_196 ( V_11 ) ) ;
}
F_42 ( F_192 ( V_232 ) ) ;
}
static void F_200 ( struct V_11 * V_11 , struct V_4 * V_5 ,
bool V_234 )
{
int V_231 ;
F_50 ( V_11 -> V_4 , V_11 ) ;
if ( V_234 )
F_190 ( V_11 , & V_231 ) ;
V_11 -> V_4 = V_5 ;
if ( V_234 )
F_197 ( V_11 , V_231 ) ;
}
static int F_201 ( void )
{
int V_235 , V_110 ;
int V_236 ;
V_235 = F_202 ( & V_237 ,
0 , V_238 , V_208 ) ;
if ( V_235 < 0 )
return V_235 ;
if ( V_235 < V_239 )
return V_235 ;
F_203 ( & V_10 ) ;
V_110 = 2 * ( V_235 + 1 ) ;
if ( V_110 < V_240 )
V_110 = V_240 ;
else if ( V_110 > V_238 )
V_110 = V_238 ;
V_236 = F_204 ( V_110 ) ;
if ( ! V_236 )
V_236 = F_205 ( V_110 ) ;
if ( ! V_236 )
V_239 = V_110 ;
F_206 ( & V_10 ) ;
if ( V_236 ) {
F_207 ( & V_237 , V_235 ) ;
return V_236 ;
}
return V_235 ;
}
static void F_208 ( int V_235 )
{
F_207 ( & V_237 , V_235 ) ;
}
static void F_209 ( struct V_199 * V_241 )
{
struct V_242 * V_243 =
F_5 ( V_241 , struct V_242 , V_204 ) ;
struct V_4 * V_5 = V_243 -> V_5 ;
struct V_244 * V_245 = V_243 -> V_245 ;
F_210 ( V_5 , V_245 ) ;
F_79 ( & V_5 -> V_9 ) ;
F_211 ( V_243 ) ;
}
static void F_212 ( struct V_4 * V_5 ,
struct V_244 * V_245 )
{
struct V_242 * V_243 ;
V_243 = F_213 ( sizeof( * V_243 ) , V_246 ) ;
if ( ! V_243 )
return;
F_95 ( & V_5 -> V_9 ) ;
V_243 -> V_5 = V_5 ;
V_243 -> V_245 = V_245 ;
F_214 ( & V_243 -> V_204 , F_209 ) ;
F_215 ( V_247 , & V_243 -> V_204 ) ;
}
static void F_216 ( struct V_4 * V_5 ,
struct V_244 * V_245 )
{
V_122 -> V_248 = 1 ;
F_212 ( V_5 , V_245 ) ;
V_122 -> V_248 = 0 ;
}
static inline bool F_217 ( void )
{
if ( F_186 () || ! V_122 -> V_81 || ( V_122 -> V_13 & V_249 ) )
return true ;
return false ;
}
struct V_244 * F_218 ( struct V_244 * V_245 )
{
struct V_4 * V_5 ;
struct V_244 * V_250 ;
int V_251 ;
F_56 ( ! F_219 ( V_245 ) ) ;
if ( F_217 () )
return V_245 ;
if ( V_122 -> V_248 )
return V_245 ;
V_5 = F_72 ( V_122 -> V_81 ) ;
V_251 = F_14 ( V_5 -> V_251 ) ;
if ( V_251 < 0 )
goto V_92;
V_250 = F_220 ( V_245 , V_251 ) ;
if ( F_174 ( V_250 ) )
return V_250 ;
F_216 ( V_5 , V_245 ) ;
V_92:
F_79 ( & V_5 -> V_9 ) ;
return V_245 ;
}
void F_221 ( struct V_244 * V_245 )
{
if ( ! F_219 ( V_245 ) )
F_79 ( & V_245 -> V_252 . V_5 -> V_9 ) ;
}
int F_222 ( struct V_11 * V_11 , T_3 V_253 , int V_140 ,
struct V_4 * V_5 )
{
unsigned int V_38 = 1 << V_140 ;
struct V_214 * V_215 ;
int V_103 ;
V_103 = F_175 ( V_5 , V_253 , V_38 ) ;
if ( V_103 )
return V_103 ;
if ( ! F_2 ( V_1 ) &&
! F_177 ( & V_5 -> V_128 , V_38 , & V_215 ) ) {
F_189 ( V_5 , V_38 ) ;
return - V_230 ;
}
V_11 -> V_4 = V_5 ;
return 0 ;
}
int F_223 ( struct V_11 * V_11 , T_3 V_253 , int V_140 )
{
struct V_4 * V_5 ;
int V_103 = 0 ;
if ( F_217 () )
return 0 ;
V_5 = F_72 ( V_122 -> V_81 ) ;
if ( ! F_6 ( V_5 ) ) {
V_103 = F_222 ( V_11 , V_253 , V_140 , V_5 ) ;
if ( ! V_103 )
F_224 ( V_11 ) ;
}
F_79 ( & V_5 -> V_9 ) ;
return V_103 ;
}
void F_225 ( struct V_11 * V_11 , int V_140 )
{
struct V_4 * V_5 = V_11 -> V_4 ;
unsigned int V_38 = 1 << V_140 ;
if ( ! V_5 )
return;
F_50 ( F_6 ( V_5 ) , V_11 ) ;
if ( ! F_2 ( V_1 ) )
F_156 ( & V_5 -> V_128 , V_38 ) ;
F_156 ( & V_5 -> V_39 , V_38 ) ;
if ( F_1 () )
F_156 ( & V_5 -> V_116 , V_38 ) ;
V_11 -> V_4 = NULL ;
if ( F_226 ( V_11 ) )
F_227 ( V_11 ) ;
F_157 ( & V_5 -> V_9 , V_38 ) ;
}
void F_228 ( struct V_11 * V_254 )
{
int V_100 ;
if ( F_75 () )
return;
for ( V_100 = 1 ; V_100 < V_255 ; V_100 ++ )
V_254 [ V_100 ] . V_4 = V_254 -> V_4 ;
F_229 ( V_254 -> V_4 -> V_47 -> V_50 [ V_54 ] ,
V_255 ) ;
}
static void F_230 ( struct V_4 * V_5 ,
int V_256 )
{
F_231 ( V_5 -> V_47 -> V_50 [ V_130 ] , V_256 ) ;
}
static int F_232 ( T_6 V_185 ,
struct V_4 * V_117 , struct V_4 * V_118 )
{
unsigned short V_257 , V_258 ;
V_257 = F_233 ( V_117 ) ;
V_258 = F_233 ( V_118 ) ;
if ( F_234 ( V_185 , V_257 , V_258 ) == V_257 ) {
F_230 ( V_117 , - 1 ) ;
F_230 ( V_118 , 1 ) ;
return 0 ;
}
return - V_259 ;
}
static inline int F_232 ( T_6 V_185 ,
struct V_4 * V_117 , struct V_4 * V_118 )
{
return - V_259 ;
}
static int F_235 ( struct V_4 * V_5 ,
unsigned long V_115 )
{
unsigned long V_260 ;
unsigned long V_261 ;
bool V_262 = false ;
int V_263 ;
int V_103 ;
V_263 = V_212 *
F_115 ( V_5 ) ;
V_261 = F_33 ( & V_5 -> V_39 ) ;
do {
if ( F_236 ( V_122 ) ) {
V_103 = - V_264 ;
break;
}
F_119 ( & V_265 ) ;
if ( V_115 > V_5 -> V_116 . V_115 ) {
F_121 ( & V_265 ) ;
V_103 = - V_259 ;
break;
}
if ( V_115 > V_5 -> V_39 . V_115 )
V_262 = true ;
V_103 = F_237 ( & V_5 -> V_39 , V_115 ) ;
F_121 ( & V_265 ) ;
if ( ! V_103 )
break;
F_171 ( V_5 , 1 , V_208 , true ) ;
V_260 = F_33 ( & V_5 -> V_39 ) ;
if ( V_260 >= V_261 )
V_263 -- ;
else
V_261 = V_260 ;
} while ( V_263 );
if ( ! V_103 && V_262 )
F_142 ( V_5 ) ;
return V_103 ;
}
static int F_238 ( struct V_4 * V_5 ,
unsigned long V_115 )
{
unsigned long V_260 ;
unsigned long V_261 ;
bool V_262 = false ;
int V_263 ;
int V_103 ;
V_263 = V_212 *
F_115 ( V_5 ) ;
V_261 = F_33 ( & V_5 -> V_116 ) ;
do {
if ( F_236 ( V_122 ) ) {
V_103 = - V_264 ;
break;
}
F_119 ( & V_265 ) ;
if ( V_115 < V_5 -> V_39 . V_115 ) {
F_121 ( & V_265 ) ;
V_103 = - V_259 ;
break;
}
if ( V_115 > V_5 -> V_116 . V_115 )
V_262 = true ;
V_103 = F_237 ( & V_5 -> V_116 , V_115 ) ;
F_121 ( & V_265 ) ;
if ( ! V_103 )
break;
F_171 ( V_5 , 1 , V_208 , false ) ;
V_260 = F_33 ( & V_5 -> V_116 ) ;
if ( V_260 >= V_261 )
V_263 -- ;
else
V_261 = V_260 ;
} while ( V_263 );
if ( ! V_103 && V_262 )
F_142 ( V_5 ) ;
return V_103 ;
}
unsigned long F_239 ( T_4 * V_93 , int V_140 ,
T_3 V_139 ,
unsigned long * V_156 )
{
unsigned long V_216 = 0 ;
struct V_16 * V_22 , * V_266 = NULL ;
unsigned long V_267 ;
int V_159 = 0 ;
struct V_19 * V_23 ;
unsigned long V_41 ;
unsigned long V_160 ;
if ( V_140 > 0 )
return 0 ;
V_23 = F_20 ( V_93 -> V_94 ) ;
if ( ! V_23 || F_240 ( & V_23 -> V_27 ) )
return 0 ;
do {
if ( V_266 )
V_22 = V_266 ;
else
V_22 = F_40 ( V_23 ) ;
if ( ! V_22 )
break;
V_160 = 0 ;
V_267 = F_132 ( V_22 -> V_5 , V_93 ,
V_139 , & V_160 ) ;
V_216 += V_267 ;
* V_156 += V_160 ;
F_41 ( & V_23 -> V_37 ) ;
F_26 ( V_22 , V_23 ) ;
V_266 = NULL ;
if ( ! V_267 )
V_266 = F_38 ( V_23 ) ;
V_41 = F_32 ( V_22 -> V_5 ) ;
F_22 ( V_22 , V_23 , V_41 ) ;
F_42 ( & V_23 -> V_37 ) ;
F_79 ( & V_22 -> V_5 -> V_9 ) ;
V_159 ++ ;
if ( ! V_216 &&
( V_266 == NULL ||
V_159 > V_268 ) )
break;
} while ( ! V_216 );
if ( V_266 )
F_79 ( & V_266 -> V_5 -> V_9 ) ;
return V_216 ;
}
static inline bool F_241 ( struct V_4 * V_5 )
{
bool V_103 ;
F_13 () ;
V_103 = F_242 ( NULL , & V_5 -> V_9 ) ;
F_17 () ;
return V_103 ;
}
static int F_243 ( struct V_4 * V_5 )
{
int V_211 = V_212 ;
F_244 () ;
while ( V_211 && F_33 ( & V_5 -> V_39 ) ) {
int V_269 ;
if ( F_236 ( V_122 ) )
return - V_264 ;
V_269 = F_171 ( V_5 , 1 ,
V_208 , true ) ;
if ( ! V_269 ) {
V_211 -- ;
F_245 ( V_270 , V_271 / 10 ) ;
}
}
return 0 ;
}
static T_7 F_246 ( struct V_272 * V_273 ,
char * V_274 , T_8 V_275 ,
T_9 V_276 )
{
struct V_4 * V_5 = F_70 ( F_247 ( V_273 ) ) ;
if ( F_6 ( V_5 ) )
return - V_259 ;
return F_243 ( V_5 ) ? : V_275 ;
}
static V_126 F_248 ( struct V_7 * V_9 ,
struct V_277 * V_278 )
{
return F_70 ( V_9 ) -> V_91 ;
}
static int F_249 ( struct V_7 * V_9 ,
struct V_277 * V_278 , V_126 V_45 )
{
int V_279 = 0 ;
struct V_4 * V_5 = F_70 ( V_9 ) ;
struct V_4 * V_280 = F_70 ( V_5 -> V_9 . V_28 ) ;
if ( V_5 -> V_91 == V_45 )
return 0 ;
if ( ( ! V_280 || ! V_280 -> V_91 ) &&
( V_45 == 1 || V_45 == 0 ) ) {
if ( ! F_241 ( V_5 ) )
V_5 -> V_91 = V_45 ;
else
V_279 = - V_281 ;
} else
V_279 = - V_259 ;
return V_279 ;
}
static void F_250 ( struct V_4 * V_5 , unsigned long * V_47 )
{
struct V_4 * V_89 ;
int V_100 ;
memset ( V_47 , 0 , sizeof( * V_47 ) * V_282 ) ;
F_85 (iter, memcg) {
for ( V_100 = 0 ; V_100 < V_282 ; V_100 ++ )
V_47 [ V_100 ] += F_114 ( V_89 , V_100 ) ;
}
}
static void F_251 ( struct V_4 * V_5 , unsigned long * V_48 )
{
struct V_4 * V_89 ;
int V_100 ;
memset ( V_48 , 0 , sizeof( * V_48 ) * V_283 ) ;
F_85 (iter, memcg) {
for ( V_100 = 0 ; V_100 < V_283 ; V_100 ++ )
V_48 [ V_100 ] += F_43 ( V_89 , V_100 ) ;
}
}
static unsigned long F_252 ( struct V_4 * V_5 , bool V_137 )
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
V_45 = F_33 ( & V_5 -> V_39 ) ;
else
V_45 = F_33 ( & V_5 -> V_116 ) ;
}
return V_45 ;
}
static V_126 F_253 ( struct V_7 * V_9 ,
struct V_277 * V_278 )
{
struct V_4 * V_5 = F_70 ( V_9 ) ;
struct V_214 * V_215 ;
switch ( F_254 ( V_278 -> V_184 ) ) {
case V_284 :
V_215 = & V_5 -> V_39 ;
break;
case V_285 :
V_215 = & V_5 -> V_116 ;
break;
case V_286 :
V_215 = & V_5 -> V_128 ;
break;
case V_287 :
V_215 = & V_5 -> V_288 ;
break;
default:
F_255 () ;
}
switch ( F_256 ( V_278 -> V_184 ) ) {
case V_289 :
if ( V_215 == & V_5 -> V_39 )
return ( V_126 ) F_252 ( V_5 , false ) * V_229 ;
if ( V_215 == & V_5 -> V_116 )
return ( V_126 ) F_252 ( V_5 , true ) * V_229 ;
return ( V_126 ) F_33 ( V_215 ) * V_229 ;
case V_290 :
return ( V_126 ) V_215 -> V_115 * V_229 ;
case V_291 :
return ( V_126 ) V_215 -> V_292 * V_229 ;
case V_293 :
return V_215 -> V_127 ;
case V_294 :
return ( V_126 ) V_5 -> V_40 * V_229 ;
default:
F_255 () ;
}
}
static int F_257 ( struct V_4 * V_5 )
{
int V_295 ;
if ( V_296 )
return 0 ;
F_84 ( V_5 -> V_251 >= 0 ) ;
F_84 ( V_5 -> V_297 ) ;
V_295 = F_201 () ;
if ( V_295 < 0 )
return V_295 ;
F_258 ( & V_298 ) ;
V_5 -> V_251 = V_295 ;
V_5 -> V_297 = V_299 ;
F_146 ( & V_5 -> V_300 ) ;
return 0 ;
}
static void F_259 ( struct V_4 * V_5 )
{
struct V_7 * V_9 ;
struct V_4 * V_28 , * V_301 ;
int V_251 ;
if ( V_5 -> V_297 != V_299 )
return;
V_5 -> V_297 = V_302 ;
F_260 ( V_5 ) ;
V_251 = V_5 -> V_251 ;
F_84 ( V_251 < 0 ) ;
V_28 = F_15 ( V_5 ) ;
if ( ! V_28 )
V_28 = V_6 ;
F_13 () ;
F_261 (css, &memcg->css) {
V_301 = F_70 ( V_9 ) ;
F_84 ( V_301 -> V_251 != V_251 ) ;
V_301 -> V_251 = V_28 -> V_251 ;
if ( ! V_5 -> V_91 )
break;
}
F_17 () ;
F_262 ( V_251 , V_28 -> V_251 ) ;
F_208 ( V_251 ) ;
}
static void F_263 ( struct V_4 * V_5 )
{
if ( F_66 ( V_5 -> V_297 == V_299 ) )
F_259 ( V_5 ) ;
if ( V_5 -> V_297 == V_302 ) {
F_264 ( V_5 ) ;
F_265 ( & V_298 ) ;
F_266 ( F_33 ( & V_5 -> V_128 ) ) ;
}
}
static int F_257 ( struct V_4 * V_5 )
{
return 0 ;
}
static void F_259 ( struct V_4 * V_5 )
{
}
static void F_263 ( struct V_4 * V_5 )
{
}
static int F_267 ( struct V_4 * V_5 ,
unsigned long V_115 )
{
int V_103 ;
F_119 ( & V_265 ) ;
V_103 = F_237 ( & V_5 -> V_128 , V_115 ) ;
F_121 ( & V_265 ) ;
return V_103 ;
}
static int F_268 ( struct V_4 * V_5 , unsigned long V_115 )
{
int V_103 ;
F_119 ( & V_265 ) ;
V_103 = F_237 ( & V_5 -> V_288 , V_115 ) ;
if ( V_103 )
goto V_92;
if ( ! V_5 -> V_303 ) {
F_258 ( & V_304 ) ;
V_5 -> V_303 = true ;
}
V_92:
F_121 ( & V_265 ) ;
return V_103 ;
}
static T_7 F_269 ( struct V_272 * V_273 ,
char * V_274 , T_8 V_275 , T_9 V_276 )
{
struct V_4 * V_5 = F_70 ( F_247 ( V_273 ) ) ;
unsigned long V_38 ;
int V_103 ;
V_274 = F_270 ( V_274 ) ;
V_103 = F_271 ( V_274 , L_12 , & V_38 ) ;
if ( V_103 )
return V_103 ;
switch ( F_256 ( F_272 ( V_273 ) -> V_184 ) ) {
case V_290 :
if ( F_6 ( V_5 ) ) {
V_103 = - V_259 ;
break;
}
switch ( F_254 ( F_272 ( V_273 ) -> V_184 ) ) {
case V_284 :
V_103 = F_235 ( V_5 , V_38 ) ;
break;
case V_285 :
V_103 = F_238 ( V_5 , V_38 ) ;
break;
case V_286 :
V_103 = F_267 ( V_5 , V_38 ) ;
break;
case V_287 :
V_103 = F_268 ( V_5 , V_38 ) ;
break;
}
break;
case V_294 :
V_5 -> V_40 = V_38 ;
V_103 = 0 ;
break;
}
return V_103 ? : V_275 ;
}
static T_7 F_273 ( struct V_272 * V_273 , char * V_274 ,
T_8 V_275 , T_9 V_276 )
{
struct V_4 * V_5 = F_70 ( F_247 ( V_273 ) ) ;
struct V_214 * V_215 ;
switch ( F_254 ( F_272 ( V_273 ) -> V_184 ) ) {
case V_284 :
V_215 = & V_5 -> V_39 ;
break;
case V_285 :
V_215 = & V_5 -> V_116 ;
break;
case V_286 :
V_215 = & V_5 -> V_128 ;
break;
case V_287 :
V_215 = & V_5 -> V_288 ;
break;
default:
F_255 () ;
}
switch ( F_256 ( F_272 ( V_273 ) -> V_184 ) ) {
case V_291 :
F_274 ( V_215 ) ;
break;
case V_293 :
V_215 -> V_127 = 0 ;
break;
default:
F_255 () ;
}
return V_275 ;
}
static V_126 F_275 ( struct V_7 * V_9 ,
struct V_277 * V_278 )
{
return F_70 ( V_9 ) -> V_305 ;
}
static int F_276 ( struct V_7 * V_9 ,
struct V_277 * V_278 , V_126 V_45 )
{
struct V_4 * V_5 = F_70 ( V_9 ) ;
if ( V_45 & ~ V_306 )
return - V_259 ;
V_5 -> V_305 = V_45 ;
return 0 ;
}
static int F_276 ( struct V_7 * V_9 ,
struct V_277 * V_278 , V_126 V_45 )
{
return - V_307 ;
}
static int F_277 ( struct V_308 * V_309 , void * V_310 )
{
struct V_311 {
const char * V_312 ;
unsigned int V_58 ;
};
static const struct V_311 V_313 [] = {
{ L_13 , V_314 } ,
{ L_14 , V_147 } ,
{ L_15 , V_148 } ,
{ L_16 , F_58 (LRU_UNEVICTABLE) } ,
} ;
const struct V_311 * V_47 ;
int V_17 ;
unsigned long V_60 ;
struct V_4 * V_5 = F_70 ( F_278 ( V_309 ) ) ;
for ( V_47 = V_313 ; V_47 < V_313 + F_113 ( V_313 ) ; V_47 ++ ) {
V_60 = F_60 ( V_5 , V_47 -> V_58 ) ;
F_279 ( V_309 , L_17 , V_47 -> V_312 , V_60 ) ;
F_61 (nid, N_MEMORY) {
V_60 = F_53 ( V_5 , V_17 ,
V_47 -> V_58 ) ;
F_279 ( V_309 , L_18 , V_17 , V_60 ) ;
}
F_280 ( V_309 , '\n' ) ;
}
for ( V_47 = V_313 ; V_47 < V_313 + F_113 ( V_313 ) ; V_47 ++ ) {
struct V_4 * V_89 ;
V_60 = 0 ;
F_85 (iter, memcg)
V_60 += F_60 ( V_89 , V_47 -> V_58 ) ;
F_279 ( V_309 , L_19 , V_47 -> V_312 , V_60 ) ;
F_61 (nid, N_MEMORY) {
V_60 = 0 ;
F_85 (iter, memcg)
V_60 += F_53 (
V_89 , V_17 , V_47 -> V_58 ) ;
F_279 ( V_309 , L_18 , V_17 , V_60 ) ;
}
F_280 ( V_309 , '\n' ) ;
}
return 0 ;
}
static int F_281 ( struct V_308 * V_309 , void * V_310 )
{
struct V_4 * V_5 = F_70 ( F_278 ( V_309 ) ) ;
unsigned long V_39 , V_116 ;
struct V_4 * V_315 ;
unsigned int V_100 ;
F_282 ( F_113 ( V_131 ) != F_113 ( V_129 ) ) ;
F_282 ( F_113 ( V_133 ) != V_132 ) ;
for ( V_100 = 0 ; V_100 < F_113 ( V_129 ) ; V_100 ++ ) {
if ( V_129 [ V_100 ] == V_130 && ! F_1 () )
continue;
F_279 ( V_309 , L_20 , V_131 [ V_100 ] ,
F_114 ( V_5 , V_129 [ V_100 ] ) *
V_229 ) ;
}
for ( V_100 = 0 ; V_100 < F_113 ( V_316 ) ; V_100 ++ )
F_279 ( V_309 , L_20 , V_317 [ V_100 ] ,
F_43 ( V_5 , V_316 [ V_100 ] ) ) ;
for ( V_100 = 0 ; V_100 < V_132 ; V_100 ++ )
F_279 ( V_309 , L_20 , V_133 [ V_100 ] ,
F_60 ( V_5 , F_58 ( V_100 ) ) * V_229 ) ;
V_39 = V_116 = V_318 ;
for ( V_315 = V_5 ; V_315 ; V_315 = F_15 ( V_315 ) ) {
V_39 = F_98 ( V_39 , V_315 -> V_39 . V_115 ) ;
V_116 = F_98 ( V_116 , V_315 -> V_116 . V_115 ) ;
}
F_279 ( V_309 , L_21 ,
( V_126 ) V_39 * V_229 ) ;
if ( F_1 () )
F_279 ( V_309 , L_22 ,
( V_126 ) V_116 * V_229 ) ;
for ( V_100 = 0 ; V_100 < F_113 ( V_129 ) ; V_100 ++ ) {
unsigned long long V_45 = 0 ;
if ( V_129 [ V_100 ] == V_130 && ! F_1 () )
continue;
F_85 (mi, memcg)
V_45 += F_114 ( V_315 , V_129 [ V_100 ] ) *
V_229 ;
F_279 ( V_309 , L_23 , V_131 [ V_100 ] , V_45 ) ;
}
for ( V_100 = 0 ; V_100 < F_113 ( V_316 ) ; V_100 ++ ) {
unsigned long long V_45 = 0 ;
F_85 (mi, memcg)
V_45 += F_43 ( V_315 , V_316 [ V_100 ] ) ;
F_279 ( V_309 , L_23 , V_317 [ V_100 ] , V_45 ) ;
}
for ( V_100 = 0 ; V_100 < V_132 ; V_100 ++ ) {
unsigned long long V_45 = 0 ;
F_85 (mi, memcg)
V_45 += F_60 ( V_315 , F_58 ( V_100 ) ) * V_229 ;
F_279 ( V_309 , L_23 , V_133 [ V_100 ] , V_45 ) ;
}
#ifdef F_283
{
T_4 * V_93 ;
struct V_16 * V_22 ;
struct V_319 * V_320 ;
unsigned long V_321 [ 2 ] = { 0 , 0 } ;
unsigned long V_322 [ 2 ] = { 0 , 0 } ;
F_284 (pgdat) {
V_22 = F_37 ( V_5 , V_93 -> V_94 ) ;
V_320 = & V_22 -> V_59 . V_323 ;
V_321 [ 0 ] += V_320 -> V_321 [ 0 ] ;
V_321 [ 1 ] += V_320 -> V_321 [ 1 ] ;
V_322 [ 0 ] += V_320 -> V_322 [ 0 ] ;
V_322 [ 1 ] += V_320 -> V_322 [ 1 ] ;
}
F_279 ( V_309 , L_24 , V_321 [ 0 ] ) ;
F_279 ( V_309 , L_25 , V_321 [ 1 ] ) ;
F_279 ( V_309 , L_26 , V_322 [ 0 ] ) ;
F_279 ( V_309 , L_27 , V_322 [ 1 ] ) ;
}
#endif
return 0 ;
}
static V_126 F_285 ( struct V_7 * V_9 ,
struct V_277 * V_278 )
{
struct V_4 * V_5 = F_70 ( V_9 ) ;
return F_117 ( V_5 ) ;
}
static int F_286 ( struct V_7 * V_9 ,
struct V_277 * V_278 , V_126 V_45 )
{
struct V_4 * V_5 = F_70 ( V_9 ) ;
if ( V_45 > 100 )
return - V_259 ;
if ( V_9 -> V_28 )
V_5 -> V_324 = V_45 ;
else
V_325 = V_45 ;
return 0 ;
}
static void F_287 ( struct V_4 * V_5 , bool V_137 )
{
struct V_326 * V_327 ;
unsigned long V_328 ;
int V_100 ;
F_13 () ;
if ( ! V_137 )
V_327 = F_73 ( V_5 -> V_329 . V_330 ) ;
else
V_327 = F_73 ( V_5 -> V_331 . V_330 ) ;
if ( ! V_327 )
goto V_120;
V_328 = F_252 ( V_5 , V_137 ) ;
V_100 = V_327 -> V_332 ;
for (; V_100 >= 0 && F_66 ( V_327 -> V_333 [ V_100 ] . V_334 > V_328 ) ; V_100 -- )
F_288 ( V_327 -> V_333 [ V_100 ] . V_335 , 1 ) ;
V_100 ++ ;
for (; V_100 < V_327 -> V_110 && F_66 ( V_327 -> V_333 [ V_100 ] . V_334 <= V_328 ) ; V_100 ++ )
F_288 ( V_327 -> V_333 [ V_100 ] . V_335 , 1 ) ;
V_327 -> V_332 = V_100 - 1 ;
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
static int F_289 ( const void * V_336 , const void * V_337 )
{
const struct F_67 * V_338 = V_336 ;
const struct F_67 * V_339 = V_337 ;
if ( V_338 -> V_334 > V_339 -> V_334 )
return 1 ;
if ( V_338 -> V_334 < V_339 -> V_334 )
return - 1 ;
return 0 ;
}
static int F_290 ( struct V_4 * V_5 )
{
struct V_340 * V_341 ;
F_100 ( & V_163 ) ;
F_291 (ev, &memcg->oom_notify, list)
F_288 ( V_341 -> V_335 , 1 ) ;
F_101 ( & V_163 ) ;
return 0 ;
}
static void F_147 ( struct V_4 * V_5 )
{
struct V_4 * V_89 ;
F_85 (iter, memcg)
F_290 ( V_89 ) ;
}
static int F_292 ( struct V_4 * V_5 ,
struct V_342 * V_335 , const char * args , enum V_343 type )
{
struct V_344 * V_329 ;
struct V_326 * V_345 ;
unsigned long V_334 ;
unsigned long V_328 ;
int V_100 , V_110 , V_103 ;
V_103 = F_271 ( args , L_12 , & V_334 ) ;
if ( V_103 )
return V_103 ;
F_119 ( & V_5 -> V_346 ) ;
if ( type == V_284 ) {
V_329 = & V_5 -> V_329 ;
V_328 = F_252 ( V_5 , false ) ;
} else if ( type == V_285 ) {
V_329 = & V_5 -> V_331 ;
V_328 = F_252 ( V_5 , true ) ;
} else
F_255 () ;
if ( V_329 -> V_330 )
F_287 ( V_5 , type == V_285 ) ;
V_110 = V_329 -> V_330 ? V_329 -> V_330 -> V_110 + 1 : 1 ;
V_345 = F_213 ( sizeof( * V_345 ) + V_110 * sizeof( struct F_67 ) ,
V_208 ) ;
if ( ! V_345 ) {
V_103 = - V_230 ;
goto V_120;
}
V_345 -> V_110 = V_110 ;
if ( V_329 -> V_330 ) {
memcpy ( V_345 -> V_333 , V_329 -> V_330 -> V_333 , ( V_110 - 1 ) *
sizeof( struct F_67 ) ) ;
}
V_345 -> V_333 [ V_110 - 1 ] . V_335 = V_335 ;
V_345 -> V_333 [ V_110 - 1 ] . V_334 = V_334 ;
F_293 ( V_345 -> V_333 , V_110 , sizeof( struct F_67 ) ,
F_289 , NULL ) ;
V_345 -> V_332 = - 1 ;
for ( V_100 = 0 ; V_100 < V_110 ; V_100 ++ ) {
if ( V_345 -> V_333 [ V_100 ] . V_334 <= V_328 ) {
++ V_345 -> V_332 ;
} else
break;
}
F_211 ( V_329 -> V_347 ) ;
V_329 -> V_347 = V_329 -> V_330 ;
F_294 ( V_329 -> V_330 , V_345 ) ;
F_295 () ;
V_120:
F_121 ( & V_5 -> V_346 ) ;
return V_103 ;
}
static int F_296 ( struct V_4 * V_5 ,
struct V_342 * V_335 , const char * args )
{
return F_292 ( V_5 , V_335 , args , V_284 ) ;
}
static int F_297 ( struct V_4 * V_5 ,
struct V_342 * V_335 , const char * args )
{
return F_292 ( V_5 , V_335 , args , V_285 ) ;
}
static void F_298 ( struct V_4 * V_5 ,
struct V_342 * V_335 , enum V_343 type )
{
struct V_344 * V_329 ;
struct V_326 * V_345 ;
unsigned long V_328 ;
int V_100 , V_348 , V_110 ;
F_119 ( & V_5 -> V_346 ) ;
if ( type == V_284 ) {
V_329 = & V_5 -> V_329 ;
V_328 = F_252 ( V_5 , false ) ;
} else if ( type == V_285 ) {
V_329 = & V_5 -> V_331 ;
V_328 = F_252 ( V_5 , true ) ;
} else
F_255 () ;
if ( ! V_329 -> V_330 )
goto V_120;
F_287 ( V_5 , type == V_285 ) ;
V_110 = 0 ;
for ( V_100 = 0 ; V_100 < V_329 -> V_330 -> V_110 ; V_100 ++ ) {
if ( V_329 -> V_330 -> V_333 [ V_100 ] . V_335 != V_335 )
V_110 ++ ;
}
V_345 = V_329 -> V_347 ;
if ( ! V_110 ) {
F_211 ( V_345 ) ;
V_345 = NULL ;
goto V_349;
}
V_345 -> V_110 = V_110 ;
V_345 -> V_332 = - 1 ;
for ( V_100 = 0 , V_348 = 0 ; V_100 < V_329 -> V_330 -> V_110 ; V_100 ++ ) {
if ( V_329 -> V_330 -> V_333 [ V_100 ] . V_335 == V_335 )
continue;
V_345 -> V_333 [ V_348 ] = V_329 -> V_330 -> V_333 [ V_100 ] ;
if ( V_345 -> V_333 [ V_348 ] . V_334 <= V_328 ) {
++ V_345 -> V_332 ;
}
V_348 ++ ;
}
V_349:
V_329 -> V_347 = V_329 -> V_330 ;
F_294 ( V_329 -> V_330 , V_345 ) ;
F_295 () ;
if ( ! V_345 ) {
F_211 ( V_329 -> V_347 ) ;
V_329 -> V_347 = NULL ;
}
V_120:
F_121 ( & V_5 -> V_346 ) ;
}
static void F_299 ( struct V_4 * V_5 ,
struct V_342 * V_335 )
{
return F_298 ( V_5 , V_335 , V_284 ) ;
}
static void F_300 ( struct V_4 * V_5 ,
struct V_342 * V_335 )
{
return F_298 ( V_5 , V_335 , V_285 ) ;
}
static int F_301 ( struct V_4 * V_5 ,
struct V_342 * V_335 , const char * args )
{
struct V_340 * V_44 ;
V_44 = F_213 ( sizeof( * V_44 ) , V_208 ) ;
if ( ! V_44 )
return - V_230 ;
F_100 ( & V_163 ) ;
V_44 -> V_335 = V_335 ;
F_302 ( & V_44 -> V_350 , & V_5 -> V_351 ) ;
if ( V_5 -> V_166 )
F_288 ( V_335 , 1 ) ;
F_101 ( & V_163 ) ;
return 0 ;
}
static void F_303 ( struct V_4 * V_5 ,
struct V_342 * V_335 )
{
struct V_340 * V_341 , * V_352 ;
F_100 ( & V_163 ) ;
F_304 (ev, tmp, &memcg->oom_notify, list) {
if ( V_341 -> V_335 == V_335 ) {
F_305 ( & V_341 -> V_350 ) ;
F_211 ( V_341 ) ;
}
}
F_101 ( & V_163 ) ;
}
static int F_306 ( struct V_308 * V_353 , void * V_310 )
{
struct V_4 * V_5 = F_70 ( F_278 ( V_353 ) ) ;
F_279 ( V_353 , L_28 , V_5 -> V_187 ) ;
F_279 ( V_353 , L_29 , ( bool ) V_5 -> V_166 ) ;
F_279 ( V_353 , L_30 , F_43 ( V_5 , V_354 ) ) ;
return 0 ;
}
static int F_307 ( struct V_7 * V_9 ,
struct V_277 * V_278 , V_126 V_45 )
{
struct V_4 * V_5 = F_70 ( V_9 ) ;
if ( ! V_9 -> V_28 || ! ( ( V_45 == 0 ) || ( V_45 == 1 ) ) )
return - V_259 ;
V_5 -> V_187 = V_45 ;
if ( ! V_45 )
F_142 ( V_5 ) ;
return 0 ;
}
struct V_355 * F_308 ( struct V_4 * V_5 )
{
return & V_5 -> V_356 ;
}
static int F_309 ( struct V_4 * V_5 , T_3 V_253 )
{
return F_310 ( & V_5 -> V_357 , V_253 ) ;
}
static void F_311 ( struct V_4 * V_5 )
{
F_312 ( & V_5 -> V_357 ) ;
}
static void F_313 ( struct V_4 * V_5 )
{
F_314 ( & V_5 -> V_357 ) ;
}
struct V_358 * F_315 ( struct V_359 * V_360 )
{
struct V_4 * V_5 = F_70 ( V_360 -> V_361 ) ;
if ( ! V_5 -> V_9 . V_28 )
return NULL ;
return & V_5 -> V_357 ;
}
void F_316 ( struct V_359 * V_360 , unsigned long * V_362 ,
unsigned long * V_363 , unsigned long * V_364 ,
unsigned long * V_365 )
{
struct V_4 * V_5 = F_70 ( V_360 -> V_361 ) ;
struct V_4 * V_28 ;
* V_364 = F_114 ( V_5 , V_366 ) ;
* V_365 = F_114 ( V_5 , V_367 ) ;
* V_362 = F_60 ( V_5 , ( 1 << V_368 ) |
( 1 << V_369 ) ) ;
* V_363 = V_318 ;
while ( ( V_28 = F_15 ( V_5 ) ) ) {
unsigned long V_370 = F_98 ( V_5 -> V_39 . V_115 , V_5 -> V_205 ) ;
unsigned long V_371 = F_33 ( & V_5 -> V_39 ) ;
* V_363 = F_98 ( * V_363 , V_370 - F_98 ( V_370 , V_371 ) ) ;
V_5 = V_28 ;
}
}
static int F_309 ( struct V_4 * V_5 , T_3 V_253 )
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
struct F_170 * V_44 =
F_5 ( V_204 , struct F_170 , remove ) ;
struct V_4 * V_5 = V_44 -> V_5 ;
F_318 ( V_44 -> V_372 , & V_44 -> V_123 ) ;
V_44 -> V_373 ( V_5 , V_44 -> V_335 ) ;
F_288 ( V_44 -> V_335 , 1 ) ;
F_319 ( V_44 -> V_335 ) ;
F_211 ( V_44 ) ;
F_79 ( & V_5 -> V_9 ) ;
}
static int F_320 ( T_5 * V_123 , unsigned V_167 ,
int V_168 , void * V_374 )
{
struct F_170 * V_44 =
F_5 ( V_123 , struct F_170 , V_123 ) ;
struct V_4 * V_5 = V_44 -> V_5 ;
unsigned long V_13 = ( unsigned long ) V_374 ;
if ( V_13 & V_375 ) {
F_100 ( & V_5 -> V_376 ) ;
if ( ! F_321 ( & V_44 -> V_350 ) ) {
F_322 ( & V_44 -> V_350 ) ;
F_187 ( & V_44 -> remove ) ;
}
F_101 ( & V_5 -> V_376 ) ;
}
return 0 ;
}
static void F_323 ( struct V_377 * V_377 ,
T_10 * V_372 , T_11 * V_378 )
{
struct F_170 * V_44 =
F_5 ( V_378 , struct F_170 , V_378 ) ;
V_44 -> V_372 = V_372 ;
F_324 ( V_372 , & V_44 -> V_123 ) ;
}
static T_7 F_325 ( struct V_272 * V_273 ,
char * V_274 , T_8 V_275 , T_9 V_276 )
{
struct V_7 * V_9 = F_247 ( V_273 ) ;
struct V_4 * V_5 = F_70 ( V_9 ) ;
struct F_170 * V_44 ;
struct V_7 * V_379 ;
unsigned int V_380 , V_381 ;
struct V_382 V_383 ;
struct V_382 V_384 ;
const char * V_312 ;
char * V_385 ;
int V_103 ;
V_274 = F_270 ( V_274 ) ;
V_380 = F_326 ( V_274 , & V_385 , 10 ) ;
if ( * V_385 != ' ' )
return - V_259 ;
V_274 = V_385 + 1 ;
V_381 = F_326 ( V_274 , & V_385 , 10 ) ;
if ( ( * V_385 != ' ' ) && ( * V_385 != '\0' ) )
return - V_259 ;
V_274 = V_385 + 1 ;
V_44 = F_327 ( sizeof( * V_44 ) , V_208 ) ;
if ( ! V_44 )
return - V_230 ;
V_44 -> V_5 = V_5 ;
F_146 ( & V_44 -> V_350 ) ;
F_328 ( & V_44 -> V_378 , F_323 ) ;
F_329 ( & V_44 -> V_123 , F_320 ) ;
F_214 ( & V_44 -> remove , F_317 ) ;
V_383 = F_330 ( V_380 ) ;
if ( ! V_383 . V_377 ) {
V_103 = - V_386 ;
goto V_387;
}
V_44 -> V_335 = F_331 ( V_383 . V_377 ) ;
if ( F_332 ( V_44 -> V_335 ) ) {
V_103 = F_333 ( V_44 -> V_335 ) ;
goto V_388;
}
V_384 = F_330 ( V_381 ) ;
if ( ! V_384 . V_377 ) {
V_103 = - V_386 ;
goto V_389;
}
V_103 = F_334 ( F_335 ( V_384 . V_377 ) , V_390 ) ;
if ( V_103 < 0 )
goto V_391;
V_312 = V_384 . V_377 -> V_392 . V_393 -> V_394 . V_312 ;
if ( ! strcmp ( V_312 , L_31 ) ) {
V_44 -> V_395 = F_296 ;
V_44 -> V_373 = F_299 ;
} else if ( ! strcmp ( V_312 , L_32 ) ) {
V_44 -> V_395 = F_301 ;
V_44 -> V_373 = F_303 ;
} else if ( ! strcmp ( V_312 , L_33 ) ) {
V_44 -> V_395 = V_396 ;
V_44 -> V_373 = V_397 ;
} else if ( ! strcmp ( V_312 , L_34 ) ) {
V_44 -> V_395 = F_297 ;
V_44 -> V_373 = F_300 ;
} else {
V_103 = - V_259 ;
goto V_391;
}
V_379 = F_336 ( V_384 . V_377 -> V_392 . V_393 -> V_398 ,
& V_1 ) ;
V_103 = - V_259 ;
if ( F_332 ( V_379 ) )
goto V_391;
if ( V_379 != V_9 ) {
F_79 ( V_379 ) ;
goto V_391;
}
V_103 = V_44 -> V_395 ( V_5 , V_44 -> V_335 , V_274 ) ;
if ( V_103 )
goto V_399;
V_383 . V_377 -> V_400 -> V_401 ( V_383 . V_377 , & V_44 -> V_378 ) ;
F_100 ( & V_5 -> V_376 ) ;
F_302 ( & V_44 -> V_350 , & V_5 -> V_402 ) ;
F_101 ( & V_5 -> V_376 ) ;
F_337 ( V_384 ) ;
F_337 ( V_383 ) ;
return V_275 ;
V_399:
F_79 ( V_9 ) ;
V_391:
F_337 ( V_384 ) ;
V_389:
F_319 ( V_44 -> V_335 ) ;
V_388:
F_337 ( V_383 ) ;
V_387:
F_211 ( V_44 ) ;
return V_103 ;
}
static void F_338 ( struct V_4 * V_5 , unsigned int V_403 )
{
F_56 ( F_124 ( & V_5 -> V_235 . V_404 ) <= 0 ) ;
F_339 ( V_403 , & V_5 -> V_235 . V_404 ) ;
}
static void F_340 ( struct V_4 * V_5 , unsigned int V_403 )
{
F_56 ( F_124 ( & V_5 -> V_235 . V_404 ) < V_403 ) ;
if ( F_341 ( V_403 , & V_5 -> V_235 . V_404 ) ) {
F_342 ( & V_405 , V_5 -> V_235 . V_235 ) ;
V_5 -> V_235 . V_235 = 0 ;
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
struct V_4 * F_345 ( unsigned short V_235 )
{
F_346 ( ! F_347 () ) ;
return F_348 ( & V_405 , V_235 ) ;
}
static int F_349 ( struct V_4 * V_5 , int V_153 )
{
struct V_16 * V_406 ;
int V_352 = V_153 ;
if ( ! F_350 ( V_153 , V_407 ) )
V_352 = - 1 ;
V_406 = F_351 ( sizeof( * V_406 ) , V_208 , V_352 ) ;
if ( ! V_406 )
return 1 ;
V_406 -> V_408 = F_352 ( struct V_408 ) ;
if ( ! V_406 -> V_408 ) {
F_211 ( V_406 ) ;
return 1 ;
}
F_353 ( & V_406 -> V_59 ) ;
V_406 -> V_32 = 0 ;
V_406 -> V_31 = false ;
V_406 -> V_5 = V_5 ;
V_5 -> V_18 [ V_153 ] = V_406 ;
return 0 ;
}
static void F_354 ( struct V_4 * V_5 , int V_153 )
{
struct V_16 * V_406 = V_5 -> V_18 [ V_153 ] ;
F_355 ( V_406 -> V_408 ) ;
F_211 ( V_406 ) ;
}
static void F_356 ( struct V_4 * V_5 )
{
int V_153 ;
F_36 (node)
F_354 ( V_5 , V_153 ) ;
F_355 ( V_5 -> V_47 ) ;
F_211 ( V_5 ) ;
}
static void F_357 ( struct V_4 * V_5 )
{
F_311 ( V_5 ) ;
F_356 ( V_5 ) ;
}
static struct V_4 * F_358 ( void )
{
struct V_4 * V_5 ;
T_8 V_110 ;
int V_153 ;
V_110 = sizeof( struct V_4 ) ;
V_110 += V_63 * sizeof( struct V_16 * ) ;
V_5 = F_327 ( V_110 , V_208 ) ;
if ( ! V_5 )
return NULL ;
V_5 -> V_235 . V_235 = F_359 ( & V_405 , NULL ,
1 , V_409 ,
V_208 ) ;
if ( V_5 -> V_235 . V_235 < 0 )
goto V_410;
V_5 -> V_47 = F_352 ( struct V_411 ) ;
if ( ! V_5 -> V_47 )
goto V_410;
F_36 (node)
if ( F_349 ( V_5 , V_153 ) )
goto V_410;
if ( F_309 ( V_5 , V_208 ) )
goto V_410;
F_214 ( & V_5 -> V_207 , F_172 ) ;
V_5 -> V_154 = V_76 ;
F_146 ( & V_5 -> V_351 ) ;
F_360 ( & V_5 -> V_346 ) ;
F_361 ( & V_5 -> V_190 ) ;
F_362 ( & V_5 -> V_3 ) ;
F_146 ( & V_5 -> V_402 ) ;
F_361 ( & V_5 -> V_376 ) ;
V_5 -> V_412 = V_413 ;
#ifndef F_363
V_5 -> V_251 = - 1 ;
#endif
#ifdef F_364
F_146 ( & V_5 -> V_356 ) ;
#endif
F_365 ( & V_405 , V_5 , V_5 -> V_235 . V_235 ) ;
return V_5 ;
V_410:
if ( V_5 -> V_235 . V_235 > 0 )
F_342 ( & V_405 , V_5 -> V_235 . V_235 ) ;
F_356 ( V_5 ) ;
return NULL ;
}
static struct V_7 * T_12
F_366 ( struct V_7 * V_414 )
{
struct V_4 * V_28 = F_70 ( V_414 ) ;
struct V_4 * V_5 ;
long error = - V_230 ;
V_5 = F_358 () ;
if ( ! V_5 )
return F_367 ( error ) ;
V_5 -> V_205 = V_318 ;
V_5 -> V_40 = V_318 ;
if ( V_28 ) {
V_5 -> V_324 = F_117 ( V_28 ) ;
V_5 -> V_187 = V_28 -> V_187 ;
}
if ( V_28 && V_28 -> V_91 ) {
V_5 -> V_91 = true ;
F_368 ( & V_5 -> V_39 , & V_28 -> V_39 ) ;
F_368 ( & V_5 -> V_137 , & V_28 -> V_137 ) ;
F_368 ( & V_5 -> V_116 , & V_28 -> V_116 ) ;
F_368 ( & V_5 -> V_128 , & V_28 -> V_128 ) ;
F_368 ( & V_5 -> V_288 , & V_28 -> V_288 ) ;
} else {
F_368 ( & V_5 -> V_39 , NULL ) ;
F_368 ( & V_5 -> V_137 , NULL ) ;
F_368 ( & V_5 -> V_116 , NULL ) ;
F_368 ( & V_5 -> V_128 , NULL ) ;
F_368 ( & V_5 -> V_288 , NULL ) ;
if ( V_28 != V_6 )
V_1 . V_415 = true ;
}
if ( ! V_28 ) {
V_6 = V_5 ;
return & V_5 -> V_9 ;
}
error = F_257 ( V_5 ) ;
if ( error )
goto V_410;
if ( F_2 ( V_1 ) && ! V_416 )
F_258 ( & V_304 ) ;
return & V_5 -> V_9 ;
V_410:
F_357 ( V_5 ) ;
return F_367 ( - V_230 ) ;
}
static int F_369 ( struct V_7 * V_9 )
{
struct V_4 * V_5 = F_70 ( V_9 ) ;
F_128 ( & V_5 -> V_235 . V_404 , 1 ) ;
F_95 ( V_9 ) ;
return 0 ;
}
static void F_370 ( struct V_7 * V_9 )
{
struct V_4 * V_5 = F_70 ( V_9 ) ;
struct F_170 * V_44 , * V_352 ;
F_100 ( & V_5 -> V_376 ) ;
F_304 (event, tmp, &memcg->event_list, list) {
F_322 ( & V_44 -> V_350 ) ;
F_187 ( & V_44 -> remove ) ;
}
F_101 ( & V_5 -> V_376 ) ;
V_5 -> V_417 = 0 ;
F_259 ( V_5 ) ;
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
if ( F_2 ( V_1 ) && ! V_416 )
F_265 ( & V_304 ) ;
if ( ! F_2 ( V_1 ) && V_5 -> V_303 )
F_265 ( & V_304 ) ;
F_374 ( & V_5 -> V_3 ) ;
F_375 ( & V_5 -> V_207 ) ;
F_35 ( V_5 ) ;
F_263 ( V_5 ) ;
F_357 ( V_5 ) ;
}
static void F_376 ( struct V_7 * V_9 )
{
struct V_4 * V_5 = F_70 ( V_9 ) ;
F_237 ( & V_5 -> V_39 , V_318 ) ;
F_237 ( & V_5 -> V_137 , V_318 ) ;
F_237 ( & V_5 -> V_116 , V_318 ) ;
F_237 ( & V_5 -> V_128 , V_318 ) ;
F_237 ( & V_5 -> V_288 , V_318 ) ;
V_5 -> V_417 = 0 ;
V_5 -> V_205 = V_318 ;
V_5 -> V_40 = V_318 ;
F_313 ( V_5 ) ;
}
static int F_377 ( unsigned long V_50 )
{
int V_103 ;
V_103 = F_175 ( V_119 . V_118 , V_208 & ~ V_418 , V_50 ) ;
if ( ! V_103 ) {
V_119 . V_419 += V_50 ;
return V_103 ;
}
while ( V_50 -- ) {
V_103 = F_175 ( V_119 . V_118 , V_208 | V_225 , 1 ) ;
if ( V_103 )
return V_103 ;
V_119 . V_419 ++ ;
F_378 () ;
}
return 0 ;
}
static struct V_11 * F_379 ( struct V_420 * V_421 ,
unsigned long V_422 , T_13 V_423 )
{
struct V_11 * V_11 = F_380 ( V_421 , V_422 , V_423 , true ) ;
if ( ! V_11 || ! F_381 ( V_11 ) )
return NULL ;
if ( F_47 ( V_11 ) ) {
if ( ! ( V_119 . V_13 & V_424 ) )
return NULL ;
} else {
if ( ! ( V_119 . V_13 & V_425 ) )
return NULL ;
}
if ( ! F_382 ( V_11 ) )
return NULL ;
return V_11 ;
}
static struct V_11 * F_383 ( struct V_420 * V_421 ,
T_13 V_423 , T_6 * V_185 )
{
struct V_11 * V_11 = NULL ;
T_6 V_426 = F_384 ( V_423 ) ;
if ( ! ( V_119 . V_13 & V_424 ) || F_385 ( V_426 ) )
return NULL ;
if ( F_386 ( V_426 ) ) {
V_11 = F_387 ( V_426 ) ;
if ( ! F_388 ( V_11 , 1 , 1 ) )
return NULL ;
return V_11 ;
}
V_11 = F_389 ( F_390 ( V_426 ) , F_391 ( V_426 ) ) ;
if ( F_1 () )
V_185 -> V_45 = V_426 . V_45 ;
return V_11 ;
}
static struct V_11 * F_383 ( struct V_420 * V_421 ,
T_13 V_423 , T_6 * V_185 )
{
return NULL ;
}
static struct V_11 * F_392 ( struct V_420 * V_421 ,
unsigned long V_422 , T_13 V_423 , T_6 * V_185 )
{
struct V_11 * V_11 = NULL ;
struct V_427 * V_428 ;
T_14 V_429 ;
if ( ! V_421 -> V_430 )
return NULL ;
if ( ! ( V_119 . V_13 & V_425 ) )
return NULL ;
V_428 = V_421 -> V_430 -> V_431 ;
V_429 = F_393 ( V_421 , V_422 ) ;
#ifdef F_394
if ( F_395 ( V_428 ) ) {
V_11 = F_396 ( V_428 , V_429 ) ;
if ( F_397 ( V_11 ) ) {
T_6 V_432 = F_398 ( V_11 ) ;
if ( F_1 () )
* V_185 = V_432 ;
V_11 = F_389 ( F_390 ( V_432 ) ,
F_391 ( V_432 ) ) ;
}
} else
V_11 = F_389 ( V_428 , V_429 ) ;
#else
V_11 = F_389 ( V_428 , V_429 ) ;
#endif
return V_11 ;
}
static int F_399 ( struct V_11 * V_11 ,
bool V_49 ,
struct V_4 * V_117 ,
struct V_4 * V_118 )
{
unsigned long V_13 ;
unsigned int V_38 = V_49 ? F_400 ( V_11 ) : 1 ;
int V_103 ;
bool V_433 ;
F_56 ( V_117 == V_118 ) ;
F_50 ( F_193 ( V_11 ) , V_11 ) ;
F_56 ( V_49 && ! F_51 ( V_11 ) ) ;
V_103 = - V_281 ;
if ( ! F_401 ( V_11 ) )
goto V_92;
V_103 = - V_259 ;
if ( V_11 -> V_4 != V_117 )
goto V_97;
V_433 = F_47 ( V_11 ) ;
F_30 ( & V_117 -> V_190 , V_13 ) ;
if ( ! V_433 && F_381 ( V_11 ) ) {
F_229 ( V_117 -> V_47 -> V_50 [ V_434 ] , V_38 ) ;
F_48 ( V_118 -> V_47 -> V_50 [ V_434 ] , V_38 ) ;
}
if ( ! V_433 && F_402 ( V_11 ) ) {
struct V_427 * V_428 = F_403 ( V_11 ) ;
if ( F_404 ( V_428 ) ) {
F_229 ( V_117 -> V_47 -> V_50 [ V_366 ] ,
V_38 ) ;
F_48 ( V_118 -> V_47 -> V_50 [ V_366 ] ,
V_38 ) ;
}
}
if ( F_405 ( V_11 ) ) {
F_229 ( V_117 -> V_47 -> V_50 [ V_367 ] , V_38 ) ;
F_48 ( V_118 -> V_47 -> V_50 [ V_367 ] , V_38 ) ;
}
V_11 -> V_4 = V_118 ;
F_31 ( & V_117 -> V_190 , V_13 ) ;
V_103 = 0 ;
F_406 () ;
F_46 ( V_118 , V_11 , V_49 , V_38 ) ;
F_65 ( V_118 , V_11 ) ;
F_46 ( V_117 , V_11 , V_49 , - V_38 ) ;
F_65 ( V_117 , V_11 ) ;
F_407 () ;
V_97:
F_408 ( V_11 ) ;
V_92:
return V_103 ;
}
static enum V_435 F_409 ( struct V_420 * V_421 ,
unsigned long V_422 , T_13 V_423 , union V_436 * V_65 )
{
struct V_11 * V_11 = NULL ;
enum V_435 V_103 = V_437 ;
T_6 V_426 = { . V_45 = 0 } ;
if ( F_410 ( V_423 ) )
V_11 = F_379 ( V_421 , V_422 , V_423 ) ;
else if ( F_411 ( V_423 ) )
V_11 = F_383 ( V_421 , V_423 , & V_426 ) ;
else if ( F_412 ( V_423 ) )
V_11 = F_392 ( V_421 , V_422 , V_423 , & V_426 ) ;
if ( ! V_11 && ! V_426 . V_45 )
return V_103 ;
if ( V_11 ) {
if ( V_11 -> V_4 == V_119 . V_117 ) {
V_103 = V_438 ;
if ( F_413 ( V_11 ) ||
F_414 ( V_11 ) )
V_103 = V_439 ;
if ( V_65 )
V_65 -> V_11 = V_11 ;
}
if ( ! V_103 || ! V_65 )
F_415 ( V_11 ) ;
}
if ( V_426 . V_45 && ! V_103 && ( ! V_11 || ! F_416 ( V_11 ) ) &&
F_233 ( V_119 . V_117 ) == F_417 ( V_426 ) ) {
V_103 = V_440 ;
if ( V_65 )
V_65 -> V_426 = V_426 ;
}
return V_103 ;
}
static enum V_435 F_418 ( struct V_420 * V_421 ,
unsigned long V_422 , T_15 V_441 , union V_436 * V_65 )
{
struct V_11 * V_11 = NULL ;
enum V_435 V_103 = V_437 ;
if ( F_66 ( F_419 ( V_441 ) ) ) {
F_56 ( F_420 () &&
! F_421 ( V_441 ) ) ;
return V_103 ;
}
V_11 = F_422 ( V_441 ) ;
F_50 ( ! V_11 || ! F_423 ( V_11 ) , V_11 ) ;
if ( ! ( V_119 . V_13 & V_424 ) )
return V_103 ;
if ( V_11 -> V_4 == V_119 . V_117 ) {
V_103 = V_438 ;
if ( V_65 ) {
F_424 ( V_11 ) ;
V_65 -> V_11 = V_11 ;
}
}
return V_103 ;
}
static inline enum V_435 F_418 ( struct V_420 * V_421 ,
unsigned long V_422 , T_15 V_441 , union V_436 * V_65 )
{
return V_437 ;
}
static int F_425 ( T_15 * V_441 ,
unsigned long V_422 , unsigned long V_442 ,
struct V_443 * V_444 )
{
struct V_420 * V_421 = V_444 -> V_421 ;
T_13 * V_445 ;
T_16 * V_446 ;
V_446 = F_426 ( V_441 , V_421 ) ;
if ( V_446 ) {
if ( F_418 ( V_421 , V_422 , * V_441 , NULL ) == V_438 )
V_119 . V_419 += V_255 ;
F_101 ( V_446 ) ;
return 0 ;
}
if ( F_427 ( V_441 ) )
return 0 ;
V_445 = F_428 ( V_421 -> V_447 , V_441 , V_422 , & V_446 ) ;
for (; V_422 != V_442 ; V_445 ++ , V_422 += V_229 )
if ( F_409 ( V_421 , V_422 , * V_445 , NULL ) )
V_119 . V_419 ++ ;
F_429 ( V_445 - 1 , V_446 ) ;
F_378 () ;
return 0 ;
}
static unsigned long F_430 ( struct V_80 * V_81 )
{
unsigned long V_419 ;
struct V_443 V_448 = {
. V_449 = F_425 ,
. V_81 = V_81 ,
} ;
F_8 ( & V_81 -> V_450 ) ;
F_431 ( 0 , V_81 -> V_451 ,
& V_448 ) ;
F_10 ( & V_81 -> V_450 ) ;
V_419 = V_119 . V_419 ;
V_119 . V_419 = 0 ;
return V_419 ;
}
static int F_432 ( struct V_80 * V_81 )
{
unsigned long V_419 = F_430 ( V_81 ) ;
F_56 ( V_119 . V_121 ) ;
V_119 . V_121 = V_122 ;
return F_377 ( V_419 ) ;
}
static void F_433 ( void )
{
struct V_4 * V_117 = V_119 . V_117 ;
struct V_4 * V_118 = V_119 . V_118 ;
if ( V_119 . V_419 ) {
F_189 ( V_119 . V_118 , V_119 . V_419 ) ;
V_119 . V_419 = 0 ;
}
if ( V_119 . V_452 ) {
F_189 ( V_119 . V_117 , V_119 . V_452 ) ;
V_119 . V_452 = 0 ;
}
if ( V_119 . V_453 ) {
if ( ! F_6 ( V_119 . V_117 ) )
F_156 ( & V_119 . V_117 -> V_116 , V_119 . V_453 ) ;
F_340 ( V_119 . V_117 , V_119 . V_453 ) ;
if ( ! F_6 ( V_119 . V_118 ) )
F_156 ( & V_119 . V_118 -> V_39 , V_119 . V_453 ) ;
F_338 ( V_119 . V_118 , V_119 . V_453 ) ;
F_157 ( & V_119 . V_118 -> V_9 , V_119 . V_453 ) ;
V_119 . V_453 = 0 ;
}
F_142 ( V_117 ) ;
F_142 ( V_118 ) ;
F_434 ( & V_119 . V_124 ) ;
}
static void F_435 ( void )
{
struct V_80 * V_81 = V_119 . V_81 ;
V_119 . V_121 = NULL ;
F_433 () ;
F_100 ( & V_119 . V_37 ) ;
V_119 . V_117 = NULL ;
V_119 . V_118 = NULL ;
V_119 . V_81 = NULL ;
F_101 ( & V_119 . V_37 ) ;
F_436 ( V_81 ) ;
}
static int F_437 ( struct V_454 * V_455 )
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
F_438 (leader, css, tset) {
F_346 ( V_26 ) ;
V_26 = V_456 ;
V_5 = F_70 ( V_9 ) ;
}
if ( ! V_26 )
return 0 ;
V_457 = F_14 ( V_5 -> V_305 ) ;
if ( ! V_457 )
return 0 ;
V_117 = F_69 ( V_26 ) ;
F_56 ( V_117 == V_5 ) ;
V_81 = F_439 ( V_26 ) ;
if ( ! V_81 )
return 0 ;
if ( V_81 -> V_82 == V_26 ) {
F_56 ( V_119 . V_117 ) ;
F_56 ( V_119 . V_118 ) ;
F_56 ( V_119 . V_419 ) ;
F_56 ( V_119 . V_452 ) ;
F_56 ( V_119 . V_453 ) ;
F_100 ( & V_119 . V_37 ) ;
V_119 . V_81 = V_81 ;
V_119 . V_117 = V_117 ;
V_119 . V_118 = V_5 ;
V_119 . V_13 = V_457 ;
F_101 ( & V_119 . V_37 ) ;
V_103 = F_432 ( V_81 ) ;
if ( V_103 )
F_435 () ;
} else {
F_436 ( V_81 ) ;
}
return V_103 ;
}
static void F_440 ( struct V_454 * V_455 )
{
if ( V_119 . V_118 )
F_435 () ;
}
static int F_441 ( T_15 * V_441 ,
unsigned long V_422 , unsigned long V_442 ,
struct V_443 * V_444 )
{
int V_103 = 0 ;
struct V_420 * V_421 = V_444 -> V_421 ;
T_13 * V_445 ;
T_16 * V_446 ;
enum V_435 V_458 ;
union V_436 V_65 ;
struct V_11 * V_11 ;
V_446 = F_426 ( V_441 , V_421 ) ;
if ( V_446 ) {
if ( V_119 . V_419 < V_255 ) {
F_101 ( V_446 ) ;
return 0 ;
}
V_458 = F_418 ( V_421 , V_422 , * V_441 , & V_65 ) ;
if ( V_458 == V_438 ) {
V_11 = V_65 . V_11 ;
if ( ! F_442 ( V_11 ) ) {
if ( ! F_399 ( V_11 , true ,
V_119 . V_117 , V_119 . V_118 ) ) {
V_119 . V_419 -= V_255 ;
V_119 . V_452 += V_255 ;
}
F_443 ( V_11 ) ;
}
F_415 ( V_11 ) ;
} else if ( V_458 == V_439 ) {
V_11 = V_65 . V_11 ;
if ( ! F_399 ( V_11 , true ,
V_119 . V_117 , V_119 . V_118 ) ) {
V_119 . V_419 -= V_255 ;
V_119 . V_452 += V_255 ;
}
F_415 ( V_11 ) ;
}
F_101 ( V_446 ) ;
return 0 ;
}
if ( F_427 ( V_441 ) )
return 0 ;
V_42:
V_445 = F_428 ( V_421 -> V_447 , V_441 , V_422 , & V_446 ) ;
for (; V_422 != V_442 ; V_422 += V_229 ) {
T_13 V_423 = * ( V_445 ++ ) ;
bool V_459 = false ;
T_6 V_426 ;
if ( ! V_119 . V_419 )
break;
switch ( F_409 ( V_421 , V_422 , V_423 , & V_65 ) ) {
case V_439 :
V_459 = true ;
case V_438 :
V_11 = V_65 . V_11 ;
if ( F_416 ( V_11 ) )
goto V_460;
if ( ! V_459 && F_442 ( V_11 ) )
goto V_460;
if ( ! F_399 ( V_11 , false ,
V_119 . V_117 , V_119 . V_118 ) ) {
V_119 . V_419 -- ;
V_119 . V_452 ++ ;
}
if ( ! V_459 )
F_443 ( V_11 ) ;
V_460:
F_415 ( V_11 ) ;
break;
case V_440 :
V_426 = V_65 . V_426 ;
if ( ! F_232 ( V_426 , V_119 . V_117 , V_119 . V_118 ) ) {
V_119 . V_419 -- ;
V_119 . V_453 ++ ;
}
break;
default:
break;
}
}
F_429 ( V_445 - 1 , V_446 ) ;
F_378 () ;
if ( V_422 != V_442 ) {
V_103 = F_377 ( 1 ) ;
if ( ! V_103 )
goto V_42;
}
return V_103 ;
}
static void F_444 ( void )
{
struct V_443 V_461 = {
. V_449 = F_441 ,
. V_81 = V_119 . V_81 ,
} ;
F_244 () ;
F_68 ( & V_119 . V_117 -> V_189 ) ;
F_295 () ;
V_42:
if ( F_66 ( ! F_445 ( & V_119 . V_81 -> V_450 ) ) ) {
F_433 () ;
F_378 () ;
goto V_42;
}
F_431 ( 0 , V_119 . V_81 -> V_451 , & V_461 ) ;
F_10 ( & V_119 . V_81 -> V_450 ) ;
F_446 ( & V_119 . V_117 -> V_189 ) ;
}
static void F_447 ( void )
{
if ( V_119 . V_118 ) {
F_444 () ;
F_435 () ;
}
}
static int F_437 ( struct V_454 * V_455 )
{
return 0 ;
}
static void F_440 ( struct V_454 * V_455 )
{
}
static void F_447 ( void )
{
}
static void F_448 ( struct V_7 * V_462 )
{
if ( F_2 ( V_1 ) )
V_6 -> V_91 = true ;
else
V_6 -> V_91 = false ;
}
static V_126 F_449 ( struct V_7 * V_9 ,
struct V_277 * V_278 )
{
struct V_4 * V_5 = F_70 ( V_9 ) ;
return ( V_126 ) F_33 ( & V_5 -> V_39 ) * V_229 ;
}
static int F_450 ( struct V_308 * V_309 , void * V_310 )
{
struct V_4 * V_5 = F_70 ( F_278 ( V_309 ) ) ;
unsigned long V_417 = F_14 ( V_5 -> V_417 ) ;
if ( V_417 == V_318 )
F_451 ( V_309 , L_35 ) ;
else
F_279 ( V_309 , L_36 , ( V_126 ) V_417 * V_229 ) ;
return 0 ;
}
static T_7 F_452 ( struct V_272 * V_273 ,
char * V_274 , T_8 V_275 , T_9 V_276 )
{
struct V_4 * V_5 = F_70 ( F_247 ( V_273 ) ) ;
unsigned long V_417 ;
int V_236 ;
V_274 = F_270 ( V_274 ) ;
V_236 = F_271 ( V_274 , L_37 , & V_417 ) ;
if ( V_236 )
return V_236 ;
V_5 -> V_417 = V_417 ;
return V_275 ;
}
static int F_453 ( struct V_308 * V_309 , void * V_310 )
{
struct V_4 * V_5 = F_70 ( F_278 ( V_309 ) ) ;
unsigned long V_205 = F_14 ( V_5 -> V_205 ) ;
if ( V_205 == V_318 )
F_451 ( V_309 , L_35 ) ;
else
F_279 ( V_309 , L_36 , ( V_126 ) V_205 * V_229 ) ;
return 0 ;
}
static T_7 F_454 ( struct V_272 * V_273 ,
char * V_274 , T_8 V_275 , T_9 V_276 )
{
struct V_4 * V_5 = F_70 ( F_247 ( V_273 ) ) ;
unsigned long V_38 ;
unsigned long V_205 ;
int V_236 ;
V_274 = F_270 ( V_274 ) ;
V_236 = F_271 ( V_274 , L_37 , & V_205 ) ;
if ( V_236 )
return V_236 ;
V_5 -> V_205 = V_205 ;
V_38 = F_33 ( & V_5 -> V_39 ) ;
if ( V_38 > V_205 )
F_171 ( V_5 , V_38 - V_205 ,
V_208 , true ) ;
F_313 ( V_5 ) ;
return V_275 ;
}
static int F_455 ( struct V_308 * V_309 , void * V_310 )
{
struct V_4 * V_5 = F_70 ( F_278 ( V_309 ) ) ;
unsigned long F_176 = F_14 ( V_5 -> V_39 . V_115 ) ;
if ( F_176 == V_318 )
F_451 ( V_309 , L_35 ) ;
else
F_279 ( V_309 , L_36 , ( V_126 ) F_176 * V_229 ) ;
return 0 ;
}
static T_7 F_456 ( struct V_272 * V_273 ,
char * V_274 , T_8 V_275 , T_9 V_276 )
{
struct V_4 * V_5 = F_70 ( F_247 ( V_273 ) ) ;
unsigned int V_463 = V_212 ;
bool V_218 = false ;
unsigned long F_176 ;
int V_236 ;
V_274 = F_270 ( V_274 ) ;
V_236 = F_271 ( V_274 , L_37 , & F_176 ) ;
if ( V_236 )
return V_236 ;
F_457 ( & V_5 -> V_39 . V_115 , F_176 ) ;
for (; ; ) {
unsigned long V_38 = F_33 ( & V_5 -> V_39 ) ;
if ( V_38 <= F_176 )
break;
if ( F_236 ( V_122 ) ) {
V_236 = - V_264 ;
break;
}
if ( ! V_218 ) {
F_161 ( V_5 ) ;
V_218 = true ;
continue;
}
if ( V_463 ) {
if ( ! F_171 ( V_5 , V_38 - F_176 ,
V_208 , true ) )
V_463 -- ;
continue;
}
F_170 ( V_5 , V_228 ) ;
if ( ! F_118 ( V_5 , V_208 , 0 ) )
break;
}
F_313 ( V_5 ) ;
return V_275 ;
}
static int F_458 ( struct V_308 * V_309 , void * V_310 )
{
struct V_4 * V_5 = F_70 ( F_278 ( V_309 ) ) ;
F_279 ( V_309 , L_38 , F_43 ( V_5 , V_464 ) ) ;
F_279 ( V_309 , L_39 , F_43 ( V_5 , V_206 ) ) ;
F_279 ( V_309 , L_40 , F_43 ( V_5 , V_224 ) ) ;
F_279 ( V_309 , L_41 , F_43 ( V_5 , V_228 ) ) ;
F_279 ( V_309 , L_30 , F_43 ( V_5 , V_354 ) ) ;
return 0 ;
}
static int F_459 ( struct V_308 * V_309 , void * V_310 )
{
struct V_4 * V_5 = F_70 ( F_278 ( V_309 ) ) ;
unsigned long V_47 [ V_282 ] ;
unsigned long V_48 [ V_283 ] ;
int V_100 ;
F_250 ( V_5 , V_47 ) ;
F_251 ( V_5 , V_48 ) ;
F_279 ( V_309 , L_42 ,
( V_126 ) V_47 [ V_51 ] * V_229 ) ;
F_279 ( V_309 , L_43 ,
( V_126 ) V_47 [ V_52 ] * V_229 ) ;
F_279 ( V_309 , L_44 ,
( V_126 ) V_47 [ V_465 ] * 1024 ) ;
F_279 ( V_309 , L_45 ,
( V_126 ) ( V_47 [ V_466 ] +
V_47 [ V_467 ] ) * V_229 ) ;
F_279 ( V_309 , L_46 ,
( V_126 ) V_47 [ V_468 ] * V_229 ) ;
F_279 ( V_309 , L_47 ,
( V_126 ) V_47 [ V_53 ] * V_229 ) ;
F_279 ( V_309 , L_48 ,
( V_126 ) V_47 [ V_434 ] * V_229 ) ;
F_279 ( V_309 , L_49 ,
( V_126 ) V_47 [ V_366 ] * V_229 ) ;
F_279 ( V_309 , L_50 ,
( V_126 ) V_47 [ V_367 ] * V_229 ) ;
for ( V_100 = 0 ; V_100 < V_132 ; V_100 ++ ) {
struct V_4 * V_315 ;
unsigned long V_45 = 0 ;
F_85 (mi, memcg)
V_45 += F_60 ( V_315 , F_58 ( V_100 ) ) ;
F_279 ( V_309 , L_51 ,
V_133 [ V_100 ] , ( V_126 ) V_45 * V_229 ) ;
}
F_279 ( V_309 , L_52 ,
( V_126 ) V_47 [ V_466 ] * V_229 ) ;
F_279 ( V_309 , L_53 ,
( V_126 ) V_47 [ V_467 ] * V_229 ) ;
F_279 ( V_309 , L_54 , V_48 [ V_469 ] ) ;
F_279 ( V_309 , L_55 , V_48 [ V_470 ] ) ;
F_279 ( V_309 , L_56 , V_48 [ V_471 ] ) ;
F_279 ( V_309 , L_57 , V_48 [ V_472 ] +
V_48 [ V_473 ] ) ;
F_279 ( V_309 , L_58 , V_48 [ V_474 ] +
V_48 [ V_475 ] ) ;
F_279 ( V_309 , L_59 , V_48 [ V_476 ] ) ;
F_279 ( V_309 , L_60 , V_48 [ V_477 ] ) ;
F_279 ( V_309 , L_61 , V_48 [ V_478 ] ) ;
F_279 ( V_309 , L_62 , V_48 [ V_479 ] ) ;
F_279 ( V_309 , L_63 ,
V_47 [ V_480 ] ) ;
F_279 ( V_309 , L_64 ,
V_47 [ V_481 ] ) ;
F_279 ( V_309 , L_65 ,
V_47 [ V_482 ] ) ;
return 0 ;
}
bool F_460 ( struct V_4 * V_83 , struct V_4 * V_5 )
{
if ( F_75 () )
return false ;
if ( ! V_83 )
V_83 = V_6 ;
if ( V_5 == V_83 )
return false ;
for (; V_5 != V_83 ; V_5 = F_15 ( V_5 ) ) {
if ( F_33 ( & V_5 -> V_39 ) >= V_5 -> V_417 )
return false ;
}
return true ;
}
int F_461 ( struct V_11 * V_11 , struct V_80 * V_81 ,
T_3 V_139 , struct V_4 * * V_483 ,
bool V_49 )
{
struct V_4 * V_5 = NULL ;
unsigned int V_38 = V_49 ? F_400 ( V_11 ) : 1 ;
int V_103 = 0 ;
if ( F_75 () )
goto V_92;
if ( F_462 ( V_11 ) ) {
F_50 ( ! F_463 ( V_11 ) , V_11 ) ;
if ( F_464 ( V_11 ) -> V_4 )
goto V_92;
if ( V_2 ) {
T_6 V_426 = { . V_45 = F_465 ( V_11 ) , } ;
unsigned short V_235 = F_417 ( V_426 ) ;
F_13 () ;
V_5 = F_345 ( V_235 ) ;
if ( V_5 && ! F_39 ( & V_5 -> V_9 ) )
V_5 = NULL ;
F_17 () ;
}
}
if ( ! V_5 )
V_5 = F_72 ( V_81 ) ;
V_103 = F_175 ( V_5 , V_139 , V_38 ) ;
F_79 ( & V_5 -> V_9 ) ;
V_92:
* V_483 = V_5 ;
return V_103 ;
}
void F_466 ( struct V_11 * V_11 , struct V_4 * V_5 ,
bool V_234 , bool V_49 )
{
unsigned int V_38 = V_49 ? F_400 ( V_11 ) : 1 ;
F_50 ( ! V_11 -> V_428 , V_11 ) ;
F_50 ( F_193 ( V_11 ) && ! V_234 , V_11 ) ;
if ( F_75 () )
return;
if ( ! V_5 )
return;
F_200 ( V_11 , V_5 , V_234 ) ;
F_406 () ;
F_46 ( V_5 , V_11 , V_49 , V_38 ) ;
F_65 ( V_5 , V_11 ) ;
F_407 () ;
if ( F_1 () && F_462 ( V_11 ) ) {
T_6 V_185 = { . V_45 = F_465 (page) } ;
F_467 ( V_185 , V_38 ) ;
}
}
void F_468 ( struct V_11 * V_11 , struct V_4 * V_5 ,
bool V_49 )
{
unsigned int V_38 = V_49 ? F_400 ( V_11 ) : 1 ;
if ( F_75 () )
return;
if ( ! V_5 )
return;
F_189 ( V_5 , V_38 ) ;
}
static inline void F_469 ( struct V_484 * V_485 )
{
memset ( V_485 , 0 , sizeof( * V_485 ) ) ;
}
static void F_470 ( const struct V_484 * V_485 )
{
unsigned long V_38 = V_485 -> V_486 + V_485 -> V_487 + V_485 -> V_488 ;
unsigned long V_13 ;
if ( ! F_6 ( V_485 -> V_5 ) ) {
F_156 ( & V_485 -> V_5 -> V_39 , V_38 ) ;
if ( F_1 () )
F_156 ( & V_485 -> V_5 -> V_116 , V_38 ) ;
if ( ! F_2 ( V_1 ) && V_485 -> V_488 )
F_156 ( & V_485 -> V_5 -> V_128 , V_485 -> V_488 ) ;
F_142 ( V_485 -> V_5 ) ;
}
F_152 ( V_13 ) ;
F_229 ( V_485 -> V_5 -> V_47 -> V_50 [ V_51 ] , V_485 -> V_486 ) ;
F_229 ( V_485 -> V_5 -> V_47 -> V_50 [ V_52 ] , V_485 -> V_487 ) ;
F_229 ( V_485 -> V_5 -> V_47 -> V_50 [ V_54 ] , V_485 -> V_489 ) ;
F_229 ( V_485 -> V_5 -> V_47 -> V_50 [ V_53 ] , V_485 -> V_490 ) ;
F_48 ( V_485 -> V_5 -> V_47 -> V_48 [ V_56 ] , V_485 -> V_491 ) ;
F_48 ( V_485 -> V_5 -> V_47 -> V_57 , V_38 ) ;
F_65 ( V_485 -> V_5 , V_485 -> V_492 ) ;
F_154 ( V_13 ) ;
if ( ! F_6 ( V_485 -> V_5 ) )
F_157 ( & V_485 -> V_5 -> V_9 , V_38 ) ;
}
static void F_471 ( struct V_11 * V_11 , struct V_484 * V_485 )
{
F_50 ( F_193 ( V_11 ) , V_11 ) ;
F_50 ( F_472 ( V_11 ) && ! F_473 ( V_11 ) &&
! F_474 ( V_11 ) , V_11 ) ;
if ( ! V_11 -> V_4 )
return;
if ( V_485 -> V_5 != V_11 -> V_4 ) {
if ( V_485 -> V_5 ) {
F_470 ( V_485 ) ;
F_469 ( V_485 ) ;
}
V_485 -> V_5 = V_11 -> V_4 ;
}
if ( ! F_226 ( V_11 ) ) {
unsigned int V_38 = 1 ;
if ( F_51 ( V_11 ) ) {
V_38 <<= F_475 ( V_11 ) ;
V_485 -> V_489 += V_38 ;
}
if ( F_47 ( V_11 ) )
V_485 -> V_486 += V_38 ;
else {
V_485 -> V_487 += V_38 ;
if ( F_49 ( V_11 ) )
V_485 -> V_490 += V_38 ;
}
V_485 -> V_491 ++ ;
} else {
V_485 -> V_488 += 1 << F_475 ( V_11 ) ;
F_227 ( V_11 ) ;
}
V_485 -> V_492 = V_11 ;
V_11 -> V_4 = NULL ;
}
static void F_476 ( struct V_355 * V_493 )
{
struct V_484 V_485 ;
struct V_355 * V_66 ;
F_469 ( & V_485 ) ;
V_66 = V_493 -> V_66 ;
do {
struct V_11 * V_11 ;
V_11 = F_477 ( V_66 , struct V_11 , V_62 ) ;
V_66 = V_11 -> V_62 . V_66 ;
F_471 ( V_11 , & V_485 ) ;
} while ( V_66 != V_493 );
if ( V_485 . V_5 )
F_470 ( & V_485 ) ;
}
void F_478 ( struct V_11 * V_11 )
{
struct V_484 V_485 ;
if ( F_75 () )
return;
if ( ! V_11 -> V_4 )
return;
F_469 ( & V_485 ) ;
F_471 ( V_11 , & V_485 ) ;
F_470 ( & V_485 ) ;
}
void F_479 ( struct V_355 * V_493 )
{
if ( F_75 () )
return;
if ( ! F_321 ( V_493 ) )
F_476 ( V_493 ) ;
}
void F_480 ( struct V_11 * V_494 , struct V_11 * V_495 )
{
struct V_4 * V_5 ;
unsigned int V_38 ;
bool V_49 ;
unsigned long V_13 ;
F_50 ( ! F_463 ( V_494 ) , V_494 ) ;
F_50 ( ! F_463 ( V_495 ) , V_495 ) ;
F_50 ( F_47 ( V_494 ) != F_47 ( V_495 ) , V_495 ) ;
F_50 ( F_51 ( V_494 ) != F_51 ( V_495 ) ,
V_495 ) ;
if ( F_75 () )
return;
if ( V_495 -> V_4 )
return;
V_5 = V_494 -> V_4 ;
if ( ! V_5 )
return;
V_49 = F_51 ( V_495 ) ;
V_38 = V_49 ? F_400 ( V_495 ) : 1 ;
F_184 ( & V_5 -> V_39 , V_38 ) ;
if ( F_1 () )
F_184 ( & V_5 -> V_116 , V_38 ) ;
F_185 ( & V_5 -> V_9 , V_38 ) ;
F_200 ( V_495 , V_5 , false ) ;
F_152 ( V_13 ) ;
F_46 ( V_5 , V_495 , V_49 , V_38 ) ;
F_65 ( V_5 , V_495 ) ;
F_154 ( V_13 ) ;
}
void F_481 ( struct V_496 * V_497 )
{
struct V_4 * V_5 ;
if ( ! V_498 )
return;
F_13 () ;
V_5 = F_69 ( V_122 ) ;
if ( V_5 == V_6 )
goto V_92;
if ( ! F_2 ( V_1 ) && ! V_5 -> V_303 )
goto V_92;
if ( F_39 ( & V_5 -> V_9 ) )
V_497 -> V_499 = V_5 ;
V_92:
F_17 () ;
}
void F_482 ( struct V_496 * V_497 )
{
if ( V_497 -> V_499 )
F_79 ( & V_497 -> V_499 -> V_9 ) ;
}
bool F_483 ( struct V_4 * V_5 , unsigned int V_38 )
{
T_3 V_139 = V_208 ;
if ( ! F_2 ( V_1 ) ) {
struct V_214 * V_410 ;
if ( F_177 ( & V_5 -> V_288 , V_38 , & V_410 ) ) {
V_5 -> V_500 = 0 ;
return true ;
}
F_184 ( & V_5 -> V_288 , V_38 ) ;
V_5 -> V_500 = 1 ;
return false ;
}
if ( F_484 () )
V_139 = V_246 ;
F_231 ( V_5 -> V_47 -> V_50 [ V_468 ] , V_38 ) ;
if ( F_175 ( V_5 , V_139 , V_38 ) == 0 )
return true ;
F_175 ( V_5 , V_139 | V_227 , V_38 ) ;
return false ;
}
void F_485 ( struct V_4 * V_5 , unsigned int V_38 )
{
if ( ! F_2 ( V_1 ) ) {
F_156 ( & V_5 -> V_288 , V_38 ) ;
return;
}
F_486 ( V_5 -> V_47 -> V_50 [ V_468 ] , V_38 ) ;
F_160 ( V_5 , V_38 ) ;
}
static int T_17 F_487 ( char * V_501 )
{
char * V_502 ;
while ( ( V_502 = F_488 ( & V_501 , L_66 ) ) != NULL ) {
if ( ! * V_502 )
continue;
if ( ! strcmp ( V_502 , L_67 ) )
V_416 = true ;
if ( ! strcmp ( V_502 , L_68 ) )
V_296 = true ;
}
return 0 ;
}
static int T_17 F_489 ( void )
{
int V_46 , V_153 ;
#ifndef F_363
V_247 = F_490 ( L_69 , 0 , 1 ) ;
F_84 ( ! V_247 ) ;
#endif
F_491 ( V_503 , L_70 , NULL ,
F_168 ) ;
F_44 (cpu)
F_214 ( & F_492 ( & V_196 , V_46 ) -> V_204 ,
F_158 ) ;
F_36 (node) {
struct V_19 * V_504 ;
V_504 = F_351 ( sizeof( * V_504 ) , V_208 ,
F_493 ( V_153 ) ? V_153 : V_505 ) ;
V_504 -> V_27 = V_506 ;
V_504 -> V_36 = NULL ;
F_361 ( & V_504 -> V_37 ) ;
V_20 . V_21 [ V_153 ] = V_504 ;
}
return 0 ;
}
static struct V_4 * F_494 ( struct V_4 * V_5 )
{
while ( ! F_495 ( & V_5 -> V_235 . V_404 ) ) {
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
void F_496 ( struct V_11 * V_11 , T_6 V_185 )
{
struct V_4 * V_5 , * V_507 ;
unsigned int V_256 ;
unsigned short V_508 ;
F_50 ( F_193 ( V_11 ) , V_11 ) ;
F_50 ( F_472 ( V_11 ) , V_11 ) ;
if ( ! F_1 () )
return;
V_5 = V_11 -> V_4 ;
if ( ! V_5 )
return;
V_507 = F_494 ( V_5 ) ;
V_256 = F_400 ( V_11 ) ;
if ( V_256 > 1 )
F_338 ( V_507 , V_256 - 1 ) ;
V_508 = F_497 ( V_185 , F_233 ( V_507 ) ,
V_256 ) ;
F_50 ( V_508 , V_11 ) ;
F_230 ( V_507 , V_256 ) ;
V_11 -> V_4 = NULL ;
if ( ! F_6 ( V_5 ) )
F_156 ( & V_5 -> V_39 , V_256 ) ;
if ( V_5 != V_507 ) {
if ( ! F_6 ( V_507 ) )
F_184 ( & V_507 -> V_116 , V_256 ) ;
F_156 ( & V_5 -> V_116 , V_256 ) ;
}
F_56 ( ! F_498 () ) ;
F_46 ( V_5 , V_11 , F_51 ( V_11 ) ,
- V_256 ) ;
F_65 ( V_5 , V_11 ) ;
if ( ! F_6 ( V_5 ) )
F_79 ( & V_5 -> V_9 ) ;
}
int F_499 ( struct V_11 * V_11 , T_6 V_185 )
{
unsigned int V_38 = F_400 ( V_11 ) ;
struct V_214 * V_215 ;
struct V_4 * V_5 ;
unsigned short V_508 ;
if ( ! F_2 ( V_1 ) || ! V_2 )
return 0 ;
V_5 = V_11 -> V_4 ;
if ( ! V_5 )
return 0 ;
V_5 = F_494 ( V_5 ) ;
if ( ! F_6 ( V_5 ) &&
! F_177 ( & V_5 -> V_137 , V_38 , & V_215 ) ) {
F_344 ( V_5 ) ;
return - V_230 ;
}
if ( V_38 > 1 )
F_338 ( V_5 , V_38 - 1 ) ;
V_508 = F_497 ( V_185 , F_233 ( V_5 ) , V_38 ) ;
F_50 ( V_508 , V_11 ) ;
F_230 ( V_5 , V_38 ) ;
return 0 ;
}
void F_467 ( T_6 V_185 , unsigned int V_38 )
{
struct V_4 * V_5 ;
unsigned short V_235 ;
if ( ! V_2 )
return;
V_235 = F_497 ( V_185 , 0 , V_38 ) ;
F_13 () ;
V_5 = F_345 ( V_235 ) ;
if ( V_5 ) {
if ( ! F_6 ( V_5 ) ) {
if ( F_2 ( V_1 ) )
F_156 ( & V_5 -> V_137 , V_38 ) ;
else
F_156 ( & V_5 -> V_116 , V_38 ) ;
}
F_230 ( V_5 , - V_38 ) ;
F_340 ( V_5 , V_38 ) ;
}
F_17 () ;
}
long F_500 ( struct V_4 * V_5 )
{
long V_509 = F_501 () ;
if ( ! V_2 || ! F_2 ( V_1 ) )
return V_509 ;
for (; V_5 != V_6 ; V_5 = F_15 ( V_5 ) )
V_509 = F_502 ( long , V_509 ,
F_14 ( V_5 -> V_137 . V_115 ) -
F_33 ( & V_5 -> V_137 ) ) ;
return V_509 ;
}
bool F_503 ( struct V_11 * V_11 )
{
struct V_4 * V_5 ;
F_50 ( ! F_463 ( V_11 ) , V_11 ) ;
if ( F_504 () )
return true ;
if ( ! V_2 || ! F_2 ( V_1 ) )
return false ;
V_5 = V_11 -> V_4 ;
if ( ! V_5 )
return false ;
for (; V_5 != V_6 ; V_5 = F_15 ( V_5 ) )
if ( F_33 ( & V_5 -> V_137 ) * 2 >= V_5 -> V_137 . V_115 )
return true ;
return false ;
}
static int T_17 F_505 ( char * V_501 )
{
if ( ! strcmp ( V_501 , L_71 ) )
V_510 = 1 ;
else if ( ! strcmp ( V_501 , L_72 ) )
V_510 = 0 ;
return 1 ;
}
static V_126 F_506 ( struct V_7 * V_9 ,
struct V_277 * V_278 )
{
struct V_4 * V_5 = F_70 ( V_9 ) ;
return ( V_126 ) F_33 ( & V_5 -> V_137 ) * V_229 ;
}
static int F_507 ( struct V_308 * V_309 , void * V_310 )
{
struct V_4 * V_5 = F_70 ( F_278 ( V_309 ) ) ;
unsigned long F_176 = F_14 ( V_5 -> V_137 . V_115 ) ;
if ( F_176 == V_318 )
F_451 ( V_309 , L_35 ) ;
else
F_279 ( V_309 , L_36 , ( V_126 ) F_176 * V_229 ) ;
return 0 ;
}
static T_7 F_508 ( struct V_272 * V_273 ,
char * V_274 , T_8 V_275 , T_9 V_276 )
{
struct V_4 * V_5 = F_70 ( F_247 ( V_273 ) ) ;
unsigned long F_176 ;
int V_236 ;
V_274 = F_270 ( V_274 ) ;
V_236 = F_271 ( V_274 , L_37 , & F_176 ) ;
if ( V_236 )
return V_236 ;
F_119 ( & V_265 ) ;
V_236 = F_237 ( & V_5 -> V_137 , F_176 ) ;
F_121 ( & V_265 ) ;
if ( V_236 )
return V_236 ;
return V_275 ;
}
static int T_17 F_509 ( void )
{
if ( ! F_75 () && V_510 ) {
V_2 = 1 ;
F_266 ( F_510 ( & V_1 ,
V_511 ) ) ;
F_266 ( F_511 ( & V_1 ,
V_512 ) ) ;
}
return 0 ;
}
