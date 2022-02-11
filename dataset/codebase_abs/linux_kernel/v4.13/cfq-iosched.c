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
struct V_2 * V_3 ;
if ( V_89 -> V_90 ) {
V_3 = F_81 ( V_89 -> V_90 ) ;
V_89 -> V_86 = F_79 ( V_89 -> V_86 ,
V_3 -> V_87 ) ;
}
}
static inline unsigned F_82 ( struct V_49 * V_50 ,
struct V_2 * V_3 , bool V_91 )
{
unsigned V_92 , V_93 ;
unsigned V_94 = V_95 - 1 ;
unsigned V_96 = V_95 / 2 ;
unsigned V_97 = F_63 ( V_91 , V_50 , V_3 ) ;
V_92 = F_83 ( V_3 -> V_98 [ V_91 ] , V_97 ) ;
V_93 = F_84 ( V_3 -> V_98 [ V_91 ] , V_97 ) ;
V_3 -> V_98 [ V_91 ] = ( V_94 * V_93 + V_92 + V_96 ) /
V_95 ;
return V_3 -> V_98 [ V_91 ] ;
}
static inline T_2
F_85 ( struct V_49 * V_50 , struct V_2 * V_3 )
{
return V_50 -> V_99 * V_3 -> V_83 >> V_85 ;
}
static inline T_2
F_86 ( struct V_49 * V_50 , struct V_53 * V_54 )
{
T_2 V_78 = F_77 ( V_50 , V_54 ) ;
if ( V_50 -> V_100 ) {
unsigned V_101 = F_82 ( V_50 , V_54 -> V_3 ,
F_59 ( V_54 ) ) ;
T_2 V_102 = V_50 -> V_77 [ 1 ] ;
T_2 V_103 = V_102 * V_101 ;
T_2 V_104 = F_85 ( V_50 , V_54 -> V_3 ) ;
if ( V_103 > V_104 ) {
T_2 V_105 = 2 * V_50 -> V_51 ;
T_2 V_106 ;
V_106 = F_87 ( V_105 * V_78 , V_102 ) ;
V_106 = F_83 ( V_78 , V_106 ) ;
V_78 = F_87 ( V_78 * V_104 , V_103 ) ;
V_78 = F_84 ( V_78 , V_106 ) ;
}
}
return V_78 ;
}
static inline void
F_88 ( struct V_49 * V_50 , struct V_53 * V_54 )
{
T_2 V_78 = F_86 ( V_50 , V_54 ) ;
T_2 V_12 = F_89 () ;
V_54 -> V_107 = V_12 ;
V_54 -> V_108 = V_12 + V_78 ;
V_54 -> V_109 = V_78 ;
F_90 ( V_50 , V_54 , L_2 , V_54 -> V_108 - V_12 ) ;
}
static inline bool F_91 ( struct V_53 * V_54 )
{
if ( F_92 ( V_54 ) )
return false ;
if ( F_89 () < V_54 -> V_108 )
return false ;
return true ;
}
static struct V_110 *
F_93 ( struct V_49 * V_50 , struct V_110 * V_111 , struct V_110 * V_112 , T_4 V_113 )
{
T_4 V_114 , V_115 , V_116 = 0 , V_117 = 0 ;
unsigned long V_118 ;
#define F_94 0x01
#define F_95 0x02
unsigned V_119 = 0 ;
if ( V_111 == NULL || V_111 == V_112 )
return V_112 ;
if ( V_112 == NULL )
return V_111 ;
if ( F_96 ( V_111 ) != F_96 ( V_112 ) )
return F_96 ( V_111 ) ? V_111 : V_112 ;
if ( ( V_111 -> V_120 ^ V_112 -> V_120 ) & V_121 )
return V_111 -> V_120 & V_121 ? V_111 : V_112 ;
V_114 = F_97 ( V_111 ) ;
V_115 = F_97 ( V_112 ) ;
V_118 = V_50 -> V_122 * 2 ;
if ( V_114 >= V_113 )
V_116 = V_114 - V_113 ;
else if ( V_114 + V_118 >= V_113 )
V_116 = ( V_113 - V_114 ) * V_50 -> V_123 ;
else
V_119 |= F_94 ;
if ( V_115 >= V_113 )
V_117 = V_115 - V_113 ;
else if ( V_115 + V_118 >= V_113 )
V_117 = ( V_113 - V_115 ) * V_50 -> V_123 ;
else
V_119 |= F_95 ;
switch ( V_119 ) {
case 0 :
if ( V_116 < V_117 )
return V_111 ;
else if ( V_117 < V_116 )
return V_112 ;
else {
if ( V_114 >= V_115 )
return V_111 ;
else
return V_112 ;
}
case F_95 :
return V_111 ;
case F_94 :
return V_112 ;
case ( F_94 | F_95 ) :
default:
if ( V_114 <= V_115 )
return V_111 ;
else
return V_112 ;
}
}
static struct V_53 * F_98 ( struct V_1 * V_124 )
{
if ( ! V_124 -> V_61 )
return NULL ;
if ( ! V_124 -> V_90 )
V_124 -> V_90 = F_99 ( & V_124 -> V_125 ) ;
if ( V_124 -> V_90 )
return F_100 ( V_124 -> V_90 , struct V_53 , V_126 ) ;
return NULL ;
}
static struct V_2 * F_101 ( struct V_1 * V_124 )
{
if ( ! V_124 -> V_90 )
V_124 -> V_90 = F_99 ( & V_124 -> V_125 ) ;
if ( V_124 -> V_90 )
return F_81 ( V_124 -> V_90 ) ;
return NULL ;
}
static void F_102 ( struct V_126 * V_127 , struct V_128 * V_124 )
{
F_103 ( V_127 , V_124 ) ;
F_104 ( V_127 ) ;
}
static void F_105 ( struct V_126 * V_127 , struct V_1 * V_124 )
{
if ( V_124 -> V_90 == V_127 )
V_124 -> V_90 = NULL ;
F_102 ( V_127 , & V_124 -> V_125 ) ;
-- V_124 -> V_61 ;
}
static struct V_110 *
F_106 ( struct V_49 * V_50 , struct V_53 * V_54 ,
struct V_110 * V_113 )
{
struct V_126 * V_129 = F_107 ( & V_113 -> V_126 ) ;
struct V_126 * V_130 = F_108 ( & V_113 -> V_126 ) ;
struct V_110 * V_131 = NULL , * V_132 = NULL ;
F_21 ( F_109 ( & V_113 -> V_126 ) ) ;
if ( V_130 )
V_132 = F_110 ( V_130 ) ;
if ( V_129 )
V_131 = F_110 ( V_129 ) ;
else {
V_129 = F_99 ( & V_54 -> V_133 ) ;
if ( V_129 && V_129 != & V_113 -> V_126 )
V_131 = F_110 ( V_129 ) ;
}
return F_93 ( V_50 , V_131 , V_132 , F_97 ( V_113 ) ) ;
}
static T_2 F_111 ( struct V_49 * V_50 ,
struct V_53 * V_54 )
{
return ( V_54 -> V_3 -> V_134 - 1 ) * ( F_74 ( V_50 , 1 , 0 ) -
F_74 ( V_50 , F_61 ( V_54 ) , V_54 -> V_81 ) ) ;
}
static inline T_3
F_112 ( struct V_1 * V_89 , struct V_2 * V_3 )
{
return V_3 -> V_87 - V_89 -> V_86 ;
}
static void
F_113 ( struct V_1 * V_89 , struct V_2 * V_3 )
{
struct V_126 * * V_135 = & V_89 -> V_125 . V_126 ;
struct V_126 * V_34 = NULL ;
struct V_2 * V_136 ;
T_3 V_137 = F_112 ( V_89 , V_3 ) ;
int V_90 = 1 ;
while ( * V_135 != NULL ) {
V_34 = * V_135 ;
V_136 = F_81 ( V_34 ) ;
if ( V_137 < F_112 ( V_89 , V_136 ) )
V_135 = & V_34 -> V_138 ;
else {
V_135 = & V_34 -> V_139 ;
V_90 = 0 ;
}
}
if ( V_90 )
V_89 -> V_90 = & V_3 -> V_126 ;
F_114 ( & V_3 -> V_126 , V_34 , V_135 ) ;
F_115 ( & V_3 -> V_126 , & V_89 -> V_125 ) ;
}
static void
F_116 ( struct V_2 * V_3 )
{
if ( V_3 -> V_140 ) {
V_3 -> V_141 = V_3 -> V_140 ;
V_3 -> V_140 = 0 ;
}
}
static void
F_117 ( struct V_2 * V_3 )
{
F_21 ( ! F_109 ( & V_3 -> V_126 ) ) ;
if ( V_3 -> V_142 ) {
V_3 -> V_143 = V_3 -> V_142 ;
V_3 -> V_142 = 0 ;
}
}
static void
F_118 ( struct V_1 * V_89 , struct V_2 * V_3 )
{
unsigned int V_144 = 1 << V_85 ;
struct V_2 * V_145 = V_3 ;
struct V_2 * V_34 ;
bool V_146 ;
F_21 ( ! F_109 ( & V_3 -> V_126 ) ) ;
F_117 ( V_3 ) ;
F_113 ( V_89 , V_3 ) ;
V_146 = ! V_145 -> V_147 ++ ;
V_145 -> V_148 += V_145 -> V_143 ;
V_144 = V_144 * V_145 -> V_143 / V_145 -> V_148 ;
while ( ( V_34 = F_33 ( V_145 ) ) ) {
if ( V_146 ) {
F_116 ( V_145 ) ;
V_146 = ! V_34 -> V_147 ++ ;
V_34 -> V_148 += V_145 -> V_141 ;
}
V_144 = V_144 * V_145 -> V_141 / V_34 -> V_148 ;
V_145 = V_34 ;
}
V_3 -> V_83 = F_119 ( unsigned , V_144 , 1 ) ;
}
static inline T_2 F_120 ( struct V_49 * V_50 )
{
if ( ! F_56 ( V_50 ) )
return V_149 ;
else
return V_150 ;
}
static void
F_121 ( struct V_49 * V_50 , struct V_2 * V_3 )
{
struct V_1 * V_89 = & V_50 -> V_151 ;
struct V_2 * V_136 ;
struct V_126 * V_127 ;
V_3 -> V_134 ++ ;
if ( ! F_109 ( & V_3 -> V_126 ) )
return;
V_127 = F_122 ( & V_89 -> V_125 ) ;
if ( V_127 ) {
V_136 = F_81 ( V_127 ) ;
V_3 -> V_87 = V_136 -> V_87 +
F_120 ( V_50 ) ;
} else
V_3 -> V_87 = V_89 -> V_86 ;
F_118 ( V_89 , V_3 ) ;
}
static void
F_123 ( struct V_1 * V_89 , struct V_2 * V_3 )
{
struct V_2 * V_145 = V_3 ;
bool V_146 ;
V_146 = ! -- V_145 -> V_147 ;
V_145 -> V_148 -= V_145 -> V_143 ;
while ( V_146 ) {
struct V_2 * V_34 = F_33 ( V_145 ) ;
F_124 ( V_145 -> V_148 ) ;
V_145 -> V_83 = 0 ;
if ( ! V_34 )
break;
V_146 = ! -- V_34 -> V_147 ;
V_34 -> V_148 -= V_145 -> V_141 ;
V_145 = V_34 ;
}
if ( ! F_109 ( & V_3 -> V_126 ) )
F_105 ( & V_3 -> V_126 , V_89 ) ;
}
static void
F_125 ( struct V_49 * V_50 , struct V_2 * V_3 )
{
struct V_1 * V_89 = & V_50 -> V_151 ;
F_21 ( V_3 -> V_134 < 1 ) ;
V_3 -> V_134 -- ;
if ( V_3 -> V_134 )
return;
F_126 ( V_50 , V_3 , L_3 ) ;
F_123 ( V_89 , V_3 ) ;
V_3 -> V_152 = 0 ;
F_13 ( V_3 ) ;
}
static inline T_2 F_127 ( struct V_53 * V_54 ,
T_2 * V_39 )
{
T_2 V_153 ;
T_2 V_12 = F_89 () ;
if ( ! V_54 -> V_107 || V_54 -> V_107 == V_12 ) {
V_153 = F_119 ( T_2 , ( V_12 - V_54 -> V_154 ) ,
F_128 ( 1 ) ) ;
} else {
V_153 = V_12 - V_54 -> V_107 ;
if ( V_153 > V_54 -> V_109 ) {
* V_39 = V_153 - V_54 -> V_109 ;
V_153 = V_54 -> V_109 ;
}
if ( V_54 -> V_107 > V_54 -> V_154 )
* V_39 += V_54 -> V_107 -
V_54 -> V_154 ;
}
return V_153 ;
}
static void F_129 ( struct V_49 * V_50 , struct V_2 * V_3 ,
struct V_53 * V_54 )
{
struct V_1 * V_89 = & V_50 -> V_151 ;
T_2 V_155 , V_82 , V_156 = 0 ;
int V_157 = V_3 -> V_134 - F_64 ( V_50 , V_3 )
- V_3 -> V_8 . V_61 ;
unsigned int V_144 ;
T_2 V_12 = F_89 () ;
F_21 ( V_157 < 0 ) ;
V_155 = V_82 = F_127 ( V_54 , & V_156 ) ;
if ( F_56 ( V_50 ) )
V_82 = V_54 -> V_158 ;
else if ( ! F_61 ( V_54 ) && ! V_157 )
V_82 = V_54 -> V_109 ;
V_144 = V_3 -> V_83 ;
F_123 ( V_89 , V_3 ) ;
V_3 -> V_87 += F_78 ( V_82 , V_144 ) ;
F_118 ( V_89 , V_3 ) ;
if ( V_50 -> V_159 > V_12 ) {
V_3 -> V_152 = V_50 -> V_159 - V_12 ;
V_3 -> V_160 = V_50 -> V_161 ;
V_3 -> V_162 = V_50 -> V_163 ;
} else
V_3 -> V_152 = 0 ;
F_126 ( V_50 , V_3 , L_4 , V_3 -> V_87 ,
V_89 -> V_86 ) ;
F_90 ( V_54 -> V_50 , V_54 ,
L_5 ,
V_155 , V_54 -> V_158 , V_82 ,
F_56 ( V_50 ) , V_54 -> V_164 ) ;
F_42 ( V_3 , V_155 , V_156 ) ;
F_14 ( V_3 ) ;
}
static void F_130 ( struct V_2 * V_3 )
{
struct V_1 * V_89 ;
int V_165 , V_166 ;
F_131 ( V_3 , V_165 , V_166 , V_89 )
* V_89 = V_167 ;
F_104 ( & V_3 -> V_126 ) ;
V_3 -> V_168 . V_169 = F_89 () ;
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
static int F_135 ( struct V_10 * V_11 , T_5 V_170 )
{
if ( F_136 ( & V_11 -> V_40 , V_170 ) ||
F_136 ( & V_11 -> V_43 , V_170 ) ||
F_136 ( & V_11 -> V_44 , V_170 ) ||
F_136 ( & V_11 -> V_19 , V_170 ) ||
F_137 ( & V_11 -> time , V_170 ) )
goto V_171;
#ifdef F_43
if ( F_137 ( & V_11 -> V_39 , V_170 ) ||
F_137 ( & V_11 -> V_22 , V_170 ) ||
F_137 ( & V_11 -> V_23 , V_170 ) ||
F_137 ( & V_11 -> V_18 , V_170 ) ||
F_137 ( & V_11 -> V_14 , V_170 ) ||
F_137 ( & V_11 -> V_21 , V_170 ) ||
F_137 ( & V_11 -> V_17 , V_170 ) )
goto V_171;
#endif
return 0 ;
V_171:
F_132 ( V_11 ) ;
return - V_172 ;
}
static struct V_27 * F_138 ( T_5 V_170 )
{
struct V_26 * V_173 ;
V_173 = F_139 ( sizeof( * V_173 ) , V_170 ) ;
if ( ! V_173 )
return NULL ;
return & V_173 -> V_28 ;
}
static void F_140 ( struct V_27 * V_28 )
{
struct V_26 * V_173 = F_26 ( V_28 ) ;
unsigned int V_141 = F_141 ( V_174 ) ?
V_175 : V_176 ;
if ( F_142 ( V_28 ) == & V_177 )
V_141 *= 2 ;
V_173 -> V_141 = V_141 ;
V_173 -> V_143 = V_141 ;
}
static void F_143 ( struct V_27 * V_28 )
{
F_144 ( F_26 ( V_28 ) ) ;
}
static void F_145 ( struct V_27 * V_28 )
{
struct V_32 * V_32 = F_142 ( V_28 ) ;
bool V_178 = F_141 ( V_174 ) ;
unsigned int V_141 = V_178 ? V_175 : V_176 ;
if ( V_32 == & V_177 )
V_141 *= 2 ;
F_124 ( F_146 ( & V_32 -> V_36 , V_141 , V_178 , true , false ) ) ;
F_124 ( F_146 ( & V_32 -> V_36 , V_141 , V_178 , true , true ) ) ;
}
static struct V_24 * F_147 ( T_5 V_170 , int V_135 )
{
struct V_2 * V_3 ;
V_3 = F_148 ( sizeof( * V_3 ) , V_170 , V_135 ) ;
if ( ! V_3 )
return NULL ;
F_130 ( V_3 ) ;
if ( F_135 ( & V_3 -> V_11 , V_170 ) ) {
F_144 ( V_3 ) ;
return NULL ;
}
return & V_3 -> V_25 ;
}
static void F_149 ( struct V_24 * V_25 )
{
struct V_2 * V_3 = F_24 ( V_25 ) ;
struct V_26 * V_173 = F_31 ( V_25 -> V_30 -> V_32 ) ;
V_3 -> V_141 = V_173 -> V_141 ;
V_3 -> V_143 = V_173 -> V_143 ;
}
static void F_150 ( struct V_24 * V_25 )
{
struct V_2 * V_3 = F_24 ( V_25 ) ;
int V_165 ;
for ( V_165 = 0 ; V_165 < V_80 ; V_165 ++ ) {
if ( V_3 -> V_179 [ 0 ] [ V_165 ] )
F_151 ( V_3 -> V_179 [ 0 ] [ V_165 ] ) ;
if ( V_3 -> V_179 [ 1 ] [ V_165 ] )
F_151 ( V_3 -> V_179 [ 1 ] [ V_165 ] ) ;
}
if ( V_3 -> V_180 )
F_151 ( V_3 -> V_180 ) ;
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
static T_2 F_158 ( struct V_181 * V_182 ,
struct V_24 * V_25 , int V_183 )
{
struct V_2 * V_3 = F_24 ( V_25 ) ;
if ( ! V_3 -> V_184 )
return 0 ;
return F_159 ( V_182 , V_25 , V_3 -> V_184 ) ;
}
static int F_160 ( struct V_181 * V_182 , void * V_185 )
{
F_161 ( V_182 , F_162 ( F_163 ( V_182 ) ) ,
F_158 , & V_31 ,
0 , false ) ;
return 0 ;
}
static T_2 F_164 ( struct V_181 * V_182 ,
struct V_24 * V_25 , int V_183 )
{
struct V_2 * V_3 = F_24 ( V_25 ) ;
if ( ! V_3 -> V_186 )
return 0 ;
return F_159 ( V_182 , V_25 , V_3 -> V_186 ) ;
}
static int F_165 ( struct V_181 * V_182 , void * V_185 )
{
F_161 ( V_182 , F_162 ( F_163 ( V_182 ) ) ,
F_164 , & V_31 ,
0 , false ) ;
return 0 ;
}
static int F_166 ( struct V_181 * V_182 , void * V_185 )
{
struct V_32 * V_32 = F_162 ( F_163 ( V_182 ) ) ;
struct V_26 * V_173 = F_31 ( V_32 ) ;
unsigned int V_187 = 0 ;
if ( V_173 )
V_187 = V_173 -> V_141 ;
F_167 ( V_182 , L_6 , V_187 ) ;
return 0 ;
}
static int F_168 ( struct V_181 * V_182 , void * V_185 )
{
struct V_32 * V_32 = F_162 ( F_163 ( V_182 ) ) ;
struct V_26 * V_173 = F_31 ( V_32 ) ;
unsigned int V_187 = 0 ;
if ( V_173 )
V_187 = V_173 -> V_143 ;
F_167 ( V_182 , L_6 , V_187 ) ;
return 0 ;
}
static T_6 F_169 ( struct V_188 * V_189 ,
char * V_190 , T_7 V_191 , T_8 V_183 ,
bool V_178 , bool V_192 )
{
unsigned int F_83 = V_178 ? V_193 : V_194 ;
unsigned int F_84 = V_178 ? V_195 : V_196 ;
struct V_32 * V_32 = F_162 ( F_170 ( V_189 ) ) ;
struct V_197 V_198 ;
struct V_2 * V_3 ;
struct V_26 * V_199 ;
int V_200 ;
T_2 V_185 ;
V_200 = F_171 ( V_32 , & V_31 , V_190 , & V_198 ) ;
if ( V_200 )
return V_200 ;
if ( sscanf ( V_198 . V_201 , L_7 , & V_185 ) == 1 ) {
V_200 = - V_202 ;
if ( ! V_185 && V_178 )
goto V_203;
} else if ( ! strcmp ( F_172 ( V_198 . V_201 ) , L_8 ) ) {
V_185 = 0 ;
} else {
V_200 = - V_204 ;
goto V_203;
}
V_3 = F_29 ( V_198 . V_30 ) ;
V_199 = F_31 ( V_32 ) ;
V_200 = - V_202 ;
if ( ! V_185 || ( V_185 >= F_83 && V_185 <= F_84 ) ) {
if ( ! V_192 ) {
V_3 -> V_184 = V_185 ;
V_3 -> V_140 = V_185 ? : V_199 -> V_141 ;
} else {
V_3 -> V_186 = V_185 ;
V_3 -> V_142 = V_185 ? : V_199 -> V_143 ;
}
V_200 = 0 ;
}
V_203:
F_173 ( & V_198 ) ;
return V_200 ? : V_191 ;
}
static T_6 F_174 ( struct V_188 * V_189 ,
char * V_190 , T_7 V_191 , T_8 V_183 )
{
return F_169 ( V_189 , V_190 , V_191 , V_183 , false , false ) ;
}
static T_6 F_175 ( struct V_188 * V_189 ,
char * V_190 , T_7 V_191 , T_8 V_183 )
{
return F_169 ( V_189 , V_190 , V_191 , V_183 , false , true ) ;
}
static int F_146 ( struct V_205 * V_36 , T_2 V_187 ,
bool V_178 , bool V_206 , bool V_192 )
{
unsigned int F_83 = V_178 ? V_193 : V_194 ;
unsigned int F_84 = V_178 ? V_195 : V_196 ;
struct V_32 * V_32 = F_162 ( V_36 ) ;
struct V_29 * V_30 ;
struct V_26 * V_199 ;
int V_200 = 0 ;
if ( V_187 < F_83 || V_187 > F_84 )
return - V_202 ;
F_176 ( & V_32 -> V_207 ) ;
V_199 = F_31 ( V_32 ) ;
if ( ! V_199 ) {
V_200 = - V_204 ;
goto V_208;
}
if ( ! V_192 )
V_199 -> V_141 = V_187 ;
else
V_199 -> V_143 = V_187 ;
F_177 (blkg, &blkcg->blkg_list, blkcg_node) {
struct V_2 * V_3 = F_29 ( V_30 ) ;
if ( ! V_3 )
continue;
if ( ! V_192 ) {
if ( V_206 )
V_3 -> V_184 = 0 ;
if ( ! V_3 -> V_184 )
V_3 -> V_140 = V_199 -> V_141 ;
} else {
if ( V_206 )
V_3 -> V_186 = 0 ;
if ( ! V_3 -> V_186 )
V_3 -> V_142 = V_199 -> V_143 ;
}
}
V_208:
F_178 ( & V_32 -> V_207 ) ;
return V_200 ;
}
static int F_179 ( struct V_205 * V_36 , struct V_209 * V_210 ,
T_2 V_187 )
{
return F_146 ( V_36 , V_187 , false , false , false ) ;
}
static int F_180 ( struct V_205 * V_36 ,
struct V_209 * V_210 , T_2 V_187 )
{
return F_146 ( V_36 , V_187 , false , false , true ) ;
}
static int F_181 ( struct V_181 * V_182 , void * V_185 )
{
F_161 ( V_182 , F_162 ( F_163 ( V_182 ) ) , V_211 ,
& V_31 , F_182 ( V_182 ) -> V_212 , false ) ;
return 0 ;
}
static int F_183 ( struct V_181 * V_182 , void * V_185 )
{
F_161 ( V_182 , F_162 ( F_163 ( V_182 ) ) , V_213 ,
& V_31 , F_182 ( V_182 ) -> V_212 , true ) ;
return 0 ;
}
static T_2 F_184 ( struct V_181 * V_182 ,
struct V_24 * V_25 , int V_183 )
{
T_2 V_214 = F_185 ( F_28 ( V_25 ) ,
& V_31 , V_183 ) ;
return F_159 ( V_182 , V_25 , V_214 ) ;
}
static T_2 F_186 ( struct V_181 * V_182 ,
struct V_24 * V_25 , int V_183 )
{
struct V_215 V_214 = F_187 ( F_28 ( V_25 ) ,
& V_31 , V_183 ) ;
return F_188 ( V_182 , V_25 , & V_214 ) ;
}
static int F_189 ( struct V_181 * V_182 , void * V_185 )
{
F_161 ( V_182 , F_162 ( F_163 ( V_182 ) ) ,
F_184 , & V_31 ,
F_182 ( V_182 ) -> V_212 , false ) ;
return 0 ;
}
static int F_190 ( struct V_181 * V_182 , void * V_185 )
{
F_161 ( V_182 , F_162 ( F_163 ( V_182 ) ) ,
F_186 , & V_31 ,
F_182 ( V_182 ) -> V_212 , true ) ;
return 0 ;
}
static T_2 F_191 ( struct V_181 * V_182 , struct V_24 * V_25 ,
int V_183 )
{
T_2 V_214 = F_15 ( & V_25 -> V_30 -> V_216 ) ;
return F_159 ( V_182 , V_25 , V_214 >> 9 ) ;
}
static int F_192 ( struct V_181 * V_182 , void * V_185 )
{
F_161 ( V_182 , F_162 ( F_163 ( V_182 ) ) ,
F_191 , & V_31 , 0 , false ) ;
return 0 ;
}
static T_2 F_193 ( struct V_181 * V_182 ,
struct V_24 * V_25 , int V_183 )
{
struct V_215 V_217 = F_187 ( V_25 -> V_30 , NULL ,
F_194 ( struct V_29 , V_216 ) ) ;
T_2 V_214 = F_195 ( & V_217 . V_218 [ V_219 ] ) +
F_195 ( & V_217 . V_218 [ V_220 ] ) ;
return F_159 ( V_182 , V_25 , V_214 >> 9 ) ;
}
static int F_196 ( struct V_181 * V_182 , void * V_185 )
{
F_161 ( V_182 , F_162 ( F_163 ( V_182 ) ) ,
F_193 , & V_31 , 0 ,
false ) ;
return 0 ;
}
static T_2 F_197 ( struct V_181 * V_182 ,
struct V_24 * V_25 , int V_183 )
{
struct V_2 * V_3 = F_24 ( V_25 ) ;
T_2 V_221 = F_198 ( & V_3 -> V_11 . V_23 ) ;
T_2 V_185 = 0 ;
if ( V_221 ) {
V_185 = F_198 ( & V_3 -> V_11 . V_22 ) ;
V_185 = F_87 ( V_185 , V_221 ) ;
}
F_159 ( V_182 , V_25 , V_185 ) ;
return 0 ;
}
static int F_199 ( struct V_181 * V_182 , void * V_185 )
{
F_161 ( V_182 , F_162 ( F_163 ( V_182 ) ) ,
F_197 , & V_31 ,
0 , false ) ;
return 0 ;
}
static int F_200 ( struct V_181 * V_182 , void * V_185 )
{
struct V_32 * V_32 = F_162 ( F_163 ( V_182 ) ) ;
struct V_26 * V_173 = F_31 ( V_32 ) ;
F_167 ( V_182 , L_9 , V_173 -> V_141 ) ;
F_161 ( V_182 , V_32 , F_158 ,
& V_31 , 0 , false ) ;
return 0 ;
}
static T_6 F_201 ( struct V_188 * V_189 ,
char * V_190 , T_7 V_191 , T_8 V_183 )
{
char * V_222 ;
int V_200 ;
T_2 V_185 ;
V_190 = F_172 ( V_190 ) ;
V_185 = F_202 ( V_190 , & V_222 , 0 ) ;
if ( * V_222 == '\0' || sscanf ( V_190 , L_10 , & V_185 ) == 1 ) {
V_200 = F_146 ( F_170 ( V_189 ) , V_185 , true , false , false ) ;
return V_200 ? : V_191 ;
}
return F_169 ( V_189 , V_190 , V_191 , V_183 , true , false ) ;
}
static struct V_2 * F_154 ( struct V_49 * V_50 ,
struct V_32 * V_32 )
{
return V_50 -> V_223 ;
}
static inline void
F_157 ( struct V_53 * V_54 , struct V_2 * V_3 ) {
V_54 -> V_3 = V_3 ;
}
static void F_203 ( struct V_49 * V_50 , struct V_53 * V_54 ,
bool V_224 )
{
struct V_126 * * V_225 , * V_34 ;
struct V_53 * V_226 ;
T_2 V_227 ;
struct V_1 * V_89 ;
int V_90 ;
int V_228 = 1 ;
T_2 V_12 = F_89 () ;
V_89 = F_1 ( V_54 -> V_3 , F_57 ( V_54 ) , F_60 ( V_54 ) ) ;
if ( F_58 ( V_54 ) ) {
V_227 = V_229 ;
V_34 = F_122 ( & V_89 -> V_125 ) ;
if ( V_34 && V_34 != & V_54 -> V_126 ) {
V_226 = F_100 ( V_34 , struct V_53 , V_126 ) ;
V_227 += V_226 -> V_227 ;
} else
V_227 += V_12 ;
} else if ( ! V_224 ) {
V_227 = F_111 ( V_50 , V_54 ) + V_12 ;
V_227 -= V_54 -> V_230 ;
V_54 -> V_230 = 0 ;
} else {
V_227 = - V_231 ;
V_226 = F_98 ( V_89 ) ;
V_227 += V_226 ? V_226 -> V_227 : V_12 ;
}
if ( ! F_109 ( & V_54 -> V_126 ) ) {
V_228 = 0 ;
if ( V_227 == V_54 -> V_227 && V_54 -> V_232 == V_89 )
return;
F_105 ( & V_54 -> V_126 , V_54 -> V_232 ) ;
V_54 -> V_232 = NULL ;
}
V_90 = 1 ;
V_34 = NULL ;
V_54 -> V_232 = V_89 ;
V_225 = & V_89 -> V_125 . V_126 ;
while ( * V_225 ) {
V_34 = * V_225 ;
V_226 = F_100 ( V_34 , struct V_53 , V_126 ) ;
if ( V_227 < V_226 -> V_227 )
V_225 = & V_34 -> V_138 ;
else {
V_225 = & V_34 -> V_139 ;
V_90 = 0 ;
}
}
if ( V_90 )
V_89 -> V_90 = & V_54 -> V_126 ;
V_54 -> V_227 = V_227 ;
F_114 ( & V_54 -> V_126 , V_34 , V_225 ) ;
F_115 ( & V_54 -> V_126 , & V_89 -> V_125 ) ;
V_89 -> V_61 ++ ;
if ( V_224 || ! V_228 )
return;
F_121 ( V_50 , V_54 -> V_3 ) ;
}
static struct V_53 *
F_204 ( struct V_49 * V_50 , struct V_128 * V_124 ,
T_4 V_233 , struct V_126 * * V_234 ,
struct V_126 * * * V_235 )
{
struct V_126 * * V_225 , * V_34 ;
struct V_53 * V_54 = NULL ;
V_34 = NULL ;
V_225 = & V_124 -> V_126 ;
while ( * V_225 ) {
struct V_126 * * V_127 ;
V_34 = * V_225 ;
V_54 = F_100 ( V_34 , struct V_53 , V_236 ) ;
if ( V_233 > F_97 ( V_54 -> V_237 ) )
V_127 = & ( * V_225 ) -> V_139 ;
else if ( V_233 < F_97 ( V_54 -> V_237 ) )
V_127 = & ( * V_225 ) -> V_138 ;
else
break;
V_225 = V_127 ;
V_54 = NULL ;
}
* V_234 = V_34 ;
if ( V_235 )
* V_235 = V_225 ;
return V_54 ;
}
static void F_205 ( struct V_49 * V_50 , struct V_53 * V_54 )
{
struct V_126 * * V_225 , * V_34 ;
struct V_53 * V_226 ;
if ( V_54 -> V_238 ) {
F_103 ( & V_54 -> V_236 , V_54 -> V_238 ) ;
V_54 -> V_238 = NULL ;
}
if ( F_58 ( V_54 ) )
return;
if ( ! V_54 -> V_237 )
return;
V_54 -> V_238 = & V_50 -> V_239 [ V_54 -> V_240 ] ;
V_226 = F_204 ( V_50 , V_54 -> V_238 ,
F_97 ( V_54 -> V_237 ) , & V_34 , & V_225 ) ;
if ( ! V_226 ) {
F_114 ( & V_54 -> V_236 , V_34 , V_225 ) ;
F_115 ( & V_54 -> V_236 , V_54 -> V_238 ) ;
} else
V_54 -> V_238 = NULL ;
}
static void F_206 ( struct V_49 * V_50 , struct V_53 * V_54 )
{
if ( F_207 ( V_54 ) ) {
F_203 ( V_50 , V_54 , 0 ) ;
F_205 ( V_50 , V_54 ) ;
}
}
static void F_208 ( struct V_49 * V_50 , struct V_53 * V_54 )
{
F_90 ( V_50 , V_54 , L_11 ) ;
F_21 ( F_207 ( V_54 ) ) ;
F_209 ( V_54 ) ;
V_50 -> V_72 ++ ;
if ( F_61 ( V_54 ) )
V_50 -> V_241 ++ ;
F_206 ( V_50 , V_54 ) ;
}
static void F_210 ( struct V_49 * V_50 , struct V_53 * V_54 )
{
F_90 ( V_50 , V_54 , L_12 ) ;
F_21 ( ! F_207 ( V_54 ) ) ;
F_211 ( V_54 ) ;
if ( ! F_109 ( & V_54 -> V_126 ) ) {
F_105 ( & V_54 -> V_126 , V_54 -> V_232 ) ;
V_54 -> V_232 = NULL ;
}
if ( V_54 -> V_238 ) {
F_103 ( & V_54 -> V_236 , V_54 -> V_238 ) ;
V_54 -> V_238 = NULL ;
}
F_125 ( V_50 , V_54 -> V_3 ) ;
F_21 ( ! V_50 -> V_72 ) ;
V_50 -> V_72 -- ;
if ( F_61 ( V_54 ) )
V_50 -> V_241 -- ;
}
static void F_212 ( struct V_110 * V_242 )
{
struct V_53 * V_54 = F_213 ( V_242 ) ;
const int V_74 = F_96 ( V_242 ) ;
F_21 ( ! V_54 -> V_19 [ V_74 ] ) ;
V_54 -> V_19 [ V_74 ] -- ;
F_214 ( & V_54 -> V_133 , V_242 ) ;
if ( F_207 ( V_54 ) && F_215 ( & V_54 -> V_133 ) ) {
if ( V_54 -> V_238 ) {
F_103 ( & V_54 -> V_236 , V_54 -> V_238 ) ;
V_54 -> V_238 = NULL ;
}
}
}
static void F_216 ( struct V_110 * V_242 )
{
struct V_53 * V_54 = F_213 ( V_242 ) ;
struct V_49 * V_50 = V_54 -> V_50 ;
struct V_110 * V_132 ;
V_54 -> V_19 [ F_96 ( V_242 ) ] ++ ;
F_217 ( & V_54 -> V_133 , V_242 ) ;
if ( ! F_207 ( V_54 ) )
F_208 ( V_50 , V_54 ) ;
V_132 = V_54 -> V_237 ;
V_54 -> V_237 = F_93 ( V_50 , V_54 -> V_237 , V_242 , V_50 -> V_243 ) ;
if ( V_132 != V_54 -> V_237 )
F_205 ( V_50 , V_54 ) ;
F_21 ( ! V_54 -> V_237 ) ;
}
static void F_218 ( struct V_53 * V_54 , struct V_110 * V_242 )
{
F_214 ( & V_54 -> V_133 , V_242 ) ;
V_54 -> V_19 [ F_96 ( V_242 ) ] -- ;
F_44 ( F_219 ( V_242 ) , V_242 -> V_120 ) ;
F_216 ( V_242 ) ;
F_40 ( F_219 ( V_242 ) , V_54 -> V_50 -> V_244 ,
V_242 -> V_120 ) ;
}
static struct V_110 *
F_220 ( struct V_49 * V_50 , struct V_245 * V_245 )
{
struct V_246 * V_247 = V_248 ;
struct V_62 * V_68 ;
struct V_53 * V_54 ;
V_68 = F_66 ( V_50 , V_247 -> V_65 ) ;
if ( ! V_68 )
return NULL ;
V_54 = F_68 ( V_68 , F_221 ( V_245 -> V_249 ) ) ;
if ( V_54 )
return F_222 ( & V_54 -> V_133 , F_223 ( V_245 ) ) ;
return NULL ;
}
static void F_224 ( struct V_250 * V_47 , struct V_110 * V_242 )
{
struct V_49 * V_50 = V_47 -> V_70 -> V_71 ;
V_50 -> V_251 ++ ;
F_90 ( V_50 , F_213 ( V_242 ) , L_13 ,
V_50 -> V_251 ) ;
V_50 -> V_243 = F_97 ( V_242 ) + F_225 ( V_242 ) ;
}
static void F_226 ( struct V_250 * V_47 , struct V_110 * V_242 )
{
struct V_49 * V_50 = V_47 -> V_70 -> V_71 ;
F_76 ( ! V_50 -> V_251 ) ;
V_50 -> V_251 -- ;
F_90 ( V_50 , F_213 ( V_242 ) , L_14 ,
V_50 -> V_251 ) ;
}
static void F_227 ( struct V_110 * V_242 )
{
struct V_53 * V_54 = F_213 ( V_242 ) ;
if ( V_54 -> V_237 == V_242 )
V_54 -> V_237 = F_106 ( V_54 -> V_50 , V_54 , V_242 ) ;
F_228 ( & V_242 -> V_252 ) ;
F_212 ( V_242 ) ;
V_54 -> V_50 -> V_253 -- ;
F_44 ( F_219 ( V_242 ) , V_242 -> V_120 ) ;
if ( V_242 -> V_120 & V_121 ) {
F_76 ( ! V_54 -> V_254 ) ;
V_54 -> V_254 -- ;
}
}
static enum V_255 F_229 ( struct V_250 * V_47 , struct V_110 * * V_256 ,
struct V_245 * V_245 )
{
struct V_49 * V_50 = V_47 -> V_70 -> V_71 ;
struct V_110 * V_257 ;
V_257 = F_220 ( V_50 , V_245 ) ;
if ( V_257 && F_230 ( V_257 , V_245 ) ) {
* V_256 = V_257 ;
return V_258 ;
}
return V_259 ;
}
static void F_231 ( struct V_250 * V_47 , struct V_110 * V_256 ,
enum V_255 type )
{
if ( type == V_258 ) {
struct V_53 * V_54 = F_213 ( V_256 ) ;
F_218 ( V_54 , V_256 ) ;
}
}
static void F_232 ( struct V_250 * V_47 , struct V_110 * V_256 ,
struct V_245 * V_245 )
{
F_45 ( F_219 ( V_256 ) , V_245 -> V_249 ) ;
}
static void
F_233 ( struct V_250 * V_47 , struct V_110 * V_242 ,
struct V_110 * V_131 )
{
struct V_53 * V_54 = F_213 ( V_242 ) ;
struct V_49 * V_50 = V_47 -> V_70 -> V_71 ;
if ( ! F_234 ( & V_242 -> V_252 ) && ! F_234 ( & V_131 -> V_252 ) &&
V_131 -> V_260 < V_242 -> V_260 &&
V_54 == F_213 ( V_131 ) ) {
F_235 ( & V_242 -> V_252 , & V_131 -> V_252 ) ;
V_242 -> V_260 = V_131 -> V_260 ;
}
if ( V_54 -> V_237 == V_131 )
V_54 -> V_237 = V_242 ;
F_227 ( V_131 ) ;
F_45 ( F_219 ( V_242 ) , V_131 -> V_120 ) ;
V_54 = F_213 ( V_131 ) ;
if ( F_207 ( V_54 ) && F_215 ( & V_54 -> V_133 ) &&
V_54 != V_50 -> V_261 )
F_210 ( V_50 , V_54 ) ;
}
static int F_236 ( struct V_250 * V_47 , struct V_110 * V_242 ,
struct V_245 * V_245 )
{
struct V_49 * V_50 = V_47 -> V_70 -> V_71 ;
bool V_69 = F_221 ( V_245 -> V_249 ) ;
struct V_62 * V_68 ;
struct V_53 * V_54 ;
if ( V_69 && ! F_96 ( V_242 ) )
return false ;
V_68 = F_66 ( V_50 , V_248 -> V_65 ) ;
if ( ! V_68 )
return false ;
V_54 = F_68 ( V_68 , V_69 ) ;
return V_54 == F_213 ( V_242 ) ;
}
static int F_237 ( struct V_250 * V_47 , struct V_110 * V_242 ,
struct V_110 * V_131 )
{
return F_213 ( V_242 ) == F_213 ( V_131 ) ;
}
static inline void F_238 ( struct V_49 * V_50 , struct V_53 * V_54 )
{
F_239 ( & V_50 -> V_262 ) ;
F_17 ( V_54 -> V_3 ) ;
}
static void F_240 ( struct V_49 * V_50 ,
struct V_53 * V_54 )
{
if ( V_54 ) {
F_90 ( V_50 , V_54 , L_15 ,
V_50 -> V_163 , V_50 -> V_161 ) ;
F_23 ( V_54 -> V_3 ) ;
V_54 -> V_107 = 0 ;
V_54 -> V_154 = F_89 () ;
V_54 -> V_109 = 0 ;
V_54 -> V_108 = 0 ;
V_54 -> V_158 = 0 ;
V_54 -> V_164 = 0 ;
F_241 ( V_54 ) ;
F_242 ( V_54 ) ;
F_243 ( V_54 ) ;
F_244 ( V_54 ) ;
F_245 ( V_54 ) ;
F_238 ( V_50 , V_54 ) ;
}
V_50 -> V_261 = V_54 ;
}
static void
F_246 ( struct V_49 * V_50 , struct V_53 * V_54 ,
bool V_263 )
{
F_90 ( V_50 , V_54 , L_16 , V_263 ) ;
if ( F_247 ( V_54 ) )
F_238 ( V_50 , V_54 ) ;
F_241 ( V_54 ) ;
F_248 ( V_54 ) ;
if ( F_249 ( V_54 ) && F_250 ( V_54 ) )
F_251 ( V_54 ) ;
if ( V_263 ) {
if ( F_92 ( V_54 ) )
V_54 -> V_230 = F_86 ( V_50 , V_54 ) ;
else
V_54 -> V_230 = V_54 -> V_108 - F_89 () ;
F_90 ( V_50 , V_54 , L_17 , V_54 -> V_230 ) ;
}
F_129 ( V_50 , V_54 -> V_3 , V_54 ) ;
if ( F_207 ( V_54 ) && F_215 ( & V_54 -> V_133 ) )
F_210 ( V_50 , V_54 ) ;
F_206 ( V_50 , V_54 ) ;
if ( V_54 == V_50 -> V_261 )
V_50 -> V_261 = NULL ;
if ( V_50 -> V_264 ) {
F_252 ( V_50 -> V_264 -> V_64 . V_66 ) ;
V_50 -> V_264 = NULL ;
}
}
static inline void F_253 ( struct V_49 * V_50 , bool V_263 )
{
struct V_53 * V_54 = V_50 -> V_261 ;
if ( V_54 )
F_246 ( V_50 , V_54 , V_263 ) ;
}
static struct V_53 * F_254 ( struct V_49 * V_50 )
{
struct V_1 * V_89 = F_1 ( V_50 -> V_244 ,
V_50 -> V_163 , V_50 -> V_161 ) ;
if ( ! V_50 -> V_253 )
return NULL ;
if ( ! V_89 )
return NULL ;
if ( F_215 ( & V_89 -> V_125 ) )
return NULL ;
return F_98 ( V_89 ) ;
}
static struct V_53 * F_255 ( struct V_49 * V_50 )
{
struct V_2 * V_3 ;
struct V_53 * V_54 ;
int V_165 , V_166 ;
struct V_1 * V_89 ;
if ( ! V_50 -> V_253 )
return NULL ;
V_3 = F_256 ( V_50 ) ;
if ( ! V_3 )
return NULL ;
F_131 (cfqg, i, j, st) {
V_54 = F_98 ( V_89 ) ;
if ( V_54 )
return V_54 ;
}
return NULL ;
}
static struct V_53 * F_257 ( struct V_49 * V_50 ,
struct V_53 * V_54 )
{
if ( ! V_54 )
V_54 = F_254 ( V_50 ) ;
F_240 ( V_50 , V_54 ) ;
return V_54 ;
}
static inline T_4 F_258 ( struct V_49 * V_50 ,
struct V_110 * V_242 )
{
if ( F_97 ( V_242 ) >= V_50 -> V_243 )
return F_97 ( V_242 ) - V_50 -> V_243 ;
else
return V_50 -> V_243 - F_97 ( V_242 ) ;
}
static inline int F_259 ( struct V_49 * V_50 , struct V_53 * V_54 ,
struct V_110 * V_242 )
{
return F_258 ( V_50 , V_242 ) <= V_265 ;
}
static struct V_53 * F_260 ( struct V_49 * V_50 ,
struct V_53 * V_266 )
{
struct V_128 * V_124 = & V_50 -> V_239 [ V_266 -> V_240 ] ;
struct V_126 * V_34 , * V_135 ;
struct V_53 * V_226 ;
T_4 V_233 = V_50 -> V_243 ;
if ( F_215 ( V_124 ) )
return NULL ;
V_226 = F_204 ( V_50 , V_124 , V_233 , & V_34 , NULL ) ;
if ( V_226 )
return V_226 ;
V_226 = F_100 ( V_34 , struct V_53 , V_236 ) ;
if ( F_259 ( V_50 , V_266 , V_226 -> V_237 ) )
return V_226 ;
if ( F_97 ( V_226 -> V_237 ) < V_233 )
V_135 = F_107 ( & V_226 -> V_236 ) ;
else
V_135 = F_108 ( & V_226 -> V_236 ) ;
if ( ! V_135 )
return NULL ;
V_226 = F_100 ( V_135 , struct V_53 , V_236 ) ;
if ( F_259 ( V_50 , V_266 , V_226 -> V_237 ) )
return V_226 ;
return NULL ;
}
static struct V_53 * F_261 ( struct V_49 * V_50 ,
struct V_53 * V_266 )
{
struct V_53 * V_54 ;
if ( F_58 ( V_266 ) )
return NULL ;
if ( ! F_61 ( V_266 ) )
return NULL ;
if ( F_250 ( V_266 ) )
return NULL ;
if ( V_266 -> V_3 -> V_134 == 1 )
return NULL ;
V_54 = F_260 ( V_50 , V_266 ) ;
if ( ! V_54 )
return NULL ;
if ( V_266 -> V_3 != V_54 -> V_3 )
return NULL ;
if ( ! F_61 ( V_54 ) )
return NULL ;
if ( F_250 ( V_54 ) )
return NULL ;
if ( F_59 ( V_54 ) != F_59 ( V_266 ) )
return NULL ;
return V_54 ;
}
static bool F_262 ( struct V_49 * V_50 , struct V_53 * V_54 )
{
enum V_4 V_60 = F_57 ( V_54 ) ;
struct V_1 * V_89 = V_54 -> V_232 ;
F_21 ( ! V_89 ) ;
F_21 ( ! V_89 -> V_61 ) ;
if ( ! V_50 -> V_51 )
return false ;
if ( V_60 == V_7 )
return false ;
if ( F_62 ( V_54 ) &&
! ( F_263 ( V_50 -> V_67 ) && V_50 -> V_52 ) )
return true ;
if ( V_89 -> V_61 == 1 && F_61 ( V_54 ) &&
! F_264 ( V_50 , & V_89 -> V_168 , false ) )
return true ;
F_90 ( V_50 , V_54 , L_18 , V_89 -> V_61 ) ;
return false ;
}
static void F_265 ( struct V_49 * V_50 )
{
struct V_53 * V_54 = V_50 -> V_261 ;
struct V_1 * V_89 = V_54 -> V_232 ;
struct V_62 * V_68 ;
T_2 V_267 , V_268 = 0 ;
T_2 V_12 = F_89 () ;
if ( F_263 ( V_50 -> V_67 ) && V_50 -> V_52 )
return;
F_76 ( ! F_215 ( & V_54 -> V_133 ) ) ;
F_76 ( F_92 ( V_54 ) ) ;
if ( ! F_262 ( V_50 , V_54 ) ) {
if ( V_50 -> V_269 )
V_268 = V_50 -> V_269 ;
else
return;
}
if ( V_54 -> V_270 )
return;
V_68 = V_50 -> V_264 ;
if ( ! V_68 || ! F_266 ( & V_68 -> V_64 . V_66 -> V_271 ) )
return;
if ( F_267 ( V_68 -> V_168 . V_272 ) &&
( V_54 -> V_108 - V_12 < V_68 -> V_168 . V_273 ) ) {
F_90 ( V_50 , V_54 , L_19 ,
V_68 -> V_168 . V_273 ) ;
return;
}
if ( V_268 &&
( V_54 -> V_3 -> V_134 > 1 ||
F_264 ( V_50 , & V_89 -> V_168 , true ) ) )
return;
F_268 ( V_54 ) ;
if ( V_268 )
V_267 = V_50 -> V_269 ;
else
V_267 = V_50 -> V_51 ;
F_269 ( & V_50 -> V_262 , F_270 ( V_267 ) ,
V_274 ) ;
F_20 ( V_54 -> V_3 ) ;
F_90 ( V_50 , V_54 , L_20 , V_267 ,
V_268 ? 1 : 0 ) ;
}
static void F_271 ( struct V_250 * V_47 , struct V_110 * V_242 )
{
struct V_49 * V_50 = V_47 -> V_70 -> V_71 ;
struct V_53 * V_54 = F_213 ( V_242 ) ;
F_90 ( V_50 , V_54 , L_21 ) ;
V_54 -> V_237 = F_106 ( V_50 , V_54 , V_242 ) ;
F_227 ( V_242 ) ;
V_54 -> V_270 ++ ;
( F_219 ( V_242 ) ) -> V_270 ++ ;
F_272 ( V_47 , V_242 ) ;
V_50 -> V_275 [ F_61 ( V_54 ) ] ++ ;
V_54 -> V_164 += F_225 ( V_242 ) ;
}
static struct V_110 * F_273 ( struct V_53 * V_54 )
{
struct V_110 * V_242 = NULL ;
if ( F_274 ( V_54 ) )
return NULL ;
F_275 ( V_54 ) ;
if ( F_234 ( & V_54 -> V_276 ) )
return NULL ;
V_242 = F_276 ( V_54 -> V_276 . V_131 ) ;
if ( F_89 () < V_242 -> V_260 )
V_242 = NULL ;
return V_242 ;
}
static inline int
F_277 ( struct V_49 * V_50 , struct V_53 * V_54 )
{
const int V_277 = V_50 -> V_278 ;
F_76 ( V_54 -> V_81 >= V_80 ) ;
return 2 * V_277 * ( V_80 - V_54 -> V_81 ) ;
}
static int F_278 ( struct V_53 * V_54 )
{
int V_279 , V_280 ;
V_280 = V_54 -> V_281 [ V_282 ] + V_54 -> V_281 [ V_283 ] ;
V_279 = V_54 -> V_284 - V_280 ;
F_21 ( V_279 < 0 ) ;
return V_279 ;
}
static void F_279 ( struct V_53 * V_54 , struct V_53 * V_228 )
{
int V_279 , V_285 ;
struct V_53 * V_226 ;
if ( ! F_278 ( V_228 ) )
return;
while ( ( V_226 = V_228 -> V_228 ) ) {
if ( V_226 == V_54 )
return;
V_228 = V_226 ;
}
V_279 = F_278 ( V_54 ) ;
V_285 = F_278 ( V_228 ) ;
if ( V_279 == 0 || V_285 == 0 )
return;
if ( V_285 >= V_279 ) {
V_54 -> V_228 = V_228 ;
V_228 -> V_284 += V_279 ;
} else {
V_228 -> V_228 = V_54 ;
V_54 -> V_284 += V_285 ;
}
}
static enum V_6 F_280 ( struct V_49 * V_50 ,
struct V_2 * V_3 , enum V_4 V_60 )
{
struct V_53 * V_67 ;
int V_165 ;
bool V_286 = false ;
T_2 V_287 = 0 ;
enum V_6 V_288 = V_58 ;
for ( V_165 = 0 ; V_165 <= V_59 ; ++ V_165 ) {
V_67 = F_98 ( F_1 ( V_3 , V_60 , V_165 ) ) ;
if ( V_67 &&
( ! V_286 || V_67 -> V_227 < V_287 ) ) {
V_287 = V_67 -> V_227 ;
V_288 = V_165 ;
V_286 = true ;
}
}
return V_288 ;
}
static void
F_281 ( struct V_49 * V_50 , struct V_2 * V_3 )
{
T_2 V_78 ;
unsigned V_61 ;
struct V_1 * V_89 ;
T_2 V_104 ;
enum V_4 V_289 = V_50 -> V_163 ;
T_2 V_12 = F_89 () ;
if ( F_63 ( V_55 , V_50 , V_3 ) )
V_50 -> V_163 = V_55 ;
else if ( F_63 ( V_56 , V_50 , V_3 ) )
V_50 -> V_163 = V_56 ;
else {
V_50 -> V_163 = V_7 ;
V_50 -> V_159 = V_12 + F_128 ( 1 ) ;
return;
}
if ( V_289 != V_50 -> V_163 )
goto V_290;
V_89 = F_1 ( V_3 , V_50 -> V_163 , V_50 -> V_161 ) ;
V_61 = V_89 -> V_61 ;
if ( V_61 && ! ( V_12 > V_50 -> V_159 ) )
return;
V_290:
V_50 -> V_161 = F_280 ( V_50 , V_3 ,
V_50 -> V_163 ) ;
V_89 = F_1 ( V_3 , V_50 -> V_163 , V_50 -> V_161 ) ;
V_61 = V_89 -> V_61 ;
V_104 = F_85 ( V_50 , V_3 ) ;
V_78 = F_75 ( V_104 * V_61 ,
F_119 ( unsigned , V_3 -> V_98 [ V_50 -> V_163 ] ,
F_63 ( V_50 -> V_163 , V_50 ,
V_3 ) ) ) ;
if ( V_50 -> V_161 == V_57 ) {
T_2 V_217 ;
V_217 = V_50 -> V_99 *
F_64 ( V_50 , V_3 ) ;
V_217 = F_75 ( V_217 , V_50 -> V_72 ) ;
V_78 = F_282 ( T_2 , V_78 , V_217 ) ;
V_78 = F_87 ( V_78 * V_50 -> V_77 [ 0 ] , V_50 -> V_77 [ 1 ] ) ;
} else
V_78 = F_84 ( V_78 , 2 * V_50 -> V_51 ) ;
V_78 = F_119 ( T_2 , V_78 , V_291 ) ;
F_72 ( V_50 , L_22 , V_78 ) ;
V_50 -> V_159 = V_12 + V_78 ;
}
static struct V_2 * F_256 ( struct V_49 * V_50 )
{
struct V_1 * V_89 = & V_50 -> V_151 ;
struct V_2 * V_3 ;
if ( F_215 ( & V_89 -> V_125 ) )
return NULL ;
V_3 = F_101 ( V_89 ) ;
F_80 ( V_89 ) ;
return V_3 ;
}
static void F_283 ( struct V_49 * V_50 )
{
struct V_2 * V_3 = F_256 ( V_50 ) ;
T_2 V_12 = F_89 () ;
V_50 -> V_244 = V_3 ;
if ( V_3 -> V_152 ) {
V_50 -> V_159 = V_12 + V_3 -> V_152 ;
V_50 -> V_161 = V_3 -> V_160 ;
V_50 -> V_163 = V_3 -> V_162 ;
} else
V_50 -> V_159 = V_12 - 1 ;
F_281 ( V_50 , V_3 ) ;
}
static struct V_53 * F_284 ( struct V_49 * V_50 )
{
struct V_53 * V_54 , * V_228 = NULL ;
T_2 V_12 = F_89 () ;
V_54 = V_50 -> V_261 ;
if ( ! V_54 )
goto V_292;
if ( ! V_50 -> V_253 )
return NULL ;
if ( F_285 ( V_54 ) && ! F_215 ( & V_54 -> V_133 ) )
goto V_293;
if ( F_91 ( V_54 ) && ! F_286 ( V_54 ) ) {
if ( V_54 -> V_3 -> V_134 == 1 && F_215 ( & V_54 -> V_133 )
&& V_54 -> V_270 && F_262 ( V_50 , V_54 ) ) {
V_54 = NULL ;
goto V_294;
} else
goto V_295;
}
if ( ! F_215 ( & V_54 -> V_133 ) )
goto V_294;
V_228 = F_261 ( V_50 , V_54 ) ;
if ( V_228 ) {
if ( ! V_54 -> V_228 )
F_279 ( V_54 , V_228 ) ;
goto V_293;
}
if ( F_287 ( & V_50 -> V_262 ) ) {
V_54 = NULL ;
goto V_294;
}
if ( F_250 ( V_54 ) && F_62 ( V_54 ) &&
( F_92 ( V_54 ) ||
( V_54 -> V_108 - V_12 > V_12 - V_54 -> V_107 ) ) ) {
F_288 ( V_54 ) ;
F_289 ( V_54 ) ;
}
if ( V_54 -> V_270 && F_262 ( V_50 , V_54 ) ) {
V_54 = NULL ;
goto V_294;
}
V_295:
if ( V_50 -> V_269 && V_54 -> V_3 -> V_134 == 1 &&
V_54 -> V_3 -> V_270 &&
! F_264 ( V_50 , & V_54 -> V_3 -> V_168 , true ) ) {
V_54 = NULL ;
goto V_294;
}
V_293:
F_253 ( V_50 , 0 ) ;
V_292:
if ( ! V_228 )
F_283 ( V_50 ) ;
V_54 = F_257 ( V_50 , V_228 ) ;
V_294:
return V_54 ;
}
static int F_290 ( struct V_53 * V_54 )
{
int V_270 = 0 ;
while ( V_54 -> V_237 ) {
F_271 ( V_54 -> V_50 -> V_67 , V_54 -> V_237 ) ;
V_270 ++ ;
}
F_21 ( ! F_234 ( & V_54 -> V_276 ) ) ;
F_246 ( V_54 -> V_50 , V_54 , 0 ) ;
return V_270 ;
}
static int F_291 ( struct V_49 * V_50 )
{
struct V_53 * V_54 ;
int V_270 = 0 ;
F_253 ( V_50 , 0 ) ;
while ( ( V_54 = F_255 ( V_50 ) ) != NULL ) {
F_240 ( V_50 , V_54 ) ;
V_270 += F_290 ( V_54 ) ;
}
F_21 ( V_50 -> V_72 ) ;
F_72 ( V_50 , L_23 , V_270 ) ;
return V_270 ;
}
static inline bool F_292 ( struct V_49 * V_50 ,
struct V_53 * V_54 )
{
T_2 V_12 = F_89 () ;
if ( F_92 ( V_54 ) )
return true ;
if ( V_12 + V_50 -> V_51 * V_54 -> V_270 > V_54 -> V_108 )
return true ;
return false ;
}
static bool F_293 ( struct V_49 * V_50 , struct V_53 * V_54 )
{
unsigned int V_296 ;
if ( F_286 ( V_54 ) )
return true ;
if ( F_262 ( V_50 , V_54 ) && V_50 -> V_275 [ V_297 ] )
return false ;
if ( V_50 -> V_275 [ V_298 ] && ! F_61 ( V_54 ) )
return false ;
V_296 = F_119 (unsigned int, cfqd->cfq_quantum / 2 , 1 ) ;
if ( F_58 ( V_54 ) )
V_296 = 1 ;
if ( V_54 -> V_270 >= V_296 ) {
bool V_299 = false ;
if ( F_58 ( V_54 ) )
return false ;
if ( F_61 ( V_54 ) && V_50 -> V_241 == 1 )
V_299 = true ;
if ( V_50 -> V_72 > 1 && F_292 ( V_50 , V_54 ) &&
! V_299 )
return false ;
if ( V_50 -> V_72 == 1 || V_299 )
V_296 = - 1 ;
else
V_296 = V_50 -> V_300 ;
}
if ( ! F_61 ( V_54 ) && V_50 -> V_100 ) {
T_2 V_301 = F_89 () - V_50 -> V_302 ;
unsigned int V_303 ;
V_303 = F_87 ( V_301 , V_50 -> V_77 [ 1 ] ) ;
if ( ! V_303 && ! V_54 -> V_270 )
V_303 = 1 ;
if ( V_303 < V_296 )
V_296 = V_303 ;
}
return V_54 -> V_270 < V_296 ;
}
static bool F_294 ( struct V_49 * V_50 , struct V_53 * V_54 )
{
struct V_110 * V_242 ;
F_21 ( F_215 ( & V_54 -> V_133 ) ) ;
V_242 = F_273 ( V_54 ) ;
if ( V_242 )
F_295 ( V_54 ) ;
if ( ! F_293 ( V_50 , V_54 ) )
return false ;
if ( ! V_242 )
V_242 = V_54 -> V_237 ;
else
F_90 ( V_54 -> V_50 , V_54 , L_24 , V_242 ) ;
F_271 ( V_50 -> V_67 , V_242 ) ;
if ( ! V_50 -> V_264 ) {
struct V_62 * V_68 = F_296 ( V_242 ) ;
F_297 ( & V_68 -> V_64 . V_66 -> V_304 ) ;
V_50 -> V_264 = V_68 ;
}
return true ;
}
static int F_298 ( struct V_250 * V_47 , int V_305 )
{
struct V_49 * V_50 = V_47 -> V_70 -> V_71 ;
struct V_53 * V_54 ;
if ( ! V_50 -> V_72 )
return 0 ;
if ( F_55 ( V_305 ) )
return F_291 ( V_50 ) ;
V_54 = F_284 ( V_50 ) ;
if ( ! V_54 )
return 0 ;
if ( ! F_294 ( V_50 , V_54 ) )
return 0 ;
V_54 -> V_158 ++ ;
F_242 ( V_54 ) ;
if ( V_50 -> V_72 > 1 && ( ( ! F_61 ( V_54 ) &&
V_54 -> V_158 >= F_277 ( V_50 , V_54 ) ) ||
F_58 ( V_54 ) ) ) {
V_54 -> V_108 = F_89 () + 1 ;
F_253 ( V_50 , 0 ) ;
}
F_90 ( V_50 , V_54 , L_25 ) ;
return 1 ;
}
static void F_151 ( struct V_53 * V_54 )
{
struct V_49 * V_50 = V_54 -> V_50 ;
struct V_2 * V_3 ;
F_21 ( V_54 -> V_284 <= 0 ) ;
V_54 -> V_284 -- ;
if ( V_54 -> V_284 )
return;
F_90 ( V_50 , V_54 , L_26 ) ;
F_21 ( F_99 ( & V_54 -> V_133 ) ) ;
F_21 ( V_54 -> V_281 [ V_282 ] + V_54 -> V_281 [ V_283 ] ) ;
V_3 = V_54 -> V_3 ;
if ( F_55 ( V_50 -> V_261 == V_54 ) ) {
F_246 ( V_50 , V_54 , 0 ) ;
F_71 ( V_50 ) ;
}
F_21 ( F_207 ( V_54 ) ) ;
F_299 ( V_306 , V_54 ) ;
F_38 ( V_3 ) ;
}
static void F_300 ( struct V_53 * V_54 )
{
struct V_53 * V_226 , * V_131 ;
V_226 = V_54 -> V_228 ;
while ( V_226 ) {
if ( V_226 == V_54 ) {
F_301 ( 1 , L_27 ) ;
break;
}
V_131 = V_226 -> V_228 ;
F_151 ( V_226 ) ;
V_226 = V_131 ;
}
}
static void F_302 ( struct V_49 * V_50 , struct V_53 * V_54 )
{
if ( F_55 ( V_54 == V_50 -> V_261 ) ) {
F_246 ( V_50 , V_54 , 0 ) ;
F_71 ( V_50 ) ;
}
F_300 ( V_54 ) ;
F_151 ( V_54 ) ;
}
static void F_303 ( struct V_63 * V_64 )
{
struct V_62 * V_68 = F_65 ( V_64 ) ;
V_68 -> V_168 . V_169 = F_89 () ;
}
static void F_304 ( struct V_63 * V_64 )
{
struct V_62 * V_68 = F_65 ( V_64 ) ;
struct V_49 * V_50 = F_70 ( V_68 ) ;
if ( F_68 ( V_68 , false ) ) {
F_302 ( V_50 , F_68 ( V_68 , false ) ) ;
F_69 ( V_68 , NULL , false ) ;
}
if ( F_68 ( V_68 , true ) ) {
F_302 ( V_50 , F_68 ( V_68 , true ) ) ;
F_69 ( V_68 , NULL , true ) ;
}
}
static void F_305 ( struct V_53 * V_54 , struct V_62 * V_68 )
{
struct V_246 * V_247 = V_248 ;
int V_307 ;
if ( ! F_306 ( V_54 ) )
return;
V_307 = F_307 ( V_68 -> V_81 ) ;
switch ( V_307 ) {
default:
F_308 ( V_308 L_28 , V_307 ) ;
case V_309 :
V_54 -> V_81 = F_309 ( V_247 ) ;
V_54 -> V_307 = F_310 ( V_247 ) ;
break;
case V_310 :
V_54 -> V_81 = F_311 ( V_68 -> V_81 ) ;
V_54 -> V_307 = V_310 ;
break;
case V_311 :
V_54 -> V_81 = F_311 ( V_68 -> V_81 ) ;
V_54 -> V_307 = V_311 ;
break;
case V_312 :
V_54 -> V_307 = V_312 ;
V_54 -> V_81 = 7 ;
F_289 ( V_54 ) ;
break;
}
V_54 -> V_240 = V_54 -> V_81 ;
V_54 -> V_313 = V_54 -> V_307 ;
F_312 ( V_54 ) ;
}
static void F_313 ( struct V_62 * V_68 , struct V_245 * V_245 )
{
int V_81 = V_68 -> V_64 . V_66 -> V_81 ;
struct V_49 * V_50 = F_70 ( V_68 ) ;
struct V_53 * V_54 ;
if ( F_55 ( ! V_50 ) || F_156 ( V_68 -> V_81 == V_81 ) )
return;
V_54 = F_68 ( V_68 , false ) ;
if ( V_54 ) {
F_151 ( V_54 ) ;
V_54 = F_314 ( V_50 , V_297 , V_68 , V_245 ) ;
F_69 ( V_68 , V_54 , false ) ;
}
V_54 = F_68 ( V_68 , true ) ;
if ( V_54 )
F_315 ( V_54 ) ;
V_68 -> V_81 = V_81 ;
}
static void F_316 ( struct V_49 * V_50 , struct V_53 * V_54 ,
T_9 V_314 , bool V_69 )
{
F_104 ( & V_54 -> V_126 ) ;
F_104 ( & V_54 -> V_236 ) ;
F_317 ( & V_54 -> V_276 ) ;
V_54 -> V_284 = 0 ;
V_54 -> V_50 = V_50 ;
F_315 ( V_54 ) ;
if ( V_69 ) {
if ( ! F_58 ( V_54 ) )
F_318 ( V_54 ) ;
F_319 ( V_54 ) ;
}
V_54 -> V_314 = V_314 ;
}
static void F_320 ( struct V_62 * V_68 , struct V_245 * V_245 )
{
struct V_49 * V_50 = F_70 ( V_68 ) ;
struct V_53 * V_54 ;
T_1 V_315 ;
F_321 () ;
V_315 = F_322 ( V_245 ) -> V_36 . V_315 ;
F_323 () ;
if ( F_55 ( ! V_50 ) || F_156 ( V_68 -> V_316 == V_315 ) )
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
V_68 -> V_316 = V_315 ;
}
static inline void F_320 ( struct V_62 * V_68 , struct V_245 * V_245 )
{
}
static struct V_53 * *
F_324 ( struct V_2 * V_3 , int V_307 , int V_81 )
{
switch ( V_307 ) {
case V_310 :
return & V_3 -> V_179 [ 0 ] [ V_81 ] ;
case V_309 :
V_81 = V_317 ;
case V_311 :
return & V_3 -> V_179 [ 1 ] [ V_81 ] ;
case V_312 :
return & V_3 -> V_180 ;
default:
F_325 () ;
}
}
static struct V_53 *
F_314 ( struct V_49 * V_50 , bool V_69 , struct V_62 * V_68 ,
struct V_245 * V_245 )
{
int V_307 = F_307 ( V_68 -> V_81 ) ;
int V_81 = F_311 ( V_68 -> V_81 ) ;
struct V_53 * * V_179 = NULL ;
struct V_53 * V_54 ;
struct V_2 * V_3 ;
F_321 () ;
V_3 = F_154 ( V_50 , F_322 ( V_245 ) ) ;
if ( ! V_3 ) {
V_54 = & V_50 -> V_318 ;
goto V_208;
}
if ( ! V_69 ) {
if ( ! F_326 ( V_68 -> V_81 ) ) {
struct V_246 * V_247 = V_248 ;
V_81 = F_309 ( V_247 ) ;
V_307 = F_310 ( V_247 ) ;
}
V_179 = F_324 ( V_3 , V_307 , V_81 ) ;
V_54 = * V_179 ;
if ( V_54 )
goto V_208;
}
V_54 = F_327 ( V_306 ,
V_319 | V_320 | V_321 ,
V_50 -> V_67 -> V_135 ) ;
if ( ! V_54 ) {
V_54 = & V_50 -> V_318 ;
goto V_208;
}
V_54 -> V_307 = V_309 ;
F_316 ( V_50 , V_54 , V_248 -> V_314 , V_69 ) ;
F_305 ( V_54 , V_68 ) ;
F_157 ( V_54 , V_3 ) ;
F_90 ( V_50 , V_54 , L_30 ) ;
if ( V_179 ) {
V_54 -> V_284 ++ ;
* V_179 = V_54 ;
}
V_208:
V_54 -> V_284 ++ ;
F_323 () ;
return V_54 ;
}
static void
F_328 ( struct V_322 * V_168 , T_2 V_323 )
{
T_2 V_324 = F_89 () - V_168 -> V_169 ;
V_324 = F_83 ( V_324 , 2UL * V_323 ) ;
V_168 -> V_272 = ( 7 * V_168 -> V_272 + 256 ) / 8 ;
V_168 -> V_325 = F_75 ( 7 * V_168 -> V_325 + 256 * V_324 , 8 ) ;
V_168 -> V_273 = F_329 ( V_168 -> V_325 + 128 ,
V_168 -> V_272 ) ;
}
static void
F_330 ( struct V_49 * V_50 , struct V_53 * V_54 ,
struct V_62 * V_68 )
{
if ( F_61 ( V_54 ) ) {
F_328 ( & V_68 -> V_168 , V_50 -> V_51 ) ;
F_328 ( & V_54 -> V_232 -> V_168 ,
V_50 -> V_51 ) ;
}
#ifdef F_331
F_328 ( & V_54 -> V_3 -> V_168 , V_50 -> V_269 ) ;
#endif
}
static void
F_332 ( struct V_49 * V_50 , struct V_53 * V_54 ,
struct V_110 * V_242 )
{
T_4 V_326 = 0 ;
T_4 V_327 = F_225 ( V_242 ) ;
if ( V_54 -> V_328 ) {
if ( V_54 -> V_328 < F_97 ( V_242 ) )
V_326 = F_97 ( V_242 ) - V_54 -> V_328 ;
else
V_326 = V_54 -> V_328 - F_97 ( V_242 ) ;
}
V_54 -> V_329 <<= 1 ;
if ( F_263 ( V_50 -> V_67 ) )
V_54 -> V_329 |= ( V_327 < V_330 ) ;
else
V_54 -> V_329 |= ( V_326 > V_331 ) ;
}
static inline bool F_333 ( struct V_110 * V_256 )
{
return F_334 ( V_256 ) == V_332 &&
( V_256 -> V_120 & ( V_333 | V_334 ) ) == V_333 ;
}
static void
F_335 ( struct V_49 * V_50 , struct V_53 * V_54 ,
struct V_62 * V_68 )
{
int V_335 , V_336 ;
if ( ! F_61 ( V_54 ) || F_58 ( V_54 ) )
return;
V_336 = V_335 = F_62 ( V_54 ) ;
if ( V_54 -> V_19 [ 0 ] + V_54 -> V_19 [ 1 ] >= 4 )
F_336 ( V_54 ) ;
if ( V_54 -> V_237 && F_333 ( V_54 -> V_237 ) )
V_336 = 0 ;
else if ( ! F_266 ( & V_68 -> V_64 . V_66 -> V_271 ) ||
! V_50 -> V_51 ||
( ! F_337 ( V_54 ) && F_250 ( V_54 ) ) )
V_336 = 0 ;
else if ( F_267 ( V_68 -> V_168 . V_272 ) ) {
if ( V_68 -> V_168 . V_273 > V_50 -> V_51 )
V_336 = 0 ;
else
V_336 = 1 ;
}
if ( V_335 != V_336 ) {
F_90 ( V_50 , V_54 , L_31 , V_336 ) ;
if ( V_336 )
F_318 ( V_54 ) ;
else
F_289 ( V_54 ) ;
}
}
static bool
F_338 ( struct V_49 * V_50 , struct V_53 * V_228 ,
struct V_110 * V_242 )
{
struct V_53 * V_54 ;
V_54 = V_50 -> V_261 ;
if ( ! V_54 )
return false ;
if ( F_58 ( V_228 ) )
return false ;
if ( F_58 ( V_54 ) )
return true ;
if ( F_59 ( V_54 ) && ! F_59 ( V_228 ) )
return false ;
if ( F_96 ( V_242 ) && ! F_61 ( V_54 ) && ! F_286 ( V_54 ) )
return true ;
if ( ! F_34 ( V_54 -> V_3 , V_228 -> V_3 ) )
return false ;
if ( F_91 ( V_54 ) )
return true ;
if ( F_59 ( V_228 ) && ! F_59 ( V_54 ) )
return true ;
F_124 ( V_54 -> V_307 != V_228 -> V_307 ) ;
if ( V_50 -> V_161 == V_58 &&
F_60 ( V_228 ) == V_58 &&
F_215 ( & V_54 -> V_133 ) )
return true ;
if ( ( V_242 -> V_120 & V_121 ) && ! V_54 -> V_254 )
return true ;
if ( F_215 ( & V_54 -> V_133 ) && ! F_262 ( V_50 , V_54 ) )
return true ;
if ( ! V_50 -> V_264 || ! F_247 ( V_54 ) )
return false ;
if ( F_259 ( V_50 , V_54 , V_242 ) )
return true ;
return false ;
}
static void F_339 ( struct V_49 * V_50 , struct V_53 * V_54 )
{
enum V_6 V_337 = F_60 ( V_50 -> V_261 ) ;
F_90 ( V_50 , V_54 , L_32 ) ;
F_253 ( V_50 , 1 ) ;
if ( V_337 != F_60 ( V_54 ) )
V_54 -> V_3 -> V_152 = 0 ;
F_21 ( ! F_207 ( V_54 ) ) ;
F_203 ( V_50 , V_54 , 1 ) ;
V_54 -> V_108 = 0 ;
F_245 ( V_54 ) ;
}
static void
F_340 ( struct V_49 * V_50 , struct V_53 * V_54 ,
struct V_110 * V_242 )
{
struct V_62 * V_68 = F_296 ( V_242 ) ;
V_50 -> V_253 ++ ;
if ( V_242 -> V_120 & V_121 )
V_54 -> V_254 ++ ;
F_330 ( V_50 , V_54 , V_68 ) ;
F_332 ( V_50 , V_54 , V_242 ) ;
F_335 ( V_50 , V_54 , V_68 ) ;
V_54 -> V_328 = F_97 ( V_242 ) + F_225 ( V_242 ) ;
if ( V_54 == V_50 -> V_261 ) {
if ( F_247 ( V_54 ) ) {
if ( F_341 ( V_242 ) > V_338 ||
V_50 -> V_72 > 1 ) {
F_238 ( V_50 , V_54 ) ;
F_241 ( V_54 ) ;
F_342 ( V_50 -> V_67 ) ;
} else {
F_17 ( V_54 -> V_3 ) ;
F_295 ( V_54 ) ;
}
}
} else if ( F_338 ( V_50 , V_54 , V_242 ) ) {
F_339 ( V_50 , V_54 ) ;
F_342 ( V_50 -> V_67 ) ;
}
}
static void F_343 ( struct V_250 * V_47 , struct V_110 * V_242 )
{
struct V_49 * V_50 = V_47 -> V_70 -> V_71 ;
struct V_53 * V_54 = F_213 ( V_242 ) ;
F_90 ( V_50 , V_54 , L_33 ) ;
F_305 ( V_54 , F_296 ( V_242 ) ) ;
V_242 -> V_260 = F_89 () + V_50 -> V_339 [ F_96 ( V_242 ) ] ;
F_344 ( & V_242 -> V_252 , & V_54 -> V_276 ) ;
F_216 ( V_242 ) ;
F_40 ( F_219 ( V_242 ) , V_50 -> V_244 ,
V_242 -> V_120 ) ;
F_340 ( V_50 , V_54 , V_242 ) ;
}
static void F_345 ( struct V_49 * V_50 )
{
struct V_53 * V_54 = V_50 -> V_261 ;
if ( V_50 -> V_251 > V_50 -> V_340 )
V_50 -> V_340 = V_50 -> V_251 ;
if ( V_50 -> V_52 == 1 )
return;
if ( V_50 -> V_253 <= V_341 &&
V_50 -> V_251 <= V_341 )
return;
if ( V_54 && F_62 ( V_54 ) &&
V_54 -> V_270 + V_54 -> V_19 [ 0 ] + V_54 -> V_19 [ 1 ] <
V_341 && V_50 -> V_251 < V_341 )
return;
if ( V_50 -> V_342 ++ < 50 )
return;
if ( V_50 -> V_340 >= V_341 )
V_50 -> V_52 = 1 ;
else
V_50 -> V_52 = 0 ;
}
static bool F_346 ( struct V_49 * V_50 , struct V_53 * V_54 )
{
struct V_62 * V_68 = V_50 -> V_264 ;
T_2 V_12 = F_89 () ;
if ( ! F_215 ( & V_54 -> V_133 ) )
return false ;
if ( V_54 -> V_3 -> V_134 > 1 )
return false ;
if ( F_264 ( V_50 , & V_54 -> V_3 -> V_168 , true ) )
return false ;
if ( F_91 ( V_54 ) )
return true ;
if ( V_68 && F_267 ( V_68 -> V_168 . V_272 )
&& ( V_54 -> V_108 - V_12 < V_68 -> V_168 . V_273 ) )
return true ;
if ( V_54 -> V_108 - V_12 <= F_128 ( 1 ) )
return true ;
return false ;
}
static void F_347 ( struct V_250 * V_47 , struct V_110 * V_242 )
{
struct V_53 * V_54 = F_213 ( V_242 ) ;
struct V_49 * V_50 = V_54 -> V_50 ;
const int V_74 = F_96 ( V_242 ) ;
T_2 V_12 = F_89 () ;
F_90 ( V_50 , V_54 , L_34 , F_333 ( V_242 ) ) ;
F_345 ( V_50 ) ;
F_76 ( ! V_50 -> V_251 ) ;
F_76 ( ! V_54 -> V_270 ) ;
V_50 -> V_251 -- ;
V_54 -> V_270 -- ;
( F_219 ( V_242 ) ) -> V_270 -- ;
F_46 ( V_54 -> V_3 , F_348 ( V_242 ) ,
F_349 ( V_242 ) , V_242 -> V_120 ) ;
V_50 -> V_275 [ F_61 ( V_54 ) ] -- ;
if ( V_74 ) {
struct V_1 * V_89 ;
F_296 ( V_242 ) -> V_168 . V_169 = V_12 ;
if ( F_207 ( V_54 ) )
V_89 = V_54 -> V_232 ;
else
V_89 = F_1 ( V_54 -> V_3 , F_57 ( V_54 ) ,
F_60 ( V_54 ) ) ;
V_89 -> V_168 . V_169 = V_12 ;
if ( ! F_350 ( V_242 -> V_41 +
F_351 ( V_50 -> V_339 [ 1 ] ) ,
V_343 ) )
V_50 -> V_302 = V_12 ;
}
#ifdef F_331
V_54 -> V_3 -> V_168 . V_169 = V_12 ;
#endif
if ( V_50 -> V_261 == V_54 ) {
const bool V_344 = F_215 ( & V_54 -> V_133 ) ;
if ( F_92 ( V_54 ) ) {
F_88 ( V_50 , V_54 ) ;
F_352 ( V_54 ) ;
}
if ( F_346 ( V_50 , V_54 ) ) {
T_2 V_345 = V_50 -> V_51 ;
if ( ! V_50 -> V_51 )
V_345 = V_50 -> V_269 ;
V_54 -> V_108 = V_12 + V_345 ;
F_353 ( V_54 ) ;
F_90 ( V_50 , V_54 , L_35 ) ;
}
if ( F_91 ( V_54 ) || F_58 ( V_54 ) )
F_253 ( V_50 , 1 ) ;
else if ( V_74 && V_344 &&
! F_261 ( V_50 , V_54 ) ) {
F_265 ( V_50 ) ;
}
}
if ( ! V_50 -> V_251 )
F_71 ( V_50 ) ;
}
static void F_354 ( struct V_53 * V_54 , unsigned int V_38 )
{
if ( ! ( V_38 & V_121 ) ) {
V_54 -> V_307 = V_54 -> V_313 ;
V_54 -> V_81 = V_54 -> V_240 ;
} else {
if ( F_58 ( V_54 ) )
V_54 -> V_307 = V_311 ;
if ( V_54 -> V_81 > V_317 )
V_54 -> V_81 = V_317 ;
}
}
static inline int F_355 ( struct V_53 * V_54 )
{
if ( F_247 ( V_54 ) && ! F_356 ( V_54 ) ) {
F_357 ( V_54 ) ;
return V_346 ;
}
return V_347 ;
}
static int F_358 ( struct V_250 * V_47 , unsigned int V_38 )
{
struct V_49 * V_50 = V_47 -> V_70 -> V_71 ;
struct V_246 * V_247 = V_248 ;
struct V_62 * V_68 ;
struct V_53 * V_54 ;
V_68 = F_66 ( V_50 , V_247 -> V_65 ) ;
if ( ! V_68 )
return V_347 ;
V_54 = F_68 ( V_68 , F_221 ( V_38 ) ) ;
if ( V_54 ) {
F_305 ( V_54 , V_68 ) ;
F_354 ( V_54 , V_38 ) ;
return F_355 ( V_54 ) ;
}
return V_347 ;
}
static void F_359 ( struct V_110 * V_242 )
{
struct V_53 * V_54 = F_213 ( V_242 ) ;
if ( V_54 ) {
const int V_348 = F_360 ( V_242 ) ;
F_21 ( ! V_54 -> V_281 [ V_348 ] ) ;
V_54 -> V_281 [ V_348 ] -- ;
F_38 ( F_219 ( V_242 ) ) ;
V_242 -> V_349 . V_350 [ 0 ] = NULL ;
V_242 -> V_349 . V_350 [ 1 ] = NULL ;
F_151 ( V_54 ) ;
}
}
static struct V_53 *
F_361 ( struct V_49 * V_50 , struct V_62 * V_68 ,
struct V_53 * V_54 )
{
F_90 ( V_50 , V_54 , L_36 , V_54 -> V_228 ) ;
F_69 ( V_68 , V_54 -> V_228 , 1 ) ;
F_362 ( V_54 -> V_228 ) ;
F_151 ( V_54 ) ;
return F_68 ( V_68 , 1 ) ;
}
static struct V_53 *
F_363 ( struct V_62 * V_68 , struct V_53 * V_54 )
{
if ( F_278 ( V_54 ) == 1 ) {
V_54 -> V_314 = V_248 -> V_314 ;
F_364 ( V_54 ) ;
F_365 ( V_54 ) ;
return V_54 ;
}
F_69 ( V_68 , NULL , 1 ) ;
F_300 ( V_54 ) ;
F_151 ( V_54 ) ;
return NULL ;
}
static int
F_366 ( struct V_250 * V_47 , struct V_110 * V_242 , struct V_245 * V_245 ,
T_5 V_351 )
{
struct V_49 * V_50 = V_47 -> V_70 -> V_71 ;
struct V_62 * V_68 = F_65 ( V_242 -> V_349 . V_64 ) ;
const int V_348 = F_360 ( V_242 ) ;
const bool V_69 = F_96 ( V_242 ) ;
struct V_53 * V_54 ;
F_176 ( V_47 -> V_48 ) ;
F_313 ( V_68 , V_245 ) ;
F_320 ( V_68 , V_245 ) ;
V_292:
V_54 = F_68 ( V_68 , V_69 ) ;
if ( ! V_54 || V_54 == & V_50 -> V_318 ) {
if ( V_54 )
F_151 ( V_54 ) ;
V_54 = F_314 ( V_50 , V_69 , V_68 , V_245 ) ;
F_69 ( V_68 , V_54 , V_69 ) ;
} else {
if ( F_249 ( V_54 ) && F_367 ( V_54 ) ) {
F_90 ( V_50 , V_54 , L_37 ) ;
V_54 = F_363 ( V_68 , V_54 ) ;
if ( ! V_54 )
goto V_292;
}
if ( V_54 -> V_228 )
V_54 = F_361 ( V_50 , V_68 , V_54 ) ;
}
V_54 -> V_281 [ V_348 ] ++ ;
V_54 -> V_284 ++ ;
F_36 ( V_54 -> V_3 ) ;
V_242 -> V_349 . V_350 [ 0 ] = V_54 ;
V_242 -> V_349 . V_350 [ 1 ] = V_54 -> V_3 ;
F_178 ( V_47 -> V_48 ) ;
return 0 ;
}
static void F_368 ( struct V_352 * V_353 )
{
struct V_49 * V_50 =
F_25 ( V_353 , struct V_49 , V_73 ) ;
struct V_250 * V_47 = V_50 -> V_67 ;
F_176 ( V_47 -> V_48 ) ;
F_342 ( V_50 -> V_67 ) ;
F_178 ( V_47 -> V_48 ) ;
}
static enum V_354 F_369 ( struct V_355 * V_356 )
{
struct V_49 * V_50 = F_25 ( V_356 , struct V_49 ,
V_262 ) ;
struct V_53 * V_54 ;
unsigned long V_357 ;
int V_263 = 1 ;
F_72 ( V_50 , L_38 ) ;
F_370 ( V_50 -> V_67 -> V_48 , V_357 ) ;
V_54 = V_50 -> V_261 ;
if ( V_54 ) {
V_263 = 0 ;
if ( F_286 ( V_54 ) )
goto V_358;
if ( F_91 ( V_54 ) )
goto V_293;
if ( ! V_50 -> V_72 )
goto V_359;
if ( ! F_215 ( & V_54 -> V_133 ) )
goto V_358;
F_288 ( V_54 ) ;
}
V_293:
F_253 ( V_50 , V_263 ) ;
V_358:
F_71 ( V_50 ) ;
V_359:
F_371 ( V_50 -> V_67 -> V_48 , V_357 ) ;
return V_360 ;
}
static void F_372 ( struct V_49 * V_50 )
{
F_373 ( & V_50 -> V_262 ) ;
F_374 ( & V_50 -> V_73 ) ;
}
static void F_375 ( struct V_361 * V_362 )
{
struct V_49 * V_50 = V_362 -> V_71 ;
struct V_250 * V_47 = V_50 -> V_67 ;
F_372 ( V_50 ) ;
F_176 ( V_47 -> V_48 ) ;
if ( V_50 -> V_261 )
F_246 ( V_50 , V_50 -> V_261 , 0 ) ;
F_178 ( V_47 -> V_48 ) ;
F_372 ( V_50 ) ;
#ifdef F_331
F_376 ( V_47 , & V_31 ) ;
#else
F_144 ( V_50 -> V_223 ) ;
#endif
F_144 ( V_50 ) ;
}
static int F_377 ( struct V_250 * V_47 , struct V_363 * V_362 )
{
struct V_49 * V_50 ;
struct V_29 * V_30 V_364 ;
int V_165 , V_200 ;
struct V_361 * V_365 ;
V_365 = F_378 ( V_47 , V_362 ) ;
if ( ! V_365 )
return - V_172 ;
V_50 = F_148 ( sizeof( * V_50 ) , V_366 , V_47 -> V_135 ) ;
if ( ! V_50 ) {
F_379 ( & V_365 -> V_367 ) ;
return - V_172 ;
}
V_365 -> V_71 = V_50 ;
V_50 -> V_67 = V_47 ;
F_176 ( V_47 -> V_48 ) ;
V_47 -> V_70 = V_365 ;
F_178 ( V_47 -> V_48 ) ;
V_50 -> V_151 = V_167 ;
#ifdef F_331
V_200 = F_380 ( V_47 , & V_31 ) ;
if ( V_200 )
goto V_368;
V_50 -> V_223 = F_29 ( V_47 -> V_369 ) ;
#else
V_200 = - V_172 ;
V_50 -> V_223 = F_148 ( sizeof( * V_50 -> V_223 ) ,
V_366 , V_50 -> V_67 -> V_135 ) ;
if ( ! V_50 -> V_223 )
goto V_368;
F_130 ( V_50 -> V_223 ) ;
V_50 -> V_223 -> V_141 = 2 * V_176 ;
V_50 -> V_223 -> V_143 = 2 * V_176 ;
#endif
for ( V_165 = 0 ; V_165 < V_370 ; V_165 ++ )
V_50 -> V_239 [ V_165 ] = V_371 ;
F_316 ( V_50 , & V_50 -> V_318 , 1 , 0 ) ;
V_50 -> V_318 . V_284 ++ ;
F_176 ( V_47 -> V_48 ) ;
F_157 ( & V_50 -> V_318 , V_50 -> V_223 ) ;
F_38 ( V_50 -> V_223 ) ;
F_178 ( V_47 -> V_48 ) ;
F_381 ( & V_50 -> V_262 , V_372 ,
V_274 ) ;
V_50 -> V_262 . V_373 = F_369 ;
F_382 ( & V_50 -> V_73 , F_368 ) ;
V_50 -> V_300 = V_300 ;
V_50 -> V_339 [ 0 ] = V_339 [ 0 ] ;
V_50 -> V_339 [ 1 ] = V_339 [ 1 ] ;
V_50 -> V_122 = V_122 ;
V_50 -> V_123 = V_123 ;
V_50 -> V_77 [ 0 ] = V_374 ;
V_50 -> V_77 [ 1 ] = V_375 ;
V_50 -> V_99 = V_99 ;
V_50 -> V_278 = V_278 ;
V_50 -> V_51 = V_51 ;
V_50 -> V_269 = V_269 ;
V_50 -> V_100 = 1 ;
V_50 -> V_52 = - 1 ;
V_50 -> V_302 = F_89 () - V_231 ;
return 0 ;
V_368:
F_144 ( V_50 ) ;
F_379 ( & V_365 -> V_367 ) ;
return V_200 ;
}
static void F_383 ( struct V_250 * V_47 )
{
struct V_361 * V_362 = V_47 -> V_70 ;
struct V_49 * V_50 = V_362 -> V_71 ;
if ( F_263 ( V_47 ) )
V_50 -> V_51 = 0 ;
F_384 ( V_47 ) ;
}
static T_6
F_385 ( unsigned int V_376 , char * V_377 )
{
return sprintf ( V_377 , L_6 , V_376 ) ;
}
static T_6
F_386 ( unsigned int * V_376 , const char * V_377 , T_7 V_61 )
{
char * V_225 = ( char * ) V_377 ;
* V_376 = F_387 ( V_225 , & V_225 , 10 ) ;
return V_61 ;
}
static int T_10 F_388 ( void )
{
int V_200 ;
#ifdef F_331
V_200 = F_389 ( & V_31 ) ;
if ( V_200 )
return V_200 ;
#else
V_269 = 0 ;
#endif
V_200 = - V_172 ;
V_306 = F_390 ( V_53 , 0 ) ;
if ( ! V_306 )
goto V_378;
V_200 = F_391 ( & V_379 ) ;
if ( V_200 )
goto V_380;
return 0 ;
V_380:
F_392 ( V_306 ) ;
V_378:
#ifdef F_331
F_393 ( & V_31 ) ;
#endif
return V_200 ;
}
static void T_11 F_394 ( void )
{
#ifdef F_331
F_393 ( & V_31 ) ;
#endif
F_395 ( & V_379 ) ;
F_392 ( V_306 ) ;
}
