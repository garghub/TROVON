static T_1 F_1 ( T_1 V_1 )
{
T_1 V_2 ;
for ( V_2 = 0 ; V_2 <= 31 ; V_2 ++ ) {
if ( ( ( V_1 >> V_2 ) & 0x1 ) == 1 )
break;
}
return V_2 ;
}
T_1
F_2 (
struct V_3 * V_4 ,
T_1 V_5 ,
T_1 V_1
)
{
T_1 V_6 = 0 , V_7 , V_8 ;
V_7 = F_3 ( V_4 , V_5 ) ;
V_8 = F_1 ( V_1 ) ;
V_6 = ( V_7 & V_1 ) >> V_8 ;
return V_6 ;
}
void F_4 ( struct V_3 * V_4 , T_1 V_5 , T_1 V_1 , T_1 V_9 )
{
T_1 V_7 , V_8 ;
if ( V_1 != V_10 ) {
V_7 = F_3 ( V_4 , V_5 ) ;
V_8 = F_1 ( V_1 ) ;
V_9 = ( ( V_7 & ( ~ V_1 ) ) | ( V_9 << V_8 ) ) ;
}
F_5 ( V_4 , V_5 , V_9 ) ;
}
static T_1
F_6 (
struct V_3 * V_4 ,
enum V_11 V_12 ,
T_1 V_13
)
{
T_1 V_14 = 0 ;
struct V_15 * V_16 = F_7 ( V_4 ) ;
struct V_17 * V_18 = & V_16 -> V_19 [ V_12 ] ;
T_1 V_20 ;
T_1 V_21 , V_22 ;
T_2 V_23 = 0 ;
V_13 &= 0xff ;
V_20 = V_13 ;
V_21 = F_8 ( V_4 , V_24 , V_10 ) ;
if ( V_12 == V_25 )
V_22 = V_21 ;
else
V_22 = F_8 ( V_4 , V_18 -> V_26 , V_10 ) ;
V_22 = ( V_22 & ( ~ V_27 ) ) | ( V_20 << 23 ) | V_28 ;
F_9 ( V_4 , V_24 , V_10 , V_21 & ( ~ V_28 ) ) ;
F_10 ( 10 ) ;
F_9 ( V_4 , V_18 -> V_26 , V_10 , V_22 ) ;
F_10 ( 100 ) ;
F_10 ( 10 ) ;
if ( V_12 == V_25 )
V_23 = ( T_2 ) F_8 ( V_4 , V_29 , V_30 ) ;
else if ( V_12 == V_31 )
V_23 = ( T_2 ) F_8 ( V_4 , V_32 , V_30 ) ;
if ( V_23 ) {
V_14 = F_8 ( V_4 , V_18 -> V_33 , V_34 ) ;
} else {
V_14 = F_8 ( V_4 , V_18 -> V_35 , V_34 ) ;
}
return V_14 ;
}
static void
F_11 (
struct V_3 * V_4 ,
enum V_11 V_12 ,
T_1 V_13 ,
T_1 V_9
)
{
T_1 V_36 = 0 ;
struct V_15 * V_16 = F_7 ( V_4 ) ;
struct V_17 * V_18 = & V_16 -> V_19 [ V_12 ] ;
T_1 V_20 ;
V_13 &= 0xff ;
V_20 = V_13 ;
V_36 = ( ( V_20 << 20 ) | ( V_9 & 0x000fffff ) ) & 0x0fffffff ;
F_9 ( V_4 , V_18 -> V_37 , V_10 , V_36 ) ;
}
T_1 F_12 ( struct V_3 * V_4 , enum V_11 V_12 ,
T_1 V_5 , T_1 V_1 )
{
T_1 V_38 , V_39 , V_8 ;
V_38 = F_6 ( V_4 , V_12 , V_5 ) ;
V_8 = F_1 ( V_1 ) ;
V_39 = ( V_38 & V_1 ) >> V_8 ;
return V_39 ;
}
void
F_13 (
struct V_3 * V_4 ,
enum V_11 V_12 ,
T_1 V_5 ,
T_1 V_1 ,
T_1 V_9
)
{
T_1 V_38 , V_8 ;
if ( V_1 != V_40 ) {
V_38 = F_6 ( V_4 , V_12 , V_5 ) ;
V_8 = F_1 ( V_1 ) ;
V_9 = ( ( V_38 & ( ~ V_1 ) ) | ( V_9 << V_8 ) ) ;
}
F_11 ( V_4 , V_12 , V_5 , V_9 ) ;
}
T_3 F_14 ( struct V_3 * V_4 )
{
struct V_15 * V_16 = F_7 ( V_4 ) ;
int V_41 = V_42 ;
if ( V_43 == F_15 ( & V_16 -> V_44 ) )
V_41 = V_45 ;
F_16 ( V_4 , V_46 , V_47 ) ;
return V_41 ;
}
static void
F_17 (
struct V_3 * V_4
)
{
struct V_15 * V_16 = F_7 ( V_4 ) ;
V_16 -> V_19 [ V_25 ] . V_48 = V_49 ;
V_16 -> V_19 [ V_31 ] . V_48 = V_49 ;
V_16 -> V_19 [ V_50 ] . V_48 = V_51 ;
V_16 -> V_19 [ V_52 ] . V_48 = V_51 ;
V_16 -> V_19 [ V_25 ] . V_53 = V_54 ;
V_16 -> V_19 [ V_31 ] . V_53 = V_54 ;
V_16 -> V_19 [ V_50 ] . V_53 = V_55 ;
V_16 -> V_19 [ V_52 ] . V_53 = V_55 ;
V_16 -> V_19 [ V_25 ] . V_56 = V_57 ;
V_16 -> V_19 [ V_31 ] . V_56 = V_58 ;
V_16 -> V_19 [ V_25 ] . V_59 = V_57 ;
V_16 -> V_19 [ V_31 ] . V_59 = V_58 ;
V_16 -> V_19 [ V_25 ] . V_37 = V_60 ;
V_16 -> V_19 [ V_31 ] . V_37 = V_61 ;
V_16 -> V_19 [ V_25 ] . V_62 = V_63 ;
V_16 -> V_19 [ V_31 ] . V_62 = V_63 ;
V_16 -> V_19 [ V_50 ] . V_62 = V_64 ;
V_16 -> V_19 [ V_52 ] . V_62 = V_64 ;
V_16 -> V_19 [ V_25 ] . V_65 = V_66 ;
V_16 -> V_19 [ V_31 ] . V_65 = V_66 ;
V_16 -> V_19 [ V_50 ] . V_65 = V_66 ;
V_16 -> V_19 [ V_52 ] . V_65 = V_66 ;
V_16 -> V_19 [ V_25 ] . V_67 = V_29 ;
V_16 -> V_19 [ V_31 ] . V_67 = V_32 ;
V_16 -> V_19 [ V_25 ] . V_26 = V_24 ;
V_16 -> V_19 [ V_31 ] . V_26 = V_68 ;
V_16 -> V_19 [ V_25 ] . V_69 = V_70 ;
V_16 -> V_19 [ V_31 ] . V_69 = V_70 ;
V_16 -> V_19 [ V_50 ] . V_69 = V_71 ;
V_16 -> V_19 [ V_52 ] . V_69 = V_71 ;
V_16 -> V_19 [ V_25 ] . V_72 = V_73 ;
V_16 -> V_19 [ V_31 ] . V_72 = V_74 ;
V_16 -> V_19 [ V_50 ] . V_72 = V_75 ;
V_16 -> V_19 [ V_52 ] . V_72 = V_76 ;
V_16 -> V_19 [ V_25 ] . V_77 = V_78 ;
V_16 -> V_19 [ V_31 ] . V_77 = V_79 ;
V_16 -> V_19 [ V_50 ] . V_77 = V_80 ;
V_16 -> V_19 [ V_52 ] . V_77 = V_81 ;
V_16 -> V_19 [ V_25 ] . V_82 = V_83 ;
V_16 -> V_19 [ V_31 ] . V_82 = V_84 ;
V_16 -> V_19 [ V_50 ] . V_82 = V_85 ;
V_16 -> V_19 [ V_52 ] . V_82 = V_86 ;
V_16 -> V_19 [ V_25 ] . V_87 = V_88 ;
V_16 -> V_19 [ V_31 ] . V_87 = V_89 ;
V_16 -> V_19 [ V_50 ] . V_87 = V_90 ;
V_16 -> V_19 [ V_52 ] . V_87 = V_91 ;
V_16 -> V_19 [ V_25 ] . V_92 = V_93 ;
V_16 -> V_19 [ V_31 ] . V_92 = V_94 ;
V_16 -> V_19 [ V_50 ] . V_92 = V_95 ;
V_16 -> V_19 [ V_52 ] . V_92 = V_96 ;
V_16 -> V_19 [ V_25 ] . V_97 = V_98 ;
V_16 -> V_19 [ V_31 ] . V_97 = V_99 ;
V_16 -> V_19 [ V_50 ] . V_97 = V_100 ;
V_16 -> V_19 [ V_52 ] . V_97 = V_101 ;
V_16 -> V_19 [ V_25 ] . V_35 = V_102 ;
V_16 -> V_19 [ V_31 ] . V_35 = V_103 ;
V_16 -> V_19 [ V_50 ] . V_35 = V_104 ;
V_16 -> V_19 [ V_52 ] . V_35 = V_105 ;
V_16 -> V_19 [ V_25 ] . V_33 = V_106 ;
V_16 -> V_19 [ V_31 ] . V_33 = V_107 ;
}
void F_18 ( struct V_3 * V_4 , T_1 V_5 , T_1 V_1 , T_1 V_9 )
{
struct V_15 * V_16 = F_7 ( V_4 ) ;
if ( V_5 == V_108 )
V_16 -> V_109 [ V_16 -> V_110 ] [ 0 ] = V_9 ;
if ( V_5 == V_111 )
V_16 -> V_109 [ V_16 -> V_110 ] [ 1 ] = V_9 ;
if ( V_5 == V_112 )
V_16 -> V_109 [ V_16 -> V_110 ] [ 6 ] = V_9 ;
if ( V_5 == V_113 && V_1 == 0xffffff00 )
V_16 -> V_109 [ V_16 -> V_110 ] [ 7 ] = V_9 ;
if ( V_5 == V_114 )
V_16 -> V_109 [ V_16 -> V_110 ] [ 2 ] = V_9 ;
if ( V_5 == V_115 )
V_16 -> V_109 [ V_16 -> V_110 ] [ 3 ] = V_9 ;
if ( V_5 == V_116 )
V_16 -> V_109 [ V_16 -> V_110 ] [ 4 ] = V_9 ;
if ( V_5 == V_117 ) {
V_16 -> V_109 [ V_16 -> V_110 ] [ 5 ] = V_9 ;
if ( V_16 -> V_118 == V_119 )
V_16 -> V_110 ++ ;
}
if ( V_5 == V_120 )
V_16 -> V_109 [ V_16 -> V_110 ] [ 8 ] = V_9 ;
if ( V_5 == V_121 )
V_16 -> V_109 [ V_16 -> V_110 ] [ 9 ] = V_9 ;
if ( V_5 == V_122 )
V_16 -> V_109 [ V_16 -> V_110 ] [ 14 ] = V_9 ;
if ( V_5 == V_113 && V_1 == 0x000000ff )
V_16 -> V_109 [ V_16 -> V_110 ] [ 15 ] = V_9 ;
if ( V_5 == V_123 )
V_16 -> V_109 [ V_16 -> V_110 ] [ 10 ] = V_9 ;
if ( V_5 == V_124 )
V_16 -> V_109 [ V_16 -> V_110 ] [ 11 ] = V_9 ;
if ( V_5 == V_125 )
V_16 -> V_109 [ V_16 -> V_110 ] [ 12 ] = V_9 ;
if ( V_5 == V_126 ) {
V_16 -> V_109 [ V_16 -> V_110 ] [ 13 ] = V_9 ;
if ( V_16 -> V_118 != V_119 )
V_16 -> V_110 ++ ;
}
}
static int F_19 ( struct V_3 * V_4 )
{
struct V_127 * V_128 = F_20 ( V_4 ) ;
struct V_15 * V_16 = F_7 ( V_4 ) ;
int V_41 = V_42 ;
if ( V_43 == F_21 ( & V_16 -> V_44 , V_129 ) )
V_41 = V_45 ;
if ( V_41 != V_42 )
goto V_130;
if ( ! V_128 -> V_131 ) {
V_16 -> V_110 = 0 ;
if ( V_43 == F_21 ( & V_16 -> V_44 , V_132 ) )
V_41 = V_45 ;
}
if ( V_41 != V_42 )
goto V_130;
if ( V_43 == F_21 ( & V_16 -> V_44 , V_133 ) )
V_41 = V_45 ;
if ( V_41 != V_42 )
goto V_130;
V_130:
return V_41 ;
}
int
F_22 (
struct V_3 * V_4
)
{
int V_41 = V_42 ;
struct V_15 * V_16 = F_7 ( V_4 ) ;
T_1 V_134 ;
T_2 V_135 ;
F_17 ( V_4 ) ;
V_134 = F_23 ( V_4 , V_136 ) ;
F_16 ( V_4 , V_136 , ( V_137 ) ( V_134 | V_138 | V_139 | V_140 ) ) ;
F_24 ( V_4 , V_141 , V_142 | V_143 | V_144 ) ;
F_24 ( V_4 , V_136 , V_145 | V_146 | V_147 | V_148 ) ;
V_41 = F_19 ( V_4 ) ;
V_135 = V_16 -> V_135 & 0x3F ;
F_9 ( V_4 , V_149 , 0x7ff800 , ( V_135 | ( V_135 << 6 ) ) ) ;
return V_41 ;
}
int F_25 ( struct V_3 * V_4 )
{
int V_41 = V_42 ;
V_41 = F_26 ( V_4 ) ;
return V_41 ;
}
int F_27 ( struct V_3 * V_4 , T_2 * V_150 , enum V_11 V_12 )
{
return V_42 ;
}
void
F_28 (
struct V_3 * V_4
)
{
struct V_15 * V_16 = F_7 ( V_4 ) ;
V_16 -> V_151 [ 0 ] = ( T_2 ) F_8 ( V_4 , V_73 , V_152 ) ;
V_16 -> V_151 [ 1 ] = ( T_2 ) F_8 ( V_4 , V_74 , V_152 ) ;
V_16 -> V_151 [ 2 ] = ( T_2 ) F_8 ( V_4 , V_75 , V_152 ) ;
V_16 -> V_151 [ 3 ] = ( T_2 ) F_8 ( V_4 , V_76 , V_152 ) ;
V_16 -> V_153 = ( T_2 ) F_8 ( V_4 , V_154 , V_152 ) ;
V_16 -> V_155 = F_8 ( V_4 , V_156 , V_10 ) ;
}
static T_2 F_29 ( struct V_3 * V_4 , enum V_157 V_158 , int V_159 )
{
T_2 V_160 = 0 ;
int V_13 = 0 ;
switch ( V_158 ) {
case V_161 :
V_13 = - 7 ;
break;
case V_162 :
case V_163 :
default:
V_13 = - 8 ;
break;
}
if ( ( V_159 - V_13 ) > 0 )
V_160 = ( T_2 ) ( ( V_159 - V_13 ) * 2 ) ;
else
V_160 = 0 ;
if ( V_160 > V_164 )
V_160 = V_164 ;
return V_160 ;
}
static int F_30 ( struct V_3 * V_4 , enum V_157 V_158 , T_2 V_160 )
{
int V_13 = 0 ;
int V_165 = 0 ;
switch ( V_158 ) {
case V_161 :
V_13 = - 7 ;
break;
case V_162 :
case V_163 :
default:
V_13 = - 8 ;
break;
}
V_165 = V_160 / 2 + V_13 ;
return V_165 ;
}
void F_31 ( struct V_3 * V_4 , T_1 * V_166 )
{
struct V_15 * V_16 = F_7 ( V_4 ) ;
T_2 V_167 = 0 ;
int V_168 ;
V_167 = V_16 -> V_169 ;
V_168 = F_30 ( V_4 , V_161 , V_167 ) ;
V_167 = V_16 -> V_170 + V_16 -> V_171 ;
if ( F_30 ( V_4 , V_162 , V_167 ) > V_168 )
V_168 = F_30 ( V_4 , V_162 , V_167 ) ;
V_167 = V_16 -> V_170 ;
if ( F_30 ( V_4 , V_163 , V_167 ) > V_168 )
V_168 = F_30 ( V_4 , V_163 , V_167 ) ;
* V_166 = V_168 ;
}
static void F_32 ( struct V_3 * V_4 , T_2 V_172 , T_2 * V_173 ,
T_2 * V_174 , T_2 * V_175 ,
T_2 * V_176 )
{
struct V_15 * V_16 = F_7 ( V_4 ) ;
T_2 V_177 = ( V_172 - 1 ) ;
T_2 V_178 = 0 , V_179 ;
if ( ( V_180 == V_16 -> V_118 ) || ( V_119 == V_16 -> V_118 ) )
V_179 = 1 ;
else
V_179 = 2 ;
for ( V_178 = 0 ; V_178 < V_179 ; V_178 ++ ) {
if ( V_178 == V_25 ) {
V_173 [ V_178 ] = V_16 -> V_181 [ V_178 ] [ V_177 ] ;
V_174 [ V_178 ] = V_16 -> V_182 [ V_25 ] [ V_177 ] +
V_16 -> V_183 [ V_178 ] [ V_25 ] ;
V_175 [ V_178 ] = V_16 -> V_182 [ V_25 ] [ V_177 ] +
V_16 -> V_184 [ V_178 ] [ V_25 ] ;
V_176 [ V_178 ] = V_16 -> V_182 [ V_178 ] [ V_177 ] ;
} else if ( V_178 == V_31 ) {
V_173 [ V_178 ] = V_16 -> V_181 [ V_178 ] [ V_177 ] ;
V_174 [ V_178 ] = V_16 -> V_182 [ V_25 ] [ V_177 ] +
V_16 -> V_184 [ V_25 ] [ V_177 ] +
V_16 -> V_184 [ V_178 ] [ V_177 ] ;
V_175 [ V_178 ] = V_16 -> V_182 [ V_25 ] [ V_177 ] +
V_16 -> V_184 [ V_178 ] [ V_25 ] +
V_16 -> V_184 [ V_178 ] [ V_177 ] ;
V_176 [ V_178 ] = V_16 -> V_182 [ V_178 ] [ V_177 ] ;
} else if ( V_178 == V_50 ) {
V_173 [ V_178 ] = V_16 -> V_181 [ V_178 ] [ V_177 ] ;
V_174 [ V_178 ] = V_16 -> V_182 [ V_25 ] [ V_177 ] +
V_16 -> V_184 [ V_25 ] [ V_177 ] +
V_16 -> V_184 [ V_31 ] [ V_177 ] +
V_16 -> V_184 [ V_178 ] [ V_177 ] ;
V_175 [ V_178 ] = V_16 -> V_182 [ V_25 ] [ V_177 ] +
V_16 -> V_184 [ V_25 ] [ V_177 ] +
V_16 -> V_184 [ V_31 ] [ V_177 ] +
V_16 -> V_184 [ V_178 ] [ V_177 ] ;
V_176 [ V_178 ] = V_16 -> V_182 [ V_178 ] [ V_177 ] ;
} else if ( V_178 == V_52 ) {
V_173 [ V_178 ] = V_16 -> V_181 [ V_178 ] [ V_177 ] ;
V_174 [ V_178 ] = V_16 -> V_182 [ V_25 ] [ V_177 ] +
V_16 -> V_184 [ V_25 ] [ V_177 ] +
V_16 -> V_184 [ V_31 ] [ V_177 ] +
V_16 -> V_184 [ V_50 ] [ V_177 ] +
V_16 -> V_184 [ V_178 ] [ V_177 ] ;
V_175 [ V_178 ] = V_16 -> V_182 [ V_25 ] [ V_177 ] +
V_16 -> V_184 [ V_25 ] [ V_177 ] +
V_16 -> V_184 [ V_31 ] [ V_177 ] +
V_16 -> V_184 [ V_50 ] [ V_177 ] +
V_16 -> V_184 [ V_178 ] [ V_177 ] ;
V_176 [ V_178 ] = V_16 -> V_182 [ V_178 ] [ V_177 ] ;
}
}
}
static void F_33 ( struct V_3 * V_4 , T_2 V_172 , T_2 * V_173 ,
T_2 * V_174 , T_2 * V_175 , T_2 * V_176 )
{
struct V_15 * V_16 = F_7 ( V_4 ) ;
V_16 -> V_169 = V_173 [ 0 ] ;
V_16 -> V_170 = V_174 [ 0 ] ;
V_16 -> V_185 = V_175 [ 0 ] ;
V_16 -> V_186 = V_176 [ 0 ] ;
}
void
F_34 (
struct V_3 * V_4 ,
T_2 V_172
)
{
T_2 V_173 [ V_187 ] = { 0 } ;
T_2 V_174 [ V_187 ] = { 0 } ;
T_2 V_175 [ V_187 ] = { 0 } ;
T_2 V_176 [ V_187 ] = { 0 } ;
F_32 ( V_4 , V_172 , & V_173 [ 0 ] , & V_174 [ 0 ] , & V_175 [ 0 ] , & V_176 [ 0 ] ) ;
F_33 ( V_4 , V_172 , & V_173 [ 0 ] , & V_174 [ 0 ] , & V_175 [ 0 ] , & V_176 [ 0 ] ) ;
F_35 ( V_4 , & V_173 [ 0 ] ) ;
F_36 ( V_4 , & V_174 [ 0 ] , & V_175 [ 0 ] , & V_176 [ 0 ] , V_172 ) ;
}
bool
F_37 (
struct V_3 * V_4 ,
int V_188
)
{
struct V_15 * V_16 = F_7 ( V_4 ) ;
T_2 V_189 ;
T_2 V_190 ;
T_2 V_191 = F_29 ( V_4 , V_161 , V_188 ) ;
T_2 V_192 = F_29 ( V_4 , V_163 , V_188 ) ;
if ( V_192 - V_16 -> V_171 > 0 )
V_192 -= V_16 -> V_171 ;
else
V_192 = 0 ;
for ( V_189 = 0 ; V_189 < 14 ; V_189 ++ ) {
for ( V_190 = 0 ; V_190 < 2 ; V_190 ++ ) {
V_16 -> V_193 [ V_190 ] [ V_189 ] = V_191 ;
V_16 -> V_194 [ V_190 ] [ V_189 ] =
V_16 -> V_195 [ V_190 ] [ V_189 ] = V_192 ;
}
}
return true ;
}
void
F_38 (
struct V_3 * V_4 ,
T_2 V_196
)
{
}
static void
F_39 (
struct V_3 * V_4
)
{
struct V_15 * V_16 = F_7 ( V_4 ) ;
T_2 V_197 ;
T_2 V_198 ;
if ( V_16 -> V_199 == V_200 )
return;
if ( V_16 -> V_199 == V_201 )
return;
if ( V_4 -> V_202 )
return;
V_197 = F_40 ( V_4 , V_203 ) ;
V_198 = F_40 ( V_4 , V_204 + 2 ) ;
switch ( V_16 -> V_205 ) {
case V_206 :
V_197 |= V_207 ;
F_24 ( V_4 , V_203 , V_197 ) ;
break;
case V_208 :
V_197 &= ~ V_207 ;
F_24 ( V_4 , V_203 , V_197 ) ;
V_198 = ( V_198 & 0x90 ) | ( V_16 -> V_209 << 5 ) ;
F_24 ( V_4 , V_204 + 2 , V_198 ) ;
break;
default:
break;
}
switch ( V_16 -> V_205 ) {
case V_206 :
F_9 ( V_4 , V_210 , V_211 , 0x0 ) ;
F_9 ( V_4 , V_212 , V_211 , 0x0 ) ;
break;
case V_208 :
F_9 ( V_4 , V_210 , V_211 , 0x1 ) ;
F_9 ( V_4 , V_212 , V_211 , 0x1 ) ;
F_9 ( V_4 , V_213 , V_214 , ( V_16 -> V_209 >> 1 ) ) ;
F_9 ( V_4 , V_215 , 0xC00 , V_16 -> V_209 ) ;
F_9 ( V_4 , 0x818 , ( V_216 | V_217 ) ,
( V_16 -> V_209 == V_218 ) ? 2 : 1 ) ;
break;
default:
break;
}
switch ( V_16 -> V_199 ) {
case V_201 :
break;
case V_219 :
break;
case V_220 :
break;
case V_200 :
break;
case V_221 :
F_41 ( V_4 , V_16 -> V_205 ) ;
break;
default:
break;
}
}
void F_42 ( struct V_3 * V_4 , enum V_222 V_223 ,
unsigned char V_13 )
{
struct V_15 * V_16 = F_7 ( V_4 ) ;
enum V_222 V_224 = V_16 -> V_205 ;
V_16 -> V_205 = V_223 ;
V_16 -> V_209 = V_13 ;
if ( ( ! V_4 -> V_202 ) && ( ! V_4 -> V_225 ) )
F_39 ( V_4 ) ;
else
V_16 -> V_205 = V_224 ;
}
static void F_43 ( struct V_3 * V_4 , T_2 V_172 )
{
T_2 V_12 ;
T_1 V_226 , V_227 ;
struct V_15 * V_16 = F_7 ( V_4 ) ;
if ( V_4 -> V_228 )
F_44 ( L_1 , V_229 , V_172 ) ;
F_34 ( V_4 , V_172 ) ;
V_226 = V_230 ;
V_227 = V_172 ;
for ( V_12 = 0 ; V_12 < V_16 -> V_231 ; V_12 ++ ) {
V_16 -> V_232 [ V_12 ] = ( ( V_16 -> V_232 [ V_12 ] & 0xfffffc00 ) | V_227 ) ;
F_45 ( V_4 , (enum V_11 ) V_12 , V_226 , V_40 , V_16 -> V_232 [ V_12 ] ) ;
}
}
void F_46 ( struct V_3 * V_4 , T_2 V_172 )
{
struct V_15 * V_16 = F_7 ( V_4 ) ;
T_2 V_233 = V_16 -> V_234 ;
bool V_235 = true ;
if ( V_16 -> V_199 == V_200 )
return;
if ( V_172 == 0 )
V_172 = 1 ;
V_16 -> V_234 = V_172 ;
if ( ( ! V_4 -> V_202 ) && ( ! V_4 -> V_225 ) ) {
F_43 ( V_4 , V_172 ) ;
if ( V_235 )
;
else
V_16 -> V_234 = V_233 ;
} else {
V_16 -> V_234 = V_233 ;
}
}
