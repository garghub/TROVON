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
return V_28 ? F_25 ( V_28 , struct V_26 , V_28 ) : NULL ;
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
T_1 V_38 , T_1 V_39 , int V_35 )
{
struct V_10 * V_11 = & V_3 -> V_11 ;
unsigned long long V_12 = F_4 () ;
if ( F_5 ( V_12 , V_39 ) )
F_39 ( & V_11 -> V_40 , V_35 , V_12 - V_39 ) ;
if ( F_5 ( V_39 , V_38 ) )
F_39 ( & V_11 -> V_41 , V_35 ,
V_39 - V_38 ) ;
}
static void F_45 ( struct V_10 * V_11 )
{
F_46 ( & V_11 -> V_37 ) ;
F_46 ( & V_11 -> V_40 ) ;
F_46 ( & V_11 -> V_41 ) ;
F_47 ( & V_11 -> time ) ;
#ifdef F_41
F_47 ( & V_11 -> V_36 ) ;
F_47 ( & V_11 -> V_22 ) ;
F_47 ( & V_11 -> V_23 ) ;
F_47 ( & V_11 -> V_18 ) ;
F_47 ( & V_11 -> V_14 ) ;
F_47 ( & V_11 -> V_21 ) ;
F_47 ( & V_11 -> V_17 ) ;
#endif
}
static void F_48 ( struct V_10 * V_42 , struct V_10 * V_43 )
{
F_49 ( & V_42 -> V_37 , & V_43 -> V_37 ) ;
F_49 ( & V_42 -> V_40 , & V_43 -> V_40 ) ;
F_49 ( & V_42 -> V_41 , & V_43 -> V_41 ) ;
F_50 ( & V_43 -> time , & V_43 -> time ) ;
#ifdef F_41
F_50 ( & V_42 -> V_36 , & V_43 -> V_36 ) ;
F_50 ( & V_42 -> V_22 , & V_43 -> V_22 ) ;
F_50 ( & V_42 -> V_23 , & V_43 -> V_23 ) ;
F_50 ( & V_42 -> V_18 , & V_43 -> V_18 ) ;
F_50 ( & V_42 -> V_14 , & V_43 -> V_14 ) ;
F_50 ( & V_42 -> V_21 , & V_43 -> V_21 ) ;
F_50 ( & V_42 -> V_17 , & V_43 -> V_17 ) ;
#endif
}
static void F_51 ( struct V_2 * V_3 )
{
struct V_2 * V_34 = F_33 ( V_3 ) ;
F_52 ( F_27 ( V_3 ) -> V_44 -> V_45 ) ;
if ( F_53 ( ! V_34 ) )
return;
F_48 ( & V_34 -> V_11 , & V_3 -> V_11 ) ;
F_45 ( & V_3 -> V_11 ) ;
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
T_1 V_38 , T_1 V_39 , int V_35 ) { }
static inline bool F_54 ( struct V_46 * V_47 )
{
if ( ! V_47 -> V_48 && V_47 -> V_49 )
return true ;
else
return false ;
}
static inline enum V_4 F_55 ( struct V_50 * V_51 )
{
if ( F_56 ( V_51 ) )
return V_7 ;
if ( F_57 ( V_51 ) )
return V_52 ;
return V_53 ;
}
static enum V_6 F_58 ( struct V_50 * V_51 )
{
if ( ! F_59 ( V_51 ) )
return V_54 ;
if ( ! F_60 ( V_51 ) )
return V_55 ;
return V_56 ;
}
static inline int F_61 ( enum V_4 V_57 ,
struct V_46 * V_47 ,
struct V_2 * V_3 )
{
if ( V_57 == V_7 )
return V_3 -> V_8 . V_58 ;
return V_3 -> V_9 [ V_57 ] [ V_54 ] . V_58 +
V_3 -> V_9 [ V_57 ] [ V_55 ] . V_58 +
V_3 -> V_9 [ V_57 ] [ V_56 ] . V_58 ;
}
static inline int F_62 ( struct V_46 * V_47 ,
struct V_2 * V_3 )
{
return V_3 -> V_9 [ V_52 ] [ V_54 ] . V_58 +
V_3 -> V_9 [ V_53 ] [ V_54 ] . V_58 ;
}
static inline struct V_59 * F_63 ( struct V_60 * V_61 )
{
return F_25 ( V_61 , struct V_59 , V_61 ) ;
}
static inline struct V_59 * F_64 ( struct V_46 * V_47 ,
struct V_62 * V_63 )
{
if ( V_63 )
return F_63 ( F_65 ( V_63 , V_47 -> V_64 ) ) ;
return NULL ;
}
static inline struct V_50 * F_66 ( struct V_59 * V_65 , bool V_66 )
{
return V_65 -> V_51 [ V_66 ] ;
}
static inline void F_67 ( struct V_59 * V_65 , struct V_50 * V_51 ,
bool V_66 )
{
V_65 -> V_51 [ V_66 ] = V_51 ;
}
static inline struct V_46 * F_68 ( struct V_59 * V_65 )
{
return V_65 -> V_61 . V_44 -> V_67 -> V_68 ;
}
static inline bool F_69 ( struct V_69 * V_69 )
{
return F_70 ( V_69 ) == V_70 || ( V_69 -> V_71 & V_72 ) ;
}
static inline void F_71 ( struct V_46 * V_47 )
{
if ( V_47 -> V_73 ) {
F_72 ( V_47 , L_1 ) ;
F_73 ( & V_47 -> V_74 ) ;
}
}
static inline int F_74 ( struct V_46 * V_47 , bool V_75 ,
unsigned short V_76 )
{
const int V_77 = V_47 -> V_78 [ V_75 ] ;
F_75 ( V_76 >= V_79 ) ;
return V_77 + ( V_77 / V_80 * ( 4 - V_76 ) ) ;
}
static inline int
F_76 ( struct V_46 * V_47 , struct V_50 * V_51 )
{
return F_74 ( V_47 , F_59 ( V_51 ) , V_51 -> V_81 ) ;
}
static inline T_2 F_77 ( unsigned long V_82 ,
unsigned int V_83 )
{
T_2 V_84 = V_82 << V_85 ;
V_84 <<= V_85 ;
F_78 ( V_84 , V_83 ) ;
return V_84 ;
}
static inline T_2 F_79 ( T_2 V_86 , T_2 V_87 )
{
T_3 V_88 = ( T_3 ) ( V_87 - V_86 ) ;
if ( V_88 > 0 )
V_86 = V_87 ;
return V_86 ;
}
static inline T_2 V_86 ( T_2 V_86 , T_2 V_87 )
{
T_3 V_88 = ( T_3 ) ( V_87 - V_86 ) ;
if ( V_88 < 0 )
V_86 = V_87 ;
return V_86 ;
}
static void F_80 ( struct V_1 * V_89 )
{
struct V_2 * V_3 ;
if ( V_89 -> V_90 ) {
V_3 = F_81 ( V_89 -> V_90 ) ;
V_89 -> V_86 = F_79 ( V_89 -> V_86 ,
V_3 -> V_87 ) ;
}
}
static inline unsigned F_82 ( struct V_46 * V_47 ,
struct V_2 * V_3 , bool V_91 )
{
unsigned V_92 , V_93 ;
unsigned V_94 = V_95 - 1 ;
unsigned V_96 = V_95 / 2 ;
unsigned V_97 = F_61 ( V_91 , V_47 , V_3 ) ;
V_92 = F_83 ( V_3 -> V_98 [ V_91 ] , V_97 ) ;
V_93 = F_84 ( V_3 -> V_98 [ V_91 ] , V_97 ) ;
V_3 -> V_98 [ V_91 ] = ( V_94 * V_93 + V_92 + V_96 ) /
V_95 ;
return V_3 -> V_98 [ V_91 ] ;
}
static inline unsigned
F_85 ( struct V_46 * V_47 , struct V_2 * V_3 )
{
return V_47 -> V_99 * V_3 -> V_83 >> V_85 ;
}
static inline unsigned
F_86 ( struct V_46 * V_47 , struct V_50 * V_51 )
{
unsigned V_100 = F_76 ( V_47 , V_51 ) ;
if ( V_47 -> V_101 ) {
unsigned V_102 = F_82 ( V_47 , V_51 -> V_3 ,
F_57 ( V_51 ) ) ;
unsigned V_103 = V_47 -> V_78 [ 1 ] ;
unsigned V_104 = V_103 * V_102 ;
unsigned V_105 = F_85 ( V_47 , V_51 -> V_3 ) ;
if ( V_104 > V_105 ) {
unsigned V_106 = 2 * V_47 -> V_48 ;
unsigned V_107 =
F_83 ( V_100 , V_106 * V_100 / V_103 ) ;
V_100 = F_84 ( V_100 * V_105 / V_104 ,
V_107 ) ;
}
}
return V_100 ;
}
static inline void
F_87 ( struct V_46 * V_47 , struct V_50 * V_51 )
{
unsigned V_100 = F_86 ( V_47 , V_51 ) ;
V_51 -> V_108 = V_109 ;
V_51 -> V_110 = V_109 + V_100 ;
V_51 -> V_111 = V_100 ;
F_88 ( V_47 , V_51 , L_2 , V_51 -> V_110 - V_109 ) ;
}
static inline bool F_89 ( struct V_50 * V_51 )
{
if ( F_90 ( V_51 ) )
return false ;
if ( F_91 ( V_109 , V_51 -> V_110 ) )
return false ;
return true ;
}
static struct V_112 *
F_92 ( struct V_46 * V_47 , struct V_112 * V_113 , struct V_112 * V_114 , T_4 V_115 )
{
T_4 V_116 , V_117 , V_118 = 0 , V_119 = 0 ;
unsigned long V_120 ;
#define F_93 0x01
#define F_94 0x02
unsigned V_121 = 0 ;
if ( V_113 == NULL || V_113 == V_114 )
return V_114 ;
if ( V_114 == NULL )
return V_113 ;
if ( F_95 ( V_113 ) != F_95 ( V_114 ) )
return F_95 ( V_113 ) ? V_113 : V_114 ;
if ( ( V_113 -> V_122 ^ V_114 -> V_122 ) & V_123 )
return V_113 -> V_122 & V_123 ? V_113 : V_114 ;
V_116 = F_96 ( V_113 ) ;
V_117 = F_96 ( V_114 ) ;
V_120 = V_47 -> V_124 * 2 ;
if ( V_116 >= V_115 )
V_118 = V_116 - V_115 ;
else if ( V_116 + V_120 >= V_115 )
V_118 = ( V_115 - V_116 ) * V_47 -> V_125 ;
else
V_121 |= F_93 ;
if ( V_117 >= V_115 )
V_119 = V_117 - V_115 ;
else if ( V_117 + V_120 >= V_115 )
V_119 = ( V_115 - V_117 ) * V_47 -> V_125 ;
else
V_121 |= F_94 ;
switch ( V_121 ) {
case 0 :
if ( V_118 < V_119 )
return V_113 ;
else if ( V_119 < V_118 )
return V_114 ;
else {
if ( V_116 >= V_117 )
return V_113 ;
else
return V_114 ;
}
case F_94 :
return V_113 ;
case F_93 :
return V_114 ;
case ( F_93 | F_94 ) :
default:
if ( V_116 <= V_117 )
return V_113 ;
else
return V_114 ;
}
}
static struct V_50 * F_97 ( struct V_1 * V_126 )
{
if ( ! V_126 -> V_58 )
return NULL ;
if ( ! V_126 -> V_90 )
V_126 -> V_90 = F_98 ( & V_126 -> V_127 ) ;
if ( V_126 -> V_90 )
return F_99 ( V_126 -> V_90 , struct V_50 , V_128 ) ;
return NULL ;
}
static struct V_2 * F_100 ( struct V_1 * V_126 )
{
if ( ! V_126 -> V_90 )
V_126 -> V_90 = F_98 ( & V_126 -> V_127 ) ;
if ( V_126 -> V_90 )
return F_81 ( V_126 -> V_90 ) ;
return NULL ;
}
static void F_101 ( struct V_128 * V_129 , struct V_130 * V_126 )
{
F_102 ( V_129 , V_126 ) ;
F_103 ( V_129 ) ;
}
static void F_104 ( struct V_128 * V_129 , struct V_1 * V_126 )
{
if ( V_126 -> V_90 == V_129 )
V_126 -> V_90 = NULL ;
F_101 ( V_129 , & V_126 -> V_127 ) ;
-- V_126 -> V_58 ;
}
static struct V_112 *
F_105 ( struct V_46 * V_47 , struct V_50 * V_51 ,
struct V_112 * V_115 )
{
struct V_128 * V_131 = F_106 ( & V_115 -> V_128 ) ;
struct V_128 * V_132 = F_107 ( & V_115 -> V_128 ) ;
struct V_112 * V_133 = NULL , * V_134 = NULL ;
F_21 ( F_108 ( & V_115 -> V_128 ) ) ;
if ( V_132 )
V_134 = F_109 ( V_132 ) ;
if ( V_131 )
V_133 = F_109 ( V_131 ) ;
else {
V_131 = F_98 ( & V_51 -> V_135 ) ;
if ( V_131 && V_131 != & V_115 -> V_128 )
V_133 = F_109 ( V_131 ) ;
}
return F_92 ( V_47 , V_133 , V_134 , F_96 ( V_115 ) ) ;
}
static unsigned long F_110 ( struct V_46 * V_47 ,
struct V_50 * V_51 )
{
return ( V_51 -> V_3 -> V_136 - 1 ) * ( F_74 ( V_47 , 1 , 0 ) -
F_74 ( V_47 , F_59 ( V_51 ) , V_51 -> V_81 ) ) ;
}
static inline T_3
F_111 ( struct V_1 * V_89 , struct V_2 * V_3 )
{
return V_3 -> V_87 - V_89 -> V_86 ;
}
static void
F_112 ( struct V_1 * V_89 , struct V_2 * V_3 )
{
struct V_128 * * V_137 = & V_89 -> V_127 . V_128 ;
struct V_128 * V_34 = NULL ;
struct V_2 * V_138 ;
T_3 V_139 = F_111 ( V_89 , V_3 ) ;
int V_90 = 1 ;
while ( * V_137 != NULL ) {
V_34 = * V_137 ;
V_138 = F_81 ( V_34 ) ;
if ( V_139 < F_111 ( V_89 , V_138 ) )
V_137 = & V_34 -> V_140 ;
else {
V_137 = & V_34 -> V_141 ;
V_90 = 0 ;
}
}
if ( V_90 )
V_89 -> V_90 = & V_3 -> V_128 ;
F_113 ( & V_3 -> V_128 , V_34 , V_137 ) ;
F_114 ( & V_3 -> V_128 , & V_89 -> V_127 ) ;
}
static void
F_115 ( struct V_2 * V_3 )
{
if ( V_3 -> V_142 ) {
V_3 -> V_143 = V_3 -> V_142 ;
V_3 -> V_142 = 0 ;
}
}
static void
F_116 ( struct V_2 * V_3 )
{
F_21 ( ! F_108 ( & V_3 -> V_128 ) ) ;
if ( V_3 -> V_144 ) {
V_3 -> V_145 = V_3 -> V_144 ;
V_3 -> V_144 = 0 ;
}
}
static void
F_117 ( struct V_1 * V_89 , struct V_2 * V_3 )
{
unsigned int V_146 = 1 << V_85 ;
struct V_2 * V_147 = V_3 ;
struct V_2 * V_34 ;
bool V_148 ;
F_21 ( ! F_108 ( & V_3 -> V_128 ) ) ;
F_116 ( V_3 ) ;
F_112 ( V_89 , V_3 ) ;
V_148 = ! V_147 -> V_149 ++ ;
V_147 -> V_150 += V_147 -> V_145 ;
V_146 = V_146 * V_147 -> V_145 / V_147 -> V_150 ;
while ( ( V_34 = F_33 ( V_147 ) ) ) {
if ( V_148 ) {
F_115 ( V_147 ) ;
V_148 = ! V_34 -> V_149 ++ ;
V_34 -> V_150 += V_147 -> V_143 ;
}
V_146 = V_146 * V_147 -> V_143 / V_34 -> V_150 ;
V_147 = V_34 ;
}
V_3 -> V_83 = F_118 ( unsigned , V_146 , 1 ) ;
}
static void
F_119 ( struct V_46 * V_47 , struct V_2 * V_3 )
{
struct V_1 * V_89 = & V_47 -> V_151 ;
struct V_2 * V_138 ;
struct V_128 * V_129 ;
V_3 -> V_136 ++ ;
if ( ! F_108 ( & V_3 -> V_128 ) )
return;
V_129 = F_120 ( & V_89 -> V_127 ) ;
if ( V_129 ) {
V_138 = F_81 ( V_129 ) ;
V_3 -> V_87 = V_138 -> V_87 + V_152 ;
} else
V_3 -> V_87 = V_89 -> V_86 ;
F_117 ( V_89 , V_3 ) ;
}
static void
F_121 ( struct V_1 * V_89 , struct V_2 * V_3 )
{
struct V_2 * V_147 = V_3 ;
bool V_148 ;
V_148 = ! -- V_147 -> V_149 ;
V_147 -> V_150 -= V_147 -> V_145 ;
while ( V_148 ) {
struct V_2 * V_34 = F_33 ( V_147 ) ;
F_122 ( V_147 -> V_150 ) ;
V_147 -> V_83 = 0 ;
if ( ! V_34 )
break;
V_148 = ! -- V_34 -> V_149 ;
V_34 -> V_150 -= V_147 -> V_143 ;
V_147 = V_34 ;
}
if ( ! F_108 ( & V_3 -> V_128 ) )
F_104 ( & V_3 -> V_128 , V_89 ) ;
}
static void
F_123 ( struct V_46 * V_47 , struct V_2 * V_3 )
{
struct V_1 * V_89 = & V_47 -> V_151 ;
F_21 ( V_3 -> V_136 < 1 ) ;
V_3 -> V_136 -- ;
if ( V_3 -> V_136 )
return;
F_124 ( V_47 , V_3 , L_3 ) ;
F_121 ( V_89 , V_3 ) ;
V_3 -> V_153 = 0 ;
F_13 ( V_3 ) ;
}
static inline unsigned int F_125 ( struct V_50 * V_51 ,
unsigned int * V_36 )
{
unsigned int V_154 ;
if ( ! V_51 -> V_108 || V_51 -> V_108 == V_109 ) {
V_154 = F_118 ( unsigned , ( V_109 - V_51 -> V_155 ) ,
1 ) ;
} else {
V_154 = V_109 - V_51 -> V_108 ;
if ( V_154 > V_51 -> V_111 ) {
* V_36 = V_154 - V_51 -> V_111 ;
V_154 = V_51 -> V_111 ;
}
if ( F_126 ( V_51 -> V_108 , V_51 -> V_155 ) )
* V_36 += V_51 -> V_108 -
V_51 -> V_155 ;
}
return V_154 ;
}
static void F_127 ( struct V_46 * V_47 , struct V_2 * V_3 ,
struct V_50 * V_51 )
{
struct V_1 * V_89 = & V_47 -> V_151 ;
unsigned int V_156 , V_82 , V_157 = 0 ;
int V_158 = V_3 -> V_136 - F_62 ( V_47 , V_3 )
- V_3 -> V_8 . V_58 ;
unsigned int V_146 ;
F_21 ( V_158 < 0 ) ;
V_156 = V_82 = F_125 ( V_51 , & V_157 ) ;
if ( F_54 ( V_47 ) )
V_82 = V_51 -> V_159 ;
else if ( ! F_59 ( V_51 ) && ! V_158 )
V_82 = V_51 -> V_111 ;
V_146 = V_3 -> V_83 ;
F_121 ( V_89 , V_3 ) ;
V_3 -> V_87 += F_77 ( V_82 , V_146 ) ;
F_117 ( V_89 , V_3 ) ;
if ( F_126 ( V_47 -> V_160 , V_109 ) ) {
V_3 -> V_153 = V_47 -> V_160
- V_109 ;
V_3 -> V_161 = V_47 -> V_162 ;
V_3 -> V_163 = V_47 -> V_164 ;
} else
V_3 -> V_153 = 0 ;
F_124 ( V_47 , V_3 , L_4 , V_3 -> V_87 ,
V_89 -> V_86 ) ;
F_88 ( V_51 -> V_47 , V_51 ,
L_5 ,
V_156 , V_51 -> V_159 , V_82 ,
F_54 ( V_47 ) , V_51 -> V_165 ) ;
F_40 ( V_3 , V_156 , V_157 ) ;
F_14 ( V_3 ) ;
}
static void F_128 ( struct V_2 * V_3 )
{
struct V_1 * V_89 ;
int V_166 , V_167 ;
F_129 ( V_3 , V_166 , V_167 , V_89 )
* V_89 = V_168 ;
F_103 ( & V_3 -> V_128 ) ;
V_3 -> V_169 . V_170 = V_109 ;
}
static void F_130 ( struct V_10 * V_11 )
{
F_131 ( & V_11 -> V_37 ) ;
F_131 ( & V_11 -> V_40 ) ;
F_131 ( & V_11 -> V_41 ) ;
F_131 ( & V_11 -> V_19 ) ;
F_132 ( & V_11 -> time ) ;
#ifdef F_41
F_132 ( & V_11 -> V_36 ) ;
F_132 ( & V_11 -> V_22 ) ;
F_132 ( & V_11 -> V_23 ) ;
F_132 ( & V_11 -> V_18 ) ;
F_132 ( & V_11 -> V_14 ) ;
F_132 ( & V_11 -> V_21 ) ;
F_132 ( & V_11 -> V_17 ) ;
#endif
}
static int F_133 ( struct V_10 * V_11 , T_5 V_171 )
{
if ( F_134 ( & V_11 -> V_37 , V_171 ) ||
F_134 ( & V_11 -> V_40 , V_171 ) ||
F_134 ( & V_11 -> V_41 , V_171 ) ||
F_134 ( & V_11 -> V_19 , V_171 ) ||
F_135 ( & V_11 -> time , V_171 ) )
goto V_172;
#ifdef F_41
if ( F_135 ( & V_11 -> V_36 , V_171 ) ||
F_135 ( & V_11 -> V_22 , V_171 ) ||
F_135 ( & V_11 -> V_23 , V_171 ) ||
F_135 ( & V_11 -> V_18 , V_171 ) ||
F_135 ( & V_11 -> V_14 , V_171 ) ||
F_135 ( & V_11 -> V_21 , V_171 ) ||
F_135 ( & V_11 -> V_17 , V_171 ) )
goto V_172;
#endif
return 0 ;
V_172:
F_130 ( V_11 ) ;
return - V_173 ;
}
static struct V_27 * F_136 ( T_5 V_171 )
{
struct V_26 * V_174 ;
V_174 = F_137 ( sizeof( * V_174 ) , V_175 ) ;
if ( ! V_174 )
return NULL ;
return & V_174 -> V_28 ;
}
static void F_138 ( struct V_27 * V_28 )
{
struct V_26 * V_174 = F_26 ( V_28 ) ;
unsigned int V_143 = F_139 ( V_176 ) ?
V_177 : V_178 ;
if ( F_140 ( V_28 ) == & V_179 )
V_143 *= 2 ;
V_174 -> V_143 = V_143 ;
V_174 -> V_145 = V_143 ;
}
static void F_141 ( struct V_27 * V_28 )
{
F_142 ( F_26 ( V_28 ) ) ;
}
static void F_143 ( struct V_27 * V_28 )
{
struct V_32 * V_32 = F_140 ( V_28 ) ;
bool V_180 = F_139 ( V_176 ) ;
unsigned int V_143 = V_180 ? V_177 : V_178 ;
if ( V_32 == & V_179 )
V_143 *= 2 ;
F_122 ( F_144 ( & V_32 -> V_181 , V_143 , V_180 , true , false ) ) ;
F_122 ( F_144 ( & V_32 -> V_181 , V_143 , V_180 , true , true ) ) ;
}
static struct V_24 * F_145 ( T_5 V_171 , int V_137 )
{
struct V_2 * V_3 ;
V_3 = F_146 ( sizeof( * V_3 ) , V_171 , V_137 ) ;
if ( ! V_3 )
return NULL ;
F_128 ( V_3 ) ;
if ( F_133 ( & V_3 -> V_11 , V_171 ) ) {
F_142 ( V_3 ) ;
return NULL ;
}
return & V_3 -> V_25 ;
}
static void F_147 ( struct V_24 * V_25 )
{
struct V_2 * V_3 = F_24 ( V_25 ) ;
struct V_26 * V_174 = F_31 ( V_25 -> V_30 -> V_32 ) ;
V_3 -> V_143 = V_174 -> V_143 ;
V_3 -> V_145 = V_174 -> V_145 ;
}
static void F_148 ( struct V_24 * V_25 )
{
struct V_2 * V_3 = F_24 ( V_25 ) ;
int V_166 ;
for ( V_166 = 0 ; V_166 < V_79 ; V_166 ++ ) {
if ( V_3 -> V_182 [ 0 ] [ V_166 ] )
F_149 ( V_3 -> V_182 [ 0 ] [ V_166 ] ) ;
if ( V_3 -> V_182 [ 1 ] [ V_166 ] )
F_149 ( V_3 -> V_182 [ 1 ] [ V_166 ] ) ;
}
if ( V_3 -> V_183 )
F_149 ( V_3 -> V_183 ) ;
F_51 ( V_3 ) ;
}
static void F_150 ( struct V_24 * V_25 )
{
struct V_2 * V_3 = F_24 ( V_25 ) ;
F_130 ( & V_3 -> V_11 ) ;
return F_142 ( V_3 ) ;
}
static void F_151 ( struct V_24 * V_25 )
{
struct V_2 * V_3 = F_24 ( V_25 ) ;
F_45 ( & V_3 -> V_11 ) ;
}
static struct V_2 * F_152 ( struct V_46 * V_47 ,
struct V_32 * V_32 )
{
struct V_29 * V_30 ;
V_30 = F_153 ( V_32 , V_47 -> V_64 ) ;
if ( F_154 ( V_30 ) )
return F_29 ( V_30 ) ;
return NULL ;
}
static void F_155 ( struct V_50 * V_51 , struct V_2 * V_3 )
{
V_51 -> V_3 = V_3 ;
F_34 ( V_3 ) ;
}
static T_2 F_156 ( struct V_184 * V_185 ,
struct V_24 * V_25 , int V_186 )
{
struct V_2 * V_3 = F_24 ( V_25 ) ;
if ( ! V_3 -> V_187 )
return 0 ;
return F_157 ( V_185 , V_25 , V_3 -> V_187 ) ;
}
static int F_158 ( struct V_184 * V_185 , void * V_188 )
{
F_159 ( V_185 , F_160 ( F_161 ( V_185 ) ) ,
F_156 , & V_31 ,
0 , false ) ;
return 0 ;
}
static T_2 F_162 ( struct V_184 * V_185 ,
struct V_24 * V_25 , int V_186 )
{
struct V_2 * V_3 = F_24 ( V_25 ) ;
if ( ! V_3 -> V_189 )
return 0 ;
return F_157 ( V_185 , V_25 , V_3 -> V_189 ) ;
}
static int F_163 ( struct V_184 * V_185 , void * V_188 )
{
F_159 ( V_185 , F_160 ( F_161 ( V_185 ) ) ,
F_162 , & V_31 ,
0 , false ) ;
return 0 ;
}
static int F_164 ( struct V_184 * V_185 , void * V_188 )
{
struct V_32 * V_32 = F_160 ( F_161 ( V_185 ) ) ;
struct V_26 * V_174 = F_31 ( V_32 ) ;
unsigned int V_190 = 0 ;
if ( V_174 )
V_190 = V_174 -> V_143 ;
F_165 ( V_185 , L_6 , V_190 ) ;
return 0 ;
}
static int F_166 ( struct V_184 * V_185 , void * V_188 )
{
struct V_32 * V_32 = F_160 ( F_161 ( V_185 ) ) ;
struct V_26 * V_174 = F_31 ( V_32 ) ;
unsigned int V_190 = 0 ;
if ( V_174 )
V_190 = V_174 -> V_145 ;
F_165 ( V_185 , L_6 , V_190 ) ;
return 0 ;
}
static T_6 F_167 ( struct V_191 * V_192 ,
char * V_193 , T_7 V_194 , T_8 V_186 ,
bool V_180 , bool V_195 )
{
unsigned int F_83 = V_180 ? V_196 : V_197 ;
unsigned int F_84 = V_180 ? V_198 : V_199 ;
struct V_32 * V_32 = F_160 ( F_168 ( V_192 ) ) ;
struct V_200 V_201 ;
struct V_2 * V_3 ;
struct V_26 * V_202 ;
int V_203 ;
T_2 V_188 ;
V_203 = F_169 ( V_32 , & V_31 , V_193 , & V_201 ) ;
if ( V_203 )
return V_203 ;
if ( sscanf ( V_201 . V_204 , L_7 , & V_188 ) == 1 ) {
V_203 = - V_205 ;
if ( ! V_188 && V_180 )
goto V_206;
} else if ( ! strcmp ( F_170 ( V_201 . V_204 ) , L_8 ) ) {
V_188 = 0 ;
} else {
V_203 = - V_207 ;
goto V_206;
}
V_3 = F_29 ( V_201 . V_30 ) ;
V_202 = F_31 ( V_32 ) ;
V_203 = - V_205 ;
if ( ! V_188 || ( V_188 >= F_83 && V_188 <= F_84 ) ) {
if ( ! V_195 ) {
V_3 -> V_187 = V_188 ;
V_3 -> V_142 = V_188 ? : V_202 -> V_143 ;
} else {
V_3 -> V_189 = V_188 ;
V_3 -> V_144 = V_188 ? : V_202 -> V_145 ;
}
V_203 = 0 ;
}
V_206:
F_171 ( & V_201 ) ;
return V_203 ? : V_194 ;
}
static T_6 F_172 ( struct V_191 * V_192 ,
char * V_193 , T_7 V_194 , T_8 V_186 )
{
return F_167 ( V_192 , V_193 , V_194 , V_186 , false , false ) ;
}
static T_6 F_173 ( struct V_191 * V_192 ,
char * V_193 , T_7 V_194 , T_8 V_186 )
{
return F_167 ( V_192 , V_193 , V_194 , V_186 , false , true ) ;
}
static int F_144 ( struct V_208 * V_181 , T_2 V_190 ,
bool V_180 , bool V_209 , bool V_195 )
{
unsigned int F_83 = V_180 ? V_196 : V_197 ;
unsigned int F_84 = V_180 ? V_198 : V_199 ;
struct V_32 * V_32 = F_160 ( V_181 ) ;
struct V_29 * V_30 ;
struct V_26 * V_202 ;
int V_203 = 0 ;
if ( V_190 < F_83 || V_190 > F_84 )
return - V_205 ;
F_174 ( & V_32 -> V_210 ) ;
V_202 = F_31 ( V_32 ) ;
if ( ! V_202 ) {
V_203 = - V_207 ;
goto V_211;
}
if ( ! V_195 )
V_202 -> V_143 = V_190 ;
else
V_202 -> V_145 = V_190 ;
F_175 (blkg, &blkcg->blkg_list, blkcg_node) {
struct V_2 * V_3 = F_29 ( V_30 ) ;
if ( ! V_3 )
continue;
if ( ! V_195 ) {
if ( V_209 )
V_3 -> V_187 = 0 ;
if ( ! V_3 -> V_187 )
V_3 -> V_142 = V_202 -> V_143 ;
} else {
if ( V_209 )
V_3 -> V_189 = 0 ;
if ( ! V_3 -> V_189 )
V_3 -> V_144 = V_202 -> V_145 ;
}
}
V_211:
F_176 ( & V_32 -> V_210 ) ;
return V_203 ;
}
static int F_177 ( struct V_208 * V_181 , struct V_212 * V_213 ,
T_2 V_190 )
{
return F_144 ( V_181 , V_190 , false , false , false ) ;
}
static int F_178 ( struct V_208 * V_181 ,
struct V_212 * V_213 , T_2 V_190 )
{
return F_144 ( V_181 , V_190 , false , false , true ) ;
}
static int F_179 ( struct V_184 * V_185 , void * V_188 )
{
F_159 ( V_185 , F_160 ( F_161 ( V_185 ) ) , V_214 ,
& V_31 , F_180 ( V_185 ) -> V_215 , false ) ;
return 0 ;
}
static int F_181 ( struct V_184 * V_185 , void * V_188 )
{
F_159 ( V_185 , F_160 ( F_161 ( V_185 ) ) , V_216 ,
& V_31 , F_180 ( V_185 ) -> V_215 , true ) ;
return 0 ;
}
static T_2 F_182 ( struct V_184 * V_185 ,
struct V_24 * V_25 , int V_186 )
{
T_2 V_217 = F_183 ( F_28 ( V_25 ) ,
& V_31 , V_186 ) ;
return F_157 ( V_185 , V_25 , V_217 ) ;
}
static T_2 F_184 ( struct V_184 * V_185 ,
struct V_24 * V_25 , int V_186 )
{
struct V_218 V_217 = F_185 ( F_28 ( V_25 ) ,
& V_31 , V_186 ) ;
return F_186 ( V_185 , V_25 , & V_217 ) ;
}
static int F_187 ( struct V_184 * V_185 , void * V_188 )
{
F_159 ( V_185 , F_160 ( F_161 ( V_185 ) ) ,
F_182 , & V_31 ,
F_180 ( V_185 ) -> V_215 , false ) ;
return 0 ;
}
static int F_188 ( struct V_184 * V_185 , void * V_188 )
{
F_159 ( V_185 , F_160 ( F_161 ( V_185 ) ) ,
F_184 , & V_31 ,
F_180 ( V_185 ) -> V_215 , true ) ;
return 0 ;
}
static T_2 F_189 ( struct V_184 * V_185 , struct V_24 * V_25 ,
int V_186 )
{
T_2 V_217 = F_15 ( & V_25 -> V_30 -> V_219 ) ;
return F_157 ( V_185 , V_25 , V_217 >> 9 ) ;
}
static int F_190 ( struct V_184 * V_185 , void * V_188 )
{
F_159 ( V_185 , F_160 ( F_161 ( V_185 ) ) ,
F_189 , & V_31 , 0 , false ) ;
return 0 ;
}
static T_2 F_191 ( struct V_184 * V_185 ,
struct V_24 * V_25 , int V_186 )
{
struct V_218 V_220 = F_185 ( V_25 -> V_30 , NULL ,
F_192 ( struct V_29 , V_219 ) ) ;
T_2 V_217 = F_193 ( & V_220 . V_221 [ V_222 ] ) +
F_193 ( & V_220 . V_221 [ V_223 ] ) ;
return F_157 ( V_185 , V_25 , V_217 >> 9 ) ;
}
static int F_194 ( struct V_184 * V_185 , void * V_188 )
{
F_159 ( V_185 , F_160 ( F_161 ( V_185 ) ) ,
F_191 , & V_31 , 0 ,
false ) ;
return 0 ;
}
static T_2 F_195 ( struct V_184 * V_185 ,
struct V_24 * V_25 , int V_186 )
{
struct V_2 * V_3 = F_24 ( V_25 ) ;
T_2 V_224 = F_196 ( & V_3 -> V_11 . V_23 ) ;
T_2 V_188 = 0 ;
if ( V_224 ) {
V_188 = F_196 ( & V_3 -> V_11 . V_22 ) ;
V_188 = F_197 ( V_188 , V_224 ) ;
}
F_157 ( V_185 , V_25 , V_188 ) ;
return 0 ;
}
static int F_198 ( struct V_184 * V_185 , void * V_188 )
{
F_159 ( V_185 , F_160 ( F_161 ( V_185 ) ) ,
F_195 , & V_31 ,
0 , false ) ;
return 0 ;
}
static int F_199 ( struct V_184 * V_185 , void * V_188 )
{
struct V_32 * V_32 = F_160 ( F_161 ( V_185 ) ) ;
struct V_26 * V_174 = F_31 ( V_32 ) ;
F_165 ( V_185 , L_9 , V_174 -> V_143 ) ;
F_159 ( V_185 , V_32 , F_156 ,
& V_31 , 0 , false ) ;
return 0 ;
}
static T_6 F_200 ( struct V_191 * V_192 ,
char * V_193 , T_7 V_194 , T_8 V_186 )
{
char * V_225 ;
int V_203 ;
T_2 V_188 ;
V_193 = F_170 ( V_193 ) ;
V_188 = F_201 ( V_193 , & V_225 , 0 ) ;
if ( * V_225 == '\0' || sscanf ( V_193 , L_10 , & V_188 ) == 1 ) {
V_203 = F_144 ( F_168 ( V_192 ) , V_188 , true , false , false ) ;
return V_203 ? : V_194 ;
}
return F_167 ( V_192 , V_193 , V_194 , V_186 , true , false ) ;
}
static struct V_2 * F_152 ( struct V_46 * V_47 ,
struct V_32 * V_32 )
{
return V_47 -> V_226 ;
}
static inline void
F_155 ( struct V_50 * V_51 , struct V_2 * V_3 ) {
V_51 -> V_3 = V_3 ;
}
static void F_202 ( struct V_46 * V_47 , struct V_50 * V_51 ,
bool V_227 )
{
struct V_128 * * V_228 , * V_34 ;
struct V_50 * V_229 ;
unsigned long V_230 ;
struct V_1 * V_89 ;
int V_90 ;
int V_231 = 1 ;
V_89 = F_1 ( V_51 -> V_3 , F_55 ( V_51 ) , F_58 ( V_51 ) ) ;
if ( F_56 ( V_51 ) ) {
V_230 = V_152 ;
V_34 = F_120 ( & V_89 -> V_127 ) ;
if ( V_34 && V_34 != & V_51 -> V_128 ) {
V_229 = F_99 ( V_34 , struct V_50 , V_128 ) ;
V_230 += V_229 -> V_230 ;
} else
V_230 += V_109 ;
} else if ( ! V_227 ) {
V_230 = F_110 ( V_47 , V_51 ) + V_109 ;
V_230 -= V_51 -> V_232 ;
V_51 -> V_232 = 0 ;
} else {
V_230 = - V_233 ;
V_229 = F_97 ( V_89 ) ;
V_230 += V_229 ? V_229 -> V_230 : V_109 ;
}
if ( ! F_108 ( & V_51 -> V_128 ) ) {
V_231 = 0 ;
if ( V_230 == V_51 -> V_230 && V_51 -> V_234 == V_89 )
return;
F_104 ( & V_51 -> V_128 , V_51 -> V_234 ) ;
V_51 -> V_234 = NULL ;
}
V_90 = 1 ;
V_34 = NULL ;
V_51 -> V_234 = V_89 ;
V_228 = & V_89 -> V_127 . V_128 ;
while ( * V_228 ) {
V_34 = * V_228 ;
V_229 = F_99 ( V_34 , struct V_50 , V_128 ) ;
if ( F_91 ( V_230 , V_229 -> V_230 ) )
V_228 = & V_34 -> V_140 ;
else {
V_228 = & V_34 -> V_141 ;
V_90 = 0 ;
}
}
if ( V_90 )
V_89 -> V_90 = & V_51 -> V_128 ;
V_51 -> V_230 = V_230 ;
F_113 ( & V_51 -> V_128 , V_34 , V_228 ) ;
F_114 ( & V_51 -> V_128 , & V_89 -> V_127 ) ;
V_89 -> V_58 ++ ;
if ( V_227 || ! V_231 )
return;
F_119 ( V_47 , V_51 -> V_3 ) ;
}
static struct V_50 *
F_203 ( struct V_46 * V_47 , struct V_130 * V_126 ,
T_4 V_235 , struct V_128 * * V_236 ,
struct V_128 * * * V_237 )
{
struct V_128 * * V_228 , * V_34 ;
struct V_50 * V_51 = NULL ;
V_34 = NULL ;
V_228 = & V_126 -> V_128 ;
while ( * V_228 ) {
struct V_128 * * V_129 ;
V_34 = * V_228 ;
V_51 = F_99 ( V_34 , struct V_50 , V_238 ) ;
if ( V_235 > F_96 ( V_51 -> V_239 ) )
V_129 = & ( * V_228 ) -> V_141 ;
else if ( V_235 < F_96 ( V_51 -> V_239 ) )
V_129 = & ( * V_228 ) -> V_140 ;
else
break;
V_228 = V_129 ;
V_51 = NULL ;
}
* V_236 = V_34 ;
if ( V_237 )
* V_237 = V_228 ;
return V_51 ;
}
static void F_204 ( struct V_46 * V_47 , struct V_50 * V_51 )
{
struct V_128 * * V_228 , * V_34 ;
struct V_50 * V_229 ;
if ( V_51 -> V_240 ) {
F_102 ( & V_51 -> V_238 , V_51 -> V_240 ) ;
V_51 -> V_240 = NULL ;
}
if ( F_56 ( V_51 ) )
return;
if ( ! V_51 -> V_239 )
return;
V_51 -> V_240 = & V_47 -> V_241 [ V_51 -> V_242 ] ;
V_229 = F_203 ( V_47 , V_51 -> V_240 ,
F_96 ( V_51 -> V_239 ) , & V_34 , & V_228 ) ;
if ( ! V_229 ) {
F_113 ( & V_51 -> V_238 , V_34 , V_228 ) ;
F_114 ( & V_51 -> V_238 , V_51 -> V_240 ) ;
} else
V_51 -> V_240 = NULL ;
}
static void F_205 ( struct V_46 * V_47 , struct V_50 * V_51 )
{
if ( F_206 ( V_51 ) ) {
F_202 ( V_47 , V_51 , 0 ) ;
F_204 ( V_47 , V_51 ) ;
}
}
static void F_207 ( struct V_46 * V_47 , struct V_50 * V_51 )
{
F_88 ( V_47 , V_51 , L_11 ) ;
F_21 ( F_206 ( V_51 ) ) ;
F_208 ( V_51 ) ;
V_47 -> V_73 ++ ;
if ( F_59 ( V_51 ) )
V_47 -> V_243 ++ ;
F_205 ( V_47 , V_51 ) ;
}
static void F_209 ( struct V_46 * V_47 , struct V_50 * V_51 )
{
F_88 ( V_47 , V_51 , L_12 ) ;
F_21 ( ! F_206 ( V_51 ) ) ;
F_210 ( V_51 ) ;
if ( ! F_108 ( & V_51 -> V_128 ) ) {
F_104 ( & V_51 -> V_128 , V_51 -> V_234 ) ;
V_51 -> V_234 = NULL ;
}
if ( V_51 -> V_240 ) {
F_102 ( & V_51 -> V_238 , V_51 -> V_240 ) ;
V_51 -> V_240 = NULL ;
}
F_123 ( V_47 , V_51 -> V_3 ) ;
F_21 ( ! V_47 -> V_73 ) ;
V_47 -> V_73 -- ;
if ( F_59 ( V_51 ) )
V_47 -> V_243 -- ;
}
static void F_211 ( struct V_112 * V_244 )
{
struct V_50 * V_51 = F_212 ( V_244 ) ;
const int V_75 = F_95 ( V_244 ) ;
F_21 ( ! V_51 -> V_19 [ V_75 ] ) ;
V_51 -> V_19 [ V_75 ] -- ;
F_213 ( & V_51 -> V_135 , V_244 ) ;
if ( F_206 ( V_51 ) && F_214 ( & V_51 -> V_135 ) ) {
if ( V_51 -> V_240 ) {
F_102 ( & V_51 -> V_238 , V_51 -> V_240 ) ;
V_51 -> V_240 = NULL ;
}
}
}
static void F_215 ( struct V_112 * V_244 )
{
struct V_50 * V_51 = F_212 ( V_244 ) ;
struct V_46 * V_47 = V_51 -> V_47 ;
struct V_112 * V_134 ;
V_51 -> V_19 [ F_95 ( V_244 ) ] ++ ;
F_216 ( & V_51 -> V_135 , V_244 ) ;
if ( ! F_206 ( V_51 ) )
F_207 ( V_47 , V_51 ) ;
V_134 = V_51 -> V_239 ;
V_51 -> V_239 = F_92 ( V_47 , V_51 -> V_239 , V_244 , V_47 -> V_245 ) ;
if ( V_134 != V_51 -> V_239 )
F_204 ( V_47 , V_51 ) ;
F_21 ( ! V_51 -> V_239 ) ;
}
static void F_217 ( struct V_50 * V_51 , struct V_112 * V_244 )
{
F_213 ( & V_51 -> V_135 , V_244 ) ;
V_51 -> V_19 [ F_95 ( V_244 ) ] -- ;
F_42 ( F_218 ( V_244 ) , V_244 -> V_122 ) ;
F_215 ( V_244 ) ;
F_38 ( F_218 ( V_244 ) , V_51 -> V_47 -> V_246 ,
V_244 -> V_122 ) ;
}
static struct V_112 *
F_219 ( struct V_46 * V_47 , struct V_69 * V_69 )
{
struct V_247 * V_248 = V_249 ;
struct V_59 * V_65 ;
struct V_50 * V_51 ;
V_65 = F_64 ( V_47 , V_248 -> V_62 ) ;
if ( ! V_65 )
return NULL ;
V_51 = F_66 ( V_65 , F_69 ( V_69 ) ) ;
if ( V_51 )
return F_220 ( & V_51 -> V_135 , F_221 ( V_69 ) ) ;
return NULL ;
}
static void F_222 ( struct V_250 * V_44 , struct V_112 * V_244 )
{
struct V_46 * V_47 = V_44 -> V_67 -> V_68 ;
V_47 -> V_251 ++ ;
F_88 ( V_47 , F_212 ( V_244 ) , L_13 ,
V_47 -> V_251 ) ;
V_47 -> V_245 = F_96 ( V_244 ) + F_223 ( V_244 ) ;
}
static void F_224 ( struct V_250 * V_44 , struct V_112 * V_244 )
{
struct V_46 * V_47 = V_44 -> V_67 -> V_68 ;
F_75 ( ! V_47 -> V_251 ) ;
V_47 -> V_251 -- ;
F_88 ( V_47 , F_212 ( V_244 ) , L_14 ,
V_47 -> V_251 ) ;
}
static void F_225 ( struct V_112 * V_244 )
{
struct V_50 * V_51 = F_212 ( V_244 ) ;
if ( V_51 -> V_239 == V_244 )
V_51 -> V_239 = F_105 ( V_51 -> V_47 , V_51 , V_244 ) ;
F_226 ( & V_244 -> V_252 ) ;
F_211 ( V_244 ) ;
V_51 -> V_47 -> V_253 -- ;
F_42 ( F_218 ( V_244 ) , V_244 -> V_122 ) ;
if ( V_244 -> V_122 & V_123 ) {
F_75 ( ! V_51 -> V_254 ) ;
V_51 -> V_254 -- ;
}
}
static int F_227 ( struct V_250 * V_44 , struct V_112 * * V_255 ,
struct V_69 * V_69 )
{
struct V_46 * V_47 = V_44 -> V_67 -> V_68 ;
struct V_112 * V_256 ;
V_256 = F_219 ( V_47 , V_69 ) ;
if ( V_256 && F_228 ( V_256 , V_69 ) ) {
* V_255 = V_256 ;
return V_257 ;
}
return V_258 ;
}
static void F_229 ( struct V_250 * V_44 , struct V_112 * V_255 ,
int type )
{
if ( type == V_257 ) {
struct V_50 * V_51 = F_212 ( V_255 ) ;
F_217 ( V_51 , V_255 ) ;
}
}
static void F_230 ( struct V_250 * V_44 , struct V_112 * V_255 ,
struct V_69 * V_69 )
{
F_43 ( F_218 ( V_255 ) , V_69 -> V_71 ) ;
}
static void
F_231 ( struct V_250 * V_44 , struct V_112 * V_244 ,
struct V_112 * V_133 )
{
struct V_50 * V_51 = F_212 ( V_244 ) ;
struct V_46 * V_47 = V_44 -> V_67 -> V_68 ;
if ( ! F_232 ( & V_244 -> V_252 ) && ! F_232 ( & V_133 -> V_252 ) &&
F_91 ( V_133 -> V_259 , V_244 -> V_259 ) &&
V_51 == F_212 ( V_133 ) ) {
F_233 ( & V_244 -> V_252 , & V_133 -> V_252 ) ;
V_244 -> V_259 = V_133 -> V_259 ;
}
if ( V_51 -> V_239 == V_133 )
V_51 -> V_239 = V_244 ;
F_225 ( V_133 ) ;
F_43 ( F_218 ( V_244 ) , V_133 -> V_122 ) ;
V_51 = F_212 ( V_133 ) ;
if ( F_206 ( V_51 ) && F_214 ( & V_51 -> V_135 ) &&
V_51 != V_47 -> V_260 )
F_209 ( V_47 , V_51 ) ;
}
static int F_234 ( struct V_250 * V_44 , struct V_112 * V_244 ,
struct V_69 * V_69 )
{
struct V_46 * V_47 = V_44 -> V_67 -> V_68 ;
struct V_59 * V_65 ;
struct V_50 * V_51 ;
if ( F_69 ( V_69 ) && ! F_95 ( V_244 ) )
return false ;
V_65 = F_64 ( V_47 , V_249 -> V_62 ) ;
if ( ! V_65 )
return false ;
V_51 = F_66 ( V_65 , F_69 ( V_69 ) ) ;
return V_51 == F_212 ( V_244 ) ;
}
static inline void F_235 ( struct V_46 * V_47 , struct V_50 * V_51 )
{
F_236 ( & V_47 -> V_261 ) ;
F_17 ( V_51 -> V_3 ) ;
}
static void F_237 ( struct V_46 * V_47 ,
struct V_50 * V_51 )
{
if ( V_51 ) {
F_88 ( V_47 , V_51 , L_15 ,
V_47 -> V_164 , V_47 -> V_162 ) ;
F_23 ( V_51 -> V_3 ) ;
V_51 -> V_108 = 0 ;
V_51 -> V_155 = V_109 ;
V_51 -> V_111 = 0 ;
V_51 -> V_110 = 0 ;
V_51 -> V_159 = 0 ;
V_51 -> V_165 = 0 ;
F_238 ( V_51 ) ;
F_239 ( V_51 ) ;
F_240 ( V_51 ) ;
F_241 ( V_51 ) ;
F_242 ( V_51 ) ;
F_235 ( V_47 , V_51 ) ;
}
V_47 -> V_260 = V_51 ;
}
static void
F_243 ( struct V_46 * V_47 , struct V_50 * V_51 ,
bool V_262 )
{
F_88 ( V_47 , V_51 , L_16 , V_262 ) ;
if ( F_244 ( V_51 ) )
F_235 ( V_47 , V_51 ) ;
F_238 ( V_51 ) ;
F_245 ( V_51 ) ;
if ( F_246 ( V_51 ) && F_247 ( V_51 ) )
F_248 ( V_51 ) ;
if ( V_262 ) {
if ( F_90 ( V_51 ) )
V_51 -> V_232 = F_86 ( V_47 , V_51 ) ;
else
V_51 -> V_232 = V_51 -> V_110 - V_109 ;
F_88 ( V_47 , V_51 , L_17 , V_51 -> V_232 ) ;
}
F_127 ( V_47 , V_51 -> V_3 , V_51 ) ;
if ( F_206 ( V_51 ) && F_214 ( & V_51 -> V_135 ) )
F_209 ( V_47 , V_51 ) ;
F_205 ( V_47 , V_51 ) ;
if ( V_51 == V_47 -> V_260 )
V_47 -> V_260 = NULL ;
if ( V_47 -> V_263 ) {
F_249 ( V_47 -> V_263 -> V_61 . V_63 ) ;
V_47 -> V_263 = NULL ;
}
}
static inline void F_250 ( struct V_46 * V_47 , bool V_262 )
{
struct V_50 * V_51 = V_47 -> V_260 ;
if ( V_51 )
F_243 ( V_47 , V_51 , V_262 ) ;
}
static struct V_50 * F_251 ( struct V_46 * V_47 )
{
struct V_1 * V_89 = F_1 ( V_47 -> V_246 ,
V_47 -> V_164 , V_47 -> V_162 ) ;
if ( ! V_47 -> V_253 )
return NULL ;
if ( ! V_89 )
return NULL ;
if ( F_214 ( & V_89 -> V_127 ) )
return NULL ;
return F_97 ( V_89 ) ;
}
static struct V_50 * F_252 ( struct V_46 * V_47 )
{
struct V_2 * V_3 ;
struct V_50 * V_51 ;
int V_166 , V_167 ;
struct V_1 * V_89 ;
if ( ! V_47 -> V_253 )
return NULL ;
V_3 = F_253 ( V_47 ) ;
if ( ! V_3 )
return NULL ;
F_129 (cfqg, i, j, st)
if ( ( V_51 = F_97 ( V_89 ) ) != NULL )
return V_51 ;
return NULL ;
}
static struct V_50 * F_254 ( struct V_46 * V_47 ,
struct V_50 * V_51 )
{
if ( ! V_51 )
V_51 = F_251 ( V_47 ) ;
F_237 ( V_47 , V_51 ) ;
return V_51 ;
}
static inline T_4 F_255 ( struct V_46 * V_47 ,
struct V_112 * V_244 )
{
if ( F_96 ( V_244 ) >= V_47 -> V_245 )
return F_96 ( V_244 ) - V_47 -> V_245 ;
else
return V_47 -> V_245 - F_96 ( V_244 ) ;
}
static inline int F_256 ( struct V_46 * V_47 , struct V_50 * V_51 ,
struct V_112 * V_244 )
{
return F_255 ( V_47 , V_244 ) <= V_264 ;
}
static struct V_50 * F_257 ( struct V_46 * V_47 ,
struct V_50 * V_265 )
{
struct V_130 * V_126 = & V_47 -> V_241 [ V_265 -> V_242 ] ;
struct V_128 * V_34 , * V_137 ;
struct V_50 * V_229 ;
T_4 V_235 = V_47 -> V_245 ;
if ( F_214 ( V_126 ) )
return NULL ;
V_229 = F_203 ( V_47 , V_126 , V_235 , & V_34 , NULL ) ;
if ( V_229 )
return V_229 ;
V_229 = F_99 ( V_34 , struct V_50 , V_238 ) ;
if ( F_256 ( V_47 , V_265 , V_229 -> V_239 ) )
return V_229 ;
if ( F_96 ( V_229 -> V_239 ) < V_235 )
V_137 = F_106 ( & V_229 -> V_238 ) ;
else
V_137 = F_107 ( & V_229 -> V_238 ) ;
if ( ! V_137 )
return NULL ;
V_229 = F_99 ( V_137 , struct V_50 , V_238 ) ;
if ( F_256 ( V_47 , V_265 , V_229 -> V_239 ) )
return V_229 ;
return NULL ;
}
static struct V_50 * F_258 ( struct V_46 * V_47 ,
struct V_50 * V_265 )
{
struct V_50 * V_51 ;
if ( F_56 ( V_265 ) )
return NULL ;
if ( ! F_59 ( V_265 ) )
return NULL ;
if ( F_247 ( V_265 ) )
return NULL ;
if ( V_265 -> V_3 -> V_136 == 1 )
return NULL ;
V_51 = F_257 ( V_47 , V_265 ) ;
if ( ! V_51 )
return NULL ;
if ( V_265 -> V_3 != V_51 -> V_3 )
return NULL ;
if ( ! F_59 ( V_51 ) )
return NULL ;
if ( F_247 ( V_51 ) )
return NULL ;
if ( F_57 ( V_51 ) != F_57 ( V_265 ) )
return NULL ;
return V_51 ;
}
static bool F_259 ( struct V_46 * V_47 , struct V_50 * V_51 )
{
enum V_4 V_57 = F_55 ( V_51 ) ;
struct V_1 * V_89 = V_51 -> V_234 ;
F_21 ( ! V_89 ) ;
F_21 ( ! V_89 -> V_58 ) ;
if ( ! V_47 -> V_48 )
return false ;
if ( V_57 == V_7 )
return false ;
if ( F_60 ( V_51 ) &&
! ( F_260 ( V_47 -> V_64 ) && V_47 -> V_49 ) )
return true ;
if ( V_89 -> V_58 == 1 && F_59 ( V_51 ) &&
! F_261 ( V_47 , & V_89 -> V_169 , false ) )
return true ;
F_88 ( V_47 , V_51 , L_18 , V_89 -> V_58 ) ;
return false ;
}
static void F_262 ( struct V_46 * V_47 )
{
struct V_50 * V_51 = V_47 -> V_260 ;
struct V_59 * V_65 ;
unsigned long V_266 , V_267 = 0 ;
if ( F_260 ( V_47 -> V_64 ) && V_47 -> V_49 )
return;
F_75 ( ! F_214 ( & V_51 -> V_135 ) ) ;
F_75 ( F_90 ( V_51 ) ) ;
if ( ! F_259 ( V_47 , V_51 ) ) {
if ( V_47 -> V_268 )
V_267 = V_47 -> V_268 ;
else
return;
}
if ( V_51 -> V_269 )
return;
V_65 = V_47 -> V_263 ;
if ( ! V_65 || ! F_263 ( & V_65 -> V_61 . V_63 -> V_270 ) )
return;
if ( F_264 ( V_65 -> V_169 . V_271 ) &&
( V_51 -> V_110 - V_109 < V_65 -> V_169 . V_272 ) ) {
F_88 ( V_47 , V_51 , L_19 ,
V_65 -> V_169 . V_272 ) ;
return;
}
if ( V_267 && V_51 -> V_3 -> V_136 > 1 )
return;
F_265 ( V_51 ) ;
if ( V_267 )
V_266 = V_47 -> V_268 ;
else
V_266 = V_47 -> V_48 ;
F_266 ( & V_47 -> V_261 , V_109 + V_266 ) ;
F_20 ( V_51 -> V_3 ) ;
F_88 ( V_47 , V_51 , L_20 , V_266 ,
V_267 ? 1 : 0 ) ;
}
static void F_267 ( struct V_250 * V_44 , struct V_112 * V_244 )
{
struct V_46 * V_47 = V_44 -> V_67 -> V_68 ;
struct V_50 * V_51 = F_212 ( V_244 ) ;
F_88 ( V_47 , V_51 , L_21 ) ;
V_51 -> V_239 = F_105 ( V_47 , V_51 , V_244 ) ;
F_225 ( V_244 ) ;
V_51 -> V_269 ++ ;
( F_218 ( V_244 ) ) -> V_269 ++ ;
F_268 ( V_44 , V_244 ) ;
V_47 -> V_273 [ F_59 ( V_51 ) ] ++ ;
V_51 -> V_165 += F_223 ( V_244 ) ;
}
static struct V_112 * F_269 ( struct V_50 * V_51 )
{
struct V_112 * V_244 = NULL ;
if ( F_270 ( V_51 ) )
return NULL ;
F_271 ( V_51 ) ;
if ( F_232 ( & V_51 -> V_274 ) )
return NULL ;
V_244 = F_272 ( V_51 -> V_274 . V_133 ) ;
if ( F_91 ( V_109 , V_244 -> V_259 ) )
V_244 = NULL ;
F_88 ( V_51 -> V_47 , V_51 , L_22 , V_244 ) ;
return V_244 ;
}
static inline int
F_273 ( struct V_46 * V_47 , struct V_50 * V_51 )
{
const int V_275 = V_47 -> V_276 ;
F_75 ( V_51 -> V_81 >= V_79 ) ;
return 2 * V_275 * ( V_79 - V_51 -> V_81 ) ;
}
static int F_274 ( struct V_50 * V_51 )
{
int V_277 , V_278 ;
V_278 = V_51 -> V_279 [ V_70 ] + V_51 -> V_279 [ V_280 ] ;
V_277 = V_51 -> V_281 - V_278 ;
F_21 ( V_277 < 0 ) ;
return V_277 ;
}
static void F_275 ( struct V_50 * V_51 , struct V_50 * V_231 )
{
int V_277 , V_282 ;
struct V_50 * V_229 ;
if ( ! F_274 ( V_231 ) )
return;
while ( ( V_229 = V_231 -> V_231 ) ) {
if ( V_229 == V_51 )
return;
V_231 = V_229 ;
}
V_277 = F_274 ( V_51 ) ;
V_282 = F_274 ( V_231 ) ;
if ( V_277 == 0 || V_282 == 0 )
return;
if ( V_282 >= V_277 ) {
V_51 -> V_231 = V_231 ;
V_231 -> V_281 += V_277 ;
} else {
V_231 -> V_231 = V_51 ;
V_51 -> V_281 += V_282 ;
}
}
static enum V_6 F_276 ( struct V_46 * V_47 ,
struct V_2 * V_3 , enum V_4 V_57 )
{
struct V_50 * V_64 ;
int V_166 ;
bool V_283 = false ;
unsigned long V_284 = 0 ;
enum V_6 V_285 = V_55 ;
for ( V_166 = 0 ; V_166 <= V_56 ; ++ V_166 ) {
V_64 = F_97 ( F_1 ( V_3 , V_57 , V_166 ) ) ;
if ( V_64 &&
( ! V_283 || F_91 ( V_64 -> V_230 , V_284 ) ) ) {
V_284 = V_64 -> V_230 ;
V_285 = V_166 ;
V_283 = true ;
}
}
return V_285 ;
}
static void
F_277 ( struct V_46 * V_47 , struct V_2 * V_3 )
{
unsigned V_100 ;
unsigned V_58 ;
struct V_1 * V_89 ;
unsigned V_105 ;
enum V_4 V_286 = V_47 -> V_164 ;
if ( F_61 ( V_52 , V_47 , V_3 ) )
V_47 -> V_164 = V_52 ;
else if ( F_61 ( V_53 , V_47 , V_3 ) )
V_47 -> V_164 = V_53 ;
else {
V_47 -> V_164 = V_7 ;
V_47 -> V_160 = V_109 + 1 ;
return;
}
if ( V_286 != V_47 -> V_164 )
goto V_287;
V_89 = F_1 ( V_3 , V_47 -> V_164 , V_47 -> V_162 ) ;
V_58 = V_89 -> V_58 ;
if ( V_58 && ! F_126 ( V_109 , V_47 -> V_160 ) )
return;
V_287:
V_47 -> V_162 = F_276 ( V_47 , V_3 ,
V_47 -> V_164 ) ;
V_89 = F_1 ( V_3 , V_47 -> V_164 , V_47 -> V_162 ) ;
V_58 = V_89 -> V_58 ;
V_105 = F_85 ( V_47 , V_3 ) ;
V_100 = V_105 * V_58 /
F_118 ( unsigned , V_3 -> V_98 [ V_47 -> V_164 ] ,
F_61 ( V_47 -> V_164 , V_47 ,
V_3 ) ) ;
if ( V_47 -> V_162 == V_54 ) {
unsigned int V_220 ;
V_220 = V_47 -> V_99 *
F_62 ( V_47 , V_3 ) ;
V_220 = V_220 / V_47 -> V_73 ;
V_100 = F_278 ( unsigned , V_100 , V_220 ) ;
V_100 = V_100 * V_47 -> V_78 [ 0 ] / V_47 -> V_78 [ 1 ] ;
} else
V_100 = F_84 ( V_100 , 2 * V_47 -> V_48 ) ;
V_100 = F_118 ( unsigned , V_100 , V_288 ) ;
F_72 ( V_47 , L_23 , V_100 ) ;
V_47 -> V_160 = V_109 + V_100 ;
}
static struct V_2 * F_253 ( struct V_46 * V_47 )
{
struct V_1 * V_89 = & V_47 -> V_151 ;
struct V_2 * V_3 ;
if ( F_214 ( & V_89 -> V_127 ) )
return NULL ;
V_3 = F_100 ( V_89 ) ;
F_80 ( V_89 ) ;
return V_3 ;
}
static void F_279 ( struct V_46 * V_47 )
{
struct V_2 * V_3 = F_253 ( V_47 ) ;
V_47 -> V_246 = V_3 ;
if ( V_3 -> V_153 ) {
V_47 -> V_160 = V_109 + V_3 -> V_153 ;
V_47 -> V_162 = V_3 -> V_161 ;
V_47 -> V_164 = V_3 -> V_163 ;
} else
V_47 -> V_160 = V_109 - 1 ;
F_277 ( V_47 , V_3 ) ;
}
static struct V_50 * F_280 ( struct V_46 * V_47 )
{
struct V_50 * V_51 , * V_231 = NULL ;
V_51 = V_47 -> V_260 ;
if ( ! V_51 )
goto V_289;
if ( ! V_47 -> V_253 )
return NULL ;
if ( F_281 ( V_51 ) && ! F_214 ( & V_51 -> V_135 ) )
goto V_290;
if ( F_89 ( V_51 ) && ! F_282 ( V_51 ) ) {
if ( V_51 -> V_3 -> V_136 == 1 && F_214 ( & V_51 -> V_135 )
&& V_51 -> V_269 && F_259 ( V_47 , V_51 ) ) {
V_51 = NULL ;
goto V_291;
} else
goto V_292;
}
if ( ! F_214 ( & V_51 -> V_135 ) )
goto V_291;
V_231 = F_258 ( V_47 , V_51 ) ;
if ( V_231 ) {
if ( ! V_51 -> V_231 )
F_275 ( V_51 , V_231 ) ;
goto V_290;
}
if ( F_283 ( & V_47 -> V_261 ) ) {
V_51 = NULL ;
goto V_291;
}
if ( F_247 ( V_51 ) && F_60 ( V_51 ) &&
( F_90 ( V_51 ) ||
( V_51 -> V_110 - V_109 > V_109 - V_51 -> V_108 ) ) ) {
F_284 ( V_51 ) ;
F_285 ( V_51 ) ;
}
if ( V_51 -> V_269 && F_259 ( V_47 , V_51 ) ) {
V_51 = NULL ;
goto V_291;
}
V_292:
if ( V_47 -> V_268 && V_51 -> V_3 -> V_136 == 1 &&
V_51 -> V_3 -> V_269 &&
! F_261 ( V_47 , & V_51 -> V_3 -> V_169 , true ) ) {
V_51 = NULL ;
goto V_291;
}
V_290:
F_250 ( V_47 , 0 ) ;
V_289:
if ( ! V_231 )
F_279 ( V_47 ) ;
V_51 = F_254 ( V_47 , V_231 ) ;
V_291:
return V_51 ;
}
static int F_286 ( struct V_50 * V_51 )
{
int V_269 = 0 ;
while ( V_51 -> V_239 ) {
F_267 ( V_51 -> V_47 -> V_64 , V_51 -> V_239 ) ;
V_269 ++ ;
}
F_21 ( ! F_232 ( & V_51 -> V_274 ) ) ;
F_243 ( V_51 -> V_47 , V_51 , 0 ) ;
return V_269 ;
}
static int F_287 ( struct V_46 * V_47 )
{
struct V_50 * V_51 ;
int V_269 = 0 ;
F_250 ( V_47 , 0 ) ;
while ( ( V_51 = F_252 ( V_47 ) ) != NULL ) {
F_237 ( V_47 , V_51 ) ;
V_269 += F_286 ( V_51 ) ;
}
F_21 ( V_47 -> V_73 ) ;
F_72 ( V_47 , L_24 , V_269 ) ;
return V_269 ;
}
static inline bool F_288 ( struct V_46 * V_47 ,
struct V_50 * V_51 )
{
if ( F_90 ( V_51 ) )
return true ;
if ( F_126 ( V_109 + V_47 -> V_48 * V_51 -> V_269 ,
V_51 -> V_110 ) )
return true ;
return false ;
}
static bool F_289 ( struct V_46 * V_47 , struct V_50 * V_51 )
{
unsigned int V_293 ;
if ( F_259 ( V_47 , V_51 ) && V_47 -> V_273 [ V_294 ] )
return false ;
if ( V_47 -> V_273 [ V_295 ] && ! F_59 ( V_51 ) )
return false ;
V_293 = F_118 (unsigned int, cfqd->cfq_quantum / 2 , 1 ) ;
if ( F_56 ( V_51 ) )
V_293 = 1 ;
if ( V_51 -> V_269 >= V_293 ) {
bool V_296 = false ;
if ( F_56 ( V_51 ) )
return false ;
if ( F_59 ( V_51 ) && V_47 -> V_243 == 1 )
V_296 = true ;
if ( V_47 -> V_73 > 1 && F_288 ( V_47 , V_51 ) &&
! V_296 )
return false ;
if ( V_47 -> V_73 == 1 || V_296 )
V_293 = - 1 ;
else
V_293 = V_47 -> V_297 ;
}
if ( ! F_59 ( V_51 ) && V_47 -> V_101 ) {
unsigned long V_298 = V_109 - V_47 -> V_299 ;
unsigned int V_300 ;
V_300 = V_298 / V_47 -> V_78 [ 1 ] ;
if ( ! V_300 && ! V_51 -> V_269 )
V_300 = 1 ;
if ( V_300 < V_293 )
V_293 = V_300 ;
}
return V_51 -> V_269 < V_293 ;
}
static bool F_290 ( struct V_46 * V_47 , struct V_50 * V_51 )
{
struct V_112 * V_244 ;
F_21 ( F_214 ( & V_51 -> V_135 ) ) ;
if ( ! F_289 ( V_47 , V_51 ) )
return false ;
V_244 = F_269 ( V_51 ) ;
if ( ! V_244 )
V_244 = V_51 -> V_239 ;
F_267 ( V_47 -> V_64 , V_244 ) ;
if ( ! V_47 -> V_263 ) {
struct V_59 * V_65 = F_291 ( V_244 ) ;
F_292 ( & V_65 -> V_61 . V_63 -> V_301 ) ;
V_47 -> V_263 = V_65 ;
}
return true ;
}
static int F_293 ( struct V_250 * V_44 , int V_302 )
{
struct V_46 * V_47 = V_44 -> V_67 -> V_68 ;
struct V_50 * V_51 ;
if ( ! V_47 -> V_73 )
return 0 ;
if ( F_53 ( V_302 ) )
return F_287 ( V_47 ) ;
V_51 = F_280 ( V_47 ) ;
if ( ! V_51 )
return 0 ;
if ( ! F_290 ( V_47 , V_51 ) )
return 0 ;
V_51 -> V_159 ++ ;
F_239 ( V_51 ) ;
if ( V_47 -> V_73 > 1 && ( ( ! F_59 ( V_51 ) &&
V_51 -> V_159 >= F_273 ( V_47 , V_51 ) ) ||
F_56 ( V_51 ) ) ) {
V_51 -> V_110 = V_109 + 1 ;
F_250 ( V_47 , 0 ) ;
}
F_88 ( V_47 , V_51 , L_25 ) ;
return 1 ;
}
static void F_149 ( struct V_50 * V_51 )
{
struct V_46 * V_47 = V_51 -> V_47 ;
struct V_2 * V_3 ;
F_21 ( V_51 -> V_281 <= 0 ) ;
V_51 -> V_281 -- ;
if ( V_51 -> V_281 )
return;
F_88 ( V_47 , V_51 , L_26 ) ;
F_21 ( F_98 ( & V_51 -> V_135 ) ) ;
F_21 ( V_51 -> V_279 [ V_70 ] + V_51 -> V_279 [ V_280 ] ) ;
V_3 = V_51 -> V_3 ;
if ( F_53 ( V_47 -> V_260 == V_51 ) ) {
F_243 ( V_47 , V_51 , 0 ) ;
F_71 ( V_47 ) ;
}
F_21 ( F_206 ( V_51 ) ) ;
F_294 ( V_303 , V_51 ) ;
F_36 ( V_3 ) ;
}
static void F_295 ( struct V_50 * V_51 )
{
struct V_50 * V_229 , * V_133 ;
V_229 = V_51 -> V_231 ;
while ( V_229 ) {
if ( V_229 == V_51 ) {
F_296 ( 1 , L_27 ) ;
break;
}
V_133 = V_229 -> V_231 ;
F_149 ( V_229 ) ;
V_229 = V_133 ;
}
}
static void F_297 ( struct V_46 * V_47 , struct V_50 * V_51 )
{
if ( F_53 ( V_51 == V_47 -> V_260 ) ) {
F_243 ( V_47 , V_51 , 0 ) ;
F_71 ( V_47 ) ;
}
F_295 ( V_51 ) ;
F_149 ( V_51 ) ;
}
static void F_298 ( struct V_60 * V_61 )
{
struct V_59 * V_65 = F_63 ( V_61 ) ;
V_65 -> V_169 . V_170 = V_109 ;
}
static void F_299 ( struct V_60 * V_61 )
{
struct V_59 * V_65 = F_63 ( V_61 ) ;
struct V_46 * V_47 = F_68 ( V_65 ) ;
if ( F_66 ( V_65 , false ) ) {
F_297 ( V_47 , F_66 ( V_65 , false ) ) ;
F_67 ( V_65 , NULL , false ) ;
}
if ( F_66 ( V_65 , true ) ) {
F_297 ( V_47 , F_66 ( V_65 , true ) ) ;
F_67 ( V_65 , NULL , true ) ;
}
}
static void F_300 ( struct V_50 * V_51 , struct V_59 * V_65 )
{
struct V_247 * V_248 = V_249 ;
int V_304 ;
if ( ! F_301 ( V_51 ) )
return;
V_304 = F_302 ( V_65 -> V_81 ) ;
switch ( V_304 ) {
default:
F_303 ( V_305 L_28 , V_304 ) ;
case V_306 :
V_51 -> V_81 = F_304 ( V_248 ) ;
V_51 -> V_304 = F_305 ( V_248 ) ;
break;
case V_307 :
V_51 -> V_81 = F_306 ( V_65 -> V_81 ) ;
V_51 -> V_304 = V_307 ;
break;
case V_308 :
V_51 -> V_81 = F_306 ( V_65 -> V_81 ) ;
V_51 -> V_304 = V_308 ;
break;
case V_309 :
V_51 -> V_304 = V_309 ;
V_51 -> V_81 = 7 ;
F_285 ( V_51 ) ;
break;
}
V_51 -> V_242 = V_51 -> V_81 ;
F_307 ( V_51 ) ;
}
static void F_308 ( struct V_59 * V_65 , struct V_69 * V_69 )
{
int V_81 = V_65 -> V_61 . V_63 -> V_81 ;
struct V_46 * V_47 = F_68 ( V_65 ) ;
struct V_50 * V_51 ;
if ( F_53 ( ! V_47 ) || F_154 ( V_65 -> V_81 == V_81 ) )
return;
V_51 = F_66 ( V_65 , false ) ;
if ( V_51 ) {
F_149 ( V_51 ) ;
V_51 = F_309 ( V_47 , V_294 , V_65 , V_69 ) ;
F_67 ( V_65 , V_51 , false ) ;
}
V_51 = F_66 ( V_65 , true ) ;
if ( V_51 )
F_310 ( V_51 ) ;
V_65 -> V_81 = V_81 ;
}
static void F_311 ( struct V_46 * V_47 , struct V_50 * V_51 ,
T_9 V_310 , bool V_66 )
{
F_103 ( & V_51 -> V_128 ) ;
F_103 ( & V_51 -> V_238 ) ;
F_312 ( & V_51 -> V_274 ) ;
V_51 -> V_281 = 0 ;
V_51 -> V_47 = V_47 ;
F_310 ( V_51 ) ;
if ( V_66 ) {
if ( ! F_56 ( V_51 ) )
F_313 ( V_51 ) ;
F_314 ( V_51 ) ;
}
V_51 -> V_310 = V_310 ;
}
static void F_315 ( struct V_59 * V_65 , struct V_69 * V_69 )
{
struct V_46 * V_47 = F_68 ( V_65 ) ;
struct V_50 * V_51 ;
T_1 V_311 ;
F_316 () ;
V_311 = F_317 ( V_69 ) -> V_181 . V_311 ;
F_318 () ;
if ( F_53 ( ! V_47 ) || F_154 ( V_65 -> V_312 == V_311 ) )
return;
V_51 = F_66 ( V_65 , false ) ;
if ( V_51 ) {
F_88 ( V_47 , V_51 , L_29 ) ;
F_67 ( V_65 , NULL , false ) ;
F_149 ( V_51 ) ;
}
V_51 = F_66 ( V_65 , true ) ;
if ( V_51 ) {
F_88 ( V_47 , V_51 , L_29 ) ;
F_67 ( V_65 , NULL , true ) ;
F_149 ( V_51 ) ;
}
V_65 -> V_312 = V_311 ;
}
static inline void F_315 ( struct V_59 * V_65 , struct V_69 * V_69 ) { }
static struct V_50 * *
F_319 ( struct V_2 * V_3 , int V_304 , int V_81 )
{
switch ( V_304 ) {
case V_307 :
return & V_3 -> V_182 [ 0 ] [ V_81 ] ;
case V_306 :
V_81 = V_313 ;
case V_308 :
return & V_3 -> V_182 [ 1 ] [ V_81 ] ;
case V_309 :
return & V_3 -> V_183 ;
default:
F_320 () ;
}
}
static struct V_50 *
F_309 ( struct V_46 * V_47 , bool V_66 , struct V_59 * V_65 ,
struct V_69 * V_69 )
{
int V_304 = F_302 ( V_65 -> V_81 ) ;
int V_81 = F_306 ( V_65 -> V_81 ) ;
struct V_50 * * V_182 = NULL ;
struct V_50 * V_51 ;
struct V_2 * V_3 ;
F_316 () ;
V_3 = F_152 ( V_47 , F_317 ( V_69 ) ) ;
if ( ! V_3 ) {
V_51 = & V_47 -> V_314 ;
goto V_211;
}
if ( ! V_66 ) {
if ( ! F_321 ( V_65 -> V_81 ) ) {
struct V_247 * V_248 = V_249 ;
V_81 = F_304 ( V_248 ) ;
V_304 = F_305 ( V_248 ) ;
}
V_182 = F_319 ( V_3 , V_304 , V_81 ) ;
V_51 = * V_182 ;
if ( V_51 )
goto V_211;
}
V_51 = F_322 ( V_303 , V_315 | V_316 ,
V_47 -> V_64 -> V_137 ) ;
if ( ! V_51 ) {
V_51 = & V_47 -> V_314 ;
goto V_211;
}
F_311 ( V_47 , V_51 , V_249 -> V_310 , V_66 ) ;
F_300 ( V_51 , V_65 ) ;
F_155 ( V_51 , V_3 ) ;
F_88 ( V_47 , V_51 , L_30 ) ;
if ( V_182 ) {
V_51 -> V_281 ++ ;
* V_182 = V_51 ;
}
V_211:
V_51 -> V_281 ++ ;
F_318 () ;
return V_51 ;
}
static void
F_323 ( struct V_317 * V_169 , unsigned long V_318 )
{
unsigned long V_319 = V_109 - V_169 -> V_170 ;
V_319 = F_83 ( V_319 , 2UL * V_318 ) ;
V_169 -> V_271 = ( 7 * V_169 -> V_271 + 256 ) / 8 ;
V_169 -> V_320 = ( 7 * V_169 -> V_320 + 256 * V_319 ) / 8 ;
V_169 -> V_272 = ( V_169 -> V_320 + 128 ) / V_169 -> V_271 ;
}
static void
F_324 ( struct V_46 * V_47 , struct V_50 * V_51 ,
struct V_59 * V_65 )
{
if ( F_59 ( V_51 ) ) {
F_323 ( & V_65 -> V_169 , V_47 -> V_48 ) ;
F_323 ( & V_51 -> V_234 -> V_169 ,
V_47 -> V_48 ) ;
}
#ifdef F_325
F_323 ( & V_51 -> V_3 -> V_169 , V_47 -> V_268 ) ;
#endif
}
static void
F_326 ( struct V_46 * V_47 , struct V_50 * V_51 ,
struct V_112 * V_244 )
{
T_4 V_321 = 0 ;
T_4 V_322 = F_223 ( V_244 ) ;
if ( V_51 -> V_323 ) {
if ( V_51 -> V_323 < F_96 ( V_244 ) )
V_321 = F_96 ( V_244 ) - V_51 -> V_323 ;
else
V_321 = V_51 -> V_323 - F_96 ( V_244 ) ;
}
V_51 -> V_324 <<= 1 ;
if ( F_260 ( V_47 -> V_64 ) )
V_51 -> V_324 |= ( V_322 < V_325 ) ;
else
V_51 -> V_324 |= ( V_321 > V_326 ) ;
}
static void
F_327 ( struct V_46 * V_47 , struct V_50 * V_51 ,
struct V_59 * V_65 )
{
int V_327 , V_328 ;
if ( ! F_59 ( V_51 ) || F_56 ( V_51 ) )
return;
V_328 = V_327 = F_60 ( V_51 ) ;
if ( V_51 -> V_19 [ 0 ] + V_51 -> V_19 [ 1 ] >= 4 )
F_328 ( V_51 ) ;
if ( V_51 -> V_239 && ( V_51 -> V_239 -> V_122 & V_329 ) )
V_328 = 0 ;
else if ( ! F_263 ( & V_65 -> V_61 . V_63 -> V_270 ) ||
! V_47 -> V_48 ||
( ! F_329 ( V_51 ) && F_247 ( V_51 ) ) )
V_328 = 0 ;
else if ( F_264 ( V_65 -> V_169 . V_271 ) ) {
if ( V_65 -> V_169 . V_272 > V_47 -> V_48 )
V_328 = 0 ;
else
V_328 = 1 ;
}
if ( V_327 != V_328 ) {
F_88 ( V_47 , V_51 , L_31 , V_328 ) ;
if ( V_328 )
F_313 ( V_51 ) ;
else
F_285 ( V_51 ) ;
}
}
static bool
F_330 ( struct V_46 * V_47 , struct V_50 * V_231 ,
struct V_112 * V_244 )
{
struct V_50 * V_51 ;
V_51 = V_47 -> V_260 ;
if ( ! V_51 )
return false ;
if ( F_56 ( V_231 ) )
return false ;
if ( F_56 ( V_51 ) )
return true ;
if ( F_57 ( V_51 ) && ! F_57 ( V_231 ) )
return false ;
if ( F_95 ( V_244 ) && ! F_59 ( V_51 ) )
return true ;
if ( V_231 -> V_3 != V_51 -> V_3 )
return false ;
if ( F_89 ( V_51 ) )
return true ;
if ( V_47 -> V_162 == V_55 &&
F_58 ( V_231 ) == V_55 &&
V_231 -> V_234 -> V_58 == 2 &&
F_214 ( & V_51 -> V_135 ) )
return true ;
if ( ( V_244 -> V_122 & V_123 ) && ! V_51 -> V_254 )
return true ;
if ( F_57 ( V_231 ) && ! F_57 ( V_51 ) )
return true ;
if ( F_214 ( & V_51 -> V_135 ) && ! F_259 ( V_47 , V_51 ) )
return true ;
if ( ! V_47 -> V_263 || ! F_244 ( V_51 ) )
return false ;
if ( F_256 ( V_47 , V_51 , V_244 ) )
return true ;
return false ;
}
static void F_331 ( struct V_46 * V_47 , struct V_50 * V_51 )
{
enum V_6 V_330 = F_58 ( V_47 -> V_260 ) ;
F_88 ( V_47 , V_51 , L_32 ) ;
F_250 ( V_47 , 1 ) ;
if ( V_330 != F_58 ( V_51 ) )
V_51 -> V_3 -> V_153 = 0 ;
F_21 ( ! F_206 ( V_51 ) ) ;
F_202 ( V_47 , V_51 , 1 ) ;
V_51 -> V_110 = 0 ;
F_242 ( V_51 ) ;
}
static void
F_332 ( struct V_46 * V_47 , struct V_50 * V_51 ,
struct V_112 * V_244 )
{
struct V_59 * V_65 = F_291 ( V_244 ) ;
V_47 -> V_253 ++ ;
if ( V_244 -> V_122 & V_123 )
V_51 -> V_254 ++ ;
F_324 ( V_47 , V_51 , V_65 ) ;
F_326 ( V_47 , V_51 , V_244 ) ;
F_327 ( V_47 , V_51 , V_65 ) ;
V_51 -> V_323 = F_96 ( V_244 ) + F_223 ( V_244 ) ;
if ( V_51 == V_47 -> V_260 ) {
if ( F_244 ( V_51 ) ) {
if ( F_333 ( V_244 ) > V_331 ||
V_47 -> V_73 > 1 ) {
F_235 ( V_47 , V_51 ) ;
F_238 ( V_51 ) ;
F_334 ( V_47 -> V_64 ) ;
} else {
F_17 ( V_51 -> V_3 ) ;
F_335 ( V_51 ) ;
}
}
} else if ( F_330 ( V_47 , V_51 , V_244 ) ) {
F_331 ( V_47 , V_51 ) ;
F_334 ( V_47 -> V_64 ) ;
}
}
static void F_336 ( struct V_250 * V_44 , struct V_112 * V_244 )
{
struct V_46 * V_47 = V_44 -> V_67 -> V_68 ;
struct V_50 * V_51 = F_212 ( V_244 ) ;
F_88 ( V_47 , V_51 , L_33 ) ;
F_300 ( V_51 , F_291 ( V_244 ) ) ;
V_244 -> V_259 = V_109 + V_47 -> V_332 [ F_95 ( V_244 ) ] ;
F_337 ( & V_244 -> V_252 , & V_51 -> V_274 ) ;
F_215 ( V_244 ) ;
F_38 ( F_218 ( V_244 ) , V_47 -> V_246 ,
V_244 -> V_122 ) ;
F_332 ( V_47 , V_51 , V_244 ) ;
}
static void F_338 ( struct V_46 * V_47 )
{
struct V_50 * V_51 = V_47 -> V_260 ;
if ( V_47 -> V_251 > V_47 -> V_333 )
V_47 -> V_333 = V_47 -> V_251 ;
if ( V_47 -> V_49 == 1 )
return;
if ( V_47 -> V_253 <= V_334 &&
V_47 -> V_251 <= V_334 )
return;
if ( V_51 && F_60 ( V_51 ) &&
V_51 -> V_269 + V_51 -> V_19 [ 0 ] + V_51 -> V_19 [ 1 ] <
V_334 && V_47 -> V_251 < V_334 )
return;
if ( V_47 -> V_335 ++ < 50 )
return;
if ( V_47 -> V_333 >= V_334 )
V_47 -> V_49 = 1 ;
else
V_47 -> V_49 = 0 ;
}
static bool F_339 ( struct V_46 * V_47 , struct V_50 * V_51 )
{
struct V_59 * V_65 = V_47 -> V_263 ;
if ( ! F_214 ( & V_51 -> V_135 ) )
return false ;
if ( V_51 -> V_3 -> V_136 > 1 )
return false ;
if ( F_261 ( V_47 , & V_51 -> V_3 -> V_169 , true ) )
return false ;
if ( F_89 ( V_51 ) )
return true ;
if ( V_65 && F_264 ( V_65 -> V_169 . V_271 )
&& ( V_51 -> V_110 - V_109 < V_65 -> V_169 . V_272 ) )
return true ;
if ( V_51 -> V_110 - V_109 == 1 )
return true ;
return false ;
}
static void F_340 ( struct V_250 * V_44 , struct V_112 * V_244 )
{
struct V_50 * V_51 = F_212 ( V_244 ) ;
struct V_46 * V_47 = V_51 -> V_47 ;
const int V_75 = F_95 ( V_244 ) ;
unsigned long V_12 ;
V_12 = V_109 ;
F_88 ( V_47 , V_51 , L_34 ,
! ! ( V_244 -> V_122 & V_329 ) ) ;
F_338 ( V_47 ) ;
F_75 ( ! V_47 -> V_251 ) ;
F_75 ( ! V_51 -> V_269 ) ;
V_47 -> V_251 -- ;
V_51 -> V_269 -- ;
( F_218 ( V_244 ) ) -> V_269 -- ;
F_44 ( V_51 -> V_3 , F_341 ( V_244 ) ,
F_342 ( V_244 ) , V_244 -> V_122 ) ;
V_47 -> V_273 [ F_59 ( V_51 ) ] -- ;
if ( V_75 ) {
struct V_1 * V_89 ;
F_291 ( V_244 ) -> V_169 . V_170 = V_12 ;
if ( F_206 ( V_51 ) )
V_89 = V_51 -> V_234 ;
else
V_89 = F_1 ( V_51 -> V_3 , F_55 ( V_51 ) ,
F_58 ( V_51 ) ) ;
V_89 -> V_169 . V_170 = V_12 ;
if ( ! F_126 ( V_244 -> V_38 + V_47 -> V_332 [ 1 ] , V_12 ) )
V_47 -> V_299 = V_12 ;
}
#ifdef F_325
V_51 -> V_3 -> V_169 . V_170 = V_12 ;
#endif
if ( V_47 -> V_260 == V_51 ) {
const bool V_336 = F_214 ( & V_51 -> V_135 ) ;
if ( F_90 ( V_51 ) ) {
F_87 ( V_47 , V_51 ) ;
F_343 ( V_51 ) ;
}
if ( F_339 ( V_47 , V_51 ) ) {
unsigned long V_337 = V_47 -> V_48 ;
if ( ! V_47 -> V_48 )
V_337 = V_47 -> V_268 ;
V_51 -> V_110 = V_109 + V_337 ;
F_344 ( V_51 ) ;
F_88 ( V_47 , V_51 , L_35 ) ;
}
if ( F_89 ( V_51 ) || F_56 ( V_51 ) )
F_250 ( V_47 , 1 ) ;
else if ( V_75 && V_336 &&
! F_258 ( V_47 , V_51 ) ) {
F_262 ( V_47 ) ;
}
}
if ( ! V_47 -> V_251 )
F_71 ( V_47 ) ;
}
static inline int F_345 ( struct V_50 * V_51 )
{
if ( F_244 ( V_51 ) && ! F_346 ( V_51 ) ) {
F_347 ( V_51 ) ;
return V_338 ;
}
return V_339 ;
}
static int F_348 ( struct V_250 * V_44 , int V_35 )
{
struct V_46 * V_47 = V_44 -> V_67 -> V_68 ;
struct V_247 * V_248 = V_249 ;
struct V_59 * V_65 ;
struct V_50 * V_51 ;
V_65 = F_64 ( V_47 , V_248 -> V_62 ) ;
if ( ! V_65 )
return V_339 ;
V_51 = F_66 ( V_65 , F_349 ( V_35 ) ) ;
if ( V_51 ) {
F_300 ( V_51 , V_65 ) ;
return F_345 ( V_51 ) ;
}
return V_339 ;
}
static void F_350 ( struct V_112 * V_244 )
{
struct V_50 * V_51 = F_212 ( V_244 ) ;
if ( V_51 ) {
const int V_35 = F_351 ( V_244 ) ;
F_21 ( ! V_51 -> V_279 [ V_35 ] ) ;
V_51 -> V_279 [ V_35 ] -- ;
F_36 ( F_218 ( V_244 ) ) ;
V_244 -> V_340 . V_341 [ 0 ] = NULL ;
V_244 -> V_340 . V_341 [ 1 ] = NULL ;
F_149 ( V_51 ) ;
}
}
static struct V_50 *
F_352 ( struct V_46 * V_47 , struct V_59 * V_65 ,
struct V_50 * V_51 )
{
F_88 ( V_47 , V_51 , L_36 , V_51 -> V_231 ) ;
F_67 ( V_65 , V_51 -> V_231 , 1 ) ;
F_353 ( V_51 -> V_231 ) ;
F_149 ( V_51 ) ;
return F_66 ( V_65 , 1 ) ;
}
static struct V_50 *
F_354 ( struct V_59 * V_65 , struct V_50 * V_51 )
{
if ( F_274 ( V_51 ) == 1 ) {
V_51 -> V_310 = V_249 -> V_310 ;
F_355 ( V_51 ) ;
F_356 ( V_51 ) ;
return V_51 ;
}
F_67 ( V_65 , NULL , 1 ) ;
F_295 ( V_51 ) ;
F_149 ( V_51 ) ;
return NULL ;
}
static int
F_357 ( struct V_250 * V_44 , struct V_112 * V_244 , struct V_69 * V_69 ,
T_5 V_342 )
{
struct V_46 * V_47 = V_44 -> V_67 -> V_68 ;
struct V_59 * V_65 = F_63 ( V_244 -> V_340 . V_61 ) ;
const int V_35 = F_351 ( V_244 ) ;
const bool V_66 = F_95 ( V_244 ) ;
struct V_50 * V_51 ;
F_174 ( V_44 -> V_45 ) ;
F_308 ( V_65 , V_69 ) ;
F_315 ( V_65 , V_69 ) ;
V_289:
V_51 = F_66 ( V_65 , V_66 ) ;
if ( ! V_51 || V_51 == & V_47 -> V_314 ) {
if ( V_51 )
F_149 ( V_51 ) ;
V_51 = F_309 ( V_47 , V_66 , V_65 , V_69 ) ;
F_67 ( V_65 , V_51 , V_66 ) ;
} else {
if ( F_246 ( V_51 ) && F_358 ( V_51 ) ) {
F_88 ( V_47 , V_51 , L_37 ) ;
V_51 = F_354 ( V_65 , V_51 ) ;
if ( ! V_51 )
goto V_289;
}
if ( V_51 -> V_231 )
V_51 = F_352 ( V_47 , V_65 , V_51 ) ;
}
V_51 -> V_279 [ V_35 ] ++ ;
V_51 -> V_281 ++ ;
F_34 ( V_51 -> V_3 ) ;
V_244 -> V_340 . V_341 [ 0 ] = V_51 ;
V_244 -> V_340 . V_341 [ 1 ] = V_51 -> V_3 ;
F_176 ( V_44 -> V_45 ) ;
return 0 ;
}
static void F_359 ( struct V_343 * V_344 )
{
struct V_46 * V_47 =
F_25 ( V_344 , struct V_46 , V_74 ) ;
struct V_250 * V_44 = V_47 -> V_64 ;
F_174 ( V_44 -> V_45 ) ;
F_334 ( V_47 -> V_64 ) ;
F_176 ( V_44 -> V_45 ) ;
}
static void F_360 ( unsigned long V_345 )
{
struct V_46 * V_47 = (struct V_46 * ) V_345 ;
struct V_50 * V_51 ;
unsigned long V_346 ;
int V_262 = 1 ;
F_72 ( V_47 , L_38 ) ;
F_361 ( V_47 -> V_64 -> V_45 , V_346 ) ;
V_51 = V_47 -> V_260 ;
if ( V_51 ) {
V_262 = 0 ;
if ( F_282 ( V_51 ) )
goto V_347;
if ( F_89 ( V_51 ) )
goto V_290;
if ( ! V_47 -> V_73 )
goto V_348;
if ( ! F_214 ( & V_51 -> V_135 ) )
goto V_347;
F_284 ( V_51 ) ;
}
V_290:
F_250 ( V_47 , V_262 ) ;
V_347:
F_71 ( V_47 ) ;
V_348:
F_362 ( V_47 -> V_64 -> V_45 , V_346 ) ;
}
static void F_363 ( struct V_46 * V_47 )
{
F_364 ( & V_47 -> V_261 ) ;
F_365 ( & V_47 -> V_74 ) ;
}
static void F_366 ( struct V_349 * V_350 )
{
struct V_46 * V_47 = V_350 -> V_68 ;
struct V_250 * V_44 = V_47 -> V_64 ;
F_363 ( V_47 ) ;
F_174 ( V_44 -> V_45 ) ;
if ( V_47 -> V_260 )
F_243 ( V_47 , V_47 -> V_260 , 0 ) ;
F_176 ( V_44 -> V_45 ) ;
F_363 ( V_47 ) ;
#ifdef F_325
F_367 ( V_44 , & V_31 ) ;
#else
F_142 ( V_47 -> V_226 ) ;
#endif
F_142 ( V_47 ) ;
}
static int F_368 ( struct V_250 * V_44 , struct V_351 * V_350 )
{
struct V_46 * V_47 ;
struct V_29 * V_30 V_352 ;
int V_166 , V_203 ;
struct V_349 * V_353 ;
V_353 = F_369 ( V_44 , V_350 ) ;
if ( ! V_353 )
return - V_173 ;
V_47 = F_146 ( sizeof( * V_47 ) , V_175 , V_44 -> V_137 ) ;
if ( ! V_47 ) {
F_370 ( & V_353 -> V_354 ) ;
return - V_173 ;
}
V_353 -> V_68 = V_47 ;
V_47 -> V_64 = V_44 ;
F_174 ( V_44 -> V_45 ) ;
V_44 -> V_67 = V_353 ;
F_176 ( V_44 -> V_45 ) ;
V_47 -> V_151 = V_168 ;
#ifdef F_325
V_203 = F_371 ( V_44 , & V_31 ) ;
if ( V_203 )
goto V_355;
V_47 -> V_226 = F_29 ( V_44 -> V_356 ) ;
#else
V_203 = - V_173 ;
V_47 -> V_226 = F_146 ( sizeof( * V_47 -> V_226 ) ,
V_175 , V_47 -> V_64 -> V_137 ) ;
if ( ! V_47 -> V_226 )
goto V_355;
F_128 ( V_47 -> V_226 ) ;
V_47 -> V_226 -> V_143 = 2 * V_178 ;
V_47 -> V_226 -> V_145 = 2 * V_178 ;
#endif
for ( V_166 = 0 ; V_166 < V_357 ; V_166 ++ )
V_47 -> V_241 [ V_166 ] = V_358 ;
F_311 ( V_47 , & V_47 -> V_314 , 1 , 0 ) ;
V_47 -> V_314 . V_281 ++ ;
F_174 ( V_44 -> V_45 ) ;
F_155 ( & V_47 -> V_314 , V_47 -> V_226 ) ;
F_36 ( V_47 -> V_226 ) ;
F_176 ( V_44 -> V_45 ) ;
F_372 ( & V_47 -> V_261 ) ;
V_47 -> V_261 . V_359 = F_360 ;
V_47 -> V_261 . V_345 = ( unsigned long ) V_47 ;
F_373 ( & V_47 -> V_74 , F_359 ) ;
V_47 -> V_297 = V_297 ;
V_47 -> V_332 [ 0 ] = V_332 [ 0 ] ;
V_47 -> V_332 [ 1 ] = V_332 [ 1 ] ;
V_47 -> V_124 = V_124 ;
V_47 -> V_125 = V_125 ;
V_47 -> V_78 [ 0 ] = V_360 ;
V_47 -> V_78 [ 1 ] = V_361 ;
V_47 -> V_99 = V_99 ;
V_47 -> V_276 = V_276 ;
V_47 -> V_48 = V_48 ;
V_47 -> V_268 = V_268 ;
V_47 -> V_101 = 1 ;
V_47 -> V_49 = - 1 ;
V_47 -> V_299 = V_109 - V_233 ;
return 0 ;
V_355:
F_142 ( V_47 ) ;
F_370 ( & V_353 -> V_354 ) ;
return V_203 ;
}
static void F_374 ( struct V_250 * V_44 )
{
struct V_349 * V_350 = V_44 -> V_67 ;
struct V_46 * V_47 = V_350 -> V_68 ;
if ( F_260 ( V_44 ) )
V_47 -> V_48 = 0 ;
}
static T_6
F_375 ( unsigned int V_362 , char * V_363 )
{
return sprintf ( V_363 , L_6 , V_362 ) ;
}
static T_6
F_376 ( unsigned int * V_362 , const char * V_363 , T_7 V_58 )
{
char * V_228 = ( char * ) V_363 ;
* V_362 = F_377 ( V_228 , & V_228 , 10 ) ;
return V_58 ;
}
static int T_10 F_378 ( void )
{
int V_203 ;
if ( ! V_360 )
V_360 = 1 ;
if ( ! V_48 )
V_48 = 1 ;
#ifdef F_325
if ( ! V_268 )
V_268 = 1 ;
V_203 = F_379 ( & V_31 ) ;
if ( V_203 )
return V_203 ;
#else
V_268 = 0 ;
#endif
V_203 = - V_173 ;
V_303 = F_380 ( V_50 , 0 ) ;
if ( ! V_303 )
goto V_364;
V_203 = F_381 ( & V_365 ) ;
if ( V_203 )
goto V_366;
return 0 ;
V_366:
F_382 ( V_303 ) ;
V_364:
#ifdef F_325
F_383 ( & V_31 ) ;
#endif
return V_203 ;
}
static void T_11 F_384 ( void )
{
#ifdef F_325
F_383 ( & V_31 ) ;
#endif
F_385 ( & V_365 ) ;
F_382 ( V_303 ) ;
}
