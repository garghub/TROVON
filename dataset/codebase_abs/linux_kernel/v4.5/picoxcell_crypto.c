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
static inline void F_11 ( struct V_45 * V_46 , T_5 V_47 , T_4 V_48 )
{
V_46 -> V_49 = V_47 ;
V_46 -> V_48 = V_48 ;
}
static struct V_45 * F_12 ( struct V_6 * V_7 ,
struct V_50 * V_51 ,
unsigned V_52 ,
enum V_53 V_54 ,
T_5 * V_55 )
{
unsigned V_56 ;
struct V_50 * V_57 ;
struct V_45 * V_46 ;
int V_58 ;
int V_59 ;
V_59 = F_13 ( V_51 , V_52 ) ;
if ( V_59 < 0 ) {
F_14 ( V_7 -> V_60 , L_1 ) ;
return NULL ;
}
V_56 = F_15 ( V_7 -> V_60 , V_51 , V_59 , V_54 ) ;
if ( V_56 + 1 > V_61 )
goto V_62;
V_46 = F_16 ( V_7 -> V_63 , V_64 , V_55 ) ;
if ( ! V_46 )
goto V_62;
F_17 (payload, cur, mapped_ents, i)
F_11 ( & V_46 [ V_58 ] , F_18 ( V_57 ) , F_19 ( V_57 ) ) ;
F_11 ( & V_46 [ V_56 ] , 0 , 0 ) ;
return V_46 ;
V_62:
F_20 ( V_7 -> V_60 , V_51 , V_59 , V_54 ) ;
return NULL ;
}
static int F_21 ( struct V_65 * V_66 )
{
struct V_67 * V_68 = F_22 ( V_66 ) ;
struct V_69 * V_70 = F_23 ( V_66 ) ;
struct V_6 * V_7 = V_70 -> V_7 ;
struct V_45 * V_71 , * V_72 ;
unsigned V_73 ;
int V_74 , V_75 ;
struct V_50 * V_57 ;
int V_58 , V_76 , V_77 ;
V_73 = V_66 -> V_78 + V_66 -> V_79 ;
if ( V_70 -> V_80 )
V_73 += F_24 ( V_68 ) ;
V_74 = F_13 ( V_66 -> V_21 , V_73 ) ;
if ( V_74 < 0 ) {
F_14 ( V_7 -> V_60 , L_2 ) ;
return V_74 ;
}
if ( V_74 + 1 > V_61 )
return - V_81 ;
V_75 = 0 ;
if ( V_66 -> V_21 != V_66 -> V_20 ) {
V_75 = F_13 ( V_66 -> V_20 , V_73 ) ;
if ( V_75 < 0 ) {
F_14 ( V_7 -> V_60 , L_3 ) ;
return V_75 ;
}
if ( V_74 + 1 > V_61 )
return - V_81 ;
}
V_71 = F_16 ( V_7 -> V_63 , V_64 , & V_70 -> V_82 ) ;
if ( ! V_71 )
goto V_83;
V_72 = F_16 ( V_7 -> V_63 , V_64 , & V_70 -> V_84 ) ;
if ( ! V_72 )
goto V_85;
V_70 -> V_71 = V_71 ;
V_70 -> V_72 = V_72 ;
if ( V_75 ) {
V_77 = F_15 ( V_7 -> V_60 , V_66 -> V_21 , V_74 ,
V_86 ) ;
if ( ! V_77 )
goto V_87;
V_76 = F_15 ( V_7 -> V_60 , V_66 -> V_20 , V_75 ,
V_88 ) ;
if ( ! V_76 ) {
F_20 ( V_7 -> V_60 , V_66 -> V_21 , V_74 ,
V_86 ) ;
goto V_87;
}
} else {
V_77 = F_15 ( V_7 -> V_60 , V_66 -> V_21 , V_74 ,
V_89 ) ;
if ( ! V_77 )
goto V_87;
V_76 = V_77 ;
}
F_17 (areq->src, cur, src_ents, i)
F_11 ( V_71 ++ , F_18 ( V_57 ) , F_19 ( V_57 ) ) ;
V_73 = V_70 -> V_80 ? 0 : V_66 -> V_78 ;
F_17 (areq->dst, cur, dst_ents, i) {
unsigned V_48 = F_19 ( V_57 ) ;
if ( V_48 <= V_73 ) {
V_73 -= V_48 ;
continue;
}
F_11 ( V_72 ++ , F_18 ( V_57 ) + V_73 , V_48 - V_73 ) ;
}
F_11 ( V_71 , 0 , 0 ) ;
F_11 ( V_72 , 0 , 0 ) ;
return 0 ;
V_87:
F_25 ( V_7 -> V_63 , V_72 , V_70 -> V_84 ) ;
V_85:
F_25 ( V_7 -> V_63 , V_71 , V_70 -> V_82 ) ;
V_83:
return - V_90 ;
}
static void F_26 ( struct V_69 * V_70 )
{
struct V_65 * V_66 = F_2 ( V_70 -> V_70 , struct V_65 ,
V_91 ) ;
struct V_67 * V_68 = F_22 ( V_66 ) ;
unsigned V_73 = V_66 -> V_78 + V_66 -> V_79 +
( V_70 -> V_80 ? F_24 ( V_68 ) : 0 ) ;
struct V_92 * V_93 = F_27 ( V_68 ) ;
struct V_6 * V_7 = V_93 -> V_94 . V_7 ;
int V_59 = F_13 ( V_66 -> V_21 , V_73 ) ;
if ( F_28 ( V_59 < 0 ) ) {
F_14 ( V_7 -> V_60 , L_2 ) ;
return;
}
if ( V_66 -> V_21 != V_66 -> V_20 ) {
F_20 ( V_7 -> V_60 , V_66 -> V_21 , V_59 , V_86 ) ;
V_59 = F_13 ( V_66 -> V_20 , V_73 ) ;
if ( F_28 ( V_59 < 0 ) ) {
F_14 ( V_7 -> V_60 , L_3 ) ;
return;
}
F_20 ( V_7 -> V_60 , V_66 -> V_20 , V_59 , V_88 ) ;
} else
F_20 ( V_7 -> V_60 , V_66 -> V_21 , V_59 , V_89 ) ;
F_25 ( V_7 -> V_63 , V_70 -> V_71 , V_70 -> V_82 ) ;
F_25 ( V_7 -> V_63 , V_70 -> V_72 , V_70 -> V_84 ) ;
}
static void F_29 ( struct V_69 * V_70 , struct V_45 * V_46 ,
T_5 V_95 , struct V_50 * V_51 ,
unsigned V_52 , enum V_53 V_54 )
{
int V_59 = F_13 ( V_51 , V_52 ) ;
if ( V_59 < 0 ) {
F_14 ( V_70 -> V_7 -> V_60 , L_1 ) ;
return;
}
F_20 ( V_70 -> V_7 -> V_60 , V_51 , V_59 , V_54 ) ;
F_25 ( V_70 -> V_7 -> V_63 , V_46 , V_95 ) ;
}
static int F_30 ( struct V_67 * V_96 , const T_3 * V_25 ,
unsigned int V_97 )
{
struct V_92 * V_13 = F_27 ( V_96 ) ;
struct V_98 V_99 ;
int V_83 ;
F_31 ( V_13 -> V_100 , V_101 ) ;
F_32 ( V_13 -> V_100 , F_33 ( V_96 ) &
V_101 ) ;
V_83 = F_34 ( V_13 -> V_100 , V_25 , V_97 ) ;
F_31 ( V_96 , V_102 ) ;
F_32 ( V_96 , F_33 ( V_13 -> V_100 ) &
V_102 ) ;
if ( V_83 )
return V_83 ;
if ( F_35 ( & V_99 , V_25 , V_97 ) != 0 )
goto V_103;
if ( V_99 . V_104 > V_105 )
goto V_103;
if ( V_99 . V_106 > sizeof( V_13 -> V_107 ) )
goto V_103;
memcpy ( V_13 -> V_108 , V_99 . V_109 , V_99 . V_104 ) ;
V_13 -> V_110 = V_99 . V_104 ;
memcpy ( V_13 -> V_107 , V_99 . V_111 , V_99 . V_106 ) ;
V_13 -> V_112 = V_99 . V_106 ;
return 0 ;
V_103:
F_32 ( V_96 , V_113 ) ;
return - V_114 ;
}
static int F_36 ( struct V_67 * V_96 ,
unsigned int V_115 )
{
struct V_92 * V_13 = F_37 ( F_38 ( V_96 ) ) ;
return F_39 ( V_13 -> V_100 , V_115 ) ;
}
static int F_40 ( struct V_65 * V_116 )
{
struct V_67 * V_68 = F_22 ( V_116 ) ;
struct V_5 * V_3 = F_41 ( V_68 ) ;
struct V_4 * V_1 = F_3 ( V_3 ) ;
struct V_92 * V_13 = F_27 ( V_68 ) ;
if ( ( V_1 -> V_117 & V_118 ) ==
V_119 &&
V_13 -> V_110 != V_120 &&
V_13 -> V_110 != V_121 )
return 1 ;
return 0 ;
}
static int F_42 ( struct V_65 * V_70 , unsigned V_122 ,
bool V_80 )
{
struct V_123 * V_124 = F_38 ( F_22 ( V_70 ) ) ;
struct V_92 * V_13 = F_37 ( V_124 ) ;
struct V_65 * V_125 = F_23 ( V_70 ) ;
F_43 ( V_125 , V_13 -> V_100 ) ;
F_44 ( V_125 , V_70 -> V_91 . V_126 ,
V_70 -> V_91 . V_127 , V_70 -> V_91 . V_128 ) ;
F_45 ( V_125 , V_70 -> V_21 , V_70 -> V_20 , V_70 -> V_79 ,
V_70 -> V_27 ) ;
F_46 ( V_125 , V_70 -> V_78 ) ;
return V_80 ? F_47 ( V_125 ) :
F_48 ( V_125 ) ;
}
static void F_49 ( struct V_69 * V_70 )
{
F_26 ( V_70 ) ;
V_70 -> V_70 -> V_127 ( V_70 -> V_70 , V_70 -> V_129 ) ;
}
static int F_50 ( struct V_69 * V_70 )
{
struct V_65 * V_116 =
F_2 ( V_70 -> V_70 , struct V_65 , V_91 ) ;
struct V_67 * V_68 = F_22 ( V_116 ) ;
unsigned int V_115 = F_24 ( V_68 ) ;
struct V_92 * V_13 = F_27 ( V_68 ) ;
struct V_5 * V_3 = F_41 ( V_68 ) ;
struct V_4 * V_1 = F_3 ( V_3 ) ;
struct V_6 * V_7 = V_13 -> V_94 . V_7 ;
T_1 V_130 , V_131 , V_132 ;
V_70 -> V_129 = - V_133 ;
V_70 -> V_134 = F_10 ( & V_13 -> V_94 , V_13 -> V_108 ,
V_13 -> V_110 , V_116 -> V_27 , F_51 ( V_68 ) ,
V_13 -> V_107 , V_13 -> V_112 ) ;
F_8 ( V_70 -> V_82 , V_7 -> V_9 + V_135 ) ;
F_8 ( V_70 -> V_84 , V_7 -> V_9 + V_136 ) ;
F_8 ( 0 , V_7 -> V_9 + V_137 ) ;
V_132 = V_116 -> V_78 ;
V_131 = V_116 -> V_79 + V_132 ;
if ( ! V_70 -> V_80 )
V_131 -= V_115 ;
F_8 ( V_131 , V_7 -> V_9 + V_138 ) ;
F_8 ( V_132 , V_7 -> V_9 + V_139 ) ;
F_8 ( V_115 , V_7 -> V_9 + V_140 ) ;
F_8 ( 0 , V_7 -> V_9 + V_141 ) ;
F_8 ( 0 , V_7 -> V_9 + V_142 ) ;
V_130 = V_1 -> V_117 | ( V_70 -> V_134 << V_143 ) |
( 1 << V_144 ) ;
if ( V_70 -> V_80 )
V_130 |= ( 1 << V_145 ) | ( 1 << V_146 ) ;
else
V_130 |= ( 1 << V_147 ) ;
F_52 ( & V_7 -> V_148 , V_149 + V_150 ) ;
F_8 ( V_130 , V_7 -> V_9 + V_151 ) ;
return - V_133 ;
}
static void F_53 ( struct V_6 * V_7 )
{
struct V_69 * V_70 ;
while ( ! F_54 ( & V_7 -> V_152 ) &&
V_7 -> V_153 + 1 <= V_7 -> V_41 ) {
++ V_7 -> V_153 ;
V_70 = F_55 ( & V_7 -> V_152 , struct V_69 ,
V_154 ) ;
F_56 ( & V_70 -> V_154 , & V_7 -> V_155 ) ;
V_70 -> V_129 = F_57 ( V_70 ) ;
}
}
static int F_58 ( struct V_65 * V_70 ,
unsigned V_122 , bool V_80 )
{
struct V_67 * V_68 = F_22 ( V_70 ) ;
struct V_5 * V_3 = F_41 ( V_68 ) ;
struct V_6 * V_7 = F_3 ( V_3 ) -> V_7 ;
struct V_69 * V_156 = F_23 ( V_70 ) ;
int V_83 ;
unsigned long V_126 ;
V_156 -> V_70 = & V_70 -> V_91 ;
V_156 -> V_80 = V_80 ;
V_156 -> V_129 = - V_157 ;
V_156 -> V_7 = V_7 ;
V_156 -> V_127 = F_49 ;
if ( F_28 ( F_40 ( V_70 ) ||
( ( V_83 = F_21 ( V_70 ) ) == - V_81 ) ) )
return F_42 ( V_70 , V_122 , V_80 ) ;
if ( V_83 )
goto V_62;
V_83 = - V_133 ;
F_59 ( & V_7 -> V_158 , V_126 ) ;
if ( F_28 ( F_4 ( V_7 ) ) ||
V_7 -> V_153 + 1 > V_7 -> V_41 ) {
if ( ! ( V_70 -> V_91 . V_126 & V_159 ) ) {
V_83 = - V_157 ;
F_60 ( & V_7 -> V_158 , V_126 ) ;
goto V_160;
}
F_61 ( & V_156 -> V_154 , & V_7 -> V_152 ) ;
} else {
F_61 ( & V_156 -> V_154 , & V_7 -> V_152 ) ;
F_53 ( V_7 ) ;
}
F_60 ( & V_7 -> V_158 , V_126 ) ;
goto V_62;
V_160:
F_26 ( V_156 ) ;
V_62:
return V_83 ;
}
static int F_62 ( struct V_65 * V_70 )
{
struct V_67 * V_68 = F_22 ( V_70 ) ;
struct V_4 * V_3 = F_3 ( F_41 ( V_68 ) ) ;
return F_58 ( V_70 , V_3 -> type , 1 ) ;
}
static int F_63 ( struct V_65 * V_70 )
{
struct V_67 * V_68 = F_22 ( V_70 ) ;
struct V_4 * V_3 = F_3 ( F_41 ( V_68 ) ) ;
return F_58 ( V_70 , V_3 -> type , 0 ) ;
}
static int F_64 ( struct V_67 * V_96 )
{
struct V_92 * V_13 = F_27 ( V_96 ) ;
struct V_5 * V_3 = F_41 ( V_96 ) ;
struct V_4 * V_1 = F_3 ( V_3 ) ;
struct V_6 * V_7 = V_1 -> V_7 ;
V_13 -> V_94 . V_126 = V_1 -> type ;
V_13 -> V_94 . V_7 = V_7 ;
V_13 -> V_100 = F_65 ( V_3 -> V_91 . V_161 , 0 ,
V_162 ) ;
if ( F_66 ( V_13 -> V_100 ) )
return F_67 ( V_13 -> V_100 ) ;
V_13 -> V_94 . V_30 = V_1 -> V_30 ;
V_13 -> V_94 . V_32 = V_1 -> V_32 ;
F_68 (
V_96 ,
F_69 ( sizeof( struct V_69 ) ,
sizeof( struct V_65 ) +
F_70 ( V_13 -> V_100 ) ) ) ;
return 0 ;
}
static void F_71 ( struct V_67 * V_96 )
{
struct V_92 * V_13 = F_27 ( V_96 ) ;
F_72 ( V_13 -> V_100 ) ;
}
static int F_73 ( struct V_163 * V_164 , const T_3 * V_25 ,
unsigned int V_48 )
{
struct V_123 * V_96 = F_74 ( V_164 ) ;
struct V_165 * V_13 = F_37 ( V_96 ) ;
T_1 V_166 [ V_167 ] ;
if ( V_48 > V_168 ) {
F_75 ( V_164 , V_113 ) ;
return - V_114 ;
}
if ( F_28 ( ! F_76 ( V_166 , V_25 ) ) &&
( F_77 ( V_164 ) & V_169 ) ) {
V_96 -> V_170 |= V_171 ;
return - V_114 ;
}
memcpy ( V_13 -> V_25 , V_25 , V_48 ) ;
V_13 -> V_26 = V_48 ;
return 0 ;
}
static int F_78 ( struct V_163 * V_164 , const T_3 * V_25 ,
unsigned int V_48 )
{
struct V_123 * V_96 = F_74 ( V_164 ) ;
struct V_165 * V_13 = F_37 ( V_96 ) ;
int V_83 = 0 ;
if ( V_48 > V_105 ) {
F_75 ( V_164 , V_113 ) ;
return - V_114 ;
}
if ( V_48 != V_120 && V_48 != V_121 &&
V_13 -> V_100 ) {
V_13 -> V_100 -> V_91 . V_170 &= ~ V_101 ;
V_13 -> V_100 -> V_91 . V_170 |=
V_164 -> V_91 . V_170 & V_101 ;
V_83 = F_79 ( V_13 -> V_100 , V_25 , V_48 ) ;
if ( V_83 )
goto V_172;
} else if ( V_48 != V_120 && V_48 != V_121 &&
! V_13 -> V_100 )
V_83 = - V_114 ;
memcpy ( V_13 -> V_25 , V_25 , V_48 ) ;
V_13 -> V_26 = V_48 ;
V_172:
if ( V_83 && V_13 -> V_100 ) {
V_96 -> V_170 &= ~ V_102 ;
V_96 -> V_170 |=
V_13 -> V_100 -> V_91 . V_170 & V_102 ;
}
return V_83 ;
}
static int F_80 ( struct V_163 * V_164 ,
const T_3 * V_25 , unsigned int V_48 )
{
struct V_123 * V_96 = F_74 ( V_164 ) ;
struct V_165 * V_13 = F_37 ( V_96 ) ;
int V_83 = 0 ;
if ( V_48 > V_105 ) {
F_75 ( V_164 , V_113 ) ;
V_83 = - V_114 ;
goto V_62;
}
memcpy ( V_13 -> V_25 , V_25 , V_48 ) ;
V_13 -> V_26 = V_48 ;
V_62:
return V_83 ;
}
static int F_81 ( struct V_69 * V_70 )
{
struct V_165 * V_13 ;
struct V_123 * V_96 = V_70 -> V_70 -> V_96 ;
struct V_2 * V_3 = V_70 -> V_70 -> V_96 -> V_173 ;
struct V_1 * V_1 = F_1 ( V_3 ) ;
V_13 = F_37 ( V_96 ) ;
return ( V_1 -> V_117 & V_118 ) ==
V_119 &&
V_13 -> V_26 != V_120 &&
V_13 -> V_26 != V_121 ;
}
static void F_82 ( struct V_69 * V_70 )
{
struct V_174 * V_175 = F_83 ( V_70 -> V_70 ) ;
if ( V_175 -> V_21 != V_175 -> V_20 ) {
F_29 ( V_70 , V_70 -> V_71 , V_70 -> V_82 , V_175 -> V_21 ,
V_175 -> V_52 , V_86 ) ;
F_29 ( V_70 , V_70 -> V_72 , V_70 -> V_84 , V_175 -> V_20 ,
V_175 -> V_52 , V_88 ) ;
} else
F_29 ( V_70 , V_70 -> V_72 , V_70 -> V_84 , V_175 -> V_20 ,
V_175 -> V_52 , V_89 ) ;
V_70 -> V_70 -> V_127 ( V_70 -> V_70 , V_70 -> V_129 ) ;
}
static int F_84 ( struct V_69 * V_70 )
{
struct V_123 * V_96 = V_70 -> V_70 -> V_96 ;
struct V_165 * V_13 = F_37 ( V_96 ) ;
struct V_174 * V_175 = F_83 ( V_70 -> V_70 ) ;
struct V_2 * V_3 = V_70 -> V_70 -> V_96 -> V_173 ;
struct V_1 * V_1 = F_1 ( V_3 ) ;
struct V_6 * V_7 = V_13 -> V_94 . V_7 ;
T_1 V_130 ;
V_70 -> V_134 = F_10 ( & V_13 -> V_94 , V_13 -> V_25 ,
V_13 -> V_26 , V_175 -> V_176 , V_3 -> V_177 . V_178 ,
NULL , 0 ) ;
F_8 ( V_70 -> V_82 , V_7 -> V_9 + V_135 ) ;
F_8 ( V_70 -> V_84 , V_7 -> V_9 + V_136 ) ;
F_8 ( 0 , V_7 -> V_9 + V_137 ) ;
F_8 ( V_175 -> V_52 , V_7 -> V_9 + V_138 ) ;
F_8 ( 0 , V_7 -> V_9 + V_141 ) ;
F_8 ( 0 , V_7 -> V_9 + V_142 ) ;
F_8 ( 0 , V_7 -> V_9 + V_139 ) ;
V_130 = V_1 -> V_117 | ( V_70 -> V_134 << V_143 ) |
( V_70 -> V_80 ? ( 1 << V_145 ) :
( 1 << V_147 ) ) ;
F_52 ( & V_7 -> V_148 , V_149 + V_150 ) ;
F_8 ( V_130 , V_7 -> V_9 + V_151 ) ;
return - V_133 ;
}
static int F_85 ( struct V_174 * V_70 ,
unsigned V_122 , bool V_80 )
{
struct V_123 * V_124 =
F_74 ( F_86 ( V_70 ) ) ;
struct V_165 * V_13 = F_37 ( V_124 ) ;
int V_83 ;
if ( ! V_13 -> V_100 )
return - V_114 ;
F_87 ( V_70 , V_13 -> V_100 ) ;
V_83 = V_80 ? F_88 ( V_70 ) :
F_89 ( V_70 ) ;
F_87 ( V_70 , F_90 ( V_124 ) ) ;
return V_83 ;
}
static int F_91 ( struct V_174 * V_70 , unsigned V_122 ,
bool V_80 )
{
struct V_2 * V_3 = V_70 -> V_91 . V_96 -> V_173 ;
struct V_6 * V_7 = F_1 ( V_3 ) -> V_7 ;
struct V_69 * V_156 = F_92 ( V_70 ) ;
unsigned long V_126 ;
int V_83 = - V_90 ;
V_156 -> V_70 = & V_70 -> V_91 ;
V_156 -> V_80 = V_80 ;
V_156 -> V_7 = V_7 ;
V_156 -> V_127 = F_82 ;
V_156 -> V_129 = - V_133 ;
if ( F_28 ( F_81 ( V_156 ) ) )
return F_85 ( V_70 , V_122 , V_80 ) ;
if ( V_70 -> V_21 != V_70 -> V_20 ) {
V_156 -> V_71 = F_12 ( V_7 , V_70 -> V_21 ,
V_70 -> V_52 , V_86 , & V_156 -> V_82 ) ;
if ( ! V_156 -> V_71 )
goto V_62;
V_156 -> V_72 = F_12 ( V_7 , V_70 -> V_20 ,
V_70 -> V_52 , V_88 , & V_156 -> V_84 ) ;
if ( ! V_156 -> V_72 )
goto V_179;
} else {
V_156 -> V_72 = F_12 ( V_7 , V_70 -> V_20 ,
V_70 -> V_52 , V_89 , & V_156 -> V_84 ) ;
if ( ! V_156 -> V_72 )
goto V_62;
V_156 -> V_71 = NULL ;
V_156 -> V_82 = V_156 -> V_84 ;
}
V_83 = - V_133 ;
F_59 ( & V_7 -> V_158 , V_126 ) ;
if ( F_28 ( F_4 ( V_7 ) ) ||
V_7 -> V_153 + 1 > V_7 -> V_41 ) {
if ( ! ( V_70 -> V_91 . V_126 & V_159 ) ) {
V_83 = - V_157 ;
F_60 ( & V_7 -> V_158 , V_126 ) ;
goto V_160;
}
F_61 ( & V_156 -> V_154 , & V_7 -> V_152 ) ;
} else {
F_61 ( & V_156 -> V_154 , & V_7 -> V_152 ) ;
F_53 ( V_7 ) ;
}
F_60 ( & V_7 -> V_158 , V_126 ) ;
goto V_62;
V_160:
F_29 ( V_156 , V_156 -> V_72 , V_156 -> V_84 , V_70 -> V_20 ,
V_70 -> V_52 , V_70 -> V_21 == V_70 -> V_20 ?
V_89 : V_88 ) ;
V_179:
if ( V_70 -> V_21 != V_70 -> V_20 )
F_29 ( V_156 , V_156 -> V_71 , V_156 -> V_82 ,
V_70 -> V_21 , V_70 -> V_52 , V_86 ) ;
V_62:
return V_83 ;
}
static int F_93 ( struct V_123 * V_96 )
{
struct V_165 * V_13 = F_37 ( V_96 ) ;
struct V_2 * V_3 = V_96 -> V_173 ;
struct V_1 * V_1 = F_1 ( V_3 ) ;
struct V_6 * V_7 = V_1 -> V_7 ;
V_13 -> V_94 . V_126 = V_1 -> type ;
V_13 -> V_94 . V_7 = V_7 ;
if ( V_3 -> V_180 & V_162 ) {
V_13 -> V_100 = F_94 ( V_3 -> V_161 , 0 ,
V_181 | V_162 ) ;
if ( F_66 ( V_13 -> V_100 ) ) {
F_95 ( V_7 -> V_60 , L_4 ,
V_3 -> V_161 ) ;
V_13 -> V_100 = NULL ;
}
}
V_13 -> V_94 . V_30 = V_1 -> V_30 ;
V_13 -> V_94 . V_32 = V_1 -> V_32 ;
V_96 -> V_182 . V_183 = sizeof( struct V_69 ) ;
return 0 ;
}
static void F_96 ( struct V_123 * V_96 )
{
struct V_165 * V_13 = F_37 ( V_96 ) ;
if ( V_13 -> V_100 )
F_97 ( V_13 -> V_100 ) ;
V_13 -> V_100 = NULL ;
}
static int F_98 ( struct V_174 * V_70 )
{
struct V_163 * V_164 = F_86 ( V_70 ) ;
struct V_123 * V_96 = F_74 ( V_164 ) ;
struct V_1 * V_3 = F_1 ( V_96 -> V_173 ) ;
return F_91 ( V_70 , V_3 -> type , 1 ) ;
}
static int F_99 ( struct V_174 * V_70 )
{
struct V_163 * V_164 = F_86 ( V_70 ) ;
struct V_123 * V_96 = F_74 ( V_164 ) ;
struct V_1 * V_3 = F_1 ( V_96 -> V_173 ) ;
return F_91 ( V_70 , V_3 -> type , 0 ) ;
}
static inline int F_100 ( struct V_6 * V_7 )
{
return F_5 ( V_7 -> V_9 + V_10 ) &
V_184 ;
}
static void F_101 ( struct V_6 * V_7 )
{
struct V_69 * V_70 ;
unsigned long V_126 ;
F_59 ( & V_7 -> V_158 , V_126 ) ;
while ( ! F_100 ( V_7 ) ) {
V_70 = F_55 ( & V_7 -> V_155 , struct V_69 ,
V_154 ) ;
F_56 ( & V_70 -> V_154 , & V_7 -> V_185 ) ;
-- V_7 -> V_153 ;
F_8 ( ~ 0 , V_7 -> V_9 + V_186 ) ;
V_70 -> V_129 = ( F_5 ( V_7 -> V_9 + V_187 ) &
V_188 ) >> V_189 ;
if ( F_28 ( V_70 -> V_129 ) ) {
switch ( V_70 -> V_129 ) {
case V_190 :
V_70 -> V_129 = - V_191 ;
break;
case V_192 :
F_95 ( V_7 -> V_60 ,
L_5 ) ;
V_70 -> V_129 = - V_193 ;
break;
case V_194 :
F_95 ( V_7 -> V_60 ,
L_6 ) ;
V_70 -> V_129 = - V_195 ;
break;
}
}
}
F_102 ( & V_7 -> V_127 ) ;
F_60 ( & V_7 -> V_158 , V_126 ) ;
}
static T_6 F_103 ( int V_196 , void * V_60 )
{
struct V_6 * V_7 = (struct V_6 * ) V_60 ;
T_1 V_197 = F_5 ( V_7 -> V_9 + V_198 ) ;
F_8 ( V_197 , V_7 -> V_9 + V_198 ) ;
F_101 ( V_7 ) ;
return V_199 ;
}
static void F_104 ( unsigned long V_128 )
{
struct V_6 * V_7 = (struct V_6 * ) V_128 ;
F_101 ( V_7 ) ;
}
static int F_57 ( struct V_69 * V_70 )
{
struct V_2 * V_3 = V_70 -> V_70 -> V_96 -> V_173 ;
if ( V_200 == ( V_201 & V_3 -> V_180 ) )
return F_50 ( V_70 ) ;
else
return F_84 ( V_70 ) ;
}
static void F_105 ( unsigned long V_128 )
{
struct V_6 * V_7 = (struct V_6 * ) V_128 ;
struct V_69 * V_70 , * V_166 ;
unsigned long V_126 ;
F_106 ( V_185 ) ;
F_59 ( & V_7 -> V_158 , V_126 ) ;
F_107 ( & V_7 -> V_185 , & V_185 ) ;
F_53 ( V_7 ) ;
if ( V_7 -> V_153 )
F_52 ( & V_7 -> V_148 , V_149 + V_150 ) ;
F_60 ( & V_7 -> V_158 , V_126 ) ;
F_108 (req, tmp, &completed, list) {
F_109 ( & V_70 -> V_154 ) ;
V_70 -> V_127 ( V_70 ) ;
}
}
static int F_110 ( struct V_202 * V_60 )
{
struct V_203 * V_204 = F_111 ( V_60 ) ;
struct V_6 * V_7 = F_112 ( V_204 ) ;
F_113 ( V_7 -> V_205 ) ;
return 0 ;
}
static int F_114 ( struct V_202 * V_60 )
{
struct V_203 * V_204 = F_111 ( V_60 ) ;
struct V_6 * V_7 = F_112 ( V_204 ) ;
return F_115 ( V_7 -> V_205 ) ;
}
static inline struct V_6 * F_116 ( struct V_202 * V_60 )
{
return V_60 ? F_112 ( F_111 ( V_60 ) ) : NULL ;
}
static T_7 F_117 ( struct V_202 * V_60 ,
struct V_206 * V_207 ,
char * V_208 )
{
struct V_6 * V_7 = F_116 ( V_60 ) ;
return snprintf ( V_208 , V_209 , L_7 , V_7 -> V_210 ) ;
}
static T_7 F_118 ( struct V_202 * V_60 ,
struct V_206 * V_207 ,
const char * V_208 , T_4 V_48 )
{
struct V_6 * V_7 = F_116 ( V_60 ) ;
unsigned long V_211 ;
if ( F_119 ( V_208 , 0 , & V_211 ) )
return - V_114 ;
V_211 = F_120 ( V_211 , 1UL , V_7 -> V_41 - 1 ) ;
V_7 -> V_210 = V_211 ;
F_8 ( V_7 -> V_210 << V_212 ,
V_7 -> V_9 + V_213 ) ;
return V_48 ;
}
static bool F_121 ( struct V_203 * V_204 ,
const char * V_214 )
{
const struct V_215 * V_216 = F_122 ( V_204 ) ;
if ( V_216 && ! strcmp ( V_216 -> V_217 , V_214 ) )
return true ;
#ifdef F_123
if ( F_124 ( V_204 -> V_60 . V_218 , V_214 ) )
return true ;
#endif
return false ;
}
static int F_125 ( struct V_203 * V_204 )
{
int V_58 , V_83 , V_219 = - V_114 ;
struct V_220 * V_221 , * V_196 ;
struct V_6 * V_7 = F_126 ( & V_204 -> V_60 , sizeof( * V_7 ) ,
V_222 ) ;
if ( ! V_7 )
return - V_90 ;
if ( F_121 ( V_204 , L_8 ) ) {
V_7 -> V_223 = V_224 ;
V_7 -> V_17 = V_225 ;
V_7 -> V_19 = V_226 ;
V_7 -> V_41 = V_227 ;
V_7 -> V_228 = V_229 ;
V_7 -> V_230 = F_127 ( V_229 ) ;
V_7 -> V_231 = V_232 ;
V_7 -> V_233 = F_127 ( V_232 ) ;
} else if ( F_121 ( V_204 , L_9 ) ) {
V_7 -> V_223 = V_234 ;
V_7 -> V_17 = V_235 ;
V_7 -> V_19 = V_236 ;
V_7 -> V_41 = V_237 ;
V_7 -> V_228 = V_238 ;
V_7 -> V_230 = F_127 ( V_238 ) ;
} else {
return - V_114 ;
}
V_7 -> V_217 = F_128 ( & V_204 -> V_60 ) ;
V_221 = F_129 ( V_204 , V_239 , 0 ) ;
V_7 -> V_9 = F_130 ( & V_204 -> V_60 , V_221 ) ;
if ( F_66 ( V_7 -> V_9 ) )
return F_67 ( V_7 -> V_9 ) ;
V_196 = F_129 ( V_204 , V_240 , 0 ) ;
if ( ! V_196 ) {
F_14 ( & V_204 -> V_60 , L_10 ) ;
return - V_241 ;
}
if ( F_131 ( & V_204 -> V_60 , V_196 -> V_242 , F_103 , 0 ,
V_7 -> V_217 , V_7 ) ) {
F_14 ( V_7 -> V_60 , L_11 ) ;
return - V_157 ;
}
V_7 -> V_60 = & V_204 -> V_60 ;
V_7 -> V_16 = V_7 -> V_9 + V_243 ;
V_7 -> V_18 = V_7 -> V_9 + V_244 ;
V_7 -> V_63 = F_132 ( V_7 -> V_217 , V_7 -> V_60 ,
V_61 * sizeof( struct V_45 ) , 8 , V_245 ) ;
if ( ! V_7 -> V_63 )
return - V_90 ;
F_133 ( & V_7 -> V_158 ) ;
V_7 -> V_205 = F_134 ( & V_204 -> V_60 , L_12 ) ;
if ( F_66 ( V_7 -> V_205 ) ) {
F_135 ( & V_204 -> V_60 , L_13 ) ;
F_136 ( & V_204 -> V_60 , & V_246 ) ;
return F_67 ( V_7 -> V_205 ) ;
}
if ( F_137 ( V_7 -> V_205 ) ) {
F_135 ( & V_204 -> V_60 , L_14 ) ;
F_138 ( V_7 -> V_205 ) ;
return - V_195 ;
}
V_83 = F_139 ( & V_204 -> V_60 , & V_246 ) ;
if ( V_83 ) {
F_140 ( V_7 -> V_205 ) ;
F_138 ( V_7 -> V_205 ) ;
return V_83 ;
}
V_7 -> V_210 = ( V_7 -> V_41 / 2 ) ;
F_8 ( V_7 -> V_210 << V_212 ,
V_7 -> V_9 + V_213 ) ;
F_8 ( V_247 | V_248 ,
V_7 -> V_9 + V_249 ) ;
F_141 ( & V_7 -> V_148 , F_104 ,
( unsigned long ) V_7 ) ;
F_142 ( & V_7 -> V_152 ) ;
F_142 ( & V_7 -> V_185 ) ;
F_142 ( & V_7 -> V_155 ) ;
V_7 -> V_153 = 0 ;
F_143 ( & V_7 -> V_127 , F_105 ,
( unsigned long ) V_7 ) ;
F_144 ( V_204 , V_7 ) ;
F_142 ( & V_7 -> V_250 ) ;
for ( V_58 = 0 ; V_58 < V_7 -> V_230 ; ++ V_58 ) {
V_7 -> V_228 [ V_58 ] . V_7 = V_7 ;
V_83 = F_145 ( & V_7 -> V_228 [ V_58 ] . V_3 ) ;
if ( ! V_83 ) {
F_61 ( & V_7 -> V_228 [ V_58 ] . V_251 ,
& V_7 -> V_250 ) ;
V_219 = 0 ;
}
if ( V_83 )
F_14 ( V_7 -> V_60 , L_15 ,
V_7 -> V_228 [ V_58 ] . V_3 . V_161 ) ;
else
F_146 ( V_7 -> V_60 , L_16 ,
V_7 -> V_228 [ V_58 ] . V_3 . V_161 ) ;
}
F_142 ( & V_7 -> V_252 ) ;
for ( V_58 = 0 ; V_58 < V_7 -> V_233 ; ++ V_58 ) {
V_7 -> V_231 [ V_58 ] . V_7 = V_7 ;
V_83 = F_147 ( & V_7 -> V_231 [ V_58 ] . V_3 ) ;
if ( ! V_83 ) {
F_61 ( & V_7 -> V_231 [ V_58 ] . V_251 ,
& V_7 -> V_252 ) ;
V_219 = 0 ;
}
if ( V_83 )
F_14 ( V_7 -> V_60 , L_15 ,
V_7 -> V_231 [ V_58 ] . V_3 . V_91 . V_161 ) ;
else
F_146 ( V_7 -> V_60 , L_16 ,
V_7 -> V_231 [ V_58 ] . V_3 . V_91 . V_161 ) ;
}
return V_219 ;
}
static int F_148 ( struct V_203 * V_204 )
{
struct V_4 * V_68 , * V_253 ;
struct V_1 * V_3 , * V_254 ;
struct V_6 * V_7 = F_112 ( V_204 ) ;
F_149 ( & V_7 -> V_148 ) ;
F_136 ( & V_204 -> V_60 , & V_246 ) ;
F_108 (aead, an, &engine->registered_aeads, entry) {
F_109 ( & V_68 -> V_251 ) ;
F_150 ( & V_68 -> V_3 ) ;
}
F_108 (alg, next, &engine->registered_algs, entry) {
F_109 ( & V_3 -> V_251 ) ;
F_151 ( & V_3 -> V_3 ) ;
}
F_140 ( V_7 -> V_205 ) ;
F_138 ( V_7 -> V_205 ) ;
return 0 ;
}
