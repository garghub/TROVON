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
static void
F_120 ( struct V_49 * V_50 , struct V_2 * V_3 )
{
struct V_1 * V_89 = & V_50 -> V_149 ;
struct V_2 * V_136 ;
struct V_126 * V_127 ;
V_3 -> V_134 ++ ;
if ( ! F_109 ( & V_3 -> V_126 ) )
return;
V_127 = F_121 ( & V_89 -> V_125 ) ;
if ( V_127 ) {
V_136 = F_81 ( V_127 ) ;
V_3 -> V_87 = V_136 -> V_87 + V_150 ;
} else
V_3 -> V_87 = V_89 -> V_86 ;
F_118 ( V_89 , V_3 ) ;
}
static void
F_122 ( struct V_1 * V_89 , struct V_2 * V_3 )
{
struct V_2 * V_145 = V_3 ;
bool V_146 ;
V_146 = ! -- V_145 -> V_147 ;
V_145 -> V_148 -= V_145 -> V_143 ;
while ( V_146 ) {
struct V_2 * V_34 = F_33 ( V_145 ) ;
F_123 ( V_145 -> V_148 ) ;
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
F_124 ( struct V_49 * V_50 , struct V_2 * V_3 )
{
struct V_1 * V_89 = & V_50 -> V_149 ;
F_21 ( V_3 -> V_134 < 1 ) ;
V_3 -> V_134 -- ;
if ( V_3 -> V_134 )
return;
F_125 ( V_50 , V_3 , L_3 ) ;
F_122 ( V_89 , V_3 ) ;
V_3 -> V_151 = 0 ;
F_13 ( V_3 ) ;
}
static inline T_2 F_126 ( struct V_53 * V_54 ,
T_2 * V_39 )
{
T_2 V_152 ;
T_2 V_12 = F_89 () ;
if ( ! V_54 -> V_107 || V_54 -> V_107 == V_12 ) {
V_152 = F_119 ( T_2 , ( V_12 - V_54 -> V_153 ) ,
F_127 ( 1 ) ) ;
} else {
V_152 = V_12 - V_54 -> V_107 ;
if ( V_152 > V_54 -> V_109 ) {
* V_39 = V_152 - V_54 -> V_109 ;
V_152 = V_54 -> V_109 ;
}
if ( V_54 -> V_107 > V_54 -> V_153 )
* V_39 += V_54 -> V_107 -
V_54 -> V_153 ;
}
return V_152 ;
}
static void F_128 ( struct V_49 * V_50 , struct V_2 * V_3 ,
struct V_53 * V_54 )
{
struct V_1 * V_89 = & V_50 -> V_149 ;
T_2 V_154 , V_82 , V_155 = 0 ;
int V_156 = V_3 -> V_134 - F_64 ( V_50 , V_3 )
- V_3 -> V_8 . V_61 ;
unsigned int V_144 ;
T_2 V_12 = F_89 () ;
F_21 ( V_156 < 0 ) ;
V_154 = V_82 = F_126 ( V_54 , & V_155 ) ;
if ( F_56 ( V_50 ) )
V_82 = V_54 -> V_157 ;
else if ( ! F_61 ( V_54 ) && ! V_156 )
V_82 = V_54 -> V_109 ;
V_144 = V_3 -> V_83 ;
F_122 ( V_89 , V_3 ) ;
V_3 -> V_87 += F_78 ( V_82 , V_144 ) ;
F_118 ( V_89 , V_3 ) ;
if ( V_50 -> V_158 > V_12 ) {
V_3 -> V_151 = V_50 -> V_158 - V_12 ;
V_3 -> V_159 = V_50 -> V_160 ;
V_3 -> V_161 = V_50 -> V_162 ;
} else
V_3 -> V_151 = 0 ;
F_125 ( V_50 , V_3 , L_4 , V_3 -> V_87 ,
V_89 -> V_86 ) ;
F_90 ( V_54 -> V_50 , V_54 ,
L_5 ,
V_154 , V_54 -> V_157 , V_82 ,
F_56 ( V_50 ) , V_54 -> V_163 ) ;
F_42 ( V_3 , V_154 , V_155 ) ;
F_14 ( V_3 ) ;
}
static void F_129 ( struct V_2 * V_3 )
{
struct V_1 * V_89 ;
int V_164 , V_165 ;
F_130 ( V_3 , V_164 , V_165 , V_89 )
* V_89 = V_166 ;
F_104 ( & V_3 -> V_126 ) ;
V_3 -> V_167 . V_168 = F_89 () ;
}
static void F_131 ( struct V_10 * V_11 )
{
F_132 ( & V_11 -> V_40 ) ;
F_132 ( & V_11 -> V_43 ) ;
F_132 ( & V_11 -> V_44 ) ;
F_132 ( & V_11 -> V_19 ) ;
F_133 ( & V_11 -> time ) ;
#ifdef F_43
F_133 ( & V_11 -> V_39 ) ;
F_133 ( & V_11 -> V_22 ) ;
F_133 ( & V_11 -> V_23 ) ;
F_133 ( & V_11 -> V_18 ) ;
F_133 ( & V_11 -> V_14 ) ;
F_133 ( & V_11 -> V_21 ) ;
F_133 ( & V_11 -> V_17 ) ;
#endif
}
static int F_134 ( struct V_10 * V_11 , T_5 V_169 )
{
if ( F_135 ( & V_11 -> V_40 , V_169 ) ||
F_135 ( & V_11 -> V_43 , V_169 ) ||
F_135 ( & V_11 -> V_44 , V_169 ) ||
F_135 ( & V_11 -> V_19 , V_169 ) ||
F_136 ( & V_11 -> time , V_169 ) )
goto V_170;
#ifdef F_43
if ( F_136 ( & V_11 -> V_39 , V_169 ) ||
F_136 ( & V_11 -> V_22 , V_169 ) ||
F_136 ( & V_11 -> V_23 , V_169 ) ||
F_136 ( & V_11 -> V_18 , V_169 ) ||
F_136 ( & V_11 -> V_14 , V_169 ) ||
F_136 ( & V_11 -> V_21 , V_169 ) ||
F_136 ( & V_11 -> V_17 , V_169 ) )
goto V_170;
#endif
return 0 ;
V_170:
F_131 ( V_11 ) ;
return - V_171 ;
}
static struct V_27 * F_137 ( T_5 V_169 )
{
struct V_26 * V_172 ;
V_172 = F_138 ( sizeof( * V_172 ) , V_169 ) ;
if ( ! V_172 )
return NULL ;
return & V_172 -> V_28 ;
}
static void F_139 ( struct V_27 * V_28 )
{
struct V_26 * V_172 = F_26 ( V_28 ) ;
unsigned int V_141 = F_140 ( V_173 ) ?
V_174 : V_175 ;
if ( F_141 ( V_28 ) == & V_176 )
V_141 *= 2 ;
V_172 -> V_141 = V_141 ;
V_172 -> V_143 = V_141 ;
}
static void F_142 ( struct V_27 * V_28 )
{
F_143 ( F_26 ( V_28 ) ) ;
}
static void F_144 ( struct V_27 * V_28 )
{
struct V_32 * V_32 = F_141 ( V_28 ) ;
bool V_177 = F_140 ( V_173 ) ;
unsigned int V_141 = V_177 ? V_174 : V_175 ;
if ( V_32 == & V_176 )
V_141 *= 2 ;
F_123 ( F_145 ( & V_32 -> V_36 , V_141 , V_177 , true , false ) ) ;
F_123 ( F_145 ( & V_32 -> V_36 , V_141 , V_177 , true , true ) ) ;
}
static struct V_24 * F_146 ( T_5 V_169 , int V_135 )
{
struct V_2 * V_3 ;
V_3 = F_147 ( sizeof( * V_3 ) , V_169 , V_135 ) ;
if ( ! V_3 )
return NULL ;
F_129 ( V_3 ) ;
if ( F_134 ( & V_3 -> V_11 , V_169 ) ) {
F_143 ( V_3 ) ;
return NULL ;
}
return & V_3 -> V_25 ;
}
static void F_148 ( struct V_24 * V_25 )
{
struct V_2 * V_3 = F_24 ( V_25 ) ;
struct V_26 * V_172 = F_31 ( V_25 -> V_30 -> V_32 ) ;
V_3 -> V_141 = V_172 -> V_141 ;
V_3 -> V_143 = V_172 -> V_143 ;
}
static void F_149 ( struct V_24 * V_25 )
{
struct V_2 * V_3 = F_24 ( V_25 ) ;
int V_164 ;
for ( V_164 = 0 ; V_164 < V_80 ; V_164 ++ ) {
if ( V_3 -> V_178 [ 0 ] [ V_164 ] )
F_150 ( V_3 -> V_178 [ 0 ] [ V_164 ] ) ;
if ( V_3 -> V_178 [ 1 ] [ V_164 ] )
F_150 ( V_3 -> V_178 [ 1 ] [ V_164 ] ) ;
}
if ( V_3 -> V_179 )
F_150 ( V_3 -> V_179 ) ;
F_53 ( V_3 ) ;
}
static void F_151 ( struct V_24 * V_25 )
{
struct V_2 * V_3 = F_24 ( V_25 ) ;
F_131 ( & V_3 -> V_11 ) ;
return F_143 ( V_3 ) ;
}
static void F_152 ( struct V_24 * V_25 )
{
struct V_2 * V_3 = F_24 ( V_25 ) ;
F_47 ( & V_3 -> V_11 ) ;
}
static struct V_2 * F_153 ( struct V_49 * V_50 ,
struct V_32 * V_32 )
{
struct V_29 * V_30 ;
V_30 = F_154 ( V_32 , V_50 -> V_67 ) ;
if ( F_155 ( V_30 ) )
return F_29 ( V_30 ) ;
return NULL ;
}
static void F_156 ( struct V_53 * V_54 , struct V_2 * V_3 )
{
V_54 -> V_3 = V_3 ;
F_36 ( V_3 ) ;
}
static T_2 F_157 ( struct V_180 * V_181 ,
struct V_24 * V_25 , int V_182 )
{
struct V_2 * V_3 = F_24 ( V_25 ) ;
if ( ! V_3 -> V_183 )
return 0 ;
return F_158 ( V_181 , V_25 , V_3 -> V_183 ) ;
}
static int F_159 ( struct V_180 * V_181 , void * V_184 )
{
F_160 ( V_181 , F_161 ( F_162 ( V_181 ) ) ,
F_157 , & V_31 ,
0 , false ) ;
return 0 ;
}
static T_2 F_163 ( struct V_180 * V_181 ,
struct V_24 * V_25 , int V_182 )
{
struct V_2 * V_3 = F_24 ( V_25 ) ;
if ( ! V_3 -> V_185 )
return 0 ;
return F_158 ( V_181 , V_25 , V_3 -> V_185 ) ;
}
static int F_164 ( struct V_180 * V_181 , void * V_184 )
{
F_160 ( V_181 , F_161 ( F_162 ( V_181 ) ) ,
F_163 , & V_31 ,
0 , false ) ;
return 0 ;
}
static int F_165 ( struct V_180 * V_181 , void * V_184 )
{
struct V_32 * V_32 = F_161 ( F_162 ( V_181 ) ) ;
struct V_26 * V_172 = F_31 ( V_32 ) ;
unsigned int V_186 = 0 ;
if ( V_172 )
V_186 = V_172 -> V_141 ;
F_166 ( V_181 , L_6 , V_186 ) ;
return 0 ;
}
static int F_167 ( struct V_180 * V_181 , void * V_184 )
{
struct V_32 * V_32 = F_161 ( F_162 ( V_181 ) ) ;
struct V_26 * V_172 = F_31 ( V_32 ) ;
unsigned int V_186 = 0 ;
if ( V_172 )
V_186 = V_172 -> V_143 ;
F_166 ( V_181 , L_6 , V_186 ) ;
return 0 ;
}
static T_6 F_168 ( struct V_187 * V_188 ,
char * V_189 , T_7 V_190 , T_8 V_182 ,
bool V_177 , bool V_191 )
{
unsigned int F_83 = V_177 ? V_192 : V_193 ;
unsigned int F_84 = V_177 ? V_194 : V_195 ;
struct V_32 * V_32 = F_161 ( F_169 ( V_188 ) ) ;
struct V_196 V_197 ;
struct V_2 * V_3 ;
struct V_26 * V_198 ;
int V_199 ;
T_2 V_184 ;
V_199 = F_170 ( V_32 , & V_31 , V_189 , & V_197 ) ;
if ( V_199 )
return V_199 ;
if ( sscanf ( V_197 . V_200 , L_7 , & V_184 ) == 1 ) {
V_199 = - V_201 ;
if ( ! V_184 && V_177 )
goto V_202;
} else if ( ! strcmp ( F_171 ( V_197 . V_200 ) , L_8 ) ) {
V_184 = 0 ;
} else {
V_199 = - V_203 ;
goto V_202;
}
V_3 = F_29 ( V_197 . V_30 ) ;
V_198 = F_31 ( V_32 ) ;
V_199 = - V_201 ;
if ( ! V_184 || ( V_184 >= F_83 && V_184 <= F_84 ) ) {
if ( ! V_191 ) {
V_3 -> V_183 = V_184 ;
V_3 -> V_140 = V_184 ? : V_198 -> V_141 ;
} else {
V_3 -> V_185 = V_184 ;
V_3 -> V_142 = V_184 ? : V_198 -> V_143 ;
}
V_199 = 0 ;
}
V_202:
F_172 ( & V_197 ) ;
return V_199 ? : V_190 ;
}
static T_6 F_173 ( struct V_187 * V_188 ,
char * V_189 , T_7 V_190 , T_8 V_182 )
{
return F_168 ( V_188 , V_189 , V_190 , V_182 , false , false ) ;
}
static T_6 F_174 ( struct V_187 * V_188 ,
char * V_189 , T_7 V_190 , T_8 V_182 )
{
return F_168 ( V_188 , V_189 , V_190 , V_182 , false , true ) ;
}
static int F_145 ( struct V_204 * V_36 , T_2 V_186 ,
bool V_177 , bool V_205 , bool V_191 )
{
unsigned int F_83 = V_177 ? V_192 : V_193 ;
unsigned int F_84 = V_177 ? V_194 : V_195 ;
struct V_32 * V_32 = F_161 ( V_36 ) ;
struct V_29 * V_30 ;
struct V_26 * V_198 ;
int V_199 = 0 ;
if ( V_186 < F_83 || V_186 > F_84 )
return - V_201 ;
F_175 ( & V_32 -> V_206 ) ;
V_198 = F_31 ( V_32 ) ;
if ( ! V_198 ) {
V_199 = - V_203 ;
goto V_207;
}
if ( ! V_191 )
V_198 -> V_141 = V_186 ;
else
V_198 -> V_143 = V_186 ;
F_176 (blkg, &blkcg->blkg_list, blkcg_node) {
struct V_2 * V_3 = F_29 ( V_30 ) ;
if ( ! V_3 )
continue;
if ( ! V_191 ) {
if ( V_205 )
V_3 -> V_183 = 0 ;
if ( ! V_3 -> V_183 )
V_3 -> V_140 = V_198 -> V_141 ;
} else {
if ( V_205 )
V_3 -> V_185 = 0 ;
if ( ! V_3 -> V_185 )
V_3 -> V_142 = V_198 -> V_143 ;
}
}
V_207:
F_177 ( & V_32 -> V_206 ) ;
return V_199 ;
}
static int F_178 ( struct V_204 * V_36 , struct V_208 * V_209 ,
T_2 V_186 )
{
return F_145 ( V_36 , V_186 , false , false , false ) ;
}
static int F_179 ( struct V_204 * V_36 ,
struct V_208 * V_209 , T_2 V_186 )
{
return F_145 ( V_36 , V_186 , false , false , true ) ;
}
static int F_180 ( struct V_180 * V_181 , void * V_184 )
{
F_160 ( V_181 , F_161 ( F_162 ( V_181 ) ) , V_210 ,
& V_31 , F_181 ( V_181 ) -> V_211 , false ) ;
return 0 ;
}
static int F_182 ( struct V_180 * V_181 , void * V_184 )
{
F_160 ( V_181 , F_161 ( F_162 ( V_181 ) ) , V_212 ,
& V_31 , F_181 ( V_181 ) -> V_211 , true ) ;
return 0 ;
}
static T_2 F_183 ( struct V_180 * V_181 ,
struct V_24 * V_25 , int V_182 )
{
T_2 V_213 = F_184 ( F_28 ( V_25 ) ,
& V_31 , V_182 ) ;
return F_158 ( V_181 , V_25 , V_213 ) ;
}
static T_2 F_185 ( struct V_180 * V_181 ,
struct V_24 * V_25 , int V_182 )
{
struct V_214 V_213 = F_186 ( F_28 ( V_25 ) ,
& V_31 , V_182 ) ;
return F_187 ( V_181 , V_25 , & V_213 ) ;
}
static int F_188 ( struct V_180 * V_181 , void * V_184 )
{
F_160 ( V_181 , F_161 ( F_162 ( V_181 ) ) ,
F_183 , & V_31 ,
F_181 ( V_181 ) -> V_211 , false ) ;
return 0 ;
}
static int F_189 ( struct V_180 * V_181 , void * V_184 )
{
F_160 ( V_181 , F_161 ( F_162 ( V_181 ) ) ,
F_185 , & V_31 ,
F_181 ( V_181 ) -> V_211 , true ) ;
return 0 ;
}
static T_2 F_190 ( struct V_180 * V_181 , struct V_24 * V_25 ,
int V_182 )
{
T_2 V_213 = F_15 ( & V_25 -> V_30 -> V_215 ) ;
return F_158 ( V_181 , V_25 , V_213 >> 9 ) ;
}
static int F_191 ( struct V_180 * V_181 , void * V_184 )
{
F_160 ( V_181 , F_161 ( F_162 ( V_181 ) ) ,
F_190 , & V_31 , 0 , false ) ;
return 0 ;
}
static T_2 F_192 ( struct V_180 * V_181 ,
struct V_24 * V_25 , int V_182 )
{
struct V_214 V_216 = F_186 ( V_25 -> V_30 , NULL ,
F_193 ( struct V_29 , V_215 ) ) ;
T_2 V_213 = F_194 ( & V_216 . V_217 [ V_218 ] ) +
F_194 ( & V_216 . V_217 [ V_219 ] ) ;
return F_158 ( V_181 , V_25 , V_213 >> 9 ) ;
}
static int F_195 ( struct V_180 * V_181 , void * V_184 )
{
F_160 ( V_181 , F_161 ( F_162 ( V_181 ) ) ,
F_192 , & V_31 , 0 ,
false ) ;
return 0 ;
}
static T_2 F_196 ( struct V_180 * V_181 ,
struct V_24 * V_25 , int V_182 )
{
struct V_2 * V_3 = F_24 ( V_25 ) ;
T_2 V_220 = F_197 ( & V_3 -> V_11 . V_23 ) ;
T_2 V_184 = 0 ;
if ( V_220 ) {
V_184 = F_197 ( & V_3 -> V_11 . V_22 ) ;
V_184 = F_87 ( V_184 , V_220 ) ;
}
F_158 ( V_181 , V_25 , V_184 ) ;
return 0 ;
}
static int F_198 ( struct V_180 * V_181 , void * V_184 )
{
F_160 ( V_181 , F_161 ( F_162 ( V_181 ) ) ,
F_196 , & V_31 ,
0 , false ) ;
return 0 ;
}
static int F_199 ( struct V_180 * V_181 , void * V_184 )
{
struct V_32 * V_32 = F_161 ( F_162 ( V_181 ) ) ;
struct V_26 * V_172 = F_31 ( V_32 ) ;
F_166 ( V_181 , L_9 , V_172 -> V_141 ) ;
F_160 ( V_181 , V_32 , F_157 ,
& V_31 , 0 , false ) ;
return 0 ;
}
static T_6 F_200 ( struct V_187 * V_188 ,
char * V_189 , T_7 V_190 , T_8 V_182 )
{
char * V_221 ;
int V_199 ;
T_2 V_184 ;
V_189 = F_171 ( V_189 ) ;
V_184 = F_201 ( V_189 , & V_221 , 0 ) ;
if ( * V_221 == '\0' || sscanf ( V_189 , L_10 , & V_184 ) == 1 ) {
V_199 = F_145 ( F_169 ( V_188 ) , V_184 , true , false , false ) ;
return V_199 ? : V_190 ;
}
return F_168 ( V_188 , V_189 , V_190 , V_182 , true , false ) ;
}
static struct V_2 * F_153 ( struct V_49 * V_50 ,
struct V_32 * V_32 )
{
return V_50 -> V_222 ;
}
static inline void
F_156 ( struct V_53 * V_54 , struct V_2 * V_3 ) {
V_54 -> V_3 = V_3 ;
}
static void F_202 ( struct V_49 * V_50 , struct V_53 * V_54 ,
bool V_223 )
{
struct V_126 * * V_224 , * V_34 ;
struct V_53 * V_225 ;
T_2 V_226 ;
struct V_1 * V_89 ;
int V_90 ;
int V_227 = 1 ;
T_2 V_12 = F_89 () ;
V_89 = F_1 ( V_54 -> V_3 , F_57 ( V_54 ) , F_60 ( V_54 ) ) ;
if ( F_58 ( V_54 ) ) {
V_226 = V_150 ;
V_34 = F_121 ( & V_89 -> V_125 ) ;
if ( V_34 && V_34 != & V_54 -> V_126 ) {
V_225 = F_100 ( V_34 , struct V_53 , V_126 ) ;
V_226 += V_225 -> V_226 ;
} else
V_226 += V_12 ;
} else if ( ! V_223 ) {
V_226 = F_111 ( V_50 , V_54 ) + V_12 ;
V_226 -= V_54 -> V_228 ;
V_54 -> V_228 = 0 ;
} else {
V_226 = - V_229 ;
V_225 = F_98 ( V_89 ) ;
V_226 += V_225 ? V_225 -> V_226 : V_12 ;
}
if ( ! F_109 ( & V_54 -> V_126 ) ) {
V_227 = 0 ;
if ( V_226 == V_54 -> V_226 && V_54 -> V_230 == V_89 )
return;
F_105 ( & V_54 -> V_126 , V_54 -> V_230 ) ;
V_54 -> V_230 = NULL ;
}
V_90 = 1 ;
V_34 = NULL ;
V_54 -> V_230 = V_89 ;
V_224 = & V_89 -> V_125 . V_126 ;
while ( * V_224 ) {
V_34 = * V_224 ;
V_225 = F_100 ( V_34 , struct V_53 , V_126 ) ;
if ( V_226 < V_225 -> V_226 )
V_224 = & V_34 -> V_138 ;
else {
V_224 = & V_34 -> V_139 ;
V_90 = 0 ;
}
}
if ( V_90 )
V_89 -> V_90 = & V_54 -> V_126 ;
V_54 -> V_226 = V_226 ;
F_114 ( & V_54 -> V_126 , V_34 , V_224 ) ;
F_115 ( & V_54 -> V_126 , & V_89 -> V_125 ) ;
V_89 -> V_61 ++ ;
if ( V_223 || ! V_227 )
return;
F_120 ( V_50 , V_54 -> V_3 ) ;
}
static struct V_53 *
F_203 ( struct V_49 * V_50 , struct V_128 * V_124 ,
T_4 V_231 , struct V_126 * * V_232 ,
struct V_126 * * * V_233 )
{
struct V_126 * * V_224 , * V_34 ;
struct V_53 * V_54 = NULL ;
V_34 = NULL ;
V_224 = & V_124 -> V_126 ;
while ( * V_224 ) {
struct V_126 * * V_127 ;
V_34 = * V_224 ;
V_54 = F_100 ( V_34 , struct V_53 , V_234 ) ;
if ( V_231 > F_97 ( V_54 -> V_235 ) )
V_127 = & ( * V_224 ) -> V_139 ;
else if ( V_231 < F_97 ( V_54 -> V_235 ) )
V_127 = & ( * V_224 ) -> V_138 ;
else
break;
V_224 = V_127 ;
V_54 = NULL ;
}
* V_232 = V_34 ;
if ( V_233 )
* V_233 = V_224 ;
return V_54 ;
}
static void F_204 ( struct V_49 * V_50 , struct V_53 * V_54 )
{
struct V_126 * * V_224 , * V_34 ;
struct V_53 * V_225 ;
if ( V_54 -> V_236 ) {
F_103 ( & V_54 -> V_234 , V_54 -> V_236 ) ;
V_54 -> V_236 = NULL ;
}
if ( F_58 ( V_54 ) )
return;
if ( ! V_54 -> V_235 )
return;
V_54 -> V_236 = & V_50 -> V_237 [ V_54 -> V_238 ] ;
V_225 = F_203 ( V_50 , V_54 -> V_236 ,
F_97 ( V_54 -> V_235 ) , & V_34 , & V_224 ) ;
if ( ! V_225 ) {
F_114 ( & V_54 -> V_234 , V_34 , V_224 ) ;
F_115 ( & V_54 -> V_234 , V_54 -> V_236 ) ;
} else
V_54 -> V_236 = NULL ;
}
static void F_205 ( struct V_49 * V_50 , struct V_53 * V_54 )
{
if ( F_206 ( V_54 ) ) {
F_202 ( V_50 , V_54 , 0 ) ;
F_204 ( V_50 , V_54 ) ;
}
}
static void F_207 ( struct V_49 * V_50 , struct V_53 * V_54 )
{
F_90 ( V_50 , V_54 , L_11 ) ;
F_21 ( F_206 ( V_54 ) ) ;
F_208 ( V_54 ) ;
V_50 -> V_72 ++ ;
if ( F_61 ( V_54 ) )
V_50 -> V_239 ++ ;
F_205 ( V_50 , V_54 ) ;
}
static void F_209 ( struct V_49 * V_50 , struct V_53 * V_54 )
{
F_90 ( V_50 , V_54 , L_12 ) ;
F_21 ( ! F_206 ( V_54 ) ) ;
F_210 ( V_54 ) ;
if ( ! F_109 ( & V_54 -> V_126 ) ) {
F_105 ( & V_54 -> V_126 , V_54 -> V_230 ) ;
V_54 -> V_230 = NULL ;
}
if ( V_54 -> V_236 ) {
F_103 ( & V_54 -> V_234 , V_54 -> V_236 ) ;
V_54 -> V_236 = NULL ;
}
F_124 ( V_50 , V_54 -> V_3 ) ;
F_21 ( ! V_50 -> V_72 ) ;
V_50 -> V_72 -- ;
if ( F_61 ( V_54 ) )
V_50 -> V_239 -- ;
}
static void F_211 ( struct V_110 * V_240 )
{
struct V_53 * V_54 = F_212 ( V_240 ) ;
const int V_74 = F_96 ( V_240 ) ;
F_21 ( ! V_54 -> V_19 [ V_74 ] ) ;
V_54 -> V_19 [ V_74 ] -- ;
F_213 ( & V_54 -> V_133 , V_240 ) ;
if ( F_206 ( V_54 ) && F_214 ( & V_54 -> V_133 ) ) {
if ( V_54 -> V_236 ) {
F_103 ( & V_54 -> V_234 , V_54 -> V_236 ) ;
V_54 -> V_236 = NULL ;
}
}
}
static void F_215 ( struct V_110 * V_240 )
{
struct V_53 * V_54 = F_212 ( V_240 ) ;
struct V_49 * V_50 = V_54 -> V_50 ;
struct V_110 * V_132 ;
V_54 -> V_19 [ F_96 ( V_240 ) ] ++ ;
F_216 ( & V_54 -> V_133 , V_240 ) ;
if ( ! F_206 ( V_54 ) )
F_207 ( V_50 , V_54 ) ;
V_132 = V_54 -> V_235 ;
V_54 -> V_235 = F_93 ( V_50 , V_54 -> V_235 , V_240 , V_50 -> V_241 ) ;
if ( V_132 != V_54 -> V_235 )
F_204 ( V_50 , V_54 ) ;
F_21 ( ! V_54 -> V_235 ) ;
}
static void F_217 ( struct V_53 * V_54 , struct V_110 * V_240 )
{
F_213 ( & V_54 -> V_133 , V_240 ) ;
V_54 -> V_19 [ F_96 ( V_240 ) ] -- ;
F_44 ( F_218 ( V_240 ) , V_240 -> V_120 ) ;
F_215 ( V_240 ) ;
F_40 ( F_218 ( V_240 ) , V_54 -> V_50 -> V_242 ,
V_240 -> V_120 ) ;
}
static struct V_110 *
F_219 ( struct V_49 * V_50 , struct V_243 * V_243 )
{
struct V_244 * V_245 = V_246 ;
struct V_62 * V_68 ;
struct V_53 * V_54 ;
V_68 = F_66 ( V_50 , V_245 -> V_65 ) ;
if ( ! V_68 )
return NULL ;
V_54 = F_68 ( V_68 , F_220 ( V_243 -> V_247 ) ) ;
if ( V_54 )
return F_221 ( & V_54 -> V_133 , F_222 ( V_243 ) ) ;
return NULL ;
}
static void F_223 ( struct V_248 * V_47 , struct V_110 * V_240 )
{
struct V_49 * V_50 = V_47 -> V_70 -> V_71 ;
V_50 -> V_249 ++ ;
F_90 ( V_50 , F_212 ( V_240 ) , L_13 ,
V_50 -> V_249 ) ;
V_50 -> V_241 = F_97 ( V_240 ) + F_224 ( V_240 ) ;
}
static void F_225 ( struct V_248 * V_47 , struct V_110 * V_240 )
{
struct V_49 * V_50 = V_47 -> V_70 -> V_71 ;
F_76 ( ! V_50 -> V_249 ) ;
V_50 -> V_249 -- ;
F_90 ( V_50 , F_212 ( V_240 ) , L_14 ,
V_50 -> V_249 ) ;
}
static void F_226 ( struct V_110 * V_240 )
{
struct V_53 * V_54 = F_212 ( V_240 ) ;
if ( V_54 -> V_235 == V_240 )
V_54 -> V_235 = F_106 ( V_54 -> V_50 , V_54 , V_240 ) ;
F_227 ( & V_240 -> V_250 ) ;
F_211 ( V_240 ) ;
V_54 -> V_50 -> V_251 -- ;
F_44 ( F_218 ( V_240 ) , V_240 -> V_120 ) ;
if ( V_240 -> V_120 & V_121 ) {
F_76 ( ! V_54 -> V_252 ) ;
V_54 -> V_252 -- ;
}
}
static int F_228 ( struct V_248 * V_47 , struct V_110 * * V_253 ,
struct V_243 * V_243 )
{
struct V_49 * V_50 = V_47 -> V_70 -> V_71 ;
struct V_110 * V_254 ;
V_254 = F_219 ( V_50 , V_243 ) ;
if ( V_254 && F_229 ( V_254 , V_243 ) ) {
* V_253 = V_254 ;
return V_255 ;
}
return V_256 ;
}
static void F_230 ( struct V_248 * V_47 , struct V_110 * V_253 ,
int type )
{
if ( type == V_255 ) {
struct V_53 * V_54 = F_212 ( V_253 ) ;
F_217 ( V_54 , V_253 ) ;
}
}
static void F_231 ( struct V_248 * V_47 , struct V_110 * V_253 ,
struct V_243 * V_243 )
{
F_45 ( F_218 ( V_253 ) , V_243 -> V_247 ) ;
}
static void
F_232 ( struct V_248 * V_47 , struct V_110 * V_240 ,
struct V_110 * V_131 )
{
struct V_53 * V_54 = F_212 ( V_240 ) ;
struct V_49 * V_50 = V_47 -> V_70 -> V_71 ;
if ( ! F_233 ( & V_240 -> V_250 ) && ! F_233 ( & V_131 -> V_250 ) &&
V_131 -> V_257 < V_240 -> V_257 &&
V_54 == F_212 ( V_131 ) ) {
F_234 ( & V_240 -> V_250 , & V_131 -> V_250 ) ;
V_240 -> V_257 = V_131 -> V_257 ;
}
if ( V_54 -> V_235 == V_131 )
V_54 -> V_235 = V_240 ;
F_226 ( V_131 ) ;
F_45 ( F_218 ( V_240 ) , V_131 -> V_120 ) ;
V_54 = F_212 ( V_131 ) ;
if ( F_206 ( V_54 ) && F_214 ( & V_54 -> V_133 ) &&
V_54 != V_50 -> V_258 )
F_209 ( V_50 , V_54 ) ;
}
static int F_235 ( struct V_248 * V_47 , struct V_110 * V_240 ,
struct V_243 * V_243 )
{
struct V_49 * V_50 = V_47 -> V_70 -> V_71 ;
bool V_69 = F_220 ( V_243 -> V_247 ) ;
struct V_62 * V_68 ;
struct V_53 * V_54 ;
if ( V_69 && ! F_96 ( V_240 ) )
return false ;
V_68 = F_66 ( V_50 , V_246 -> V_65 ) ;
if ( ! V_68 )
return false ;
V_54 = F_68 ( V_68 , V_69 ) ;
return V_54 == F_212 ( V_240 ) ;
}
static int F_236 ( struct V_248 * V_47 , struct V_110 * V_240 ,
struct V_110 * V_131 )
{
return F_212 ( V_240 ) == F_212 ( V_131 ) ;
}
static inline void F_237 ( struct V_49 * V_50 , struct V_53 * V_54 )
{
F_238 ( & V_50 -> V_259 ) ;
F_17 ( V_54 -> V_3 ) ;
}
static void F_239 ( struct V_49 * V_50 ,
struct V_53 * V_54 )
{
if ( V_54 ) {
F_90 ( V_50 , V_54 , L_15 ,
V_50 -> V_162 , V_50 -> V_160 ) ;
F_23 ( V_54 -> V_3 ) ;
V_54 -> V_107 = 0 ;
V_54 -> V_153 = F_89 () ;
V_54 -> V_109 = 0 ;
V_54 -> V_108 = 0 ;
V_54 -> V_157 = 0 ;
V_54 -> V_163 = 0 ;
F_240 ( V_54 ) ;
F_241 ( V_54 ) ;
F_242 ( V_54 ) ;
F_243 ( V_54 ) ;
F_244 ( V_54 ) ;
F_237 ( V_50 , V_54 ) ;
}
V_50 -> V_258 = V_54 ;
}
static void
F_245 ( struct V_49 * V_50 , struct V_53 * V_54 ,
bool V_260 )
{
F_90 ( V_50 , V_54 , L_16 , V_260 ) ;
if ( F_246 ( V_54 ) )
F_237 ( V_50 , V_54 ) ;
F_240 ( V_54 ) ;
F_247 ( V_54 ) ;
if ( F_248 ( V_54 ) && F_249 ( V_54 ) )
F_250 ( V_54 ) ;
if ( V_260 ) {
if ( F_92 ( V_54 ) )
V_54 -> V_228 = F_86 ( V_50 , V_54 ) ;
else
V_54 -> V_228 = V_54 -> V_108 - F_89 () ;
F_90 ( V_50 , V_54 , L_17 , V_54 -> V_228 ) ;
}
F_128 ( V_50 , V_54 -> V_3 , V_54 ) ;
if ( F_206 ( V_54 ) && F_214 ( & V_54 -> V_133 ) )
F_209 ( V_50 , V_54 ) ;
F_205 ( V_50 , V_54 ) ;
if ( V_54 == V_50 -> V_258 )
V_50 -> V_258 = NULL ;
if ( V_50 -> V_261 ) {
F_251 ( V_50 -> V_261 -> V_64 . V_66 ) ;
V_50 -> V_261 = NULL ;
}
}
static inline void F_252 ( struct V_49 * V_50 , bool V_260 )
{
struct V_53 * V_54 = V_50 -> V_258 ;
if ( V_54 )
F_245 ( V_50 , V_54 , V_260 ) ;
}
static struct V_53 * F_253 ( struct V_49 * V_50 )
{
struct V_1 * V_89 = F_1 ( V_50 -> V_242 ,
V_50 -> V_162 , V_50 -> V_160 ) ;
if ( ! V_50 -> V_251 )
return NULL ;
if ( ! V_89 )
return NULL ;
if ( F_214 ( & V_89 -> V_125 ) )
return NULL ;
return F_98 ( V_89 ) ;
}
static struct V_53 * F_254 ( struct V_49 * V_50 )
{
struct V_2 * V_3 ;
struct V_53 * V_54 ;
int V_164 , V_165 ;
struct V_1 * V_89 ;
if ( ! V_50 -> V_251 )
return NULL ;
V_3 = F_255 ( V_50 ) ;
if ( ! V_3 )
return NULL ;
F_130 (cfqg, i, j, st)
if ( ( V_54 = F_98 ( V_89 ) ) != NULL )
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
struct V_110 * V_240 )
{
if ( F_97 ( V_240 ) >= V_50 -> V_241 )
return F_97 ( V_240 ) - V_50 -> V_241 ;
else
return V_50 -> V_241 - F_97 ( V_240 ) ;
}
static inline int F_258 ( struct V_49 * V_50 , struct V_53 * V_54 ,
struct V_110 * V_240 )
{
return F_257 ( V_50 , V_240 ) <= V_262 ;
}
static struct V_53 * F_259 ( struct V_49 * V_50 ,
struct V_53 * V_263 )
{
struct V_128 * V_124 = & V_50 -> V_237 [ V_263 -> V_238 ] ;
struct V_126 * V_34 , * V_135 ;
struct V_53 * V_225 ;
T_4 V_231 = V_50 -> V_241 ;
if ( F_214 ( V_124 ) )
return NULL ;
V_225 = F_203 ( V_50 , V_124 , V_231 , & V_34 , NULL ) ;
if ( V_225 )
return V_225 ;
V_225 = F_100 ( V_34 , struct V_53 , V_234 ) ;
if ( F_258 ( V_50 , V_263 , V_225 -> V_235 ) )
return V_225 ;
if ( F_97 ( V_225 -> V_235 ) < V_231 )
V_135 = F_107 ( & V_225 -> V_234 ) ;
else
V_135 = F_108 ( & V_225 -> V_234 ) ;
if ( ! V_135 )
return NULL ;
V_225 = F_100 ( V_135 , struct V_53 , V_234 ) ;
if ( F_258 ( V_50 , V_263 , V_225 -> V_235 ) )
return V_225 ;
return NULL ;
}
static struct V_53 * F_260 ( struct V_49 * V_50 ,
struct V_53 * V_263 )
{
struct V_53 * V_54 ;
if ( F_58 ( V_263 ) )
return NULL ;
if ( ! F_61 ( V_263 ) )
return NULL ;
if ( F_249 ( V_263 ) )
return NULL ;
if ( V_263 -> V_3 -> V_134 == 1 )
return NULL ;
V_54 = F_259 ( V_50 , V_263 ) ;
if ( ! V_54 )
return NULL ;
if ( V_263 -> V_3 != V_54 -> V_3 )
return NULL ;
if ( ! F_61 ( V_54 ) )
return NULL ;
if ( F_249 ( V_54 ) )
return NULL ;
if ( F_59 ( V_54 ) != F_59 ( V_263 ) )
return NULL ;
return V_54 ;
}
static bool F_261 ( struct V_49 * V_50 , struct V_53 * V_54 )
{
enum V_4 V_60 = F_57 ( V_54 ) ;
struct V_1 * V_89 = V_54 -> V_230 ;
F_21 ( ! V_89 ) ;
F_21 ( ! V_89 -> V_61 ) ;
if ( ! V_50 -> V_51 )
return false ;
if ( V_60 == V_7 )
return false ;
if ( F_62 ( V_54 ) &&
! ( F_262 ( V_50 -> V_67 ) && V_50 -> V_52 ) )
return true ;
if ( V_89 -> V_61 == 1 && F_61 ( V_54 ) &&
! F_263 ( V_50 , & V_89 -> V_167 , false ) )
return true ;
F_90 ( V_50 , V_54 , L_18 , V_89 -> V_61 ) ;
return false ;
}
static void F_264 ( struct V_49 * V_50 )
{
struct V_53 * V_54 = V_50 -> V_258 ;
struct V_1 * V_89 = V_54 -> V_230 ;
struct V_62 * V_68 ;
T_2 V_264 , V_265 = 0 ;
T_2 V_12 = F_89 () ;
if ( F_262 ( V_50 -> V_67 ) && V_50 -> V_52 )
return;
F_76 ( ! F_214 ( & V_54 -> V_133 ) ) ;
F_76 ( F_92 ( V_54 ) ) ;
if ( ! F_261 ( V_50 , V_54 ) ) {
if ( V_50 -> V_266 )
V_265 = V_50 -> V_266 ;
else
return;
}
if ( V_54 -> V_267 )
return;
V_68 = V_50 -> V_261 ;
if ( ! V_68 || ! F_265 ( & V_68 -> V_64 . V_66 -> V_268 ) )
return;
if ( F_266 ( V_68 -> V_167 . V_269 ) &&
( V_54 -> V_108 - V_12 < V_68 -> V_167 . V_270 ) ) {
F_90 ( V_50 , V_54 , L_19 ,
V_68 -> V_167 . V_270 ) ;
return;
}
if ( V_265 &&
( V_54 -> V_3 -> V_134 > 1 ||
F_263 ( V_50 , & V_89 -> V_167 , true ) ) )
return;
F_267 ( V_54 ) ;
if ( V_265 )
V_264 = V_50 -> V_266 ;
else
V_264 = V_50 -> V_51 ;
F_268 ( & V_50 -> V_259 , F_269 ( V_264 ) ,
V_271 ) ;
F_20 ( V_54 -> V_3 ) ;
F_90 ( V_50 , V_54 , L_20 , V_264 ,
V_265 ? 1 : 0 ) ;
}
static void F_270 ( struct V_248 * V_47 , struct V_110 * V_240 )
{
struct V_49 * V_50 = V_47 -> V_70 -> V_71 ;
struct V_53 * V_54 = F_212 ( V_240 ) ;
F_90 ( V_50 , V_54 , L_21 ) ;
V_54 -> V_235 = F_106 ( V_50 , V_54 , V_240 ) ;
F_226 ( V_240 ) ;
V_54 -> V_267 ++ ;
( F_218 ( V_240 ) ) -> V_267 ++ ;
F_271 ( V_47 , V_240 ) ;
V_50 -> V_272 [ F_61 ( V_54 ) ] ++ ;
V_54 -> V_163 += F_224 ( V_240 ) ;
}
static struct V_110 * F_272 ( struct V_53 * V_54 )
{
struct V_110 * V_240 = NULL ;
if ( F_273 ( V_54 ) )
return NULL ;
F_274 ( V_54 ) ;
if ( F_233 ( & V_54 -> V_273 ) )
return NULL ;
V_240 = F_275 ( V_54 -> V_273 . V_131 ) ;
if ( F_89 () < V_240 -> V_257 )
V_240 = NULL ;
return V_240 ;
}
static inline int
F_276 ( struct V_49 * V_50 , struct V_53 * V_54 )
{
const int V_274 = V_50 -> V_275 ;
F_76 ( V_54 -> V_81 >= V_80 ) ;
return 2 * V_274 * ( V_80 - V_54 -> V_81 ) ;
}
static int F_277 ( struct V_53 * V_54 )
{
int V_276 , V_277 ;
V_277 = V_54 -> V_278 [ V_279 ] + V_54 -> V_278 [ V_280 ] ;
V_276 = V_54 -> V_281 - V_277 ;
F_21 ( V_276 < 0 ) ;
return V_276 ;
}
static void F_278 ( struct V_53 * V_54 , struct V_53 * V_227 )
{
int V_276 , V_282 ;
struct V_53 * V_225 ;
if ( ! F_277 ( V_227 ) )
return;
while ( ( V_225 = V_227 -> V_227 ) ) {
if ( V_225 == V_54 )
return;
V_227 = V_225 ;
}
V_276 = F_277 ( V_54 ) ;
V_282 = F_277 ( V_227 ) ;
if ( V_276 == 0 || V_282 == 0 )
return;
if ( V_282 >= V_276 ) {
V_54 -> V_227 = V_227 ;
V_227 -> V_281 += V_276 ;
} else {
V_227 -> V_227 = V_54 ;
V_54 -> V_281 += V_282 ;
}
}
static enum V_6 F_279 ( struct V_49 * V_50 ,
struct V_2 * V_3 , enum V_4 V_60 )
{
struct V_53 * V_67 ;
int V_164 ;
bool V_283 = false ;
T_2 V_284 = 0 ;
enum V_6 V_285 = V_58 ;
for ( V_164 = 0 ; V_164 <= V_59 ; ++ V_164 ) {
V_67 = F_98 ( F_1 ( V_3 , V_60 , V_164 ) ) ;
if ( V_67 &&
( ! V_283 || V_67 -> V_226 < V_284 ) ) {
V_284 = V_67 -> V_226 ;
V_285 = V_164 ;
V_283 = true ;
}
}
return V_285 ;
}
static void
F_280 ( struct V_49 * V_50 , struct V_2 * V_3 )
{
T_2 V_78 ;
unsigned V_61 ;
struct V_1 * V_89 ;
T_2 V_104 ;
enum V_4 V_286 = V_50 -> V_162 ;
T_2 V_12 = F_89 () ;
if ( F_63 ( V_55 , V_50 , V_3 ) )
V_50 -> V_162 = V_55 ;
else if ( F_63 ( V_56 , V_50 , V_3 ) )
V_50 -> V_162 = V_56 ;
else {
V_50 -> V_162 = V_7 ;
V_50 -> V_158 = V_12 + F_127 ( 1 ) ;
return;
}
if ( V_286 != V_50 -> V_162 )
goto V_287;
V_89 = F_1 ( V_3 , V_50 -> V_162 , V_50 -> V_160 ) ;
V_61 = V_89 -> V_61 ;
if ( V_61 && ! ( V_12 > V_50 -> V_158 ) )
return;
V_287:
V_50 -> V_160 = F_279 ( V_50 , V_3 ,
V_50 -> V_162 ) ;
V_89 = F_1 ( V_3 , V_50 -> V_162 , V_50 -> V_160 ) ;
V_61 = V_89 -> V_61 ;
V_104 = F_85 ( V_50 , V_3 ) ;
V_78 = F_75 ( V_104 * V_61 ,
F_119 ( unsigned , V_3 -> V_98 [ V_50 -> V_162 ] ,
F_63 ( V_50 -> V_162 , V_50 ,
V_3 ) ) ) ;
if ( V_50 -> V_160 == V_57 ) {
T_2 V_216 ;
V_216 = V_50 -> V_99 *
F_64 ( V_50 , V_3 ) ;
V_216 = F_75 ( V_216 , V_50 -> V_72 ) ;
V_78 = F_281 ( T_2 , V_78 , V_216 ) ;
V_78 = F_87 ( V_78 * V_50 -> V_77 [ 0 ] , V_50 -> V_77 [ 1 ] ) ;
} else
V_78 = F_84 ( V_78 , 2 * V_50 -> V_51 ) ;
V_78 = F_119 ( T_2 , V_78 , V_288 ) ;
F_72 ( V_50 , L_22 , V_78 ) ;
V_50 -> V_158 = V_12 + V_78 ;
}
static struct V_2 * F_255 ( struct V_49 * V_50 )
{
struct V_1 * V_89 = & V_50 -> V_149 ;
struct V_2 * V_3 ;
if ( F_214 ( & V_89 -> V_125 ) )
return NULL ;
V_3 = F_101 ( V_89 ) ;
F_80 ( V_89 ) ;
return V_3 ;
}
static void F_282 ( struct V_49 * V_50 )
{
struct V_2 * V_3 = F_255 ( V_50 ) ;
T_2 V_12 = F_89 () ;
V_50 -> V_242 = V_3 ;
if ( V_3 -> V_151 ) {
V_50 -> V_158 = V_12 + V_3 -> V_151 ;
V_50 -> V_160 = V_3 -> V_159 ;
V_50 -> V_162 = V_3 -> V_161 ;
} else
V_50 -> V_158 = V_12 - 1 ;
F_280 ( V_50 , V_3 ) ;
}
static struct V_53 * F_283 ( struct V_49 * V_50 )
{
struct V_53 * V_54 , * V_227 = NULL ;
T_2 V_12 = F_89 () ;
V_54 = V_50 -> V_258 ;
if ( ! V_54 )
goto V_289;
if ( ! V_50 -> V_251 )
return NULL ;
if ( F_284 ( V_54 ) && ! F_214 ( & V_54 -> V_133 ) )
goto V_290;
if ( F_91 ( V_54 ) && ! F_285 ( V_54 ) ) {
if ( V_54 -> V_3 -> V_134 == 1 && F_214 ( & V_54 -> V_133 )
&& V_54 -> V_267 && F_261 ( V_50 , V_54 ) ) {
V_54 = NULL ;
goto V_291;
} else
goto V_292;
}
if ( ! F_214 ( & V_54 -> V_133 ) )
goto V_291;
V_227 = F_260 ( V_50 , V_54 ) ;
if ( V_227 ) {
if ( ! V_54 -> V_227 )
F_278 ( V_54 , V_227 ) ;
goto V_290;
}
if ( F_286 ( & V_50 -> V_259 ) ) {
V_54 = NULL ;
goto V_291;
}
if ( F_249 ( V_54 ) && F_62 ( V_54 ) &&
( F_92 ( V_54 ) ||
( V_54 -> V_108 - V_12 > V_12 - V_54 -> V_107 ) ) ) {
F_287 ( V_54 ) ;
F_288 ( V_54 ) ;
}
if ( V_54 -> V_267 && F_261 ( V_50 , V_54 ) ) {
V_54 = NULL ;
goto V_291;
}
V_292:
if ( V_50 -> V_266 && V_54 -> V_3 -> V_134 == 1 &&
V_54 -> V_3 -> V_267 &&
! F_263 ( V_50 , & V_54 -> V_3 -> V_167 , true ) ) {
V_54 = NULL ;
goto V_291;
}
V_290:
F_252 ( V_50 , 0 ) ;
V_289:
if ( ! V_227 )
F_282 ( V_50 ) ;
V_54 = F_256 ( V_50 , V_227 ) ;
V_291:
return V_54 ;
}
static int F_289 ( struct V_53 * V_54 )
{
int V_267 = 0 ;
while ( V_54 -> V_235 ) {
F_270 ( V_54 -> V_50 -> V_67 , V_54 -> V_235 ) ;
V_267 ++ ;
}
F_21 ( ! F_233 ( & V_54 -> V_273 ) ) ;
F_245 ( V_54 -> V_50 , V_54 , 0 ) ;
return V_267 ;
}
static int F_290 ( struct V_49 * V_50 )
{
struct V_53 * V_54 ;
int V_267 = 0 ;
F_252 ( V_50 , 0 ) ;
while ( ( V_54 = F_254 ( V_50 ) ) != NULL ) {
F_239 ( V_50 , V_54 ) ;
V_267 += F_289 ( V_54 ) ;
}
F_21 ( V_50 -> V_72 ) ;
F_72 ( V_50 , L_23 , V_267 ) ;
return V_267 ;
}
static inline bool F_291 ( struct V_49 * V_50 ,
struct V_53 * V_54 )
{
T_2 V_12 = F_89 () ;
if ( F_92 ( V_54 ) )
return true ;
if ( V_12 + V_50 -> V_51 * V_54 -> V_267 > V_54 -> V_108 )
return true ;
return false ;
}
static bool F_292 ( struct V_49 * V_50 , struct V_53 * V_54 )
{
unsigned int V_293 ;
if ( F_285 ( V_54 ) )
return true ;
if ( F_261 ( V_50 , V_54 ) && V_50 -> V_272 [ V_294 ] )
return false ;
if ( V_50 -> V_272 [ V_295 ] && ! F_61 ( V_54 ) )
return false ;
V_293 = F_119 (unsigned int, cfqd->cfq_quantum / 2 , 1 ) ;
if ( F_58 ( V_54 ) )
V_293 = 1 ;
if ( V_54 -> V_267 >= V_293 ) {
bool V_296 = false ;
if ( F_58 ( V_54 ) )
return false ;
if ( F_61 ( V_54 ) && V_50 -> V_239 == 1 )
V_296 = true ;
if ( V_50 -> V_72 > 1 && F_291 ( V_50 , V_54 ) &&
! V_296 )
return false ;
if ( V_50 -> V_72 == 1 || V_296 )
V_293 = - 1 ;
else
V_293 = V_50 -> V_297 ;
}
if ( ! F_61 ( V_54 ) && V_50 -> V_100 ) {
T_2 V_298 = F_89 () - V_50 -> V_299 ;
unsigned int V_300 ;
V_300 = F_87 ( V_298 , V_50 -> V_77 [ 1 ] ) ;
if ( ! V_300 && ! V_54 -> V_267 )
V_300 = 1 ;
if ( V_300 < V_293 )
V_293 = V_300 ;
}
return V_54 -> V_267 < V_293 ;
}
static bool F_293 ( struct V_49 * V_50 , struct V_53 * V_54 )
{
struct V_110 * V_240 ;
F_21 ( F_214 ( & V_54 -> V_133 ) ) ;
V_240 = F_272 ( V_54 ) ;
if ( V_240 )
F_294 ( V_54 ) ;
if ( ! F_292 ( V_50 , V_54 ) )
return false ;
if ( ! V_240 )
V_240 = V_54 -> V_235 ;
else
F_90 ( V_54 -> V_50 , V_54 , L_24 , V_240 ) ;
F_270 ( V_50 -> V_67 , V_240 ) ;
if ( ! V_50 -> V_261 ) {
struct V_62 * V_68 = F_295 ( V_240 ) ;
F_296 ( & V_68 -> V_64 . V_66 -> V_301 ) ;
V_50 -> V_261 = V_68 ;
}
return true ;
}
static int F_297 ( struct V_248 * V_47 , int V_302 )
{
struct V_49 * V_50 = V_47 -> V_70 -> V_71 ;
struct V_53 * V_54 ;
if ( ! V_50 -> V_72 )
return 0 ;
if ( F_55 ( V_302 ) )
return F_290 ( V_50 ) ;
V_54 = F_283 ( V_50 ) ;
if ( ! V_54 )
return 0 ;
if ( ! F_293 ( V_50 , V_54 ) )
return 0 ;
V_54 -> V_157 ++ ;
F_241 ( V_54 ) ;
if ( V_50 -> V_72 > 1 && ( ( ! F_61 ( V_54 ) &&
V_54 -> V_157 >= F_276 ( V_50 , V_54 ) ) ||
F_58 ( V_54 ) ) ) {
V_54 -> V_108 = F_89 () + 1 ;
F_252 ( V_50 , 0 ) ;
}
F_90 ( V_50 , V_54 , L_25 ) ;
return 1 ;
}
static void F_150 ( struct V_53 * V_54 )
{
struct V_49 * V_50 = V_54 -> V_50 ;
struct V_2 * V_3 ;
F_21 ( V_54 -> V_281 <= 0 ) ;
V_54 -> V_281 -- ;
if ( V_54 -> V_281 )
return;
F_90 ( V_50 , V_54 , L_26 ) ;
F_21 ( F_99 ( & V_54 -> V_133 ) ) ;
F_21 ( V_54 -> V_278 [ V_279 ] + V_54 -> V_278 [ V_280 ] ) ;
V_3 = V_54 -> V_3 ;
if ( F_55 ( V_50 -> V_258 == V_54 ) ) {
F_245 ( V_50 , V_54 , 0 ) ;
F_71 ( V_50 ) ;
}
F_21 ( F_206 ( V_54 ) ) ;
F_298 ( V_303 , V_54 ) ;
F_38 ( V_3 ) ;
}
static void F_299 ( struct V_53 * V_54 )
{
struct V_53 * V_225 , * V_131 ;
V_225 = V_54 -> V_227 ;
while ( V_225 ) {
if ( V_225 == V_54 ) {
F_300 ( 1 , L_27 ) ;
break;
}
V_131 = V_225 -> V_227 ;
F_150 ( V_225 ) ;
V_225 = V_131 ;
}
}
static void F_301 ( struct V_49 * V_50 , struct V_53 * V_54 )
{
if ( F_55 ( V_54 == V_50 -> V_258 ) ) {
F_245 ( V_50 , V_54 , 0 ) ;
F_71 ( V_50 ) ;
}
F_299 ( V_54 ) ;
F_150 ( V_54 ) ;
}
static void F_302 ( struct V_63 * V_64 )
{
struct V_62 * V_68 = F_65 ( V_64 ) ;
V_68 -> V_167 . V_168 = F_89 () ;
}
static void F_303 ( struct V_63 * V_64 )
{
struct V_62 * V_68 = F_65 ( V_64 ) ;
struct V_49 * V_50 = F_70 ( V_68 ) ;
if ( F_68 ( V_68 , false ) ) {
F_301 ( V_50 , F_68 ( V_68 , false ) ) ;
F_69 ( V_68 , NULL , false ) ;
}
if ( F_68 ( V_68 , true ) ) {
F_301 ( V_50 , F_68 ( V_68 , true ) ) ;
F_69 ( V_68 , NULL , true ) ;
}
}
static void F_304 ( struct V_53 * V_54 , struct V_62 * V_68 )
{
struct V_244 * V_245 = V_246 ;
int V_304 ;
if ( ! F_305 ( V_54 ) )
return;
V_304 = F_306 ( V_68 -> V_81 ) ;
switch ( V_304 ) {
default:
F_307 ( V_305 L_28 , V_304 ) ;
case V_306 :
V_54 -> V_81 = F_308 ( V_245 ) ;
V_54 -> V_304 = F_309 ( V_245 ) ;
break;
case V_307 :
V_54 -> V_81 = F_310 ( V_68 -> V_81 ) ;
V_54 -> V_304 = V_307 ;
break;
case V_308 :
V_54 -> V_81 = F_310 ( V_68 -> V_81 ) ;
V_54 -> V_304 = V_308 ;
break;
case V_309 :
V_54 -> V_304 = V_309 ;
V_54 -> V_81 = 7 ;
F_288 ( V_54 ) ;
break;
}
V_54 -> V_238 = V_54 -> V_81 ;
V_54 -> V_310 = V_54 -> V_304 ;
F_311 ( V_54 ) ;
}
static void F_312 ( struct V_62 * V_68 , struct V_243 * V_243 )
{
int V_81 = V_68 -> V_64 . V_66 -> V_81 ;
struct V_49 * V_50 = F_70 ( V_68 ) ;
struct V_53 * V_54 ;
if ( F_55 ( ! V_50 ) || F_155 ( V_68 -> V_81 == V_81 ) )
return;
V_54 = F_68 ( V_68 , false ) ;
if ( V_54 ) {
F_150 ( V_54 ) ;
V_54 = F_313 ( V_50 , V_294 , V_68 , V_243 ) ;
F_69 ( V_68 , V_54 , false ) ;
}
V_54 = F_68 ( V_68 , true ) ;
if ( V_54 )
F_314 ( V_54 ) ;
V_68 -> V_81 = V_81 ;
}
static void F_315 ( struct V_49 * V_50 , struct V_53 * V_54 ,
T_9 V_311 , bool V_69 )
{
F_104 ( & V_54 -> V_126 ) ;
F_104 ( & V_54 -> V_234 ) ;
F_316 ( & V_54 -> V_273 ) ;
V_54 -> V_281 = 0 ;
V_54 -> V_50 = V_50 ;
F_314 ( V_54 ) ;
if ( V_69 ) {
if ( ! F_58 ( V_54 ) )
F_317 ( V_54 ) ;
F_318 ( V_54 ) ;
}
V_54 -> V_311 = V_311 ;
}
static bool F_319 ( struct V_62 * V_68 , struct V_243 * V_243 )
{
struct V_49 * V_50 = F_70 ( V_68 ) ;
struct V_53 * V_54 ;
T_1 V_312 ;
bool V_313 ;
F_320 () ;
V_312 = F_321 ( V_243 ) -> V_36 . V_312 ;
V_313 = F_321 ( V_243 ) != & V_176 ;
F_322 () ;
if ( F_55 ( ! V_50 ) || F_155 ( V_68 -> V_314 == V_312 ) )
return V_313 ;
V_54 = F_68 ( V_68 , false ) ;
if ( V_54 ) {
F_90 ( V_50 , V_54 , L_29 ) ;
F_69 ( V_68 , NULL , false ) ;
F_150 ( V_54 ) ;
}
V_54 = F_68 ( V_68 , true ) ;
if ( V_54 ) {
F_90 ( V_50 , V_54 , L_29 ) ;
F_69 ( V_68 , NULL , true ) ;
F_150 ( V_54 ) ;
}
V_68 -> V_314 = V_312 ;
return V_313 ;
}
static inline bool F_319 ( struct V_62 * V_68 , struct V_243 * V_243 )
{
return false ;
}
static struct V_53 * *
F_323 ( struct V_2 * V_3 , int V_304 , int V_81 )
{
switch ( V_304 ) {
case V_307 :
return & V_3 -> V_178 [ 0 ] [ V_81 ] ;
case V_306 :
V_81 = V_315 ;
case V_308 :
return & V_3 -> V_178 [ 1 ] [ V_81 ] ;
case V_309 :
return & V_3 -> V_179 ;
default:
F_324 () ;
}
}
static struct V_53 *
F_313 ( struct V_49 * V_50 , bool V_69 , struct V_62 * V_68 ,
struct V_243 * V_243 )
{
int V_304 = F_306 ( V_68 -> V_81 ) ;
int V_81 = F_310 ( V_68 -> V_81 ) ;
struct V_53 * * V_178 = NULL ;
struct V_53 * V_54 ;
struct V_2 * V_3 ;
F_320 () ;
V_3 = F_153 ( V_50 , F_321 ( V_243 ) ) ;
if ( ! V_3 ) {
V_54 = & V_50 -> V_316 ;
goto V_207;
}
if ( ! V_69 ) {
if ( ! F_325 ( V_68 -> V_81 ) ) {
struct V_244 * V_245 = V_246 ;
V_81 = F_308 ( V_245 ) ;
V_304 = F_309 ( V_245 ) ;
}
V_178 = F_323 ( V_3 , V_304 , V_81 ) ;
V_54 = * V_178 ;
if ( V_54 )
goto V_207;
}
V_54 = F_326 ( V_303 ,
V_317 | V_318 | V_319 ,
V_50 -> V_67 -> V_135 ) ;
if ( ! V_54 ) {
V_54 = & V_50 -> V_316 ;
goto V_207;
}
F_315 ( V_50 , V_54 , V_246 -> V_311 , V_69 ) ;
F_304 ( V_54 , V_68 ) ;
F_156 ( V_54 , V_3 ) ;
F_90 ( V_50 , V_54 , L_30 ) ;
if ( V_178 ) {
V_54 -> V_281 ++ ;
* V_178 = V_54 ;
}
V_207:
V_54 -> V_281 ++ ;
F_322 () ;
return V_54 ;
}
static void
F_327 ( struct V_320 * V_167 , T_2 V_321 )
{
T_2 V_322 = F_89 () - V_167 -> V_168 ;
V_322 = F_83 ( V_322 , 2UL * V_321 ) ;
V_167 -> V_269 = ( 7 * V_167 -> V_269 + 256 ) / 8 ;
V_167 -> V_323 = F_75 ( 7 * V_167 -> V_323 + 256 * V_322 , 8 ) ;
V_167 -> V_270 = F_328 ( V_167 -> V_323 + 128 ,
V_167 -> V_269 ) ;
}
static void
F_329 ( struct V_49 * V_50 , struct V_53 * V_54 ,
struct V_62 * V_68 )
{
if ( F_61 ( V_54 ) ) {
F_327 ( & V_68 -> V_167 , V_50 -> V_51 ) ;
F_327 ( & V_54 -> V_230 -> V_167 ,
V_50 -> V_51 ) ;
}
#ifdef F_330
F_327 ( & V_54 -> V_3 -> V_167 , V_50 -> V_266 ) ;
#endif
}
static void
F_331 ( struct V_49 * V_50 , struct V_53 * V_54 ,
struct V_110 * V_240 )
{
T_4 V_324 = 0 ;
T_4 V_325 = F_224 ( V_240 ) ;
if ( V_54 -> V_326 ) {
if ( V_54 -> V_326 < F_97 ( V_240 ) )
V_324 = F_97 ( V_240 ) - V_54 -> V_326 ;
else
V_324 = V_54 -> V_326 - F_97 ( V_240 ) ;
}
V_54 -> V_327 <<= 1 ;
if ( F_262 ( V_50 -> V_67 ) )
V_54 -> V_327 |= ( V_325 < V_328 ) ;
else
V_54 -> V_327 |= ( V_324 > V_329 ) ;
}
static inline bool F_332 ( struct V_110 * V_253 )
{
return F_333 ( V_253 ) == V_330 &&
( V_253 -> V_120 & ( V_331 | V_332 ) ) == V_331 ;
}
static void
F_334 ( struct V_49 * V_50 , struct V_53 * V_54 ,
struct V_62 * V_68 )
{
int V_333 , V_334 ;
if ( ! F_61 ( V_54 ) || F_58 ( V_54 ) )
return;
V_334 = V_333 = F_62 ( V_54 ) ;
if ( V_54 -> V_19 [ 0 ] + V_54 -> V_19 [ 1 ] >= 4 )
F_335 ( V_54 ) ;
if ( V_54 -> V_235 && F_332 ( V_54 -> V_235 ) )
V_334 = 0 ;
else if ( ! F_265 ( & V_68 -> V_64 . V_66 -> V_268 ) ||
! V_50 -> V_51 ||
( ! F_336 ( V_54 ) && F_249 ( V_54 ) ) )
V_334 = 0 ;
else if ( F_266 ( V_68 -> V_167 . V_269 ) ) {
if ( V_68 -> V_167 . V_270 > V_50 -> V_51 )
V_334 = 0 ;
else
V_334 = 1 ;
}
if ( V_333 != V_334 ) {
F_90 ( V_50 , V_54 , L_31 , V_334 ) ;
if ( V_334 )
F_317 ( V_54 ) ;
else
F_288 ( V_54 ) ;
}
}
static bool
F_337 ( struct V_49 * V_50 , struct V_53 * V_227 ,
struct V_110 * V_240 )
{
struct V_53 * V_54 ;
V_54 = V_50 -> V_258 ;
if ( ! V_54 )
return false ;
if ( F_58 ( V_227 ) )
return false ;
if ( F_58 ( V_54 ) )
return true ;
if ( F_59 ( V_54 ) && ! F_59 ( V_227 ) )
return false ;
if ( F_96 ( V_240 ) && ! F_61 ( V_54 ) && ! F_285 ( V_54 ) )
return true ;
if ( ! F_34 ( V_54 -> V_3 , V_227 -> V_3 ) )
return false ;
if ( F_91 ( V_54 ) )
return true ;
if ( F_59 ( V_227 ) && ! F_59 ( V_54 ) )
return true ;
F_123 ( V_54 -> V_304 != V_227 -> V_304 ) ;
if ( V_50 -> V_160 == V_58 &&
F_60 ( V_227 ) == V_58 &&
F_214 ( & V_54 -> V_133 ) )
return true ;
if ( ( V_240 -> V_120 & V_121 ) && ! V_54 -> V_252 )
return true ;
if ( F_214 ( & V_54 -> V_133 ) && ! F_261 ( V_50 , V_54 ) )
return true ;
if ( ! V_50 -> V_261 || ! F_246 ( V_54 ) )
return false ;
if ( F_258 ( V_50 , V_54 , V_240 ) )
return true ;
return false ;
}
static void F_338 ( struct V_49 * V_50 , struct V_53 * V_54 )
{
enum V_6 V_335 = F_60 ( V_50 -> V_258 ) ;
F_90 ( V_50 , V_54 , L_32 ) ;
F_252 ( V_50 , 1 ) ;
if ( V_335 != F_60 ( V_54 ) )
V_54 -> V_3 -> V_151 = 0 ;
F_21 ( ! F_206 ( V_54 ) ) ;
F_202 ( V_50 , V_54 , 1 ) ;
V_54 -> V_108 = 0 ;
F_244 ( V_54 ) ;
}
static void
F_339 ( struct V_49 * V_50 , struct V_53 * V_54 ,
struct V_110 * V_240 )
{
struct V_62 * V_68 = F_295 ( V_240 ) ;
V_50 -> V_251 ++ ;
if ( V_240 -> V_120 & V_121 )
V_54 -> V_252 ++ ;
F_329 ( V_50 , V_54 , V_68 ) ;
F_331 ( V_50 , V_54 , V_240 ) ;
F_334 ( V_50 , V_54 , V_68 ) ;
V_54 -> V_326 = F_97 ( V_240 ) + F_224 ( V_240 ) ;
if ( V_54 == V_50 -> V_258 ) {
if ( F_246 ( V_54 ) ) {
if ( F_340 ( V_240 ) > V_336 ||
V_50 -> V_72 > 1 ) {
F_237 ( V_50 , V_54 ) ;
F_240 ( V_54 ) ;
F_341 ( V_50 -> V_67 ) ;
} else {
F_17 ( V_54 -> V_3 ) ;
F_294 ( V_54 ) ;
}
}
} else if ( F_337 ( V_50 , V_54 , V_240 ) ) {
F_338 ( V_50 , V_54 ) ;
F_341 ( V_50 -> V_67 ) ;
}
}
static void F_342 ( struct V_248 * V_47 , struct V_110 * V_240 )
{
struct V_49 * V_50 = V_47 -> V_70 -> V_71 ;
struct V_53 * V_54 = F_212 ( V_240 ) ;
F_90 ( V_50 , V_54 , L_33 ) ;
F_304 ( V_54 , F_295 ( V_240 ) ) ;
V_240 -> V_257 = F_89 () + V_50 -> V_337 [ F_96 ( V_240 ) ] ;
F_343 ( & V_240 -> V_250 , & V_54 -> V_273 ) ;
F_215 ( V_240 ) ;
F_40 ( F_218 ( V_240 ) , V_50 -> V_242 ,
V_240 -> V_120 ) ;
F_339 ( V_50 , V_54 , V_240 ) ;
}
static void F_344 ( struct V_49 * V_50 )
{
struct V_53 * V_54 = V_50 -> V_258 ;
if ( V_50 -> V_249 > V_50 -> V_338 )
V_50 -> V_338 = V_50 -> V_249 ;
if ( V_50 -> V_52 == 1 )
return;
if ( V_50 -> V_251 <= V_339 &&
V_50 -> V_249 <= V_339 )
return;
if ( V_54 && F_62 ( V_54 ) &&
V_54 -> V_267 + V_54 -> V_19 [ 0 ] + V_54 -> V_19 [ 1 ] <
V_339 && V_50 -> V_249 < V_339 )
return;
if ( V_50 -> V_340 ++ < 50 )
return;
if ( V_50 -> V_338 >= V_339 )
V_50 -> V_52 = 1 ;
else
V_50 -> V_52 = 0 ;
}
static bool F_345 ( struct V_49 * V_50 , struct V_53 * V_54 )
{
struct V_62 * V_68 = V_50 -> V_261 ;
T_2 V_12 = F_89 () ;
if ( ! F_214 ( & V_54 -> V_133 ) )
return false ;
if ( V_54 -> V_3 -> V_134 > 1 )
return false ;
if ( F_263 ( V_50 , & V_54 -> V_3 -> V_167 , true ) )
return false ;
if ( F_91 ( V_54 ) )
return true ;
if ( V_68 && F_266 ( V_68 -> V_167 . V_269 )
&& ( V_54 -> V_108 - V_12 < V_68 -> V_167 . V_270 ) )
return true ;
if ( V_54 -> V_108 - V_12 <= F_127 ( 1 ) )
return true ;
return false ;
}
static void F_346 ( struct V_248 * V_47 , struct V_110 * V_240 )
{
struct V_53 * V_54 = F_212 ( V_240 ) ;
struct V_49 * V_50 = V_54 -> V_50 ;
const int V_74 = F_96 ( V_240 ) ;
T_2 V_12 = F_89 () ;
F_90 ( V_50 , V_54 , L_34 , F_332 ( V_240 ) ) ;
F_344 ( V_50 ) ;
F_76 ( ! V_50 -> V_249 ) ;
F_76 ( ! V_54 -> V_267 ) ;
V_50 -> V_249 -- ;
V_54 -> V_267 -- ;
( F_218 ( V_240 ) ) -> V_267 -- ;
F_46 ( V_54 -> V_3 , F_347 ( V_240 ) ,
F_348 ( V_240 ) , V_240 -> V_120 ) ;
V_50 -> V_272 [ F_61 ( V_54 ) ] -- ;
if ( V_74 ) {
struct V_1 * V_89 ;
F_295 ( V_240 ) -> V_167 . V_168 = V_12 ;
if ( F_206 ( V_54 ) )
V_89 = V_54 -> V_230 ;
else
V_89 = F_1 ( V_54 -> V_3 , F_57 ( V_54 ) ,
F_60 ( V_54 ) ) ;
V_89 -> V_167 . V_168 = V_12 ;
if ( ! F_349 ( V_240 -> V_41 +
F_350 ( V_50 -> V_337 [ 1 ] ) ,
V_341 ) )
V_50 -> V_299 = V_12 ;
}
#ifdef F_330
V_54 -> V_3 -> V_167 . V_168 = V_12 ;
#endif
if ( V_50 -> V_258 == V_54 ) {
const bool V_342 = F_214 ( & V_54 -> V_133 ) ;
if ( F_92 ( V_54 ) ) {
F_88 ( V_50 , V_54 ) ;
F_351 ( V_54 ) ;
}
if ( F_345 ( V_50 , V_54 ) ) {
T_2 V_343 = V_50 -> V_51 ;
if ( ! V_50 -> V_51 )
V_343 = V_50 -> V_266 ;
V_54 -> V_108 = V_12 + V_343 ;
F_352 ( V_54 ) ;
F_90 ( V_50 , V_54 , L_35 ) ;
}
if ( F_91 ( V_54 ) || F_58 ( V_54 ) )
F_252 ( V_50 , 1 ) ;
else if ( V_74 && V_342 &&
! F_260 ( V_50 , V_54 ) ) {
F_264 ( V_50 ) ;
}
}
if ( ! V_50 -> V_249 )
F_71 ( V_50 ) ;
}
static void F_353 ( struct V_53 * V_54 , unsigned int V_38 )
{
if ( ! ( V_38 & V_121 ) ) {
V_54 -> V_304 = V_54 -> V_310 ;
V_54 -> V_81 = V_54 -> V_238 ;
} else {
if ( F_58 ( V_54 ) )
V_54 -> V_304 = V_308 ;
if ( V_54 -> V_81 > V_315 )
V_54 -> V_81 = V_315 ;
}
}
static inline int F_354 ( struct V_53 * V_54 )
{
if ( F_246 ( V_54 ) && ! F_355 ( V_54 ) ) {
F_356 ( V_54 ) ;
return V_344 ;
}
return V_345 ;
}
static int F_357 ( struct V_248 * V_47 , unsigned int V_38 )
{
struct V_49 * V_50 = V_47 -> V_70 -> V_71 ;
struct V_244 * V_245 = V_246 ;
struct V_62 * V_68 ;
struct V_53 * V_54 ;
V_68 = F_66 ( V_50 , V_245 -> V_65 ) ;
if ( ! V_68 )
return V_345 ;
V_54 = F_68 ( V_68 , F_220 ( V_38 ) ) ;
if ( V_54 ) {
F_304 ( V_54 , V_68 ) ;
F_353 ( V_54 , V_38 ) ;
return F_354 ( V_54 ) ;
}
return V_345 ;
}
static void F_358 ( struct V_110 * V_240 )
{
struct V_53 * V_54 = F_212 ( V_240 ) ;
if ( V_54 ) {
const int V_346 = F_359 ( V_240 ) ;
F_21 ( ! V_54 -> V_278 [ V_346 ] ) ;
V_54 -> V_278 [ V_346 ] -- ;
F_38 ( F_218 ( V_240 ) ) ;
V_240 -> V_347 . V_348 [ 0 ] = NULL ;
V_240 -> V_347 . V_348 [ 1 ] = NULL ;
F_150 ( V_54 ) ;
}
}
static struct V_53 *
F_360 ( struct V_49 * V_50 , struct V_62 * V_68 ,
struct V_53 * V_54 )
{
F_90 ( V_50 , V_54 , L_36 , V_54 -> V_227 ) ;
F_69 ( V_68 , V_54 -> V_227 , 1 ) ;
F_361 ( V_54 -> V_227 ) ;
F_150 ( V_54 ) ;
return F_68 ( V_68 , 1 ) ;
}
static struct V_53 *
F_362 ( struct V_62 * V_68 , struct V_53 * V_54 )
{
if ( F_277 ( V_54 ) == 1 ) {
V_54 -> V_311 = V_246 -> V_311 ;
F_363 ( V_54 ) ;
F_364 ( V_54 ) ;
return V_54 ;
}
F_69 ( V_68 , NULL , 1 ) ;
F_299 ( V_54 ) ;
F_150 ( V_54 ) ;
return NULL ;
}
static int
F_365 ( struct V_248 * V_47 , struct V_110 * V_240 , struct V_243 * V_243 ,
T_5 V_349 )
{
struct V_49 * V_50 = V_47 -> V_70 -> V_71 ;
struct V_62 * V_68 = F_65 ( V_240 -> V_347 . V_64 ) ;
const int V_346 = F_359 ( V_240 ) ;
const bool V_69 = F_96 ( V_240 ) ;
struct V_53 * V_54 ;
bool V_350 ;
F_175 ( V_47 -> V_48 ) ;
F_312 ( V_68 , V_243 ) ;
V_350 = F_319 ( V_68 , V_243 ) ;
V_289:
V_54 = F_68 ( V_68 , V_69 ) ;
if ( ! V_54 || V_54 == & V_50 -> V_316 ) {
if ( V_54 )
F_150 ( V_54 ) ;
V_54 = F_313 ( V_50 , V_69 , V_68 , V_243 ) ;
F_69 ( V_68 , V_54 , V_69 ) ;
} else {
if ( F_248 ( V_54 ) && F_366 ( V_54 ) ) {
F_90 ( V_50 , V_54 , L_37 ) ;
V_54 = F_362 ( V_68 , V_54 ) ;
if ( ! V_54 )
goto V_289;
}
if ( V_54 -> V_227 )
V_54 = F_360 ( V_50 , V_68 , V_54 ) ;
}
V_54 -> V_278 [ V_346 ] ++ ;
V_54 -> V_281 ++ ;
F_36 ( V_54 -> V_3 ) ;
V_240 -> V_347 . V_348 [ 0 ] = V_54 ;
V_240 -> V_347 . V_348 [ 1 ] = V_54 -> V_3 ;
F_177 ( V_47 -> V_48 ) ;
if ( V_350 )
F_367 ( V_47 ) ;
return 0 ;
}
static void F_368 ( struct V_351 * V_352 )
{
struct V_49 * V_50 =
F_25 ( V_352 , struct V_49 , V_73 ) ;
struct V_248 * V_47 = V_50 -> V_67 ;
F_175 ( V_47 -> V_48 ) ;
F_341 ( V_50 -> V_67 ) ;
F_177 ( V_47 -> V_48 ) ;
}
static enum V_353 F_369 ( struct V_354 * V_355 )
{
struct V_49 * V_50 = F_25 ( V_355 , struct V_49 ,
V_259 ) ;
struct V_53 * V_54 ;
unsigned long V_356 ;
int V_260 = 1 ;
F_72 ( V_50 , L_38 ) ;
F_370 ( V_50 -> V_67 -> V_48 , V_356 ) ;
V_54 = V_50 -> V_258 ;
if ( V_54 ) {
V_260 = 0 ;
if ( F_285 ( V_54 ) )
goto V_357;
if ( F_91 ( V_54 ) )
goto V_290;
if ( ! V_50 -> V_72 )
goto V_358;
if ( ! F_214 ( & V_54 -> V_133 ) )
goto V_357;
F_287 ( V_54 ) ;
}
V_290:
F_252 ( V_50 , V_260 ) ;
V_357:
F_71 ( V_50 ) ;
V_358:
F_371 ( V_50 -> V_67 -> V_48 , V_356 ) ;
return V_359 ;
}
static void F_372 ( struct V_49 * V_50 )
{
F_373 ( & V_50 -> V_259 ) ;
F_374 ( & V_50 -> V_73 ) ;
}
static void F_375 ( struct V_360 * V_361 )
{
struct V_49 * V_50 = V_361 -> V_71 ;
struct V_248 * V_47 = V_50 -> V_67 ;
F_372 ( V_50 ) ;
F_175 ( V_47 -> V_48 ) ;
if ( V_50 -> V_258 )
F_245 ( V_50 , V_50 -> V_258 , 0 ) ;
F_177 ( V_47 -> V_48 ) ;
F_372 ( V_50 ) ;
#ifdef F_330
F_376 ( V_47 , & V_31 ) ;
#else
F_143 ( V_50 -> V_222 ) ;
#endif
F_143 ( V_50 ) ;
}
static int F_377 ( struct V_248 * V_47 , struct V_362 * V_361 )
{
struct V_49 * V_50 ;
struct V_29 * V_30 V_363 ;
int V_164 , V_199 ;
struct V_360 * V_364 ;
V_364 = F_378 ( V_47 , V_361 ) ;
if ( ! V_364 )
return - V_171 ;
V_50 = F_147 ( sizeof( * V_50 ) , V_365 , V_47 -> V_135 ) ;
if ( ! V_50 ) {
F_379 ( & V_364 -> V_366 ) ;
return - V_171 ;
}
V_364 -> V_71 = V_50 ;
V_50 -> V_67 = V_47 ;
F_175 ( V_47 -> V_48 ) ;
V_47 -> V_70 = V_364 ;
F_177 ( V_47 -> V_48 ) ;
V_50 -> V_149 = V_166 ;
#ifdef F_330
V_199 = F_380 ( V_47 , & V_31 ) ;
if ( V_199 )
goto V_367;
V_50 -> V_222 = F_29 ( V_47 -> V_368 ) ;
#else
V_199 = - V_171 ;
V_50 -> V_222 = F_147 ( sizeof( * V_50 -> V_222 ) ,
V_365 , V_50 -> V_67 -> V_135 ) ;
if ( ! V_50 -> V_222 )
goto V_367;
F_129 ( V_50 -> V_222 ) ;
V_50 -> V_222 -> V_141 = 2 * V_175 ;
V_50 -> V_222 -> V_143 = 2 * V_175 ;
#endif
for ( V_164 = 0 ; V_164 < V_369 ; V_164 ++ )
V_50 -> V_237 [ V_164 ] = V_370 ;
F_315 ( V_50 , & V_50 -> V_316 , 1 , 0 ) ;
V_50 -> V_316 . V_281 ++ ;
F_175 ( V_47 -> V_48 ) ;
F_156 ( & V_50 -> V_316 , V_50 -> V_222 ) ;
F_38 ( V_50 -> V_222 ) ;
F_177 ( V_47 -> V_48 ) ;
F_381 ( & V_50 -> V_259 , V_371 ,
V_271 ) ;
V_50 -> V_259 . V_372 = F_369 ;
F_382 ( & V_50 -> V_73 , F_368 ) ;
V_50 -> V_297 = V_297 ;
V_50 -> V_337 [ 0 ] = V_337 [ 0 ] ;
V_50 -> V_337 [ 1 ] = V_337 [ 1 ] ;
V_50 -> V_122 = V_122 ;
V_50 -> V_123 = V_123 ;
V_50 -> V_77 [ 0 ] = V_373 ;
V_50 -> V_77 [ 1 ] = V_374 ;
V_50 -> V_99 = V_99 ;
V_50 -> V_275 = V_275 ;
V_50 -> V_51 = V_51 ;
V_50 -> V_266 = V_266 ;
V_50 -> V_100 = 1 ;
V_50 -> V_52 = - 1 ;
V_50 -> V_299 = F_89 () - V_229 ;
return 0 ;
V_367:
F_143 ( V_50 ) ;
F_379 ( & V_364 -> V_366 ) ;
return V_199 ;
}
static void F_383 ( struct V_248 * V_47 )
{
struct V_360 * V_361 = V_47 -> V_70 ;
struct V_49 * V_50 = V_361 -> V_71 ;
if ( F_262 ( V_47 ) )
V_50 -> V_51 = 0 ;
}
static T_6
F_384 ( unsigned int V_375 , char * V_376 )
{
return sprintf ( V_376 , L_6 , V_375 ) ;
}
static T_6
F_385 ( unsigned int * V_375 , const char * V_376 , T_7 V_61 )
{
char * V_224 = ( char * ) V_376 ;
* V_375 = F_386 ( V_224 , & V_224 , 10 ) ;
return V_61 ;
}
static int T_10 F_387 ( void )
{
int V_199 ;
#ifdef F_330
V_199 = F_388 ( & V_31 ) ;
if ( V_199 )
return V_199 ;
#else
V_266 = 0 ;
#endif
V_199 = - V_171 ;
V_303 = F_389 ( V_53 , 0 ) ;
if ( ! V_303 )
goto V_377;
V_199 = F_390 ( & V_378 ) ;
if ( V_199 )
goto V_379;
return 0 ;
V_379:
F_391 ( V_303 ) ;
V_377:
#ifdef F_330
F_392 ( & V_31 ) ;
#endif
return V_199 ;
}
static void T_11 F_393 ( void )
{
#ifdef F_330
F_392 ( & V_31 ) ;
#endif
F_394 ( & V_378 ) ;
F_391 ( V_303 ) ;
}
