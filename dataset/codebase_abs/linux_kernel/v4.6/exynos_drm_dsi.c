static inline struct V_1 * F_1 ( struct V_2 * V_3 )
{
return F_2 ( V_3 , struct V_1 , V_4 ) ;
}
static inline void F_3 ( struct V_1 * V_5 , enum V_6 V_7 ,
T_1 V_8 )
{
F_4 ( V_8 , V_5 -> V_9 + V_5 -> V_10 -> V_11 [ V_7 ] ) ;
}
static inline T_1 F_5 ( struct V_1 * V_5 , enum V_6 V_7 )
{
return F_6 ( V_5 -> V_9 + V_5 -> V_10 -> V_11 [ V_7 ] ) ;
}
static inline struct V_12 * F_7 (
struct V_13 * V_14 )
{
const struct V_15 * V_16 =
F_8 ( V_17 , & V_14 -> V_18 ) ;
return (struct V_12 * ) V_16 -> V_19 ;
}
static void F_9 ( struct V_1 * V_5 )
{
if ( F_10 ( & V_5 -> V_20 , F_11 ( 300 ) ) )
return;
F_12 ( V_5 -> V_18 , L_1 ) ;
}
static void F_13 ( struct V_1 * V_5 )
{
T_1 V_21 = V_5 -> V_10 -> V_22 [ V_23 ] ;
F_14 ( & V_5 -> V_20 ) ;
F_3 ( V_5 , V_24 , V_21 ) ;
}
static unsigned long F_15 ( struct V_1 * V_5 ,
unsigned long V_25 , unsigned long V_26 , T_2 * V_27 , T_3 * V_28 , T_2 * V_29 )
{
struct V_12 * V_10 = V_5 -> V_10 ;
unsigned long V_30 = 0 ;
T_1 V_31 = 0xffffffff ;
T_2 V_32 , V_33 ;
T_2 V_34 , V_35 ( V_36 ) ;
T_3 V_37 , V_35 ( V_38 ) ;
T_2 V_39 , V_35 ( V_40 ) ;
V_32 = F_16 ( V_25 , ( 12 * V_41 ) ) ;
V_33 = V_25 / ( 6 * V_41 ) ;
for ( V_34 = V_32 ; V_34 <= V_33 ; ++ V_34 ) {
for ( V_39 = 0 ; V_39 <= 5 ; ++ V_39 ) {
T_4 V_42 ;
T_1 V_43 ;
V_42 = ( T_4 ) V_26 * ( V_34 << V_39 ) ;
F_17 ( V_42 , V_25 ) ;
V_37 = V_42 ;
if ( V_37 < 41 || V_37 > 125 )
continue;
V_42 = ( T_4 ) V_37 * V_25 ;
F_17 ( V_42 , V_34 ) ;
if ( V_42 < 500 * V_41 ||
V_42 > V_10 -> V_44 * V_41 )
continue;
V_42 = ( T_4 ) V_37 * V_25 ;
F_17 ( V_42 , V_34 << V_39 ) ;
V_43 = abs ( V_26 - V_42 ) ;
if ( V_43 < V_31 ) {
V_36 = V_34 ;
V_38 = V_37 ;
V_40 = V_39 ;
V_31 = V_43 ;
V_30 = V_42 ;
}
}
}
if ( V_30 ) {
* V_27 = V_36 ;
* V_28 = V_38 ;
* V_29 = V_40 ;
}
return V_30 ;
}
static unsigned long F_18 ( struct V_1 * V_5 ,
unsigned long V_45 )
{
struct V_12 * V_10 = V_5 -> V_10 ;
unsigned long V_25 , V_26 ;
int V_46 ;
T_2 V_27 , V_29 ;
T_3 V_28 ;
T_1 V_47 ;
V_25 = V_5 -> V_48 ;
V_26 = F_15 ( V_5 , V_25 , V_45 , & V_27 , & V_28 , & V_29 ) ;
if ( ! V_26 ) {
F_12 ( V_5 -> V_18 ,
L_2 ) ;
return 0 ;
}
F_19 ( V_5 -> V_18 , L_3 , V_26 , V_27 , V_28 , V_29 ) ;
F_4 ( V_10 -> V_22 [ V_49 ] ,
V_5 -> V_9 + V_10 -> V_50 ) ;
V_47 = V_51 | F_20 ( V_27 ) | F_21 ( V_28 ) | F_22 ( V_29 ) ;
if ( V_10 -> V_52 ) {
static const unsigned long V_53 [] = {
100 * V_41 , 120 * V_41 , 160 * V_41 , 200 * V_41 ,
270 * V_41 , 320 * V_41 , 390 * V_41 , 450 * V_41 ,
510 * V_41 , 560 * V_41 , 640 * V_41 , 690 * V_41 ,
770 * V_41 , 870 * V_41 , 950 * V_41 ,
} ;
int V_54 ;
for ( V_54 = 0 ; V_54 < F_23 ( V_53 ) ; ++ V_54 )
if ( V_26 < V_53 [ V_54 ] )
break;
F_19 ( V_5 -> V_18 , L_4 , V_54 ) ;
V_47 |= F_24 ( V_54 ) ;
}
F_3 ( V_5 , V_55 , V_47 ) ;
V_46 = 1000 ;
do {
if ( V_46 -- == 0 ) {
F_12 ( V_5 -> V_18 , L_5 ) ;
return 0 ;
}
V_47 = F_5 ( V_5 , V_56 ) ;
} while ( ( V_47 & V_57 ) == 0 );
return V_26 ;
}
static int F_25 ( struct V_1 * V_5 )
{
unsigned long V_58 , V_59 , V_60 ;
unsigned long V_61 ;
T_1 V_47 ;
V_58 = F_18 ( V_5 , V_5 -> V_62 ) ;
if ( ! V_58 ) {
F_12 ( V_5 -> V_18 , L_6 ) ;
return - V_63 ;
}
V_59 = V_58 / 8 ;
V_61 = F_16 ( V_59 , V_5 -> V_64 ) ;
V_60 = V_59 / V_61 ;
if ( V_60 > 20 * V_41 ) {
++ V_61 ;
V_60 = V_59 / V_61 ;
}
F_19 ( V_5 -> V_18 , L_7 ,
V_58 , V_59 , V_60 ) ;
V_47 = F_5 ( V_5 , V_65 ) ;
V_47 &= ~ ( V_66 | V_67
| V_68 | V_69
| V_70 ) ;
V_47 |= V_71 | V_72
| F_26 ( V_61 )
| V_67
| F_27 ( F_28 ( V_5 -> V_73 ) - 1 )
| F_29 ( 0 )
| V_74 ;
F_3 ( V_5 , V_65 , V_47 ) ;
return 0 ;
}
static void F_30 ( struct V_1 * V_5 )
{
struct V_12 * V_10 = V_5 -> V_10 ;
const unsigned int * V_22 = V_10 -> V_22 ;
T_1 V_47 ;
if ( V_10 -> V_52 )
return;
V_47 = V_22 [ V_75 ] | V_22 [ V_76 ] |
V_22 [ V_77 ] ;
F_3 ( V_5 , V_78 , V_47 ) ;
V_47 = V_22 [ V_79 ] | V_22 [ V_80 ] ;
F_3 ( V_5 , V_81 , V_47 ) ;
V_47 = V_22 [ V_82 ] |
V_22 [ V_83 ] |
V_22 [ V_84 ] |
V_22 [ V_85 ] ;
F_3 ( V_5 , V_86 , V_47 ) ;
V_47 = V_22 [ V_87 ] | V_22 [ V_88 ] |
V_22 [ V_89 ] ;
F_3 ( V_5 , V_90 , V_47 ) ;
}
static void F_31 ( struct V_1 * V_5 )
{
T_1 V_47 ;
V_47 = F_5 ( V_5 , V_65 ) ;
V_47 &= ~ ( V_67 | V_68
| V_71 | V_72 ) ;
F_3 ( V_5 , V_65 , V_47 ) ;
V_47 = F_5 ( V_5 , V_55 ) ;
V_47 &= ~ V_51 ;
F_3 ( V_5 , V_55 , V_47 ) ;
}
static void F_32 ( struct V_1 * V_5 , T_1 V_91 )
{
T_1 V_47 = F_5 ( V_5 , V_92 ) ;
V_47 |= ( F_33 ( V_5 -> V_73 - 1 ) | V_93 |
F_34 ( V_91 ) ) ;
F_3 ( V_5 , V_92 , V_47 ) ;
}
static int F_35 ( struct V_1 * V_5 )
{
struct V_12 * V_10 = V_5 -> V_10 ;
int V_46 ;
T_1 V_47 ;
T_1 V_94 ;
V_47 = F_5 ( V_5 , V_95 ) ;
V_47 &= ~ 0x1f ;
F_3 ( V_5 , V_95 , V_47 ) ;
F_36 ( 9000 , 11000 ) ;
V_47 |= 0x1f ;
F_3 ( V_5 , V_95 , V_47 ) ;
F_36 ( 9000 , 11000 ) ;
V_47 = 0 ;
if ( V_5 -> V_96 & V_97 ) {
V_47 |= V_98 ;
if ( ! ( V_5 -> V_96 & V_99 ) )
V_47 |= V_100 ;
if ( V_5 -> V_96 & V_101 )
V_47 |= V_102 ;
if ( V_5 -> V_96 & V_103 )
V_47 |= V_104 ;
if ( V_5 -> V_96 & V_105 )
V_47 |= V_106 ;
if ( V_5 -> V_96 & V_107 )
V_47 |= V_108 ;
if ( ! ( V_5 -> V_96 & V_109 ) )
V_47 |= V_110 ;
if ( ! ( V_5 -> V_96 & V_111 ) )
V_47 |= V_112 ;
if ( ! ( V_5 -> V_96 & V_113 ) )
V_47 |= V_114 ;
}
if ( ! ( V_5 -> V_96 & V_115 ) )
V_47 |= V_116 ;
switch ( V_5 -> V_117 ) {
case V_118 :
V_47 |= V_119 ;
break;
case V_120 :
V_47 |= V_121 ;
break;
case V_122 :
V_47 |= V_123 ;
break;
case V_124 :
V_47 |= V_125 ;
break;
default:
F_12 ( V_5 -> V_18 , L_8 ) ;
return - V_126 ;
}
if ( V_10 -> V_127 &&
V_5 -> V_96 & V_128 ) {
V_47 |= V_129 ;
}
F_3 ( V_5 , V_92 , V_47 ) ;
V_94 = F_28 ( V_5 -> V_73 ) - 1 ;
F_32 ( V_5 , V_94 ) ;
V_46 = 100 ;
do {
if ( V_46 -- == 0 ) {
F_12 ( V_5 -> V_18 , L_9 ) ;
return - V_63 ;
}
V_47 = F_5 ( V_5 , V_56 ) ;
if ( ( V_47 & F_37 ( V_94 ) )
!= F_37 ( V_94 ) )
continue;
} while ( ! ( V_47 & ( V_130 | V_131 ) ) );
V_47 = F_5 ( V_5 , V_132 ) ;
V_47 &= ~ V_133 ;
V_47 |= F_38 ( V_10 -> V_22 [ V_134 ] ) ;
F_3 ( V_5 , V_132 , V_47 ) ;
V_47 = F_39 ( 0xff ) | F_40 ( 0xffff ) ;
F_3 ( V_5 , V_135 , V_47 ) ;
return 0 ;
}
static void F_41 ( struct V_1 * V_5 )
{
struct V_136 * V_137 = & V_5 -> V_137 ;
unsigned int V_138 = V_5 -> V_10 -> V_138 ;
T_1 V_47 ;
if ( V_5 -> V_96 & V_97 ) {
V_47 = F_42 ( 0xf )
| F_43 ( V_137 -> V_139 )
| F_44 ( V_137 -> V_140 ) ;
F_3 ( V_5 , V_141 , V_47 ) ;
V_47 = F_45 ( V_137 -> V_142 )
| F_46 ( V_137 -> V_143 ) ;
F_3 ( V_5 , V_144 , V_47 ) ;
V_47 = F_47 ( V_137 -> V_145 )
| F_48 ( V_137 -> V_146 ) ;
F_3 ( V_5 , V_147 , V_47 ) ;
}
V_47 = F_49 ( V_137 -> V_148 , V_138 ) |
F_50 ( V_137 -> V_149 , V_138 ) ;
F_3 ( V_5 , V_150 , V_47 ) ;
F_19 ( V_5 -> V_18 , L_10 , V_137 -> V_148 , V_137 -> V_149 ) ;
}
static void F_51 ( struct V_1 * V_5 , bool V_151 )
{
T_1 V_47 ;
V_47 = F_5 ( V_5 , V_150 ) ;
if ( V_151 )
V_47 |= V_152 ;
else
V_47 &= ~ V_152 ;
F_3 ( V_5 , V_150 , V_47 ) ;
}
static int F_52 ( struct V_1 * V_5 )
{
int V_46 = 2000 ;
do {
T_1 V_47 = F_5 ( V_5 , V_95 ) ;
if ( ! ( V_47 & V_153 ) )
return 0 ;
if ( ! F_53 () )
F_36 ( 950 , 1050 ) ;
} while ( -- V_46 );
return - V_154 ;
}
static void F_54 ( struct V_1 * V_5 , bool V_155 )
{
T_1 V_156 = F_5 ( V_5 , V_132 ) ;
if ( V_155 )
V_156 |= V_157 ;
else
V_156 &= ~ V_157 ;
F_3 ( V_5 , V_132 , V_156 ) ;
}
static void F_55 ( struct V_1 * V_5 )
{
T_1 V_156 = F_5 ( V_5 , V_132 ) ;
V_156 |= V_158 ;
F_3 ( V_5 , V_132 , V_156 ) ;
}
static void F_56 ( struct V_1 * V_5 ,
struct V_159 * V_160 )
{
struct V_161 * V_18 = V_5 -> V_18 ;
struct V_162 * V_163 = & V_160 -> V_164 ;
const T_2 * V_165 = V_163 -> V_165 + V_160 -> V_166 ;
T_3 V_167 = V_163 -> V_168 - V_160 -> V_166 ;
bool V_169 = ! V_160 -> V_166 ;
T_1 V_47 ;
F_19 ( V_18 , L_11 ,
V_160 , V_167 , V_160 -> V_166 , V_160 -> V_170 , V_160 -> V_171 ) ;
if ( V_167 > V_172 )
V_167 = V_172 ;
V_160 -> V_166 += V_167 ;
while ( V_167 >= 4 ) {
V_47 = F_57 ( V_165 ) ;
F_3 ( V_5 , V_173 , V_47 ) ;
V_165 += 4 ;
V_167 -= 4 ;
}
V_47 = 0 ;
switch ( V_167 ) {
case 3 :
V_47 |= V_165 [ 2 ] << 16 ;
case 2 :
V_47 |= V_165 [ 1 ] << 8 ;
case 1 :
V_47 |= V_165 [ 0 ] ;
F_3 ( V_5 , V_173 , V_47 ) ;
break;
}
if ( ! V_169 )
return;
V_47 = F_57 ( V_163 -> V_174 ) ;
if ( F_52 ( V_5 ) ) {
F_12 ( V_18 , L_12 ) ;
return;
}
if ( F_58 ( V_160 -> V_175 & V_176 ,
V_5 -> V_177 & V_178 ) ) {
F_54 ( V_5 , V_160 -> V_175 & V_176 ) ;
V_5 -> V_177 ^= V_178 ;
}
F_3 ( V_5 , V_179 , V_47 ) ;
if ( V_160 -> V_175 & V_180 )
F_55 ( V_5 ) ;
}
static void F_59 ( struct V_1 * V_5 ,
struct V_159 * V_160 )
{
T_2 * V_165 = V_160 -> V_181 + V_160 -> V_171 ;
bool V_169 = ! V_160 -> V_171 ;
struct V_161 * V_18 = V_5 -> V_18 ;
T_3 V_167 ;
T_1 V_47 ;
if ( V_169 ) {
V_47 = F_5 ( V_5 , V_182 ) ;
switch ( V_47 & 0x3f ) {
case V_183 :
case V_184 :
if ( V_160 -> V_170 >= 2 ) {
V_165 [ 1 ] = V_47 >> 16 ;
++ V_160 -> V_171 ;
}
case V_185 :
case V_186 :
V_165 [ 0 ] = V_47 >> 8 ;
++ V_160 -> V_171 ;
V_160 -> V_170 = V_160 -> V_171 ;
V_160 -> V_187 = 0 ;
goto V_188;
case V_189 :
F_12 ( V_18 , L_13 ,
( V_47 >> 8 ) & 0xffff ) ;
V_160 -> V_187 = 0 ;
goto V_188;
}
V_167 = ( V_47 >> 8 ) & 0xffff ;
if ( V_167 > V_160 -> V_170 ) {
F_12 ( V_18 ,
L_14 ,
V_160 -> V_170 , V_167 ) ;
V_167 = V_160 -> V_170 ;
} else if ( V_167 < V_160 -> V_170 )
V_160 -> V_170 = V_167 ;
}
V_167 = V_160 -> V_170 - V_160 -> V_171 ;
V_160 -> V_171 += V_167 ;
while ( V_167 >= 4 ) {
V_47 = F_5 ( V_5 , V_182 ) ;
V_165 [ 0 ] = ( V_47 >> 0 ) & 0xff ;
V_165 [ 1 ] = ( V_47 >> 8 ) & 0xff ;
V_165 [ 2 ] = ( V_47 >> 16 ) & 0xff ;
V_165 [ 3 ] = ( V_47 >> 24 ) & 0xff ;
V_165 += 4 ;
V_167 -= 4 ;
}
if ( V_167 ) {
V_47 = F_5 ( V_5 , V_182 ) ;
switch ( V_167 ) {
case 3 :
V_165 [ 2 ] = ( V_47 >> 16 ) & 0xff ;
case 2 :
V_165 [ 1 ] = ( V_47 >> 8 ) & 0xff ;
case 1 :
V_165 [ 0 ] = V_47 & 0xff ;
}
}
if ( V_160 -> V_171 == V_160 -> V_170 )
V_160 -> V_187 = 0 ;
V_188:
V_167 = V_190 / 4 ;
do {
V_47 = F_5 ( V_5 , V_182 ) ;
if ( V_47 == V_191 )
break;
} while ( -- V_167 );
}
static void F_60 ( struct V_1 * V_5 )
{
unsigned long V_175 ;
struct V_159 * V_160 ;
bool V_192 = false ;
V_193:
F_61 ( & V_5 -> V_194 , V_175 ) ;
if ( F_62 ( & V_5 -> V_195 ) ) {
F_63 ( & V_5 -> V_194 , V_175 ) ;
return;
}
V_160 = F_64 ( & V_5 -> V_195 ,
struct V_159 , V_196 ) ;
F_63 ( & V_5 -> V_194 , V_175 ) ;
if ( V_160 -> V_164 . V_168 &&
V_160 -> V_166 == V_160 -> V_164 . V_168 )
return;
F_56 ( V_5 , V_160 ) ;
if ( V_160 -> V_164 . V_168 || V_160 -> V_170 )
return;
V_160 -> V_187 = 0 ;
F_65 ( & V_160 -> V_20 ) ;
F_61 ( & V_5 -> V_194 , V_175 ) ;
F_66 ( & V_160 -> V_196 ) ;
V_192 = ! F_62 ( & V_5 -> V_195 ) ;
F_63 ( & V_5 -> V_194 , V_175 ) ;
if ( V_192 )
goto V_193;
}
static bool F_67 ( struct V_1 * V_5 )
{
struct V_159 * V_160 ;
unsigned long V_175 ;
bool V_192 = true ;
F_61 ( & V_5 -> V_194 , V_175 ) ;
if ( F_62 ( & V_5 -> V_195 ) ) {
F_63 ( & V_5 -> V_194 , V_175 ) ;
return false ;
}
V_160 = F_64 ( & V_5 -> V_195 ,
struct V_159 , V_196 ) ;
F_63 ( & V_5 -> V_194 , V_175 ) ;
F_19 ( V_5 -> V_18 ,
L_15 ,
V_160 , V_160 -> V_164 . V_168 , V_160 -> V_166 , V_160 -> V_170 ,
V_160 -> V_171 ) ;
if ( V_160 -> V_166 != V_160 -> V_164 . V_168 )
return true ;
if ( V_160 -> V_171 != V_160 -> V_170 )
F_59 ( V_5 , V_160 ) ;
if ( V_160 -> V_171 != V_160 -> V_170 )
return true ;
F_61 ( & V_5 -> V_194 , V_175 ) ;
F_66 ( & V_160 -> V_196 ) ;
V_192 = ! F_62 ( & V_5 -> V_195 ) ;
F_63 ( & V_5 -> V_194 , V_175 ) ;
if ( ! V_160 -> V_170 )
V_160 -> V_187 = 0 ;
F_65 ( & V_160 -> V_20 ) ;
return V_192 ;
}
static void F_68 ( struct V_1 * V_5 ,
struct V_159 * V_160 )
{
unsigned long V_175 ;
bool V_192 ;
F_61 ( & V_5 -> V_194 , V_175 ) ;
if ( ! F_62 ( & V_5 -> V_195 ) &&
V_160 == F_64 ( & V_5 -> V_195 ,
struct V_159 , V_196 ) ) {
F_66 ( & V_160 -> V_196 ) ;
V_192 = ! F_62 ( & V_5 -> V_195 ) ;
F_63 ( & V_5 -> V_194 , V_175 ) ;
if ( V_192 )
F_60 ( V_5 ) ;
return;
}
F_66 ( & V_160 -> V_196 ) ;
F_63 ( & V_5 -> V_194 , V_175 ) ;
}
static int V_159 ( struct V_1 * V_5 ,
struct V_159 * V_160 )
{
unsigned long V_175 ;
bool V_197 ;
V_160 -> V_166 = 0 ;
V_160 -> V_171 = 0 ;
V_160 -> V_187 = - V_154 ;
F_69 ( & V_160 -> V_20 ) ;
F_61 ( & V_5 -> V_194 , V_175 ) ;
V_197 = F_62 ( & V_5 -> V_195 ) ;
F_70 ( & V_160 -> V_196 , & V_5 -> V_195 ) ;
F_63 ( & V_5 -> V_194 , V_175 ) ;
if ( V_197 )
F_60 ( V_5 ) ;
F_10 ( & V_160 -> V_20 ,
F_11 ( V_198 ) ) ;
if ( V_160 -> V_187 == - V_154 ) {
struct V_162 * V_163 = & V_160 -> V_164 ;
F_68 ( V_5 , V_160 ) ;
F_12 ( V_5 -> V_18 , L_16 , 4 , V_163 -> V_174 ,
( int ) V_163 -> V_168 , V_163 -> V_165 ) ;
return - V_154 ;
}
return V_160 -> V_187 ;
}
static T_5 F_71 ( int V_199 , void * V_200 )
{
struct V_1 * V_5 = V_200 ;
T_1 V_201 ;
V_201 = F_5 ( V_5 , V_202 ) ;
if ( ! V_201 ) {
static unsigned long int V_203 ;
if ( F_72 ( & V_203 , 500 ) )
F_73 ( V_5 -> V_18 , L_17 ) ;
return V_204 ;
}
F_3 ( V_5 , V_202 , V_201 ) ;
if ( V_201 & V_205 ) {
T_1 V_206 = ~ ( V_207 | V_208 |
V_209 | V_210 |
V_211 | V_205 ) ;
F_3 ( V_5 , V_212 , V_206 ) ;
F_65 ( & V_5 -> V_20 ) ;
return V_204 ;
}
if ( ! ( V_201 & ( V_207 | V_208 |
V_210 | V_213 ) ) )
return V_204 ;
if ( F_67 ( V_5 ) )
F_60 ( V_5 ) ;
return V_204 ;
}
static T_5 F_74 ( int V_199 , void * V_200 )
{
struct V_1 * V_5 = (struct V_1 * ) V_200 ;
struct V_2 * V_4 = & V_5 -> V_4 ;
if ( V_5 -> V_177 & V_214 )
F_75 ( V_4 -> V_215 ) ;
return V_204 ;
}
static void F_76 ( struct V_1 * V_5 )
{
F_77 ( V_5 -> V_199 ) ;
if ( F_78 ( V_5 -> V_216 ) )
F_77 ( F_79 ( V_5 -> V_216 ) ) ;
}
static void F_80 ( struct V_1 * V_5 )
{
if ( F_78 ( V_5 -> V_216 ) )
F_81 ( F_79 ( V_5 -> V_216 ) ) ;
F_81 ( V_5 -> V_199 ) ;
}
static int F_82 ( struct V_1 * V_5 )
{
struct V_12 * V_10 = V_5 -> V_10 ;
F_13 ( V_5 ) ;
F_76 ( V_5 ) ;
if ( V_10 -> V_22 [ V_23 ] == V_217 )
F_32 ( V_5 , F_28 ( V_5 -> V_73 ) - 1 ) ;
F_25 ( V_5 ) ;
if ( V_10 -> V_218 )
F_9 ( V_5 ) ;
F_30 ( V_5 ) ;
F_35 ( V_5 ) ;
return 0 ;
}
static int F_83 ( struct V_1 * V_5 )
{
int V_219 ;
int V_220 ;
V_5 -> V_216 = F_84 ( V_5 -> V_221 , L_18 , 0 ) ;
if ( ! F_78 ( V_5 -> V_216 ) ) {
F_12 ( V_5 -> V_18 , L_19 ) ;
V_219 = V_5 -> V_216 ;
goto V_222;
}
V_219 = F_85 ( V_5 -> V_216 , L_20 ) ;
if ( V_219 ) {
F_12 ( V_5 -> V_18 , L_21 , V_219 ) ;
goto V_222;
}
V_220 = F_79 ( V_5 -> V_216 ) ;
F_86 ( V_220 , V_223 ) ;
V_219 = F_87 ( V_220 , F_74 , NULL ,
V_224 , L_22 , V_5 ) ;
if ( V_219 ) {
F_12 ( V_5 -> V_18 , L_23 , V_219 ) ;
F_88 ( V_5 -> V_216 ) ;
goto V_222;
}
V_222:
return V_219 ;
}
static void F_89 ( struct V_1 * V_5 )
{
if ( F_78 ( V_5 -> V_216 ) ) {
F_90 ( F_79 ( V_5 -> V_216 ) , V_5 ) ;
F_88 ( V_5 -> V_216 ) ;
V_5 -> V_216 = - V_225 ;
}
}
static int F_91 ( struct V_226 * V_227 ,
struct V_228 * V_161 )
{
struct V_1 * V_5 = F_92 ( V_227 ) ;
V_5 -> V_73 = V_161 -> V_73 ;
V_5 -> V_117 = V_161 -> V_117 ;
V_5 -> V_96 = V_161 -> V_96 ;
V_5 -> V_221 = V_161 -> V_18 . V_229 ;
if ( ! ( V_5 -> V_96 & V_97 ) ) {
int V_219 = F_83 ( V_5 ) ;
if ( V_219 )
return V_219 ;
}
if ( V_5 -> V_230 . V_18 )
F_93 ( V_5 -> V_230 . V_18 ) ;
return 0 ;
}
static int F_94 ( struct V_226 * V_227 ,
struct V_228 * V_161 )
{
struct V_1 * V_5 = F_92 ( V_227 ) ;
F_89 ( V_5 ) ;
V_5 -> V_221 = NULL ;
if ( V_5 -> V_230 . V_18 )
F_93 ( V_5 -> V_230 . V_18 ) ;
return 0 ;
}
static T_6 F_95 ( struct V_226 * V_227 ,
const struct V_231 * V_232 )
{
struct V_1 * V_5 = F_92 ( V_227 ) ;
struct V_159 V_160 ;
int V_219 ;
if ( ! ( V_5 -> V_177 & V_233 ) )
return - V_126 ;
if ( ! ( V_5 -> V_177 & V_234 ) ) {
V_219 = F_82 ( V_5 ) ;
if ( V_219 )
return V_219 ;
V_5 -> V_177 |= V_234 ;
}
V_219 = F_96 ( & V_160 . V_164 , V_232 ) ;
if ( V_219 < 0 )
return V_219 ;
V_160 . V_170 = V_232 -> V_170 ;
V_160 . V_181 = V_232 -> V_235 ;
V_160 . V_175 = V_232 -> V_175 ;
V_219 = V_159 ( V_5 , & V_160 ) ;
return ( V_219 < 0 ) ? V_219 : V_160 . V_171 ;
}
static void F_97 ( struct V_2 * V_4 )
{
struct V_1 * V_5 = F_1 ( V_4 ) ;
int V_219 ;
if ( V_5 -> V_177 & V_233 )
return;
F_98 ( V_5 -> V_18 ) ;
V_5 -> V_177 |= V_233 ;
V_219 = F_99 ( V_5 -> V_236 ) ;
if ( V_219 < 0 ) {
V_5 -> V_177 &= ~ V_233 ;
F_100 ( V_5 -> V_18 ) ;
return;
}
F_41 ( V_5 ) ;
F_51 ( V_5 , true ) ;
V_219 = F_101 ( V_5 -> V_236 ) ;
if ( V_219 < 0 ) {
V_5 -> V_177 &= ~ V_233 ;
F_51 ( V_5 , false ) ;
F_102 ( V_5 -> V_236 ) ;
F_100 ( V_5 -> V_18 ) ;
return;
}
V_5 -> V_177 |= V_214 ;
}
static void F_103 ( struct V_2 * V_4 )
{
struct V_1 * V_5 = F_1 ( V_4 ) ;
if ( ! ( V_5 -> V_177 & V_233 ) )
return;
V_5 -> V_177 &= ~ V_214 ;
F_104 ( V_5 -> V_236 ) ;
F_51 ( V_5 , false ) ;
F_102 ( V_5 -> V_236 ) ;
V_5 -> V_177 &= ~ V_233 ;
F_100 ( V_5 -> V_18 ) ;
}
static enum V_237
F_105 ( struct V_238 * V_230 , bool V_239 )
{
struct V_1 * V_5 = F_106 ( V_230 ) ;
if ( ! V_5 -> V_236 ) {
V_5 -> V_236 = F_107 ( V_5 -> V_221 ) ;
if ( V_5 -> V_236 )
F_108 ( V_5 -> V_236 , & V_5 -> V_230 ) ;
} else if ( ! V_5 -> V_221 ) {
struct V_2 * V_4 ;
V_4 = F_109 ( F_110 ( V_5 -> V_18 ) ) ;
F_103 ( V_4 ) ;
F_111 ( V_5 -> V_236 ) ;
V_5 -> V_236 = NULL ;
}
if ( V_5 -> V_236 )
return V_240 ;
return V_241 ;
}
static void F_112 ( struct V_238 * V_230 )
{
F_113 ( V_230 ) ;
F_114 ( V_230 ) ;
V_230 -> V_18 = NULL ;
}
static int F_115 ( struct V_238 * V_230 )
{
struct V_1 * V_5 = F_106 ( V_230 ) ;
if ( V_5 -> V_236 )
return V_5 -> V_236 -> V_242 -> V_243 ( V_5 -> V_236 ) ;
return 0 ;
}
static struct V_2 *
F_116 ( struct V_238 * V_230 )
{
struct V_1 * V_5 = F_106 ( V_230 ) ;
return & V_5 -> V_4 ;
}
static int F_117 ( struct V_2 * V_4 )
{
struct V_1 * V_5 = F_1 ( V_4 ) ;
struct V_238 * V_230 = & V_5 -> V_230 ;
int V_219 ;
V_230 -> V_244 = V_245 ;
V_219 = F_118 ( V_4 -> V_18 , V_230 ,
& V_246 ,
V_247 ) ;
if ( V_219 ) {
F_119 ( L_24 ) ;
return V_219 ;
}
F_120 ( V_230 , & V_248 ) ;
F_121 ( V_230 ) ;
F_122 ( V_230 , V_4 ) ;
return 0 ;
}
static void F_123 ( struct V_2 * V_4 ,
struct V_249 * V_250 ,
struct V_249 * V_251 )
{
struct V_1 * V_5 = F_1 ( V_4 ) ;
struct V_136 * V_137 = & V_5 -> V_137 ;
struct V_249 * V_28 = V_251 ;
V_137 -> V_148 = V_28 -> V_252 ;
V_137 -> V_149 = V_28 -> V_253 ;
V_137 -> V_139 = V_28 -> V_254 - V_28 -> V_253 ;
V_137 -> V_140 = V_28 -> V_255 - V_28 -> V_256 ;
V_137 -> V_145 = V_28 -> V_256 - V_28 -> V_254 ;
V_137 -> V_142 = V_28 -> V_257 - V_28 -> V_252 ;
V_137 -> V_143 = V_28 -> V_258 - V_28 -> V_259 ;
V_137 -> V_146 = V_28 -> V_259 - V_28 -> V_257 ;
}
static struct V_260 *
F_124 ( struct V_260 * V_261 , const char * V_262 , T_1 V_47 )
{
struct V_260 * V_263 ;
F_125 (parent, np) {
T_1 V_264 ;
if ( ! V_263 -> V_262 || F_126 ( V_263 -> V_262 , V_262 ) )
continue;
if ( F_127 ( V_263 , L_25 , & V_264 ) < 0 )
V_264 = 0 ;
if ( V_47 == V_264 )
break;
}
return V_263 ;
}
static struct V_260 * F_128 ( struct V_260 * V_261 ,
T_1 V_47 )
{
struct V_260 * V_265 , * V_266 ;
V_265 = F_129 ( V_261 , L_26 ) ;
if ( V_265 )
V_261 = V_265 ;
V_266 = F_124 ( V_261 , L_27 , V_47 ) ;
F_130 ( V_265 ) ;
return V_266 ;
}
static struct V_260 *
F_131 ( struct V_260 * V_266 , T_1 V_47 )
{
return F_124 ( V_266 , L_28 , V_47 ) ;
}
static int F_132 ( const struct V_260 * V_263 ,
const char * V_267 , T_1 * V_268 )
{
int V_219 = F_127 ( V_263 , V_267 , V_268 ) ;
if ( V_219 < 0 )
F_133 ( L_29 , V_263 -> V_269 ,
V_267 ) ;
return V_219 ;
}
static int F_134 ( struct V_1 * V_5 )
{
struct V_161 * V_18 = V_5 -> V_18 ;
struct V_260 * V_270 = V_18 -> V_229 ;
struct V_260 * V_266 , * V_271 ;
int V_219 ;
V_219 = F_132 ( V_270 , L_30 ,
& V_5 -> V_48 ) ;
if ( V_219 < 0 )
return V_219 ;
V_266 = F_128 ( V_270 , V_272 ) ;
if ( ! V_266 ) {
F_12 ( V_18 , L_31 ) ;
return - V_126 ;
}
V_271 = F_131 ( V_266 , 0 ) ;
F_130 ( V_266 ) ;
if ( ! V_271 ) {
F_12 ( V_18 , L_32 ) ;
return - V_126 ;
}
V_219 = F_132 ( V_271 , L_33 ,
& V_5 -> V_62 ) ;
if ( V_219 < 0 )
goto V_273;
V_219 = F_132 ( V_271 , L_34 ,
& V_5 -> V_64 ) ;
if ( V_219 < 0 )
goto V_273;
F_130 ( V_271 ) ;
V_271 = F_135 ( V_270 , NULL ) ;
if ( ! V_271 ) {
V_219 = - V_126 ;
goto V_273;
}
V_5 -> V_274 = F_136 ( V_271 ) ;
if ( ! V_5 -> V_274 ) {
V_219 = - V_126 ;
goto V_273;
}
V_273:
F_130 ( V_271 ) ;
return V_219 ;
}
static int F_137 ( struct V_161 * V_18 , struct V_161 * V_275 ,
void * V_19 )
{
struct V_2 * V_4 = F_138 ( V_18 ) ;
struct V_1 * V_5 = F_1 ( V_4 ) ;
struct V_276 * V_277 = V_19 ;
struct V_278 * V_279 ;
int V_219 ;
V_219 = F_139 ( V_277 ,
V_280 ) ;
if ( V_219 < 0 )
return V_219 ;
V_4 -> V_281 = 1 << V_219 ;
F_140 ( L_35 , V_4 -> V_281 ) ;
F_141 ( V_277 , V_4 , & V_282 ,
V_283 , NULL ) ;
F_142 ( V_4 , & V_284 ) ;
V_219 = F_117 ( V_4 ) ;
if ( V_219 ) {
F_119 ( L_36 , V_219 ) ;
F_143 ( V_4 ) ;
return V_219 ;
}
V_279 = F_144 ( V_5 -> V_274 ) ;
if ( V_279 ) {
V_4 -> V_279 = V_279 ;
F_145 ( V_277 , V_279 ) ;
}
return F_146 ( & V_5 -> V_285 ) ;
}
static void F_147 ( struct V_161 * V_18 , struct V_161 * V_275 ,
void * V_19 )
{
struct V_2 * V_4 = F_138 ( V_18 ) ;
struct V_1 * V_5 = F_1 ( V_4 ) ;
F_103 ( V_4 ) ;
F_148 ( & V_5 -> V_285 ) ;
}
static int F_149 ( struct V_13 * V_14 )
{
struct V_161 * V_18 = & V_14 -> V_18 ;
struct V_286 * V_287 ;
struct V_1 * V_5 ;
int V_219 , V_288 ;
V_5 = F_150 ( V_18 , sizeof( * V_5 ) , V_289 ) ;
if ( ! V_5 )
return - V_290 ;
V_5 -> V_216 = - V_225 ;
F_69 ( & V_5 -> V_20 ) ;
F_151 ( & V_5 -> V_194 ) ;
F_152 ( & V_5 -> V_195 ) ;
V_5 -> V_285 . V_291 = & V_292 ;
V_5 -> V_285 . V_18 = V_18 ;
V_5 -> V_18 = V_18 ;
V_5 -> V_10 = F_7 ( V_14 ) ;
V_219 = F_134 ( V_5 ) ;
if ( V_219 )
return V_219 ;
V_5 -> V_293 [ 0 ] . V_294 = L_37 ;
V_5 -> V_293 [ 1 ] . V_294 = L_38 ;
V_219 = F_153 ( V_18 , F_23 ( V_5 -> V_293 ) ,
V_5 -> V_293 ) ;
if ( V_219 ) {
F_154 ( V_18 , L_39 , V_219 ) ;
return - V_295 ;
}
V_5 -> V_296 = F_150 ( V_18 ,
sizeof( * V_5 -> V_296 ) * V_5 -> V_10 -> V_297 ,
V_289 ) ;
if ( ! V_5 -> V_296 )
return - V_290 ;
for ( V_288 = 0 ; V_288 < V_5 -> V_10 -> V_297 ; V_288 ++ ) {
V_5 -> V_296 [ V_288 ] = F_155 ( V_18 , V_298 [ V_288 ] ) ;
if ( F_156 ( V_5 -> V_296 [ V_288 ] ) ) {
if ( strcmp ( V_298 [ V_288 ] , L_40 ) == 0 ) {
strcpy ( V_298 [ V_288 ] , V_299 ) ;
V_288 -- ;
continue;
}
F_154 ( V_18 , L_41 ,
V_298 [ V_288 ] ) ;
return F_157 ( V_5 -> V_296 [ V_288 ] ) ;
}
}
V_287 = F_158 ( V_14 , V_300 , 0 ) ;
V_5 -> V_9 = F_159 ( V_18 , V_287 ) ;
if ( F_156 ( V_5 -> V_9 ) ) {
F_12 ( V_18 , L_42 ) ;
return F_157 ( V_5 -> V_9 ) ;
}
V_5 -> V_301 = F_160 ( V_18 , L_43 ) ;
if ( F_156 ( V_5 -> V_301 ) ) {
F_154 ( V_18 , L_44 ) ;
return F_157 ( V_5 -> V_301 ) ;
}
V_5 -> V_199 = F_161 ( V_14 , 0 ) ;
if ( V_5 -> V_199 < 0 ) {
F_12 ( V_18 , L_45 ) ;
return V_5 -> V_199 ;
}
F_86 ( V_5 -> V_199 , V_223 ) ;
V_219 = F_162 ( V_18 , V_5 -> V_199 , NULL ,
F_71 , V_302 ,
F_163 ( V_18 ) , V_5 ) ;
if ( V_219 ) {
F_12 ( V_18 , L_46 ) ;
return V_219 ;
}
F_164 ( V_14 , & V_5 -> V_4 ) ;
F_165 ( V_18 ) ;
return F_166 ( V_18 , & V_303 ) ;
}
static int F_167 ( struct V_13 * V_14 )
{
F_168 ( & V_14 -> V_18 ) ;
F_169 ( & V_14 -> V_18 , & V_303 ) ;
return 0 ;
}
static int T_7 F_170 ( struct V_161 * V_18 )
{
struct V_2 * V_4 = F_138 ( V_18 ) ;
struct V_1 * V_5 = F_1 ( V_4 ) ;
struct V_12 * V_10 = V_5 -> V_10 ;
int V_219 , V_288 ;
F_36 ( 10000 , 20000 ) ;
if ( V_5 -> V_177 & V_234 ) {
V_5 -> V_177 &= ~ V_234 ;
F_31 ( V_5 ) ;
F_80 ( V_5 ) ;
}
V_5 -> V_177 &= ~ V_178 ;
F_171 ( V_5 -> V_301 ) ;
for ( V_288 = V_10 -> V_297 - 1 ; V_288 > - 1 ; V_288 -- )
F_172 ( V_5 -> V_296 [ V_288 ] ) ;
V_219 = F_173 ( F_23 ( V_5 -> V_293 ) , V_5 -> V_293 ) ;
if ( V_219 < 0 )
F_12 ( V_5 -> V_18 , L_47 , V_219 ) ;
return 0 ;
}
static int T_7 F_174 ( struct V_161 * V_18 )
{
struct V_2 * V_4 = F_138 ( V_18 ) ;
struct V_1 * V_5 = F_1 ( V_4 ) ;
struct V_12 * V_10 = V_5 -> V_10 ;
int V_219 , V_288 ;
V_219 = F_175 ( F_23 ( V_5 -> V_293 ) , V_5 -> V_293 ) ;
if ( V_219 < 0 ) {
F_12 ( V_5 -> V_18 , L_48 , V_219 ) ;
return V_219 ;
}
for ( V_288 = 0 ; V_288 < V_10 -> V_297 ; V_288 ++ ) {
V_219 = F_176 ( V_5 -> V_296 [ V_288 ] ) ;
if ( V_219 < 0 )
goto V_304;
}
V_219 = F_177 ( V_5 -> V_301 ) ;
if ( V_219 < 0 ) {
F_12 ( V_5 -> V_18 , L_49 , V_219 ) ;
goto V_304;
}
return 0 ;
V_304:
while ( -- V_288 > - 1 )
F_172 ( V_5 -> V_296 [ V_288 ] ) ;
F_173 ( F_23 ( V_5 -> V_293 ) , V_5 -> V_293 ) ;
return V_219 ;
}
