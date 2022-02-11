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
struct V_4 * F_30 ( struct V_28 * V_28 )
{
struct V_1 * V_2 ;
F_13 () ;
V_2 = V_28 -> V_1 ;
if ( ! V_2 || ! F_31 ( V_2 -> V_6 . V_29 ) )
V_2 = V_8 ;
F_17 () ;
return & V_2 -> V_6 ;
}
static struct V_22 *
F_32 ( struct V_1 * V_2 , struct V_28 * V_28 )
{
int V_24 = F_33 ( V_28 ) ;
int V_25 = F_34 ( V_28 ) ;
return & V_2 -> V_26 [ V_24 ] -> V_27 [ V_25 ] ;
}
static struct V_30 *
F_35 ( int V_24 , int V_25 )
{
return & V_31 . V_32 [ V_24 ] -> V_33 [ V_25 ] ;
}
static struct V_30 *
F_36 ( struct V_28 * V_28 )
{
int V_24 = F_33 ( V_28 ) ;
int V_25 = F_34 ( V_28 ) ;
return & V_31 . V_32 [ V_24 ] -> V_33 [ V_25 ] ;
}
static void F_37 ( struct V_22 * V_34 ,
struct V_30 * V_35 ,
unsigned long V_36 )
{
struct V_37 * * V_38 = & V_35 -> V_39 . V_37 ;
struct V_37 * V_40 = NULL ;
struct V_22 * V_41 ;
if ( V_34 -> V_42 )
return;
V_34 -> V_43 = V_36 ;
if ( ! V_34 -> V_43 )
return;
while ( * V_38 ) {
V_40 = * V_38 ;
V_41 = F_38 ( V_40 , struct V_22 ,
V_44 ) ;
if ( V_34 -> V_43 < V_41 -> V_43 )
V_38 = & ( * V_38 ) -> V_45 ;
else if ( V_34 -> V_43 >= V_41 -> V_43 )
V_38 = & ( * V_38 ) -> V_46 ;
}
F_39 ( & V_34 -> V_44 , V_40 , V_38 ) ;
F_40 ( & V_34 -> V_44 , & V_35 -> V_39 ) ;
V_34 -> V_42 = true ;
}
static void F_41 ( struct V_22 * V_34 ,
struct V_30 * V_35 )
{
if ( ! V_34 -> V_42 )
return;
F_42 ( & V_34 -> V_44 , & V_35 -> V_39 ) ;
V_34 -> V_42 = false ;
}
static void F_43 ( struct V_22 * V_34 ,
struct V_30 * V_35 )
{
unsigned long V_47 ;
F_44 ( & V_35 -> V_48 , V_47 ) ;
F_41 ( V_34 , V_35 ) ;
F_45 ( & V_35 -> V_48 , V_47 ) ;
}
static unsigned long F_46 ( struct V_1 * V_2 )
{
unsigned long V_49 = F_47 ( & V_2 -> V_50 ) ;
unsigned long V_51 = F_48 ( V_2 -> V_51 ) ;
unsigned long V_52 = 0 ;
if ( V_49 > V_51 )
V_52 = V_49 - V_51 ;
return V_52 ;
}
static void F_49 ( struct V_1 * V_2 , struct V_28 * V_28 )
{
unsigned long V_52 ;
struct V_22 * V_34 ;
struct V_30 * V_35 ;
V_35 = F_36 ( V_28 ) ;
for (; V_2 ; V_2 = F_50 ( V_2 ) ) {
V_34 = F_32 ( V_2 , V_28 ) ;
V_52 = F_46 ( V_2 ) ;
if ( V_52 || V_34 -> V_42 ) {
unsigned long V_47 ;
F_44 ( & V_35 -> V_48 , V_47 ) ;
if ( V_34 -> V_42 )
F_41 ( V_34 , V_35 ) ;
F_37 ( V_34 , V_35 , V_52 ) ;
F_45 ( & V_35 -> V_48 , V_47 ) ;
}
}
}
static void F_51 ( struct V_1 * V_2 )
{
struct V_30 * V_35 ;
struct V_22 * V_34 ;
int V_24 , V_25 ;
F_52 (nid) {
for ( V_25 = 0 ; V_25 < V_53 ; V_25 ++ ) {
V_34 = & V_2 -> V_26 [ V_24 ] -> V_27 [ V_25 ] ;
V_35 = F_35 ( V_24 , V_25 ) ;
F_43 ( V_34 , V_35 ) ;
}
}
}
static struct V_22 *
F_53 ( struct V_30 * V_35 )
{
struct V_37 * V_54 = NULL ;
struct V_22 * V_34 ;
V_55:
V_34 = NULL ;
V_54 = F_54 ( & V_35 -> V_39 ) ;
if ( ! V_54 )
goto V_56;
V_34 = F_38 ( V_54 , struct V_22 , V_44 ) ;
F_41 ( V_34 , V_35 ) ;
if ( ! F_46 ( V_34 -> V_2 ) ||
! F_16 ( & V_34 -> V_2 -> V_6 ) )
goto V_55;
V_56:
return V_34 ;
}
static struct V_22 *
F_55 ( struct V_30 * V_35 )
{
struct V_22 * V_34 ;
F_56 ( & V_35 -> V_48 ) ;
V_34 = F_53 ( V_35 ) ;
F_57 ( & V_35 -> V_48 ) ;
return V_34 ;
}
static long F_58 ( struct V_1 * V_2 ,
enum V_57 V_58 )
{
long V_59 = 0 ;
int V_60 ;
F_59 (cpu)
V_59 += F_60 ( V_2 -> V_61 -> V_62 [ V_58 ] , V_60 ) ;
return V_59 ;
}
static unsigned long F_61 ( struct V_1 * V_2 ,
enum V_63 V_58 )
{
unsigned long V_59 = 0 ;
int V_60 ;
F_59 (cpu)
V_59 += F_60 ( V_2 -> V_61 -> V_64 [ V_58 ] , V_60 ) ;
return V_59 ;
}
static void F_62 ( struct V_1 * V_2 ,
struct V_28 * V_28 ,
int V_49 )
{
if ( F_63 ( V_28 ) )
F_64 ( V_2 -> V_61 -> V_62 [ V_65 ] ,
V_49 ) ;
else
F_64 ( V_2 -> V_61 -> V_62 [ V_66 ] ,
V_49 ) ;
if ( F_65 ( V_28 ) )
F_64 ( V_2 -> V_61 -> V_62 [ V_67 ] ,
V_49 ) ;
if ( V_49 > 0 )
F_66 ( V_2 -> V_61 -> V_64 [ V_68 ] ) ;
else {
F_66 ( V_2 -> V_61 -> V_64 [ V_69 ] ) ;
V_49 = - V_49 ;
}
F_64 ( V_2 -> V_61 -> V_70 , V_49 ) ;
}
unsigned long F_67 ( struct V_71 * V_71 , enum V_72 V_73 )
{
struct V_22 * V_34 ;
V_34 = F_3 ( V_71 , struct V_22 , V_71 ) ;
return V_34 -> V_74 [ V_73 ] ;
}
static unsigned long F_68 ( struct V_1 * V_2 ,
int V_24 ,
unsigned int V_75 )
{
unsigned long V_76 = 0 ;
int V_25 ;
F_69 ( ( unsigned ) V_24 >= V_77 ) ;
for ( V_25 = 0 ; V_25 < V_53 ; V_25 ++ ) {
struct V_22 * V_34 ;
enum V_72 V_73 ;
F_70 (lru) {
if ( ! ( F_71 ( V_73 ) & V_75 ) )
continue;
V_34 = & V_2 -> V_26 [ V_24 ] -> V_27 [ V_25 ] ;
V_76 += V_34 -> V_74 [ V_73 ] ;
}
}
return V_76 ;
}
static unsigned long F_72 ( struct V_1 * V_2 ,
unsigned int V_75 )
{
unsigned long V_76 = 0 ;
int V_24 ;
F_73 (nid, N_MEMORY)
V_76 += F_68 ( V_2 , V_24 , V_75 ) ;
return V_76 ;
}
static bool F_74 ( struct V_1 * V_2 ,
enum V_78 V_79 )
{
unsigned long V_59 , V_80 ;
V_59 = F_75 ( V_2 -> V_61 -> V_70 ) ;
V_80 = F_75 ( V_2 -> V_61 -> V_81 [ V_79 ] ) ;
if ( ( long ) V_80 - ( long ) V_59 < 0 ) {
switch ( V_79 ) {
case V_82 :
V_80 = V_59 + V_83 ;
break;
case V_84 :
V_80 = V_59 + V_85 ;
break;
case V_86 :
V_80 = V_59 + V_87 ;
break;
default:
break;
}
F_76 ( V_2 -> V_61 -> V_81 [ V_79 ] , V_80 ) ;
return true ;
}
return false ;
}
static void F_77 ( struct V_1 * V_2 , struct V_28 * V_28 )
{
if ( F_78 ( F_74 ( V_2 ,
V_82 ) ) ) {
bool V_88 ;
bool T_1 V_89 ;
V_88 = F_74 ( V_2 ,
V_84 ) ;
#if V_90 > 1
T_1 = F_74 ( V_2 ,
V_86 ) ;
#endif
F_79 ( V_2 ) ;
if ( F_78 ( V_88 ) )
F_49 ( V_2 , V_28 ) ;
#if V_90 > 1
if ( F_78 ( T_1 ) )
F_80 ( & V_2 -> V_91 ) ;
#endif
}
}
struct V_1 * F_14 ( struct V_92 * V_38 )
{
if ( F_78 ( ! V_38 ) )
return NULL ;
return F_2 ( F_81 ( V_38 , V_93 ) ) ;
}
static struct V_1 * F_82 ( struct V_94 * V_95 )
{
struct V_1 * V_2 = NULL ;
F_13 () ;
do {
if ( F_78 ( ! V_95 ) )
V_2 = V_8 ;
else {
V_2 = F_14 ( F_83 ( V_95 -> V_96 ) ) ;
if ( F_78 ( ! V_2 ) )
V_2 = V_8 ;
}
} while ( ! F_16 ( & V_2 -> V_6 ) );
F_17 () ;
return V_2 ;
}
struct V_1 * F_84 ( struct V_1 * V_97 ,
struct V_1 * V_98 ,
struct V_99 * V_100 )
{
struct V_101 * V_102 ( V_103 ) ;
struct V_4 * V_6 = NULL ;
struct V_1 * V_2 = NULL ;
struct V_1 * V_104 = NULL ;
if ( F_85 () )
return NULL ;
if ( ! V_97 )
V_97 = V_8 ;
if ( V_98 && ! V_100 )
V_104 = V_98 ;
if ( ! V_97 -> V_105 && V_97 != V_8 ) {
if ( V_98 )
goto V_106;
return V_97 ;
}
F_13 () ;
if ( V_100 ) {
struct V_22 * V_34 ;
V_34 = F_26 ( V_97 , V_100 -> V_23 ) ;
V_103 = & V_34 -> V_103 [ V_100 -> V_107 ] ;
if ( V_98 && V_100 -> V_108 != V_103 -> V_108 )
goto V_109;
do {
V_104 = F_48 ( V_103 -> V_110 ) ;
} while ( V_104 && ! F_86 ( & V_104 -> V_6 ) );
}
if ( V_104 )
V_6 = & V_104 -> V_6 ;
for (; ; ) {
V_6 = F_87 ( V_6 , & V_97 -> V_6 ) ;
if ( ! V_6 ) {
if ( ! V_98 )
continue;
break;
}
V_2 = F_2 ( V_6 ) ;
if ( V_6 == & V_97 -> V_6 )
break;
if ( F_86 ( V_6 ) ) {
if ( F_88 ( & V_2 -> V_111 ) )
break;
F_20 ( V_6 ) ;
}
V_2 = NULL ;
}
if ( V_100 ) {
if ( F_89 ( & V_103 -> V_110 , V_104 , V_2 ) == V_104 ) {
if ( V_2 )
F_12 ( & V_2 -> V_6 ) ;
if ( V_104 )
F_20 ( & V_104 -> V_6 ) ;
}
if ( V_104 )
F_20 ( & V_104 -> V_6 ) ;
if ( ! V_2 )
V_103 -> V_108 ++ ;
else if ( ! V_98 )
V_100 -> V_108 = V_103 -> V_108 ;
}
V_109:
F_17 () ;
V_106:
if ( V_98 && V_98 != V_97 )
F_20 ( & V_98 -> V_6 ) ;
return V_2 ;
}
void F_90 ( struct V_1 * V_97 ,
struct V_1 * V_98 )
{
if ( ! V_97 )
V_97 = V_8 ;
if ( V_98 && V_98 != V_97 )
F_20 ( & V_98 -> V_6 ) ;
}
void F_91 ( struct V_94 * V_95 , enum V_112 V_58 )
{
struct V_1 * V_2 ;
F_13 () ;
V_2 = F_14 ( F_83 ( V_95 -> V_96 ) ) ;
if ( F_78 ( ! V_2 ) )
goto V_106;
switch ( V_58 ) {
case V_113 :
F_92 ( V_2 -> V_61 -> V_64 [ V_114 ] ) ;
break;
case V_115 :
F_92 ( V_2 -> V_61 -> V_64 [ V_116 ] ) ;
break;
default:
F_93 () ;
}
V_106:
F_17 () ;
}
struct V_71 * F_94 ( struct V_23 * V_23 ,
struct V_1 * V_2 )
{
struct V_22 * V_34 ;
struct V_71 * V_71 ;
if ( F_85 () ) {
V_71 = & V_23 -> V_71 ;
goto V_106;
}
V_34 = F_26 ( V_2 , V_23 ) ;
V_71 = & V_34 -> V_71 ;
V_106:
if ( F_78 ( V_71 -> V_23 != V_23 ) )
V_71 -> V_23 = V_23 ;
return V_71 ;
}
struct V_71 * F_95 ( struct V_28 * V_28 , struct V_23 * V_23 )
{
struct V_22 * V_34 ;
struct V_1 * V_2 ;
struct V_71 * V_71 ;
if ( F_85 () ) {
V_71 = & V_23 -> V_71 ;
goto V_106;
}
V_2 = V_28 -> V_1 ;
if ( ! V_2 )
V_2 = V_8 ;
V_34 = F_32 ( V_2 , V_28 ) ;
V_71 = & V_34 -> V_71 ;
V_106:
if ( F_78 ( V_71 -> V_23 != V_23 ) )
V_71 -> V_23 = V_23 ;
return V_71 ;
}
void F_96 ( struct V_71 * V_71 , enum V_72 V_73 ,
int V_49 )
{
struct V_22 * V_34 ;
unsigned long * V_74 ;
if ( F_85 () )
return;
V_34 = F_3 ( V_71 , struct V_22 , V_71 ) ;
V_74 = V_34 -> V_74 + V_73 ;
* V_74 += V_49 ;
F_69 ( ( long ) ( * V_74 ) < 0 ) ;
}
bool F_97 ( struct V_1 * V_2 , struct V_1 * V_97 )
{
if ( V_97 == V_2 )
return true ;
if ( ! V_97 -> V_105 )
return false ;
return F_98 ( V_2 -> V_6 . V_29 , V_97 -> V_6 . V_29 ) ;
}
bool F_99 ( struct V_92 * V_117 , struct V_1 * V_2 )
{
struct V_1 * V_118 ;
struct V_92 * V_38 ;
bool V_119 ;
V_38 = F_100 ( V_117 ) ;
if ( V_38 ) {
V_118 = F_82 ( V_38 -> V_95 ) ;
F_101 ( V_38 ) ;
} else {
F_13 () ;
V_118 = F_14 ( V_117 ) ;
F_12 ( & V_118 -> V_6 ) ;
F_17 () ;
}
V_119 = F_97 ( V_118 , V_2 ) ;
F_20 ( & V_118 -> V_6 ) ;
return V_119 ;
}
int F_102 ( struct V_71 * V_71 )
{
unsigned long V_120 ;
unsigned long V_121 ;
unsigned long V_122 ;
unsigned long V_123 ;
V_121 = F_67 ( V_71 , V_124 ) ;
V_122 = F_67 ( V_71 , V_125 ) ;
V_123 = ( V_121 + V_122 ) >> ( 30 - V_126 ) ;
if ( V_123 )
V_120 = F_103 ( 10 * V_123 ) ;
else
V_120 = 1 ;
return V_121 * V_120 < V_122 ;
}
bool F_104 ( struct V_71 * V_71 )
{
struct V_22 * V_34 ;
struct V_1 * V_2 ;
if ( F_85 () )
return true ;
V_34 = F_3 ( V_71 , struct V_22 , V_71 ) ;
V_2 = V_34 -> V_2 ;
return ! ! ( V_2 -> V_6 . V_47 & V_127 ) ;
}
static unsigned long F_105 ( struct V_1 * V_2 )
{
unsigned long V_128 = 0 ;
unsigned long V_62 ;
unsigned long V_129 ;
V_62 = F_47 ( & V_2 -> V_50 ) ;
V_129 = F_48 ( V_2 -> V_50 . V_129 ) ;
if ( V_62 < V_129 )
V_128 = V_129 - V_62 ;
if ( V_130 ) {
V_62 = F_47 ( & V_2 -> V_131 ) ;
V_129 = F_48 ( V_2 -> V_131 . V_129 ) ;
if ( V_62 <= V_129 )
V_128 = F_106 ( V_128 , V_129 - V_62 ) ;
}
return V_128 ;
}
int F_107 ( struct V_1 * V_2 )
{
if ( F_85 () || ! V_2 -> V_6 . V_40 )
return V_132 ;
return V_2 -> V_133 ;
}
static bool F_108 ( struct V_1 * V_2 )
{
struct V_1 * V_134 ;
struct V_1 * V_135 ;
bool V_119 = false ;
F_109 ( & V_136 . V_48 ) ;
V_134 = V_136 . V_134 ;
V_135 = V_136 . V_135 ;
if ( ! V_134 )
goto V_137;
V_119 = F_97 ( V_134 , V_2 ) ||
F_97 ( V_135 , V_2 ) ;
V_137:
F_110 ( & V_136 . V_48 ) ;
return V_119 ;
}
static bool F_111 ( struct V_1 * V_2 )
{
if ( V_136 . V_138 && V_19 != V_136 . V_138 ) {
if ( F_108 ( V_2 ) ) {
F_112 ( V_139 ) ;
F_113 ( & V_136 . V_140 , & V_139 , V_141 ) ;
if ( V_136 . V_138 )
F_114 () ;
F_115 ( & V_136 . V_140 , & V_139 ) ;
return true ;
}
}
return false ;
}
void F_116 ( struct V_1 * V_2 , struct V_92 * V_38 )
{
static F_117 ( V_142 ) ;
struct V_1 * V_103 ;
unsigned int V_143 ;
F_118 ( & V_142 ) ;
F_13 () ;
if ( V_38 ) {
F_119 ( L_1 ) ;
F_120 ( F_121 ( V_38 , V_93 ) ) ;
F_122 ( L_2 ) ;
} else {
F_119 ( L_3 ) ;
}
F_120 ( V_2 -> V_6 . V_29 ) ;
F_122 ( L_4 ) ;
F_17 () ;
F_119 ( L_5 ,
F_123 ( ( V_144 ) F_47 ( & V_2 -> V_50 ) ) ,
F_123 ( ( V_144 ) V_2 -> V_50 . V_129 ) , V_2 -> V_50 . V_145 ) ;
F_119 ( L_6 ,
F_123 ( ( V_144 ) F_47 ( & V_2 -> V_131 ) ) ,
F_123 ( ( V_144 ) V_2 -> V_131 . V_129 ) , V_2 -> V_131 . V_145 ) ;
F_119 ( L_7 ,
F_123 ( ( V_144 ) F_47 ( & V_2 -> V_146 ) ) ,
F_123 ( ( V_144 ) V_2 -> V_146 . V_129 ) , V_2 -> V_146 . V_145 ) ;
F_124 (iter, memcg) {
F_119 ( L_8 ) ;
F_120 ( V_103 -> V_6 . V_29 ) ;
F_122 ( L_9 ) ;
for ( V_143 = 0 ; V_143 < V_147 ; V_143 ++ ) {
if ( V_143 == V_148 && ! V_130 )
continue;
F_122 ( L_10 , V_149 [ V_143 ] ,
F_123 ( F_58 ( V_103 , V_143 ) ) ) ;
}
for ( V_143 = 0 ; V_143 < V_150 ; V_143 ++ )
F_122 ( L_11 , V_151 [ V_143 ] ,
F_123 ( F_72 ( V_103 , F_71 ( V_143 ) ) ) ) ;
F_122 ( L_4 ) ;
}
F_125 ( & V_142 ) ;
}
static int F_126 ( struct V_1 * V_2 )
{
int V_152 = 0 ;
struct V_1 * V_103 ;
F_124 (iter, memcg)
V_152 ++ ;
return V_152 ;
}
static unsigned long F_127 ( struct V_1 * V_2 )
{
unsigned long V_129 ;
V_129 = V_2 -> V_50 . V_129 ;
if ( F_107 ( V_2 ) ) {
unsigned long V_153 ;
V_153 = V_2 -> V_131 . V_129 ;
V_129 = F_106 ( V_129 + V_154 , V_153 ) ;
}
return V_129 ;
}
static void F_128 ( struct V_1 * V_2 , T_2 V_155 ,
int V_156 )
{
struct V_1 * V_103 ;
unsigned long V_157 = 0 ;
unsigned long V_158 ;
unsigned int V_159 = 0 ;
struct V_92 * V_160 = NULL ;
F_118 ( & V_161 ) ;
if ( F_129 ( V_19 ) || F_130 ( V_19 ) ) {
F_131 ( V_19 ) ;
goto V_137;
}
F_132 ( V_162 , V_155 , V_156 , NULL , V_2 ) ;
V_158 = F_127 ( V_2 ) ? : 1 ;
F_124 (iter, memcg) {
struct V_163 V_164 ;
struct V_92 * V_117 ;
F_133 ( & V_103 -> V_6 , & V_164 ) ;
while ( ( V_117 = F_134 ( & V_164 ) ) ) {
switch ( F_135 ( V_117 , V_158 , NULL ,
false ) ) {
case V_165 :
if ( V_160 )
F_136 ( V_160 ) ;
V_160 = V_117 ;
V_157 = V_166 ;
F_137 ( V_160 ) ;
case V_167 :
continue;
case V_168 :
F_138 ( & V_164 ) ;
F_90 ( V_2 , V_103 ) ;
if ( V_160 )
F_136 ( V_160 ) ;
goto V_137;
case V_169 :
break;
} ;
V_159 = F_139 ( V_117 , V_2 , NULL , V_158 ) ;
if ( ! V_159 || V_159 < V_157 )
continue;
if ( V_159 == V_157 &&
F_140 ( V_160 ) )
continue;
if ( V_160 )
F_136 ( V_160 ) ;
V_160 = V_117 ;
V_157 = V_159 ;
F_137 ( V_160 ) ;
}
F_138 ( & V_164 ) ;
}
if ( V_160 ) {
V_159 = V_157 * 1000 / V_158 ;
F_141 ( V_160 , V_155 , V_156 , V_159 , V_158 ,
V_2 , NULL , L_12 ) ;
}
V_137:
F_125 ( & V_161 ) ;
}
static bool F_142 ( struct V_1 * V_2 ,
int V_24 , bool V_170 )
{
if ( F_68 ( V_2 , V_24 , V_171 ) )
return true ;
if ( V_170 || ! V_154 )
return false ;
if ( F_68 ( V_2 , V_24 , V_172 ) )
return true ;
return false ;
}
static void F_143 ( struct V_1 * V_2 )
{
int V_24 ;
if ( ! F_144 ( & V_2 -> V_91 ) )
return;
if ( F_145 ( & V_2 -> V_173 ) > 1 )
return;
V_2 -> V_174 = V_175 [ V_176 ] ;
F_146 (nid, node_states[N_MEMORY]) {
if ( ! F_142 ( V_2 , V_24 , false ) )
F_147 ( V_24 , V_2 -> V_174 ) ;
}
F_148 ( & V_2 -> V_91 , 0 ) ;
F_148 ( & V_2 -> V_173 , 0 ) ;
}
int F_149 ( struct V_1 * V_2 )
{
int V_177 ;
F_143 ( V_2 ) ;
V_177 = V_2 -> V_178 ;
V_177 = F_150 ( V_177 , V_2 -> V_174 ) ;
if ( V_177 == V_90 )
V_177 = F_151 ( V_2 -> V_174 ) ;
if ( F_78 ( V_177 == V_90 ) )
V_177 = F_152 () ;
V_2 -> V_178 = V_177 ;
return V_177 ;
}
int F_149 ( struct V_1 * V_2 )
{
return 0 ;
}
static int F_153 ( struct V_1 * V_179 ,
struct V_23 * V_23 ,
T_2 V_155 ,
unsigned long * V_180 )
{
struct V_1 * V_181 = NULL ;
int V_182 = 0 ;
int V_183 = 0 ;
unsigned long V_52 ;
unsigned long V_184 ;
struct V_99 V_100 = {
. V_23 = V_23 ,
. V_107 = 0 ,
} ;
V_52 = F_46 ( V_179 ) ;
while ( 1 ) {
V_181 = F_84 ( V_179 , V_181 , & V_100 ) ;
if ( ! V_181 ) {
V_183 ++ ;
if ( V_183 >= 2 ) {
if ( ! V_182 )
break;
if ( V_182 >= ( V_52 >> 2 ) ||
( V_183 > V_185 ) )
break;
}
continue;
}
V_182 += F_154 ( V_181 , V_155 , false ,
V_23 , & V_184 ) ;
* V_180 += V_184 ;
if ( ! F_46 ( V_179 ) )
break;
}
F_90 ( V_179 , V_181 ) ;
return V_182 ;
}
static bool F_155 ( struct V_1 * V_2 )
{
struct V_1 * V_103 , * V_186 = NULL ;
F_109 ( & V_187 ) ;
F_124 (iter, memcg) {
if ( V_103 -> V_161 ) {
V_186 = V_103 ;
F_90 ( V_2 , V_103 ) ;
break;
} else
V_103 -> V_161 = true ;
}
if ( V_186 ) {
F_124 (iter, memcg) {
if ( V_103 == V_186 ) {
F_90 ( V_2 , V_103 ) ;
break;
}
V_103 -> V_161 = false ;
}
} else
F_156 ( & V_188 , 0 , 1 , V_189 ) ;
F_110 ( & V_187 ) ;
return ! V_186 ;
}
static void F_157 ( struct V_1 * V_2 )
{
struct V_1 * V_103 ;
F_109 ( & V_187 ) ;
F_158 ( & V_188 , 1 , V_189 ) ;
F_124 (iter, memcg)
V_103 -> V_161 = false ;
F_110 ( & V_187 ) ;
}
static void F_159 ( struct V_1 * V_2 )
{
struct V_1 * V_103 ;
F_109 ( & V_187 ) ;
F_124 (iter, memcg)
V_103 -> V_190 ++ ;
F_110 ( & V_187 ) ;
}
static void F_160 ( struct V_1 * V_2 )
{
struct V_1 * V_103 ;
F_109 ( & V_187 ) ;
F_124 (iter, memcg)
if ( V_103 -> V_190 > 0 )
V_103 -> V_190 -- ;
F_110 ( & V_187 ) ;
}
static int F_161 ( T_3 * V_139 ,
unsigned V_191 , int V_192 , void * V_193 )
{
struct V_1 * V_194 = (struct V_1 * ) V_193 ;
struct V_1 * V_195 ;
struct V_196 * V_196 ;
V_196 = F_3 ( V_139 , struct V_196 , V_139 ) ;
V_195 = V_196 -> V_2 ;
if ( ! F_97 ( V_194 , V_195 ) &&
! F_97 ( V_195 , V_194 ) )
return 0 ;
return F_162 ( V_139 , V_191 , V_192 , V_193 ) ;
}
static void F_163 ( struct V_1 * V_2 )
{
if ( V_2 && V_2 -> V_190 )
F_164 ( & V_197 , V_198 , 0 , V_2 ) ;
}
static void F_165 ( struct V_1 * V_2 , T_2 V_199 , int V_156 )
{
if ( ! V_19 -> V_200 . V_201 )
return;
F_12 ( & V_2 -> V_6 ) ;
V_19 -> V_200 . V_2 = V_2 ;
V_19 -> V_200 . V_155 = V_199 ;
V_19 -> V_200 . V_156 = V_156 ;
}
bool F_166 ( bool V_202 )
{
struct V_1 * V_2 = V_19 -> V_200 . V_2 ;
struct V_196 V_203 ;
bool V_204 ;
if ( ! V_2 )
return false ;
if ( ! V_202 || V_205 )
goto V_206;
V_203 . V_2 = V_2 ;
V_203 . V_139 . V_47 = 0 ;
V_203 . V_139 . V_207 = F_161 ;
V_203 . V_139 . V_208 = V_19 ;
F_167 ( & V_203 . V_139 . V_209 ) ;
F_113 ( & V_197 , & V_203 . V_139 , V_210 ) ;
F_159 ( V_2 ) ;
V_204 = F_155 ( V_2 ) ;
if ( V_204 )
F_168 ( V_2 ) ;
if ( V_204 && ! V_2 -> V_211 ) {
F_160 ( V_2 ) ;
F_115 ( & V_197 , & V_203 . V_139 ) ;
F_128 ( V_2 , V_19 -> V_200 . V_155 ,
V_19 -> V_200 . V_156 ) ;
} else {
F_114 () ;
F_160 ( V_2 ) ;
F_115 ( & V_197 , & V_203 . V_139 ) ;
}
if ( V_204 ) {
F_157 ( V_2 ) ;
F_163 ( V_2 ) ;
}
V_206:
V_19 -> V_200 . V_2 = NULL ;
F_20 ( & V_2 -> V_6 ) ;
return true ;
}
struct V_1 * F_169 ( struct V_28 * V_28 )
{
struct V_1 * V_2 ;
unsigned long V_47 ;
F_13 () ;
if ( F_85 () )
return NULL ;
V_212:
V_2 = V_28 -> V_1 ;
if ( F_78 ( ! V_2 ) )
return NULL ;
if ( F_144 ( & V_2 -> V_213 ) <= 0 )
return V_2 ;
F_44 ( & V_2 -> V_214 , V_47 ) ;
if ( V_2 != V_28 -> V_1 ) {
F_45 ( & V_2 -> V_214 , V_47 ) ;
goto V_212;
}
V_2 -> V_215 = V_19 ;
V_2 -> V_216 = V_47 ;
return V_2 ;
}
void F_170 ( struct V_1 * V_2 )
{
if ( V_2 && V_2 -> V_215 == V_19 ) {
unsigned long V_47 = V_2 -> V_216 ;
V_2 -> V_215 = NULL ;
V_2 -> V_216 = 0 ;
F_45 ( & V_2 -> V_214 , V_47 ) ;
}
F_17 () ;
}
void F_171 ( struct V_1 * V_2 ,
enum V_57 V_58 , int V_59 )
{
F_69 ( ! F_172 () ) ;
if ( V_2 )
F_173 ( V_2 -> V_61 -> V_62 [ V_58 ] , V_59 ) ;
}
static bool F_174 ( struct V_1 * V_2 , unsigned int V_49 )
{
struct V_217 * V_218 ;
bool V_119 = false ;
if ( V_49 > V_219 )
return V_119 ;
V_218 = & F_175 ( V_220 ) ;
if ( V_2 == V_218 -> V_221 && V_218 -> V_49 >= V_49 ) {
V_218 -> V_49 -= V_49 ;
V_119 = true ;
}
F_176 ( V_220 ) ;
return V_119 ;
}
static void F_177 ( struct V_217 * V_218 )
{
struct V_1 * V_222 = V_218 -> V_221 ;
if ( V_218 -> V_49 ) {
F_178 ( & V_222 -> V_50 , V_218 -> V_49 ) ;
if ( V_130 )
F_178 ( & V_222 -> V_131 , V_218 -> V_49 ) ;
F_179 ( & V_222 -> V_6 , V_218 -> V_49 ) ;
V_218 -> V_49 = 0 ;
}
V_218 -> V_221 = NULL ;
}
static void F_180 ( struct V_223 * V_224 )
{
struct V_217 * V_218 = F_181 ( & V_220 ) ;
F_177 ( V_218 ) ;
F_182 ( V_225 , & V_218 -> V_47 ) ;
}
static void F_183 ( struct V_1 * V_2 , unsigned int V_49 )
{
struct V_217 * V_218 = & F_175 ( V_220 ) ;
if ( V_218 -> V_221 != V_2 ) {
F_177 ( V_218 ) ;
V_218 -> V_221 = V_2 ;
}
V_218 -> V_49 += V_49 ;
F_176 ( V_220 ) ;
}
static void F_184 ( struct V_1 * V_179 )
{
int V_60 , V_226 ;
if ( ! F_185 ( & V_227 ) )
return;
F_186 () ;
V_226 = F_187 () ;
F_188 (cpu) {
struct V_217 * V_218 = & F_60 ( V_220 , V_60 ) ;
struct V_1 * V_2 ;
V_2 = V_218 -> V_221 ;
if ( ! V_2 || ! V_218 -> V_49 )
continue;
if ( ! F_97 ( V_2 , V_179 ) )
continue;
if ( ! F_189 ( V_225 , & V_218 -> V_47 ) ) {
if ( V_60 == V_226 )
F_180 ( & V_218 -> V_228 ) ;
else
F_190 ( V_60 , & V_218 -> V_228 ) ;
}
}
F_191 () ;
F_192 () ;
F_125 ( & V_227 ) ;
}
static int F_193 ( struct V_229 * V_230 ,
unsigned long V_231 ,
void * V_232 )
{
int V_60 = ( unsigned long ) V_232 ;
struct V_217 * V_218 ;
if ( V_231 == V_233 )
return V_234 ;
if ( V_231 != V_235 && V_231 != V_236 )
return V_234 ;
V_218 = & F_60 ( V_220 , V_60 ) ;
F_177 ( V_218 ) ;
return V_234 ;
}
static int F_194 ( struct V_1 * V_2 , T_2 V_155 ,
unsigned int V_49 )
{
unsigned int V_237 = F_195 ( V_219 , V_49 ) ;
int V_238 = V_239 ;
struct V_1 * V_240 ;
struct V_241 * V_242 ;
unsigned long V_243 ;
bool V_244 = true ;
bool V_245 = false ;
int V_119 = 0 ;
if ( F_6 ( V_2 ) )
goto V_56;
V_55:
if ( F_174 ( V_2 , V_49 ) )
goto V_56;
if ( ! V_130 ||
! F_196 ( & V_2 -> V_131 , V_237 , & V_242 ) ) {
if ( ! F_196 ( & V_2 -> V_50 , V_237 , & V_242 ) )
goto V_246;
if ( V_130 )
F_178 ( & V_2 -> V_131 , V_237 ) ;
V_240 = F_197 ( V_242 , V_50 ) ;
} else {
V_240 = F_197 ( V_242 , V_131 ) ;
V_244 = false ;
}
if ( V_237 > V_49 ) {
V_237 = V_49 ;
goto V_55;
}
if ( F_78 ( F_198 ( V_247 ) ||
F_129 ( V_19 ) ||
V_19 -> V_47 & V_248 ) )
goto V_249;
if ( F_78 ( F_199 ( V_19 ) ) )
goto V_250;
if ( ! ( V_155 & V_251 ) )
goto V_250;
F_200 ( V_240 , V_252 , 1 ) ;
V_243 = F_201 ( V_240 , V_49 ,
V_155 , V_244 ) ;
if ( F_105 ( V_240 ) >= V_49 )
goto V_55;
if ( ! V_245 ) {
F_184 ( V_240 ) ;
V_245 = true ;
goto V_55;
}
if ( V_155 & V_253 )
goto V_250;
if ( V_243 && V_49 <= ( 1 << V_254 ) )
goto V_55;
if ( F_111 ( V_240 ) )
goto V_55;
if ( V_238 -- )
goto V_55;
if ( V_155 & V_255 )
goto V_249;
if ( F_129 ( V_19 ) )
goto V_249;
F_200 ( V_240 , V_256 , 1 ) ;
F_165 ( V_240 , V_155 , F_202 ( V_49 ) ) ;
V_250:
if ( ! ( V_155 & V_255 ) )
return - V_257 ;
V_249:
return - V_258 ;
V_246:
F_203 ( & V_2 -> V_6 , V_237 ) ;
if ( V_237 > V_49 )
F_183 ( V_2 , V_237 - V_49 ) ;
if ( ! ( V_155 & V_251 ) )
goto V_56;
do {
if ( F_47 ( & V_2 -> V_50 ) <= V_2 -> V_259 )
continue;
F_200 ( V_2 , V_260 , 1 ) ;
F_201 ( V_2 , V_49 , V_155 , true ) ;
} while ( ( V_2 = F_50 ( V_2 ) ) );
V_56:
return V_119 ;
}
static void F_204 ( struct V_1 * V_2 , unsigned int V_49 )
{
if ( F_6 ( V_2 ) )
return;
F_178 ( & V_2 -> V_50 , V_49 ) ;
if ( V_130 )
F_178 ( & V_2 -> V_131 , V_49 ) ;
F_179 ( & V_2 -> V_6 , V_49 ) ;
}
struct V_1 * F_205 ( struct V_28 * V_28 )
{
struct V_1 * V_2 ;
unsigned short V_10 ;
T_4 V_261 ;
F_206 ( ! F_207 ( V_28 ) , V_28 ) ;
V_2 = V_28 -> V_1 ;
if ( V_2 ) {
if ( ! F_16 ( & V_2 -> V_6 ) )
V_2 = NULL ;
} else if ( F_208 ( V_28 ) ) {
V_261 . V_59 = F_209 ( V_28 ) ;
V_10 = F_210 ( V_261 ) ;
F_13 () ;
V_2 = F_8 ( V_10 ) ;
if ( V_2 && ! F_16 ( & V_2 -> V_6 ) )
V_2 = NULL ;
F_17 () ;
}
return V_2 ;
}
static void F_211 ( struct V_28 * V_28 , int * V_262 )
{
struct V_23 * V_23 = F_212 ( V_28 ) ;
F_56 ( & V_23 -> V_263 ) ;
if ( F_213 ( V_28 ) ) {
struct V_71 * V_71 ;
V_71 = F_95 ( V_28 , V_23 ) ;
F_214 ( V_28 ) ;
F_215 ( V_28 , V_71 , F_216 ( V_28 ) ) ;
* V_262 = 1 ;
} else
* V_262 = 0 ;
}
static void F_217 ( struct V_28 * V_28 , int V_262 )
{
struct V_23 * V_23 = F_212 ( V_28 ) ;
if ( V_262 ) {
struct V_71 * V_71 ;
V_71 = F_95 ( V_28 , V_23 ) ;
F_206 ( F_213 ( V_28 ) , V_28 ) ;
F_218 ( V_28 ) ;
F_219 ( V_28 , V_71 , F_216 ( V_28 ) ) ;
}
F_57 ( & V_23 -> V_263 ) ;
}
static void F_220 ( struct V_28 * V_28 , struct V_1 * V_2 ,
bool V_264 )
{
int V_262 ;
F_206 ( V_28 -> V_1 , V_28 ) ;
if ( V_264 )
F_211 ( V_28 , & V_262 ) ;
V_28 -> V_1 = V_2 ;
if ( V_264 )
F_217 ( V_28 , V_262 ) ;
}
int F_221 ( struct V_1 * V_2 , T_2 V_265 ,
unsigned long V_49 )
{
struct V_241 * V_242 ;
int V_119 = 0 ;
V_119 = F_196 ( & V_2 -> V_146 , V_49 , & V_242 ) ;
if ( V_119 < 0 )
return V_119 ;
V_119 = F_194 ( V_2 , V_265 , V_49 ) ;
if ( V_119 == - V_258 ) {
F_222 ( & V_2 -> V_50 , V_49 ) ;
if ( V_130 )
F_222 ( & V_2 -> V_131 , V_49 ) ;
F_203 ( & V_2 -> V_6 , V_49 ) ;
V_119 = 0 ;
} else if ( V_119 )
F_178 ( & V_2 -> V_146 , V_49 ) ;
return V_119 ;
}
void F_223 ( struct V_1 * V_2 , unsigned long V_49 )
{
F_178 ( & V_2 -> V_50 , V_49 ) ;
if ( V_130 )
F_178 ( & V_2 -> V_131 , V_49 ) ;
F_178 ( & V_2 -> V_146 , V_49 ) ;
F_179 ( & V_2 -> V_6 , V_49 ) ;
}
int F_224 ( struct V_1 * V_2 )
{
return V_2 ? V_2 -> V_266 : - 1 ;
}
static int F_225 ( void )
{
int V_10 , V_267 ;
int V_268 ;
V_10 = F_226 ( & V_269 ,
0 , V_270 , V_271 ) ;
if ( V_10 < 0 )
return V_10 ;
if ( V_10 < V_272 )
return V_10 ;
F_227 ( & V_21 ) ;
V_267 = 2 * ( V_10 + 1 ) ;
if ( V_267 < V_273 )
V_267 = V_273 ;
else if ( V_267 > V_270 )
V_267 = V_270 ;
V_268 = F_228 ( V_267 ) ;
if ( ! V_268 )
V_268 = F_229 ( V_267 ) ;
if ( ! V_268 )
V_272 = V_267 ;
F_230 ( & V_21 ) ;
if ( V_268 ) {
F_231 ( & V_269 , V_10 ) ;
return V_268 ;
}
return V_10 ;
}
static void F_232 ( int V_10 )
{
F_231 ( & V_269 , V_10 ) ;
}
static void F_233 ( struct V_223 * V_274 )
{
struct V_275 * V_276 =
F_3 ( V_274 , struct V_275 , V_228 ) ;
struct V_1 * V_2 = V_276 -> V_2 ;
struct V_277 * V_278 = V_276 -> V_278 ;
F_234 ( V_2 , V_278 ) ;
F_20 ( & V_2 -> V_6 ) ;
F_235 ( V_276 ) ;
}
static void F_236 ( struct V_1 * V_2 ,
struct V_277 * V_278 )
{
struct V_275 * V_276 ;
V_276 = F_237 ( sizeof( * V_276 ) , V_279 ) ;
if ( ! V_276 )
return;
F_12 ( & V_2 -> V_6 ) ;
V_276 -> V_2 = V_2 ;
V_276 -> V_278 = V_278 ;
F_238 ( & V_276 -> V_228 , F_233 ) ;
F_239 ( & V_276 -> V_228 ) ;
}
static void F_240 ( struct V_1 * V_2 ,
struct V_277 * V_278 )
{
V_19 -> V_280 = 1 ;
F_236 ( V_2 , V_278 ) ;
V_19 -> V_280 = 0 ;
}
struct V_277 * F_241 ( struct V_277 * V_278 )
{
struct V_1 * V_2 ;
struct V_277 * V_281 ;
int V_266 ;
F_69 ( ! F_242 ( V_278 ) ) ;
if ( V_19 -> V_280 )
return V_278 ;
V_2 = F_82 ( V_19 -> V_95 ) ;
V_266 = F_48 ( V_2 -> V_266 ) ;
if ( V_266 < 0 )
goto V_106;
V_281 = F_243 ( V_278 , V_266 ) ;
if ( F_244 ( V_281 ) )
return V_281 ;
F_240 ( V_2 , V_278 ) ;
V_106:
F_20 ( & V_2 -> V_6 ) ;
return V_278 ;
}
void F_245 ( struct V_277 * V_278 )
{
if ( ! F_242 ( V_278 ) )
F_20 ( & V_278 -> V_282 . V_2 -> V_6 ) ;
}
bool
F_246 ( T_2 V_265 , struct V_1 * * V_283 , int V_156 )
{
struct V_1 * V_2 ;
int V_119 ;
* V_283 = NULL ;
V_2 = F_82 ( V_19 -> V_95 ) ;
if ( ! F_1 ( V_2 ) ) {
F_20 ( & V_2 -> V_6 ) ;
return true ;
}
V_119 = F_221 ( V_2 , V_265 , 1 << V_156 ) ;
if ( ! V_119 )
* V_283 = V_2 ;
F_20 ( & V_2 -> V_6 ) ;
return ( V_119 == 0 ) ;
}
void F_247 ( struct V_28 * V_28 , struct V_1 * V_2 ,
int V_156 )
{
F_69 ( F_6 ( V_2 ) ) ;
if ( ! V_28 ) {
F_223 ( V_2 , 1 << V_156 ) ;
return;
}
V_28 -> V_1 = V_2 ;
}
void F_248 ( struct V_28 * V_28 , int V_156 )
{
struct V_1 * V_2 = V_28 -> V_1 ;
if ( ! V_2 )
return;
F_206 ( F_6 ( V_2 ) , V_28 ) ;
F_223 ( V_2 , 1 << V_156 ) ;
V_28 -> V_1 = NULL ;
}
struct V_1 * F_249 ( void * V_284 )
{
struct V_1 * V_2 = NULL ;
struct V_277 * V_278 ;
struct V_28 * V_28 ;
V_28 = F_250 ( V_284 ) ;
if ( F_251 ( V_28 ) ) {
V_278 = V_28 -> V_285 ;
if ( ! F_242 ( V_278 ) )
V_2 = V_278 -> V_282 . V_2 ;
} else
V_2 = V_28 -> V_1 ;
return V_2 ;
}
void F_252 ( struct V_28 * V_286 )
{
int V_143 ;
if ( F_85 () )
return;
for ( V_143 = 1 ; V_143 < V_287 ; V_143 ++ )
V_286 [ V_143 ] . V_1 = V_286 -> V_1 ;
F_253 ( V_286 -> V_1 -> V_61 -> V_62 [ V_67 ] ,
V_287 ) ;
}
static void F_254 ( struct V_1 * V_2 ,
bool V_288 )
{
int V_59 = ( V_288 ) ? 1 : - 1 ;
F_173 ( V_2 -> V_61 -> V_62 [ V_148 ] , V_59 ) ;
}
static int F_255 ( T_4 V_289 ,
struct V_1 * V_134 , struct V_1 * V_135 )
{
unsigned short V_290 , V_291 ;
V_290 = F_7 ( V_134 ) ;
V_291 = F_7 ( V_135 ) ;
if ( F_256 ( V_289 , V_290 , V_291 ) == V_290 ) {
F_254 ( V_134 , false ) ;
F_254 ( V_135 , true ) ;
return 0 ;
}
return - V_292 ;
}
static inline int F_255 ( T_4 V_289 ,
struct V_1 * V_134 , struct V_1 * V_135 )
{
return - V_292 ;
}
static int F_257 ( struct V_1 * V_2 ,
unsigned long V_129 )
{
unsigned long V_293 ;
unsigned long V_294 ;
bool V_295 = false ;
int V_296 ;
int V_119 ;
V_296 = V_239 *
F_126 ( V_2 ) ;
V_294 = F_47 ( & V_2 -> V_50 ) ;
do {
if ( F_258 ( V_19 ) ) {
V_119 = - V_258 ;
break;
}
F_118 ( & V_297 ) ;
if ( V_129 > V_2 -> V_131 . V_129 ) {
F_125 ( & V_297 ) ;
V_119 = - V_292 ;
break;
}
if ( V_129 > V_2 -> V_50 . V_129 )
V_295 = true ;
V_119 = F_259 ( & V_2 -> V_50 , V_129 ) ;
F_125 ( & V_297 ) ;
if ( ! V_119 )
break;
F_201 ( V_2 , 1 , V_271 , true ) ;
V_293 = F_47 ( & V_2 -> V_50 ) ;
if ( V_293 >= V_294 )
V_296 -- ;
else
V_294 = V_293 ;
} while ( V_296 );
if ( ! V_119 && V_295 )
F_163 ( V_2 ) ;
return V_119 ;
}
static int F_260 ( struct V_1 * V_2 ,
unsigned long V_129 )
{
unsigned long V_293 ;
unsigned long V_294 ;
bool V_295 = false ;
int V_296 ;
int V_119 ;
V_296 = V_239 *
F_126 ( V_2 ) ;
V_294 = F_47 ( & V_2 -> V_131 ) ;
do {
if ( F_258 ( V_19 ) ) {
V_119 = - V_258 ;
break;
}
F_118 ( & V_297 ) ;
if ( V_129 < V_2 -> V_50 . V_129 ) {
F_125 ( & V_297 ) ;
V_119 = - V_292 ;
break;
}
if ( V_129 > V_2 -> V_131 . V_129 )
V_295 = true ;
V_119 = F_259 ( & V_2 -> V_131 , V_129 ) ;
F_125 ( & V_297 ) ;
if ( ! V_119 )
break;
F_201 ( V_2 , 1 , V_271 , false ) ;
V_293 = F_47 ( & V_2 -> V_131 ) ;
if ( V_293 >= V_294 )
V_296 -- ;
else
V_294 = V_293 ;
} while ( V_296 );
if ( ! V_119 && V_295 )
F_163 ( V_2 ) ;
return V_119 ;
}
unsigned long F_261 ( struct V_23 * V_23 , int V_156 ,
T_2 V_155 ,
unsigned long * V_180 )
{
unsigned long V_243 = 0 ;
struct V_22 * V_34 , * V_298 = NULL ;
unsigned long V_299 ;
int V_183 = 0 ;
struct V_30 * V_35 ;
unsigned long V_52 ;
unsigned long V_184 ;
if ( V_156 > 0 )
return 0 ;
V_35 = F_35 ( F_27 ( V_23 ) , F_28 ( V_23 ) ) ;
do {
if ( V_298 )
V_34 = V_298 ;
else
V_34 = F_55 ( V_35 ) ;
if ( ! V_34 )
break;
V_184 = 0 ;
V_299 = F_153 ( V_34 -> V_2 , V_23 ,
V_155 , & V_184 ) ;
V_243 += V_299 ;
* V_180 += V_184 ;
F_56 ( & V_35 -> V_48 ) ;
F_41 ( V_34 , V_35 ) ;
V_298 = NULL ;
if ( ! V_299 )
V_298 = F_53 ( V_35 ) ;
V_52 = F_46 ( V_34 -> V_2 ) ;
F_37 ( V_34 , V_35 , V_52 ) ;
F_57 ( & V_35 -> V_48 ) ;
F_20 ( & V_34 -> V_2 -> V_6 ) ;
V_183 ++ ;
if ( ! V_243 &&
( V_298 == NULL ||
V_183 > V_300 ) )
break;
} while ( ! V_243 );
if ( V_298 )
F_20 ( & V_298 -> V_2 -> V_6 ) ;
return V_243 ;
}
static inline bool F_262 ( struct V_1 * V_2 )
{
bool V_119 ;
F_263 ( & V_301 ) ;
F_13 () ;
V_119 = F_264 ( NULL , & V_2 -> V_6 ) ;
F_17 () ;
return V_119 ;
}
static int F_265 ( struct V_1 * V_2 )
{
int V_238 = V_239 ;
F_266 () ;
while ( V_238 && F_47 ( & V_2 -> V_50 ) ) {
int V_302 ;
if ( F_258 ( V_19 ) )
return - V_258 ;
V_302 = F_201 ( V_2 , 1 ,
V_271 , true ) ;
if ( ! V_302 ) {
V_238 -- ;
F_267 ( V_303 , V_304 / 10 ) ;
}
}
return 0 ;
}
static T_5 F_268 ( struct V_305 * V_306 ,
char * V_307 , T_6 V_308 ,
T_7 V_309 )
{
struct V_1 * V_2 = F_2 ( F_269 ( V_306 ) ) ;
if ( F_6 ( V_2 ) )
return - V_292 ;
return F_265 ( V_2 ) ? : V_308 ;
}
static V_144 F_270 ( struct V_4 * V_6 ,
struct V_310 * V_311 )
{
return F_2 ( V_6 ) -> V_105 ;
}
static int F_271 ( struct V_4 * V_6 ,
struct V_310 * V_311 , V_144 V_59 )
{
int V_312 = 0 ;
struct V_1 * V_2 = F_2 ( V_6 ) ;
struct V_1 * V_313 = F_2 ( V_2 -> V_6 . V_40 ) ;
F_118 ( & V_301 ) ;
if ( V_2 -> V_105 == V_59 )
goto V_106;
if ( ( ! V_313 || ! V_313 -> V_105 ) &&
( V_59 == 1 || V_59 == 0 ) ) {
if ( ! F_262 ( V_2 ) )
V_2 -> V_105 = V_59 ;
else
V_312 = - V_314 ;
} else
V_312 = - V_292 ;
V_106:
F_125 ( & V_301 ) ;
return V_312 ;
}
static unsigned long F_272 ( struct V_1 * V_2 ,
enum V_57 V_58 )
{
struct V_1 * V_103 ;
long V_59 = 0 ;
F_124 (iter, memcg)
V_59 += F_58 ( V_103 , V_58 ) ;
if ( V_59 < 0 )
V_59 = 0 ;
return V_59 ;
}
static inline V_144 F_273 ( struct V_1 * V_2 , bool V_315 )
{
V_144 V_59 ;
if ( F_6 ( V_2 ) ) {
V_59 = F_272 ( V_2 , V_66 ) ;
V_59 += F_272 ( V_2 , V_65 ) ;
if ( V_315 )
V_59 += F_272 ( V_2 , V_148 ) ;
} else {
if ( ! V_315 )
V_59 = F_47 ( & V_2 -> V_50 ) ;
else
V_59 = F_47 ( & V_2 -> V_131 ) ;
}
return V_59 << V_126 ;
}
static V_144 F_274 ( struct V_4 * V_6 ,
struct V_310 * V_311 )
{
struct V_1 * V_2 = F_2 ( V_6 ) ;
struct V_241 * V_242 ;
switch ( F_275 ( V_311 -> V_208 ) ) {
case V_316 :
V_242 = & V_2 -> V_50 ;
break;
case V_317 :
V_242 = & V_2 -> V_131 ;
break;
case V_318 :
V_242 = & V_2 -> V_146 ;
break;
default:
F_93 () ;
}
switch ( F_276 ( V_311 -> V_208 ) ) {
case V_319 :
if ( V_242 == & V_2 -> V_50 )
return F_273 ( V_2 , false ) ;
if ( V_242 == & V_2 -> V_131 )
return F_273 ( V_2 , true ) ;
return ( V_144 ) F_47 ( V_242 ) * V_320 ;
case V_321 :
return ( V_144 ) V_242 -> V_129 * V_320 ;
case V_322 :
return ( V_144 ) V_242 -> V_323 * V_320 ;
case V_324 :
return V_242 -> V_145 ;
case V_325 :
return ( V_144 ) V_2 -> V_51 * V_320 ;
default:
F_93 () ;
}
}
static int F_277 ( struct V_1 * V_2 ,
unsigned long V_49 )
{
int V_268 = 0 ;
int V_326 ;
F_11 ( V_2 -> V_266 >= 0 ) ;
F_11 ( V_2 -> V_327 ) ;
F_11 ( V_2 -> V_3 ) ;
F_118 ( & V_301 ) ;
if ( F_278 ( V_2 -> V_6 . V_29 ) ||
( V_2 -> V_105 && F_262 ( V_2 ) ) )
V_268 = - V_314 ;
F_125 ( & V_301 ) ;
if ( V_268 )
goto V_106;
V_326 = F_225 () ;
if ( V_326 < 0 ) {
V_268 = V_326 ;
goto V_106;
}
V_268 = F_259 ( & V_2 -> V_146 , V_49 ) ;
F_69 ( V_268 ) ;
F_279 ( & V_328 ) ;
V_2 -> V_266 = V_326 ;
V_2 -> V_327 = true ;
V_2 -> V_3 = true ;
V_106:
return V_268 ;
}
static int F_280 ( struct V_1 * V_2 ,
unsigned long V_129 )
{
int V_119 ;
F_118 ( & V_297 ) ;
if ( ! F_1 ( V_2 ) )
V_119 = F_277 ( V_2 , V_129 ) ;
else
V_119 = F_259 ( & V_2 -> V_146 , V_129 ) ;
F_125 ( & V_297 ) ;
return V_119 ;
}
static int F_281 ( struct V_1 * V_2 )
{
int V_119 = 0 ;
struct V_1 * V_40 = F_50 ( V_2 ) ;
if ( ! V_40 )
return 0 ;
F_118 ( & V_297 ) ;
if ( F_1 ( V_40 ) )
V_119 = F_277 ( V_2 , V_329 ) ;
F_125 ( & V_297 ) ;
return V_119 ;
}
static int F_280 ( struct V_1 * V_2 ,
unsigned long V_129 )
{
return - V_292 ;
}
static T_5 F_282 ( struct V_305 * V_306 ,
char * V_307 , T_6 V_308 , T_7 V_309 )
{
struct V_1 * V_2 = F_2 ( F_269 ( V_306 ) ) ;
unsigned long V_49 ;
int V_119 ;
V_307 = F_283 ( V_307 ) ;
V_119 = F_284 ( V_307 , L_13 , & V_49 ) ;
if ( V_119 )
return V_119 ;
switch ( F_276 ( F_285 ( V_306 ) -> V_208 ) ) {
case V_321 :
if ( F_6 ( V_2 ) ) {
V_119 = - V_292 ;
break;
}
switch ( F_275 ( F_285 ( V_306 ) -> V_208 ) ) {
case V_316 :
V_119 = F_257 ( V_2 , V_49 ) ;
break;
case V_317 :
V_119 = F_260 ( V_2 , V_49 ) ;
break;
case V_318 :
V_119 = F_280 ( V_2 , V_49 ) ;
break;
}
break;
case V_325 :
V_2 -> V_51 = V_49 ;
V_119 = 0 ;
break;
}
return V_119 ? : V_308 ;
}
static T_5 F_286 ( struct V_305 * V_306 , char * V_307 ,
T_6 V_308 , T_7 V_309 )
{
struct V_1 * V_2 = F_2 ( F_269 ( V_306 ) ) ;
struct V_241 * V_242 ;
switch ( F_275 ( F_285 ( V_306 ) -> V_208 ) ) {
case V_316 :
V_242 = & V_2 -> V_50 ;
break;
case V_317 :
V_242 = & V_2 -> V_131 ;
break;
case V_318 :
V_242 = & V_2 -> V_146 ;
break;
default:
F_93 () ;
}
switch ( F_276 ( F_285 ( V_306 ) -> V_208 ) ) {
case V_322 :
F_287 ( V_242 ) ;
break;
case V_324 :
V_242 -> V_145 = 0 ;
break;
default:
F_93 () ;
}
return V_308 ;
}
static V_144 F_288 ( struct V_4 * V_6 ,
struct V_310 * V_311 )
{
return F_2 ( V_6 ) -> V_330 ;
}
static int F_289 ( struct V_4 * V_6 ,
struct V_310 * V_311 , V_144 V_59 )
{
struct V_1 * V_2 = F_2 ( V_6 ) ;
if ( V_59 & ~ V_331 )
return - V_292 ;
V_2 -> V_330 = V_59 ;
return 0 ;
}
static int F_289 ( struct V_4 * V_6 ,
struct V_310 * V_311 , V_144 V_59 )
{
return - V_332 ;
}
static int F_290 ( struct V_333 * V_334 , void * V_335 )
{
struct V_336 {
const char * V_337 ;
unsigned int V_75 ;
};
static const struct V_336 V_338 [] = {
{ L_14 , V_339 } ,
{ L_15 , V_171 } ,
{ L_16 , V_172 } ,
{ L_17 , F_71 (LRU_UNEVICTABLE) } ,
} ;
const struct V_336 * V_61 ;
int V_24 ;
unsigned long V_76 ;
struct V_1 * V_2 = F_2 ( F_291 ( V_334 ) ) ;
for ( V_61 = V_338 ; V_61 < V_338 + F_292 ( V_338 ) ; V_61 ++ ) {
V_76 = F_72 ( V_2 , V_61 -> V_75 ) ;
F_293 ( V_334 , L_18 , V_61 -> V_337 , V_76 ) ;
F_73 (nid, N_MEMORY) {
V_76 = F_68 ( V_2 , V_24 ,
V_61 -> V_75 ) ;
F_293 ( V_334 , L_19 , V_24 , V_76 ) ;
}
F_294 ( V_334 , '\n' ) ;
}
for ( V_61 = V_338 ; V_61 < V_338 + F_292 ( V_338 ) ; V_61 ++ ) {
struct V_1 * V_103 ;
V_76 = 0 ;
F_124 (iter, memcg)
V_76 += F_72 ( V_103 , V_61 -> V_75 ) ;
F_293 ( V_334 , L_20 , V_61 -> V_337 , V_76 ) ;
F_73 (nid, N_MEMORY) {
V_76 = 0 ;
F_124 (iter, memcg)
V_76 += F_68 (
V_103 , V_24 , V_61 -> V_75 ) ;
F_293 ( V_334 , L_19 , V_24 , V_76 ) ;
}
F_294 ( V_334 , '\n' ) ;
}
return 0 ;
}
static int F_295 ( struct V_333 * V_334 , void * V_335 )
{
struct V_1 * V_2 = F_2 ( F_291 ( V_334 ) ) ;
unsigned long V_50 , V_131 ;
struct V_1 * V_340 ;
unsigned int V_143 ;
F_296 ( F_292 ( V_149 ) !=
V_147 ) ;
F_296 ( F_292 ( V_341 ) !=
V_342 ) ;
F_296 ( F_292 ( V_151 ) != V_150 ) ;
for ( V_143 = 0 ; V_143 < V_147 ; V_143 ++ ) {
if ( V_143 == V_148 && ! V_130 )
continue;
F_293 ( V_334 , L_21 , V_149 [ V_143 ] ,
F_58 ( V_2 , V_143 ) * V_320 ) ;
}
for ( V_143 = 0 ; V_143 < V_342 ; V_143 ++ )
F_293 ( V_334 , L_22 , V_341 [ V_143 ] ,
F_61 ( V_2 , V_143 ) ) ;
for ( V_143 = 0 ; V_143 < V_150 ; V_143 ++ )
F_293 ( V_334 , L_22 , V_151 [ V_143 ] ,
F_72 ( V_2 , F_71 ( V_143 ) ) * V_320 ) ;
V_50 = V_131 = V_329 ;
for ( V_340 = V_2 ; V_340 ; V_340 = F_50 ( V_340 ) ) {
V_50 = F_106 ( V_50 , V_340 -> V_50 . V_129 ) ;
V_131 = F_106 ( V_131 , V_340 -> V_131 . V_129 ) ;
}
F_293 ( V_334 , L_23 ,
( V_144 ) V_50 * V_320 ) ;
if ( V_130 )
F_293 ( V_334 , L_24 ,
( V_144 ) V_131 * V_320 ) ;
for ( V_143 = 0 ; V_143 < V_147 ; V_143 ++ ) {
long long V_59 = 0 ;
if ( V_143 == V_148 && ! V_130 )
continue;
F_124 (mi, memcg)
V_59 += F_58 ( V_340 , V_143 ) * V_320 ;
F_293 ( V_334 , L_25 , V_149 [ V_143 ] , V_59 ) ;
}
for ( V_143 = 0 ; V_143 < V_342 ; V_143 ++ ) {
unsigned long long V_59 = 0 ;
F_124 (mi, memcg)
V_59 += F_61 ( V_340 , V_143 ) ;
F_293 ( V_334 , L_26 ,
V_341 [ V_143 ] , V_59 ) ;
}
for ( V_143 = 0 ; V_143 < V_150 ; V_143 ++ ) {
unsigned long long V_59 = 0 ;
F_124 (mi, memcg)
V_59 += F_72 ( V_340 , F_71 ( V_143 ) ) * V_320 ;
F_293 ( V_334 , L_26 , V_151 [ V_143 ] , V_59 ) ;
}
#ifdef F_297
{
int V_24 , V_25 ;
struct V_22 * V_34 ;
struct V_343 * V_344 ;
unsigned long V_345 [ 2 ] = { 0 , 0 } ;
unsigned long V_346 [ 2 ] = { 0 , 0 } ;
F_298 (nid)
for ( V_25 = 0 ; V_25 < V_53 ; V_25 ++ ) {
V_34 = & V_2 -> V_26 [ V_24 ] -> V_27 [ V_25 ] ;
V_344 = & V_34 -> V_71 . V_347 ;
V_345 [ 0 ] += V_344 -> V_345 [ 0 ] ;
V_345 [ 1 ] += V_344 -> V_345 [ 1 ] ;
V_346 [ 0 ] += V_344 -> V_346 [ 0 ] ;
V_346 [ 1 ] += V_344 -> V_346 [ 1 ] ;
}
F_293 ( V_334 , L_27 , V_345 [ 0 ] ) ;
F_293 ( V_334 , L_28 , V_345 [ 1 ] ) ;
F_293 ( V_334 , L_29 , V_346 [ 0 ] ) ;
F_293 ( V_334 , L_30 , V_346 [ 1 ] ) ;
}
#endif
return 0 ;
}
static V_144 F_299 ( struct V_4 * V_6 ,
struct V_310 * V_311 )
{
struct V_1 * V_2 = F_2 ( V_6 ) ;
return F_107 ( V_2 ) ;
}
static int F_300 ( struct V_4 * V_6 ,
struct V_310 * V_311 , V_144 V_59 )
{
struct V_1 * V_2 = F_2 ( V_6 ) ;
if ( V_59 > 100 )
return - V_292 ;
if ( V_6 -> V_40 )
V_2 -> V_133 = V_59 ;
else
V_132 = V_59 ;
return 0 ;
}
static void F_301 ( struct V_1 * V_2 , bool V_315 )
{
struct V_348 * V_349 ;
unsigned long V_350 ;
int V_143 ;
F_13 () ;
if ( ! V_315 )
V_349 = F_83 ( V_2 -> V_351 . V_352 ) ;
else
V_349 = F_83 ( V_2 -> V_353 . V_352 ) ;
if ( ! V_349 )
goto V_137;
V_350 = F_273 ( V_2 , V_315 ) ;
V_143 = V_349 -> V_354 ;
for (; V_143 >= 0 && F_78 ( V_349 -> V_355 [ V_143 ] . V_356 > V_350 ) ; V_143 -- )
F_302 ( V_349 -> V_355 [ V_143 ] . V_357 , 1 ) ;
V_143 ++ ;
for (; V_143 < V_349 -> V_267 && F_78 ( V_349 -> V_355 [ V_143 ] . V_356 <= V_350 ) ; V_143 ++ )
F_302 ( V_349 -> V_355 [ V_143 ] . V_357 , 1 ) ;
V_349 -> V_354 = V_143 - 1 ;
V_137:
F_17 () ;
}
static void F_79 ( struct V_1 * V_2 )
{
while ( V_2 ) {
F_301 ( V_2 , false ) ;
if ( V_130 )
F_301 ( V_2 , true ) ;
V_2 = F_50 ( V_2 ) ;
}
}
static int F_303 ( const void * V_358 , const void * V_359 )
{
const struct F_79 * V_360 = V_358 ;
const struct F_79 * V_361 = V_359 ;
if ( V_360 -> V_356 > V_361 -> V_356 )
return 1 ;
if ( V_360 -> V_356 < V_361 -> V_356 )
return - 1 ;
return 0 ;
}
static int F_304 ( struct V_1 * V_2 )
{
struct V_362 * V_363 ;
F_109 ( & V_187 ) ;
F_305 (ev, &memcg->oom_notify, list)
F_302 ( V_363 -> V_357 , 1 ) ;
F_110 ( & V_187 ) ;
return 0 ;
}
static void F_168 ( struct V_1 * V_2 )
{
struct V_1 * V_103 ;
F_124 (iter, memcg)
F_304 ( V_103 ) ;
}
static int F_306 ( struct V_1 * V_2 ,
struct V_364 * V_357 , const char * args , enum V_365 type )
{
struct V_366 * V_351 ;
struct V_348 * V_367 ;
unsigned long V_356 ;
unsigned long V_350 ;
int V_143 , V_267 , V_119 ;
V_119 = F_284 ( args , L_13 , & V_356 ) ;
if ( V_119 )
return V_119 ;
F_118 ( & V_2 -> V_368 ) ;
if ( type == V_316 ) {
V_351 = & V_2 -> V_351 ;
V_350 = F_273 ( V_2 , false ) ;
} else if ( type == V_317 ) {
V_351 = & V_2 -> V_353 ;
V_350 = F_273 ( V_2 , true ) ;
} else
F_93 () ;
if ( V_351 -> V_352 )
F_301 ( V_2 , type == V_317 ) ;
V_267 = V_351 -> V_352 ? V_351 -> V_352 -> V_267 + 1 : 1 ;
V_367 = F_237 ( sizeof( * V_367 ) + V_267 * sizeof( struct F_79 ) ,
V_271 ) ;
if ( ! V_367 ) {
V_119 = - V_257 ;
goto V_137;
}
V_367 -> V_267 = V_267 ;
if ( V_351 -> V_352 ) {
memcpy ( V_367 -> V_355 , V_351 -> V_352 -> V_355 , ( V_267 - 1 ) *
sizeof( struct F_79 ) ) ;
}
V_367 -> V_355 [ V_267 - 1 ] . V_357 = V_357 ;
V_367 -> V_355 [ V_267 - 1 ] . V_356 = V_356 ;
F_307 ( V_367 -> V_355 , V_267 , sizeof( struct F_79 ) ,
F_303 , NULL ) ;
V_367 -> V_354 = - 1 ;
for ( V_143 = 0 ; V_143 < V_267 ; V_143 ++ ) {
if ( V_367 -> V_355 [ V_143 ] . V_356 <= V_350 ) {
++ V_367 -> V_354 ;
} else
break;
}
F_235 ( V_351 -> V_369 ) ;
V_351 -> V_369 = V_351 -> V_352 ;
F_308 ( V_351 -> V_352 , V_367 ) ;
F_309 () ;
V_137:
F_125 ( & V_2 -> V_368 ) ;
return V_119 ;
}
static int F_310 ( struct V_1 * V_2 ,
struct V_364 * V_357 , const char * args )
{
return F_306 ( V_2 , V_357 , args , V_316 ) ;
}
static int F_311 ( struct V_1 * V_2 ,
struct V_364 * V_357 , const char * args )
{
return F_306 ( V_2 , V_357 , args , V_317 ) ;
}
static void F_312 ( struct V_1 * V_2 ,
struct V_364 * V_357 , enum V_365 type )
{
struct V_366 * V_351 ;
struct V_348 * V_367 ;
unsigned long V_350 ;
int V_143 , V_370 , V_267 ;
F_118 ( & V_2 -> V_368 ) ;
if ( type == V_316 ) {
V_351 = & V_2 -> V_351 ;
V_350 = F_273 ( V_2 , false ) ;
} else if ( type == V_317 ) {
V_351 = & V_2 -> V_353 ;
V_350 = F_273 ( V_2 , true ) ;
} else
F_93 () ;
if ( ! V_351 -> V_352 )
goto V_137;
F_301 ( V_2 , type == V_317 ) ;
V_267 = 0 ;
for ( V_143 = 0 ; V_143 < V_351 -> V_352 -> V_267 ; V_143 ++ ) {
if ( V_351 -> V_352 -> V_355 [ V_143 ] . V_357 != V_357 )
V_267 ++ ;
}
V_367 = V_351 -> V_369 ;
if ( ! V_267 ) {
F_235 ( V_367 ) ;
V_367 = NULL ;
goto V_371;
}
V_367 -> V_267 = V_267 ;
V_367 -> V_354 = - 1 ;
for ( V_143 = 0 , V_370 = 0 ; V_143 < V_351 -> V_352 -> V_267 ; V_143 ++ ) {
if ( V_351 -> V_352 -> V_355 [ V_143 ] . V_357 == V_357 )
continue;
V_367 -> V_355 [ V_370 ] = V_351 -> V_352 -> V_355 [ V_143 ] ;
if ( V_367 -> V_355 [ V_370 ] . V_356 <= V_350 ) {
++ V_367 -> V_354 ;
}
V_370 ++ ;
}
V_371:
V_351 -> V_369 = V_351 -> V_352 ;
if ( ! V_367 ) {
F_235 ( V_351 -> V_369 ) ;
V_351 -> V_369 = NULL ;
}
F_308 ( V_351 -> V_352 , V_367 ) ;
F_309 () ;
V_137:
F_125 ( & V_2 -> V_368 ) ;
}
static void F_313 ( struct V_1 * V_2 ,
struct V_364 * V_357 )
{
return F_312 ( V_2 , V_357 , V_316 ) ;
}
static void F_314 ( struct V_1 * V_2 ,
struct V_364 * V_357 )
{
return F_312 ( V_2 , V_357 , V_317 ) ;
}
static int F_315 ( struct V_1 * V_2 ,
struct V_364 * V_357 , const char * args )
{
struct V_362 * V_372 ;
V_372 = F_237 ( sizeof( * V_372 ) , V_271 ) ;
if ( ! V_372 )
return - V_257 ;
F_109 ( & V_187 ) ;
V_372 -> V_357 = V_357 ;
F_316 ( & V_372 -> V_373 , & V_2 -> V_374 ) ;
if ( V_2 -> V_190 )
F_302 ( V_357 , 1 ) ;
F_110 ( & V_187 ) ;
return 0 ;
}
static void F_317 ( struct V_1 * V_2 ,
struct V_364 * V_357 )
{
struct V_362 * V_363 , * V_375 ;
F_109 ( & V_187 ) ;
F_318 (ev, tmp, &memcg->oom_notify, list) {
if ( V_363 -> V_357 == V_357 ) {
F_319 ( & V_363 -> V_373 ) ;
F_235 ( V_363 ) ;
}
}
F_110 ( & V_187 ) ;
}
static int F_320 ( struct V_333 * V_376 , void * V_335 )
{
struct V_1 * V_2 = F_2 ( F_291 ( V_376 ) ) ;
F_293 ( V_376 , L_31 , V_2 -> V_211 ) ;
F_293 ( V_376 , L_32 , ( bool ) V_2 -> V_190 ) ;
return 0 ;
}
static int F_321 ( struct V_4 * V_6 ,
struct V_310 * V_311 , V_144 V_59 )
{
struct V_1 * V_2 = F_2 ( V_6 ) ;
if ( ! V_6 -> V_40 || ! ( ( V_59 == 0 ) || ( V_59 == 1 ) ) )
return - V_292 ;
V_2 -> V_211 = V_59 ;
if ( ! V_59 )
F_163 ( V_2 ) ;
return 0 ;
}
static int F_322 ( struct V_1 * V_2 , struct V_377 * V_378 )
{
int V_119 ;
V_119 = F_281 ( V_2 ) ;
if ( V_119 )
return V_119 ;
return F_323 ( V_2 , V_378 ) ;
}
static void F_324 ( struct V_1 * V_2 )
{
struct V_4 * V_6 ;
struct V_1 * V_40 , * V_379 ;
int V_266 ;
if ( ! V_2 -> V_3 )
return;
V_2 -> V_3 = false ;
F_325 ( V_2 ) ;
V_266 = V_2 -> V_266 ;
F_11 ( V_266 < 0 ) ;
V_40 = F_50 ( V_2 ) ;
if ( ! V_40 )
V_40 = V_8 ;
F_326 (css, &memcg->css) {
V_379 = F_2 ( V_6 ) ;
F_11 ( V_379 -> V_266 != V_266 ) ;
V_379 -> V_266 = V_40 -> V_266 ;
if ( ! V_2 -> V_105 )
break;
}
F_327 ( V_266 , V_40 -> V_266 ) ;
F_232 ( V_266 ) ;
}
static void F_328 ( struct V_1 * V_2 )
{
if ( V_2 -> V_327 ) {
F_329 ( V_2 ) ;
F_330 ( & V_328 ) ;
F_19 ( F_47 ( & V_2 -> V_146 ) ) ;
}
F_331 ( V_2 ) ;
}
static int F_322 ( struct V_1 * V_2 , struct V_377 * V_378 )
{
return 0 ;
}
static void F_324 ( struct V_1 * V_2 )
{
}
static void F_328 ( struct V_1 * V_2 )
{
}
struct V_380 * F_332 ( struct V_1 * V_2 )
{
return & V_2 -> V_381 ;
}
static int F_333 ( struct V_1 * V_2 , T_2 V_265 )
{
return F_334 ( & V_2 -> V_382 , V_265 ) ;
}
static void F_335 ( struct V_1 * V_2 )
{
F_336 ( & V_2 -> V_382 ) ;
}
static void F_337 ( struct V_1 * V_2 )
{
F_338 ( & V_2 -> V_382 ) ;
}
struct V_383 * F_339 ( struct V_384 * V_385 )
{
struct V_1 * V_2 = F_2 ( V_385 -> V_386 ) ;
if ( ! V_2 -> V_6 . V_40 )
return NULL ;
return & V_2 -> V_382 ;
}
void F_340 ( struct V_384 * V_385 , unsigned long * V_387 ,
unsigned long * V_388 , unsigned long * V_389 )
{
struct V_1 * V_2 = F_2 ( V_385 -> V_386 ) ;
struct V_1 * V_40 ;
unsigned long V_390 = V_329 ;
unsigned long V_391 ;
* V_388 = F_58 ( V_2 , V_392 ) ;
* V_389 = F_58 ( V_2 , V_393 ) ;
V_391 = F_72 ( V_2 , ( 1 << V_394 ) |
( 1 << V_395 ) ) ;
while ( ( V_40 = F_50 ( V_2 ) ) ) {
unsigned long V_396 = F_106 ( V_2 -> V_50 . V_129 , V_2 -> V_259 ) ;
unsigned long V_397 = F_47 ( & V_2 -> V_50 ) ;
V_390 = F_106 ( V_390 , V_396 - F_106 ( V_396 , V_397 ) ) ;
V_2 = V_40 ;
}
* V_387 = V_391 + V_390 ;
}
static int F_333 ( struct V_1 * V_2 , T_2 V_265 )
{
return 0 ;
}
static void F_335 ( struct V_1 * V_2 )
{
}
static void F_337 ( struct V_1 * V_2 )
{
}
static void F_341 ( struct V_223 * V_228 )
{
struct V_398 * V_372 =
F_3 ( V_228 , struct V_398 , remove ) ;
struct V_1 * V_2 = V_372 -> V_2 ;
F_342 ( V_372 -> V_399 , & V_372 -> V_139 ) ;
V_372 -> V_400 ( V_2 , V_372 -> V_357 ) ;
F_302 ( V_372 -> V_357 , 1 ) ;
F_343 ( V_372 -> V_357 ) ;
F_235 ( V_372 ) ;
F_20 ( & V_2 -> V_6 ) ;
}
static int F_344 ( T_3 * V_139 , unsigned V_191 ,
int V_192 , void * V_401 )
{
struct V_398 * V_372 =
F_3 ( V_139 , struct V_398 , V_139 ) ;
struct V_1 * V_2 = V_372 -> V_2 ;
unsigned long V_47 = ( unsigned long ) V_401 ;
if ( V_47 & V_402 ) {
F_109 ( & V_2 -> V_403 ) ;
if ( ! F_345 ( & V_372 -> V_373 ) ) {
F_346 ( & V_372 -> V_373 ) ;
F_239 ( & V_372 -> remove ) ;
}
F_110 ( & V_2 -> V_403 ) ;
}
return 0 ;
}
static void F_347 ( struct V_404 * V_404 ,
T_8 * V_399 , T_9 * V_405 )
{
struct V_398 * V_372 =
F_3 ( V_405 , struct V_398 , V_405 ) ;
V_372 -> V_399 = V_399 ;
F_348 ( V_399 , & V_372 -> V_139 ) ;
}
static T_5 F_349 ( struct V_305 * V_306 ,
char * V_307 , T_6 V_308 , T_7 V_309 )
{
struct V_4 * V_6 = F_269 ( V_306 ) ;
struct V_1 * V_2 = F_2 ( V_6 ) ;
struct V_398 * V_372 ;
struct V_4 * V_406 ;
unsigned int V_407 , V_408 ;
struct V_409 V_410 ;
struct V_409 V_411 ;
const char * V_337 ;
char * V_412 ;
int V_119 ;
V_307 = F_283 ( V_307 ) ;
V_407 = F_350 ( V_307 , & V_412 , 10 ) ;
if ( * V_412 != ' ' )
return - V_292 ;
V_307 = V_412 + 1 ;
V_408 = F_350 ( V_307 , & V_412 , 10 ) ;
if ( ( * V_412 != ' ' ) && ( * V_412 != '\0' ) )
return - V_292 ;
V_307 = V_412 + 1 ;
V_372 = F_351 ( sizeof( * V_372 ) , V_271 ) ;
if ( ! V_372 )
return - V_257 ;
V_372 -> V_2 = V_2 ;
F_167 ( & V_372 -> V_373 ) ;
F_352 ( & V_372 -> V_405 , F_347 ) ;
F_353 ( & V_372 -> V_139 , F_344 ) ;
F_238 ( & V_372 -> remove , F_341 ) ;
V_410 = F_354 ( V_407 ) ;
if ( ! V_410 . V_404 ) {
V_119 = - V_413 ;
goto V_414;
}
V_372 -> V_357 = F_355 ( V_410 . V_404 ) ;
if ( F_356 ( V_372 -> V_357 ) ) {
V_119 = F_357 ( V_372 -> V_357 ) ;
goto V_415;
}
V_411 = F_354 ( V_408 ) ;
if ( ! V_411 . V_404 ) {
V_119 = - V_413 ;
goto V_416;
}
V_119 = F_358 ( F_359 ( V_411 . V_404 ) , V_417 ) ;
if ( V_119 < 0 )
goto V_418;
V_337 = V_411 . V_404 -> V_419 . V_420 -> V_421 . V_337 ;
if ( ! strcmp ( V_337 , L_33 ) ) {
V_372 -> V_422 = F_310 ;
V_372 -> V_400 = F_313 ;
} else if ( ! strcmp ( V_337 , L_34 ) ) {
V_372 -> V_422 = F_315 ;
V_372 -> V_400 = F_317 ;
} else if ( ! strcmp ( V_337 , L_35 ) ) {
V_372 -> V_422 = V_423 ;
V_372 -> V_400 = V_424 ;
} else if ( ! strcmp ( V_337 , L_36 ) ) {
V_372 -> V_422 = F_311 ;
V_372 -> V_400 = F_314 ;
} else {
V_119 = - V_292 ;
goto V_418;
}
V_406 = F_360 ( V_411 . V_404 -> V_419 . V_420 -> V_425 ,
& V_11 ) ;
V_119 = - V_292 ;
if ( F_356 ( V_406 ) )
goto V_418;
if ( V_406 != V_6 ) {
F_20 ( V_406 ) ;
goto V_418;
}
V_119 = V_372 -> V_422 ( V_2 , V_372 -> V_357 , V_307 ) ;
if ( V_119 )
goto V_426;
V_410 . V_404 -> V_427 -> V_428 ( V_410 . V_404 , & V_372 -> V_405 ) ;
F_109 ( & V_2 -> V_403 ) ;
F_316 ( & V_372 -> V_373 , & V_2 -> V_429 ) ;
F_110 ( & V_2 -> V_403 ) ;
F_361 ( V_411 ) ;
F_361 ( V_410 ) ;
return V_308 ;
V_426:
F_20 ( V_6 ) ;
V_418:
F_361 ( V_411 ) ;
V_416:
F_343 ( V_372 -> V_357 ) ;
V_415:
F_361 ( V_410 ) ;
V_414:
F_235 ( V_372 ) ;
return V_119 ;
}
static int F_362 ( struct V_1 * V_2 , int V_177 )
{
struct V_430 * V_431 ;
struct V_22 * V_34 ;
int V_23 , V_375 = V_177 ;
if ( ! F_363 ( V_177 , V_432 ) )
V_375 = - 1 ;
V_431 = F_364 ( sizeof( * V_431 ) , V_271 , V_375 ) ;
if ( ! V_431 )
return 1 ;
for ( V_23 = 0 ; V_23 < V_53 ; V_23 ++ ) {
V_34 = & V_431 -> V_27 [ V_23 ] ;
F_365 ( & V_34 -> V_71 ) ;
V_34 -> V_43 = 0 ;
V_34 -> V_42 = false ;
V_34 -> V_2 = V_2 ;
}
V_2 -> V_26 [ V_177 ] = V_431 ;
return 0 ;
}
static void F_366 ( struct V_1 * V_2 , int V_177 )
{
F_235 ( V_2 -> V_26 [ V_177 ] ) ;
}
static struct V_1 * F_367 ( void )
{
struct V_1 * V_2 ;
T_6 V_267 ;
V_267 = sizeof( struct V_1 ) ;
V_267 += V_77 * sizeof( struct V_430 * ) ;
V_2 = F_351 ( V_267 , V_271 ) ;
if ( ! V_2 )
return NULL ;
V_2 -> V_61 = F_368 ( struct V_433 ) ;
if ( ! V_2 -> V_61 )
goto V_434;
if ( F_333 ( V_2 , V_271 ) )
goto V_435;
F_369 ( & V_2 -> V_436 ) ;
return V_2 ;
V_435:
F_370 ( V_2 -> V_61 ) ;
V_434:
F_235 ( V_2 ) ;
return NULL ;
}
static void F_371 ( struct V_1 * V_2 )
{
int V_177 ;
F_51 ( V_2 ) ;
F_52 (node)
F_366 ( V_2 , V_177 ) ;
F_370 ( V_2 -> V_61 ) ;
F_335 ( V_2 ) ;
F_235 ( V_2 ) ;
}
struct V_1 * F_50 ( struct V_1 * V_2 )
{
if ( ! V_2 -> V_50 . V_40 )
return NULL ;
return F_197 ( V_2 -> V_50 . V_40 , V_50 ) ;
}
static struct V_4 * T_10
F_372 ( struct V_4 * V_437 )
{
struct V_1 * V_2 ;
long error = - V_257 ;
int V_177 ;
V_2 = F_367 () ;
if ( ! V_2 )
return F_373 ( error ) ;
F_52 (node)
if ( F_362 ( V_2 , V_177 ) )
goto V_438;
if ( V_437 == NULL ) {
V_8 = V_2 ;
V_439 = & V_2 -> V_6 ;
F_374 ( & V_2 -> V_50 , NULL ) ;
V_2 -> V_259 = V_329 ;
V_2 -> V_51 = V_329 ;
F_374 ( & V_2 -> V_131 , NULL ) ;
F_374 ( & V_2 -> V_146 , NULL ) ;
}
V_2 -> V_178 = V_90 ;
F_167 ( & V_2 -> V_374 ) ;
V_2 -> V_330 = 0 ;
F_375 ( & V_2 -> V_368 ) ;
F_369 ( & V_2 -> V_214 ) ;
F_376 ( & V_2 -> V_7 ) ;
F_167 ( & V_2 -> V_429 ) ;
F_369 ( & V_2 -> V_403 ) ;
#ifdef F_377
V_2 -> V_266 = - 1 ;
#endif
#ifdef F_378
F_167 ( & V_2 -> V_381 ) ;
#endif
return & V_2 -> V_6 ;
V_438:
F_371 ( V_2 ) ;
return F_373 ( error ) ;
}
static int
F_379 ( struct V_4 * V_6 )
{
struct V_1 * V_2 = F_2 ( V_6 ) ;
struct V_1 * V_40 = F_2 ( V_6 -> V_40 ) ;
int V_119 ;
if ( V_6 -> V_10 > V_440 )
return - V_441 ;
if ( ! V_40 )
return 0 ;
F_118 ( & V_301 ) ;
V_2 -> V_105 = V_40 -> V_105 ;
V_2 -> V_211 = V_40 -> V_211 ;
V_2 -> V_133 = F_107 ( V_40 ) ;
if ( V_40 -> V_105 ) {
F_374 ( & V_2 -> V_50 , & V_40 -> V_50 ) ;
V_2 -> V_259 = V_329 ;
V_2 -> V_51 = V_329 ;
F_374 ( & V_2 -> V_131 , & V_40 -> V_131 ) ;
F_374 ( & V_2 -> V_146 , & V_40 -> V_146 ) ;
} else {
F_374 ( & V_2 -> V_50 , NULL ) ;
V_2 -> V_259 = V_329 ;
V_2 -> V_51 = V_329 ;
F_374 ( & V_2 -> V_131 , NULL ) ;
F_374 ( & V_2 -> V_146 , NULL ) ;
if ( V_40 != V_8 )
V_11 . V_442 = true ;
}
F_125 ( & V_301 ) ;
V_119 = F_322 ( V_2 , & V_11 ) ;
if ( V_119 )
return V_119 ;
F_380 ( & V_2 -> V_111 , 1 ) ;
return 0 ;
}
static void F_381 ( struct V_4 * V_6 )
{
struct V_1 * V_2 = F_2 ( V_6 ) ;
struct V_398 * V_372 , * V_375 ;
F_109 ( & V_2 -> V_403 ) ;
F_318 (event, tmp, &memcg->event_list, list) {
F_346 ( & V_372 -> V_373 ) ;
F_239 ( & V_372 -> remove ) ;
}
F_110 ( & V_2 -> V_403 ) ;
F_382 ( & V_2 -> V_7 ) ;
F_324 ( V_2 ) ;
F_383 ( V_2 ) ;
}
static void F_384 ( struct V_4 * V_6 )
{
struct V_1 * V_2 = F_2 ( V_6 ) ;
F_328 ( V_2 ) ;
F_371 ( V_2 ) ;
}
static void F_385 ( struct V_4 * V_6 )
{
struct V_1 * V_2 = F_2 ( V_6 ) ;
F_257 ( V_2 , V_329 ) ;
F_260 ( V_2 , V_329 ) ;
F_280 ( V_2 , V_329 ) ;
V_2 -> V_443 = 0 ;
V_2 -> V_259 = V_329 ;
V_2 -> V_51 = V_329 ;
F_337 ( V_2 ) ;
}
static int F_386 ( unsigned long V_62 )
{
int V_119 ;
V_119 = F_194 ( V_136 . V_135 , V_271 & ~ V_251 , V_62 ) ;
if ( ! V_119 ) {
V_136 . V_444 += V_62 ;
return V_119 ;
}
if ( V_119 == - V_258 ) {
F_204 ( V_8 , V_62 ) ;
return V_119 ;
}
while ( V_62 -- ) {
V_119 = F_194 ( V_136 . V_135 , V_271 & ~ V_253 , 1 ) ;
if ( V_119 == - V_258 )
F_204 ( V_8 , 1 ) ;
if ( V_119 )
return V_119 ;
V_136 . V_444 ++ ;
F_387 () ;
}
return 0 ;
}
static struct V_28 * F_388 ( struct V_445 * V_446 ,
unsigned long V_447 , T_11 V_448 )
{
struct V_28 * V_28 = F_389 ( V_446 , V_447 , V_448 ) ;
if ( ! V_28 || ! F_390 ( V_28 ) )
return NULL ;
if ( F_63 ( V_28 ) ) {
if ( ! ( V_136 . V_47 & V_449 ) )
return NULL ;
} else {
if ( ! ( V_136 . V_47 & V_450 ) )
return NULL ;
}
if ( ! F_391 ( V_28 ) )
return NULL ;
return V_28 ;
}
static struct V_28 * F_392 ( struct V_445 * V_446 ,
unsigned long V_447 , T_11 V_448 , T_4 * V_289 )
{
struct V_28 * V_28 = NULL ;
T_4 V_261 = F_393 ( V_448 ) ;
if ( ! ( V_136 . V_47 & V_449 ) || F_394 ( V_261 ) )
return NULL ;
V_28 = F_395 ( F_396 ( V_261 ) , V_261 . V_59 ) ;
if ( V_130 )
V_289 -> V_59 = V_261 . V_59 ;
return V_28 ;
}
static struct V_28 * F_392 ( struct V_445 * V_446 ,
unsigned long V_447 , T_11 V_448 , T_4 * V_289 )
{
return NULL ;
}
static struct V_28 * F_397 ( struct V_445 * V_446 ,
unsigned long V_447 , T_11 V_448 , T_4 * V_289 )
{
struct V_28 * V_28 = NULL ;
struct V_451 * V_452 ;
T_12 V_453 ;
if ( ! V_446 -> V_454 )
return NULL ;
if ( ! ( V_136 . V_47 & V_450 ) )
return NULL ;
V_452 = V_446 -> V_454 -> V_455 ;
V_453 = F_398 ( V_446 , V_447 ) ;
#ifdef F_399
if ( F_400 ( V_452 ) ) {
V_28 = F_401 ( V_452 , V_453 ) ;
if ( F_402 ( V_28 ) ) {
T_4 V_456 = F_403 ( V_28 ) ;
if ( V_130 )
* V_289 = V_456 ;
V_28 = F_395 ( F_396 ( V_456 ) , V_456 . V_59 ) ;
}
} else
V_28 = F_395 ( V_452 , V_453 ) ;
#else
V_28 = F_395 ( V_452 , V_453 ) ;
#endif
return V_28 ;
}
static int F_404 ( struct V_28 * V_28 ,
unsigned int V_49 ,
struct V_1 * V_134 ,
struct V_1 * V_135 )
{
unsigned long V_47 ;
int V_119 ;
bool V_457 ;
F_69 ( V_134 == V_135 ) ;
F_206 ( F_213 ( V_28 ) , V_28 ) ;
V_119 = - V_314 ;
if ( V_49 > 1 && ! F_65 ( V_28 ) )
goto V_106;
if ( ! F_405 ( V_28 ) )
goto V_106;
V_119 = - V_292 ;
if ( V_28 -> V_1 != V_134 )
goto V_109;
V_457 = F_63 ( V_28 ) ;
F_44 ( & V_134 -> V_214 , V_47 ) ;
if ( ! V_457 && F_390 ( V_28 ) ) {
F_253 ( V_134 -> V_61 -> V_62 [ V_458 ] ,
V_49 ) ;
F_64 ( V_135 -> V_61 -> V_62 [ V_458 ] ,
V_49 ) ;
}
if ( ! V_457 && F_406 ( V_28 ) ) {
struct V_451 * V_452 = F_407 ( V_28 ) ;
if ( F_408 ( V_452 ) ) {
F_253 ( V_134 -> V_61 -> V_62 [ V_392 ] ,
V_49 ) ;
F_64 ( V_135 -> V_61 -> V_62 [ V_392 ] ,
V_49 ) ;
}
}
if ( F_409 ( V_28 ) ) {
F_253 ( V_134 -> V_61 -> V_62 [ V_393 ] ,
V_49 ) ;
F_64 ( V_135 -> V_61 -> V_62 [ V_393 ] ,
V_49 ) ;
}
V_28 -> V_1 = V_135 ;
F_45 ( & V_134 -> V_214 , V_47 ) ;
V_119 = 0 ;
F_410 () ;
F_62 ( V_135 , V_28 , V_49 ) ;
F_77 ( V_135 , V_28 ) ;
F_62 ( V_134 , V_28 , - V_49 ) ;
F_77 ( V_134 , V_28 ) ;
F_411 () ;
V_109:
F_412 ( V_28 ) ;
V_106:
return V_119 ;
}
static enum V_459 F_413 ( struct V_445 * V_446 ,
unsigned long V_447 , T_11 V_448 , union V_460 * V_79 )
{
struct V_28 * V_28 = NULL ;
enum V_459 V_119 = V_461 ;
T_4 V_261 = { . V_59 = 0 } ;
if ( F_414 ( V_448 ) )
V_28 = F_388 ( V_446 , V_447 , V_448 ) ;
else if ( F_415 ( V_448 ) )
V_28 = F_392 ( V_446 , V_447 , V_448 , & V_261 ) ;
else if ( F_416 ( V_448 ) )
V_28 = F_397 ( V_446 , V_447 , V_448 , & V_261 ) ;
if ( ! V_28 && ! V_261 . V_59 )
return V_119 ;
if ( V_28 ) {
if ( V_28 -> V_1 == V_136 . V_134 ) {
V_119 = V_462 ;
if ( V_79 )
V_79 -> V_28 = V_28 ;
}
if ( ! V_119 || ! V_79 )
F_417 ( V_28 ) ;
}
if ( V_261 . V_59 && ! V_119 &&
F_7 ( V_136 . V_134 ) == F_210 ( V_261 ) ) {
V_119 = V_463 ;
if ( V_79 )
V_79 -> V_261 = V_261 ;
}
return V_119 ;
}
static enum V_459 F_418 ( struct V_445 * V_446 ,
unsigned long V_447 , T_13 V_464 , union V_460 * V_79 )
{
struct V_28 * V_28 = NULL ;
enum V_459 V_119 = V_461 ;
V_28 = F_419 ( V_464 ) ;
F_206 ( ! V_28 || ! F_420 ( V_28 ) , V_28 ) ;
if ( ! ( V_136 . V_47 & V_449 ) )
return V_119 ;
if ( V_28 -> V_1 == V_136 . V_134 ) {
V_119 = V_462 ;
if ( V_79 ) {
F_421 ( V_28 ) ;
V_79 -> V_28 = V_28 ;
}
}
return V_119 ;
}
static inline enum V_459 F_418 ( struct V_445 * V_446 ,
unsigned long V_447 , T_13 V_464 , union V_460 * V_79 )
{
return V_461 ;
}
static int F_422 ( T_13 * V_464 ,
unsigned long V_447 , unsigned long V_465 ,
struct V_466 * V_467 )
{
struct V_445 * V_446 = V_467 -> V_446 ;
T_11 * V_468 ;
T_14 * V_469 ;
if ( F_423 ( V_464 , V_446 , & V_469 ) == 1 ) {
if ( F_418 ( V_446 , V_447 , * V_464 , NULL ) == V_462 )
V_136 . V_444 += V_287 ;
F_110 ( V_469 ) ;
return 0 ;
}
if ( F_424 ( V_464 ) )
return 0 ;
V_468 = F_425 ( V_446 -> V_470 , V_464 , V_447 , & V_469 ) ;
for (; V_447 != V_465 ; V_468 ++ , V_447 += V_320 )
if ( F_413 ( V_446 , V_447 , * V_468 , NULL ) )
V_136 . V_444 ++ ;
F_426 ( V_468 - 1 , V_469 ) ;
F_387 () ;
return 0 ;
}
static unsigned long F_427 ( struct V_94 * V_95 )
{
unsigned long V_444 ;
struct V_466 V_471 = {
. V_472 = F_422 ,
. V_95 = V_95 ,
} ;
F_23 ( & V_95 -> V_473 ) ;
F_428 ( 0 , ~ 0UL , & V_471 ) ;
F_25 ( & V_95 -> V_473 ) ;
V_444 = V_136 . V_444 ;
V_136 . V_444 = 0 ;
return V_444 ;
}
static int F_429 ( struct V_94 * V_95 )
{
unsigned long V_444 = F_427 ( V_95 ) ;
F_69 ( V_136 . V_138 ) ;
V_136 . V_138 = V_19 ;
return F_386 ( V_444 ) ;
}
static void F_430 ( void )
{
struct V_1 * V_134 = V_136 . V_134 ;
struct V_1 * V_135 = V_136 . V_135 ;
if ( V_136 . V_444 ) {
F_204 ( V_136 . V_135 , V_136 . V_444 ) ;
V_136 . V_444 = 0 ;
}
if ( V_136 . V_474 ) {
F_204 ( V_136 . V_134 , V_136 . V_474 ) ;
V_136 . V_474 = 0 ;
}
if ( V_136 . V_475 ) {
if ( ! F_6 ( V_136 . V_134 ) )
F_178 ( & V_136 . V_134 -> V_131 , V_136 . V_475 ) ;
if ( ! F_6 ( V_136 . V_135 ) )
F_178 ( & V_136 . V_135 -> V_50 , V_136 . V_475 ) ;
F_179 ( & V_136 . V_134 -> V_6 , V_136 . V_475 ) ;
V_136 . V_475 = 0 ;
}
F_163 ( V_134 ) ;
F_163 ( V_135 ) ;
F_431 ( & V_136 . V_140 ) ;
}
static void F_432 ( void )
{
V_136 . V_138 = NULL ;
F_430 () ;
F_109 ( & V_136 . V_48 ) ;
V_136 . V_134 = NULL ;
V_136 . V_135 = NULL ;
F_110 ( & V_136 . V_48 ) ;
}
static int F_433 ( struct V_4 * V_6 ,
struct V_476 * V_477 )
{
struct V_92 * V_38 = F_434 ( V_477 ) ;
int V_119 = 0 ;
struct V_1 * V_2 = F_2 ( V_6 ) ;
unsigned long V_478 ;
V_478 = F_48 ( V_2 -> V_330 ) ;
if ( V_478 ) {
struct V_94 * V_95 ;
struct V_1 * V_134 = F_14 ( V_38 ) ;
F_69 ( V_134 == V_2 ) ;
V_95 = F_435 ( V_38 ) ;
if ( ! V_95 )
return 0 ;
if ( V_95 -> V_96 == V_38 ) {
F_69 ( V_136 . V_134 ) ;
F_69 ( V_136 . V_135 ) ;
F_69 ( V_136 . V_444 ) ;
F_69 ( V_136 . V_474 ) ;
F_69 ( V_136 . V_475 ) ;
F_109 ( & V_136 . V_48 ) ;
V_136 . V_134 = V_134 ;
V_136 . V_135 = V_2 ;
V_136 . V_47 = V_478 ;
F_110 ( & V_136 . V_48 ) ;
V_119 = F_429 ( V_95 ) ;
if ( V_119 )
F_432 () ;
}
F_436 ( V_95 ) ;
}
return V_119 ;
}
static void F_437 ( struct V_4 * V_6 ,
struct V_476 * V_477 )
{
if ( V_136 . V_135 )
F_432 () ;
}
static int F_438 ( T_13 * V_464 ,
unsigned long V_447 , unsigned long V_465 ,
struct V_466 * V_467 )
{
int V_119 = 0 ;
struct V_445 * V_446 = V_467 -> V_446 ;
T_11 * V_468 ;
T_14 * V_469 ;
enum V_459 V_479 ;
union V_460 V_79 ;
struct V_28 * V_28 ;
if ( F_423 ( V_464 , V_446 , & V_469 ) == 1 ) {
if ( V_136 . V_444 < V_287 ) {
F_110 ( V_469 ) ;
return 0 ;
}
V_479 = F_418 ( V_446 , V_447 , * V_464 , & V_79 ) ;
if ( V_479 == V_462 ) {
V_28 = V_79 . V_28 ;
if ( ! F_439 ( V_28 ) ) {
if ( ! F_404 ( V_28 , V_287 ,
V_136 . V_134 , V_136 . V_135 ) ) {
V_136 . V_444 -= V_287 ;
V_136 . V_474 += V_287 ;
}
F_440 ( V_28 ) ;
}
F_417 ( V_28 ) ;
}
F_110 ( V_469 ) ;
return 0 ;
}
if ( F_424 ( V_464 ) )
return 0 ;
V_55:
V_468 = F_425 ( V_446 -> V_470 , V_464 , V_447 , & V_469 ) ;
for (; V_447 != V_465 ; V_447 += V_320 ) {
T_11 V_448 = * ( V_468 ++ ) ;
T_4 V_261 ;
if ( ! V_136 . V_444 )
break;
switch ( F_413 ( V_446 , V_447 , V_448 , & V_79 ) ) {
case V_462 :
V_28 = V_79 . V_28 ;
if ( F_439 ( V_28 ) )
goto V_480;
if ( ! F_404 ( V_28 , 1 , V_136 . V_134 , V_136 . V_135 ) ) {
V_136 . V_444 -- ;
V_136 . V_474 ++ ;
}
F_440 ( V_28 ) ;
V_480:
F_417 ( V_28 ) ;
break;
case V_463 :
V_261 = V_79 . V_261 ;
if ( ! F_255 ( V_261 , V_136 . V_134 , V_136 . V_135 ) ) {
V_136 . V_444 -- ;
V_136 . V_475 ++ ;
}
break;
default:
break;
}
}
F_426 ( V_468 - 1 , V_469 ) ;
F_387 () ;
if ( V_447 != V_465 ) {
V_119 = F_386 ( 1 ) ;
if ( ! V_119 )
goto V_55;
}
return V_119 ;
}
static void F_441 ( struct V_94 * V_95 )
{
struct V_466 V_481 = {
. V_472 = F_438 ,
. V_95 = V_95 ,
} ;
F_266 () ;
F_80 ( & V_136 . V_134 -> V_213 ) ;
F_309 () ;
V_55:
if ( F_78 ( ! F_442 ( & V_95 -> V_473 ) ) ) {
F_430 () ;
F_387 () ;
goto V_55;
}
F_428 ( 0 , ~ 0UL , & V_481 ) ;
F_25 ( & V_95 -> V_473 ) ;
F_443 ( & V_136 . V_134 -> V_213 ) ;
}
static void F_444 ( struct V_4 * V_6 ,
struct V_476 * V_477 )
{
struct V_92 * V_38 = F_434 ( V_477 ) ;
struct V_94 * V_95 = F_435 ( V_38 ) ;
if ( V_95 ) {
if ( V_136 . V_135 )
F_441 ( V_95 ) ;
F_436 ( V_95 ) ;
}
if ( V_136 . V_135 )
F_432 () ;
}
static int F_433 ( struct V_4 * V_6 ,
struct V_476 * V_477 )
{
return 0 ;
}
static void F_437 ( struct V_4 * V_6 ,
struct V_476 * V_477 )
{
}
static void F_444 ( struct V_4 * V_6 ,
struct V_476 * V_477 )
{
}
static void F_445 ( struct V_4 * V_482 )
{
if ( F_31 ( V_482 -> V_29 ) )
V_8 -> V_105 = true ;
else
V_8 -> V_105 = false ;
}
static V_144 F_446 ( struct V_4 * V_6 ,
struct V_310 * V_311 )
{
return F_273 ( F_2 ( V_6 ) , false ) ;
}
static int F_447 ( struct V_333 * V_334 , void * V_335 )
{
struct V_1 * V_2 = F_2 ( F_291 ( V_334 ) ) ;
unsigned long V_443 = F_48 ( V_2 -> V_443 ) ;
if ( V_443 == V_329 )
F_448 ( V_334 , L_37 ) ;
else
F_293 ( V_334 , L_38 , ( V_144 ) V_443 * V_320 ) ;
return 0 ;
}
static T_5 F_449 ( struct V_305 * V_306 ,
char * V_307 , T_6 V_308 , T_7 V_309 )
{
struct V_1 * V_2 = F_2 ( F_269 ( V_306 ) ) ;
unsigned long V_443 ;
int V_268 ;
V_307 = F_283 ( V_307 ) ;
V_268 = F_284 ( V_307 , L_39 , & V_443 ) ;
if ( V_268 )
return V_268 ;
V_2 -> V_443 = V_443 ;
return V_308 ;
}
static int F_450 ( struct V_333 * V_334 , void * V_335 )
{
struct V_1 * V_2 = F_2 ( F_291 ( V_334 ) ) ;
unsigned long V_259 = F_48 ( V_2 -> V_259 ) ;
if ( V_259 == V_329 )
F_448 ( V_334 , L_37 ) ;
else
F_293 ( V_334 , L_38 , ( V_144 ) V_259 * V_320 ) ;
return 0 ;
}
static T_5 F_451 ( struct V_305 * V_306 ,
char * V_307 , T_6 V_308 , T_7 V_309 )
{
struct V_1 * V_2 = F_2 ( F_269 ( V_306 ) ) ;
unsigned long V_259 ;
int V_268 ;
V_307 = F_283 ( V_307 ) ;
V_268 = F_284 ( V_307 , L_39 , & V_259 ) ;
if ( V_268 )
return V_268 ;
V_2 -> V_259 = V_259 ;
F_337 ( V_2 ) ;
return V_308 ;
}
static int F_452 ( struct V_333 * V_334 , void * V_335 )
{
struct V_1 * V_2 = F_2 ( F_291 ( V_334 ) ) ;
unsigned long F_195 = F_48 ( V_2 -> V_50 . V_129 ) ;
if ( F_195 == V_329 )
F_448 ( V_334 , L_37 ) ;
else
F_293 ( V_334 , L_38 , ( V_144 ) F_195 * V_320 ) ;
return 0 ;
}
static T_5 F_453 ( struct V_305 * V_306 ,
char * V_307 , T_6 V_308 , T_7 V_309 )
{
struct V_1 * V_2 = F_2 ( F_269 ( V_306 ) ) ;
unsigned long F_195 ;
int V_268 ;
V_307 = F_283 ( V_307 ) ;
V_268 = F_284 ( V_307 , L_39 , & F_195 ) ;
if ( V_268 )
return V_268 ;
V_268 = F_257 ( V_2 , F_195 ) ;
if ( V_268 )
return V_268 ;
F_337 ( V_2 ) ;
return V_308 ;
}
static int F_454 ( struct V_333 * V_334 , void * V_335 )
{
struct V_1 * V_2 = F_2 ( F_291 ( V_334 ) ) ;
F_293 ( V_334 , L_40 , F_61 ( V_2 , V_483 ) ) ;
F_293 ( V_334 , L_41 , F_61 ( V_2 , V_260 ) ) ;
F_293 ( V_334 , L_42 , F_61 ( V_2 , V_252 ) ) ;
F_293 ( V_334 , L_43 , F_61 ( V_2 , V_256 ) ) ;
return 0 ;
}
void F_200 ( struct V_1 * V_2 ,
enum V_63 V_58 ,
unsigned int V_76 )
{
F_173 ( V_2 -> V_61 -> V_64 [ V_58 ] , V_76 ) ;
}
bool F_455 ( struct V_1 * V_97 , struct V_1 * V_2 )
{
if ( F_85 () )
return false ;
if ( V_2 == V_8 )
return false ;
if ( F_47 ( & V_2 -> V_50 ) >= V_2 -> V_443 )
return false ;
while ( V_2 != V_97 ) {
V_2 = F_50 ( V_2 ) ;
if ( V_2 == V_8 )
break;
if ( F_47 ( & V_2 -> V_50 ) >= V_2 -> V_443 )
return false ;
}
return true ;
}
int F_456 ( struct V_28 * V_28 , struct V_94 * V_95 ,
T_2 V_155 , struct V_1 * * V_484 )
{
struct V_1 * V_2 = NULL ;
unsigned int V_49 = 1 ;
int V_119 = 0 ;
if ( F_85 () )
goto V_106;
if ( F_208 ( V_28 ) ) {
if ( V_28 -> V_1 )
goto V_106;
}
if ( F_65 ( V_28 ) ) {
V_49 <<= F_457 ( V_28 ) ;
F_206 ( ! F_65 ( V_28 ) , V_28 ) ;
}
if ( V_130 && F_208 ( V_28 ) )
V_2 = F_205 ( V_28 ) ;
if ( ! V_2 )
V_2 = F_82 ( V_95 ) ;
V_119 = F_194 ( V_2 , V_155 , V_49 ) ;
F_20 ( & V_2 -> V_6 ) ;
if ( V_119 == - V_258 ) {
V_2 = V_8 ;
V_119 = 0 ;
}
V_106:
* V_484 = V_2 ;
return V_119 ;
}
void F_458 ( struct V_28 * V_28 , struct V_1 * V_2 ,
bool V_264 )
{
unsigned int V_49 = 1 ;
F_206 ( ! V_28 -> V_452 , V_28 ) ;
F_206 ( F_213 ( V_28 ) && ! V_264 , V_28 ) ;
if ( F_85 () )
return;
if ( ! V_2 )
return;
F_220 ( V_28 , V_2 , V_264 ) ;
if ( F_65 ( V_28 ) ) {
V_49 <<= F_457 ( V_28 ) ;
F_206 ( ! F_65 ( V_28 ) , V_28 ) ;
}
F_410 () ;
F_62 ( V_2 , V_28 , V_49 ) ;
F_77 ( V_2 , V_28 ) ;
F_411 () ;
if ( V_130 && F_208 ( V_28 ) ) {
T_4 V_289 = { . V_59 = F_209 (page) } ;
F_459 ( V_289 ) ;
}
}
void F_460 ( struct V_28 * V_28 , struct V_1 * V_2 )
{
unsigned int V_49 = 1 ;
if ( F_85 () )
return;
if ( ! V_2 )
return;
if ( F_65 ( V_28 ) ) {
V_49 <<= F_457 ( V_28 ) ;
F_206 ( ! F_65 ( V_28 ) , V_28 ) ;
}
F_204 ( V_2 , V_49 ) ;
}
static void F_461 ( struct V_1 * V_2 , unsigned long V_485 ,
unsigned long V_486 , unsigned long V_487 ,
unsigned long V_488 , struct V_28 * V_489 )
{
unsigned long V_49 = V_486 + V_487 ;
unsigned long V_47 ;
if ( ! F_6 ( V_2 ) ) {
F_178 ( & V_2 -> V_50 , V_49 ) ;
if ( V_130 )
F_178 ( & V_2 -> V_131 , V_49 ) ;
F_163 ( V_2 ) ;
}
F_462 ( V_47 ) ;
F_253 ( V_2 -> V_61 -> V_62 [ V_65 ] , V_486 ) ;
F_253 ( V_2 -> V_61 -> V_62 [ V_66 ] , V_487 ) ;
F_253 ( V_2 -> V_61 -> V_62 [ V_67 ] , V_488 ) ;
F_64 ( V_2 -> V_61 -> V_64 [ V_69 ] , V_485 ) ;
F_64 ( V_2 -> V_61 -> V_70 , V_49 ) ;
F_77 ( V_2 , V_489 ) ;
F_463 ( V_47 ) ;
if ( ! F_6 ( V_2 ) )
F_179 ( & V_2 -> V_6 , V_49 ) ;
}
static void F_464 ( struct V_380 * V_490 )
{
struct V_1 * V_2 = NULL ;
unsigned long V_486 = 0 ;
unsigned long V_487 = 0 ;
unsigned long V_488 = 0 ;
unsigned long V_485 = 0 ;
struct V_380 * V_80 ;
struct V_28 * V_28 ;
V_80 = V_490 -> V_80 ;
do {
unsigned int V_49 = 1 ;
V_28 = F_465 ( V_80 , struct V_28 , V_73 ) ;
V_80 = V_28 -> V_73 . V_80 ;
F_206 ( F_213 ( V_28 ) , V_28 ) ;
F_206 ( F_466 ( V_28 ) , V_28 ) ;
if ( ! V_28 -> V_1 )
continue;
if ( V_2 != V_28 -> V_1 ) {
if ( V_2 ) {
F_461 ( V_2 , V_485 , V_486 , V_487 ,
V_488 , V_28 ) ;
V_485 = V_486 = V_487 = V_488 = 0 ;
}
V_2 = V_28 -> V_1 ;
}
if ( F_65 ( V_28 ) ) {
V_49 <<= F_457 ( V_28 ) ;
F_206 ( ! F_65 ( V_28 ) , V_28 ) ;
V_488 += V_49 ;
}
if ( F_63 ( V_28 ) )
V_486 += V_49 ;
else
V_487 += V_49 ;
V_28 -> V_1 = NULL ;
V_485 ++ ;
} while ( V_80 != V_490 );
if ( V_2 )
F_461 ( V_2 , V_485 , V_486 , V_487 ,
V_488 , V_28 ) ;
}
void F_467 ( struct V_28 * V_28 )
{
if ( F_85 () )
return;
if ( ! V_28 -> V_1 )
return;
F_167 ( & V_28 -> V_73 ) ;
F_464 ( & V_28 -> V_73 ) ;
}
void F_468 ( struct V_380 * V_490 )
{
if ( F_85 () )
return;
if ( ! F_345 ( V_490 ) )
F_464 ( V_490 ) ;
}
void F_469 ( struct V_28 * V_491 , struct V_28 * V_492 ,
bool V_264 )
{
struct V_1 * V_2 ;
int V_262 ;
F_206 ( ! F_207 ( V_491 ) , V_491 ) ;
F_206 ( ! F_207 ( V_492 ) , V_492 ) ;
F_206 ( ! V_264 && F_213 ( V_491 ) , V_491 ) ;
F_206 ( ! V_264 && F_213 ( V_492 ) , V_492 ) ;
F_206 ( F_63 ( V_491 ) != F_63 ( V_492 ) , V_492 ) ;
F_206 ( F_65 ( V_491 ) != F_65 ( V_492 ) ,
V_492 ) ;
if ( F_85 () )
return;
if ( V_492 -> V_1 )
return;
V_2 = V_491 -> V_1 ;
if ( ! V_2 )
return;
if ( V_264 )
F_211 ( V_491 , & V_262 ) ;
V_491 -> V_1 = NULL ;
if ( V_264 )
F_217 ( V_491 , V_262 ) ;
F_220 ( V_492 , V_2 , V_264 ) ;
}
static int T_15 F_470 ( void )
{
int V_60 , V_177 ;
F_471 ( F_193 , 0 ) ;
F_59 (cpu)
F_238 ( & F_472 ( & V_220 , V_60 ) -> V_228 ,
F_180 ) ;
F_52 (node) {
struct V_493 * V_494 ;
int V_23 ;
V_494 = F_364 ( sizeof( * V_494 ) , V_271 ,
F_473 ( V_177 ) ? V_177 : V_495 ) ;
for ( V_23 = 0 ; V_23 < V_53 ; V_23 ++ ) {
struct V_30 * V_496 ;
V_496 = & V_494 -> V_33 [ V_23 ] ;
V_496 -> V_39 = V_497 ;
F_369 ( & V_496 -> V_48 ) ;
}
V_31 . V_32 [ V_177 ] = V_494 ;
}
return 0 ;
}
void F_474 ( struct V_28 * V_28 , T_4 V_289 )
{
struct V_1 * V_2 ;
unsigned short V_498 ;
F_206 ( F_213 ( V_28 ) , V_28 ) ;
F_206 ( F_466 ( V_28 ) , V_28 ) ;
if ( ! V_130 )
return;
V_2 = V_28 -> V_1 ;
if ( ! V_2 )
return;
V_498 = F_475 ( V_289 , F_7 ( V_2 ) ) ;
F_206 ( V_498 , V_28 ) ;
F_254 ( V_2 , true ) ;
V_28 -> V_1 = NULL ;
if ( ! F_6 ( V_2 ) )
F_178 ( & V_2 -> V_50 , 1 ) ;
F_62 ( V_2 , V_28 , - 1 ) ;
F_77 ( V_2 , V_28 ) ;
}
void F_459 ( T_4 V_289 )
{
struct V_1 * V_2 ;
unsigned short V_10 ;
if ( ! V_130 )
return;
V_10 = F_475 ( V_289 , 0 ) ;
F_13 () ;
V_2 = F_8 ( V_10 ) ;
if ( V_2 ) {
if ( ! F_6 ( V_2 ) )
F_178 ( & V_2 -> V_131 , 1 ) ;
F_254 ( V_2 , false ) ;
F_20 ( & V_2 -> V_6 ) ;
}
F_17 () ;
}
static int T_15 F_476 ( char * V_5 )
{
if ( ! strcmp ( V_5 , L_44 ) )
V_499 = 1 ;
else if ( ! strcmp ( V_5 , L_45 ) )
V_499 = 0 ;
return 1 ;
}
static int T_15 F_477 ( void )
{
if ( ! F_85 () && V_499 ) {
V_130 = 1 ;
F_19 ( F_478 ( & V_11 ,
V_500 ) ) ;
}
return 0 ;
}
