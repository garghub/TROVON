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
static inline bool F_2 ( struct V_10 * V_11 )
{
if ( ! V_11 -> V_12 && V_11 -> V_13 )
return true ;
else
return false ;
}
static inline enum V_4 F_3 ( struct V_14 * V_15 )
{
if ( F_4 ( V_15 ) )
return V_7 ;
if ( F_5 ( V_15 ) )
return V_16 ;
return V_17 ;
}
static enum V_6 F_6 ( struct V_14 * V_15 )
{
if ( ! F_7 ( V_15 ) )
return V_18 ;
if ( ! F_8 ( V_15 ) )
return V_19 ;
return V_20 ;
}
static inline int F_9 ( enum V_4 V_21 ,
struct V_10 * V_11 ,
struct V_2 * V_3 )
{
if ( V_21 == V_7 )
return V_3 -> V_8 . V_22 ;
return V_3 -> V_9 [ V_21 ] [ V_18 ] . V_22
+ V_3 -> V_9 [ V_21 ] [ V_19 ] . V_22
+ V_3 -> V_9 [ V_21 ] [ V_20 ] . V_22 ;
}
static inline int F_10 ( struct V_10 * V_11 ,
struct V_2 * V_3 )
{
return V_3 -> V_9 [ V_16 ] [ V_18 ] . V_22
+ V_3 -> V_9 [ V_17 ] [ V_18 ] . V_22 ;
}
static inline struct V_14 * F_11 ( struct V_23 * V_24 ,
bool V_25 )
{
return V_24 -> V_15 [ V_25 ] ;
}
static inline void F_12 ( struct V_23 * V_24 ,
struct V_14 * V_15 , bool V_25 )
{
V_24 -> V_15 [ V_25 ] = V_15 ;
}
static inline void * F_13 ( struct V_10 * V_11 )
{
return ( void * ) ( V_11 -> V_26 << V_27 | V_28 ) ;
}
static inline struct V_10 * F_14 ( struct V_23 * V_24 )
{
struct V_10 * V_11 = V_24 -> V_29 ;
if ( F_15 ( ( unsigned long ) V_11 & V_28 ) )
return NULL ;
return V_11 ;
}
static inline bool F_16 ( struct V_30 * V_30 )
{
return F_17 ( V_30 ) == V_31 || ( V_30 -> V_32 & V_33 ) ;
}
static inline void F_18 ( struct V_10 * V_11 )
{
if ( V_11 -> V_34 ) {
F_19 ( V_11 , L_1 ) ;
F_20 ( V_11 -> V_35 , & V_11 -> V_36 ) ;
}
}
static inline int F_21 ( struct V_10 * V_11 , bool V_37 ,
unsigned short V_5 )
{
const int V_38 = V_11 -> V_39 [ V_37 ] ;
F_22 ( V_5 >= V_40 ) ;
return V_38 + ( V_38 / V_41 * ( 4 - V_5 ) ) ;
}
static inline int
F_23 ( struct V_10 * V_11 , struct V_14 * V_15 )
{
return F_21 ( V_11 , F_7 ( V_15 ) , V_15 -> V_42 ) ;
}
static inline T_1 F_24 ( unsigned long V_43 , struct V_2 * V_3 )
{
T_1 V_44 = V_43 << V_45 ;
V_44 = V_44 * V_46 ;
F_25 ( V_44 , V_3 -> V_47 ) ;
return V_44 ;
}
static inline T_1 F_26 ( T_1 V_48 , T_1 V_49 )
{
T_2 V_43 = ( T_2 ) ( V_49 - V_48 ) ;
if ( V_43 > 0 )
V_48 = V_49 ;
return V_48 ;
}
static inline T_1 V_48 ( T_1 V_48 , T_1 V_49 )
{
T_2 V_43 = ( T_2 ) ( V_49 - V_48 ) ;
if ( V_43 < 0 )
V_48 = V_49 ;
return V_48 ;
}
static void F_27 ( struct V_1 * V_50 )
{
struct V_2 * V_3 ;
if ( V_50 -> V_51 ) {
V_3 = F_28 ( V_50 -> V_51 ) ;
V_50 -> V_48 = F_26 ( V_50 -> V_48 ,
V_3 -> V_49 ) ;
}
}
static inline unsigned F_29 ( struct V_10 * V_11 ,
struct V_2 * V_3 , bool V_52 )
{
unsigned V_53 , V_54 ;
unsigned V_55 = V_56 - 1 ;
unsigned V_57 = V_56 / 2 ;
unsigned V_58 = F_9 ( V_52 , V_11 , V_3 ) ;
V_53 = F_30 ( V_3 -> V_59 [ V_52 ] , V_58 ) ;
V_54 = F_31 ( V_3 -> V_59 [ V_52 ] , V_58 ) ;
V_3 -> V_59 [ V_52 ] = ( V_55 * V_54 + V_53 + V_57 ) /
V_56 ;
return V_3 -> V_59 [ V_52 ] ;
}
static inline unsigned
F_32 ( struct V_10 * V_11 , struct V_2 * V_3 )
{
struct V_1 * V_50 = & V_11 -> V_60 ;
return V_61 * V_3 -> V_47 / V_50 -> V_62 ;
}
static inline unsigned
F_33 ( struct V_10 * V_11 , struct V_14 * V_15 )
{
unsigned V_63 = F_23 ( V_11 , V_15 ) ;
if ( V_11 -> V_64 ) {
unsigned V_65 = F_29 ( V_11 , V_15 -> V_3 ,
F_5 ( V_15 ) ) ;
unsigned V_66 = V_11 -> V_39 [ 1 ] ;
unsigned V_67 = V_66 * V_65 ;
unsigned V_68 = F_32 ( V_11 , V_15 -> V_3 ) ;
if ( V_67 > V_68 ) {
unsigned V_69 = 2 * V_11 -> V_12 ;
unsigned V_70 =
F_30 ( V_63 , V_69 * V_63 / V_66 ) ;
V_63 = F_31 ( V_63 * V_68 / V_67 ,
V_70 ) ;
}
}
return V_63 ;
}
static inline void
F_34 ( struct V_10 * V_11 , struct V_14 * V_15 )
{
unsigned V_63 = F_33 ( V_11 , V_15 ) ;
V_15 -> V_71 = V_72 ;
V_15 -> V_73 = V_72 + V_63 ;
V_15 -> V_74 = V_63 ;
F_35 ( V_11 , V_15 , L_2 , V_15 -> V_73 - V_72 ) ;
}
static inline bool F_36 ( struct V_14 * V_15 )
{
if ( F_37 ( V_15 ) )
return false ;
if ( F_38 ( V_72 , V_15 -> V_73 ) )
return false ;
return true ;
}
static struct V_75 *
F_39 ( struct V_10 * V_11 , struct V_75 * V_76 , struct V_75 * V_77 , T_3 V_78 )
{
T_3 V_79 , V_80 , V_81 = 0 , V_82 = 0 ;
unsigned long V_83 ;
#define F_40 0x01
#define F_41 0x02
unsigned V_84 = 0 ;
if ( V_76 == NULL || V_76 == V_77 )
return V_77 ;
if ( V_77 == NULL )
return V_76 ;
if ( F_42 ( V_76 ) != F_42 ( V_77 ) )
return F_42 ( V_76 ) ? V_76 : V_77 ;
if ( ( V_76 -> V_85 ^ V_77 -> V_85 ) & V_86 )
return V_76 -> V_85 & V_86 ? V_76 : V_77 ;
V_79 = F_43 ( V_76 ) ;
V_80 = F_43 ( V_77 ) ;
V_83 = V_11 -> V_87 * 2 ;
if ( V_79 >= V_78 )
V_81 = V_79 - V_78 ;
else if ( V_79 + V_83 >= V_78 )
V_81 = ( V_78 - V_79 ) * V_11 -> V_88 ;
else
V_84 |= F_40 ;
if ( V_80 >= V_78 )
V_82 = V_80 - V_78 ;
else if ( V_80 + V_83 >= V_78 )
V_82 = ( V_78 - V_80 ) * V_11 -> V_88 ;
else
V_84 |= F_41 ;
switch ( V_84 ) {
case 0 :
if ( V_81 < V_82 )
return V_76 ;
else if ( V_82 < V_81 )
return V_77 ;
else {
if ( V_79 >= V_80 )
return V_76 ;
else
return V_77 ;
}
case F_41 :
return V_76 ;
case F_40 :
return V_77 ;
case ( F_40 | F_41 ) :
default:
if ( V_79 <= V_80 )
return V_76 ;
else
return V_77 ;
}
}
static struct V_14 * F_44 ( struct V_1 * V_89 )
{
if ( ! V_89 -> V_22 )
return NULL ;
if ( ! V_89 -> V_51 )
V_89 -> V_51 = F_45 ( & V_89 -> V_90 ) ;
if ( V_89 -> V_51 )
return F_46 ( V_89 -> V_51 , struct V_14 , V_91 ) ;
return NULL ;
}
static struct V_2 * F_47 ( struct V_1 * V_89 )
{
if ( ! V_89 -> V_51 )
V_89 -> V_51 = F_45 ( & V_89 -> V_90 ) ;
if ( V_89 -> V_51 )
return F_28 ( V_89 -> V_51 ) ;
return NULL ;
}
static void F_48 ( struct V_91 * V_92 , struct V_93 * V_89 )
{
F_49 ( V_92 , V_89 ) ;
F_50 ( V_92 ) ;
}
static void F_51 ( struct V_91 * V_92 , struct V_1 * V_89 )
{
if ( V_89 -> V_51 == V_92 )
V_89 -> V_51 = NULL ;
F_48 ( V_92 , & V_89 -> V_90 ) ;
-- V_89 -> V_22 ;
}
static struct V_75 *
F_52 ( struct V_10 * V_11 , struct V_14 * V_15 ,
struct V_75 * V_78 )
{
struct V_91 * V_94 = F_53 ( & V_78 -> V_91 ) ;
struct V_91 * V_95 = F_54 ( & V_78 -> V_91 ) ;
struct V_75 * V_96 = NULL , * V_97 = NULL ;
F_55 ( F_56 ( & V_78 -> V_91 ) ) ;
if ( V_95 )
V_97 = F_57 ( V_95 ) ;
if ( V_94 )
V_96 = F_57 ( V_94 ) ;
else {
V_94 = F_45 ( & V_15 -> V_98 ) ;
if ( V_94 && V_94 != & V_78 -> V_91 )
V_96 = F_57 ( V_94 ) ;
}
return F_39 ( V_11 , V_96 , V_97 , F_43 ( V_78 ) ) ;
}
static unsigned long F_58 ( struct V_10 * V_11 ,
struct V_14 * V_15 )
{
return ( V_15 -> V_3 -> V_99 - 1 ) * ( F_21 ( V_11 , 1 , 0 ) -
F_21 ( V_11 , F_7 ( V_15 ) , V_15 -> V_42 ) ) ;
}
static inline T_2
F_59 ( struct V_1 * V_50 , struct V_2 * V_3 )
{
return V_3 -> V_49 - V_50 -> V_48 ;
}
static void
F_60 ( struct V_1 * V_50 , struct V_2 * V_3 )
{
struct V_91 * * V_100 = & V_50 -> V_90 . V_91 ;
struct V_91 * V_101 = NULL ;
struct V_2 * V_102 ;
T_2 V_29 = F_59 ( V_50 , V_3 ) ;
int V_51 = 1 ;
while ( * V_100 != NULL ) {
V_101 = * V_100 ;
V_102 = F_28 ( V_101 ) ;
if ( V_29 < F_59 ( V_50 , V_102 ) )
V_100 = & V_101 -> V_103 ;
else {
V_100 = & V_101 -> V_104 ;
V_51 = 0 ;
}
}
if ( V_51 )
V_50 -> V_51 = & V_3 -> V_91 ;
F_61 ( & V_3 -> V_91 , V_101 , V_100 ) ;
F_62 ( & V_3 -> V_91 , & V_50 -> V_90 ) ;
}
static void
F_63 ( struct V_2 * V_3 )
{
F_55 ( ! F_56 ( & V_3 -> V_91 ) ) ;
if ( V_3 -> V_105 ) {
V_3 -> V_47 = V_3 -> V_106 ;
V_3 -> V_105 = false ;
}
}
static void
F_64 ( struct V_1 * V_50 , struct V_2 * V_3 )
{
F_55 ( ! F_56 ( & V_3 -> V_91 ) ) ;
F_63 ( V_3 ) ;
F_60 ( V_50 , V_3 ) ;
V_50 -> V_62 += V_3 -> V_47 ;
}
static void
F_65 ( struct V_10 * V_11 , struct V_2 * V_3 )
{
struct V_1 * V_50 = & V_11 -> V_60 ;
struct V_2 * V_102 ;
struct V_91 * V_92 ;
V_3 -> V_99 ++ ;
if ( ! F_56 ( & V_3 -> V_91 ) )
return;
V_92 = F_66 ( & V_50 -> V_90 ) ;
if ( V_92 ) {
V_102 = F_28 ( V_92 ) ;
V_3 -> V_49 = V_102 -> V_49 + V_107 ;
} else
V_3 -> V_49 = V_50 -> V_48 ;
F_64 ( V_50 , V_3 ) ;
}
static void
F_67 ( struct V_1 * V_50 , struct V_2 * V_3 )
{
V_50 -> V_62 -= V_3 -> V_47 ;
if ( ! F_56 ( & V_3 -> V_91 ) )
F_51 ( & V_3 -> V_91 , V_50 ) ;
}
static void
F_68 ( struct V_10 * V_11 , struct V_2 * V_3 )
{
struct V_1 * V_50 = & V_11 -> V_60 ;
F_55 ( V_3 -> V_99 < 1 ) ;
V_3 -> V_99 -- ;
if ( V_3 -> V_99 )
return;
F_69 ( V_11 , V_3 , L_3 ) ;
F_67 ( V_50 , V_3 ) ;
V_3 -> V_108 = 0 ;
F_70 ( & V_3 -> V_109 , 1 ) ;
}
static inline unsigned int F_71 ( struct V_14 * V_15 ,
unsigned int * V_110 )
{
unsigned int V_111 ;
if ( ! V_15 -> V_71 || V_15 -> V_71 == V_72 ) {
V_111 = F_72 ( unsigned , ( V_72 - V_15 -> V_112 ) ,
1 ) ;
} else {
V_111 = V_72 - V_15 -> V_71 ;
if ( V_111 > V_15 -> V_74 ) {
* V_110 = V_111 - V_15 -> V_74 ;
V_111 = V_15 -> V_74 ;
}
if ( F_73 ( V_15 -> V_71 , V_15 -> V_112 ) )
* V_110 += V_15 -> V_71 -
V_15 -> V_112 ;
}
return V_111 ;
}
static void F_74 ( struct V_10 * V_11 , struct V_2 * V_3 ,
struct V_14 * V_15 )
{
struct V_1 * V_50 = & V_11 -> V_60 ;
unsigned int V_113 , V_114 , V_115 = 0 ;
int V_116 = V_3 -> V_99 - F_10 ( V_11 , V_3 )
- V_3 -> V_8 . V_22 ;
F_55 ( V_116 < 0 ) ;
V_113 = V_114 = F_71 ( V_15 , & V_115 ) ;
if ( F_2 ( V_11 ) )
V_114 = V_15 -> V_117 ;
else if ( ! F_7 ( V_15 ) && ! V_116 )
V_114 = V_15 -> V_74 ;
F_67 ( V_50 , V_3 ) ;
V_3 -> V_49 += F_24 ( V_114 , V_3 ) ;
F_64 ( V_50 , V_3 ) ;
if ( F_73 ( V_11 -> V_118 , V_72 ) ) {
V_3 -> V_108 = V_11 -> V_118
- V_72 ;
V_3 -> V_119 = V_11 -> V_120 ;
V_3 -> V_121 = V_11 -> V_122 ;
} else
V_3 -> V_108 = 0 ;
F_69 ( V_11 , V_3 , L_4 , V_3 -> V_49 ,
V_50 -> V_48 ) ;
F_35 ( V_15 -> V_11 , V_15 ,
L_5 ,
V_113 , V_15 -> V_117 , V_114 ,
F_2 ( V_11 ) , V_15 -> V_123 ) ;
F_75 ( & V_3 -> V_109 , V_113 ,
V_115 ) ;
F_76 ( & V_3 -> V_109 ) ;
}
static inline struct V_2 * F_77 ( struct V_124 * V_109 )
{
if ( V_109 )
return F_78 ( V_109 , struct V_2 , V_109 ) ;
return NULL ;
}
static void F_79 ( void * V_29 , struct V_124 * V_109 ,
unsigned int V_47 )
{
struct V_2 * V_3 = F_77 ( V_109 ) ;
V_3 -> V_106 = V_47 ;
V_3 -> V_105 = true ;
}
static void F_80 ( struct V_10 * V_11 ,
struct V_2 * V_3 , struct V_125 * V_126 )
{
struct V_127 * V_128 = & V_11 -> V_35 -> V_127 ;
unsigned int V_129 , V_130 ;
if ( V_128 -> V_131 ) {
sscanf ( F_81 ( V_128 -> V_131 ) , L_6 , & V_129 , & V_130 ) ;
F_82 ( V_126 , & V_3 -> V_109 ,
( void * ) V_11 , F_83 ( V_129 , V_130 ) ) ;
} else
F_82 ( V_126 , & V_3 -> V_109 ,
( void * ) V_11 , 0 ) ;
V_11 -> V_132 ++ ;
V_3 -> V_47 = F_84 ( V_126 , V_3 -> V_109 . V_131 ) ;
F_85 ( & V_3 -> V_133 , & V_11 -> V_134 ) ;
}
static struct V_2 * F_86 ( struct V_10 * V_11 )
{
struct V_2 * V_3 = NULL ;
int V_135 , V_136 , V_137 ;
struct V_1 * V_50 ;
V_3 = F_87 ( sizeof( * V_3 ) , V_138 , V_11 -> V_35 -> V_100 ) ;
if ( ! V_3 )
return NULL ;
F_88 ( V_3 , V_135 , V_136 , V_50 )
* V_50 = V_139 ;
F_50 ( & V_3 -> V_91 ) ;
V_3 -> V_140 . V_141 = V_72 ;
V_3 -> V_142 = 1 ;
V_137 = F_89 ( & V_3 -> V_109 ) ;
if ( V_137 ) {
F_90 ( V_3 ) ;
return NULL ;
}
return V_3 ;
}
static struct V_2 *
F_91 ( struct V_10 * V_11 , struct V_125 * V_126 )
{
struct V_2 * V_3 = NULL ;
void * V_29 = V_11 ;
struct V_127 * V_128 = & V_11 -> V_35 -> V_127 ;
unsigned int V_129 , V_130 ;
if ( V_126 == & V_143 )
V_3 = & V_11 -> V_144 ;
else
V_3 = F_77 ( F_92 ( V_126 , V_29 ) ) ;
if ( V_3 && ! V_3 -> V_109 . V_131 && V_128 -> V_131 && F_81 ( V_128 -> V_131 ) ) {
sscanf ( F_81 ( V_128 -> V_131 ) , L_6 , & V_129 , & V_130 ) ;
V_3 -> V_109 . V_131 = F_83 ( V_129 , V_130 ) ;
}
return V_3 ;
}
static struct V_2 * F_93 ( struct V_10 * V_11 )
{
struct V_125 * V_126 ;
struct V_2 * V_3 = NULL , * V_102 = NULL ;
struct V_145 * V_146 = V_11 -> V_35 ;
F_94 () ;
V_126 = F_95 ( V_147 ) ;
V_3 = F_91 ( V_11 , V_126 ) ;
if ( V_3 ) {
F_96 () ;
return V_3 ;
}
F_96 () ;
F_97 ( V_146 -> V_148 ) ;
V_3 = F_86 ( V_11 ) ;
F_98 ( V_146 -> V_148 ) ;
F_94 () ;
V_126 = F_95 ( V_147 ) ;
V_102 = F_91 ( V_11 , V_126 ) ;
if ( V_102 ) {
F_90 ( V_3 ) ;
F_96 () ;
return V_102 ;
}
if ( ! V_3 )
V_3 = & V_11 -> V_144 ;
F_80 ( V_11 , V_3 , V_126 ) ;
F_96 () ;
return V_3 ;
}
static inline struct V_2 * F_99 ( struct V_2 * V_3 )
{
V_3 -> V_142 ++ ;
return V_3 ;
}
static void F_100 ( struct V_14 * V_15 , struct V_2 * V_3 )
{
if ( ! F_7 ( V_15 ) )
V_3 = & V_15 -> V_11 -> V_144 ;
V_15 -> V_3 = V_3 ;
V_15 -> V_3 -> V_142 ++ ;
}
static void F_101 ( struct V_2 * V_3 )
{
struct V_1 * V_50 ;
int V_135 , V_136 ;
F_55 ( V_3 -> V_142 <= 0 ) ;
V_3 -> V_142 -- ;
if ( V_3 -> V_142 )
return;
F_88 (cfqg, i, j, st)
F_55 ( ! F_102 ( & V_50 -> V_90 ) ) ;
F_103 ( V_3 -> V_109 . V_149 ) ;
F_90 ( V_3 ) ;
}
static void F_104 ( struct V_10 * V_11 , struct V_2 * V_3 )
{
F_55 ( F_105 ( & V_3 -> V_133 ) ) ;
F_106 ( & V_3 -> V_133 ) ;
F_55 ( V_11 -> V_132 <= 0 ) ;
V_11 -> V_132 -- ;
F_101 ( V_3 ) ;
}
static void F_107 ( struct V_10 * V_11 )
{
struct V_150 * V_151 , * V_92 ;
struct V_2 * V_3 ;
F_108 (cfqg, pos, n, &cfqd->cfqg_list, cfqd_node) {
if ( ! F_109 ( & V_3 -> V_109 ) )
F_104 ( V_11 , V_3 ) ;
}
}
static void F_110 ( void * V_29 , struct V_124 * V_109 )
{
unsigned long V_152 ;
struct V_10 * V_11 = V_29 ;
F_111 ( V_11 -> V_35 -> V_148 , V_152 ) ;
F_104 ( V_11 , F_77 ( V_109 ) ) ;
F_112 ( V_11 -> V_35 -> V_148 , V_152 ) ;
}
static struct V_2 * F_93 ( struct V_10 * V_11 )
{
return & V_11 -> V_144 ;
}
static inline struct V_2 * F_99 ( struct V_2 * V_3 )
{
return V_3 ;
}
static inline void
F_100 ( struct V_14 * V_15 , struct V_2 * V_3 ) {
V_15 -> V_3 = V_3 ;
}
static void F_107 ( struct V_10 * V_11 ) {}
static inline void F_101 ( struct V_2 * V_3 ) {}
static void F_113 ( struct V_10 * V_11 , struct V_14 * V_15 ,
bool V_153 )
{
struct V_91 * * V_154 , * V_101 ;
struct V_14 * V_155 ;
unsigned long V_156 ;
struct V_1 * V_157 ;
int V_51 ;
int V_158 = 1 ;
V_157 = F_1 ( V_15 -> V_3 , F_3 ( V_15 ) ,
F_6 ( V_15 ) ) ;
if ( F_4 ( V_15 ) ) {
V_156 = V_107 ;
V_101 = F_66 ( & V_157 -> V_90 ) ;
if ( V_101 && V_101 != & V_15 -> V_91 ) {
V_155 = F_46 ( V_101 , struct V_14 , V_91 ) ;
V_156 += V_155 -> V_156 ;
} else
V_156 += V_72 ;
} else if ( ! V_153 ) {
V_156 = F_58 ( V_11 , V_15 ) + V_72 ;
V_156 -= V_15 -> V_159 ;
V_15 -> V_159 = 0 ;
} else {
V_156 = - V_160 ;
V_155 = F_44 ( V_157 ) ;
V_156 += V_155 ? V_155 -> V_156 : V_72 ;
}
if ( ! F_56 ( & V_15 -> V_91 ) ) {
V_158 = 0 ;
if ( V_156 == V_15 -> V_156 &&
V_15 -> V_157 == V_157 )
return;
F_51 ( & V_15 -> V_91 , V_15 -> V_157 ) ;
V_15 -> V_157 = NULL ;
}
V_51 = 1 ;
V_101 = NULL ;
V_15 -> V_157 = V_157 ;
V_154 = & V_157 -> V_90 . V_91 ;
while ( * V_154 ) {
struct V_91 * * V_92 ;
V_101 = * V_154 ;
V_155 = F_46 ( V_101 , struct V_14 , V_91 ) ;
if ( F_38 ( V_156 , V_155 -> V_156 ) )
V_92 = & ( * V_154 ) -> V_103 ;
else {
V_92 = & ( * V_154 ) -> V_104 ;
V_51 = 0 ;
}
V_154 = V_92 ;
}
if ( V_51 )
V_157 -> V_51 = & V_15 -> V_91 ;
V_15 -> V_156 = V_156 ;
F_61 ( & V_15 -> V_91 , V_101 , V_154 ) ;
F_62 ( & V_15 -> V_91 , & V_157 -> V_90 ) ;
V_157 -> V_22 ++ ;
if ( V_153 || ! V_158 )
return;
F_65 ( V_11 , V_15 -> V_3 ) ;
}
static struct V_14 *
F_114 ( struct V_10 * V_11 , struct V_93 * V_89 ,
T_3 V_161 , struct V_91 * * V_162 ,
struct V_91 * * * V_163 )
{
struct V_91 * * V_154 , * V_101 ;
struct V_14 * V_15 = NULL ;
V_101 = NULL ;
V_154 = & V_89 -> V_91 ;
while ( * V_154 ) {
struct V_91 * * V_92 ;
V_101 = * V_154 ;
V_15 = F_46 ( V_101 , struct V_14 , V_164 ) ;
if ( V_161 > F_43 ( V_15 -> V_165 ) )
V_92 = & ( * V_154 ) -> V_104 ;
else if ( V_161 < F_43 ( V_15 -> V_165 ) )
V_92 = & ( * V_154 ) -> V_103 ;
else
break;
V_154 = V_92 ;
V_15 = NULL ;
}
* V_162 = V_101 ;
if ( V_163 )
* V_163 = V_154 ;
return V_15 ;
}
static void F_115 ( struct V_10 * V_11 , struct V_14 * V_15 )
{
struct V_91 * * V_154 , * V_101 ;
struct V_14 * V_155 ;
if ( V_15 -> V_166 ) {
F_49 ( & V_15 -> V_164 , V_15 -> V_166 ) ;
V_15 -> V_166 = NULL ;
}
if ( F_4 ( V_15 ) )
return;
if ( ! V_15 -> V_165 )
return;
V_15 -> V_166 = & V_11 -> V_167 [ V_15 -> V_168 ] ;
V_155 = F_114 ( V_11 , V_15 -> V_166 ,
F_43 ( V_15 -> V_165 ) , & V_101 , & V_154 ) ;
if ( ! V_155 ) {
F_61 ( & V_15 -> V_164 , V_101 , V_154 ) ;
F_62 ( & V_15 -> V_164 , V_15 -> V_166 ) ;
} else
V_15 -> V_166 = NULL ;
}
static void F_116 ( struct V_10 * V_11 , struct V_14 * V_15 )
{
if ( F_117 ( V_15 ) ) {
F_113 ( V_11 , V_15 , 0 ) ;
F_115 ( V_11 , V_15 ) ;
}
}
static void F_118 ( struct V_10 * V_11 , struct V_14 * V_15 )
{
F_35 ( V_11 , V_15 , L_7 ) ;
F_55 ( F_117 ( V_15 ) ) ;
F_119 ( V_15 ) ;
V_11 -> V_34 ++ ;
if ( F_7 ( V_15 ) )
V_11 -> V_169 ++ ;
F_116 ( V_11 , V_15 ) ;
}
static void F_120 ( struct V_10 * V_11 , struct V_14 * V_15 )
{
F_35 ( V_11 , V_15 , L_8 ) ;
F_55 ( ! F_117 ( V_15 ) ) ;
F_121 ( V_15 ) ;
if ( ! F_56 ( & V_15 -> V_91 ) ) {
F_51 ( & V_15 -> V_91 , V_15 -> V_157 ) ;
V_15 -> V_157 = NULL ;
}
if ( V_15 -> V_166 ) {
F_49 ( & V_15 -> V_164 , V_15 -> V_166 ) ;
V_15 -> V_166 = NULL ;
}
F_68 ( V_11 , V_15 -> V_3 ) ;
F_55 ( ! V_11 -> V_34 ) ;
V_11 -> V_34 -- ;
if ( F_7 ( V_15 ) )
V_11 -> V_169 -- ;
}
static void F_122 ( struct V_75 * V_170 )
{
struct V_14 * V_15 = F_123 ( V_170 ) ;
const int V_37 = F_42 ( V_170 ) ;
F_55 ( ! V_15 -> V_171 [ V_37 ] ) ;
V_15 -> V_171 [ V_37 ] -- ;
F_124 ( & V_15 -> V_98 , V_170 ) ;
if ( F_117 ( V_15 ) && F_102 ( & V_15 -> V_98 ) ) {
if ( V_15 -> V_166 ) {
F_49 ( & V_15 -> V_164 , V_15 -> V_166 ) ;
V_15 -> V_166 = NULL ;
}
}
}
static void F_125 ( struct V_75 * V_170 )
{
struct V_14 * V_15 = F_123 ( V_170 ) ;
struct V_10 * V_11 = V_15 -> V_11 ;
struct V_75 * V_97 ;
V_15 -> V_171 [ F_42 ( V_170 ) ] ++ ;
F_126 ( & V_15 -> V_98 , V_170 ) ;
if ( ! F_117 ( V_15 ) )
F_118 ( V_11 , V_15 ) ;
V_97 = V_15 -> V_165 ;
V_15 -> V_165 = F_39 ( V_11 , V_15 -> V_165 , V_170 , V_11 -> V_172 ) ;
if ( V_97 != V_15 -> V_165 )
F_115 ( V_11 , V_15 ) ;
F_55 ( ! V_15 -> V_165 ) ;
}
static void F_127 ( struct V_14 * V_15 , struct V_75 * V_170 )
{
F_124 ( & V_15 -> V_98 , V_170 ) ;
V_15 -> V_171 [ F_42 ( V_170 ) ] -- ;
F_128 ( & ( F_129 ( V_170 ) ) -> V_109 ,
F_130 ( V_170 ) , F_42 ( V_170 ) ) ;
F_125 ( V_170 ) ;
F_131 ( & ( F_129 ( V_170 ) ) -> V_109 ,
& V_15 -> V_11 -> V_173 -> V_109 , F_130 ( V_170 ) ,
F_42 ( V_170 ) ) ;
}
static struct V_75 *
F_132 ( struct V_10 * V_11 , struct V_30 * V_30 )
{
struct V_174 * V_175 = V_147 ;
struct V_23 * V_24 ;
struct V_14 * V_15 ;
V_24 = F_133 ( V_11 , V_175 -> V_176 ) ;
if ( ! V_24 )
return NULL ;
V_15 = F_11 ( V_24 , F_16 ( V_30 ) ) ;
if ( V_15 ) {
T_3 V_161 = V_30 -> V_177 + F_134 ( V_30 ) ;
return F_135 ( & V_15 -> V_98 , V_161 ) ;
}
return NULL ;
}
static void F_136 ( struct V_145 * V_146 , struct V_75 * V_170 )
{
struct V_10 * V_11 = V_146 -> V_178 -> V_179 ;
V_11 -> V_180 ++ ;
F_35 ( V_11 , F_123 ( V_170 ) , L_9 ,
V_11 -> V_180 ) ;
V_11 -> V_172 = F_43 ( V_170 ) + F_137 ( V_170 ) ;
}
static void F_138 ( struct V_145 * V_146 , struct V_75 * V_170 )
{
struct V_10 * V_11 = V_146 -> V_178 -> V_179 ;
F_22 ( ! V_11 -> V_180 ) ;
V_11 -> V_180 -- ;
F_35 ( V_11 , F_123 ( V_170 ) , L_10 ,
V_11 -> V_180 ) ;
}
static void F_139 ( struct V_75 * V_170 )
{
struct V_14 * V_15 = F_123 ( V_170 ) ;
if ( V_15 -> V_165 == V_170 )
V_15 -> V_165 = F_52 ( V_15 -> V_11 , V_15 , V_170 ) ;
F_140 ( & V_170 -> V_181 ) ;
F_122 ( V_170 ) ;
V_15 -> V_11 -> V_182 -- ;
F_128 ( & ( F_129 ( V_170 ) ) -> V_109 ,
F_130 ( V_170 ) , F_42 ( V_170 ) ) ;
if ( V_170 -> V_85 & V_86 ) {
F_22 ( ! V_15 -> V_183 ) ;
V_15 -> V_183 -- ;
}
}
static int F_141 ( struct V_145 * V_146 , struct V_75 * * V_184 ,
struct V_30 * V_30 )
{
struct V_10 * V_11 = V_146 -> V_178 -> V_179 ;
struct V_75 * V_185 ;
V_185 = F_132 ( V_11 , V_30 ) ;
if ( V_185 && F_142 ( V_185 , V_30 ) ) {
* V_184 = V_185 ;
return V_186 ;
}
return V_187 ;
}
static void F_143 ( struct V_145 * V_146 , struct V_75 * V_184 ,
int type )
{
if ( type == V_186 ) {
struct V_14 * V_15 = F_123 ( V_184 ) ;
F_127 ( V_15 , V_184 ) ;
}
}
static void F_144 ( struct V_145 * V_146 , struct V_75 * V_184 ,
struct V_30 * V_30 )
{
F_145 ( & ( F_129 ( V_184 ) ) -> V_109 ,
F_17 ( V_30 ) , F_16 ( V_30 ) ) ;
}
static void
F_146 ( struct V_145 * V_146 , struct V_75 * V_170 ,
struct V_75 * V_96 )
{
struct V_14 * V_15 = F_123 ( V_170 ) ;
if ( ! F_147 ( & V_170 -> V_181 ) && ! F_147 ( & V_96 -> V_181 ) &&
F_38 ( F_148 ( V_96 ) , F_148 ( V_170 ) ) ) {
F_149 ( & V_170 -> V_181 , & V_96 -> V_181 ) ;
F_150 ( V_170 , F_148 ( V_96 ) ) ;
}
if ( V_15 -> V_165 == V_96 )
V_15 -> V_165 = V_170 ;
F_139 ( V_96 ) ;
F_145 ( & ( F_129 ( V_170 ) ) -> V_109 ,
F_130 ( V_96 ) , F_42 ( V_96 ) ) ;
}
static int F_151 ( struct V_145 * V_146 , struct V_75 * V_170 ,
struct V_30 * V_30 )
{
struct V_10 * V_11 = V_146 -> V_178 -> V_179 ;
struct V_23 * V_24 ;
struct V_14 * V_15 ;
if ( F_16 ( V_30 ) && ! F_42 ( V_170 ) )
return false ;
V_24 = F_133 ( V_11 , V_147 -> V_176 ) ;
if ( ! V_24 )
return false ;
V_15 = F_11 ( V_24 , F_16 ( V_30 ) ) ;
return V_15 == F_123 ( V_170 ) ;
}
static inline void F_152 ( struct V_10 * V_11 , struct V_14 * V_15 )
{
F_153 ( & V_11 -> V_188 ) ;
F_154 ( & V_15 -> V_3 -> V_109 ) ;
}
static void F_155 ( struct V_10 * V_11 ,
struct V_14 * V_15 )
{
if ( V_15 ) {
F_35 ( V_11 , V_15 , L_11 ,
V_11 -> V_122 , V_11 -> V_120 ) ;
F_156 ( & V_15 -> V_3 -> V_109 ) ;
V_15 -> V_71 = 0 ;
V_15 -> V_112 = V_72 ;
V_15 -> V_74 = 0 ;
V_15 -> V_73 = 0 ;
V_15 -> V_117 = 0 ;
V_15 -> V_123 = 0 ;
F_157 ( V_15 ) ;
F_158 ( V_15 ) ;
F_159 ( V_15 ) ;
F_160 ( V_15 ) ;
F_161 ( V_15 ) ;
F_152 ( V_11 , V_15 ) ;
}
V_11 -> V_189 = V_15 ;
}
static void
F_162 ( struct V_10 * V_11 , struct V_14 * V_15 ,
bool V_190 )
{
F_35 ( V_11 , V_15 , L_12 , V_190 ) ;
if ( F_163 ( V_15 ) )
F_152 ( V_11 , V_15 ) ;
F_157 ( V_15 ) ;
F_164 ( V_15 ) ;
if ( F_165 ( V_15 ) && F_166 ( V_15 ) )
F_167 ( V_15 ) ;
if ( V_190 ) {
if ( F_37 ( V_15 ) )
V_15 -> V_159 = F_33 ( V_11 , V_15 ) ;
else
V_15 -> V_159 = V_15 -> V_73 - V_72 ;
F_35 ( V_11 , V_15 , L_13 , V_15 -> V_159 ) ;
}
F_74 ( V_11 , V_15 -> V_3 , V_15 ) ;
if ( F_117 ( V_15 ) && F_102 ( & V_15 -> V_98 ) )
F_120 ( V_11 , V_15 ) ;
F_116 ( V_11 , V_15 ) ;
if ( V_15 == V_11 -> V_189 )
V_11 -> V_189 = NULL ;
if ( V_11 -> V_191 ) {
F_168 ( V_11 -> V_191 -> V_192 ) ;
V_11 -> V_191 = NULL ;
}
}
static inline void F_169 ( struct V_10 * V_11 , bool V_190 )
{
struct V_14 * V_15 = V_11 -> V_189 ;
if ( V_15 )
F_162 ( V_11 , V_15 , V_190 ) ;
}
static struct V_14 * F_170 ( struct V_10 * V_11 )
{
struct V_1 * V_157 =
F_1 ( V_11 -> V_173 , V_11 -> V_122 ,
V_11 -> V_120 ) ;
if ( ! V_11 -> V_182 )
return NULL ;
if ( ! V_157 )
return NULL ;
if ( F_102 ( & V_157 -> V_90 ) )
return NULL ;
return F_44 ( V_157 ) ;
}
static struct V_14 * F_171 ( struct V_10 * V_11 )
{
struct V_2 * V_3 ;
struct V_14 * V_15 ;
int V_135 , V_136 ;
struct V_1 * V_50 ;
if ( ! V_11 -> V_182 )
return NULL ;
V_3 = F_172 ( V_11 ) ;
if ( ! V_3 )
return NULL ;
F_88 (cfqg, i, j, st)
if ( ( V_15 = F_44 ( V_50 ) ) != NULL )
return V_15 ;
return NULL ;
}
static struct V_14 * F_173 ( struct V_10 * V_11 ,
struct V_14 * V_15 )
{
if ( ! V_15 )
V_15 = F_170 ( V_11 ) ;
F_155 ( V_11 , V_15 ) ;
return V_15 ;
}
static inline T_3 F_174 ( struct V_10 * V_11 ,
struct V_75 * V_170 )
{
if ( F_43 ( V_170 ) >= V_11 -> V_172 )
return F_43 ( V_170 ) - V_11 -> V_172 ;
else
return V_11 -> V_172 - F_43 ( V_170 ) ;
}
static inline int F_175 ( struct V_10 * V_11 , struct V_14 * V_15 ,
struct V_75 * V_170 )
{
return F_174 ( V_11 , V_170 ) <= V_193 ;
}
static struct V_14 * F_176 ( struct V_10 * V_11 ,
struct V_14 * V_194 )
{
struct V_93 * V_89 = & V_11 -> V_167 [ V_194 -> V_168 ] ;
struct V_91 * V_101 , * V_100 ;
struct V_14 * V_155 ;
T_3 V_161 = V_11 -> V_172 ;
if ( F_102 ( V_89 ) )
return NULL ;
V_155 = F_114 ( V_11 , V_89 , V_161 , & V_101 , NULL ) ;
if ( V_155 )
return V_155 ;
V_155 = F_46 ( V_101 , struct V_14 , V_164 ) ;
if ( F_175 ( V_11 , V_194 , V_155 -> V_165 ) )
return V_155 ;
if ( F_43 ( V_155 -> V_165 ) < V_161 )
V_100 = F_53 ( & V_155 -> V_164 ) ;
else
V_100 = F_54 ( & V_155 -> V_164 ) ;
if ( ! V_100 )
return NULL ;
V_155 = F_46 ( V_100 , struct V_14 , V_164 ) ;
if ( F_175 ( V_11 , V_194 , V_155 -> V_165 ) )
return V_155 ;
return NULL ;
}
static struct V_14 * F_177 ( struct V_10 * V_11 ,
struct V_14 * V_194 )
{
struct V_14 * V_15 ;
if ( F_4 ( V_194 ) )
return NULL ;
if ( ! F_7 ( V_194 ) )
return NULL ;
if ( F_166 ( V_194 ) )
return NULL ;
if ( V_194 -> V_3 -> V_99 == 1 )
return NULL ;
V_15 = F_176 ( V_11 , V_194 ) ;
if ( ! V_15 )
return NULL ;
if ( V_194 -> V_3 != V_15 -> V_3 )
return NULL ;
if ( ! F_7 ( V_15 ) )
return NULL ;
if ( F_166 ( V_15 ) )
return NULL ;
if ( F_5 ( V_15 ) != F_5 ( V_194 ) )
return NULL ;
return V_15 ;
}
static bool F_178 ( struct V_10 * V_11 , struct V_14 * V_15 )
{
enum V_4 V_5 = F_3 ( V_15 ) ;
struct V_1 * V_157 = V_15 -> V_157 ;
F_55 ( ! V_157 ) ;
F_55 ( ! V_157 -> V_22 ) ;
if ( ! V_11 -> V_12 )
return false ;
if ( V_5 == V_7 )
return false ;
if ( F_8 ( V_15 ) &&
! ( F_179 ( V_11 -> V_35 ) && V_11 -> V_13 ) )
return true ;
if ( V_157 -> V_22 == 1 && F_7 ( V_15 ) &&
! F_180 ( V_11 , & V_157 -> V_140 , false ) )
return true ;
F_35 ( V_11 , V_15 , L_14 ,
V_157 -> V_22 ) ;
return false ;
}
static void F_181 ( struct V_10 * V_11 )
{
struct V_14 * V_15 = V_11 -> V_189 ;
struct V_23 * V_24 ;
unsigned long V_195 , V_196 = 0 ;
if ( F_179 ( V_11 -> V_35 ) && V_11 -> V_13 )
return;
F_22 ( ! F_102 ( & V_15 -> V_98 ) ) ;
F_22 ( F_37 ( V_15 ) ) ;
if ( ! F_178 ( V_11 , V_15 ) ) {
if ( V_11 -> V_197 )
V_196 = V_11 -> V_197 ;
else
return;
}
if ( V_15 -> V_198 )
return;
V_24 = V_11 -> V_191 ;
if ( ! V_24 || ! F_182 ( & V_24 -> V_192 -> V_199 ) )
return;
if ( F_183 ( V_24 -> V_140 . V_200 ) &&
( V_15 -> V_73 - V_72 < V_24 -> V_140 . V_201 ) ) {
F_35 ( V_11 , V_15 , L_15 ,
V_24 -> V_140 . V_201 ) ;
return;
}
if ( V_196 && V_15 -> V_3 -> V_99 > 1 )
return;
F_184 ( V_15 ) ;
if ( V_196 )
V_195 = V_11 -> V_197 ;
else
V_195 = V_11 -> V_12 ;
F_185 ( & V_11 -> V_188 , V_72 + V_195 ) ;
F_186 ( & V_15 -> V_3 -> V_109 ) ;
F_35 ( V_11 , V_15 , L_16 , V_195 ,
V_196 ? 1 : 0 ) ;
}
static void F_187 ( struct V_145 * V_146 , struct V_75 * V_170 )
{
struct V_10 * V_11 = V_146 -> V_178 -> V_179 ;
struct V_14 * V_15 = F_123 ( V_170 ) ;
F_35 ( V_11 , V_15 , L_17 ) ;
V_15 -> V_165 = F_52 ( V_11 , V_15 , V_170 ) ;
F_139 ( V_170 ) ;
V_15 -> V_198 ++ ;
( F_129 ( V_170 ) ) -> V_198 ++ ;
F_188 ( V_146 , V_170 ) ;
V_11 -> V_202 [ F_7 ( V_15 ) ] ++ ;
V_15 -> V_123 += F_137 ( V_170 ) ;
F_189 ( & V_15 -> V_3 -> V_109 , F_190 ( V_170 ) ,
F_130 ( V_170 ) , F_42 ( V_170 ) ) ;
}
static struct V_75 * F_191 ( struct V_14 * V_15 )
{
struct V_75 * V_170 = NULL ;
if ( F_192 ( V_15 ) )
return NULL ;
F_193 ( V_15 ) ;
if ( F_147 ( & V_15 -> V_203 ) )
return NULL ;
V_170 = F_194 ( V_15 -> V_203 . V_96 ) ;
if ( F_38 ( V_72 , F_148 ( V_170 ) ) )
V_170 = NULL ;
F_35 ( V_15 -> V_11 , V_15 , L_18 , V_170 ) ;
return V_170 ;
}
static inline int
F_195 ( struct V_10 * V_11 , struct V_14 * V_15 )
{
const int V_204 = V_11 -> V_205 ;
F_22 ( V_15 -> V_42 >= V_40 ) ;
return 2 * V_204 * ( V_40 - V_15 -> V_42 ) ;
}
static int F_196 ( struct V_14 * V_15 )
{
int V_206 , V_207 ;
V_207 = V_15 -> V_208 [ V_31 ] + V_15 -> V_208 [ V_209 ] ;
V_206 = V_15 -> V_142 - V_207 ;
F_55 ( V_206 < 0 ) ;
return V_206 ;
}
static void F_197 ( struct V_14 * V_15 , struct V_14 * V_158 )
{
int V_206 , V_210 ;
struct V_14 * V_155 ;
if ( ! F_196 ( V_158 ) )
return;
while ( ( V_155 = V_158 -> V_158 ) ) {
if ( V_155 == V_15 )
return;
V_158 = V_155 ;
}
V_206 = F_196 ( V_15 ) ;
V_210 = F_196 ( V_158 ) ;
if ( V_206 == 0 || V_210 == 0 )
return;
if ( V_210 >= V_206 ) {
V_15 -> V_158 = V_158 ;
V_158 -> V_142 += V_206 ;
} else {
V_158 -> V_158 = V_15 ;
V_15 -> V_142 += V_210 ;
}
}
static enum V_6 F_198 ( struct V_10 * V_11 ,
struct V_2 * V_3 , enum V_4 V_5 )
{
struct V_14 * V_35 ;
int V_135 ;
bool V_211 = false ;
unsigned long V_212 = 0 ;
enum V_6 V_213 = V_19 ;
for ( V_135 = 0 ; V_135 <= V_20 ; ++ V_135 ) {
V_35 = F_44 ( F_1 ( V_3 , V_5 , V_135 ) ) ;
if ( V_35 &&
( ! V_211 || F_38 ( V_35 -> V_156 , V_212 ) ) ) {
V_212 = V_35 -> V_156 ;
V_213 = V_135 ;
V_211 = true ;
}
}
return V_213 ;
}
static void F_199 ( struct V_10 * V_11 , struct V_2 * V_3 )
{
unsigned V_63 ;
unsigned V_22 ;
struct V_1 * V_50 ;
unsigned V_68 ;
enum V_4 V_214 = V_11 -> V_122 ;
if ( F_9 ( V_16 , V_11 , V_3 ) )
V_11 -> V_122 = V_16 ;
else if ( F_9 ( V_17 , V_11 , V_3 ) )
V_11 -> V_122 = V_17 ;
else {
V_11 -> V_122 = V_7 ;
V_11 -> V_118 = V_72 + 1 ;
return;
}
if ( V_214 != V_11 -> V_122 )
goto V_215;
V_50 = F_1 ( V_3 , V_11 -> V_122 , V_11 -> V_120 ) ;
V_22 = V_50 -> V_22 ;
if ( V_22 && ! F_73 ( V_72 , V_11 -> V_118 ) )
return;
V_215:
V_11 -> V_120 =
F_198 ( V_11 , V_3 , V_11 -> V_122 ) ;
V_50 = F_1 ( V_3 , V_11 -> V_122 , V_11 -> V_120 ) ;
V_22 = V_50 -> V_22 ;
V_68 = F_32 ( V_11 , V_3 ) ;
V_63 = V_68 * V_22 /
F_72 ( unsigned , V_3 -> V_59 [ V_11 -> V_122 ] ,
F_9 ( V_11 -> V_122 , V_11 , V_3 ) ) ;
if ( V_11 -> V_120 == V_18 ) {
unsigned int V_216 ;
V_216 = V_61 * F_10 ( V_11 , V_3 ) ;
V_216 = V_216 / V_11 -> V_34 ;
V_63 = F_200 ( unsigned , V_63 , V_216 ) ;
V_63 = V_63 * V_11 -> V_39 [ 0 ] / V_11 -> V_39 [ 1 ] ;
} else
V_63 = F_31 ( V_63 , 2 * V_11 -> V_12 ) ;
V_63 = F_72 ( unsigned , V_63 , V_217 ) ;
F_19 ( V_11 , L_19 , V_63 ) ;
V_11 -> V_118 = V_72 + V_63 ;
}
static struct V_2 * F_172 ( struct V_10 * V_11 )
{
struct V_1 * V_50 = & V_11 -> V_60 ;
struct V_2 * V_3 ;
if ( F_102 ( & V_50 -> V_90 ) )
return NULL ;
V_3 = F_47 ( V_50 ) ;
F_27 ( V_50 ) ;
return V_3 ;
}
static void F_201 ( struct V_10 * V_11 )
{
struct V_2 * V_3 = F_172 ( V_11 ) ;
V_11 -> V_173 = V_3 ;
if ( V_3 -> V_108 ) {
V_11 -> V_118 = V_72 + V_3 -> V_108 ;
V_11 -> V_120 = V_3 -> V_119 ;
V_11 -> V_122 = V_3 -> V_121 ;
} else
V_11 -> V_118 = V_72 - 1 ;
F_199 ( V_11 , V_3 ) ;
}
static struct V_14 * F_202 ( struct V_10 * V_11 )
{
struct V_14 * V_15 , * V_158 = NULL ;
V_15 = V_11 -> V_189 ;
if ( ! V_15 )
goto V_218;
if ( ! V_11 -> V_182 )
return NULL ;
if ( F_203 ( V_15 ) && ! F_102 ( & V_15 -> V_98 ) )
goto V_219;
if ( F_36 ( V_15 ) && ! F_204 ( V_15 ) ) {
if ( V_15 -> V_3 -> V_99 == 1 && F_102 ( & V_15 -> V_98 )
&& V_15 -> V_198 && F_178 ( V_11 , V_15 ) ) {
V_15 = NULL ;
goto V_220;
} else
goto V_221;
}
if ( ! F_102 ( & V_15 -> V_98 ) )
goto V_220;
V_158 = F_177 ( V_11 , V_15 ) ;
if ( V_158 ) {
if ( ! V_15 -> V_158 )
F_197 ( V_15 , V_158 ) ;
goto V_219;
}
if ( F_205 ( & V_11 -> V_188 ) ) {
V_15 = NULL ;
goto V_220;
}
if ( F_166 ( V_15 ) && F_8 ( V_15 ) &&
( F_37 ( V_15 ) ||
( V_15 -> V_73 - V_72 > V_72 - V_15 -> V_71 ) ) ) {
F_206 ( V_15 ) ;
F_207 ( V_15 ) ;
}
if ( V_15 -> V_198 && F_178 ( V_11 , V_15 ) ) {
V_15 = NULL ;
goto V_220;
}
V_221:
if ( V_11 -> V_197 && V_15 -> V_3 -> V_99 == 1 &&
V_15 -> V_3 -> V_198 &&
! F_180 ( V_11 , & V_15 -> V_3 -> V_140 , true ) ) {
V_15 = NULL ;
goto V_220;
}
V_219:
F_169 ( V_11 , 0 ) ;
V_218:
if ( ! V_158 )
F_201 ( V_11 ) ;
V_15 = F_173 ( V_11 , V_158 ) ;
V_220:
return V_15 ;
}
static int F_208 ( struct V_14 * V_15 )
{
int V_198 = 0 ;
while ( V_15 -> V_165 ) {
F_187 ( V_15 -> V_11 -> V_35 , V_15 -> V_165 ) ;
V_198 ++ ;
}
F_55 ( ! F_147 ( & V_15 -> V_203 ) ) ;
F_162 ( V_15 -> V_11 , V_15 , 0 ) ;
return V_198 ;
}
static int F_209 ( struct V_10 * V_11 )
{
struct V_14 * V_15 ;
int V_198 = 0 ;
F_169 ( V_11 , 0 ) ;
while ( ( V_15 = F_171 ( V_11 ) ) != NULL ) {
F_155 ( V_11 , V_15 ) ;
V_198 += F_208 ( V_15 ) ;
}
F_55 ( V_11 -> V_34 ) ;
F_19 ( V_11 , L_20 , V_198 ) ;
return V_198 ;
}
static inline bool F_210 ( struct V_10 * V_11 ,
struct V_14 * V_15 )
{
if ( F_37 ( V_15 ) )
return true ;
if ( F_73 ( V_72 + V_11 -> V_12 * V_15 -> V_198 ,
V_15 -> V_73 ) )
return true ;
return false ;
}
static bool F_211 ( struct V_10 * V_11 , struct V_14 * V_15 )
{
unsigned int V_222 ;
if ( F_178 ( V_11 , V_15 ) && V_11 -> V_202 [ V_223 ] )
return false ;
if ( V_11 -> V_202 [ V_224 ] && ! F_7 ( V_15 ) )
return false ;
V_222 = F_72 (unsigned int, cfqd->cfq_quantum / 2 , 1 ) ;
if ( F_4 ( V_15 ) )
V_222 = 1 ;
if ( V_15 -> V_198 >= V_222 ) {
bool V_225 = false ;
if ( F_4 ( V_15 ) )
return false ;
if ( F_7 ( V_15 ) && V_11 -> V_169 == 1 )
V_225 = true ;
if ( V_11 -> V_34 > 1 && F_210 ( V_11 , V_15 ) &&
! V_225 )
return false ;
if ( V_11 -> V_34 == 1 || V_225 )
V_222 = - 1 ;
else
V_222 = V_11 -> V_226 ;
}
if ( ! F_7 ( V_15 ) && V_11 -> V_64 ) {
unsigned long V_227 = V_72 - V_11 -> V_228 ;
unsigned int V_229 ;
V_229 = V_227 / V_11 -> V_39 [ 1 ] ;
if ( ! V_229 && ! V_15 -> V_198 )
V_229 = 1 ;
if ( V_229 < V_222 )
V_222 = V_229 ;
}
return V_15 -> V_198 < V_222 ;
}
static bool F_212 ( struct V_10 * V_11 , struct V_14 * V_15 )
{
struct V_75 * V_170 ;
F_55 ( F_102 ( & V_15 -> V_98 ) ) ;
if ( ! F_211 ( V_11 , V_15 ) )
return false ;
V_170 = F_191 ( V_15 ) ;
if ( ! V_170 )
V_170 = V_15 -> V_165 ;
F_187 ( V_11 -> V_35 , V_170 ) ;
if ( ! V_11 -> V_191 ) {
struct V_23 * V_24 = F_213 ( V_170 ) ;
F_214 ( & V_24 -> V_192 -> V_230 ) ;
V_11 -> V_191 = V_24 ;
}
return true ;
}
static int F_215 ( struct V_145 * V_146 , int V_231 )
{
struct V_10 * V_11 = V_146 -> V_178 -> V_179 ;
struct V_14 * V_15 ;
if ( ! V_11 -> V_34 )
return 0 ;
if ( F_15 ( V_231 ) )
return F_209 ( V_11 ) ;
V_15 = F_202 ( V_11 ) ;
if ( ! V_15 )
return 0 ;
if ( ! F_212 ( V_11 , V_15 ) )
return 0 ;
V_15 -> V_117 ++ ;
F_158 ( V_15 ) ;
if ( V_11 -> V_34 > 1 && ( ( ! F_7 ( V_15 ) &&
V_15 -> V_117 >= F_195 ( V_11 , V_15 ) ) ||
F_4 ( V_15 ) ) ) {
V_15 -> V_73 = V_72 + 1 ;
F_169 ( V_11 , 0 ) ;
}
F_35 ( V_11 , V_15 , L_21 ) ;
return 1 ;
}
static void F_216 ( struct V_14 * V_15 )
{
struct V_10 * V_11 = V_15 -> V_11 ;
struct V_2 * V_3 ;
F_55 ( V_15 -> V_142 <= 0 ) ;
V_15 -> V_142 -- ;
if ( V_15 -> V_142 )
return;
F_35 ( V_11 , V_15 , L_22 ) ;
F_55 ( F_45 ( & V_15 -> V_98 ) ) ;
F_55 ( V_15 -> V_208 [ V_31 ] + V_15 -> V_208 [ V_209 ] ) ;
V_3 = V_15 -> V_3 ;
if ( F_15 ( V_11 -> V_189 == V_15 ) ) {
F_162 ( V_11 , V_15 , 0 ) ;
F_18 ( V_11 ) ;
}
F_55 ( F_117 ( V_15 ) ) ;
F_217 ( V_232 , V_15 ) ;
F_101 ( V_3 ) ;
}
static void
F_218 ( struct V_176 * V_192 ,
void (* F_219)( struct V_176 * , struct V_23 * ) )
{
struct V_23 * V_24 ;
struct V_150 * V_92 ;
F_94 () ;
F_220 (cic, n, &ioc->cic_list, cic_list)
F_219 ( V_192 , V_24 ) ;
F_96 () ;
}
static void F_221 ( struct V_233 * V_234 )
{
struct V_23 * V_24 ;
V_24 = F_78 ( V_234 , struct V_23 , V_233 ) ;
F_217 ( V_235 , V_24 ) ;
F_222 ( V_236 ) ;
if ( V_237 ) {
F_223 ( & V_238 ) ;
if ( V_237 && ! F_224 ( V_236 ) ) {
F_225 ( V_237 ) ;
V_237 = NULL ;
}
F_226 ( & V_238 ) ;
}
}
static void F_227 ( struct V_23 * V_24 )
{
F_228 ( & V_24 -> V_233 , F_221 ) ;
}
static void F_229 ( struct V_176 * V_192 , struct V_23 * V_24 )
{
unsigned long V_152 ;
unsigned long V_239 = ( unsigned long ) V_24 -> V_29 ;
F_55 ( ! ( V_239 & V_28 ) ) ;
F_111 ( & V_192 -> V_240 , V_152 ) ;
F_230 ( & V_192 -> V_241 , V_239 >> V_27 ) ;
F_231 ( & V_24 -> V_242 ) ;
F_112 ( & V_192 -> V_240 , V_152 ) ;
F_227 ( V_24 ) ;
}
static void F_232 ( struct V_176 * V_192 )
{
F_218 ( V_192 , F_229 ) ;
}
static void F_233 ( struct V_14 * V_15 )
{
struct V_14 * V_155 , * V_96 ;
V_155 = V_15 -> V_158 ;
while ( V_155 ) {
if ( V_155 == V_15 ) {
F_234 ( 1 , L_23 ) ;
break;
}
V_96 = V_155 -> V_158 ;
F_216 ( V_155 ) ;
V_155 = V_96 ;
}
}
static void F_235 ( struct V_10 * V_11 , struct V_14 * V_15 )
{
if ( F_15 ( V_15 == V_11 -> V_189 ) ) {
F_162 ( V_11 , V_15 , 0 ) ;
F_18 ( V_11 ) ;
}
F_233 ( V_15 ) ;
F_216 ( V_15 ) ;
}
static void F_236 ( struct V_10 * V_11 ,
struct V_23 * V_24 )
{
struct V_176 * V_192 = V_24 -> V_192 ;
F_140 ( & V_24 -> V_243 ) ;
F_237 () ;
V_24 -> V_29 = F_13 ( V_11 ) ;
F_94 () ;
if ( F_238 ( V_192 -> V_244 ) == V_24 ) {
F_96 () ;
F_223 ( & V_192 -> V_240 ) ;
F_239 ( V_192 -> V_244 , NULL ) ;
F_226 ( & V_192 -> V_240 ) ;
} else
F_96 () ;
if ( V_24 -> V_15 [ V_223 ] ) {
F_235 ( V_11 , V_24 -> V_15 [ V_223 ] ) ;
V_24 -> V_15 [ V_223 ] = NULL ;
}
if ( V_24 -> V_15 [ V_224 ] ) {
F_235 ( V_11 , V_24 -> V_15 [ V_224 ] ) ;
V_24 -> V_15 [ V_224 ] = NULL ;
}
}
static void F_240 ( struct V_176 * V_192 ,
struct V_23 * V_24 )
{
struct V_10 * V_11 = F_14 ( V_24 ) ;
if ( V_11 ) {
struct V_145 * V_146 = V_11 -> V_35 ;
unsigned long V_152 ;
F_111 ( V_146 -> V_148 , V_152 ) ;
F_241 () ;
if ( V_24 -> V_29 == V_11 )
F_236 ( V_11 , V_24 ) ;
F_112 ( V_146 -> V_148 , V_152 ) ;
}
}
static void F_242 ( struct V_176 * V_192 )
{
F_218 ( V_192 , F_240 ) ;
}
static struct V_23 *
F_243 ( struct V_10 * V_11 , T_4 V_245 )
{
struct V_23 * V_24 ;
V_24 = F_244 ( V_235 , V_245 | V_246 ,
V_11 -> V_35 -> V_100 ) ;
if ( V_24 ) {
V_24 -> V_140 . V_141 = V_72 ;
F_245 ( & V_24 -> V_243 ) ;
F_246 ( & V_24 -> V_242 ) ;
V_24 -> V_247 = F_232 ;
V_24 -> exit = F_242 ;
F_247 ( V_236 ) ;
}
return V_24 ;
}
static void F_248 ( struct V_14 * V_15 , struct V_176 * V_192 )
{
struct V_174 * V_175 = V_147 ;
int V_248 ;
if ( ! F_249 ( V_15 ) )
return;
V_248 = F_250 ( V_192 -> V_42 ) ;
switch ( V_248 ) {
default:
F_251 ( V_249 L_24 , V_248 ) ;
case V_250 :
V_15 -> V_42 = F_252 ( V_175 ) ;
V_15 -> V_248 = F_253 ( V_175 ) ;
break;
case V_251 :
V_15 -> V_42 = F_254 ( V_192 ) ;
V_15 -> V_248 = V_251 ;
break;
case V_252 :
V_15 -> V_42 = F_254 ( V_192 ) ;
V_15 -> V_248 = V_252 ;
break;
case V_253 :
V_15 -> V_248 = V_253 ;
V_15 -> V_42 = 7 ;
F_207 ( V_15 ) ;
break;
}
V_15 -> V_168 = V_15 -> V_42 ;
F_255 ( V_15 ) ;
}
static void F_256 ( struct V_176 * V_192 , struct V_23 * V_24 )
{
struct V_10 * V_11 = F_14 ( V_24 ) ;
struct V_14 * V_15 ;
unsigned long V_152 ;
if ( F_15 ( ! V_11 ) )
return;
F_111 ( V_11 -> V_35 -> V_148 , V_152 ) ;
V_15 = V_24 -> V_15 [ V_223 ] ;
if ( V_15 ) {
struct V_14 * V_158 ;
V_158 = F_257 ( V_11 , V_223 , V_24 -> V_192 ,
V_138 ) ;
if ( V_158 ) {
V_24 -> V_15 [ V_223 ] = V_158 ;
F_216 ( V_15 ) ;
}
}
V_15 = V_24 -> V_15 [ V_224 ] ;
if ( V_15 )
F_258 ( V_15 ) ;
F_112 ( V_11 -> V_35 -> V_148 , V_152 ) ;
}
static void F_259 ( struct V_176 * V_192 )
{
F_218 ( V_192 , F_256 ) ;
V_192 -> V_254 = 0 ;
}
static void F_260 ( struct V_10 * V_11 , struct V_14 * V_15 ,
T_5 V_255 , bool V_25 )
{
F_50 ( & V_15 -> V_91 ) ;
F_50 ( & V_15 -> V_164 ) ;
F_245 ( & V_15 -> V_203 ) ;
V_15 -> V_142 = 0 ;
V_15 -> V_11 = V_11 ;
F_258 ( V_15 ) ;
if ( V_25 ) {
if ( ! F_4 ( V_15 ) )
F_261 ( V_15 ) ;
F_262 ( V_15 ) ;
}
V_15 -> V_255 = V_255 ;
}
static void F_263 ( struct V_176 * V_192 , struct V_23 * V_24 )
{
struct V_14 * V_256 = F_11 ( V_24 , 1 ) ;
struct V_10 * V_11 = F_14 ( V_24 ) ;
unsigned long V_152 ;
struct V_145 * V_146 ;
if ( F_15 ( ! V_11 ) )
return;
V_146 = V_11 -> V_35 ;
F_111 ( V_146 -> V_148 , V_152 ) ;
if ( V_256 ) {
F_35 ( V_11 , V_256 , L_25 ) ;
F_12 ( V_24 , NULL , 1 ) ;
F_216 ( V_256 ) ;
}
F_112 ( V_146 -> V_148 , V_152 ) ;
}
static void F_264 ( struct V_176 * V_192 )
{
F_218 ( V_192 , F_263 ) ;
V_192 -> V_257 = 0 ;
}
static struct V_14 *
F_265 ( struct V_10 * V_11 , bool V_25 ,
struct V_176 * V_192 , T_4 V_245 )
{
struct V_14 * V_15 , * V_158 = NULL ;
struct V_23 * V_24 ;
struct V_2 * V_3 ;
V_258:
V_3 = F_93 ( V_11 ) ;
V_24 = F_133 ( V_11 , V_192 ) ;
V_15 = F_11 ( V_24 , V_25 ) ;
if ( ! V_15 || V_15 == & V_11 -> V_259 ) {
V_15 = NULL ;
if ( V_158 ) {
V_15 = V_158 ;
V_158 = NULL ;
} else if ( V_245 & V_260 ) {
F_97 ( V_11 -> V_35 -> V_148 ) ;
V_158 = F_244 ( V_232 ,
V_245 | V_246 ,
V_11 -> V_35 -> V_100 ) ;
F_98 ( V_11 -> V_35 -> V_148 ) ;
if ( V_158 )
goto V_258;
} else {
V_15 = F_244 ( V_232 ,
V_245 | V_246 ,
V_11 -> V_35 -> V_100 ) ;
}
if ( V_15 ) {
F_260 ( V_11 , V_15 , V_147 -> V_255 , V_25 ) ;
F_248 ( V_15 , V_192 ) ;
F_100 ( V_15 , V_3 ) ;
F_35 ( V_11 , V_15 , L_26 ) ;
} else
V_15 = & V_11 -> V_259 ;
}
if ( V_158 )
F_217 ( V_232 , V_158 ) ;
return V_15 ;
}
static struct V_14 * *
F_266 ( struct V_10 * V_11 , int V_248 , int V_42 )
{
switch ( V_248 ) {
case V_251 :
return & V_11 -> V_261 [ 0 ] [ V_42 ] ;
case V_252 :
return & V_11 -> V_261 [ 1 ] [ V_42 ] ;
case V_253 :
return & V_11 -> V_262 ;
default:
F_267 () ;
}
}
static struct V_14 *
F_257 ( struct V_10 * V_11 , bool V_25 , struct V_176 * V_192 ,
T_4 V_245 )
{
const int V_42 = F_254 ( V_192 ) ;
const int V_248 = F_268 ( V_192 ) ;
struct V_14 * * V_261 = NULL ;
struct V_14 * V_15 = NULL ;
if ( ! V_25 ) {
V_261 = F_266 ( V_11 , V_248 , V_42 ) ;
V_15 = * V_261 ;
}
if ( ! V_15 )
V_15 = F_265 ( V_11 , V_25 , V_192 , V_245 ) ;
if ( ! V_25 && ! ( * V_261 ) ) {
V_15 -> V_142 ++ ;
* V_261 = V_15 ;
}
V_15 -> V_142 ++ ;
return V_15 ;
}
static void
F_269 ( struct V_10 * V_11 , struct V_176 * V_192 ,
struct V_23 * V_24 )
{
unsigned long V_152 ;
F_22 ( ! F_147 ( & V_24 -> V_243 ) ) ;
F_55 ( V_24 -> V_29 != F_13 ( V_11 ) ) ;
F_111 ( & V_192 -> V_240 , V_152 ) ;
F_55 ( F_270 ( V_192 -> V_244 ,
F_271 ( & V_192 -> V_240 ) ) == V_24 ) ;
F_230 ( & V_192 -> V_241 , V_11 -> V_26 ) ;
F_231 ( & V_24 -> V_242 ) ;
F_112 ( & V_192 -> V_240 , V_152 ) ;
F_227 ( V_24 ) ;
}
static struct V_23 *
F_133 ( struct V_10 * V_11 , struct V_176 * V_192 )
{
struct V_23 * V_24 ;
unsigned long V_152 ;
if ( F_15 ( ! V_192 ) )
return NULL ;
F_94 () ;
V_24 = F_238 ( V_192 -> V_244 ) ;
if ( V_24 && V_24 -> V_29 == V_11 ) {
F_96 () ;
return V_24 ;
}
do {
V_24 = F_272 ( & V_192 -> V_241 , V_11 -> V_26 ) ;
F_96 () ;
if ( ! V_24 )
break;
if ( F_15 ( V_24 -> V_29 != V_11 ) ) {
F_269 ( V_11 , V_192 , V_24 ) ;
F_94 () ;
continue;
}
F_111 ( & V_192 -> V_240 , V_152 ) ;
F_239 ( V_192 -> V_244 , V_24 ) ;
F_112 ( & V_192 -> V_240 , V_152 ) ;
break;
} while ( 1 );
return V_24 ;
}
static int F_273 ( struct V_10 * V_11 , struct V_176 * V_192 ,
struct V_23 * V_24 , T_4 V_245 )
{
unsigned long V_152 ;
int V_137 ;
V_137 = F_274 ( V_245 ) ;
if ( ! V_137 ) {
V_24 -> V_192 = V_192 ;
V_24 -> V_29 = V_11 ;
F_111 ( & V_192 -> V_240 , V_152 ) ;
V_137 = F_275 ( & V_192 -> V_241 ,
V_11 -> V_26 , V_24 ) ;
if ( ! V_137 )
F_276 ( & V_24 -> V_242 , & V_192 -> V_242 ) ;
F_112 ( & V_192 -> V_240 , V_152 ) ;
F_277 () ;
if ( ! V_137 ) {
F_111 ( V_11 -> V_35 -> V_148 , V_152 ) ;
F_278 ( & V_24 -> V_243 , & V_11 -> V_242 ) ;
F_112 ( V_11 -> V_35 -> V_148 , V_152 ) ;
}
}
if ( V_137 )
F_251 ( V_249 L_27 ) ;
return V_137 ;
}
static struct V_23 *
F_279 ( struct V_10 * V_11 , T_4 V_245 )
{
struct V_176 * V_192 = NULL ;
struct V_23 * V_24 ;
F_280 ( V_245 & V_260 ) ;
V_192 = F_281 ( V_245 , V_11 -> V_35 -> V_100 ) ;
if ( ! V_192 )
return NULL ;
V_24 = F_133 ( V_11 , V_192 ) ;
if ( V_24 )
goto V_263;
V_24 = F_243 ( V_11 , V_245 ) ;
if ( V_24 == NULL )
goto V_264;
if ( F_273 ( V_11 , V_192 , V_24 , V_245 ) )
goto V_265;
V_263:
F_241 () ;
if ( F_15 ( V_192 -> V_254 ) )
F_259 ( V_192 ) ;
#ifdef F_282
if ( F_15 ( V_192 -> V_257 ) )
F_264 ( V_192 ) ;
#endif
return V_24 ;
V_265:
F_227 ( V_24 ) ;
V_264:
F_168 ( V_192 ) ;
return NULL ;
}
static void
F_283 ( struct V_266 * V_140 , unsigned long V_267 )
{
unsigned long V_268 = V_72 - V_140 -> V_141 ;
V_268 = F_30 ( V_268 , 2UL * V_267 ) ;
V_140 -> V_200 = ( 7 * V_140 -> V_200 + 256 ) / 8 ;
V_140 -> V_269 = ( 7 * V_140 -> V_269 + 256 * V_268 ) / 8 ;
V_140 -> V_201 = ( V_140 -> V_269 + 128 ) / V_140 -> V_200 ;
}
static void
F_284 ( struct V_10 * V_11 , struct V_14 * V_15 ,
struct V_23 * V_24 )
{
if ( F_7 ( V_15 ) ) {
F_283 ( & V_24 -> V_140 , V_11 -> V_12 ) ;
F_283 ( & V_15 -> V_157 -> V_140 ,
V_11 -> V_12 ) ;
}
#ifdef F_282
F_283 ( & V_15 -> V_3 -> V_140 , V_11 -> V_197 ) ;
#endif
}
static void
F_285 ( struct V_10 * V_11 , struct V_14 * V_15 ,
struct V_75 * V_170 )
{
T_3 V_270 = 0 ;
T_3 V_271 = F_137 ( V_170 ) ;
if ( V_15 -> V_272 ) {
if ( V_15 -> V_272 < F_43 ( V_170 ) )
V_270 = F_43 ( V_170 ) - V_15 -> V_272 ;
else
V_270 = V_15 -> V_272 - F_43 ( V_170 ) ;
}
V_15 -> V_273 <<= 1 ;
if ( F_179 ( V_11 -> V_35 ) )
V_15 -> V_273 |= ( V_271 < V_274 ) ;
else
V_15 -> V_273 |= ( V_270 > V_275 ) ;
}
static void
F_286 ( struct V_10 * V_11 , struct V_14 * V_15 ,
struct V_23 * V_24 )
{
int V_276 , V_277 ;
if ( ! F_7 ( V_15 ) || F_4 ( V_15 ) )
return;
V_277 = V_276 = F_8 ( V_15 ) ;
if ( V_15 -> V_171 [ 0 ] + V_15 -> V_171 [ 1 ] >= 4 )
F_287 ( V_15 ) ;
if ( V_15 -> V_165 && ( V_15 -> V_165 -> V_85 & V_278 ) )
V_277 = 0 ;
else if ( ! F_182 ( & V_24 -> V_192 -> V_199 ) || ! V_11 -> V_12 ||
( ! F_288 ( V_15 ) && F_166 ( V_15 ) ) )
V_277 = 0 ;
else if ( F_183 ( V_24 -> V_140 . V_200 ) ) {
if ( V_24 -> V_140 . V_201 > V_11 -> V_12 )
V_277 = 0 ;
else
V_277 = 1 ;
}
if ( V_276 != V_277 ) {
F_35 ( V_11 , V_15 , L_28 , V_277 ) ;
if ( V_277 )
F_261 ( V_15 ) ;
else
F_207 ( V_15 ) ;
}
}
static bool
F_289 ( struct V_10 * V_11 , struct V_14 * V_158 ,
struct V_75 * V_170 )
{
struct V_14 * V_15 ;
V_15 = V_11 -> V_189 ;
if ( ! V_15 )
return false ;
if ( F_4 ( V_158 ) )
return false ;
if ( F_4 ( V_15 ) )
return true ;
if ( F_5 ( V_15 ) && ! F_5 ( V_158 ) )
return false ;
if ( F_42 ( V_170 ) && ! F_7 ( V_15 ) )
return true ;
if ( V_158 -> V_3 != V_15 -> V_3 )
return false ;
if ( F_36 ( V_15 ) )
return true ;
if ( V_11 -> V_120 == V_19 &&
F_6 ( V_158 ) == V_19 &&
V_158 -> V_157 -> V_22 == 2 &&
F_102 ( & V_15 -> V_98 ) )
return true ;
if ( ( V_170 -> V_85 & V_86 ) && ! V_15 -> V_183 )
return true ;
if ( F_5 ( V_158 ) && ! F_5 ( V_15 ) )
return true ;
if ( F_102 ( & V_15 -> V_98 ) && ! F_178 ( V_11 , V_15 ) )
return true ;
if ( ! V_11 -> V_191 || ! F_163 ( V_15 ) )
return false ;
if ( F_175 ( V_11 , V_15 , V_170 ) )
return true ;
return false ;
}
static void F_290 ( struct V_10 * V_11 , struct V_14 * V_15 )
{
struct V_14 * V_279 = V_11 -> V_189 ;
F_35 ( V_11 , V_15 , L_29 ) ;
F_169 ( V_11 , 1 ) ;
if ( F_6 ( V_279 ) != F_6 ( V_15 ) )
V_15 -> V_3 -> V_108 = 0 ;
F_55 ( ! F_117 ( V_15 ) ) ;
F_113 ( V_11 , V_15 , 1 ) ;
V_15 -> V_73 = 0 ;
F_161 ( V_15 ) ;
}
static void
F_291 ( struct V_10 * V_11 , struct V_14 * V_15 ,
struct V_75 * V_170 )
{
struct V_23 * V_24 = F_213 ( V_170 ) ;
V_11 -> V_182 ++ ;
if ( V_170 -> V_85 & V_86 )
V_15 -> V_183 ++ ;
F_284 ( V_11 , V_15 , V_24 ) ;
F_285 ( V_11 , V_15 , V_170 ) ;
F_286 ( V_11 , V_15 , V_24 ) ;
V_15 -> V_272 = F_43 ( V_170 ) + F_137 ( V_170 ) ;
if ( V_15 == V_11 -> V_189 ) {
if ( F_163 ( V_15 ) ) {
if ( F_190 ( V_170 ) > V_280 ||
V_11 -> V_34 > 1 ) {
F_152 ( V_11 , V_15 ) ;
F_157 ( V_15 ) ;
F_292 ( V_11 -> V_35 ) ;
} else {
F_154 (
& V_15 -> V_3 -> V_109 ) ;
F_293 ( V_15 ) ;
}
}
} else if ( F_289 ( V_11 , V_15 , V_170 ) ) {
F_290 ( V_11 , V_15 ) ;
F_292 ( V_11 -> V_35 ) ;
}
}
static void F_294 ( struct V_145 * V_146 , struct V_75 * V_170 )
{
struct V_10 * V_11 = V_146 -> V_178 -> V_179 ;
struct V_14 * V_15 = F_123 ( V_170 ) ;
F_35 ( V_11 , V_15 , L_30 ) ;
F_248 ( V_15 , F_213 ( V_170 ) -> V_192 ) ;
F_150 ( V_170 , V_72 + V_11 -> V_281 [ F_42 ( V_170 ) ] ) ;
F_295 ( & V_170 -> V_181 , & V_15 -> V_203 ) ;
F_125 ( V_170 ) ;
F_131 ( & ( F_129 ( V_170 ) ) -> V_109 ,
& V_11 -> V_173 -> V_109 , F_130 ( V_170 ) ,
F_42 ( V_170 ) ) ;
F_291 ( V_11 , V_15 , V_170 ) ;
}
static void F_296 ( struct V_10 * V_11 )
{
struct V_14 * V_15 = V_11 -> V_189 ;
if ( V_11 -> V_180 > V_11 -> V_282 )
V_11 -> V_282 = V_11 -> V_180 ;
if ( V_11 -> V_13 == 1 )
return;
if ( V_11 -> V_182 <= V_283 &&
V_11 -> V_180 <= V_283 )
return;
if ( V_15 && F_8 ( V_15 ) &&
V_15 -> V_198 + V_15 -> V_171 [ 0 ] + V_15 -> V_171 [ 1 ] <
V_283 && V_11 -> V_180 < V_283 )
return;
if ( V_11 -> V_284 ++ < 50 )
return;
if ( V_11 -> V_282 >= V_283 )
V_11 -> V_13 = 1 ;
else
V_11 -> V_13 = 0 ;
}
static bool F_297 ( struct V_10 * V_11 , struct V_14 * V_15 )
{
struct V_23 * V_24 = V_11 -> V_191 ;
if ( ! F_102 ( & V_15 -> V_98 ) )
return false ;
if ( V_15 -> V_3 -> V_99 > 1 )
return false ;
if ( F_180 ( V_11 , & V_15 -> V_3 -> V_140 , true ) )
return false ;
if ( F_36 ( V_15 ) )
return true ;
if ( V_24 && F_183 ( V_24 -> V_140 . V_200 )
&& ( V_15 -> V_73 - V_72 < V_24 -> V_140 . V_201 ) )
return true ;
if ( V_15 -> V_73 - V_72 == 1 )
return true ;
return false ;
}
static void F_298 ( struct V_145 * V_146 , struct V_75 * V_170 )
{
struct V_14 * V_15 = F_123 ( V_170 ) ;
struct V_10 * V_11 = V_15 -> V_11 ;
const int V_37 = F_42 ( V_170 ) ;
unsigned long V_285 ;
V_285 = V_72 ;
F_35 ( V_11 , V_15 , L_31 ,
! ! ( V_170 -> V_85 & V_278 ) ) ;
F_296 ( V_11 ) ;
F_22 ( ! V_11 -> V_180 ) ;
F_22 ( ! V_15 -> V_198 ) ;
V_11 -> V_180 -- ;
V_15 -> V_198 -- ;
( F_129 ( V_170 ) ) -> V_198 -- ;
F_299 ( & V_15 -> V_3 -> V_109 ,
F_300 ( V_170 ) , F_301 ( V_170 ) ,
F_130 ( V_170 ) , F_42 ( V_170 ) ) ;
V_11 -> V_202 [ F_7 ( V_15 ) ] -- ;
if ( V_37 ) {
struct V_1 * V_157 ;
F_213 ( V_170 ) -> V_140 . V_141 = V_285 ;
if ( F_117 ( V_15 ) )
V_157 = V_15 -> V_157 ;
else
V_157 = F_1 ( V_15 -> V_3 ,
F_3 ( V_15 ) , F_6 ( V_15 ) ) ;
V_157 -> V_140 . V_141 = V_285 ;
if ( ! F_73 ( V_170 -> V_286 + V_11 -> V_281 [ 1 ] , V_285 ) )
V_11 -> V_228 = V_285 ;
}
#ifdef F_282
V_15 -> V_3 -> V_140 . V_141 = V_285 ;
#endif
if ( V_11 -> V_189 == V_15 ) {
const bool V_287 = F_102 ( & V_15 -> V_98 ) ;
if ( F_37 ( V_15 ) ) {
F_34 ( V_11 , V_15 ) ;
F_302 ( V_15 ) ;
}
if ( F_297 ( V_11 , V_15 ) ) {
unsigned long V_288 = V_11 -> V_12 ;
if ( ! V_11 -> V_12 )
V_288 = V_11 -> V_197 ;
V_15 -> V_73 = V_72 + V_288 ;
F_303 ( V_15 ) ;
F_35 ( V_11 , V_15 , L_32 ) ;
}
if ( F_36 ( V_15 ) || F_4 ( V_15 ) )
F_169 ( V_11 , 1 ) ;
else if ( V_37 && V_287 &&
! F_177 ( V_11 , V_15 ) ) {
F_181 ( V_11 ) ;
}
}
if ( ! V_11 -> V_180 )
F_18 ( V_11 ) ;
}
static inline int F_304 ( struct V_14 * V_15 )
{
if ( F_163 ( V_15 ) && ! F_305 ( V_15 ) ) {
F_306 ( V_15 ) ;
return V_289 ;
}
return V_290 ;
}
static int F_307 ( struct V_145 * V_146 , int V_291 )
{
struct V_10 * V_11 = V_146 -> V_178 -> V_179 ;
struct V_174 * V_175 = V_147 ;
struct V_23 * V_24 ;
struct V_14 * V_15 ;
V_24 = F_133 ( V_11 , V_175 -> V_176 ) ;
if ( ! V_24 )
return V_290 ;
V_15 = F_11 ( V_24 , F_308 ( V_291 ) ) ;
if ( V_15 ) {
F_248 ( V_15 , V_24 -> V_192 ) ;
return F_304 ( V_15 ) ;
}
return V_290 ;
}
static void F_309 ( struct V_75 * V_170 )
{
struct V_14 * V_15 = F_123 ( V_170 ) ;
if ( V_15 ) {
const int V_291 = F_130 ( V_170 ) ;
F_55 ( ! V_15 -> V_208 [ V_291 ] ) ;
V_15 -> V_208 [ V_291 ] -- ;
F_168 ( F_213 ( V_170 ) -> V_192 ) ;
V_170 -> V_292 [ 0 ] = NULL ;
V_170 -> V_292 [ 1 ] = NULL ;
F_101 ( F_129 ( V_170 ) ) ;
V_170 -> V_292 [ 2 ] = NULL ;
F_216 ( V_15 ) ;
}
}
static struct V_14 *
F_310 ( struct V_10 * V_11 , struct V_23 * V_24 ,
struct V_14 * V_15 )
{
F_35 ( V_11 , V_15 , L_33 , V_15 -> V_158 ) ;
F_12 ( V_24 , V_15 -> V_158 , 1 ) ;
F_311 ( V_15 -> V_158 ) ;
F_216 ( V_15 ) ;
return F_11 ( V_24 , 1 ) ;
}
static struct V_14 *
F_312 ( struct V_23 * V_24 , struct V_14 * V_15 )
{
if ( F_196 ( V_15 ) == 1 ) {
V_15 -> V_255 = V_147 -> V_255 ;
F_313 ( V_15 ) ;
F_314 ( V_15 ) ;
return V_15 ;
}
F_12 ( V_24 , NULL , 1 ) ;
F_233 ( V_15 ) ;
F_216 ( V_15 ) ;
return NULL ;
}
static int
F_315 ( struct V_145 * V_146 , struct V_75 * V_170 , T_4 V_245 )
{
struct V_10 * V_11 = V_146 -> V_178 -> V_179 ;
struct V_23 * V_24 ;
const int V_291 = F_130 ( V_170 ) ;
const bool V_25 = F_42 ( V_170 ) ;
struct V_14 * V_15 ;
unsigned long V_152 ;
F_280 ( V_245 & V_260 ) ;
V_24 = F_279 ( V_11 , V_245 ) ;
F_111 ( V_146 -> V_148 , V_152 ) ;
if ( ! V_24 )
goto V_293;
V_218:
V_15 = F_11 ( V_24 , V_25 ) ;
if ( ! V_15 || V_15 == & V_11 -> V_259 ) {
V_15 = F_257 ( V_11 , V_25 , V_24 -> V_192 , V_245 ) ;
F_12 ( V_24 , V_15 , V_25 ) ;
} else {
if ( F_165 ( V_15 ) && F_316 ( V_15 ) ) {
F_35 ( V_11 , V_15 , L_34 ) ;
V_15 = F_312 ( V_24 , V_15 ) ;
if ( ! V_15 )
goto V_218;
}
if ( V_15 -> V_158 )
V_15 = F_310 ( V_11 , V_24 , V_15 ) ;
}
V_15 -> V_208 [ V_291 ] ++ ;
V_15 -> V_142 ++ ;
V_170 -> V_292 [ 0 ] = V_24 ;
V_170 -> V_292 [ 1 ] = V_15 ;
V_170 -> V_292 [ 2 ] = F_99 ( V_15 -> V_3 ) ;
F_112 ( V_146 -> V_148 , V_152 ) ;
return 0 ;
V_293:
F_18 ( V_11 ) ;
F_112 ( V_146 -> V_148 , V_152 ) ;
F_19 ( V_11 , L_35 ) ;
return 1 ;
}
static void F_317 ( struct V_294 * V_295 )
{
struct V_10 * V_11 =
F_78 ( V_295 , struct V_10 , V_36 ) ;
struct V_145 * V_146 = V_11 -> V_35 ;
F_98 ( V_146 -> V_148 ) ;
F_292 ( V_11 -> V_35 ) ;
F_97 ( V_146 -> V_148 ) ;
}
static void F_318 ( unsigned long V_296 )
{
struct V_10 * V_11 = (struct V_10 * ) V_296 ;
struct V_14 * V_15 ;
unsigned long V_152 ;
int V_190 = 1 ;
F_19 ( V_11 , L_36 ) ;
F_111 ( V_11 -> V_35 -> V_148 , V_152 ) ;
V_15 = V_11 -> V_189 ;
if ( V_15 ) {
V_190 = 0 ;
if ( F_204 ( V_15 ) )
goto V_297;
if ( F_36 ( V_15 ) )
goto V_219;
if ( ! V_11 -> V_34 )
goto V_298;
if ( ! F_102 ( & V_15 -> V_98 ) )
goto V_297;
F_206 ( V_15 ) ;
}
V_219:
F_169 ( V_11 , V_190 ) ;
V_297:
F_18 ( V_11 ) ;
V_298:
F_112 ( V_11 -> V_35 -> V_148 , V_152 ) ;
}
static void F_319 ( struct V_10 * V_11 )
{
F_320 ( & V_11 -> V_188 ) ;
F_321 ( & V_11 -> V_36 ) ;
}
static void F_322 ( struct V_10 * V_11 )
{
int V_135 ;
for ( V_135 = 0 ; V_135 < V_40 ; V_135 ++ ) {
if ( V_11 -> V_261 [ 0 ] [ V_135 ] )
F_216 ( V_11 -> V_261 [ 0 ] [ V_135 ] ) ;
if ( V_11 -> V_261 [ 1 ] [ V_135 ] )
F_216 ( V_11 -> V_261 [ 1 ] [ V_135 ] ) ;
}
if ( V_11 -> V_262 )
F_216 ( V_11 -> V_262 ) ;
}
static void F_323 ( struct V_299 * V_300 )
{
struct V_10 * V_11 = V_300 -> V_179 ;
struct V_145 * V_146 = V_11 -> V_35 ;
bool V_301 = false ;
F_319 ( V_11 ) ;
F_98 ( V_146 -> V_148 ) ;
if ( V_11 -> V_189 )
F_162 ( V_11 , V_11 -> V_189 , 0 ) ;
while ( ! F_147 ( & V_11 -> V_242 ) ) {
struct V_23 * V_24 = F_324 ( V_11 -> V_242 . V_96 ,
struct V_23 ,
V_243 ) ;
F_236 ( V_11 , V_24 ) ;
}
F_322 ( V_11 ) ;
F_107 ( V_11 ) ;
if ( V_11 -> V_132 )
V_301 = true ;
F_97 ( V_146 -> V_148 ) ;
F_319 ( V_11 ) ;
F_223 ( & V_302 ) ;
F_325 ( & V_303 , V_11 -> V_26 ) ;
F_226 ( & V_302 ) ;
if ( V_301 )
F_326 () ;
#ifdef F_282
F_103 ( V_11 -> V_144 . V_109 . V_149 ) ;
#endif
F_90 ( V_11 ) ;
}
static int F_327 ( void )
{
int V_304 , error ;
do {
if ( ! F_328 ( & V_303 , V_305 ) )
return - V_306 ;
F_223 ( & V_302 ) ;
error = F_329 ( & V_303 , & V_304 ) ;
F_226 ( & V_302 ) ;
if ( error && error != - V_307 )
return error ;
} while ( error );
return V_304 ;
}
static void * F_330 ( struct V_145 * V_146 )
{
struct V_10 * V_11 ;
int V_135 , V_136 ;
struct V_2 * V_3 ;
struct V_1 * V_50 ;
V_135 = F_327 () ;
if ( V_135 < 0 )
return NULL ;
V_11 = F_331 ( sizeof( * V_11 ) , V_305 | V_246 , V_146 -> V_100 ) ;
if ( ! V_11 ) {
F_223 ( & V_302 ) ;
F_325 ( & V_303 , V_135 ) ;
F_226 ( & V_302 ) ;
return NULL ;
}
V_11 -> V_26 = V_135 ;
V_11 -> V_60 = V_139 ;
V_3 = & V_11 -> V_144 ;
F_88 ( V_3 , V_135 , V_136 , V_50 )
* V_50 = V_139 ;
F_50 ( & V_3 -> V_91 ) ;
V_3 -> V_47 = 2 * V_46 ;
#ifdef F_282
V_3 -> V_142 = 2 ;
if ( F_89 ( & V_3 -> V_109 ) ) {
F_90 ( V_3 ) ;
F_90 ( V_11 ) ;
return NULL ;
}
F_94 () ;
F_82 ( & V_143 , & V_3 -> V_109 ,
( void * ) V_11 , 0 ) ;
F_96 () ;
V_11 -> V_132 ++ ;
F_85 ( & V_3 -> V_133 , & V_11 -> V_134 ) ;
#endif
for ( V_135 = 0 ; V_135 < V_308 ; V_135 ++ )
V_11 -> V_167 [ V_135 ] = V_309 ;
F_260 ( V_11 , & V_11 -> V_259 , 1 , 0 ) ;
V_11 -> V_259 . V_142 ++ ;
F_100 ( & V_11 -> V_259 , & V_11 -> V_144 ) ;
F_245 ( & V_11 -> V_242 ) ;
V_11 -> V_35 = V_146 ;
F_332 ( & V_11 -> V_188 ) ;
V_11 -> V_188 . V_310 = F_318 ;
V_11 -> V_188 . V_296 = ( unsigned long ) V_11 ;
F_333 ( & V_11 -> V_36 , F_317 ) ;
V_11 -> V_226 = V_226 ;
V_11 -> V_281 [ 0 ] = V_281 [ 0 ] ;
V_11 -> V_281 [ 1 ] = V_281 [ 1 ] ;
V_11 -> V_87 = V_87 ;
V_11 -> V_88 = V_88 ;
V_11 -> V_39 [ 0 ] = V_311 ;
V_11 -> V_39 [ 1 ] = V_312 ;
V_11 -> V_205 = V_205 ;
V_11 -> V_12 = V_12 ;
V_11 -> V_197 = V_197 ;
V_11 -> V_64 = 1 ;
V_11 -> V_13 = - 1 ;
V_11 -> V_228 = V_72 - V_160 ;
return V_11 ;
}
static void F_334 ( void )
{
if ( V_232 )
F_335 ( V_232 ) ;
if ( V_235 )
F_335 ( V_235 ) ;
}
static int T_6 F_336 ( void )
{
V_232 = F_337 ( V_14 , 0 ) ;
if ( ! V_232 )
goto V_313;
V_235 = F_337 ( V_23 , 0 ) ;
if ( ! V_235 )
goto V_313;
return 0 ;
V_313:
F_334 () ;
return - V_306 ;
}
static T_7
F_338 ( unsigned int V_314 , char * V_315 )
{
return sprintf ( V_315 , L_37 , V_314 ) ;
}
static T_7
F_339 ( unsigned int * V_314 , const char * V_315 , T_8 V_22 )
{
char * V_154 = ( char * ) V_315 ;
* V_314 = F_340 ( V_154 , & V_154 , 10 ) ;
return V_22 ;
}
static int T_6 F_341 ( void )
{
if ( ! V_311 )
V_311 = 1 ;
if ( ! V_12 )
V_12 = 1 ;
#ifdef F_282
if ( ! V_197 )
V_197 = 1 ;
#else
V_197 = 0 ;
#endif
if ( F_336 () )
return - V_306 ;
F_342 ( & V_316 ) ;
F_343 ( & V_317 ) ;
return 0 ;
}
static void T_9 F_344 ( void )
{
F_345 ( V_318 ) ;
F_346 ( & V_317 ) ;
F_347 ( & V_316 ) ;
V_237 = & V_318 ;
F_237 () ;
if ( F_224 ( V_236 ) )
F_348 ( & V_318 ) ;
F_349 ( & V_303 ) ;
F_334 () ;
}
