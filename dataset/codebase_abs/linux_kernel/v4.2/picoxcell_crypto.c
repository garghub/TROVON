static inline struct V_1 * F_1 ( struct V_2 * V_3 )
{
return V_3 ? F_2 ( V_3 , struct V_1 , V_3 ) : NULL ;
}
static inline int F_3 ( struct V_4 * V_5 )
{
T_1 V_6 = F_4 ( V_5 -> V_7 + V_8 ) ;
return V_6 & V_9 ;
}
static inline void T_2 * F_5 ( struct V_10 * V_11 ,
unsigned V_12 ,
bool V_13 )
{
return V_13 ? V_11 -> V_5 -> V_14 +
( V_12 * V_11 -> V_5 -> V_15 ) :
V_11 -> V_5 -> V_16 + ( V_12 * V_11 -> V_5 -> V_17 ) ;
}
static inline void F_6 ( T_1 T_2 * V_18 , const void * V_19 ,
unsigned V_20 )
{
const T_1 * V_21 = ( const T_1 * ) V_19 ;
while ( V_20 -- )
F_7 ( * V_21 ++ , V_18 ++ ) ;
}
static void F_8 ( struct V_10 * V_11 ,
void T_2 * V_22 , const T_3 * V_23 ,
T_4 V_24 , const T_3 * V_25 , T_4 V_26 )
{
void T_2 * V_27 = V_22 + V_11 -> V_28 ;
void T_2 * V_29 = V_22 + V_11 -> V_30 ;
F_6 ( V_27 , V_23 , V_24 / 4 ) ;
F_6 ( V_29 , V_25 , V_26 / 4 ) ;
}
static unsigned F_9 ( struct V_10 * V_11 ,
const T_3 * V_31 , T_4 V_32 ,
const T_3 * V_25 , T_4 V_33 , const T_3 * V_34 ,
T_4 V_35 )
{
unsigned V_12 = V_11 -> V_5 -> V_36 ++ ;
void T_2 * V_37 , * V_38 ;
V_37 = F_5 ( V_11 , V_12 , 1 ) ;
V_38 = F_5 ( V_11 , V_12 , 0 ) ;
V_11 -> V_5 -> V_36 &= V_11 -> V_5 -> V_39 - 1 ;
F_8 ( V_11 , V_37 , V_31 , V_32 , V_25 ,
V_33 ) ;
F_7 ( V_32 | ( V_12 << V_40 ) |
( 1 << V_41 ) ,
V_11 -> V_5 -> V_7 + V_42 ) ;
if ( V_34 ) {
F_6 ( V_38 , V_34 , V_35 / 4 ) ;
F_7 ( V_35 | ( V_12 << V_40 ) ,
V_11 -> V_5 -> V_7 + V_42 ) ;
}
return V_12 ;
}
static inline int F_10 ( struct V_43 * V_44 , int V_45 )
{
return F_11 ( V_44 , V_45 ) ;
}
static inline void F_12 ( struct V_46 * V_47 , T_5 V_48 , T_4 V_49 )
{
V_47 -> V_50 = V_48 ;
V_47 -> V_49 = V_49 ;
}
static struct V_46 * F_13 ( struct V_4 * V_5 ,
struct V_43 * V_51 ,
unsigned V_45 ,
enum V_52 V_53 ,
T_5 * V_54 )
{
unsigned V_55 , V_56 ;
struct V_43 * V_57 ;
struct V_46 * V_47 ;
int V_58 ;
V_55 = F_10 ( V_51 , V_45 ) ;
V_56 = F_14 ( V_5 -> V_59 , V_51 , V_55 , V_53 ) ;
if ( V_56 + 1 > V_60 )
goto V_61;
V_47 = F_15 ( V_5 -> V_62 , V_63 , V_54 ) ;
if ( ! V_47 )
goto V_61;
F_16 (payload, cur, mapped_ents, i)
F_12 ( & V_47 [ V_58 ] , F_17 ( V_57 ) , F_18 ( V_57 ) ) ;
F_12 ( & V_47 [ V_56 ] , 0 , 0 ) ;
return V_47 ;
V_61:
F_19 ( V_5 -> V_59 , V_51 , V_55 , V_53 ) ;
return NULL ;
}
static int F_20 ( struct V_64 * V_65 , T_3 * V_66 )
{
struct V_67 * V_68 = F_2 ( V_65 -> V_65 , struct V_67 ,
V_69 ) ;
struct V_4 * V_5 = V_65 -> V_5 ;
struct V_46 * V_70 , * V_71 ;
unsigned V_72 = F_21 ( F_22 ( V_68 ) ) ;
unsigned V_55 = F_10 ( V_68 -> V_19 , V_68 -> V_73 ) ;
unsigned V_74 ;
T_5 V_75 ;
struct V_43 * V_57 ;
int V_58 , V_76 , V_77 , V_78 ;
T_3 * V_25 = V_66 ? V_66 : V_68 -> V_25 ;
V_70 = F_15 ( V_5 -> V_62 , V_63 , & V_65 -> V_79 ) ;
if ( ! V_70 )
return - V_80 ;
V_71 = F_15 ( V_5 -> V_62 , V_63 , & V_65 -> V_81 ) ;
if ( ! V_71 ) {
F_23 ( V_5 -> V_62 , V_70 , V_65 -> V_79 ) ;
return - V_80 ;
}
V_65 -> V_70 = V_70 ;
V_65 -> V_71 = V_71 ;
V_78 = F_14 ( V_5 -> V_59 , V_68 -> V_82 ,
F_10 ( V_68 -> V_82 , V_68 -> V_83 ) , V_84 ) ;
if ( V_68 -> V_19 != V_68 -> V_18 ) {
V_77 = F_14 ( V_5 -> V_59 , V_68 -> V_19 , V_55 ,
V_84 ) ;
V_76 = F_14 ( V_5 -> V_59 , V_68 -> V_18 , V_55 ,
V_85 ) ;
} else {
V_77 = F_14 ( V_5 -> V_59 , V_68 -> V_19 , V_55 ,
V_86 ) ;
V_76 = 0 ;
}
V_75 = F_24 ( V_5 -> V_59 , V_25 , V_72 ,
V_66 ? V_86 : V_84 ) ;
V_65 -> V_87 = V_75 ;
V_74 = V_68 -> V_83 ;
F_16 (areq->assoc, cur, assoc_ents, i) {
unsigned V_49 = F_18 ( V_57 ) ;
if ( V_49 > V_74 )
V_49 = V_74 ;
V_74 -= V_49 ;
F_12 ( V_70 ++ , F_17 ( V_57 ) , V_49 ) ;
if ( V_65 -> V_88 )
F_12 ( V_71 ++ , F_17 ( V_57 ) , V_49 ) ;
}
F_12 ( V_70 ++ , V_75 , V_72 ) ;
if ( V_66 || V_65 -> V_88 )
F_12 ( V_71 ++ , V_75 , V_72 ) ;
F_16 (areq->src, cur, src_ents, i) {
F_12 ( V_70 ++ , F_17 ( V_57 ) , F_18 ( V_57 ) ) ;
if ( V_68 -> V_19 == V_68 -> V_18 )
F_12 ( V_71 ++ , F_17 ( V_57 ) ,
F_18 ( V_57 ) ) ;
}
F_16 (areq->dst, cur, dst_ents, i)
F_12 ( V_71 ++ , F_17 ( V_57 ) ,
F_18 ( V_57 ) ) ;
F_12 ( V_70 , 0 , 0 ) ;
F_12 ( V_71 , 0 , 0 ) ;
return 0 ;
}
static void F_25 ( struct V_64 * V_65 )
{
struct V_67 * V_68 = F_2 ( V_65 -> V_65 , struct V_67 ,
V_69 ) ;
struct V_1 * V_3 = F_1 ( V_65 -> V_65 -> V_89 -> V_90 ) ;
struct V_91 * V_92 = F_26 ( V_65 -> V_65 -> V_89 ) ;
struct V_4 * V_5 = V_92 -> V_93 . V_5 ;
unsigned V_72 = V_3 -> V_3 . V_94 . V_72 ;
unsigned V_55 = F_10 ( V_68 -> V_19 , V_68 -> V_73 ) ;
if ( V_68 -> V_19 != V_68 -> V_18 ) {
F_19 ( V_5 -> V_59 , V_68 -> V_19 , V_55 , V_84 ) ;
F_19 ( V_5 -> V_59 , V_68 -> V_18 ,
F_10 ( V_68 -> V_18 , V_68 -> V_73 ) ,
V_85 ) ;
} else
F_19 ( V_5 -> V_59 , V_68 -> V_19 , V_55 , V_86 ) ;
F_19 ( V_5 -> V_59 , V_68 -> V_82 ,
F_10 ( V_68 -> V_82 , V_68 -> V_83 ) , V_84 ) ;
F_27 ( V_5 -> V_59 , V_65 -> V_87 , V_72 , V_86 ) ;
F_23 ( V_5 -> V_62 , V_65 -> V_70 , V_65 -> V_79 ) ;
F_23 ( V_5 -> V_62 , V_65 -> V_71 , V_65 -> V_81 ) ;
}
static void F_28 ( struct V_64 * V_65 , struct V_46 * V_47 ,
T_5 V_95 , struct V_43 * V_51 ,
unsigned V_45 , enum V_52 V_53 )
{
unsigned V_55 = F_10 ( V_51 , V_45 ) ;
F_19 ( V_65 -> V_5 -> V_59 , V_51 , V_55 , V_53 ) ;
F_23 ( V_65 -> V_5 -> V_62 , V_47 , V_95 ) ;
}
static int F_29 ( struct V_96 * V_97 , const T_3 * V_23 ,
unsigned int V_49 )
{
struct V_98 * V_89 = F_30 ( V_97 ) ;
struct V_99 * V_11 = F_26 ( V_89 ) ;
T_1 V_100 [ V_101 ] ;
if ( F_31 ( ! F_32 ( V_100 , V_23 ) ) &&
( F_33 ( V_97 ) ) & V_102 ) {
V_89 -> V_103 |= V_104 ;
return - V_105 ;
}
memcpy ( V_11 -> V_106 , V_23 , V_49 ) ;
V_11 -> V_107 = V_49 ;
return 0 ;
}
static int F_34 ( struct V_96 * V_97 , const T_3 * V_23 ,
unsigned int V_49 )
{
struct V_98 * V_89 = F_30 ( V_97 ) ;
struct V_99 * V_11 = F_26 ( V_89 ) ;
if ( V_49 != V_108 && V_49 != V_109 ) {
V_11 -> V_110 -> V_69 . V_103 &= ~ V_111 ;
V_11 -> V_110 -> V_69 . V_103 |=
V_89 -> V_103 & V_111 ;
return F_35 ( V_11 -> V_110 , V_23 , V_49 ) ;
}
memcpy ( V_11 -> V_106 , V_23 , V_49 ) ;
V_11 -> V_107 = V_49 ;
return 0 ;
}
static int F_36 ( struct V_96 * V_89 , const T_3 * V_23 ,
unsigned int V_112 )
{
struct V_99 * V_11 = F_37 ( V_89 ) ;
struct V_1 * V_3 = F_1 ( V_89 -> V_69 . V_90 ) ;
struct V_113 V_114 ;
int V_115 = - V_105 ;
if ( F_38 ( & V_114 , V_23 , V_112 ) != 0 )
goto V_116;
if ( V_114 . V_117 > V_118 )
goto V_116;
if ( V_114 . V_119 > sizeof( V_11 -> V_120 ) )
goto V_116;
if ( ( V_3 -> V_121 & V_122 ) ==
V_123 )
V_115 = F_34 ( V_89 , V_114 . V_124 , V_114 . V_117 ) ;
else
V_115 = F_29 ( V_89 , V_114 . V_124 , V_114 . V_117 ) ;
if ( V_115 )
goto V_116;
memcpy ( V_11 -> V_120 , V_114 . V_125 , V_114 . V_119 ) ;
V_11 -> V_126 = V_114 . V_119 ;
return 0 ;
V_116:
F_39 ( V_89 , V_127 ) ;
return - V_105 ;
}
static int F_40 ( struct V_96 * V_89 ,
unsigned int V_128 )
{
struct V_99 * V_11 = F_26 ( F_30 ( V_89 ) ) ;
V_11 -> V_129 = V_128 ;
return 0 ;
}
static int F_41 ( struct V_64 * V_65 )
{
struct V_67 * V_130 ;
struct V_98 * V_89 = V_65 -> V_65 -> V_89 ;
struct V_2 * V_3 = V_65 -> V_65 -> V_89 -> V_90 ;
struct V_1 * V_1 = F_1 ( V_3 ) ;
struct V_99 * V_11 = F_26 ( V_89 ) ;
V_130 = F_2 ( V_65 -> V_65 , struct V_67 , V_69 ) ;
if ( ( V_1 -> V_121 & V_122 ) ==
V_123 &&
V_11 -> V_107 != V_108 &&
V_11 -> V_107 != V_109 )
return 1 ;
return 0 ;
}
static int F_42 ( struct V_67 * V_65 , unsigned V_131 ,
bool V_88 )
{
struct V_98 * V_132 = F_30 ( F_22 ( V_65 ) ) ;
struct V_99 * V_11 = F_26 ( V_132 ) ;
int V_115 ;
if ( V_11 -> V_110 ) {
F_43 ( V_65 , V_11 -> V_110 ) ;
V_115 = V_88 ? F_44 ( V_65 ) :
F_45 ( V_65 ) ;
F_43 ( V_65 , F_46 ( V_132 ) ) ;
} else
V_115 = - V_105 ;
return V_115 ;
}
static void F_47 ( struct V_64 * V_65 )
{
F_25 ( V_65 ) ;
V_65 -> V_65 -> V_133 ( V_65 -> V_65 , V_65 -> V_134 ) ;
}
static int F_48 ( struct V_64 * V_65 )
{
struct V_98 * V_89 = V_65 -> V_65 -> V_89 ;
struct V_99 * V_11 = F_26 ( V_89 ) ;
struct V_2 * V_3 = V_65 -> V_65 -> V_89 -> V_90 ;
struct V_1 * V_1 = F_1 ( V_3 ) ;
struct V_4 * V_5 = V_11 -> V_93 . V_5 ;
T_1 V_135 , V_136 , V_137 ;
struct V_67 * V_130 =
F_2 ( V_65 -> V_65 , struct V_67 , V_69 ) ;
V_65 -> V_134 = - V_138 ;
V_65 -> V_139 = F_9 ( & V_11 -> V_93 , V_11 -> V_106 ,
V_11 -> V_107 , V_130 -> V_25 , V_3 -> V_94 . V_72 ,
V_11 -> V_120 , V_11 -> V_126 ) ;
F_7 ( V_65 -> V_79 , V_5 -> V_7 + V_140 ) ;
F_7 ( V_65 -> V_81 , V_5 -> V_7 + V_141 ) ;
F_7 ( 0 , V_5 -> V_7 + V_142 ) ;
V_137 = V_130 -> V_83 ;
V_136 = V_130 -> V_73 + V_137 ;
if ( ! V_65 -> V_66 ) {
V_137 += F_21 ( F_22 ( V_130 ) ) ;
V_136 += F_21 ( F_22 ( V_130 ) ) ;
} else
V_136 += V_65 -> V_143 ;
if ( ! V_65 -> V_88 )
V_136 -= V_11 -> V_129 ;
F_7 ( V_136 , V_5 -> V_7 + V_144 ) ;
F_7 ( V_137 , V_5 -> V_7 + V_145 ) ;
F_7 ( V_11 -> V_129 , V_5 -> V_7 + V_146 ) ;
F_7 ( 0 , V_5 -> V_7 + V_147 ) ;
F_7 ( 0 , V_5 -> V_7 + V_148 ) ;
V_135 = V_1 -> V_121 | ( V_65 -> V_139 << V_149 ) |
( 1 << V_150 ) ;
if ( V_65 -> V_88 )
V_135 |= ( 1 << V_151 ) | ( 1 << V_152 ) ;
else
V_135 |= ( 1 << V_153 ) ;
F_49 ( & V_5 -> V_154 , V_155 + V_156 ) ;
F_7 ( V_135 , V_5 -> V_7 + V_157 ) ;
return - V_138 ;
}
static void F_50 ( struct V_4 * V_5 )
{
struct V_64 * V_65 ;
while ( ! F_51 ( & V_5 -> V_158 ) &&
V_5 -> V_159 + 1 <= V_5 -> V_39 ) {
++ V_5 -> V_159 ;
V_65 = F_52 ( & V_5 -> V_158 , struct V_64 ,
V_160 ) ;
F_53 ( & V_65 -> V_160 , & V_5 -> V_161 ) ;
V_65 -> V_134 = F_54 ( V_65 ) ;
}
}
static int F_55 ( struct V_67 * V_65 , T_3 * V_66 ,
unsigned V_131 , bool V_88 )
{
struct V_2 * V_3 = V_65 -> V_69 . V_89 -> V_90 ;
struct V_4 * V_5 = F_1 ( V_3 ) -> V_5 ;
struct V_64 * V_162 = F_56 ( V_65 ) ;
int V_115 = - V_138 ;
unsigned long V_163 ;
unsigned V_72 = F_21 ( F_22 ( V_65 ) ) ;
V_162 -> V_66 = V_66 ;
V_162 -> V_143 = V_72 ;
V_162 -> V_65 = & V_65 -> V_69 ;
V_162 -> V_88 = V_88 ;
V_162 -> V_134 = - V_164 ;
V_162 -> V_5 = V_5 ;
V_162 -> V_133 = F_47 ;
if ( F_31 ( F_41 ( V_162 ) ) )
return F_42 ( V_65 , V_131 , V_88 ) ;
F_20 ( V_162 , V_162 -> V_66 ) ;
V_115 = - V_138 ;
F_57 ( & V_5 -> V_165 , V_163 ) ;
if ( F_31 ( F_3 ( V_5 ) ) ||
V_5 -> V_159 + 1 > V_5 -> V_39 ) {
if ( ! ( V_65 -> V_69 . V_163 & V_166 ) ) {
V_115 = - V_164 ;
F_58 ( & V_5 -> V_165 , V_163 ) ;
goto V_167;
}
F_59 ( & V_162 -> V_160 , & V_5 -> V_158 ) ;
} else {
F_59 ( & V_162 -> V_160 , & V_5 -> V_158 ) ;
F_50 ( V_5 ) ;
}
F_58 ( & V_5 -> V_165 , V_163 ) ;
goto V_61;
V_167:
F_25 ( V_162 ) ;
V_61:
return V_115 ;
}
static int F_60 ( struct V_67 * V_65 )
{
struct V_96 * V_97 = F_22 ( V_65 ) ;
struct V_98 * V_89 = F_30 ( V_97 ) ;
struct V_1 * V_3 = F_1 ( V_89 -> V_90 ) ;
return F_55 ( V_65 , NULL , V_3 -> type , 1 ) ;
}
static int F_61 ( struct V_168 * V_65 )
{
struct V_96 * V_89 = F_62 ( V_65 ) ;
struct V_99 * V_11 = F_37 ( V_89 ) ;
T_4 V_72 = F_21 ( V_89 ) ;
struct V_1 * V_3 = F_1 ( V_89 -> V_69 . V_90 ) ;
unsigned V_49 ;
T_6 V_169 ;
memcpy ( V_65 -> V_68 . V_25 , V_11 -> V_170 , V_72 ) ;
V_49 = V_72 ;
if ( V_72 > sizeof( V_171 ) ) {
memset ( V_65 -> V_66 , 0 , V_72 - sizeof( V_171 ) ) ;
V_49 = sizeof( V_171 ) ;
}
V_169 = F_63 ( V_65 -> V_169 ) ;
memcpy ( V_65 -> V_66 + V_72 - V_49 , & V_169 , V_49 ) ;
return F_55 ( & V_65 -> V_68 , V_65 -> V_66 , V_3 -> type , 1 ) ;
}
static int F_64 ( struct V_67 * V_65 )
{
struct V_96 * V_97 = F_22 ( V_65 ) ;
struct V_98 * V_89 = F_30 ( V_97 ) ;
struct V_1 * V_3 = F_1 ( V_89 -> V_90 ) ;
return F_55 ( V_65 , NULL , V_3 -> type , 0 ) ;
}
static int F_65 ( struct V_98 * V_89 )
{
struct V_99 * V_11 = F_26 ( V_89 ) ;
struct V_2 * V_3 = V_89 -> V_90 ;
struct V_1 * V_1 = F_1 ( V_3 ) ;
struct V_4 * V_5 = V_1 -> V_5 ;
V_11 -> V_93 . V_163 = V_1 -> type ;
V_11 -> V_93 . V_5 = V_5 ;
V_11 -> V_110 = F_66 ( V_3 -> V_172 , 0 ,
V_173 |
V_174 ) ;
if ( F_67 ( V_11 -> V_110 ) ) {
F_68 ( V_5 -> V_59 , L_1 ,
V_3 -> V_172 ) ;
V_11 -> V_110 = NULL ;
}
V_11 -> V_93 . V_28 = V_1 -> V_28 ;
V_11 -> V_93 . V_30 = V_1 -> V_30 ;
F_69 ( V_11 -> V_170 , sizeof( V_11 -> V_170 ) ) ;
F_70 ( F_46 ( V_89 ) ,
sizeof( struct V_64 ) ) ;
return 0 ;
}
static void F_71 ( struct V_98 * V_89 )
{
struct V_99 * V_11 = F_26 ( V_89 ) ;
if ( V_11 -> V_110 )
F_72 ( V_11 -> V_110 ) ;
V_11 -> V_110 = NULL ;
}
static int F_73 ( struct V_175 * V_176 , const T_3 * V_23 ,
unsigned int V_49 )
{
struct V_98 * V_89 = F_74 ( V_176 ) ;
struct V_91 * V_11 = F_26 ( V_89 ) ;
T_1 V_100 [ V_101 ] ;
if ( V_49 > V_177 ) {
F_75 ( V_176 , V_127 ) ;
return - V_105 ;
}
if ( F_31 ( ! F_32 ( V_100 , V_23 ) ) &&
( F_76 ( V_176 ) & V_102 ) ) {
V_89 -> V_103 |= V_104 ;
return - V_105 ;
}
memcpy ( V_11 -> V_23 , V_23 , V_49 ) ;
V_11 -> V_24 = V_49 ;
return 0 ;
}
static int F_77 ( struct V_175 * V_176 , const T_3 * V_23 ,
unsigned int V_49 )
{
struct V_98 * V_89 = F_74 ( V_176 ) ;
struct V_91 * V_11 = F_26 ( V_89 ) ;
int V_115 = 0 ;
if ( V_49 > V_118 ) {
F_75 ( V_176 , V_127 ) ;
return - V_105 ;
}
if ( V_49 != V_108 && V_49 != V_109 &&
V_11 -> V_110 ) {
V_11 -> V_110 -> V_69 . V_103 &= ~ V_111 ;
V_11 -> V_110 -> V_69 . V_103 |=
V_176 -> V_69 . V_103 & V_111 ;
V_115 = F_78 ( V_11 -> V_110 , V_23 , V_49 ) ;
if ( V_115 )
goto V_178;
} else if ( V_49 != V_108 && V_49 != V_109 &&
! V_11 -> V_110 )
V_115 = - V_105 ;
memcpy ( V_11 -> V_23 , V_23 , V_49 ) ;
V_11 -> V_24 = V_49 ;
V_178:
if ( V_115 && V_11 -> V_110 ) {
V_89 -> V_103 &= ~ V_179 ;
V_89 -> V_103 |=
V_11 -> V_110 -> V_69 . V_103 & V_179 ;
}
return V_115 ;
}
static int F_79 ( struct V_175 * V_176 ,
const T_3 * V_23 , unsigned int V_49 )
{
struct V_98 * V_89 = F_74 ( V_176 ) ;
struct V_91 * V_11 = F_26 ( V_89 ) ;
int V_115 = 0 ;
if ( V_49 > V_118 ) {
F_75 ( V_176 , V_127 ) ;
V_115 = - V_105 ;
goto V_61;
}
memcpy ( V_11 -> V_23 , V_23 , V_49 ) ;
V_11 -> V_24 = V_49 ;
V_61:
return V_115 ;
}
static int F_80 ( struct V_64 * V_65 )
{
struct V_91 * V_11 ;
struct V_98 * V_89 = V_65 -> V_65 -> V_89 ;
struct V_2 * V_3 = V_65 -> V_65 -> V_89 -> V_90 ;
struct V_1 * V_1 = F_1 ( V_3 ) ;
V_11 = F_26 ( V_89 ) ;
return ( V_1 -> V_121 & V_122 ) ==
V_123 &&
V_11 -> V_24 != V_108 &&
V_11 -> V_24 != V_109 ;
}
static void F_81 ( struct V_64 * V_65 )
{
struct V_180 * V_181 =
F_2 ( V_65 -> V_65 , struct V_180 , V_69 ) ;
if ( V_181 -> V_19 != V_181 -> V_18 ) {
F_28 ( V_65 , V_65 -> V_70 , V_65 -> V_79 , V_181 -> V_19 ,
V_181 -> V_45 , V_84 ) ;
F_28 ( V_65 , V_65 -> V_71 , V_65 -> V_81 , V_181 -> V_18 ,
V_181 -> V_45 , V_85 ) ;
} else
F_28 ( V_65 , V_65 -> V_71 , V_65 -> V_81 , V_181 -> V_18 ,
V_181 -> V_45 , V_86 ) ;
V_65 -> V_65 -> V_133 ( V_65 -> V_65 , V_65 -> V_134 ) ;
}
static int F_82 ( struct V_64 * V_65 )
{
struct V_98 * V_89 = V_65 -> V_65 -> V_89 ;
struct V_91 * V_11 = F_26 ( V_89 ) ;
struct V_180 * V_181 = F_83 ( V_65 -> V_65 ) ;
struct V_2 * V_3 = V_65 -> V_65 -> V_89 -> V_90 ;
struct V_1 * V_1 = F_1 ( V_3 ) ;
struct V_4 * V_5 = V_11 -> V_93 . V_5 ;
T_1 V_135 ;
V_65 -> V_139 = F_9 ( & V_11 -> V_93 , V_11 -> V_23 ,
V_11 -> V_24 , V_181 -> V_182 , V_3 -> V_183 . V_72 ,
NULL , 0 ) ;
F_7 ( V_65 -> V_79 , V_5 -> V_7 + V_140 ) ;
F_7 ( V_65 -> V_81 , V_5 -> V_7 + V_141 ) ;
F_7 ( 0 , V_5 -> V_7 + V_142 ) ;
F_7 ( V_181 -> V_45 , V_5 -> V_7 + V_144 ) ;
F_7 ( 0 , V_5 -> V_7 + V_147 ) ;
F_7 ( 0 , V_5 -> V_7 + V_148 ) ;
F_7 ( 0 , V_5 -> V_7 + V_145 ) ;
V_135 = V_1 -> V_121 | ( V_65 -> V_139 << V_149 ) |
( V_65 -> V_88 ? ( 1 << V_151 ) :
( 1 << V_153 ) ) ;
F_49 ( & V_5 -> V_154 , V_155 + V_156 ) ;
F_7 ( V_135 , V_5 -> V_7 + V_157 ) ;
return - V_138 ;
}
static int F_84 ( struct V_180 * V_65 ,
unsigned V_131 , bool V_88 )
{
struct V_98 * V_132 =
F_74 ( F_85 ( V_65 ) ) ;
struct V_91 * V_11 = F_26 ( V_132 ) ;
int V_115 ;
if ( ! V_11 -> V_110 )
return - V_105 ;
F_86 ( V_65 , V_11 -> V_110 ) ;
V_115 = V_88 ? F_87 ( V_65 ) :
F_88 ( V_65 ) ;
F_86 ( V_65 , F_89 ( V_132 ) ) ;
return V_115 ;
}
static int F_90 ( struct V_180 * V_65 , unsigned V_131 ,
bool V_88 )
{
struct V_2 * V_3 = V_65 -> V_69 . V_89 -> V_90 ;
struct V_4 * V_5 = F_1 ( V_3 ) -> V_5 ;
struct V_64 * V_162 = F_91 ( V_65 ) ;
unsigned long V_163 ;
int V_115 = - V_80 ;
V_162 -> V_65 = & V_65 -> V_69 ;
V_162 -> V_88 = V_88 ;
V_162 -> V_5 = V_5 ;
V_162 -> V_133 = F_81 ;
V_162 -> V_134 = - V_138 ;
if ( F_31 ( F_80 ( V_162 ) ) )
return F_84 ( V_65 , V_131 , V_88 ) ;
if ( V_65 -> V_19 != V_65 -> V_18 ) {
V_162 -> V_70 = F_13 ( V_5 , V_65 -> V_19 ,
V_65 -> V_45 , V_84 , & V_162 -> V_79 ) ;
if ( ! V_162 -> V_70 )
goto V_61;
V_162 -> V_71 = F_13 ( V_5 , V_65 -> V_18 ,
V_65 -> V_45 , V_85 , & V_162 -> V_81 ) ;
if ( ! V_162 -> V_71 )
goto V_184;
} else {
V_162 -> V_71 = F_13 ( V_5 , V_65 -> V_18 ,
V_65 -> V_45 , V_86 , & V_162 -> V_81 ) ;
if ( ! V_162 -> V_71 )
goto V_61;
V_162 -> V_70 = NULL ;
V_162 -> V_79 = V_162 -> V_81 ;
}
V_115 = - V_138 ;
F_57 ( & V_5 -> V_165 , V_163 ) ;
if ( F_31 ( F_3 ( V_5 ) ) ||
V_5 -> V_159 + 1 > V_5 -> V_39 ) {
if ( ! ( V_65 -> V_69 . V_163 & V_166 ) ) {
V_115 = - V_164 ;
F_58 ( & V_5 -> V_165 , V_163 ) ;
goto V_167;
}
F_59 ( & V_162 -> V_160 , & V_5 -> V_158 ) ;
} else {
F_59 ( & V_162 -> V_160 , & V_5 -> V_158 ) ;
F_50 ( V_5 ) ;
}
F_58 ( & V_5 -> V_165 , V_163 ) ;
goto V_61;
V_167:
F_28 ( V_162 , V_162 -> V_71 , V_162 -> V_81 , V_65 -> V_18 ,
V_65 -> V_45 , V_65 -> V_19 == V_65 -> V_18 ?
V_86 : V_85 ) ;
V_184:
if ( V_65 -> V_19 != V_65 -> V_18 )
F_28 ( V_162 , V_162 -> V_70 , V_162 -> V_79 ,
V_65 -> V_19 , V_65 -> V_45 , V_84 ) ;
V_61:
return V_115 ;
}
static int F_92 ( struct V_98 * V_89 )
{
struct V_91 * V_11 = F_26 ( V_89 ) ;
struct V_2 * V_3 = V_89 -> V_90 ;
struct V_1 * V_1 = F_1 ( V_3 ) ;
struct V_4 * V_5 = V_1 -> V_5 ;
V_11 -> V_93 . V_163 = V_1 -> type ;
V_11 -> V_93 . V_5 = V_5 ;
if ( V_3 -> V_185 & V_174 ) {
V_11 -> V_110 = F_93 ( V_3 -> V_172 , 0 ,
V_173 | V_174 ) ;
if ( F_67 ( V_11 -> V_110 ) ) {
F_68 ( V_5 -> V_59 , L_1 ,
V_3 -> V_172 ) ;
V_11 -> V_110 = NULL ;
}
}
V_11 -> V_93 . V_28 = V_1 -> V_28 ;
V_11 -> V_93 . V_30 = V_1 -> V_30 ;
V_89 -> V_186 . V_187 = sizeof( struct V_64 ) ;
return 0 ;
}
static void F_94 ( struct V_98 * V_89 )
{
struct V_91 * V_11 = F_26 ( V_89 ) ;
if ( V_11 -> V_110 )
F_95 ( V_11 -> V_110 ) ;
V_11 -> V_110 = NULL ;
}
static int F_96 ( struct V_180 * V_65 )
{
struct V_175 * V_176 = F_85 ( V_65 ) ;
struct V_98 * V_89 = F_74 ( V_176 ) ;
struct V_1 * V_3 = F_1 ( V_89 -> V_90 ) ;
return F_90 ( V_65 , V_3 -> type , 1 ) ;
}
static int F_97 ( struct V_180 * V_65 )
{
struct V_175 * V_176 = F_85 ( V_65 ) ;
struct V_98 * V_89 = F_74 ( V_176 ) ;
struct V_1 * V_3 = F_1 ( V_89 -> V_90 ) ;
return F_90 ( V_65 , V_3 -> type , 0 ) ;
}
static inline int F_98 ( struct V_4 * V_5 )
{
return F_4 ( V_5 -> V_7 + V_8 ) &
V_188 ;
}
static void F_99 ( struct V_4 * V_5 )
{
struct V_64 * V_65 ;
unsigned long V_163 ;
F_57 ( & V_5 -> V_165 , V_163 ) ;
while ( ! F_98 ( V_5 ) ) {
V_65 = F_52 ( & V_5 -> V_161 , struct V_64 ,
V_160 ) ;
F_53 ( & V_65 -> V_160 , & V_5 -> V_189 ) ;
-- V_5 -> V_159 ;
F_7 ( ~ 0 , V_5 -> V_7 + V_190 ) ;
V_65 -> V_134 = ( F_4 ( V_5 -> V_7 + V_191 ) &
V_192 ) >> V_193 ;
if ( F_31 ( V_65 -> V_134 ) ) {
switch ( V_65 -> V_134 ) {
case V_194 :
V_65 -> V_134 = - V_195 ;
break;
case V_196 :
F_68 ( V_5 -> V_59 ,
L_2 ) ;
V_65 -> V_134 = - V_197 ;
break;
case V_198 :
F_68 ( V_5 -> V_59 ,
L_3 ) ;
V_65 -> V_134 = - V_199 ;
break;
}
}
}
F_100 ( & V_5 -> V_133 ) ;
F_58 ( & V_5 -> V_165 , V_163 ) ;
}
static T_7 F_101 ( int V_200 , void * V_59 )
{
struct V_4 * V_5 = (struct V_4 * ) V_59 ;
T_1 V_201 = F_4 ( V_5 -> V_7 + V_202 ) ;
F_7 ( V_201 , V_5 -> V_7 + V_202 ) ;
F_99 ( V_5 ) ;
return V_203 ;
}
static void F_102 ( unsigned long V_204 )
{
struct V_4 * V_5 = (struct V_4 * ) V_204 ;
F_99 ( V_5 ) ;
}
static int F_54 ( struct V_64 * V_65 )
{
struct V_2 * V_3 = V_65 -> V_65 -> V_89 -> V_90 ;
if ( V_205 == ( V_206 & V_3 -> V_185 ) )
return F_48 ( V_65 ) ;
else
return F_82 ( V_65 ) ;
}
static void F_103 ( unsigned long V_204 )
{
struct V_4 * V_5 = (struct V_4 * ) V_204 ;
struct V_64 * V_65 , * V_100 ;
unsigned long V_163 ;
F_104 ( V_189 ) ;
F_57 ( & V_5 -> V_165 , V_163 ) ;
F_105 ( & V_5 -> V_189 , & V_189 ) ;
F_50 ( V_5 ) ;
if ( V_5 -> V_159 )
F_49 ( & V_5 -> V_154 , V_155 + V_156 ) ;
F_58 ( & V_5 -> V_165 , V_163 ) ;
F_106 (req, tmp, &completed, list) {
F_107 ( & V_65 -> V_160 ) ;
V_65 -> V_133 ( V_65 ) ;
}
}
static int F_108 ( struct V_207 * V_59 )
{
struct V_208 * V_209 = F_109 ( V_59 ) ;
struct V_4 * V_5 = F_110 ( V_209 ) ;
F_111 ( V_5 -> V_210 ) ;
return 0 ;
}
static int F_112 ( struct V_207 * V_59 )
{
struct V_208 * V_209 = F_109 ( V_59 ) ;
struct V_4 * V_5 = F_110 ( V_209 ) ;
return F_113 ( V_5 -> V_210 ) ;
}
static inline struct V_4 * F_114 ( struct V_207 * V_59 )
{
return V_59 ? F_110 ( F_109 ( V_59 ) ) : NULL ;
}
static T_8 F_115 ( struct V_207 * V_59 ,
struct V_211 * V_212 ,
char * V_213 )
{
struct V_4 * V_5 = F_114 ( V_59 ) ;
return snprintf ( V_213 , V_214 , L_4 , V_5 -> V_215 ) ;
}
static T_8 F_116 ( struct V_207 * V_59 ,
struct V_211 * V_212 ,
const char * V_213 , T_4 V_49 )
{
struct V_4 * V_5 = F_114 ( V_59 ) ;
unsigned long V_216 ;
if ( F_117 ( V_213 , 0 , & V_216 ) )
return - V_105 ;
V_216 = F_118 ( V_216 , 1UL , V_5 -> V_39 - 1 ) ;
V_5 -> V_215 = V_216 ;
F_7 ( V_5 -> V_215 << V_217 ,
V_5 -> V_7 + V_218 ) ;
return V_49 ;
}
static bool F_119 ( struct V_208 * V_209 ,
const char * V_219 )
{
const struct V_220 * V_221 = F_120 ( V_209 ) ;
if ( V_221 && ! strcmp ( V_221 -> V_222 , V_219 ) )
return true ;
#ifdef F_121
if ( F_122 ( V_209 -> V_59 . V_223 , V_219 ) )
return true ;
#endif
return false ;
}
static int F_123 ( struct V_208 * V_209 )
{
int V_58 , V_115 , V_224 = - V_105 ;
struct V_225 * V_226 , * V_200 ;
struct V_4 * V_5 = F_124 ( & V_209 -> V_59 , sizeof( * V_5 ) ,
V_227 ) ;
if ( ! V_5 )
return - V_80 ;
if ( F_119 ( V_209 , L_5 ) ) {
V_5 -> V_228 = V_229 ;
V_5 -> V_15 = V_230 ;
V_5 -> V_17 = V_231 ;
V_5 -> V_39 = V_232 ;
V_5 -> V_233 = V_234 ;
V_5 -> V_235 = F_125 ( V_234 ) ;
} else if ( F_119 ( V_209 , L_6 ) ) {
V_5 -> V_228 = V_236 ;
V_5 -> V_15 = V_237 ;
V_5 -> V_17 = V_238 ;
V_5 -> V_39 = V_239 ;
V_5 -> V_233 = V_240 ;
V_5 -> V_235 = F_125 ( V_240 ) ;
} else {
return - V_105 ;
}
V_5 -> V_222 = F_126 ( & V_209 -> V_59 ) ;
V_226 = F_127 ( V_209 , V_241 , 0 ) ;
V_5 -> V_7 = F_128 ( & V_209 -> V_59 , V_226 ) ;
if ( F_67 ( V_5 -> V_7 ) )
return F_129 ( V_5 -> V_7 ) ;
V_200 = F_127 ( V_209 , V_242 , 0 ) ;
if ( ! V_200 ) {
F_130 ( & V_209 -> V_59 , L_7 ) ;
return - V_243 ;
}
if ( F_131 ( & V_209 -> V_59 , V_200 -> V_244 , F_101 , 0 ,
V_5 -> V_222 , V_5 ) ) {
F_130 ( V_5 -> V_59 , L_8 ) ;
return - V_164 ;
}
V_5 -> V_59 = & V_209 -> V_59 ;
V_5 -> V_14 = V_5 -> V_7 + V_245 ;
V_5 -> V_16 = V_5 -> V_7 + V_246 ;
V_5 -> V_62 = F_132 ( V_5 -> V_222 , V_5 -> V_59 ,
V_60 * sizeof( struct V_46 ) , 8 , V_247 ) ;
if ( ! V_5 -> V_62 )
return - V_80 ;
F_133 ( & V_5 -> V_165 ) ;
V_5 -> V_210 = F_134 ( & V_209 -> V_59 , L_9 ) ;
if ( F_67 ( V_5 -> V_210 ) ) {
F_135 ( & V_209 -> V_59 , L_10 ) ;
F_136 ( & V_209 -> V_59 , & V_248 ) ;
return F_129 ( V_5 -> V_210 ) ;
}
if ( F_137 ( V_5 -> V_210 ) ) {
F_135 ( & V_209 -> V_59 , L_11 ) ;
F_138 ( V_5 -> V_210 ) ;
return - V_199 ;
}
V_115 = F_139 ( & V_209 -> V_59 , & V_248 ) ;
if ( V_115 ) {
F_140 ( V_5 -> V_210 ) ;
F_138 ( V_5 -> V_210 ) ;
return V_115 ;
}
V_5 -> V_215 = ( V_5 -> V_39 / 2 ) ;
F_7 ( V_5 -> V_215 << V_217 ,
V_5 -> V_7 + V_218 ) ;
F_7 ( V_249 | V_250 ,
V_5 -> V_7 + V_251 ) ;
F_141 ( & V_5 -> V_154 , F_102 ,
( unsigned long ) V_5 ) ;
F_142 ( & V_5 -> V_158 ) ;
F_142 ( & V_5 -> V_189 ) ;
F_142 ( & V_5 -> V_161 ) ;
V_5 -> V_159 = 0 ;
F_143 ( & V_5 -> V_133 , F_103 ,
( unsigned long ) V_5 ) ;
F_144 ( V_209 , V_5 ) ;
F_142 ( & V_5 -> V_252 ) ;
for ( V_58 = 0 ; V_58 < V_5 -> V_235 ; ++ V_58 ) {
V_5 -> V_233 [ V_58 ] . V_5 = V_5 ;
V_115 = F_145 ( & V_5 -> V_233 [ V_58 ] . V_3 ) ;
if ( ! V_115 ) {
F_59 ( & V_5 -> V_233 [ V_58 ] . V_253 ,
& V_5 -> V_252 ) ;
V_224 = 0 ;
}
if ( V_115 )
F_130 ( V_5 -> V_59 , L_12 ,
V_5 -> V_233 [ V_58 ] . V_3 . V_172 ) ;
else
F_146 ( V_5 -> V_59 , L_13 ,
V_5 -> V_233 [ V_58 ] . V_3 . V_172 ) ;
}
return V_224 ;
}
static int F_147 ( struct V_208 * V_209 )
{
struct V_1 * V_3 , * V_254 ;
struct V_4 * V_5 = F_110 ( V_209 ) ;
F_148 ( & V_5 -> V_154 ) ;
F_136 ( & V_209 -> V_59 , & V_248 ) ;
F_106 (alg, next, &engine->registered_algs, entry) {
F_107 ( & V_3 -> V_253 ) ;
F_149 ( & V_3 -> V_3 ) ;
}
F_140 ( V_5 -> V_210 ) ;
F_138 ( V_5 -> V_210 ) ;
return 0 ;
}
