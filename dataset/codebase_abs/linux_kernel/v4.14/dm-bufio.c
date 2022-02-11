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
V_8 -> V_64 . V_65 = error ? V_66 : 0 ;
V_8 -> V_64 . V_67 ( & V_8 -> V_64 ) ;
}
static void F_52 ( struct V_7 * V_8 , int V_68 , T_1 V_69 ,
unsigned V_70 , unsigned V_71 , T_3 * V_72 )
{
int V_73 ;
struct V_74 V_75 = {
. V_76 = V_68 ,
. V_77 = 0 ,
. V_78 . V_79 = F_51 ,
. V_78 . V_63 = V_8 ,
. V_80 = V_8 -> V_2 -> V_81 ,
} ;
struct V_82 V_83 = {
. V_84 = V_8 -> V_2 -> V_84 ,
. V_69 = V_69 ,
. V_85 = V_70 ,
} ;
if ( V_8 -> V_26 != V_52 ) {
V_75 . V_86 . type = V_87 ;
V_75 . V_86 . V_44 . V_88 = ( char * ) V_8 -> V_54 + V_71 ;
} else {
V_75 . V_86 . type = V_89 ;
V_75 . V_86 . V_44 . V_90 = ( char * ) V_8 -> V_54 + V_71 ;
}
V_8 -> V_64 . V_67 = V_72 ;
V_73 = V_81 ( & V_75 , 1 , & V_83 , NULL ) ;
if ( V_73 ) {
V_8 -> V_64 . V_65 = F_53 ( V_73 ) ;
V_72 ( & V_8 -> V_64 ) ;
}
}
static void F_54 ( struct V_64 * V_64 )
{
T_3 * V_91 = V_64 -> V_92 ;
T_4 V_93 = V_64 -> V_65 ;
F_55 ( V_64 ) ;
V_64 -> V_65 = V_93 ;
V_91 ( V_64 ) ;
}
static void F_56 ( struct V_7 * V_8 , int V_68 , T_1 V_69 ,
unsigned V_70 , unsigned V_71 , T_3 * V_72 )
{
char * V_44 ;
unsigned V_94 ;
F_57 ( & V_8 -> V_64 , V_8 -> V_95 , V_96 ) ;
V_8 -> V_64 . V_97 . V_98 = V_69 ;
F_58 ( & V_8 -> V_64 , V_8 -> V_2 -> V_84 ) ;
V_8 -> V_64 . V_67 = F_54 ;
V_8 -> V_64 . V_92 = V_72 ;
F_59 ( & V_8 -> V_64 , V_68 , 0 ) ;
V_44 = ( char * ) V_8 -> V_54 + V_71 ;
V_94 = V_70 << V_99 ;
do {
unsigned V_100 = F_60 ( ( unsigned ) ( V_101 - F_61 ( V_44 ) ) , V_94 ) ;
if ( ! F_62 ( & V_8 -> V_64 , F_63 ( V_44 ) , V_100 ,
F_61 ( V_44 ) ) ) {
F_2 ( V_8 -> V_2 -> V_45 <= V_101 ) ;
F_52 ( V_8 , V_68 , V_69 , V_70 , V_71 , V_72 ) ;
return;
}
V_94 -= V_100 ;
V_44 += V_100 ;
} while ( V_94 > 0 );
F_64 ( & V_8 -> V_64 ) ;
}
static void F_65 ( struct V_7 * V_8 , int V_68 , T_3 * V_72 )
{
unsigned V_70 ;
T_1 V_69 ;
unsigned V_71 , V_102 ;
V_69 = ( V_8 -> V_16 << V_8 -> V_2 -> V_103 ) + V_8 -> V_2 -> V_104 ;
if ( V_68 != V_105 ) {
V_70 = 1 << V_8 -> V_2 -> V_103 ;
V_71 = 0 ;
} else {
if ( V_8 -> V_2 -> V_106 )
V_8 -> V_2 -> V_106 ( V_8 ) ;
V_71 = V_8 -> V_107 ;
V_102 = V_8 -> V_108 ;
V_71 &= - V_109 ;
V_102 += V_109 - 1 ;
V_102 &= - V_109 ;
if ( F_66 ( V_102 > V_8 -> V_2 -> V_45 ) )
V_102 = V_8 -> V_2 -> V_45 ;
V_69 += V_71 >> V_99 ;
V_70 = ( V_102 - V_71 ) >> V_99 ;
}
if ( V_70 <= ( ( V_96 * V_101 ) >> V_99 ) &&
V_8 -> V_26 != V_52 )
F_56 ( V_8 , V_68 , V_69 , V_70 , V_71 , V_72 ) ;
else
F_52 ( V_8 , V_68 , V_69 , V_70 , V_71 , V_72 ) ;
}
static void F_67 ( struct V_64 * V_64 )
{
struct V_7 * V_8 = F_14 ( V_64 , struct V_7 , V_64 ) ;
V_8 -> V_110 = V_64 -> V_65 ;
if ( F_66 ( V_64 -> V_65 ) ) {
struct V_1 * V_2 = V_8 -> V_2 ;
( void ) F_26 ( & V_2 -> V_111 , 0 ,
F_68 ( V_64 -> V_65 ) ) ;
}
F_2 ( ! F_69 ( V_112 , & V_8 -> V_113 ) ) ;
F_70 () ;
F_71 ( V_112 , & V_8 -> V_113 ) ;
F_72 () ;
F_73 ( & V_8 -> V_113 , V_112 ) ;
}
static void F_74 ( struct V_7 * V_8 ,
struct V_114 * V_115 )
{
if ( ! F_69 ( V_116 , & V_8 -> V_113 ) )
return;
F_71 ( V_116 , & V_8 -> V_113 ) ;
F_75 ( & V_8 -> V_113 , V_112 , V_117 ) ;
V_8 -> V_107 = V_8 -> V_118 ;
V_8 -> V_108 = V_8 -> V_119 ;
if ( ! V_115 )
F_65 ( V_8 , V_105 , F_67 ) ;
else
F_76 ( & V_8 -> V_115 , V_115 ) ;
}
static void F_77 ( struct V_114 * V_115 )
{
struct V_120 V_121 ;
F_78 ( & V_121 ) ;
while ( ! F_79 ( V_115 ) ) {
struct V_7 * V_8 =
F_80 ( V_115 -> V_122 , struct V_7 , V_115 ) ;
F_48 ( & V_8 -> V_115 ) ;
F_65 ( V_8 , V_105 , F_67 ) ;
F_81 () ;
}
F_82 ( & V_121 ) ;
}
static void F_83 ( struct V_7 * V_8 )
{
F_2 ( V_8 -> V_123 ) ;
if ( ! V_8 -> V_113 )
return;
F_84 ( & V_8 -> V_113 , V_124 , V_117 ) ;
F_74 ( V_8 , NULL ) ;
F_84 ( & V_8 -> V_113 , V_112 , V_117 ) ;
}
static struct V_7 * F_85 ( struct V_1 * V_2 )
{
struct V_7 * V_8 ;
F_86 (b, &c->lru[LIST_CLEAN], lru_list) {
F_2 ( F_69 ( V_112 , & V_8 -> V_113 ) ) ;
F_2 ( F_69 ( V_116 , & V_8 -> V_113 ) ) ;
if ( ! V_8 -> V_123 ) {
F_83 ( V_8 ) ;
F_47 ( V_8 ) ;
return V_8 ;
}
F_81 () ;
}
F_86 (b, &c->lru[LIST_DIRTY], lru_list) {
F_2 ( F_69 ( V_124 , & V_8 -> V_113 ) ) ;
if ( ! V_8 -> V_123 ) {
F_83 ( V_8 ) ;
F_47 ( V_8 ) ;
return V_8 ;
}
F_81 () ;
}
return NULL ;
}
static void F_87 ( struct V_1 * V_2 )
{
F_88 ( V_125 , V_126 ) ;
F_89 ( & V_2 -> V_127 , & V_125 ) ;
F_90 ( V_117 ) ;
F_9 ( V_2 ) ;
F_91 () ;
F_92 ( & V_2 -> V_127 , & V_125 ) ;
F_4 ( V_2 ) ;
}
static struct V_7 * F_93 ( struct V_1 * V_2 , enum V_128 V_129 )
{
struct V_7 * V_8 ;
bool V_130 = false ;
while ( 1 ) {
if ( V_38 != 1 ) {
V_8 = F_40 ( V_2 , V_131 | V_49 | V_132 | V_133 ) ;
if ( V_8 )
return V_8 ;
}
if ( V_129 == V_134 )
return NULL ;
if ( V_38 != 1 && ! V_130 ) {
F_9 ( V_2 ) ;
V_8 = F_40 ( V_2 , V_135 | V_49 | V_132 | V_133 ) ;
F_4 ( V_2 ) ;
if ( V_8 )
return V_8 ;
V_130 = true ;
}
if ( ! F_79 ( & V_2 -> V_136 ) ) {
V_8 = F_80 ( V_2 -> V_136 . V_122 ,
struct V_7 , V_59 ) ;
F_48 ( & V_8 -> V_59 ) ;
V_2 -> V_137 ++ ;
return V_8 ;
}
V_8 = F_85 ( V_2 ) ;
if ( V_8 )
return V_8 ;
F_87 ( V_2 ) ;
}
}
static struct V_7 * F_94 ( struct V_1 * V_2 , enum V_128 V_129 )
{
struct V_7 * V_8 = F_93 ( V_2 , V_129 ) ;
if ( ! V_8 )
return NULL ;
if ( V_2 -> V_138 )
V_2 -> V_138 ( V_8 ) ;
return V_8 ;
}
static void F_95 ( struct V_7 * V_8 )
{
struct V_1 * V_2 = V_8 -> V_2 ;
if ( ! V_2 -> V_137 )
F_44 ( V_8 ) ;
else {
F_46 ( & V_8 -> V_59 , & V_2 -> V_136 ) ;
V_2 -> V_137 -- ;
}
F_96 ( & V_2 -> V_127 ) ;
}
static void F_97 ( struct V_1 * V_2 , int V_139 ,
struct V_114 * V_115 )
{
struct V_7 * V_8 , * V_140 ;
F_98 (b, tmp, &c->lru[LIST_DIRTY], lru_list) {
F_2 ( F_69 ( V_124 , & V_8 -> V_113 ) ) ;
if ( ! F_69 ( V_116 , & V_8 -> V_113 ) &&
! F_69 ( V_112 , & V_8 -> V_113 ) ) {
F_49 ( V_8 , V_141 ) ;
continue;
}
if ( V_139 && F_69 ( V_112 , & V_8 -> V_113 ) )
return;
F_74 ( V_8 , V_115 ) ;
F_81 () ;
}
}
static void F_99 ( struct V_1 * V_2 ,
unsigned long * V_142 ,
unsigned long * V_143 )
{
unsigned long V_144 ;
if ( F_66 ( F_25 ( V_39 ) != V_38 ) ) {
if ( F_8 ( & V_36 ) ) {
F_23 () ;
F_10 ( & V_36 ) ;
}
}
V_144 = V_41 >>
( V_2 -> V_103 + V_99 ) ;
if ( V_144 < V_2 -> V_145 )
V_144 = V_2 -> V_145 ;
* V_143 = V_144 ;
* V_142 = V_144 * V_146 / 100 ;
}
static void F_100 ( struct V_1 * V_2 ,
struct V_114 * V_115 )
{
unsigned long V_142 , V_143 ;
F_99 ( V_2 , & V_142 , & V_143 ) ;
while ( V_2 -> V_57 [ V_141 ] + V_2 -> V_57 [ V_147 ] >
V_143 ) {
struct V_7 * V_8 = F_85 ( V_2 ) ;
if ( ! V_8 )
return;
F_95 ( V_8 ) ;
F_81 () ;
}
if ( V_2 -> V_57 [ V_147 ] > V_142 )
F_97 ( V_2 , 1 , V_115 ) ;
}
static struct V_7 * F_101 ( struct V_1 * V_2 , T_1 V_16 ,
enum V_128 V_129 , int * V_148 ,
struct V_114 * V_115 )
{
struct V_7 * V_8 , * V_149 = NULL ;
* V_148 = 0 ;
V_8 = F_13 ( V_2 , V_16 ) ;
if ( V_8 )
goto V_150;
if ( V_129 == V_151 )
return NULL ;
V_149 = F_94 ( V_2 , V_129 ) ;
if ( ! V_149 )
return NULL ;
V_8 = F_13 ( V_2 , V_16 ) ;
if ( V_8 ) {
F_95 ( V_149 ) ;
goto V_150;
}
F_100 ( V_2 , V_115 ) ;
V_8 = V_149 ;
V_8 -> V_123 = 1 ;
V_8 -> V_152 = 0 ;
V_8 -> V_110 = 0 ;
F_45 ( V_8 , V_16 , V_141 ) ;
if ( V_129 == V_153 ) {
V_8 -> V_113 = 0 ;
return V_8 ;
}
V_8 -> V_113 = 1 << V_124 ;
* V_148 = 1 ;
return V_8 ;
V_150:
if ( V_129 == V_134 )
return NULL ;
if ( V_129 == V_151 && F_66 ( F_69 ( V_124 , & V_8 -> V_113 ) ) )
return NULL ;
V_8 -> V_123 ++ ;
F_49 ( V_8 , F_69 ( V_116 , & V_8 -> V_113 ) ||
F_69 ( V_112 , & V_8 -> V_113 ) ) ;
return V_8 ;
}
static void F_102 ( struct V_64 * V_64 )
{
struct V_7 * V_8 = F_14 ( V_64 , struct V_7 , V_64 ) ;
V_8 -> V_152 = V_64 -> V_65 ;
F_2 ( ! F_69 ( V_124 , & V_8 -> V_113 ) ) ;
F_70 () ;
F_71 ( V_124 , & V_8 -> V_113 ) ;
F_72 () ;
F_73 ( & V_8 -> V_113 , V_124 ) ;
}
static void * F_103 ( struct V_1 * V_2 , T_1 V_16 ,
enum V_128 V_129 , struct V_7 * * V_154 )
{
int V_148 ;
struct V_7 * V_8 ;
F_104 ( V_115 ) ;
F_4 ( V_2 ) ;
V_8 = F_101 ( V_2 , V_16 , V_129 , & V_148 , & V_115 ) ;
#ifdef F_43
if ( V_8 && V_8 -> V_123 == 1 )
F_11 ( V_8 ) ;
#endif
F_9 ( V_2 ) ;
F_77 ( & V_115 ) ;
if ( ! V_8 )
return NULL ;
if ( V_148 )
F_65 ( V_8 , V_155 , F_102 ) ;
F_84 ( & V_8 -> V_113 , V_124 , V_117 ) ;
if ( V_8 -> V_152 ) {
int error = F_68 ( V_8 -> V_152 ) ;
F_105 ( V_8 ) ;
return F_106 ( error ) ;
}
* V_154 = V_8 ;
return V_8 -> V_54 ;
}
void * F_107 ( struct V_1 * V_2 , T_1 V_16 ,
struct V_7 * * V_154 )
{
return F_103 ( V_2 , V_16 , V_151 , V_154 ) ;
}
void * F_108 ( struct V_1 * V_2 , T_1 V_16 ,
struct V_7 * * V_154 )
{
F_2 ( F_6 () ) ;
return F_103 ( V_2 , V_16 , V_156 , V_154 ) ;
}
void * F_109 ( struct V_1 * V_2 , T_1 V_16 ,
struct V_7 * * V_154 )
{
F_2 ( F_6 () ) ;
return F_103 ( V_2 , V_16 , V_153 , V_154 ) ;
}
void F_110 ( struct V_1 * V_2 ,
T_1 V_16 , unsigned V_157 )
{
struct V_120 V_121 ;
F_104 ( V_115 ) ;
F_2 ( F_6 () ) ;
F_78 ( & V_121 ) ;
F_4 ( V_2 ) ;
for (; V_157 -- ; V_16 ++ ) {
int V_148 ;
struct V_7 * V_8 ;
V_8 = F_101 ( V_2 , V_16 , V_134 , & V_148 ,
& V_115 ) ;
if ( F_66 ( ! F_79 ( & V_115 ) ) ) {
F_9 ( V_2 ) ;
F_82 ( & V_121 ) ;
F_77 ( & V_115 ) ;
F_78 ( & V_121 ) ;
F_4 ( V_2 ) ;
}
if ( F_66 ( V_8 != NULL ) ) {
F_9 ( V_2 ) ;
if ( V_148 )
F_65 ( V_8 , V_155 , F_102 ) ;
F_105 ( V_8 ) ;
F_81 () ;
if ( ! V_157 )
goto V_158;
F_4 ( V_2 ) ;
}
}
F_9 ( V_2 ) ;
V_158:
F_82 ( & V_121 ) ;
}
void F_105 ( struct V_7 * V_8 )
{
struct V_1 * V_2 = V_8 -> V_2 ;
F_4 ( V_2 ) ;
F_2 ( ! V_8 -> V_123 ) ;
V_8 -> V_123 -- ;
if ( ! V_8 -> V_123 ) {
F_96 ( & V_2 -> V_127 ) ;
if ( ( V_8 -> V_152 || V_8 -> V_110 ) &&
! F_69 ( V_124 , & V_8 -> V_113 ) &&
! F_69 ( V_112 , & V_8 -> V_113 ) &&
! F_69 ( V_116 , & V_8 -> V_113 ) ) {
F_47 ( V_8 ) ;
F_95 ( V_8 ) ;
}
}
F_9 ( V_2 ) ;
}
void F_111 ( struct V_7 * V_8 ,
unsigned V_104 , unsigned V_102 )
{
struct V_1 * V_2 = V_8 -> V_2 ;
F_2 ( V_104 >= V_102 ) ;
F_2 ( V_102 > V_8 -> V_2 -> V_45 ) ;
F_4 ( V_2 ) ;
F_2 ( F_69 ( V_124 , & V_8 -> V_113 ) ) ;
if ( ! F_112 ( V_116 , & V_8 -> V_113 ) ) {
V_8 -> V_118 = V_104 ;
V_8 -> V_119 = V_102 ;
F_49 ( V_8 , V_147 ) ;
} else {
if ( V_104 < V_8 -> V_118 )
V_8 -> V_118 = V_104 ;
if ( V_102 > V_8 -> V_119 )
V_8 -> V_119 = V_102 ;
}
F_9 ( V_2 ) ;
}
void F_113 ( struct V_7 * V_8 )
{
F_111 ( V_8 , 0 , V_8 -> V_2 -> V_45 ) ;
}
void F_114 ( struct V_1 * V_2 )
{
F_104 ( V_115 ) ;
F_2 ( F_6 () ) ;
F_4 ( V_2 ) ;
F_97 ( V_2 , 0 , & V_115 ) ;
F_9 ( V_2 ) ;
F_77 ( & V_115 ) ;
}
int F_115 ( struct V_1 * V_2 )
{
int V_159 , V_160 ;
unsigned long V_161 = 0 ;
struct V_7 * V_8 , * V_140 ;
F_104 ( V_115 ) ;
F_4 ( V_2 ) ;
F_97 ( V_2 , 0 , & V_115 ) ;
F_9 ( V_2 ) ;
F_77 ( & V_115 ) ;
F_4 ( V_2 ) ;
V_162:
F_98 (b, tmp, &c->lru[LIST_DIRTY], lru_list) {
int V_163 = 0 ;
if ( V_161 < V_2 -> V_57 [ V_147 ] )
V_161 ++ ;
F_2 ( F_69 ( V_124 , & V_8 -> V_113 ) ) ;
if ( F_69 ( V_112 , & V_8 -> V_113 ) ) {
if ( V_161 < V_2 -> V_57 [ V_147 ] ) {
V_163 = 1 ;
V_8 -> V_123 ++ ;
F_9 ( V_2 ) ;
F_84 ( & V_8 -> V_113 , V_112 ,
V_117 ) ;
F_4 ( V_2 ) ;
V_8 -> V_123 -- ;
} else
F_84 ( & V_8 -> V_113 , V_112 ,
V_117 ) ;
}
if ( ! F_69 ( V_116 , & V_8 -> V_113 ) &&
! F_69 ( V_112 , & V_8 -> V_113 ) )
F_49 ( V_8 , V_141 ) ;
F_81 () ;
if ( V_163 )
goto V_162;
}
F_96 ( & V_2 -> V_127 ) ;
F_9 ( V_2 ) ;
V_159 = F_116 ( & V_2 -> V_111 , 0 ) ;
V_160 = F_117 ( V_2 ) ;
if ( V_159 )
return V_159 ;
return V_160 ;
}
int F_117 ( struct V_1 * V_2 )
{
struct V_74 V_75 = {
. V_76 = V_164 ,
. V_77 = V_165 | V_166 ,
. V_86 . type = V_87 ,
. V_86 . V_44 . V_88 = NULL ,
. V_80 = V_2 -> V_81 ,
} ;
struct V_82 V_167 = {
. V_84 = V_2 -> V_84 ,
. V_69 = 0 ,
. V_85 = 0 ,
} ;
F_2 ( F_6 () ) ;
return V_81 ( & V_75 , 1 , & V_167 , NULL ) ;
}
void F_118 ( struct V_7 * V_8 , T_1 V_168 )
{
struct V_1 * V_2 = V_8 -> V_2 ;
struct V_7 * V_23 ;
F_2 ( F_6 () ) ;
F_4 ( V_2 ) ;
V_169:
V_23 = F_13 ( V_2 , V_168 ) ;
if ( V_23 ) {
if ( V_23 -> V_123 ) {
F_87 ( V_2 ) ;
goto V_169;
}
F_83 ( V_23 ) ;
F_47 ( V_23 ) ;
F_95 ( V_23 ) ;
}
F_2 ( ! V_8 -> V_123 ) ;
F_2 ( F_69 ( V_124 , & V_8 -> V_113 ) ) ;
F_74 ( V_8 , NULL ) ;
if ( V_8 -> V_123 == 1 ) {
F_84 ( & V_8 -> V_113 , V_112 ,
V_117 ) ;
F_119 ( V_116 , & V_8 -> V_113 ) ;
V_8 -> V_118 = 0 ;
V_8 -> V_119 = V_2 -> V_45 ;
F_47 ( V_8 ) ;
F_45 ( V_8 , V_168 , V_147 ) ;
} else {
T_1 V_170 ;
F_75 ( & V_8 -> V_113 , V_112 ,
V_117 ) ;
V_170 = V_8 -> V_16 ;
F_47 ( V_8 ) ;
F_45 ( V_8 , V_168 , V_8 -> V_58 ) ;
F_65 ( V_8 , V_105 , F_67 ) ;
F_84 ( & V_8 -> V_113 , V_112 ,
V_117 ) ;
F_47 ( V_8 ) ;
F_45 ( V_8 , V_170 , V_8 -> V_58 ) ;
}
F_9 ( V_2 ) ;
F_105 ( V_8 ) ;
}
void F_120 ( struct V_1 * V_2 , T_1 V_16 )
{
struct V_7 * V_8 ;
F_4 ( V_2 ) ;
V_8 = F_13 ( V_2 , V_16 ) ;
if ( V_8 && F_121 ( ! V_8 -> V_123 ) && F_121 ( ! V_8 -> V_113 ) ) {
F_47 ( V_8 ) ;
F_95 ( V_8 ) ;
}
F_9 ( V_2 ) ;
}
void F_122 ( struct V_1 * V_2 , unsigned V_18 )
{
V_2 -> V_145 = V_18 ;
}
unsigned F_123 ( struct V_1 * V_2 )
{
return V_2 -> V_45 ;
}
T_1 F_124 ( struct V_1 * V_2 )
{
return F_125 ( V_2 -> V_84 -> V_171 ) >>
( V_99 + V_2 -> V_103 ) ;
}
T_1 F_126 ( struct V_7 * V_8 )
{
return V_8 -> V_16 ;
}
void * F_127 ( struct V_7 * V_8 )
{
return V_8 -> V_54 ;
}
void * F_128 ( struct V_7 * V_8 )
{
return V_8 + 1 ;
}
struct V_1 * F_129 ( struct V_7 * V_8 )
{
return V_8 -> V_2 ;
}
static void F_130 ( struct V_1 * V_2 )
{
struct V_7 * V_8 ;
int V_172 ;
bool V_173 = false ;
F_2 ( F_6 () ) ;
F_114 ( V_2 ) ;
F_4 ( V_2 ) ;
while ( ( V_8 = F_85 ( V_2 ) ) )
F_95 ( V_8 ) ;
for ( V_172 = 0 ; V_172 < V_174 ; V_172 ++ )
F_131 (b, &c->lru[i], lru_list) {
F_132 ( ! V_173 ) ;
V_173 = true ;
F_133 ( L_2 ,
( unsigned long long ) V_8 -> V_16 , V_8 -> V_123 , V_172 ) ;
#ifdef F_43
F_134 ( & V_8 -> V_9 , 1 ) ;
V_8 -> V_123 = 0 ;
#endif
}
#ifdef F_43
while ( ( V_8 = F_85 ( V_2 ) ) )
F_95 ( V_8 ) ;
#endif
for ( V_172 = 0 ; V_172 < V_174 ; V_172 ++ )
F_2 ( ! F_79 ( & V_2 -> V_60 [ V_172 ] ) ) ;
F_9 ( V_2 ) ;
}
static bool F_135 ( struct V_7 * V_8 , T_2 V_175 )
{
if ( ! ( V_175 & V_176 ) ) {
if ( F_69 ( V_124 , & V_8 -> V_113 ) ||
F_69 ( V_112 , & V_8 -> V_113 ) ||
F_69 ( V_116 , & V_8 -> V_113 ) )
return false ;
}
if ( V_8 -> V_123 )
return false ;
F_83 ( V_8 ) ;
F_47 ( V_8 ) ;
F_95 ( V_8 ) ;
return true ;
}
static unsigned long F_136 ( struct V_1 * V_2 )
{
unsigned long V_177 = F_25 ( V_178 ) ;
return V_177 >> ( V_2 -> V_103 + V_99 ) ;
}
static unsigned long F_137 ( struct V_1 * V_2 , unsigned long V_179 ,
T_2 V_42 )
{
int V_180 ;
struct V_7 * V_8 , * V_140 ;
unsigned long V_181 = 0 ;
unsigned long V_85 = V_179 ;
unsigned long V_182 = F_136 ( V_2 ) ;
for ( V_180 = 0 ; V_180 < V_174 ; V_180 ++ ) {
F_98 (b, tmp, &c->lru[l], lru_list) {
if ( F_135 ( V_8 , V_42 ) )
V_181 ++ ;
if ( ! -- V_179 || ( ( V_85 - V_181 ) <= V_182 ) )
return V_181 ;
F_81 () ;
}
}
return V_181 ;
}
static unsigned long
F_138 ( struct V_183 * V_184 , struct V_185 * V_186 )
{
struct V_1 * V_2 ;
unsigned long V_181 ;
V_2 = F_14 ( V_184 , struct V_1 , V_183 ) ;
if ( V_186 -> V_42 & V_176 )
F_4 ( V_2 ) ;
else if ( ! F_7 ( V_2 ) )
return V_187 ;
V_181 = F_137 ( V_2 , V_186 -> V_179 , V_186 -> V_42 ) ;
F_9 ( V_2 ) ;
return V_181 ;
}
static unsigned long
F_139 ( struct V_183 * V_184 , struct V_185 * V_186 )
{
struct V_1 * V_2 = F_14 ( V_184 , struct V_1 , V_183 ) ;
return F_25 ( V_2 -> V_57 [ V_141 ] ) + F_25 ( V_2 -> V_57 [ V_147 ] ) ;
}
struct V_1 * F_140 ( struct V_188 * V_84 , unsigned V_45 ,
unsigned V_136 , unsigned V_55 ,
void (* V_138)( struct V_7 * ) ,
void (* V_106)( struct V_7 * ) )
{
int V_73 ;
struct V_1 * V_2 ;
unsigned V_172 ;
F_2 ( V_45 < 1 << V_99 ||
( V_45 & ( V_45 - 1 ) ) ) ;
V_2 = F_141 ( sizeof( * V_2 ) , V_189 ) ;
if ( ! V_2 ) {
V_73 = - V_190 ;
goto V_191;
}
V_2 -> V_19 = V_192 ;
V_2 -> V_84 = V_84 ;
V_2 -> V_45 = V_45 ;
V_2 -> V_103 = F_142 ( V_45 ) - V_99 ;
V_2 -> V_51 = ( F_142 ( V_45 ) >= V_193 ) ?
F_142 ( V_45 ) - V_193 : 0 ;
V_2 -> V_4 = ( F_142 ( V_45 ) < V_193 ?
V_193 - F_142 ( V_45 ) : 0 ) ;
V_2 -> V_55 = V_55 ;
V_2 -> V_138 = V_138 ;
V_2 -> V_106 = V_106 ;
for ( V_172 = 0 ; V_172 < V_174 ; V_172 ++ ) {
F_143 ( & V_2 -> V_60 [ V_172 ] ) ;
V_2 -> V_57 [ V_172 ] = 0 ;
}
F_144 ( & V_2 -> V_6 ) ;
F_143 ( & V_2 -> V_136 ) ;
V_2 -> V_137 = V_136 ;
V_2 -> V_145 = V_194 ;
F_145 ( & V_2 -> V_127 ) ;
V_2 -> V_111 = 0 ;
V_2 -> V_81 = F_146 () ;
if ( F_147 ( V_2 -> V_81 ) ) {
V_73 = F_148 ( V_2 -> V_81 ) ;
goto V_195;
}
F_149 ( & V_36 ) ;
if ( V_2 -> V_4 ) {
if ( ! F_150 ( V_2 ) ) {
F_150 ( V_2 ) = F_151 ( V_189 , L_3 , V_2 -> V_45 ) ;
if ( ! F_150 ( V_2 ) ) {
V_73 = - V_190 ;
F_10 ( & V_36 ) ;
goto V_196;
}
}
if ( ! F_29 ( V_2 ) ) {
F_29 ( V_2 ) = F_152 ( F_150 ( V_2 ) ,
V_2 -> V_45 ,
V_2 -> V_45 , 0 , NULL ) ;
if ( ! F_29 ( V_2 ) ) {
V_73 = - V_190 ;
F_10 ( & V_36 ) ;
goto V_196;
}
}
}
F_10 ( & V_36 ) ;
while ( V_2 -> V_137 ) {
struct V_7 * V_8 = F_40 ( V_2 , V_189 ) ;
if ( ! V_8 ) {
V_73 = - V_190 ;
goto V_197;
}
F_95 ( V_8 ) ;
}
F_149 ( & V_36 ) ;
V_37 ++ ;
F_46 ( & V_2 -> V_198 , & V_199 ) ;
F_23 () ;
F_10 ( & V_36 ) ;
V_2 -> V_183 . V_200 = F_139 ;
V_2 -> V_183 . V_201 = F_138 ;
V_2 -> V_183 . V_202 = 1 ;
V_2 -> V_183 . V_203 = 0 ;
F_153 ( & V_2 -> V_183 ) ;
return V_2 ;
V_197:
V_196:
while ( ! F_79 ( & V_2 -> V_136 ) ) {
struct V_7 * V_8 = F_80 ( V_2 -> V_136 . V_122 ,
struct V_7 , V_59 ) ;
F_48 ( & V_8 -> V_59 ) ;
F_44 ( V_8 ) ;
}
F_154 ( V_2 -> V_81 ) ;
V_195:
F_42 ( V_2 ) ;
V_191:
return F_106 ( V_73 ) ;
}
void F_155 ( struct V_1 * V_2 )
{
unsigned V_172 ;
F_130 ( V_2 ) ;
F_156 ( & V_2 -> V_183 ) ;
F_149 ( & V_36 ) ;
F_48 ( & V_2 -> V_198 ) ;
V_37 -- ;
F_23 () ;
F_10 ( & V_36 ) ;
F_2 ( ! F_157 ( & V_2 -> V_19 ) ) ;
F_2 ( V_2 -> V_137 ) ;
while ( ! F_79 ( & V_2 -> V_136 ) ) {
struct V_7 * V_8 = F_80 ( V_2 -> V_136 . V_122 ,
struct V_7 , V_59 ) ;
F_48 ( & V_8 -> V_59 ) ;
F_44 ( V_8 ) ;
}
for ( V_172 = 0 ; V_172 < V_174 ; V_172 ++ )
if ( V_2 -> V_57 [ V_172 ] )
F_133 ( L_4 , V_172 , V_2 -> V_57 [ V_172 ] ) ;
for ( V_172 = 0 ; V_172 < V_174 ; V_172 ++ )
F_2 ( V_2 -> V_57 [ V_172 ] ) ;
F_154 ( V_2 -> V_81 ) ;
F_42 ( V_2 ) ;
}
void F_158 ( struct V_1 * V_2 , T_1 V_104 )
{
V_2 -> V_104 = V_104 ;
}
static unsigned F_159 ( void )
{
unsigned V_204 = F_25 ( V_205 ) ;
if ( V_204 > V_206 / V_207 )
V_204 = V_206 / V_207 ;
return V_204 * V_207 ;
}
static bool F_160 ( struct V_7 * V_8 , unsigned long V_208 )
{
return F_161 ( V_62 , V_8 -> V_61 + V_208 ) ;
}
static void F_162 ( struct V_1 * V_2 , unsigned long V_208 )
{
struct V_7 * V_8 , * V_140 ;
unsigned long V_182 = F_136 ( V_2 ) ;
unsigned long V_85 ;
F_104 ( V_115 ) ;
F_4 ( V_2 ) ;
F_100 ( V_2 , & V_115 ) ;
if ( F_66 ( ! F_79 ( & V_115 ) ) ) {
F_9 ( V_2 ) ;
F_77 ( & V_115 ) ;
F_4 ( V_2 ) ;
}
V_85 = V_2 -> V_57 [ V_141 ] + V_2 -> V_57 [ V_147 ] ;
F_98 (b, tmp, &c->lru[LIST_CLEAN], lru_list) {
if ( V_85 <= V_182 )
break;
if ( ! F_160 ( V_8 , V_208 ) )
break;
if ( F_135 ( V_8 , 0 ) )
V_85 -- ;
F_81 () ;
}
F_9 ( V_2 ) ;
}
static void F_163 ( void )
{
unsigned long V_209 = F_159 () ;
struct V_1 * V_2 ;
F_149 ( & V_36 ) ;
F_23 () ;
F_131 (c, &dm_bufio_all_clients, client_list)
F_162 ( V_2 , V_209 ) ;
F_10 ( & V_36 ) ;
}
static void F_164 ( struct V_210 * V_211 )
{
F_163 () ;
F_165 ( V_212 , & V_213 ,
V_214 * V_207 ) ;
}
static int T_5 F_166 ( void )
{
T_6 V_86 ;
V_30 = 0 ;
V_31 = 0 ;
V_32 = 0 ;
V_34 = 0 ;
memset ( & V_5 , 0 , sizeof V_5 ) ;
memset ( & V_215 , 0 , sizeof V_215 ) ;
V_86 = ( T_6 ) ( ( V_216 - V_217 ) *
V_218 / 100 ) << V_193 ;
if ( V_86 > V_219 )
V_86 = V_219 ;
#ifdef F_167
if ( V_86 > ( V_220 - V_221 ) * V_222 / 100 )
V_86 = ( V_220 - V_221 ) * V_222 / 100 ;
#endif
V_40 = V_86 ;
F_149 ( & V_36 ) ;
F_23 () ;
F_10 ( & V_36 ) ;
V_212 = F_168 ( L_5 , V_223 , 0 ) ;
if ( ! V_212 )
return - V_190 ;
F_169 ( & V_213 , F_164 ) ;
F_165 ( V_212 , & V_213 ,
V_214 * V_207 ) ;
return 0 ;
}
static void T_7 F_170 ( void )
{
int V_224 = 0 ;
int V_172 ;
F_171 ( & V_213 ) ;
F_172 ( V_212 ) ;
for ( V_172 = 0 ; V_172 < F_3 ( V_5 ) ; V_172 ++ )
F_173 ( V_5 [ V_172 ] ) ;
for ( V_172 = 0 ; V_172 < F_3 ( V_215 ) ; V_172 ++ )
F_42 ( V_215 [ V_172 ] ) ;
if ( V_37 ) {
F_38 ( L_6 ,
V_225 , V_37 ) ;
V_224 = 1 ;
}
if ( V_34 ) {
F_38 ( L_7 ,
V_225 , V_34 ) ;
V_224 = 1 ;
}
if ( V_31 ) {
F_38 ( L_8 ,
V_225 , V_31 ) ;
V_224 = 1 ;
}
if ( V_32 ) {
F_38 ( L_9 ,
V_225 , V_32 ) ;
V_224 = 1 ;
}
F_2 ( V_224 ) ;
}
