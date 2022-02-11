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
static void F_11 ( enum V_7 V_7 , long V_8 )
{
static unsigned long * const V_9 [ V_10 ] = {
& V_11 ,
& V_12 ,
& V_13 ,
} ;
F_12 ( & V_14 ) ;
* V_9 [ V_7 ] += V_8 ;
V_15 += V_8 ;
if ( V_15 > V_16 )
V_16 = V_15 ;
F_13 ( & V_14 ) ;
}
static void F_14 ( void )
{
F_2 ( ! F_15 ( & V_17 ) ) ;
F_2 ( V_18 < 0 ) ;
V_19 = F_16 ( V_20 ) ;
if ( ! V_19 ) {
( void ) F_17 ( & V_20 , 0 ,
V_21 ) ;
V_19 = V_21 ;
}
V_22 = V_19 /
( V_18 ? : 1 ) ;
}
static void * F_18 ( struct V_1 * V_2 , T_1 V_23 ,
enum V_7 * V_7 )
{
unsigned V_24 ;
void * V_25 ;
if ( V_2 -> V_26 <= V_27 ) {
* V_7 = V_28 ;
return F_19 ( F_20 ( V_2 ) , V_23 ) ;
}
if ( V_2 -> V_26 <= V_29 &&
V_23 & V_30 ) {
* V_7 = V_31 ;
return ( void * ) F_21 ( V_23 ,
V_2 -> V_32 ) ;
}
* V_7 = V_33 ;
if ( V_23 & V_30 )
V_24 = F_22 () ;
V_25 = F_23 ( V_2 -> V_26 , V_23 | V_34 , V_35 ) ;
if ( V_23 & V_30 )
F_24 ( V_24 ) ;
return V_25 ;
}
static void F_25 ( struct V_1 * V_2 ,
void * V_36 , enum V_7 V_7 )
{
switch ( V_7 ) {
case V_28 :
F_26 ( F_20 ( V_2 ) , V_36 ) ;
break;
case V_31 :
F_27 ( ( unsigned long ) V_36 , V_2 -> V_32 ) ;
break;
case V_33 :
F_28 ( V_36 ) ;
break;
default:
F_29 ( L_1 ,
V_7 ) ;
F_30 () ;
}
}
static struct V_37 * F_31 ( struct V_1 * V_2 , T_1 V_23 )
{
struct V_37 * V_38 = F_32 ( sizeof( struct V_37 ) + V_2 -> V_39 ,
V_23 ) ;
if ( ! V_38 )
return NULL ;
V_38 -> V_2 = V_2 ;
V_38 -> V_36 = F_18 ( V_2 , V_23 , & V_38 -> V_7 ) ;
if ( ! V_38 -> V_36 ) {
F_33 ( V_38 ) ;
return NULL ;
}
F_11 ( V_38 -> V_7 , ( long ) V_2 -> V_26 ) ;
return V_38 ;
}
static void F_34 ( struct V_37 * V_38 )
{
struct V_1 * V_2 = V_38 -> V_2 ;
F_11 ( V_38 -> V_7 , - ( long ) V_2 -> V_26 ) ;
F_25 ( V_2 , V_38 -> V_36 , V_38 -> V_7 ) ;
F_33 ( V_38 ) ;
}
static void F_35 ( struct V_37 * V_38 , T_2 V_40 , int V_41 )
{
struct V_1 * V_2 = V_38 -> V_2 ;
V_2 -> V_42 [ V_41 ] ++ ;
V_38 -> V_40 = V_40 ;
V_38 -> V_43 = V_41 ;
F_36 ( & V_38 -> V_44 , & V_2 -> V_45 [ V_41 ] ) ;
F_37 ( & V_38 -> V_46 , & V_2 -> V_47 [ F_38 ( V_40 ) ] ) ;
V_38 -> V_48 = V_49 ;
}
static void F_39 ( struct V_37 * V_38 )
{
struct V_1 * V_2 = V_38 -> V_2 ;
F_2 ( ! V_2 -> V_42 [ V_38 -> V_43 ] ) ;
V_2 -> V_42 [ V_38 -> V_43 ] -- ;
F_40 ( & V_38 -> V_46 ) ;
F_41 ( & V_38 -> V_44 ) ;
}
static void F_42 ( struct V_37 * V_38 , int V_41 )
{
struct V_1 * V_2 = V_38 -> V_2 ;
F_2 ( ! V_2 -> V_42 [ V_38 -> V_43 ] ) ;
V_2 -> V_42 [ V_38 -> V_43 ] -- ;
V_2 -> V_42 [ V_41 ] ++ ;
V_38 -> V_43 = V_41 ;
F_43 ( & V_38 -> V_44 , & V_2 -> V_45 [ V_41 ] ) ;
V_38 -> V_48 = V_49 ;
}
static void F_44 ( unsigned long error , void * V_50 )
{
struct V_37 * V_38 = V_50 ;
V_38 -> V_51 . V_52 ( & V_38 -> V_51 , error ? - V_53 : 0 ) ;
}
static void F_45 ( struct V_37 * V_38 , int V_54 , T_2 V_40 ,
T_3 * V_55 )
{
int V_56 ;
struct V_57 V_58 = {
. V_59 = V_54 ,
. V_60 . V_61 = F_44 ,
. V_60 . V_50 = V_38 ,
. V_62 = V_38 -> V_2 -> V_63 ,
} ;
struct V_64 V_65 = {
. V_66 = V_38 -> V_2 -> V_66 ,
. V_67 = V_40 << V_38 -> V_2 -> V_68 ,
. V_69 = V_38 -> V_2 -> V_26 >> V_70 ,
} ;
if ( V_38 -> V_7 != V_33 ) {
V_58 . V_71 . type = V_72 ;
V_58 . V_71 . V_25 . V_73 = V_38 -> V_36 ;
} else {
V_58 . V_71 . type = V_74 ;
V_58 . V_71 . V_25 . V_75 = V_38 -> V_36 ;
}
V_38 -> V_51 . V_52 = V_55 ;
V_56 = V_63 ( & V_58 , 1 , & V_65 , NULL ) ;
if ( V_56 )
V_55 ( & V_38 -> V_51 , V_56 ) ;
}
static void F_46 ( struct V_37 * V_38 , int V_54 , T_2 V_40 ,
T_3 * V_55 )
{
char * V_25 ;
int V_76 ;
F_47 ( & V_38 -> V_51 ) ;
V_38 -> V_51 . V_77 = V_38 -> V_78 ;
V_38 -> V_51 . V_79 = V_80 ;
V_38 -> V_51 . V_81 . V_82 = V_40 << V_38 -> V_2 -> V_68 ;
V_38 -> V_51 . V_83 = V_38 -> V_2 -> V_66 ;
V_38 -> V_51 . V_52 = V_55 ;
V_25 = V_38 -> V_36 ;
V_76 = V_38 -> V_2 -> V_26 ;
if ( V_76 >= V_84 )
F_2 ( ( unsigned long ) V_25 & ( V_84 - 1 ) ) ;
else
F_2 ( ( unsigned long ) V_25 & ( V_76 - 1 ) ) ;
do {
if ( ! F_48 ( & V_38 -> V_51 , F_49 ( V_25 ) ,
V_76 < V_84 ? V_76 : V_84 ,
F_50 ( V_25 ) & ( V_84 - 1 ) ) ) {
F_2 ( V_38 -> V_2 -> V_26 <= V_84 ) ;
F_45 ( V_38 , V_54 , V_40 , V_55 ) ;
return;
}
V_76 -= V_84 ;
V_25 += V_84 ;
} while ( V_76 > 0 );
F_51 ( V_54 , & V_38 -> V_51 ) ;
}
static void F_52 ( struct V_37 * V_38 , int V_54 , T_2 V_40 ,
T_3 * V_55 )
{
if ( V_54 == V_85 && V_38 -> V_2 -> V_86 )
V_38 -> V_2 -> V_86 ( V_38 ) ;
if ( V_38 -> V_2 -> V_26 <= V_80 * V_84 &&
V_38 -> V_7 != V_33 )
F_46 ( V_38 , V_54 , V_40 , V_55 ) ;
else
F_45 ( V_38 , V_54 , V_40 , V_55 ) ;
}
static void F_53 ( struct V_51 * V_51 , int error )
{
struct V_37 * V_38 = F_54 ( V_51 , struct V_37 , V_51 ) ;
V_38 -> V_87 = error ;
if ( F_55 ( error ) ) {
struct V_1 * V_2 = V_38 -> V_2 ;
( void ) F_17 ( & V_2 -> V_88 , 0 , error ) ;
}
F_2 ( ! F_56 ( V_89 , & V_38 -> V_90 ) ) ;
F_57 () ;
F_58 ( V_89 , & V_38 -> V_90 ) ;
F_59 () ;
F_60 ( & V_38 -> V_90 , V_89 ) ;
}
static void F_61 ( struct V_37 * V_38 ,
struct V_91 * V_92 )
{
if ( ! F_56 ( V_93 , & V_38 -> V_90 ) )
return;
F_58 ( V_93 , & V_38 -> V_90 ) ;
F_62 ( & V_38 -> V_90 , V_89 , V_94 ) ;
if ( ! V_92 )
F_52 ( V_38 , V_85 , V_38 -> V_40 , F_53 ) ;
else
F_63 ( & V_38 -> V_92 , V_92 ) ;
}
static void F_64 ( struct V_91 * V_92 )
{
struct V_95 V_96 ;
F_65 ( & V_96 ) ;
while ( ! F_66 ( V_92 ) ) {
struct V_37 * V_38 =
F_67 ( V_92 -> V_97 , struct V_37 , V_92 ) ;
F_41 ( & V_38 -> V_92 ) ;
F_52 ( V_38 , V_85 , V_38 -> V_40 , F_53 ) ;
F_68 () ;
}
F_69 ( & V_96 ) ;
}
static void F_70 ( struct V_37 * V_38 )
{
F_2 ( V_38 -> V_98 ) ;
if ( ! V_38 -> V_90 )
return;
F_71 ( & V_38 -> V_90 , V_99 , V_94 ) ;
F_61 ( V_38 , NULL ) ;
F_71 ( & V_38 -> V_90 , V_89 , V_94 ) ;
}
static struct V_37 * F_72 ( struct V_1 * V_2 )
{
struct V_37 * V_38 ;
F_73 (b, &c->lru[LIST_CLEAN], lru_list) {
F_2 ( F_56 ( V_89 , & V_38 -> V_90 ) ) ;
F_2 ( F_56 ( V_93 , & V_38 -> V_90 ) ) ;
if ( ! V_38 -> V_98 ) {
F_70 ( V_38 ) ;
F_39 ( V_38 ) ;
return V_38 ;
}
F_68 () ;
}
F_73 (b, &c->lru[LIST_DIRTY], lru_list) {
F_2 ( F_56 ( V_99 , & V_38 -> V_90 ) ) ;
if ( ! V_38 -> V_98 ) {
F_70 ( V_38 ) ;
F_39 ( V_38 ) ;
return V_38 ;
}
F_68 () ;
}
return NULL ;
}
static void F_74 ( struct V_1 * V_2 )
{
F_75 ( V_100 , V_101 ) ;
F_76 ( & V_2 -> V_102 , & V_100 ) ;
F_77 ( V_101 , V_94 ) ;
F_9 ( V_2 ) ;
F_78 () ;
F_79 ( & V_2 -> V_102 , & V_100 ) ;
F_4 ( V_2 ) ;
}
static struct V_37 * F_80 ( struct V_1 * V_2 , enum V_103 V_104 )
{
struct V_37 * V_38 ;
while ( 1 ) {
if ( V_19 != 1 ) {
V_38 = F_31 ( V_2 , V_105 | V_30 | V_106 | V_107 ) ;
if ( V_38 )
return V_38 ;
}
if ( V_104 == V_108 )
return NULL ;
if ( ! F_66 ( & V_2 -> V_109 ) ) {
V_38 = F_67 ( V_2 -> V_109 . V_97 ,
struct V_37 , V_44 ) ;
F_41 ( & V_38 -> V_44 ) ;
V_2 -> V_110 ++ ;
return V_38 ;
}
V_38 = F_72 ( V_2 ) ;
if ( V_38 )
return V_38 ;
F_74 ( V_2 ) ;
}
}
static struct V_37 * F_81 ( struct V_1 * V_2 , enum V_103 V_104 )
{
struct V_37 * V_38 = F_80 ( V_2 , V_104 ) ;
if ( ! V_38 )
return NULL ;
if ( V_2 -> V_111 )
V_2 -> V_111 ( V_38 ) ;
return V_38 ;
}
static void F_82 ( struct V_37 * V_38 )
{
struct V_1 * V_2 = V_38 -> V_2 ;
if ( ! V_2 -> V_110 )
F_34 ( V_38 ) ;
else {
F_36 ( & V_38 -> V_44 , & V_2 -> V_109 ) ;
V_2 -> V_110 -- ;
}
F_83 ( & V_2 -> V_102 ) ;
}
static void F_84 ( struct V_1 * V_2 , int V_112 ,
struct V_91 * V_92 )
{
struct V_37 * V_38 , * V_113 ;
F_85 (b, tmp, &c->lru[LIST_DIRTY], lru_list) {
F_2 ( F_56 ( V_99 , & V_38 -> V_90 ) ) ;
if ( ! F_56 ( V_93 , & V_38 -> V_90 ) &&
! F_56 ( V_89 , & V_38 -> V_90 ) ) {
F_42 ( V_38 , V_114 ) ;
continue;
}
if ( V_112 && F_56 ( V_89 , & V_38 -> V_90 ) )
return;
F_61 ( V_38 , V_92 ) ;
F_68 () ;
}
}
static void F_86 ( struct V_1 * V_2 ,
unsigned long * V_115 ,
unsigned long * V_116 )
{
unsigned long V_117 ;
if ( F_16 ( V_20 ) != V_19 ) {
F_87 ( & V_17 ) ;
F_14 () ;
F_10 ( & V_17 ) ;
}
V_117 = V_22 >>
( V_2 -> V_68 + V_70 ) ;
if ( V_117 < V_2 -> V_118 )
V_117 = V_2 -> V_118 ;
* V_116 = V_117 ;
* V_115 = V_117 * V_119 / 100 ;
}
static void F_88 ( struct V_1 * V_2 ,
struct V_91 * V_92 )
{
unsigned long V_115 , V_116 ;
F_86 ( V_2 , & V_115 , & V_116 ) ;
while ( V_2 -> V_42 [ V_114 ] + V_2 -> V_42 [ V_120 ] >
V_116 ) {
struct V_37 * V_38 = F_72 ( V_2 ) ;
if ( ! V_38 )
return;
F_82 ( V_38 ) ;
F_68 () ;
}
if ( V_2 -> V_42 [ V_120 ] > V_115 )
F_84 ( V_2 , 1 , V_92 ) ;
}
static struct V_37 * F_89 ( struct V_1 * V_2 , T_2 V_40 )
{
struct V_37 * V_38 ;
F_90 (b, &c->cache_hash[DM_BUFIO_HASH(block)],
hash_list) {
F_68 () ;
if ( V_38 -> V_40 == V_40 )
return V_38 ;
}
return NULL ;
}
static struct V_37 * F_91 ( struct V_1 * V_2 , T_2 V_40 ,
enum V_103 V_104 , int * V_121 ,
struct V_91 * V_92 )
{
struct V_37 * V_38 , * V_122 = NULL ;
* V_121 = 0 ;
V_38 = F_89 ( V_2 , V_40 ) ;
if ( V_38 )
goto V_123;
if ( V_104 == V_124 )
return NULL ;
V_122 = F_81 ( V_2 , V_104 ) ;
if ( ! V_122 )
return NULL ;
V_38 = F_89 ( V_2 , V_40 ) ;
if ( V_38 ) {
F_82 ( V_122 ) ;
goto V_123;
}
F_88 ( V_2 , V_92 ) ;
V_38 = V_122 ;
V_38 -> V_98 = 1 ;
V_38 -> V_125 = 0 ;
V_38 -> V_87 = 0 ;
F_35 ( V_38 , V_40 , V_114 ) ;
if ( V_104 == V_126 ) {
V_38 -> V_90 = 0 ;
return V_38 ;
}
V_38 -> V_90 = 1 << V_99 ;
* V_121 = 1 ;
return V_38 ;
V_123:
if ( V_104 == V_108 )
return NULL ;
if ( V_104 == V_124 && F_55 ( F_56 ( V_99 , & V_38 -> V_90 ) ) )
return NULL ;
V_38 -> V_98 ++ ;
F_42 ( V_38 , F_56 ( V_93 , & V_38 -> V_90 ) ||
F_56 ( V_89 , & V_38 -> V_90 ) ) ;
return V_38 ;
}
static void F_92 ( struct V_51 * V_51 , int error )
{
struct V_37 * V_38 = F_54 ( V_51 , struct V_37 , V_51 ) ;
V_38 -> V_125 = error ;
F_2 ( ! F_56 ( V_99 , & V_38 -> V_90 ) ) ;
F_57 () ;
F_58 ( V_99 , & V_38 -> V_90 ) ;
F_59 () ;
F_60 ( & V_38 -> V_90 , V_99 ) ;
}
static void * F_93 ( struct V_1 * V_2 , T_2 V_40 ,
enum V_103 V_104 , struct V_37 * * V_127 )
{
int V_121 ;
struct V_37 * V_38 ;
F_94 ( V_92 ) ;
F_4 ( V_2 ) ;
V_38 = F_91 ( V_2 , V_40 , V_104 , & V_121 , & V_92 ) ;
F_9 ( V_2 ) ;
F_64 ( & V_92 ) ;
if ( ! V_38 )
return V_38 ;
if ( V_121 )
F_52 ( V_38 , V_128 , V_38 -> V_40 , F_92 ) ;
F_71 ( & V_38 -> V_90 , V_99 , V_94 ) ;
if ( V_38 -> V_125 ) {
int error = V_38 -> V_125 ;
F_95 ( V_38 ) ;
return F_96 ( error ) ;
}
* V_127 = V_38 ;
return V_38 -> V_36 ;
}
void * F_97 ( struct V_1 * V_2 , T_2 V_40 ,
struct V_37 * * V_127 )
{
return F_93 ( V_2 , V_40 , V_124 , V_127 ) ;
}
void * F_98 ( struct V_1 * V_2 , T_2 V_40 ,
struct V_37 * * V_127 )
{
F_2 ( F_6 () ) ;
return F_93 ( V_2 , V_40 , V_129 , V_127 ) ;
}
void * F_99 ( struct V_1 * V_2 , T_2 V_40 ,
struct V_37 * * V_127 )
{
F_2 ( F_6 () ) ;
return F_93 ( V_2 , V_40 , V_126 , V_127 ) ;
}
void F_100 ( struct V_1 * V_2 ,
T_2 V_40 , unsigned V_130 )
{
struct V_95 V_96 ;
F_94 ( V_92 ) ;
F_2 ( F_6 () ) ;
F_65 ( & V_96 ) ;
F_4 ( V_2 ) ;
for (; V_130 -- ; V_40 ++ ) {
int V_121 ;
struct V_37 * V_38 ;
V_38 = F_91 ( V_2 , V_40 , V_108 , & V_121 ,
& V_92 ) ;
if ( F_55 ( ! F_66 ( & V_92 ) ) ) {
F_9 ( V_2 ) ;
F_69 ( & V_96 ) ;
F_64 ( & V_92 ) ;
F_65 ( & V_96 ) ;
F_4 ( V_2 ) ;
}
if ( F_55 ( V_38 != NULL ) ) {
F_9 ( V_2 ) ;
if ( V_121 )
F_52 ( V_38 , V_128 , V_38 -> V_40 , F_92 ) ;
F_95 ( V_38 ) ;
F_68 () ;
if ( ! V_130 )
goto V_131;
F_4 ( V_2 ) ;
}
}
F_9 ( V_2 ) ;
V_131:
F_69 ( & V_96 ) ;
}
void F_95 ( struct V_37 * V_38 )
{
struct V_1 * V_2 = V_38 -> V_2 ;
F_4 ( V_2 ) ;
F_2 ( ! V_38 -> V_98 ) ;
V_38 -> V_98 -- ;
if ( ! V_38 -> V_98 ) {
F_83 ( & V_2 -> V_102 ) ;
if ( ( V_38 -> V_125 || V_38 -> V_87 ) &&
! F_56 ( V_99 , & V_38 -> V_90 ) &&
! F_56 ( V_89 , & V_38 -> V_90 ) &&
! F_56 ( V_93 , & V_38 -> V_90 ) ) {
F_39 ( V_38 ) ;
F_82 ( V_38 ) ;
}
}
F_9 ( V_2 ) ;
}
void F_101 ( struct V_37 * V_38 )
{
struct V_1 * V_2 = V_38 -> V_2 ;
F_4 ( V_2 ) ;
F_2 ( F_56 ( V_99 , & V_38 -> V_90 ) ) ;
if ( ! F_102 ( V_93 , & V_38 -> V_90 ) )
F_42 ( V_38 , V_120 ) ;
F_9 ( V_2 ) ;
}
void F_103 ( struct V_1 * V_2 )
{
F_94 ( V_92 ) ;
F_2 ( F_6 () ) ;
F_4 ( V_2 ) ;
F_84 ( V_2 , 0 , & V_92 ) ;
F_9 ( V_2 ) ;
F_64 ( & V_92 ) ;
}
int F_104 ( struct V_1 * V_2 )
{
int V_132 , V_133 ;
unsigned long V_134 = 0 ;
struct V_37 * V_38 , * V_113 ;
F_94 ( V_92 ) ;
F_4 ( V_2 ) ;
F_84 ( V_2 , 0 , & V_92 ) ;
F_9 ( V_2 ) ;
F_64 ( & V_92 ) ;
F_4 ( V_2 ) ;
V_135:
F_85 (b, tmp, &c->lru[LIST_DIRTY], lru_list) {
int V_136 = 0 ;
if ( V_134 < V_2 -> V_42 [ V_120 ] )
V_134 ++ ;
F_2 ( F_56 ( V_99 , & V_38 -> V_90 ) ) ;
if ( F_56 ( V_89 , & V_38 -> V_90 ) ) {
if ( V_134 < V_2 -> V_42 [ V_120 ] ) {
V_136 = 1 ;
V_38 -> V_98 ++ ;
F_9 ( V_2 ) ;
F_71 ( & V_38 -> V_90 , V_89 ,
V_94 ) ;
F_4 ( V_2 ) ;
V_38 -> V_98 -- ;
} else
F_71 ( & V_38 -> V_90 , V_89 ,
V_94 ) ;
}
if ( ! F_56 ( V_93 , & V_38 -> V_90 ) &&
! F_56 ( V_89 , & V_38 -> V_90 ) )
F_42 ( V_38 , V_114 ) ;
F_68 () ;
if ( V_136 )
goto V_135;
}
F_83 ( & V_2 -> V_102 ) ;
F_9 ( V_2 ) ;
V_132 = F_105 ( & V_2 -> V_88 , 0 ) ;
V_133 = F_106 ( V_2 ) ;
if ( V_132 )
return V_132 ;
return V_133 ;
}
int F_106 ( struct V_1 * V_2 )
{
struct V_57 V_58 = {
. V_59 = V_137 ,
. V_71 . type = V_72 ,
. V_71 . V_25 . V_73 = NULL ,
. V_62 = V_2 -> V_63 ,
} ;
struct V_64 V_138 = {
. V_66 = V_2 -> V_66 ,
. V_67 = 0 ,
. V_69 = 0 ,
} ;
F_2 ( F_6 () ) ;
return V_63 ( & V_58 , 1 , & V_138 , NULL ) ;
}
void F_107 ( struct V_37 * V_38 , T_2 V_139 )
{
struct V_1 * V_2 = V_38 -> V_2 ;
struct V_37 * V_140 ;
F_2 ( F_6 () ) ;
F_4 ( V_2 ) ;
V_141:
V_140 = F_89 ( V_2 , V_139 ) ;
if ( V_140 ) {
if ( V_140 -> V_98 ) {
F_74 ( V_2 ) ;
goto V_141;
}
F_70 ( V_140 ) ;
F_39 ( V_140 ) ;
F_82 ( V_140 ) ;
}
F_2 ( ! V_38 -> V_98 ) ;
F_2 ( F_56 ( V_99 , & V_38 -> V_90 ) ) ;
F_61 ( V_38 , NULL ) ;
if ( V_38 -> V_98 == 1 ) {
F_71 ( & V_38 -> V_90 , V_89 ,
V_94 ) ;
F_108 ( V_93 , & V_38 -> V_90 ) ;
F_39 ( V_38 ) ;
F_35 ( V_38 , V_139 , V_120 ) ;
} else {
T_2 V_142 ;
F_62 ( & V_38 -> V_90 , V_89 ,
V_94 ) ;
V_142 = V_38 -> V_40 ;
F_39 ( V_38 ) ;
F_35 ( V_38 , V_139 , V_38 -> V_43 ) ;
F_52 ( V_38 , V_85 , V_139 , F_53 ) ;
F_71 ( & V_38 -> V_90 , V_89 ,
V_94 ) ;
F_39 ( V_38 ) ;
F_35 ( V_38 , V_142 , V_38 -> V_43 ) ;
}
F_9 ( V_2 ) ;
F_95 ( V_38 ) ;
}
void F_109 ( struct V_1 * V_2 , T_2 V_40 )
{
struct V_37 * V_38 ;
F_4 ( V_2 ) ;
V_38 = F_89 ( V_2 , V_40 ) ;
if ( V_38 && F_110 ( ! V_38 -> V_98 ) && F_110 ( ! V_38 -> V_90 ) ) {
F_39 ( V_38 ) ;
F_82 ( V_38 ) ;
}
F_9 ( V_2 ) ;
}
void F_111 ( struct V_1 * V_2 , unsigned V_143 )
{
V_2 -> V_118 = V_143 ;
}
unsigned F_112 ( struct V_1 * V_2 )
{
return V_2 -> V_26 ;
}
T_2 F_113 ( struct V_1 * V_2 )
{
return F_114 ( V_2 -> V_66 -> V_144 ) >>
( V_70 + V_2 -> V_68 ) ;
}
T_2 F_115 ( struct V_37 * V_38 )
{
return V_38 -> V_40 ;
}
void * F_116 ( struct V_37 * V_38 )
{
return V_38 -> V_36 ;
}
void * F_117 ( struct V_37 * V_38 )
{
return V_38 + 1 ;
}
struct V_1 * F_118 ( struct V_37 * V_38 )
{
return V_38 -> V_2 ;
}
static void F_119 ( struct V_1 * V_2 )
{
struct V_37 * V_38 ;
int V_145 ;
F_2 ( F_6 () ) ;
F_103 ( V_2 ) ;
F_4 ( V_2 ) ;
while ( ( V_38 = F_72 ( V_2 ) ) )
F_82 ( V_38 ) ;
for ( V_145 = 0 ; V_145 < V_146 ; V_145 ++ )
F_120 (b, &c->lru[i], lru_list)
F_121 ( L_2 ,
( unsigned long long ) V_38 -> V_40 , V_38 -> V_98 , V_145 ) ;
for ( V_145 = 0 ; V_145 < V_146 ; V_145 ++ )
F_2 ( ! F_66 ( & V_2 -> V_45 [ V_145 ] ) ) ;
F_9 ( V_2 ) ;
}
static int F_122 ( struct V_37 * V_38 , T_1 V_147 ,
unsigned long V_148 )
{
if ( V_49 - V_38 -> V_48 < V_148 )
return 0 ;
if ( ! ( V_147 & V_149 ) ) {
if ( F_56 ( V_99 , & V_38 -> V_90 ) ||
F_56 ( V_89 , & V_38 -> V_90 ) ||
F_56 ( V_93 , & V_38 -> V_90 ) )
return 0 ;
}
if ( V_38 -> V_98 )
return 0 ;
F_70 ( V_38 ) ;
F_39 ( V_38 ) ;
F_82 ( V_38 ) ;
return 1 ;
}
static long F_123 ( struct V_1 * V_2 , unsigned long V_150 ,
T_1 V_23 )
{
int V_151 ;
struct V_37 * V_38 , * V_113 ;
long V_152 = 0 ;
for ( V_151 = 0 ; V_151 < V_146 ; V_151 ++ ) {
F_85 (b, tmp, &c->lru[l], lru_list) {
V_152 += F_122 ( V_38 , V_23 , 0 ) ;
if ( ! -- V_150 )
return V_152 ;
F_68 () ;
}
}
return V_152 ;
}
static unsigned long
F_124 ( struct V_153 * V_154 , struct V_155 * V_156 )
{
struct V_1 * V_2 ;
unsigned long V_152 ;
V_2 = F_54 ( V_154 , struct V_1 , V_153 ) ;
if ( V_156 -> V_23 & V_149 )
F_4 ( V_2 ) ;
else if ( ! F_7 ( V_2 ) )
return V_157 ;
V_152 = F_123 ( V_2 , V_156 -> V_150 , V_156 -> V_23 ) ;
F_9 ( V_2 ) ;
return V_152 ;
}
static unsigned long
F_125 ( struct V_153 * V_154 , struct V_155 * V_156 )
{
struct V_1 * V_2 ;
unsigned long V_69 ;
V_2 = F_54 ( V_154 , struct V_1 , V_153 ) ;
if ( V_156 -> V_23 & V_149 )
F_4 ( V_2 ) ;
else if ( ! F_7 ( V_2 ) )
return 0 ;
V_69 = V_2 -> V_42 [ V_114 ] + V_2 -> V_42 [ V_120 ] ;
F_9 ( V_2 ) ;
return V_69 ;
}
struct V_1 * F_126 ( struct V_158 * V_66 , unsigned V_26 ,
unsigned V_109 , unsigned V_39 ,
void (* V_111)( struct V_37 * ) ,
void (* V_86)( struct V_37 * ) )
{
int V_56 ;
struct V_1 * V_2 ;
unsigned V_145 ;
F_2 ( V_26 < 1 << V_70 ||
( V_26 & ( V_26 - 1 ) ) ) ;
V_2 = F_127 ( sizeof( * V_2 ) , V_159 ) ;
if ( ! V_2 ) {
V_56 = - V_160 ;
goto V_161;
}
V_2 -> V_47 = F_128 ( sizeof( struct V_162 ) << V_163 ) ;
if ( ! V_2 -> V_47 ) {
V_56 = - V_160 ;
goto V_164;
}
V_2 -> V_66 = V_66 ;
V_2 -> V_26 = V_26 ;
V_2 -> V_68 = F_129 ( V_26 ) - 1 - V_70 ;
V_2 -> V_32 = ( F_129 ( V_26 ) - 1 >= V_165 ) ?
F_129 ( V_26 ) - 1 - V_165 : 0 ;
V_2 -> V_4 = ( F_129 ( V_26 ) - 1 < V_165 ?
V_165 - ( F_129 ( V_26 ) - 1 ) : 0 ) ;
V_2 -> V_39 = V_39 ;
V_2 -> V_111 = V_111 ;
V_2 -> V_86 = V_86 ;
for ( V_145 = 0 ; V_145 < V_146 ; V_145 ++ ) {
F_130 ( & V_2 -> V_45 [ V_145 ] ) ;
V_2 -> V_42 [ V_145 ] = 0 ;
}
for ( V_145 = 0 ; V_145 < 1 << V_163 ; V_145 ++ )
F_131 ( & V_2 -> V_47 [ V_145 ] ) ;
F_132 ( & V_2 -> V_6 ) ;
F_130 ( & V_2 -> V_109 ) ;
V_2 -> V_110 = V_109 ;
V_2 -> V_118 = V_166 ;
F_133 ( & V_2 -> V_102 ) ;
V_2 -> V_88 = 0 ;
V_2 -> V_63 = F_134 () ;
if ( F_135 ( V_2 -> V_63 ) ) {
V_56 = F_136 ( V_2 -> V_63 ) ;
goto V_167;
}
F_87 ( & V_17 ) ;
if ( V_2 -> V_4 ) {
if ( ! F_137 ( V_2 ) ) {
F_137 ( V_2 ) = F_138 ( V_159 , L_3 , V_2 -> V_26 ) ;
if ( ! F_137 ( V_2 ) ) {
V_56 = - V_160 ;
F_10 ( & V_17 ) ;
goto V_168;
}
}
if ( ! F_20 ( V_2 ) ) {
F_20 ( V_2 ) = F_139 ( F_137 ( V_2 ) ,
V_2 -> V_26 ,
V_2 -> V_26 , 0 , NULL ) ;
if ( ! F_20 ( V_2 ) ) {
V_56 = - V_160 ;
F_10 ( & V_17 ) ;
goto V_168;
}
}
}
F_10 ( & V_17 ) ;
while ( V_2 -> V_110 ) {
struct V_37 * V_38 = F_31 ( V_2 , V_159 ) ;
if ( ! V_38 ) {
V_56 = - V_160 ;
goto V_169;
}
F_82 ( V_38 ) ;
}
F_87 ( & V_17 ) ;
V_18 ++ ;
F_36 ( & V_2 -> V_170 , & V_171 ) ;
F_14 () ;
F_10 ( & V_17 ) ;
V_2 -> V_153 . V_172 = F_125 ;
V_2 -> V_153 . V_173 = F_124 ;
V_2 -> V_153 . V_174 = 1 ;
V_2 -> V_153 . V_175 = 0 ;
F_140 ( & V_2 -> V_153 ) ;
return V_2 ;
V_169:
V_168:
while ( ! F_66 ( & V_2 -> V_109 ) ) {
struct V_37 * V_38 = F_67 ( V_2 -> V_109 . V_97 ,
struct V_37 , V_44 ) ;
F_41 ( & V_38 -> V_44 ) ;
F_34 ( V_38 ) ;
}
F_141 ( V_2 -> V_63 ) ;
V_167:
F_28 ( V_2 -> V_47 ) ;
V_164:
F_33 ( V_2 ) ;
V_161:
return F_96 ( V_56 ) ;
}
void F_142 ( struct V_1 * V_2 )
{
unsigned V_145 ;
F_119 ( V_2 ) ;
F_143 ( & V_2 -> V_153 ) ;
F_87 ( & V_17 ) ;
F_41 ( & V_2 -> V_170 ) ;
V_18 -- ;
F_14 () ;
F_10 ( & V_17 ) ;
for ( V_145 = 0 ; V_145 < 1 << V_163 ; V_145 ++ )
F_2 ( ! F_144 ( & V_2 -> V_47 [ V_145 ] ) ) ;
F_2 ( V_2 -> V_110 ) ;
while ( ! F_66 ( & V_2 -> V_109 ) ) {
struct V_37 * V_38 = F_67 ( V_2 -> V_109 . V_97 ,
struct V_37 , V_44 ) ;
F_41 ( & V_38 -> V_44 ) ;
F_34 ( V_38 ) ;
}
for ( V_145 = 0 ; V_145 < V_146 ; V_145 ++ )
if ( V_2 -> V_42 [ V_145 ] )
F_121 ( L_4 , V_145 , V_2 -> V_42 [ V_145 ] ) ;
for ( V_145 = 0 ; V_145 < V_146 ; V_145 ++ )
F_2 ( V_2 -> V_42 [ V_145 ] ) ;
F_141 ( V_2 -> V_63 ) ;
F_28 ( V_2 -> V_47 ) ;
F_33 ( V_2 ) ;
}
static void F_145 ( void )
{
unsigned long V_176 = F_16 ( V_177 ) ;
struct V_1 * V_2 ;
if ( V_176 > V_178 / V_179 )
V_176 = V_178 / V_179 ;
F_87 ( & V_17 ) ;
F_120 (c, &dm_bufio_all_clients, client_list) {
if ( ! F_7 ( V_2 ) )
continue;
while ( ! F_66 ( & V_2 -> V_45 [ V_114 ] ) ) {
struct V_37 * V_38 ;
V_38 = F_67 ( V_2 -> V_45 [ V_114 ] . V_180 ,
struct V_37 , V_44 ) ;
if ( ! F_122 ( V_38 , 0 , V_176 * V_179 ) )
break;
F_68 () ;
}
F_9 ( V_2 ) ;
F_68 () ;
}
F_10 ( & V_17 ) ;
}
static void F_146 ( struct V_181 * V_182 )
{
F_145 () ;
F_147 ( V_183 , & V_184 ,
V_185 * V_179 ) ;
}
static int T_4 F_148 ( void )
{
T_5 V_71 ;
V_11 = 0 ;
V_12 = 0 ;
V_13 = 0 ;
V_15 = 0 ;
memset ( & V_5 , 0 , sizeof V_5 ) ;
memset ( & V_186 , 0 , sizeof V_186 ) ;
V_71 = ( T_5 ) ( ( V_187 - V_188 ) *
V_189 / 100 ) << V_165 ;
if ( V_71 > V_178 )
V_71 = V_178 ;
#ifdef F_149
if ( V_71 > ( V_190 - V_191 ) * V_192 / 100 )
V_71 = ( V_190 - V_191 ) * V_192 / 100 ;
#endif
V_21 = V_71 ;
F_87 ( & V_17 ) ;
F_14 () ;
F_10 ( & V_17 ) ;
V_183 = F_150 ( L_5 ) ;
if ( ! V_183 )
return - V_160 ;
F_151 ( & V_184 , F_146 ) ;
F_147 ( V_183 , & V_184 ,
V_185 * V_179 ) ;
return 0 ;
}
static void T_6 F_152 ( void )
{
int V_193 = 0 ;
int V_145 ;
F_153 ( & V_184 ) ;
F_154 ( V_183 ) ;
for ( V_145 = 0 ; V_145 < F_3 ( V_5 ) ; V_145 ++ ) {
struct V_194 * V_195 = V_5 [ V_145 ] ;
if ( V_195 )
F_155 ( V_195 ) ;
}
for ( V_145 = 0 ; V_145 < F_3 ( V_186 ) ; V_145 ++ )
F_33 ( V_186 [ V_145 ] ) ;
if ( V_18 ) {
F_29 ( L_6 ,
V_196 , V_18 ) ;
V_193 = 1 ;
}
if ( V_15 ) {
F_29 ( L_7 ,
V_196 , V_15 ) ;
V_193 = 1 ;
}
if ( V_12 ) {
F_29 ( L_8 ,
V_196 , V_12 ) ;
V_193 = 1 ;
}
if ( V_13 ) {
F_29 ( L_9 ,
V_196 , V_13 ) ;
V_193 = 1 ;
}
if ( V_193 )
F_30 () ;
}
