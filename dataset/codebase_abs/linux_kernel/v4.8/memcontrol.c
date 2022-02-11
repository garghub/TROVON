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
struct V_102 * F_79 ( struct V_11 * V_11 , struct V_103 * V_93 )
{
struct V_16 * V_22 ;
struct V_4 * V_5 ;
struct V_102 * V_102 ;
if ( F_72 () ) {
V_102 = & V_93 -> V_102 ;
goto V_92;
}
V_5 = V_11 -> V_4 ;
if ( ! V_5 )
V_5 = V_6 ;
V_22 = F_18 ( V_5 , V_11 ) ;
V_102 = & V_22 -> V_102 ;
V_92:
if ( F_63 ( V_102 -> V_93 != V_93 ) )
V_102 -> V_93 = V_93 ;
return V_102 ;
}
void F_80 ( struct V_102 * V_102 , enum V_60 V_61 ,
int V_36 )
{
struct V_16 * V_22 ;
unsigned long * V_63 ;
long V_104 ;
bool V_105 ;
if ( F_72 () )
return;
V_22 = F_5 ( V_102 , struct V_16 , V_102 ) ;
V_63 = V_22 -> V_63 + V_61 ;
V_105 = F_81 ( V_102 -> V_106 + V_61 ) ;
if ( V_36 < 0 )
* V_63 += V_36 ;
V_104 = * V_63 ;
if ( F_82 ( V_104 < 0 || V_105 != ! V_104 ,
L_1 ,
V_107 , V_102 , V_61 , V_36 , V_104 , V_105 ? L_2 : L_3 ) ) {
F_54 ( 1 ) ;
* V_63 = 0 ;
}
if ( V_36 > 0 )
* V_63 += V_36 ;
}
bool F_83 ( struct V_78 * V_108 , struct V_4 * V_5 )
{
struct V_4 * V_109 ;
struct V_78 * V_26 ;
bool V_110 ;
V_26 = F_84 ( V_108 ) ;
if ( V_26 ) {
V_109 = F_69 ( V_26 -> V_81 ) ;
F_85 ( V_26 ) ;
} else {
F_13 () ;
V_109 = F_66 ( V_108 ) ;
F_86 ( & V_109 -> V_9 ) ;
F_17 () ;
}
V_110 = F_87 ( V_109 , V_5 ) ;
F_76 ( & V_109 -> V_9 ) ;
return V_110 ;
}
static unsigned long F_88 ( struct V_4 * V_5 )
{
unsigned long V_111 = 0 ;
unsigned long V_48 ;
unsigned long V_112 ;
V_48 = F_32 ( & V_5 -> V_37 ) ;
V_112 = F_14 ( V_5 -> V_37 . V_112 ) ;
if ( V_48 < V_112 )
V_111 = V_112 - V_48 ;
if ( F_1 () ) {
V_48 = F_32 ( & V_5 -> V_113 ) ;
V_112 = F_14 ( V_5 -> V_113 . V_112 ) ;
if ( V_48 <= V_112 )
V_111 = F_89 ( V_111 , V_112 - V_48 ) ;
else
V_111 = 0 ;
}
return V_111 ;
}
static bool F_90 ( struct V_4 * V_5 )
{
struct V_4 * V_114 ;
struct V_4 * V_115 ;
bool V_110 = false ;
F_91 ( & V_116 . V_35 ) ;
V_114 = V_116 . V_114 ;
V_115 = V_116 . V_115 ;
if ( ! V_114 )
goto V_117;
V_110 = F_87 ( V_114 , V_5 ) ||
F_87 ( V_115 , V_5 ) ;
V_117:
F_92 ( & V_116 . V_35 ) ;
return V_110 ;
}
static bool F_93 ( struct V_4 * V_5 )
{
if ( V_116 . V_118 && V_119 != V_116 . V_118 ) {
if ( F_90 ( V_5 ) ) {
F_94 ( V_120 ) ;
F_95 ( & V_116 . V_121 , & V_120 , V_122 ) ;
if ( V_116 . V_118 )
F_96 () ;
F_97 ( & V_116 . V_121 , & V_120 ) ;
return true ;
}
}
return false ;
}
void F_98 ( struct V_4 * V_5 , struct V_78 * V_26 )
{
struct V_4 * V_89 ;
unsigned int V_100 ;
F_13 () ;
if ( V_26 ) {
F_99 ( L_4 ) ;
F_100 ( F_101 ( V_26 , V_79 ) ) ;
F_102 ( L_5 ) ;
} else {
F_99 ( L_6 ) ;
}
F_100 ( V_5 -> V_9 . V_15 ) ;
F_102 ( L_7 ) ;
F_17 () ;
F_99 ( L_8 ,
F_103 ( ( V_123 ) F_32 ( & V_5 -> V_37 ) ) ,
F_103 ( ( V_123 ) V_5 -> V_37 . V_112 ) , V_5 -> V_37 . V_124 ) ;
F_99 ( L_9 ,
F_103 ( ( V_123 ) F_32 ( & V_5 -> V_113 ) ) ,
F_103 ( ( V_123 ) V_5 -> V_113 . V_112 ) , V_5 -> V_113 . V_124 ) ;
F_99 ( L_10 ,
F_103 ( ( V_123 ) F_32 ( & V_5 -> V_125 ) ) ,
F_103 ( ( V_123 ) V_5 -> V_125 . V_112 ) , V_5 -> V_125 . V_124 ) ;
F_104 (iter, memcg) {
F_99 ( L_11 ) ;
F_100 ( V_89 -> V_9 . V_15 ) ;
F_102 ( L_12 ) ;
for ( V_100 = 0 ; V_100 < V_126 ; V_100 ++ ) {
if ( V_100 == V_127 && ! V_2 )
continue;
F_102 ( L_13 , V_128 [ V_100 ] ,
F_103 ( F_43 ( V_89 , V_100 ) ) ) ;
}
for ( V_100 = 0 ; V_100 < V_129 ; V_100 ++ )
F_102 ( L_13 , V_130 [ V_100 ] ,
F_103 ( F_57 ( V_89 , F_56 ( V_100 ) ) ) ) ;
F_102 ( L_7 ) ;
}
}
static int F_105 ( struct V_4 * V_5 )
{
int V_131 = 0 ;
struct V_4 * V_89 ;
F_104 (iter, memcg)
V_131 ++ ;
return V_131 ;
}
static unsigned long F_106 ( struct V_4 * V_5 )
{
unsigned long V_112 ;
V_112 = V_5 -> V_37 . V_112 ;
if ( F_107 ( V_5 ) ) {
unsigned long V_132 ;
unsigned long V_133 ;
V_132 = V_5 -> V_113 . V_112 ;
V_133 = V_5 -> V_134 . V_112 ;
V_133 = F_89 ( V_133 , ( unsigned long ) V_135 ) ;
V_112 = F_89 ( V_112 + V_133 , V_132 ) ;
}
return V_112 ;
}
static bool F_108 ( struct V_4 * V_5 , T_3 V_136 ,
int V_137 )
{
struct V_138 V_139 = {
. V_140 = NULL ,
. V_141 = NULL ,
. V_5 = V_5 ,
. V_136 = V_136 ,
. V_137 = V_137 ,
} ;
struct V_4 * V_89 ;
unsigned long V_142 = 0 ;
unsigned long V_143 ;
unsigned int V_144 = 0 ;
struct V_78 * V_145 = NULL ;
F_109 ( & V_146 ) ;
if ( F_110 ( V_119 ) ) {
F_111 ( V_119 ) ;
F_112 ( V_119 ) ;
goto V_117;
}
F_113 ( & V_139 , V_147 ) ;
V_143 = F_106 ( V_5 ) ? : 1 ;
F_104 (iter, memcg) {
struct V_148 V_149 ;
struct V_78 * V_108 ;
F_114 ( & V_89 -> V_9 , & V_149 ) ;
while ( ( V_108 = F_115 ( & V_149 ) ) ) {
switch ( F_116 ( & V_139 , V_108 ) ) {
case V_150 :
if ( V_145 )
F_117 ( V_145 ) ;
V_145 = V_108 ;
V_142 = V_151 ;
F_118 ( V_145 ) ;
case V_152 :
continue;
case V_153 :
F_119 ( & V_149 ) ;
F_77 ( V_5 , V_89 ) ;
if ( V_145 )
F_117 ( V_145 ) ;
V_145 = ( void * ) 1 ;
goto V_117;
case V_154 :
break;
} ;
V_144 = F_120 ( V_108 , V_5 , NULL , V_143 ) ;
if ( ! V_144 || V_144 < V_142 )
continue;
if ( V_144 == V_142 &&
F_121 ( V_145 ) )
continue;
if ( V_145 )
F_117 ( V_145 ) ;
V_145 = V_108 ;
V_142 = V_144 ;
F_118 ( V_145 ) ;
}
F_119 ( & V_149 ) ;
}
if ( V_145 ) {
V_144 = V_142 * 1000 / V_143 ;
F_122 ( & V_139 , V_145 , V_144 , V_143 ,
L_14 ) ;
}
V_117:
F_123 ( & V_146 ) ;
return V_145 ;
}
static bool F_124 ( struct V_4 * V_5 ,
int V_17 , bool V_155 )
{
if ( F_53 ( V_5 , V_17 , V_156 ) )
return true ;
if ( V_155 || ! V_135 )
return false ;
if ( F_53 ( V_5 , V_17 , V_157 ) )
return true ;
return false ;
}
static void F_125 ( struct V_4 * V_5 )
{
int V_17 ;
if ( ! F_126 ( & V_5 -> V_77 ) )
return;
if ( F_127 ( & V_5 -> V_158 ) > 1 )
return;
V_5 -> V_159 = V_160 [ V_161 ] ;
F_128 (nid, node_states[N_MEMORY]) {
if ( ! F_124 ( V_5 , V_17 , false ) )
F_129 ( V_17 , V_5 -> V_159 ) ;
}
F_130 ( & V_5 -> V_77 , 0 ) ;
F_130 ( & V_5 -> V_158 , 0 ) ;
}
int F_131 ( struct V_4 * V_5 )
{
int V_162 ;
F_125 ( V_5 ) ;
V_162 = V_5 -> V_163 ;
V_162 = F_132 ( V_162 , V_5 -> V_159 ) ;
if ( F_63 ( V_162 == V_76 ) )
V_162 = F_133 () ;
V_5 -> V_163 = V_162 ;
return V_162 ;
}
int F_131 ( struct V_4 * V_5 )
{
return 0 ;
}
static int F_134 ( struct V_4 * V_164 ,
T_4 * V_93 ,
T_3 V_136 ,
unsigned long * V_165 )
{
struct V_4 * V_166 = NULL ;
int V_167 = 0 ;
int V_168 = 0 ;
unsigned long V_39 ;
unsigned long V_169 ;
struct V_85 V_86 = {
. V_93 = V_93 ,
. V_95 = 0 ,
} ;
V_39 = F_31 ( V_164 ) ;
while ( 1 ) {
V_166 = F_71 ( V_164 , V_166 , & V_86 ) ;
if ( ! V_166 ) {
V_168 ++ ;
if ( V_168 >= 2 ) {
if ( ! V_167 )
break;
if ( V_167 >= ( V_39 >> 2 ) ||
( V_168 > V_170 ) )
break;
}
continue;
}
V_167 += F_135 ( V_166 , V_136 , false ,
V_93 , & V_169 ) ;
* V_165 += V_169 ;
if ( ! F_31 ( V_164 ) )
break;
}
F_77 ( V_164 , V_166 ) ;
return V_167 ;
}
static bool F_136 ( struct V_4 * V_5 )
{
struct V_4 * V_89 , * V_171 = NULL ;
F_91 ( & V_172 ) ;
F_104 (iter, memcg) {
if ( V_89 -> V_146 ) {
V_171 = V_89 ;
F_77 ( V_5 , V_89 ) ;
break;
} else
V_89 -> V_146 = true ;
}
if ( V_171 ) {
F_104 (iter, memcg) {
if ( V_89 == V_171 ) {
F_77 ( V_5 , V_89 ) ;
break;
}
V_89 -> V_146 = false ;
}
} else
F_137 ( & V_173 , 0 , 1 , V_174 ) ;
F_92 ( & V_172 ) ;
return ! V_171 ;
}
static void F_138 ( struct V_4 * V_5 )
{
struct V_4 * V_89 ;
F_91 ( & V_172 ) ;
F_139 ( & V_173 , 1 , V_174 ) ;
F_104 (iter, memcg)
V_89 -> V_146 = false ;
F_92 ( & V_172 ) ;
}
static void F_140 ( struct V_4 * V_5 )
{
struct V_4 * V_89 ;
F_91 ( & V_172 ) ;
F_104 (iter, memcg)
V_89 -> V_175 ++ ;
F_92 ( & V_172 ) ;
}
static void F_141 ( struct V_4 * V_5 )
{
struct V_4 * V_89 ;
F_91 ( & V_172 ) ;
F_104 (iter, memcg)
if ( V_89 -> V_175 > 0 )
V_89 -> V_175 -- ;
F_92 ( & V_172 ) ;
}
static int F_142 ( T_5 * V_120 ,
unsigned V_176 , int V_177 , void * V_178 )
{
struct V_4 * V_179 = (struct V_4 * ) V_178 ;
struct V_4 * V_180 ;
struct V_181 * V_181 ;
V_181 = F_5 ( V_120 , struct V_181 , V_120 ) ;
V_180 = V_181 -> V_5 ;
if ( ! F_87 ( V_179 , V_180 ) &&
! F_87 ( V_180 , V_179 ) )
return 0 ;
return F_143 ( V_120 , V_176 , V_177 , V_178 ) ;
}
static void F_144 ( struct V_4 * V_5 )
{
if ( V_5 && V_5 -> V_175 )
F_145 ( & V_182 , V_183 , 0 , V_5 ) ;
}
static void F_146 ( struct V_4 * V_5 , T_3 V_184 , int V_137 )
{
if ( ! V_119 -> V_185 )
return;
F_86 ( & V_5 -> V_9 ) ;
V_119 -> V_186 = V_5 ;
V_119 -> V_187 = V_184 ;
V_119 -> V_188 = V_137 ;
}
bool F_147 ( bool V_189 )
{
struct V_4 * V_5 = V_119 -> V_186 ;
struct V_181 V_190 ;
bool V_191 ;
if ( ! V_5 )
return false ;
if ( ! V_189 || V_192 )
goto V_193;
V_190 . V_5 = V_5 ;
V_190 . V_120 . V_13 = 0 ;
V_190 . V_120 . V_194 = F_142 ;
V_190 . V_120 . V_195 = V_119 ;
F_148 ( & V_190 . V_120 . V_196 ) ;
F_95 ( & V_182 , & V_190 . V_120 , V_197 ) ;
F_140 ( V_5 ) ;
V_191 = F_136 ( V_5 ) ;
if ( V_191 )
F_149 ( V_5 ) ;
if ( V_191 && ! V_5 -> V_198 ) {
F_141 ( V_5 ) ;
F_97 ( & V_182 , & V_190 . V_120 ) ;
F_108 ( V_5 , V_119 -> V_187 ,
V_119 -> V_188 ) ;
} else {
F_96 () ;
F_141 ( V_5 ) ;
F_97 ( & V_182 , & V_190 . V_120 ) ;
}
if ( V_191 ) {
F_138 ( V_5 ) ;
F_144 ( V_5 ) ;
}
V_193:
V_119 -> V_186 = NULL ;
F_76 ( & V_5 -> V_9 ) ;
return true ;
}
void F_150 ( struct V_11 * V_11 )
{
struct V_4 * V_5 ;
unsigned long V_13 ;
F_13 () ;
if ( F_72 () )
return;
V_199:
V_5 = V_11 -> V_4 ;
if ( F_63 ( ! V_5 ) )
return;
if ( F_126 ( & V_5 -> V_200 ) <= 0 )
return;
F_29 ( & V_5 -> V_201 , V_13 ) ;
if ( V_5 != V_11 -> V_4 ) {
F_30 ( & V_5 -> V_201 , V_13 ) ;
goto V_199;
}
V_5 -> V_202 = V_119 ;
V_5 -> V_203 = V_13 ;
return;
}
void F_151 ( struct V_11 * V_11 )
{
struct V_4 * V_5 = V_11 -> V_4 ;
if ( V_5 && V_5 -> V_202 == V_119 ) {
unsigned long V_13 = V_5 -> V_203 ;
V_5 -> V_202 = NULL ;
V_5 -> V_203 = 0 ;
F_30 ( & V_5 -> V_201 , V_13 ) ;
}
F_17 () ;
}
static bool F_152 ( struct V_4 * V_5 , unsigned int V_36 )
{
struct V_204 * V_205 ;
unsigned long V_13 ;
bool V_110 = false ;
if ( V_36 > V_206 )
return V_110 ;
F_153 ( V_13 ) ;
V_205 = F_154 ( & V_207 ) ;
if ( V_5 == V_205 -> V_208 && V_205 -> V_36 >= V_36 ) {
V_205 -> V_36 -= V_36 ;
V_110 = true ;
}
F_155 ( V_13 ) ;
return V_110 ;
}
static void F_156 ( struct V_204 * V_205 )
{
struct V_4 * V_209 = V_205 -> V_208 ;
if ( V_205 -> V_36 ) {
F_157 ( & V_209 -> V_37 , V_205 -> V_36 ) ;
if ( F_1 () )
F_157 ( & V_209 -> V_113 , V_205 -> V_36 ) ;
F_158 ( & V_209 -> V_9 , V_205 -> V_36 ) ;
V_205 -> V_36 = 0 ;
}
V_205 -> V_208 = NULL ;
}
static void F_159 ( struct V_210 * V_211 )
{
struct V_204 * V_205 ;
unsigned long V_13 ;
F_153 ( V_13 ) ;
V_205 = F_154 ( & V_207 ) ;
F_156 ( V_205 ) ;
F_160 ( V_212 , & V_205 -> V_13 ) ;
F_155 ( V_13 ) ;
}
static void F_161 ( struct V_4 * V_5 , unsigned int V_36 )
{
struct V_204 * V_205 ;
unsigned long V_13 ;
F_153 ( V_13 ) ;
V_205 = F_154 ( & V_207 ) ;
if ( V_205 -> V_208 != V_5 ) {
F_156 ( V_205 ) ;
V_205 -> V_208 = V_5 ;
}
V_205 -> V_36 += V_36 ;
F_155 ( V_13 ) ;
}
static void F_162 ( struct V_4 * V_164 )
{
int V_46 , V_213 ;
if ( ! F_163 ( & V_214 ) )
return;
F_164 () ;
V_213 = F_165 () ;
F_166 (cpu) {
struct V_204 * V_205 = & F_45 ( V_207 , V_46 ) ;
struct V_4 * V_5 ;
V_5 = V_205 -> V_208 ;
if ( ! V_5 || ! V_205 -> V_36 )
continue;
if ( ! F_87 ( V_5 , V_164 ) )
continue;
if ( ! F_167 ( V_212 , & V_205 -> V_13 ) ) {
if ( V_46 == V_213 )
F_159 ( & V_205 -> V_215 ) ;
else
F_168 ( V_46 , & V_205 -> V_215 ) ;
}
}
F_169 () ;
F_170 () ;
F_123 ( & V_214 ) ;
}
static int F_171 ( struct V_216 * V_217 ,
unsigned long V_218 ,
void * V_219 )
{
int V_46 = ( unsigned long ) V_219 ;
struct V_204 * V_205 ;
if ( V_218 == V_220 )
return V_221 ;
if ( V_218 != V_222 && V_218 != V_223 )
return V_221 ;
V_205 = & F_45 ( V_207 , V_46 ) ;
F_156 ( V_205 ) ;
return V_221 ;
}
static void F_172 ( struct V_4 * V_5 ,
unsigned int V_36 ,
T_3 V_136 )
{
do {
if ( F_32 ( & V_5 -> V_37 ) <= V_5 -> V_224 )
continue;
F_173 ( V_5 , V_225 , 1 ) ;
F_174 ( V_5 , V_36 , V_136 , true ) ;
} while ( ( V_5 = F_15 ( V_5 ) ) );
}
static void F_175 ( struct V_210 * V_215 )
{
struct V_4 * V_5 ;
V_5 = F_5 ( V_215 , struct V_4 , V_226 ) ;
F_172 ( V_5 , V_206 , V_227 ) ;
}
void F_176 ( void )
{
unsigned int V_36 = V_119 -> V_228 ;
struct V_4 * V_5 ;
if ( F_177 ( ! V_36 ) )
return;
V_5 = F_69 ( V_119 -> V_81 ) ;
F_172 ( V_5 , V_36 , V_227 ) ;
F_76 ( & V_5 -> V_9 ) ;
V_119 -> V_228 = 0 ;
}
static int F_178 ( struct V_4 * V_5 , T_3 V_136 ,
unsigned int V_36 )
{
unsigned int V_229 = F_179 ( V_206 , V_36 ) ;
int V_230 = V_231 ;
struct V_4 * V_232 ;
struct V_233 * V_234 ;
unsigned long V_235 ;
bool V_236 = true ;
bool V_237 = false ;
if ( F_6 ( V_5 ) )
return 0 ;
V_41:
if ( F_152 ( V_5 , V_36 ) )
return 0 ;
if ( ! F_1 () ||
F_180 ( & V_5 -> V_113 , V_229 , & V_234 ) ) {
if ( F_180 ( & V_5 -> V_37 , V_229 , & V_234 ) )
goto V_238;
if ( F_1 () )
F_157 ( & V_5 -> V_113 , V_229 ) ;
V_232 = F_181 ( V_234 , V_37 ) ;
} else {
V_232 = F_181 ( V_234 , V_113 ) ;
V_236 = false ;
}
if ( V_229 > V_36 ) {
V_229 = V_36 ;
goto V_41;
}
if ( F_63 ( F_182 ( V_239 ) ||
F_183 ( V_119 ) ||
V_119 -> V_13 & V_240 ) )
goto V_241;
if ( F_63 ( F_184 ( V_119 ) ) )
goto V_242;
if ( ! F_185 ( V_136 ) )
goto V_242;
F_173 ( V_232 , V_243 , 1 ) ;
V_235 = F_174 ( V_232 , V_36 ,
V_136 , V_236 ) ;
if ( F_88 ( V_232 ) >= V_36 )
goto V_41;
if ( ! V_237 ) {
F_162 ( V_232 ) ;
V_237 = true ;
goto V_41;
}
if ( V_136 & V_244 )
goto V_242;
if ( V_235 && V_36 <= ( 1 << V_245 ) )
goto V_41;
if ( F_93 ( V_232 ) )
goto V_41;
if ( V_230 -- )
goto V_41;
if ( V_136 & V_246 )
goto V_241;
if ( F_183 ( V_119 ) )
goto V_241;
F_173 ( V_232 , V_247 , 1 ) ;
F_146 ( V_232 , V_136 ,
F_186 ( V_36 * V_248 ) ) ;
V_242:
if ( ! ( V_136 & V_246 ) )
return - V_249 ;
V_241:
F_187 ( & V_5 -> V_37 , V_36 ) ;
if ( F_1 () )
F_187 ( & V_5 -> V_113 , V_36 ) ;
F_188 ( & V_5 -> V_9 , V_36 ) ;
return 0 ;
V_238:
F_188 ( & V_5 -> V_9 , V_229 ) ;
if ( V_229 > V_36 )
F_161 ( V_5 , V_229 - V_36 ) ;
do {
if ( F_32 ( & V_5 -> V_37 ) > V_5 -> V_224 ) {
if ( F_189 () ) {
F_190 ( & V_5 -> V_226 ) ;
break;
}
V_119 -> V_228 += V_229 ;
F_191 ( V_119 ) ;
break;
}
} while ( ( V_5 = F_15 ( V_5 ) ) );
return 0 ;
}
static void F_192 ( struct V_4 * V_5 , unsigned int V_36 )
{
if ( F_6 ( V_5 ) )
return;
F_157 ( & V_5 -> V_37 , V_36 ) ;
if ( F_1 () )
F_157 ( & V_5 -> V_113 , V_36 ) ;
F_158 ( & V_5 -> V_9 , V_36 ) ;
}
static void F_193 ( struct V_11 * V_11 , int * V_250 )
{
struct V_251 * V_251 = F_194 ( V_11 ) ;
F_41 ( F_195 ( V_251 ) ) ;
if ( F_196 ( V_11 ) ) {
struct V_102 * V_102 ;
V_102 = F_79 ( V_11 , V_251 -> V_252 ) ;
F_197 ( V_11 ) ;
F_198 ( V_11 , V_102 , F_199 ( V_11 ) ) ;
* V_250 = 1 ;
} else
* V_250 = 0 ;
}
static void F_200 ( struct V_11 * V_11 , int V_250 )
{
struct V_251 * V_251 = F_194 ( V_11 ) ;
if ( V_250 ) {
struct V_102 * V_102 ;
V_102 = F_79 ( V_11 , V_251 -> V_252 ) ;
F_50 ( F_196 ( V_11 ) , V_11 ) ;
F_201 ( V_11 ) ;
F_202 ( V_11 , V_102 , F_199 ( V_11 ) ) ;
}
F_42 ( F_195 ( V_251 ) ) ;
}
static void F_203 ( struct V_11 * V_11 , struct V_4 * V_5 ,
bool V_253 )
{
int V_250 ;
F_50 ( V_11 -> V_4 , V_11 ) ;
if ( V_253 )
F_193 ( V_11 , & V_250 ) ;
V_11 -> V_4 = V_5 ;
if ( V_253 )
F_200 ( V_11 , V_250 ) ;
}
static int F_204 ( void )
{
int V_254 , V_104 ;
int V_255 ;
V_254 = F_205 ( & V_256 ,
0 , V_257 , V_227 ) ;
if ( V_254 < 0 )
return V_254 ;
if ( V_254 < V_258 )
return V_254 ;
F_206 ( & V_10 ) ;
V_104 = 2 * ( V_254 + 1 ) ;
if ( V_104 < V_259 )
V_104 = V_259 ;
else if ( V_104 > V_257 )
V_104 = V_257 ;
V_255 = F_207 ( V_104 ) ;
if ( ! V_255 )
V_255 = F_208 ( V_104 ) ;
if ( ! V_255 )
V_258 = V_104 ;
F_209 ( & V_10 ) ;
if ( V_255 ) {
F_210 ( & V_256 , V_254 ) ;
return V_255 ;
}
return V_254 ;
}
static void F_211 ( int V_254 )
{
F_210 ( & V_256 , V_254 ) ;
}
static void F_212 ( struct V_210 * V_260 )
{
struct V_261 * V_262 =
F_5 ( V_260 , struct V_261 , V_215 ) ;
struct V_4 * V_5 = V_262 -> V_5 ;
struct V_263 * V_264 = V_262 -> V_264 ;
F_213 ( V_5 , V_264 ) ;
F_76 ( & V_5 -> V_9 ) ;
F_214 ( V_262 ) ;
}
static void F_215 ( struct V_4 * V_5 ,
struct V_263 * V_264 )
{
struct V_261 * V_262 ;
V_262 = F_216 ( sizeof( * V_262 ) , V_265 ) ;
if ( ! V_262 )
return;
F_86 ( & V_5 -> V_9 ) ;
V_262 -> V_5 = V_5 ;
V_262 -> V_264 = V_264 ;
F_217 ( & V_262 -> V_215 , F_212 ) ;
F_190 ( & V_262 -> V_215 ) ;
}
static void F_218 ( struct V_4 * V_5 ,
struct V_263 * V_264 )
{
V_119 -> V_266 = 1 ;
F_215 ( V_5 , V_264 ) ;
V_119 -> V_266 = 0 ;
}
static inline bool F_219 ( void )
{
if ( F_189 () || ! V_119 -> V_81 || ( V_119 -> V_13 & V_267 ) )
return true ;
return false ;
}
struct V_263 * F_220 ( struct V_263 * V_264 )
{
struct V_4 * V_5 ;
struct V_263 * V_268 ;
int V_269 ;
F_54 ( ! F_221 ( V_264 ) ) ;
if ( F_219 () )
return V_264 ;
if ( V_119 -> V_266 )
return V_264 ;
V_5 = F_69 ( V_119 -> V_81 ) ;
V_269 = F_14 ( V_5 -> V_269 ) ;
if ( V_269 < 0 )
goto V_92;
V_268 = F_222 ( V_264 , V_269 ) ;
if ( F_177 ( V_268 ) )
return V_268 ;
F_218 ( V_5 , V_264 ) ;
V_92:
F_76 ( & V_5 -> V_9 ) ;
return V_264 ;
}
void F_223 ( struct V_263 * V_264 )
{
if ( ! F_221 ( V_264 ) )
F_76 ( & V_264 -> V_270 . V_5 -> V_9 ) ;
}
int F_224 ( struct V_11 * V_11 , T_3 V_271 , int V_137 ,
struct V_4 * V_5 )
{
unsigned int V_36 = 1 << V_137 ;
struct V_233 * V_234 ;
int V_110 ;
V_110 = F_178 ( V_5 , V_271 , V_36 ) ;
if ( V_110 )
return V_110 ;
if ( ! F_2 ( V_1 ) &&
! F_180 ( & V_5 -> V_125 , V_36 , & V_234 ) ) {
F_192 ( V_5 , V_36 ) ;
return - V_249 ;
}
V_11 -> V_4 = V_5 ;
return 0 ;
}
int F_225 ( struct V_11 * V_11 , T_3 V_271 , int V_137 )
{
struct V_4 * V_5 ;
int V_110 = 0 ;
if ( F_219 () )
return 0 ;
V_5 = F_69 ( V_119 -> V_81 ) ;
if ( ! F_6 ( V_5 ) ) {
V_110 = F_224 ( V_11 , V_271 , V_137 , V_5 ) ;
if ( ! V_110 )
F_226 ( V_11 ) ;
}
F_76 ( & V_5 -> V_9 ) ;
return V_110 ;
}
void F_227 ( struct V_11 * V_11 , int V_137 )
{
struct V_4 * V_5 = V_11 -> V_4 ;
unsigned int V_36 = 1 << V_137 ;
if ( ! V_5 )
return;
F_50 ( F_6 ( V_5 ) , V_11 ) ;
if ( ! F_2 ( V_1 ) )
F_157 ( & V_5 -> V_125 , V_36 ) ;
F_157 ( & V_5 -> V_37 , V_36 ) ;
if ( F_1 () )
F_157 ( & V_5 -> V_113 , V_36 ) ;
V_11 -> V_4 = NULL ;
if ( F_228 ( V_11 ) )
F_229 ( V_11 ) ;
F_158 ( & V_5 -> V_9 , V_36 ) ;
}
void F_230 ( struct V_11 * V_272 )
{
int V_100 ;
if ( F_72 () )
return;
for ( V_100 = 1 ; V_100 < V_273 ; V_100 ++ )
V_272 [ V_100 ] . V_4 = V_272 -> V_4 ;
F_231 ( V_272 -> V_4 -> V_47 -> V_48 [ V_54 ] ,
V_273 ) ;
}
static void F_232 ( struct V_4 * V_5 ,
bool V_274 )
{
int V_45 = ( V_274 ) ? 1 : - 1 ;
F_233 ( V_5 -> V_47 -> V_48 [ V_127 ] , V_45 ) ;
}
static int F_234 ( T_6 V_275 ,
struct V_4 * V_114 , struct V_4 * V_115 )
{
unsigned short V_276 , V_277 ;
V_276 = F_235 ( V_114 ) ;
V_277 = F_235 ( V_115 ) ;
if ( F_236 ( V_275 , V_276 , V_277 ) == V_276 ) {
F_232 ( V_114 , false ) ;
F_232 ( V_115 , true ) ;
return 0 ;
}
return - V_278 ;
}
static inline int F_234 ( T_6 V_275 ,
struct V_4 * V_114 , struct V_4 * V_115 )
{
return - V_278 ;
}
static int F_237 ( struct V_4 * V_5 ,
unsigned long V_112 )
{
unsigned long V_279 ;
unsigned long V_280 ;
bool V_281 = false ;
int V_282 ;
int V_110 ;
V_282 = V_231 *
F_105 ( V_5 ) ;
V_280 = F_32 ( & V_5 -> V_37 ) ;
do {
if ( F_238 ( V_119 ) ) {
V_110 = - V_283 ;
break;
}
F_109 ( & V_284 ) ;
if ( V_112 > V_5 -> V_113 . V_112 ) {
F_123 ( & V_284 ) ;
V_110 = - V_278 ;
break;
}
if ( V_112 > V_5 -> V_37 . V_112 )
V_281 = true ;
V_110 = F_239 ( & V_5 -> V_37 , V_112 ) ;
F_123 ( & V_284 ) ;
if ( ! V_110 )
break;
F_174 ( V_5 , 1 , V_227 , true ) ;
V_279 = F_32 ( & V_5 -> V_37 ) ;
if ( V_279 >= V_280 )
V_282 -- ;
else
V_280 = V_279 ;
} while ( V_282 );
if ( ! V_110 && V_281 )
F_144 ( V_5 ) ;
return V_110 ;
}
static int F_240 ( struct V_4 * V_5 ,
unsigned long V_112 )
{
unsigned long V_279 ;
unsigned long V_280 ;
bool V_281 = false ;
int V_282 ;
int V_110 ;
V_282 = V_231 *
F_105 ( V_5 ) ;
V_280 = F_32 ( & V_5 -> V_113 ) ;
do {
if ( F_238 ( V_119 ) ) {
V_110 = - V_283 ;
break;
}
F_109 ( & V_284 ) ;
if ( V_112 < V_5 -> V_37 . V_112 ) {
F_123 ( & V_284 ) ;
V_110 = - V_278 ;
break;
}
if ( V_112 > V_5 -> V_113 . V_112 )
V_281 = true ;
V_110 = F_239 ( & V_5 -> V_113 , V_112 ) ;
F_123 ( & V_284 ) ;
if ( ! V_110 )
break;
F_174 ( V_5 , 1 , V_227 , false ) ;
V_279 = F_32 ( & V_5 -> V_113 ) ;
if ( V_279 >= V_280 )
V_282 -- ;
else
V_280 = V_279 ;
} while ( V_282 );
if ( ! V_110 && V_281 )
F_144 ( V_5 ) ;
return V_110 ;
}
unsigned long F_241 ( T_4 * V_93 , int V_137 ,
T_3 V_136 ,
unsigned long * V_165 )
{
unsigned long V_235 = 0 ;
struct V_16 * V_22 , * V_285 = NULL ;
unsigned long V_286 ;
int V_168 = 0 ;
struct V_19 * V_23 ;
unsigned long V_39 ;
unsigned long V_169 ;
if ( V_137 > 0 )
return 0 ;
V_23 = F_20 ( V_93 -> V_94 ) ;
if ( F_242 ( & V_23 -> V_27 ) )
return 0 ;
do {
if ( V_285 )
V_22 = V_285 ;
else
V_22 = F_40 ( V_23 ) ;
if ( ! V_22 )
break;
V_169 = 0 ;
V_286 = F_134 ( V_22 -> V_5 , V_93 ,
V_136 , & V_169 ) ;
V_235 += V_286 ;
* V_165 += V_169 ;
F_41 ( & V_23 -> V_35 ) ;
F_26 ( V_22 , V_23 ) ;
V_285 = NULL ;
if ( ! V_286 )
V_285 = F_37 ( V_23 ) ;
V_39 = F_31 ( V_22 -> V_5 ) ;
F_22 ( V_22 , V_23 , V_39 ) ;
F_42 ( & V_23 -> V_35 ) ;
F_76 ( & V_22 -> V_5 -> V_9 ) ;
V_168 ++ ;
if ( ! V_235 &&
( V_285 == NULL ||
V_168 > V_287 ) )
break;
} while ( ! V_235 );
if ( V_285 )
F_76 ( & V_285 -> V_5 -> V_9 ) ;
return V_235 ;
}
static inline bool F_243 ( struct V_4 * V_5 )
{
bool V_110 ;
F_13 () ;
V_110 = F_244 ( NULL , & V_5 -> V_9 ) ;
F_17 () ;
return V_110 ;
}
static int F_245 ( struct V_4 * V_5 )
{
int V_230 = V_231 ;
F_246 () ;
while ( V_230 && F_32 ( & V_5 -> V_37 ) ) {
int V_288 ;
if ( F_238 ( V_119 ) )
return - V_283 ;
V_288 = F_174 ( V_5 , 1 ,
V_227 , true ) ;
if ( ! V_288 ) {
V_230 -- ;
F_247 ( V_289 , V_290 / 10 ) ;
}
}
return 0 ;
}
static T_7 F_248 ( struct V_291 * V_292 ,
char * V_293 , T_8 V_294 ,
T_9 V_295 )
{
struct V_4 * V_5 = F_67 ( F_249 ( V_292 ) ) ;
if ( F_6 ( V_5 ) )
return - V_278 ;
return F_245 ( V_5 ) ? : V_294 ;
}
static V_123 F_250 ( struct V_7 * V_9 ,
struct V_296 * V_297 )
{
return F_67 ( V_9 ) -> V_91 ;
}
static int F_251 ( struct V_7 * V_9 ,
struct V_296 * V_297 , V_123 V_45 )
{
int V_298 = 0 ;
struct V_4 * V_5 = F_67 ( V_9 ) ;
struct V_4 * V_299 = F_67 ( V_5 -> V_9 . V_28 ) ;
if ( V_5 -> V_91 == V_45 )
return 0 ;
if ( ( ! V_299 || ! V_299 -> V_91 ) &&
( V_45 == 1 || V_45 == 0 ) ) {
if ( ! F_243 ( V_5 ) )
V_5 -> V_91 = V_45 ;
else
V_298 = - V_300 ;
} else
V_298 = - V_278 ;
return V_298 ;
}
static void F_252 ( struct V_4 * V_5 , unsigned long * V_47 )
{
struct V_4 * V_89 ;
int V_100 ;
memset ( V_47 , 0 , sizeof( * V_47 ) * V_301 ) ;
F_104 (iter, memcg) {
for ( V_100 = 0 ; V_100 < V_301 ; V_100 ++ )
V_47 [ V_100 ] += F_43 ( V_89 , V_100 ) ;
}
}
static void F_253 ( struct V_4 * V_5 , unsigned long * V_50 )
{
struct V_4 * V_89 ;
int V_100 ;
memset ( V_50 , 0 , sizeof( * V_50 ) * V_302 ) ;
F_104 (iter, memcg) {
for ( V_100 = 0 ; V_100 < V_302 ; V_100 ++ )
V_50 [ V_100 ] += F_46 ( V_89 , V_100 ) ;
}
}
static unsigned long F_254 ( struct V_4 * V_5 , bool V_134 )
{
unsigned long V_45 = 0 ;
if ( F_6 ( V_5 ) ) {
struct V_4 * V_89 ;
F_104 (iter, memcg) {
V_45 += F_43 ( V_89 ,
V_53 ) ;
V_45 += F_43 ( V_89 ,
V_52 ) ;
if ( V_134 )
V_45 += F_43 ( V_89 ,
V_127 ) ;
}
} else {
if ( ! V_134 )
V_45 = F_32 ( & V_5 -> V_37 ) ;
else
V_45 = F_32 ( & V_5 -> V_113 ) ;
}
return V_45 ;
}
static V_123 F_255 ( struct V_7 * V_9 ,
struct V_296 * V_297 )
{
struct V_4 * V_5 = F_67 ( V_9 ) ;
struct V_233 * V_234 ;
switch ( F_256 ( V_297 -> V_195 ) ) {
case V_303 :
V_234 = & V_5 -> V_37 ;
break;
case V_304 :
V_234 = & V_5 -> V_113 ;
break;
case V_305 :
V_234 = & V_5 -> V_125 ;
break;
case V_306 :
V_234 = & V_5 -> V_307 ;
break;
default:
F_257 () ;
}
switch ( F_258 ( V_297 -> V_195 ) ) {
case V_308 :
if ( V_234 == & V_5 -> V_37 )
return ( V_123 ) F_254 ( V_5 , false ) * V_248 ;
if ( V_234 == & V_5 -> V_113 )
return ( V_123 ) F_254 ( V_5 , true ) * V_248 ;
return ( V_123 ) F_32 ( V_234 ) * V_248 ;
case V_309 :
return ( V_123 ) V_234 -> V_112 * V_248 ;
case V_310 :
return ( V_123 ) V_234 -> V_311 * V_248 ;
case V_312 :
return V_234 -> V_124 ;
case V_313 :
return ( V_123 ) V_5 -> V_38 * V_248 ;
default:
F_257 () ;
}
}
static int F_259 ( struct V_4 * V_5 )
{
int V_314 ;
if ( V_315 )
return 0 ;
F_260 ( V_5 -> V_269 >= 0 ) ;
F_260 ( V_5 -> V_316 ) ;
V_314 = F_204 () ;
if ( V_314 < 0 )
return V_314 ;
F_261 ( & V_317 ) ;
V_5 -> V_269 = V_314 ;
V_5 -> V_316 = V_318 ;
return 0 ;
}
static void F_262 ( struct V_4 * V_5 )
{
struct V_7 * V_9 ;
struct V_4 * V_28 , * V_319 ;
int V_269 ;
if ( V_5 -> V_316 != V_318 )
return;
V_5 -> V_316 = V_320 ;
F_263 ( V_5 ) ;
V_269 = V_5 -> V_269 ;
F_260 ( V_269 < 0 ) ;
V_28 = F_15 ( V_5 ) ;
if ( ! V_28 )
V_28 = V_6 ;
F_13 () ;
F_264 (css, &memcg->css) {
V_319 = F_67 ( V_9 ) ;
F_260 ( V_319 -> V_269 != V_269 ) ;
V_319 -> V_269 = V_28 -> V_269 ;
if ( ! V_5 -> V_91 )
break;
}
F_17 () ;
F_265 ( V_269 , V_28 -> V_269 ) ;
F_211 ( V_269 ) ;
}
static void F_266 ( struct V_4 * V_5 )
{
if ( F_63 ( V_5 -> V_316 == V_318 ) )
F_262 ( V_5 ) ;
if ( V_5 -> V_316 == V_320 ) {
F_267 ( V_5 ) ;
F_268 ( & V_317 ) ;
F_269 ( F_32 ( & V_5 -> V_125 ) ) ;
}
}
static int F_259 ( struct V_4 * V_5 )
{
return 0 ;
}
static void F_262 ( struct V_4 * V_5 )
{
}
static void F_266 ( struct V_4 * V_5 )
{
}
static int F_270 ( struct V_4 * V_5 ,
unsigned long V_112 )
{
int V_110 ;
F_109 ( & V_284 ) ;
V_110 = F_239 ( & V_5 -> V_125 , V_112 ) ;
F_123 ( & V_284 ) ;
return V_110 ;
}
static int F_271 ( struct V_4 * V_5 , unsigned long V_112 )
{
int V_110 ;
F_109 ( & V_284 ) ;
V_110 = F_239 ( & V_5 -> V_307 , V_112 ) ;
if ( V_110 )
goto V_92;
if ( ! V_5 -> V_321 ) {
F_261 ( & V_322 ) ;
V_5 -> V_321 = true ;
}
V_92:
F_123 ( & V_284 ) ;
return V_110 ;
}
static T_7 F_272 ( struct V_291 * V_292 ,
char * V_293 , T_8 V_294 , T_9 V_295 )
{
struct V_4 * V_5 = F_67 ( F_249 ( V_292 ) ) ;
unsigned long V_36 ;
int V_110 ;
V_293 = F_273 ( V_293 ) ;
V_110 = F_274 ( V_293 , L_15 , & V_36 ) ;
if ( V_110 )
return V_110 ;
switch ( F_258 ( F_275 ( V_292 ) -> V_195 ) ) {
case V_309 :
if ( F_6 ( V_5 ) ) {
V_110 = - V_278 ;
break;
}
switch ( F_256 ( F_275 ( V_292 ) -> V_195 ) ) {
case V_303 :
V_110 = F_237 ( V_5 , V_36 ) ;
break;
case V_304 :
V_110 = F_240 ( V_5 , V_36 ) ;
break;
case V_305 :
V_110 = F_270 ( V_5 , V_36 ) ;
break;
case V_306 :
V_110 = F_271 ( V_5 , V_36 ) ;
break;
}
break;
case V_313 :
V_5 -> V_38 = V_36 ;
V_110 = 0 ;
break;
}
return V_110 ? : V_294 ;
}
static T_7 F_276 ( struct V_291 * V_292 , char * V_293 ,
T_8 V_294 , T_9 V_295 )
{
struct V_4 * V_5 = F_67 ( F_249 ( V_292 ) ) ;
struct V_233 * V_234 ;
switch ( F_256 ( F_275 ( V_292 ) -> V_195 ) ) {
case V_303 :
V_234 = & V_5 -> V_37 ;
break;
case V_304 :
V_234 = & V_5 -> V_113 ;
break;
case V_305 :
V_234 = & V_5 -> V_125 ;
break;
case V_306 :
V_234 = & V_5 -> V_307 ;
break;
default:
F_257 () ;
}
switch ( F_258 ( F_275 ( V_292 ) -> V_195 ) ) {
case V_310 :
F_277 ( V_234 ) ;
break;
case V_312 :
V_234 -> V_124 = 0 ;
break;
default:
F_257 () ;
}
return V_294 ;
}
static V_123 F_278 ( struct V_7 * V_9 ,
struct V_296 * V_297 )
{
return F_67 ( V_9 ) -> V_323 ;
}
static int F_279 ( struct V_7 * V_9 ,
struct V_296 * V_297 , V_123 V_45 )
{
struct V_4 * V_5 = F_67 ( V_9 ) ;
if ( V_45 & ~ V_324 )
return - V_278 ;
V_5 -> V_323 = V_45 ;
return 0 ;
}
static int F_279 ( struct V_7 * V_9 ,
struct V_296 * V_297 , V_123 V_45 )
{
return - V_325 ;
}
static int F_280 ( struct V_326 * V_327 , void * V_328 )
{
struct V_329 {
const char * V_330 ;
unsigned int V_58 ;
};
static const struct V_329 V_331 [] = {
{ L_16 , V_332 } ,
{ L_17 , V_156 } ,
{ L_18 , V_157 } ,
{ L_19 , F_56 (LRU_UNEVICTABLE) } ,
} ;
const struct V_329 * V_47 ;
int V_17 ;
unsigned long V_59 ;
struct V_4 * V_5 = F_67 ( F_281 ( V_327 ) ) ;
for ( V_47 = V_331 ; V_47 < V_331 + F_282 ( V_331 ) ; V_47 ++ ) {
V_59 = F_57 ( V_5 , V_47 -> V_58 ) ;
F_283 ( V_327 , L_20 , V_47 -> V_330 , V_59 ) ;
F_58 (nid, N_MEMORY) {
V_59 = F_53 ( V_5 , V_17 ,
V_47 -> V_58 ) ;
F_283 ( V_327 , L_21 , V_17 , V_59 ) ;
}
F_284 ( V_327 , '\n' ) ;
}
for ( V_47 = V_331 ; V_47 < V_331 + F_282 ( V_331 ) ; V_47 ++ ) {
struct V_4 * V_89 ;
V_59 = 0 ;
F_104 (iter, memcg)
V_59 += F_57 ( V_89 , V_47 -> V_58 ) ;
F_283 ( V_327 , L_22 , V_47 -> V_330 , V_59 ) ;
F_58 (nid, N_MEMORY) {
V_59 = 0 ;
F_104 (iter, memcg)
V_59 += F_53 (
V_89 , V_17 , V_47 -> V_58 ) ;
F_283 ( V_327 , L_21 , V_17 , V_59 ) ;
}
F_284 ( V_327 , '\n' ) ;
}
return 0 ;
}
static int F_285 ( struct V_326 * V_327 , void * V_328 )
{
struct V_4 * V_5 = F_67 ( F_281 ( V_327 ) ) ;
unsigned long V_37 , V_113 ;
struct V_4 * V_333 ;
unsigned int V_100 ;
F_286 ( F_282 ( V_128 ) !=
V_126 ) ;
F_286 ( F_282 ( V_334 ) !=
V_335 ) ;
F_286 ( F_282 ( V_130 ) != V_129 ) ;
for ( V_100 = 0 ; V_100 < V_126 ; V_100 ++ ) {
if ( V_100 == V_127 && ! F_1 () )
continue;
F_283 ( V_327 , L_23 , V_128 [ V_100 ] ,
F_43 ( V_5 , V_100 ) * V_248 ) ;
}
for ( V_100 = 0 ; V_100 < V_335 ; V_100 ++ )
F_283 ( V_327 , L_23 , V_334 [ V_100 ] ,
F_46 ( V_5 , V_100 ) ) ;
for ( V_100 = 0 ; V_100 < V_129 ; V_100 ++ )
F_283 ( V_327 , L_23 , V_130 [ V_100 ] ,
F_57 ( V_5 , F_56 ( V_100 ) ) * V_248 ) ;
V_37 = V_113 = V_336 ;
for ( V_333 = V_5 ; V_333 ; V_333 = F_15 ( V_333 ) ) {
V_37 = F_89 ( V_37 , V_333 -> V_37 . V_112 ) ;
V_113 = F_89 ( V_113 , V_333 -> V_113 . V_112 ) ;
}
F_283 ( V_327 , L_24 ,
( V_123 ) V_37 * V_248 ) ;
if ( F_1 () )
F_283 ( V_327 , L_25 ,
( V_123 ) V_113 * V_248 ) ;
for ( V_100 = 0 ; V_100 < V_126 ; V_100 ++ ) {
unsigned long long V_45 = 0 ;
if ( V_100 == V_127 && ! F_1 () )
continue;
F_104 (mi, memcg)
V_45 += F_43 ( V_333 , V_100 ) * V_248 ;
F_283 ( V_327 , L_26 , V_128 [ V_100 ] , V_45 ) ;
}
for ( V_100 = 0 ; V_100 < V_335 ; V_100 ++ ) {
unsigned long long V_45 = 0 ;
F_104 (mi, memcg)
V_45 += F_46 ( V_333 , V_100 ) ;
F_283 ( V_327 , L_26 ,
V_334 [ V_100 ] , V_45 ) ;
}
for ( V_100 = 0 ; V_100 < V_129 ; V_100 ++ ) {
unsigned long long V_45 = 0 ;
F_104 (mi, memcg)
V_45 += F_57 ( V_333 , F_56 ( V_100 ) ) * V_248 ;
F_283 ( V_327 , L_26 , V_130 [ V_100 ] , V_45 ) ;
}
#ifdef F_287
{
T_4 * V_93 ;
struct V_16 * V_22 ;
struct V_337 * V_338 ;
unsigned long V_339 [ 2 ] = { 0 , 0 } ;
unsigned long V_340 [ 2 ] = { 0 , 0 } ;
F_288 (pgdat) {
V_22 = F_36 ( V_5 , V_93 -> V_94 ) ;
V_338 = & V_22 -> V_102 . V_341 ;
V_339 [ 0 ] += V_338 -> V_339 [ 0 ] ;
V_339 [ 1 ] += V_338 -> V_339 [ 1 ] ;
V_340 [ 0 ] += V_338 -> V_340 [ 0 ] ;
V_340 [ 1 ] += V_338 -> V_340 [ 1 ] ;
}
F_283 ( V_327 , L_27 , V_339 [ 0 ] ) ;
F_283 ( V_327 , L_28 , V_339 [ 1 ] ) ;
F_283 ( V_327 , L_29 , V_340 [ 0 ] ) ;
F_283 ( V_327 , L_30 , V_340 [ 1 ] ) ;
}
#endif
return 0 ;
}
static V_123 F_289 ( struct V_7 * V_9 ,
struct V_296 * V_297 )
{
struct V_4 * V_5 = F_67 ( V_9 ) ;
return F_107 ( V_5 ) ;
}
static int F_290 ( struct V_7 * V_9 ,
struct V_296 * V_297 , V_123 V_45 )
{
struct V_4 * V_5 = F_67 ( V_9 ) ;
if ( V_45 > 100 )
return - V_278 ;
if ( V_9 -> V_28 )
V_5 -> V_342 = V_45 ;
else
V_343 = V_45 ;
return 0 ;
}
static void F_291 ( struct V_4 * V_5 , bool V_134 )
{
struct V_344 * V_345 ;
unsigned long V_346 ;
int V_100 ;
F_13 () ;
if ( ! V_134 )
V_345 = F_70 ( V_5 -> V_347 . V_348 ) ;
else
V_345 = F_70 ( V_5 -> V_349 . V_348 ) ;
if ( ! V_345 )
goto V_117;
V_346 = F_254 ( V_5 , V_134 ) ;
V_100 = V_345 -> V_350 ;
for (; V_100 >= 0 && F_63 ( V_345 -> V_351 [ V_100 ] . V_352 > V_346 ) ; V_100 -- )
F_292 ( V_345 -> V_351 [ V_100 ] . V_353 , 1 ) ;
V_100 ++ ;
for (; V_100 < V_345 -> V_104 && F_63 ( V_345 -> V_351 [ V_100 ] . V_352 <= V_346 ) ; V_100 ++ )
F_292 ( V_345 -> V_351 [ V_100 ] . V_353 , 1 ) ;
V_345 -> V_350 = V_100 - 1 ;
V_117:
F_17 () ;
}
static void F_64 ( struct V_4 * V_5 )
{
while ( V_5 ) {
F_291 ( V_5 , false ) ;
if ( F_1 () )
F_291 ( V_5 , true ) ;
V_5 = F_15 ( V_5 ) ;
}
}
static int F_293 ( const void * V_354 , const void * V_355 )
{
const struct F_64 * V_356 = V_354 ;
const struct F_64 * V_357 = V_355 ;
if ( V_356 -> V_352 > V_357 -> V_352 )
return 1 ;
if ( V_356 -> V_352 < V_357 -> V_352 )
return - 1 ;
return 0 ;
}
static int F_294 ( struct V_4 * V_5 )
{
struct V_358 * V_359 ;
F_91 ( & V_172 ) ;
F_295 (ev, &memcg->oom_notify, list)
F_292 ( V_359 -> V_353 , 1 ) ;
F_92 ( & V_172 ) ;
return 0 ;
}
static void F_149 ( struct V_4 * V_5 )
{
struct V_4 * V_89 ;
F_104 (iter, memcg)
F_294 ( V_89 ) ;
}
static int F_296 ( struct V_4 * V_5 ,
struct V_360 * V_353 , const char * args , enum V_361 type )
{
struct V_362 * V_347 ;
struct V_344 * V_363 ;
unsigned long V_352 ;
unsigned long V_346 ;
int V_100 , V_104 , V_110 ;
V_110 = F_274 ( args , L_15 , & V_352 ) ;
if ( V_110 )
return V_110 ;
F_109 ( & V_5 -> V_364 ) ;
if ( type == V_303 ) {
V_347 = & V_5 -> V_347 ;
V_346 = F_254 ( V_5 , false ) ;
} else if ( type == V_304 ) {
V_347 = & V_5 -> V_349 ;
V_346 = F_254 ( V_5 , true ) ;
} else
F_257 () ;
if ( V_347 -> V_348 )
F_291 ( V_5 , type == V_304 ) ;
V_104 = V_347 -> V_348 ? V_347 -> V_348 -> V_104 + 1 : 1 ;
V_363 = F_216 ( sizeof( * V_363 ) + V_104 * sizeof( struct F_64 ) ,
V_227 ) ;
if ( ! V_363 ) {
V_110 = - V_249 ;
goto V_117;
}
V_363 -> V_104 = V_104 ;
if ( V_347 -> V_348 ) {
memcpy ( V_363 -> V_351 , V_347 -> V_348 -> V_351 , ( V_104 - 1 ) *
sizeof( struct F_64 ) ) ;
}
V_363 -> V_351 [ V_104 - 1 ] . V_353 = V_353 ;
V_363 -> V_351 [ V_104 - 1 ] . V_352 = V_352 ;
F_297 ( V_363 -> V_351 , V_104 , sizeof( struct F_64 ) ,
F_293 , NULL ) ;
V_363 -> V_350 = - 1 ;
for ( V_100 = 0 ; V_100 < V_104 ; V_100 ++ ) {
if ( V_363 -> V_351 [ V_100 ] . V_352 <= V_346 ) {
++ V_363 -> V_350 ;
} else
break;
}
F_214 ( V_347 -> V_365 ) ;
V_347 -> V_365 = V_347 -> V_348 ;
F_298 ( V_347 -> V_348 , V_363 ) ;
F_299 () ;
V_117:
F_123 ( & V_5 -> V_364 ) ;
return V_110 ;
}
static int F_300 ( struct V_4 * V_5 ,
struct V_360 * V_353 , const char * args )
{
return F_296 ( V_5 , V_353 , args , V_303 ) ;
}
static int F_301 ( struct V_4 * V_5 ,
struct V_360 * V_353 , const char * args )
{
return F_296 ( V_5 , V_353 , args , V_304 ) ;
}
static void F_302 ( struct V_4 * V_5 ,
struct V_360 * V_353 , enum V_361 type )
{
struct V_362 * V_347 ;
struct V_344 * V_363 ;
unsigned long V_346 ;
int V_100 , V_366 , V_104 ;
F_109 ( & V_5 -> V_364 ) ;
if ( type == V_303 ) {
V_347 = & V_5 -> V_347 ;
V_346 = F_254 ( V_5 , false ) ;
} else if ( type == V_304 ) {
V_347 = & V_5 -> V_349 ;
V_346 = F_254 ( V_5 , true ) ;
} else
F_257 () ;
if ( ! V_347 -> V_348 )
goto V_117;
F_291 ( V_5 , type == V_304 ) ;
V_104 = 0 ;
for ( V_100 = 0 ; V_100 < V_347 -> V_348 -> V_104 ; V_100 ++ ) {
if ( V_347 -> V_348 -> V_351 [ V_100 ] . V_353 != V_353 )
V_104 ++ ;
}
V_363 = V_347 -> V_365 ;
if ( ! V_104 ) {
F_214 ( V_363 ) ;
V_363 = NULL ;
goto V_367;
}
V_363 -> V_104 = V_104 ;
V_363 -> V_350 = - 1 ;
for ( V_100 = 0 , V_366 = 0 ; V_100 < V_347 -> V_348 -> V_104 ; V_100 ++ ) {
if ( V_347 -> V_348 -> V_351 [ V_100 ] . V_353 == V_353 )
continue;
V_363 -> V_351 [ V_366 ] = V_347 -> V_348 -> V_351 [ V_100 ] ;
if ( V_363 -> V_351 [ V_366 ] . V_352 <= V_346 ) {
++ V_363 -> V_350 ;
}
V_366 ++ ;
}
V_367:
V_347 -> V_365 = V_347 -> V_348 ;
F_298 ( V_347 -> V_348 , V_363 ) ;
F_299 () ;
if ( ! V_363 ) {
F_214 ( V_347 -> V_365 ) ;
V_347 -> V_365 = NULL ;
}
V_117:
F_123 ( & V_5 -> V_364 ) ;
}
static void F_303 ( struct V_4 * V_5 ,
struct V_360 * V_353 )
{
return F_302 ( V_5 , V_353 , V_303 ) ;
}
static void F_304 ( struct V_4 * V_5 ,
struct V_360 * V_353 )
{
return F_302 ( V_5 , V_353 , V_304 ) ;
}
static int F_305 ( struct V_4 * V_5 ,
struct V_360 * V_353 , const char * args )
{
struct V_358 * V_368 ;
V_368 = F_216 ( sizeof( * V_368 ) , V_227 ) ;
if ( ! V_368 )
return - V_249 ;
F_91 ( & V_172 ) ;
V_368 -> V_353 = V_353 ;
F_306 ( & V_368 -> V_369 , & V_5 -> V_370 ) ;
if ( V_5 -> V_175 )
F_292 ( V_353 , 1 ) ;
F_92 ( & V_172 ) ;
return 0 ;
}
static void F_307 ( struct V_4 * V_5 ,
struct V_360 * V_353 )
{
struct V_358 * V_359 , * V_371 ;
F_91 ( & V_172 ) ;
F_308 (ev, tmp, &memcg->oom_notify, list) {
if ( V_359 -> V_353 == V_353 ) {
F_309 ( & V_359 -> V_369 ) ;
F_214 ( V_359 ) ;
}
}
F_92 ( & V_172 ) ;
}
static int F_310 ( struct V_326 * V_372 , void * V_328 )
{
struct V_4 * V_5 = F_67 ( F_281 ( V_372 ) ) ;
F_283 ( V_372 , L_31 , V_5 -> V_198 ) ;
F_283 ( V_372 , L_32 , ( bool ) V_5 -> V_175 ) ;
return 0 ;
}
static int F_311 ( struct V_7 * V_9 ,
struct V_296 * V_297 , V_123 V_45 )
{
struct V_4 * V_5 = F_67 ( V_9 ) ;
if ( ! V_9 -> V_28 || ! ( ( V_45 == 0 ) || ( V_45 == 1 ) ) )
return - V_278 ;
V_5 -> V_198 = V_45 ;
if ( ! V_45 )
F_144 ( V_5 ) ;
return 0 ;
}
struct V_373 * F_312 ( struct V_4 * V_5 )
{
return & V_5 -> V_374 ;
}
static int F_313 ( struct V_4 * V_5 , T_3 V_271 )
{
return F_314 ( & V_5 -> V_375 , V_271 ) ;
}
static void F_315 ( struct V_4 * V_5 )
{
F_316 ( & V_5 -> V_375 ) ;
}
static void F_317 ( struct V_4 * V_5 )
{
F_318 ( & V_5 -> V_375 ) ;
}
struct V_376 * F_319 ( struct V_377 * V_378 )
{
struct V_4 * V_5 = F_67 ( V_378 -> V_379 ) ;
if ( ! V_5 -> V_9 . V_28 )
return NULL ;
return & V_5 -> V_375 ;
}
void F_320 ( struct V_377 * V_378 , unsigned long * V_380 ,
unsigned long * V_381 , unsigned long * V_382 ,
unsigned long * V_383 )
{
struct V_4 * V_5 = F_67 ( V_378 -> V_379 ) ;
struct V_4 * V_28 ;
* V_382 = F_43 ( V_5 , V_384 ) ;
* V_383 = F_43 ( V_5 , V_385 ) ;
* V_380 = F_57 ( V_5 , ( 1 << V_386 ) |
( 1 << V_387 ) ) ;
* V_381 = V_336 ;
while ( ( V_28 = F_15 ( V_5 ) ) ) {
unsigned long V_388 = F_89 ( V_5 -> V_37 . V_112 , V_5 -> V_224 ) ;
unsigned long V_389 = F_32 ( & V_5 -> V_37 ) ;
* V_381 = F_89 ( * V_381 , V_388 - F_89 ( V_388 , V_389 ) ) ;
V_5 = V_28 ;
}
}
static int F_313 ( struct V_4 * V_5 , T_3 V_271 )
{
return 0 ;
}
static void F_315 ( struct V_4 * V_5 )
{
}
static void F_317 ( struct V_4 * V_5 )
{
}
static void F_321 ( struct V_210 * V_215 )
{
struct V_390 * V_368 =
F_5 ( V_215 , struct V_390 , remove ) ;
struct V_4 * V_5 = V_368 -> V_5 ;
F_322 ( V_368 -> V_391 , & V_368 -> V_120 ) ;
V_368 -> V_392 ( V_5 , V_368 -> V_353 ) ;
F_292 ( V_368 -> V_353 , 1 ) ;
F_323 ( V_368 -> V_353 ) ;
F_214 ( V_368 ) ;
F_76 ( & V_5 -> V_9 ) ;
}
static int F_324 ( T_5 * V_120 , unsigned V_176 ,
int V_177 , void * V_393 )
{
struct V_390 * V_368 =
F_5 ( V_120 , struct V_390 , V_120 ) ;
struct V_4 * V_5 = V_368 -> V_5 ;
unsigned long V_13 = ( unsigned long ) V_393 ;
if ( V_13 & V_394 ) {
F_91 ( & V_5 -> V_395 ) ;
if ( ! F_81 ( & V_368 -> V_369 ) ) {
F_325 ( & V_368 -> V_369 ) ;
F_190 ( & V_368 -> remove ) ;
}
F_92 ( & V_5 -> V_395 ) ;
}
return 0 ;
}
static void F_326 ( struct V_396 * V_396 ,
T_10 * V_391 , T_11 * V_397 )
{
struct V_390 * V_368 =
F_5 ( V_397 , struct V_390 , V_397 ) ;
V_368 -> V_391 = V_391 ;
F_327 ( V_391 , & V_368 -> V_120 ) ;
}
static T_7 F_328 ( struct V_291 * V_292 ,
char * V_293 , T_8 V_294 , T_9 V_295 )
{
struct V_7 * V_9 = F_249 ( V_292 ) ;
struct V_4 * V_5 = F_67 ( V_9 ) ;
struct V_390 * V_368 ;
struct V_7 * V_398 ;
unsigned int V_399 , V_400 ;
struct V_401 V_402 ;
struct V_401 V_403 ;
const char * V_330 ;
char * V_404 ;
int V_110 ;
V_293 = F_273 ( V_293 ) ;
V_399 = F_329 ( V_293 , & V_404 , 10 ) ;
if ( * V_404 != ' ' )
return - V_278 ;
V_293 = V_404 + 1 ;
V_400 = F_329 ( V_293 , & V_404 , 10 ) ;
if ( ( * V_404 != ' ' ) && ( * V_404 != '\0' ) )
return - V_278 ;
V_293 = V_404 + 1 ;
V_368 = F_330 ( sizeof( * V_368 ) , V_227 ) ;
if ( ! V_368 )
return - V_249 ;
V_368 -> V_5 = V_5 ;
F_148 ( & V_368 -> V_369 ) ;
F_331 ( & V_368 -> V_397 , F_326 ) ;
F_332 ( & V_368 -> V_120 , F_324 ) ;
F_217 ( & V_368 -> remove , F_321 ) ;
V_402 = F_333 ( V_399 ) ;
if ( ! V_402 . V_396 ) {
V_110 = - V_405 ;
goto V_406;
}
V_368 -> V_353 = F_334 ( V_402 . V_396 ) ;
if ( F_335 ( V_368 -> V_353 ) ) {
V_110 = F_336 ( V_368 -> V_353 ) ;
goto V_407;
}
V_403 = F_333 ( V_400 ) ;
if ( ! V_403 . V_396 ) {
V_110 = - V_405 ;
goto V_408;
}
V_110 = F_337 ( F_338 ( V_403 . V_396 ) , V_409 ) ;
if ( V_110 < 0 )
goto V_410;
V_330 = V_403 . V_396 -> V_411 . V_412 -> V_413 . V_330 ;
if ( ! strcmp ( V_330 , L_33 ) ) {
V_368 -> V_414 = F_300 ;
V_368 -> V_392 = F_303 ;
} else if ( ! strcmp ( V_330 , L_34 ) ) {
V_368 -> V_414 = F_305 ;
V_368 -> V_392 = F_307 ;
} else if ( ! strcmp ( V_330 , L_35 ) ) {
V_368 -> V_414 = V_415 ;
V_368 -> V_392 = V_416 ;
} else if ( ! strcmp ( V_330 , L_36 ) ) {
V_368 -> V_414 = F_301 ;
V_368 -> V_392 = F_304 ;
} else {
V_110 = - V_278 ;
goto V_410;
}
V_398 = F_339 ( V_403 . V_396 -> V_411 . V_412 -> V_417 ,
& V_1 ) ;
V_110 = - V_278 ;
if ( F_335 ( V_398 ) )
goto V_410;
if ( V_398 != V_9 ) {
F_76 ( V_398 ) ;
goto V_410;
}
V_110 = V_368 -> V_414 ( V_5 , V_368 -> V_353 , V_293 ) ;
if ( V_110 )
goto V_418;
V_402 . V_396 -> V_419 -> V_420 ( V_402 . V_396 , & V_368 -> V_397 ) ;
F_91 ( & V_5 -> V_395 ) ;
F_306 ( & V_368 -> V_369 , & V_5 -> V_421 ) ;
F_92 ( & V_5 -> V_395 ) ;
F_340 ( V_403 ) ;
F_340 ( V_402 ) ;
return V_294 ;
V_418:
F_76 ( V_9 ) ;
V_410:
F_340 ( V_403 ) ;
V_408:
F_323 ( V_368 -> V_353 ) ;
V_407:
F_340 ( V_402 ) ;
V_406:
F_214 ( V_368 ) ;
return V_110 ;
}
static void F_341 ( struct V_4 * V_5 , unsigned int V_422 )
{
F_342 ( V_422 , & V_5 -> V_254 . V_423 ) ;
}
static void F_343 ( struct V_4 * V_5 , unsigned int V_422 )
{
if ( F_344 ( V_422 , & V_5 -> V_254 . V_423 ) ) {
F_345 ( & V_424 , V_5 -> V_254 . V_254 ) ;
V_5 -> V_254 . V_254 = 0 ;
F_76 ( & V_5 -> V_9 ) ;
}
}
static inline void F_346 ( struct V_4 * V_5 )
{
F_341 ( V_5 , 1 ) ;
}
static inline void F_347 ( struct V_4 * V_5 )
{
F_343 ( V_5 , 1 ) ;
}
struct V_4 * F_348 ( unsigned short V_254 )
{
F_349 ( ! F_350 () ) ;
return F_351 ( & V_424 , V_254 ) ;
}
static int F_352 ( struct V_4 * V_5 , int V_162 )
{
struct V_16 * V_425 ;
int V_371 = V_162 ;
if ( ! F_353 ( V_162 , V_426 ) )
V_371 = - 1 ;
V_425 = F_354 ( sizeof( * V_425 ) , V_227 , V_371 ) ;
if ( ! V_425 )
return 1 ;
F_355 ( & V_425 -> V_102 ) ;
V_425 -> V_31 = 0 ;
V_425 -> V_30 = false ;
V_425 -> V_5 = V_5 ;
V_5 -> V_18 [ V_162 ] = V_425 ;
return 0 ;
}
static void F_356 ( struct V_4 * V_5 , int V_162 )
{
F_214 ( V_5 -> V_18 [ V_162 ] ) ;
}
static void F_357 ( struct V_4 * V_5 )
{
int V_162 ;
F_315 ( V_5 ) ;
F_35 (node)
F_356 ( V_5 , V_162 ) ;
F_358 ( V_5 -> V_47 ) ;
F_214 ( V_5 ) ;
}
static struct V_4 * F_359 ( void )
{
struct V_4 * V_5 ;
T_8 V_104 ;
int V_162 ;
V_104 = sizeof( struct V_4 ) ;
V_104 += V_62 * sizeof( struct V_16 * ) ;
V_5 = F_330 ( V_104 , V_227 ) ;
if ( ! V_5 )
return NULL ;
V_5 -> V_254 . V_254 = F_360 ( & V_424 , NULL ,
1 , V_427 ,
V_227 ) ;
if ( V_5 -> V_254 . V_254 < 0 )
goto V_428;
V_5 -> V_47 = F_361 ( struct V_429 ) ;
if ( ! V_5 -> V_47 )
goto V_428;
F_35 (node)
if ( F_352 ( V_5 , V_162 ) )
goto V_428;
if ( F_313 ( V_5 , V_227 ) )
goto V_428;
F_217 ( & V_5 -> V_226 , F_175 ) ;
V_5 -> V_163 = V_76 ;
F_148 ( & V_5 -> V_370 ) ;
F_362 ( & V_5 -> V_364 ) ;
F_363 ( & V_5 -> V_201 ) ;
F_364 ( & V_5 -> V_3 ) ;
F_148 ( & V_5 -> V_421 ) ;
F_363 ( & V_5 -> V_395 ) ;
V_5 -> V_430 = V_431 ;
#ifndef F_365
V_5 -> V_269 = - 1 ;
#endif
#ifdef F_366
F_148 ( & V_5 -> V_374 ) ;
#endif
F_367 ( & V_424 , V_5 , V_5 -> V_254 . V_254 ) ;
return V_5 ;
V_428:
if ( V_5 -> V_254 . V_254 > 0 )
F_345 ( & V_424 , V_5 -> V_254 . V_254 ) ;
F_357 ( V_5 ) ;
return NULL ;
}
static struct V_7 * T_12
F_368 ( struct V_7 * V_432 )
{
struct V_4 * V_28 = F_67 ( V_432 ) ;
struct V_4 * V_5 ;
long error = - V_249 ;
V_5 = F_359 () ;
if ( ! V_5 )
return F_369 ( error ) ;
V_5 -> V_224 = V_336 ;
V_5 -> V_38 = V_336 ;
if ( V_28 ) {
V_5 -> V_342 = F_107 ( V_28 ) ;
V_5 -> V_198 = V_28 -> V_198 ;
}
if ( V_28 && V_28 -> V_91 ) {
V_5 -> V_91 = true ;
F_370 ( & V_5 -> V_37 , & V_28 -> V_37 ) ;
F_370 ( & V_5 -> V_134 , & V_28 -> V_134 ) ;
F_370 ( & V_5 -> V_113 , & V_28 -> V_113 ) ;
F_370 ( & V_5 -> V_125 , & V_28 -> V_125 ) ;
F_370 ( & V_5 -> V_307 , & V_28 -> V_307 ) ;
} else {
F_370 ( & V_5 -> V_37 , NULL ) ;
F_370 ( & V_5 -> V_134 , NULL ) ;
F_370 ( & V_5 -> V_113 , NULL ) ;
F_370 ( & V_5 -> V_125 , NULL ) ;
F_370 ( & V_5 -> V_307 , NULL ) ;
if ( V_28 != V_6 )
V_1 . V_433 = true ;
}
if ( ! V_28 ) {
V_6 = V_5 ;
return & V_5 -> V_9 ;
}
error = F_259 ( V_5 ) ;
if ( error )
goto V_428;
if ( F_2 ( V_1 ) && ! V_434 )
F_261 ( & V_322 ) ;
return & V_5 -> V_9 ;
V_428:
F_357 ( V_5 ) ;
return F_369 ( - V_249 ) ;
}
static int F_371 ( struct V_7 * V_9 )
{
F_346 ( F_67 ( V_9 ) ) ;
F_86 ( V_9 ) ;
return 0 ;
}
static void F_372 ( struct V_7 * V_9 )
{
struct V_4 * V_5 = F_67 ( V_9 ) ;
struct V_390 * V_368 , * V_371 ;
F_91 ( & V_5 -> V_395 ) ;
F_308 (event, tmp, &memcg->event_list, list) {
F_325 ( & V_368 -> V_369 ) ;
F_190 ( & V_368 -> remove ) ;
}
F_92 ( & V_5 -> V_395 ) ;
F_262 ( V_5 ) ;
F_373 ( V_5 ) ;
F_347 ( V_5 ) ;
}
static void F_374 ( struct V_7 * V_9 )
{
struct V_4 * V_5 = F_67 ( V_9 ) ;
F_78 ( V_5 ) ;
}
static void F_375 ( struct V_7 * V_9 )
{
struct V_4 * V_5 = F_67 ( V_9 ) ;
if ( F_2 ( V_1 ) && ! V_434 )
F_268 ( & V_322 ) ;
if ( ! F_2 ( V_1 ) && V_5 -> V_321 )
F_268 ( & V_322 ) ;
F_376 ( & V_5 -> V_3 ) ;
F_377 ( & V_5 -> V_226 ) ;
F_34 ( V_5 ) ;
F_266 ( V_5 ) ;
F_357 ( V_5 ) ;
}
static void F_378 ( struct V_7 * V_9 )
{
struct V_4 * V_5 = F_67 ( V_9 ) ;
F_239 ( & V_5 -> V_37 , V_336 ) ;
F_239 ( & V_5 -> V_134 , V_336 ) ;
F_239 ( & V_5 -> V_113 , V_336 ) ;
F_239 ( & V_5 -> V_125 , V_336 ) ;
F_239 ( & V_5 -> V_307 , V_336 ) ;
V_5 -> V_435 = 0 ;
V_5 -> V_224 = V_336 ;
V_5 -> V_38 = V_336 ;
F_317 ( V_5 ) ;
}
static int F_379 ( unsigned long V_48 )
{
int V_110 ;
V_110 = F_178 ( V_116 . V_115 , V_227 & ~ V_436 , V_48 ) ;
if ( ! V_110 ) {
V_116 . V_437 += V_48 ;
return V_110 ;
}
while ( V_48 -- ) {
V_110 = F_178 ( V_116 . V_115 , V_227 & ~ V_244 , 1 ) ;
if ( V_110 )
return V_110 ;
V_116 . V_437 ++ ;
F_380 () ;
}
return 0 ;
}
static struct V_11 * F_381 ( struct V_438 * V_439 ,
unsigned long V_440 , T_13 V_441 )
{
struct V_11 * V_11 = F_382 ( V_439 , V_440 , V_441 ) ;
if ( ! V_11 || ! F_383 ( V_11 ) )
return NULL ;
if ( F_48 ( V_11 ) ) {
if ( ! ( V_116 . V_13 & V_442 ) )
return NULL ;
} else {
if ( ! ( V_116 . V_13 & V_443 ) )
return NULL ;
}
if ( ! F_384 ( V_11 ) )
return NULL ;
return V_11 ;
}
static struct V_11 * F_385 ( struct V_438 * V_439 ,
T_13 V_441 , T_6 * V_275 )
{
struct V_11 * V_11 = NULL ;
T_6 V_444 = F_386 ( V_441 ) ;
if ( ! ( V_116 . V_13 & V_442 ) || F_387 ( V_444 ) )
return NULL ;
V_11 = F_388 ( F_389 ( V_444 ) , V_444 . V_45 ) ;
if ( F_1 () )
V_275 -> V_45 = V_444 . V_45 ;
return V_11 ;
}
static struct V_11 * F_385 ( struct V_438 * V_439 ,
T_13 V_441 , T_6 * V_275 )
{
return NULL ;
}
static struct V_11 * F_390 ( struct V_438 * V_439 ,
unsigned long V_440 , T_13 V_441 , T_6 * V_275 )
{
struct V_11 * V_11 = NULL ;
struct V_445 * V_446 ;
T_14 V_447 ;
if ( ! V_439 -> V_448 )
return NULL ;
if ( ! ( V_116 . V_13 & V_443 ) )
return NULL ;
V_446 = V_439 -> V_448 -> V_449 ;
V_447 = F_391 ( V_439 , V_440 ) ;
#ifdef F_392
if ( F_393 ( V_446 ) ) {
V_11 = F_394 ( V_446 , V_447 ) ;
if ( F_395 ( V_11 ) ) {
T_6 V_450 = F_396 ( V_11 ) ;
if ( F_1 () )
* V_275 = V_450 ;
V_11 = F_388 ( F_389 ( V_450 ) , V_450 . V_45 ) ;
}
} else
V_11 = F_388 ( V_446 , V_447 ) ;
#else
V_11 = F_388 ( V_446 , V_447 ) ;
#endif
return V_11 ;
}
static int F_397 ( struct V_11 * V_11 ,
bool V_51 ,
struct V_4 * V_114 ,
struct V_4 * V_115 )
{
unsigned long V_13 ;
unsigned int V_36 = V_51 ? F_398 ( V_11 ) : 1 ;
int V_110 ;
bool V_451 ;
F_54 ( V_114 == V_115 ) ;
F_50 ( F_196 ( V_11 ) , V_11 ) ;
F_54 ( V_51 && ! F_51 ( V_11 ) ) ;
V_110 = - V_300 ;
if ( ! F_399 ( V_11 ) )
goto V_92;
V_110 = - V_278 ;
if ( V_11 -> V_4 != V_114 )
goto V_97;
V_451 = F_48 ( V_11 ) ;
F_29 ( & V_114 -> V_201 , V_13 ) ;
if ( ! V_451 && F_383 ( V_11 ) ) {
F_231 ( V_114 -> V_47 -> V_48 [ V_452 ] ,
V_36 ) ;
F_49 ( V_115 -> V_47 -> V_48 [ V_452 ] ,
V_36 ) ;
}
if ( ! V_451 && F_400 ( V_11 ) ) {
struct V_445 * V_446 = F_401 ( V_11 ) ;
if ( F_402 ( V_446 ) ) {
F_231 ( V_114 -> V_47 -> V_48 [ V_384 ] ,
V_36 ) ;
F_49 ( V_115 -> V_47 -> V_48 [ V_384 ] ,
V_36 ) ;
}
}
if ( F_403 ( V_11 ) ) {
F_231 ( V_114 -> V_47 -> V_48 [ V_385 ] ,
V_36 ) ;
F_49 ( V_115 -> V_47 -> V_48 [ V_385 ] ,
V_36 ) ;
}
V_11 -> V_4 = V_115 ;
F_30 ( & V_114 -> V_201 , V_13 ) ;
V_110 = 0 ;
F_404 () ;
F_47 ( V_115 , V_11 , V_51 , V_36 ) ;
F_62 ( V_115 , V_11 ) ;
F_47 ( V_114 , V_11 , V_51 , - V_36 ) ;
F_62 ( V_114 , V_11 ) ;
F_405 () ;
V_97:
F_406 ( V_11 ) ;
V_92:
return V_110 ;
}
static enum V_453 F_407 ( struct V_438 * V_439 ,
unsigned long V_440 , T_13 V_441 , union V_454 * V_65 )
{
struct V_11 * V_11 = NULL ;
enum V_453 V_110 = V_455 ;
T_6 V_444 = { . V_45 = 0 } ;
if ( F_408 ( V_441 ) )
V_11 = F_381 ( V_439 , V_440 , V_441 ) ;
else if ( F_409 ( V_441 ) )
V_11 = F_385 ( V_439 , V_441 , & V_444 ) ;
else if ( F_410 ( V_441 ) )
V_11 = F_390 ( V_439 , V_440 , V_441 , & V_444 ) ;
if ( ! V_11 && ! V_444 . V_45 )
return V_110 ;
if ( V_11 ) {
if ( V_11 -> V_4 == V_116 . V_114 ) {
V_110 = V_456 ;
if ( V_65 )
V_65 -> V_11 = V_11 ;
}
if ( ! V_110 || ! V_65 )
F_411 ( V_11 ) ;
}
if ( V_444 . V_45 && ! V_110 &&
F_235 ( V_116 . V_114 ) == F_412 ( V_444 ) ) {
V_110 = V_457 ;
if ( V_65 )
V_65 -> V_444 = V_444 ;
}
return V_110 ;
}
static enum V_453 F_413 ( struct V_438 * V_439 ,
unsigned long V_440 , T_15 V_458 , union V_454 * V_65 )
{
struct V_11 * V_11 = NULL ;
enum V_453 V_110 = V_455 ;
V_11 = F_414 ( V_458 ) ;
F_50 ( ! V_11 || ! F_415 ( V_11 ) , V_11 ) ;
if ( ! ( V_116 . V_13 & V_442 ) )
return V_110 ;
if ( V_11 -> V_4 == V_116 . V_114 ) {
V_110 = V_456 ;
if ( V_65 ) {
F_416 ( V_11 ) ;
V_65 -> V_11 = V_11 ;
}
}
return V_110 ;
}
static inline enum V_453 F_413 ( struct V_438 * V_439 ,
unsigned long V_440 , T_15 V_458 , union V_454 * V_65 )
{
return V_455 ;
}
static int F_417 ( T_15 * V_458 ,
unsigned long V_440 , unsigned long V_459 ,
struct V_460 * V_461 )
{
struct V_438 * V_439 = V_461 -> V_439 ;
T_13 * V_462 ;
T_16 * V_463 ;
V_463 = F_418 ( V_458 , V_439 ) ;
if ( V_463 ) {
if ( F_413 ( V_439 , V_440 , * V_458 , NULL ) == V_456 )
V_116 . V_437 += V_273 ;
F_92 ( V_463 ) ;
return 0 ;
}
if ( F_419 ( V_458 ) )
return 0 ;
V_462 = F_420 ( V_439 -> V_464 , V_458 , V_440 , & V_463 ) ;
for (; V_440 != V_459 ; V_462 ++ , V_440 += V_248 )
if ( F_407 ( V_439 , V_440 , * V_462 , NULL ) )
V_116 . V_437 ++ ;
F_421 ( V_462 - 1 , V_463 ) ;
F_380 () ;
return 0 ;
}
static unsigned long F_422 ( struct V_80 * V_81 )
{
unsigned long V_437 ;
struct V_460 V_465 = {
. V_466 = F_417 ,
. V_81 = V_81 ,
} ;
F_8 ( & V_81 -> V_467 ) ;
F_423 ( 0 , ~ 0UL , & V_465 ) ;
F_10 ( & V_81 -> V_467 ) ;
V_437 = V_116 . V_437 ;
V_116 . V_437 = 0 ;
return V_437 ;
}
static int F_424 ( struct V_80 * V_81 )
{
unsigned long V_437 = F_422 ( V_81 ) ;
F_54 ( V_116 . V_118 ) ;
V_116 . V_118 = V_119 ;
return F_379 ( V_437 ) ;
}
static void F_425 ( void )
{
struct V_4 * V_114 = V_116 . V_114 ;
struct V_4 * V_115 = V_116 . V_115 ;
if ( V_116 . V_437 ) {
F_192 ( V_116 . V_115 , V_116 . V_437 ) ;
V_116 . V_437 = 0 ;
}
if ( V_116 . V_468 ) {
F_192 ( V_116 . V_114 , V_116 . V_468 ) ;
V_116 . V_468 = 0 ;
}
if ( V_116 . V_469 ) {
if ( ! F_6 ( V_116 . V_114 ) )
F_157 ( & V_116 . V_114 -> V_113 , V_116 . V_469 ) ;
F_343 ( V_116 . V_114 , V_116 . V_469 ) ;
if ( ! F_6 ( V_116 . V_115 ) )
F_157 ( & V_116 . V_115 -> V_37 , V_116 . V_469 ) ;
F_341 ( V_116 . V_115 , V_116 . V_469 ) ;
F_158 ( & V_116 . V_115 -> V_9 , V_116 . V_469 ) ;
V_116 . V_469 = 0 ;
}
F_144 ( V_114 ) ;
F_144 ( V_115 ) ;
F_426 ( & V_116 . V_121 ) ;
}
static void F_427 ( void )
{
struct V_80 * V_81 = V_116 . V_81 ;
V_116 . V_118 = NULL ;
F_425 () ;
F_91 ( & V_116 . V_35 ) ;
V_116 . V_114 = NULL ;
V_116 . V_115 = NULL ;
V_116 . V_81 = NULL ;
F_92 ( & V_116 . V_35 ) ;
F_428 ( V_81 ) ;
}
static int F_429 ( struct V_470 * V_471 )
{
struct V_7 * V_9 ;
struct V_4 * V_5 = NULL ;
struct V_4 * V_114 ;
struct V_78 * V_472 , * V_26 ;
struct V_80 * V_81 ;
unsigned long V_473 ;
int V_110 = 0 ;
if ( F_2 ( V_1 ) )
return 0 ;
V_26 = NULL ;
F_430 (leader, css, tset) {
F_349 ( V_26 ) ;
V_26 = V_472 ;
V_5 = F_67 ( V_9 ) ;
}
if ( ! V_26 )
return 0 ;
V_473 = F_14 ( V_5 -> V_323 ) ;
if ( ! V_473 )
return 0 ;
V_114 = F_66 ( V_26 ) ;
F_54 ( V_114 == V_5 ) ;
V_81 = F_431 ( V_26 ) ;
if ( ! V_81 )
return 0 ;
if ( V_81 -> V_82 == V_26 ) {
F_54 ( V_116 . V_114 ) ;
F_54 ( V_116 . V_115 ) ;
F_54 ( V_116 . V_437 ) ;
F_54 ( V_116 . V_468 ) ;
F_54 ( V_116 . V_469 ) ;
F_91 ( & V_116 . V_35 ) ;
V_116 . V_81 = V_81 ;
V_116 . V_114 = V_114 ;
V_116 . V_115 = V_5 ;
V_116 . V_13 = V_473 ;
F_92 ( & V_116 . V_35 ) ;
V_110 = F_424 ( V_81 ) ;
if ( V_110 )
F_427 () ;
} else {
F_428 ( V_81 ) ;
}
return V_110 ;
}
static void F_432 ( struct V_470 * V_471 )
{
if ( V_116 . V_115 )
F_427 () ;
}
static int F_433 ( T_15 * V_458 ,
unsigned long V_440 , unsigned long V_459 ,
struct V_460 * V_461 )
{
int V_110 = 0 ;
struct V_438 * V_439 = V_461 -> V_439 ;
T_13 * V_462 ;
T_16 * V_463 ;
enum V_453 V_474 ;
union V_454 V_65 ;
struct V_11 * V_11 ;
V_463 = F_418 ( V_458 , V_439 ) ;
if ( V_463 ) {
if ( V_116 . V_437 < V_273 ) {
F_92 ( V_463 ) ;
return 0 ;
}
V_474 = F_413 ( V_439 , V_440 , * V_458 , & V_65 ) ;
if ( V_474 == V_456 ) {
V_11 = V_65 . V_11 ;
if ( ! F_434 ( V_11 ) ) {
if ( ! F_397 ( V_11 , true ,
V_116 . V_114 , V_116 . V_115 ) ) {
V_116 . V_437 -= V_273 ;
V_116 . V_468 += V_273 ;
}
F_435 ( V_11 ) ;
}
F_411 ( V_11 ) ;
}
F_92 ( V_463 ) ;
return 0 ;
}
if ( F_419 ( V_458 ) )
return 0 ;
V_41:
V_462 = F_420 ( V_439 -> V_464 , V_458 , V_440 , & V_463 ) ;
for (; V_440 != V_459 ; V_440 += V_248 ) {
T_13 V_441 = * ( V_462 ++ ) ;
T_6 V_444 ;
if ( ! V_116 . V_437 )
break;
switch ( F_407 ( V_439 , V_440 , V_441 , & V_65 ) ) {
case V_456 :
V_11 = V_65 . V_11 ;
if ( F_436 ( V_11 ) )
goto V_475;
if ( F_434 ( V_11 ) )
goto V_475;
if ( ! F_397 ( V_11 , false ,
V_116 . V_114 , V_116 . V_115 ) ) {
V_116 . V_437 -- ;
V_116 . V_468 ++ ;
}
F_435 ( V_11 ) ;
V_475:
F_411 ( V_11 ) ;
break;
case V_457 :
V_444 = V_65 . V_444 ;
if ( ! F_234 ( V_444 , V_116 . V_114 , V_116 . V_115 ) ) {
V_116 . V_437 -- ;
V_116 . V_469 ++ ;
}
break;
default:
break;
}
}
F_421 ( V_462 - 1 , V_463 ) ;
F_380 () ;
if ( V_440 != V_459 ) {
V_110 = F_379 ( 1 ) ;
if ( ! V_110 )
goto V_41;
}
return V_110 ;
}
static void F_437 ( void )
{
struct V_460 V_476 = {
. V_466 = F_433 ,
. V_81 = V_116 . V_81 ,
} ;
F_246 () ;
F_65 ( & V_116 . V_114 -> V_200 ) ;
F_299 () ;
V_41:
if ( F_63 ( ! F_438 ( & V_116 . V_81 -> V_467 ) ) ) {
F_425 () ;
F_380 () ;
goto V_41;
}
F_423 ( 0 , ~ 0UL , & V_476 ) ;
F_10 ( & V_116 . V_81 -> V_467 ) ;
F_439 ( & V_116 . V_114 -> V_200 ) ;
}
static void F_440 ( void )
{
if ( V_116 . V_115 ) {
F_437 () ;
F_427 () ;
}
}
static int F_429 ( struct V_470 * V_471 )
{
return 0 ;
}
static void F_432 ( struct V_470 * V_471 )
{
}
static void F_440 ( void )
{
}
static void F_441 ( struct V_7 * V_477 )
{
if ( F_2 ( V_1 ) )
V_6 -> V_91 = true ;
else
V_6 -> V_91 = false ;
}
static V_123 F_442 ( struct V_7 * V_9 ,
struct V_296 * V_297 )
{
struct V_4 * V_5 = F_67 ( V_9 ) ;
return ( V_123 ) F_32 ( & V_5 -> V_37 ) * V_248 ;
}
static int F_443 ( struct V_326 * V_327 , void * V_328 )
{
struct V_4 * V_5 = F_67 ( F_281 ( V_327 ) ) ;
unsigned long V_435 = F_14 ( V_5 -> V_435 ) ;
if ( V_435 == V_336 )
F_444 ( V_327 , L_37 ) ;
else
F_283 ( V_327 , L_38 , ( V_123 ) V_435 * V_248 ) ;
return 0 ;
}
static T_7 F_445 ( struct V_291 * V_292 ,
char * V_293 , T_8 V_294 , T_9 V_295 )
{
struct V_4 * V_5 = F_67 ( F_249 ( V_292 ) ) ;
unsigned long V_435 ;
int V_255 ;
V_293 = F_273 ( V_293 ) ;
V_255 = F_274 ( V_293 , L_39 , & V_435 ) ;
if ( V_255 )
return V_255 ;
V_5 -> V_435 = V_435 ;
return V_294 ;
}
static int F_446 ( struct V_326 * V_327 , void * V_328 )
{
struct V_4 * V_5 = F_67 ( F_281 ( V_327 ) ) ;
unsigned long V_224 = F_14 ( V_5 -> V_224 ) ;
if ( V_224 == V_336 )
F_444 ( V_327 , L_37 ) ;
else
F_283 ( V_327 , L_38 , ( V_123 ) V_224 * V_248 ) ;
return 0 ;
}
static T_7 F_447 ( struct V_291 * V_292 ,
char * V_293 , T_8 V_294 , T_9 V_295 )
{
struct V_4 * V_5 = F_67 ( F_249 ( V_292 ) ) ;
unsigned long V_36 ;
unsigned long V_224 ;
int V_255 ;
V_293 = F_273 ( V_293 ) ;
V_255 = F_274 ( V_293 , L_39 , & V_224 ) ;
if ( V_255 )
return V_255 ;
V_5 -> V_224 = V_224 ;
V_36 = F_32 ( & V_5 -> V_37 ) ;
if ( V_36 > V_224 )
F_174 ( V_5 , V_36 - V_224 ,
V_227 , true ) ;
F_317 ( V_5 ) ;
return V_294 ;
}
static int F_448 ( struct V_326 * V_327 , void * V_328 )
{
struct V_4 * V_5 = F_67 ( F_281 ( V_327 ) ) ;
unsigned long F_179 = F_14 ( V_5 -> V_37 . V_112 ) ;
if ( F_179 == V_336 )
F_444 ( V_327 , L_37 ) ;
else
F_283 ( V_327 , L_38 , ( V_123 ) F_179 * V_248 ) ;
return 0 ;
}
static T_7 F_449 ( struct V_291 * V_292 ,
char * V_293 , T_8 V_294 , T_9 V_295 )
{
struct V_4 * V_5 = F_67 ( F_249 ( V_292 ) ) ;
unsigned int V_478 = V_231 ;
bool V_237 = false ;
unsigned long F_179 ;
int V_255 ;
V_293 = F_273 ( V_293 ) ;
V_255 = F_274 ( V_293 , L_39 , & F_179 ) ;
if ( V_255 )
return V_255 ;
F_450 ( & V_5 -> V_37 . V_112 , F_179 ) ;
for (; ; ) {
unsigned long V_36 = F_32 ( & V_5 -> V_37 ) ;
if ( V_36 <= F_179 )
break;
if ( F_238 ( V_119 ) ) {
V_255 = - V_283 ;
break;
}
if ( ! V_237 ) {
F_162 ( V_5 ) ;
V_237 = true ;
continue;
}
if ( V_478 ) {
if ( ! F_174 ( V_5 , V_36 - F_179 ,
V_227 , true ) )
V_478 -- ;
continue;
}
F_173 ( V_5 , V_247 , 1 ) ;
if ( ! F_108 ( V_5 , V_227 , 0 ) )
break;
}
F_317 ( V_5 ) ;
return V_294 ;
}
static int F_451 ( struct V_326 * V_327 , void * V_328 )
{
struct V_4 * V_5 = F_67 ( F_281 ( V_327 ) ) ;
F_283 ( V_327 , L_40 , F_46 ( V_5 , V_479 ) ) ;
F_283 ( V_327 , L_41 , F_46 ( V_5 , V_225 ) ) ;
F_283 ( V_327 , L_42 , F_46 ( V_5 , V_243 ) ) ;
F_283 ( V_327 , L_43 , F_46 ( V_5 , V_247 ) ) ;
return 0 ;
}
static int F_452 ( struct V_326 * V_327 , void * V_328 )
{
struct V_4 * V_5 = F_67 ( F_281 ( V_327 ) ) ;
unsigned long V_47 [ V_301 ] ;
unsigned long V_50 [ V_302 ] ;
int V_100 ;
F_252 ( V_5 , V_47 ) ;
F_253 ( V_5 , V_50 ) ;
F_283 ( V_327 , L_44 ,
( V_123 ) V_47 [ V_52 ] * V_248 ) ;
F_283 ( V_327 , L_45 ,
( V_123 ) V_47 [ V_53 ] * V_248 ) ;
F_283 ( V_327 , L_46 ,
( V_123 ) V_47 [ V_480 ] * 1024 ) ;
F_283 ( V_327 , L_47 ,
( V_123 ) ( V_47 [ V_481 ] +
V_47 [ V_482 ] ) * V_248 ) ;
F_283 ( V_327 , L_48 ,
( V_123 ) V_47 [ V_483 ] * V_248 ) ;
F_283 ( V_327 , L_49 ,
( V_123 ) V_47 [ V_452 ] * V_248 ) ;
F_283 ( V_327 , L_50 ,
( V_123 ) V_47 [ V_384 ] * V_248 ) ;
F_283 ( V_327 , L_51 ,
( V_123 ) V_47 [ V_385 ] * V_248 ) ;
for ( V_100 = 0 ; V_100 < V_129 ; V_100 ++ ) {
struct V_4 * V_333 ;
unsigned long V_45 = 0 ;
F_104 (mi, memcg)
V_45 += F_57 ( V_333 , F_56 ( V_100 ) ) ;
F_283 ( V_327 , L_52 ,
V_130 [ V_100 ] , ( V_123 ) V_45 * V_248 ) ;
}
F_283 ( V_327 , L_53 ,
( V_123 ) V_47 [ V_481 ] * V_248 ) ;
F_283 ( V_327 , L_54 ,
( V_123 ) V_47 [ V_482 ] * V_248 ) ;
F_283 ( V_327 , L_55 ,
V_50 [ V_484 ] ) ;
F_283 ( V_327 , L_56 ,
V_50 [ V_485 ] ) ;
return 0 ;
}
bool F_453 ( struct V_4 * V_83 , struct V_4 * V_5 )
{
if ( F_72 () )
return false ;
if ( V_5 == V_6 )
return false ;
if ( F_32 ( & V_5 -> V_37 ) >= V_5 -> V_435 )
return false ;
while ( V_5 != V_83 ) {
V_5 = F_15 ( V_5 ) ;
if ( V_5 == V_6 )
break;
if ( F_32 ( & V_5 -> V_37 ) >= V_5 -> V_435 )
return false ;
}
return true ;
}
int F_454 ( struct V_11 * V_11 , struct V_80 * V_81 ,
T_3 V_136 , struct V_4 * * V_486 ,
bool V_51 )
{
struct V_4 * V_5 = NULL ;
unsigned int V_36 = V_51 ? F_398 ( V_11 ) : 1 ;
int V_110 = 0 ;
if ( F_72 () )
goto V_92;
if ( F_455 ( V_11 ) ) {
F_50 ( ! F_456 ( V_11 ) , V_11 ) ;
if ( V_11 -> V_4 )
goto V_92;
if ( V_2 ) {
T_6 V_444 = { . V_45 = F_457 ( V_11 ) , } ;
unsigned short V_254 = F_412 ( V_444 ) ;
F_13 () ;
V_5 = F_348 ( V_254 ) ;
if ( V_5 && ! F_39 ( & V_5 -> V_9 ) )
V_5 = NULL ;
F_17 () ;
}
}
if ( ! V_5 )
V_5 = F_69 ( V_81 ) ;
V_110 = F_178 ( V_5 , V_136 , V_36 ) ;
F_76 ( & V_5 -> V_9 ) ;
V_92:
* V_486 = V_5 ;
return V_110 ;
}
void F_458 ( struct V_11 * V_11 , struct V_4 * V_5 ,
bool V_253 , bool V_51 )
{
unsigned int V_36 = V_51 ? F_398 ( V_11 ) : 1 ;
F_50 ( ! V_11 -> V_446 , V_11 ) ;
F_50 ( F_196 ( V_11 ) && ! V_253 , V_11 ) ;
if ( F_72 () )
return;
if ( ! V_5 )
return;
F_203 ( V_11 , V_5 , V_253 ) ;
F_404 () ;
F_47 ( V_5 , V_11 , V_51 , V_36 ) ;
F_62 ( V_5 , V_11 ) ;
F_405 () ;
if ( F_1 () && F_455 ( V_11 ) ) {
T_6 V_275 = { . V_45 = F_457 (page) } ;
F_459 ( V_275 ) ;
}
}
void F_460 ( struct V_11 * V_11 , struct V_4 * V_5 ,
bool V_51 )
{
unsigned int V_36 = V_51 ? F_398 ( V_11 ) : 1 ;
if ( F_72 () )
return;
if ( ! V_5 )
return;
F_192 ( V_5 , V_36 ) ;
}
static void F_461 ( struct V_4 * V_5 , unsigned long V_487 ,
unsigned long V_488 , unsigned long V_489 ,
unsigned long V_490 , unsigned long V_491 ,
struct V_11 * V_492 )
{
unsigned long V_36 = V_488 + V_489 + V_491 ;
unsigned long V_13 ;
if ( ! F_6 ( V_5 ) ) {
F_157 ( & V_5 -> V_37 , V_36 ) ;
if ( F_1 () )
F_157 ( & V_5 -> V_113 , V_36 ) ;
if ( ! F_2 ( V_1 ) && V_491 )
F_157 ( & V_5 -> V_125 , V_491 ) ;
F_144 ( V_5 ) ;
}
F_153 ( V_13 ) ;
F_231 ( V_5 -> V_47 -> V_48 [ V_52 ] , V_488 ) ;
F_231 ( V_5 -> V_47 -> V_48 [ V_53 ] , V_489 ) ;
F_231 ( V_5 -> V_47 -> V_48 [ V_54 ] , V_490 ) ;
F_49 ( V_5 -> V_47 -> V_50 [ V_56 ] , V_487 ) ;
F_49 ( V_5 -> V_47 -> V_57 , V_36 ) ;
F_62 ( V_5 , V_492 ) ;
F_155 ( V_13 ) ;
if ( ! F_6 ( V_5 ) )
F_158 ( & V_5 -> V_9 , V_36 ) ;
}
static void F_462 ( struct V_373 * V_493 )
{
struct V_4 * V_5 = NULL ;
unsigned long V_488 = 0 ;
unsigned long V_489 = 0 ;
unsigned long V_490 = 0 ;
unsigned long V_491 = 0 ;
unsigned long V_487 = 0 ;
struct V_373 * V_66 ;
struct V_11 * V_11 ;
V_66 = V_493 -> V_66 ;
do {
V_11 = F_463 ( V_66 , struct V_11 , V_61 ) ;
V_66 = V_11 -> V_61 . V_66 ;
F_50 ( F_196 ( V_11 ) , V_11 ) ;
F_50 ( F_464 ( V_11 ) , V_11 ) ;
if ( ! V_11 -> V_4 )
continue;
if ( V_5 != V_11 -> V_4 ) {
if ( V_5 ) {
F_461 ( V_5 , V_487 , V_488 , V_489 ,
V_490 , V_491 , V_11 ) ;
V_487 = V_488 = V_489 =
V_490 = V_491 = 0 ;
}
V_5 = V_11 -> V_4 ;
}
if ( ! F_228 ( V_11 ) ) {
unsigned int V_36 = 1 ;
if ( F_51 ( V_11 ) ) {
V_36 <<= F_465 ( V_11 ) ;
V_490 += V_36 ;
}
if ( F_48 ( V_11 ) )
V_488 += V_36 ;
else
V_489 += V_36 ;
V_487 ++ ;
} else {
V_491 += 1 << F_465 ( V_11 ) ;
F_229 ( V_11 ) ;
}
V_11 -> V_4 = NULL ;
} while ( V_66 != V_493 );
if ( V_5 )
F_461 ( V_5 , V_487 , V_488 , V_489 ,
V_490 , V_491 , V_11 ) ;
}
void F_466 ( struct V_11 * V_11 )
{
if ( F_72 () )
return;
if ( ! V_11 -> V_4 )
return;
F_148 ( & V_11 -> V_61 ) ;
F_462 ( & V_11 -> V_61 ) ;
}
void F_467 ( struct V_373 * V_493 )
{
if ( F_72 () )
return;
if ( ! F_81 ( V_493 ) )
F_462 ( V_493 ) ;
}
void F_468 ( struct V_11 * V_494 , struct V_11 * V_495 )
{
struct V_4 * V_5 ;
unsigned int V_36 ;
bool V_51 ;
unsigned long V_13 ;
F_50 ( ! F_456 ( V_494 ) , V_494 ) ;
F_50 ( ! F_456 ( V_495 ) , V_495 ) ;
F_50 ( F_48 ( V_494 ) != F_48 ( V_495 ) , V_495 ) ;
F_50 ( F_51 ( V_494 ) != F_51 ( V_495 ) ,
V_495 ) ;
if ( F_72 () )
return;
if ( V_495 -> V_4 )
return;
V_5 = V_494 -> V_4 ;
if ( ! V_5 )
return;
V_51 = F_51 ( V_495 ) ;
V_36 = V_51 ? F_398 ( V_495 ) : 1 ;
F_187 ( & V_5 -> V_37 , V_36 ) ;
if ( F_1 () )
F_187 ( & V_5 -> V_113 , V_36 ) ;
F_188 ( & V_5 -> V_9 , V_36 ) ;
F_203 ( V_495 , V_5 , false ) ;
F_153 ( V_13 ) ;
F_47 ( V_5 , V_495 , V_51 , V_36 ) ;
F_62 ( V_5 , V_495 ) ;
F_155 ( V_13 ) ;
}
void F_469 ( struct V_496 * V_497 )
{
struct V_4 * V_5 ;
if ( V_497 -> V_498 ) {
F_260 ( F_6 ( V_497 -> V_498 ) ) ;
F_86 ( & V_497 -> V_498 -> V_9 ) ;
return;
}
F_13 () ;
V_5 = F_66 ( V_119 ) ;
if ( V_5 == V_6 )
goto V_92;
if ( ! F_2 ( V_1 ) && ! V_5 -> V_321 )
goto V_92;
if ( F_39 ( & V_5 -> V_9 ) )
V_497 -> V_498 = V_5 ;
V_92:
F_17 () ;
}
void F_470 ( struct V_496 * V_497 )
{
F_269 ( ! V_497 -> V_498 ) ;
F_76 ( & V_497 -> V_498 -> V_9 ) ;
}
bool F_471 ( struct V_4 * V_5 , unsigned int V_36 )
{
T_3 V_136 = V_227 ;
if ( ! F_2 ( V_1 ) ) {
struct V_233 * V_428 ;
if ( F_180 ( & V_5 -> V_307 , V_36 , & V_428 ) ) {
V_5 -> V_499 = 0 ;
return true ;
}
F_187 ( & V_5 -> V_307 , V_36 ) ;
V_5 -> V_499 = 1 ;
return false ;
}
if ( F_472 () )
V_136 = V_265 ;
F_233 ( V_5 -> V_47 -> V_48 [ V_483 ] , V_36 ) ;
if ( F_178 ( V_5 , V_136 , V_36 ) == 0 )
return true ;
F_178 ( V_5 , V_136 | V_246 , V_36 ) ;
return false ;
}
void F_473 ( struct V_4 * V_5 , unsigned int V_36 )
{
if ( ! F_2 ( V_1 ) ) {
F_157 ( & V_5 -> V_307 , V_36 ) ;
return;
}
F_474 ( V_5 -> V_47 -> V_48 [ V_483 ] , V_36 ) ;
F_157 ( & V_5 -> V_37 , V_36 ) ;
F_158 ( & V_5 -> V_9 , V_36 ) ;
}
static int T_17 F_475 ( char * V_500 )
{
char * V_501 ;
while ( ( V_501 = F_476 ( & V_500 , L_57 ) ) != NULL ) {
if ( ! * V_501 )
continue;
if ( ! strcmp ( V_501 , L_58 ) )
V_434 = true ;
if ( ! strcmp ( V_501 , L_59 ) )
V_315 = true ;
}
return 0 ;
}
static int T_17 F_477 ( void )
{
int V_46 , V_162 ;
F_478 ( F_171 , 0 ) ;
F_44 (cpu)
F_217 ( & F_479 ( & V_207 , V_46 ) -> V_215 ,
F_159 ) ;
F_35 (node) {
struct V_19 * V_502 ;
V_502 = F_354 ( sizeof( * V_502 ) , V_227 ,
F_480 ( V_162 ) ? V_162 : V_503 ) ;
V_502 -> V_27 = V_504 ;
F_363 ( & V_502 -> V_35 ) ;
V_20 . V_21 [ V_162 ] = V_502 ;
}
return 0 ;
}
static struct V_4 * F_481 ( struct V_4 * V_5 )
{
while ( ! F_482 ( & V_5 -> V_254 . V_423 ) ) {
if ( F_349 ( V_5 == V_6 ) ) {
F_54 ( 1 ) ;
break;
}
V_5 = F_15 ( V_5 ) ;
if ( ! V_5 )
V_5 = V_6 ;
}
return V_5 ;
}
void F_483 ( struct V_11 * V_11 , T_6 V_275 )
{
struct V_4 * V_5 , * V_505 ;
unsigned short V_506 ;
F_50 ( F_196 ( V_11 ) , V_11 ) ;
F_50 ( F_464 ( V_11 ) , V_11 ) ;
if ( ! F_1 () )
return;
V_5 = V_11 -> V_4 ;
if ( ! V_5 )
return;
V_505 = F_481 ( V_5 ) ;
V_506 = F_484 ( V_275 , F_235 ( V_505 ) ) ;
F_50 ( V_506 , V_11 ) ;
F_232 ( V_505 , true ) ;
V_11 -> V_4 = NULL ;
if ( ! F_6 ( V_5 ) )
F_157 ( & V_5 -> V_37 , 1 ) ;
if ( V_5 != V_505 ) {
if ( ! F_6 ( V_505 ) )
F_187 ( & V_505 -> V_113 , 1 ) ;
F_157 ( & V_5 -> V_113 , 1 ) ;
}
F_54 ( ! F_485 () ) ;
F_47 ( V_5 , V_11 , false , - 1 ) ;
F_62 ( V_5 , V_11 ) ;
if ( ! F_6 ( V_5 ) )
F_76 ( & V_5 -> V_9 ) ;
}
int F_486 ( struct V_11 * V_11 , T_6 V_275 )
{
struct V_4 * V_5 ;
struct V_233 * V_234 ;
unsigned short V_506 ;
if ( ! F_2 ( V_1 ) || ! V_2 )
return 0 ;
V_5 = V_11 -> V_4 ;
if ( ! V_5 )
return 0 ;
V_5 = F_481 ( V_5 ) ;
if ( ! F_6 ( V_5 ) &&
! F_180 ( & V_5 -> V_134 , 1 , & V_234 ) ) {
F_347 ( V_5 ) ;
return - V_249 ;
}
V_506 = F_484 ( V_275 , F_235 ( V_5 ) ) ;
F_50 ( V_506 , V_11 ) ;
F_232 ( V_5 , true ) ;
return 0 ;
}
void F_459 ( T_6 V_275 )
{
struct V_4 * V_5 ;
unsigned short V_254 ;
if ( ! V_2 )
return;
V_254 = F_484 ( V_275 , 0 ) ;
F_13 () ;
V_5 = F_348 ( V_254 ) ;
if ( V_5 ) {
if ( ! F_6 ( V_5 ) ) {
if ( F_2 ( V_1 ) )
F_157 ( & V_5 -> V_134 , 1 ) ;
else
F_157 ( & V_5 -> V_113 , 1 ) ;
}
F_232 ( V_5 , false ) ;
F_347 ( V_5 ) ;
}
F_17 () ;
}
long F_487 ( struct V_4 * V_5 )
{
long V_507 = F_488 () ;
if ( ! V_2 || ! F_2 ( V_1 ) )
return V_507 ;
for (; V_5 != V_6 ; V_5 = F_15 ( V_5 ) )
V_507 = F_489 ( long , V_507 ,
F_14 ( V_5 -> V_134 . V_112 ) -
F_32 ( & V_5 -> V_134 ) ) ;
return V_507 ;
}
bool F_490 ( struct V_11 * V_11 )
{
struct V_4 * V_5 ;
F_50 ( ! F_456 ( V_11 ) , V_11 ) ;
if ( F_491 () )
return true ;
if ( ! V_2 || ! F_2 ( V_1 ) )
return false ;
V_5 = V_11 -> V_4 ;
if ( ! V_5 )
return false ;
for (; V_5 != V_6 ; V_5 = F_15 ( V_5 ) )
if ( F_32 ( & V_5 -> V_134 ) * 2 >= V_5 -> V_134 . V_112 )
return true ;
return false ;
}
static int T_17 F_492 ( char * V_500 )
{
if ( ! strcmp ( V_500 , L_60 ) )
V_508 = 1 ;
else if ( ! strcmp ( V_500 , L_61 ) )
V_508 = 0 ;
return 1 ;
}
static V_123 F_493 ( struct V_7 * V_9 ,
struct V_296 * V_297 )
{
struct V_4 * V_5 = F_67 ( V_9 ) ;
return ( V_123 ) F_32 ( & V_5 -> V_134 ) * V_248 ;
}
static int F_494 ( struct V_326 * V_327 , void * V_328 )
{
struct V_4 * V_5 = F_67 ( F_281 ( V_327 ) ) ;
unsigned long F_179 = F_14 ( V_5 -> V_134 . V_112 ) ;
if ( F_179 == V_336 )
F_444 ( V_327 , L_37 ) ;
else
F_283 ( V_327 , L_38 , ( V_123 ) F_179 * V_248 ) ;
return 0 ;
}
static T_7 F_495 ( struct V_291 * V_292 ,
char * V_293 , T_8 V_294 , T_9 V_295 )
{
struct V_4 * V_5 = F_67 ( F_249 ( V_292 ) ) ;
unsigned long F_179 ;
int V_255 ;
V_293 = F_273 ( V_293 ) ;
V_255 = F_274 ( V_293 , L_39 , & F_179 ) ;
if ( V_255 )
return V_255 ;
F_109 ( & V_284 ) ;
V_255 = F_239 ( & V_5 -> V_134 , F_179 ) ;
F_123 ( & V_284 ) ;
if ( V_255 )
return V_255 ;
return V_294 ;
}
static int T_17 F_496 ( void )
{
if ( ! F_72 () && V_508 ) {
V_2 = 1 ;
F_269 ( F_497 ( & V_1 ,
V_509 ) ) ;
F_269 ( F_498 ( & V_1 ,
V_510 ) ) ;
}
return 0 ;
}
