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
static inline struct V_2 * F_2 ( struct V_10 * V_11 )
{
return V_11 ? F_3 ( V_11 , struct V_2 , V_11 ) : NULL ;
}
static inline struct V_12 * F_4 ( struct V_2 * V_3 )
{
return F_5 ( & V_3 -> V_11 ) ;
}
static void F_6 ( struct V_13 * V_14 )
{
unsigned long long V_15 ;
if ( ! F_7 ( V_14 ) )
return;
V_15 = F_8 () ;
if ( F_9 ( V_15 , V_14 -> V_16 ) )
F_10 ( & V_14 -> V_17 ,
V_15 - V_14 -> V_16 ) ;
F_11 ( V_14 ) ;
}
static void F_12 ( struct V_2 * V_3 ,
struct V_2 * V_18 )
{
struct V_13 * V_14 = & V_3 -> V_14 ;
if ( F_7 ( V_14 ) )
return;
if ( V_3 == V_18 )
return;
V_14 -> V_16 = F_8 () ;
F_13 ( V_14 ) ;
}
static void F_14 ( struct V_13 * V_14 )
{
unsigned long long V_15 ;
if ( ! F_15 ( V_14 ) )
return;
V_15 = F_8 () ;
if ( F_9 ( V_15 , V_14 -> V_19 ) )
F_10 ( & V_14 -> V_20 ,
V_15 - V_14 -> V_19 ) ;
F_16 ( V_14 ) ;
}
static void F_17 ( struct V_2 * V_3 )
{
F_10 ( & V_3 -> V_14 . V_21 , 1 ) ;
}
static void F_18 ( struct V_2 * V_3 )
{
struct V_13 * V_14 = & V_3 -> V_14 ;
if ( F_19 ( & V_14 -> V_22 ) )
return;
if ( F_15 ( V_14 ) )
return;
V_14 -> V_19 = F_8 () ;
F_20 ( V_14 ) ;
}
static void F_21 ( struct V_2 * V_3 )
{
struct V_13 * V_14 = & V_3 -> V_14 ;
if ( F_22 ( V_14 ) ) {
unsigned long long V_15 = F_8 () ;
if ( F_9 ( V_15 , V_14 -> V_23 ) )
F_10 ( & V_14 -> V_24 ,
V_15 - V_14 -> V_23 ) ;
F_23 ( V_14 ) ;
}
}
static void F_24 ( struct V_2 * V_3 )
{
struct V_13 * V_14 = & V_3 -> V_14 ;
F_25 ( F_22 ( V_14 ) ) ;
V_14 -> V_23 = F_8 () ;
F_26 ( V_14 ) ;
}
static void F_27 ( struct V_2 * V_3 )
{
struct V_13 * V_14 = & V_3 -> V_14 ;
F_10 ( & V_14 -> V_25 ,
F_19 ( & V_14 -> V_22 ) ) ;
F_10 ( & V_14 -> V_26 , 1 ) ;
F_6 ( V_14 ) ;
}
static inline void F_12 ( struct V_2 * V_3 , struct V_2 * V_18 ) { }
static inline void F_14 ( struct V_13 * V_14 ) { }
static inline void F_17 ( struct V_2 * V_3 ) { }
static inline void F_18 ( struct V_2 * V_3 ) { }
static inline void F_21 ( struct V_2 * V_3 ) { }
static inline void F_24 ( struct V_2 * V_3 ) { }
static inline void F_27 ( struct V_2 * V_3 ) { }
static inline struct V_2 * F_28 ( struct V_12 * V_27 )
{
return F_2 ( F_29 ( V_27 , & V_28 ) ) ;
}
static inline struct V_2 * F_30 ( struct V_2 * V_3 )
{
struct V_12 * V_29 = F_4 ( V_3 ) -> V_30 ;
return V_29 ? F_28 ( V_29 ) : NULL ;
}
static inline void F_31 ( struct V_2 * V_3 )
{
return F_32 ( F_4 ( V_3 ) ) ;
}
static inline void F_33 ( struct V_2 * V_3 )
{
return F_34 ( F_4 ( V_3 ) ) ;
}
static inline void F_35 ( struct V_2 * V_3 ,
struct V_2 * V_18 , int V_31 )
{
F_36 ( & V_3 -> V_14 . V_22 , V_31 , 1 ) ;
F_14 ( & V_3 -> V_14 ) ;
F_12 ( V_3 , V_18 ) ;
}
static inline void F_37 ( struct V_2 * V_3 ,
unsigned long time , unsigned long V_32 )
{
F_10 ( & V_3 -> V_14 . time , time ) ;
#ifdef F_38
F_10 ( & V_3 -> V_14 . V_32 , V_32 ) ;
#endif
}
static inline void F_39 ( struct V_2 * V_3 , int V_31 )
{
F_36 ( & V_3 -> V_14 . V_22 , V_31 , - 1 ) ;
}
static inline void F_40 ( struct V_2 * V_3 , int V_31 )
{
F_36 ( & V_3 -> V_14 . V_33 , V_31 , 1 ) ;
}
static inline void F_41 ( struct V_2 * V_3 ,
T_1 V_34 , int V_31 )
{
F_10 ( & V_3 -> V_14 . V_35 , V_34 >> 9 ) ;
F_36 ( & V_3 -> V_14 . V_36 , V_31 , 1 ) ;
F_36 ( & V_3 -> V_14 . V_37 , V_31 , V_34 ) ;
}
static inline void F_42 ( struct V_2 * V_3 ,
T_1 V_38 , T_1 V_39 , int V_31 )
{
struct V_13 * V_14 = & V_3 -> V_14 ;
unsigned long long V_15 = F_8 () ;
if ( F_9 ( V_15 , V_39 ) )
F_36 ( & V_14 -> V_40 , V_31 , V_15 - V_39 ) ;
if ( F_9 ( V_39 , V_38 ) )
F_36 ( & V_14 -> V_41 , V_31 ,
V_39 - V_38 ) ;
}
static void F_43 ( struct V_13 * V_14 )
{
F_44 ( & V_14 -> V_37 ) ;
F_44 ( & V_14 -> V_36 ) ;
F_44 ( & V_14 -> V_33 ) ;
F_44 ( & V_14 -> V_40 ) ;
F_44 ( & V_14 -> V_41 ) ;
F_45 ( & V_14 -> time ) ;
#ifdef F_38
F_45 ( & V_14 -> V_32 ) ;
F_45 ( & V_14 -> V_25 ) ;
F_45 ( & V_14 -> V_26 ) ;
F_45 ( & V_14 -> V_21 ) ;
F_45 ( & V_14 -> V_17 ) ;
F_45 ( & V_14 -> V_24 ) ;
F_45 ( & V_14 -> V_20 ) ;
#endif
}
static void F_46 ( struct V_13 * V_42 , struct V_13 * V_43 )
{
F_47 ( & V_42 -> V_37 , & V_43 -> V_37 ) ;
F_47 ( & V_42 -> V_36 , & V_43 -> V_36 ) ;
F_47 ( & V_42 -> V_33 , & V_43 -> V_33 ) ;
F_47 ( & V_42 -> V_40 , & V_43 -> V_40 ) ;
F_47 ( & V_42 -> V_41 , & V_43 -> V_41 ) ;
F_48 ( & V_43 -> time , & V_43 -> time ) ;
#ifdef F_38
F_48 ( & V_42 -> V_32 , & V_43 -> V_32 ) ;
F_48 ( & V_42 -> V_25 , & V_43 -> V_25 ) ;
F_48 ( & V_42 -> V_26 , & V_43 -> V_26 ) ;
F_48 ( & V_42 -> V_21 , & V_43 -> V_21 ) ;
F_48 ( & V_42 -> V_17 , & V_43 -> V_17 ) ;
F_48 ( & V_42 -> V_24 , & V_43 -> V_24 ) ;
F_48 ( & V_42 -> V_20 , & V_43 -> V_20 ) ;
#endif
}
static void F_49 ( struct V_2 * V_3 )
{
struct V_2 * V_30 = F_30 ( V_3 ) ;
F_50 ( F_4 ( V_3 ) -> V_44 -> V_45 ) ;
if ( F_51 ( ! V_30 ) )
return;
F_46 ( & V_30 -> V_46 , & V_3 -> V_14 ) ;
F_46 ( & V_30 -> V_46 , & V_3 -> V_46 ) ;
F_43 ( & V_3 -> V_14 ) ;
F_43 ( & V_3 -> V_46 ) ;
}
static inline struct V_2 * F_30 ( struct V_2 * V_3 ) { return NULL ; }
static inline void F_31 ( struct V_2 * V_3 ) { }
static inline void F_33 ( struct V_2 * V_3 ) { }
static inline void F_35 ( struct V_2 * V_3 ,
struct V_2 * V_18 , int V_31 ) { }
static inline void F_37 ( struct V_2 * V_3 ,
unsigned long time , unsigned long V_32 ) { }
static inline void F_39 ( struct V_2 * V_3 , int V_31 ) { }
static inline void F_40 ( struct V_2 * V_3 , int V_31 ) { }
static inline void F_41 ( struct V_2 * V_3 ,
T_1 V_34 , int V_31 ) { }
static inline void F_42 ( struct V_2 * V_3 ,
T_1 V_38 , T_1 V_39 , int V_31 ) { }
static inline bool F_52 ( struct V_47 * V_48 )
{
if ( ! V_48 -> V_49 && V_48 -> V_50 )
return true ;
else
return false ;
}
static inline enum V_4 F_53 ( struct V_51 * V_52 )
{
if ( F_54 ( V_52 ) )
return V_7 ;
if ( F_55 ( V_52 ) )
return V_53 ;
return V_54 ;
}
static enum V_6 F_56 ( struct V_51 * V_52 )
{
if ( ! F_57 ( V_52 ) )
return V_55 ;
if ( ! F_58 ( V_52 ) )
return V_56 ;
return V_57 ;
}
static inline int F_59 ( enum V_4 V_58 ,
struct V_47 * V_48 ,
struct V_2 * V_3 )
{
if ( V_58 == V_7 )
return V_3 -> V_8 . V_59 ;
return V_3 -> V_9 [ V_58 ] [ V_55 ] . V_59 +
V_3 -> V_9 [ V_58 ] [ V_56 ] . V_59 +
V_3 -> V_9 [ V_58 ] [ V_57 ] . V_59 ;
}
static inline int F_60 ( struct V_47 * V_48 ,
struct V_2 * V_3 )
{
return V_3 -> V_9 [ V_53 ] [ V_55 ] . V_59 +
V_3 -> V_9 [ V_54 ] [ V_55 ] . V_59 ;
}
static inline struct V_60 * F_61 ( struct V_61 * V_62 )
{
return F_3 ( V_62 , struct V_60 , V_62 ) ;
}
static inline struct V_60 * F_62 ( struct V_47 * V_48 ,
struct V_63 * V_64 )
{
if ( V_64 )
return F_61 ( F_63 ( V_64 , V_48 -> V_65 ) ) ;
return NULL ;
}
static inline struct V_51 * F_64 ( struct V_60 * V_66 , bool V_67 )
{
return V_66 -> V_52 [ V_67 ] ;
}
static inline void F_65 ( struct V_60 * V_66 , struct V_51 * V_52 ,
bool V_67 )
{
V_66 -> V_52 [ V_67 ] = V_52 ;
}
static inline struct V_47 * F_66 ( struct V_60 * V_66 )
{
return V_66 -> V_62 . V_44 -> V_68 -> V_69 ;
}
static inline bool F_67 ( struct V_70 * V_70 )
{
return F_68 ( V_70 ) == V_71 || ( V_70 -> V_72 & V_73 ) ;
}
static inline void F_69 ( struct V_47 * V_48 )
{
if ( V_48 -> V_74 ) {
F_70 ( V_48 , L_1 ) ;
F_71 ( & V_48 -> V_75 ) ;
}
}
static inline int F_72 ( struct V_47 * V_48 , bool V_76 ,
unsigned short V_77 )
{
const int V_78 = V_48 -> V_79 [ V_76 ] ;
F_73 ( V_77 >= V_80 ) ;
return V_78 + ( V_78 / V_81 * ( 4 - V_77 ) ) ;
}
static inline int
F_74 ( struct V_47 * V_48 , struct V_51 * V_52 )
{
return F_72 ( V_48 , F_57 ( V_52 ) , V_52 -> V_82 ) ;
}
static inline T_2 F_75 ( unsigned long V_83 ,
unsigned int V_84 )
{
T_2 V_85 = V_83 << V_86 ;
V_85 <<= V_86 ;
F_76 ( V_85 , V_84 ) ;
return V_85 ;
}
static inline T_2 F_77 ( T_2 V_87 , T_2 V_88 )
{
T_3 V_89 = ( T_3 ) ( V_88 - V_87 ) ;
if ( V_89 > 0 )
V_87 = V_88 ;
return V_87 ;
}
static inline T_2 V_87 ( T_2 V_87 , T_2 V_88 )
{
T_3 V_89 = ( T_3 ) ( V_88 - V_87 ) ;
if ( V_89 < 0 )
V_87 = V_88 ;
return V_87 ;
}
static void F_78 ( struct V_1 * V_90 )
{
struct V_2 * V_3 ;
if ( V_90 -> V_91 ) {
V_3 = F_79 ( V_90 -> V_91 ) ;
V_90 -> V_87 = F_77 ( V_90 -> V_87 ,
V_3 -> V_88 ) ;
}
}
static inline unsigned F_80 ( struct V_47 * V_48 ,
struct V_2 * V_3 , bool V_92 )
{
unsigned V_93 , V_94 ;
unsigned V_95 = V_96 - 1 ;
unsigned V_97 = V_96 / 2 ;
unsigned V_98 = F_59 ( V_92 , V_48 , V_3 ) ;
V_93 = F_81 ( V_3 -> V_99 [ V_92 ] , V_98 ) ;
V_94 = F_82 ( V_3 -> V_99 [ V_92 ] , V_98 ) ;
V_3 -> V_99 [ V_92 ] = ( V_95 * V_94 + V_93 + V_97 ) /
V_96 ;
return V_3 -> V_99 [ V_92 ] ;
}
static inline unsigned
F_83 ( struct V_47 * V_48 , struct V_2 * V_3 )
{
return V_48 -> V_100 * V_3 -> V_84 >> V_86 ;
}
static inline unsigned
F_84 ( struct V_47 * V_48 , struct V_51 * V_52 )
{
unsigned V_101 = F_74 ( V_48 , V_52 ) ;
if ( V_48 -> V_102 ) {
unsigned V_103 = F_80 ( V_48 , V_52 -> V_3 ,
F_55 ( V_52 ) ) ;
unsigned V_104 = V_48 -> V_79 [ 1 ] ;
unsigned V_105 = V_104 * V_103 ;
unsigned V_106 = F_83 ( V_48 , V_52 -> V_3 ) ;
if ( V_105 > V_106 ) {
unsigned V_107 = 2 * V_48 -> V_49 ;
unsigned V_108 =
F_81 ( V_101 , V_107 * V_101 / V_104 ) ;
V_101 = F_82 ( V_101 * V_106 / V_105 ,
V_108 ) ;
}
}
return V_101 ;
}
static inline void
F_85 ( struct V_47 * V_48 , struct V_51 * V_52 )
{
unsigned V_101 = F_84 ( V_48 , V_52 ) ;
V_52 -> V_109 = V_110 ;
V_52 -> V_111 = V_110 + V_101 ;
V_52 -> V_112 = V_101 ;
F_86 ( V_48 , V_52 , L_2 , V_52 -> V_111 - V_110 ) ;
}
static inline bool F_87 ( struct V_51 * V_52 )
{
if ( F_88 ( V_52 ) )
return false ;
if ( F_89 ( V_110 , V_52 -> V_111 ) )
return false ;
return true ;
}
static struct V_113 *
F_90 ( struct V_47 * V_48 , struct V_113 * V_114 , struct V_113 * V_115 , T_4 V_116 )
{
T_4 V_117 , V_118 , V_119 = 0 , V_120 = 0 ;
unsigned long V_121 ;
#define F_91 0x01
#define F_92 0x02
unsigned V_122 = 0 ;
if ( V_114 == NULL || V_114 == V_115 )
return V_115 ;
if ( V_115 == NULL )
return V_114 ;
if ( F_93 ( V_114 ) != F_93 ( V_115 ) )
return F_93 ( V_114 ) ? V_114 : V_115 ;
if ( ( V_114 -> V_123 ^ V_115 -> V_123 ) & V_124 )
return V_114 -> V_123 & V_124 ? V_114 : V_115 ;
V_117 = F_94 ( V_114 ) ;
V_118 = F_94 ( V_115 ) ;
V_121 = V_48 -> V_125 * 2 ;
if ( V_117 >= V_116 )
V_119 = V_117 - V_116 ;
else if ( V_117 + V_121 >= V_116 )
V_119 = ( V_116 - V_117 ) * V_48 -> V_126 ;
else
V_122 |= F_91 ;
if ( V_118 >= V_116 )
V_120 = V_118 - V_116 ;
else if ( V_118 + V_121 >= V_116 )
V_120 = ( V_116 - V_118 ) * V_48 -> V_126 ;
else
V_122 |= F_92 ;
switch ( V_122 ) {
case 0 :
if ( V_119 < V_120 )
return V_114 ;
else if ( V_120 < V_119 )
return V_115 ;
else {
if ( V_117 >= V_118 )
return V_114 ;
else
return V_115 ;
}
case F_92 :
return V_114 ;
case F_91 :
return V_115 ;
case ( F_91 | F_92 ) :
default:
if ( V_117 <= V_118 )
return V_114 ;
else
return V_115 ;
}
}
static struct V_51 * F_95 ( struct V_1 * V_127 )
{
if ( ! V_127 -> V_59 )
return NULL ;
if ( ! V_127 -> V_91 )
V_127 -> V_91 = F_96 ( & V_127 -> V_128 ) ;
if ( V_127 -> V_91 )
return F_97 ( V_127 -> V_91 , struct V_51 , V_129 ) ;
return NULL ;
}
static struct V_2 * F_98 ( struct V_1 * V_127 )
{
if ( ! V_127 -> V_91 )
V_127 -> V_91 = F_96 ( & V_127 -> V_128 ) ;
if ( V_127 -> V_91 )
return F_79 ( V_127 -> V_91 ) ;
return NULL ;
}
static void F_99 ( struct V_129 * V_130 , struct V_131 * V_127 )
{
F_100 ( V_130 , V_127 ) ;
F_101 ( V_130 ) ;
}
static void F_102 ( struct V_129 * V_130 , struct V_1 * V_127 )
{
if ( V_127 -> V_91 == V_130 )
V_127 -> V_91 = NULL ;
F_99 ( V_130 , & V_127 -> V_128 ) ;
-- V_127 -> V_59 ;
}
static struct V_113 *
F_103 ( struct V_47 * V_48 , struct V_51 * V_52 ,
struct V_113 * V_116 )
{
struct V_129 * V_132 = F_104 ( & V_116 -> V_129 ) ;
struct V_129 * V_133 = F_105 ( & V_116 -> V_129 ) ;
struct V_113 * V_134 = NULL , * V_135 = NULL ;
F_25 ( F_106 ( & V_116 -> V_129 ) ) ;
if ( V_133 )
V_135 = F_107 ( V_133 ) ;
if ( V_132 )
V_134 = F_107 ( V_132 ) ;
else {
V_132 = F_96 ( & V_52 -> V_136 ) ;
if ( V_132 && V_132 != & V_116 -> V_129 )
V_134 = F_107 ( V_132 ) ;
}
return F_90 ( V_48 , V_134 , V_135 , F_94 ( V_116 ) ) ;
}
static unsigned long F_108 ( struct V_47 * V_48 ,
struct V_51 * V_52 )
{
return ( V_52 -> V_3 -> V_137 - 1 ) * ( F_72 ( V_48 , 1 , 0 ) -
F_72 ( V_48 , F_57 ( V_52 ) , V_52 -> V_82 ) ) ;
}
static inline T_3
F_109 ( struct V_1 * V_90 , struct V_2 * V_3 )
{
return V_3 -> V_88 - V_90 -> V_87 ;
}
static void
F_110 ( struct V_1 * V_90 , struct V_2 * V_3 )
{
struct V_129 * * V_138 = & V_90 -> V_128 . V_129 ;
struct V_129 * V_30 = NULL ;
struct V_2 * V_139 ;
T_3 V_140 = F_109 ( V_90 , V_3 ) ;
int V_91 = 1 ;
while ( * V_138 != NULL ) {
V_30 = * V_138 ;
V_139 = F_79 ( V_30 ) ;
if ( V_140 < F_109 ( V_90 , V_139 ) )
V_138 = & V_30 -> V_141 ;
else {
V_138 = & V_30 -> V_142 ;
V_91 = 0 ;
}
}
if ( V_91 )
V_90 -> V_91 = & V_3 -> V_129 ;
F_111 ( & V_3 -> V_129 , V_30 , V_138 ) ;
F_112 ( & V_3 -> V_129 , & V_90 -> V_128 ) ;
}
static void
F_113 ( struct V_2 * V_3 )
{
F_25 ( ! F_106 ( & V_3 -> V_129 ) ) ;
if ( V_3 -> V_143 ) {
V_3 -> V_144 = V_3 -> V_143 ;
V_3 -> V_143 = 0 ;
}
if ( V_3 -> V_145 ) {
V_3 -> V_146 = V_3 -> V_145 ;
V_3 -> V_145 = 0 ;
}
}
static void
F_114 ( struct V_1 * V_90 , struct V_2 * V_3 )
{
unsigned int V_147 = 1 << V_86 ;
struct V_2 * V_148 = V_3 ;
struct V_2 * V_30 ;
bool V_149 ;
F_25 ( ! F_106 ( & V_3 -> V_129 ) ) ;
F_113 ( V_3 ) ;
F_110 ( V_90 , V_3 ) ;
V_149 = ! V_148 -> V_150 ++ ;
V_148 -> V_151 += V_148 -> V_146 ;
V_147 = V_147 * V_148 -> V_146 / V_148 -> V_151 ;
while ( ( V_30 = F_30 ( V_148 ) ) ) {
if ( V_149 ) {
V_149 = ! V_30 -> V_150 ++ ;
V_30 -> V_151 += V_148 -> V_144 ;
}
V_147 = V_147 * V_148 -> V_144 / V_30 -> V_151 ;
V_148 = V_30 ;
}
V_3 -> V_84 = F_115 ( unsigned , V_147 , 1 ) ;
}
static void
F_116 ( struct V_47 * V_48 , struct V_2 * V_3 )
{
struct V_1 * V_90 = & V_48 -> V_152 ;
struct V_2 * V_139 ;
struct V_129 * V_130 ;
V_3 -> V_137 ++ ;
if ( ! F_106 ( & V_3 -> V_129 ) )
return;
V_130 = F_117 ( & V_90 -> V_128 ) ;
if ( V_130 ) {
V_139 = F_79 ( V_130 ) ;
V_3 -> V_88 = V_139 -> V_88 + V_153 ;
} else
V_3 -> V_88 = V_90 -> V_87 ;
F_114 ( V_90 , V_3 ) ;
}
static void
F_118 ( struct V_1 * V_90 , struct V_2 * V_3 )
{
struct V_2 * V_148 = V_3 ;
bool V_149 ;
V_149 = ! -- V_148 -> V_150 ;
V_148 -> V_151 -= V_148 -> V_146 ;
while ( V_149 ) {
struct V_2 * V_30 = F_30 ( V_148 ) ;
F_119 ( V_148 -> V_151 ) ;
V_148 -> V_84 = 0 ;
if ( ! V_30 )
break;
V_149 = ! -- V_30 -> V_150 ;
V_30 -> V_151 -= V_148 -> V_144 ;
V_148 = V_30 ;
}
if ( ! F_106 ( & V_3 -> V_129 ) )
F_102 ( & V_3 -> V_129 , V_90 ) ;
}
static void
F_120 ( struct V_47 * V_48 , struct V_2 * V_3 )
{
struct V_1 * V_90 = & V_48 -> V_152 ;
F_25 ( V_3 -> V_137 < 1 ) ;
V_3 -> V_137 -- ;
if ( V_3 -> V_137 )
return;
F_121 ( V_48 , V_3 , L_3 ) ;
F_118 ( V_90 , V_3 ) ;
V_3 -> V_154 = 0 ;
F_17 ( V_3 ) ;
}
static inline unsigned int F_122 ( struct V_51 * V_52 ,
unsigned int * V_32 )
{
unsigned int V_155 ;
if ( ! V_52 -> V_109 || V_52 -> V_109 == V_110 ) {
V_155 = F_115 ( unsigned , ( V_110 - V_52 -> V_156 ) ,
1 ) ;
} else {
V_155 = V_110 - V_52 -> V_109 ;
if ( V_155 > V_52 -> V_112 ) {
* V_32 = V_155 - V_52 -> V_112 ;
V_155 = V_52 -> V_112 ;
}
if ( F_123 ( V_52 -> V_109 , V_52 -> V_156 ) )
* V_32 += V_52 -> V_109 -
V_52 -> V_156 ;
}
return V_155 ;
}
static void F_124 ( struct V_47 * V_48 , struct V_2 * V_3 ,
struct V_51 * V_52 )
{
struct V_1 * V_90 = & V_48 -> V_152 ;
unsigned int V_157 , V_83 , V_158 = 0 ;
int V_159 = V_3 -> V_137 - F_60 ( V_48 , V_3 )
- V_3 -> V_8 . V_59 ;
unsigned int V_147 ;
F_25 ( V_159 < 0 ) ;
V_157 = V_83 = F_122 ( V_52 , & V_158 ) ;
if ( F_52 ( V_48 ) )
V_83 = V_52 -> V_160 ;
else if ( ! F_57 ( V_52 ) && ! V_159 )
V_83 = V_52 -> V_112 ;
V_147 = V_3 -> V_84 ;
F_118 ( V_90 , V_3 ) ;
V_3 -> V_88 += F_75 ( V_83 , V_147 ) ;
F_114 ( V_90 , V_3 ) ;
if ( F_123 ( V_48 -> V_161 , V_110 ) ) {
V_3 -> V_154 = V_48 -> V_161
- V_110 ;
V_3 -> V_162 = V_48 -> V_163 ;
V_3 -> V_164 = V_48 -> V_165 ;
} else
V_3 -> V_154 = 0 ;
F_121 ( V_48 , V_3 , L_4 , V_3 -> V_88 ,
V_90 -> V_87 ) ;
F_86 ( V_52 -> V_48 , V_52 ,
L_5 ,
V_157 , V_52 -> V_160 , V_83 ,
F_52 ( V_48 ) , V_52 -> V_166 ) ;
F_37 ( V_3 , V_157 , V_158 ) ;
F_18 ( V_3 ) ;
}
static void F_125 ( struct V_2 * V_3 )
{
struct V_1 * V_90 ;
int V_167 , V_168 ;
F_126 ( V_3 , V_167 , V_168 , V_90 )
* V_90 = V_169 ;
F_101 ( & V_3 -> V_129 ) ;
V_3 -> V_170 . V_171 = V_110 ;
}
static void F_127 ( struct V_13 * V_14 )
{
F_128 ( & V_14 -> V_37 ) ;
F_128 ( & V_14 -> V_36 ) ;
F_128 ( & V_14 -> V_33 ) ;
F_128 ( & V_14 -> V_40 ) ;
F_128 ( & V_14 -> V_41 ) ;
F_128 ( & V_14 -> V_22 ) ;
F_129 ( & V_14 -> V_35 ) ;
F_129 ( & V_14 -> time ) ;
#ifdef F_38
F_129 ( & V_14 -> V_32 ) ;
F_129 ( & V_14 -> V_25 ) ;
F_129 ( & V_14 -> V_26 ) ;
F_129 ( & V_14 -> V_21 ) ;
F_129 ( & V_14 -> V_17 ) ;
F_129 ( & V_14 -> V_24 ) ;
F_129 ( & V_14 -> V_20 ) ;
#endif
}
static void F_130 ( struct V_12 * V_27 )
{
struct V_2 * V_3 = F_28 ( V_27 ) ;
F_125 ( V_3 ) ;
V_3 -> V_144 = V_27 -> V_172 -> V_173 ;
V_3 -> V_146 = V_27 -> V_172 -> V_174 ;
F_127 ( & V_3 -> V_14 ) ;
F_127 ( & V_3 -> V_46 ) ;
}
static void F_131 ( struct V_12 * V_27 )
{
F_49 ( F_28 ( V_27 ) ) ;
}
static T_2 F_132 ( struct V_10 * V_11 , int V_175 )
{
T_2 V_176 = 0 ;
V_176 += F_133 ( V_11 , V_175 ) ;
V_176 += F_133 ( V_11 , V_175 + V_177 ) ;
return V_176 ;
}
static struct V_178 F_134 ( struct V_10 * V_11 ,
int V_175 )
{
struct V_178 V_179 , V_180 ;
V_179 = F_135 ( V_11 , V_175 ) ;
V_180 = F_135 ( V_11 , V_175 + V_177 ) ;
F_47 ( & V_179 , & V_180 ) ;
return V_179 ;
}
static void F_136 ( struct V_12 * V_27 )
{
struct V_2 * V_3 = F_28 ( V_27 ) ;
F_43 ( & V_3 -> V_14 ) ;
F_43 ( & V_3 -> V_46 ) ;
}
static struct V_2 * F_137 ( struct V_47 * V_48 ,
struct V_172 * V_172 )
{
struct V_181 * V_44 = V_48 -> V_65 ;
struct V_2 * V_3 = NULL ;
if ( V_172 == & V_182 ) {
V_3 = V_48 -> V_183 ;
} else {
struct V_12 * V_27 ;
V_27 = F_138 ( V_172 , V_44 ) ;
if ( ! F_139 ( V_27 ) )
V_3 = F_28 ( V_27 ) ;
}
return V_3 ;
}
static void F_140 ( struct V_51 * V_52 , struct V_2 * V_3 )
{
if ( ! F_57 ( V_52 ) )
V_3 = V_52 -> V_48 -> V_183 ;
V_52 -> V_3 = V_3 ;
F_31 ( V_3 ) ;
}
static T_2 F_141 ( struct V_184 * V_185 ,
struct V_10 * V_11 , int V_175 )
{
struct V_2 * V_3 = F_2 ( V_11 ) ;
if ( ! V_3 -> V_186 )
return 0 ;
return F_142 ( V_185 , V_11 , V_3 -> V_186 ) ;
}
static int F_143 ( struct V_184 * V_185 , void * V_187 )
{
F_144 ( V_185 , F_145 ( F_146 ( V_185 ) ) ,
F_141 , & V_28 ,
0 , false ) ;
return 0 ;
}
static T_2 F_147 ( struct V_184 * V_185 ,
struct V_10 * V_11 , int V_175 )
{
struct V_2 * V_3 = F_2 ( V_11 ) ;
if ( ! V_3 -> V_188 )
return 0 ;
return F_142 ( V_185 , V_11 , V_3 -> V_188 ) ;
}
static int F_148 ( struct V_184 * V_185 , void * V_187 )
{
F_144 ( V_185 , F_145 ( F_146 ( V_185 ) ) ,
F_147 , & V_28 ,
0 , false ) ;
return 0 ;
}
static int F_149 ( struct V_184 * V_185 , void * V_187 )
{
F_150 ( V_185 , L_6 , F_145 ( F_146 ( V_185 ) ) -> V_173 ) ;
return 0 ;
}
static int F_151 ( struct V_184 * V_185 , void * V_187 )
{
F_150 ( V_185 , L_6 , F_145 ( F_146 ( V_185 ) ) -> V_174 ) ;
return 0 ;
}
static T_5 F_152 ( struct V_189 * V_190 ,
char * V_191 , T_6 V_192 , T_7 V_175 ,
bool V_193 )
{
struct V_172 * V_172 = F_145 ( F_153 ( V_190 ) ) ;
struct V_194 V_195 ;
struct V_2 * V_3 ;
int V_196 ;
V_196 = F_154 ( V_172 , & V_28 , V_191 , & V_195 ) ;
if ( V_196 )
return V_196 ;
V_196 = - V_197 ;
V_3 = F_28 ( V_195 . V_27 ) ;
if ( ! V_195 . V_187 || ( V_195 . V_187 >= V_198 && V_195 . V_187 <= V_199 ) ) {
if ( ! V_193 ) {
V_3 -> V_186 = V_195 . V_187 ;
V_3 -> V_143 = V_195 . V_187 ? : V_172 -> V_173 ;
} else {
V_3 -> V_188 = V_195 . V_187 ;
V_3 -> V_145 = V_195 . V_187 ? : V_172 -> V_174 ;
}
V_196 = 0 ;
}
F_155 ( & V_195 ) ;
return V_196 ? : V_192 ;
}
static T_5 F_156 ( struct V_189 * V_190 ,
char * V_191 , T_6 V_192 , T_7 V_175 )
{
return F_152 ( V_190 , V_191 , V_192 , V_175 , false ) ;
}
static T_5 F_157 ( struct V_189 * V_190 ,
char * V_191 , T_6 V_192 , T_7 V_175 )
{
return F_152 ( V_190 , V_191 , V_192 , V_175 , true ) ;
}
static int F_158 ( struct V_200 * V_201 , struct V_202 * V_203 ,
T_2 V_204 , bool V_193 )
{
struct V_172 * V_172 = F_145 ( V_201 ) ;
struct V_12 * V_27 ;
if ( V_204 < V_198 || V_204 > V_199 )
return - V_197 ;
F_159 ( & V_172 -> V_205 ) ;
if ( ! V_193 )
V_172 -> V_173 = V_204 ;
else
V_172 -> V_174 = V_204 ;
F_160 (blkg, &blkcg->blkg_list, blkcg_node) {
struct V_2 * V_3 = F_28 ( V_27 ) ;
if ( ! V_3 )
continue;
if ( ! V_193 ) {
if ( ! V_3 -> V_186 )
V_3 -> V_143 = V_172 -> V_173 ;
} else {
if ( ! V_3 -> V_188 )
V_3 -> V_145 = V_172 -> V_174 ;
}
}
F_161 ( & V_172 -> V_205 ) ;
return 0 ;
}
static int F_162 ( struct V_200 * V_201 , struct V_202 * V_203 ,
T_2 V_204 )
{
return F_158 ( V_201 , V_203 , V_204 , false ) ;
}
static int F_163 ( struct V_200 * V_201 ,
struct V_202 * V_203 , T_2 V_204 )
{
return F_158 ( V_201 , V_203 , V_204 , true ) ;
}
static int F_164 ( struct V_184 * V_185 , void * V_187 )
{
F_144 ( V_185 , F_145 ( F_146 ( V_185 ) ) , V_206 ,
& V_28 , F_165 ( V_185 ) -> V_207 , false ) ;
return 0 ;
}
static int F_166 ( struct V_184 * V_185 , void * V_187 )
{
F_144 ( V_185 , F_145 ( F_146 ( V_185 ) ) , V_208 ,
& V_28 , F_165 ( V_185 ) -> V_207 , true ) ;
return 0 ;
}
static T_2 F_167 ( struct V_184 * V_185 ,
struct V_10 * V_11 , int V_175 )
{
T_2 V_176 = F_132 ( V_11 , V_175 ) ;
return F_142 ( V_185 , V_11 , V_176 ) ;
}
static T_2 F_168 ( struct V_184 * V_185 ,
struct V_10 * V_11 , int V_175 )
{
struct V_178 V_176 = F_134 ( V_11 , V_175 ) ;
return F_169 ( V_185 , V_11 , & V_176 ) ;
}
static int F_170 ( struct V_184 * V_185 , void * V_187 )
{
F_144 ( V_185 , F_145 ( F_146 ( V_185 ) ) ,
F_167 , & V_28 ,
F_165 ( V_185 ) -> V_207 , false ) ;
return 0 ;
}
static int F_171 ( struct V_184 * V_185 , void * V_187 )
{
F_144 ( V_185 , F_145 ( F_146 ( V_185 ) ) ,
F_168 , & V_28 ,
F_165 ( V_185 ) -> V_207 , true ) ;
return 0 ;
}
static T_2 F_172 ( struct V_184 * V_185 ,
struct V_10 * V_11 , int V_175 )
{
struct V_2 * V_3 = F_2 ( V_11 ) ;
T_2 V_209 = F_173 ( & V_3 -> V_14 . V_26 ) ;
T_2 V_187 = 0 ;
if ( V_209 ) {
V_187 = F_173 ( & V_3 -> V_14 . V_25 ) ;
V_187 = F_174 ( V_187 , V_209 ) ;
}
F_142 ( V_185 , V_11 , V_187 ) ;
return 0 ;
}
static int F_175 ( struct V_184 * V_185 , void * V_187 )
{
F_144 ( V_185 , F_145 ( F_146 ( V_185 ) ) ,
F_172 , & V_28 ,
0 , false ) ;
return 0 ;
}
static struct V_2 * F_137 ( struct V_47 * V_48 ,
struct V_172 * V_172 )
{
return V_48 -> V_183 ;
}
static inline void
F_140 ( struct V_51 * V_52 , struct V_2 * V_3 ) {
V_52 -> V_3 = V_3 ;
}
static void F_176 ( struct V_47 * V_48 , struct V_51 * V_52 ,
bool V_210 )
{
struct V_129 * * V_211 , * V_30 ;
struct V_51 * V_212 ;
unsigned long V_213 ;
struct V_1 * V_90 ;
int V_91 ;
int V_214 = 1 ;
V_90 = F_1 ( V_52 -> V_3 , F_53 ( V_52 ) , F_56 ( V_52 ) ) ;
if ( F_54 ( V_52 ) ) {
V_213 = V_153 ;
V_30 = F_117 ( & V_90 -> V_128 ) ;
if ( V_30 && V_30 != & V_52 -> V_129 ) {
V_212 = F_97 ( V_30 , struct V_51 , V_129 ) ;
V_213 += V_212 -> V_213 ;
} else
V_213 += V_110 ;
} else if ( ! V_210 ) {
V_213 = F_108 ( V_48 , V_52 ) + V_110 ;
V_213 -= V_52 -> V_215 ;
V_52 -> V_215 = 0 ;
} else {
V_213 = - V_216 ;
V_212 = F_95 ( V_90 ) ;
V_213 += V_212 ? V_212 -> V_213 : V_110 ;
}
if ( ! F_106 ( & V_52 -> V_129 ) ) {
V_214 = 0 ;
if ( V_213 == V_52 -> V_213 && V_52 -> V_217 == V_90 )
return;
F_102 ( & V_52 -> V_129 , V_52 -> V_217 ) ;
V_52 -> V_217 = NULL ;
}
V_91 = 1 ;
V_30 = NULL ;
V_52 -> V_217 = V_90 ;
V_211 = & V_90 -> V_128 . V_129 ;
while ( * V_211 ) {
V_30 = * V_211 ;
V_212 = F_97 ( V_30 , struct V_51 , V_129 ) ;
if ( F_89 ( V_213 , V_212 -> V_213 ) )
V_211 = & V_30 -> V_141 ;
else {
V_211 = & V_30 -> V_142 ;
V_91 = 0 ;
}
}
if ( V_91 )
V_90 -> V_91 = & V_52 -> V_129 ;
V_52 -> V_213 = V_213 ;
F_111 ( & V_52 -> V_129 , V_30 , V_211 ) ;
F_112 ( & V_52 -> V_129 , & V_90 -> V_128 ) ;
V_90 -> V_59 ++ ;
if ( V_210 || ! V_214 )
return;
F_116 ( V_48 , V_52 -> V_3 ) ;
}
static struct V_51 *
F_177 ( struct V_47 * V_48 , struct V_131 * V_127 ,
T_4 V_218 , struct V_129 * * V_219 ,
struct V_129 * * * V_220 )
{
struct V_129 * * V_211 , * V_30 ;
struct V_51 * V_52 = NULL ;
V_30 = NULL ;
V_211 = & V_127 -> V_129 ;
while ( * V_211 ) {
struct V_129 * * V_130 ;
V_30 = * V_211 ;
V_52 = F_97 ( V_30 , struct V_51 , V_221 ) ;
if ( V_218 > F_94 ( V_52 -> V_222 ) )
V_130 = & ( * V_211 ) -> V_142 ;
else if ( V_218 < F_94 ( V_52 -> V_222 ) )
V_130 = & ( * V_211 ) -> V_141 ;
else
break;
V_211 = V_130 ;
V_52 = NULL ;
}
* V_219 = V_30 ;
if ( V_220 )
* V_220 = V_211 ;
return V_52 ;
}
static void F_178 ( struct V_47 * V_48 , struct V_51 * V_52 )
{
struct V_129 * * V_211 , * V_30 ;
struct V_51 * V_212 ;
if ( V_52 -> V_223 ) {
F_100 ( & V_52 -> V_221 , V_52 -> V_223 ) ;
V_52 -> V_223 = NULL ;
}
if ( F_54 ( V_52 ) )
return;
if ( ! V_52 -> V_222 )
return;
V_52 -> V_223 = & V_48 -> V_224 [ V_52 -> V_225 ] ;
V_212 = F_177 ( V_48 , V_52 -> V_223 ,
F_94 ( V_52 -> V_222 ) , & V_30 , & V_211 ) ;
if ( ! V_212 ) {
F_111 ( & V_52 -> V_221 , V_30 , V_211 ) ;
F_112 ( & V_52 -> V_221 , V_52 -> V_223 ) ;
} else
V_52 -> V_223 = NULL ;
}
static void F_179 ( struct V_47 * V_48 , struct V_51 * V_52 )
{
if ( F_180 ( V_52 ) ) {
F_176 ( V_48 , V_52 , 0 ) ;
F_178 ( V_48 , V_52 ) ;
}
}
static void F_181 ( struct V_47 * V_48 , struct V_51 * V_52 )
{
F_86 ( V_48 , V_52 , L_7 ) ;
F_25 ( F_180 ( V_52 ) ) ;
F_182 ( V_52 ) ;
V_48 -> V_74 ++ ;
if ( F_57 ( V_52 ) )
V_48 -> V_226 ++ ;
F_179 ( V_48 , V_52 ) ;
}
static void F_183 ( struct V_47 * V_48 , struct V_51 * V_52 )
{
F_86 ( V_48 , V_52 , L_8 ) ;
F_25 ( ! F_180 ( V_52 ) ) ;
F_184 ( V_52 ) ;
if ( ! F_106 ( & V_52 -> V_129 ) ) {
F_102 ( & V_52 -> V_129 , V_52 -> V_217 ) ;
V_52 -> V_217 = NULL ;
}
if ( V_52 -> V_223 ) {
F_100 ( & V_52 -> V_221 , V_52 -> V_223 ) ;
V_52 -> V_223 = NULL ;
}
F_120 ( V_48 , V_52 -> V_3 ) ;
F_25 ( ! V_48 -> V_74 ) ;
V_48 -> V_74 -- ;
if ( F_57 ( V_52 ) )
V_48 -> V_226 -- ;
}
static void F_185 ( struct V_113 * V_227 )
{
struct V_51 * V_52 = F_186 ( V_227 ) ;
const int V_76 = F_93 ( V_227 ) ;
F_25 ( ! V_52 -> V_22 [ V_76 ] ) ;
V_52 -> V_22 [ V_76 ] -- ;
F_187 ( & V_52 -> V_136 , V_227 ) ;
if ( F_180 ( V_52 ) && F_188 ( & V_52 -> V_136 ) ) {
if ( V_52 -> V_223 ) {
F_100 ( & V_52 -> V_221 , V_52 -> V_223 ) ;
V_52 -> V_223 = NULL ;
}
}
}
static void F_189 ( struct V_113 * V_227 )
{
struct V_51 * V_52 = F_186 ( V_227 ) ;
struct V_47 * V_48 = V_52 -> V_48 ;
struct V_113 * V_135 ;
V_52 -> V_22 [ F_93 ( V_227 ) ] ++ ;
F_190 ( & V_52 -> V_136 , V_227 ) ;
if ( ! F_180 ( V_52 ) )
F_181 ( V_48 , V_52 ) ;
V_135 = V_52 -> V_222 ;
V_52 -> V_222 = F_90 ( V_48 , V_52 -> V_222 , V_227 , V_48 -> V_228 ) ;
if ( V_135 != V_52 -> V_222 )
F_178 ( V_48 , V_52 ) ;
F_25 ( ! V_52 -> V_222 ) ;
}
static void F_191 ( struct V_51 * V_52 , struct V_113 * V_227 )
{
F_187 ( & V_52 -> V_136 , V_227 ) ;
V_52 -> V_22 [ F_93 ( V_227 ) ] -- ;
F_39 ( F_192 ( V_227 ) , V_227 -> V_123 ) ;
F_189 ( V_227 ) ;
F_35 ( F_192 ( V_227 ) , V_52 -> V_48 -> V_229 ,
V_227 -> V_123 ) ;
}
static struct V_113 *
F_193 ( struct V_47 * V_48 , struct V_70 * V_70 )
{
struct V_230 * V_231 = V_232 ;
struct V_60 * V_66 ;
struct V_51 * V_52 ;
V_66 = F_62 ( V_48 , V_231 -> V_63 ) ;
if ( ! V_66 )
return NULL ;
V_52 = F_64 ( V_66 , F_67 ( V_70 ) ) ;
if ( V_52 )
return F_194 ( & V_52 -> V_136 , F_195 ( V_70 ) ) ;
return NULL ;
}
static void F_196 ( struct V_181 * V_44 , struct V_113 * V_227 )
{
struct V_47 * V_48 = V_44 -> V_68 -> V_69 ;
V_48 -> V_233 ++ ;
F_86 ( V_48 , F_186 ( V_227 ) , L_9 ,
V_48 -> V_233 ) ;
V_48 -> V_228 = F_94 ( V_227 ) + F_197 ( V_227 ) ;
}
static void F_198 ( struct V_181 * V_44 , struct V_113 * V_227 )
{
struct V_47 * V_48 = V_44 -> V_68 -> V_69 ;
F_73 ( ! V_48 -> V_233 ) ;
V_48 -> V_233 -- ;
F_86 ( V_48 , F_186 ( V_227 ) , L_10 ,
V_48 -> V_233 ) ;
}
static void F_199 ( struct V_113 * V_227 )
{
struct V_51 * V_52 = F_186 ( V_227 ) ;
if ( V_52 -> V_222 == V_227 )
V_52 -> V_222 = F_103 ( V_52 -> V_48 , V_52 , V_227 ) ;
F_200 ( & V_227 -> V_234 ) ;
F_185 ( V_227 ) ;
V_52 -> V_48 -> V_235 -- ;
F_39 ( F_192 ( V_227 ) , V_227 -> V_123 ) ;
if ( V_227 -> V_123 & V_124 ) {
F_73 ( ! V_52 -> V_236 ) ;
V_52 -> V_236 -- ;
}
}
static int F_201 ( struct V_181 * V_44 , struct V_113 * * V_237 ,
struct V_70 * V_70 )
{
struct V_47 * V_48 = V_44 -> V_68 -> V_69 ;
struct V_113 * V_238 ;
V_238 = F_193 ( V_48 , V_70 ) ;
if ( V_238 && F_202 ( V_238 , V_70 ) ) {
* V_237 = V_238 ;
return V_239 ;
}
return V_240 ;
}
static void F_203 ( struct V_181 * V_44 , struct V_113 * V_237 ,
int type )
{
if ( type == V_239 ) {
struct V_51 * V_52 = F_186 ( V_237 ) ;
F_191 ( V_52 , V_237 ) ;
}
}
static void F_204 ( struct V_181 * V_44 , struct V_113 * V_237 ,
struct V_70 * V_70 )
{
F_40 ( F_192 ( V_237 ) , V_70 -> V_72 ) ;
}
static void
F_205 ( struct V_181 * V_44 , struct V_113 * V_227 ,
struct V_113 * V_134 )
{
struct V_51 * V_52 = F_186 ( V_227 ) ;
struct V_47 * V_48 = V_44 -> V_68 -> V_69 ;
if ( ! F_206 ( & V_227 -> V_234 ) && ! F_206 ( & V_134 -> V_234 ) &&
F_89 ( V_134 -> V_241 , V_227 -> V_241 ) &&
V_52 == F_186 ( V_134 ) ) {
F_207 ( & V_227 -> V_234 , & V_134 -> V_234 ) ;
V_227 -> V_241 = V_134 -> V_241 ;
}
if ( V_52 -> V_222 == V_134 )
V_52 -> V_222 = V_227 ;
F_199 ( V_134 ) ;
F_40 ( F_192 ( V_227 ) , V_134 -> V_123 ) ;
V_52 = F_186 ( V_134 ) ;
if ( F_180 ( V_52 ) && F_188 ( & V_52 -> V_136 ) &&
V_52 != V_48 -> V_242 )
F_183 ( V_48 , V_52 ) ;
}
static int F_208 ( struct V_181 * V_44 , struct V_113 * V_227 ,
struct V_70 * V_70 )
{
struct V_47 * V_48 = V_44 -> V_68 -> V_69 ;
struct V_60 * V_66 ;
struct V_51 * V_52 ;
if ( F_67 ( V_70 ) && ! F_93 ( V_227 ) )
return false ;
V_66 = F_62 ( V_48 , V_232 -> V_63 ) ;
if ( ! V_66 )
return false ;
V_52 = F_64 ( V_66 , F_67 ( V_70 ) ) ;
return V_52 == F_186 ( V_227 ) ;
}
static inline void F_209 ( struct V_47 * V_48 , struct V_51 * V_52 )
{
F_210 ( & V_48 -> V_243 ) ;
F_21 ( V_52 -> V_3 ) ;
}
static void F_211 ( struct V_47 * V_48 ,
struct V_51 * V_52 )
{
if ( V_52 ) {
F_86 ( V_48 , V_52 , L_11 ,
V_48 -> V_165 , V_48 -> V_163 ) ;
F_27 ( V_52 -> V_3 ) ;
V_52 -> V_109 = 0 ;
V_52 -> V_156 = V_110 ;
V_52 -> V_112 = 0 ;
V_52 -> V_111 = 0 ;
V_52 -> V_160 = 0 ;
V_52 -> V_166 = 0 ;
F_212 ( V_52 ) ;
F_213 ( V_52 ) ;
F_214 ( V_52 ) ;
F_215 ( V_52 ) ;
F_216 ( V_52 ) ;
F_209 ( V_48 , V_52 ) ;
}
V_48 -> V_242 = V_52 ;
}
static void
F_217 ( struct V_47 * V_48 , struct V_51 * V_52 ,
bool V_244 )
{
F_86 ( V_48 , V_52 , L_12 , V_244 ) ;
if ( F_218 ( V_52 ) )
F_209 ( V_48 , V_52 ) ;
F_212 ( V_52 ) ;
F_219 ( V_52 ) ;
if ( F_220 ( V_52 ) && F_221 ( V_52 ) )
F_222 ( V_52 ) ;
if ( V_244 ) {
if ( F_88 ( V_52 ) )
V_52 -> V_215 = F_84 ( V_48 , V_52 ) ;
else
V_52 -> V_215 = V_52 -> V_111 - V_110 ;
F_86 ( V_48 , V_52 , L_13 , V_52 -> V_215 ) ;
}
F_124 ( V_48 , V_52 -> V_3 , V_52 ) ;
if ( F_180 ( V_52 ) && F_188 ( & V_52 -> V_136 ) )
F_183 ( V_48 , V_52 ) ;
F_179 ( V_48 , V_52 ) ;
if ( V_52 == V_48 -> V_242 )
V_48 -> V_242 = NULL ;
if ( V_48 -> V_245 ) {
F_223 ( V_48 -> V_245 -> V_62 . V_64 ) ;
V_48 -> V_245 = NULL ;
}
}
static inline void F_224 ( struct V_47 * V_48 , bool V_244 )
{
struct V_51 * V_52 = V_48 -> V_242 ;
if ( V_52 )
F_217 ( V_48 , V_52 , V_244 ) ;
}
static struct V_51 * F_225 ( struct V_47 * V_48 )
{
struct V_1 * V_90 = F_1 ( V_48 -> V_229 ,
V_48 -> V_165 , V_48 -> V_163 ) ;
if ( ! V_48 -> V_235 )
return NULL ;
if ( ! V_90 )
return NULL ;
if ( F_188 ( & V_90 -> V_128 ) )
return NULL ;
return F_95 ( V_90 ) ;
}
static struct V_51 * F_226 ( struct V_47 * V_48 )
{
struct V_2 * V_3 ;
struct V_51 * V_52 ;
int V_167 , V_168 ;
struct V_1 * V_90 ;
if ( ! V_48 -> V_235 )
return NULL ;
V_3 = F_227 ( V_48 ) ;
if ( ! V_3 )
return NULL ;
F_126 (cfqg, i, j, st)
if ( ( V_52 = F_95 ( V_90 ) ) != NULL )
return V_52 ;
return NULL ;
}
static struct V_51 * F_228 ( struct V_47 * V_48 ,
struct V_51 * V_52 )
{
if ( ! V_52 )
V_52 = F_225 ( V_48 ) ;
F_211 ( V_48 , V_52 ) ;
return V_52 ;
}
static inline T_4 F_229 ( struct V_47 * V_48 ,
struct V_113 * V_227 )
{
if ( F_94 ( V_227 ) >= V_48 -> V_228 )
return F_94 ( V_227 ) - V_48 -> V_228 ;
else
return V_48 -> V_228 - F_94 ( V_227 ) ;
}
static inline int F_230 ( struct V_47 * V_48 , struct V_51 * V_52 ,
struct V_113 * V_227 )
{
return F_229 ( V_48 , V_227 ) <= V_246 ;
}
static struct V_51 * F_231 ( struct V_47 * V_48 ,
struct V_51 * V_247 )
{
struct V_131 * V_127 = & V_48 -> V_224 [ V_247 -> V_225 ] ;
struct V_129 * V_30 , * V_138 ;
struct V_51 * V_212 ;
T_4 V_218 = V_48 -> V_228 ;
if ( F_188 ( V_127 ) )
return NULL ;
V_212 = F_177 ( V_48 , V_127 , V_218 , & V_30 , NULL ) ;
if ( V_212 )
return V_212 ;
V_212 = F_97 ( V_30 , struct V_51 , V_221 ) ;
if ( F_230 ( V_48 , V_247 , V_212 -> V_222 ) )
return V_212 ;
if ( F_94 ( V_212 -> V_222 ) < V_218 )
V_138 = F_104 ( & V_212 -> V_221 ) ;
else
V_138 = F_105 ( & V_212 -> V_221 ) ;
if ( ! V_138 )
return NULL ;
V_212 = F_97 ( V_138 , struct V_51 , V_221 ) ;
if ( F_230 ( V_48 , V_247 , V_212 -> V_222 ) )
return V_212 ;
return NULL ;
}
static struct V_51 * F_232 ( struct V_47 * V_48 ,
struct V_51 * V_247 )
{
struct V_51 * V_52 ;
if ( F_54 ( V_247 ) )
return NULL ;
if ( ! F_57 ( V_247 ) )
return NULL ;
if ( F_221 ( V_247 ) )
return NULL ;
if ( V_247 -> V_3 -> V_137 == 1 )
return NULL ;
V_52 = F_231 ( V_48 , V_247 ) ;
if ( ! V_52 )
return NULL ;
if ( V_247 -> V_3 != V_52 -> V_3 )
return NULL ;
if ( ! F_57 ( V_52 ) )
return NULL ;
if ( F_221 ( V_52 ) )
return NULL ;
if ( F_55 ( V_52 ) != F_55 ( V_247 ) )
return NULL ;
return V_52 ;
}
static bool F_233 ( struct V_47 * V_48 , struct V_51 * V_52 )
{
enum V_4 V_58 = F_53 ( V_52 ) ;
struct V_1 * V_90 = V_52 -> V_217 ;
F_25 ( ! V_90 ) ;
F_25 ( ! V_90 -> V_59 ) ;
if ( ! V_48 -> V_49 )
return false ;
if ( V_58 == V_7 )
return false ;
if ( F_58 ( V_52 ) &&
! ( F_234 ( V_48 -> V_65 ) && V_48 -> V_50 ) )
return true ;
if ( V_90 -> V_59 == 1 && F_57 ( V_52 ) &&
! F_235 ( V_48 , & V_90 -> V_170 , false ) )
return true ;
F_86 ( V_48 , V_52 , L_14 , V_90 -> V_59 ) ;
return false ;
}
static void F_236 ( struct V_47 * V_48 )
{
struct V_51 * V_52 = V_48 -> V_242 ;
struct V_60 * V_66 ;
unsigned long V_248 , V_249 = 0 ;
if ( F_234 ( V_48 -> V_65 ) && V_48 -> V_50 )
return;
F_73 ( ! F_188 ( & V_52 -> V_136 ) ) ;
F_73 ( F_88 ( V_52 ) ) ;
if ( ! F_233 ( V_48 , V_52 ) ) {
if ( V_48 -> V_250 )
V_249 = V_48 -> V_250 ;
else
return;
}
if ( V_52 -> V_251 )
return;
V_66 = V_48 -> V_245 ;
if ( ! V_66 || ! F_237 ( & V_66 -> V_62 . V_64 -> V_252 ) )
return;
if ( F_238 ( V_66 -> V_170 . V_253 ) &&
( V_52 -> V_111 - V_110 < V_66 -> V_170 . V_254 ) ) {
F_86 ( V_48 , V_52 , L_15 ,
V_66 -> V_170 . V_254 ) ;
return;
}
if ( V_249 && V_52 -> V_3 -> V_137 > 1 )
return;
F_239 ( V_52 ) ;
if ( V_249 )
V_248 = V_48 -> V_250 ;
else
V_248 = V_48 -> V_49 ;
F_240 ( & V_48 -> V_243 , V_110 + V_248 ) ;
F_24 ( V_52 -> V_3 ) ;
F_86 ( V_48 , V_52 , L_16 , V_248 ,
V_249 ? 1 : 0 ) ;
}
static void F_241 ( struct V_181 * V_44 , struct V_113 * V_227 )
{
struct V_47 * V_48 = V_44 -> V_68 -> V_69 ;
struct V_51 * V_52 = F_186 ( V_227 ) ;
F_86 ( V_48 , V_52 , L_17 ) ;
V_52 -> V_222 = F_103 ( V_48 , V_52 , V_227 ) ;
F_199 ( V_227 ) ;
V_52 -> V_251 ++ ;
( F_192 ( V_227 ) ) -> V_251 ++ ;
F_242 ( V_44 , V_227 ) ;
V_48 -> V_255 [ F_57 ( V_52 ) ] ++ ;
V_52 -> V_166 += F_197 ( V_227 ) ;
F_41 ( V_52 -> V_3 , F_243 ( V_227 ) , V_227 -> V_123 ) ;
}
static struct V_113 * F_244 ( struct V_51 * V_52 )
{
struct V_113 * V_227 = NULL ;
if ( F_245 ( V_52 ) )
return NULL ;
F_246 ( V_52 ) ;
if ( F_206 ( & V_52 -> V_256 ) )
return NULL ;
V_227 = F_247 ( V_52 -> V_256 . V_134 ) ;
if ( F_89 ( V_110 , V_227 -> V_241 ) )
V_227 = NULL ;
F_86 ( V_52 -> V_48 , V_52 , L_18 , V_227 ) ;
return V_227 ;
}
static inline int
F_248 ( struct V_47 * V_48 , struct V_51 * V_52 )
{
const int V_257 = V_48 -> V_258 ;
F_73 ( V_52 -> V_82 >= V_80 ) ;
return 2 * V_257 * ( V_80 - V_52 -> V_82 ) ;
}
static int F_249 ( struct V_51 * V_52 )
{
int V_259 , V_260 ;
V_260 = V_52 -> V_261 [ V_71 ] + V_52 -> V_261 [ V_262 ] ;
V_259 = V_52 -> V_263 - V_260 ;
F_25 ( V_259 < 0 ) ;
return V_259 ;
}
static void F_250 ( struct V_51 * V_52 , struct V_51 * V_214 )
{
int V_259 , V_264 ;
struct V_51 * V_212 ;
if ( ! F_249 ( V_214 ) )
return;
while ( ( V_212 = V_214 -> V_214 ) ) {
if ( V_212 == V_52 )
return;
V_214 = V_212 ;
}
V_259 = F_249 ( V_52 ) ;
V_264 = F_249 ( V_214 ) ;
if ( V_259 == 0 || V_264 == 0 )
return;
if ( V_264 >= V_259 ) {
V_52 -> V_214 = V_214 ;
V_214 -> V_263 += V_259 ;
} else {
V_214 -> V_214 = V_52 ;
V_52 -> V_263 += V_264 ;
}
}
static enum V_6 F_251 ( struct V_47 * V_48 ,
struct V_2 * V_3 , enum V_4 V_58 )
{
struct V_51 * V_65 ;
int V_167 ;
bool V_265 = false ;
unsigned long V_266 = 0 ;
enum V_6 V_267 = V_56 ;
for ( V_167 = 0 ; V_167 <= V_57 ; ++ V_167 ) {
V_65 = F_95 ( F_1 ( V_3 , V_58 , V_167 ) ) ;
if ( V_65 &&
( ! V_265 || F_89 ( V_65 -> V_213 , V_266 ) ) ) {
V_266 = V_65 -> V_213 ;
V_267 = V_167 ;
V_265 = true ;
}
}
return V_267 ;
}
static void
F_252 ( struct V_47 * V_48 , struct V_2 * V_3 )
{
unsigned V_101 ;
unsigned V_59 ;
struct V_1 * V_90 ;
unsigned V_106 ;
enum V_4 V_268 = V_48 -> V_165 ;
if ( F_59 ( V_53 , V_48 , V_3 ) )
V_48 -> V_165 = V_53 ;
else if ( F_59 ( V_54 , V_48 , V_3 ) )
V_48 -> V_165 = V_54 ;
else {
V_48 -> V_165 = V_7 ;
V_48 -> V_161 = V_110 + 1 ;
return;
}
if ( V_268 != V_48 -> V_165 )
goto V_269;
V_90 = F_1 ( V_3 , V_48 -> V_165 , V_48 -> V_163 ) ;
V_59 = V_90 -> V_59 ;
if ( V_59 && ! F_123 ( V_110 , V_48 -> V_161 ) )
return;
V_269:
V_48 -> V_163 = F_251 ( V_48 , V_3 ,
V_48 -> V_165 ) ;
V_90 = F_1 ( V_3 , V_48 -> V_165 , V_48 -> V_163 ) ;
V_59 = V_90 -> V_59 ;
V_106 = F_83 ( V_48 , V_3 ) ;
V_101 = V_106 * V_59 /
F_115 ( unsigned , V_3 -> V_99 [ V_48 -> V_165 ] ,
F_59 ( V_48 -> V_165 , V_48 ,
V_3 ) ) ;
if ( V_48 -> V_163 == V_55 ) {
unsigned int V_270 ;
V_270 = V_48 -> V_100 *
F_60 ( V_48 , V_3 ) ;
V_270 = V_270 / V_48 -> V_74 ;
V_101 = F_253 ( unsigned , V_101 , V_270 ) ;
V_101 = V_101 * V_48 -> V_79 [ 0 ] / V_48 -> V_79 [ 1 ] ;
} else
V_101 = F_82 ( V_101 , 2 * V_48 -> V_49 ) ;
V_101 = F_115 ( unsigned , V_101 , V_271 ) ;
F_70 ( V_48 , L_19 , V_101 ) ;
V_48 -> V_161 = V_110 + V_101 ;
}
static struct V_2 * F_227 ( struct V_47 * V_48 )
{
struct V_1 * V_90 = & V_48 -> V_152 ;
struct V_2 * V_3 ;
if ( F_188 ( & V_90 -> V_128 ) )
return NULL ;
V_3 = F_98 ( V_90 ) ;
F_78 ( V_90 ) ;
return V_3 ;
}
static void F_254 ( struct V_47 * V_48 )
{
struct V_2 * V_3 = F_227 ( V_48 ) ;
V_48 -> V_229 = V_3 ;
if ( V_3 -> V_154 ) {
V_48 -> V_161 = V_110 + V_3 -> V_154 ;
V_48 -> V_163 = V_3 -> V_162 ;
V_48 -> V_165 = V_3 -> V_164 ;
} else
V_48 -> V_161 = V_110 - 1 ;
F_252 ( V_48 , V_3 ) ;
}
static struct V_51 * F_255 ( struct V_47 * V_48 )
{
struct V_51 * V_52 , * V_214 = NULL ;
V_52 = V_48 -> V_242 ;
if ( ! V_52 )
goto V_272;
if ( ! V_48 -> V_235 )
return NULL ;
if ( F_256 ( V_52 ) && ! F_188 ( & V_52 -> V_136 ) )
goto V_273;
if ( F_87 ( V_52 ) && ! F_257 ( V_52 ) ) {
if ( V_52 -> V_3 -> V_137 == 1 && F_188 ( & V_52 -> V_136 )
&& V_52 -> V_251 && F_233 ( V_48 , V_52 ) ) {
V_52 = NULL ;
goto V_274;
} else
goto V_275;
}
if ( ! F_188 ( & V_52 -> V_136 ) )
goto V_274;
V_214 = F_232 ( V_48 , V_52 ) ;
if ( V_214 ) {
if ( ! V_52 -> V_214 )
F_250 ( V_52 , V_214 ) ;
goto V_273;
}
if ( F_258 ( & V_48 -> V_243 ) ) {
V_52 = NULL ;
goto V_274;
}
if ( F_221 ( V_52 ) && F_58 ( V_52 ) &&
( F_88 ( V_52 ) ||
( V_52 -> V_111 - V_110 > V_110 - V_52 -> V_109 ) ) ) {
F_259 ( V_52 ) ;
F_260 ( V_52 ) ;
}
if ( V_52 -> V_251 && F_233 ( V_48 , V_52 ) ) {
V_52 = NULL ;
goto V_274;
}
V_275:
if ( V_48 -> V_250 && V_52 -> V_3 -> V_137 == 1 &&
V_52 -> V_3 -> V_251 &&
! F_235 ( V_48 , & V_52 -> V_3 -> V_170 , true ) ) {
V_52 = NULL ;
goto V_274;
}
V_273:
F_224 ( V_48 , 0 ) ;
V_272:
if ( ! V_214 )
F_254 ( V_48 ) ;
V_52 = F_228 ( V_48 , V_214 ) ;
V_274:
return V_52 ;
}
static int F_261 ( struct V_51 * V_52 )
{
int V_251 = 0 ;
while ( V_52 -> V_222 ) {
F_241 ( V_52 -> V_48 -> V_65 , V_52 -> V_222 ) ;
V_251 ++ ;
}
F_25 ( ! F_206 ( & V_52 -> V_256 ) ) ;
F_217 ( V_52 -> V_48 , V_52 , 0 ) ;
return V_251 ;
}
static int F_262 ( struct V_47 * V_48 )
{
struct V_51 * V_52 ;
int V_251 = 0 ;
F_224 ( V_48 , 0 ) ;
while ( ( V_52 = F_226 ( V_48 ) ) != NULL ) {
F_211 ( V_48 , V_52 ) ;
V_251 += F_261 ( V_52 ) ;
}
F_25 ( V_48 -> V_74 ) ;
F_70 ( V_48 , L_20 , V_251 ) ;
return V_251 ;
}
static inline bool F_263 ( struct V_47 * V_48 ,
struct V_51 * V_52 )
{
if ( F_88 ( V_52 ) )
return true ;
if ( F_123 ( V_110 + V_48 -> V_49 * V_52 -> V_251 ,
V_52 -> V_111 ) )
return true ;
return false ;
}
static bool F_264 ( struct V_47 * V_48 , struct V_51 * V_52 )
{
unsigned int V_276 ;
if ( F_233 ( V_48 , V_52 ) && V_48 -> V_255 [ V_277 ] )
return false ;
if ( V_48 -> V_255 [ V_278 ] && ! F_57 ( V_52 ) )
return false ;
V_276 = F_115 (unsigned int, cfqd->cfq_quantum / 2 , 1 ) ;
if ( F_54 ( V_52 ) )
V_276 = 1 ;
if ( V_52 -> V_251 >= V_276 ) {
bool V_279 = false ;
if ( F_54 ( V_52 ) )
return false ;
if ( F_57 ( V_52 ) && V_48 -> V_226 == 1 )
V_279 = true ;
if ( V_48 -> V_74 > 1 && F_263 ( V_48 , V_52 ) &&
! V_279 )
return false ;
if ( V_48 -> V_74 == 1 || V_279 )
V_276 = - 1 ;
else
V_276 = V_48 -> V_280 ;
}
if ( ! F_57 ( V_52 ) && V_48 -> V_102 ) {
unsigned long V_281 = V_110 - V_48 -> V_282 ;
unsigned int V_283 ;
V_283 = V_281 / V_48 -> V_79 [ 1 ] ;
if ( ! V_283 && ! V_52 -> V_251 )
V_283 = 1 ;
if ( V_283 < V_276 )
V_276 = V_283 ;
}
return V_52 -> V_251 < V_276 ;
}
static bool F_265 ( struct V_47 * V_48 , struct V_51 * V_52 )
{
struct V_113 * V_227 ;
F_25 ( F_188 ( & V_52 -> V_136 ) ) ;
if ( ! F_264 ( V_48 , V_52 ) )
return false ;
V_227 = F_244 ( V_52 ) ;
if ( ! V_227 )
V_227 = V_52 -> V_222 ;
F_241 ( V_48 -> V_65 , V_227 ) ;
if ( ! V_48 -> V_245 ) {
struct V_60 * V_66 = F_266 ( V_227 ) ;
F_267 ( & V_66 -> V_62 . V_64 -> V_284 ) ;
V_48 -> V_245 = V_66 ;
}
return true ;
}
static int F_268 ( struct V_181 * V_44 , int V_285 )
{
struct V_47 * V_48 = V_44 -> V_68 -> V_69 ;
struct V_51 * V_52 ;
if ( ! V_48 -> V_74 )
return 0 ;
if ( F_51 ( V_285 ) )
return F_262 ( V_48 ) ;
V_52 = F_255 ( V_48 ) ;
if ( ! V_52 )
return 0 ;
if ( ! F_265 ( V_48 , V_52 ) )
return 0 ;
V_52 -> V_160 ++ ;
F_213 ( V_52 ) ;
if ( V_48 -> V_74 > 1 && ( ( ! F_57 ( V_52 ) &&
V_52 -> V_160 >= F_248 ( V_48 , V_52 ) ) ||
F_54 ( V_52 ) ) ) {
V_52 -> V_111 = V_110 + 1 ;
F_224 ( V_48 , 0 ) ;
}
F_86 ( V_48 , V_52 , L_21 ) ;
return 1 ;
}
static void F_269 ( struct V_51 * V_52 )
{
struct V_47 * V_48 = V_52 -> V_48 ;
struct V_2 * V_3 ;
F_25 ( V_52 -> V_263 <= 0 ) ;
V_52 -> V_263 -- ;
if ( V_52 -> V_263 )
return;
F_86 ( V_48 , V_52 , L_22 ) ;
F_25 ( F_96 ( & V_52 -> V_136 ) ) ;
F_25 ( V_52 -> V_261 [ V_71 ] + V_52 -> V_261 [ V_262 ] ) ;
V_3 = V_52 -> V_3 ;
if ( F_51 ( V_48 -> V_242 == V_52 ) ) {
F_217 ( V_48 , V_52 , 0 ) ;
F_69 ( V_48 ) ;
}
F_25 ( F_180 ( V_52 ) ) ;
F_270 ( V_286 , V_52 ) ;
F_33 ( V_3 ) ;
}
static void F_271 ( struct V_51 * V_52 )
{
struct V_51 * V_212 , * V_134 ;
V_212 = V_52 -> V_214 ;
while ( V_212 ) {
if ( V_212 == V_52 ) {
F_272 ( 1 , L_23 ) ;
break;
}
V_134 = V_212 -> V_214 ;
F_269 ( V_212 ) ;
V_212 = V_134 ;
}
}
static void F_273 ( struct V_47 * V_48 , struct V_51 * V_52 )
{
if ( F_51 ( V_52 == V_48 -> V_242 ) ) {
F_217 ( V_48 , V_52 , 0 ) ;
F_69 ( V_48 ) ;
}
F_271 ( V_52 ) ;
F_269 ( V_52 ) ;
}
static void F_274 ( struct V_61 * V_62 )
{
struct V_60 * V_66 = F_61 ( V_62 ) ;
V_66 -> V_170 . V_171 = V_110 ;
}
static void F_275 ( struct V_61 * V_62 )
{
struct V_60 * V_66 = F_61 ( V_62 ) ;
struct V_47 * V_48 = F_66 ( V_66 ) ;
if ( V_66 -> V_52 [ V_277 ] ) {
F_273 ( V_48 , V_66 -> V_52 [ V_277 ] ) ;
V_66 -> V_52 [ V_277 ] = NULL ;
}
if ( V_66 -> V_52 [ V_278 ] ) {
F_273 ( V_48 , V_66 -> V_52 [ V_278 ] ) ;
V_66 -> V_52 [ V_278 ] = NULL ;
}
}
static void F_276 ( struct V_51 * V_52 , struct V_60 * V_66 )
{
struct V_230 * V_231 = V_232 ;
int V_287 ;
if ( ! F_277 ( V_52 ) )
return;
V_287 = F_278 ( V_66 -> V_82 ) ;
switch ( V_287 ) {
default:
F_279 ( V_288 L_24 , V_287 ) ;
case V_289 :
V_52 -> V_82 = F_280 ( V_231 ) ;
V_52 -> V_287 = F_281 ( V_231 ) ;
break;
case V_290 :
V_52 -> V_82 = F_282 ( V_66 -> V_82 ) ;
V_52 -> V_287 = V_290 ;
break;
case V_291 :
V_52 -> V_82 = F_282 ( V_66 -> V_82 ) ;
V_52 -> V_287 = V_291 ;
break;
case V_292 :
V_52 -> V_287 = V_292 ;
V_52 -> V_82 = 7 ;
F_260 ( V_52 ) ;
break;
}
V_52 -> V_225 = V_52 -> V_82 ;
F_283 ( V_52 ) ;
}
static void F_284 ( struct V_60 * V_66 , struct V_70 * V_70 )
{
int V_82 = V_66 -> V_62 . V_64 -> V_82 ;
struct V_47 * V_48 = F_66 ( V_66 ) ;
struct V_51 * V_52 ;
if ( F_51 ( ! V_48 ) || F_285 ( V_66 -> V_82 == V_82 ) )
return;
V_52 = V_66 -> V_52 [ V_277 ] ;
if ( V_52 ) {
struct V_51 * V_214 ;
V_214 = F_286 ( V_48 , V_277 , V_66 , V_70 ,
V_293 ) ;
if ( V_214 ) {
V_66 -> V_52 [ V_277 ] = V_214 ;
F_269 ( V_52 ) ;
}
}
V_52 = V_66 -> V_52 [ V_278 ] ;
if ( V_52 )
F_287 ( V_52 ) ;
V_66 -> V_82 = V_82 ;
}
static void F_288 ( struct V_47 * V_48 , struct V_51 * V_52 ,
T_8 V_294 , bool V_67 )
{
F_101 ( & V_52 -> V_129 ) ;
F_101 ( & V_52 -> V_221 ) ;
F_289 ( & V_52 -> V_256 ) ;
V_52 -> V_263 = 0 ;
V_52 -> V_48 = V_48 ;
F_287 ( V_52 ) ;
if ( V_67 ) {
if ( ! F_54 ( V_52 ) )
F_290 ( V_52 ) ;
F_291 ( V_52 ) ;
}
V_52 -> V_294 = V_294 ;
}
static void F_292 ( struct V_60 * V_66 , struct V_70 * V_70 )
{
struct V_47 * V_48 = F_66 ( V_66 ) ;
struct V_51 * V_295 ;
T_1 V_296 ;
F_293 () ;
V_296 = F_294 ( V_70 ) -> V_296 ;
F_295 () ;
if ( F_51 ( ! V_48 ) || F_285 ( V_66 -> V_297 == V_296 ) )
return;
V_295 = F_64 ( V_66 , 1 ) ;
if ( V_295 ) {
F_86 ( V_48 , V_295 , L_25 ) ;
F_65 ( V_66 , NULL , 1 ) ;
F_269 ( V_295 ) ;
}
V_66 -> V_297 = V_296 ;
}
static inline void F_292 ( struct V_60 * V_66 , struct V_70 * V_70 ) { }
static struct V_51 *
F_296 ( struct V_47 * V_48 , bool V_67 , struct V_60 * V_66 ,
struct V_70 * V_70 , T_9 V_298 )
{
struct V_172 * V_172 ;
struct V_51 * V_52 , * V_214 = NULL ;
struct V_2 * V_3 ;
V_299:
F_293 () ;
V_172 = F_294 ( V_70 ) ;
V_3 = F_137 ( V_48 , V_172 ) ;
V_52 = F_64 ( V_66 , V_67 ) ;
if ( ! V_52 || V_52 == & V_48 -> V_300 ) {
V_52 = NULL ;
if ( V_214 ) {
V_52 = V_214 ;
V_214 = NULL ;
} else if ( V_298 & V_301 ) {
F_295 () ;
F_161 ( V_48 -> V_65 -> V_45 ) ;
V_214 = F_297 ( V_286 ,
V_298 | V_302 ,
V_48 -> V_65 -> V_138 ) ;
F_159 ( V_48 -> V_65 -> V_45 ) ;
if ( V_214 )
goto V_299;
else
return & V_48 -> V_300 ;
} else {
V_52 = F_297 ( V_286 ,
V_298 | V_302 ,
V_48 -> V_65 -> V_138 ) ;
}
if ( V_52 ) {
F_288 ( V_48 , V_52 , V_232 -> V_294 , V_67 ) ;
F_276 ( V_52 , V_66 ) ;
F_140 ( V_52 , V_3 ) ;
F_86 ( V_48 , V_52 , L_26 ) ;
} else
V_52 = & V_48 -> V_300 ;
}
if ( V_214 )
F_270 ( V_286 , V_214 ) ;
F_295 () ;
return V_52 ;
}
static struct V_51 * *
F_298 ( struct V_47 * V_48 , int V_287 , int V_82 )
{
switch ( V_287 ) {
case V_290 :
return & V_48 -> V_303 [ 0 ] [ V_82 ] ;
case V_289 :
V_82 = V_304 ;
case V_291 :
return & V_48 -> V_303 [ 1 ] [ V_82 ] ;
case V_292 :
return & V_48 -> V_305 ;
default:
F_299 () ;
}
}
static struct V_51 *
F_286 ( struct V_47 * V_48 , bool V_67 , struct V_60 * V_66 ,
struct V_70 * V_70 , T_9 V_298 )
{
const int V_287 = F_278 ( V_66 -> V_82 ) ;
const int V_82 = F_282 ( V_66 -> V_82 ) ;
struct V_51 * * V_303 = NULL ;
struct V_51 * V_52 = NULL ;
if ( ! V_67 ) {
V_303 = F_298 ( V_48 , V_287 , V_82 ) ;
V_52 = * V_303 ;
}
if ( ! V_52 )
V_52 = F_296 ( V_48 , V_67 , V_66 , V_70 , V_298 ) ;
if ( ! V_67 && ! ( * V_303 ) ) {
V_52 -> V_263 ++ ;
* V_303 = V_52 ;
}
V_52 -> V_263 ++ ;
return V_52 ;
}
static void
F_300 ( struct V_306 * V_170 , unsigned long V_307 )
{
unsigned long V_308 = V_110 - V_170 -> V_171 ;
V_308 = F_81 ( V_308 , 2UL * V_307 ) ;
V_170 -> V_253 = ( 7 * V_170 -> V_253 + 256 ) / 8 ;
V_170 -> V_309 = ( 7 * V_170 -> V_309 + 256 * V_308 ) / 8 ;
V_170 -> V_254 = ( V_170 -> V_309 + 128 ) / V_170 -> V_253 ;
}
static void
F_301 ( struct V_47 * V_48 , struct V_51 * V_52 ,
struct V_60 * V_66 )
{
if ( F_57 ( V_52 ) ) {
F_300 ( & V_66 -> V_170 , V_48 -> V_49 ) ;
F_300 ( & V_52 -> V_217 -> V_170 ,
V_48 -> V_49 ) ;
}
#ifdef F_302
F_300 ( & V_52 -> V_3 -> V_170 , V_48 -> V_250 ) ;
#endif
}
static void
F_303 ( struct V_47 * V_48 , struct V_51 * V_52 ,
struct V_113 * V_227 )
{
T_4 V_310 = 0 ;
T_4 V_311 = F_197 ( V_227 ) ;
if ( V_52 -> V_312 ) {
if ( V_52 -> V_312 < F_94 ( V_227 ) )
V_310 = F_94 ( V_227 ) - V_52 -> V_312 ;
else
V_310 = V_52 -> V_312 - F_94 ( V_227 ) ;
}
V_52 -> V_313 <<= 1 ;
if ( F_234 ( V_48 -> V_65 ) )
V_52 -> V_313 |= ( V_311 < V_314 ) ;
else
V_52 -> V_313 |= ( V_310 > V_315 ) ;
}
static void
F_304 ( struct V_47 * V_48 , struct V_51 * V_52 ,
struct V_60 * V_66 )
{
int V_316 , V_317 ;
if ( ! F_57 ( V_52 ) || F_54 ( V_52 ) )
return;
V_317 = V_316 = F_58 ( V_52 ) ;
if ( V_52 -> V_22 [ 0 ] + V_52 -> V_22 [ 1 ] >= 4 )
F_305 ( V_52 ) ;
if ( V_52 -> V_222 && ( V_52 -> V_222 -> V_123 & V_318 ) )
V_317 = 0 ;
else if ( ! F_237 ( & V_66 -> V_62 . V_64 -> V_252 ) ||
! V_48 -> V_49 ||
( ! F_306 ( V_52 ) && F_221 ( V_52 ) ) )
V_317 = 0 ;
else if ( F_238 ( V_66 -> V_170 . V_253 ) ) {
if ( V_66 -> V_170 . V_254 > V_48 -> V_49 )
V_317 = 0 ;
else
V_317 = 1 ;
}
if ( V_316 != V_317 ) {
F_86 ( V_48 , V_52 , L_27 , V_317 ) ;
if ( V_317 )
F_290 ( V_52 ) ;
else
F_260 ( V_52 ) ;
}
}
static bool
F_307 ( struct V_47 * V_48 , struct V_51 * V_214 ,
struct V_113 * V_227 )
{
struct V_51 * V_52 ;
V_52 = V_48 -> V_242 ;
if ( ! V_52 )
return false ;
if ( F_54 ( V_214 ) )
return false ;
if ( F_54 ( V_52 ) )
return true ;
if ( F_55 ( V_52 ) && ! F_55 ( V_214 ) )
return false ;
if ( F_93 ( V_227 ) && ! F_57 ( V_52 ) )
return true ;
if ( V_214 -> V_3 != V_52 -> V_3 )
return false ;
if ( F_87 ( V_52 ) )
return true ;
if ( V_48 -> V_163 == V_56 &&
F_56 ( V_214 ) == V_56 &&
V_214 -> V_217 -> V_59 == 2 &&
F_188 ( & V_52 -> V_136 ) )
return true ;
if ( ( V_227 -> V_123 & V_124 ) && ! V_52 -> V_236 )
return true ;
if ( F_55 ( V_214 ) && ! F_55 ( V_52 ) )
return true ;
if ( F_188 ( & V_52 -> V_136 ) && ! F_233 ( V_48 , V_52 ) )
return true ;
if ( ! V_48 -> V_245 || ! F_218 ( V_52 ) )
return false ;
if ( F_230 ( V_48 , V_52 , V_227 ) )
return true ;
return false ;
}
static void F_308 ( struct V_47 * V_48 , struct V_51 * V_52 )
{
enum V_6 V_319 = F_56 ( V_48 -> V_242 ) ;
F_86 ( V_48 , V_52 , L_28 ) ;
F_224 ( V_48 , 1 ) ;
if ( V_319 != F_56 ( V_52 ) )
V_52 -> V_3 -> V_154 = 0 ;
F_25 ( ! F_180 ( V_52 ) ) ;
F_176 ( V_48 , V_52 , 1 ) ;
V_52 -> V_111 = 0 ;
F_216 ( V_52 ) ;
}
static void
F_309 ( struct V_47 * V_48 , struct V_51 * V_52 ,
struct V_113 * V_227 )
{
struct V_60 * V_66 = F_266 ( V_227 ) ;
V_48 -> V_235 ++ ;
if ( V_227 -> V_123 & V_124 )
V_52 -> V_236 ++ ;
F_301 ( V_48 , V_52 , V_66 ) ;
F_303 ( V_48 , V_52 , V_227 ) ;
F_304 ( V_48 , V_52 , V_66 ) ;
V_52 -> V_312 = F_94 ( V_227 ) + F_197 ( V_227 ) ;
if ( V_52 == V_48 -> V_242 ) {
if ( F_218 ( V_52 ) ) {
if ( F_243 ( V_227 ) > V_320 ||
V_48 -> V_74 > 1 ) {
F_209 ( V_48 , V_52 ) ;
F_212 ( V_52 ) ;
F_310 ( V_48 -> V_65 ) ;
} else {
F_21 ( V_52 -> V_3 ) ;
F_311 ( V_52 ) ;
}
}
} else if ( F_307 ( V_48 , V_52 , V_227 ) ) {
F_308 ( V_48 , V_52 ) ;
F_310 ( V_48 -> V_65 ) ;
}
}
static void F_312 ( struct V_181 * V_44 , struct V_113 * V_227 )
{
struct V_47 * V_48 = V_44 -> V_68 -> V_69 ;
struct V_51 * V_52 = F_186 ( V_227 ) ;
F_86 ( V_48 , V_52 , L_29 ) ;
F_276 ( V_52 , F_266 ( V_227 ) ) ;
V_227 -> V_241 = V_110 + V_48 -> V_321 [ F_93 ( V_227 ) ] ;
F_313 ( & V_227 -> V_234 , & V_52 -> V_256 ) ;
F_189 ( V_227 ) ;
F_35 ( F_192 ( V_227 ) , V_48 -> V_229 ,
V_227 -> V_123 ) ;
F_309 ( V_48 , V_52 , V_227 ) ;
}
static void F_314 ( struct V_47 * V_48 )
{
struct V_51 * V_52 = V_48 -> V_242 ;
if ( V_48 -> V_233 > V_48 -> V_322 )
V_48 -> V_322 = V_48 -> V_233 ;
if ( V_48 -> V_50 == 1 )
return;
if ( V_48 -> V_235 <= V_323 &&
V_48 -> V_233 <= V_323 )
return;
if ( V_52 && F_58 ( V_52 ) &&
V_52 -> V_251 + V_52 -> V_22 [ 0 ] + V_52 -> V_22 [ 1 ] <
V_323 && V_48 -> V_233 < V_323 )
return;
if ( V_48 -> V_324 ++ < 50 )
return;
if ( V_48 -> V_322 >= V_323 )
V_48 -> V_50 = 1 ;
else
V_48 -> V_50 = 0 ;
}
static bool F_315 ( struct V_47 * V_48 , struct V_51 * V_52 )
{
struct V_60 * V_66 = V_48 -> V_245 ;
if ( ! F_188 ( & V_52 -> V_136 ) )
return false ;
if ( V_52 -> V_3 -> V_137 > 1 )
return false ;
if ( F_235 ( V_48 , & V_52 -> V_3 -> V_170 , true ) )
return false ;
if ( F_87 ( V_52 ) )
return true ;
if ( V_66 && F_238 ( V_66 -> V_170 . V_253 )
&& ( V_52 -> V_111 - V_110 < V_66 -> V_170 . V_254 ) )
return true ;
if ( V_52 -> V_111 - V_110 == 1 )
return true ;
return false ;
}
static void F_316 ( struct V_181 * V_44 , struct V_113 * V_227 )
{
struct V_51 * V_52 = F_186 ( V_227 ) ;
struct V_47 * V_48 = V_52 -> V_48 ;
const int V_76 = F_93 ( V_227 ) ;
unsigned long V_15 ;
V_15 = V_110 ;
F_86 ( V_48 , V_52 , L_30 ,
! ! ( V_227 -> V_123 & V_318 ) ) ;
F_314 ( V_48 ) ;
F_73 ( ! V_48 -> V_233 ) ;
F_73 ( ! V_52 -> V_251 ) ;
V_48 -> V_233 -- ;
V_52 -> V_251 -- ;
( F_192 ( V_227 ) ) -> V_251 -- ;
F_42 ( V_52 -> V_3 , F_317 ( V_227 ) ,
F_318 ( V_227 ) , V_227 -> V_123 ) ;
V_48 -> V_255 [ F_57 ( V_52 ) ] -- ;
if ( V_76 ) {
struct V_1 * V_90 ;
F_266 ( V_227 ) -> V_170 . V_171 = V_15 ;
if ( F_180 ( V_52 ) )
V_90 = V_52 -> V_217 ;
else
V_90 = F_1 ( V_52 -> V_3 , F_53 ( V_52 ) ,
F_56 ( V_52 ) ) ;
V_90 -> V_170 . V_171 = V_15 ;
if ( ! F_123 ( V_227 -> V_38 + V_48 -> V_321 [ 1 ] , V_15 ) )
V_48 -> V_282 = V_15 ;
}
#ifdef F_302
V_52 -> V_3 -> V_170 . V_171 = V_15 ;
#endif
if ( V_48 -> V_242 == V_52 ) {
const bool V_325 = F_188 ( & V_52 -> V_136 ) ;
if ( F_88 ( V_52 ) ) {
F_85 ( V_48 , V_52 ) ;
F_319 ( V_52 ) ;
}
if ( F_315 ( V_48 , V_52 ) ) {
unsigned long V_326 = V_48 -> V_49 ;
if ( ! V_48 -> V_49 )
V_326 = V_48 -> V_250 ;
V_52 -> V_111 = V_110 + V_326 ;
F_320 ( V_52 ) ;
F_86 ( V_48 , V_52 , L_31 ) ;
}
if ( F_87 ( V_52 ) || F_54 ( V_52 ) )
F_224 ( V_48 , 1 ) ;
else if ( V_76 && V_325 &&
! F_232 ( V_48 , V_52 ) ) {
F_236 ( V_48 ) ;
}
}
if ( ! V_48 -> V_233 )
F_69 ( V_48 ) ;
}
static inline int F_321 ( struct V_51 * V_52 )
{
if ( F_218 ( V_52 ) && ! F_322 ( V_52 ) ) {
F_323 ( V_52 ) ;
return V_327 ;
}
return V_328 ;
}
static int F_324 ( struct V_181 * V_44 , int V_31 )
{
struct V_47 * V_48 = V_44 -> V_68 -> V_69 ;
struct V_230 * V_231 = V_232 ;
struct V_60 * V_66 ;
struct V_51 * V_52 ;
V_66 = F_62 ( V_48 , V_231 -> V_63 ) ;
if ( ! V_66 )
return V_328 ;
V_52 = F_64 ( V_66 , F_325 ( V_31 ) ) ;
if ( V_52 ) {
F_276 ( V_52 , V_66 ) ;
return F_321 ( V_52 ) ;
}
return V_328 ;
}
static void F_326 ( struct V_113 * V_227 )
{
struct V_51 * V_52 = F_186 ( V_227 ) ;
if ( V_52 ) {
const int V_31 = F_327 ( V_227 ) ;
F_25 ( ! V_52 -> V_261 [ V_31 ] ) ;
V_52 -> V_261 [ V_31 ] -- ;
F_33 ( F_192 ( V_227 ) ) ;
V_227 -> V_329 . V_330 [ 0 ] = NULL ;
V_227 -> V_329 . V_330 [ 1 ] = NULL ;
F_269 ( V_52 ) ;
}
}
static struct V_51 *
F_328 ( struct V_47 * V_48 , struct V_60 * V_66 ,
struct V_51 * V_52 )
{
F_86 ( V_48 , V_52 , L_32 , V_52 -> V_214 ) ;
F_65 ( V_66 , V_52 -> V_214 , 1 ) ;
F_329 ( V_52 -> V_214 ) ;
F_269 ( V_52 ) ;
return F_64 ( V_66 , 1 ) ;
}
static struct V_51 *
F_330 ( struct V_60 * V_66 , struct V_51 * V_52 )
{
if ( F_249 ( V_52 ) == 1 ) {
V_52 -> V_294 = V_232 -> V_294 ;
F_331 ( V_52 ) ;
F_332 ( V_52 ) ;
return V_52 ;
}
F_65 ( V_66 , NULL , 1 ) ;
F_271 ( V_52 ) ;
F_269 ( V_52 ) ;
return NULL ;
}
static int
F_333 ( struct V_181 * V_44 , struct V_113 * V_227 , struct V_70 * V_70 ,
T_9 V_298 )
{
struct V_47 * V_48 = V_44 -> V_68 -> V_69 ;
struct V_60 * V_66 = F_61 ( V_227 -> V_329 . V_62 ) ;
const int V_31 = F_327 ( V_227 ) ;
const bool V_67 = F_93 ( V_227 ) ;
struct V_51 * V_52 ;
F_334 ( V_298 & V_301 ) ;
F_159 ( V_44 -> V_45 ) ;
F_284 ( V_66 , V_70 ) ;
F_292 ( V_66 , V_70 ) ;
V_272:
V_52 = F_64 ( V_66 , V_67 ) ;
if ( ! V_52 || V_52 == & V_48 -> V_300 ) {
V_52 = F_286 ( V_48 , V_67 , V_66 , V_70 , V_298 ) ;
F_65 ( V_66 , V_52 , V_67 ) ;
} else {
if ( F_220 ( V_52 ) && F_335 ( V_52 ) ) {
F_86 ( V_48 , V_52 , L_33 ) ;
V_52 = F_330 ( V_66 , V_52 ) ;
if ( ! V_52 )
goto V_272;
}
if ( V_52 -> V_214 )
V_52 = F_328 ( V_48 , V_66 , V_52 ) ;
}
V_52 -> V_261 [ V_31 ] ++ ;
V_52 -> V_263 ++ ;
F_31 ( V_52 -> V_3 ) ;
V_227 -> V_329 . V_330 [ 0 ] = V_52 ;
V_227 -> V_329 . V_330 [ 1 ] = V_52 -> V_3 ;
F_161 ( V_44 -> V_45 ) ;
return 0 ;
}
static void F_336 ( struct V_331 * V_332 )
{
struct V_47 * V_48 =
F_3 ( V_332 , struct V_47 , V_75 ) ;
struct V_181 * V_44 = V_48 -> V_65 ;
F_159 ( V_44 -> V_45 ) ;
F_310 ( V_48 -> V_65 ) ;
F_161 ( V_44 -> V_45 ) ;
}
static void F_337 ( unsigned long V_333 )
{
struct V_47 * V_48 = (struct V_47 * ) V_333 ;
struct V_51 * V_52 ;
unsigned long V_334 ;
int V_244 = 1 ;
F_70 ( V_48 , L_34 ) ;
F_338 ( V_48 -> V_65 -> V_45 , V_334 ) ;
V_52 = V_48 -> V_242 ;
if ( V_52 ) {
V_244 = 0 ;
if ( F_257 ( V_52 ) )
goto V_335;
if ( F_87 ( V_52 ) )
goto V_273;
if ( ! V_48 -> V_74 )
goto V_336;
if ( ! F_188 ( & V_52 -> V_136 ) )
goto V_335;
F_259 ( V_52 ) ;
}
V_273:
F_224 ( V_48 , V_244 ) ;
V_335:
F_69 ( V_48 ) ;
V_336:
F_339 ( V_48 -> V_65 -> V_45 , V_334 ) ;
}
static void F_340 ( struct V_47 * V_48 )
{
F_341 ( & V_48 -> V_243 ) ;
F_342 ( & V_48 -> V_75 ) ;
}
static void F_343 ( struct V_47 * V_48 )
{
int V_167 ;
for ( V_167 = 0 ; V_167 < V_80 ; V_167 ++ ) {
if ( V_48 -> V_303 [ 0 ] [ V_167 ] )
F_269 ( V_48 -> V_303 [ 0 ] [ V_167 ] ) ;
if ( V_48 -> V_303 [ 1 ] [ V_167 ] )
F_269 ( V_48 -> V_303 [ 1 ] [ V_167 ] ) ;
}
if ( V_48 -> V_305 )
F_269 ( V_48 -> V_305 ) ;
}
static void F_344 ( struct V_337 * V_338 )
{
struct V_47 * V_48 = V_338 -> V_69 ;
struct V_181 * V_44 = V_48 -> V_65 ;
F_340 ( V_48 ) ;
F_159 ( V_44 -> V_45 ) ;
if ( V_48 -> V_242 )
F_217 ( V_48 , V_48 -> V_242 , 0 ) ;
F_343 ( V_48 ) ;
F_161 ( V_44 -> V_45 ) ;
F_340 ( V_48 ) ;
#ifdef F_302
F_345 ( V_44 , & V_28 ) ;
#else
F_346 ( V_48 -> V_183 ) ;
#endif
F_346 ( V_48 ) ;
}
static int F_347 ( struct V_181 * V_44 , struct V_339 * V_338 )
{
struct V_47 * V_48 ;
struct V_12 * V_27 V_340 ;
int V_167 , V_196 ;
struct V_337 * V_341 ;
V_341 = F_348 ( V_44 , V_338 ) ;
if ( ! V_341 )
return - V_342 ;
V_48 = F_349 ( sizeof( * V_48 ) , V_343 , V_44 -> V_138 ) ;
if ( ! V_48 ) {
F_350 ( & V_341 -> V_344 ) ;
return - V_342 ;
}
V_341 -> V_69 = V_48 ;
V_48 -> V_65 = V_44 ;
F_159 ( V_44 -> V_45 ) ;
V_44 -> V_68 = V_341 ;
F_161 ( V_44 -> V_45 ) ;
V_48 -> V_152 = V_169 ;
#ifdef F_302
V_196 = F_351 ( V_44 , & V_28 ) ;
if ( V_196 )
goto V_345;
V_48 -> V_183 = F_28 ( V_44 -> V_346 ) ;
#else
V_196 = - V_342 ;
V_48 -> V_183 = F_349 ( sizeof( * V_48 -> V_183 ) ,
V_343 , V_48 -> V_65 -> V_138 ) ;
if ( ! V_48 -> V_183 )
goto V_345;
F_125 ( V_48 -> V_183 ) ;
#endif
V_48 -> V_183 -> V_144 = 2 * V_347 ;
V_48 -> V_183 -> V_146 = 2 * V_347 ;
for ( V_167 = 0 ; V_167 < V_348 ; V_167 ++ )
V_48 -> V_224 [ V_167 ] = V_349 ;
F_288 ( V_48 , & V_48 -> V_300 , 1 , 0 ) ;
V_48 -> V_300 . V_263 ++ ;
F_159 ( V_44 -> V_45 ) ;
F_140 ( & V_48 -> V_300 , V_48 -> V_183 ) ;
F_33 ( V_48 -> V_183 ) ;
F_161 ( V_44 -> V_45 ) ;
F_352 ( & V_48 -> V_243 ) ;
V_48 -> V_243 . V_350 = F_337 ;
V_48 -> V_243 . V_333 = ( unsigned long ) V_48 ;
F_353 ( & V_48 -> V_75 , F_336 ) ;
V_48 -> V_280 = V_280 ;
V_48 -> V_321 [ 0 ] = V_321 [ 0 ] ;
V_48 -> V_321 [ 1 ] = V_321 [ 1 ] ;
V_48 -> V_125 = V_125 ;
V_48 -> V_126 = V_126 ;
V_48 -> V_79 [ 0 ] = V_351 ;
V_48 -> V_79 [ 1 ] = V_352 ;
V_48 -> V_100 = V_100 ;
V_48 -> V_258 = V_258 ;
V_48 -> V_49 = V_49 ;
V_48 -> V_250 = V_250 ;
V_48 -> V_102 = 1 ;
V_48 -> V_50 = - 1 ;
V_48 -> V_282 = V_110 - V_216 ;
return 0 ;
V_345:
F_346 ( V_48 ) ;
F_350 ( & V_341 -> V_344 ) ;
return V_196 ;
}
static T_5
F_354 ( unsigned int V_353 , char * V_354 )
{
return sprintf ( V_354 , L_6 , V_353 ) ;
}
static T_5
F_355 ( unsigned int * V_353 , const char * V_354 , T_6 V_59 )
{
char * V_211 = ( char * ) V_354 ;
* V_353 = F_356 ( V_211 , & V_211 , 10 ) ;
return V_59 ;
}
static int T_10 F_357 ( void )
{
int V_196 ;
if ( ! V_351 )
V_351 = 1 ;
if ( ! V_49 )
V_49 = 1 ;
#ifdef F_302
if ( ! V_250 )
V_250 = 1 ;
V_196 = F_358 ( & V_28 ) ;
if ( V_196 )
return V_196 ;
#else
V_250 = 0 ;
#endif
V_196 = - V_342 ;
V_286 = F_359 ( V_51 , 0 ) ;
if ( ! V_286 )
goto V_355;
V_196 = F_360 ( & V_356 ) ;
if ( V_196 )
goto V_357;
return 0 ;
V_357:
F_361 ( V_286 ) ;
V_355:
#ifdef F_302
F_362 ( & V_28 ) ;
#endif
return V_196 ;
}
static void T_11 F_363 ( void )
{
#ifdef F_302
F_362 ( & V_28 ) ;
#endif
F_364 ( & V_356 ) ;
F_361 ( V_286 ) ;
}
