struct V_1 * F_1 ( struct V_2 * V_3 )
{
if ( ! V_3 )
V_3 = V_4 ;
return & V_3 -> V_1 ;
}
struct V_5 * F_2 ( struct V_1 * V_6 )
{
return & F_3 ( V_6 , struct V_2 , V_1 ) -> V_7 ;
}
static inline bool F_4 ( struct V_2 * V_3 )
{
return ( V_3 == V_4 ) ;
}
static inline unsigned short F_5 ( struct V_2 * V_3 )
{
return V_3 -> V_7 . V_8 ;
}
static inline struct V_2 * F_6 ( unsigned short V_8 )
{
struct V_5 * V_7 ;
V_7 = F_7 ( V_8 , & V_9 ) ;
return F_8 ( V_7 ) ;
}
void F_9 ( struct V_10 * V_11 )
{
if ( V_12 ) {
struct V_2 * V_3 ;
struct V_13 * V_13 ;
F_10 ( ! V_11 -> V_14 -> V_15 ) ;
if ( V_11 -> V_16 ) {
F_10 ( F_4 ( V_11 -> V_16 -> V_3 ) ) ;
F_11 ( & V_11 -> V_16 -> V_3 -> V_7 ) ;
return;
}
F_12 () ;
V_3 = F_13 ( V_17 ) ;
V_13 = V_11 -> V_14 -> V_15 ( V_3 ) ;
if ( V_13 && F_14 ( V_18 , & V_13 -> V_19 ) &&
F_15 ( & V_3 -> V_7 ) ) {
V_11 -> V_16 = V_13 ;
}
F_16 () ;
}
}
void F_17 ( struct V_10 * V_11 )
{
if ( V_12 && V_11 -> V_16 ) {
struct V_2 * V_3 ;
F_18 ( ! V_11 -> V_16 -> V_3 ) ;
V_3 = V_11 -> V_16 -> V_3 ;
F_19 ( & V_11 -> V_16 -> V_3 -> V_7 ) ;
}
}
struct V_13 * F_20 ( struct V_2 * V_3 )
{
if ( ! V_3 || F_4 ( V_3 ) )
return NULL ;
return & V_3 -> V_20 ;
}
void F_21 ( void )
{
F_22 ( & V_21 ) ;
}
void F_23 ( void )
{
F_24 ( & V_21 ) ;
}
static struct V_22 *
F_25 ( struct V_2 * V_3 , struct V_23 * V_23 )
{
int V_24 = F_26 ( V_23 ) ;
int V_25 = F_27 ( V_23 ) ;
return & V_3 -> V_26 [ V_24 ] -> V_27 [ V_25 ] ;
}
struct V_5 * F_28 ( struct V_28 * V_28 )
{
struct V_2 * V_3 ;
F_12 () ;
V_3 = V_28 -> V_2 ;
if ( ! V_3 || ! F_29 ( V_9 ) )
V_3 = V_4 ;
F_16 () ;
return & V_3 -> V_7 ;
}
T_1 F_30 ( struct V_28 * V_28 )
{
struct V_2 * V_3 ;
unsigned long V_29 = 0 ;
F_12 () ;
V_3 = F_31 ( V_28 -> V_2 ) ;
while ( V_3 && ! ( V_3 -> V_7 . V_19 & V_30 ) )
V_3 = F_32 ( V_3 ) ;
if ( V_3 )
V_29 = F_33 ( V_3 -> V_7 . V_31 ) ;
F_16 () ;
return V_29 ;
}
static struct V_22 *
F_34 ( struct V_2 * V_3 , struct V_28 * V_28 )
{
int V_24 = F_35 ( V_28 ) ;
int V_25 = F_36 ( V_28 ) ;
return & V_3 -> V_26 [ V_24 ] -> V_27 [ V_25 ] ;
}
static struct V_32 *
F_37 ( int V_24 , int V_25 )
{
return & V_33 . V_34 [ V_24 ] -> V_35 [ V_25 ] ;
}
static struct V_32 *
F_38 ( struct V_28 * V_28 )
{
int V_24 = F_35 ( V_28 ) ;
int V_25 = F_36 ( V_28 ) ;
return & V_33 . V_34 [ V_24 ] -> V_35 [ V_25 ] ;
}
static void F_39 ( struct V_22 * V_36 ,
struct V_32 * V_37 ,
unsigned long V_38 )
{
struct V_39 * * V_40 = & V_37 -> V_41 . V_39 ;
struct V_39 * V_42 = NULL ;
struct V_22 * V_43 ;
if ( V_36 -> V_44 )
return;
V_36 -> V_45 = V_38 ;
if ( ! V_36 -> V_45 )
return;
while ( * V_40 ) {
V_42 = * V_40 ;
V_43 = F_40 ( V_42 , struct V_22 ,
V_46 ) ;
if ( V_36 -> V_45 < V_43 -> V_45 )
V_40 = & ( * V_40 ) -> V_47 ;
else if ( V_36 -> V_45 >= V_43 -> V_45 )
V_40 = & ( * V_40 ) -> V_48 ;
}
F_41 ( & V_36 -> V_46 , V_42 , V_40 ) ;
F_42 ( & V_36 -> V_46 , & V_37 -> V_41 ) ;
V_36 -> V_44 = true ;
}
static void F_43 ( struct V_22 * V_36 ,
struct V_32 * V_37 )
{
if ( ! V_36 -> V_44 )
return;
F_44 ( & V_36 -> V_46 , & V_37 -> V_41 ) ;
V_36 -> V_44 = false ;
}
static void F_45 ( struct V_22 * V_36 ,
struct V_32 * V_37 )
{
unsigned long V_19 ;
F_46 ( & V_37 -> V_49 , V_19 ) ;
F_43 ( V_36 , V_37 ) ;
F_47 ( & V_37 -> V_49 , V_19 ) ;
}
static unsigned long F_48 ( struct V_2 * V_3 )
{
unsigned long V_50 = F_49 ( & V_3 -> V_51 ) ;
unsigned long V_52 = F_31 ( V_3 -> V_52 ) ;
unsigned long V_53 = 0 ;
if ( V_50 > V_52 )
V_53 = V_50 - V_52 ;
return V_53 ;
}
static void F_50 ( struct V_2 * V_3 , struct V_28 * V_28 )
{
unsigned long V_53 ;
struct V_22 * V_36 ;
struct V_32 * V_37 ;
V_37 = F_38 ( V_28 ) ;
for (; V_3 ; V_3 = F_32 ( V_3 ) ) {
V_36 = F_34 ( V_3 , V_28 ) ;
V_53 = F_48 ( V_3 ) ;
if ( V_53 || V_36 -> V_44 ) {
unsigned long V_19 ;
F_46 ( & V_37 -> V_49 , V_19 ) ;
if ( V_36 -> V_44 )
F_43 ( V_36 , V_37 ) ;
F_39 ( V_36 , V_37 , V_53 ) ;
F_47 ( & V_37 -> V_49 , V_19 ) ;
}
}
}
static void F_51 ( struct V_2 * V_3 )
{
struct V_32 * V_37 ;
struct V_22 * V_36 ;
int V_24 , V_25 ;
F_52 (nid) {
for ( V_25 = 0 ; V_25 < V_54 ; V_25 ++ ) {
V_36 = & V_3 -> V_26 [ V_24 ] -> V_27 [ V_25 ] ;
V_37 = F_37 ( V_24 , V_25 ) ;
F_45 ( V_36 , V_37 ) ;
}
}
}
static struct V_22 *
F_53 ( struct V_32 * V_37 )
{
struct V_39 * V_55 = NULL ;
struct V_22 * V_36 ;
V_56:
V_36 = NULL ;
V_55 = F_54 ( & V_37 -> V_41 ) ;
if ( ! V_55 )
goto V_57;
V_36 = F_40 ( V_55 , struct V_22 , V_46 ) ;
F_43 ( V_36 , V_37 ) ;
if ( ! F_48 ( V_36 -> V_3 ) ||
! F_15 ( & V_36 -> V_3 -> V_7 ) )
goto V_56;
V_57:
return V_36 ;
}
static struct V_22 *
F_55 ( struct V_32 * V_37 )
{
struct V_22 * V_36 ;
F_56 ( & V_37 -> V_49 ) ;
V_36 = F_53 ( V_37 ) ;
F_57 ( & V_37 -> V_49 ) ;
return V_36 ;
}
static unsigned long
F_58 ( struct V_2 * V_3 , enum V_58 V_59 )
{
long V_60 = 0 ;
int V_61 ;
F_59 (cpu)
V_60 += F_60 ( V_3 -> V_62 -> V_63 [ V_59 ] , V_61 ) ;
if ( V_60 < 0 )
V_60 = 0 ;
return V_60 ;
}
static unsigned long F_61 ( struct V_2 * V_3 ,
enum V_64 V_59 )
{
unsigned long V_60 = 0 ;
int V_61 ;
F_59 (cpu)
V_60 += F_60 ( V_3 -> V_62 -> V_65 [ V_59 ] , V_61 ) ;
return V_60 ;
}
static void F_62 ( struct V_2 * V_3 ,
struct V_28 * V_28 ,
int V_50 )
{
if ( F_63 ( V_28 ) )
F_64 ( V_3 -> V_62 -> V_63 [ V_66 ] ,
V_50 ) ;
else
F_64 ( V_3 -> V_62 -> V_63 [ V_67 ] ,
V_50 ) ;
if ( F_65 ( V_28 ) )
F_64 ( V_3 -> V_62 -> V_63 [ V_68 ] ,
V_50 ) ;
if ( V_50 > 0 )
F_66 ( V_3 -> V_62 -> V_65 [ V_69 ] ) ;
else {
F_66 ( V_3 -> V_62 -> V_65 [ V_70 ] ) ;
V_50 = - V_50 ;
}
F_64 ( V_3 -> V_62 -> V_71 , V_50 ) ;
}
static unsigned long F_67 ( struct V_2 * V_3 ,
int V_24 ,
unsigned int V_72 )
{
unsigned long V_73 = 0 ;
int V_25 ;
F_68 ( ( unsigned ) V_24 >= V_74 ) ;
for ( V_25 = 0 ; V_25 < V_54 ; V_25 ++ ) {
struct V_22 * V_36 ;
enum V_75 V_76 ;
F_69 (lru) {
if ( ! ( F_70 ( V_76 ) & V_72 ) )
continue;
V_36 = & V_3 -> V_26 [ V_24 ] -> V_27 [ V_25 ] ;
V_73 += V_36 -> V_77 [ V_76 ] ;
}
}
return V_73 ;
}
static unsigned long F_71 ( struct V_2 * V_3 ,
unsigned int V_72 )
{
unsigned long V_73 = 0 ;
int V_24 ;
F_72 (nid, N_MEMORY)
V_73 += F_67 ( V_3 , V_24 , V_72 ) ;
return V_73 ;
}
static bool F_73 ( struct V_2 * V_3 ,
enum V_78 V_79 )
{
unsigned long V_60 , V_80 ;
V_60 = F_74 ( V_3 -> V_62 -> V_71 ) ;
V_80 = F_74 ( V_3 -> V_62 -> V_81 [ V_79 ] ) ;
if ( ( long ) V_80 - ( long ) V_60 < 0 ) {
switch ( V_79 ) {
case V_82 :
V_80 = V_60 + V_83 ;
break;
case V_84 :
V_80 = V_60 + V_85 ;
break;
case V_86 :
V_80 = V_60 + V_87 ;
break;
default:
break;
}
F_75 ( V_3 -> V_62 -> V_81 [ V_79 ] , V_80 ) ;
return true ;
}
return false ;
}
static void F_76 ( struct V_2 * V_3 , struct V_28 * V_28 )
{
if ( F_77 ( F_73 ( V_3 ,
V_82 ) ) ) {
bool V_88 ;
bool T_2 V_89 ;
V_88 = F_73 ( V_3 ,
V_84 ) ;
#if V_90 > 1
T_2 = F_73 ( V_3 ,
V_86 ) ;
#endif
F_78 ( V_3 ) ;
if ( F_77 ( V_88 ) )
F_50 ( V_3 , V_28 ) ;
#if V_90 > 1
if ( F_77 ( T_2 ) )
F_79 ( & V_3 -> V_91 ) ;
#endif
}
}
struct V_2 * F_13 ( struct V_92 * V_40 )
{
if ( F_77 ( ! V_40 ) )
return NULL ;
return F_8 ( F_80 ( V_40 , V_93 ) ) ;
}
static struct V_2 * F_81 ( struct V_94 * V_95 )
{
struct V_2 * V_3 = NULL ;
F_12 () ;
do {
if ( F_77 ( ! V_95 ) )
V_3 = V_4 ;
else {
V_3 = F_13 ( F_82 ( V_95 -> V_96 ) ) ;
if ( F_77 ( ! V_3 ) )
V_3 = V_4 ;
}
} while ( ! F_15 ( & V_3 -> V_7 ) );
F_16 () ;
return V_3 ;
}
struct V_2 * F_83 ( struct V_2 * V_97 ,
struct V_2 * V_98 ,
struct V_99 * V_100 )
{
struct V_101 * V_102 ( V_103 ) ;
struct V_5 * V_7 = NULL ;
struct V_2 * V_3 = NULL ;
struct V_2 * V_104 = NULL ;
if ( F_84 () )
return NULL ;
if ( ! V_97 )
V_97 = V_4 ;
if ( V_98 && ! V_100 )
V_104 = V_98 ;
if ( ! V_97 -> V_105 && V_97 != V_4 ) {
if ( V_98 )
goto V_106;
return V_97 ;
}
F_12 () ;
if ( V_100 ) {
struct V_22 * V_36 ;
V_36 = F_25 ( V_97 , V_100 -> V_23 ) ;
V_103 = & V_36 -> V_103 [ V_100 -> V_107 ] ;
if ( V_98 && V_100 -> V_108 != V_103 -> V_108 )
goto V_109;
while ( 1 ) {
V_104 = F_31 ( V_103 -> V_110 ) ;
if ( ! V_104 || F_85 ( & V_104 -> V_7 ) )
break;
( void ) F_86 ( & V_103 -> V_110 , V_104 , NULL ) ;
}
}
if ( V_104 )
V_7 = & V_104 -> V_7 ;
for (; ; ) {
V_7 = F_87 ( V_7 , & V_97 -> V_7 ) ;
if ( ! V_7 ) {
if ( ! V_98 )
continue;
break;
}
V_3 = F_8 ( V_7 ) ;
if ( V_7 == & V_97 -> V_7 )
break;
if ( F_85 ( V_7 ) ) {
if ( F_88 ( & V_3 -> V_111 ) )
break;
F_19 ( V_7 ) ;
}
V_3 = NULL ;
}
if ( V_100 ) {
( void ) F_86 ( & V_103 -> V_110 , V_104 , V_3 ) ;
if ( V_104 )
F_19 ( & V_104 -> V_7 ) ;
if ( ! V_3 )
V_103 -> V_108 ++ ;
else if ( ! V_98 )
V_100 -> V_108 = V_103 -> V_108 ;
}
V_109:
F_16 () ;
V_106:
if ( V_98 && V_98 != V_97 )
F_19 ( & V_98 -> V_7 ) ;
return V_3 ;
}
void F_89 ( struct V_2 * V_97 ,
struct V_2 * V_98 )
{
if ( ! V_97 )
V_97 = V_4 ;
if ( V_98 && V_98 != V_97 )
F_19 ( & V_98 -> V_7 ) ;
}
static void F_90 ( struct V_2 * V_112 )
{
struct V_2 * V_3 = V_112 ;
struct V_101 * V_103 ;
struct V_22 * V_36 ;
int V_24 , V_25 ;
int V_113 ;
while ( ( V_3 = F_32 ( V_3 ) ) ) {
F_52 (nid) {
for ( V_25 = 0 ; V_25 < V_54 ; V_25 ++ ) {
V_36 = & V_3 -> V_26 [ V_24 ] -> V_27 [ V_25 ] ;
for ( V_113 = 0 ; V_113 <= V_114 ; V_113 ++ ) {
V_103 = & V_36 -> V_103 [ V_113 ] ;
F_86 ( & V_103 -> V_110 ,
V_112 , NULL ) ;
}
}
}
}
}
struct V_115 * F_91 ( struct V_23 * V_23 ,
struct V_2 * V_3 )
{
struct V_22 * V_36 ;
struct V_115 * V_115 ;
if ( F_84 () ) {
V_115 = & V_23 -> V_115 ;
goto V_106;
}
V_36 = F_25 ( V_3 , V_23 ) ;
V_115 = & V_36 -> V_115 ;
V_106:
if ( F_77 ( V_115 -> V_23 != V_23 ) )
V_115 -> V_23 = V_23 ;
return V_115 ;
}
struct V_115 * F_92 ( struct V_28 * V_28 , struct V_23 * V_23 )
{
struct V_22 * V_36 ;
struct V_2 * V_3 ;
struct V_115 * V_115 ;
if ( F_84 () ) {
V_115 = & V_23 -> V_115 ;
goto V_106;
}
V_3 = V_28 -> V_2 ;
if ( ! V_3 )
V_3 = V_4 ;
V_36 = F_34 ( V_3 , V_28 ) ;
V_115 = & V_36 -> V_115 ;
V_106:
if ( F_77 ( V_115 -> V_23 != V_23 ) )
V_115 -> V_23 = V_23 ;
return V_115 ;
}
void F_93 ( struct V_115 * V_115 , enum V_75 V_76 ,
int V_50 )
{
struct V_22 * V_36 ;
unsigned long * V_77 ;
if ( F_84 () )
return;
V_36 = F_3 ( V_115 , struct V_22 , V_115 ) ;
V_77 = V_36 -> V_77 + V_76 ;
* V_77 += V_50 ;
F_68 ( ( long ) ( * V_77 ) < 0 ) ;
}
bool F_94 ( struct V_92 * V_116 , struct V_2 * V_3 )
{
struct V_2 * V_117 ;
struct V_92 * V_40 ;
bool V_118 ;
V_40 = F_95 ( V_116 ) ;
if ( V_40 ) {
V_117 = F_81 ( V_40 -> V_95 ) ;
F_96 ( V_40 ) ;
} else {
F_12 () ;
V_117 = F_13 ( V_116 ) ;
F_11 ( & V_117 -> V_7 ) ;
F_16 () ;
}
V_118 = F_97 ( V_117 , V_3 ) ;
F_19 ( & V_117 -> V_7 ) ;
return V_118 ;
}
static unsigned long F_98 ( struct V_2 * V_3 )
{
unsigned long V_119 = 0 ;
unsigned long V_63 ;
unsigned long V_120 ;
V_63 = F_49 ( & V_3 -> V_51 ) ;
V_120 = F_31 ( V_3 -> V_51 . V_120 ) ;
if ( V_63 < V_120 )
V_119 = V_120 - V_63 ;
if ( V_121 ) {
V_63 = F_49 ( & V_3 -> V_122 ) ;
V_120 = F_31 ( V_3 -> V_122 . V_120 ) ;
if ( V_63 <= V_120 )
V_119 = F_99 ( V_119 , V_120 - V_63 ) ;
}
return V_119 ;
}
static bool F_100 ( struct V_2 * V_3 )
{
struct V_2 * V_123 ;
struct V_2 * V_124 ;
bool V_118 = false ;
F_101 ( & V_125 . V_49 ) ;
V_123 = V_125 . V_123 ;
V_124 = V_125 . V_124 ;
if ( ! V_123 )
goto V_126;
V_118 = F_97 ( V_123 , V_3 ) ||
F_97 ( V_124 , V_3 ) ;
V_126:
F_102 ( & V_125 . V_49 ) ;
return V_118 ;
}
static bool F_103 ( struct V_2 * V_3 )
{
if ( V_125 . V_127 && V_17 != V_125 . V_127 ) {
if ( F_100 ( V_3 ) ) {
F_104 ( V_128 ) ;
F_105 ( & V_125 . V_129 , & V_128 , V_130 ) ;
if ( V_125 . V_127 )
F_106 () ;
F_107 ( & V_125 . V_129 , & V_128 ) ;
return true ;
}
}
return false ;
}
void F_108 ( struct V_2 * V_3 , struct V_92 * V_40 )
{
static F_109 ( V_131 ) ;
struct V_2 * V_103 ;
unsigned int V_113 ;
F_110 ( & V_131 ) ;
F_12 () ;
if ( V_40 ) {
F_111 ( L_1 ) ;
F_112 ( F_113 ( V_40 , V_93 ) ) ;
F_114 ( L_2 ) ;
} else {
F_111 ( L_3 ) ;
}
F_112 ( V_3 -> V_7 . V_31 ) ;
F_114 ( L_4 ) ;
F_16 () ;
F_111 ( L_5 ,
F_115 ( ( V_132 ) F_49 ( & V_3 -> V_51 ) ) ,
F_115 ( ( V_132 ) V_3 -> V_51 . V_120 ) , V_3 -> V_51 . V_133 ) ;
F_111 ( L_6 ,
F_115 ( ( V_132 ) F_49 ( & V_3 -> V_122 ) ) ,
F_115 ( ( V_132 ) V_3 -> V_122 . V_120 ) , V_3 -> V_122 . V_133 ) ;
F_111 ( L_7 ,
F_115 ( ( V_132 ) F_49 ( & V_3 -> V_134 ) ) ,
F_115 ( ( V_132 ) V_3 -> V_134 . V_120 ) , V_3 -> V_134 . V_133 ) ;
F_116 (iter, memcg) {
F_111 ( L_8 ) ;
F_112 ( V_103 -> V_7 . V_31 ) ;
F_114 ( L_9 ) ;
for ( V_113 = 0 ; V_113 < V_135 ; V_113 ++ ) {
if ( V_113 == V_136 && ! V_121 )
continue;
F_114 ( L_10 , V_137 [ V_113 ] ,
F_115 ( F_58 ( V_103 , V_113 ) ) ) ;
}
for ( V_113 = 0 ; V_113 < V_138 ; V_113 ++ )
F_114 ( L_10 , V_139 [ V_113 ] ,
F_115 ( F_71 ( V_103 , F_70 ( V_113 ) ) ) ) ;
F_114 ( L_4 ) ;
}
F_117 ( & V_131 ) ;
}
static int F_118 ( struct V_2 * V_3 )
{
int V_140 = 0 ;
struct V_2 * V_103 ;
F_116 (iter, memcg)
V_140 ++ ;
return V_140 ;
}
static unsigned long F_119 ( struct V_2 * V_3 )
{
unsigned long V_120 ;
V_120 = V_3 -> V_51 . V_120 ;
if ( F_120 ( V_3 ) ) {
unsigned long V_141 ;
V_141 = V_3 -> V_122 . V_120 ;
V_120 = F_99 ( V_120 + V_142 , V_141 ) ;
}
return V_120 ;
}
static void F_121 ( struct V_2 * V_3 , T_3 V_143 ,
int V_144 )
{
struct V_145 V_146 = {
. V_147 = NULL ,
. V_148 = NULL ,
. V_143 = V_143 ,
. V_144 = V_144 ,
} ;
struct V_2 * V_103 ;
unsigned long V_149 = 0 ;
unsigned long V_150 ;
unsigned int V_151 = 0 ;
struct V_92 * V_152 = NULL ;
F_110 ( & V_153 ) ;
if ( F_122 ( V_17 ) || F_123 ( V_17 ) ) {
F_124 ( V_17 ) ;
goto V_126;
}
F_125 ( & V_146 , V_154 , V_3 ) ;
V_150 = F_119 ( V_3 ) ? : 1 ;
F_116 (iter, memcg) {
struct V_155 V_156 ;
struct V_92 * V_116 ;
F_126 ( & V_103 -> V_7 , & V_156 ) ;
while ( ( V_116 = F_127 ( & V_156 ) ) ) {
switch ( F_128 ( & V_146 , V_116 , V_150 ) ) {
case V_157 :
if ( V_152 )
F_129 ( V_152 ) ;
V_152 = V_116 ;
V_149 = V_158 ;
F_130 ( V_152 ) ;
case V_159 :
continue;
case V_160 :
F_131 ( & V_156 ) ;
F_89 ( V_3 , V_103 ) ;
if ( V_152 )
F_129 ( V_152 ) ;
goto V_126;
case V_161 :
break;
} ;
V_151 = F_132 ( V_116 , V_3 , NULL , V_150 ) ;
if ( ! V_151 || V_151 < V_149 )
continue;
if ( V_151 == V_149 &&
F_133 ( V_152 ) )
continue;
if ( V_152 )
F_129 ( V_152 ) ;
V_152 = V_116 ;
V_149 = V_151 ;
F_130 ( V_152 ) ;
}
F_131 ( & V_156 ) ;
}
if ( V_152 ) {
V_151 = V_149 * 1000 / V_150 ;
F_134 ( & V_146 , V_152 , V_151 , V_150 , V_3 ,
L_11 ) ;
}
V_126:
F_117 ( & V_153 ) ;
}
static bool F_135 ( struct V_2 * V_3 ,
int V_24 , bool V_162 )
{
if ( F_67 ( V_3 , V_24 , V_163 ) )
return true ;
if ( V_162 || ! V_142 )
return false ;
if ( F_67 ( V_3 , V_24 , V_164 ) )
return true ;
return false ;
}
static void F_136 ( struct V_2 * V_3 )
{
int V_24 ;
if ( ! F_137 ( & V_3 -> V_91 ) )
return;
if ( F_138 ( & V_3 -> V_165 ) > 1 )
return;
V_3 -> V_166 = V_167 [ V_168 ] ;
F_139 (nid, node_states[N_MEMORY]) {
if ( ! F_135 ( V_3 , V_24 , false ) )
F_140 ( V_24 , V_3 -> V_166 ) ;
}
F_141 ( & V_3 -> V_91 , 0 ) ;
F_141 ( & V_3 -> V_165 , 0 ) ;
}
int F_142 ( struct V_2 * V_3 )
{
int V_169 ;
F_136 ( V_3 ) ;
V_169 = V_3 -> V_170 ;
V_169 = F_143 ( V_169 , V_3 -> V_166 ) ;
if ( V_169 == V_90 )
V_169 = F_144 ( V_3 -> V_166 ) ;
if ( F_77 ( V_169 == V_90 ) )
V_169 = F_145 () ;
V_3 -> V_170 = V_169 ;
return V_169 ;
}
int F_142 ( struct V_2 * V_3 )
{
return 0 ;
}
static int F_146 ( struct V_2 * V_171 ,
struct V_23 * V_23 ,
T_3 V_143 ,
unsigned long * V_172 )
{
struct V_2 * V_173 = NULL ;
int V_174 = 0 ;
int V_175 = 0 ;
unsigned long V_53 ;
unsigned long V_176 ;
struct V_99 V_100 = {
. V_23 = V_23 ,
. V_107 = 0 ,
} ;
V_53 = F_48 ( V_171 ) ;
while ( 1 ) {
V_173 = F_83 ( V_171 , V_173 , & V_100 ) ;
if ( ! V_173 ) {
V_175 ++ ;
if ( V_175 >= 2 ) {
if ( ! V_174 )
break;
if ( V_174 >= ( V_53 >> 2 ) ||
( V_175 > V_177 ) )
break;
}
continue;
}
V_174 += F_147 ( V_173 , V_143 , false ,
V_23 , & V_176 ) ;
* V_172 += V_176 ;
if ( ! F_48 ( V_171 ) )
break;
}
F_89 ( V_171 , V_173 ) ;
return V_174 ;
}
static bool F_148 ( struct V_2 * V_3 )
{
struct V_2 * V_103 , * V_178 = NULL ;
F_101 ( & V_179 ) ;
F_116 (iter, memcg) {
if ( V_103 -> V_153 ) {
V_178 = V_103 ;
F_89 ( V_3 , V_103 ) ;
break;
} else
V_103 -> V_153 = true ;
}
if ( V_178 ) {
F_116 (iter, memcg) {
if ( V_103 == V_178 ) {
F_89 ( V_3 , V_103 ) ;
break;
}
V_103 -> V_153 = false ;
}
} else
F_149 ( & V_180 , 0 , 1 , V_181 ) ;
F_102 ( & V_179 ) ;
return ! V_178 ;
}
static void F_150 ( struct V_2 * V_3 )
{
struct V_2 * V_103 ;
F_101 ( & V_179 ) ;
F_151 ( & V_180 , 1 , V_181 ) ;
F_116 (iter, memcg)
V_103 -> V_153 = false ;
F_102 ( & V_179 ) ;
}
static void F_152 ( struct V_2 * V_3 )
{
struct V_2 * V_103 ;
F_101 ( & V_179 ) ;
F_116 (iter, memcg)
V_103 -> V_182 ++ ;
F_102 ( & V_179 ) ;
}
static void F_153 ( struct V_2 * V_3 )
{
struct V_2 * V_103 ;
F_101 ( & V_179 ) ;
F_116 (iter, memcg)
if ( V_103 -> V_182 > 0 )
V_103 -> V_182 -- ;
F_102 ( & V_179 ) ;
}
static int F_154 ( T_4 * V_128 ,
unsigned V_183 , int V_184 , void * V_185 )
{
struct V_2 * V_186 = (struct V_2 * ) V_185 ;
struct V_2 * V_187 ;
struct V_188 * V_188 ;
V_188 = F_3 ( V_128 , struct V_188 , V_128 ) ;
V_187 = V_188 -> V_3 ;
if ( ! F_97 ( V_186 , V_187 ) &&
! F_97 ( V_187 , V_186 ) )
return 0 ;
return F_155 ( V_128 , V_183 , V_184 , V_185 ) ;
}
static void F_156 ( struct V_2 * V_3 )
{
if ( V_3 && V_3 -> V_182 )
F_157 ( & V_189 , V_190 , 0 , V_3 ) ;
}
static void F_158 ( struct V_2 * V_3 , T_3 V_191 , int V_144 )
{
if ( ! V_17 -> V_192 )
return;
F_11 ( & V_3 -> V_7 ) ;
V_17 -> V_193 = V_3 ;
V_17 -> V_194 = V_191 ;
V_17 -> V_195 = V_144 ;
}
bool F_159 ( bool V_196 )
{
struct V_2 * V_3 = V_17 -> V_193 ;
struct V_188 V_197 ;
bool V_198 ;
if ( ! V_3 )
return false ;
if ( ! V_196 || V_199 )
goto V_200;
V_197 . V_3 = V_3 ;
V_197 . V_128 . V_19 = 0 ;
V_197 . V_128 . V_201 = F_154 ;
V_197 . V_128 . V_202 = V_17 ;
F_160 ( & V_197 . V_128 . V_203 ) ;
F_105 ( & V_189 , & V_197 . V_128 , V_204 ) ;
F_152 ( V_3 ) ;
V_198 = F_148 ( V_3 ) ;
if ( V_198 )
F_161 ( V_3 ) ;
if ( V_198 && ! V_3 -> V_205 ) {
F_153 ( V_3 ) ;
F_107 ( & V_189 , & V_197 . V_128 ) ;
F_121 ( V_3 , V_17 -> V_194 ,
V_17 -> V_195 ) ;
} else {
F_106 () ;
F_153 ( V_3 ) ;
F_107 ( & V_189 , & V_197 . V_128 ) ;
}
if ( V_198 ) {
F_150 ( V_3 ) ;
F_156 ( V_3 ) ;
}
V_200:
V_17 -> V_193 = NULL ;
F_19 ( & V_3 -> V_7 ) ;
return true ;
}
struct V_2 * F_162 ( struct V_28 * V_28 )
{
struct V_2 * V_3 ;
unsigned long V_19 ;
F_12 () ;
if ( F_84 () )
return NULL ;
V_206:
V_3 = V_28 -> V_2 ;
if ( F_77 ( ! V_3 ) )
return NULL ;
if ( F_137 ( & V_3 -> V_207 ) <= 0 )
return V_3 ;
F_46 ( & V_3 -> V_208 , V_19 ) ;
if ( V_3 != V_28 -> V_2 ) {
F_47 ( & V_3 -> V_208 , V_19 ) ;
goto V_206;
}
V_3 -> V_209 = V_17 ;
V_3 -> V_210 = V_19 ;
return V_3 ;
}
void F_163 ( struct V_2 * V_3 )
{
if ( V_3 && V_3 -> V_209 == V_17 ) {
unsigned long V_19 = V_3 -> V_210 ;
V_3 -> V_209 = NULL ;
V_3 -> V_210 = 0 ;
F_47 ( & V_3 -> V_208 , V_19 ) ;
}
F_16 () ;
}
static bool F_164 ( struct V_2 * V_3 , unsigned int V_50 )
{
struct V_211 * V_212 ;
bool V_118 = false ;
if ( V_50 > V_213 )
return V_118 ;
V_212 = & F_165 ( V_214 ) ;
if ( V_3 == V_212 -> V_215 && V_212 -> V_50 >= V_50 ) {
V_212 -> V_50 -= V_50 ;
V_118 = true ;
}
F_166 ( V_214 ) ;
return V_118 ;
}
static void F_167 ( struct V_211 * V_212 )
{
struct V_2 * V_216 = V_212 -> V_215 ;
if ( V_212 -> V_50 ) {
F_168 ( & V_216 -> V_51 , V_212 -> V_50 ) ;
if ( V_121 )
F_168 ( & V_216 -> V_122 , V_212 -> V_50 ) ;
F_169 ( & V_216 -> V_7 , V_212 -> V_50 ) ;
V_212 -> V_50 = 0 ;
}
V_212 -> V_215 = NULL ;
}
static void F_170 ( struct V_217 * V_218 )
{
struct V_211 * V_212 = F_171 ( & V_214 ) ;
F_167 ( V_212 ) ;
F_172 ( V_219 , & V_212 -> V_19 ) ;
}
static void F_173 ( struct V_2 * V_3 , unsigned int V_50 )
{
struct V_211 * V_212 = & F_165 ( V_214 ) ;
if ( V_212 -> V_215 != V_3 ) {
F_167 ( V_212 ) ;
V_212 -> V_215 = V_3 ;
}
V_212 -> V_50 += V_50 ;
F_166 ( V_214 ) ;
}
static void F_174 ( struct V_2 * V_171 )
{
int V_61 , V_220 ;
if ( ! F_175 ( & V_221 ) )
return;
F_176 () ;
V_220 = F_177 () ;
F_178 (cpu) {
struct V_211 * V_212 = & F_60 ( V_214 , V_61 ) ;
struct V_2 * V_3 ;
V_3 = V_212 -> V_215 ;
if ( ! V_3 || ! V_212 -> V_50 )
continue;
if ( ! F_97 ( V_3 , V_171 ) )
continue;
if ( ! F_179 ( V_219 , & V_212 -> V_19 ) ) {
if ( V_61 == V_220 )
F_170 ( & V_212 -> V_222 ) ;
else
F_180 ( V_61 , & V_212 -> V_222 ) ;
}
}
F_181 () ;
F_182 () ;
F_117 ( & V_221 ) ;
}
static int F_183 ( struct V_223 * V_224 ,
unsigned long V_225 ,
void * V_226 )
{
int V_61 = ( unsigned long ) V_226 ;
struct V_211 * V_212 ;
if ( V_225 == V_227 )
return V_228 ;
if ( V_225 != V_229 && V_225 != V_230 )
return V_228 ;
V_212 = & F_60 ( V_214 , V_61 ) ;
F_167 ( V_212 ) ;
return V_228 ;
}
void F_184 ( void )
{
unsigned int V_50 = V_17 -> V_231 ;
struct V_2 * V_3 , * V_104 ;
if ( F_185 ( ! V_50 ) )
return;
V_104 = V_3 = F_81 ( V_17 -> V_95 ) ;
do {
if ( F_49 ( & V_104 -> V_51 ) <= V_104 -> V_232 )
continue;
F_186 ( V_104 , V_233 , 1 ) ;
F_187 ( V_104 , V_50 , V_234 , true ) ;
} while ( ( V_104 = F_32 ( V_104 ) ) );
F_19 ( & V_3 -> V_7 ) ;
V_17 -> V_231 = 0 ;
}
static int F_188 ( struct V_2 * V_3 , T_3 V_143 ,
unsigned int V_50 )
{
unsigned int V_235 = F_189 ( V_213 , V_50 ) ;
int V_236 = V_237 ;
struct V_2 * V_238 ;
struct V_239 * V_240 ;
unsigned long V_241 ;
bool V_242 = true ;
bool V_243 = false ;
if ( F_4 ( V_3 ) )
return 0 ;
V_56:
if ( F_164 ( V_3 , V_50 ) )
return 0 ;
if ( ! V_121 ||
F_190 ( & V_3 -> V_122 , V_235 , & V_240 ) ) {
if ( F_190 ( & V_3 -> V_51 , V_235 , & V_240 ) )
goto V_244;
if ( V_121 )
F_168 ( & V_3 -> V_122 , V_235 ) ;
V_238 = F_191 ( V_240 , V_51 ) ;
} else {
V_238 = F_191 ( V_240 , V_122 ) ;
V_242 = false ;
}
if ( V_235 > V_50 ) {
V_235 = V_50 ;
goto V_56;
}
if ( F_77 ( F_192 ( V_245 ) ||
F_122 ( V_17 ) ||
V_17 -> V_19 & V_246 ) )
goto V_247;
if ( F_77 ( F_193 ( V_17 ) ) )
goto V_248;
if ( ! F_194 ( V_143 ) )
goto V_248;
F_186 ( V_238 , V_249 , 1 ) ;
V_241 = F_187 ( V_238 , V_50 ,
V_143 , V_242 ) ;
if ( F_98 ( V_238 ) >= V_50 )
goto V_56;
if ( ! V_243 ) {
F_174 ( V_238 ) ;
V_243 = true ;
goto V_56;
}
if ( V_143 & V_250 )
goto V_248;
if ( V_241 && V_50 <= ( 1 << V_251 ) )
goto V_56;
if ( F_103 ( V_238 ) )
goto V_56;
if ( V_236 -- )
goto V_56;
if ( V_143 & V_252 )
goto V_247;
if ( F_122 ( V_17 ) )
goto V_247;
F_186 ( V_238 , V_253 , 1 ) ;
F_158 ( V_238 , V_143 ,
F_195 ( V_50 * V_254 ) ) ;
V_248:
if ( ! ( V_143 & V_252 ) )
return - V_255 ;
V_247:
F_196 ( & V_3 -> V_51 , V_50 ) ;
if ( V_121 )
F_196 ( & V_3 -> V_122 , V_50 ) ;
F_197 ( & V_3 -> V_7 , V_50 ) ;
return 0 ;
V_244:
F_197 ( & V_3 -> V_7 , V_235 ) ;
if ( V_235 > V_50 )
F_173 ( V_3 , V_235 - V_50 ) ;
do {
if ( F_49 ( & V_3 -> V_51 ) > V_3 -> V_232 ) {
V_17 -> V_231 += V_235 ;
F_198 ( V_17 ) ;
break;
}
} while ( ( V_3 = F_32 ( V_3 ) ) );
return 0 ;
}
static void F_199 ( struct V_2 * V_3 , unsigned int V_50 )
{
if ( F_4 ( V_3 ) )
return;
F_168 ( & V_3 -> V_51 , V_50 ) ;
if ( V_121 )
F_168 ( & V_3 -> V_122 , V_50 ) ;
F_169 ( & V_3 -> V_7 , V_50 ) ;
}
static void F_200 ( struct V_28 * V_28 , int * V_256 )
{
struct V_23 * V_23 = F_201 ( V_28 ) ;
F_56 ( & V_23 -> V_257 ) ;
if ( F_202 ( V_28 ) ) {
struct V_115 * V_115 ;
V_115 = F_92 ( V_28 , V_23 ) ;
F_203 ( V_28 ) ;
F_204 ( V_28 , V_115 , F_205 ( V_28 ) ) ;
* V_256 = 1 ;
} else
* V_256 = 0 ;
}
static void F_206 ( struct V_28 * V_28 , int V_256 )
{
struct V_23 * V_23 = F_201 ( V_28 ) ;
if ( V_256 ) {
struct V_115 * V_115 ;
V_115 = F_92 ( V_28 , V_23 ) ;
F_207 ( F_202 ( V_28 ) , V_28 ) ;
F_208 ( V_28 ) ;
F_209 ( V_28 , V_115 , F_205 ( V_28 ) ) ;
}
F_57 ( & V_23 -> V_257 ) ;
}
static void F_210 ( struct V_28 * V_28 , struct V_2 * V_3 ,
bool V_258 )
{
int V_256 ;
F_207 ( V_28 -> V_2 , V_28 ) ;
if ( V_258 )
F_200 ( V_28 , & V_256 ) ;
V_28 -> V_2 = V_3 ;
if ( V_258 )
F_206 ( V_28 , V_256 ) ;
}
static int F_211 ( void )
{
int V_8 , V_259 ;
int V_260 ;
V_8 = F_212 ( & V_261 ,
0 , V_262 , V_234 ) ;
if ( V_8 < 0 )
return V_8 ;
if ( V_8 < V_263 )
return V_8 ;
F_213 ( & V_21 ) ;
V_259 = 2 * ( V_8 + 1 ) ;
if ( V_259 < V_264 )
V_259 = V_264 ;
else if ( V_259 > V_262 )
V_259 = V_262 ;
V_260 = F_214 ( V_259 ) ;
if ( ! V_260 )
V_260 = F_215 ( V_259 ) ;
if ( ! V_260 )
V_263 = V_259 ;
F_216 ( & V_21 ) ;
if ( V_260 ) {
F_217 ( & V_261 , V_8 ) ;
return V_260 ;
}
return V_8 ;
}
static void F_218 ( int V_8 )
{
F_217 ( & V_261 , V_8 ) ;
}
static void F_219 ( struct V_217 * V_265 )
{
struct V_266 * V_267 =
F_3 ( V_265 , struct V_266 , V_222 ) ;
struct V_2 * V_3 = V_267 -> V_3 ;
struct V_268 * V_269 = V_267 -> V_269 ;
F_220 ( V_3 , V_269 ) ;
F_19 ( & V_3 -> V_7 ) ;
F_221 ( V_267 ) ;
}
static void F_222 ( struct V_2 * V_3 ,
struct V_268 * V_269 )
{
struct V_266 * V_267 ;
V_267 = F_223 ( sizeof( * V_267 ) , V_270 ) ;
if ( ! V_267 )
return;
F_11 ( & V_3 -> V_7 ) ;
V_267 -> V_3 = V_3 ;
V_267 -> V_269 = V_269 ;
F_224 ( & V_267 -> V_222 , F_219 ) ;
F_225 ( & V_267 -> V_222 ) ;
}
static void F_226 ( struct V_2 * V_3 ,
struct V_268 * V_269 )
{
V_17 -> V_271 = 1 ;
F_222 ( V_3 , V_269 ) ;
V_17 -> V_271 = 0 ;
}
struct V_268 * F_227 ( struct V_268 * V_269 )
{
struct V_2 * V_3 ;
struct V_268 * V_272 ;
int V_273 ;
F_68 ( ! F_228 ( V_269 ) ) ;
if ( V_17 -> V_271 )
return V_269 ;
V_3 = F_81 ( V_17 -> V_95 ) ;
V_273 = F_31 ( V_3 -> V_273 ) ;
if ( V_273 < 0 )
goto V_106;
V_272 = F_229 ( V_269 , V_273 ) ;
if ( F_185 ( V_272 ) )
return V_272 ;
F_226 ( V_3 , V_269 ) ;
V_106:
F_19 ( & V_3 -> V_7 ) ;
return V_269 ;
}
void F_230 ( struct V_268 * V_269 )
{
if ( ! F_228 ( V_269 ) )
F_19 ( & V_269 -> V_274 . V_3 -> V_7 ) ;
}
int F_231 ( struct V_28 * V_28 , T_3 V_275 , int V_144 ,
struct V_2 * V_3 )
{
unsigned int V_50 = 1 << V_144 ;
struct V_239 * V_240 ;
int V_118 ;
if ( ! F_232 ( V_3 ) )
return 0 ;
if ( ! F_190 ( & V_3 -> V_134 , V_50 , & V_240 ) )
return - V_255 ;
V_118 = F_188 ( V_3 , V_275 , V_50 ) ;
if ( V_118 ) {
F_168 ( & V_3 -> V_134 , V_50 ) ;
return V_118 ;
}
V_28 -> V_2 = V_3 ;
return 0 ;
}
int F_233 ( struct V_28 * V_28 , T_3 V_275 , int V_144 )
{
struct V_2 * V_3 ;
int V_118 ;
V_3 = F_81 ( V_17 -> V_95 ) ;
V_118 = F_231 ( V_28 , V_275 , V_144 , V_3 ) ;
F_19 ( & V_3 -> V_7 ) ;
return V_118 ;
}
void F_234 ( struct V_28 * V_28 , int V_144 )
{
struct V_2 * V_3 = V_28 -> V_2 ;
unsigned int V_50 = 1 << V_144 ;
if ( ! V_3 )
return;
F_207 ( F_4 ( V_3 ) , V_28 ) ;
F_168 ( & V_3 -> V_134 , V_50 ) ;
F_168 ( & V_3 -> V_51 , V_50 ) ;
if ( V_121 )
F_168 ( & V_3 -> V_122 , V_50 ) ;
V_28 -> V_2 = NULL ;
F_169 ( & V_3 -> V_7 , V_50 ) ;
}
void F_235 ( struct V_28 * V_276 )
{
int V_113 ;
if ( F_84 () )
return;
for ( V_113 = 1 ; V_113 < V_277 ; V_113 ++ )
V_276 [ V_113 ] . V_2 = V_276 -> V_2 ;
F_236 ( V_276 -> V_2 -> V_62 -> V_63 [ V_68 ] ,
V_277 ) ;
}
static void F_237 ( struct V_2 * V_3 ,
bool V_278 )
{
int V_60 = ( V_278 ) ? 1 : - 1 ;
F_238 ( V_3 -> V_62 -> V_63 [ V_136 ] , V_60 ) ;
}
static int F_239 ( T_5 V_279 ,
struct V_2 * V_123 , struct V_2 * V_124 )
{
unsigned short V_280 , V_281 ;
V_280 = F_5 ( V_123 ) ;
V_281 = F_5 ( V_124 ) ;
if ( F_240 ( V_279 , V_280 , V_281 ) == V_280 ) {
F_237 ( V_123 , false ) ;
F_237 ( V_124 , true ) ;
return 0 ;
}
return - V_282 ;
}
static inline int F_239 ( T_5 V_279 ,
struct V_2 * V_123 , struct V_2 * V_124 )
{
return - V_282 ;
}
static int F_241 ( struct V_2 * V_3 ,
unsigned long V_120 )
{
unsigned long V_283 ;
unsigned long V_284 ;
bool V_285 = false ;
int V_286 ;
int V_118 ;
V_286 = V_237 *
F_118 ( V_3 ) ;
V_284 = F_49 ( & V_3 -> V_51 ) ;
do {
if ( F_242 ( V_17 ) ) {
V_118 = - V_287 ;
break;
}
F_110 ( & V_288 ) ;
if ( V_120 > V_3 -> V_122 . V_120 ) {
F_117 ( & V_288 ) ;
V_118 = - V_282 ;
break;
}
if ( V_120 > V_3 -> V_51 . V_120 )
V_285 = true ;
V_118 = F_243 ( & V_3 -> V_51 , V_120 ) ;
F_117 ( & V_288 ) ;
if ( ! V_118 )
break;
F_187 ( V_3 , 1 , V_234 , true ) ;
V_283 = F_49 ( & V_3 -> V_51 ) ;
if ( V_283 >= V_284 )
V_286 -- ;
else
V_284 = V_283 ;
} while ( V_286 );
if ( ! V_118 && V_285 )
F_156 ( V_3 ) ;
return V_118 ;
}
static int F_244 ( struct V_2 * V_3 ,
unsigned long V_120 )
{
unsigned long V_283 ;
unsigned long V_284 ;
bool V_285 = false ;
int V_286 ;
int V_118 ;
V_286 = V_237 *
F_118 ( V_3 ) ;
V_284 = F_49 ( & V_3 -> V_122 ) ;
do {
if ( F_242 ( V_17 ) ) {
V_118 = - V_287 ;
break;
}
F_110 ( & V_288 ) ;
if ( V_120 < V_3 -> V_51 . V_120 ) {
F_117 ( & V_288 ) ;
V_118 = - V_282 ;
break;
}
if ( V_120 > V_3 -> V_122 . V_120 )
V_285 = true ;
V_118 = F_243 ( & V_3 -> V_122 , V_120 ) ;
F_117 ( & V_288 ) ;
if ( ! V_118 )
break;
F_187 ( V_3 , 1 , V_234 , false ) ;
V_283 = F_49 ( & V_3 -> V_122 ) ;
if ( V_283 >= V_284 )
V_286 -- ;
else
V_284 = V_283 ;
} while ( V_286 );
if ( ! V_118 && V_285 )
F_156 ( V_3 ) ;
return V_118 ;
}
unsigned long F_245 ( struct V_23 * V_23 , int V_144 ,
T_3 V_143 ,
unsigned long * V_172 )
{
unsigned long V_241 = 0 ;
struct V_22 * V_36 , * V_289 = NULL ;
unsigned long V_290 ;
int V_175 = 0 ;
struct V_32 * V_37 ;
unsigned long V_53 ;
unsigned long V_176 ;
if ( V_144 > 0 )
return 0 ;
V_37 = F_37 ( F_26 ( V_23 ) , F_27 ( V_23 ) ) ;
do {
if ( V_289 )
V_36 = V_289 ;
else
V_36 = F_55 ( V_37 ) ;
if ( ! V_36 )
break;
V_176 = 0 ;
V_290 = F_146 ( V_36 -> V_3 , V_23 ,
V_143 , & V_176 ) ;
V_241 += V_290 ;
* V_172 += V_176 ;
F_56 ( & V_37 -> V_49 ) ;
F_43 ( V_36 , V_37 ) ;
V_289 = NULL ;
if ( ! V_290 )
V_289 = F_53 ( V_37 ) ;
V_53 = F_48 ( V_36 -> V_3 ) ;
F_39 ( V_36 , V_37 , V_53 ) ;
F_57 ( & V_37 -> V_49 ) ;
F_19 ( & V_36 -> V_3 -> V_7 ) ;
V_175 ++ ;
if ( ! V_241 &&
( V_289 == NULL ||
V_175 > V_291 ) )
break;
} while ( ! V_241 );
if ( V_289 )
F_19 ( & V_289 -> V_3 -> V_7 ) ;
return V_241 ;
}
static inline bool F_246 ( struct V_2 * V_3 )
{
bool V_118 ;
F_247 ( & V_292 ) ;
F_12 () ;
V_118 = F_248 ( NULL , & V_3 -> V_7 ) ;
F_16 () ;
return V_118 ;
}
static int F_249 ( struct V_2 * V_3 )
{
int V_236 = V_237 ;
F_250 () ;
while ( V_236 && F_49 ( & V_3 -> V_51 ) ) {
int V_293 ;
if ( F_242 ( V_17 ) )
return - V_287 ;
V_293 = F_187 ( V_3 , 1 ,
V_234 , true ) ;
if ( ! V_293 ) {
V_236 -- ;
F_251 ( V_294 , V_295 / 10 ) ;
}
}
return 0 ;
}
static T_6 F_252 ( struct V_296 * V_297 ,
char * V_298 , T_7 V_299 ,
T_8 V_300 )
{
struct V_2 * V_3 = F_8 ( F_253 ( V_297 ) ) ;
if ( F_4 ( V_3 ) )
return - V_282 ;
return F_249 ( V_3 ) ? : V_299 ;
}
static V_132 F_254 ( struct V_5 * V_7 ,
struct V_301 * V_302 )
{
return F_8 ( V_7 ) -> V_105 ;
}
static int F_255 ( struct V_5 * V_7 ,
struct V_301 * V_302 , V_132 V_60 )
{
int V_303 = 0 ;
struct V_2 * V_3 = F_8 ( V_7 ) ;
struct V_2 * V_304 = F_8 ( V_3 -> V_7 . V_42 ) ;
F_110 ( & V_292 ) ;
if ( V_3 -> V_105 == V_60 )
goto V_106;
if ( ( ! V_304 || ! V_304 -> V_105 ) &&
( V_60 == 1 || V_60 == 0 ) ) {
if ( ! F_246 ( V_3 ) )
V_3 -> V_105 = V_60 ;
else
V_303 = - V_305 ;
} else
V_303 = - V_282 ;
V_106:
F_117 ( & V_292 ) ;
return V_303 ;
}
static unsigned long F_256 ( struct V_2 * V_3 ,
enum V_58 V_59 )
{
struct V_2 * V_103 ;
unsigned long V_60 = 0 ;
F_116 (iter, memcg)
V_60 += F_58 ( V_103 , V_59 ) ;
return V_60 ;
}
static unsigned long F_257 ( struct V_2 * V_3 , bool V_306 )
{
unsigned long V_60 ;
if ( F_4 ( V_3 ) ) {
V_60 = F_256 ( V_3 , V_67 ) ;
V_60 += F_256 ( V_3 , V_66 ) ;
if ( V_306 )
V_60 += F_256 ( V_3 , V_136 ) ;
} else {
if ( ! V_306 )
V_60 = F_49 ( & V_3 -> V_51 ) ;
else
V_60 = F_49 ( & V_3 -> V_122 ) ;
}
return V_60 ;
}
static V_132 F_258 ( struct V_5 * V_7 ,
struct V_301 * V_302 )
{
struct V_2 * V_3 = F_8 ( V_7 ) ;
struct V_239 * V_240 ;
switch ( F_259 ( V_302 -> V_202 ) ) {
case V_307 :
V_240 = & V_3 -> V_51 ;
break;
case V_308 :
V_240 = & V_3 -> V_122 ;
break;
case V_309 :
V_240 = & V_3 -> V_134 ;
break;
default:
F_260 () ;
}
switch ( F_261 ( V_302 -> V_202 ) ) {
case V_310 :
if ( V_240 == & V_3 -> V_51 )
return ( V_132 ) F_257 ( V_3 , false ) * V_254 ;
if ( V_240 == & V_3 -> V_122 )
return ( V_132 ) F_257 ( V_3 , true ) * V_254 ;
return ( V_132 ) F_49 ( V_240 ) * V_254 ;
case V_311 :
return ( V_132 ) V_240 -> V_120 * V_254 ;
case V_312 :
return ( V_132 ) V_240 -> V_313 * V_254 ;
case V_314 :
return V_240 -> V_133 ;
case V_315 :
return ( V_132 ) V_3 -> V_52 * V_254 ;
default:
F_260 () ;
}
}
static int F_262 ( struct V_2 * V_3 ,
unsigned long V_50 )
{
int V_260 = 0 ;
int V_316 ;
F_10 ( V_3 -> V_273 >= 0 ) ;
F_10 ( V_3 -> V_317 ) ;
F_10 ( V_3 -> V_318 ) ;
F_110 ( & V_292 ) ;
if ( F_263 ( V_3 -> V_7 . V_31 ) ||
( V_3 -> V_105 && F_246 ( V_3 ) ) )
V_260 = - V_305 ;
F_117 ( & V_292 ) ;
if ( V_260 )
goto V_106;
V_316 = F_211 () ;
if ( V_316 < 0 ) {
V_260 = V_316 ;
goto V_106;
}
V_260 = F_243 ( & V_3 -> V_134 , V_50 ) ;
F_68 ( V_260 ) ;
F_264 ( & V_319 ) ;
V_3 -> V_273 = V_316 ;
V_3 -> V_317 = true ;
V_3 -> V_318 = true ;
V_106:
return V_260 ;
}
static int F_265 ( struct V_2 * V_3 ,
unsigned long V_120 )
{
int V_118 ;
F_110 ( & V_288 ) ;
if ( ! F_232 ( V_3 ) )
V_118 = F_262 ( V_3 , V_120 ) ;
else
V_118 = F_243 ( & V_3 -> V_134 , V_120 ) ;
F_117 ( & V_288 ) ;
return V_118 ;
}
static int F_266 ( struct V_2 * V_3 )
{
int V_118 = 0 ;
struct V_2 * V_42 = F_32 ( V_3 ) ;
if ( ! V_42 )
return 0 ;
F_110 ( & V_288 ) ;
if ( F_232 ( V_42 ) )
V_118 = F_262 ( V_3 , V_320 ) ;
F_117 ( & V_288 ) ;
return V_118 ;
}
static int F_265 ( struct V_2 * V_3 ,
unsigned long V_120 )
{
return - V_282 ;
}
static T_6 F_267 ( struct V_296 * V_297 ,
char * V_298 , T_7 V_299 , T_8 V_300 )
{
struct V_2 * V_3 = F_8 ( F_253 ( V_297 ) ) ;
unsigned long V_50 ;
int V_118 ;
V_298 = F_268 ( V_298 ) ;
V_118 = F_269 ( V_298 , L_12 , & V_50 ) ;
if ( V_118 )
return V_118 ;
switch ( F_261 ( F_270 ( V_297 ) -> V_202 ) ) {
case V_311 :
if ( F_4 ( V_3 ) ) {
V_118 = - V_282 ;
break;
}
switch ( F_259 ( F_270 ( V_297 ) -> V_202 ) ) {
case V_307 :
V_118 = F_241 ( V_3 , V_50 ) ;
break;
case V_308 :
V_118 = F_244 ( V_3 , V_50 ) ;
break;
case V_309 :
V_118 = F_265 ( V_3 , V_50 ) ;
break;
}
break;
case V_315 :
V_3 -> V_52 = V_50 ;
V_118 = 0 ;
break;
}
return V_118 ? : V_299 ;
}
static T_6 F_271 ( struct V_296 * V_297 , char * V_298 ,
T_7 V_299 , T_8 V_300 )
{
struct V_2 * V_3 = F_8 ( F_253 ( V_297 ) ) ;
struct V_239 * V_240 ;
switch ( F_259 ( F_270 ( V_297 ) -> V_202 ) ) {
case V_307 :
V_240 = & V_3 -> V_51 ;
break;
case V_308 :
V_240 = & V_3 -> V_122 ;
break;
case V_309 :
V_240 = & V_3 -> V_134 ;
break;
default:
F_260 () ;
}
switch ( F_261 ( F_270 ( V_297 ) -> V_202 ) ) {
case V_312 :
F_272 ( V_240 ) ;
break;
case V_314 :
V_240 -> V_133 = 0 ;
break;
default:
F_260 () ;
}
return V_299 ;
}
static V_132 F_273 ( struct V_5 * V_7 ,
struct V_301 * V_302 )
{
return F_8 ( V_7 ) -> V_321 ;
}
static int F_274 ( struct V_5 * V_7 ,
struct V_301 * V_302 , V_132 V_60 )
{
struct V_2 * V_3 = F_8 ( V_7 ) ;
if ( V_60 & ~ V_322 )
return - V_282 ;
V_3 -> V_321 = V_60 ;
return 0 ;
}
static int F_274 ( struct V_5 * V_7 ,
struct V_301 * V_302 , V_132 V_60 )
{
return - V_323 ;
}
static int F_275 ( struct V_324 * V_325 , void * V_326 )
{
struct V_327 {
const char * V_328 ;
unsigned int V_72 ;
};
static const struct V_327 V_329 [] = {
{ L_13 , V_330 } ,
{ L_14 , V_163 } ,
{ L_15 , V_164 } ,
{ L_16 , F_70 (LRU_UNEVICTABLE) } ,
} ;
const struct V_327 * V_62 ;
int V_24 ;
unsigned long V_73 ;
struct V_2 * V_3 = F_8 ( F_276 ( V_325 ) ) ;
for ( V_62 = V_329 ; V_62 < V_329 + F_277 ( V_329 ) ; V_62 ++ ) {
V_73 = F_71 ( V_3 , V_62 -> V_72 ) ;
F_278 ( V_325 , L_17 , V_62 -> V_328 , V_73 ) ;
F_72 (nid, N_MEMORY) {
V_73 = F_67 ( V_3 , V_24 ,
V_62 -> V_72 ) ;
F_278 ( V_325 , L_18 , V_24 , V_73 ) ;
}
F_279 ( V_325 , '\n' ) ;
}
for ( V_62 = V_329 ; V_62 < V_329 + F_277 ( V_329 ) ; V_62 ++ ) {
struct V_2 * V_103 ;
V_73 = 0 ;
F_116 (iter, memcg)
V_73 += F_71 ( V_103 , V_62 -> V_72 ) ;
F_278 ( V_325 , L_19 , V_62 -> V_328 , V_73 ) ;
F_72 (nid, N_MEMORY) {
V_73 = 0 ;
F_116 (iter, memcg)
V_73 += F_67 (
V_103 , V_24 , V_62 -> V_72 ) ;
F_278 ( V_325 , L_18 , V_24 , V_73 ) ;
}
F_279 ( V_325 , '\n' ) ;
}
return 0 ;
}
static int F_280 ( struct V_324 * V_325 , void * V_326 )
{
struct V_2 * V_3 = F_8 ( F_276 ( V_325 ) ) ;
unsigned long V_51 , V_122 ;
struct V_2 * V_331 ;
unsigned int V_113 ;
F_281 ( F_277 ( V_137 ) !=
V_135 ) ;
F_281 ( F_277 ( V_332 ) !=
V_333 ) ;
F_281 ( F_277 ( V_139 ) != V_138 ) ;
for ( V_113 = 0 ; V_113 < V_135 ; V_113 ++ ) {
if ( V_113 == V_136 && ! V_121 )
continue;
F_278 ( V_325 , L_20 , V_137 [ V_113 ] ,
F_58 ( V_3 , V_113 ) * V_254 ) ;
}
for ( V_113 = 0 ; V_113 < V_333 ; V_113 ++ )
F_278 ( V_325 , L_20 , V_332 [ V_113 ] ,
F_61 ( V_3 , V_113 ) ) ;
for ( V_113 = 0 ; V_113 < V_138 ; V_113 ++ )
F_278 ( V_325 , L_20 , V_139 [ V_113 ] ,
F_71 ( V_3 , F_70 ( V_113 ) ) * V_254 ) ;
V_51 = V_122 = V_320 ;
for ( V_331 = V_3 ; V_331 ; V_331 = F_32 ( V_331 ) ) {
V_51 = F_99 ( V_51 , V_331 -> V_51 . V_120 ) ;
V_122 = F_99 ( V_122 , V_331 -> V_122 . V_120 ) ;
}
F_278 ( V_325 , L_21 ,
( V_132 ) V_51 * V_254 ) ;
if ( V_121 )
F_278 ( V_325 , L_22 ,
( V_132 ) V_122 * V_254 ) ;
for ( V_113 = 0 ; V_113 < V_135 ; V_113 ++ ) {
unsigned long long V_60 = 0 ;
if ( V_113 == V_136 && ! V_121 )
continue;
F_116 (mi, memcg)
V_60 += F_58 ( V_331 , V_113 ) * V_254 ;
F_278 ( V_325 , L_23 , V_137 [ V_113 ] , V_60 ) ;
}
for ( V_113 = 0 ; V_113 < V_333 ; V_113 ++ ) {
unsigned long long V_60 = 0 ;
F_116 (mi, memcg)
V_60 += F_61 ( V_331 , V_113 ) ;
F_278 ( V_325 , L_23 ,
V_332 [ V_113 ] , V_60 ) ;
}
for ( V_113 = 0 ; V_113 < V_138 ; V_113 ++ ) {
unsigned long long V_60 = 0 ;
F_116 (mi, memcg)
V_60 += F_71 ( V_331 , F_70 ( V_113 ) ) * V_254 ;
F_278 ( V_325 , L_23 , V_139 [ V_113 ] , V_60 ) ;
}
#ifdef F_282
{
int V_24 , V_25 ;
struct V_22 * V_36 ;
struct V_334 * V_335 ;
unsigned long V_336 [ 2 ] = { 0 , 0 } ;
unsigned long V_337 [ 2 ] = { 0 , 0 } ;
F_283 (nid)
for ( V_25 = 0 ; V_25 < V_54 ; V_25 ++ ) {
V_36 = & V_3 -> V_26 [ V_24 ] -> V_27 [ V_25 ] ;
V_335 = & V_36 -> V_115 . V_338 ;
V_336 [ 0 ] += V_335 -> V_336 [ 0 ] ;
V_336 [ 1 ] += V_335 -> V_336 [ 1 ] ;
V_337 [ 0 ] += V_335 -> V_337 [ 0 ] ;
V_337 [ 1 ] += V_335 -> V_337 [ 1 ] ;
}
F_278 ( V_325 , L_24 , V_336 [ 0 ] ) ;
F_278 ( V_325 , L_25 , V_336 [ 1 ] ) ;
F_278 ( V_325 , L_26 , V_337 [ 0 ] ) ;
F_278 ( V_325 , L_27 , V_337 [ 1 ] ) ;
}
#endif
return 0 ;
}
static V_132 F_284 ( struct V_5 * V_7 ,
struct V_301 * V_302 )
{
struct V_2 * V_3 = F_8 ( V_7 ) ;
return F_120 ( V_3 ) ;
}
static int F_285 ( struct V_5 * V_7 ,
struct V_301 * V_302 , V_132 V_60 )
{
struct V_2 * V_3 = F_8 ( V_7 ) ;
if ( V_60 > 100 )
return - V_282 ;
if ( V_7 -> V_42 )
V_3 -> V_339 = V_60 ;
else
V_340 = V_60 ;
return 0 ;
}
static void F_286 ( struct V_2 * V_3 , bool V_306 )
{
struct V_341 * V_342 ;
unsigned long V_343 ;
int V_113 ;
F_12 () ;
if ( ! V_306 )
V_342 = F_82 ( V_3 -> V_344 . V_345 ) ;
else
V_342 = F_82 ( V_3 -> V_346 . V_345 ) ;
if ( ! V_342 )
goto V_126;
V_343 = F_257 ( V_3 , V_306 ) ;
V_113 = V_342 -> V_347 ;
for (; V_113 >= 0 && F_77 ( V_342 -> V_348 [ V_113 ] . V_349 > V_343 ) ; V_113 -- )
F_287 ( V_342 -> V_348 [ V_113 ] . V_350 , 1 ) ;
V_113 ++ ;
for (; V_113 < V_342 -> V_259 && F_77 ( V_342 -> V_348 [ V_113 ] . V_349 <= V_343 ) ; V_113 ++ )
F_287 ( V_342 -> V_348 [ V_113 ] . V_350 , 1 ) ;
V_342 -> V_347 = V_113 - 1 ;
V_126:
F_16 () ;
}
static void F_78 ( struct V_2 * V_3 )
{
while ( V_3 ) {
F_286 ( V_3 , false ) ;
if ( V_121 )
F_286 ( V_3 , true ) ;
V_3 = F_32 ( V_3 ) ;
}
}
static int F_288 ( const void * V_351 , const void * V_352 )
{
const struct F_78 * V_353 = V_351 ;
const struct F_78 * V_354 = V_352 ;
if ( V_353 -> V_349 > V_354 -> V_349 )
return 1 ;
if ( V_353 -> V_349 < V_354 -> V_349 )
return - 1 ;
return 0 ;
}
static int F_289 ( struct V_2 * V_3 )
{
struct V_355 * V_356 ;
F_101 ( & V_179 ) ;
F_290 (ev, &memcg->oom_notify, list)
F_287 ( V_356 -> V_350 , 1 ) ;
F_102 ( & V_179 ) ;
return 0 ;
}
static void F_161 ( struct V_2 * V_3 )
{
struct V_2 * V_103 ;
F_116 (iter, memcg)
F_289 ( V_103 ) ;
}
static int F_291 ( struct V_2 * V_3 ,
struct V_357 * V_350 , const char * args , enum V_358 type )
{
struct V_359 * V_344 ;
struct V_341 * V_360 ;
unsigned long V_349 ;
unsigned long V_343 ;
int V_113 , V_259 , V_118 ;
V_118 = F_269 ( args , L_12 , & V_349 ) ;
if ( V_118 )
return V_118 ;
F_110 ( & V_3 -> V_361 ) ;
if ( type == V_307 ) {
V_344 = & V_3 -> V_344 ;
V_343 = F_257 ( V_3 , false ) ;
} else if ( type == V_308 ) {
V_344 = & V_3 -> V_346 ;
V_343 = F_257 ( V_3 , true ) ;
} else
F_260 () ;
if ( V_344 -> V_345 )
F_286 ( V_3 , type == V_308 ) ;
V_259 = V_344 -> V_345 ? V_344 -> V_345 -> V_259 + 1 : 1 ;
V_360 = F_223 ( sizeof( * V_360 ) + V_259 * sizeof( struct F_78 ) ,
V_234 ) ;
if ( ! V_360 ) {
V_118 = - V_255 ;
goto V_126;
}
V_360 -> V_259 = V_259 ;
if ( V_344 -> V_345 ) {
memcpy ( V_360 -> V_348 , V_344 -> V_345 -> V_348 , ( V_259 - 1 ) *
sizeof( struct F_78 ) ) ;
}
V_360 -> V_348 [ V_259 - 1 ] . V_350 = V_350 ;
V_360 -> V_348 [ V_259 - 1 ] . V_349 = V_349 ;
F_292 ( V_360 -> V_348 , V_259 , sizeof( struct F_78 ) ,
F_288 , NULL ) ;
V_360 -> V_347 = - 1 ;
for ( V_113 = 0 ; V_113 < V_259 ; V_113 ++ ) {
if ( V_360 -> V_348 [ V_113 ] . V_349 <= V_343 ) {
++ V_360 -> V_347 ;
} else
break;
}
F_221 ( V_344 -> V_362 ) ;
V_344 -> V_362 = V_344 -> V_345 ;
F_293 ( V_344 -> V_345 , V_360 ) ;
F_294 () ;
V_126:
F_117 ( & V_3 -> V_361 ) ;
return V_118 ;
}
static int F_295 ( struct V_2 * V_3 ,
struct V_357 * V_350 , const char * args )
{
return F_291 ( V_3 , V_350 , args , V_307 ) ;
}
static int F_296 ( struct V_2 * V_3 ,
struct V_357 * V_350 , const char * args )
{
return F_291 ( V_3 , V_350 , args , V_308 ) ;
}
static void F_297 ( struct V_2 * V_3 ,
struct V_357 * V_350 , enum V_358 type )
{
struct V_359 * V_344 ;
struct V_341 * V_360 ;
unsigned long V_343 ;
int V_113 , V_363 , V_259 ;
F_110 ( & V_3 -> V_361 ) ;
if ( type == V_307 ) {
V_344 = & V_3 -> V_344 ;
V_343 = F_257 ( V_3 , false ) ;
} else if ( type == V_308 ) {
V_344 = & V_3 -> V_346 ;
V_343 = F_257 ( V_3 , true ) ;
} else
F_260 () ;
if ( ! V_344 -> V_345 )
goto V_126;
F_286 ( V_3 , type == V_308 ) ;
V_259 = 0 ;
for ( V_113 = 0 ; V_113 < V_344 -> V_345 -> V_259 ; V_113 ++ ) {
if ( V_344 -> V_345 -> V_348 [ V_113 ] . V_350 != V_350 )
V_259 ++ ;
}
V_360 = V_344 -> V_362 ;
if ( ! V_259 ) {
F_221 ( V_360 ) ;
V_360 = NULL ;
goto V_364;
}
V_360 -> V_259 = V_259 ;
V_360 -> V_347 = - 1 ;
for ( V_113 = 0 , V_363 = 0 ; V_113 < V_344 -> V_345 -> V_259 ; V_113 ++ ) {
if ( V_344 -> V_345 -> V_348 [ V_113 ] . V_350 == V_350 )
continue;
V_360 -> V_348 [ V_363 ] = V_344 -> V_345 -> V_348 [ V_113 ] ;
if ( V_360 -> V_348 [ V_363 ] . V_349 <= V_343 ) {
++ V_360 -> V_347 ;
}
V_363 ++ ;
}
V_364:
V_344 -> V_362 = V_344 -> V_345 ;
if ( ! V_360 ) {
F_221 ( V_344 -> V_362 ) ;
V_344 -> V_362 = NULL ;
}
F_293 ( V_344 -> V_345 , V_360 ) ;
F_294 () ;
V_126:
F_117 ( & V_3 -> V_361 ) ;
}
static void F_298 ( struct V_2 * V_3 ,
struct V_357 * V_350 )
{
return F_297 ( V_3 , V_350 , V_307 ) ;
}
static void F_299 ( struct V_2 * V_3 ,
struct V_357 * V_350 )
{
return F_297 ( V_3 , V_350 , V_308 ) ;
}
static int F_300 ( struct V_2 * V_3 ,
struct V_357 * V_350 , const char * args )
{
struct V_355 * V_365 ;
V_365 = F_223 ( sizeof( * V_365 ) , V_234 ) ;
if ( ! V_365 )
return - V_255 ;
F_101 ( & V_179 ) ;
V_365 -> V_350 = V_350 ;
F_301 ( & V_365 -> V_366 , & V_3 -> V_367 ) ;
if ( V_3 -> V_182 )
F_287 ( V_350 , 1 ) ;
F_102 ( & V_179 ) ;
return 0 ;
}
static void F_302 ( struct V_2 * V_3 ,
struct V_357 * V_350 )
{
struct V_355 * V_356 , * V_368 ;
F_101 ( & V_179 ) ;
F_303 (ev, tmp, &memcg->oom_notify, list) {
if ( V_356 -> V_350 == V_350 ) {
F_304 ( & V_356 -> V_366 ) ;
F_221 ( V_356 ) ;
}
}
F_102 ( & V_179 ) ;
}
static int F_305 ( struct V_324 * V_369 , void * V_326 )
{
struct V_2 * V_3 = F_8 ( F_276 ( V_369 ) ) ;
F_278 ( V_369 , L_28 , V_3 -> V_205 ) ;
F_278 ( V_369 , L_29 , ( bool ) V_3 -> V_182 ) ;
return 0 ;
}
static int F_306 ( struct V_5 * V_7 ,
struct V_301 * V_302 , V_132 V_60 )
{
struct V_2 * V_3 = F_8 ( V_7 ) ;
if ( ! V_7 -> V_42 || ! ( ( V_60 == 0 ) || ( V_60 == 1 ) ) )
return - V_282 ;
V_3 -> V_205 = V_60 ;
if ( ! V_60 )
F_156 ( V_3 ) ;
return 0 ;
}
static int F_307 ( struct V_2 * V_3 , struct V_370 * V_371 )
{
int V_118 ;
V_118 = F_266 ( V_3 ) ;
if ( V_118 )
return V_118 ;
return F_308 ( V_3 , V_371 ) ;
}
static void F_309 ( struct V_2 * V_3 )
{
struct V_5 * V_7 ;
struct V_2 * V_42 , * V_372 ;
int V_273 ;
if ( ! V_3 -> V_318 )
return;
V_3 -> V_318 = false ;
F_310 ( V_3 ) ;
V_273 = V_3 -> V_273 ;
F_10 ( V_273 < 0 ) ;
V_42 = F_32 ( V_3 ) ;
if ( ! V_42 )
V_42 = V_4 ;
F_311 (css, &memcg->css) {
V_372 = F_8 ( V_7 ) ;
F_10 ( V_372 -> V_273 != V_273 ) ;
V_372 -> V_273 = V_42 -> V_273 ;
if ( ! V_3 -> V_105 )
break;
}
F_312 ( V_273 , V_42 -> V_273 ) ;
F_218 ( V_273 ) ;
}
static void F_313 ( struct V_2 * V_3 )
{
if ( V_3 -> V_317 ) {
F_314 ( V_3 ) ;
F_315 ( & V_319 ) ;
F_18 ( F_49 ( & V_3 -> V_134 ) ) ;
}
F_316 ( V_3 ) ;
}
static int F_307 ( struct V_2 * V_3 , struct V_370 * V_371 )
{
return 0 ;
}
static void F_309 ( struct V_2 * V_3 )
{
}
static void F_313 ( struct V_2 * V_3 )
{
}
struct V_373 * F_317 ( struct V_2 * V_3 )
{
return & V_3 -> V_374 ;
}
static int F_318 ( struct V_2 * V_3 , T_3 V_275 )
{
return F_319 ( & V_3 -> V_375 , V_275 ) ;
}
static void F_320 ( struct V_2 * V_3 )
{
F_321 ( & V_3 -> V_375 ) ;
}
static void F_322 ( struct V_2 * V_3 )
{
F_323 ( & V_3 -> V_375 ) ;
}
struct V_376 * F_324 ( struct V_377 * V_378 )
{
struct V_2 * V_3 = F_8 ( V_378 -> V_379 ) ;
if ( ! V_3 -> V_7 . V_42 )
return NULL ;
return & V_3 -> V_375 ;
}
void F_325 ( struct V_377 * V_378 , unsigned long * V_380 ,
unsigned long * V_381 , unsigned long * V_382 ,
unsigned long * V_383 )
{
struct V_2 * V_3 = F_8 ( V_378 -> V_379 ) ;
struct V_2 * V_42 ;
* V_382 = F_58 ( V_3 , V_384 ) ;
* V_383 = F_58 ( V_3 , V_385 ) ;
* V_380 = F_71 ( V_3 , ( 1 << V_386 ) |
( 1 << V_387 ) ) ;
* V_381 = V_320 ;
while ( ( V_42 = F_32 ( V_3 ) ) ) {
unsigned long V_388 = F_99 ( V_3 -> V_51 . V_120 , V_3 -> V_232 ) ;
unsigned long V_389 = F_49 ( & V_3 -> V_51 ) ;
* V_381 = F_99 ( * V_381 , V_388 - F_99 ( V_388 , V_389 ) ) ;
V_3 = V_42 ;
}
}
static int F_318 ( struct V_2 * V_3 , T_3 V_275 )
{
return 0 ;
}
static void F_320 ( struct V_2 * V_3 )
{
}
static void F_322 ( struct V_2 * V_3 )
{
}
static void F_326 ( struct V_217 * V_222 )
{
struct V_390 * V_365 =
F_3 ( V_222 , struct V_390 , remove ) ;
struct V_2 * V_3 = V_365 -> V_3 ;
F_327 ( V_365 -> V_391 , & V_365 -> V_128 ) ;
V_365 -> V_392 ( V_3 , V_365 -> V_350 ) ;
F_287 ( V_365 -> V_350 , 1 ) ;
F_328 ( V_365 -> V_350 ) ;
F_221 ( V_365 ) ;
F_19 ( & V_3 -> V_7 ) ;
}
static int F_329 ( T_4 * V_128 , unsigned V_183 ,
int V_184 , void * V_393 )
{
struct V_390 * V_365 =
F_3 ( V_128 , struct V_390 , V_128 ) ;
struct V_2 * V_3 = V_365 -> V_3 ;
unsigned long V_19 = ( unsigned long ) V_393 ;
if ( V_19 & V_394 ) {
F_101 ( & V_3 -> V_395 ) ;
if ( ! F_330 ( & V_365 -> V_366 ) ) {
F_331 ( & V_365 -> V_366 ) ;
F_225 ( & V_365 -> remove ) ;
}
F_102 ( & V_3 -> V_395 ) ;
}
return 0 ;
}
static void F_332 ( struct V_396 * V_396 ,
T_9 * V_391 , T_10 * V_397 )
{
struct V_390 * V_365 =
F_3 ( V_397 , struct V_390 , V_397 ) ;
V_365 -> V_391 = V_391 ;
F_333 ( V_391 , & V_365 -> V_128 ) ;
}
static T_6 F_334 ( struct V_296 * V_297 ,
char * V_298 , T_7 V_299 , T_8 V_300 )
{
struct V_5 * V_7 = F_253 ( V_297 ) ;
struct V_2 * V_3 = F_8 ( V_7 ) ;
struct V_390 * V_365 ;
struct V_5 * V_398 ;
unsigned int V_399 , V_400 ;
struct V_401 V_402 ;
struct V_401 V_403 ;
const char * V_328 ;
char * V_404 ;
int V_118 ;
V_298 = F_268 ( V_298 ) ;
V_399 = F_335 ( V_298 , & V_404 , 10 ) ;
if ( * V_404 != ' ' )
return - V_282 ;
V_298 = V_404 + 1 ;
V_400 = F_335 ( V_298 , & V_404 , 10 ) ;
if ( ( * V_404 != ' ' ) && ( * V_404 != '\0' ) )
return - V_282 ;
V_298 = V_404 + 1 ;
V_365 = F_336 ( sizeof( * V_365 ) , V_234 ) ;
if ( ! V_365 )
return - V_255 ;
V_365 -> V_3 = V_3 ;
F_160 ( & V_365 -> V_366 ) ;
F_337 ( & V_365 -> V_397 , F_332 ) ;
F_338 ( & V_365 -> V_128 , F_329 ) ;
F_224 ( & V_365 -> remove , F_326 ) ;
V_402 = F_339 ( V_399 ) ;
if ( ! V_402 . V_396 ) {
V_118 = - V_405 ;
goto V_406;
}
V_365 -> V_350 = F_340 ( V_402 . V_396 ) ;
if ( F_341 ( V_365 -> V_350 ) ) {
V_118 = F_342 ( V_365 -> V_350 ) ;
goto V_407;
}
V_403 = F_339 ( V_400 ) ;
if ( ! V_403 . V_396 ) {
V_118 = - V_405 ;
goto V_408;
}
V_118 = F_343 ( F_344 ( V_403 . V_396 ) , V_409 ) ;
if ( V_118 < 0 )
goto V_410;
V_328 = V_403 . V_396 -> V_411 . V_412 -> V_413 . V_328 ;
if ( ! strcmp ( V_328 , L_30 ) ) {
V_365 -> V_414 = F_295 ;
V_365 -> V_392 = F_298 ;
} else if ( ! strcmp ( V_328 , L_31 ) ) {
V_365 -> V_414 = F_300 ;
V_365 -> V_392 = F_302 ;
} else if ( ! strcmp ( V_328 , L_32 ) ) {
V_365 -> V_414 = V_415 ;
V_365 -> V_392 = V_416 ;
} else if ( ! strcmp ( V_328 , L_33 ) ) {
V_365 -> V_414 = F_296 ;
V_365 -> V_392 = F_299 ;
} else {
V_118 = - V_282 ;
goto V_410;
}
V_398 = F_345 ( V_403 . V_396 -> V_411 . V_412 -> V_417 ,
& V_9 ) ;
V_118 = - V_282 ;
if ( F_341 ( V_398 ) )
goto V_410;
if ( V_398 != V_7 ) {
F_19 ( V_398 ) ;
goto V_410;
}
V_118 = V_365 -> V_414 ( V_3 , V_365 -> V_350 , V_298 ) ;
if ( V_118 )
goto V_418;
V_402 . V_396 -> V_419 -> V_420 ( V_402 . V_396 , & V_365 -> V_397 ) ;
F_101 ( & V_3 -> V_395 ) ;
F_301 ( & V_365 -> V_366 , & V_3 -> V_421 ) ;
F_102 ( & V_3 -> V_395 ) ;
F_346 ( V_403 ) ;
F_346 ( V_402 ) ;
return V_299 ;
V_418:
F_19 ( V_7 ) ;
V_410:
F_346 ( V_403 ) ;
V_408:
F_328 ( V_365 -> V_350 ) ;
V_407:
F_346 ( V_402 ) ;
V_406:
F_221 ( V_365 ) ;
return V_118 ;
}
static int F_347 ( struct V_2 * V_3 , int V_169 )
{
struct V_422 * V_423 ;
struct V_22 * V_36 ;
int V_23 , V_368 = V_169 ;
if ( ! F_348 ( V_169 , V_424 ) )
V_368 = - 1 ;
V_423 = F_349 ( sizeof( * V_423 ) , V_234 , V_368 ) ;
if ( ! V_423 )
return 1 ;
for ( V_23 = 0 ; V_23 < V_54 ; V_23 ++ ) {
V_36 = & V_423 -> V_27 [ V_23 ] ;
F_350 ( & V_36 -> V_115 ) ;
V_36 -> V_45 = 0 ;
V_36 -> V_44 = false ;
V_36 -> V_3 = V_3 ;
}
V_3 -> V_26 [ V_169 ] = V_423 ;
return 0 ;
}
static void F_351 ( struct V_2 * V_3 , int V_169 )
{
F_221 ( V_3 -> V_26 [ V_169 ] ) ;
}
static struct V_2 * F_352 ( void )
{
struct V_2 * V_3 ;
T_7 V_259 ;
V_259 = sizeof( struct V_2 ) ;
V_259 += V_74 * sizeof( struct V_422 * ) ;
V_3 = F_336 ( V_259 , V_234 ) ;
if ( ! V_3 )
return NULL ;
V_3 -> V_62 = F_353 ( struct V_425 ) ;
if ( ! V_3 -> V_62 )
goto V_426;
if ( F_318 ( V_3 , V_234 ) )
goto V_427;
return V_3 ;
V_427:
F_354 ( V_3 -> V_62 ) ;
V_426:
F_221 ( V_3 ) ;
return NULL ;
}
static void F_355 ( struct V_2 * V_3 )
{
int V_169 ;
F_51 ( V_3 ) ;
F_52 (node)
F_351 ( V_3 , V_169 ) ;
F_354 ( V_3 -> V_62 ) ;
F_320 ( V_3 ) ;
F_221 ( V_3 ) ;
}
struct V_2 * F_32 ( struct V_2 * V_3 )
{
if ( ! V_3 -> V_51 . V_42 )
return NULL ;
return F_191 ( V_3 -> V_51 . V_42 , V_51 ) ;
}
static struct V_5 * T_11
F_356 ( struct V_5 * V_428 )
{
struct V_2 * V_3 ;
long error = - V_255 ;
int V_169 ;
V_3 = F_352 () ;
if ( ! V_3 )
return F_357 ( error ) ;
F_52 (node)
if ( F_347 ( V_3 , V_169 ) )
goto V_429;
if ( V_428 == NULL ) {
V_4 = V_3 ;
V_430 = & V_3 -> V_7 ;
F_358 ( & V_3 -> V_51 , NULL ) ;
V_3 -> V_232 = V_320 ;
V_3 -> V_52 = V_320 ;
F_358 ( & V_3 -> V_122 , NULL ) ;
F_358 ( & V_3 -> V_134 , NULL ) ;
}
V_3 -> V_170 = V_90 ;
F_160 ( & V_3 -> V_367 ) ;
V_3 -> V_321 = 0 ;
F_359 ( & V_3 -> V_361 ) ;
F_360 ( & V_3 -> V_208 ) ;
F_361 ( & V_3 -> V_1 ) ;
F_160 ( & V_3 -> V_421 ) ;
F_360 ( & V_3 -> V_395 ) ;
#ifdef F_362
V_3 -> V_273 = - 1 ;
#endif
#ifdef F_363
F_160 ( & V_3 -> V_374 ) ;
#endif
return & V_3 -> V_7 ;
V_429:
F_355 ( V_3 ) ;
return F_357 ( error ) ;
}
static int
F_364 ( struct V_5 * V_7 )
{
struct V_2 * V_3 = F_8 ( V_7 ) ;
struct V_2 * V_42 = F_8 ( V_7 -> V_42 ) ;
int V_118 ;
if ( V_7 -> V_8 > V_431 )
return - V_432 ;
if ( ! V_42 )
return 0 ;
F_110 ( & V_292 ) ;
V_3 -> V_105 = V_42 -> V_105 ;
V_3 -> V_205 = V_42 -> V_205 ;
V_3 -> V_339 = F_120 ( V_42 ) ;
if ( V_42 -> V_105 ) {
F_358 ( & V_3 -> V_51 , & V_42 -> V_51 ) ;
V_3 -> V_232 = V_320 ;
V_3 -> V_52 = V_320 ;
F_358 ( & V_3 -> V_122 , & V_42 -> V_122 ) ;
F_358 ( & V_3 -> V_134 , & V_42 -> V_134 ) ;
} else {
F_358 ( & V_3 -> V_51 , NULL ) ;
V_3 -> V_232 = V_320 ;
V_3 -> V_52 = V_320 ;
F_358 ( & V_3 -> V_122 , NULL ) ;
F_358 ( & V_3 -> V_134 , NULL ) ;
if ( V_42 != V_4 )
V_9 . V_433 = true ;
}
F_117 ( & V_292 ) ;
V_118 = F_307 ( V_3 , & V_9 ) ;
if ( V_118 )
return V_118 ;
F_365 ( & V_3 -> V_111 , 1 ) ;
return 0 ;
}
static void F_366 ( struct V_5 * V_7 )
{
struct V_2 * V_3 = F_8 ( V_7 ) ;
struct V_390 * V_365 , * V_368 ;
F_101 ( & V_3 -> V_395 ) ;
F_303 (event, tmp, &memcg->event_list, list) {
F_331 ( & V_365 -> V_366 ) ;
F_225 ( & V_365 -> remove ) ;
}
F_102 ( & V_3 -> V_395 ) ;
F_367 ( & V_3 -> V_1 ) ;
F_309 ( V_3 ) ;
F_368 ( V_3 ) ;
}
static void F_369 ( struct V_5 * V_7 )
{
struct V_2 * V_3 = F_8 ( V_7 ) ;
F_90 ( V_3 ) ;
}
static void F_370 ( struct V_5 * V_7 )
{
struct V_2 * V_3 = F_8 ( V_7 ) ;
F_313 ( V_3 ) ;
F_355 ( V_3 ) ;
}
static void F_371 ( struct V_5 * V_7 )
{
struct V_2 * V_3 = F_8 ( V_7 ) ;
F_241 ( V_3 , V_320 ) ;
F_244 ( V_3 , V_320 ) ;
F_265 ( V_3 , V_320 ) ;
V_3 -> V_434 = 0 ;
V_3 -> V_232 = V_320 ;
V_3 -> V_52 = V_320 ;
F_322 ( V_3 ) ;
}
static int F_372 ( unsigned long V_63 )
{
int V_118 ;
V_118 = F_188 ( V_125 . V_124 , V_234 & ~ V_435 , V_63 ) ;
if ( ! V_118 ) {
V_125 . V_436 += V_63 ;
return V_118 ;
}
while ( V_63 -- ) {
V_118 = F_188 ( V_125 . V_124 , V_234 & ~ V_250 , 1 ) ;
if ( V_118 )
return V_118 ;
V_125 . V_436 ++ ;
F_373 () ;
}
return 0 ;
}
static struct V_28 * F_374 ( struct V_437 * V_438 ,
unsigned long V_439 , T_12 V_440 )
{
struct V_28 * V_28 = F_375 ( V_438 , V_439 , V_440 ) ;
if ( ! V_28 || ! F_376 ( V_28 ) )
return NULL ;
if ( F_63 ( V_28 ) ) {
if ( ! ( V_125 . V_19 & V_441 ) )
return NULL ;
} else {
if ( ! ( V_125 . V_19 & V_442 ) )
return NULL ;
}
if ( ! F_377 ( V_28 ) )
return NULL ;
return V_28 ;
}
static struct V_28 * F_378 ( struct V_437 * V_438 ,
unsigned long V_439 , T_12 V_440 , T_5 * V_279 )
{
struct V_28 * V_28 = NULL ;
T_5 V_443 = F_379 ( V_440 ) ;
if ( ! ( V_125 . V_19 & V_441 ) || F_380 ( V_443 ) )
return NULL ;
V_28 = F_381 ( F_382 ( V_443 ) , V_443 . V_60 ) ;
if ( V_121 )
V_279 -> V_60 = V_443 . V_60 ;
return V_28 ;
}
static struct V_28 * F_378 ( struct V_437 * V_438 ,
unsigned long V_439 , T_12 V_440 , T_5 * V_279 )
{
return NULL ;
}
static struct V_28 * F_383 ( struct V_437 * V_438 ,
unsigned long V_439 , T_12 V_440 , T_5 * V_279 )
{
struct V_28 * V_28 = NULL ;
struct V_444 * V_445 ;
T_13 V_446 ;
if ( ! V_438 -> V_447 )
return NULL ;
if ( ! ( V_125 . V_19 & V_442 ) )
return NULL ;
V_445 = V_438 -> V_447 -> V_448 ;
V_446 = F_384 ( V_438 , V_439 ) ;
#ifdef F_385
if ( F_386 ( V_445 ) ) {
V_28 = F_387 ( V_445 , V_446 ) ;
if ( F_388 ( V_28 ) ) {
T_5 V_449 = F_389 ( V_28 ) ;
if ( V_121 )
* V_279 = V_449 ;
V_28 = F_381 ( F_382 ( V_449 ) , V_449 . V_60 ) ;
}
} else
V_28 = F_381 ( V_445 , V_446 ) ;
#else
V_28 = F_381 ( V_445 , V_446 ) ;
#endif
return V_28 ;
}
static int F_390 ( struct V_28 * V_28 ,
unsigned int V_50 ,
struct V_2 * V_123 ,
struct V_2 * V_124 )
{
unsigned long V_19 ;
int V_118 ;
bool V_450 ;
F_68 ( V_123 == V_124 ) ;
F_207 ( F_202 ( V_28 ) , V_28 ) ;
V_118 = - V_305 ;
if ( V_50 > 1 && ! F_65 ( V_28 ) )
goto V_106;
if ( ! F_391 ( V_28 ) )
goto V_106;
V_118 = - V_282 ;
if ( V_28 -> V_2 != V_123 )
goto V_109;
V_450 = F_63 ( V_28 ) ;
F_46 ( & V_123 -> V_208 , V_19 ) ;
if ( ! V_450 && F_376 ( V_28 ) ) {
F_236 ( V_123 -> V_62 -> V_63 [ V_451 ] ,
V_50 ) ;
F_64 ( V_124 -> V_62 -> V_63 [ V_451 ] ,
V_50 ) ;
}
if ( ! V_450 && F_392 ( V_28 ) ) {
struct V_444 * V_445 = F_393 ( V_28 ) ;
if ( F_394 ( V_445 ) ) {
F_236 ( V_123 -> V_62 -> V_63 [ V_384 ] ,
V_50 ) ;
F_64 ( V_124 -> V_62 -> V_63 [ V_384 ] ,
V_50 ) ;
}
}
if ( F_395 ( V_28 ) ) {
F_236 ( V_123 -> V_62 -> V_63 [ V_385 ] ,
V_50 ) ;
F_64 ( V_124 -> V_62 -> V_63 [ V_385 ] ,
V_50 ) ;
}
V_28 -> V_2 = V_124 ;
F_47 ( & V_123 -> V_208 , V_19 ) ;
V_118 = 0 ;
F_396 () ;
F_62 ( V_124 , V_28 , V_50 ) ;
F_76 ( V_124 , V_28 ) ;
F_62 ( V_123 , V_28 , - V_50 ) ;
F_76 ( V_123 , V_28 ) ;
F_397 () ;
V_109:
F_398 ( V_28 ) ;
V_106:
return V_118 ;
}
static enum V_452 F_399 ( struct V_437 * V_438 ,
unsigned long V_439 , T_12 V_440 , union V_453 * V_79 )
{
struct V_28 * V_28 = NULL ;
enum V_452 V_118 = V_454 ;
T_5 V_443 = { . V_60 = 0 } ;
if ( F_400 ( V_440 ) )
V_28 = F_374 ( V_438 , V_439 , V_440 ) ;
else if ( F_401 ( V_440 ) )
V_28 = F_378 ( V_438 , V_439 , V_440 , & V_443 ) ;
else if ( F_402 ( V_440 ) )
V_28 = F_383 ( V_438 , V_439 , V_440 , & V_443 ) ;
if ( ! V_28 && ! V_443 . V_60 )
return V_118 ;
if ( V_28 ) {
if ( V_28 -> V_2 == V_125 . V_123 ) {
V_118 = V_455 ;
if ( V_79 )
V_79 -> V_28 = V_28 ;
}
if ( ! V_118 || ! V_79 )
F_403 ( V_28 ) ;
}
if ( V_443 . V_60 && ! V_118 &&
F_5 ( V_125 . V_123 ) == F_404 ( V_443 ) ) {
V_118 = V_456 ;
if ( V_79 )
V_79 -> V_443 = V_443 ;
}
return V_118 ;
}
static enum V_452 F_405 ( struct V_437 * V_438 ,
unsigned long V_439 , T_14 V_457 , union V_453 * V_79 )
{
struct V_28 * V_28 = NULL ;
enum V_452 V_118 = V_454 ;
V_28 = F_406 ( V_457 ) ;
F_207 ( ! V_28 || ! F_407 ( V_28 ) , V_28 ) ;
if ( ! ( V_125 . V_19 & V_441 ) )
return V_118 ;
if ( V_28 -> V_2 == V_125 . V_123 ) {
V_118 = V_455 ;
if ( V_79 ) {
F_408 ( V_28 ) ;
V_79 -> V_28 = V_28 ;
}
}
return V_118 ;
}
static inline enum V_452 F_405 ( struct V_437 * V_438 ,
unsigned long V_439 , T_14 V_457 , union V_453 * V_79 )
{
return V_454 ;
}
static int F_409 ( T_14 * V_457 ,
unsigned long V_439 , unsigned long V_458 ,
struct V_459 * V_460 )
{
struct V_437 * V_438 = V_460 -> V_438 ;
T_12 * V_461 ;
T_15 * V_462 ;
if ( F_410 ( V_457 , V_438 , & V_462 ) == 1 ) {
if ( F_405 ( V_438 , V_439 , * V_457 , NULL ) == V_455 )
V_125 . V_436 += V_277 ;
F_102 ( V_462 ) ;
return 0 ;
}
if ( F_411 ( V_457 ) )
return 0 ;
V_461 = F_412 ( V_438 -> V_463 , V_457 , V_439 , & V_462 ) ;
for (; V_439 != V_458 ; V_461 ++ , V_439 += V_254 )
if ( F_399 ( V_438 , V_439 , * V_461 , NULL ) )
V_125 . V_436 ++ ;
F_413 ( V_461 - 1 , V_462 ) ;
F_373 () ;
return 0 ;
}
static unsigned long F_414 ( struct V_94 * V_95 )
{
unsigned long V_436 ;
struct V_459 V_464 = {
. V_465 = F_409 ,
. V_95 = V_95 ,
} ;
F_22 ( & V_95 -> V_466 ) ;
F_415 ( 0 , ~ 0UL , & V_464 ) ;
F_24 ( & V_95 -> V_466 ) ;
V_436 = V_125 . V_436 ;
V_125 . V_436 = 0 ;
return V_436 ;
}
static int F_416 ( struct V_94 * V_95 )
{
unsigned long V_436 = F_414 ( V_95 ) ;
F_68 ( V_125 . V_127 ) ;
V_125 . V_127 = V_17 ;
return F_372 ( V_436 ) ;
}
static void F_417 ( void )
{
struct V_2 * V_123 = V_125 . V_123 ;
struct V_2 * V_124 = V_125 . V_124 ;
if ( V_125 . V_436 ) {
F_199 ( V_125 . V_124 , V_125 . V_436 ) ;
V_125 . V_436 = 0 ;
}
if ( V_125 . V_467 ) {
F_199 ( V_125 . V_123 , V_125 . V_467 ) ;
V_125 . V_467 = 0 ;
}
if ( V_125 . V_468 ) {
if ( ! F_4 ( V_125 . V_123 ) )
F_168 ( & V_125 . V_123 -> V_122 , V_125 . V_468 ) ;
if ( ! F_4 ( V_125 . V_124 ) )
F_168 ( & V_125 . V_124 -> V_51 , V_125 . V_468 ) ;
F_169 ( & V_125 . V_123 -> V_7 , V_125 . V_468 ) ;
V_125 . V_468 = 0 ;
}
F_156 ( V_123 ) ;
F_156 ( V_124 ) ;
F_418 ( & V_125 . V_129 ) ;
}
static void F_419 ( void )
{
V_125 . V_127 = NULL ;
F_417 () ;
F_101 ( & V_125 . V_49 ) ;
V_125 . V_123 = NULL ;
V_125 . V_124 = NULL ;
F_102 ( & V_125 . V_49 ) ;
}
static int F_420 ( struct V_469 * V_470 )
{
struct V_5 * V_7 ;
struct V_2 * V_3 ;
struct V_2 * V_123 ;
struct V_92 * V_471 , * V_40 ;
struct V_94 * V_95 ;
unsigned long V_472 ;
int V_118 = 0 ;
if ( F_29 ( V_9 ) )
return 0 ;
V_40 = NULL ;
F_421 (leader, css, tset) {
F_422 ( V_40 ) ;
V_40 = V_471 ;
V_3 = F_8 ( V_7 ) ;
}
if ( ! V_40 )
return 0 ;
V_472 = F_31 ( V_3 -> V_321 ) ;
if ( ! V_472 )
return 0 ;
V_123 = F_13 ( V_40 ) ;
F_68 ( V_123 == V_3 ) ;
V_95 = F_423 ( V_40 ) ;
if ( ! V_95 )
return 0 ;
if ( V_95 -> V_96 == V_40 ) {
F_68 ( V_125 . V_123 ) ;
F_68 ( V_125 . V_124 ) ;
F_68 ( V_125 . V_436 ) ;
F_68 ( V_125 . V_467 ) ;
F_68 ( V_125 . V_468 ) ;
F_101 ( & V_125 . V_49 ) ;
V_125 . V_123 = V_123 ;
V_125 . V_124 = V_3 ;
V_125 . V_19 = V_472 ;
F_102 ( & V_125 . V_49 ) ;
V_118 = F_416 ( V_95 ) ;
if ( V_118 )
F_419 () ;
}
F_424 ( V_95 ) ;
return V_118 ;
}
static void F_425 ( struct V_469 * V_470 )
{
if ( V_125 . V_124 )
F_419 () ;
}
static int F_426 ( T_14 * V_457 ,
unsigned long V_439 , unsigned long V_458 ,
struct V_459 * V_460 )
{
int V_118 = 0 ;
struct V_437 * V_438 = V_460 -> V_438 ;
T_12 * V_461 ;
T_15 * V_462 ;
enum V_452 V_473 ;
union V_453 V_79 ;
struct V_28 * V_28 ;
if ( F_410 ( V_457 , V_438 , & V_462 ) == 1 ) {
if ( V_125 . V_436 < V_277 ) {
F_102 ( V_462 ) ;
return 0 ;
}
V_473 = F_405 ( V_438 , V_439 , * V_457 , & V_79 ) ;
if ( V_473 == V_455 ) {
V_28 = V_79 . V_28 ;
if ( ! F_427 ( V_28 ) ) {
if ( ! F_390 ( V_28 , V_277 ,
V_125 . V_123 , V_125 . V_124 ) ) {
V_125 . V_436 -= V_277 ;
V_125 . V_467 += V_277 ;
}
F_428 ( V_28 ) ;
}
F_403 ( V_28 ) ;
}
F_102 ( V_462 ) ;
return 0 ;
}
if ( F_411 ( V_457 ) )
return 0 ;
V_56:
V_461 = F_412 ( V_438 -> V_463 , V_457 , V_439 , & V_462 ) ;
for (; V_439 != V_458 ; V_439 += V_254 ) {
T_12 V_440 = * ( V_461 ++ ) ;
T_5 V_443 ;
if ( ! V_125 . V_436 )
break;
switch ( F_399 ( V_438 , V_439 , V_440 , & V_79 ) ) {
case V_455 :
V_28 = V_79 . V_28 ;
if ( F_427 ( V_28 ) )
goto V_474;
if ( ! F_390 ( V_28 , 1 , V_125 . V_123 , V_125 . V_124 ) ) {
V_125 . V_436 -- ;
V_125 . V_467 ++ ;
}
F_428 ( V_28 ) ;
V_474:
F_403 ( V_28 ) ;
break;
case V_456 :
V_443 = V_79 . V_443 ;
if ( ! F_239 ( V_443 , V_125 . V_123 , V_125 . V_124 ) ) {
V_125 . V_436 -- ;
V_125 . V_468 ++ ;
}
break;
default:
break;
}
}
F_413 ( V_461 - 1 , V_462 ) ;
F_373 () ;
if ( V_439 != V_458 ) {
V_118 = F_372 ( 1 ) ;
if ( ! V_118 )
goto V_56;
}
return V_118 ;
}
static void F_429 ( struct V_94 * V_95 )
{
struct V_459 V_475 = {
. V_465 = F_426 ,
. V_95 = V_95 ,
} ;
F_250 () ;
F_79 ( & V_125 . V_123 -> V_207 ) ;
F_294 () ;
V_56:
if ( F_77 ( ! F_430 ( & V_95 -> V_466 ) ) ) {
F_417 () ;
F_373 () ;
goto V_56;
}
F_415 ( 0 , ~ 0UL , & V_475 ) ;
F_24 ( & V_95 -> V_466 ) ;
F_431 ( & V_125 . V_123 -> V_207 ) ;
}
static void F_432 ( struct V_469 * V_470 )
{
struct V_5 * V_7 ;
struct V_92 * V_40 = F_433 ( V_470 , & V_7 ) ;
struct V_94 * V_95 = F_423 ( V_40 ) ;
if ( V_95 ) {
if ( V_125 . V_124 )
F_429 ( V_95 ) ;
F_424 ( V_95 ) ;
}
if ( V_125 . V_124 )
F_419 () ;
}
static int F_420 ( struct V_469 * V_470 )
{
return 0 ;
}
static void F_425 ( struct V_469 * V_470 )
{
}
static void F_432 ( struct V_469 * V_470 )
{
}
static void F_434 ( struct V_5 * V_476 )
{
if ( F_29 ( V_9 ) )
V_4 -> V_105 = true ;
else
V_4 -> V_105 = false ;
}
static V_132 F_435 ( struct V_5 * V_7 ,
struct V_301 * V_302 )
{
struct V_2 * V_3 = F_8 ( V_7 ) ;
return ( V_132 ) F_49 ( & V_3 -> V_51 ) * V_254 ;
}
static int F_436 ( struct V_324 * V_325 , void * V_326 )
{
struct V_2 * V_3 = F_8 ( F_276 ( V_325 ) ) ;
unsigned long V_434 = F_31 ( V_3 -> V_434 ) ;
if ( V_434 == V_320 )
F_437 ( V_325 , L_34 ) ;
else
F_278 ( V_325 , L_35 , ( V_132 ) V_434 * V_254 ) ;
return 0 ;
}
static T_6 F_438 ( struct V_296 * V_297 ,
char * V_298 , T_7 V_299 , T_8 V_300 )
{
struct V_2 * V_3 = F_8 ( F_253 ( V_297 ) ) ;
unsigned long V_434 ;
int V_260 ;
V_298 = F_268 ( V_298 ) ;
V_260 = F_269 ( V_298 , L_36 , & V_434 ) ;
if ( V_260 )
return V_260 ;
V_3 -> V_434 = V_434 ;
return V_299 ;
}
static int F_439 ( struct V_324 * V_325 , void * V_326 )
{
struct V_2 * V_3 = F_8 ( F_276 ( V_325 ) ) ;
unsigned long V_232 = F_31 ( V_3 -> V_232 ) ;
if ( V_232 == V_320 )
F_437 ( V_325 , L_34 ) ;
else
F_278 ( V_325 , L_35 , ( V_132 ) V_232 * V_254 ) ;
return 0 ;
}
static T_6 F_440 ( struct V_296 * V_297 ,
char * V_298 , T_7 V_299 , T_8 V_300 )
{
struct V_2 * V_3 = F_8 ( F_253 ( V_297 ) ) ;
unsigned long V_232 ;
int V_260 ;
V_298 = F_268 ( V_298 ) ;
V_260 = F_269 ( V_298 , L_36 , & V_232 ) ;
if ( V_260 )
return V_260 ;
V_3 -> V_232 = V_232 ;
F_322 ( V_3 ) ;
return V_299 ;
}
static int F_441 ( struct V_324 * V_325 , void * V_326 )
{
struct V_2 * V_3 = F_8 ( F_276 ( V_325 ) ) ;
unsigned long F_189 = F_31 ( V_3 -> V_51 . V_120 ) ;
if ( F_189 == V_320 )
F_437 ( V_325 , L_34 ) ;
else
F_278 ( V_325 , L_35 , ( V_132 ) F_189 * V_254 ) ;
return 0 ;
}
static T_6 F_442 ( struct V_296 * V_297 ,
char * V_298 , T_7 V_299 , T_8 V_300 )
{
struct V_2 * V_3 = F_8 ( F_253 ( V_297 ) ) ;
unsigned long F_189 ;
int V_260 ;
V_298 = F_268 ( V_298 ) ;
V_260 = F_269 ( V_298 , L_36 , & F_189 ) ;
if ( V_260 )
return V_260 ;
V_260 = F_241 ( V_3 , F_189 ) ;
if ( V_260 )
return V_260 ;
F_322 ( V_3 ) ;
return V_299 ;
}
static int F_443 ( struct V_324 * V_325 , void * V_326 )
{
struct V_2 * V_3 = F_8 ( F_276 ( V_325 ) ) ;
F_278 ( V_325 , L_37 , F_61 ( V_3 , V_477 ) ) ;
F_278 ( V_325 , L_38 , F_61 ( V_3 , V_233 ) ) ;
F_278 ( V_325 , L_39 , F_61 ( V_3 , V_249 ) ) ;
F_278 ( V_325 , L_40 , F_61 ( V_3 , V_253 ) ) ;
return 0 ;
}
bool F_444 ( struct V_2 * V_97 , struct V_2 * V_3 )
{
if ( F_84 () )
return false ;
if ( V_3 == V_4 )
return false ;
if ( F_49 ( & V_3 -> V_51 ) >= V_3 -> V_434 )
return false ;
while ( V_3 != V_97 ) {
V_3 = F_32 ( V_3 ) ;
if ( V_3 == V_4 )
break;
if ( F_49 ( & V_3 -> V_51 ) >= V_3 -> V_434 )
return false ;
}
return true ;
}
int F_445 ( struct V_28 * V_28 , struct V_94 * V_95 ,
T_3 V_143 , struct V_2 * * V_478 )
{
struct V_2 * V_3 = NULL ;
unsigned int V_50 = 1 ;
int V_118 = 0 ;
if ( F_84 () )
goto V_106;
if ( F_446 ( V_28 ) ) {
F_207 ( ! F_447 ( V_28 ) , V_28 ) ;
if ( V_28 -> V_2 )
goto V_106;
if ( V_121 ) {
T_5 V_443 = { . V_60 = F_448 ( V_28 ) , } ;
unsigned short V_8 = F_404 ( V_443 ) ;
F_12 () ;
V_3 = F_6 ( V_8 ) ;
if ( V_3 && ! F_15 ( & V_3 -> V_7 ) )
V_3 = NULL ;
F_16 () ;
}
}
if ( F_65 ( V_28 ) ) {
V_50 <<= F_449 ( V_28 ) ;
F_207 ( ! F_65 ( V_28 ) , V_28 ) ;
}
if ( ! V_3 )
V_3 = F_81 ( V_95 ) ;
V_118 = F_188 ( V_3 , V_143 , V_50 ) ;
F_19 ( & V_3 -> V_7 ) ;
V_106:
* V_478 = V_3 ;
return V_118 ;
}
void F_450 ( struct V_28 * V_28 , struct V_2 * V_3 ,
bool V_258 )
{
unsigned int V_50 = 1 ;
F_207 ( ! V_28 -> V_445 , V_28 ) ;
F_207 ( F_202 ( V_28 ) && ! V_258 , V_28 ) ;
if ( F_84 () )
return;
if ( ! V_3 )
return;
F_210 ( V_28 , V_3 , V_258 ) ;
if ( F_65 ( V_28 ) ) {
V_50 <<= F_449 ( V_28 ) ;
F_207 ( ! F_65 ( V_28 ) , V_28 ) ;
}
F_396 () ;
F_62 ( V_3 , V_28 , V_50 ) ;
F_76 ( V_3 , V_28 ) ;
F_397 () ;
if ( V_121 && F_446 ( V_28 ) ) {
T_5 V_279 = { . V_60 = F_448 (page) } ;
F_451 ( V_279 ) ;
}
}
void F_452 ( struct V_28 * V_28 , struct V_2 * V_3 )
{
unsigned int V_50 = 1 ;
if ( F_84 () )
return;
if ( ! V_3 )
return;
if ( F_65 ( V_28 ) ) {
V_50 <<= F_449 ( V_28 ) ;
F_207 ( ! F_65 ( V_28 ) , V_28 ) ;
}
F_199 ( V_3 , V_50 ) ;
}
static void F_453 ( struct V_2 * V_3 , unsigned long V_479 ,
unsigned long V_480 , unsigned long V_481 ,
unsigned long V_482 , struct V_28 * V_483 )
{
unsigned long V_50 = V_480 + V_481 ;
unsigned long V_19 ;
if ( ! F_4 ( V_3 ) ) {
F_168 ( & V_3 -> V_51 , V_50 ) ;
if ( V_121 )
F_168 ( & V_3 -> V_122 , V_50 ) ;
F_156 ( V_3 ) ;
}
F_454 ( V_19 ) ;
F_236 ( V_3 -> V_62 -> V_63 [ V_66 ] , V_480 ) ;
F_236 ( V_3 -> V_62 -> V_63 [ V_67 ] , V_481 ) ;
F_236 ( V_3 -> V_62 -> V_63 [ V_68 ] , V_482 ) ;
F_64 ( V_3 -> V_62 -> V_65 [ V_70 ] , V_479 ) ;
F_64 ( V_3 -> V_62 -> V_71 , V_50 ) ;
F_76 ( V_3 , V_483 ) ;
F_455 ( V_19 ) ;
if ( ! F_4 ( V_3 ) )
F_169 ( & V_3 -> V_7 , V_50 ) ;
}
static void F_456 ( struct V_373 * V_484 )
{
struct V_2 * V_3 = NULL ;
unsigned long V_480 = 0 ;
unsigned long V_481 = 0 ;
unsigned long V_482 = 0 ;
unsigned long V_479 = 0 ;
struct V_373 * V_80 ;
struct V_28 * V_28 ;
V_80 = V_484 -> V_80 ;
do {
unsigned int V_50 = 1 ;
V_28 = F_457 ( V_80 , struct V_28 , V_76 ) ;
V_80 = V_28 -> V_76 . V_80 ;
F_207 ( F_202 ( V_28 ) , V_28 ) ;
F_207 ( F_458 ( V_28 ) , V_28 ) ;
if ( ! V_28 -> V_2 )
continue;
if ( V_3 != V_28 -> V_2 ) {
if ( V_3 ) {
F_453 ( V_3 , V_479 , V_480 , V_481 ,
V_482 , V_28 ) ;
V_479 = V_480 = V_481 = V_482 = 0 ;
}
V_3 = V_28 -> V_2 ;
}
if ( F_65 ( V_28 ) ) {
V_50 <<= F_449 ( V_28 ) ;
F_207 ( ! F_65 ( V_28 ) , V_28 ) ;
V_482 += V_50 ;
}
if ( F_63 ( V_28 ) )
V_480 += V_50 ;
else
V_481 += V_50 ;
V_28 -> V_2 = NULL ;
V_479 ++ ;
} while ( V_80 != V_484 );
if ( V_3 )
F_453 ( V_3 , V_479 , V_480 , V_481 ,
V_482 , V_28 ) ;
}
void F_459 ( struct V_28 * V_28 )
{
if ( F_84 () )
return;
if ( ! V_28 -> V_2 )
return;
F_160 ( & V_28 -> V_76 ) ;
F_456 ( & V_28 -> V_76 ) ;
}
void F_460 ( struct V_373 * V_484 )
{
if ( F_84 () )
return;
if ( ! F_330 ( V_484 ) )
F_456 ( V_484 ) ;
}
void F_461 ( struct V_28 * V_485 , struct V_28 * V_486 )
{
struct V_2 * V_3 ;
int V_256 ;
F_207 ( ! F_447 ( V_485 ) , V_485 ) ;
F_207 ( ! F_447 ( V_486 ) , V_486 ) ;
F_207 ( F_63 ( V_485 ) != F_63 ( V_486 ) , V_486 ) ;
F_207 ( F_65 ( V_485 ) != F_65 ( V_486 ) ,
V_486 ) ;
if ( F_84 () )
return;
if ( V_486 -> V_2 )
return;
V_3 = V_485 -> V_2 ;
if ( ! V_3 )
return;
F_200 ( V_485 , & V_256 ) ;
V_485 -> V_2 = NULL ;
F_206 ( V_485 , V_256 ) ;
F_210 ( V_486 , V_3 , true ) ;
}
static int T_16 F_462 ( void )
{
int V_61 , V_169 ;
F_463 ( F_183 , 0 ) ;
F_59 (cpu)
F_224 ( & F_464 ( & V_214 , V_61 ) -> V_222 ,
F_170 ) ;
F_52 (node) {
struct V_487 * V_488 ;
int V_23 ;
V_488 = F_349 ( sizeof( * V_488 ) , V_234 ,
F_465 ( V_169 ) ? V_169 : V_489 ) ;
for ( V_23 = 0 ; V_23 < V_54 ; V_23 ++ ) {
struct V_32 * V_490 ;
V_490 = & V_488 -> V_35 [ V_23 ] ;
V_490 -> V_41 = V_491 ;
F_360 ( & V_490 -> V_49 ) ;
}
V_33 . V_34 [ V_169 ] = V_488 ;
}
return 0 ;
}
void F_466 ( struct V_28 * V_28 , T_5 V_279 )
{
struct V_2 * V_3 ;
unsigned short V_492 ;
F_207 ( F_202 ( V_28 ) , V_28 ) ;
F_207 ( F_458 ( V_28 ) , V_28 ) ;
if ( ! V_121 )
return;
V_3 = V_28 -> V_2 ;
if ( ! V_3 )
return;
V_492 = F_467 ( V_279 , F_5 ( V_3 ) ) ;
F_207 ( V_492 , V_28 ) ;
F_237 ( V_3 , true ) ;
V_28 -> V_2 = NULL ;
if ( ! F_4 ( V_3 ) )
F_168 ( & V_3 -> V_51 , 1 ) ;
F_68 ( ! F_468 () ) ;
F_62 ( V_3 , V_28 , - 1 ) ;
F_76 ( V_3 , V_28 ) ;
}
void F_451 ( T_5 V_279 )
{
struct V_2 * V_3 ;
unsigned short V_8 ;
if ( ! V_121 )
return;
V_8 = F_467 ( V_279 , 0 ) ;
F_12 () ;
V_3 = F_6 ( V_8 ) ;
if ( V_3 ) {
if ( ! F_4 ( V_3 ) )
F_168 ( & V_3 -> V_122 , 1 ) ;
F_237 ( V_3 , false ) ;
F_19 ( & V_3 -> V_7 ) ;
}
F_16 () ;
}
static int T_16 F_469 ( char * V_493 )
{
if ( ! strcmp ( V_493 , L_41 ) )
V_494 = 1 ;
else if ( ! strcmp ( V_493 , L_42 ) )
V_494 = 0 ;
return 1 ;
}
static int T_16 F_470 ( void )
{
if ( ! F_84 () && V_494 ) {
V_121 = 1 ;
F_18 ( F_471 ( & V_9 ,
V_495 ) ) ;
}
return 0 ;
}
