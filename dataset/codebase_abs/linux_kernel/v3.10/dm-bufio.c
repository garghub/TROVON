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
V_25 = F_23 ( V_2 -> V_26 , V_23 , V_34 ) ;
if ( V_23 & V_30 )
F_24 ( V_24 ) ;
return V_25 ;
}
static void F_25 ( struct V_1 * V_2 ,
void * V_35 , enum V_7 V_7 )
{
switch ( V_7 ) {
case V_28 :
F_26 ( F_20 ( V_2 ) , V_35 ) ;
break;
case V_31 :
F_27 ( ( unsigned long ) V_35 , V_2 -> V_32 ) ;
break;
case V_33 :
F_28 ( V_35 ) ;
break;
default:
F_29 ( L_1 ,
V_7 ) ;
F_30 () ;
}
}
static struct V_36 * F_31 ( struct V_1 * V_2 , T_1 V_23 )
{
struct V_36 * V_37 = F_32 ( sizeof( struct V_36 ) + V_2 -> V_38 ,
V_23 ) ;
if ( ! V_37 )
return NULL ;
V_37 -> V_2 = V_2 ;
V_37 -> V_35 = F_18 ( V_2 , V_23 , & V_37 -> V_7 ) ;
if ( ! V_37 -> V_35 ) {
F_33 ( V_37 ) ;
return NULL ;
}
F_11 ( V_37 -> V_7 , ( long ) V_2 -> V_26 ) ;
return V_37 ;
}
static void F_34 ( struct V_36 * V_37 )
{
struct V_1 * V_2 = V_37 -> V_2 ;
F_11 ( V_37 -> V_7 , - ( long ) V_2 -> V_26 ) ;
F_25 ( V_2 , V_37 -> V_35 , V_37 -> V_7 ) ;
F_33 ( V_37 ) ;
}
static void F_35 ( struct V_36 * V_37 , T_2 V_39 , int V_40 )
{
struct V_1 * V_2 = V_37 -> V_2 ;
V_2 -> V_41 [ V_40 ] ++ ;
V_37 -> V_39 = V_39 ;
V_37 -> V_42 = V_40 ;
F_36 ( & V_37 -> V_43 , & V_2 -> V_44 [ V_40 ] ) ;
F_37 ( & V_37 -> V_45 , & V_2 -> V_46 [ F_38 ( V_39 ) ] ) ;
V_37 -> V_47 = V_48 ;
}
static void F_39 ( struct V_36 * V_37 )
{
struct V_1 * V_2 = V_37 -> V_2 ;
F_2 ( ! V_2 -> V_41 [ V_37 -> V_42 ] ) ;
V_2 -> V_41 [ V_37 -> V_42 ] -- ;
F_40 ( & V_37 -> V_45 ) ;
F_41 ( & V_37 -> V_43 ) ;
}
static void F_42 ( struct V_36 * V_37 , int V_40 )
{
struct V_1 * V_2 = V_37 -> V_2 ;
F_2 ( ! V_2 -> V_41 [ V_37 -> V_42 ] ) ;
V_2 -> V_41 [ V_37 -> V_42 ] -- ;
V_2 -> V_41 [ V_40 ] ++ ;
V_37 -> V_42 = V_40 ;
F_43 ( & V_37 -> V_43 , & V_2 -> V_44 [ V_40 ] ) ;
}
static void F_44 ( unsigned long error , void * V_49 )
{
struct V_36 * V_37 = V_49 ;
V_37 -> V_50 . V_51 ( & V_37 -> V_50 , error ? - V_52 : 0 ) ;
}
static void F_45 ( struct V_36 * V_37 , int V_53 , T_2 V_39 ,
T_3 * V_54 )
{
int V_55 ;
struct V_56 V_57 = {
. V_58 = V_53 ,
. V_59 . V_60 = F_44 ,
. V_59 . V_49 = V_37 ,
. V_61 = V_37 -> V_2 -> V_62 ,
} ;
struct V_63 V_64 = {
. V_65 = V_37 -> V_2 -> V_65 ,
. V_66 = V_39 << V_37 -> V_2 -> V_67 ,
. V_68 = V_37 -> V_2 -> V_26 >> V_69 ,
} ;
if ( V_37 -> V_7 != V_33 ) {
V_57 . V_70 . type = V_71 ;
V_57 . V_70 . V_25 . V_72 = V_37 -> V_35 ;
} else {
V_57 . V_70 . type = V_73 ;
V_57 . V_70 . V_25 . V_74 = V_37 -> V_35 ;
}
V_37 -> V_50 . V_51 = V_54 ;
V_55 = V_62 ( & V_57 , 1 , & V_64 , NULL ) ;
if ( V_55 )
V_54 ( & V_37 -> V_50 , V_55 ) ;
}
static void F_46 ( struct V_36 * V_37 , int V_53 , T_2 V_39 ,
T_3 * V_54 )
{
char * V_25 ;
int V_75 ;
F_47 ( & V_37 -> V_50 ) ;
V_37 -> V_50 . V_76 = V_37 -> V_77 ;
V_37 -> V_50 . V_78 = V_79 ;
V_37 -> V_50 . V_80 = V_39 << V_37 -> V_2 -> V_67 ;
V_37 -> V_50 . V_81 = V_37 -> V_2 -> V_65 ;
V_37 -> V_50 . V_51 = V_54 ;
V_25 = V_37 -> V_35 ;
V_75 = V_37 -> V_2 -> V_26 ;
if ( V_75 >= V_82 )
F_2 ( ( unsigned long ) V_25 & ( V_82 - 1 ) ) ;
else
F_2 ( ( unsigned long ) V_25 & ( V_75 - 1 ) ) ;
do {
if ( ! F_48 ( & V_37 -> V_50 , F_49 ( V_25 ) ,
V_75 < V_82 ? V_75 : V_82 ,
F_50 ( V_25 ) & ( V_82 - 1 ) ) ) {
F_2 ( V_37 -> V_2 -> V_26 <= V_82 ) ;
F_45 ( V_37 , V_53 , V_39 , V_54 ) ;
return;
}
V_75 -= V_82 ;
V_25 += V_82 ;
} while ( V_75 > 0 );
F_51 ( V_53 , & V_37 -> V_50 ) ;
}
static void F_52 ( struct V_36 * V_37 , int V_53 , T_2 V_39 ,
T_3 * V_54 )
{
if ( V_53 == V_83 && V_37 -> V_2 -> V_84 )
V_37 -> V_2 -> V_84 ( V_37 ) ;
if ( V_37 -> V_2 -> V_26 <= V_79 * V_82 &&
V_37 -> V_7 != V_33 )
F_46 ( V_37 , V_53 , V_39 , V_54 ) ;
else
F_45 ( V_37 , V_53 , V_39 , V_54 ) ;
}
static void F_53 ( struct V_50 * V_50 , int error )
{
struct V_36 * V_37 = F_54 ( V_50 , struct V_36 , V_50 ) ;
V_37 -> V_85 = error ;
if ( F_55 ( error ) ) {
struct V_1 * V_2 = V_37 -> V_2 ;
( void ) F_17 ( & V_2 -> V_86 , 0 , error ) ;
}
F_2 ( ! F_56 ( V_87 , & V_37 -> V_88 ) ) ;
F_57 () ;
F_58 ( V_87 , & V_37 -> V_88 ) ;
F_59 () ;
F_60 ( & V_37 -> V_88 , V_87 ) ;
}
static int F_61 ( void * V_89 )
{
F_62 () ;
return 0 ;
}
static void F_63 ( struct V_36 * V_37 )
{
if ( ! F_56 ( V_90 , & V_37 -> V_88 ) )
return;
F_58 ( V_90 , & V_37 -> V_88 ) ;
F_64 ( & V_37 -> V_88 , V_87 ,
F_61 , V_91 ) ;
F_52 ( V_37 , V_83 , V_37 -> V_39 , F_53 ) ;
}
static void F_65 ( struct V_36 * V_37 )
{
F_2 ( V_37 -> V_92 ) ;
if ( ! V_37 -> V_88 )
return;
F_66 ( & V_37 -> V_88 , V_93 , F_61 , V_91 ) ;
F_63 ( V_37 ) ;
F_66 ( & V_37 -> V_88 , V_87 , F_61 , V_91 ) ;
}
static struct V_36 * F_67 ( struct V_1 * V_2 )
{
struct V_36 * V_37 ;
F_68 (b, &c->lru[LIST_CLEAN], lru_list) {
F_2 ( F_56 ( V_87 , & V_37 -> V_88 ) ) ;
F_2 ( F_56 ( V_90 , & V_37 -> V_88 ) ) ;
if ( ! V_37 -> V_92 ) {
F_65 ( V_37 ) ;
F_39 ( V_37 ) ;
return V_37 ;
}
F_69 () ;
}
F_68 (b, &c->lru[LIST_DIRTY], lru_list) {
F_2 ( F_56 ( V_93 , & V_37 -> V_88 ) ) ;
if ( ! V_37 -> V_92 ) {
F_65 ( V_37 ) ;
F_39 ( V_37 ) ;
return V_37 ;
}
F_69 () ;
}
return NULL ;
}
static void F_70 ( struct V_1 * V_2 )
{
F_71 ( V_94 , V_95 ) ;
F_72 ( & V_2 -> V_96 , & V_94 ) ;
F_73 ( V_95 , V_91 ) ;
F_9 ( V_2 ) ;
F_62 () ;
F_73 ( V_95 , V_97 ) ;
F_74 ( & V_2 -> V_96 , & V_94 ) ;
F_4 ( V_2 ) ;
}
static struct V_36 * F_75 ( struct V_1 * V_2 , enum V_98 V_99 )
{
struct V_36 * V_37 ;
while ( 1 ) {
if ( V_19 != 1 ) {
V_37 = F_31 ( V_2 , V_100 | V_30 | V_101 | V_102 ) ;
if ( V_37 )
return V_37 ;
}
if ( V_99 == V_103 )
return NULL ;
if ( ! F_76 ( & V_2 -> V_104 ) ) {
V_37 = F_77 ( V_2 -> V_104 . V_105 ,
struct V_36 , V_43 ) ;
F_41 ( & V_37 -> V_43 ) ;
V_2 -> V_106 ++ ;
return V_37 ;
}
V_37 = F_67 ( V_2 ) ;
if ( V_37 )
return V_37 ;
F_70 ( V_2 ) ;
}
}
static struct V_36 * F_78 ( struct V_1 * V_2 , enum V_98 V_99 )
{
struct V_36 * V_37 = F_75 ( V_2 , V_99 ) ;
if ( ! V_37 )
return NULL ;
if ( V_2 -> V_107 )
V_2 -> V_107 ( V_37 ) ;
return V_37 ;
}
static void F_79 ( struct V_36 * V_37 )
{
struct V_1 * V_2 = V_37 -> V_2 ;
if ( ! V_2 -> V_106 )
F_34 ( V_37 ) ;
else {
F_36 ( & V_37 -> V_43 , & V_2 -> V_104 ) ;
V_2 -> V_106 -- ;
}
F_80 ( & V_2 -> V_96 ) ;
}
static void F_81 ( struct V_1 * V_2 , int V_108 )
{
struct V_36 * V_37 , * V_109 ;
F_82 (b, tmp, &c->lru[LIST_DIRTY], lru_list) {
F_2 ( F_56 ( V_93 , & V_37 -> V_88 ) ) ;
if ( ! F_56 ( V_90 , & V_37 -> V_88 ) &&
! F_56 ( V_87 , & V_37 -> V_88 ) ) {
F_42 ( V_37 , V_110 ) ;
continue;
}
if ( V_108 && F_56 ( V_87 , & V_37 -> V_88 ) )
return;
F_63 ( V_37 ) ;
F_69 () ;
}
}
static void F_83 ( struct V_1 * V_2 ,
unsigned long * V_111 ,
unsigned long * V_112 )
{
unsigned long V_113 ;
if ( F_16 ( V_20 ) != V_19 ) {
F_84 ( & V_17 ) ;
F_14 () ;
F_10 ( & V_17 ) ;
}
V_113 = V_22 >>
( V_2 -> V_67 + V_69 ) ;
if ( V_113 < V_114 )
V_113 = V_114 ;
* V_112 = V_113 ;
* V_111 = V_113 * V_115 / 100 ;
}
static void F_85 ( struct V_1 * V_2 )
{
unsigned long V_111 , V_112 ;
F_83 ( V_2 , & V_111 , & V_112 ) ;
while ( V_2 -> V_41 [ V_110 ] + V_2 -> V_41 [ V_116 ] >
V_112 ) {
struct V_36 * V_37 = F_67 ( V_2 ) ;
if ( ! V_37 )
return;
F_79 ( V_37 ) ;
F_69 () ;
}
if ( V_2 -> V_41 [ V_116 ] > V_111 )
F_81 ( V_2 , 1 ) ;
}
static struct V_36 * F_86 ( struct V_1 * V_2 , T_2 V_39 )
{
struct V_36 * V_37 ;
F_87 (b, &c->cache_hash[DM_BUFIO_HASH(block)],
hash_list) {
F_69 () ;
if ( V_37 -> V_39 == V_39 )
return V_37 ;
}
return NULL ;
}
static struct V_36 * F_88 ( struct V_1 * V_2 , T_2 V_39 ,
enum V_98 V_99 , int * V_117 )
{
struct V_36 * V_37 , * V_118 = NULL ;
* V_117 = 0 ;
V_37 = F_86 ( V_2 , V_39 ) ;
if ( V_37 )
goto V_119;
if ( V_99 == V_120 )
return NULL ;
V_118 = F_78 ( V_2 , V_99 ) ;
if ( ! V_118 )
return NULL ;
V_37 = F_86 ( V_2 , V_39 ) ;
if ( V_37 ) {
F_79 ( V_118 ) ;
goto V_119;
}
F_85 ( V_2 ) ;
V_37 = V_118 ;
V_37 -> V_92 = 1 ;
V_37 -> V_121 = 0 ;
V_37 -> V_85 = 0 ;
F_35 ( V_37 , V_39 , V_110 ) ;
if ( V_99 == V_122 ) {
V_37 -> V_88 = 0 ;
return V_37 ;
}
V_37 -> V_88 = 1 << V_93 ;
* V_117 = 1 ;
return V_37 ;
V_119:
if ( V_99 == V_103 )
return NULL ;
if ( V_99 == V_120 && F_55 ( F_56 ( V_93 , & V_37 -> V_88 ) ) )
return NULL ;
V_37 -> V_92 ++ ;
F_42 ( V_37 , F_56 ( V_90 , & V_37 -> V_88 ) ||
F_56 ( V_87 , & V_37 -> V_88 ) ) ;
return V_37 ;
}
static void F_89 ( struct V_50 * V_50 , int error )
{
struct V_36 * V_37 = F_54 ( V_50 , struct V_36 , V_50 ) ;
V_37 -> V_121 = error ;
F_2 ( ! F_56 ( V_93 , & V_37 -> V_88 ) ) ;
F_57 () ;
F_58 ( V_93 , & V_37 -> V_88 ) ;
F_59 () ;
F_60 ( & V_37 -> V_88 , V_93 ) ;
}
static void * F_90 ( struct V_1 * V_2 , T_2 V_39 ,
enum V_98 V_99 , struct V_36 * * V_123 )
{
int V_117 ;
struct V_36 * V_37 ;
F_4 ( V_2 ) ;
V_37 = F_88 ( V_2 , V_39 , V_99 , & V_117 ) ;
F_9 ( V_2 ) ;
if ( ! V_37 )
return V_37 ;
if ( V_117 )
F_52 ( V_37 , V_124 , V_37 -> V_39 , F_89 ) ;
F_66 ( & V_37 -> V_88 , V_93 , F_61 , V_91 ) ;
if ( V_37 -> V_121 ) {
int error = V_37 -> V_121 ;
F_91 ( V_37 ) ;
return F_92 ( error ) ;
}
* V_123 = V_37 ;
return V_37 -> V_35 ;
}
void * F_93 ( struct V_1 * V_2 , T_2 V_39 ,
struct V_36 * * V_123 )
{
return F_90 ( V_2 , V_39 , V_120 , V_123 ) ;
}
void * F_94 ( struct V_1 * V_2 , T_2 V_39 ,
struct V_36 * * V_123 )
{
F_2 ( F_6 () ) ;
return F_90 ( V_2 , V_39 , V_125 , V_123 ) ;
}
void * F_95 ( struct V_1 * V_2 , T_2 V_39 ,
struct V_36 * * V_123 )
{
F_2 ( F_6 () ) ;
return F_90 ( V_2 , V_39 , V_122 , V_123 ) ;
}
void F_96 ( struct V_1 * V_2 ,
T_2 V_39 , unsigned V_126 )
{
struct V_127 V_128 ;
F_2 ( F_6 () ) ;
F_97 ( & V_128 ) ;
F_4 ( V_2 ) ;
for (; V_126 -- ; V_39 ++ ) {
int V_117 ;
struct V_36 * V_37 ;
V_37 = F_88 ( V_2 , V_39 , V_103 , & V_117 ) ;
if ( F_55 ( V_37 != NULL ) ) {
F_9 ( V_2 ) ;
if ( V_117 )
F_52 ( V_37 , V_124 , V_37 -> V_39 , F_89 ) ;
F_91 ( V_37 ) ;
F_69 () ;
if ( ! V_126 )
goto V_129;
F_4 ( V_2 ) ;
}
}
F_9 ( V_2 ) ;
V_129:
F_98 ( & V_128 ) ;
}
void F_91 ( struct V_36 * V_37 )
{
struct V_1 * V_2 = V_37 -> V_2 ;
F_4 ( V_2 ) ;
F_2 ( ! V_37 -> V_92 ) ;
V_37 -> V_92 -- ;
if ( ! V_37 -> V_92 ) {
F_80 ( & V_2 -> V_96 ) ;
if ( ( V_37 -> V_121 || V_37 -> V_85 ) &&
! F_56 ( V_93 , & V_37 -> V_88 ) &&
! F_56 ( V_87 , & V_37 -> V_88 ) &&
! F_56 ( V_90 , & V_37 -> V_88 ) ) {
F_39 ( V_37 ) ;
F_79 ( V_37 ) ;
}
}
F_9 ( V_2 ) ;
}
void F_99 ( struct V_36 * V_37 )
{
struct V_1 * V_2 = V_37 -> V_2 ;
F_4 ( V_2 ) ;
F_2 ( F_56 ( V_93 , & V_37 -> V_88 ) ) ;
if ( ! F_100 ( V_90 , & V_37 -> V_88 ) )
F_42 ( V_37 , V_116 ) ;
F_9 ( V_2 ) ;
}
void F_101 ( struct V_1 * V_2 )
{
F_2 ( F_6 () ) ;
F_4 ( V_2 ) ;
F_81 ( V_2 , 0 ) ;
F_9 ( V_2 ) ;
}
int F_102 ( struct V_1 * V_2 )
{
int V_130 , V_131 ;
unsigned long V_132 = 0 ;
struct V_36 * V_37 , * V_109 ;
F_4 ( V_2 ) ;
F_81 ( V_2 , 0 ) ;
V_133:
F_82 (b, tmp, &c->lru[LIST_DIRTY], lru_list) {
int V_134 = 0 ;
if ( V_132 < V_2 -> V_41 [ V_116 ] )
V_132 ++ ;
F_2 ( F_56 ( V_93 , & V_37 -> V_88 ) ) ;
if ( F_56 ( V_87 , & V_37 -> V_88 ) ) {
if ( V_132 < V_2 -> V_41 [ V_116 ] ) {
V_134 = 1 ;
V_37 -> V_92 ++ ;
F_9 ( V_2 ) ;
F_66 ( & V_37 -> V_88 , V_87 ,
F_61 ,
V_91 ) ;
F_4 ( V_2 ) ;
V_37 -> V_92 -- ;
} else
F_66 ( & V_37 -> V_88 , V_87 ,
F_61 ,
V_91 ) ;
}
if ( ! F_56 ( V_90 , & V_37 -> V_88 ) &&
! F_56 ( V_87 , & V_37 -> V_88 ) )
F_42 ( V_37 , V_110 ) ;
F_69 () ;
if ( V_134 )
goto V_133;
}
F_80 ( & V_2 -> V_96 ) ;
F_9 ( V_2 ) ;
V_130 = F_103 ( & V_2 -> V_86 , 0 ) ;
V_131 = F_104 ( V_2 ) ;
if ( V_130 )
return V_130 ;
return V_131 ;
}
int F_104 ( struct V_1 * V_2 )
{
struct V_56 V_57 = {
. V_58 = V_135 ,
. V_70 . type = V_71 ,
. V_70 . V_25 . V_72 = NULL ,
. V_61 = V_2 -> V_62 ,
} ;
struct V_63 V_136 = {
. V_65 = V_2 -> V_65 ,
. V_66 = 0 ,
. V_68 = 0 ,
} ;
F_2 ( F_6 () ) ;
return V_62 ( & V_57 , 1 , & V_136 , NULL ) ;
}
void F_105 ( struct V_36 * V_37 , T_2 V_137 )
{
struct V_1 * V_2 = V_37 -> V_2 ;
struct V_36 * V_138 ;
F_2 ( F_6 () ) ;
F_4 ( V_2 ) ;
V_139:
V_138 = F_86 ( V_2 , V_137 ) ;
if ( V_138 ) {
if ( V_138 -> V_92 ) {
F_70 ( V_2 ) ;
goto V_139;
}
F_65 ( V_138 ) ;
F_39 ( V_138 ) ;
F_79 ( V_138 ) ;
}
F_2 ( ! V_37 -> V_92 ) ;
F_2 ( F_56 ( V_93 , & V_37 -> V_88 ) ) ;
F_63 ( V_37 ) ;
if ( V_37 -> V_92 == 1 ) {
F_66 ( & V_37 -> V_88 , V_87 ,
F_61 , V_91 ) ;
F_106 ( V_90 , & V_37 -> V_88 ) ;
F_39 ( V_37 ) ;
F_35 ( V_37 , V_137 , V_116 ) ;
} else {
T_2 V_140 ;
F_64 ( & V_37 -> V_88 , V_87 ,
F_61 , V_91 ) ;
V_140 = V_37 -> V_39 ;
F_39 ( V_37 ) ;
F_35 ( V_37 , V_137 , V_37 -> V_42 ) ;
F_52 ( V_37 , V_83 , V_137 , F_53 ) ;
F_66 ( & V_37 -> V_88 , V_87 ,
F_61 , V_91 ) ;
F_39 ( V_37 ) ;
F_35 ( V_37 , V_140 , V_37 -> V_42 ) ;
}
F_9 ( V_2 ) ;
F_91 ( V_37 ) ;
}
unsigned F_107 ( struct V_1 * V_2 )
{
return V_2 -> V_26 ;
}
T_2 F_108 ( struct V_1 * V_2 )
{
return F_109 ( V_2 -> V_65 -> V_141 ) >>
( V_69 + V_2 -> V_67 ) ;
}
T_2 F_110 ( struct V_36 * V_37 )
{
return V_37 -> V_39 ;
}
void * F_111 ( struct V_36 * V_37 )
{
return V_37 -> V_35 ;
}
void * F_112 ( struct V_36 * V_37 )
{
return V_37 + 1 ;
}
struct V_1 * F_113 ( struct V_36 * V_37 )
{
return V_37 -> V_2 ;
}
static void F_114 ( struct V_1 * V_2 )
{
struct V_36 * V_37 ;
int V_142 ;
F_2 ( F_6 () ) ;
F_101 ( V_2 ) ;
F_4 ( V_2 ) ;
while ( ( V_37 = F_67 ( V_2 ) ) )
F_79 ( V_37 ) ;
for ( V_142 = 0 ; V_142 < V_143 ; V_142 ++ )
F_115 (b, &c->lru[i], lru_list)
F_116 ( L_2 ,
( unsigned long long ) V_37 -> V_39 , V_37 -> V_92 , V_142 ) ;
for ( V_142 = 0 ; V_142 < V_143 ; V_142 ++ )
F_2 ( ! F_76 ( & V_2 -> V_44 [ V_142 ] ) ) ;
F_9 ( V_2 ) ;
}
static int F_117 ( struct V_36 * V_37 , T_1 V_144 ,
unsigned long V_145 )
{
if ( V_48 - V_37 -> V_47 < V_145 )
return 1 ;
if ( ! ( V_144 & V_146 ) ) {
if ( F_56 ( V_93 , & V_37 -> V_88 ) ||
F_56 ( V_87 , & V_37 -> V_88 ) ||
F_56 ( V_90 , & V_37 -> V_88 ) )
return 1 ;
}
if ( V_37 -> V_92 )
return 1 ;
F_65 ( V_37 ) ;
F_39 ( V_37 ) ;
F_79 ( V_37 ) ;
return 0 ;
}
static void F_118 ( struct V_1 * V_2 , unsigned long V_147 ,
struct V_148 * V_149 )
{
int V_150 ;
struct V_36 * V_37 , * V_109 ;
for ( V_150 = 0 ; V_150 < V_143 ; V_150 ++ ) {
F_82 (b, tmp, &c->lru[l], lru_list)
if ( ! F_117 ( V_37 , V_149 -> V_23 , 0 ) &&
! -- V_147 )
return;
F_69 () ;
}
}
static int F_119 ( struct V_151 * V_151 , struct V_148 * V_149 )
{
struct V_1 * V_2 =
F_54 ( V_151 , struct V_1 , V_151 ) ;
unsigned long V_55 ;
unsigned long V_147 = V_149 -> V_147 ;
if ( V_149 -> V_23 & V_146 )
F_4 ( V_2 ) ;
else if ( ! F_7 ( V_2 ) )
return ! V_147 ? 0 : - 1 ;
if ( V_147 )
F_118 ( V_2 , V_147 , V_149 ) ;
V_55 = V_2 -> V_41 [ V_110 ] + V_2 -> V_41 [ V_116 ] ;
if ( V_55 > V_152 )
V_55 = V_152 ;
F_9 ( V_2 ) ;
return V_55 ;
}
struct V_1 * F_120 ( struct V_153 * V_65 , unsigned V_26 ,
unsigned V_104 , unsigned V_38 ,
void (* V_107)( struct V_36 * ) ,
void (* V_84)( struct V_36 * ) )
{
int V_55 ;
struct V_1 * V_2 ;
unsigned V_142 ;
F_2 ( V_26 < 1 << V_69 ||
( V_26 & ( V_26 - 1 ) ) ) ;
V_2 = F_32 ( sizeof( * V_2 ) , V_154 ) ;
if ( ! V_2 ) {
V_55 = - V_155 ;
goto V_156;
}
V_2 -> V_46 = F_121 ( sizeof( struct V_157 ) << V_158 ) ;
if ( ! V_2 -> V_46 ) {
V_55 = - V_155 ;
goto V_159;
}
V_2 -> V_65 = V_65 ;
V_2 -> V_26 = V_26 ;
V_2 -> V_67 = F_122 ( V_26 ) - 1 - V_69 ;
V_2 -> V_32 = ( F_122 ( V_26 ) - 1 >= V_160 ) ?
F_122 ( V_26 ) - 1 - V_160 : 0 ;
V_2 -> V_4 = ( F_122 ( V_26 ) - 1 < V_160 ?
V_160 - ( F_122 ( V_26 ) - 1 ) : 0 ) ;
V_2 -> V_38 = V_38 ;
V_2 -> V_107 = V_107 ;
V_2 -> V_84 = V_84 ;
for ( V_142 = 0 ; V_142 < V_143 ; V_142 ++ ) {
F_123 ( & V_2 -> V_44 [ V_142 ] ) ;
V_2 -> V_41 [ V_142 ] = 0 ;
}
for ( V_142 = 0 ; V_142 < 1 << V_158 ; V_142 ++ )
F_124 ( & V_2 -> V_46 [ V_142 ] ) ;
F_125 ( & V_2 -> V_6 ) ;
F_123 ( & V_2 -> V_104 ) ;
V_2 -> V_106 = V_104 ;
F_126 ( & V_2 -> V_96 ) ;
V_2 -> V_86 = 0 ;
V_2 -> V_62 = F_127 () ;
if ( F_128 ( V_2 -> V_62 ) ) {
V_55 = F_129 ( V_2 -> V_62 ) ;
goto V_161;
}
F_84 ( & V_17 ) ;
if ( V_2 -> V_4 ) {
if ( ! F_130 ( V_2 ) ) {
F_130 ( V_2 ) = F_131 ( V_154 , L_3 , V_2 -> V_26 ) ;
if ( ! F_130 ( V_2 ) ) {
V_55 = - V_155 ;
F_10 ( & V_17 ) ;
goto V_162;
}
}
if ( ! F_20 ( V_2 ) ) {
F_20 ( V_2 ) = F_132 ( F_130 ( V_2 ) ,
V_2 -> V_26 ,
V_2 -> V_26 , 0 , NULL ) ;
if ( ! F_20 ( V_2 ) ) {
V_55 = - V_155 ;
F_10 ( & V_17 ) ;
goto V_162;
}
}
}
F_10 ( & V_17 ) ;
while ( V_2 -> V_106 ) {
struct V_36 * V_37 = F_31 ( V_2 , V_154 ) ;
if ( ! V_37 ) {
V_55 = - V_155 ;
goto V_163;
}
F_79 ( V_37 ) ;
}
F_84 ( & V_17 ) ;
V_18 ++ ;
F_36 ( & V_2 -> V_164 , & V_165 ) ;
F_14 () ;
F_10 ( & V_17 ) ;
V_2 -> V_151 . F_119 = F_119 ;
V_2 -> V_151 . V_166 = 1 ;
V_2 -> V_151 . V_167 = 0 ;
F_133 ( & V_2 -> V_151 ) ;
return V_2 ;
V_163:
V_162:
while ( ! F_76 ( & V_2 -> V_104 ) ) {
struct V_36 * V_37 = F_77 ( V_2 -> V_104 . V_105 ,
struct V_36 , V_43 ) ;
F_41 ( & V_37 -> V_43 ) ;
F_34 ( V_37 ) ;
}
F_134 ( V_2 -> V_62 ) ;
V_161:
F_28 ( V_2 -> V_46 ) ;
V_159:
F_33 ( V_2 ) ;
V_156:
return F_92 ( V_55 ) ;
}
void F_135 ( struct V_1 * V_2 )
{
unsigned V_142 ;
F_114 ( V_2 ) ;
F_136 ( & V_2 -> V_151 ) ;
F_84 ( & V_17 ) ;
F_41 ( & V_2 -> V_164 ) ;
V_18 -- ;
F_14 () ;
F_10 ( & V_17 ) ;
for ( V_142 = 0 ; V_142 < 1 << V_158 ; V_142 ++ )
F_2 ( ! F_137 ( & V_2 -> V_46 [ V_142 ] ) ) ;
F_2 ( V_2 -> V_106 ) ;
while ( ! F_76 ( & V_2 -> V_104 ) ) {
struct V_36 * V_37 = F_77 ( V_2 -> V_104 . V_105 ,
struct V_36 , V_43 ) ;
F_41 ( & V_37 -> V_43 ) ;
F_34 ( V_37 ) ;
}
for ( V_142 = 0 ; V_142 < V_143 ; V_142 ++ )
if ( V_2 -> V_41 [ V_142 ] )
F_116 ( L_4 , V_142 , V_2 -> V_41 [ V_142 ] ) ;
for ( V_142 = 0 ; V_142 < V_143 ; V_142 ++ )
F_2 ( V_2 -> V_41 [ V_142 ] ) ;
F_134 ( V_2 -> V_62 ) ;
F_28 ( V_2 -> V_46 ) ;
F_33 ( V_2 ) ;
}
static void F_138 ( void )
{
unsigned long V_168 = F_16 ( V_169 ) ;
struct V_1 * V_2 ;
if ( V_168 > V_170 / V_171 )
V_168 = V_170 / V_171 ;
F_84 ( & V_17 ) ;
F_115 (c, &dm_bufio_all_clients, client_list) {
if ( ! F_7 ( V_2 ) )
continue;
while ( ! F_76 ( & V_2 -> V_44 [ V_110 ] ) ) {
struct V_36 * V_37 ;
V_37 = F_77 ( V_2 -> V_44 [ V_110 ] . V_172 ,
struct V_36 , V_43 ) ;
if ( F_117 ( V_37 , 0 , V_168 * V_171 ) )
break;
F_69 () ;
}
F_9 ( V_2 ) ;
F_69 () ;
}
F_10 ( & V_17 ) ;
}
static void F_139 ( struct V_173 * V_174 )
{
F_138 () ;
F_140 ( V_175 , & V_176 ,
V_177 * V_171 ) ;
}
static int T_4 F_141 ( void )
{
T_5 V_70 ;
memset ( & V_5 , 0 , sizeof V_5 ) ;
memset ( & V_178 , 0 , sizeof V_178 ) ;
V_70 = ( T_5 ) ( ( V_179 - V_180 ) *
V_181 / 100 ) << V_160 ;
if ( V_70 > V_170 )
V_70 = V_170 ;
#ifdef F_142
if ( V_70 > ( V_182 - V_183 ) * V_184 / 100 )
V_70 = ( V_182 - V_183 ) * V_184 / 100 ;
#endif
V_21 = V_70 ;
F_84 ( & V_17 ) ;
F_14 () ;
F_10 ( & V_17 ) ;
V_175 = F_143 ( L_5 ) ;
if ( ! V_175 )
return - V_155 ;
F_144 ( & V_176 , F_139 ) ;
F_140 ( V_175 , & V_176 ,
V_177 * V_171 ) ;
return 0 ;
}
static void T_6 F_145 ( void )
{
int V_185 = 0 ;
int V_142 ;
F_146 ( & V_176 ) ;
F_147 ( V_175 ) ;
for ( V_142 = 0 ; V_142 < F_3 ( V_5 ) ; V_142 ++ ) {
struct V_186 * V_187 = V_5 [ V_142 ] ;
if ( V_187 )
F_148 ( V_187 ) ;
}
for ( V_142 = 0 ; V_142 < F_3 ( V_178 ) ; V_142 ++ )
F_33 ( V_178 [ V_142 ] ) ;
if ( V_18 ) {
F_29 ( L_6 ,
V_188 , V_18 ) ;
V_185 = 1 ;
}
if ( V_15 ) {
F_29 ( L_7 ,
V_188 , V_15 ) ;
V_185 = 1 ;
}
if ( V_12 ) {
F_29 ( L_8 ,
V_188 , V_12 ) ;
V_185 = 1 ;
}
if ( V_13 ) {
F_29 ( L_9 ,
V_188 , V_13 ) ;
V_185 = 1 ;
}
if ( V_185 )
F_30 () ;
}
