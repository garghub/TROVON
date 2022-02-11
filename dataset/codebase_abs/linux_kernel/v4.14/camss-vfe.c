static T_1 F_1 ( T_2 V_1 )
{
unsigned int V_2 ;
for ( V_2 = 0 ; V_2 < F_2 ( V_3 ) ; V_2 ++ )
if ( V_1 == V_3 [ V_2 ] . V_1 )
return V_3 [ V_2 ] . V_4 ;
F_3 ( 1 , L_1 ) ;
return V_3 [ 0 ] . V_4 ;
}
static inline void F_4 ( struct V_5 * V_6 , T_2 V_7 , T_2 V_8 )
{
T_2 V_9 = F_5 ( V_6 -> V_10 + V_7 ) ;
F_6 ( V_9 & ~ V_8 , V_6 -> V_10 + V_7 ) ;
}
static inline void F_7 ( struct V_5 * V_6 , T_2 V_7 , T_2 V_11 )
{
T_2 V_9 = F_5 ( V_6 -> V_10 + V_7 ) ;
F_6 ( V_9 | V_11 , V_6 -> V_10 + V_7 ) ;
}
static void F_8 ( struct V_5 * V_6 )
{
T_2 V_12 = V_13 |
V_14 |
V_15 |
V_16 |
V_17 |
V_18 |
V_19 |
V_20 |
V_21 ;
F_6 ( V_12 , V_6 -> V_10 + V_22 ) ;
}
static void F_9 ( struct V_5 * V_6 , T_1 V_23 , T_1 V_24 )
{
if ( V_24 )
F_7 ( V_6 , F_10 ( V_23 ) ,
1 << V_25 ) ;
else
F_4 ( V_6 , F_10 ( V_23 ) ,
1 << V_25 ) ;
}
static void F_11 ( struct V_5 * V_6 , T_1 V_23 , T_1 V_24 )
{
if ( V_24 )
F_7 ( V_6 , F_10 ( V_23 ) ,
1 << V_26 ) ;
else
F_4 ( V_6 , F_10 ( V_23 ) ,
1 << V_26 ) ;
}
static int F_12 ( T_3 V_27 , T_3 V_28 )
{
int V_29 = 0 ;
switch ( V_27 ) {
case V_30 :
case V_31 :
case V_32 :
case V_33 :
V_29 = F_13 ( V_28 , 1 , 8 ) ;
break;
case V_34 :
case V_35 :
case V_36 :
case V_37 :
V_29 = F_13 ( V_28 , 2 , 8 ) ;
break;
}
return V_29 ;
}
static void F_14 ( struct V_38 * V_39 , T_1 V_40 ,
T_4 * V_41 , T_4 * V_42 , T_4 * V_43 )
{
switch ( V_39 -> V_44 ) {
case V_30 :
case V_31 :
* V_41 = V_39 -> V_41 ;
* V_42 = V_39 -> V_42 ;
* V_43 = V_39 -> V_45 [ 0 ] . V_43 ;
if ( V_40 == 1 )
* V_42 /= 2 ;
break;
case V_32 :
case V_33 :
* V_41 = V_39 -> V_41 ;
* V_42 = V_39 -> V_42 ;
* V_43 = V_39 -> V_45 [ 0 ] . V_43 ;
break;
}
}
static void F_15 ( struct V_5 * V_6 , T_2 V_23 ,
struct V_38 * V_39 ,
T_1 V_40 , T_2 V_24 )
{
T_2 V_7 ;
if ( V_24 ) {
T_4 V_41 = 0 , V_42 = 0 , V_43 = 0 , V_46 ;
F_14 ( V_39 , V_40 , & V_41 , & V_42 , & V_43 ) ;
V_46 = F_12 ( V_39 -> V_44 , V_41 ) ;
V_7 = V_42 - 1 ;
V_7 |= ( ( V_46 + 1 ) / 2 - 1 ) << 16 ;
F_6 ( V_7 , V_6 -> V_10 +
F_16 ( V_23 ) ) ;
V_46 = F_12 ( V_39 -> V_44 , V_43 ) ;
V_7 = 0x3 ;
V_7 |= ( V_42 - 1 ) << 4 ;
V_7 |= V_46 << 16 ;
F_6 ( V_7 , V_6 -> V_10 +
F_17 ( V_23 ) ) ;
} else {
F_6 ( 0 , V_6 -> V_10 +
F_16 ( V_23 ) ) ;
F_6 ( 0 , V_6 -> V_10 +
F_17 ( V_23 ) ) ;
}
}
static void F_18 ( struct V_5 * V_6 , T_1 V_23 , T_1 V_47 )
{
T_2 V_7 ;
V_7 = F_5 ( V_6 -> V_10 +
F_19 ( V_23 ) ) ;
V_7 &= ~ ( V_48 ) ;
V_7 |= ( V_47 << V_49 )
& V_48 ;
F_6 ( V_7 ,
V_6 -> V_10 + F_19 ( V_23 ) ) ;
}
static void F_20 ( struct V_5 * V_6 , T_1 V_23 ,
T_2 V_50 )
{
F_6 ( V_50 ,
V_6 -> V_10 + F_21 ( V_23 ) ) ;
}
static void F_22 ( struct V_5 * V_6 , T_1 V_23 , T_4 V_51 ,
T_4 V_52 )
{
T_2 V_7 ;
V_7 = ( V_51 << V_53 ) |
V_52 ;
F_6 ( V_7 , V_6 -> V_10 + F_23 ( V_23 ) ) ;
}
static void F_24 ( struct V_5 * V_6 , T_1 V_23 )
{
F_25 () ;
F_6 ( F_26 ( V_23 ) , V_6 -> V_10 + V_54 ) ;
F_25 () ;
}
static void F_27 ( struct V_5 * V_6 , T_1 V_23 , T_2 V_55 )
{
F_6 ( V_55 ,
V_6 -> V_10 + F_28 ( V_23 ) ) ;
}
static void F_29 ( struct V_5 * V_6 , T_1 V_23 , T_2 V_55 )
{
F_6 ( V_55 ,
V_6 -> V_10 + F_30 ( V_23 ) ) ;
}
static int F_31 ( struct V_5 * V_6 , T_1 V_23 )
{
T_2 V_7 ;
V_7 = F_5 ( V_6 -> V_10 + V_56 ) ;
return ( V_7 >> V_23 ) & 0x1 ;
}
static void F_32 ( struct V_5 * V_6 , T_1 V_24 )
{
if ( V_24 )
F_6 ( 0x10000009 , V_6 -> V_10 + V_57 ) ;
else
F_6 ( 0 , V_6 -> V_10 + V_57 ) ;
}
static void F_33 ( struct V_5 * V_6 , T_1 V_23 ,
enum V_58 V_59 )
{
T_2 V_7 ;
V_7 = V_60 ;
V_7 |= F_34 ( V_59 ) ;
F_7 ( V_6 , F_35 ( 0 ) , V_7 ) ;
V_7 = V_61 ;
V_7 |= ( ( 3 * V_59 ) << V_62 ) &
V_63 ;
F_7 ( V_6 , F_35 ( V_59 ) , V_7 ) ;
switch ( V_59 ) {
case V_64 :
default:
V_7 = V_65 <<
V_66 ;
break;
case V_67 :
V_7 = V_68 <<
V_66 ;
break;
case V_69 :
V_7 = V_70 <<
V_66 ;
break;
}
if ( V_23 % 2 == 1 )
V_7 <<= 16 ;
F_7 ( V_6 , F_36 ( V_23 ) , V_7 ) ;
}
static void F_37 ( struct V_5 * V_6 , T_1 V_23 )
{
F_6 ( V_71 ,
V_6 -> V_10 +
F_38 ( V_23 ) ) ;
}
static void F_39 ( struct V_5 * V_6 , T_1 V_23 ,
enum V_58 V_59 )
{
T_2 V_7 ;
V_7 = F_34 ( V_59 ) ;
F_4 ( V_6 , F_35 ( 0 ) , V_7 ) ;
V_7 = V_61 ;
F_4 ( V_6 , F_35 ( V_59 ) , V_7 ) ;
switch ( V_59 ) {
case V_64 :
default:
V_7 = V_65 <<
V_66 ;
break;
case V_67 :
V_7 = V_68 <<
V_66 ;
break;
case V_69 :
V_7 = V_70 <<
V_66 ;
break;
}
if ( V_23 % 2 == 1 )
V_7 <<= 16 ;
F_4 ( V_6 , F_36 ( V_23 ) , V_7 ) ;
}
static void F_40 ( struct V_5 * V_6 , struct V_72 * V_73 ,
T_1 V_24 )
{
struct V_74 * line = F_41 ( V_73 , struct V_74 , V_73 ) ;
T_2 V_75 = line -> V_76 . V_77 . V_78 . V_79 . V_44 ;
T_2 V_7 ;
unsigned int V_2 ;
for ( V_2 = 0 ; V_2 < V_73 -> V_80 ; V_2 ++ ) {
if ( V_2 == 0 ) {
V_7 = V_81 <<
V_66 ;
} else if ( V_2 == 1 ) {
V_7 = V_82 ;
if ( V_75 == V_30 || V_75 == V_32 )
V_7 |= V_83 ;
}
if ( V_73 -> V_84 [ V_2 ] % 2 == 1 )
V_7 <<= 16 ;
if ( V_24 )
F_7 ( V_6 ,
F_36 ( V_73 -> V_84 [ V_2 ] ) ,
V_7 ) ;
else
F_4 ( V_6 ,
F_36 ( V_73 -> V_84 [ V_2 ] ) ,
V_7 ) ;
}
}
static void F_42 ( struct V_5 * V_6 , enum V_58 V_59 , T_1 V_85 )
{
F_4 ( V_6 , F_35 ( V_59 ) ,
V_86 ) ;
F_7 ( V_6 , F_35 ( V_59 ) ,
V_85 << V_87 ) ;
}
static void F_43 ( struct V_5 * V_6 , enum V_58 V_88 )
{
V_6 -> V_89 |= F_44 ( V_88 ) ;
F_25 () ;
F_6 ( V_6 -> V_89 , V_6 -> V_10 + V_90 ) ;
F_25 () ;
}
static void F_45 ( struct V_5 * V_6 , T_1 V_23 ,
enum V_58 V_88 , T_1 V_24 )
{
T_2 V_91 = F_46 ( V_23 ) |
F_47 ( V_88 ) ;
T_2 V_92 = F_48 ( V_23 ) |
F_49 ( V_88 ) ;
if ( V_24 ) {
F_7 ( V_6 , V_93 , V_91 ) ;
F_7 ( V_6 , V_94 , V_92 ) ;
} else {
F_4 ( V_6 , V_93 , V_91 ) ;
F_4 ( V_6 , V_94 , V_92 ) ;
}
}
static void F_50 ( struct V_5 * V_6 , T_1 V_95 ,
enum V_58 V_88 , T_1 V_24 )
{
struct V_72 * V_73 = & V_6 -> line [ V_88 ] . V_73 ;
unsigned int V_2 ;
T_2 V_91 ;
T_2 V_92 ;
T_2 V_96 = 0 ;
V_91 = V_97 ;
V_91 |= V_98 ;
V_91 |= F_51 ( V_95 ) ;
V_91 |= F_47 ( V_88 ) ;
V_92 = V_99 ;
for ( V_2 = 0 ; V_2 < V_73 -> V_80 ; V_2 ++ ) {
V_92 |= F_48 (
V_73 -> V_84 [ V_2 ] ) ;
V_96 |= ( 1 << V_73 -> V_84 [ V_2 ] ) << V_95 * 8 ;
}
if ( V_24 ) {
F_7 ( V_6 , V_93 , V_91 ) ;
F_7 ( V_6 , V_94 , V_92 ) ;
F_7 ( V_6 , V_100 , V_96 ) ;
} else {
F_4 ( V_6 , V_93 , V_91 ) ;
F_4 ( V_6 , V_94 , V_92 ) ;
F_4 ( V_6 , V_100 , V_96 ) ;
}
}
static void F_52 ( struct V_5 * V_6 )
{
T_2 V_91 = V_101 ;
T_2 V_92 = V_102 |
V_103 ;
F_7 ( V_6 , V_93 , V_91 ) ;
F_7 ( V_6 , V_94 , V_92 ) ;
}
static void F_53 ( struct V_5 * V_6 , struct V_74 * line )
{
T_2 V_29 , V_104 , V_105 ;
F_6 ( V_106 , V_6 -> V_10 + V_107 ) ;
V_29 = V_108 | V_109 ;
F_6 ( V_29 , V_6 -> V_10 + V_110 ) ;
V_29 = V_111 | V_112 ;
F_6 ( V_29 , V_6 -> V_10 + V_113 ) ;
switch ( line -> V_78 [ V_114 ] . V_1 ) {
case V_115 :
V_104 = V_116 ;
V_105 = V_117 ;
break;
case V_118 :
V_104 = V_119 ;
V_105 = V_120 ;
break;
case V_121 :
default:
V_104 = V_122 ;
V_105 = V_123 ;
break;
case V_124 :
V_104 = V_125 ;
V_105 = V_126 ;
break;
}
F_6 ( V_104 , V_6 -> V_10 + V_127 ) ;
F_6 ( V_105 , V_6 -> V_10 + V_128 ) ;
}
static inline T_1 F_54 ( T_4 V_129 , T_4 V_73 )
{
if ( V_129 / V_73 >= 16 )
return 0 ;
if ( V_129 / V_73 >= 8 )
return 1 ;
if ( V_129 / V_73 >= 4 )
return 2 ;
return 3 ;
}
static void F_55 ( struct V_5 * V_6 , struct V_74 * line )
{
T_2 V_75 = line -> V_76 . V_77 . V_78 . V_79 . V_44 ;
T_2 V_7 ;
T_4 V_129 , V_73 ;
T_1 V_130 ;
T_2 V_131 ;
F_6 ( 0x3 , V_6 -> V_10 + V_132 ) ;
V_129 = line -> V_78 [ V_114 ] . V_41 ;
V_73 = line -> V_133 . V_41 ;
V_7 = ( V_73 << 16 ) | V_129 ;
F_6 ( V_7 , V_6 -> V_10 + V_134 ) ;
V_130 = F_54 ( V_129 , V_73 ) ;
V_131 = V_129 * ( 1 << ( 13 + V_130 ) ) / V_73 ;
V_7 = ( V_130 << 20 ) | V_131 ;
F_6 ( V_7 , V_6 -> V_10 + V_135 ) ;
V_129 = line -> V_78 [ V_114 ] . V_42 ;
V_73 = line -> V_133 . V_42 ;
V_7 = ( V_73 << 16 ) | V_129 ;
F_6 ( V_7 , V_6 -> V_10 + V_136 ) ;
V_130 = F_54 ( V_129 , V_73 ) ;
V_131 = V_129 * ( 1 << ( 13 + V_130 ) ) / V_73 ;
V_7 = ( V_130 << 20 ) | V_131 ;
F_6 ( V_7 , V_6 -> V_10 + V_137 ) ;
F_6 ( 0x3 , V_6 -> V_10 + V_138 ) ;
V_129 = line -> V_78 [ V_114 ] . V_41 ;
V_73 = line -> V_133 . V_41 / 2 ;
V_7 = ( V_73 << 16 ) | V_129 ;
F_6 ( V_7 , V_6 -> V_10 + V_139 ) ;
V_130 = F_54 ( V_129 , V_73 ) ;
V_131 = V_129 * ( 1 << ( 13 + V_130 ) ) / V_73 ;
V_7 = ( V_130 << 20 ) | V_131 ;
F_6 ( V_7 , V_6 -> V_10 + V_140 ) ;
V_129 = line -> V_78 [ V_114 ] . V_42 ;
V_73 = line -> V_133 . V_42 ;
if ( V_75 == V_30 || V_75 == V_31 )
V_73 = line -> V_133 . V_42 / 2 ;
V_7 = ( V_73 << 16 ) | V_129 ;
F_6 ( V_7 , V_6 -> V_10 + V_141 ) ;
V_130 = F_54 ( V_129 , V_73 ) ;
V_131 = V_129 * ( 1 << ( 13 + V_130 ) ) / V_73 ;
V_7 = ( V_130 << 20 ) | V_131 ;
F_6 ( V_7 , V_6 -> V_10 + V_142 ) ;
}
static void F_56 ( struct V_5 * V_6 , struct V_74 * line )
{
T_2 V_75 = line -> V_76 . V_77 . V_78 . V_79 . V_44 ;
T_2 V_7 ;
T_4 V_143 , V_144 ;
V_143 = line -> V_145 . V_146 ;
V_144 = line -> V_145 . V_146 + line -> V_145 . V_41 - 1 ;
V_7 = ( V_143 << 16 ) | V_144 ;
F_6 ( V_7 , V_6 -> V_10 + V_147 ) ;
V_143 = line -> V_145 . V_148 ;
V_144 = line -> V_145 . V_148 + line -> V_145 . V_42 - 1 ;
V_7 = ( V_143 << 16 ) | V_144 ;
F_6 ( V_7 , V_6 -> V_10 + V_149 ) ;
V_143 = line -> V_145 . V_146 / 2 ;
V_144 = line -> V_145 . V_146 / 2 + line -> V_145 . V_41 / 2 - 1 ;
V_7 = ( V_143 << 16 ) | V_144 ;
F_6 ( V_7 , V_6 -> V_10 + V_150 ) ;
V_143 = line -> V_145 . V_148 ;
V_144 = line -> V_145 . V_148 + line -> V_145 . V_42 - 1 ;
if ( V_75 == V_30 || V_75 == V_31 ) {
V_143 = line -> V_145 . V_148 / 2 ;
V_144 = line -> V_145 . V_148 / 2 + line -> V_145 . V_42 / 2 - 1 ;
}
V_7 = ( V_143 << 16 ) | V_144 ;
F_6 ( V_7 , V_6 -> V_10 + V_151 ) ;
}
static void F_57 ( struct V_5 * V_6 )
{
T_2 V_29 = V_152 |
V_153 |
V_154 ;
F_6 ( V_29 , V_6 -> V_10 + V_155 ) ;
V_29 = V_156 |
V_157 |
V_158 ;
F_6 ( V_29 , V_6 -> V_10 + V_159 ) ;
}
static int F_58 ( struct V_5 * V_6 )
{
unsigned long time ;
F_59 ( & V_6 -> V_160 ) ;
F_8 ( V_6 ) ;
time = F_60 ( & V_6 -> V_160 ,
F_61 ( V_161 ) ) ;
if ( ! time ) {
F_62 ( F_63 ( V_6 ) , L_2 ) ;
return - V_162 ;
}
return 0 ;
}
static int F_64 ( struct V_5 * V_6 )
{
unsigned long time ;
F_59 ( & V_6 -> V_163 ) ;
F_6 ( V_164 ,
V_6 -> V_10 + V_165 ) ;
time = F_60 ( & V_6 -> V_163 ,
F_61 ( V_166 ) ) ;
if ( ! time ) {
F_62 ( F_63 ( V_6 ) , L_3 ) ;
return - V_162 ;
}
return 0 ;
}
static void F_65 ( struct V_5 * V_6 )
{
int V_2 ;
for ( V_2 = 0 ; V_2 < F_2 ( V_6 -> line ) ; V_2 ++ ) {
struct V_72 * V_73 = & V_6 -> line [ V_2 ] . V_73 ;
V_73 -> V_167 = V_168 ;
V_73 -> V_169 [ 0 ] = NULL ;
V_73 -> V_169 [ 1 ] = NULL ;
F_66 ( & V_73 -> V_170 ) ;
V_73 -> V_80 = 1 ;
if ( V_6 -> line [ V_2 ] . V_59 == V_171 )
V_73 -> V_80 = 2 ;
}
}
static void F_67 ( struct V_5 * V_6 )
{
int V_2 ;
for ( V_2 = 0 ; V_2 < F_2 ( V_6 -> V_172 ) ; V_2 ++ )
V_6 -> V_172 [ V_2 ] = V_173 ;
}
static void F_68 ( struct V_5 * V_6 )
{
T_2 V_29 = V_174 ;
T_2 V_175 = V_176 ;
F_6 ( V_29 , V_6 -> V_10 + V_177 ) ;
F_6 ( V_29 , V_6 -> V_10 + V_178 ) ;
F_6 ( V_29 , V_6 -> V_10 + V_179 ) ;
F_6 ( V_29 , V_6 -> V_10 + V_180 ) ;
F_6 ( V_29 , V_6 -> V_10 + V_181 ) ;
F_6 ( V_29 , V_6 -> V_10 + V_182 ) ;
F_6 ( V_29 , V_6 -> V_10 + V_183 ) ;
F_6 ( V_175 , V_6 -> V_10 + V_184 ) ;
}
static void F_69 ( struct V_5 * V_6 , T_1 V_23 , T_1 V_24 )
{
T_2 V_29 = F_70 ( V_23 ) ;
if ( V_24 )
F_7 ( V_6 , V_185 , V_29 ) ;
else
F_4 ( V_6 , V_185 , V_29 ) ;
F_25 () ;
}
static void F_71 ( struct V_5 * V_6 , T_1 V_24 )
{
T_2 V_29 = V_186 |
V_187 |
V_188 |
V_189 ;
if ( V_24 )
F_6 ( V_29 , V_6 -> V_10 + V_190 ) ;
else
F_6 ( 0x0 , V_6 -> V_10 + V_190 ) ;
}
static void F_72 ( struct V_5 * V_6 , struct V_74 * line )
{
T_2 V_29 ;
switch ( line -> V_78 [ V_114 ] . V_1 ) {
case V_115 :
V_29 = V_191 ;
break;
case V_118 :
V_29 = V_192 ;
break;
case V_121 :
default:
V_29 = V_193 ;
break;
case V_124 :
V_29 = V_194 ;
break;
}
F_6 ( V_29 , V_6 -> V_10 + V_195 ) ;
V_29 = line -> V_78 [ V_114 ] . V_41 * 2 ;
V_29 |= line -> V_78 [ V_114 ] . V_42 << 16 ;
F_6 ( V_29 , V_6 -> V_10 + V_196 ) ;
V_29 = line -> V_78 [ V_114 ] . V_41 * 2 - 1 ;
F_6 ( V_29 , V_6 -> V_10 + V_197 ) ;
V_29 = line -> V_78 [ V_114 ] . V_42 - 1 ;
F_6 ( V_29 , V_6 -> V_10 + V_198 ) ;
V_29 = 0xffffffff ;
F_6 ( V_29 , V_6 -> V_10 + V_199 ) ;
V_29 = 0xffffffff ;
F_6 ( V_29 , V_6 -> V_10 + V_200 ) ;
V_29 = V_60 ;
F_7 ( V_6 , F_35 ( 0 ) , V_29 ) ;
V_29 = V_201 ;
F_6 ( V_29 , V_6 -> V_10 + V_202 ) ;
}
static void F_73 ( struct V_5 * V_6 , T_2 V_203 )
{
F_6 ( V_204 ,
V_6 -> V_10 + V_205 ) ;
F_6 ( V_203 , V_6 -> V_10 + V_205 ) ;
}
static int F_74 ( struct V_5 * V_6 )
{
T_2 V_29 ;
int V_206 ;
V_206 = F_75 ( V_6 -> V_10 + V_207 ,
V_29 ,
( V_29 & V_208 ) ,
V_209 ,
V_210 ) ;
if ( V_206 < 0 )
F_62 ( F_63 ( V_6 ) , L_4 , V_211 ) ;
return V_206 ;
}
static void F_76 ( struct V_5 * V_6 ,
struct V_72 * V_73 , T_1 V_212 )
{
T_2 V_213 ;
T_2 V_214 ;
unsigned int V_2 ;
V_73 -> V_215 = 0 ;
for ( V_2 = 0 ; V_2 < V_73 -> V_80 ; V_2 ++ ) {
if ( V_73 -> V_169 [ 0 ] )
V_213 = V_73 -> V_169 [ 0 ] -> V_55 [ V_2 ] ;
else
V_213 = 0 ;
if ( V_73 -> V_169 [ 1 ] )
V_214 = V_73 -> V_169 [ 1 ] -> V_55 [ V_2 ] ;
else
V_214 = V_213 ;
F_27 ( V_6 , V_73 -> V_84 [ V_2 ] , V_213 ) ;
F_29 ( V_6 , V_73 -> V_84 [ V_2 ] , V_214 ) ;
if ( V_212 )
F_24 ( V_6 , V_73 -> V_84 [ V_2 ] ) ;
}
}
static void F_77 ( struct V_5 * V_6 ,
struct V_72 * V_73 , T_1 V_212 )
{
T_2 V_55 ;
unsigned int V_2 ;
for ( V_2 = 0 ; V_2 < V_73 -> V_80 ; V_2 ++ ) {
if ( V_73 -> V_169 [ 0 ] )
V_55 = V_73 -> V_169 [ 0 ] -> V_55 [ V_2 ] ;
else
V_55 = 0 ;
F_27 ( V_6 , V_73 -> V_84 [ V_2 ] , V_55 ) ;
if ( V_212 )
F_24 ( V_6 , V_73 -> V_84 [ V_2 ] ) ;
}
}
static void F_78 ( struct V_5 * V_6 ,
struct V_72 * V_73 , T_1 V_212 )
{
T_2 V_55 ;
unsigned int V_2 ;
for ( V_2 = 0 ; V_2 < V_73 -> V_80 ; V_2 ++ ) {
if ( V_73 -> V_169 [ 1 ] )
V_55 = V_73 -> V_169 [ 1 ] -> V_55 [ V_2 ] ;
else
V_55 = 0 ;
F_29 ( V_6 , V_73 -> V_84 [ V_2 ] , V_55 ) ;
if ( V_212 )
F_24 ( V_6 , V_73 -> V_84 [ V_2 ] ) ;
}
}
static int F_79 ( struct V_5 * V_6 , enum V_58 V_88 )
{
int V_206 = - V_216 ;
int V_2 ;
for ( V_2 = 0 ; V_2 < F_2 ( V_6 -> V_172 ) ; V_2 ++ ) {
if ( V_6 -> V_172 [ V_2 ] == V_173 ) {
V_6 -> V_172 [ V_2 ] = V_88 ;
V_206 = V_2 ;
break;
}
}
return V_206 ;
}
static int F_80 ( struct V_5 * V_6 , T_1 V_23 )
{
if ( V_23 >= F_2 ( V_6 -> V_172 ) )
return - V_217 ;
V_6 -> V_172 [ V_23 ] = V_173 ;
return 0 ;
}
static void F_81 ( struct V_5 * V_6 ,
struct V_72 * V_73 ,
T_2 V_218 )
{
T_1 V_219 ;
unsigned int V_2 ;
V_73 -> V_220 ++ ;
V_73 -> V_220 %= V_221 ;
V_219 = V_222 + V_73 -> V_220 ;
for ( V_2 = 0 ; V_2 < V_73 -> V_80 ; V_2 ++ ) {
F_18 ( V_6 , V_73 -> V_84 [ V_2 ] ,
V_219 ) ;
F_20 ( V_6 , V_73 -> V_84 [ V_2 ] ,
V_218 ) ;
}
F_43 ( V_6 , F_41 ( V_73 , struct V_74 , V_73 ) -> V_59 ) ;
}
static struct V_223 * F_82 ( struct V_72 * V_73 )
{
struct V_223 * V_224 = NULL ;
if ( ! F_83 ( & V_73 -> V_170 ) ) {
V_224 = F_84 ( & V_73 -> V_170 ,
struct V_223 ,
V_225 ) ;
F_85 ( & V_224 -> V_225 ) ;
}
return V_224 ;
}
static void F_86 ( struct V_72 * V_73 ,
struct V_223 * V_224 )
{
F_66 ( & V_224 -> V_225 ) ;
F_87 ( & V_224 -> V_225 , & V_73 -> V_170 ) ;
}
static void F_88 ( struct V_72 * V_73 ,
enum V_226 V_167 )
{
struct V_223 * V_169 ;
struct V_223 * V_227 ;
F_89 (buf, t, &output->pending_bufs, queue) {
F_90 ( & V_169 -> V_228 . V_229 , V_167 ) ;
F_85 ( & V_169 -> V_225 ) ;
}
}
static void F_91 ( struct V_5 * V_6 ,
struct V_72 * V_73 )
{
switch ( V_73 -> V_167 ) {
case V_230 :
F_81 ( V_6 , V_73 , 3 ) ;
break;
case V_231 :
default:
F_92 ( F_63 ( V_6 ) ,
L_5 ,
V_73 -> V_167 ) ;
break;
}
}
static void F_93 ( struct V_5 * V_6 ,
struct V_72 * V_73 )
{
switch ( V_73 -> V_167 ) {
case V_230 :
V_73 -> V_167 = V_231 ;
F_81 ( V_6 , V_73 , 1 ) ;
break;
case V_231 :
V_73 -> V_167 = V_232 ;
F_81 ( V_6 , V_73 , 0 ) ;
break;
default:
F_92 ( F_63 ( V_6 ) ,
L_6 ,
V_73 -> V_167 ) ;
break;
}
}
static void F_94 ( struct V_5 * V_6 ,
struct V_72 * V_73 ,
struct V_223 * V_233 )
{
int V_234 ;
switch ( V_73 -> V_167 ) {
case V_231 :
V_234 = ! V_73 -> V_215 ;
if ( ! V_73 -> V_169 [ V_234 ] ) {
V_73 -> V_169 [ V_234 ] = V_233 ;
if ( V_234 )
F_78 ( V_6 , V_73 , 0 ) ;
else
F_77 ( V_6 , V_73 , 0 ) ;
F_81 ( V_6 , V_73 , 3 ) ;
V_73 -> V_167 = V_230 ;
} else {
F_86 ( V_73 , V_233 ) ;
F_92 ( F_63 ( V_6 ) ,
L_7 ) ;
}
break;
case V_235 :
if ( ! V_73 -> V_169 [ 0 ] ) {
V_73 -> V_169 [ 0 ] = V_233 ;
F_76 ( V_6 , V_73 , 1 ) ;
F_81 ( V_6 , V_73 , 1 ) ;
V_73 -> V_167 = V_231 ;
} else {
F_86 ( V_73 , V_233 ) ;
F_92 ( F_63 ( V_6 ) ,
L_8 ) ;
}
break;
case V_230 :
default:
F_86 ( V_73 , V_233 ) ;
break;
}
}
static int F_95 ( struct V_74 * line )
{
struct V_5 * V_6 = F_96 ( line ) ;
struct V_72 * V_73 ;
unsigned long V_236 ;
int V_2 ;
int V_84 ;
F_97 ( & V_6 -> V_237 , V_236 ) ;
V_73 = & line -> V_73 ;
if ( V_73 -> V_167 != V_168 ) {
F_62 ( F_63 ( V_6 ) , L_9 ) ;
goto error;
}
V_73 -> V_167 = V_238 ;
V_73 -> V_215 = 0 ;
for ( V_2 = 0 ; V_2 < V_73 -> V_80 ; V_2 ++ ) {
V_84 = F_79 ( V_6 , line -> V_59 ) ;
if ( V_84 < 0 ) {
F_62 ( F_63 ( V_6 ) , L_10 ) ;
goto V_239;
}
V_73 -> V_84 [ V_2 ] = V_84 ;
}
V_73 -> V_220 = 0 ;
F_98 ( & V_6 -> V_237 , V_236 ) ;
return 0 ;
V_239:
for ( V_2 -- ; V_2 >= 0 ; V_2 -- )
F_80 ( V_6 , V_73 -> V_84 [ V_2 ] ) ;
V_73 -> V_167 = V_168 ;
error:
F_98 ( & V_6 -> V_237 , V_236 ) ;
return - V_217 ;
}
static int F_99 ( struct V_74 * line )
{
struct V_5 * V_6 = F_96 ( line ) ;
struct V_72 * V_73 = & line -> V_73 ;
unsigned long V_236 ;
unsigned int V_2 ;
F_97 ( & V_6 -> V_237 , V_236 ) ;
for ( V_2 = 0 ; V_2 < V_73 -> V_80 ; V_2 ++ )
F_80 ( V_6 , V_73 -> V_84 [ V_2 ] ) ;
V_73 -> V_167 = V_168 ;
F_98 ( & V_6 -> V_237 , V_236 ) ;
return 0 ;
}
static int F_100 ( struct V_74 * line )
{
struct V_5 * V_6 = F_96 ( line ) ;
struct V_72 * V_73 = & line -> V_73 ;
unsigned long V_236 ;
unsigned int V_2 ;
T_4 V_240 ;
switch ( V_6 -> V_59 ) {
case 0 :
V_240 = V_241 ;
break;
case 1 :
V_240 = V_242 ;
break;
default:
return - V_217 ;
}
F_97 ( & V_6 -> V_237 , V_236 ) ;
V_6 -> V_89 &= ~ F_44 ( line -> V_59 ) ;
if ( V_73 -> V_167 != V_238 ) {
F_62 ( F_63 ( V_6 ) , L_11 ,
V_73 -> V_167 ) ;
F_98 ( & V_6 -> V_237 , V_236 ) ;
return - V_217 ;
}
V_73 -> V_167 = V_235 ;
V_73 -> V_169 [ 0 ] = F_82 ( V_73 ) ;
V_73 -> V_169 [ 1 ] = F_82 ( V_73 ) ;
if ( ! V_73 -> V_169 [ 0 ] && V_73 -> V_169 [ 1 ] ) {
V_73 -> V_169 [ 0 ] = V_73 -> V_169 [ 1 ] ;
V_73 -> V_169 [ 1 ] = NULL ;
}
if ( V_73 -> V_169 [ 0 ] )
V_73 -> V_167 = V_231 ;
if ( V_73 -> V_169 [ 1 ] )
V_73 -> V_167 = V_230 ;
switch ( V_73 -> V_167 ) {
case V_231 :
F_81 ( V_6 , V_73 , 1 ) ;
break;
case V_230 :
F_81 ( V_6 , V_73 , 3 ) ;
break;
default:
F_81 ( V_6 , V_73 , 0 ) ;
break;
}
V_73 -> V_243 = 0 ;
V_73 -> V_244 = 0 ;
V_73 -> V_245 = 0 ;
F_59 ( & V_73 -> V_246 ) ;
F_59 ( & V_73 -> V_89 ) ;
F_76 ( V_6 , V_73 , 0 ) ;
if ( line -> V_59 != V_171 ) {
F_69 ( V_6 , V_73 -> V_84 [ 0 ] , 1 ) ;
F_45 ( V_6 , V_73 -> V_84 [ 0 ] , line -> V_59 , 1 ) ;
F_33 ( V_6 , V_73 -> V_84 [ 0 ] , line -> V_59 ) ;
F_37 ( V_6 , V_73 -> V_84 [ 0 ] ) ;
F_42 ( V_6 , line -> V_59 , 0 ) ;
F_22 ( V_6 , V_73 -> V_84 [ 0 ] ,
( V_240 + 1 ) * V_73 -> V_84 [ 0 ] , V_240 ) ;
F_11 ( V_6 , V_73 -> V_84 [ 0 ] , 1 ) ;
F_9 ( V_6 , V_73 -> V_84 [ 0 ] , 1 ) ;
F_24 ( V_6 , V_73 -> V_84 [ 0 ] ) ;
} else {
V_240 /= V_73 -> V_80 ;
for ( V_2 = 0 ; V_2 < V_73 -> V_80 ; V_2 ++ ) {
F_69 ( V_6 , V_73 -> V_84 [ V_2 ] , 1 ) ;
F_37 ( V_6 , V_73 -> V_84 [ V_2 ] ) ;
F_22 ( V_6 , V_73 -> V_84 [ V_2 ] ,
( V_240 + 1 ) * V_73 -> V_84 [ V_2 ] ,
V_240 ) ;
F_15 ( V_6 , V_73 -> V_84 [ V_2 ] ,
& line -> V_76 . V_77 . V_78 . V_79 ,
V_2 , 1 ) ;
F_9 ( V_6 , V_73 -> V_84 [ V_2 ] , 1 ) ;
F_24 ( V_6 , V_73 -> V_84 [ V_2 ] ) ;
}
F_50 ( V_6 , 0 , line -> V_59 , 1 ) ;
F_71 ( V_6 , 1 ) ;
F_72 ( V_6 , line ) ;
F_40 ( V_6 , V_73 , 1 ) ;
F_53 ( V_6 , line ) ;
F_55 ( V_6 , line ) ;
F_56 ( V_6 , line ) ;
F_57 ( V_6 ) ;
F_73 ( V_6 , V_247 ) ;
}
F_43 ( V_6 , line -> V_59 ) ;
F_98 ( & V_6 -> V_237 , V_236 ) ;
return 0 ;
}
static int F_101 ( struct V_74 * line )
{
struct V_5 * V_6 = F_96 ( line ) ;
struct V_72 * V_73 = & line -> V_73 ;
unsigned long V_236 ;
unsigned long time ;
unsigned int V_2 ;
F_97 ( & V_6 -> V_237 , V_236 ) ;
V_73 -> V_244 = 1 ;
F_98 ( & V_6 -> V_237 , V_236 ) ;
time = F_60 ( & V_73 -> V_246 ,
F_61 ( V_248 ) ) ;
if ( ! time )
F_62 ( F_63 ( V_6 ) , L_12 ) ;
F_97 ( & V_6 -> V_237 , V_236 ) ;
for ( V_2 = 0 ; V_2 < V_73 -> V_80 ; V_2 ++ )
F_9 ( V_6 , V_73 -> V_84 [ V_2 ] , 0 ) ;
F_43 ( V_6 , line -> V_59 ) ;
V_73 -> V_245 = 1 ;
F_98 ( & V_6 -> V_237 , V_236 ) ;
time = F_60 ( & V_73 -> V_89 ,
F_61 ( V_248 ) ) ;
if ( ! time )
F_62 ( F_63 ( V_6 ) , L_13 ) ;
F_97 ( & V_6 -> V_237 , V_236 ) ;
if ( line -> V_59 != V_171 ) {
F_11 ( V_6 , V_73 -> V_84 [ 0 ] , 0 ) ;
F_39 ( V_6 , V_73 -> V_84 [ 0 ] , line -> V_59 ) ;
F_45 ( V_6 , V_73 -> V_84 [ 0 ] , line -> V_59 , 0 ) ;
F_69 ( V_6 , V_73 -> V_84 [ 0 ] , 0 ) ;
F_98 ( & V_6 -> V_237 , V_236 ) ;
} else {
for ( V_2 = 0 ; V_2 < V_73 -> V_80 ; V_2 ++ ) {
F_15 ( V_6 , V_73 -> V_84 [ V_2 ] , NULL , V_2 , 0 ) ;
F_69 ( V_6 , V_73 -> V_84 [ V_2 ] , 0 ) ;
}
F_50 ( V_6 , 0 , line -> V_59 , 0 ) ;
F_71 ( V_6 , 0 ) ;
F_40 ( V_6 , V_73 , 0 ) ;
F_73 ( V_6 , V_249 ) ;
F_98 ( & V_6 -> V_237 , V_236 ) ;
F_74 ( V_6 ) ;
}
return 0 ;
}
static int F_102 ( struct V_74 * line )
{
struct V_5 * V_6 = F_96 ( line ) ;
int V_206 ;
F_103 ( & V_6 -> V_250 ) ;
if ( ! V_6 -> V_251 ) {
F_52 ( V_6 ) ;
F_32 ( V_6 , 1 ) ;
F_68 ( V_6 ) ;
}
V_6 -> V_251 ++ ;
F_104 ( & V_6 -> V_250 ) ;
V_206 = F_95 ( line ) ;
if ( V_206 < 0 )
goto V_252;
V_206 = F_100 ( line ) ;
if ( V_206 < 0 )
goto V_253;
V_6 -> V_254 = 1 ;
return 0 ;
V_253:
F_99 ( line ) ;
V_252:
F_103 ( & V_6 -> V_250 ) ;
if ( V_6 -> V_251 == 1 )
F_32 ( V_6 , 0 ) ;
V_6 -> V_251 -- ;
F_104 ( & V_6 -> V_250 ) ;
return V_206 ;
}
static int F_105 ( struct V_74 * line )
{
struct V_5 * V_6 = F_96 ( line ) ;
F_101 ( line ) ;
F_99 ( line ) ;
F_103 ( & V_6 -> V_250 ) ;
if ( V_6 -> V_251 == 1 )
F_32 ( V_6 , 0 ) ;
V_6 -> V_251 -- ;
F_104 ( & V_6 -> V_250 ) ;
return 0 ;
}
static void F_106 ( struct V_5 * V_6 , enum V_58 V_88 )
{
struct V_72 * V_73 ;
unsigned long V_236 ;
F_97 ( & V_6 -> V_237 , V_236 ) ;
V_73 = & V_6 -> line [ V_88 ] . V_73 ;
if ( V_73 -> V_244 ) {
V_73 -> V_244 = 0 ;
F_107 ( & V_73 -> V_246 ) ;
}
F_98 ( & V_6 -> V_237 , V_236 ) ;
}
static void F_108 ( struct V_5 * V_6 , enum V_58 V_88 )
{
struct V_72 * V_73 ;
unsigned long V_236 ;
F_97 ( & V_6 -> V_237 , V_236 ) ;
V_6 -> V_89 &= ~ F_44 ( V_88 ) ;
V_73 = & V_6 -> line [ V_88 ] . V_73 ;
if ( V_73 -> V_245 ) {
V_73 -> V_245 = 0 ;
F_107 ( & V_73 -> V_89 ) ;
F_98 ( & V_6 -> V_237 , V_236 ) ;
return;
}
if ( V_73 -> V_167 == V_232 ) {
if ( V_73 -> V_255 ) {
F_90 ( & V_73 -> V_255 -> V_228 . V_229 ,
V_256 ) ;
V_73 -> V_255 = NULL ;
}
V_73 -> V_167 = V_235 ;
V_73 -> V_169 [ 0 ] = F_82 ( V_73 ) ;
V_73 -> V_169 [ 1 ] = F_82 ( V_73 ) ;
if ( ! V_73 -> V_169 [ 0 ] && V_73 -> V_169 [ 1 ] ) {
V_73 -> V_169 [ 0 ] = V_73 -> V_169 [ 1 ] ;
V_73 -> V_169 [ 1 ] = NULL ;
}
if ( V_73 -> V_169 [ 0 ] )
V_73 -> V_167 = V_231 ;
if ( V_73 -> V_169 [ 1 ] )
V_73 -> V_167 = V_230 ;
switch ( V_73 -> V_167 ) {
case V_231 :
F_81 ( V_6 , V_73 , 2 ) ;
break;
case V_230 :
F_81 ( V_6 , V_73 , 3 ) ;
break;
default:
F_81 ( V_6 , V_73 , 0 ) ;
break;
}
F_76 ( V_6 , V_73 , 1 ) ;
}
F_98 ( & V_6 -> V_237 , V_236 ) ;
}
static void F_109 ( struct V_5 * V_6 , T_1 V_23 )
{
struct V_223 * V_257 ;
struct V_72 * V_73 ;
T_5 * V_258 ;
unsigned long V_236 ;
T_2 V_259 ;
T_6 V_260 = F_110 () ;
unsigned int V_2 ;
V_259 = F_31 ( V_6 , V_23 ) ;
F_97 ( & V_6 -> V_237 , V_236 ) ;
if ( V_6 -> V_172 [ V_23 ] == V_173 ) {
F_92 ( F_63 ( V_6 ) ,
L_14 ) ;
goto V_261;
}
V_73 = & V_6 -> line [ V_6 -> V_172 [ V_23 ] ] . V_73 ;
if ( V_73 -> V_215 == V_259 ) {
F_92 ( F_63 ( V_6 ) ,
L_15 ) ;
goto V_261;
}
V_73 -> V_215 = V_259 ;
V_257 = V_73 -> V_169 [ ! V_259 ] ;
if ( ! V_257 ) {
F_92 ( F_63 ( V_6 ) ,
L_16 ,
! V_259 , V_73 -> V_167 ) ;
goto V_261;
}
V_257 -> V_228 . V_229 . V_262 = V_260 ;
V_257 -> V_228 . V_243 = V_73 -> V_243 ++ ;
V_73 -> V_169 [ ! V_259 ] = F_82 ( V_73 ) ;
if ( ! V_73 -> V_169 [ ! V_259 ] ) {
V_258 = V_257 -> V_55 ;
F_93 ( V_6 , V_73 ) ;
} else {
V_258 = V_73 -> V_169 [ ! V_259 ] -> V_55 ;
F_91 ( V_6 , V_73 ) ;
}
if ( V_259 )
for ( V_2 = 0 ; V_2 < V_73 -> V_80 ; V_2 ++ )
F_27 ( V_6 , V_73 -> V_84 [ V_2 ] ,
V_258 [ V_2 ] ) ;
else
for ( V_2 = 0 ; V_2 < V_73 -> V_80 ; V_2 ++ )
F_29 ( V_6 , V_73 -> V_84 [ V_2 ] ,
V_258 [ V_2 ] ) ;
F_98 ( & V_6 -> V_237 , V_236 ) ;
if ( V_73 -> V_167 == V_232 )
V_73 -> V_255 = V_257 ;
else
F_90 ( & V_257 -> V_228 . V_229 , V_256 ) ;
return;
V_261:
F_98 ( & V_6 -> V_237 , V_236 ) ;
}
static void F_111 ( struct V_5 * V_6 , T_1 V_95 )
{
unsigned int V_2 ;
for ( V_2 = 0 ; V_2 < F_2 ( V_6 -> V_172 ) ; V_2 ++ )
if ( V_6 -> V_172 [ V_2 ] == V_171 ) {
F_109 ( V_6 , V_2 ) ;
break;
}
}
static T_7 F_112 ( int V_263 , void * V_264 )
{
struct V_5 * V_6 = V_264 ;
T_2 V_265 , V_266 ;
T_2 V_267 ;
int V_2 , V_268 ;
V_265 = F_5 ( V_6 -> V_10 + V_269 ) ;
V_266 = F_5 ( V_6 -> V_10 + V_270 ) ;
F_6 ( V_265 , V_6 -> V_10 + V_271 ) ;
F_6 ( V_266 , V_6 -> V_10 + V_272 ) ;
F_25 () ;
F_6 ( V_273 , V_6 -> V_10 + V_274 ) ;
if ( V_265 & V_275 )
F_107 ( & V_6 -> V_160 ) ;
if ( V_266 & V_276 ) {
V_267 = F_5 ( V_6 -> V_10 + V_277 ) ;
F_92 ( F_63 ( V_6 ) ,
L_17 , V_267 ) ;
}
if ( V_266 & V_278 ) {
F_107 ( & V_6 -> V_163 ) ;
F_6 ( 0x0 , V_6 -> V_10 + V_165 ) ;
}
for ( V_2 = V_64 ; V_2 <= V_171 ; V_2 ++ )
if ( V_265 & F_113 ( V_2 ) )
F_108 ( V_6 , V_2 ) ;
if ( V_265 & V_279 )
F_106 ( V_6 , V_171 ) ;
for ( V_2 = V_64 ; V_2 <= V_69 ; V_2 ++ )
if ( V_266 & F_114 ( V_2 ) )
F_106 ( V_6 , V_2 ) ;
for ( V_2 = 0 ; V_2 < V_280 ; V_2 ++ )
if ( V_265 & F_115 ( V_2 ) ) {
F_111 ( V_6 , V_2 ) ;
for ( V_268 = 0 ; V_268 < F_2 ( V_6 -> V_172 ) ; V_268 ++ )
if ( V_6 -> V_172 [ V_268 ] == V_171 )
V_265 &= ~ F_46 ( V_268 ) ;
}
for ( V_2 = 0 ; V_2 < V_281 ; V_2 ++ )
if ( V_265 & F_116 ( V_2 ) )
F_109 ( V_6 , V_2 ) ;
return V_282 ;
}
static int F_117 ( struct V_5 * V_6 )
{
struct V_283 * V_264 = F_63 ( V_6 ) ;
T_2 V_284 [ V_285 ] ;
int V_2 , V_268 ;
int V_206 ;
for ( V_2 = V_64 ; V_2 <= V_171 ; V_2 ++ ) {
V_206 = F_118 ( & V_6 -> line [ V_2 ] . V_286 . V_287 ,
& V_284 [ V_2 ] ) ;
if ( V_206 )
V_284 [ V_2 ] = 0 ;
}
for ( V_2 = 0 ; V_2 < V_6 -> V_288 ; V_2 ++ ) {
struct V_289 * clock = & V_6 -> clock [ V_2 ] ;
if ( ! strcmp ( clock -> V_290 , L_18 ) ) {
T_6 V_291 = 0 ;
long V_292 ;
for ( V_268 = V_64 ; V_268 <= V_171 ; V_268 ++ ) {
T_2 V_293 ;
T_1 V_4 ;
if ( V_268 == V_171 ) {
V_293 = V_284 [ V_268 ] ;
} else {
V_4 = F_1 ( V_6 -> line [ V_268 ] .
V_78 [ V_114 ] . V_1 ) ;
V_293 = V_284 [ V_268 ] * V_4 / 64 ;
}
if ( V_291 < V_293 )
V_291 = V_293 ;
}
F_119 ( & V_291 ) ;
for ( V_268 = 0 ; V_268 < clock -> V_294 ; V_268 ++ )
if ( V_291 < clock -> V_295 [ V_268 ] )
break;
if ( V_268 == clock -> V_294 ) {
F_62 ( V_264 ,
L_19 ) ;
return - V_217 ;
}
if ( V_291 == 0 )
V_268 = clock -> V_294 - 1 ;
V_292 = F_120 ( clock -> V_296 , clock -> V_295 [ V_268 ] ) ;
if ( V_292 < 0 ) {
F_62 ( V_264 , L_20 ,
V_292 ) ;
return - V_217 ;
}
V_206 = F_121 ( clock -> V_296 , V_292 ) ;
if ( V_206 < 0 ) {
F_62 ( V_264 , L_21 , V_206 ) ;
return V_206 ;
}
}
}
return 0 ;
}
static int F_122 ( struct V_5 * V_6 )
{
T_2 V_284 [ V_285 ] ;
int V_2 , V_268 ;
int V_206 ;
for ( V_2 = V_64 ; V_2 <= V_171 ; V_2 ++ ) {
V_206 = F_118 ( & V_6 -> line [ V_2 ] . V_286 . V_287 ,
& V_284 [ V_2 ] ) ;
if ( V_206 )
V_284 [ V_2 ] = 0 ;
}
for ( V_2 = 0 ; V_2 < V_6 -> V_288 ; V_2 ++ ) {
struct V_289 * clock = & V_6 -> clock [ V_2 ] ;
if ( ! strcmp ( clock -> V_290 , L_18 ) ) {
T_6 V_291 = 0 ;
unsigned long V_292 ;
for ( V_268 = V_64 ; V_268 <= V_171 ; V_268 ++ ) {
T_2 V_293 ;
T_1 V_4 ;
if ( V_268 == V_171 ) {
V_293 = V_284 [ V_268 ] ;
} else {
V_4 = F_1 ( V_6 -> line [ V_268 ] .
V_78 [ V_114 ] . V_1 ) ;
V_293 = V_284 [ V_268 ] * V_4 / 64 ;
}
if ( V_291 < V_293 )
V_291 = V_293 ;
}
F_119 ( & V_291 ) ;
V_292 = F_123 ( clock -> V_296 ) ;
if ( V_292 < V_291 )
return - V_216 ;
}
}
return 0 ;
}
static int F_124 ( struct V_5 * V_6 )
{
int V_206 ;
F_103 ( & V_6 -> V_297 ) ;
if ( V_6 -> V_298 == 0 ) {
V_206 = F_117 ( V_6 ) ;
if ( V_206 < 0 )
goto V_299;
V_206 = F_125 ( V_6 -> V_288 , V_6 -> clock ,
F_63 ( V_6 ) ) ;
if ( V_206 < 0 )
goto V_299;
V_206 = F_58 ( V_6 ) ;
if ( V_206 < 0 )
goto V_300;
F_67 ( V_6 ) ;
F_65 ( V_6 ) ;
} else {
V_206 = F_122 ( V_6 ) ;
if ( V_206 < 0 )
goto V_299;
}
V_6 -> V_298 ++ ;
F_104 ( & V_6 -> V_297 ) ;
return 0 ;
V_300:
F_126 ( V_6 -> V_288 , V_6 -> clock ) ;
V_299:
F_104 ( & V_6 -> V_297 ) ;
return V_206 ;
}
static void F_127 ( struct V_5 * V_6 )
{
F_103 ( & V_6 -> V_297 ) ;
if ( V_6 -> V_298 == 0 ) {
F_62 ( F_63 ( V_6 ) , L_22 ) ;
goto exit;
} else if ( V_6 -> V_298 == 1 ) {
if ( V_6 -> V_254 ) {
V_6 -> V_254 = 0 ;
F_64 ( V_6 ) ;
}
F_126 ( V_6 -> V_288 , V_6 -> clock ) ;
}
V_6 -> V_298 -- ;
exit:
F_104 ( & V_6 -> V_297 ) ;
}
static struct V_74 * F_128 ( struct V_301 * V_302 )
{
struct V_301 * V_303 ;
struct V_304 * V_286 ;
V_303 = F_129 ( V_302 ) ;
if ( V_303 == NULL )
return NULL ;
V_286 = F_130 ( V_303 -> V_287 ) ;
return F_41 ( V_286 , struct V_74 , V_286 ) ;
}
static int F_131 ( struct V_305 * V_306 ,
struct V_223 * V_169 )
{
struct V_5 * V_6 = & V_306 -> V_307 -> V_6 ;
struct V_74 * line ;
struct V_72 * V_73 ;
unsigned long V_236 ;
line = F_128 ( & V_306 -> V_302 ) ;
if ( ! line ) {
F_62 ( F_63 ( V_6 ) , L_23 ) ;
return - 1 ;
}
V_73 = & line -> V_73 ;
F_97 ( & V_6 -> V_237 , V_236 ) ;
F_94 ( V_6 , V_73 , V_169 ) ;
F_98 ( & V_6 -> V_237 , V_236 ) ;
return 0 ;
}
static int F_132 ( struct V_305 * V_306 ,
enum V_226 V_167 )
{
struct V_5 * V_6 = & V_306 -> V_307 -> V_6 ;
struct V_74 * line ;
struct V_72 * V_73 ;
unsigned long V_236 ;
line = F_128 ( & V_306 -> V_302 ) ;
if ( ! line ) {
F_62 ( F_63 ( V_6 ) , L_24 ) ;
return - 1 ;
}
V_73 = & line -> V_73 ;
F_97 ( & V_6 -> V_237 , V_236 ) ;
F_88 ( V_73 , V_167 ) ;
if ( V_73 -> V_169 [ 0 ] )
F_90 ( & V_73 -> V_169 [ 0 ] -> V_228 . V_229 , V_167 ) ;
if ( V_73 -> V_169 [ 1 ] )
F_90 ( & V_73 -> V_169 [ 1 ] -> V_228 . V_229 , V_167 ) ;
if ( V_73 -> V_255 ) {
F_90 ( & V_73 -> V_255 -> V_228 . V_229 , V_167 ) ;
V_73 -> V_255 = NULL ;
}
F_98 ( & V_6 -> V_237 , V_236 ) ;
return 0 ;
}
static int F_133 ( struct V_304 * V_308 , int V_309 )
{
struct V_74 * line = F_134 ( V_308 ) ;
struct V_5 * V_6 = F_96 ( line ) ;
int V_206 ;
if ( V_309 ) {
T_2 V_310 ;
V_206 = F_124 ( V_6 ) ;
if ( V_206 < 0 )
return V_206 ;
V_310 = F_5 ( V_6 -> V_10 + V_311 ) ;
F_135 ( F_63 ( V_6 ) ,
L_25 , V_310 ) ;
} else {
F_127 ( V_6 ) ;
}
return 0 ;
}
static int F_136 ( struct V_304 * V_308 , int V_24 )
{
struct V_74 * line = F_134 ( V_308 ) ;
struct V_5 * V_6 = F_96 ( line ) ;
int V_206 ;
if ( V_24 ) {
V_206 = F_102 ( line ) ;
if ( V_206 < 0 )
F_62 ( F_63 ( V_6 ) ,
L_26 ) ;
} else {
V_206 = F_105 ( line ) ;
if ( V_206 < 0 )
F_62 ( F_63 ( V_6 ) ,
L_27 ) ;
}
return V_206 ;
}
static struct V_312 *
F_137 ( struct V_74 * line ,
struct V_313 * V_314 ,
unsigned int V_302 ,
enum V_315 V_316 )
{
if ( V_316 == V_317 )
return F_138 ( & line -> V_286 , V_314 , V_302 ) ;
return & line -> V_78 [ V_302 ] ;
}
static struct V_318 *
F_139 ( struct V_74 * line ,
struct V_313 * V_314 ,
enum V_315 V_316 )
{
if ( V_316 == V_317 )
return F_140 ( & line -> V_286 , V_314 ,
V_114 ) ;
return & line -> V_133 ;
}
static struct V_318 *
F_141 ( struct V_74 * line ,
struct V_313 * V_314 ,
enum V_315 V_316 )
{
if ( V_316 == V_317 )
return F_142 ( & line -> V_286 , V_314 ,
V_319 ) ;
return & line -> V_145 ;
}
static void F_143 ( struct V_74 * line ,
struct V_313 * V_314 ,
unsigned int V_302 ,
struct V_312 * V_78 ,
enum V_315 V_316 )
{
unsigned int V_2 ;
T_2 V_1 ;
switch ( V_302 ) {
case V_114 :
for ( V_2 = 0 ; V_2 < F_2 ( V_3 ) ; V_2 ++ )
if ( V_78 -> V_1 == V_3 [ V_2 ] . V_1 )
break;
if ( V_2 >= F_2 ( V_3 ) )
V_78 -> V_1 = V_121 ;
V_78 -> V_41 = F_144 ( T_2 , V_78 -> V_41 , 1 , 8191 ) ;
V_78 -> V_42 = F_144 ( T_2 , V_78 -> V_42 , 1 , 8191 ) ;
V_78 -> V_320 = V_321 ;
V_78 -> V_322 = V_323 ;
break;
case V_319 :
V_1 = V_78 -> V_1 ;
* V_78 = * F_137 ( line , V_314 , V_114 ,
V_316 ) ;
if ( line -> V_59 == V_171 ) {
struct V_318 * V_324 ;
V_324 = F_141 ( line , V_314 , V_316 ) ;
V_78 -> V_41 = V_324 -> V_41 ;
V_78 -> V_42 = V_324 -> V_42 ;
switch ( V_78 -> V_1 ) {
case V_115 :
if ( V_1 == V_325 )
V_78 -> V_1 = V_325 ;
else
V_78 -> V_1 = V_115 ;
break;
case V_118 :
if ( V_1 == V_326 )
V_78 -> V_1 = V_326 ;
else
V_78 -> V_1 = V_118 ;
break;
case V_121 :
default:
if ( V_1 == V_327 )
V_78 -> V_1 = V_327 ;
else
V_78 -> V_1 = V_121 ;
break;
case V_124 :
if ( V_1 == V_328 )
V_78 -> V_1 = V_328 ;
else
V_78 -> V_1 = V_124 ;
break;
}
}
break;
}
V_78 -> V_322 = V_323 ;
}
static void F_145 ( struct V_74 * line ,
struct V_313 * V_314 ,
struct V_318 * V_324 ,
enum V_315 V_316 )
{
struct V_312 * V_78 ;
V_78 = F_137 ( line , V_314 , V_114 , V_316 ) ;
if ( V_324 -> V_41 > V_78 -> V_41 )
V_324 -> V_41 = V_78 -> V_41 ;
if ( V_324 -> V_42 > V_78 -> V_42 )
V_324 -> V_42 = V_78 -> V_42 ;
if ( V_78 -> V_41 > V_324 -> V_41 * V_329 )
V_324 -> V_41 = ( V_78 -> V_41 + V_329 - 1 ) /
V_329 ;
V_324 -> V_41 &= ~ 0x1 ;
if ( V_78 -> V_42 > V_324 -> V_42 * V_329 )
V_324 -> V_42 = ( V_78 -> V_42 + V_329 - 1 ) /
V_329 ;
if ( V_324 -> V_41 < 16 )
V_324 -> V_41 = 16 ;
if ( V_324 -> V_42 < 4 )
V_324 -> V_42 = 4 ;
}
static void F_146 ( struct V_74 * line ,
struct V_313 * V_314 ,
struct V_318 * V_324 ,
enum V_315 V_316 )
{
struct V_318 * V_133 ;
V_133 = F_139 ( line , V_314 , V_316 ) ;
if ( V_324 -> V_41 > V_133 -> V_41 )
V_324 -> V_41 = V_133 -> V_41 ;
if ( V_324 -> V_41 + V_324 -> V_146 > V_133 -> V_41 )
V_324 -> V_146 = V_133 -> V_41 - V_324 -> V_41 ;
if ( V_324 -> V_42 > V_133 -> V_42 )
V_324 -> V_42 = V_133 -> V_42 ;
if ( V_324 -> V_42 + V_324 -> V_148 > V_133 -> V_42 )
V_324 -> V_148 = V_133 -> V_42 - V_324 -> V_42 ;
V_324 -> V_146 += ( V_324 -> V_41 & 0xf ) >> 1 ;
V_324 -> V_41 &= ~ 0xf ;
if ( V_324 -> V_41 < 16 ) {
V_324 -> V_146 = 0 ;
V_324 -> V_41 = 16 ;
}
if ( V_324 -> V_42 < 4 ) {
V_324 -> V_148 = 0 ;
V_324 -> V_42 = 4 ;
}
}
static int F_147 ( struct V_304 * V_308 ,
struct V_313 * V_314 ,
struct V_330 * V_1 )
{
struct V_74 * line = F_134 ( V_308 ) ;
struct V_312 * V_27 ;
if ( V_1 -> V_302 == V_114 ) {
if ( V_1 -> V_331 >= F_2 ( V_3 ) )
return - V_217 ;
V_1 -> V_1 = V_3 [ V_1 -> V_331 ] . V_1 ;
} else {
if ( V_1 -> V_331 > 0 )
return - V_217 ;
V_27 = F_137 ( line , V_314 , V_114 ,
V_1 -> V_316 ) ;
V_1 -> V_1 = V_27 -> V_1 ;
}
return 0 ;
}
static int F_148 ( struct V_304 * V_308 ,
struct V_313 * V_314 ,
struct V_332 * V_333 )
{
struct V_74 * line = F_134 ( V_308 ) ;
struct V_312 V_27 ;
if ( V_333 -> V_331 != 0 )
return - V_217 ;
V_27 . V_1 = V_333 -> V_1 ;
V_27 . V_41 = 1 ;
V_27 . V_42 = 1 ;
F_143 ( line , V_314 , V_333 -> V_302 , & V_27 , V_333 -> V_316 ) ;
V_333 -> V_334 = V_27 . V_41 ;
V_333 -> V_335 = V_27 . V_42 ;
if ( V_27 . V_1 != V_333 -> V_1 )
return - V_217 ;
V_27 . V_1 = V_333 -> V_1 ;
V_27 . V_41 = - 1 ;
V_27 . V_42 = - 1 ;
F_143 ( line , V_314 , V_333 -> V_302 , & V_27 , V_333 -> V_316 ) ;
V_333 -> V_336 = V_27 . V_41 ;
V_333 -> V_337 = V_27 . V_42 ;
return 0 ;
}
static int F_149 ( struct V_304 * V_308 ,
struct V_313 * V_314 ,
struct V_338 * V_78 )
{
struct V_74 * line = F_134 ( V_308 ) ;
struct V_312 * V_27 ;
V_27 = F_137 ( line , V_314 , V_78 -> V_302 , V_78 -> V_316 ) ;
if ( V_27 == NULL )
return - V_217 ;
V_78 -> V_27 = * V_27 ;
return 0 ;
}
static int F_150 ( struct V_304 * V_308 ,
struct V_313 * V_314 ,
struct V_338 * V_78 )
{
struct V_74 * line = F_134 ( V_308 ) ;
struct V_312 * V_27 ;
V_27 = F_137 ( line , V_314 , V_78 -> V_302 , V_78 -> V_316 ) ;
if ( V_27 == NULL )
return - V_217 ;
F_143 ( line , V_314 , V_78 -> V_302 , & V_78 -> V_27 , V_78 -> V_316 ) ;
* V_27 = V_78 -> V_27 ;
if ( V_78 -> V_302 == V_114 ) {
struct V_339 V_340 = { 0 } ;
int V_206 ;
V_27 = F_137 ( line , V_314 , V_319 ,
V_78 -> V_316 ) ;
* V_27 = V_78 -> V_27 ;
F_143 ( line , V_314 , V_319 , V_27 ,
V_78 -> V_316 ) ;
if ( line -> V_59 != V_171 )
return 0 ;
V_340 . V_316 = V_78 -> V_316 ;
V_340 . V_302 = V_114 ;
V_340 . V_341 = V_342 ;
V_340 . V_343 . V_41 = V_78 -> V_27 . V_41 ;
V_340 . V_343 . V_42 = V_78 -> V_27 . V_42 ;
V_206 = F_151 ( V_308 , V_314 , & V_340 ) ;
if ( V_206 < 0 )
return V_206 ;
}
return 0 ;
}
static int F_152 ( struct V_304 * V_308 ,
struct V_313 * V_314 ,
struct V_339 * V_340 )
{
struct V_74 * line = F_134 ( V_308 ) ;
struct V_338 V_78 = { 0 } ;
struct V_318 * V_324 ;
int V_206 ;
if ( line -> V_59 != V_171 )
return - V_217 ;
if ( V_340 -> V_302 == V_114 )
switch ( V_340 -> V_341 ) {
case V_344 :
V_78 . V_302 = V_340 -> V_302 ;
V_78 . V_316 = V_340 -> V_316 ;
V_206 = F_149 ( V_308 , V_314 , & V_78 ) ;
if ( V_206 < 0 )
return V_206 ;
V_340 -> V_343 . V_146 = 0 ;
V_340 -> V_343 . V_148 = 0 ;
V_340 -> V_343 . V_41 = V_78 . V_27 . V_41 ;
V_340 -> V_343 . V_42 = V_78 . V_27 . V_42 ;
break;
case V_342 :
V_324 = F_139 ( line , V_314 , V_340 -> V_316 ) ;
if ( V_324 == NULL )
return - V_217 ;
V_340 -> V_343 = * V_324 ;
break;
default:
return - V_217 ;
}
else if ( V_340 -> V_302 == V_319 )
switch ( V_340 -> V_341 ) {
case V_345 :
V_324 = F_139 ( line , V_314 , V_340 -> V_316 ) ;
if ( V_324 == NULL )
return - V_217 ;
V_340 -> V_343 . V_146 = V_324 -> V_146 ;
V_340 -> V_343 . V_148 = V_324 -> V_148 ;
V_340 -> V_343 . V_41 = V_324 -> V_41 ;
V_340 -> V_343 . V_42 = V_324 -> V_42 ;
break;
case V_346 :
V_324 = F_141 ( line , V_314 , V_340 -> V_316 ) ;
if ( V_324 == NULL )
return - V_217 ;
V_340 -> V_343 = * V_324 ;
break;
default:
return - V_217 ;
}
return 0 ;
}
static int F_151 ( struct V_304 * V_308 ,
struct V_313 * V_314 ,
struct V_339 * V_340 )
{
struct V_74 * line = F_134 ( V_308 ) ;
struct V_318 * V_324 ;
int V_206 ;
if ( line -> V_59 != V_171 )
return - V_217 ;
if ( V_340 -> V_341 == V_342 &&
V_340 -> V_302 == V_114 ) {
struct V_339 V_145 = { 0 } ;
V_324 = F_139 ( line , V_314 , V_340 -> V_316 ) ;
if ( V_324 == NULL )
return - V_217 ;
F_145 ( line , V_314 , & V_340 -> V_343 , V_340 -> V_316 ) ;
* V_324 = V_340 -> V_343 ;
V_145 . V_316 = V_340 -> V_316 ;
V_145 . V_302 = V_319 ;
V_145 . V_341 = V_346 ;
V_145 . V_343 = * V_324 ;
V_206 = F_151 ( V_308 , V_314 , & V_145 ) ;
} else if ( V_340 -> V_341 == V_346 &&
V_340 -> V_302 == V_319 ) {
struct V_338 V_78 = { 0 } ;
V_324 = F_141 ( line , V_314 , V_340 -> V_316 ) ;
if ( V_324 == NULL )
return - V_217 ;
F_146 ( line , V_314 , & V_340 -> V_343 , V_340 -> V_316 ) ;
* V_324 = V_340 -> V_343 ;
V_78 . V_316 = V_340 -> V_316 ;
V_78 . V_302 = V_319 ;
V_206 = F_149 ( V_308 , V_314 , & V_78 ) ;
if ( V_206 < 0 )
return V_206 ;
V_78 . V_27 . V_41 = V_324 -> V_41 ;
V_78 . V_27 . V_42 = V_324 -> V_42 ;
V_206 = F_150 ( V_308 , V_314 , & V_78 ) ;
} else {
V_206 = - V_217 ;
}
return V_206 ;
}
static int F_153 ( struct V_304 * V_308 , struct V_347 * V_348 )
{
struct V_338 V_27 = {
. V_302 = V_114 ,
. V_316 = V_348 ? V_317 :
V_349 ,
. V_27 = {
. V_1 = V_121 ,
. V_41 = 1920 ,
. V_42 = 1080
}
} ;
return F_150 ( V_308 , V_348 ? V_348 -> V_302 : NULL , & V_27 ) ;
}
int F_154 ( struct V_5 * V_6 , const struct V_350 * V_351 )
{
struct V_283 * V_264 = F_63 ( V_6 ) ;
struct V_352 * V_353 = F_155 ( V_264 ) ;
struct V_354 * V_343 ;
struct V_307 * V_307 = F_156 ( V_6 ) ;
int V_2 , V_268 ;
int V_206 ;
V_343 = F_157 ( V_353 , V_355 , V_351 -> V_7 [ 0 ] ) ;
V_6 -> V_10 = F_158 ( V_264 , V_343 ) ;
if ( F_159 ( V_6 -> V_10 ) ) {
F_62 ( V_264 , L_28 ) ;
return F_160 ( V_6 -> V_10 ) ;
}
V_343 = F_157 ( V_353 , V_356 ,
V_351 -> V_357 [ 0 ] ) ;
if ( ! V_343 ) {
F_62 ( V_264 , L_29 ) ;
return - V_217 ;
}
V_6 -> V_263 = V_343 -> V_358 ;
snprintf ( V_6 -> V_359 , sizeof( V_6 -> V_359 ) , L_30 ,
F_161 ( V_264 ) , V_360 , V_6 -> V_59 ) ;
V_206 = F_162 ( V_264 , V_6 -> V_263 , F_112 ,
V_361 , V_6 -> V_359 , V_6 ) ;
if ( V_206 < 0 ) {
F_62 ( V_264 , L_31 , V_206 ) ;
return V_206 ;
}
V_6 -> V_288 = 0 ;
while ( V_351 -> clock [ V_6 -> V_288 ] )
V_6 -> V_288 ++ ;
V_6 -> clock = F_163 ( V_264 , V_6 -> V_288 * sizeof( * V_6 -> clock ) ,
V_362 ) ;
if ( ! V_6 -> clock )
return - V_363 ;
for ( V_2 = 0 ; V_2 < V_6 -> V_288 ; V_2 ++ ) {
struct V_289 * clock = & V_6 -> clock [ V_2 ] ;
clock -> V_296 = F_164 ( V_264 , V_351 -> clock [ V_2 ] ) ;
if ( F_159 ( clock -> V_296 ) )
return F_160 ( clock -> V_296 ) ;
clock -> V_290 = V_351 -> clock [ V_2 ] ;
clock -> V_294 = 0 ;
while ( V_351 -> V_364 [ V_2 ] [ clock -> V_294 ] )
clock -> V_294 ++ ;
if ( ! clock -> V_294 ) {
clock -> V_295 = NULL ;
continue;
}
clock -> V_295 = F_163 ( V_264 , clock -> V_294 *
sizeof( * clock -> V_295 ) , V_362 ) ;
if ( ! clock -> V_295 )
return - V_363 ;
for ( V_268 = 0 ; V_268 < clock -> V_294 ; V_268 ++ )
clock -> V_295 [ V_268 ] = V_351 -> V_364 [ V_2 ] [ V_268 ] ;
}
F_165 ( & V_6 -> V_297 ) ;
V_6 -> V_298 = 0 ;
F_165 ( & V_6 -> V_250 ) ;
V_6 -> V_251 = 0 ;
F_166 ( & V_6 -> V_237 ) ;
V_6 -> V_59 = 0 ;
V_6 -> V_89 = 0 ;
for ( V_2 = V_64 ; V_2 <= V_171 ; V_2 ++ ) {
V_6 -> line [ V_2 ] . V_76 . type =
V_365 ;
V_6 -> line [ V_2 ] . V_76 . V_307 = V_307 ;
V_6 -> line [ V_2 ] . V_59 = V_2 ;
F_167 ( & V_6 -> line [ V_2 ] . V_73 . V_246 ) ;
F_167 ( & V_6 -> line [ V_2 ] . V_73 . V_89 ) ;
}
F_167 ( & V_6 -> V_160 ) ;
F_167 ( & V_6 -> V_163 ) ;
return 0 ;
}
void F_168 ( struct V_366 * V_287 , T_1 * V_59 )
{
struct V_304 * V_308 ;
struct V_74 * line ;
struct V_5 * V_6 ;
V_308 = F_130 ( V_287 ) ;
line = F_134 ( V_308 ) ;
V_6 = F_96 ( line ) ;
* V_59 = V_6 -> V_59 ;
}
void F_169 ( struct V_366 * V_287 , enum V_58 * V_59 )
{
struct V_304 * V_308 ;
struct V_74 * line ;
V_308 = F_130 ( V_287 ) ;
line = F_134 ( V_308 ) ;
* V_59 = line -> V_59 ;
}
static int F_170 ( struct V_366 * V_287 ,
const struct V_301 * V_367 ,
const struct V_301 * V_368 , T_2 V_236 )
{
if ( V_236 & V_369 )
if ( F_129 ( V_367 ) )
return - V_216 ;
return 0 ;
}
void F_171 ( struct V_5 * V_6 )
{
int V_2 ;
for ( V_2 = 0 ; V_2 < F_2 ( V_6 -> line ) ; V_2 ++ )
F_172 ( & V_6 -> line [ V_2 ] . V_76 ) ;
}
int F_173 ( struct V_5 * V_6 ,
struct V_370 * V_371 )
{
struct V_283 * V_264 = F_63 ( V_6 ) ;
struct V_304 * V_308 ;
struct V_301 * V_372 ;
struct V_305 * V_76 ;
int V_206 ;
int V_2 ;
for ( V_2 = 0 ; V_2 < F_2 ( V_6 -> line ) ; V_2 ++ ) {
char V_290 [ 32 ] ;
V_308 = & V_6 -> line [ V_2 ] . V_286 ;
V_372 = V_6 -> line [ V_2 ] . V_372 ;
V_76 = & V_6 -> line [ V_2 ] . V_76 ;
F_174 ( V_308 , & V_373 ) ;
V_308 -> V_374 = & V_375 ;
V_308 -> V_236 |= V_376 ;
if ( V_2 == V_171 )
snprintf ( V_308 -> V_290 , F_2 ( V_308 -> V_290 ) , L_32 ,
V_360 , V_6 -> V_59 , L_33 ) ;
else
snprintf ( V_308 -> V_290 , F_2 ( V_308 -> V_290 ) , L_34 ,
V_360 , V_6 -> V_59 , L_35 , V_2 ) ;
F_175 ( V_308 , & V_6 -> line [ V_2 ] ) ;
V_206 = F_153 ( V_308 , NULL ) ;
if ( V_206 < 0 ) {
F_62 ( V_264 , L_36 , V_206 ) ;
goto V_377;
}
V_372 [ V_114 ] . V_236 = V_378 ;
V_372 [ V_319 ] . V_236 = V_379 ;
V_308 -> V_287 . V_380 = V_381 ;
V_308 -> V_287 . V_382 = & V_383 ;
V_206 = F_176 ( & V_308 -> V_287 , V_384 ,
V_372 ) ;
if ( V_206 < 0 ) {
F_62 ( V_264 , L_37 , V_206 ) ;
goto V_377;
}
V_206 = F_177 ( V_371 , V_308 ) ;
if ( V_206 < 0 ) {
F_62 ( V_264 , L_38 , V_206 ) ;
goto V_385;
}
V_76 -> V_382 = & V_386 ;
V_76 -> V_387 = 8 ;
V_76 -> V_388 = 0 ;
if ( V_2 == V_171 ) {
V_76 -> V_387 = 16 ;
V_76 -> V_388 = 1 ;
}
snprintf ( V_290 , F_2 ( V_290 ) , L_34 ,
V_360 , V_6 -> V_59 , L_39 , V_2 ) ;
V_206 = F_178 ( V_76 , V_371 , V_290 ,
V_2 == V_171 ? 1 : 0 ) ;
if ( V_206 < 0 ) {
F_62 ( V_264 , L_40 ,
V_206 ) ;
goto V_389;
}
V_206 = F_179 (
& V_308 -> V_287 , V_319 ,
& V_76 -> V_390 . V_287 , 0 ,
V_391 | V_369 ) ;
if ( V_206 < 0 ) {
F_62 ( V_264 , L_41 ,
V_308 -> V_287 . V_290 , V_76 -> V_390 . V_287 . V_290 ,
V_206 ) ;
goto V_392;
}
}
return 0 ;
V_392:
F_180 ( V_76 ) ;
V_389:
F_181 ( V_308 ) ;
V_385:
F_182 ( & V_308 -> V_287 ) ;
V_377:
for ( V_2 -- ; V_2 >= 0 ; V_2 -- ) {
V_308 = & V_6 -> line [ V_2 ] . V_286 ;
V_76 = & V_6 -> line [ V_2 ] . V_76 ;
F_180 ( V_76 ) ;
F_181 ( V_308 ) ;
F_182 ( & V_308 -> V_287 ) ;
}
return V_206 ;
}
void F_183 ( struct V_5 * V_6 )
{
int V_2 ;
F_184 ( & V_6 -> V_297 ) ;
F_184 ( & V_6 -> V_250 ) ;
for ( V_2 = 0 ; V_2 < F_2 ( V_6 -> line ) ; V_2 ++ ) {
struct V_304 * V_308 = & V_6 -> line [ V_2 ] . V_286 ;
struct V_305 * V_76 = & V_6 -> line [ V_2 ] . V_76 ;
F_180 ( V_76 ) ;
F_181 ( V_308 ) ;
F_182 ( & V_308 -> V_287 ) ;
}
}
