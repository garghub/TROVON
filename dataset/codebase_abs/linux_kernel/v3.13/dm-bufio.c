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
V_38 -> V_51 . V_81 = V_40 << V_38 -> V_2 -> V_68 ;
V_38 -> V_51 . V_82 = V_38 -> V_2 -> V_66 ;
V_38 -> V_51 . V_52 = V_55 ;
V_25 = V_38 -> V_36 ;
V_76 = V_38 -> V_2 -> V_26 ;
if ( V_76 >= V_83 )
F_2 ( ( unsigned long ) V_25 & ( V_83 - 1 ) ) ;
else
F_2 ( ( unsigned long ) V_25 & ( V_76 - 1 ) ) ;
do {
if ( ! F_48 ( & V_38 -> V_51 , F_49 ( V_25 ) ,
V_76 < V_83 ? V_76 : V_83 ,
F_50 ( V_25 ) & ( V_83 - 1 ) ) ) {
F_2 ( V_38 -> V_2 -> V_26 <= V_83 ) ;
F_45 ( V_38 , V_54 , V_40 , V_55 ) ;
return;
}
V_76 -= V_83 ;
V_25 += V_83 ;
} while ( V_76 > 0 );
F_51 ( V_54 , & V_38 -> V_51 ) ;
}
static void F_52 ( struct V_37 * V_38 , int V_54 , T_2 V_40 ,
T_3 * V_55 )
{
if ( V_54 == V_84 && V_38 -> V_2 -> V_85 )
V_38 -> V_2 -> V_85 ( V_38 ) ;
if ( V_38 -> V_2 -> V_26 <= V_80 * V_83 &&
V_38 -> V_7 != V_33 )
F_46 ( V_38 , V_54 , V_40 , V_55 ) ;
else
F_45 ( V_38 , V_54 , V_40 , V_55 ) ;
}
static void F_53 ( struct V_51 * V_51 , int error )
{
struct V_37 * V_38 = F_54 ( V_51 , struct V_37 , V_51 ) ;
V_38 -> V_86 = error ;
if ( F_55 ( error ) ) {
struct V_1 * V_2 = V_38 -> V_2 ;
( void ) F_17 ( & V_2 -> V_87 , 0 , error ) ;
}
F_2 ( ! F_56 ( V_88 , & V_38 -> V_89 ) ) ;
F_57 () ;
F_58 ( V_88 , & V_38 -> V_89 ) ;
F_59 () ;
F_60 ( & V_38 -> V_89 , V_88 ) ;
}
static int F_61 ( void * V_90 )
{
F_62 () ;
return 0 ;
}
static void F_63 ( struct V_37 * V_38 ,
struct V_91 * V_92 )
{
if ( ! F_56 ( V_93 , & V_38 -> V_89 ) )
return;
F_58 ( V_93 , & V_38 -> V_89 ) ;
F_64 ( & V_38 -> V_89 , V_88 ,
F_61 , V_94 ) ;
if ( ! V_92 )
F_52 ( V_38 , V_84 , V_38 -> V_40 , F_53 ) ;
else
F_65 ( & V_38 -> V_92 , V_92 ) ;
}
static void F_66 ( struct V_91 * V_92 )
{
struct V_95 V_96 ;
F_67 ( & V_96 ) ;
while ( ! F_68 ( V_92 ) ) {
struct V_37 * V_38 =
F_69 ( V_92 -> V_97 , struct V_37 , V_92 ) ;
F_41 ( & V_38 -> V_92 ) ;
F_52 ( V_38 , V_84 , V_38 -> V_40 , F_53 ) ;
F_70 () ;
}
F_71 ( & V_96 ) ;
}
static void F_72 ( struct V_37 * V_38 )
{
F_2 ( V_38 -> V_98 ) ;
if ( ! V_38 -> V_89 )
return;
F_73 ( & V_38 -> V_89 , V_99 , F_61 , V_94 ) ;
F_63 ( V_38 , NULL ) ;
F_73 ( & V_38 -> V_89 , V_88 , F_61 , V_94 ) ;
}
static struct V_37 * F_74 ( struct V_1 * V_2 )
{
struct V_37 * V_38 ;
F_75 (b, &c->lru[LIST_CLEAN], lru_list) {
F_2 ( F_56 ( V_88 , & V_38 -> V_89 ) ) ;
F_2 ( F_56 ( V_93 , & V_38 -> V_89 ) ) ;
if ( ! V_38 -> V_98 ) {
F_72 ( V_38 ) ;
F_39 ( V_38 ) ;
return V_38 ;
}
F_70 () ;
}
F_75 (b, &c->lru[LIST_DIRTY], lru_list) {
F_2 ( F_56 ( V_99 , & V_38 -> V_89 ) ) ;
if ( ! V_38 -> V_98 ) {
F_72 ( V_38 ) ;
F_39 ( V_38 ) ;
return V_38 ;
}
F_70 () ;
}
return NULL ;
}
static void F_76 ( struct V_1 * V_2 )
{
F_77 ( V_100 , V_101 ) ;
F_78 ( & V_2 -> V_102 , & V_100 ) ;
F_79 ( V_101 , V_94 ) ;
F_9 ( V_2 ) ;
F_62 () ;
F_79 ( V_101 , V_103 ) ;
F_80 ( & V_2 -> V_102 , & V_100 ) ;
F_4 ( V_2 ) ;
}
static struct V_37 * F_81 ( struct V_1 * V_2 , enum V_104 V_105 )
{
struct V_37 * V_38 ;
while ( 1 ) {
if ( V_19 != 1 ) {
V_38 = F_31 ( V_2 , V_106 | V_30 | V_107 | V_108 ) ;
if ( V_38 )
return V_38 ;
}
if ( V_105 == V_109 )
return NULL ;
if ( ! F_68 ( & V_2 -> V_110 ) ) {
V_38 = F_69 ( V_2 -> V_110 . V_97 ,
struct V_37 , V_44 ) ;
F_41 ( & V_38 -> V_44 ) ;
V_2 -> V_111 ++ ;
return V_38 ;
}
V_38 = F_74 ( V_2 ) ;
if ( V_38 )
return V_38 ;
F_76 ( V_2 ) ;
}
}
static struct V_37 * F_82 ( struct V_1 * V_2 , enum V_104 V_105 )
{
struct V_37 * V_38 = F_81 ( V_2 , V_105 ) ;
if ( ! V_38 )
return NULL ;
if ( V_2 -> V_112 )
V_2 -> V_112 ( V_38 ) ;
return V_38 ;
}
static void F_83 ( struct V_37 * V_38 )
{
struct V_1 * V_2 = V_38 -> V_2 ;
if ( ! V_2 -> V_111 )
F_34 ( V_38 ) ;
else {
F_36 ( & V_38 -> V_44 , & V_2 -> V_110 ) ;
V_2 -> V_111 -- ;
}
F_84 ( & V_2 -> V_102 ) ;
}
static void F_85 ( struct V_1 * V_2 , int V_113 ,
struct V_91 * V_92 )
{
struct V_37 * V_38 , * V_114 ;
F_86 (b, tmp, &c->lru[LIST_DIRTY], lru_list) {
F_2 ( F_56 ( V_99 , & V_38 -> V_89 ) ) ;
if ( ! F_56 ( V_93 , & V_38 -> V_89 ) &&
! F_56 ( V_88 , & V_38 -> V_89 ) ) {
F_42 ( V_38 , V_115 ) ;
continue;
}
if ( V_113 && F_56 ( V_88 , & V_38 -> V_89 ) )
return;
F_63 ( V_38 , V_92 ) ;
F_70 () ;
}
}
static void F_87 ( struct V_1 * V_2 ,
unsigned long * V_116 ,
unsigned long * V_117 )
{
unsigned long V_118 ;
if ( F_16 ( V_20 ) != V_19 ) {
F_88 ( & V_17 ) ;
F_14 () ;
F_10 ( & V_17 ) ;
}
V_118 = V_22 >>
( V_2 -> V_68 + V_70 ) ;
if ( V_118 < V_119 )
V_118 = V_119 ;
* V_117 = V_118 ;
* V_116 = V_118 * V_120 / 100 ;
}
static void F_89 ( struct V_1 * V_2 ,
struct V_91 * V_92 )
{
unsigned long V_116 , V_117 ;
F_87 ( V_2 , & V_116 , & V_117 ) ;
while ( V_2 -> V_42 [ V_115 ] + V_2 -> V_42 [ V_121 ] >
V_117 ) {
struct V_37 * V_38 = F_74 ( V_2 ) ;
if ( ! V_38 )
return;
F_83 ( V_38 ) ;
F_70 () ;
}
if ( V_2 -> V_42 [ V_121 ] > V_116 )
F_85 ( V_2 , 1 , V_92 ) ;
}
static struct V_37 * F_90 ( struct V_1 * V_2 , T_2 V_40 )
{
struct V_37 * V_38 ;
F_91 (b, &c->cache_hash[DM_BUFIO_HASH(block)],
hash_list) {
F_70 () ;
if ( V_38 -> V_40 == V_40 )
return V_38 ;
}
return NULL ;
}
static struct V_37 * F_92 ( struct V_1 * V_2 , T_2 V_40 ,
enum V_104 V_105 , int * V_122 ,
struct V_91 * V_92 )
{
struct V_37 * V_38 , * V_123 = NULL ;
* V_122 = 0 ;
V_38 = F_90 ( V_2 , V_40 ) ;
if ( V_38 )
goto V_124;
if ( V_105 == V_125 )
return NULL ;
V_123 = F_82 ( V_2 , V_105 ) ;
if ( ! V_123 )
return NULL ;
V_38 = F_90 ( V_2 , V_40 ) ;
if ( V_38 ) {
F_83 ( V_123 ) ;
goto V_124;
}
F_89 ( V_2 , V_92 ) ;
V_38 = V_123 ;
V_38 -> V_98 = 1 ;
V_38 -> V_126 = 0 ;
V_38 -> V_86 = 0 ;
F_35 ( V_38 , V_40 , V_115 ) ;
if ( V_105 == V_127 ) {
V_38 -> V_89 = 0 ;
return V_38 ;
}
V_38 -> V_89 = 1 << V_99 ;
* V_122 = 1 ;
return V_38 ;
V_124:
if ( V_105 == V_109 )
return NULL ;
if ( V_105 == V_125 && F_55 ( F_56 ( V_99 , & V_38 -> V_89 ) ) )
return NULL ;
V_38 -> V_98 ++ ;
F_42 ( V_38 , F_56 ( V_93 , & V_38 -> V_89 ) ||
F_56 ( V_88 , & V_38 -> V_89 ) ) ;
return V_38 ;
}
static void F_93 ( struct V_51 * V_51 , int error )
{
struct V_37 * V_38 = F_54 ( V_51 , struct V_37 , V_51 ) ;
V_38 -> V_126 = error ;
F_2 ( ! F_56 ( V_99 , & V_38 -> V_89 ) ) ;
F_57 () ;
F_58 ( V_99 , & V_38 -> V_89 ) ;
F_59 () ;
F_60 ( & V_38 -> V_89 , V_99 ) ;
}
static void * F_94 ( struct V_1 * V_2 , T_2 V_40 ,
enum V_104 V_105 , struct V_37 * * V_128 )
{
int V_122 ;
struct V_37 * V_38 ;
F_95 ( V_92 ) ;
F_4 ( V_2 ) ;
V_38 = F_92 ( V_2 , V_40 , V_105 , & V_122 , & V_92 ) ;
F_9 ( V_2 ) ;
F_66 ( & V_92 ) ;
if ( ! V_38 )
return V_38 ;
if ( V_122 )
F_52 ( V_38 , V_129 , V_38 -> V_40 , F_93 ) ;
F_73 ( & V_38 -> V_89 , V_99 , F_61 , V_94 ) ;
if ( V_38 -> V_126 ) {
int error = V_38 -> V_126 ;
F_96 ( V_38 ) ;
return F_97 ( error ) ;
}
* V_128 = V_38 ;
return V_38 -> V_36 ;
}
void * F_98 ( struct V_1 * V_2 , T_2 V_40 ,
struct V_37 * * V_128 )
{
return F_94 ( V_2 , V_40 , V_125 , V_128 ) ;
}
void * F_99 ( struct V_1 * V_2 , T_2 V_40 ,
struct V_37 * * V_128 )
{
F_2 ( F_6 () ) ;
return F_94 ( V_2 , V_40 , V_130 , V_128 ) ;
}
void * F_100 ( struct V_1 * V_2 , T_2 V_40 ,
struct V_37 * * V_128 )
{
F_2 ( F_6 () ) ;
return F_94 ( V_2 , V_40 , V_127 , V_128 ) ;
}
void F_101 ( struct V_1 * V_2 ,
T_2 V_40 , unsigned V_131 )
{
struct V_95 V_96 ;
F_95 ( V_92 ) ;
F_2 ( F_6 () ) ;
F_67 ( & V_96 ) ;
F_4 ( V_2 ) ;
for (; V_131 -- ; V_40 ++ ) {
int V_122 ;
struct V_37 * V_38 ;
V_38 = F_92 ( V_2 , V_40 , V_109 , & V_122 ,
& V_92 ) ;
if ( F_55 ( ! F_68 ( & V_92 ) ) ) {
F_9 ( V_2 ) ;
F_71 ( & V_96 ) ;
F_66 ( & V_92 ) ;
F_67 ( & V_96 ) ;
F_4 ( V_2 ) ;
}
if ( F_55 ( V_38 != NULL ) ) {
F_9 ( V_2 ) ;
if ( V_122 )
F_52 ( V_38 , V_129 , V_38 -> V_40 , F_93 ) ;
F_96 ( V_38 ) ;
F_70 () ;
if ( ! V_131 )
goto V_132;
F_4 ( V_2 ) ;
}
}
F_9 ( V_2 ) ;
V_132:
F_71 ( & V_96 ) ;
}
void F_96 ( struct V_37 * V_38 )
{
struct V_1 * V_2 = V_38 -> V_2 ;
F_4 ( V_2 ) ;
F_2 ( ! V_38 -> V_98 ) ;
V_38 -> V_98 -- ;
if ( ! V_38 -> V_98 ) {
F_84 ( & V_2 -> V_102 ) ;
if ( ( V_38 -> V_126 || V_38 -> V_86 ) &&
! F_56 ( V_99 , & V_38 -> V_89 ) &&
! F_56 ( V_88 , & V_38 -> V_89 ) &&
! F_56 ( V_93 , & V_38 -> V_89 ) ) {
F_39 ( V_38 ) ;
F_83 ( V_38 ) ;
}
}
F_9 ( V_2 ) ;
}
void F_102 ( struct V_37 * V_38 )
{
struct V_1 * V_2 = V_38 -> V_2 ;
F_4 ( V_2 ) ;
F_2 ( F_56 ( V_99 , & V_38 -> V_89 ) ) ;
if ( ! F_103 ( V_93 , & V_38 -> V_89 ) )
F_42 ( V_38 , V_121 ) ;
F_9 ( V_2 ) ;
}
void F_104 ( struct V_1 * V_2 )
{
F_95 ( V_92 ) ;
F_2 ( F_6 () ) ;
F_4 ( V_2 ) ;
F_85 ( V_2 , 0 , & V_92 ) ;
F_9 ( V_2 ) ;
F_66 ( & V_92 ) ;
}
int F_105 ( struct V_1 * V_2 )
{
int V_133 , V_134 ;
unsigned long V_135 = 0 ;
struct V_37 * V_38 , * V_114 ;
F_95 ( V_92 ) ;
F_4 ( V_2 ) ;
F_85 ( V_2 , 0 , & V_92 ) ;
F_9 ( V_2 ) ;
F_66 ( & V_92 ) ;
F_4 ( V_2 ) ;
V_136:
F_86 (b, tmp, &c->lru[LIST_DIRTY], lru_list) {
int V_137 = 0 ;
if ( V_135 < V_2 -> V_42 [ V_121 ] )
V_135 ++ ;
F_2 ( F_56 ( V_99 , & V_38 -> V_89 ) ) ;
if ( F_56 ( V_88 , & V_38 -> V_89 ) ) {
if ( V_135 < V_2 -> V_42 [ V_121 ] ) {
V_137 = 1 ;
V_38 -> V_98 ++ ;
F_9 ( V_2 ) ;
F_73 ( & V_38 -> V_89 , V_88 ,
F_61 ,
V_94 ) ;
F_4 ( V_2 ) ;
V_38 -> V_98 -- ;
} else
F_73 ( & V_38 -> V_89 , V_88 ,
F_61 ,
V_94 ) ;
}
if ( ! F_56 ( V_93 , & V_38 -> V_89 ) &&
! F_56 ( V_88 , & V_38 -> V_89 ) )
F_42 ( V_38 , V_115 ) ;
F_70 () ;
if ( V_137 )
goto V_136;
}
F_84 ( & V_2 -> V_102 ) ;
F_9 ( V_2 ) ;
V_133 = F_106 ( & V_2 -> V_87 , 0 ) ;
V_134 = F_107 ( V_2 ) ;
if ( V_133 )
return V_133 ;
return V_134 ;
}
int F_107 ( struct V_1 * V_2 )
{
struct V_57 V_58 = {
. V_59 = V_138 ,
. V_71 . type = V_72 ,
. V_71 . V_25 . V_73 = NULL ,
. V_62 = V_2 -> V_63 ,
} ;
struct V_64 V_139 = {
. V_66 = V_2 -> V_66 ,
. V_67 = 0 ,
. V_69 = 0 ,
} ;
F_2 ( F_6 () ) ;
return V_63 ( & V_58 , 1 , & V_139 , NULL ) ;
}
void F_108 ( struct V_37 * V_38 , T_2 V_140 )
{
struct V_1 * V_2 = V_38 -> V_2 ;
struct V_37 * V_141 ;
F_2 ( F_6 () ) ;
F_4 ( V_2 ) ;
V_142:
V_141 = F_90 ( V_2 , V_140 ) ;
if ( V_141 ) {
if ( V_141 -> V_98 ) {
F_76 ( V_2 ) ;
goto V_142;
}
F_72 ( V_141 ) ;
F_39 ( V_141 ) ;
F_83 ( V_141 ) ;
}
F_2 ( ! V_38 -> V_98 ) ;
F_2 ( F_56 ( V_99 , & V_38 -> V_89 ) ) ;
F_63 ( V_38 , NULL ) ;
if ( V_38 -> V_98 == 1 ) {
F_73 ( & V_38 -> V_89 , V_88 ,
F_61 , V_94 ) ;
F_109 ( V_93 , & V_38 -> V_89 ) ;
F_39 ( V_38 ) ;
F_35 ( V_38 , V_140 , V_121 ) ;
} else {
T_2 V_143 ;
F_64 ( & V_38 -> V_89 , V_88 ,
F_61 , V_94 ) ;
V_143 = V_38 -> V_40 ;
F_39 ( V_38 ) ;
F_35 ( V_38 , V_140 , V_38 -> V_43 ) ;
F_52 ( V_38 , V_84 , V_140 , F_53 ) ;
F_73 ( & V_38 -> V_89 , V_88 ,
F_61 , V_94 ) ;
F_39 ( V_38 ) ;
F_35 ( V_38 , V_143 , V_38 -> V_43 ) ;
}
F_9 ( V_2 ) ;
F_96 ( V_38 ) ;
}
unsigned F_110 ( struct V_1 * V_2 )
{
return V_2 -> V_26 ;
}
T_2 F_111 ( struct V_1 * V_2 )
{
return F_112 ( V_2 -> V_66 -> V_144 ) >>
( V_70 + V_2 -> V_68 ) ;
}
T_2 F_113 ( struct V_37 * V_38 )
{
return V_38 -> V_40 ;
}
void * F_114 ( struct V_37 * V_38 )
{
return V_38 -> V_36 ;
}
void * F_115 ( struct V_37 * V_38 )
{
return V_38 + 1 ;
}
struct V_1 * F_116 ( struct V_37 * V_38 )
{
return V_38 -> V_2 ;
}
static void F_117 ( struct V_1 * V_2 )
{
struct V_37 * V_38 ;
int V_145 ;
F_2 ( F_6 () ) ;
F_104 ( V_2 ) ;
F_4 ( V_2 ) ;
while ( ( V_38 = F_74 ( V_2 ) ) )
F_83 ( V_38 ) ;
for ( V_145 = 0 ; V_145 < V_146 ; V_145 ++ )
F_118 (b, &c->lru[i], lru_list)
F_119 ( L_2 ,
( unsigned long long ) V_38 -> V_40 , V_38 -> V_98 , V_145 ) ;
for ( V_145 = 0 ; V_145 < V_146 ; V_145 ++ )
F_2 ( ! F_68 ( & V_2 -> V_45 [ V_145 ] ) ) ;
F_9 ( V_2 ) ;
}
static int F_120 ( struct V_37 * V_38 , T_1 V_147 ,
unsigned long V_148 )
{
if ( V_49 - V_38 -> V_48 < V_148 )
return 0 ;
if ( ! ( V_147 & V_149 ) ) {
if ( F_56 ( V_99 , & V_38 -> V_89 ) ||
F_56 ( V_88 , & V_38 -> V_89 ) ||
F_56 ( V_93 , & V_38 -> V_89 ) )
return 0 ;
}
if ( V_38 -> V_98 )
return 0 ;
F_72 ( V_38 ) ;
F_39 ( V_38 ) ;
F_83 ( V_38 ) ;
return 1 ;
}
static long F_121 ( struct V_1 * V_2 , unsigned long V_150 ,
T_1 V_23 )
{
int V_151 ;
struct V_37 * V_38 , * V_114 ;
long V_152 = 0 ;
for ( V_151 = 0 ; V_151 < V_146 ; V_151 ++ ) {
F_86 (b, tmp, &c->lru[l], lru_list) {
V_152 += F_120 ( V_38 , V_23 , 0 ) ;
if ( ! -- V_150 )
break;
}
F_70 () ;
}
return V_152 ;
}
static unsigned long
F_122 ( struct V_153 * V_154 , struct V_155 * V_156 )
{
struct V_1 * V_2 ;
unsigned long V_152 ;
V_2 = F_54 ( V_154 , struct V_1 , V_153 ) ;
if ( V_156 -> V_23 & V_149 )
F_4 ( V_2 ) ;
else if ( ! F_7 ( V_2 ) )
return V_157 ;
V_152 = F_121 ( V_2 , V_156 -> V_150 , V_156 -> V_23 ) ;
F_9 ( V_2 ) ;
return V_152 ;
}
static unsigned long
F_123 ( struct V_153 * V_154 , struct V_155 * V_156 )
{
struct V_1 * V_2 ;
unsigned long V_69 ;
V_2 = F_54 ( V_154 , struct V_1 , V_153 ) ;
if ( V_156 -> V_23 & V_149 )
F_4 ( V_2 ) ;
else if ( ! F_7 ( V_2 ) )
return 0 ;
V_69 = V_2 -> V_42 [ V_115 ] + V_2 -> V_42 [ V_121 ] ;
F_9 ( V_2 ) ;
return V_69 ;
}
struct V_1 * F_124 ( struct V_158 * V_66 , unsigned V_26 ,
unsigned V_110 , unsigned V_39 ,
void (* V_112)( struct V_37 * ) ,
void (* V_85)( struct V_37 * ) )
{
int V_56 ;
struct V_1 * V_2 ;
unsigned V_145 ;
F_2 ( V_26 < 1 << V_70 ||
( V_26 & ( V_26 - 1 ) ) ) ;
V_2 = F_32 ( sizeof( * V_2 ) , V_159 ) ;
if ( ! V_2 ) {
V_56 = - V_160 ;
goto V_161;
}
V_2 -> V_47 = F_125 ( sizeof( struct V_162 ) << V_163 ) ;
if ( ! V_2 -> V_47 ) {
V_56 = - V_160 ;
goto V_164;
}
V_2 -> V_66 = V_66 ;
V_2 -> V_26 = V_26 ;
V_2 -> V_68 = F_126 ( V_26 ) - 1 - V_70 ;
V_2 -> V_32 = ( F_126 ( V_26 ) - 1 >= V_165 ) ?
F_126 ( V_26 ) - 1 - V_165 : 0 ;
V_2 -> V_4 = ( F_126 ( V_26 ) - 1 < V_165 ?
V_165 - ( F_126 ( V_26 ) - 1 ) : 0 ) ;
V_2 -> V_39 = V_39 ;
V_2 -> V_112 = V_112 ;
V_2 -> V_85 = V_85 ;
for ( V_145 = 0 ; V_145 < V_146 ; V_145 ++ ) {
F_127 ( & V_2 -> V_45 [ V_145 ] ) ;
V_2 -> V_42 [ V_145 ] = 0 ;
}
for ( V_145 = 0 ; V_145 < 1 << V_163 ; V_145 ++ )
F_128 ( & V_2 -> V_47 [ V_145 ] ) ;
F_129 ( & V_2 -> V_6 ) ;
F_127 ( & V_2 -> V_110 ) ;
V_2 -> V_111 = V_110 ;
F_130 ( & V_2 -> V_102 ) ;
V_2 -> V_87 = 0 ;
V_2 -> V_63 = F_131 () ;
if ( F_132 ( V_2 -> V_63 ) ) {
V_56 = F_133 ( V_2 -> V_63 ) ;
goto V_166;
}
F_88 ( & V_17 ) ;
if ( V_2 -> V_4 ) {
if ( ! F_134 ( V_2 ) ) {
F_134 ( V_2 ) = F_135 ( V_159 , L_3 , V_2 -> V_26 ) ;
if ( ! F_134 ( V_2 ) ) {
V_56 = - V_160 ;
F_10 ( & V_17 ) ;
goto V_167;
}
}
if ( ! F_20 ( V_2 ) ) {
F_20 ( V_2 ) = F_136 ( F_134 ( V_2 ) ,
V_2 -> V_26 ,
V_2 -> V_26 , 0 , NULL ) ;
if ( ! F_20 ( V_2 ) ) {
V_56 = - V_160 ;
F_10 ( & V_17 ) ;
goto V_167;
}
}
}
F_10 ( & V_17 ) ;
while ( V_2 -> V_111 ) {
struct V_37 * V_38 = F_31 ( V_2 , V_159 ) ;
if ( ! V_38 ) {
V_56 = - V_160 ;
goto V_168;
}
F_83 ( V_38 ) ;
}
F_88 ( & V_17 ) ;
V_18 ++ ;
F_36 ( & V_2 -> V_169 , & V_170 ) ;
F_14 () ;
F_10 ( & V_17 ) ;
V_2 -> V_153 . V_171 = F_123 ;
V_2 -> V_153 . V_172 = F_122 ;
V_2 -> V_153 . V_173 = 1 ;
V_2 -> V_153 . V_174 = 0 ;
F_137 ( & V_2 -> V_153 ) ;
return V_2 ;
V_168:
V_167:
while ( ! F_68 ( & V_2 -> V_110 ) ) {
struct V_37 * V_38 = F_69 ( V_2 -> V_110 . V_97 ,
struct V_37 , V_44 ) ;
F_41 ( & V_38 -> V_44 ) ;
F_34 ( V_38 ) ;
}
F_138 ( V_2 -> V_63 ) ;
V_166:
F_28 ( V_2 -> V_47 ) ;
V_164:
F_33 ( V_2 ) ;
V_161:
return F_97 ( V_56 ) ;
}
void F_139 ( struct V_1 * V_2 )
{
unsigned V_145 ;
F_117 ( V_2 ) ;
F_140 ( & V_2 -> V_153 ) ;
F_88 ( & V_17 ) ;
F_41 ( & V_2 -> V_169 ) ;
V_18 -- ;
F_14 () ;
F_10 ( & V_17 ) ;
for ( V_145 = 0 ; V_145 < 1 << V_163 ; V_145 ++ )
F_2 ( ! F_141 ( & V_2 -> V_47 [ V_145 ] ) ) ;
F_2 ( V_2 -> V_111 ) ;
while ( ! F_68 ( & V_2 -> V_110 ) ) {
struct V_37 * V_38 = F_69 ( V_2 -> V_110 . V_97 ,
struct V_37 , V_44 ) ;
F_41 ( & V_38 -> V_44 ) ;
F_34 ( V_38 ) ;
}
for ( V_145 = 0 ; V_145 < V_146 ; V_145 ++ )
if ( V_2 -> V_42 [ V_145 ] )
F_119 ( L_4 , V_145 , V_2 -> V_42 [ V_145 ] ) ;
for ( V_145 = 0 ; V_145 < V_146 ; V_145 ++ )
F_2 ( V_2 -> V_42 [ V_145 ] ) ;
F_138 ( V_2 -> V_63 ) ;
F_28 ( V_2 -> V_47 ) ;
F_33 ( V_2 ) ;
}
static void F_142 ( void )
{
unsigned long V_175 = F_16 ( V_176 ) ;
struct V_1 * V_2 ;
if ( V_175 > V_177 / V_178 )
V_175 = V_177 / V_178 ;
F_88 ( & V_17 ) ;
F_118 (c, &dm_bufio_all_clients, client_list) {
if ( ! F_7 ( V_2 ) )
continue;
while ( ! F_68 ( & V_2 -> V_45 [ V_115 ] ) ) {
struct V_37 * V_38 ;
V_38 = F_69 ( V_2 -> V_45 [ V_115 ] . V_179 ,
struct V_37 , V_44 ) ;
if ( ! F_120 ( V_38 , 0 , V_175 * V_178 ) )
break;
F_70 () ;
}
F_9 ( V_2 ) ;
F_70 () ;
}
F_10 ( & V_17 ) ;
}
static void F_143 ( struct V_180 * V_181 )
{
F_142 () ;
F_144 ( V_182 , & V_183 ,
V_184 * V_178 ) ;
}
static int T_4 F_145 ( void )
{
T_5 V_71 ;
V_11 = 0 ;
V_12 = 0 ;
V_13 = 0 ;
V_15 = 0 ;
memset ( & V_5 , 0 , sizeof V_5 ) ;
memset ( & V_185 , 0 , sizeof V_185 ) ;
V_71 = ( T_5 ) ( ( V_186 - V_187 ) *
V_188 / 100 ) << V_165 ;
if ( V_71 > V_177 )
V_71 = V_177 ;
#ifdef F_146
if ( V_71 > ( V_189 - V_190 ) * V_191 / 100 )
V_71 = ( V_189 - V_190 ) * V_191 / 100 ;
#endif
V_21 = V_71 ;
F_88 ( & V_17 ) ;
F_14 () ;
F_10 ( & V_17 ) ;
V_182 = F_147 ( L_5 ) ;
if ( ! V_182 )
return - V_160 ;
F_148 ( & V_183 , F_143 ) ;
F_144 ( V_182 , & V_183 ,
V_184 * V_178 ) ;
return 0 ;
}
static void T_6 F_149 ( void )
{
int V_192 = 0 ;
int V_145 ;
F_150 ( & V_183 ) ;
F_151 ( V_182 ) ;
for ( V_145 = 0 ; V_145 < F_3 ( V_5 ) ; V_145 ++ ) {
struct V_193 * V_194 = V_5 [ V_145 ] ;
if ( V_194 )
F_152 ( V_194 ) ;
}
for ( V_145 = 0 ; V_145 < F_3 ( V_185 ) ; V_145 ++ )
F_33 ( V_185 [ V_145 ] ) ;
if ( V_18 ) {
F_29 ( L_6 ,
V_195 , V_18 ) ;
V_192 = 1 ;
}
if ( V_15 ) {
F_29 ( L_7 ,
V_195 , V_15 ) ;
V_192 = 1 ;
}
if ( V_12 ) {
F_29 ( L_8 ,
V_195 , V_12 ) ;
V_192 = 1 ;
}
if ( V_13 ) {
F_29 ( L_9 ,
V_195 , V_13 ) ;
V_192 = 1 ;
}
if ( V_192 )
F_30 () ;
}
