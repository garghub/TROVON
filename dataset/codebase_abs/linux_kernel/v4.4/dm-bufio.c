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
static struct V_7 * F_11 ( struct V_1 * V_2 , T_1 V_8 )
{
struct V_9 * V_10 = V_2 -> V_11 . V_9 ;
struct V_7 * V_12 ;
while ( V_10 ) {
V_12 = F_12 ( V_10 , struct V_7 , V_13 ) ;
if ( V_12 -> V_8 == V_8 )
return V_12 ;
V_10 = ( V_12 -> V_8 < V_8 ) ? V_10 -> V_14 : V_10 -> V_15 ;
}
return NULL ;
}
static void F_13 ( struct V_1 * V_2 , struct V_7 * V_12 )
{
struct V_9 * * V_16 = & V_2 -> V_11 . V_9 , * V_17 = NULL ;
struct V_7 * V_18 ;
while ( * V_16 ) {
V_18 = F_12 ( * V_16 , struct V_7 , V_13 ) ;
if ( V_18 -> V_8 == V_12 -> V_8 ) {
F_2 ( V_18 != V_12 ) ;
return;
}
V_17 = * V_16 ;
V_16 = ( V_18 -> V_8 < V_12 -> V_8 ) ?
& ( ( * V_16 ) -> V_14 ) : & ( ( * V_16 ) -> V_15 ) ;
}
F_14 ( & V_12 -> V_13 , V_17 , V_16 ) ;
F_15 ( & V_12 -> V_13 , & V_2 -> V_11 ) ;
}
static void F_16 ( struct V_1 * V_2 , struct V_7 * V_12 )
{
F_17 ( & V_12 -> V_13 , & V_2 -> V_11 ) ;
}
static void F_18 ( enum V_19 V_19 , long V_20 )
{
static unsigned long * const V_21 [ V_22 ] = {
& V_23 ,
& V_24 ,
& V_25 ,
} ;
F_19 ( & V_26 ) ;
* V_21 [ V_19 ] += V_20 ;
V_27 += V_20 ;
if ( V_27 > V_28 )
V_28 = V_27 ;
F_20 ( & V_26 ) ;
}
static void F_21 ( void )
{
F_2 ( ! F_22 ( & V_29 ) ) ;
F_2 ( V_30 < 0 ) ;
V_31 = F_23 ( V_32 ) ;
if ( ! V_31 ) {
( void ) F_24 ( & V_32 , 0 ,
V_33 ) ;
V_31 = V_33 ;
}
V_34 = V_31 /
( V_30 ? : 1 ) ;
}
static void * F_25 ( struct V_1 * V_2 , T_2 V_35 ,
enum V_19 * V_19 )
{
unsigned V_36 ;
void * V_37 ;
if ( V_2 -> V_38 <= V_39 ) {
* V_19 = V_40 ;
return F_26 ( F_27 ( V_2 ) , V_35 ) ;
}
if ( V_2 -> V_38 <= V_41 &&
V_35 & V_42 ) {
* V_19 = V_43 ;
return ( void * ) F_28 ( V_35 ,
V_2 -> V_44 ) ;
}
* V_19 = V_45 ;
if ( V_35 & V_42 )
V_36 = F_29 () ;
V_37 = F_30 ( V_2 -> V_38 , V_35 | V_46 , V_47 ) ;
if ( V_35 & V_42 )
F_31 ( V_36 ) ;
return V_37 ;
}
static void F_32 ( struct V_1 * V_2 ,
void * V_48 , enum V_19 V_19 )
{
switch ( V_19 ) {
case V_40 :
F_33 ( F_27 ( V_2 ) , V_48 ) ;
break;
case V_43 :
F_34 ( ( unsigned long ) V_48 , V_2 -> V_44 ) ;
break;
case V_45 :
F_35 ( V_48 ) ;
break;
default:
F_36 ( L_1 ,
V_19 ) ;
F_37 () ;
}
}
static struct V_7 * F_38 ( struct V_1 * V_2 , T_2 V_35 )
{
struct V_7 * V_12 = F_39 ( sizeof( struct V_7 ) + V_2 -> V_49 ,
V_35 ) ;
if ( ! V_12 )
return NULL ;
V_12 -> V_2 = V_2 ;
V_12 -> V_48 = F_25 ( V_2 , V_35 , & V_12 -> V_19 ) ;
if ( ! V_12 -> V_48 ) {
F_40 ( V_12 ) ;
return NULL ;
}
F_18 ( V_12 -> V_19 , ( long ) V_2 -> V_38 ) ;
return V_12 ;
}
static void F_41 ( struct V_7 * V_12 )
{
struct V_1 * V_2 = V_12 -> V_2 ;
F_18 ( V_12 -> V_19 , - ( long ) V_2 -> V_38 ) ;
F_32 ( V_2 , V_12 -> V_48 , V_12 -> V_19 ) ;
F_40 ( V_12 ) ;
}
static void F_42 ( struct V_7 * V_12 , T_1 V_8 , int V_50 )
{
struct V_1 * V_2 = V_12 -> V_2 ;
V_2 -> V_51 [ V_50 ] ++ ;
V_12 -> V_8 = V_8 ;
V_12 -> V_52 = V_50 ;
F_43 ( & V_12 -> V_53 , & V_2 -> V_54 [ V_50 ] ) ;
F_13 ( V_12 -> V_2 , V_12 ) ;
V_12 -> V_55 = V_56 ;
}
static void F_44 ( struct V_7 * V_12 )
{
struct V_1 * V_2 = V_12 -> V_2 ;
F_2 ( ! V_2 -> V_51 [ V_12 -> V_52 ] ) ;
V_2 -> V_51 [ V_12 -> V_52 ] -- ;
F_16 ( V_12 -> V_2 , V_12 ) ;
F_45 ( & V_12 -> V_53 ) ;
}
static void F_46 ( struct V_7 * V_12 , int V_50 )
{
struct V_1 * V_2 = V_12 -> V_2 ;
F_2 ( ! V_2 -> V_51 [ V_12 -> V_52 ] ) ;
V_2 -> V_51 [ V_12 -> V_52 ] -- ;
V_2 -> V_51 [ V_50 ] ++ ;
V_12 -> V_52 = V_50 ;
F_47 ( & V_12 -> V_53 , & V_2 -> V_54 [ V_50 ] ) ;
V_12 -> V_55 = V_56 ;
}
static void F_48 ( unsigned long error , void * V_57 )
{
struct V_7 * V_12 = V_57 ;
V_12 -> V_58 . V_59 = error ? - V_60 : 0 ;
V_12 -> V_58 . V_61 ( & V_12 -> V_58 ) ;
}
static void F_49 ( struct V_7 * V_12 , int V_62 , T_1 V_8 ,
T_3 * V_63 )
{
int V_64 ;
struct V_65 V_66 = {
. V_67 = V_62 ,
. V_68 . V_69 = F_48 ,
. V_68 . V_57 = V_12 ,
. V_70 = V_12 -> V_2 -> V_71 ,
} ;
struct V_72 V_73 = {
. V_74 = V_12 -> V_2 -> V_74 ,
. V_75 = V_8 << V_12 -> V_2 -> V_76 ,
. V_77 = V_12 -> V_2 -> V_38 >> V_78 ,
} ;
if ( V_12 -> V_19 != V_45 ) {
V_66 . V_79 . type = V_80 ;
V_66 . V_79 . V_37 . V_81 = V_12 -> V_48 ;
} else {
V_66 . V_79 . type = V_82 ;
V_66 . V_79 . V_37 . V_83 = V_12 -> V_48 ;
}
V_12 -> V_58 . V_61 = V_63 ;
V_64 = V_71 ( & V_66 , 1 , & V_73 , NULL ) ;
if ( V_64 ) {
V_12 -> V_58 . V_59 = V_64 ;
V_63 ( & V_12 -> V_58 ) ;
}
}
static void F_50 ( struct V_58 * V_58 )
{
T_3 * V_84 = V_58 -> V_85 ;
int error = V_58 -> V_59 ;
F_51 ( V_58 ) ;
V_58 -> V_59 = error ;
V_84 ( V_58 ) ;
}
static void F_52 ( struct V_7 * V_12 , int V_62 , T_1 V_8 ,
T_3 * V_63 )
{
char * V_37 ;
int V_86 ;
F_53 ( & V_12 -> V_58 ) ;
V_12 -> V_58 . V_87 = V_12 -> V_88 ;
V_12 -> V_58 . V_89 = V_90 ;
V_12 -> V_58 . V_91 . V_92 = V_8 << V_12 -> V_2 -> V_76 ;
V_12 -> V_58 . V_93 = V_12 -> V_2 -> V_74 ;
V_12 -> V_58 . V_61 = F_50 ;
V_12 -> V_58 . V_85 = V_63 ;
V_37 = V_12 -> V_48 ;
V_86 = V_12 -> V_2 -> V_38 ;
if ( V_86 >= V_94 )
F_2 ( ( unsigned long ) V_37 & ( V_94 - 1 ) ) ;
else
F_2 ( ( unsigned long ) V_37 & ( V_86 - 1 ) ) ;
do {
if ( ! F_54 ( & V_12 -> V_58 , F_55 ( V_37 ) ,
V_86 < V_94 ? V_86 : V_94 ,
F_56 ( V_37 ) & ( V_94 - 1 ) ) ) {
F_2 ( V_12 -> V_2 -> V_38 <= V_94 ) ;
F_49 ( V_12 , V_62 , V_8 , V_63 ) ;
return;
}
V_86 -= V_94 ;
V_37 += V_94 ;
} while ( V_86 > 0 );
F_57 ( V_62 , & V_12 -> V_58 ) ;
}
static void F_58 ( struct V_7 * V_12 , int V_62 , T_1 V_8 ,
T_3 * V_63 )
{
if ( V_62 == V_95 && V_12 -> V_2 -> V_96 )
V_12 -> V_2 -> V_96 ( V_12 ) ;
if ( V_12 -> V_2 -> V_38 <= V_90 * V_94 &&
V_12 -> V_19 != V_45 )
F_52 ( V_12 , V_62 , V_8 , V_63 ) ;
else
F_49 ( V_12 , V_62 , V_8 , V_63 ) ;
}
static void F_59 ( struct V_58 * V_58 )
{
struct V_7 * V_12 = F_12 ( V_58 , struct V_7 , V_58 ) ;
V_12 -> V_97 = V_58 -> V_59 ;
if ( F_60 ( V_58 -> V_59 ) ) {
struct V_1 * V_2 = V_12 -> V_2 ;
int error = V_58 -> V_59 ;
( void ) F_24 ( & V_2 -> V_98 , 0 , error ) ;
}
F_2 ( ! F_61 ( V_99 , & V_12 -> V_100 ) ) ;
F_62 () ;
F_63 ( V_99 , & V_12 -> V_100 ) ;
F_64 () ;
F_65 ( & V_12 -> V_100 , V_99 ) ;
}
static void F_66 ( struct V_7 * V_12 ,
struct V_101 * V_102 )
{
if ( ! F_61 ( V_103 , & V_12 -> V_100 ) )
return;
F_63 ( V_103 , & V_12 -> V_100 ) ;
F_67 ( & V_12 -> V_100 , V_99 , V_104 ) ;
if ( ! V_102 )
F_58 ( V_12 , V_95 , V_12 -> V_8 , F_59 ) ;
else
F_68 ( & V_12 -> V_102 , V_102 ) ;
}
static void F_69 ( struct V_101 * V_102 )
{
struct V_105 V_106 ;
F_70 ( & V_106 ) ;
while ( ! F_71 ( V_102 ) ) {
struct V_7 * V_12 =
F_72 ( V_102 -> V_107 , struct V_7 , V_102 ) ;
F_45 ( & V_12 -> V_102 ) ;
F_58 ( V_12 , V_95 , V_12 -> V_8 , F_59 ) ;
F_73 () ;
}
F_74 ( & V_106 ) ;
}
static void F_75 ( struct V_7 * V_12 )
{
F_2 ( V_12 -> V_108 ) ;
if ( ! V_12 -> V_100 )
return;
F_76 ( & V_12 -> V_100 , V_109 , V_104 ) ;
F_66 ( V_12 , NULL ) ;
F_76 ( & V_12 -> V_100 , V_99 , V_104 ) ;
}
static struct V_7 * F_77 ( struct V_1 * V_2 )
{
struct V_7 * V_12 ;
F_78 (b, &c->lru[LIST_CLEAN], lru_list) {
F_2 ( F_61 ( V_99 , & V_12 -> V_100 ) ) ;
F_2 ( F_61 ( V_103 , & V_12 -> V_100 ) ) ;
if ( ! V_12 -> V_108 ) {
F_75 ( V_12 ) ;
F_44 ( V_12 ) ;
return V_12 ;
}
F_73 () ;
}
F_78 (b, &c->lru[LIST_DIRTY], lru_list) {
F_2 ( F_61 ( V_109 , & V_12 -> V_100 ) ) ;
if ( ! V_12 -> V_108 ) {
F_75 ( V_12 ) ;
F_44 ( V_12 ) ;
return V_12 ;
}
F_73 () ;
}
return NULL ;
}
static void F_79 ( struct V_1 * V_2 )
{
F_80 ( V_110 , V_111 ) ;
F_81 ( & V_2 -> V_112 , & V_110 ) ;
F_82 ( V_111 , V_104 ) ;
F_9 ( V_2 ) ;
F_83 () ;
F_84 ( & V_2 -> V_112 , & V_110 ) ;
F_4 ( V_2 ) ;
}
static struct V_7 * F_85 ( struct V_1 * V_2 , enum V_113 V_114 )
{
struct V_7 * V_12 ;
while ( 1 ) {
if ( V_31 != 1 ) {
V_12 = F_38 ( V_2 , V_115 | V_42 | V_116 | V_117 ) ;
if ( V_12 )
return V_12 ;
}
if ( V_114 == V_118 )
return NULL ;
if ( ! F_71 ( & V_2 -> V_119 ) ) {
V_12 = F_72 ( V_2 -> V_119 . V_107 ,
struct V_7 , V_53 ) ;
F_45 ( & V_12 -> V_53 ) ;
V_2 -> V_120 ++ ;
return V_12 ;
}
V_12 = F_77 ( V_2 ) ;
if ( V_12 )
return V_12 ;
F_79 ( V_2 ) ;
}
}
static struct V_7 * F_86 ( struct V_1 * V_2 , enum V_113 V_114 )
{
struct V_7 * V_12 = F_85 ( V_2 , V_114 ) ;
if ( ! V_12 )
return NULL ;
if ( V_2 -> V_121 )
V_2 -> V_121 ( V_12 ) ;
return V_12 ;
}
static void F_87 ( struct V_7 * V_12 )
{
struct V_1 * V_2 = V_12 -> V_2 ;
if ( ! V_2 -> V_120 )
F_41 ( V_12 ) ;
else {
F_43 ( & V_12 -> V_53 , & V_2 -> V_119 ) ;
V_2 -> V_120 -- ;
}
F_88 ( & V_2 -> V_112 ) ;
}
static void F_89 ( struct V_1 * V_2 , int V_122 ,
struct V_101 * V_102 )
{
struct V_7 * V_12 , * V_123 ;
F_90 (b, tmp, &c->lru[LIST_DIRTY], lru_list) {
F_2 ( F_61 ( V_109 , & V_12 -> V_100 ) ) ;
if ( ! F_61 ( V_103 , & V_12 -> V_100 ) &&
! F_61 ( V_99 , & V_12 -> V_100 ) ) {
F_46 ( V_12 , V_124 ) ;
continue;
}
if ( V_122 && F_61 ( V_99 , & V_12 -> V_100 ) )
return;
F_66 ( V_12 , V_102 ) ;
F_73 () ;
}
}
static void F_91 ( struct V_1 * V_2 ,
unsigned long * V_125 ,
unsigned long * V_126 )
{
unsigned long V_127 ;
if ( F_23 ( V_32 ) != V_31 ) {
F_92 ( & V_29 ) ;
F_21 () ;
F_10 ( & V_29 ) ;
}
V_127 = V_34 >>
( V_2 -> V_76 + V_78 ) ;
if ( V_127 < V_2 -> V_128 )
V_127 = V_2 -> V_128 ;
* V_126 = V_127 ;
* V_125 = V_127 * V_129 / 100 ;
}
static void F_93 ( struct V_1 * V_2 ,
struct V_101 * V_102 )
{
unsigned long V_125 , V_126 ;
F_91 ( V_2 , & V_125 , & V_126 ) ;
while ( V_2 -> V_51 [ V_124 ] + V_2 -> V_51 [ V_130 ] >
V_126 ) {
struct V_7 * V_12 = F_77 ( V_2 ) ;
if ( ! V_12 )
return;
F_87 ( V_12 ) ;
F_73 () ;
}
if ( V_2 -> V_51 [ V_130 ] > V_125 )
F_89 ( V_2 , 1 , V_102 ) ;
}
static struct V_7 * F_94 ( struct V_1 * V_2 , T_1 V_8 ,
enum V_113 V_114 , int * V_131 ,
struct V_101 * V_102 )
{
struct V_7 * V_12 , * V_132 = NULL ;
* V_131 = 0 ;
V_12 = F_11 ( V_2 , V_8 ) ;
if ( V_12 )
goto V_133;
if ( V_114 == V_134 )
return NULL ;
V_132 = F_86 ( V_2 , V_114 ) ;
if ( ! V_132 )
return NULL ;
V_12 = F_11 ( V_2 , V_8 ) ;
if ( V_12 ) {
F_87 ( V_132 ) ;
goto V_133;
}
F_93 ( V_2 , V_102 ) ;
V_12 = V_132 ;
V_12 -> V_108 = 1 ;
V_12 -> V_135 = 0 ;
V_12 -> V_97 = 0 ;
F_42 ( V_12 , V_8 , V_124 ) ;
if ( V_114 == V_136 ) {
V_12 -> V_100 = 0 ;
return V_12 ;
}
V_12 -> V_100 = 1 << V_109 ;
* V_131 = 1 ;
return V_12 ;
V_133:
if ( V_114 == V_118 )
return NULL ;
if ( V_114 == V_134 && F_60 ( F_61 ( V_109 , & V_12 -> V_100 ) ) )
return NULL ;
V_12 -> V_108 ++ ;
F_46 ( V_12 , F_61 ( V_103 , & V_12 -> V_100 ) ||
F_61 ( V_99 , & V_12 -> V_100 ) ) ;
return V_12 ;
}
static void F_95 ( struct V_58 * V_58 )
{
struct V_7 * V_12 = F_12 ( V_58 , struct V_7 , V_58 ) ;
V_12 -> V_135 = V_58 -> V_59 ;
F_2 ( ! F_61 ( V_109 , & V_12 -> V_100 ) ) ;
F_62 () ;
F_63 ( V_109 , & V_12 -> V_100 ) ;
F_64 () ;
F_65 ( & V_12 -> V_100 , V_109 ) ;
}
static void * F_96 ( struct V_1 * V_2 , T_1 V_8 ,
enum V_113 V_114 , struct V_7 * * V_137 )
{
int V_131 ;
struct V_7 * V_12 ;
F_97 ( V_102 ) ;
F_4 ( V_2 ) ;
V_12 = F_94 ( V_2 , V_8 , V_114 , & V_131 , & V_102 ) ;
F_9 ( V_2 ) ;
F_69 ( & V_102 ) ;
if ( ! V_12 )
return V_12 ;
if ( V_131 )
F_58 ( V_12 , V_138 , V_12 -> V_8 , F_95 ) ;
F_76 ( & V_12 -> V_100 , V_109 , V_104 ) ;
if ( V_12 -> V_135 ) {
int error = V_12 -> V_135 ;
F_98 ( V_12 ) ;
return F_99 ( error ) ;
}
* V_137 = V_12 ;
return V_12 -> V_48 ;
}
void * F_100 ( struct V_1 * V_2 , T_1 V_8 ,
struct V_7 * * V_137 )
{
return F_96 ( V_2 , V_8 , V_134 , V_137 ) ;
}
void * F_101 ( struct V_1 * V_2 , T_1 V_8 ,
struct V_7 * * V_137 )
{
F_2 ( F_6 () ) ;
return F_96 ( V_2 , V_8 , V_139 , V_137 ) ;
}
void * F_102 ( struct V_1 * V_2 , T_1 V_8 ,
struct V_7 * * V_137 )
{
F_2 ( F_6 () ) ;
return F_96 ( V_2 , V_8 , V_136 , V_137 ) ;
}
void F_103 ( struct V_1 * V_2 ,
T_1 V_8 , unsigned V_140 )
{
struct V_105 V_106 ;
F_97 ( V_102 ) ;
F_2 ( F_6 () ) ;
F_70 ( & V_106 ) ;
F_4 ( V_2 ) ;
for (; V_140 -- ; V_8 ++ ) {
int V_131 ;
struct V_7 * V_12 ;
V_12 = F_94 ( V_2 , V_8 , V_118 , & V_131 ,
& V_102 ) ;
if ( F_60 ( ! F_71 ( & V_102 ) ) ) {
F_9 ( V_2 ) ;
F_74 ( & V_106 ) ;
F_69 ( & V_102 ) ;
F_70 ( & V_106 ) ;
F_4 ( V_2 ) ;
}
if ( F_60 ( V_12 != NULL ) ) {
F_9 ( V_2 ) ;
if ( V_131 )
F_58 ( V_12 , V_138 , V_12 -> V_8 , F_95 ) ;
F_98 ( V_12 ) ;
F_73 () ;
if ( ! V_140 )
goto V_141;
F_4 ( V_2 ) ;
}
}
F_9 ( V_2 ) ;
V_141:
F_74 ( & V_106 ) ;
}
void F_98 ( struct V_7 * V_12 )
{
struct V_1 * V_2 = V_12 -> V_2 ;
F_4 ( V_2 ) ;
F_2 ( ! V_12 -> V_108 ) ;
V_12 -> V_108 -- ;
if ( ! V_12 -> V_108 ) {
F_88 ( & V_2 -> V_112 ) ;
if ( ( V_12 -> V_135 || V_12 -> V_97 ) &&
! F_61 ( V_109 , & V_12 -> V_100 ) &&
! F_61 ( V_99 , & V_12 -> V_100 ) &&
! F_61 ( V_103 , & V_12 -> V_100 ) ) {
F_44 ( V_12 ) ;
F_87 ( V_12 ) ;
}
}
F_9 ( V_2 ) ;
}
void F_104 ( struct V_7 * V_12 )
{
struct V_1 * V_2 = V_12 -> V_2 ;
F_4 ( V_2 ) ;
F_2 ( F_61 ( V_109 , & V_12 -> V_100 ) ) ;
if ( ! F_105 ( V_103 , & V_12 -> V_100 ) )
F_46 ( V_12 , V_130 ) ;
F_9 ( V_2 ) ;
}
void F_106 ( struct V_1 * V_2 )
{
F_97 ( V_102 ) ;
F_2 ( F_6 () ) ;
F_4 ( V_2 ) ;
F_89 ( V_2 , 0 , & V_102 ) ;
F_9 ( V_2 ) ;
F_69 ( & V_102 ) ;
}
int F_107 ( struct V_1 * V_2 )
{
int V_142 , V_143 ;
unsigned long V_144 = 0 ;
struct V_7 * V_12 , * V_123 ;
F_97 ( V_102 ) ;
F_4 ( V_2 ) ;
F_89 ( V_2 , 0 , & V_102 ) ;
F_9 ( V_2 ) ;
F_69 ( & V_102 ) ;
F_4 ( V_2 ) ;
V_145:
F_90 (b, tmp, &c->lru[LIST_DIRTY], lru_list) {
int V_146 = 0 ;
if ( V_144 < V_2 -> V_51 [ V_130 ] )
V_144 ++ ;
F_2 ( F_61 ( V_109 , & V_12 -> V_100 ) ) ;
if ( F_61 ( V_99 , & V_12 -> V_100 ) ) {
if ( V_144 < V_2 -> V_51 [ V_130 ] ) {
V_146 = 1 ;
V_12 -> V_108 ++ ;
F_9 ( V_2 ) ;
F_76 ( & V_12 -> V_100 , V_99 ,
V_104 ) ;
F_4 ( V_2 ) ;
V_12 -> V_108 -- ;
} else
F_76 ( & V_12 -> V_100 , V_99 ,
V_104 ) ;
}
if ( ! F_61 ( V_103 , & V_12 -> V_100 ) &&
! F_61 ( V_99 , & V_12 -> V_100 ) )
F_46 ( V_12 , V_124 ) ;
F_73 () ;
if ( V_146 )
goto V_145;
}
F_88 ( & V_2 -> V_112 ) ;
F_9 ( V_2 ) ;
V_142 = F_108 ( & V_2 -> V_98 , 0 ) ;
V_143 = F_109 ( V_2 ) ;
if ( V_142 )
return V_142 ;
return V_143 ;
}
int F_109 ( struct V_1 * V_2 )
{
struct V_65 V_66 = {
. V_67 = V_147 ,
. V_79 . type = V_80 ,
. V_79 . V_37 . V_81 = NULL ,
. V_70 = V_2 -> V_71 ,
} ;
struct V_72 V_148 = {
. V_74 = V_2 -> V_74 ,
. V_75 = 0 ,
. V_77 = 0 ,
} ;
F_2 ( F_6 () ) ;
return V_71 ( & V_66 , 1 , & V_148 , NULL ) ;
}
void F_110 ( struct V_7 * V_12 , T_1 V_149 )
{
struct V_1 * V_2 = V_12 -> V_2 ;
struct V_7 * V_16 ;
F_2 ( F_6 () ) ;
F_4 ( V_2 ) ;
V_150:
V_16 = F_11 ( V_2 , V_149 ) ;
if ( V_16 ) {
if ( V_16 -> V_108 ) {
F_79 ( V_2 ) ;
goto V_150;
}
F_75 ( V_16 ) ;
F_44 ( V_16 ) ;
F_87 ( V_16 ) ;
}
F_2 ( ! V_12 -> V_108 ) ;
F_2 ( F_61 ( V_109 , & V_12 -> V_100 ) ) ;
F_66 ( V_12 , NULL ) ;
if ( V_12 -> V_108 == 1 ) {
F_76 ( & V_12 -> V_100 , V_99 ,
V_104 ) ;
F_111 ( V_103 , & V_12 -> V_100 ) ;
F_44 ( V_12 ) ;
F_42 ( V_12 , V_149 , V_130 ) ;
} else {
T_1 V_151 ;
F_67 ( & V_12 -> V_100 , V_99 ,
V_104 ) ;
V_151 = V_12 -> V_8 ;
F_44 ( V_12 ) ;
F_42 ( V_12 , V_149 , V_12 -> V_52 ) ;
F_58 ( V_12 , V_95 , V_149 , F_59 ) ;
F_76 ( & V_12 -> V_100 , V_99 ,
V_104 ) ;
F_44 ( V_12 ) ;
F_42 ( V_12 , V_151 , V_12 -> V_52 ) ;
}
F_9 ( V_2 ) ;
F_98 ( V_12 ) ;
}
void F_112 ( struct V_1 * V_2 , T_1 V_8 )
{
struct V_7 * V_12 ;
F_4 ( V_2 ) ;
V_12 = F_11 ( V_2 , V_8 ) ;
if ( V_12 && F_113 ( ! V_12 -> V_108 ) && F_113 ( ! V_12 -> V_100 ) ) {
F_44 ( V_12 ) ;
F_87 ( V_12 ) ;
}
F_9 ( V_2 ) ;
}
void F_114 ( struct V_1 * V_2 , unsigned V_10 )
{
V_2 -> V_128 = V_10 ;
}
unsigned F_115 ( struct V_1 * V_2 )
{
return V_2 -> V_38 ;
}
T_1 F_116 ( struct V_1 * V_2 )
{
return F_117 ( V_2 -> V_74 -> V_152 ) >>
( V_78 + V_2 -> V_76 ) ;
}
T_1 F_118 ( struct V_7 * V_12 )
{
return V_12 -> V_8 ;
}
void * F_119 ( struct V_7 * V_12 )
{
return V_12 -> V_48 ;
}
void * F_120 ( struct V_7 * V_12 )
{
return V_12 + 1 ;
}
struct V_1 * F_121 ( struct V_7 * V_12 )
{
return V_12 -> V_2 ;
}
static void F_122 ( struct V_1 * V_2 )
{
struct V_7 * V_12 ;
int V_153 ;
F_2 ( F_6 () ) ;
F_106 ( V_2 ) ;
F_4 ( V_2 ) ;
while ( ( V_12 = F_77 ( V_2 ) ) )
F_87 ( V_12 ) ;
for ( V_153 = 0 ; V_153 < V_154 ; V_153 ++ )
F_123 (b, &c->lru[i], lru_list)
F_124 ( L_2 ,
( unsigned long long ) V_12 -> V_8 , V_12 -> V_108 , V_153 ) ;
for ( V_153 = 0 ; V_153 < V_154 ; V_153 ++ )
F_2 ( ! F_71 ( & V_2 -> V_54 [ V_153 ] ) ) ;
F_9 ( V_2 ) ;
}
static bool F_125 ( struct V_7 * V_12 , T_2 V_155 )
{
if ( ! ( V_155 & V_156 ) ) {
if ( F_61 ( V_109 , & V_12 -> V_100 ) ||
F_61 ( V_99 , & V_12 -> V_100 ) ||
F_61 ( V_103 , & V_12 -> V_100 ) )
return false ;
}
if ( V_12 -> V_108 )
return false ;
F_75 ( V_12 ) ;
F_44 ( V_12 ) ;
F_87 ( V_12 ) ;
return true ;
}
static unsigned F_126 ( struct V_1 * V_2 )
{
unsigned V_157 = F_23 ( V_158 ) ;
return V_157 / V_2 -> V_38 ;
}
static unsigned long F_127 ( struct V_1 * V_2 , unsigned long V_159 ,
T_2 V_35 )
{
int V_160 ;
struct V_7 * V_12 , * V_123 ;
unsigned long V_161 = 0 ;
unsigned long V_77 = V_159 ;
unsigned V_162 = F_126 ( V_2 ) ;
for ( V_160 = 0 ; V_160 < V_154 ; V_160 ++ ) {
F_90 (b, tmp, &c->lru[l], lru_list) {
if ( F_125 ( V_12 , V_35 ) )
V_161 ++ ;
if ( ! -- V_159 || ( ( V_77 - V_161 ) <= V_162 ) )
return V_161 ;
F_73 () ;
}
}
return V_161 ;
}
static unsigned long
F_128 ( struct V_163 * V_164 , struct V_165 * V_166 )
{
struct V_1 * V_2 ;
unsigned long V_161 ;
V_2 = F_12 ( V_164 , struct V_1 , V_163 ) ;
if ( V_166 -> V_35 & V_156 )
F_4 ( V_2 ) ;
else if ( ! F_7 ( V_2 ) )
return V_167 ;
V_161 = F_127 ( V_2 , V_166 -> V_159 , V_166 -> V_35 ) ;
F_9 ( V_2 ) ;
return V_161 ;
}
static unsigned long
F_129 ( struct V_163 * V_164 , struct V_165 * V_166 )
{
struct V_1 * V_2 ;
unsigned long V_77 ;
V_2 = F_12 ( V_164 , struct V_1 , V_163 ) ;
if ( V_166 -> V_35 & V_156 )
F_4 ( V_2 ) ;
else if ( ! F_7 ( V_2 ) )
return 0 ;
V_77 = V_2 -> V_51 [ V_124 ] + V_2 -> V_51 [ V_130 ] ;
F_9 ( V_2 ) ;
return V_77 ;
}
struct V_1 * F_130 ( struct V_168 * V_74 , unsigned V_38 ,
unsigned V_119 , unsigned V_49 ,
void (* V_121)( struct V_7 * ) ,
void (* V_96)( struct V_7 * ) )
{
int V_64 ;
struct V_1 * V_2 ;
unsigned V_153 ;
F_2 ( V_38 < 1 << V_78 ||
( V_38 & ( V_38 - 1 ) ) ) ;
V_2 = F_131 ( sizeof( * V_2 ) , V_169 ) ;
if ( ! V_2 ) {
V_64 = - V_170 ;
goto V_171;
}
V_2 -> V_11 = V_172 ;
V_2 -> V_74 = V_74 ;
V_2 -> V_38 = V_38 ;
V_2 -> V_76 = F_132 ( V_38 ) - V_78 ;
V_2 -> V_44 = ( F_132 ( V_38 ) >= V_173 ) ?
F_132 ( V_38 ) - V_173 : 0 ;
V_2 -> V_4 = ( F_132 ( V_38 ) < V_173 ?
V_173 - F_132 ( V_38 ) : 0 ) ;
V_2 -> V_49 = V_49 ;
V_2 -> V_121 = V_121 ;
V_2 -> V_96 = V_96 ;
for ( V_153 = 0 ; V_153 < V_154 ; V_153 ++ ) {
F_133 ( & V_2 -> V_54 [ V_153 ] ) ;
V_2 -> V_51 [ V_153 ] = 0 ;
}
F_134 ( & V_2 -> V_6 ) ;
F_133 ( & V_2 -> V_119 ) ;
V_2 -> V_120 = V_119 ;
V_2 -> V_128 = V_174 ;
F_135 ( & V_2 -> V_112 ) ;
V_2 -> V_98 = 0 ;
V_2 -> V_71 = F_136 () ;
if ( F_137 ( V_2 -> V_71 ) ) {
V_64 = F_138 ( V_2 -> V_71 ) ;
goto V_175;
}
F_92 ( & V_29 ) ;
if ( V_2 -> V_4 ) {
if ( ! F_139 ( V_2 ) ) {
F_139 ( V_2 ) = F_140 ( V_169 , L_3 , V_2 -> V_38 ) ;
if ( ! F_139 ( V_2 ) ) {
V_64 = - V_170 ;
F_10 ( & V_29 ) ;
goto V_176;
}
}
if ( ! F_27 ( V_2 ) ) {
F_27 ( V_2 ) = F_141 ( F_139 ( V_2 ) ,
V_2 -> V_38 ,
V_2 -> V_38 , 0 , NULL ) ;
if ( ! F_27 ( V_2 ) ) {
V_64 = - V_170 ;
F_10 ( & V_29 ) ;
goto V_176;
}
}
}
F_10 ( & V_29 ) ;
while ( V_2 -> V_120 ) {
struct V_7 * V_12 = F_38 ( V_2 , V_169 ) ;
if ( ! V_12 ) {
V_64 = - V_170 ;
goto V_177;
}
F_87 ( V_12 ) ;
}
F_92 ( & V_29 ) ;
V_30 ++ ;
F_43 ( & V_2 -> V_178 , & V_179 ) ;
F_21 () ;
F_10 ( & V_29 ) ;
V_2 -> V_163 . V_180 = F_129 ;
V_2 -> V_163 . V_181 = F_128 ;
V_2 -> V_163 . V_182 = 1 ;
V_2 -> V_163 . V_183 = 0 ;
F_142 ( & V_2 -> V_163 ) ;
return V_2 ;
V_177:
V_176:
while ( ! F_71 ( & V_2 -> V_119 ) ) {
struct V_7 * V_12 = F_72 ( V_2 -> V_119 . V_107 ,
struct V_7 , V_53 ) ;
F_45 ( & V_12 -> V_53 ) ;
F_41 ( V_12 ) ;
}
F_143 ( V_2 -> V_71 ) ;
V_175:
F_40 ( V_2 ) ;
V_171:
return F_99 ( V_64 ) ;
}
void F_144 ( struct V_1 * V_2 )
{
unsigned V_153 ;
F_122 ( V_2 ) ;
F_145 ( & V_2 -> V_163 ) ;
F_92 ( & V_29 ) ;
F_45 ( & V_2 -> V_178 ) ;
V_30 -- ;
F_21 () ;
F_10 ( & V_29 ) ;
F_2 ( ! F_146 ( & V_2 -> V_11 ) ) ;
F_2 ( V_2 -> V_120 ) ;
while ( ! F_71 ( & V_2 -> V_119 ) ) {
struct V_7 * V_12 = F_72 ( V_2 -> V_119 . V_107 ,
struct V_7 , V_53 ) ;
F_45 ( & V_12 -> V_53 ) ;
F_41 ( V_12 ) ;
}
for ( V_153 = 0 ; V_153 < V_154 ; V_153 ++ )
if ( V_2 -> V_51 [ V_153 ] )
F_124 ( L_4 , V_153 , V_2 -> V_51 [ V_153 ] ) ;
for ( V_153 = 0 ; V_153 < V_154 ; V_153 ++ )
F_2 ( V_2 -> V_51 [ V_153 ] ) ;
F_143 ( V_2 -> V_71 ) ;
F_40 ( V_2 ) ;
}
static unsigned F_147 ( void )
{
unsigned V_184 = F_23 ( V_185 ) ;
if ( V_184 > V_186 / V_187 )
V_184 = V_186 / V_187 ;
return V_184 * V_187 ;
}
static bool F_148 ( struct V_7 * V_12 , unsigned long V_188 )
{
return F_149 ( V_56 , V_12 -> V_55 + V_188 ) ;
}
static void F_150 ( struct V_1 * V_2 , unsigned long V_188 )
{
struct V_7 * V_12 , * V_123 ;
unsigned V_162 = F_126 ( V_2 ) ;
unsigned V_77 ;
F_4 ( V_2 ) ;
V_77 = V_2 -> V_51 [ V_124 ] + V_2 -> V_51 [ V_130 ] ;
F_90 (b, tmp, &c->lru[LIST_CLEAN], lru_list) {
if ( V_77 <= V_162 )
break;
if ( ! F_148 ( V_12 , V_188 ) )
break;
if ( F_125 ( V_12 , 0 ) )
V_77 -- ;
F_73 () ;
}
F_9 ( V_2 ) ;
}
static void F_151 ( void )
{
unsigned long V_189 = F_147 () ;
struct V_1 * V_2 ;
F_92 ( & V_29 ) ;
F_123 (c, &dm_bufio_all_clients, client_list)
F_150 ( V_2 , V_189 ) ;
F_10 ( & V_29 ) ;
}
static void F_152 ( struct V_190 * V_191 )
{
F_151 () ;
F_153 ( V_192 , & V_193 ,
V_194 * V_187 ) ;
}
static int T_4 F_154 ( void )
{
T_5 V_79 ;
V_23 = 0 ;
V_24 = 0 ;
V_25 = 0 ;
V_27 = 0 ;
memset ( & V_5 , 0 , sizeof V_5 ) ;
memset ( & V_195 , 0 , sizeof V_195 ) ;
V_79 = ( T_5 ) ( ( V_196 - V_197 ) *
V_198 / 100 ) << V_173 ;
if ( V_79 > V_199 )
V_79 = V_199 ;
#ifdef F_155
if ( V_79 > ( V_200 - V_201 ) * V_202 / 100 )
V_79 = ( V_200 - V_201 ) * V_202 / 100 ;
#endif
V_33 = V_79 ;
F_92 ( & V_29 ) ;
F_21 () ;
F_10 ( & V_29 ) ;
V_192 = F_156 ( L_5 ) ;
if ( ! V_192 )
return - V_170 ;
F_157 ( & V_193 , F_152 ) ;
F_153 ( V_192 , & V_193 ,
V_194 * V_187 ) ;
return 0 ;
}
static void T_6 F_158 ( void )
{
int V_203 = 0 ;
int V_153 ;
F_159 ( & V_193 ) ;
F_160 ( V_192 ) ;
for ( V_153 = 0 ; V_153 < F_3 ( V_5 ) ; V_153 ++ )
F_161 ( V_5 [ V_153 ] ) ;
for ( V_153 = 0 ; V_153 < F_3 ( V_195 ) ; V_153 ++ )
F_40 ( V_195 [ V_153 ] ) ;
if ( V_30 ) {
F_36 ( L_6 ,
V_204 , V_30 ) ;
V_203 = 1 ;
}
if ( V_27 ) {
F_36 ( L_7 ,
V_204 , V_27 ) ;
V_203 = 1 ;
}
if ( V_24 ) {
F_36 ( L_8 ,
V_204 , V_24 ) ;
V_203 = 1 ;
}
if ( V_25 ) {
F_36 ( L_9 ,
V_204 , V_25 ) ;
V_203 = 1 ;
}
if ( V_203 )
F_37 () ;
}
