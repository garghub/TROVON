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
static inline struct V_23 * F_11 ( struct V_24 * V_25 )
{
return F_12 ( V_25 , struct V_23 , V_25 ) ;
}
static inline struct V_23 * F_13 ( struct V_10 * V_11 ,
struct V_26 * V_27 )
{
if ( V_27 )
return F_11 ( F_14 ( V_27 , V_11 -> V_28 ) ) ;
return NULL ;
}
static inline struct V_14 * F_15 ( struct V_23 * V_29 , bool V_30 )
{
return V_29 -> V_15 [ V_30 ] ;
}
static inline void F_16 ( struct V_23 * V_29 , struct V_14 * V_15 ,
bool V_30 )
{
V_29 -> V_15 [ V_30 ] = V_15 ;
}
static inline struct V_10 * F_17 ( struct V_23 * V_29 )
{
return V_29 -> V_25 . V_31 -> V_32 -> V_33 ;
}
static inline bool F_18 ( struct V_34 * V_34 )
{
return F_19 ( V_34 ) == V_35 || ( V_34 -> V_36 & V_37 ) ;
}
static inline void F_20 ( struct V_10 * V_11 )
{
if ( V_11 -> V_38 ) {
F_21 ( V_11 , L_1 ) ;
F_22 ( V_11 -> V_28 , & V_11 -> V_39 ) ;
}
}
static inline int F_23 ( struct V_10 * V_11 , bool V_40 ,
unsigned short V_5 )
{
const int V_41 = V_11 -> V_42 [ V_40 ] ;
F_24 ( V_5 >= V_43 ) ;
return V_41 + ( V_41 / V_44 * ( 4 - V_5 ) ) ;
}
static inline int
F_25 ( struct V_10 * V_11 , struct V_14 * V_15 )
{
return F_23 ( V_11 , F_7 ( V_15 ) , V_15 -> V_45 ) ;
}
static inline T_1 F_26 ( unsigned long V_46 , struct V_2 * V_3 )
{
T_1 V_47 = V_46 << V_48 ;
V_47 = V_47 * V_49 ;
F_27 ( V_47 , V_3 -> V_50 ) ;
return V_47 ;
}
static inline T_1 F_28 ( T_1 V_51 , T_1 V_52 )
{
T_2 V_46 = ( T_2 ) ( V_52 - V_51 ) ;
if ( V_46 > 0 )
V_51 = V_52 ;
return V_51 ;
}
static inline T_1 V_51 ( T_1 V_51 , T_1 V_52 )
{
T_2 V_46 = ( T_2 ) ( V_52 - V_51 ) ;
if ( V_46 < 0 )
V_51 = V_52 ;
return V_51 ;
}
static void F_29 ( struct V_1 * V_53 )
{
struct V_2 * V_3 ;
if ( V_53 -> V_54 ) {
V_3 = F_30 ( V_53 -> V_54 ) ;
V_53 -> V_51 = F_28 ( V_53 -> V_51 ,
V_3 -> V_52 ) ;
}
}
static inline unsigned F_31 ( struct V_10 * V_11 ,
struct V_2 * V_3 , bool V_55 )
{
unsigned V_56 , V_57 ;
unsigned V_58 = V_59 - 1 ;
unsigned V_60 = V_59 / 2 ;
unsigned V_61 = F_9 ( V_55 , V_11 , V_3 ) ;
V_56 = F_32 ( V_3 -> V_62 [ V_55 ] , V_61 ) ;
V_57 = F_33 ( V_3 -> V_62 [ V_55 ] , V_61 ) ;
V_3 -> V_62 [ V_55 ] = ( V_58 * V_57 + V_56 + V_60 ) /
V_59 ;
return V_3 -> V_62 [ V_55 ] ;
}
static inline unsigned
F_34 ( struct V_10 * V_11 , struct V_2 * V_3 )
{
struct V_1 * V_53 = & V_11 -> V_63 ;
return V_11 -> V_64 * V_3 -> V_50 / V_53 -> V_65 ;
}
static inline unsigned
F_35 ( struct V_10 * V_11 , struct V_14 * V_15 )
{
unsigned V_66 = F_25 ( V_11 , V_15 ) ;
if ( V_11 -> V_67 ) {
unsigned V_68 = F_31 ( V_11 , V_15 -> V_3 ,
F_5 ( V_15 ) ) ;
unsigned V_69 = V_11 -> V_42 [ 1 ] ;
unsigned V_70 = V_69 * V_68 ;
unsigned V_71 = F_34 ( V_11 , V_15 -> V_3 ) ;
if ( V_70 > V_71 ) {
unsigned V_72 = 2 * V_11 -> V_12 ;
unsigned V_73 =
F_32 ( V_66 , V_72 * V_66 / V_69 ) ;
V_66 = F_33 ( V_66 * V_71 / V_70 ,
V_73 ) ;
}
}
return V_66 ;
}
static inline void
F_36 ( struct V_10 * V_11 , struct V_14 * V_15 )
{
unsigned V_66 = F_35 ( V_11 , V_15 ) ;
V_15 -> V_74 = V_75 ;
V_15 -> V_76 = V_75 + V_66 ;
V_15 -> V_77 = V_66 ;
F_37 ( V_11 , V_15 , L_2 , V_15 -> V_76 - V_75 ) ;
}
static inline bool F_38 ( struct V_14 * V_15 )
{
if ( F_39 ( V_15 ) )
return false ;
if ( F_40 ( V_75 , V_15 -> V_76 ) )
return false ;
return true ;
}
static struct V_78 *
F_41 ( struct V_10 * V_11 , struct V_78 * V_79 , struct V_78 * V_80 , T_3 V_81 )
{
T_3 V_82 , V_83 , V_84 = 0 , V_85 = 0 ;
unsigned long V_86 ;
#define F_42 0x01
#define F_43 0x02
unsigned V_87 = 0 ;
if ( V_79 == NULL || V_79 == V_80 )
return V_80 ;
if ( V_80 == NULL )
return V_79 ;
if ( F_44 ( V_79 ) != F_44 ( V_80 ) )
return F_44 ( V_79 ) ? V_79 : V_80 ;
if ( ( V_79 -> V_88 ^ V_80 -> V_88 ) & V_89 )
return V_79 -> V_88 & V_89 ? V_79 : V_80 ;
V_82 = F_45 ( V_79 ) ;
V_83 = F_45 ( V_80 ) ;
V_86 = V_11 -> V_90 * 2 ;
if ( V_82 >= V_81 )
V_84 = V_82 - V_81 ;
else if ( V_82 + V_86 >= V_81 )
V_84 = ( V_81 - V_82 ) * V_11 -> V_91 ;
else
V_87 |= F_42 ;
if ( V_83 >= V_81 )
V_85 = V_83 - V_81 ;
else if ( V_83 + V_86 >= V_81 )
V_85 = ( V_81 - V_83 ) * V_11 -> V_91 ;
else
V_87 |= F_43 ;
switch ( V_87 ) {
case 0 :
if ( V_84 < V_85 )
return V_79 ;
else if ( V_85 < V_84 )
return V_80 ;
else {
if ( V_82 >= V_83 )
return V_79 ;
else
return V_80 ;
}
case F_43 :
return V_79 ;
case F_42 :
return V_80 ;
case ( F_42 | F_43 ) :
default:
if ( V_82 <= V_83 )
return V_79 ;
else
return V_80 ;
}
}
static struct V_14 * F_46 ( struct V_1 * V_92 )
{
if ( ! V_92 -> V_22 )
return NULL ;
if ( ! V_92 -> V_54 )
V_92 -> V_54 = F_47 ( & V_92 -> V_93 ) ;
if ( V_92 -> V_54 )
return F_48 ( V_92 -> V_54 , struct V_14 , V_94 ) ;
return NULL ;
}
static struct V_2 * F_49 ( struct V_1 * V_92 )
{
if ( ! V_92 -> V_54 )
V_92 -> V_54 = F_47 ( & V_92 -> V_93 ) ;
if ( V_92 -> V_54 )
return F_30 ( V_92 -> V_54 ) ;
return NULL ;
}
static void F_50 ( struct V_94 * V_95 , struct V_96 * V_92 )
{
F_51 ( V_95 , V_92 ) ;
F_52 ( V_95 ) ;
}
static void F_53 ( struct V_94 * V_95 , struct V_1 * V_92 )
{
if ( V_92 -> V_54 == V_95 )
V_92 -> V_54 = NULL ;
F_50 ( V_95 , & V_92 -> V_93 ) ;
-- V_92 -> V_22 ;
}
static struct V_78 *
F_54 ( struct V_10 * V_11 , struct V_14 * V_15 ,
struct V_78 * V_81 )
{
struct V_94 * V_97 = F_55 ( & V_81 -> V_94 ) ;
struct V_94 * V_98 = F_56 ( & V_81 -> V_94 ) ;
struct V_78 * V_99 = NULL , * V_100 = NULL ;
F_57 ( F_58 ( & V_81 -> V_94 ) ) ;
if ( V_98 )
V_100 = F_59 ( V_98 ) ;
if ( V_97 )
V_99 = F_59 ( V_97 ) ;
else {
V_97 = F_47 ( & V_15 -> V_101 ) ;
if ( V_97 && V_97 != & V_81 -> V_94 )
V_99 = F_59 ( V_97 ) ;
}
return F_41 ( V_11 , V_99 , V_100 , F_45 ( V_81 ) ) ;
}
static unsigned long F_60 ( struct V_10 * V_11 ,
struct V_14 * V_15 )
{
return ( V_15 -> V_3 -> V_102 - 1 ) * ( F_23 ( V_11 , 1 , 0 ) -
F_23 ( V_11 , F_7 ( V_15 ) , V_15 -> V_45 ) ) ;
}
static inline T_2
F_61 ( struct V_1 * V_53 , struct V_2 * V_3 )
{
return V_3 -> V_52 - V_53 -> V_51 ;
}
static void
F_62 ( struct V_1 * V_53 , struct V_2 * V_3 )
{
struct V_94 * * V_103 = & V_53 -> V_93 . V_94 ;
struct V_94 * V_104 = NULL ;
struct V_2 * V_105 ;
T_2 V_106 = F_61 ( V_53 , V_3 ) ;
int V_54 = 1 ;
while ( * V_103 != NULL ) {
V_104 = * V_103 ;
V_105 = F_30 ( V_104 ) ;
if ( V_106 < F_61 ( V_53 , V_105 ) )
V_103 = & V_104 -> V_107 ;
else {
V_103 = & V_104 -> V_108 ;
V_54 = 0 ;
}
}
if ( V_54 )
V_53 -> V_54 = & V_3 -> V_94 ;
F_63 ( & V_3 -> V_94 , V_104 , V_103 ) ;
F_64 ( & V_3 -> V_94 , & V_53 -> V_93 ) ;
}
static void
F_65 ( struct V_2 * V_3 )
{
F_57 ( ! F_58 ( & V_3 -> V_94 ) ) ;
if ( V_3 -> V_109 ) {
V_3 -> V_50 = V_3 -> V_110 ;
V_3 -> V_109 = false ;
}
}
static void
F_66 ( struct V_1 * V_53 , struct V_2 * V_3 )
{
F_57 ( ! F_58 ( & V_3 -> V_94 ) ) ;
F_65 ( V_3 ) ;
F_62 ( V_53 , V_3 ) ;
V_53 -> V_65 += V_3 -> V_50 ;
}
static void
F_67 ( struct V_10 * V_11 , struct V_2 * V_3 )
{
struct V_1 * V_53 = & V_11 -> V_63 ;
struct V_2 * V_105 ;
struct V_94 * V_95 ;
V_3 -> V_102 ++ ;
if ( ! F_58 ( & V_3 -> V_94 ) )
return;
V_95 = F_68 ( & V_53 -> V_93 ) ;
if ( V_95 ) {
V_105 = F_30 ( V_95 ) ;
V_3 -> V_52 = V_105 -> V_52 + V_111 ;
} else
V_3 -> V_52 = V_53 -> V_51 ;
F_66 ( V_53 , V_3 ) ;
}
static void
F_69 ( struct V_1 * V_53 , struct V_2 * V_3 )
{
V_53 -> V_65 -= V_3 -> V_50 ;
if ( ! F_58 ( & V_3 -> V_94 ) )
F_53 ( & V_3 -> V_94 , V_53 ) ;
}
static void
F_70 ( struct V_10 * V_11 , struct V_2 * V_3 )
{
struct V_1 * V_53 = & V_11 -> V_63 ;
F_57 ( V_3 -> V_102 < 1 ) ;
V_3 -> V_102 -- ;
if ( V_3 -> V_102 )
return;
F_71 ( V_11 , V_3 , L_3 ) ;
F_69 ( V_53 , V_3 ) ;
V_3 -> V_112 = 0 ;
F_72 ( & V_3 -> V_113 , 1 ) ;
}
static inline unsigned int F_73 ( struct V_14 * V_15 ,
unsigned int * V_114 )
{
unsigned int V_115 ;
if ( ! V_15 -> V_74 || V_15 -> V_74 == V_75 ) {
V_115 = F_74 ( unsigned , ( V_75 - V_15 -> V_116 ) ,
1 ) ;
} else {
V_115 = V_75 - V_15 -> V_74 ;
if ( V_115 > V_15 -> V_77 ) {
* V_114 = V_115 - V_15 -> V_77 ;
V_115 = V_15 -> V_77 ;
}
if ( F_75 ( V_15 -> V_74 , V_15 -> V_116 ) )
* V_114 += V_15 -> V_74 -
V_15 -> V_116 ;
}
return V_115 ;
}
static void F_76 ( struct V_10 * V_11 , struct V_2 * V_3 ,
struct V_14 * V_15 )
{
struct V_1 * V_53 = & V_11 -> V_63 ;
unsigned int V_117 , V_118 , V_119 = 0 ;
int V_120 = V_3 -> V_102 - F_10 ( V_11 , V_3 )
- V_3 -> V_8 . V_22 ;
F_57 ( V_120 < 0 ) ;
V_117 = V_118 = F_73 ( V_15 , & V_119 ) ;
if ( F_2 ( V_11 ) )
V_118 = V_15 -> V_121 ;
else if ( ! F_7 ( V_15 ) && ! V_120 )
V_118 = V_15 -> V_77 ;
F_69 ( V_53 , V_3 ) ;
V_3 -> V_52 += F_26 ( V_118 , V_3 ) ;
F_66 ( V_53 , V_3 ) ;
if ( F_75 ( V_11 -> V_122 , V_75 ) ) {
V_3 -> V_112 = V_11 -> V_122
- V_75 ;
V_3 -> V_123 = V_11 -> V_124 ;
V_3 -> V_125 = V_11 -> V_126 ;
} else
V_3 -> V_112 = 0 ;
F_71 ( V_11 , V_3 , L_4 , V_3 -> V_52 ,
V_53 -> V_51 ) ;
F_37 ( V_15 -> V_11 , V_15 ,
L_5 ,
V_117 , V_15 -> V_121 , V_118 ,
F_2 ( V_11 ) , V_15 -> V_127 ) ;
F_77 ( & V_3 -> V_113 , V_117 ,
V_119 ) ;
F_78 ( & V_3 -> V_113 ) ;
}
static inline struct V_2 * F_79 ( struct V_128 * V_113 )
{
if ( V_113 )
return F_12 ( V_113 , struct V_2 , V_113 ) ;
return NULL ;
}
static void F_80 ( void * V_106 , struct V_128 * V_113 ,
unsigned int V_50 )
{
struct V_2 * V_3 = F_79 ( V_113 ) ;
V_3 -> V_110 = V_50 ;
V_3 -> V_109 = true ;
}
static void F_81 ( struct V_10 * V_11 ,
struct V_2 * V_3 , struct V_129 * V_130 )
{
struct V_131 * V_132 = & V_11 -> V_28 -> V_131 ;
unsigned int V_133 , V_134 ;
if ( V_132 -> V_135 ) {
sscanf ( F_82 ( V_132 -> V_135 ) , L_6 , & V_133 , & V_134 ) ;
F_83 ( V_130 , & V_3 -> V_113 ,
( void * ) V_11 , F_84 ( V_133 , V_134 ) ) ;
} else
F_83 ( V_130 , & V_3 -> V_113 ,
( void * ) V_11 , 0 ) ;
V_11 -> V_136 ++ ;
V_3 -> V_50 = F_85 ( V_130 , V_3 -> V_113 . V_135 ) ;
F_86 ( & V_3 -> V_137 , & V_11 -> V_138 ) ;
}
static struct V_2 * F_87 ( struct V_10 * V_11 )
{
struct V_2 * V_3 = NULL ;
int V_139 , V_140 , V_141 ;
struct V_1 * V_53 ;
V_3 = F_88 ( sizeof( * V_3 ) , V_142 , V_11 -> V_28 -> V_103 ) ;
if ( ! V_3 )
return NULL ;
F_89 ( V_3 , V_139 , V_140 , V_53 )
* V_53 = V_143 ;
F_52 ( & V_3 -> V_94 ) ;
V_3 -> V_144 . V_145 = V_75 ;
V_3 -> V_146 = 1 ;
V_141 = F_90 ( & V_3 -> V_113 ) ;
if ( V_141 ) {
F_91 ( V_3 ) ;
return NULL ;
}
return V_3 ;
}
static struct V_2 *
F_92 ( struct V_10 * V_11 , struct V_129 * V_130 )
{
struct V_2 * V_3 = NULL ;
void * V_106 = V_11 ;
struct V_131 * V_132 = & V_11 -> V_28 -> V_131 ;
unsigned int V_133 , V_134 ;
if ( V_130 == & V_147 )
V_3 = & V_11 -> V_148 ;
else
V_3 = F_79 ( F_93 ( V_130 , V_106 ) ) ;
if ( V_3 && ! V_3 -> V_113 . V_135 && V_132 -> V_135 && F_82 ( V_132 -> V_135 ) ) {
sscanf ( F_82 ( V_132 -> V_135 ) , L_6 , & V_133 , & V_134 ) ;
V_3 -> V_113 . V_135 = F_84 ( V_133 , V_134 ) ;
}
return V_3 ;
}
static struct V_2 * F_94 ( struct V_10 * V_11 )
{
struct V_129 * V_130 ;
struct V_2 * V_3 = NULL , * V_105 = NULL ;
struct V_149 * V_31 = V_11 -> V_28 ;
F_95 () ;
V_130 = F_96 ( V_150 ) ;
V_3 = F_92 ( V_11 , V_130 ) ;
if ( V_3 ) {
F_97 () ;
return V_3 ;
}
F_97 () ;
F_98 ( V_31 -> V_151 ) ;
V_3 = F_87 ( V_11 ) ;
F_99 ( V_31 -> V_151 ) ;
F_95 () ;
V_130 = F_96 ( V_150 ) ;
V_105 = F_92 ( V_11 , V_130 ) ;
if ( V_105 ) {
F_91 ( V_3 ) ;
F_97 () ;
return V_105 ;
}
if ( ! V_3 )
V_3 = & V_11 -> V_148 ;
F_81 ( V_11 , V_3 , V_130 ) ;
F_97 () ;
return V_3 ;
}
static inline struct V_2 * F_100 ( struct V_2 * V_3 )
{
V_3 -> V_146 ++ ;
return V_3 ;
}
static void F_101 ( struct V_14 * V_15 , struct V_2 * V_3 )
{
if ( ! F_7 ( V_15 ) )
V_3 = & V_15 -> V_11 -> V_148 ;
V_15 -> V_3 = V_3 ;
V_15 -> V_3 -> V_146 ++ ;
}
static void F_102 ( struct V_2 * V_3 )
{
struct V_1 * V_53 ;
int V_139 , V_140 ;
F_57 ( V_3 -> V_146 <= 0 ) ;
V_3 -> V_146 -- ;
if ( V_3 -> V_146 )
return;
F_89 (cfqg, i, j, st)
F_57 ( ! F_103 ( & V_53 -> V_93 ) ) ;
F_104 ( V_3 -> V_113 . V_152 ) ;
F_91 ( V_3 ) ;
}
static void F_105 ( struct V_10 * V_11 , struct V_2 * V_3 )
{
F_57 ( F_106 ( & V_3 -> V_137 ) ) ;
F_107 ( & V_3 -> V_137 ) ;
F_57 ( V_11 -> V_136 <= 0 ) ;
V_11 -> V_136 -- ;
F_102 ( V_3 ) ;
}
static void F_108 ( struct V_10 * V_11 )
{
struct V_153 * V_154 , * V_95 ;
struct V_2 * V_3 ;
F_109 (cfqg, pos, n, &cfqd->cfqg_list, cfqd_node) {
if ( ! F_110 ( & V_3 -> V_113 ) )
F_105 ( V_11 , V_3 ) ;
}
}
static void F_111 ( void * V_106 , struct V_128 * V_113 )
{
unsigned long V_155 ;
struct V_10 * V_11 = V_106 ;
F_112 ( V_11 -> V_28 -> V_151 , V_155 ) ;
F_105 ( V_11 , F_79 ( V_113 ) ) ;
F_113 ( V_11 -> V_28 -> V_151 , V_155 ) ;
}
static struct V_2 * F_94 ( struct V_10 * V_11 )
{
return & V_11 -> V_148 ;
}
static inline struct V_2 * F_100 ( struct V_2 * V_3 )
{
return V_3 ;
}
static inline void
F_101 ( struct V_14 * V_15 , struct V_2 * V_3 ) {
V_15 -> V_3 = V_3 ;
}
static void F_108 ( struct V_10 * V_11 ) {}
static inline void F_102 ( struct V_2 * V_3 ) {}
static void F_114 ( struct V_10 * V_11 , struct V_14 * V_15 ,
bool V_156 )
{
struct V_94 * * V_157 , * V_104 ;
struct V_14 * V_158 ;
unsigned long V_159 ;
struct V_1 * V_160 ;
int V_54 ;
int V_161 = 1 ;
V_160 = F_1 ( V_15 -> V_3 , F_3 ( V_15 ) ,
F_6 ( V_15 ) ) ;
if ( F_4 ( V_15 ) ) {
V_159 = V_111 ;
V_104 = F_68 ( & V_160 -> V_93 ) ;
if ( V_104 && V_104 != & V_15 -> V_94 ) {
V_158 = F_48 ( V_104 , struct V_14 , V_94 ) ;
V_159 += V_158 -> V_159 ;
} else
V_159 += V_75 ;
} else if ( ! V_156 ) {
V_159 = F_60 ( V_11 , V_15 ) + V_75 ;
V_159 -= V_15 -> V_162 ;
V_15 -> V_162 = 0 ;
} else {
V_159 = - V_163 ;
V_158 = F_46 ( V_160 ) ;
V_159 += V_158 ? V_158 -> V_159 : V_75 ;
}
if ( ! F_58 ( & V_15 -> V_94 ) ) {
V_161 = 0 ;
if ( V_159 == V_15 -> V_159 &&
V_15 -> V_160 == V_160 )
return;
F_53 ( & V_15 -> V_94 , V_15 -> V_160 ) ;
V_15 -> V_160 = NULL ;
}
V_54 = 1 ;
V_104 = NULL ;
V_15 -> V_160 = V_160 ;
V_157 = & V_160 -> V_93 . V_94 ;
while ( * V_157 ) {
struct V_94 * * V_95 ;
V_104 = * V_157 ;
V_158 = F_48 ( V_104 , struct V_14 , V_94 ) ;
if ( F_40 ( V_159 , V_158 -> V_159 ) )
V_95 = & ( * V_157 ) -> V_107 ;
else {
V_95 = & ( * V_157 ) -> V_108 ;
V_54 = 0 ;
}
V_157 = V_95 ;
}
if ( V_54 )
V_160 -> V_54 = & V_15 -> V_94 ;
V_15 -> V_159 = V_159 ;
F_63 ( & V_15 -> V_94 , V_104 , V_157 ) ;
F_64 ( & V_15 -> V_94 , & V_160 -> V_93 ) ;
V_160 -> V_22 ++ ;
if ( V_156 || ! V_161 )
return;
F_67 ( V_11 , V_15 -> V_3 ) ;
}
static struct V_14 *
F_115 ( struct V_10 * V_11 , struct V_96 * V_92 ,
T_3 V_164 , struct V_94 * * V_165 ,
struct V_94 * * * V_166 )
{
struct V_94 * * V_157 , * V_104 ;
struct V_14 * V_15 = NULL ;
V_104 = NULL ;
V_157 = & V_92 -> V_94 ;
while ( * V_157 ) {
struct V_94 * * V_95 ;
V_104 = * V_157 ;
V_15 = F_48 ( V_104 , struct V_14 , V_167 ) ;
if ( V_164 > F_45 ( V_15 -> V_168 ) )
V_95 = & ( * V_157 ) -> V_108 ;
else if ( V_164 < F_45 ( V_15 -> V_168 ) )
V_95 = & ( * V_157 ) -> V_107 ;
else
break;
V_157 = V_95 ;
V_15 = NULL ;
}
* V_165 = V_104 ;
if ( V_166 )
* V_166 = V_157 ;
return V_15 ;
}
static void F_116 ( struct V_10 * V_11 , struct V_14 * V_15 )
{
struct V_94 * * V_157 , * V_104 ;
struct V_14 * V_158 ;
if ( V_15 -> V_169 ) {
F_51 ( & V_15 -> V_167 , V_15 -> V_169 ) ;
V_15 -> V_169 = NULL ;
}
if ( F_4 ( V_15 ) )
return;
if ( ! V_15 -> V_168 )
return;
V_15 -> V_169 = & V_11 -> V_170 [ V_15 -> V_171 ] ;
V_158 = F_115 ( V_11 , V_15 -> V_169 ,
F_45 ( V_15 -> V_168 ) , & V_104 , & V_157 ) ;
if ( ! V_158 ) {
F_63 ( & V_15 -> V_167 , V_104 , V_157 ) ;
F_64 ( & V_15 -> V_167 , V_15 -> V_169 ) ;
} else
V_15 -> V_169 = NULL ;
}
static void F_117 ( struct V_10 * V_11 , struct V_14 * V_15 )
{
if ( F_118 ( V_15 ) ) {
F_114 ( V_11 , V_15 , 0 ) ;
F_116 ( V_11 , V_15 ) ;
}
}
static void F_119 ( struct V_10 * V_11 , struct V_14 * V_15 )
{
F_37 ( V_11 , V_15 , L_7 ) ;
F_57 ( F_118 ( V_15 ) ) ;
F_120 ( V_15 ) ;
V_11 -> V_38 ++ ;
if ( F_7 ( V_15 ) )
V_11 -> V_172 ++ ;
F_117 ( V_11 , V_15 ) ;
}
static void F_121 ( struct V_10 * V_11 , struct V_14 * V_15 )
{
F_37 ( V_11 , V_15 , L_8 ) ;
F_57 ( ! F_118 ( V_15 ) ) ;
F_122 ( V_15 ) ;
if ( ! F_58 ( & V_15 -> V_94 ) ) {
F_53 ( & V_15 -> V_94 , V_15 -> V_160 ) ;
V_15 -> V_160 = NULL ;
}
if ( V_15 -> V_169 ) {
F_51 ( & V_15 -> V_167 , V_15 -> V_169 ) ;
V_15 -> V_169 = NULL ;
}
F_70 ( V_11 , V_15 -> V_3 ) ;
F_57 ( ! V_11 -> V_38 ) ;
V_11 -> V_38 -- ;
if ( F_7 ( V_15 ) )
V_11 -> V_172 -- ;
}
static void F_123 ( struct V_78 * V_173 )
{
struct V_14 * V_15 = F_124 ( V_173 ) ;
const int V_40 = F_44 ( V_173 ) ;
F_57 ( ! V_15 -> V_174 [ V_40 ] ) ;
V_15 -> V_174 [ V_40 ] -- ;
F_125 ( & V_15 -> V_101 , V_173 ) ;
if ( F_118 ( V_15 ) && F_103 ( & V_15 -> V_101 ) ) {
if ( V_15 -> V_169 ) {
F_51 ( & V_15 -> V_167 , V_15 -> V_169 ) ;
V_15 -> V_169 = NULL ;
}
}
}
static void F_126 ( struct V_78 * V_173 )
{
struct V_14 * V_15 = F_124 ( V_173 ) ;
struct V_10 * V_11 = V_15 -> V_11 ;
struct V_78 * V_100 ;
V_15 -> V_174 [ F_44 ( V_173 ) ] ++ ;
F_127 ( & V_15 -> V_101 , V_173 ) ;
if ( ! F_118 ( V_15 ) )
F_119 ( V_11 , V_15 ) ;
V_100 = V_15 -> V_168 ;
V_15 -> V_168 = F_41 ( V_11 , V_15 -> V_168 , V_173 , V_11 -> V_175 ) ;
if ( V_100 != V_15 -> V_168 )
F_116 ( V_11 , V_15 ) ;
F_57 ( ! V_15 -> V_168 ) ;
}
static void F_128 ( struct V_14 * V_15 , struct V_78 * V_173 )
{
F_125 ( & V_15 -> V_101 , V_173 ) ;
V_15 -> V_174 [ F_44 ( V_173 ) ] -- ;
F_129 ( & ( F_130 ( V_173 ) ) -> V_113 ,
F_131 ( V_173 ) , F_44 ( V_173 ) ) ;
F_126 ( V_173 ) ;
F_132 ( & ( F_130 ( V_173 ) ) -> V_113 ,
& V_15 -> V_11 -> V_176 -> V_113 , F_131 ( V_173 ) ,
F_44 ( V_173 ) ) ;
}
static struct V_78 *
F_133 ( struct V_10 * V_11 , struct V_34 * V_34 )
{
struct V_177 * V_178 = V_150 ;
struct V_23 * V_29 ;
struct V_14 * V_15 ;
V_29 = F_13 ( V_11 , V_178 -> V_26 ) ;
if ( ! V_29 )
return NULL ;
V_15 = F_15 ( V_29 , F_18 ( V_34 ) ) ;
if ( V_15 ) {
T_3 V_164 = V_34 -> V_179 + F_134 ( V_34 ) ;
return F_135 ( & V_15 -> V_101 , V_164 ) ;
}
return NULL ;
}
static void F_136 ( struct V_149 * V_31 , struct V_78 * V_173 )
{
struct V_10 * V_11 = V_31 -> V_32 -> V_33 ;
V_11 -> V_180 ++ ;
F_37 ( V_11 , F_124 ( V_173 ) , L_9 ,
V_11 -> V_180 ) ;
V_11 -> V_175 = F_45 ( V_173 ) + F_137 ( V_173 ) ;
}
static void F_138 ( struct V_149 * V_31 , struct V_78 * V_173 )
{
struct V_10 * V_11 = V_31 -> V_32 -> V_33 ;
F_24 ( ! V_11 -> V_180 ) ;
V_11 -> V_180 -- ;
F_37 ( V_11 , F_124 ( V_173 ) , L_10 ,
V_11 -> V_180 ) ;
}
static void F_139 ( struct V_78 * V_173 )
{
struct V_14 * V_15 = F_124 ( V_173 ) ;
if ( V_15 -> V_168 == V_173 )
V_15 -> V_168 = F_54 ( V_15 -> V_11 , V_15 , V_173 ) ;
F_140 ( & V_173 -> V_181 ) ;
F_123 ( V_173 ) ;
V_15 -> V_11 -> V_182 -- ;
F_129 ( & ( F_130 ( V_173 ) ) -> V_113 ,
F_131 ( V_173 ) , F_44 ( V_173 ) ) ;
if ( V_173 -> V_88 & V_89 ) {
F_24 ( ! V_15 -> V_183 ) ;
V_15 -> V_183 -- ;
}
}
static int F_141 ( struct V_149 * V_31 , struct V_78 * * V_184 ,
struct V_34 * V_34 )
{
struct V_10 * V_11 = V_31 -> V_32 -> V_33 ;
struct V_78 * V_185 ;
V_185 = F_133 ( V_11 , V_34 ) ;
if ( V_185 && F_142 ( V_185 , V_34 ) ) {
* V_184 = V_185 ;
return V_186 ;
}
return V_187 ;
}
static void F_143 ( struct V_149 * V_31 , struct V_78 * V_184 ,
int type )
{
if ( type == V_186 ) {
struct V_14 * V_15 = F_124 ( V_184 ) ;
F_128 ( V_15 , V_184 ) ;
}
}
static void F_144 ( struct V_149 * V_31 , struct V_78 * V_184 ,
struct V_34 * V_34 )
{
F_145 ( & ( F_130 ( V_184 ) ) -> V_113 ,
F_19 ( V_34 ) , F_18 ( V_34 ) ) ;
}
static void
F_146 ( struct V_149 * V_31 , struct V_78 * V_173 ,
struct V_78 * V_99 )
{
struct V_14 * V_15 = F_124 ( V_173 ) ;
struct V_10 * V_11 = V_31 -> V_32 -> V_33 ;
if ( ! F_147 ( & V_173 -> V_181 ) && ! F_147 ( & V_99 -> V_181 ) &&
F_40 ( F_148 ( V_99 ) , F_148 ( V_173 ) ) ) {
F_149 ( & V_173 -> V_181 , & V_99 -> V_181 ) ;
F_150 ( V_173 , F_148 ( V_99 ) ) ;
}
if ( V_15 -> V_168 == V_99 )
V_15 -> V_168 = V_173 ;
F_139 ( V_99 ) ;
F_145 ( & ( F_130 ( V_173 ) ) -> V_113 ,
F_131 ( V_99 ) , F_44 ( V_99 ) ) ;
V_15 = F_124 ( V_99 ) ;
if ( F_118 ( V_15 ) && F_103 ( & V_15 -> V_101 ) &&
V_15 != V_11 -> V_188 )
F_121 ( V_11 , V_15 ) ;
}
static int F_151 ( struct V_149 * V_31 , struct V_78 * V_173 ,
struct V_34 * V_34 )
{
struct V_10 * V_11 = V_31 -> V_32 -> V_33 ;
struct V_23 * V_29 ;
struct V_14 * V_15 ;
if ( F_18 ( V_34 ) && ! F_44 ( V_173 ) )
return false ;
V_29 = F_13 ( V_11 , V_150 -> V_26 ) ;
if ( ! V_29 )
return false ;
V_15 = F_15 ( V_29 , F_18 ( V_34 ) ) ;
return V_15 == F_124 ( V_173 ) ;
}
static inline void F_152 ( struct V_10 * V_11 , struct V_14 * V_15 )
{
F_153 ( & V_11 -> V_189 ) ;
F_154 ( & V_15 -> V_3 -> V_113 ) ;
}
static void F_155 ( struct V_10 * V_11 ,
struct V_14 * V_15 )
{
if ( V_15 ) {
F_37 ( V_11 , V_15 , L_11 ,
V_11 -> V_126 , V_11 -> V_124 ) ;
F_156 ( & V_15 -> V_3 -> V_113 ) ;
V_15 -> V_74 = 0 ;
V_15 -> V_116 = V_75 ;
V_15 -> V_77 = 0 ;
V_15 -> V_76 = 0 ;
V_15 -> V_121 = 0 ;
V_15 -> V_127 = 0 ;
F_157 ( V_15 ) ;
F_158 ( V_15 ) ;
F_159 ( V_15 ) ;
F_160 ( V_15 ) ;
F_161 ( V_15 ) ;
F_152 ( V_11 , V_15 ) ;
}
V_11 -> V_188 = V_15 ;
}
static void
F_162 ( struct V_10 * V_11 , struct V_14 * V_15 ,
bool V_190 )
{
F_37 ( V_11 , V_15 , L_12 , V_190 ) ;
if ( F_163 ( V_15 ) )
F_152 ( V_11 , V_15 ) ;
F_157 ( V_15 ) ;
F_164 ( V_15 ) ;
if ( F_165 ( V_15 ) && F_166 ( V_15 ) )
F_167 ( V_15 ) ;
if ( V_190 ) {
if ( F_39 ( V_15 ) )
V_15 -> V_162 = F_35 ( V_11 , V_15 ) ;
else
V_15 -> V_162 = V_15 -> V_76 - V_75 ;
F_37 ( V_11 , V_15 , L_13 , V_15 -> V_162 ) ;
}
F_76 ( V_11 , V_15 -> V_3 , V_15 ) ;
if ( F_118 ( V_15 ) && F_103 ( & V_15 -> V_101 ) )
F_121 ( V_11 , V_15 ) ;
F_117 ( V_11 , V_15 ) ;
if ( V_15 == V_11 -> V_188 )
V_11 -> V_188 = NULL ;
if ( V_11 -> V_191 ) {
F_168 ( V_11 -> V_191 -> V_25 . V_27 ) ;
V_11 -> V_191 = NULL ;
}
}
static inline void F_169 ( struct V_10 * V_11 , bool V_190 )
{
struct V_14 * V_15 = V_11 -> V_188 ;
if ( V_15 )
F_162 ( V_11 , V_15 , V_190 ) ;
}
static struct V_14 * F_170 ( struct V_10 * V_11 )
{
struct V_1 * V_160 =
F_1 ( V_11 -> V_176 , V_11 -> V_126 ,
V_11 -> V_124 ) ;
if ( ! V_11 -> V_182 )
return NULL ;
if ( ! V_160 )
return NULL ;
if ( F_103 ( & V_160 -> V_93 ) )
return NULL ;
return F_46 ( V_160 ) ;
}
static struct V_14 * F_171 ( struct V_10 * V_11 )
{
struct V_2 * V_3 ;
struct V_14 * V_15 ;
int V_139 , V_140 ;
struct V_1 * V_53 ;
if ( ! V_11 -> V_182 )
return NULL ;
V_3 = F_172 ( V_11 ) ;
if ( ! V_3 )
return NULL ;
F_89 (cfqg, i, j, st)
if ( ( V_15 = F_46 ( V_53 ) ) != NULL )
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
struct V_78 * V_173 )
{
if ( F_45 ( V_173 ) >= V_11 -> V_175 )
return F_45 ( V_173 ) - V_11 -> V_175 ;
else
return V_11 -> V_175 - F_45 ( V_173 ) ;
}
static inline int F_175 ( struct V_10 * V_11 , struct V_14 * V_15 ,
struct V_78 * V_173 )
{
return F_174 ( V_11 , V_173 ) <= V_192 ;
}
static struct V_14 * F_176 ( struct V_10 * V_11 ,
struct V_14 * V_193 )
{
struct V_96 * V_92 = & V_11 -> V_170 [ V_193 -> V_171 ] ;
struct V_94 * V_104 , * V_103 ;
struct V_14 * V_158 ;
T_3 V_164 = V_11 -> V_175 ;
if ( F_103 ( V_92 ) )
return NULL ;
V_158 = F_115 ( V_11 , V_92 , V_164 , & V_104 , NULL ) ;
if ( V_158 )
return V_158 ;
V_158 = F_48 ( V_104 , struct V_14 , V_167 ) ;
if ( F_175 ( V_11 , V_193 , V_158 -> V_168 ) )
return V_158 ;
if ( F_45 ( V_158 -> V_168 ) < V_164 )
V_103 = F_55 ( & V_158 -> V_167 ) ;
else
V_103 = F_56 ( & V_158 -> V_167 ) ;
if ( ! V_103 )
return NULL ;
V_158 = F_48 ( V_103 , struct V_14 , V_167 ) ;
if ( F_175 ( V_11 , V_193 , V_158 -> V_168 ) )
return V_158 ;
return NULL ;
}
static struct V_14 * F_177 ( struct V_10 * V_11 ,
struct V_14 * V_193 )
{
struct V_14 * V_15 ;
if ( F_4 ( V_193 ) )
return NULL ;
if ( ! F_7 ( V_193 ) )
return NULL ;
if ( F_166 ( V_193 ) )
return NULL ;
if ( V_193 -> V_3 -> V_102 == 1 )
return NULL ;
V_15 = F_176 ( V_11 , V_193 ) ;
if ( ! V_15 )
return NULL ;
if ( V_193 -> V_3 != V_15 -> V_3 )
return NULL ;
if ( ! F_7 ( V_15 ) )
return NULL ;
if ( F_166 ( V_15 ) )
return NULL ;
if ( F_5 ( V_15 ) != F_5 ( V_193 ) )
return NULL ;
return V_15 ;
}
static bool F_178 ( struct V_10 * V_11 , struct V_14 * V_15 )
{
enum V_4 V_5 = F_3 ( V_15 ) ;
struct V_1 * V_160 = V_15 -> V_160 ;
F_57 ( ! V_160 ) ;
F_57 ( ! V_160 -> V_22 ) ;
if ( ! V_11 -> V_12 )
return false ;
if ( V_5 == V_7 )
return false ;
if ( F_8 ( V_15 ) &&
! ( F_179 ( V_11 -> V_28 ) && V_11 -> V_13 ) )
return true ;
if ( V_160 -> V_22 == 1 && F_7 ( V_15 ) &&
! F_180 ( V_11 , & V_160 -> V_144 , false ) )
return true ;
F_37 ( V_11 , V_15 , L_14 ,
V_160 -> V_22 ) ;
return false ;
}
static void F_181 ( struct V_10 * V_11 )
{
struct V_14 * V_15 = V_11 -> V_188 ;
struct V_23 * V_29 ;
unsigned long V_194 , V_195 = 0 ;
if ( F_179 ( V_11 -> V_28 ) && V_11 -> V_13 )
return;
F_24 ( ! F_103 ( & V_15 -> V_101 ) ) ;
F_24 ( F_39 ( V_15 ) ) ;
if ( ! F_178 ( V_11 , V_15 ) ) {
if ( V_11 -> V_196 )
V_195 = V_11 -> V_196 ;
else
return;
}
if ( V_15 -> V_197 )
return;
V_29 = V_11 -> V_191 ;
if ( ! V_29 || ! F_182 ( & V_29 -> V_25 . V_27 -> V_198 ) )
return;
if ( F_183 ( V_29 -> V_144 . V_199 ) &&
( V_15 -> V_76 - V_75 < V_29 -> V_144 . V_200 ) ) {
F_37 ( V_11 , V_15 , L_15 ,
V_29 -> V_144 . V_200 ) ;
return;
}
if ( V_195 && V_15 -> V_3 -> V_102 > 1 )
return;
F_184 ( V_15 ) ;
if ( V_195 )
V_194 = V_11 -> V_196 ;
else
V_194 = V_11 -> V_12 ;
F_185 ( & V_11 -> V_189 , V_75 + V_194 ) ;
F_186 ( & V_15 -> V_3 -> V_113 ) ;
F_37 ( V_11 , V_15 , L_16 , V_194 ,
V_195 ? 1 : 0 ) ;
}
static void F_187 ( struct V_149 * V_31 , struct V_78 * V_173 )
{
struct V_10 * V_11 = V_31 -> V_32 -> V_33 ;
struct V_14 * V_15 = F_124 ( V_173 ) ;
F_37 ( V_11 , V_15 , L_17 ) ;
V_15 -> V_168 = F_54 ( V_11 , V_15 , V_173 ) ;
F_139 ( V_173 ) ;
V_15 -> V_197 ++ ;
( F_130 ( V_173 ) ) -> V_197 ++ ;
F_188 ( V_31 , V_173 ) ;
V_11 -> V_201 [ F_7 ( V_15 ) ] ++ ;
V_15 -> V_127 += F_137 ( V_173 ) ;
F_189 ( & V_15 -> V_3 -> V_113 , F_190 ( V_173 ) ,
F_131 ( V_173 ) , F_44 ( V_173 ) ) ;
}
static struct V_78 * F_191 ( struct V_14 * V_15 )
{
struct V_78 * V_173 = NULL ;
if ( F_192 ( V_15 ) )
return NULL ;
F_193 ( V_15 ) ;
if ( F_147 ( & V_15 -> V_202 ) )
return NULL ;
V_173 = F_194 ( V_15 -> V_202 . V_99 ) ;
if ( F_40 ( V_75 , F_148 ( V_173 ) ) )
V_173 = NULL ;
F_37 ( V_15 -> V_11 , V_15 , L_18 , V_173 ) ;
return V_173 ;
}
static inline int
F_195 ( struct V_10 * V_11 , struct V_14 * V_15 )
{
const int V_203 = V_11 -> V_204 ;
F_24 ( V_15 -> V_45 >= V_43 ) ;
return 2 * V_203 * ( V_43 - V_15 -> V_45 ) ;
}
static int F_196 ( struct V_14 * V_15 )
{
int V_205 , V_206 ;
V_206 = V_15 -> V_207 [ V_35 ] + V_15 -> V_207 [ V_208 ] ;
V_205 = V_15 -> V_146 - V_206 ;
F_57 ( V_205 < 0 ) ;
return V_205 ;
}
static void F_197 ( struct V_14 * V_15 , struct V_14 * V_161 )
{
int V_205 , V_209 ;
struct V_14 * V_158 ;
if ( ! F_196 ( V_161 ) )
return;
while ( ( V_158 = V_161 -> V_161 ) ) {
if ( V_158 == V_15 )
return;
V_161 = V_158 ;
}
V_205 = F_196 ( V_15 ) ;
V_209 = F_196 ( V_161 ) ;
if ( V_205 == 0 || V_209 == 0 )
return;
if ( V_209 >= V_205 ) {
V_15 -> V_161 = V_161 ;
V_161 -> V_146 += V_205 ;
} else {
V_161 -> V_161 = V_15 ;
V_15 -> V_146 += V_209 ;
}
}
static enum V_6 F_198 ( struct V_10 * V_11 ,
struct V_2 * V_3 , enum V_4 V_5 )
{
struct V_14 * V_28 ;
int V_139 ;
bool V_210 = false ;
unsigned long V_211 = 0 ;
enum V_6 V_212 = V_19 ;
for ( V_139 = 0 ; V_139 <= V_20 ; ++ V_139 ) {
V_28 = F_46 ( F_1 ( V_3 , V_5 , V_139 ) ) ;
if ( V_28 &&
( ! V_210 || F_40 ( V_28 -> V_159 , V_211 ) ) ) {
V_211 = V_28 -> V_159 ;
V_212 = V_139 ;
V_210 = true ;
}
}
return V_212 ;
}
static void F_199 ( struct V_10 * V_11 , struct V_2 * V_3 )
{
unsigned V_66 ;
unsigned V_22 ;
struct V_1 * V_53 ;
unsigned V_71 ;
enum V_4 V_213 = V_11 -> V_126 ;
if ( F_9 ( V_16 , V_11 , V_3 ) )
V_11 -> V_126 = V_16 ;
else if ( F_9 ( V_17 , V_11 , V_3 ) )
V_11 -> V_126 = V_17 ;
else {
V_11 -> V_126 = V_7 ;
V_11 -> V_122 = V_75 + 1 ;
return;
}
if ( V_213 != V_11 -> V_126 )
goto V_214;
V_53 = F_1 ( V_3 , V_11 -> V_126 , V_11 -> V_124 ) ;
V_22 = V_53 -> V_22 ;
if ( V_22 && ! F_75 ( V_75 , V_11 -> V_122 ) )
return;
V_214:
V_11 -> V_124 =
F_198 ( V_11 , V_3 , V_11 -> V_126 ) ;
V_53 = F_1 ( V_3 , V_11 -> V_126 , V_11 -> V_124 ) ;
V_22 = V_53 -> V_22 ;
V_71 = F_34 ( V_11 , V_3 ) ;
V_66 = V_71 * V_22 /
F_74 ( unsigned , V_3 -> V_62 [ V_11 -> V_126 ] ,
F_9 ( V_11 -> V_126 , V_11 , V_3 ) ) ;
if ( V_11 -> V_124 == V_18 ) {
unsigned int V_215 ;
V_215 = V_11 -> V_64 *
F_10 ( V_11 , V_3 ) ;
V_215 = V_215 / V_11 -> V_38 ;
V_66 = F_200 ( unsigned , V_66 , V_215 ) ;
V_66 = V_66 * V_11 -> V_42 [ 0 ] / V_11 -> V_42 [ 1 ] ;
} else
V_66 = F_33 ( V_66 , 2 * V_11 -> V_12 ) ;
V_66 = F_74 ( unsigned , V_66 , V_216 ) ;
F_21 ( V_11 , L_19 , V_66 ) ;
V_11 -> V_122 = V_75 + V_66 ;
}
static struct V_2 * F_172 ( struct V_10 * V_11 )
{
struct V_1 * V_53 = & V_11 -> V_63 ;
struct V_2 * V_3 ;
if ( F_103 ( & V_53 -> V_93 ) )
return NULL ;
V_3 = F_49 ( V_53 ) ;
F_29 ( V_53 ) ;
return V_3 ;
}
static void F_201 ( struct V_10 * V_11 )
{
struct V_2 * V_3 = F_172 ( V_11 ) ;
V_11 -> V_176 = V_3 ;
if ( V_3 -> V_112 ) {
V_11 -> V_122 = V_75 + V_3 -> V_112 ;
V_11 -> V_124 = V_3 -> V_123 ;
V_11 -> V_126 = V_3 -> V_125 ;
} else
V_11 -> V_122 = V_75 - 1 ;
F_199 ( V_11 , V_3 ) ;
}
static struct V_14 * F_202 ( struct V_10 * V_11 )
{
struct V_14 * V_15 , * V_161 = NULL ;
V_15 = V_11 -> V_188 ;
if ( ! V_15 )
goto V_217;
if ( ! V_11 -> V_182 )
return NULL ;
if ( F_203 ( V_15 ) && ! F_103 ( & V_15 -> V_101 ) )
goto V_218;
if ( F_38 ( V_15 ) && ! F_204 ( V_15 ) ) {
if ( V_15 -> V_3 -> V_102 == 1 && F_103 ( & V_15 -> V_101 )
&& V_15 -> V_197 && F_178 ( V_11 , V_15 ) ) {
V_15 = NULL ;
goto V_219;
} else
goto V_220;
}
if ( ! F_103 ( & V_15 -> V_101 ) )
goto V_219;
V_161 = F_177 ( V_11 , V_15 ) ;
if ( V_161 ) {
if ( ! V_15 -> V_161 )
F_197 ( V_15 , V_161 ) ;
goto V_218;
}
if ( F_205 ( & V_11 -> V_189 ) ) {
V_15 = NULL ;
goto V_219;
}
if ( F_166 ( V_15 ) && F_8 ( V_15 ) &&
( F_39 ( V_15 ) ||
( V_15 -> V_76 - V_75 > V_75 - V_15 -> V_74 ) ) ) {
F_206 ( V_15 ) ;
F_207 ( V_15 ) ;
}
if ( V_15 -> V_197 && F_178 ( V_11 , V_15 ) ) {
V_15 = NULL ;
goto V_219;
}
V_220:
if ( V_11 -> V_196 && V_15 -> V_3 -> V_102 == 1 &&
V_15 -> V_3 -> V_197 &&
! F_180 ( V_11 , & V_15 -> V_3 -> V_144 , true ) ) {
V_15 = NULL ;
goto V_219;
}
V_218:
F_169 ( V_11 , 0 ) ;
V_217:
if ( ! V_161 )
F_201 ( V_11 ) ;
V_15 = F_173 ( V_11 , V_161 ) ;
V_219:
return V_15 ;
}
static int F_208 ( struct V_14 * V_15 )
{
int V_197 = 0 ;
while ( V_15 -> V_168 ) {
F_187 ( V_15 -> V_11 -> V_28 , V_15 -> V_168 ) ;
V_197 ++ ;
}
F_57 ( ! F_147 ( & V_15 -> V_202 ) ) ;
F_162 ( V_15 -> V_11 , V_15 , 0 ) ;
return V_197 ;
}
static int F_209 ( struct V_10 * V_11 )
{
struct V_14 * V_15 ;
int V_197 = 0 ;
F_169 ( V_11 , 0 ) ;
while ( ( V_15 = F_171 ( V_11 ) ) != NULL ) {
F_155 ( V_11 , V_15 ) ;
V_197 += F_208 ( V_15 ) ;
}
F_57 ( V_11 -> V_38 ) ;
F_21 ( V_11 , L_20 , V_197 ) ;
return V_197 ;
}
static inline bool F_210 ( struct V_10 * V_11 ,
struct V_14 * V_15 )
{
if ( F_39 ( V_15 ) )
return true ;
if ( F_75 ( V_75 + V_11 -> V_12 * V_15 -> V_197 ,
V_15 -> V_76 ) )
return true ;
return false ;
}
static bool F_211 ( struct V_10 * V_11 , struct V_14 * V_15 )
{
unsigned int V_221 ;
if ( F_178 ( V_11 , V_15 ) && V_11 -> V_201 [ V_222 ] )
return false ;
if ( V_11 -> V_201 [ V_223 ] && ! F_7 ( V_15 ) )
return false ;
V_221 = F_74 (unsigned int, cfqd->cfq_quantum / 2 , 1 ) ;
if ( F_4 ( V_15 ) )
V_221 = 1 ;
if ( V_15 -> V_197 >= V_221 ) {
bool V_224 = false ;
if ( F_4 ( V_15 ) )
return false ;
if ( F_7 ( V_15 ) && V_11 -> V_172 == 1 )
V_224 = true ;
if ( V_11 -> V_38 > 1 && F_210 ( V_11 , V_15 ) &&
! V_224 )
return false ;
if ( V_11 -> V_38 == 1 || V_224 )
V_221 = - 1 ;
else
V_221 = V_11 -> V_225 ;
}
if ( ! F_7 ( V_15 ) && V_11 -> V_67 ) {
unsigned long V_226 = V_75 - V_11 -> V_227 ;
unsigned int V_228 ;
V_228 = V_226 / V_11 -> V_42 [ 1 ] ;
if ( ! V_228 && ! V_15 -> V_197 )
V_228 = 1 ;
if ( V_228 < V_221 )
V_221 = V_228 ;
}
return V_15 -> V_197 < V_221 ;
}
static bool F_212 ( struct V_10 * V_11 , struct V_14 * V_15 )
{
struct V_78 * V_173 ;
F_57 ( F_103 ( & V_15 -> V_101 ) ) ;
if ( ! F_211 ( V_11 , V_15 ) )
return false ;
V_173 = F_191 ( V_15 ) ;
if ( ! V_173 )
V_173 = V_15 -> V_168 ;
F_187 ( V_11 -> V_28 , V_173 ) ;
if ( ! V_11 -> V_191 ) {
struct V_23 * V_29 = F_213 ( V_173 ) ;
F_214 ( & V_29 -> V_25 . V_27 -> V_229 ) ;
V_11 -> V_191 = V_29 ;
}
return true ;
}
static int F_215 ( struct V_149 * V_31 , int V_230 )
{
struct V_10 * V_11 = V_31 -> V_32 -> V_33 ;
struct V_14 * V_15 ;
if ( ! V_11 -> V_38 )
return 0 ;
if ( F_216 ( V_230 ) )
return F_209 ( V_11 ) ;
V_15 = F_202 ( V_11 ) ;
if ( ! V_15 )
return 0 ;
if ( ! F_212 ( V_11 , V_15 ) )
return 0 ;
V_15 -> V_121 ++ ;
F_158 ( V_15 ) ;
if ( V_11 -> V_38 > 1 && ( ( ! F_7 ( V_15 ) &&
V_15 -> V_121 >= F_195 ( V_11 , V_15 ) ) ||
F_4 ( V_15 ) ) ) {
V_15 -> V_76 = V_75 + 1 ;
F_169 ( V_11 , 0 ) ;
}
F_37 ( V_11 , V_15 , L_21 ) ;
return 1 ;
}
static void F_217 ( struct V_14 * V_15 )
{
struct V_10 * V_11 = V_15 -> V_11 ;
struct V_2 * V_3 ;
F_57 ( V_15 -> V_146 <= 0 ) ;
V_15 -> V_146 -- ;
if ( V_15 -> V_146 )
return;
F_37 ( V_11 , V_15 , L_22 ) ;
F_57 ( F_47 ( & V_15 -> V_101 ) ) ;
F_57 ( V_15 -> V_207 [ V_35 ] + V_15 -> V_207 [ V_208 ] ) ;
V_3 = V_15 -> V_3 ;
if ( F_216 ( V_11 -> V_188 == V_15 ) ) {
F_162 ( V_11 , V_15 , 0 ) ;
F_20 ( V_11 ) ;
}
F_57 ( F_118 ( V_15 ) ) ;
F_218 ( V_231 , V_15 ) ;
F_102 ( V_3 ) ;
}
static void F_219 ( struct V_14 * V_15 )
{
struct V_14 * V_158 , * V_99 ;
V_158 = V_15 -> V_161 ;
while ( V_158 ) {
if ( V_158 == V_15 ) {
F_220 ( 1 , L_23 ) ;
break;
}
V_99 = V_158 -> V_161 ;
F_217 ( V_158 ) ;
V_158 = V_99 ;
}
}
static void F_221 ( struct V_10 * V_11 , struct V_14 * V_15 )
{
if ( F_216 ( V_15 == V_11 -> V_188 ) ) {
F_162 ( V_11 , V_15 , 0 ) ;
F_20 ( V_11 ) ;
}
F_219 ( V_15 ) ;
F_217 ( V_15 ) ;
}
static void F_222 ( struct V_24 * V_25 )
{
struct V_23 * V_29 = F_11 ( V_25 ) ;
V_29 -> V_144 . V_145 = V_75 ;
}
static void F_223 ( struct V_24 * V_25 )
{
struct V_23 * V_29 = F_11 ( V_25 ) ;
struct V_10 * V_11 = F_17 ( V_29 ) ;
if ( V_29 -> V_15 [ V_222 ] ) {
F_221 ( V_11 , V_29 -> V_15 [ V_222 ] ) ;
V_29 -> V_15 [ V_222 ] = NULL ;
}
if ( V_29 -> V_15 [ V_223 ] ) {
F_221 ( V_11 , V_29 -> V_15 [ V_223 ] ) ;
V_29 -> V_15 [ V_223 ] = NULL ;
}
}
static void F_224 ( struct V_14 * V_15 , struct V_26 * V_27 )
{
struct V_177 * V_178 = V_150 ;
int V_232 ;
if ( ! F_225 ( V_15 ) )
return;
V_232 = F_226 ( V_27 -> V_45 ) ;
switch ( V_232 ) {
default:
F_227 ( V_233 L_24 , V_232 ) ;
case V_234 :
V_15 -> V_45 = F_228 ( V_178 ) ;
V_15 -> V_232 = F_229 ( V_178 ) ;
break;
case V_235 :
V_15 -> V_45 = F_230 ( V_27 ) ;
V_15 -> V_232 = V_235 ;
break;
case V_236 :
V_15 -> V_45 = F_230 ( V_27 ) ;
V_15 -> V_232 = V_236 ;
break;
case V_237 :
V_15 -> V_232 = V_237 ;
V_15 -> V_45 = 7 ;
F_207 ( V_15 ) ;
break;
}
V_15 -> V_171 = V_15 -> V_45 ;
F_231 ( V_15 ) ;
}
static void F_232 ( struct V_23 * V_29 )
{
struct V_10 * V_11 = F_17 ( V_29 ) ;
struct V_14 * V_15 ;
if ( F_216 ( ! V_11 ) )
return;
V_15 = V_29 -> V_15 [ V_222 ] ;
if ( V_15 ) {
struct V_14 * V_161 ;
V_161 = F_233 ( V_11 , V_222 , V_29 -> V_25 . V_27 ,
V_142 ) ;
if ( V_161 ) {
V_29 -> V_15 [ V_222 ] = V_161 ;
F_217 ( V_15 ) ;
}
}
V_15 = V_29 -> V_15 [ V_223 ] ;
if ( V_15 )
F_234 ( V_15 ) ;
}
static void F_235 ( struct V_10 * V_11 , struct V_14 * V_15 ,
T_4 V_238 , bool V_30 )
{
F_52 ( & V_15 -> V_94 ) ;
F_52 ( & V_15 -> V_167 ) ;
F_236 ( & V_15 -> V_202 ) ;
V_15 -> V_146 = 0 ;
V_15 -> V_11 = V_11 ;
F_234 ( V_15 ) ;
if ( V_30 ) {
if ( ! F_4 ( V_15 ) )
F_237 ( V_15 ) ;
F_238 ( V_15 ) ;
}
V_15 -> V_238 = V_238 ;
}
static void F_239 ( struct V_23 * V_29 )
{
struct V_14 * V_239 = F_15 ( V_29 , 1 ) ;
struct V_10 * V_11 = F_17 ( V_29 ) ;
struct V_149 * V_31 ;
if ( F_216 ( ! V_11 ) )
return;
V_31 = V_11 -> V_28 ;
if ( V_239 ) {
F_37 ( V_11 , V_239 , L_25 ) ;
F_16 ( V_29 , NULL , 1 ) ;
F_217 ( V_239 ) ;
}
}
static struct V_14 *
F_240 ( struct V_10 * V_11 , bool V_30 ,
struct V_26 * V_27 , T_5 V_240 )
{
struct V_14 * V_15 , * V_161 = NULL ;
struct V_23 * V_29 ;
struct V_2 * V_3 ;
V_241:
V_3 = F_94 ( V_11 ) ;
V_29 = F_13 ( V_11 , V_27 ) ;
V_15 = F_15 ( V_29 , V_30 ) ;
if ( ! V_15 || V_15 == & V_11 -> V_242 ) {
V_15 = NULL ;
if ( V_161 ) {
V_15 = V_161 ;
V_161 = NULL ;
} else if ( V_240 & V_243 ) {
F_98 ( V_11 -> V_28 -> V_151 ) ;
V_161 = F_241 ( V_231 ,
V_240 | V_244 ,
V_11 -> V_28 -> V_103 ) ;
F_99 ( V_11 -> V_28 -> V_151 ) ;
if ( V_161 )
goto V_241;
} else {
V_15 = F_241 ( V_231 ,
V_240 | V_244 ,
V_11 -> V_28 -> V_103 ) ;
}
if ( V_15 ) {
F_235 ( V_11 , V_15 , V_150 -> V_238 , V_30 ) ;
F_224 ( V_15 , V_27 ) ;
F_101 ( V_15 , V_3 ) ;
F_37 ( V_11 , V_15 , L_26 ) ;
} else
V_15 = & V_11 -> V_242 ;
}
if ( V_161 )
F_218 ( V_231 , V_161 ) ;
return V_15 ;
}
static struct V_14 * *
F_242 ( struct V_10 * V_11 , int V_232 , int V_45 )
{
switch ( V_232 ) {
case V_235 :
return & V_11 -> V_245 [ 0 ] [ V_45 ] ;
case V_236 :
return & V_11 -> V_245 [ 1 ] [ V_45 ] ;
case V_237 :
return & V_11 -> V_246 ;
default:
F_243 () ;
}
}
static struct V_14 *
F_233 ( struct V_10 * V_11 , bool V_30 , struct V_26 * V_27 ,
T_5 V_240 )
{
const int V_45 = F_230 ( V_27 ) ;
const int V_232 = F_244 ( V_27 ) ;
struct V_14 * * V_245 = NULL ;
struct V_14 * V_15 = NULL ;
if ( ! V_30 ) {
V_245 = F_242 ( V_11 , V_232 , V_45 ) ;
V_15 = * V_245 ;
}
if ( ! V_15 )
V_15 = F_240 ( V_11 , V_30 , V_27 , V_240 ) ;
if ( ! V_30 && ! ( * V_245 ) ) {
V_15 -> V_146 ++ ;
* V_245 = V_15 ;
}
V_15 -> V_146 ++ ;
return V_15 ;
}
static void
F_245 ( struct V_247 * V_144 , unsigned long V_248 )
{
unsigned long V_249 = V_75 - V_144 -> V_145 ;
V_249 = F_32 ( V_249 , 2UL * V_248 ) ;
V_144 -> V_199 = ( 7 * V_144 -> V_199 + 256 ) / 8 ;
V_144 -> V_250 = ( 7 * V_144 -> V_250 + 256 * V_249 ) / 8 ;
V_144 -> V_200 = ( V_144 -> V_250 + 128 ) / V_144 -> V_199 ;
}
static void
F_246 ( struct V_10 * V_11 , struct V_14 * V_15 ,
struct V_23 * V_29 )
{
if ( F_7 ( V_15 ) ) {
F_245 ( & V_29 -> V_144 , V_11 -> V_12 ) ;
F_245 ( & V_15 -> V_160 -> V_144 ,
V_11 -> V_12 ) ;
}
#ifdef F_247
F_245 ( & V_15 -> V_3 -> V_144 , V_11 -> V_196 ) ;
#endif
}
static void
F_248 ( struct V_10 * V_11 , struct V_14 * V_15 ,
struct V_78 * V_173 )
{
T_3 V_251 = 0 ;
T_3 V_252 = F_137 ( V_173 ) ;
if ( V_15 -> V_253 ) {
if ( V_15 -> V_253 < F_45 ( V_173 ) )
V_251 = F_45 ( V_173 ) - V_15 -> V_253 ;
else
V_251 = V_15 -> V_253 - F_45 ( V_173 ) ;
}
V_15 -> V_254 <<= 1 ;
if ( F_179 ( V_11 -> V_28 ) )
V_15 -> V_254 |= ( V_252 < V_255 ) ;
else
V_15 -> V_254 |= ( V_251 > V_256 ) ;
}
static void
F_249 ( struct V_10 * V_11 , struct V_14 * V_15 ,
struct V_23 * V_29 )
{
int V_257 , V_258 ;
if ( ! F_7 ( V_15 ) || F_4 ( V_15 ) )
return;
V_258 = V_257 = F_8 ( V_15 ) ;
if ( V_15 -> V_174 [ 0 ] + V_15 -> V_174 [ 1 ] >= 4 )
F_250 ( V_15 ) ;
if ( V_15 -> V_168 && ( V_15 -> V_168 -> V_88 & V_259 ) )
V_258 = 0 ;
else if ( ! F_182 ( & V_29 -> V_25 . V_27 -> V_198 ) ||
! V_11 -> V_12 ||
( ! F_251 ( V_15 ) && F_166 ( V_15 ) ) )
V_258 = 0 ;
else if ( F_183 ( V_29 -> V_144 . V_199 ) ) {
if ( V_29 -> V_144 . V_200 > V_11 -> V_12 )
V_258 = 0 ;
else
V_258 = 1 ;
}
if ( V_257 != V_258 ) {
F_37 ( V_11 , V_15 , L_27 , V_258 ) ;
if ( V_258 )
F_237 ( V_15 ) ;
else
F_207 ( V_15 ) ;
}
}
static bool
F_252 ( struct V_10 * V_11 , struct V_14 * V_161 ,
struct V_78 * V_173 )
{
struct V_14 * V_15 ;
V_15 = V_11 -> V_188 ;
if ( ! V_15 )
return false ;
if ( F_4 ( V_161 ) )
return false ;
if ( F_4 ( V_15 ) )
return true ;
if ( F_5 ( V_15 ) && ! F_5 ( V_161 ) )
return false ;
if ( F_44 ( V_173 ) && ! F_7 ( V_15 ) )
return true ;
if ( V_161 -> V_3 != V_15 -> V_3 )
return false ;
if ( F_38 ( V_15 ) )
return true ;
if ( V_11 -> V_124 == V_19 &&
F_6 ( V_161 ) == V_19 &&
V_161 -> V_160 -> V_22 == 2 &&
F_103 ( & V_15 -> V_101 ) )
return true ;
if ( ( V_173 -> V_88 & V_89 ) && ! V_15 -> V_183 )
return true ;
if ( F_5 ( V_161 ) && ! F_5 ( V_15 ) )
return true ;
if ( F_103 ( & V_15 -> V_101 ) && ! F_178 ( V_11 , V_15 ) )
return true ;
if ( ! V_11 -> V_191 || ! F_163 ( V_15 ) )
return false ;
if ( F_175 ( V_11 , V_15 , V_173 ) )
return true ;
return false ;
}
static void F_253 ( struct V_10 * V_11 , struct V_14 * V_15 )
{
enum V_6 V_260 = F_6 ( V_11 -> V_188 ) ;
F_37 ( V_11 , V_15 , L_28 ) ;
F_169 ( V_11 , 1 ) ;
if ( V_260 != F_6 ( V_15 ) )
V_15 -> V_3 -> V_112 = 0 ;
F_57 ( ! F_118 ( V_15 ) ) ;
F_114 ( V_11 , V_15 , 1 ) ;
V_15 -> V_76 = 0 ;
F_161 ( V_15 ) ;
}
static void
F_254 ( struct V_10 * V_11 , struct V_14 * V_15 ,
struct V_78 * V_173 )
{
struct V_23 * V_29 = F_213 ( V_173 ) ;
V_11 -> V_182 ++ ;
if ( V_173 -> V_88 & V_89 )
V_15 -> V_183 ++ ;
F_246 ( V_11 , V_15 , V_29 ) ;
F_248 ( V_11 , V_15 , V_173 ) ;
F_249 ( V_11 , V_15 , V_29 ) ;
V_15 -> V_253 = F_45 ( V_173 ) + F_137 ( V_173 ) ;
if ( V_15 == V_11 -> V_188 ) {
if ( F_163 ( V_15 ) ) {
if ( F_190 ( V_173 ) > V_261 ||
V_11 -> V_38 > 1 ) {
F_152 ( V_11 , V_15 ) ;
F_157 ( V_15 ) ;
F_255 ( V_11 -> V_28 ) ;
} else {
F_154 (
& V_15 -> V_3 -> V_113 ) ;
F_256 ( V_15 ) ;
}
}
} else if ( F_252 ( V_11 , V_15 , V_173 ) ) {
F_253 ( V_11 , V_15 ) ;
F_255 ( V_11 -> V_28 ) ;
}
}
static void F_257 ( struct V_149 * V_31 , struct V_78 * V_173 )
{
struct V_10 * V_11 = V_31 -> V_32 -> V_33 ;
struct V_14 * V_15 = F_124 ( V_173 ) ;
F_37 ( V_11 , V_15 , L_29 ) ;
F_224 ( V_15 , F_213 ( V_173 ) -> V_25 . V_27 ) ;
F_150 ( V_173 , V_75 + V_11 -> V_262 [ F_44 ( V_173 ) ] ) ;
F_258 ( & V_173 -> V_181 , & V_15 -> V_202 ) ;
F_126 ( V_173 ) ;
F_132 ( & ( F_130 ( V_173 ) ) -> V_113 ,
& V_11 -> V_176 -> V_113 , F_131 ( V_173 ) ,
F_44 ( V_173 ) ) ;
F_254 ( V_11 , V_15 , V_173 ) ;
}
static void F_259 ( struct V_10 * V_11 )
{
struct V_14 * V_15 = V_11 -> V_188 ;
if ( V_11 -> V_180 > V_11 -> V_263 )
V_11 -> V_263 = V_11 -> V_180 ;
if ( V_11 -> V_13 == 1 )
return;
if ( V_11 -> V_182 <= V_264 &&
V_11 -> V_180 <= V_264 )
return;
if ( V_15 && F_8 ( V_15 ) &&
V_15 -> V_197 + V_15 -> V_174 [ 0 ] + V_15 -> V_174 [ 1 ] <
V_264 && V_11 -> V_180 < V_264 )
return;
if ( V_11 -> V_265 ++ < 50 )
return;
if ( V_11 -> V_263 >= V_264 )
V_11 -> V_13 = 1 ;
else
V_11 -> V_13 = 0 ;
}
static bool F_260 ( struct V_10 * V_11 , struct V_14 * V_15 )
{
struct V_23 * V_29 = V_11 -> V_191 ;
if ( ! F_103 ( & V_15 -> V_101 ) )
return false ;
if ( V_15 -> V_3 -> V_102 > 1 )
return false ;
if ( F_180 ( V_11 , & V_15 -> V_3 -> V_144 , true ) )
return false ;
if ( F_38 ( V_15 ) )
return true ;
if ( V_29 && F_183 ( V_29 -> V_144 . V_199 )
&& ( V_15 -> V_76 - V_75 < V_29 -> V_144 . V_200 ) )
return true ;
if ( V_15 -> V_76 - V_75 == 1 )
return true ;
return false ;
}
static void F_261 ( struct V_149 * V_31 , struct V_78 * V_173 )
{
struct V_14 * V_15 = F_124 ( V_173 ) ;
struct V_10 * V_11 = V_15 -> V_11 ;
const int V_40 = F_44 ( V_173 ) ;
unsigned long V_266 ;
V_266 = V_75 ;
F_37 ( V_11 , V_15 , L_30 ,
! ! ( V_173 -> V_88 & V_259 ) ) ;
F_259 ( V_11 ) ;
F_24 ( ! V_11 -> V_180 ) ;
F_24 ( ! V_15 -> V_197 ) ;
V_11 -> V_180 -- ;
V_15 -> V_197 -- ;
( F_130 ( V_173 ) ) -> V_197 -- ;
F_262 ( & V_15 -> V_3 -> V_113 ,
F_263 ( V_173 ) , F_264 ( V_173 ) ,
F_131 ( V_173 ) , F_44 ( V_173 ) ) ;
V_11 -> V_201 [ F_7 ( V_15 ) ] -- ;
if ( V_40 ) {
struct V_1 * V_160 ;
F_213 ( V_173 ) -> V_144 . V_145 = V_266 ;
if ( F_118 ( V_15 ) )
V_160 = V_15 -> V_160 ;
else
V_160 = F_1 ( V_15 -> V_3 ,
F_3 ( V_15 ) , F_6 ( V_15 ) ) ;
V_160 -> V_144 . V_145 = V_266 ;
if ( ! F_75 ( V_173 -> V_267 + V_11 -> V_262 [ 1 ] , V_266 ) )
V_11 -> V_227 = V_266 ;
}
#ifdef F_247
V_15 -> V_3 -> V_144 . V_145 = V_266 ;
#endif
if ( V_11 -> V_188 == V_15 ) {
const bool V_268 = F_103 ( & V_15 -> V_101 ) ;
if ( F_39 ( V_15 ) ) {
F_36 ( V_11 , V_15 ) ;
F_265 ( V_15 ) ;
}
if ( F_260 ( V_11 , V_15 ) ) {
unsigned long V_269 = V_11 -> V_12 ;
if ( ! V_11 -> V_12 )
V_269 = V_11 -> V_196 ;
V_15 -> V_76 = V_75 + V_269 ;
F_266 ( V_15 ) ;
F_37 ( V_11 , V_15 , L_31 ) ;
}
if ( F_38 ( V_15 ) || F_4 ( V_15 ) )
F_169 ( V_11 , 1 ) ;
else if ( V_40 && V_268 &&
! F_177 ( V_11 , V_15 ) ) {
F_181 ( V_11 ) ;
}
}
if ( ! V_11 -> V_180 )
F_20 ( V_11 ) ;
}
static inline int F_267 ( struct V_14 * V_15 )
{
if ( F_163 ( V_15 ) && ! F_268 ( V_15 ) ) {
F_269 ( V_15 ) ;
return V_270 ;
}
return V_271 ;
}
static int F_270 ( struct V_149 * V_31 , int V_272 )
{
struct V_10 * V_11 = V_31 -> V_32 -> V_33 ;
struct V_177 * V_178 = V_150 ;
struct V_23 * V_29 ;
struct V_14 * V_15 ;
V_29 = F_13 ( V_11 , V_178 -> V_26 ) ;
if ( ! V_29 )
return V_271 ;
V_15 = F_15 ( V_29 , F_271 ( V_272 ) ) ;
if ( V_15 ) {
F_224 ( V_15 , V_29 -> V_25 . V_27 ) ;
return F_267 ( V_15 ) ;
}
return V_271 ;
}
static void F_272 ( struct V_78 * V_173 )
{
struct V_14 * V_15 = F_124 ( V_173 ) ;
if ( V_15 ) {
const int V_272 = F_131 ( V_173 ) ;
F_57 ( ! V_15 -> V_207 [ V_272 ] ) ;
V_15 -> V_207 [ V_272 ] -- ;
F_102 ( F_130 ( V_173 ) ) ;
V_173 -> V_273 . V_274 [ 0 ] = NULL ;
V_173 -> V_273 . V_274 [ 1 ] = NULL ;
F_217 ( V_15 ) ;
}
}
static struct V_14 *
F_273 ( struct V_10 * V_11 , struct V_23 * V_29 ,
struct V_14 * V_15 )
{
F_37 ( V_11 , V_15 , L_32 , V_15 -> V_161 ) ;
F_16 ( V_29 , V_15 -> V_161 , 1 ) ;
F_274 ( V_15 -> V_161 ) ;
F_217 ( V_15 ) ;
return F_15 ( V_29 , 1 ) ;
}
static struct V_14 *
F_275 ( struct V_23 * V_29 , struct V_14 * V_15 )
{
if ( F_196 ( V_15 ) == 1 ) {
V_15 -> V_238 = V_150 -> V_238 ;
F_276 ( V_15 ) ;
F_277 ( V_15 ) ;
return V_15 ;
}
F_16 ( V_29 , NULL , 1 ) ;
F_219 ( V_15 ) ;
F_217 ( V_15 ) ;
return NULL ;
}
static int
F_278 ( struct V_149 * V_31 , struct V_78 * V_173 , T_5 V_240 )
{
struct V_10 * V_11 = V_31 -> V_32 -> V_33 ;
struct V_23 * V_29 = F_11 ( V_173 -> V_273 . V_25 ) ;
const int V_272 = F_131 ( V_173 ) ;
const bool V_30 = F_44 ( V_173 ) ;
struct V_14 * V_15 ;
unsigned int V_275 ;
F_279 ( V_240 & V_243 ) ;
F_99 ( V_31 -> V_151 ) ;
V_275 = F_280 ( & V_29 -> V_25 ) ;
if ( F_216 ( V_275 & V_276 ) )
F_232 ( V_29 ) ;
#ifdef F_247
if ( F_216 ( V_275 & V_277 ) )
F_239 ( V_29 ) ;
#endif
V_217:
V_15 = F_15 ( V_29 , V_30 ) ;
if ( ! V_15 || V_15 == & V_11 -> V_242 ) {
V_15 = F_233 ( V_11 , V_30 , V_29 -> V_25 . V_27 , V_240 ) ;
F_16 ( V_29 , V_15 , V_30 ) ;
} else {
if ( F_165 ( V_15 ) && F_281 ( V_15 ) ) {
F_37 ( V_11 , V_15 , L_33 ) ;
V_15 = F_275 ( V_29 , V_15 ) ;
if ( ! V_15 )
goto V_217;
}
if ( V_15 -> V_161 )
V_15 = F_273 ( V_11 , V_29 , V_15 ) ;
}
V_15 -> V_207 [ V_272 ] ++ ;
V_15 -> V_146 ++ ;
V_173 -> V_273 . V_274 [ 0 ] = V_15 ;
V_173 -> V_273 . V_274 [ 1 ] = F_100 ( V_15 -> V_3 ) ;
F_98 ( V_31 -> V_151 ) ;
return 0 ;
}
static void F_282 ( struct V_278 * V_279 )
{
struct V_10 * V_11 =
F_12 ( V_279 , struct V_10 , V_39 ) ;
struct V_149 * V_31 = V_11 -> V_28 ;
F_99 ( V_31 -> V_151 ) ;
F_255 ( V_11 -> V_28 ) ;
F_98 ( V_31 -> V_151 ) ;
}
static void F_283 ( unsigned long V_280 )
{
struct V_10 * V_11 = (struct V_10 * ) V_280 ;
struct V_14 * V_15 ;
unsigned long V_155 ;
int V_190 = 1 ;
F_21 ( V_11 , L_34 ) ;
F_112 ( V_11 -> V_28 -> V_151 , V_155 ) ;
V_15 = V_11 -> V_188 ;
if ( V_15 ) {
V_190 = 0 ;
if ( F_204 ( V_15 ) )
goto V_281;
if ( F_38 ( V_15 ) )
goto V_218;
if ( ! V_11 -> V_38 )
goto V_282;
if ( ! F_103 ( & V_15 -> V_101 ) )
goto V_281;
F_206 ( V_15 ) ;
}
V_218:
F_169 ( V_11 , V_190 ) ;
V_281:
F_20 ( V_11 ) ;
V_282:
F_113 ( V_11 -> V_28 -> V_151 , V_155 ) ;
}
static void F_284 ( struct V_10 * V_11 )
{
F_285 ( & V_11 -> V_189 ) ;
F_286 ( & V_11 -> V_39 ) ;
}
static void F_287 ( struct V_10 * V_11 )
{
int V_139 ;
for ( V_139 = 0 ; V_139 < V_43 ; V_139 ++ ) {
if ( V_11 -> V_245 [ 0 ] [ V_139 ] )
F_217 ( V_11 -> V_245 [ 0 ] [ V_139 ] ) ;
if ( V_11 -> V_245 [ 1 ] [ V_139 ] )
F_217 ( V_11 -> V_245 [ 1 ] [ V_139 ] ) ;
}
if ( V_11 -> V_246 )
F_217 ( V_11 -> V_246 ) ;
}
static void F_288 ( struct V_283 * V_284 )
{
struct V_10 * V_11 = V_284 -> V_33 ;
struct V_149 * V_31 = V_11 -> V_28 ;
bool V_285 = false ;
F_284 ( V_11 ) ;
F_99 ( V_31 -> V_151 ) ;
if ( V_11 -> V_188 )
F_162 ( V_11 , V_11 -> V_188 , 0 ) ;
F_287 ( V_11 ) ;
F_108 ( V_11 ) ;
if ( V_11 -> V_136 )
V_285 = true ;
F_98 ( V_31 -> V_151 ) ;
F_284 ( V_11 ) ;
if ( V_285 )
F_289 () ;
#ifdef F_247
F_104 ( V_11 -> V_148 . V_113 . V_152 ) ;
#endif
F_91 ( V_11 ) ;
}
static void * F_290 ( struct V_149 * V_31 )
{
struct V_10 * V_11 ;
int V_139 , V_140 ;
struct V_2 * V_3 ;
struct V_1 * V_53 ;
V_11 = F_291 ( sizeof( * V_11 ) , V_286 | V_244 , V_31 -> V_103 ) ;
if ( ! V_11 )
return NULL ;
V_11 -> V_63 = V_143 ;
V_3 = & V_11 -> V_148 ;
F_89 ( V_3 , V_139 , V_140 , V_53 )
* V_53 = V_143 ;
F_52 ( & V_3 -> V_94 ) ;
V_3 -> V_50 = 2 * V_49 ;
#ifdef F_247
V_3 -> V_146 = 2 ;
if ( F_90 ( & V_3 -> V_113 ) ) {
F_91 ( V_3 ) ;
F_91 ( V_11 ) ;
return NULL ;
}
F_95 () ;
F_83 ( & V_147 , & V_3 -> V_113 ,
( void * ) V_11 , 0 ) ;
F_97 () ;
V_11 -> V_136 ++ ;
F_86 ( & V_3 -> V_137 , & V_11 -> V_138 ) ;
#endif
for ( V_139 = 0 ; V_139 < V_287 ; V_139 ++ )
V_11 -> V_170 [ V_139 ] = V_288 ;
F_235 ( V_11 , & V_11 -> V_242 , 1 , 0 ) ;
V_11 -> V_242 . V_146 ++ ;
F_101 ( & V_11 -> V_242 , & V_11 -> V_148 ) ;
V_11 -> V_28 = V_31 ;
F_292 ( & V_11 -> V_189 ) ;
V_11 -> V_189 . V_289 = F_283 ;
V_11 -> V_189 . V_280 = ( unsigned long ) V_11 ;
F_293 ( & V_11 -> V_39 , F_282 ) ;
V_11 -> V_225 = V_225 ;
V_11 -> V_262 [ 0 ] = V_262 [ 0 ] ;
V_11 -> V_262 [ 1 ] = V_262 [ 1 ] ;
V_11 -> V_90 = V_90 ;
V_11 -> V_91 = V_91 ;
V_11 -> V_42 [ 0 ] = V_290 ;
V_11 -> V_42 [ 1 ] = V_291 ;
V_11 -> V_64 = V_64 ;
V_11 -> V_204 = V_204 ;
V_11 -> V_12 = V_12 ;
V_11 -> V_196 = V_196 ;
V_11 -> V_67 = 1 ;
V_11 -> V_13 = - 1 ;
V_11 -> V_227 = V_75 - V_163 ;
return V_11 ;
}
static T_6
F_294 ( unsigned int V_292 , char * V_293 )
{
return sprintf ( V_293 , L_35 , V_292 ) ;
}
static T_6
F_295 ( unsigned int * V_292 , const char * V_293 , T_7 V_22 )
{
char * V_157 = ( char * ) V_293 ;
* V_292 = F_296 ( V_157 , & V_157 , 10 ) ;
return V_22 ;
}
static int T_8 F_297 ( void )
{
int V_141 ;
if ( ! V_290 )
V_290 = 1 ;
if ( ! V_12 )
V_12 = 1 ;
#ifdef F_247
if ( ! V_196 )
V_196 = 1 ;
#else
V_196 = 0 ;
#endif
V_231 = F_298 ( V_14 , 0 ) ;
if ( ! V_231 )
return - V_294 ;
V_141 = F_299 ( & V_295 ) ;
if ( V_141 ) {
F_300 ( V_231 ) ;
return V_141 ;
}
F_301 ( & V_296 ) ;
return 0 ;
}
static void T_9 F_302 ( void )
{
F_303 ( & V_296 ) ;
F_304 ( & V_295 ) ;
F_300 ( V_231 ) ;
}
