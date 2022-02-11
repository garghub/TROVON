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
V_44 = F_32 ( V_2 -> V_45 , V_42 | V_53 , V_54 ) ;
if ( V_42 & V_49 )
F_33 ( V_43 ) ;
return V_44 ;
}
static void F_34 ( struct V_1 * V_2 ,
void * V_55 , enum V_26 V_26 )
{
switch ( V_26 ) {
case V_47 :
F_35 ( F_29 ( V_2 ) , V_55 ) ;
break;
case V_50 :
F_36 ( ( unsigned long ) V_55 , V_2 -> V_51 ) ;
break;
case V_52 :
F_37 ( V_55 ) ;
break;
default:
F_38 ( L_1 ,
V_26 ) ;
F_39 () ;
}
}
static struct V_7 * F_40 ( struct V_1 * V_2 , T_2 V_42 )
{
struct V_7 * V_8 = F_41 ( sizeof( struct V_7 ) + V_2 -> V_56 ,
V_42 ) ;
if ( ! V_8 )
return NULL ;
V_8 -> V_2 = V_2 ;
V_8 -> V_55 = F_27 ( V_2 , V_42 , & V_8 -> V_26 ) ;
if ( ! V_8 -> V_55 ) {
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
F_34 ( V_2 , V_8 -> V_55 , V_8 -> V_26 ) ;
F_42 ( V_8 ) ;
}
static void F_45 ( struct V_7 * V_8 , T_1 V_16 , int V_57 )
{
struct V_1 * V_2 = V_8 -> V_2 ;
V_2 -> V_58 [ V_57 ] ++ ;
V_8 -> V_16 = V_16 ;
V_8 -> V_59 = V_57 ;
F_46 ( & V_8 -> V_60 , & V_2 -> V_61 [ V_57 ] ) ;
F_15 ( V_8 -> V_2 , V_8 ) ;
V_8 -> V_62 = V_63 ;
}
static void F_47 ( struct V_7 * V_8 )
{
struct V_1 * V_2 = V_8 -> V_2 ;
F_2 ( ! V_2 -> V_58 [ V_8 -> V_59 ] ) ;
V_2 -> V_58 [ V_8 -> V_59 ] -- ;
F_18 ( V_8 -> V_2 , V_8 ) ;
F_48 ( & V_8 -> V_60 ) ;
}
static void F_49 ( struct V_7 * V_8 , int V_57 )
{
struct V_1 * V_2 = V_8 -> V_2 ;
F_2 ( ! V_2 -> V_58 [ V_8 -> V_59 ] ) ;
V_2 -> V_58 [ V_8 -> V_59 ] -- ;
V_2 -> V_58 [ V_57 ] ++ ;
V_8 -> V_59 = V_57 ;
F_50 ( & V_8 -> V_60 , & V_2 -> V_61 [ V_57 ] ) ;
V_8 -> V_62 = V_63 ;
}
static void F_51 ( unsigned long error , void * V_64 )
{
struct V_7 * V_8 = V_64 ;
V_8 -> V_65 . V_66 = error ? - V_67 : 0 ;
V_8 -> V_65 . V_68 ( & V_8 -> V_65 ) ;
}
static void F_52 ( struct V_7 * V_8 , int V_69 , T_1 V_16 ,
T_3 * V_70 )
{
int V_71 ;
struct V_72 V_73 = {
. V_74 = V_69 ,
. V_75 = 0 ,
. V_76 . V_77 = F_51 ,
. V_76 . V_64 = V_8 ,
. V_78 = V_8 -> V_2 -> V_79 ,
} ;
struct V_80 V_81 = {
. V_82 = V_8 -> V_2 -> V_82 ,
. V_83 = V_16 << V_8 -> V_2 -> V_84 ,
. V_85 = V_8 -> V_2 -> V_45 >> V_86 ,
} ;
if ( V_8 -> V_26 != V_52 ) {
V_73 . V_87 . type = V_88 ;
V_73 . V_87 . V_44 . V_89 = V_8 -> V_55 ;
} else {
V_73 . V_87 . type = V_90 ;
V_73 . V_87 . V_44 . V_91 = V_8 -> V_55 ;
}
V_8 -> V_65 . V_68 = V_70 ;
V_71 = V_79 ( & V_73 , 1 , & V_81 , NULL ) ;
if ( V_71 ) {
V_8 -> V_65 . V_66 = V_71 ;
V_70 ( & V_8 -> V_65 ) ;
}
}
static void F_53 ( struct V_65 * V_65 )
{
T_3 * V_92 = V_65 -> V_93 ;
int error = V_65 -> V_66 ;
F_54 ( V_65 ) ;
V_65 -> V_66 = error ;
V_92 ( V_65 ) ;
}
static void F_55 ( struct V_7 * V_8 , int V_69 , T_1 V_16 ,
T_3 * V_70 )
{
char * V_44 ;
int V_94 ;
F_56 ( & V_8 -> V_65 , V_8 -> V_95 , V_96 ) ;
V_8 -> V_65 . V_97 . V_98 = V_16 << V_8 -> V_2 -> V_84 ;
V_8 -> V_65 . V_99 = V_8 -> V_2 -> V_82 ;
V_8 -> V_65 . V_68 = F_53 ;
V_8 -> V_65 . V_93 = V_70 ;
F_57 ( & V_8 -> V_65 , V_69 , 0 ) ;
V_44 = V_8 -> V_55 ;
V_94 = V_8 -> V_2 -> V_45 ;
if ( V_94 >= V_100 )
F_2 ( ( unsigned long ) V_44 & ( V_100 - 1 ) ) ;
else
F_2 ( ( unsigned long ) V_44 & ( V_94 - 1 ) ) ;
do {
if ( ! F_58 ( & V_8 -> V_65 , F_59 ( V_44 ) ,
V_94 < V_100 ? V_94 : V_100 ,
F_60 ( V_44 ) ) ) {
F_2 ( V_8 -> V_2 -> V_45 <= V_100 ) ;
F_52 ( V_8 , V_69 , V_16 , V_70 ) ;
return;
}
V_94 -= V_100 ;
V_44 += V_100 ;
} while ( V_94 > 0 );
F_61 ( & V_8 -> V_65 ) ;
}
static void F_62 ( struct V_7 * V_8 , int V_69 , T_1 V_16 ,
T_3 * V_70 )
{
if ( V_69 == V_101 && V_8 -> V_2 -> V_102 )
V_8 -> V_2 -> V_102 ( V_8 ) ;
if ( V_8 -> V_2 -> V_45 <= V_96 * V_100 &&
V_8 -> V_26 != V_52 )
F_55 ( V_8 , V_69 , V_16 , V_70 ) ;
else
F_52 ( V_8 , V_69 , V_16 , V_70 ) ;
}
static void F_63 ( struct V_65 * V_65 )
{
struct V_7 * V_8 = F_14 ( V_65 , struct V_7 , V_65 ) ;
V_8 -> V_103 = V_65 -> V_66 ;
if ( F_64 ( V_65 -> V_66 ) ) {
struct V_1 * V_2 = V_8 -> V_2 ;
int error = V_65 -> V_66 ;
( void ) F_26 ( & V_2 -> V_104 , 0 , error ) ;
}
F_2 ( ! F_65 ( V_105 , & V_8 -> V_106 ) ) ;
F_66 () ;
F_67 ( V_105 , & V_8 -> V_106 ) ;
F_68 () ;
F_69 ( & V_8 -> V_106 , V_105 ) ;
}
static void F_70 ( struct V_7 * V_8 ,
struct V_107 * V_108 )
{
if ( ! F_65 ( V_109 , & V_8 -> V_106 ) )
return;
F_67 ( V_109 , & V_8 -> V_106 ) ;
F_71 ( & V_8 -> V_106 , V_105 , V_110 ) ;
if ( ! V_108 )
F_62 ( V_8 , V_101 , V_8 -> V_16 , F_63 ) ;
else
F_72 ( & V_8 -> V_108 , V_108 ) ;
}
static void F_73 ( struct V_107 * V_108 )
{
struct V_111 V_112 ;
F_74 ( & V_112 ) ;
while ( ! F_75 ( V_108 ) ) {
struct V_7 * V_8 =
F_76 ( V_108 -> V_113 , struct V_7 , V_108 ) ;
F_48 ( & V_8 -> V_108 ) ;
F_62 ( V_8 , V_101 , V_8 -> V_16 , F_63 ) ;
F_77 () ;
}
F_78 ( & V_112 ) ;
}
static void F_79 ( struct V_7 * V_8 )
{
F_2 ( V_8 -> V_114 ) ;
if ( ! V_8 -> V_106 )
return;
F_80 ( & V_8 -> V_106 , V_115 , V_110 ) ;
F_70 ( V_8 , NULL ) ;
F_80 ( & V_8 -> V_106 , V_105 , V_110 ) ;
}
static struct V_7 * F_81 ( struct V_1 * V_2 )
{
struct V_7 * V_8 ;
F_82 (b, &c->lru[LIST_CLEAN], lru_list) {
F_2 ( F_65 ( V_105 , & V_8 -> V_106 ) ) ;
F_2 ( F_65 ( V_109 , & V_8 -> V_106 ) ) ;
if ( ! V_8 -> V_114 ) {
F_79 ( V_8 ) ;
F_47 ( V_8 ) ;
return V_8 ;
}
F_77 () ;
}
F_82 (b, &c->lru[LIST_DIRTY], lru_list) {
F_2 ( F_65 ( V_115 , & V_8 -> V_106 ) ) ;
if ( ! V_8 -> V_114 ) {
F_79 ( V_8 ) ;
F_47 ( V_8 ) ;
return V_8 ;
}
F_77 () ;
}
return NULL ;
}
static void F_83 ( struct V_1 * V_2 )
{
F_84 ( V_116 , V_117 ) ;
F_85 ( & V_2 -> V_118 , & V_116 ) ;
F_86 ( V_110 ) ;
F_9 ( V_2 ) ;
F_87 () ;
F_88 ( & V_2 -> V_118 , & V_116 ) ;
F_4 ( V_2 ) ;
}
static struct V_7 * F_89 ( struct V_1 * V_2 , enum V_119 V_120 )
{
struct V_7 * V_8 ;
bool V_121 = false ;
while ( 1 ) {
if ( V_38 != 1 ) {
V_8 = F_40 ( V_2 , V_122 | V_49 | V_123 | V_124 ) ;
if ( V_8 )
return V_8 ;
}
if ( V_120 == V_125 )
return NULL ;
if ( V_38 != 1 && ! V_121 ) {
F_9 ( V_2 ) ;
V_8 = F_40 ( V_2 , V_126 | V_49 | V_123 | V_124 ) ;
F_4 ( V_2 ) ;
if ( V_8 )
return V_8 ;
V_121 = true ;
}
if ( ! F_75 ( & V_2 -> V_127 ) ) {
V_8 = F_76 ( V_2 -> V_127 . V_113 ,
struct V_7 , V_60 ) ;
F_48 ( & V_8 -> V_60 ) ;
V_2 -> V_128 ++ ;
return V_8 ;
}
V_8 = F_81 ( V_2 ) ;
if ( V_8 )
return V_8 ;
F_83 ( V_2 ) ;
}
}
static struct V_7 * F_90 ( struct V_1 * V_2 , enum V_119 V_120 )
{
struct V_7 * V_8 = F_89 ( V_2 , V_120 ) ;
if ( ! V_8 )
return NULL ;
if ( V_2 -> V_129 )
V_2 -> V_129 ( V_8 ) ;
return V_8 ;
}
static void F_91 ( struct V_7 * V_8 )
{
struct V_1 * V_2 = V_8 -> V_2 ;
if ( ! V_2 -> V_128 )
F_44 ( V_8 ) ;
else {
F_46 ( & V_8 -> V_60 , & V_2 -> V_127 ) ;
V_2 -> V_128 -- ;
}
F_92 ( & V_2 -> V_118 ) ;
}
static void F_93 ( struct V_1 * V_2 , int V_130 ,
struct V_107 * V_108 )
{
struct V_7 * V_8 , * V_131 ;
F_94 (b, tmp, &c->lru[LIST_DIRTY], lru_list) {
F_2 ( F_65 ( V_115 , & V_8 -> V_106 ) ) ;
if ( ! F_65 ( V_109 , & V_8 -> V_106 ) &&
! F_65 ( V_105 , & V_8 -> V_106 ) ) {
F_49 ( V_8 , V_132 ) ;
continue;
}
if ( V_130 && F_65 ( V_105 , & V_8 -> V_106 ) )
return;
F_70 ( V_8 , V_108 ) ;
F_77 () ;
}
}
static void F_95 ( struct V_1 * V_2 ,
unsigned long * V_133 ,
unsigned long * V_134 )
{
unsigned long V_135 ;
if ( F_25 ( V_39 ) != V_38 ) {
F_96 ( & V_36 ) ;
F_23 () ;
F_10 ( & V_36 ) ;
}
V_135 = V_41 >>
( V_2 -> V_84 + V_86 ) ;
if ( V_135 < V_2 -> V_136 )
V_135 = V_2 -> V_136 ;
* V_134 = V_135 ;
* V_133 = V_135 * V_137 / 100 ;
}
static void F_97 ( struct V_1 * V_2 ,
struct V_107 * V_108 )
{
unsigned long V_133 , V_134 ;
F_95 ( V_2 , & V_133 , & V_134 ) ;
while ( V_2 -> V_58 [ V_132 ] + V_2 -> V_58 [ V_138 ] >
V_134 ) {
struct V_7 * V_8 = F_81 ( V_2 ) ;
if ( ! V_8 )
return;
F_91 ( V_8 ) ;
F_77 () ;
}
if ( V_2 -> V_58 [ V_138 ] > V_133 )
F_93 ( V_2 , 1 , V_108 ) ;
}
static struct V_7 * F_98 ( struct V_1 * V_2 , T_1 V_16 ,
enum V_119 V_120 , int * V_139 ,
struct V_107 * V_108 )
{
struct V_7 * V_8 , * V_140 = NULL ;
* V_139 = 0 ;
V_8 = F_13 ( V_2 , V_16 ) ;
if ( V_8 )
goto V_141;
if ( V_120 == V_142 )
return NULL ;
V_140 = F_90 ( V_2 , V_120 ) ;
if ( ! V_140 )
return NULL ;
V_8 = F_13 ( V_2 , V_16 ) ;
if ( V_8 ) {
F_91 ( V_140 ) ;
goto V_141;
}
F_97 ( V_2 , V_108 ) ;
V_8 = V_140 ;
V_8 -> V_114 = 1 ;
V_8 -> V_143 = 0 ;
V_8 -> V_103 = 0 ;
F_45 ( V_8 , V_16 , V_132 ) ;
if ( V_120 == V_144 ) {
V_8 -> V_106 = 0 ;
return V_8 ;
}
V_8 -> V_106 = 1 << V_115 ;
* V_139 = 1 ;
return V_8 ;
V_141:
if ( V_120 == V_125 )
return NULL ;
if ( V_120 == V_142 && F_64 ( F_65 ( V_115 , & V_8 -> V_106 ) ) )
return NULL ;
V_8 -> V_114 ++ ;
F_49 ( V_8 , F_65 ( V_109 , & V_8 -> V_106 ) ||
F_65 ( V_105 , & V_8 -> V_106 ) ) ;
return V_8 ;
}
static void F_99 ( struct V_65 * V_65 )
{
struct V_7 * V_8 = F_14 ( V_65 , struct V_7 , V_65 ) ;
V_8 -> V_143 = V_65 -> V_66 ;
F_2 ( ! F_65 ( V_115 , & V_8 -> V_106 ) ) ;
F_66 () ;
F_67 ( V_115 , & V_8 -> V_106 ) ;
F_68 () ;
F_69 ( & V_8 -> V_106 , V_115 ) ;
}
static void * F_100 ( struct V_1 * V_2 , T_1 V_16 ,
enum V_119 V_120 , struct V_7 * * V_145 )
{
int V_139 ;
struct V_7 * V_8 ;
F_101 ( V_108 ) ;
F_4 ( V_2 ) ;
V_8 = F_98 ( V_2 , V_16 , V_120 , & V_139 , & V_108 ) ;
#ifdef F_43
if ( V_8 && V_8 -> V_114 == 1 )
F_11 ( V_8 ) ;
#endif
F_9 ( V_2 ) ;
F_73 ( & V_108 ) ;
if ( ! V_8 )
return NULL ;
if ( V_139 )
F_62 ( V_8 , V_146 , V_8 -> V_16 , F_99 ) ;
F_80 ( & V_8 -> V_106 , V_115 , V_110 ) ;
if ( V_8 -> V_143 ) {
int error = V_8 -> V_143 ;
F_102 ( V_8 ) ;
return F_103 ( error ) ;
}
* V_145 = V_8 ;
return V_8 -> V_55 ;
}
void * F_104 ( struct V_1 * V_2 , T_1 V_16 ,
struct V_7 * * V_145 )
{
return F_100 ( V_2 , V_16 , V_142 , V_145 ) ;
}
void * F_105 ( struct V_1 * V_2 , T_1 V_16 ,
struct V_7 * * V_145 )
{
F_2 ( F_6 () ) ;
return F_100 ( V_2 , V_16 , V_147 , V_145 ) ;
}
void * F_106 ( struct V_1 * V_2 , T_1 V_16 ,
struct V_7 * * V_145 )
{
F_2 ( F_6 () ) ;
return F_100 ( V_2 , V_16 , V_144 , V_145 ) ;
}
void F_107 ( struct V_1 * V_2 ,
T_1 V_16 , unsigned V_148 )
{
struct V_111 V_112 ;
F_101 ( V_108 ) ;
F_2 ( F_6 () ) ;
F_74 ( & V_112 ) ;
F_4 ( V_2 ) ;
for (; V_148 -- ; V_16 ++ ) {
int V_139 ;
struct V_7 * V_8 ;
V_8 = F_98 ( V_2 , V_16 , V_125 , & V_139 ,
& V_108 ) ;
if ( F_64 ( ! F_75 ( & V_108 ) ) ) {
F_9 ( V_2 ) ;
F_78 ( & V_112 ) ;
F_73 ( & V_108 ) ;
F_74 ( & V_112 ) ;
F_4 ( V_2 ) ;
}
if ( F_64 ( V_8 != NULL ) ) {
F_9 ( V_2 ) ;
if ( V_139 )
F_62 ( V_8 , V_146 , V_8 -> V_16 , F_99 ) ;
F_102 ( V_8 ) ;
F_77 () ;
if ( ! V_148 )
goto V_149;
F_4 ( V_2 ) ;
}
}
F_9 ( V_2 ) ;
V_149:
F_78 ( & V_112 ) ;
}
void F_102 ( struct V_7 * V_8 )
{
struct V_1 * V_2 = V_8 -> V_2 ;
F_4 ( V_2 ) ;
F_2 ( ! V_8 -> V_114 ) ;
V_8 -> V_114 -- ;
if ( ! V_8 -> V_114 ) {
F_92 ( & V_2 -> V_118 ) ;
if ( ( V_8 -> V_143 || V_8 -> V_103 ) &&
! F_65 ( V_115 , & V_8 -> V_106 ) &&
! F_65 ( V_105 , & V_8 -> V_106 ) &&
! F_65 ( V_109 , & V_8 -> V_106 ) ) {
F_47 ( V_8 ) ;
F_91 ( V_8 ) ;
}
}
F_9 ( V_2 ) ;
}
void F_108 ( struct V_7 * V_8 )
{
struct V_1 * V_2 = V_8 -> V_2 ;
F_4 ( V_2 ) ;
F_2 ( F_65 ( V_115 , & V_8 -> V_106 ) ) ;
if ( ! F_109 ( V_109 , & V_8 -> V_106 ) )
F_49 ( V_8 , V_138 ) ;
F_9 ( V_2 ) ;
}
void F_110 ( struct V_1 * V_2 )
{
F_101 ( V_108 ) ;
F_2 ( F_6 () ) ;
F_4 ( V_2 ) ;
F_93 ( V_2 , 0 , & V_108 ) ;
F_9 ( V_2 ) ;
F_73 ( & V_108 ) ;
}
int F_111 ( struct V_1 * V_2 )
{
int V_150 , V_151 ;
unsigned long V_152 = 0 ;
struct V_7 * V_8 , * V_131 ;
F_101 ( V_108 ) ;
F_4 ( V_2 ) ;
F_93 ( V_2 , 0 , & V_108 ) ;
F_9 ( V_2 ) ;
F_73 ( & V_108 ) ;
F_4 ( V_2 ) ;
V_153:
F_94 (b, tmp, &c->lru[LIST_DIRTY], lru_list) {
int V_154 = 0 ;
if ( V_152 < V_2 -> V_58 [ V_138 ] )
V_152 ++ ;
F_2 ( F_65 ( V_115 , & V_8 -> V_106 ) ) ;
if ( F_65 ( V_105 , & V_8 -> V_106 ) ) {
if ( V_152 < V_2 -> V_58 [ V_138 ] ) {
V_154 = 1 ;
V_8 -> V_114 ++ ;
F_9 ( V_2 ) ;
F_80 ( & V_8 -> V_106 , V_105 ,
V_110 ) ;
F_4 ( V_2 ) ;
V_8 -> V_114 -- ;
} else
F_80 ( & V_8 -> V_106 , V_105 ,
V_110 ) ;
}
if ( ! F_65 ( V_109 , & V_8 -> V_106 ) &&
! F_65 ( V_105 , & V_8 -> V_106 ) )
F_49 ( V_8 , V_132 ) ;
F_77 () ;
if ( V_154 )
goto V_153;
}
F_92 ( & V_2 -> V_118 ) ;
F_9 ( V_2 ) ;
V_150 = F_112 ( & V_2 -> V_104 , 0 ) ;
V_151 = F_113 ( V_2 ) ;
if ( V_150 )
return V_150 ;
return V_151 ;
}
int F_113 ( struct V_1 * V_2 )
{
struct V_72 V_73 = {
. V_74 = V_155 ,
. V_75 = V_156 ,
. V_87 . type = V_88 ,
. V_87 . V_44 . V_89 = NULL ,
. V_78 = V_2 -> V_79 ,
} ;
struct V_80 V_157 = {
. V_82 = V_2 -> V_82 ,
. V_83 = 0 ,
. V_85 = 0 ,
} ;
F_2 ( F_6 () ) ;
return V_79 ( & V_73 , 1 , & V_157 , NULL ) ;
}
void F_114 ( struct V_7 * V_8 , T_1 V_158 )
{
struct V_1 * V_2 = V_8 -> V_2 ;
struct V_7 * V_23 ;
F_2 ( F_6 () ) ;
F_4 ( V_2 ) ;
V_159:
V_23 = F_13 ( V_2 , V_158 ) ;
if ( V_23 ) {
if ( V_23 -> V_114 ) {
F_83 ( V_2 ) ;
goto V_159;
}
F_79 ( V_23 ) ;
F_47 ( V_23 ) ;
F_91 ( V_23 ) ;
}
F_2 ( ! V_8 -> V_114 ) ;
F_2 ( F_65 ( V_115 , & V_8 -> V_106 ) ) ;
F_70 ( V_8 , NULL ) ;
if ( V_8 -> V_114 == 1 ) {
F_80 ( & V_8 -> V_106 , V_105 ,
V_110 ) ;
F_115 ( V_109 , & V_8 -> V_106 ) ;
F_47 ( V_8 ) ;
F_45 ( V_8 , V_158 , V_138 ) ;
} else {
T_1 V_160 ;
F_71 ( & V_8 -> V_106 , V_105 ,
V_110 ) ;
V_160 = V_8 -> V_16 ;
F_47 ( V_8 ) ;
F_45 ( V_8 , V_158 , V_8 -> V_59 ) ;
F_62 ( V_8 , V_101 , V_158 , F_63 ) ;
F_80 ( & V_8 -> V_106 , V_105 ,
V_110 ) ;
F_47 ( V_8 ) ;
F_45 ( V_8 , V_160 , V_8 -> V_59 ) ;
}
F_9 ( V_2 ) ;
F_102 ( V_8 ) ;
}
void F_116 ( struct V_1 * V_2 , T_1 V_16 )
{
struct V_7 * V_8 ;
F_4 ( V_2 ) ;
V_8 = F_13 ( V_2 , V_16 ) ;
if ( V_8 && F_117 ( ! V_8 -> V_114 ) && F_117 ( ! V_8 -> V_106 ) ) {
F_47 ( V_8 ) ;
F_91 ( V_8 ) ;
}
F_9 ( V_2 ) ;
}
void F_118 ( struct V_1 * V_2 , unsigned V_18 )
{
V_2 -> V_136 = V_18 ;
}
unsigned F_119 ( struct V_1 * V_2 )
{
return V_2 -> V_45 ;
}
T_1 F_120 ( struct V_1 * V_2 )
{
return F_121 ( V_2 -> V_82 -> V_161 ) >>
( V_86 + V_2 -> V_84 ) ;
}
T_1 F_122 ( struct V_7 * V_8 )
{
return V_8 -> V_16 ;
}
void * F_123 ( struct V_7 * V_8 )
{
return V_8 -> V_55 ;
}
void * F_124 ( struct V_7 * V_8 )
{
return V_8 + 1 ;
}
struct V_1 * F_125 ( struct V_7 * V_8 )
{
return V_8 -> V_2 ;
}
static void F_126 ( struct V_1 * V_2 )
{
struct V_7 * V_8 ;
int V_162 ;
bool V_163 = false ;
F_2 ( F_6 () ) ;
F_110 ( V_2 ) ;
F_4 ( V_2 ) ;
while ( ( V_8 = F_81 ( V_2 ) ) )
F_91 ( V_8 ) ;
for ( V_162 = 0 ; V_162 < V_164 ; V_162 ++ )
F_127 (b, &c->lru[i], lru_list) {
F_128 ( ! V_163 ) ;
V_163 = true ;
F_129 ( L_2 ,
( unsigned long long ) V_8 -> V_16 , V_8 -> V_114 , V_162 ) ;
#ifdef F_43
F_130 ( & V_8 -> V_9 , 1 ) ;
V_8 -> V_114 = 0 ;
#endif
}
#ifdef F_43
while ( ( V_8 = F_81 ( V_2 ) ) )
F_91 ( V_8 ) ;
#endif
for ( V_162 = 0 ; V_162 < V_164 ; V_162 ++ )
F_2 ( ! F_75 ( & V_2 -> V_61 [ V_162 ] ) ) ;
F_9 ( V_2 ) ;
}
static bool F_131 ( struct V_7 * V_8 , T_2 V_165 )
{
if ( ! ( V_165 & V_166 ) ) {
if ( F_65 ( V_115 , & V_8 -> V_106 ) ||
F_65 ( V_105 , & V_8 -> V_106 ) ||
F_65 ( V_109 , & V_8 -> V_106 ) )
return false ;
}
if ( V_8 -> V_114 )
return false ;
F_79 ( V_8 ) ;
F_47 ( V_8 ) ;
F_91 ( V_8 ) ;
return true ;
}
static unsigned F_132 ( struct V_1 * V_2 )
{
unsigned V_167 = F_25 ( V_168 ) ;
return V_167 / V_2 -> V_45 ;
}
static unsigned long F_133 ( struct V_1 * V_2 , unsigned long V_169 ,
T_2 V_42 )
{
int V_170 ;
struct V_7 * V_8 , * V_131 ;
unsigned long V_171 = 0 ;
unsigned long V_85 = V_169 ;
unsigned V_172 = F_132 ( V_2 ) ;
for ( V_170 = 0 ; V_170 < V_164 ; V_170 ++ ) {
F_94 (b, tmp, &c->lru[l], lru_list) {
if ( F_131 ( V_8 , V_42 ) )
V_171 ++ ;
if ( ! -- V_169 || ( ( V_85 - V_171 ) <= V_172 ) )
return V_171 ;
F_77 () ;
}
}
return V_171 ;
}
static unsigned long
F_134 ( struct V_173 * V_174 , struct V_175 * V_176 )
{
struct V_1 * V_2 ;
unsigned long V_171 ;
V_2 = F_14 ( V_174 , struct V_1 , V_173 ) ;
if ( V_176 -> V_42 & V_166 )
F_4 ( V_2 ) ;
else if ( ! F_7 ( V_2 ) )
return V_177 ;
V_171 = F_133 ( V_2 , V_176 -> V_169 , V_176 -> V_42 ) ;
F_9 ( V_2 ) ;
return V_171 ;
}
static unsigned long
F_135 ( struct V_173 * V_174 , struct V_175 * V_176 )
{
struct V_1 * V_2 = F_14 ( V_174 , struct V_1 , V_173 ) ;
return F_25 ( V_2 -> V_58 [ V_132 ] ) + F_25 ( V_2 -> V_58 [ V_138 ] ) ;
}
struct V_1 * F_136 ( struct V_178 * V_82 , unsigned V_45 ,
unsigned V_127 , unsigned V_56 ,
void (* V_129)( struct V_7 * ) ,
void (* V_102)( struct V_7 * ) )
{
int V_71 ;
struct V_1 * V_2 ;
unsigned V_162 ;
F_2 ( V_45 < 1 << V_86 ||
( V_45 & ( V_45 - 1 ) ) ) ;
V_2 = F_137 ( sizeof( * V_2 ) , V_179 ) ;
if ( ! V_2 ) {
V_71 = - V_180 ;
goto V_181;
}
V_2 -> V_19 = V_182 ;
V_2 -> V_82 = V_82 ;
V_2 -> V_45 = V_45 ;
V_2 -> V_84 = F_138 ( V_45 ) - V_86 ;
V_2 -> V_51 = ( F_138 ( V_45 ) >= V_183 ) ?
F_138 ( V_45 ) - V_183 : 0 ;
V_2 -> V_4 = ( F_138 ( V_45 ) < V_183 ?
V_183 - F_138 ( V_45 ) : 0 ) ;
V_2 -> V_56 = V_56 ;
V_2 -> V_129 = V_129 ;
V_2 -> V_102 = V_102 ;
for ( V_162 = 0 ; V_162 < V_164 ; V_162 ++ ) {
F_139 ( & V_2 -> V_61 [ V_162 ] ) ;
V_2 -> V_58 [ V_162 ] = 0 ;
}
F_140 ( & V_2 -> V_6 ) ;
F_139 ( & V_2 -> V_127 ) ;
V_2 -> V_128 = V_127 ;
V_2 -> V_136 = V_184 ;
F_141 ( & V_2 -> V_118 ) ;
V_2 -> V_104 = 0 ;
V_2 -> V_79 = F_142 () ;
if ( F_143 ( V_2 -> V_79 ) ) {
V_71 = F_144 ( V_2 -> V_79 ) ;
goto V_185;
}
F_96 ( & V_36 ) ;
if ( V_2 -> V_4 ) {
if ( ! F_145 ( V_2 ) ) {
F_145 ( V_2 ) = F_146 ( V_179 , L_3 , V_2 -> V_45 ) ;
if ( ! F_145 ( V_2 ) ) {
V_71 = - V_180 ;
F_10 ( & V_36 ) ;
goto V_186;
}
}
if ( ! F_29 ( V_2 ) ) {
F_29 ( V_2 ) = F_147 ( F_145 ( V_2 ) ,
V_2 -> V_45 ,
V_2 -> V_45 , 0 , NULL ) ;
if ( ! F_29 ( V_2 ) ) {
V_71 = - V_180 ;
F_10 ( & V_36 ) ;
goto V_186;
}
}
}
F_10 ( & V_36 ) ;
while ( V_2 -> V_128 ) {
struct V_7 * V_8 = F_40 ( V_2 , V_179 ) ;
if ( ! V_8 ) {
V_71 = - V_180 ;
goto V_187;
}
F_91 ( V_8 ) ;
}
F_96 ( & V_36 ) ;
V_37 ++ ;
F_46 ( & V_2 -> V_188 , & V_189 ) ;
F_23 () ;
F_10 ( & V_36 ) ;
V_2 -> V_173 . V_190 = F_135 ;
V_2 -> V_173 . V_191 = F_134 ;
V_2 -> V_173 . V_192 = 1 ;
V_2 -> V_173 . V_193 = 0 ;
F_148 ( & V_2 -> V_173 ) ;
return V_2 ;
V_187:
V_186:
while ( ! F_75 ( & V_2 -> V_127 ) ) {
struct V_7 * V_8 = F_76 ( V_2 -> V_127 . V_113 ,
struct V_7 , V_60 ) ;
F_48 ( & V_8 -> V_60 ) ;
F_44 ( V_8 ) ;
}
F_149 ( V_2 -> V_79 ) ;
V_185:
F_42 ( V_2 ) ;
V_181:
return F_103 ( V_71 ) ;
}
void F_150 ( struct V_1 * V_2 )
{
unsigned V_162 ;
F_126 ( V_2 ) ;
F_151 ( & V_2 -> V_173 ) ;
F_96 ( & V_36 ) ;
F_48 ( & V_2 -> V_188 ) ;
V_37 -- ;
F_23 () ;
F_10 ( & V_36 ) ;
F_2 ( ! F_152 ( & V_2 -> V_19 ) ) ;
F_2 ( V_2 -> V_128 ) ;
while ( ! F_75 ( & V_2 -> V_127 ) ) {
struct V_7 * V_8 = F_76 ( V_2 -> V_127 . V_113 ,
struct V_7 , V_60 ) ;
F_48 ( & V_8 -> V_60 ) ;
F_44 ( V_8 ) ;
}
for ( V_162 = 0 ; V_162 < V_164 ; V_162 ++ )
if ( V_2 -> V_58 [ V_162 ] )
F_129 ( L_4 , V_162 , V_2 -> V_58 [ V_162 ] ) ;
for ( V_162 = 0 ; V_162 < V_164 ; V_162 ++ )
F_2 ( V_2 -> V_58 [ V_162 ] ) ;
F_149 ( V_2 -> V_79 ) ;
F_42 ( V_2 ) ;
}
static unsigned F_153 ( void )
{
unsigned V_194 = F_25 ( V_195 ) ;
if ( V_194 > V_196 / V_197 )
V_194 = V_196 / V_197 ;
return V_194 * V_197 ;
}
static bool F_154 ( struct V_7 * V_8 , unsigned long V_198 )
{
return F_155 ( V_63 , V_8 -> V_62 + V_198 ) ;
}
static void F_156 ( struct V_1 * V_2 , unsigned long V_198 )
{
struct V_7 * V_8 , * V_131 ;
unsigned V_172 = F_132 ( V_2 ) ;
unsigned V_85 ;
F_4 ( V_2 ) ;
V_85 = V_2 -> V_58 [ V_132 ] + V_2 -> V_58 [ V_138 ] ;
F_94 (b, tmp, &c->lru[LIST_CLEAN], lru_list) {
if ( V_85 <= V_172 )
break;
if ( ! F_154 ( V_8 , V_198 ) )
break;
if ( F_131 ( V_8 , 0 ) )
V_85 -- ;
F_77 () ;
}
F_9 ( V_2 ) ;
}
static void F_157 ( void )
{
unsigned long V_199 = F_153 () ;
struct V_1 * V_2 ;
F_96 ( & V_36 ) ;
F_127 (c, &dm_bufio_all_clients, client_list)
F_156 ( V_2 , V_199 ) ;
F_10 ( & V_36 ) ;
}
static void F_158 ( struct V_200 * V_201 )
{
F_157 () ;
F_159 ( V_202 , & V_203 ,
V_204 * V_197 ) ;
}
static int T_4 F_160 ( void )
{
T_5 V_87 ;
V_30 = 0 ;
V_31 = 0 ;
V_32 = 0 ;
V_34 = 0 ;
memset ( & V_5 , 0 , sizeof V_5 ) ;
memset ( & V_205 , 0 , sizeof V_205 ) ;
V_87 = ( T_5 ) ( ( V_206 - V_207 ) *
V_208 / 100 ) << V_183 ;
if ( V_87 > V_209 )
V_87 = V_209 ;
#ifdef F_161
if ( V_87 > ( V_210 - V_211 ) * V_212 / 100 )
V_87 = ( V_210 - V_211 ) * V_212 / 100 ;
#endif
V_40 = V_87 ;
F_96 ( & V_36 ) ;
F_23 () ;
F_10 ( & V_36 ) ;
V_202 = F_162 ( L_5 , V_213 , 0 ) ;
if ( ! V_202 )
return - V_180 ;
F_163 ( & V_203 , F_158 ) ;
F_159 ( V_202 , & V_203 ,
V_204 * V_197 ) ;
return 0 ;
}
static void T_6 F_164 ( void )
{
int V_214 = 0 ;
int V_162 ;
F_165 ( & V_203 ) ;
F_166 ( V_202 ) ;
for ( V_162 = 0 ; V_162 < F_3 ( V_5 ) ; V_162 ++ )
F_167 ( V_5 [ V_162 ] ) ;
for ( V_162 = 0 ; V_162 < F_3 ( V_205 ) ; V_162 ++ )
F_42 ( V_205 [ V_162 ] ) ;
if ( V_37 ) {
F_38 ( L_6 ,
V_215 , V_37 ) ;
V_214 = 1 ;
}
if ( V_34 ) {
F_38 ( L_7 ,
V_215 , V_34 ) ;
V_214 = 1 ;
}
if ( V_31 ) {
F_38 ( L_8 ,
V_215 , V_31 ) ;
V_214 = 1 ;
}
if ( V_32 ) {
F_38 ( L_9 ,
V_215 , V_32 ) ;
V_214 = 1 ;
}
F_2 ( V_214 ) ;
}
