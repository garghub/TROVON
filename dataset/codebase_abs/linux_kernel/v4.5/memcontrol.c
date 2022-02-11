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
static inline unsigned short F_7 ( struct V_4 * V_5 )
{
return V_5 -> V_9 . V_10 ;
}
static inline struct V_4 * F_8 ( unsigned short V_10 )
{
struct V_7 * V_9 ;
V_9 = F_9 ( V_10 , & V_1 ) ;
return F_10 ( V_9 ) ;
}
void F_11 ( void )
{
F_12 ( & V_11 ) ;
}
void F_13 ( void )
{
F_14 ( & V_11 ) ;
}
static struct V_12 *
F_15 ( struct V_4 * V_5 , struct V_13 * V_13 )
{
int V_14 = F_16 ( V_13 ) ;
int V_15 = F_17 ( V_13 ) ;
return & V_5 -> V_16 [ V_14 ] -> V_17 [ V_15 ] ;
}
struct V_7 * F_18 ( struct V_18 * V_18 )
{
struct V_4 * V_5 ;
V_5 = V_18 -> V_4 ;
if ( ! V_5 || ! F_2 ( V_1 ) )
V_5 = V_6 ;
return & V_5 -> V_9 ;
}
T_1 F_19 ( struct V_18 * V_18 )
{
struct V_4 * V_5 ;
unsigned long V_19 = 0 ;
F_20 () ;
V_5 = F_21 ( V_18 -> V_4 ) ;
while ( V_5 && ! ( V_5 -> V_9 . V_20 & V_21 ) )
V_5 = F_22 ( V_5 ) ;
if ( V_5 )
V_19 = F_23 ( V_5 -> V_9 . V_22 ) ;
F_24 () ;
return V_19 ;
}
static struct V_12 *
F_25 ( struct V_4 * V_5 , struct V_18 * V_18 )
{
int V_14 = F_26 ( V_18 ) ;
int V_15 = F_27 ( V_18 ) ;
return & V_5 -> V_16 [ V_14 ] -> V_17 [ V_15 ] ;
}
static struct V_23 *
F_28 ( int V_14 , int V_15 )
{
return & V_24 . V_25 [ V_14 ] -> V_26 [ V_15 ] ;
}
static struct V_23 *
F_29 ( struct V_18 * V_18 )
{
int V_14 = F_26 ( V_18 ) ;
int V_15 = F_27 ( V_18 ) ;
return & V_24 . V_25 [ V_14 ] -> V_26 [ V_15 ] ;
}
static void F_30 ( struct V_12 * V_27 ,
struct V_23 * V_28 ,
unsigned long V_29 )
{
struct V_30 * * V_31 = & V_28 -> V_32 . V_30 ;
struct V_30 * V_33 = NULL ;
struct V_12 * V_34 ;
if ( V_27 -> V_35 )
return;
V_27 -> V_36 = V_29 ;
if ( ! V_27 -> V_36 )
return;
while ( * V_31 ) {
V_33 = * V_31 ;
V_34 = F_31 ( V_33 , struct V_12 ,
V_37 ) ;
if ( V_27 -> V_36 < V_34 -> V_36 )
V_31 = & ( * V_31 ) -> V_38 ;
else if ( V_27 -> V_36 >= V_34 -> V_36 )
V_31 = & ( * V_31 ) -> V_39 ;
}
F_32 ( & V_27 -> V_37 , V_33 , V_31 ) ;
F_33 ( & V_27 -> V_37 , & V_28 -> V_32 ) ;
V_27 -> V_35 = true ;
}
static void F_34 ( struct V_12 * V_27 ,
struct V_23 * V_28 )
{
if ( ! V_27 -> V_35 )
return;
F_35 ( & V_27 -> V_37 , & V_28 -> V_32 ) ;
V_27 -> V_35 = false ;
}
static void F_36 ( struct V_12 * V_27 ,
struct V_23 * V_28 )
{
unsigned long V_20 ;
F_37 ( & V_28 -> V_40 , V_20 ) ;
F_34 ( V_27 , V_28 ) ;
F_38 ( & V_28 -> V_40 , V_20 ) ;
}
static unsigned long F_39 ( struct V_4 * V_5 )
{
unsigned long V_41 = F_40 ( & V_5 -> V_42 ) ;
unsigned long V_43 = F_21 ( V_5 -> V_43 ) ;
unsigned long V_44 = 0 ;
if ( V_41 > V_43 )
V_44 = V_41 - V_43 ;
return V_44 ;
}
static void F_41 ( struct V_4 * V_5 , struct V_18 * V_18 )
{
unsigned long V_44 ;
struct V_12 * V_27 ;
struct V_23 * V_28 ;
V_28 = F_29 ( V_18 ) ;
for (; V_5 ; V_5 = F_22 ( V_5 ) ) {
V_27 = F_25 ( V_5 , V_18 ) ;
V_44 = F_39 ( V_5 ) ;
if ( V_44 || V_27 -> V_35 ) {
unsigned long V_20 ;
F_37 ( & V_28 -> V_40 , V_20 ) ;
if ( V_27 -> V_35 )
F_34 ( V_27 , V_28 ) ;
F_30 ( V_27 , V_28 , V_44 ) ;
F_38 ( & V_28 -> V_40 , V_20 ) ;
}
}
}
static void F_42 ( struct V_4 * V_5 )
{
struct V_23 * V_28 ;
struct V_12 * V_27 ;
int V_14 , V_15 ;
F_43 (nid) {
for ( V_15 = 0 ; V_15 < V_45 ; V_15 ++ ) {
V_27 = & V_5 -> V_16 [ V_14 ] -> V_17 [ V_15 ] ;
V_28 = F_28 ( V_14 , V_15 ) ;
F_36 ( V_27 , V_28 ) ;
}
}
}
static struct V_12 *
F_44 ( struct V_23 * V_28 )
{
struct V_30 * V_46 = NULL ;
struct V_12 * V_27 ;
V_47:
V_27 = NULL ;
V_46 = F_45 ( & V_28 -> V_32 ) ;
if ( ! V_46 )
goto V_48;
V_27 = F_31 ( V_46 , struct V_12 , V_37 ) ;
F_34 ( V_27 , V_28 ) ;
if ( ! F_39 ( V_27 -> V_5 ) ||
! F_46 ( & V_27 -> V_5 -> V_9 ) )
goto V_47;
V_48:
return V_27 ;
}
static struct V_12 *
F_47 ( struct V_23 * V_28 )
{
struct V_12 * V_27 ;
F_48 ( & V_28 -> V_40 ) ;
V_27 = F_44 ( V_28 ) ;
F_49 ( & V_28 -> V_40 ) ;
return V_27 ;
}
static unsigned long
F_50 ( struct V_4 * V_5 , enum V_49 V_50 )
{
long V_51 = 0 ;
int V_52 ;
F_51 (cpu)
V_51 += F_52 ( V_5 -> V_53 -> V_54 [ V_50 ] , V_52 ) ;
if ( V_51 < 0 )
V_51 = 0 ;
return V_51 ;
}
static unsigned long F_53 ( struct V_4 * V_5 ,
enum V_55 V_50 )
{
unsigned long V_51 = 0 ;
int V_52 ;
F_51 (cpu)
V_51 += F_52 ( V_5 -> V_53 -> V_56 [ V_50 ] , V_52 ) ;
return V_51 ;
}
static void F_54 ( struct V_4 * V_5 ,
struct V_18 * V_18 ,
bool V_57 , int V_41 )
{
if ( F_55 ( V_18 ) )
F_56 ( V_5 -> V_53 -> V_54 [ V_58 ] ,
V_41 ) ;
else
F_56 ( V_5 -> V_53 -> V_54 [ V_59 ] ,
V_41 ) ;
if ( V_57 ) {
F_57 ( ! F_58 ( V_18 ) , V_18 ) ;
F_56 ( V_5 -> V_53 -> V_54 [ V_60 ] ,
V_41 ) ;
}
if ( V_41 > 0 )
F_59 ( V_5 -> V_53 -> V_56 [ V_61 ] ) ;
else {
F_59 ( V_5 -> V_53 -> V_56 [ V_62 ] ) ;
V_41 = - V_41 ;
}
F_56 ( V_5 -> V_53 -> V_63 , V_41 ) ;
}
static unsigned long F_60 ( struct V_4 * V_5 ,
int V_14 ,
unsigned int V_64 )
{
unsigned long V_65 = 0 ;
int V_15 ;
F_61 ( ( unsigned ) V_14 >= V_66 ) ;
for ( V_15 = 0 ; V_15 < V_45 ; V_15 ++ ) {
struct V_12 * V_27 ;
enum V_67 V_68 ;
F_62 (lru) {
if ( ! ( F_63 ( V_68 ) & V_64 ) )
continue;
V_27 = & V_5 -> V_16 [ V_14 ] -> V_17 [ V_15 ] ;
V_65 += V_27 -> V_69 [ V_68 ] ;
}
}
return V_65 ;
}
static unsigned long F_64 ( struct V_4 * V_5 ,
unsigned int V_64 )
{
unsigned long V_65 = 0 ;
int V_14 ;
F_65 (nid, N_MEMORY)
V_65 += F_60 ( V_5 , V_14 , V_64 ) ;
return V_65 ;
}
static bool F_66 ( struct V_4 * V_5 ,
enum V_70 V_71 )
{
unsigned long V_51 , V_72 ;
V_51 = F_67 ( V_5 -> V_53 -> V_63 ) ;
V_72 = F_67 ( V_5 -> V_53 -> V_73 [ V_71 ] ) ;
if ( ( long ) V_72 - ( long ) V_51 < 0 ) {
switch ( V_71 ) {
case V_74 :
V_72 = V_51 + V_75 ;
break;
case V_76 :
V_72 = V_51 + V_77 ;
break;
case V_78 :
V_72 = V_51 + V_79 ;
break;
default:
break;
}
F_68 ( V_5 -> V_53 -> V_73 [ V_71 ] , V_72 ) ;
return true ;
}
return false ;
}
static void F_69 ( struct V_4 * V_5 , struct V_18 * V_18 )
{
if ( F_70 ( F_66 ( V_5 ,
V_74 ) ) ) {
bool V_80 ;
bool T_2 V_81 ;
V_80 = F_66 ( V_5 ,
V_76 ) ;
#if V_82 > 1
T_2 = F_66 ( V_5 ,
V_78 ) ;
#endif
F_71 ( V_5 ) ;
if ( F_70 ( V_80 ) )
F_41 ( V_5 , V_18 ) ;
#if V_82 > 1
if ( F_70 ( T_2 ) )
F_72 ( & V_5 -> V_83 ) ;
#endif
}
}
struct V_4 * F_73 ( struct V_84 * V_31 )
{
if ( F_70 ( ! V_31 ) )
return NULL ;
return F_10 ( F_74 ( V_31 , V_85 ) ) ;
}
static struct V_4 * F_75 ( struct V_86 * V_87 )
{
struct V_4 * V_5 = NULL ;
F_20 () ;
do {
if ( F_70 ( ! V_87 ) )
V_5 = V_6 ;
else {
V_5 = F_73 ( F_76 ( V_87 -> V_88 ) ) ;
if ( F_70 ( ! V_5 ) )
V_5 = V_6 ;
}
} while ( ! F_46 ( & V_5 -> V_9 ) );
F_24 () ;
return V_5 ;
}
struct V_4 * F_77 ( struct V_4 * V_89 ,
struct V_4 * V_90 ,
struct V_91 * V_92 )
{
struct V_93 * V_94 ( V_95 ) ;
struct V_7 * V_9 = NULL ;
struct V_4 * V_5 = NULL ;
struct V_4 * V_96 = NULL ;
if ( F_78 () )
return NULL ;
if ( ! V_89 )
V_89 = V_6 ;
if ( V_90 && ! V_92 )
V_96 = V_90 ;
if ( ! V_89 -> V_97 && V_89 != V_6 ) {
if ( V_90 )
goto V_98;
return V_89 ;
}
F_20 () ;
if ( V_92 ) {
struct V_12 * V_27 ;
V_27 = F_15 ( V_89 , V_92 -> V_13 ) ;
V_95 = & V_27 -> V_95 [ V_92 -> V_99 ] ;
if ( V_90 && V_92 -> V_100 != V_95 -> V_100 )
goto V_101;
while ( 1 ) {
V_96 = F_21 ( V_95 -> V_102 ) ;
if ( ! V_96 || F_79 ( & V_96 -> V_9 ) )
break;
( void ) F_80 ( & V_95 -> V_102 , V_96 , NULL ) ;
}
}
if ( V_96 )
V_9 = & V_96 -> V_9 ;
for (; ; ) {
V_9 = F_81 ( V_9 , & V_89 -> V_9 ) ;
if ( ! V_9 ) {
if ( ! V_90 )
continue;
break;
}
V_5 = F_10 ( V_9 ) ;
if ( V_9 == & V_89 -> V_9 )
break;
if ( F_79 ( V_9 ) )
break;
V_5 = NULL ;
}
if ( V_92 ) {
( void ) F_80 ( & V_95 -> V_102 , V_96 , V_5 ) ;
if ( V_96 )
F_82 ( & V_96 -> V_9 ) ;
if ( ! V_5 )
V_95 -> V_100 ++ ;
else if ( ! V_90 )
V_92 -> V_100 = V_95 -> V_100 ;
}
V_101:
F_24 () ;
V_98:
if ( V_90 && V_90 != V_89 )
F_82 ( & V_90 -> V_9 ) ;
return V_5 ;
}
void F_83 ( struct V_4 * V_89 ,
struct V_4 * V_90 )
{
if ( ! V_89 )
V_89 = V_6 ;
if ( V_90 && V_90 != V_89 )
F_82 ( & V_90 -> V_9 ) ;
}
static void F_84 ( struct V_4 * V_103 )
{
struct V_4 * V_5 = V_103 ;
struct V_93 * V_95 ;
struct V_12 * V_27 ;
int V_14 , V_15 ;
int V_104 ;
while ( ( V_5 = F_22 ( V_5 ) ) ) {
F_43 (nid) {
for ( V_15 = 0 ; V_15 < V_45 ; V_15 ++ ) {
V_27 = & V_5 -> V_16 [ V_14 ] -> V_17 [ V_15 ] ;
for ( V_104 = 0 ; V_104 <= V_105 ; V_104 ++ ) {
V_95 = & V_27 -> V_95 [ V_104 ] ;
F_80 ( & V_95 -> V_102 ,
V_103 , NULL ) ;
}
}
}
}
}
struct V_106 * F_85 ( struct V_13 * V_13 ,
struct V_4 * V_5 )
{
struct V_12 * V_27 ;
struct V_106 * V_106 ;
if ( F_78 () ) {
V_106 = & V_13 -> V_106 ;
goto V_98;
}
V_27 = F_15 ( V_5 , V_13 ) ;
V_106 = & V_27 -> V_106 ;
V_98:
if ( F_70 ( V_106 -> V_13 != V_13 ) )
V_106 -> V_13 = V_13 ;
return V_106 ;
}
struct V_106 * F_86 ( struct V_18 * V_18 , struct V_13 * V_13 )
{
struct V_12 * V_27 ;
struct V_4 * V_5 ;
struct V_106 * V_106 ;
if ( F_78 () ) {
V_106 = & V_13 -> V_106 ;
goto V_98;
}
V_5 = V_18 -> V_4 ;
if ( ! V_5 )
V_5 = V_6 ;
V_27 = F_25 ( V_5 , V_18 ) ;
V_106 = & V_27 -> V_106 ;
V_98:
if ( F_70 ( V_106 -> V_13 != V_13 ) )
V_106 -> V_13 = V_13 ;
return V_106 ;
}
void F_87 ( struct V_106 * V_106 , enum V_67 V_68 ,
int V_41 )
{
struct V_12 * V_27 ;
unsigned long * V_69 ;
if ( F_78 () )
return;
V_27 = F_5 ( V_106 , struct V_12 , V_106 ) ;
V_69 = V_27 -> V_69 + V_68 ;
* V_69 += V_41 ;
F_61 ( ( long ) ( * V_69 ) < 0 ) ;
}
bool F_88 ( struct V_84 * V_107 , struct V_4 * V_5 )
{
struct V_4 * V_108 ;
struct V_84 * V_31 ;
bool V_109 ;
V_31 = F_89 ( V_107 ) ;
if ( V_31 ) {
V_108 = F_75 ( V_31 -> V_87 ) ;
F_90 ( V_31 ) ;
} else {
F_20 () ;
V_108 = F_73 ( V_107 ) ;
F_91 ( & V_108 -> V_9 ) ;
F_24 () ;
}
V_109 = F_92 ( V_108 , V_5 ) ;
F_82 ( & V_108 -> V_9 ) ;
return V_109 ;
}
static unsigned long F_93 ( struct V_4 * V_5 )
{
unsigned long V_110 = 0 ;
unsigned long V_54 ;
unsigned long V_111 ;
V_54 = F_40 ( & V_5 -> V_42 ) ;
V_111 = F_21 ( V_5 -> V_42 . V_111 ) ;
if ( V_54 < V_111 )
V_110 = V_111 - V_54 ;
if ( F_1 () ) {
V_54 = F_40 ( & V_5 -> V_112 ) ;
V_111 = F_21 ( V_5 -> V_112 . V_111 ) ;
if ( V_54 <= V_111 )
V_110 = F_94 ( V_110 , V_111 - V_54 ) ;
}
return V_110 ;
}
static bool F_95 ( struct V_4 * V_5 )
{
struct V_4 * V_113 ;
struct V_4 * V_114 ;
bool V_109 = false ;
F_96 ( & V_115 . V_40 ) ;
V_113 = V_115 . V_113 ;
V_114 = V_115 . V_114 ;
if ( ! V_113 )
goto V_116;
V_109 = F_92 ( V_113 , V_5 ) ||
F_92 ( V_114 , V_5 ) ;
V_116:
F_97 ( & V_115 . V_40 ) ;
return V_109 ;
}
static bool F_98 ( struct V_4 * V_5 )
{
if ( V_115 . V_117 && V_118 != V_115 . V_117 ) {
if ( F_95 ( V_5 ) ) {
F_99 ( V_119 ) ;
F_100 ( & V_115 . V_120 , & V_119 , V_121 ) ;
if ( V_115 . V_117 )
F_101 () ;
F_102 ( & V_115 . V_120 , & V_119 ) ;
return true ;
}
}
return false ;
}
void F_103 ( struct V_4 * V_5 , struct V_84 * V_31 )
{
static F_104 ( V_122 ) ;
struct V_4 * V_95 ;
unsigned int V_104 ;
F_105 ( & V_122 ) ;
F_20 () ;
if ( V_31 ) {
F_106 ( L_1 ) ;
F_107 ( F_108 ( V_31 , V_85 ) ) ;
F_109 ( L_2 ) ;
} else {
F_106 ( L_3 ) ;
}
F_107 ( V_5 -> V_9 . V_22 ) ;
F_109 ( L_4 ) ;
F_24 () ;
F_106 ( L_5 ,
F_110 ( ( V_123 ) F_40 ( & V_5 -> V_42 ) ) ,
F_110 ( ( V_123 ) V_5 -> V_42 . V_111 ) , V_5 -> V_42 . V_124 ) ;
F_106 ( L_6 ,
F_110 ( ( V_123 ) F_40 ( & V_5 -> V_112 ) ) ,
F_110 ( ( V_123 ) V_5 -> V_112 . V_111 ) , V_5 -> V_112 . V_124 ) ;
F_106 ( L_7 ,
F_110 ( ( V_123 ) F_40 ( & V_5 -> V_125 ) ) ,
F_110 ( ( V_123 ) V_5 -> V_125 . V_111 ) , V_5 -> V_125 . V_124 ) ;
F_111 (iter, memcg) {
F_106 ( L_8 ) ;
F_107 ( V_95 -> V_9 . V_22 ) ;
F_109 ( L_9 ) ;
for ( V_104 = 0 ; V_104 < V_126 ; V_104 ++ ) {
if ( V_104 == V_127 && ! V_2 )
continue;
F_109 ( L_10 , V_128 [ V_104 ] ,
F_110 ( F_50 ( V_95 , V_104 ) ) ) ;
}
for ( V_104 = 0 ; V_104 < V_129 ; V_104 ++ )
F_109 ( L_10 , V_130 [ V_104 ] ,
F_110 ( F_64 ( V_95 , F_63 ( V_104 ) ) ) ) ;
F_109 ( L_4 ) ;
}
F_112 ( & V_122 ) ;
}
static int F_113 ( struct V_4 * V_5 )
{
int V_131 = 0 ;
struct V_4 * V_95 ;
F_111 (iter, memcg)
V_131 ++ ;
return V_131 ;
}
static unsigned long F_114 ( struct V_4 * V_5 )
{
unsigned long V_111 ;
V_111 = V_5 -> V_42 . V_111 ;
if ( F_115 ( V_5 ) ) {
unsigned long V_132 ;
unsigned long V_133 ;
V_132 = V_5 -> V_112 . V_111 ;
V_133 = V_5 -> V_134 . V_111 ;
V_133 = F_94 ( V_133 , ( unsigned long ) V_135 ) ;
V_111 = F_94 ( V_111 + V_133 , V_132 ) ;
}
return V_111 ;
}
static void F_116 ( struct V_4 * V_5 , T_3 V_136 ,
int V_137 )
{
struct V_138 V_139 = {
. V_140 = NULL ,
. V_141 = NULL ,
. V_136 = V_136 ,
. V_137 = V_137 ,
} ;
struct V_4 * V_95 ;
unsigned long V_142 = 0 ;
unsigned long V_143 ;
unsigned int V_144 = 0 ;
struct V_84 * V_145 = NULL ;
F_105 ( & V_146 ) ;
if ( F_117 ( V_118 ) || F_118 ( V_118 ) ) {
F_119 ( V_118 ) ;
goto V_116;
}
F_120 ( & V_139 , V_147 , V_5 ) ;
V_143 = F_114 ( V_5 ) ? : 1 ;
F_111 (iter, memcg) {
struct V_148 V_149 ;
struct V_84 * V_107 ;
F_121 ( & V_95 -> V_9 , & V_149 ) ;
while ( ( V_107 = F_122 ( & V_149 ) ) ) {
switch ( F_123 ( & V_139 , V_107 , V_143 ) ) {
case V_150 :
if ( V_145 )
F_124 ( V_145 ) ;
V_145 = V_107 ;
V_142 = V_151 ;
F_125 ( V_145 ) ;
case V_152 :
continue;
case V_153 :
F_126 ( & V_149 ) ;
F_83 ( V_5 , V_95 ) ;
if ( V_145 )
F_124 ( V_145 ) ;
goto V_116;
case V_154 :
break;
} ;
V_144 = F_127 ( V_107 , V_5 , NULL , V_143 ) ;
if ( ! V_144 || V_144 < V_142 )
continue;
if ( V_144 == V_142 &&
F_128 ( V_145 ) )
continue;
if ( V_145 )
F_124 ( V_145 ) ;
V_145 = V_107 ;
V_142 = V_144 ;
F_125 ( V_145 ) ;
}
F_126 ( & V_149 ) ;
}
if ( V_145 ) {
V_144 = V_142 * 1000 / V_143 ;
F_129 ( & V_139 , V_145 , V_144 , V_143 , V_5 ,
L_11 ) ;
}
V_116:
F_112 ( & V_146 ) ;
}
static bool F_130 ( struct V_4 * V_5 ,
int V_14 , bool V_155 )
{
if ( F_60 ( V_5 , V_14 , V_156 ) )
return true ;
if ( V_155 || ! V_135 )
return false ;
if ( F_60 ( V_5 , V_14 , V_157 ) )
return true ;
return false ;
}
static void F_131 ( struct V_4 * V_5 )
{
int V_14 ;
if ( ! F_132 ( & V_5 -> V_83 ) )
return;
if ( F_133 ( & V_5 -> V_158 ) > 1 )
return;
V_5 -> V_159 = V_160 [ V_161 ] ;
F_134 (nid, node_states[N_MEMORY]) {
if ( ! F_130 ( V_5 , V_14 , false ) )
F_135 ( V_14 , V_5 -> V_159 ) ;
}
F_136 ( & V_5 -> V_83 , 0 ) ;
F_136 ( & V_5 -> V_158 , 0 ) ;
}
int F_137 ( struct V_4 * V_5 )
{
int V_162 ;
F_131 ( V_5 ) ;
V_162 = V_5 -> V_163 ;
V_162 = F_138 ( V_162 , V_5 -> V_159 ) ;
if ( V_162 == V_82 )
V_162 = F_139 ( V_5 -> V_159 ) ;
if ( F_70 ( V_162 == V_82 ) )
V_162 = F_140 () ;
V_5 -> V_163 = V_162 ;
return V_162 ;
}
int F_137 ( struct V_4 * V_5 )
{
return 0 ;
}
static int F_141 ( struct V_4 * V_164 ,
struct V_13 * V_13 ,
T_3 V_136 ,
unsigned long * V_165 )
{
struct V_4 * V_166 = NULL ;
int V_167 = 0 ;
int V_168 = 0 ;
unsigned long V_44 ;
unsigned long V_169 ;
struct V_91 V_92 = {
. V_13 = V_13 ,
. V_99 = 0 ,
} ;
V_44 = F_39 ( V_164 ) ;
while ( 1 ) {
V_166 = F_77 ( V_164 , V_166 , & V_92 ) ;
if ( ! V_166 ) {
V_168 ++ ;
if ( V_168 >= 2 ) {
if ( ! V_167 )
break;
if ( V_167 >= ( V_44 >> 2 ) ||
( V_168 > V_170 ) )
break;
}
continue;
}
V_167 += F_142 ( V_166 , V_136 , false ,
V_13 , & V_169 ) ;
* V_165 += V_169 ;
if ( ! F_39 ( V_164 ) )
break;
}
F_83 ( V_164 , V_166 ) ;
return V_167 ;
}
static bool F_143 ( struct V_4 * V_5 )
{
struct V_4 * V_95 , * V_171 = NULL ;
F_96 ( & V_172 ) ;
F_111 (iter, memcg) {
if ( V_95 -> V_146 ) {
V_171 = V_95 ;
F_83 ( V_5 , V_95 ) ;
break;
} else
V_95 -> V_146 = true ;
}
if ( V_171 ) {
F_111 (iter, memcg) {
if ( V_95 == V_171 ) {
F_83 ( V_5 , V_95 ) ;
break;
}
V_95 -> V_146 = false ;
}
} else
F_144 ( & V_173 , 0 , 1 , V_174 ) ;
F_97 ( & V_172 ) ;
return ! V_171 ;
}
static void F_145 ( struct V_4 * V_5 )
{
struct V_4 * V_95 ;
F_96 ( & V_172 ) ;
F_146 ( & V_173 , 1 , V_174 ) ;
F_111 (iter, memcg)
V_95 -> V_146 = false ;
F_97 ( & V_172 ) ;
}
static void F_147 ( struct V_4 * V_5 )
{
struct V_4 * V_95 ;
F_96 ( & V_172 ) ;
F_111 (iter, memcg)
V_95 -> V_175 ++ ;
F_97 ( & V_172 ) ;
}
static void F_148 ( struct V_4 * V_5 )
{
struct V_4 * V_95 ;
F_96 ( & V_172 ) ;
F_111 (iter, memcg)
if ( V_95 -> V_175 > 0 )
V_95 -> V_175 -- ;
F_97 ( & V_172 ) ;
}
static int F_149 ( T_4 * V_119 ,
unsigned V_176 , int V_177 , void * V_178 )
{
struct V_4 * V_179 = (struct V_4 * ) V_178 ;
struct V_4 * V_180 ;
struct V_181 * V_181 ;
V_181 = F_5 ( V_119 , struct V_181 , V_119 ) ;
V_180 = V_181 -> V_5 ;
if ( ! F_92 ( V_179 , V_180 ) &&
! F_92 ( V_180 , V_179 ) )
return 0 ;
return F_150 ( V_119 , V_176 , V_177 , V_178 ) ;
}
static void F_151 ( struct V_4 * V_5 )
{
if ( V_5 && V_5 -> V_175 )
F_152 ( & V_182 , V_183 , 0 , V_5 ) ;
}
static void F_153 ( struct V_4 * V_5 , T_3 V_184 , int V_137 )
{
if ( ! V_118 -> V_185 )
return;
F_91 ( & V_5 -> V_9 ) ;
V_118 -> V_186 = V_5 ;
V_118 -> V_187 = V_184 ;
V_118 -> V_188 = V_137 ;
}
bool F_154 ( bool V_189 )
{
struct V_4 * V_5 = V_118 -> V_186 ;
struct V_181 V_190 ;
bool V_191 ;
if ( ! V_5 )
return false ;
if ( ! V_189 || V_192 )
goto V_193;
V_190 . V_5 = V_5 ;
V_190 . V_119 . V_20 = 0 ;
V_190 . V_119 . V_194 = F_149 ;
V_190 . V_119 . V_195 = V_118 ;
F_155 ( & V_190 . V_119 . V_196 ) ;
F_100 ( & V_182 , & V_190 . V_119 , V_197 ) ;
F_147 ( V_5 ) ;
V_191 = F_143 ( V_5 ) ;
if ( V_191 )
F_156 ( V_5 ) ;
if ( V_191 && ! V_5 -> V_198 ) {
F_148 ( V_5 ) ;
F_102 ( & V_182 , & V_190 . V_119 ) ;
F_116 ( V_5 , V_118 -> V_187 ,
V_118 -> V_188 ) ;
} else {
F_101 () ;
F_148 ( V_5 ) ;
F_102 ( & V_182 , & V_190 . V_119 ) ;
}
if ( V_191 ) {
F_145 ( V_5 ) ;
F_151 ( V_5 ) ;
}
V_193:
V_118 -> V_186 = NULL ;
F_82 ( & V_5 -> V_9 ) ;
return true ;
}
struct V_4 * F_157 ( struct V_18 * V_18 )
{
struct V_4 * V_5 ;
unsigned long V_20 ;
F_20 () ;
if ( F_78 () )
return NULL ;
V_199:
V_5 = V_18 -> V_4 ;
if ( F_70 ( ! V_5 ) )
return NULL ;
if ( F_132 ( & V_5 -> V_200 ) <= 0 )
return V_5 ;
F_37 ( & V_5 -> V_201 , V_20 ) ;
if ( V_5 != V_18 -> V_4 ) {
F_38 ( & V_5 -> V_201 , V_20 ) ;
goto V_199;
}
V_5 -> V_202 = V_118 ;
V_5 -> V_203 = V_20 ;
return V_5 ;
}
void F_158 ( struct V_4 * V_5 )
{
if ( V_5 && V_5 -> V_202 == V_118 ) {
unsigned long V_20 = V_5 -> V_203 ;
V_5 -> V_202 = NULL ;
V_5 -> V_203 = 0 ;
F_38 ( & V_5 -> V_201 , V_20 ) ;
}
F_24 () ;
}
static bool F_159 ( struct V_4 * V_5 , unsigned int V_41 )
{
struct V_204 * V_205 ;
bool V_109 = false ;
if ( V_41 > V_206 )
return V_109 ;
V_205 = & F_160 ( V_207 ) ;
if ( V_5 == V_205 -> V_208 && V_205 -> V_41 >= V_41 ) {
V_205 -> V_41 -= V_41 ;
V_109 = true ;
}
F_161 ( V_207 ) ;
return V_109 ;
}
static void F_162 ( struct V_204 * V_205 )
{
struct V_4 * V_209 = V_205 -> V_208 ;
if ( V_205 -> V_41 ) {
F_163 ( & V_209 -> V_42 , V_205 -> V_41 ) ;
if ( F_1 () )
F_163 ( & V_209 -> V_112 , V_205 -> V_41 ) ;
F_164 ( & V_209 -> V_9 , V_205 -> V_41 ) ;
V_205 -> V_41 = 0 ;
}
V_205 -> V_208 = NULL ;
}
static void F_165 ( struct V_210 * V_211 )
{
struct V_204 * V_205 = F_166 ( & V_207 ) ;
F_162 ( V_205 ) ;
F_167 ( V_212 , & V_205 -> V_20 ) ;
}
static void F_168 ( struct V_4 * V_5 , unsigned int V_41 )
{
struct V_204 * V_205 = & F_160 ( V_207 ) ;
if ( V_205 -> V_208 != V_5 ) {
F_162 ( V_205 ) ;
V_205 -> V_208 = V_5 ;
}
V_205 -> V_41 += V_41 ;
F_161 ( V_207 ) ;
}
static void F_169 ( struct V_4 * V_164 )
{
int V_52 , V_213 ;
if ( ! F_170 ( & V_214 ) )
return;
F_171 () ;
V_213 = F_172 () ;
F_173 (cpu) {
struct V_204 * V_205 = & F_52 ( V_207 , V_52 ) ;
struct V_4 * V_5 ;
V_5 = V_205 -> V_208 ;
if ( ! V_5 || ! V_205 -> V_41 )
continue;
if ( ! F_92 ( V_5 , V_164 ) )
continue;
if ( ! F_174 ( V_212 , & V_205 -> V_20 ) ) {
if ( V_52 == V_213 )
F_165 ( & V_205 -> V_215 ) ;
else
F_175 ( V_52 , & V_205 -> V_215 ) ;
}
}
F_176 () ;
F_177 () ;
F_112 ( & V_214 ) ;
}
static int F_178 ( struct V_216 * V_217 ,
unsigned long V_218 ,
void * V_219 )
{
int V_52 = ( unsigned long ) V_219 ;
struct V_204 * V_205 ;
if ( V_218 == V_220 )
return V_221 ;
if ( V_218 != V_222 && V_218 != V_223 )
return V_221 ;
V_205 = & F_52 ( V_207 , V_52 ) ;
F_162 ( V_205 ) ;
return V_221 ;
}
static void F_179 ( struct V_4 * V_5 ,
unsigned int V_41 ,
T_3 V_136 )
{
do {
if ( F_40 ( & V_5 -> V_42 ) <= V_5 -> V_224 )
continue;
F_180 ( V_5 , V_225 , 1 ) ;
F_181 ( V_5 , V_41 , V_136 , true ) ;
} while ( ( V_5 = F_22 ( V_5 ) ) );
}
static void F_182 ( struct V_210 * V_215 )
{
struct V_4 * V_5 ;
V_5 = F_5 ( V_215 , struct V_4 , V_226 ) ;
F_179 ( V_5 , V_206 , V_227 ) ;
}
void F_183 ( void )
{
unsigned int V_41 = V_118 -> V_228 ;
struct V_4 * V_5 ;
if ( F_184 ( ! V_41 ) )
return;
V_5 = F_75 ( V_118 -> V_87 ) ;
F_179 ( V_5 , V_41 , V_227 ) ;
F_82 ( & V_5 -> V_9 ) ;
V_118 -> V_228 = 0 ;
}
static int F_185 ( struct V_4 * V_5 , T_3 V_136 ,
unsigned int V_41 )
{
unsigned int V_229 = F_186 ( V_206 , V_41 ) ;
int V_230 = V_231 ;
struct V_4 * V_232 ;
struct V_233 * V_234 ;
unsigned long V_235 ;
bool V_236 = true ;
bool V_237 = false ;
if ( F_6 ( V_5 ) )
return 0 ;
V_47:
if ( F_159 ( V_5 , V_41 ) )
return 0 ;
if ( ! F_1 () ||
F_187 ( & V_5 -> V_112 , V_229 , & V_234 ) ) {
if ( F_187 ( & V_5 -> V_42 , V_229 , & V_234 ) )
goto V_238;
if ( F_1 () )
F_163 ( & V_5 -> V_112 , V_229 ) ;
V_232 = F_188 ( V_234 , V_42 ) ;
} else {
V_232 = F_188 ( V_234 , V_112 ) ;
V_236 = false ;
}
if ( V_229 > V_41 ) {
V_229 = V_41 ;
goto V_47;
}
if ( F_70 ( F_189 ( V_239 ) ||
F_117 ( V_118 ) ||
V_118 -> V_20 & V_240 ) )
goto V_241;
if ( F_70 ( F_190 ( V_118 ) ) )
goto V_242;
if ( ! F_191 ( V_136 ) )
goto V_242;
F_180 ( V_232 , V_243 , 1 ) ;
V_235 = F_181 ( V_232 , V_41 ,
V_136 , V_236 ) ;
if ( F_93 ( V_232 ) >= V_41 )
goto V_47;
if ( ! V_237 ) {
F_169 ( V_232 ) ;
V_237 = true ;
goto V_47;
}
if ( V_136 & V_244 )
goto V_242;
if ( V_235 && V_41 <= ( 1 << V_245 ) )
goto V_47;
if ( F_98 ( V_232 ) )
goto V_47;
if ( V_230 -- )
goto V_47;
if ( V_136 & V_246 )
goto V_241;
if ( F_117 ( V_118 ) )
goto V_241;
F_180 ( V_232 , V_247 , 1 ) ;
F_153 ( V_232 , V_136 ,
F_192 ( V_41 * V_248 ) ) ;
V_242:
if ( ! ( V_136 & V_246 ) )
return - V_249 ;
V_241:
F_193 ( & V_5 -> V_42 , V_41 ) ;
if ( F_1 () )
F_193 ( & V_5 -> V_112 , V_41 ) ;
F_194 ( & V_5 -> V_9 , V_41 ) ;
return 0 ;
V_238:
F_194 ( & V_5 -> V_9 , V_229 ) ;
if ( V_229 > V_41 )
F_168 ( V_5 , V_229 - V_41 ) ;
do {
if ( F_40 ( & V_5 -> V_42 ) > V_5 -> V_224 ) {
if ( F_195 () ) {
F_196 ( & V_5 -> V_226 ) ;
break;
}
V_118 -> V_228 += V_229 ;
F_197 ( V_118 ) ;
break;
}
} while ( ( V_5 = F_22 ( V_5 ) ) );
return 0 ;
}
static void F_198 ( struct V_4 * V_5 , unsigned int V_41 )
{
if ( F_6 ( V_5 ) )
return;
F_163 ( & V_5 -> V_42 , V_41 ) ;
if ( F_1 () )
F_163 ( & V_5 -> V_112 , V_41 ) ;
F_164 ( & V_5 -> V_9 , V_41 ) ;
}
static void F_199 ( struct V_18 * V_18 , int * V_250 )
{
struct V_13 * V_13 = F_200 ( V_18 ) ;
F_48 ( & V_13 -> V_251 ) ;
if ( F_201 ( V_18 ) ) {
struct V_106 * V_106 ;
V_106 = F_86 ( V_18 , V_13 ) ;
F_202 ( V_18 ) ;
F_203 ( V_18 , V_106 , F_204 ( V_18 ) ) ;
* V_250 = 1 ;
} else
* V_250 = 0 ;
}
static void F_205 ( struct V_18 * V_18 , int V_250 )
{
struct V_13 * V_13 = F_200 ( V_18 ) ;
if ( V_250 ) {
struct V_106 * V_106 ;
V_106 = F_86 ( V_18 , V_13 ) ;
F_57 ( F_201 ( V_18 ) , V_18 ) ;
F_206 ( V_18 ) ;
F_207 ( V_18 , V_106 , F_204 ( V_18 ) ) ;
}
F_49 ( & V_13 -> V_251 ) ;
}
static void F_208 ( struct V_18 * V_18 , struct V_4 * V_5 ,
bool V_252 )
{
int V_250 ;
F_57 ( V_18 -> V_4 , V_18 ) ;
if ( V_252 )
F_199 ( V_18 , & V_250 ) ;
V_18 -> V_4 = V_5 ;
if ( V_252 )
F_205 ( V_18 , V_250 ) ;
}
static int F_209 ( void )
{
int V_10 , V_253 ;
int V_254 ;
V_10 = F_210 ( & V_255 ,
0 , V_256 , V_227 ) ;
if ( V_10 < 0 )
return V_10 ;
if ( V_10 < V_257 )
return V_10 ;
F_211 ( & V_11 ) ;
V_253 = 2 * ( V_10 + 1 ) ;
if ( V_253 < V_258 )
V_253 = V_258 ;
else if ( V_253 > V_256 )
V_253 = V_256 ;
V_254 = F_212 ( V_253 ) ;
if ( ! V_254 )
V_254 = F_213 ( V_253 ) ;
if ( ! V_254 )
V_257 = V_253 ;
F_214 ( & V_11 ) ;
if ( V_254 ) {
F_215 ( & V_255 , V_10 ) ;
return V_254 ;
}
return V_10 ;
}
static void F_216 ( int V_10 )
{
F_215 ( & V_255 , V_10 ) ;
}
static void F_217 ( struct V_210 * V_259 )
{
struct V_260 * V_261 =
F_5 ( V_259 , struct V_260 , V_215 ) ;
struct V_4 * V_5 = V_261 -> V_5 ;
struct V_262 * V_263 = V_261 -> V_263 ;
F_218 ( V_5 , V_263 ) ;
F_82 ( & V_5 -> V_9 ) ;
F_219 ( V_261 ) ;
}
static void F_220 ( struct V_4 * V_5 ,
struct V_262 * V_263 )
{
struct V_260 * V_261 ;
V_261 = F_221 ( sizeof( * V_261 ) , V_264 ) ;
if ( ! V_261 )
return;
F_91 ( & V_5 -> V_9 ) ;
V_261 -> V_5 = V_5 ;
V_261 -> V_263 = V_263 ;
F_222 ( & V_261 -> V_215 , F_217 ) ;
F_196 ( & V_261 -> V_215 ) ;
}
static void F_223 ( struct V_4 * V_5 ,
struct V_262 * V_263 )
{
V_118 -> V_265 = 1 ;
F_220 ( V_5 , V_263 ) ;
V_118 -> V_265 = 0 ;
}
struct V_262 * F_224 ( struct V_262 * V_263 , T_3 V_266 )
{
struct V_4 * V_5 ;
struct V_262 * V_267 ;
int V_268 ;
F_61 ( ! F_225 ( V_263 ) ) ;
if ( V_263 -> V_20 & V_269 )
V_266 |= V_270 ;
if ( ! ( V_266 & V_270 ) )
return V_263 ;
if ( V_118 -> V_265 )
return V_263 ;
V_5 = F_75 ( V_118 -> V_87 ) ;
V_268 = F_21 ( V_5 -> V_268 ) ;
if ( V_268 < 0 )
goto V_98;
V_267 = F_226 ( V_263 , V_268 ) ;
if ( F_184 ( V_267 ) )
return V_267 ;
F_223 ( V_5 , V_263 ) ;
V_98:
F_82 ( & V_5 -> V_9 ) ;
return V_263 ;
}
void F_227 ( struct V_262 * V_263 )
{
if ( ! F_225 ( V_263 ) )
F_82 ( & V_263 -> V_271 . V_5 -> V_9 ) ;
}
int F_228 ( struct V_18 * V_18 , T_3 V_266 , int V_137 ,
struct V_4 * V_5 )
{
unsigned int V_41 = 1 << V_137 ;
struct V_233 * V_234 ;
int V_109 ;
if ( ! F_229 ( V_5 ) )
return 0 ;
V_109 = F_185 ( V_5 , V_266 , V_41 ) ;
if ( V_109 )
return V_109 ;
if ( ! F_2 ( V_1 ) &&
! F_187 ( & V_5 -> V_125 , V_41 , & V_234 ) ) {
F_198 ( V_5 , V_41 ) ;
return - V_249 ;
}
V_18 -> V_4 = V_5 ;
return 0 ;
}
int F_230 ( struct V_18 * V_18 , T_3 V_266 , int V_137 )
{
struct V_4 * V_5 ;
int V_109 ;
V_5 = F_75 ( V_118 -> V_87 ) ;
V_109 = F_228 ( V_18 , V_266 , V_137 , V_5 ) ;
F_82 ( & V_5 -> V_9 ) ;
return V_109 ;
}
void F_231 ( struct V_18 * V_18 , int V_137 )
{
struct V_4 * V_5 = V_18 -> V_4 ;
unsigned int V_41 = 1 << V_137 ;
if ( ! V_5 )
return;
F_57 ( F_6 ( V_5 ) , V_18 ) ;
if ( ! F_2 ( V_1 ) )
F_163 ( & V_5 -> V_125 , V_41 ) ;
F_163 ( & V_5 -> V_42 , V_41 ) ;
if ( F_1 () )
F_163 ( & V_5 -> V_112 , V_41 ) ;
V_18 -> V_4 = NULL ;
F_164 ( & V_5 -> V_9 , V_41 ) ;
}
void F_232 ( struct V_18 * V_272 )
{
int V_104 ;
if ( F_78 () )
return;
for ( V_104 = 1 ; V_104 < V_273 ; V_104 ++ )
V_272 [ V_104 ] . V_4 = V_272 -> V_4 ;
F_233 ( V_272 -> V_4 -> V_53 -> V_54 [ V_60 ] ,
V_273 ) ;
}
static void F_234 ( struct V_4 * V_5 ,
bool V_274 )
{
int V_51 = ( V_274 ) ? 1 : - 1 ;
F_235 ( V_5 -> V_53 -> V_54 [ V_127 ] , V_51 ) ;
}
static int F_236 ( T_5 V_275 ,
struct V_4 * V_113 , struct V_4 * V_114 )
{
unsigned short V_276 , V_277 ;
V_276 = F_7 ( V_113 ) ;
V_277 = F_7 ( V_114 ) ;
if ( F_237 ( V_275 , V_276 , V_277 ) == V_276 ) {
F_234 ( V_113 , false ) ;
F_234 ( V_114 , true ) ;
return 0 ;
}
return - V_278 ;
}
static inline int F_236 ( T_5 V_275 ,
struct V_4 * V_113 , struct V_4 * V_114 )
{
return - V_278 ;
}
static int F_238 ( struct V_4 * V_5 ,
unsigned long V_111 )
{
unsigned long V_279 ;
unsigned long V_280 ;
bool V_281 = false ;
int V_282 ;
int V_109 ;
V_282 = V_231 *
F_113 ( V_5 ) ;
V_280 = F_40 ( & V_5 -> V_42 ) ;
do {
if ( F_239 ( V_118 ) ) {
V_109 = - V_283 ;
break;
}
F_105 ( & V_284 ) ;
if ( V_111 > V_5 -> V_112 . V_111 ) {
F_112 ( & V_284 ) ;
V_109 = - V_278 ;
break;
}
if ( V_111 > V_5 -> V_42 . V_111 )
V_281 = true ;
V_109 = F_240 ( & V_5 -> V_42 , V_111 ) ;
F_112 ( & V_284 ) ;
if ( ! V_109 )
break;
F_181 ( V_5 , 1 , V_227 , true ) ;
V_279 = F_40 ( & V_5 -> V_42 ) ;
if ( V_279 >= V_280 )
V_282 -- ;
else
V_280 = V_279 ;
} while ( V_282 );
if ( ! V_109 && V_281 )
F_151 ( V_5 ) ;
return V_109 ;
}
static int F_241 ( struct V_4 * V_5 ,
unsigned long V_111 )
{
unsigned long V_279 ;
unsigned long V_280 ;
bool V_281 = false ;
int V_282 ;
int V_109 ;
V_282 = V_231 *
F_113 ( V_5 ) ;
V_280 = F_40 ( & V_5 -> V_112 ) ;
do {
if ( F_239 ( V_118 ) ) {
V_109 = - V_283 ;
break;
}
F_105 ( & V_284 ) ;
if ( V_111 < V_5 -> V_42 . V_111 ) {
F_112 ( & V_284 ) ;
V_109 = - V_278 ;
break;
}
if ( V_111 > V_5 -> V_112 . V_111 )
V_281 = true ;
V_109 = F_240 ( & V_5 -> V_112 , V_111 ) ;
F_112 ( & V_284 ) ;
if ( ! V_109 )
break;
F_181 ( V_5 , 1 , V_227 , false ) ;
V_279 = F_40 ( & V_5 -> V_112 ) ;
if ( V_279 >= V_280 )
V_282 -- ;
else
V_280 = V_279 ;
} while ( V_282 );
if ( ! V_109 && V_281 )
F_151 ( V_5 ) ;
return V_109 ;
}
unsigned long F_242 ( struct V_13 * V_13 , int V_137 ,
T_3 V_136 ,
unsigned long * V_165 )
{
unsigned long V_235 = 0 ;
struct V_12 * V_27 , * V_285 = NULL ;
unsigned long V_286 ;
int V_168 = 0 ;
struct V_23 * V_28 ;
unsigned long V_44 ;
unsigned long V_169 ;
if ( V_137 > 0 )
return 0 ;
V_28 = F_28 ( F_16 ( V_13 ) , F_17 ( V_13 ) ) ;
do {
if ( V_285 )
V_27 = V_285 ;
else
V_27 = F_47 ( V_28 ) ;
if ( ! V_27 )
break;
V_169 = 0 ;
V_286 = F_141 ( V_27 -> V_5 , V_13 ,
V_136 , & V_169 ) ;
V_235 += V_286 ;
* V_165 += V_169 ;
F_48 ( & V_28 -> V_40 ) ;
F_34 ( V_27 , V_28 ) ;
V_285 = NULL ;
if ( ! V_286 )
V_285 = F_44 ( V_28 ) ;
V_44 = F_39 ( V_27 -> V_5 ) ;
F_30 ( V_27 , V_28 , V_44 ) ;
F_49 ( & V_28 -> V_40 ) ;
F_82 ( & V_27 -> V_5 -> V_9 ) ;
V_168 ++ ;
if ( ! V_235 &&
( V_285 == NULL ||
V_168 > V_287 ) )
break;
} while ( ! V_235 );
if ( V_285 )
F_82 ( & V_285 -> V_5 -> V_9 ) ;
return V_235 ;
}
static inline bool F_243 ( struct V_4 * V_5 )
{
bool V_109 ;
F_20 () ;
V_109 = F_244 ( NULL , & V_5 -> V_9 ) ;
F_24 () ;
return V_109 ;
}
static int F_245 ( struct V_4 * V_5 )
{
int V_230 = V_231 ;
F_246 () ;
while ( V_230 && F_40 ( & V_5 -> V_42 ) ) {
int V_288 ;
if ( F_239 ( V_118 ) )
return - V_283 ;
V_288 = F_181 ( V_5 , 1 ,
V_227 , true ) ;
if ( ! V_288 ) {
V_230 -- ;
F_247 ( V_289 , V_290 / 10 ) ;
}
}
return 0 ;
}
static T_6 F_248 ( struct V_291 * V_292 ,
char * V_293 , T_7 V_294 ,
T_8 V_295 )
{
struct V_4 * V_5 = F_10 ( F_249 ( V_292 ) ) ;
if ( F_6 ( V_5 ) )
return - V_278 ;
return F_245 ( V_5 ) ? : V_294 ;
}
static V_123 F_250 ( struct V_7 * V_9 ,
struct V_296 * V_297 )
{
return F_10 ( V_9 ) -> V_97 ;
}
static int F_251 ( struct V_7 * V_9 ,
struct V_296 * V_297 , V_123 V_51 )
{
int V_298 = 0 ;
struct V_4 * V_5 = F_10 ( V_9 ) ;
struct V_4 * V_299 = F_10 ( V_5 -> V_9 . V_33 ) ;
if ( V_5 -> V_97 == V_51 )
return 0 ;
if ( ( ! V_299 || ! V_299 -> V_97 ) &&
( V_51 == 1 || V_51 == 0 ) ) {
if ( ! F_243 ( V_5 ) )
V_5 -> V_97 = V_51 ;
else
V_298 = - V_300 ;
} else
V_298 = - V_278 ;
return V_298 ;
}
static unsigned long F_252 ( struct V_4 * V_5 ,
enum V_49 V_50 )
{
struct V_4 * V_95 ;
unsigned long V_51 = 0 ;
F_111 (iter, memcg)
V_51 += F_50 ( V_95 , V_50 ) ;
return V_51 ;
}
static unsigned long F_253 ( struct V_4 * V_5 ,
enum V_55 V_50 )
{
struct V_4 * V_95 ;
unsigned long V_51 = 0 ;
F_111 (iter, memcg)
V_51 += F_53 ( V_95 , V_50 ) ;
return V_51 ;
}
static unsigned long F_254 ( struct V_4 * V_5 , bool V_134 )
{
unsigned long V_51 ;
if ( F_6 ( V_5 ) ) {
V_51 = F_252 ( V_5 , V_59 ) ;
V_51 += F_252 ( V_5 , V_58 ) ;
if ( V_134 )
V_51 += F_252 ( V_5 , V_127 ) ;
} else {
if ( ! V_134 )
V_51 = F_40 ( & V_5 -> V_42 ) ;
else
V_51 = F_40 ( & V_5 -> V_112 ) ;
}
return V_51 ;
}
static V_123 F_255 ( struct V_7 * V_9 ,
struct V_296 * V_297 )
{
struct V_4 * V_5 = F_10 ( V_9 ) ;
struct V_233 * V_234 ;
switch ( F_256 ( V_297 -> V_195 ) ) {
case V_301 :
V_234 = & V_5 -> V_42 ;
break;
case V_302 :
V_234 = & V_5 -> V_112 ;
break;
case V_303 :
V_234 = & V_5 -> V_125 ;
break;
case V_304 :
V_234 = & V_5 -> V_305 ;
break;
default:
F_257 () ;
}
switch ( F_258 ( V_297 -> V_195 ) ) {
case V_306 :
if ( V_234 == & V_5 -> V_42 )
return ( V_123 ) F_254 ( V_5 , false ) * V_248 ;
if ( V_234 == & V_5 -> V_112 )
return ( V_123 ) F_254 ( V_5 , true ) * V_248 ;
return ( V_123 ) F_40 ( V_234 ) * V_248 ;
case V_307 :
return ( V_123 ) V_234 -> V_111 * V_248 ;
case V_308 :
return ( V_123 ) V_234 -> V_309 * V_248 ;
case V_310 :
return V_234 -> V_124 ;
case V_311 :
return ( V_123 ) V_5 -> V_43 * V_248 ;
default:
F_257 () ;
}
}
static int F_259 ( struct V_4 * V_5 )
{
int V_312 ;
F_260 ( V_5 -> V_268 >= 0 ) ;
F_260 ( V_5 -> V_313 ) ;
V_312 = F_209 () ;
if ( V_312 < 0 )
return V_312 ;
F_261 ( & V_314 ) ;
V_5 -> V_268 = V_312 ;
V_5 -> V_313 = V_315 ;
return 0 ;
}
static int F_262 ( struct V_4 * V_33 ,
struct V_4 * V_5 )
{
int V_109 = 0 ;
F_105 ( & V_284 ) ;
if ( F_229 ( V_33 ) ||
( F_2 ( V_1 ) && ! V_316 ) )
V_109 = F_259 ( V_5 ) ;
F_112 ( & V_284 ) ;
return V_109 ;
}
static void F_263 ( struct V_4 * V_5 )
{
struct V_7 * V_9 ;
struct V_4 * V_33 , * V_317 ;
int V_268 ;
if ( V_5 -> V_313 != V_315 )
return;
V_5 -> V_313 = V_318 ;
F_264 ( V_5 ) ;
V_268 = V_5 -> V_268 ;
F_260 ( V_268 < 0 ) ;
V_33 = F_22 ( V_5 ) ;
if ( ! V_33 )
V_33 = V_6 ;
F_265 (css, &memcg->css) {
V_317 = F_10 ( V_9 ) ;
F_260 ( V_317 -> V_268 != V_268 ) ;
V_317 -> V_268 = V_33 -> V_268 ;
if ( ! V_5 -> V_97 )
break;
}
F_266 ( V_268 , V_33 -> V_268 ) ;
F_216 ( V_268 ) ;
}
static void F_267 ( struct V_4 * V_5 )
{
if ( F_70 ( V_5 -> V_313 == V_315 ) )
F_263 ( V_5 ) ;
if ( V_5 -> V_313 == V_318 ) {
F_268 ( V_5 ) ;
F_269 ( & V_314 ) ;
F_270 ( F_40 ( & V_5 -> V_125 ) ) ;
}
}
static int F_262 ( struct V_4 * V_33 , struct V_4 * V_5 )
{
return 0 ;
}
static int F_259 ( struct V_4 * V_5 )
{
return 0 ;
}
static void F_263 ( struct V_4 * V_5 )
{
}
static void F_267 ( struct V_4 * V_5 )
{
}
static int F_271 ( struct V_4 * V_5 ,
unsigned long V_111 )
{
int V_109 = 0 ;
F_105 ( & V_284 ) ;
if ( ! F_229 ( V_5 ) ) {
if ( F_272 ( V_5 -> V_9 . V_22 ) ||
( V_5 -> V_97 && F_243 ( V_5 ) ) )
V_109 = - V_300 ;
if ( V_109 )
goto V_98;
V_109 = F_259 ( V_5 ) ;
if ( V_109 )
goto V_98;
}
V_109 = F_240 ( & V_5 -> V_125 , V_111 ) ;
V_98:
F_112 ( & V_284 ) ;
return V_109 ;
}
static int F_273 ( struct V_4 * V_5 , unsigned long V_111 )
{
int V_109 ;
F_105 ( & V_284 ) ;
V_109 = F_240 ( & V_5 -> V_305 , V_111 ) ;
if ( V_109 )
goto V_98;
if ( ! V_5 -> V_319 ) {
F_261 ( & V_320 ) ;
V_5 -> V_319 = true ;
}
V_98:
F_112 ( & V_284 ) ;
return V_109 ;
}
static T_6 F_274 ( struct V_291 * V_292 ,
char * V_293 , T_7 V_294 , T_8 V_295 )
{
struct V_4 * V_5 = F_10 ( F_249 ( V_292 ) ) ;
unsigned long V_41 ;
int V_109 ;
V_293 = F_275 ( V_293 ) ;
V_109 = F_276 ( V_293 , L_12 , & V_41 ) ;
if ( V_109 )
return V_109 ;
switch ( F_258 ( F_277 ( V_292 ) -> V_195 ) ) {
case V_307 :
if ( F_6 ( V_5 ) ) {
V_109 = - V_278 ;
break;
}
switch ( F_256 ( F_277 ( V_292 ) -> V_195 ) ) {
case V_301 :
V_109 = F_238 ( V_5 , V_41 ) ;
break;
case V_302 :
V_109 = F_241 ( V_5 , V_41 ) ;
break;
case V_303 :
V_109 = F_271 ( V_5 , V_41 ) ;
break;
case V_304 :
V_109 = F_273 ( V_5 , V_41 ) ;
break;
}
break;
case V_311 :
V_5 -> V_43 = V_41 ;
V_109 = 0 ;
break;
}
return V_109 ? : V_294 ;
}
static T_6 F_278 ( struct V_291 * V_292 , char * V_293 ,
T_7 V_294 , T_8 V_295 )
{
struct V_4 * V_5 = F_10 ( F_249 ( V_292 ) ) ;
struct V_233 * V_234 ;
switch ( F_256 ( F_277 ( V_292 ) -> V_195 ) ) {
case V_301 :
V_234 = & V_5 -> V_42 ;
break;
case V_302 :
V_234 = & V_5 -> V_112 ;
break;
case V_303 :
V_234 = & V_5 -> V_125 ;
break;
case V_304 :
V_234 = & V_5 -> V_305 ;
break;
default:
F_257 () ;
}
switch ( F_258 ( F_277 ( V_292 ) -> V_195 ) ) {
case V_308 :
F_279 ( V_234 ) ;
break;
case V_310 :
V_234 -> V_124 = 0 ;
break;
default:
F_257 () ;
}
return V_294 ;
}
static V_123 F_280 ( struct V_7 * V_9 ,
struct V_296 * V_297 )
{
return F_10 ( V_9 ) -> V_321 ;
}
static int F_281 ( struct V_7 * V_9 ,
struct V_296 * V_297 , V_123 V_51 )
{
struct V_4 * V_5 = F_10 ( V_9 ) ;
if ( V_51 & ~ V_322 )
return - V_278 ;
V_5 -> V_321 = V_51 ;
return 0 ;
}
static int F_281 ( struct V_7 * V_9 ,
struct V_296 * V_297 , V_123 V_51 )
{
return - V_323 ;
}
static int F_282 ( struct V_324 * V_325 , void * V_326 )
{
struct V_327 {
const char * V_328 ;
unsigned int V_64 ;
};
static const struct V_327 V_329 [] = {
{ L_13 , V_330 } ,
{ L_14 , V_156 } ,
{ L_15 , V_157 } ,
{ L_16 , F_63 (LRU_UNEVICTABLE) } ,
} ;
const struct V_327 * V_53 ;
int V_14 ;
unsigned long V_65 ;
struct V_4 * V_5 = F_10 ( F_283 ( V_325 ) ) ;
for ( V_53 = V_329 ; V_53 < V_329 + F_284 ( V_329 ) ; V_53 ++ ) {
V_65 = F_64 ( V_5 , V_53 -> V_64 ) ;
F_285 ( V_325 , L_17 , V_53 -> V_328 , V_65 ) ;
F_65 (nid, N_MEMORY) {
V_65 = F_60 ( V_5 , V_14 ,
V_53 -> V_64 ) ;
F_285 ( V_325 , L_18 , V_14 , V_65 ) ;
}
F_286 ( V_325 , '\n' ) ;
}
for ( V_53 = V_329 ; V_53 < V_329 + F_284 ( V_329 ) ; V_53 ++ ) {
struct V_4 * V_95 ;
V_65 = 0 ;
F_111 (iter, memcg)
V_65 += F_64 ( V_95 , V_53 -> V_64 ) ;
F_285 ( V_325 , L_19 , V_53 -> V_328 , V_65 ) ;
F_65 (nid, N_MEMORY) {
V_65 = 0 ;
F_111 (iter, memcg)
V_65 += F_60 (
V_95 , V_14 , V_53 -> V_64 ) ;
F_285 ( V_325 , L_18 , V_14 , V_65 ) ;
}
F_286 ( V_325 , '\n' ) ;
}
return 0 ;
}
static int F_287 ( struct V_324 * V_325 , void * V_326 )
{
struct V_4 * V_5 = F_10 ( F_283 ( V_325 ) ) ;
unsigned long V_42 , V_112 ;
struct V_4 * V_331 ;
unsigned int V_104 ;
F_288 ( F_284 ( V_128 ) !=
V_126 ) ;
F_288 ( F_284 ( V_332 ) !=
V_333 ) ;
F_288 ( F_284 ( V_130 ) != V_129 ) ;
for ( V_104 = 0 ; V_104 < V_126 ; V_104 ++ ) {
if ( V_104 == V_127 && ! F_1 () )
continue;
F_285 ( V_325 , L_20 , V_128 [ V_104 ] ,
F_50 ( V_5 , V_104 ) * V_248 ) ;
}
for ( V_104 = 0 ; V_104 < V_333 ; V_104 ++ )
F_285 ( V_325 , L_20 , V_332 [ V_104 ] ,
F_53 ( V_5 , V_104 ) ) ;
for ( V_104 = 0 ; V_104 < V_129 ; V_104 ++ )
F_285 ( V_325 , L_20 , V_130 [ V_104 ] ,
F_64 ( V_5 , F_63 ( V_104 ) ) * V_248 ) ;
V_42 = V_112 = V_334 ;
for ( V_331 = V_5 ; V_331 ; V_331 = F_22 ( V_331 ) ) {
V_42 = F_94 ( V_42 , V_331 -> V_42 . V_111 ) ;
V_112 = F_94 ( V_112 , V_331 -> V_112 . V_111 ) ;
}
F_285 ( V_325 , L_21 ,
( V_123 ) V_42 * V_248 ) ;
if ( F_1 () )
F_285 ( V_325 , L_22 ,
( V_123 ) V_112 * V_248 ) ;
for ( V_104 = 0 ; V_104 < V_126 ; V_104 ++ ) {
unsigned long long V_51 = 0 ;
if ( V_104 == V_127 && ! F_1 () )
continue;
F_111 (mi, memcg)
V_51 += F_50 ( V_331 , V_104 ) * V_248 ;
F_285 ( V_325 , L_23 , V_128 [ V_104 ] , V_51 ) ;
}
for ( V_104 = 0 ; V_104 < V_333 ; V_104 ++ ) {
unsigned long long V_51 = 0 ;
F_111 (mi, memcg)
V_51 += F_53 ( V_331 , V_104 ) ;
F_285 ( V_325 , L_23 ,
V_332 [ V_104 ] , V_51 ) ;
}
for ( V_104 = 0 ; V_104 < V_129 ; V_104 ++ ) {
unsigned long long V_51 = 0 ;
F_111 (mi, memcg)
V_51 += F_64 ( V_331 , F_63 ( V_104 ) ) * V_248 ;
F_285 ( V_325 , L_23 , V_130 [ V_104 ] , V_51 ) ;
}
#ifdef F_289
{
int V_14 , V_15 ;
struct V_12 * V_27 ;
struct V_335 * V_336 ;
unsigned long V_337 [ 2 ] = { 0 , 0 } ;
unsigned long V_338 [ 2 ] = { 0 , 0 } ;
F_290 (nid)
for ( V_15 = 0 ; V_15 < V_45 ; V_15 ++ ) {
V_27 = & V_5 -> V_16 [ V_14 ] -> V_17 [ V_15 ] ;
V_336 = & V_27 -> V_106 . V_339 ;
V_337 [ 0 ] += V_336 -> V_337 [ 0 ] ;
V_337 [ 1 ] += V_336 -> V_337 [ 1 ] ;
V_338 [ 0 ] += V_336 -> V_338 [ 0 ] ;
V_338 [ 1 ] += V_336 -> V_338 [ 1 ] ;
}
F_285 ( V_325 , L_24 , V_337 [ 0 ] ) ;
F_285 ( V_325 , L_25 , V_337 [ 1 ] ) ;
F_285 ( V_325 , L_26 , V_338 [ 0 ] ) ;
F_285 ( V_325 , L_27 , V_338 [ 1 ] ) ;
}
#endif
return 0 ;
}
static V_123 F_291 ( struct V_7 * V_9 ,
struct V_296 * V_297 )
{
struct V_4 * V_5 = F_10 ( V_9 ) ;
return F_115 ( V_5 ) ;
}
static int F_292 ( struct V_7 * V_9 ,
struct V_296 * V_297 , V_123 V_51 )
{
struct V_4 * V_5 = F_10 ( V_9 ) ;
if ( V_51 > 100 )
return - V_278 ;
if ( V_9 -> V_33 )
V_5 -> V_340 = V_51 ;
else
V_341 = V_51 ;
return 0 ;
}
static void F_293 ( struct V_4 * V_5 , bool V_134 )
{
struct V_342 * V_343 ;
unsigned long V_344 ;
int V_104 ;
F_20 () ;
if ( ! V_134 )
V_343 = F_76 ( V_5 -> V_345 . V_346 ) ;
else
V_343 = F_76 ( V_5 -> V_347 . V_346 ) ;
if ( ! V_343 )
goto V_116;
V_344 = F_254 ( V_5 , V_134 ) ;
V_104 = V_343 -> V_348 ;
for (; V_104 >= 0 && F_70 ( V_343 -> V_349 [ V_104 ] . V_350 > V_344 ) ; V_104 -- )
F_294 ( V_343 -> V_349 [ V_104 ] . V_351 , 1 ) ;
V_104 ++ ;
for (; V_104 < V_343 -> V_253 && F_70 ( V_343 -> V_349 [ V_104 ] . V_350 <= V_344 ) ; V_104 ++ )
F_294 ( V_343 -> V_349 [ V_104 ] . V_351 , 1 ) ;
V_343 -> V_348 = V_104 - 1 ;
V_116:
F_24 () ;
}
static void F_71 ( struct V_4 * V_5 )
{
while ( V_5 ) {
F_293 ( V_5 , false ) ;
if ( F_1 () )
F_293 ( V_5 , true ) ;
V_5 = F_22 ( V_5 ) ;
}
}
static int F_295 ( const void * V_352 , const void * V_353 )
{
const struct F_71 * V_354 = V_352 ;
const struct F_71 * V_355 = V_353 ;
if ( V_354 -> V_350 > V_355 -> V_350 )
return 1 ;
if ( V_354 -> V_350 < V_355 -> V_350 )
return - 1 ;
return 0 ;
}
static int F_296 ( struct V_4 * V_5 )
{
struct V_356 * V_357 ;
F_96 ( & V_172 ) ;
F_297 (ev, &memcg->oom_notify, list)
F_294 ( V_357 -> V_351 , 1 ) ;
F_97 ( & V_172 ) ;
return 0 ;
}
static void F_156 ( struct V_4 * V_5 )
{
struct V_4 * V_95 ;
F_111 (iter, memcg)
F_296 ( V_95 ) ;
}
static int F_298 ( struct V_4 * V_5 ,
struct V_358 * V_351 , const char * args , enum V_359 type )
{
struct V_360 * V_345 ;
struct V_342 * V_361 ;
unsigned long V_350 ;
unsigned long V_344 ;
int V_104 , V_253 , V_109 ;
V_109 = F_276 ( args , L_12 , & V_350 ) ;
if ( V_109 )
return V_109 ;
F_105 ( & V_5 -> V_362 ) ;
if ( type == V_301 ) {
V_345 = & V_5 -> V_345 ;
V_344 = F_254 ( V_5 , false ) ;
} else if ( type == V_302 ) {
V_345 = & V_5 -> V_347 ;
V_344 = F_254 ( V_5 , true ) ;
} else
F_257 () ;
if ( V_345 -> V_346 )
F_293 ( V_5 , type == V_302 ) ;
V_253 = V_345 -> V_346 ? V_345 -> V_346 -> V_253 + 1 : 1 ;
V_361 = F_221 ( sizeof( * V_361 ) + V_253 * sizeof( struct F_71 ) ,
V_227 ) ;
if ( ! V_361 ) {
V_109 = - V_249 ;
goto V_116;
}
V_361 -> V_253 = V_253 ;
if ( V_345 -> V_346 ) {
memcpy ( V_361 -> V_349 , V_345 -> V_346 -> V_349 , ( V_253 - 1 ) *
sizeof( struct F_71 ) ) ;
}
V_361 -> V_349 [ V_253 - 1 ] . V_351 = V_351 ;
V_361 -> V_349 [ V_253 - 1 ] . V_350 = V_350 ;
F_299 ( V_361 -> V_349 , V_253 , sizeof( struct F_71 ) ,
F_295 , NULL ) ;
V_361 -> V_348 = - 1 ;
for ( V_104 = 0 ; V_104 < V_253 ; V_104 ++ ) {
if ( V_361 -> V_349 [ V_104 ] . V_350 <= V_344 ) {
++ V_361 -> V_348 ;
} else
break;
}
F_219 ( V_345 -> V_363 ) ;
V_345 -> V_363 = V_345 -> V_346 ;
F_300 ( V_345 -> V_346 , V_361 ) ;
F_301 () ;
V_116:
F_112 ( & V_5 -> V_362 ) ;
return V_109 ;
}
static int F_302 ( struct V_4 * V_5 ,
struct V_358 * V_351 , const char * args )
{
return F_298 ( V_5 , V_351 , args , V_301 ) ;
}
static int F_303 ( struct V_4 * V_5 ,
struct V_358 * V_351 , const char * args )
{
return F_298 ( V_5 , V_351 , args , V_302 ) ;
}
static void F_304 ( struct V_4 * V_5 ,
struct V_358 * V_351 , enum V_359 type )
{
struct V_360 * V_345 ;
struct V_342 * V_361 ;
unsigned long V_344 ;
int V_104 , V_364 , V_253 ;
F_105 ( & V_5 -> V_362 ) ;
if ( type == V_301 ) {
V_345 = & V_5 -> V_345 ;
V_344 = F_254 ( V_5 , false ) ;
} else if ( type == V_302 ) {
V_345 = & V_5 -> V_347 ;
V_344 = F_254 ( V_5 , true ) ;
} else
F_257 () ;
if ( ! V_345 -> V_346 )
goto V_116;
F_293 ( V_5 , type == V_302 ) ;
V_253 = 0 ;
for ( V_104 = 0 ; V_104 < V_345 -> V_346 -> V_253 ; V_104 ++ ) {
if ( V_345 -> V_346 -> V_349 [ V_104 ] . V_351 != V_351 )
V_253 ++ ;
}
V_361 = V_345 -> V_363 ;
if ( ! V_253 ) {
F_219 ( V_361 ) ;
V_361 = NULL ;
goto V_365;
}
V_361 -> V_253 = V_253 ;
V_361 -> V_348 = - 1 ;
for ( V_104 = 0 , V_364 = 0 ; V_104 < V_345 -> V_346 -> V_253 ; V_104 ++ ) {
if ( V_345 -> V_346 -> V_349 [ V_104 ] . V_351 == V_351 )
continue;
V_361 -> V_349 [ V_364 ] = V_345 -> V_346 -> V_349 [ V_104 ] ;
if ( V_361 -> V_349 [ V_364 ] . V_350 <= V_344 ) {
++ V_361 -> V_348 ;
}
V_364 ++ ;
}
V_365:
V_345 -> V_363 = V_345 -> V_346 ;
F_300 ( V_345 -> V_346 , V_361 ) ;
F_301 () ;
if ( ! V_361 ) {
F_219 ( V_345 -> V_363 ) ;
V_345 -> V_363 = NULL ;
}
V_116:
F_112 ( & V_5 -> V_362 ) ;
}
static void F_305 ( struct V_4 * V_5 ,
struct V_358 * V_351 )
{
return F_304 ( V_5 , V_351 , V_301 ) ;
}
static void F_306 ( struct V_4 * V_5 ,
struct V_358 * V_351 )
{
return F_304 ( V_5 , V_351 , V_302 ) ;
}
static int F_307 ( struct V_4 * V_5 ,
struct V_358 * V_351 , const char * args )
{
struct V_356 * V_366 ;
V_366 = F_221 ( sizeof( * V_366 ) , V_227 ) ;
if ( ! V_366 )
return - V_249 ;
F_96 ( & V_172 ) ;
V_366 -> V_351 = V_351 ;
F_308 ( & V_366 -> V_367 , & V_5 -> V_368 ) ;
if ( V_5 -> V_175 )
F_294 ( V_351 , 1 ) ;
F_97 ( & V_172 ) ;
return 0 ;
}
static void F_309 ( struct V_4 * V_5 ,
struct V_358 * V_351 )
{
struct V_356 * V_357 , * V_369 ;
F_96 ( & V_172 ) ;
F_310 (ev, tmp, &memcg->oom_notify, list) {
if ( V_357 -> V_351 == V_351 ) {
F_311 ( & V_357 -> V_367 ) ;
F_219 ( V_357 ) ;
}
}
F_97 ( & V_172 ) ;
}
static int F_312 ( struct V_324 * V_370 , void * V_326 )
{
struct V_4 * V_5 = F_10 ( F_283 ( V_370 ) ) ;
F_285 ( V_370 , L_28 , V_5 -> V_198 ) ;
F_285 ( V_370 , L_29 , ( bool ) V_5 -> V_175 ) ;
return 0 ;
}
static int F_313 ( struct V_7 * V_9 ,
struct V_296 * V_297 , V_123 V_51 )
{
struct V_4 * V_5 = F_10 ( V_9 ) ;
if ( ! V_9 -> V_33 || ! ( ( V_51 == 0 ) || ( V_51 == 1 ) ) )
return - V_278 ;
V_5 -> V_198 = V_51 ;
if ( ! V_51 )
F_151 ( V_5 ) ;
return 0 ;
}
struct V_371 * F_314 ( struct V_4 * V_5 )
{
return & V_5 -> V_372 ;
}
static int F_315 ( struct V_4 * V_5 , T_3 V_266 )
{
return F_316 ( & V_5 -> V_373 , V_266 ) ;
}
static void F_317 ( struct V_4 * V_5 )
{
F_318 ( & V_5 -> V_373 ) ;
}
static void F_319 ( struct V_4 * V_5 )
{
F_320 ( & V_5 -> V_373 ) ;
}
struct V_374 * F_321 ( struct V_375 * V_376 )
{
struct V_4 * V_5 = F_10 ( V_376 -> V_377 ) ;
if ( ! V_5 -> V_9 . V_33 )
return NULL ;
return & V_5 -> V_373 ;
}
void F_322 ( struct V_375 * V_376 , unsigned long * V_378 ,
unsigned long * V_379 , unsigned long * V_380 ,
unsigned long * V_381 )
{
struct V_4 * V_5 = F_10 ( V_376 -> V_377 ) ;
struct V_4 * V_33 ;
* V_380 = F_50 ( V_5 , V_382 ) ;
* V_381 = F_50 ( V_5 , V_383 ) ;
* V_378 = F_64 ( V_5 , ( 1 << V_384 ) |
( 1 << V_385 ) ) ;
* V_379 = V_334 ;
while ( ( V_33 = F_22 ( V_5 ) ) ) {
unsigned long V_386 = F_94 ( V_5 -> V_42 . V_111 , V_5 -> V_224 ) ;
unsigned long V_387 = F_40 ( & V_5 -> V_42 ) ;
* V_379 = F_94 ( * V_379 , V_386 - F_94 ( V_386 , V_387 ) ) ;
V_5 = V_33 ;
}
}
static int F_315 ( struct V_4 * V_5 , T_3 V_266 )
{
return 0 ;
}
static void F_317 ( struct V_4 * V_5 )
{
}
static void F_319 ( struct V_4 * V_5 )
{
}
static void F_323 ( struct V_210 * V_215 )
{
struct V_388 * V_366 =
F_5 ( V_215 , struct V_388 , remove ) ;
struct V_4 * V_5 = V_366 -> V_5 ;
F_324 ( V_366 -> V_389 , & V_366 -> V_119 ) ;
V_366 -> V_390 ( V_5 , V_366 -> V_351 ) ;
F_294 ( V_366 -> V_351 , 1 ) ;
F_325 ( V_366 -> V_351 ) ;
F_219 ( V_366 ) ;
F_82 ( & V_5 -> V_9 ) ;
}
static int F_326 ( T_4 * V_119 , unsigned V_176 ,
int V_177 , void * V_391 )
{
struct V_388 * V_366 =
F_5 ( V_119 , struct V_388 , V_119 ) ;
struct V_4 * V_5 = V_366 -> V_5 ;
unsigned long V_20 = ( unsigned long ) V_391 ;
if ( V_20 & V_392 ) {
F_96 ( & V_5 -> V_393 ) ;
if ( ! F_327 ( & V_366 -> V_367 ) ) {
F_328 ( & V_366 -> V_367 ) ;
F_196 ( & V_366 -> remove ) ;
}
F_97 ( & V_5 -> V_393 ) ;
}
return 0 ;
}
static void F_329 ( struct V_394 * V_394 ,
T_9 * V_389 , T_10 * V_395 )
{
struct V_388 * V_366 =
F_5 ( V_395 , struct V_388 , V_395 ) ;
V_366 -> V_389 = V_389 ;
F_330 ( V_389 , & V_366 -> V_119 ) ;
}
static T_6 F_331 ( struct V_291 * V_292 ,
char * V_293 , T_7 V_294 , T_8 V_295 )
{
struct V_7 * V_9 = F_249 ( V_292 ) ;
struct V_4 * V_5 = F_10 ( V_9 ) ;
struct V_388 * V_366 ;
struct V_7 * V_396 ;
unsigned int V_397 , V_398 ;
struct V_399 V_400 ;
struct V_399 V_401 ;
const char * V_328 ;
char * V_402 ;
int V_109 ;
V_293 = F_275 ( V_293 ) ;
V_397 = F_332 ( V_293 , & V_402 , 10 ) ;
if ( * V_402 != ' ' )
return - V_278 ;
V_293 = V_402 + 1 ;
V_398 = F_332 ( V_293 , & V_402 , 10 ) ;
if ( ( * V_402 != ' ' ) && ( * V_402 != '\0' ) )
return - V_278 ;
V_293 = V_402 + 1 ;
V_366 = F_333 ( sizeof( * V_366 ) , V_227 ) ;
if ( ! V_366 )
return - V_249 ;
V_366 -> V_5 = V_5 ;
F_155 ( & V_366 -> V_367 ) ;
F_334 ( & V_366 -> V_395 , F_329 ) ;
F_335 ( & V_366 -> V_119 , F_326 ) ;
F_222 ( & V_366 -> remove , F_323 ) ;
V_400 = F_336 ( V_397 ) ;
if ( ! V_400 . V_394 ) {
V_109 = - V_403 ;
goto V_404;
}
V_366 -> V_351 = F_337 ( V_400 . V_394 ) ;
if ( F_338 ( V_366 -> V_351 ) ) {
V_109 = F_339 ( V_366 -> V_351 ) ;
goto V_405;
}
V_401 = F_336 ( V_398 ) ;
if ( ! V_401 . V_394 ) {
V_109 = - V_403 ;
goto V_406;
}
V_109 = F_340 ( F_341 ( V_401 . V_394 ) , V_407 ) ;
if ( V_109 < 0 )
goto V_408;
V_328 = V_401 . V_394 -> V_409 . V_410 -> V_411 . V_328 ;
if ( ! strcmp ( V_328 , L_30 ) ) {
V_366 -> V_412 = F_302 ;
V_366 -> V_390 = F_305 ;
} else if ( ! strcmp ( V_328 , L_31 ) ) {
V_366 -> V_412 = F_307 ;
V_366 -> V_390 = F_309 ;
} else if ( ! strcmp ( V_328 , L_32 ) ) {
V_366 -> V_412 = V_413 ;
V_366 -> V_390 = V_414 ;
} else if ( ! strcmp ( V_328 , L_33 ) ) {
V_366 -> V_412 = F_303 ;
V_366 -> V_390 = F_306 ;
} else {
V_109 = - V_278 ;
goto V_408;
}
V_396 = F_342 ( V_401 . V_394 -> V_409 . V_410 -> V_415 ,
& V_1 ) ;
V_109 = - V_278 ;
if ( F_338 ( V_396 ) )
goto V_408;
if ( V_396 != V_9 ) {
F_82 ( V_396 ) ;
goto V_408;
}
V_109 = V_366 -> V_412 ( V_5 , V_366 -> V_351 , V_293 ) ;
if ( V_109 )
goto V_416;
V_400 . V_394 -> V_417 -> V_418 ( V_400 . V_394 , & V_366 -> V_395 ) ;
F_96 ( & V_5 -> V_393 ) ;
F_308 ( & V_366 -> V_367 , & V_5 -> V_419 ) ;
F_97 ( & V_5 -> V_393 ) ;
F_343 ( V_401 ) ;
F_343 ( V_400 ) ;
return V_294 ;
V_416:
F_82 ( V_9 ) ;
V_408:
F_343 ( V_401 ) ;
V_406:
F_325 ( V_366 -> V_351 ) ;
V_405:
F_343 ( V_400 ) ;
V_404:
F_219 ( V_366 ) ;
return V_109 ;
}
static int F_344 ( struct V_4 * V_5 , int V_162 )
{
struct V_420 * V_421 ;
struct V_12 * V_27 ;
int V_13 , V_369 = V_162 ;
if ( ! F_345 ( V_162 , V_422 ) )
V_369 = - 1 ;
V_421 = F_346 ( sizeof( * V_421 ) , V_227 , V_369 ) ;
if ( ! V_421 )
return 1 ;
for ( V_13 = 0 ; V_13 < V_45 ; V_13 ++ ) {
V_27 = & V_421 -> V_17 [ V_13 ] ;
F_347 ( & V_27 -> V_106 ) ;
V_27 -> V_36 = 0 ;
V_27 -> V_35 = false ;
V_27 -> V_5 = V_5 ;
}
V_5 -> V_16 [ V_162 ] = V_421 ;
return 0 ;
}
static void F_348 ( struct V_4 * V_5 , int V_162 )
{
F_219 ( V_5 -> V_16 [ V_162 ] ) ;
}
static void F_349 ( struct V_4 * V_5 )
{
int V_162 ;
F_317 ( V_5 ) ;
F_43 (node)
F_348 ( V_5 , V_162 ) ;
F_350 ( V_5 -> V_53 ) ;
F_219 ( V_5 ) ;
}
static struct V_4 * F_351 ( void )
{
struct V_4 * V_5 ;
T_7 V_253 ;
int V_162 ;
V_253 = sizeof( struct V_4 ) ;
V_253 += V_66 * sizeof( struct V_420 * ) ;
V_5 = F_333 ( V_253 , V_227 ) ;
if ( ! V_5 )
return NULL ;
V_5 -> V_53 = F_352 ( struct V_423 ) ;
if ( ! V_5 -> V_53 )
goto V_424;
F_43 (node)
if ( F_344 ( V_5 , V_162 ) )
goto V_424;
if ( F_315 ( V_5 , V_227 ) )
goto V_424;
F_222 ( & V_5 -> V_226 , F_182 ) ;
V_5 -> V_163 = V_82 ;
F_155 ( & V_5 -> V_368 ) ;
F_353 ( & V_5 -> V_362 ) ;
F_354 ( & V_5 -> V_201 ) ;
F_355 ( & V_5 -> V_3 ) ;
F_155 ( & V_5 -> V_419 ) ;
F_354 ( & V_5 -> V_393 ) ;
V_5 -> V_425 = V_426 ;
#ifndef F_356
V_5 -> V_268 = - 1 ;
#endif
#ifdef F_357
F_155 ( & V_5 -> V_372 ) ;
#endif
return V_5 ;
V_424:
F_349 ( V_5 ) ;
return NULL ;
}
static struct V_7 * T_11
F_358 ( struct V_7 * V_427 )
{
struct V_4 * V_33 = F_10 ( V_427 ) ;
struct V_4 * V_5 ;
long error = - V_249 ;
V_5 = F_351 () ;
if ( ! V_5 )
return F_359 ( error ) ;
V_5 -> V_224 = V_334 ;
V_5 -> V_43 = V_334 ;
if ( V_33 ) {
V_5 -> V_340 = F_115 ( V_33 ) ;
V_5 -> V_198 = V_33 -> V_198 ;
}
if ( V_33 && V_33 -> V_97 ) {
V_5 -> V_97 = true ;
F_360 ( & V_5 -> V_42 , & V_33 -> V_42 ) ;
F_360 ( & V_5 -> V_134 , & V_33 -> V_134 ) ;
F_360 ( & V_5 -> V_112 , & V_33 -> V_112 ) ;
F_360 ( & V_5 -> V_125 , & V_33 -> V_125 ) ;
F_360 ( & V_5 -> V_305 , & V_33 -> V_305 ) ;
} else {
F_360 ( & V_5 -> V_42 , NULL ) ;
F_360 ( & V_5 -> V_134 , NULL ) ;
F_360 ( & V_5 -> V_112 , NULL ) ;
F_360 ( & V_5 -> V_125 , NULL ) ;
F_360 ( & V_5 -> V_305 , NULL ) ;
if ( V_33 != V_6 )
V_1 . V_428 = true ;
}
if ( ! V_33 ) {
V_6 = V_5 ;
return & V_5 -> V_9 ;
}
error = F_262 ( V_33 , V_5 ) ;
if ( error )
goto V_424;
if ( F_2 ( V_1 ) && ! V_429 )
F_261 ( & V_320 ) ;
return & V_5 -> V_9 ;
V_424:
F_349 ( V_5 ) ;
return NULL ;
}
static int
F_361 ( struct V_7 * V_9 )
{
if ( V_9 -> V_10 > V_430 )
return - V_431 ;
return 0 ;
}
static void F_362 ( struct V_7 * V_9 )
{
struct V_4 * V_5 = F_10 ( V_9 ) ;
struct V_388 * V_366 , * V_369 ;
F_96 ( & V_5 -> V_393 ) ;
F_310 (event, tmp, &memcg->event_list, list) {
F_328 ( & V_366 -> V_367 ) ;
F_196 ( & V_366 -> remove ) ;
}
F_97 ( & V_5 -> V_393 ) ;
F_263 ( V_5 ) ;
F_363 ( V_5 ) ;
}
static void F_364 ( struct V_7 * V_9 )
{
struct V_4 * V_5 = F_10 ( V_9 ) ;
F_84 ( V_5 ) ;
}
static void F_365 ( struct V_7 * V_9 )
{
struct V_4 * V_5 = F_10 ( V_9 ) ;
if ( F_2 ( V_1 ) && ! V_429 )
F_269 ( & V_320 ) ;
if ( ! F_2 ( V_1 ) && V_5 -> V_319 )
F_269 ( & V_320 ) ;
F_366 ( & V_5 -> V_3 ) ;
F_367 ( & V_5 -> V_226 ) ;
F_42 ( V_5 ) ;
F_267 ( V_5 ) ;
F_349 ( V_5 ) ;
}
static void F_368 ( struct V_7 * V_9 )
{
struct V_4 * V_5 = F_10 ( V_9 ) ;
F_238 ( V_5 , V_334 ) ;
F_241 ( V_5 , V_334 ) ;
F_271 ( V_5 , V_334 ) ;
V_5 -> V_432 = 0 ;
V_5 -> V_224 = V_334 ;
V_5 -> V_43 = V_334 ;
F_319 ( V_5 ) ;
}
static int F_369 ( unsigned long V_54 )
{
int V_109 ;
V_109 = F_185 ( V_115 . V_114 , V_227 & ~ V_433 , V_54 ) ;
if ( ! V_109 ) {
V_115 . V_434 += V_54 ;
return V_109 ;
}
while ( V_54 -- ) {
V_109 = F_185 ( V_115 . V_114 , V_227 & ~ V_244 , 1 ) ;
if ( V_109 )
return V_109 ;
V_115 . V_434 ++ ;
F_370 () ;
}
return 0 ;
}
static struct V_18 * F_371 ( struct V_435 * V_436 ,
unsigned long V_437 , T_12 V_438 )
{
struct V_18 * V_18 = F_372 ( V_436 , V_437 , V_438 ) ;
if ( ! V_18 || ! F_373 ( V_18 ) )
return NULL ;
if ( F_55 ( V_18 ) ) {
if ( ! ( V_115 . V_20 & V_439 ) )
return NULL ;
} else {
if ( ! ( V_115 . V_20 & V_440 ) )
return NULL ;
}
if ( ! F_374 ( V_18 ) )
return NULL ;
return V_18 ;
}
static struct V_18 * F_375 ( struct V_435 * V_436 ,
unsigned long V_437 , T_12 V_438 , T_5 * V_275 )
{
struct V_18 * V_18 = NULL ;
T_5 V_441 = F_376 ( V_438 ) ;
if ( ! ( V_115 . V_20 & V_439 ) || F_377 ( V_441 ) )
return NULL ;
V_18 = F_378 ( F_379 ( V_441 ) , V_441 . V_51 ) ;
if ( F_1 () )
V_275 -> V_51 = V_441 . V_51 ;
return V_18 ;
}
static struct V_18 * F_375 ( struct V_435 * V_436 ,
unsigned long V_437 , T_12 V_438 , T_5 * V_275 )
{
return NULL ;
}
static struct V_18 * F_380 ( struct V_435 * V_436 ,
unsigned long V_437 , T_12 V_438 , T_5 * V_275 )
{
struct V_18 * V_18 = NULL ;
struct V_442 * V_443 ;
T_13 V_444 ;
if ( ! V_436 -> V_445 )
return NULL ;
if ( ! ( V_115 . V_20 & V_440 ) )
return NULL ;
V_443 = V_436 -> V_445 -> V_446 ;
V_444 = F_381 ( V_436 , V_437 ) ;
#ifdef F_382
if ( F_383 ( V_443 ) ) {
V_18 = F_384 ( V_443 , V_444 ) ;
if ( F_385 ( V_18 ) ) {
T_5 V_447 = F_386 ( V_18 ) ;
if ( F_1 () )
* V_275 = V_447 ;
V_18 = F_378 ( F_379 ( V_447 ) , V_447 . V_51 ) ;
}
} else
V_18 = F_378 ( V_443 , V_444 ) ;
#else
V_18 = F_378 ( V_443 , V_444 ) ;
#endif
return V_18 ;
}
static int F_387 ( struct V_18 * V_18 ,
bool V_57 ,
struct V_4 * V_113 ,
struct V_4 * V_114 )
{
unsigned long V_20 ;
unsigned int V_41 = V_57 ? F_388 ( V_18 ) : 1 ;
int V_109 ;
bool V_448 ;
F_61 ( V_113 == V_114 ) ;
F_57 ( F_201 ( V_18 ) , V_18 ) ;
F_61 ( V_57 && ! F_58 ( V_18 ) ) ;
V_109 = - V_300 ;
if ( ! F_389 ( V_18 ) )
goto V_98;
V_109 = - V_278 ;
if ( V_18 -> V_4 != V_113 )
goto V_101;
V_448 = F_55 ( V_18 ) ;
F_37 ( & V_113 -> V_201 , V_20 ) ;
if ( ! V_448 && F_373 ( V_18 ) ) {
F_233 ( V_113 -> V_53 -> V_54 [ V_449 ] ,
V_41 ) ;
F_56 ( V_114 -> V_53 -> V_54 [ V_449 ] ,
V_41 ) ;
}
if ( ! V_448 && F_390 ( V_18 ) ) {
struct V_442 * V_443 = F_391 ( V_18 ) ;
if ( F_392 ( V_443 ) ) {
F_233 ( V_113 -> V_53 -> V_54 [ V_382 ] ,
V_41 ) ;
F_56 ( V_114 -> V_53 -> V_54 [ V_382 ] ,
V_41 ) ;
}
}
if ( F_393 ( V_18 ) ) {
F_233 ( V_113 -> V_53 -> V_54 [ V_383 ] ,
V_41 ) ;
F_56 ( V_114 -> V_53 -> V_54 [ V_383 ] ,
V_41 ) ;
}
V_18 -> V_4 = V_114 ;
F_38 ( & V_113 -> V_201 , V_20 ) ;
V_109 = 0 ;
F_394 () ;
F_54 ( V_114 , V_18 , V_57 , V_41 ) ;
F_69 ( V_114 , V_18 ) ;
F_54 ( V_113 , V_18 , V_57 , - V_41 ) ;
F_69 ( V_113 , V_18 ) ;
F_395 () ;
V_101:
F_396 ( V_18 ) ;
V_98:
return V_109 ;
}
static enum V_450 F_397 ( struct V_435 * V_436 ,
unsigned long V_437 , T_12 V_438 , union V_451 * V_71 )
{
struct V_18 * V_18 = NULL ;
enum V_450 V_109 = V_452 ;
T_5 V_441 = { . V_51 = 0 } ;
if ( F_398 ( V_438 ) )
V_18 = F_371 ( V_436 , V_437 , V_438 ) ;
else if ( F_399 ( V_438 ) )
V_18 = F_375 ( V_436 , V_437 , V_438 , & V_441 ) ;
else if ( F_400 ( V_438 ) )
V_18 = F_380 ( V_436 , V_437 , V_438 , & V_441 ) ;
if ( ! V_18 && ! V_441 . V_51 )
return V_109 ;
if ( V_18 ) {
if ( V_18 -> V_4 == V_115 . V_113 ) {
V_109 = V_453 ;
if ( V_71 )
V_71 -> V_18 = V_18 ;
}
if ( ! V_109 || ! V_71 )
F_401 ( V_18 ) ;
}
if ( V_441 . V_51 && ! V_109 &&
F_7 ( V_115 . V_113 ) == F_402 ( V_441 ) ) {
V_109 = V_454 ;
if ( V_71 )
V_71 -> V_441 = V_441 ;
}
return V_109 ;
}
static enum V_450 F_403 ( struct V_435 * V_436 ,
unsigned long V_437 , T_14 V_455 , union V_451 * V_71 )
{
struct V_18 * V_18 = NULL ;
enum V_450 V_109 = V_452 ;
V_18 = F_404 ( V_455 ) ;
F_57 ( ! V_18 || ! F_405 ( V_18 ) , V_18 ) ;
if ( ! ( V_115 . V_20 & V_439 ) )
return V_109 ;
if ( V_18 -> V_4 == V_115 . V_113 ) {
V_109 = V_453 ;
if ( V_71 ) {
F_406 ( V_18 ) ;
V_71 -> V_18 = V_18 ;
}
}
return V_109 ;
}
static inline enum V_450 F_403 ( struct V_435 * V_436 ,
unsigned long V_437 , T_14 V_455 , union V_451 * V_71 )
{
return V_452 ;
}
static int F_407 ( T_14 * V_455 ,
unsigned long V_437 , unsigned long V_456 ,
struct V_457 * V_458 )
{
struct V_435 * V_436 = V_458 -> V_436 ;
T_12 * V_459 ;
T_15 * V_460 ;
V_460 = F_408 ( V_455 , V_436 ) ;
if ( V_460 ) {
if ( F_403 ( V_436 , V_437 , * V_455 , NULL ) == V_453 )
V_115 . V_434 += V_273 ;
F_97 ( V_460 ) ;
return 0 ;
}
if ( F_409 ( V_455 ) )
return 0 ;
V_459 = F_410 ( V_436 -> V_461 , V_455 , V_437 , & V_460 ) ;
for (; V_437 != V_456 ; V_459 ++ , V_437 += V_248 )
if ( F_397 ( V_436 , V_437 , * V_459 , NULL ) )
V_115 . V_434 ++ ;
F_411 ( V_459 - 1 , V_460 ) ;
F_370 () ;
return 0 ;
}
static unsigned long F_412 ( struct V_86 * V_87 )
{
unsigned long V_434 ;
struct V_457 V_462 = {
. V_463 = F_407 ,
. V_87 = V_87 ,
} ;
F_12 ( & V_87 -> V_464 ) ;
F_413 ( 0 , ~ 0UL , & V_462 ) ;
F_14 ( & V_87 -> V_464 ) ;
V_434 = V_115 . V_434 ;
V_115 . V_434 = 0 ;
return V_434 ;
}
static int F_414 ( struct V_86 * V_87 )
{
unsigned long V_434 = F_412 ( V_87 ) ;
F_61 ( V_115 . V_117 ) ;
V_115 . V_117 = V_118 ;
return F_369 ( V_434 ) ;
}
static void F_415 ( void )
{
struct V_4 * V_113 = V_115 . V_113 ;
struct V_4 * V_114 = V_115 . V_114 ;
if ( V_115 . V_434 ) {
F_198 ( V_115 . V_114 , V_115 . V_434 ) ;
V_115 . V_434 = 0 ;
}
if ( V_115 . V_465 ) {
F_198 ( V_115 . V_113 , V_115 . V_465 ) ;
V_115 . V_465 = 0 ;
}
if ( V_115 . V_466 ) {
if ( ! F_6 ( V_115 . V_113 ) )
F_163 ( & V_115 . V_113 -> V_112 , V_115 . V_466 ) ;
if ( ! F_6 ( V_115 . V_114 ) )
F_163 ( & V_115 . V_114 -> V_42 , V_115 . V_466 ) ;
F_164 ( & V_115 . V_113 -> V_9 , V_115 . V_466 ) ;
V_115 . V_466 = 0 ;
}
F_151 ( V_113 ) ;
F_151 ( V_114 ) ;
F_416 ( & V_115 . V_120 ) ;
}
static void F_417 ( void )
{
V_115 . V_117 = NULL ;
F_415 () ;
F_96 ( & V_115 . V_40 ) ;
V_115 . V_113 = NULL ;
V_115 . V_114 = NULL ;
F_97 ( & V_115 . V_40 ) ;
}
static int F_418 ( struct V_467 * V_468 )
{
struct V_7 * V_9 ;
struct V_4 * V_5 = NULL ;
struct V_4 * V_113 ;
struct V_84 * V_469 , * V_31 ;
struct V_86 * V_87 ;
unsigned long V_470 ;
int V_109 = 0 ;
if ( F_2 ( V_1 ) )
return 0 ;
V_31 = NULL ;
F_419 (leader, css, tset) {
F_420 ( V_31 ) ;
V_31 = V_469 ;
V_5 = F_10 ( V_9 ) ;
}
if ( ! V_31 )
return 0 ;
V_470 = F_21 ( V_5 -> V_321 ) ;
if ( ! V_470 )
return 0 ;
V_113 = F_73 ( V_31 ) ;
F_61 ( V_113 == V_5 ) ;
V_87 = F_421 ( V_31 ) ;
if ( ! V_87 )
return 0 ;
if ( V_87 -> V_88 == V_31 ) {
F_61 ( V_115 . V_113 ) ;
F_61 ( V_115 . V_114 ) ;
F_61 ( V_115 . V_434 ) ;
F_61 ( V_115 . V_465 ) ;
F_61 ( V_115 . V_466 ) ;
F_96 ( & V_115 . V_40 ) ;
V_115 . V_113 = V_113 ;
V_115 . V_114 = V_5 ;
V_115 . V_20 = V_470 ;
F_97 ( & V_115 . V_40 ) ;
V_109 = F_414 ( V_87 ) ;
if ( V_109 )
F_417 () ;
}
F_422 ( V_87 ) ;
return V_109 ;
}
static void F_423 ( struct V_467 * V_468 )
{
if ( V_115 . V_114 )
F_417 () ;
}
static int F_424 ( T_14 * V_455 ,
unsigned long V_437 , unsigned long V_456 ,
struct V_457 * V_458 )
{
int V_109 = 0 ;
struct V_435 * V_436 = V_458 -> V_436 ;
T_12 * V_459 ;
T_15 * V_460 ;
enum V_450 V_471 ;
union V_451 V_71 ;
struct V_18 * V_18 ;
V_460 = F_408 ( V_455 , V_436 ) ;
if ( V_460 ) {
if ( V_115 . V_434 < V_273 ) {
F_97 ( V_460 ) ;
return 0 ;
}
V_471 = F_403 ( V_436 , V_437 , * V_455 , & V_71 ) ;
if ( V_471 == V_453 ) {
V_18 = V_71 . V_18 ;
if ( ! F_425 ( V_18 ) ) {
if ( ! F_387 ( V_18 , true ,
V_115 . V_113 , V_115 . V_114 ) ) {
V_115 . V_434 -= V_273 ;
V_115 . V_465 += V_273 ;
}
F_426 ( V_18 ) ;
}
F_401 ( V_18 ) ;
}
F_97 ( V_460 ) ;
return 0 ;
}
if ( F_409 ( V_455 ) )
return 0 ;
V_47:
V_459 = F_410 ( V_436 -> V_461 , V_455 , V_437 , & V_460 ) ;
for (; V_437 != V_456 ; V_437 += V_248 ) {
T_12 V_438 = * ( V_459 ++ ) ;
T_5 V_441 ;
if ( ! V_115 . V_434 )
break;
switch ( F_397 ( V_436 , V_437 , V_438 , & V_71 ) ) {
case V_453 :
V_18 = V_71 . V_18 ;
if ( F_427 ( V_18 ) )
goto V_472;
if ( F_425 ( V_18 ) )
goto V_472;
if ( ! F_387 ( V_18 , false ,
V_115 . V_113 , V_115 . V_114 ) ) {
V_115 . V_434 -- ;
V_115 . V_465 ++ ;
}
F_426 ( V_18 ) ;
V_472:
F_401 ( V_18 ) ;
break;
case V_454 :
V_441 = V_71 . V_441 ;
if ( ! F_236 ( V_441 , V_115 . V_113 , V_115 . V_114 ) ) {
V_115 . V_434 -- ;
V_115 . V_466 ++ ;
}
break;
default:
break;
}
}
F_411 ( V_459 - 1 , V_460 ) ;
F_370 () ;
if ( V_437 != V_456 ) {
V_109 = F_369 ( 1 ) ;
if ( ! V_109 )
goto V_47;
}
return V_109 ;
}
static void F_428 ( struct V_86 * V_87 )
{
struct V_457 V_473 = {
. V_463 = F_424 ,
. V_87 = V_87 ,
} ;
F_246 () ;
F_72 ( & V_115 . V_113 -> V_200 ) ;
F_301 () ;
V_47:
if ( F_70 ( ! F_429 ( & V_87 -> V_464 ) ) ) {
F_415 () ;
F_370 () ;
goto V_47;
}
F_413 ( 0 , ~ 0UL , & V_473 ) ;
F_14 ( & V_87 -> V_464 ) ;
F_430 ( & V_115 . V_113 -> V_200 ) ;
}
static void F_431 ( struct V_467 * V_468 )
{
struct V_7 * V_9 ;
struct V_84 * V_31 = F_432 ( V_468 , & V_9 ) ;
struct V_86 * V_87 = F_421 ( V_31 ) ;
if ( V_87 ) {
if ( V_115 . V_114 )
F_428 ( V_87 ) ;
F_422 ( V_87 ) ;
}
if ( V_115 . V_114 )
F_417 () ;
}
static int F_418 ( struct V_467 * V_468 )
{
return 0 ;
}
static void F_423 ( struct V_467 * V_468 )
{
}
static void F_431 ( struct V_467 * V_468 )
{
}
static void F_433 ( struct V_7 * V_474 )
{
if ( F_2 ( V_1 ) )
V_6 -> V_97 = true ;
else
V_6 -> V_97 = false ;
}
static V_123 F_434 ( struct V_7 * V_9 ,
struct V_296 * V_297 )
{
struct V_4 * V_5 = F_10 ( V_9 ) ;
return ( V_123 ) F_40 ( & V_5 -> V_42 ) * V_248 ;
}
static int F_435 ( struct V_324 * V_325 , void * V_326 )
{
struct V_4 * V_5 = F_10 ( F_283 ( V_325 ) ) ;
unsigned long V_432 = F_21 ( V_5 -> V_432 ) ;
if ( V_432 == V_334 )
F_436 ( V_325 , L_34 ) ;
else
F_285 ( V_325 , L_35 , ( V_123 ) V_432 * V_248 ) ;
return 0 ;
}
static T_6 F_437 ( struct V_291 * V_292 ,
char * V_293 , T_7 V_294 , T_8 V_295 )
{
struct V_4 * V_5 = F_10 ( F_249 ( V_292 ) ) ;
unsigned long V_432 ;
int V_254 ;
V_293 = F_275 ( V_293 ) ;
V_254 = F_276 ( V_293 , L_36 , & V_432 ) ;
if ( V_254 )
return V_254 ;
V_5 -> V_432 = V_432 ;
return V_294 ;
}
static int F_438 ( struct V_324 * V_325 , void * V_326 )
{
struct V_4 * V_5 = F_10 ( F_283 ( V_325 ) ) ;
unsigned long V_224 = F_21 ( V_5 -> V_224 ) ;
if ( V_224 == V_334 )
F_436 ( V_325 , L_34 ) ;
else
F_285 ( V_325 , L_35 , ( V_123 ) V_224 * V_248 ) ;
return 0 ;
}
static T_6 F_439 ( struct V_291 * V_292 ,
char * V_293 , T_7 V_294 , T_8 V_295 )
{
struct V_4 * V_5 = F_10 ( F_249 ( V_292 ) ) ;
unsigned long V_224 ;
int V_254 ;
V_293 = F_275 ( V_293 ) ;
V_254 = F_276 ( V_293 , L_36 , & V_224 ) ;
if ( V_254 )
return V_254 ;
V_5 -> V_224 = V_224 ;
F_319 ( V_5 ) ;
return V_294 ;
}
static int F_440 ( struct V_324 * V_325 , void * V_326 )
{
struct V_4 * V_5 = F_10 ( F_283 ( V_325 ) ) ;
unsigned long F_186 = F_21 ( V_5 -> V_42 . V_111 ) ;
if ( F_186 == V_334 )
F_436 ( V_325 , L_34 ) ;
else
F_285 ( V_325 , L_35 , ( V_123 ) F_186 * V_248 ) ;
return 0 ;
}
static T_6 F_441 ( struct V_291 * V_292 ,
char * V_293 , T_7 V_294 , T_8 V_295 )
{
struct V_4 * V_5 = F_10 ( F_249 ( V_292 ) ) ;
unsigned long F_186 ;
int V_254 ;
V_293 = F_275 ( V_293 ) ;
V_254 = F_276 ( V_293 , L_36 , & F_186 ) ;
if ( V_254 )
return V_254 ;
V_254 = F_238 ( V_5 , F_186 ) ;
if ( V_254 )
return V_254 ;
F_319 ( V_5 ) ;
return V_294 ;
}
static int F_442 ( struct V_324 * V_325 , void * V_326 )
{
struct V_4 * V_5 = F_10 ( F_283 ( V_325 ) ) ;
F_285 ( V_325 , L_37 , F_53 ( V_5 , V_475 ) ) ;
F_285 ( V_325 , L_38 , F_53 ( V_5 , V_225 ) ) ;
F_285 ( V_325 , L_39 , F_53 ( V_5 , V_243 ) ) ;
F_285 ( V_325 , L_40 , F_53 ( V_5 , V_247 ) ) ;
return 0 ;
}
static int F_443 ( struct V_324 * V_325 , void * V_326 )
{
struct V_4 * V_5 = F_10 ( F_283 ( V_325 ) ) ;
int V_104 ;
F_285 ( V_325 , L_41 ,
( V_123 ) F_252 ( V_5 , V_58 ) * V_248 ) ;
F_285 ( V_325 , L_42 ,
( V_123 ) F_252 ( V_5 , V_59 ) * V_248 ) ;
F_285 ( V_325 , L_43 ,
( V_123 ) F_252 ( V_5 , V_476 ) * V_248 ) ;
F_285 ( V_325 , L_44 ,
( V_123 ) F_252 ( V_5 , V_449 ) *
V_248 ) ;
F_285 ( V_325 , L_45 ,
( V_123 ) F_252 ( V_5 , V_382 ) *
V_248 ) ;
F_285 ( V_325 , L_46 ,
( V_123 ) F_252 ( V_5 , V_383 ) *
V_248 ) ;
for ( V_104 = 0 ; V_104 < V_129 ; V_104 ++ ) {
struct V_4 * V_331 ;
unsigned long V_51 = 0 ;
F_111 (mi, memcg)
V_51 += F_64 ( V_331 , F_63 ( V_104 ) ) ;
F_285 ( V_325 , L_47 ,
V_130 [ V_104 ] , ( V_123 ) V_51 * V_248 ) ;
}
F_285 ( V_325 , L_48 ,
F_253 ( V_5 , V_477 ) ) ;
F_285 ( V_325 , L_49 ,
F_253 ( V_5 , V_478 ) ) ;
return 0 ;
}
bool F_444 ( struct V_4 * V_89 , struct V_4 * V_5 )
{
if ( F_78 () )
return false ;
if ( V_5 == V_6 )
return false ;
if ( F_40 ( & V_5 -> V_42 ) >= V_5 -> V_432 )
return false ;
while ( V_5 != V_89 ) {
V_5 = F_22 ( V_5 ) ;
if ( V_5 == V_6 )
break;
if ( F_40 ( & V_5 -> V_42 ) >= V_5 -> V_432 )
return false ;
}
return true ;
}
int F_445 ( struct V_18 * V_18 , struct V_86 * V_87 ,
T_3 V_136 , struct V_4 * * V_479 ,
bool V_57 )
{
struct V_4 * V_5 = NULL ;
unsigned int V_41 = V_57 ? F_388 ( V_18 ) : 1 ;
int V_109 = 0 ;
if ( F_78 () )
goto V_98;
if ( F_446 ( V_18 ) ) {
F_57 ( ! F_447 ( V_18 ) , V_18 ) ;
if ( V_18 -> V_4 )
goto V_98;
if ( V_2 ) {
T_5 V_441 = { . V_51 = F_448 ( V_18 ) , } ;
unsigned short V_10 = F_402 ( V_441 ) ;
F_20 () ;
V_5 = F_8 ( V_10 ) ;
if ( V_5 && ! F_46 ( & V_5 -> V_9 ) )
V_5 = NULL ;
F_24 () ;
}
}
if ( ! V_5 )
V_5 = F_75 ( V_87 ) ;
V_109 = F_185 ( V_5 , V_136 , V_41 ) ;
F_82 ( & V_5 -> V_9 ) ;
V_98:
* V_479 = V_5 ;
return V_109 ;
}
void F_449 ( struct V_18 * V_18 , struct V_4 * V_5 ,
bool V_252 , bool V_57 )
{
unsigned int V_41 = V_57 ? F_388 ( V_18 ) : 1 ;
F_57 ( ! V_18 -> V_443 , V_18 ) ;
F_57 ( F_201 ( V_18 ) && ! V_252 , V_18 ) ;
if ( F_78 () )
return;
if ( ! V_5 )
return;
F_208 ( V_18 , V_5 , V_252 ) ;
F_394 () ;
F_54 ( V_5 , V_18 , V_57 , V_41 ) ;
F_69 ( V_5 , V_18 ) ;
F_395 () ;
if ( F_1 () && F_446 ( V_18 ) ) {
T_5 V_275 = { . V_51 = F_448 (page) } ;
F_450 ( V_275 ) ;
}
}
void F_451 ( struct V_18 * V_18 , struct V_4 * V_5 ,
bool V_57 )
{
unsigned int V_41 = V_57 ? F_388 ( V_18 ) : 1 ;
if ( F_78 () )
return;
if ( ! V_5 )
return;
F_198 ( V_5 , V_41 ) ;
}
static void F_452 ( struct V_4 * V_5 , unsigned long V_480 ,
unsigned long V_481 , unsigned long V_482 ,
unsigned long V_483 , struct V_18 * V_484 )
{
unsigned long V_41 = V_481 + V_482 ;
unsigned long V_20 ;
if ( ! F_6 ( V_5 ) ) {
F_163 ( & V_5 -> V_42 , V_41 ) ;
if ( F_1 () )
F_163 ( & V_5 -> V_112 , V_41 ) ;
F_151 ( V_5 ) ;
}
F_453 ( V_20 ) ;
F_233 ( V_5 -> V_53 -> V_54 [ V_58 ] , V_481 ) ;
F_233 ( V_5 -> V_53 -> V_54 [ V_59 ] , V_482 ) ;
F_233 ( V_5 -> V_53 -> V_54 [ V_60 ] , V_483 ) ;
F_56 ( V_5 -> V_53 -> V_56 [ V_62 ] , V_480 ) ;
F_56 ( V_5 -> V_53 -> V_63 , V_41 ) ;
F_69 ( V_5 , V_484 ) ;
F_454 ( V_20 ) ;
if ( ! F_6 ( V_5 ) )
F_164 ( & V_5 -> V_9 , V_41 ) ;
}
static void F_455 ( struct V_371 * V_485 )
{
struct V_4 * V_5 = NULL ;
unsigned long V_481 = 0 ;
unsigned long V_482 = 0 ;
unsigned long V_483 = 0 ;
unsigned long V_480 = 0 ;
struct V_371 * V_72 ;
struct V_18 * V_18 ;
V_72 = V_485 -> V_72 ;
do {
unsigned int V_41 = 1 ;
V_18 = F_456 ( V_72 , struct V_18 , V_68 ) ;
V_72 = V_18 -> V_68 . V_72 ;
F_57 ( F_201 ( V_18 ) , V_18 ) ;
F_57 ( F_457 ( V_18 ) , V_18 ) ;
if ( ! V_18 -> V_4 )
continue;
if ( V_5 != V_18 -> V_4 ) {
if ( V_5 ) {
F_452 ( V_5 , V_480 , V_481 , V_482 ,
V_483 , V_18 ) ;
V_480 = V_481 = V_482 = V_483 = 0 ;
}
V_5 = V_18 -> V_4 ;
}
if ( F_58 ( V_18 ) ) {
V_41 <<= F_458 ( V_18 ) ;
F_57 ( ! F_58 ( V_18 ) , V_18 ) ;
V_483 += V_41 ;
}
if ( F_55 ( V_18 ) )
V_481 += V_41 ;
else
V_482 += V_41 ;
V_18 -> V_4 = NULL ;
V_480 ++ ;
} while ( V_72 != V_485 );
if ( V_5 )
F_452 ( V_5 , V_480 , V_481 , V_482 ,
V_483 , V_18 ) ;
}
void F_459 ( struct V_18 * V_18 )
{
if ( F_78 () )
return;
if ( ! V_18 -> V_4 )
return;
F_155 ( & V_18 -> V_68 ) ;
F_455 ( & V_18 -> V_68 ) ;
}
void F_460 ( struct V_371 * V_485 )
{
if ( F_78 () )
return;
if ( ! F_327 ( V_485 ) )
F_455 ( V_485 ) ;
}
void F_461 ( struct V_18 * V_486 , struct V_18 * V_487 )
{
struct V_4 * V_5 ;
unsigned int V_41 ;
bool V_57 ;
F_57 ( ! F_447 ( V_486 ) , V_486 ) ;
F_57 ( ! F_447 ( V_487 ) , V_487 ) ;
F_57 ( F_55 ( V_486 ) != F_55 ( V_487 ) , V_487 ) ;
F_57 ( F_58 ( V_486 ) != F_58 ( V_487 ) ,
V_487 ) ;
if ( F_78 () )
return;
if ( V_487 -> V_4 )
return;
V_5 = V_486 -> V_4 ;
if ( ! V_5 )
return;
V_57 = F_58 ( V_487 ) ;
V_41 = V_57 ? F_388 ( V_487 ) : 1 ;
F_193 ( & V_5 -> V_42 , V_41 ) ;
if ( F_1 () )
F_193 ( & V_5 -> V_112 , V_41 ) ;
F_194 ( & V_5 -> V_9 , V_41 ) ;
F_208 ( V_487 , V_5 , true ) ;
F_394 () ;
F_54 ( V_5 , V_487 , V_57 , V_41 ) ;
F_69 ( V_5 , V_487 ) ;
F_395 () ;
}
void F_462 ( struct V_488 * V_489 )
{
struct V_4 * V_5 ;
if ( V_489 -> V_490 ) {
F_260 ( F_6 ( V_489 -> V_490 ) ) ;
F_91 ( & V_489 -> V_490 -> V_9 ) ;
return;
}
F_20 () ;
V_5 = F_73 ( V_118 ) ;
if ( V_5 == V_6 )
goto V_98;
if ( ! F_2 ( V_1 ) && ! V_5 -> V_319 )
goto V_98;
if ( F_46 ( & V_5 -> V_9 ) )
V_489 -> V_490 = V_5 ;
V_98:
F_24 () ;
}
void F_463 ( struct V_488 * V_489 )
{
F_270 ( ! V_489 -> V_490 ) ;
F_82 ( & V_489 -> V_490 -> V_9 ) ;
}
bool F_464 ( struct V_4 * V_5 , unsigned int V_41 )
{
T_3 V_136 = V_227 ;
if ( ! F_2 ( V_1 ) ) {
struct V_233 * V_424 ;
if ( F_187 ( & V_5 -> V_305 , V_41 , & V_424 ) ) {
V_5 -> V_491 = 0 ;
return true ;
}
F_193 ( & V_5 -> V_305 , V_41 ) ;
V_5 -> V_491 = 1 ;
return false ;
}
if ( F_465 () )
V_136 = V_264 ;
F_235 ( V_5 -> V_53 -> V_54 [ V_476 ] , V_41 ) ;
if ( F_185 ( V_5 , V_136 , V_41 ) == 0 )
return true ;
F_185 ( V_5 , V_136 | V_246 , V_41 ) ;
return false ;
}
void F_466 ( struct V_4 * V_5 , unsigned int V_41 )
{
if ( ! F_2 ( V_1 ) ) {
F_163 ( & V_5 -> V_305 , V_41 ) ;
return;
}
F_467 ( V_5 -> V_53 -> V_54 [ V_476 ] , V_41 ) ;
F_163 ( & V_5 -> V_42 , V_41 ) ;
F_164 ( & V_5 -> V_9 , V_41 ) ;
}
static int T_16 F_468 ( char * V_492 )
{
char * V_493 ;
while ( ( V_493 = F_469 ( & V_492 , L_50 ) ) != NULL ) {
if ( ! * V_493 )
continue;
if ( ! strcmp ( V_493 , L_51 ) )
V_429 = true ;
if ( ! strcmp ( V_493 , L_52 ) )
V_316 = true ;
}
return 0 ;
}
static int T_16 F_470 ( void )
{
int V_52 , V_162 ;
F_471 ( F_178 , 0 ) ;
F_51 (cpu)
F_222 ( & F_472 ( & V_207 , V_52 ) -> V_215 ,
F_165 ) ;
F_43 (node) {
struct V_494 * V_495 ;
int V_13 ;
V_495 = F_346 ( sizeof( * V_495 ) , V_227 ,
F_473 ( V_162 ) ? V_162 : V_496 ) ;
for ( V_13 = 0 ; V_13 < V_45 ; V_13 ++ ) {
struct V_23 * V_497 ;
V_497 = & V_495 -> V_26 [ V_13 ] ;
V_497 -> V_32 = V_498 ;
F_354 ( & V_497 -> V_40 ) ;
}
V_24 . V_25 [ V_162 ] = V_495 ;
}
return 0 ;
}
void F_474 ( struct V_18 * V_18 , T_5 V_275 )
{
struct V_4 * V_5 ;
unsigned short V_499 ;
F_57 ( F_201 ( V_18 ) , V_18 ) ;
F_57 ( F_457 ( V_18 ) , V_18 ) ;
if ( ! F_1 () )
return;
V_5 = V_18 -> V_4 ;
if ( ! V_5 )
return;
V_499 = F_475 ( V_275 , F_7 ( V_5 ) ) ;
F_57 ( V_499 , V_18 ) ;
F_234 ( V_5 , true ) ;
V_18 -> V_4 = NULL ;
if ( ! F_6 ( V_5 ) )
F_163 ( & V_5 -> V_42 , 1 ) ;
F_61 ( ! F_476 () ) ;
F_54 ( V_5 , V_18 , false , - 1 ) ;
F_69 ( V_5 , V_18 ) ;
}
int F_477 ( struct V_18 * V_18 , T_5 V_275 )
{
struct V_4 * V_5 ;
struct V_233 * V_234 ;
unsigned short V_499 ;
if ( ! F_2 ( V_1 ) || ! V_2 )
return 0 ;
V_5 = V_18 -> V_4 ;
if ( ! V_5 )
return 0 ;
if ( ! F_6 ( V_5 ) &&
! F_187 ( & V_5 -> V_134 , 1 , & V_234 ) )
return - V_249 ;
V_499 = F_475 ( V_275 , F_7 ( V_5 ) ) ;
F_57 ( V_499 , V_18 ) ;
F_234 ( V_5 , true ) ;
F_91 ( & V_5 -> V_9 ) ;
return 0 ;
}
void F_450 ( T_5 V_275 )
{
struct V_4 * V_5 ;
unsigned short V_10 ;
if ( ! V_2 )
return;
V_10 = F_475 ( V_275 , 0 ) ;
F_20 () ;
V_5 = F_8 ( V_10 ) ;
if ( V_5 ) {
if ( ! F_6 ( V_5 ) ) {
if ( F_2 ( V_1 ) )
F_163 ( & V_5 -> V_134 , 1 ) ;
else
F_163 ( & V_5 -> V_112 , 1 ) ;
}
F_234 ( V_5 , false ) ;
F_82 ( & V_5 -> V_9 ) ;
}
F_24 () ;
}
long F_478 ( struct V_4 * V_5 )
{
long V_500 = F_479 () ;
if ( ! V_2 || ! F_2 ( V_1 ) )
return V_500 ;
for (; V_5 != V_6 ; V_5 = F_22 ( V_5 ) )
V_500 = F_480 ( long , V_500 ,
F_21 ( V_5 -> V_134 . V_111 ) -
F_40 ( & V_5 -> V_134 ) ) ;
return V_500 ;
}
bool F_481 ( struct V_18 * V_18 )
{
struct V_4 * V_5 ;
F_57 ( ! F_447 ( V_18 ) , V_18 ) ;
if ( F_482 () )
return true ;
if ( ! V_2 || ! F_2 ( V_1 ) )
return false ;
V_5 = V_18 -> V_4 ;
if ( ! V_5 )
return false ;
for (; V_5 != V_6 ; V_5 = F_22 ( V_5 ) )
if ( F_40 ( & V_5 -> V_134 ) * 2 >= V_5 -> V_134 . V_111 )
return true ;
return false ;
}
static int T_16 F_483 ( char * V_492 )
{
if ( ! strcmp ( V_492 , L_53 ) )
V_501 = 1 ;
else if ( ! strcmp ( V_492 , L_54 ) )
V_501 = 0 ;
return 1 ;
}
static V_123 F_484 ( struct V_7 * V_9 ,
struct V_296 * V_297 )
{
struct V_4 * V_5 = F_10 ( V_9 ) ;
return ( V_123 ) F_40 ( & V_5 -> V_134 ) * V_248 ;
}
static int F_485 ( struct V_324 * V_325 , void * V_326 )
{
struct V_4 * V_5 = F_10 ( F_283 ( V_325 ) ) ;
unsigned long F_186 = F_21 ( V_5 -> V_134 . V_111 ) ;
if ( F_186 == V_334 )
F_436 ( V_325 , L_34 ) ;
else
F_285 ( V_325 , L_35 , ( V_123 ) F_186 * V_248 ) ;
return 0 ;
}
static T_6 F_486 ( struct V_291 * V_292 ,
char * V_293 , T_7 V_294 , T_8 V_295 )
{
struct V_4 * V_5 = F_10 ( F_249 ( V_292 ) ) ;
unsigned long F_186 ;
int V_254 ;
V_293 = F_275 ( V_293 ) ;
V_254 = F_276 ( V_293 , L_36 , & F_186 ) ;
if ( V_254 )
return V_254 ;
F_105 ( & V_284 ) ;
V_254 = F_240 ( & V_5 -> V_134 , F_186 ) ;
F_112 ( & V_284 ) ;
if ( V_254 )
return V_254 ;
return V_294 ;
}
static int T_16 F_487 ( void )
{
if ( ! F_78 () && V_501 ) {
V_2 = 1 ;
F_270 ( F_488 ( & V_1 ,
V_502 ) ) ;
F_270 ( F_489 ( & V_1 ,
V_503 ) ) ;
}
return 0 ;
}
