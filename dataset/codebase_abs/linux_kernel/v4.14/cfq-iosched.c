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
struct V_2 * V_15 ,
unsigned int V_38 )
{
F_41 ( & V_3 -> V_11 . V_19 , V_38 , 1 ) ;
F_10 ( & V_3 -> V_11 ) ;
F_8 ( V_3 , V_15 ) ;
}
static inline void F_42 ( struct V_2 * V_3 ,
T_1 time , unsigned long V_39 )
{
F_6 ( & V_3 -> V_11 . time , time ) ;
#ifdef F_43
F_6 ( & V_3 -> V_11 . V_39 , V_39 ) ;
#endif
}
static inline void F_44 ( struct V_2 * V_3 ,
unsigned int V_38 )
{
F_41 ( & V_3 -> V_11 . V_19 , V_38 , - 1 ) ;
}
static inline void F_45 ( struct V_2 * V_3 ,
unsigned int V_38 )
{
F_41 ( & V_3 -> V_11 . V_40 , V_38 , 1 ) ;
}
static inline void F_46 ( struct V_2 * V_3 ,
T_1 V_41 , T_1 V_42 ,
unsigned int V_38 )
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
struct V_2 * V_15 , unsigned int V_38 ) { }
static inline void F_42 ( struct V_2 * V_3 ,
T_1 time , unsigned long V_39 ) { }
static inline void F_44 ( struct V_2 * V_3 ,
unsigned int V_38 ) { }
static inline void F_45 ( struct V_2 * V_3 ,
unsigned int V_38 ) { }
static inline void F_46 ( struct V_2 * V_3 ,
T_1 V_41 , T_1 V_42 ,
unsigned int V_38 ) { }
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
static inline void F_71 ( struct V_49 * V_50 )
{
if ( V_50 -> V_72 ) {
F_72 ( V_50 , L_1 ) ;
F_73 ( & V_50 -> V_73 ) ;
}
}
static inline T_2 F_74 ( struct V_49 * V_50 , bool V_74 ,
unsigned short V_75 )
{
T_2 V_76 = V_50 -> V_77 [ V_74 ] ;
T_2 V_78 = F_75 ( V_76 , V_79 ) ;
F_76 ( V_75 >= V_80 ) ;
return V_76 + ( V_78 * ( 4 - V_75 ) ) ;
}
static inline T_2
F_77 ( struct V_49 * V_50 , struct V_53 * V_54 )
{
return F_74 ( V_50 , F_61 ( V_54 ) , V_54 -> V_81 ) ;
}
static inline T_2 F_78 ( T_2 V_82 ,
unsigned int V_83 )
{
T_2 V_84 = V_82 << V_85 ;
V_84 <<= V_85 ;
return F_75 ( V_84 , V_83 ) ;
}
static inline T_2 F_79 ( T_2 V_86 , T_2 V_87 )
{
T_3 V_88 = ( T_3 ) ( V_87 - V_86 ) ;
if ( V_88 > 0 )
V_86 = V_87 ;
return V_86 ;
}
static void F_80 ( struct V_1 * V_89 )
{
if ( ! F_81 ( & V_89 -> V_90 . V_91 ) ) {
struct V_2 * V_3 = F_82 ( V_89 -> V_90 . V_92 ) ;
V_89 -> V_86 = F_79 ( V_89 -> V_86 ,
V_3 -> V_87 ) ;
}
}
static inline unsigned F_83 ( struct V_49 * V_50 ,
struct V_2 * V_3 , bool V_93 )
{
unsigned V_94 , V_95 ;
unsigned V_96 = V_97 - 1 ;
unsigned V_98 = V_97 / 2 ;
unsigned V_99 = F_63 ( V_93 , V_50 , V_3 ) ;
V_94 = F_84 ( V_3 -> V_100 [ V_93 ] , V_99 ) ;
V_95 = F_85 ( V_3 -> V_100 [ V_93 ] , V_99 ) ;
V_3 -> V_100 [ V_93 ] = ( V_96 * V_95 + V_94 + V_98 ) /
V_97 ;
return V_3 -> V_100 [ V_93 ] ;
}
static inline T_2
F_86 ( struct V_49 * V_50 , struct V_2 * V_3 )
{
return V_50 -> V_101 * V_3 -> V_83 >> V_85 ;
}
static inline T_2
F_87 ( struct V_49 * V_50 , struct V_53 * V_54 )
{
T_2 V_78 = F_77 ( V_50 , V_54 ) ;
if ( V_50 -> V_102 ) {
unsigned V_103 = F_83 ( V_50 , V_54 -> V_3 ,
F_59 ( V_54 ) ) ;
T_2 V_104 = V_50 -> V_77 [ 1 ] ;
T_2 V_105 = V_104 * V_103 ;
T_2 V_106 = F_86 ( V_50 , V_54 -> V_3 ) ;
if ( V_105 > V_106 ) {
T_2 V_107 = 2 * V_50 -> V_51 ;
T_2 V_108 ;
V_108 = F_88 ( V_107 * V_78 , V_104 ) ;
V_108 = F_84 ( V_78 , V_108 ) ;
V_78 = F_88 ( V_78 * V_106 , V_105 ) ;
V_78 = F_85 ( V_78 , V_108 ) ;
}
}
return V_78 ;
}
static inline void
F_89 ( struct V_49 * V_50 , struct V_53 * V_54 )
{
T_2 V_78 = F_87 ( V_50 , V_54 ) ;
T_2 V_12 = F_90 () ;
V_54 -> V_109 = V_12 ;
V_54 -> V_110 = V_12 + V_78 ;
V_54 -> V_111 = V_78 ;
F_91 ( V_50 , V_54 , L_2 , V_54 -> V_110 - V_12 ) ;
}
static inline bool F_92 ( struct V_53 * V_54 )
{
if ( F_93 ( V_54 ) )
return false ;
if ( F_90 () < V_54 -> V_110 )
return false ;
return true ;
}
static struct V_112 *
F_94 ( struct V_49 * V_50 , struct V_112 * V_113 , struct V_112 * V_114 , T_4 V_115 )
{
T_4 V_116 , V_117 , V_118 = 0 , V_119 = 0 ;
unsigned long V_120 ;
#define F_95 0x01
#define F_96 0x02
unsigned V_121 = 0 ;
if ( V_113 == NULL || V_113 == V_114 )
return V_114 ;
if ( V_114 == NULL )
return V_113 ;
if ( F_97 ( V_113 ) != F_97 ( V_114 ) )
return F_97 ( V_113 ) ? V_113 : V_114 ;
if ( ( V_113 -> V_122 ^ V_114 -> V_122 ) & V_123 )
return V_113 -> V_122 & V_123 ? V_113 : V_114 ;
V_116 = F_98 ( V_113 ) ;
V_117 = F_98 ( V_114 ) ;
V_120 = V_50 -> V_124 * 2 ;
if ( V_116 >= V_115 )
V_118 = V_116 - V_115 ;
else if ( V_116 + V_120 >= V_115 )
V_118 = ( V_115 - V_116 ) * V_50 -> V_125 ;
else
V_121 |= F_95 ;
if ( V_117 >= V_115 )
V_119 = V_117 - V_115 ;
else if ( V_117 + V_120 >= V_115 )
V_119 = ( V_115 - V_117 ) * V_50 -> V_125 ;
else
V_121 |= F_96 ;
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
case F_96 :
return V_113 ;
case F_95 :
return V_114 ;
case ( F_95 | F_96 ) :
default:
if ( V_116 <= V_117 )
return V_113 ;
else
return V_114 ;
}
}
static struct V_53 * F_99 ( struct V_1 * V_126 )
{
if ( ! V_126 -> V_61 )
return NULL ;
return F_100 ( F_101 ( & V_126 -> V_90 ) , struct V_53 , V_127 ) ;
}
static struct V_2 * F_102 ( struct V_1 * V_126 )
{
return F_82 ( F_101 ( & V_126 -> V_90 ) ) ;
}
static void F_103 ( struct V_127 * V_128 , struct V_1 * V_126 )
{
if ( V_126 -> V_129 == V_128 )
V_126 -> V_129 = F_104 ( V_128 ) ;
F_105 ( V_128 , & V_126 -> V_90 ) ;
F_106 ( V_128 ) ;
-- V_126 -> V_61 ;
}
static struct V_112 *
F_107 ( struct V_49 * V_50 , struct V_53 * V_54 ,
struct V_112 * V_115 )
{
struct V_127 * V_130 = F_108 ( & V_115 -> V_127 ) ;
struct V_127 * V_131 = F_104 ( & V_115 -> V_127 ) ;
struct V_112 * V_132 = NULL , * V_133 = NULL ;
F_21 ( F_109 ( & V_115 -> V_127 ) ) ;
if ( V_131 )
V_133 = F_110 ( V_131 ) ;
if ( V_130 )
V_132 = F_110 ( V_130 ) ;
else {
V_130 = F_111 ( & V_54 -> V_134 ) ;
if ( V_130 && V_130 != & V_115 -> V_127 )
V_132 = F_110 ( V_130 ) ;
}
return F_94 ( V_50 , V_132 , V_133 , F_98 ( V_115 ) ) ;
}
static T_2 F_112 ( struct V_49 * V_50 ,
struct V_53 * V_54 )
{
return ( V_54 -> V_3 -> V_135 - 1 ) * ( F_74 ( V_50 , 1 , 0 ) -
F_74 ( V_50 , F_61 ( V_54 ) , V_54 -> V_81 ) ) ;
}
static inline T_3
F_113 ( struct V_1 * V_89 , struct V_2 * V_3 )
{
return V_3 -> V_87 - V_89 -> V_86 ;
}
static void
F_114 ( struct V_1 * V_89 , struct V_2 * V_3 )
{
struct V_127 * * V_136 = & V_89 -> V_90 . V_91 . V_127 ;
struct V_127 * V_34 = NULL ;
struct V_2 * V_137 ;
T_3 V_138 = F_113 ( V_89 , V_3 ) ;
bool V_139 = true , V_140 = true ;
while ( * V_136 != NULL ) {
V_34 = * V_136 ;
V_137 = F_82 ( V_34 ) ;
if ( V_138 < F_113 ( V_89 , V_137 ) ) {
V_136 = & V_34 -> V_141 ;
V_140 = false ;
} else {
V_136 = & V_34 -> V_142 ;
V_139 = false ;
}
}
if ( V_140 )
V_89 -> V_129 = & V_3 -> V_127 ;
F_115 ( & V_3 -> V_127 , V_34 , V_136 ) ;
F_116 ( & V_3 -> V_127 , & V_89 -> V_90 , V_139 ) ;
}
static void
F_117 ( struct V_2 * V_3 )
{
if ( V_3 -> V_143 ) {
V_3 -> V_144 = V_3 -> V_143 ;
V_3 -> V_143 = 0 ;
}
}
static void
F_118 ( struct V_2 * V_3 )
{
F_21 ( ! F_109 ( & V_3 -> V_127 ) ) ;
if ( V_3 -> V_145 ) {
V_3 -> V_146 = V_3 -> V_145 ;
V_3 -> V_145 = 0 ;
}
}
static void
F_119 ( struct V_1 * V_89 , struct V_2 * V_3 )
{
unsigned int V_147 = 1 << V_85 ;
struct V_2 * V_148 = V_3 ;
struct V_2 * V_34 ;
bool V_149 ;
F_21 ( ! F_109 ( & V_3 -> V_127 ) ) ;
F_118 ( V_3 ) ;
F_114 ( V_89 , V_3 ) ;
V_149 = ! V_148 -> V_150 ++ ;
V_148 -> V_151 += V_148 -> V_146 ;
V_147 = V_147 * V_148 -> V_146 / V_148 -> V_151 ;
while ( ( V_34 = F_33 ( V_148 ) ) ) {
if ( V_149 ) {
F_117 ( V_148 ) ;
V_149 = ! V_34 -> V_150 ++ ;
V_34 -> V_151 += V_148 -> V_144 ;
}
V_147 = V_147 * V_148 -> V_144 / V_34 -> V_151 ;
V_148 = V_34 ;
}
V_3 -> V_83 = F_120 ( unsigned , V_147 , 1 ) ;
}
static inline T_2 F_121 ( struct V_49 * V_50 )
{
if ( ! F_56 ( V_50 ) )
return V_152 ;
else
return V_153 ;
}
static void
F_122 ( struct V_49 * V_50 , struct V_2 * V_3 )
{
struct V_1 * V_89 = & V_50 -> V_154 ;
struct V_2 * V_137 ;
struct V_127 * V_128 ;
V_3 -> V_135 ++ ;
if ( ! F_109 ( & V_3 -> V_127 ) )
return;
V_128 = V_89 -> V_129 ;
if ( V_128 ) {
V_137 = F_82 ( V_128 ) ;
V_3 -> V_87 = V_137 -> V_87 +
F_121 ( V_50 ) ;
} else
V_3 -> V_87 = V_89 -> V_86 ;
F_119 ( V_89 , V_3 ) ;
}
static void
F_123 ( struct V_1 * V_89 , struct V_2 * V_3 )
{
struct V_2 * V_148 = V_3 ;
bool V_149 ;
V_149 = ! -- V_148 -> V_150 ;
V_148 -> V_151 -= V_148 -> V_146 ;
while ( V_149 ) {
struct V_2 * V_34 = F_33 ( V_148 ) ;
F_124 ( V_148 -> V_151 ) ;
V_148 -> V_83 = 0 ;
if ( ! V_34 )
break;
V_149 = ! -- V_34 -> V_150 ;
V_34 -> V_151 -= V_148 -> V_144 ;
V_148 = V_34 ;
}
if ( ! F_109 ( & V_3 -> V_127 ) )
F_103 ( & V_3 -> V_127 , V_89 ) ;
}
static void
F_125 ( struct V_49 * V_50 , struct V_2 * V_3 )
{
struct V_1 * V_89 = & V_50 -> V_154 ;
F_21 ( V_3 -> V_135 < 1 ) ;
V_3 -> V_135 -- ;
if ( V_3 -> V_135 )
return;
F_126 ( V_50 , V_3 , L_3 ) ;
F_123 ( V_89 , V_3 ) ;
V_3 -> V_155 = 0 ;
F_13 ( V_3 ) ;
}
static inline T_2 F_127 ( struct V_53 * V_54 ,
T_2 * V_39 )
{
T_2 V_156 ;
T_2 V_12 = F_90 () ;
if ( ! V_54 -> V_109 || V_54 -> V_109 == V_12 ) {
V_156 = F_120 ( T_2 , ( V_12 - V_54 -> V_157 ) ,
F_128 ( 1 ) ) ;
} else {
V_156 = V_12 - V_54 -> V_109 ;
if ( V_156 > V_54 -> V_111 ) {
* V_39 = V_156 - V_54 -> V_111 ;
V_156 = V_54 -> V_111 ;
}
if ( V_54 -> V_109 > V_54 -> V_157 )
* V_39 += V_54 -> V_109 -
V_54 -> V_157 ;
}
return V_156 ;
}
static void F_129 ( struct V_49 * V_50 , struct V_2 * V_3 ,
struct V_53 * V_54 )
{
struct V_1 * V_89 = & V_50 -> V_154 ;
T_2 V_158 , V_82 , V_159 = 0 ;
int V_160 = V_3 -> V_135 - F_64 ( V_50 , V_3 )
- V_3 -> V_8 . V_61 ;
unsigned int V_147 ;
T_2 V_12 = F_90 () ;
F_21 ( V_160 < 0 ) ;
V_158 = V_82 = F_127 ( V_54 , & V_159 ) ;
if ( F_56 ( V_50 ) )
V_82 = V_54 -> V_161 ;
else if ( ! F_61 ( V_54 ) && ! V_160 )
V_82 = V_54 -> V_111 ;
V_147 = V_3 -> V_83 ;
F_123 ( V_89 , V_3 ) ;
V_3 -> V_87 += F_78 ( V_82 , V_147 ) ;
F_119 ( V_89 , V_3 ) ;
if ( V_50 -> V_162 > V_12 ) {
V_3 -> V_155 = V_50 -> V_162 - V_12 ;
V_3 -> V_163 = V_50 -> V_164 ;
V_3 -> V_165 = V_50 -> V_166 ;
} else
V_3 -> V_155 = 0 ;
F_126 ( V_50 , V_3 , L_4 , V_3 -> V_87 ,
V_89 -> V_86 ) ;
F_91 ( V_54 -> V_50 , V_54 ,
L_5 ,
V_158 , V_54 -> V_161 , V_82 ,
F_56 ( V_50 ) , V_54 -> V_167 ) ;
F_42 ( V_3 , V_158 , V_159 ) ;
F_14 ( V_3 ) ;
}
static void F_130 ( struct V_2 * V_3 )
{
struct V_1 * V_89 ;
int V_168 , V_169 ;
F_131 ( V_3 , V_168 , V_169 , V_89 )
* V_89 = V_170 ;
F_106 ( & V_3 -> V_127 ) ;
V_3 -> V_171 . V_172 = F_90 () ;
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
static int F_135 ( struct V_10 * V_11 , T_5 V_173 )
{
if ( F_136 ( & V_11 -> V_40 , V_173 ) ||
F_136 ( & V_11 -> V_43 , V_173 ) ||
F_136 ( & V_11 -> V_44 , V_173 ) ||
F_136 ( & V_11 -> V_19 , V_173 ) ||
F_137 ( & V_11 -> time , V_173 ) )
goto V_174;
#ifdef F_43
if ( F_137 ( & V_11 -> V_39 , V_173 ) ||
F_137 ( & V_11 -> V_22 , V_173 ) ||
F_137 ( & V_11 -> V_23 , V_173 ) ||
F_137 ( & V_11 -> V_18 , V_173 ) ||
F_137 ( & V_11 -> V_14 , V_173 ) ||
F_137 ( & V_11 -> V_21 , V_173 ) ||
F_137 ( & V_11 -> V_17 , V_173 ) )
goto V_174;
#endif
return 0 ;
V_174:
F_132 ( V_11 ) ;
return - V_175 ;
}
static struct V_27 * F_138 ( T_5 V_173 )
{
struct V_26 * V_176 ;
V_176 = F_139 ( sizeof( * V_176 ) , V_173 ) ;
if ( ! V_176 )
return NULL ;
return & V_176 -> V_28 ;
}
static void F_140 ( struct V_27 * V_28 )
{
struct V_26 * V_176 = F_26 ( V_28 ) ;
unsigned int V_144 = F_141 ( V_177 ) ?
V_178 : V_179 ;
if ( F_142 ( V_28 ) == & V_180 )
V_144 *= 2 ;
V_176 -> V_144 = V_144 ;
V_176 -> V_146 = V_144 ;
}
static void F_143 ( struct V_27 * V_28 )
{
F_144 ( F_26 ( V_28 ) ) ;
}
static void F_145 ( struct V_27 * V_28 )
{
struct V_32 * V_32 = F_142 ( V_28 ) ;
bool V_181 = F_141 ( V_177 ) ;
unsigned int V_144 = V_181 ? V_178 : V_179 ;
if ( V_32 == & V_180 )
V_144 *= 2 ;
F_124 ( F_146 ( & V_32 -> V_36 , V_144 , V_181 , true , false ) ) ;
F_124 ( F_146 ( & V_32 -> V_36 , V_144 , V_181 , true , true ) ) ;
}
static struct V_24 * F_147 ( T_5 V_173 , int V_136 )
{
struct V_2 * V_3 ;
V_3 = F_148 ( sizeof( * V_3 ) , V_173 , V_136 ) ;
if ( ! V_3 )
return NULL ;
F_130 ( V_3 ) ;
if ( F_135 ( & V_3 -> V_11 , V_173 ) ) {
F_144 ( V_3 ) ;
return NULL ;
}
return & V_3 -> V_25 ;
}
static void F_149 ( struct V_24 * V_25 )
{
struct V_2 * V_3 = F_24 ( V_25 ) ;
struct V_26 * V_176 = F_31 ( V_25 -> V_30 -> V_32 ) ;
V_3 -> V_144 = V_176 -> V_144 ;
V_3 -> V_146 = V_176 -> V_146 ;
}
static void F_150 ( struct V_24 * V_25 )
{
struct V_2 * V_3 = F_24 ( V_25 ) ;
int V_168 ;
for ( V_168 = 0 ; V_168 < V_80 ; V_168 ++ ) {
if ( V_3 -> V_182 [ 0 ] [ V_168 ] )
F_151 ( V_3 -> V_182 [ 0 ] [ V_168 ] ) ;
if ( V_3 -> V_182 [ 1 ] [ V_168 ] )
F_151 ( V_3 -> V_182 [ 1 ] [ V_168 ] ) ;
}
if ( V_3 -> V_183 )
F_151 ( V_3 -> V_183 ) ;
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
static T_2 F_158 ( struct V_184 * V_185 ,
struct V_24 * V_25 , int V_186 )
{
struct V_2 * V_3 = F_24 ( V_25 ) ;
if ( ! V_3 -> V_187 )
return 0 ;
return F_159 ( V_185 , V_25 , V_3 -> V_187 ) ;
}
static int F_160 ( struct V_184 * V_185 , void * V_188 )
{
F_161 ( V_185 , F_162 ( F_163 ( V_185 ) ) ,
F_158 , & V_31 ,
0 , false ) ;
return 0 ;
}
static T_2 F_164 ( struct V_184 * V_185 ,
struct V_24 * V_25 , int V_186 )
{
struct V_2 * V_3 = F_24 ( V_25 ) ;
if ( ! V_3 -> V_189 )
return 0 ;
return F_159 ( V_185 , V_25 , V_3 -> V_189 ) ;
}
static int F_165 ( struct V_184 * V_185 , void * V_188 )
{
F_161 ( V_185 , F_162 ( F_163 ( V_185 ) ) ,
F_164 , & V_31 ,
0 , false ) ;
return 0 ;
}
static int F_166 ( struct V_184 * V_185 , void * V_188 )
{
struct V_32 * V_32 = F_162 ( F_163 ( V_185 ) ) ;
struct V_26 * V_176 = F_31 ( V_32 ) ;
unsigned int V_190 = 0 ;
if ( V_176 )
V_190 = V_176 -> V_144 ;
F_167 ( V_185 , L_6 , V_190 ) ;
return 0 ;
}
static int F_168 ( struct V_184 * V_185 , void * V_188 )
{
struct V_32 * V_32 = F_162 ( F_163 ( V_185 ) ) ;
struct V_26 * V_176 = F_31 ( V_32 ) ;
unsigned int V_190 = 0 ;
if ( V_176 )
V_190 = V_176 -> V_146 ;
F_167 ( V_185 , L_6 , V_190 ) ;
return 0 ;
}
static T_6 F_169 ( struct V_191 * V_192 ,
char * V_193 , T_7 V_194 , T_8 V_186 ,
bool V_181 , bool V_195 )
{
unsigned int F_84 = V_181 ? V_196 : V_197 ;
unsigned int F_85 = V_181 ? V_198 : V_199 ;
struct V_32 * V_32 = F_162 ( F_170 ( V_192 ) ) ;
struct V_200 V_201 ;
struct V_2 * V_3 ;
struct V_26 * V_202 ;
int V_203 ;
T_2 V_188 ;
V_203 = F_171 ( V_32 , & V_31 , V_193 , & V_201 ) ;
if ( V_203 )
return V_203 ;
if ( sscanf ( V_201 . V_204 , L_7 , & V_188 ) == 1 ) {
V_203 = - V_205 ;
if ( ! V_188 && V_181 )
goto V_206;
} else if ( ! strcmp ( F_172 ( V_201 . V_204 ) , L_8 ) ) {
V_188 = 0 ;
} else {
V_203 = - V_207 ;
goto V_206;
}
V_3 = F_29 ( V_201 . V_30 ) ;
V_202 = F_31 ( V_32 ) ;
V_203 = - V_205 ;
if ( ! V_188 || ( V_188 >= F_84 && V_188 <= F_85 ) ) {
if ( ! V_195 ) {
V_3 -> V_187 = V_188 ;
V_3 -> V_143 = V_188 ? : V_202 -> V_144 ;
} else {
V_3 -> V_189 = V_188 ;
V_3 -> V_145 = V_188 ? : V_202 -> V_146 ;
}
V_203 = 0 ;
}
V_206:
F_173 ( & V_201 ) ;
return V_203 ? : V_194 ;
}
static T_6 F_174 ( struct V_191 * V_192 ,
char * V_193 , T_7 V_194 , T_8 V_186 )
{
return F_169 ( V_192 , V_193 , V_194 , V_186 , false , false ) ;
}
static T_6 F_175 ( struct V_191 * V_192 ,
char * V_193 , T_7 V_194 , T_8 V_186 )
{
return F_169 ( V_192 , V_193 , V_194 , V_186 , false , true ) ;
}
static int F_146 ( struct V_208 * V_36 , T_2 V_190 ,
bool V_181 , bool V_209 , bool V_195 )
{
unsigned int F_84 = V_181 ? V_196 : V_197 ;
unsigned int F_85 = V_181 ? V_198 : V_199 ;
struct V_32 * V_32 = F_162 ( V_36 ) ;
struct V_29 * V_30 ;
struct V_26 * V_202 ;
int V_203 = 0 ;
if ( V_190 < F_84 || V_190 > F_85 )
return - V_205 ;
F_176 ( & V_32 -> V_210 ) ;
V_202 = F_31 ( V_32 ) ;
if ( ! V_202 ) {
V_203 = - V_207 ;
goto V_211;
}
if ( ! V_195 )
V_202 -> V_144 = V_190 ;
else
V_202 -> V_146 = V_190 ;
F_177 (blkg, &blkcg->blkg_list, blkcg_node) {
struct V_2 * V_3 = F_29 ( V_30 ) ;
if ( ! V_3 )
continue;
if ( ! V_195 ) {
if ( V_209 )
V_3 -> V_187 = 0 ;
if ( ! V_3 -> V_187 )
V_3 -> V_143 = V_202 -> V_144 ;
} else {
if ( V_209 )
V_3 -> V_189 = 0 ;
if ( ! V_3 -> V_189 )
V_3 -> V_145 = V_202 -> V_146 ;
}
}
V_211:
F_178 ( & V_32 -> V_210 ) ;
return V_203 ;
}
static int F_179 ( struct V_208 * V_36 , struct V_212 * V_213 ,
T_2 V_190 )
{
return F_146 ( V_36 , V_190 , false , false , false ) ;
}
static int F_180 ( struct V_208 * V_36 ,
struct V_212 * V_213 , T_2 V_190 )
{
return F_146 ( V_36 , V_190 , false , false , true ) ;
}
static int F_181 ( struct V_184 * V_185 , void * V_188 )
{
F_161 ( V_185 , F_162 ( F_163 ( V_185 ) ) , V_214 ,
& V_31 , F_182 ( V_185 ) -> V_215 , false ) ;
return 0 ;
}
static int F_183 ( struct V_184 * V_185 , void * V_188 )
{
F_161 ( V_185 , F_162 ( F_163 ( V_185 ) ) , V_216 ,
& V_31 , F_182 ( V_185 ) -> V_215 , true ) ;
return 0 ;
}
static T_2 F_184 ( struct V_184 * V_185 ,
struct V_24 * V_25 , int V_186 )
{
T_2 V_217 = F_185 ( F_28 ( V_25 ) ,
& V_31 , V_186 ) ;
return F_159 ( V_185 , V_25 , V_217 ) ;
}
static T_2 F_186 ( struct V_184 * V_185 ,
struct V_24 * V_25 , int V_186 )
{
struct V_218 V_217 = F_187 ( F_28 ( V_25 ) ,
& V_31 , V_186 ) ;
return F_188 ( V_185 , V_25 , & V_217 ) ;
}
static int F_189 ( struct V_184 * V_185 , void * V_188 )
{
F_161 ( V_185 , F_162 ( F_163 ( V_185 ) ) ,
F_184 , & V_31 ,
F_182 ( V_185 ) -> V_215 , false ) ;
return 0 ;
}
static int F_190 ( struct V_184 * V_185 , void * V_188 )
{
F_161 ( V_185 , F_162 ( F_163 ( V_185 ) ) ,
F_186 , & V_31 ,
F_182 ( V_185 ) -> V_215 , true ) ;
return 0 ;
}
static T_2 F_191 ( struct V_184 * V_185 , struct V_24 * V_25 ,
int V_186 )
{
T_2 V_217 = F_15 ( & V_25 -> V_30 -> V_219 ) ;
return F_159 ( V_185 , V_25 , V_217 >> 9 ) ;
}
static int F_192 ( struct V_184 * V_185 , void * V_188 )
{
F_161 ( V_185 , F_162 ( F_163 ( V_185 ) ) ,
F_191 , & V_31 , 0 , false ) ;
return 0 ;
}
static T_2 F_193 ( struct V_184 * V_185 ,
struct V_24 * V_25 , int V_186 )
{
struct V_218 V_220 = F_187 ( V_25 -> V_30 , NULL ,
F_194 ( struct V_29 , V_219 ) ) ;
T_2 V_217 = F_195 ( & V_220 . V_221 [ V_222 ] ) +
F_195 ( & V_220 . V_221 [ V_223 ] ) ;
return F_159 ( V_185 , V_25 , V_217 >> 9 ) ;
}
static int F_196 ( struct V_184 * V_185 , void * V_188 )
{
F_161 ( V_185 , F_162 ( F_163 ( V_185 ) ) ,
F_193 , & V_31 , 0 ,
false ) ;
return 0 ;
}
static T_2 F_197 ( struct V_184 * V_185 ,
struct V_24 * V_25 , int V_186 )
{
struct V_2 * V_3 = F_24 ( V_25 ) ;
T_2 V_224 = F_198 ( & V_3 -> V_11 . V_23 ) ;
T_2 V_188 = 0 ;
if ( V_224 ) {
V_188 = F_198 ( & V_3 -> V_11 . V_22 ) ;
V_188 = F_88 ( V_188 , V_224 ) ;
}
F_159 ( V_185 , V_25 , V_188 ) ;
return 0 ;
}
static int F_199 ( struct V_184 * V_185 , void * V_188 )
{
F_161 ( V_185 , F_162 ( F_163 ( V_185 ) ) ,
F_197 , & V_31 ,
0 , false ) ;
return 0 ;
}
static int F_200 ( struct V_184 * V_185 , void * V_188 )
{
struct V_32 * V_32 = F_162 ( F_163 ( V_185 ) ) ;
struct V_26 * V_176 = F_31 ( V_32 ) ;
F_167 ( V_185 , L_9 , V_176 -> V_144 ) ;
F_161 ( V_185 , V_32 , F_158 ,
& V_31 , 0 , false ) ;
return 0 ;
}
static T_6 F_201 ( struct V_191 * V_192 ,
char * V_193 , T_7 V_194 , T_8 V_186 )
{
char * V_225 ;
int V_203 ;
T_2 V_188 ;
V_193 = F_172 ( V_193 ) ;
V_188 = F_202 ( V_193 , & V_225 , 0 ) ;
if ( * V_225 == '\0' || sscanf ( V_193 , L_10 , & V_188 ) == 1 ) {
V_203 = F_146 ( F_170 ( V_192 ) , V_188 , true , false , false ) ;
return V_203 ? : V_194 ;
}
return F_169 ( V_192 , V_193 , V_194 , V_186 , true , false ) ;
}
static struct V_2 * F_154 ( struct V_49 * V_50 ,
struct V_32 * V_32 )
{
return V_50 -> V_226 ;
}
static inline void
F_157 ( struct V_53 * V_54 , struct V_2 * V_3 ) {
V_54 -> V_3 = V_3 ;
}
static void F_203 ( struct V_49 * V_50 , struct V_53 * V_54 ,
bool V_227 )
{
struct V_127 * * V_228 , * V_34 ;
struct V_53 * V_229 ;
T_2 V_230 ;
struct V_1 * V_89 ;
bool V_139 = true ;
int V_231 = 1 ;
T_2 V_12 = F_90 () ;
V_89 = F_1 ( V_54 -> V_3 , F_57 ( V_54 ) , F_60 ( V_54 ) ) ;
if ( F_58 ( V_54 ) ) {
V_230 = V_232 ;
V_34 = V_89 -> V_129 ;
if ( V_34 && V_34 != & V_54 -> V_127 ) {
V_229 = F_100 ( V_34 , struct V_53 , V_127 ) ;
V_230 += V_229 -> V_230 ;
} else
V_230 += V_12 ;
} else if ( ! V_227 ) {
V_230 = F_112 ( V_50 , V_54 ) + V_12 ;
V_230 -= V_54 -> V_233 ;
V_54 -> V_233 = 0 ;
} else {
V_230 = - V_234 ;
V_229 = F_99 ( V_89 ) ;
V_230 += V_229 ? V_229 -> V_230 : V_12 ;
}
if ( ! F_109 ( & V_54 -> V_127 ) ) {
V_231 = 0 ;
if ( V_230 == V_54 -> V_230 && V_54 -> V_235 == V_89 )
return;
F_103 ( & V_54 -> V_127 , V_54 -> V_235 ) ;
V_54 -> V_235 = NULL ;
}
V_34 = NULL ;
V_54 -> V_235 = V_89 ;
V_228 = & V_89 -> V_90 . V_91 . V_127 ;
while ( * V_228 ) {
V_34 = * V_228 ;
V_229 = F_100 ( V_34 , struct V_53 , V_127 ) ;
if ( V_230 < V_229 -> V_230 )
V_228 = & V_34 -> V_141 ;
else {
V_228 = & V_34 -> V_142 ;
V_139 = false ;
}
}
V_54 -> V_230 = V_230 ;
F_115 ( & V_54 -> V_127 , V_34 , V_228 ) ;
F_116 ( & V_54 -> V_127 , & V_89 -> V_90 , V_139 ) ;
V_89 -> V_61 ++ ;
if ( V_227 || ! V_231 )
return;
F_122 ( V_50 , V_54 -> V_3 ) ;
}
static struct V_53 *
F_204 ( struct V_49 * V_50 , struct V_91 * V_126 ,
T_4 V_236 , struct V_127 * * V_237 ,
struct V_127 * * * V_238 )
{
struct V_127 * * V_228 , * V_34 ;
struct V_53 * V_54 = NULL ;
V_34 = NULL ;
V_228 = & V_126 -> V_127 ;
while ( * V_228 ) {
struct V_127 * * V_128 ;
V_34 = * V_228 ;
V_54 = F_100 ( V_34 , struct V_53 , V_239 ) ;
if ( V_236 > F_98 ( V_54 -> V_240 ) )
V_128 = & ( * V_228 ) -> V_142 ;
else if ( V_236 < F_98 ( V_54 -> V_240 ) )
V_128 = & ( * V_228 ) -> V_141 ;
else
break;
V_228 = V_128 ;
V_54 = NULL ;
}
* V_237 = V_34 ;
if ( V_238 )
* V_238 = V_228 ;
return V_54 ;
}
static void F_205 ( struct V_49 * V_50 , struct V_53 * V_54 )
{
struct V_127 * * V_228 , * V_34 ;
struct V_53 * V_229 ;
if ( V_54 -> V_241 ) {
F_206 ( & V_54 -> V_239 , V_54 -> V_241 ) ;
V_54 -> V_241 = NULL ;
}
if ( F_58 ( V_54 ) )
return;
if ( ! V_54 -> V_240 )
return;
V_54 -> V_241 = & V_50 -> V_242 [ V_54 -> V_243 ] ;
V_229 = F_204 ( V_50 , V_54 -> V_241 ,
F_98 ( V_54 -> V_240 ) , & V_34 , & V_228 ) ;
if ( ! V_229 ) {
F_115 ( & V_54 -> V_239 , V_34 , V_228 ) ;
F_207 ( & V_54 -> V_239 , V_54 -> V_241 ) ;
} else
V_54 -> V_241 = NULL ;
}
static void F_208 ( struct V_49 * V_50 , struct V_53 * V_54 )
{
if ( F_209 ( V_54 ) ) {
F_203 ( V_50 , V_54 , 0 ) ;
F_205 ( V_50 , V_54 ) ;
}
}
static void F_210 ( struct V_49 * V_50 , struct V_53 * V_54 )
{
F_91 ( V_50 , V_54 , L_11 ) ;
F_21 ( F_209 ( V_54 ) ) ;
F_211 ( V_54 ) ;
V_50 -> V_72 ++ ;
if ( F_61 ( V_54 ) )
V_50 -> V_244 ++ ;
F_208 ( V_50 , V_54 ) ;
}
static void F_212 ( struct V_49 * V_50 , struct V_53 * V_54 )
{
F_91 ( V_50 , V_54 , L_12 ) ;
F_21 ( ! F_209 ( V_54 ) ) ;
F_213 ( V_54 ) ;
if ( ! F_109 ( & V_54 -> V_127 ) ) {
F_103 ( & V_54 -> V_127 , V_54 -> V_235 ) ;
V_54 -> V_235 = NULL ;
}
if ( V_54 -> V_241 ) {
F_206 ( & V_54 -> V_239 , V_54 -> V_241 ) ;
V_54 -> V_241 = NULL ;
}
F_125 ( V_50 , V_54 -> V_3 ) ;
F_21 ( ! V_50 -> V_72 ) ;
V_50 -> V_72 -- ;
if ( F_61 ( V_54 ) )
V_50 -> V_244 -- ;
}
static void F_214 ( struct V_112 * V_245 )
{
struct V_53 * V_54 = F_215 ( V_245 ) ;
const int V_74 = F_97 ( V_245 ) ;
F_21 ( ! V_54 -> V_19 [ V_74 ] ) ;
V_54 -> V_19 [ V_74 ] -- ;
F_216 ( & V_54 -> V_134 , V_245 ) ;
if ( F_209 ( V_54 ) && F_81 ( & V_54 -> V_134 ) ) {
if ( V_54 -> V_241 ) {
F_206 ( & V_54 -> V_239 , V_54 -> V_241 ) ;
V_54 -> V_241 = NULL ;
}
}
}
static void F_217 ( struct V_112 * V_245 )
{
struct V_53 * V_54 = F_215 ( V_245 ) ;
struct V_49 * V_50 = V_54 -> V_50 ;
struct V_112 * V_133 ;
V_54 -> V_19 [ F_97 ( V_245 ) ] ++ ;
F_218 ( & V_54 -> V_134 , V_245 ) ;
if ( ! F_209 ( V_54 ) )
F_210 ( V_50 , V_54 ) ;
V_133 = V_54 -> V_240 ;
V_54 -> V_240 = F_94 ( V_50 , V_54 -> V_240 , V_245 , V_50 -> V_246 ) ;
if ( V_133 != V_54 -> V_240 )
F_205 ( V_50 , V_54 ) ;
F_21 ( ! V_54 -> V_240 ) ;
}
static void F_219 ( struct V_53 * V_54 , struct V_112 * V_245 )
{
F_216 ( & V_54 -> V_134 , V_245 ) ;
V_54 -> V_19 [ F_97 ( V_245 ) ] -- ;
F_44 ( F_220 ( V_245 ) , V_245 -> V_122 ) ;
F_217 ( V_245 ) ;
F_40 ( F_220 ( V_245 ) , V_54 -> V_50 -> V_247 ,
V_245 -> V_122 ) ;
}
static struct V_112 *
F_221 ( struct V_49 * V_50 , struct V_248 * V_248 )
{
struct V_249 * V_250 = V_251 ;
struct V_62 * V_68 ;
struct V_53 * V_54 ;
V_68 = F_66 ( V_50 , V_250 -> V_65 ) ;
if ( ! V_68 )
return NULL ;
V_54 = F_68 ( V_68 , F_222 ( V_248 -> V_252 ) ) ;
if ( V_54 )
return F_223 ( & V_54 -> V_134 , F_224 ( V_248 ) ) ;
return NULL ;
}
static void F_225 ( struct V_253 * V_47 , struct V_112 * V_245 )
{
struct V_49 * V_50 = V_47 -> V_70 -> V_71 ;
V_50 -> V_254 ++ ;
F_91 ( V_50 , F_215 ( V_245 ) , L_13 ,
V_50 -> V_254 ) ;
V_50 -> V_246 = F_98 ( V_245 ) + F_226 ( V_245 ) ;
}
static void F_227 ( struct V_253 * V_47 , struct V_112 * V_245 )
{
struct V_49 * V_50 = V_47 -> V_70 -> V_71 ;
F_76 ( ! V_50 -> V_254 ) ;
V_50 -> V_254 -- ;
F_91 ( V_50 , F_215 ( V_245 ) , L_14 ,
V_50 -> V_254 ) ;
}
static void F_228 ( struct V_112 * V_245 )
{
struct V_53 * V_54 = F_215 ( V_245 ) ;
if ( V_54 -> V_240 == V_245 )
V_54 -> V_240 = F_107 ( V_54 -> V_50 , V_54 , V_245 ) ;
F_229 ( & V_245 -> V_255 ) ;
F_214 ( V_245 ) ;
V_54 -> V_50 -> V_256 -- ;
F_44 ( F_220 ( V_245 ) , V_245 -> V_122 ) ;
if ( V_245 -> V_122 & V_123 ) {
F_76 ( ! V_54 -> V_257 ) ;
V_54 -> V_257 -- ;
}
}
static enum V_258 F_230 ( struct V_253 * V_47 , struct V_112 * * V_259 ,
struct V_248 * V_248 )
{
struct V_49 * V_50 = V_47 -> V_70 -> V_71 ;
struct V_112 * V_260 ;
V_260 = F_221 ( V_50 , V_248 ) ;
if ( V_260 && F_231 ( V_260 , V_248 ) ) {
* V_259 = V_260 ;
return V_261 ;
}
return V_262 ;
}
static void F_232 ( struct V_253 * V_47 , struct V_112 * V_259 ,
enum V_258 type )
{
if ( type == V_261 ) {
struct V_53 * V_54 = F_215 ( V_259 ) ;
F_219 ( V_54 , V_259 ) ;
}
}
static void F_233 ( struct V_253 * V_47 , struct V_112 * V_259 ,
struct V_248 * V_248 )
{
F_45 ( F_220 ( V_259 ) , V_248 -> V_252 ) ;
}
static void
F_234 ( struct V_253 * V_47 , struct V_112 * V_245 ,
struct V_112 * V_132 )
{
struct V_53 * V_54 = F_215 ( V_245 ) ;
struct V_49 * V_50 = V_47 -> V_70 -> V_71 ;
if ( ! F_235 ( & V_245 -> V_255 ) && ! F_235 ( & V_132 -> V_255 ) &&
V_132 -> V_263 < V_245 -> V_263 &&
V_54 == F_215 ( V_132 ) ) {
F_236 ( & V_245 -> V_255 , & V_132 -> V_255 ) ;
V_245 -> V_263 = V_132 -> V_263 ;
}
if ( V_54 -> V_240 == V_132 )
V_54 -> V_240 = V_245 ;
F_228 ( V_132 ) ;
F_45 ( F_220 ( V_245 ) , V_132 -> V_122 ) ;
V_54 = F_215 ( V_132 ) ;
if ( F_209 ( V_54 ) && F_81 ( & V_54 -> V_134 ) &&
V_54 != V_50 -> V_264 )
F_212 ( V_50 , V_54 ) ;
}
static int F_237 ( struct V_253 * V_47 , struct V_112 * V_245 ,
struct V_248 * V_248 )
{
struct V_49 * V_50 = V_47 -> V_70 -> V_71 ;
bool V_69 = F_222 ( V_248 -> V_252 ) ;
struct V_62 * V_68 ;
struct V_53 * V_54 ;
if ( V_69 && ! F_97 ( V_245 ) )
return false ;
V_68 = F_66 ( V_50 , V_251 -> V_65 ) ;
if ( ! V_68 )
return false ;
V_54 = F_68 ( V_68 , V_69 ) ;
return V_54 == F_215 ( V_245 ) ;
}
static int F_238 ( struct V_253 * V_47 , struct V_112 * V_245 ,
struct V_112 * V_132 )
{
return F_215 ( V_245 ) == F_215 ( V_132 ) ;
}
static inline void F_239 ( struct V_49 * V_50 , struct V_53 * V_54 )
{
F_240 ( & V_50 -> V_265 ) ;
F_17 ( V_54 -> V_3 ) ;
}
static void F_241 ( struct V_49 * V_50 ,
struct V_53 * V_54 )
{
if ( V_54 ) {
F_91 ( V_50 , V_54 , L_15 ,
V_50 -> V_166 , V_50 -> V_164 ) ;
F_23 ( V_54 -> V_3 ) ;
V_54 -> V_109 = 0 ;
V_54 -> V_157 = F_90 () ;
V_54 -> V_111 = 0 ;
V_54 -> V_110 = 0 ;
V_54 -> V_161 = 0 ;
V_54 -> V_167 = 0 ;
F_242 ( V_54 ) ;
F_243 ( V_54 ) ;
F_244 ( V_54 ) ;
F_245 ( V_54 ) ;
F_246 ( V_54 ) ;
F_239 ( V_50 , V_54 ) ;
}
V_50 -> V_264 = V_54 ;
}
static void
F_247 ( struct V_49 * V_50 , struct V_53 * V_54 ,
bool V_266 )
{
F_91 ( V_50 , V_54 , L_16 , V_266 ) ;
if ( F_248 ( V_54 ) )
F_239 ( V_50 , V_54 ) ;
F_242 ( V_54 ) ;
F_249 ( V_54 ) ;
if ( F_250 ( V_54 ) && F_251 ( V_54 ) )
F_252 ( V_54 ) ;
if ( V_266 ) {
if ( F_93 ( V_54 ) )
V_54 -> V_233 = F_87 ( V_50 , V_54 ) ;
else
V_54 -> V_233 = V_54 -> V_110 - F_90 () ;
F_91 ( V_50 , V_54 , L_17 , V_54 -> V_233 ) ;
}
F_129 ( V_50 , V_54 -> V_3 , V_54 ) ;
if ( F_209 ( V_54 ) && F_81 ( & V_54 -> V_134 ) )
F_212 ( V_50 , V_54 ) ;
F_208 ( V_50 , V_54 ) ;
if ( V_54 == V_50 -> V_264 )
V_50 -> V_264 = NULL ;
if ( V_50 -> V_267 ) {
F_253 ( V_50 -> V_267 -> V_64 . V_66 ) ;
V_50 -> V_267 = NULL ;
}
}
static inline void F_254 ( struct V_49 * V_50 , bool V_266 )
{
struct V_53 * V_54 = V_50 -> V_264 ;
if ( V_54 )
F_247 ( V_50 , V_54 , V_266 ) ;
}
static struct V_53 * F_255 ( struct V_49 * V_50 )
{
struct V_1 * V_89 = F_1 ( V_50 -> V_247 ,
V_50 -> V_166 , V_50 -> V_164 ) ;
if ( ! V_50 -> V_256 )
return NULL ;
if ( ! V_89 )
return NULL ;
if ( F_81 ( & V_89 -> V_90 . V_91 ) )
return NULL ;
return F_99 ( V_89 ) ;
}
static struct V_53 * F_256 ( struct V_49 * V_50 )
{
struct V_2 * V_3 ;
struct V_53 * V_54 ;
int V_168 , V_169 ;
struct V_1 * V_89 ;
if ( ! V_50 -> V_256 )
return NULL ;
V_3 = F_257 ( V_50 ) ;
if ( ! V_3 )
return NULL ;
F_131 (cfqg, i, j, st) {
V_54 = F_99 ( V_89 ) ;
if ( V_54 )
return V_54 ;
}
return NULL ;
}
static struct V_53 * F_258 ( struct V_49 * V_50 ,
struct V_53 * V_54 )
{
if ( ! V_54 )
V_54 = F_255 ( V_50 ) ;
F_241 ( V_50 , V_54 ) ;
return V_54 ;
}
static inline T_4 F_259 ( struct V_49 * V_50 ,
struct V_112 * V_245 )
{
if ( F_98 ( V_245 ) >= V_50 -> V_246 )
return F_98 ( V_245 ) - V_50 -> V_246 ;
else
return V_50 -> V_246 - F_98 ( V_245 ) ;
}
static inline int F_260 ( struct V_49 * V_50 , struct V_53 * V_54 ,
struct V_112 * V_245 )
{
return F_259 ( V_50 , V_245 ) <= V_268 ;
}
static struct V_53 * F_261 ( struct V_49 * V_50 ,
struct V_53 * V_269 )
{
struct V_91 * V_126 = & V_50 -> V_242 [ V_269 -> V_243 ] ;
struct V_127 * V_34 , * V_136 ;
struct V_53 * V_229 ;
T_4 V_236 = V_50 -> V_246 ;
if ( F_81 ( V_126 ) )
return NULL ;
V_229 = F_204 ( V_50 , V_126 , V_236 , & V_34 , NULL ) ;
if ( V_229 )
return V_229 ;
V_229 = F_100 ( V_34 , struct V_53 , V_239 ) ;
if ( F_260 ( V_50 , V_269 , V_229 -> V_240 ) )
return V_229 ;
if ( F_98 ( V_229 -> V_240 ) < V_236 )
V_136 = F_108 ( & V_229 -> V_239 ) ;
else
V_136 = F_104 ( & V_229 -> V_239 ) ;
if ( ! V_136 )
return NULL ;
V_229 = F_100 ( V_136 , struct V_53 , V_239 ) ;
if ( F_260 ( V_50 , V_269 , V_229 -> V_240 ) )
return V_229 ;
return NULL ;
}
static struct V_53 * F_262 ( struct V_49 * V_50 ,
struct V_53 * V_269 )
{
struct V_53 * V_54 ;
if ( F_58 ( V_269 ) )
return NULL ;
if ( ! F_61 ( V_269 ) )
return NULL ;
if ( F_251 ( V_269 ) )
return NULL ;
if ( V_269 -> V_3 -> V_135 == 1 )
return NULL ;
V_54 = F_261 ( V_50 , V_269 ) ;
if ( ! V_54 )
return NULL ;
if ( V_269 -> V_3 != V_54 -> V_3 )
return NULL ;
if ( ! F_61 ( V_54 ) )
return NULL ;
if ( F_251 ( V_54 ) )
return NULL ;
if ( F_59 ( V_54 ) != F_59 ( V_269 ) )
return NULL ;
return V_54 ;
}
static bool F_263 ( struct V_49 * V_50 , struct V_53 * V_54 )
{
enum V_4 V_60 = F_57 ( V_54 ) ;
struct V_1 * V_89 = V_54 -> V_235 ;
F_21 ( ! V_89 ) ;
F_21 ( ! V_89 -> V_61 ) ;
if ( ! V_50 -> V_51 )
return false ;
if ( V_60 == V_7 )
return false ;
if ( F_62 ( V_54 ) &&
! ( F_264 ( V_50 -> V_67 ) && V_50 -> V_52 ) )
return true ;
if ( V_89 -> V_61 == 1 && F_61 ( V_54 ) &&
! F_265 ( V_50 , & V_89 -> V_171 , false ) )
return true ;
F_91 ( V_50 , V_54 , L_18 , V_89 -> V_61 ) ;
return false ;
}
static void F_266 ( struct V_49 * V_50 )
{
struct V_53 * V_54 = V_50 -> V_264 ;
struct V_1 * V_89 = V_54 -> V_235 ;
struct V_62 * V_68 ;
T_2 V_270 , V_271 = 0 ;
T_2 V_12 = F_90 () ;
if ( F_264 ( V_50 -> V_67 ) && V_50 -> V_52 &&
! V_50 -> V_272 )
return;
F_76 ( ! F_81 ( & V_54 -> V_134 ) ) ;
F_76 ( F_93 ( V_54 ) ) ;
if ( ! F_263 ( V_50 , V_54 ) ) {
if ( V_50 -> V_272 )
V_271 = V_50 -> V_272 ;
else
return;
}
if ( V_54 -> V_273 )
return;
V_68 = V_50 -> V_267 ;
if ( ! V_68 || ! F_267 ( & V_68 -> V_64 . V_66 -> V_274 ) )
return;
if ( F_268 ( V_68 -> V_171 . V_275 ) &&
( V_54 -> V_110 - V_12 < V_68 -> V_171 . V_276 ) ) {
F_91 ( V_50 , V_54 , L_19 ,
V_68 -> V_171 . V_276 ) ;
return;
}
if ( V_271 &&
( V_54 -> V_3 -> V_135 > 1 ||
F_265 ( V_50 , & V_89 -> V_171 , true ) ) )
return;
F_269 ( V_54 ) ;
if ( V_271 )
V_270 = V_50 -> V_272 ;
else
V_270 = V_50 -> V_51 ;
F_270 ( & V_50 -> V_265 , F_271 ( V_270 ) ,
V_277 ) ;
F_20 ( V_54 -> V_3 ) ;
F_91 ( V_50 , V_54 , L_20 , V_270 ,
V_271 ? 1 : 0 ) ;
}
static void F_272 ( struct V_253 * V_47 , struct V_112 * V_245 )
{
struct V_49 * V_50 = V_47 -> V_70 -> V_71 ;
struct V_53 * V_54 = F_215 ( V_245 ) ;
F_91 ( V_50 , V_54 , L_21 ) ;
V_54 -> V_240 = F_107 ( V_50 , V_54 , V_245 ) ;
F_228 ( V_245 ) ;
V_54 -> V_273 ++ ;
( F_220 ( V_245 ) ) -> V_273 ++ ;
F_273 ( V_47 , V_245 ) ;
V_50 -> V_278 [ F_61 ( V_54 ) ] ++ ;
V_54 -> V_167 += F_226 ( V_245 ) ;
}
static struct V_112 * F_274 ( struct V_53 * V_54 )
{
struct V_112 * V_245 = NULL ;
if ( F_275 ( V_54 ) )
return NULL ;
F_276 ( V_54 ) ;
if ( F_235 ( & V_54 -> V_279 ) )
return NULL ;
V_245 = F_277 ( V_54 -> V_279 . V_132 ) ;
if ( F_90 () < V_245 -> V_263 )
V_245 = NULL ;
return V_245 ;
}
static inline int
F_278 ( struct V_49 * V_50 , struct V_53 * V_54 )
{
const int V_280 = V_50 -> V_281 ;
F_76 ( V_54 -> V_81 >= V_80 ) ;
return 2 * V_280 * ( V_80 - V_54 -> V_81 ) ;
}
static int F_279 ( struct V_53 * V_54 )
{
int V_282 , V_283 ;
V_283 = V_54 -> V_284 [ V_285 ] + V_54 -> V_284 [ V_286 ] ;
V_282 = V_54 -> V_287 - V_283 ;
F_21 ( V_282 < 0 ) ;
return V_282 ;
}
static void F_280 ( struct V_53 * V_54 , struct V_53 * V_231 )
{
int V_282 , V_288 ;
struct V_53 * V_229 ;
if ( ! F_279 ( V_231 ) )
return;
while ( ( V_229 = V_231 -> V_231 ) ) {
if ( V_229 == V_54 )
return;
V_231 = V_229 ;
}
V_282 = F_279 ( V_54 ) ;
V_288 = F_279 ( V_231 ) ;
if ( V_282 == 0 || V_288 == 0 )
return;
if ( V_288 >= V_282 ) {
V_54 -> V_231 = V_231 ;
V_231 -> V_287 += V_282 ;
} else {
V_231 -> V_231 = V_54 ;
V_54 -> V_287 += V_288 ;
}
}
static enum V_6 F_281 ( struct V_49 * V_50 ,
struct V_2 * V_3 , enum V_4 V_60 )
{
struct V_53 * V_67 ;
int V_168 ;
bool V_289 = false ;
T_2 V_290 = 0 ;
enum V_6 V_291 = V_58 ;
for ( V_168 = 0 ; V_168 <= V_59 ; ++ V_168 ) {
V_67 = F_99 ( F_1 ( V_3 , V_60 , V_168 ) ) ;
if ( V_67 &&
( ! V_289 || V_67 -> V_230 < V_290 ) ) {
V_290 = V_67 -> V_230 ;
V_291 = V_168 ;
V_289 = true ;
}
}
return V_291 ;
}
static void
F_282 ( struct V_49 * V_50 , struct V_2 * V_3 )
{
T_2 V_78 ;
unsigned V_61 ;
struct V_1 * V_89 ;
T_2 V_106 ;
enum V_4 V_292 = V_50 -> V_166 ;
T_2 V_12 = F_90 () ;
if ( F_63 ( V_55 , V_50 , V_3 ) )
V_50 -> V_166 = V_55 ;
else if ( F_63 ( V_56 , V_50 , V_3 ) )
V_50 -> V_166 = V_56 ;
else {
V_50 -> V_166 = V_7 ;
V_50 -> V_162 = V_12 + F_128 ( 1 ) ;
return;
}
if ( V_292 != V_50 -> V_166 )
goto V_293;
V_89 = F_1 ( V_3 , V_50 -> V_166 , V_50 -> V_164 ) ;
V_61 = V_89 -> V_61 ;
if ( V_61 && ! ( V_12 > V_50 -> V_162 ) )
return;
V_293:
V_50 -> V_164 = F_281 ( V_50 , V_3 ,
V_50 -> V_166 ) ;
V_89 = F_1 ( V_3 , V_50 -> V_166 , V_50 -> V_164 ) ;
V_61 = V_89 -> V_61 ;
V_106 = F_86 ( V_50 , V_3 ) ;
V_78 = F_75 ( V_106 * V_61 ,
F_120 ( unsigned , V_3 -> V_100 [ V_50 -> V_166 ] ,
F_63 ( V_50 -> V_166 , V_50 ,
V_3 ) ) ) ;
if ( V_50 -> V_164 == V_57 ) {
T_2 V_220 ;
V_220 = V_50 -> V_101 *
F_64 ( V_50 , V_3 ) ;
V_220 = F_75 ( V_220 , V_50 -> V_72 ) ;
V_78 = F_283 ( T_2 , V_78 , V_220 ) ;
V_78 = F_88 ( V_78 * V_50 -> V_77 [ 0 ] , V_50 -> V_77 [ 1 ] ) ;
} else
V_78 = F_85 ( V_78 , 2 * V_50 -> V_51 ) ;
V_78 = F_120 ( T_2 , V_78 , V_294 ) ;
F_72 ( V_50 , L_22 , V_78 ) ;
V_50 -> V_162 = V_12 + V_78 ;
}
static struct V_2 * F_257 ( struct V_49 * V_50 )
{
struct V_1 * V_89 = & V_50 -> V_154 ;
struct V_2 * V_3 ;
if ( F_81 ( & V_89 -> V_90 . V_91 ) )
return NULL ;
V_3 = F_102 ( V_89 ) ;
F_80 ( V_89 ) ;
return V_3 ;
}
static void F_284 ( struct V_49 * V_50 )
{
struct V_2 * V_3 = F_257 ( V_50 ) ;
T_2 V_12 = F_90 () ;
V_50 -> V_247 = V_3 ;
if ( V_3 -> V_155 ) {
V_50 -> V_162 = V_12 + V_3 -> V_155 ;
V_50 -> V_164 = V_3 -> V_163 ;
V_50 -> V_166 = V_3 -> V_165 ;
} else
V_50 -> V_162 = V_12 - 1 ;
F_282 ( V_50 , V_3 ) ;
}
static struct V_53 * F_285 ( struct V_49 * V_50 )
{
struct V_53 * V_54 , * V_231 = NULL ;
T_2 V_12 = F_90 () ;
V_54 = V_50 -> V_264 ;
if ( ! V_54 )
goto V_295;
if ( ! V_50 -> V_256 )
return NULL ;
if ( F_286 ( V_54 ) && ! F_81 ( & V_54 -> V_134 ) )
goto V_296;
if ( F_92 ( V_54 ) && ! F_287 ( V_54 ) ) {
if ( V_54 -> V_3 -> V_135 == 1 && F_81 ( & V_54 -> V_134 )
&& V_54 -> V_273 && F_263 ( V_50 , V_54 ) ) {
V_54 = NULL ;
goto V_297;
} else
goto V_298;
}
if ( ! F_81 ( & V_54 -> V_134 ) )
goto V_297;
V_231 = F_262 ( V_50 , V_54 ) ;
if ( V_231 ) {
if ( ! V_54 -> V_231 )
F_280 ( V_54 , V_231 ) ;
goto V_296;
}
if ( F_288 ( & V_50 -> V_265 ) ) {
V_54 = NULL ;
goto V_297;
}
if ( F_251 ( V_54 ) && F_62 ( V_54 ) &&
( F_93 ( V_54 ) ||
( V_54 -> V_110 - V_12 > V_12 - V_54 -> V_109 ) ) ) {
F_289 ( V_54 ) ;
F_290 ( V_54 ) ;
}
if ( V_54 -> V_273 && F_263 ( V_50 , V_54 ) ) {
V_54 = NULL ;
goto V_297;
}
V_298:
if ( V_50 -> V_272 && V_54 -> V_3 -> V_135 == 1 &&
V_54 -> V_3 -> V_273 &&
! F_265 ( V_50 , & V_54 -> V_3 -> V_171 , true ) ) {
V_54 = NULL ;
goto V_297;
}
V_296:
F_254 ( V_50 , 0 ) ;
V_295:
if ( ! V_231 )
F_284 ( V_50 ) ;
V_54 = F_258 ( V_50 , V_231 ) ;
V_297:
return V_54 ;
}
static int F_291 ( struct V_53 * V_54 )
{
int V_273 = 0 ;
while ( V_54 -> V_240 ) {
F_272 ( V_54 -> V_50 -> V_67 , V_54 -> V_240 ) ;
V_273 ++ ;
}
F_21 ( ! F_235 ( & V_54 -> V_279 ) ) ;
F_247 ( V_54 -> V_50 , V_54 , 0 ) ;
return V_273 ;
}
static int F_292 ( struct V_49 * V_50 )
{
struct V_53 * V_54 ;
int V_273 = 0 ;
F_254 ( V_50 , 0 ) ;
while ( ( V_54 = F_256 ( V_50 ) ) != NULL ) {
F_241 ( V_50 , V_54 ) ;
V_273 += F_291 ( V_54 ) ;
}
F_21 ( V_50 -> V_72 ) ;
F_72 ( V_50 , L_23 , V_273 ) ;
return V_273 ;
}
static inline bool F_293 ( struct V_49 * V_50 ,
struct V_53 * V_54 )
{
T_2 V_12 = F_90 () ;
if ( F_93 ( V_54 ) )
return true ;
if ( V_12 + V_50 -> V_51 * V_54 -> V_273 > V_54 -> V_110 )
return true ;
return false ;
}
static bool F_294 ( struct V_49 * V_50 , struct V_53 * V_54 )
{
unsigned int V_299 ;
if ( F_287 ( V_54 ) )
return true ;
if ( F_263 ( V_50 , V_54 ) && V_50 -> V_278 [ V_300 ] )
return false ;
if ( V_50 -> V_278 [ V_301 ] && ! F_61 ( V_54 ) )
return false ;
V_299 = F_120 (unsigned int, cfqd->cfq_quantum / 2 , 1 ) ;
if ( F_58 ( V_54 ) )
V_299 = 1 ;
if ( V_54 -> V_273 >= V_299 ) {
bool V_302 = false ;
if ( F_58 ( V_54 ) )
return false ;
if ( F_61 ( V_54 ) && V_50 -> V_244 == 1 )
V_302 = true ;
if ( V_50 -> V_72 > 1 && F_293 ( V_50 , V_54 ) &&
! V_302 )
return false ;
if ( V_50 -> V_72 == 1 || V_302 )
V_299 = - 1 ;
else
V_299 = V_50 -> V_303 ;
}
if ( ! F_61 ( V_54 ) && V_50 -> V_102 ) {
T_2 V_304 = F_90 () - V_50 -> V_305 ;
unsigned int V_306 ;
V_306 = F_88 ( V_304 , V_50 -> V_77 [ 1 ] ) ;
if ( ! V_306 && ! V_54 -> V_273 )
V_306 = 1 ;
if ( V_306 < V_299 )
V_299 = V_306 ;
}
return V_54 -> V_273 < V_299 ;
}
static bool F_295 ( struct V_49 * V_50 , struct V_53 * V_54 )
{
struct V_112 * V_245 ;
F_21 ( F_81 ( & V_54 -> V_134 ) ) ;
V_245 = F_274 ( V_54 ) ;
if ( V_245 )
F_296 ( V_54 ) ;
if ( ! F_294 ( V_50 , V_54 ) )
return false ;
if ( ! V_245 )
V_245 = V_54 -> V_240 ;
else
F_91 ( V_54 -> V_50 , V_54 , L_24 , V_245 ) ;
F_272 ( V_50 -> V_67 , V_245 ) ;
if ( ! V_50 -> V_267 ) {
struct V_62 * V_68 = F_297 ( V_245 ) ;
F_298 ( & V_68 -> V_64 . V_66 -> V_307 ) ;
V_50 -> V_267 = V_68 ;
}
return true ;
}
static int F_299 ( struct V_253 * V_47 , int V_308 )
{
struct V_49 * V_50 = V_47 -> V_70 -> V_71 ;
struct V_53 * V_54 ;
if ( ! V_50 -> V_72 )
return 0 ;
if ( F_55 ( V_308 ) )
return F_292 ( V_50 ) ;
V_54 = F_285 ( V_50 ) ;
if ( ! V_54 )
return 0 ;
if ( ! F_295 ( V_50 , V_54 ) )
return 0 ;
V_54 -> V_161 ++ ;
F_243 ( V_54 ) ;
if ( V_50 -> V_72 > 1 && ( ( ! F_61 ( V_54 ) &&
V_54 -> V_161 >= F_278 ( V_50 , V_54 ) ) ||
F_58 ( V_54 ) ) ) {
V_54 -> V_110 = F_90 () + 1 ;
F_254 ( V_50 , 0 ) ;
}
F_91 ( V_50 , V_54 , L_25 ) ;
return 1 ;
}
static void F_151 ( struct V_53 * V_54 )
{
struct V_49 * V_50 = V_54 -> V_50 ;
struct V_2 * V_3 ;
F_21 ( V_54 -> V_287 <= 0 ) ;
V_54 -> V_287 -- ;
if ( V_54 -> V_287 )
return;
F_91 ( V_50 , V_54 , L_26 ) ;
F_21 ( F_111 ( & V_54 -> V_134 ) ) ;
F_21 ( V_54 -> V_284 [ V_285 ] + V_54 -> V_284 [ V_286 ] ) ;
V_3 = V_54 -> V_3 ;
if ( F_55 ( V_50 -> V_264 == V_54 ) ) {
F_247 ( V_50 , V_54 , 0 ) ;
F_71 ( V_50 ) ;
}
F_21 ( F_209 ( V_54 ) ) ;
F_300 ( V_309 , V_54 ) ;
F_38 ( V_3 ) ;
}
static void F_301 ( struct V_53 * V_54 )
{
struct V_53 * V_229 , * V_132 ;
V_229 = V_54 -> V_231 ;
while ( V_229 ) {
if ( V_229 == V_54 ) {
F_302 ( 1 , L_27 ) ;
break;
}
V_132 = V_229 -> V_231 ;
F_151 ( V_229 ) ;
V_229 = V_132 ;
}
}
static void F_303 ( struct V_49 * V_50 , struct V_53 * V_54 )
{
if ( F_55 ( V_54 == V_50 -> V_264 ) ) {
F_247 ( V_50 , V_54 , 0 ) ;
F_71 ( V_50 ) ;
}
F_301 ( V_54 ) ;
F_151 ( V_54 ) ;
}
static void F_304 ( struct V_63 * V_64 )
{
struct V_62 * V_68 = F_65 ( V_64 ) ;
V_68 -> V_171 . V_172 = F_90 () ;
}
static void F_305 ( struct V_63 * V_64 )
{
struct V_62 * V_68 = F_65 ( V_64 ) ;
struct V_49 * V_50 = F_70 ( V_68 ) ;
if ( F_68 ( V_68 , false ) ) {
F_303 ( V_50 , F_68 ( V_68 , false ) ) ;
F_69 ( V_68 , NULL , false ) ;
}
if ( F_68 ( V_68 , true ) ) {
F_303 ( V_50 , F_68 ( V_68 , true ) ) ;
F_69 ( V_68 , NULL , true ) ;
}
}
static void F_306 ( struct V_53 * V_54 , struct V_62 * V_68 )
{
struct V_249 * V_250 = V_251 ;
int V_310 ;
if ( ! F_307 ( V_54 ) )
return;
V_310 = F_308 ( V_68 -> V_81 ) ;
switch ( V_310 ) {
default:
F_309 ( V_311 L_28 , V_310 ) ;
case V_312 :
V_54 -> V_81 = F_310 ( V_250 ) ;
V_54 -> V_310 = F_311 ( V_250 ) ;
break;
case V_313 :
V_54 -> V_81 = F_312 ( V_68 -> V_81 ) ;
V_54 -> V_310 = V_313 ;
break;
case V_314 :
V_54 -> V_81 = F_312 ( V_68 -> V_81 ) ;
V_54 -> V_310 = V_314 ;
break;
case V_315 :
V_54 -> V_310 = V_315 ;
V_54 -> V_81 = 7 ;
F_290 ( V_54 ) ;
break;
}
V_54 -> V_243 = V_54 -> V_81 ;
V_54 -> V_316 = V_54 -> V_310 ;
F_313 ( V_54 ) ;
}
static void F_314 ( struct V_62 * V_68 , struct V_248 * V_248 )
{
int V_81 = V_68 -> V_64 . V_66 -> V_81 ;
struct V_49 * V_50 = F_70 ( V_68 ) ;
struct V_53 * V_54 ;
if ( F_55 ( ! V_50 ) || F_156 ( V_68 -> V_81 == V_81 ) )
return;
V_54 = F_68 ( V_68 , false ) ;
if ( V_54 ) {
F_151 ( V_54 ) ;
V_54 = F_315 ( V_50 , V_300 , V_68 , V_248 ) ;
F_69 ( V_68 , V_54 , false ) ;
}
V_54 = F_68 ( V_68 , true ) ;
if ( V_54 )
F_316 ( V_54 ) ;
V_68 -> V_81 = V_81 ;
}
static void F_317 ( struct V_49 * V_50 , struct V_53 * V_54 ,
T_9 V_317 , bool V_69 )
{
F_106 ( & V_54 -> V_127 ) ;
F_106 ( & V_54 -> V_239 ) ;
F_318 ( & V_54 -> V_279 ) ;
V_54 -> V_287 = 0 ;
V_54 -> V_50 = V_50 ;
F_316 ( V_54 ) ;
if ( V_69 ) {
if ( ! F_58 ( V_54 ) )
F_319 ( V_54 ) ;
F_320 ( V_54 ) ;
}
V_54 -> V_317 = V_317 ;
}
static void F_321 ( struct V_62 * V_68 , struct V_248 * V_248 )
{
struct V_49 * V_50 = F_70 ( V_68 ) ;
struct V_53 * V_54 ;
T_1 V_318 ;
F_322 () ;
V_318 = F_323 ( V_248 ) -> V_36 . V_318 ;
F_324 () ;
if ( F_55 ( ! V_50 ) || F_156 ( V_68 -> V_319 == V_318 ) )
return;
V_54 = F_68 ( V_68 , false ) ;
if ( V_54 ) {
F_91 ( V_50 , V_54 , L_29 ) ;
F_69 ( V_68 , NULL , false ) ;
F_151 ( V_54 ) ;
}
V_54 = F_68 ( V_68 , true ) ;
if ( V_54 ) {
F_91 ( V_50 , V_54 , L_29 ) ;
F_69 ( V_68 , NULL , true ) ;
F_151 ( V_54 ) ;
}
V_68 -> V_319 = V_318 ;
}
static inline void F_321 ( struct V_62 * V_68 , struct V_248 * V_248 )
{
}
static struct V_53 * *
F_325 ( struct V_2 * V_3 , int V_310 , int V_81 )
{
switch ( V_310 ) {
case V_313 :
return & V_3 -> V_182 [ 0 ] [ V_81 ] ;
case V_312 :
V_81 = V_320 ;
case V_314 :
return & V_3 -> V_182 [ 1 ] [ V_81 ] ;
case V_315 :
return & V_3 -> V_183 ;
default:
F_326 () ;
}
}
static struct V_53 *
F_315 ( struct V_49 * V_50 , bool V_69 , struct V_62 * V_68 ,
struct V_248 * V_248 )
{
int V_310 = F_308 ( V_68 -> V_81 ) ;
int V_81 = F_312 ( V_68 -> V_81 ) ;
struct V_53 * * V_182 = NULL ;
struct V_53 * V_54 ;
struct V_2 * V_3 ;
F_322 () ;
V_3 = F_154 ( V_50 , F_323 ( V_248 ) ) ;
if ( ! V_3 ) {
V_54 = & V_50 -> V_321 ;
goto V_211;
}
if ( ! V_69 ) {
if ( ! F_327 ( V_68 -> V_81 ) ) {
struct V_249 * V_250 = V_251 ;
V_81 = F_310 ( V_250 ) ;
V_310 = F_311 ( V_250 ) ;
}
V_182 = F_325 ( V_3 , V_310 , V_81 ) ;
V_54 = * V_182 ;
if ( V_54 )
goto V_211;
}
V_54 = F_328 ( V_309 ,
V_322 | V_323 | V_324 ,
V_50 -> V_67 -> V_136 ) ;
if ( ! V_54 ) {
V_54 = & V_50 -> V_321 ;
goto V_211;
}
V_54 -> V_310 = V_312 ;
F_317 ( V_50 , V_54 , V_251 -> V_317 , V_69 ) ;
F_306 ( V_54 , V_68 ) ;
F_157 ( V_54 , V_3 ) ;
F_91 ( V_50 , V_54 , L_30 ) ;
if ( V_182 ) {
V_54 -> V_287 ++ ;
* V_182 = V_54 ;
}
V_211:
V_54 -> V_287 ++ ;
F_324 () ;
return V_54 ;
}
static void
F_329 ( struct V_325 * V_171 , T_2 V_326 )
{
T_2 V_327 = F_90 () - V_171 -> V_172 ;
V_327 = F_84 ( V_327 , 2UL * V_326 ) ;
V_171 -> V_275 = ( 7 * V_171 -> V_275 + 256 ) / 8 ;
V_171 -> V_328 = F_75 ( 7 * V_171 -> V_328 + 256 * V_327 , 8 ) ;
V_171 -> V_276 = F_330 ( V_171 -> V_328 + 128 ,
V_171 -> V_275 ) ;
}
static void
F_331 ( struct V_49 * V_50 , struct V_53 * V_54 ,
struct V_62 * V_68 )
{
if ( F_61 ( V_54 ) ) {
F_329 ( & V_68 -> V_171 , V_50 -> V_51 ) ;
F_329 ( & V_54 -> V_235 -> V_171 ,
V_50 -> V_51 ) ;
}
#ifdef F_332
F_329 ( & V_54 -> V_3 -> V_171 , V_50 -> V_272 ) ;
#endif
}
static void
F_333 ( struct V_49 * V_50 , struct V_53 * V_54 ,
struct V_112 * V_245 )
{
T_4 V_329 = 0 ;
T_4 V_330 = F_226 ( V_245 ) ;
if ( V_54 -> V_331 ) {
if ( V_54 -> V_331 < F_98 ( V_245 ) )
V_329 = F_98 ( V_245 ) - V_54 -> V_331 ;
else
V_329 = V_54 -> V_331 - F_98 ( V_245 ) ;
}
V_54 -> V_332 <<= 1 ;
if ( F_264 ( V_50 -> V_67 ) )
V_54 -> V_332 |= ( V_330 < V_333 ) ;
else
V_54 -> V_332 |= ( V_329 > V_334 ) ;
}
static inline bool F_334 ( struct V_112 * V_259 )
{
return F_335 ( V_259 ) == V_335 &&
( V_259 -> V_122 & ( V_336 | V_337 ) ) == V_336 ;
}
static void
F_336 ( struct V_49 * V_50 , struct V_53 * V_54 ,
struct V_62 * V_68 )
{
int V_338 , V_339 ;
if ( ! F_61 ( V_54 ) || F_58 ( V_54 ) )
return;
V_339 = V_338 = F_62 ( V_54 ) ;
if ( V_54 -> V_19 [ 0 ] + V_54 -> V_19 [ 1 ] >= 4 )
F_337 ( V_54 ) ;
if ( V_54 -> V_240 && F_334 ( V_54 -> V_240 ) )
V_339 = 0 ;
else if ( ! F_267 ( & V_68 -> V_64 . V_66 -> V_274 ) ||
! V_50 -> V_51 ||
( ! F_338 ( V_54 ) && F_251 ( V_54 ) ) )
V_339 = 0 ;
else if ( F_268 ( V_68 -> V_171 . V_275 ) ) {
if ( V_68 -> V_171 . V_276 > V_50 -> V_51 )
V_339 = 0 ;
else
V_339 = 1 ;
}
if ( V_338 != V_339 ) {
F_91 ( V_50 , V_54 , L_31 , V_339 ) ;
if ( V_339 )
F_319 ( V_54 ) ;
else
F_290 ( V_54 ) ;
}
}
static bool
F_339 ( struct V_49 * V_50 , struct V_53 * V_231 ,
struct V_112 * V_245 )
{
struct V_53 * V_54 ;
V_54 = V_50 -> V_264 ;
if ( ! V_54 )
return false ;
if ( F_58 ( V_231 ) )
return false ;
if ( F_58 ( V_54 ) )
return true ;
if ( F_59 ( V_54 ) && ! F_59 ( V_231 ) )
return false ;
if ( F_97 ( V_245 ) && ! F_61 ( V_54 ) && ! F_287 ( V_54 ) )
return true ;
if ( ! F_34 ( V_54 -> V_3 , V_231 -> V_3 ) )
return false ;
if ( F_92 ( V_54 ) )
return true ;
if ( F_59 ( V_231 ) && ! F_59 ( V_54 ) )
return true ;
F_124 ( V_54 -> V_310 != V_231 -> V_310 ) ;
if ( V_50 -> V_164 == V_58 &&
F_60 ( V_231 ) == V_58 &&
F_81 ( & V_54 -> V_134 ) )
return true ;
if ( ( V_245 -> V_122 & V_123 ) && ! V_54 -> V_257 )
return true ;
if ( F_81 ( & V_54 -> V_134 ) && ! F_263 ( V_50 , V_54 ) )
return true ;
if ( ! V_50 -> V_267 || ! F_248 ( V_54 ) )
return false ;
if ( F_260 ( V_50 , V_54 , V_245 ) )
return true ;
return false ;
}
static void F_340 ( struct V_49 * V_50 , struct V_53 * V_54 )
{
enum V_6 V_340 = F_60 ( V_50 -> V_264 ) ;
F_91 ( V_50 , V_54 , L_32 ) ;
F_254 ( V_50 , 1 ) ;
if ( V_340 != F_60 ( V_54 ) )
V_54 -> V_3 -> V_155 = 0 ;
F_21 ( ! F_209 ( V_54 ) ) ;
F_203 ( V_50 , V_54 , 1 ) ;
V_54 -> V_110 = 0 ;
F_246 ( V_54 ) ;
}
static void
F_341 ( struct V_49 * V_50 , struct V_53 * V_54 ,
struct V_112 * V_245 )
{
struct V_62 * V_68 = F_297 ( V_245 ) ;
V_50 -> V_256 ++ ;
if ( V_245 -> V_122 & V_123 )
V_54 -> V_257 ++ ;
F_331 ( V_50 , V_54 , V_68 ) ;
F_333 ( V_50 , V_54 , V_245 ) ;
F_336 ( V_50 , V_54 , V_68 ) ;
V_54 -> V_331 = F_98 ( V_245 ) + F_226 ( V_245 ) ;
if ( V_54 == V_50 -> V_264 ) {
if ( F_248 ( V_54 ) ) {
if ( F_342 ( V_245 ) > V_341 ||
V_50 -> V_72 > 1 ) {
F_239 ( V_50 , V_54 ) ;
F_242 ( V_54 ) ;
F_343 ( V_50 -> V_67 ) ;
} else {
F_17 ( V_54 -> V_3 ) ;
F_296 ( V_54 ) ;
}
}
} else if ( F_339 ( V_50 , V_54 , V_245 ) ) {
F_340 ( V_50 , V_54 ) ;
F_343 ( V_50 -> V_67 ) ;
}
}
static void F_344 ( struct V_253 * V_47 , struct V_112 * V_245 )
{
struct V_49 * V_50 = V_47 -> V_70 -> V_71 ;
struct V_53 * V_54 = F_215 ( V_245 ) ;
F_91 ( V_50 , V_54 , L_33 ) ;
F_306 ( V_54 , F_297 ( V_245 ) ) ;
V_245 -> V_263 = F_90 () + V_50 -> V_342 [ F_97 ( V_245 ) ] ;
F_345 ( & V_245 -> V_255 , & V_54 -> V_279 ) ;
F_217 ( V_245 ) ;
F_40 ( F_220 ( V_245 ) , V_50 -> V_247 ,
V_245 -> V_122 ) ;
F_341 ( V_50 , V_54 , V_245 ) ;
}
static void F_346 ( struct V_49 * V_50 )
{
struct V_53 * V_54 = V_50 -> V_264 ;
if ( V_50 -> V_254 > V_50 -> V_343 )
V_50 -> V_343 = V_50 -> V_254 ;
if ( V_50 -> V_52 == 1 )
return;
if ( V_50 -> V_256 <= V_344 &&
V_50 -> V_254 <= V_344 )
return;
if ( V_54 && F_62 ( V_54 ) &&
V_54 -> V_273 + V_54 -> V_19 [ 0 ] + V_54 -> V_19 [ 1 ] <
V_344 && V_50 -> V_254 < V_344 )
return;
if ( V_50 -> V_345 ++ < 50 )
return;
if ( V_50 -> V_343 >= V_344 )
V_50 -> V_52 = 1 ;
else
V_50 -> V_52 = 0 ;
}
static bool F_347 ( struct V_49 * V_50 , struct V_53 * V_54 )
{
struct V_62 * V_68 = V_50 -> V_267 ;
T_2 V_12 = F_90 () ;
if ( ! F_81 ( & V_54 -> V_134 ) )
return false ;
if ( V_54 -> V_3 -> V_135 > 1 )
return false ;
if ( F_265 ( V_50 , & V_54 -> V_3 -> V_171 , true ) )
return false ;
if ( F_92 ( V_54 ) )
return true ;
if ( V_68 && F_268 ( V_68 -> V_171 . V_275 )
&& ( V_54 -> V_110 - V_12 < V_68 -> V_171 . V_276 ) )
return true ;
if ( V_54 -> V_110 - V_12 <= F_128 ( 1 ) )
return true ;
return false ;
}
static void F_348 ( struct V_253 * V_47 , struct V_112 * V_245 )
{
struct V_53 * V_54 = F_215 ( V_245 ) ;
struct V_49 * V_50 = V_54 -> V_50 ;
const int V_74 = F_97 ( V_245 ) ;
T_2 V_12 = F_90 () ;
F_91 ( V_50 , V_54 , L_34 , F_334 ( V_245 ) ) ;
F_346 ( V_50 ) ;
F_76 ( ! V_50 -> V_254 ) ;
F_76 ( ! V_54 -> V_273 ) ;
V_50 -> V_254 -- ;
V_54 -> V_273 -- ;
( F_220 ( V_245 ) ) -> V_273 -- ;
F_46 ( V_54 -> V_3 , F_349 ( V_245 ) ,
F_350 ( V_245 ) , V_245 -> V_122 ) ;
V_50 -> V_278 [ F_61 ( V_54 ) ] -- ;
if ( V_74 ) {
struct V_1 * V_89 ;
F_297 ( V_245 ) -> V_171 . V_172 = V_12 ;
if ( F_209 ( V_54 ) )
V_89 = V_54 -> V_235 ;
else
V_89 = F_1 ( V_54 -> V_3 , F_57 ( V_54 ) ,
F_60 ( V_54 ) ) ;
V_89 -> V_171 . V_172 = V_12 ;
if ( ! F_351 ( V_245 -> V_41 +
F_352 ( V_50 -> V_342 [ 1 ] ) ,
V_346 ) )
V_50 -> V_305 = V_12 ;
}
#ifdef F_332
V_54 -> V_3 -> V_171 . V_172 = V_12 ;
#endif
if ( V_50 -> V_264 == V_54 ) {
const bool V_347 = F_81 ( & V_54 -> V_134 ) ;
if ( F_93 ( V_54 ) ) {
F_89 ( V_50 , V_54 ) ;
F_353 ( V_54 ) ;
}
if ( F_347 ( V_50 , V_54 ) ) {
T_2 V_348 = V_50 -> V_51 ;
if ( ! V_50 -> V_51 )
V_348 = V_50 -> V_272 ;
V_54 -> V_110 = V_12 + V_348 ;
F_354 ( V_54 ) ;
F_91 ( V_50 , V_54 , L_35 ) ;
}
if ( F_92 ( V_54 ) || F_58 ( V_54 ) )
F_254 ( V_50 , 1 ) ;
else if ( V_74 && V_347 &&
! F_262 ( V_50 , V_54 ) ) {
F_266 ( V_50 ) ;
}
}
if ( ! V_50 -> V_254 )
F_71 ( V_50 ) ;
}
static void F_355 ( struct V_53 * V_54 , unsigned int V_38 )
{
if ( ! ( V_38 & V_123 ) ) {
V_54 -> V_310 = V_54 -> V_316 ;
V_54 -> V_81 = V_54 -> V_243 ;
} else {
if ( F_58 ( V_54 ) )
V_54 -> V_310 = V_314 ;
if ( V_54 -> V_81 > V_320 )
V_54 -> V_81 = V_320 ;
}
}
static inline int F_356 ( struct V_53 * V_54 )
{
if ( F_248 ( V_54 ) && ! F_357 ( V_54 ) ) {
F_358 ( V_54 ) ;
return V_349 ;
}
return V_350 ;
}
static int F_359 ( struct V_253 * V_47 , unsigned int V_38 )
{
struct V_49 * V_50 = V_47 -> V_70 -> V_71 ;
struct V_249 * V_250 = V_251 ;
struct V_62 * V_68 ;
struct V_53 * V_54 ;
V_68 = F_66 ( V_50 , V_250 -> V_65 ) ;
if ( ! V_68 )
return V_350 ;
V_54 = F_68 ( V_68 , F_222 ( V_38 ) ) ;
if ( V_54 ) {
F_306 ( V_54 , V_68 ) ;
F_355 ( V_54 , V_38 ) ;
return F_356 ( V_54 ) ;
}
return V_350 ;
}
static void F_360 ( struct V_112 * V_245 )
{
struct V_53 * V_54 = F_215 ( V_245 ) ;
if ( V_54 ) {
const int V_351 = F_361 ( V_245 ) ;
F_21 ( ! V_54 -> V_284 [ V_351 ] ) ;
V_54 -> V_284 [ V_351 ] -- ;
F_38 ( F_220 ( V_245 ) ) ;
V_245 -> V_352 . V_353 [ 0 ] = NULL ;
V_245 -> V_352 . V_353 [ 1 ] = NULL ;
F_151 ( V_54 ) ;
}
}
static struct V_53 *
F_362 ( struct V_49 * V_50 , struct V_62 * V_68 ,
struct V_53 * V_54 )
{
F_91 ( V_50 , V_54 , L_36 , V_54 -> V_231 ) ;
F_69 ( V_68 , V_54 -> V_231 , 1 ) ;
F_363 ( V_54 -> V_231 ) ;
F_151 ( V_54 ) ;
return F_68 ( V_68 , 1 ) ;
}
static struct V_53 *
F_364 ( struct V_62 * V_68 , struct V_53 * V_54 )
{
if ( F_279 ( V_54 ) == 1 ) {
V_54 -> V_317 = V_251 -> V_317 ;
F_365 ( V_54 ) ;
F_366 ( V_54 ) ;
return V_54 ;
}
F_69 ( V_68 , NULL , 1 ) ;
F_301 ( V_54 ) ;
F_151 ( V_54 ) ;
return NULL ;
}
static int
F_367 ( struct V_253 * V_47 , struct V_112 * V_245 , struct V_248 * V_248 ,
T_5 V_354 )
{
struct V_49 * V_50 = V_47 -> V_70 -> V_71 ;
struct V_62 * V_68 = F_65 ( V_245 -> V_352 . V_64 ) ;
const int V_351 = F_361 ( V_245 ) ;
const bool V_69 = F_97 ( V_245 ) ;
struct V_53 * V_54 ;
F_176 ( V_47 -> V_48 ) ;
F_314 ( V_68 , V_248 ) ;
F_321 ( V_68 , V_248 ) ;
V_295:
V_54 = F_68 ( V_68 , V_69 ) ;
if ( ! V_54 || V_54 == & V_50 -> V_321 ) {
if ( V_54 )
F_151 ( V_54 ) ;
V_54 = F_315 ( V_50 , V_69 , V_68 , V_248 ) ;
F_69 ( V_68 , V_54 , V_69 ) ;
} else {
if ( F_250 ( V_54 ) && F_368 ( V_54 ) ) {
F_91 ( V_50 , V_54 , L_37 ) ;
V_54 = F_364 ( V_68 , V_54 ) ;
if ( ! V_54 )
goto V_295;
}
if ( V_54 -> V_231 )
V_54 = F_362 ( V_50 , V_68 , V_54 ) ;
}
V_54 -> V_284 [ V_351 ] ++ ;
V_54 -> V_287 ++ ;
F_36 ( V_54 -> V_3 ) ;
V_245 -> V_352 . V_353 [ 0 ] = V_54 ;
V_245 -> V_352 . V_353 [ 1 ] = V_54 -> V_3 ;
F_178 ( V_47 -> V_48 ) ;
return 0 ;
}
static void F_369 ( struct V_355 * V_356 )
{
struct V_49 * V_50 =
F_25 ( V_356 , struct V_49 , V_73 ) ;
struct V_253 * V_47 = V_50 -> V_67 ;
F_176 ( V_47 -> V_48 ) ;
F_343 ( V_50 -> V_67 ) ;
F_178 ( V_47 -> V_48 ) ;
}
static enum V_357 F_370 ( struct V_358 * V_359 )
{
struct V_49 * V_50 = F_25 ( V_359 , struct V_49 ,
V_265 ) ;
struct V_53 * V_54 ;
unsigned long V_360 ;
int V_266 = 1 ;
F_72 ( V_50 , L_38 ) ;
F_371 ( V_50 -> V_67 -> V_48 , V_360 ) ;
V_54 = V_50 -> V_264 ;
if ( V_54 ) {
V_266 = 0 ;
if ( F_287 ( V_54 ) )
goto V_361;
if ( F_92 ( V_54 ) )
goto V_296;
if ( ! V_50 -> V_72 )
goto V_362;
if ( ! F_81 ( & V_54 -> V_134 ) )
goto V_361;
F_289 ( V_54 ) ;
}
V_296:
F_254 ( V_50 , V_266 ) ;
V_361:
F_71 ( V_50 ) ;
V_362:
F_372 ( V_50 -> V_67 -> V_48 , V_360 ) ;
return V_363 ;
}
static void F_373 ( struct V_49 * V_50 )
{
F_374 ( & V_50 -> V_265 ) ;
F_375 ( & V_50 -> V_73 ) ;
}
static void F_376 ( struct V_364 * V_365 )
{
struct V_49 * V_50 = V_365 -> V_71 ;
struct V_253 * V_47 = V_50 -> V_67 ;
F_373 ( V_50 ) ;
F_176 ( V_47 -> V_48 ) ;
if ( V_50 -> V_264 )
F_247 ( V_50 , V_50 -> V_264 , 0 ) ;
F_178 ( V_47 -> V_48 ) ;
F_373 ( V_50 ) ;
#ifdef F_332
F_377 ( V_47 , & V_31 ) ;
#else
F_144 ( V_50 -> V_226 ) ;
#endif
F_144 ( V_50 ) ;
}
static int F_378 ( struct V_253 * V_47 , struct V_366 * V_365 )
{
struct V_49 * V_50 ;
struct V_29 * V_30 V_367 ;
int V_168 , V_203 ;
struct V_364 * V_368 ;
V_368 = F_379 ( V_47 , V_365 ) ;
if ( ! V_368 )
return - V_175 ;
V_50 = F_148 ( sizeof( * V_50 ) , V_369 , V_47 -> V_136 ) ;
if ( ! V_50 ) {
F_380 ( & V_368 -> V_370 ) ;
return - V_175 ;
}
V_368 -> V_71 = V_50 ;
V_50 -> V_67 = V_47 ;
F_176 ( V_47 -> V_48 ) ;
V_47 -> V_70 = V_368 ;
F_178 ( V_47 -> V_48 ) ;
V_50 -> V_154 = V_170 ;
#ifdef F_332
V_203 = F_381 ( V_47 , & V_31 ) ;
if ( V_203 )
goto V_371;
V_50 -> V_226 = F_29 ( V_47 -> V_372 ) ;
#else
V_203 = - V_175 ;
V_50 -> V_226 = F_148 ( sizeof( * V_50 -> V_226 ) ,
V_369 , V_50 -> V_67 -> V_136 ) ;
if ( ! V_50 -> V_226 )
goto V_371;
F_130 ( V_50 -> V_226 ) ;
V_50 -> V_226 -> V_144 = 2 * V_179 ;
V_50 -> V_226 -> V_146 = 2 * V_179 ;
#endif
for ( V_168 = 0 ; V_168 < V_373 ; V_168 ++ )
V_50 -> V_242 [ V_168 ] = V_374 ;
F_317 ( V_50 , & V_50 -> V_321 , 1 , 0 ) ;
V_50 -> V_321 . V_287 ++ ;
F_176 ( V_47 -> V_48 ) ;
F_157 ( & V_50 -> V_321 , V_50 -> V_226 ) ;
F_38 ( V_50 -> V_226 ) ;
F_178 ( V_47 -> V_48 ) ;
F_382 ( & V_50 -> V_265 , V_375 ,
V_277 ) ;
V_50 -> V_265 . V_376 = F_370 ;
F_383 ( & V_50 -> V_73 , F_369 ) ;
V_50 -> V_303 = V_303 ;
V_50 -> V_342 [ 0 ] = V_342 [ 0 ] ;
V_50 -> V_342 [ 1 ] = V_342 [ 1 ] ;
V_50 -> V_124 = V_124 ;
V_50 -> V_125 = V_125 ;
V_50 -> V_77 [ 0 ] = V_377 ;
V_50 -> V_77 [ 1 ] = V_378 ;
V_50 -> V_101 = V_101 ;
V_50 -> V_281 = V_281 ;
V_50 -> V_51 = V_51 ;
V_50 -> V_272 = V_272 ;
V_50 -> V_102 = 1 ;
V_50 -> V_52 = - 1 ;
V_50 -> V_305 = F_90 () - V_234 ;
return 0 ;
V_371:
F_144 ( V_50 ) ;
F_380 ( & V_368 -> V_370 ) ;
return V_203 ;
}
static void F_384 ( struct V_253 * V_47 )
{
struct V_364 * V_365 = V_47 -> V_70 ;
struct V_49 * V_50 = V_365 -> V_71 ;
if ( F_264 ( V_47 ) )
V_50 -> V_51 = 0 ;
F_385 ( V_47 ) ;
}
static T_6
F_386 ( unsigned int V_379 , char * V_380 )
{
return sprintf ( V_380 , L_6 , V_379 ) ;
}
static void
F_387 ( unsigned int * V_379 , const char * V_380 )
{
char * V_228 = ( char * ) V_380 ;
* V_379 = F_388 ( V_228 , & V_228 , 10 ) ;
}
static int T_10 F_389 ( void )
{
int V_203 ;
#ifdef F_332
V_203 = F_390 ( & V_31 ) ;
if ( V_203 )
return V_203 ;
#else
V_272 = 0 ;
#endif
V_203 = - V_175 ;
V_309 = F_391 ( V_53 , 0 ) ;
if ( ! V_309 )
goto V_381;
V_203 = F_392 ( & V_382 ) ;
if ( V_203 )
goto V_383;
return 0 ;
V_383:
F_393 ( V_309 ) ;
V_381:
#ifdef F_332
F_394 ( & V_31 ) ;
#endif
return V_203 ;
}
static void T_11 F_395 ( void )
{
#ifdef F_332
F_394 ( & V_31 ) ;
#endif
F_396 ( & V_382 ) ;
F_393 ( V_309 ) ;
}
