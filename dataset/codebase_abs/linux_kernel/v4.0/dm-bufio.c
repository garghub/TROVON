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
V_12 -> V_58 . V_59 ( & V_12 -> V_58 , error ? - V_60 : 0 ) ;
}
static void F_49 ( struct V_7 * V_12 , int V_61 , T_1 V_8 ,
T_3 * V_62 )
{
int V_63 ;
struct V_64 V_65 = {
. V_66 = V_61 ,
. V_67 . V_68 = F_48 ,
. V_67 . V_57 = V_12 ,
. V_69 = V_12 -> V_2 -> V_70 ,
} ;
struct V_71 V_72 = {
. V_73 = V_12 -> V_2 -> V_73 ,
. V_74 = V_8 << V_12 -> V_2 -> V_75 ,
. V_76 = V_12 -> V_2 -> V_38 >> V_77 ,
} ;
if ( V_12 -> V_19 != V_45 ) {
V_65 . V_78 . type = V_79 ;
V_65 . V_78 . V_37 . V_80 = V_12 -> V_48 ;
} else {
V_65 . V_78 . type = V_81 ;
V_65 . V_78 . V_37 . V_82 = V_12 -> V_48 ;
}
V_12 -> V_58 . V_59 = V_62 ;
V_63 = V_70 ( & V_65 , 1 , & V_72 , NULL ) ;
if ( V_63 )
V_62 ( & V_12 -> V_58 , V_63 ) ;
}
static void F_50 ( struct V_58 * V_58 , int error )
{
T_3 * V_83 = V_58 -> V_84 ;
F_51 ( V_58 ) ;
V_83 ( V_58 , error ) ;
}
static void F_52 ( struct V_7 * V_12 , int V_61 , T_1 V_8 ,
T_3 * V_62 )
{
char * V_37 ;
int V_85 ;
F_53 ( & V_12 -> V_58 ) ;
V_12 -> V_58 . V_86 = V_12 -> V_87 ;
V_12 -> V_58 . V_88 = V_89 ;
V_12 -> V_58 . V_90 . V_91 = V_8 << V_12 -> V_2 -> V_75 ;
V_12 -> V_58 . V_92 = V_12 -> V_2 -> V_73 ;
V_12 -> V_58 . V_59 = F_50 ;
V_12 -> V_58 . V_84 = V_62 ;
V_37 = V_12 -> V_48 ;
V_85 = V_12 -> V_2 -> V_38 ;
if ( V_85 >= V_93 )
F_2 ( ( unsigned long ) V_37 & ( V_93 - 1 ) ) ;
else
F_2 ( ( unsigned long ) V_37 & ( V_85 - 1 ) ) ;
do {
if ( ! F_54 ( & V_12 -> V_58 , F_55 ( V_37 ) ,
V_85 < V_93 ? V_85 : V_93 ,
F_56 ( V_37 ) & ( V_93 - 1 ) ) ) {
F_2 ( V_12 -> V_2 -> V_38 <= V_93 ) ;
F_49 ( V_12 , V_61 , V_8 , V_62 ) ;
return;
}
V_85 -= V_93 ;
V_37 += V_93 ;
} while ( V_85 > 0 );
F_57 ( V_61 , & V_12 -> V_58 ) ;
}
static void F_58 ( struct V_7 * V_12 , int V_61 , T_1 V_8 ,
T_3 * V_62 )
{
if ( V_61 == V_94 && V_12 -> V_2 -> V_95 )
V_12 -> V_2 -> V_95 ( V_12 ) ;
if ( V_12 -> V_2 -> V_38 <= V_89 * V_93 &&
V_12 -> V_19 != V_45 )
F_52 ( V_12 , V_61 , V_8 , V_62 ) ;
else
F_49 ( V_12 , V_61 , V_8 , V_62 ) ;
}
static void F_59 ( struct V_58 * V_58 , int error )
{
struct V_7 * V_12 = F_12 ( V_58 , struct V_7 , V_58 ) ;
V_12 -> V_96 = error ;
if ( F_60 ( error ) ) {
struct V_1 * V_2 = V_12 -> V_2 ;
( void ) F_24 ( & V_2 -> V_97 , 0 , error ) ;
}
F_2 ( ! F_61 ( V_98 , & V_12 -> V_99 ) ) ;
F_62 () ;
F_63 ( V_98 , & V_12 -> V_99 ) ;
F_64 () ;
F_65 ( & V_12 -> V_99 , V_98 ) ;
}
static void F_66 ( struct V_7 * V_12 ,
struct V_100 * V_101 )
{
if ( ! F_61 ( V_102 , & V_12 -> V_99 ) )
return;
F_63 ( V_102 , & V_12 -> V_99 ) ;
F_67 ( & V_12 -> V_99 , V_98 , V_103 ) ;
if ( ! V_101 )
F_58 ( V_12 , V_94 , V_12 -> V_8 , F_59 ) ;
else
F_68 ( & V_12 -> V_101 , V_101 ) ;
}
static void F_69 ( struct V_100 * V_101 )
{
struct V_104 V_105 ;
F_70 ( & V_105 ) ;
while ( ! F_71 ( V_101 ) ) {
struct V_7 * V_12 =
F_72 ( V_101 -> V_106 , struct V_7 , V_101 ) ;
F_45 ( & V_12 -> V_101 ) ;
F_58 ( V_12 , V_94 , V_12 -> V_8 , F_59 ) ;
F_73 () ;
}
F_74 ( & V_105 ) ;
}
static void F_75 ( struct V_7 * V_12 )
{
F_2 ( V_12 -> V_107 ) ;
if ( ! V_12 -> V_99 )
return;
F_76 ( & V_12 -> V_99 , V_108 , V_103 ) ;
F_66 ( V_12 , NULL ) ;
F_76 ( & V_12 -> V_99 , V_98 , V_103 ) ;
}
static struct V_7 * F_77 ( struct V_1 * V_2 )
{
struct V_7 * V_12 ;
F_78 (b, &c->lru[LIST_CLEAN], lru_list) {
F_2 ( F_61 ( V_98 , & V_12 -> V_99 ) ) ;
F_2 ( F_61 ( V_102 , & V_12 -> V_99 ) ) ;
if ( ! V_12 -> V_107 ) {
F_75 ( V_12 ) ;
F_44 ( V_12 ) ;
return V_12 ;
}
F_73 () ;
}
F_78 (b, &c->lru[LIST_DIRTY], lru_list) {
F_2 ( F_61 ( V_108 , & V_12 -> V_99 ) ) ;
if ( ! V_12 -> V_107 ) {
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
F_80 ( V_109 , V_110 ) ;
F_81 ( & V_2 -> V_111 , & V_109 ) ;
F_82 ( V_110 , V_103 ) ;
F_9 ( V_2 ) ;
F_83 () ;
F_84 ( & V_2 -> V_111 , & V_109 ) ;
F_4 ( V_2 ) ;
}
static struct V_7 * F_85 ( struct V_1 * V_2 , enum V_112 V_113 )
{
struct V_7 * V_12 ;
while ( 1 ) {
if ( V_31 != 1 ) {
V_12 = F_38 ( V_2 , V_114 | V_42 | V_115 | V_116 ) ;
if ( V_12 )
return V_12 ;
}
if ( V_113 == V_117 )
return NULL ;
if ( ! F_71 ( & V_2 -> V_118 ) ) {
V_12 = F_72 ( V_2 -> V_118 . V_106 ,
struct V_7 , V_53 ) ;
F_45 ( & V_12 -> V_53 ) ;
V_2 -> V_119 ++ ;
return V_12 ;
}
V_12 = F_77 ( V_2 ) ;
if ( V_12 )
return V_12 ;
F_79 ( V_2 ) ;
}
}
static struct V_7 * F_86 ( struct V_1 * V_2 , enum V_112 V_113 )
{
struct V_7 * V_12 = F_85 ( V_2 , V_113 ) ;
if ( ! V_12 )
return NULL ;
if ( V_2 -> V_120 )
V_2 -> V_120 ( V_12 ) ;
return V_12 ;
}
static void F_87 ( struct V_7 * V_12 )
{
struct V_1 * V_2 = V_12 -> V_2 ;
if ( ! V_2 -> V_119 )
F_41 ( V_12 ) ;
else {
F_43 ( & V_12 -> V_53 , & V_2 -> V_118 ) ;
V_2 -> V_119 -- ;
}
F_88 ( & V_2 -> V_111 ) ;
}
static void F_89 ( struct V_1 * V_2 , int V_121 ,
struct V_100 * V_101 )
{
struct V_7 * V_12 , * V_122 ;
F_90 (b, tmp, &c->lru[LIST_DIRTY], lru_list) {
F_2 ( F_61 ( V_108 , & V_12 -> V_99 ) ) ;
if ( ! F_61 ( V_102 , & V_12 -> V_99 ) &&
! F_61 ( V_98 , & V_12 -> V_99 ) ) {
F_46 ( V_12 , V_123 ) ;
continue;
}
if ( V_121 && F_61 ( V_98 , & V_12 -> V_99 ) )
return;
F_66 ( V_12 , V_101 ) ;
F_73 () ;
}
}
static void F_91 ( struct V_1 * V_2 ,
unsigned long * V_124 ,
unsigned long * V_125 )
{
unsigned long V_126 ;
if ( F_23 ( V_32 ) != V_31 ) {
F_92 ( & V_29 ) ;
F_21 () ;
F_10 ( & V_29 ) ;
}
V_126 = V_34 >>
( V_2 -> V_75 + V_77 ) ;
if ( V_126 < V_2 -> V_127 )
V_126 = V_2 -> V_127 ;
* V_125 = V_126 ;
* V_124 = V_126 * V_128 / 100 ;
}
static void F_93 ( struct V_1 * V_2 ,
struct V_100 * V_101 )
{
unsigned long V_124 , V_125 ;
F_91 ( V_2 , & V_124 , & V_125 ) ;
while ( V_2 -> V_51 [ V_123 ] + V_2 -> V_51 [ V_129 ] >
V_125 ) {
struct V_7 * V_12 = F_77 ( V_2 ) ;
if ( ! V_12 )
return;
F_87 ( V_12 ) ;
F_73 () ;
}
if ( V_2 -> V_51 [ V_129 ] > V_124 )
F_89 ( V_2 , 1 , V_101 ) ;
}
static struct V_7 * F_94 ( struct V_1 * V_2 , T_1 V_8 ,
enum V_112 V_113 , int * V_130 ,
struct V_100 * V_101 )
{
struct V_7 * V_12 , * V_131 = NULL ;
* V_130 = 0 ;
V_12 = F_11 ( V_2 , V_8 ) ;
if ( V_12 )
goto V_132;
if ( V_113 == V_133 )
return NULL ;
V_131 = F_86 ( V_2 , V_113 ) ;
if ( ! V_131 )
return NULL ;
V_12 = F_11 ( V_2 , V_8 ) ;
if ( V_12 ) {
F_87 ( V_131 ) ;
goto V_132;
}
F_93 ( V_2 , V_101 ) ;
V_12 = V_131 ;
V_12 -> V_107 = 1 ;
V_12 -> V_134 = 0 ;
V_12 -> V_96 = 0 ;
F_42 ( V_12 , V_8 , V_123 ) ;
if ( V_113 == V_135 ) {
V_12 -> V_99 = 0 ;
return V_12 ;
}
V_12 -> V_99 = 1 << V_108 ;
* V_130 = 1 ;
return V_12 ;
V_132:
if ( V_113 == V_117 )
return NULL ;
if ( V_113 == V_133 && F_60 ( F_61 ( V_108 , & V_12 -> V_99 ) ) )
return NULL ;
V_12 -> V_107 ++ ;
F_46 ( V_12 , F_61 ( V_102 , & V_12 -> V_99 ) ||
F_61 ( V_98 , & V_12 -> V_99 ) ) ;
return V_12 ;
}
static void F_95 ( struct V_58 * V_58 , int error )
{
struct V_7 * V_12 = F_12 ( V_58 , struct V_7 , V_58 ) ;
V_12 -> V_134 = error ;
F_2 ( ! F_61 ( V_108 , & V_12 -> V_99 ) ) ;
F_62 () ;
F_63 ( V_108 , & V_12 -> V_99 ) ;
F_64 () ;
F_65 ( & V_12 -> V_99 , V_108 ) ;
}
static void * F_96 ( struct V_1 * V_2 , T_1 V_8 ,
enum V_112 V_113 , struct V_7 * * V_136 )
{
int V_130 ;
struct V_7 * V_12 ;
F_97 ( V_101 ) ;
F_4 ( V_2 ) ;
V_12 = F_94 ( V_2 , V_8 , V_113 , & V_130 , & V_101 ) ;
F_9 ( V_2 ) ;
F_69 ( & V_101 ) ;
if ( ! V_12 )
return V_12 ;
if ( V_130 )
F_58 ( V_12 , V_137 , V_12 -> V_8 , F_95 ) ;
F_76 ( & V_12 -> V_99 , V_108 , V_103 ) ;
if ( V_12 -> V_134 ) {
int error = V_12 -> V_134 ;
F_98 ( V_12 ) ;
return F_99 ( error ) ;
}
* V_136 = V_12 ;
return V_12 -> V_48 ;
}
void * F_100 ( struct V_1 * V_2 , T_1 V_8 ,
struct V_7 * * V_136 )
{
return F_96 ( V_2 , V_8 , V_133 , V_136 ) ;
}
void * F_101 ( struct V_1 * V_2 , T_1 V_8 ,
struct V_7 * * V_136 )
{
F_2 ( F_6 () ) ;
return F_96 ( V_2 , V_8 , V_138 , V_136 ) ;
}
void * F_102 ( struct V_1 * V_2 , T_1 V_8 ,
struct V_7 * * V_136 )
{
F_2 ( F_6 () ) ;
return F_96 ( V_2 , V_8 , V_135 , V_136 ) ;
}
void F_103 ( struct V_1 * V_2 ,
T_1 V_8 , unsigned V_139 )
{
struct V_104 V_105 ;
F_97 ( V_101 ) ;
F_2 ( F_6 () ) ;
F_70 ( & V_105 ) ;
F_4 ( V_2 ) ;
for (; V_139 -- ; V_8 ++ ) {
int V_130 ;
struct V_7 * V_12 ;
V_12 = F_94 ( V_2 , V_8 , V_117 , & V_130 ,
& V_101 ) ;
if ( F_60 ( ! F_71 ( & V_101 ) ) ) {
F_9 ( V_2 ) ;
F_74 ( & V_105 ) ;
F_69 ( & V_101 ) ;
F_70 ( & V_105 ) ;
F_4 ( V_2 ) ;
}
if ( F_60 ( V_12 != NULL ) ) {
F_9 ( V_2 ) ;
if ( V_130 )
F_58 ( V_12 , V_137 , V_12 -> V_8 , F_95 ) ;
F_98 ( V_12 ) ;
F_73 () ;
if ( ! V_139 )
goto V_140;
F_4 ( V_2 ) ;
}
}
F_9 ( V_2 ) ;
V_140:
F_74 ( & V_105 ) ;
}
void F_98 ( struct V_7 * V_12 )
{
struct V_1 * V_2 = V_12 -> V_2 ;
F_4 ( V_2 ) ;
F_2 ( ! V_12 -> V_107 ) ;
V_12 -> V_107 -- ;
if ( ! V_12 -> V_107 ) {
F_88 ( & V_2 -> V_111 ) ;
if ( ( V_12 -> V_134 || V_12 -> V_96 ) &&
! F_61 ( V_108 , & V_12 -> V_99 ) &&
! F_61 ( V_98 , & V_12 -> V_99 ) &&
! F_61 ( V_102 , & V_12 -> V_99 ) ) {
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
F_2 ( F_61 ( V_108 , & V_12 -> V_99 ) ) ;
if ( ! F_105 ( V_102 , & V_12 -> V_99 ) )
F_46 ( V_12 , V_129 ) ;
F_9 ( V_2 ) ;
}
void F_106 ( struct V_1 * V_2 )
{
F_97 ( V_101 ) ;
F_2 ( F_6 () ) ;
F_4 ( V_2 ) ;
F_89 ( V_2 , 0 , & V_101 ) ;
F_9 ( V_2 ) ;
F_69 ( & V_101 ) ;
}
int F_107 ( struct V_1 * V_2 )
{
int V_141 , V_142 ;
unsigned long V_143 = 0 ;
struct V_7 * V_12 , * V_122 ;
F_97 ( V_101 ) ;
F_4 ( V_2 ) ;
F_89 ( V_2 , 0 , & V_101 ) ;
F_9 ( V_2 ) ;
F_69 ( & V_101 ) ;
F_4 ( V_2 ) ;
V_144:
F_90 (b, tmp, &c->lru[LIST_DIRTY], lru_list) {
int V_145 = 0 ;
if ( V_143 < V_2 -> V_51 [ V_129 ] )
V_143 ++ ;
F_2 ( F_61 ( V_108 , & V_12 -> V_99 ) ) ;
if ( F_61 ( V_98 , & V_12 -> V_99 ) ) {
if ( V_143 < V_2 -> V_51 [ V_129 ] ) {
V_145 = 1 ;
V_12 -> V_107 ++ ;
F_9 ( V_2 ) ;
F_76 ( & V_12 -> V_99 , V_98 ,
V_103 ) ;
F_4 ( V_2 ) ;
V_12 -> V_107 -- ;
} else
F_76 ( & V_12 -> V_99 , V_98 ,
V_103 ) ;
}
if ( ! F_61 ( V_102 , & V_12 -> V_99 ) &&
! F_61 ( V_98 , & V_12 -> V_99 ) )
F_46 ( V_12 , V_123 ) ;
F_73 () ;
if ( V_145 )
goto V_144;
}
F_88 ( & V_2 -> V_111 ) ;
F_9 ( V_2 ) ;
V_141 = F_108 ( & V_2 -> V_97 , 0 ) ;
V_142 = F_109 ( V_2 ) ;
if ( V_141 )
return V_141 ;
return V_142 ;
}
int F_109 ( struct V_1 * V_2 )
{
struct V_64 V_65 = {
. V_66 = V_146 ,
. V_78 . type = V_79 ,
. V_78 . V_37 . V_80 = NULL ,
. V_69 = V_2 -> V_70 ,
} ;
struct V_71 V_147 = {
. V_73 = V_2 -> V_73 ,
. V_74 = 0 ,
. V_76 = 0 ,
} ;
F_2 ( F_6 () ) ;
return V_70 ( & V_65 , 1 , & V_147 , NULL ) ;
}
void F_110 ( struct V_7 * V_12 , T_1 V_148 )
{
struct V_1 * V_2 = V_12 -> V_2 ;
struct V_7 * V_16 ;
F_2 ( F_6 () ) ;
F_4 ( V_2 ) ;
V_149:
V_16 = F_11 ( V_2 , V_148 ) ;
if ( V_16 ) {
if ( V_16 -> V_107 ) {
F_79 ( V_2 ) ;
goto V_149;
}
F_75 ( V_16 ) ;
F_44 ( V_16 ) ;
F_87 ( V_16 ) ;
}
F_2 ( ! V_12 -> V_107 ) ;
F_2 ( F_61 ( V_108 , & V_12 -> V_99 ) ) ;
F_66 ( V_12 , NULL ) ;
if ( V_12 -> V_107 == 1 ) {
F_76 ( & V_12 -> V_99 , V_98 ,
V_103 ) ;
F_111 ( V_102 , & V_12 -> V_99 ) ;
F_44 ( V_12 ) ;
F_42 ( V_12 , V_148 , V_129 ) ;
} else {
T_1 V_150 ;
F_67 ( & V_12 -> V_99 , V_98 ,
V_103 ) ;
V_150 = V_12 -> V_8 ;
F_44 ( V_12 ) ;
F_42 ( V_12 , V_148 , V_12 -> V_52 ) ;
F_58 ( V_12 , V_94 , V_148 , F_59 ) ;
F_76 ( & V_12 -> V_99 , V_98 ,
V_103 ) ;
F_44 ( V_12 ) ;
F_42 ( V_12 , V_150 , V_12 -> V_52 ) ;
}
F_9 ( V_2 ) ;
F_98 ( V_12 ) ;
}
void F_112 ( struct V_1 * V_2 , T_1 V_8 )
{
struct V_7 * V_12 ;
F_4 ( V_2 ) ;
V_12 = F_11 ( V_2 , V_8 ) ;
if ( V_12 && F_113 ( ! V_12 -> V_107 ) && F_113 ( ! V_12 -> V_99 ) ) {
F_44 ( V_12 ) ;
F_87 ( V_12 ) ;
}
F_9 ( V_2 ) ;
}
void F_114 ( struct V_1 * V_2 , unsigned V_10 )
{
V_2 -> V_127 = V_10 ;
}
unsigned F_115 ( struct V_1 * V_2 )
{
return V_2 -> V_38 ;
}
T_1 F_116 ( struct V_1 * V_2 )
{
return F_117 ( V_2 -> V_73 -> V_151 ) >>
( V_77 + V_2 -> V_75 ) ;
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
int V_152 ;
F_2 ( F_6 () ) ;
F_106 ( V_2 ) ;
F_4 ( V_2 ) ;
while ( ( V_12 = F_77 ( V_2 ) ) )
F_87 ( V_12 ) ;
for ( V_152 = 0 ; V_152 < V_153 ; V_152 ++ )
F_123 (b, &c->lru[i], lru_list)
F_124 ( L_2 ,
( unsigned long long ) V_12 -> V_8 , V_12 -> V_107 , V_152 ) ;
for ( V_152 = 0 ; V_152 < V_153 ; V_152 ++ )
F_2 ( ! F_71 ( & V_2 -> V_54 [ V_152 ] ) ) ;
F_9 ( V_2 ) ;
}
static bool F_125 ( struct V_7 * V_12 , T_2 V_154 )
{
if ( ! ( V_154 & V_155 ) ) {
if ( F_61 ( V_108 , & V_12 -> V_99 ) ||
F_61 ( V_98 , & V_12 -> V_99 ) ||
F_61 ( V_102 , & V_12 -> V_99 ) )
return false ;
}
if ( V_12 -> V_107 )
return false ;
F_75 ( V_12 ) ;
F_44 ( V_12 ) ;
F_87 ( V_12 ) ;
return true ;
}
static unsigned F_126 ( struct V_1 * V_2 )
{
unsigned V_156 = F_23 ( V_157 ) ;
return V_156 / V_2 -> V_38 ;
}
static unsigned long F_127 ( struct V_1 * V_2 , unsigned long V_158 ,
T_2 V_35 )
{
int V_159 ;
struct V_7 * V_12 , * V_122 ;
unsigned long V_160 = 0 ;
unsigned long V_76 = V_158 ;
unsigned V_161 = F_126 ( V_2 ) ;
for ( V_159 = 0 ; V_159 < V_153 ; V_159 ++ ) {
F_90 (b, tmp, &c->lru[l], lru_list) {
if ( F_125 ( V_12 , V_35 ) )
V_160 ++ ;
if ( ! -- V_158 || ( ( V_76 - V_160 ) <= V_161 ) )
return V_160 ;
F_73 () ;
}
}
return V_160 ;
}
static unsigned long
F_128 ( struct V_162 * V_163 , struct V_164 * V_165 )
{
struct V_1 * V_2 ;
unsigned long V_160 ;
V_2 = F_12 ( V_163 , struct V_1 , V_162 ) ;
if ( V_165 -> V_35 & V_155 )
F_4 ( V_2 ) ;
else if ( ! F_7 ( V_2 ) )
return V_166 ;
V_160 = F_127 ( V_2 , V_165 -> V_158 , V_165 -> V_35 ) ;
F_9 ( V_2 ) ;
return V_160 ;
}
static unsigned long
F_129 ( struct V_162 * V_163 , struct V_164 * V_165 )
{
struct V_1 * V_2 ;
unsigned long V_76 ;
V_2 = F_12 ( V_163 , struct V_1 , V_162 ) ;
if ( V_165 -> V_35 & V_155 )
F_4 ( V_2 ) ;
else if ( ! F_7 ( V_2 ) )
return 0 ;
V_76 = V_2 -> V_51 [ V_123 ] + V_2 -> V_51 [ V_129 ] ;
F_9 ( V_2 ) ;
return V_76 ;
}
struct V_1 * F_130 ( struct V_167 * V_73 , unsigned V_38 ,
unsigned V_118 , unsigned V_49 ,
void (* V_120)( struct V_7 * ) ,
void (* V_95)( struct V_7 * ) )
{
int V_63 ;
struct V_1 * V_2 ;
unsigned V_152 ;
F_2 ( V_38 < 1 << V_77 ||
( V_38 & ( V_38 - 1 ) ) ) ;
V_2 = F_131 ( sizeof( * V_2 ) , V_168 ) ;
if ( ! V_2 ) {
V_63 = - V_169 ;
goto V_170;
}
V_2 -> V_11 = V_171 ;
V_2 -> V_73 = V_73 ;
V_2 -> V_38 = V_38 ;
V_2 -> V_75 = F_132 ( V_38 ) - 1 - V_77 ;
V_2 -> V_44 = ( F_132 ( V_38 ) - 1 >= V_172 ) ?
F_132 ( V_38 ) - 1 - V_172 : 0 ;
V_2 -> V_4 = ( F_132 ( V_38 ) - 1 < V_172 ?
V_172 - ( F_132 ( V_38 ) - 1 ) : 0 ) ;
V_2 -> V_49 = V_49 ;
V_2 -> V_120 = V_120 ;
V_2 -> V_95 = V_95 ;
for ( V_152 = 0 ; V_152 < V_153 ; V_152 ++ ) {
F_133 ( & V_2 -> V_54 [ V_152 ] ) ;
V_2 -> V_51 [ V_152 ] = 0 ;
}
F_134 ( & V_2 -> V_6 ) ;
F_133 ( & V_2 -> V_118 ) ;
V_2 -> V_119 = V_118 ;
V_2 -> V_127 = V_173 ;
F_135 ( & V_2 -> V_111 ) ;
V_2 -> V_97 = 0 ;
V_2 -> V_70 = F_136 () ;
if ( F_137 ( V_2 -> V_70 ) ) {
V_63 = F_138 ( V_2 -> V_70 ) ;
goto V_174;
}
F_92 ( & V_29 ) ;
if ( V_2 -> V_4 ) {
if ( ! F_139 ( V_2 ) ) {
F_139 ( V_2 ) = F_140 ( V_168 , L_3 , V_2 -> V_38 ) ;
if ( ! F_139 ( V_2 ) ) {
V_63 = - V_169 ;
F_10 ( & V_29 ) ;
goto V_175;
}
}
if ( ! F_27 ( V_2 ) ) {
F_27 ( V_2 ) = F_141 ( F_139 ( V_2 ) ,
V_2 -> V_38 ,
V_2 -> V_38 , 0 , NULL ) ;
if ( ! F_27 ( V_2 ) ) {
V_63 = - V_169 ;
F_10 ( & V_29 ) ;
goto V_175;
}
}
}
F_10 ( & V_29 ) ;
while ( V_2 -> V_119 ) {
struct V_7 * V_12 = F_38 ( V_2 , V_168 ) ;
if ( ! V_12 ) {
V_63 = - V_169 ;
goto V_176;
}
F_87 ( V_12 ) ;
}
F_92 ( & V_29 ) ;
V_30 ++ ;
F_43 ( & V_2 -> V_177 , & V_178 ) ;
F_21 () ;
F_10 ( & V_29 ) ;
V_2 -> V_162 . V_179 = F_129 ;
V_2 -> V_162 . V_180 = F_128 ;
V_2 -> V_162 . V_181 = 1 ;
V_2 -> V_162 . V_182 = 0 ;
F_142 ( & V_2 -> V_162 ) ;
return V_2 ;
V_176:
V_175:
while ( ! F_71 ( & V_2 -> V_118 ) ) {
struct V_7 * V_12 = F_72 ( V_2 -> V_118 . V_106 ,
struct V_7 , V_53 ) ;
F_45 ( & V_12 -> V_53 ) ;
F_41 ( V_12 ) ;
}
F_143 ( V_2 -> V_70 ) ;
V_174:
F_40 ( V_2 ) ;
V_170:
return F_99 ( V_63 ) ;
}
void F_144 ( struct V_1 * V_2 )
{
unsigned V_152 ;
F_122 ( V_2 ) ;
F_145 ( & V_2 -> V_162 ) ;
F_92 ( & V_29 ) ;
F_45 ( & V_2 -> V_177 ) ;
V_30 -- ;
F_21 () ;
F_10 ( & V_29 ) ;
F_2 ( ! F_146 ( & V_2 -> V_11 ) ) ;
F_2 ( V_2 -> V_119 ) ;
while ( ! F_71 ( & V_2 -> V_118 ) ) {
struct V_7 * V_12 = F_72 ( V_2 -> V_118 . V_106 ,
struct V_7 , V_53 ) ;
F_45 ( & V_12 -> V_53 ) ;
F_41 ( V_12 ) ;
}
for ( V_152 = 0 ; V_152 < V_153 ; V_152 ++ )
if ( V_2 -> V_51 [ V_152 ] )
F_124 ( L_4 , V_152 , V_2 -> V_51 [ V_152 ] ) ;
for ( V_152 = 0 ; V_152 < V_153 ; V_152 ++ )
F_2 ( V_2 -> V_51 [ V_152 ] ) ;
F_143 ( V_2 -> V_70 ) ;
F_40 ( V_2 ) ;
}
static unsigned F_147 ( void )
{
unsigned V_183 = F_23 ( V_184 ) ;
if ( V_183 > V_185 / V_186 )
V_183 = V_185 / V_186 ;
return V_183 * V_186 ;
}
static bool F_148 ( struct V_7 * V_12 , unsigned long V_187 )
{
return F_149 ( V_56 , V_12 -> V_55 + V_187 ) ;
}
static void F_150 ( struct V_1 * V_2 , unsigned long V_187 )
{
struct V_7 * V_12 , * V_122 ;
unsigned V_161 = F_126 ( V_2 ) ;
unsigned V_76 ;
F_4 ( V_2 ) ;
V_76 = V_2 -> V_51 [ V_123 ] + V_2 -> V_51 [ V_129 ] ;
F_90 (b, tmp, &c->lru[LIST_CLEAN], lru_list) {
if ( V_76 <= V_161 )
break;
if ( ! F_148 ( V_12 , V_187 ) )
break;
if ( F_125 ( V_12 , 0 ) )
V_76 -- ;
F_73 () ;
}
F_9 ( V_2 ) ;
}
static void F_151 ( void )
{
unsigned long V_188 = F_147 () ;
struct V_1 * V_2 ;
F_92 ( & V_29 ) ;
F_123 (c, &dm_bufio_all_clients, client_list)
F_150 ( V_2 , V_188 ) ;
F_10 ( & V_29 ) ;
}
static void F_152 ( struct V_189 * V_190 )
{
F_151 () ;
F_153 ( V_191 , & V_192 ,
V_193 * V_186 ) ;
}
static int T_4 F_154 ( void )
{
T_5 V_78 ;
V_23 = 0 ;
V_24 = 0 ;
V_25 = 0 ;
V_27 = 0 ;
memset ( & V_5 , 0 , sizeof V_5 ) ;
memset ( & V_194 , 0 , sizeof V_194 ) ;
V_78 = ( T_5 ) ( ( V_195 - V_196 ) *
V_197 / 100 ) << V_172 ;
if ( V_78 > V_198 )
V_78 = V_198 ;
#ifdef F_155
if ( V_78 > ( V_199 - V_200 ) * V_201 / 100 )
V_78 = ( V_199 - V_200 ) * V_201 / 100 ;
#endif
V_33 = V_78 ;
F_92 ( & V_29 ) ;
F_21 () ;
F_10 ( & V_29 ) ;
V_191 = F_156 ( L_5 ) ;
if ( ! V_191 )
return - V_169 ;
F_157 ( & V_192 , F_152 ) ;
F_153 ( V_191 , & V_192 ,
V_193 * V_186 ) ;
return 0 ;
}
static void T_6 F_158 ( void )
{
int V_202 = 0 ;
int V_152 ;
F_159 ( & V_192 ) ;
F_160 ( V_191 ) ;
for ( V_152 = 0 ; V_152 < F_3 ( V_5 ) ; V_152 ++ ) {
struct V_203 * V_204 = V_5 [ V_152 ] ;
if ( V_204 )
F_161 ( V_204 ) ;
}
for ( V_152 = 0 ; V_152 < F_3 ( V_194 ) ; V_152 ++ )
F_40 ( V_194 [ V_152 ] ) ;
if ( V_30 ) {
F_36 ( L_6 ,
V_205 , V_30 ) ;
V_202 = 1 ;
}
if ( V_27 ) {
F_36 ( L_7 ,
V_205 , V_27 ) ;
V_202 = 1 ;
}
if ( V_24 ) {
F_36 ( L_8 ,
V_205 , V_24 ) ;
V_202 = 1 ;
}
if ( V_25 ) {
F_36 ( L_9 ,
V_205 , V_25 ) ;
V_202 = 1 ;
}
if ( V_202 )
F_37 () ;
}
