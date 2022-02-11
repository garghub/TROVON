bool F_1 ( struct V_1 * V_2 )
{
return V_2 -> V_3 ;
}
struct V_1 * F_2 ( struct V_4 * V_5 )
{
return V_5 ? F_3 ( V_5 , struct V_1 , V_6 ) : NULL ;
}
struct V_7 * F_4 ( struct V_1 * V_2 )
{
if ( ! V_2 )
V_2 = V_8 ;
return & V_2 -> V_7 ;
}
struct V_4 * F_5 ( struct V_7 * V_9 )
{
return & F_3 ( V_9 , struct V_1 , V_7 ) -> V_6 ;
}
static inline bool F_6 ( struct V_1 * V_2 )
{
return ( V_2 == V_8 ) ;
}
static inline unsigned short F_7 ( struct V_1 * V_2 )
{
return V_2 -> V_6 . V_10 ;
}
static inline struct V_1 * F_8 ( unsigned short V_10 )
{
struct V_4 * V_6 ;
V_6 = F_9 ( V_10 , & V_11 ) ;
return F_2 ( V_6 ) ;
}
void F_10 ( struct V_12 * V_13 )
{
if ( V_14 ) {
struct V_1 * V_2 ;
struct V_15 * V_15 ;
F_11 ( ! V_13 -> V_16 -> V_17 ) ;
if ( V_13 -> V_18 ) {
F_11 ( F_6 ( V_13 -> V_18 -> V_2 ) ) ;
F_12 ( & V_13 -> V_18 -> V_2 -> V_6 ) ;
return;
}
F_13 () ;
V_2 = F_14 ( V_19 ) ;
V_15 = V_13 -> V_16 -> V_17 ( V_2 ) ;
if ( ! F_6 ( V_2 ) &&
F_15 ( V_15 ) &&
F_16 ( & V_2 -> V_6 ) ) {
V_13 -> V_18 = V_15 ;
}
F_17 () ;
}
}
void F_18 ( struct V_12 * V_13 )
{
if ( V_14 && V_13 -> V_18 ) {
struct V_1 * V_2 ;
F_19 ( ! V_13 -> V_18 -> V_2 ) ;
V_2 = V_13 -> V_18 -> V_2 ;
F_20 ( & V_13 -> V_18 -> V_2 -> V_6 ) ;
}
}
struct V_15 * F_21 ( struct V_1 * V_2 )
{
if ( ! V_2 || F_6 ( V_2 ) )
return NULL ;
return & V_2 -> V_20 ;
}
void F_22 ( void )
{
F_23 ( & V_21 ) ;
}
void F_24 ( void )
{
F_25 ( & V_21 ) ;
}
static struct V_22 *
F_26 ( struct V_1 * V_2 , struct V_23 * V_23 )
{
int V_24 = F_27 ( V_23 ) ;
int V_25 = F_28 ( V_23 ) ;
return & V_2 -> V_26 [ V_24 ] -> V_27 [ V_25 ] ;
}
struct V_4 * F_29 ( struct V_1 * V_2 )
{
return & V_2 -> V_6 ;
}
static struct V_22 *
F_30 ( struct V_1 * V_2 , struct V_28 * V_28 )
{
int V_24 = F_31 ( V_28 ) ;
int V_25 = F_32 ( V_28 ) ;
return & V_2 -> V_26 [ V_24 ] -> V_27 [ V_25 ] ;
}
static struct V_29 *
F_33 ( int V_24 , int V_25 )
{
return & V_30 . V_31 [ V_24 ] -> V_32 [ V_25 ] ;
}
static struct V_29 *
F_34 ( struct V_28 * V_28 )
{
int V_24 = F_31 ( V_28 ) ;
int V_25 = F_32 ( V_28 ) ;
return & V_30 . V_31 [ V_24 ] -> V_32 [ V_25 ] ;
}
static void F_35 ( struct V_22 * V_33 ,
struct V_29 * V_34 ,
unsigned long V_35 )
{
struct V_36 * * V_37 = & V_34 -> V_38 . V_36 ;
struct V_36 * V_39 = NULL ;
struct V_22 * V_40 ;
if ( V_33 -> V_41 )
return;
V_33 -> V_42 = V_35 ;
if ( ! V_33 -> V_42 )
return;
while ( * V_37 ) {
V_39 = * V_37 ;
V_40 = F_36 ( V_39 , struct V_22 ,
V_43 ) ;
if ( V_33 -> V_42 < V_40 -> V_42 )
V_37 = & ( * V_37 ) -> V_44 ;
else if ( V_33 -> V_42 >= V_40 -> V_42 )
V_37 = & ( * V_37 ) -> V_45 ;
}
F_37 ( & V_33 -> V_43 , V_39 , V_37 ) ;
F_38 ( & V_33 -> V_43 , & V_34 -> V_38 ) ;
V_33 -> V_41 = true ;
}
static void F_39 ( struct V_22 * V_33 ,
struct V_29 * V_34 )
{
if ( ! V_33 -> V_41 )
return;
F_40 ( & V_33 -> V_43 , & V_34 -> V_38 ) ;
V_33 -> V_41 = false ;
}
static void F_41 ( struct V_22 * V_33 ,
struct V_29 * V_34 )
{
unsigned long V_46 ;
F_42 ( & V_34 -> V_47 , V_46 ) ;
F_39 ( V_33 , V_34 ) ;
F_43 ( & V_34 -> V_47 , V_46 ) ;
}
static unsigned long F_44 ( struct V_1 * V_2 )
{
unsigned long V_48 = F_45 ( & V_2 -> V_49 ) ;
unsigned long V_50 = F_46 ( V_2 -> V_50 ) ;
unsigned long V_51 = 0 ;
if ( V_48 > V_50 )
V_51 = V_48 - V_50 ;
return V_51 ;
}
static void F_47 ( struct V_1 * V_2 , struct V_28 * V_28 )
{
unsigned long V_51 ;
struct V_22 * V_33 ;
struct V_29 * V_34 ;
V_34 = F_34 ( V_28 ) ;
for (; V_2 ; V_2 = F_48 ( V_2 ) ) {
V_33 = F_30 ( V_2 , V_28 ) ;
V_51 = F_44 ( V_2 ) ;
if ( V_51 || V_33 -> V_41 ) {
unsigned long V_46 ;
F_42 ( & V_34 -> V_47 , V_46 ) ;
if ( V_33 -> V_41 )
F_39 ( V_33 , V_34 ) ;
F_35 ( V_33 , V_34 , V_51 ) ;
F_43 ( & V_34 -> V_47 , V_46 ) ;
}
}
}
static void F_49 ( struct V_1 * V_2 )
{
struct V_29 * V_34 ;
struct V_22 * V_33 ;
int V_24 , V_25 ;
F_50 (nid) {
for ( V_25 = 0 ; V_25 < V_52 ; V_25 ++ ) {
V_33 = & V_2 -> V_26 [ V_24 ] -> V_27 [ V_25 ] ;
V_34 = F_33 ( V_24 , V_25 ) ;
F_41 ( V_33 , V_34 ) ;
}
}
}
static struct V_22 *
F_51 ( struct V_29 * V_34 )
{
struct V_36 * V_53 = NULL ;
struct V_22 * V_33 ;
V_54:
V_33 = NULL ;
V_53 = F_52 ( & V_34 -> V_38 ) ;
if ( ! V_53 )
goto V_55;
V_33 = F_36 ( V_53 , struct V_22 , V_43 ) ;
F_39 ( V_33 , V_34 ) ;
if ( ! F_44 ( V_33 -> V_2 ) ||
! F_16 ( & V_33 -> V_2 -> V_6 ) )
goto V_54;
V_55:
return V_33 ;
}
static struct V_22 *
F_53 ( struct V_29 * V_34 )
{
struct V_22 * V_33 ;
F_54 ( & V_34 -> V_47 ) ;
V_33 = F_51 ( V_34 ) ;
F_55 ( & V_34 -> V_47 ) ;
return V_33 ;
}
static long F_56 ( struct V_1 * V_2 ,
enum V_56 V_57 )
{
long V_58 = 0 ;
int V_59 ;
F_57 () ;
F_58 (cpu)
V_58 += F_59 ( V_2 -> V_60 -> V_61 [ V_57 ] , V_59 ) ;
#ifdef F_60
F_61 ( & V_2 -> V_62 ) ;
V_58 += V_2 -> V_63 . V_61 [ V_57 ] ;
F_62 ( & V_2 -> V_62 ) ;
#endif
F_63 () ;
return V_58 ;
}
static unsigned long F_64 ( struct V_1 * V_2 ,
enum V_64 V_57 )
{
unsigned long V_58 = 0 ;
int V_59 ;
F_57 () ;
F_58 (cpu)
V_58 += F_59 ( V_2 -> V_60 -> V_65 [ V_57 ] , V_59 ) ;
#ifdef F_60
F_61 ( & V_2 -> V_62 ) ;
V_58 += V_2 -> V_63 . V_65 [ V_57 ] ;
F_62 ( & V_2 -> V_62 ) ;
#endif
F_63 () ;
return V_58 ;
}
static void F_65 ( struct V_1 * V_2 ,
struct V_28 * V_28 ,
int V_48 )
{
if ( F_66 ( V_28 ) )
F_67 ( V_2 -> V_60 -> V_61 [ V_66 ] ,
V_48 ) ;
else
F_67 ( V_2 -> V_60 -> V_61 [ V_67 ] ,
V_48 ) ;
if ( F_68 ( V_28 ) )
F_67 ( V_2 -> V_60 -> V_61 [ V_68 ] ,
V_48 ) ;
if ( V_48 > 0 )
F_69 ( V_2 -> V_60 -> V_65 [ V_69 ] ) ;
else {
F_69 ( V_2 -> V_60 -> V_65 [ V_70 ] ) ;
V_48 = - V_48 ;
}
F_67 ( V_2 -> V_60 -> V_71 , V_48 ) ;
}
unsigned long F_70 ( struct V_72 * V_72 , enum V_73 V_74 )
{
struct V_22 * V_33 ;
V_33 = F_3 ( V_72 , struct V_22 , V_72 ) ;
return V_33 -> V_75 [ V_74 ] ;
}
static unsigned long F_71 ( struct V_1 * V_2 ,
int V_24 ,
unsigned int V_76 )
{
unsigned long V_77 = 0 ;
int V_25 ;
F_72 ( ( unsigned ) V_24 >= V_78 ) ;
for ( V_25 = 0 ; V_25 < V_52 ; V_25 ++ ) {
struct V_22 * V_33 ;
enum V_73 V_74 ;
F_73 (lru) {
if ( ! ( F_74 ( V_74 ) & V_76 ) )
continue;
V_33 = & V_2 -> V_26 [ V_24 ] -> V_27 [ V_25 ] ;
V_77 += V_33 -> V_75 [ V_74 ] ;
}
}
return V_77 ;
}
static unsigned long F_75 ( struct V_1 * V_2 ,
unsigned int V_76 )
{
unsigned long V_77 = 0 ;
int V_24 ;
F_76 (nid, N_MEMORY)
V_77 += F_71 ( V_2 , V_24 , V_76 ) ;
return V_77 ;
}
static bool F_77 ( struct V_1 * V_2 ,
enum V_79 V_80 )
{
unsigned long V_58 , V_81 ;
V_58 = F_78 ( V_2 -> V_60 -> V_71 ) ;
V_81 = F_78 ( V_2 -> V_60 -> V_82 [ V_80 ] ) ;
if ( ( long ) V_81 - ( long ) V_58 < 0 ) {
switch ( V_80 ) {
case V_83 :
V_81 = V_58 + V_84 ;
break;
case V_85 :
V_81 = V_58 + V_86 ;
break;
case V_87 :
V_81 = V_58 + V_88 ;
break;
default:
break;
}
F_79 ( V_2 -> V_60 -> V_82 [ V_80 ] , V_81 ) ;
return true ;
}
return false ;
}
static void F_80 ( struct V_1 * V_2 , struct V_28 * V_28 )
{
if ( F_81 ( F_77 ( V_2 ,
V_83 ) ) ) {
bool V_89 ;
bool T_1 V_90 ;
V_89 = F_77 ( V_2 ,
V_85 ) ;
#if V_91 > 1
T_1 = F_77 ( V_2 ,
V_87 ) ;
#endif
F_82 ( V_2 ) ;
if ( F_81 ( V_89 ) )
F_47 ( V_2 , V_28 ) ;
#if V_91 > 1
if ( F_81 ( T_1 ) )
F_83 ( & V_2 -> V_92 ) ;
#endif
}
}
struct V_1 * F_14 ( struct V_93 * V_37 )
{
if ( F_81 ( ! V_37 ) )
return NULL ;
return F_2 ( F_84 ( V_37 , V_94 ) ) ;
}
static struct V_1 * F_85 ( struct V_95 * V_96 )
{
struct V_1 * V_2 = NULL ;
F_13 () ;
do {
if ( F_81 ( ! V_96 ) )
V_2 = V_8 ;
else {
V_2 = F_14 ( F_86 ( V_96 -> V_97 ) ) ;
if ( F_81 ( ! V_2 ) )
V_2 = V_8 ;
}
} while ( ! F_16 ( & V_2 -> V_6 ) );
F_17 () ;
return V_2 ;
}
struct V_1 * F_87 ( struct V_1 * V_98 ,
struct V_1 * V_99 ,
struct V_100 * V_101 )
{
struct V_102 * V_103 ( V_104 ) ;
struct V_4 * V_6 = NULL ;
struct V_1 * V_2 = NULL ;
struct V_1 * V_105 = NULL ;
if ( F_88 () )
return NULL ;
if ( ! V_98 )
V_98 = V_8 ;
if ( V_99 && ! V_101 )
V_105 = V_99 ;
if ( ! V_98 -> V_106 && V_98 != V_8 ) {
if ( V_99 )
goto V_107;
return V_98 ;
}
F_13 () ;
if ( V_101 ) {
struct V_22 * V_33 ;
V_33 = F_26 ( V_98 , V_101 -> V_23 ) ;
V_104 = & V_33 -> V_104 [ V_101 -> V_108 ] ;
if ( V_99 && V_101 -> V_109 != V_104 -> V_109 )
goto V_110;
do {
V_105 = F_46 ( V_104 -> V_111 ) ;
} while ( V_105 && ! F_89 ( & V_105 -> V_6 ) );
}
if ( V_105 )
V_6 = & V_105 -> V_6 ;
for (; ; ) {
V_6 = F_90 ( V_6 , & V_98 -> V_6 ) ;
if ( ! V_6 ) {
if ( ! V_99 )
continue;
break;
}
V_2 = F_2 ( V_6 ) ;
if ( V_6 == & V_98 -> V_6 )
break;
if ( F_89 ( V_6 ) ) {
if ( F_91 ( & V_2 -> V_112 ) )
break;
F_20 ( V_6 ) ;
}
V_2 = NULL ;
}
if ( V_101 ) {
if ( F_92 ( & V_104 -> V_111 , V_105 , V_2 ) == V_105 ) {
if ( V_2 )
F_12 ( & V_2 -> V_6 ) ;
if ( V_105 )
F_20 ( & V_105 -> V_6 ) ;
}
if ( V_105 )
F_20 ( & V_105 -> V_6 ) ;
if ( ! V_2 )
V_104 -> V_109 ++ ;
else if ( ! V_99 )
V_101 -> V_109 = V_104 -> V_109 ;
}
V_110:
F_17 () ;
V_107:
if ( V_99 && V_99 != V_98 )
F_20 ( & V_99 -> V_6 ) ;
return V_2 ;
}
void F_93 ( struct V_1 * V_98 ,
struct V_1 * V_99 )
{
if ( ! V_98 )
V_98 = V_8 ;
if ( V_99 && V_99 != V_98 )
F_20 ( & V_99 -> V_6 ) ;
}
void F_94 ( struct V_95 * V_96 , enum V_113 V_57 )
{
struct V_1 * V_2 ;
F_13 () ;
V_2 = F_14 ( F_86 ( V_96 -> V_97 ) ) ;
if ( F_81 ( ! V_2 ) )
goto V_107;
switch ( V_57 ) {
case V_114 :
F_95 ( V_2 -> V_60 -> V_65 [ V_115 ] ) ;
break;
case V_116 :
F_95 ( V_2 -> V_60 -> V_65 [ V_117 ] ) ;
break;
default:
F_96 () ;
}
V_107:
F_17 () ;
}
struct V_72 * F_97 ( struct V_23 * V_23 ,
struct V_1 * V_2 )
{
struct V_22 * V_33 ;
struct V_72 * V_72 ;
if ( F_88 () ) {
V_72 = & V_23 -> V_72 ;
goto V_107;
}
V_33 = F_26 ( V_2 , V_23 ) ;
V_72 = & V_33 -> V_72 ;
V_107:
if ( F_81 ( V_72 -> V_23 != V_23 ) )
V_72 -> V_23 = V_23 ;
return V_72 ;
}
struct V_72 * F_98 ( struct V_28 * V_28 , struct V_23 * V_23 )
{
struct V_22 * V_33 ;
struct V_1 * V_2 ;
struct V_72 * V_72 ;
if ( F_88 () ) {
V_72 = & V_23 -> V_72 ;
goto V_107;
}
V_2 = V_28 -> V_1 ;
if ( ! V_2 )
V_2 = V_8 ;
V_33 = F_30 ( V_2 , V_28 ) ;
V_72 = & V_33 -> V_72 ;
V_107:
if ( F_81 ( V_72 -> V_23 != V_23 ) )
V_72 -> V_23 = V_23 ;
return V_72 ;
}
void F_99 ( struct V_72 * V_72 , enum V_73 V_74 ,
int V_48 )
{
struct V_22 * V_33 ;
unsigned long * V_75 ;
if ( F_88 () )
return;
V_33 = F_3 ( V_72 , struct V_22 , V_72 ) ;
V_75 = V_33 -> V_75 + V_74 ;
* V_75 += V_48 ;
F_72 ( ( long ) ( * V_75 ) < 0 ) ;
}
bool F_100 ( struct V_1 * V_2 , struct V_1 * V_98 )
{
if ( V_98 == V_2 )
return true ;
if ( ! V_98 -> V_106 )
return false ;
return F_101 ( V_2 -> V_6 . V_118 , V_98 -> V_6 . V_118 ) ;
}
bool F_102 ( struct V_93 * V_119 , struct V_1 * V_2 )
{
struct V_1 * V_120 ;
struct V_93 * V_37 ;
bool V_121 ;
V_37 = F_103 ( V_119 ) ;
if ( V_37 ) {
V_120 = F_85 ( V_37 -> V_96 ) ;
F_104 ( V_37 ) ;
} else {
F_13 () ;
V_120 = F_14 ( V_119 ) ;
F_12 ( & V_120 -> V_6 ) ;
F_17 () ;
}
V_121 = F_100 ( V_120 , V_2 ) ;
F_20 ( & V_120 -> V_6 ) ;
return V_121 ;
}
int F_105 ( struct V_72 * V_72 )
{
unsigned long V_122 ;
unsigned long V_123 ;
unsigned long V_124 ;
unsigned long V_125 ;
V_123 = F_70 ( V_72 , V_126 ) ;
V_124 = F_70 ( V_72 , V_127 ) ;
V_125 = ( V_123 + V_124 ) >> ( 30 - V_128 ) ;
if ( V_125 )
V_122 = F_106 ( 10 * V_125 ) ;
else
V_122 = 1 ;
return V_123 * V_122 < V_124 ;
}
bool F_107 ( struct V_72 * V_72 )
{
struct V_22 * V_33 ;
struct V_1 * V_2 ;
if ( F_88 () )
return true ;
V_33 = F_3 ( V_72 , struct V_22 , V_72 ) ;
V_2 = V_33 -> V_2 ;
return ! ! ( V_2 -> V_6 . V_46 & V_129 ) ;
}
static unsigned long F_108 ( struct V_1 * V_2 )
{
unsigned long V_130 = 0 ;
unsigned long V_61 ;
unsigned long V_131 ;
V_61 = F_45 ( & V_2 -> V_49 ) ;
V_131 = F_46 ( V_2 -> V_49 . V_131 ) ;
if ( V_61 < V_131 )
V_130 = V_131 - V_61 ;
if ( V_132 ) {
V_61 = F_45 ( & V_2 -> V_133 ) ;
V_131 = F_46 ( V_2 -> V_133 . V_131 ) ;
if ( V_61 <= V_131 )
V_130 = F_109 ( V_130 , V_131 - V_61 ) ;
}
return V_130 ;
}
int F_110 ( struct V_1 * V_2 )
{
if ( F_88 () || ! V_2 -> V_6 . V_39 )
return V_134 ;
return V_2 -> V_135 ;
}
static bool F_111 ( struct V_1 * V_2 )
{
struct V_1 * V_136 ;
struct V_1 * V_137 ;
bool V_121 = false ;
F_61 ( & V_138 . V_47 ) ;
V_136 = V_138 . V_136 ;
V_137 = V_138 . V_137 ;
if ( ! V_136 )
goto V_139;
V_121 = F_100 ( V_136 , V_2 ) ||
F_100 ( V_137 , V_2 ) ;
V_139:
F_62 ( & V_138 . V_47 ) ;
return V_121 ;
}
static bool F_112 ( struct V_1 * V_2 )
{
if ( V_138 . V_140 && V_19 != V_138 . V_140 ) {
if ( F_111 ( V_2 ) ) {
F_113 ( V_141 ) ;
F_114 ( & V_138 . V_142 , & V_141 , V_143 ) ;
if ( V_138 . V_140 )
F_115 () ;
F_116 ( & V_138 . V_142 , & V_141 ) ;
return true ;
}
}
return false ;
}
void F_117 ( struct V_1 * V_2 , struct V_93 * V_37 )
{
static F_118 ( V_144 ) ;
struct V_1 * V_104 ;
unsigned int V_145 ;
if ( ! V_37 )
return;
F_119 ( & V_144 ) ;
F_13 () ;
F_120 ( L_1 ) ;
F_121 ( F_122 ( V_37 , V_94 ) ) ;
F_123 ( L_2 ) ;
F_121 ( V_2 -> V_6 . V_118 ) ;
F_123 ( L_3 ) ;
F_17 () ;
F_120 ( L_4 ,
F_124 ( ( V_146 ) F_45 ( & V_2 -> V_49 ) ) ,
F_124 ( ( V_146 ) V_2 -> V_49 . V_131 ) , V_2 -> V_49 . V_147 ) ;
F_120 ( L_5 ,
F_124 ( ( V_146 ) F_45 ( & V_2 -> V_133 ) ) ,
F_124 ( ( V_146 ) V_2 -> V_133 . V_131 ) , V_2 -> V_133 . V_147 ) ;
F_120 ( L_6 ,
F_124 ( ( V_146 ) F_45 ( & V_2 -> V_148 ) ) ,
F_124 ( ( V_146 ) V_2 -> V_148 . V_131 ) , V_2 -> V_148 . V_147 ) ;
F_125 (iter, memcg) {
F_120 ( L_7 ) ;
F_121 ( V_104 -> V_6 . V_118 ) ;
F_123 ( L_8 ) ;
for ( V_145 = 0 ; V_145 < V_149 ; V_145 ++ ) {
if ( V_145 == V_150 && ! V_132 )
continue;
F_123 ( L_9 , V_151 [ V_145 ] ,
F_124 ( F_56 ( V_104 , V_145 ) ) ) ;
}
for ( V_145 = 0 ; V_145 < V_152 ; V_145 ++ )
F_123 ( L_10 , V_153 [ V_145 ] ,
F_124 ( F_75 ( V_104 , F_74 ( V_145 ) ) ) ) ;
F_123 ( L_3 ) ;
}
F_126 ( & V_144 ) ;
}
static int F_127 ( struct V_1 * V_2 )
{
int V_154 = 0 ;
struct V_1 * V_104 ;
F_125 (iter, memcg)
V_154 ++ ;
return V_154 ;
}
static unsigned long F_128 ( struct V_1 * V_2 )
{
unsigned long V_131 ;
V_131 = V_2 -> V_49 . V_131 ;
if ( F_110 ( V_2 ) ) {
unsigned long V_155 ;
V_155 = V_2 -> V_133 . V_131 ;
V_131 = F_109 ( V_131 + V_156 , V_155 ) ;
}
return V_131 ;
}
static void F_129 ( struct V_1 * V_2 , T_2 V_157 ,
int V_158 )
{
struct V_1 * V_104 ;
unsigned long V_159 = 0 ;
unsigned long V_160 ;
unsigned int V_161 = 0 ;
struct V_93 * V_162 = NULL ;
if ( F_130 ( V_19 ) || F_131 ( V_19 ) ) {
F_132 ( V_19 ) ;
return;
}
F_133 ( V_163 , V_157 , V_158 , NULL ) ;
V_160 = F_128 ( V_2 ) ? : 1 ;
F_125 (iter, memcg) {
struct V_164 V_165 ;
struct V_93 * V_119 ;
F_134 ( & V_104 -> V_6 , & V_165 ) ;
while ( ( V_119 = F_135 ( & V_165 ) ) ) {
switch ( F_136 ( V_119 , V_160 , NULL ,
false ) ) {
case V_166 :
if ( V_162 )
F_137 ( V_162 ) ;
V_162 = V_119 ;
V_159 = V_167 ;
F_138 ( V_162 ) ;
case V_168 :
continue;
case V_169 :
F_139 ( & V_165 ) ;
F_93 ( V_2 , V_104 ) ;
if ( V_162 )
F_137 ( V_162 ) ;
return;
case V_170 :
break;
} ;
V_161 = F_140 ( V_119 , V_2 , NULL , V_160 ) ;
if ( ! V_161 || V_161 < V_159 )
continue;
if ( V_161 == V_159 &&
F_141 ( V_162 ) )
continue;
if ( V_162 )
F_137 ( V_162 ) ;
V_162 = V_119 ;
V_159 = V_161 ;
F_138 ( V_162 ) ;
}
F_139 ( & V_165 ) ;
}
if ( ! V_162 )
return;
V_161 = V_159 * 1000 / V_160 ;
F_142 ( V_162 , V_157 , V_158 , V_161 , V_160 , V_2 ,
NULL , L_11 ) ;
}
static bool F_143 ( struct V_1 * V_2 ,
int V_24 , bool V_171 )
{
if ( F_71 ( V_2 , V_24 , V_172 ) )
return true ;
if ( V_171 || ! V_156 )
return false ;
if ( F_71 ( V_2 , V_24 , V_173 ) )
return true ;
return false ;
}
static void F_144 ( struct V_1 * V_2 )
{
int V_24 ;
if ( ! F_145 ( & V_2 -> V_92 ) )
return;
if ( F_146 ( & V_2 -> V_174 ) > 1 )
return;
V_2 -> V_175 = V_176 [ V_177 ] ;
F_147 (nid, node_states[N_MEMORY]) {
if ( ! F_143 ( V_2 , V_24 , false ) )
F_148 ( V_24 , V_2 -> V_175 ) ;
}
F_149 ( & V_2 -> V_92 , 0 ) ;
F_149 ( & V_2 -> V_174 , 0 ) ;
}
int F_150 ( struct V_1 * V_2 )
{
int V_178 ;
F_144 ( V_2 ) ;
V_178 = V_2 -> V_179 ;
V_178 = F_151 ( V_178 , V_2 -> V_175 ) ;
if ( V_178 == V_91 )
V_178 = F_152 ( V_2 -> V_175 ) ;
if ( F_81 ( V_178 == V_91 ) )
V_178 = F_153 () ;
V_2 -> V_179 = V_178 ;
return V_178 ;
}
int F_150 ( struct V_1 * V_2 )
{
return 0 ;
}
static int F_154 ( struct V_1 * V_180 ,
struct V_23 * V_23 ,
T_2 V_157 ,
unsigned long * V_181 )
{
struct V_1 * V_182 = NULL ;
int V_183 = 0 ;
int V_184 = 0 ;
unsigned long V_51 ;
unsigned long V_185 ;
struct V_100 V_101 = {
. V_23 = V_23 ,
. V_108 = 0 ,
} ;
V_51 = F_44 ( V_180 ) ;
while ( 1 ) {
V_182 = F_87 ( V_180 , V_182 , & V_101 ) ;
if ( ! V_182 ) {
V_184 ++ ;
if ( V_184 >= 2 ) {
if ( ! V_183 )
break;
if ( V_183 >= ( V_51 >> 2 ) ||
( V_184 > V_186 ) )
break;
}
continue;
}
V_183 += F_155 ( V_182 , V_157 , false ,
V_23 , & V_185 ) ;
* V_181 += V_185 ;
if ( ! F_44 ( V_180 ) )
break;
}
F_93 ( V_180 , V_182 ) ;
return V_183 ;
}
static bool F_156 ( struct V_1 * V_2 )
{
struct V_1 * V_104 , * V_187 = NULL ;
F_61 ( & V_188 ) ;
F_125 (iter, memcg) {
if ( V_104 -> V_189 ) {
V_187 = V_104 ;
F_93 ( V_2 , V_104 ) ;
break;
} else
V_104 -> V_189 = true ;
}
if ( V_187 ) {
F_125 (iter, memcg) {
if ( V_104 == V_187 ) {
F_93 ( V_2 , V_104 ) ;
break;
}
V_104 -> V_189 = false ;
}
} else
F_157 ( & V_190 , 0 , 1 , V_191 ) ;
F_62 ( & V_188 ) ;
return ! V_187 ;
}
static void F_158 ( struct V_1 * V_2 )
{
struct V_1 * V_104 ;
F_61 ( & V_188 ) ;
F_159 ( & V_190 , 1 , V_191 ) ;
F_125 (iter, memcg)
V_104 -> V_189 = false ;
F_62 ( & V_188 ) ;
}
static void F_160 ( struct V_1 * V_2 )
{
struct V_1 * V_104 ;
F_125 (iter, memcg)
F_83 ( & V_104 -> V_192 ) ;
}
static void F_161 ( struct V_1 * V_2 )
{
struct V_1 * V_104 ;
F_125 (iter, memcg)
F_162 ( & V_104 -> V_192 , - 1 , 0 ) ;
}
static int F_163 ( T_3 * V_141 ,
unsigned V_193 , int V_194 , void * V_195 )
{
struct V_1 * V_196 = (struct V_1 * ) V_195 ;
struct V_1 * V_197 ;
struct V_198 * V_198 ;
V_198 = F_3 ( V_141 , struct V_198 , V_141 ) ;
V_197 = V_198 -> V_2 ;
if ( ! F_100 ( V_196 , V_197 ) &&
! F_100 ( V_197 , V_196 ) )
return 0 ;
return F_164 ( V_141 , V_193 , V_194 , V_195 ) ;
}
static void F_165 ( struct V_1 * V_2 )
{
F_83 ( & V_2 -> V_199 ) ;
F_166 ( & V_200 , V_201 , 0 , V_2 ) ;
}
static void F_167 ( struct V_1 * V_2 )
{
if ( V_2 && F_145 ( & V_2 -> V_192 ) )
F_165 ( V_2 ) ;
}
static void F_168 ( struct V_1 * V_2 , T_2 V_202 , int V_158 )
{
if ( ! V_19 -> V_203 . V_204 )
return;
F_12 ( & V_2 -> V_6 ) ;
V_19 -> V_203 . V_2 = V_2 ;
V_19 -> V_203 . V_157 = V_202 ;
V_19 -> V_203 . V_158 = V_158 ;
}
bool F_169 ( bool V_205 )
{
struct V_1 * V_2 = V_19 -> V_203 . V_2 ;
struct V_198 V_206 ;
bool V_207 ;
if ( ! V_2 )
return false ;
if ( ! V_205 || V_208 )
goto V_209;
V_206 . V_2 = V_2 ;
V_206 . V_141 . V_46 = 0 ;
V_206 . V_141 . V_210 = F_163 ;
V_206 . V_141 . V_211 = V_19 ;
F_170 ( & V_206 . V_141 . V_212 ) ;
F_114 ( & V_200 , & V_206 . V_141 , V_213 ) ;
F_160 ( V_2 ) ;
V_207 = F_156 ( V_2 ) ;
if ( V_207 )
F_171 ( V_2 ) ;
if ( V_207 && ! V_2 -> V_214 ) {
F_161 ( V_2 ) ;
F_116 ( & V_200 , & V_206 . V_141 ) ;
F_129 ( V_2 , V_19 -> V_203 . V_157 ,
V_19 -> V_203 . V_158 ) ;
} else {
F_115 () ;
F_161 ( V_2 ) ;
F_116 ( & V_200 , & V_206 . V_141 ) ;
}
if ( V_207 ) {
F_158 ( V_2 ) ;
F_167 ( V_2 ) ;
}
V_209:
V_19 -> V_203 . V_2 = NULL ;
F_20 ( & V_2 -> V_6 ) ;
return true ;
}
struct V_1 * F_172 ( struct V_28 * V_28 )
{
struct V_1 * V_2 ;
unsigned long V_46 ;
F_13 () ;
if ( F_88 () )
return NULL ;
V_215:
V_2 = V_28 -> V_1 ;
if ( F_81 ( ! V_2 ) )
return NULL ;
if ( F_145 ( & V_2 -> V_216 ) <= 0 )
return V_2 ;
F_42 ( & V_2 -> V_217 , V_46 ) ;
if ( V_2 != V_28 -> V_1 ) {
F_43 ( & V_2 -> V_217 , V_46 ) ;
goto V_215;
}
V_2 -> V_218 = V_19 ;
V_2 -> V_219 = V_46 ;
return V_2 ;
}
void F_173 ( struct V_1 * V_2 )
{
if ( V_2 && V_2 -> V_218 == V_19 ) {
unsigned long V_46 = V_2 -> V_219 ;
V_2 -> V_218 = NULL ;
V_2 -> V_219 = 0 ;
F_43 ( & V_2 -> V_217 , V_46 ) ;
}
F_17 () ;
}
void F_174 ( struct V_1 * V_2 ,
enum V_56 V_57 , int V_58 )
{
F_72 ( ! F_175 () ) ;
if ( V_2 )
F_176 ( V_2 -> V_60 -> V_61 [ V_57 ] , V_58 ) ;
}
static bool F_177 ( struct V_1 * V_2 , unsigned int V_48 )
{
struct V_220 * V_221 ;
bool V_121 = false ;
if ( V_48 > V_222 )
return V_121 ;
V_221 = & F_178 ( V_223 ) ;
if ( V_2 == V_221 -> V_224 && V_221 -> V_48 >= V_48 ) {
V_221 -> V_48 -= V_48 ;
V_121 = true ;
}
F_179 ( V_223 ) ;
return V_121 ;
}
static void F_180 ( struct V_220 * V_221 )
{
struct V_1 * V_225 = V_221 -> V_224 ;
if ( V_221 -> V_48 ) {
F_181 ( & V_225 -> V_49 , V_221 -> V_48 ) ;
if ( V_132 )
F_181 ( & V_225 -> V_133 , V_221 -> V_48 ) ;
F_182 ( & V_225 -> V_6 , V_221 -> V_48 ) ;
V_221 -> V_48 = 0 ;
}
V_221 -> V_224 = NULL ;
}
static void F_183 ( struct V_226 * V_227 )
{
struct V_220 * V_221 = F_184 ( & V_223 ) ;
F_180 ( V_221 ) ;
F_185 ( V_228 , & V_221 -> V_46 ) ;
}
static void F_186 ( struct V_1 * V_2 , unsigned int V_48 )
{
struct V_220 * V_221 = & F_178 ( V_223 ) ;
if ( V_221 -> V_224 != V_2 ) {
F_180 ( V_221 ) ;
V_221 -> V_224 = V_2 ;
}
V_221 -> V_48 += V_48 ;
F_179 ( V_223 ) ;
}
static void F_187 ( struct V_1 * V_180 )
{
int V_59 , V_229 ;
if ( ! F_188 ( & V_230 ) )
return;
F_57 () ;
V_229 = F_189 () ;
F_58 (cpu) {
struct V_220 * V_221 = & F_59 ( V_223 , V_59 ) ;
struct V_1 * V_2 ;
V_2 = V_221 -> V_224 ;
if ( ! V_2 || ! V_221 -> V_48 )
continue;
if ( ! F_100 ( V_2 , V_180 ) )
continue;
if ( ! F_190 ( V_228 , & V_221 -> V_46 ) ) {
if ( V_59 == V_229 )
F_183 ( & V_221 -> V_231 ) ;
else
F_191 ( V_59 , & V_221 -> V_231 ) ;
}
}
F_192 () ;
F_63 () ;
F_126 ( & V_230 ) ;
}
static void F_193 ( struct V_1 * V_2 , int V_59 )
{
int V_145 ;
F_61 ( & V_2 -> V_62 ) ;
for ( V_145 = 0 ; V_145 < V_149 ; V_145 ++ ) {
long V_232 = F_59 ( V_2 -> V_60 -> V_61 [ V_145 ] , V_59 ) ;
F_59 ( V_2 -> V_60 -> V_61 [ V_145 ] , V_59 ) = 0 ;
V_2 -> V_63 . V_61 [ V_145 ] += V_232 ;
}
for ( V_145 = 0 ; V_145 < V_233 ; V_145 ++ ) {
unsigned long V_232 = F_59 ( V_2 -> V_60 -> V_65 [ V_145 ] , V_59 ) ;
F_59 ( V_2 -> V_60 -> V_65 [ V_145 ] , V_59 ) = 0 ;
V_2 -> V_63 . V_65 [ V_145 ] += V_232 ;
}
F_62 ( & V_2 -> V_62 ) ;
}
static int F_194 ( struct V_234 * V_235 ,
unsigned long V_236 ,
void * V_237 )
{
int V_59 = ( unsigned long ) V_237 ;
struct V_220 * V_221 ;
struct V_1 * V_104 ;
if ( V_236 == V_238 )
return V_239 ;
if ( V_236 != V_240 && V_236 != V_241 )
return V_239 ;
F_195 (iter)
F_193 ( V_104 , V_59 ) ;
V_221 = & F_59 ( V_223 , V_59 ) ;
F_180 ( V_221 ) ;
return V_239 ;
}
static int F_196 ( struct V_1 * V_2 , T_2 V_157 ,
unsigned int V_48 )
{
unsigned int V_242 = F_197 ( V_222 , V_48 ) ;
int V_243 = V_244 ;
struct V_1 * V_245 ;
struct V_246 * V_247 ;
unsigned long V_248 ;
bool V_249 = true ;
bool V_250 = false ;
int V_121 = 0 ;
if ( F_6 ( V_2 ) )
goto V_55;
V_54:
if ( F_177 ( V_2 , V_48 ) )
goto V_55;
if ( ! V_132 ||
! F_198 ( & V_2 -> V_133 , V_242 , & V_247 ) ) {
if ( ! F_198 ( & V_2 -> V_49 , V_242 , & V_247 ) )
goto V_251;
if ( V_132 )
F_181 ( & V_2 -> V_133 , V_242 ) ;
V_245 = F_199 ( V_247 , V_49 ) ;
} else {
V_245 = F_199 ( V_247 , V_133 ) ;
V_249 = false ;
}
if ( V_242 > V_48 ) {
V_242 = V_48 ;
goto V_54;
}
if ( F_81 ( F_200 ( V_252 ) ||
F_130 ( V_19 ) ||
V_19 -> V_46 & V_253 ) )
goto V_254;
if ( F_81 ( F_201 ( V_19 ) ) )
goto V_255;
if ( ! ( V_157 & V_256 ) )
goto V_255;
F_202 ( V_245 , V_257 , 1 ) ;
V_248 = F_203 ( V_245 , V_48 ,
V_157 , V_249 ) ;
if ( F_108 ( V_245 ) >= V_48 )
goto V_54;
if ( ! V_250 ) {
F_187 ( V_245 ) ;
V_250 = true ;
goto V_54;
}
if ( V_157 & V_258 )
goto V_255;
if ( V_248 && V_48 <= ( 1 << V_259 ) )
goto V_54;
if ( F_112 ( V_245 ) )
goto V_54;
if ( V_243 -- )
goto V_54;
if ( V_157 & V_260 )
goto V_254;
if ( F_130 ( V_19 ) )
goto V_254;
F_202 ( V_245 , V_261 , 1 ) ;
F_168 ( V_245 , V_157 , F_204 ( V_48 ) ) ;
V_255:
if ( ! ( V_157 & V_260 ) )
return - V_262 ;
V_254:
return - V_263 ;
V_251:
F_205 ( & V_2 -> V_6 , V_242 ) ;
if ( V_242 > V_48 )
F_186 ( V_2 , V_242 - V_48 ) ;
do {
if ( F_45 ( & V_2 -> V_49 ) <= V_2 -> V_264 )
continue;
F_202 ( V_2 , V_265 , 1 ) ;
F_203 ( V_2 , V_48 , V_157 , true ) ;
} while ( ( V_2 = F_48 ( V_2 ) ) );
V_55:
return V_121 ;
}
static void F_206 ( struct V_1 * V_2 , unsigned int V_48 )
{
if ( F_6 ( V_2 ) )
return;
F_181 ( & V_2 -> V_49 , V_48 ) ;
if ( V_132 )
F_181 ( & V_2 -> V_133 , V_48 ) ;
F_182 ( & V_2 -> V_6 , V_48 ) ;
}
static struct V_1 * F_207 ( unsigned short V_10 )
{
if ( ! V_10 )
return NULL ;
return F_8 ( V_10 ) ;
}
struct V_1 * F_208 ( struct V_28 * V_28 )
{
struct V_1 * V_2 ;
unsigned short V_10 ;
T_4 V_266 ;
F_209 ( ! F_210 ( V_28 ) , V_28 ) ;
V_2 = V_28 -> V_1 ;
if ( V_2 ) {
if ( ! F_16 ( & V_2 -> V_6 ) )
V_2 = NULL ;
} else if ( F_211 ( V_28 ) ) {
V_266 . V_58 = F_212 ( V_28 ) ;
V_10 = F_213 ( V_266 ) ;
F_13 () ;
V_2 = F_207 ( V_10 ) ;
if ( V_2 && ! F_16 ( & V_2 -> V_6 ) )
V_2 = NULL ;
F_17 () ;
}
return V_2 ;
}
static void F_214 ( struct V_28 * V_28 , int * V_267 )
{
struct V_23 * V_23 = F_215 ( V_28 ) ;
F_54 ( & V_23 -> V_268 ) ;
if ( F_216 ( V_28 ) ) {
struct V_72 * V_72 ;
V_72 = F_98 ( V_28 , V_23 ) ;
F_217 ( V_28 ) ;
F_218 ( V_28 , V_72 , F_219 ( V_28 ) ) ;
* V_267 = 1 ;
} else
* V_267 = 0 ;
}
static void F_220 ( struct V_28 * V_28 , int V_267 )
{
struct V_23 * V_23 = F_215 ( V_28 ) ;
if ( V_267 ) {
struct V_72 * V_72 ;
V_72 = F_98 ( V_28 , V_23 ) ;
F_209 ( F_216 ( V_28 ) , V_28 ) ;
F_221 ( V_28 ) ;
F_222 ( V_28 , V_72 , F_219 ( V_28 ) ) ;
}
F_55 ( & V_23 -> V_268 ) ;
}
static void F_223 ( struct V_28 * V_28 , struct V_1 * V_2 ,
bool V_269 )
{
int V_267 ;
F_209 ( V_28 -> V_1 , V_28 ) ;
if ( V_269 )
F_214 ( V_28 , & V_267 ) ;
V_28 -> V_1 = V_2 ;
if ( V_269 )
F_220 ( V_28 , V_267 ) ;
}
int F_224 ( struct V_1 * V_2 , T_2 V_270 ,
unsigned long V_48 )
{
struct V_246 * V_247 ;
int V_121 = 0 ;
V_121 = F_198 ( & V_2 -> V_148 , V_48 , & V_247 ) ;
if ( V_121 < 0 )
return V_121 ;
V_121 = F_196 ( V_2 , V_270 , V_48 ) ;
if ( V_121 == - V_263 ) {
F_225 ( & V_2 -> V_49 , V_48 ) ;
if ( V_132 )
F_225 ( & V_2 -> V_133 , V_48 ) ;
F_205 ( & V_2 -> V_6 , V_48 ) ;
V_121 = 0 ;
} else if ( V_121 )
F_181 ( & V_2 -> V_148 , V_48 ) ;
return V_121 ;
}
void F_226 ( struct V_1 * V_2 , unsigned long V_48 )
{
F_181 ( & V_2 -> V_49 , V_48 ) ;
if ( V_132 )
F_181 ( & V_2 -> V_133 , V_48 ) ;
F_181 ( & V_2 -> V_148 , V_48 ) ;
F_182 ( & V_2 -> V_6 , V_48 ) ;
}
int F_227 ( struct V_1 * V_2 )
{
return V_2 ? V_2 -> V_271 : - 1 ;
}
static int F_228 ( void )
{
int V_10 , V_272 ;
int V_273 ;
V_10 = F_229 ( & V_274 ,
0 , V_275 , V_276 ) ;
if ( V_10 < 0 )
return V_10 ;
if ( V_10 < V_277 )
return V_10 ;
F_230 ( & V_21 ) ;
V_272 = 2 * ( V_10 + 1 ) ;
if ( V_272 < V_278 )
V_272 = V_278 ;
else if ( V_272 > V_275 )
V_272 = V_275 ;
V_273 = F_231 ( V_272 ) ;
if ( ! V_273 )
V_273 = F_232 ( V_272 ) ;
if ( ! V_273 )
V_277 = V_272 ;
F_233 ( & V_21 ) ;
if ( V_273 ) {
F_234 ( & V_274 , V_10 ) ;
return V_273 ;
}
return V_10 ;
}
static void F_235 ( int V_10 )
{
F_234 ( & V_274 , V_10 ) ;
}
static void F_236 ( struct V_226 * V_279 )
{
struct V_280 * V_281 =
F_3 ( V_279 , struct V_280 , V_231 ) ;
struct V_1 * V_2 = V_281 -> V_2 ;
struct V_282 * V_283 = V_281 -> V_283 ;
F_237 ( V_2 , V_283 ) ;
F_20 ( & V_2 -> V_6 ) ;
F_238 ( V_281 ) ;
}
static void F_239 ( struct V_1 * V_2 ,
struct V_282 * V_283 )
{
struct V_280 * V_281 ;
V_281 = F_240 ( sizeof( * V_281 ) , V_284 ) ;
if ( ! V_281 )
return;
F_12 ( & V_2 -> V_6 ) ;
V_281 -> V_2 = V_2 ;
V_281 -> V_283 = V_283 ;
F_241 ( & V_281 -> V_231 , F_236 ) ;
F_242 ( & V_281 -> V_231 ) ;
}
static void F_243 ( struct V_1 * V_2 ,
struct V_282 * V_283 )
{
V_19 -> V_285 = 1 ;
F_239 ( V_2 , V_283 ) ;
V_19 -> V_285 = 0 ;
}
struct V_282 * F_244 ( struct V_282 * V_283 )
{
struct V_1 * V_2 ;
struct V_282 * V_286 ;
int V_271 ;
F_72 ( ! F_245 ( V_283 ) ) ;
if ( V_19 -> V_285 )
return V_283 ;
V_2 = F_85 ( V_19 -> V_96 ) ;
V_271 = F_46 ( V_2 -> V_271 ) ;
if ( V_271 < 0 )
goto V_107;
V_286 = F_246 ( V_283 , V_271 ) ;
if ( F_247 ( V_286 ) )
return V_286 ;
F_243 ( V_2 , V_283 ) ;
V_107:
F_20 ( & V_2 -> V_6 ) ;
return V_283 ;
}
void F_248 ( struct V_282 * V_283 )
{
if ( ! F_245 ( V_283 ) )
F_20 ( & V_283 -> V_287 . V_2 -> V_6 ) ;
}
bool
F_249 ( T_2 V_270 , struct V_1 * * V_288 , int V_158 )
{
struct V_1 * V_2 ;
int V_121 ;
* V_288 = NULL ;
V_2 = F_85 ( V_19 -> V_96 ) ;
if ( ! F_1 ( V_2 ) ) {
F_20 ( & V_2 -> V_6 ) ;
return true ;
}
V_121 = F_224 ( V_2 , V_270 , 1 << V_158 ) ;
if ( ! V_121 )
* V_288 = V_2 ;
F_20 ( & V_2 -> V_6 ) ;
return ( V_121 == 0 ) ;
}
void F_250 ( struct V_28 * V_28 , struct V_1 * V_2 ,
int V_158 )
{
F_72 ( F_6 ( V_2 ) ) ;
if ( ! V_28 ) {
F_226 ( V_2 , 1 << V_158 ) ;
return;
}
V_28 -> V_1 = V_2 ;
}
void F_251 ( struct V_28 * V_28 , int V_158 )
{
struct V_1 * V_2 = V_28 -> V_1 ;
if ( ! V_2 )
return;
F_209 ( F_6 ( V_2 ) , V_28 ) ;
F_226 ( V_2 , 1 << V_158 ) ;
V_28 -> V_1 = NULL ;
}
struct V_1 * F_252 ( void * V_289 )
{
struct V_1 * V_2 = NULL ;
struct V_282 * V_283 ;
struct V_28 * V_28 ;
V_28 = F_253 ( V_289 ) ;
if ( F_254 ( V_28 ) ) {
V_283 = V_28 -> V_290 ;
if ( ! F_245 ( V_283 ) )
V_2 = V_283 -> V_287 . V_2 ;
} else
V_2 = V_28 -> V_1 ;
return V_2 ;
}
void F_255 ( struct V_28 * V_291 )
{
int V_145 ;
if ( F_88 () )
return;
for ( V_145 = 1 ; V_145 < V_292 ; V_145 ++ )
V_291 [ V_145 ] . V_1 = V_291 -> V_1 ;
F_256 ( V_291 -> V_1 -> V_60 -> V_61 [ V_68 ] ,
V_292 ) ;
}
static int F_257 ( struct V_28 * V_28 ,
unsigned int V_48 ,
struct V_1 * V_136 ,
struct V_1 * V_137 )
{
unsigned long V_46 ;
int V_121 ;
F_72 ( V_136 == V_137 ) ;
F_209 ( F_216 ( V_28 ) , V_28 ) ;
V_121 = - V_293 ;
if ( V_48 > 1 && ! F_68 ( V_28 ) )
goto V_107;
if ( ! F_258 ( V_28 ) )
goto V_107;
V_121 = - V_294 ;
if ( V_28 -> V_1 != V_136 )
goto V_110;
F_42 ( & V_136 -> V_217 , V_46 ) ;
if ( ! F_66 ( V_28 ) && F_259 ( V_28 ) ) {
F_256 ( V_136 -> V_60 -> V_61 [ V_295 ] ,
V_48 ) ;
F_67 ( V_137 -> V_60 -> V_61 [ V_295 ] ,
V_48 ) ;
}
if ( F_260 ( V_28 ) ) {
F_256 ( V_136 -> V_60 -> V_61 [ V_296 ] ,
V_48 ) ;
F_67 ( V_137 -> V_60 -> V_61 [ V_296 ] ,
V_48 ) ;
}
V_28 -> V_1 = V_137 ;
F_43 ( & V_136 -> V_217 , V_46 ) ;
V_121 = 0 ;
F_261 () ;
F_65 ( V_137 , V_28 , V_48 ) ;
F_80 ( V_137 , V_28 ) ;
F_65 ( V_136 , V_28 , - V_48 ) ;
F_80 ( V_136 , V_28 ) ;
F_262 () ;
V_110:
F_263 ( V_28 ) ;
V_107:
return V_121 ;
}
static void F_264 ( struct V_1 * V_2 ,
bool V_297 )
{
int V_58 = ( V_297 ) ? 1 : - 1 ;
F_176 ( V_2 -> V_60 -> V_61 [ V_150 ] , V_58 ) ;
}
static int F_265 ( T_4 V_298 ,
struct V_1 * V_136 , struct V_1 * V_137 )
{
unsigned short V_299 , V_300 ;
V_299 = F_7 ( V_136 ) ;
V_300 = F_7 ( V_137 ) ;
if ( F_266 ( V_298 , V_299 , V_300 ) == V_299 ) {
F_264 ( V_136 , false ) ;
F_264 ( V_137 , true ) ;
return 0 ;
}
return - V_294 ;
}
static inline int F_265 ( T_4 V_298 ,
struct V_1 * V_136 , struct V_1 * V_137 )
{
return - V_294 ;
}
static int F_267 ( struct V_1 * V_2 ,
unsigned long V_131 )
{
unsigned long V_301 ;
unsigned long V_302 ;
bool V_303 = false ;
int V_304 ;
int V_121 ;
V_304 = V_244 *
F_127 ( V_2 ) ;
V_302 = F_45 ( & V_2 -> V_49 ) ;
do {
if ( F_268 ( V_19 ) ) {
V_121 = - V_263 ;
break;
}
F_119 ( & V_305 ) ;
if ( V_131 > V_2 -> V_133 . V_131 ) {
F_126 ( & V_305 ) ;
V_121 = - V_294 ;
break;
}
if ( V_131 > V_2 -> V_49 . V_131 )
V_303 = true ;
V_121 = F_269 ( & V_2 -> V_49 , V_131 ) ;
F_126 ( & V_305 ) ;
if ( ! V_121 )
break;
F_203 ( V_2 , 1 , V_276 , true ) ;
V_301 = F_45 ( & V_2 -> V_49 ) ;
if ( V_301 >= V_302 )
V_304 -- ;
else
V_302 = V_301 ;
} while ( V_304 );
if ( ! V_121 && V_303 )
F_167 ( V_2 ) ;
return V_121 ;
}
static int F_270 ( struct V_1 * V_2 ,
unsigned long V_131 )
{
unsigned long V_301 ;
unsigned long V_302 ;
bool V_303 = false ;
int V_304 ;
int V_121 ;
V_304 = V_244 *
F_127 ( V_2 ) ;
V_302 = F_45 ( & V_2 -> V_133 ) ;
do {
if ( F_268 ( V_19 ) ) {
V_121 = - V_263 ;
break;
}
F_119 ( & V_305 ) ;
if ( V_131 < V_2 -> V_49 . V_131 ) {
F_126 ( & V_305 ) ;
V_121 = - V_294 ;
break;
}
if ( V_131 > V_2 -> V_133 . V_131 )
V_303 = true ;
V_121 = F_269 ( & V_2 -> V_133 , V_131 ) ;
F_126 ( & V_305 ) ;
if ( ! V_121 )
break;
F_203 ( V_2 , 1 , V_276 , false ) ;
V_301 = F_45 ( & V_2 -> V_133 ) ;
if ( V_301 >= V_302 )
V_304 -- ;
else
V_302 = V_301 ;
} while ( V_304 );
if ( ! V_121 && V_303 )
F_167 ( V_2 ) ;
return V_121 ;
}
unsigned long F_271 ( struct V_23 * V_23 , int V_158 ,
T_2 V_157 ,
unsigned long * V_181 )
{
unsigned long V_248 = 0 ;
struct V_22 * V_33 , * V_306 = NULL ;
unsigned long V_307 ;
int V_184 = 0 ;
struct V_29 * V_34 ;
unsigned long V_51 ;
unsigned long V_185 ;
if ( V_158 > 0 )
return 0 ;
V_34 = F_33 ( F_27 ( V_23 ) , F_28 ( V_23 ) ) ;
do {
if ( V_306 )
V_33 = V_306 ;
else
V_33 = F_53 ( V_34 ) ;
if ( ! V_33 )
break;
V_185 = 0 ;
V_307 = F_154 ( V_33 -> V_2 , V_23 ,
V_157 , & V_185 ) ;
V_248 += V_307 ;
* V_181 += V_185 ;
F_54 ( & V_34 -> V_47 ) ;
F_39 ( V_33 , V_34 ) ;
V_306 = NULL ;
if ( ! V_307 )
V_306 = F_51 ( V_34 ) ;
V_51 = F_44 ( V_33 -> V_2 ) ;
F_35 ( V_33 , V_34 , V_51 ) ;
F_55 ( & V_34 -> V_47 ) ;
F_20 ( & V_33 -> V_2 -> V_6 ) ;
V_184 ++ ;
if ( ! V_248 &&
( V_306 == NULL ||
V_184 > V_308 ) )
break;
} while ( ! V_248 );
if ( V_306 )
F_20 ( & V_306 -> V_2 -> V_6 ) ;
return V_248 ;
}
static inline bool F_272 ( struct V_1 * V_2 )
{
bool V_121 ;
F_273 ( & V_309 ) ;
F_13 () ;
V_121 = F_274 ( NULL , & V_2 -> V_6 ) ;
F_17 () ;
return V_121 ;
}
static int F_275 ( struct V_1 * V_2 )
{
int V_243 = V_244 ;
F_276 () ;
while ( V_243 && F_45 ( & V_2 -> V_49 ) ) {
int V_310 ;
if ( F_268 ( V_19 ) )
return - V_263 ;
V_310 = F_203 ( V_2 , 1 ,
V_276 , true ) ;
if ( ! V_310 ) {
V_243 -- ;
F_277 ( V_311 , V_312 / 10 ) ;
}
}
return 0 ;
}
static T_5 F_278 ( struct V_313 * V_314 ,
char * V_315 , T_6 V_316 ,
T_7 V_317 )
{
struct V_1 * V_2 = F_2 ( F_279 ( V_314 ) ) ;
if ( F_6 ( V_2 ) )
return - V_294 ;
return F_275 ( V_2 ) ? : V_316 ;
}
static V_146 F_280 ( struct V_4 * V_6 ,
struct V_318 * V_319 )
{
return F_2 ( V_6 ) -> V_106 ;
}
static int F_281 ( struct V_4 * V_6 ,
struct V_318 * V_319 , V_146 V_58 )
{
int V_320 = 0 ;
struct V_1 * V_2 = F_2 ( V_6 ) ;
struct V_1 * V_321 = F_2 ( V_2 -> V_6 . V_39 ) ;
F_119 ( & V_309 ) ;
if ( V_2 -> V_106 == V_58 )
goto V_107;
if ( ( ! V_321 || ! V_321 -> V_106 ) &&
( V_58 == 1 || V_58 == 0 ) ) {
if ( ! F_272 ( V_2 ) )
V_2 -> V_106 = V_58 ;
else
V_320 = - V_293 ;
} else
V_320 = - V_294 ;
V_107:
F_126 ( & V_309 ) ;
return V_320 ;
}
static unsigned long F_282 ( struct V_1 * V_2 ,
enum V_56 V_57 )
{
struct V_1 * V_104 ;
long V_58 = 0 ;
F_125 (iter, memcg)
V_58 += F_56 ( V_104 , V_57 ) ;
if ( V_58 < 0 )
V_58 = 0 ;
return V_58 ;
}
static inline V_146 F_283 ( struct V_1 * V_2 , bool V_322 )
{
V_146 V_58 ;
if ( F_6 ( V_2 ) ) {
V_58 = F_282 ( V_2 , V_67 ) ;
V_58 += F_282 ( V_2 , V_66 ) ;
if ( V_322 )
V_58 += F_282 ( V_2 , V_150 ) ;
} else {
if ( ! V_322 )
V_58 = F_45 ( & V_2 -> V_49 ) ;
else
V_58 = F_45 ( & V_2 -> V_133 ) ;
}
return V_58 << V_128 ;
}
static V_146 F_284 ( struct V_4 * V_6 ,
struct V_318 * V_319 )
{
struct V_1 * V_2 = F_2 ( V_6 ) ;
struct V_246 * V_247 ;
switch ( F_285 ( V_319 -> V_211 ) ) {
case V_323 :
V_247 = & V_2 -> V_49 ;
break;
case V_324 :
V_247 = & V_2 -> V_133 ;
break;
case V_325 :
V_247 = & V_2 -> V_148 ;
break;
default:
F_96 () ;
}
switch ( F_286 ( V_319 -> V_211 ) ) {
case V_326 :
if ( V_247 == & V_2 -> V_49 )
return F_283 ( V_2 , false ) ;
if ( V_247 == & V_2 -> V_133 )
return F_283 ( V_2 , true ) ;
return ( V_146 ) F_45 ( V_247 ) * V_327 ;
case V_328 :
return ( V_146 ) V_247 -> V_131 * V_327 ;
case V_329 :
return ( V_146 ) V_247 -> V_330 * V_327 ;
case V_331 :
return V_247 -> V_147 ;
case V_332 :
return ( V_146 ) V_2 -> V_50 * V_327 ;
default:
F_96 () ;
}
}
static int F_287 ( struct V_1 * V_2 ,
unsigned long V_48 )
{
int V_273 = 0 ;
int V_333 ;
F_11 ( V_2 -> V_271 >= 0 ) ;
F_11 ( V_2 -> V_334 ) ;
F_11 ( V_2 -> V_3 ) ;
F_119 ( & V_309 ) ;
if ( F_288 ( V_2 -> V_6 . V_118 ) ||
( V_2 -> V_106 && F_272 ( V_2 ) ) )
V_273 = - V_293 ;
F_126 ( & V_309 ) ;
if ( V_273 )
goto V_107;
V_333 = F_228 () ;
if ( V_333 < 0 ) {
V_273 = V_333 ;
goto V_107;
}
V_273 = F_269 ( & V_2 -> V_148 , V_48 ) ;
F_72 ( V_273 ) ;
F_289 ( & V_335 ) ;
V_2 -> V_271 = V_333 ;
V_2 -> V_334 = true ;
V_2 -> V_3 = true ;
V_107:
return V_273 ;
}
static int F_290 ( struct V_1 * V_2 ,
unsigned long V_131 )
{
int V_121 ;
F_119 ( & V_305 ) ;
if ( ! F_1 ( V_2 ) )
V_121 = F_287 ( V_2 , V_131 ) ;
else
V_121 = F_269 ( & V_2 -> V_148 , V_131 ) ;
F_126 ( & V_305 ) ;
return V_121 ;
}
static int F_291 ( struct V_1 * V_2 )
{
int V_121 = 0 ;
struct V_1 * V_39 = F_48 ( V_2 ) ;
if ( ! V_39 )
return 0 ;
F_119 ( & V_305 ) ;
if ( F_1 ( V_39 ) )
V_121 = F_287 ( V_2 , V_336 ) ;
F_126 ( & V_305 ) ;
return V_121 ;
}
static int F_290 ( struct V_1 * V_2 ,
unsigned long V_131 )
{
return - V_294 ;
}
static T_5 F_292 ( struct V_313 * V_314 ,
char * V_315 , T_6 V_316 , T_7 V_317 )
{
struct V_1 * V_2 = F_2 ( F_279 ( V_314 ) ) ;
unsigned long V_48 ;
int V_121 ;
V_315 = F_293 ( V_315 ) ;
V_121 = F_294 ( V_315 , L_12 , & V_48 ) ;
if ( V_121 )
return V_121 ;
switch ( F_286 ( F_295 ( V_314 ) -> V_211 ) ) {
case V_328 :
if ( F_6 ( V_2 ) ) {
V_121 = - V_294 ;
break;
}
switch ( F_285 ( F_295 ( V_314 ) -> V_211 ) ) {
case V_323 :
V_121 = F_267 ( V_2 , V_48 ) ;
break;
case V_324 :
V_121 = F_270 ( V_2 , V_48 ) ;
break;
case V_325 :
V_121 = F_290 ( V_2 , V_48 ) ;
break;
}
break;
case V_332 :
V_2 -> V_50 = V_48 ;
V_121 = 0 ;
break;
}
return V_121 ? : V_316 ;
}
static T_5 F_296 ( struct V_313 * V_314 , char * V_315 ,
T_6 V_316 , T_7 V_317 )
{
struct V_1 * V_2 = F_2 ( F_279 ( V_314 ) ) ;
struct V_246 * V_247 ;
switch ( F_285 ( F_295 ( V_314 ) -> V_211 ) ) {
case V_323 :
V_247 = & V_2 -> V_49 ;
break;
case V_324 :
V_247 = & V_2 -> V_133 ;
break;
case V_325 :
V_247 = & V_2 -> V_148 ;
break;
default:
F_96 () ;
}
switch ( F_286 ( F_295 ( V_314 ) -> V_211 ) ) {
case V_329 :
F_297 ( V_247 ) ;
break;
case V_331 :
V_247 -> V_147 = 0 ;
break;
default:
F_96 () ;
}
return V_316 ;
}
static V_146 F_298 ( struct V_4 * V_6 ,
struct V_318 * V_319 )
{
return F_2 ( V_6 ) -> V_337 ;
}
static int F_299 ( struct V_4 * V_6 ,
struct V_318 * V_319 , V_146 V_58 )
{
struct V_1 * V_2 = F_2 ( V_6 ) ;
if ( V_58 & ~ V_338 )
return - V_294 ;
V_2 -> V_337 = V_58 ;
return 0 ;
}
static int F_299 ( struct V_4 * V_6 ,
struct V_318 * V_319 , V_146 V_58 )
{
return - V_339 ;
}
static int F_300 ( struct V_340 * V_341 , void * V_342 )
{
struct V_343 {
const char * V_344 ;
unsigned int V_76 ;
};
static const struct V_343 V_345 [] = {
{ L_13 , V_346 } ,
{ L_14 , V_172 } ,
{ L_15 , V_173 } ,
{ L_16 , F_74 (LRU_UNEVICTABLE) } ,
} ;
const struct V_343 * V_60 ;
int V_24 ;
unsigned long V_77 ;
struct V_1 * V_2 = F_2 ( F_301 ( V_341 ) ) ;
for ( V_60 = V_345 ; V_60 < V_345 + F_302 ( V_345 ) ; V_60 ++ ) {
V_77 = F_75 ( V_2 , V_60 -> V_76 ) ;
F_303 ( V_341 , L_17 , V_60 -> V_344 , V_77 ) ;
F_76 (nid, N_MEMORY) {
V_77 = F_71 ( V_2 , V_24 ,
V_60 -> V_76 ) ;
F_303 ( V_341 , L_18 , V_24 , V_77 ) ;
}
F_304 ( V_341 , '\n' ) ;
}
for ( V_60 = V_345 ; V_60 < V_345 + F_302 ( V_345 ) ; V_60 ++ ) {
struct V_1 * V_104 ;
V_77 = 0 ;
F_125 (iter, memcg)
V_77 += F_75 ( V_104 , V_60 -> V_76 ) ;
F_303 ( V_341 , L_19 , V_60 -> V_344 , V_77 ) ;
F_76 (nid, N_MEMORY) {
V_77 = 0 ;
F_125 (iter, memcg)
V_77 += F_71 (
V_104 , V_24 , V_60 -> V_76 ) ;
F_303 ( V_341 , L_18 , V_24 , V_77 ) ;
}
F_304 ( V_341 , '\n' ) ;
}
return 0 ;
}
static int F_305 ( struct V_340 * V_341 , void * V_342 )
{
struct V_1 * V_2 = F_2 ( F_301 ( V_341 ) ) ;
unsigned long V_49 , V_133 ;
struct V_1 * V_347 ;
unsigned int V_145 ;
F_306 ( F_302 ( V_151 ) !=
V_149 ) ;
F_306 ( F_302 ( V_348 ) !=
V_233 ) ;
F_306 ( F_302 ( V_153 ) != V_152 ) ;
for ( V_145 = 0 ; V_145 < V_149 ; V_145 ++ ) {
if ( V_145 == V_150 && ! V_132 )
continue;
F_303 ( V_341 , L_20 , V_151 [ V_145 ] ,
F_56 ( V_2 , V_145 ) * V_327 ) ;
}
for ( V_145 = 0 ; V_145 < V_233 ; V_145 ++ )
F_303 ( V_341 , L_21 , V_348 [ V_145 ] ,
F_64 ( V_2 , V_145 ) ) ;
for ( V_145 = 0 ; V_145 < V_152 ; V_145 ++ )
F_303 ( V_341 , L_21 , V_153 [ V_145 ] ,
F_75 ( V_2 , F_74 ( V_145 ) ) * V_327 ) ;
V_49 = V_133 = V_336 ;
for ( V_347 = V_2 ; V_347 ; V_347 = F_48 ( V_347 ) ) {
V_49 = F_109 ( V_49 , V_347 -> V_49 . V_131 ) ;
V_133 = F_109 ( V_133 , V_347 -> V_133 . V_131 ) ;
}
F_303 ( V_341 , L_22 ,
( V_146 ) V_49 * V_327 ) ;
if ( V_132 )
F_303 ( V_341 , L_23 ,
( V_146 ) V_133 * V_327 ) ;
for ( V_145 = 0 ; V_145 < V_149 ; V_145 ++ ) {
long long V_58 = 0 ;
if ( V_145 == V_150 && ! V_132 )
continue;
F_125 (mi, memcg)
V_58 += F_56 ( V_347 , V_145 ) * V_327 ;
F_303 ( V_341 , L_24 , V_151 [ V_145 ] , V_58 ) ;
}
for ( V_145 = 0 ; V_145 < V_233 ; V_145 ++ ) {
unsigned long long V_58 = 0 ;
F_125 (mi, memcg)
V_58 += F_64 ( V_347 , V_145 ) ;
F_303 ( V_341 , L_25 ,
V_348 [ V_145 ] , V_58 ) ;
}
for ( V_145 = 0 ; V_145 < V_152 ; V_145 ++ ) {
unsigned long long V_58 = 0 ;
F_125 (mi, memcg)
V_58 += F_75 ( V_347 , F_74 ( V_145 ) ) * V_327 ;
F_303 ( V_341 , L_25 , V_153 [ V_145 ] , V_58 ) ;
}
#ifdef F_307
{
int V_24 , V_25 ;
struct V_22 * V_33 ;
struct V_349 * V_350 ;
unsigned long V_351 [ 2 ] = { 0 , 0 } ;
unsigned long V_352 [ 2 ] = { 0 , 0 } ;
F_308 (nid)
for ( V_25 = 0 ; V_25 < V_52 ; V_25 ++ ) {
V_33 = & V_2 -> V_26 [ V_24 ] -> V_27 [ V_25 ] ;
V_350 = & V_33 -> V_72 . V_353 ;
V_351 [ 0 ] += V_350 -> V_351 [ 0 ] ;
V_351 [ 1 ] += V_350 -> V_351 [ 1 ] ;
V_352 [ 0 ] += V_350 -> V_352 [ 0 ] ;
V_352 [ 1 ] += V_350 -> V_352 [ 1 ] ;
}
F_303 ( V_341 , L_26 , V_351 [ 0 ] ) ;
F_303 ( V_341 , L_27 , V_351 [ 1 ] ) ;
F_303 ( V_341 , L_28 , V_352 [ 0 ] ) ;
F_303 ( V_341 , L_29 , V_352 [ 1 ] ) ;
}
#endif
return 0 ;
}
static V_146 F_309 ( struct V_4 * V_6 ,
struct V_318 * V_319 )
{
struct V_1 * V_2 = F_2 ( V_6 ) ;
return F_110 ( V_2 ) ;
}
static int F_310 ( struct V_4 * V_6 ,
struct V_318 * V_319 , V_146 V_58 )
{
struct V_1 * V_2 = F_2 ( V_6 ) ;
if ( V_58 > 100 )
return - V_294 ;
if ( V_6 -> V_39 )
V_2 -> V_135 = V_58 ;
else
V_134 = V_58 ;
return 0 ;
}
static void F_311 ( struct V_1 * V_2 , bool V_322 )
{
struct V_354 * V_355 ;
unsigned long V_356 ;
int V_145 ;
F_13 () ;
if ( ! V_322 )
V_355 = F_86 ( V_2 -> V_357 . V_358 ) ;
else
V_355 = F_86 ( V_2 -> V_359 . V_358 ) ;
if ( ! V_355 )
goto V_139;
V_356 = F_283 ( V_2 , V_322 ) ;
V_145 = V_355 -> V_360 ;
for (; V_145 >= 0 && F_81 ( V_355 -> V_361 [ V_145 ] . V_362 > V_356 ) ; V_145 -- )
F_312 ( V_355 -> V_361 [ V_145 ] . V_363 , 1 ) ;
V_145 ++ ;
for (; V_145 < V_355 -> V_272 && F_81 ( V_355 -> V_361 [ V_145 ] . V_362 <= V_356 ) ; V_145 ++ )
F_312 ( V_355 -> V_361 [ V_145 ] . V_363 , 1 ) ;
V_355 -> V_360 = V_145 - 1 ;
V_139:
F_17 () ;
}
static void F_82 ( struct V_1 * V_2 )
{
while ( V_2 ) {
F_311 ( V_2 , false ) ;
if ( V_132 )
F_311 ( V_2 , true ) ;
V_2 = F_48 ( V_2 ) ;
}
}
static int F_313 ( const void * V_364 , const void * V_365 )
{
const struct F_82 * V_366 = V_364 ;
const struct F_82 * V_367 = V_365 ;
if ( V_366 -> V_362 > V_367 -> V_362 )
return 1 ;
if ( V_366 -> V_362 < V_367 -> V_362 )
return - 1 ;
return 0 ;
}
static int F_314 ( struct V_1 * V_2 )
{
struct V_368 * V_369 ;
F_61 ( & V_188 ) ;
F_315 (ev, &memcg->oom_notify, list)
F_312 ( V_369 -> V_363 , 1 ) ;
F_62 ( & V_188 ) ;
return 0 ;
}
static void F_171 ( struct V_1 * V_2 )
{
struct V_1 * V_104 ;
F_125 (iter, memcg)
F_314 ( V_104 ) ;
}
static int F_316 ( struct V_1 * V_2 ,
struct V_370 * V_363 , const char * args , enum V_371 type )
{
struct V_372 * V_357 ;
struct V_354 * V_373 ;
unsigned long V_362 ;
unsigned long V_356 ;
int V_145 , V_272 , V_121 ;
V_121 = F_294 ( args , L_12 , & V_362 ) ;
if ( V_121 )
return V_121 ;
F_119 ( & V_2 -> V_374 ) ;
if ( type == V_323 ) {
V_357 = & V_2 -> V_357 ;
V_356 = F_283 ( V_2 , false ) ;
} else if ( type == V_324 ) {
V_357 = & V_2 -> V_359 ;
V_356 = F_283 ( V_2 , true ) ;
} else
F_96 () ;
if ( V_357 -> V_358 )
F_311 ( V_2 , type == V_324 ) ;
V_272 = V_357 -> V_358 ? V_357 -> V_358 -> V_272 + 1 : 1 ;
V_373 = F_240 ( sizeof( * V_373 ) + V_272 * sizeof( struct F_82 ) ,
V_276 ) ;
if ( ! V_373 ) {
V_121 = - V_262 ;
goto V_139;
}
V_373 -> V_272 = V_272 ;
if ( V_357 -> V_358 ) {
memcpy ( V_373 -> V_361 , V_357 -> V_358 -> V_361 , ( V_272 - 1 ) *
sizeof( struct F_82 ) ) ;
}
V_373 -> V_361 [ V_272 - 1 ] . V_363 = V_363 ;
V_373 -> V_361 [ V_272 - 1 ] . V_362 = V_362 ;
F_317 ( V_373 -> V_361 , V_272 , sizeof( struct F_82 ) ,
F_313 , NULL ) ;
V_373 -> V_360 = - 1 ;
for ( V_145 = 0 ; V_145 < V_272 ; V_145 ++ ) {
if ( V_373 -> V_361 [ V_145 ] . V_362 <= V_356 ) {
++ V_373 -> V_360 ;
} else
break;
}
F_238 ( V_357 -> V_375 ) ;
V_357 -> V_375 = V_357 -> V_358 ;
F_318 ( V_357 -> V_358 , V_373 ) ;
F_319 () ;
V_139:
F_126 ( & V_2 -> V_374 ) ;
return V_121 ;
}
static int F_320 ( struct V_1 * V_2 ,
struct V_370 * V_363 , const char * args )
{
return F_316 ( V_2 , V_363 , args , V_323 ) ;
}
static int F_321 ( struct V_1 * V_2 ,
struct V_370 * V_363 , const char * args )
{
return F_316 ( V_2 , V_363 , args , V_324 ) ;
}
static void F_322 ( struct V_1 * V_2 ,
struct V_370 * V_363 , enum V_371 type )
{
struct V_372 * V_357 ;
struct V_354 * V_373 ;
unsigned long V_356 ;
int V_145 , V_376 , V_272 ;
F_119 ( & V_2 -> V_374 ) ;
if ( type == V_323 ) {
V_357 = & V_2 -> V_357 ;
V_356 = F_283 ( V_2 , false ) ;
} else if ( type == V_324 ) {
V_357 = & V_2 -> V_359 ;
V_356 = F_283 ( V_2 , true ) ;
} else
F_96 () ;
if ( ! V_357 -> V_358 )
goto V_139;
F_311 ( V_2 , type == V_324 ) ;
V_272 = 0 ;
for ( V_145 = 0 ; V_145 < V_357 -> V_358 -> V_272 ; V_145 ++ ) {
if ( V_357 -> V_358 -> V_361 [ V_145 ] . V_363 != V_363 )
V_272 ++ ;
}
V_373 = V_357 -> V_375 ;
if ( ! V_272 ) {
F_238 ( V_373 ) ;
V_373 = NULL ;
goto V_377;
}
V_373 -> V_272 = V_272 ;
V_373 -> V_360 = - 1 ;
for ( V_145 = 0 , V_376 = 0 ; V_145 < V_357 -> V_358 -> V_272 ; V_145 ++ ) {
if ( V_357 -> V_358 -> V_361 [ V_145 ] . V_363 == V_363 )
continue;
V_373 -> V_361 [ V_376 ] = V_357 -> V_358 -> V_361 [ V_145 ] ;
if ( V_373 -> V_361 [ V_376 ] . V_362 <= V_356 ) {
++ V_373 -> V_360 ;
}
V_376 ++ ;
}
V_377:
V_357 -> V_375 = V_357 -> V_358 ;
if ( ! V_373 ) {
F_238 ( V_357 -> V_375 ) ;
V_357 -> V_375 = NULL ;
}
F_318 ( V_357 -> V_358 , V_373 ) ;
F_319 () ;
V_139:
F_126 ( & V_2 -> V_374 ) ;
}
static void F_323 ( struct V_1 * V_2 ,
struct V_370 * V_363 )
{
return F_322 ( V_2 , V_363 , V_323 ) ;
}
static void F_324 ( struct V_1 * V_2 ,
struct V_370 * V_363 )
{
return F_322 ( V_2 , V_363 , V_324 ) ;
}
static int F_325 ( struct V_1 * V_2 ,
struct V_370 * V_363 , const char * args )
{
struct V_368 * V_378 ;
V_378 = F_240 ( sizeof( * V_378 ) , V_276 ) ;
if ( ! V_378 )
return - V_262 ;
F_61 ( & V_188 ) ;
V_378 -> V_363 = V_363 ;
F_326 ( & V_378 -> V_379 , & V_2 -> V_380 ) ;
if ( F_145 ( & V_2 -> V_192 ) )
F_312 ( V_363 , 1 ) ;
F_62 ( & V_188 ) ;
return 0 ;
}
static void F_327 ( struct V_1 * V_2 ,
struct V_370 * V_363 )
{
struct V_368 * V_369 , * V_381 ;
F_61 ( & V_188 ) ;
F_328 (ev, tmp, &memcg->oom_notify, list) {
if ( V_369 -> V_363 == V_363 ) {
F_329 ( & V_369 -> V_379 ) ;
F_238 ( V_369 ) ;
}
}
F_62 ( & V_188 ) ;
}
static int F_330 ( struct V_340 * V_382 , void * V_342 )
{
struct V_1 * V_2 = F_2 ( F_301 ( V_382 ) ) ;
F_303 ( V_382 , L_30 , V_2 -> V_214 ) ;
F_303 ( V_382 , L_31 , ( bool ) F_145 ( & V_2 -> V_192 ) ) ;
return 0 ;
}
static int F_331 ( struct V_4 * V_6 ,
struct V_318 * V_319 , V_146 V_58 )
{
struct V_1 * V_2 = F_2 ( V_6 ) ;
if ( ! V_6 -> V_39 || ! ( ( V_58 == 0 ) || ( V_58 == 1 ) ) )
return - V_294 ;
V_2 -> V_214 = V_58 ;
if ( ! V_58 )
F_167 ( V_2 ) ;
return 0 ;
}
static int F_332 ( struct V_1 * V_2 , struct V_383 * V_384 )
{
int V_121 ;
V_121 = F_291 ( V_2 ) ;
if ( V_121 )
return V_121 ;
return F_333 ( V_2 , V_384 ) ;
}
static void F_334 ( struct V_1 * V_2 )
{
struct V_4 * V_6 ;
struct V_1 * V_39 , * V_385 ;
int V_271 ;
if ( ! V_2 -> V_3 )
return;
V_2 -> V_3 = false ;
F_335 ( V_2 ) ;
V_271 = V_2 -> V_271 ;
F_11 ( V_271 < 0 ) ;
V_39 = F_48 ( V_2 ) ;
if ( ! V_39 )
V_39 = V_8 ;
F_336 (css, &memcg->css) {
V_385 = F_2 ( V_6 ) ;
F_11 ( V_385 -> V_271 != V_271 ) ;
V_385 -> V_271 = V_39 -> V_271 ;
if ( ! V_2 -> V_106 )
break;
}
F_337 ( V_271 , V_39 -> V_271 ) ;
F_235 ( V_271 ) ;
}
static void F_338 ( struct V_1 * V_2 )
{
if ( V_2 -> V_334 ) {
F_339 ( V_2 ) ;
F_340 ( & V_335 ) ;
F_19 ( F_45 ( & V_2 -> V_148 ) ) ;
}
F_341 ( V_2 ) ;
}
static int F_332 ( struct V_1 * V_2 , struct V_383 * V_384 )
{
return 0 ;
}
static void F_334 ( struct V_1 * V_2 )
{
}
static void F_338 ( struct V_1 * V_2 )
{
}
static void F_342 ( struct V_226 * V_231 )
{
struct V_386 * V_378 =
F_3 ( V_231 , struct V_386 , remove ) ;
struct V_1 * V_2 = V_378 -> V_2 ;
F_343 ( V_378 -> V_387 , & V_378 -> V_141 ) ;
V_378 -> V_388 ( V_2 , V_378 -> V_363 ) ;
F_312 ( V_378 -> V_363 , 1 ) ;
F_344 ( V_378 -> V_363 ) ;
F_238 ( V_378 ) ;
F_20 ( & V_2 -> V_6 ) ;
}
static int F_345 ( T_3 * V_141 , unsigned V_193 ,
int V_194 , void * V_389 )
{
struct V_386 * V_378 =
F_3 ( V_141 , struct V_386 , V_141 ) ;
struct V_1 * V_2 = V_378 -> V_2 ;
unsigned long V_46 = ( unsigned long ) V_389 ;
if ( V_46 & V_390 ) {
F_61 ( & V_2 -> V_391 ) ;
if ( ! F_346 ( & V_378 -> V_379 ) ) {
F_347 ( & V_378 -> V_379 ) ;
F_242 ( & V_378 -> remove ) ;
}
F_62 ( & V_2 -> V_391 ) ;
}
return 0 ;
}
static void F_348 ( struct V_392 * V_392 ,
T_8 * V_387 , T_9 * V_393 )
{
struct V_386 * V_378 =
F_3 ( V_393 , struct V_386 , V_393 ) ;
V_378 -> V_387 = V_387 ;
F_349 ( V_387 , & V_378 -> V_141 ) ;
}
static T_5 F_350 ( struct V_313 * V_314 ,
char * V_315 , T_6 V_316 , T_7 V_317 )
{
struct V_4 * V_6 = F_279 ( V_314 ) ;
struct V_1 * V_2 = F_2 ( V_6 ) ;
struct V_386 * V_378 ;
struct V_4 * V_394 ;
unsigned int V_395 , V_396 ;
struct V_397 V_398 ;
struct V_397 V_399 ;
const char * V_344 ;
char * V_400 ;
int V_121 ;
V_315 = F_293 ( V_315 ) ;
V_395 = F_351 ( V_315 , & V_400 , 10 ) ;
if ( * V_400 != ' ' )
return - V_294 ;
V_315 = V_400 + 1 ;
V_396 = F_351 ( V_315 , & V_400 , 10 ) ;
if ( ( * V_400 != ' ' ) && ( * V_400 != '\0' ) )
return - V_294 ;
V_315 = V_400 + 1 ;
V_378 = F_352 ( sizeof( * V_378 ) , V_276 ) ;
if ( ! V_378 )
return - V_262 ;
V_378 -> V_2 = V_2 ;
F_170 ( & V_378 -> V_379 ) ;
F_353 ( & V_378 -> V_393 , F_348 ) ;
F_354 ( & V_378 -> V_141 , F_345 ) ;
F_241 ( & V_378 -> remove , F_342 ) ;
V_398 = F_355 ( V_395 ) ;
if ( ! V_398 . V_392 ) {
V_121 = - V_401 ;
goto V_402;
}
V_378 -> V_363 = F_356 ( V_398 . V_392 ) ;
if ( F_357 ( V_378 -> V_363 ) ) {
V_121 = F_358 ( V_378 -> V_363 ) ;
goto V_403;
}
V_399 = F_355 ( V_396 ) ;
if ( ! V_399 . V_392 ) {
V_121 = - V_401 ;
goto V_404;
}
V_121 = F_359 ( F_360 ( V_399 . V_392 ) , V_405 ) ;
if ( V_121 < 0 )
goto V_406;
V_344 = V_399 . V_392 -> V_407 . V_408 -> V_409 . V_344 ;
if ( ! strcmp ( V_344 , L_32 ) ) {
V_378 -> V_410 = F_320 ;
V_378 -> V_388 = F_323 ;
} else if ( ! strcmp ( V_344 , L_33 ) ) {
V_378 -> V_410 = F_325 ;
V_378 -> V_388 = F_327 ;
} else if ( ! strcmp ( V_344 , L_34 ) ) {
V_378 -> V_410 = V_411 ;
V_378 -> V_388 = V_412 ;
} else if ( ! strcmp ( V_344 , L_35 ) ) {
V_378 -> V_410 = F_321 ;
V_378 -> V_388 = F_324 ;
} else {
V_121 = - V_294 ;
goto V_406;
}
V_394 = F_361 ( V_399 . V_392 -> V_407 . V_408 -> V_413 ,
& V_11 ) ;
V_121 = - V_294 ;
if ( F_357 ( V_394 ) )
goto V_406;
if ( V_394 != V_6 ) {
F_20 ( V_394 ) ;
goto V_406;
}
V_121 = V_378 -> V_410 ( V_2 , V_378 -> V_363 , V_315 ) ;
if ( V_121 )
goto V_414;
V_398 . V_392 -> V_415 -> V_416 ( V_398 . V_392 , & V_378 -> V_393 ) ;
F_61 ( & V_2 -> V_391 ) ;
F_326 ( & V_378 -> V_379 , & V_2 -> V_417 ) ;
F_62 ( & V_2 -> V_391 ) ;
F_362 ( V_399 ) ;
F_362 ( V_398 ) ;
return V_316 ;
V_414:
F_20 ( V_6 ) ;
V_406:
F_362 ( V_399 ) ;
V_404:
F_344 ( V_378 -> V_363 ) ;
V_403:
F_362 ( V_398 ) ;
V_402:
F_238 ( V_378 ) ;
return V_121 ;
}
static int F_363 ( struct V_1 * V_2 , int V_178 )
{
struct V_418 * V_419 ;
struct V_22 * V_33 ;
int V_23 , V_381 = V_178 ;
if ( ! F_364 ( V_178 , V_420 ) )
V_381 = - 1 ;
V_419 = F_365 ( sizeof( * V_419 ) , V_276 , V_381 ) ;
if ( ! V_419 )
return 1 ;
for ( V_23 = 0 ; V_23 < V_52 ; V_23 ++ ) {
V_33 = & V_419 -> V_27 [ V_23 ] ;
F_366 ( & V_33 -> V_72 ) ;
V_33 -> V_42 = 0 ;
V_33 -> V_41 = false ;
V_33 -> V_2 = V_2 ;
}
V_2 -> V_26 [ V_178 ] = V_419 ;
return 0 ;
}
static void F_367 ( struct V_1 * V_2 , int V_178 )
{
F_238 ( V_2 -> V_26 [ V_178 ] ) ;
}
static struct V_1 * F_368 ( void )
{
struct V_1 * V_2 ;
T_6 V_272 ;
V_272 = sizeof( struct V_1 ) ;
V_272 += V_78 * sizeof( struct V_418 * ) ;
V_2 = F_352 ( V_272 , V_276 ) ;
if ( ! V_2 )
return NULL ;
V_2 -> V_60 = F_369 ( struct V_421 ) ;
if ( ! V_2 -> V_60 )
goto V_422;
F_370 ( & V_2 -> V_62 ) ;
return V_2 ;
V_422:
F_238 ( V_2 ) ;
return NULL ;
}
static void F_371 ( struct V_1 * V_2 )
{
int V_178 ;
F_49 ( V_2 ) ;
F_50 (node)
F_367 ( V_2 , V_178 ) ;
F_372 ( V_2 -> V_60 ) ;
F_238 ( V_2 ) ;
}
struct V_1 * F_48 ( struct V_1 * V_2 )
{
if ( ! V_2 -> V_49 . V_39 )
return NULL ;
return F_199 ( V_2 -> V_49 . V_39 , V_49 ) ;
}
static struct V_4 * T_10
F_373 ( struct V_4 * V_423 )
{
struct V_1 * V_2 ;
long error = - V_262 ;
int V_178 ;
V_2 = F_368 () ;
if ( ! V_2 )
return F_374 ( error ) ;
F_50 (node)
if ( F_363 ( V_2 , V_178 ) )
goto V_424;
if ( V_423 == NULL ) {
V_8 = V_2 ;
F_375 ( & V_2 -> V_49 , NULL ) ;
V_2 -> V_264 = V_336 ;
V_2 -> V_50 = V_336 ;
F_375 ( & V_2 -> V_133 , NULL ) ;
F_375 ( & V_2 -> V_148 , NULL ) ;
}
V_2 -> V_179 = V_91 ;
F_170 ( & V_2 -> V_380 ) ;
V_2 -> V_337 = 0 ;
F_376 ( & V_2 -> V_374 ) ;
F_370 ( & V_2 -> V_217 ) ;
F_377 ( & V_2 -> V_7 ) ;
F_170 ( & V_2 -> V_417 ) ;
F_370 ( & V_2 -> V_391 ) ;
#ifdef F_378
V_2 -> V_271 = - 1 ;
#endif
return & V_2 -> V_6 ;
V_424:
F_371 ( V_2 ) ;
return F_374 ( error ) ;
}
static int
F_379 ( struct V_4 * V_6 )
{
struct V_1 * V_2 = F_2 ( V_6 ) ;
struct V_1 * V_39 = F_2 ( V_6 -> V_39 ) ;
int V_121 ;
if ( V_6 -> V_10 > V_425 )
return - V_426 ;
if ( ! V_39 )
return 0 ;
F_119 ( & V_309 ) ;
V_2 -> V_106 = V_39 -> V_106 ;
V_2 -> V_214 = V_39 -> V_214 ;
V_2 -> V_135 = F_110 ( V_39 ) ;
if ( V_39 -> V_106 ) {
F_375 ( & V_2 -> V_49 , & V_39 -> V_49 ) ;
V_2 -> V_264 = V_336 ;
V_2 -> V_50 = V_336 ;
F_375 ( & V_2 -> V_133 , & V_39 -> V_133 ) ;
F_375 ( & V_2 -> V_148 , & V_39 -> V_148 ) ;
} else {
F_375 ( & V_2 -> V_49 , NULL ) ;
V_2 -> V_264 = V_336 ;
V_2 -> V_50 = V_336 ;
F_375 ( & V_2 -> V_133 , NULL ) ;
F_375 ( & V_2 -> V_148 , NULL ) ;
if ( V_39 != V_8 )
V_11 . V_427 = true ;
}
F_126 ( & V_309 ) ;
V_121 = F_332 ( V_2 , & V_11 ) ;
if ( V_121 )
return V_121 ;
F_380 ( & V_2 -> V_112 , 1 ) ;
return 0 ;
}
static void F_381 ( struct V_4 * V_6 )
{
struct V_1 * V_2 = F_2 ( V_6 ) ;
struct V_386 * V_378 , * V_381 ;
F_61 ( & V_2 -> V_391 ) ;
F_328 (event, tmp, &memcg->event_list, list) {
F_347 ( & V_378 -> V_379 ) ;
F_242 ( & V_378 -> remove ) ;
}
F_62 ( & V_2 -> V_391 ) ;
F_382 ( & V_2 -> V_7 ) ;
F_334 ( V_2 ) ;
}
static void F_383 ( struct V_4 * V_6 )
{
struct V_1 * V_2 = F_2 ( V_6 ) ;
F_338 ( V_2 ) ;
F_371 ( V_2 ) ;
}
static void F_384 ( struct V_4 * V_6 )
{
struct V_1 * V_2 = F_2 ( V_6 ) ;
F_267 ( V_2 , V_336 ) ;
F_270 ( V_2 , V_336 ) ;
F_290 ( V_2 , V_336 ) ;
V_2 -> V_428 = 0 ;
V_2 -> V_264 = V_336 ;
V_2 -> V_50 = V_336 ;
}
static int F_385 ( unsigned long V_61 )
{
int V_121 ;
V_121 = F_196 ( V_138 . V_137 , V_276 & ~ V_256 , V_61 ) ;
if ( ! V_121 ) {
V_138 . V_429 += V_61 ;
return V_121 ;
}
if ( V_121 == - V_263 ) {
F_206 ( V_8 , V_61 ) ;
return V_121 ;
}
while ( V_61 -- ) {
V_121 = F_196 ( V_138 . V_137 , V_276 & ~ V_258 , 1 ) ;
if ( V_121 == - V_263 )
F_206 ( V_8 , 1 ) ;
if ( V_121 )
return V_121 ;
V_138 . V_429 ++ ;
F_386 () ;
}
return 0 ;
}
static struct V_28 * F_387 ( struct V_430 * V_431 ,
unsigned long V_432 , T_11 V_433 )
{
struct V_28 * V_28 = F_388 ( V_431 , V_432 , V_433 ) ;
if ( ! V_28 || ! F_259 ( V_28 ) )
return NULL ;
if ( F_66 ( V_28 ) ) {
if ( ! ( V_138 . V_46 & V_434 ) )
return NULL ;
} else {
if ( ! ( V_138 . V_46 & V_435 ) )
return NULL ;
}
if ( ! F_389 ( V_28 ) )
return NULL ;
return V_28 ;
}
static struct V_28 * F_390 ( struct V_430 * V_431 ,
unsigned long V_432 , T_11 V_433 , T_4 * V_298 )
{
struct V_28 * V_28 = NULL ;
T_4 V_266 = F_391 ( V_433 ) ;
if ( ! ( V_138 . V_46 & V_434 ) || F_392 ( V_266 ) )
return NULL ;
V_28 = F_393 ( F_394 ( V_266 ) , V_266 . V_58 ) ;
if ( V_132 )
V_298 -> V_58 = V_266 . V_58 ;
return V_28 ;
}
static struct V_28 * F_390 ( struct V_430 * V_431 ,
unsigned long V_432 , T_11 V_433 , T_4 * V_298 )
{
return NULL ;
}
static struct V_28 * F_395 ( struct V_430 * V_431 ,
unsigned long V_432 , T_11 V_433 , T_4 * V_298 )
{
struct V_28 * V_28 = NULL ;
struct V_436 * V_437 ;
T_12 V_438 ;
if ( ! V_431 -> V_439 )
return NULL ;
if ( ! ( V_138 . V_46 & V_435 ) )
return NULL ;
V_437 = V_431 -> V_439 -> V_440 ;
V_438 = F_396 ( V_431 , V_432 ) ;
#ifdef F_397
if ( F_398 ( V_437 ) ) {
V_28 = F_399 ( V_437 , V_438 ) ;
if ( F_400 ( V_28 ) ) {
T_4 V_441 = F_401 ( V_28 ) ;
if ( V_132 )
* V_298 = V_441 ;
V_28 = F_393 ( F_394 ( V_441 ) , V_441 . V_58 ) ;
}
} else
V_28 = F_393 ( V_437 , V_438 ) ;
#else
V_28 = F_393 ( V_437 , V_438 ) ;
#endif
return V_28 ;
}
static enum V_442 F_402 ( struct V_430 * V_431 ,
unsigned long V_432 , T_11 V_433 , union V_443 * V_80 )
{
struct V_28 * V_28 = NULL ;
enum V_442 V_121 = V_444 ;
T_4 V_266 = { . V_58 = 0 } ;
if ( F_403 ( V_433 ) )
V_28 = F_387 ( V_431 , V_432 , V_433 ) ;
else if ( F_404 ( V_433 ) )
V_28 = F_390 ( V_431 , V_432 , V_433 , & V_266 ) ;
else if ( F_405 ( V_433 ) )
V_28 = F_395 ( V_431 , V_432 , V_433 , & V_266 ) ;
if ( ! V_28 && ! V_266 . V_58 )
return V_121 ;
if ( V_28 ) {
if ( V_28 -> V_1 == V_138 . V_136 ) {
V_121 = V_445 ;
if ( V_80 )
V_80 -> V_28 = V_28 ;
}
if ( ! V_121 || ! V_80 )
F_406 ( V_28 ) ;
}
if ( V_266 . V_58 && ! V_121 &&
F_7 ( V_138 . V_136 ) == F_213 ( V_266 ) ) {
V_121 = V_446 ;
if ( V_80 )
V_80 -> V_266 = V_266 ;
}
return V_121 ;
}
static enum V_442 F_407 ( struct V_430 * V_431 ,
unsigned long V_432 , T_13 V_447 , union V_443 * V_80 )
{
struct V_28 * V_28 = NULL ;
enum V_442 V_121 = V_444 ;
V_28 = F_408 ( V_447 ) ;
F_209 ( ! V_28 || ! F_409 ( V_28 ) , V_28 ) ;
if ( ! ( V_138 . V_46 & V_434 ) )
return V_121 ;
if ( V_28 -> V_1 == V_138 . V_136 ) {
V_121 = V_445 ;
if ( V_80 ) {
F_410 ( V_28 ) ;
V_80 -> V_28 = V_28 ;
}
}
return V_121 ;
}
static inline enum V_442 F_407 ( struct V_430 * V_431 ,
unsigned long V_432 , T_13 V_447 , union V_443 * V_80 )
{
return V_444 ;
}
static int F_411 ( T_13 * V_447 ,
unsigned long V_432 , unsigned long V_448 ,
struct V_449 * V_450 )
{
struct V_430 * V_431 = V_450 -> V_431 ;
T_11 * V_451 ;
T_14 * V_452 ;
if ( F_412 ( V_447 , V_431 , & V_452 ) == 1 ) {
if ( F_407 ( V_431 , V_432 , * V_447 , NULL ) == V_445 )
V_138 . V_429 += V_292 ;
F_62 ( V_452 ) ;
return 0 ;
}
if ( F_413 ( V_447 ) )
return 0 ;
V_451 = F_414 ( V_431 -> V_453 , V_447 , V_432 , & V_452 ) ;
for (; V_432 != V_448 ; V_451 ++ , V_432 += V_327 )
if ( F_402 ( V_431 , V_432 , * V_451 , NULL ) )
V_138 . V_429 ++ ;
F_415 ( V_451 - 1 , V_452 ) ;
F_386 () ;
return 0 ;
}
static unsigned long F_416 ( struct V_95 * V_96 )
{
unsigned long V_429 ;
struct V_449 V_454 = {
. V_455 = F_411 ,
. V_96 = V_96 ,
} ;
F_23 ( & V_96 -> V_456 ) ;
F_417 ( 0 , ~ 0UL , & V_454 ) ;
F_25 ( & V_96 -> V_456 ) ;
V_429 = V_138 . V_429 ;
V_138 . V_429 = 0 ;
return V_429 ;
}
static int F_418 ( struct V_95 * V_96 )
{
unsigned long V_429 = F_416 ( V_96 ) ;
F_72 ( V_138 . V_140 ) ;
V_138 . V_140 = V_19 ;
return F_385 ( V_429 ) ;
}
static void F_419 ( void )
{
struct V_1 * V_136 = V_138 . V_136 ;
struct V_1 * V_137 = V_138 . V_137 ;
if ( V_138 . V_429 ) {
F_206 ( V_138 . V_137 , V_138 . V_429 ) ;
V_138 . V_429 = 0 ;
}
if ( V_138 . V_457 ) {
F_206 ( V_138 . V_136 , V_138 . V_457 ) ;
V_138 . V_457 = 0 ;
}
if ( V_138 . V_458 ) {
if ( ! F_6 ( V_138 . V_136 ) )
F_181 ( & V_138 . V_136 -> V_133 , V_138 . V_458 ) ;
if ( ! F_6 ( V_138 . V_137 ) )
F_181 ( & V_138 . V_137 -> V_49 , V_138 . V_458 ) ;
F_182 ( & V_138 . V_136 -> V_6 , V_138 . V_458 ) ;
V_138 . V_458 = 0 ;
}
F_167 ( V_136 ) ;
F_167 ( V_137 ) ;
F_420 ( & V_138 . V_142 ) ;
}
static void F_421 ( void )
{
V_138 . V_140 = NULL ;
F_419 () ;
F_61 ( & V_138 . V_47 ) ;
V_138 . V_136 = NULL ;
V_138 . V_137 = NULL ;
F_62 ( & V_138 . V_47 ) ;
}
static int F_422 ( struct V_4 * V_6 ,
struct V_459 * V_460 )
{
struct V_93 * V_37 = F_423 ( V_460 ) ;
int V_121 = 0 ;
struct V_1 * V_2 = F_2 ( V_6 ) ;
unsigned long V_461 ;
V_461 = F_46 ( V_2 -> V_337 ) ;
if ( V_461 ) {
struct V_95 * V_96 ;
struct V_1 * V_136 = F_14 ( V_37 ) ;
F_72 ( V_136 == V_2 ) ;
V_96 = F_424 ( V_37 ) ;
if ( ! V_96 )
return 0 ;
if ( V_96 -> V_97 == V_37 ) {
F_72 ( V_138 . V_136 ) ;
F_72 ( V_138 . V_137 ) ;
F_72 ( V_138 . V_429 ) ;
F_72 ( V_138 . V_457 ) ;
F_72 ( V_138 . V_458 ) ;
F_61 ( & V_138 . V_47 ) ;
V_138 . V_136 = V_136 ;
V_138 . V_137 = V_2 ;
V_138 . V_46 = V_461 ;
F_62 ( & V_138 . V_47 ) ;
V_121 = F_418 ( V_96 ) ;
if ( V_121 )
F_421 () ;
}
F_425 ( V_96 ) ;
}
return V_121 ;
}
static void F_426 ( struct V_4 * V_6 ,
struct V_459 * V_460 )
{
if ( V_138 . V_137 )
F_421 () ;
}
static int F_427 ( T_13 * V_447 ,
unsigned long V_432 , unsigned long V_448 ,
struct V_449 * V_450 )
{
int V_121 = 0 ;
struct V_430 * V_431 = V_450 -> V_431 ;
T_11 * V_451 ;
T_14 * V_452 ;
enum V_442 V_462 ;
union V_443 V_80 ;
struct V_28 * V_28 ;
if ( F_412 ( V_447 , V_431 , & V_452 ) == 1 ) {
if ( V_138 . V_429 < V_292 ) {
F_62 ( V_452 ) ;
return 0 ;
}
V_462 = F_407 ( V_431 , V_432 , * V_447 , & V_80 ) ;
if ( V_462 == V_445 ) {
V_28 = V_80 . V_28 ;
if ( ! F_428 ( V_28 ) ) {
if ( ! F_257 ( V_28 , V_292 ,
V_138 . V_136 , V_138 . V_137 ) ) {
V_138 . V_429 -= V_292 ;
V_138 . V_457 += V_292 ;
}
F_429 ( V_28 ) ;
}
F_406 ( V_28 ) ;
}
F_62 ( V_452 ) ;
return 0 ;
}
if ( F_413 ( V_447 ) )
return 0 ;
V_54:
V_451 = F_414 ( V_431 -> V_453 , V_447 , V_432 , & V_452 ) ;
for (; V_432 != V_448 ; V_432 += V_327 ) {
T_11 V_433 = * ( V_451 ++ ) ;
T_4 V_266 ;
if ( ! V_138 . V_429 )
break;
switch ( F_402 ( V_431 , V_432 , V_433 , & V_80 ) ) {
case V_445 :
V_28 = V_80 . V_28 ;
if ( F_428 ( V_28 ) )
goto V_463;
if ( ! F_257 ( V_28 , 1 , V_138 . V_136 , V_138 . V_137 ) ) {
V_138 . V_429 -- ;
V_138 . V_457 ++ ;
}
F_429 ( V_28 ) ;
V_463:
F_406 ( V_28 ) ;
break;
case V_446 :
V_266 = V_80 . V_266 ;
if ( ! F_265 ( V_266 , V_138 . V_136 , V_138 . V_137 ) ) {
V_138 . V_429 -- ;
V_138 . V_458 ++ ;
}
break;
default:
break;
}
}
F_415 ( V_451 - 1 , V_452 ) ;
F_386 () ;
if ( V_432 != V_448 ) {
V_121 = F_385 ( 1 ) ;
if ( ! V_121 )
goto V_54;
}
return V_121 ;
}
static void F_430 ( struct V_95 * V_96 )
{
struct V_449 V_464 = {
. V_455 = F_427 ,
. V_96 = V_96 ,
} ;
F_276 () ;
F_83 ( & V_138 . V_136 -> V_216 ) ;
F_319 () ;
V_54:
if ( F_81 ( ! F_431 ( & V_96 -> V_456 ) ) ) {
F_419 () ;
F_386 () ;
goto V_54;
}
F_417 ( 0 , ~ 0UL , & V_464 ) ;
F_25 ( & V_96 -> V_456 ) ;
F_432 ( & V_138 . V_136 -> V_216 ) ;
}
static void F_433 ( struct V_4 * V_6 ,
struct V_459 * V_460 )
{
struct V_93 * V_37 = F_423 ( V_460 ) ;
struct V_95 * V_96 = F_424 ( V_37 ) ;
if ( V_96 ) {
if ( V_138 . V_137 )
F_430 ( V_96 ) ;
F_425 ( V_96 ) ;
}
if ( V_138 . V_137 )
F_421 () ;
}
static int F_422 ( struct V_4 * V_6 ,
struct V_459 * V_460 )
{
return 0 ;
}
static void F_426 ( struct V_4 * V_6 ,
struct V_459 * V_460 )
{
}
static void F_433 ( struct V_4 * V_6 ,
struct V_459 * V_460 )
{
}
static void F_434 ( struct V_4 * V_465 )
{
if ( F_435 ( V_465 -> V_118 ) )
V_8 -> V_106 = true ;
else
V_8 -> V_106 = false ;
}
static V_146 F_436 ( struct V_4 * V_6 ,
struct V_318 * V_319 )
{
return F_283 ( F_2 ( V_6 ) , false ) ;
}
static int F_437 ( struct V_340 * V_341 , void * V_342 )
{
struct V_1 * V_2 = F_2 ( F_301 ( V_341 ) ) ;
unsigned long V_428 = F_46 ( V_2 -> V_428 ) ;
if ( V_428 == V_336 )
F_438 ( V_341 , L_36 ) ;
else
F_303 ( V_341 , L_37 , ( V_146 ) V_428 * V_327 ) ;
return 0 ;
}
static T_5 F_439 ( struct V_313 * V_314 ,
char * V_315 , T_6 V_316 , T_7 V_317 )
{
struct V_1 * V_2 = F_2 ( F_279 ( V_314 ) ) ;
unsigned long V_428 ;
int V_273 ;
V_315 = F_293 ( V_315 ) ;
V_273 = F_294 ( V_315 , L_38 , & V_428 ) ;
if ( V_273 )
return V_273 ;
V_2 -> V_428 = V_428 ;
return V_316 ;
}
static int F_440 ( struct V_340 * V_341 , void * V_342 )
{
struct V_1 * V_2 = F_2 ( F_301 ( V_341 ) ) ;
unsigned long V_264 = F_46 ( V_2 -> V_264 ) ;
if ( V_264 == V_336 )
F_438 ( V_341 , L_36 ) ;
else
F_303 ( V_341 , L_37 , ( V_146 ) V_264 * V_327 ) ;
return 0 ;
}
static T_5 F_441 ( struct V_313 * V_314 ,
char * V_315 , T_6 V_316 , T_7 V_317 )
{
struct V_1 * V_2 = F_2 ( F_279 ( V_314 ) ) ;
unsigned long V_264 ;
int V_273 ;
V_315 = F_293 ( V_315 ) ;
V_273 = F_294 ( V_315 , L_38 , & V_264 ) ;
if ( V_273 )
return V_273 ;
V_2 -> V_264 = V_264 ;
return V_316 ;
}
static int F_442 ( struct V_340 * V_341 , void * V_342 )
{
struct V_1 * V_2 = F_2 ( F_301 ( V_341 ) ) ;
unsigned long F_197 = F_46 ( V_2 -> V_49 . V_131 ) ;
if ( F_197 == V_336 )
F_438 ( V_341 , L_36 ) ;
else
F_303 ( V_341 , L_37 , ( V_146 ) F_197 * V_327 ) ;
return 0 ;
}
static T_5 F_443 ( struct V_313 * V_314 ,
char * V_315 , T_6 V_316 , T_7 V_317 )
{
struct V_1 * V_2 = F_2 ( F_279 ( V_314 ) ) ;
unsigned long F_197 ;
int V_273 ;
V_315 = F_293 ( V_315 ) ;
V_273 = F_294 ( V_315 , L_38 , & F_197 ) ;
if ( V_273 )
return V_273 ;
V_273 = F_267 ( V_2 , F_197 ) ;
if ( V_273 )
return V_273 ;
return V_316 ;
}
static int F_444 ( struct V_340 * V_341 , void * V_342 )
{
struct V_1 * V_2 = F_2 ( F_301 ( V_341 ) ) ;
F_303 ( V_341 , L_39 , F_64 ( V_2 , V_466 ) ) ;
F_303 ( V_341 , L_40 , F_64 ( V_2 , V_265 ) ) ;
F_303 ( V_341 , L_41 , F_64 ( V_2 , V_257 ) ) ;
F_303 ( V_341 , L_42 , F_64 ( V_2 , V_261 ) ) ;
return 0 ;
}
void F_202 ( struct V_1 * V_2 ,
enum V_64 V_57 ,
unsigned int V_77 )
{
F_176 ( V_2 -> V_60 -> V_65 [ V_57 ] , V_77 ) ;
}
bool F_445 ( struct V_1 * V_98 , struct V_1 * V_2 )
{
if ( F_88 () )
return false ;
if ( V_2 == V_8 )
return false ;
if ( F_45 ( & V_2 -> V_49 ) >= V_2 -> V_428 )
return false ;
while ( V_2 != V_98 ) {
V_2 = F_48 ( V_2 ) ;
if ( V_2 == V_8 )
break;
if ( F_45 ( & V_2 -> V_49 ) >= V_2 -> V_428 )
return false ;
}
return true ;
}
int F_446 ( struct V_28 * V_28 , struct V_95 * V_96 ,
T_2 V_157 , struct V_1 * * V_467 )
{
struct V_1 * V_2 = NULL ;
unsigned int V_48 = 1 ;
int V_121 = 0 ;
if ( F_88 () )
goto V_107;
if ( F_211 ( V_28 ) ) {
if ( V_28 -> V_1 )
goto V_107;
}
if ( F_68 ( V_28 ) ) {
V_48 <<= F_447 ( V_28 ) ;
F_209 ( ! F_68 ( V_28 ) , V_28 ) ;
}
if ( V_132 && F_211 ( V_28 ) )
V_2 = F_208 ( V_28 ) ;
if ( ! V_2 )
V_2 = F_85 ( V_96 ) ;
V_121 = F_196 ( V_2 , V_157 , V_48 ) ;
F_20 ( & V_2 -> V_6 ) ;
if ( V_121 == - V_263 ) {
V_2 = V_8 ;
V_121 = 0 ;
}
V_107:
* V_467 = V_2 ;
return V_121 ;
}
void F_448 ( struct V_28 * V_28 , struct V_1 * V_2 ,
bool V_269 )
{
unsigned int V_48 = 1 ;
F_209 ( ! V_28 -> V_437 , V_28 ) ;
F_209 ( F_216 ( V_28 ) && ! V_269 , V_28 ) ;
if ( F_88 () )
return;
if ( ! V_2 )
return;
F_223 ( V_28 , V_2 , V_269 ) ;
if ( F_68 ( V_28 ) ) {
V_48 <<= F_447 ( V_28 ) ;
F_209 ( ! F_68 ( V_28 ) , V_28 ) ;
}
F_261 () ;
F_65 ( V_2 , V_28 , V_48 ) ;
F_80 ( V_2 , V_28 ) ;
F_262 () ;
if ( V_132 && F_211 ( V_28 ) ) {
T_4 V_298 = { . V_58 = F_212 (page) } ;
F_449 ( V_298 ) ;
}
}
void F_450 ( struct V_28 * V_28 , struct V_1 * V_2 )
{
unsigned int V_48 = 1 ;
if ( F_88 () )
return;
if ( ! V_2 )
return;
if ( F_68 ( V_28 ) ) {
V_48 <<= F_447 ( V_28 ) ;
F_209 ( ! F_68 ( V_28 ) , V_28 ) ;
}
F_206 ( V_2 , V_48 ) ;
}
static void F_451 ( struct V_1 * V_2 , unsigned long V_468 ,
unsigned long V_469 , unsigned long V_470 ,
unsigned long V_471 , struct V_28 * V_472 )
{
unsigned long V_48 = V_469 + V_470 ;
unsigned long V_46 ;
if ( ! F_6 ( V_2 ) ) {
F_181 ( & V_2 -> V_49 , V_48 ) ;
if ( V_132 )
F_181 ( & V_2 -> V_133 , V_48 ) ;
F_167 ( V_2 ) ;
}
F_452 ( V_46 ) ;
F_256 ( V_2 -> V_60 -> V_61 [ V_66 ] , V_469 ) ;
F_256 ( V_2 -> V_60 -> V_61 [ V_67 ] , V_470 ) ;
F_256 ( V_2 -> V_60 -> V_61 [ V_68 ] , V_471 ) ;
F_67 ( V_2 -> V_60 -> V_65 [ V_70 ] , V_468 ) ;
F_67 ( V_2 -> V_60 -> V_71 , V_48 ) ;
F_80 ( V_2 , V_472 ) ;
F_453 ( V_46 ) ;
if ( ! F_6 ( V_2 ) )
F_182 ( & V_2 -> V_6 , V_48 ) ;
}
static void F_454 ( struct V_473 * V_474 )
{
struct V_1 * V_2 = NULL ;
unsigned long V_469 = 0 ;
unsigned long V_470 = 0 ;
unsigned long V_471 = 0 ;
unsigned long V_468 = 0 ;
struct V_473 * V_81 ;
struct V_28 * V_28 ;
V_81 = V_474 -> V_81 ;
do {
unsigned int V_48 = 1 ;
V_28 = F_455 ( V_81 , struct V_28 , V_74 ) ;
V_81 = V_28 -> V_74 . V_81 ;
F_209 ( F_216 ( V_28 ) , V_28 ) ;
F_209 ( F_456 ( V_28 ) , V_28 ) ;
if ( ! V_28 -> V_1 )
continue;
if ( V_2 != V_28 -> V_1 ) {
if ( V_2 ) {
F_451 ( V_2 , V_468 , V_469 , V_470 ,
V_471 , V_28 ) ;
V_468 = V_469 = V_470 = V_471 = 0 ;
}
V_2 = V_28 -> V_1 ;
}
if ( F_68 ( V_28 ) ) {
V_48 <<= F_447 ( V_28 ) ;
F_209 ( ! F_68 ( V_28 ) , V_28 ) ;
V_471 += V_48 ;
}
if ( F_66 ( V_28 ) )
V_469 += V_48 ;
else
V_470 += V_48 ;
V_28 -> V_1 = NULL ;
V_468 ++ ;
} while ( V_81 != V_474 );
if ( V_2 )
F_451 ( V_2 , V_468 , V_469 , V_470 ,
V_471 , V_28 ) ;
}
void F_457 ( struct V_28 * V_28 )
{
if ( F_88 () )
return;
if ( ! V_28 -> V_1 )
return;
F_170 ( & V_28 -> V_74 ) ;
F_454 ( & V_28 -> V_74 ) ;
}
void F_458 ( struct V_473 * V_474 )
{
if ( F_88 () )
return;
if ( ! F_346 ( V_474 ) )
F_454 ( V_474 ) ;
}
void F_459 ( struct V_28 * V_475 , struct V_28 * V_476 ,
bool V_269 )
{
struct V_1 * V_2 ;
int V_267 ;
F_209 ( ! F_210 ( V_475 ) , V_475 ) ;
F_209 ( ! F_210 ( V_476 ) , V_476 ) ;
F_209 ( ! V_269 && F_216 ( V_475 ) , V_475 ) ;
F_209 ( ! V_269 && F_216 ( V_476 ) , V_476 ) ;
F_209 ( F_66 ( V_475 ) != F_66 ( V_476 ) , V_476 ) ;
F_209 ( F_68 ( V_475 ) != F_68 ( V_476 ) ,
V_476 ) ;
if ( F_88 () )
return;
if ( V_476 -> V_1 )
return;
V_2 = V_475 -> V_1 ;
if ( ! V_2 )
return;
if ( V_269 )
F_214 ( V_475 , & V_267 ) ;
V_475 -> V_1 = NULL ;
if ( V_269 )
F_220 ( V_475 , V_267 ) ;
F_223 ( V_476 , V_2 , V_269 ) ;
}
static int T_15 F_460 ( void )
{
int V_59 , V_178 ;
F_461 ( F_194 , 0 ) ;
F_462 (cpu)
F_241 ( & F_463 ( & V_223 , V_59 ) -> V_231 ,
F_183 ) ;
F_50 (node) {
struct V_477 * V_478 ;
int V_23 ;
V_478 = F_365 ( sizeof( * V_478 ) , V_276 ,
F_464 ( V_178 ) ? V_178 : V_479 ) ;
for ( V_23 = 0 ; V_23 < V_52 ; V_23 ++ ) {
struct V_29 * V_480 ;
V_480 = & V_478 -> V_32 [ V_23 ] ;
V_480 -> V_38 = V_481 ;
F_370 ( & V_480 -> V_47 ) ;
}
V_30 . V_31 [ V_178 ] = V_478 ;
}
return 0 ;
}
void F_465 ( struct V_28 * V_28 , T_4 V_298 )
{
struct V_1 * V_2 ;
unsigned short V_482 ;
F_209 ( F_216 ( V_28 ) , V_28 ) ;
F_209 ( F_456 ( V_28 ) , V_28 ) ;
if ( ! V_132 )
return;
V_2 = V_28 -> V_1 ;
if ( ! V_2 )
return;
V_482 = F_466 ( V_298 , F_7 ( V_2 ) ) ;
F_209 ( V_482 , V_28 ) ;
F_264 ( V_2 , true ) ;
V_28 -> V_1 = NULL ;
if ( ! F_6 ( V_2 ) )
F_181 ( & V_2 -> V_49 , 1 ) ;
F_72 ( ! F_467 () ) ;
F_65 ( V_2 , V_28 , - 1 ) ;
F_80 ( V_2 , V_28 ) ;
}
void F_449 ( T_4 V_298 )
{
struct V_1 * V_2 ;
unsigned short V_10 ;
if ( ! V_132 )
return;
V_10 = F_466 ( V_298 , 0 ) ;
F_13 () ;
V_2 = F_207 ( V_10 ) ;
if ( V_2 ) {
if ( ! F_6 ( V_2 ) )
F_181 ( & V_2 -> V_133 , 1 ) ;
F_264 ( V_2 , false ) ;
F_20 ( & V_2 -> V_6 ) ;
}
F_17 () ;
}
static int T_15 F_468 ( char * V_5 )
{
if ( ! strcmp ( V_5 , L_43 ) )
V_483 = 1 ;
else if ( ! strcmp ( V_5 , L_44 ) )
V_483 = 0 ;
return 1 ;
}
static int T_15 F_469 ( void )
{
if ( ! F_88 () && V_483 ) {
V_132 = 1 ;
F_19 ( F_470 ( & V_11 ,
V_484 ) ) ;
}
return 0 ;
}
