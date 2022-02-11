static inline int F_1 ( struct V_1 * V_2 )
{
unsigned V_3 = V_2 -> V_4 - 1 ;
F_2 ( V_3 >= F_3 ( V_5 ) ) ;
return V_3 ;
}
static void F_4 ( struct V_1 * V_2 )
{
F_5 ( & V_2 -> V_6 , F_6 () ) ;
}
static int F_7 ( struct V_1 * V_2 )
{
return F_8 ( & V_2 -> V_6 ) ;
}
static void F_9 ( struct V_1 * V_2 )
{
F_10 ( & V_2 -> V_6 ) ;
}
static void F_11 ( struct V_7 * V_8 )
{
V_8 -> V_9 . V_10 = 0 ;
V_8 -> V_9 . V_11 = V_12 ;
V_8 -> V_9 . V_13 = V_8 -> V_14 ;
V_8 -> V_9 . V_15 = 2 ;
F_12 ( & V_8 -> V_9 ) ;
}
static struct V_7 * F_13 ( struct V_1 * V_2 , T_1 V_16 )
{
struct V_17 * V_18 = V_2 -> V_19 . V_17 ;
struct V_7 * V_8 ;
while ( V_18 ) {
V_8 = F_14 ( V_18 , struct V_7 , V_20 ) ;
if ( V_8 -> V_16 == V_16 )
return V_8 ;
V_18 = ( V_8 -> V_16 < V_16 ) ? V_18 -> V_21 : V_18 -> V_22 ;
}
return NULL ;
}
static void F_15 ( struct V_1 * V_2 , struct V_7 * V_8 )
{
struct V_17 * * V_23 = & V_2 -> V_19 . V_17 , * V_24 = NULL ;
struct V_7 * V_25 ;
while ( * V_23 ) {
V_25 = F_14 ( * V_23 , struct V_7 , V_20 ) ;
if ( V_25 -> V_16 == V_8 -> V_16 ) {
F_2 ( V_25 != V_8 ) ;
return;
}
V_24 = * V_23 ;
V_23 = ( V_25 -> V_16 < V_8 -> V_16 ) ?
& ( ( * V_23 ) -> V_21 ) : & ( ( * V_23 ) -> V_22 ) ;
}
F_16 ( & V_8 -> V_20 , V_24 , V_23 ) ;
F_17 ( & V_8 -> V_20 , & V_2 -> V_19 ) ;
}
static void F_18 ( struct V_1 * V_2 , struct V_7 * V_8 )
{
F_19 ( & V_8 -> V_20 , & V_2 -> V_19 ) ;
}
static void F_20 ( enum V_26 V_26 , long V_27 )
{
static unsigned long * const V_28 [ V_29 ] = {
& V_30 ,
& V_31 ,
& V_32 ,
} ;
F_21 ( & V_33 ) ;
* V_28 [ V_26 ] += V_27 ;
V_34 += V_27 ;
if ( V_34 > V_35 )
V_35 = V_34 ;
F_22 ( & V_33 ) ;
}
static void F_23 ( void )
{
F_2 ( ! F_24 ( & V_36 ) ) ;
F_2 ( V_37 < 0 ) ;
V_38 = F_25 ( V_39 ) ;
if ( ! V_38 ) {
( void ) F_26 ( & V_39 , 0 ,
V_40 ) ;
V_38 = V_40 ;
}
V_41 = V_38 /
( V_37 ? : 1 ) ;
}
static void * F_27 ( struct V_1 * V_2 , T_2 V_42 ,
enum V_26 * V_26 )
{
unsigned V_43 ;
void * V_44 ;
if ( V_2 -> V_45 <= V_46 ) {
* V_26 = V_47 ;
return F_28 ( F_29 ( V_2 ) , V_42 ) ;
}
if ( V_2 -> V_45 <= V_48 &&
V_42 & V_49 ) {
* V_26 = V_50 ;
return ( void * ) F_30 ( V_42 ,
V_2 -> V_51 ) ;
}
* V_26 = V_52 ;
if ( V_42 & V_49 )
V_43 = F_31 () ;
V_44 = F_32 ( V_2 -> V_45 , V_42 , V_53 ) ;
if ( V_42 & V_49 )
F_33 ( V_43 ) ;
return V_44 ;
}
static void F_34 ( struct V_1 * V_2 ,
void * V_54 , enum V_26 V_26 )
{
switch ( V_26 ) {
case V_47 :
F_35 ( F_29 ( V_2 ) , V_54 ) ;
break;
case V_50 :
F_36 ( ( unsigned long ) V_54 , V_2 -> V_51 ) ;
break;
case V_52 :
F_37 ( V_54 ) ;
break;
default:
F_38 ( L_1 ,
V_26 ) ;
F_39 () ;
}
}
static struct V_7 * F_40 ( struct V_1 * V_2 , T_2 V_42 )
{
struct V_7 * V_8 = F_41 ( sizeof( struct V_7 ) + V_2 -> V_55 ,
V_42 ) ;
if ( ! V_8 )
return NULL ;
V_8 -> V_2 = V_2 ;
V_8 -> V_54 = F_27 ( V_2 , V_42 , & V_8 -> V_26 ) ;
if ( ! V_8 -> V_54 ) {
F_42 ( V_8 ) ;
return NULL ;
}
F_20 ( V_8 -> V_26 , ( long ) V_2 -> V_45 ) ;
#ifdef F_43
memset ( & V_8 -> V_9 , 0 , sizeof( V_8 -> V_9 ) ) ;
#endif
return V_8 ;
}
static void F_44 ( struct V_7 * V_8 )
{
struct V_1 * V_2 = V_8 -> V_2 ;
F_20 ( V_8 -> V_26 , - ( long ) V_2 -> V_45 ) ;
F_34 ( V_2 , V_8 -> V_54 , V_8 -> V_26 ) ;
F_42 ( V_8 ) ;
}
static void F_45 ( struct V_7 * V_8 , T_1 V_16 , int V_56 )
{
struct V_1 * V_2 = V_8 -> V_2 ;
V_2 -> V_57 [ V_56 ] ++ ;
V_8 -> V_16 = V_16 ;
V_8 -> V_58 = V_56 ;
F_46 ( & V_8 -> V_59 , & V_2 -> V_60 [ V_56 ] ) ;
F_15 ( V_8 -> V_2 , V_8 ) ;
V_8 -> V_61 = V_62 ;
}
static void F_47 ( struct V_7 * V_8 )
{
struct V_1 * V_2 = V_8 -> V_2 ;
F_2 ( ! V_2 -> V_57 [ V_8 -> V_58 ] ) ;
V_2 -> V_57 [ V_8 -> V_58 ] -- ;
F_18 ( V_8 -> V_2 , V_8 ) ;
F_48 ( & V_8 -> V_59 ) ;
}
static void F_49 ( struct V_7 * V_8 , int V_56 )
{
struct V_1 * V_2 = V_8 -> V_2 ;
F_2 ( ! V_2 -> V_57 [ V_8 -> V_58 ] ) ;
V_2 -> V_57 [ V_8 -> V_58 ] -- ;
V_2 -> V_57 [ V_56 ] ++ ;
V_8 -> V_58 = V_56 ;
F_50 ( & V_8 -> V_59 , & V_2 -> V_60 [ V_56 ] ) ;
V_8 -> V_61 = V_62 ;
}
static void F_51 ( unsigned long error , void * V_63 )
{
struct V_7 * V_8 = V_63 ;
V_8 -> V_64 . V_65 = error ? V_66 : 0 ;
V_8 -> V_64 . V_67 ( & V_8 -> V_64 ) ;
}
static void F_52 ( struct V_7 * V_8 , int V_68 , T_1 V_69 ,
unsigned V_70 , T_3 * V_71 )
{
int V_72 ;
struct V_73 V_74 = {
. V_75 = V_68 ,
. V_76 = 0 ,
. V_77 . V_78 = F_51 ,
. V_77 . V_63 = V_8 ,
. V_79 = V_8 -> V_2 -> V_80 ,
} ;
struct V_81 V_82 = {
. V_83 = V_8 -> V_2 -> V_83 ,
. V_69 = V_69 ,
. V_84 = V_70 ,
} ;
if ( V_8 -> V_26 != V_52 ) {
V_74 . V_85 . type = V_86 ;
V_74 . V_85 . V_44 . V_87 = V_8 -> V_54 ;
} else {
V_74 . V_85 . type = V_88 ;
V_74 . V_85 . V_44 . V_89 = V_8 -> V_54 ;
}
V_8 -> V_64 . V_67 = V_71 ;
V_72 = V_80 ( & V_74 , 1 , & V_82 , NULL ) ;
if ( V_72 ) {
V_8 -> V_64 . V_65 = F_53 ( V_72 ) ;
V_71 ( & V_8 -> V_64 ) ;
}
}
static void F_54 ( struct V_64 * V_64 )
{
T_3 * V_90 = V_64 -> V_91 ;
T_4 V_92 = V_64 -> V_65 ;
F_55 ( V_64 ) ;
V_64 -> V_65 = V_92 ;
V_90 ( V_64 ) ;
}
static void F_56 ( struct V_7 * V_8 , int V_68 , T_1 V_69 ,
unsigned V_70 , T_3 * V_71 )
{
char * V_44 ;
int V_93 ;
F_57 ( & V_8 -> V_64 , V_8 -> V_94 , V_95 ) ;
V_8 -> V_64 . V_96 . V_97 = V_69 ;
V_8 -> V_64 . V_98 = V_8 -> V_2 -> V_83 ;
V_8 -> V_64 . V_67 = F_54 ;
V_8 -> V_64 . V_91 = V_71 ;
F_58 ( & V_8 -> V_64 , V_68 , 0 ) ;
V_44 = V_8 -> V_54 ;
V_93 = V_70 << V_99 ;
if ( V_93 >= V_100 )
F_2 ( ( unsigned long ) V_44 & ( V_100 - 1 ) ) ;
else
F_2 ( ( unsigned long ) V_44 & ( V_93 - 1 ) ) ;
do {
if ( ! F_59 ( & V_8 -> V_64 , F_60 ( V_44 ) ,
V_93 < V_100 ? V_93 : V_100 ,
F_61 ( V_44 ) ) ) {
F_2 ( V_8 -> V_2 -> V_45 <= V_100 ) ;
F_52 ( V_8 , V_68 , V_69 , V_70 , V_71 ) ;
return;
}
V_93 -= V_100 ;
V_44 += V_100 ;
} while ( V_93 > 0 );
F_62 ( & V_8 -> V_64 ) ;
}
static void F_63 ( struct V_7 * V_8 , int V_68 , T_3 * V_71 )
{
unsigned V_70 ;
T_1 V_69 ;
if ( V_68 == V_101 && V_8 -> V_2 -> V_102 )
V_8 -> V_2 -> V_102 ( V_8 ) ;
V_69 = ( V_8 -> V_16 << V_8 -> V_2 -> V_103 ) + V_8 -> V_2 -> V_104 ;
V_70 = 1 << V_8 -> V_2 -> V_103 ;
if ( V_70 <= ( ( V_95 * V_100 ) >> V_99 ) &&
V_8 -> V_26 != V_52 )
F_56 ( V_8 , V_68 , V_69 , V_70 , V_71 ) ;
else
F_52 ( V_8 , V_68 , V_69 , V_70 , V_71 ) ;
}
static void F_64 ( struct V_64 * V_64 )
{
struct V_7 * V_8 = F_14 ( V_64 , struct V_7 , V_64 ) ;
V_8 -> V_105 = V_64 -> V_65 ;
if ( F_65 ( V_64 -> V_65 ) ) {
struct V_1 * V_2 = V_8 -> V_2 ;
( void ) F_26 ( & V_2 -> V_106 , 0 ,
F_66 ( V_64 -> V_65 ) ) ;
}
F_2 ( ! F_67 ( V_107 , & V_8 -> V_108 ) ) ;
F_68 () ;
F_69 ( V_107 , & V_8 -> V_108 ) ;
F_70 () ;
F_71 ( & V_8 -> V_108 , V_107 ) ;
}
static void F_72 ( struct V_7 * V_8 ,
struct V_109 * V_110 )
{
if ( ! F_67 ( V_111 , & V_8 -> V_108 ) )
return;
F_69 ( V_111 , & V_8 -> V_108 ) ;
F_73 ( & V_8 -> V_108 , V_107 , V_112 ) ;
if ( ! V_110 )
F_63 ( V_8 , V_101 , F_64 ) ;
else
F_74 ( & V_8 -> V_110 , V_110 ) ;
}
static void F_75 ( struct V_109 * V_110 )
{
struct V_113 V_114 ;
F_76 ( & V_114 ) ;
while ( ! F_77 ( V_110 ) ) {
struct V_7 * V_8 =
F_78 ( V_110 -> V_115 , struct V_7 , V_110 ) ;
F_48 ( & V_8 -> V_110 ) ;
F_63 ( V_8 , V_101 , F_64 ) ;
F_79 () ;
}
F_80 ( & V_114 ) ;
}
static void F_81 ( struct V_7 * V_8 )
{
F_2 ( V_8 -> V_116 ) ;
if ( ! V_8 -> V_108 )
return;
F_82 ( & V_8 -> V_108 , V_117 , V_112 ) ;
F_72 ( V_8 , NULL ) ;
F_82 ( & V_8 -> V_108 , V_107 , V_112 ) ;
}
static struct V_7 * F_83 ( struct V_1 * V_2 )
{
struct V_7 * V_8 ;
F_84 (b, &c->lru[LIST_CLEAN], lru_list) {
F_2 ( F_67 ( V_107 , & V_8 -> V_108 ) ) ;
F_2 ( F_67 ( V_111 , & V_8 -> V_108 ) ) ;
if ( ! V_8 -> V_116 ) {
F_81 ( V_8 ) ;
F_47 ( V_8 ) ;
return V_8 ;
}
F_79 () ;
}
F_84 (b, &c->lru[LIST_DIRTY], lru_list) {
F_2 ( F_67 ( V_117 , & V_8 -> V_108 ) ) ;
if ( ! V_8 -> V_116 ) {
F_81 ( V_8 ) ;
F_47 ( V_8 ) ;
return V_8 ;
}
F_79 () ;
}
return NULL ;
}
static void F_85 ( struct V_1 * V_2 )
{
F_86 ( V_118 , V_119 ) ;
F_87 ( & V_2 -> V_120 , & V_118 ) ;
F_88 ( V_112 ) ;
F_9 ( V_2 ) ;
F_89 () ;
F_90 ( & V_2 -> V_120 , & V_118 ) ;
F_4 ( V_2 ) ;
}
static struct V_7 * F_91 ( struct V_1 * V_2 , enum V_121 V_122 )
{
struct V_7 * V_8 ;
bool V_123 = false ;
while ( 1 ) {
if ( V_38 != 1 ) {
V_8 = F_40 ( V_2 , V_124 | V_49 | V_125 | V_126 ) ;
if ( V_8 )
return V_8 ;
}
if ( V_122 == V_127 )
return NULL ;
if ( V_38 != 1 && ! V_123 ) {
F_9 ( V_2 ) ;
V_8 = F_40 ( V_2 , V_128 | V_49 | V_125 | V_126 ) ;
F_4 ( V_2 ) ;
if ( V_8 )
return V_8 ;
V_123 = true ;
}
if ( ! F_77 ( & V_2 -> V_129 ) ) {
V_8 = F_78 ( V_2 -> V_129 . V_115 ,
struct V_7 , V_59 ) ;
F_48 ( & V_8 -> V_59 ) ;
V_2 -> V_130 ++ ;
return V_8 ;
}
V_8 = F_83 ( V_2 ) ;
if ( V_8 )
return V_8 ;
F_85 ( V_2 ) ;
}
}
static struct V_7 * F_92 ( struct V_1 * V_2 , enum V_121 V_122 )
{
struct V_7 * V_8 = F_91 ( V_2 , V_122 ) ;
if ( ! V_8 )
return NULL ;
if ( V_2 -> V_131 )
V_2 -> V_131 ( V_8 ) ;
return V_8 ;
}
static void F_93 ( struct V_7 * V_8 )
{
struct V_1 * V_2 = V_8 -> V_2 ;
if ( ! V_2 -> V_130 )
F_44 ( V_8 ) ;
else {
F_46 ( & V_8 -> V_59 , & V_2 -> V_129 ) ;
V_2 -> V_130 -- ;
}
F_94 ( & V_2 -> V_120 ) ;
}
static void F_95 ( struct V_1 * V_2 , int V_132 ,
struct V_109 * V_110 )
{
struct V_7 * V_8 , * V_133 ;
F_96 (b, tmp, &c->lru[LIST_DIRTY], lru_list) {
F_2 ( F_67 ( V_117 , & V_8 -> V_108 ) ) ;
if ( ! F_67 ( V_111 , & V_8 -> V_108 ) &&
! F_67 ( V_107 , & V_8 -> V_108 ) ) {
F_49 ( V_8 , V_134 ) ;
continue;
}
if ( V_132 && F_67 ( V_107 , & V_8 -> V_108 ) )
return;
F_72 ( V_8 , V_110 ) ;
F_79 () ;
}
}
static void F_97 ( struct V_1 * V_2 ,
unsigned long * V_135 ,
unsigned long * V_136 )
{
unsigned long V_137 ;
if ( F_65 ( F_25 ( V_39 ) != V_38 ) ) {
if ( F_8 ( & V_36 ) ) {
F_23 () ;
F_10 ( & V_36 ) ;
}
}
V_137 = V_41 >>
( V_2 -> V_103 + V_99 ) ;
if ( V_137 < V_2 -> V_138 )
V_137 = V_2 -> V_138 ;
* V_136 = V_137 ;
* V_135 = V_137 * V_139 / 100 ;
}
static void F_98 ( struct V_1 * V_2 ,
struct V_109 * V_110 )
{
unsigned long V_135 , V_136 ;
F_97 ( V_2 , & V_135 , & V_136 ) ;
while ( V_2 -> V_57 [ V_134 ] + V_2 -> V_57 [ V_140 ] >
V_136 ) {
struct V_7 * V_8 = F_83 ( V_2 ) ;
if ( ! V_8 )
return;
F_93 ( V_8 ) ;
F_79 () ;
}
if ( V_2 -> V_57 [ V_140 ] > V_135 )
F_95 ( V_2 , 1 , V_110 ) ;
}
static struct V_7 * F_99 ( struct V_1 * V_2 , T_1 V_16 ,
enum V_121 V_122 , int * V_141 ,
struct V_109 * V_110 )
{
struct V_7 * V_8 , * V_142 = NULL ;
* V_141 = 0 ;
V_8 = F_13 ( V_2 , V_16 ) ;
if ( V_8 )
goto V_143;
if ( V_122 == V_144 )
return NULL ;
V_142 = F_92 ( V_2 , V_122 ) ;
if ( ! V_142 )
return NULL ;
V_8 = F_13 ( V_2 , V_16 ) ;
if ( V_8 ) {
F_93 ( V_142 ) ;
goto V_143;
}
F_98 ( V_2 , V_110 ) ;
V_8 = V_142 ;
V_8 -> V_116 = 1 ;
V_8 -> V_145 = 0 ;
V_8 -> V_105 = 0 ;
F_45 ( V_8 , V_16 , V_134 ) ;
if ( V_122 == V_146 ) {
V_8 -> V_108 = 0 ;
return V_8 ;
}
V_8 -> V_108 = 1 << V_117 ;
* V_141 = 1 ;
return V_8 ;
V_143:
if ( V_122 == V_127 )
return NULL ;
if ( V_122 == V_144 && F_65 ( F_67 ( V_117 , & V_8 -> V_108 ) ) )
return NULL ;
V_8 -> V_116 ++ ;
F_49 ( V_8 , F_67 ( V_111 , & V_8 -> V_108 ) ||
F_67 ( V_107 , & V_8 -> V_108 ) ) ;
return V_8 ;
}
static void F_100 ( struct V_64 * V_64 )
{
struct V_7 * V_8 = F_14 ( V_64 , struct V_7 , V_64 ) ;
V_8 -> V_145 = V_64 -> V_65 ;
F_2 ( ! F_67 ( V_117 , & V_8 -> V_108 ) ) ;
F_68 () ;
F_69 ( V_117 , & V_8 -> V_108 ) ;
F_70 () ;
F_71 ( & V_8 -> V_108 , V_117 ) ;
}
static void * F_101 ( struct V_1 * V_2 , T_1 V_16 ,
enum V_121 V_122 , struct V_7 * * V_147 )
{
int V_141 ;
struct V_7 * V_8 ;
F_102 ( V_110 ) ;
F_4 ( V_2 ) ;
V_8 = F_99 ( V_2 , V_16 , V_122 , & V_141 , & V_110 ) ;
#ifdef F_43
if ( V_8 && V_8 -> V_116 == 1 )
F_11 ( V_8 ) ;
#endif
F_9 ( V_2 ) ;
F_75 ( & V_110 ) ;
if ( ! V_8 )
return NULL ;
if ( V_141 )
F_63 ( V_8 , V_148 , F_100 ) ;
F_82 ( & V_8 -> V_108 , V_117 , V_112 ) ;
if ( V_8 -> V_145 ) {
int error = F_66 ( V_8 -> V_145 ) ;
F_103 ( V_8 ) ;
return F_104 ( error ) ;
}
* V_147 = V_8 ;
return V_8 -> V_54 ;
}
void * F_105 ( struct V_1 * V_2 , T_1 V_16 ,
struct V_7 * * V_147 )
{
return F_101 ( V_2 , V_16 , V_144 , V_147 ) ;
}
void * F_106 ( struct V_1 * V_2 , T_1 V_16 ,
struct V_7 * * V_147 )
{
F_2 ( F_6 () ) ;
return F_101 ( V_2 , V_16 , V_149 , V_147 ) ;
}
void * F_107 ( struct V_1 * V_2 , T_1 V_16 ,
struct V_7 * * V_147 )
{
F_2 ( F_6 () ) ;
return F_101 ( V_2 , V_16 , V_146 , V_147 ) ;
}
void F_108 ( struct V_1 * V_2 ,
T_1 V_16 , unsigned V_150 )
{
struct V_113 V_114 ;
F_102 ( V_110 ) ;
F_2 ( F_6 () ) ;
F_76 ( & V_114 ) ;
F_4 ( V_2 ) ;
for (; V_150 -- ; V_16 ++ ) {
int V_141 ;
struct V_7 * V_8 ;
V_8 = F_99 ( V_2 , V_16 , V_127 , & V_141 ,
& V_110 ) ;
if ( F_65 ( ! F_77 ( & V_110 ) ) ) {
F_9 ( V_2 ) ;
F_80 ( & V_114 ) ;
F_75 ( & V_110 ) ;
F_76 ( & V_114 ) ;
F_4 ( V_2 ) ;
}
if ( F_65 ( V_8 != NULL ) ) {
F_9 ( V_2 ) ;
if ( V_141 )
F_63 ( V_8 , V_148 , F_100 ) ;
F_103 ( V_8 ) ;
F_79 () ;
if ( ! V_150 )
goto V_151;
F_4 ( V_2 ) ;
}
}
F_9 ( V_2 ) ;
V_151:
F_80 ( & V_114 ) ;
}
void F_103 ( struct V_7 * V_8 )
{
struct V_1 * V_2 = V_8 -> V_2 ;
F_4 ( V_2 ) ;
F_2 ( ! V_8 -> V_116 ) ;
V_8 -> V_116 -- ;
if ( ! V_8 -> V_116 ) {
F_94 ( & V_2 -> V_120 ) ;
if ( ( V_8 -> V_145 || V_8 -> V_105 ) &&
! F_67 ( V_117 , & V_8 -> V_108 ) &&
! F_67 ( V_107 , & V_8 -> V_108 ) &&
! F_67 ( V_111 , & V_8 -> V_108 ) ) {
F_47 ( V_8 ) ;
F_93 ( V_8 ) ;
}
}
F_9 ( V_2 ) ;
}
void F_109 ( struct V_7 * V_8 )
{
struct V_1 * V_2 = V_8 -> V_2 ;
F_4 ( V_2 ) ;
F_2 ( F_67 ( V_117 , & V_8 -> V_108 ) ) ;
if ( ! F_110 ( V_111 , & V_8 -> V_108 ) )
F_49 ( V_8 , V_140 ) ;
F_9 ( V_2 ) ;
}
void F_111 ( struct V_1 * V_2 )
{
F_102 ( V_110 ) ;
F_2 ( F_6 () ) ;
F_4 ( V_2 ) ;
F_95 ( V_2 , 0 , & V_110 ) ;
F_9 ( V_2 ) ;
F_75 ( & V_110 ) ;
}
int F_112 ( struct V_1 * V_2 )
{
int V_152 , V_153 ;
unsigned long V_154 = 0 ;
struct V_7 * V_8 , * V_133 ;
F_102 ( V_110 ) ;
F_4 ( V_2 ) ;
F_95 ( V_2 , 0 , & V_110 ) ;
F_9 ( V_2 ) ;
F_75 ( & V_110 ) ;
F_4 ( V_2 ) ;
V_155:
F_96 (b, tmp, &c->lru[LIST_DIRTY], lru_list) {
int V_156 = 0 ;
if ( V_154 < V_2 -> V_57 [ V_140 ] )
V_154 ++ ;
F_2 ( F_67 ( V_117 , & V_8 -> V_108 ) ) ;
if ( F_67 ( V_107 , & V_8 -> V_108 ) ) {
if ( V_154 < V_2 -> V_57 [ V_140 ] ) {
V_156 = 1 ;
V_8 -> V_116 ++ ;
F_9 ( V_2 ) ;
F_82 ( & V_8 -> V_108 , V_107 ,
V_112 ) ;
F_4 ( V_2 ) ;
V_8 -> V_116 -- ;
} else
F_82 ( & V_8 -> V_108 , V_107 ,
V_112 ) ;
}
if ( ! F_67 ( V_111 , & V_8 -> V_108 ) &&
! F_67 ( V_107 , & V_8 -> V_108 ) )
F_49 ( V_8 , V_134 ) ;
F_79 () ;
if ( V_156 )
goto V_155;
}
F_94 ( & V_2 -> V_120 ) ;
F_9 ( V_2 ) ;
V_152 = F_113 ( & V_2 -> V_106 , 0 ) ;
V_153 = F_114 ( V_2 ) ;
if ( V_152 )
return V_152 ;
return V_153 ;
}
int F_114 ( struct V_1 * V_2 )
{
struct V_73 V_74 = {
. V_75 = V_157 ,
. V_76 = V_158 | V_159 ,
. V_85 . type = V_86 ,
. V_85 . V_44 . V_87 = NULL ,
. V_79 = V_2 -> V_80 ,
} ;
struct V_81 V_160 = {
. V_83 = V_2 -> V_83 ,
. V_69 = 0 ,
. V_84 = 0 ,
} ;
F_2 ( F_6 () ) ;
return V_80 ( & V_74 , 1 , & V_160 , NULL ) ;
}
void F_115 ( struct V_7 * V_8 , T_1 V_161 )
{
struct V_1 * V_2 = V_8 -> V_2 ;
struct V_7 * V_23 ;
F_2 ( F_6 () ) ;
F_4 ( V_2 ) ;
V_162:
V_23 = F_13 ( V_2 , V_161 ) ;
if ( V_23 ) {
if ( V_23 -> V_116 ) {
F_85 ( V_2 ) ;
goto V_162;
}
F_81 ( V_23 ) ;
F_47 ( V_23 ) ;
F_93 ( V_23 ) ;
}
F_2 ( ! V_8 -> V_116 ) ;
F_2 ( F_67 ( V_117 , & V_8 -> V_108 ) ) ;
F_72 ( V_8 , NULL ) ;
if ( V_8 -> V_116 == 1 ) {
F_82 ( & V_8 -> V_108 , V_107 ,
V_112 ) ;
F_116 ( V_111 , & V_8 -> V_108 ) ;
F_47 ( V_8 ) ;
F_45 ( V_8 , V_161 , V_140 ) ;
} else {
T_1 V_163 ;
F_73 ( & V_8 -> V_108 , V_107 ,
V_112 ) ;
V_163 = V_8 -> V_16 ;
F_47 ( V_8 ) ;
F_45 ( V_8 , V_161 , V_8 -> V_58 ) ;
F_63 ( V_8 , V_101 , F_64 ) ;
F_82 ( & V_8 -> V_108 , V_107 ,
V_112 ) ;
F_47 ( V_8 ) ;
F_45 ( V_8 , V_163 , V_8 -> V_58 ) ;
}
F_9 ( V_2 ) ;
F_103 ( V_8 ) ;
}
void F_117 ( struct V_1 * V_2 , T_1 V_16 )
{
struct V_7 * V_8 ;
F_4 ( V_2 ) ;
V_8 = F_13 ( V_2 , V_16 ) ;
if ( V_8 && F_118 ( ! V_8 -> V_116 ) && F_118 ( ! V_8 -> V_108 ) ) {
F_47 ( V_8 ) ;
F_93 ( V_8 ) ;
}
F_9 ( V_2 ) ;
}
void F_119 ( struct V_1 * V_2 , unsigned V_18 )
{
V_2 -> V_138 = V_18 ;
}
unsigned F_120 ( struct V_1 * V_2 )
{
return V_2 -> V_45 ;
}
T_1 F_121 ( struct V_1 * V_2 )
{
return F_122 ( V_2 -> V_83 -> V_164 ) >>
( V_99 + V_2 -> V_103 ) ;
}
T_1 F_123 ( struct V_7 * V_8 )
{
return V_8 -> V_16 ;
}
void * F_124 ( struct V_7 * V_8 )
{
return V_8 -> V_54 ;
}
void * F_125 ( struct V_7 * V_8 )
{
return V_8 + 1 ;
}
struct V_1 * F_126 ( struct V_7 * V_8 )
{
return V_8 -> V_2 ;
}
static void F_127 ( struct V_1 * V_2 )
{
struct V_7 * V_8 ;
int V_165 ;
bool V_166 = false ;
F_2 ( F_6 () ) ;
F_111 ( V_2 ) ;
F_4 ( V_2 ) ;
while ( ( V_8 = F_83 ( V_2 ) ) )
F_93 ( V_8 ) ;
for ( V_165 = 0 ; V_165 < V_167 ; V_165 ++ )
F_128 (b, &c->lru[i], lru_list) {
F_129 ( ! V_166 ) ;
V_166 = true ;
F_130 ( L_2 ,
( unsigned long long ) V_8 -> V_16 , V_8 -> V_116 , V_165 ) ;
#ifdef F_43
F_131 ( & V_8 -> V_9 , 1 ) ;
V_8 -> V_116 = 0 ;
#endif
}
#ifdef F_43
while ( ( V_8 = F_83 ( V_2 ) ) )
F_93 ( V_8 ) ;
#endif
for ( V_165 = 0 ; V_165 < V_167 ; V_165 ++ )
F_2 ( ! F_77 ( & V_2 -> V_60 [ V_165 ] ) ) ;
F_9 ( V_2 ) ;
}
static bool F_132 ( struct V_7 * V_8 , T_2 V_168 )
{
if ( ! ( V_168 & V_169 ) ) {
if ( F_67 ( V_117 , & V_8 -> V_108 ) ||
F_67 ( V_107 , & V_8 -> V_108 ) ||
F_67 ( V_111 , & V_8 -> V_108 ) )
return false ;
}
if ( V_8 -> V_116 )
return false ;
F_81 ( V_8 ) ;
F_47 ( V_8 ) ;
F_93 ( V_8 ) ;
return true ;
}
static unsigned long F_133 ( struct V_1 * V_2 )
{
unsigned long V_170 = F_25 ( V_171 ) ;
return V_170 >> ( V_2 -> V_103 + V_99 ) ;
}
static unsigned long F_134 ( struct V_1 * V_2 , unsigned long V_172 ,
T_2 V_42 )
{
int V_173 ;
struct V_7 * V_8 , * V_133 ;
unsigned long V_174 = 0 ;
unsigned long V_84 = V_172 ;
unsigned long V_175 = F_133 ( V_2 ) ;
for ( V_173 = 0 ; V_173 < V_167 ; V_173 ++ ) {
F_96 (b, tmp, &c->lru[l], lru_list) {
if ( F_132 ( V_8 , V_42 ) )
V_174 ++ ;
if ( ! -- V_172 || ( ( V_84 - V_174 ) <= V_175 ) )
return V_174 ;
F_79 () ;
}
}
return V_174 ;
}
static unsigned long
F_135 ( struct V_176 * V_177 , struct V_178 * V_179 )
{
struct V_1 * V_2 ;
unsigned long V_174 ;
V_2 = F_14 ( V_177 , struct V_1 , V_176 ) ;
if ( V_179 -> V_42 & V_169 )
F_4 ( V_2 ) ;
else if ( ! F_7 ( V_2 ) )
return V_180 ;
V_174 = F_134 ( V_2 , V_179 -> V_172 , V_179 -> V_42 ) ;
F_9 ( V_2 ) ;
return V_174 ;
}
static unsigned long
F_136 ( struct V_176 * V_177 , struct V_178 * V_179 )
{
struct V_1 * V_2 = F_14 ( V_177 , struct V_1 , V_176 ) ;
return F_25 ( V_2 -> V_57 [ V_134 ] ) + F_25 ( V_2 -> V_57 [ V_140 ] ) ;
}
struct V_1 * F_137 ( struct V_181 * V_83 , unsigned V_45 ,
unsigned V_129 , unsigned V_55 ,
void (* V_131)( struct V_7 * ) ,
void (* V_102)( struct V_7 * ) )
{
int V_72 ;
struct V_1 * V_2 ;
unsigned V_165 ;
F_2 ( V_45 < 1 << V_99 ||
( V_45 & ( V_45 - 1 ) ) ) ;
V_2 = F_138 ( sizeof( * V_2 ) , V_182 ) ;
if ( ! V_2 ) {
V_72 = - V_183 ;
goto V_184;
}
V_2 -> V_19 = V_185 ;
V_2 -> V_83 = V_83 ;
V_2 -> V_45 = V_45 ;
V_2 -> V_103 = F_139 ( V_45 ) - V_99 ;
V_2 -> V_51 = ( F_139 ( V_45 ) >= V_186 ) ?
F_139 ( V_45 ) - V_186 : 0 ;
V_2 -> V_4 = ( F_139 ( V_45 ) < V_186 ?
V_186 - F_139 ( V_45 ) : 0 ) ;
V_2 -> V_55 = V_55 ;
V_2 -> V_131 = V_131 ;
V_2 -> V_102 = V_102 ;
for ( V_165 = 0 ; V_165 < V_167 ; V_165 ++ ) {
F_140 ( & V_2 -> V_60 [ V_165 ] ) ;
V_2 -> V_57 [ V_165 ] = 0 ;
}
F_141 ( & V_2 -> V_6 ) ;
F_140 ( & V_2 -> V_129 ) ;
V_2 -> V_130 = V_129 ;
V_2 -> V_138 = V_187 ;
F_142 ( & V_2 -> V_120 ) ;
V_2 -> V_106 = 0 ;
V_2 -> V_80 = F_143 () ;
if ( F_144 ( V_2 -> V_80 ) ) {
V_72 = F_145 ( V_2 -> V_80 ) ;
goto V_188;
}
F_146 ( & V_36 ) ;
if ( V_2 -> V_4 ) {
if ( ! F_147 ( V_2 ) ) {
F_147 ( V_2 ) = F_148 ( V_182 , L_3 , V_2 -> V_45 ) ;
if ( ! F_147 ( V_2 ) ) {
V_72 = - V_183 ;
F_10 ( & V_36 ) ;
goto V_189;
}
}
if ( ! F_29 ( V_2 ) ) {
F_29 ( V_2 ) = F_149 ( F_147 ( V_2 ) ,
V_2 -> V_45 ,
V_2 -> V_45 , 0 , NULL ) ;
if ( ! F_29 ( V_2 ) ) {
V_72 = - V_183 ;
F_10 ( & V_36 ) ;
goto V_189;
}
}
}
F_10 ( & V_36 ) ;
while ( V_2 -> V_130 ) {
struct V_7 * V_8 = F_40 ( V_2 , V_182 ) ;
if ( ! V_8 ) {
V_72 = - V_183 ;
goto V_190;
}
F_93 ( V_8 ) ;
}
F_146 ( & V_36 ) ;
V_37 ++ ;
F_46 ( & V_2 -> V_191 , & V_192 ) ;
F_23 () ;
F_10 ( & V_36 ) ;
V_2 -> V_176 . V_193 = F_136 ;
V_2 -> V_176 . V_194 = F_135 ;
V_2 -> V_176 . V_195 = 1 ;
V_2 -> V_176 . V_196 = 0 ;
F_150 ( & V_2 -> V_176 ) ;
return V_2 ;
V_190:
V_189:
while ( ! F_77 ( & V_2 -> V_129 ) ) {
struct V_7 * V_8 = F_78 ( V_2 -> V_129 . V_115 ,
struct V_7 , V_59 ) ;
F_48 ( & V_8 -> V_59 ) ;
F_44 ( V_8 ) ;
}
F_151 ( V_2 -> V_80 ) ;
V_188:
F_42 ( V_2 ) ;
V_184:
return F_104 ( V_72 ) ;
}
void F_152 ( struct V_1 * V_2 )
{
unsigned V_165 ;
F_127 ( V_2 ) ;
F_153 ( & V_2 -> V_176 ) ;
F_146 ( & V_36 ) ;
F_48 ( & V_2 -> V_191 ) ;
V_37 -- ;
F_23 () ;
F_10 ( & V_36 ) ;
F_2 ( ! F_154 ( & V_2 -> V_19 ) ) ;
F_2 ( V_2 -> V_130 ) ;
while ( ! F_77 ( & V_2 -> V_129 ) ) {
struct V_7 * V_8 = F_78 ( V_2 -> V_129 . V_115 ,
struct V_7 , V_59 ) ;
F_48 ( & V_8 -> V_59 ) ;
F_44 ( V_8 ) ;
}
for ( V_165 = 0 ; V_165 < V_167 ; V_165 ++ )
if ( V_2 -> V_57 [ V_165 ] )
F_130 ( L_4 , V_165 , V_2 -> V_57 [ V_165 ] ) ;
for ( V_165 = 0 ; V_165 < V_167 ; V_165 ++ )
F_2 ( V_2 -> V_57 [ V_165 ] ) ;
F_151 ( V_2 -> V_80 ) ;
F_42 ( V_2 ) ;
}
void F_155 ( struct V_1 * V_2 , T_1 V_104 )
{
V_2 -> V_104 = V_104 ;
}
static unsigned F_156 ( void )
{
unsigned V_197 = F_25 ( V_198 ) ;
if ( V_197 > V_199 / V_200 )
V_197 = V_199 / V_200 ;
return V_197 * V_200 ;
}
static bool F_157 ( struct V_7 * V_8 , unsigned long V_201 )
{
return F_158 ( V_62 , V_8 -> V_61 + V_201 ) ;
}
static void F_159 ( struct V_1 * V_2 , unsigned long V_201 )
{
struct V_7 * V_8 , * V_133 ;
unsigned long V_175 = F_133 ( V_2 ) ;
unsigned long V_84 ;
F_102 ( V_110 ) ;
F_4 ( V_2 ) ;
F_98 ( V_2 , & V_110 ) ;
if ( F_65 ( ! F_77 ( & V_110 ) ) ) {
F_9 ( V_2 ) ;
F_75 ( & V_110 ) ;
F_4 ( V_2 ) ;
}
V_84 = V_2 -> V_57 [ V_134 ] + V_2 -> V_57 [ V_140 ] ;
F_96 (b, tmp, &c->lru[LIST_CLEAN], lru_list) {
if ( V_84 <= V_175 )
break;
if ( ! F_157 ( V_8 , V_201 ) )
break;
if ( F_132 ( V_8 , 0 ) )
V_84 -- ;
F_79 () ;
}
F_9 ( V_2 ) ;
}
static void F_160 ( void )
{
unsigned long V_202 = F_156 () ;
struct V_1 * V_2 ;
F_146 ( & V_36 ) ;
F_23 () ;
F_128 (c, &dm_bufio_all_clients, client_list)
F_159 ( V_2 , V_202 ) ;
F_10 ( & V_36 ) ;
}
static void F_161 ( struct V_203 * V_204 )
{
F_160 () ;
F_162 ( V_205 , & V_206 ,
V_207 * V_200 ) ;
}
static int T_5 F_163 ( void )
{
T_6 V_85 ;
V_30 = 0 ;
V_31 = 0 ;
V_32 = 0 ;
V_34 = 0 ;
memset ( & V_5 , 0 , sizeof V_5 ) ;
memset ( & V_208 , 0 , sizeof V_208 ) ;
V_85 = ( T_6 ) ( ( V_209 - V_210 ) *
V_211 / 100 ) << V_186 ;
if ( V_85 > V_212 )
V_85 = V_212 ;
#ifdef F_164
if ( V_85 > ( V_213 - V_214 ) * V_215 / 100 )
V_85 = ( V_213 - V_214 ) * V_215 / 100 ;
#endif
V_40 = V_85 ;
F_146 ( & V_36 ) ;
F_23 () ;
F_10 ( & V_36 ) ;
V_205 = F_165 ( L_5 , V_216 , 0 ) ;
if ( ! V_205 )
return - V_183 ;
F_166 ( & V_206 , F_161 ) ;
F_162 ( V_205 , & V_206 ,
V_207 * V_200 ) ;
return 0 ;
}
static void T_7 F_167 ( void )
{
int V_217 = 0 ;
int V_165 ;
F_168 ( & V_206 ) ;
F_169 ( V_205 ) ;
for ( V_165 = 0 ; V_165 < F_3 ( V_5 ) ; V_165 ++ )
F_170 ( V_5 [ V_165 ] ) ;
for ( V_165 = 0 ; V_165 < F_3 ( V_208 ) ; V_165 ++ )
F_42 ( V_208 [ V_165 ] ) ;
if ( V_37 ) {
F_38 ( L_6 ,
V_218 , V_37 ) ;
V_217 = 1 ;
}
if ( V_34 ) {
F_38 ( L_7 ,
V_218 , V_34 ) ;
V_217 = 1 ;
}
if ( V_31 ) {
F_38 ( L_8 ,
V_218 , V_31 ) ;
V_217 = 1 ;
}
if ( V_32 ) {
F_38 ( L_9 ,
V_218 , V_32 ) ;
V_217 = 1 ;
}
F_2 ( V_217 ) ;
}
