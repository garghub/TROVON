static void F_1 ( struct V_1 * V_2 , T_1 V_3 )
{
unsigned long V_4 ;
F_2 ( & V_2 -> V_5 , V_4 ) ;
V_2 -> V_6 |= V_3 ;
F_3 ( & V_2 -> V_5 , V_4 ) ;
}
void F_4 ( struct V_1 * V_2 , T_1 V_3 )
{
unsigned long V_4 ;
F_2 ( & V_2 -> V_5 , V_4 ) ;
V_2 -> V_6 |= V_3 ;
F_5 ( V_7 , V_3 ) ;
F_3 ( & V_2 -> V_5 , V_4 ) ;
}
void F_6 ( struct V_1 * V_2 , T_1 V_3 )
{
T_1 V_8 ;
unsigned long V_4 ;
F_2 ( & V_2 -> V_5 , V_4 ) ;
V_8 = V_3 & V_2 -> V_6 ;
if ( V_8 )
F_5 ( V_7 , V_8 ) ;
F_3 ( & V_2 -> V_5 , V_4 ) ;
}
static inline void F_7 ( struct V_1 * V_2 )
{
F_6 ( V_2 , 0xffffffff ) ;
}
void F_8 ( struct V_1 * V_2 , T_1 V_3 )
{
unsigned long V_4 ;
F_2 ( & V_2 -> V_5 , V_4 ) ;
F_9 ( V_7 , V_3 ) ;
F_3 ( & V_2 -> V_5 , V_4 ) ;
}
static inline void F_10 ( struct V_1 * V_2 )
{
F_8 ( V_2 , 0xffffffff ) ;
}
void F_11 ( struct V_1 * V_2 , T_1 V_3 )
{
unsigned long V_4 ;
F_2 ( & V_2 -> V_5 , V_4 ) ;
V_2 -> V_6 &= ~ V_3 ;
F_9 ( V_7 , V_3 ) ;
F_3 ( & V_2 -> V_5 , V_4 ) ;
}
static T_1 F_12 ( struct V_1 * V_2 )
{
T_1 V_8 ;
unsigned long V_4 ;
F_2 ( & V_2 -> V_5 , V_4 ) ;
V_8 = F_13 ( V_7 ) ;
F_3 ( & V_2 -> V_5 , V_4 ) ;
return V_8 ;
}
static int F_14 ( T_1 V_9 )
{
static char * V_10 [ 16 ] = {
[ V_11 >> 28 ] = L_1 ,
[ V_12 >> 28 ] = L_2 ,
[ V_13 >> 28 ] = L_3 ,
[ V_14 >> 28 ] = L_4 ,
[ V_15 >> 28 ] = L_5 ,
[ V_16 >> 28 ] = L_6 ,
[ V_17 >> 28 ] = L_7 ,
[ V_18 >> 28 ] = L_8 ,
[ V_19 >> 28 ] = L_9 ,
[ V_20 >> 28 ] = L_10 ,
} ;
static int V_21 [ 16 ] = {
[ V_12 >> 28 ] = 3 ,
[ V_16 >> 28 ] = 3 ,
[ V_17 >> 28 ] = 1 ,
[ V_11 >> 28 ] = 1 ,
[ V_18 >> 28 ] = 3 ,
[ V_19 >> 28 ] = 3 ,
[ V_20 >> 28 ] = 4 ,
} ;
static char * V_22 [] = {
L_11 , L_12 , L_13 , L_14 ,
L_15 , L_16 , L_17 , L_18 ,
L_19 , L_20 , L_21 , L_22 ,
L_23 , L_24 , L_25 , L_26 ,
} ;
int V_23 ;
F_15 ( L_27 , V_9 ,
V_10 [ V_9 >> 28 ] ? V_10 [ V_9 >> 28 ] : L_28 ) ;
for ( V_23 = F_16 ( V_22 ) - 1 ; V_23 >= 0 ; V_23 -- )
if ( V_9 & ( 1 << ( V_23 + 12 ) ) )
F_15 ( L_29 , V_22 [ V_23 ] ) ;
F_15 ( L_30 , V_9 & 0xfff ) ;
return V_21 [ V_9 >> 28 ] ? V_21 [ V_9 >> 28 ] : 1 ;
}
static void F_17 ( struct V_24 * V_25 ,
struct V_26 * V_27 , T_1 V_28 )
{
struct V_1 * V_2 = V_25 -> V_2 ;
struct V_29 * V_30 ;
if ( F_18 ( & V_27 -> V_31 ) )
return;
V_30 = F_19 ( V_27 -> V_31 . V_32 ,
struct V_29 , V_33 ) ;
F_20 ( & V_30 -> V_34 . V_35 . V_36 ) ;
V_30 -> V_34 . V_35 . V_37 = V_27 -> V_28 ++ ;
F_21 ( 1 , L_31 , V_30 , V_30 -> V_34 . V_35 . V_38 ,
V_28 , V_27 -> V_28 ) ;
F_22 ( & V_30 -> V_33 ) ;
F_23 ( & V_30 -> V_34 , V_39 ) ;
}
int F_24 ( struct V_1 * V_2 ,
struct V_40 * V_41 ,
unsigned int V_42 , T_1 V_9 )
{
unsigned int V_23 , V_43 ;
T_1 V_44 ;
if ( V_41 -> V_45 == 0 ) {
F_21 ( 1 , L_32 , V_46 ,
V_41 -> V_47 ) ;
F_25 ( V_41 -> V_48 , 0 ) ;
F_25 ( V_41 -> V_49 , 0 ) ;
F_25 ( V_41 -> V_50 , 0 ) ;
F_25 ( V_41 -> V_51 , 0 ) ;
return 0 ;
} else {
F_21 ( 1 , L_33 , V_46 ,
V_41 -> V_47 ) ;
}
V_42 = ( V_42 + 7 ) & ~ 7 ;
V_44 = V_41 -> V_44 ;
V_43 = V_41 -> V_52 / V_42 ;
if ( V_43 > 6 )
V_43 = 6 ;
F_26 ( V_43 < 2 ) ;
F_25 ( 8 + 0 , V_16 | V_53 ) ;
F_25 ( 8 + 4 , 12 ) ;
F_25 ( 8 + 8 , 0 ) ;
for ( V_23 = 0 ; V_23 < V_43 ; V_23 ++ ) {
F_21 ( 2 , L_34 , V_46 , V_44 + 16 * V_23 ,
V_41 -> V_54 + V_42 * V_23 ) ;
F_25 ( V_44 + 16 * V_23 , V_41 -> V_54 + V_42 * V_23 ) ;
F_25 ( V_44 + 16 * V_23 + 4 , 0 ) ;
F_25 ( V_44 + 16 * V_23 + 8 , 0 ) ;
F_25 ( V_44 + 16 * V_23 + 12 , 0 ) ;
}
if ( V_41 -> V_55 )
F_25 ( V_41 -> V_45 + 0 , 8 ) ;
else
F_25 ( V_41 -> V_45 + 0 , V_9 ) ;
F_25 ( V_41 -> V_45 + 4 , 0 ) ;
F_25 ( V_41 -> V_45 + 8 , V_44 ) ;
F_25 ( V_41 -> V_45 + 12 , ( V_43 * 16 ) >> 3 ) ;
F_25 ( V_41 -> V_45 + 16 , V_41 -> V_56 ) ;
if ( V_41 -> V_55 )
F_25 ( V_41 -> V_45 + 20 , 0x80000000 | ( 64 >> 2 ) ) ;
else
F_25 ( V_41 -> V_45 + 20 , 64 >> 2 ) ;
for ( V_23 = 24 ; V_23 < 80 ; V_23 += 4 )
F_25 ( V_41 -> V_45 + V_23 , 0 ) ;
F_25 ( V_41 -> V_48 , V_41 -> V_54 ) ;
F_25 ( V_41 -> V_49 , V_44 ) ;
F_25 ( V_41 -> V_50 , ( V_43 * 16 ) >> 3 ) ;
F_25 ( V_41 -> V_51 , ( V_42 >> 3 ) - 1 ) ;
F_21 ( 2 , L_35 ,
V_2 -> V_57 ,
V_41 -> V_47 ,
V_42 ,
V_43 ) ;
return 0 ;
}
void F_27 ( struct V_1 * V_2 ,
struct V_40 * V_41 )
{
static char * V_47 [] = {
L_36 ,
L_37 ,
L_38 ,
L_39 ,
L_40 ,
L_41 ,
L_42 ,
L_43 ,
L_44 ,
L_45 ,
L_46 ,
L_47 ,
L_48 ,
L_49 ,
} ;
T_1 V_9 ;
unsigned int V_23 , V_58 , V_59 ;
F_15 ( V_60 L_50 ,
V_2 -> V_47 , V_41 -> V_47 ) ;
for ( V_23 = 0 ; V_23 < F_16 ( V_47 ) ; V_23 ++ )
F_15 ( V_60 L_51 ,
V_2 -> V_47 , V_47 [ V_23 ] ,
F_13 ( V_41 -> V_45 + 4 * V_23 ) ) ;
for ( V_23 = 0 ; V_23 < 4 ; V_23 ++ ) {
V_9 = F_13 ( V_41 -> V_45 + 4 * ( V_23 + 14 ) ) ;
F_15 ( V_60 L_52 , V_2 -> V_47 , V_23 ) ;
F_14 ( V_9 ) ;
}
for ( V_23 = 0 ; V_23 < ( 64 >> 2 ) ; V_23 += V_59 ) {
V_9 = F_13 ( V_41 -> V_56 + 4 * V_23 ) ;
F_15 ( V_60 L_53 , V_2 -> V_47 ,
V_41 -> V_56 + 4 * V_23 , V_23 ) ;
V_59 = F_14 ( V_9 ) ;
for ( V_58 = 1 ; V_58 < V_59 ; V_58 ++ ) {
V_9 = F_13 ( V_41 -> V_56 + 4 * ( V_23 + V_58 ) ) ;
F_15 ( V_60 L_54 ,
V_2 -> V_47 , V_23 + V_58 , V_9 , V_58 ) ;
}
}
F_15 ( V_60 L_55 ,
V_2 -> V_47 , V_41 -> V_54 , V_41 -> V_54 + V_41 -> V_52 ) ;
F_15 ( V_60 L_56 ,
V_2 -> V_47 , V_41 -> V_56 , V_41 -> V_56 + 6 * 16 ) ;
F_15 ( V_60 L_57 ,
V_2 -> V_47 , F_13 ( V_41 -> V_48 ) ) ;
F_15 ( V_60 L_58 ,
V_2 -> V_47 , F_13 ( V_41 -> V_49 ) ) ;
F_15 ( V_60 L_59 ,
V_2 -> V_47 , F_13 ( V_41 -> V_51 ) ) ;
F_15 ( V_60 L_60 ,
V_2 -> V_47 , F_13 ( V_41 -> V_50 ) ) ;
}
static void F_28 ( struct V_24 * V_25 ,
struct V_61 * V_9 )
{
struct V_1 * V_2 = V_25 -> V_2 ;
unsigned int V_23 , V_58 , V_59 ;
F_15 ( V_62 L_61 ,
V_2 -> V_47 , V_9 -> V_63 , ( unsigned long ) V_9 -> V_64 ) ;
for ( V_23 = 0 ; V_23 < ( V_9 -> V_65 >> 2 ) ; V_23 += V_59 ) {
F_15 ( V_62 L_62 , V_2 -> V_47 , V_23 ) ;
V_59 = F_14 ( F_29 ( V_9 -> V_63 [ V_23 ] ) ) ;
for ( V_58 = 1 ; V_58 < V_59 ; V_58 ++ )
F_15 ( V_62 L_63 ,
V_2 -> V_47 , V_23 + V_58 , V_9 -> V_63 [ V_23 + V_58 ] , V_58 ) ;
if ( V_9 -> V_63 [ V_23 ] == F_30 ( V_16 ) )
break;
}
}
static void F_31 ( struct V_1 * V_2 )
{
F_25 ( V_66 , 0 ) ;
F_25 ( V_67 , 0 ) ;
F_25 ( V_68 , 0 ) ;
F_25 ( V_69 , 0 ) ;
F_25 ( V_70 , 0 ) ;
F_25 ( V_71 , 0 ) ;
F_25 ( V_72 , 0 ) ;
F_25 ( V_73 , 0 ) ;
F_10 ( V_2 ) ;
F_25 ( V_74 , 0 ) ;
F_25 ( V_75 , 0 ) ;
F_25 ( V_76 , 0 ) ;
F_25 ( V_77 , 0 ) ;
F_25 ( V_78 , 0 ) ;
}
static void F_32 ( struct V_1 * V_2 )
{
F_21 ( 1 , L_64 , V_46 ) ;
F_31 ( V_2 ) ;
F_25 ( V_79 , 0xffffffff ) ;
F_25 ( V_80 , 0xffffffff ) ;
F_25 ( V_81 , 0xffffffff ) ;
F_25 ( V_82 , 0xffffffff ) ;
F_25 ( V_83 , 0xffffffff ) ;
F_25 ( V_84 , 0xffffffff ) ;
F_25 ( V_85 , F_13 ( V_85 ) & 0x80000000 ) ;
F_25 ( V_86 , 0x00500300 ) ;
F_33 ( 100 ) ;
F_24 ( V_2 , & V_2 -> V_87 [ V_88 ] ,
720 * 4 , 0 ) ;
F_24 ( V_2 , & V_2 -> V_87 [ V_89 ] , 128 , 0 ) ;
F_24 ( V_2 , & V_2 -> V_87 [ V_90 ] ,
188 * 4 , 0 ) ;
F_24 ( V_2 , & V_2 -> V_87 [ V_91 ] , 128 , 0 ) ;
F_24 ( V_2 , & V_2 -> V_87 [ V_92 ] , 128 , 0 ) ;
F_24 ( V_2 , & V_2 -> V_87 [ V_93 ] ,
188 * 4 , 0 ) ;
F_24 ( V_2 , & V_2 -> V_87 [ V_94 ] , 128 , 0 ) ;
F_24 ( V_2 , & V_2 -> V_87 [ V_95 ] , 128 , 0 ) ;
F_24 ( V_2 , & V_2 -> V_87 [ V_96 ] , 128 , 0 ) ;
F_34 ( V_2 ) ;
}
static int F_35 ( struct V_1 * V_2 )
{
F_21 ( 1 , L_64 , V_46 ) ;
if ( V_2 -> V_57 == V_97 )
F_9 ( V_98 , 1 << 4 ) ;
return 0 ;
}
static int F_36 ( struct V_1 * V_2 )
{
if ( F_37 ( F_38 ( V_2 -> V_99 , 0 ) ,
F_39 ( V_2 -> V_99 , 0 ) ,
V_2 -> V_47 ) )
return 0 ;
F_15 ( V_100 L_65 ,
V_2 -> V_47 , ( unsigned long long ) F_38 ( V_2 -> V_99 , 0 ) ) ;
return - V_101 ;
}
static int F_40 ( struct V_1 * V_2 ,
struct V_24 * V_25 , int V_102 )
{
F_21 ( 1 , L_66 , V_46 , V_102 ) ;
V_25 -> V_103 = 0x11 ;
V_25 -> V_104 = 0x1111 ;
V_25 -> V_105 = 0x0 ;
V_25 -> V_106 = ( 0x47 << 16 | 188 << 4 ) ;
F_41 ( & V_25 -> V_107 ) ;
V_25 -> V_2 = V_2 ;
V_25 -> V_108 = V_102 ;
F_42 ( & V_25 -> V_109 . V_31 ) ;
F_43 ( & V_25 -> V_110 . V_111 ) ;
F_42 ( & V_25 -> V_110 . V_112 ) ;
V_25 -> V_110 . V_113 = 0 ;
if ( ! V_25 -> V_114 )
V_25 -> V_114 = 1 ;
switch ( V_102 ) {
case 1 :
V_25 -> V_115 = V_116 ;
V_25 -> V_117 = V_118 ;
V_25 -> V_119 = V_69 ;
V_25 -> V_120 = V_121 ;
V_25 -> V_122 = V_123 ;
V_25 -> V_124 = V_125 ;
V_25 -> V_126 = V_127 ;
V_25 -> V_128 = V_129 ;
V_25 -> V_130 = V_131 ;
V_25 -> V_132 = V_133 ;
V_25 -> V_134 = V_135 ;
V_25 -> V_136 = V_137 ;
V_25 -> V_138 = V_75 ;
V_25 -> V_139 = V_81 ;
V_25 -> V_140 = V_90 ;
V_25 -> V_6 = 0x02 ;
break;
case 2 :
V_25 -> V_115 = V_141 ;
V_25 -> V_117 = V_142 ;
V_25 -> V_119 = V_70 ;
V_25 -> V_120 = V_143 ;
V_25 -> V_122 = V_144 ;
V_25 -> V_124 = V_145 ;
V_25 -> V_126 = V_146 ;
V_25 -> V_128 = V_147 ;
V_25 -> V_130 = V_148 ;
V_25 -> V_132 = V_149 ;
V_25 -> V_134 = V_150 ;
V_25 -> V_136 = 0 ;
V_25 -> V_138 = V_76 ;
V_25 -> V_139 = V_82 ;
V_25 -> V_140 = V_93 ;
V_25 -> V_6 = 0x04 ;
break;
default:
F_44 () ;
}
return 0 ;
}
static void F_45 ( struct V_1 * V_2 )
{
switch ( F_13 ( V_151 ) & 0xff ) {
case 0x00 :
V_2 -> V_152 = 0xa0 ;
break;
case 0x01 :
V_2 -> V_152 = 0xa1 ;
break;
case 0x02 :
V_2 -> V_152 = 0xb0 ;
break;
case 0x03 :
if ( V_2 -> V_99 -> V_153 == 0x8880 ) {
V_2 -> V_152 = 0xc0 ;
} else {
V_2 -> V_152 = 0xa4 ;
}
break;
case 0x04 :
if ( V_2 -> V_99 -> V_153 == 0x8880 ) {
V_2 -> V_152 = 0xd0 ;
} else {
V_2 -> V_152 = 0xa5 ;
}
break;
case 0x0e :
V_2 -> V_152 = 0xc0 ;
break;
case 0x0f :
V_2 -> V_152 = 0xb1 ;
break;
default:
F_15 ( V_100 L_67 ,
V_46 , V_2 -> V_152 ) ;
}
if ( V_2 -> V_152 )
F_15 ( V_62 L_68 ,
V_46 , V_2 -> V_152 ) ;
else
F_15 ( V_100 L_69 ,
V_46 , V_2 -> V_152 ) ;
}
struct V_154 * F_46 ( struct V_1 * V_2 , T_1 V_155 )
{
struct V_154 * V_156 = NULL ;
struct V_154 * V_157 ;
F_47 ( & V_2 -> V_158 . V_111 ) ;
F_48 (sd, &dev->v4l2_dev) {
if ( V_157 -> V_159 == V_155 ) {
V_156 = V_157 ;
break;
}
}
F_49 ( & V_2 -> V_158 . V_111 ) ;
return V_156 ;
}
static int F_50 ( struct V_1 * V_2 )
{
int V_23 ;
F_41 ( & V_2 -> V_5 ) ;
F_41 ( & V_2 -> V_107 ) ;
F_43 ( & V_2 -> V_111 ) ;
F_43 ( & V_2 -> V_160 ) ;
F_51 ( & V_2 -> V_161 ) ;
V_2 -> V_108 = V_162 ++ ;
sprintf ( V_2 -> V_47 , L_70 , V_2 -> V_108 ) ;
if ( V_2 -> V_99 -> V_153 == 0x8880 ) {
V_2 -> V_57 = V_163 ;
V_2 -> V_164 = 25000000 ;
V_2 -> V_87 = V_165 ;
} else
if ( V_2 -> V_99 -> V_153 == 0x8852 ) {
V_2 -> V_57 = V_97 ;
V_2 -> V_164 = 28000000 ;
V_2 -> V_87 = V_166 ;
} else
F_44 () ;
F_21 ( 1 , L_71 ,
V_46 , V_2 -> V_57 ) ;
V_2 -> V_167 = V_168 ;
if ( V_169 [ V_2 -> V_108 ] < V_170 )
V_2 -> V_167 = V_169 [ V_2 -> V_108 ] ;
for ( V_23 = 0 ; V_168 == V_2 -> V_167 && V_23 < V_171 ; V_23 ++ )
if ( V_2 -> V_99 -> V_172 == V_173 [ V_23 ] . V_174 &&
V_2 -> V_99 -> V_175 == V_173 [ V_23 ] . V_176 )
V_2 -> V_167 = V_173 [ V_23 ] . V_169 ;
if ( V_168 == V_2 -> V_167 ) {
V_2 -> V_167 = V_177 ;
F_52 ( V_2 ) ;
}
if ( V_178 [ V_2 -> V_167 ] . V_164 > 0 )
V_2 -> V_164 = V_178 [ V_2 -> V_167 ] . V_164 ;
V_2 -> V_179 = V_2 -> V_99 -> V_180 -> V_181 ;
V_2 -> V_182 = F_53 ( V_2 -> V_99 -> V_183 ) ;
F_1 ( V_2 , 0x001f00 ) ;
V_2 -> V_184 [ 0 ] . V_108 = 0 ;
V_2 -> V_184 [ 0 ] . V_2 = V_2 ;
V_2 -> V_184 [ 0 ] . V_185 = V_186 ;
V_2 -> V_184 [ 0 ] . V_187 = V_188 ;
V_2 -> V_184 [ 0 ] . V_189 = V_190 ;
V_2 -> V_184 [ 0 ] . V_191 = V_192 ;
V_2 -> V_184 [ 0 ] . V_193 = V_194 ;
V_2 -> V_184 [ 0 ] . V_195 = ( 0x9d << 24 ) ;
V_2 -> V_184 [ 1 ] . V_108 = 1 ;
V_2 -> V_184 [ 1 ] . V_2 = V_2 ;
V_2 -> V_184 [ 1 ] . V_185 = V_196 ;
V_2 -> V_184 [ 1 ] . V_187 = V_197 ;
V_2 -> V_184 [ 1 ] . V_189 = V_198 ;
V_2 -> V_184 [ 1 ] . V_191 = V_199 ;
V_2 -> V_184 [ 1 ] . V_193 = V_200 ;
V_2 -> V_184 [ 1 ] . V_195 = ( 0x9d << 24 ) ;
V_2 -> V_184 [ 2 ] . V_108 = 2 ;
V_2 -> V_184 [ 2 ] . V_2 = V_2 ;
V_2 -> V_184 [ 2 ] . V_185 = V_201 ;
V_2 -> V_184 [ 2 ] . V_187 = V_202 ;
V_2 -> V_184 [ 2 ] . V_189 = V_203 ;
V_2 -> V_184 [ 2 ] . V_191 = V_204 ;
V_2 -> V_184 [ 2 ] . V_193 = V_205 ;
V_2 -> V_184 [ 2 ] . V_195 = ( 0x07 << 24 ) ;
if ( ( V_178 [ V_2 -> V_167 ] . V_206 == V_207 ) ||
( V_178 [ V_2 -> V_167 ] . V_206 == V_208 ) )
F_40 ( V_2 , & V_2 -> V_209 , 1 ) ;
if ( ( V_178 [ V_2 -> V_167 ] . V_210 == V_207 ) ||
( V_178 [ V_2 -> V_167 ] . V_210 == V_208 ) )
F_40 ( V_2 , & V_2 -> V_211 , 2 ) ;
if ( F_36 ( V_2 ) < 0 ) {
F_15 ( V_100 L_72
L_73 ,
V_2 -> V_47 , V_2 -> V_99 -> V_172 ,
V_2 -> V_99 -> V_175 ) ;
V_162 -- ;
return - V_212 ;
}
V_2 -> V_213 = F_54 ( F_38 ( V_2 -> V_99 , 0 ) ,
F_39 ( V_2 -> V_99 , 0 ) ) ;
V_2 -> V_214 = ( V_215 V_216 * ) V_2 -> V_213 ;
F_15 ( V_62 L_74 ,
V_2 -> V_47 , V_2 -> V_99 -> V_172 ,
V_2 -> V_99 -> V_175 , V_178 [ V_2 -> V_167 ] . V_47 ,
V_2 -> V_167 , V_169 [ V_2 -> V_108 ] == V_2 -> V_167 ?
L_75 : L_76 ) ;
F_35 ( V_2 ) ;
V_2 -> V_217 = V_178 [ V_2 -> V_167 ] . V_217 ;
V_2 -> V_218 = V_178 [ V_2 -> V_167 ] . V_218 ;
V_2 -> V_219 = V_178 [ V_2 -> V_167 ] . V_219 ;
V_2 -> V_220 = V_178 [ V_2 -> V_167 ] . V_220 ;
V_2 -> V_221 = V_178 [ V_2 -> V_167 ] . V_221 ;
F_21 ( 1 , L_77 ,
V_46 , V_2 -> V_217 , V_2 -> V_218 , V_2 -> V_219 ) ;
F_21 ( 1 , L_78 ,
V_46 , V_2 -> V_220 , V_2 -> V_221 ) ;
if ( ( V_178 [ V_2 -> V_167 ] . V_206 == V_208 ) ||
( V_178 [ V_2 -> V_167 ] . V_210 == V_208 ) )
F_55 ( V_2 ) ;
F_32 ( V_2 ) ;
F_56 ( & V_2 -> V_184 [ 0 ] ) ;
F_56 ( & V_2 -> V_184 [ 1 ] ) ;
F_56 ( & V_2 -> V_184 [ 2 ] ) ;
F_57 ( V_2 ) ;
F_58 ( V_2 , V_222 , V_223 , 0 ) ;
F_59 ( V_2 ) ;
if ( V_178 [ V_2 -> V_167 ] . V_224 == V_225 ) {
if ( F_60 ( V_2 ) < 0 ) {
F_15 ( V_100 L_79
L_80 , V_46 ) ;
}
}
if ( V_178 [ V_2 -> V_167 ] . V_206 == V_207 ) {
if ( V_178 [ V_2 -> V_167 ] . V_226 )
V_2 -> V_209 . V_114 =
V_178 [ V_2 -> V_167 ] . V_226 ;
if ( F_61 ( & V_2 -> V_209 ) < 0 ) {
F_15 ( V_100 L_81 ,
V_46 ) ;
}
} else
if ( V_178 [ V_2 -> V_167 ] . V_206 == V_208 ) {
if ( F_62 ( V_2 ) < 0 ) {
F_15 ( V_100
L_82 ,
V_46 ) ;
}
}
if ( V_178 [ V_2 -> V_167 ] . V_210 == V_207 ) {
if ( V_178 [ V_2 -> V_167 ] . V_227 )
V_2 -> V_211 . V_114 =
V_178 [ V_2 -> V_167 ] . V_227 ;
if ( F_61 ( & V_2 -> V_211 ) < 0 ) {
F_15 ( V_100
L_83 ,
V_46 ) ;
}
} else
if ( V_178 [ V_2 -> V_167 ] . V_210 == V_208 ) {
if ( F_62 ( V_2 ) < 0 ) {
F_15 ( V_100
L_84 ,
V_46 ) ;
}
}
F_45 ( V_2 ) ;
if ( V_178 [ V_2 -> V_167 ] . V_228 > 0 )
F_9 ( V_229 , 1 << 8 ) ;
switch ( V_2 -> V_167 ) {
case V_230 :
case V_231 :
F_9 ( V_229 , 1 << 8 ) ;
break;
}
return 0 ;
}
static void F_63 ( struct V_1 * V_2 )
{
F_64 ( F_38 ( V_2 -> V_99 , 0 ) ,
F_39 ( V_2 -> V_99 , 0 ) ) ;
if ( ! F_65 ( & V_2 -> V_161 ) )
return;
if ( V_178 [ V_2 -> V_167 ] . V_224 == V_225 )
F_66 ( V_2 ) ;
if ( V_178 [ V_2 -> V_167 ] . V_206 == V_207 )
F_67 ( & V_2 -> V_209 ) ;
if ( V_178 [ V_2 -> V_167 ] . V_206 == V_208 )
F_68 ( V_2 ) ;
if ( V_178 [ V_2 -> V_167 ] . V_210 == V_207 )
F_67 ( & V_2 -> V_211 ) ;
if ( V_178 [ V_2 -> V_167 ] . V_210 == V_208 )
F_68 ( V_2 ) ;
F_69 ( & V_2 -> V_184 [ 2 ] ) ;
F_69 ( & V_2 -> V_184 [ 1 ] ) ;
F_69 ( & V_2 -> V_184 [ 0 ] ) ;
F_70 ( V_2 -> V_213 ) ;
}
static T_2 * F_71 ( T_2 * V_232 , struct V_233 * V_234 ,
unsigned int V_235 , T_1 V_236 ,
unsigned int V_42 , unsigned int V_237 ,
unsigned int V_43 , unsigned int V_238 , bool V_239 )
{
struct V_233 * V_240 ;
unsigned int line , V_241 , V_242 ;
if ( V_239 ) {
* ( V_232 ++ ) = F_30 ( V_16 ) ;
* ( V_232 ++ ) = F_30 ( 0 ) ;
* ( V_232 ++ ) = F_30 ( 0 ) ;
}
if ( V_236 != V_243 )
* ( V_232 ++ ) = F_30 ( V_244 | V_236 ) ;
V_240 = V_234 ;
for ( line = 0 ; line < V_43 ; line ++ ) {
while ( V_235 && V_235 >= F_72 ( V_240 ) ) {
V_235 -= F_72 ( V_240 ) ;
V_240 = F_73 ( V_240 ) ;
}
if ( V_238 && line > 0 && ! ( line % V_238 ) )
V_242 = V_245 | V_246 | V_247 ;
else
V_242 = V_245 ;
if ( V_42 <= F_72 ( V_240 ) - V_235 ) {
* ( V_232 ++ ) = F_30 ( V_12 | V_242 | V_248 | V_42 ) ;
* ( V_232 ++ ) = F_30 ( F_74 ( V_240 ) + V_235 ) ;
* ( V_232 ++ ) = F_30 ( 0 ) ;
V_235 += V_42 ;
} else {
V_241 = V_42 ;
* ( V_232 ++ ) = F_30 ( V_12 | V_242 |
( F_72 ( V_240 ) - V_235 ) ) ;
* ( V_232 ++ ) = F_30 ( F_74 ( V_240 ) + V_235 ) ;
* ( V_232 ++ ) = F_30 ( 0 ) ;
V_241 -= ( F_72 ( V_240 ) - V_235 ) ;
V_235 = 0 ;
V_240 = F_73 ( V_240 ) ;
while ( V_241 > F_72 ( V_240 ) ) {
* ( V_232 ++ ) = F_30 ( V_12 |
F_72 ( V_240 ) ) ;
* ( V_232 ++ ) = F_30 ( F_74 ( V_240 ) ) ;
* ( V_232 ++ ) = F_30 ( 0 ) ;
V_241 -= F_72 ( V_240 ) ;
V_240 = F_73 ( V_240 ) ;
}
* ( V_232 ++ ) = F_30 ( V_12 | V_248 | V_241 ) ;
* ( V_232 ++ ) = F_30 ( F_74 ( V_240 ) ) ;
* ( V_232 ++ ) = F_30 ( 0 ) ;
V_235 += V_241 ;
}
V_235 += V_237 ;
}
return V_232 ;
}
int F_75 ( struct V_249 * V_99 , struct V_61 * V_9 ,
struct V_233 * V_234 , unsigned int V_250 ,
unsigned int V_251 , unsigned int V_42 ,
unsigned int V_237 , unsigned int V_43 )
{
T_1 V_252 , V_253 ;
T_2 * V_232 ;
V_253 = 0 ;
if ( V_168 != V_250 )
V_253 ++ ;
if ( V_168 != V_251 )
V_253 ++ ;
V_252 = V_253 * ( 1 + ( ( V_42 + V_237 ) * V_43 )
/ V_254 + V_43 ) ;
V_252 += 5 ;
V_9 -> V_65 = V_252 * 12 ;
V_9 -> V_63 = F_76 ( V_99 , V_9 -> V_65 , & V_9 -> V_64 ) ;
if ( V_9 -> V_63 == NULL )
return - V_255 ;
V_232 = V_9 -> V_63 ;
if ( V_168 != V_250 )
V_232 = F_71 ( V_232 , V_234 , V_250 , 0 ,
V_42 , V_237 , V_43 , 0 , true ) ;
if ( V_168 != V_251 )
V_232 = F_71 ( V_232 , V_234 , V_251 , 0x200 ,
V_42 , V_237 , V_43 , 0 , V_168 == V_250 ) ;
V_9 -> V_256 = V_232 ;
F_26 ( ( V_9 -> V_256 - V_9 -> V_63 + 2 ) * sizeof( * V_9 -> V_63 ) > V_9 -> V_65 ) ;
return 0 ;
}
int F_77 ( struct V_249 * V_99 ,
struct V_61 * V_9 ,
struct V_233 * V_234 ,
unsigned int V_42 ,
unsigned int V_43 , unsigned int V_238 )
{
T_1 V_252 ;
T_2 * V_232 ;
V_252 = 1 + ( V_42 * V_43 ) / V_254 + V_43 ;
V_252 += 4 ;
V_9 -> V_65 = V_252 * 12 ;
V_9 -> V_63 = F_76 ( V_99 , V_9 -> V_65 , & V_9 -> V_64 ) ;
if ( V_9 -> V_63 == NULL )
return - V_255 ;
V_232 = V_9 -> V_63 ;
V_232 = F_71 ( V_232 , V_234 , 0 , V_243 ,
V_42 , 0 , V_43 , V_238 , V_238 == 0 ) ;
V_9 -> V_256 = V_232 ;
F_26 ( ( V_9 -> V_256 - V_9 -> V_63 + 2 ) * sizeof( * V_9 -> V_63 ) > V_9 -> V_65 ) ;
return 0 ;
}
int F_78 ( struct V_249 * V_99 , struct V_61 * V_9 ,
struct V_233 * V_234 , unsigned int V_250 ,
unsigned int V_251 , unsigned int V_42 ,
unsigned int V_237 , unsigned int V_43 )
{
T_1 V_252 , V_253 ;
T_2 * V_232 ;
V_253 = 0 ;
if ( V_168 != V_250 )
V_253 ++ ;
if ( V_168 != V_251 )
V_253 ++ ;
V_252 = V_253 * ( 1 + ( ( V_42 + V_237 ) * V_43 )
/ V_254 + V_43 ) ;
V_252 += 5 ;
V_9 -> V_65 = V_252 * 12 ;
V_9 -> V_63 = F_76 ( V_99 , V_9 -> V_65 , & V_9 -> V_64 ) ;
if ( V_9 -> V_63 == NULL )
return - V_255 ;
V_232 = V_9 -> V_63 ;
if ( V_168 != V_250 )
V_232 = F_71 ( V_232 , V_234 , V_250 , 0 ,
V_42 , V_237 , V_43 , 0 , true ) ;
if ( V_168 != V_251 )
V_232 = F_71 ( V_232 , V_234 , V_251 , 0x200 ,
V_42 , V_237 , V_43 , 0 , V_168 == V_250 ) ;
V_9 -> V_256 = V_232 ;
F_26 ( ( V_9 -> V_256 - V_9 -> V_63 + 2 ) * sizeof( * V_9 -> V_63 ) > V_9 -> V_65 ) ;
return 0 ;
}
void F_79 ( struct V_1 * V_2 , struct V_29 * V_30 )
{
struct V_61 * V_9 = & V_30 -> V_9 ;
F_26 ( F_80 () ) ;
F_81 ( V_2 -> V_99 , V_9 -> V_65 , V_9 -> V_63 , V_9 -> V_64 ) ;
}
static void F_82 ( struct V_24 * V_25 )
{
struct V_1 * V_2 = V_25 -> V_2 ;
F_21 ( 1 , L_85 , V_46 ) ;
F_21 ( 1 , L_86 , V_46 ,
F_13 ( V_66 ) ) ;
F_21 ( 1 , L_87 , V_46 ,
F_12 ( V_2 ) ) ;
F_21 ( 1 , L_88 , V_46 ,
F_13 ( V_77 ) ) ;
F_21 ( 1 , L_89 , V_46 ,
F_13 ( V_71 ) ) ;
F_21 ( 1 , L_90 , V_46 ,
F_13 ( V_78 ) ) ;
F_21 ( 1 , L_91 , V_46 ,
F_13 ( V_72 ) ) ;
F_21 ( 1 , L_92 , V_46 ,
F_13 ( V_86 ) ) ;
F_21 ( 1 , L_93 , V_46 ,
F_13 ( V_257 ) ) ;
F_21 ( 1 , L_94 , V_46 ,
F_13 ( V_258 ) ) ;
F_21 ( 1 , L_95 , V_46 ,
V_25 -> V_115 , F_13 ( V_25 -> V_115 ) ) ;
F_21 ( 1 , L_96 , V_46 ,
V_25 -> V_117 , F_13 ( V_25 -> V_117 ) ) ;
F_21 ( 1 , L_97 , V_46 ,
V_25 -> V_119 , F_13 ( V_25 -> V_119 ) ) ;
if ( V_25 -> V_136 )
F_21 ( 1 , L_98 , V_46 ,
V_25 -> V_136 , F_13 ( V_25 -> V_136 ) ) ;
F_21 ( 1 , L_99 , V_46 ,
V_25 -> V_120 , F_13 ( V_25 -> V_120 ) ) ;
F_21 ( 1 , L_100 , V_46 ,
V_25 -> V_122 , F_13 ( V_25 -> V_122 ) ) ;
F_21 ( 1 , L_101 , V_46 ,
V_25 -> V_124 , F_13 ( V_25 -> V_124 ) ) ;
F_21 ( 1 , L_102 , V_46 ,
V_25 -> V_126 , F_13 ( V_25 -> V_126 ) ) ;
F_21 ( 1 , L_103 , V_46 ,
V_25 -> V_128 , F_13 ( V_25 -> V_128 ) ) ;
F_21 ( 1 , L_104 , V_46 ,
V_25 -> V_130 , F_13 ( V_25 -> V_130 ) ) ;
F_21 ( 1 , L_105 , V_46 ,
V_25 -> V_132 , F_13 ( V_25 -> V_132 ) ) ;
F_21 ( 1 , L_106 , V_46 ,
V_25 -> V_134 , F_13 ( V_25 -> V_134 ) ) ;
F_21 ( 1 , L_107 , V_46 ,
V_25 -> V_138 , F_13 ( V_25 -> V_138 ) ) ;
}
int F_83 ( struct V_24 * V_25 ,
struct V_26 * V_27 ,
struct V_29 * V_30 )
{
struct V_1 * V_2 = V_25 -> V_2 ;
T_1 V_259 ;
F_21 ( 1 , L_108 , V_46 ,
V_2 -> V_260 , V_2 -> V_261 , V_2 -> V_262 ) ;
F_9 ( V_25 -> V_119 , V_25 -> V_103 ) ;
F_24 ( V_2 ,
& V_2 -> V_87 [ V_25 -> V_140 ] ,
V_25 -> V_263 , V_30 -> V_9 . V_64 ) ;
if ( V_264 > 5 ) {
F_27 ( V_2 ,
& V_2 -> V_87 [ V_25 -> V_140 ] ) ;
F_28 ( V_25 , & V_30 -> V_9 ) ;
}
F_25 ( V_25 -> V_120 , V_25 -> V_263 ) ;
if ( ( ! ( V_178 [ V_2 -> V_167 ] . V_206 & V_207 ) ) &&
( ! ( V_178 [ V_2 -> V_167 ] . V_210 & V_207 ) ) ) {
F_15 ( L_109 ,
V_46 ,
V_178 [ V_2 -> V_167 ] . V_206 ,
V_178 [ V_2 -> V_167 ] . V_210 ) ;
return - V_265 ;
}
if ( V_178 [ V_2 -> V_167 ] . V_206 == V_208 )
F_84 ( V_2 , 0 ) ;
F_85 ( 100 ) ;
if ( V_25 -> V_136 )
F_25 ( V_25 -> V_136 , V_25 -> V_266 ) ;
F_25 ( V_25 -> V_122 , V_25 -> V_106 ) ;
F_25 ( V_25 -> V_134 , V_25 -> V_267 ) ;
F_25 ( V_25 -> V_132 , V_25 -> V_105 ) ;
F_25 ( V_25 -> V_124 , V_25 -> V_268 ) ;
F_85 ( 100 ) ;
F_25 ( V_25 -> V_117 , 3 ) ;
V_27 -> V_28 = 0 ;
if ( V_178 [ V_2 -> V_167 ] . V_206 == V_207 ) {
V_259 = F_13 ( V_86 ) ;
V_259 &= ~ 0x3 ;
F_25 ( V_86 , V_259 ) ;
}
if ( V_178 [ V_2 -> V_167 ] . V_210 == V_207 ) {
V_259 = F_13 ( V_86 ) ;
V_259 &= ~ 0x4 ;
F_25 ( V_86 , V_259 ) ;
}
if ( V_178 [ V_2 -> V_167 ] . V_206 == V_208 ) {
V_259 = F_13 ( V_86 ) ;
V_259 = V_259 & ~ 0x1 ;
V_259 = V_259 | 0xa ;
F_25 ( V_86 , V_259 ) ;
F_25 ( V_85 , F_13 ( V_85 ) | 0x80000011 ) ;
F_25 ( V_257 , 0x10100045 ) ;
}
switch ( V_2 -> V_57 ) {
case V_97 :
case V_163 :
case V_269 :
F_21 ( 1 , L_110 , V_46 ) ;
F_5 ( V_25 -> V_138 , V_25 -> V_104 ) ;
F_5 ( V_25 -> V_119 , V_25 -> V_103 ) ;
F_1 ( V_2 , V_25 -> V_6 ) ;
F_7 ( V_2 ) ;
break;
default:
F_44 () ;
}
F_5 ( V_66 , ( 1 << 5 ) ) ;
if ( V_178 [ V_2 -> V_167 ] . V_206 == V_208 )
F_84 ( V_2 , 1 ) ;
if ( V_264 > 4 )
F_82 ( V_25 ) ;
return 0 ;
}
static int F_86 ( struct V_24 * V_25 )
{
struct V_1 * V_2 = V_25 -> V_2 ;
T_1 V_259 ;
F_21 ( 1 , L_64 , V_46 ) ;
F_9 ( V_25 -> V_138 , V_25 -> V_104 ) ;
F_9 ( V_25 -> V_119 , V_25 -> V_103 ) ;
if ( V_178 [ V_2 -> V_167 ] . V_206 == V_208 ) {
V_259 = F_13 ( V_86 ) ;
V_259 = V_259 | 0x1 ;
V_259 = V_259 & ~ 0xa ;
F_25 ( V_86 , V_259 ) ;
F_25 ( V_25 -> V_136 , 0 ) ;
F_25 ( V_25 -> V_124 , 8 ) ;
}
if ( V_178 [ V_2 -> V_167 ] . V_206 == V_208 )
F_84 ( V_2 , 0 ) ;
return 0 ;
}
int F_87 ( struct V_29 * V_30 , struct V_24 * V_25 )
{
struct V_1 * V_2 = V_25 -> V_2 ;
int V_65 = V_25 -> V_263 * V_25 -> V_270 ;
struct V_271 * V_272 = F_88 ( & V_30 -> V_34 , 0 ) ;
F_21 ( 1 , L_111 , V_46 , V_30 ) ;
if ( F_89 ( & V_30 -> V_34 , 0 ) < V_65 )
return - V_265 ;
F_90 ( & V_30 -> V_34 , 0 , V_65 ) ;
F_77 ( V_2 -> V_99 , & V_30 -> V_9 ,
V_272 -> V_273 ,
V_25 -> V_263 , V_25 -> V_270 , 0 ) ;
return 0 ;
}
void F_91 ( struct V_24 * V_25 , struct V_29 * V_30 )
{
struct V_29 * V_274 ;
struct V_1 * V_2 = V_25 -> V_2 ;
struct V_26 * V_275 = & V_25 -> V_109 ;
unsigned long V_4 ;
V_30 -> V_9 . V_63 [ 1 ] = F_30 ( V_30 -> V_9 . V_64 + 12 ) ;
V_30 -> V_9 . V_256 [ 0 ] = F_30 ( V_16 | V_247 ) ;
V_30 -> V_9 . V_256 [ 1 ] = F_30 ( V_30 -> V_9 . V_64 + 12 ) ;
V_30 -> V_9 . V_256 [ 2 ] = F_30 ( 0 ) ;
F_2 ( & V_2 -> V_107 , V_4 ) ;
if ( F_18 ( & V_275 -> V_31 ) ) {
F_92 ( & V_30 -> V_33 , & V_275 -> V_31 ) ;
F_21 ( 1 , L_112 ,
V_30 , V_30 -> V_34 . V_35 . V_38 , V_46 ) ;
} else {
V_30 -> V_9 . V_63 [ 0 ] |= F_30 ( V_246 ) ;
V_274 = F_19 ( V_275 -> V_31 . V_274 , struct V_29 ,
V_33 ) ;
F_92 ( & V_30 -> V_33 , & V_275 -> V_31 ) ;
V_274 -> V_9 . V_256 [ 1 ] = F_30 ( V_30 -> V_9 . V_64 ) ;
F_21 ( 1 , L_113 ,
V_30 , V_30 -> V_34 . V_35 . V_38 , V_46 ) ;
}
F_3 ( & V_2 -> V_107 , V_4 ) ;
}
static void F_93 ( struct V_24 * V_25 , char * V_276 )
{
struct V_1 * V_2 = V_25 -> V_2 ;
struct V_26 * V_27 = & V_25 -> V_109 ;
struct V_29 * V_30 ;
unsigned long V_4 ;
F_2 ( & V_25 -> V_107 , V_4 ) ;
while ( ! F_18 ( & V_27 -> V_31 ) ) {
V_30 = F_19 ( V_27 -> V_31 . V_32 , struct V_29 ,
V_33 ) ;
F_22 ( & V_30 -> V_33 ) ;
F_23 ( & V_30 -> V_34 , V_277 ) ;
F_21 ( 1 , L_114 ,
V_30 , V_30 -> V_34 . V_35 . V_38 , V_276 , ( unsigned long ) V_30 -> V_9 . V_64 ) ;
}
F_3 ( & V_25 -> V_107 , V_4 ) ;
}
void F_94 ( struct V_24 * V_25 )
{
struct V_1 * V_2 = V_25 -> V_2 ;
F_21 ( 1 , L_64 , V_46 ) ;
F_86 ( V_25 ) ;
F_93 ( V_25 , L_115 ) ;
}
int F_95 ( struct V_1 * V_2 , T_1 V_278 )
{
struct V_24 * V_25 = & V_2 -> V_209 ;
int V_28 = 0 ;
int V_279 = 0 ;
if ( V_278 == 0 )
return V_279 ;
V_28 = F_13 ( V_25 -> V_115 ) ;
F_21 ( 7 , L_116 ,
V_278 , F_13 ( V_25 -> V_138 ) , V_28 ) ;
if ( ( V_278 & V_280 ) ||
( V_278 & V_281 ) ||
( V_278 & V_282 ) ||
( V_278 & V_283 ) ||
( V_278 & V_284 ) ||
( V_278 & V_285 ) ||
( V_278 & V_286 ) ) {
F_15 ( V_100 L_117
L_118 , V_2 -> V_47 , V_278 ) ;
if ( V_278 & V_280 )
F_21 ( 1 , L_119 ) ;
if ( V_278 & V_281 )
F_21 ( 1 , L_120 ) ;
if ( V_278 & V_282 )
F_21 ( 1 , L_121 ) ;
if ( V_278 & V_283 )
F_21 ( 1 , L_122 ) ;
if ( V_278 & V_284 )
F_21 ( 1 , L_123 ) ;
if ( V_278 & V_285 )
F_21 ( 1 , L_124 ) ;
if ( V_278 & V_286 )
F_21 ( 1 , L_125 ) ;
F_9 ( V_25 -> V_119 , V_25 -> V_103 ) ;
F_27 ( V_2 ,
& V_2 -> V_87 [ V_25 -> V_140 ] ) ;
F_96 ( V_2 ) ;
} else if ( V_278 & V_287 ) {
F_21 ( 7 , L_126 ) ;
F_47 ( & V_25 -> V_107 ) ;
F_17 ( V_25 , & V_25 -> V_109 , V_28 ) ;
F_49 ( & V_25 -> V_107 ) ;
}
if ( V_278 ) {
F_25 ( V_25 -> V_139 , V_278 ) ;
V_279 = 1 ;
}
return V_279 ;
}
static int F_97 ( struct V_24 * V_25 , T_1 V_278 )
{
struct V_1 * V_2 = V_25 -> V_2 ;
int V_279 = 0 ;
T_1 V_28 ;
if ( ( V_278 & V_288 ) ||
( V_278 & V_289 ) ||
( V_278 & V_290 ) ||
( V_278 & V_291 ) ) {
if ( V_278 & V_288 )
F_21 ( 7 , L_127 ,
V_288 ) ;
if ( V_278 & V_289 )
F_21 ( 7 , L_128 ,
V_289 ) ;
if ( V_278 & V_290 )
F_21 ( 7 , L_129 ,
V_290 ) ;
if ( V_278 & V_291 )
F_21 ( 7 , L_130 ,
V_291 ) ;
F_15 ( V_100 L_131 , V_2 -> V_47 ) ;
F_9 ( V_25 -> V_119 , V_25 -> V_103 ) ;
F_27 ( V_2 ,
& V_2 -> V_87 [ V_25 -> V_140 ] ) ;
} else if ( V_278 & V_292 ) {
F_21 ( 7 , L_132 , V_292 ) ;
F_47 ( & V_25 -> V_107 ) ;
V_28 = F_13 ( V_25 -> V_115 ) ;
F_17 ( V_25 , & V_25 -> V_109 , V_28 ) ;
F_49 ( & V_25 -> V_107 ) ;
}
if ( V_278 ) {
F_25 ( V_25 -> V_139 , V_278 ) ;
V_279 = 1 ;
}
return V_279 ;
}
static T_3 F_98 ( int V_293 , void * V_294 )
{
struct V_1 * V_2 = V_294 ;
struct V_24 * V_209 = & V_2 -> V_209 ;
struct V_24 * V_211 = & V_2 -> V_211 ;
T_1 V_295 , V_296 ;
T_1 V_297 , V_298 ;
T_1 V_299 , V_300 ;
T_1 V_301 , V_302 ;
T_1 V_303 , V_304 ;
int V_305 = 0 , V_306 = 0 , V_307 = 0 , V_279 = 0 ;
int V_308 = 0 ;
bool V_309 ;
V_295 = F_13 ( V_79 ) ;
V_296 = F_12 ( V_2 ) ;
V_297 = F_13 ( V_80 ) ;
V_298 = F_13 ( V_74 ) ;
V_299 = F_13 ( V_83 ) ;
V_300 = F_13 ( V_77 ) ;
V_301 = F_13 ( V_81 ) ;
V_302 = F_13 ( V_75 ) ;
V_303 = F_13 ( V_82 ) ;
V_304 = F_13 ( V_76 ) ;
if ( ( V_295 == 0 ) && ( V_303 == 0 ) && ( V_301 == 0 ) )
goto V_310;
V_305 = F_13 ( V_311 ) ;
V_308 = F_13 ( V_312 ) ;
V_306 = F_13 ( V_209 -> V_115 ) ;
V_307 = F_13 ( V_211 -> V_115 ) ;
F_21 ( 7 , L_133 ,
V_295 , V_296 ) ;
F_21 ( 7 , L_134 ,
V_297 , V_298 , V_305 ) ;
F_21 ( 7 , L_135 ,
V_299 , V_300 , V_308 ) ;
F_21 ( 7 , L_136 ,
V_301 , V_302 , V_306 ) ;
F_21 ( 7 , L_137 ,
V_303 , V_304 , V_307 ) ;
if ( V_295 & ( V_313 | V_314 |
V_315 | V_316 | V_317 |
V_318 | V_319 | V_320 |
V_321 | V_322 |
V_323 | V_324 |
V_325 | V_326 ) ) {
if ( V_295 & V_313 )
F_21 ( 7 , L_138 ,
V_313 ) ;
if ( V_295 & V_314 )
F_21 ( 7 , L_139 ,
V_314 ) ;
if ( V_295 & V_315 )
F_21 ( 7 , L_140 ,
V_315 ) ;
if ( V_295 & V_316 )
F_21 ( 7 , L_141 ,
V_316 ) ;
if ( V_295 & V_317 )
F_21 ( 7 , L_142 ,
V_317 ) ;
if ( V_295 & V_318 )
F_21 ( 7 , L_143 ,
V_318 ) ;
if ( V_295 & V_319 )
F_21 ( 7 , L_144 ,
V_319 ) ;
if ( V_295 & V_320 )
F_21 ( 7 , L_145 ,
V_320 ) ;
if ( V_295 & V_321 )
F_21 ( 7 , L_146 ,
V_321 ) ;
if ( V_295 & V_322 )
F_21 ( 7 , L_147 ,
V_322 ) ;
if ( V_295 & V_323 )
F_21 ( 7 , L_148 ,
V_323 ) ;
if ( V_295 & V_324 )
F_21 ( 7 , L_149 ,
V_324 ) ;
if ( V_295 & V_325 )
F_21 ( 7 , L_150 ,
V_325 ) ;
if ( V_295 & V_326 )
F_21 ( 7 , L_151 ,
V_326 ) ;
}
if ( V_178 [ V_2 -> V_167 ] . V_228 == 1 &&
( V_295 & ( V_324 | V_323 ) ) )
V_279 += F_99 ( V_2 , V_295 ) ;
if ( V_178 [ V_2 -> V_167 ] . V_228 == 2 &&
( V_295 & V_323 ) )
V_279 += F_100 ( V_2 ) ;
if ( V_301 ) {
if ( V_178 [ V_2 -> V_167 ] . V_206 == V_207 )
V_279 += F_97 ( V_209 , V_301 ) ;
else
if ( V_178 [ V_2 -> V_167 ] . V_206 == V_208 )
V_279 += F_95 ( V_2 , V_301 ) ;
}
if ( V_303 ) {
if ( V_178 [ V_2 -> V_167 ] . V_210 == V_207 )
V_279 += F_97 ( V_211 , V_303 ) ;
else
if ( V_178 [ V_2 -> V_167 ] . V_210 == V_208 )
V_279 += F_95 ( V_2 , V_303 ) ;
}
if ( V_297 )
V_279 += F_101 ( V_2 , V_297 ) ;
if ( V_299 )
V_279 += F_102 ( V_2 , V_299 , V_300 ) ;
if ( V_295 & V_326 ) {
V_309 = false ;
F_103 ( V_2 -> V_327 , V_222 , V_328 ,
V_295 , & V_309 ) ;
if ( V_309 )
V_279 ++ ;
}
if ( ( V_295 & V_296 ) & V_325 ) {
F_8 ( V_2 , V_325 ) ;
F_104 ( & V_2 -> V_329 ) ;
V_279 ++ ;
}
if ( V_279 )
F_25 ( V_79 , V_295 ) ;
V_310:
return F_105 ( V_279 ) ;
}
static void F_106 ( struct V_154 * V_157 ,
unsigned int V_330 , void * V_331 )
{
struct V_1 * V_2 ;
if ( V_157 == NULL )
return;
V_2 = F_107 ( V_157 -> V_158 ) ;
switch ( V_330 ) {
case V_332 :
if ( V_157 == V_2 -> V_327 )
F_108 ( V_157 , * ( T_1 * ) V_331 ) ;
break;
case V_333 :
if ( V_157 == V_2 -> V_327 )
F_109 ( V_157 , * ( T_1 * ) V_331 ) ;
break;
}
}
static void F_110 ( struct V_1 * V_2 )
{
F_111 ( & V_2 -> V_329 , V_334 ) ;
F_111 ( & V_2 -> V_335 , V_336 ) ;
F_111 ( & V_2 -> V_337 , V_338 ) ;
V_2 -> V_158 . V_339 = F_106 ;
}
static inline int F_112 ( struct V_1 * V_2 )
{
return V_178 [ V_2 -> V_167 ] . V_206 == V_208 ;
}
static inline int F_113 ( struct V_1 * V_2 )
{
return V_178 [ V_2 -> V_167 ] . V_210 == V_208 ;
}
void F_114 ( struct V_1 * V_2 , T_1 V_3 )
{
if ( V_3 & 0x7 )
F_5 ( V_340 , V_3 & 0x7 ) ;
if ( V_3 & 0x0007fff8 ) {
if ( F_112 ( V_2 ) || F_113 ( V_2 ) )
F_15 ( V_100
L_152 ,
V_2 -> V_47 ) ;
F_5 ( V_341 , ( V_3 & 0x0007fff8 ) >> 3 ) ;
}
if ( V_3 & 0x00f80000 )
F_15 ( V_62 L_153 , V_2 -> V_47 ) ;
}
void F_115 ( struct V_1 * V_2 , T_1 V_3 )
{
if ( V_3 & 0x00000007 )
F_9 ( V_340 , V_3 & 0x7 ) ;
if ( V_3 & 0x0007fff8 ) {
if ( F_112 ( V_2 ) || F_113 ( V_2 ) )
F_15 ( V_100
L_154 ,
V_2 -> V_47 ) ;
F_9 ( V_341 , ( V_3 & 0x7fff8 ) >> 3 ) ;
}
if ( V_3 & 0x00f80000 )
F_15 ( V_62 L_153 , V_2 -> V_47 ) ;
}
T_1 F_116 ( struct V_1 * V_2 , T_1 V_3 )
{
if ( V_3 & 0x00000007 )
return ( F_13 ( V_340 ) >> 8 ) & V_3 & 0x7 ;
if ( V_3 & 0x0007fff8 ) {
if ( F_112 ( V_2 ) || F_113 ( V_2 ) )
F_15 ( V_100
L_155 ,
V_2 -> V_47 ) ;
return ( F_13 ( V_341 ) & ( ( V_3 & 0x7fff8 ) >> 3 ) ) << 3 ;
}
if ( V_3 & 0x00f80000 )
F_15 ( V_62 L_153 , V_2 -> V_47 ) ;
return 0 ;
}
void F_117 ( struct V_1 * V_2 , T_1 V_3 , int V_342 )
{
if ( ( V_3 & 0x00000007 ) && V_342 )
F_5 ( V_340 , ( V_3 & 0x7 ) << 16 ) ;
else if ( ( V_3 & 0x00000007 ) && ! V_342 )
F_9 ( V_340 , ( V_3 & 0x7 ) << 16 ) ;
if ( V_3 & 0x0007fff8 ) {
if ( F_112 ( V_2 ) || F_113 ( V_2 ) )
F_15 ( V_100
L_156 ,
V_2 -> V_47 ) ;
}
if ( ( V_3 & 0x0007fff8 ) && V_342 )
F_9 ( V_343 , ( V_3 & 0x7fff8 ) >> 3 ) ;
else if ( ( V_3 & 0x0007fff8 ) && ! V_342 )
F_5 ( V_343 , ( V_3 & 0x7fff8 ) >> 3 ) ;
}
static int F_118 ( struct V_249 * V_249 ,
const struct V_344 * V_345 )
{
struct V_1 * V_2 ;
struct V_346 * V_347 ;
int V_348 ;
V_2 = F_119 ( sizeof( * V_2 ) , V_349 ) ;
if ( NULL == V_2 )
return - V_255 ;
V_348 = F_120 ( & V_249 -> V_2 , & V_2 -> V_158 ) ;
if ( V_348 < 0 )
goto V_350;
V_347 = & V_2 -> V_351 ;
F_121 ( V_347 , 6 ) ;
if ( V_347 -> error ) {
V_348 = V_347 -> error ;
goto V_352;
}
V_2 -> V_158 . V_351 = V_347 ;
F_110 ( V_2 ) ;
V_2 -> V_99 = V_249 ;
if ( F_122 ( V_249 ) ) {
V_348 = - V_353 ;
goto V_352;
}
if ( F_50 ( V_2 ) < 0 ) {
V_348 = - V_265 ;
goto V_352;
}
V_2 -> V_354 = V_249 -> V_355 ;
F_123 ( V_249 , V_356 , & V_2 -> V_357 ) ;
F_15 ( V_62 L_157
L_158 , V_2 -> V_47 ,
F_124 ( V_249 ) , V_2 -> V_354 , V_249 -> V_293 ,
V_2 -> V_357 ,
( unsigned long long ) F_38 ( V_249 , 0 ) ) ;
F_125 ( V_249 ) ;
if ( ! F_126 ( V_249 , 0xffffffff ) ) {
F_15 ( L_159 , V_2 -> V_47 ) ;
V_348 = - V_353 ;
goto V_358;
}
V_2 -> V_359 = F_127 ( & V_249 -> V_2 ) ;
if ( F_128 ( V_2 -> V_359 ) ) {
V_348 = F_129 ( V_2 -> V_359 ) ;
goto V_358;
}
V_348 = F_130 ( V_249 -> V_293 , F_98 ,
V_360 , V_2 -> V_47 , V_2 ) ;
if ( V_348 < 0 ) {
F_15 ( V_100 L_160 ,
V_2 -> V_47 , V_249 -> V_293 ) ;
goto V_361;
}
switch ( V_2 -> V_167 ) {
case V_362 :
F_4 ( V_2 , V_324 | V_323 ) ;
break;
case V_363 :
F_4 ( V_2 , V_323 ) ;
break;
}
F_131 ( V_2 ) ;
F_132 ( V_2 ) ;
return 0 ;
V_361:
F_133 ( V_2 -> V_359 ) ;
V_358:
F_63 ( V_2 ) ;
V_352:
F_134 ( V_347 ) ;
F_135 ( & V_2 -> V_158 ) ;
V_350:
F_136 ( V_2 ) ;
return V_348 ;
}
static void F_137 ( struct V_249 * V_249 )
{
struct V_364 * V_158 = F_138 ( V_249 ) ;
struct V_1 * V_2 = F_107 ( V_158 ) ;
F_139 ( V_2 ) ;
F_140 ( V_2 ) ;
F_31 ( V_2 ) ;
F_141 ( V_249 -> V_293 , V_2 ) ;
F_142 ( V_249 ) ;
F_63 ( V_2 ) ;
F_133 ( V_2 -> V_359 ) ;
F_134 ( & V_2 -> V_351 ) ;
F_135 ( V_158 ) ;
F_136 ( V_2 ) ;
}
static int T_4 F_143 ( void )
{
F_15 ( V_62 L_161 ,
V_365 ) ;
return F_144 ( & V_366 ) ;
}
static void T_5 F_145 ( void )
{
F_146 ( & V_366 ) ;
}
