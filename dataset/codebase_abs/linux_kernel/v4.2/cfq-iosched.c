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
static void F_2 ( struct V_10 * V_11 )
{
unsigned long long V_12 ;
if ( ! F_3 ( V_11 ) )
return;
V_12 = F_4 () ;
if ( F_5 ( V_12 , V_11 -> V_13 ) )
F_6 ( & V_11 -> V_14 ,
V_12 - V_11 -> V_13 ) ;
F_7 ( V_11 ) ;
}
static void F_8 ( struct V_2 * V_3 ,
struct V_2 * V_15 )
{
struct V_10 * V_11 = & V_3 -> V_11 ;
if ( F_3 ( V_11 ) )
return;
if ( V_3 == V_15 )
return;
V_11 -> V_13 = F_4 () ;
F_9 ( V_11 ) ;
}
static void F_10 ( struct V_10 * V_11 )
{
unsigned long long V_12 ;
if ( ! F_11 ( V_11 ) )
return;
V_12 = F_4 () ;
if ( F_5 ( V_12 , V_11 -> V_16 ) )
F_6 ( & V_11 -> V_17 ,
V_12 - V_11 -> V_16 ) ;
F_12 ( V_11 ) ;
}
static void F_13 ( struct V_2 * V_3 )
{
F_6 ( & V_3 -> V_11 . V_18 , 1 ) ;
}
static void F_14 ( struct V_2 * V_3 )
{
struct V_10 * V_11 = & V_3 -> V_11 ;
if ( F_15 ( & V_11 -> V_19 ) )
return;
if ( F_11 ( V_11 ) )
return;
V_11 -> V_16 = F_4 () ;
F_16 ( V_11 ) ;
}
static void F_17 ( struct V_2 * V_3 )
{
struct V_10 * V_11 = & V_3 -> V_11 ;
if ( F_18 ( V_11 ) ) {
unsigned long long V_12 = F_4 () ;
if ( F_5 ( V_12 , V_11 -> V_20 ) )
F_6 ( & V_11 -> V_21 ,
V_12 - V_11 -> V_20 ) ;
F_19 ( V_11 ) ;
}
}
static void F_20 ( struct V_2 * V_3 )
{
struct V_10 * V_11 = & V_3 -> V_11 ;
F_21 ( F_18 ( V_11 ) ) ;
V_11 -> V_20 = F_4 () ;
F_22 ( V_11 ) ;
}
static void F_23 ( struct V_2 * V_3 )
{
struct V_10 * V_11 = & V_3 -> V_11 ;
F_6 ( & V_11 -> V_22 ,
F_15 ( & V_11 -> V_19 ) ) ;
F_6 ( & V_11 -> V_23 , 1 ) ;
F_2 ( V_11 ) ;
}
static inline void F_8 ( struct V_2 * V_3 , struct V_2 * V_15 ) { }
static inline void F_10 ( struct V_10 * V_11 ) { }
static inline void F_13 ( struct V_2 * V_3 ) { }
static inline void F_14 ( struct V_2 * V_3 ) { }
static inline void F_17 ( struct V_2 * V_3 ) { }
static inline void F_20 ( struct V_2 * V_3 ) { }
static inline void F_23 ( struct V_2 * V_3 ) { }
static inline struct V_2 * F_24 ( struct V_24 * V_25 )
{
return V_25 ? F_25 ( V_25 , struct V_2 , V_25 ) : NULL ;
}
static struct V_26
* F_26 ( struct V_27 * V_28 )
{
return V_28 ? F_25 ( V_28 , struct V_26 , V_25 ) : NULL ;
}
static inline struct V_29 * F_27 ( struct V_2 * V_3 )
{
return F_28 ( & V_3 -> V_25 ) ;
}
static inline struct V_2 * F_29 ( struct V_29 * V_30 )
{
return F_24 ( F_30 ( V_30 , & V_31 ) ) ;
}
static struct V_26 * F_31 ( struct V_32 * V_32 )
{
return F_26 ( F_32 ( V_32 , & V_31 ) ) ;
}
static inline struct V_2 * F_33 ( struct V_2 * V_3 )
{
struct V_29 * V_33 = F_27 ( V_3 ) -> V_34 ;
return V_33 ? F_29 ( V_33 ) : NULL ;
}
static inline void F_34 ( struct V_2 * V_3 )
{
return F_35 ( F_27 ( V_3 ) ) ;
}
static inline void F_36 ( struct V_2 * V_3 )
{
return F_37 ( F_27 ( V_3 ) ) ;
}
static inline void F_38 ( struct V_2 * V_3 ,
struct V_2 * V_15 , int V_35 )
{
F_39 ( & V_3 -> V_11 . V_19 , V_35 , 1 ) ;
F_10 ( & V_3 -> V_11 ) ;
F_8 ( V_3 , V_15 ) ;
}
static inline void F_40 ( struct V_2 * V_3 ,
unsigned long time , unsigned long V_36 )
{
F_6 ( & V_3 -> V_11 . time , time ) ;
#ifdef F_41
F_6 ( & V_3 -> V_11 . V_36 , V_36 ) ;
#endif
}
static inline void F_42 ( struct V_2 * V_3 , int V_35 )
{
F_39 ( & V_3 -> V_11 . V_19 , V_35 , - 1 ) ;
}
static inline void F_43 ( struct V_2 * V_3 , int V_35 )
{
F_39 ( & V_3 -> V_11 . V_37 , V_35 , 1 ) ;
}
static inline void F_44 ( struct V_2 * V_3 ,
T_1 V_38 , int V_35 )
{
F_6 ( & V_3 -> V_11 . V_39 , V_38 >> 9 ) ;
F_39 ( & V_3 -> V_11 . V_40 , V_35 , 1 ) ;
F_39 ( & V_3 -> V_11 . V_41 , V_35 , V_38 ) ;
}
static inline void F_45 ( struct V_2 * V_3 ,
T_1 V_42 , T_1 V_43 , int V_35 )
{
struct V_10 * V_11 = & V_3 -> V_11 ;
unsigned long long V_12 = F_4 () ;
if ( F_5 ( V_12 , V_43 ) )
F_39 ( & V_11 -> V_44 , V_35 , V_12 - V_43 ) ;
if ( F_5 ( V_43 , V_42 ) )
F_39 ( & V_11 -> V_45 , V_35 ,
V_43 - V_42 ) ;
}
static void F_46 ( struct V_10 * V_11 )
{
F_47 ( & V_11 -> V_41 ) ;
F_47 ( & V_11 -> V_40 ) ;
F_47 ( & V_11 -> V_37 ) ;
F_47 ( & V_11 -> V_44 ) ;
F_47 ( & V_11 -> V_45 ) ;
F_48 ( & V_11 -> time ) ;
#ifdef F_41
F_48 ( & V_11 -> V_36 ) ;
F_48 ( & V_11 -> V_22 ) ;
F_48 ( & V_11 -> V_23 ) ;
F_48 ( & V_11 -> V_18 ) ;
F_48 ( & V_11 -> V_14 ) ;
F_48 ( & V_11 -> V_21 ) ;
F_48 ( & V_11 -> V_17 ) ;
#endif
}
static void F_49 ( struct V_10 * V_46 , struct V_10 * V_47 )
{
F_50 ( & V_46 -> V_41 , & V_47 -> V_41 ) ;
F_50 ( & V_46 -> V_40 , & V_47 -> V_40 ) ;
F_50 ( & V_46 -> V_37 , & V_47 -> V_37 ) ;
F_50 ( & V_46 -> V_44 , & V_47 -> V_44 ) ;
F_50 ( & V_46 -> V_45 , & V_47 -> V_45 ) ;
F_51 ( & V_47 -> time , & V_47 -> time ) ;
#ifdef F_41
F_51 ( & V_46 -> V_36 , & V_47 -> V_36 ) ;
F_51 ( & V_46 -> V_22 , & V_47 -> V_22 ) ;
F_51 ( & V_46 -> V_23 , & V_47 -> V_23 ) ;
F_51 ( & V_46 -> V_18 , & V_47 -> V_18 ) ;
F_51 ( & V_46 -> V_14 , & V_47 -> V_14 ) ;
F_51 ( & V_46 -> V_21 , & V_47 -> V_21 ) ;
F_51 ( & V_46 -> V_17 , & V_47 -> V_17 ) ;
#endif
}
static void F_52 ( struct V_2 * V_3 )
{
struct V_2 * V_34 = F_33 ( V_3 ) ;
F_53 ( F_27 ( V_3 ) -> V_48 -> V_49 ) ;
if ( F_54 ( ! V_34 ) )
return;
F_49 ( & V_34 -> V_50 , & V_3 -> V_11 ) ;
F_49 ( & V_34 -> V_50 , & V_3 -> V_50 ) ;
F_46 ( & V_3 -> V_11 ) ;
F_46 ( & V_3 -> V_50 ) ;
}
static inline struct V_2 * F_33 ( struct V_2 * V_3 ) { return NULL ; }
static inline void F_34 ( struct V_2 * V_3 ) { }
static inline void F_36 ( struct V_2 * V_3 ) { }
static inline void F_38 ( struct V_2 * V_3 ,
struct V_2 * V_15 , int V_35 ) { }
static inline void F_40 ( struct V_2 * V_3 ,
unsigned long time , unsigned long V_36 ) { }
static inline void F_42 ( struct V_2 * V_3 , int V_35 ) { }
static inline void F_43 ( struct V_2 * V_3 , int V_35 ) { }
static inline void F_44 ( struct V_2 * V_3 ,
T_1 V_38 , int V_35 ) { }
static inline void F_45 ( struct V_2 * V_3 ,
T_1 V_42 , T_1 V_43 , int V_35 ) { }
static inline bool F_55 ( struct V_51 * V_52 )
{
if ( ! V_52 -> V_53 && V_52 -> V_54 )
return true ;
else
return false ;
}
static inline enum V_4 F_56 ( struct V_55 * V_56 )
{
if ( F_57 ( V_56 ) )
return V_7 ;
if ( F_58 ( V_56 ) )
return V_57 ;
return V_58 ;
}
static enum V_6 F_59 ( struct V_55 * V_56 )
{
if ( ! F_60 ( V_56 ) )
return V_59 ;
if ( ! F_61 ( V_56 ) )
return V_60 ;
return V_61 ;
}
static inline int F_62 ( enum V_4 V_62 ,
struct V_51 * V_52 ,
struct V_2 * V_3 )
{
if ( V_62 == V_7 )
return V_3 -> V_8 . V_63 ;
return V_3 -> V_9 [ V_62 ] [ V_59 ] . V_63 +
V_3 -> V_9 [ V_62 ] [ V_60 ] . V_63 +
V_3 -> V_9 [ V_62 ] [ V_61 ] . V_63 ;
}
static inline int F_63 ( struct V_51 * V_52 ,
struct V_2 * V_3 )
{
return V_3 -> V_9 [ V_57 ] [ V_59 ] . V_63 +
V_3 -> V_9 [ V_58 ] [ V_59 ] . V_63 ;
}
static inline struct V_64 * F_64 ( struct V_65 * V_66 )
{
return F_25 ( V_66 , struct V_64 , V_66 ) ;
}
static inline struct V_64 * F_65 ( struct V_51 * V_52 ,
struct V_67 * V_68 )
{
if ( V_68 )
return F_64 ( F_66 ( V_68 , V_52 -> V_69 ) ) ;
return NULL ;
}
static inline struct V_55 * F_67 ( struct V_64 * V_70 , bool V_71 )
{
return V_70 -> V_56 [ V_71 ] ;
}
static inline void F_68 ( struct V_64 * V_70 , struct V_55 * V_56 ,
bool V_71 )
{
V_70 -> V_56 [ V_71 ] = V_56 ;
}
static inline struct V_51 * F_69 ( struct V_64 * V_70 )
{
return V_70 -> V_66 . V_48 -> V_72 -> V_73 ;
}
static inline bool F_70 ( struct V_74 * V_74 )
{
return F_71 ( V_74 ) == V_75 || ( V_74 -> V_76 & V_77 ) ;
}
static inline void F_72 ( struct V_51 * V_52 )
{
if ( V_52 -> V_78 ) {
F_73 ( V_52 , L_1 ) ;
F_74 ( & V_52 -> V_79 ) ;
}
}
static inline int F_75 ( struct V_51 * V_52 , bool V_80 ,
unsigned short V_81 )
{
const int V_82 = V_52 -> V_83 [ V_80 ] ;
F_76 ( V_81 >= V_84 ) ;
return V_82 + ( V_82 / V_85 * ( 4 - V_81 ) ) ;
}
static inline int
F_77 ( struct V_51 * V_52 , struct V_55 * V_56 )
{
return F_75 ( V_52 , F_60 ( V_56 ) , V_56 -> V_86 ) ;
}
static inline T_2 F_78 ( unsigned long V_87 ,
unsigned int V_88 )
{
T_2 V_89 = V_87 << V_90 ;
V_89 <<= V_90 ;
F_79 ( V_89 , V_88 ) ;
return V_89 ;
}
static inline T_2 F_80 ( T_2 V_91 , T_2 V_92 )
{
T_3 V_93 = ( T_3 ) ( V_92 - V_91 ) ;
if ( V_93 > 0 )
V_91 = V_92 ;
return V_91 ;
}
static inline T_2 V_91 ( T_2 V_91 , T_2 V_92 )
{
T_3 V_93 = ( T_3 ) ( V_92 - V_91 ) ;
if ( V_93 < 0 )
V_91 = V_92 ;
return V_91 ;
}
static void F_81 ( struct V_1 * V_94 )
{
struct V_2 * V_3 ;
if ( V_94 -> V_95 ) {
V_3 = F_82 ( V_94 -> V_95 ) ;
V_94 -> V_91 = F_80 ( V_94 -> V_91 ,
V_3 -> V_92 ) ;
}
}
static inline unsigned F_83 ( struct V_51 * V_52 ,
struct V_2 * V_3 , bool V_96 )
{
unsigned V_97 , V_98 ;
unsigned V_99 = V_100 - 1 ;
unsigned V_101 = V_100 / 2 ;
unsigned V_102 = F_62 ( V_96 , V_52 , V_3 ) ;
V_97 = F_84 ( V_3 -> V_103 [ V_96 ] , V_102 ) ;
V_98 = F_85 ( V_3 -> V_103 [ V_96 ] , V_102 ) ;
V_3 -> V_103 [ V_96 ] = ( V_99 * V_98 + V_97 + V_101 ) /
V_100 ;
return V_3 -> V_103 [ V_96 ] ;
}
static inline unsigned
F_86 ( struct V_51 * V_52 , struct V_2 * V_3 )
{
return V_52 -> V_104 * V_3 -> V_88 >> V_90 ;
}
static inline unsigned
F_87 ( struct V_51 * V_52 , struct V_55 * V_56 )
{
unsigned V_105 = F_77 ( V_52 , V_56 ) ;
if ( V_52 -> V_106 ) {
unsigned V_107 = F_83 ( V_52 , V_56 -> V_3 ,
F_58 ( V_56 ) ) ;
unsigned V_108 = V_52 -> V_83 [ 1 ] ;
unsigned V_109 = V_108 * V_107 ;
unsigned V_110 = F_86 ( V_52 , V_56 -> V_3 ) ;
if ( V_109 > V_110 ) {
unsigned V_111 = 2 * V_52 -> V_53 ;
unsigned V_112 =
F_84 ( V_105 , V_111 * V_105 / V_108 ) ;
V_105 = F_85 ( V_105 * V_110 / V_109 ,
V_112 ) ;
}
}
return V_105 ;
}
static inline void
F_88 ( struct V_51 * V_52 , struct V_55 * V_56 )
{
unsigned V_105 = F_87 ( V_52 , V_56 ) ;
V_56 -> V_113 = V_114 ;
V_56 -> V_115 = V_114 + V_105 ;
V_56 -> V_116 = V_105 ;
F_89 ( V_52 , V_56 , L_2 , V_56 -> V_115 - V_114 ) ;
}
static inline bool F_90 ( struct V_55 * V_56 )
{
if ( F_91 ( V_56 ) )
return false ;
if ( F_92 ( V_114 , V_56 -> V_115 ) )
return false ;
return true ;
}
static struct V_117 *
F_93 ( struct V_51 * V_52 , struct V_117 * V_118 , struct V_117 * V_119 , T_4 V_120 )
{
T_4 V_121 , V_122 , V_123 = 0 , V_124 = 0 ;
unsigned long V_125 ;
#define F_94 0x01
#define F_95 0x02
unsigned V_126 = 0 ;
if ( V_118 == NULL || V_118 == V_119 )
return V_119 ;
if ( V_119 == NULL )
return V_118 ;
if ( F_96 ( V_118 ) != F_96 ( V_119 ) )
return F_96 ( V_118 ) ? V_118 : V_119 ;
if ( ( V_118 -> V_127 ^ V_119 -> V_127 ) & V_128 )
return V_118 -> V_127 & V_128 ? V_118 : V_119 ;
V_121 = F_97 ( V_118 ) ;
V_122 = F_97 ( V_119 ) ;
V_125 = V_52 -> V_129 * 2 ;
if ( V_121 >= V_120 )
V_123 = V_121 - V_120 ;
else if ( V_121 + V_125 >= V_120 )
V_123 = ( V_120 - V_121 ) * V_52 -> V_130 ;
else
V_126 |= F_94 ;
if ( V_122 >= V_120 )
V_124 = V_122 - V_120 ;
else if ( V_122 + V_125 >= V_120 )
V_124 = ( V_120 - V_122 ) * V_52 -> V_130 ;
else
V_126 |= F_95 ;
switch ( V_126 ) {
case 0 :
if ( V_123 < V_124 )
return V_118 ;
else if ( V_124 < V_123 )
return V_119 ;
else {
if ( V_121 >= V_122 )
return V_118 ;
else
return V_119 ;
}
case F_95 :
return V_118 ;
case F_94 :
return V_119 ;
case ( F_94 | F_95 ) :
default:
if ( V_121 <= V_122 )
return V_118 ;
else
return V_119 ;
}
}
static struct V_55 * F_98 ( struct V_1 * V_131 )
{
if ( ! V_131 -> V_63 )
return NULL ;
if ( ! V_131 -> V_95 )
V_131 -> V_95 = F_99 ( & V_131 -> V_132 ) ;
if ( V_131 -> V_95 )
return F_100 ( V_131 -> V_95 , struct V_55 , V_133 ) ;
return NULL ;
}
static struct V_2 * F_101 ( struct V_1 * V_131 )
{
if ( ! V_131 -> V_95 )
V_131 -> V_95 = F_99 ( & V_131 -> V_132 ) ;
if ( V_131 -> V_95 )
return F_82 ( V_131 -> V_95 ) ;
return NULL ;
}
static void F_102 ( struct V_133 * V_134 , struct V_135 * V_131 )
{
F_103 ( V_134 , V_131 ) ;
F_104 ( V_134 ) ;
}
static void F_105 ( struct V_133 * V_134 , struct V_1 * V_131 )
{
if ( V_131 -> V_95 == V_134 )
V_131 -> V_95 = NULL ;
F_102 ( V_134 , & V_131 -> V_132 ) ;
-- V_131 -> V_63 ;
}
static struct V_117 *
F_106 ( struct V_51 * V_52 , struct V_55 * V_56 ,
struct V_117 * V_120 )
{
struct V_133 * V_136 = F_107 ( & V_120 -> V_133 ) ;
struct V_133 * V_137 = F_108 ( & V_120 -> V_133 ) ;
struct V_117 * V_138 = NULL , * V_139 = NULL ;
F_21 ( F_109 ( & V_120 -> V_133 ) ) ;
if ( V_137 )
V_139 = F_110 ( V_137 ) ;
if ( V_136 )
V_138 = F_110 ( V_136 ) ;
else {
V_136 = F_99 ( & V_56 -> V_140 ) ;
if ( V_136 && V_136 != & V_120 -> V_133 )
V_138 = F_110 ( V_136 ) ;
}
return F_93 ( V_52 , V_138 , V_139 , F_97 ( V_120 ) ) ;
}
static unsigned long F_111 ( struct V_51 * V_52 ,
struct V_55 * V_56 )
{
return ( V_56 -> V_3 -> V_141 - 1 ) * ( F_75 ( V_52 , 1 , 0 ) -
F_75 ( V_52 , F_60 ( V_56 ) , V_56 -> V_86 ) ) ;
}
static inline T_3
F_112 ( struct V_1 * V_94 , struct V_2 * V_3 )
{
return V_3 -> V_92 - V_94 -> V_91 ;
}
static void
F_113 ( struct V_1 * V_94 , struct V_2 * V_3 )
{
struct V_133 * * V_142 = & V_94 -> V_132 . V_133 ;
struct V_133 * V_34 = NULL ;
struct V_2 * V_143 ;
T_3 V_144 = F_112 ( V_94 , V_3 ) ;
int V_95 = 1 ;
while ( * V_142 != NULL ) {
V_34 = * V_142 ;
V_143 = F_82 ( V_34 ) ;
if ( V_144 < F_112 ( V_94 , V_143 ) )
V_142 = & V_34 -> V_145 ;
else {
V_142 = & V_34 -> V_146 ;
V_95 = 0 ;
}
}
if ( V_95 )
V_94 -> V_95 = & V_3 -> V_133 ;
F_114 ( & V_3 -> V_133 , V_34 , V_142 ) ;
F_115 ( & V_3 -> V_133 , & V_94 -> V_132 ) ;
}
static void
F_116 ( struct V_2 * V_3 )
{
if ( V_3 -> V_147 ) {
V_3 -> V_148 = V_3 -> V_147 ;
V_3 -> V_147 = 0 ;
}
}
static void
F_117 ( struct V_2 * V_3 )
{
F_21 ( ! F_109 ( & V_3 -> V_133 ) ) ;
if ( V_3 -> V_149 ) {
V_3 -> V_150 = V_3 -> V_149 ;
V_3 -> V_149 = 0 ;
}
}
static void
F_118 ( struct V_1 * V_94 , struct V_2 * V_3 )
{
unsigned int V_151 = 1 << V_90 ;
struct V_2 * V_152 = V_3 ;
struct V_2 * V_34 ;
bool V_153 ;
F_21 ( ! F_109 ( & V_3 -> V_133 ) ) ;
F_117 ( V_3 ) ;
F_113 ( V_94 , V_3 ) ;
V_153 = ! V_152 -> V_154 ++ ;
V_152 -> V_155 += V_152 -> V_150 ;
V_151 = V_151 * V_152 -> V_150 / V_152 -> V_155 ;
while ( ( V_34 = F_33 ( V_152 ) ) ) {
if ( V_153 ) {
F_116 ( V_152 ) ;
V_153 = ! V_34 -> V_154 ++ ;
V_34 -> V_155 += V_152 -> V_148 ;
}
V_151 = V_151 * V_152 -> V_148 / V_34 -> V_155 ;
V_152 = V_34 ;
}
V_3 -> V_88 = F_119 ( unsigned , V_151 , 1 ) ;
}
static void
F_120 ( struct V_51 * V_52 , struct V_2 * V_3 )
{
struct V_1 * V_94 = & V_52 -> V_156 ;
struct V_2 * V_143 ;
struct V_133 * V_134 ;
V_3 -> V_141 ++ ;
if ( ! F_109 ( & V_3 -> V_133 ) )
return;
V_134 = F_121 ( & V_94 -> V_132 ) ;
if ( V_134 ) {
V_143 = F_82 ( V_134 ) ;
V_3 -> V_92 = V_143 -> V_92 + V_157 ;
} else
V_3 -> V_92 = V_94 -> V_91 ;
F_118 ( V_94 , V_3 ) ;
}
static void
F_122 ( struct V_1 * V_94 , struct V_2 * V_3 )
{
struct V_2 * V_152 = V_3 ;
bool V_153 ;
V_153 = ! -- V_152 -> V_154 ;
V_152 -> V_155 -= V_152 -> V_150 ;
while ( V_153 ) {
struct V_2 * V_34 = F_33 ( V_152 ) ;
F_123 ( V_152 -> V_155 ) ;
V_152 -> V_88 = 0 ;
if ( ! V_34 )
break;
V_153 = ! -- V_34 -> V_154 ;
V_34 -> V_155 -= V_152 -> V_148 ;
V_152 = V_34 ;
}
if ( ! F_109 ( & V_3 -> V_133 ) )
F_105 ( & V_3 -> V_133 , V_94 ) ;
}
static void
F_124 ( struct V_51 * V_52 , struct V_2 * V_3 )
{
struct V_1 * V_94 = & V_52 -> V_156 ;
F_21 ( V_3 -> V_141 < 1 ) ;
V_3 -> V_141 -- ;
if ( V_3 -> V_141 )
return;
F_125 ( V_52 , V_3 , L_3 ) ;
F_122 ( V_94 , V_3 ) ;
V_3 -> V_158 = 0 ;
F_13 ( V_3 ) ;
}
static inline unsigned int F_126 ( struct V_55 * V_56 ,
unsigned int * V_36 )
{
unsigned int V_159 ;
if ( ! V_56 -> V_113 || V_56 -> V_113 == V_114 ) {
V_159 = F_119 ( unsigned , ( V_114 - V_56 -> V_160 ) ,
1 ) ;
} else {
V_159 = V_114 - V_56 -> V_113 ;
if ( V_159 > V_56 -> V_116 ) {
* V_36 = V_159 - V_56 -> V_116 ;
V_159 = V_56 -> V_116 ;
}
if ( F_127 ( V_56 -> V_113 , V_56 -> V_160 ) )
* V_36 += V_56 -> V_113 -
V_56 -> V_160 ;
}
return V_159 ;
}
static void F_128 ( struct V_51 * V_52 , struct V_2 * V_3 ,
struct V_55 * V_56 )
{
struct V_1 * V_94 = & V_52 -> V_156 ;
unsigned int V_161 , V_87 , V_162 = 0 ;
int V_163 = V_3 -> V_141 - F_63 ( V_52 , V_3 )
- V_3 -> V_8 . V_63 ;
unsigned int V_151 ;
F_21 ( V_163 < 0 ) ;
V_161 = V_87 = F_126 ( V_56 , & V_162 ) ;
if ( F_55 ( V_52 ) )
V_87 = V_56 -> V_164 ;
else if ( ! F_60 ( V_56 ) && ! V_163 )
V_87 = V_56 -> V_116 ;
V_151 = V_3 -> V_88 ;
F_122 ( V_94 , V_3 ) ;
V_3 -> V_92 += F_78 ( V_87 , V_151 ) ;
F_118 ( V_94 , V_3 ) ;
if ( F_127 ( V_52 -> V_165 , V_114 ) ) {
V_3 -> V_158 = V_52 -> V_165
- V_114 ;
V_3 -> V_166 = V_52 -> V_167 ;
V_3 -> V_168 = V_52 -> V_169 ;
} else
V_3 -> V_158 = 0 ;
F_125 ( V_52 , V_3 , L_4 , V_3 -> V_92 ,
V_94 -> V_91 ) ;
F_89 ( V_56 -> V_52 , V_56 ,
L_5 ,
V_161 , V_56 -> V_164 , V_87 ,
F_55 ( V_52 ) , V_56 -> V_170 ) ;
F_40 ( V_3 , V_161 , V_162 ) ;
F_14 ( V_3 ) ;
}
static void F_129 ( struct V_2 * V_3 )
{
struct V_1 * V_94 ;
int V_171 , V_172 ;
F_130 ( V_3 , V_171 , V_172 , V_94 )
* V_94 = V_173 ;
F_104 ( & V_3 -> V_133 ) ;
V_3 -> V_174 . V_175 = V_114 ;
}
static void F_131 ( struct V_10 * V_11 )
{
F_132 ( & V_11 -> V_41 ) ;
F_132 ( & V_11 -> V_40 ) ;
F_132 ( & V_11 -> V_37 ) ;
F_132 ( & V_11 -> V_44 ) ;
F_132 ( & V_11 -> V_45 ) ;
F_132 ( & V_11 -> V_19 ) ;
F_133 ( & V_11 -> V_39 ) ;
F_133 ( & V_11 -> time ) ;
#ifdef F_41
F_133 ( & V_11 -> V_36 ) ;
F_133 ( & V_11 -> V_22 ) ;
F_133 ( & V_11 -> V_23 ) ;
F_133 ( & V_11 -> V_18 ) ;
F_133 ( & V_11 -> V_14 ) ;
F_133 ( & V_11 -> V_21 ) ;
F_133 ( & V_11 -> V_17 ) ;
#endif
}
static void F_134 ( const struct V_32 * V_32 )
{
struct V_26 * V_176 =
F_26 ( V_32 -> V_25 [ V_31 . V_177 ] ) ;
if ( V_32 == & V_178 ) {
V_176 -> V_148 = 2 * V_179 ;
V_176 -> V_150 = 2 * V_179 ;
} else {
V_176 -> V_148 = V_179 ;
V_176 -> V_150 = V_179 ;
}
}
static void F_135 ( struct V_29 * V_30 )
{
struct V_2 * V_3 = F_29 ( V_30 ) ;
struct V_26 * V_176 = F_31 ( V_30 -> V_32 ) ;
F_129 ( V_3 ) ;
V_3 -> V_148 = V_176 -> V_148 ;
V_3 -> V_150 = V_176 -> V_150 ;
F_131 ( & V_3 -> V_11 ) ;
F_131 ( & V_3 -> V_50 ) ;
}
static void F_136 ( struct V_29 * V_30 )
{
F_52 ( F_29 ( V_30 ) ) ;
}
static T_2 F_137 ( struct V_24 * V_25 , int V_180 )
{
T_2 V_181 = 0 ;
V_181 += F_138 ( V_25 , V_180 ) ;
V_181 += F_138 ( V_25 , V_180 + V_182 ) ;
return V_181 ;
}
static struct V_183 F_139 ( struct V_24 * V_25 ,
int V_180 )
{
struct V_183 V_184 , V_185 ;
V_184 = F_140 ( V_25 , V_180 ) ;
V_185 = F_140 ( V_25 , V_180 + V_182 ) ;
F_50 ( & V_184 , & V_185 ) ;
return V_184 ;
}
static void F_141 ( struct V_29 * V_30 )
{
struct V_2 * V_3 = F_29 ( V_30 ) ;
F_46 ( & V_3 -> V_11 ) ;
F_46 ( & V_3 -> V_50 ) ;
}
static struct V_2 * F_142 ( struct V_51 * V_52 ,
struct V_32 * V_32 )
{
struct V_186 * V_48 = V_52 -> V_69 ;
struct V_2 * V_3 = NULL ;
if ( V_32 == & V_178 ) {
V_3 = V_52 -> V_187 ;
} else {
struct V_29 * V_30 ;
V_30 = F_143 ( V_32 , V_48 ) ;
if ( ! F_144 ( V_30 ) )
V_3 = F_29 ( V_30 ) ;
}
return V_3 ;
}
static void F_145 ( struct V_55 * V_56 , struct V_2 * V_3 )
{
if ( ! F_60 ( V_56 ) )
V_3 = V_56 -> V_52 -> V_187 ;
V_56 -> V_3 = V_3 ;
F_34 ( V_3 ) ;
}
static T_2 F_146 ( struct V_188 * V_189 ,
struct V_24 * V_25 , int V_180 )
{
struct V_2 * V_3 = F_24 ( V_25 ) ;
if ( ! V_3 -> V_190 )
return 0 ;
return F_147 ( V_189 , V_25 , V_3 -> V_190 ) ;
}
static int F_148 ( struct V_188 * V_189 , void * V_191 )
{
F_149 ( V_189 , F_150 ( F_151 ( V_189 ) ) ,
F_146 , & V_31 ,
0 , false ) ;
return 0 ;
}
static T_2 F_152 ( struct V_188 * V_189 ,
struct V_24 * V_25 , int V_180 )
{
struct V_2 * V_3 = F_24 ( V_25 ) ;
if ( ! V_3 -> V_192 )
return 0 ;
return F_147 ( V_189 , V_25 , V_3 -> V_192 ) ;
}
static int F_153 ( struct V_188 * V_189 , void * V_191 )
{
F_149 ( V_189 , F_150 ( F_151 ( V_189 ) ) ,
F_152 , & V_31 ,
0 , false ) ;
return 0 ;
}
static int F_154 ( struct V_188 * V_189 , void * V_191 )
{
struct V_32 * V_32 = F_150 ( F_151 ( V_189 ) ) ;
struct V_26 * V_176 = F_31 ( V_32 ) ;
unsigned int V_193 = 0 ;
if ( V_176 )
V_193 = V_176 -> V_148 ;
F_155 ( V_189 , L_6 , V_193 ) ;
return 0 ;
}
static int F_156 ( struct V_188 * V_189 , void * V_191 )
{
struct V_32 * V_32 = F_150 ( F_151 ( V_189 ) ) ;
struct V_26 * V_176 = F_31 ( V_32 ) ;
unsigned int V_193 = 0 ;
if ( V_176 )
V_193 = V_176 -> V_150 ;
F_155 ( V_189 , L_6 , V_193 ) ;
return 0 ;
}
static T_5 F_157 ( struct V_194 * V_195 ,
char * V_196 , T_6 V_197 , T_7 V_180 ,
bool V_198 )
{
struct V_32 * V_32 = F_150 ( F_158 ( V_195 ) ) ;
struct V_199 V_200 ;
struct V_2 * V_3 ;
struct V_26 * V_201 ;
int V_202 ;
V_202 = F_159 ( V_32 , & V_31 , V_196 , & V_200 ) ;
if ( V_202 )
return V_202 ;
V_202 = - V_203 ;
V_3 = F_29 ( V_200 . V_30 ) ;
V_201 = F_31 ( V_32 ) ;
if ( ! V_3 || ! V_201 )
goto V_204;
if ( ! V_200 . V_191 || ( V_200 . V_191 >= V_205 && V_200 . V_191 <= V_206 ) ) {
if ( ! V_198 ) {
V_3 -> V_190 = V_200 . V_191 ;
V_3 -> V_147 = V_200 . V_191 ? : V_201 -> V_148 ;
} else {
V_3 -> V_192 = V_200 . V_191 ;
V_3 -> V_149 = V_200 . V_191 ? : V_201 -> V_150 ;
}
V_202 = 0 ;
}
V_204:
F_160 ( & V_200 ) ;
return V_202 ? : V_197 ;
}
static T_5 F_161 ( struct V_194 * V_195 ,
char * V_196 , T_6 V_197 , T_7 V_180 )
{
return F_157 ( V_195 , V_196 , V_197 , V_180 , false ) ;
}
static T_5 F_162 ( struct V_194 * V_195 ,
char * V_196 , T_6 V_197 , T_7 V_180 )
{
return F_157 ( V_195 , V_196 , V_197 , V_180 , true ) ;
}
static int F_163 ( struct V_207 * V_208 , struct V_209 * V_210 ,
T_2 V_193 , bool V_198 )
{
struct V_32 * V_32 = F_150 ( V_208 ) ;
struct V_29 * V_30 ;
struct V_26 * V_201 ;
int V_202 = 0 ;
if ( V_193 < V_205 || V_193 > V_206 )
return - V_203 ;
F_164 ( & V_32 -> V_211 ) ;
V_201 = F_31 ( V_32 ) ;
if ( ! V_201 ) {
V_202 = - V_203 ;
goto V_212;
}
if ( ! V_198 )
V_201 -> V_148 = V_193 ;
else
V_201 -> V_150 = V_193 ;
F_165 (blkg, &blkcg->blkg_list, blkcg_node) {
struct V_2 * V_3 = F_29 ( V_30 ) ;
if ( ! V_3 )
continue;
if ( ! V_198 ) {
if ( ! V_3 -> V_190 )
V_3 -> V_147 = V_201 -> V_148 ;
} else {
if ( ! V_3 -> V_192 )
V_3 -> V_149 = V_201 -> V_150 ;
}
}
V_212:
F_166 ( & V_32 -> V_211 ) ;
return V_202 ;
}
static int F_167 ( struct V_207 * V_208 , struct V_209 * V_210 ,
T_2 V_193 )
{
return F_163 ( V_208 , V_210 , V_193 , false ) ;
}
static int F_168 ( struct V_207 * V_208 ,
struct V_209 * V_210 , T_2 V_193 )
{
return F_163 ( V_208 , V_210 , V_193 , true ) ;
}
static int F_169 ( struct V_188 * V_189 , void * V_191 )
{
F_149 ( V_189 , F_150 ( F_151 ( V_189 ) ) , V_213 ,
& V_31 , F_170 ( V_189 ) -> V_214 , false ) ;
return 0 ;
}
static int F_171 ( struct V_188 * V_189 , void * V_191 )
{
F_149 ( V_189 , F_150 ( F_151 ( V_189 ) ) , V_215 ,
& V_31 , F_170 ( V_189 ) -> V_214 , true ) ;
return 0 ;
}
static T_2 F_172 ( struct V_188 * V_189 ,
struct V_24 * V_25 , int V_180 )
{
T_2 V_181 = F_137 ( V_25 , V_180 ) ;
return F_147 ( V_189 , V_25 , V_181 ) ;
}
static T_2 F_173 ( struct V_188 * V_189 ,
struct V_24 * V_25 , int V_180 )
{
struct V_183 V_181 = F_139 ( V_25 , V_180 ) ;
return F_174 ( V_189 , V_25 , & V_181 ) ;
}
static int F_175 ( struct V_188 * V_189 , void * V_191 )
{
F_149 ( V_189 , F_150 ( F_151 ( V_189 ) ) ,
F_172 , & V_31 ,
F_170 ( V_189 ) -> V_214 , false ) ;
return 0 ;
}
static int F_176 ( struct V_188 * V_189 , void * V_191 )
{
F_149 ( V_189 , F_150 ( F_151 ( V_189 ) ) ,
F_173 , & V_31 ,
F_170 ( V_189 ) -> V_214 , true ) ;
return 0 ;
}
static T_2 F_177 ( struct V_188 * V_189 ,
struct V_24 * V_25 , int V_180 )
{
struct V_2 * V_3 = F_24 ( V_25 ) ;
T_2 V_216 = F_178 ( & V_3 -> V_11 . V_23 ) ;
T_2 V_191 = 0 ;
if ( V_216 ) {
V_191 = F_178 ( & V_3 -> V_11 . V_22 ) ;
V_191 = F_179 ( V_191 , V_216 ) ;
}
F_147 ( V_189 , V_25 , V_191 ) ;
return 0 ;
}
static int F_180 ( struct V_188 * V_189 , void * V_191 )
{
F_149 ( V_189 , F_150 ( F_151 ( V_189 ) ) ,
F_177 , & V_31 ,
0 , false ) ;
return 0 ;
}
static struct V_2 * F_142 ( struct V_51 * V_52 ,
struct V_32 * V_32 )
{
return V_52 -> V_187 ;
}
static inline void
F_145 ( struct V_55 * V_56 , struct V_2 * V_3 ) {
V_56 -> V_3 = V_3 ;
}
static void F_181 ( struct V_51 * V_52 , struct V_55 * V_56 ,
bool V_217 )
{
struct V_133 * * V_218 , * V_34 ;
struct V_55 * V_219 ;
unsigned long V_220 ;
struct V_1 * V_94 ;
int V_95 ;
int V_221 = 1 ;
V_94 = F_1 ( V_56 -> V_3 , F_56 ( V_56 ) , F_59 ( V_56 ) ) ;
if ( F_57 ( V_56 ) ) {
V_220 = V_157 ;
V_34 = F_121 ( & V_94 -> V_132 ) ;
if ( V_34 && V_34 != & V_56 -> V_133 ) {
V_219 = F_100 ( V_34 , struct V_55 , V_133 ) ;
V_220 += V_219 -> V_220 ;
} else
V_220 += V_114 ;
} else if ( ! V_217 ) {
V_220 = F_111 ( V_52 , V_56 ) + V_114 ;
V_220 -= V_56 -> V_222 ;
V_56 -> V_222 = 0 ;
} else {
V_220 = - V_223 ;
V_219 = F_98 ( V_94 ) ;
V_220 += V_219 ? V_219 -> V_220 : V_114 ;
}
if ( ! F_109 ( & V_56 -> V_133 ) ) {
V_221 = 0 ;
if ( V_220 == V_56 -> V_220 && V_56 -> V_224 == V_94 )
return;
F_105 ( & V_56 -> V_133 , V_56 -> V_224 ) ;
V_56 -> V_224 = NULL ;
}
V_95 = 1 ;
V_34 = NULL ;
V_56 -> V_224 = V_94 ;
V_218 = & V_94 -> V_132 . V_133 ;
while ( * V_218 ) {
V_34 = * V_218 ;
V_219 = F_100 ( V_34 , struct V_55 , V_133 ) ;
if ( F_92 ( V_220 , V_219 -> V_220 ) )
V_218 = & V_34 -> V_145 ;
else {
V_218 = & V_34 -> V_146 ;
V_95 = 0 ;
}
}
if ( V_95 )
V_94 -> V_95 = & V_56 -> V_133 ;
V_56 -> V_220 = V_220 ;
F_114 ( & V_56 -> V_133 , V_34 , V_218 ) ;
F_115 ( & V_56 -> V_133 , & V_94 -> V_132 ) ;
V_94 -> V_63 ++ ;
if ( V_217 || ! V_221 )
return;
F_120 ( V_52 , V_56 -> V_3 ) ;
}
static struct V_55 *
F_182 ( struct V_51 * V_52 , struct V_135 * V_131 ,
T_4 V_225 , struct V_133 * * V_226 ,
struct V_133 * * * V_227 )
{
struct V_133 * * V_218 , * V_34 ;
struct V_55 * V_56 = NULL ;
V_34 = NULL ;
V_218 = & V_131 -> V_133 ;
while ( * V_218 ) {
struct V_133 * * V_134 ;
V_34 = * V_218 ;
V_56 = F_100 ( V_34 , struct V_55 , V_228 ) ;
if ( V_225 > F_97 ( V_56 -> V_229 ) )
V_134 = & ( * V_218 ) -> V_146 ;
else if ( V_225 < F_97 ( V_56 -> V_229 ) )
V_134 = & ( * V_218 ) -> V_145 ;
else
break;
V_218 = V_134 ;
V_56 = NULL ;
}
* V_226 = V_34 ;
if ( V_227 )
* V_227 = V_218 ;
return V_56 ;
}
static void F_183 ( struct V_51 * V_52 , struct V_55 * V_56 )
{
struct V_133 * * V_218 , * V_34 ;
struct V_55 * V_219 ;
if ( V_56 -> V_230 ) {
F_103 ( & V_56 -> V_228 , V_56 -> V_230 ) ;
V_56 -> V_230 = NULL ;
}
if ( F_57 ( V_56 ) )
return;
if ( ! V_56 -> V_229 )
return;
V_56 -> V_230 = & V_52 -> V_231 [ V_56 -> V_232 ] ;
V_219 = F_182 ( V_52 , V_56 -> V_230 ,
F_97 ( V_56 -> V_229 ) , & V_34 , & V_218 ) ;
if ( ! V_219 ) {
F_114 ( & V_56 -> V_228 , V_34 , V_218 ) ;
F_115 ( & V_56 -> V_228 , V_56 -> V_230 ) ;
} else
V_56 -> V_230 = NULL ;
}
static void F_184 ( struct V_51 * V_52 , struct V_55 * V_56 )
{
if ( F_185 ( V_56 ) ) {
F_181 ( V_52 , V_56 , 0 ) ;
F_183 ( V_52 , V_56 ) ;
}
}
static void F_186 ( struct V_51 * V_52 , struct V_55 * V_56 )
{
F_89 ( V_52 , V_56 , L_7 ) ;
F_21 ( F_185 ( V_56 ) ) ;
F_187 ( V_56 ) ;
V_52 -> V_78 ++ ;
if ( F_60 ( V_56 ) )
V_52 -> V_233 ++ ;
F_184 ( V_52 , V_56 ) ;
}
static void F_188 ( struct V_51 * V_52 , struct V_55 * V_56 )
{
F_89 ( V_52 , V_56 , L_8 ) ;
F_21 ( ! F_185 ( V_56 ) ) ;
F_189 ( V_56 ) ;
if ( ! F_109 ( & V_56 -> V_133 ) ) {
F_105 ( & V_56 -> V_133 , V_56 -> V_224 ) ;
V_56 -> V_224 = NULL ;
}
if ( V_56 -> V_230 ) {
F_103 ( & V_56 -> V_228 , V_56 -> V_230 ) ;
V_56 -> V_230 = NULL ;
}
F_124 ( V_52 , V_56 -> V_3 ) ;
F_21 ( ! V_52 -> V_78 ) ;
V_52 -> V_78 -- ;
if ( F_60 ( V_56 ) )
V_52 -> V_233 -- ;
}
static void F_190 ( struct V_117 * V_234 )
{
struct V_55 * V_56 = F_191 ( V_234 ) ;
const int V_80 = F_96 ( V_234 ) ;
F_21 ( ! V_56 -> V_19 [ V_80 ] ) ;
V_56 -> V_19 [ V_80 ] -- ;
F_192 ( & V_56 -> V_140 , V_234 ) ;
if ( F_185 ( V_56 ) && F_193 ( & V_56 -> V_140 ) ) {
if ( V_56 -> V_230 ) {
F_103 ( & V_56 -> V_228 , V_56 -> V_230 ) ;
V_56 -> V_230 = NULL ;
}
}
}
static void F_194 ( struct V_117 * V_234 )
{
struct V_55 * V_56 = F_191 ( V_234 ) ;
struct V_51 * V_52 = V_56 -> V_52 ;
struct V_117 * V_139 ;
V_56 -> V_19 [ F_96 ( V_234 ) ] ++ ;
F_195 ( & V_56 -> V_140 , V_234 ) ;
if ( ! F_185 ( V_56 ) )
F_186 ( V_52 , V_56 ) ;
V_139 = V_56 -> V_229 ;
V_56 -> V_229 = F_93 ( V_52 , V_56 -> V_229 , V_234 , V_52 -> V_235 ) ;
if ( V_139 != V_56 -> V_229 )
F_183 ( V_52 , V_56 ) ;
F_21 ( ! V_56 -> V_229 ) ;
}
static void F_196 ( struct V_55 * V_56 , struct V_117 * V_234 )
{
F_192 ( & V_56 -> V_140 , V_234 ) ;
V_56 -> V_19 [ F_96 ( V_234 ) ] -- ;
F_42 ( F_197 ( V_234 ) , V_234 -> V_127 ) ;
F_194 ( V_234 ) ;
F_38 ( F_197 ( V_234 ) , V_56 -> V_52 -> V_236 ,
V_234 -> V_127 ) ;
}
static struct V_117 *
F_198 ( struct V_51 * V_52 , struct V_74 * V_74 )
{
struct V_237 * V_238 = V_239 ;
struct V_64 * V_70 ;
struct V_55 * V_56 ;
V_70 = F_65 ( V_52 , V_238 -> V_67 ) ;
if ( ! V_70 )
return NULL ;
V_56 = F_67 ( V_70 , F_70 ( V_74 ) ) ;
if ( V_56 )
return F_199 ( & V_56 -> V_140 , F_200 ( V_74 ) ) ;
return NULL ;
}
static void F_201 ( struct V_186 * V_48 , struct V_117 * V_234 )
{
struct V_51 * V_52 = V_48 -> V_72 -> V_73 ;
V_52 -> V_240 ++ ;
F_89 ( V_52 , F_191 ( V_234 ) , L_9 ,
V_52 -> V_240 ) ;
V_52 -> V_235 = F_97 ( V_234 ) + F_202 ( V_234 ) ;
}
static void F_203 ( struct V_186 * V_48 , struct V_117 * V_234 )
{
struct V_51 * V_52 = V_48 -> V_72 -> V_73 ;
F_76 ( ! V_52 -> V_240 ) ;
V_52 -> V_240 -- ;
F_89 ( V_52 , F_191 ( V_234 ) , L_10 ,
V_52 -> V_240 ) ;
}
static void F_204 ( struct V_117 * V_234 )
{
struct V_55 * V_56 = F_191 ( V_234 ) ;
if ( V_56 -> V_229 == V_234 )
V_56 -> V_229 = F_106 ( V_56 -> V_52 , V_56 , V_234 ) ;
F_205 ( & V_234 -> V_241 ) ;
F_190 ( V_234 ) ;
V_56 -> V_52 -> V_242 -- ;
F_42 ( F_197 ( V_234 ) , V_234 -> V_127 ) ;
if ( V_234 -> V_127 & V_128 ) {
F_76 ( ! V_56 -> V_243 ) ;
V_56 -> V_243 -- ;
}
}
static int F_206 ( struct V_186 * V_48 , struct V_117 * * V_244 ,
struct V_74 * V_74 )
{
struct V_51 * V_52 = V_48 -> V_72 -> V_73 ;
struct V_117 * V_245 ;
V_245 = F_198 ( V_52 , V_74 ) ;
if ( V_245 && F_207 ( V_245 , V_74 ) ) {
* V_244 = V_245 ;
return V_246 ;
}
return V_247 ;
}
static void F_208 ( struct V_186 * V_48 , struct V_117 * V_244 ,
int type )
{
if ( type == V_246 ) {
struct V_55 * V_56 = F_191 ( V_244 ) ;
F_196 ( V_56 , V_244 ) ;
}
}
static void F_209 ( struct V_186 * V_48 , struct V_117 * V_244 ,
struct V_74 * V_74 )
{
F_43 ( F_197 ( V_244 ) , V_74 -> V_76 ) ;
}
static void
F_210 ( struct V_186 * V_48 , struct V_117 * V_234 ,
struct V_117 * V_138 )
{
struct V_55 * V_56 = F_191 ( V_234 ) ;
struct V_51 * V_52 = V_48 -> V_72 -> V_73 ;
if ( ! F_211 ( & V_234 -> V_241 ) && ! F_211 ( & V_138 -> V_241 ) &&
F_92 ( V_138 -> V_248 , V_234 -> V_248 ) &&
V_56 == F_191 ( V_138 ) ) {
F_212 ( & V_234 -> V_241 , & V_138 -> V_241 ) ;
V_234 -> V_248 = V_138 -> V_248 ;
}
if ( V_56 -> V_229 == V_138 )
V_56 -> V_229 = V_234 ;
F_204 ( V_138 ) ;
F_43 ( F_197 ( V_234 ) , V_138 -> V_127 ) ;
V_56 = F_191 ( V_138 ) ;
if ( F_185 ( V_56 ) && F_193 ( & V_56 -> V_140 ) &&
V_56 != V_52 -> V_249 )
F_188 ( V_52 , V_56 ) ;
}
static int F_213 ( struct V_186 * V_48 , struct V_117 * V_234 ,
struct V_74 * V_74 )
{
struct V_51 * V_52 = V_48 -> V_72 -> V_73 ;
struct V_64 * V_70 ;
struct V_55 * V_56 ;
if ( F_70 ( V_74 ) && ! F_96 ( V_234 ) )
return false ;
V_70 = F_65 ( V_52 , V_239 -> V_67 ) ;
if ( ! V_70 )
return false ;
V_56 = F_67 ( V_70 , F_70 ( V_74 ) ) ;
return V_56 == F_191 ( V_234 ) ;
}
static inline void F_214 ( struct V_51 * V_52 , struct V_55 * V_56 )
{
F_215 ( & V_52 -> V_250 ) ;
F_17 ( V_56 -> V_3 ) ;
}
static void F_216 ( struct V_51 * V_52 ,
struct V_55 * V_56 )
{
if ( V_56 ) {
F_89 ( V_52 , V_56 , L_11 ,
V_52 -> V_169 , V_52 -> V_167 ) ;
F_23 ( V_56 -> V_3 ) ;
V_56 -> V_113 = 0 ;
V_56 -> V_160 = V_114 ;
V_56 -> V_116 = 0 ;
V_56 -> V_115 = 0 ;
V_56 -> V_164 = 0 ;
V_56 -> V_170 = 0 ;
F_217 ( V_56 ) ;
F_218 ( V_56 ) ;
F_219 ( V_56 ) ;
F_220 ( V_56 ) ;
F_221 ( V_56 ) ;
F_214 ( V_52 , V_56 ) ;
}
V_52 -> V_249 = V_56 ;
}
static void
F_222 ( struct V_51 * V_52 , struct V_55 * V_56 ,
bool V_251 )
{
F_89 ( V_52 , V_56 , L_12 , V_251 ) ;
if ( F_223 ( V_56 ) )
F_214 ( V_52 , V_56 ) ;
F_217 ( V_56 ) ;
F_224 ( V_56 ) ;
if ( F_225 ( V_56 ) && F_226 ( V_56 ) )
F_227 ( V_56 ) ;
if ( V_251 ) {
if ( F_91 ( V_56 ) )
V_56 -> V_222 = F_87 ( V_52 , V_56 ) ;
else
V_56 -> V_222 = V_56 -> V_115 - V_114 ;
F_89 ( V_52 , V_56 , L_13 , V_56 -> V_222 ) ;
}
F_128 ( V_52 , V_56 -> V_3 , V_56 ) ;
if ( F_185 ( V_56 ) && F_193 ( & V_56 -> V_140 ) )
F_188 ( V_52 , V_56 ) ;
F_184 ( V_52 , V_56 ) ;
if ( V_56 == V_52 -> V_249 )
V_52 -> V_249 = NULL ;
if ( V_52 -> V_252 ) {
F_228 ( V_52 -> V_252 -> V_66 . V_68 ) ;
V_52 -> V_252 = NULL ;
}
}
static inline void F_229 ( struct V_51 * V_52 , bool V_251 )
{
struct V_55 * V_56 = V_52 -> V_249 ;
if ( V_56 )
F_222 ( V_52 , V_56 , V_251 ) ;
}
static struct V_55 * F_230 ( struct V_51 * V_52 )
{
struct V_1 * V_94 = F_1 ( V_52 -> V_236 ,
V_52 -> V_169 , V_52 -> V_167 ) ;
if ( ! V_52 -> V_242 )
return NULL ;
if ( ! V_94 )
return NULL ;
if ( F_193 ( & V_94 -> V_132 ) )
return NULL ;
return F_98 ( V_94 ) ;
}
static struct V_55 * F_231 ( struct V_51 * V_52 )
{
struct V_2 * V_3 ;
struct V_55 * V_56 ;
int V_171 , V_172 ;
struct V_1 * V_94 ;
if ( ! V_52 -> V_242 )
return NULL ;
V_3 = F_232 ( V_52 ) ;
if ( ! V_3 )
return NULL ;
F_130 (cfqg, i, j, st)
if ( ( V_56 = F_98 ( V_94 ) ) != NULL )
return V_56 ;
return NULL ;
}
static struct V_55 * F_233 ( struct V_51 * V_52 ,
struct V_55 * V_56 )
{
if ( ! V_56 )
V_56 = F_230 ( V_52 ) ;
F_216 ( V_52 , V_56 ) ;
return V_56 ;
}
static inline T_4 F_234 ( struct V_51 * V_52 ,
struct V_117 * V_234 )
{
if ( F_97 ( V_234 ) >= V_52 -> V_235 )
return F_97 ( V_234 ) - V_52 -> V_235 ;
else
return V_52 -> V_235 - F_97 ( V_234 ) ;
}
static inline int F_235 ( struct V_51 * V_52 , struct V_55 * V_56 ,
struct V_117 * V_234 )
{
return F_234 ( V_52 , V_234 ) <= V_253 ;
}
static struct V_55 * F_236 ( struct V_51 * V_52 ,
struct V_55 * V_254 )
{
struct V_135 * V_131 = & V_52 -> V_231 [ V_254 -> V_232 ] ;
struct V_133 * V_34 , * V_142 ;
struct V_55 * V_219 ;
T_4 V_225 = V_52 -> V_235 ;
if ( F_193 ( V_131 ) )
return NULL ;
V_219 = F_182 ( V_52 , V_131 , V_225 , & V_34 , NULL ) ;
if ( V_219 )
return V_219 ;
V_219 = F_100 ( V_34 , struct V_55 , V_228 ) ;
if ( F_235 ( V_52 , V_254 , V_219 -> V_229 ) )
return V_219 ;
if ( F_97 ( V_219 -> V_229 ) < V_225 )
V_142 = F_107 ( & V_219 -> V_228 ) ;
else
V_142 = F_108 ( & V_219 -> V_228 ) ;
if ( ! V_142 )
return NULL ;
V_219 = F_100 ( V_142 , struct V_55 , V_228 ) ;
if ( F_235 ( V_52 , V_254 , V_219 -> V_229 ) )
return V_219 ;
return NULL ;
}
static struct V_55 * F_237 ( struct V_51 * V_52 ,
struct V_55 * V_254 )
{
struct V_55 * V_56 ;
if ( F_57 ( V_254 ) )
return NULL ;
if ( ! F_60 ( V_254 ) )
return NULL ;
if ( F_226 ( V_254 ) )
return NULL ;
if ( V_254 -> V_3 -> V_141 == 1 )
return NULL ;
V_56 = F_236 ( V_52 , V_254 ) ;
if ( ! V_56 )
return NULL ;
if ( V_254 -> V_3 != V_56 -> V_3 )
return NULL ;
if ( ! F_60 ( V_56 ) )
return NULL ;
if ( F_226 ( V_56 ) )
return NULL ;
if ( F_58 ( V_56 ) != F_58 ( V_254 ) )
return NULL ;
return V_56 ;
}
static bool F_238 ( struct V_51 * V_52 , struct V_55 * V_56 )
{
enum V_4 V_62 = F_56 ( V_56 ) ;
struct V_1 * V_94 = V_56 -> V_224 ;
F_21 ( ! V_94 ) ;
F_21 ( ! V_94 -> V_63 ) ;
if ( ! V_52 -> V_53 )
return false ;
if ( V_62 == V_7 )
return false ;
if ( F_61 ( V_56 ) &&
! ( F_239 ( V_52 -> V_69 ) && V_52 -> V_54 ) )
return true ;
if ( V_94 -> V_63 == 1 && F_60 ( V_56 ) &&
! F_240 ( V_52 , & V_94 -> V_174 , false ) )
return true ;
F_89 ( V_52 , V_56 , L_14 , V_94 -> V_63 ) ;
return false ;
}
static void F_241 ( struct V_51 * V_52 )
{
struct V_55 * V_56 = V_52 -> V_249 ;
struct V_64 * V_70 ;
unsigned long V_255 , V_256 = 0 ;
if ( F_239 ( V_52 -> V_69 ) && V_52 -> V_54 )
return;
F_76 ( ! F_193 ( & V_56 -> V_140 ) ) ;
F_76 ( F_91 ( V_56 ) ) ;
if ( ! F_238 ( V_52 , V_56 ) ) {
if ( V_52 -> V_257 )
V_256 = V_52 -> V_257 ;
else
return;
}
if ( V_56 -> V_258 )
return;
V_70 = V_52 -> V_252 ;
if ( ! V_70 || ! F_242 ( & V_70 -> V_66 . V_68 -> V_259 ) )
return;
if ( F_243 ( V_70 -> V_174 . V_260 ) &&
( V_56 -> V_115 - V_114 < V_70 -> V_174 . V_261 ) ) {
F_89 ( V_52 , V_56 , L_15 ,
V_70 -> V_174 . V_261 ) ;
return;
}
if ( V_256 && V_56 -> V_3 -> V_141 > 1 )
return;
F_244 ( V_56 ) ;
if ( V_256 )
V_255 = V_52 -> V_257 ;
else
V_255 = V_52 -> V_53 ;
F_245 ( & V_52 -> V_250 , V_114 + V_255 ) ;
F_20 ( V_56 -> V_3 ) ;
F_89 ( V_52 , V_56 , L_16 , V_255 ,
V_256 ? 1 : 0 ) ;
}
static void F_246 ( struct V_186 * V_48 , struct V_117 * V_234 )
{
struct V_51 * V_52 = V_48 -> V_72 -> V_73 ;
struct V_55 * V_56 = F_191 ( V_234 ) ;
F_89 ( V_52 , V_56 , L_17 ) ;
V_56 -> V_229 = F_106 ( V_52 , V_56 , V_234 ) ;
F_204 ( V_234 ) ;
V_56 -> V_258 ++ ;
( F_197 ( V_234 ) ) -> V_258 ++ ;
F_247 ( V_48 , V_234 ) ;
V_52 -> V_262 [ F_60 ( V_56 ) ] ++ ;
V_56 -> V_170 += F_202 ( V_234 ) ;
F_44 ( V_56 -> V_3 , F_248 ( V_234 ) , V_234 -> V_127 ) ;
}
static struct V_117 * F_249 ( struct V_55 * V_56 )
{
struct V_117 * V_234 = NULL ;
if ( F_250 ( V_56 ) )
return NULL ;
F_251 ( V_56 ) ;
if ( F_211 ( & V_56 -> V_263 ) )
return NULL ;
V_234 = F_252 ( V_56 -> V_263 . V_138 ) ;
if ( F_92 ( V_114 , V_234 -> V_248 ) )
V_234 = NULL ;
F_89 ( V_56 -> V_52 , V_56 , L_18 , V_234 ) ;
return V_234 ;
}
static inline int
F_253 ( struct V_51 * V_52 , struct V_55 * V_56 )
{
const int V_264 = V_52 -> V_265 ;
F_76 ( V_56 -> V_86 >= V_84 ) ;
return 2 * V_264 * ( V_84 - V_56 -> V_86 ) ;
}
static int F_254 ( struct V_55 * V_56 )
{
int V_266 , V_267 ;
V_267 = V_56 -> V_268 [ V_75 ] + V_56 -> V_268 [ V_269 ] ;
V_266 = V_56 -> V_270 - V_267 ;
F_21 ( V_266 < 0 ) ;
return V_266 ;
}
static void F_255 ( struct V_55 * V_56 , struct V_55 * V_221 )
{
int V_266 , V_271 ;
struct V_55 * V_219 ;
if ( ! F_254 ( V_221 ) )
return;
while ( ( V_219 = V_221 -> V_221 ) ) {
if ( V_219 == V_56 )
return;
V_221 = V_219 ;
}
V_266 = F_254 ( V_56 ) ;
V_271 = F_254 ( V_221 ) ;
if ( V_266 == 0 || V_271 == 0 )
return;
if ( V_271 >= V_266 ) {
V_56 -> V_221 = V_221 ;
V_221 -> V_270 += V_266 ;
} else {
V_221 -> V_221 = V_56 ;
V_56 -> V_270 += V_271 ;
}
}
static enum V_6 F_256 ( struct V_51 * V_52 ,
struct V_2 * V_3 , enum V_4 V_62 )
{
struct V_55 * V_69 ;
int V_171 ;
bool V_272 = false ;
unsigned long V_273 = 0 ;
enum V_6 V_274 = V_60 ;
for ( V_171 = 0 ; V_171 <= V_61 ; ++ V_171 ) {
V_69 = F_98 ( F_1 ( V_3 , V_62 , V_171 ) ) ;
if ( V_69 &&
( ! V_272 || F_92 ( V_69 -> V_220 , V_273 ) ) ) {
V_273 = V_69 -> V_220 ;
V_274 = V_171 ;
V_272 = true ;
}
}
return V_274 ;
}
static void
F_257 ( struct V_51 * V_52 , struct V_2 * V_3 )
{
unsigned V_105 ;
unsigned V_63 ;
struct V_1 * V_94 ;
unsigned V_110 ;
enum V_4 V_275 = V_52 -> V_169 ;
if ( F_62 ( V_57 , V_52 , V_3 ) )
V_52 -> V_169 = V_57 ;
else if ( F_62 ( V_58 , V_52 , V_3 ) )
V_52 -> V_169 = V_58 ;
else {
V_52 -> V_169 = V_7 ;
V_52 -> V_165 = V_114 + 1 ;
return;
}
if ( V_275 != V_52 -> V_169 )
goto V_276;
V_94 = F_1 ( V_3 , V_52 -> V_169 , V_52 -> V_167 ) ;
V_63 = V_94 -> V_63 ;
if ( V_63 && ! F_127 ( V_114 , V_52 -> V_165 ) )
return;
V_276:
V_52 -> V_167 = F_256 ( V_52 , V_3 ,
V_52 -> V_169 ) ;
V_94 = F_1 ( V_3 , V_52 -> V_169 , V_52 -> V_167 ) ;
V_63 = V_94 -> V_63 ;
V_110 = F_86 ( V_52 , V_3 ) ;
V_105 = V_110 * V_63 /
F_119 ( unsigned , V_3 -> V_103 [ V_52 -> V_169 ] ,
F_62 ( V_52 -> V_169 , V_52 ,
V_3 ) ) ;
if ( V_52 -> V_167 == V_59 ) {
unsigned int V_277 ;
V_277 = V_52 -> V_104 *
F_63 ( V_52 , V_3 ) ;
V_277 = V_277 / V_52 -> V_78 ;
V_105 = F_258 ( unsigned , V_105 , V_277 ) ;
V_105 = V_105 * V_52 -> V_83 [ 0 ] / V_52 -> V_83 [ 1 ] ;
} else
V_105 = F_85 ( V_105 , 2 * V_52 -> V_53 ) ;
V_105 = F_119 ( unsigned , V_105 , V_278 ) ;
F_73 ( V_52 , L_19 , V_105 ) ;
V_52 -> V_165 = V_114 + V_105 ;
}
static struct V_2 * F_232 ( struct V_51 * V_52 )
{
struct V_1 * V_94 = & V_52 -> V_156 ;
struct V_2 * V_3 ;
if ( F_193 ( & V_94 -> V_132 ) )
return NULL ;
V_3 = F_101 ( V_94 ) ;
F_81 ( V_94 ) ;
return V_3 ;
}
static void F_259 ( struct V_51 * V_52 )
{
struct V_2 * V_3 = F_232 ( V_52 ) ;
V_52 -> V_236 = V_3 ;
if ( V_3 -> V_158 ) {
V_52 -> V_165 = V_114 + V_3 -> V_158 ;
V_52 -> V_167 = V_3 -> V_166 ;
V_52 -> V_169 = V_3 -> V_168 ;
} else
V_52 -> V_165 = V_114 - 1 ;
F_257 ( V_52 , V_3 ) ;
}
static struct V_55 * F_260 ( struct V_51 * V_52 )
{
struct V_55 * V_56 , * V_221 = NULL ;
V_56 = V_52 -> V_249 ;
if ( ! V_56 )
goto V_279;
if ( ! V_52 -> V_242 )
return NULL ;
if ( F_261 ( V_56 ) && ! F_193 ( & V_56 -> V_140 ) )
goto V_280;
if ( F_90 ( V_56 ) && ! F_262 ( V_56 ) ) {
if ( V_56 -> V_3 -> V_141 == 1 && F_193 ( & V_56 -> V_140 )
&& V_56 -> V_258 && F_238 ( V_52 , V_56 ) ) {
V_56 = NULL ;
goto V_281;
} else
goto V_282;
}
if ( ! F_193 ( & V_56 -> V_140 ) )
goto V_281;
V_221 = F_237 ( V_52 , V_56 ) ;
if ( V_221 ) {
if ( ! V_56 -> V_221 )
F_255 ( V_56 , V_221 ) ;
goto V_280;
}
if ( F_263 ( & V_52 -> V_250 ) ) {
V_56 = NULL ;
goto V_281;
}
if ( F_226 ( V_56 ) && F_61 ( V_56 ) &&
( F_91 ( V_56 ) ||
( V_56 -> V_115 - V_114 > V_114 - V_56 -> V_113 ) ) ) {
F_264 ( V_56 ) ;
F_265 ( V_56 ) ;
}
if ( V_56 -> V_258 && F_238 ( V_52 , V_56 ) ) {
V_56 = NULL ;
goto V_281;
}
V_282:
if ( V_52 -> V_257 && V_56 -> V_3 -> V_141 == 1 &&
V_56 -> V_3 -> V_258 &&
! F_240 ( V_52 , & V_56 -> V_3 -> V_174 , true ) ) {
V_56 = NULL ;
goto V_281;
}
V_280:
F_229 ( V_52 , 0 ) ;
V_279:
if ( ! V_221 )
F_259 ( V_52 ) ;
V_56 = F_233 ( V_52 , V_221 ) ;
V_281:
return V_56 ;
}
static int F_266 ( struct V_55 * V_56 )
{
int V_258 = 0 ;
while ( V_56 -> V_229 ) {
F_246 ( V_56 -> V_52 -> V_69 , V_56 -> V_229 ) ;
V_258 ++ ;
}
F_21 ( ! F_211 ( & V_56 -> V_263 ) ) ;
F_222 ( V_56 -> V_52 , V_56 , 0 ) ;
return V_258 ;
}
static int F_267 ( struct V_51 * V_52 )
{
struct V_55 * V_56 ;
int V_258 = 0 ;
F_229 ( V_52 , 0 ) ;
while ( ( V_56 = F_231 ( V_52 ) ) != NULL ) {
F_216 ( V_52 , V_56 ) ;
V_258 += F_266 ( V_56 ) ;
}
F_21 ( V_52 -> V_78 ) ;
F_73 ( V_52 , L_20 , V_258 ) ;
return V_258 ;
}
static inline bool F_268 ( struct V_51 * V_52 ,
struct V_55 * V_56 )
{
if ( F_91 ( V_56 ) )
return true ;
if ( F_127 ( V_114 + V_52 -> V_53 * V_56 -> V_258 ,
V_56 -> V_115 ) )
return true ;
return false ;
}
static bool F_269 ( struct V_51 * V_52 , struct V_55 * V_56 )
{
unsigned int V_283 ;
if ( F_238 ( V_52 , V_56 ) && V_52 -> V_262 [ V_284 ] )
return false ;
if ( V_52 -> V_262 [ V_285 ] && ! F_60 ( V_56 ) )
return false ;
V_283 = F_119 (unsigned int, cfqd->cfq_quantum / 2 , 1 ) ;
if ( F_57 ( V_56 ) )
V_283 = 1 ;
if ( V_56 -> V_258 >= V_283 ) {
bool V_286 = false ;
if ( F_57 ( V_56 ) )
return false ;
if ( F_60 ( V_56 ) && V_52 -> V_233 == 1 )
V_286 = true ;
if ( V_52 -> V_78 > 1 && F_268 ( V_52 , V_56 ) &&
! V_286 )
return false ;
if ( V_52 -> V_78 == 1 || V_286 )
V_283 = - 1 ;
else
V_283 = V_52 -> V_287 ;
}
if ( ! F_60 ( V_56 ) && V_52 -> V_106 ) {
unsigned long V_288 = V_114 - V_52 -> V_289 ;
unsigned int V_290 ;
V_290 = V_288 / V_52 -> V_83 [ 1 ] ;
if ( ! V_290 && ! V_56 -> V_258 )
V_290 = 1 ;
if ( V_290 < V_283 )
V_283 = V_290 ;
}
return V_56 -> V_258 < V_283 ;
}
static bool F_270 ( struct V_51 * V_52 , struct V_55 * V_56 )
{
struct V_117 * V_234 ;
F_21 ( F_193 ( & V_56 -> V_140 ) ) ;
if ( ! F_269 ( V_52 , V_56 ) )
return false ;
V_234 = F_249 ( V_56 ) ;
if ( ! V_234 )
V_234 = V_56 -> V_229 ;
F_246 ( V_52 -> V_69 , V_234 ) ;
if ( ! V_52 -> V_252 ) {
struct V_64 * V_70 = F_271 ( V_234 ) ;
F_272 ( & V_70 -> V_66 . V_68 -> V_291 ) ;
V_52 -> V_252 = V_70 ;
}
return true ;
}
static int F_273 ( struct V_186 * V_48 , int V_292 )
{
struct V_51 * V_52 = V_48 -> V_72 -> V_73 ;
struct V_55 * V_56 ;
if ( ! V_52 -> V_78 )
return 0 ;
if ( F_54 ( V_292 ) )
return F_267 ( V_52 ) ;
V_56 = F_260 ( V_52 ) ;
if ( ! V_56 )
return 0 ;
if ( ! F_270 ( V_52 , V_56 ) )
return 0 ;
V_56 -> V_164 ++ ;
F_218 ( V_56 ) ;
if ( V_52 -> V_78 > 1 && ( ( ! F_60 ( V_56 ) &&
V_56 -> V_164 >= F_253 ( V_52 , V_56 ) ) ||
F_57 ( V_56 ) ) ) {
V_56 -> V_115 = V_114 + 1 ;
F_229 ( V_52 , 0 ) ;
}
F_89 ( V_52 , V_56 , L_21 ) ;
return 1 ;
}
static void F_274 ( struct V_55 * V_56 )
{
struct V_51 * V_52 = V_56 -> V_52 ;
struct V_2 * V_3 ;
F_21 ( V_56 -> V_270 <= 0 ) ;
V_56 -> V_270 -- ;
if ( V_56 -> V_270 )
return;
F_89 ( V_52 , V_56 , L_22 ) ;
F_21 ( F_99 ( & V_56 -> V_140 ) ) ;
F_21 ( V_56 -> V_268 [ V_75 ] + V_56 -> V_268 [ V_269 ] ) ;
V_3 = V_56 -> V_3 ;
if ( F_54 ( V_52 -> V_249 == V_56 ) ) {
F_222 ( V_52 , V_56 , 0 ) ;
F_72 ( V_52 ) ;
}
F_21 ( F_185 ( V_56 ) ) ;
F_275 ( V_293 , V_56 ) ;
F_36 ( V_3 ) ;
}
static void F_276 ( struct V_55 * V_56 )
{
struct V_55 * V_219 , * V_138 ;
V_219 = V_56 -> V_221 ;
while ( V_219 ) {
if ( V_219 == V_56 ) {
F_277 ( 1 , L_23 ) ;
break;
}
V_138 = V_219 -> V_221 ;
F_274 ( V_219 ) ;
V_219 = V_138 ;
}
}
static void F_278 ( struct V_51 * V_52 , struct V_55 * V_56 )
{
if ( F_54 ( V_56 == V_52 -> V_249 ) ) {
F_222 ( V_52 , V_56 , 0 ) ;
F_72 ( V_52 ) ;
}
F_276 ( V_56 ) ;
F_274 ( V_56 ) ;
}
static void F_279 ( struct V_65 * V_66 )
{
struct V_64 * V_70 = F_64 ( V_66 ) ;
V_70 -> V_174 . V_175 = V_114 ;
}
static void F_280 ( struct V_65 * V_66 )
{
struct V_64 * V_70 = F_64 ( V_66 ) ;
struct V_51 * V_52 = F_69 ( V_70 ) ;
if ( V_70 -> V_56 [ V_284 ] ) {
F_278 ( V_52 , V_70 -> V_56 [ V_284 ] ) ;
V_70 -> V_56 [ V_284 ] = NULL ;
}
if ( V_70 -> V_56 [ V_285 ] ) {
F_278 ( V_52 , V_70 -> V_56 [ V_285 ] ) ;
V_70 -> V_56 [ V_285 ] = NULL ;
}
}
static void F_281 ( struct V_55 * V_56 , struct V_64 * V_70 )
{
struct V_237 * V_238 = V_239 ;
int V_294 ;
if ( ! F_282 ( V_56 ) )
return;
V_294 = F_283 ( V_70 -> V_86 ) ;
switch ( V_294 ) {
default:
F_284 ( V_295 L_24 , V_294 ) ;
case V_296 :
V_56 -> V_86 = F_285 ( V_238 ) ;
V_56 -> V_294 = F_286 ( V_238 ) ;
break;
case V_297 :
V_56 -> V_86 = F_287 ( V_70 -> V_86 ) ;
V_56 -> V_294 = V_297 ;
break;
case V_298 :
V_56 -> V_86 = F_287 ( V_70 -> V_86 ) ;
V_56 -> V_294 = V_298 ;
break;
case V_299 :
V_56 -> V_294 = V_299 ;
V_56 -> V_86 = 7 ;
F_265 ( V_56 ) ;
break;
}
V_56 -> V_232 = V_56 -> V_86 ;
F_288 ( V_56 ) ;
}
static void F_289 ( struct V_64 * V_70 , struct V_74 * V_74 )
{
int V_86 = V_70 -> V_66 . V_68 -> V_86 ;
struct V_51 * V_52 = F_69 ( V_70 ) ;
struct V_55 * V_56 ;
if ( F_54 ( ! V_52 ) || F_290 ( V_70 -> V_86 == V_86 ) )
return;
V_56 = V_70 -> V_56 [ V_284 ] ;
if ( V_56 ) {
struct V_55 * V_221 ;
V_221 = F_291 ( V_52 , V_284 , V_70 , V_74 ,
V_300 ) ;
if ( V_221 ) {
V_70 -> V_56 [ V_284 ] = V_221 ;
F_274 ( V_56 ) ;
}
}
V_56 = V_70 -> V_56 [ V_285 ] ;
if ( V_56 )
F_292 ( V_56 ) ;
V_70 -> V_86 = V_86 ;
}
static void F_293 ( struct V_51 * V_52 , struct V_55 * V_56 ,
T_8 V_301 , bool V_71 )
{
F_104 ( & V_56 -> V_133 ) ;
F_104 ( & V_56 -> V_228 ) ;
F_294 ( & V_56 -> V_263 ) ;
V_56 -> V_270 = 0 ;
V_56 -> V_52 = V_52 ;
F_292 ( V_56 ) ;
if ( V_71 ) {
if ( ! F_57 ( V_56 ) )
F_295 ( V_56 ) ;
F_296 ( V_56 ) ;
}
V_56 -> V_301 = V_301 ;
}
static void F_297 ( struct V_64 * V_70 , struct V_74 * V_74 )
{
struct V_51 * V_52 = F_69 ( V_70 ) ;
struct V_55 * V_302 ;
T_1 V_303 ;
F_298 () ;
V_303 = F_299 ( V_74 ) -> V_208 . V_303 ;
F_300 () ;
if ( F_54 ( ! V_52 ) || F_290 ( V_70 -> V_304 == V_303 ) )
return;
V_302 = F_67 ( V_70 , 1 ) ;
if ( V_302 ) {
F_89 ( V_52 , V_302 , L_25 ) ;
F_68 ( V_70 , NULL , 1 ) ;
F_274 ( V_302 ) ;
}
V_70 -> V_304 = V_303 ;
}
static inline void F_297 ( struct V_64 * V_70 , struct V_74 * V_74 ) { }
static struct V_55 *
F_301 ( struct V_51 * V_52 , bool V_71 , struct V_64 * V_70 ,
struct V_74 * V_74 , T_9 V_305 )
{
struct V_32 * V_32 ;
struct V_55 * V_56 , * V_221 = NULL ;
struct V_2 * V_3 ;
V_306:
F_298 () ;
V_32 = F_299 ( V_74 ) ;
V_3 = F_142 ( V_52 , V_32 ) ;
if ( ! V_3 ) {
V_56 = & V_52 -> V_307 ;
goto V_212;
}
V_56 = F_67 ( V_70 , V_71 ) ;
if ( ! V_56 || V_56 == & V_52 -> V_307 ) {
V_56 = NULL ;
if ( V_221 ) {
V_56 = V_221 ;
V_221 = NULL ;
} else if ( V_305 & V_308 ) {
F_300 () ;
F_166 ( V_52 -> V_69 -> V_49 ) ;
V_221 = F_302 ( V_293 ,
V_305 | V_309 ,
V_52 -> V_69 -> V_142 ) ;
F_164 ( V_52 -> V_69 -> V_49 ) ;
if ( V_221 )
goto V_306;
else
return & V_52 -> V_307 ;
} else {
V_56 = F_302 ( V_293 ,
V_305 | V_309 ,
V_52 -> V_69 -> V_142 ) ;
}
if ( V_56 ) {
F_293 ( V_52 , V_56 , V_239 -> V_301 , V_71 ) ;
F_281 ( V_56 , V_70 ) ;
F_145 ( V_56 , V_3 ) ;
F_89 ( V_52 , V_56 , L_26 ) ;
} else
V_56 = & V_52 -> V_307 ;
}
V_212:
if ( V_221 )
F_275 ( V_293 , V_221 ) ;
F_300 () ;
return V_56 ;
}
static struct V_55 * *
F_303 ( struct V_51 * V_52 , int V_294 , int V_86 )
{
switch ( V_294 ) {
case V_297 :
return & V_52 -> V_310 [ 0 ] [ V_86 ] ;
case V_296 :
V_86 = V_311 ;
case V_298 :
return & V_52 -> V_310 [ 1 ] [ V_86 ] ;
case V_299 :
return & V_52 -> V_312 ;
default:
F_304 () ;
}
}
static struct V_55 *
F_291 ( struct V_51 * V_52 , bool V_71 , struct V_64 * V_70 ,
struct V_74 * V_74 , T_9 V_305 )
{
int V_294 = F_283 ( V_70 -> V_86 ) ;
int V_86 = F_287 ( V_70 -> V_86 ) ;
struct V_55 * * V_310 = NULL ;
struct V_55 * V_56 = NULL ;
if ( ! V_71 ) {
if ( ! F_305 ( V_70 -> V_86 ) ) {
struct V_237 * V_238 = V_239 ;
V_86 = F_285 ( V_238 ) ;
V_294 = F_286 ( V_238 ) ;
}
V_310 = F_303 ( V_52 , V_294 , V_86 ) ;
V_56 = * V_310 ;
}
if ( ! V_56 )
V_56 = F_301 ( V_52 , V_71 , V_70 , V_74 , V_305 ) ;
if ( ! V_71 && ! ( * V_310 ) ) {
V_56 -> V_270 ++ ;
* V_310 = V_56 ;
}
V_56 -> V_270 ++ ;
return V_56 ;
}
static void
F_306 ( struct V_313 * V_174 , unsigned long V_314 )
{
unsigned long V_315 = V_114 - V_174 -> V_175 ;
V_315 = F_84 ( V_315 , 2UL * V_314 ) ;
V_174 -> V_260 = ( 7 * V_174 -> V_260 + 256 ) / 8 ;
V_174 -> V_316 = ( 7 * V_174 -> V_316 + 256 * V_315 ) / 8 ;
V_174 -> V_261 = ( V_174 -> V_316 + 128 ) / V_174 -> V_260 ;
}
static void
F_307 ( struct V_51 * V_52 , struct V_55 * V_56 ,
struct V_64 * V_70 )
{
if ( F_60 ( V_56 ) ) {
F_306 ( & V_70 -> V_174 , V_52 -> V_53 ) ;
F_306 ( & V_56 -> V_224 -> V_174 ,
V_52 -> V_53 ) ;
}
#ifdef F_308
F_306 ( & V_56 -> V_3 -> V_174 , V_52 -> V_257 ) ;
#endif
}
static void
F_309 ( struct V_51 * V_52 , struct V_55 * V_56 ,
struct V_117 * V_234 )
{
T_4 V_317 = 0 ;
T_4 V_318 = F_202 ( V_234 ) ;
if ( V_56 -> V_319 ) {
if ( V_56 -> V_319 < F_97 ( V_234 ) )
V_317 = F_97 ( V_234 ) - V_56 -> V_319 ;
else
V_317 = V_56 -> V_319 - F_97 ( V_234 ) ;
}
V_56 -> V_320 <<= 1 ;
if ( F_239 ( V_52 -> V_69 ) )
V_56 -> V_320 |= ( V_318 < V_321 ) ;
else
V_56 -> V_320 |= ( V_317 > V_322 ) ;
}
static void
F_310 ( struct V_51 * V_52 , struct V_55 * V_56 ,
struct V_64 * V_70 )
{
int V_323 , V_324 ;
if ( ! F_60 ( V_56 ) || F_57 ( V_56 ) )
return;
V_324 = V_323 = F_61 ( V_56 ) ;
if ( V_56 -> V_19 [ 0 ] + V_56 -> V_19 [ 1 ] >= 4 )
F_311 ( V_56 ) ;
if ( V_56 -> V_229 && ( V_56 -> V_229 -> V_127 & V_325 ) )
V_324 = 0 ;
else if ( ! F_242 ( & V_70 -> V_66 . V_68 -> V_259 ) ||
! V_52 -> V_53 ||
( ! F_312 ( V_56 ) && F_226 ( V_56 ) ) )
V_324 = 0 ;
else if ( F_243 ( V_70 -> V_174 . V_260 ) ) {
if ( V_70 -> V_174 . V_261 > V_52 -> V_53 )
V_324 = 0 ;
else
V_324 = 1 ;
}
if ( V_323 != V_324 ) {
F_89 ( V_52 , V_56 , L_27 , V_324 ) ;
if ( V_324 )
F_295 ( V_56 ) ;
else
F_265 ( V_56 ) ;
}
}
static bool
F_313 ( struct V_51 * V_52 , struct V_55 * V_221 ,
struct V_117 * V_234 )
{
struct V_55 * V_56 ;
V_56 = V_52 -> V_249 ;
if ( ! V_56 )
return false ;
if ( F_57 ( V_221 ) )
return false ;
if ( F_57 ( V_56 ) )
return true ;
if ( F_58 ( V_56 ) && ! F_58 ( V_221 ) )
return false ;
if ( F_96 ( V_234 ) && ! F_60 ( V_56 ) )
return true ;
if ( V_221 -> V_3 != V_56 -> V_3 )
return false ;
if ( F_90 ( V_56 ) )
return true ;
if ( V_52 -> V_167 == V_60 &&
F_59 ( V_221 ) == V_60 &&
V_221 -> V_224 -> V_63 == 2 &&
F_193 ( & V_56 -> V_140 ) )
return true ;
if ( ( V_234 -> V_127 & V_128 ) && ! V_56 -> V_243 )
return true ;
if ( F_58 ( V_221 ) && ! F_58 ( V_56 ) )
return true ;
if ( F_193 ( & V_56 -> V_140 ) && ! F_238 ( V_52 , V_56 ) )
return true ;
if ( ! V_52 -> V_252 || ! F_223 ( V_56 ) )
return false ;
if ( F_235 ( V_52 , V_56 , V_234 ) )
return true ;
return false ;
}
static void F_314 ( struct V_51 * V_52 , struct V_55 * V_56 )
{
enum V_6 V_326 = F_59 ( V_52 -> V_249 ) ;
F_89 ( V_52 , V_56 , L_28 ) ;
F_229 ( V_52 , 1 ) ;
if ( V_326 != F_59 ( V_56 ) )
V_56 -> V_3 -> V_158 = 0 ;
F_21 ( ! F_185 ( V_56 ) ) ;
F_181 ( V_52 , V_56 , 1 ) ;
V_56 -> V_115 = 0 ;
F_221 ( V_56 ) ;
}
static void
F_315 ( struct V_51 * V_52 , struct V_55 * V_56 ,
struct V_117 * V_234 )
{
struct V_64 * V_70 = F_271 ( V_234 ) ;
V_52 -> V_242 ++ ;
if ( V_234 -> V_127 & V_128 )
V_56 -> V_243 ++ ;
F_307 ( V_52 , V_56 , V_70 ) ;
F_309 ( V_52 , V_56 , V_234 ) ;
F_310 ( V_52 , V_56 , V_70 ) ;
V_56 -> V_319 = F_97 ( V_234 ) + F_202 ( V_234 ) ;
if ( V_56 == V_52 -> V_249 ) {
if ( F_223 ( V_56 ) ) {
if ( F_248 ( V_234 ) > V_327 ||
V_52 -> V_78 > 1 ) {
F_214 ( V_52 , V_56 ) ;
F_217 ( V_56 ) ;
F_316 ( V_52 -> V_69 ) ;
} else {
F_17 ( V_56 -> V_3 ) ;
F_317 ( V_56 ) ;
}
}
} else if ( F_313 ( V_52 , V_56 , V_234 ) ) {
F_314 ( V_52 , V_56 ) ;
F_316 ( V_52 -> V_69 ) ;
}
}
static void F_318 ( struct V_186 * V_48 , struct V_117 * V_234 )
{
struct V_51 * V_52 = V_48 -> V_72 -> V_73 ;
struct V_55 * V_56 = F_191 ( V_234 ) ;
F_89 ( V_52 , V_56 , L_29 ) ;
F_281 ( V_56 , F_271 ( V_234 ) ) ;
V_234 -> V_248 = V_114 + V_52 -> V_328 [ F_96 ( V_234 ) ] ;
F_319 ( & V_234 -> V_241 , & V_56 -> V_263 ) ;
F_194 ( V_234 ) ;
F_38 ( F_197 ( V_234 ) , V_52 -> V_236 ,
V_234 -> V_127 ) ;
F_315 ( V_52 , V_56 , V_234 ) ;
}
static void F_320 ( struct V_51 * V_52 )
{
struct V_55 * V_56 = V_52 -> V_249 ;
if ( V_52 -> V_240 > V_52 -> V_329 )
V_52 -> V_329 = V_52 -> V_240 ;
if ( V_52 -> V_54 == 1 )
return;
if ( V_52 -> V_242 <= V_330 &&
V_52 -> V_240 <= V_330 )
return;
if ( V_56 && F_61 ( V_56 ) &&
V_56 -> V_258 + V_56 -> V_19 [ 0 ] + V_56 -> V_19 [ 1 ] <
V_330 && V_52 -> V_240 < V_330 )
return;
if ( V_52 -> V_331 ++ < 50 )
return;
if ( V_52 -> V_329 >= V_330 )
V_52 -> V_54 = 1 ;
else
V_52 -> V_54 = 0 ;
}
static bool F_321 ( struct V_51 * V_52 , struct V_55 * V_56 )
{
struct V_64 * V_70 = V_52 -> V_252 ;
if ( ! F_193 ( & V_56 -> V_140 ) )
return false ;
if ( V_56 -> V_3 -> V_141 > 1 )
return false ;
if ( F_240 ( V_52 , & V_56 -> V_3 -> V_174 , true ) )
return false ;
if ( F_90 ( V_56 ) )
return true ;
if ( V_70 && F_243 ( V_70 -> V_174 . V_260 )
&& ( V_56 -> V_115 - V_114 < V_70 -> V_174 . V_261 ) )
return true ;
if ( V_56 -> V_115 - V_114 == 1 )
return true ;
return false ;
}
static void F_322 ( struct V_186 * V_48 , struct V_117 * V_234 )
{
struct V_55 * V_56 = F_191 ( V_234 ) ;
struct V_51 * V_52 = V_56 -> V_52 ;
const int V_80 = F_96 ( V_234 ) ;
unsigned long V_12 ;
V_12 = V_114 ;
F_89 ( V_52 , V_56 , L_30 ,
! ! ( V_234 -> V_127 & V_325 ) ) ;
F_320 ( V_52 ) ;
F_76 ( ! V_52 -> V_240 ) ;
F_76 ( ! V_56 -> V_258 ) ;
V_52 -> V_240 -- ;
V_56 -> V_258 -- ;
( F_197 ( V_234 ) ) -> V_258 -- ;
F_45 ( V_56 -> V_3 , F_323 ( V_234 ) ,
F_324 ( V_234 ) , V_234 -> V_127 ) ;
V_52 -> V_262 [ F_60 ( V_56 ) ] -- ;
if ( V_80 ) {
struct V_1 * V_94 ;
F_271 ( V_234 ) -> V_174 . V_175 = V_12 ;
if ( F_185 ( V_56 ) )
V_94 = V_56 -> V_224 ;
else
V_94 = F_1 ( V_56 -> V_3 , F_56 ( V_56 ) ,
F_59 ( V_56 ) ) ;
V_94 -> V_174 . V_175 = V_12 ;
if ( ! F_127 ( V_234 -> V_42 + V_52 -> V_328 [ 1 ] , V_12 ) )
V_52 -> V_289 = V_12 ;
}
#ifdef F_308
V_56 -> V_3 -> V_174 . V_175 = V_12 ;
#endif
if ( V_52 -> V_249 == V_56 ) {
const bool V_332 = F_193 ( & V_56 -> V_140 ) ;
if ( F_91 ( V_56 ) ) {
F_88 ( V_52 , V_56 ) ;
F_325 ( V_56 ) ;
}
if ( F_321 ( V_52 , V_56 ) ) {
unsigned long V_333 = V_52 -> V_53 ;
if ( ! V_52 -> V_53 )
V_333 = V_52 -> V_257 ;
V_56 -> V_115 = V_114 + V_333 ;
F_326 ( V_56 ) ;
F_89 ( V_52 , V_56 , L_31 ) ;
}
if ( F_90 ( V_56 ) || F_57 ( V_56 ) )
F_229 ( V_52 , 1 ) ;
else if ( V_80 && V_332 &&
! F_237 ( V_52 , V_56 ) ) {
F_241 ( V_52 ) ;
}
}
if ( ! V_52 -> V_240 )
F_72 ( V_52 ) ;
}
static inline int F_327 ( struct V_55 * V_56 )
{
if ( F_223 ( V_56 ) && ! F_328 ( V_56 ) ) {
F_329 ( V_56 ) ;
return V_334 ;
}
return V_335 ;
}
static int F_330 ( struct V_186 * V_48 , int V_35 )
{
struct V_51 * V_52 = V_48 -> V_72 -> V_73 ;
struct V_237 * V_238 = V_239 ;
struct V_64 * V_70 ;
struct V_55 * V_56 ;
V_70 = F_65 ( V_52 , V_238 -> V_67 ) ;
if ( ! V_70 )
return V_335 ;
V_56 = F_67 ( V_70 , F_331 ( V_35 ) ) ;
if ( V_56 ) {
F_281 ( V_56 , V_70 ) ;
return F_327 ( V_56 ) ;
}
return V_335 ;
}
static void F_332 ( struct V_117 * V_234 )
{
struct V_55 * V_56 = F_191 ( V_234 ) ;
if ( V_56 ) {
const int V_35 = F_333 ( V_234 ) ;
F_21 ( ! V_56 -> V_268 [ V_35 ] ) ;
V_56 -> V_268 [ V_35 ] -- ;
F_36 ( F_197 ( V_234 ) ) ;
V_234 -> V_336 . V_337 [ 0 ] = NULL ;
V_234 -> V_336 . V_337 [ 1 ] = NULL ;
F_274 ( V_56 ) ;
}
}
static struct V_55 *
F_334 ( struct V_51 * V_52 , struct V_64 * V_70 ,
struct V_55 * V_56 )
{
F_89 ( V_52 , V_56 , L_32 , V_56 -> V_221 ) ;
F_68 ( V_70 , V_56 -> V_221 , 1 ) ;
F_335 ( V_56 -> V_221 ) ;
F_274 ( V_56 ) ;
return F_67 ( V_70 , 1 ) ;
}
static struct V_55 *
F_336 ( struct V_64 * V_70 , struct V_55 * V_56 )
{
if ( F_254 ( V_56 ) == 1 ) {
V_56 -> V_301 = V_239 -> V_301 ;
F_337 ( V_56 ) ;
F_338 ( V_56 ) ;
return V_56 ;
}
F_68 ( V_70 , NULL , 1 ) ;
F_276 ( V_56 ) ;
F_274 ( V_56 ) ;
return NULL ;
}
static int
F_339 ( struct V_186 * V_48 , struct V_117 * V_234 , struct V_74 * V_74 ,
T_9 V_305 )
{
struct V_51 * V_52 = V_48 -> V_72 -> V_73 ;
struct V_64 * V_70 = F_64 ( V_234 -> V_336 . V_66 ) ;
const int V_35 = F_333 ( V_234 ) ;
const bool V_71 = F_96 ( V_234 ) ;
struct V_55 * V_56 ;
F_340 ( V_305 & V_308 ) ;
F_164 ( V_48 -> V_49 ) ;
F_289 ( V_70 , V_74 ) ;
F_297 ( V_70 , V_74 ) ;
V_279:
V_56 = F_67 ( V_70 , V_71 ) ;
if ( ! V_56 || V_56 == & V_52 -> V_307 ) {
V_56 = F_291 ( V_52 , V_71 , V_70 , V_74 , V_305 ) ;
F_68 ( V_70 , V_56 , V_71 ) ;
} else {
if ( F_225 ( V_56 ) && F_341 ( V_56 ) ) {
F_89 ( V_52 , V_56 , L_33 ) ;
V_56 = F_336 ( V_70 , V_56 ) ;
if ( ! V_56 )
goto V_279;
}
if ( V_56 -> V_221 )
V_56 = F_334 ( V_52 , V_70 , V_56 ) ;
}
V_56 -> V_268 [ V_35 ] ++ ;
V_56 -> V_270 ++ ;
F_34 ( V_56 -> V_3 ) ;
V_234 -> V_336 . V_337 [ 0 ] = V_56 ;
V_234 -> V_336 . V_337 [ 1 ] = V_56 -> V_3 ;
F_166 ( V_48 -> V_49 ) ;
return 0 ;
}
static void F_342 ( struct V_338 * V_339 )
{
struct V_51 * V_52 =
F_25 ( V_339 , struct V_51 , V_79 ) ;
struct V_186 * V_48 = V_52 -> V_69 ;
F_164 ( V_48 -> V_49 ) ;
F_316 ( V_52 -> V_69 ) ;
F_166 ( V_48 -> V_49 ) ;
}
static void F_343 ( unsigned long V_340 )
{
struct V_51 * V_52 = (struct V_51 * ) V_340 ;
struct V_55 * V_56 ;
unsigned long V_341 ;
int V_251 = 1 ;
F_73 ( V_52 , L_34 ) ;
F_344 ( V_52 -> V_69 -> V_49 , V_341 ) ;
V_56 = V_52 -> V_249 ;
if ( V_56 ) {
V_251 = 0 ;
if ( F_262 ( V_56 ) )
goto V_342;
if ( F_90 ( V_56 ) )
goto V_280;
if ( ! V_52 -> V_78 )
goto V_343;
if ( ! F_193 ( & V_56 -> V_140 ) )
goto V_342;
F_264 ( V_56 ) ;
}
V_280:
F_229 ( V_52 , V_251 ) ;
V_342:
F_72 ( V_52 ) ;
V_343:
F_345 ( V_52 -> V_69 -> V_49 , V_341 ) ;
}
static void F_346 ( struct V_51 * V_52 )
{
F_347 ( & V_52 -> V_250 ) ;
F_348 ( & V_52 -> V_79 ) ;
}
static void F_349 ( struct V_51 * V_52 )
{
int V_171 ;
for ( V_171 = 0 ; V_171 < V_84 ; V_171 ++ ) {
if ( V_52 -> V_310 [ 0 ] [ V_171 ] )
F_274 ( V_52 -> V_310 [ 0 ] [ V_171 ] ) ;
if ( V_52 -> V_310 [ 1 ] [ V_171 ] )
F_274 ( V_52 -> V_310 [ 1 ] [ V_171 ] ) ;
}
if ( V_52 -> V_312 )
F_274 ( V_52 -> V_312 ) ;
}
static void F_350 ( struct V_344 * V_345 )
{
struct V_51 * V_52 = V_345 -> V_73 ;
struct V_186 * V_48 = V_52 -> V_69 ;
F_346 ( V_52 ) ;
F_164 ( V_48 -> V_49 ) ;
if ( V_52 -> V_249 )
F_222 ( V_52 , V_52 -> V_249 , 0 ) ;
F_349 ( V_52 ) ;
F_166 ( V_48 -> V_49 ) ;
F_346 ( V_52 ) ;
#ifdef F_308
F_351 ( V_48 , & V_31 ) ;
#else
F_352 ( V_52 -> V_187 ) ;
#endif
F_352 ( V_52 ) ;
}
static int F_353 ( struct V_186 * V_48 , struct V_346 * V_345 )
{
struct V_51 * V_52 ;
struct V_29 * V_30 V_347 ;
int V_171 , V_202 ;
struct V_344 * V_348 ;
V_348 = F_354 ( V_48 , V_345 ) ;
if ( ! V_348 )
return - V_349 ;
V_52 = F_355 ( sizeof( * V_52 ) , V_350 , V_48 -> V_142 ) ;
if ( ! V_52 ) {
F_356 ( & V_348 -> V_351 ) ;
return - V_349 ;
}
V_348 -> V_73 = V_52 ;
V_52 -> V_69 = V_48 ;
F_164 ( V_48 -> V_49 ) ;
V_48 -> V_72 = V_348 ;
F_166 ( V_48 -> V_49 ) ;
V_52 -> V_156 = V_173 ;
#ifdef F_308
V_202 = F_357 ( V_48 , & V_31 ) ;
if ( V_202 )
goto V_352;
V_52 -> V_187 = F_29 ( V_48 -> V_353 ) ;
#else
V_202 = - V_349 ;
V_52 -> V_187 = F_355 ( sizeof( * V_52 -> V_187 ) ,
V_350 , V_52 -> V_69 -> V_142 ) ;
if ( ! V_52 -> V_187 )
goto V_352;
F_129 ( V_52 -> V_187 ) ;
#endif
V_52 -> V_187 -> V_148 = 2 * V_179 ;
V_52 -> V_187 -> V_150 = 2 * V_179 ;
for ( V_171 = 0 ; V_171 < V_354 ; V_171 ++ )
V_52 -> V_231 [ V_171 ] = V_355 ;
F_293 ( V_52 , & V_52 -> V_307 , 1 , 0 ) ;
V_52 -> V_307 . V_270 ++ ;
F_164 ( V_48 -> V_49 ) ;
F_145 ( & V_52 -> V_307 , V_52 -> V_187 ) ;
F_36 ( V_52 -> V_187 ) ;
F_166 ( V_48 -> V_49 ) ;
F_358 ( & V_52 -> V_250 ) ;
V_52 -> V_250 . V_356 = F_343 ;
V_52 -> V_250 . V_340 = ( unsigned long ) V_52 ;
F_359 ( & V_52 -> V_79 , F_342 ) ;
V_52 -> V_287 = V_287 ;
V_52 -> V_328 [ 0 ] = V_328 [ 0 ] ;
V_52 -> V_328 [ 1 ] = V_328 [ 1 ] ;
V_52 -> V_129 = V_129 ;
V_52 -> V_130 = V_130 ;
V_52 -> V_83 [ 0 ] = V_357 ;
V_52 -> V_83 [ 1 ] = V_358 ;
V_52 -> V_104 = V_104 ;
V_52 -> V_265 = V_265 ;
V_52 -> V_53 = V_53 ;
V_52 -> V_257 = V_257 ;
V_52 -> V_106 = 1 ;
V_52 -> V_54 = - 1 ;
V_52 -> V_289 = V_114 - V_223 ;
return 0 ;
V_352:
F_352 ( V_52 ) ;
F_356 ( & V_348 -> V_351 ) ;
return V_202 ;
}
static void F_360 ( struct V_186 * V_48 )
{
struct V_344 * V_345 = V_48 -> V_72 ;
struct V_51 * V_52 = V_345 -> V_73 ;
if ( F_239 ( V_48 ) )
V_52 -> V_53 = 0 ;
}
static T_5
F_361 ( unsigned int V_359 , char * V_360 )
{
return sprintf ( V_360 , L_6 , V_359 ) ;
}
static T_5
F_362 ( unsigned int * V_359 , const char * V_360 , T_6 V_63 )
{
char * V_218 = ( char * ) V_360 ;
* V_359 = F_363 ( V_218 , & V_218 , 10 ) ;
return V_63 ;
}
static int T_10 F_364 ( void )
{
int V_202 ;
if ( ! V_357 )
V_357 = 1 ;
if ( ! V_53 )
V_53 = 1 ;
#ifdef F_308
if ( ! V_257 )
V_257 = 1 ;
V_202 = F_365 ( & V_31 ) ;
if ( V_202 )
return V_202 ;
#else
V_257 = 0 ;
#endif
V_202 = - V_349 ;
V_293 = F_366 ( V_55 , 0 ) ;
if ( ! V_293 )
goto V_361;
V_202 = F_367 ( & V_362 ) ;
if ( V_202 )
goto V_363;
return 0 ;
V_363:
F_368 ( V_293 ) ;
V_361:
#ifdef F_308
F_369 ( & V_31 ) ;
#endif
return V_202 ;
}
static void T_11 F_370 ( void )
{
#ifdef F_308
F_369 ( & V_31 ) ;
#endif
F_371 ( & V_362 ) ;
F_368 ( V_293 ) ;
}
