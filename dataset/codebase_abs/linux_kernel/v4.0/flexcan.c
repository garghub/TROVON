static inline T_1 F_1 ( void T_2 * V_1 )
{
return F_2 ( V_1 ) ;
}
static inline void F_3 ( T_1 V_2 , void T_2 * V_1 )
{
F_4 ( V_1 , V_2 ) ;
}
static inline T_1 F_1 ( void T_2 * V_1 )
{
return F_5 ( V_1 ) ;
}
static inline void F_3 ( T_1 V_2 , void T_2 * V_1 )
{
F_6 ( V_2 , V_1 ) ;
}
static inline int F_7 ( const struct V_3 * V_4 )
{
if ( ! V_4 -> V_5 )
return 0 ;
return F_8 ( V_4 -> V_5 ) ;
}
static inline int F_9 ( const struct V_3 * V_4 )
{
if ( ! V_4 -> V_5 )
return 0 ;
return F_10 ( V_4 -> V_5 ) ;
}
static inline int F_11 ( const struct V_3 * V_4 ,
T_1 V_6 )
{
return ( V_4 -> V_7 . V_8 & V_9 ) &&
( V_6 & V_10 ) ;
}
static int F_12 ( struct V_3 * V_4 )
{
struct V_11 T_2 * V_12 = V_4 -> V_13 ;
unsigned int V_14 = V_15 / 10 ;
T_1 V_16 ;
V_16 = F_1 ( & V_12 -> V_17 ) ;
V_16 &= ~ V_18 ;
F_3 ( V_16 , & V_12 -> V_17 ) ;
while ( V_14 -- && ( F_1 ( & V_12 -> V_17 ) & V_19 ) )
F_13 ( 10 ) ;
if ( F_1 ( & V_12 -> V_17 ) & V_19 )
return - V_20 ;
return 0 ;
}
static int F_14 ( struct V_3 * V_4 )
{
struct V_11 T_2 * V_12 = V_4 -> V_13 ;
unsigned int V_14 = V_15 / 10 ;
T_1 V_16 ;
V_16 = F_1 ( & V_12 -> V_17 ) ;
V_16 |= V_18 ;
F_3 ( V_16 , & V_12 -> V_17 ) ;
while ( V_14 -- && ! ( F_1 ( & V_12 -> V_17 ) & V_19 ) )
F_13 ( 10 ) ;
if ( ! ( F_1 ( & V_12 -> V_17 ) & V_19 ) )
return - V_20 ;
return 0 ;
}
static int F_15 ( struct V_3 * V_4 )
{
struct V_11 T_2 * V_12 = V_4 -> V_13 ;
unsigned int V_14 = 1000 * 1000 * 10 / V_4 -> V_7 . V_21 . V_22 ;
T_1 V_16 ;
V_16 = F_1 ( & V_12 -> V_17 ) ;
V_16 |= V_23 ;
F_3 ( V_16 , & V_12 -> V_17 ) ;
while ( V_14 -- && ! ( F_1 ( & V_12 -> V_17 ) & V_24 ) )
F_13 ( 100 ) ;
if ( ! ( F_1 ( & V_12 -> V_17 ) & V_24 ) )
return - V_20 ;
return 0 ;
}
static int F_16 ( struct V_3 * V_4 )
{
struct V_11 T_2 * V_12 = V_4 -> V_13 ;
unsigned int V_14 = V_15 / 10 ;
T_1 V_16 ;
V_16 = F_1 ( & V_12 -> V_17 ) ;
V_16 &= ~ V_23 ;
F_3 ( V_16 , & V_12 -> V_17 ) ;
while ( V_14 -- && ( F_1 ( & V_12 -> V_17 ) & V_24 ) )
F_13 ( 10 ) ;
if ( F_1 ( & V_12 -> V_17 ) & V_24 )
return - V_20 ;
return 0 ;
}
static int F_17 ( struct V_3 * V_4 )
{
struct V_11 T_2 * V_12 = V_4 -> V_13 ;
unsigned int V_14 = V_15 / 10 ;
F_3 ( V_25 , & V_12 -> V_17 ) ;
while ( V_14 -- && ( F_1 ( & V_12 -> V_17 ) & V_25 ) )
F_13 ( 10 ) ;
if ( F_1 ( & V_12 -> V_17 ) & V_25 )
return - V_20 ;
return 0 ;
}
static int F_18 ( const struct V_26 * V_27 ,
struct V_28 * V_29 )
{
const struct V_3 * V_4 = F_19 ( V_27 ) ;
struct V_11 T_2 * V_12 = V_4 -> V_13 ;
T_1 V_16 = F_1 ( & V_12 -> V_30 ) ;
V_29 -> V_31 = ( V_16 >> 0 ) & 0xff ;
V_29 -> V_32 = ( V_16 >> 8 ) & 0xff ;
return 0 ;
}
static int F_20 ( const struct V_26 * V_27 ,
struct V_28 * V_29 )
{
const struct V_3 * V_4 = F_19 ( V_27 ) ;
int V_33 ;
V_33 = F_21 ( V_4 -> V_34 ) ;
if ( V_33 )
return V_33 ;
V_33 = F_21 ( V_4 -> V_35 ) ;
if ( V_33 )
goto V_36;
V_33 = F_18 ( V_27 , V_29 ) ;
F_22 ( V_4 -> V_35 ) ;
V_36:
F_22 ( V_4 -> V_34 ) ;
return V_33 ;
}
static int F_23 ( struct V_37 * V_38 , struct V_26 * V_27 )
{
const struct V_3 * V_4 = F_19 ( V_27 ) ;
struct V_11 T_2 * V_12 = V_4 -> V_13 ;
struct V_39 * V_40 = (struct V_39 * ) V_38 -> V_41 ;
T_1 V_42 ;
T_1 V_43 = F_24 ( 0xc ) | ( V_40 -> V_44 << 16 ) ;
if ( F_25 ( V_27 , V_38 ) )
return V_45 ;
F_26 ( V_27 ) ;
if ( V_40 -> V_42 & V_46 ) {
V_42 = V_40 -> V_42 & V_47 ;
V_43 |= V_48 | V_49 ;
} else {
V_42 = ( V_40 -> V_42 & V_50 ) << 18 ;
}
if ( V_40 -> V_42 & V_51 )
V_43 |= V_52 ;
if ( V_40 -> V_44 > 0 ) {
T_1 V_41 = F_27 ( ( V_53 * ) & V_40 -> V_41 [ 0 ] ) ;
F_3 ( V_41 , & V_12 -> V_54 [ V_55 ] . V_41 [ 0 ] ) ;
}
if ( V_40 -> V_44 > 3 ) {
T_1 V_41 = F_27 ( ( V_53 * ) & V_40 -> V_41 [ 4 ] ) ;
F_3 ( V_41 , & V_12 -> V_54 [ V_55 ] . V_41 [ 1 ] ) ;
}
F_28 ( V_38 , V_27 , 0 ) ;
F_3 ( V_42 , & V_12 -> V_54 [ V_55 ] . V_42 ) ;
F_3 ( V_43 , & V_12 -> V_54 [ V_55 ] . V_56 ) ;
F_3 ( V_57 ,
& V_12 -> V_54 [ V_58 ] . V_56 ) ;
F_3 ( V_57 ,
& V_12 -> V_54 [ V_58 ] . V_56 ) ;
return V_45 ;
}
static void F_29 ( struct V_26 * V_27 ,
struct V_39 * V_40 , T_1 V_6 )
{
struct V_3 * V_4 = F_19 ( V_27 ) ;
int V_59 = 0 , V_60 = 0 ;
V_40 -> V_42 |= V_61 | V_62 ;
if ( V_6 & V_63 ) {
F_30 ( V_27 , L_1 ) ;
V_40 -> V_41 [ 2 ] |= V_64 ;
V_60 = 1 ;
}
if ( V_6 & V_65 ) {
F_30 ( V_27 , L_2 ) ;
V_40 -> V_41 [ 2 ] |= V_66 ;
V_60 = 1 ;
}
if ( V_6 & V_67 ) {
F_30 ( V_27 , L_3 ) ;
V_40 -> V_42 |= V_68 ;
V_40 -> V_41 [ 3 ] |= V_69 ;
V_60 = 1 ;
}
if ( V_6 & V_70 ) {
F_30 ( V_27 , L_4 ) ;
V_40 -> V_41 [ 2 ] |= V_71 ;
V_40 -> V_41 [ 3 ] |= V_72 ;
V_59 = 1 ;
}
if ( V_6 & V_73 ) {
F_30 ( V_27 , L_5 ) ;
V_40 -> V_41 [ 2 ] |= V_74 ;
V_59 = 1 ;
}
if ( V_6 & V_75 ) {
F_30 ( V_27 , L_6 ) ;
V_40 -> V_41 [ 2 ] |= V_76 ;
V_59 = 1 ;
}
V_4 -> V_7 . V_77 . V_78 ++ ;
if ( V_59 )
V_27 -> V_79 . V_59 ++ ;
if ( V_60 )
V_27 -> V_79 . V_60 ++ ;
}
static int F_31 ( struct V_26 * V_27 , T_1 V_6 )
{
struct V_37 * V_38 ;
struct V_39 * V_40 ;
V_38 = F_32 ( V_27 , & V_40 ) ;
if ( F_33 ( ! V_38 ) )
return 0 ;
F_29 ( V_27 , V_40 , V_6 ) ;
F_34 ( V_38 ) ;
V_27 -> V_79 . V_80 ++ ;
V_27 -> V_79 . V_81 += V_40 -> V_44 ;
return 1 ;
}
static int F_35 ( struct V_26 * V_27 , T_1 V_6 )
{
struct V_3 * V_4 = F_19 ( V_27 ) ;
struct V_37 * V_38 ;
struct V_39 * V_40 ;
enum V_82 V_83 = 0 , V_84 = 0 , V_85 = 0 ;
int V_86 ;
struct V_28 V_29 ;
V_86 = V_6 & V_87 ;
if ( F_36 ( V_86 == V_88 ) ) {
V_85 = F_33 ( V_6 & V_89 ) ?
V_90 : V_91 ;
V_84 = F_33 ( V_6 & V_92 ) ?
V_90 : V_91 ;
V_83 = F_37 ( V_85 , V_84 ) ;
} else {
F_18 ( V_27 , & V_29 ) ;
V_83 = V_86 == V_93 ?
V_94 : V_95 ;
V_84 = V_29 . V_32 >= V_29 . V_31 ? V_83 : 0 ;
V_85 = V_29 . V_32 <= V_29 . V_31 ? V_83 : 0 ;
}
if ( F_36 ( V_83 == V_4 -> V_7 . V_96 ) )
return 0 ;
V_38 = F_32 ( V_27 , & V_40 ) ;
if ( F_33 ( ! V_38 ) )
return 0 ;
F_38 ( V_27 , V_40 , V_85 , V_84 ) ;
if ( F_33 ( V_83 == V_95 ) )
F_39 ( V_27 ) ;
F_34 ( V_38 ) ;
V_27 -> V_79 . V_80 ++ ;
V_27 -> V_79 . V_81 += V_40 -> V_44 ;
return 1 ;
}
static void F_40 ( const struct V_26 * V_27 ,
struct V_39 * V_40 )
{
const struct V_3 * V_4 = F_19 ( V_27 ) ;
struct V_11 T_2 * V_12 = V_4 -> V_13 ;
struct V_97 T_2 * V_98 = & V_12 -> V_54 [ 0 ] ;
T_1 V_99 , V_100 ;
V_99 = F_1 ( & V_98 -> V_56 ) ;
V_100 = F_1 ( & V_98 -> V_42 ) ;
if ( V_99 & V_48 )
V_40 -> V_42 = ( ( V_100 >> 0 ) & V_47 ) | V_46 ;
else
V_40 -> V_42 = ( V_100 >> 18 ) & V_50 ;
if ( V_99 & V_52 )
V_40 -> V_42 |= V_51 ;
V_40 -> V_44 = F_41 ( ( V_99 >> 16 ) & 0xf ) ;
* ( V_53 * ) ( V_40 -> V_41 + 0 ) = F_42 ( F_1 ( & V_98 -> V_41 [ 0 ] ) ) ;
* ( V_53 * ) ( V_40 -> V_41 + 4 ) = F_42 ( F_1 ( & V_98 -> V_41 [ 1 ] ) ) ;
F_3 ( V_101 , & V_12 -> V_102 ) ;
F_1 ( & V_12 -> V_103 ) ;
}
static int F_43 ( struct V_26 * V_27 )
{
struct V_104 * V_79 = & V_27 -> V_79 ;
struct V_39 * V_40 ;
struct V_37 * V_38 ;
V_38 = F_44 ( V_27 , & V_40 ) ;
if ( F_33 ( ! V_38 ) ) {
V_79 -> V_105 ++ ;
return 0 ;
}
F_40 ( V_27 , V_40 ) ;
F_34 ( V_38 ) ;
V_79 -> V_80 ++ ;
V_79 -> V_81 += V_40 -> V_44 ;
F_45 ( V_27 , V_106 ) ;
return 1 ;
}
static int F_46 ( struct V_107 * V_108 , int V_109 )
{
struct V_26 * V_27 = V_108 -> V_27 ;
const struct V_3 * V_4 = F_19 ( V_27 ) ;
struct V_11 T_2 * V_12 = V_4 -> V_13 ;
T_1 V_110 , V_6 ;
int V_111 = 0 ;
V_6 = F_1 ( & V_12 -> V_112 ) | V_4 -> V_6 ;
V_111 += F_35 ( V_27 , V_6 ) ;
V_110 = F_1 ( & V_12 -> V_102 ) ;
while ( V_110 & V_101 &&
V_111 < V_109 ) {
V_111 += F_43 ( V_27 ) ;
V_110 = F_1 ( & V_12 -> V_102 ) ;
}
if ( F_11 ( V_4 , V_6 ) && V_111 < V_109 )
V_111 += F_31 ( V_27 , V_6 ) ;
if ( V_111 < V_109 ) {
F_47 ( V_108 ) ;
F_3 ( V_113 , & V_12 -> V_114 ) ;
F_3 ( V_4 -> V_115 , & V_12 -> V_43 ) ;
}
return V_111 ;
}
static T_3 F_48 ( int V_116 , void * V_117 )
{
struct V_26 * V_27 = V_117 ;
struct V_104 * V_79 = & V_27 -> V_79 ;
struct V_3 * V_4 = F_19 ( V_27 ) ;
struct V_11 T_2 * V_12 = V_4 -> V_13 ;
T_1 V_110 , V_6 ;
V_110 = F_1 ( & V_12 -> V_102 ) ;
V_6 = F_1 ( & V_12 -> V_112 ) ;
if ( V_6 & V_118 )
F_3 ( V_6 & V_118 , & V_12 -> V_112 ) ;
if ( ( V_110 & V_101 ) ||
( V_6 & V_119 ) ||
F_11 ( V_4 , V_6 ) ) {
V_4 -> V_6 = V_6 & V_10 ;
F_3 ( V_113 &
~ V_101 , & V_12 -> V_114 ) ;
F_3 ( V_4 -> V_115 & ~ V_120 ,
& V_12 -> V_43 ) ;
F_49 ( & V_4 -> V_108 ) ;
}
if ( V_110 & V_121 ) {
F_3 ( V_121 , & V_12 -> V_102 ) ;
V_27 -> V_79 . V_122 ++ ;
V_27 -> V_79 . V_59 ++ ;
}
if ( V_110 & ( 1 << V_55 ) ) {
V_79 -> V_123 += F_50 ( V_27 , 0 ) ;
V_79 -> V_124 ++ ;
F_45 ( V_27 , V_125 ) ;
F_3 ( V_57 ,
& V_12 -> V_54 [ V_55 ] . V_56 ) ;
F_3 ( ( 1 << V_55 ) , & V_12 -> V_102 ) ;
F_51 ( V_27 ) ;
}
return V_126 ;
}
static void F_52 ( struct V_26 * V_27 )
{
const struct V_3 * V_4 = F_19 ( V_27 ) ;
const struct V_127 * V_128 = & V_4 -> V_7 . V_21 ;
struct V_11 T_2 * V_12 = V_4 -> V_13 ;
T_1 V_16 ;
V_16 = F_1 ( & V_12 -> V_43 ) ;
V_16 &= ~ ( F_53 ( 0xff ) |
F_54 ( 0x3 ) |
F_55 ( 0x7 ) |
F_56 ( 0x7 ) |
F_57 ( 0x7 ) |
V_129 |
V_130 |
V_131 ) ;
V_16 |= F_53 ( V_128 -> V_132 - 1 ) |
F_55 ( V_128 -> V_133 - 1 ) |
F_56 ( V_128 -> V_134 - 1 ) |
F_54 ( V_128 -> V_135 - 1 ) |
F_57 ( V_128 -> V_136 - 1 ) ;
if ( V_4 -> V_7 . V_8 & V_137 )
V_16 |= V_129 ;
if ( V_4 -> V_7 . V_8 & V_138 )
V_16 |= V_131 ;
if ( V_4 -> V_7 . V_8 & V_139 )
V_16 |= V_130 ;
F_58 ( V_27 , L_7 , V_16 ) ;
F_3 ( V_16 , & V_12 -> V_43 ) ;
F_30 ( V_27 , L_8 , V_140 ,
F_1 ( & V_12 -> V_17 ) , F_1 ( & V_12 -> V_43 ) ) ;
}
static int F_59 ( struct V_26 * V_27 )
{
struct V_3 * V_4 = F_19 ( V_27 ) ;
struct V_11 T_2 * V_12 = V_4 -> V_13 ;
T_1 V_141 , V_99 , V_142 , V_143 ;
int V_33 , V_144 ;
V_33 = F_12 ( V_4 ) ;
if ( V_33 )
return V_33 ;
V_33 = F_17 ( V_4 ) ;
if ( V_33 )
goto V_145;
F_52 ( V_27 ) ;
V_141 = F_1 ( & V_12 -> V_17 ) ;
V_141 &= ~ F_60 ( 0xff ) ;
V_141 |= V_146 | V_147 | V_23 |
V_148 | V_149 |
V_150 | V_151 |
F_60 ( V_55 ) ;
F_30 ( V_27 , L_9 , V_140 , V_141 ) ;
F_3 ( V_141 , & V_12 -> V_17 ) ;
V_99 = F_1 ( & V_12 -> V_43 ) ;
V_99 &= ~ V_152 ;
V_99 |= V_153 | V_154 |
V_155 ;
if ( V_4 -> V_156 -> V_157 & V_158 ||
V_4 -> V_7 . V_8 & V_9 )
V_99 |= V_159 ;
else
V_99 &= ~ V_159 ;
V_4 -> V_115 = V_99 ;
F_30 ( V_27 , L_10 , V_140 , V_99 ) ;
F_3 ( V_99 , & V_12 -> V_43 ) ;
for ( V_144 = V_55 ; V_144 < F_61 ( V_12 -> V_54 ) ; V_144 ++ ) {
F_3 ( V_160 ,
& V_12 -> V_54 [ V_144 ] . V_56 ) ;
}
F_3 ( V_57 ,
& V_12 -> V_54 [ V_58 ] . V_56 ) ;
F_3 ( V_57 ,
& V_12 -> V_54 [ V_55 ] . V_56 ) ;
F_3 ( 0x0 , & V_12 -> V_161 ) ;
F_3 ( 0x0 , & V_12 -> V_162 ) ;
F_3 ( 0x0 , & V_12 -> V_163 ) ;
if ( V_4 -> V_156 -> V_157 & V_164 )
F_3 ( 0x0 , & V_12 -> V_165 ) ;
if ( V_4 -> V_156 -> V_157 & V_166 ) {
V_142 = F_1 ( & V_12 -> V_167 ) ;
V_142 |= V_168 ;
F_3 ( V_142 , & V_12 -> V_167 ) ;
V_143 = F_1 ( & V_12 -> V_169 ) ;
V_143 &= ~ V_170 ;
F_3 ( V_143 , & V_12 -> V_169 ) ;
V_143 &= ~ ( V_171 | V_172 |
V_173 ) ;
F_3 ( V_143 , & V_12 -> V_169 ) ;
}
V_33 = F_7 ( V_4 ) ;
if ( V_33 )
goto V_145;
V_33 = F_16 ( V_4 ) ;
if ( V_33 )
goto V_174;
V_4 -> V_7 . V_96 = V_91 ;
F_3 ( V_113 , & V_12 -> V_114 ) ;
F_30 ( V_27 , L_11 , V_140 ,
F_1 ( & V_12 -> V_17 ) , F_1 ( & V_12 -> V_43 ) ) ;
return 0 ;
V_174:
F_9 ( V_4 ) ;
V_145:
F_14 ( V_4 ) ;
return V_33 ;
}
static void F_62 ( struct V_26 * V_27 )
{
struct V_3 * V_4 = F_19 ( V_27 ) ;
struct V_11 T_2 * V_12 = V_4 -> V_13 ;
F_15 ( V_4 ) ;
F_14 ( V_4 ) ;
F_3 ( 0 , & V_12 -> V_114 ) ;
F_3 ( V_4 -> V_115 & ~ V_120 ,
& V_12 -> V_43 ) ;
F_9 ( V_4 ) ;
V_4 -> V_7 . V_96 = V_175 ;
return;
}
static int F_63 ( struct V_26 * V_27 )
{
struct V_3 * V_4 = F_19 ( V_27 ) ;
int V_33 ;
V_33 = F_21 ( V_4 -> V_34 ) ;
if ( V_33 )
return V_33 ;
V_33 = F_21 ( V_4 -> V_35 ) ;
if ( V_33 )
goto V_36;
V_33 = F_64 ( V_27 ) ;
if ( V_33 )
goto V_176;
V_33 = F_65 ( V_27 -> V_116 , F_48 , V_177 , V_27 -> V_178 , V_27 ) ;
if ( V_33 )
goto V_179;
V_33 = F_59 ( V_27 ) ;
if ( V_33 )
goto V_180;
F_45 ( V_27 , V_181 ) ;
F_66 ( & V_4 -> V_108 ) ;
F_67 ( V_27 ) ;
return 0 ;
V_180:
F_68 ( V_27 -> V_116 , V_27 ) ;
V_179:
F_69 ( V_27 ) ;
V_176:
F_22 ( V_4 -> V_35 ) ;
V_36:
F_22 ( V_4 -> V_34 ) ;
return V_33 ;
}
static int F_70 ( struct V_26 * V_27 )
{
struct V_3 * V_4 = F_19 ( V_27 ) ;
F_26 ( V_27 ) ;
F_71 ( & V_4 -> V_108 ) ;
F_62 ( V_27 ) ;
F_68 ( V_27 -> V_116 , V_27 ) ;
F_22 ( V_4 -> V_35 ) ;
F_22 ( V_4 -> V_34 ) ;
F_69 ( V_27 ) ;
F_45 ( V_27 , V_182 ) ;
return 0 ;
}
static int F_72 ( struct V_26 * V_27 , enum V_183 V_184 )
{
int V_33 ;
switch ( V_184 ) {
case V_185 :
V_33 = F_59 ( V_27 ) ;
if ( V_33 )
return V_33 ;
F_51 ( V_27 ) ;
break;
default:
return - V_186 ;
}
return 0 ;
}
static int F_73 ( struct V_26 * V_27 )
{
struct V_3 * V_4 = F_19 ( V_27 ) ;
struct V_11 T_2 * V_12 = V_4 -> V_13 ;
T_1 V_16 , V_33 ;
V_33 = F_21 ( V_4 -> V_34 ) ;
if ( V_33 )
return V_33 ;
V_33 = F_21 ( V_4 -> V_35 ) ;
if ( V_33 )
goto V_36;
V_33 = F_14 ( V_4 ) ;
if ( V_33 )
goto V_176;
V_16 = F_1 ( & V_12 -> V_43 ) ;
V_16 |= V_187 ;
F_3 ( V_16 , & V_12 -> V_43 ) ;
V_33 = F_12 ( V_4 ) ;
if ( V_33 )
goto V_145;
V_16 = F_1 ( & V_12 -> V_17 ) ;
V_16 |= V_146 | V_23 |
V_147 | V_148 ;
F_3 ( V_16 , & V_12 -> V_17 ) ;
V_16 = F_1 ( & V_12 -> V_17 ) ;
if ( ! ( V_16 & V_147 ) ) {
F_74 ( V_27 , L_12 ) ;
V_33 = - V_188 ;
goto V_145;
}
V_33 = F_75 ( V_27 ) ;
V_145:
F_14 ( V_4 ) ;
V_176:
F_22 ( V_4 -> V_35 ) ;
V_36:
F_22 ( V_4 -> V_34 ) ;
return V_33 ;
}
static void F_76 ( struct V_26 * V_27 )
{
F_77 ( V_27 ) ;
}
static int F_78 ( struct V_189 * V_190 )
{
const struct V_191 * V_192 ;
const struct V_193 * V_156 ;
struct V_26 * V_27 ;
struct V_3 * V_4 ;
struct V_194 * V_5 ;
struct V_195 * V_196 ;
struct V_197 * V_34 = NULL , * V_35 = NULL ;
void T_2 * V_13 ;
int V_33 , V_116 ;
T_1 V_198 = 0 ;
V_5 = F_79 ( & V_190 -> V_27 , L_13 ) ;
if ( F_80 ( V_5 ) == - V_199 )
return - V_199 ;
else if ( F_81 ( V_5 ) )
V_5 = NULL ;
if ( V_190 -> V_27 . V_200 )
F_82 ( V_190 -> V_27 . V_200 ,
L_14 , & V_198 ) ;
if ( ! V_198 ) {
V_34 = F_83 ( & V_190 -> V_27 , L_15 ) ;
if ( F_81 ( V_34 ) ) {
F_84 ( & V_190 -> V_27 , L_16 ) ;
return F_80 ( V_34 ) ;
}
V_35 = F_83 ( & V_190 -> V_27 , L_17 ) ;
if ( F_81 ( V_35 ) ) {
F_84 ( & V_190 -> V_27 , L_18 ) ;
return F_80 ( V_35 ) ;
}
V_198 = F_85 ( V_35 ) ;
}
V_196 = F_86 ( V_190 , V_201 , 0 ) ;
V_116 = F_87 ( V_190 , 0 ) ;
if ( V_116 <= 0 )
return - V_188 ;
V_13 = F_88 ( & V_190 -> V_27 , V_196 ) ;
if ( F_81 ( V_13 ) )
return F_80 ( V_13 ) ;
V_192 = F_89 ( V_202 , & V_190 -> V_27 ) ;
if ( V_192 ) {
V_156 = V_192 -> V_41 ;
} else if ( F_90 ( V_190 ) -> V_203 ) {
V_156 = (struct V_193 * )
F_90 ( V_190 ) -> V_203 ;
} else {
return - V_188 ;
}
V_27 = F_91 ( sizeof( struct V_3 ) , 1 ) ;
if ( ! V_27 )
return - V_204 ;
V_27 -> V_205 = & V_206 ;
V_27 -> V_116 = V_116 ;
V_27 -> V_207 |= V_208 ;
V_4 = F_19 ( V_27 ) ;
V_4 -> V_7 . clock . V_209 = V_198 ;
V_4 -> V_7 . V_210 = & V_211 ;
V_4 -> V_7 . V_212 = F_72 ;
V_4 -> V_7 . V_213 = F_20 ;
V_4 -> V_7 . V_214 = V_137 |
V_138 | V_139 |
V_9 ;
V_4 -> V_13 = V_13 ;
V_4 -> V_34 = V_34 ;
V_4 -> V_35 = V_35 ;
V_4 -> V_215 = F_92 ( & V_190 -> V_27 ) ;
V_4 -> V_156 = V_156 ;
V_4 -> V_5 = V_5 ;
F_93 ( V_27 , & V_4 -> V_108 , F_46 , V_216 ) ;
F_94 ( V_190 , V_27 ) ;
F_95 ( V_27 , & V_190 -> V_27 ) ;
V_33 = F_73 ( V_27 ) ;
if ( V_33 ) {
F_84 ( & V_190 -> V_27 , L_19 ) ;
goto V_217;
}
F_96 ( V_27 ) ;
F_97 ( & V_190 -> V_27 , L_20 ,
V_4 -> V_13 , V_27 -> V_116 ) ;
return 0 ;
V_217:
F_98 ( V_27 ) ;
return V_33 ;
}
static int F_99 ( struct V_189 * V_190 )
{
struct V_26 * V_27 = F_100 ( V_190 ) ;
struct V_3 * V_4 = F_19 ( V_27 ) ;
F_76 ( V_27 ) ;
F_101 ( & V_4 -> V_108 ) ;
F_98 ( V_27 ) ;
return 0 ;
}
static int T_4 F_102 ( struct V_218 * V_218 )
{
struct V_26 * V_27 = F_103 ( V_218 ) ;
struct V_3 * V_4 = F_19 ( V_27 ) ;
int V_33 ;
V_33 = F_14 ( V_4 ) ;
if ( V_33 )
return V_33 ;
if ( F_104 ( V_27 ) ) {
F_26 ( V_27 ) ;
F_105 ( V_27 ) ;
}
V_4 -> V_7 . V_96 = V_219 ;
return 0 ;
}
static int T_4 F_106 ( struct V_218 * V_218 )
{
struct V_26 * V_27 = F_103 ( V_218 ) ;
struct V_3 * V_4 = F_19 ( V_27 ) ;
V_4 -> V_7 . V_96 = V_91 ;
if ( F_104 ( V_27 ) ) {
F_107 ( V_27 ) ;
F_67 ( V_27 ) ;
}
return F_12 ( V_4 ) ;
}
