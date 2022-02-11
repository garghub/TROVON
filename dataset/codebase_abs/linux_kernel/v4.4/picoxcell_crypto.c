static inline struct V_1 * F_1 ( struct V_2 * V_3 )
{
return V_3 ? F_2 ( V_3 , struct V_1 , V_3 ) : NULL ;
}
static inline struct V_4 * F_3 ( struct V_5 * V_3 )
{
return F_2 ( V_3 , struct V_4 , V_3 ) ;
}
static inline int F_4 ( struct V_6 * V_7 )
{
T_1 V_8 = F_5 ( V_7 -> V_9 + V_10 ) ;
return V_8 & V_11 ;
}
static inline void T_2 * F_6 ( struct V_12 * V_13 ,
unsigned V_14 ,
bool V_15 )
{
return V_15 ? V_13 -> V_7 -> V_16 +
( V_14 * V_13 -> V_7 -> V_17 ) :
V_13 -> V_7 -> V_18 + ( V_14 * V_13 -> V_7 -> V_19 ) ;
}
static inline void F_7 ( T_1 T_2 * V_20 , const void * V_21 ,
unsigned V_22 )
{
const T_1 * V_23 = ( const T_1 * ) V_21 ;
while ( V_22 -- )
F_8 ( * V_23 ++ , V_20 ++ ) ;
}
static void F_9 ( struct V_12 * V_13 ,
void T_2 * V_24 , const T_3 * V_25 ,
T_4 V_26 , const T_3 * V_27 , T_4 V_28 )
{
void T_2 * V_29 = V_24 + V_13 -> V_30 ;
void T_2 * V_31 = V_24 + V_13 -> V_32 ;
F_7 ( V_29 , V_25 , V_26 / 4 ) ;
F_7 ( V_31 , V_27 , V_28 / 4 ) ;
}
static unsigned F_10 ( struct V_12 * V_13 ,
const T_3 * V_33 , T_4 V_34 ,
const T_3 * V_27 , T_4 V_35 , const T_3 * V_36 ,
T_4 V_37 )
{
unsigned V_14 = V_13 -> V_7 -> V_38 ++ ;
void T_2 * V_39 , * V_40 ;
V_39 = F_6 ( V_13 , V_14 , 1 ) ;
V_40 = F_6 ( V_13 , V_14 , 0 ) ;
V_13 -> V_7 -> V_38 &= V_13 -> V_7 -> V_41 - 1 ;
F_9 ( V_13 , V_39 , V_33 , V_34 , V_27 ,
V_35 ) ;
F_8 ( V_34 | ( V_14 << V_42 ) |
( 1 << V_43 ) ,
V_13 -> V_7 -> V_9 + V_44 ) ;
if ( V_36 ) {
F_7 ( V_40 , V_36 , V_37 / 4 ) ;
F_8 ( V_37 | ( V_14 << V_42 ) ,
V_13 -> V_7 -> V_9 + V_44 ) ;
}
return V_14 ;
}
static inline int F_11 ( struct V_45 * V_46 , int V_47 )
{
return F_12 ( V_46 , V_47 ) ;
}
static inline void F_13 ( struct V_48 * V_49 , T_5 V_50 , T_4 V_51 )
{
V_49 -> V_52 = V_50 ;
V_49 -> V_51 = V_51 ;
}
static struct V_48 * F_14 ( struct V_6 * V_7 ,
struct V_45 * V_53 ,
unsigned V_47 ,
enum V_54 V_55 ,
T_5 * V_56 )
{
unsigned V_57 , V_58 ;
struct V_45 * V_59 ;
struct V_48 * V_49 ;
int V_60 ;
V_57 = F_11 ( V_53 , V_47 ) ;
V_58 = F_15 ( V_7 -> V_61 , V_53 , V_57 , V_55 ) ;
if ( V_58 + 1 > V_62 )
goto V_63;
V_49 = F_16 ( V_7 -> V_64 , V_65 , V_56 ) ;
if ( ! V_49 )
goto V_63;
F_17 (payload, cur, mapped_ents, i)
F_13 ( & V_49 [ V_60 ] , F_18 ( V_59 ) , F_19 ( V_59 ) ) ;
F_13 ( & V_49 [ V_58 ] , 0 , 0 ) ;
return V_49 ;
V_63:
F_20 ( V_7 -> V_61 , V_53 , V_57 , V_55 ) ;
return NULL ;
}
static int F_21 ( struct V_66 * V_67 )
{
struct V_68 * V_69 = F_22 ( V_67 ) ;
struct V_70 * V_71 = F_23 ( V_67 ) ;
struct V_6 * V_7 = V_71 -> V_7 ;
struct V_48 * V_72 , * V_73 ;
unsigned V_74 ;
unsigned int V_75 , V_76 ;
struct V_45 * V_59 ;
int V_60 , V_77 , V_78 ;
V_74 = V_67 -> V_79 + V_67 -> V_80 ;
if ( V_71 -> V_81 )
V_74 += F_24 ( V_69 ) ;
V_75 = F_11 ( V_67 -> V_21 , V_74 ) ;
if ( V_75 + 1 > V_62 )
return - V_82 ;
V_76 = 0 ;
if ( V_67 -> V_21 != V_67 -> V_20 ) {
V_76 = F_11 ( V_67 -> V_20 , V_74 ) ;
if ( V_75 + 1 > V_62 )
return - V_82 ;
}
V_72 = F_16 ( V_7 -> V_64 , V_65 , & V_71 -> V_83 ) ;
if ( ! V_72 )
goto V_84;
V_73 = F_16 ( V_7 -> V_64 , V_65 , & V_71 -> V_85 ) ;
if ( ! V_73 )
goto V_86;
V_71 -> V_72 = V_72 ;
V_71 -> V_73 = V_73 ;
if ( V_76 ) {
V_78 = F_15 ( V_7 -> V_61 , V_67 -> V_21 , V_75 ,
V_87 ) ;
if ( ! V_78 )
goto V_88;
V_77 = F_15 ( V_7 -> V_61 , V_67 -> V_20 , V_76 ,
V_89 ) ;
if ( ! V_77 ) {
F_20 ( V_7 -> V_61 , V_67 -> V_21 , V_75 ,
V_87 ) ;
goto V_88;
}
} else {
V_78 = F_15 ( V_7 -> V_61 , V_67 -> V_21 , V_75 ,
V_90 ) ;
if ( ! V_78 )
goto V_88;
V_77 = V_78 ;
}
F_17 (areq->src, cur, src_ents, i)
F_13 ( V_72 ++ , F_18 ( V_59 ) , F_19 ( V_59 ) ) ;
V_74 = V_71 -> V_81 ? 0 : V_67 -> V_79 ;
F_17 (areq->dst, cur, dst_ents, i) {
unsigned V_51 = F_19 ( V_59 ) ;
if ( V_51 <= V_74 ) {
V_74 -= V_51 ;
continue;
}
F_13 ( V_73 ++ , F_18 ( V_59 ) + V_74 , V_51 - V_74 ) ;
}
F_13 ( V_72 , 0 , 0 ) ;
F_13 ( V_73 , 0 , 0 ) ;
return 0 ;
V_88:
F_25 ( V_7 -> V_64 , V_73 , V_71 -> V_85 ) ;
V_86:
F_25 ( V_7 -> V_64 , V_72 , V_71 -> V_83 ) ;
V_84:
return - V_91 ;
}
static void F_26 ( struct V_70 * V_71 )
{
struct V_66 * V_67 = F_2 ( V_71 -> V_71 , struct V_66 ,
V_92 ) ;
struct V_68 * V_69 = F_22 ( V_67 ) ;
unsigned V_74 = V_67 -> V_79 + V_67 -> V_80 +
( V_71 -> V_81 ? F_24 ( V_69 ) : 0 ) ;
struct V_93 * V_94 = F_27 ( V_69 ) ;
struct V_6 * V_7 = V_94 -> V_95 . V_7 ;
unsigned V_57 = F_11 ( V_67 -> V_21 , V_74 ) ;
if ( V_67 -> V_21 != V_67 -> V_20 ) {
F_20 ( V_7 -> V_61 , V_67 -> V_21 , V_57 , V_87 ) ;
F_20 ( V_7 -> V_61 , V_67 -> V_20 ,
F_11 ( V_67 -> V_20 , V_74 ) ,
V_89 ) ;
} else
F_20 ( V_7 -> V_61 , V_67 -> V_21 , V_57 , V_90 ) ;
F_25 ( V_7 -> V_64 , V_71 -> V_72 , V_71 -> V_83 ) ;
F_25 ( V_7 -> V_64 , V_71 -> V_73 , V_71 -> V_85 ) ;
}
static void F_28 ( struct V_70 * V_71 , struct V_48 * V_49 ,
T_5 V_96 , struct V_45 * V_53 ,
unsigned V_47 , enum V_54 V_55 )
{
unsigned V_57 = F_11 ( V_53 , V_47 ) ;
F_20 ( V_71 -> V_7 -> V_61 , V_53 , V_57 , V_55 ) ;
F_25 ( V_71 -> V_7 -> V_64 , V_49 , V_96 ) ;
}
static int F_29 ( struct V_68 * V_97 , const T_3 * V_25 ,
unsigned int V_98 )
{
struct V_93 * V_13 = F_27 ( V_97 ) ;
struct V_99 V_100 ;
int V_84 ;
F_30 ( V_13 -> V_101 , V_102 ) ;
F_31 ( V_13 -> V_101 , F_32 ( V_97 ) &
V_102 ) ;
V_84 = F_33 ( V_13 -> V_101 , V_25 , V_98 ) ;
F_30 ( V_97 , V_103 ) ;
F_31 ( V_97 , F_32 ( V_13 -> V_101 ) &
V_103 ) ;
if ( V_84 )
return V_84 ;
if ( F_34 ( & V_100 , V_25 , V_98 ) != 0 )
goto V_104;
if ( V_100 . V_105 > V_106 )
goto V_104;
if ( V_100 . V_107 > sizeof( V_13 -> V_108 ) )
goto V_104;
memcpy ( V_13 -> V_109 , V_100 . V_110 , V_100 . V_105 ) ;
V_13 -> V_111 = V_100 . V_105 ;
memcpy ( V_13 -> V_108 , V_100 . V_112 , V_100 . V_107 ) ;
V_13 -> V_113 = V_100 . V_107 ;
return 0 ;
V_104:
F_31 ( V_97 , V_114 ) ;
return - V_115 ;
}
static int F_35 ( struct V_68 * V_97 ,
unsigned int V_116 )
{
struct V_93 * V_13 = F_36 ( F_37 ( V_97 ) ) ;
return F_38 ( V_13 -> V_101 , V_116 ) ;
}
static int F_39 ( struct V_66 * V_117 )
{
struct V_68 * V_69 = F_22 ( V_117 ) ;
struct V_5 * V_3 = F_40 ( V_69 ) ;
struct V_4 * V_1 = F_3 ( V_3 ) ;
struct V_93 * V_13 = F_27 ( V_69 ) ;
if ( ( V_1 -> V_118 & V_119 ) ==
V_120 &&
V_13 -> V_111 != V_121 &&
V_13 -> V_111 != V_122 )
return 1 ;
return 0 ;
}
static int F_41 ( struct V_66 * V_71 , unsigned V_123 ,
bool V_81 )
{
struct V_124 * V_125 = F_37 ( F_22 ( V_71 ) ) ;
struct V_93 * V_13 = F_36 ( V_125 ) ;
struct V_66 * V_126 = F_23 ( V_71 ) ;
F_42 ( V_126 , V_13 -> V_101 ) ;
F_43 ( V_126 , V_71 -> V_92 . V_127 ,
V_71 -> V_92 . V_128 , V_71 -> V_92 . V_129 ) ;
F_44 ( V_126 , V_71 -> V_21 , V_71 -> V_20 , V_71 -> V_80 ,
V_71 -> V_27 ) ;
F_45 ( V_126 , V_71 -> V_79 ) ;
return V_81 ? F_46 ( V_126 ) :
F_47 ( V_126 ) ;
}
static void F_48 ( struct V_70 * V_71 )
{
F_26 ( V_71 ) ;
V_71 -> V_71 -> V_128 ( V_71 -> V_71 , V_71 -> V_130 ) ;
}
static int F_49 ( struct V_70 * V_71 )
{
struct V_66 * V_117 =
F_2 ( V_71 -> V_71 , struct V_66 , V_92 ) ;
struct V_68 * V_69 = F_22 ( V_117 ) ;
unsigned int V_116 = F_24 ( V_69 ) ;
struct V_93 * V_13 = F_27 ( V_69 ) ;
struct V_5 * V_3 = F_40 ( V_69 ) ;
struct V_4 * V_1 = F_3 ( V_3 ) ;
struct V_6 * V_7 = V_13 -> V_95 . V_7 ;
T_1 V_131 , V_132 , V_133 ;
V_71 -> V_130 = - V_134 ;
V_71 -> V_135 = F_10 ( & V_13 -> V_95 , V_13 -> V_109 ,
V_13 -> V_111 , V_117 -> V_27 , F_50 ( V_69 ) ,
V_13 -> V_108 , V_13 -> V_113 ) ;
F_8 ( V_71 -> V_83 , V_7 -> V_9 + V_136 ) ;
F_8 ( V_71 -> V_85 , V_7 -> V_9 + V_137 ) ;
F_8 ( 0 , V_7 -> V_9 + V_138 ) ;
V_133 = V_117 -> V_79 ;
V_132 = V_117 -> V_80 + V_133 ;
if ( ! V_71 -> V_81 )
V_132 -= V_116 ;
F_8 ( V_132 , V_7 -> V_9 + V_139 ) ;
F_8 ( V_133 , V_7 -> V_9 + V_140 ) ;
F_8 ( V_116 , V_7 -> V_9 + V_141 ) ;
F_8 ( 0 , V_7 -> V_9 + V_142 ) ;
F_8 ( 0 , V_7 -> V_9 + V_143 ) ;
V_131 = V_1 -> V_118 | ( V_71 -> V_135 << V_144 ) |
( 1 << V_145 ) ;
if ( V_71 -> V_81 )
V_131 |= ( 1 << V_146 ) | ( 1 << V_147 ) ;
else
V_131 |= ( 1 << V_148 ) ;
F_51 ( & V_7 -> V_149 , V_150 + V_151 ) ;
F_8 ( V_131 , V_7 -> V_9 + V_152 ) ;
return - V_134 ;
}
static void F_52 ( struct V_6 * V_7 )
{
struct V_70 * V_71 ;
while ( ! F_53 ( & V_7 -> V_153 ) &&
V_7 -> V_154 + 1 <= V_7 -> V_41 ) {
++ V_7 -> V_154 ;
V_71 = F_54 ( & V_7 -> V_153 , struct V_70 ,
V_155 ) ;
F_55 ( & V_71 -> V_155 , & V_7 -> V_156 ) ;
V_71 -> V_130 = F_56 ( V_71 ) ;
}
}
static int F_57 ( struct V_66 * V_71 ,
unsigned V_123 , bool V_81 )
{
struct V_68 * V_69 = F_22 ( V_71 ) ;
struct V_5 * V_3 = F_40 ( V_69 ) ;
struct V_6 * V_7 = F_3 ( V_3 ) -> V_7 ;
struct V_70 * V_157 = F_23 ( V_71 ) ;
int V_84 ;
unsigned long V_127 ;
V_157 -> V_71 = & V_71 -> V_92 ;
V_157 -> V_81 = V_81 ;
V_157 -> V_130 = - V_158 ;
V_157 -> V_7 = V_7 ;
V_157 -> V_128 = F_48 ;
if ( F_58 ( F_39 ( V_71 ) ||
( ( V_84 = F_21 ( V_71 ) ) == - V_82 ) ) )
return F_41 ( V_71 , V_123 , V_81 ) ;
if ( V_84 )
goto V_63;
V_84 = - V_134 ;
F_59 ( & V_7 -> V_159 , V_127 ) ;
if ( F_58 ( F_4 ( V_7 ) ) ||
V_7 -> V_154 + 1 > V_7 -> V_41 ) {
if ( ! ( V_71 -> V_92 . V_127 & V_160 ) ) {
V_84 = - V_158 ;
F_60 ( & V_7 -> V_159 , V_127 ) ;
goto V_161;
}
F_61 ( & V_157 -> V_155 , & V_7 -> V_153 ) ;
} else {
F_61 ( & V_157 -> V_155 , & V_7 -> V_153 ) ;
F_52 ( V_7 ) ;
}
F_60 ( & V_7 -> V_159 , V_127 ) ;
goto V_63;
V_161:
F_26 ( V_157 ) ;
V_63:
return V_84 ;
}
static int F_62 ( struct V_66 * V_71 )
{
struct V_68 * V_69 = F_22 ( V_71 ) ;
struct V_4 * V_3 = F_3 ( F_40 ( V_69 ) ) ;
return F_57 ( V_71 , V_3 -> type , 1 ) ;
}
static int F_63 ( struct V_66 * V_71 )
{
struct V_68 * V_69 = F_22 ( V_71 ) ;
struct V_4 * V_3 = F_3 ( F_40 ( V_69 ) ) ;
return F_57 ( V_71 , V_3 -> type , 0 ) ;
}
static int F_64 ( struct V_68 * V_97 )
{
struct V_93 * V_13 = F_27 ( V_97 ) ;
struct V_5 * V_3 = F_40 ( V_97 ) ;
struct V_4 * V_1 = F_3 ( V_3 ) ;
struct V_6 * V_7 = V_1 -> V_7 ;
V_13 -> V_95 . V_127 = V_1 -> type ;
V_13 -> V_95 . V_7 = V_7 ;
V_13 -> V_101 = F_65 ( V_3 -> V_92 . V_162 , 0 ,
V_163 ) ;
if ( F_66 ( V_13 -> V_101 ) )
return F_67 ( V_13 -> V_101 ) ;
V_13 -> V_95 . V_30 = V_1 -> V_30 ;
V_13 -> V_95 . V_32 = V_1 -> V_32 ;
F_68 (
V_97 ,
F_69 ( sizeof( struct V_70 ) ,
sizeof( struct V_66 ) +
F_70 ( V_13 -> V_101 ) ) ) ;
return 0 ;
}
static void F_71 ( struct V_68 * V_97 )
{
struct V_93 * V_13 = F_27 ( V_97 ) ;
F_72 ( V_13 -> V_101 ) ;
}
static int F_73 ( struct V_164 * V_165 , const T_3 * V_25 ,
unsigned int V_51 )
{
struct V_124 * V_97 = F_74 ( V_165 ) ;
struct V_166 * V_13 = F_36 ( V_97 ) ;
T_1 V_167 [ V_168 ] ;
if ( V_51 > V_169 ) {
F_75 ( V_165 , V_114 ) ;
return - V_115 ;
}
if ( F_58 ( ! F_76 ( V_167 , V_25 ) ) &&
( F_77 ( V_165 ) & V_170 ) ) {
V_97 -> V_171 |= V_172 ;
return - V_115 ;
}
memcpy ( V_13 -> V_25 , V_25 , V_51 ) ;
V_13 -> V_26 = V_51 ;
return 0 ;
}
static int F_78 ( struct V_164 * V_165 , const T_3 * V_25 ,
unsigned int V_51 )
{
struct V_124 * V_97 = F_74 ( V_165 ) ;
struct V_166 * V_13 = F_36 ( V_97 ) ;
int V_84 = 0 ;
if ( V_51 > V_106 ) {
F_75 ( V_165 , V_114 ) ;
return - V_115 ;
}
if ( V_51 != V_121 && V_51 != V_122 &&
V_13 -> V_101 ) {
V_13 -> V_101 -> V_92 . V_171 &= ~ V_102 ;
V_13 -> V_101 -> V_92 . V_171 |=
V_165 -> V_92 . V_171 & V_102 ;
V_84 = F_79 ( V_13 -> V_101 , V_25 , V_51 ) ;
if ( V_84 )
goto V_173;
} else if ( V_51 != V_121 && V_51 != V_122 &&
! V_13 -> V_101 )
V_84 = - V_115 ;
memcpy ( V_13 -> V_25 , V_25 , V_51 ) ;
V_13 -> V_26 = V_51 ;
V_173:
if ( V_84 && V_13 -> V_101 ) {
V_97 -> V_171 &= ~ V_103 ;
V_97 -> V_171 |=
V_13 -> V_101 -> V_92 . V_171 & V_103 ;
}
return V_84 ;
}
static int F_80 ( struct V_164 * V_165 ,
const T_3 * V_25 , unsigned int V_51 )
{
struct V_124 * V_97 = F_74 ( V_165 ) ;
struct V_166 * V_13 = F_36 ( V_97 ) ;
int V_84 = 0 ;
if ( V_51 > V_106 ) {
F_75 ( V_165 , V_114 ) ;
V_84 = - V_115 ;
goto V_63;
}
memcpy ( V_13 -> V_25 , V_25 , V_51 ) ;
V_13 -> V_26 = V_51 ;
V_63:
return V_84 ;
}
static int F_81 ( struct V_70 * V_71 )
{
struct V_166 * V_13 ;
struct V_124 * V_97 = V_71 -> V_71 -> V_97 ;
struct V_2 * V_3 = V_71 -> V_71 -> V_97 -> V_174 ;
struct V_1 * V_1 = F_1 ( V_3 ) ;
V_13 = F_36 ( V_97 ) ;
return ( V_1 -> V_118 & V_119 ) ==
V_120 &&
V_13 -> V_26 != V_121 &&
V_13 -> V_26 != V_122 ;
}
static void F_82 ( struct V_70 * V_71 )
{
struct V_175 * V_176 =
F_2 ( V_71 -> V_71 , struct V_175 , V_92 ) ;
if ( V_176 -> V_21 != V_176 -> V_20 ) {
F_28 ( V_71 , V_71 -> V_72 , V_71 -> V_83 , V_176 -> V_21 ,
V_176 -> V_47 , V_87 ) ;
F_28 ( V_71 , V_71 -> V_73 , V_71 -> V_85 , V_176 -> V_20 ,
V_176 -> V_47 , V_89 ) ;
} else
F_28 ( V_71 , V_71 -> V_73 , V_71 -> V_85 , V_176 -> V_20 ,
V_176 -> V_47 , V_90 ) ;
V_71 -> V_71 -> V_128 ( V_71 -> V_71 , V_71 -> V_130 ) ;
}
static int F_83 ( struct V_70 * V_71 )
{
struct V_124 * V_97 = V_71 -> V_71 -> V_97 ;
struct V_166 * V_13 = F_36 ( V_97 ) ;
struct V_175 * V_176 = F_84 ( V_71 -> V_71 ) ;
struct V_2 * V_3 = V_71 -> V_71 -> V_97 -> V_174 ;
struct V_1 * V_1 = F_1 ( V_3 ) ;
struct V_6 * V_7 = V_13 -> V_95 . V_7 ;
T_1 V_131 ;
V_71 -> V_135 = F_10 ( & V_13 -> V_95 , V_13 -> V_25 ,
V_13 -> V_26 , V_176 -> V_177 , V_3 -> V_178 . V_179 ,
NULL , 0 ) ;
F_8 ( V_71 -> V_83 , V_7 -> V_9 + V_136 ) ;
F_8 ( V_71 -> V_85 , V_7 -> V_9 + V_137 ) ;
F_8 ( 0 , V_7 -> V_9 + V_138 ) ;
F_8 ( V_176 -> V_47 , V_7 -> V_9 + V_139 ) ;
F_8 ( 0 , V_7 -> V_9 + V_142 ) ;
F_8 ( 0 , V_7 -> V_9 + V_143 ) ;
F_8 ( 0 , V_7 -> V_9 + V_140 ) ;
V_131 = V_1 -> V_118 | ( V_71 -> V_135 << V_144 ) |
( V_71 -> V_81 ? ( 1 << V_146 ) :
( 1 << V_148 ) ) ;
F_51 ( & V_7 -> V_149 , V_150 + V_151 ) ;
F_8 ( V_131 , V_7 -> V_9 + V_152 ) ;
return - V_134 ;
}
static int F_85 ( struct V_175 * V_71 ,
unsigned V_123 , bool V_81 )
{
struct V_124 * V_125 =
F_74 ( F_86 ( V_71 ) ) ;
struct V_166 * V_13 = F_36 ( V_125 ) ;
int V_84 ;
if ( ! V_13 -> V_101 )
return - V_115 ;
F_87 ( V_71 , V_13 -> V_101 ) ;
V_84 = V_81 ? F_88 ( V_71 ) :
F_89 ( V_71 ) ;
F_87 ( V_71 , F_90 ( V_125 ) ) ;
return V_84 ;
}
static int F_91 ( struct V_175 * V_71 , unsigned V_123 ,
bool V_81 )
{
struct V_2 * V_3 = V_71 -> V_92 . V_97 -> V_174 ;
struct V_6 * V_7 = F_1 ( V_3 ) -> V_7 ;
struct V_70 * V_157 = F_92 ( V_71 ) ;
unsigned long V_127 ;
int V_84 = - V_91 ;
V_157 -> V_71 = & V_71 -> V_92 ;
V_157 -> V_81 = V_81 ;
V_157 -> V_7 = V_7 ;
V_157 -> V_128 = F_82 ;
V_157 -> V_130 = - V_134 ;
if ( F_58 ( F_81 ( V_157 ) ) )
return F_85 ( V_71 , V_123 , V_81 ) ;
if ( V_71 -> V_21 != V_71 -> V_20 ) {
V_157 -> V_72 = F_14 ( V_7 , V_71 -> V_21 ,
V_71 -> V_47 , V_87 , & V_157 -> V_83 ) ;
if ( ! V_157 -> V_72 )
goto V_63;
V_157 -> V_73 = F_14 ( V_7 , V_71 -> V_20 ,
V_71 -> V_47 , V_89 , & V_157 -> V_85 ) ;
if ( ! V_157 -> V_73 )
goto V_180;
} else {
V_157 -> V_73 = F_14 ( V_7 , V_71 -> V_20 ,
V_71 -> V_47 , V_90 , & V_157 -> V_85 ) ;
if ( ! V_157 -> V_73 )
goto V_63;
V_157 -> V_72 = NULL ;
V_157 -> V_83 = V_157 -> V_85 ;
}
V_84 = - V_134 ;
F_59 ( & V_7 -> V_159 , V_127 ) ;
if ( F_58 ( F_4 ( V_7 ) ) ||
V_7 -> V_154 + 1 > V_7 -> V_41 ) {
if ( ! ( V_71 -> V_92 . V_127 & V_160 ) ) {
V_84 = - V_158 ;
F_60 ( & V_7 -> V_159 , V_127 ) ;
goto V_161;
}
F_61 ( & V_157 -> V_155 , & V_7 -> V_153 ) ;
} else {
F_61 ( & V_157 -> V_155 , & V_7 -> V_153 ) ;
F_52 ( V_7 ) ;
}
F_60 ( & V_7 -> V_159 , V_127 ) ;
goto V_63;
V_161:
F_28 ( V_157 , V_157 -> V_73 , V_157 -> V_85 , V_71 -> V_20 ,
V_71 -> V_47 , V_71 -> V_21 == V_71 -> V_20 ?
V_90 : V_89 ) ;
V_180:
if ( V_71 -> V_21 != V_71 -> V_20 )
F_28 ( V_157 , V_157 -> V_72 , V_157 -> V_83 ,
V_71 -> V_21 , V_71 -> V_47 , V_87 ) ;
V_63:
return V_84 ;
}
static int F_93 ( struct V_124 * V_97 )
{
struct V_166 * V_13 = F_36 ( V_97 ) ;
struct V_2 * V_3 = V_97 -> V_174 ;
struct V_1 * V_1 = F_1 ( V_3 ) ;
struct V_6 * V_7 = V_1 -> V_7 ;
V_13 -> V_95 . V_127 = V_1 -> type ;
V_13 -> V_95 . V_7 = V_7 ;
if ( V_3 -> V_181 & V_163 ) {
V_13 -> V_101 = F_94 ( V_3 -> V_162 , 0 ,
V_182 | V_163 ) ;
if ( F_66 ( V_13 -> V_101 ) ) {
F_95 ( V_7 -> V_61 , L_1 ,
V_3 -> V_162 ) ;
V_13 -> V_101 = NULL ;
}
}
V_13 -> V_95 . V_30 = V_1 -> V_30 ;
V_13 -> V_95 . V_32 = V_1 -> V_32 ;
V_97 -> V_183 . V_184 = sizeof( struct V_70 ) ;
return 0 ;
}
static void F_96 ( struct V_124 * V_97 )
{
struct V_166 * V_13 = F_36 ( V_97 ) ;
if ( V_13 -> V_101 )
F_97 ( V_13 -> V_101 ) ;
V_13 -> V_101 = NULL ;
}
static int F_98 ( struct V_175 * V_71 )
{
struct V_164 * V_165 = F_86 ( V_71 ) ;
struct V_124 * V_97 = F_74 ( V_165 ) ;
struct V_1 * V_3 = F_1 ( V_97 -> V_174 ) ;
return F_91 ( V_71 , V_3 -> type , 1 ) ;
}
static int F_99 ( struct V_175 * V_71 )
{
struct V_164 * V_165 = F_86 ( V_71 ) ;
struct V_124 * V_97 = F_74 ( V_165 ) ;
struct V_1 * V_3 = F_1 ( V_97 -> V_174 ) ;
return F_91 ( V_71 , V_3 -> type , 0 ) ;
}
static inline int F_100 ( struct V_6 * V_7 )
{
return F_5 ( V_7 -> V_9 + V_10 ) &
V_185 ;
}
static void F_101 ( struct V_6 * V_7 )
{
struct V_70 * V_71 ;
unsigned long V_127 ;
F_59 ( & V_7 -> V_159 , V_127 ) ;
while ( ! F_100 ( V_7 ) ) {
V_71 = F_54 ( & V_7 -> V_156 , struct V_70 ,
V_155 ) ;
F_55 ( & V_71 -> V_155 , & V_7 -> V_186 ) ;
-- V_7 -> V_154 ;
F_8 ( ~ 0 , V_7 -> V_9 + V_187 ) ;
V_71 -> V_130 = ( F_5 ( V_7 -> V_9 + V_188 ) &
V_189 ) >> V_190 ;
if ( F_58 ( V_71 -> V_130 ) ) {
switch ( V_71 -> V_130 ) {
case V_191 :
V_71 -> V_130 = - V_192 ;
break;
case V_193 :
F_95 ( V_7 -> V_61 ,
L_2 ) ;
V_71 -> V_130 = - V_194 ;
break;
case V_195 :
F_95 ( V_7 -> V_61 ,
L_3 ) ;
V_71 -> V_130 = - V_196 ;
break;
}
}
}
F_102 ( & V_7 -> V_128 ) ;
F_60 ( & V_7 -> V_159 , V_127 ) ;
}
static T_6 F_103 ( int V_197 , void * V_61 )
{
struct V_6 * V_7 = (struct V_6 * ) V_61 ;
T_1 V_198 = F_5 ( V_7 -> V_9 + V_199 ) ;
F_8 ( V_198 , V_7 -> V_9 + V_199 ) ;
F_101 ( V_7 ) ;
return V_200 ;
}
static void F_104 ( unsigned long V_129 )
{
struct V_6 * V_7 = (struct V_6 * ) V_129 ;
F_101 ( V_7 ) ;
}
static int F_56 ( struct V_70 * V_71 )
{
struct V_2 * V_3 = V_71 -> V_71 -> V_97 -> V_174 ;
if ( V_201 == ( V_202 & V_3 -> V_181 ) )
return F_49 ( V_71 ) ;
else
return F_83 ( V_71 ) ;
}
static void F_105 ( unsigned long V_129 )
{
struct V_6 * V_7 = (struct V_6 * ) V_129 ;
struct V_70 * V_71 , * V_167 ;
unsigned long V_127 ;
F_106 ( V_186 ) ;
F_59 ( & V_7 -> V_159 , V_127 ) ;
F_107 ( & V_7 -> V_186 , & V_186 ) ;
F_52 ( V_7 ) ;
if ( V_7 -> V_154 )
F_51 ( & V_7 -> V_149 , V_150 + V_151 ) ;
F_60 ( & V_7 -> V_159 , V_127 ) ;
F_108 (req, tmp, &completed, list) {
F_109 ( & V_71 -> V_155 ) ;
V_71 -> V_128 ( V_71 ) ;
}
}
static int F_110 ( struct V_203 * V_61 )
{
struct V_204 * V_205 = F_111 ( V_61 ) ;
struct V_6 * V_7 = F_112 ( V_205 ) ;
F_113 ( V_7 -> V_206 ) ;
return 0 ;
}
static int F_114 ( struct V_203 * V_61 )
{
struct V_204 * V_205 = F_111 ( V_61 ) ;
struct V_6 * V_7 = F_112 ( V_205 ) ;
return F_115 ( V_7 -> V_206 ) ;
}
static inline struct V_6 * F_116 ( struct V_203 * V_61 )
{
return V_61 ? F_112 ( F_111 ( V_61 ) ) : NULL ;
}
static T_7 F_117 ( struct V_203 * V_61 ,
struct V_207 * V_208 ,
char * V_209 )
{
struct V_6 * V_7 = F_116 ( V_61 ) ;
return snprintf ( V_209 , V_210 , L_4 , V_7 -> V_211 ) ;
}
static T_7 F_118 ( struct V_203 * V_61 ,
struct V_207 * V_208 ,
const char * V_209 , T_4 V_51 )
{
struct V_6 * V_7 = F_116 ( V_61 ) ;
unsigned long V_212 ;
if ( F_119 ( V_209 , 0 , & V_212 ) )
return - V_115 ;
V_212 = F_120 ( V_212 , 1UL , V_7 -> V_41 - 1 ) ;
V_7 -> V_211 = V_212 ;
F_8 ( V_7 -> V_211 << V_213 ,
V_7 -> V_9 + V_214 ) ;
return V_51 ;
}
static bool F_121 ( struct V_204 * V_205 ,
const char * V_215 )
{
const struct V_216 * V_217 = F_122 ( V_205 ) ;
if ( V_217 && ! strcmp ( V_217 -> V_218 , V_215 ) )
return true ;
#ifdef F_123
if ( F_124 ( V_205 -> V_61 . V_219 , V_215 ) )
return true ;
#endif
return false ;
}
static int F_125 ( struct V_204 * V_205 )
{
int V_60 , V_84 , V_220 = - V_115 ;
struct V_221 * V_222 , * V_197 ;
struct V_6 * V_7 = F_126 ( & V_205 -> V_61 , sizeof( * V_7 ) ,
V_223 ) ;
if ( ! V_7 )
return - V_91 ;
if ( F_121 ( V_205 , L_5 ) ) {
V_7 -> V_224 = V_225 ;
V_7 -> V_17 = V_226 ;
V_7 -> V_19 = V_227 ;
V_7 -> V_41 = V_228 ;
V_7 -> V_229 = V_230 ;
V_7 -> V_231 = F_127 ( V_230 ) ;
V_7 -> V_232 = V_233 ;
V_7 -> V_234 = F_127 ( V_233 ) ;
} else if ( F_121 ( V_205 , L_6 ) ) {
V_7 -> V_224 = V_235 ;
V_7 -> V_17 = V_236 ;
V_7 -> V_19 = V_237 ;
V_7 -> V_41 = V_238 ;
V_7 -> V_229 = V_239 ;
V_7 -> V_231 = F_127 ( V_239 ) ;
} else {
return - V_115 ;
}
V_7 -> V_218 = F_128 ( & V_205 -> V_61 ) ;
V_222 = F_129 ( V_205 , V_240 , 0 ) ;
V_7 -> V_9 = F_130 ( & V_205 -> V_61 , V_222 ) ;
if ( F_66 ( V_7 -> V_9 ) )
return F_67 ( V_7 -> V_9 ) ;
V_197 = F_129 ( V_205 , V_241 , 0 ) ;
if ( ! V_197 ) {
F_131 ( & V_205 -> V_61 , L_7 ) ;
return - V_242 ;
}
if ( F_132 ( & V_205 -> V_61 , V_197 -> V_243 , F_103 , 0 ,
V_7 -> V_218 , V_7 ) ) {
F_131 ( V_7 -> V_61 , L_8 ) ;
return - V_158 ;
}
V_7 -> V_61 = & V_205 -> V_61 ;
V_7 -> V_16 = V_7 -> V_9 + V_244 ;
V_7 -> V_18 = V_7 -> V_9 + V_245 ;
V_7 -> V_64 = F_133 ( V_7 -> V_218 , V_7 -> V_61 ,
V_62 * sizeof( struct V_48 ) , 8 , V_246 ) ;
if ( ! V_7 -> V_64 )
return - V_91 ;
F_134 ( & V_7 -> V_159 ) ;
V_7 -> V_206 = F_135 ( & V_205 -> V_61 , L_9 ) ;
if ( F_66 ( V_7 -> V_206 ) ) {
F_136 ( & V_205 -> V_61 , L_10 ) ;
F_137 ( & V_205 -> V_61 , & V_247 ) ;
return F_67 ( V_7 -> V_206 ) ;
}
if ( F_138 ( V_7 -> V_206 ) ) {
F_136 ( & V_205 -> V_61 , L_11 ) ;
F_139 ( V_7 -> V_206 ) ;
return - V_196 ;
}
V_84 = F_140 ( & V_205 -> V_61 , & V_247 ) ;
if ( V_84 ) {
F_141 ( V_7 -> V_206 ) ;
F_139 ( V_7 -> V_206 ) ;
return V_84 ;
}
V_7 -> V_211 = ( V_7 -> V_41 / 2 ) ;
F_8 ( V_7 -> V_211 << V_213 ,
V_7 -> V_9 + V_214 ) ;
F_8 ( V_248 | V_249 ,
V_7 -> V_9 + V_250 ) ;
F_142 ( & V_7 -> V_149 , F_104 ,
( unsigned long ) V_7 ) ;
F_143 ( & V_7 -> V_153 ) ;
F_143 ( & V_7 -> V_186 ) ;
F_143 ( & V_7 -> V_156 ) ;
V_7 -> V_154 = 0 ;
F_144 ( & V_7 -> V_128 , F_105 ,
( unsigned long ) V_7 ) ;
F_145 ( V_205 , V_7 ) ;
F_143 ( & V_7 -> V_251 ) ;
for ( V_60 = 0 ; V_60 < V_7 -> V_231 ; ++ V_60 ) {
V_7 -> V_229 [ V_60 ] . V_7 = V_7 ;
V_84 = F_146 ( & V_7 -> V_229 [ V_60 ] . V_3 ) ;
if ( ! V_84 ) {
F_61 ( & V_7 -> V_229 [ V_60 ] . V_252 ,
& V_7 -> V_251 ) ;
V_220 = 0 ;
}
if ( V_84 )
F_131 ( V_7 -> V_61 , L_12 ,
V_7 -> V_229 [ V_60 ] . V_3 . V_162 ) ;
else
F_147 ( V_7 -> V_61 , L_13 ,
V_7 -> V_229 [ V_60 ] . V_3 . V_162 ) ;
}
F_143 ( & V_7 -> V_253 ) ;
for ( V_60 = 0 ; V_60 < V_7 -> V_234 ; ++ V_60 ) {
V_7 -> V_232 [ V_60 ] . V_7 = V_7 ;
V_84 = F_148 ( & V_7 -> V_232 [ V_60 ] . V_3 ) ;
if ( ! V_84 ) {
F_61 ( & V_7 -> V_232 [ V_60 ] . V_252 ,
& V_7 -> V_253 ) ;
V_220 = 0 ;
}
if ( V_84 )
F_131 ( V_7 -> V_61 , L_12 ,
V_7 -> V_232 [ V_60 ] . V_3 . V_92 . V_162 ) ;
else
F_147 ( V_7 -> V_61 , L_13 ,
V_7 -> V_232 [ V_60 ] . V_3 . V_92 . V_162 ) ;
}
return V_220 ;
}
static int F_149 ( struct V_204 * V_205 )
{
struct V_4 * V_69 , * V_254 ;
struct V_1 * V_3 , * V_255 ;
struct V_6 * V_7 = F_112 ( V_205 ) ;
F_150 ( & V_7 -> V_149 ) ;
F_137 ( & V_205 -> V_61 , & V_247 ) ;
F_108 (aead, an, &engine->registered_aeads, entry) {
F_109 ( & V_69 -> V_252 ) ;
F_151 ( & V_69 -> V_3 ) ;
}
F_108 (alg, next, &engine->registered_algs, entry) {
F_109 ( & V_3 -> V_252 ) ;
F_152 ( & V_3 -> V_3 ) ;
}
F_141 ( V_7 -> V_206 ) ;
F_139 ( V_7 -> V_206 ) ;
return 0 ;
}
