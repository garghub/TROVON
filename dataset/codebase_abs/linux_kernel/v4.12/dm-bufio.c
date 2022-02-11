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
V_8 -> V_64 . V_65 = error ? - V_66 : 0 ;
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
V_8 -> V_64 . V_65 = V_72 ;
V_71 ( & V_8 -> V_64 ) ;
}
}
static void F_53 ( struct V_64 * V_64 )
{
T_3 * V_90 = V_64 -> V_91 ;
int error = V_64 -> V_65 ;
F_54 ( V_64 ) ;
V_64 -> V_65 = error ;
V_90 ( V_64 ) ;
}
static void F_55 ( struct V_7 * V_8 , int V_68 , T_1 V_69 ,
unsigned V_70 , T_3 * V_71 )
{
char * V_44 ;
int V_92 ;
F_56 ( & V_8 -> V_64 , V_8 -> V_93 , V_94 ) ;
V_8 -> V_64 . V_95 . V_96 = V_69 ;
V_8 -> V_64 . V_97 = V_8 -> V_2 -> V_83 ;
V_8 -> V_64 . V_67 = F_53 ;
V_8 -> V_64 . V_91 = V_71 ;
F_57 ( & V_8 -> V_64 , V_68 , 0 ) ;
V_44 = V_8 -> V_54 ;
V_92 = V_70 << V_98 ;
if ( V_92 >= V_99 )
F_2 ( ( unsigned long ) V_44 & ( V_99 - 1 ) ) ;
else
F_2 ( ( unsigned long ) V_44 & ( V_92 - 1 ) ) ;
do {
if ( ! F_58 ( & V_8 -> V_64 , F_59 ( V_44 ) ,
V_92 < V_99 ? V_92 : V_99 ,
F_60 ( V_44 ) ) ) {
F_2 ( V_8 -> V_2 -> V_45 <= V_99 ) ;
F_52 ( V_8 , V_68 , V_69 , V_70 , V_71 ) ;
return;
}
V_92 -= V_99 ;
V_44 += V_99 ;
} while ( V_92 > 0 );
F_61 ( & V_8 -> V_64 ) ;
}
static void F_62 ( struct V_7 * V_8 , int V_68 , T_3 * V_71 )
{
unsigned V_70 ;
T_1 V_69 ;
if ( V_68 == V_100 && V_8 -> V_2 -> V_101 )
V_8 -> V_2 -> V_101 ( V_8 ) ;
V_69 = ( V_8 -> V_16 << V_8 -> V_2 -> V_102 ) + V_8 -> V_2 -> V_103 ;
V_70 = 1 << V_8 -> V_2 -> V_102 ;
if ( V_70 <= ( ( V_94 * V_99 ) >> V_98 ) &&
V_8 -> V_26 != V_52 )
F_55 ( V_8 , V_68 , V_69 , V_70 , V_71 ) ;
else
F_52 ( V_8 , V_68 , V_69 , V_70 , V_71 ) ;
}
static void F_63 ( struct V_64 * V_64 )
{
struct V_7 * V_8 = F_14 ( V_64 , struct V_7 , V_64 ) ;
V_8 -> V_104 = V_64 -> V_65 ;
if ( F_64 ( V_64 -> V_65 ) ) {
struct V_1 * V_2 = V_8 -> V_2 ;
int error = V_64 -> V_65 ;
( void ) F_26 ( & V_2 -> V_105 , 0 , error ) ;
}
F_2 ( ! F_65 ( V_106 , & V_8 -> V_107 ) ) ;
F_66 () ;
F_67 ( V_106 , & V_8 -> V_107 ) ;
F_68 () ;
F_69 ( & V_8 -> V_107 , V_106 ) ;
}
static void F_70 ( struct V_7 * V_8 ,
struct V_108 * V_109 )
{
if ( ! F_65 ( V_110 , & V_8 -> V_107 ) )
return;
F_67 ( V_110 , & V_8 -> V_107 ) ;
F_71 ( & V_8 -> V_107 , V_106 , V_111 ) ;
if ( ! V_109 )
F_62 ( V_8 , V_100 , F_63 ) ;
else
F_72 ( & V_8 -> V_109 , V_109 ) ;
}
static void F_73 ( struct V_108 * V_109 )
{
struct V_112 V_113 ;
F_74 ( & V_113 ) ;
while ( ! F_75 ( V_109 ) ) {
struct V_7 * V_8 =
F_76 ( V_109 -> V_114 , struct V_7 , V_109 ) ;
F_48 ( & V_8 -> V_109 ) ;
F_62 ( V_8 , V_100 , F_63 ) ;
F_77 () ;
}
F_78 ( & V_113 ) ;
}
static void F_79 ( struct V_7 * V_8 )
{
F_2 ( V_8 -> V_115 ) ;
if ( ! V_8 -> V_107 )
return;
F_80 ( & V_8 -> V_107 , V_116 , V_111 ) ;
F_70 ( V_8 , NULL ) ;
F_80 ( & V_8 -> V_107 , V_106 , V_111 ) ;
}
static struct V_7 * F_81 ( struct V_1 * V_2 )
{
struct V_7 * V_8 ;
F_82 (b, &c->lru[LIST_CLEAN], lru_list) {
F_2 ( F_65 ( V_106 , & V_8 -> V_107 ) ) ;
F_2 ( F_65 ( V_110 , & V_8 -> V_107 ) ) ;
if ( ! V_8 -> V_115 ) {
F_79 ( V_8 ) ;
F_47 ( V_8 ) ;
return V_8 ;
}
F_77 () ;
}
F_82 (b, &c->lru[LIST_DIRTY], lru_list) {
F_2 ( F_65 ( V_116 , & V_8 -> V_107 ) ) ;
if ( ! V_8 -> V_115 ) {
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
F_84 ( V_117 , V_118 ) ;
F_85 ( & V_2 -> V_119 , & V_117 ) ;
F_86 ( V_111 ) ;
F_9 ( V_2 ) ;
F_87 () ;
F_88 ( & V_2 -> V_119 , & V_117 ) ;
F_4 ( V_2 ) ;
}
static struct V_7 * F_89 ( struct V_1 * V_2 , enum V_120 V_121 )
{
struct V_7 * V_8 ;
bool V_122 = false ;
while ( 1 ) {
if ( V_38 != 1 ) {
V_8 = F_40 ( V_2 , V_123 | V_49 | V_124 | V_125 ) ;
if ( V_8 )
return V_8 ;
}
if ( V_121 == V_126 )
return NULL ;
if ( V_38 != 1 && ! V_122 ) {
F_9 ( V_2 ) ;
V_8 = F_40 ( V_2 , V_127 | V_49 | V_124 | V_125 ) ;
F_4 ( V_2 ) ;
if ( V_8 )
return V_8 ;
V_122 = true ;
}
if ( ! F_75 ( & V_2 -> V_128 ) ) {
V_8 = F_76 ( V_2 -> V_128 . V_114 ,
struct V_7 , V_59 ) ;
F_48 ( & V_8 -> V_59 ) ;
V_2 -> V_129 ++ ;
return V_8 ;
}
V_8 = F_81 ( V_2 ) ;
if ( V_8 )
return V_8 ;
F_83 ( V_2 ) ;
}
}
static struct V_7 * F_90 ( struct V_1 * V_2 , enum V_120 V_121 )
{
struct V_7 * V_8 = F_89 ( V_2 , V_121 ) ;
if ( ! V_8 )
return NULL ;
if ( V_2 -> V_130 )
V_2 -> V_130 ( V_8 ) ;
return V_8 ;
}
static void F_91 ( struct V_7 * V_8 )
{
struct V_1 * V_2 = V_8 -> V_2 ;
if ( ! V_2 -> V_129 )
F_44 ( V_8 ) ;
else {
F_46 ( & V_8 -> V_59 , & V_2 -> V_128 ) ;
V_2 -> V_129 -- ;
}
F_92 ( & V_2 -> V_119 ) ;
}
static void F_93 ( struct V_1 * V_2 , int V_131 ,
struct V_108 * V_109 )
{
struct V_7 * V_8 , * V_132 ;
F_94 (b, tmp, &c->lru[LIST_DIRTY], lru_list) {
F_2 ( F_65 ( V_116 , & V_8 -> V_107 ) ) ;
if ( ! F_65 ( V_110 , & V_8 -> V_107 ) &&
! F_65 ( V_106 , & V_8 -> V_107 ) ) {
F_49 ( V_8 , V_133 ) ;
continue;
}
if ( V_131 && F_65 ( V_106 , & V_8 -> V_107 ) )
return;
F_70 ( V_8 , V_109 ) ;
F_77 () ;
}
}
static void F_95 ( struct V_1 * V_2 ,
unsigned long * V_134 ,
unsigned long * V_135 )
{
unsigned long V_136 ;
if ( F_64 ( F_25 ( V_39 ) != V_38 ) ) {
if ( F_8 ( & V_36 ) ) {
F_23 () ;
F_10 ( & V_36 ) ;
}
}
V_136 = V_41 >>
( V_2 -> V_102 + V_98 ) ;
if ( V_136 < V_2 -> V_137 )
V_136 = V_2 -> V_137 ;
* V_135 = V_136 ;
* V_134 = V_136 * V_138 / 100 ;
}
static void F_96 ( struct V_1 * V_2 ,
struct V_108 * V_109 )
{
unsigned long V_134 , V_135 ;
F_95 ( V_2 , & V_134 , & V_135 ) ;
while ( V_2 -> V_57 [ V_133 ] + V_2 -> V_57 [ V_139 ] >
V_135 ) {
struct V_7 * V_8 = F_81 ( V_2 ) ;
if ( ! V_8 )
return;
F_91 ( V_8 ) ;
F_77 () ;
}
if ( V_2 -> V_57 [ V_139 ] > V_134 )
F_93 ( V_2 , 1 , V_109 ) ;
}
static struct V_7 * F_97 ( struct V_1 * V_2 , T_1 V_16 ,
enum V_120 V_121 , int * V_140 ,
struct V_108 * V_109 )
{
struct V_7 * V_8 , * V_141 = NULL ;
* V_140 = 0 ;
V_8 = F_13 ( V_2 , V_16 ) ;
if ( V_8 )
goto V_142;
if ( V_121 == V_143 )
return NULL ;
V_141 = F_90 ( V_2 , V_121 ) ;
if ( ! V_141 )
return NULL ;
V_8 = F_13 ( V_2 , V_16 ) ;
if ( V_8 ) {
F_91 ( V_141 ) ;
goto V_142;
}
F_96 ( V_2 , V_109 ) ;
V_8 = V_141 ;
V_8 -> V_115 = 1 ;
V_8 -> V_144 = 0 ;
V_8 -> V_104 = 0 ;
F_45 ( V_8 , V_16 , V_133 ) ;
if ( V_121 == V_145 ) {
V_8 -> V_107 = 0 ;
return V_8 ;
}
V_8 -> V_107 = 1 << V_116 ;
* V_140 = 1 ;
return V_8 ;
V_142:
if ( V_121 == V_126 )
return NULL ;
if ( V_121 == V_143 && F_64 ( F_65 ( V_116 , & V_8 -> V_107 ) ) )
return NULL ;
V_8 -> V_115 ++ ;
F_49 ( V_8 , F_65 ( V_110 , & V_8 -> V_107 ) ||
F_65 ( V_106 , & V_8 -> V_107 ) ) ;
return V_8 ;
}
static void F_98 ( struct V_64 * V_64 )
{
struct V_7 * V_8 = F_14 ( V_64 , struct V_7 , V_64 ) ;
V_8 -> V_144 = V_64 -> V_65 ;
F_2 ( ! F_65 ( V_116 , & V_8 -> V_107 ) ) ;
F_66 () ;
F_67 ( V_116 , & V_8 -> V_107 ) ;
F_68 () ;
F_69 ( & V_8 -> V_107 , V_116 ) ;
}
static void * F_99 ( struct V_1 * V_2 , T_1 V_16 ,
enum V_120 V_121 , struct V_7 * * V_146 )
{
int V_140 ;
struct V_7 * V_8 ;
F_100 ( V_109 ) ;
F_4 ( V_2 ) ;
V_8 = F_97 ( V_2 , V_16 , V_121 , & V_140 , & V_109 ) ;
#ifdef F_43
if ( V_8 && V_8 -> V_115 == 1 )
F_11 ( V_8 ) ;
#endif
F_9 ( V_2 ) ;
F_73 ( & V_109 ) ;
if ( ! V_8 )
return NULL ;
if ( V_140 )
F_62 ( V_8 , V_147 , F_98 ) ;
F_80 ( & V_8 -> V_107 , V_116 , V_111 ) ;
if ( V_8 -> V_144 ) {
int error = V_8 -> V_144 ;
F_101 ( V_8 ) ;
return F_102 ( error ) ;
}
* V_146 = V_8 ;
return V_8 -> V_54 ;
}
void * F_103 ( struct V_1 * V_2 , T_1 V_16 ,
struct V_7 * * V_146 )
{
return F_99 ( V_2 , V_16 , V_143 , V_146 ) ;
}
void * F_104 ( struct V_1 * V_2 , T_1 V_16 ,
struct V_7 * * V_146 )
{
F_2 ( F_6 () ) ;
return F_99 ( V_2 , V_16 , V_148 , V_146 ) ;
}
void * F_105 ( struct V_1 * V_2 , T_1 V_16 ,
struct V_7 * * V_146 )
{
F_2 ( F_6 () ) ;
return F_99 ( V_2 , V_16 , V_145 , V_146 ) ;
}
void F_106 ( struct V_1 * V_2 ,
T_1 V_16 , unsigned V_149 )
{
struct V_112 V_113 ;
F_100 ( V_109 ) ;
F_2 ( F_6 () ) ;
F_74 ( & V_113 ) ;
F_4 ( V_2 ) ;
for (; V_149 -- ; V_16 ++ ) {
int V_140 ;
struct V_7 * V_8 ;
V_8 = F_97 ( V_2 , V_16 , V_126 , & V_140 ,
& V_109 ) ;
if ( F_64 ( ! F_75 ( & V_109 ) ) ) {
F_9 ( V_2 ) ;
F_78 ( & V_113 ) ;
F_73 ( & V_109 ) ;
F_74 ( & V_113 ) ;
F_4 ( V_2 ) ;
}
if ( F_64 ( V_8 != NULL ) ) {
F_9 ( V_2 ) ;
if ( V_140 )
F_62 ( V_8 , V_147 , F_98 ) ;
F_101 ( V_8 ) ;
F_77 () ;
if ( ! V_149 )
goto V_150;
F_4 ( V_2 ) ;
}
}
F_9 ( V_2 ) ;
V_150:
F_78 ( & V_113 ) ;
}
void F_101 ( struct V_7 * V_8 )
{
struct V_1 * V_2 = V_8 -> V_2 ;
F_4 ( V_2 ) ;
F_2 ( ! V_8 -> V_115 ) ;
V_8 -> V_115 -- ;
if ( ! V_8 -> V_115 ) {
F_92 ( & V_2 -> V_119 ) ;
if ( ( V_8 -> V_144 || V_8 -> V_104 ) &&
! F_65 ( V_116 , & V_8 -> V_107 ) &&
! F_65 ( V_106 , & V_8 -> V_107 ) &&
! F_65 ( V_110 , & V_8 -> V_107 ) ) {
F_47 ( V_8 ) ;
F_91 ( V_8 ) ;
}
}
F_9 ( V_2 ) ;
}
void F_107 ( struct V_7 * V_8 )
{
struct V_1 * V_2 = V_8 -> V_2 ;
F_4 ( V_2 ) ;
F_2 ( F_65 ( V_116 , & V_8 -> V_107 ) ) ;
if ( ! F_108 ( V_110 , & V_8 -> V_107 ) )
F_49 ( V_8 , V_139 ) ;
F_9 ( V_2 ) ;
}
void F_109 ( struct V_1 * V_2 )
{
F_100 ( V_109 ) ;
F_2 ( F_6 () ) ;
F_4 ( V_2 ) ;
F_93 ( V_2 , 0 , & V_109 ) ;
F_9 ( V_2 ) ;
F_73 ( & V_109 ) ;
}
int F_110 ( struct V_1 * V_2 )
{
int V_151 , V_152 ;
unsigned long V_153 = 0 ;
struct V_7 * V_8 , * V_132 ;
F_100 ( V_109 ) ;
F_4 ( V_2 ) ;
F_93 ( V_2 , 0 , & V_109 ) ;
F_9 ( V_2 ) ;
F_73 ( & V_109 ) ;
F_4 ( V_2 ) ;
V_154:
F_94 (b, tmp, &c->lru[LIST_DIRTY], lru_list) {
int V_155 = 0 ;
if ( V_153 < V_2 -> V_57 [ V_139 ] )
V_153 ++ ;
F_2 ( F_65 ( V_116 , & V_8 -> V_107 ) ) ;
if ( F_65 ( V_106 , & V_8 -> V_107 ) ) {
if ( V_153 < V_2 -> V_57 [ V_139 ] ) {
V_155 = 1 ;
V_8 -> V_115 ++ ;
F_9 ( V_2 ) ;
F_80 ( & V_8 -> V_107 , V_106 ,
V_111 ) ;
F_4 ( V_2 ) ;
V_8 -> V_115 -- ;
} else
F_80 ( & V_8 -> V_107 , V_106 ,
V_111 ) ;
}
if ( ! F_65 ( V_110 , & V_8 -> V_107 ) &&
! F_65 ( V_106 , & V_8 -> V_107 ) )
F_49 ( V_8 , V_133 ) ;
F_77 () ;
if ( V_155 )
goto V_154;
}
F_92 ( & V_2 -> V_119 ) ;
F_9 ( V_2 ) ;
V_151 = F_111 ( & V_2 -> V_105 , 0 ) ;
V_152 = F_112 ( V_2 ) ;
if ( V_151 )
return V_151 ;
return V_152 ;
}
int F_112 ( struct V_1 * V_2 )
{
struct V_73 V_74 = {
. V_75 = V_156 ,
. V_76 = V_157 | V_158 ,
. V_85 . type = V_86 ,
. V_85 . V_44 . V_87 = NULL ,
. V_79 = V_2 -> V_80 ,
} ;
struct V_81 V_159 = {
. V_83 = V_2 -> V_83 ,
. V_69 = 0 ,
. V_84 = 0 ,
} ;
F_2 ( F_6 () ) ;
return V_80 ( & V_74 , 1 , & V_159 , NULL ) ;
}
void F_113 ( struct V_7 * V_8 , T_1 V_160 )
{
struct V_1 * V_2 = V_8 -> V_2 ;
struct V_7 * V_23 ;
F_2 ( F_6 () ) ;
F_4 ( V_2 ) ;
V_161:
V_23 = F_13 ( V_2 , V_160 ) ;
if ( V_23 ) {
if ( V_23 -> V_115 ) {
F_83 ( V_2 ) ;
goto V_161;
}
F_79 ( V_23 ) ;
F_47 ( V_23 ) ;
F_91 ( V_23 ) ;
}
F_2 ( ! V_8 -> V_115 ) ;
F_2 ( F_65 ( V_116 , & V_8 -> V_107 ) ) ;
F_70 ( V_8 , NULL ) ;
if ( V_8 -> V_115 == 1 ) {
F_80 ( & V_8 -> V_107 , V_106 ,
V_111 ) ;
F_114 ( V_110 , & V_8 -> V_107 ) ;
F_47 ( V_8 ) ;
F_45 ( V_8 , V_160 , V_139 ) ;
} else {
T_1 V_162 ;
F_71 ( & V_8 -> V_107 , V_106 ,
V_111 ) ;
V_162 = V_8 -> V_16 ;
F_47 ( V_8 ) ;
F_45 ( V_8 , V_160 , V_8 -> V_58 ) ;
F_62 ( V_8 , V_100 , F_63 ) ;
F_80 ( & V_8 -> V_107 , V_106 ,
V_111 ) ;
F_47 ( V_8 ) ;
F_45 ( V_8 , V_162 , V_8 -> V_58 ) ;
}
F_9 ( V_2 ) ;
F_101 ( V_8 ) ;
}
void F_115 ( struct V_1 * V_2 , T_1 V_16 )
{
struct V_7 * V_8 ;
F_4 ( V_2 ) ;
V_8 = F_13 ( V_2 , V_16 ) ;
if ( V_8 && F_116 ( ! V_8 -> V_115 ) && F_116 ( ! V_8 -> V_107 ) ) {
F_47 ( V_8 ) ;
F_91 ( V_8 ) ;
}
F_9 ( V_2 ) ;
}
void F_117 ( struct V_1 * V_2 , unsigned V_18 )
{
V_2 -> V_137 = V_18 ;
}
unsigned F_118 ( struct V_1 * V_2 )
{
return V_2 -> V_45 ;
}
T_1 F_119 ( struct V_1 * V_2 )
{
return F_120 ( V_2 -> V_83 -> V_163 ) >>
( V_98 + V_2 -> V_102 ) ;
}
T_1 F_121 ( struct V_7 * V_8 )
{
return V_8 -> V_16 ;
}
void * F_122 ( struct V_7 * V_8 )
{
return V_8 -> V_54 ;
}
void * F_123 ( struct V_7 * V_8 )
{
return V_8 + 1 ;
}
struct V_1 * F_124 ( struct V_7 * V_8 )
{
return V_8 -> V_2 ;
}
static void F_125 ( struct V_1 * V_2 )
{
struct V_7 * V_8 ;
int V_164 ;
bool V_165 = false ;
F_2 ( F_6 () ) ;
F_109 ( V_2 ) ;
F_4 ( V_2 ) ;
while ( ( V_8 = F_81 ( V_2 ) ) )
F_91 ( V_8 ) ;
for ( V_164 = 0 ; V_164 < V_166 ; V_164 ++ )
F_126 (b, &c->lru[i], lru_list) {
F_127 ( ! V_165 ) ;
V_165 = true ;
F_128 ( L_2 ,
( unsigned long long ) V_8 -> V_16 , V_8 -> V_115 , V_164 ) ;
#ifdef F_43
F_129 ( & V_8 -> V_9 , 1 ) ;
V_8 -> V_115 = 0 ;
#endif
}
#ifdef F_43
while ( ( V_8 = F_81 ( V_2 ) ) )
F_91 ( V_8 ) ;
#endif
for ( V_164 = 0 ; V_164 < V_166 ; V_164 ++ )
F_2 ( ! F_75 ( & V_2 -> V_60 [ V_164 ] ) ) ;
F_9 ( V_2 ) ;
}
static bool F_130 ( struct V_7 * V_8 , T_2 V_167 )
{
if ( ! ( V_167 & V_168 ) ) {
if ( F_65 ( V_116 , & V_8 -> V_107 ) ||
F_65 ( V_106 , & V_8 -> V_107 ) ||
F_65 ( V_110 , & V_8 -> V_107 ) )
return false ;
}
if ( V_8 -> V_115 )
return false ;
F_79 ( V_8 ) ;
F_47 ( V_8 ) ;
F_91 ( V_8 ) ;
return true ;
}
static unsigned long F_131 ( struct V_1 * V_2 )
{
unsigned long V_169 = F_25 ( V_170 ) ;
return V_169 >> ( V_2 -> V_102 + V_98 ) ;
}
static unsigned long F_132 ( struct V_1 * V_2 , unsigned long V_171 ,
T_2 V_42 )
{
int V_172 ;
struct V_7 * V_8 , * V_132 ;
unsigned long V_173 = 0 ;
unsigned long V_84 = V_171 ;
unsigned long V_174 = F_131 ( V_2 ) ;
for ( V_172 = 0 ; V_172 < V_166 ; V_172 ++ ) {
F_94 (b, tmp, &c->lru[l], lru_list) {
if ( F_130 ( V_8 , V_42 ) )
V_173 ++ ;
if ( ! -- V_171 || ( ( V_84 - V_173 ) <= V_174 ) )
return V_173 ;
F_77 () ;
}
}
return V_173 ;
}
static unsigned long
F_133 ( struct V_175 * V_176 , struct V_177 * V_178 )
{
struct V_1 * V_2 ;
unsigned long V_173 ;
V_2 = F_14 ( V_176 , struct V_1 , V_175 ) ;
if ( V_178 -> V_42 & V_168 )
F_4 ( V_2 ) ;
else if ( ! F_7 ( V_2 ) )
return V_179 ;
V_173 = F_132 ( V_2 , V_178 -> V_171 , V_178 -> V_42 ) ;
F_9 ( V_2 ) ;
return V_173 ;
}
static unsigned long
F_134 ( struct V_175 * V_176 , struct V_177 * V_178 )
{
struct V_1 * V_2 = F_14 ( V_176 , struct V_1 , V_175 ) ;
return F_25 ( V_2 -> V_57 [ V_133 ] ) + F_25 ( V_2 -> V_57 [ V_139 ] ) ;
}
struct V_1 * F_135 ( struct V_180 * V_83 , unsigned V_45 ,
unsigned V_128 , unsigned V_55 ,
void (* V_130)( struct V_7 * ) ,
void (* V_101)( struct V_7 * ) )
{
int V_72 ;
struct V_1 * V_2 ;
unsigned V_164 ;
F_2 ( V_45 < 1 << V_98 ||
( V_45 & ( V_45 - 1 ) ) ) ;
V_2 = F_136 ( sizeof( * V_2 ) , V_181 ) ;
if ( ! V_2 ) {
V_72 = - V_182 ;
goto V_183;
}
V_2 -> V_19 = V_184 ;
V_2 -> V_83 = V_83 ;
V_2 -> V_45 = V_45 ;
V_2 -> V_102 = F_137 ( V_45 ) - V_98 ;
V_2 -> V_51 = ( F_137 ( V_45 ) >= V_185 ) ?
F_137 ( V_45 ) - V_185 : 0 ;
V_2 -> V_4 = ( F_137 ( V_45 ) < V_185 ?
V_185 - F_137 ( V_45 ) : 0 ) ;
V_2 -> V_55 = V_55 ;
V_2 -> V_130 = V_130 ;
V_2 -> V_101 = V_101 ;
for ( V_164 = 0 ; V_164 < V_166 ; V_164 ++ ) {
F_138 ( & V_2 -> V_60 [ V_164 ] ) ;
V_2 -> V_57 [ V_164 ] = 0 ;
}
F_139 ( & V_2 -> V_6 ) ;
F_138 ( & V_2 -> V_128 ) ;
V_2 -> V_129 = V_128 ;
V_2 -> V_137 = V_186 ;
F_140 ( & V_2 -> V_119 ) ;
V_2 -> V_105 = 0 ;
V_2 -> V_80 = F_141 () ;
if ( F_142 ( V_2 -> V_80 ) ) {
V_72 = F_143 ( V_2 -> V_80 ) ;
goto V_187;
}
F_144 ( & V_36 ) ;
if ( V_2 -> V_4 ) {
if ( ! F_145 ( V_2 ) ) {
F_145 ( V_2 ) = F_146 ( V_181 , L_3 , V_2 -> V_45 ) ;
if ( ! F_145 ( V_2 ) ) {
V_72 = - V_182 ;
F_10 ( & V_36 ) ;
goto V_188;
}
}
if ( ! F_29 ( V_2 ) ) {
F_29 ( V_2 ) = F_147 ( F_145 ( V_2 ) ,
V_2 -> V_45 ,
V_2 -> V_45 , 0 , NULL ) ;
if ( ! F_29 ( V_2 ) ) {
V_72 = - V_182 ;
F_10 ( & V_36 ) ;
goto V_188;
}
}
}
F_10 ( & V_36 ) ;
while ( V_2 -> V_129 ) {
struct V_7 * V_8 = F_40 ( V_2 , V_181 ) ;
if ( ! V_8 ) {
V_72 = - V_182 ;
goto V_189;
}
F_91 ( V_8 ) ;
}
F_144 ( & V_36 ) ;
V_37 ++ ;
F_46 ( & V_2 -> V_190 , & V_191 ) ;
F_23 () ;
F_10 ( & V_36 ) ;
V_2 -> V_175 . V_192 = F_134 ;
V_2 -> V_175 . V_193 = F_133 ;
V_2 -> V_175 . V_194 = 1 ;
V_2 -> V_175 . V_195 = 0 ;
F_148 ( & V_2 -> V_175 ) ;
return V_2 ;
V_189:
V_188:
while ( ! F_75 ( & V_2 -> V_128 ) ) {
struct V_7 * V_8 = F_76 ( V_2 -> V_128 . V_114 ,
struct V_7 , V_59 ) ;
F_48 ( & V_8 -> V_59 ) ;
F_44 ( V_8 ) ;
}
F_149 ( V_2 -> V_80 ) ;
V_187:
F_42 ( V_2 ) ;
V_183:
return F_102 ( V_72 ) ;
}
void F_150 ( struct V_1 * V_2 )
{
unsigned V_164 ;
F_125 ( V_2 ) ;
F_151 ( & V_2 -> V_175 ) ;
F_144 ( & V_36 ) ;
F_48 ( & V_2 -> V_190 ) ;
V_37 -- ;
F_23 () ;
F_10 ( & V_36 ) ;
F_2 ( ! F_152 ( & V_2 -> V_19 ) ) ;
F_2 ( V_2 -> V_129 ) ;
while ( ! F_75 ( & V_2 -> V_128 ) ) {
struct V_7 * V_8 = F_76 ( V_2 -> V_128 . V_114 ,
struct V_7 , V_59 ) ;
F_48 ( & V_8 -> V_59 ) ;
F_44 ( V_8 ) ;
}
for ( V_164 = 0 ; V_164 < V_166 ; V_164 ++ )
if ( V_2 -> V_57 [ V_164 ] )
F_128 ( L_4 , V_164 , V_2 -> V_57 [ V_164 ] ) ;
for ( V_164 = 0 ; V_164 < V_166 ; V_164 ++ )
F_2 ( V_2 -> V_57 [ V_164 ] ) ;
F_149 ( V_2 -> V_80 ) ;
F_42 ( V_2 ) ;
}
void F_153 ( struct V_1 * V_2 , T_1 V_103 )
{
V_2 -> V_103 = V_103 ;
}
static unsigned F_154 ( void )
{
unsigned V_196 = F_25 ( V_197 ) ;
if ( V_196 > V_198 / V_199 )
V_196 = V_198 / V_199 ;
return V_196 * V_199 ;
}
static bool F_155 ( struct V_7 * V_8 , unsigned long V_200 )
{
return F_156 ( V_62 , V_8 -> V_61 + V_200 ) ;
}
static void F_157 ( struct V_1 * V_2 , unsigned long V_200 )
{
struct V_7 * V_8 , * V_132 ;
unsigned long V_174 = F_131 ( V_2 ) ;
unsigned long V_84 ;
F_100 ( V_109 ) ;
F_4 ( V_2 ) ;
F_96 ( V_2 , & V_109 ) ;
if ( F_64 ( ! F_75 ( & V_109 ) ) ) {
F_9 ( V_2 ) ;
F_73 ( & V_109 ) ;
F_4 ( V_2 ) ;
}
V_84 = V_2 -> V_57 [ V_133 ] + V_2 -> V_57 [ V_139 ] ;
F_94 (b, tmp, &c->lru[LIST_CLEAN], lru_list) {
if ( V_84 <= V_174 )
break;
if ( ! F_155 ( V_8 , V_200 ) )
break;
if ( F_130 ( V_8 , 0 ) )
V_84 -- ;
F_77 () ;
}
F_9 ( V_2 ) ;
}
static void F_158 ( void )
{
unsigned long V_201 = F_154 () ;
struct V_1 * V_2 ;
F_144 ( & V_36 ) ;
F_23 () ;
F_126 (c, &dm_bufio_all_clients, client_list)
F_157 ( V_2 , V_201 ) ;
F_10 ( & V_36 ) ;
}
static void F_159 ( struct V_202 * V_203 )
{
F_158 () ;
F_160 ( V_204 , & V_205 ,
V_206 * V_199 ) ;
}
static int T_4 F_161 ( void )
{
T_5 V_85 ;
V_30 = 0 ;
V_31 = 0 ;
V_32 = 0 ;
V_34 = 0 ;
memset ( & V_5 , 0 , sizeof V_5 ) ;
memset ( & V_207 , 0 , sizeof V_207 ) ;
V_85 = ( T_5 ) ( ( V_208 - V_209 ) *
V_210 / 100 ) << V_185 ;
if ( V_85 > V_211 )
V_85 = V_211 ;
#ifdef F_162
if ( V_85 > ( V_212 - V_213 ) * V_214 / 100 )
V_85 = ( V_212 - V_213 ) * V_214 / 100 ;
#endif
V_40 = V_85 ;
F_144 ( & V_36 ) ;
F_23 () ;
F_10 ( & V_36 ) ;
V_204 = F_163 ( L_5 , V_215 , 0 ) ;
if ( ! V_204 )
return - V_182 ;
F_164 ( & V_205 , F_159 ) ;
F_160 ( V_204 , & V_205 ,
V_206 * V_199 ) ;
return 0 ;
}
static void T_6 F_165 ( void )
{
int V_216 = 0 ;
int V_164 ;
F_166 ( & V_205 ) ;
F_167 ( V_204 ) ;
for ( V_164 = 0 ; V_164 < F_3 ( V_5 ) ; V_164 ++ )
F_168 ( V_5 [ V_164 ] ) ;
for ( V_164 = 0 ; V_164 < F_3 ( V_207 ) ; V_164 ++ )
F_42 ( V_207 [ V_164 ] ) ;
if ( V_37 ) {
F_38 ( L_6 ,
V_217 , V_37 ) ;
V_216 = 1 ;
}
if ( V_34 ) {
F_38 ( L_7 ,
V_217 , V_34 ) ;
V_216 = 1 ;
}
if ( V_31 ) {
F_38 ( L_8 ,
V_217 , V_31 ) ;
V_216 = 1 ;
}
if ( V_32 ) {
F_38 ( L_9 ,
V_217 , V_32 ) ;
V_216 = 1 ;
}
F_2 ( V_216 ) ;
}
