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
static struct V_11 *
F_11 ( struct V_4 * V_5 , struct V_12 * V_12 )
{
int V_13 = F_12 ( V_12 ) ;
int V_14 = F_13 ( V_12 ) ;
return & V_5 -> V_15 [ V_13 ] -> V_16 [ V_14 ] ;
}
struct V_7 * F_14 ( struct V_17 * V_17 )
{
struct V_4 * V_5 ;
V_5 = V_17 -> V_4 ;
if ( ! V_5 || ! F_2 ( V_1 ) )
V_5 = V_6 ;
return & V_5 -> V_9 ;
}
T_1 F_15 ( struct V_17 * V_17 )
{
struct V_4 * V_5 ;
unsigned long V_18 = 0 ;
F_16 () ;
V_5 = F_17 ( V_17 -> V_4 ) ;
while ( V_5 && ! ( V_5 -> V_9 . V_19 & V_20 ) )
V_5 = F_18 ( V_5 ) ;
if ( V_5 )
V_18 = F_19 ( V_5 -> V_9 . V_21 ) ;
F_20 () ;
return V_18 ;
}
static struct V_11 *
F_21 ( struct V_4 * V_5 , struct V_17 * V_17 )
{
int V_13 = F_22 ( V_17 ) ;
int V_14 = F_23 ( V_17 ) ;
return & V_5 -> V_15 [ V_13 ] -> V_16 [ V_14 ] ;
}
static struct V_22 *
F_24 ( int V_13 , int V_14 )
{
return & V_23 . V_24 [ V_13 ] -> V_25 [ V_14 ] ;
}
static struct V_22 *
F_25 ( struct V_17 * V_17 )
{
int V_13 = F_22 ( V_17 ) ;
int V_14 = F_23 ( V_17 ) ;
return & V_23 . V_24 [ V_13 ] -> V_25 [ V_14 ] ;
}
static void F_26 ( struct V_11 * V_26 ,
struct V_22 * V_27 ,
unsigned long V_28 )
{
struct V_29 * * V_30 = & V_27 -> V_31 . V_29 ;
struct V_29 * V_32 = NULL ;
struct V_11 * V_33 ;
if ( V_26 -> V_34 )
return;
V_26 -> V_35 = V_28 ;
if ( ! V_26 -> V_35 )
return;
while ( * V_30 ) {
V_32 = * V_30 ;
V_33 = F_27 ( V_32 , struct V_11 ,
V_36 ) ;
if ( V_26 -> V_35 < V_33 -> V_35 )
V_30 = & ( * V_30 ) -> V_37 ;
else if ( V_26 -> V_35 >= V_33 -> V_35 )
V_30 = & ( * V_30 ) -> V_38 ;
}
F_28 ( & V_26 -> V_36 , V_32 , V_30 ) ;
F_29 ( & V_26 -> V_36 , & V_27 -> V_31 ) ;
V_26 -> V_34 = true ;
}
static void F_30 ( struct V_11 * V_26 ,
struct V_22 * V_27 )
{
if ( ! V_26 -> V_34 )
return;
F_31 ( & V_26 -> V_36 , & V_27 -> V_31 ) ;
V_26 -> V_34 = false ;
}
static void F_32 ( struct V_11 * V_26 ,
struct V_22 * V_27 )
{
unsigned long V_19 ;
F_33 ( & V_27 -> V_39 , V_19 ) ;
F_30 ( V_26 , V_27 ) ;
F_34 ( & V_27 -> V_39 , V_19 ) ;
}
static unsigned long F_35 ( struct V_4 * V_5 )
{
unsigned long V_40 = F_36 ( & V_5 -> V_41 ) ;
unsigned long V_42 = F_17 ( V_5 -> V_42 ) ;
unsigned long V_43 = 0 ;
if ( V_40 > V_42 )
V_43 = V_40 - V_42 ;
return V_43 ;
}
static void F_37 ( struct V_4 * V_5 , struct V_17 * V_17 )
{
unsigned long V_43 ;
struct V_11 * V_26 ;
struct V_22 * V_27 ;
V_27 = F_25 ( V_17 ) ;
for (; V_5 ; V_5 = F_18 ( V_5 ) ) {
V_26 = F_21 ( V_5 , V_17 ) ;
V_43 = F_35 ( V_5 ) ;
if ( V_43 || V_26 -> V_34 ) {
unsigned long V_19 ;
F_33 ( & V_27 -> V_39 , V_19 ) ;
if ( V_26 -> V_34 )
F_30 ( V_26 , V_27 ) ;
F_26 ( V_26 , V_27 , V_43 ) ;
F_34 ( & V_27 -> V_39 , V_19 ) ;
}
}
}
static void F_38 ( struct V_4 * V_5 )
{
struct V_22 * V_27 ;
struct V_11 * V_26 ;
int V_13 , V_14 ;
F_39 (nid) {
for ( V_14 = 0 ; V_14 < V_44 ; V_14 ++ ) {
V_26 = & V_5 -> V_15 [ V_13 ] -> V_16 [ V_14 ] ;
V_27 = F_24 ( V_13 , V_14 ) ;
F_32 ( V_26 , V_27 ) ;
}
}
}
static struct V_11 *
F_40 ( struct V_22 * V_27 )
{
struct V_29 * V_45 = NULL ;
struct V_11 * V_26 ;
V_46:
V_26 = NULL ;
V_45 = F_41 ( & V_27 -> V_31 ) ;
if ( ! V_45 )
goto V_47;
V_26 = F_27 ( V_45 , struct V_11 , V_36 ) ;
F_30 ( V_26 , V_27 ) ;
if ( ! F_35 ( V_26 -> V_5 ) ||
! F_42 ( & V_26 -> V_5 -> V_9 ) )
goto V_46;
V_47:
return V_26 ;
}
static struct V_11 *
F_43 ( struct V_22 * V_27 )
{
struct V_11 * V_26 ;
F_44 ( & V_27 -> V_39 ) ;
V_26 = F_40 ( V_27 ) ;
F_45 ( & V_27 -> V_39 ) ;
return V_26 ;
}
static unsigned long
F_46 ( struct V_4 * V_5 , enum V_48 V_49 )
{
long V_50 = 0 ;
int V_51 ;
F_47 (cpu)
V_50 += F_48 ( V_5 -> V_52 -> V_53 [ V_49 ] , V_51 ) ;
if ( V_50 < 0 )
V_50 = 0 ;
return V_50 ;
}
static unsigned long F_49 ( struct V_4 * V_5 ,
enum V_54 V_49 )
{
unsigned long V_50 = 0 ;
int V_51 ;
F_47 (cpu)
V_50 += F_48 ( V_5 -> V_52 -> V_55 [ V_49 ] , V_51 ) ;
return V_50 ;
}
static void F_50 ( struct V_4 * V_5 ,
struct V_17 * V_17 ,
bool V_56 , int V_40 )
{
if ( F_51 ( V_17 ) )
F_52 ( V_5 -> V_52 -> V_53 [ V_57 ] ,
V_40 ) ;
else
F_52 ( V_5 -> V_52 -> V_53 [ V_58 ] ,
V_40 ) ;
if ( V_56 ) {
F_53 ( ! F_54 ( V_17 ) , V_17 ) ;
F_52 ( V_5 -> V_52 -> V_53 [ V_59 ] ,
V_40 ) ;
}
if ( V_40 > 0 )
F_55 ( V_5 -> V_52 -> V_55 [ V_60 ] ) ;
else {
F_55 ( V_5 -> V_52 -> V_55 [ V_61 ] ) ;
V_40 = - V_40 ;
}
F_52 ( V_5 -> V_52 -> V_62 , V_40 ) ;
}
unsigned long F_56 ( struct V_4 * V_5 ,
int V_13 , unsigned int V_63 )
{
unsigned long V_64 = 0 ;
int V_14 ;
F_57 ( ( unsigned ) V_13 >= V_65 ) ;
for ( V_14 = 0 ; V_14 < V_44 ; V_14 ++ ) {
struct V_11 * V_26 ;
enum V_66 V_67 ;
F_58 (lru) {
if ( ! ( F_59 ( V_67 ) & V_63 ) )
continue;
V_26 = & V_5 -> V_15 [ V_13 ] -> V_16 [ V_14 ] ;
V_64 += V_26 -> V_68 [ V_67 ] ;
}
}
return V_64 ;
}
static unsigned long F_60 ( struct V_4 * V_5 ,
unsigned int V_63 )
{
unsigned long V_64 = 0 ;
int V_13 ;
F_61 (nid, N_MEMORY)
V_64 += F_56 ( V_5 , V_13 , V_63 ) ;
return V_64 ;
}
static bool F_62 ( struct V_4 * V_5 ,
enum V_69 V_70 )
{
unsigned long V_50 , V_71 ;
V_50 = F_63 ( V_5 -> V_52 -> V_62 ) ;
V_71 = F_63 ( V_5 -> V_52 -> V_72 [ V_70 ] ) ;
if ( ( long ) V_71 - ( long ) V_50 < 0 ) {
switch ( V_70 ) {
case V_73 :
V_71 = V_50 + V_74 ;
break;
case V_75 :
V_71 = V_50 + V_76 ;
break;
case V_77 :
V_71 = V_50 + V_78 ;
break;
default:
break;
}
F_64 ( V_5 -> V_52 -> V_72 [ V_70 ] , V_71 ) ;
return true ;
}
return false ;
}
static void F_65 ( struct V_4 * V_5 , struct V_17 * V_17 )
{
if ( F_66 ( F_62 ( V_5 ,
V_73 ) ) ) {
bool V_79 ;
bool T_2 V_80 ;
V_79 = F_62 ( V_5 ,
V_75 ) ;
#if V_81 > 1
T_2 = F_62 ( V_5 ,
V_77 ) ;
#endif
F_67 ( V_5 ) ;
if ( F_66 ( V_79 ) )
F_37 ( V_5 , V_17 ) ;
#if V_81 > 1
if ( F_66 ( T_2 ) )
F_68 ( & V_5 -> V_82 ) ;
#endif
}
}
struct V_4 * F_69 ( struct V_83 * V_30 )
{
if ( F_66 ( ! V_30 ) )
return NULL ;
return F_70 ( F_71 ( V_30 , V_84 ) ) ;
}
static struct V_4 * F_72 ( struct V_85 * V_86 )
{
struct V_4 * V_5 = NULL ;
F_16 () ;
do {
if ( F_66 ( ! V_86 ) )
V_5 = V_6 ;
else {
V_5 = F_69 ( F_73 ( V_86 -> V_87 ) ) ;
if ( F_66 ( ! V_5 ) )
V_5 = V_6 ;
}
} while ( ! F_42 ( & V_5 -> V_9 ) );
F_20 () ;
return V_5 ;
}
struct V_4 * F_74 ( struct V_4 * V_88 ,
struct V_4 * V_89 ,
struct V_90 * V_91 )
{
struct V_92 * V_93 ( V_94 ) ;
struct V_7 * V_9 = NULL ;
struct V_4 * V_5 = NULL ;
struct V_4 * V_95 = NULL ;
if ( F_75 () )
return NULL ;
if ( ! V_88 )
V_88 = V_6 ;
if ( V_89 && ! V_91 )
V_95 = V_89 ;
if ( ! V_88 -> V_96 && V_88 != V_6 ) {
if ( V_89 )
goto V_97;
return V_88 ;
}
F_16 () ;
if ( V_91 ) {
struct V_11 * V_26 ;
V_26 = F_11 ( V_88 , V_91 -> V_12 ) ;
V_94 = & V_26 -> V_94 [ V_91 -> V_98 ] ;
if ( V_89 && V_91 -> V_99 != V_94 -> V_99 )
goto V_100;
while ( 1 ) {
V_95 = F_17 ( V_94 -> V_101 ) ;
if ( ! V_95 || F_76 ( & V_95 -> V_9 ) )
break;
( void ) F_77 ( & V_94 -> V_101 , V_95 , NULL ) ;
}
}
if ( V_95 )
V_9 = & V_95 -> V_9 ;
for (; ; ) {
V_9 = F_78 ( V_9 , & V_88 -> V_9 ) ;
if ( ! V_9 ) {
if ( ! V_89 )
continue;
break;
}
V_5 = F_70 ( V_9 ) ;
if ( V_9 == & V_88 -> V_9 )
break;
if ( F_76 ( V_9 ) )
break;
V_5 = NULL ;
}
if ( V_91 ) {
( void ) F_77 ( & V_94 -> V_101 , V_95 , V_5 ) ;
if ( V_95 )
F_79 ( & V_95 -> V_9 ) ;
if ( ! V_5 )
V_94 -> V_99 ++ ;
else if ( ! V_89 )
V_91 -> V_99 = V_94 -> V_99 ;
}
V_100:
F_20 () ;
V_97:
if ( V_89 && V_89 != V_88 )
F_79 ( & V_89 -> V_9 ) ;
return V_5 ;
}
void F_80 ( struct V_4 * V_88 ,
struct V_4 * V_89 )
{
if ( ! V_88 )
V_88 = V_6 ;
if ( V_89 && V_89 != V_88 )
F_79 ( & V_89 -> V_9 ) ;
}
static void F_81 ( struct V_4 * V_102 )
{
struct V_4 * V_5 = V_102 ;
struct V_92 * V_94 ;
struct V_11 * V_26 ;
int V_13 , V_14 ;
int V_103 ;
while ( ( V_5 = F_18 ( V_5 ) ) ) {
F_39 (nid) {
for ( V_14 = 0 ; V_14 < V_44 ; V_14 ++ ) {
V_26 = & V_5 -> V_15 [ V_13 ] -> V_16 [ V_14 ] ;
for ( V_103 = 0 ; V_103 <= V_104 ; V_103 ++ ) {
V_94 = & V_26 -> V_94 [ V_103 ] ;
F_77 ( & V_94 -> V_101 ,
V_102 , NULL ) ;
}
}
}
}
}
struct V_105 * F_82 ( struct V_12 * V_12 ,
struct V_4 * V_5 )
{
struct V_11 * V_26 ;
struct V_105 * V_105 ;
if ( F_75 () ) {
V_105 = & V_12 -> V_105 ;
goto V_97;
}
V_26 = F_11 ( V_5 , V_12 ) ;
V_105 = & V_26 -> V_105 ;
V_97:
if ( F_66 ( V_105 -> V_12 != V_12 ) )
V_105 -> V_12 = V_12 ;
return V_105 ;
}
struct V_105 * F_83 ( struct V_17 * V_17 , struct V_12 * V_12 )
{
struct V_11 * V_26 ;
struct V_4 * V_5 ;
struct V_105 * V_105 ;
if ( F_75 () ) {
V_105 = & V_12 -> V_105 ;
goto V_97;
}
V_5 = V_17 -> V_4 ;
if ( ! V_5 )
V_5 = V_6 ;
V_26 = F_21 ( V_5 , V_17 ) ;
V_105 = & V_26 -> V_105 ;
V_97:
if ( F_66 ( V_105 -> V_12 != V_12 ) )
V_105 -> V_12 = V_12 ;
return V_105 ;
}
void F_84 ( struct V_105 * V_105 , enum V_66 V_67 ,
int V_40 )
{
struct V_11 * V_26 ;
unsigned long * V_68 ;
long V_106 ;
bool V_107 ;
F_85 ( V_105 , V_67 , V_40 ) ;
if ( F_75 () )
return;
V_26 = F_5 ( V_105 , struct V_11 , V_105 ) ;
V_68 = V_26 -> V_68 + V_67 ;
V_107 = F_86 ( V_105 -> V_108 + V_67 ) ;
if ( V_40 < 0 )
* V_68 += V_40 ;
V_106 = * V_68 ;
if ( F_87 ( V_106 < 0 || V_107 != ! V_106 ,
L_1 ,
V_109 , V_105 , V_67 , V_40 , V_106 , V_107 ? L_2 : L_3 ) ) {
F_57 ( 1 ) ;
* V_68 = 0 ;
}
if ( V_40 > 0 )
* V_68 += V_40 ;
}
bool F_88 ( struct V_83 * V_110 , struct V_4 * V_5 )
{
struct V_4 * V_111 ;
struct V_83 * V_30 ;
bool V_112 ;
V_30 = F_89 ( V_110 ) ;
if ( V_30 ) {
V_111 = F_72 ( V_30 -> V_86 ) ;
F_90 ( V_30 ) ;
} else {
F_16 () ;
V_111 = F_69 ( V_110 ) ;
F_91 ( & V_111 -> V_9 ) ;
F_20 () ;
}
V_112 = F_92 ( V_111 , V_5 ) ;
F_79 ( & V_111 -> V_9 ) ;
return V_112 ;
}
static unsigned long F_93 ( struct V_4 * V_5 )
{
unsigned long V_113 = 0 ;
unsigned long V_53 ;
unsigned long V_114 ;
V_53 = F_36 ( & V_5 -> V_41 ) ;
V_114 = F_17 ( V_5 -> V_41 . V_114 ) ;
if ( V_53 < V_114 )
V_113 = V_114 - V_53 ;
if ( F_1 () ) {
V_53 = F_36 ( & V_5 -> V_115 ) ;
V_114 = F_17 ( V_5 -> V_115 . V_114 ) ;
if ( V_53 <= V_114 )
V_113 = F_94 ( V_113 , V_114 - V_53 ) ;
else
V_113 = 0 ;
}
return V_113 ;
}
static bool F_95 ( struct V_4 * V_5 )
{
struct V_4 * V_116 ;
struct V_4 * V_117 ;
bool V_112 = false ;
F_96 ( & V_118 . V_39 ) ;
V_116 = V_118 . V_116 ;
V_117 = V_118 . V_117 ;
if ( ! V_116 )
goto V_119;
V_112 = F_92 ( V_116 , V_5 ) ||
F_92 ( V_117 , V_5 ) ;
V_119:
F_97 ( & V_118 . V_39 ) ;
return V_112 ;
}
static bool F_98 ( struct V_4 * V_5 )
{
if ( V_118 . V_120 && V_121 != V_118 . V_120 ) {
if ( F_95 ( V_5 ) ) {
F_99 ( V_122 ) ;
F_100 ( & V_118 . V_123 , & V_122 , V_124 ) ;
if ( V_118 . V_120 )
F_101 () ;
F_102 ( & V_118 . V_123 , & V_122 ) ;
return true ;
}
}
return false ;
}
void F_103 ( struct V_4 * V_5 , struct V_83 * V_30 )
{
struct V_4 * V_94 ;
unsigned int V_103 ;
F_16 () ;
if ( V_30 ) {
F_104 ( L_4 ) ;
F_105 ( F_106 ( V_30 , V_84 ) ) ;
F_107 ( L_5 ) ;
} else {
F_104 ( L_6 ) ;
}
F_105 ( V_5 -> V_9 . V_21 ) ;
F_107 ( L_7 ) ;
F_20 () ;
F_104 ( L_8 ,
F_108 ( ( V_125 ) F_36 ( & V_5 -> V_41 ) ) ,
F_108 ( ( V_125 ) V_5 -> V_41 . V_114 ) , V_5 -> V_41 . V_126 ) ;
F_104 ( L_9 ,
F_108 ( ( V_125 ) F_36 ( & V_5 -> V_115 ) ) ,
F_108 ( ( V_125 ) V_5 -> V_115 . V_114 ) , V_5 -> V_115 . V_126 ) ;
F_104 ( L_10 ,
F_108 ( ( V_125 ) F_36 ( & V_5 -> V_127 ) ) ,
F_108 ( ( V_125 ) V_5 -> V_127 . V_114 ) , V_5 -> V_127 . V_126 ) ;
F_109 (iter, memcg) {
F_104 ( L_11 ) ;
F_105 ( V_94 -> V_9 . V_21 ) ;
F_107 ( L_12 ) ;
for ( V_103 = 0 ; V_103 < V_128 ; V_103 ++ ) {
if ( V_103 == V_129 && ! V_2 )
continue;
F_107 ( L_13 , V_130 [ V_103 ] ,
F_108 ( F_46 ( V_94 , V_103 ) ) ) ;
}
for ( V_103 = 0 ; V_103 < V_131 ; V_103 ++ )
F_107 ( L_13 , V_132 [ V_103 ] ,
F_108 ( F_60 ( V_94 , F_59 ( V_103 ) ) ) ) ;
F_107 ( L_7 ) ;
}
}
static int F_110 ( struct V_4 * V_5 )
{
int V_133 = 0 ;
struct V_4 * V_94 ;
F_109 (iter, memcg)
V_133 ++ ;
return V_133 ;
}
static unsigned long F_111 ( struct V_4 * V_5 )
{
unsigned long V_114 ;
V_114 = V_5 -> V_41 . V_114 ;
if ( F_112 ( V_5 ) ) {
unsigned long V_134 ;
unsigned long V_135 ;
V_134 = V_5 -> V_115 . V_114 ;
V_135 = V_5 -> V_136 . V_114 ;
V_135 = F_94 ( V_135 , ( unsigned long ) V_137 ) ;
V_114 = F_94 ( V_114 + V_135 , V_134 ) ;
}
return V_114 ;
}
static bool F_113 ( struct V_4 * V_5 , T_3 V_138 ,
int V_139 )
{
struct V_140 V_141 = {
. V_142 = NULL ,
. V_143 = NULL ,
. V_138 = V_138 ,
. V_139 = V_139 ,
} ;
struct V_4 * V_94 ;
unsigned long V_144 = 0 ;
unsigned long V_145 ;
unsigned int V_146 = 0 ;
struct V_83 * V_147 = NULL ;
F_114 ( & V_148 ) ;
if ( F_115 ( V_121 ) || F_116 ( V_121 ) ) {
F_117 ( V_121 ) ;
F_118 ( V_121 ) ;
goto V_119;
}
F_119 ( & V_141 , V_149 , V_5 ) ;
V_145 = F_111 ( V_5 ) ? : 1 ;
F_109 (iter, memcg) {
struct V_150 V_151 ;
struct V_83 * V_110 ;
F_120 ( & V_94 -> V_9 , & V_151 ) ;
while ( ( V_110 = F_121 ( & V_151 ) ) ) {
switch ( F_122 ( & V_141 , V_110 , V_145 ) ) {
case V_152 :
if ( V_147 )
F_123 ( V_147 ) ;
V_147 = V_110 ;
V_144 = V_153 ;
F_124 ( V_147 ) ;
case V_154 :
continue;
case V_155 :
F_125 ( & V_151 ) ;
F_80 ( V_5 , V_94 ) ;
if ( V_147 )
F_123 ( V_147 ) ;
V_147 = ( void * ) 1 ;
goto V_119;
case V_156 :
break;
} ;
V_146 = F_126 ( V_110 , V_5 , NULL , V_145 ) ;
if ( ! V_146 || V_146 < V_144 )
continue;
if ( V_146 == V_144 &&
F_127 ( V_147 ) )
continue;
if ( V_147 )
F_123 ( V_147 ) ;
V_147 = V_110 ;
V_144 = V_146 ;
F_124 ( V_147 ) ;
}
F_125 ( & V_151 ) ;
}
if ( V_147 ) {
V_146 = V_144 * 1000 / V_145 ;
F_128 ( & V_141 , V_147 , V_146 , V_145 , V_5 ,
L_14 ) ;
}
V_119:
F_129 ( & V_148 ) ;
return V_147 ;
}
static bool F_130 ( struct V_4 * V_5 ,
int V_13 , bool V_157 )
{
if ( F_56 ( V_5 , V_13 , V_158 ) )
return true ;
if ( V_157 || ! V_137 )
return false ;
if ( F_56 ( V_5 , V_13 , V_159 ) )
return true ;
return false ;
}
static void F_131 ( struct V_4 * V_5 )
{
int V_13 ;
if ( ! F_132 ( & V_5 -> V_82 ) )
return;
if ( F_133 ( & V_5 -> V_160 ) > 1 )
return;
V_5 -> V_161 = V_162 [ V_163 ] ;
F_134 (nid, node_states[N_MEMORY]) {
if ( ! F_130 ( V_5 , V_13 , false ) )
F_135 ( V_13 , V_5 -> V_161 ) ;
}
F_136 ( & V_5 -> V_82 , 0 ) ;
F_136 ( & V_5 -> V_160 , 0 ) ;
}
int F_137 ( struct V_4 * V_5 )
{
int V_164 ;
F_131 ( V_5 ) ;
V_164 = V_5 -> V_165 ;
V_164 = F_138 ( V_164 , V_5 -> V_161 ) ;
if ( F_66 ( V_164 == V_81 ) )
V_164 = F_139 () ;
V_5 -> V_165 = V_164 ;
return V_164 ;
}
int F_137 ( struct V_4 * V_5 )
{
return 0 ;
}
static int F_140 ( struct V_4 * V_166 ,
struct V_12 * V_12 ,
T_3 V_138 ,
unsigned long * V_167 )
{
struct V_4 * V_168 = NULL ;
int V_169 = 0 ;
int V_170 = 0 ;
unsigned long V_43 ;
unsigned long V_171 ;
struct V_90 V_91 = {
. V_12 = V_12 ,
. V_98 = 0 ,
} ;
V_43 = F_35 ( V_166 ) ;
while ( 1 ) {
V_168 = F_74 ( V_166 , V_168 , & V_91 ) ;
if ( ! V_168 ) {
V_170 ++ ;
if ( V_170 >= 2 ) {
if ( ! V_169 )
break;
if ( V_169 >= ( V_43 >> 2 ) ||
( V_170 > V_172 ) )
break;
}
continue;
}
V_169 += F_141 ( V_168 , V_138 , false ,
V_12 , & V_171 ) ;
* V_167 += V_171 ;
if ( ! F_35 ( V_166 ) )
break;
}
F_80 ( V_166 , V_168 ) ;
return V_169 ;
}
static bool F_142 ( struct V_4 * V_5 )
{
struct V_4 * V_94 , * V_173 = NULL ;
F_96 ( & V_174 ) ;
F_109 (iter, memcg) {
if ( V_94 -> V_148 ) {
V_173 = V_94 ;
F_80 ( V_5 , V_94 ) ;
break;
} else
V_94 -> V_148 = true ;
}
if ( V_173 ) {
F_109 (iter, memcg) {
if ( V_94 == V_173 ) {
F_80 ( V_5 , V_94 ) ;
break;
}
V_94 -> V_148 = false ;
}
} else
F_143 ( & V_175 , 0 , 1 , V_176 ) ;
F_97 ( & V_174 ) ;
return ! V_173 ;
}
static void F_144 ( struct V_4 * V_5 )
{
struct V_4 * V_94 ;
F_96 ( & V_174 ) ;
F_145 ( & V_175 , 1 , V_176 ) ;
F_109 (iter, memcg)
V_94 -> V_148 = false ;
F_97 ( & V_174 ) ;
}
static void F_146 ( struct V_4 * V_5 )
{
struct V_4 * V_94 ;
F_96 ( & V_174 ) ;
F_109 (iter, memcg)
V_94 -> V_177 ++ ;
F_97 ( & V_174 ) ;
}
static void F_147 ( struct V_4 * V_5 )
{
struct V_4 * V_94 ;
F_96 ( & V_174 ) ;
F_109 (iter, memcg)
if ( V_94 -> V_177 > 0 )
V_94 -> V_177 -- ;
F_97 ( & V_174 ) ;
}
static int F_148 ( T_4 * V_122 ,
unsigned V_178 , int V_179 , void * V_180 )
{
struct V_4 * V_181 = (struct V_4 * ) V_180 ;
struct V_4 * V_182 ;
struct V_183 * V_183 ;
V_183 = F_5 ( V_122 , struct V_183 , V_122 ) ;
V_182 = V_183 -> V_5 ;
if ( ! F_92 ( V_181 , V_182 ) &&
! F_92 ( V_182 , V_181 ) )
return 0 ;
return F_149 ( V_122 , V_178 , V_179 , V_180 ) ;
}
static void F_150 ( struct V_4 * V_5 )
{
if ( V_5 && V_5 -> V_177 )
F_151 ( & V_184 , V_185 , 0 , V_5 ) ;
}
static void F_152 ( struct V_4 * V_5 , T_3 V_186 , int V_139 )
{
if ( ! V_121 -> V_187 )
return;
F_91 ( & V_5 -> V_9 ) ;
V_121 -> V_188 = V_5 ;
V_121 -> V_189 = V_186 ;
V_121 -> V_190 = V_139 ;
}
bool F_153 ( bool V_191 )
{
struct V_4 * V_5 = V_121 -> V_188 ;
struct V_183 V_192 ;
bool V_193 ;
if ( ! V_5 )
return false ;
if ( ! V_191 || V_194 )
goto V_195;
V_192 . V_5 = V_5 ;
V_192 . V_122 . V_19 = 0 ;
V_192 . V_122 . V_196 = F_148 ;
V_192 . V_122 . V_197 = V_121 ;
F_154 ( & V_192 . V_122 . V_198 ) ;
F_100 ( & V_184 , & V_192 . V_122 , V_199 ) ;
F_146 ( V_5 ) ;
V_193 = F_142 ( V_5 ) ;
if ( V_193 )
F_155 ( V_5 ) ;
if ( V_193 && ! V_5 -> V_200 ) {
F_147 ( V_5 ) ;
F_102 ( & V_184 , & V_192 . V_122 ) ;
F_113 ( V_5 , V_121 -> V_189 ,
V_121 -> V_190 ) ;
} else {
F_101 () ;
F_147 ( V_5 ) ;
F_102 ( & V_184 , & V_192 . V_122 ) ;
}
if ( V_193 ) {
F_144 ( V_5 ) ;
F_150 ( V_5 ) ;
}
V_195:
V_121 -> V_188 = NULL ;
F_79 ( & V_5 -> V_9 ) ;
return true ;
}
void F_156 ( struct V_17 * V_17 )
{
struct V_4 * V_5 ;
unsigned long V_19 ;
F_16 () ;
if ( F_75 () )
return;
V_201:
V_5 = V_17 -> V_4 ;
if ( F_66 ( ! V_5 ) )
return;
if ( F_132 ( & V_5 -> V_202 ) <= 0 )
return;
F_33 ( & V_5 -> V_203 , V_19 ) ;
if ( V_5 != V_17 -> V_4 ) {
F_34 ( & V_5 -> V_203 , V_19 ) ;
goto V_201;
}
V_5 -> V_204 = V_121 ;
V_5 -> V_205 = V_19 ;
return;
}
void F_157 ( struct V_17 * V_17 )
{
struct V_4 * V_5 = V_17 -> V_4 ;
if ( V_5 && V_5 -> V_204 == V_121 ) {
unsigned long V_19 = V_5 -> V_205 ;
V_5 -> V_204 = NULL ;
V_5 -> V_205 = 0 ;
F_34 ( & V_5 -> V_203 , V_19 ) ;
}
F_20 () ;
}
static bool F_158 ( struct V_4 * V_5 , unsigned int V_40 )
{
struct V_206 * V_207 ;
bool V_112 = false ;
if ( V_40 > V_208 )
return V_112 ;
V_207 = & F_159 ( V_209 ) ;
if ( V_5 == V_207 -> V_210 && V_207 -> V_40 >= V_40 ) {
V_207 -> V_40 -= V_40 ;
V_112 = true ;
}
F_160 ( V_209 ) ;
return V_112 ;
}
static void F_161 ( struct V_206 * V_207 )
{
struct V_4 * V_211 = V_207 -> V_210 ;
if ( V_207 -> V_40 ) {
F_162 ( & V_211 -> V_41 , V_207 -> V_40 ) ;
if ( F_1 () )
F_162 ( & V_211 -> V_115 , V_207 -> V_40 ) ;
F_163 ( & V_211 -> V_9 , V_207 -> V_40 ) ;
V_207 -> V_40 = 0 ;
}
V_207 -> V_210 = NULL ;
}
static void F_164 ( struct V_212 * V_213 )
{
struct V_206 * V_207 = F_165 ( & V_209 ) ;
F_161 ( V_207 ) ;
F_166 ( V_214 , & V_207 -> V_19 ) ;
}
static void F_167 ( struct V_4 * V_5 , unsigned int V_40 )
{
struct V_206 * V_207 = & F_159 ( V_209 ) ;
if ( V_207 -> V_210 != V_5 ) {
F_161 ( V_207 ) ;
V_207 -> V_210 = V_5 ;
}
V_207 -> V_40 += V_40 ;
F_160 ( V_209 ) ;
}
static void F_168 ( struct V_4 * V_166 )
{
int V_51 , V_215 ;
if ( ! F_169 ( & V_216 ) )
return;
F_170 () ;
V_215 = F_171 () ;
F_172 (cpu) {
struct V_206 * V_207 = & F_48 ( V_209 , V_51 ) ;
struct V_4 * V_5 ;
V_5 = V_207 -> V_210 ;
if ( ! V_5 || ! V_207 -> V_40 )
continue;
if ( ! F_92 ( V_5 , V_166 ) )
continue;
if ( ! F_173 ( V_214 , & V_207 -> V_19 ) ) {
if ( V_51 == V_215 )
F_164 ( & V_207 -> V_217 ) ;
else
F_174 ( V_51 , & V_207 -> V_217 ) ;
}
}
F_175 () ;
F_176 () ;
F_129 ( & V_216 ) ;
}
static int F_177 ( struct V_218 * V_219 ,
unsigned long V_220 ,
void * V_221 )
{
int V_51 = ( unsigned long ) V_221 ;
struct V_206 * V_207 ;
if ( V_220 == V_222 )
return V_223 ;
if ( V_220 != V_224 && V_220 != V_225 )
return V_223 ;
V_207 = & F_48 ( V_209 , V_51 ) ;
F_161 ( V_207 ) ;
return V_223 ;
}
static void F_178 ( struct V_4 * V_5 ,
unsigned int V_40 ,
T_3 V_138 )
{
do {
if ( F_36 ( & V_5 -> V_41 ) <= V_5 -> V_226 )
continue;
F_179 ( V_5 , V_227 , 1 ) ;
F_180 ( V_5 , V_40 , V_138 , true ) ;
} while ( ( V_5 = F_18 ( V_5 ) ) );
}
static void F_181 ( struct V_212 * V_217 )
{
struct V_4 * V_5 ;
V_5 = F_5 ( V_217 , struct V_4 , V_228 ) ;
F_178 ( V_5 , V_208 , V_229 ) ;
}
void F_182 ( void )
{
unsigned int V_40 = V_121 -> V_230 ;
struct V_4 * V_5 ;
if ( F_183 ( ! V_40 ) )
return;
V_5 = F_72 ( V_121 -> V_86 ) ;
F_178 ( V_5 , V_40 , V_229 ) ;
F_79 ( & V_5 -> V_9 ) ;
V_121 -> V_230 = 0 ;
}
static int F_184 ( struct V_4 * V_5 , T_3 V_138 ,
unsigned int V_40 )
{
unsigned int V_231 = F_185 ( V_208 , V_40 ) ;
int V_232 = V_233 ;
struct V_4 * V_234 ;
struct V_235 * V_236 ;
unsigned long V_237 ;
bool V_238 = true ;
bool V_239 = false ;
if ( F_6 ( V_5 ) )
return 0 ;
V_46:
if ( F_158 ( V_5 , V_40 ) )
return 0 ;
if ( ! F_1 () ||
F_186 ( & V_5 -> V_115 , V_231 , & V_236 ) ) {
if ( F_186 ( & V_5 -> V_41 , V_231 , & V_236 ) )
goto V_240;
if ( F_1 () )
F_162 ( & V_5 -> V_115 , V_231 ) ;
V_234 = F_187 ( V_236 , V_41 ) ;
} else {
V_234 = F_187 ( V_236 , V_115 ) ;
V_238 = false ;
}
if ( V_231 > V_40 ) {
V_231 = V_40 ;
goto V_46;
}
if ( F_66 ( F_188 ( V_241 ) ||
F_115 ( V_121 ) ||
V_121 -> V_19 & V_242 ) )
goto V_243;
if ( F_66 ( F_189 ( V_121 ) ) )
goto V_244;
if ( ! F_190 ( V_138 ) )
goto V_244;
F_179 ( V_234 , V_245 , 1 ) ;
V_237 = F_180 ( V_234 , V_40 ,
V_138 , V_238 ) ;
if ( F_93 ( V_234 ) >= V_40 )
goto V_46;
if ( ! V_239 ) {
F_168 ( V_234 ) ;
V_239 = true ;
goto V_46;
}
if ( V_138 & V_246 )
goto V_244;
if ( V_237 && V_40 <= ( 1 << V_247 ) )
goto V_46;
if ( F_98 ( V_234 ) )
goto V_46;
if ( V_232 -- )
goto V_46;
if ( V_138 & V_248 )
goto V_243;
if ( F_115 ( V_121 ) )
goto V_243;
F_179 ( V_234 , V_249 , 1 ) ;
F_152 ( V_234 , V_138 ,
F_191 ( V_40 * V_250 ) ) ;
V_244:
if ( ! ( V_138 & V_248 ) )
return - V_251 ;
V_243:
F_192 ( & V_5 -> V_41 , V_40 ) ;
if ( F_1 () )
F_192 ( & V_5 -> V_115 , V_40 ) ;
F_193 ( & V_5 -> V_9 , V_40 ) ;
return 0 ;
V_240:
F_193 ( & V_5 -> V_9 , V_231 ) ;
if ( V_231 > V_40 )
F_167 ( V_5 , V_231 - V_40 ) ;
do {
if ( F_36 ( & V_5 -> V_41 ) > V_5 -> V_226 ) {
if ( F_194 () ) {
F_195 ( & V_5 -> V_228 ) ;
break;
}
V_121 -> V_230 += V_231 ;
F_196 ( V_121 ) ;
break;
}
} while ( ( V_5 = F_18 ( V_5 ) ) );
return 0 ;
}
static void F_197 ( struct V_4 * V_5 , unsigned int V_40 )
{
if ( F_6 ( V_5 ) )
return;
F_162 ( & V_5 -> V_41 , V_40 ) ;
if ( F_1 () )
F_162 ( & V_5 -> V_115 , V_40 ) ;
F_163 ( & V_5 -> V_9 , V_40 ) ;
}
static void F_198 ( struct V_17 * V_17 , int * V_252 )
{
struct V_12 * V_12 = F_199 ( V_17 ) ;
F_44 ( & V_12 -> V_253 ) ;
if ( F_200 ( V_17 ) ) {
struct V_105 * V_105 ;
V_105 = F_83 ( V_17 , V_12 ) ;
F_201 ( V_17 ) ;
F_202 ( V_17 , V_105 , F_203 ( V_17 ) ) ;
* V_252 = 1 ;
} else
* V_252 = 0 ;
}
static void F_204 ( struct V_17 * V_17 , int V_252 )
{
struct V_12 * V_12 = F_199 ( V_17 ) ;
if ( V_252 ) {
struct V_105 * V_105 ;
V_105 = F_83 ( V_17 , V_12 ) ;
F_53 ( F_200 ( V_17 ) , V_17 ) ;
F_205 ( V_17 ) ;
F_206 ( V_17 , V_105 , F_203 ( V_17 ) ) ;
}
F_45 ( & V_12 -> V_253 ) ;
}
static void F_207 ( struct V_17 * V_17 , struct V_4 * V_5 ,
bool V_254 )
{
int V_252 ;
F_53 ( V_17 -> V_4 , V_17 ) ;
if ( V_254 )
F_198 ( V_17 , & V_252 ) ;
V_17 -> V_4 = V_5 ;
if ( V_254 )
F_204 ( V_17 , V_252 ) ;
}
static int F_208 ( void )
{
int V_255 , V_106 ;
int V_256 ;
V_255 = F_209 ( & V_257 ,
0 , V_258 , V_229 ) ;
if ( V_255 < 0 )
return V_255 ;
if ( V_255 < V_259 )
return V_255 ;
F_210 ( & V_10 ) ;
V_106 = 2 * ( V_255 + 1 ) ;
if ( V_106 < V_260 )
V_106 = V_260 ;
else if ( V_106 > V_258 )
V_106 = V_258 ;
V_256 = F_211 ( V_106 ) ;
if ( ! V_256 )
V_256 = F_212 ( V_106 ) ;
if ( ! V_256 )
V_259 = V_106 ;
F_213 ( & V_10 ) ;
if ( V_256 ) {
F_214 ( & V_257 , V_255 ) ;
return V_256 ;
}
return V_255 ;
}
static void F_215 ( int V_255 )
{
F_214 ( & V_257 , V_255 ) ;
}
static void F_216 ( struct V_212 * V_261 )
{
struct V_262 * V_263 =
F_5 ( V_261 , struct V_262 , V_217 ) ;
struct V_4 * V_5 = V_263 -> V_5 ;
struct V_264 * V_265 = V_263 -> V_265 ;
F_217 ( V_5 , V_265 ) ;
F_79 ( & V_5 -> V_9 ) ;
F_218 ( V_263 ) ;
}
static void F_219 ( struct V_4 * V_5 ,
struct V_264 * V_265 )
{
struct V_262 * V_263 ;
V_263 = F_220 ( sizeof( * V_263 ) , V_266 ) ;
if ( ! V_263 )
return;
F_91 ( & V_5 -> V_9 ) ;
V_263 -> V_5 = V_5 ;
V_263 -> V_265 = V_265 ;
F_221 ( & V_263 -> V_217 , F_216 ) ;
F_195 ( & V_263 -> V_217 ) ;
}
static void F_222 ( struct V_4 * V_5 ,
struct V_264 * V_265 )
{
V_121 -> V_267 = 1 ;
F_219 ( V_5 , V_265 ) ;
V_121 -> V_267 = 0 ;
}
struct V_264 * F_223 ( struct V_264 * V_265 , T_3 V_268 )
{
struct V_4 * V_5 ;
struct V_264 * V_269 ;
int V_270 ;
F_57 ( ! F_224 ( V_265 ) ) ;
if ( V_265 -> V_19 & V_271 )
V_268 |= V_272 ;
if ( ! ( V_268 & V_272 ) )
return V_265 ;
if ( V_121 -> V_267 )
return V_265 ;
V_5 = F_72 ( V_121 -> V_86 ) ;
V_270 = F_17 ( V_5 -> V_270 ) ;
if ( V_270 < 0 )
goto V_97;
V_269 = F_225 ( V_265 , V_270 ) ;
if ( F_183 ( V_269 ) )
return V_269 ;
F_222 ( V_5 , V_265 ) ;
V_97:
F_79 ( & V_5 -> V_9 ) ;
return V_265 ;
}
void F_226 ( struct V_264 * V_265 )
{
if ( ! F_224 ( V_265 ) )
F_79 ( & V_265 -> V_273 . V_5 -> V_9 ) ;
}
int F_227 ( struct V_17 * V_17 , T_3 V_268 , int V_139 ,
struct V_4 * V_5 )
{
unsigned int V_40 = 1 << V_139 ;
struct V_235 * V_236 ;
int V_112 ;
V_112 = F_184 ( V_5 , V_268 , V_40 ) ;
if ( V_112 )
return V_112 ;
if ( ! F_2 ( V_1 ) &&
! F_186 ( & V_5 -> V_127 , V_40 , & V_236 ) ) {
F_197 ( V_5 , V_40 ) ;
return - V_251 ;
}
V_17 -> V_4 = V_5 ;
return 0 ;
}
int F_228 ( struct V_17 * V_17 , T_3 V_268 , int V_139 )
{
struct V_4 * V_5 ;
int V_112 = 0 ;
V_5 = F_72 ( V_121 -> V_86 ) ;
if ( ! F_6 ( V_5 ) )
V_112 = F_227 ( V_17 , V_268 , V_139 , V_5 ) ;
F_79 ( & V_5 -> V_9 ) ;
return V_112 ;
}
void F_229 ( struct V_17 * V_17 , int V_139 )
{
struct V_4 * V_5 = V_17 -> V_4 ;
unsigned int V_40 = 1 << V_139 ;
if ( ! V_5 )
return;
F_53 ( F_6 ( V_5 ) , V_17 ) ;
if ( ! F_2 ( V_1 ) )
F_162 ( & V_5 -> V_127 , V_40 ) ;
F_162 ( & V_5 -> V_41 , V_40 ) ;
if ( F_1 () )
F_162 ( & V_5 -> V_115 , V_40 ) ;
V_17 -> V_4 = NULL ;
F_163 ( & V_5 -> V_9 , V_40 ) ;
}
void F_230 ( struct V_17 * V_274 )
{
int V_103 ;
if ( F_75 () )
return;
for ( V_103 = 1 ; V_103 < V_275 ; V_103 ++ )
V_274 [ V_103 ] . V_4 = V_274 -> V_4 ;
F_231 ( V_274 -> V_4 -> V_52 -> V_53 [ V_59 ] ,
V_275 ) ;
}
static void F_232 ( struct V_4 * V_5 ,
bool V_276 )
{
int V_50 = ( V_276 ) ? 1 : - 1 ;
F_233 ( V_5 -> V_52 -> V_53 [ V_129 ] , V_50 ) ;
}
static int F_234 ( T_5 V_277 ,
struct V_4 * V_116 , struct V_4 * V_117 )
{
unsigned short V_278 , V_279 ;
V_278 = F_235 ( V_116 ) ;
V_279 = F_235 ( V_117 ) ;
if ( F_236 ( V_277 , V_278 , V_279 ) == V_278 ) {
F_232 ( V_116 , false ) ;
F_232 ( V_117 , true ) ;
return 0 ;
}
return - V_280 ;
}
static inline int F_234 ( T_5 V_277 ,
struct V_4 * V_116 , struct V_4 * V_117 )
{
return - V_280 ;
}
static int F_237 ( struct V_4 * V_5 ,
unsigned long V_114 )
{
unsigned long V_281 ;
unsigned long V_282 ;
bool V_283 = false ;
int V_284 ;
int V_112 ;
V_284 = V_233 *
F_110 ( V_5 ) ;
V_282 = F_36 ( & V_5 -> V_41 ) ;
do {
if ( F_238 ( V_121 ) ) {
V_112 = - V_285 ;
break;
}
F_114 ( & V_286 ) ;
if ( V_114 > V_5 -> V_115 . V_114 ) {
F_129 ( & V_286 ) ;
V_112 = - V_280 ;
break;
}
if ( V_114 > V_5 -> V_41 . V_114 )
V_283 = true ;
V_112 = F_239 ( & V_5 -> V_41 , V_114 ) ;
F_129 ( & V_286 ) ;
if ( ! V_112 )
break;
F_180 ( V_5 , 1 , V_229 , true ) ;
V_281 = F_36 ( & V_5 -> V_41 ) ;
if ( V_281 >= V_282 )
V_284 -- ;
else
V_282 = V_281 ;
} while ( V_284 );
if ( ! V_112 && V_283 )
F_150 ( V_5 ) ;
return V_112 ;
}
static int F_240 ( struct V_4 * V_5 ,
unsigned long V_114 )
{
unsigned long V_281 ;
unsigned long V_282 ;
bool V_283 = false ;
int V_284 ;
int V_112 ;
V_284 = V_233 *
F_110 ( V_5 ) ;
V_282 = F_36 ( & V_5 -> V_115 ) ;
do {
if ( F_238 ( V_121 ) ) {
V_112 = - V_285 ;
break;
}
F_114 ( & V_286 ) ;
if ( V_114 < V_5 -> V_41 . V_114 ) {
F_129 ( & V_286 ) ;
V_112 = - V_280 ;
break;
}
if ( V_114 > V_5 -> V_115 . V_114 )
V_283 = true ;
V_112 = F_239 ( & V_5 -> V_115 , V_114 ) ;
F_129 ( & V_286 ) ;
if ( ! V_112 )
break;
F_180 ( V_5 , 1 , V_229 , false ) ;
V_281 = F_36 ( & V_5 -> V_115 ) ;
if ( V_281 >= V_282 )
V_284 -- ;
else
V_282 = V_281 ;
} while ( V_284 );
if ( ! V_112 && V_283 )
F_150 ( V_5 ) ;
return V_112 ;
}
unsigned long F_241 ( struct V_12 * V_12 , int V_139 ,
T_3 V_138 ,
unsigned long * V_167 )
{
unsigned long V_237 = 0 ;
struct V_11 * V_26 , * V_287 = NULL ;
unsigned long V_288 ;
int V_170 = 0 ;
struct V_22 * V_27 ;
unsigned long V_43 ;
unsigned long V_171 ;
if ( V_139 > 0 )
return 0 ;
V_27 = F_24 ( F_12 ( V_12 ) , F_13 ( V_12 ) ) ;
do {
if ( V_287 )
V_26 = V_287 ;
else
V_26 = F_43 ( V_27 ) ;
if ( ! V_26 )
break;
V_171 = 0 ;
V_288 = F_140 ( V_26 -> V_5 , V_12 ,
V_138 , & V_171 ) ;
V_237 += V_288 ;
* V_167 += V_171 ;
F_44 ( & V_27 -> V_39 ) ;
F_30 ( V_26 , V_27 ) ;
V_287 = NULL ;
if ( ! V_288 )
V_287 = F_40 ( V_27 ) ;
V_43 = F_35 ( V_26 -> V_5 ) ;
F_26 ( V_26 , V_27 , V_43 ) ;
F_45 ( & V_27 -> V_39 ) ;
F_79 ( & V_26 -> V_5 -> V_9 ) ;
V_170 ++ ;
if ( ! V_237 &&
( V_287 == NULL ||
V_170 > V_289 ) )
break;
} while ( ! V_237 );
if ( V_287 )
F_79 ( & V_287 -> V_5 -> V_9 ) ;
return V_237 ;
}
static inline bool F_242 ( struct V_4 * V_5 )
{
bool V_112 ;
F_16 () ;
V_112 = F_243 ( NULL , & V_5 -> V_9 ) ;
F_20 () ;
return V_112 ;
}
static int F_244 ( struct V_4 * V_5 )
{
int V_232 = V_233 ;
F_245 () ;
while ( V_232 && F_36 ( & V_5 -> V_41 ) ) {
int V_290 ;
if ( F_238 ( V_121 ) )
return - V_285 ;
V_290 = F_180 ( V_5 , 1 ,
V_229 , true ) ;
if ( ! V_290 ) {
V_232 -- ;
F_246 ( V_291 , V_292 / 10 ) ;
}
}
return 0 ;
}
static T_6 F_247 ( struct V_293 * V_294 ,
char * V_295 , T_7 V_296 ,
T_8 V_297 )
{
struct V_4 * V_5 = F_70 ( F_248 ( V_294 ) ) ;
if ( F_6 ( V_5 ) )
return - V_280 ;
return F_244 ( V_5 ) ? : V_296 ;
}
static V_125 F_249 ( struct V_7 * V_9 ,
struct V_298 * V_299 )
{
return F_70 ( V_9 ) -> V_96 ;
}
static int F_250 ( struct V_7 * V_9 ,
struct V_298 * V_299 , V_125 V_50 )
{
int V_300 = 0 ;
struct V_4 * V_5 = F_70 ( V_9 ) ;
struct V_4 * V_301 = F_70 ( V_5 -> V_9 . V_32 ) ;
if ( V_5 -> V_96 == V_50 )
return 0 ;
if ( ( ! V_301 || ! V_301 -> V_96 ) &&
( V_50 == 1 || V_50 == 0 ) ) {
if ( ! F_242 ( V_5 ) )
V_5 -> V_96 = V_50 ;
else
V_300 = - V_302 ;
} else
V_300 = - V_280 ;
return V_300 ;
}
static void F_251 ( struct V_4 * V_5 , unsigned long * V_52 )
{
struct V_4 * V_94 ;
int V_103 ;
memset ( V_52 , 0 , sizeof( * V_52 ) * V_303 ) ;
F_109 (iter, memcg) {
for ( V_103 = 0 ; V_103 < V_303 ; V_103 ++ )
V_52 [ V_103 ] += F_46 ( V_94 , V_103 ) ;
}
}
static void F_252 ( struct V_4 * V_5 , unsigned long * V_55 )
{
struct V_4 * V_94 ;
int V_103 ;
memset ( V_55 , 0 , sizeof( * V_55 ) * V_304 ) ;
F_109 (iter, memcg) {
for ( V_103 = 0 ; V_103 < V_304 ; V_103 ++ )
V_55 [ V_103 ] += F_49 ( V_94 , V_103 ) ;
}
}
static unsigned long F_253 ( struct V_4 * V_5 , bool V_136 )
{
unsigned long V_50 = 0 ;
if ( F_6 ( V_5 ) ) {
struct V_4 * V_94 ;
F_109 (iter, memcg) {
V_50 += F_46 ( V_94 ,
V_58 ) ;
V_50 += F_46 ( V_94 ,
V_57 ) ;
if ( V_136 )
V_50 += F_46 ( V_94 ,
V_129 ) ;
}
} else {
if ( ! V_136 )
V_50 = F_36 ( & V_5 -> V_41 ) ;
else
V_50 = F_36 ( & V_5 -> V_115 ) ;
}
return V_50 ;
}
static V_125 F_254 ( struct V_7 * V_9 ,
struct V_298 * V_299 )
{
struct V_4 * V_5 = F_70 ( V_9 ) ;
struct V_235 * V_236 ;
switch ( F_255 ( V_299 -> V_197 ) ) {
case V_305 :
V_236 = & V_5 -> V_41 ;
break;
case V_306 :
V_236 = & V_5 -> V_115 ;
break;
case V_307 :
V_236 = & V_5 -> V_127 ;
break;
case V_308 :
V_236 = & V_5 -> V_309 ;
break;
default:
F_256 () ;
}
switch ( F_257 ( V_299 -> V_197 ) ) {
case V_310 :
if ( V_236 == & V_5 -> V_41 )
return ( V_125 ) F_253 ( V_5 , false ) * V_250 ;
if ( V_236 == & V_5 -> V_115 )
return ( V_125 ) F_253 ( V_5 , true ) * V_250 ;
return ( V_125 ) F_36 ( V_236 ) * V_250 ;
case V_311 :
return ( V_125 ) V_236 -> V_114 * V_250 ;
case V_312 :
return ( V_125 ) V_236 -> V_313 * V_250 ;
case V_314 :
return V_236 -> V_126 ;
case V_315 :
return ( V_125 ) V_5 -> V_42 * V_250 ;
default:
F_256 () ;
}
}
static int F_258 ( struct V_4 * V_5 )
{
int V_316 ;
if ( V_317 )
return 0 ;
F_259 ( V_5 -> V_270 >= 0 ) ;
F_259 ( V_5 -> V_318 ) ;
V_316 = F_208 () ;
if ( V_316 < 0 )
return V_316 ;
F_260 ( & V_319 ) ;
V_5 -> V_270 = V_316 ;
V_5 -> V_318 = V_320 ;
return 0 ;
}
static void F_261 ( struct V_4 * V_5 )
{
struct V_7 * V_9 ;
struct V_4 * V_32 , * V_321 ;
int V_270 ;
if ( V_5 -> V_318 != V_320 )
return;
V_5 -> V_318 = V_322 ;
F_262 ( V_5 ) ;
V_270 = V_5 -> V_270 ;
F_259 ( V_270 < 0 ) ;
V_32 = F_18 ( V_5 ) ;
if ( ! V_32 )
V_32 = V_6 ;
F_16 () ;
F_263 (css, &memcg->css) {
V_321 = F_70 ( V_9 ) ;
F_259 ( V_321 -> V_270 != V_270 ) ;
V_321 -> V_270 = V_32 -> V_270 ;
if ( ! V_5 -> V_96 )
break;
}
F_20 () ;
F_264 ( V_270 , V_32 -> V_270 ) ;
F_215 ( V_270 ) ;
}
static void F_265 ( struct V_4 * V_5 )
{
if ( F_66 ( V_5 -> V_318 == V_320 ) )
F_261 ( V_5 ) ;
if ( V_5 -> V_318 == V_322 ) {
F_266 ( V_5 ) ;
F_267 ( & V_319 ) ;
F_268 ( F_36 ( & V_5 -> V_127 ) ) ;
}
}
static int F_258 ( struct V_4 * V_5 )
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
unsigned long V_114 )
{
int V_112 ;
F_114 ( & V_286 ) ;
V_112 = F_239 ( & V_5 -> V_127 , V_114 ) ;
F_129 ( & V_286 ) ;
return V_112 ;
}
static int F_270 ( struct V_4 * V_5 , unsigned long V_114 )
{
int V_112 ;
F_114 ( & V_286 ) ;
V_112 = F_239 ( & V_5 -> V_309 , V_114 ) ;
if ( V_112 )
goto V_97;
if ( ! V_5 -> V_323 ) {
F_260 ( & V_324 ) ;
V_5 -> V_323 = true ;
}
V_97:
F_129 ( & V_286 ) ;
return V_112 ;
}
static T_6 F_271 ( struct V_293 * V_294 ,
char * V_295 , T_7 V_296 , T_8 V_297 )
{
struct V_4 * V_5 = F_70 ( F_248 ( V_294 ) ) ;
unsigned long V_40 ;
int V_112 ;
V_295 = F_272 ( V_295 ) ;
V_112 = F_273 ( V_295 , L_15 , & V_40 ) ;
if ( V_112 )
return V_112 ;
switch ( F_257 ( F_274 ( V_294 ) -> V_197 ) ) {
case V_311 :
if ( F_6 ( V_5 ) ) {
V_112 = - V_280 ;
break;
}
switch ( F_255 ( F_274 ( V_294 ) -> V_197 ) ) {
case V_305 :
V_112 = F_237 ( V_5 , V_40 ) ;
break;
case V_306 :
V_112 = F_240 ( V_5 , V_40 ) ;
break;
case V_307 :
V_112 = F_269 ( V_5 , V_40 ) ;
break;
case V_308 :
V_112 = F_270 ( V_5 , V_40 ) ;
break;
}
break;
case V_315 :
V_5 -> V_42 = V_40 ;
V_112 = 0 ;
break;
}
return V_112 ? : V_296 ;
}
static T_6 F_275 ( struct V_293 * V_294 , char * V_295 ,
T_7 V_296 , T_8 V_297 )
{
struct V_4 * V_5 = F_70 ( F_248 ( V_294 ) ) ;
struct V_235 * V_236 ;
switch ( F_255 ( F_274 ( V_294 ) -> V_197 ) ) {
case V_305 :
V_236 = & V_5 -> V_41 ;
break;
case V_306 :
V_236 = & V_5 -> V_115 ;
break;
case V_307 :
V_236 = & V_5 -> V_127 ;
break;
case V_308 :
V_236 = & V_5 -> V_309 ;
break;
default:
F_256 () ;
}
switch ( F_257 ( F_274 ( V_294 ) -> V_197 ) ) {
case V_312 :
F_276 ( V_236 ) ;
break;
case V_314 :
V_236 -> V_126 = 0 ;
break;
default:
F_256 () ;
}
return V_296 ;
}
static V_125 F_277 ( struct V_7 * V_9 ,
struct V_298 * V_299 )
{
return F_70 ( V_9 ) -> V_325 ;
}
static int F_278 ( struct V_7 * V_9 ,
struct V_298 * V_299 , V_125 V_50 )
{
struct V_4 * V_5 = F_70 ( V_9 ) ;
if ( V_50 & ~ V_326 )
return - V_280 ;
V_5 -> V_325 = V_50 ;
return 0 ;
}
static int F_278 ( struct V_7 * V_9 ,
struct V_298 * V_299 , V_125 V_50 )
{
return - V_327 ;
}
static int F_279 ( struct V_328 * V_329 , void * V_330 )
{
struct V_331 {
const char * V_332 ;
unsigned int V_63 ;
};
static const struct V_331 V_333 [] = {
{ L_16 , V_334 } ,
{ L_17 , V_158 } ,
{ L_18 , V_159 } ,
{ L_19 , F_59 (LRU_UNEVICTABLE) } ,
} ;
const struct V_331 * V_52 ;
int V_13 ;
unsigned long V_64 ;
struct V_4 * V_5 = F_70 ( F_280 ( V_329 ) ) ;
for ( V_52 = V_333 ; V_52 < V_333 + F_281 ( V_333 ) ; V_52 ++ ) {
V_64 = F_60 ( V_5 , V_52 -> V_63 ) ;
F_282 ( V_329 , L_20 , V_52 -> V_332 , V_64 ) ;
F_61 (nid, N_MEMORY) {
V_64 = F_56 ( V_5 , V_13 ,
V_52 -> V_63 ) ;
F_282 ( V_329 , L_21 , V_13 , V_64 ) ;
}
F_283 ( V_329 , '\n' ) ;
}
for ( V_52 = V_333 ; V_52 < V_333 + F_281 ( V_333 ) ; V_52 ++ ) {
struct V_4 * V_94 ;
V_64 = 0 ;
F_109 (iter, memcg)
V_64 += F_60 ( V_94 , V_52 -> V_63 ) ;
F_282 ( V_329 , L_22 , V_52 -> V_332 , V_64 ) ;
F_61 (nid, N_MEMORY) {
V_64 = 0 ;
F_109 (iter, memcg)
V_64 += F_56 (
V_94 , V_13 , V_52 -> V_63 ) ;
F_282 ( V_329 , L_21 , V_13 , V_64 ) ;
}
F_283 ( V_329 , '\n' ) ;
}
return 0 ;
}
static int F_284 ( struct V_328 * V_329 , void * V_330 )
{
struct V_4 * V_5 = F_70 ( F_280 ( V_329 ) ) ;
unsigned long V_41 , V_115 ;
struct V_4 * V_335 ;
unsigned int V_103 ;
F_285 ( F_281 ( V_130 ) !=
V_128 ) ;
F_285 ( F_281 ( V_336 ) !=
V_337 ) ;
F_285 ( F_281 ( V_132 ) != V_131 ) ;
for ( V_103 = 0 ; V_103 < V_128 ; V_103 ++ ) {
if ( V_103 == V_129 && ! F_1 () )
continue;
F_282 ( V_329 , L_23 , V_130 [ V_103 ] ,
F_46 ( V_5 , V_103 ) * V_250 ) ;
}
for ( V_103 = 0 ; V_103 < V_337 ; V_103 ++ )
F_282 ( V_329 , L_23 , V_336 [ V_103 ] ,
F_49 ( V_5 , V_103 ) ) ;
for ( V_103 = 0 ; V_103 < V_131 ; V_103 ++ )
F_282 ( V_329 , L_23 , V_132 [ V_103 ] ,
F_60 ( V_5 , F_59 ( V_103 ) ) * V_250 ) ;
V_41 = V_115 = V_338 ;
for ( V_335 = V_5 ; V_335 ; V_335 = F_18 ( V_335 ) ) {
V_41 = F_94 ( V_41 , V_335 -> V_41 . V_114 ) ;
V_115 = F_94 ( V_115 , V_335 -> V_115 . V_114 ) ;
}
F_282 ( V_329 , L_24 ,
( V_125 ) V_41 * V_250 ) ;
if ( F_1 () )
F_282 ( V_329 , L_25 ,
( V_125 ) V_115 * V_250 ) ;
for ( V_103 = 0 ; V_103 < V_128 ; V_103 ++ ) {
unsigned long long V_50 = 0 ;
if ( V_103 == V_129 && ! F_1 () )
continue;
F_109 (mi, memcg)
V_50 += F_46 ( V_335 , V_103 ) * V_250 ;
F_282 ( V_329 , L_26 , V_130 [ V_103 ] , V_50 ) ;
}
for ( V_103 = 0 ; V_103 < V_337 ; V_103 ++ ) {
unsigned long long V_50 = 0 ;
F_109 (mi, memcg)
V_50 += F_49 ( V_335 , V_103 ) ;
F_282 ( V_329 , L_26 ,
V_336 [ V_103 ] , V_50 ) ;
}
for ( V_103 = 0 ; V_103 < V_131 ; V_103 ++ ) {
unsigned long long V_50 = 0 ;
F_109 (mi, memcg)
V_50 += F_60 ( V_335 , F_59 ( V_103 ) ) * V_250 ;
F_282 ( V_329 , L_26 , V_132 [ V_103 ] , V_50 ) ;
}
#ifdef F_286
{
int V_13 , V_14 ;
struct V_11 * V_26 ;
struct V_339 * V_340 ;
unsigned long V_341 [ 2 ] = { 0 , 0 } ;
unsigned long V_342 [ 2 ] = { 0 , 0 } ;
F_287 (nid)
for ( V_14 = 0 ; V_14 < V_44 ; V_14 ++ ) {
V_26 = & V_5 -> V_15 [ V_13 ] -> V_16 [ V_14 ] ;
V_340 = & V_26 -> V_105 . V_343 ;
V_341 [ 0 ] += V_340 -> V_341 [ 0 ] ;
V_341 [ 1 ] += V_340 -> V_341 [ 1 ] ;
V_342 [ 0 ] += V_340 -> V_342 [ 0 ] ;
V_342 [ 1 ] += V_340 -> V_342 [ 1 ] ;
}
F_282 ( V_329 , L_27 , V_341 [ 0 ] ) ;
F_282 ( V_329 , L_28 , V_341 [ 1 ] ) ;
F_282 ( V_329 , L_29 , V_342 [ 0 ] ) ;
F_282 ( V_329 , L_30 , V_342 [ 1 ] ) ;
}
#endif
return 0 ;
}
static V_125 F_288 ( struct V_7 * V_9 ,
struct V_298 * V_299 )
{
struct V_4 * V_5 = F_70 ( V_9 ) ;
return F_112 ( V_5 ) ;
}
static int F_289 ( struct V_7 * V_9 ,
struct V_298 * V_299 , V_125 V_50 )
{
struct V_4 * V_5 = F_70 ( V_9 ) ;
if ( V_50 > 100 )
return - V_280 ;
if ( V_9 -> V_32 )
V_5 -> V_344 = V_50 ;
else
V_345 = V_50 ;
return 0 ;
}
static void F_290 ( struct V_4 * V_5 , bool V_136 )
{
struct V_346 * V_347 ;
unsigned long V_348 ;
int V_103 ;
F_16 () ;
if ( ! V_136 )
V_347 = F_73 ( V_5 -> V_349 . V_350 ) ;
else
V_347 = F_73 ( V_5 -> V_351 . V_350 ) ;
if ( ! V_347 )
goto V_119;
V_348 = F_253 ( V_5 , V_136 ) ;
V_103 = V_347 -> V_352 ;
for (; V_103 >= 0 && F_66 ( V_347 -> V_353 [ V_103 ] . V_354 > V_348 ) ; V_103 -- )
F_291 ( V_347 -> V_353 [ V_103 ] . V_355 , 1 ) ;
V_103 ++ ;
for (; V_103 < V_347 -> V_106 && F_66 ( V_347 -> V_353 [ V_103 ] . V_354 <= V_348 ) ; V_103 ++ )
F_291 ( V_347 -> V_353 [ V_103 ] . V_355 , 1 ) ;
V_347 -> V_352 = V_103 - 1 ;
V_119:
F_20 () ;
}
static void F_67 ( struct V_4 * V_5 )
{
while ( V_5 ) {
F_290 ( V_5 , false ) ;
if ( F_1 () )
F_290 ( V_5 , true ) ;
V_5 = F_18 ( V_5 ) ;
}
}
static int F_292 ( const void * V_356 , const void * V_357 )
{
const struct F_67 * V_358 = V_356 ;
const struct F_67 * V_359 = V_357 ;
if ( V_358 -> V_354 > V_359 -> V_354 )
return 1 ;
if ( V_358 -> V_354 < V_359 -> V_354 )
return - 1 ;
return 0 ;
}
static int F_293 ( struct V_4 * V_5 )
{
struct V_360 * V_361 ;
F_96 ( & V_174 ) ;
F_294 (ev, &memcg->oom_notify, list)
F_291 ( V_361 -> V_355 , 1 ) ;
F_97 ( & V_174 ) ;
return 0 ;
}
static void F_155 ( struct V_4 * V_5 )
{
struct V_4 * V_94 ;
F_109 (iter, memcg)
F_293 ( V_94 ) ;
}
static int F_295 ( struct V_4 * V_5 ,
struct V_362 * V_355 , const char * args , enum V_363 type )
{
struct V_364 * V_349 ;
struct V_346 * V_365 ;
unsigned long V_354 ;
unsigned long V_348 ;
int V_103 , V_106 , V_112 ;
V_112 = F_273 ( args , L_15 , & V_354 ) ;
if ( V_112 )
return V_112 ;
F_114 ( & V_5 -> V_366 ) ;
if ( type == V_305 ) {
V_349 = & V_5 -> V_349 ;
V_348 = F_253 ( V_5 , false ) ;
} else if ( type == V_306 ) {
V_349 = & V_5 -> V_351 ;
V_348 = F_253 ( V_5 , true ) ;
} else
F_256 () ;
if ( V_349 -> V_350 )
F_290 ( V_5 , type == V_306 ) ;
V_106 = V_349 -> V_350 ? V_349 -> V_350 -> V_106 + 1 : 1 ;
V_365 = F_220 ( sizeof( * V_365 ) + V_106 * sizeof( struct F_67 ) ,
V_229 ) ;
if ( ! V_365 ) {
V_112 = - V_251 ;
goto V_119;
}
V_365 -> V_106 = V_106 ;
if ( V_349 -> V_350 ) {
memcpy ( V_365 -> V_353 , V_349 -> V_350 -> V_353 , ( V_106 - 1 ) *
sizeof( struct F_67 ) ) ;
}
V_365 -> V_353 [ V_106 - 1 ] . V_355 = V_355 ;
V_365 -> V_353 [ V_106 - 1 ] . V_354 = V_354 ;
F_296 ( V_365 -> V_353 , V_106 , sizeof( struct F_67 ) ,
F_292 , NULL ) ;
V_365 -> V_352 = - 1 ;
for ( V_103 = 0 ; V_103 < V_106 ; V_103 ++ ) {
if ( V_365 -> V_353 [ V_103 ] . V_354 <= V_348 ) {
++ V_365 -> V_352 ;
} else
break;
}
F_218 ( V_349 -> V_367 ) ;
V_349 -> V_367 = V_349 -> V_350 ;
F_297 ( V_349 -> V_350 , V_365 ) ;
F_298 () ;
V_119:
F_129 ( & V_5 -> V_366 ) ;
return V_112 ;
}
static int F_299 ( struct V_4 * V_5 ,
struct V_362 * V_355 , const char * args )
{
return F_295 ( V_5 , V_355 , args , V_305 ) ;
}
static int F_300 ( struct V_4 * V_5 ,
struct V_362 * V_355 , const char * args )
{
return F_295 ( V_5 , V_355 , args , V_306 ) ;
}
static void F_301 ( struct V_4 * V_5 ,
struct V_362 * V_355 , enum V_363 type )
{
struct V_364 * V_349 ;
struct V_346 * V_365 ;
unsigned long V_348 ;
int V_103 , V_368 , V_106 ;
F_114 ( & V_5 -> V_366 ) ;
if ( type == V_305 ) {
V_349 = & V_5 -> V_349 ;
V_348 = F_253 ( V_5 , false ) ;
} else if ( type == V_306 ) {
V_349 = & V_5 -> V_351 ;
V_348 = F_253 ( V_5 , true ) ;
} else
F_256 () ;
if ( ! V_349 -> V_350 )
goto V_119;
F_290 ( V_5 , type == V_306 ) ;
V_106 = 0 ;
for ( V_103 = 0 ; V_103 < V_349 -> V_350 -> V_106 ; V_103 ++ ) {
if ( V_349 -> V_350 -> V_353 [ V_103 ] . V_355 != V_355 )
V_106 ++ ;
}
V_365 = V_349 -> V_367 ;
if ( ! V_106 ) {
F_218 ( V_365 ) ;
V_365 = NULL ;
goto V_369;
}
V_365 -> V_106 = V_106 ;
V_365 -> V_352 = - 1 ;
for ( V_103 = 0 , V_368 = 0 ; V_103 < V_349 -> V_350 -> V_106 ; V_103 ++ ) {
if ( V_349 -> V_350 -> V_353 [ V_103 ] . V_355 == V_355 )
continue;
V_365 -> V_353 [ V_368 ] = V_349 -> V_350 -> V_353 [ V_103 ] ;
if ( V_365 -> V_353 [ V_368 ] . V_354 <= V_348 ) {
++ V_365 -> V_352 ;
}
V_368 ++ ;
}
V_369:
V_349 -> V_367 = V_349 -> V_350 ;
F_297 ( V_349 -> V_350 , V_365 ) ;
F_298 () ;
if ( ! V_365 ) {
F_218 ( V_349 -> V_367 ) ;
V_349 -> V_367 = NULL ;
}
V_119:
F_129 ( & V_5 -> V_366 ) ;
}
static void F_302 ( struct V_4 * V_5 ,
struct V_362 * V_355 )
{
return F_301 ( V_5 , V_355 , V_305 ) ;
}
static void F_303 ( struct V_4 * V_5 ,
struct V_362 * V_355 )
{
return F_301 ( V_5 , V_355 , V_306 ) ;
}
static int F_304 ( struct V_4 * V_5 ,
struct V_362 * V_355 , const char * args )
{
struct V_360 * V_370 ;
V_370 = F_220 ( sizeof( * V_370 ) , V_229 ) ;
if ( ! V_370 )
return - V_251 ;
F_96 ( & V_174 ) ;
V_370 -> V_355 = V_355 ;
F_305 ( & V_370 -> V_371 , & V_5 -> V_372 ) ;
if ( V_5 -> V_177 )
F_291 ( V_355 , 1 ) ;
F_97 ( & V_174 ) ;
return 0 ;
}
static void F_306 ( struct V_4 * V_5 ,
struct V_362 * V_355 )
{
struct V_360 * V_361 , * V_373 ;
F_96 ( & V_174 ) ;
F_307 (ev, tmp, &memcg->oom_notify, list) {
if ( V_361 -> V_355 == V_355 ) {
F_308 ( & V_361 -> V_371 ) ;
F_218 ( V_361 ) ;
}
}
F_97 ( & V_174 ) ;
}
static int F_309 ( struct V_328 * V_374 , void * V_330 )
{
struct V_4 * V_5 = F_70 ( F_280 ( V_374 ) ) ;
F_282 ( V_374 , L_31 , V_5 -> V_200 ) ;
F_282 ( V_374 , L_32 , ( bool ) V_5 -> V_177 ) ;
return 0 ;
}
static int F_310 ( struct V_7 * V_9 ,
struct V_298 * V_299 , V_125 V_50 )
{
struct V_4 * V_5 = F_70 ( V_9 ) ;
if ( ! V_9 -> V_32 || ! ( ( V_50 == 0 ) || ( V_50 == 1 ) ) )
return - V_280 ;
V_5 -> V_200 = V_50 ;
if ( ! V_50 )
F_150 ( V_5 ) ;
return 0 ;
}
struct V_375 * F_311 ( struct V_4 * V_5 )
{
return & V_5 -> V_376 ;
}
static int F_312 ( struct V_4 * V_5 , T_3 V_268 )
{
return F_313 ( & V_5 -> V_377 , V_268 ) ;
}
static void F_314 ( struct V_4 * V_5 )
{
F_315 ( & V_5 -> V_377 ) ;
}
static void F_316 ( struct V_4 * V_5 )
{
F_317 ( & V_5 -> V_377 ) ;
}
struct V_378 * F_318 ( struct V_379 * V_380 )
{
struct V_4 * V_5 = F_70 ( V_380 -> V_381 ) ;
if ( ! V_5 -> V_9 . V_32 )
return NULL ;
return & V_5 -> V_377 ;
}
void F_319 ( struct V_379 * V_380 , unsigned long * V_382 ,
unsigned long * V_383 , unsigned long * V_384 ,
unsigned long * V_385 )
{
struct V_4 * V_5 = F_70 ( V_380 -> V_381 ) ;
struct V_4 * V_32 ;
* V_384 = F_46 ( V_5 , V_386 ) ;
* V_385 = F_46 ( V_5 , V_387 ) ;
* V_382 = F_60 ( V_5 , ( 1 << V_388 ) |
( 1 << V_389 ) ) ;
* V_383 = V_338 ;
while ( ( V_32 = F_18 ( V_5 ) ) ) {
unsigned long V_390 = F_94 ( V_5 -> V_41 . V_114 , V_5 -> V_226 ) ;
unsigned long V_391 = F_36 ( & V_5 -> V_41 ) ;
* V_383 = F_94 ( * V_383 , V_390 - F_94 ( V_390 , V_391 ) ) ;
V_5 = V_32 ;
}
}
static int F_312 ( struct V_4 * V_5 , T_3 V_268 )
{
return 0 ;
}
static void F_314 ( struct V_4 * V_5 )
{
}
static void F_316 ( struct V_4 * V_5 )
{
}
static void F_320 ( struct V_212 * V_217 )
{
struct V_392 * V_370 =
F_5 ( V_217 , struct V_392 , remove ) ;
struct V_4 * V_5 = V_370 -> V_5 ;
F_321 ( V_370 -> V_393 , & V_370 -> V_122 ) ;
V_370 -> V_394 ( V_5 , V_370 -> V_355 ) ;
F_291 ( V_370 -> V_355 , 1 ) ;
F_322 ( V_370 -> V_355 ) ;
F_218 ( V_370 ) ;
F_79 ( & V_5 -> V_9 ) ;
}
static int F_323 ( T_4 * V_122 , unsigned V_178 ,
int V_179 , void * V_395 )
{
struct V_392 * V_370 =
F_5 ( V_122 , struct V_392 , V_122 ) ;
struct V_4 * V_5 = V_370 -> V_5 ;
unsigned long V_19 = ( unsigned long ) V_395 ;
if ( V_19 & V_396 ) {
F_96 ( & V_5 -> V_397 ) ;
if ( ! F_86 ( & V_370 -> V_371 ) ) {
F_324 ( & V_370 -> V_371 ) ;
F_195 ( & V_370 -> remove ) ;
}
F_97 ( & V_5 -> V_397 ) ;
}
return 0 ;
}
static void F_325 ( struct V_398 * V_398 ,
T_9 * V_393 , T_10 * V_399 )
{
struct V_392 * V_370 =
F_5 ( V_399 , struct V_392 , V_399 ) ;
V_370 -> V_393 = V_393 ;
F_326 ( V_393 , & V_370 -> V_122 ) ;
}
static T_6 F_327 ( struct V_293 * V_294 ,
char * V_295 , T_7 V_296 , T_8 V_297 )
{
struct V_7 * V_9 = F_248 ( V_294 ) ;
struct V_4 * V_5 = F_70 ( V_9 ) ;
struct V_392 * V_370 ;
struct V_7 * V_400 ;
unsigned int V_401 , V_402 ;
struct V_403 V_404 ;
struct V_403 V_405 ;
const char * V_332 ;
char * V_406 ;
int V_112 ;
V_295 = F_272 ( V_295 ) ;
V_401 = F_328 ( V_295 , & V_406 , 10 ) ;
if ( * V_406 != ' ' )
return - V_280 ;
V_295 = V_406 + 1 ;
V_402 = F_328 ( V_295 , & V_406 , 10 ) ;
if ( ( * V_406 != ' ' ) && ( * V_406 != '\0' ) )
return - V_280 ;
V_295 = V_406 + 1 ;
V_370 = F_329 ( sizeof( * V_370 ) , V_229 ) ;
if ( ! V_370 )
return - V_251 ;
V_370 -> V_5 = V_5 ;
F_154 ( & V_370 -> V_371 ) ;
F_330 ( & V_370 -> V_399 , F_325 ) ;
F_331 ( & V_370 -> V_122 , F_323 ) ;
F_221 ( & V_370 -> remove , F_320 ) ;
V_404 = F_332 ( V_401 ) ;
if ( ! V_404 . V_398 ) {
V_112 = - V_407 ;
goto V_408;
}
V_370 -> V_355 = F_333 ( V_404 . V_398 ) ;
if ( F_334 ( V_370 -> V_355 ) ) {
V_112 = F_335 ( V_370 -> V_355 ) ;
goto V_409;
}
V_405 = F_332 ( V_402 ) ;
if ( ! V_405 . V_398 ) {
V_112 = - V_407 ;
goto V_410;
}
V_112 = F_336 ( F_337 ( V_405 . V_398 ) , V_411 ) ;
if ( V_112 < 0 )
goto V_412;
V_332 = V_405 . V_398 -> V_413 . V_414 -> V_415 . V_332 ;
if ( ! strcmp ( V_332 , L_33 ) ) {
V_370 -> V_416 = F_299 ;
V_370 -> V_394 = F_302 ;
} else if ( ! strcmp ( V_332 , L_34 ) ) {
V_370 -> V_416 = F_304 ;
V_370 -> V_394 = F_306 ;
} else if ( ! strcmp ( V_332 , L_35 ) ) {
V_370 -> V_416 = V_417 ;
V_370 -> V_394 = V_418 ;
} else if ( ! strcmp ( V_332 , L_36 ) ) {
V_370 -> V_416 = F_300 ;
V_370 -> V_394 = F_303 ;
} else {
V_112 = - V_280 ;
goto V_412;
}
V_400 = F_338 ( V_405 . V_398 -> V_413 . V_414 -> V_419 ,
& V_1 ) ;
V_112 = - V_280 ;
if ( F_334 ( V_400 ) )
goto V_412;
if ( V_400 != V_9 ) {
F_79 ( V_400 ) ;
goto V_412;
}
V_112 = V_370 -> V_416 ( V_5 , V_370 -> V_355 , V_295 ) ;
if ( V_112 )
goto V_420;
V_404 . V_398 -> V_421 -> V_422 ( V_404 . V_398 , & V_370 -> V_399 ) ;
F_96 ( & V_5 -> V_397 ) ;
F_305 ( & V_370 -> V_371 , & V_5 -> V_423 ) ;
F_97 ( & V_5 -> V_397 ) ;
F_339 ( V_405 ) ;
F_339 ( V_404 ) ;
return V_296 ;
V_420:
F_79 ( V_9 ) ;
V_412:
F_339 ( V_405 ) ;
V_410:
F_322 ( V_370 -> V_355 ) ;
V_409:
F_339 ( V_404 ) ;
V_408:
F_218 ( V_370 ) ;
return V_112 ;
}
static void F_340 ( struct V_4 * V_5 )
{
F_68 ( & V_5 -> V_255 . V_424 ) ;
}
static void F_341 ( struct V_4 * V_5 )
{
if ( F_342 ( & V_5 -> V_255 . V_424 ) ) {
F_343 ( & V_425 , V_5 -> V_255 . V_255 ) ;
V_5 -> V_255 . V_255 = 0 ;
F_79 ( & V_5 -> V_9 ) ;
}
}
struct V_4 * F_344 ( unsigned short V_255 )
{
F_345 ( ! F_346 () ) ;
return F_347 ( & V_425 , V_255 ) ;
}
static int F_348 ( struct V_4 * V_5 , int V_164 )
{
struct V_426 * V_427 ;
struct V_11 * V_26 ;
int V_12 , V_373 = V_164 ;
if ( ! F_349 ( V_164 , V_428 ) )
V_373 = - 1 ;
V_427 = F_350 ( sizeof( * V_427 ) , V_229 , V_373 ) ;
if ( ! V_427 )
return 1 ;
for ( V_12 = 0 ; V_12 < V_44 ; V_12 ++ ) {
V_26 = & V_427 -> V_16 [ V_12 ] ;
F_351 ( & V_26 -> V_105 ) ;
V_26 -> V_35 = 0 ;
V_26 -> V_34 = false ;
V_26 -> V_5 = V_5 ;
}
V_5 -> V_15 [ V_164 ] = V_427 ;
return 0 ;
}
static void F_352 ( struct V_4 * V_5 , int V_164 )
{
F_218 ( V_5 -> V_15 [ V_164 ] ) ;
}
static void F_353 ( struct V_4 * V_5 )
{
int V_164 ;
F_314 ( V_5 ) ;
F_39 (node)
F_352 ( V_5 , V_164 ) ;
F_354 ( V_5 -> V_52 ) ;
F_218 ( V_5 ) ;
}
static struct V_4 * F_355 ( void )
{
struct V_4 * V_5 ;
T_7 V_106 ;
int V_164 ;
V_106 = sizeof( struct V_4 ) ;
V_106 += V_65 * sizeof( struct V_426 * ) ;
V_5 = F_329 ( V_106 , V_229 ) ;
if ( ! V_5 )
return NULL ;
V_5 -> V_255 . V_255 = F_356 ( & V_425 , NULL ,
1 , V_429 ,
V_229 ) ;
if ( V_5 -> V_255 . V_255 < 0 )
goto V_430;
V_5 -> V_52 = F_357 ( struct V_431 ) ;
if ( ! V_5 -> V_52 )
goto V_430;
F_39 (node)
if ( F_348 ( V_5 , V_164 ) )
goto V_430;
if ( F_312 ( V_5 , V_229 ) )
goto V_430;
F_221 ( & V_5 -> V_228 , F_181 ) ;
V_5 -> V_165 = V_81 ;
F_154 ( & V_5 -> V_372 ) ;
F_358 ( & V_5 -> V_366 ) ;
F_359 ( & V_5 -> V_203 ) ;
F_360 ( & V_5 -> V_3 ) ;
F_154 ( & V_5 -> V_423 ) ;
F_359 ( & V_5 -> V_397 ) ;
V_5 -> V_432 = V_433 ;
#ifndef F_361
V_5 -> V_270 = - 1 ;
#endif
#ifdef F_362
F_154 ( & V_5 -> V_376 ) ;
#endif
F_363 ( & V_425 , V_5 , V_5 -> V_255 . V_255 ) ;
return V_5 ;
V_430:
if ( V_5 -> V_255 . V_255 > 0 )
F_343 ( & V_425 , V_5 -> V_255 . V_255 ) ;
F_353 ( V_5 ) ;
return NULL ;
}
static struct V_7 * T_11
F_364 ( struct V_7 * V_434 )
{
struct V_4 * V_32 = F_70 ( V_434 ) ;
struct V_4 * V_5 ;
long error = - V_251 ;
V_5 = F_355 () ;
if ( ! V_5 )
return F_365 ( error ) ;
V_5 -> V_226 = V_338 ;
V_5 -> V_42 = V_338 ;
if ( V_32 ) {
V_5 -> V_344 = F_112 ( V_32 ) ;
V_5 -> V_200 = V_32 -> V_200 ;
}
if ( V_32 && V_32 -> V_96 ) {
V_5 -> V_96 = true ;
F_366 ( & V_5 -> V_41 , & V_32 -> V_41 ) ;
F_366 ( & V_5 -> V_136 , & V_32 -> V_136 ) ;
F_366 ( & V_5 -> V_115 , & V_32 -> V_115 ) ;
F_366 ( & V_5 -> V_127 , & V_32 -> V_127 ) ;
F_366 ( & V_5 -> V_309 , & V_32 -> V_309 ) ;
} else {
F_366 ( & V_5 -> V_41 , NULL ) ;
F_366 ( & V_5 -> V_136 , NULL ) ;
F_366 ( & V_5 -> V_115 , NULL ) ;
F_366 ( & V_5 -> V_127 , NULL ) ;
F_366 ( & V_5 -> V_309 , NULL ) ;
if ( V_32 != V_6 )
V_1 . V_435 = true ;
}
if ( ! V_32 ) {
V_6 = V_5 ;
return & V_5 -> V_9 ;
}
error = F_258 ( V_5 ) ;
if ( error )
goto V_430;
if ( F_2 ( V_1 ) && ! V_436 )
F_260 ( & V_324 ) ;
return & V_5 -> V_9 ;
V_430:
F_353 ( V_5 ) ;
return F_365 ( - V_251 ) ;
}
static int F_367 ( struct V_7 * V_9 )
{
F_340 ( F_70 ( V_9 ) ) ;
F_91 ( V_9 ) ;
return 0 ;
}
static void F_368 ( struct V_7 * V_9 )
{
struct V_4 * V_5 = F_70 ( V_9 ) ;
struct V_392 * V_370 , * V_373 ;
F_96 ( & V_5 -> V_397 ) ;
F_307 (event, tmp, &memcg->event_list, list) {
F_324 ( & V_370 -> V_371 ) ;
F_195 ( & V_370 -> remove ) ;
}
F_97 ( & V_5 -> V_397 ) ;
F_261 ( V_5 ) ;
F_369 ( V_5 ) ;
F_341 ( V_5 ) ;
}
static void F_370 ( struct V_7 * V_9 )
{
struct V_4 * V_5 = F_70 ( V_9 ) ;
F_81 ( V_5 ) ;
}
static void F_371 ( struct V_7 * V_9 )
{
struct V_4 * V_5 = F_70 ( V_9 ) ;
if ( F_2 ( V_1 ) && ! V_436 )
F_267 ( & V_324 ) ;
if ( ! F_2 ( V_1 ) && V_5 -> V_323 )
F_267 ( & V_324 ) ;
F_372 ( & V_5 -> V_3 ) ;
F_373 ( & V_5 -> V_228 ) ;
F_38 ( V_5 ) ;
F_265 ( V_5 ) ;
F_353 ( V_5 ) ;
}
static void F_374 ( struct V_7 * V_9 )
{
struct V_4 * V_5 = F_70 ( V_9 ) ;
F_239 ( & V_5 -> V_41 , V_338 ) ;
F_239 ( & V_5 -> V_136 , V_338 ) ;
F_239 ( & V_5 -> V_115 , V_338 ) ;
F_239 ( & V_5 -> V_127 , V_338 ) ;
F_239 ( & V_5 -> V_309 , V_338 ) ;
V_5 -> V_437 = 0 ;
V_5 -> V_226 = V_338 ;
V_5 -> V_42 = V_338 ;
F_316 ( V_5 ) ;
}
static int F_375 ( unsigned long V_53 )
{
int V_112 ;
V_112 = F_184 ( V_118 . V_117 , V_229 & ~ V_438 , V_53 ) ;
if ( ! V_112 ) {
V_118 . V_439 += V_53 ;
return V_112 ;
}
while ( V_53 -- ) {
V_112 = F_184 ( V_118 . V_117 , V_229 & ~ V_246 , 1 ) ;
if ( V_112 )
return V_112 ;
V_118 . V_439 ++ ;
F_376 () ;
}
return 0 ;
}
static struct V_17 * F_377 ( struct V_440 * V_441 ,
unsigned long V_442 , T_12 V_443 )
{
struct V_17 * V_17 = F_378 ( V_441 , V_442 , V_443 ) ;
if ( ! V_17 || ! F_379 ( V_17 ) )
return NULL ;
if ( F_51 ( V_17 ) ) {
if ( ! ( V_118 . V_19 & V_444 ) )
return NULL ;
} else {
if ( ! ( V_118 . V_19 & V_445 ) )
return NULL ;
}
if ( ! F_380 ( V_17 ) )
return NULL ;
return V_17 ;
}
static struct V_17 * F_381 ( struct V_440 * V_441 ,
unsigned long V_442 , T_12 V_443 , T_5 * V_277 )
{
struct V_17 * V_17 = NULL ;
T_5 V_446 = F_382 ( V_443 ) ;
if ( ! ( V_118 . V_19 & V_444 ) || F_383 ( V_446 ) )
return NULL ;
V_17 = F_384 ( F_385 ( V_446 ) , V_446 . V_50 ) ;
if ( F_1 () )
V_277 -> V_50 = V_446 . V_50 ;
return V_17 ;
}
static struct V_17 * F_381 ( struct V_440 * V_441 ,
unsigned long V_442 , T_12 V_443 , T_5 * V_277 )
{
return NULL ;
}
static struct V_17 * F_386 ( struct V_440 * V_441 ,
unsigned long V_442 , T_12 V_443 , T_5 * V_277 )
{
struct V_17 * V_17 = NULL ;
struct V_447 * V_448 ;
T_13 V_449 ;
if ( ! V_441 -> V_450 )
return NULL ;
if ( ! ( V_118 . V_19 & V_445 ) )
return NULL ;
V_448 = V_441 -> V_450 -> V_451 ;
V_449 = F_387 ( V_441 , V_442 ) ;
#ifdef F_388
if ( F_389 ( V_448 ) ) {
V_17 = F_390 ( V_448 , V_449 ) ;
if ( F_391 ( V_17 ) ) {
T_5 V_452 = F_392 ( V_17 ) ;
if ( F_1 () )
* V_277 = V_452 ;
V_17 = F_384 ( F_385 ( V_452 ) , V_452 . V_50 ) ;
}
} else
V_17 = F_384 ( V_448 , V_449 ) ;
#else
V_17 = F_384 ( V_448 , V_449 ) ;
#endif
return V_17 ;
}
static int F_393 ( struct V_17 * V_17 ,
bool V_56 ,
struct V_4 * V_116 ,
struct V_4 * V_117 )
{
unsigned long V_19 ;
unsigned int V_40 = V_56 ? F_394 ( V_17 ) : 1 ;
int V_112 ;
bool V_453 ;
F_57 ( V_116 == V_117 ) ;
F_53 ( F_200 ( V_17 ) , V_17 ) ;
F_57 ( V_56 && ! F_54 ( V_17 ) ) ;
V_112 = - V_302 ;
if ( ! F_395 ( V_17 ) )
goto V_97;
V_112 = - V_280 ;
if ( V_17 -> V_4 != V_116 )
goto V_100;
V_453 = F_51 ( V_17 ) ;
F_33 ( & V_116 -> V_203 , V_19 ) ;
if ( ! V_453 && F_379 ( V_17 ) ) {
F_231 ( V_116 -> V_52 -> V_53 [ V_454 ] ,
V_40 ) ;
F_52 ( V_117 -> V_52 -> V_53 [ V_454 ] ,
V_40 ) ;
}
if ( ! V_453 && F_396 ( V_17 ) ) {
struct V_447 * V_448 = F_397 ( V_17 ) ;
if ( F_398 ( V_448 ) ) {
F_231 ( V_116 -> V_52 -> V_53 [ V_386 ] ,
V_40 ) ;
F_52 ( V_117 -> V_52 -> V_53 [ V_386 ] ,
V_40 ) ;
}
}
if ( F_399 ( V_17 ) ) {
F_231 ( V_116 -> V_52 -> V_53 [ V_387 ] ,
V_40 ) ;
F_52 ( V_117 -> V_52 -> V_53 [ V_387 ] ,
V_40 ) ;
}
V_17 -> V_4 = V_117 ;
F_34 ( & V_116 -> V_203 , V_19 ) ;
V_112 = 0 ;
F_400 () ;
F_50 ( V_117 , V_17 , V_56 , V_40 ) ;
F_65 ( V_117 , V_17 ) ;
F_50 ( V_116 , V_17 , V_56 , - V_40 ) ;
F_65 ( V_116 , V_17 ) ;
F_401 () ;
V_100:
F_402 ( V_17 ) ;
V_97:
return V_112 ;
}
static enum V_455 F_403 ( struct V_440 * V_441 ,
unsigned long V_442 , T_12 V_443 , union V_456 * V_70 )
{
struct V_17 * V_17 = NULL ;
enum V_455 V_112 = V_457 ;
T_5 V_446 = { . V_50 = 0 } ;
if ( F_404 ( V_443 ) )
V_17 = F_377 ( V_441 , V_442 , V_443 ) ;
else if ( F_405 ( V_443 ) )
V_17 = F_381 ( V_441 , V_442 , V_443 , & V_446 ) ;
else if ( F_406 ( V_443 ) )
V_17 = F_386 ( V_441 , V_442 , V_443 , & V_446 ) ;
if ( ! V_17 && ! V_446 . V_50 )
return V_112 ;
if ( V_17 ) {
if ( V_17 -> V_4 == V_118 . V_116 ) {
V_112 = V_458 ;
if ( V_70 )
V_70 -> V_17 = V_17 ;
}
if ( ! V_112 || ! V_70 )
F_407 ( V_17 ) ;
}
if ( V_446 . V_50 && ! V_112 &&
F_235 ( V_118 . V_116 ) == F_408 ( V_446 ) ) {
V_112 = V_459 ;
if ( V_70 )
V_70 -> V_446 = V_446 ;
}
return V_112 ;
}
static enum V_455 F_409 ( struct V_440 * V_441 ,
unsigned long V_442 , T_14 V_460 , union V_456 * V_70 )
{
struct V_17 * V_17 = NULL ;
enum V_455 V_112 = V_457 ;
V_17 = F_410 ( V_460 ) ;
F_53 ( ! V_17 || ! F_411 ( V_17 ) , V_17 ) ;
if ( ! ( V_118 . V_19 & V_444 ) )
return V_112 ;
if ( V_17 -> V_4 == V_118 . V_116 ) {
V_112 = V_458 ;
if ( V_70 ) {
F_412 ( V_17 ) ;
V_70 -> V_17 = V_17 ;
}
}
return V_112 ;
}
static inline enum V_455 F_409 ( struct V_440 * V_441 ,
unsigned long V_442 , T_14 V_460 , union V_456 * V_70 )
{
return V_457 ;
}
static int F_413 ( T_14 * V_460 ,
unsigned long V_442 , unsigned long V_461 ,
struct V_462 * V_463 )
{
struct V_440 * V_441 = V_463 -> V_441 ;
T_12 * V_464 ;
T_15 * V_465 ;
V_465 = F_414 ( V_460 , V_441 ) ;
if ( V_465 ) {
if ( F_409 ( V_441 , V_442 , * V_460 , NULL ) == V_458 )
V_118 . V_439 += V_275 ;
F_97 ( V_465 ) ;
return 0 ;
}
if ( F_415 ( V_460 ) )
return 0 ;
V_464 = F_416 ( V_441 -> V_466 , V_460 , V_442 , & V_465 ) ;
for (; V_442 != V_461 ; V_464 ++ , V_442 += V_250 )
if ( F_403 ( V_441 , V_442 , * V_464 , NULL ) )
V_118 . V_439 ++ ;
F_417 ( V_464 - 1 , V_465 ) ;
F_376 () ;
return 0 ;
}
static unsigned long F_418 ( struct V_85 * V_86 )
{
unsigned long V_439 ;
struct V_462 V_467 = {
. V_468 = F_413 ,
. V_86 = V_86 ,
} ;
F_8 ( & V_86 -> V_469 ) ;
F_419 ( 0 , ~ 0UL , & V_467 ) ;
F_10 ( & V_86 -> V_469 ) ;
V_439 = V_118 . V_439 ;
V_118 . V_439 = 0 ;
return V_439 ;
}
static int F_420 ( struct V_85 * V_86 )
{
unsigned long V_439 = F_418 ( V_86 ) ;
F_57 ( V_118 . V_120 ) ;
V_118 . V_120 = V_121 ;
return F_375 ( V_439 ) ;
}
static void F_421 ( void )
{
struct V_4 * V_116 = V_118 . V_116 ;
struct V_4 * V_117 = V_118 . V_117 ;
if ( V_118 . V_439 ) {
F_197 ( V_118 . V_117 , V_118 . V_439 ) ;
V_118 . V_439 = 0 ;
}
if ( V_118 . V_470 ) {
F_197 ( V_118 . V_116 , V_118 . V_470 ) ;
V_118 . V_470 = 0 ;
}
if ( V_118 . V_471 ) {
if ( ! F_6 ( V_118 . V_116 ) )
F_162 ( & V_118 . V_116 -> V_115 , V_118 . V_471 ) ;
if ( ! F_6 ( V_118 . V_117 ) )
F_162 ( & V_118 . V_117 -> V_41 , V_118 . V_471 ) ;
F_163 ( & V_118 . V_116 -> V_9 , V_118 . V_471 ) ;
V_118 . V_471 = 0 ;
}
F_150 ( V_116 ) ;
F_150 ( V_117 ) ;
F_422 ( & V_118 . V_123 ) ;
}
static void F_423 ( void )
{
struct V_85 * V_86 = V_118 . V_86 ;
V_118 . V_120 = NULL ;
F_421 () ;
F_96 ( & V_118 . V_39 ) ;
V_118 . V_116 = NULL ;
V_118 . V_117 = NULL ;
V_118 . V_86 = NULL ;
F_97 ( & V_118 . V_39 ) ;
F_424 ( V_86 ) ;
}
static int F_425 ( struct V_472 * V_473 )
{
struct V_7 * V_9 ;
struct V_4 * V_5 = NULL ;
struct V_4 * V_116 ;
struct V_83 * V_474 , * V_30 ;
struct V_85 * V_86 ;
unsigned long V_475 ;
int V_112 = 0 ;
if ( F_2 ( V_1 ) )
return 0 ;
V_30 = NULL ;
F_426 (leader, css, tset) {
F_345 ( V_30 ) ;
V_30 = V_474 ;
V_5 = F_70 ( V_9 ) ;
}
if ( ! V_30 )
return 0 ;
V_475 = F_17 ( V_5 -> V_325 ) ;
if ( ! V_475 )
return 0 ;
V_116 = F_69 ( V_30 ) ;
F_57 ( V_116 == V_5 ) ;
V_86 = F_427 ( V_30 ) ;
if ( ! V_86 )
return 0 ;
if ( V_86 -> V_87 == V_30 ) {
F_57 ( V_118 . V_116 ) ;
F_57 ( V_118 . V_117 ) ;
F_57 ( V_118 . V_439 ) ;
F_57 ( V_118 . V_470 ) ;
F_57 ( V_118 . V_471 ) ;
F_96 ( & V_118 . V_39 ) ;
V_118 . V_86 = V_86 ;
V_118 . V_116 = V_116 ;
V_118 . V_117 = V_5 ;
V_118 . V_19 = V_475 ;
F_97 ( & V_118 . V_39 ) ;
V_112 = F_420 ( V_86 ) ;
if ( V_112 )
F_423 () ;
} else {
F_424 ( V_86 ) ;
}
return V_112 ;
}
static void F_428 ( struct V_472 * V_473 )
{
if ( V_118 . V_117 )
F_423 () ;
}
static int F_429 ( T_14 * V_460 ,
unsigned long V_442 , unsigned long V_461 ,
struct V_462 * V_463 )
{
int V_112 = 0 ;
struct V_440 * V_441 = V_463 -> V_441 ;
T_12 * V_464 ;
T_15 * V_465 ;
enum V_455 V_476 ;
union V_456 V_70 ;
struct V_17 * V_17 ;
V_465 = F_414 ( V_460 , V_441 ) ;
if ( V_465 ) {
if ( V_118 . V_439 < V_275 ) {
F_97 ( V_465 ) ;
return 0 ;
}
V_476 = F_409 ( V_441 , V_442 , * V_460 , & V_70 ) ;
if ( V_476 == V_458 ) {
V_17 = V_70 . V_17 ;
if ( ! F_430 ( V_17 ) ) {
if ( ! F_393 ( V_17 , true ,
V_118 . V_116 , V_118 . V_117 ) ) {
V_118 . V_439 -= V_275 ;
V_118 . V_470 += V_275 ;
}
F_431 ( V_17 ) ;
}
F_407 ( V_17 ) ;
}
F_97 ( V_465 ) ;
return 0 ;
}
if ( F_415 ( V_460 ) )
return 0 ;
V_46:
V_464 = F_416 ( V_441 -> V_466 , V_460 , V_442 , & V_465 ) ;
for (; V_442 != V_461 ; V_442 += V_250 ) {
T_12 V_443 = * ( V_464 ++ ) ;
T_5 V_446 ;
if ( ! V_118 . V_439 )
break;
switch ( F_403 ( V_441 , V_442 , V_443 , & V_70 ) ) {
case V_458 :
V_17 = V_70 . V_17 ;
if ( F_432 ( V_17 ) )
goto V_477;
if ( F_430 ( V_17 ) )
goto V_477;
if ( ! F_393 ( V_17 , false ,
V_118 . V_116 , V_118 . V_117 ) ) {
V_118 . V_439 -- ;
V_118 . V_470 ++ ;
}
F_431 ( V_17 ) ;
V_477:
F_407 ( V_17 ) ;
break;
case V_459 :
V_446 = V_70 . V_446 ;
if ( ! F_234 ( V_446 , V_118 . V_116 , V_118 . V_117 ) ) {
V_118 . V_439 -- ;
V_118 . V_471 ++ ;
}
break;
default:
break;
}
}
F_417 ( V_464 - 1 , V_465 ) ;
F_376 () ;
if ( V_442 != V_461 ) {
V_112 = F_375 ( 1 ) ;
if ( ! V_112 )
goto V_46;
}
return V_112 ;
}
static void F_433 ( void )
{
struct V_462 V_478 = {
. V_468 = F_429 ,
. V_86 = V_118 . V_86 ,
} ;
F_245 () ;
F_68 ( & V_118 . V_116 -> V_202 ) ;
F_298 () ;
V_46:
if ( F_66 ( ! F_434 ( & V_118 . V_86 -> V_469 ) ) ) {
F_421 () ;
F_376 () ;
goto V_46;
}
F_419 ( 0 , ~ 0UL , & V_478 ) ;
F_10 ( & V_118 . V_86 -> V_469 ) ;
F_435 ( & V_118 . V_116 -> V_202 ) ;
}
static void F_436 ( void )
{
if ( V_118 . V_117 ) {
F_433 () ;
F_423 () ;
}
}
static int F_425 ( struct V_472 * V_473 )
{
return 0 ;
}
static void F_428 ( struct V_472 * V_473 )
{
}
static void F_436 ( void )
{
}
static void F_437 ( struct V_7 * V_479 )
{
if ( F_2 ( V_1 ) )
V_6 -> V_96 = true ;
else
V_6 -> V_96 = false ;
}
static V_125 F_438 ( struct V_7 * V_9 ,
struct V_298 * V_299 )
{
struct V_4 * V_5 = F_70 ( V_9 ) ;
return ( V_125 ) F_36 ( & V_5 -> V_41 ) * V_250 ;
}
static int F_439 ( struct V_328 * V_329 , void * V_330 )
{
struct V_4 * V_5 = F_70 ( F_280 ( V_329 ) ) ;
unsigned long V_437 = F_17 ( V_5 -> V_437 ) ;
if ( V_437 == V_338 )
F_440 ( V_329 , L_37 ) ;
else
F_282 ( V_329 , L_38 , ( V_125 ) V_437 * V_250 ) ;
return 0 ;
}
static T_6 F_441 ( struct V_293 * V_294 ,
char * V_295 , T_7 V_296 , T_8 V_297 )
{
struct V_4 * V_5 = F_70 ( F_248 ( V_294 ) ) ;
unsigned long V_437 ;
int V_256 ;
V_295 = F_272 ( V_295 ) ;
V_256 = F_273 ( V_295 , L_39 , & V_437 ) ;
if ( V_256 )
return V_256 ;
V_5 -> V_437 = V_437 ;
return V_296 ;
}
static int F_442 ( struct V_328 * V_329 , void * V_330 )
{
struct V_4 * V_5 = F_70 ( F_280 ( V_329 ) ) ;
unsigned long V_226 = F_17 ( V_5 -> V_226 ) ;
if ( V_226 == V_338 )
F_440 ( V_329 , L_37 ) ;
else
F_282 ( V_329 , L_38 , ( V_125 ) V_226 * V_250 ) ;
return 0 ;
}
static T_6 F_443 ( struct V_293 * V_294 ,
char * V_295 , T_7 V_296 , T_8 V_297 )
{
struct V_4 * V_5 = F_70 ( F_248 ( V_294 ) ) ;
unsigned long V_40 ;
unsigned long V_226 ;
int V_256 ;
V_295 = F_272 ( V_295 ) ;
V_256 = F_273 ( V_295 , L_39 , & V_226 ) ;
if ( V_256 )
return V_256 ;
V_5 -> V_226 = V_226 ;
V_40 = F_36 ( & V_5 -> V_41 ) ;
if ( V_40 > V_226 )
F_180 ( V_5 , V_40 - V_226 ,
V_229 , true ) ;
F_316 ( V_5 ) ;
return V_296 ;
}
static int F_444 ( struct V_328 * V_329 , void * V_330 )
{
struct V_4 * V_5 = F_70 ( F_280 ( V_329 ) ) ;
unsigned long F_185 = F_17 ( V_5 -> V_41 . V_114 ) ;
if ( F_185 == V_338 )
F_440 ( V_329 , L_37 ) ;
else
F_282 ( V_329 , L_38 , ( V_125 ) F_185 * V_250 ) ;
return 0 ;
}
static T_6 F_445 ( struct V_293 * V_294 ,
char * V_295 , T_7 V_296 , T_8 V_297 )
{
struct V_4 * V_5 = F_70 ( F_248 ( V_294 ) ) ;
unsigned int V_480 = V_233 ;
bool V_239 = false ;
unsigned long F_185 ;
int V_256 ;
V_295 = F_272 ( V_295 ) ;
V_256 = F_273 ( V_295 , L_39 , & F_185 ) ;
if ( V_256 )
return V_256 ;
F_446 ( & V_5 -> V_41 . V_114 , F_185 ) ;
for (; ; ) {
unsigned long V_40 = F_36 ( & V_5 -> V_41 ) ;
if ( V_40 <= F_185 )
break;
if ( F_238 ( V_121 ) ) {
V_256 = - V_285 ;
break;
}
if ( ! V_239 ) {
F_168 ( V_5 ) ;
V_239 = true ;
continue;
}
if ( V_480 ) {
if ( ! F_180 ( V_5 , V_40 - F_185 ,
V_229 , true ) )
V_480 -- ;
continue;
}
F_179 ( V_5 , V_249 , 1 ) ;
if ( ! F_113 ( V_5 , V_229 , 0 ) )
break;
}
F_316 ( V_5 ) ;
return V_296 ;
}
static int F_447 ( struct V_328 * V_329 , void * V_330 )
{
struct V_4 * V_5 = F_70 ( F_280 ( V_329 ) ) ;
F_282 ( V_329 , L_40 , F_49 ( V_5 , V_481 ) ) ;
F_282 ( V_329 , L_41 , F_49 ( V_5 , V_227 ) ) ;
F_282 ( V_329 , L_42 , F_49 ( V_5 , V_245 ) ) ;
F_282 ( V_329 , L_43 , F_49 ( V_5 , V_249 ) ) ;
return 0 ;
}
static int F_448 ( struct V_328 * V_329 , void * V_330 )
{
struct V_4 * V_5 = F_70 ( F_280 ( V_329 ) ) ;
unsigned long V_52 [ V_303 ] ;
unsigned long V_55 [ V_304 ] ;
int V_103 ;
F_251 ( V_5 , V_52 ) ;
F_252 ( V_5 , V_55 ) ;
F_282 ( V_329 , L_44 ,
( V_125 ) V_52 [ V_57 ] * V_250 ) ;
F_282 ( V_329 , L_45 ,
( V_125 ) V_52 [ V_58 ] * V_250 ) ;
F_282 ( V_329 , L_46 ,
( V_125 ) V_52 [ V_482 ] * V_250 ) ;
F_282 ( V_329 , L_47 ,
( V_125 ) ( V_52 [ V_483 ] +
V_52 [ V_484 ] ) * V_250 ) ;
F_282 ( V_329 , L_48 ,
( V_125 ) V_52 [ V_485 ] * V_250 ) ;
F_282 ( V_329 , L_49 ,
( V_125 ) V_52 [ V_454 ] * V_250 ) ;
F_282 ( V_329 , L_50 ,
( V_125 ) V_52 [ V_386 ] * V_250 ) ;
F_282 ( V_329 , L_51 ,
( V_125 ) V_52 [ V_387 ] * V_250 ) ;
for ( V_103 = 0 ; V_103 < V_131 ; V_103 ++ ) {
struct V_4 * V_335 ;
unsigned long V_50 = 0 ;
F_109 (mi, memcg)
V_50 += F_60 ( V_335 , F_59 ( V_103 ) ) ;
F_282 ( V_329 , L_52 ,
V_132 [ V_103 ] , ( V_125 ) V_50 * V_250 ) ;
}
F_282 ( V_329 , L_53 ,
( V_125 ) V_52 [ V_483 ] * V_250 ) ;
F_282 ( V_329 , L_54 ,
( V_125 ) V_52 [ V_484 ] * V_250 ) ;
F_282 ( V_329 , L_55 ,
V_55 [ V_486 ] ) ;
F_282 ( V_329 , L_56 ,
V_55 [ V_487 ] ) ;
return 0 ;
}
bool F_449 ( struct V_4 * V_88 , struct V_4 * V_5 )
{
if ( F_75 () )
return false ;
if ( V_5 == V_6 )
return false ;
if ( F_36 ( & V_5 -> V_41 ) >= V_5 -> V_437 )
return false ;
while ( V_5 != V_88 ) {
V_5 = F_18 ( V_5 ) ;
if ( V_5 == V_6 )
break;
if ( F_36 ( & V_5 -> V_41 ) >= V_5 -> V_437 )
return false ;
}
return true ;
}
int F_450 ( struct V_17 * V_17 , struct V_85 * V_86 ,
T_3 V_138 , struct V_4 * * V_488 ,
bool V_56 )
{
struct V_4 * V_5 = NULL ;
unsigned int V_40 = V_56 ? F_394 ( V_17 ) : 1 ;
int V_112 = 0 ;
if ( F_75 () )
goto V_97;
if ( F_451 ( V_17 ) ) {
F_53 ( ! F_452 ( V_17 ) , V_17 ) ;
if ( V_17 -> V_4 )
goto V_97;
if ( V_2 ) {
T_5 V_446 = { . V_50 = F_453 ( V_17 ) , } ;
unsigned short V_255 = F_408 ( V_446 ) ;
F_16 () ;
V_5 = F_344 ( V_255 ) ;
if ( V_5 && ! F_42 ( & V_5 -> V_9 ) )
V_5 = NULL ;
F_20 () ;
}
}
if ( ! V_5 )
V_5 = F_72 ( V_86 ) ;
V_112 = F_184 ( V_5 , V_138 , V_40 ) ;
F_79 ( & V_5 -> V_9 ) ;
V_97:
* V_488 = V_5 ;
return V_112 ;
}
void F_454 ( struct V_17 * V_17 , struct V_4 * V_5 ,
bool V_254 , bool V_56 )
{
unsigned int V_40 = V_56 ? F_394 ( V_17 ) : 1 ;
F_53 ( ! V_17 -> V_448 , V_17 ) ;
F_53 ( F_200 ( V_17 ) && ! V_254 , V_17 ) ;
if ( F_75 () )
return;
if ( ! V_5 )
return;
F_207 ( V_17 , V_5 , V_254 ) ;
F_400 () ;
F_50 ( V_5 , V_17 , V_56 , V_40 ) ;
F_65 ( V_5 , V_17 ) ;
F_401 () ;
if ( F_1 () && F_451 ( V_17 ) ) {
T_5 V_277 = { . V_50 = F_453 (page) } ;
F_455 ( V_277 ) ;
}
}
void F_456 ( struct V_17 * V_17 , struct V_4 * V_5 ,
bool V_56 )
{
unsigned int V_40 = V_56 ? F_394 ( V_17 ) : 1 ;
if ( F_75 () )
return;
if ( ! V_5 )
return;
F_197 ( V_5 , V_40 ) ;
}
static void F_457 ( struct V_4 * V_5 , unsigned long V_489 ,
unsigned long V_490 , unsigned long V_491 ,
unsigned long V_492 , struct V_17 * V_493 )
{
unsigned long V_40 = V_490 + V_491 ;
unsigned long V_19 ;
if ( ! F_6 ( V_5 ) ) {
F_162 ( & V_5 -> V_41 , V_40 ) ;
if ( F_1 () )
F_162 ( & V_5 -> V_115 , V_40 ) ;
F_150 ( V_5 ) ;
}
F_458 ( V_19 ) ;
F_231 ( V_5 -> V_52 -> V_53 [ V_57 ] , V_490 ) ;
F_231 ( V_5 -> V_52 -> V_53 [ V_58 ] , V_491 ) ;
F_231 ( V_5 -> V_52 -> V_53 [ V_59 ] , V_492 ) ;
F_52 ( V_5 -> V_52 -> V_55 [ V_61 ] , V_489 ) ;
F_52 ( V_5 -> V_52 -> V_62 , V_40 ) ;
F_65 ( V_5 , V_493 ) ;
F_459 ( V_19 ) ;
if ( ! F_6 ( V_5 ) )
F_163 ( & V_5 -> V_9 , V_40 ) ;
}
static void F_460 ( struct V_375 * V_494 )
{
struct V_4 * V_5 = NULL ;
unsigned long V_490 = 0 ;
unsigned long V_491 = 0 ;
unsigned long V_492 = 0 ;
unsigned long V_489 = 0 ;
struct V_375 * V_71 ;
struct V_17 * V_17 ;
V_71 = V_494 -> V_71 ;
do {
unsigned int V_40 = 1 ;
V_17 = F_461 ( V_71 , struct V_17 , V_67 ) ;
V_71 = V_17 -> V_67 . V_71 ;
F_53 ( F_200 ( V_17 ) , V_17 ) ;
F_53 ( F_462 ( V_17 ) , V_17 ) ;
if ( ! V_17 -> V_4 )
continue;
if ( V_5 != V_17 -> V_4 ) {
if ( V_5 ) {
F_457 ( V_5 , V_489 , V_490 , V_491 ,
V_492 , V_17 ) ;
V_489 = V_490 = V_491 = V_492 = 0 ;
}
V_5 = V_17 -> V_4 ;
}
if ( F_54 ( V_17 ) ) {
V_40 <<= F_463 ( V_17 ) ;
F_53 ( ! F_54 ( V_17 ) , V_17 ) ;
V_492 += V_40 ;
}
if ( F_51 ( V_17 ) )
V_490 += V_40 ;
else
V_491 += V_40 ;
V_17 -> V_4 = NULL ;
V_489 ++ ;
} while ( V_71 != V_494 );
if ( V_5 )
F_457 ( V_5 , V_489 , V_490 , V_491 ,
V_492 , V_17 ) ;
}
void F_464 ( struct V_17 * V_17 )
{
if ( F_75 () )
return;
if ( ! V_17 -> V_4 )
return;
F_154 ( & V_17 -> V_67 ) ;
F_460 ( & V_17 -> V_67 ) ;
}
void F_465 ( struct V_375 * V_494 )
{
if ( F_75 () )
return;
if ( ! F_86 ( V_494 ) )
F_460 ( V_494 ) ;
}
void F_466 ( struct V_17 * V_495 , struct V_17 * V_496 )
{
struct V_4 * V_5 ;
unsigned int V_40 ;
bool V_56 ;
unsigned long V_19 ;
F_53 ( ! F_452 ( V_495 ) , V_495 ) ;
F_53 ( ! F_452 ( V_496 ) , V_496 ) ;
F_53 ( F_51 ( V_495 ) != F_51 ( V_496 ) , V_496 ) ;
F_53 ( F_54 ( V_495 ) != F_54 ( V_496 ) ,
V_496 ) ;
if ( F_75 () )
return;
if ( V_496 -> V_4 )
return;
V_5 = V_495 -> V_4 ;
if ( ! V_5 )
return;
V_56 = F_54 ( V_496 ) ;
V_40 = V_56 ? F_394 ( V_496 ) : 1 ;
F_192 ( & V_5 -> V_41 , V_40 ) ;
if ( F_1 () )
F_192 ( & V_5 -> V_115 , V_40 ) ;
F_193 ( & V_5 -> V_9 , V_40 ) ;
F_207 ( V_496 , V_5 , false ) ;
F_458 ( V_19 ) ;
F_50 ( V_5 , V_496 , V_56 , V_40 ) ;
F_65 ( V_5 , V_496 ) ;
F_459 ( V_19 ) ;
}
void F_467 ( struct V_497 * V_498 )
{
struct V_4 * V_5 ;
if ( V_498 -> V_499 ) {
F_259 ( F_6 ( V_498 -> V_499 ) ) ;
F_91 ( & V_498 -> V_499 -> V_9 ) ;
return;
}
F_16 () ;
V_5 = F_69 ( V_121 ) ;
if ( V_5 == V_6 )
goto V_97;
if ( ! F_2 ( V_1 ) && ! V_5 -> V_323 )
goto V_97;
if ( F_42 ( & V_5 -> V_9 ) )
V_498 -> V_499 = V_5 ;
V_97:
F_20 () ;
}
void F_468 ( struct V_497 * V_498 )
{
F_268 ( ! V_498 -> V_499 ) ;
F_79 ( & V_498 -> V_499 -> V_9 ) ;
}
bool F_469 ( struct V_4 * V_5 , unsigned int V_40 )
{
T_3 V_138 = V_229 ;
if ( ! F_2 ( V_1 ) ) {
struct V_235 * V_430 ;
if ( F_186 ( & V_5 -> V_309 , V_40 , & V_430 ) ) {
V_5 -> V_500 = 0 ;
return true ;
}
F_192 ( & V_5 -> V_309 , V_40 ) ;
V_5 -> V_500 = 1 ;
return false ;
}
if ( F_470 () )
V_138 = V_266 ;
F_233 ( V_5 -> V_52 -> V_53 [ V_485 ] , V_40 ) ;
if ( F_184 ( V_5 , V_138 , V_40 ) == 0 )
return true ;
F_184 ( V_5 , V_138 | V_248 , V_40 ) ;
return false ;
}
void F_471 ( struct V_4 * V_5 , unsigned int V_40 )
{
if ( ! F_2 ( V_1 ) ) {
F_162 ( & V_5 -> V_309 , V_40 ) ;
return;
}
F_472 ( V_5 -> V_52 -> V_53 [ V_485 ] , V_40 ) ;
F_162 ( & V_5 -> V_41 , V_40 ) ;
F_163 ( & V_5 -> V_9 , V_40 ) ;
}
static int T_16 F_473 ( char * V_501 )
{
char * V_502 ;
while ( ( V_502 = F_474 ( & V_501 , L_57 ) ) != NULL ) {
if ( ! * V_502 )
continue;
if ( ! strcmp ( V_502 , L_58 ) )
V_436 = true ;
if ( ! strcmp ( V_502 , L_59 ) )
V_317 = true ;
}
return 0 ;
}
static int T_16 F_475 ( void )
{
int V_51 , V_164 ;
F_476 ( F_177 , 0 ) ;
F_47 (cpu)
F_221 ( & F_477 ( & V_209 , V_51 ) -> V_217 ,
F_164 ) ;
F_39 (node) {
struct V_503 * V_504 ;
int V_12 ;
V_504 = F_350 ( sizeof( * V_504 ) , V_229 ,
F_478 ( V_164 ) ? V_164 : V_505 ) ;
for ( V_12 = 0 ; V_12 < V_44 ; V_12 ++ ) {
struct V_22 * V_506 ;
V_506 = & V_504 -> V_25 [ V_12 ] ;
V_506 -> V_31 = V_507 ;
F_359 ( & V_506 -> V_39 ) ;
}
V_23 . V_24 [ V_164 ] = V_504 ;
}
return 0 ;
}
void F_479 ( struct V_17 * V_17 , T_5 V_277 )
{
struct V_4 * V_5 ;
unsigned short V_508 ;
F_53 ( F_200 ( V_17 ) , V_17 ) ;
F_53 ( F_462 ( V_17 ) , V_17 ) ;
if ( ! F_1 () )
return;
V_5 = V_17 -> V_4 ;
if ( ! V_5 )
return;
F_340 ( V_5 ) ;
V_508 = F_480 ( V_277 , F_235 ( V_5 ) ) ;
F_53 ( V_508 , V_17 ) ;
F_232 ( V_5 , true ) ;
V_17 -> V_4 = NULL ;
if ( ! F_6 ( V_5 ) )
F_162 ( & V_5 -> V_41 , 1 ) ;
F_57 ( ! F_481 () ) ;
F_50 ( V_5 , V_17 , false , - 1 ) ;
F_65 ( V_5 , V_17 ) ;
if ( ! F_6 ( V_5 ) )
F_79 ( & V_5 -> V_9 ) ;
}
int F_482 ( struct V_17 * V_17 , T_5 V_277 )
{
struct V_4 * V_5 ;
struct V_235 * V_236 ;
unsigned short V_508 ;
if ( ! F_2 ( V_1 ) || ! V_2 )
return 0 ;
V_5 = V_17 -> V_4 ;
if ( ! V_5 )
return 0 ;
if ( ! F_6 ( V_5 ) &&
! F_186 ( & V_5 -> V_136 , 1 , & V_236 ) )
return - V_251 ;
F_340 ( V_5 ) ;
V_508 = F_480 ( V_277 , F_235 ( V_5 ) ) ;
F_53 ( V_508 , V_17 ) ;
F_232 ( V_5 , true ) ;
return 0 ;
}
void F_455 ( T_5 V_277 )
{
struct V_4 * V_5 ;
unsigned short V_255 ;
if ( ! V_2 )
return;
V_255 = F_480 ( V_277 , 0 ) ;
F_16 () ;
V_5 = F_344 ( V_255 ) ;
if ( V_5 ) {
if ( ! F_6 ( V_5 ) ) {
if ( F_2 ( V_1 ) )
F_162 ( & V_5 -> V_136 , 1 ) ;
else
F_162 ( & V_5 -> V_115 , 1 ) ;
}
F_232 ( V_5 , false ) ;
F_341 ( V_5 ) ;
}
F_20 () ;
}
long F_483 ( struct V_4 * V_5 )
{
long V_509 = F_484 () ;
if ( ! V_2 || ! F_2 ( V_1 ) )
return V_509 ;
for (; V_5 != V_6 ; V_5 = F_18 ( V_5 ) )
V_509 = F_485 ( long , V_509 ,
F_17 ( V_5 -> V_136 . V_114 ) -
F_36 ( & V_5 -> V_136 ) ) ;
return V_509 ;
}
bool F_486 ( struct V_17 * V_17 )
{
struct V_4 * V_5 ;
F_53 ( ! F_452 ( V_17 ) , V_17 ) ;
if ( F_487 () )
return true ;
if ( ! V_2 || ! F_2 ( V_1 ) )
return false ;
V_5 = V_17 -> V_4 ;
if ( ! V_5 )
return false ;
for (; V_5 != V_6 ; V_5 = F_18 ( V_5 ) )
if ( F_36 ( & V_5 -> V_136 ) * 2 >= V_5 -> V_136 . V_114 )
return true ;
return false ;
}
static int T_16 F_488 ( char * V_501 )
{
if ( ! strcmp ( V_501 , L_60 ) )
V_510 = 1 ;
else if ( ! strcmp ( V_501 , L_61 ) )
V_510 = 0 ;
return 1 ;
}
static V_125 F_489 ( struct V_7 * V_9 ,
struct V_298 * V_299 )
{
struct V_4 * V_5 = F_70 ( V_9 ) ;
return ( V_125 ) F_36 ( & V_5 -> V_136 ) * V_250 ;
}
static int F_490 ( struct V_328 * V_329 , void * V_330 )
{
struct V_4 * V_5 = F_70 ( F_280 ( V_329 ) ) ;
unsigned long F_185 = F_17 ( V_5 -> V_136 . V_114 ) ;
if ( F_185 == V_338 )
F_440 ( V_329 , L_37 ) ;
else
F_282 ( V_329 , L_38 , ( V_125 ) F_185 * V_250 ) ;
return 0 ;
}
static T_6 F_491 ( struct V_293 * V_294 ,
char * V_295 , T_7 V_296 , T_8 V_297 )
{
struct V_4 * V_5 = F_70 ( F_248 ( V_294 ) ) ;
unsigned long F_185 ;
int V_256 ;
V_295 = F_272 ( V_295 ) ;
V_256 = F_273 ( V_295 , L_39 , & F_185 ) ;
if ( V_256 )
return V_256 ;
F_114 ( & V_286 ) ;
V_256 = F_239 ( & V_5 -> V_136 , F_185 ) ;
F_129 ( & V_286 ) ;
if ( V_256 )
return V_256 ;
return V_296 ;
}
static int T_16 F_492 ( void )
{
if ( ! F_75 () && V_510 ) {
V_2 = 1 ;
F_268 ( F_493 ( & V_1 ,
V_511 ) ) ;
F_268 ( F_494 ( & V_1 ,
V_512 ) ) ;
}
return 0 ;
}
