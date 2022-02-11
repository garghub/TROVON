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
. V_75 . V_76 = F_51 ,
. V_75 . V_64 = V_8 ,
. V_77 = V_8 -> V_2 -> V_78 ,
} ;
struct V_79 V_80 = {
. V_81 = V_8 -> V_2 -> V_81 ,
. V_82 = V_16 << V_8 -> V_2 -> V_83 ,
. V_84 = V_8 -> V_2 -> V_45 >> V_85 ,
} ;
if ( V_8 -> V_26 != V_52 ) {
V_73 . V_86 . type = V_87 ;
V_73 . V_86 . V_44 . V_88 = V_8 -> V_55 ;
} else {
V_73 . V_86 . type = V_89 ;
V_73 . V_86 . V_44 . V_90 = V_8 -> V_55 ;
}
V_8 -> V_65 . V_68 = V_70 ;
V_71 = V_78 ( & V_73 , 1 , & V_80 , NULL ) ;
if ( V_71 ) {
V_8 -> V_65 . V_66 = V_71 ;
V_70 ( & V_8 -> V_65 ) ;
}
}
static void F_53 ( struct V_65 * V_65 )
{
T_3 * V_91 = V_65 -> V_92 ;
int error = V_65 -> V_66 ;
F_54 ( V_65 ) ;
V_65 -> V_66 = error ;
V_91 ( V_65 ) ;
}
static void F_55 ( struct V_7 * V_8 , int V_69 , T_1 V_16 ,
T_3 * V_70 )
{
char * V_44 ;
int V_93 ;
F_56 ( & V_8 -> V_65 ) ;
V_8 -> V_65 . V_94 = V_8 -> V_95 ;
V_8 -> V_65 . V_96 = V_97 ;
V_8 -> V_65 . V_98 . V_99 = V_16 << V_8 -> V_2 -> V_83 ;
V_8 -> V_65 . V_100 = V_8 -> V_2 -> V_81 ;
V_8 -> V_65 . V_68 = F_53 ;
V_8 -> V_65 . V_92 = V_70 ;
V_44 = V_8 -> V_55 ;
V_93 = V_8 -> V_2 -> V_45 ;
if ( V_93 >= V_101 )
F_2 ( ( unsigned long ) V_44 & ( V_101 - 1 ) ) ;
else
F_2 ( ( unsigned long ) V_44 & ( V_93 - 1 ) ) ;
do {
if ( ! F_57 ( & V_8 -> V_65 , F_58 ( V_44 ) ,
V_93 < V_101 ? V_93 : V_101 ,
F_59 ( V_44 ) ) ) {
F_2 ( V_8 -> V_2 -> V_45 <= V_101 ) ;
F_52 ( V_8 , V_69 , V_16 , V_70 ) ;
return;
}
V_93 -= V_101 ;
V_44 += V_101 ;
} while ( V_93 > 0 );
F_60 ( V_69 , & V_8 -> V_65 ) ;
}
static void F_61 ( struct V_7 * V_8 , int V_69 , T_1 V_16 ,
T_3 * V_70 )
{
if ( V_69 == V_102 && V_8 -> V_2 -> V_103 )
V_8 -> V_2 -> V_103 ( V_8 ) ;
if ( V_8 -> V_2 -> V_45 <= V_97 * V_101 &&
V_8 -> V_26 != V_52 )
F_55 ( V_8 , V_69 , V_16 , V_70 ) ;
else
F_52 ( V_8 , V_69 , V_16 , V_70 ) ;
}
static void F_62 ( struct V_65 * V_65 )
{
struct V_7 * V_8 = F_14 ( V_65 , struct V_7 , V_65 ) ;
V_8 -> V_104 = V_65 -> V_66 ;
if ( F_63 ( V_65 -> V_66 ) ) {
struct V_1 * V_2 = V_8 -> V_2 ;
int error = V_65 -> V_66 ;
( void ) F_26 ( & V_2 -> V_105 , 0 , error ) ;
}
F_2 ( ! F_64 ( V_106 , & V_8 -> V_107 ) ) ;
F_65 () ;
F_66 ( V_106 , & V_8 -> V_107 ) ;
F_67 () ;
F_68 ( & V_8 -> V_107 , V_106 ) ;
}
static void F_69 ( struct V_7 * V_8 ,
struct V_108 * V_109 )
{
if ( ! F_64 ( V_110 , & V_8 -> V_107 ) )
return;
F_66 ( V_110 , & V_8 -> V_107 ) ;
F_70 ( & V_8 -> V_107 , V_106 , V_111 ) ;
if ( ! V_109 )
F_61 ( V_8 , V_102 , V_8 -> V_16 , F_62 ) ;
else
F_71 ( & V_8 -> V_109 , V_109 ) ;
}
static void F_72 ( struct V_108 * V_109 )
{
struct V_112 V_113 ;
F_73 ( & V_113 ) ;
while ( ! F_74 ( V_109 ) ) {
struct V_7 * V_8 =
F_75 ( V_109 -> V_114 , struct V_7 , V_109 ) ;
F_48 ( & V_8 -> V_109 ) ;
F_61 ( V_8 , V_102 , V_8 -> V_16 , F_62 ) ;
F_76 () ;
}
F_77 ( & V_113 ) ;
}
static void F_78 ( struct V_7 * V_8 )
{
F_2 ( V_8 -> V_115 ) ;
if ( ! V_8 -> V_107 )
return;
F_79 ( & V_8 -> V_107 , V_116 , V_111 ) ;
F_69 ( V_8 , NULL ) ;
F_79 ( & V_8 -> V_107 , V_106 , V_111 ) ;
}
static struct V_7 * F_80 ( struct V_1 * V_2 )
{
struct V_7 * V_8 ;
F_81 (b, &c->lru[LIST_CLEAN], lru_list) {
F_2 ( F_64 ( V_106 , & V_8 -> V_107 ) ) ;
F_2 ( F_64 ( V_110 , & V_8 -> V_107 ) ) ;
if ( ! V_8 -> V_115 ) {
F_78 ( V_8 ) ;
F_47 ( V_8 ) ;
return V_8 ;
}
F_76 () ;
}
F_81 (b, &c->lru[LIST_DIRTY], lru_list) {
F_2 ( F_64 ( V_116 , & V_8 -> V_107 ) ) ;
if ( ! V_8 -> V_115 ) {
F_78 ( V_8 ) ;
F_47 ( V_8 ) ;
return V_8 ;
}
F_76 () ;
}
return NULL ;
}
static void F_82 ( struct V_1 * V_2 )
{
F_83 ( V_117 , V_118 ) ;
F_84 ( & V_2 -> V_119 , & V_117 ) ;
F_85 ( V_118 , V_111 ) ;
F_9 ( V_2 ) ;
F_86 () ;
F_87 ( & V_2 -> V_119 , & V_117 ) ;
F_4 ( V_2 ) ;
}
static struct V_7 * F_88 ( struct V_1 * V_2 , enum V_120 V_121 )
{
struct V_7 * V_8 ;
while ( 1 ) {
if ( V_38 != 1 ) {
V_8 = F_40 ( V_2 , V_122 | V_49 | V_123 | V_124 ) ;
if ( V_8 )
return V_8 ;
}
if ( V_121 == V_125 )
return NULL ;
if ( ! F_74 ( & V_2 -> V_126 ) ) {
V_8 = F_75 ( V_2 -> V_126 . V_114 ,
struct V_7 , V_60 ) ;
F_48 ( & V_8 -> V_60 ) ;
V_2 -> V_127 ++ ;
return V_8 ;
}
V_8 = F_80 ( V_2 ) ;
if ( V_8 )
return V_8 ;
F_82 ( V_2 ) ;
}
}
static struct V_7 * F_89 ( struct V_1 * V_2 , enum V_120 V_121 )
{
struct V_7 * V_8 = F_88 ( V_2 , V_121 ) ;
if ( ! V_8 )
return NULL ;
if ( V_2 -> V_128 )
V_2 -> V_128 ( V_8 ) ;
return V_8 ;
}
static void F_90 ( struct V_7 * V_8 )
{
struct V_1 * V_2 = V_8 -> V_2 ;
if ( ! V_2 -> V_127 )
F_44 ( V_8 ) ;
else {
F_46 ( & V_8 -> V_60 , & V_2 -> V_126 ) ;
V_2 -> V_127 -- ;
}
F_91 ( & V_2 -> V_119 ) ;
}
static void F_92 ( struct V_1 * V_2 , int V_129 ,
struct V_108 * V_109 )
{
struct V_7 * V_8 , * V_130 ;
F_93 (b, tmp, &c->lru[LIST_DIRTY], lru_list) {
F_2 ( F_64 ( V_116 , & V_8 -> V_107 ) ) ;
if ( ! F_64 ( V_110 , & V_8 -> V_107 ) &&
! F_64 ( V_106 , & V_8 -> V_107 ) ) {
F_49 ( V_8 , V_131 ) ;
continue;
}
if ( V_129 && F_64 ( V_106 , & V_8 -> V_107 ) )
return;
F_69 ( V_8 , V_109 ) ;
F_76 () ;
}
}
static void F_94 ( struct V_1 * V_2 ,
unsigned long * V_132 ,
unsigned long * V_133 )
{
unsigned long V_134 ;
if ( F_25 ( V_39 ) != V_38 ) {
F_95 ( & V_36 ) ;
F_23 () ;
F_10 ( & V_36 ) ;
}
V_134 = V_41 >>
( V_2 -> V_83 + V_85 ) ;
if ( V_134 < V_2 -> V_135 )
V_134 = V_2 -> V_135 ;
* V_133 = V_134 ;
* V_132 = V_134 * V_136 / 100 ;
}
static void F_96 ( struct V_1 * V_2 ,
struct V_108 * V_109 )
{
unsigned long V_132 , V_133 ;
F_94 ( V_2 , & V_132 , & V_133 ) ;
while ( V_2 -> V_58 [ V_131 ] + V_2 -> V_58 [ V_137 ] >
V_133 ) {
struct V_7 * V_8 = F_80 ( V_2 ) ;
if ( ! V_8 )
return;
F_90 ( V_8 ) ;
F_76 () ;
}
if ( V_2 -> V_58 [ V_137 ] > V_132 )
F_92 ( V_2 , 1 , V_109 ) ;
}
static struct V_7 * F_97 ( struct V_1 * V_2 , T_1 V_16 ,
enum V_120 V_121 , int * V_138 ,
struct V_108 * V_109 )
{
struct V_7 * V_8 , * V_139 = NULL ;
* V_138 = 0 ;
V_8 = F_13 ( V_2 , V_16 ) ;
if ( V_8 )
goto V_140;
if ( V_121 == V_141 )
return NULL ;
V_139 = F_89 ( V_2 , V_121 ) ;
if ( ! V_139 )
return NULL ;
V_8 = F_13 ( V_2 , V_16 ) ;
if ( V_8 ) {
F_90 ( V_139 ) ;
goto V_140;
}
F_96 ( V_2 , V_109 ) ;
V_8 = V_139 ;
V_8 -> V_115 = 1 ;
V_8 -> V_142 = 0 ;
V_8 -> V_104 = 0 ;
F_45 ( V_8 , V_16 , V_131 ) ;
if ( V_121 == V_143 ) {
V_8 -> V_107 = 0 ;
return V_8 ;
}
V_8 -> V_107 = 1 << V_116 ;
* V_138 = 1 ;
return V_8 ;
V_140:
if ( V_121 == V_125 )
return NULL ;
if ( V_121 == V_141 && F_63 ( F_64 ( V_116 , & V_8 -> V_107 ) ) )
return NULL ;
V_8 -> V_115 ++ ;
F_49 ( V_8 , F_64 ( V_110 , & V_8 -> V_107 ) ||
F_64 ( V_106 , & V_8 -> V_107 ) ) ;
return V_8 ;
}
static void F_98 ( struct V_65 * V_65 )
{
struct V_7 * V_8 = F_14 ( V_65 , struct V_7 , V_65 ) ;
V_8 -> V_142 = V_65 -> V_66 ;
F_2 ( ! F_64 ( V_116 , & V_8 -> V_107 ) ) ;
F_65 () ;
F_66 ( V_116 , & V_8 -> V_107 ) ;
F_67 () ;
F_68 ( & V_8 -> V_107 , V_116 ) ;
}
static void * F_99 ( struct V_1 * V_2 , T_1 V_16 ,
enum V_120 V_121 , struct V_7 * * V_144 )
{
int V_138 ;
struct V_7 * V_8 ;
F_100 ( V_109 ) ;
F_4 ( V_2 ) ;
V_8 = F_97 ( V_2 , V_16 , V_121 , & V_138 , & V_109 ) ;
#ifdef F_43
if ( V_8 && V_8 -> V_115 == 1 )
F_11 ( V_8 ) ;
#endif
F_9 ( V_2 ) ;
F_72 ( & V_109 ) ;
if ( ! V_8 )
return NULL ;
if ( V_138 )
F_61 ( V_8 , V_145 , V_8 -> V_16 , F_98 ) ;
F_79 ( & V_8 -> V_107 , V_116 , V_111 ) ;
if ( V_8 -> V_142 ) {
int error = V_8 -> V_142 ;
F_101 ( V_8 ) ;
return F_102 ( error ) ;
}
* V_144 = V_8 ;
return V_8 -> V_55 ;
}
void * F_103 ( struct V_1 * V_2 , T_1 V_16 ,
struct V_7 * * V_144 )
{
return F_99 ( V_2 , V_16 , V_141 , V_144 ) ;
}
void * F_104 ( struct V_1 * V_2 , T_1 V_16 ,
struct V_7 * * V_144 )
{
F_2 ( F_6 () ) ;
return F_99 ( V_2 , V_16 , V_146 , V_144 ) ;
}
void * F_105 ( struct V_1 * V_2 , T_1 V_16 ,
struct V_7 * * V_144 )
{
F_2 ( F_6 () ) ;
return F_99 ( V_2 , V_16 , V_143 , V_144 ) ;
}
void F_106 ( struct V_1 * V_2 ,
T_1 V_16 , unsigned V_147 )
{
struct V_112 V_113 ;
F_100 ( V_109 ) ;
F_2 ( F_6 () ) ;
F_73 ( & V_113 ) ;
F_4 ( V_2 ) ;
for (; V_147 -- ; V_16 ++ ) {
int V_138 ;
struct V_7 * V_8 ;
V_8 = F_97 ( V_2 , V_16 , V_125 , & V_138 ,
& V_109 ) ;
if ( F_63 ( ! F_74 ( & V_109 ) ) ) {
F_9 ( V_2 ) ;
F_77 ( & V_113 ) ;
F_72 ( & V_109 ) ;
F_73 ( & V_113 ) ;
F_4 ( V_2 ) ;
}
if ( F_63 ( V_8 != NULL ) ) {
F_9 ( V_2 ) ;
if ( V_138 )
F_61 ( V_8 , V_145 , V_8 -> V_16 , F_98 ) ;
F_101 ( V_8 ) ;
F_76 () ;
if ( ! V_147 )
goto V_148;
F_4 ( V_2 ) ;
}
}
F_9 ( V_2 ) ;
V_148:
F_77 ( & V_113 ) ;
}
void F_101 ( struct V_7 * V_8 )
{
struct V_1 * V_2 = V_8 -> V_2 ;
F_4 ( V_2 ) ;
F_2 ( ! V_8 -> V_115 ) ;
V_8 -> V_115 -- ;
if ( ! V_8 -> V_115 ) {
F_91 ( & V_2 -> V_119 ) ;
if ( ( V_8 -> V_142 || V_8 -> V_104 ) &&
! F_64 ( V_116 , & V_8 -> V_107 ) &&
! F_64 ( V_106 , & V_8 -> V_107 ) &&
! F_64 ( V_110 , & V_8 -> V_107 ) ) {
F_47 ( V_8 ) ;
F_90 ( V_8 ) ;
}
}
F_9 ( V_2 ) ;
}
void F_107 ( struct V_7 * V_8 )
{
struct V_1 * V_2 = V_8 -> V_2 ;
F_4 ( V_2 ) ;
F_2 ( F_64 ( V_116 , & V_8 -> V_107 ) ) ;
if ( ! F_108 ( V_110 , & V_8 -> V_107 ) )
F_49 ( V_8 , V_137 ) ;
F_9 ( V_2 ) ;
}
void F_109 ( struct V_1 * V_2 )
{
F_100 ( V_109 ) ;
F_2 ( F_6 () ) ;
F_4 ( V_2 ) ;
F_92 ( V_2 , 0 , & V_109 ) ;
F_9 ( V_2 ) ;
F_72 ( & V_109 ) ;
}
int F_110 ( struct V_1 * V_2 )
{
int V_149 , V_150 ;
unsigned long V_151 = 0 ;
struct V_7 * V_8 , * V_130 ;
F_100 ( V_109 ) ;
F_4 ( V_2 ) ;
F_92 ( V_2 , 0 , & V_109 ) ;
F_9 ( V_2 ) ;
F_72 ( & V_109 ) ;
F_4 ( V_2 ) ;
V_152:
F_93 (b, tmp, &c->lru[LIST_DIRTY], lru_list) {
int V_153 = 0 ;
if ( V_151 < V_2 -> V_58 [ V_137 ] )
V_151 ++ ;
F_2 ( F_64 ( V_116 , & V_8 -> V_107 ) ) ;
if ( F_64 ( V_106 , & V_8 -> V_107 ) ) {
if ( V_151 < V_2 -> V_58 [ V_137 ] ) {
V_153 = 1 ;
V_8 -> V_115 ++ ;
F_9 ( V_2 ) ;
F_79 ( & V_8 -> V_107 , V_106 ,
V_111 ) ;
F_4 ( V_2 ) ;
V_8 -> V_115 -- ;
} else
F_79 ( & V_8 -> V_107 , V_106 ,
V_111 ) ;
}
if ( ! F_64 ( V_110 , & V_8 -> V_107 ) &&
! F_64 ( V_106 , & V_8 -> V_107 ) )
F_49 ( V_8 , V_131 ) ;
F_76 () ;
if ( V_153 )
goto V_152;
}
F_91 ( & V_2 -> V_119 ) ;
F_9 ( V_2 ) ;
V_149 = F_111 ( & V_2 -> V_105 , 0 ) ;
V_150 = F_112 ( V_2 ) ;
if ( V_149 )
return V_149 ;
return V_150 ;
}
int F_112 ( struct V_1 * V_2 )
{
struct V_72 V_73 = {
. V_74 = V_154 ,
. V_86 . type = V_87 ,
. V_86 . V_44 . V_88 = NULL ,
. V_77 = V_2 -> V_78 ,
} ;
struct V_79 V_155 = {
. V_81 = V_2 -> V_81 ,
. V_82 = 0 ,
. V_84 = 0 ,
} ;
F_2 ( F_6 () ) ;
return V_78 ( & V_73 , 1 , & V_155 , NULL ) ;
}
void F_113 ( struct V_7 * V_8 , T_1 V_156 )
{
struct V_1 * V_2 = V_8 -> V_2 ;
struct V_7 * V_23 ;
F_2 ( F_6 () ) ;
F_4 ( V_2 ) ;
V_157:
V_23 = F_13 ( V_2 , V_156 ) ;
if ( V_23 ) {
if ( V_23 -> V_115 ) {
F_82 ( V_2 ) ;
goto V_157;
}
F_78 ( V_23 ) ;
F_47 ( V_23 ) ;
F_90 ( V_23 ) ;
}
F_2 ( ! V_8 -> V_115 ) ;
F_2 ( F_64 ( V_116 , & V_8 -> V_107 ) ) ;
F_69 ( V_8 , NULL ) ;
if ( V_8 -> V_115 == 1 ) {
F_79 ( & V_8 -> V_107 , V_106 ,
V_111 ) ;
F_114 ( V_110 , & V_8 -> V_107 ) ;
F_47 ( V_8 ) ;
F_45 ( V_8 , V_156 , V_137 ) ;
} else {
T_1 V_158 ;
F_70 ( & V_8 -> V_107 , V_106 ,
V_111 ) ;
V_158 = V_8 -> V_16 ;
F_47 ( V_8 ) ;
F_45 ( V_8 , V_156 , V_8 -> V_59 ) ;
F_61 ( V_8 , V_102 , V_156 , F_62 ) ;
F_79 ( & V_8 -> V_107 , V_106 ,
V_111 ) ;
F_47 ( V_8 ) ;
F_45 ( V_8 , V_158 , V_8 -> V_59 ) ;
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
F_90 ( V_8 ) ;
}
F_9 ( V_2 ) ;
}
void F_117 ( struct V_1 * V_2 , unsigned V_18 )
{
V_2 -> V_135 = V_18 ;
}
unsigned F_118 ( struct V_1 * V_2 )
{
return V_2 -> V_45 ;
}
T_1 F_119 ( struct V_1 * V_2 )
{
return F_120 ( V_2 -> V_81 -> V_159 ) >>
( V_85 + V_2 -> V_83 ) ;
}
T_1 F_121 ( struct V_7 * V_8 )
{
return V_8 -> V_16 ;
}
void * F_122 ( struct V_7 * V_8 )
{
return V_8 -> V_55 ;
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
int V_160 ;
bool V_161 = false ;
F_2 ( F_6 () ) ;
F_109 ( V_2 ) ;
F_4 ( V_2 ) ;
while ( ( V_8 = F_80 ( V_2 ) ) )
F_90 ( V_8 ) ;
for ( V_160 = 0 ; V_160 < V_162 ; V_160 ++ )
F_126 (b, &c->lru[i], lru_list) {
F_127 ( ! V_161 ) ;
V_161 = true ;
F_128 ( L_2 ,
( unsigned long long ) V_8 -> V_16 , V_8 -> V_115 , V_160 ) ;
#ifdef F_43
F_129 ( & V_8 -> V_9 , 1 ) ;
V_8 -> V_115 = 0 ;
#endif
}
#ifdef F_43
while ( ( V_8 = F_80 ( V_2 ) ) )
F_90 ( V_8 ) ;
#endif
for ( V_160 = 0 ; V_160 < V_162 ; V_160 ++ )
F_2 ( ! F_74 ( & V_2 -> V_61 [ V_160 ] ) ) ;
F_9 ( V_2 ) ;
}
static bool F_130 ( struct V_7 * V_8 , T_2 V_163 )
{
if ( ! ( V_163 & V_164 ) ) {
if ( F_64 ( V_116 , & V_8 -> V_107 ) ||
F_64 ( V_106 , & V_8 -> V_107 ) ||
F_64 ( V_110 , & V_8 -> V_107 ) )
return false ;
}
if ( V_8 -> V_115 )
return false ;
F_78 ( V_8 ) ;
F_47 ( V_8 ) ;
F_90 ( V_8 ) ;
return true ;
}
static unsigned F_131 ( struct V_1 * V_2 )
{
unsigned V_165 = F_25 ( V_166 ) ;
return V_165 / V_2 -> V_45 ;
}
static unsigned long F_132 ( struct V_1 * V_2 , unsigned long V_167 ,
T_2 V_42 )
{
int V_168 ;
struct V_7 * V_8 , * V_130 ;
unsigned long V_169 = 0 ;
unsigned long V_84 = V_167 ;
unsigned V_170 = F_131 ( V_2 ) ;
for ( V_168 = 0 ; V_168 < V_162 ; V_168 ++ ) {
F_93 (b, tmp, &c->lru[l], lru_list) {
if ( F_130 ( V_8 , V_42 ) )
V_169 ++ ;
if ( ! -- V_167 || ( ( V_84 - V_169 ) <= V_170 ) )
return V_169 ;
F_76 () ;
}
}
return V_169 ;
}
static unsigned long
F_133 ( struct V_171 * V_172 , struct V_173 * V_174 )
{
struct V_1 * V_2 ;
unsigned long V_169 ;
V_2 = F_14 ( V_172 , struct V_1 , V_171 ) ;
if ( V_174 -> V_42 & V_164 )
F_4 ( V_2 ) ;
else if ( ! F_7 ( V_2 ) )
return V_175 ;
V_169 = F_132 ( V_2 , V_174 -> V_167 , V_174 -> V_42 ) ;
F_9 ( V_2 ) ;
return V_169 ;
}
static unsigned long
F_134 ( struct V_171 * V_172 , struct V_173 * V_174 )
{
struct V_1 * V_2 ;
unsigned long V_84 ;
V_2 = F_14 ( V_172 , struct V_1 , V_171 ) ;
if ( V_174 -> V_42 & V_164 )
F_4 ( V_2 ) ;
else if ( ! F_7 ( V_2 ) )
return 0 ;
V_84 = V_2 -> V_58 [ V_131 ] + V_2 -> V_58 [ V_137 ] ;
F_9 ( V_2 ) ;
return V_84 ;
}
struct V_1 * F_135 ( struct V_176 * V_81 , unsigned V_45 ,
unsigned V_126 , unsigned V_56 ,
void (* V_128)( struct V_7 * ) ,
void (* V_103)( struct V_7 * ) )
{
int V_71 ;
struct V_1 * V_2 ;
unsigned V_160 ;
F_2 ( V_45 < 1 << V_85 ||
( V_45 & ( V_45 - 1 ) ) ) ;
V_2 = F_136 ( sizeof( * V_2 ) , V_177 ) ;
if ( ! V_2 ) {
V_71 = - V_178 ;
goto V_179;
}
V_2 -> V_19 = V_180 ;
V_2 -> V_81 = V_81 ;
V_2 -> V_45 = V_45 ;
V_2 -> V_83 = F_137 ( V_45 ) - V_85 ;
V_2 -> V_51 = ( F_137 ( V_45 ) >= V_181 ) ?
F_137 ( V_45 ) - V_181 : 0 ;
V_2 -> V_4 = ( F_137 ( V_45 ) < V_181 ?
V_181 - F_137 ( V_45 ) : 0 ) ;
V_2 -> V_56 = V_56 ;
V_2 -> V_128 = V_128 ;
V_2 -> V_103 = V_103 ;
for ( V_160 = 0 ; V_160 < V_162 ; V_160 ++ ) {
F_138 ( & V_2 -> V_61 [ V_160 ] ) ;
V_2 -> V_58 [ V_160 ] = 0 ;
}
F_139 ( & V_2 -> V_6 ) ;
F_138 ( & V_2 -> V_126 ) ;
V_2 -> V_127 = V_126 ;
V_2 -> V_135 = V_182 ;
F_140 ( & V_2 -> V_119 ) ;
V_2 -> V_105 = 0 ;
V_2 -> V_78 = F_141 () ;
if ( F_142 ( V_2 -> V_78 ) ) {
V_71 = F_143 ( V_2 -> V_78 ) ;
goto V_183;
}
F_95 ( & V_36 ) ;
if ( V_2 -> V_4 ) {
if ( ! F_144 ( V_2 ) ) {
F_144 ( V_2 ) = F_145 ( V_177 , L_3 , V_2 -> V_45 ) ;
if ( ! F_144 ( V_2 ) ) {
V_71 = - V_178 ;
F_10 ( & V_36 ) ;
goto V_184;
}
}
if ( ! F_29 ( V_2 ) ) {
F_29 ( V_2 ) = F_146 ( F_144 ( V_2 ) ,
V_2 -> V_45 ,
V_2 -> V_45 , 0 , NULL ) ;
if ( ! F_29 ( V_2 ) ) {
V_71 = - V_178 ;
F_10 ( & V_36 ) ;
goto V_184;
}
}
}
F_10 ( & V_36 ) ;
while ( V_2 -> V_127 ) {
struct V_7 * V_8 = F_40 ( V_2 , V_177 ) ;
if ( ! V_8 ) {
V_71 = - V_178 ;
goto V_185;
}
F_90 ( V_8 ) ;
}
F_95 ( & V_36 ) ;
V_37 ++ ;
F_46 ( & V_2 -> V_186 , & V_187 ) ;
F_23 () ;
F_10 ( & V_36 ) ;
V_2 -> V_171 . V_188 = F_134 ;
V_2 -> V_171 . V_189 = F_133 ;
V_2 -> V_171 . V_190 = 1 ;
V_2 -> V_171 . V_191 = 0 ;
F_147 ( & V_2 -> V_171 ) ;
return V_2 ;
V_185:
V_184:
while ( ! F_74 ( & V_2 -> V_126 ) ) {
struct V_7 * V_8 = F_75 ( V_2 -> V_126 . V_114 ,
struct V_7 , V_60 ) ;
F_48 ( & V_8 -> V_60 ) ;
F_44 ( V_8 ) ;
}
F_148 ( V_2 -> V_78 ) ;
V_183:
F_42 ( V_2 ) ;
V_179:
return F_102 ( V_71 ) ;
}
void F_149 ( struct V_1 * V_2 )
{
unsigned V_160 ;
F_125 ( V_2 ) ;
F_150 ( & V_2 -> V_171 ) ;
F_95 ( & V_36 ) ;
F_48 ( & V_2 -> V_186 ) ;
V_37 -- ;
F_23 () ;
F_10 ( & V_36 ) ;
F_2 ( ! F_151 ( & V_2 -> V_19 ) ) ;
F_2 ( V_2 -> V_127 ) ;
while ( ! F_74 ( & V_2 -> V_126 ) ) {
struct V_7 * V_8 = F_75 ( V_2 -> V_126 . V_114 ,
struct V_7 , V_60 ) ;
F_48 ( & V_8 -> V_60 ) ;
F_44 ( V_8 ) ;
}
for ( V_160 = 0 ; V_160 < V_162 ; V_160 ++ )
if ( V_2 -> V_58 [ V_160 ] )
F_128 ( L_4 , V_160 , V_2 -> V_58 [ V_160 ] ) ;
for ( V_160 = 0 ; V_160 < V_162 ; V_160 ++ )
F_2 ( V_2 -> V_58 [ V_160 ] ) ;
F_148 ( V_2 -> V_78 ) ;
F_42 ( V_2 ) ;
}
static unsigned F_152 ( void )
{
unsigned V_192 = F_25 ( V_193 ) ;
if ( V_192 > V_194 / V_195 )
V_192 = V_194 / V_195 ;
return V_192 * V_195 ;
}
static bool F_153 ( struct V_7 * V_8 , unsigned long V_196 )
{
return F_154 ( V_63 , V_8 -> V_62 + V_196 ) ;
}
static void F_155 ( struct V_1 * V_2 , unsigned long V_196 )
{
struct V_7 * V_8 , * V_130 ;
unsigned V_170 = F_131 ( V_2 ) ;
unsigned V_84 ;
F_4 ( V_2 ) ;
V_84 = V_2 -> V_58 [ V_131 ] + V_2 -> V_58 [ V_137 ] ;
F_93 (b, tmp, &c->lru[LIST_CLEAN], lru_list) {
if ( V_84 <= V_170 )
break;
if ( ! F_153 ( V_8 , V_196 ) )
break;
if ( F_130 ( V_8 , 0 ) )
V_84 -- ;
F_76 () ;
}
F_9 ( V_2 ) ;
}
static void F_156 ( void )
{
unsigned long V_197 = F_152 () ;
struct V_1 * V_2 ;
F_95 ( & V_36 ) ;
F_126 (c, &dm_bufio_all_clients, client_list)
F_155 ( V_2 , V_197 ) ;
F_10 ( & V_36 ) ;
}
static void F_157 ( struct V_198 * V_199 )
{
F_156 () ;
F_158 ( V_200 , & V_201 ,
V_202 * V_195 ) ;
}
static int T_4 F_159 ( void )
{
T_5 V_86 ;
V_30 = 0 ;
V_31 = 0 ;
V_32 = 0 ;
V_34 = 0 ;
memset ( & V_5 , 0 , sizeof V_5 ) ;
memset ( & V_203 , 0 , sizeof V_203 ) ;
V_86 = ( T_5 ) ( ( V_204 - V_205 ) *
V_206 / 100 ) << V_181 ;
if ( V_86 > V_207 )
V_86 = V_207 ;
#ifdef F_160
if ( V_86 > ( V_208 - V_209 ) * V_210 / 100 )
V_86 = ( V_208 - V_209 ) * V_210 / 100 ;
#endif
V_40 = V_86 ;
F_95 ( & V_36 ) ;
F_23 () ;
F_10 ( & V_36 ) ;
V_200 = F_161 ( L_5 ) ;
if ( ! V_200 )
return - V_178 ;
F_162 ( & V_201 , F_157 ) ;
F_158 ( V_200 , & V_201 ,
V_202 * V_195 ) ;
return 0 ;
}
static void T_6 F_163 ( void )
{
int V_211 = 0 ;
int V_160 ;
F_164 ( & V_201 ) ;
F_165 ( V_200 ) ;
for ( V_160 = 0 ; V_160 < F_3 ( V_5 ) ; V_160 ++ )
F_166 ( V_5 [ V_160 ] ) ;
for ( V_160 = 0 ; V_160 < F_3 ( V_203 ) ; V_160 ++ )
F_42 ( V_203 [ V_160 ] ) ;
if ( V_37 ) {
F_38 ( L_6 ,
V_212 , V_37 ) ;
V_211 = 1 ;
}
if ( V_34 ) {
F_38 ( L_7 ,
V_212 , V_34 ) ;
V_211 = 1 ;
}
if ( V_31 ) {
F_38 ( L_8 ,
V_212 , V_31 ) ;
V_211 = 1 ;
}
if ( V_32 ) {
F_38 ( L_9 ,
V_212 , V_32 ) ;
V_211 = 1 ;
}
F_2 ( V_211 ) ;
}
