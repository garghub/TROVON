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
if ( ! V_3 || ! F_29 ( V_3 -> V_7 . V_29 ) )
V_3 = V_4 ;
F_16 () ;
return & V_3 -> V_7 ;
}
T_1 F_30 ( struct V_28 * V_28 )
{
struct V_2 * V_3 ;
unsigned long V_30 = 0 ;
F_12 () ;
V_3 = F_31 ( V_28 -> V_2 ) ;
while ( V_3 && ! ( V_3 -> V_7 . V_19 & V_31 ) )
V_3 = F_32 ( V_3 ) ;
if ( V_3 )
V_30 = F_33 ( V_3 -> V_7 . V_29 ) ;
F_16 () ;
return V_30 ;
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
do {
V_104 = F_31 ( V_103 -> V_110 ) ;
} while ( V_104 && ! F_85 ( & V_104 -> V_7 ) );
}
if ( V_104 )
V_7 = & V_104 -> V_7 ;
for (; ; ) {
V_7 = F_86 ( V_7 , & V_97 -> V_7 ) ;
if ( ! V_7 ) {
if ( ! V_98 )
continue;
break;
}
V_3 = F_8 ( V_7 ) ;
if ( V_7 == & V_97 -> V_7 )
break;
if ( F_85 ( V_7 ) ) {
if ( F_87 ( & V_3 -> V_111 ) )
break;
F_19 ( V_7 ) ;
}
V_3 = NULL ;
}
if ( V_100 ) {
if ( F_88 ( & V_103 -> V_110 , V_104 , V_3 ) == V_104 ) {
if ( V_3 )
F_11 ( & V_3 -> V_7 ) ;
if ( V_104 )
F_19 ( & V_104 -> V_7 ) ;
}
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
struct V_112 * F_90 ( struct V_23 * V_23 ,
struct V_2 * V_3 )
{
struct V_22 * V_36 ;
struct V_112 * V_112 ;
if ( F_84 () ) {
V_112 = & V_23 -> V_112 ;
goto V_106;
}
V_36 = F_25 ( V_3 , V_23 ) ;
V_112 = & V_36 -> V_112 ;
V_106:
if ( F_77 ( V_112 -> V_23 != V_23 ) )
V_112 -> V_23 = V_23 ;
return V_112 ;
}
struct V_112 * F_91 ( struct V_28 * V_28 , struct V_23 * V_23 )
{
struct V_22 * V_36 ;
struct V_2 * V_3 ;
struct V_112 * V_112 ;
if ( F_84 () ) {
V_112 = & V_23 -> V_112 ;
goto V_106;
}
V_3 = V_28 -> V_2 ;
if ( ! V_3 )
V_3 = V_4 ;
V_36 = F_34 ( V_3 , V_28 ) ;
V_112 = & V_36 -> V_112 ;
V_106:
if ( F_77 ( V_112 -> V_23 != V_23 ) )
V_112 -> V_23 = V_23 ;
return V_112 ;
}
void F_92 ( struct V_112 * V_112 , enum V_75 V_76 ,
int V_50 )
{
struct V_22 * V_36 ;
unsigned long * V_77 ;
if ( F_84 () )
return;
V_36 = F_3 ( V_112 , struct V_22 , V_112 ) ;
V_77 = V_36 -> V_77 + V_76 ;
* V_77 += V_50 ;
F_68 ( ( long ) ( * V_77 ) < 0 ) ;
}
bool F_93 ( struct V_92 * V_113 , struct V_2 * V_3 )
{
struct V_2 * V_114 ;
struct V_92 * V_40 ;
bool V_115 ;
V_40 = F_94 ( V_113 ) ;
if ( V_40 ) {
V_114 = F_81 ( V_40 -> V_95 ) ;
F_95 ( V_40 ) ;
} else {
F_12 () ;
V_114 = F_13 ( V_113 ) ;
F_11 ( & V_114 -> V_7 ) ;
F_16 () ;
}
V_115 = F_96 ( V_114 , V_3 ) ;
F_19 ( & V_114 -> V_7 ) ;
return V_115 ;
}
static unsigned long F_97 ( struct V_2 * V_3 )
{
unsigned long V_116 = 0 ;
unsigned long V_63 ;
unsigned long V_117 ;
V_63 = F_49 ( & V_3 -> V_51 ) ;
V_117 = F_31 ( V_3 -> V_51 . V_117 ) ;
if ( V_63 < V_117 )
V_116 = V_117 - V_63 ;
if ( V_118 ) {
V_63 = F_49 ( & V_3 -> V_119 ) ;
V_117 = F_31 ( V_3 -> V_119 . V_117 ) ;
if ( V_63 <= V_117 )
V_116 = F_98 ( V_116 , V_117 - V_63 ) ;
}
return V_116 ;
}
static bool F_99 ( struct V_2 * V_3 )
{
struct V_2 * V_120 ;
struct V_2 * V_121 ;
bool V_115 = false ;
F_100 ( & V_122 . V_49 ) ;
V_120 = V_122 . V_120 ;
V_121 = V_122 . V_121 ;
if ( ! V_120 )
goto V_123;
V_115 = F_96 ( V_120 , V_3 ) ||
F_96 ( V_121 , V_3 ) ;
V_123:
F_101 ( & V_122 . V_49 ) ;
return V_115 ;
}
static bool F_102 ( struct V_2 * V_3 )
{
if ( V_122 . V_124 && V_17 != V_122 . V_124 ) {
if ( F_99 ( V_3 ) ) {
F_103 ( V_125 ) ;
F_104 ( & V_122 . V_126 , & V_125 , V_127 ) ;
if ( V_122 . V_124 )
F_105 () ;
F_106 ( & V_122 . V_126 , & V_125 ) ;
return true ;
}
}
return false ;
}
void F_107 ( struct V_2 * V_3 , struct V_92 * V_40 )
{
static F_108 ( V_128 ) ;
struct V_2 * V_103 ;
unsigned int V_129 ;
F_109 ( & V_128 ) ;
F_12 () ;
if ( V_40 ) {
F_110 ( L_1 ) ;
F_111 ( F_112 ( V_40 , V_93 ) ) ;
F_113 ( L_2 ) ;
} else {
F_110 ( L_3 ) ;
}
F_111 ( V_3 -> V_7 . V_29 ) ;
F_113 ( L_4 ) ;
F_16 () ;
F_110 ( L_5 ,
F_114 ( ( V_130 ) F_49 ( & V_3 -> V_51 ) ) ,
F_114 ( ( V_130 ) V_3 -> V_51 . V_117 ) , V_3 -> V_51 . V_131 ) ;
F_110 ( L_6 ,
F_114 ( ( V_130 ) F_49 ( & V_3 -> V_119 ) ) ,
F_114 ( ( V_130 ) V_3 -> V_119 . V_117 ) , V_3 -> V_119 . V_131 ) ;
F_110 ( L_7 ,
F_114 ( ( V_130 ) F_49 ( & V_3 -> V_132 ) ) ,
F_114 ( ( V_130 ) V_3 -> V_132 . V_117 ) , V_3 -> V_132 . V_131 ) ;
F_115 (iter, memcg) {
F_110 ( L_8 ) ;
F_111 ( V_103 -> V_7 . V_29 ) ;
F_113 ( L_9 ) ;
for ( V_129 = 0 ; V_129 < V_133 ; V_129 ++ ) {
if ( V_129 == V_134 && ! V_118 )
continue;
F_113 ( L_10 , V_135 [ V_129 ] ,
F_114 ( F_58 ( V_103 , V_129 ) ) ) ;
}
for ( V_129 = 0 ; V_129 < V_136 ; V_129 ++ )
F_113 ( L_10 , V_137 [ V_129 ] ,
F_114 ( F_71 ( V_103 , F_70 ( V_129 ) ) ) ) ;
F_113 ( L_4 ) ;
}
F_116 ( & V_128 ) ;
}
static int F_117 ( struct V_2 * V_3 )
{
int V_138 = 0 ;
struct V_2 * V_103 ;
F_115 (iter, memcg)
V_138 ++ ;
return V_138 ;
}
static unsigned long F_118 ( struct V_2 * V_3 )
{
unsigned long V_117 ;
V_117 = V_3 -> V_51 . V_117 ;
if ( F_119 ( V_3 ) ) {
unsigned long V_139 ;
V_139 = V_3 -> V_119 . V_117 ;
V_117 = F_98 ( V_117 + V_140 , V_139 ) ;
}
return V_117 ;
}
static void F_120 ( struct V_2 * V_3 , T_3 V_141 ,
int V_142 )
{
struct V_143 V_144 = {
. V_145 = NULL ,
. V_146 = NULL ,
. V_141 = V_141 ,
. V_142 = V_142 ,
} ;
struct V_2 * V_103 ;
unsigned long V_147 = 0 ;
unsigned long V_148 ;
unsigned int V_149 = 0 ;
struct V_92 * V_150 = NULL ;
F_109 ( & V_151 ) ;
if ( F_121 ( V_17 ) || F_122 ( V_17 ) ) {
F_123 ( V_17 ) ;
goto V_123;
}
F_124 ( & V_144 , V_152 , V_3 ) ;
V_148 = F_118 ( V_3 ) ? : 1 ;
F_115 (iter, memcg) {
struct V_153 V_154 ;
struct V_92 * V_113 ;
F_125 ( & V_103 -> V_7 , & V_154 ) ;
while ( ( V_113 = F_126 ( & V_154 ) ) ) {
switch ( F_127 ( & V_144 , V_113 , V_148 ) ) {
case V_155 :
if ( V_150 )
F_128 ( V_150 ) ;
V_150 = V_113 ;
V_147 = V_156 ;
F_129 ( V_150 ) ;
case V_157 :
continue;
case V_158 :
F_130 ( & V_154 ) ;
F_89 ( V_3 , V_103 ) ;
if ( V_150 )
F_128 ( V_150 ) ;
goto V_123;
case V_159 :
break;
} ;
V_149 = F_131 ( V_113 , V_3 , NULL , V_148 ) ;
if ( ! V_149 || V_149 < V_147 )
continue;
if ( V_149 == V_147 &&
F_132 ( V_150 ) )
continue;
if ( V_150 )
F_128 ( V_150 ) ;
V_150 = V_113 ;
V_147 = V_149 ;
F_129 ( V_150 ) ;
}
F_130 ( & V_154 ) ;
}
if ( V_150 ) {
V_149 = V_147 * 1000 / V_148 ;
F_133 ( & V_144 , V_150 , V_149 , V_148 , V_3 ,
L_11 ) ;
}
V_123:
F_116 ( & V_151 ) ;
}
static bool F_134 ( struct V_2 * V_3 ,
int V_24 , bool V_160 )
{
if ( F_67 ( V_3 , V_24 , V_161 ) )
return true ;
if ( V_160 || ! V_140 )
return false ;
if ( F_67 ( V_3 , V_24 , V_162 ) )
return true ;
return false ;
}
static void F_135 ( struct V_2 * V_3 )
{
int V_24 ;
if ( ! F_136 ( & V_3 -> V_91 ) )
return;
if ( F_137 ( & V_3 -> V_163 ) > 1 )
return;
V_3 -> V_164 = V_165 [ V_166 ] ;
F_138 (nid, node_states[N_MEMORY]) {
if ( ! F_134 ( V_3 , V_24 , false ) )
F_139 ( V_24 , V_3 -> V_164 ) ;
}
F_140 ( & V_3 -> V_91 , 0 ) ;
F_140 ( & V_3 -> V_163 , 0 ) ;
}
int F_141 ( struct V_2 * V_3 )
{
int V_167 ;
F_135 ( V_3 ) ;
V_167 = V_3 -> V_168 ;
V_167 = F_142 ( V_167 , V_3 -> V_164 ) ;
if ( V_167 == V_90 )
V_167 = F_143 ( V_3 -> V_164 ) ;
if ( F_77 ( V_167 == V_90 ) )
V_167 = F_144 () ;
V_3 -> V_168 = V_167 ;
return V_167 ;
}
int F_141 ( struct V_2 * V_3 )
{
return 0 ;
}
static int F_145 ( struct V_2 * V_169 ,
struct V_23 * V_23 ,
T_3 V_141 ,
unsigned long * V_170 )
{
struct V_2 * V_171 = NULL ;
int V_172 = 0 ;
int V_173 = 0 ;
unsigned long V_53 ;
unsigned long V_174 ;
struct V_99 V_100 = {
. V_23 = V_23 ,
. V_107 = 0 ,
} ;
V_53 = F_48 ( V_169 ) ;
while ( 1 ) {
V_171 = F_83 ( V_169 , V_171 , & V_100 ) ;
if ( ! V_171 ) {
V_173 ++ ;
if ( V_173 >= 2 ) {
if ( ! V_172 )
break;
if ( V_172 >= ( V_53 >> 2 ) ||
( V_173 > V_175 ) )
break;
}
continue;
}
V_172 += F_146 ( V_171 , V_141 , false ,
V_23 , & V_174 ) ;
* V_170 += V_174 ;
if ( ! F_48 ( V_169 ) )
break;
}
F_89 ( V_169 , V_171 ) ;
return V_172 ;
}
static bool F_147 ( struct V_2 * V_3 )
{
struct V_2 * V_103 , * V_176 = NULL ;
F_100 ( & V_177 ) ;
F_115 (iter, memcg) {
if ( V_103 -> V_151 ) {
V_176 = V_103 ;
F_89 ( V_3 , V_103 ) ;
break;
} else
V_103 -> V_151 = true ;
}
if ( V_176 ) {
F_115 (iter, memcg) {
if ( V_103 == V_176 ) {
F_89 ( V_3 , V_103 ) ;
break;
}
V_103 -> V_151 = false ;
}
} else
F_148 ( & V_178 , 0 , 1 , V_179 ) ;
F_101 ( & V_177 ) ;
return ! V_176 ;
}
static void F_149 ( struct V_2 * V_3 )
{
struct V_2 * V_103 ;
F_100 ( & V_177 ) ;
F_150 ( & V_178 , 1 , V_179 ) ;
F_115 (iter, memcg)
V_103 -> V_151 = false ;
F_101 ( & V_177 ) ;
}
static void F_151 ( struct V_2 * V_3 )
{
struct V_2 * V_103 ;
F_100 ( & V_177 ) ;
F_115 (iter, memcg)
V_103 -> V_180 ++ ;
F_101 ( & V_177 ) ;
}
static void F_152 ( struct V_2 * V_3 )
{
struct V_2 * V_103 ;
F_100 ( & V_177 ) ;
F_115 (iter, memcg)
if ( V_103 -> V_180 > 0 )
V_103 -> V_180 -- ;
F_101 ( & V_177 ) ;
}
static int F_153 ( T_4 * V_125 ,
unsigned V_181 , int V_182 , void * V_183 )
{
struct V_2 * V_184 = (struct V_2 * ) V_183 ;
struct V_2 * V_185 ;
struct V_186 * V_186 ;
V_186 = F_3 ( V_125 , struct V_186 , V_125 ) ;
V_185 = V_186 -> V_3 ;
if ( ! F_96 ( V_184 , V_185 ) &&
! F_96 ( V_185 , V_184 ) )
return 0 ;
return F_154 ( V_125 , V_181 , V_182 , V_183 ) ;
}
static void F_155 ( struct V_2 * V_3 )
{
if ( V_3 && V_3 -> V_180 )
F_156 ( & V_187 , V_188 , 0 , V_3 ) ;
}
static void F_157 ( struct V_2 * V_3 , T_3 V_189 , int V_142 )
{
if ( ! V_17 -> V_190 . V_191 )
return;
F_11 ( & V_3 -> V_7 ) ;
V_17 -> V_190 . V_3 = V_3 ;
V_17 -> V_190 . V_141 = V_189 ;
V_17 -> V_190 . V_142 = V_142 ;
}
bool F_158 ( bool V_192 )
{
struct V_2 * V_3 = V_17 -> V_190 . V_3 ;
struct V_186 V_193 ;
bool V_194 ;
if ( ! V_3 )
return false ;
if ( ! V_192 || V_195 )
goto V_196;
V_193 . V_3 = V_3 ;
V_193 . V_125 . V_19 = 0 ;
V_193 . V_125 . V_197 = F_153 ;
V_193 . V_125 . V_198 = V_17 ;
F_159 ( & V_193 . V_125 . V_199 ) ;
F_104 ( & V_187 , & V_193 . V_125 , V_200 ) ;
F_151 ( V_3 ) ;
V_194 = F_147 ( V_3 ) ;
if ( V_194 )
F_160 ( V_3 ) ;
if ( V_194 && ! V_3 -> V_201 ) {
F_152 ( V_3 ) ;
F_106 ( & V_187 , & V_193 . V_125 ) ;
F_120 ( V_3 , V_17 -> V_190 . V_141 ,
V_17 -> V_190 . V_142 ) ;
} else {
F_105 () ;
F_152 ( V_3 ) ;
F_106 ( & V_187 , & V_193 . V_125 ) ;
}
if ( V_194 ) {
F_149 ( V_3 ) ;
F_155 ( V_3 ) ;
}
V_196:
V_17 -> V_190 . V_3 = NULL ;
F_19 ( & V_3 -> V_7 ) ;
return true ;
}
struct V_2 * F_161 ( struct V_28 * V_28 )
{
struct V_2 * V_3 ;
unsigned long V_19 ;
F_12 () ;
if ( F_84 () )
return NULL ;
V_202:
V_3 = V_28 -> V_2 ;
if ( F_77 ( ! V_3 ) )
return NULL ;
if ( F_136 ( & V_3 -> V_203 ) <= 0 )
return V_3 ;
F_46 ( & V_3 -> V_204 , V_19 ) ;
if ( V_3 != V_28 -> V_2 ) {
F_47 ( & V_3 -> V_204 , V_19 ) ;
goto V_202;
}
V_3 -> V_205 = V_17 ;
V_3 -> V_206 = V_19 ;
return V_3 ;
}
void F_162 ( struct V_2 * V_3 )
{
if ( V_3 && V_3 -> V_205 == V_17 ) {
unsigned long V_19 = V_3 -> V_206 ;
V_3 -> V_205 = NULL ;
V_3 -> V_206 = 0 ;
F_47 ( & V_3 -> V_204 , V_19 ) ;
}
F_16 () ;
}
static bool F_163 ( struct V_2 * V_3 , unsigned int V_50 )
{
struct V_207 * V_208 ;
bool V_115 = false ;
if ( V_50 > V_209 )
return V_115 ;
V_208 = & F_164 ( V_210 ) ;
if ( V_3 == V_208 -> V_211 && V_208 -> V_50 >= V_50 ) {
V_208 -> V_50 -= V_50 ;
V_115 = true ;
}
F_165 ( V_210 ) ;
return V_115 ;
}
static void F_166 ( struct V_207 * V_208 )
{
struct V_2 * V_212 = V_208 -> V_211 ;
if ( V_208 -> V_50 ) {
F_167 ( & V_212 -> V_51 , V_208 -> V_50 ) ;
if ( V_118 )
F_167 ( & V_212 -> V_119 , V_208 -> V_50 ) ;
F_168 ( & V_212 -> V_7 , V_208 -> V_50 ) ;
V_208 -> V_50 = 0 ;
}
V_208 -> V_211 = NULL ;
}
static void F_169 ( struct V_213 * V_214 )
{
struct V_207 * V_208 = F_170 ( & V_210 ) ;
F_166 ( V_208 ) ;
F_171 ( V_215 , & V_208 -> V_19 ) ;
}
static void F_172 ( struct V_2 * V_3 , unsigned int V_50 )
{
struct V_207 * V_208 = & F_164 ( V_210 ) ;
if ( V_208 -> V_211 != V_3 ) {
F_166 ( V_208 ) ;
V_208 -> V_211 = V_3 ;
}
V_208 -> V_50 += V_50 ;
F_165 ( V_210 ) ;
}
static void F_173 ( struct V_2 * V_169 )
{
int V_61 , V_216 ;
if ( ! F_174 ( & V_217 ) )
return;
F_175 () ;
V_216 = F_176 () ;
F_177 (cpu) {
struct V_207 * V_208 = & F_60 ( V_210 , V_61 ) ;
struct V_2 * V_3 ;
V_3 = V_208 -> V_211 ;
if ( ! V_3 || ! V_208 -> V_50 )
continue;
if ( ! F_96 ( V_3 , V_169 ) )
continue;
if ( ! F_178 ( V_215 , & V_208 -> V_19 ) ) {
if ( V_61 == V_216 )
F_169 ( & V_208 -> V_218 ) ;
else
F_179 ( V_61 , & V_208 -> V_218 ) ;
}
}
F_180 () ;
F_181 () ;
F_116 ( & V_217 ) ;
}
static int F_182 ( struct V_219 * V_220 ,
unsigned long V_221 ,
void * V_222 )
{
int V_61 = ( unsigned long ) V_222 ;
struct V_207 * V_208 ;
if ( V_221 == V_223 )
return V_224 ;
if ( V_221 != V_225 && V_221 != V_226 )
return V_224 ;
V_208 = & F_60 ( V_210 , V_61 ) ;
F_166 ( V_208 ) ;
return V_224 ;
}
static int F_183 ( struct V_2 * V_3 , T_3 V_141 ,
unsigned int V_50 )
{
unsigned int V_227 = F_184 ( V_209 , V_50 ) ;
int V_228 = V_229 ;
struct V_2 * V_230 ;
struct V_231 * V_232 ;
unsigned long V_233 ;
bool V_234 = true ;
bool V_235 = false ;
int V_115 = 0 ;
if ( F_4 ( V_3 ) )
goto V_57;
V_56:
if ( F_163 ( V_3 , V_50 ) )
goto V_57;
if ( ! V_118 ||
! F_185 ( & V_3 -> V_119 , V_227 , & V_232 ) ) {
if ( ! F_185 ( & V_3 -> V_51 , V_227 , & V_232 ) )
goto V_236;
if ( V_118 )
F_167 ( & V_3 -> V_119 , V_227 ) ;
V_230 = F_186 ( V_232 , V_51 ) ;
} else {
V_230 = F_186 ( V_232 , V_119 ) ;
V_234 = false ;
}
if ( V_227 > V_50 ) {
V_227 = V_50 ;
goto V_56;
}
if ( F_77 ( F_187 ( V_237 ) ||
F_121 ( V_17 ) ||
V_17 -> V_19 & V_238 ) )
goto V_239;
if ( F_77 ( F_188 ( V_17 ) ) )
goto V_240;
if ( ! ( V_141 & V_241 ) )
goto V_240;
F_189 ( V_230 , V_242 , 1 ) ;
V_233 = F_190 ( V_230 , V_50 ,
V_141 , V_234 ) ;
if ( F_97 ( V_230 ) >= V_50 )
goto V_56;
if ( ! V_235 ) {
F_173 ( V_230 ) ;
V_235 = true ;
goto V_56;
}
if ( V_141 & V_243 )
goto V_240;
if ( V_233 && V_50 <= ( 1 << V_244 ) )
goto V_56;
if ( F_102 ( V_230 ) )
goto V_56;
if ( V_228 -- )
goto V_56;
if ( V_141 & V_245 )
goto V_239;
if ( F_121 ( V_17 ) )
goto V_239;
F_189 ( V_230 , V_246 , 1 ) ;
F_157 ( V_230 , V_141 , F_191 ( V_50 ) ) ;
V_240:
if ( ! ( V_141 & V_245 ) )
return - V_247 ;
V_239:
return - V_248 ;
V_236:
F_192 ( & V_3 -> V_7 , V_227 ) ;
if ( V_227 > V_50 )
F_172 ( V_3 , V_227 - V_50 ) ;
if ( ! ( V_141 & V_241 ) )
goto V_57;
do {
if ( F_49 ( & V_3 -> V_51 ) <= V_3 -> V_249 )
continue;
F_189 ( V_3 , V_250 , 1 ) ;
F_190 ( V_3 , V_50 , V_141 , true ) ;
} while ( ( V_3 = F_32 ( V_3 ) ) );
V_57:
return V_115 ;
}
static void F_193 ( struct V_2 * V_3 , unsigned int V_50 )
{
if ( F_4 ( V_3 ) )
return;
F_167 ( & V_3 -> V_51 , V_50 ) ;
if ( V_118 )
F_167 ( & V_3 -> V_119 , V_50 ) ;
F_168 ( & V_3 -> V_7 , V_50 ) ;
}
static void F_194 ( struct V_28 * V_28 , int * V_251 )
{
struct V_23 * V_23 = F_195 ( V_28 ) ;
F_56 ( & V_23 -> V_252 ) ;
if ( F_196 ( V_28 ) ) {
struct V_112 * V_112 ;
V_112 = F_91 ( V_28 , V_23 ) ;
F_197 ( V_28 ) ;
F_198 ( V_28 , V_112 , F_199 ( V_28 ) ) ;
* V_251 = 1 ;
} else
* V_251 = 0 ;
}
static void F_200 ( struct V_28 * V_28 , int V_251 )
{
struct V_23 * V_23 = F_195 ( V_28 ) ;
if ( V_251 ) {
struct V_112 * V_112 ;
V_112 = F_91 ( V_28 , V_23 ) ;
F_201 ( F_196 ( V_28 ) , V_28 ) ;
F_202 ( V_28 ) ;
F_203 ( V_28 , V_112 , F_199 ( V_28 ) ) ;
}
F_57 ( & V_23 -> V_252 ) ;
}
static void F_204 ( struct V_28 * V_28 , struct V_2 * V_3 ,
bool V_253 )
{
int V_251 ;
F_201 ( V_28 -> V_2 , V_28 ) ;
if ( V_253 )
F_194 ( V_28 , & V_251 ) ;
V_28 -> V_2 = V_3 ;
if ( V_253 )
F_200 ( V_28 , V_251 ) ;
}
int F_205 ( struct V_2 * V_3 , T_3 V_254 ,
unsigned long V_50 )
{
struct V_231 * V_232 ;
int V_115 = 0 ;
V_115 = F_185 ( & V_3 -> V_132 , V_50 , & V_232 ) ;
if ( V_115 < 0 )
return V_115 ;
V_115 = F_183 ( V_3 , V_254 , V_50 ) ;
if ( V_115 == - V_248 ) {
F_206 ( & V_3 -> V_51 , V_50 ) ;
if ( V_118 )
F_206 ( & V_3 -> V_119 , V_50 ) ;
F_192 ( & V_3 -> V_7 , V_50 ) ;
V_115 = 0 ;
} else if ( V_115 )
F_167 ( & V_3 -> V_132 , V_50 ) ;
return V_115 ;
}
void F_207 ( struct V_2 * V_3 , unsigned long V_50 )
{
F_167 ( & V_3 -> V_51 , V_50 ) ;
if ( V_118 )
F_167 ( & V_3 -> V_119 , V_50 ) ;
F_167 ( & V_3 -> V_132 , V_50 ) ;
F_168 ( & V_3 -> V_7 , V_50 ) ;
}
static int F_208 ( void )
{
int V_8 , V_255 ;
int V_256 ;
V_8 = F_209 ( & V_257 ,
0 , V_258 , V_259 ) ;
if ( V_8 < 0 )
return V_8 ;
if ( V_8 < V_260 )
return V_8 ;
F_210 ( & V_21 ) ;
V_255 = 2 * ( V_8 + 1 ) ;
if ( V_255 < V_261 )
V_255 = V_261 ;
else if ( V_255 > V_258 )
V_255 = V_258 ;
V_256 = F_211 ( V_255 ) ;
if ( ! V_256 )
V_256 = F_212 ( V_255 ) ;
if ( ! V_256 )
V_260 = V_255 ;
F_213 ( & V_21 ) ;
if ( V_256 ) {
F_214 ( & V_257 , V_8 ) ;
return V_256 ;
}
return V_8 ;
}
static void F_215 ( int V_8 )
{
F_214 ( & V_257 , V_8 ) ;
}
static void F_216 ( struct V_213 * V_262 )
{
struct V_263 * V_264 =
F_3 ( V_262 , struct V_263 , V_218 ) ;
struct V_2 * V_3 = V_264 -> V_3 ;
struct V_265 * V_266 = V_264 -> V_266 ;
F_217 ( V_3 , V_266 ) ;
F_19 ( & V_3 -> V_7 ) ;
F_218 ( V_264 ) ;
}
static void F_219 ( struct V_2 * V_3 ,
struct V_265 * V_266 )
{
struct V_263 * V_264 ;
V_264 = F_220 ( sizeof( * V_264 ) , V_267 ) ;
if ( ! V_264 )
return;
F_11 ( & V_3 -> V_7 ) ;
V_264 -> V_3 = V_3 ;
V_264 -> V_266 = V_266 ;
F_221 ( & V_264 -> V_218 , F_216 ) ;
F_222 ( & V_264 -> V_218 ) ;
}
static void F_223 ( struct V_2 * V_3 ,
struct V_265 * V_266 )
{
V_17 -> V_268 = 1 ;
F_219 ( V_3 , V_266 ) ;
V_17 -> V_268 = 0 ;
}
struct V_265 * F_224 ( struct V_265 * V_266 )
{
struct V_2 * V_3 ;
struct V_265 * V_269 ;
int V_270 ;
F_68 ( ! F_225 ( V_266 ) ) ;
if ( V_17 -> V_268 )
return V_266 ;
V_3 = F_81 ( V_17 -> V_95 ) ;
V_270 = F_31 ( V_3 -> V_270 ) ;
if ( V_270 < 0 )
goto V_106;
V_269 = F_226 ( V_266 , V_270 ) ;
if ( F_227 ( V_269 ) )
return V_269 ;
F_223 ( V_3 , V_266 ) ;
V_106:
F_19 ( & V_3 -> V_7 ) ;
return V_266 ;
}
void F_228 ( struct V_265 * V_266 )
{
if ( ! F_225 ( V_266 ) )
F_19 ( & V_266 -> V_271 . V_3 -> V_7 ) ;
}
bool
F_229 ( T_3 V_254 , struct V_2 * * V_272 , int V_142 )
{
struct V_2 * V_3 ;
int V_115 ;
* V_272 = NULL ;
V_3 = F_81 ( V_17 -> V_95 ) ;
if ( ! F_230 ( V_3 ) ) {
F_19 ( & V_3 -> V_7 ) ;
return true ;
}
V_115 = F_205 ( V_3 , V_254 , 1 << V_142 ) ;
if ( ! V_115 )
* V_272 = V_3 ;
F_19 ( & V_3 -> V_7 ) ;
return ( V_115 == 0 ) ;
}
void F_231 ( struct V_28 * V_28 , struct V_2 * V_3 ,
int V_142 )
{
F_68 ( F_4 ( V_3 ) ) ;
if ( ! V_28 ) {
F_207 ( V_3 , 1 << V_142 ) ;
return;
}
V_28 -> V_2 = V_3 ;
}
void F_232 ( struct V_28 * V_28 , int V_142 )
{
struct V_2 * V_3 = V_28 -> V_2 ;
if ( ! V_3 )
return;
F_201 ( F_4 ( V_3 ) , V_28 ) ;
F_207 ( V_3 , 1 << V_142 ) ;
V_28 -> V_2 = NULL ;
}
struct V_2 * F_233 ( void * V_273 )
{
struct V_2 * V_3 = NULL ;
struct V_265 * V_266 ;
struct V_28 * V_28 ;
V_28 = F_234 ( V_273 ) ;
if ( F_235 ( V_28 ) ) {
V_266 = V_28 -> V_274 ;
if ( ! F_225 ( V_266 ) )
V_3 = V_266 -> V_271 . V_3 ;
} else
V_3 = V_28 -> V_2 ;
return V_3 ;
}
void F_236 ( struct V_28 * V_275 )
{
int V_129 ;
if ( F_84 () )
return;
for ( V_129 = 1 ; V_129 < V_276 ; V_129 ++ )
V_275 [ V_129 ] . V_2 = V_275 -> V_2 ;
F_237 ( V_275 -> V_2 -> V_62 -> V_63 [ V_68 ] ,
V_276 ) ;
}
static void F_238 ( struct V_2 * V_3 ,
bool V_277 )
{
int V_60 = ( V_277 ) ? 1 : - 1 ;
F_239 ( V_3 -> V_62 -> V_63 [ V_134 ] , V_60 ) ;
}
static int F_240 ( T_5 V_278 ,
struct V_2 * V_120 , struct V_2 * V_121 )
{
unsigned short V_279 , V_280 ;
V_279 = F_5 ( V_120 ) ;
V_280 = F_5 ( V_121 ) ;
if ( F_241 ( V_278 , V_279 , V_280 ) == V_279 ) {
F_238 ( V_120 , false ) ;
F_238 ( V_121 , true ) ;
return 0 ;
}
return - V_281 ;
}
static inline int F_240 ( T_5 V_278 ,
struct V_2 * V_120 , struct V_2 * V_121 )
{
return - V_281 ;
}
static int F_242 ( struct V_2 * V_3 ,
unsigned long V_117 )
{
unsigned long V_282 ;
unsigned long V_283 ;
bool V_284 = false ;
int V_285 ;
int V_115 ;
V_285 = V_229 *
F_117 ( V_3 ) ;
V_283 = F_49 ( & V_3 -> V_51 ) ;
do {
if ( F_243 ( V_17 ) ) {
V_115 = - V_248 ;
break;
}
F_109 ( & V_286 ) ;
if ( V_117 > V_3 -> V_119 . V_117 ) {
F_116 ( & V_286 ) ;
V_115 = - V_281 ;
break;
}
if ( V_117 > V_3 -> V_51 . V_117 )
V_284 = true ;
V_115 = F_244 ( & V_3 -> V_51 , V_117 ) ;
F_116 ( & V_286 ) ;
if ( ! V_115 )
break;
F_190 ( V_3 , 1 , V_259 , true ) ;
V_282 = F_49 ( & V_3 -> V_51 ) ;
if ( V_282 >= V_283 )
V_285 -- ;
else
V_283 = V_282 ;
} while ( V_285 );
if ( ! V_115 && V_284 )
F_155 ( V_3 ) ;
return V_115 ;
}
static int F_245 ( struct V_2 * V_3 ,
unsigned long V_117 )
{
unsigned long V_282 ;
unsigned long V_283 ;
bool V_284 = false ;
int V_285 ;
int V_115 ;
V_285 = V_229 *
F_117 ( V_3 ) ;
V_283 = F_49 ( & V_3 -> V_119 ) ;
do {
if ( F_243 ( V_17 ) ) {
V_115 = - V_248 ;
break;
}
F_109 ( & V_286 ) ;
if ( V_117 < V_3 -> V_51 . V_117 ) {
F_116 ( & V_286 ) ;
V_115 = - V_281 ;
break;
}
if ( V_117 > V_3 -> V_119 . V_117 )
V_284 = true ;
V_115 = F_244 ( & V_3 -> V_119 , V_117 ) ;
F_116 ( & V_286 ) ;
if ( ! V_115 )
break;
F_190 ( V_3 , 1 , V_259 , false ) ;
V_282 = F_49 ( & V_3 -> V_119 ) ;
if ( V_282 >= V_283 )
V_285 -- ;
else
V_283 = V_282 ;
} while ( V_285 );
if ( ! V_115 && V_284 )
F_155 ( V_3 ) ;
return V_115 ;
}
unsigned long F_246 ( struct V_23 * V_23 , int V_142 ,
T_3 V_141 ,
unsigned long * V_170 )
{
unsigned long V_233 = 0 ;
struct V_22 * V_36 , * V_287 = NULL ;
unsigned long V_288 ;
int V_173 = 0 ;
struct V_32 * V_37 ;
unsigned long V_53 ;
unsigned long V_174 ;
if ( V_142 > 0 )
return 0 ;
V_37 = F_37 ( F_26 ( V_23 ) , F_27 ( V_23 ) ) ;
do {
if ( V_287 )
V_36 = V_287 ;
else
V_36 = F_55 ( V_37 ) ;
if ( ! V_36 )
break;
V_174 = 0 ;
V_288 = F_145 ( V_36 -> V_3 , V_23 ,
V_141 , & V_174 ) ;
V_233 += V_288 ;
* V_170 += V_174 ;
F_56 ( & V_37 -> V_49 ) ;
F_43 ( V_36 , V_37 ) ;
V_287 = NULL ;
if ( ! V_288 )
V_287 = F_53 ( V_37 ) ;
V_53 = F_48 ( V_36 -> V_3 ) ;
F_39 ( V_36 , V_37 , V_53 ) ;
F_57 ( & V_37 -> V_49 ) ;
F_19 ( & V_36 -> V_3 -> V_7 ) ;
V_173 ++ ;
if ( ! V_233 &&
( V_287 == NULL ||
V_173 > V_289 ) )
break;
} while ( ! V_233 );
if ( V_287 )
F_19 ( & V_287 -> V_3 -> V_7 ) ;
return V_233 ;
}
static inline bool F_247 ( struct V_2 * V_3 )
{
bool V_115 ;
F_248 ( & V_290 ) ;
F_12 () ;
V_115 = F_249 ( NULL , & V_3 -> V_7 ) ;
F_16 () ;
return V_115 ;
}
static int F_250 ( struct V_2 * V_3 )
{
int V_228 = V_229 ;
F_251 () ;
while ( V_228 && F_49 ( & V_3 -> V_51 ) ) {
int V_291 ;
if ( F_243 ( V_17 ) )
return - V_248 ;
V_291 = F_190 ( V_3 , 1 ,
V_259 , true ) ;
if ( ! V_291 ) {
V_228 -- ;
F_252 ( V_292 , V_293 / 10 ) ;
}
}
return 0 ;
}
static T_6 F_253 ( struct V_294 * V_295 ,
char * V_296 , T_7 V_297 ,
T_8 V_298 )
{
struct V_2 * V_3 = F_8 ( F_254 ( V_295 ) ) ;
if ( F_4 ( V_3 ) )
return - V_281 ;
return F_250 ( V_3 ) ? : V_297 ;
}
static V_130 F_255 ( struct V_5 * V_7 ,
struct V_299 * V_300 )
{
return F_8 ( V_7 ) -> V_105 ;
}
static int F_256 ( struct V_5 * V_7 ,
struct V_299 * V_300 , V_130 V_60 )
{
int V_301 = 0 ;
struct V_2 * V_3 = F_8 ( V_7 ) ;
struct V_2 * V_302 = F_8 ( V_3 -> V_7 . V_42 ) ;
F_109 ( & V_290 ) ;
if ( V_3 -> V_105 == V_60 )
goto V_106;
if ( ( ! V_302 || ! V_302 -> V_105 ) &&
( V_60 == 1 || V_60 == 0 ) ) {
if ( ! F_247 ( V_3 ) )
V_3 -> V_105 = V_60 ;
else
V_301 = - V_303 ;
} else
V_301 = - V_281 ;
V_106:
F_116 ( & V_290 ) ;
return V_301 ;
}
static unsigned long F_257 ( struct V_2 * V_3 ,
enum V_58 V_59 )
{
struct V_2 * V_103 ;
unsigned long V_60 = 0 ;
F_115 (iter, memcg)
V_60 += F_58 ( V_103 , V_59 ) ;
return V_60 ;
}
static inline V_130 F_258 ( struct V_2 * V_3 , bool V_304 )
{
V_130 V_60 ;
if ( F_4 ( V_3 ) ) {
V_60 = F_257 ( V_3 , V_67 ) ;
V_60 += F_257 ( V_3 , V_66 ) ;
if ( V_304 )
V_60 += F_257 ( V_3 , V_134 ) ;
} else {
if ( ! V_304 )
V_60 = F_49 ( & V_3 -> V_51 ) ;
else
V_60 = F_49 ( & V_3 -> V_119 ) ;
}
return V_60 << V_305 ;
}
static V_130 F_259 ( struct V_5 * V_7 ,
struct V_299 * V_300 )
{
struct V_2 * V_3 = F_8 ( V_7 ) ;
struct V_231 * V_232 ;
switch ( F_260 ( V_300 -> V_198 ) ) {
case V_306 :
V_232 = & V_3 -> V_51 ;
break;
case V_307 :
V_232 = & V_3 -> V_119 ;
break;
case V_308 :
V_232 = & V_3 -> V_132 ;
break;
default:
F_261 () ;
}
switch ( F_262 ( V_300 -> V_198 ) ) {
case V_309 :
if ( V_232 == & V_3 -> V_51 )
return F_258 ( V_3 , false ) ;
if ( V_232 == & V_3 -> V_119 )
return F_258 ( V_3 , true ) ;
return ( V_130 ) F_49 ( V_232 ) * V_310 ;
case V_311 :
return ( V_130 ) V_232 -> V_117 * V_310 ;
case V_312 :
return ( V_130 ) V_232 -> V_313 * V_310 ;
case V_314 :
return V_232 -> V_131 ;
case V_315 :
return ( V_130 ) V_3 -> V_52 * V_310 ;
default:
F_261 () ;
}
}
static int F_263 ( struct V_2 * V_3 ,
unsigned long V_50 )
{
int V_256 = 0 ;
int V_316 ;
F_10 ( V_3 -> V_270 >= 0 ) ;
F_10 ( V_3 -> V_317 ) ;
F_10 ( V_3 -> V_318 ) ;
F_109 ( & V_290 ) ;
if ( F_264 ( V_3 -> V_7 . V_29 ) ||
( V_3 -> V_105 && F_247 ( V_3 ) ) )
V_256 = - V_303 ;
F_116 ( & V_290 ) ;
if ( V_256 )
goto V_106;
V_316 = F_208 () ;
if ( V_316 < 0 ) {
V_256 = V_316 ;
goto V_106;
}
V_256 = F_244 ( & V_3 -> V_132 , V_50 ) ;
F_68 ( V_256 ) ;
F_265 ( & V_319 ) ;
V_3 -> V_270 = V_316 ;
V_3 -> V_317 = true ;
V_3 -> V_318 = true ;
V_106:
return V_256 ;
}
static int F_266 ( struct V_2 * V_3 ,
unsigned long V_117 )
{
int V_115 ;
F_109 ( & V_286 ) ;
if ( ! F_230 ( V_3 ) )
V_115 = F_263 ( V_3 , V_117 ) ;
else
V_115 = F_244 ( & V_3 -> V_132 , V_117 ) ;
F_116 ( & V_286 ) ;
return V_115 ;
}
static int F_267 ( struct V_2 * V_3 )
{
int V_115 = 0 ;
struct V_2 * V_42 = F_32 ( V_3 ) ;
if ( ! V_42 )
return 0 ;
F_109 ( & V_286 ) ;
if ( F_230 ( V_42 ) )
V_115 = F_263 ( V_3 , V_320 ) ;
F_116 ( & V_286 ) ;
return V_115 ;
}
static int F_266 ( struct V_2 * V_3 ,
unsigned long V_117 )
{
return - V_281 ;
}
static T_6 F_268 ( struct V_294 * V_295 ,
char * V_296 , T_7 V_297 , T_8 V_298 )
{
struct V_2 * V_3 = F_8 ( F_254 ( V_295 ) ) ;
unsigned long V_50 ;
int V_115 ;
V_296 = F_269 ( V_296 ) ;
V_115 = F_270 ( V_296 , L_12 , & V_50 ) ;
if ( V_115 )
return V_115 ;
switch ( F_262 ( F_271 ( V_295 ) -> V_198 ) ) {
case V_311 :
if ( F_4 ( V_3 ) ) {
V_115 = - V_281 ;
break;
}
switch ( F_260 ( F_271 ( V_295 ) -> V_198 ) ) {
case V_306 :
V_115 = F_242 ( V_3 , V_50 ) ;
break;
case V_307 :
V_115 = F_245 ( V_3 , V_50 ) ;
break;
case V_308 :
V_115 = F_266 ( V_3 , V_50 ) ;
break;
}
break;
case V_315 :
V_3 -> V_52 = V_50 ;
V_115 = 0 ;
break;
}
return V_115 ? : V_297 ;
}
static T_6 F_272 ( struct V_294 * V_295 , char * V_296 ,
T_7 V_297 , T_8 V_298 )
{
struct V_2 * V_3 = F_8 ( F_254 ( V_295 ) ) ;
struct V_231 * V_232 ;
switch ( F_260 ( F_271 ( V_295 ) -> V_198 ) ) {
case V_306 :
V_232 = & V_3 -> V_51 ;
break;
case V_307 :
V_232 = & V_3 -> V_119 ;
break;
case V_308 :
V_232 = & V_3 -> V_132 ;
break;
default:
F_261 () ;
}
switch ( F_262 ( F_271 ( V_295 ) -> V_198 ) ) {
case V_312 :
F_273 ( V_232 ) ;
break;
case V_314 :
V_232 -> V_131 = 0 ;
break;
default:
F_261 () ;
}
return V_297 ;
}
static V_130 F_274 ( struct V_5 * V_7 ,
struct V_299 * V_300 )
{
return F_8 ( V_7 ) -> V_321 ;
}
static int F_275 ( struct V_5 * V_7 ,
struct V_299 * V_300 , V_130 V_60 )
{
struct V_2 * V_3 = F_8 ( V_7 ) ;
if ( V_60 & ~ V_322 )
return - V_281 ;
V_3 -> V_321 = V_60 ;
return 0 ;
}
static int F_275 ( struct V_5 * V_7 ,
struct V_299 * V_300 , V_130 V_60 )
{
return - V_323 ;
}
static int F_276 ( struct V_324 * V_325 , void * V_326 )
{
struct V_327 {
const char * V_328 ;
unsigned int V_72 ;
};
static const struct V_327 V_329 [] = {
{ L_13 , V_330 } ,
{ L_14 , V_161 } ,
{ L_15 , V_162 } ,
{ L_16 , F_70 (LRU_UNEVICTABLE) } ,
} ;
const struct V_327 * V_62 ;
int V_24 ;
unsigned long V_73 ;
struct V_2 * V_3 = F_8 ( F_277 ( V_325 ) ) ;
for ( V_62 = V_329 ; V_62 < V_329 + F_278 ( V_329 ) ; V_62 ++ ) {
V_73 = F_71 ( V_3 , V_62 -> V_72 ) ;
F_279 ( V_325 , L_17 , V_62 -> V_328 , V_73 ) ;
F_72 (nid, N_MEMORY) {
V_73 = F_67 ( V_3 , V_24 ,
V_62 -> V_72 ) ;
F_279 ( V_325 , L_18 , V_24 , V_73 ) ;
}
F_280 ( V_325 , '\n' ) ;
}
for ( V_62 = V_329 ; V_62 < V_329 + F_278 ( V_329 ) ; V_62 ++ ) {
struct V_2 * V_103 ;
V_73 = 0 ;
F_115 (iter, memcg)
V_73 += F_71 ( V_103 , V_62 -> V_72 ) ;
F_279 ( V_325 , L_19 , V_62 -> V_328 , V_73 ) ;
F_72 (nid, N_MEMORY) {
V_73 = 0 ;
F_115 (iter, memcg)
V_73 += F_67 (
V_103 , V_24 , V_62 -> V_72 ) ;
F_279 ( V_325 , L_18 , V_24 , V_73 ) ;
}
F_280 ( V_325 , '\n' ) ;
}
return 0 ;
}
static int F_281 ( struct V_324 * V_325 , void * V_326 )
{
struct V_2 * V_3 = F_8 ( F_277 ( V_325 ) ) ;
unsigned long V_51 , V_119 ;
struct V_2 * V_331 ;
unsigned int V_129 ;
F_282 ( F_278 ( V_135 ) !=
V_133 ) ;
F_282 ( F_278 ( V_332 ) !=
V_333 ) ;
F_282 ( F_278 ( V_137 ) != V_136 ) ;
for ( V_129 = 0 ; V_129 < V_133 ; V_129 ++ ) {
if ( V_129 == V_134 && ! V_118 )
continue;
F_279 ( V_325 , L_20 , V_135 [ V_129 ] ,
F_58 ( V_3 , V_129 ) * V_310 ) ;
}
for ( V_129 = 0 ; V_129 < V_333 ; V_129 ++ )
F_279 ( V_325 , L_20 , V_332 [ V_129 ] ,
F_61 ( V_3 , V_129 ) ) ;
for ( V_129 = 0 ; V_129 < V_136 ; V_129 ++ )
F_279 ( V_325 , L_20 , V_137 [ V_129 ] ,
F_71 ( V_3 , F_70 ( V_129 ) ) * V_310 ) ;
V_51 = V_119 = V_320 ;
for ( V_331 = V_3 ; V_331 ; V_331 = F_32 ( V_331 ) ) {
V_51 = F_98 ( V_51 , V_331 -> V_51 . V_117 ) ;
V_119 = F_98 ( V_119 , V_331 -> V_119 . V_117 ) ;
}
F_279 ( V_325 , L_21 ,
( V_130 ) V_51 * V_310 ) ;
if ( V_118 )
F_279 ( V_325 , L_22 ,
( V_130 ) V_119 * V_310 ) ;
for ( V_129 = 0 ; V_129 < V_133 ; V_129 ++ ) {
unsigned long long V_60 = 0 ;
if ( V_129 == V_134 && ! V_118 )
continue;
F_115 (mi, memcg)
V_60 += F_58 ( V_331 , V_129 ) * V_310 ;
F_279 ( V_325 , L_23 , V_135 [ V_129 ] , V_60 ) ;
}
for ( V_129 = 0 ; V_129 < V_333 ; V_129 ++ ) {
unsigned long long V_60 = 0 ;
F_115 (mi, memcg)
V_60 += F_61 ( V_331 , V_129 ) ;
F_279 ( V_325 , L_23 ,
V_332 [ V_129 ] , V_60 ) ;
}
for ( V_129 = 0 ; V_129 < V_136 ; V_129 ++ ) {
unsigned long long V_60 = 0 ;
F_115 (mi, memcg)
V_60 += F_71 ( V_331 , F_70 ( V_129 ) ) * V_310 ;
F_279 ( V_325 , L_23 , V_137 [ V_129 ] , V_60 ) ;
}
#ifdef F_283
{
int V_24 , V_25 ;
struct V_22 * V_36 ;
struct V_334 * V_335 ;
unsigned long V_336 [ 2 ] = { 0 , 0 } ;
unsigned long V_337 [ 2 ] = { 0 , 0 } ;
F_284 (nid)
for ( V_25 = 0 ; V_25 < V_54 ; V_25 ++ ) {
V_36 = & V_3 -> V_26 [ V_24 ] -> V_27 [ V_25 ] ;
V_335 = & V_36 -> V_112 . V_338 ;
V_336 [ 0 ] += V_335 -> V_336 [ 0 ] ;
V_336 [ 1 ] += V_335 -> V_336 [ 1 ] ;
V_337 [ 0 ] += V_335 -> V_337 [ 0 ] ;
V_337 [ 1 ] += V_335 -> V_337 [ 1 ] ;
}
F_279 ( V_325 , L_24 , V_336 [ 0 ] ) ;
F_279 ( V_325 , L_25 , V_336 [ 1 ] ) ;
F_279 ( V_325 , L_26 , V_337 [ 0 ] ) ;
F_279 ( V_325 , L_27 , V_337 [ 1 ] ) ;
}
#endif
return 0 ;
}
static V_130 F_285 ( struct V_5 * V_7 ,
struct V_299 * V_300 )
{
struct V_2 * V_3 = F_8 ( V_7 ) ;
return F_119 ( V_3 ) ;
}
static int F_286 ( struct V_5 * V_7 ,
struct V_299 * V_300 , V_130 V_60 )
{
struct V_2 * V_3 = F_8 ( V_7 ) ;
if ( V_60 > 100 )
return - V_281 ;
if ( V_7 -> V_42 )
V_3 -> V_339 = V_60 ;
else
V_340 = V_60 ;
return 0 ;
}
static void F_287 ( struct V_2 * V_3 , bool V_304 )
{
struct V_341 * V_342 ;
unsigned long V_343 ;
int V_129 ;
F_12 () ;
if ( ! V_304 )
V_342 = F_82 ( V_3 -> V_344 . V_345 ) ;
else
V_342 = F_82 ( V_3 -> V_346 . V_345 ) ;
if ( ! V_342 )
goto V_123;
V_343 = F_258 ( V_3 , V_304 ) ;
V_129 = V_342 -> V_347 ;
for (; V_129 >= 0 && F_77 ( V_342 -> V_348 [ V_129 ] . V_349 > V_343 ) ; V_129 -- )
F_288 ( V_342 -> V_348 [ V_129 ] . V_350 , 1 ) ;
V_129 ++ ;
for (; V_129 < V_342 -> V_255 && F_77 ( V_342 -> V_348 [ V_129 ] . V_349 <= V_343 ) ; V_129 ++ )
F_288 ( V_342 -> V_348 [ V_129 ] . V_350 , 1 ) ;
V_342 -> V_347 = V_129 - 1 ;
V_123:
F_16 () ;
}
static void F_78 ( struct V_2 * V_3 )
{
while ( V_3 ) {
F_287 ( V_3 , false ) ;
if ( V_118 )
F_287 ( V_3 , true ) ;
V_3 = F_32 ( V_3 ) ;
}
}
static int F_289 ( const void * V_351 , const void * V_352 )
{
const struct F_78 * V_353 = V_351 ;
const struct F_78 * V_354 = V_352 ;
if ( V_353 -> V_349 > V_354 -> V_349 )
return 1 ;
if ( V_353 -> V_349 < V_354 -> V_349 )
return - 1 ;
return 0 ;
}
static int F_290 ( struct V_2 * V_3 )
{
struct V_355 * V_356 ;
F_100 ( & V_177 ) ;
F_291 (ev, &memcg->oom_notify, list)
F_288 ( V_356 -> V_350 , 1 ) ;
F_101 ( & V_177 ) ;
return 0 ;
}
static void F_160 ( struct V_2 * V_3 )
{
struct V_2 * V_103 ;
F_115 (iter, memcg)
F_290 ( V_103 ) ;
}
static int F_292 ( struct V_2 * V_3 ,
struct V_357 * V_350 , const char * args , enum V_358 type )
{
struct V_359 * V_344 ;
struct V_341 * V_360 ;
unsigned long V_349 ;
unsigned long V_343 ;
int V_129 , V_255 , V_115 ;
V_115 = F_270 ( args , L_12 , & V_349 ) ;
if ( V_115 )
return V_115 ;
V_349 <<= V_305 ;
F_109 ( & V_3 -> V_361 ) ;
if ( type == V_306 ) {
V_344 = & V_3 -> V_344 ;
V_343 = F_258 ( V_3 , false ) ;
} else if ( type == V_307 ) {
V_344 = & V_3 -> V_346 ;
V_343 = F_258 ( V_3 , true ) ;
} else
F_261 () ;
if ( V_344 -> V_345 )
F_287 ( V_3 , type == V_307 ) ;
V_255 = V_344 -> V_345 ? V_344 -> V_345 -> V_255 + 1 : 1 ;
V_360 = F_220 ( sizeof( * V_360 ) + V_255 * sizeof( struct F_78 ) ,
V_259 ) ;
if ( ! V_360 ) {
V_115 = - V_247 ;
goto V_123;
}
V_360 -> V_255 = V_255 ;
if ( V_344 -> V_345 ) {
memcpy ( V_360 -> V_348 , V_344 -> V_345 -> V_348 , ( V_255 - 1 ) *
sizeof( struct F_78 ) ) ;
}
V_360 -> V_348 [ V_255 - 1 ] . V_350 = V_350 ;
V_360 -> V_348 [ V_255 - 1 ] . V_349 = V_349 ;
F_293 ( V_360 -> V_348 , V_255 , sizeof( struct F_78 ) ,
F_289 , NULL ) ;
V_360 -> V_347 = - 1 ;
for ( V_129 = 0 ; V_129 < V_255 ; V_129 ++ ) {
if ( V_360 -> V_348 [ V_129 ] . V_349 <= V_343 ) {
++ V_360 -> V_347 ;
} else
break;
}
F_218 ( V_344 -> V_362 ) ;
V_344 -> V_362 = V_344 -> V_345 ;
F_294 ( V_344 -> V_345 , V_360 ) ;
F_295 () ;
V_123:
F_116 ( & V_3 -> V_361 ) ;
return V_115 ;
}
static int F_296 ( struct V_2 * V_3 ,
struct V_357 * V_350 , const char * args )
{
return F_292 ( V_3 , V_350 , args , V_306 ) ;
}
static int F_297 ( struct V_2 * V_3 ,
struct V_357 * V_350 , const char * args )
{
return F_292 ( V_3 , V_350 , args , V_307 ) ;
}
static void F_298 ( struct V_2 * V_3 ,
struct V_357 * V_350 , enum V_358 type )
{
struct V_359 * V_344 ;
struct V_341 * V_360 ;
unsigned long V_343 ;
int V_129 , V_363 , V_255 ;
F_109 ( & V_3 -> V_361 ) ;
if ( type == V_306 ) {
V_344 = & V_3 -> V_344 ;
V_343 = F_258 ( V_3 , false ) ;
} else if ( type == V_307 ) {
V_344 = & V_3 -> V_346 ;
V_343 = F_258 ( V_3 , true ) ;
} else
F_261 () ;
if ( ! V_344 -> V_345 )
goto V_123;
F_287 ( V_3 , type == V_307 ) ;
V_255 = 0 ;
for ( V_129 = 0 ; V_129 < V_344 -> V_345 -> V_255 ; V_129 ++ ) {
if ( V_344 -> V_345 -> V_348 [ V_129 ] . V_350 != V_350 )
V_255 ++ ;
}
V_360 = V_344 -> V_362 ;
if ( ! V_255 ) {
F_218 ( V_360 ) ;
V_360 = NULL ;
goto V_364;
}
V_360 -> V_255 = V_255 ;
V_360 -> V_347 = - 1 ;
for ( V_129 = 0 , V_363 = 0 ; V_129 < V_344 -> V_345 -> V_255 ; V_129 ++ ) {
if ( V_344 -> V_345 -> V_348 [ V_129 ] . V_350 == V_350 )
continue;
V_360 -> V_348 [ V_363 ] = V_344 -> V_345 -> V_348 [ V_129 ] ;
if ( V_360 -> V_348 [ V_363 ] . V_349 <= V_343 ) {
++ V_360 -> V_347 ;
}
V_363 ++ ;
}
V_364:
V_344 -> V_362 = V_344 -> V_345 ;
if ( ! V_360 ) {
F_218 ( V_344 -> V_362 ) ;
V_344 -> V_362 = NULL ;
}
F_294 ( V_344 -> V_345 , V_360 ) ;
F_295 () ;
V_123:
F_116 ( & V_3 -> V_361 ) ;
}
static void F_299 ( struct V_2 * V_3 ,
struct V_357 * V_350 )
{
return F_298 ( V_3 , V_350 , V_306 ) ;
}
static void F_300 ( struct V_2 * V_3 ,
struct V_357 * V_350 )
{
return F_298 ( V_3 , V_350 , V_307 ) ;
}
static int F_301 ( struct V_2 * V_3 ,
struct V_357 * V_350 , const char * args )
{
struct V_355 * V_365 ;
V_365 = F_220 ( sizeof( * V_365 ) , V_259 ) ;
if ( ! V_365 )
return - V_247 ;
F_100 ( & V_177 ) ;
V_365 -> V_350 = V_350 ;
F_302 ( & V_365 -> V_366 , & V_3 -> V_367 ) ;
if ( V_3 -> V_180 )
F_288 ( V_350 , 1 ) ;
F_101 ( & V_177 ) ;
return 0 ;
}
static void F_303 ( struct V_2 * V_3 ,
struct V_357 * V_350 )
{
struct V_355 * V_356 , * V_368 ;
F_100 ( & V_177 ) ;
F_304 (ev, tmp, &memcg->oom_notify, list) {
if ( V_356 -> V_350 == V_350 ) {
F_305 ( & V_356 -> V_366 ) ;
F_218 ( V_356 ) ;
}
}
F_101 ( & V_177 ) ;
}
static int F_306 ( struct V_324 * V_369 , void * V_326 )
{
struct V_2 * V_3 = F_8 ( F_277 ( V_369 ) ) ;
F_279 ( V_369 , L_28 , V_3 -> V_201 ) ;
F_279 ( V_369 , L_29 , ( bool ) V_3 -> V_180 ) ;
return 0 ;
}
static int F_307 ( struct V_5 * V_7 ,
struct V_299 * V_300 , V_130 V_60 )
{
struct V_2 * V_3 = F_8 ( V_7 ) ;
if ( ! V_7 -> V_42 || ! ( ( V_60 == 0 ) || ( V_60 == 1 ) ) )
return - V_281 ;
V_3 -> V_201 = V_60 ;
if ( ! V_60 )
F_155 ( V_3 ) ;
return 0 ;
}
static int F_308 ( struct V_2 * V_3 , struct V_370 * V_371 )
{
int V_115 ;
V_115 = F_267 ( V_3 ) ;
if ( V_115 )
return V_115 ;
return F_309 ( V_3 , V_371 ) ;
}
static void F_310 ( struct V_2 * V_3 )
{
struct V_5 * V_7 ;
struct V_2 * V_42 , * V_372 ;
int V_270 ;
if ( ! V_3 -> V_318 )
return;
V_3 -> V_318 = false ;
F_311 ( V_3 ) ;
V_270 = V_3 -> V_270 ;
F_10 ( V_270 < 0 ) ;
V_42 = F_32 ( V_3 ) ;
if ( ! V_42 )
V_42 = V_4 ;
F_312 (css, &memcg->css) {
V_372 = F_8 ( V_7 ) ;
F_10 ( V_372 -> V_270 != V_270 ) ;
V_372 -> V_270 = V_42 -> V_270 ;
if ( ! V_3 -> V_105 )
break;
}
F_313 ( V_270 , V_42 -> V_270 ) ;
F_215 ( V_270 ) ;
}
static void F_314 ( struct V_2 * V_3 )
{
if ( V_3 -> V_317 ) {
F_315 ( V_3 ) ;
F_316 ( & V_319 ) ;
F_18 ( F_49 ( & V_3 -> V_132 ) ) ;
}
F_317 ( V_3 ) ;
}
static int F_308 ( struct V_2 * V_3 , struct V_370 * V_371 )
{
return 0 ;
}
static void F_310 ( struct V_2 * V_3 )
{
}
static void F_314 ( struct V_2 * V_3 )
{
}
struct V_373 * F_318 ( struct V_2 * V_3 )
{
return & V_3 -> V_374 ;
}
static int F_319 ( struct V_2 * V_3 , T_3 V_254 )
{
return F_320 ( & V_3 -> V_375 , V_254 ) ;
}
static void F_321 ( struct V_2 * V_3 )
{
F_322 ( & V_3 -> V_375 ) ;
}
static void F_323 ( struct V_2 * V_3 )
{
F_324 ( & V_3 -> V_375 ) ;
}
struct V_376 * F_325 ( struct V_377 * V_378 )
{
struct V_2 * V_3 = F_8 ( V_378 -> V_379 ) ;
if ( ! V_3 -> V_7 . V_42 )
return NULL ;
return & V_3 -> V_375 ;
}
void F_326 ( struct V_377 * V_378 , unsigned long * V_380 ,
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
unsigned long V_388 = F_98 ( V_3 -> V_51 . V_117 , V_3 -> V_249 ) ;
unsigned long V_389 = F_49 ( & V_3 -> V_51 ) ;
* V_381 = F_98 ( * V_381 , V_388 - F_98 ( V_388 , V_389 ) ) ;
V_3 = V_42 ;
}
}
static int F_319 ( struct V_2 * V_3 , T_3 V_254 )
{
return 0 ;
}
static void F_321 ( struct V_2 * V_3 )
{
}
static void F_323 ( struct V_2 * V_3 )
{
}
static void F_327 ( struct V_213 * V_218 )
{
struct V_390 * V_365 =
F_3 ( V_218 , struct V_390 , remove ) ;
struct V_2 * V_3 = V_365 -> V_3 ;
F_328 ( V_365 -> V_391 , & V_365 -> V_125 ) ;
V_365 -> V_392 ( V_3 , V_365 -> V_350 ) ;
F_288 ( V_365 -> V_350 , 1 ) ;
F_329 ( V_365 -> V_350 ) ;
F_218 ( V_365 ) ;
F_19 ( & V_3 -> V_7 ) ;
}
static int F_330 ( T_4 * V_125 , unsigned V_181 ,
int V_182 , void * V_393 )
{
struct V_390 * V_365 =
F_3 ( V_125 , struct V_390 , V_125 ) ;
struct V_2 * V_3 = V_365 -> V_3 ;
unsigned long V_19 = ( unsigned long ) V_393 ;
if ( V_19 & V_394 ) {
F_100 ( & V_3 -> V_395 ) ;
if ( ! F_331 ( & V_365 -> V_366 ) ) {
F_332 ( & V_365 -> V_366 ) ;
F_222 ( & V_365 -> remove ) ;
}
F_101 ( & V_3 -> V_395 ) ;
}
return 0 ;
}
static void F_333 ( struct V_396 * V_396 ,
T_9 * V_391 , T_10 * V_397 )
{
struct V_390 * V_365 =
F_3 ( V_397 , struct V_390 , V_397 ) ;
V_365 -> V_391 = V_391 ;
F_334 ( V_391 , & V_365 -> V_125 ) ;
}
static T_6 F_335 ( struct V_294 * V_295 ,
char * V_296 , T_7 V_297 , T_8 V_298 )
{
struct V_5 * V_7 = F_254 ( V_295 ) ;
struct V_2 * V_3 = F_8 ( V_7 ) ;
struct V_390 * V_365 ;
struct V_5 * V_398 ;
unsigned int V_399 , V_400 ;
struct V_401 V_402 ;
struct V_401 V_403 ;
const char * V_328 ;
char * V_404 ;
int V_115 ;
V_296 = F_269 ( V_296 ) ;
V_399 = F_336 ( V_296 , & V_404 , 10 ) ;
if ( * V_404 != ' ' )
return - V_281 ;
V_296 = V_404 + 1 ;
V_400 = F_336 ( V_296 , & V_404 , 10 ) ;
if ( ( * V_404 != ' ' ) && ( * V_404 != '\0' ) )
return - V_281 ;
V_296 = V_404 + 1 ;
V_365 = F_337 ( sizeof( * V_365 ) , V_259 ) ;
if ( ! V_365 )
return - V_247 ;
V_365 -> V_3 = V_3 ;
F_159 ( & V_365 -> V_366 ) ;
F_338 ( & V_365 -> V_397 , F_333 ) ;
F_339 ( & V_365 -> V_125 , F_330 ) ;
F_221 ( & V_365 -> remove , F_327 ) ;
V_402 = F_340 ( V_399 ) ;
if ( ! V_402 . V_396 ) {
V_115 = - V_405 ;
goto V_406;
}
V_365 -> V_350 = F_341 ( V_402 . V_396 ) ;
if ( F_342 ( V_365 -> V_350 ) ) {
V_115 = F_343 ( V_365 -> V_350 ) ;
goto V_407;
}
V_403 = F_340 ( V_400 ) ;
if ( ! V_403 . V_396 ) {
V_115 = - V_405 ;
goto V_408;
}
V_115 = F_344 ( F_345 ( V_403 . V_396 ) , V_409 ) ;
if ( V_115 < 0 )
goto V_410;
V_328 = V_403 . V_396 -> V_411 . V_412 -> V_413 . V_328 ;
if ( ! strcmp ( V_328 , L_30 ) ) {
V_365 -> V_414 = F_296 ;
V_365 -> V_392 = F_299 ;
} else if ( ! strcmp ( V_328 , L_31 ) ) {
V_365 -> V_414 = F_301 ;
V_365 -> V_392 = F_303 ;
} else if ( ! strcmp ( V_328 , L_32 ) ) {
V_365 -> V_414 = V_415 ;
V_365 -> V_392 = V_416 ;
} else if ( ! strcmp ( V_328 , L_33 ) ) {
V_365 -> V_414 = F_297 ;
V_365 -> V_392 = F_300 ;
} else {
V_115 = - V_281 ;
goto V_410;
}
V_398 = F_346 ( V_403 . V_396 -> V_411 . V_412 -> V_417 ,
& V_9 ) ;
V_115 = - V_281 ;
if ( F_342 ( V_398 ) )
goto V_410;
if ( V_398 != V_7 ) {
F_19 ( V_398 ) ;
goto V_410;
}
V_115 = V_365 -> V_414 ( V_3 , V_365 -> V_350 , V_296 ) ;
if ( V_115 )
goto V_418;
V_402 . V_396 -> V_419 -> V_420 ( V_402 . V_396 , & V_365 -> V_397 ) ;
F_100 ( & V_3 -> V_395 ) ;
F_302 ( & V_365 -> V_366 , & V_3 -> V_421 ) ;
F_101 ( & V_3 -> V_395 ) ;
F_347 ( V_403 ) ;
F_347 ( V_402 ) ;
return V_297 ;
V_418:
F_19 ( V_7 ) ;
V_410:
F_347 ( V_403 ) ;
V_408:
F_329 ( V_365 -> V_350 ) ;
V_407:
F_347 ( V_402 ) ;
V_406:
F_218 ( V_365 ) ;
return V_115 ;
}
static int F_348 ( struct V_2 * V_3 , int V_167 )
{
struct V_422 * V_423 ;
struct V_22 * V_36 ;
int V_23 , V_368 = V_167 ;
if ( ! F_349 ( V_167 , V_424 ) )
V_368 = - 1 ;
V_423 = F_350 ( sizeof( * V_423 ) , V_259 , V_368 ) ;
if ( ! V_423 )
return 1 ;
for ( V_23 = 0 ; V_23 < V_54 ; V_23 ++ ) {
V_36 = & V_423 -> V_27 [ V_23 ] ;
F_351 ( & V_36 -> V_112 ) ;
V_36 -> V_45 = 0 ;
V_36 -> V_44 = false ;
V_36 -> V_3 = V_3 ;
}
V_3 -> V_26 [ V_167 ] = V_423 ;
return 0 ;
}
static void F_352 ( struct V_2 * V_3 , int V_167 )
{
F_218 ( V_3 -> V_26 [ V_167 ] ) ;
}
static struct V_2 * F_353 ( void )
{
struct V_2 * V_3 ;
T_7 V_255 ;
V_255 = sizeof( struct V_2 ) ;
V_255 += V_74 * sizeof( struct V_422 * ) ;
V_3 = F_337 ( V_255 , V_259 ) ;
if ( ! V_3 )
return NULL ;
V_3 -> V_62 = F_354 ( struct V_425 ) ;
if ( ! V_3 -> V_62 )
goto V_426;
if ( F_319 ( V_3 , V_259 ) )
goto V_427;
return V_3 ;
V_427:
F_355 ( V_3 -> V_62 ) ;
V_426:
F_218 ( V_3 ) ;
return NULL ;
}
static void F_356 ( struct V_2 * V_3 )
{
int V_167 ;
F_51 ( V_3 ) ;
F_52 (node)
F_352 ( V_3 , V_167 ) ;
F_355 ( V_3 -> V_62 ) ;
F_321 ( V_3 ) ;
F_218 ( V_3 ) ;
}
struct V_2 * F_32 ( struct V_2 * V_3 )
{
if ( ! V_3 -> V_51 . V_42 )
return NULL ;
return F_186 ( V_3 -> V_51 . V_42 , V_51 ) ;
}
static struct V_5 * T_11
F_357 ( struct V_5 * V_428 )
{
struct V_2 * V_3 ;
long error = - V_247 ;
int V_167 ;
V_3 = F_353 () ;
if ( ! V_3 )
return F_358 ( error ) ;
F_52 (node)
if ( F_348 ( V_3 , V_167 ) )
goto V_429;
if ( V_428 == NULL ) {
V_4 = V_3 ;
V_430 = & V_3 -> V_7 ;
F_359 ( & V_3 -> V_51 , NULL ) ;
V_3 -> V_249 = V_320 ;
V_3 -> V_52 = V_320 ;
F_359 ( & V_3 -> V_119 , NULL ) ;
F_359 ( & V_3 -> V_132 , NULL ) ;
}
V_3 -> V_168 = V_90 ;
F_159 ( & V_3 -> V_367 ) ;
V_3 -> V_321 = 0 ;
F_360 ( & V_3 -> V_361 ) ;
F_361 ( & V_3 -> V_204 ) ;
F_362 ( & V_3 -> V_1 ) ;
F_159 ( & V_3 -> V_421 ) ;
F_361 ( & V_3 -> V_395 ) ;
#ifdef F_363
V_3 -> V_270 = - 1 ;
#endif
#ifdef F_364
F_159 ( & V_3 -> V_374 ) ;
#endif
return & V_3 -> V_7 ;
V_429:
F_356 ( V_3 ) ;
return F_358 ( error ) ;
}
static int
F_365 ( struct V_5 * V_7 )
{
struct V_2 * V_3 = F_8 ( V_7 ) ;
struct V_2 * V_42 = F_8 ( V_7 -> V_42 ) ;
int V_115 ;
if ( V_7 -> V_8 > V_431 )
return - V_432 ;
if ( ! V_42 )
return 0 ;
F_109 ( & V_290 ) ;
V_3 -> V_105 = V_42 -> V_105 ;
V_3 -> V_201 = V_42 -> V_201 ;
V_3 -> V_339 = F_119 ( V_42 ) ;
if ( V_42 -> V_105 ) {
F_359 ( & V_3 -> V_51 , & V_42 -> V_51 ) ;
V_3 -> V_249 = V_320 ;
V_3 -> V_52 = V_320 ;
F_359 ( & V_3 -> V_119 , & V_42 -> V_119 ) ;
F_359 ( & V_3 -> V_132 , & V_42 -> V_132 ) ;
} else {
F_359 ( & V_3 -> V_51 , NULL ) ;
V_3 -> V_249 = V_320 ;
V_3 -> V_52 = V_320 ;
F_359 ( & V_3 -> V_119 , NULL ) ;
F_359 ( & V_3 -> V_132 , NULL ) ;
if ( V_42 != V_4 )
V_9 . V_433 = true ;
}
F_116 ( & V_290 ) ;
V_115 = F_308 ( V_3 , & V_9 ) ;
if ( V_115 )
return V_115 ;
F_366 ( & V_3 -> V_111 , 1 ) ;
return 0 ;
}
static void F_367 ( struct V_5 * V_7 )
{
struct V_2 * V_3 = F_8 ( V_7 ) ;
struct V_390 * V_365 , * V_368 ;
F_100 ( & V_3 -> V_395 ) ;
F_304 (event, tmp, &memcg->event_list, list) {
F_332 ( & V_365 -> V_366 ) ;
F_222 ( & V_365 -> remove ) ;
}
F_101 ( & V_3 -> V_395 ) ;
F_368 ( & V_3 -> V_1 ) ;
F_310 ( V_3 ) ;
F_369 ( V_3 ) ;
}
static void F_370 ( struct V_5 * V_7 )
{
struct V_2 * V_3 = F_8 ( V_7 ) ;
F_314 ( V_3 ) ;
F_356 ( V_3 ) ;
}
static void F_371 ( struct V_5 * V_7 )
{
struct V_2 * V_3 = F_8 ( V_7 ) ;
F_242 ( V_3 , V_320 ) ;
F_245 ( V_3 , V_320 ) ;
F_266 ( V_3 , V_320 ) ;
V_3 -> V_434 = 0 ;
V_3 -> V_249 = V_320 ;
V_3 -> V_52 = V_320 ;
F_323 ( V_3 ) ;
}
static int F_372 ( unsigned long V_63 )
{
int V_115 ;
V_115 = F_183 ( V_122 . V_121 , V_259 & ~ V_241 , V_63 ) ;
if ( ! V_115 ) {
V_122 . V_435 += V_63 ;
return V_115 ;
}
if ( V_115 == - V_248 ) {
F_193 ( V_4 , V_63 ) ;
return V_115 ;
}
while ( V_63 -- ) {
V_115 = F_183 ( V_122 . V_121 , V_259 & ~ V_243 , 1 ) ;
if ( V_115 == - V_248 )
F_193 ( V_4 , 1 ) ;
if ( V_115 )
return V_115 ;
V_122 . V_435 ++ ;
F_373 () ;
}
return 0 ;
}
static struct V_28 * F_374 ( struct V_436 * V_437 ,
unsigned long V_438 , T_12 V_439 )
{
struct V_28 * V_28 = F_375 ( V_437 , V_438 , V_439 ) ;
if ( ! V_28 || ! F_376 ( V_28 ) )
return NULL ;
if ( F_63 ( V_28 ) ) {
if ( ! ( V_122 . V_19 & V_440 ) )
return NULL ;
} else {
if ( ! ( V_122 . V_19 & V_441 ) )
return NULL ;
}
if ( ! F_377 ( V_28 ) )
return NULL ;
return V_28 ;
}
static struct V_28 * F_378 ( struct V_436 * V_437 ,
unsigned long V_438 , T_12 V_439 , T_5 * V_278 )
{
struct V_28 * V_28 = NULL ;
T_5 V_442 = F_379 ( V_439 ) ;
if ( ! ( V_122 . V_19 & V_440 ) || F_380 ( V_442 ) )
return NULL ;
V_28 = F_381 ( F_382 ( V_442 ) , V_442 . V_60 ) ;
if ( V_118 )
V_278 -> V_60 = V_442 . V_60 ;
return V_28 ;
}
static struct V_28 * F_378 ( struct V_436 * V_437 ,
unsigned long V_438 , T_12 V_439 , T_5 * V_278 )
{
return NULL ;
}
static struct V_28 * F_383 ( struct V_436 * V_437 ,
unsigned long V_438 , T_12 V_439 , T_5 * V_278 )
{
struct V_28 * V_28 = NULL ;
struct V_443 * V_444 ;
T_13 V_445 ;
if ( ! V_437 -> V_446 )
return NULL ;
if ( ! ( V_122 . V_19 & V_441 ) )
return NULL ;
V_444 = V_437 -> V_446 -> V_447 ;
V_445 = F_384 ( V_437 , V_438 ) ;
#ifdef F_385
if ( F_386 ( V_444 ) ) {
V_28 = F_387 ( V_444 , V_445 ) ;
if ( F_388 ( V_28 ) ) {
T_5 V_448 = F_389 ( V_28 ) ;
if ( V_118 )
* V_278 = V_448 ;
V_28 = F_381 ( F_382 ( V_448 ) , V_448 . V_60 ) ;
}
} else
V_28 = F_381 ( V_444 , V_445 ) ;
#else
V_28 = F_381 ( V_444 , V_445 ) ;
#endif
return V_28 ;
}
static int F_390 ( struct V_28 * V_28 ,
unsigned int V_50 ,
struct V_2 * V_120 ,
struct V_2 * V_121 )
{
unsigned long V_19 ;
int V_115 ;
bool V_449 ;
F_68 ( V_120 == V_121 ) ;
F_201 ( F_196 ( V_28 ) , V_28 ) ;
V_115 = - V_303 ;
if ( V_50 > 1 && ! F_65 ( V_28 ) )
goto V_106;
if ( ! F_391 ( V_28 ) )
goto V_106;
V_115 = - V_281 ;
if ( V_28 -> V_2 != V_120 )
goto V_109;
V_449 = F_63 ( V_28 ) ;
F_46 ( & V_120 -> V_204 , V_19 ) ;
if ( ! V_449 && F_376 ( V_28 ) ) {
F_237 ( V_120 -> V_62 -> V_63 [ V_450 ] ,
V_50 ) ;
F_64 ( V_121 -> V_62 -> V_63 [ V_450 ] ,
V_50 ) ;
}
if ( ! V_449 && F_392 ( V_28 ) ) {
struct V_443 * V_444 = F_393 ( V_28 ) ;
if ( F_394 ( V_444 ) ) {
F_237 ( V_120 -> V_62 -> V_63 [ V_384 ] ,
V_50 ) ;
F_64 ( V_121 -> V_62 -> V_63 [ V_384 ] ,
V_50 ) ;
}
}
if ( F_395 ( V_28 ) ) {
F_237 ( V_120 -> V_62 -> V_63 [ V_385 ] ,
V_50 ) ;
F_64 ( V_121 -> V_62 -> V_63 [ V_385 ] ,
V_50 ) ;
}
V_28 -> V_2 = V_121 ;
F_47 ( & V_120 -> V_204 , V_19 ) ;
V_115 = 0 ;
F_396 () ;
F_62 ( V_121 , V_28 , V_50 ) ;
F_76 ( V_121 , V_28 ) ;
F_62 ( V_120 , V_28 , - V_50 ) ;
F_76 ( V_120 , V_28 ) ;
F_397 () ;
V_109:
F_398 ( V_28 ) ;
V_106:
return V_115 ;
}
static enum V_451 F_399 ( struct V_436 * V_437 ,
unsigned long V_438 , T_12 V_439 , union V_452 * V_79 )
{
struct V_28 * V_28 = NULL ;
enum V_451 V_115 = V_453 ;
T_5 V_442 = { . V_60 = 0 } ;
if ( F_400 ( V_439 ) )
V_28 = F_374 ( V_437 , V_438 , V_439 ) ;
else if ( F_401 ( V_439 ) )
V_28 = F_378 ( V_437 , V_438 , V_439 , & V_442 ) ;
else if ( F_402 ( V_439 ) )
V_28 = F_383 ( V_437 , V_438 , V_439 , & V_442 ) ;
if ( ! V_28 && ! V_442 . V_60 )
return V_115 ;
if ( V_28 ) {
if ( V_28 -> V_2 == V_122 . V_120 ) {
V_115 = V_454 ;
if ( V_79 )
V_79 -> V_28 = V_28 ;
}
if ( ! V_115 || ! V_79 )
F_403 ( V_28 ) ;
}
if ( V_442 . V_60 && ! V_115 &&
F_5 ( V_122 . V_120 ) == F_404 ( V_442 ) ) {
V_115 = V_455 ;
if ( V_79 )
V_79 -> V_442 = V_442 ;
}
return V_115 ;
}
static enum V_451 F_405 ( struct V_436 * V_437 ,
unsigned long V_438 , T_14 V_456 , union V_452 * V_79 )
{
struct V_28 * V_28 = NULL ;
enum V_451 V_115 = V_453 ;
V_28 = F_406 ( V_456 ) ;
F_201 ( ! V_28 || ! F_407 ( V_28 ) , V_28 ) ;
if ( ! ( V_122 . V_19 & V_440 ) )
return V_115 ;
if ( V_28 -> V_2 == V_122 . V_120 ) {
V_115 = V_454 ;
if ( V_79 ) {
F_408 ( V_28 ) ;
V_79 -> V_28 = V_28 ;
}
}
return V_115 ;
}
static inline enum V_451 F_405 ( struct V_436 * V_437 ,
unsigned long V_438 , T_14 V_456 , union V_452 * V_79 )
{
return V_453 ;
}
static int F_409 ( T_14 * V_456 ,
unsigned long V_438 , unsigned long V_457 ,
struct V_458 * V_459 )
{
struct V_436 * V_437 = V_459 -> V_437 ;
T_12 * V_460 ;
T_15 * V_461 ;
if ( F_410 ( V_456 , V_437 , & V_461 ) == 1 ) {
if ( F_405 ( V_437 , V_438 , * V_456 , NULL ) == V_454 )
V_122 . V_435 += V_276 ;
F_101 ( V_461 ) ;
return 0 ;
}
if ( F_411 ( V_456 ) )
return 0 ;
V_460 = F_412 ( V_437 -> V_462 , V_456 , V_438 , & V_461 ) ;
for (; V_438 != V_457 ; V_460 ++ , V_438 += V_310 )
if ( F_399 ( V_437 , V_438 , * V_460 , NULL ) )
V_122 . V_435 ++ ;
F_413 ( V_460 - 1 , V_461 ) ;
F_373 () ;
return 0 ;
}
static unsigned long F_414 ( struct V_94 * V_95 )
{
unsigned long V_435 ;
struct V_458 V_463 = {
. V_464 = F_409 ,
. V_95 = V_95 ,
} ;
F_22 ( & V_95 -> V_465 ) ;
F_415 ( 0 , ~ 0UL , & V_463 ) ;
F_24 ( & V_95 -> V_465 ) ;
V_435 = V_122 . V_435 ;
V_122 . V_435 = 0 ;
return V_435 ;
}
static int F_416 ( struct V_94 * V_95 )
{
unsigned long V_435 = F_414 ( V_95 ) ;
F_68 ( V_122 . V_124 ) ;
V_122 . V_124 = V_17 ;
return F_372 ( V_435 ) ;
}
static void F_417 ( void )
{
struct V_2 * V_120 = V_122 . V_120 ;
struct V_2 * V_121 = V_122 . V_121 ;
if ( V_122 . V_435 ) {
F_193 ( V_122 . V_121 , V_122 . V_435 ) ;
V_122 . V_435 = 0 ;
}
if ( V_122 . V_466 ) {
F_193 ( V_122 . V_120 , V_122 . V_466 ) ;
V_122 . V_466 = 0 ;
}
if ( V_122 . V_467 ) {
if ( ! F_4 ( V_122 . V_120 ) )
F_167 ( & V_122 . V_120 -> V_119 , V_122 . V_467 ) ;
if ( ! F_4 ( V_122 . V_121 ) )
F_167 ( & V_122 . V_121 -> V_51 , V_122 . V_467 ) ;
F_168 ( & V_122 . V_120 -> V_7 , V_122 . V_467 ) ;
V_122 . V_467 = 0 ;
}
F_155 ( V_120 ) ;
F_155 ( V_121 ) ;
F_418 ( & V_122 . V_126 ) ;
}
static void F_419 ( void )
{
V_122 . V_124 = NULL ;
F_417 () ;
F_100 ( & V_122 . V_49 ) ;
V_122 . V_120 = NULL ;
V_122 . V_121 = NULL ;
F_101 ( & V_122 . V_49 ) ;
}
static int F_420 ( struct V_5 * V_7 ,
struct V_468 * V_469 )
{
struct V_2 * V_3 = F_8 ( V_7 ) ;
struct V_2 * V_120 ;
struct V_92 * V_40 ;
struct V_94 * V_95 ;
unsigned long V_470 ;
int V_115 = 0 ;
V_470 = F_31 ( V_3 -> V_321 ) ;
if ( ! V_470 )
return 0 ;
V_40 = F_421 ( V_469 ) ;
V_120 = F_13 ( V_40 ) ;
F_68 ( V_120 == V_3 ) ;
V_95 = F_422 ( V_40 ) ;
if ( ! V_95 )
return 0 ;
if ( V_95 -> V_96 == V_40 ) {
F_68 ( V_122 . V_120 ) ;
F_68 ( V_122 . V_121 ) ;
F_68 ( V_122 . V_435 ) ;
F_68 ( V_122 . V_466 ) ;
F_68 ( V_122 . V_467 ) ;
F_100 ( & V_122 . V_49 ) ;
V_122 . V_120 = V_120 ;
V_122 . V_121 = V_3 ;
V_122 . V_19 = V_470 ;
F_101 ( & V_122 . V_49 ) ;
V_115 = F_416 ( V_95 ) ;
if ( V_115 )
F_419 () ;
}
F_423 ( V_95 ) ;
return V_115 ;
}
static void F_424 ( struct V_5 * V_7 ,
struct V_468 * V_469 )
{
if ( V_122 . V_121 )
F_419 () ;
}
static int F_425 ( T_14 * V_456 ,
unsigned long V_438 , unsigned long V_457 ,
struct V_458 * V_459 )
{
int V_115 = 0 ;
struct V_436 * V_437 = V_459 -> V_437 ;
T_12 * V_460 ;
T_15 * V_461 ;
enum V_451 V_471 ;
union V_452 V_79 ;
struct V_28 * V_28 ;
if ( F_410 ( V_456 , V_437 , & V_461 ) == 1 ) {
if ( V_122 . V_435 < V_276 ) {
F_101 ( V_461 ) ;
return 0 ;
}
V_471 = F_405 ( V_437 , V_438 , * V_456 , & V_79 ) ;
if ( V_471 == V_454 ) {
V_28 = V_79 . V_28 ;
if ( ! F_426 ( V_28 ) ) {
if ( ! F_390 ( V_28 , V_276 ,
V_122 . V_120 , V_122 . V_121 ) ) {
V_122 . V_435 -= V_276 ;
V_122 . V_466 += V_276 ;
}
F_427 ( V_28 ) ;
}
F_403 ( V_28 ) ;
}
F_101 ( V_461 ) ;
return 0 ;
}
if ( F_411 ( V_456 ) )
return 0 ;
V_56:
V_460 = F_412 ( V_437 -> V_462 , V_456 , V_438 , & V_461 ) ;
for (; V_438 != V_457 ; V_438 += V_310 ) {
T_12 V_439 = * ( V_460 ++ ) ;
T_5 V_442 ;
if ( ! V_122 . V_435 )
break;
switch ( F_399 ( V_437 , V_438 , V_439 , & V_79 ) ) {
case V_454 :
V_28 = V_79 . V_28 ;
if ( F_426 ( V_28 ) )
goto V_472;
if ( ! F_390 ( V_28 , 1 , V_122 . V_120 , V_122 . V_121 ) ) {
V_122 . V_435 -- ;
V_122 . V_466 ++ ;
}
F_427 ( V_28 ) ;
V_472:
F_403 ( V_28 ) ;
break;
case V_455 :
V_442 = V_79 . V_442 ;
if ( ! F_240 ( V_442 , V_122 . V_120 , V_122 . V_121 ) ) {
V_122 . V_435 -- ;
V_122 . V_467 ++ ;
}
break;
default:
break;
}
}
F_413 ( V_460 - 1 , V_461 ) ;
F_373 () ;
if ( V_438 != V_457 ) {
V_115 = F_372 ( 1 ) ;
if ( ! V_115 )
goto V_56;
}
return V_115 ;
}
static void F_428 ( struct V_94 * V_95 )
{
struct V_458 V_473 = {
. V_464 = F_425 ,
. V_95 = V_95 ,
} ;
F_251 () ;
F_79 ( & V_122 . V_120 -> V_203 ) ;
F_295 () ;
V_56:
if ( F_77 ( ! F_429 ( & V_95 -> V_465 ) ) ) {
F_417 () ;
F_373 () ;
goto V_56;
}
F_415 ( 0 , ~ 0UL , & V_473 ) ;
F_24 ( & V_95 -> V_465 ) ;
F_430 ( & V_122 . V_120 -> V_203 ) ;
}
static void F_431 ( struct V_5 * V_7 ,
struct V_468 * V_469 )
{
struct V_92 * V_40 = F_421 ( V_469 ) ;
struct V_94 * V_95 = F_422 ( V_40 ) ;
if ( V_95 ) {
if ( V_122 . V_121 )
F_428 ( V_95 ) ;
F_423 ( V_95 ) ;
}
if ( V_122 . V_121 )
F_419 () ;
}
static int F_420 ( struct V_5 * V_7 ,
struct V_468 * V_469 )
{
return 0 ;
}
static void F_424 ( struct V_5 * V_7 ,
struct V_468 * V_469 )
{
}
static void F_431 ( struct V_5 * V_7 ,
struct V_468 * V_469 )
{
}
static void F_432 ( struct V_5 * V_474 )
{
if ( F_29 ( V_474 -> V_29 ) )
V_4 -> V_105 = true ;
else
V_4 -> V_105 = false ;
}
static V_130 F_433 ( struct V_5 * V_7 ,
struct V_299 * V_300 )
{
return F_258 ( F_8 ( V_7 ) , false ) ;
}
static int F_434 ( struct V_324 * V_325 , void * V_326 )
{
struct V_2 * V_3 = F_8 ( F_277 ( V_325 ) ) ;
unsigned long V_434 = F_31 ( V_3 -> V_434 ) ;
if ( V_434 == V_320 )
F_435 ( V_325 , L_34 ) ;
else
F_279 ( V_325 , L_35 , ( V_130 ) V_434 * V_310 ) ;
return 0 ;
}
static T_6 F_436 ( struct V_294 * V_295 ,
char * V_296 , T_7 V_297 , T_8 V_298 )
{
struct V_2 * V_3 = F_8 ( F_254 ( V_295 ) ) ;
unsigned long V_434 ;
int V_256 ;
V_296 = F_269 ( V_296 ) ;
V_256 = F_270 ( V_296 , L_36 , & V_434 ) ;
if ( V_256 )
return V_256 ;
V_3 -> V_434 = V_434 ;
return V_297 ;
}
static int F_437 ( struct V_324 * V_325 , void * V_326 )
{
struct V_2 * V_3 = F_8 ( F_277 ( V_325 ) ) ;
unsigned long V_249 = F_31 ( V_3 -> V_249 ) ;
if ( V_249 == V_320 )
F_435 ( V_325 , L_34 ) ;
else
F_279 ( V_325 , L_35 , ( V_130 ) V_249 * V_310 ) ;
return 0 ;
}
static T_6 F_438 ( struct V_294 * V_295 ,
char * V_296 , T_7 V_297 , T_8 V_298 )
{
struct V_2 * V_3 = F_8 ( F_254 ( V_295 ) ) ;
unsigned long V_249 ;
int V_256 ;
V_296 = F_269 ( V_296 ) ;
V_256 = F_270 ( V_296 , L_36 , & V_249 ) ;
if ( V_256 )
return V_256 ;
V_3 -> V_249 = V_249 ;
F_323 ( V_3 ) ;
return V_297 ;
}
static int F_439 ( struct V_324 * V_325 , void * V_326 )
{
struct V_2 * V_3 = F_8 ( F_277 ( V_325 ) ) ;
unsigned long F_184 = F_31 ( V_3 -> V_51 . V_117 ) ;
if ( F_184 == V_320 )
F_435 ( V_325 , L_34 ) ;
else
F_279 ( V_325 , L_35 , ( V_130 ) F_184 * V_310 ) ;
return 0 ;
}
static T_6 F_440 ( struct V_294 * V_295 ,
char * V_296 , T_7 V_297 , T_8 V_298 )
{
struct V_2 * V_3 = F_8 ( F_254 ( V_295 ) ) ;
unsigned long F_184 ;
int V_256 ;
V_296 = F_269 ( V_296 ) ;
V_256 = F_270 ( V_296 , L_36 , & F_184 ) ;
if ( V_256 )
return V_256 ;
V_256 = F_242 ( V_3 , F_184 ) ;
if ( V_256 )
return V_256 ;
F_323 ( V_3 ) ;
return V_297 ;
}
static int F_441 ( struct V_324 * V_325 , void * V_326 )
{
struct V_2 * V_3 = F_8 ( F_277 ( V_325 ) ) ;
F_279 ( V_325 , L_37 , F_61 ( V_3 , V_475 ) ) ;
F_279 ( V_325 , L_38 , F_61 ( V_3 , V_250 ) ) ;
F_279 ( V_325 , L_39 , F_61 ( V_3 , V_242 ) ) ;
F_279 ( V_325 , L_40 , F_61 ( V_3 , V_246 ) ) ;
return 0 ;
}
bool F_442 ( struct V_2 * V_97 , struct V_2 * V_3 )
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
int F_443 ( struct V_28 * V_28 , struct V_94 * V_95 ,
T_3 V_141 , struct V_2 * * V_476 )
{
struct V_2 * V_3 = NULL ;
unsigned int V_50 = 1 ;
int V_115 = 0 ;
if ( F_84 () )
goto V_106;
if ( F_444 ( V_28 ) ) {
F_201 ( ! F_445 ( V_28 ) , V_28 ) ;
if ( V_28 -> V_2 )
goto V_106;
if ( V_118 ) {
T_5 V_442 = { . V_60 = F_446 ( V_28 ) , } ;
unsigned short V_8 = F_404 ( V_442 ) ;
F_12 () ;
V_3 = F_6 ( V_8 ) ;
if ( V_3 && ! F_15 ( & V_3 -> V_7 ) )
V_3 = NULL ;
F_16 () ;
}
}
if ( F_65 ( V_28 ) ) {
V_50 <<= F_447 ( V_28 ) ;
F_201 ( ! F_65 ( V_28 ) , V_28 ) ;
}
if ( ! V_3 )
V_3 = F_81 ( V_95 ) ;
V_115 = F_183 ( V_3 , V_141 , V_50 ) ;
F_19 ( & V_3 -> V_7 ) ;
if ( V_115 == - V_248 ) {
V_3 = V_4 ;
V_115 = 0 ;
}
V_106:
* V_476 = V_3 ;
return V_115 ;
}
void F_448 ( struct V_28 * V_28 , struct V_2 * V_3 ,
bool V_253 )
{
unsigned int V_50 = 1 ;
F_201 ( ! V_28 -> V_444 , V_28 ) ;
F_201 ( F_196 ( V_28 ) && ! V_253 , V_28 ) ;
if ( F_84 () )
return;
if ( ! V_3 )
return;
F_204 ( V_28 , V_3 , V_253 ) ;
if ( F_65 ( V_28 ) ) {
V_50 <<= F_447 ( V_28 ) ;
F_201 ( ! F_65 ( V_28 ) , V_28 ) ;
}
F_396 () ;
F_62 ( V_3 , V_28 , V_50 ) ;
F_76 ( V_3 , V_28 ) ;
F_397 () ;
if ( V_118 && F_444 ( V_28 ) ) {
T_5 V_278 = { . V_60 = F_446 (page) } ;
F_449 ( V_278 ) ;
}
}
void F_450 ( struct V_28 * V_28 , struct V_2 * V_3 )
{
unsigned int V_50 = 1 ;
if ( F_84 () )
return;
if ( ! V_3 )
return;
if ( F_65 ( V_28 ) ) {
V_50 <<= F_447 ( V_28 ) ;
F_201 ( ! F_65 ( V_28 ) , V_28 ) ;
}
F_193 ( V_3 , V_50 ) ;
}
static void F_451 ( struct V_2 * V_3 , unsigned long V_477 ,
unsigned long V_478 , unsigned long V_479 ,
unsigned long V_480 , struct V_28 * V_481 )
{
unsigned long V_50 = V_478 + V_479 ;
unsigned long V_19 ;
if ( ! F_4 ( V_3 ) ) {
F_167 ( & V_3 -> V_51 , V_50 ) ;
if ( V_118 )
F_167 ( & V_3 -> V_119 , V_50 ) ;
F_155 ( V_3 ) ;
}
F_452 ( V_19 ) ;
F_237 ( V_3 -> V_62 -> V_63 [ V_66 ] , V_478 ) ;
F_237 ( V_3 -> V_62 -> V_63 [ V_67 ] , V_479 ) ;
F_237 ( V_3 -> V_62 -> V_63 [ V_68 ] , V_480 ) ;
F_64 ( V_3 -> V_62 -> V_65 [ V_70 ] , V_477 ) ;
F_64 ( V_3 -> V_62 -> V_71 , V_50 ) ;
F_76 ( V_3 , V_481 ) ;
F_453 ( V_19 ) ;
if ( ! F_4 ( V_3 ) )
F_168 ( & V_3 -> V_7 , V_50 ) ;
}
static void F_454 ( struct V_373 * V_482 )
{
struct V_2 * V_3 = NULL ;
unsigned long V_478 = 0 ;
unsigned long V_479 = 0 ;
unsigned long V_480 = 0 ;
unsigned long V_477 = 0 ;
struct V_373 * V_80 ;
struct V_28 * V_28 ;
V_80 = V_482 -> V_80 ;
do {
unsigned int V_50 = 1 ;
V_28 = F_455 ( V_80 , struct V_28 , V_76 ) ;
V_80 = V_28 -> V_76 . V_80 ;
F_201 ( F_196 ( V_28 ) , V_28 ) ;
F_201 ( F_456 ( V_28 ) , V_28 ) ;
if ( ! V_28 -> V_2 )
continue;
if ( V_3 != V_28 -> V_2 ) {
if ( V_3 ) {
F_451 ( V_3 , V_477 , V_478 , V_479 ,
V_480 , V_28 ) ;
V_477 = V_478 = V_479 = V_480 = 0 ;
}
V_3 = V_28 -> V_2 ;
}
if ( F_65 ( V_28 ) ) {
V_50 <<= F_447 ( V_28 ) ;
F_201 ( ! F_65 ( V_28 ) , V_28 ) ;
V_480 += V_50 ;
}
if ( F_63 ( V_28 ) )
V_478 += V_50 ;
else
V_479 += V_50 ;
V_28 -> V_2 = NULL ;
V_477 ++ ;
} while ( V_80 != V_482 );
if ( V_3 )
F_451 ( V_3 , V_477 , V_478 , V_479 ,
V_480 , V_28 ) ;
}
void F_457 ( struct V_28 * V_28 )
{
if ( F_84 () )
return;
if ( ! V_28 -> V_2 )
return;
F_159 ( & V_28 -> V_76 ) ;
F_454 ( & V_28 -> V_76 ) ;
}
void F_458 ( struct V_373 * V_482 )
{
if ( F_84 () )
return;
if ( ! F_331 ( V_482 ) )
F_454 ( V_482 ) ;
}
void F_459 ( struct V_28 * V_483 , struct V_28 * V_484 ,
bool V_253 )
{
struct V_2 * V_3 ;
int V_251 ;
F_201 ( ! F_445 ( V_483 ) , V_483 ) ;
F_201 ( ! F_445 ( V_484 ) , V_484 ) ;
F_201 ( ! V_253 && F_196 ( V_483 ) , V_483 ) ;
F_201 ( ! V_253 && F_196 ( V_484 ) , V_484 ) ;
F_201 ( F_63 ( V_483 ) != F_63 ( V_484 ) , V_484 ) ;
F_201 ( F_65 ( V_483 ) != F_65 ( V_484 ) ,
V_484 ) ;
if ( F_84 () )
return;
if ( V_484 -> V_2 )
return;
V_3 = V_483 -> V_2 ;
if ( ! V_3 )
return;
if ( V_253 )
F_194 ( V_483 , & V_251 ) ;
V_483 -> V_2 = NULL ;
if ( V_253 )
F_200 ( V_483 , V_251 ) ;
F_204 ( V_484 , V_3 , V_253 ) ;
}
static int T_16 F_460 ( void )
{
int V_61 , V_167 ;
F_461 ( F_182 , 0 ) ;
F_59 (cpu)
F_221 ( & F_462 ( & V_210 , V_61 ) -> V_218 ,
F_169 ) ;
F_52 (node) {
struct V_485 * V_486 ;
int V_23 ;
V_486 = F_350 ( sizeof( * V_486 ) , V_259 ,
F_463 ( V_167 ) ? V_167 : V_487 ) ;
for ( V_23 = 0 ; V_23 < V_54 ; V_23 ++ ) {
struct V_32 * V_488 ;
V_488 = & V_486 -> V_35 [ V_23 ] ;
V_488 -> V_41 = V_489 ;
F_361 ( & V_488 -> V_49 ) ;
}
V_33 . V_34 [ V_167 ] = V_486 ;
}
return 0 ;
}
void F_464 ( struct V_28 * V_28 , T_5 V_278 )
{
struct V_2 * V_3 ;
unsigned short V_490 ;
F_201 ( F_196 ( V_28 ) , V_28 ) ;
F_201 ( F_456 ( V_28 ) , V_28 ) ;
if ( ! V_118 )
return;
V_3 = V_28 -> V_2 ;
if ( ! V_3 )
return;
V_490 = F_465 ( V_278 , F_5 ( V_3 ) ) ;
F_201 ( V_490 , V_28 ) ;
F_238 ( V_3 , true ) ;
V_28 -> V_2 = NULL ;
if ( ! F_4 ( V_3 ) )
F_167 ( & V_3 -> V_51 , 1 ) ;
F_68 ( ! F_466 () ) ;
F_62 ( V_3 , V_28 , - 1 ) ;
F_76 ( V_3 , V_28 ) ;
}
void F_449 ( T_5 V_278 )
{
struct V_2 * V_3 ;
unsigned short V_8 ;
if ( ! V_118 )
return;
V_8 = F_465 ( V_278 , 0 ) ;
F_12 () ;
V_3 = F_6 ( V_8 ) ;
if ( V_3 ) {
if ( ! F_4 ( V_3 ) )
F_167 ( & V_3 -> V_119 , 1 ) ;
F_238 ( V_3 , false ) ;
F_19 ( & V_3 -> V_7 ) ;
}
F_16 () ;
}
static int T_16 F_467 ( char * V_491 )
{
if ( ! strcmp ( V_491 , L_41 ) )
V_492 = 1 ;
else if ( ! strcmp ( V_491 , L_42 ) )
V_492 = 0 ;
return 1 ;
}
static int T_16 F_468 ( void )
{
if ( ! F_84 () && V_492 ) {
V_118 = 1 ;
F_18 ( F_469 ( & V_9 ,
V_493 ) ) ;
}
return 0 ;
}
