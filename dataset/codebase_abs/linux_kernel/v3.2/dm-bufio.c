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
V_19 = V_20 ;
F_16 () ;
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
if ( V_2 -> V_24 <= V_25 ) {
* V_7 = V_26 ;
return F_19 ( F_20 ( V_2 ) , V_23 ) ;
}
if ( V_2 -> V_24 <= V_27 &&
V_23 & V_28 ) {
* V_7 = V_29 ;
return ( void * ) F_21 ( V_23 ,
V_2 -> V_30 ) ;
}
* V_7 = V_31 ;
return F_22 ( V_2 -> V_24 , V_23 , V_32 ) ;
}
static void F_23 ( struct V_1 * V_2 ,
void * V_33 , enum V_7 V_7 )
{
switch ( V_7 ) {
case V_26 :
F_24 ( F_20 ( V_2 ) , V_33 ) ;
break;
case V_29 :
F_25 ( ( unsigned long ) V_33 , V_2 -> V_30 ) ;
break;
case V_31 :
F_26 ( V_33 ) ;
break;
default:
F_27 ( L_1 ,
V_7 ) ;
F_28 () ;
}
}
static struct V_34 * F_29 ( struct V_1 * V_2 , T_1 V_23 )
{
struct V_34 * V_35 = F_30 ( sizeof( struct V_34 ) + V_2 -> V_36 ,
V_23 ) ;
if ( ! V_35 )
return NULL ;
V_35 -> V_2 = V_2 ;
V_35 -> V_33 = F_18 ( V_2 , V_23 , & V_35 -> V_7 ) ;
if ( ! V_35 -> V_33 ) {
F_31 ( V_35 ) ;
return NULL ;
}
F_11 ( V_35 -> V_7 , ( long ) V_2 -> V_24 ) ;
return V_35 ;
}
static void F_32 ( struct V_34 * V_35 )
{
struct V_1 * V_2 = V_35 -> V_2 ;
F_11 ( V_35 -> V_7 , - ( long ) V_2 -> V_24 ) ;
F_23 ( V_2 , V_35 -> V_33 , V_35 -> V_7 ) ;
F_31 ( V_35 ) ;
}
static void F_33 ( struct V_34 * V_35 , T_2 V_37 , int V_38 )
{
struct V_1 * V_2 = V_35 -> V_2 ;
V_2 -> V_39 [ V_38 ] ++ ;
V_35 -> V_37 = V_37 ;
V_35 -> V_40 = V_38 ;
F_34 ( & V_35 -> V_41 , & V_2 -> V_42 [ V_38 ] ) ;
F_35 ( & V_35 -> V_43 , & V_2 -> V_44 [ F_36 ( V_37 ) ] ) ;
V_35 -> V_45 = V_46 ;
}
static void F_37 ( struct V_34 * V_35 )
{
struct V_1 * V_2 = V_35 -> V_2 ;
F_2 ( ! V_2 -> V_39 [ V_35 -> V_40 ] ) ;
V_2 -> V_39 [ V_35 -> V_40 ] -- ;
F_38 ( & V_35 -> V_43 ) ;
F_39 ( & V_35 -> V_41 ) ;
}
static void F_40 ( struct V_34 * V_35 , int V_38 )
{
struct V_1 * V_2 = V_35 -> V_2 ;
F_2 ( ! V_2 -> V_39 [ V_35 -> V_40 ] ) ;
V_2 -> V_39 [ V_35 -> V_40 ] -- ;
V_2 -> V_39 [ V_38 ] ++ ;
V_35 -> V_40 = V_38 ;
F_39 ( & V_35 -> V_41 ) ;
F_34 ( & V_35 -> V_41 , & V_2 -> V_42 [ V_38 ] ) ;
}
static void F_41 ( unsigned long error , void * V_47 )
{
struct V_34 * V_35 = V_47 ;
V_35 -> V_48 . V_49 ( & V_35 -> V_48 , error ? - V_50 : 0 ) ;
}
static void F_42 ( struct V_34 * V_35 , int V_51 , T_2 V_37 ,
T_3 * V_52 )
{
int V_53 ;
struct V_54 V_55 = {
. V_56 = V_51 ,
. V_57 . V_58 = F_41 ,
. V_57 . V_47 = V_35 ,
. V_59 = V_35 -> V_2 -> V_60 ,
} ;
struct V_61 V_62 = {
. V_63 = V_35 -> V_2 -> V_63 ,
. V_64 = V_37 << V_35 -> V_2 -> V_65 ,
. V_66 = V_35 -> V_2 -> V_24 >> V_67 ,
} ;
if ( V_35 -> V_7 != V_31 ) {
V_55 . V_68 . type = V_69 ;
V_55 . V_68 . V_70 . V_71 = V_35 -> V_33 ;
} else {
V_55 . V_68 . type = V_72 ;
V_55 . V_68 . V_70 . V_73 = V_35 -> V_33 ;
}
V_35 -> V_48 . V_49 = V_52 ;
V_53 = V_60 ( & V_55 , 1 , & V_62 , NULL ) ;
if ( V_53 )
V_52 ( & V_35 -> V_48 , V_53 ) ;
}
static void F_43 ( struct V_34 * V_35 , int V_51 , T_2 V_37 ,
T_3 * V_52 )
{
char * V_70 ;
int V_74 ;
F_44 ( & V_35 -> V_48 ) ;
V_35 -> V_48 . V_75 = V_35 -> V_76 ;
V_35 -> V_48 . V_77 = V_78 ;
V_35 -> V_48 . V_79 = V_37 << V_35 -> V_2 -> V_65 ;
V_35 -> V_48 . V_80 = V_35 -> V_2 -> V_63 ;
V_35 -> V_48 . V_49 = V_52 ;
V_70 = V_35 -> V_33 ;
V_74 = V_35 -> V_2 -> V_24 ;
if ( V_74 >= V_81 )
F_2 ( ( unsigned long ) V_70 & ( V_81 - 1 ) ) ;
else
F_2 ( ( unsigned long ) V_70 & ( V_74 - 1 ) ) ;
do {
if ( ! F_45 ( & V_35 -> V_48 , F_46 ( V_70 ) ,
V_74 < V_81 ? V_74 : V_81 ,
F_47 ( V_70 ) & ( V_81 - 1 ) ) ) {
F_2 ( V_35 -> V_2 -> V_24 <= V_81 ) ;
F_42 ( V_35 , V_51 , V_37 , V_52 ) ;
return;
}
V_74 -= V_81 ;
V_70 += V_81 ;
} while ( V_74 > 0 );
F_48 ( V_51 , & V_35 -> V_48 ) ;
}
static void F_49 ( struct V_34 * V_35 , int V_51 , T_2 V_37 ,
T_3 * V_52 )
{
if ( V_51 == V_82 && V_35 -> V_2 -> V_83 )
V_35 -> V_2 -> V_83 ( V_35 ) ;
if ( V_35 -> V_2 -> V_24 <= V_78 * V_81 &&
V_35 -> V_7 != V_31 )
F_43 ( V_35 , V_51 , V_37 , V_52 ) ;
else
F_42 ( V_35 , V_51 , V_37 , V_52 ) ;
}
static void F_50 ( struct V_48 * V_48 , int error )
{
struct V_34 * V_35 = F_51 ( V_48 , struct V_34 , V_48 ) ;
V_35 -> V_84 = error ;
if ( error ) {
struct V_1 * V_2 = V_35 -> V_2 ;
( void ) F_17 ( & V_2 -> V_85 , 0 , error ) ;
}
F_2 ( ! F_52 ( V_86 , & V_35 -> V_87 ) ) ;
F_53 () ;
F_54 ( V_86 , & V_35 -> V_87 ) ;
F_55 () ;
F_56 ( & V_35 -> V_87 , V_86 ) ;
}
static int F_57 ( void * V_88 )
{
F_58 () ;
return 0 ;
}
static void F_59 ( struct V_34 * V_35 )
{
if ( ! F_52 ( V_89 , & V_35 -> V_87 ) )
return;
F_54 ( V_89 , & V_35 -> V_87 ) ;
F_60 ( & V_35 -> V_87 , V_86 ,
F_57 , V_90 ) ;
F_49 ( V_35 , V_82 , V_35 -> V_37 , F_50 ) ;
}
static void F_61 ( struct V_34 * V_35 )
{
F_2 ( V_35 -> V_91 ) ;
if ( ! V_35 -> V_87 )
return;
F_62 ( & V_35 -> V_87 , V_92 , F_57 , V_90 ) ;
F_59 ( V_35 ) ;
F_62 ( & V_35 -> V_87 , V_86 , F_57 , V_90 ) ;
}
static struct V_34 * F_63 ( struct V_1 * V_2 )
{
struct V_34 * V_35 ;
F_64 (b, &c->lru[LIST_CLEAN], lru_list) {
F_2 ( F_52 ( V_86 , & V_35 -> V_87 ) ) ;
F_2 ( F_52 ( V_89 , & V_35 -> V_87 ) ) ;
if ( ! V_35 -> V_91 ) {
F_61 ( V_35 ) ;
F_37 ( V_35 ) ;
return V_35 ;
}
F_65 () ;
}
F_64 (b, &c->lru[LIST_DIRTY], lru_list) {
F_2 ( F_52 ( V_92 , & V_35 -> V_87 ) ) ;
if ( ! V_35 -> V_91 ) {
F_61 ( V_35 ) ;
F_37 ( V_35 ) ;
return V_35 ;
}
F_65 () ;
}
return NULL ;
}
static void F_66 ( struct V_1 * V_2 )
{
F_67 ( V_93 , V_94 ) ;
F_68 ( & V_2 -> V_95 , & V_93 ) ;
F_69 ( V_94 , V_90 ) ;
F_9 ( V_2 ) ;
F_58 () ;
F_69 ( V_94 , V_96 ) ;
F_70 ( & V_2 -> V_95 , & V_93 ) ;
F_4 ( V_2 ) ;
}
static struct V_34 * F_71 ( struct V_1 * V_2 )
{
struct V_34 * V_35 ;
while ( 1 ) {
if ( V_19 != 1 ) {
V_35 = F_29 ( V_2 , V_97 | V_28 | V_98 | V_99 ) ;
if ( V_35 )
return V_35 ;
}
if ( ! F_72 ( & V_2 -> V_100 ) ) {
V_35 = F_73 ( V_2 -> V_100 . V_101 ,
struct V_34 , V_41 ) ;
F_39 ( & V_35 -> V_41 ) ;
V_2 -> V_102 ++ ;
return V_35 ;
}
V_35 = F_63 ( V_2 ) ;
if ( V_35 )
return V_35 ;
F_66 ( V_2 ) ;
}
}
static struct V_34 * F_74 ( struct V_1 * V_2 )
{
struct V_34 * V_35 = F_71 ( V_2 ) ;
if ( V_2 -> V_103 )
V_2 -> V_103 ( V_35 ) ;
return V_35 ;
}
static void F_75 ( struct V_34 * V_35 )
{
struct V_1 * V_2 = V_35 -> V_2 ;
if ( ! V_2 -> V_102 )
F_32 ( V_35 ) ;
else {
F_34 ( & V_35 -> V_41 , & V_2 -> V_100 ) ;
V_2 -> V_102 -- ;
}
F_76 ( & V_2 -> V_95 ) ;
}
static void F_77 ( struct V_1 * V_2 , int V_104 )
{
struct V_34 * V_35 , * V_105 ;
F_78 (b, tmp, &c->lru[LIST_DIRTY], lru_list) {
F_2 ( F_52 ( V_92 , & V_35 -> V_87 ) ) ;
if ( ! F_52 ( V_89 , & V_35 -> V_87 ) &&
! F_52 ( V_86 , & V_35 -> V_87 ) ) {
F_40 ( V_35 , V_106 ) ;
continue;
}
if ( V_104 && F_52 ( V_86 , & V_35 -> V_87 ) )
return;
F_59 ( V_35 ) ;
F_65 () ;
}
}
static void F_79 ( struct V_1 * V_2 ,
unsigned long * V_107 ,
unsigned long * V_108 )
{
unsigned long V_109 ;
if ( V_20 != V_19 ) {
F_80 ( & V_17 ) ;
F_14 () ;
F_10 ( & V_17 ) ;
}
V_109 = V_22 >>
( V_2 -> V_65 + V_67 ) ;
if ( V_109 < V_110 )
V_109 = V_110 ;
* V_108 = V_109 ;
* V_107 = V_109 * V_111 / 100 ;
}
static void F_81 ( struct V_1 * V_2 )
{
unsigned long V_107 , V_108 ;
F_79 ( V_2 , & V_107 , & V_108 ) ;
while ( V_2 -> V_39 [ V_106 ] + V_2 -> V_39 [ V_112 ] >
V_108 ) {
struct V_34 * V_35 = F_63 ( V_2 ) ;
if ( ! V_35 )
return;
F_75 ( V_35 ) ;
F_65 () ;
}
if ( V_2 -> V_39 [ V_112 ] > V_107 )
F_77 ( V_2 , 1 ) ;
}
static struct V_34 * F_82 ( struct V_1 * V_2 , T_2 V_37 )
{
struct V_34 * V_35 ;
struct V_113 * V_114 ;
F_83 (b, hn, &c->cache_hash[DM_BUFIO_HASH(block)],
hash_list) {
F_65 () ;
if ( V_35 -> V_37 == V_37 )
return V_35 ;
}
return NULL ;
}
static struct V_34 * F_84 ( struct V_1 * V_2 , T_2 V_37 ,
enum V_115 V_116 , struct V_34 * * V_117 ,
int * V_118 )
{
struct V_34 * V_35 , * V_119 = NULL ;
* V_118 = 0 ;
V_35 = F_82 ( V_2 , V_37 ) ;
if ( V_35 ) {
V_35 -> V_91 ++ ;
F_40 ( V_35 , F_52 ( V_89 , & V_35 -> V_87 ) ||
F_52 ( V_86 , & V_35 -> V_87 ) ) ;
return V_35 ;
}
if ( V_116 == V_120 )
return NULL ;
V_119 = F_74 ( V_2 ) ;
V_35 = F_82 ( V_2 , V_37 ) ;
if ( V_35 ) {
F_75 ( V_119 ) ;
V_35 -> V_91 ++ ;
F_40 ( V_35 , F_52 ( V_89 , & V_35 -> V_87 ) ||
F_52 ( V_86 , & V_35 -> V_87 ) ) ;
return V_35 ;
}
F_81 ( V_2 ) ;
V_35 = V_119 ;
V_35 -> V_91 = 1 ;
V_35 -> V_121 = 0 ;
V_35 -> V_84 = 0 ;
F_33 ( V_35 , V_37 , V_106 ) ;
if ( V_116 == V_122 ) {
V_35 -> V_87 = 0 ;
return V_35 ;
}
V_35 -> V_87 = 1 << V_92 ;
* V_118 = 1 ;
return V_35 ;
}
static void F_85 ( struct V_48 * V_48 , int error )
{
struct V_34 * V_35 = F_51 ( V_48 , struct V_34 , V_48 ) ;
V_35 -> V_121 = error ;
F_2 ( ! F_52 ( V_92 , & V_35 -> V_87 ) ) ;
F_53 () ;
F_54 ( V_92 , & V_35 -> V_87 ) ;
F_55 () ;
F_56 ( & V_35 -> V_87 , V_92 ) ;
}
static void * F_86 ( struct V_1 * V_2 , T_2 V_37 ,
enum V_115 V_116 , struct V_34 * * V_117 )
{
int V_118 ;
struct V_34 * V_35 ;
F_4 ( V_2 ) ;
V_35 = F_84 ( V_2 , V_37 , V_116 , V_117 , & V_118 ) ;
F_9 ( V_2 ) ;
if ( ! V_35 || F_87 ( V_35 ) )
return V_35 ;
if ( V_118 )
F_49 ( V_35 , V_123 , V_35 -> V_37 , F_85 ) ;
F_62 ( & V_35 -> V_87 , V_92 , F_57 , V_90 ) ;
if ( V_35 -> V_121 ) {
int error = V_35 -> V_121 ;
F_88 ( V_35 ) ;
return F_89 ( error ) ;
}
* V_117 = V_35 ;
return V_35 -> V_33 ;
}
void * F_90 ( struct V_1 * V_2 , T_2 V_37 ,
struct V_34 * * V_117 )
{
return F_86 ( V_2 , V_37 , V_120 , V_117 ) ;
}
void * F_91 ( struct V_1 * V_2 , T_2 V_37 ,
struct V_34 * * V_117 )
{
F_2 ( F_6 () ) ;
return F_86 ( V_2 , V_37 , V_124 , V_117 ) ;
}
void * F_92 ( struct V_1 * V_2 , T_2 V_37 ,
struct V_34 * * V_117 )
{
F_2 ( F_6 () ) ;
return F_86 ( V_2 , V_37 , V_122 , V_117 ) ;
}
void F_88 ( struct V_34 * V_35 )
{
struct V_1 * V_2 = V_35 -> V_2 ;
F_4 ( V_2 ) ;
F_2 ( F_52 ( V_92 , & V_35 -> V_87 ) ) ;
F_2 ( ! V_35 -> V_91 ) ;
V_35 -> V_91 -- ;
if ( ! V_35 -> V_91 ) {
F_76 ( & V_2 -> V_95 ) ;
if ( ( V_35 -> V_121 || V_35 -> V_84 ) &&
! F_52 ( V_86 , & V_35 -> V_87 ) &&
! F_52 ( V_89 , & V_35 -> V_87 ) ) {
F_37 ( V_35 ) ;
F_75 ( V_35 ) ;
}
}
F_9 ( V_2 ) ;
}
void F_93 ( struct V_34 * V_35 )
{
struct V_1 * V_2 = V_35 -> V_2 ;
F_4 ( V_2 ) ;
if ( ! F_94 ( V_89 , & V_35 -> V_87 ) )
F_40 ( V_35 , V_112 ) ;
F_9 ( V_2 ) ;
}
void F_95 ( struct V_1 * V_2 )
{
F_2 ( F_6 () ) ;
F_4 ( V_2 ) ;
F_77 ( V_2 , 0 ) ;
F_9 ( V_2 ) ;
}
int F_96 ( struct V_1 * V_2 )
{
int V_125 , V_126 ;
unsigned long V_127 = 0 ;
struct V_34 * V_35 , * V_105 ;
F_4 ( V_2 ) ;
F_77 ( V_2 , 0 ) ;
V_128:
F_78 (b, tmp, &c->lru[LIST_DIRTY], lru_list) {
int V_129 = 0 ;
if ( V_127 < V_2 -> V_39 [ V_112 ] )
V_127 ++ ;
F_2 ( F_52 ( V_92 , & V_35 -> V_87 ) ) ;
if ( F_52 ( V_86 , & V_35 -> V_87 ) ) {
if ( V_127 < V_2 -> V_39 [ V_112 ] ) {
V_129 = 1 ;
V_35 -> V_91 ++ ;
F_9 ( V_2 ) ;
F_62 ( & V_35 -> V_87 , V_86 ,
F_57 ,
V_90 ) ;
F_4 ( V_2 ) ;
V_35 -> V_91 -- ;
} else
F_62 ( & V_35 -> V_87 , V_86 ,
F_57 ,
V_90 ) ;
}
if ( ! F_52 ( V_89 , & V_35 -> V_87 ) &&
! F_52 ( V_86 , & V_35 -> V_87 ) )
F_40 ( V_35 , V_106 ) ;
F_65 () ;
if ( V_129 )
goto V_128;
}
F_76 ( & V_2 -> V_95 ) ;
F_9 ( V_2 ) ;
V_125 = F_97 ( & V_2 -> V_85 , 0 ) ;
V_126 = F_98 ( V_2 ) ;
if ( V_125 )
return V_125 ;
return V_126 ;
}
int F_98 ( struct V_1 * V_2 )
{
struct V_54 V_55 = {
. V_56 = V_130 ,
. V_68 . type = V_69 ,
. V_68 . V_70 . V_71 = NULL ,
. V_59 = V_2 -> V_60 ,
} ;
struct V_61 V_131 = {
. V_63 = V_2 -> V_63 ,
. V_64 = 0 ,
. V_66 = 0 ,
} ;
F_2 ( F_6 () ) ;
return V_60 ( & V_55 , 1 , & V_131 , NULL ) ;
}
void F_99 ( struct V_34 * V_35 , T_2 V_132 )
{
struct V_1 * V_2 = V_35 -> V_2 ;
struct V_34 * V_133 ;
F_2 ( F_6 () ) ;
F_4 ( V_2 ) ;
V_134:
V_133 = F_82 ( V_2 , V_132 ) ;
if ( V_133 ) {
if ( V_133 -> V_91 ) {
F_66 ( V_2 ) ;
goto V_134;
}
F_61 ( V_133 ) ;
F_37 ( V_133 ) ;
F_75 ( V_133 ) ;
}
F_2 ( ! V_35 -> V_91 ) ;
F_2 ( F_52 ( V_92 , & V_35 -> V_87 ) ) ;
F_59 ( V_35 ) ;
if ( V_35 -> V_91 == 1 ) {
F_62 ( & V_35 -> V_87 , V_86 ,
F_57 , V_90 ) ;
F_100 ( V_89 , & V_35 -> V_87 ) ;
F_37 ( V_35 ) ;
F_33 ( V_35 , V_132 , V_112 ) ;
} else {
T_2 V_135 ;
F_60 ( & V_35 -> V_87 , V_86 ,
F_57 , V_90 ) ;
V_135 = V_35 -> V_37 ;
F_37 ( V_35 ) ;
F_33 ( V_35 , V_132 , V_35 -> V_40 ) ;
F_49 ( V_35 , V_82 , V_132 , F_50 ) ;
F_62 ( & V_35 -> V_87 , V_86 ,
F_57 , V_90 ) ;
F_37 ( V_35 ) ;
F_33 ( V_35 , V_135 , V_35 -> V_40 ) ;
}
F_9 ( V_2 ) ;
F_88 ( V_35 ) ;
}
unsigned F_101 ( struct V_1 * V_2 )
{
return V_2 -> V_24 ;
}
T_2 F_102 ( struct V_1 * V_2 )
{
return F_103 ( V_2 -> V_63 -> V_136 ) >>
( V_67 + V_2 -> V_65 ) ;
}
T_2 F_104 ( struct V_34 * V_35 )
{
return V_35 -> V_37 ;
}
void * F_105 ( struct V_34 * V_35 )
{
return V_35 -> V_33 ;
}
void * F_106 ( struct V_34 * V_35 )
{
return V_35 + 1 ;
}
struct V_1 * F_107 ( struct V_34 * V_35 )
{
return V_35 -> V_2 ;
}
static void F_108 ( struct V_1 * V_2 )
{
struct V_34 * V_35 ;
int V_137 ;
F_2 ( F_6 () ) ;
F_95 ( V_2 ) ;
F_4 ( V_2 ) ;
while ( ( V_35 = F_63 ( V_2 ) ) )
F_75 ( V_35 ) ;
for ( V_137 = 0 ; V_137 < V_138 ; V_137 ++ )
F_109 (b, &c->lru[i], lru_list)
F_110 ( L_2 ,
( unsigned long long ) V_35 -> V_37 , V_35 -> V_91 , V_137 ) ;
for ( V_137 = 0 ; V_137 < V_138 ; V_137 ++ )
F_2 ( ! F_72 ( & V_2 -> V_42 [ V_137 ] ) ) ;
F_9 ( V_2 ) ;
}
static int F_111 ( struct V_34 * V_35 , T_1 V_139 ,
unsigned long V_140 )
{
if ( V_46 - V_35 -> V_45 < V_140 )
return 1 ;
if ( ! ( V_139 & V_141 ) ) {
if ( F_52 ( V_92 , & V_35 -> V_87 ) ||
F_52 ( V_86 , & V_35 -> V_87 ) ||
F_52 ( V_89 , & V_35 -> V_87 ) )
return 1 ;
}
if ( V_35 -> V_91 )
return 1 ;
F_61 ( V_35 ) ;
F_37 ( V_35 ) ;
F_75 ( V_35 ) ;
return 0 ;
}
static void F_112 ( struct V_1 * V_2 , unsigned long V_142 ,
struct V_143 * V_144 )
{
int V_145 ;
struct V_34 * V_35 , * V_105 ;
for ( V_145 = 0 ; V_145 < V_138 ; V_145 ++ ) {
F_78 (b, tmp, &c->lru[l], lru_list)
if ( ! F_111 ( V_35 , V_144 -> V_23 , 0 ) &&
! -- V_142 )
return;
F_65 () ;
}
}
static int F_113 ( struct V_146 * V_146 , struct V_143 * V_144 )
{
struct V_1 * V_2 =
F_51 ( V_146 , struct V_1 , V_146 ) ;
unsigned long V_53 ;
unsigned long V_142 = V_144 -> V_142 ;
if ( V_144 -> V_23 & V_141 )
F_4 ( V_2 ) ;
else if ( ! F_7 ( V_2 ) )
return ! V_142 ? 0 : - 1 ;
if ( V_142 )
F_112 ( V_2 , V_142 , V_144 ) ;
V_53 = V_2 -> V_39 [ V_106 ] + V_2 -> V_39 [ V_112 ] ;
if ( V_53 > V_147 )
V_53 = V_147 ;
F_9 ( V_2 ) ;
return V_53 ;
}
struct V_1 * F_114 ( struct V_148 * V_63 , unsigned V_24 ,
unsigned V_100 , unsigned V_36 ,
void (* V_103)( struct V_34 * ) ,
void (* V_83)( struct V_34 * ) )
{
int V_53 ;
struct V_1 * V_2 ;
unsigned V_137 ;
F_2 ( V_24 < 1 << V_67 ||
( V_24 & ( V_24 - 1 ) ) ) ;
V_2 = F_30 ( sizeof( * V_2 ) , V_149 ) ;
if ( ! V_2 ) {
V_53 = - V_150 ;
goto V_151;
}
V_2 -> V_44 = F_115 ( sizeof( struct V_152 ) << V_153 ) ;
if ( ! V_2 -> V_44 ) {
V_53 = - V_150 ;
goto V_154;
}
V_2 -> V_63 = V_63 ;
V_2 -> V_24 = V_24 ;
V_2 -> V_65 = F_116 ( V_24 ) - 1 - V_67 ;
V_2 -> V_30 = ( F_116 ( V_24 ) - 1 >= V_155 ) ?
F_116 ( V_24 ) - 1 - V_155 : 0 ;
V_2 -> V_4 = ( F_116 ( V_24 ) - 1 < V_155 ?
V_155 - ( F_116 ( V_24 ) - 1 ) : 0 ) ;
V_2 -> V_36 = V_36 ;
V_2 -> V_103 = V_103 ;
V_2 -> V_83 = V_83 ;
for ( V_137 = 0 ; V_137 < V_138 ; V_137 ++ ) {
F_117 ( & V_2 -> V_42 [ V_137 ] ) ;
V_2 -> V_39 [ V_137 ] = 0 ;
}
for ( V_137 = 0 ; V_137 < 1 << V_153 ; V_137 ++ )
F_118 ( & V_2 -> V_44 [ V_137 ] ) ;
F_119 ( & V_2 -> V_6 ) ;
F_117 ( & V_2 -> V_100 ) ;
V_2 -> V_102 = V_100 ;
F_120 ( & V_2 -> V_95 ) ;
V_2 -> V_85 = 0 ;
V_2 -> V_60 = F_121 () ;
if ( F_87 ( V_2 -> V_60 ) ) {
V_53 = F_122 ( V_2 -> V_60 ) ;
goto V_156;
}
F_80 ( & V_17 ) ;
if ( V_2 -> V_4 ) {
if ( ! F_123 ( V_2 ) ) {
F_123 ( V_2 ) = F_124 ( V_149 , L_3 , V_2 -> V_24 ) ;
if ( ! F_123 ( V_2 ) ) {
V_53 = - V_150 ;
F_10 ( & V_17 ) ;
goto V_157;
}
}
if ( ! F_20 ( V_2 ) ) {
F_20 ( V_2 ) = F_125 ( F_123 ( V_2 ) ,
V_2 -> V_24 ,
V_2 -> V_24 , 0 , NULL ) ;
if ( ! F_20 ( V_2 ) ) {
V_53 = - V_150 ;
F_10 ( & V_17 ) ;
goto V_157;
}
}
}
F_10 ( & V_17 ) ;
while ( V_2 -> V_102 ) {
struct V_34 * V_35 = F_29 ( V_2 , V_149 ) ;
if ( ! V_35 ) {
V_53 = - V_150 ;
goto V_158;
}
F_75 ( V_35 ) ;
}
F_80 ( & V_17 ) ;
V_18 ++ ;
F_34 ( & V_2 -> V_159 , & V_160 ) ;
F_14 () ;
F_10 ( & V_17 ) ;
V_2 -> V_146 . F_113 = F_113 ;
V_2 -> V_146 . V_161 = 1 ;
V_2 -> V_146 . V_162 = 0 ;
F_126 ( & V_2 -> V_146 ) ;
return V_2 ;
V_158:
V_157:
while ( ! F_72 ( & V_2 -> V_100 ) ) {
struct V_34 * V_35 = F_73 ( V_2 -> V_100 . V_101 ,
struct V_34 , V_41 ) ;
F_39 ( & V_35 -> V_41 ) ;
F_32 ( V_35 ) ;
}
F_127 ( V_2 -> V_60 ) ;
V_156:
F_26 ( V_2 -> V_44 ) ;
V_154:
F_31 ( V_2 ) ;
V_151:
return F_89 ( V_53 ) ;
}
void F_128 ( struct V_1 * V_2 )
{
unsigned V_137 ;
F_108 ( V_2 ) ;
F_129 ( & V_2 -> V_146 ) ;
F_80 ( & V_17 ) ;
F_39 ( & V_2 -> V_159 ) ;
V_18 -- ;
F_14 () ;
F_10 ( & V_17 ) ;
for ( V_137 = 0 ; V_137 < 1 << V_153 ; V_137 ++ )
F_2 ( ! F_130 ( & V_2 -> V_44 [ V_137 ] ) ) ;
F_2 ( V_2 -> V_102 ) ;
while ( ! F_72 ( & V_2 -> V_100 ) ) {
struct V_34 * V_35 = F_73 ( V_2 -> V_100 . V_101 ,
struct V_34 , V_41 ) ;
F_39 ( & V_35 -> V_41 ) ;
F_32 ( V_35 ) ;
}
for ( V_137 = 0 ; V_137 < V_138 ; V_137 ++ )
if ( V_2 -> V_39 [ V_137 ] )
F_110 ( L_4 , V_137 , V_2 -> V_39 [ V_137 ] ) ;
for ( V_137 = 0 ; V_137 < V_138 ; V_137 ++ )
F_2 ( V_2 -> V_39 [ V_137 ] ) ;
F_127 ( V_2 -> V_60 ) ;
F_26 ( V_2 -> V_44 ) ;
F_31 ( V_2 ) ;
}
static void F_131 ( void )
{
unsigned long V_163 = V_164 ;
struct V_1 * V_2 ;
F_16 () ;
if ( V_163 > V_165 / V_166 )
V_163 = V_165 / V_166 ;
F_80 ( & V_17 ) ;
F_109 (c, &dm_bufio_all_clients, client_list) {
if ( ! F_7 ( V_2 ) )
continue;
while ( ! F_72 ( & V_2 -> V_42 [ V_106 ] ) ) {
struct V_34 * V_35 ;
V_35 = F_73 ( V_2 -> V_42 [ V_106 ] . V_167 ,
struct V_34 , V_41 ) ;
if ( F_111 ( V_35 , 0 , V_163 * V_166 ) )
break;
F_65 () ;
}
F_9 ( V_2 ) ;
F_65 () ;
}
F_10 ( & V_17 ) ;
}
static void F_132 ( struct V_168 * V_169 )
{
F_131 () ;
F_133 ( V_170 , & V_171 ,
V_172 * V_166 ) ;
}
static int T_4 F_134 ( void )
{
T_5 V_68 ;
memset ( & V_5 , 0 , sizeof V_5 ) ;
memset ( & V_173 , 0 , sizeof V_173 ) ;
V_68 = ( T_5 ) ( ( V_174 - V_175 ) *
V_176 / 100 ) << V_155 ;
if ( V_68 > V_165 )
V_68 = V_165 ;
#ifdef F_135
if ( V_68 > ( V_177 - V_178 ) * V_179 / 100 )
V_68 = ( V_177 - V_178 ) * V_179 / 100 ;
#endif
V_21 = V_68 ;
F_80 ( & V_17 ) ;
F_14 () ;
F_10 ( & V_17 ) ;
V_170 = F_136 ( L_5 ) ;
if ( ! V_170 )
return - V_150 ;
F_137 ( & V_171 , F_132 ) ;
F_133 ( V_170 , & V_171 ,
V_172 * V_166 ) ;
return 0 ;
}
static void T_6 F_138 ( void )
{
int V_180 = 0 ;
int V_137 ;
F_139 ( & V_171 ) ;
F_140 ( V_170 ) ;
for ( V_137 = 0 ; V_137 < F_3 ( V_5 ) ; V_137 ++ ) {
struct V_181 * V_182 = V_5 [ V_137 ] ;
if ( V_182 )
F_141 ( V_182 ) ;
}
for ( V_137 = 0 ; V_137 < F_3 ( V_173 ) ; V_137 ++ )
F_31 ( V_173 [ V_137 ] ) ;
if ( V_18 ) {
F_27 ( L_6 ,
V_183 , V_18 ) ;
V_180 = 1 ;
}
if ( V_15 ) {
F_27 ( L_7 ,
V_183 , V_15 ) ;
V_180 = 1 ;
}
if ( V_12 ) {
F_27 ( L_8 ,
V_183 , V_12 ) ;
V_180 = 1 ;
}
if ( V_13 ) {
F_27 ( L_9 ,
V_183 , V_13 ) ;
V_180 = 1 ;
}
if ( V_180 )
F_28 () ;
}
