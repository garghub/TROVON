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
static inline bool F_34 ( struct V_2 * V_3 ,
struct V_2 * V_35 )
{
return F_35 ( F_27 ( V_3 ) -> V_32 -> V_36 . V_37 ,
F_27 ( V_35 ) -> V_32 -> V_36 . V_37 ) ;
}
static inline void F_36 ( struct V_2 * V_3 )
{
return F_37 ( F_27 ( V_3 ) ) ;
}
static inline void F_38 ( struct V_2 * V_3 )
{
return F_39 ( F_27 ( V_3 ) ) ;
}
static inline void F_40 ( struct V_2 * V_3 ,
struct V_2 * V_15 , int V_38 )
{
F_41 ( & V_3 -> V_11 . V_19 , V_38 , 1 ) ;
F_10 ( & V_3 -> V_11 ) ;
F_8 ( V_3 , V_15 ) ;
}
static inline void F_42 ( struct V_2 * V_3 ,
unsigned long time , unsigned long V_39 )
{
F_6 ( & V_3 -> V_11 . time , time ) ;
#ifdef F_43
F_6 ( & V_3 -> V_11 . V_39 , V_39 ) ;
#endif
}
static inline void F_44 ( struct V_2 * V_3 , int V_38 )
{
F_41 ( & V_3 -> V_11 . V_19 , V_38 , - 1 ) ;
}
static inline void F_45 ( struct V_2 * V_3 , int V_38 )
{
F_41 ( & V_3 -> V_11 . V_40 , V_38 , 1 ) ;
}
static inline void F_46 ( struct V_2 * V_3 ,
T_1 V_41 , T_1 V_42 , int V_38 )
{
struct V_10 * V_11 = & V_3 -> V_11 ;
unsigned long long V_12 = F_4 () ;
if ( F_5 ( V_12 , V_42 ) )
F_41 ( & V_11 -> V_43 , V_38 , V_12 - V_42 ) ;
if ( F_5 ( V_42 , V_41 ) )
F_41 ( & V_11 -> V_44 , V_38 ,
V_42 - V_41 ) ;
}
static void F_47 ( struct V_10 * V_11 )
{
F_48 ( & V_11 -> V_40 ) ;
F_48 ( & V_11 -> V_43 ) ;
F_48 ( & V_11 -> V_44 ) ;
F_49 ( & V_11 -> time ) ;
#ifdef F_43
F_49 ( & V_11 -> V_39 ) ;
F_49 ( & V_11 -> V_22 ) ;
F_49 ( & V_11 -> V_23 ) ;
F_49 ( & V_11 -> V_18 ) ;
F_49 ( & V_11 -> V_14 ) ;
F_49 ( & V_11 -> V_21 ) ;
F_49 ( & V_11 -> V_17 ) ;
#endif
}
static void F_50 ( struct V_10 * V_45 , struct V_10 * V_46 )
{
F_51 ( & V_45 -> V_40 , & V_46 -> V_40 ) ;
F_51 ( & V_45 -> V_43 , & V_46 -> V_43 ) ;
F_51 ( & V_45 -> V_44 , & V_46 -> V_44 ) ;
F_52 ( & V_46 -> time , & V_46 -> time ) ;
#ifdef F_43
F_52 ( & V_45 -> V_39 , & V_46 -> V_39 ) ;
F_52 ( & V_45 -> V_22 , & V_46 -> V_22 ) ;
F_52 ( & V_45 -> V_23 , & V_46 -> V_23 ) ;
F_52 ( & V_45 -> V_18 , & V_46 -> V_18 ) ;
F_52 ( & V_45 -> V_14 , & V_46 -> V_14 ) ;
F_52 ( & V_45 -> V_21 , & V_46 -> V_21 ) ;
F_52 ( & V_45 -> V_17 , & V_46 -> V_17 ) ;
#endif
}
static void F_53 ( struct V_2 * V_3 )
{
struct V_2 * V_34 = F_33 ( V_3 ) ;
F_54 ( F_27 ( V_3 ) -> V_47 -> V_48 ) ;
if ( F_55 ( ! V_34 ) )
return;
F_50 ( & V_34 -> V_11 , & V_3 -> V_11 ) ;
F_47 ( & V_3 -> V_11 ) ;
}
static inline struct V_2 * F_33 ( struct V_2 * V_3 ) { return NULL ; }
static inline bool F_34 ( struct V_2 * V_3 ,
struct V_2 * V_35 )
{
return true ;
}
static inline void F_36 ( struct V_2 * V_3 ) { }
static inline void F_38 ( struct V_2 * V_3 ) { }
static inline void F_40 ( struct V_2 * V_3 ,
struct V_2 * V_15 , int V_38 ) { }
static inline void F_42 ( struct V_2 * V_3 ,
unsigned long time , unsigned long V_39 ) { }
static inline void F_44 ( struct V_2 * V_3 , int V_38 ) { }
static inline void F_45 ( struct V_2 * V_3 , int V_38 ) { }
static inline void F_46 ( struct V_2 * V_3 ,
T_1 V_41 , T_1 V_42 , int V_38 ) { }
static inline bool F_56 ( struct V_49 * V_50 )
{
if ( ! V_50 -> V_51 && V_50 -> V_52 )
return true ;
else
return false ;
}
static inline enum V_4 F_57 ( struct V_53 * V_54 )
{
if ( F_58 ( V_54 ) )
return V_7 ;
if ( F_59 ( V_54 ) )
return V_55 ;
return V_56 ;
}
static enum V_6 F_60 ( struct V_53 * V_54 )
{
if ( ! F_61 ( V_54 ) )
return V_57 ;
if ( ! F_62 ( V_54 ) )
return V_58 ;
return V_59 ;
}
static inline int F_63 ( enum V_4 V_60 ,
struct V_49 * V_50 ,
struct V_2 * V_3 )
{
if ( V_60 == V_7 )
return V_3 -> V_8 . V_61 ;
return V_3 -> V_9 [ V_60 ] [ V_57 ] . V_61 +
V_3 -> V_9 [ V_60 ] [ V_58 ] . V_61 +
V_3 -> V_9 [ V_60 ] [ V_59 ] . V_61 ;
}
static inline int F_64 ( struct V_49 * V_50 ,
struct V_2 * V_3 )
{
return V_3 -> V_9 [ V_55 ] [ V_57 ] . V_61 +
V_3 -> V_9 [ V_56 ] [ V_57 ] . V_61 ;
}
static inline struct V_62 * F_65 ( struct V_63 * V_64 )
{
return F_25 ( V_64 , struct V_62 , V_64 ) ;
}
static inline struct V_62 * F_66 ( struct V_49 * V_50 ,
struct V_65 * V_66 )
{
if ( V_66 )
return F_65 ( F_67 ( V_66 , V_50 -> V_67 ) ) ;
return NULL ;
}
static inline struct V_53 * F_68 ( struct V_62 * V_68 , bool V_69 )
{
return V_68 -> V_54 [ V_69 ] ;
}
static inline void F_69 ( struct V_62 * V_68 , struct V_53 * V_54 ,
bool V_69 )
{
V_68 -> V_54 [ V_69 ] = V_54 ;
}
static inline struct V_49 * F_70 ( struct V_62 * V_68 )
{
return V_68 -> V_64 . V_47 -> V_70 -> V_71 ;
}
static inline bool F_71 ( struct V_72 * V_72 )
{
return F_72 ( V_72 ) == V_73 || ( V_72 -> V_74 & V_75 ) ;
}
static inline void F_73 ( struct V_49 * V_50 )
{
if ( V_50 -> V_76 ) {
F_74 ( V_50 , L_1 ) ;
F_75 ( & V_50 -> V_77 ) ;
}
}
static inline int F_76 ( struct V_49 * V_50 , bool V_78 ,
unsigned short V_79 )
{
const int V_80 = V_50 -> V_81 [ V_78 ] ;
F_77 ( V_79 >= V_82 ) ;
return V_80 + ( V_80 / V_83 * ( 4 - V_79 ) ) ;
}
static inline int
F_78 ( struct V_49 * V_50 , struct V_53 * V_54 )
{
return F_76 ( V_50 , F_61 ( V_54 ) , V_54 -> V_84 ) ;
}
static inline T_2 F_79 ( unsigned long V_85 ,
unsigned int V_86 )
{
T_2 V_87 = V_85 << V_88 ;
V_87 <<= V_88 ;
F_80 ( V_87 , V_86 ) ;
return V_87 ;
}
static inline T_2 F_81 ( T_2 V_89 , T_2 V_90 )
{
T_3 V_91 = ( T_3 ) ( V_90 - V_89 ) ;
if ( V_91 > 0 )
V_89 = V_90 ;
return V_89 ;
}
static inline T_2 V_89 ( T_2 V_89 , T_2 V_90 )
{
T_3 V_91 = ( T_3 ) ( V_90 - V_89 ) ;
if ( V_91 < 0 )
V_89 = V_90 ;
return V_89 ;
}
static void F_82 ( struct V_1 * V_92 )
{
struct V_2 * V_3 ;
if ( V_92 -> V_93 ) {
V_3 = F_83 ( V_92 -> V_93 ) ;
V_92 -> V_89 = F_81 ( V_92 -> V_89 ,
V_3 -> V_90 ) ;
}
}
static inline unsigned F_84 ( struct V_49 * V_50 ,
struct V_2 * V_3 , bool V_94 )
{
unsigned V_95 , V_96 ;
unsigned V_97 = V_98 - 1 ;
unsigned V_99 = V_98 / 2 ;
unsigned V_100 = F_63 ( V_94 , V_50 , V_3 ) ;
V_95 = F_85 ( V_3 -> V_101 [ V_94 ] , V_100 ) ;
V_96 = F_86 ( V_3 -> V_101 [ V_94 ] , V_100 ) ;
V_3 -> V_101 [ V_94 ] = ( V_97 * V_96 + V_95 + V_99 ) /
V_98 ;
return V_3 -> V_101 [ V_94 ] ;
}
static inline unsigned
F_87 ( struct V_49 * V_50 , struct V_2 * V_3 )
{
return V_50 -> V_102 * V_3 -> V_86 >> V_88 ;
}
static inline unsigned
F_88 ( struct V_49 * V_50 , struct V_53 * V_54 )
{
unsigned V_103 = F_78 ( V_50 , V_54 ) ;
if ( V_50 -> V_104 ) {
unsigned V_105 = F_84 ( V_50 , V_54 -> V_3 ,
F_59 ( V_54 ) ) ;
unsigned V_106 = V_50 -> V_81 [ 1 ] ;
unsigned V_107 = V_106 * V_105 ;
unsigned V_108 = F_87 ( V_50 , V_54 -> V_3 ) ;
if ( V_107 > V_108 ) {
unsigned V_109 = 2 * V_50 -> V_51 ;
unsigned V_110 =
F_85 ( V_103 , V_109 * V_103 / V_106 ) ;
V_103 = F_86 ( V_103 * V_108 / V_107 ,
V_110 ) ;
}
}
return V_103 ;
}
static inline void
F_89 ( struct V_49 * V_50 , struct V_53 * V_54 )
{
unsigned V_103 = F_88 ( V_50 , V_54 ) ;
V_54 -> V_111 = V_112 ;
V_54 -> V_113 = V_112 + V_103 ;
V_54 -> V_114 = V_103 ;
F_90 ( V_50 , V_54 , L_2 , V_54 -> V_113 - V_112 ) ;
}
static inline bool F_91 ( struct V_53 * V_54 )
{
if ( F_92 ( V_54 ) )
return false ;
if ( F_93 ( V_112 , V_54 -> V_113 ) )
return false ;
return true ;
}
static struct V_115 *
F_94 ( struct V_49 * V_50 , struct V_115 * V_116 , struct V_115 * V_117 , T_4 V_118 )
{
T_4 V_119 , V_120 , V_121 = 0 , V_122 = 0 ;
unsigned long V_123 ;
#define F_95 0x01
#define F_96 0x02
unsigned V_124 = 0 ;
if ( V_116 == NULL || V_116 == V_117 )
return V_117 ;
if ( V_117 == NULL )
return V_116 ;
if ( F_97 ( V_116 ) != F_97 ( V_117 ) )
return F_97 ( V_116 ) ? V_116 : V_117 ;
if ( ( V_116 -> V_125 ^ V_117 -> V_125 ) & V_126 )
return V_116 -> V_125 & V_126 ? V_116 : V_117 ;
V_119 = F_98 ( V_116 ) ;
V_120 = F_98 ( V_117 ) ;
V_123 = V_50 -> V_127 * 2 ;
if ( V_119 >= V_118 )
V_121 = V_119 - V_118 ;
else if ( V_119 + V_123 >= V_118 )
V_121 = ( V_118 - V_119 ) * V_50 -> V_128 ;
else
V_124 |= F_95 ;
if ( V_120 >= V_118 )
V_122 = V_120 - V_118 ;
else if ( V_120 + V_123 >= V_118 )
V_122 = ( V_118 - V_120 ) * V_50 -> V_128 ;
else
V_124 |= F_96 ;
switch ( V_124 ) {
case 0 :
if ( V_121 < V_122 )
return V_116 ;
else if ( V_122 < V_121 )
return V_117 ;
else {
if ( V_119 >= V_120 )
return V_116 ;
else
return V_117 ;
}
case F_96 :
return V_116 ;
case F_95 :
return V_117 ;
case ( F_95 | F_96 ) :
default:
if ( V_119 <= V_120 )
return V_116 ;
else
return V_117 ;
}
}
static struct V_53 * F_99 ( struct V_1 * V_129 )
{
if ( ! V_129 -> V_61 )
return NULL ;
if ( ! V_129 -> V_93 )
V_129 -> V_93 = F_100 ( & V_129 -> V_130 ) ;
if ( V_129 -> V_93 )
return F_101 ( V_129 -> V_93 , struct V_53 , V_131 ) ;
return NULL ;
}
static struct V_2 * F_102 ( struct V_1 * V_129 )
{
if ( ! V_129 -> V_93 )
V_129 -> V_93 = F_100 ( & V_129 -> V_130 ) ;
if ( V_129 -> V_93 )
return F_83 ( V_129 -> V_93 ) ;
return NULL ;
}
static void F_103 ( struct V_131 * V_132 , struct V_133 * V_129 )
{
F_104 ( V_132 , V_129 ) ;
F_105 ( V_132 ) ;
}
static void F_106 ( struct V_131 * V_132 , struct V_1 * V_129 )
{
if ( V_129 -> V_93 == V_132 )
V_129 -> V_93 = NULL ;
F_103 ( V_132 , & V_129 -> V_130 ) ;
-- V_129 -> V_61 ;
}
static struct V_115 *
F_107 ( struct V_49 * V_50 , struct V_53 * V_54 ,
struct V_115 * V_118 )
{
struct V_131 * V_134 = F_108 ( & V_118 -> V_131 ) ;
struct V_131 * V_135 = F_109 ( & V_118 -> V_131 ) ;
struct V_115 * V_136 = NULL , * V_137 = NULL ;
F_21 ( F_110 ( & V_118 -> V_131 ) ) ;
if ( V_135 )
V_137 = F_111 ( V_135 ) ;
if ( V_134 )
V_136 = F_111 ( V_134 ) ;
else {
V_134 = F_100 ( & V_54 -> V_138 ) ;
if ( V_134 && V_134 != & V_118 -> V_131 )
V_136 = F_111 ( V_134 ) ;
}
return F_94 ( V_50 , V_136 , V_137 , F_98 ( V_118 ) ) ;
}
static unsigned long F_112 ( struct V_49 * V_50 ,
struct V_53 * V_54 )
{
return ( V_54 -> V_3 -> V_139 - 1 ) * ( F_76 ( V_50 , 1 , 0 ) -
F_76 ( V_50 , F_61 ( V_54 ) , V_54 -> V_84 ) ) ;
}
static inline T_3
F_113 ( struct V_1 * V_92 , struct V_2 * V_3 )
{
return V_3 -> V_90 - V_92 -> V_89 ;
}
static void
F_114 ( struct V_1 * V_92 , struct V_2 * V_3 )
{
struct V_131 * * V_140 = & V_92 -> V_130 . V_131 ;
struct V_131 * V_34 = NULL ;
struct V_2 * V_141 ;
T_3 V_142 = F_113 ( V_92 , V_3 ) ;
int V_93 = 1 ;
while ( * V_140 != NULL ) {
V_34 = * V_140 ;
V_141 = F_83 ( V_34 ) ;
if ( V_142 < F_113 ( V_92 , V_141 ) )
V_140 = & V_34 -> V_143 ;
else {
V_140 = & V_34 -> V_144 ;
V_93 = 0 ;
}
}
if ( V_93 )
V_92 -> V_93 = & V_3 -> V_131 ;
F_115 ( & V_3 -> V_131 , V_34 , V_140 ) ;
F_116 ( & V_3 -> V_131 , & V_92 -> V_130 ) ;
}
static void
F_117 ( struct V_2 * V_3 )
{
if ( V_3 -> V_145 ) {
V_3 -> V_146 = V_3 -> V_145 ;
V_3 -> V_145 = 0 ;
}
}
static void
F_118 ( struct V_2 * V_3 )
{
F_21 ( ! F_110 ( & V_3 -> V_131 ) ) ;
if ( V_3 -> V_147 ) {
V_3 -> V_148 = V_3 -> V_147 ;
V_3 -> V_147 = 0 ;
}
}
static void
F_119 ( struct V_1 * V_92 , struct V_2 * V_3 )
{
unsigned int V_149 = 1 << V_88 ;
struct V_2 * V_150 = V_3 ;
struct V_2 * V_34 ;
bool V_151 ;
F_21 ( ! F_110 ( & V_3 -> V_131 ) ) ;
F_118 ( V_3 ) ;
F_114 ( V_92 , V_3 ) ;
V_151 = ! V_150 -> V_152 ++ ;
V_150 -> V_153 += V_150 -> V_148 ;
V_149 = V_149 * V_150 -> V_148 / V_150 -> V_153 ;
while ( ( V_34 = F_33 ( V_150 ) ) ) {
if ( V_151 ) {
F_117 ( V_150 ) ;
V_151 = ! V_34 -> V_152 ++ ;
V_34 -> V_153 += V_150 -> V_146 ;
}
V_149 = V_149 * V_150 -> V_146 / V_34 -> V_153 ;
V_150 = V_34 ;
}
V_3 -> V_86 = F_120 ( unsigned , V_149 , 1 ) ;
}
static void
F_121 ( struct V_49 * V_50 , struct V_2 * V_3 )
{
struct V_1 * V_92 = & V_50 -> V_154 ;
struct V_2 * V_141 ;
struct V_131 * V_132 ;
V_3 -> V_139 ++ ;
if ( ! F_110 ( & V_3 -> V_131 ) )
return;
V_132 = F_122 ( & V_92 -> V_130 ) ;
if ( V_132 ) {
V_141 = F_83 ( V_132 ) ;
V_3 -> V_90 = V_141 -> V_90 + V_155 ;
} else
V_3 -> V_90 = V_92 -> V_89 ;
F_119 ( V_92 , V_3 ) ;
}
static void
F_123 ( struct V_1 * V_92 , struct V_2 * V_3 )
{
struct V_2 * V_150 = V_3 ;
bool V_151 ;
V_151 = ! -- V_150 -> V_152 ;
V_150 -> V_153 -= V_150 -> V_148 ;
while ( V_151 ) {
struct V_2 * V_34 = F_33 ( V_150 ) ;
F_124 ( V_150 -> V_153 ) ;
V_150 -> V_86 = 0 ;
if ( ! V_34 )
break;
V_151 = ! -- V_34 -> V_152 ;
V_34 -> V_153 -= V_150 -> V_146 ;
V_150 = V_34 ;
}
if ( ! F_110 ( & V_3 -> V_131 ) )
F_106 ( & V_3 -> V_131 , V_92 ) ;
}
static void
F_125 ( struct V_49 * V_50 , struct V_2 * V_3 )
{
struct V_1 * V_92 = & V_50 -> V_154 ;
F_21 ( V_3 -> V_139 < 1 ) ;
V_3 -> V_139 -- ;
if ( V_3 -> V_139 )
return;
F_126 ( V_50 , V_3 , L_3 ) ;
F_123 ( V_92 , V_3 ) ;
V_3 -> V_156 = 0 ;
F_13 ( V_3 ) ;
}
static inline unsigned int F_127 ( struct V_53 * V_54 ,
unsigned int * V_39 )
{
unsigned int V_157 ;
if ( ! V_54 -> V_111 || V_54 -> V_111 == V_112 ) {
V_157 = F_120 ( unsigned , ( V_112 - V_54 -> V_158 ) ,
1 ) ;
} else {
V_157 = V_112 - V_54 -> V_111 ;
if ( V_157 > V_54 -> V_114 ) {
* V_39 = V_157 - V_54 -> V_114 ;
V_157 = V_54 -> V_114 ;
}
if ( F_128 ( V_54 -> V_111 , V_54 -> V_158 ) )
* V_39 += V_54 -> V_111 -
V_54 -> V_158 ;
}
return V_157 ;
}
static void F_129 ( struct V_49 * V_50 , struct V_2 * V_3 ,
struct V_53 * V_54 )
{
struct V_1 * V_92 = & V_50 -> V_154 ;
unsigned int V_159 , V_85 , V_160 = 0 ;
int V_161 = V_3 -> V_139 - F_64 ( V_50 , V_3 )
- V_3 -> V_8 . V_61 ;
unsigned int V_149 ;
F_21 ( V_161 < 0 ) ;
V_159 = V_85 = F_127 ( V_54 , & V_160 ) ;
if ( F_56 ( V_50 ) )
V_85 = V_54 -> V_162 ;
else if ( ! F_61 ( V_54 ) && ! V_161 )
V_85 = V_54 -> V_114 ;
V_149 = V_3 -> V_86 ;
F_123 ( V_92 , V_3 ) ;
V_3 -> V_90 += F_79 ( V_85 , V_149 ) ;
F_119 ( V_92 , V_3 ) ;
if ( F_128 ( V_50 -> V_163 , V_112 ) ) {
V_3 -> V_156 = V_50 -> V_163
- V_112 ;
V_3 -> V_164 = V_50 -> V_165 ;
V_3 -> V_166 = V_50 -> V_167 ;
} else
V_3 -> V_156 = 0 ;
F_126 ( V_50 , V_3 , L_4 , V_3 -> V_90 ,
V_92 -> V_89 ) ;
F_90 ( V_54 -> V_50 , V_54 ,
L_5 ,
V_159 , V_54 -> V_162 , V_85 ,
F_56 ( V_50 ) , V_54 -> V_168 ) ;
F_42 ( V_3 , V_159 , V_160 ) ;
F_14 ( V_3 ) ;
}
static void F_130 ( struct V_2 * V_3 )
{
struct V_1 * V_92 ;
int V_169 , V_170 ;
F_131 ( V_3 , V_169 , V_170 , V_92 )
* V_92 = V_171 ;
F_105 ( & V_3 -> V_131 ) ;
V_3 -> V_172 . V_173 = V_112 ;
}
static void F_132 ( struct V_10 * V_11 )
{
F_133 ( & V_11 -> V_40 ) ;
F_133 ( & V_11 -> V_43 ) ;
F_133 ( & V_11 -> V_44 ) ;
F_133 ( & V_11 -> V_19 ) ;
F_134 ( & V_11 -> time ) ;
#ifdef F_43
F_134 ( & V_11 -> V_39 ) ;
F_134 ( & V_11 -> V_22 ) ;
F_134 ( & V_11 -> V_23 ) ;
F_134 ( & V_11 -> V_18 ) ;
F_134 ( & V_11 -> V_14 ) ;
F_134 ( & V_11 -> V_21 ) ;
F_134 ( & V_11 -> V_17 ) ;
#endif
}
static int F_135 ( struct V_10 * V_11 , T_5 V_174 )
{
if ( F_136 ( & V_11 -> V_40 , V_174 ) ||
F_136 ( & V_11 -> V_43 , V_174 ) ||
F_136 ( & V_11 -> V_44 , V_174 ) ||
F_136 ( & V_11 -> V_19 , V_174 ) ||
F_137 ( & V_11 -> time , V_174 ) )
goto V_175;
#ifdef F_43
if ( F_137 ( & V_11 -> V_39 , V_174 ) ||
F_137 ( & V_11 -> V_22 , V_174 ) ||
F_137 ( & V_11 -> V_23 , V_174 ) ||
F_137 ( & V_11 -> V_18 , V_174 ) ||
F_137 ( & V_11 -> V_14 , V_174 ) ||
F_137 ( & V_11 -> V_21 , V_174 ) ||
F_137 ( & V_11 -> V_17 , V_174 ) )
goto V_175;
#endif
return 0 ;
V_175:
F_132 ( V_11 ) ;
return - V_176 ;
}
static struct V_27 * F_138 ( T_5 V_174 )
{
struct V_26 * V_177 ;
V_177 = F_139 ( sizeof( * V_177 ) , V_178 ) ;
if ( ! V_177 )
return NULL ;
return & V_177 -> V_28 ;
}
static void F_140 ( struct V_27 * V_28 )
{
struct V_26 * V_177 = F_26 ( V_28 ) ;
unsigned int V_146 = F_141 ( V_179 ) ?
V_180 : V_181 ;
if ( F_142 ( V_28 ) == & V_182 )
V_146 *= 2 ;
V_177 -> V_146 = V_146 ;
V_177 -> V_148 = V_146 ;
}
static void F_143 ( struct V_27 * V_28 )
{
F_144 ( F_26 ( V_28 ) ) ;
}
static void F_145 ( struct V_27 * V_28 )
{
struct V_32 * V_32 = F_142 ( V_28 ) ;
bool V_183 = F_141 ( V_179 ) ;
unsigned int V_146 = V_183 ? V_180 : V_181 ;
if ( V_32 == & V_182 )
V_146 *= 2 ;
F_124 ( F_146 ( & V_32 -> V_36 , V_146 , V_183 , true , false ) ) ;
F_124 ( F_146 ( & V_32 -> V_36 , V_146 , V_183 , true , true ) ) ;
}
static struct V_24 * F_147 ( T_5 V_174 , int V_140 )
{
struct V_2 * V_3 ;
V_3 = F_148 ( sizeof( * V_3 ) , V_174 , V_140 ) ;
if ( ! V_3 )
return NULL ;
F_130 ( V_3 ) ;
if ( F_135 ( & V_3 -> V_11 , V_174 ) ) {
F_144 ( V_3 ) ;
return NULL ;
}
return & V_3 -> V_25 ;
}
static void F_149 ( struct V_24 * V_25 )
{
struct V_2 * V_3 = F_24 ( V_25 ) ;
struct V_26 * V_177 = F_31 ( V_25 -> V_30 -> V_32 ) ;
V_3 -> V_146 = V_177 -> V_146 ;
V_3 -> V_148 = V_177 -> V_148 ;
}
static void F_150 ( struct V_24 * V_25 )
{
struct V_2 * V_3 = F_24 ( V_25 ) ;
int V_169 ;
for ( V_169 = 0 ; V_169 < V_82 ; V_169 ++ ) {
if ( V_3 -> V_184 [ 0 ] [ V_169 ] )
F_151 ( V_3 -> V_184 [ 0 ] [ V_169 ] ) ;
if ( V_3 -> V_184 [ 1 ] [ V_169 ] )
F_151 ( V_3 -> V_184 [ 1 ] [ V_169 ] ) ;
}
if ( V_3 -> V_185 )
F_151 ( V_3 -> V_185 ) ;
F_53 ( V_3 ) ;
}
static void F_152 ( struct V_24 * V_25 )
{
struct V_2 * V_3 = F_24 ( V_25 ) ;
F_132 ( & V_3 -> V_11 ) ;
return F_144 ( V_3 ) ;
}
static void F_153 ( struct V_24 * V_25 )
{
struct V_2 * V_3 = F_24 ( V_25 ) ;
F_47 ( & V_3 -> V_11 ) ;
}
static struct V_2 * F_154 ( struct V_49 * V_50 ,
struct V_32 * V_32 )
{
struct V_29 * V_30 ;
V_30 = F_155 ( V_32 , V_50 -> V_67 ) ;
if ( F_156 ( V_30 ) )
return F_29 ( V_30 ) ;
return NULL ;
}
static void F_157 ( struct V_53 * V_54 , struct V_2 * V_3 )
{
V_54 -> V_3 = V_3 ;
F_36 ( V_3 ) ;
}
static T_2 F_158 ( struct V_186 * V_187 ,
struct V_24 * V_25 , int V_188 )
{
struct V_2 * V_3 = F_24 ( V_25 ) ;
if ( ! V_3 -> V_189 )
return 0 ;
return F_159 ( V_187 , V_25 , V_3 -> V_189 ) ;
}
static int F_160 ( struct V_186 * V_187 , void * V_190 )
{
F_161 ( V_187 , F_162 ( F_163 ( V_187 ) ) ,
F_158 , & V_31 ,
0 , false ) ;
return 0 ;
}
static T_2 F_164 ( struct V_186 * V_187 ,
struct V_24 * V_25 , int V_188 )
{
struct V_2 * V_3 = F_24 ( V_25 ) ;
if ( ! V_3 -> V_191 )
return 0 ;
return F_159 ( V_187 , V_25 , V_3 -> V_191 ) ;
}
static int F_165 ( struct V_186 * V_187 , void * V_190 )
{
F_161 ( V_187 , F_162 ( F_163 ( V_187 ) ) ,
F_164 , & V_31 ,
0 , false ) ;
return 0 ;
}
static int F_166 ( struct V_186 * V_187 , void * V_190 )
{
struct V_32 * V_32 = F_162 ( F_163 ( V_187 ) ) ;
struct V_26 * V_177 = F_31 ( V_32 ) ;
unsigned int V_192 = 0 ;
if ( V_177 )
V_192 = V_177 -> V_146 ;
F_167 ( V_187 , L_6 , V_192 ) ;
return 0 ;
}
static int F_168 ( struct V_186 * V_187 , void * V_190 )
{
struct V_32 * V_32 = F_162 ( F_163 ( V_187 ) ) ;
struct V_26 * V_177 = F_31 ( V_32 ) ;
unsigned int V_192 = 0 ;
if ( V_177 )
V_192 = V_177 -> V_148 ;
F_167 ( V_187 , L_6 , V_192 ) ;
return 0 ;
}
static T_6 F_169 ( struct V_193 * V_194 ,
char * V_195 , T_7 V_196 , T_8 V_188 ,
bool V_183 , bool V_197 )
{
unsigned int F_85 = V_183 ? V_198 : V_199 ;
unsigned int F_86 = V_183 ? V_200 : V_201 ;
struct V_32 * V_32 = F_162 ( F_170 ( V_194 ) ) ;
struct V_202 V_203 ;
struct V_2 * V_3 ;
struct V_26 * V_204 ;
int V_205 ;
T_2 V_190 ;
V_205 = F_171 ( V_32 , & V_31 , V_195 , & V_203 ) ;
if ( V_205 )
return V_205 ;
if ( sscanf ( V_203 . V_206 , L_7 , & V_190 ) == 1 ) {
V_205 = - V_207 ;
if ( ! V_190 && V_183 )
goto V_208;
} else if ( ! strcmp ( F_172 ( V_203 . V_206 ) , L_8 ) ) {
V_190 = 0 ;
} else {
V_205 = - V_209 ;
goto V_208;
}
V_3 = F_29 ( V_203 . V_30 ) ;
V_204 = F_31 ( V_32 ) ;
V_205 = - V_207 ;
if ( ! V_190 || ( V_190 >= F_85 && V_190 <= F_86 ) ) {
if ( ! V_197 ) {
V_3 -> V_189 = V_190 ;
V_3 -> V_145 = V_190 ? : V_204 -> V_146 ;
} else {
V_3 -> V_191 = V_190 ;
V_3 -> V_147 = V_190 ? : V_204 -> V_148 ;
}
V_205 = 0 ;
}
V_208:
F_173 ( & V_203 ) ;
return V_205 ? : V_196 ;
}
static T_6 F_174 ( struct V_193 * V_194 ,
char * V_195 , T_7 V_196 , T_8 V_188 )
{
return F_169 ( V_194 , V_195 , V_196 , V_188 , false , false ) ;
}
static T_6 F_175 ( struct V_193 * V_194 ,
char * V_195 , T_7 V_196 , T_8 V_188 )
{
return F_169 ( V_194 , V_195 , V_196 , V_188 , false , true ) ;
}
static int F_146 ( struct V_210 * V_36 , T_2 V_192 ,
bool V_183 , bool V_211 , bool V_197 )
{
unsigned int F_85 = V_183 ? V_198 : V_199 ;
unsigned int F_86 = V_183 ? V_200 : V_201 ;
struct V_32 * V_32 = F_162 ( V_36 ) ;
struct V_29 * V_30 ;
struct V_26 * V_204 ;
int V_205 = 0 ;
if ( V_192 < F_85 || V_192 > F_86 )
return - V_207 ;
F_176 ( & V_32 -> V_212 ) ;
V_204 = F_31 ( V_32 ) ;
if ( ! V_204 ) {
V_205 = - V_209 ;
goto V_213;
}
if ( ! V_197 )
V_204 -> V_146 = V_192 ;
else
V_204 -> V_148 = V_192 ;
F_177 (blkg, &blkcg->blkg_list, blkcg_node) {
struct V_2 * V_3 = F_29 ( V_30 ) ;
if ( ! V_3 )
continue;
if ( ! V_197 ) {
if ( V_211 )
V_3 -> V_189 = 0 ;
if ( ! V_3 -> V_189 )
V_3 -> V_145 = V_204 -> V_146 ;
} else {
if ( V_211 )
V_3 -> V_191 = 0 ;
if ( ! V_3 -> V_191 )
V_3 -> V_147 = V_204 -> V_148 ;
}
}
V_213:
F_178 ( & V_32 -> V_212 ) ;
return V_205 ;
}
static int F_179 ( struct V_210 * V_36 , struct V_214 * V_215 ,
T_2 V_192 )
{
return F_146 ( V_36 , V_192 , false , false , false ) ;
}
static int F_180 ( struct V_210 * V_36 ,
struct V_214 * V_215 , T_2 V_192 )
{
return F_146 ( V_36 , V_192 , false , false , true ) ;
}
static int F_181 ( struct V_186 * V_187 , void * V_190 )
{
F_161 ( V_187 , F_162 ( F_163 ( V_187 ) ) , V_216 ,
& V_31 , F_182 ( V_187 ) -> V_217 , false ) ;
return 0 ;
}
static int F_183 ( struct V_186 * V_187 , void * V_190 )
{
F_161 ( V_187 , F_162 ( F_163 ( V_187 ) ) , V_218 ,
& V_31 , F_182 ( V_187 ) -> V_217 , true ) ;
return 0 ;
}
static T_2 F_184 ( struct V_186 * V_187 ,
struct V_24 * V_25 , int V_188 )
{
T_2 V_219 = F_185 ( F_28 ( V_25 ) ,
& V_31 , V_188 ) ;
return F_159 ( V_187 , V_25 , V_219 ) ;
}
static T_2 F_186 ( struct V_186 * V_187 ,
struct V_24 * V_25 , int V_188 )
{
struct V_220 V_219 = F_187 ( F_28 ( V_25 ) ,
& V_31 , V_188 ) ;
return F_188 ( V_187 , V_25 , & V_219 ) ;
}
static int F_189 ( struct V_186 * V_187 , void * V_190 )
{
F_161 ( V_187 , F_162 ( F_163 ( V_187 ) ) ,
F_184 , & V_31 ,
F_182 ( V_187 ) -> V_217 , false ) ;
return 0 ;
}
static int F_190 ( struct V_186 * V_187 , void * V_190 )
{
F_161 ( V_187 , F_162 ( F_163 ( V_187 ) ) ,
F_186 , & V_31 ,
F_182 ( V_187 ) -> V_217 , true ) ;
return 0 ;
}
static T_2 F_191 ( struct V_186 * V_187 , struct V_24 * V_25 ,
int V_188 )
{
T_2 V_219 = F_15 ( & V_25 -> V_30 -> V_221 ) ;
return F_159 ( V_187 , V_25 , V_219 >> 9 ) ;
}
static int F_192 ( struct V_186 * V_187 , void * V_190 )
{
F_161 ( V_187 , F_162 ( F_163 ( V_187 ) ) ,
F_191 , & V_31 , 0 , false ) ;
return 0 ;
}
static T_2 F_193 ( struct V_186 * V_187 ,
struct V_24 * V_25 , int V_188 )
{
struct V_220 V_222 = F_187 ( V_25 -> V_30 , NULL ,
F_194 ( struct V_29 , V_221 ) ) ;
T_2 V_219 = F_195 ( & V_222 . V_223 [ V_224 ] ) +
F_195 ( & V_222 . V_223 [ V_225 ] ) ;
return F_159 ( V_187 , V_25 , V_219 >> 9 ) ;
}
static int F_196 ( struct V_186 * V_187 , void * V_190 )
{
F_161 ( V_187 , F_162 ( F_163 ( V_187 ) ) ,
F_193 , & V_31 , 0 ,
false ) ;
return 0 ;
}
static T_2 F_197 ( struct V_186 * V_187 ,
struct V_24 * V_25 , int V_188 )
{
struct V_2 * V_3 = F_24 ( V_25 ) ;
T_2 V_226 = F_198 ( & V_3 -> V_11 . V_23 ) ;
T_2 V_190 = 0 ;
if ( V_226 ) {
V_190 = F_198 ( & V_3 -> V_11 . V_22 ) ;
V_190 = F_199 ( V_190 , V_226 ) ;
}
F_159 ( V_187 , V_25 , V_190 ) ;
return 0 ;
}
static int F_200 ( struct V_186 * V_187 , void * V_190 )
{
F_161 ( V_187 , F_162 ( F_163 ( V_187 ) ) ,
F_197 , & V_31 ,
0 , false ) ;
return 0 ;
}
static int F_201 ( struct V_186 * V_187 , void * V_190 )
{
struct V_32 * V_32 = F_162 ( F_163 ( V_187 ) ) ;
struct V_26 * V_177 = F_31 ( V_32 ) ;
F_167 ( V_187 , L_9 , V_177 -> V_146 ) ;
F_161 ( V_187 , V_32 , F_158 ,
& V_31 , 0 , false ) ;
return 0 ;
}
static T_6 F_202 ( struct V_193 * V_194 ,
char * V_195 , T_7 V_196 , T_8 V_188 )
{
char * V_227 ;
int V_205 ;
T_2 V_190 ;
V_195 = F_172 ( V_195 ) ;
V_190 = F_203 ( V_195 , & V_227 , 0 ) ;
if ( * V_227 == '\0' || sscanf ( V_195 , L_10 , & V_190 ) == 1 ) {
V_205 = F_146 ( F_170 ( V_194 ) , V_190 , true , false , false ) ;
return V_205 ? : V_196 ;
}
return F_169 ( V_194 , V_195 , V_196 , V_188 , true , false ) ;
}
static struct V_2 * F_154 ( struct V_49 * V_50 ,
struct V_32 * V_32 )
{
return V_50 -> V_228 ;
}
static inline void
F_157 ( struct V_53 * V_54 , struct V_2 * V_3 ) {
V_54 -> V_3 = V_3 ;
}
static void F_204 ( struct V_49 * V_50 , struct V_53 * V_54 ,
bool V_229 )
{
struct V_131 * * V_230 , * V_34 ;
struct V_53 * V_231 ;
unsigned long V_232 ;
struct V_1 * V_92 ;
int V_93 ;
int V_233 = 1 ;
V_92 = F_1 ( V_54 -> V_3 , F_57 ( V_54 ) , F_60 ( V_54 ) ) ;
if ( F_58 ( V_54 ) ) {
V_232 = V_155 ;
V_34 = F_122 ( & V_92 -> V_130 ) ;
if ( V_34 && V_34 != & V_54 -> V_131 ) {
V_231 = F_101 ( V_34 , struct V_53 , V_131 ) ;
V_232 += V_231 -> V_232 ;
} else
V_232 += V_112 ;
} else if ( ! V_229 ) {
V_232 = F_112 ( V_50 , V_54 ) + V_112 ;
V_232 -= V_54 -> V_234 ;
V_54 -> V_234 = 0 ;
} else {
V_232 = - V_235 ;
V_231 = F_99 ( V_92 ) ;
V_232 += V_231 ? V_231 -> V_232 : V_112 ;
}
if ( ! F_110 ( & V_54 -> V_131 ) ) {
V_233 = 0 ;
if ( V_232 == V_54 -> V_232 && V_54 -> V_236 == V_92 )
return;
F_106 ( & V_54 -> V_131 , V_54 -> V_236 ) ;
V_54 -> V_236 = NULL ;
}
V_93 = 1 ;
V_34 = NULL ;
V_54 -> V_236 = V_92 ;
V_230 = & V_92 -> V_130 . V_131 ;
while ( * V_230 ) {
V_34 = * V_230 ;
V_231 = F_101 ( V_34 , struct V_53 , V_131 ) ;
if ( F_93 ( V_232 , V_231 -> V_232 ) )
V_230 = & V_34 -> V_143 ;
else {
V_230 = & V_34 -> V_144 ;
V_93 = 0 ;
}
}
if ( V_93 )
V_92 -> V_93 = & V_54 -> V_131 ;
V_54 -> V_232 = V_232 ;
F_115 ( & V_54 -> V_131 , V_34 , V_230 ) ;
F_116 ( & V_54 -> V_131 , & V_92 -> V_130 ) ;
V_92 -> V_61 ++ ;
if ( V_229 || ! V_233 )
return;
F_121 ( V_50 , V_54 -> V_3 ) ;
}
static struct V_53 *
F_205 ( struct V_49 * V_50 , struct V_133 * V_129 ,
T_4 V_237 , struct V_131 * * V_238 ,
struct V_131 * * * V_239 )
{
struct V_131 * * V_230 , * V_34 ;
struct V_53 * V_54 = NULL ;
V_34 = NULL ;
V_230 = & V_129 -> V_131 ;
while ( * V_230 ) {
struct V_131 * * V_132 ;
V_34 = * V_230 ;
V_54 = F_101 ( V_34 , struct V_53 , V_240 ) ;
if ( V_237 > F_98 ( V_54 -> V_241 ) )
V_132 = & ( * V_230 ) -> V_144 ;
else if ( V_237 < F_98 ( V_54 -> V_241 ) )
V_132 = & ( * V_230 ) -> V_143 ;
else
break;
V_230 = V_132 ;
V_54 = NULL ;
}
* V_238 = V_34 ;
if ( V_239 )
* V_239 = V_230 ;
return V_54 ;
}
static void F_206 ( struct V_49 * V_50 , struct V_53 * V_54 )
{
struct V_131 * * V_230 , * V_34 ;
struct V_53 * V_231 ;
if ( V_54 -> V_242 ) {
F_104 ( & V_54 -> V_240 , V_54 -> V_242 ) ;
V_54 -> V_242 = NULL ;
}
if ( F_58 ( V_54 ) )
return;
if ( ! V_54 -> V_241 )
return;
V_54 -> V_242 = & V_50 -> V_243 [ V_54 -> V_244 ] ;
V_231 = F_205 ( V_50 , V_54 -> V_242 ,
F_98 ( V_54 -> V_241 ) , & V_34 , & V_230 ) ;
if ( ! V_231 ) {
F_115 ( & V_54 -> V_240 , V_34 , V_230 ) ;
F_116 ( & V_54 -> V_240 , V_54 -> V_242 ) ;
} else
V_54 -> V_242 = NULL ;
}
static void F_207 ( struct V_49 * V_50 , struct V_53 * V_54 )
{
if ( F_208 ( V_54 ) ) {
F_204 ( V_50 , V_54 , 0 ) ;
F_206 ( V_50 , V_54 ) ;
}
}
static void F_209 ( struct V_49 * V_50 , struct V_53 * V_54 )
{
F_90 ( V_50 , V_54 , L_11 ) ;
F_21 ( F_208 ( V_54 ) ) ;
F_210 ( V_54 ) ;
V_50 -> V_76 ++ ;
if ( F_61 ( V_54 ) )
V_50 -> V_245 ++ ;
F_207 ( V_50 , V_54 ) ;
}
static void F_211 ( struct V_49 * V_50 , struct V_53 * V_54 )
{
F_90 ( V_50 , V_54 , L_12 ) ;
F_21 ( ! F_208 ( V_54 ) ) ;
F_212 ( V_54 ) ;
if ( ! F_110 ( & V_54 -> V_131 ) ) {
F_106 ( & V_54 -> V_131 , V_54 -> V_236 ) ;
V_54 -> V_236 = NULL ;
}
if ( V_54 -> V_242 ) {
F_104 ( & V_54 -> V_240 , V_54 -> V_242 ) ;
V_54 -> V_242 = NULL ;
}
F_125 ( V_50 , V_54 -> V_3 ) ;
F_21 ( ! V_50 -> V_76 ) ;
V_50 -> V_76 -- ;
if ( F_61 ( V_54 ) )
V_50 -> V_245 -- ;
}
static void F_213 ( struct V_115 * V_246 )
{
struct V_53 * V_54 = F_214 ( V_246 ) ;
const int V_78 = F_97 ( V_246 ) ;
F_21 ( ! V_54 -> V_19 [ V_78 ] ) ;
V_54 -> V_19 [ V_78 ] -- ;
F_215 ( & V_54 -> V_138 , V_246 ) ;
if ( F_208 ( V_54 ) && F_216 ( & V_54 -> V_138 ) ) {
if ( V_54 -> V_242 ) {
F_104 ( & V_54 -> V_240 , V_54 -> V_242 ) ;
V_54 -> V_242 = NULL ;
}
}
}
static void F_217 ( struct V_115 * V_246 )
{
struct V_53 * V_54 = F_214 ( V_246 ) ;
struct V_49 * V_50 = V_54 -> V_50 ;
struct V_115 * V_137 ;
V_54 -> V_19 [ F_97 ( V_246 ) ] ++ ;
F_218 ( & V_54 -> V_138 , V_246 ) ;
if ( ! F_208 ( V_54 ) )
F_209 ( V_50 , V_54 ) ;
V_137 = V_54 -> V_241 ;
V_54 -> V_241 = F_94 ( V_50 , V_54 -> V_241 , V_246 , V_50 -> V_247 ) ;
if ( V_137 != V_54 -> V_241 )
F_206 ( V_50 , V_54 ) ;
F_21 ( ! V_54 -> V_241 ) ;
}
static void F_219 ( struct V_53 * V_54 , struct V_115 * V_246 )
{
F_215 ( & V_54 -> V_138 , V_246 ) ;
V_54 -> V_19 [ F_97 ( V_246 ) ] -- ;
F_44 ( F_220 ( V_246 ) , V_246 -> V_125 ) ;
F_217 ( V_246 ) ;
F_40 ( F_220 ( V_246 ) , V_54 -> V_50 -> V_248 ,
V_246 -> V_125 ) ;
}
static struct V_115 *
F_221 ( struct V_49 * V_50 , struct V_72 * V_72 )
{
struct V_249 * V_250 = V_251 ;
struct V_62 * V_68 ;
struct V_53 * V_54 ;
V_68 = F_66 ( V_50 , V_250 -> V_65 ) ;
if ( ! V_68 )
return NULL ;
V_54 = F_68 ( V_68 , F_71 ( V_72 ) ) ;
if ( V_54 )
return F_222 ( & V_54 -> V_138 , F_223 ( V_72 ) ) ;
return NULL ;
}
static void F_224 ( struct V_252 * V_47 , struct V_115 * V_246 )
{
struct V_49 * V_50 = V_47 -> V_70 -> V_71 ;
V_50 -> V_253 ++ ;
F_90 ( V_50 , F_214 ( V_246 ) , L_13 ,
V_50 -> V_253 ) ;
V_50 -> V_247 = F_98 ( V_246 ) + F_225 ( V_246 ) ;
}
static void F_226 ( struct V_252 * V_47 , struct V_115 * V_246 )
{
struct V_49 * V_50 = V_47 -> V_70 -> V_71 ;
F_77 ( ! V_50 -> V_253 ) ;
V_50 -> V_253 -- ;
F_90 ( V_50 , F_214 ( V_246 ) , L_14 ,
V_50 -> V_253 ) ;
}
static void F_227 ( struct V_115 * V_246 )
{
struct V_53 * V_54 = F_214 ( V_246 ) ;
if ( V_54 -> V_241 == V_246 )
V_54 -> V_241 = F_107 ( V_54 -> V_50 , V_54 , V_246 ) ;
F_228 ( & V_246 -> V_254 ) ;
F_213 ( V_246 ) ;
V_54 -> V_50 -> V_255 -- ;
F_44 ( F_220 ( V_246 ) , V_246 -> V_125 ) ;
if ( V_246 -> V_125 & V_126 ) {
F_77 ( ! V_54 -> V_256 ) ;
V_54 -> V_256 -- ;
}
}
static int F_229 ( struct V_252 * V_47 , struct V_115 * * V_257 ,
struct V_72 * V_72 )
{
struct V_49 * V_50 = V_47 -> V_70 -> V_71 ;
struct V_115 * V_258 ;
V_258 = F_221 ( V_50 , V_72 ) ;
if ( V_258 && F_230 ( V_258 , V_72 ) ) {
* V_257 = V_258 ;
return V_259 ;
}
return V_260 ;
}
static void F_231 ( struct V_252 * V_47 , struct V_115 * V_257 ,
int type )
{
if ( type == V_259 ) {
struct V_53 * V_54 = F_214 ( V_257 ) ;
F_219 ( V_54 , V_257 ) ;
}
}
static void F_232 ( struct V_252 * V_47 , struct V_115 * V_257 ,
struct V_72 * V_72 )
{
F_45 ( F_220 ( V_257 ) , V_72 -> V_74 ) ;
}
static void
F_233 ( struct V_252 * V_47 , struct V_115 * V_246 ,
struct V_115 * V_136 )
{
struct V_53 * V_54 = F_214 ( V_246 ) ;
struct V_49 * V_50 = V_47 -> V_70 -> V_71 ;
if ( ! F_234 ( & V_246 -> V_254 ) && ! F_234 ( & V_136 -> V_254 ) &&
F_93 ( V_136 -> V_261 , V_246 -> V_261 ) &&
V_54 == F_214 ( V_136 ) ) {
F_235 ( & V_246 -> V_254 , & V_136 -> V_254 ) ;
V_246 -> V_261 = V_136 -> V_261 ;
}
if ( V_54 -> V_241 == V_136 )
V_54 -> V_241 = V_246 ;
F_227 ( V_136 ) ;
F_45 ( F_220 ( V_246 ) , V_136 -> V_125 ) ;
V_54 = F_214 ( V_136 ) ;
if ( F_208 ( V_54 ) && F_216 ( & V_54 -> V_138 ) &&
V_54 != V_50 -> V_262 )
F_211 ( V_50 , V_54 ) ;
}
static int F_236 ( struct V_252 * V_47 , struct V_115 * V_246 ,
struct V_72 * V_72 )
{
struct V_49 * V_50 = V_47 -> V_70 -> V_71 ;
struct V_62 * V_68 ;
struct V_53 * V_54 ;
if ( F_71 ( V_72 ) && ! F_97 ( V_246 ) )
return false ;
V_68 = F_66 ( V_50 , V_251 -> V_65 ) ;
if ( ! V_68 )
return false ;
V_54 = F_68 ( V_68 , F_71 ( V_72 ) ) ;
return V_54 == F_214 ( V_246 ) ;
}
static inline void F_237 ( struct V_49 * V_50 , struct V_53 * V_54 )
{
F_238 ( & V_50 -> V_263 ) ;
F_17 ( V_54 -> V_3 ) ;
}
static void F_239 ( struct V_49 * V_50 ,
struct V_53 * V_54 )
{
if ( V_54 ) {
F_90 ( V_50 , V_54 , L_15 ,
V_50 -> V_167 , V_50 -> V_165 ) ;
F_23 ( V_54 -> V_3 ) ;
V_54 -> V_111 = 0 ;
V_54 -> V_158 = V_112 ;
V_54 -> V_114 = 0 ;
V_54 -> V_113 = 0 ;
V_54 -> V_162 = 0 ;
V_54 -> V_168 = 0 ;
F_240 ( V_54 ) ;
F_241 ( V_54 ) ;
F_242 ( V_54 ) ;
F_243 ( V_54 ) ;
F_244 ( V_54 ) ;
F_237 ( V_50 , V_54 ) ;
}
V_50 -> V_262 = V_54 ;
}
static void
F_245 ( struct V_49 * V_50 , struct V_53 * V_54 ,
bool V_264 )
{
F_90 ( V_50 , V_54 , L_16 , V_264 ) ;
if ( F_246 ( V_54 ) )
F_237 ( V_50 , V_54 ) ;
F_240 ( V_54 ) ;
F_247 ( V_54 ) ;
if ( F_248 ( V_54 ) && F_249 ( V_54 ) )
F_250 ( V_54 ) ;
if ( V_264 ) {
if ( F_92 ( V_54 ) )
V_54 -> V_234 = F_88 ( V_50 , V_54 ) ;
else
V_54 -> V_234 = V_54 -> V_113 - V_112 ;
F_90 ( V_50 , V_54 , L_17 , V_54 -> V_234 ) ;
}
F_129 ( V_50 , V_54 -> V_3 , V_54 ) ;
if ( F_208 ( V_54 ) && F_216 ( & V_54 -> V_138 ) )
F_211 ( V_50 , V_54 ) ;
F_207 ( V_50 , V_54 ) ;
if ( V_54 == V_50 -> V_262 )
V_50 -> V_262 = NULL ;
if ( V_50 -> V_265 ) {
F_251 ( V_50 -> V_265 -> V_64 . V_66 ) ;
V_50 -> V_265 = NULL ;
}
}
static inline void F_252 ( struct V_49 * V_50 , bool V_264 )
{
struct V_53 * V_54 = V_50 -> V_262 ;
if ( V_54 )
F_245 ( V_50 , V_54 , V_264 ) ;
}
static struct V_53 * F_253 ( struct V_49 * V_50 )
{
struct V_1 * V_92 = F_1 ( V_50 -> V_248 ,
V_50 -> V_167 , V_50 -> V_165 ) ;
if ( ! V_50 -> V_255 )
return NULL ;
if ( ! V_92 )
return NULL ;
if ( F_216 ( & V_92 -> V_130 ) )
return NULL ;
return F_99 ( V_92 ) ;
}
static struct V_53 * F_254 ( struct V_49 * V_50 )
{
struct V_2 * V_3 ;
struct V_53 * V_54 ;
int V_169 , V_170 ;
struct V_1 * V_92 ;
if ( ! V_50 -> V_255 )
return NULL ;
V_3 = F_255 ( V_50 ) ;
if ( ! V_3 )
return NULL ;
F_131 (cfqg, i, j, st)
if ( ( V_54 = F_99 ( V_92 ) ) != NULL )
return V_54 ;
return NULL ;
}
static struct V_53 * F_256 ( struct V_49 * V_50 ,
struct V_53 * V_54 )
{
if ( ! V_54 )
V_54 = F_253 ( V_50 ) ;
F_239 ( V_50 , V_54 ) ;
return V_54 ;
}
static inline T_4 F_257 ( struct V_49 * V_50 ,
struct V_115 * V_246 )
{
if ( F_98 ( V_246 ) >= V_50 -> V_247 )
return F_98 ( V_246 ) - V_50 -> V_247 ;
else
return V_50 -> V_247 - F_98 ( V_246 ) ;
}
static inline int F_258 ( struct V_49 * V_50 , struct V_53 * V_54 ,
struct V_115 * V_246 )
{
return F_257 ( V_50 , V_246 ) <= V_266 ;
}
static struct V_53 * F_259 ( struct V_49 * V_50 ,
struct V_53 * V_267 )
{
struct V_133 * V_129 = & V_50 -> V_243 [ V_267 -> V_244 ] ;
struct V_131 * V_34 , * V_140 ;
struct V_53 * V_231 ;
T_4 V_237 = V_50 -> V_247 ;
if ( F_216 ( V_129 ) )
return NULL ;
V_231 = F_205 ( V_50 , V_129 , V_237 , & V_34 , NULL ) ;
if ( V_231 )
return V_231 ;
V_231 = F_101 ( V_34 , struct V_53 , V_240 ) ;
if ( F_258 ( V_50 , V_267 , V_231 -> V_241 ) )
return V_231 ;
if ( F_98 ( V_231 -> V_241 ) < V_237 )
V_140 = F_108 ( & V_231 -> V_240 ) ;
else
V_140 = F_109 ( & V_231 -> V_240 ) ;
if ( ! V_140 )
return NULL ;
V_231 = F_101 ( V_140 , struct V_53 , V_240 ) ;
if ( F_258 ( V_50 , V_267 , V_231 -> V_241 ) )
return V_231 ;
return NULL ;
}
static struct V_53 * F_260 ( struct V_49 * V_50 ,
struct V_53 * V_267 )
{
struct V_53 * V_54 ;
if ( F_58 ( V_267 ) )
return NULL ;
if ( ! F_61 ( V_267 ) )
return NULL ;
if ( F_249 ( V_267 ) )
return NULL ;
if ( V_267 -> V_3 -> V_139 == 1 )
return NULL ;
V_54 = F_259 ( V_50 , V_267 ) ;
if ( ! V_54 )
return NULL ;
if ( V_267 -> V_3 != V_54 -> V_3 )
return NULL ;
if ( ! F_61 ( V_54 ) )
return NULL ;
if ( F_249 ( V_54 ) )
return NULL ;
if ( F_59 ( V_54 ) != F_59 ( V_267 ) )
return NULL ;
return V_54 ;
}
static bool F_261 ( struct V_49 * V_50 , struct V_53 * V_54 )
{
enum V_4 V_60 = F_57 ( V_54 ) ;
struct V_1 * V_92 = V_54 -> V_236 ;
F_21 ( ! V_92 ) ;
F_21 ( ! V_92 -> V_61 ) ;
if ( ! V_50 -> V_51 )
return false ;
if ( V_60 == V_7 )
return false ;
if ( F_62 ( V_54 ) &&
! ( F_262 ( V_50 -> V_67 ) && V_50 -> V_52 ) )
return true ;
if ( V_92 -> V_61 == 1 && F_61 ( V_54 ) &&
! F_263 ( V_50 , & V_92 -> V_172 , false ) )
return true ;
F_90 ( V_50 , V_54 , L_18 , V_92 -> V_61 ) ;
return false ;
}
static void F_264 ( struct V_49 * V_50 )
{
struct V_53 * V_54 = V_50 -> V_262 ;
struct V_1 * V_92 = V_54 -> V_236 ;
struct V_62 * V_68 ;
unsigned long V_268 , V_269 = 0 ;
if ( F_262 ( V_50 -> V_67 ) && V_50 -> V_52 )
return;
F_77 ( ! F_216 ( & V_54 -> V_138 ) ) ;
F_77 ( F_92 ( V_54 ) ) ;
if ( ! F_261 ( V_50 , V_54 ) ) {
if ( V_50 -> V_270 )
V_269 = V_50 -> V_270 ;
else
return;
}
if ( V_54 -> V_271 )
return;
V_68 = V_50 -> V_265 ;
if ( ! V_68 || ! F_265 ( & V_68 -> V_64 . V_66 -> V_272 ) )
return;
if ( F_266 ( V_68 -> V_172 . V_273 ) &&
( V_54 -> V_113 - V_112 < V_68 -> V_172 . V_274 ) ) {
F_90 ( V_50 , V_54 , L_19 ,
V_68 -> V_172 . V_274 ) ;
return;
}
if ( V_269 &&
( V_54 -> V_3 -> V_139 > 1 ||
F_263 ( V_50 , & V_92 -> V_172 , true ) ) )
return;
F_267 ( V_54 ) ;
if ( V_269 )
V_268 = V_50 -> V_270 ;
else
V_268 = V_50 -> V_51 ;
F_268 ( & V_50 -> V_263 , V_112 + V_268 ) ;
F_20 ( V_54 -> V_3 ) ;
F_90 ( V_50 , V_54 , L_20 , V_268 ,
V_269 ? 1 : 0 ) ;
}
static void F_269 ( struct V_252 * V_47 , struct V_115 * V_246 )
{
struct V_49 * V_50 = V_47 -> V_70 -> V_71 ;
struct V_53 * V_54 = F_214 ( V_246 ) ;
F_90 ( V_50 , V_54 , L_21 ) ;
V_54 -> V_241 = F_107 ( V_50 , V_54 , V_246 ) ;
F_227 ( V_246 ) ;
V_54 -> V_271 ++ ;
( F_220 ( V_246 ) ) -> V_271 ++ ;
F_270 ( V_47 , V_246 ) ;
V_50 -> V_275 [ F_61 ( V_54 ) ] ++ ;
V_54 -> V_168 += F_225 ( V_246 ) ;
}
static struct V_115 * F_271 ( struct V_53 * V_54 )
{
struct V_115 * V_246 = NULL ;
if ( F_272 ( V_54 ) )
return NULL ;
F_273 ( V_54 ) ;
if ( F_234 ( & V_54 -> V_276 ) )
return NULL ;
V_246 = F_274 ( V_54 -> V_276 . V_136 ) ;
if ( F_93 ( V_112 , V_246 -> V_261 ) )
V_246 = NULL ;
F_90 ( V_54 -> V_50 , V_54 , L_22 , V_246 ) ;
return V_246 ;
}
static inline int
F_275 ( struct V_49 * V_50 , struct V_53 * V_54 )
{
const int V_277 = V_50 -> V_278 ;
F_77 ( V_54 -> V_84 >= V_82 ) ;
return 2 * V_277 * ( V_82 - V_54 -> V_84 ) ;
}
static int F_276 ( struct V_53 * V_54 )
{
int V_279 , V_280 ;
V_280 = V_54 -> V_281 [ V_73 ] + V_54 -> V_281 [ V_282 ] ;
V_279 = V_54 -> V_283 - V_280 ;
F_21 ( V_279 < 0 ) ;
return V_279 ;
}
static void F_277 ( struct V_53 * V_54 , struct V_53 * V_233 )
{
int V_279 , V_284 ;
struct V_53 * V_231 ;
if ( ! F_276 ( V_233 ) )
return;
while ( ( V_231 = V_233 -> V_233 ) ) {
if ( V_231 == V_54 )
return;
V_233 = V_231 ;
}
V_279 = F_276 ( V_54 ) ;
V_284 = F_276 ( V_233 ) ;
if ( V_279 == 0 || V_284 == 0 )
return;
if ( V_284 >= V_279 ) {
V_54 -> V_233 = V_233 ;
V_233 -> V_283 += V_279 ;
} else {
V_233 -> V_233 = V_54 ;
V_54 -> V_283 += V_284 ;
}
}
static enum V_6 F_278 ( struct V_49 * V_50 ,
struct V_2 * V_3 , enum V_4 V_60 )
{
struct V_53 * V_67 ;
int V_169 ;
bool V_285 = false ;
unsigned long V_286 = 0 ;
enum V_6 V_287 = V_58 ;
for ( V_169 = 0 ; V_169 <= V_59 ; ++ V_169 ) {
V_67 = F_99 ( F_1 ( V_3 , V_60 , V_169 ) ) ;
if ( V_67 &&
( ! V_285 || F_93 ( V_67 -> V_232 , V_286 ) ) ) {
V_286 = V_67 -> V_232 ;
V_287 = V_169 ;
V_285 = true ;
}
}
return V_287 ;
}
static void
F_279 ( struct V_49 * V_50 , struct V_2 * V_3 )
{
unsigned V_103 ;
unsigned V_61 ;
struct V_1 * V_92 ;
unsigned V_108 ;
enum V_4 V_288 = V_50 -> V_167 ;
if ( F_63 ( V_55 , V_50 , V_3 ) )
V_50 -> V_167 = V_55 ;
else if ( F_63 ( V_56 , V_50 , V_3 ) )
V_50 -> V_167 = V_56 ;
else {
V_50 -> V_167 = V_7 ;
V_50 -> V_163 = V_112 + 1 ;
return;
}
if ( V_288 != V_50 -> V_167 )
goto V_289;
V_92 = F_1 ( V_3 , V_50 -> V_167 , V_50 -> V_165 ) ;
V_61 = V_92 -> V_61 ;
if ( V_61 && ! F_128 ( V_112 , V_50 -> V_163 ) )
return;
V_289:
V_50 -> V_165 = F_278 ( V_50 , V_3 ,
V_50 -> V_167 ) ;
V_92 = F_1 ( V_3 , V_50 -> V_167 , V_50 -> V_165 ) ;
V_61 = V_92 -> V_61 ;
V_108 = F_87 ( V_50 , V_3 ) ;
V_103 = V_108 * V_61 /
F_120 ( unsigned , V_3 -> V_101 [ V_50 -> V_167 ] ,
F_63 ( V_50 -> V_167 , V_50 ,
V_3 ) ) ;
if ( V_50 -> V_165 == V_57 ) {
unsigned int V_222 ;
V_222 = V_50 -> V_102 *
F_64 ( V_50 , V_3 ) ;
V_222 = V_222 / V_50 -> V_76 ;
V_103 = F_280 ( unsigned , V_103 , V_222 ) ;
V_103 = V_103 * V_50 -> V_81 [ 0 ] / V_50 -> V_81 [ 1 ] ;
} else
V_103 = F_86 ( V_103 , 2 * V_50 -> V_51 ) ;
V_103 = F_120 ( unsigned , V_103 , V_290 ) ;
F_74 ( V_50 , L_23 , V_103 ) ;
V_50 -> V_163 = V_112 + V_103 ;
}
static struct V_2 * F_255 ( struct V_49 * V_50 )
{
struct V_1 * V_92 = & V_50 -> V_154 ;
struct V_2 * V_3 ;
if ( F_216 ( & V_92 -> V_130 ) )
return NULL ;
V_3 = F_102 ( V_92 ) ;
F_82 ( V_92 ) ;
return V_3 ;
}
static void F_281 ( struct V_49 * V_50 )
{
struct V_2 * V_3 = F_255 ( V_50 ) ;
V_50 -> V_248 = V_3 ;
if ( V_3 -> V_156 ) {
V_50 -> V_163 = V_112 + V_3 -> V_156 ;
V_50 -> V_165 = V_3 -> V_164 ;
V_50 -> V_167 = V_3 -> V_166 ;
} else
V_50 -> V_163 = V_112 - 1 ;
F_279 ( V_50 , V_3 ) ;
}
static struct V_53 * F_282 ( struct V_49 * V_50 )
{
struct V_53 * V_54 , * V_233 = NULL ;
V_54 = V_50 -> V_262 ;
if ( ! V_54 )
goto V_291;
if ( ! V_50 -> V_255 )
return NULL ;
if ( F_283 ( V_54 ) && ! F_216 ( & V_54 -> V_138 ) )
goto V_292;
if ( F_91 ( V_54 ) && ! F_284 ( V_54 ) ) {
if ( V_54 -> V_3 -> V_139 == 1 && F_216 ( & V_54 -> V_138 )
&& V_54 -> V_271 && F_261 ( V_50 , V_54 ) ) {
V_54 = NULL ;
goto V_293;
} else
goto V_294;
}
if ( ! F_216 ( & V_54 -> V_138 ) )
goto V_293;
V_233 = F_260 ( V_50 , V_54 ) ;
if ( V_233 ) {
if ( ! V_54 -> V_233 )
F_277 ( V_54 , V_233 ) ;
goto V_292;
}
if ( F_285 ( & V_50 -> V_263 ) ) {
V_54 = NULL ;
goto V_293;
}
if ( F_249 ( V_54 ) && F_62 ( V_54 ) &&
( F_92 ( V_54 ) ||
( V_54 -> V_113 - V_112 > V_112 - V_54 -> V_111 ) ) ) {
F_286 ( V_54 ) ;
F_287 ( V_54 ) ;
}
if ( V_54 -> V_271 && F_261 ( V_50 , V_54 ) ) {
V_54 = NULL ;
goto V_293;
}
V_294:
if ( V_50 -> V_270 && V_54 -> V_3 -> V_139 == 1 &&
V_54 -> V_3 -> V_271 &&
! F_263 ( V_50 , & V_54 -> V_3 -> V_172 , true ) ) {
V_54 = NULL ;
goto V_293;
}
V_292:
F_252 ( V_50 , 0 ) ;
V_291:
if ( ! V_233 )
F_281 ( V_50 ) ;
V_54 = F_256 ( V_50 , V_233 ) ;
V_293:
return V_54 ;
}
static int F_288 ( struct V_53 * V_54 )
{
int V_271 = 0 ;
while ( V_54 -> V_241 ) {
F_269 ( V_54 -> V_50 -> V_67 , V_54 -> V_241 ) ;
V_271 ++ ;
}
F_21 ( ! F_234 ( & V_54 -> V_276 ) ) ;
F_245 ( V_54 -> V_50 , V_54 , 0 ) ;
return V_271 ;
}
static int F_289 ( struct V_49 * V_50 )
{
struct V_53 * V_54 ;
int V_271 = 0 ;
F_252 ( V_50 , 0 ) ;
while ( ( V_54 = F_254 ( V_50 ) ) != NULL ) {
F_239 ( V_50 , V_54 ) ;
V_271 += F_288 ( V_54 ) ;
}
F_21 ( V_50 -> V_76 ) ;
F_74 ( V_50 , L_24 , V_271 ) ;
return V_271 ;
}
static inline bool F_290 ( struct V_49 * V_50 ,
struct V_53 * V_54 )
{
if ( F_92 ( V_54 ) )
return true ;
if ( F_128 ( V_112 + V_50 -> V_51 * V_54 -> V_271 ,
V_54 -> V_113 ) )
return true ;
return false ;
}
static bool F_291 ( struct V_49 * V_50 , struct V_53 * V_54 )
{
unsigned int V_295 ;
if ( F_261 ( V_50 , V_54 ) && V_50 -> V_275 [ V_296 ] )
return false ;
if ( V_50 -> V_275 [ V_297 ] && ! F_61 ( V_54 ) )
return false ;
V_295 = F_120 (unsigned int, cfqd->cfq_quantum / 2 , 1 ) ;
if ( F_58 ( V_54 ) )
V_295 = 1 ;
if ( V_54 -> V_271 >= V_295 ) {
bool V_298 = false ;
if ( F_58 ( V_54 ) )
return false ;
if ( F_61 ( V_54 ) && V_50 -> V_245 == 1 )
V_298 = true ;
if ( V_50 -> V_76 > 1 && F_290 ( V_50 , V_54 ) &&
! V_298 )
return false ;
if ( V_50 -> V_76 == 1 || V_298 )
V_295 = - 1 ;
else
V_295 = V_50 -> V_299 ;
}
if ( ! F_61 ( V_54 ) && V_50 -> V_104 ) {
unsigned long V_300 = V_112 - V_50 -> V_301 ;
unsigned int V_302 ;
V_302 = V_300 / V_50 -> V_81 [ 1 ] ;
if ( ! V_302 && ! V_54 -> V_271 )
V_302 = 1 ;
if ( V_302 < V_295 )
V_295 = V_302 ;
}
return V_54 -> V_271 < V_295 ;
}
static bool F_292 ( struct V_49 * V_50 , struct V_53 * V_54 )
{
struct V_115 * V_246 ;
F_21 ( F_216 ( & V_54 -> V_138 ) ) ;
if ( ! F_291 ( V_50 , V_54 ) )
return false ;
V_246 = F_271 ( V_54 ) ;
if ( ! V_246 )
V_246 = V_54 -> V_241 ;
F_269 ( V_50 -> V_67 , V_246 ) ;
if ( ! V_50 -> V_265 ) {
struct V_62 * V_68 = F_293 ( V_246 ) ;
F_294 ( & V_68 -> V_64 . V_66 -> V_303 ) ;
V_50 -> V_265 = V_68 ;
}
return true ;
}
static int F_295 ( struct V_252 * V_47 , int V_304 )
{
struct V_49 * V_50 = V_47 -> V_70 -> V_71 ;
struct V_53 * V_54 ;
if ( ! V_50 -> V_76 )
return 0 ;
if ( F_55 ( V_304 ) )
return F_289 ( V_50 ) ;
V_54 = F_282 ( V_50 ) ;
if ( ! V_54 )
return 0 ;
if ( ! F_292 ( V_50 , V_54 ) )
return 0 ;
V_54 -> V_162 ++ ;
F_241 ( V_54 ) ;
if ( V_50 -> V_76 > 1 && ( ( ! F_61 ( V_54 ) &&
V_54 -> V_162 >= F_275 ( V_50 , V_54 ) ) ||
F_58 ( V_54 ) ) ) {
V_54 -> V_113 = V_112 + 1 ;
F_252 ( V_50 , 0 ) ;
}
F_90 ( V_50 , V_54 , L_25 ) ;
return 1 ;
}
static void F_151 ( struct V_53 * V_54 )
{
struct V_49 * V_50 = V_54 -> V_50 ;
struct V_2 * V_3 ;
F_21 ( V_54 -> V_283 <= 0 ) ;
V_54 -> V_283 -- ;
if ( V_54 -> V_283 )
return;
F_90 ( V_50 , V_54 , L_26 ) ;
F_21 ( F_100 ( & V_54 -> V_138 ) ) ;
F_21 ( V_54 -> V_281 [ V_73 ] + V_54 -> V_281 [ V_282 ] ) ;
V_3 = V_54 -> V_3 ;
if ( F_55 ( V_50 -> V_262 == V_54 ) ) {
F_245 ( V_50 , V_54 , 0 ) ;
F_73 ( V_50 ) ;
}
F_21 ( F_208 ( V_54 ) ) ;
F_296 ( V_305 , V_54 ) ;
F_38 ( V_3 ) ;
}
static void F_297 ( struct V_53 * V_54 )
{
struct V_53 * V_231 , * V_136 ;
V_231 = V_54 -> V_233 ;
while ( V_231 ) {
if ( V_231 == V_54 ) {
F_298 ( 1 , L_27 ) ;
break;
}
V_136 = V_231 -> V_233 ;
F_151 ( V_231 ) ;
V_231 = V_136 ;
}
}
static void F_299 ( struct V_49 * V_50 , struct V_53 * V_54 )
{
if ( F_55 ( V_54 == V_50 -> V_262 ) ) {
F_245 ( V_50 , V_54 , 0 ) ;
F_73 ( V_50 ) ;
}
F_297 ( V_54 ) ;
F_151 ( V_54 ) ;
}
static void F_300 ( struct V_63 * V_64 )
{
struct V_62 * V_68 = F_65 ( V_64 ) ;
V_68 -> V_172 . V_173 = V_112 ;
}
static void F_301 ( struct V_63 * V_64 )
{
struct V_62 * V_68 = F_65 ( V_64 ) ;
struct V_49 * V_50 = F_70 ( V_68 ) ;
if ( F_68 ( V_68 , false ) ) {
F_299 ( V_50 , F_68 ( V_68 , false ) ) ;
F_69 ( V_68 , NULL , false ) ;
}
if ( F_68 ( V_68 , true ) ) {
F_299 ( V_50 , F_68 ( V_68 , true ) ) ;
F_69 ( V_68 , NULL , true ) ;
}
}
static void F_302 ( struct V_53 * V_54 , struct V_62 * V_68 )
{
struct V_249 * V_250 = V_251 ;
int V_306 ;
if ( ! F_303 ( V_54 ) )
return;
V_306 = F_304 ( V_68 -> V_84 ) ;
switch ( V_306 ) {
default:
F_305 ( V_307 L_28 , V_306 ) ;
case V_308 :
V_54 -> V_84 = F_306 ( V_250 ) ;
V_54 -> V_306 = F_307 ( V_250 ) ;
break;
case V_309 :
V_54 -> V_84 = F_308 ( V_68 -> V_84 ) ;
V_54 -> V_306 = V_309 ;
break;
case V_310 :
V_54 -> V_84 = F_308 ( V_68 -> V_84 ) ;
V_54 -> V_306 = V_310 ;
break;
case V_311 :
V_54 -> V_306 = V_311 ;
V_54 -> V_84 = 7 ;
F_287 ( V_54 ) ;
break;
}
V_54 -> V_244 = V_54 -> V_84 ;
F_309 ( V_54 ) ;
}
static void F_310 ( struct V_62 * V_68 , struct V_72 * V_72 )
{
int V_84 = V_68 -> V_64 . V_66 -> V_84 ;
struct V_49 * V_50 = F_70 ( V_68 ) ;
struct V_53 * V_54 ;
if ( F_55 ( ! V_50 ) || F_156 ( V_68 -> V_84 == V_84 ) )
return;
V_54 = F_68 ( V_68 , false ) ;
if ( V_54 ) {
F_151 ( V_54 ) ;
V_54 = F_311 ( V_50 , V_296 , V_68 , V_72 ) ;
F_69 ( V_68 , V_54 , false ) ;
}
V_54 = F_68 ( V_68 , true ) ;
if ( V_54 )
F_312 ( V_54 ) ;
V_68 -> V_84 = V_84 ;
}
static void F_313 ( struct V_49 * V_50 , struct V_53 * V_54 ,
T_9 V_312 , bool V_69 )
{
F_105 ( & V_54 -> V_131 ) ;
F_105 ( & V_54 -> V_240 ) ;
F_314 ( & V_54 -> V_276 ) ;
V_54 -> V_283 = 0 ;
V_54 -> V_50 = V_50 ;
F_312 ( V_54 ) ;
if ( V_69 ) {
if ( ! F_58 ( V_54 ) )
F_315 ( V_54 ) ;
F_316 ( V_54 ) ;
}
V_54 -> V_312 = V_312 ;
}
static void F_317 ( struct V_62 * V_68 , struct V_72 * V_72 )
{
struct V_49 * V_50 = F_70 ( V_68 ) ;
struct V_53 * V_54 ;
T_1 V_313 ;
F_318 () ;
V_313 = F_319 ( V_72 ) -> V_36 . V_313 ;
F_320 () ;
if ( F_55 ( ! V_50 ) || F_156 ( V_68 -> V_314 == V_313 ) )
return;
V_54 = F_68 ( V_68 , false ) ;
if ( V_54 ) {
F_90 ( V_50 , V_54 , L_29 ) ;
F_69 ( V_68 , NULL , false ) ;
F_151 ( V_54 ) ;
}
V_54 = F_68 ( V_68 , true ) ;
if ( V_54 ) {
F_90 ( V_50 , V_54 , L_29 ) ;
F_69 ( V_68 , NULL , true ) ;
F_151 ( V_54 ) ;
}
V_68 -> V_314 = V_313 ;
}
static inline void F_317 ( struct V_62 * V_68 , struct V_72 * V_72 ) { }
static struct V_53 * *
F_321 ( struct V_2 * V_3 , int V_306 , int V_84 )
{
switch ( V_306 ) {
case V_309 :
return & V_3 -> V_184 [ 0 ] [ V_84 ] ;
case V_308 :
V_84 = V_315 ;
case V_310 :
return & V_3 -> V_184 [ 1 ] [ V_84 ] ;
case V_311 :
return & V_3 -> V_185 ;
default:
F_322 () ;
}
}
static struct V_53 *
F_311 ( struct V_49 * V_50 , bool V_69 , struct V_62 * V_68 ,
struct V_72 * V_72 )
{
int V_306 = F_304 ( V_68 -> V_84 ) ;
int V_84 = F_308 ( V_68 -> V_84 ) ;
struct V_53 * * V_184 = NULL ;
struct V_53 * V_54 ;
struct V_2 * V_3 ;
F_318 () ;
V_3 = F_154 ( V_50 , F_319 ( V_72 ) ) ;
if ( ! V_3 ) {
V_54 = & V_50 -> V_316 ;
goto V_213;
}
if ( ! V_69 ) {
if ( ! F_323 ( V_68 -> V_84 ) ) {
struct V_249 * V_250 = V_251 ;
V_84 = F_306 ( V_250 ) ;
V_306 = F_307 ( V_250 ) ;
}
V_184 = F_321 ( V_3 , V_306 , V_84 ) ;
V_54 = * V_184 ;
if ( V_54 )
goto V_213;
}
V_54 = F_324 ( V_305 , V_317 | V_318 ,
V_50 -> V_67 -> V_140 ) ;
if ( ! V_54 ) {
V_54 = & V_50 -> V_316 ;
goto V_213;
}
F_313 ( V_50 , V_54 , V_251 -> V_312 , V_69 ) ;
F_302 ( V_54 , V_68 ) ;
F_157 ( V_54 , V_3 ) ;
F_90 ( V_50 , V_54 , L_30 ) ;
if ( V_184 ) {
V_54 -> V_283 ++ ;
* V_184 = V_54 ;
}
V_213:
V_54 -> V_283 ++ ;
F_320 () ;
return V_54 ;
}
static void
F_325 ( struct V_319 * V_172 , unsigned long V_320 )
{
unsigned long V_321 = V_112 - V_172 -> V_173 ;
V_321 = F_85 ( V_321 , 2UL * V_320 ) ;
V_172 -> V_273 = ( 7 * V_172 -> V_273 + 256 ) / 8 ;
V_172 -> V_322 = ( 7 * V_172 -> V_322 + 256 * V_321 ) / 8 ;
V_172 -> V_274 = ( V_172 -> V_322 + 128 ) / V_172 -> V_273 ;
}
static void
F_326 ( struct V_49 * V_50 , struct V_53 * V_54 ,
struct V_62 * V_68 )
{
if ( F_61 ( V_54 ) ) {
F_325 ( & V_68 -> V_172 , V_50 -> V_51 ) ;
F_325 ( & V_54 -> V_236 -> V_172 ,
V_50 -> V_51 ) ;
}
#ifdef F_327
F_325 ( & V_54 -> V_3 -> V_172 , V_50 -> V_270 ) ;
#endif
}
static void
F_328 ( struct V_49 * V_50 , struct V_53 * V_54 ,
struct V_115 * V_246 )
{
T_4 V_323 = 0 ;
T_4 V_324 = F_225 ( V_246 ) ;
if ( V_54 -> V_325 ) {
if ( V_54 -> V_325 < F_98 ( V_246 ) )
V_323 = F_98 ( V_246 ) - V_54 -> V_325 ;
else
V_323 = V_54 -> V_325 - F_98 ( V_246 ) ;
}
V_54 -> V_326 <<= 1 ;
if ( F_262 ( V_50 -> V_67 ) )
V_54 -> V_326 |= ( V_324 < V_327 ) ;
else
V_54 -> V_326 |= ( V_323 > V_328 ) ;
}
static void
F_329 ( struct V_49 * V_50 , struct V_53 * V_54 ,
struct V_62 * V_68 )
{
int V_329 , V_330 ;
if ( ! F_61 ( V_54 ) || F_58 ( V_54 ) )
return;
V_330 = V_329 = F_62 ( V_54 ) ;
if ( V_54 -> V_19 [ 0 ] + V_54 -> V_19 [ 1 ] >= 4 )
F_330 ( V_54 ) ;
if ( V_54 -> V_241 && ( V_54 -> V_241 -> V_125 & V_331 ) )
V_330 = 0 ;
else if ( ! F_265 ( & V_68 -> V_64 . V_66 -> V_272 ) ||
! V_50 -> V_51 ||
( ! F_331 ( V_54 ) && F_249 ( V_54 ) ) )
V_330 = 0 ;
else if ( F_266 ( V_68 -> V_172 . V_273 ) ) {
if ( V_68 -> V_172 . V_274 > V_50 -> V_51 )
V_330 = 0 ;
else
V_330 = 1 ;
}
if ( V_329 != V_330 ) {
F_90 ( V_50 , V_54 , L_31 , V_330 ) ;
if ( V_330 )
F_315 ( V_54 ) ;
else
F_287 ( V_54 ) ;
}
}
static bool
F_332 ( struct V_49 * V_50 , struct V_53 * V_233 ,
struct V_115 * V_246 )
{
struct V_53 * V_54 ;
V_54 = V_50 -> V_262 ;
if ( ! V_54 )
return false ;
if ( F_58 ( V_233 ) )
return false ;
if ( F_58 ( V_54 ) )
return true ;
if ( F_59 ( V_54 ) && ! F_59 ( V_233 ) )
return false ;
if ( F_97 ( V_246 ) && ! F_61 ( V_54 ) )
return true ;
if ( ! F_34 ( V_54 -> V_3 , V_233 -> V_3 ) )
return false ;
if ( F_91 ( V_54 ) )
return true ;
if ( F_59 ( V_233 ) && ! F_59 ( V_54 ) )
return true ;
F_124 ( V_54 -> V_306 != V_233 -> V_306 ) ;
if ( V_50 -> V_165 == V_58 &&
F_60 ( V_233 ) == V_58 &&
F_216 ( & V_54 -> V_138 ) )
return true ;
if ( ( V_246 -> V_125 & V_126 ) && ! V_54 -> V_256 )
return true ;
if ( F_216 ( & V_54 -> V_138 ) && ! F_261 ( V_50 , V_54 ) )
return true ;
if ( ! V_50 -> V_265 || ! F_246 ( V_54 ) )
return false ;
if ( F_258 ( V_50 , V_54 , V_246 ) )
return true ;
return false ;
}
static void F_333 ( struct V_49 * V_50 , struct V_53 * V_54 )
{
enum V_6 V_332 = F_60 ( V_50 -> V_262 ) ;
F_90 ( V_50 , V_54 , L_32 ) ;
F_252 ( V_50 , 1 ) ;
if ( V_332 != F_60 ( V_54 ) )
V_54 -> V_3 -> V_156 = 0 ;
F_21 ( ! F_208 ( V_54 ) ) ;
F_204 ( V_50 , V_54 , 1 ) ;
V_54 -> V_113 = 0 ;
F_244 ( V_54 ) ;
}
static void
F_334 ( struct V_49 * V_50 , struct V_53 * V_54 ,
struct V_115 * V_246 )
{
struct V_62 * V_68 = F_293 ( V_246 ) ;
V_50 -> V_255 ++ ;
if ( V_246 -> V_125 & V_126 )
V_54 -> V_256 ++ ;
F_326 ( V_50 , V_54 , V_68 ) ;
F_328 ( V_50 , V_54 , V_246 ) ;
F_329 ( V_50 , V_54 , V_68 ) ;
V_54 -> V_325 = F_98 ( V_246 ) + F_225 ( V_246 ) ;
if ( V_54 == V_50 -> V_262 ) {
if ( F_246 ( V_54 ) ) {
if ( F_335 ( V_246 ) > V_333 ||
V_50 -> V_76 > 1 ) {
F_237 ( V_50 , V_54 ) ;
F_240 ( V_54 ) ;
F_336 ( V_50 -> V_67 ) ;
} else {
F_17 ( V_54 -> V_3 ) ;
F_337 ( V_54 ) ;
}
}
} else if ( F_332 ( V_50 , V_54 , V_246 ) ) {
F_333 ( V_50 , V_54 ) ;
F_336 ( V_50 -> V_67 ) ;
}
}
static void F_338 ( struct V_252 * V_47 , struct V_115 * V_246 )
{
struct V_49 * V_50 = V_47 -> V_70 -> V_71 ;
struct V_53 * V_54 = F_214 ( V_246 ) ;
F_90 ( V_50 , V_54 , L_33 ) ;
F_302 ( V_54 , F_293 ( V_246 ) ) ;
V_246 -> V_261 = V_112 + V_50 -> V_334 [ F_97 ( V_246 ) ] ;
F_339 ( & V_246 -> V_254 , & V_54 -> V_276 ) ;
F_217 ( V_246 ) ;
F_40 ( F_220 ( V_246 ) , V_50 -> V_248 ,
V_246 -> V_125 ) ;
F_334 ( V_50 , V_54 , V_246 ) ;
}
static void F_340 ( struct V_49 * V_50 )
{
struct V_53 * V_54 = V_50 -> V_262 ;
if ( V_50 -> V_253 > V_50 -> V_335 )
V_50 -> V_335 = V_50 -> V_253 ;
if ( V_50 -> V_52 == 1 )
return;
if ( V_50 -> V_255 <= V_336 &&
V_50 -> V_253 <= V_336 )
return;
if ( V_54 && F_62 ( V_54 ) &&
V_54 -> V_271 + V_54 -> V_19 [ 0 ] + V_54 -> V_19 [ 1 ] <
V_336 && V_50 -> V_253 < V_336 )
return;
if ( V_50 -> V_337 ++ < 50 )
return;
if ( V_50 -> V_335 >= V_336 )
V_50 -> V_52 = 1 ;
else
V_50 -> V_52 = 0 ;
}
static bool F_341 ( struct V_49 * V_50 , struct V_53 * V_54 )
{
struct V_62 * V_68 = V_50 -> V_265 ;
if ( ! F_216 ( & V_54 -> V_138 ) )
return false ;
if ( V_54 -> V_3 -> V_139 > 1 )
return false ;
if ( F_263 ( V_50 , & V_54 -> V_3 -> V_172 , true ) )
return false ;
if ( F_91 ( V_54 ) )
return true ;
if ( V_68 && F_266 ( V_68 -> V_172 . V_273 )
&& ( V_54 -> V_113 - V_112 < V_68 -> V_172 . V_274 ) )
return true ;
if ( V_54 -> V_113 - V_112 == 1 )
return true ;
return false ;
}
static void F_342 ( struct V_252 * V_47 , struct V_115 * V_246 )
{
struct V_53 * V_54 = F_214 ( V_246 ) ;
struct V_49 * V_50 = V_54 -> V_50 ;
const int V_78 = F_97 ( V_246 ) ;
unsigned long V_12 ;
V_12 = V_112 ;
F_90 ( V_50 , V_54 , L_34 ,
! ! ( V_246 -> V_125 & V_331 ) ) ;
F_340 ( V_50 ) ;
F_77 ( ! V_50 -> V_253 ) ;
F_77 ( ! V_54 -> V_271 ) ;
V_50 -> V_253 -- ;
V_54 -> V_271 -- ;
( F_220 ( V_246 ) ) -> V_271 -- ;
F_46 ( V_54 -> V_3 , F_343 ( V_246 ) ,
F_344 ( V_246 ) , V_246 -> V_125 ) ;
V_50 -> V_275 [ F_61 ( V_54 ) ] -- ;
if ( V_78 ) {
struct V_1 * V_92 ;
F_293 ( V_246 ) -> V_172 . V_173 = V_12 ;
if ( F_208 ( V_54 ) )
V_92 = V_54 -> V_236 ;
else
V_92 = F_1 ( V_54 -> V_3 , F_57 ( V_54 ) ,
F_60 ( V_54 ) ) ;
V_92 -> V_172 . V_173 = V_12 ;
if ( ! F_128 ( V_246 -> V_41 + V_50 -> V_334 [ 1 ] , V_12 ) )
V_50 -> V_301 = V_12 ;
}
#ifdef F_327
V_54 -> V_3 -> V_172 . V_173 = V_12 ;
#endif
if ( V_50 -> V_262 == V_54 ) {
const bool V_338 = F_216 ( & V_54 -> V_138 ) ;
if ( F_92 ( V_54 ) ) {
F_89 ( V_50 , V_54 ) ;
F_345 ( V_54 ) ;
}
if ( F_341 ( V_50 , V_54 ) ) {
unsigned long V_339 = V_50 -> V_51 ;
if ( ! V_50 -> V_51 )
V_339 = V_50 -> V_270 ;
V_54 -> V_113 = V_112 + V_339 ;
F_346 ( V_54 ) ;
F_90 ( V_50 , V_54 , L_35 ) ;
}
if ( F_91 ( V_54 ) || F_58 ( V_54 ) )
F_252 ( V_50 , 1 ) ;
else if ( V_78 && V_338 &&
! F_260 ( V_50 , V_54 ) ) {
F_264 ( V_50 ) ;
}
}
if ( ! V_50 -> V_253 )
F_73 ( V_50 ) ;
}
static inline int F_347 ( struct V_53 * V_54 )
{
if ( F_246 ( V_54 ) && ! F_348 ( V_54 ) ) {
F_349 ( V_54 ) ;
return V_340 ;
}
return V_341 ;
}
static int F_350 ( struct V_252 * V_47 , int V_38 )
{
struct V_49 * V_50 = V_47 -> V_70 -> V_71 ;
struct V_249 * V_250 = V_251 ;
struct V_62 * V_68 ;
struct V_53 * V_54 ;
V_68 = F_66 ( V_50 , V_250 -> V_65 ) ;
if ( ! V_68 )
return V_341 ;
V_54 = F_68 ( V_68 , F_351 ( V_38 ) ) ;
if ( V_54 ) {
F_302 ( V_54 , V_68 ) ;
return F_347 ( V_54 ) ;
}
return V_341 ;
}
static void F_352 ( struct V_115 * V_246 )
{
struct V_53 * V_54 = F_214 ( V_246 ) ;
if ( V_54 ) {
const int V_38 = F_353 ( V_246 ) ;
F_21 ( ! V_54 -> V_281 [ V_38 ] ) ;
V_54 -> V_281 [ V_38 ] -- ;
F_38 ( F_220 ( V_246 ) ) ;
V_246 -> V_342 . V_343 [ 0 ] = NULL ;
V_246 -> V_342 . V_343 [ 1 ] = NULL ;
F_151 ( V_54 ) ;
}
}
static struct V_53 *
F_354 ( struct V_49 * V_50 , struct V_62 * V_68 ,
struct V_53 * V_54 )
{
F_90 ( V_50 , V_54 , L_36 , V_54 -> V_233 ) ;
F_69 ( V_68 , V_54 -> V_233 , 1 ) ;
F_355 ( V_54 -> V_233 ) ;
F_151 ( V_54 ) ;
return F_68 ( V_68 , 1 ) ;
}
static struct V_53 *
F_356 ( struct V_62 * V_68 , struct V_53 * V_54 )
{
if ( F_276 ( V_54 ) == 1 ) {
V_54 -> V_312 = V_251 -> V_312 ;
F_357 ( V_54 ) ;
F_358 ( V_54 ) ;
return V_54 ;
}
F_69 ( V_68 , NULL , 1 ) ;
F_297 ( V_54 ) ;
F_151 ( V_54 ) ;
return NULL ;
}
static int
F_359 ( struct V_252 * V_47 , struct V_115 * V_246 , struct V_72 * V_72 ,
T_5 V_344 )
{
struct V_49 * V_50 = V_47 -> V_70 -> V_71 ;
struct V_62 * V_68 = F_65 ( V_246 -> V_342 . V_64 ) ;
const int V_38 = F_353 ( V_246 ) ;
const bool V_69 = F_97 ( V_246 ) ;
struct V_53 * V_54 ;
F_176 ( V_47 -> V_48 ) ;
F_310 ( V_68 , V_72 ) ;
F_317 ( V_68 , V_72 ) ;
V_291:
V_54 = F_68 ( V_68 , V_69 ) ;
if ( ! V_54 || V_54 == & V_50 -> V_316 ) {
if ( V_54 )
F_151 ( V_54 ) ;
V_54 = F_311 ( V_50 , V_69 , V_68 , V_72 ) ;
F_69 ( V_68 , V_54 , V_69 ) ;
} else {
if ( F_248 ( V_54 ) && F_360 ( V_54 ) ) {
F_90 ( V_50 , V_54 , L_37 ) ;
V_54 = F_356 ( V_68 , V_54 ) ;
if ( ! V_54 )
goto V_291;
}
if ( V_54 -> V_233 )
V_54 = F_354 ( V_50 , V_68 , V_54 ) ;
}
V_54 -> V_281 [ V_38 ] ++ ;
V_54 -> V_283 ++ ;
F_36 ( V_54 -> V_3 ) ;
V_246 -> V_342 . V_343 [ 0 ] = V_54 ;
V_246 -> V_342 . V_343 [ 1 ] = V_54 -> V_3 ;
F_178 ( V_47 -> V_48 ) ;
return 0 ;
}
static void F_361 ( struct V_345 * V_346 )
{
struct V_49 * V_50 =
F_25 ( V_346 , struct V_49 , V_77 ) ;
struct V_252 * V_47 = V_50 -> V_67 ;
F_176 ( V_47 -> V_48 ) ;
F_336 ( V_50 -> V_67 ) ;
F_178 ( V_47 -> V_48 ) ;
}
static void F_362 ( unsigned long V_347 )
{
struct V_49 * V_50 = (struct V_49 * ) V_347 ;
struct V_53 * V_54 ;
unsigned long V_348 ;
int V_264 = 1 ;
F_74 ( V_50 , L_38 ) ;
F_363 ( V_50 -> V_67 -> V_48 , V_348 ) ;
V_54 = V_50 -> V_262 ;
if ( V_54 ) {
V_264 = 0 ;
if ( F_284 ( V_54 ) )
goto V_349;
if ( F_91 ( V_54 ) )
goto V_292;
if ( ! V_50 -> V_76 )
goto V_350;
if ( ! F_216 ( & V_54 -> V_138 ) )
goto V_349;
F_286 ( V_54 ) ;
}
V_292:
F_252 ( V_50 , V_264 ) ;
V_349:
F_73 ( V_50 ) ;
V_350:
F_364 ( V_50 -> V_67 -> V_48 , V_348 ) ;
}
static void F_365 ( struct V_49 * V_50 )
{
F_366 ( & V_50 -> V_263 ) ;
F_367 ( & V_50 -> V_77 ) ;
}
static void F_368 ( struct V_351 * V_352 )
{
struct V_49 * V_50 = V_352 -> V_71 ;
struct V_252 * V_47 = V_50 -> V_67 ;
F_365 ( V_50 ) ;
F_176 ( V_47 -> V_48 ) ;
if ( V_50 -> V_262 )
F_245 ( V_50 , V_50 -> V_262 , 0 ) ;
F_178 ( V_47 -> V_48 ) ;
F_365 ( V_50 ) ;
#ifdef F_327
F_369 ( V_47 , & V_31 ) ;
#else
F_144 ( V_50 -> V_228 ) ;
#endif
F_144 ( V_50 ) ;
}
static int F_370 ( struct V_252 * V_47 , struct V_353 * V_352 )
{
struct V_49 * V_50 ;
struct V_29 * V_30 V_354 ;
int V_169 , V_205 ;
struct V_351 * V_355 ;
V_355 = F_371 ( V_47 , V_352 ) ;
if ( ! V_355 )
return - V_176 ;
V_50 = F_148 ( sizeof( * V_50 ) , V_178 , V_47 -> V_140 ) ;
if ( ! V_50 ) {
F_372 ( & V_355 -> V_356 ) ;
return - V_176 ;
}
V_355 -> V_71 = V_50 ;
V_50 -> V_67 = V_47 ;
F_176 ( V_47 -> V_48 ) ;
V_47 -> V_70 = V_355 ;
F_178 ( V_47 -> V_48 ) ;
V_50 -> V_154 = V_171 ;
#ifdef F_327
V_205 = F_373 ( V_47 , & V_31 ) ;
if ( V_205 )
goto V_357;
V_50 -> V_228 = F_29 ( V_47 -> V_358 ) ;
#else
V_205 = - V_176 ;
V_50 -> V_228 = F_148 ( sizeof( * V_50 -> V_228 ) ,
V_178 , V_50 -> V_67 -> V_140 ) ;
if ( ! V_50 -> V_228 )
goto V_357;
F_130 ( V_50 -> V_228 ) ;
V_50 -> V_228 -> V_146 = 2 * V_181 ;
V_50 -> V_228 -> V_148 = 2 * V_181 ;
#endif
for ( V_169 = 0 ; V_169 < V_359 ; V_169 ++ )
V_50 -> V_243 [ V_169 ] = V_360 ;
F_313 ( V_50 , & V_50 -> V_316 , 1 , 0 ) ;
V_50 -> V_316 . V_283 ++ ;
F_176 ( V_47 -> V_48 ) ;
F_157 ( & V_50 -> V_316 , V_50 -> V_228 ) ;
F_38 ( V_50 -> V_228 ) ;
F_178 ( V_47 -> V_48 ) ;
F_374 ( & V_50 -> V_263 ) ;
V_50 -> V_263 . V_361 = F_362 ;
V_50 -> V_263 . V_347 = ( unsigned long ) V_50 ;
F_375 ( & V_50 -> V_77 , F_361 ) ;
V_50 -> V_299 = V_299 ;
V_50 -> V_334 [ 0 ] = V_334 [ 0 ] ;
V_50 -> V_334 [ 1 ] = V_334 [ 1 ] ;
V_50 -> V_127 = V_127 ;
V_50 -> V_128 = V_128 ;
V_50 -> V_81 [ 0 ] = V_362 ;
V_50 -> V_81 [ 1 ] = V_363 ;
V_50 -> V_102 = V_102 ;
V_50 -> V_278 = V_278 ;
V_50 -> V_51 = V_51 ;
V_50 -> V_270 = V_270 ;
V_50 -> V_104 = 1 ;
V_50 -> V_52 = - 1 ;
V_50 -> V_301 = V_112 - V_235 ;
return 0 ;
V_357:
F_144 ( V_50 ) ;
F_372 ( & V_355 -> V_356 ) ;
return V_205 ;
}
static void F_376 ( struct V_252 * V_47 )
{
struct V_351 * V_352 = V_47 -> V_70 ;
struct V_49 * V_50 = V_352 -> V_71 ;
if ( F_262 ( V_47 ) )
V_50 -> V_51 = 0 ;
}
static T_6
F_377 ( unsigned int V_364 , char * V_365 )
{
return sprintf ( V_365 , L_6 , V_364 ) ;
}
static T_6
F_378 ( unsigned int * V_364 , const char * V_365 , T_7 V_61 )
{
char * V_230 = ( char * ) V_365 ;
* V_364 = F_379 ( V_230 , & V_230 , 10 ) ;
return V_61 ;
}
static int T_10 F_380 ( void )
{
int V_205 ;
if ( ! V_362 )
V_362 = 1 ;
if ( ! V_51 )
V_51 = 1 ;
#ifdef F_327
if ( ! V_270 )
V_270 = 1 ;
V_205 = F_381 ( & V_31 ) ;
if ( V_205 )
return V_205 ;
#else
V_270 = 0 ;
#endif
V_205 = - V_176 ;
V_305 = F_382 ( V_53 , 0 ) ;
if ( ! V_305 )
goto V_366;
V_205 = F_383 ( & V_367 ) ;
if ( V_205 )
goto V_368;
return 0 ;
V_368:
F_384 ( V_305 ) ;
V_366:
#ifdef F_327
F_385 ( & V_31 ) ;
#endif
return V_205 ;
}
static void T_11 F_386 ( void )
{
#ifdef F_327
F_385 ( & V_31 ) ;
#endif
F_387 ( & V_367 ) ;
F_384 ( V_305 ) ;
}
