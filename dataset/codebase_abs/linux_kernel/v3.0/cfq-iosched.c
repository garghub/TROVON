static struct V_1 * F_1 ( struct V_2 * V_3 ,
enum V_4 V_5 ,
enum V_6 type )
{
if ( ! V_3 )
return NULL ;
if ( V_5 == V_7 )
return & V_3 -> V_8 ;
return & V_3 -> V_9 [ V_5 ] [ type ] ;
}
static inline enum V_4 F_2 ( struct V_10 * V_11 )
{
if ( F_3 ( V_11 ) )
return V_7 ;
if ( F_4 ( V_11 ) )
return V_12 ;
return V_13 ;
}
static enum V_6 F_5 ( struct V_10 * V_11 )
{
if ( ! F_6 ( V_11 ) )
return V_14 ;
if ( ! F_7 ( V_11 ) )
return V_15 ;
return V_16 ;
}
static inline int F_8 ( enum V_4 V_17 ,
struct V_18 * V_19 ,
struct V_2 * V_3 )
{
if ( V_17 == V_7 )
return V_3 -> V_8 . V_20 ;
return V_3 -> V_9 [ V_17 ] [ V_14 ] . V_20
+ V_3 -> V_9 [ V_17 ] [ V_15 ] . V_20
+ V_3 -> V_9 [ V_17 ] [ V_16 ] . V_20 ;
}
static inline int F_9 ( struct V_18 * V_19 ,
struct V_2 * V_3 )
{
return V_3 -> V_9 [ V_12 ] [ V_14 ] . V_20
+ V_3 -> V_9 [ V_13 ] [ V_14 ] . V_20 ;
}
static inline struct V_10 * F_10 ( struct V_21 * V_22 ,
bool V_23 )
{
return V_22 -> V_11 [ V_23 ] ;
}
static inline void F_11 ( struct V_21 * V_22 ,
struct V_10 * V_11 , bool V_23 )
{
V_22 -> V_11 [ V_23 ] = V_11 ;
}
static inline void * F_12 ( struct V_18 * V_19 )
{
return ( void * ) ( V_19 -> V_24 << V_25 | V_26 ) ;
}
static inline struct V_18 * F_13 ( struct V_21 * V_22 )
{
struct V_18 * V_19 = V_22 -> V_27 ;
if ( F_14 ( ( unsigned long ) V_19 & V_26 ) )
return NULL ;
return V_19 ;
}
static inline bool F_15 ( struct V_28 * V_28 )
{
return F_16 ( V_28 ) == V_29 || ( V_28 -> V_30 & V_31 ) ;
}
static inline void F_17 ( struct V_18 * V_19 )
{
if ( V_19 -> V_32 ) {
F_18 ( V_19 , L_1 ) ;
F_19 ( V_19 -> V_33 , & V_19 -> V_34 ) ;
}
}
static inline int F_20 ( struct V_18 * V_19 , bool V_35 ,
unsigned short V_5 )
{
const int V_36 = V_19 -> V_37 [ V_35 ] ;
F_21 ( V_5 >= V_38 ) ;
return V_36 + ( V_36 / V_39 * ( 4 - V_5 ) ) ;
}
static inline int
F_22 ( struct V_18 * V_19 , struct V_10 * V_11 )
{
return F_20 ( V_19 , F_6 ( V_11 ) , V_11 -> V_40 ) ;
}
static inline T_1 F_23 ( unsigned long V_41 , struct V_2 * V_3 )
{
T_1 V_42 = V_41 << V_43 ;
V_42 = V_42 * V_44 ;
F_24 ( V_42 , V_3 -> V_45 ) ;
return V_42 ;
}
static inline T_1 F_25 ( T_1 V_46 , T_1 V_47 )
{
T_2 V_41 = ( T_2 ) ( V_47 - V_46 ) ;
if ( V_41 > 0 )
V_46 = V_47 ;
return V_46 ;
}
static inline T_1 V_46 ( T_1 V_46 , T_1 V_47 )
{
T_2 V_41 = ( T_2 ) ( V_47 - V_46 ) ;
if ( V_41 < 0 )
V_46 = V_47 ;
return V_46 ;
}
static void F_26 ( struct V_1 * V_48 )
{
struct V_2 * V_3 ;
if ( V_48 -> V_49 ) {
V_3 = F_27 ( V_48 -> V_49 ) ;
V_48 -> V_46 = F_25 ( V_48 -> V_46 ,
V_3 -> V_47 ) ;
}
}
static inline unsigned F_28 ( struct V_18 * V_19 ,
struct V_2 * V_3 , bool V_50 )
{
unsigned V_51 , V_52 ;
unsigned V_53 = V_54 - 1 ;
unsigned V_55 = V_54 / 2 ;
unsigned V_56 = F_8 ( V_50 , V_19 , V_3 ) ;
V_51 = F_29 ( V_3 -> V_57 [ V_50 ] , V_56 ) ;
V_52 = F_30 ( V_3 -> V_57 [ V_50 ] , V_56 ) ;
V_3 -> V_57 [ V_50 ] = ( V_53 * V_52 + V_51 + V_55 ) /
V_54 ;
return V_3 -> V_57 [ V_50 ] ;
}
static inline unsigned
F_31 ( struct V_18 * V_19 , struct V_2 * V_3 )
{
struct V_1 * V_48 = & V_19 -> V_58 ;
return V_59 * V_3 -> V_45 / V_48 -> V_60 ;
}
static inline unsigned
F_32 ( struct V_18 * V_19 , struct V_10 * V_11 )
{
unsigned V_61 = F_22 ( V_19 , V_11 ) ;
if ( V_19 -> V_62 ) {
unsigned V_63 = F_28 ( V_19 , V_11 -> V_3 ,
F_4 ( V_11 ) ) ;
unsigned V_64 = V_19 -> V_37 [ 1 ] ;
unsigned V_65 = V_64 * V_63 ;
unsigned V_66 = F_31 ( V_19 , V_11 -> V_3 ) ;
if ( V_65 > V_66 ) {
unsigned V_67 = 2 * V_19 -> V_68 ;
unsigned V_69 =
F_29 ( V_61 , V_67 * V_61 / V_64 ) ;
V_61 = F_30 ( V_61 * V_66 / V_65 ,
V_69 ) ;
}
}
return V_61 ;
}
static inline void
F_33 ( struct V_18 * V_19 , struct V_10 * V_11 )
{
unsigned V_61 = F_32 ( V_19 , V_11 ) ;
V_11 -> V_70 = V_71 ;
V_11 -> V_72 = V_71 + V_61 ;
V_11 -> V_73 = V_61 ;
F_34 ( V_19 , V_11 , L_2 , V_11 -> V_72 - V_71 ) ;
}
static inline bool F_35 ( struct V_10 * V_11 )
{
if ( F_36 ( V_11 ) )
return false ;
if ( F_37 ( V_71 , V_11 -> V_72 ) )
return false ;
return true ;
}
static struct V_74 *
F_38 ( struct V_18 * V_19 , struct V_74 * V_75 , struct V_74 * V_76 , T_3 V_77 )
{
T_3 V_78 , V_79 , V_80 = 0 , V_81 = 0 ;
unsigned long V_82 ;
#define F_39 0x01
#define F_40 0x02
unsigned V_83 = 0 ;
if ( V_75 == NULL || V_75 == V_76 )
return V_76 ;
if ( V_76 == NULL )
return V_75 ;
if ( F_41 ( V_75 ) != F_41 ( V_76 ) )
return F_41 ( V_75 ) ? V_75 : V_76 ;
if ( ( V_75 -> V_84 ^ V_76 -> V_84 ) & V_85 )
return V_75 -> V_84 & V_85 ? V_75 : V_76 ;
V_78 = F_42 ( V_75 ) ;
V_79 = F_42 ( V_76 ) ;
V_82 = V_19 -> V_86 * 2 ;
if ( V_78 >= V_77 )
V_80 = V_78 - V_77 ;
else if ( V_78 + V_82 >= V_77 )
V_80 = ( V_77 - V_78 ) * V_19 -> V_87 ;
else
V_83 |= F_39 ;
if ( V_79 >= V_77 )
V_81 = V_79 - V_77 ;
else if ( V_79 + V_82 >= V_77 )
V_81 = ( V_77 - V_79 ) * V_19 -> V_87 ;
else
V_83 |= F_40 ;
switch ( V_83 ) {
case 0 :
if ( V_80 < V_81 )
return V_75 ;
else if ( V_81 < V_80 )
return V_76 ;
else {
if ( V_78 >= V_79 )
return V_75 ;
else
return V_76 ;
}
case F_40 :
return V_75 ;
case F_39 :
return V_76 ;
case ( F_39 | F_40 ) :
default:
if ( V_78 <= V_79 )
return V_75 ;
else
return V_76 ;
}
}
static struct V_10 * F_43 ( struct V_1 * V_88 )
{
if ( ! V_88 -> V_20 )
return NULL ;
if ( ! V_88 -> V_49 )
V_88 -> V_49 = F_44 ( & V_88 -> V_89 ) ;
if ( V_88 -> V_49 )
return F_45 ( V_88 -> V_49 , struct V_10 , V_90 ) ;
return NULL ;
}
static struct V_2 * F_46 ( struct V_1 * V_88 )
{
if ( ! V_88 -> V_49 )
V_88 -> V_49 = F_44 ( & V_88 -> V_89 ) ;
if ( V_88 -> V_49 )
return F_27 ( V_88 -> V_49 ) ;
return NULL ;
}
static void F_47 ( struct V_90 * V_91 , struct V_92 * V_88 )
{
F_48 ( V_91 , V_88 ) ;
F_49 ( V_91 ) ;
}
static void F_50 ( struct V_90 * V_91 , struct V_1 * V_88 )
{
if ( V_88 -> V_49 == V_91 )
V_88 -> V_49 = NULL ;
F_47 ( V_91 , & V_88 -> V_89 ) ;
-- V_88 -> V_20 ;
}
static struct V_74 *
F_51 ( struct V_18 * V_19 , struct V_10 * V_11 ,
struct V_74 * V_77 )
{
struct V_90 * V_93 = F_52 ( & V_77 -> V_90 ) ;
struct V_90 * V_94 = F_53 ( & V_77 -> V_90 ) ;
struct V_74 * V_95 = NULL , * V_96 = NULL ;
F_54 ( F_55 ( & V_77 -> V_90 ) ) ;
if ( V_94 )
V_96 = F_56 ( V_94 ) ;
if ( V_93 )
V_95 = F_56 ( V_93 ) ;
else {
V_93 = F_44 ( & V_11 -> V_97 ) ;
if ( V_93 && V_93 != & V_77 -> V_90 )
V_95 = F_56 ( V_93 ) ;
}
return F_38 ( V_19 , V_95 , V_96 , F_42 ( V_77 ) ) ;
}
static unsigned long F_57 ( struct V_18 * V_19 ,
struct V_10 * V_11 )
{
return ( V_11 -> V_3 -> V_98 - 1 ) * ( F_20 ( V_19 , 1 , 0 ) -
F_20 ( V_19 , F_6 ( V_11 ) , V_11 -> V_40 ) ) ;
}
static inline T_2
F_58 ( struct V_1 * V_48 , struct V_2 * V_3 )
{
return V_3 -> V_47 - V_48 -> V_46 ;
}
static void
F_59 ( struct V_1 * V_48 , struct V_2 * V_3 )
{
struct V_90 * * V_99 = & V_48 -> V_89 . V_90 ;
struct V_90 * V_100 = NULL ;
struct V_2 * V_101 ;
T_2 V_27 = F_58 ( V_48 , V_3 ) ;
int V_49 = 1 ;
while ( * V_99 != NULL ) {
V_100 = * V_99 ;
V_101 = F_27 ( V_100 ) ;
if ( V_27 < F_58 ( V_48 , V_101 ) )
V_99 = & V_100 -> V_102 ;
else {
V_99 = & V_100 -> V_103 ;
V_49 = 0 ;
}
}
if ( V_49 )
V_48 -> V_49 = & V_3 -> V_90 ;
F_60 ( & V_3 -> V_90 , V_100 , V_99 ) ;
F_61 ( & V_3 -> V_90 , & V_48 -> V_89 ) ;
}
static void
F_62 ( struct V_2 * V_3 )
{
F_54 ( ! F_55 ( & V_3 -> V_90 ) ) ;
if ( V_3 -> V_104 ) {
V_3 -> V_45 = V_3 -> V_105 ;
V_3 -> V_104 = false ;
}
}
static void
F_63 ( struct V_1 * V_48 , struct V_2 * V_3 )
{
F_54 ( ! F_55 ( & V_3 -> V_90 ) ) ;
F_62 ( V_3 ) ;
F_59 ( V_48 , V_3 ) ;
V_48 -> V_60 += V_3 -> V_45 ;
}
static void
F_64 ( struct V_18 * V_19 , struct V_2 * V_3 )
{
struct V_1 * V_48 = & V_19 -> V_58 ;
struct V_2 * V_101 ;
struct V_90 * V_91 ;
V_3 -> V_98 ++ ;
if ( ! F_55 ( & V_3 -> V_90 ) )
return;
V_91 = F_65 ( & V_48 -> V_89 ) ;
if ( V_91 ) {
V_101 = F_27 ( V_91 ) ;
V_3 -> V_47 = V_101 -> V_47 + V_106 ;
} else
V_3 -> V_47 = V_48 -> V_46 ;
F_63 ( V_48 , V_3 ) ;
}
static void
F_66 ( struct V_1 * V_48 , struct V_2 * V_3 )
{
V_48 -> V_60 -= V_3 -> V_45 ;
if ( ! F_55 ( & V_3 -> V_90 ) )
F_50 ( & V_3 -> V_90 , V_48 ) ;
}
static void
F_67 ( struct V_18 * V_19 , struct V_2 * V_3 )
{
struct V_1 * V_48 = & V_19 -> V_58 ;
F_54 ( V_3 -> V_98 < 1 ) ;
V_3 -> V_98 -- ;
if ( V_3 -> V_98 )
return;
F_68 ( V_19 , V_3 , L_3 ) ;
F_66 ( V_48 , V_3 ) ;
V_3 -> V_107 = 0 ;
F_69 ( & V_3 -> V_108 , 1 ) ;
}
static inline unsigned int F_70 ( struct V_10 * V_11 ,
unsigned int * V_109 )
{
unsigned int V_110 ;
if ( ! V_11 -> V_70 || V_11 -> V_70 == V_71 ) {
V_110 = F_71 ( unsigned , ( V_71 - V_11 -> V_111 ) ,
1 ) ;
} else {
V_110 = V_71 - V_11 -> V_70 ;
if ( V_110 > V_11 -> V_73 ) {
* V_109 = V_110 - V_11 -> V_73 ;
V_110 = V_11 -> V_73 ;
}
if ( F_72 ( V_11 -> V_70 , V_11 -> V_111 ) )
* V_109 += V_11 -> V_70 -
V_11 -> V_111 ;
}
return V_110 ;
}
static void F_73 ( struct V_18 * V_19 , struct V_2 * V_3 ,
struct V_10 * V_11 )
{
struct V_1 * V_48 = & V_19 -> V_58 ;
unsigned int V_112 , V_113 , V_114 = 0 ;
int V_115 = V_3 -> V_98 - F_9 ( V_19 , V_3 )
- V_3 -> V_8 . V_20 ;
F_54 ( V_115 < 0 ) ;
V_112 = V_113 = F_70 ( V_11 , & V_114 ) ;
if ( F_74 ( V_19 ) )
V_113 = V_11 -> V_116 ;
else if ( ! F_6 ( V_11 ) && ! V_115 )
V_113 = V_11 -> V_73 ;
F_66 ( V_48 , V_3 ) ;
V_3 -> V_47 += F_23 ( V_113 , V_3 ) ;
F_63 ( V_48 , V_3 ) ;
if ( F_72 ( V_19 -> V_117 , V_71 ) ) {
V_3 -> V_107 = V_19 -> V_117
- V_71 ;
V_3 -> V_118 = V_19 -> V_119 ;
V_3 -> V_120 = V_19 -> V_121 ;
} else
V_3 -> V_107 = 0 ;
F_68 ( V_19 , V_3 , L_4 , V_3 -> V_47 ,
V_48 -> V_46 ) ;
F_34 ( V_11 -> V_19 , V_11 ,
L_5 ,
V_112 , V_11 -> V_116 , V_113 ,
F_74 ( V_19 ) , V_11 -> V_122 ) ;
F_75 ( & V_3 -> V_108 , V_112 ,
V_114 ) ;
F_76 ( & V_3 -> V_108 ) ;
}
static inline struct V_2 * F_77 ( struct V_123 * V_108 )
{
if ( V_108 )
return F_78 ( V_108 , struct V_2 , V_108 ) ;
return NULL ;
}
void F_79 ( void * V_27 , struct V_123 * V_108 ,
unsigned int V_45 )
{
struct V_2 * V_3 = F_77 ( V_108 ) ;
V_3 -> V_105 = V_45 ;
V_3 -> V_104 = true ;
}
static void F_80 ( struct V_18 * V_19 ,
struct V_2 * V_3 , struct V_124 * V_125 )
{
struct V_126 * V_127 = & V_19 -> V_33 -> V_126 ;
unsigned int V_128 , V_129 ;
if ( V_127 -> V_130 ) {
sscanf ( F_81 ( V_127 -> V_130 ) , L_6 , & V_128 , & V_129 ) ;
F_82 ( V_125 , & V_3 -> V_108 ,
( void * ) V_19 , F_83 ( V_128 , V_129 ) ) ;
} else
F_82 ( V_125 , & V_3 -> V_108 ,
( void * ) V_19 , 0 ) ;
V_19 -> V_131 ++ ;
V_3 -> V_45 = F_84 ( V_125 , V_3 -> V_108 . V_130 ) ;
F_85 ( & V_3 -> V_132 , & V_19 -> V_133 ) ;
}
static struct V_2 * F_86 ( struct V_18 * V_19 )
{
struct V_2 * V_3 = NULL ;
int V_134 , V_135 , V_136 ;
struct V_1 * V_48 ;
V_3 = F_87 ( sizeof( * V_3 ) , V_137 , V_19 -> V_33 -> V_99 ) ;
if ( ! V_3 )
return NULL ;
F_88 ( V_3 , V_134 , V_135 , V_48 )
* V_48 = V_138 ;
F_49 ( & V_3 -> V_90 ) ;
V_3 -> V_139 = 1 ;
V_136 = F_89 ( & V_3 -> V_108 ) ;
if ( V_136 ) {
F_90 ( V_3 ) ;
return NULL ;
}
return V_3 ;
}
static struct V_2 *
F_91 ( struct V_18 * V_19 , struct V_124 * V_125 )
{
struct V_2 * V_3 = NULL ;
void * V_27 = V_19 ;
struct V_126 * V_127 = & V_19 -> V_33 -> V_126 ;
unsigned int V_128 , V_129 ;
if ( V_125 == & V_140 )
V_3 = & V_19 -> V_141 ;
else
V_3 = F_77 ( F_92 ( V_125 , V_27 ) ) ;
if ( V_3 && ! V_3 -> V_108 . V_130 && V_127 -> V_130 && F_81 ( V_127 -> V_130 ) ) {
sscanf ( F_81 ( V_127 -> V_130 ) , L_6 , & V_128 , & V_129 ) ;
V_3 -> V_108 . V_130 = F_83 ( V_128 , V_129 ) ;
}
return V_3 ;
}
static struct V_2 * F_93 ( struct V_18 * V_19 )
{
struct V_124 * V_125 ;
struct V_2 * V_3 = NULL , * V_101 = NULL ;
struct V_142 * V_143 = V_19 -> V_33 ;
F_94 () ;
V_125 = F_95 ( V_144 ) ;
V_3 = F_91 ( V_19 , V_125 ) ;
if ( V_3 ) {
F_96 () ;
return V_3 ;
}
F_96 () ;
F_97 ( V_143 -> V_145 ) ;
V_3 = F_86 ( V_19 ) ;
F_98 ( V_143 -> V_145 ) ;
F_94 () ;
V_125 = F_95 ( V_144 ) ;
V_101 = F_91 ( V_19 , V_125 ) ;
if ( V_101 ) {
F_90 ( V_3 ) ;
F_96 () ;
return V_101 ;
}
if ( ! V_3 )
V_3 = & V_19 -> V_141 ;
F_80 ( V_19 , V_3 , V_125 ) ;
F_96 () ;
return V_3 ;
}
static inline struct V_2 * F_99 ( struct V_2 * V_3 )
{
V_3 -> V_139 ++ ;
return V_3 ;
}
static void F_100 ( struct V_10 * V_11 , struct V_2 * V_3 )
{
if ( ! F_6 ( V_11 ) )
V_3 = & V_11 -> V_19 -> V_141 ;
V_11 -> V_3 = V_3 ;
V_11 -> V_3 -> V_139 ++ ;
}
static void F_101 ( struct V_2 * V_3 )
{
struct V_1 * V_48 ;
int V_134 , V_135 ;
F_54 ( V_3 -> V_139 <= 0 ) ;
V_3 -> V_139 -- ;
if ( V_3 -> V_139 )
return;
F_88 (cfqg, i, j, st)
F_54 ( ! F_102 ( & V_48 -> V_89 ) ) ;
F_103 ( V_3 -> V_108 . V_146 ) ;
F_90 ( V_3 ) ;
}
static void F_104 ( struct V_18 * V_19 , struct V_2 * V_3 )
{
F_54 ( F_105 ( & V_3 -> V_132 ) ) ;
F_106 ( & V_3 -> V_132 ) ;
F_101 ( V_3 ) ;
}
static void F_107 ( struct V_18 * V_19 )
{
struct V_147 * V_148 , * V_91 ;
struct V_2 * V_3 ;
F_108 (cfqg, pos, n, &cfqd->cfqg_list, cfqd_node) {
if ( ! F_109 ( & V_3 -> V_108 ) )
F_104 ( V_19 , V_3 ) ;
}
}
void F_110 ( void * V_27 , struct V_123 * V_108 )
{
unsigned long V_149 ;
struct V_18 * V_19 = V_27 ;
F_111 ( V_19 -> V_33 -> V_145 , V_149 ) ;
F_104 ( V_19 , F_77 ( V_108 ) ) ;
F_112 ( V_19 -> V_33 -> V_145 , V_149 ) ;
}
static struct V_2 * F_93 ( struct V_18 * V_19 )
{
return & V_19 -> V_141 ;
}
static inline struct V_2 * F_99 ( struct V_2 * V_3 )
{
return V_3 ;
}
static inline void
F_100 ( struct V_10 * V_11 , struct V_2 * V_3 ) {
V_11 -> V_3 = V_3 ;
}
static void F_107 ( struct V_18 * V_19 ) {}
static inline void F_101 ( struct V_2 * V_3 ) {}
static void F_113 ( struct V_18 * V_19 , struct V_10 * V_11 ,
bool V_150 )
{
struct V_90 * * V_151 , * V_100 ;
struct V_10 * V_152 ;
unsigned long V_153 ;
struct V_1 * V_154 ;
int V_49 ;
int V_155 = 1 ;
V_154 = F_1 ( V_11 -> V_3 , F_2 ( V_11 ) ,
F_5 ( V_11 ) ) ;
if ( F_3 ( V_11 ) ) {
V_153 = V_106 ;
V_100 = F_65 ( & V_154 -> V_89 ) ;
if ( V_100 && V_100 != & V_11 -> V_90 ) {
V_152 = F_45 ( V_100 , struct V_10 , V_90 ) ;
V_153 += V_152 -> V_153 ;
} else
V_153 += V_71 ;
} else if ( ! V_150 ) {
V_153 = F_57 ( V_19 , V_11 ) + V_71 ;
V_153 -= V_11 -> V_156 ;
V_11 -> V_156 = 0 ;
} else {
V_153 = - V_157 ;
V_152 = F_43 ( V_154 ) ;
V_153 += V_152 ? V_152 -> V_153 : V_71 ;
}
if ( ! F_55 ( & V_11 -> V_90 ) ) {
V_155 = 0 ;
if ( V_153 == V_11 -> V_153 &&
V_11 -> V_154 == V_154 )
return;
F_50 ( & V_11 -> V_90 , V_11 -> V_154 ) ;
V_11 -> V_154 = NULL ;
}
V_49 = 1 ;
V_100 = NULL ;
V_11 -> V_154 = V_154 ;
V_151 = & V_154 -> V_89 . V_90 ;
while ( * V_151 ) {
struct V_90 * * V_91 ;
V_100 = * V_151 ;
V_152 = F_45 ( V_100 , struct V_10 , V_90 ) ;
if ( F_37 ( V_153 , V_152 -> V_153 ) )
V_91 = & ( * V_151 ) -> V_102 ;
else {
V_91 = & ( * V_151 ) -> V_103 ;
V_49 = 0 ;
}
V_151 = V_91 ;
}
if ( V_49 )
V_154 -> V_49 = & V_11 -> V_90 ;
V_11 -> V_153 = V_153 ;
F_60 ( & V_11 -> V_90 , V_100 , V_151 ) ;
F_61 ( & V_11 -> V_90 , & V_154 -> V_89 ) ;
V_154 -> V_20 ++ ;
if ( V_150 || ! V_155 )
return;
F_64 ( V_19 , V_11 -> V_3 ) ;
}
static struct V_10 *
F_114 ( struct V_18 * V_19 , struct V_92 * V_88 ,
T_3 V_158 , struct V_90 * * V_159 ,
struct V_90 * * * V_160 )
{
struct V_90 * * V_151 , * V_100 ;
struct V_10 * V_11 = NULL ;
V_100 = NULL ;
V_151 = & V_88 -> V_90 ;
while ( * V_151 ) {
struct V_90 * * V_91 ;
V_100 = * V_151 ;
V_11 = F_45 ( V_100 , struct V_10 , V_161 ) ;
if ( V_158 > F_42 ( V_11 -> V_162 ) )
V_91 = & ( * V_151 ) -> V_103 ;
else if ( V_158 < F_42 ( V_11 -> V_162 ) )
V_91 = & ( * V_151 ) -> V_102 ;
else
break;
V_151 = V_91 ;
V_11 = NULL ;
}
* V_159 = V_100 ;
if ( V_160 )
* V_160 = V_151 ;
return V_11 ;
}
static void F_115 ( struct V_18 * V_19 , struct V_10 * V_11 )
{
struct V_90 * * V_151 , * V_100 ;
struct V_10 * V_152 ;
if ( V_11 -> V_163 ) {
F_48 ( & V_11 -> V_161 , V_11 -> V_163 ) ;
V_11 -> V_163 = NULL ;
}
if ( F_3 ( V_11 ) )
return;
if ( ! V_11 -> V_162 )
return;
V_11 -> V_163 = & V_19 -> V_164 [ V_11 -> V_165 ] ;
V_152 = F_114 ( V_19 , V_11 -> V_163 ,
F_42 ( V_11 -> V_162 ) , & V_100 , & V_151 ) ;
if ( ! V_152 ) {
F_60 ( & V_11 -> V_161 , V_100 , V_151 ) ;
F_61 ( & V_11 -> V_161 , V_11 -> V_163 ) ;
} else
V_11 -> V_163 = NULL ;
}
static void F_116 ( struct V_18 * V_19 , struct V_10 * V_11 )
{
if ( F_117 ( V_11 ) ) {
F_113 ( V_19 , V_11 , 0 ) ;
F_115 ( V_19 , V_11 ) ;
}
}
static void F_118 ( struct V_18 * V_19 , struct V_10 * V_11 )
{
F_34 ( V_19 , V_11 , L_7 ) ;
F_54 ( F_117 ( V_11 ) ) ;
F_119 ( V_11 ) ;
V_19 -> V_32 ++ ;
if ( F_6 ( V_11 ) )
V_19 -> V_166 ++ ;
F_116 ( V_19 , V_11 ) ;
}
static void F_120 ( struct V_18 * V_19 , struct V_10 * V_11 )
{
F_34 ( V_19 , V_11 , L_8 ) ;
F_54 ( ! F_117 ( V_11 ) ) ;
F_121 ( V_11 ) ;
if ( ! F_55 ( & V_11 -> V_90 ) ) {
F_50 ( & V_11 -> V_90 , V_11 -> V_154 ) ;
V_11 -> V_154 = NULL ;
}
if ( V_11 -> V_163 ) {
F_48 ( & V_11 -> V_161 , V_11 -> V_163 ) ;
V_11 -> V_163 = NULL ;
}
F_67 ( V_19 , V_11 -> V_3 ) ;
F_54 ( ! V_19 -> V_32 ) ;
V_19 -> V_32 -- ;
if ( F_6 ( V_11 ) )
V_19 -> V_166 -- ;
}
static void F_122 ( struct V_74 * V_167 )
{
struct V_10 * V_11 = F_123 ( V_167 ) ;
const int V_35 = F_41 ( V_167 ) ;
F_54 ( ! V_11 -> V_168 [ V_35 ] ) ;
V_11 -> V_168 [ V_35 ] -- ;
F_124 ( & V_11 -> V_97 , V_167 ) ;
if ( F_117 ( V_11 ) && F_102 ( & V_11 -> V_97 ) ) {
if ( V_11 -> V_163 ) {
F_48 ( & V_11 -> V_161 , V_11 -> V_163 ) ;
V_11 -> V_163 = NULL ;
}
}
}
static void F_125 ( struct V_74 * V_167 )
{
struct V_10 * V_11 = F_123 ( V_167 ) ;
struct V_18 * V_19 = V_11 -> V_19 ;
struct V_74 * V_169 , * V_96 ;
V_11 -> V_168 [ F_41 ( V_167 ) ] ++ ;
while ( ( V_169 = F_126 ( & V_11 -> V_97 , V_167 ) ) != NULL )
F_127 ( V_19 -> V_33 , V_169 ) ;
if ( ! F_117 ( V_11 ) )
F_118 ( V_19 , V_11 ) ;
V_96 = V_11 -> V_162 ;
V_11 -> V_162 = F_38 ( V_19 , V_11 -> V_162 , V_167 , V_19 -> V_170 ) ;
if ( V_96 != V_11 -> V_162 )
F_115 ( V_19 , V_11 ) ;
F_54 ( ! V_11 -> V_162 ) ;
}
static void F_128 ( struct V_10 * V_11 , struct V_74 * V_167 )
{
F_124 ( & V_11 -> V_97 , V_167 ) ;
V_11 -> V_168 [ F_41 ( V_167 ) ] -- ;
F_129 ( & ( F_130 ( V_167 ) ) -> V_108 ,
F_131 ( V_167 ) , F_41 ( V_167 ) ) ;
F_125 ( V_167 ) ;
F_132 ( & ( F_130 ( V_167 ) ) -> V_108 ,
& V_11 -> V_19 -> V_171 -> V_108 , F_131 ( V_167 ) ,
F_41 ( V_167 ) ) ;
}
static struct V_74 *
F_133 ( struct V_18 * V_19 , struct V_28 * V_28 )
{
struct V_172 * V_173 = V_144 ;
struct V_21 * V_22 ;
struct V_10 * V_11 ;
V_22 = F_134 ( V_19 , V_173 -> V_174 ) ;
if ( ! V_22 )
return NULL ;
V_11 = F_10 ( V_22 , F_15 ( V_28 ) ) ;
if ( V_11 ) {
T_3 V_158 = V_28 -> V_175 + F_135 ( V_28 ) ;
return F_136 ( & V_11 -> V_97 , V_158 ) ;
}
return NULL ;
}
static void F_137 ( struct V_142 * V_143 , struct V_74 * V_167 )
{
struct V_18 * V_19 = V_143 -> V_176 -> V_177 ;
V_19 -> V_178 ++ ;
F_34 ( V_19 , F_123 ( V_167 ) , L_9 ,
V_19 -> V_178 ) ;
V_19 -> V_170 = F_42 ( V_167 ) + F_138 ( V_167 ) ;
}
static void F_139 ( struct V_142 * V_143 , struct V_74 * V_167 )
{
struct V_18 * V_19 = V_143 -> V_176 -> V_177 ;
F_21 ( ! V_19 -> V_178 ) ;
V_19 -> V_178 -- ;
F_34 ( V_19 , F_123 ( V_167 ) , L_10 ,
V_19 -> V_178 ) ;
}
static void F_140 ( struct V_74 * V_167 )
{
struct V_10 * V_11 = F_123 ( V_167 ) ;
if ( V_11 -> V_162 == V_167 )
V_11 -> V_162 = F_51 ( V_11 -> V_19 , V_11 , V_167 ) ;
F_141 ( & V_167 -> V_179 ) ;
F_122 ( V_167 ) ;
V_11 -> V_19 -> V_180 -- ;
F_129 ( & ( F_130 ( V_167 ) ) -> V_108 ,
F_131 ( V_167 ) , F_41 ( V_167 ) ) ;
if ( V_167 -> V_84 & V_85 ) {
F_21 ( ! V_11 -> V_181 ) ;
V_11 -> V_181 -- ;
}
}
static int F_142 ( struct V_142 * V_143 , struct V_74 * * V_182 ,
struct V_28 * V_28 )
{
struct V_18 * V_19 = V_143 -> V_176 -> V_177 ;
struct V_74 * V_183 ;
V_183 = F_133 ( V_19 , V_28 ) ;
if ( V_183 && F_143 ( V_183 , V_28 ) ) {
* V_182 = V_183 ;
return V_184 ;
}
return V_185 ;
}
static void F_144 ( struct V_142 * V_143 , struct V_74 * V_182 ,
int type )
{
if ( type == V_184 ) {
struct V_10 * V_11 = F_123 ( V_182 ) ;
F_128 ( V_11 , V_182 ) ;
}
}
static void F_145 ( struct V_142 * V_143 , struct V_74 * V_182 ,
struct V_28 * V_28 )
{
F_146 ( & ( F_130 ( V_182 ) ) -> V_108 ,
F_16 ( V_28 ) , F_15 ( V_28 ) ) ;
}
static void
F_147 ( struct V_142 * V_143 , struct V_74 * V_167 ,
struct V_74 * V_95 )
{
struct V_10 * V_11 = F_123 ( V_167 ) ;
if ( ! F_148 ( & V_167 -> V_179 ) && ! F_148 ( & V_95 -> V_179 ) &&
F_37 ( F_149 ( V_95 ) , F_149 ( V_167 ) ) ) {
F_150 ( & V_167 -> V_179 , & V_95 -> V_179 ) ;
F_151 ( V_167 , F_149 ( V_95 ) ) ;
}
if ( V_11 -> V_162 == V_95 )
V_11 -> V_162 = V_167 ;
F_140 ( V_95 ) ;
F_146 ( & ( F_130 ( V_167 ) ) -> V_108 ,
F_131 ( V_95 ) , F_41 ( V_95 ) ) ;
}
static int F_152 ( struct V_142 * V_143 , struct V_74 * V_167 ,
struct V_28 * V_28 )
{
struct V_18 * V_19 = V_143 -> V_176 -> V_177 ;
struct V_21 * V_22 ;
struct V_10 * V_11 ;
if ( F_15 ( V_28 ) && ! F_41 ( V_167 ) )
return false ;
V_22 = F_134 ( V_19 , V_144 -> V_174 ) ;
if ( ! V_22 )
return false ;
V_11 = F_10 ( V_22 , F_15 ( V_28 ) ) ;
return V_11 == F_123 ( V_167 ) ;
}
static inline void F_153 ( struct V_18 * V_19 , struct V_10 * V_11 )
{
F_154 ( & V_19 -> V_186 ) ;
F_155 ( & V_11 -> V_3 -> V_108 ) ;
}
static void F_156 ( struct V_18 * V_19 ,
struct V_10 * V_11 )
{
if ( V_11 ) {
F_34 ( V_19 , V_11 , L_11 ,
V_19 -> V_121 , V_19 -> V_119 ) ;
F_157 ( & V_11 -> V_3 -> V_108 ) ;
V_11 -> V_70 = 0 ;
V_11 -> V_111 = V_71 ;
V_11 -> V_73 = 0 ;
V_11 -> V_72 = 0 ;
V_11 -> V_116 = 0 ;
V_11 -> V_122 = 0 ;
F_158 ( V_11 ) ;
F_159 ( V_11 ) ;
F_160 ( V_11 ) ;
F_161 ( V_11 ) ;
F_162 ( V_11 ) ;
F_153 ( V_19 , V_11 ) ;
}
V_19 -> V_187 = V_11 ;
}
static void
F_163 ( struct V_18 * V_19 , struct V_10 * V_11 ,
bool V_188 )
{
F_34 ( V_19 , V_11 , L_12 , V_188 ) ;
if ( F_164 ( V_11 ) )
F_153 ( V_19 , V_11 ) ;
F_158 ( V_11 ) ;
F_165 ( V_11 ) ;
if ( F_166 ( V_11 ) && F_167 ( V_11 ) )
F_168 ( V_11 ) ;
if ( V_188 ) {
if ( F_36 ( V_11 ) )
V_11 -> V_156 = F_32 ( V_19 , V_11 ) ;
else
V_11 -> V_156 = V_11 -> V_72 - V_71 ;
F_34 ( V_19 , V_11 , L_13 , V_11 -> V_156 ) ;
}
F_73 ( V_19 , V_11 -> V_3 , V_11 ) ;
if ( F_117 ( V_11 ) && F_102 ( & V_11 -> V_97 ) )
F_120 ( V_19 , V_11 ) ;
F_116 ( V_19 , V_11 ) ;
if ( V_11 == V_19 -> V_187 )
V_19 -> V_187 = NULL ;
if ( V_19 -> V_189 ) {
F_169 ( V_19 -> V_189 -> V_190 ) ;
V_19 -> V_189 = NULL ;
}
}
static inline void F_170 ( struct V_18 * V_19 , bool V_188 )
{
struct V_10 * V_11 = V_19 -> V_187 ;
if ( V_11 )
F_163 ( V_19 , V_11 , V_188 ) ;
}
static struct V_10 * F_171 ( struct V_18 * V_19 )
{
struct V_1 * V_154 =
F_1 ( V_19 -> V_171 , V_19 -> V_121 ,
V_19 -> V_119 ) ;
if ( ! V_19 -> V_180 )
return NULL ;
if ( ! V_154 )
return NULL ;
if ( F_102 ( & V_154 -> V_89 ) )
return NULL ;
return F_43 ( V_154 ) ;
}
static struct V_10 * F_172 ( struct V_18 * V_19 )
{
struct V_2 * V_3 ;
struct V_10 * V_11 ;
int V_134 , V_135 ;
struct V_1 * V_48 ;
if ( ! V_19 -> V_180 )
return NULL ;
V_3 = F_173 ( V_19 ) ;
if ( ! V_3 )
return NULL ;
F_88 (cfqg, i, j, st)
if ( ( V_11 = F_43 ( V_48 ) ) != NULL )
return V_11 ;
return NULL ;
}
static struct V_10 * F_174 ( struct V_18 * V_19 ,
struct V_10 * V_11 )
{
if ( ! V_11 )
V_11 = F_171 ( V_19 ) ;
F_156 ( V_19 , V_11 ) ;
return V_11 ;
}
static inline T_3 F_175 ( struct V_18 * V_19 ,
struct V_74 * V_167 )
{
if ( F_42 ( V_167 ) >= V_19 -> V_170 )
return F_42 ( V_167 ) - V_19 -> V_170 ;
else
return V_19 -> V_170 - F_42 ( V_167 ) ;
}
static inline int F_176 ( struct V_18 * V_19 , struct V_10 * V_11 ,
struct V_74 * V_167 )
{
return F_175 ( V_19 , V_167 ) <= V_191 ;
}
static struct V_10 * F_177 ( struct V_18 * V_19 ,
struct V_10 * V_192 )
{
struct V_92 * V_88 = & V_19 -> V_164 [ V_192 -> V_165 ] ;
struct V_90 * V_100 , * V_99 ;
struct V_10 * V_152 ;
T_3 V_158 = V_19 -> V_170 ;
if ( F_102 ( V_88 ) )
return NULL ;
V_152 = F_114 ( V_19 , V_88 , V_158 , & V_100 , NULL ) ;
if ( V_152 )
return V_152 ;
V_152 = F_45 ( V_100 , struct V_10 , V_161 ) ;
if ( F_176 ( V_19 , V_192 , V_152 -> V_162 ) )
return V_152 ;
if ( F_42 ( V_152 -> V_162 ) < V_158 )
V_99 = F_52 ( & V_152 -> V_161 ) ;
else
V_99 = F_53 ( & V_152 -> V_161 ) ;
if ( ! V_99 )
return NULL ;
V_152 = F_45 ( V_99 , struct V_10 , V_161 ) ;
if ( F_176 ( V_19 , V_192 , V_152 -> V_162 ) )
return V_152 ;
return NULL ;
}
static struct V_10 * F_178 ( struct V_18 * V_19 ,
struct V_10 * V_192 )
{
struct V_10 * V_11 ;
if ( F_3 ( V_192 ) )
return NULL ;
if ( ! F_6 ( V_192 ) )
return NULL ;
if ( F_167 ( V_192 ) )
return NULL ;
if ( V_192 -> V_3 -> V_98 == 1 )
return NULL ;
V_11 = F_177 ( V_19 , V_192 ) ;
if ( ! V_11 )
return NULL ;
if ( V_192 -> V_3 != V_11 -> V_3 )
return NULL ;
if ( ! F_6 ( V_11 ) )
return NULL ;
if ( F_167 ( V_11 ) )
return NULL ;
if ( F_4 ( V_11 ) != F_4 ( V_192 ) )
return NULL ;
return V_11 ;
}
static bool F_179 ( struct V_18 * V_19 , struct V_10 * V_11 )
{
enum V_4 V_5 = F_2 ( V_11 ) ;
struct V_1 * V_154 = V_11 -> V_154 ;
F_54 ( ! V_154 ) ;
F_54 ( ! V_154 -> V_20 ) ;
if ( ! V_19 -> V_68 )
return false ;
if ( V_5 == V_7 )
return false ;
if ( F_7 ( V_11 ) &&
! ( F_180 ( V_19 -> V_33 ) && V_19 -> V_193 ) )
return true ;
if ( V_154 -> V_20 == 1 && F_6 ( V_11 ) )
return true ;
F_34 ( V_19 , V_11 , L_14 ,
V_154 -> V_20 ) ;
return false ;
}
static void F_181 ( struct V_18 * V_19 )
{
struct V_10 * V_11 = V_19 -> V_187 ;
struct V_21 * V_22 ;
unsigned long V_194 , V_195 = 0 ;
if ( F_180 ( V_19 -> V_33 ) && V_19 -> V_193 )
return;
F_21 ( ! F_102 ( & V_11 -> V_97 ) ) ;
F_21 ( F_36 ( V_11 ) ) ;
if ( ! F_179 ( V_19 , V_11 ) ) {
if ( V_19 -> V_196 )
V_195 = V_19 -> V_196 ;
else
return;
}
if ( V_11 -> V_197 )
return;
V_22 = V_19 -> V_189 ;
if ( ! V_22 || ! F_182 ( & V_22 -> V_190 -> V_198 ) )
return;
if ( F_183 ( V_22 -> V_199 ) &&
( V_11 -> V_72 - V_71 < V_22 -> V_200 ) ) {
F_34 ( V_19 , V_11 , L_15 ,
V_22 -> V_200 ) ;
return;
}
if ( V_195 && V_11 -> V_3 -> V_98 > 1 )
return;
F_184 ( V_11 ) ;
if ( V_195 )
V_194 = V_19 -> V_196 ;
else
V_194 = V_19 -> V_68 ;
F_185 ( & V_19 -> V_186 , V_71 + V_194 ) ;
F_186 ( & V_11 -> V_3 -> V_108 ) ;
F_34 ( V_19 , V_11 , L_16 , V_194 ,
V_195 ? 1 : 0 ) ;
}
static void F_127 ( struct V_142 * V_143 , struct V_74 * V_167 )
{
struct V_18 * V_19 = V_143 -> V_176 -> V_177 ;
struct V_10 * V_11 = F_123 ( V_167 ) ;
F_34 ( V_19 , V_11 , L_17 ) ;
V_11 -> V_162 = F_51 ( V_19 , V_11 , V_167 ) ;
F_140 ( V_167 ) ;
V_11 -> V_197 ++ ;
( F_130 ( V_167 ) ) -> V_197 ++ ;
F_187 ( V_143 , V_167 ) ;
V_19 -> V_201 [ F_6 ( V_11 ) ] ++ ;
V_11 -> V_122 += F_138 ( V_167 ) ;
F_188 ( & V_11 -> V_3 -> V_108 , F_189 ( V_167 ) ,
F_131 ( V_167 ) , F_41 ( V_167 ) ) ;
}
static struct V_74 * F_190 ( struct V_10 * V_11 )
{
struct V_74 * V_167 = NULL ;
if ( F_191 ( V_11 ) )
return NULL ;
F_192 ( V_11 ) ;
if ( F_148 ( & V_11 -> V_202 ) )
return NULL ;
V_167 = F_193 ( V_11 -> V_202 . V_95 ) ;
if ( F_37 ( V_71 , F_149 ( V_167 ) ) )
V_167 = NULL ;
F_34 ( V_11 -> V_19 , V_11 , L_18 , V_167 ) ;
return V_167 ;
}
static inline int
F_194 ( struct V_18 * V_19 , struct V_10 * V_11 )
{
const int V_203 = V_19 -> V_204 ;
F_21 ( V_11 -> V_40 >= V_38 ) ;
return 2 * V_203 * ( V_38 - V_11 -> V_40 ) ;
}
static int F_195 ( struct V_10 * V_11 )
{
int V_205 , V_206 ;
V_206 = V_11 -> V_207 [ V_29 ] + V_11 -> V_207 [ V_208 ] ;
V_205 = V_11 -> V_139 - V_206 ;
F_54 ( V_205 < 0 ) ;
return V_205 ;
}
static void F_196 ( struct V_10 * V_11 , struct V_10 * V_155 )
{
int V_205 , V_209 ;
struct V_10 * V_152 ;
if ( ! F_195 ( V_155 ) )
return;
while ( ( V_152 = V_155 -> V_155 ) ) {
if ( V_152 == V_11 )
return;
V_155 = V_152 ;
}
V_205 = F_195 ( V_11 ) ;
V_209 = F_195 ( V_155 ) ;
if ( V_205 == 0 || V_209 == 0 )
return;
if ( V_209 >= V_205 ) {
V_11 -> V_155 = V_155 ;
V_155 -> V_139 += V_205 ;
} else {
V_155 -> V_155 = V_11 ;
V_11 -> V_139 += V_209 ;
}
}
static enum V_6 F_197 ( struct V_18 * V_19 ,
struct V_2 * V_3 , enum V_4 V_5 )
{
struct V_10 * V_33 ;
int V_134 ;
bool V_210 = false ;
unsigned long V_211 = 0 ;
enum V_6 V_212 = V_15 ;
for ( V_134 = 0 ; V_134 <= V_16 ; ++ V_134 ) {
V_33 = F_43 ( F_1 ( V_3 , V_5 , V_134 ) ) ;
if ( V_33 &&
( ! V_210 || F_37 ( V_33 -> V_153 , V_211 ) ) ) {
V_211 = V_33 -> V_153 ;
V_212 = V_134 ;
V_210 = true ;
}
}
return V_212 ;
}
static void F_198 ( struct V_18 * V_19 , struct V_2 * V_3 )
{
unsigned V_61 ;
unsigned V_20 ;
struct V_1 * V_48 ;
unsigned V_66 ;
enum V_4 V_213 = V_19 -> V_121 ;
if ( F_8 ( V_12 , V_19 , V_3 ) )
V_19 -> V_121 = V_12 ;
else if ( F_8 ( V_13 , V_19 , V_3 ) )
V_19 -> V_121 = V_13 ;
else {
V_19 -> V_121 = V_7 ;
V_19 -> V_117 = V_71 + 1 ;
return;
}
if ( V_213 != V_19 -> V_121 )
goto V_214;
V_48 = F_1 ( V_3 , V_19 -> V_121 , V_19 -> V_119 ) ;
V_20 = V_48 -> V_20 ;
if ( V_20 && ! F_72 ( V_71 , V_19 -> V_117 ) )
return;
V_214:
V_19 -> V_119 =
F_197 ( V_19 , V_3 , V_19 -> V_121 ) ;
V_48 = F_1 ( V_3 , V_19 -> V_121 , V_19 -> V_119 ) ;
V_20 = V_48 -> V_20 ;
V_66 = F_31 ( V_19 , V_3 ) ;
V_61 = V_66 * V_20 /
F_71 ( unsigned , V_3 -> V_57 [ V_19 -> V_121 ] ,
F_8 ( V_19 -> V_121 , V_19 , V_3 ) ) ;
if ( V_19 -> V_119 == V_14 ) {
unsigned int V_215 ;
V_215 = V_59 * F_9 ( V_19 , V_3 ) ;
V_215 = V_215 / V_19 -> V_32 ;
V_61 = F_199 ( unsigned , V_61 , V_215 ) ;
V_61 = V_61 * V_19 -> V_37 [ 0 ] / V_19 -> V_37 [ 1 ] ;
} else
V_61 = F_30 ( V_61 , 2 * V_19 -> V_68 ) ;
V_61 = F_71 ( unsigned , V_61 , V_216 ) ;
F_18 ( V_19 , L_19 , V_61 ) ;
V_19 -> V_117 = V_71 + V_61 ;
}
static struct V_2 * F_173 ( struct V_18 * V_19 )
{
struct V_1 * V_48 = & V_19 -> V_58 ;
struct V_2 * V_3 ;
if ( F_102 ( & V_48 -> V_89 ) )
return NULL ;
V_3 = F_46 ( V_48 ) ;
F_26 ( V_48 ) ;
return V_3 ;
}
static void F_200 ( struct V_18 * V_19 )
{
struct V_2 * V_3 = F_173 ( V_19 ) ;
V_19 -> V_171 = V_3 ;
if ( V_3 -> V_107 ) {
V_19 -> V_117 = V_71 + V_3 -> V_107 ;
V_19 -> V_119 = V_3 -> V_118 ;
V_19 -> V_121 = V_3 -> V_120 ;
} else
V_19 -> V_117 = V_71 - 1 ;
F_198 ( V_19 , V_3 ) ;
}
static struct V_10 * F_201 ( struct V_18 * V_19 )
{
struct V_10 * V_11 , * V_155 = NULL ;
V_11 = V_19 -> V_187 ;
if ( ! V_11 )
goto V_217;
if ( ! V_19 -> V_180 )
return NULL ;
if ( F_202 ( V_11 ) && ! F_102 ( & V_11 -> V_97 ) )
goto V_218;
if ( F_35 ( V_11 ) && ! F_203 ( V_11 ) ) {
if ( V_11 -> V_3 -> V_98 == 1 && F_102 ( & V_11 -> V_97 )
&& V_11 -> V_197 && F_179 ( V_19 , V_11 ) ) {
V_11 = NULL ;
goto V_219;
} else
goto V_220;
}
if ( ! F_102 ( & V_11 -> V_97 ) )
goto V_219;
V_155 = F_178 ( V_19 , V_11 ) ;
if ( V_155 ) {
if ( ! V_11 -> V_155 )
F_196 ( V_11 , V_155 ) ;
goto V_218;
}
if ( F_204 ( & V_19 -> V_186 ) ) {
V_11 = NULL ;
goto V_219;
}
if ( F_167 ( V_11 ) && F_7 ( V_11 ) &&
( F_36 ( V_11 ) ||
( V_11 -> V_72 - V_71 > V_71 - V_11 -> V_70 ) ) ) {
F_205 ( V_11 ) ;
F_206 ( V_11 ) ;
}
if ( V_11 -> V_197 && F_179 ( V_19 , V_11 ) ) {
V_11 = NULL ;
goto V_219;
}
V_220:
if ( V_19 -> V_196 && V_11 -> V_3 -> V_98 == 1
&& V_11 -> V_3 -> V_197 ) {
V_11 = NULL ;
goto V_219;
}
V_218:
F_170 ( V_19 , 0 ) ;
V_217:
if ( ! V_155 )
F_200 ( V_19 ) ;
V_11 = F_174 ( V_19 , V_155 ) ;
V_219:
return V_11 ;
}
static int F_207 ( struct V_10 * V_11 )
{
int V_197 = 0 ;
while ( V_11 -> V_162 ) {
F_127 ( V_11 -> V_19 -> V_33 , V_11 -> V_162 ) ;
V_197 ++ ;
}
F_54 ( ! F_148 ( & V_11 -> V_202 ) ) ;
F_163 ( V_11 -> V_19 , V_11 , 0 ) ;
return V_197 ;
}
static int F_208 ( struct V_18 * V_19 )
{
struct V_10 * V_11 ;
int V_197 = 0 ;
F_170 ( V_19 , 0 ) ;
while ( ( V_11 = F_172 ( V_19 ) ) != NULL ) {
F_156 ( V_19 , V_11 ) ;
V_197 += F_207 ( V_11 ) ;
}
F_54 ( V_19 -> V_32 ) ;
F_18 ( V_19 , L_20 , V_197 ) ;
return V_197 ;
}
static inline bool F_209 ( struct V_18 * V_19 ,
struct V_10 * V_11 )
{
if ( F_36 ( V_11 ) )
return true ;
if ( F_72 ( V_71 + V_19 -> V_68 * V_11 -> V_197 ,
V_11 -> V_72 ) )
return true ;
return false ;
}
static bool F_210 ( struct V_18 * V_19 , struct V_10 * V_11 )
{
unsigned int V_221 ;
if ( F_179 ( V_19 , V_11 ) && V_19 -> V_201 [ V_222 ] )
return false ;
if ( V_19 -> V_201 [ V_223 ] && ! F_6 ( V_11 ) )
return false ;
V_221 = F_71 (unsigned int, cfqd->cfq_quantum / 2 , 1 ) ;
if ( F_3 ( V_11 ) )
V_221 = 1 ;
if ( V_11 -> V_197 >= V_221 ) {
bool V_224 = false ;
if ( F_3 ( V_11 ) )
return false ;
if ( F_6 ( V_11 ) && V_19 -> V_166 == 1 )
V_224 = true ;
if ( V_19 -> V_32 > 1 && F_209 ( V_19 , V_11 ) &&
! V_224 )
return false ;
if ( V_19 -> V_32 == 1 || V_224 )
V_221 = - 1 ;
else
V_221 = V_19 -> V_225 ;
}
if ( ! F_6 ( V_11 ) && V_19 -> V_62 ) {
unsigned long V_226 = V_71 - V_19 -> V_227 ;
unsigned int V_228 ;
V_228 = V_226 / V_19 -> V_37 [ 1 ] ;
if ( ! V_228 && ! V_11 -> V_197 )
V_228 = 1 ;
if ( V_228 < V_221 )
V_221 = V_228 ;
}
return V_11 -> V_197 < V_221 ;
}
static bool F_211 ( struct V_18 * V_19 , struct V_10 * V_11 )
{
struct V_74 * V_167 ;
F_54 ( F_102 ( & V_11 -> V_97 ) ) ;
if ( ! F_210 ( V_19 , V_11 ) )
return false ;
V_167 = F_190 ( V_11 ) ;
if ( ! V_167 )
V_167 = V_11 -> V_162 ;
F_127 ( V_19 -> V_33 , V_167 ) ;
if ( ! V_19 -> V_189 ) {
struct V_21 * V_22 = F_212 ( V_167 ) ;
F_213 ( & V_22 -> V_190 -> V_229 ) ;
V_19 -> V_189 = V_22 ;
}
return true ;
}
static int F_214 ( struct V_142 * V_143 , int V_230 )
{
struct V_18 * V_19 = V_143 -> V_176 -> V_177 ;
struct V_10 * V_11 ;
if ( ! V_19 -> V_32 )
return 0 ;
if ( F_14 ( V_230 ) )
return F_208 ( V_19 ) ;
V_11 = F_201 ( V_19 ) ;
if ( ! V_11 )
return 0 ;
if ( ! F_211 ( V_19 , V_11 ) )
return 0 ;
V_11 -> V_116 ++ ;
F_159 ( V_11 ) ;
if ( V_19 -> V_32 > 1 && ( ( ! F_6 ( V_11 ) &&
V_11 -> V_116 >= F_194 ( V_19 , V_11 ) ) ||
F_3 ( V_11 ) ) ) {
V_11 -> V_72 = V_71 + 1 ;
F_170 ( V_19 , 0 ) ;
}
F_34 ( V_19 , V_11 , L_21 ) ;
return 1 ;
}
static void F_215 ( struct V_10 * V_11 )
{
struct V_18 * V_19 = V_11 -> V_19 ;
struct V_2 * V_3 ;
F_54 ( V_11 -> V_139 <= 0 ) ;
V_11 -> V_139 -- ;
if ( V_11 -> V_139 )
return;
F_34 ( V_19 , V_11 , L_22 ) ;
F_54 ( F_44 ( & V_11 -> V_97 ) ) ;
F_54 ( V_11 -> V_207 [ V_29 ] + V_11 -> V_207 [ V_208 ] ) ;
V_3 = V_11 -> V_3 ;
if ( F_14 ( V_19 -> V_187 == V_11 ) ) {
F_163 ( V_19 , V_11 , 0 ) ;
F_17 ( V_19 ) ;
}
F_54 ( F_117 ( V_11 ) ) ;
F_216 ( V_231 , V_11 ) ;
F_101 ( V_3 ) ;
}
static void
F_217 ( struct V_174 * V_190 ,
void (* F_218)( struct V_174 * , struct V_21 * ) )
{
struct V_21 * V_22 ;
struct V_147 * V_91 ;
F_94 () ;
F_219 (cic, n, &ioc->cic_list, cic_list)
F_218 ( V_190 , V_22 ) ;
F_96 () ;
}
static void F_220 ( struct V_232 * V_233 )
{
struct V_21 * V_22 ;
V_22 = F_78 ( V_233 , struct V_21 , V_232 ) ;
F_216 ( V_234 , V_22 ) ;
F_221 ( V_235 ) ;
if ( V_236 ) {
F_222 ( & V_237 ) ;
if ( V_236 && ! F_223 ( V_235 ) ) {
F_224 ( V_236 ) ;
V_236 = NULL ;
}
F_225 ( & V_237 ) ;
}
}
static void F_226 ( struct V_21 * V_22 )
{
F_227 ( & V_22 -> V_232 , F_220 ) ;
}
static void F_228 ( struct V_174 * V_190 , struct V_21 * V_22 )
{
unsigned long V_149 ;
unsigned long V_238 = ( unsigned long ) V_22 -> V_27 ;
F_54 ( ! ( V_238 & V_26 ) ) ;
F_111 ( & V_190 -> V_239 , V_149 ) ;
F_229 ( & V_190 -> V_240 , V_238 >> V_25 ) ;
F_230 ( & V_22 -> V_241 ) ;
F_112 ( & V_190 -> V_239 , V_149 ) ;
F_226 ( V_22 ) ;
}
static void F_231 ( struct V_174 * V_190 )
{
F_217 ( V_190 , F_228 ) ;
}
static void F_232 ( struct V_10 * V_11 )
{
struct V_10 * V_152 , * V_95 ;
V_152 = V_11 -> V_155 ;
while ( V_152 ) {
if ( V_152 == V_11 ) {
F_233 ( 1 , L_23 ) ;
break;
}
V_95 = V_152 -> V_155 ;
F_215 ( V_152 ) ;
V_152 = V_95 ;
}
}
static void F_234 ( struct V_18 * V_19 , struct V_10 * V_11 )
{
if ( F_14 ( V_11 == V_19 -> V_187 ) ) {
F_163 ( V_19 , V_11 , 0 ) ;
F_17 ( V_19 ) ;
}
F_232 ( V_11 ) ;
F_215 ( V_11 ) ;
}
static void F_235 ( struct V_18 * V_19 ,
struct V_21 * V_22 )
{
struct V_174 * V_190 = V_22 -> V_190 ;
F_141 ( & V_22 -> V_242 ) ;
F_236 () ;
V_22 -> V_27 = F_12 ( V_19 ) ;
F_94 () ;
if ( F_237 ( V_190 -> V_243 ) == V_22 ) {
F_96 () ;
F_222 ( & V_190 -> V_239 ) ;
F_238 ( V_190 -> V_243 , NULL ) ;
F_225 ( & V_190 -> V_239 ) ;
} else
F_96 () ;
if ( V_22 -> V_11 [ V_222 ] ) {
F_234 ( V_19 , V_22 -> V_11 [ V_222 ] ) ;
V_22 -> V_11 [ V_222 ] = NULL ;
}
if ( V_22 -> V_11 [ V_223 ] ) {
F_234 ( V_19 , V_22 -> V_11 [ V_223 ] ) ;
V_22 -> V_11 [ V_223 ] = NULL ;
}
}
static void F_239 ( struct V_174 * V_190 ,
struct V_21 * V_22 )
{
struct V_18 * V_19 = F_13 ( V_22 ) ;
if ( V_19 ) {
struct V_142 * V_143 = V_19 -> V_33 ;
unsigned long V_149 ;
F_111 ( V_143 -> V_145 , V_149 ) ;
F_240 () ;
if ( V_22 -> V_27 == V_19 )
F_235 ( V_19 , V_22 ) ;
F_112 ( V_143 -> V_145 , V_149 ) ;
}
}
static void F_241 ( struct V_174 * V_190 )
{
F_217 ( V_190 , F_239 ) ;
}
static struct V_21 *
F_242 ( struct V_18 * V_19 , T_4 V_244 )
{
struct V_21 * V_22 ;
V_22 = F_243 ( V_234 , V_244 | V_245 ,
V_19 -> V_33 -> V_99 ) ;
if ( V_22 ) {
V_22 -> V_246 = V_71 ;
F_244 ( & V_22 -> V_242 ) ;
F_245 ( & V_22 -> V_241 ) ;
V_22 -> V_247 = F_231 ;
V_22 -> exit = F_241 ;
F_246 ( V_235 ) ;
}
return V_22 ;
}
static void F_247 ( struct V_10 * V_11 , struct V_174 * V_190 )
{
struct V_172 * V_173 = V_144 ;
int V_248 ;
if ( ! F_248 ( V_11 ) )
return;
V_248 = F_249 ( V_190 -> V_40 ) ;
switch ( V_248 ) {
default:
F_250 ( V_249 L_24 , V_248 ) ;
case V_250 :
V_11 -> V_40 = F_251 ( V_173 ) ;
V_11 -> V_248 = F_252 ( V_173 ) ;
break;
case V_251 :
V_11 -> V_40 = F_253 ( V_190 ) ;
V_11 -> V_248 = V_251 ;
break;
case V_252 :
V_11 -> V_40 = F_253 ( V_190 ) ;
V_11 -> V_248 = V_252 ;
break;
case V_253 :
V_11 -> V_248 = V_253 ;
V_11 -> V_40 = 7 ;
F_206 ( V_11 ) ;
break;
}
V_11 -> V_165 = V_11 -> V_40 ;
V_11 -> V_254 = V_11 -> V_248 ;
F_254 ( V_11 ) ;
}
static void F_255 ( struct V_174 * V_190 , struct V_21 * V_22 )
{
struct V_18 * V_19 = F_13 ( V_22 ) ;
struct V_10 * V_11 ;
unsigned long V_149 ;
if ( F_14 ( ! V_19 ) )
return;
F_111 ( V_19 -> V_33 -> V_145 , V_149 ) ;
V_11 = V_22 -> V_11 [ V_222 ] ;
if ( V_11 ) {
struct V_10 * V_155 ;
V_155 = F_256 ( V_19 , V_222 , V_22 -> V_190 ,
V_137 ) ;
if ( V_155 ) {
V_22 -> V_11 [ V_222 ] = V_155 ;
F_215 ( V_11 ) ;
}
}
V_11 = V_22 -> V_11 [ V_223 ] ;
if ( V_11 )
F_257 ( V_11 ) ;
F_112 ( V_19 -> V_33 -> V_145 , V_149 ) ;
}
static void F_258 ( struct V_174 * V_190 )
{
F_217 ( V_190 , F_255 ) ;
V_190 -> V_255 = 0 ;
}
static void F_259 ( struct V_18 * V_19 , struct V_10 * V_11 ,
T_5 V_256 , bool V_23 )
{
F_49 ( & V_11 -> V_90 ) ;
F_49 ( & V_11 -> V_161 ) ;
F_244 ( & V_11 -> V_202 ) ;
V_11 -> V_139 = 0 ;
V_11 -> V_19 = V_19 ;
F_257 ( V_11 ) ;
if ( V_23 ) {
if ( ! F_3 ( V_11 ) )
F_260 ( V_11 ) ;
F_261 ( V_11 ) ;
}
V_11 -> V_256 = V_256 ;
}
static void F_262 ( struct V_174 * V_190 , struct V_21 * V_22 )
{
struct V_10 * V_257 = F_10 ( V_22 , 1 ) ;
struct V_18 * V_19 = F_13 ( V_22 ) ;
unsigned long V_149 ;
struct V_142 * V_143 ;
if ( F_14 ( ! V_19 ) )
return;
V_143 = V_19 -> V_33 ;
F_111 ( V_143 -> V_145 , V_149 ) ;
if ( V_257 ) {
F_34 ( V_19 , V_257 , L_25 ) ;
F_11 ( V_22 , NULL , 1 ) ;
F_215 ( V_257 ) ;
}
F_112 ( V_143 -> V_145 , V_149 ) ;
}
static void F_263 ( struct V_174 * V_190 )
{
F_217 ( V_190 , F_262 ) ;
V_190 -> V_258 = 0 ;
}
static struct V_10 *
F_264 ( struct V_18 * V_19 , bool V_23 ,
struct V_174 * V_190 , T_4 V_244 )
{
struct V_10 * V_11 , * V_155 = NULL ;
struct V_21 * V_22 ;
struct V_2 * V_3 ;
V_259:
V_3 = F_93 ( V_19 ) ;
V_22 = F_134 ( V_19 , V_190 ) ;
V_11 = F_10 ( V_22 , V_23 ) ;
if ( ! V_11 || V_11 == & V_19 -> V_260 ) {
V_11 = NULL ;
if ( V_155 ) {
V_11 = V_155 ;
V_155 = NULL ;
} else if ( V_244 & V_261 ) {
F_97 ( V_19 -> V_33 -> V_145 ) ;
V_155 = F_243 ( V_231 ,
V_244 | V_245 ,
V_19 -> V_33 -> V_99 ) ;
F_98 ( V_19 -> V_33 -> V_145 ) ;
if ( V_155 )
goto V_259;
} else {
V_11 = F_243 ( V_231 ,
V_244 | V_245 ,
V_19 -> V_33 -> V_99 ) ;
}
if ( V_11 ) {
F_259 ( V_19 , V_11 , V_144 -> V_256 , V_23 ) ;
F_247 ( V_11 , V_190 ) ;
F_100 ( V_11 , V_3 ) ;
F_34 ( V_19 , V_11 , L_26 ) ;
} else
V_11 = & V_19 -> V_260 ;
}
if ( V_155 )
F_216 ( V_231 , V_155 ) ;
return V_11 ;
}
static struct V_10 * *
F_265 ( struct V_18 * V_19 , int V_248 , int V_40 )
{
switch ( V_248 ) {
case V_251 :
return & V_19 -> V_262 [ 0 ] [ V_40 ] ;
case V_252 :
return & V_19 -> V_262 [ 1 ] [ V_40 ] ;
case V_253 :
return & V_19 -> V_263 ;
default:
F_266 () ;
}
}
static struct V_10 *
F_256 ( struct V_18 * V_19 , bool V_23 , struct V_174 * V_190 ,
T_4 V_244 )
{
const int V_40 = F_253 ( V_190 ) ;
const int V_248 = F_267 ( V_190 ) ;
struct V_10 * * V_262 = NULL ;
struct V_10 * V_11 = NULL ;
if ( ! V_23 ) {
V_262 = F_265 ( V_19 , V_248 , V_40 ) ;
V_11 = * V_262 ;
}
if ( ! V_11 )
V_11 = F_264 ( V_19 , V_23 , V_190 , V_244 ) ;
if ( ! V_23 && ! ( * V_262 ) ) {
V_11 -> V_139 ++ ;
* V_262 = V_11 ;
}
V_11 -> V_139 ++ ;
return V_11 ;
}
static void
F_268 ( struct V_18 * V_19 , struct V_174 * V_190 ,
struct V_21 * V_22 )
{
unsigned long V_149 ;
F_21 ( ! F_148 ( & V_22 -> V_242 ) ) ;
F_54 ( V_22 -> V_27 != F_12 ( V_19 ) ) ;
F_111 ( & V_190 -> V_239 , V_149 ) ;
F_54 ( F_269 ( V_190 -> V_243 ,
F_270 ( & V_190 -> V_239 ) ) == V_22 ) ;
F_229 ( & V_190 -> V_240 , V_19 -> V_24 ) ;
F_230 ( & V_22 -> V_241 ) ;
F_112 ( & V_190 -> V_239 , V_149 ) ;
F_226 ( V_22 ) ;
}
static struct V_21 *
F_134 ( struct V_18 * V_19 , struct V_174 * V_190 )
{
struct V_21 * V_22 ;
unsigned long V_149 ;
if ( F_14 ( ! V_190 ) )
return NULL ;
F_94 () ;
V_22 = F_237 ( V_190 -> V_243 ) ;
if ( V_22 && V_22 -> V_27 == V_19 ) {
F_96 () ;
return V_22 ;
}
do {
V_22 = F_271 ( & V_190 -> V_240 , V_19 -> V_24 ) ;
F_96 () ;
if ( ! V_22 )
break;
if ( F_14 ( V_22 -> V_27 != V_19 ) ) {
F_268 ( V_19 , V_190 , V_22 ) ;
F_94 () ;
continue;
}
F_111 ( & V_190 -> V_239 , V_149 ) ;
F_238 ( V_190 -> V_243 , V_22 ) ;
F_112 ( & V_190 -> V_239 , V_149 ) ;
break;
} while ( 1 );
return V_22 ;
}
static int F_272 ( struct V_18 * V_19 , struct V_174 * V_190 ,
struct V_21 * V_22 , T_4 V_244 )
{
unsigned long V_149 ;
int V_136 ;
V_136 = F_273 ( V_244 ) ;
if ( ! V_136 ) {
V_22 -> V_190 = V_190 ;
V_22 -> V_27 = V_19 ;
F_111 ( & V_190 -> V_239 , V_149 ) ;
V_136 = F_274 ( & V_190 -> V_240 ,
V_19 -> V_24 , V_22 ) ;
if ( ! V_136 )
F_275 ( & V_22 -> V_241 , & V_190 -> V_241 ) ;
F_112 ( & V_190 -> V_239 , V_149 ) ;
F_276 () ;
if ( ! V_136 ) {
F_111 ( V_19 -> V_33 -> V_145 , V_149 ) ;
F_277 ( & V_22 -> V_242 , & V_19 -> V_241 ) ;
F_112 ( V_19 -> V_33 -> V_145 , V_149 ) ;
}
}
if ( V_136 )
F_250 ( V_249 L_27 ) ;
return V_136 ;
}
static struct V_21 *
F_278 ( struct V_18 * V_19 , T_4 V_244 )
{
struct V_174 * V_190 = NULL ;
struct V_21 * V_22 ;
F_279 ( V_244 & V_261 ) ;
V_190 = F_280 ( V_244 , V_19 -> V_33 -> V_99 ) ;
if ( ! V_190 )
return NULL ;
V_22 = F_134 ( V_19 , V_190 ) ;
if ( V_22 )
goto V_264;
V_22 = F_242 ( V_19 , V_244 ) ;
if ( V_22 == NULL )
goto V_265;
if ( F_272 ( V_19 , V_190 , V_22 , V_244 ) )
goto V_266;
V_264:
F_240 () ;
if ( F_14 ( V_190 -> V_255 ) )
F_258 ( V_190 ) ;
#ifdef F_281
if ( F_14 ( V_190 -> V_258 ) )
F_263 ( V_190 ) ;
#endif
return V_22 ;
V_266:
F_226 ( V_22 ) ;
V_265:
F_169 ( V_190 ) ;
return NULL ;
}
static void
F_282 ( struct V_18 * V_19 , struct V_21 * V_22 )
{
unsigned long V_267 = V_71 - V_22 -> V_246 ;
unsigned long V_268 = F_29 ( V_267 , 2UL * V_19 -> V_68 ) ;
V_22 -> V_199 = ( 7 * V_22 -> V_199 + 256 ) / 8 ;
V_22 -> V_269 = ( 7 * V_22 -> V_269 + 256 * V_268 ) / 8 ;
V_22 -> V_200 = ( V_22 -> V_269 + 128 ) / V_22 -> V_199 ;
}
static void
F_283 ( struct V_18 * V_19 , struct V_10 * V_11 ,
struct V_74 * V_167 )
{
T_3 V_270 = 0 ;
T_3 V_271 = F_138 ( V_167 ) ;
if ( V_11 -> V_272 ) {
if ( V_11 -> V_272 < F_42 ( V_167 ) )
V_270 = F_42 ( V_167 ) - V_11 -> V_272 ;
else
V_270 = V_11 -> V_272 - F_42 ( V_167 ) ;
}
V_11 -> V_273 <<= 1 ;
if ( F_180 ( V_19 -> V_33 ) )
V_11 -> V_273 |= ( V_271 < V_274 ) ;
else
V_11 -> V_273 |= ( V_270 > V_275 ) ;
}
static void
F_284 ( struct V_18 * V_19 , struct V_10 * V_11 ,
struct V_21 * V_22 )
{
int V_276 , V_277 ;
if ( ! F_6 ( V_11 ) || F_3 ( V_11 ) )
return;
V_277 = V_276 = F_7 ( V_11 ) ;
if ( V_11 -> V_168 [ 0 ] + V_11 -> V_168 [ 1 ] >= 4 )
F_285 ( V_11 ) ;
if ( V_11 -> V_162 && ( V_11 -> V_162 -> V_84 & V_278 ) )
V_277 = 0 ;
else if ( ! F_182 ( & V_22 -> V_190 -> V_198 ) || ! V_19 -> V_68 ||
( ! F_286 ( V_11 ) && F_167 ( V_11 ) ) )
V_277 = 0 ;
else if ( F_183 ( V_22 -> V_199 ) ) {
if ( V_22 -> V_200 > V_19 -> V_68 )
V_277 = 0 ;
else
V_277 = 1 ;
}
if ( V_276 != V_277 ) {
F_34 ( V_19 , V_11 , L_28 , V_277 ) ;
if ( V_277 )
F_260 ( V_11 ) ;
else
F_206 ( V_11 ) ;
}
}
static bool
F_287 ( struct V_18 * V_19 , struct V_10 * V_155 ,
struct V_74 * V_167 )
{
struct V_10 * V_11 ;
V_11 = V_19 -> V_187 ;
if ( ! V_11 )
return false ;
if ( F_3 ( V_155 ) )
return false ;
if ( F_3 ( V_11 ) )
return true ;
if ( F_4 ( V_11 ) && ! F_4 ( V_155 ) )
return false ;
if ( F_41 ( V_167 ) && ! F_6 ( V_11 ) )
return true ;
if ( V_155 -> V_3 != V_11 -> V_3 )
return false ;
if ( F_35 ( V_11 ) )
return true ;
if ( V_19 -> V_119 == V_15 &&
F_5 ( V_155 ) == V_15 &&
V_155 -> V_154 -> V_20 == 2 &&
F_102 ( & V_11 -> V_97 ) )
return true ;
if ( ( V_167 -> V_84 & V_85 ) && ! V_11 -> V_181 )
return true ;
if ( F_4 ( V_155 ) && ! F_4 ( V_11 ) )
return true ;
if ( F_102 ( & V_11 -> V_97 ) && ! F_179 ( V_19 , V_11 ) )
return true ;
if ( ! V_19 -> V_189 || ! F_164 ( V_11 ) )
return false ;
if ( F_176 ( V_19 , V_11 , V_167 ) )
return true ;
return false ;
}
static void F_288 ( struct V_18 * V_19 , struct V_10 * V_11 )
{
struct V_10 * V_279 = V_19 -> V_187 ;
F_34 ( V_19 , V_11 , L_29 ) ;
F_170 ( V_19 , 1 ) ;
if ( F_5 ( V_279 ) != F_5 ( V_11 ) )
V_11 -> V_3 -> V_107 = 0 ;
F_54 ( ! F_117 ( V_11 ) ) ;
F_113 ( V_19 , V_11 , 1 ) ;
V_11 -> V_72 = 0 ;
F_162 ( V_11 ) ;
}
static void
F_289 ( struct V_18 * V_19 , struct V_10 * V_11 ,
struct V_74 * V_167 )
{
struct V_21 * V_22 = F_212 ( V_167 ) ;
V_19 -> V_180 ++ ;
if ( V_167 -> V_84 & V_85 )
V_11 -> V_181 ++ ;
F_282 ( V_19 , V_22 ) ;
F_283 ( V_19 , V_11 , V_167 ) ;
F_284 ( V_19 , V_11 , V_22 ) ;
V_11 -> V_272 = F_42 ( V_167 ) + F_138 ( V_167 ) ;
if ( V_11 == V_19 -> V_187 ) {
if ( F_164 ( V_11 ) ) {
if ( F_189 ( V_167 ) > V_280 ||
V_19 -> V_32 > 1 ) {
F_153 ( V_19 , V_11 ) ;
F_158 ( V_11 ) ;
F_290 ( V_19 -> V_33 ) ;
} else {
F_155 (
& V_11 -> V_3 -> V_108 ) ;
F_291 ( V_11 ) ;
}
}
} else if ( F_287 ( V_19 , V_11 , V_167 ) ) {
F_288 ( V_19 , V_11 ) ;
F_290 ( V_19 -> V_33 ) ;
}
}
static void F_292 ( struct V_142 * V_143 , struct V_74 * V_167 )
{
struct V_18 * V_19 = V_143 -> V_176 -> V_177 ;
struct V_10 * V_11 = F_123 ( V_167 ) ;
F_34 ( V_19 , V_11 , L_30 ) ;
F_247 ( V_11 , F_212 ( V_167 ) -> V_190 ) ;
F_151 ( V_167 , V_71 + V_19 -> V_281 [ F_41 ( V_167 ) ] ) ;
F_293 ( & V_167 -> V_179 , & V_11 -> V_202 ) ;
F_125 ( V_167 ) ;
F_132 ( & ( F_130 ( V_167 ) ) -> V_108 ,
& V_19 -> V_171 -> V_108 , F_131 ( V_167 ) ,
F_41 ( V_167 ) ) ;
F_289 ( V_19 , V_11 , V_167 ) ;
}
static void F_294 ( struct V_18 * V_19 )
{
struct V_10 * V_11 = V_19 -> V_187 ;
if ( V_19 -> V_178 > V_19 -> V_282 )
V_19 -> V_282 = V_19 -> V_178 ;
if ( V_19 -> V_193 == 1 )
return;
if ( V_19 -> V_180 <= V_283 &&
V_19 -> V_178 <= V_283 )
return;
if ( V_11 && F_7 ( V_11 ) &&
V_11 -> V_197 + V_11 -> V_168 [ 0 ] + V_11 -> V_168 [ 1 ] <
V_283 && V_19 -> V_178 < V_283 )
return;
if ( V_19 -> V_284 ++ < 50 )
return;
if ( V_19 -> V_282 >= V_283 )
V_19 -> V_193 = 1 ;
else
V_19 -> V_193 = 0 ;
}
static bool F_295 ( struct V_18 * V_19 , struct V_10 * V_11 )
{
struct V_21 * V_22 = V_19 -> V_189 ;
if ( ! F_102 ( & V_11 -> V_97 ) )
return false ;
if ( V_11 -> V_3 -> V_98 > 1 )
return false ;
if ( F_35 ( V_11 ) )
return true ;
if ( V_22 && F_183 ( V_22 -> V_199 )
&& ( V_11 -> V_72 - V_71 < V_22 -> V_200 ) )
return true ;
if ( V_11 -> V_72 - V_71 == 1 )
return true ;
return false ;
}
static void F_296 ( struct V_142 * V_143 , struct V_74 * V_167 )
{
struct V_10 * V_11 = F_123 ( V_167 ) ;
struct V_18 * V_19 = V_11 -> V_19 ;
const int V_35 = F_41 ( V_167 ) ;
unsigned long V_285 ;
V_285 = V_71 ;
F_34 ( V_19 , V_11 , L_31 ,
! ! ( V_167 -> V_84 & V_278 ) ) ;
F_294 ( V_19 ) ;
F_21 ( ! V_19 -> V_178 ) ;
F_21 ( ! V_11 -> V_197 ) ;
V_19 -> V_178 -- ;
V_11 -> V_197 -- ;
( F_130 ( V_167 ) ) -> V_197 -- ;
F_297 ( & V_11 -> V_3 -> V_108 ,
F_298 ( V_167 ) , F_299 ( V_167 ) ,
F_131 ( V_167 ) , F_41 ( V_167 ) ) ;
V_19 -> V_201 [ F_6 ( V_11 ) ] -- ;
if ( V_35 ) {
F_212 ( V_167 ) -> V_246 = V_285 ;
if ( ! F_72 ( V_167 -> V_286 + V_19 -> V_281 [ 1 ] , V_285 ) )
V_19 -> V_227 = V_285 ;
}
if ( V_19 -> V_187 == V_11 ) {
const bool V_287 = F_102 ( & V_11 -> V_97 ) ;
if ( F_36 ( V_11 ) ) {
F_33 ( V_19 , V_11 ) ;
F_300 ( V_11 ) ;
}
if ( F_295 ( V_19 , V_11 ) ) {
unsigned long V_288 = V_19 -> V_68 ;
if ( ! V_19 -> V_68 )
V_288 = V_19 -> V_196 ;
V_11 -> V_72 = V_71 + V_288 ;
F_301 ( V_11 ) ;
F_34 ( V_19 , V_11 , L_32 ) ;
}
if ( F_35 ( V_11 ) || F_3 ( V_11 ) )
F_170 ( V_19 , 1 ) ;
else if ( V_35 && V_287 &&
! F_178 ( V_19 , V_11 ) ) {
F_181 ( V_19 ) ;
}
}
if ( ! V_19 -> V_178 )
F_17 ( V_19 ) ;
}
static void F_302 ( struct V_10 * V_11 )
{
if ( F_303 () ) {
if ( F_3 ( V_11 ) )
V_11 -> V_248 = V_252 ;
if ( V_11 -> V_40 > V_289 )
V_11 -> V_40 = V_289 ;
} else {
V_11 -> V_248 = V_11 -> V_254 ;
V_11 -> V_40 = V_11 -> V_165 ;
}
}
static inline int F_304 ( struct V_10 * V_11 )
{
if ( F_164 ( V_11 ) && ! F_305 ( V_11 ) ) {
F_306 ( V_11 ) ;
return V_290 ;
}
return V_291 ;
}
static int F_307 ( struct V_142 * V_143 , int V_292 )
{
struct V_18 * V_19 = V_143 -> V_176 -> V_177 ;
struct V_172 * V_173 = V_144 ;
struct V_21 * V_22 ;
struct V_10 * V_11 ;
V_22 = F_134 ( V_19 , V_173 -> V_174 ) ;
if ( ! V_22 )
return V_291 ;
V_11 = F_10 ( V_22 , F_308 ( V_292 ) ) ;
if ( V_11 ) {
F_247 ( V_11 , V_22 -> V_190 ) ;
F_302 ( V_11 ) ;
return F_304 ( V_11 ) ;
}
return V_291 ;
}
static void F_309 ( struct V_74 * V_167 )
{
struct V_10 * V_11 = F_123 ( V_167 ) ;
if ( V_11 ) {
const int V_292 = F_131 ( V_167 ) ;
F_54 ( ! V_11 -> V_207 [ V_292 ] ) ;
V_11 -> V_207 [ V_292 ] -- ;
F_169 ( F_212 ( V_167 ) -> V_190 ) ;
V_167 -> V_293 [ 0 ] = NULL ;
V_167 -> V_293 [ 1 ] = NULL ;
F_101 ( F_130 ( V_167 ) ) ;
V_167 -> V_293 [ 2 ] = NULL ;
F_215 ( V_11 ) ;
}
}
static struct V_10 *
F_310 ( struct V_18 * V_19 , struct V_21 * V_22 ,
struct V_10 * V_11 )
{
F_34 ( V_19 , V_11 , L_33 , V_11 -> V_155 ) ;
F_11 ( V_22 , V_11 -> V_155 , 1 ) ;
F_311 ( V_11 -> V_155 ) ;
F_215 ( V_11 ) ;
return F_10 ( V_22 , 1 ) ;
}
static struct V_10 *
F_312 ( struct V_21 * V_22 , struct V_10 * V_11 )
{
if ( F_195 ( V_11 ) == 1 ) {
V_11 -> V_256 = V_144 -> V_256 ;
F_313 ( V_11 ) ;
F_314 ( V_11 ) ;
return V_11 ;
}
F_11 ( V_22 , NULL , 1 ) ;
F_232 ( V_11 ) ;
F_215 ( V_11 ) ;
return NULL ;
}
static int
F_315 ( struct V_142 * V_143 , struct V_74 * V_167 , T_4 V_244 )
{
struct V_18 * V_19 = V_143 -> V_176 -> V_177 ;
struct V_21 * V_22 ;
const int V_292 = F_131 ( V_167 ) ;
const bool V_23 = F_41 ( V_167 ) ;
struct V_10 * V_11 ;
unsigned long V_149 ;
F_279 ( V_244 & V_261 ) ;
V_22 = F_278 ( V_19 , V_244 ) ;
F_111 ( V_143 -> V_145 , V_149 ) ;
if ( ! V_22 )
goto V_294;
V_217:
V_11 = F_10 ( V_22 , V_23 ) ;
if ( ! V_11 || V_11 == & V_19 -> V_260 ) {
V_11 = F_256 ( V_19 , V_23 , V_22 -> V_190 , V_244 ) ;
F_11 ( V_22 , V_11 , V_23 ) ;
} else {
if ( F_166 ( V_11 ) && F_316 ( V_11 ) ) {
F_34 ( V_19 , V_11 , L_34 ) ;
V_11 = F_312 ( V_22 , V_11 ) ;
if ( ! V_11 )
goto V_217;
}
if ( V_11 -> V_155 )
V_11 = F_310 ( V_19 , V_22 , V_11 ) ;
}
V_11 -> V_207 [ V_292 ] ++ ;
V_11 -> V_139 ++ ;
V_167 -> V_293 [ 0 ] = V_22 ;
V_167 -> V_293 [ 1 ] = V_11 ;
V_167 -> V_293 [ 2 ] = F_99 ( V_11 -> V_3 ) ;
F_112 ( V_143 -> V_145 , V_149 ) ;
return 0 ;
V_294:
F_17 ( V_19 ) ;
F_112 ( V_143 -> V_145 , V_149 ) ;
F_18 ( V_19 , L_35 ) ;
return 1 ;
}
static void F_317 ( struct V_295 * V_296 )
{
struct V_18 * V_19 =
F_78 ( V_296 , struct V_18 , V_34 ) ;
struct V_142 * V_143 = V_19 -> V_33 ;
F_98 ( V_143 -> V_145 ) ;
F_290 ( V_19 -> V_33 ) ;
F_97 ( V_143 -> V_145 ) ;
}
static void F_318 ( unsigned long V_297 )
{
struct V_18 * V_19 = (struct V_18 * ) V_297 ;
struct V_10 * V_11 ;
unsigned long V_149 ;
int V_188 = 1 ;
F_18 ( V_19 , L_36 ) ;
F_111 ( V_19 -> V_33 -> V_145 , V_149 ) ;
V_11 = V_19 -> V_187 ;
if ( V_11 ) {
V_188 = 0 ;
if ( F_203 ( V_11 ) )
goto V_298;
if ( F_35 ( V_11 ) )
goto V_218;
if ( ! V_19 -> V_32 )
goto V_299;
if ( ! F_102 ( & V_11 -> V_97 ) )
goto V_298;
F_205 ( V_11 ) ;
}
V_218:
F_170 ( V_19 , V_188 ) ;
V_298:
F_17 ( V_19 ) ;
V_299:
F_112 ( V_19 -> V_33 -> V_145 , V_149 ) ;
}
static void F_319 ( struct V_18 * V_19 )
{
F_320 ( & V_19 -> V_186 ) ;
F_321 ( & V_19 -> V_34 ) ;
}
static void F_322 ( struct V_18 * V_19 )
{
int V_134 ;
for ( V_134 = 0 ; V_134 < V_38 ; V_134 ++ ) {
if ( V_19 -> V_262 [ 0 ] [ V_134 ] )
F_215 ( V_19 -> V_262 [ 0 ] [ V_134 ] ) ;
if ( V_19 -> V_262 [ 1 ] [ V_134 ] )
F_215 ( V_19 -> V_262 [ 1 ] [ V_134 ] ) ;
}
if ( V_19 -> V_263 )
F_215 ( V_19 -> V_263 ) ;
}
static void F_323 ( struct V_300 * V_301 )
{
struct V_18 * V_19 = V_301 -> V_177 ;
struct V_142 * V_143 = V_19 -> V_33 ;
bool V_302 = false ;
F_319 ( V_19 ) ;
F_98 ( V_143 -> V_145 ) ;
if ( V_19 -> V_187 )
F_163 ( V_19 , V_19 -> V_187 , 0 ) ;
while ( ! F_148 ( & V_19 -> V_241 ) ) {
struct V_21 * V_22 = F_324 ( V_19 -> V_241 . V_95 ,
struct V_21 ,
V_242 ) ;
F_235 ( V_19 , V_22 ) ;
}
F_322 ( V_19 ) ;
F_107 ( V_19 ) ;
if ( V_19 -> V_131 )
V_302 = true ;
F_97 ( V_143 -> V_145 ) ;
F_319 ( V_19 ) ;
F_222 ( & V_303 ) ;
F_325 ( & V_304 , V_19 -> V_24 ) ;
F_225 ( & V_303 ) ;
if ( V_302 )
F_326 () ;
#ifdef F_281
F_103 ( V_19 -> V_141 . V_108 . V_146 ) ;
#endif
F_90 ( V_19 ) ;
}
static int F_327 ( void )
{
int V_305 , error ;
do {
if ( ! F_328 ( & V_304 , V_306 ) )
return - V_307 ;
F_222 ( & V_303 ) ;
error = F_329 ( & V_304 , & V_305 ) ;
F_225 ( & V_303 ) ;
if ( error && error != - V_308 )
return error ;
} while ( error );
return V_305 ;
}
static void * F_330 ( struct V_142 * V_143 )
{
struct V_18 * V_19 ;
int V_134 , V_135 ;
struct V_2 * V_3 ;
struct V_1 * V_48 ;
V_134 = F_327 () ;
if ( V_134 < 0 )
return NULL ;
V_19 = F_331 ( sizeof( * V_19 ) , V_306 | V_245 , V_143 -> V_99 ) ;
if ( ! V_19 ) {
F_222 ( & V_303 ) ;
F_325 ( & V_304 , V_134 ) ;
F_225 ( & V_303 ) ;
return NULL ;
}
V_19 -> V_24 = V_134 ;
V_19 -> V_58 = V_138 ;
V_3 = & V_19 -> V_141 ;
F_88 ( V_3 , V_134 , V_135 , V_48 )
* V_48 = V_138 ;
F_49 ( & V_3 -> V_90 ) ;
V_3 -> V_45 = 2 * V_44 ;
#ifdef F_281
V_3 -> V_139 = 2 ;
if ( F_89 ( & V_3 -> V_108 ) ) {
F_90 ( V_3 ) ;
F_90 ( V_19 ) ;
return NULL ;
}
F_94 () ;
F_82 ( & V_140 , & V_3 -> V_108 ,
( void * ) V_19 , 0 ) ;
F_96 () ;
V_19 -> V_131 ++ ;
F_85 ( & V_3 -> V_132 , & V_19 -> V_133 ) ;
#endif
for ( V_134 = 0 ; V_134 < V_309 ; V_134 ++ )
V_19 -> V_164 [ V_134 ] = V_310 ;
F_259 ( V_19 , & V_19 -> V_260 , 1 , 0 ) ;
V_19 -> V_260 . V_139 ++ ;
F_100 ( & V_19 -> V_260 , & V_19 -> V_141 ) ;
F_244 ( & V_19 -> V_241 ) ;
V_19 -> V_33 = V_143 ;
F_332 ( & V_19 -> V_186 ) ;
V_19 -> V_186 . V_311 = F_318 ;
V_19 -> V_186 . V_297 = ( unsigned long ) V_19 ;
F_333 ( & V_19 -> V_34 , F_317 ) ;
V_19 -> V_225 = V_225 ;
V_19 -> V_281 [ 0 ] = V_281 [ 0 ] ;
V_19 -> V_281 [ 1 ] = V_281 [ 1 ] ;
V_19 -> V_86 = V_86 ;
V_19 -> V_87 = V_87 ;
V_19 -> V_37 [ 0 ] = V_312 ;
V_19 -> V_37 [ 1 ] = V_313 ;
V_19 -> V_204 = V_204 ;
V_19 -> V_68 = V_68 ;
V_19 -> V_196 = V_196 ;
V_19 -> V_62 = 1 ;
V_19 -> V_193 = - 1 ;
V_19 -> V_227 = V_71 - V_157 ;
return V_19 ;
}
static void F_334 ( void )
{
if ( V_231 )
F_335 ( V_231 ) ;
if ( V_234 )
F_335 ( V_234 ) ;
}
static int T_6 F_336 ( void )
{
V_231 = F_337 ( V_10 , 0 ) ;
if ( ! V_231 )
goto V_314;
V_234 = F_337 ( V_21 , 0 ) ;
if ( ! V_234 )
goto V_314;
return 0 ;
V_314:
F_334 () ;
return - V_307 ;
}
static T_7
F_338 ( unsigned int V_315 , char * V_316 )
{
return sprintf ( V_316 , L_37 , V_315 ) ;
}
static T_7
F_339 ( unsigned int * V_315 , const char * V_316 , T_8 V_20 )
{
char * V_151 = ( char * ) V_316 ;
* V_315 = F_340 ( V_151 , & V_151 , 10 ) ;
return V_20 ;
}
static int T_6 F_341 ( void )
{
if ( ! V_312 )
V_312 = 1 ;
if ( ! V_68 )
V_68 = 1 ;
#ifdef F_281
if ( ! V_196 )
V_196 = 1 ;
#else
V_196 = 0 ;
#endif
if ( F_336 () )
return - V_307 ;
F_342 ( & V_317 ) ;
F_343 ( & V_318 ) ;
return 0 ;
}
static void T_9 F_344 ( void )
{
F_345 ( V_319 ) ;
F_346 ( & V_318 ) ;
F_347 ( & V_317 ) ;
V_236 = & V_319 ;
F_236 () ;
if ( F_223 ( V_235 ) )
F_348 ( & V_319 ) ;
F_349 ( & V_304 ) ;
F_334 () ;
}
