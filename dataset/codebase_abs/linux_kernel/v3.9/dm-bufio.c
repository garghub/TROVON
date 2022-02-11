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
F_41 ( & V_35 -> V_41 , & V_2 -> V_42 [ V_38 ] ) ;
}
static void F_42 ( unsigned long error , void * V_47 )
{
struct V_34 * V_35 = V_47 ;
V_35 -> V_48 . V_49 ( & V_35 -> V_48 , error ? - V_50 : 0 ) ;
}
static void F_43 ( struct V_34 * V_35 , int V_51 , T_2 V_37 ,
T_3 * V_52 )
{
int V_53 ;
struct V_54 V_55 = {
. V_56 = V_51 ,
. V_57 . V_58 = F_42 ,
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
static void F_44 ( struct V_34 * V_35 , int V_51 , T_2 V_37 ,
T_3 * V_52 )
{
char * V_70 ;
int V_74 ;
F_45 ( & V_35 -> V_48 ) ;
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
if ( ! F_46 ( & V_35 -> V_48 , F_47 ( V_70 ) ,
V_74 < V_81 ? V_74 : V_81 ,
F_48 ( V_70 ) & ( V_81 - 1 ) ) ) {
F_2 ( V_35 -> V_2 -> V_24 <= V_81 ) ;
F_43 ( V_35 , V_51 , V_37 , V_52 ) ;
return;
}
V_74 -= V_81 ;
V_70 += V_81 ;
} while ( V_74 > 0 );
F_49 ( V_51 , & V_35 -> V_48 ) ;
}
static void F_50 ( struct V_34 * V_35 , int V_51 , T_2 V_37 ,
T_3 * V_52 )
{
if ( V_51 == V_82 && V_35 -> V_2 -> V_83 )
V_35 -> V_2 -> V_83 ( V_35 ) ;
if ( V_35 -> V_2 -> V_24 <= V_78 * V_81 &&
V_35 -> V_7 != V_31 )
F_44 ( V_35 , V_51 , V_37 , V_52 ) ;
else
F_43 ( V_35 , V_51 , V_37 , V_52 ) ;
}
static void F_51 ( struct V_48 * V_48 , int error )
{
struct V_34 * V_35 = F_52 ( V_48 , struct V_34 , V_48 ) ;
V_35 -> V_84 = error ;
if ( F_53 ( error ) ) {
struct V_1 * V_2 = V_35 -> V_2 ;
( void ) F_17 ( & V_2 -> V_85 , 0 , error ) ;
}
F_2 ( ! F_54 ( V_86 , & V_35 -> V_87 ) ) ;
F_55 () ;
F_56 ( V_86 , & V_35 -> V_87 ) ;
F_57 () ;
F_58 ( & V_35 -> V_87 , V_86 ) ;
}
static int F_59 ( void * V_88 )
{
F_60 () ;
return 0 ;
}
static void F_61 ( struct V_34 * V_35 )
{
if ( ! F_54 ( V_89 , & V_35 -> V_87 ) )
return;
F_56 ( V_89 , & V_35 -> V_87 ) ;
F_62 ( & V_35 -> V_87 , V_86 ,
F_59 , V_90 ) ;
F_50 ( V_35 , V_82 , V_35 -> V_37 , F_51 ) ;
}
static void F_63 ( struct V_34 * V_35 )
{
F_2 ( V_35 -> V_91 ) ;
if ( ! V_35 -> V_87 )
return;
F_64 ( & V_35 -> V_87 , V_92 , F_59 , V_90 ) ;
F_61 ( V_35 ) ;
F_64 ( & V_35 -> V_87 , V_86 , F_59 , V_90 ) ;
}
static struct V_34 * F_65 ( struct V_1 * V_2 )
{
struct V_34 * V_35 ;
F_66 (b, &c->lru[LIST_CLEAN], lru_list) {
F_2 ( F_54 ( V_86 , & V_35 -> V_87 ) ) ;
F_2 ( F_54 ( V_89 , & V_35 -> V_87 ) ) ;
if ( ! V_35 -> V_91 ) {
F_63 ( V_35 ) ;
F_37 ( V_35 ) ;
return V_35 ;
}
F_67 () ;
}
F_66 (b, &c->lru[LIST_DIRTY], lru_list) {
F_2 ( F_54 ( V_92 , & V_35 -> V_87 ) ) ;
if ( ! V_35 -> V_91 ) {
F_63 ( V_35 ) ;
F_37 ( V_35 ) ;
return V_35 ;
}
F_67 () ;
}
return NULL ;
}
static void F_68 ( struct V_1 * V_2 )
{
F_69 ( V_93 , V_94 ) ;
F_70 ( & V_2 -> V_95 , & V_93 ) ;
F_71 ( V_94 , V_90 ) ;
F_9 ( V_2 ) ;
F_60 () ;
F_71 ( V_94 , V_96 ) ;
F_72 ( & V_2 -> V_95 , & V_93 ) ;
F_4 ( V_2 ) ;
}
static struct V_34 * F_73 ( struct V_1 * V_2 , enum V_97 V_98 )
{
struct V_34 * V_35 ;
while ( 1 ) {
if ( V_19 != 1 ) {
V_35 = F_29 ( V_2 , V_99 | V_28 | V_100 | V_101 ) ;
if ( V_35 )
return V_35 ;
}
if ( V_98 == V_102 )
return NULL ;
if ( ! F_74 ( & V_2 -> V_103 ) ) {
V_35 = F_75 ( V_2 -> V_103 . V_104 ,
struct V_34 , V_41 ) ;
F_39 ( & V_35 -> V_41 ) ;
V_2 -> V_105 ++ ;
return V_35 ;
}
V_35 = F_65 ( V_2 ) ;
if ( V_35 )
return V_35 ;
F_68 ( V_2 ) ;
}
}
static struct V_34 * F_76 ( struct V_1 * V_2 , enum V_97 V_98 )
{
struct V_34 * V_35 = F_73 ( V_2 , V_98 ) ;
if ( ! V_35 )
return NULL ;
if ( V_2 -> V_106 )
V_2 -> V_106 ( V_35 ) ;
return V_35 ;
}
static void F_77 ( struct V_34 * V_35 )
{
struct V_1 * V_2 = V_35 -> V_2 ;
if ( ! V_2 -> V_105 )
F_32 ( V_35 ) ;
else {
F_34 ( & V_35 -> V_41 , & V_2 -> V_103 ) ;
V_2 -> V_105 -- ;
}
F_78 ( & V_2 -> V_95 ) ;
}
static void F_79 ( struct V_1 * V_2 , int V_107 )
{
struct V_34 * V_35 , * V_108 ;
F_80 (b, tmp, &c->lru[LIST_DIRTY], lru_list) {
F_2 ( F_54 ( V_92 , & V_35 -> V_87 ) ) ;
if ( ! F_54 ( V_89 , & V_35 -> V_87 ) &&
! F_54 ( V_86 , & V_35 -> V_87 ) ) {
F_40 ( V_35 , V_109 ) ;
continue;
}
if ( V_107 && F_54 ( V_86 , & V_35 -> V_87 ) )
return;
F_61 ( V_35 ) ;
F_67 () ;
}
}
static void F_81 ( struct V_1 * V_2 ,
unsigned long * V_110 ,
unsigned long * V_111 )
{
unsigned long V_112 ;
if ( F_16 ( V_20 ) != V_19 ) {
F_82 ( & V_17 ) ;
F_14 () ;
F_10 ( & V_17 ) ;
}
V_112 = V_22 >>
( V_2 -> V_65 + V_67 ) ;
if ( V_112 < V_113 )
V_112 = V_113 ;
* V_111 = V_112 ;
* V_110 = V_112 * V_114 / 100 ;
}
static void F_83 ( struct V_1 * V_2 )
{
unsigned long V_110 , V_111 ;
F_81 ( V_2 , & V_110 , & V_111 ) ;
while ( V_2 -> V_39 [ V_109 ] + V_2 -> V_39 [ V_115 ] >
V_111 ) {
struct V_34 * V_35 = F_65 ( V_2 ) ;
if ( ! V_35 )
return;
F_77 ( V_35 ) ;
F_67 () ;
}
if ( V_2 -> V_39 [ V_115 ] > V_110 )
F_79 ( V_2 , 1 ) ;
}
static struct V_34 * F_84 ( struct V_1 * V_2 , T_2 V_37 )
{
struct V_34 * V_35 ;
F_85 (b, &c->cache_hash[DM_BUFIO_HASH(block)],
hash_list) {
F_67 () ;
if ( V_35 -> V_37 == V_37 )
return V_35 ;
}
return NULL ;
}
static struct V_34 * F_86 ( struct V_1 * V_2 , T_2 V_37 ,
enum V_97 V_98 , int * V_116 )
{
struct V_34 * V_35 , * V_117 = NULL ;
* V_116 = 0 ;
V_35 = F_84 ( V_2 , V_37 ) ;
if ( V_35 )
goto V_118;
if ( V_98 == V_119 )
return NULL ;
V_117 = F_76 ( V_2 , V_98 ) ;
if ( ! V_117 )
return NULL ;
V_35 = F_84 ( V_2 , V_37 ) ;
if ( V_35 ) {
F_77 ( V_117 ) ;
goto V_118;
}
F_83 ( V_2 ) ;
V_35 = V_117 ;
V_35 -> V_91 = 1 ;
V_35 -> V_120 = 0 ;
V_35 -> V_84 = 0 ;
F_33 ( V_35 , V_37 , V_109 ) ;
if ( V_98 == V_121 ) {
V_35 -> V_87 = 0 ;
return V_35 ;
}
V_35 -> V_87 = 1 << V_92 ;
* V_116 = 1 ;
return V_35 ;
V_118:
if ( V_98 == V_102 )
return NULL ;
if ( V_98 == V_119 && F_53 ( F_54 ( V_92 , & V_35 -> V_87 ) ) )
return NULL ;
V_35 -> V_91 ++ ;
F_40 ( V_35 , F_54 ( V_89 , & V_35 -> V_87 ) ||
F_54 ( V_86 , & V_35 -> V_87 ) ) ;
return V_35 ;
}
static void F_87 ( struct V_48 * V_48 , int error )
{
struct V_34 * V_35 = F_52 ( V_48 , struct V_34 , V_48 ) ;
V_35 -> V_120 = error ;
F_2 ( ! F_54 ( V_92 , & V_35 -> V_87 ) ) ;
F_55 () ;
F_56 ( V_92 , & V_35 -> V_87 ) ;
F_57 () ;
F_58 ( & V_35 -> V_87 , V_92 ) ;
}
static void * F_88 ( struct V_1 * V_2 , T_2 V_37 ,
enum V_97 V_98 , struct V_34 * * V_122 )
{
int V_116 ;
struct V_34 * V_35 ;
F_4 ( V_2 ) ;
V_35 = F_86 ( V_2 , V_37 , V_98 , & V_116 ) ;
F_9 ( V_2 ) ;
if ( ! V_35 )
return V_35 ;
if ( V_116 )
F_50 ( V_35 , V_123 , V_35 -> V_37 , F_87 ) ;
F_64 ( & V_35 -> V_87 , V_92 , F_59 , V_90 ) ;
if ( V_35 -> V_120 ) {
int error = V_35 -> V_120 ;
F_89 ( V_35 ) ;
return F_90 ( error ) ;
}
* V_122 = V_35 ;
return V_35 -> V_33 ;
}
void * F_91 ( struct V_1 * V_2 , T_2 V_37 ,
struct V_34 * * V_122 )
{
return F_88 ( V_2 , V_37 , V_119 , V_122 ) ;
}
void * F_92 ( struct V_1 * V_2 , T_2 V_37 ,
struct V_34 * * V_122 )
{
F_2 ( F_6 () ) ;
return F_88 ( V_2 , V_37 , V_124 , V_122 ) ;
}
void * F_93 ( struct V_1 * V_2 , T_2 V_37 ,
struct V_34 * * V_122 )
{
F_2 ( F_6 () ) ;
return F_88 ( V_2 , V_37 , V_121 , V_122 ) ;
}
void F_94 ( struct V_1 * V_2 ,
T_2 V_37 , unsigned V_125 )
{
struct V_126 V_127 ;
F_2 ( F_6 () ) ;
F_95 ( & V_127 ) ;
F_4 ( V_2 ) ;
for (; V_125 -- ; V_37 ++ ) {
int V_116 ;
struct V_34 * V_35 ;
V_35 = F_86 ( V_2 , V_37 , V_102 , & V_116 ) ;
if ( F_53 ( V_35 != NULL ) ) {
F_9 ( V_2 ) ;
if ( V_116 )
F_50 ( V_35 , V_123 , V_35 -> V_37 , F_87 ) ;
F_89 ( V_35 ) ;
F_67 () ;
if ( ! V_125 )
goto V_128;
F_4 ( V_2 ) ;
}
}
F_9 ( V_2 ) ;
V_128:
F_96 ( & V_127 ) ;
}
void F_89 ( struct V_34 * V_35 )
{
struct V_1 * V_2 = V_35 -> V_2 ;
F_4 ( V_2 ) ;
F_2 ( ! V_35 -> V_91 ) ;
V_35 -> V_91 -- ;
if ( ! V_35 -> V_91 ) {
F_78 ( & V_2 -> V_95 ) ;
if ( ( V_35 -> V_120 || V_35 -> V_84 ) &&
! F_54 ( V_92 , & V_35 -> V_87 ) &&
! F_54 ( V_86 , & V_35 -> V_87 ) &&
! F_54 ( V_89 , & V_35 -> V_87 ) ) {
F_37 ( V_35 ) ;
F_77 ( V_35 ) ;
}
}
F_9 ( V_2 ) ;
}
void F_97 ( struct V_34 * V_35 )
{
struct V_1 * V_2 = V_35 -> V_2 ;
F_4 ( V_2 ) ;
F_2 ( F_54 ( V_92 , & V_35 -> V_87 ) ) ;
if ( ! F_98 ( V_89 , & V_35 -> V_87 ) )
F_40 ( V_35 , V_115 ) ;
F_9 ( V_2 ) ;
}
void F_99 ( struct V_1 * V_2 )
{
F_2 ( F_6 () ) ;
F_4 ( V_2 ) ;
F_79 ( V_2 , 0 ) ;
F_9 ( V_2 ) ;
}
int F_100 ( struct V_1 * V_2 )
{
int V_129 , V_130 ;
unsigned long V_131 = 0 ;
struct V_34 * V_35 , * V_108 ;
F_4 ( V_2 ) ;
F_79 ( V_2 , 0 ) ;
V_132:
F_80 (b, tmp, &c->lru[LIST_DIRTY], lru_list) {
int V_133 = 0 ;
if ( V_131 < V_2 -> V_39 [ V_115 ] )
V_131 ++ ;
F_2 ( F_54 ( V_92 , & V_35 -> V_87 ) ) ;
if ( F_54 ( V_86 , & V_35 -> V_87 ) ) {
if ( V_131 < V_2 -> V_39 [ V_115 ] ) {
V_133 = 1 ;
V_35 -> V_91 ++ ;
F_9 ( V_2 ) ;
F_64 ( & V_35 -> V_87 , V_86 ,
F_59 ,
V_90 ) ;
F_4 ( V_2 ) ;
V_35 -> V_91 -- ;
} else
F_64 ( & V_35 -> V_87 , V_86 ,
F_59 ,
V_90 ) ;
}
if ( ! F_54 ( V_89 , & V_35 -> V_87 ) &&
! F_54 ( V_86 , & V_35 -> V_87 ) )
F_40 ( V_35 , V_109 ) ;
F_67 () ;
if ( V_133 )
goto V_132;
}
F_78 ( & V_2 -> V_95 ) ;
F_9 ( V_2 ) ;
V_129 = F_101 ( & V_2 -> V_85 , 0 ) ;
V_130 = F_102 ( V_2 ) ;
if ( V_129 )
return V_129 ;
return V_130 ;
}
int F_102 ( struct V_1 * V_2 )
{
struct V_54 V_55 = {
. V_56 = V_134 ,
. V_68 . type = V_69 ,
. V_68 . V_70 . V_71 = NULL ,
. V_59 = V_2 -> V_60 ,
} ;
struct V_61 V_135 = {
. V_63 = V_2 -> V_63 ,
. V_64 = 0 ,
. V_66 = 0 ,
} ;
F_2 ( F_6 () ) ;
return V_60 ( & V_55 , 1 , & V_135 , NULL ) ;
}
void F_103 ( struct V_34 * V_35 , T_2 V_136 )
{
struct V_1 * V_2 = V_35 -> V_2 ;
struct V_34 * V_137 ;
F_2 ( F_6 () ) ;
F_4 ( V_2 ) ;
V_138:
V_137 = F_84 ( V_2 , V_136 ) ;
if ( V_137 ) {
if ( V_137 -> V_91 ) {
F_68 ( V_2 ) ;
goto V_138;
}
F_63 ( V_137 ) ;
F_37 ( V_137 ) ;
F_77 ( V_137 ) ;
}
F_2 ( ! V_35 -> V_91 ) ;
F_2 ( F_54 ( V_92 , & V_35 -> V_87 ) ) ;
F_61 ( V_35 ) ;
if ( V_35 -> V_91 == 1 ) {
F_64 ( & V_35 -> V_87 , V_86 ,
F_59 , V_90 ) ;
F_104 ( V_89 , & V_35 -> V_87 ) ;
F_37 ( V_35 ) ;
F_33 ( V_35 , V_136 , V_115 ) ;
} else {
T_2 V_139 ;
F_62 ( & V_35 -> V_87 , V_86 ,
F_59 , V_90 ) ;
V_139 = V_35 -> V_37 ;
F_37 ( V_35 ) ;
F_33 ( V_35 , V_136 , V_35 -> V_40 ) ;
F_50 ( V_35 , V_82 , V_136 , F_51 ) ;
F_64 ( & V_35 -> V_87 , V_86 ,
F_59 , V_90 ) ;
F_37 ( V_35 ) ;
F_33 ( V_35 , V_139 , V_35 -> V_40 ) ;
}
F_9 ( V_2 ) ;
F_89 ( V_35 ) ;
}
unsigned F_105 ( struct V_1 * V_2 )
{
return V_2 -> V_24 ;
}
T_2 F_106 ( struct V_1 * V_2 )
{
return F_107 ( V_2 -> V_63 -> V_140 ) >>
( V_67 + V_2 -> V_65 ) ;
}
T_2 F_108 ( struct V_34 * V_35 )
{
return V_35 -> V_37 ;
}
void * F_109 ( struct V_34 * V_35 )
{
return V_35 -> V_33 ;
}
void * F_110 ( struct V_34 * V_35 )
{
return V_35 + 1 ;
}
struct V_1 * F_111 ( struct V_34 * V_35 )
{
return V_35 -> V_2 ;
}
static void F_112 ( struct V_1 * V_2 )
{
struct V_34 * V_35 ;
int V_141 ;
F_2 ( F_6 () ) ;
F_99 ( V_2 ) ;
F_4 ( V_2 ) ;
while ( ( V_35 = F_65 ( V_2 ) ) )
F_77 ( V_35 ) ;
for ( V_141 = 0 ; V_141 < V_142 ; V_141 ++ )
F_113 (b, &c->lru[i], lru_list)
F_114 ( L_2 ,
( unsigned long long ) V_35 -> V_37 , V_35 -> V_91 , V_141 ) ;
for ( V_141 = 0 ; V_141 < V_142 ; V_141 ++ )
F_2 ( ! F_74 ( & V_2 -> V_42 [ V_141 ] ) ) ;
F_9 ( V_2 ) ;
}
static int F_115 ( struct V_34 * V_35 , T_1 V_143 ,
unsigned long V_144 )
{
if ( V_46 - V_35 -> V_45 < V_144 )
return 1 ;
if ( ! ( V_143 & V_145 ) ) {
if ( F_54 ( V_92 , & V_35 -> V_87 ) ||
F_54 ( V_86 , & V_35 -> V_87 ) ||
F_54 ( V_89 , & V_35 -> V_87 ) )
return 1 ;
}
if ( V_35 -> V_91 )
return 1 ;
F_63 ( V_35 ) ;
F_37 ( V_35 ) ;
F_77 ( V_35 ) ;
return 0 ;
}
static void F_116 ( struct V_1 * V_2 , unsigned long V_146 ,
struct V_147 * V_148 )
{
int V_149 ;
struct V_34 * V_35 , * V_108 ;
for ( V_149 = 0 ; V_149 < V_142 ; V_149 ++ ) {
F_80 (b, tmp, &c->lru[l], lru_list)
if ( ! F_115 ( V_35 , V_148 -> V_23 , 0 ) &&
! -- V_146 )
return;
F_67 () ;
}
}
static int F_117 ( struct V_150 * V_150 , struct V_147 * V_148 )
{
struct V_1 * V_2 =
F_52 ( V_150 , struct V_1 , V_150 ) ;
unsigned long V_53 ;
unsigned long V_146 = V_148 -> V_146 ;
if ( V_148 -> V_23 & V_145 )
F_4 ( V_2 ) ;
else if ( ! F_7 ( V_2 ) )
return ! V_146 ? 0 : - 1 ;
if ( V_146 )
F_116 ( V_2 , V_146 , V_148 ) ;
V_53 = V_2 -> V_39 [ V_109 ] + V_2 -> V_39 [ V_115 ] ;
if ( V_53 > V_151 )
V_53 = V_151 ;
F_9 ( V_2 ) ;
return V_53 ;
}
struct V_1 * F_118 ( struct V_152 * V_63 , unsigned V_24 ,
unsigned V_103 , unsigned V_36 ,
void (* V_106)( struct V_34 * ) ,
void (* V_83)( struct V_34 * ) )
{
int V_53 ;
struct V_1 * V_2 ;
unsigned V_141 ;
F_2 ( V_24 < 1 << V_67 ||
( V_24 & ( V_24 - 1 ) ) ) ;
V_2 = F_30 ( sizeof( * V_2 ) , V_153 ) ;
if ( ! V_2 ) {
V_53 = - V_154 ;
goto V_155;
}
V_2 -> V_44 = F_119 ( sizeof( struct V_156 ) << V_157 ) ;
if ( ! V_2 -> V_44 ) {
V_53 = - V_154 ;
goto V_158;
}
V_2 -> V_63 = V_63 ;
V_2 -> V_24 = V_24 ;
V_2 -> V_65 = F_120 ( V_24 ) - 1 - V_67 ;
V_2 -> V_30 = ( F_120 ( V_24 ) - 1 >= V_159 ) ?
F_120 ( V_24 ) - 1 - V_159 : 0 ;
V_2 -> V_4 = ( F_120 ( V_24 ) - 1 < V_159 ?
V_159 - ( F_120 ( V_24 ) - 1 ) : 0 ) ;
V_2 -> V_36 = V_36 ;
V_2 -> V_106 = V_106 ;
V_2 -> V_83 = V_83 ;
for ( V_141 = 0 ; V_141 < V_142 ; V_141 ++ ) {
F_121 ( & V_2 -> V_42 [ V_141 ] ) ;
V_2 -> V_39 [ V_141 ] = 0 ;
}
for ( V_141 = 0 ; V_141 < 1 << V_157 ; V_141 ++ )
F_122 ( & V_2 -> V_44 [ V_141 ] ) ;
F_123 ( & V_2 -> V_6 ) ;
F_121 ( & V_2 -> V_103 ) ;
V_2 -> V_105 = V_103 ;
F_124 ( & V_2 -> V_95 ) ;
V_2 -> V_85 = 0 ;
V_2 -> V_60 = F_125 () ;
if ( F_126 ( V_2 -> V_60 ) ) {
V_53 = F_127 ( V_2 -> V_60 ) ;
goto V_160;
}
F_82 ( & V_17 ) ;
if ( V_2 -> V_4 ) {
if ( ! F_128 ( V_2 ) ) {
F_128 ( V_2 ) = F_129 ( V_153 , L_3 , V_2 -> V_24 ) ;
if ( ! F_128 ( V_2 ) ) {
V_53 = - V_154 ;
F_10 ( & V_17 ) ;
goto V_161;
}
}
if ( ! F_20 ( V_2 ) ) {
F_20 ( V_2 ) = F_130 ( F_128 ( V_2 ) ,
V_2 -> V_24 ,
V_2 -> V_24 , 0 , NULL ) ;
if ( ! F_20 ( V_2 ) ) {
V_53 = - V_154 ;
F_10 ( & V_17 ) ;
goto V_161;
}
}
}
F_10 ( & V_17 ) ;
while ( V_2 -> V_105 ) {
struct V_34 * V_35 = F_29 ( V_2 , V_153 ) ;
if ( ! V_35 ) {
V_53 = - V_154 ;
goto V_162;
}
F_77 ( V_35 ) ;
}
F_82 ( & V_17 ) ;
V_18 ++ ;
F_34 ( & V_2 -> V_163 , & V_164 ) ;
F_14 () ;
F_10 ( & V_17 ) ;
V_2 -> V_150 . F_117 = F_117 ;
V_2 -> V_150 . V_165 = 1 ;
V_2 -> V_150 . V_166 = 0 ;
F_131 ( & V_2 -> V_150 ) ;
return V_2 ;
V_162:
V_161:
while ( ! F_74 ( & V_2 -> V_103 ) ) {
struct V_34 * V_35 = F_75 ( V_2 -> V_103 . V_104 ,
struct V_34 , V_41 ) ;
F_39 ( & V_35 -> V_41 ) ;
F_32 ( V_35 ) ;
}
F_132 ( V_2 -> V_60 ) ;
V_160:
F_26 ( V_2 -> V_44 ) ;
V_158:
F_31 ( V_2 ) ;
V_155:
return F_90 ( V_53 ) ;
}
void F_133 ( struct V_1 * V_2 )
{
unsigned V_141 ;
F_112 ( V_2 ) ;
F_134 ( & V_2 -> V_150 ) ;
F_82 ( & V_17 ) ;
F_39 ( & V_2 -> V_163 ) ;
V_18 -- ;
F_14 () ;
F_10 ( & V_17 ) ;
for ( V_141 = 0 ; V_141 < 1 << V_157 ; V_141 ++ )
F_2 ( ! F_135 ( & V_2 -> V_44 [ V_141 ] ) ) ;
F_2 ( V_2 -> V_105 ) ;
while ( ! F_74 ( & V_2 -> V_103 ) ) {
struct V_34 * V_35 = F_75 ( V_2 -> V_103 . V_104 ,
struct V_34 , V_41 ) ;
F_39 ( & V_35 -> V_41 ) ;
F_32 ( V_35 ) ;
}
for ( V_141 = 0 ; V_141 < V_142 ; V_141 ++ )
if ( V_2 -> V_39 [ V_141 ] )
F_114 ( L_4 , V_141 , V_2 -> V_39 [ V_141 ] ) ;
for ( V_141 = 0 ; V_141 < V_142 ; V_141 ++ )
F_2 ( V_2 -> V_39 [ V_141 ] ) ;
F_132 ( V_2 -> V_60 ) ;
F_26 ( V_2 -> V_44 ) ;
F_31 ( V_2 ) ;
}
static void F_136 ( void )
{
unsigned long V_167 = F_16 ( V_168 ) ;
struct V_1 * V_2 ;
if ( V_167 > V_169 / V_170 )
V_167 = V_169 / V_170 ;
F_82 ( & V_17 ) ;
F_113 (c, &dm_bufio_all_clients, client_list) {
if ( ! F_7 ( V_2 ) )
continue;
while ( ! F_74 ( & V_2 -> V_42 [ V_109 ] ) ) {
struct V_34 * V_35 ;
V_35 = F_75 ( V_2 -> V_42 [ V_109 ] . V_171 ,
struct V_34 , V_41 ) ;
if ( F_115 ( V_35 , 0 , V_167 * V_170 ) )
break;
F_67 () ;
}
F_9 ( V_2 ) ;
F_67 () ;
}
F_10 ( & V_17 ) ;
}
static void F_137 ( struct V_172 * V_173 )
{
F_136 () ;
F_138 ( V_174 , & V_175 ,
V_176 * V_170 ) ;
}
static int T_4 F_139 ( void )
{
T_5 V_68 ;
memset ( & V_5 , 0 , sizeof V_5 ) ;
memset ( & V_177 , 0 , sizeof V_177 ) ;
V_68 = ( T_5 ) ( ( V_178 - V_179 ) *
V_180 / 100 ) << V_159 ;
if ( V_68 > V_169 )
V_68 = V_169 ;
#ifdef F_140
if ( V_68 > ( V_181 - V_182 ) * V_183 / 100 )
V_68 = ( V_181 - V_182 ) * V_183 / 100 ;
#endif
V_21 = V_68 ;
F_82 ( & V_17 ) ;
F_14 () ;
F_10 ( & V_17 ) ;
V_174 = F_141 ( L_5 ) ;
if ( ! V_174 )
return - V_154 ;
F_142 ( & V_175 , F_137 ) ;
F_138 ( V_174 , & V_175 ,
V_176 * V_170 ) ;
return 0 ;
}
static void T_6 F_143 ( void )
{
int V_184 = 0 ;
int V_141 ;
F_144 ( & V_175 ) ;
F_145 ( V_174 ) ;
for ( V_141 = 0 ; V_141 < F_3 ( V_5 ) ; V_141 ++ ) {
struct V_185 * V_186 = V_5 [ V_141 ] ;
if ( V_186 )
F_146 ( V_186 ) ;
}
for ( V_141 = 0 ; V_141 < F_3 ( V_177 ) ; V_141 ++ )
F_31 ( V_177 [ V_141 ] ) ;
if ( V_18 ) {
F_27 ( L_6 ,
V_187 , V_18 ) ;
V_184 = 1 ;
}
if ( V_15 ) {
F_27 ( L_7 ,
V_187 , V_15 ) ;
V_184 = 1 ;
}
if ( V_12 ) {
F_27 ( L_8 ,
V_187 , V_12 ) ;
V_184 = 1 ;
}
if ( V_13 ) {
F_27 ( L_9 ,
V_187 , V_13 ) ;
V_184 = 1 ;
}
if ( V_184 )
F_28 () ;
}
