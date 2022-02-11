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
static int F_11 ( struct V_3 * V_4 )
{
struct V_6 T_2 * V_7 = V_4 -> V_7 ;
unsigned int V_8 = V_9 / 10 ;
T_1 V_10 ;
V_10 = F_1 ( & V_7 -> V_11 ) ;
V_10 &= ~ V_12 ;
F_3 ( V_10 , & V_7 -> V_11 ) ;
while ( V_8 -- && ( F_1 ( & V_7 -> V_11 ) & V_13 ) )
F_12 ( 10 ) ;
if ( F_1 ( & V_7 -> V_11 ) & V_13 )
return - V_14 ;
return 0 ;
}
static int F_13 ( struct V_3 * V_4 )
{
struct V_6 T_2 * V_7 = V_4 -> V_7 ;
unsigned int V_8 = V_9 / 10 ;
T_1 V_10 ;
V_10 = F_1 ( & V_7 -> V_11 ) ;
V_10 |= V_12 ;
F_3 ( V_10 , & V_7 -> V_11 ) ;
while ( V_8 -- && ! ( F_1 ( & V_7 -> V_11 ) & V_13 ) )
F_12 ( 10 ) ;
if ( ! ( F_1 ( & V_7 -> V_11 ) & V_13 ) )
return - V_14 ;
return 0 ;
}
static int F_14 ( struct V_3 * V_4 )
{
struct V_6 T_2 * V_7 = V_4 -> V_7 ;
unsigned int V_8 = 1000 * 1000 * 10 / V_4 -> V_15 . V_16 . V_17 ;
T_1 V_10 ;
V_10 = F_1 ( & V_7 -> V_11 ) ;
V_10 |= V_18 ;
F_3 ( V_10 , & V_7 -> V_11 ) ;
while ( V_8 -- && ! ( F_1 ( & V_7 -> V_11 ) & V_19 ) )
F_12 ( 100 ) ;
if ( ! ( F_1 ( & V_7 -> V_11 ) & V_19 ) )
return - V_14 ;
return 0 ;
}
static int F_15 ( struct V_3 * V_4 )
{
struct V_6 T_2 * V_7 = V_4 -> V_7 ;
unsigned int V_8 = V_9 / 10 ;
T_1 V_10 ;
V_10 = F_1 ( & V_7 -> V_11 ) ;
V_10 &= ~ V_18 ;
F_3 ( V_10 , & V_7 -> V_11 ) ;
while ( V_8 -- && ( F_1 ( & V_7 -> V_11 ) & V_19 ) )
F_12 ( 10 ) ;
if ( F_1 ( & V_7 -> V_11 ) & V_19 )
return - V_14 ;
return 0 ;
}
static int F_16 ( struct V_3 * V_4 )
{
struct V_6 T_2 * V_7 = V_4 -> V_7 ;
unsigned int V_8 = V_9 / 10 ;
F_3 ( V_20 , & V_7 -> V_11 ) ;
while ( V_8 -- && ( F_1 ( & V_7 -> V_11 ) & V_20 ) )
F_12 ( 10 ) ;
if ( F_1 ( & V_7 -> V_11 ) & V_20 )
return - V_14 ;
return 0 ;
}
static int F_17 ( const struct V_21 * V_22 ,
struct V_23 * V_24 )
{
const struct V_3 * V_4 = F_18 ( V_22 ) ;
struct V_6 T_2 * V_7 = V_4 -> V_7 ;
T_1 V_10 = F_1 ( & V_7 -> V_25 ) ;
V_24 -> V_26 = ( V_10 >> 0 ) & 0xff ;
V_24 -> V_27 = ( V_10 >> 8 ) & 0xff ;
return 0 ;
}
static int F_19 ( const struct V_21 * V_22 ,
struct V_23 * V_24 )
{
const struct V_3 * V_4 = F_18 ( V_22 ) ;
int V_28 ;
V_28 = F_20 ( V_4 -> V_29 ) ;
if ( V_28 )
return V_28 ;
V_28 = F_20 ( V_4 -> V_30 ) ;
if ( V_28 )
goto V_31;
V_28 = F_17 ( V_22 , V_24 ) ;
F_21 ( V_4 -> V_30 ) ;
V_31:
F_21 ( V_4 -> V_29 ) ;
return V_28 ;
}
static int F_22 ( struct V_32 * V_33 , struct V_21 * V_22 )
{
const struct V_3 * V_4 = F_18 ( V_22 ) ;
struct V_34 * V_35 = (struct V_34 * ) V_33 -> V_36 ;
T_1 V_37 ;
T_1 V_36 ;
T_1 V_38 = V_39 | ( V_35 -> V_40 << 16 ) ;
if ( F_23 ( V_22 , V_33 ) )
return V_41 ;
F_24 ( V_22 ) ;
if ( V_35 -> V_37 & V_42 ) {
V_37 = V_35 -> V_37 & V_43 ;
V_38 |= V_44 | V_45 ;
} else {
V_37 = ( V_35 -> V_37 & V_46 ) << 18 ;
}
if ( V_35 -> V_37 & V_47 )
V_38 |= V_48 ;
if ( V_35 -> V_40 > 0 ) {
V_36 = F_25 ( ( V_49 * ) & V_35 -> V_36 [ 0 ] ) ;
F_3 ( V_36 , & V_4 -> V_50 -> V_36 [ 0 ] ) ;
}
if ( V_35 -> V_40 > 3 ) {
V_36 = F_25 ( ( V_49 * ) & V_35 -> V_36 [ 4 ] ) ;
F_3 ( V_36 , & V_4 -> V_50 -> V_36 [ 1 ] ) ;
}
F_26 ( V_33 , V_22 , 0 ) ;
F_3 ( V_37 , & V_4 -> V_50 -> V_37 ) ;
F_3 ( V_38 , & V_4 -> V_50 -> V_51 ) ;
F_3 ( V_52 ,
& V_4 -> V_53 -> V_51 ) ;
F_3 ( V_52 ,
& V_4 -> V_53 -> V_51 ) ;
return V_41 ;
}
static void F_27 ( struct V_21 * V_22 , T_1 V_54 )
{
struct V_3 * V_4 = F_18 ( V_22 ) ;
struct V_32 * V_33 ;
struct V_34 * V_35 ;
bool V_55 = false , V_56 = false ;
V_33 = F_28 ( V_22 , & V_35 ) ;
if ( F_29 ( ! V_33 ) )
return;
V_35 -> V_37 |= V_57 | V_58 ;
if ( V_54 & V_59 ) {
F_30 ( V_22 , L_1 ) ;
V_35 -> V_36 [ 2 ] |= V_60 ;
V_56 = true ;
}
if ( V_54 & V_61 ) {
F_30 ( V_22 , L_2 ) ;
V_35 -> V_36 [ 2 ] |= V_62 ;
V_56 = true ;
}
if ( V_54 & V_63 ) {
F_30 ( V_22 , L_3 ) ;
V_35 -> V_37 |= V_64 ;
V_35 -> V_36 [ 3 ] = V_65 ;
V_56 = true ;
}
if ( V_54 & V_66 ) {
F_30 ( V_22 , L_4 ) ;
V_35 -> V_36 [ 2 ] |= V_67 ;
V_35 -> V_36 [ 3 ] = V_68 ;
V_55 = true ;
}
if ( V_54 & V_69 ) {
F_30 ( V_22 , L_5 ) ;
V_35 -> V_36 [ 2 ] |= V_70 ;
V_55 = true ;
}
if ( V_54 & V_71 ) {
F_30 ( V_22 , L_6 ) ;
V_35 -> V_36 [ 2 ] |= V_72 ;
V_55 = true ;
}
V_4 -> V_15 . V_73 . V_74 ++ ;
if ( V_55 )
V_22 -> V_75 . V_55 ++ ;
if ( V_56 )
V_22 -> V_75 . V_56 ++ ;
F_31 ( & V_4 -> V_76 , V_33 ) ;
}
static void F_32 ( struct V_21 * V_22 , T_1 V_54 )
{
struct V_3 * V_4 = F_18 ( V_22 ) ;
struct V_32 * V_33 ;
struct V_34 * V_35 ;
enum V_77 V_78 , V_79 , V_80 ;
int V_81 ;
struct V_23 V_24 ;
V_81 = V_54 & V_82 ;
if ( F_33 ( V_81 == V_83 ) ) {
V_80 = F_29 ( V_54 & V_84 ) ?
V_85 : V_86 ;
V_79 = F_29 ( V_54 & V_87 ) ?
V_85 : V_86 ;
V_78 = F_34 ( V_80 , V_79 ) ;
} else {
F_17 ( V_22 , & V_24 ) ;
V_78 = V_81 == V_88 ?
V_89 : V_90 ;
V_79 = V_24 . V_27 >= V_24 . V_26 ? V_78 : 0 ;
V_80 = V_24 . V_27 <= V_24 . V_26 ? V_78 : 0 ;
}
if ( F_33 ( V_78 == V_4 -> V_15 . V_91 ) )
return;
V_33 = F_28 ( V_22 , & V_35 ) ;
if ( F_29 ( ! V_33 ) )
return;
F_35 ( V_22 , V_35 , V_80 , V_79 ) ;
if ( F_29 ( V_78 == V_90 ) )
F_36 ( V_22 ) ;
F_31 ( & V_4 -> V_76 , V_33 ) ;
}
static inline struct V_3 * F_37 ( struct V_92 * V_76 )
{
return F_38 ( V_76 , struct V_3 , V_76 ) ;
}
static unsigned int F_39 ( struct V_92 * V_76 ,
struct V_34 * V_35 ,
T_1 * V_93 , unsigned int V_94 )
{
struct V_3 * V_4 = F_37 ( V_76 ) ;
struct V_6 T_2 * V_7 = V_4 -> V_7 ;
struct V_95 T_2 * V_96 = & V_7 -> V_96 [ V_94 ] ;
T_1 V_97 , V_98 , V_99 ;
if ( V_4 -> V_100 -> V_101 & V_102 ) {
T_1 V_103 ;
do {
V_97 = F_1 ( & V_96 -> V_51 ) ;
} while ( V_97 & V_104 );
V_103 = V_97 & V_105 ;
if ( ( V_103 != V_106 ) &&
( V_103 != V_107 ) )
return 0 ;
if ( V_103 == V_107 ) {
V_76 -> V_22 -> V_75 . V_108 ++ ;
V_76 -> V_22 -> V_75 . V_55 ++ ;
}
} else {
V_99 = F_1 ( & V_7 -> V_109 ) ;
if ( ! ( V_99 & V_110 ) )
return 0 ;
V_97 = F_1 ( & V_96 -> V_51 ) ;
}
* V_93 = V_97 << 16 ;
V_98 = F_1 ( & V_96 -> V_37 ) ;
if ( V_97 & V_44 )
V_35 -> V_37 = ( ( V_98 >> 0 ) & V_43 ) | V_42 ;
else
V_35 -> V_37 = ( V_98 >> 18 ) & V_46 ;
if ( V_97 & V_48 )
V_35 -> V_37 |= V_47 ;
V_35 -> V_40 = F_40 ( ( V_97 >> 16 ) & 0xf ) ;
* ( V_49 * ) ( V_35 -> V_36 + 0 ) = F_41 ( F_1 ( & V_96 -> V_36 [ 0 ] ) ) ;
* ( V_49 * ) ( V_35 -> V_36 + 4 ) = F_41 ( F_1 ( & V_96 -> V_36 [ 1 ] ) ) ;
if ( V_4 -> V_100 -> V_101 & V_102 ) {
if ( V_94 < 32 )
F_3 ( F_42 ( V_94 ) , & V_7 -> V_109 ) ;
else
F_3 ( F_42 ( V_94 - 32 ) , & V_7 -> V_111 ) ;
} else {
F_3 ( V_110 , & V_7 -> V_109 ) ;
F_1 ( & V_7 -> V_112 ) ;
}
return 1 ;
}
static inline T_3 F_43 ( struct V_3 * V_4 )
{
struct V_6 T_2 * V_7 = V_4 -> V_7 ;
T_1 V_109 , V_111 ;
V_111 = F_1 ( & V_7 -> V_111 ) & V_4 -> V_113 ;
V_109 = F_1 ( & V_7 -> V_109 ) & V_4 -> V_114 &
~ F_44 ( V_4 -> V_115 ) ;
return ( T_3 ) V_111 << 32 | V_109 ;
}
static T_4 F_45 ( int V_116 , void * V_117 )
{
struct V_21 * V_22 = V_117 ;
struct V_118 * V_75 = & V_22 -> V_75 ;
struct V_3 * V_4 = F_18 ( V_22 ) ;
struct V_6 T_2 * V_7 = V_4 -> V_7 ;
T_4 V_119 = V_120 ;
T_1 V_99 , V_54 ;
V_99 = F_1 ( & V_7 -> V_109 ) ;
if ( V_4 -> V_100 -> V_101 & V_102 ) {
T_3 V_121 ;
int V_122 ;
while ( ( V_121 = F_43 ( V_4 ) ) ) {
V_119 = V_123 ;
V_122 = F_46 ( & V_4 -> V_76 ,
V_121 ) ;
if ( ! V_122 )
break;
}
} else {
if ( V_99 & V_110 ) {
V_119 = V_123 ;
F_47 ( & V_4 -> V_76 ) ;
}
if ( V_99 & V_124 ) {
V_119 = V_123 ;
F_3 ( V_124 , & V_7 -> V_109 ) ;
V_22 -> V_75 . V_108 ++ ;
V_22 -> V_75 . V_55 ++ ;
}
}
if ( V_99 & F_44 ( V_4 -> V_115 ) ) {
V_119 = V_123 ;
V_75 -> V_125 += F_48 ( V_22 , 0 ) ;
V_75 -> V_126 ++ ;
F_49 ( V_22 , V_127 ) ;
F_3 ( V_52 ,
& V_4 -> V_50 -> V_51 ) ;
F_3 ( F_44 ( V_4 -> V_115 ) , & V_7 -> V_109 ) ;
F_50 ( V_22 ) ;
}
V_54 = F_1 ( & V_7 -> V_128 ) ;
if ( V_54 & V_129 ) {
V_119 = V_123 ;
F_3 ( V_54 & V_129 , & V_7 -> V_128 ) ;
}
if ( V_54 & V_130 )
F_32 ( V_22 , V_54 ) ;
if ( ( V_54 & V_131 ) &&
( V_4 -> V_15 . V_132 & V_133 ) )
F_27 ( V_22 , V_54 ) ;
return V_119 ;
}
static void F_51 ( struct V_21 * V_22 )
{
const struct V_3 * V_4 = F_18 ( V_22 ) ;
const struct V_134 * V_135 = & V_4 -> V_15 . V_16 ;
struct V_6 T_2 * V_7 = V_4 -> V_7 ;
T_1 V_10 ;
V_10 = F_1 ( & V_7 -> V_38 ) ;
V_10 &= ~ ( F_52 ( 0xff ) |
F_53 ( 0x3 ) |
F_54 ( 0x7 ) |
F_55 ( 0x7 ) |
F_56 ( 0x7 ) |
V_136 |
V_137 |
V_138 ) ;
V_10 |= F_52 ( V_135 -> V_139 - 1 ) |
F_54 ( V_135 -> V_140 - 1 ) |
F_55 ( V_135 -> V_141 - 1 ) |
F_53 ( V_135 -> V_142 - 1 ) |
F_56 ( V_135 -> V_143 - 1 ) ;
if ( V_4 -> V_15 . V_132 & V_144 )
V_10 |= V_136 ;
if ( V_4 -> V_15 . V_132 & V_145 )
V_10 |= V_138 ;
if ( V_4 -> V_15 . V_132 & V_146 )
V_10 |= V_137 ;
F_30 ( V_22 , L_7 , V_10 ) ;
F_3 ( V_10 , & V_7 -> V_38 ) ;
F_30 ( V_22 , L_8 , V_147 ,
F_1 ( & V_7 -> V_11 ) , F_1 ( & V_7 -> V_38 ) ) ;
}
static int F_57 ( struct V_21 * V_22 )
{
struct V_3 * V_4 = F_18 ( V_22 ) ;
struct V_6 T_2 * V_7 = V_4 -> V_7 ;
T_1 V_148 , V_97 , V_149 , V_150 ;
int V_28 , V_151 ;
V_28 = F_11 ( V_4 ) ;
if ( V_28 )
return V_28 ;
V_28 = F_16 ( V_4 ) ;
if ( V_28 )
goto V_152;
F_51 ( V_22 ) ;
V_148 = F_1 ( & V_7 -> V_11 ) ;
V_148 &= ~ F_58 ( 0xff ) ;
V_148 |= V_153 | V_18 | V_154 |
V_155 | V_156 | V_157 |
V_158 ;
if ( V_4 -> V_100 -> V_101 & V_102 ) {
V_148 &= ~ V_159 ;
V_148 |= F_58 ( V_4 -> V_76 . V_160 ) ;
} else {
V_148 |= V_159 |
F_58 ( V_4 -> V_115 ) ;
}
F_30 ( V_22 , L_9 , V_147 , V_148 ) ;
F_3 ( V_148 , & V_7 -> V_11 ) ;
V_97 = F_1 ( & V_7 -> V_38 ) ;
V_97 &= ~ V_161 ;
V_97 |= V_162 | V_163 |
V_164 ;
if ( V_4 -> V_100 -> V_101 & V_165 ||
V_4 -> V_15 . V_132 & V_133 )
V_97 |= V_166 ;
else
V_97 &= ~ V_166 ;
V_4 -> V_167 = V_97 ;
V_97 &= ~ V_168 ;
F_30 ( V_22 , L_10 , V_147 , V_97 ) ;
F_3 ( V_97 , & V_7 -> V_38 ) ;
if ( ( V_4 -> V_100 -> V_101 & V_169 ) ) {
V_149 = F_1 ( & V_7 -> V_170 ) ;
V_149 |= V_171 | V_172 ;
F_3 ( V_149 , & V_7 -> V_170 ) ;
}
for ( V_151 = V_4 -> V_115 ; V_151 < F_59 ( V_7 -> V_96 ) ; V_151 ++ ) {
F_3 ( V_173 ,
& V_7 -> V_96 [ V_151 ] . V_51 ) ;
}
if ( V_4 -> V_100 -> V_101 & V_102 ) {
for ( V_151 = V_4 -> V_76 . V_174 ; V_151 <= V_4 -> V_76 . V_160 ; V_151 ++ )
F_3 ( V_175 ,
& V_7 -> V_96 [ V_151 ] . V_51 ) ;
}
F_3 ( V_52 ,
& V_4 -> V_53 -> V_51 ) ;
F_3 ( V_52 ,
& V_4 -> V_50 -> V_51 ) ;
F_3 ( 0x0 , & V_7 -> V_176 ) ;
F_3 ( 0x0 , & V_7 -> V_177 ) ;
F_3 ( 0x0 , & V_7 -> V_178 ) ;
if ( V_4 -> V_100 -> V_101 & V_179 )
F_3 ( 0x0 , & V_7 -> V_180 ) ;
for ( V_151 = 0 ; V_151 < F_59 ( V_7 -> V_96 ) ; V_151 ++ )
F_3 ( 0 , & V_7 -> V_181 [ V_151 ] ) ;
if ( V_4 -> V_100 -> V_101 & V_182 ) {
V_149 = F_1 ( & V_7 -> V_170 ) ;
V_149 |= V_183 ;
F_3 ( V_149 , & V_7 -> V_170 ) ;
V_150 = F_1 ( & V_7 -> V_184 ) ;
V_150 &= ~ V_185 ;
F_3 ( V_150 , & V_7 -> V_184 ) ;
V_150 &= ~ ( V_186 | V_187 |
V_188 ) ;
F_3 ( V_150 , & V_7 -> V_184 ) ;
}
V_28 = F_7 ( V_4 ) ;
if ( V_28 )
goto V_152;
V_28 = F_15 ( V_4 ) ;
if ( V_28 )
goto V_189;
V_4 -> V_15 . V_91 = V_86 ;
F_60 ( V_22 -> V_116 ) ;
F_3 ( V_4 -> V_167 , & V_7 -> V_38 ) ;
F_3 ( V_4 -> V_114 , & V_7 -> V_190 ) ;
F_3 ( V_4 -> V_113 , & V_7 -> V_191 ) ;
F_61 ( V_22 -> V_116 ) ;
F_30 ( V_22 , L_11 , V_147 ,
F_1 ( & V_7 -> V_11 ) , F_1 ( & V_7 -> V_38 ) ) ;
return 0 ;
V_189:
F_9 ( V_4 ) ;
V_152:
F_13 ( V_4 ) ;
return V_28 ;
}
static void F_62 ( struct V_21 * V_22 )
{
struct V_3 * V_4 = F_18 ( V_22 ) ;
struct V_6 T_2 * V_7 = V_4 -> V_7 ;
F_14 ( V_4 ) ;
F_13 ( V_4 ) ;
F_3 ( 0 , & V_7 -> V_191 ) ;
F_3 ( 0 , & V_7 -> V_190 ) ;
F_3 ( V_4 -> V_167 & ~ V_168 ,
& V_7 -> V_38 ) ;
F_9 ( V_4 ) ;
V_4 -> V_15 . V_91 = V_192 ;
}
static int F_63 ( struct V_21 * V_22 )
{
struct V_3 * V_4 = F_18 ( V_22 ) ;
int V_28 ;
V_28 = F_20 ( V_4 -> V_29 ) ;
if ( V_28 )
return V_28 ;
V_28 = F_20 ( V_4 -> V_30 ) ;
if ( V_28 )
goto V_31;
V_28 = F_64 ( V_22 ) ;
if ( V_28 )
goto V_193;
V_28 = F_65 ( V_22 -> V_116 , F_45 , V_194 , V_22 -> V_195 , V_22 ) ;
if ( V_28 )
goto V_196;
V_28 = F_57 ( V_22 ) ;
if ( V_28 )
goto V_197;
F_49 ( V_22 , V_198 ) ;
F_66 ( & V_4 -> V_76 ) ;
F_67 ( V_22 ) ;
return 0 ;
V_197:
F_68 ( V_22 -> V_116 , V_22 ) ;
V_196:
F_69 ( V_22 ) ;
V_193:
F_21 ( V_4 -> V_30 ) ;
V_31:
F_21 ( V_4 -> V_29 ) ;
return V_28 ;
}
static int F_70 ( struct V_21 * V_22 )
{
struct V_3 * V_4 = F_18 ( V_22 ) ;
F_24 ( V_22 ) ;
F_71 ( & V_4 -> V_76 ) ;
F_62 ( V_22 ) ;
F_68 ( V_22 -> V_116 , V_22 ) ;
F_21 ( V_4 -> V_30 ) ;
F_21 ( V_4 -> V_29 ) ;
F_69 ( V_22 ) ;
F_49 ( V_22 , V_199 ) ;
return 0 ;
}
static int F_72 ( struct V_21 * V_22 , enum V_200 V_201 )
{
int V_28 ;
switch ( V_201 ) {
case V_202 :
V_28 = F_57 ( V_22 ) ;
if ( V_28 )
return V_28 ;
F_50 ( V_22 ) ;
break;
default:
return - V_203 ;
}
return 0 ;
}
static int F_73 ( struct V_21 * V_22 )
{
struct V_3 * V_4 = F_18 ( V_22 ) ;
struct V_6 T_2 * V_7 = V_4 -> V_7 ;
T_1 V_10 , V_28 ;
V_28 = F_20 ( V_4 -> V_29 ) ;
if ( V_28 )
return V_28 ;
V_28 = F_20 ( V_4 -> V_30 ) ;
if ( V_28 )
goto V_31;
V_28 = F_13 ( V_4 ) ;
if ( V_28 )
goto V_193;
V_10 = F_1 ( & V_7 -> V_38 ) ;
V_10 |= V_204 ;
F_3 ( V_10 , & V_7 -> V_38 ) ;
V_28 = F_11 ( V_4 ) ;
if ( V_28 )
goto V_152;
V_10 = F_1 ( & V_7 -> V_11 ) ;
V_10 |= V_153 | V_18 |
V_159 | V_154 ;
F_3 ( V_10 , & V_7 -> V_11 ) ;
V_10 = F_1 ( & V_7 -> V_11 ) ;
if ( ! ( V_10 & V_159 ) ) {
F_74 ( V_22 , L_12 ) ;
V_28 = - V_205 ;
goto V_152;
}
V_28 = F_75 ( V_22 ) ;
V_152:
F_13 ( V_4 ) ;
V_193:
F_21 ( V_4 -> V_30 ) ;
V_31:
F_21 ( V_4 -> V_29 ) ;
return V_28 ;
}
static void F_76 ( struct V_21 * V_22 )
{
F_77 ( V_22 ) ;
}
static int F_78 ( struct V_206 * V_207 )
{
const struct V_208 * V_209 ;
const struct V_210 * V_100 ;
struct V_21 * V_22 ;
struct V_3 * V_4 ;
struct V_211 * V_5 ;
struct V_212 * V_213 ;
struct V_214 * V_29 = NULL , * V_30 = NULL ;
struct V_6 T_2 * V_7 ;
int V_28 , V_116 ;
T_1 V_215 = 0 ;
V_5 = F_79 ( & V_207 -> V_22 , L_13 ) ;
if ( F_80 ( V_5 ) == - V_216 )
return - V_216 ;
else if ( F_81 ( V_5 ) )
V_5 = NULL ;
if ( V_207 -> V_22 . V_217 )
F_82 ( V_207 -> V_22 . V_217 ,
L_14 , & V_215 ) ;
if ( ! V_215 ) {
V_29 = F_83 ( & V_207 -> V_22 , L_15 ) ;
if ( F_81 ( V_29 ) ) {
F_84 ( & V_207 -> V_22 , L_16 ) ;
return F_80 ( V_29 ) ;
}
V_30 = F_83 ( & V_207 -> V_22 , L_17 ) ;
if ( F_81 ( V_30 ) ) {
F_84 ( & V_207 -> V_22 , L_18 ) ;
return F_80 ( V_30 ) ;
}
V_215 = F_85 ( V_30 ) ;
}
V_213 = F_86 ( V_207 , V_218 , 0 ) ;
V_116 = F_87 ( V_207 , 0 ) ;
if ( V_116 <= 0 )
return - V_205 ;
V_7 = F_88 ( & V_207 -> V_22 , V_213 ) ;
if ( F_81 ( V_7 ) )
return F_80 ( V_7 ) ;
V_209 = F_89 ( V_219 , & V_207 -> V_22 ) ;
if ( V_209 ) {
V_100 = V_209 -> V_36 ;
} else if ( F_90 ( V_207 ) -> V_220 ) {
V_100 = (struct V_210 * )
F_90 ( V_207 ) -> V_220 ;
} else {
return - V_205 ;
}
V_22 = F_91 ( sizeof( struct V_3 ) , 1 ) ;
if ( ! V_22 )
return - V_221 ;
F_92 ( V_207 , V_22 ) ;
F_93 ( V_22 , & V_207 -> V_22 ) ;
V_22 -> V_222 = & V_223 ;
V_22 -> V_116 = V_116 ;
V_22 -> V_224 |= V_225 ;
V_4 = F_18 ( V_22 ) ;
V_4 -> V_15 . clock . V_226 = V_215 ;
V_4 -> V_15 . V_227 = & V_228 ;
V_4 -> V_15 . V_229 = F_72 ;
V_4 -> V_15 . V_230 = F_19 ;
V_4 -> V_15 . V_231 = V_144 |
V_145 | V_146 |
V_133 ;
V_4 -> V_7 = V_7 ;
V_4 -> V_29 = V_29 ;
V_4 -> V_30 = V_30 ;
V_4 -> V_100 = V_100 ;
V_4 -> V_5 = V_5 ;
if ( V_4 -> V_100 -> V_101 & V_102 ) {
V_4 -> V_115 = V_232 ;
V_4 -> V_53 = & V_7 -> V_96 [ V_233 ] ;
} else {
V_4 -> V_115 = V_234 ;
V_4 -> V_53 = & V_7 -> V_96 [ V_235 ] ;
}
V_4 -> V_50 = & V_7 -> V_96 [ V_4 -> V_115 ] ;
V_4 -> V_114 = F_44 ( V_4 -> V_115 ) ;
V_4 -> V_113 = 0 ;
V_4 -> V_76 . V_236 = F_39 ;
if ( V_4 -> V_100 -> V_101 & V_102 ) {
T_3 V_237 ;
V_4 -> V_76 . V_174 = V_238 ;
V_4 -> V_76 . V_160 = V_239 ;
V_237 = F_94 ( V_4 -> V_76 . V_160 , V_4 -> V_76 . V_174 ) ;
V_4 -> V_114 |= V_237 ;
V_4 -> V_113 |= V_237 >> 32 ;
V_28 = F_95 ( V_22 , & V_4 -> V_76 ) ;
} else {
V_4 -> V_114 |= V_124 |
V_110 ;
V_28 = F_96 ( V_22 , & V_4 -> V_76 , V_240 ) ;
}
if ( V_28 )
goto V_241;
V_28 = F_73 ( V_22 ) ;
if ( V_28 ) {
F_84 ( & V_207 -> V_22 , L_19 ) ;
goto V_242;
}
F_97 ( V_22 ) ;
F_98 ( & V_207 -> V_22 , L_20 ,
V_4 -> V_7 , V_22 -> V_116 ) ;
return 0 ;
V_241:
V_242:
F_99 ( V_22 ) ;
return V_28 ;
}
static int F_100 ( struct V_206 * V_207 )
{
struct V_21 * V_22 = F_101 ( V_207 ) ;
struct V_3 * V_4 = F_18 ( V_22 ) ;
F_76 ( V_22 ) ;
F_102 ( & V_4 -> V_76 ) ;
F_99 ( V_22 ) ;
return 0 ;
}
static int T_5 F_103 ( struct V_243 * V_243 )
{
struct V_21 * V_22 = F_104 ( V_243 ) ;
struct V_3 * V_4 = F_18 ( V_22 ) ;
int V_28 ;
if ( F_105 ( V_22 ) ) {
V_28 = F_13 ( V_4 ) ;
if ( V_28 )
return V_28 ;
F_24 ( V_22 ) ;
F_106 ( V_22 ) ;
}
V_4 -> V_15 . V_91 = V_244 ;
return 0 ;
}
static int T_5 F_107 ( struct V_243 * V_243 )
{
struct V_21 * V_22 = F_104 ( V_243 ) ;
struct V_3 * V_4 = F_18 ( V_22 ) ;
int V_28 ;
V_4 -> V_15 . V_91 = V_86 ;
if ( F_105 ( V_22 ) ) {
F_108 ( V_22 ) ;
F_67 ( V_22 ) ;
V_28 = F_11 ( V_4 ) ;
if ( V_28 )
return V_28 ;
}
return 0 ;
}
