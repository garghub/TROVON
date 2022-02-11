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
if ( F_75 () )
return;
V_26 = F_5 ( V_105 , struct V_11 , V_105 ) ;
V_68 = V_26 -> V_68 + V_67 ;
* V_68 += V_40 ;
F_57 ( ( long ) ( * V_68 ) < 0 ) ;
}
bool F_85 ( struct V_83 * V_106 , struct V_4 * V_5 )
{
struct V_4 * V_107 ;
struct V_83 * V_30 ;
bool V_108 ;
V_30 = F_86 ( V_106 ) ;
if ( V_30 ) {
V_107 = F_72 ( V_30 -> V_86 ) ;
F_87 ( V_30 ) ;
} else {
F_16 () ;
V_107 = F_69 ( V_106 ) ;
F_88 ( & V_107 -> V_9 ) ;
F_20 () ;
}
V_108 = F_89 ( V_107 , V_5 ) ;
F_79 ( & V_107 -> V_9 ) ;
return V_108 ;
}
static unsigned long F_90 ( struct V_4 * V_5 )
{
unsigned long V_109 = 0 ;
unsigned long V_53 ;
unsigned long V_110 ;
V_53 = F_36 ( & V_5 -> V_41 ) ;
V_110 = F_17 ( V_5 -> V_41 . V_110 ) ;
if ( V_53 < V_110 )
V_109 = V_110 - V_53 ;
if ( F_1 () ) {
V_53 = F_36 ( & V_5 -> V_111 ) ;
V_110 = F_17 ( V_5 -> V_111 . V_110 ) ;
if ( V_53 <= V_110 )
V_109 = F_91 ( V_109 , V_110 - V_53 ) ;
}
return V_109 ;
}
static bool F_92 ( struct V_4 * V_5 )
{
struct V_4 * V_112 ;
struct V_4 * V_113 ;
bool V_108 = false ;
F_93 ( & V_114 . V_39 ) ;
V_112 = V_114 . V_112 ;
V_113 = V_114 . V_113 ;
if ( ! V_112 )
goto V_115;
V_108 = F_89 ( V_112 , V_5 ) ||
F_89 ( V_113 , V_5 ) ;
V_115:
F_94 ( & V_114 . V_39 ) ;
return V_108 ;
}
static bool F_95 ( struct V_4 * V_5 )
{
if ( V_114 . V_116 && V_117 != V_114 . V_116 ) {
if ( F_92 ( V_5 ) ) {
F_96 ( V_118 ) ;
F_97 ( & V_114 . V_119 , & V_118 , V_120 ) ;
if ( V_114 . V_116 )
F_98 () ;
F_99 ( & V_114 . V_119 , & V_118 ) ;
return true ;
}
}
return false ;
}
void F_100 ( struct V_4 * V_5 , struct V_83 * V_30 )
{
struct V_4 * V_94 ;
unsigned int V_103 ;
F_16 () ;
if ( V_30 ) {
F_101 ( L_1 ) ;
F_102 ( F_103 ( V_30 , V_84 ) ) ;
F_104 ( L_2 ) ;
} else {
F_101 ( L_3 ) ;
}
F_102 ( V_5 -> V_9 . V_21 ) ;
F_104 ( L_4 ) ;
F_20 () ;
F_101 ( L_5 ,
F_105 ( ( V_121 ) F_36 ( & V_5 -> V_41 ) ) ,
F_105 ( ( V_121 ) V_5 -> V_41 . V_110 ) , V_5 -> V_41 . V_122 ) ;
F_101 ( L_6 ,
F_105 ( ( V_121 ) F_36 ( & V_5 -> V_111 ) ) ,
F_105 ( ( V_121 ) V_5 -> V_111 . V_110 ) , V_5 -> V_111 . V_122 ) ;
F_101 ( L_7 ,
F_105 ( ( V_121 ) F_36 ( & V_5 -> V_123 ) ) ,
F_105 ( ( V_121 ) V_5 -> V_123 . V_110 ) , V_5 -> V_123 . V_122 ) ;
F_106 (iter, memcg) {
F_101 ( L_8 ) ;
F_102 ( V_94 -> V_9 . V_21 ) ;
F_104 ( L_9 ) ;
for ( V_103 = 0 ; V_103 < V_124 ; V_103 ++ ) {
if ( V_103 == V_125 && ! V_2 )
continue;
F_104 ( L_10 , V_126 [ V_103 ] ,
F_105 ( F_46 ( V_94 , V_103 ) ) ) ;
}
for ( V_103 = 0 ; V_103 < V_127 ; V_103 ++ )
F_104 ( L_10 , V_128 [ V_103 ] ,
F_105 ( F_60 ( V_94 , F_59 ( V_103 ) ) ) ) ;
F_104 ( L_4 ) ;
}
}
static int F_107 ( struct V_4 * V_5 )
{
int V_129 = 0 ;
struct V_4 * V_94 ;
F_106 (iter, memcg)
V_129 ++ ;
return V_129 ;
}
static unsigned long F_108 ( struct V_4 * V_5 )
{
unsigned long V_110 ;
V_110 = V_5 -> V_41 . V_110 ;
if ( F_109 ( V_5 ) ) {
unsigned long V_130 ;
unsigned long V_131 ;
V_130 = V_5 -> V_111 . V_110 ;
V_131 = V_5 -> V_132 . V_110 ;
V_131 = F_91 ( V_131 , ( unsigned long ) V_133 ) ;
V_110 = F_91 ( V_110 + V_131 , V_130 ) ;
}
return V_110 ;
}
static bool F_110 ( struct V_4 * V_5 , T_3 V_134 ,
int V_135 )
{
struct V_136 V_137 = {
. V_138 = NULL ,
. V_139 = NULL ,
. V_134 = V_134 ,
. V_135 = V_135 ,
} ;
struct V_4 * V_94 ;
unsigned long V_140 = 0 ;
unsigned long V_141 ;
unsigned int V_142 = 0 ;
struct V_83 * V_143 = NULL ;
F_111 ( & V_144 ) ;
if ( F_112 ( V_117 ) || F_113 ( V_117 ) ) {
F_114 ( V_117 ) ;
goto V_115;
}
F_115 ( & V_137 , V_145 , V_5 ) ;
V_141 = F_108 ( V_5 ) ? : 1 ;
F_106 (iter, memcg) {
struct V_146 V_147 ;
struct V_83 * V_106 ;
F_116 ( & V_94 -> V_9 , & V_147 ) ;
while ( ( V_106 = F_117 ( & V_147 ) ) ) {
switch ( F_118 ( & V_137 , V_106 , V_141 ) ) {
case V_148 :
if ( V_143 )
F_119 ( V_143 ) ;
V_143 = V_106 ;
V_140 = V_149 ;
F_120 ( V_143 ) ;
case V_150 :
continue;
case V_151 :
F_121 ( & V_147 ) ;
F_80 ( V_5 , V_94 ) ;
if ( V_143 )
F_119 ( V_143 ) ;
goto V_115;
case V_152 :
break;
} ;
V_142 = F_122 ( V_106 , V_5 , NULL , V_141 ) ;
if ( ! V_142 || V_142 < V_140 )
continue;
if ( V_142 == V_140 &&
F_123 ( V_143 ) )
continue;
if ( V_143 )
F_119 ( V_143 ) ;
V_143 = V_106 ;
V_140 = V_142 ;
F_120 ( V_143 ) ;
}
F_121 ( & V_147 ) ;
}
if ( V_143 ) {
V_142 = V_140 * 1000 / V_141 ;
F_124 ( & V_137 , V_143 , V_142 , V_141 , V_5 ,
L_11 ) ;
}
V_115:
F_125 ( & V_144 ) ;
return V_143 ;
}
static bool F_126 ( struct V_4 * V_5 ,
int V_13 , bool V_153 )
{
if ( F_56 ( V_5 , V_13 , V_154 ) )
return true ;
if ( V_153 || ! V_133 )
return false ;
if ( F_56 ( V_5 , V_13 , V_155 ) )
return true ;
return false ;
}
static void F_127 ( struct V_4 * V_5 )
{
int V_13 ;
if ( ! F_128 ( & V_5 -> V_82 ) )
return;
if ( F_129 ( & V_5 -> V_156 ) > 1 )
return;
V_5 -> V_157 = V_158 [ V_159 ] ;
F_130 (nid, node_states[N_MEMORY]) {
if ( ! F_126 ( V_5 , V_13 , false ) )
F_131 ( V_13 , V_5 -> V_157 ) ;
}
F_132 ( & V_5 -> V_82 , 0 ) ;
F_132 ( & V_5 -> V_156 , 0 ) ;
}
int F_133 ( struct V_4 * V_5 )
{
int V_160 ;
F_127 ( V_5 ) ;
V_160 = V_5 -> V_161 ;
V_160 = F_134 ( V_160 , V_5 -> V_157 ) ;
if ( V_160 == V_81 )
V_160 = F_135 ( V_5 -> V_157 ) ;
if ( F_66 ( V_160 == V_81 ) )
V_160 = F_136 () ;
V_5 -> V_161 = V_160 ;
return V_160 ;
}
int F_133 ( struct V_4 * V_5 )
{
return 0 ;
}
static int F_137 ( struct V_4 * V_162 ,
struct V_12 * V_12 ,
T_3 V_134 ,
unsigned long * V_163 )
{
struct V_4 * V_164 = NULL ;
int V_165 = 0 ;
int V_166 = 0 ;
unsigned long V_43 ;
unsigned long V_167 ;
struct V_90 V_91 = {
. V_12 = V_12 ,
. V_98 = 0 ,
} ;
V_43 = F_35 ( V_162 ) ;
while ( 1 ) {
V_164 = F_74 ( V_162 , V_164 , & V_91 ) ;
if ( ! V_164 ) {
V_166 ++ ;
if ( V_166 >= 2 ) {
if ( ! V_165 )
break;
if ( V_165 >= ( V_43 >> 2 ) ||
( V_166 > V_168 ) )
break;
}
continue;
}
V_165 += F_138 ( V_164 , V_134 , false ,
V_12 , & V_167 ) ;
* V_163 += V_167 ;
if ( ! F_35 ( V_162 ) )
break;
}
F_80 ( V_162 , V_164 ) ;
return V_165 ;
}
static bool F_139 ( struct V_4 * V_5 )
{
struct V_4 * V_94 , * V_169 = NULL ;
F_93 ( & V_170 ) ;
F_106 (iter, memcg) {
if ( V_94 -> V_144 ) {
V_169 = V_94 ;
F_80 ( V_5 , V_94 ) ;
break;
} else
V_94 -> V_144 = true ;
}
if ( V_169 ) {
F_106 (iter, memcg) {
if ( V_94 == V_169 ) {
F_80 ( V_5 , V_94 ) ;
break;
}
V_94 -> V_144 = false ;
}
} else
F_140 ( & V_171 , 0 , 1 , V_172 ) ;
F_94 ( & V_170 ) ;
return ! V_169 ;
}
static void F_141 ( struct V_4 * V_5 )
{
struct V_4 * V_94 ;
F_93 ( & V_170 ) ;
F_142 ( & V_171 , 1 , V_172 ) ;
F_106 (iter, memcg)
V_94 -> V_144 = false ;
F_94 ( & V_170 ) ;
}
static void F_143 ( struct V_4 * V_5 )
{
struct V_4 * V_94 ;
F_93 ( & V_170 ) ;
F_106 (iter, memcg)
V_94 -> V_173 ++ ;
F_94 ( & V_170 ) ;
}
static void F_144 ( struct V_4 * V_5 )
{
struct V_4 * V_94 ;
F_93 ( & V_170 ) ;
F_106 (iter, memcg)
if ( V_94 -> V_173 > 0 )
V_94 -> V_173 -- ;
F_94 ( & V_170 ) ;
}
static int F_145 ( T_4 * V_118 ,
unsigned V_174 , int V_175 , void * V_176 )
{
struct V_4 * V_177 = (struct V_4 * ) V_176 ;
struct V_4 * V_178 ;
struct V_179 * V_179 ;
V_179 = F_5 ( V_118 , struct V_179 , V_118 ) ;
V_178 = V_179 -> V_5 ;
if ( ! F_89 ( V_177 , V_178 ) &&
! F_89 ( V_178 , V_177 ) )
return 0 ;
return F_146 ( V_118 , V_174 , V_175 , V_176 ) ;
}
static void F_147 ( struct V_4 * V_5 )
{
if ( V_5 && V_5 -> V_173 )
F_148 ( & V_180 , V_181 , 0 , V_5 ) ;
}
static void F_149 ( struct V_4 * V_5 , T_3 V_182 , int V_135 )
{
if ( ! V_117 -> V_183 )
return;
F_88 ( & V_5 -> V_9 ) ;
V_117 -> V_184 = V_5 ;
V_117 -> V_185 = V_182 ;
V_117 -> V_186 = V_135 ;
}
bool F_150 ( bool V_187 )
{
struct V_4 * V_5 = V_117 -> V_184 ;
struct V_179 V_188 ;
bool V_189 ;
if ( ! V_5 )
return false ;
if ( ! V_187 || V_190 )
goto V_191;
V_188 . V_5 = V_5 ;
V_188 . V_118 . V_19 = 0 ;
V_188 . V_118 . V_192 = F_145 ;
V_188 . V_118 . V_193 = V_117 ;
F_151 ( & V_188 . V_118 . V_194 ) ;
F_97 ( & V_180 , & V_188 . V_118 , V_195 ) ;
F_143 ( V_5 ) ;
V_189 = F_139 ( V_5 ) ;
if ( V_189 )
F_152 ( V_5 ) ;
if ( V_189 && ! V_5 -> V_196 ) {
F_144 ( V_5 ) ;
F_99 ( & V_180 , & V_188 . V_118 ) ;
F_110 ( V_5 , V_117 -> V_185 ,
V_117 -> V_186 ) ;
} else {
F_98 () ;
F_144 ( V_5 ) ;
F_99 ( & V_180 , & V_188 . V_118 ) ;
}
if ( V_189 ) {
F_141 ( V_5 ) ;
F_147 ( V_5 ) ;
}
V_191:
V_117 -> V_184 = NULL ;
F_79 ( & V_5 -> V_9 ) ;
return true ;
}
void F_153 ( struct V_17 * V_17 )
{
struct V_4 * V_5 ;
unsigned long V_19 ;
F_16 () ;
if ( F_75 () )
return;
V_197:
V_5 = V_17 -> V_4 ;
if ( F_66 ( ! V_5 ) )
return;
if ( F_128 ( & V_5 -> V_198 ) <= 0 )
return;
F_33 ( & V_5 -> V_199 , V_19 ) ;
if ( V_5 != V_17 -> V_4 ) {
F_34 ( & V_5 -> V_199 , V_19 ) ;
goto V_197;
}
V_5 -> V_200 = V_117 ;
V_5 -> V_201 = V_19 ;
return;
}
void F_154 ( struct V_17 * V_17 )
{
struct V_4 * V_5 = V_17 -> V_4 ;
if ( V_5 && V_5 -> V_200 == V_117 ) {
unsigned long V_19 = V_5 -> V_201 ;
V_5 -> V_200 = NULL ;
V_5 -> V_201 = 0 ;
F_34 ( & V_5 -> V_199 , V_19 ) ;
}
F_20 () ;
}
static bool F_155 ( struct V_4 * V_5 , unsigned int V_40 )
{
struct V_202 * V_203 ;
bool V_108 = false ;
if ( V_40 > V_204 )
return V_108 ;
V_203 = & F_156 ( V_205 ) ;
if ( V_5 == V_203 -> V_206 && V_203 -> V_40 >= V_40 ) {
V_203 -> V_40 -= V_40 ;
V_108 = true ;
}
F_157 ( V_205 ) ;
return V_108 ;
}
static void F_158 ( struct V_202 * V_203 )
{
struct V_4 * V_207 = V_203 -> V_206 ;
if ( V_203 -> V_40 ) {
F_159 ( & V_207 -> V_41 , V_203 -> V_40 ) ;
if ( F_1 () )
F_159 ( & V_207 -> V_111 , V_203 -> V_40 ) ;
F_160 ( & V_207 -> V_9 , V_203 -> V_40 ) ;
V_203 -> V_40 = 0 ;
}
V_203 -> V_206 = NULL ;
}
static void F_161 ( struct V_208 * V_209 )
{
struct V_202 * V_203 = F_162 ( & V_205 ) ;
F_158 ( V_203 ) ;
F_163 ( V_210 , & V_203 -> V_19 ) ;
}
static void F_164 ( struct V_4 * V_5 , unsigned int V_40 )
{
struct V_202 * V_203 = & F_156 ( V_205 ) ;
if ( V_203 -> V_206 != V_5 ) {
F_158 ( V_203 ) ;
V_203 -> V_206 = V_5 ;
}
V_203 -> V_40 += V_40 ;
F_157 ( V_205 ) ;
}
static void F_165 ( struct V_4 * V_162 )
{
int V_51 , V_211 ;
if ( ! F_166 ( & V_212 ) )
return;
F_167 () ;
V_211 = F_168 () ;
F_169 (cpu) {
struct V_202 * V_203 = & F_48 ( V_205 , V_51 ) ;
struct V_4 * V_5 ;
V_5 = V_203 -> V_206 ;
if ( ! V_5 || ! V_203 -> V_40 )
continue;
if ( ! F_89 ( V_5 , V_162 ) )
continue;
if ( ! F_170 ( V_210 , & V_203 -> V_19 ) ) {
if ( V_51 == V_211 )
F_161 ( & V_203 -> V_213 ) ;
else
F_171 ( V_51 , & V_203 -> V_213 ) ;
}
}
F_172 () ;
F_173 () ;
F_125 ( & V_212 ) ;
}
static int F_174 ( struct V_214 * V_215 ,
unsigned long V_216 ,
void * V_217 )
{
int V_51 = ( unsigned long ) V_217 ;
struct V_202 * V_203 ;
if ( V_216 == V_218 )
return V_219 ;
if ( V_216 != V_220 && V_216 != V_221 )
return V_219 ;
V_203 = & F_48 ( V_205 , V_51 ) ;
F_158 ( V_203 ) ;
return V_219 ;
}
static void F_175 ( struct V_4 * V_5 ,
unsigned int V_40 ,
T_3 V_134 )
{
do {
if ( F_36 ( & V_5 -> V_41 ) <= V_5 -> V_222 )
continue;
F_176 ( V_5 , V_223 , 1 ) ;
F_177 ( V_5 , V_40 , V_134 , true ) ;
} while ( ( V_5 = F_18 ( V_5 ) ) );
}
static void F_178 ( struct V_208 * V_213 )
{
struct V_4 * V_5 ;
V_5 = F_5 ( V_213 , struct V_4 , V_224 ) ;
F_175 ( V_5 , V_204 , V_225 ) ;
}
void F_179 ( void )
{
unsigned int V_40 = V_117 -> V_226 ;
struct V_4 * V_5 ;
if ( F_180 ( ! V_40 ) )
return;
V_5 = F_72 ( V_117 -> V_86 ) ;
F_175 ( V_5 , V_40 , V_225 ) ;
F_79 ( & V_5 -> V_9 ) ;
V_117 -> V_226 = 0 ;
}
static int F_181 ( struct V_4 * V_5 , T_3 V_134 ,
unsigned int V_40 )
{
unsigned int V_227 = F_182 ( V_204 , V_40 ) ;
int V_228 = V_229 ;
struct V_4 * V_230 ;
struct V_231 * V_232 ;
unsigned long V_233 ;
bool V_234 = true ;
bool V_235 = false ;
if ( F_6 ( V_5 ) )
return 0 ;
V_46:
if ( F_155 ( V_5 , V_40 ) )
return 0 ;
if ( ! F_1 () ||
F_183 ( & V_5 -> V_111 , V_227 , & V_232 ) ) {
if ( F_183 ( & V_5 -> V_41 , V_227 , & V_232 ) )
goto V_236;
if ( F_1 () )
F_159 ( & V_5 -> V_111 , V_227 ) ;
V_230 = F_184 ( V_232 , V_41 ) ;
} else {
V_230 = F_184 ( V_232 , V_111 ) ;
V_234 = false ;
}
if ( V_227 > V_40 ) {
V_227 = V_40 ;
goto V_46;
}
if ( F_66 ( F_185 ( V_237 ) ||
F_112 ( V_117 ) ||
V_117 -> V_19 & V_238 ) )
goto V_239;
if ( F_66 ( F_186 ( V_117 ) ) )
goto V_240;
if ( ! F_187 ( V_134 ) )
goto V_240;
F_176 ( V_230 , V_241 , 1 ) ;
V_233 = F_177 ( V_230 , V_40 ,
V_134 , V_234 ) ;
if ( F_90 ( V_230 ) >= V_40 )
goto V_46;
if ( ! V_235 ) {
F_165 ( V_230 ) ;
V_235 = true ;
goto V_46;
}
if ( V_134 & V_242 )
goto V_240;
if ( V_233 && V_40 <= ( 1 << V_243 ) )
goto V_46;
if ( F_95 ( V_230 ) )
goto V_46;
if ( V_228 -- )
goto V_46;
if ( V_134 & V_244 )
goto V_239;
if ( F_112 ( V_117 ) )
goto V_239;
F_176 ( V_230 , V_245 , 1 ) ;
F_149 ( V_230 , V_134 ,
F_188 ( V_40 * V_246 ) ) ;
V_240:
if ( ! ( V_134 & V_244 ) )
return - V_247 ;
V_239:
F_189 ( & V_5 -> V_41 , V_40 ) ;
if ( F_1 () )
F_189 ( & V_5 -> V_111 , V_40 ) ;
F_190 ( & V_5 -> V_9 , V_40 ) ;
return 0 ;
V_236:
F_190 ( & V_5 -> V_9 , V_227 ) ;
if ( V_227 > V_40 )
F_164 ( V_5 , V_227 - V_40 ) ;
do {
if ( F_36 ( & V_5 -> V_41 ) > V_5 -> V_222 ) {
if ( F_191 () ) {
F_192 ( & V_5 -> V_224 ) ;
break;
}
V_117 -> V_226 += V_227 ;
F_193 ( V_117 ) ;
break;
}
} while ( ( V_5 = F_18 ( V_5 ) ) );
return 0 ;
}
static void F_194 ( struct V_4 * V_5 , unsigned int V_40 )
{
if ( F_6 ( V_5 ) )
return;
F_159 ( & V_5 -> V_41 , V_40 ) ;
if ( F_1 () )
F_159 ( & V_5 -> V_111 , V_40 ) ;
F_160 ( & V_5 -> V_9 , V_40 ) ;
}
static void F_195 ( struct V_17 * V_17 , int * V_248 )
{
struct V_12 * V_12 = F_196 ( V_17 ) ;
F_44 ( & V_12 -> V_249 ) ;
if ( F_197 ( V_17 ) ) {
struct V_105 * V_105 ;
V_105 = F_83 ( V_17 , V_12 ) ;
F_198 ( V_17 ) ;
F_199 ( V_17 , V_105 , F_200 ( V_17 ) ) ;
* V_248 = 1 ;
} else
* V_248 = 0 ;
}
static void F_201 ( struct V_17 * V_17 , int V_248 )
{
struct V_12 * V_12 = F_196 ( V_17 ) ;
if ( V_248 ) {
struct V_105 * V_105 ;
V_105 = F_83 ( V_17 , V_12 ) ;
F_53 ( F_197 ( V_17 ) , V_17 ) ;
F_202 ( V_17 ) ;
F_203 ( V_17 , V_105 , F_200 ( V_17 ) ) ;
}
F_45 ( & V_12 -> V_249 ) ;
}
static void F_204 ( struct V_17 * V_17 , struct V_4 * V_5 ,
bool V_250 )
{
int V_248 ;
F_53 ( V_17 -> V_4 , V_17 ) ;
if ( V_250 )
F_195 ( V_17 , & V_248 ) ;
V_17 -> V_4 = V_5 ;
if ( V_250 )
F_201 ( V_17 , V_248 ) ;
}
static int F_205 ( void )
{
int V_251 , V_252 ;
int V_253 ;
V_251 = F_206 ( & V_254 ,
0 , V_255 , V_225 ) ;
if ( V_251 < 0 )
return V_251 ;
if ( V_251 < V_256 )
return V_251 ;
F_207 ( & V_10 ) ;
V_252 = 2 * ( V_251 + 1 ) ;
if ( V_252 < V_257 )
V_252 = V_257 ;
else if ( V_252 > V_255 )
V_252 = V_255 ;
V_253 = F_208 ( V_252 ) ;
if ( ! V_253 )
V_253 = F_209 ( V_252 ) ;
if ( ! V_253 )
V_256 = V_252 ;
F_210 ( & V_10 ) ;
if ( V_253 ) {
F_211 ( & V_254 , V_251 ) ;
return V_253 ;
}
return V_251 ;
}
static void F_212 ( int V_251 )
{
F_211 ( & V_254 , V_251 ) ;
}
static void F_213 ( struct V_208 * V_258 )
{
struct V_259 * V_260 =
F_5 ( V_258 , struct V_259 , V_213 ) ;
struct V_4 * V_5 = V_260 -> V_5 ;
struct V_261 * V_262 = V_260 -> V_262 ;
F_214 ( V_5 , V_262 ) ;
F_79 ( & V_5 -> V_9 ) ;
F_215 ( V_260 ) ;
}
static void F_216 ( struct V_4 * V_5 ,
struct V_261 * V_262 )
{
struct V_259 * V_260 ;
V_260 = F_217 ( sizeof( * V_260 ) , V_263 ) ;
if ( ! V_260 )
return;
F_88 ( & V_5 -> V_9 ) ;
V_260 -> V_5 = V_5 ;
V_260 -> V_262 = V_262 ;
F_218 ( & V_260 -> V_213 , F_213 ) ;
F_192 ( & V_260 -> V_213 ) ;
}
static void F_219 ( struct V_4 * V_5 ,
struct V_261 * V_262 )
{
V_117 -> V_264 = 1 ;
F_216 ( V_5 , V_262 ) ;
V_117 -> V_264 = 0 ;
}
struct V_261 * F_220 ( struct V_261 * V_262 , T_3 V_265 )
{
struct V_4 * V_5 ;
struct V_261 * V_266 ;
int V_267 ;
F_57 ( ! F_221 ( V_262 ) ) ;
if ( V_262 -> V_19 & V_268 )
V_265 |= V_269 ;
if ( ! ( V_265 & V_269 ) )
return V_262 ;
if ( V_117 -> V_264 )
return V_262 ;
V_5 = F_72 ( V_117 -> V_86 ) ;
V_267 = F_17 ( V_5 -> V_267 ) ;
if ( V_267 < 0 )
goto V_97;
V_266 = F_222 ( V_262 , V_267 ) ;
if ( F_180 ( V_266 ) )
return V_266 ;
F_219 ( V_5 , V_262 ) ;
V_97:
F_79 ( & V_5 -> V_9 ) ;
return V_262 ;
}
void F_223 ( struct V_261 * V_262 )
{
if ( ! F_221 ( V_262 ) )
F_79 ( & V_262 -> V_270 . V_5 -> V_9 ) ;
}
int F_224 ( struct V_17 * V_17 , T_3 V_265 , int V_135 ,
struct V_4 * V_5 )
{
unsigned int V_40 = 1 << V_135 ;
struct V_231 * V_232 ;
int V_108 ;
V_108 = F_181 ( V_5 , V_265 , V_40 ) ;
if ( V_108 )
return V_108 ;
if ( ! F_2 ( V_1 ) &&
! F_183 ( & V_5 -> V_123 , V_40 , & V_232 ) ) {
F_194 ( V_5 , V_40 ) ;
return - V_247 ;
}
V_17 -> V_4 = V_5 ;
return 0 ;
}
int F_225 ( struct V_17 * V_17 , T_3 V_265 , int V_135 )
{
struct V_4 * V_5 ;
int V_108 = 0 ;
V_5 = F_72 ( V_117 -> V_86 ) ;
if ( ! F_6 ( V_5 ) )
V_108 = F_224 ( V_17 , V_265 , V_135 , V_5 ) ;
F_79 ( & V_5 -> V_9 ) ;
return V_108 ;
}
void F_226 ( struct V_17 * V_17 , int V_135 )
{
struct V_4 * V_5 = V_17 -> V_4 ;
unsigned int V_40 = 1 << V_135 ;
if ( ! V_5 )
return;
F_53 ( F_6 ( V_5 ) , V_17 ) ;
if ( ! F_2 ( V_1 ) )
F_159 ( & V_5 -> V_123 , V_40 ) ;
F_159 ( & V_5 -> V_41 , V_40 ) ;
if ( F_1 () )
F_159 ( & V_5 -> V_111 , V_40 ) ;
V_17 -> V_4 = NULL ;
F_160 ( & V_5 -> V_9 , V_40 ) ;
}
void F_227 ( struct V_17 * V_271 )
{
int V_103 ;
if ( F_75 () )
return;
for ( V_103 = 1 ; V_103 < V_272 ; V_103 ++ )
V_271 [ V_103 ] . V_4 = V_271 -> V_4 ;
F_228 ( V_271 -> V_4 -> V_52 -> V_53 [ V_59 ] ,
V_272 ) ;
}
static void F_229 ( struct V_4 * V_5 ,
bool V_273 )
{
int V_50 = ( V_273 ) ? 1 : - 1 ;
F_230 ( V_5 -> V_52 -> V_53 [ V_125 ] , V_50 ) ;
}
static int F_231 ( T_5 V_274 ,
struct V_4 * V_112 , struct V_4 * V_113 )
{
unsigned short V_275 , V_276 ;
V_275 = F_232 ( V_112 ) ;
V_276 = F_232 ( V_113 ) ;
if ( F_233 ( V_274 , V_275 , V_276 ) == V_275 ) {
F_229 ( V_112 , false ) ;
F_229 ( V_113 , true ) ;
return 0 ;
}
return - V_277 ;
}
static inline int F_231 ( T_5 V_274 ,
struct V_4 * V_112 , struct V_4 * V_113 )
{
return - V_277 ;
}
static int F_234 ( struct V_4 * V_5 ,
unsigned long V_110 )
{
unsigned long V_278 ;
unsigned long V_279 ;
bool V_280 = false ;
int V_281 ;
int V_108 ;
V_281 = V_229 *
F_107 ( V_5 ) ;
V_279 = F_36 ( & V_5 -> V_41 ) ;
do {
if ( F_235 ( V_117 ) ) {
V_108 = - V_282 ;
break;
}
F_111 ( & V_283 ) ;
if ( V_110 > V_5 -> V_111 . V_110 ) {
F_125 ( & V_283 ) ;
V_108 = - V_277 ;
break;
}
if ( V_110 > V_5 -> V_41 . V_110 )
V_280 = true ;
V_108 = F_236 ( & V_5 -> V_41 , V_110 ) ;
F_125 ( & V_283 ) ;
if ( ! V_108 )
break;
F_177 ( V_5 , 1 , V_225 , true ) ;
V_278 = F_36 ( & V_5 -> V_41 ) ;
if ( V_278 >= V_279 )
V_281 -- ;
else
V_279 = V_278 ;
} while ( V_281 );
if ( ! V_108 && V_280 )
F_147 ( V_5 ) ;
return V_108 ;
}
static int F_237 ( struct V_4 * V_5 ,
unsigned long V_110 )
{
unsigned long V_278 ;
unsigned long V_279 ;
bool V_280 = false ;
int V_281 ;
int V_108 ;
V_281 = V_229 *
F_107 ( V_5 ) ;
V_279 = F_36 ( & V_5 -> V_111 ) ;
do {
if ( F_235 ( V_117 ) ) {
V_108 = - V_282 ;
break;
}
F_111 ( & V_283 ) ;
if ( V_110 < V_5 -> V_41 . V_110 ) {
F_125 ( & V_283 ) ;
V_108 = - V_277 ;
break;
}
if ( V_110 > V_5 -> V_111 . V_110 )
V_280 = true ;
V_108 = F_236 ( & V_5 -> V_111 , V_110 ) ;
F_125 ( & V_283 ) ;
if ( ! V_108 )
break;
F_177 ( V_5 , 1 , V_225 , false ) ;
V_278 = F_36 ( & V_5 -> V_111 ) ;
if ( V_278 >= V_279 )
V_281 -- ;
else
V_279 = V_278 ;
} while ( V_281 );
if ( ! V_108 && V_280 )
F_147 ( V_5 ) ;
return V_108 ;
}
unsigned long F_238 ( struct V_12 * V_12 , int V_135 ,
T_3 V_134 ,
unsigned long * V_163 )
{
unsigned long V_233 = 0 ;
struct V_11 * V_26 , * V_284 = NULL ;
unsigned long V_285 ;
int V_166 = 0 ;
struct V_22 * V_27 ;
unsigned long V_43 ;
unsigned long V_167 ;
if ( V_135 > 0 )
return 0 ;
V_27 = F_24 ( F_12 ( V_12 ) , F_13 ( V_12 ) ) ;
do {
if ( V_284 )
V_26 = V_284 ;
else
V_26 = F_43 ( V_27 ) ;
if ( ! V_26 )
break;
V_167 = 0 ;
V_285 = F_137 ( V_26 -> V_5 , V_12 ,
V_134 , & V_167 ) ;
V_233 += V_285 ;
* V_163 += V_167 ;
F_44 ( & V_27 -> V_39 ) ;
F_30 ( V_26 , V_27 ) ;
V_284 = NULL ;
if ( ! V_285 )
V_284 = F_40 ( V_27 ) ;
V_43 = F_35 ( V_26 -> V_5 ) ;
F_26 ( V_26 , V_27 , V_43 ) ;
F_45 ( & V_27 -> V_39 ) ;
F_79 ( & V_26 -> V_5 -> V_9 ) ;
V_166 ++ ;
if ( ! V_233 &&
( V_284 == NULL ||
V_166 > V_286 ) )
break;
} while ( ! V_233 );
if ( V_284 )
F_79 ( & V_284 -> V_5 -> V_9 ) ;
return V_233 ;
}
static inline bool F_239 ( struct V_4 * V_5 )
{
bool V_108 ;
F_16 () ;
V_108 = F_240 ( NULL , & V_5 -> V_9 ) ;
F_20 () ;
return V_108 ;
}
static int F_241 ( struct V_4 * V_5 )
{
int V_228 = V_229 ;
F_242 () ;
while ( V_228 && F_36 ( & V_5 -> V_41 ) ) {
int V_287 ;
if ( F_235 ( V_117 ) )
return - V_282 ;
V_287 = F_177 ( V_5 , 1 ,
V_225 , true ) ;
if ( ! V_287 ) {
V_228 -- ;
F_243 ( V_288 , V_289 / 10 ) ;
}
}
return 0 ;
}
static T_6 F_244 ( struct V_290 * V_291 ,
char * V_292 , T_7 V_293 ,
T_8 V_294 )
{
struct V_4 * V_5 = F_70 ( F_245 ( V_291 ) ) ;
if ( F_6 ( V_5 ) )
return - V_277 ;
return F_241 ( V_5 ) ? : V_293 ;
}
static V_121 F_246 ( struct V_7 * V_9 ,
struct V_295 * V_296 )
{
return F_70 ( V_9 ) -> V_96 ;
}
static int F_247 ( struct V_7 * V_9 ,
struct V_295 * V_296 , V_121 V_50 )
{
int V_297 = 0 ;
struct V_4 * V_5 = F_70 ( V_9 ) ;
struct V_4 * V_298 = F_70 ( V_5 -> V_9 . V_32 ) ;
if ( V_5 -> V_96 == V_50 )
return 0 ;
if ( ( ! V_298 || ! V_298 -> V_96 ) &&
( V_50 == 1 || V_50 == 0 ) ) {
if ( ! F_239 ( V_5 ) )
V_5 -> V_96 = V_50 ;
else
V_297 = - V_299 ;
} else
V_297 = - V_277 ;
return V_297 ;
}
static void F_248 ( struct V_4 * V_5 , unsigned long * V_52 )
{
struct V_4 * V_94 ;
int V_103 ;
memset ( V_52 , 0 , sizeof( * V_52 ) * V_300 ) ;
F_106 (iter, memcg) {
for ( V_103 = 0 ; V_103 < V_300 ; V_103 ++ )
V_52 [ V_103 ] += F_46 ( V_94 , V_103 ) ;
}
}
static void F_249 ( struct V_4 * V_5 , unsigned long * V_55 )
{
struct V_4 * V_94 ;
int V_103 ;
memset ( V_55 , 0 , sizeof( * V_55 ) * V_301 ) ;
F_106 (iter, memcg) {
for ( V_103 = 0 ; V_103 < V_301 ; V_103 ++ )
V_55 [ V_103 ] += F_49 ( V_94 , V_103 ) ;
}
}
static unsigned long F_250 ( struct V_4 * V_5 , bool V_132 )
{
unsigned long V_50 = 0 ;
if ( F_6 ( V_5 ) ) {
struct V_4 * V_94 ;
F_106 (iter, memcg) {
V_50 += F_46 ( V_94 ,
V_58 ) ;
V_50 += F_46 ( V_94 ,
V_57 ) ;
if ( V_132 )
V_50 += F_46 ( V_94 ,
V_125 ) ;
}
} else {
if ( ! V_132 )
V_50 = F_36 ( & V_5 -> V_41 ) ;
else
V_50 = F_36 ( & V_5 -> V_111 ) ;
}
return V_50 ;
}
static V_121 F_251 ( struct V_7 * V_9 ,
struct V_295 * V_296 )
{
struct V_4 * V_5 = F_70 ( V_9 ) ;
struct V_231 * V_232 ;
switch ( F_252 ( V_296 -> V_193 ) ) {
case V_302 :
V_232 = & V_5 -> V_41 ;
break;
case V_303 :
V_232 = & V_5 -> V_111 ;
break;
case V_304 :
V_232 = & V_5 -> V_123 ;
break;
case V_305 :
V_232 = & V_5 -> V_306 ;
break;
default:
F_253 () ;
}
switch ( F_254 ( V_296 -> V_193 ) ) {
case V_307 :
if ( V_232 == & V_5 -> V_41 )
return ( V_121 ) F_250 ( V_5 , false ) * V_246 ;
if ( V_232 == & V_5 -> V_111 )
return ( V_121 ) F_250 ( V_5 , true ) * V_246 ;
return ( V_121 ) F_36 ( V_232 ) * V_246 ;
case V_308 :
return ( V_121 ) V_232 -> V_110 * V_246 ;
case V_309 :
return ( V_121 ) V_232 -> V_310 * V_246 ;
case V_311 :
return V_232 -> V_122 ;
case V_312 :
return ( V_121 ) V_5 -> V_42 * V_246 ;
default:
F_253 () ;
}
}
static int F_255 ( struct V_4 * V_5 )
{
int V_313 ;
if ( V_314 )
return 0 ;
F_256 ( V_5 -> V_267 >= 0 ) ;
F_256 ( V_5 -> V_315 ) ;
V_313 = F_205 () ;
if ( V_313 < 0 )
return V_313 ;
F_257 ( & V_316 ) ;
V_5 -> V_267 = V_313 ;
V_5 -> V_315 = V_317 ;
return 0 ;
}
static void F_258 ( struct V_4 * V_5 )
{
struct V_7 * V_9 ;
struct V_4 * V_32 , * V_318 ;
int V_267 ;
if ( V_5 -> V_315 != V_317 )
return;
V_5 -> V_315 = V_319 ;
F_259 ( V_5 ) ;
V_267 = V_5 -> V_267 ;
F_256 ( V_267 < 0 ) ;
V_32 = F_18 ( V_5 ) ;
if ( ! V_32 )
V_32 = V_6 ;
F_260 (css, &memcg->css) {
V_318 = F_70 ( V_9 ) ;
F_256 ( V_318 -> V_267 != V_267 ) ;
V_318 -> V_267 = V_32 -> V_267 ;
if ( ! V_5 -> V_96 )
break;
}
F_261 ( V_267 , V_32 -> V_267 ) ;
F_212 ( V_267 ) ;
}
static void F_262 ( struct V_4 * V_5 )
{
if ( F_66 ( V_5 -> V_315 == V_317 ) )
F_258 ( V_5 ) ;
if ( V_5 -> V_315 == V_319 ) {
F_263 ( V_5 ) ;
F_264 ( & V_316 ) ;
F_265 ( F_36 ( & V_5 -> V_123 ) ) ;
}
}
static int F_255 ( struct V_4 * V_5 )
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
unsigned long V_110 )
{
int V_108 ;
F_111 ( & V_283 ) ;
V_108 = F_236 ( & V_5 -> V_123 , V_110 ) ;
F_125 ( & V_283 ) ;
return V_108 ;
}
static int F_267 ( struct V_4 * V_5 , unsigned long V_110 )
{
int V_108 ;
F_111 ( & V_283 ) ;
V_108 = F_236 ( & V_5 -> V_306 , V_110 ) ;
if ( V_108 )
goto V_97;
if ( ! V_5 -> V_320 ) {
F_257 ( & V_321 ) ;
V_5 -> V_320 = true ;
}
V_97:
F_125 ( & V_283 ) ;
return V_108 ;
}
static T_6 F_268 ( struct V_290 * V_291 ,
char * V_292 , T_7 V_293 , T_8 V_294 )
{
struct V_4 * V_5 = F_70 ( F_245 ( V_291 ) ) ;
unsigned long V_40 ;
int V_108 ;
V_292 = F_269 ( V_292 ) ;
V_108 = F_270 ( V_292 , L_12 , & V_40 ) ;
if ( V_108 )
return V_108 ;
switch ( F_254 ( F_271 ( V_291 ) -> V_193 ) ) {
case V_308 :
if ( F_6 ( V_5 ) ) {
V_108 = - V_277 ;
break;
}
switch ( F_252 ( F_271 ( V_291 ) -> V_193 ) ) {
case V_302 :
V_108 = F_234 ( V_5 , V_40 ) ;
break;
case V_303 :
V_108 = F_237 ( V_5 , V_40 ) ;
break;
case V_304 :
V_108 = F_266 ( V_5 , V_40 ) ;
break;
case V_305 :
V_108 = F_267 ( V_5 , V_40 ) ;
break;
}
break;
case V_312 :
V_5 -> V_42 = V_40 ;
V_108 = 0 ;
break;
}
return V_108 ? : V_293 ;
}
static T_6 F_272 ( struct V_290 * V_291 , char * V_292 ,
T_7 V_293 , T_8 V_294 )
{
struct V_4 * V_5 = F_70 ( F_245 ( V_291 ) ) ;
struct V_231 * V_232 ;
switch ( F_252 ( F_271 ( V_291 ) -> V_193 ) ) {
case V_302 :
V_232 = & V_5 -> V_41 ;
break;
case V_303 :
V_232 = & V_5 -> V_111 ;
break;
case V_304 :
V_232 = & V_5 -> V_123 ;
break;
case V_305 :
V_232 = & V_5 -> V_306 ;
break;
default:
F_253 () ;
}
switch ( F_254 ( F_271 ( V_291 ) -> V_193 ) ) {
case V_309 :
F_273 ( V_232 ) ;
break;
case V_311 :
V_232 -> V_122 = 0 ;
break;
default:
F_253 () ;
}
return V_293 ;
}
static V_121 F_274 ( struct V_7 * V_9 ,
struct V_295 * V_296 )
{
return F_70 ( V_9 ) -> V_322 ;
}
static int F_275 ( struct V_7 * V_9 ,
struct V_295 * V_296 , V_121 V_50 )
{
struct V_4 * V_5 = F_70 ( V_9 ) ;
if ( V_50 & ~ V_323 )
return - V_277 ;
V_5 -> V_322 = V_50 ;
return 0 ;
}
static int F_275 ( struct V_7 * V_9 ,
struct V_295 * V_296 , V_121 V_50 )
{
return - V_324 ;
}
static int F_276 ( struct V_325 * V_326 , void * V_327 )
{
struct V_328 {
const char * V_329 ;
unsigned int V_63 ;
};
static const struct V_328 V_330 [] = {
{ L_13 , V_331 } ,
{ L_14 , V_154 } ,
{ L_15 , V_155 } ,
{ L_16 , F_59 (LRU_UNEVICTABLE) } ,
} ;
const struct V_328 * V_52 ;
int V_13 ;
unsigned long V_64 ;
struct V_4 * V_5 = F_70 ( F_277 ( V_326 ) ) ;
for ( V_52 = V_330 ; V_52 < V_330 + F_278 ( V_330 ) ; V_52 ++ ) {
V_64 = F_60 ( V_5 , V_52 -> V_63 ) ;
F_279 ( V_326 , L_17 , V_52 -> V_329 , V_64 ) ;
F_61 (nid, N_MEMORY) {
V_64 = F_56 ( V_5 , V_13 ,
V_52 -> V_63 ) ;
F_279 ( V_326 , L_18 , V_13 , V_64 ) ;
}
F_280 ( V_326 , '\n' ) ;
}
for ( V_52 = V_330 ; V_52 < V_330 + F_278 ( V_330 ) ; V_52 ++ ) {
struct V_4 * V_94 ;
V_64 = 0 ;
F_106 (iter, memcg)
V_64 += F_60 ( V_94 , V_52 -> V_63 ) ;
F_279 ( V_326 , L_19 , V_52 -> V_329 , V_64 ) ;
F_61 (nid, N_MEMORY) {
V_64 = 0 ;
F_106 (iter, memcg)
V_64 += F_56 (
V_94 , V_13 , V_52 -> V_63 ) ;
F_279 ( V_326 , L_18 , V_13 , V_64 ) ;
}
F_280 ( V_326 , '\n' ) ;
}
return 0 ;
}
static int F_281 ( struct V_325 * V_326 , void * V_327 )
{
struct V_4 * V_5 = F_70 ( F_277 ( V_326 ) ) ;
unsigned long V_41 , V_111 ;
struct V_4 * V_332 ;
unsigned int V_103 ;
F_282 ( F_278 ( V_126 ) !=
V_124 ) ;
F_282 ( F_278 ( V_333 ) !=
V_334 ) ;
F_282 ( F_278 ( V_128 ) != V_127 ) ;
for ( V_103 = 0 ; V_103 < V_124 ; V_103 ++ ) {
if ( V_103 == V_125 && ! F_1 () )
continue;
F_279 ( V_326 , L_20 , V_126 [ V_103 ] ,
F_46 ( V_5 , V_103 ) * V_246 ) ;
}
for ( V_103 = 0 ; V_103 < V_334 ; V_103 ++ )
F_279 ( V_326 , L_20 , V_333 [ V_103 ] ,
F_49 ( V_5 , V_103 ) ) ;
for ( V_103 = 0 ; V_103 < V_127 ; V_103 ++ )
F_279 ( V_326 , L_20 , V_128 [ V_103 ] ,
F_60 ( V_5 , F_59 ( V_103 ) ) * V_246 ) ;
V_41 = V_111 = V_335 ;
for ( V_332 = V_5 ; V_332 ; V_332 = F_18 ( V_332 ) ) {
V_41 = F_91 ( V_41 , V_332 -> V_41 . V_110 ) ;
V_111 = F_91 ( V_111 , V_332 -> V_111 . V_110 ) ;
}
F_279 ( V_326 , L_21 ,
( V_121 ) V_41 * V_246 ) ;
if ( F_1 () )
F_279 ( V_326 , L_22 ,
( V_121 ) V_111 * V_246 ) ;
for ( V_103 = 0 ; V_103 < V_124 ; V_103 ++ ) {
unsigned long long V_50 = 0 ;
if ( V_103 == V_125 && ! F_1 () )
continue;
F_106 (mi, memcg)
V_50 += F_46 ( V_332 , V_103 ) * V_246 ;
F_279 ( V_326 , L_23 , V_126 [ V_103 ] , V_50 ) ;
}
for ( V_103 = 0 ; V_103 < V_334 ; V_103 ++ ) {
unsigned long long V_50 = 0 ;
F_106 (mi, memcg)
V_50 += F_49 ( V_332 , V_103 ) ;
F_279 ( V_326 , L_23 ,
V_333 [ V_103 ] , V_50 ) ;
}
for ( V_103 = 0 ; V_103 < V_127 ; V_103 ++ ) {
unsigned long long V_50 = 0 ;
F_106 (mi, memcg)
V_50 += F_60 ( V_332 , F_59 ( V_103 ) ) * V_246 ;
F_279 ( V_326 , L_23 , V_128 [ V_103 ] , V_50 ) ;
}
#ifdef F_283
{
int V_13 , V_14 ;
struct V_11 * V_26 ;
struct V_336 * V_337 ;
unsigned long V_338 [ 2 ] = { 0 , 0 } ;
unsigned long V_339 [ 2 ] = { 0 , 0 } ;
F_284 (nid)
for ( V_14 = 0 ; V_14 < V_44 ; V_14 ++ ) {
V_26 = & V_5 -> V_15 [ V_13 ] -> V_16 [ V_14 ] ;
V_337 = & V_26 -> V_105 . V_340 ;
V_338 [ 0 ] += V_337 -> V_338 [ 0 ] ;
V_338 [ 1 ] += V_337 -> V_338 [ 1 ] ;
V_339 [ 0 ] += V_337 -> V_339 [ 0 ] ;
V_339 [ 1 ] += V_337 -> V_339 [ 1 ] ;
}
F_279 ( V_326 , L_24 , V_338 [ 0 ] ) ;
F_279 ( V_326 , L_25 , V_338 [ 1 ] ) ;
F_279 ( V_326 , L_26 , V_339 [ 0 ] ) ;
F_279 ( V_326 , L_27 , V_339 [ 1 ] ) ;
}
#endif
return 0 ;
}
static V_121 F_285 ( struct V_7 * V_9 ,
struct V_295 * V_296 )
{
struct V_4 * V_5 = F_70 ( V_9 ) ;
return F_109 ( V_5 ) ;
}
static int F_286 ( struct V_7 * V_9 ,
struct V_295 * V_296 , V_121 V_50 )
{
struct V_4 * V_5 = F_70 ( V_9 ) ;
if ( V_50 > 100 )
return - V_277 ;
if ( V_9 -> V_32 )
V_5 -> V_341 = V_50 ;
else
V_342 = V_50 ;
return 0 ;
}
static void F_287 ( struct V_4 * V_5 , bool V_132 )
{
struct V_343 * V_344 ;
unsigned long V_345 ;
int V_103 ;
F_16 () ;
if ( ! V_132 )
V_344 = F_73 ( V_5 -> V_346 . V_347 ) ;
else
V_344 = F_73 ( V_5 -> V_348 . V_347 ) ;
if ( ! V_344 )
goto V_115;
V_345 = F_250 ( V_5 , V_132 ) ;
V_103 = V_344 -> V_349 ;
for (; V_103 >= 0 && F_66 ( V_344 -> V_350 [ V_103 ] . V_351 > V_345 ) ; V_103 -- )
F_288 ( V_344 -> V_350 [ V_103 ] . V_352 , 1 ) ;
V_103 ++ ;
for (; V_103 < V_344 -> V_252 && F_66 ( V_344 -> V_350 [ V_103 ] . V_351 <= V_345 ) ; V_103 ++ )
F_288 ( V_344 -> V_350 [ V_103 ] . V_352 , 1 ) ;
V_344 -> V_349 = V_103 - 1 ;
V_115:
F_20 () ;
}
static void F_67 ( struct V_4 * V_5 )
{
while ( V_5 ) {
F_287 ( V_5 , false ) ;
if ( F_1 () )
F_287 ( V_5 , true ) ;
V_5 = F_18 ( V_5 ) ;
}
}
static int F_289 ( const void * V_353 , const void * V_354 )
{
const struct F_67 * V_355 = V_353 ;
const struct F_67 * V_356 = V_354 ;
if ( V_355 -> V_351 > V_356 -> V_351 )
return 1 ;
if ( V_355 -> V_351 < V_356 -> V_351 )
return - 1 ;
return 0 ;
}
static int F_290 ( struct V_4 * V_5 )
{
struct V_357 * V_358 ;
F_93 ( & V_170 ) ;
F_291 (ev, &memcg->oom_notify, list)
F_288 ( V_358 -> V_352 , 1 ) ;
F_94 ( & V_170 ) ;
return 0 ;
}
static void F_152 ( struct V_4 * V_5 )
{
struct V_4 * V_94 ;
F_106 (iter, memcg)
F_290 ( V_94 ) ;
}
static int F_292 ( struct V_4 * V_5 ,
struct V_359 * V_352 , const char * args , enum V_360 type )
{
struct V_361 * V_346 ;
struct V_343 * V_362 ;
unsigned long V_351 ;
unsigned long V_345 ;
int V_103 , V_252 , V_108 ;
V_108 = F_270 ( args , L_12 , & V_351 ) ;
if ( V_108 )
return V_108 ;
F_111 ( & V_5 -> V_363 ) ;
if ( type == V_302 ) {
V_346 = & V_5 -> V_346 ;
V_345 = F_250 ( V_5 , false ) ;
} else if ( type == V_303 ) {
V_346 = & V_5 -> V_348 ;
V_345 = F_250 ( V_5 , true ) ;
} else
F_253 () ;
if ( V_346 -> V_347 )
F_287 ( V_5 , type == V_303 ) ;
V_252 = V_346 -> V_347 ? V_346 -> V_347 -> V_252 + 1 : 1 ;
V_362 = F_217 ( sizeof( * V_362 ) + V_252 * sizeof( struct F_67 ) ,
V_225 ) ;
if ( ! V_362 ) {
V_108 = - V_247 ;
goto V_115;
}
V_362 -> V_252 = V_252 ;
if ( V_346 -> V_347 ) {
memcpy ( V_362 -> V_350 , V_346 -> V_347 -> V_350 , ( V_252 - 1 ) *
sizeof( struct F_67 ) ) ;
}
V_362 -> V_350 [ V_252 - 1 ] . V_352 = V_352 ;
V_362 -> V_350 [ V_252 - 1 ] . V_351 = V_351 ;
F_293 ( V_362 -> V_350 , V_252 , sizeof( struct F_67 ) ,
F_289 , NULL ) ;
V_362 -> V_349 = - 1 ;
for ( V_103 = 0 ; V_103 < V_252 ; V_103 ++ ) {
if ( V_362 -> V_350 [ V_103 ] . V_351 <= V_345 ) {
++ V_362 -> V_349 ;
} else
break;
}
F_215 ( V_346 -> V_364 ) ;
V_346 -> V_364 = V_346 -> V_347 ;
F_294 ( V_346 -> V_347 , V_362 ) ;
F_295 () ;
V_115:
F_125 ( & V_5 -> V_363 ) ;
return V_108 ;
}
static int F_296 ( struct V_4 * V_5 ,
struct V_359 * V_352 , const char * args )
{
return F_292 ( V_5 , V_352 , args , V_302 ) ;
}
static int F_297 ( struct V_4 * V_5 ,
struct V_359 * V_352 , const char * args )
{
return F_292 ( V_5 , V_352 , args , V_303 ) ;
}
static void F_298 ( struct V_4 * V_5 ,
struct V_359 * V_352 , enum V_360 type )
{
struct V_361 * V_346 ;
struct V_343 * V_362 ;
unsigned long V_345 ;
int V_103 , V_365 , V_252 ;
F_111 ( & V_5 -> V_363 ) ;
if ( type == V_302 ) {
V_346 = & V_5 -> V_346 ;
V_345 = F_250 ( V_5 , false ) ;
} else if ( type == V_303 ) {
V_346 = & V_5 -> V_348 ;
V_345 = F_250 ( V_5 , true ) ;
} else
F_253 () ;
if ( ! V_346 -> V_347 )
goto V_115;
F_287 ( V_5 , type == V_303 ) ;
V_252 = 0 ;
for ( V_103 = 0 ; V_103 < V_346 -> V_347 -> V_252 ; V_103 ++ ) {
if ( V_346 -> V_347 -> V_350 [ V_103 ] . V_352 != V_352 )
V_252 ++ ;
}
V_362 = V_346 -> V_364 ;
if ( ! V_252 ) {
F_215 ( V_362 ) ;
V_362 = NULL ;
goto V_366;
}
V_362 -> V_252 = V_252 ;
V_362 -> V_349 = - 1 ;
for ( V_103 = 0 , V_365 = 0 ; V_103 < V_346 -> V_347 -> V_252 ; V_103 ++ ) {
if ( V_346 -> V_347 -> V_350 [ V_103 ] . V_352 == V_352 )
continue;
V_362 -> V_350 [ V_365 ] = V_346 -> V_347 -> V_350 [ V_103 ] ;
if ( V_362 -> V_350 [ V_365 ] . V_351 <= V_345 ) {
++ V_362 -> V_349 ;
}
V_365 ++ ;
}
V_366:
V_346 -> V_364 = V_346 -> V_347 ;
F_294 ( V_346 -> V_347 , V_362 ) ;
F_295 () ;
if ( ! V_362 ) {
F_215 ( V_346 -> V_364 ) ;
V_346 -> V_364 = NULL ;
}
V_115:
F_125 ( & V_5 -> V_363 ) ;
}
static void F_299 ( struct V_4 * V_5 ,
struct V_359 * V_352 )
{
return F_298 ( V_5 , V_352 , V_302 ) ;
}
static void F_300 ( struct V_4 * V_5 ,
struct V_359 * V_352 )
{
return F_298 ( V_5 , V_352 , V_303 ) ;
}
static int F_301 ( struct V_4 * V_5 ,
struct V_359 * V_352 , const char * args )
{
struct V_357 * V_367 ;
V_367 = F_217 ( sizeof( * V_367 ) , V_225 ) ;
if ( ! V_367 )
return - V_247 ;
F_93 ( & V_170 ) ;
V_367 -> V_352 = V_352 ;
F_302 ( & V_367 -> V_368 , & V_5 -> V_369 ) ;
if ( V_5 -> V_173 )
F_288 ( V_352 , 1 ) ;
F_94 ( & V_170 ) ;
return 0 ;
}
static void F_303 ( struct V_4 * V_5 ,
struct V_359 * V_352 )
{
struct V_357 * V_358 , * V_370 ;
F_93 ( & V_170 ) ;
F_304 (ev, tmp, &memcg->oom_notify, list) {
if ( V_358 -> V_352 == V_352 ) {
F_305 ( & V_358 -> V_368 ) ;
F_215 ( V_358 ) ;
}
}
F_94 ( & V_170 ) ;
}
static int F_306 ( struct V_325 * V_371 , void * V_327 )
{
struct V_4 * V_5 = F_70 ( F_277 ( V_371 ) ) ;
F_279 ( V_371 , L_28 , V_5 -> V_196 ) ;
F_279 ( V_371 , L_29 , ( bool ) V_5 -> V_173 ) ;
return 0 ;
}
static int F_307 ( struct V_7 * V_9 ,
struct V_295 * V_296 , V_121 V_50 )
{
struct V_4 * V_5 = F_70 ( V_9 ) ;
if ( ! V_9 -> V_32 || ! ( ( V_50 == 0 ) || ( V_50 == 1 ) ) )
return - V_277 ;
V_5 -> V_196 = V_50 ;
if ( ! V_50 )
F_147 ( V_5 ) ;
return 0 ;
}
struct V_372 * F_308 ( struct V_4 * V_5 )
{
return & V_5 -> V_373 ;
}
static int F_309 ( struct V_4 * V_5 , T_3 V_265 )
{
return F_310 ( & V_5 -> V_374 , V_265 ) ;
}
static void F_311 ( struct V_4 * V_5 )
{
F_312 ( & V_5 -> V_374 ) ;
}
static void F_313 ( struct V_4 * V_5 )
{
F_314 ( & V_5 -> V_374 ) ;
}
struct V_375 * F_315 ( struct V_376 * V_377 )
{
struct V_4 * V_5 = F_70 ( V_377 -> V_378 ) ;
if ( ! V_5 -> V_9 . V_32 )
return NULL ;
return & V_5 -> V_374 ;
}
void F_316 ( struct V_376 * V_377 , unsigned long * V_379 ,
unsigned long * V_380 , unsigned long * V_381 ,
unsigned long * V_382 )
{
struct V_4 * V_5 = F_70 ( V_377 -> V_378 ) ;
struct V_4 * V_32 ;
* V_381 = F_46 ( V_5 , V_383 ) ;
* V_382 = F_46 ( V_5 , V_384 ) ;
* V_379 = F_60 ( V_5 , ( 1 << V_385 ) |
( 1 << V_386 ) ) ;
* V_380 = V_335 ;
while ( ( V_32 = F_18 ( V_5 ) ) ) {
unsigned long V_387 = F_91 ( V_5 -> V_41 . V_110 , V_5 -> V_222 ) ;
unsigned long V_388 = F_36 ( & V_5 -> V_41 ) ;
* V_380 = F_91 ( * V_380 , V_387 - F_91 ( V_387 , V_388 ) ) ;
V_5 = V_32 ;
}
}
static int F_309 ( struct V_4 * V_5 , T_3 V_265 )
{
return 0 ;
}
static void F_311 ( struct V_4 * V_5 )
{
}
static void F_313 ( struct V_4 * V_5 )
{
}
static void F_317 ( struct V_208 * V_213 )
{
struct V_389 * V_367 =
F_5 ( V_213 , struct V_389 , remove ) ;
struct V_4 * V_5 = V_367 -> V_5 ;
F_318 ( V_367 -> V_390 , & V_367 -> V_118 ) ;
V_367 -> V_391 ( V_5 , V_367 -> V_352 ) ;
F_288 ( V_367 -> V_352 , 1 ) ;
F_319 ( V_367 -> V_352 ) ;
F_215 ( V_367 ) ;
F_79 ( & V_5 -> V_9 ) ;
}
static int F_320 ( T_4 * V_118 , unsigned V_174 ,
int V_175 , void * V_392 )
{
struct V_389 * V_367 =
F_5 ( V_118 , struct V_389 , V_118 ) ;
struct V_4 * V_5 = V_367 -> V_5 ;
unsigned long V_19 = ( unsigned long ) V_392 ;
if ( V_19 & V_393 ) {
F_93 ( & V_5 -> V_394 ) ;
if ( ! F_321 ( & V_367 -> V_368 ) ) {
F_322 ( & V_367 -> V_368 ) ;
F_192 ( & V_367 -> remove ) ;
}
F_94 ( & V_5 -> V_394 ) ;
}
return 0 ;
}
static void F_323 ( struct V_395 * V_395 ,
T_9 * V_390 , T_10 * V_396 )
{
struct V_389 * V_367 =
F_5 ( V_396 , struct V_389 , V_396 ) ;
V_367 -> V_390 = V_390 ;
F_324 ( V_390 , & V_367 -> V_118 ) ;
}
static T_6 F_325 ( struct V_290 * V_291 ,
char * V_292 , T_7 V_293 , T_8 V_294 )
{
struct V_7 * V_9 = F_245 ( V_291 ) ;
struct V_4 * V_5 = F_70 ( V_9 ) ;
struct V_389 * V_367 ;
struct V_7 * V_397 ;
unsigned int V_398 , V_399 ;
struct V_400 V_401 ;
struct V_400 V_402 ;
const char * V_329 ;
char * V_403 ;
int V_108 ;
V_292 = F_269 ( V_292 ) ;
V_398 = F_326 ( V_292 , & V_403 , 10 ) ;
if ( * V_403 != ' ' )
return - V_277 ;
V_292 = V_403 + 1 ;
V_399 = F_326 ( V_292 , & V_403 , 10 ) ;
if ( ( * V_403 != ' ' ) && ( * V_403 != '\0' ) )
return - V_277 ;
V_292 = V_403 + 1 ;
V_367 = F_327 ( sizeof( * V_367 ) , V_225 ) ;
if ( ! V_367 )
return - V_247 ;
V_367 -> V_5 = V_5 ;
F_151 ( & V_367 -> V_368 ) ;
F_328 ( & V_367 -> V_396 , F_323 ) ;
F_329 ( & V_367 -> V_118 , F_320 ) ;
F_218 ( & V_367 -> remove , F_317 ) ;
V_401 = F_330 ( V_398 ) ;
if ( ! V_401 . V_395 ) {
V_108 = - V_404 ;
goto V_405;
}
V_367 -> V_352 = F_331 ( V_401 . V_395 ) ;
if ( F_332 ( V_367 -> V_352 ) ) {
V_108 = F_333 ( V_367 -> V_352 ) ;
goto V_406;
}
V_402 = F_330 ( V_399 ) ;
if ( ! V_402 . V_395 ) {
V_108 = - V_404 ;
goto V_407;
}
V_108 = F_334 ( F_335 ( V_402 . V_395 ) , V_408 ) ;
if ( V_108 < 0 )
goto V_409;
V_329 = V_402 . V_395 -> V_410 . V_411 -> V_412 . V_329 ;
if ( ! strcmp ( V_329 , L_30 ) ) {
V_367 -> V_413 = F_296 ;
V_367 -> V_391 = F_299 ;
} else if ( ! strcmp ( V_329 , L_31 ) ) {
V_367 -> V_413 = F_301 ;
V_367 -> V_391 = F_303 ;
} else if ( ! strcmp ( V_329 , L_32 ) ) {
V_367 -> V_413 = V_414 ;
V_367 -> V_391 = V_415 ;
} else if ( ! strcmp ( V_329 , L_33 ) ) {
V_367 -> V_413 = F_297 ;
V_367 -> V_391 = F_300 ;
} else {
V_108 = - V_277 ;
goto V_409;
}
V_397 = F_336 ( V_402 . V_395 -> V_410 . V_411 -> V_416 ,
& V_1 ) ;
V_108 = - V_277 ;
if ( F_332 ( V_397 ) )
goto V_409;
if ( V_397 != V_9 ) {
F_79 ( V_397 ) ;
goto V_409;
}
V_108 = V_367 -> V_413 ( V_5 , V_367 -> V_352 , V_292 ) ;
if ( V_108 )
goto V_417;
V_401 . V_395 -> V_418 -> V_419 ( V_401 . V_395 , & V_367 -> V_396 ) ;
F_93 ( & V_5 -> V_394 ) ;
F_302 ( & V_367 -> V_368 , & V_5 -> V_420 ) ;
F_94 ( & V_5 -> V_394 ) ;
F_337 ( V_402 ) ;
F_337 ( V_401 ) ;
return V_293 ;
V_417:
F_79 ( V_9 ) ;
V_409:
F_337 ( V_402 ) ;
V_407:
F_319 ( V_367 -> V_352 ) ;
V_406:
F_337 ( V_401 ) ;
V_405:
F_215 ( V_367 ) ;
return V_108 ;
}
static int F_338 ( struct V_4 * V_5 , int V_160 )
{
struct V_421 * V_422 ;
struct V_11 * V_26 ;
int V_12 , V_370 = V_160 ;
if ( ! F_339 ( V_160 , V_423 ) )
V_370 = - 1 ;
V_422 = F_340 ( sizeof( * V_422 ) , V_225 , V_370 ) ;
if ( ! V_422 )
return 1 ;
for ( V_12 = 0 ; V_12 < V_44 ; V_12 ++ ) {
V_26 = & V_422 -> V_16 [ V_12 ] ;
F_341 ( & V_26 -> V_105 ) ;
V_26 -> V_35 = 0 ;
V_26 -> V_34 = false ;
V_26 -> V_5 = V_5 ;
}
V_5 -> V_15 [ V_160 ] = V_422 ;
return 0 ;
}
static void F_342 ( struct V_4 * V_5 , int V_160 )
{
F_215 ( V_5 -> V_15 [ V_160 ] ) ;
}
static void F_343 ( struct V_4 * V_5 )
{
int V_160 ;
F_311 ( V_5 ) ;
F_39 (node)
F_342 ( V_5 , V_160 ) ;
F_344 ( V_5 -> V_52 ) ;
F_215 ( V_5 ) ;
}
static struct V_4 * F_345 ( void )
{
struct V_4 * V_5 ;
T_7 V_252 ;
int V_160 ;
V_252 = sizeof( struct V_4 ) ;
V_252 += V_65 * sizeof( struct V_421 * ) ;
V_5 = F_327 ( V_252 , V_225 ) ;
if ( ! V_5 )
return NULL ;
V_5 -> V_52 = F_346 ( struct V_424 ) ;
if ( ! V_5 -> V_52 )
goto V_425;
F_39 (node)
if ( F_338 ( V_5 , V_160 ) )
goto V_425;
if ( F_309 ( V_5 , V_225 ) )
goto V_425;
F_218 ( & V_5 -> V_224 , F_178 ) ;
V_5 -> V_161 = V_81 ;
F_151 ( & V_5 -> V_369 ) ;
F_347 ( & V_5 -> V_363 ) ;
F_348 ( & V_5 -> V_199 ) ;
F_349 ( & V_5 -> V_3 ) ;
F_151 ( & V_5 -> V_420 ) ;
F_348 ( & V_5 -> V_394 ) ;
V_5 -> V_426 = V_427 ;
#ifndef F_350
V_5 -> V_267 = - 1 ;
#endif
#ifdef F_351
F_151 ( & V_5 -> V_373 ) ;
#endif
return V_5 ;
V_425:
F_343 ( V_5 ) ;
return NULL ;
}
static struct V_7 * T_11
F_352 ( struct V_7 * V_428 )
{
struct V_4 * V_32 = F_70 ( V_428 ) ;
struct V_4 * V_5 ;
long error = - V_247 ;
V_5 = F_345 () ;
if ( ! V_5 )
return F_353 ( error ) ;
V_5 -> V_222 = V_335 ;
V_5 -> V_42 = V_335 ;
if ( V_32 ) {
V_5 -> V_341 = F_109 ( V_32 ) ;
V_5 -> V_196 = V_32 -> V_196 ;
}
if ( V_32 && V_32 -> V_96 ) {
V_5 -> V_96 = true ;
F_354 ( & V_5 -> V_41 , & V_32 -> V_41 ) ;
F_354 ( & V_5 -> V_132 , & V_32 -> V_132 ) ;
F_354 ( & V_5 -> V_111 , & V_32 -> V_111 ) ;
F_354 ( & V_5 -> V_123 , & V_32 -> V_123 ) ;
F_354 ( & V_5 -> V_306 , & V_32 -> V_306 ) ;
} else {
F_354 ( & V_5 -> V_41 , NULL ) ;
F_354 ( & V_5 -> V_132 , NULL ) ;
F_354 ( & V_5 -> V_111 , NULL ) ;
F_354 ( & V_5 -> V_123 , NULL ) ;
F_354 ( & V_5 -> V_306 , NULL ) ;
if ( V_32 != V_6 )
V_1 . V_429 = true ;
}
if ( ! V_32 ) {
V_6 = V_5 ;
return & V_5 -> V_9 ;
}
error = F_255 ( V_5 ) ;
if ( error )
goto V_425;
if ( F_2 ( V_1 ) && ! V_430 )
F_257 ( & V_321 ) ;
return & V_5 -> V_9 ;
V_425:
F_343 ( V_5 ) ;
return NULL ;
}
static int
F_355 ( struct V_7 * V_9 )
{
if ( V_9 -> V_251 > V_431 )
return - V_432 ;
return 0 ;
}
static void F_356 ( struct V_7 * V_9 )
{
struct V_4 * V_5 = F_70 ( V_9 ) ;
struct V_389 * V_367 , * V_370 ;
F_93 ( & V_5 -> V_394 ) ;
F_304 (event, tmp, &memcg->event_list, list) {
F_322 ( & V_367 -> V_368 ) ;
F_192 ( & V_367 -> remove ) ;
}
F_94 ( & V_5 -> V_394 ) ;
F_258 ( V_5 ) ;
F_357 ( V_5 ) ;
}
static void F_358 ( struct V_7 * V_9 )
{
struct V_4 * V_5 = F_70 ( V_9 ) ;
F_81 ( V_5 ) ;
}
static void F_359 ( struct V_7 * V_9 )
{
struct V_4 * V_5 = F_70 ( V_9 ) ;
if ( F_2 ( V_1 ) && ! V_430 )
F_264 ( & V_321 ) ;
if ( ! F_2 ( V_1 ) && V_5 -> V_320 )
F_264 ( & V_321 ) ;
F_360 ( & V_5 -> V_3 ) ;
F_361 ( & V_5 -> V_224 ) ;
F_38 ( V_5 ) ;
F_262 ( V_5 ) ;
F_343 ( V_5 ) ;
}
static void F_362 ( struct V_7 * V_9 )
{
struct V_4 * V_5 = F_70 ( V_9 ) ;
F_236 ( & V_5 -> V_41 , V_335 ) ;
F_236 ( & V_5 -> V_132 , V_335 ) ;
F_236 ( & V_5 -> V_111 , V_335 ) ;
F_236 ( & V_5 -> V_123 , V_335 ) ;
F_236 ( & V_5 -> V_306 , V_335 ) ;
V_5 -> V_433 = 0 ;
V_5 -> V_222 = V_335 ;
V_5 -> V_42 = V_335 ;
F_313 ( V_5 ) ;
}
static int F_363 ( unsigned long V_53 )
{
int V_108 ;
V_108 = F_181 ( V_114 . V_113 , V_225 & ~ V_434 , V_53 ) ;
if ( ! V_108 ) {
V_114 . V_435 += V_53 ;
return V_108 ;
}
while ( V_53 -- ) {
V_108 = F_181 ( V_114 . V_113 , V_225 & ~ V_242 , 1 ) ;
if ( V_108 )
return V_108 ;
V_114 . V_435 ++ ;
F_364 () ;
}
return 0 ;
}
static struct V_17 * F_365 ( struct V_436 * V_437 ,
unsigned long V_438 , T_12 V_439 )
{
struct V_17 * V_17 = F_366 ( V_437 , V_438 , V_439 ) ;
if ( ! V_17 || ! F_367 ( V_17 ) )
return NULL ;
if ( F_51 ( V_17 ) ) {
if ( ! ( V_114 . V_19 & V_440 ) )
return NULL ;
} else {
if ( ! ( V_114 . V_19 & V_441 ) )
return NULL ;
}
if ( ! F_368 ( V_17 ) )
return NULL ;
return V_17 ;
}
static struct V_17 * F_369 ( struct V_436 * V_437 ,
unsigned long V_438 , T_12 V_439 , T_5 * V_274 )
{
struct V_17 * V_17 = NULL ;
T_5 V_442 = F_370 ( V_439 ) ;
if ( ! ( V_114 . V_19 & V_440 ) || F_371 ( V_442 ) )
return NULL ;
V_17 = F_372 ( F_373 ( V_442 ) , V_442 . V_50 ) ;
if ( F_1 () )
V_274 -> V_50 = V_442 . V_50 ;
return V_17 ;
}
static struct V_17 * F_369 ( struct V_436 * V_437 ,
unsigned long V_438 , T_12 V_439 , T_5 * V_274 )
{
return NULL ;
}
static struct V_17 * F_374 ( struct V_436 * V_437 ,
unsigned long V_438 , T_12 V_439 , T_5 * V_274 )
{
struct V_17 * V_17 = NULL ;
struct V_443 * V_444 ;
T_13 V_445 ;
if ( ! V_437 -> V_446 )
return NULL ;
if ( ! ( V_114 . V_19 & V_441 ) )
return NULL ;
V_444 = V_437 -> V_446 -> V_447 ;
V_445 = F_375 ( V_437 , V_438 ) ;
#ifdef F_376
if ( F_377 ( V_444 ) ) {
V_17 = F_378 ( V_444 , V_445 ) ;
if ( F_379 ( V_17 ) ) {
T_5 V_448 = F_380 ( V_17 ) ;
if ( F_1 () )
* V_274 = V_448 ;
V_17 = F_372 ( F_373 ( V_448 ) , V_448 . V_50 ) ;
}
} else
V_17 = F_372 ( V_444 , V_445 ) ;
#else
V_17 = F_372 ( V_444 , V_445 ) ;
#endif
return V_17 ;
}
static int F_381 ( struct V_17 * V_17 ,
bool V_56 ,
struct V_4 * V_112 ,
struct V_4 * V_113 )
{
unsigned long V_19 ;
unsigned int V_40 = V_56 ? F_382 ( V_17 ) : 1 ;
int V_108 ;
bool V_449 ;
F_57 ( V_112 == V_113 ) ;
F_53 ( F_197 ( V_17 ) , V_17 ) ;
F_57 ( V_56 && ! F_54 ( V_17 ) ) ;
V_108 = - V_299 ;
if ( ! F_383 ( V_17 ) )
goto V_97;
V_108 = - V_277 ;
if ( V_17 -> V_4 != V_112 )
goto V_100;
V_449 = F_51 ( V_17 ) ;
F_33 ( & V_112 -> V_199 , V_19 ) ;
if ( ! V_449 && F_367 ( V_17 ) ) {
F_228 ( V_112 -> V_52 -> V_53 [ V_450 ] ,
V_40 ) ;
F_52 ( V_113 -> V_52 -> V_53 [ V_450 ] ,
V_40 ) ;
}
if ( ! V_449 && F_384 ( V_17 ) ) {
struct V_443 * V_444 = F_385 ( V_17 ) ;
if ( F_386 ( V_444 ) ) {
F_228 ( V_112 -> V_52 -> V_53 [ V_383 ] ,
V_40 ) ;
F_52 ( V_113 -> V_52 -> V_53 [ V_383 ] ,
V_40 ) ;
}
}
if ( F_387 ( V_17 ) ) {
F_228 ( V_112 -> V_52 -> V_53 [ V_384 ] ,
V_40 ) ;
F_52 ( V_113 -> V_52 -> V_53 [ V_384 ] ,
V_40 ) ;
}
V_17 -> V_4 = V_113 ;
F_34 ( & V_112 -> V_199 , V_19 ) ;
V_108 = 0 ;
F_388 () ;
F_50 ( V_113 , V_17 , V_56 , V_40 ) ;
F_65 ( V_113 , V_17 ) ;
F_50 ( V_112 , V_17 , V_56 , - V_40 ) ;
F_65 ( V_112 , V_17 ) ;
F_389 () ;
V_100:
F_390 ( V_17 ) ;
V_97:
return V_108 ;
}
static enum V_451 F_391 ( struct V_436 * V_437 ,
unsigned long V_438 , T_12 V_439 , union V_452 * V_70 )
{
struct V_17 * V_17 = NULL ;
enum V_451 V_108 = V_453 ;
T_5 V_442 = { . V_50 = 0 } ;
if ( F_392 ( V_439 ) )
V_17 = F_365 ( V_437 , V_438 , V_439 ) ;
else if ( F_393 ( V_439 ) )
V_17 = F_369 ( V_437 , V_438 , V_439 , & V_442 ) ;
else if ( F_394 ( V_439 ) )
V_17 = F_374 ( V_437 , V_438 , V_439 , & V_442 ) ;
if ( ! V_17 && ! V_442 . V_50 )
return V_108 ;
if ( V_17 ) {
if ( V_17 -> V_4 == V_114 . V_112 ) {
V_108 = V_454 ;
if ( V_70 )
V_70 -> V_17 = V_17 ;
}
if ( ! V_108 || ! V_70 )
F_395 ( V_17 ) ;
}
if ( V_442 . V_50 && ! V_108 &&
F_232 ( V_114 . V_112 ) == F_396 ( V_442 ) ) {
V_108 = V_455 ;
if ( V_70 )
V_70 -> V_442 = V_442 ;
}
return V_108 ;
}
static enum V_451 F_397 ( struct V_436 * V_437 ,
unsigned long V_438 , T_14 V_456 , union V_452 * V_70 )
{
struct V_17 * V_17 = NULL ;
enum V_451 V_108 = V_453 ;
V_17 = F_398 ( V_456 ) ;
F_53 ( ! V_17 || ! F_399 ( V_17 ) , V_17 ) ;
if ( ! ( V_114 . V_19 & V_440 ) )
return V_108 ;
if ( V_17 -> V_4 == V_114 . V_112 ) {
V_108 = V_454 ;
if ( V_70 ) {
F_400 ( V_17 ) ;
V_70 -> V_17 = V_17 ;
}
}
return V_108 ;
}
static inline enum V_451 F_397 ( struct V_436 * V_437 ,
unsigned long V_438 , T_14 V_456 , union V_452 * V_70 )
{
return V_453 ;
}
static int F_401 ( T_14 * V_456 ,
unsigned long V_438 , unsigned long V_457 ,
struct V_458 * V_459 )
{
struct V_436 * V_437 = V_459 -> V_437 ;
T_12 * V_460 ;
T_15 * V_461 ;
V_461 = F_402 ( V_456 , V_437 ) ;
if ( V_461 ) {
if ( F_397 ( V_437 , V_438 , * V_456 , NULL ) == V_454 )
V_114 . V_435 += V_272 ;
F_94 ( V_461 ) ;
return 0 ;
}
if ( F_403 ( V_456 ) )
return 0 ;
V_460 = F_404 ( V_437 -> V_462 , V_456 , V_438 , & V_461 ) ;
for (; V_438 != V_457 ; V_460 ++ , V_438 += V_246 )
if ( F_391 ( V_437 , V_438 , * V_460 , NULL ) )
V_114 . V_435 ++ ;
F_405 ( V_460 - 1 , V_461 ) ;
F_364 () ;
return 0 ;
}
static unsigned long F_406 ( struct V_85 * V_86 )
{
unsigned long V_435 ;
struct V_458 V_463 = {
. V_464 = F_401 ,
. V_86 = V_86 ,
} ;
F_8 ( & V_86 -> V_465 ) ;
F_407 ( 0 , ~ 0UL , & V_463 ) ;
F_10 ( & V_86 -> V_465 ) ;
V_435 = V_114 . V_435 ;
V_114 . V_435 = 0 ;
return V_435 ;
}
static int F_408 ( struct V_85 * V_86 )
{
unsigned long V_435 = F_406 ( V_86 ) ;
F_57 ( V_114 . V_116 ) ;
V_114 . V_116 = V_117 ;
return F_363 ( V_435 ) ;
}
static void F_409 ( void )
{
struct V_4 * V_112 = V_114 . V_112 ;
struct V_4 * V_113 = V_114 . V_113 ;
if ( V_114 . V_435 ) {
F_194 ( V_114 . V_113 , V_114 . V_435 ) ;
V_114 . V_435 = 0 ;
}
if ( V_114 . V_466 ) {
F_194 ( V_114 . V_112 , V_114 . V_466 ) ;
V_114 . V_466 = 0 ;
}
if ( V_114 . V_467 ) {
if ( ! F_6 ( V_114 . V_112 ) )
F_159 ( & V_114 . V_112 -> V_111 , V_114 . V_467 ) ;
if ( ! F_6 ( V_114 . V_113 ) )
F_159 ( & V_114 . V_113 -> V_41 , V_114 . V_467 ) ;
F_160 ( & V_114 . V_112 -> V_9 , V_114 . V_467 ) ;
V_114 . V_467 = 0 ;
}
F_147 ( V_112 ) ;
F_147 ( V_113 ) ;
F_410 ( & V_114 . V_119 ) ;
}
static void F_411 ( void )
{
struct V_85 * V_86 = V_114 . V_86 ;
V_114 . V_116 = NULL ;
F_409 () ;
F_93 ( & V_114 . V_39 ) ;
V_114 . V_112 = NULL ;
V_114 . V_113 = NULL ;
V_114 . V_86 = NULL ;
F_94 ( & V_114 . V_39 ) ;
F_412 ( V_86 ) ;
}
static int F_413 ( struct V_468 * V_469 )
{
struct V_7 * V_9 ;
struct V_4 * V_5 = NULL ;
struct V_4 * V_112 ;
struct V_83 * V_470 , * V_30 ;
struct V_85 * V_86 ;
unsigned long V_471 ;
int V_108 = 0 ;
if ( F_2 ( V_1 ) )
return 0 ;
V_30 = NULL ;
F_414 (leader, css, tset) {
F_415 ( V_30 ) ;
V_30 = V_470 ;
V_5 = F_70 ( V_9 ) ;
}
if ( ! V_30 )
return 0 ;
V_471 = F_17 ( V_5 -> V_322 ) ;
if ( ! V_471 )
return 0 ;
V_112 = F_69 ( V_30 ) ;
F_57 ( V_112 == V_5 ) ;
V_86 = F_416 ( V_30 ) ;
if ( ! V_86 )
return 0 ;
if ( V_86 -> V_87 == V_30 ) {
F_57 ( V_114 . V_112 ) ;
F_57 ( V_114 . V_113 ) ;
F_57 ( V_114 . V_435 ) ;
F_57 ( V_114 . V_466 ) ;
F_57 ( V_114 . V_467 ) ;
F_93 ( & V_114 . V_39 ) ;
V_114 . V_86 = V_86 ;
V_114 . V_112 = V_112 ;
V_114 . V_113 = V_5 ;
V_114 . V_19 = V_471 ;
F_94 ( & V_114 . V_39 ) ;
V_108 = F_408 ( V_86 ) ;
if ( V_108 )
F_411 () ;
} else {
F_412 ( V_86 ) ;
}
return V_108 ;
}
static void F_417 ( struct V_468 * V_469 )
{
if ( V_114 . V_113 )
F_411 () ;
}
static int F_418 ( T_14 * V_456 ,
unsigned long V_438 , unsigned long V_457 ,
struct V_458 * V_459 )
{
int V_108 = 0 ;
struct V_436 * V_437 = V_459 -> V_437 ;
T_12 * V_460 ;
T_15 * V_461 ;
enum V_451 V_472 ;
union V_452 V_70 ;
struct V_17 * V_17 ;
V_461 = F_402 ( V_456 , V_437 ) ;
if ( V_461 ) {
if ( V_114 . V_435 < V_272 ) {
F_94 ( V_461 ) ;
return 0 ;
}
V_472 = F_397 ( V_437 , V_438 , * V_456 , & V_70 ) ;
if ( V_472 == V_454 ) {
V_17 = V_70 . V_17 ;
if ( ! F_419 ( V_17 ) ) {
if ( ! F_381 ( V_17 , true ,
V_114 . V_112 , V_114 . V_113 ) ) {
V_114 . V_435 -= V_272 ;
V_114 . V_466 += V_272 ;
}
F_420 ( V_17 ) ;
}
F_395 ( V_17 ) ;
}
F_94 ( V_461 ) ;
return 0 ;
}
if ( F_403 ( V_456 ) )
return 0 ;
V_46:
V_460 = F_404 ( V_437 -> V_462 , V_456 , V_438 , & V_461 ) ;
for (; V_438 != V_457 ; V_438 += V_246 ) {
T_12 V_439 = * ( V_460 ++ ) ;
T_5 V_442 ;
if ( ! V_114 . V_435 )
break;
switch ( F_391 ( V_437 , V_438 , V_439 , & V_70 ) ) {
case V_454 :
V_17 = V_70 . V_17 ;
if ( F_421 ( V_17 ) )
goto V_473;
if ( F_419 ( V_17 ) )
goto V_473;
if ( ! F_381 ( V_17 , false ,
V_114 . V_112 , V_114 . V_113 ) ) {
V_114 . V_435 -- ;
V_114 . V_466 ++ ;
}
F_420 ( V_17 ) ;
V_473:
F_395 ( V_17 ) ;
break;
case V_455 :
V_442 = V_70 . V_442 ;
if ( ! F_231 ( V_442 , V_114 . V_112 , V_114 . V_113 ) ) {
V_114 . V_435 -- ;
V_114 . V_467 ++ ;
}
break;
default:
break;
}
}
F_405 ( V_460 - 1 , V_461 ) ;
F_364 () ;
if ( V_438 != V_457 ) {
V_108 = F_363 ( 1 ) ;
if ( ! V_108 )
goto V_46;
}
return V_108 ;
}
static void F_422 ( void )
{
struct V_458 V_474 = {
. V_464 = F_418 ,
. V_86 = V_114 . V_86 ,
} ;
F_242 () ;
F_68 ( & V_114 . V_112 -> V_198 ) ;
F_295 () ;
V_46:
if ( F_66 ( ! F_423 ( & V_114 . V_86 -> V_465 ) ) ) {
F_409 () ;
F_364 () ;
goto V_46;
}
F_407 ( 0 , ~ 0UL , & V_474 ) ;
F_10 ( & V_114 . V_86 -> V_465 ) ;
F_424 ( & V_114 . V_112 -> V_198 ) ;
}
static void F_425 ( void )
{
if ( V_114 . V_113 ) {
F_422 () ;
F_411 () ;
}
}
static int F_413 ( struct V_468 * V_469 )
{
return 0 ;
}
static void F_417 ( struct V_468 * V_469 )
{
}
static void F_425 ( void )
{
}
static void F_426 ( struct V_7 * V_475 )
{
if ( F_2 ( V_1 ) )
V_6 -> V_96 = true ;
else
V_6 -> V_96 = false ;
}
static V_121 F_427 ( struct V_7 * V_9 ,
struct V_295 * V_296 )
{
struct V_4 * V_5 = F_70 ( V_9 ) ;
return ( V_121 ) F_36 ( & V_5 -> V_41 ) * V_246 ;
}
static int F_428 ( struct V_325 * V_326 , void * V_327 )
{
struct V_4 * V_5 = F_70 ( F_277 ( V_326 ) ) ;
unsigned long V_433 = F_17 ( V_5 -> V_433 ) ;
if ( V_433 == V_335 )
F_429 ( V_326 , L_34 ) ;
else
F_279 ( V_326 , L_35 , ( V_121 ) V_433 * V_246 ) ;
return 0 ;
}
static T_6 F_430 ( struct V_290 * V_291 ,
char * V_292 , T_7 V_293 , T_8 V_294 )
{
struct V_4 * V_5 = F_70 ( F_245 ( V_291 ) ) ;
unsigned long V_433 ;
int V_253 ;
V_292 = F_269 ( V_292 ) ;
V_253 = F_270 ( V_292 , L_36 , & V_433 ) ;
if ( V_253 )
return V_253 ;
V_5 -> V_433 = V_433 ;
return V_293 ;
}
static int F_431 ( struct V_325 * V_326 , void * V_327 )
{
struct V_4 * V_5 = F_70 ( F_277 ( V_326 ) ) ;
unsigned long V_222 = F_17 ( V_5 -> V_222 ) ;
if ( V_222 == V_335 )
F_429 ( V_326 , L_34 ) ;
else
F_279 ( V_326 , L_35 , ( V_121 ) V_222 * V_246 ) ;
return 0 ;
}
static T_6 F_432 ( struct V_290 * V_291 ,
char * V_292 , T_7 V_293 , T_8 V_294 )
{
struct V_4 * V_5 = F_70 ( F_245 ( V_291 ) ) ;
unsigned long V_40 ;
unsigned long V_222 ;
int V_253 ;
V_292 = F_269 ( V_292 ) ;
V_253 = F_270 ( V_292 , L_36 , & V_222 ) ;
if ( V_253 )
return V_253 ;
V_5 -> V_222 = V_222 ;
V_40 = F_36 ( & V_5 -> V_41 ) ;
if ( V_40 > V_222 )
F_177 ( V_5 , V_40 - V_222 ,
V_225 , true ) ;
F_313 ( V_5 ) ;
return V_293 ;
}
static int F_433 ( struct V_325 * V_326 , void * V_327 )
{
struct V_4 * V_5 = F_70 ( F_277 ( V_326 ) ) ;
unsigned long F_182 = F_17 ( V_5 -> V_41 . V_110 ) ;
if ( F_182 == V_335 )
F_429 ( V_326 , L_34 ) ;
else
F_279 ( V_326 , L_35 , ( V_121 ) F_182 * V_246 ) ;
return 0 ;
}
static T_6 F_434 ( struct V_290 * V_291 ,
char * V_292 , T_7 V_293 , T_8 V_294 )
{
struct V_4 * V_5 = F_70 ( F_245 ( V_291 ) ) ;
unsigned int V_476 = V_229 ;
bool V_235 = false ;
unsigned long F_182 ;
int V_253 ;
V_292 = F_269 ( V_292 ) ;
V_253 = F_270 ( V_292 , L_36 , & F_182 ) ;
if ( V_253 )
return V_253 ;
F_435 ( & V_5 -> V_41 . V_110 , F_182 ) ;
for (; ; ) {
unsigned long V_40 = F_36 ( & V_5 -> V_41 ) ;
if ( V_40 <= F_182 )
break;
if ( F_235 ( V_117 ) ) {
V_253 = - V_282 ;
break;
}
if ( ! V_235 ) {
F_165 ( V_5 ) ;
V_235 = true ;
continue;
}
if ( V_476 ) {
if ( ! F_177 ( V_5 , V_40 - F_182 ,
V_225 , true ) )
V_476 -- ;
continue;
}
F_176 ( V_5 , V_245 , 1 ) ;
if ( ! F_110 ( V_5 , V_225 , 0 ) )
break;
}
F_313 ( V_5 ) ;
return V_293 ;
}
static int F_436 ( struct V_325 * V_326 , void * V_327 )
{
struct V_4 * V_5 = F_70 ( F_277 ( V_326 ) ) ;
F_279 ( V_326 , L_37 , F_49 ( V_5 , V_477 ) ) ;
F_279 ( V_326 , L_38 , F_49 ( V_5 , V_223 ) ) ;
F_279 ( V_326 , L_39 , F_49 ( V_5 , V_241 ) ) ;
F_279 ( V_326 , L_40 , F_49 ( V_5 , V_245 ) ) ;
return 0 ;
}
static int F_437 ( struct V_325 * V_326 , void * V_327 )
{
struct V_4 * V_5 = F_70 ( F_277 ( V_326 ) ) ;
unsigned long V_52 [ V_300 ] ;
unsigned long V_55 [ V_301 ] ;
int V_103 ;
F_248 ( V_5 , V_52 ) ;
F_249 ( V_5 , V_55 ) ;
F_279 ( V_326 , L_41 ,
( V_121 ) V_52 [ V_57 ] * V_246 ) ;
F_279 ( V_326 , L_42 ,
( V_121 ) V_52 [ V_58 ] * V_246 ) ;
F_279 ( V_326 , L_43 ,
( V_121 ) V_52 [ V_478 ] * V_246 ) ;
F_279 ( V_326 , L_44 ,
( V_121 ) ( V_52 [ V_479 ] +
V_52 [ V_480 ] ) * V_246 ) ;
F_279 ( V_326 , L_45 ,
( V_121 ) V_52 [ V_481 ] * V_246 ) ;
F_279 ( V_326 , L_46 ,
( V_121 ) V_52 [ V_450 ] * V_246 ) ;
F_279 ( V_326 , L_47 ,
( V_121 ) V_52 [ V_383 ] * V_246 ) ;
F_279 ( V_326 , L_48 ,
( V_121 ) V_52 [ V_384 ] * V_246 ) ;
for ( V_103 = 0 ; V_103 < V_127 ; V_103 ++ ) {
struct V_4 * V_332 ;
unsigned long V_50 = 0 ;
F_106 (mi, memcg)
V_50 += F_60 ( V_332 , F_59 ( V_103 ) ) ;
F_279 ( V_326 , L_49 ,
V_128 [ V_103 ] , ( V_121 ) V_50 * V_246 ) ;
}
F_279 ( V_326 , L_50 ,
( V_121 ) V_52 [ V_479 ] * V_246 ) ;
F_279 ( V_326 , L_51 ,
( V_121 ) V_52 [ V_480 ] * V_246 ) ;
F_279 ( V_326 , L_52 ,
V_55 [ V_482 ] ) ;
F_279 ( V_326 , L_53 ,
V_55 [ V_483 ] ) ;
return 0 ;
}
bool F_438 ( struct V_4 * V_88 , struct V_4 * V_5 )
{
if ( F_75 () )
return false ;
if ( V_5 == V_6 )
return false ;
if ( F_36 ( & V_5 -> V_41 ) >= V_5 -> V_433 )
return false ;
while ( V_5 != V_88 ) {
V_5 = F_18 ( V_5 ) ;
if ( V_5 == V_6 )
break;
if ( F_36 ( & V_5 -> V_41 ) >= V_5 -> V_433 )
return false ;
}
return true ;
}
int F_439 ( struct V_17 * V_17 , struct V_85 * V_86 ,
T_3 V_134 , struct V_4 * * V_484 ,
bool V_56 )
{
struct V_4 * V_5 = NULL ;
unsigned int V_40 = V_56 ? F_382 ( V_17 ) : 1 ;
int V_108 = 0 ;
if ( F_75 () )
goto V_97;
if ( F_440 ( V_17 ) ) {
F_53 ( ! F_441 ( V_17 ) , V_17 ) ;
if ( V_17 -> V_4 )
goto V_97;
if ( V_2 ) {
T_5 V_442 = { . V_50 = F_442 ( V_17 ) , } ;
unsigned short V_251 = F_396 ( V_442 ) ;
F_16 () ;
V_5 = F_443 ( V_251 ) ;
if ( V_5 && ! F_42 ( & V_5 -> V_9 ) )
V_5 = NULL ;
F_20 () ;
}
}
if ( ! V_5 )
V_5 = F_72 ( V_86 ) ;
V_108 = F_181 ( V_5 , V_134 , V_40 ) ;
F_79 ( & V_5 -> V_9 ) ;
V_97:
* V_484 = V_5 ;
return V_108 ;
}
void F_444 ( struct V_17 * V_17 , struct V_4 * V_5 ,
bool V_250 , bool V_56 )
{
unsigned int V_40 = V_56 ? F_382 ( V_17 ) : 1 ;
F_53 ( ! V_17 -> V_444 , V_17 ) ;
F_53 ( F_197 ( V_17 ) && ! V_250 , V_17 ) ;
if ( F_75 () )
return;
if ( ! V_5 )
return;
F_204 ( V_17 , V_5 , V_250 ) ;
F_388 () ;
F_50 ( V_5 , V_17 , V_56 , V_40 ) ;
F_65 ( V_5 , V_17 ) ;
F_389 () ;
if ( F_1 () && F_440 ( V_17 ) ) {
T_5 V_274 = { . V_50 = F_442 (page) } ;
F_445 ( V_274 ) ;
}
}
void F_446 ( struct V_17 * V_17 , struct V_4 * V_5 ,
bool V_56 )
{
unsigned int V_40 = V_56 ? F_382 ( V_17 ) : 1 ;
if ( F_75 () )
return;
if ( ! V_5 )
return;
F_194 ( V_5 , V_40 ) ;
}
static void F_447 ( struct V_4 * V_5 , unsigned long V_485 ,
unsigned long V_486 , unsigned long V_487 ,
unsigned long V_488 , struct V_17 * V_489 )
{
unsigned long V_40 = V_486 + V_487 ;
unsigned long V_19 ;
if ( ! F_6 ( V_5 ) ) {
F_159 ( & V_5 -> V_41 , V_40 ) ;
if ( F_1 () )
F_159 ( & V_5 -> V_111 , V_40 ) ;
F_147 ( V_5 ) ;
}
F_448 ( V_19 ) ;
F_228 ( V_5 -> V_52 -> V_53 [ V_57 ] , V_486 ) ;
F_228 ( V_5 -> V_52 -> V_53 [ V_58 ] , V_487 ) ;
F_228 ( V_5 -> V_52 -> V_53 [ V_59 ] , V_488 ) ;
F_52 ( V_5 -> V_52 -> V_55 [ V_61 ] , V_485 ) ;
F_52 ( V_5 -> V_52 -> V_62 , V_40 ) ;
F_65 ( V_5 , V_489 ) ;
F_449 ( V_19 ) ;
if ( ! F_6 ( V_5 ) )
F_160 ( & V_5 -> V_9 , V_40 ) ;
}
static void F_450 ( struct V_372 * V_490 )
{
struct V_4 * V_5 = NULL ;
unsigned long V_486 = 0 ;
unsigned long V_487 = 0 ;
unsigned long V_488 = 0 ;
unsigned long V_485 = 0 ;
struct V_372 * V_71 ;
struct V_17 * V_17 ;
V_71 = V_490 -> V_71 ;
do {
unsigned int V_40 = 1 ;
V_17 = F_451 ( V_71 , struct V_17 , V_67 ) ;
V_71 = V_17 -> V_67 . V_71 ;
F_53 ( F_197 ( V_17 ) , V_17 ) ;
F_53 ( F_452 ( V_17 ) , V_17 ) ;
if ( ! V_17 -> V_4 )
continue;
if ( V_5 != V_17 -> V_4 ) {
if ( V_5 ) {
F_447 ( V_5 , V_485 , V_486 , V_487 ,
V_488 , V_17 ) ;
V_485 = V_486 = V_487 = V_488 = 0 ;
}
V_5 = V_17 -> V_4 ;
}
if ( F_54 ( V_17 ) ) {
V_40 <<= F_453 ( V_17 ) ;
F_53 ( ! F_54 ( V_17 ) , V_17 ) ;
V_488 += V_40 ;
}
if ( F_51 ( V_17 ) )
V_486 += V_40 ;
else
V_487 += V_40 ;
V_17 -> V_4 = NULL ;
V_485 ++ ;
} while ( V_71 != V_490 );
if ( V_5 )
F_447 ( V_5 , V_485 , V_486 , V_487 ,
V_488 , V_17 ) ;
}
void F_454 ( struct V_17 * V_17 )
{
if ( F_75 () )
return;
if ( ! V_17 -> V_4 )
return;
F_151 ( & V_17 -> V_67 ) ;
F_450 ( & V_17 -> V_67 ) ;
}
void F_455 ( struct V_372 * V_490 )
{
if ( F_75 () )
return;
if ( ! F_321 ( V_490 ) )
F_450 ( V_490 ) ;
}
void F_456 ( struct V_17 * V_491 , struct V_17 * V_492 )
{
struct V_4 * V_5 ;
unsigned int V_40 ;
bool V_56 ;
F_53 ( ! F_441 ( V_491 ) , V_491 ) ;
F_53 ( ! F_441 ( V_492 ) , V_492 ) ;
F_53 ( F_51 ( V_491 ) != F_51 ( V_492 ) , V_492 ) ;
F_53 ( F_54 ( V_491 ) != F_54 ( V_492 ) ,
V_492 ) ;
if ( F_75 () )
return;
if ( V_492 -> V_4 )
return;
V_5 = V_491 -> V_4 ;
if ( ! V_5 )
return;
V_56 = F_54 ( V_492 ) ;
V_40 = V_56 ? F_382 ( V_492 ) : 1 ;
F_189 ( & V_5 -> V_41 , V_40 ) ;
if ( F_1 () )
F_189 ( & V_5 -> V_111 , V_40 ) ;
F_190 ( & V_5 -> V_9 , V_40 ) ;
F_204 ( V_492 , V_5 , false ) ;
F_388 () ;
F_50 ( V_5 , V_492 , V_56 , V_40 ) ;
F_65 ( V_5 , V_492 ) ;
F_389 () ;
}
void F_457 ( struct V_493 * V_494 )
{
struct V_4 * V_5 ;
if ( V_494 -> V_495 ) {
F_256 ( F_6 ( V_494 -> V_495 ) ) ;
F_88 ( & V_494 -> V_495 -> V_9 ) ;
return;
}
F_16 () ;
V_5 = F_69 ( V_117 ) ;
if ( V_5 == V_6 )
goto V_97;
if ( ! F_2 ( V_1 ) && ! V_5 -> V_320 )
goto V_97;
if ( F_42 ( & V_5 -> V_9 ) )
V_494 -> V_495 = V_5 ;
V_97:
F_20 () ;
}
void F_458 ( struct V_493 * V_494 )
{
F_265 ( ! V_494 -> V_495 ) ;
F_79 ( & V_494 -> V_495 -> V_9 ) ;
}
bool F_459 ( struct V_4 * V_5 , unsigned int V_40 )
{
T_3 V_134 = V_225 ;
if ( ! F_2 ( V_1 ) ) {
struct V_231 * V_425 ;
if ( F_183 ( & V_5 -> V_306 , V_40 , & V_425 ) ) {
V_5 -> V_496 = 0 ;
return true ;
}
F_189 ( & V_5 -> V_306 , V_40 ) ;
V_5 -> V_496 = 1 ;
return false ;
}
if ( F_460 () )
V_134 = V_263 ;
F_230 ( V_5 -> V_52 -> V_53 [ V_481 ] , V_40 ) ;
if ( F_181 ( V_5 , V_134 , V_40 ) == 0 )
return true ;
F_181 ( V_5 , V_134 | V_244 , V_40 ) ;
return false ;
}
void F_461 ( struct V_4 * V_5 , unsigned int V_40 )
{
if ( ! F_2 ( V_1 ) ) {
F_159 ( & V_5 -> V_306 , V_40 ) ;
return;
}
F_462 ( V_5 -> V_52 -> V_53 [ V_481 ] , V_40 ) ;
F_159 ( & V_5 -> V_41 , V_40 ) ;
F_160 ( & V_5 -> V_9 , V_40 ) ;
}
static int T_16 F_463 ( char * V_497 )
{
char * V_498 ;
while ( ( V_498 = F_464 ( & V_497 , L_54 ) ) != NULL ) {
if ( ! * V_498 )
continue;
if ( ! strcmp ( V_498 , L_55 ) )
V_430 = true ;
if ( ! strcmp ( V_498 , L_56 ) )
V_314 = true ;
}
return 0 ;
}
static int T_16 F_465 ( void )
{
int V_51 , V_160 ;
F_466 ( F_174 , 0 ) ;
F_47 (cpu)
F_218 ( & F_467 ( & V_205 , V_51 ) -> V_213 ,
F_161 ) ;
F_39 (node) {
struct V_499 * V_500 ;
int V_12 ;
V_500 = F_340 ( sizeof( * V_500 ) , V_225 ,
F_468 ( V_160 ) ? V_160 : V_501 ) ;
for ( V_12 = 0 ; V_12 < V_44 ; V_12 ++ ) {
struct V_22 * V_502 ;
V_502 = & V_500 -> V_25 [ V_12 ] ;
V_502 -> V_31 = V_503 ;
F_348 ( & V_502 -> V_39 ) ;
}
V_23 . V_24 [ V_160 ] = V_500 ;
}
return 0 ;
}
void F_469 ( struct V_17 * V_17 , T_5 V_274 )
{
struct V_4 * V_5 ;
unsigned short V_504 ;
F_53 ( F_197 ( V_17 ) , V_17 ) ;
F_53 ( F_452 ( V_17 ) , V_17 ) ;
if ( ! F_1 () )
return;
V_5 = V_17 -> V_4 ;
if ( ! V_5 )
return;
V_504 = F_470 ( V_274 , F_232 ( V_5 ) ) ;
F_53 ( V_504 , V_17 ) ;
F_229 ( V_5 , true ) ;
V_17 -> V_4 = NULL ;
if ( ! F_6 ( V_5 ) )
F_159 ( & V_5 -> V_41 , 1 ) ;
F_57 ( ! F_471 () ) ;
F_50 ( V_5 , V_17 , false , - 1 ) ;
F_65 ( V_5 , V_17 ) ;
}
int F_472 ( struct V_17 * V_17 , T_5 V_274 )
{
struct V_4 * V_5 ;
struct V_231 * V_232 ;
unsigned short V_504 ;
if ( ! F_2 ( V_1 ) || ! V_2 )
return 0 ;
V_5 = V_17 -> V_4 ;
if ( ! V_5 )
return 0 ;
if ( ! F_6 ( V_5 ) &&
! F_183 ( & V_5 -> V_132 , 1 , & V_232 ) )
return - V_247 ;
V_504 = F_470 ( V_274 , F_232 ( V_5 ) ) ;
F_53 ( V_504 , V_17 ) ;
F_229 ( V_5 , true ) ;
F_88 ( & V_5 -> V_9 ) ;
return 0 ;
}
void F_445 ( T_5 V_274 )
{
struct V_4 * V_5 ;
unsigned short V_251 ;
if ( ! V_2 )
return;
V_251 = F_470 ( V_274 , 0 ) ;
F_16 () ;
V_5 = F_443 ( V_251 ) ;
if ( V_5 ) {
if ( ! F_6 ( V_5 ) ) {
if ( F_2 ( V_1 ) )
F_159 ( & V_5 -> V_132 , 1 ) ;
else
F_159 ( & V_5 -> V_111 , 1 ) ;
}
F_229 ( V_5 , false ) ;
F_79 ( & V_5 -> V_9 ) ;
}
F_20 () ;
}
long F_473 ( struct V_4 * V_5 )
{
long V_505 = F_474 () ;
if ( ! V_2 || ! F_2 ( V_1 ) )
return V_505 ;
for (; V_5 != V_6 ; V_5 = F_18 ( V_5 ) )
V_505 = F_475 ( long , V_505 ,
F_17 ( V_5 -> V_132 . V_110 ) -
F_36 ( & V_5 -> V_132 ) ) ;
return V_505 ;
}
bool F_476 ( struct V_17 * V_17 )
{
struct V_4 * V_5 ;
F_53 ( ! F_441 ( V_17 ) , V_17 ) ;
if ( F_477 () )
return true ;
if ( ! V_2 || ! F_2 ( V_1 ) )
return false ;
V_5 = V_17 -> V_4 ;
if ( ! V_5 )
return false ;
for (; V_5 != V_6 ; V_5 = F_18 ( V_5 ) )
if ( F_36 ( & V_5 -> V_132 ) * 2 >= V_5 -> V_132 . V_110 )
return true ;
return false ;
}
static int T_16 F_478 ( char * V_497 )
{
if ( ! strcmp ( V_497 , L_57 ) )
V_506 = 1 ;
else if ( ! strcmp ( V_497 , L_58 ) )
V_506 = 0 ;
return 1 ;
}
static V_121 F_479 ( struct V_7 * V_9 ,
struct V_295 * V_296 )
{
struct V_4 * V_5 = F_70 ( V_9 ) ;
return ( V_121 ) F_36 ( & V_5 -> V_132 ) * V_246 ;
}
static int F_480 ( struct V_325 * V_326 , void * V_327 )
{
struct V_4 * V_5 = F_70 ( F_277 ( V_326 ) ) ;
unsigned long F_182 = F_17 ( V_5 -> V_132 . V_110 ) ;
if ( F_182 == V_335 )
F_429 ( V_326 , L_34 ) ;
else
F_279 ( V_326 , L_35 , ( V_121 ) F_182 * V_246 ) ;
return 0 ;
}
static T_6 F_481 ( struct V_290 * V_291 ,
char * V_292 , T_7 V_293 , T_8 V_294 )
{
struct V_4 * V_5 = F_70 ( F_245 ( V_291 ) ) ;
unsigned long F_182 ;
int V_253 ;
V_292 = F_269 ( V_292 ) ;
V_253 = F_270 ( V_292 , L_36 , & F_182 ) ;
if ( V_253 )
return V_253 ;
F_111 ( & V_283 ) ;
V_253 = F_236 ( & V_5 -> V_132 , F_182 ) ;
F_125 ( & V_283 ) ;
if ( V_253 )
return V_253 ;
return V_293 ;
}
static int T_16 F_482 ( void )
{
if ( ! F_75 () && V_506 ) {
V_2 = 1 ;
F_265 ( F_483 ( & V_1 ,
V_507 ) ) ;
F_265 ( F_484 ( & V_1 ,
V_508 ) ) ;
}
return 0 ;
}
