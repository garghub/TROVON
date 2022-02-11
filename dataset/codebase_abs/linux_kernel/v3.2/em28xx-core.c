int F_1 ( struct V_1 * V_2 , T_1 V_3 , T_2 V_4 ,
char * V_5 , int V_6 )
{
int V_7 ;
int V_8 = F_2 ( V_2 -> V_9 , 0 ) ;
if ( V_2 -> V_10 & V_11 )
return - V_12 ;
if ( V_6 > V_13 )
return - V_14 ;
if ( V_15 ) {
F_3 ( V_16 L_1
L_2 ,
V_8 ,
V_17 | V_18 | V_19 ,
V_3 , 0 , 0 ,
V_4 & 0xff , V_4 >> 8 ,
V_6 & 0xff , V_6 >> 8 ) ;
}
F_4 ( & V_2 -> V_20 ) ;
V_7 = F_5 ( V_2 -> V_9 , V_8 , V_3 ,
V_17 | V_18 | V_19 ,
0x0000 , V_4 , V_2 -> V_21 , V_6 , V_22 ) ;
if ( V_7 < 0 ) {
if ( V_15 )
F_3 ( L_3 ) ;
F_6 ( & V_2 -> V_20 ) ;
return V_7 ;
}
if ( V_6 )
memcpy ( V_5 , V_2 -> V_21 , V_6 ) ;
F_6 ( & V_2 -> V_20 ) ;
if ( V_15 ) {
int V_23 ;
F_3 ( L_4 ) ;
for ( V_23 = 0 ; V_23 < V_6 ; V_23 ++ )
F_3 ( L_5 , ( unsigned char ) V_5 [ V_23 ] ) ;
F_3 ( L_6 ) ;
}
return V_7 ;
}
int F_7 ( struct V_1 * V_2 , T_1 V_3 , T_2 V_4 )
{
int V_7 ;
T_1 V_24 ;
V_7 = F_1 ( V_2 , V_3 , V_4 , & V_24 , 1 ) ;
if ( V_7 < 0 )
return V_7 ;
return V_24 ;
}
int F_8 ( struct V_1 * V_2 , T_2 V_4 )
{
return F_7 ( V_2 , V_25 , V_4 ) ;
}
int F_9 ( struct V_1 * V_2 , T_1 V_3 , T_2 V_4 , char * V_5 ,
int V_6 )
{
int V_7 ;
int V_8 = F_10 ( V_2 -> V_9 , 0 ) ;
if ( V_2 -> V_10 & V_11 )
return - V_12 ;
if ( ( V_6 < 1 ) || ( V_6 > V_13 ) )
return - V_14 ;
if ( V_15 ) {
int V_23 ;
F_3 ( V_16 L_1
L_7 ,
V_8 ,
V_26 | V_18 | V_19 ,
V_3 , 0 , 0 ,
V_4 & 0xff , V_4 >> 8 ,
V_6 & 0xff , V_6 >> 8 ) ;
for ( V_23 = 0 ; V_23 < V_6 ; V_23 ++ )
F_3 ( L_5 , ( unsigned char ) V_5 [ V_23 ] ) ;
F_3 ( L_6 ) ;
}
F_4 ( & V_2 -> V_20 ) ;
memcpy ( V_2 -> V_21 , V_5 , V_6 ) ;
V_7 = F_5 ( V_2 -> V_9 , V_8 , V_3 ,
V_26 | V_18 | V_19 ,
0x0000 , V_4 , V_2 -> V_21 , V_6 , V_22 ) ;
F_6 ( & V_2 -> V_20 ) ;
if ( V_2 -> V_27 )
F_11 ( V_2 -> V_27 ) ;
return V_7 ;
}
int F_12 ( struct V_1 * V_2 , T_2 V_4 , char * V_5 , int V_6 )
{
int V_28 ;
V_28 = F_9 ( V_2 , V_25 , V_4 , V_5 , V_6 ) ;
if ( V_28 >= 0 ) {
if ( V_4 == V_2 -> V_29 )
V_2 -> V_30 = V_5 [ 0 ] ;
else if ( V_4 == V_2 -> V_31 )
V_2 -> V_32 = V_5 [ 0 ] ;
}
return V_28 ;
}
int F_13 ( struct V_1 * V_2 , T_2 V_4 , T_1 V_24 )
{
return F_12 ( V_2 , V_4 , & V_24 , 1 ) ;
}
int F_14 ( struct V_1 * V_2 , T_2 V_4 , T_1 V_24 ,
T_1 V_33 )
{
int V_34 ;
T_1 V_35 ;
if ( V_4 == V_2 -> V_29 )
V_34 = V_2 -> V_30 ;
else if ( V_4 == V_2 -> V_31 )
V_34 = V_2 -> V_32 ;
else
V_34 = F_8 ( V_2 , V_4 ) ;
if ( V_34 < 0 )
return V_34 ;
V_35 = ( ( ( T_1 ) V_34 ) & ~ V_33 ) | ( V_24 & V_33 ) ;
return F_12 ( V_2 , V_4 , & V_35 , 1 ) ;
}
static int F_15 ( struct V_1 * V_2 )
{
int V_7 , V_36 ;
for ( V_36 = 0 ; V_36 < 10 ; V_36 ++ , F_11 ( 5 ) ) {
V_7 = F_8 ( V_2 , V_37 ) ;
if ( V_7 < 0 )
return V_7 ;
if ( ! ( V_7 & 0x01 ) )
return 0 ;
}
F_16 ( L_8 ) ;
return - V_38 ;
}
int F_17 ( struct V_1 * V_2 , T_1 V_4 )
{
int V_7 ;
T_1 V_39 = ( V_4 & 0x7f ) | 0x80 ;
T_2 V_24 ;
V_7 = F_15 ( V_2 ) ;
if ( V_7 < 0 )
return V_7 ;
V_7 = F_12 ( V_2 , V_40 , & V_39 , 1 ) ;
if ( V_7 < 0 )
return V_7 ;
V_7 = V_2 -> F_1 ( V_2 , 0 , V_41 ,
( T_1 * ) & V_24 , sizeof( V_24 ) ) ;
if ( V_7 < 0 )
return V_7 ;
return F_18 ( V_24 ) ;
}
int F_19 ( struct V_1 * V_2 , T_1 V_4 , T_2 V_24 )
{
int V_7 ;
T_1 V_39 = V_4 & 0x7f ;
T_3 V_42 ;
V_42 = F_20 ( V_24 ) ;
V_7 = F_15 ( V_2 ) ;
if ( V_7 < 0 )
return V_7 ;
V_7 = F_12 ( V_2 , V_41 , ( T_1 * ) & V_42 , 2 ) ;
if ( V_7 < 0 )
return V_7 ;
V_7 = F_12 ( V_2 , V_40 , & V_39 , 1 ) ;
if ( V_7 < 0 )
return V_7 ;
return 0 ;
}
static int F_21 ( struct V_1 * V_2 )
{
int V_7 , V_36 ;
enum V_43 V_44 = V_2 -> V_45 ;
if ( V_44 == V_46 )
V_44 = V_47 ;
for ( V_36 = 0 ; V_36 < F_22 ( V_48 ) ; V_36 ++ ) {
if ( V_44 == V_48 [ V_36 ] . V_49 )
V_7 = F_19 ( V_2 , V_48 [ V_36 ] . V_4 , 0x0808 ) ;
else
V_7 = F_19 ( V_2 , V_48 [ V_36 ] . V_4 , 0x8000 ) ;
if ( V_7 < 0 )
F_16 ( L_9 ,
V_48 [ V_36 ] . V_4 ) ;
}
return 0 ;
}
static int F_23 ( struct V_1 * V_2 )
{
int V_7 ;
T_1 V_50 ;
if ( V_2 -> V_51 . V_52 ) {
if ( V_2 -> V_45 == V_47 )
V_50 = V_53 ;
else
V_50 = V_54 ;
V_7 = F_12 ( V_2 , V_55 , & V_50 , 1 ) ;
if ( V_7 < 0 )
return V_7 ;
}
if ( V_2 -> V_51 . V_56 )
V_50 = V_57 ;
else {
switch ( V_2 -> V_45 ) {
case V_47 :
V_50 = V_57 ;
break;
default:
V_50 = V_58 ;
break;
}
}
if ( V_2 -> V_51 . V_59 && V_2 -> V_60 )
F_24 ( V_2 , V_2 -> V_51 . V_59 ) ;
else
F_24 ( V_2 , F_25 ( V_2 -> V_61 ) -> V_62 ) ;
V_7 = F_14 ( V_2 , V_63 , V_50 , 0xc0 ) ;
if ( V_7 < 0 )
return V_7 ;
F_11 ( 5 ) ;
switch ( V_2 -> V_64 . V_65 ) {
case V_66 :
break;
default:
V_7 = F_21 ( V_2 ) ;
}
return V_7 ;
}
int F_26 ( struct V_1 * V_2 )
{
int V_7 , V_36 ;
T_1 V_67 ;
if ( ! V_2 -> V_64 . V_68 )
return 0 ;
if ( V_2 -> V_64 . V_65 != V_66 ) {
for ( V_36 = 0 ; V_36 < F_22 ( V_69 ) ; V_36 ++ ) {
V_7 = F_19 ( V_2 , V_69 [ V_36 ] . V_4 , 0x8000 ) ;
if ( V_7 < 0 )
F_16 ( L_9 ,
V_69 [ V_36 ] . V_4 ) ;
}
}
V_67 = V_2 -> V_51 . V_67 & 0x7f ;
if ( ! V_2 -> V_60 )
V_67 |= V_70 ;
V_7 = F_13 ( V_2 , V_71 , V_67 ) ;
if ( V_7 < 0 )
return V_7 ;
F_11 ( 10 ) ;
V_7 = F_23 ( V_2 ) ;
if ( V_2 -> V_64 . V_65 != V_66 ) {
int V_72 ;
F_19 ( V_2 , V_73 , 0x4200 ) ;
F_19 ( V_2 , V_74 , 0x0031 ) ;
F_19 ( V_2 , V_75 , 0xbb80 ) ;
V_72 = ( 0x1f - V_2 -> V_76 ) | ( ( 0x1f - V_2 -> V_76 ) << 8 ) ;
if ( V_2 -> V_60 )
V_72 |= 0x8000 ;
for ( V_36 = 0 ; V_36 < F_22 ( V_69 ) ; V_36 ++ ) {
if ( V_2 -> V_77 & V_69 [ V_36 ] . V_49 )
V_7 = F_19 ( V_2 , V_69 [ V_36 ] . V_4 ,
V_72 ) ;
if ( V_7 < 0 )
F_16 ( L_9 ,
V_69 [ V_36 ] . V_4 ) ;
}
if ( V_2 -> V_77 & V_78 ) {
int V_79 = F_27 ( V_2 -> V_77 ) ;
V_79 |= ( V_79 << 8 ) ;
F_19 ( V_2 , V_80 , V_79 ) ;
}
}
return V_7 ;
}
int F_28 ( struct V_1 * V_2 )
{
int V_81 , V_82 , V_83 , V_84 ;
T_4 V_85 ;
if ( V_2 -> V_86 == V_87 || V_2 -> V_86 == V_88
|| V_2 -> V_86 == V_89 ) {
V_2 -> V_64 . V_68 = false ;
V_2 -> V_90 = false ;
V_2 -> V_91 = false ;
return 0 ;
}
V_2 -> V_64 . V_68 = true ;
V_84 = F_8 ( V_2 , V_92 ) ;
F_29 ( L_10 , V_84 ) ;
if ( V_84 < 0 ) {
V_84 = V_93 ;
} else if ( ( V_84 & V_94 ) == 0x00 ) {
V_2 -> V_91 = false ;
V_2 -> V_64 . V_68 = false ;
return 0 ;
} else if ( ( V_84 & V_94 ) ==
V_95 ) {
F_29 ( L_11 ) ;
V_2 -> V_64 . V_96 = 1 ;
} else if ( ( V_84 & V_94 ) ==
V_97 ) {
F_29 ( L_12 ) ;
V_2 -> V_64 . V_98 = 1 ;
}
if ( ( V_84 & V_94 ) != V_93 ) {
V_2 -> V_64 . V_65 = V_66 ;
goto V_99;
}
V_2 -> V_64 . V_65 = V_100 ;
V_81 = F_17 ( V_2 , V_101 ) ;
if ( V_81 < 0 ) {
F_16 ( L_13 ) ;
V_2 -> V_64 . V_65 = V_66 ;
V_2 -> V_91 = false ;
V_2 -> V_64 . V_68 = false ;
goto V_99;
}
V_82 = F_17 ( V_2 , V_102 ) ;
if ( V_82 < 0 )
goto V_99;
V_85 = V_81 << 16 | V_82 ;
V_2 -> V_64 . V_103 = V_85 ;
F_16 ( L_14 , V_85 ) ;
V_83 = F_17 ( V_2 , V_104 ) ;
if ( V_83 < 0 )
goto V_99;
V_2 -> V_64 . V_105 = V_83 ;
F_16 ( L_15 , V_83 ) ;
if ( ( V_85 == 0xffffffff ) && ( V_83 == 0x6a90 ) )
V_2 -> V_64 . V_65 = V_106 ;
else if ( ( V_85 >> 8 ) == 0x838476 )
V_2 -> V_64 . V_65 = V_107 ;
V_99:
switch ( V_2 -> V_64 . V_65 ) {
case V_66 :
F_29 ( L_16 ) ;
break;
case V_106 :
F_29 ( L_17 ) ;
break;
case V_107 :
F_29 ( L_18 ,
V_2 -> V_64 . V_103 & 0xff ) ;
break;
case V_100 :
F_16 ( L_19 ) ;
break;
default:
break;
}
return F_26 ( V_2 ) ;
}
int F_30 ( struct V_1 * V_2 )
{
F_13 ( V_2 , V_108 , 0x10 ) ;
F_13 ( V_2 , V_109 , 0x00 ) ;
F_13 ( V_2 , V_110 , 0x10 ) ;
F_13 ( V_2 , V_111 , 0x00 ) ;
F_13 ( V_2 , V_112 , 0x00 ) ;
F_13 ( V_2 , V_113 , 0x00 ) ;
F_13 ( V_2 , V_114 , 0x20 ) ;
F_13 ( V_2 , V_115 , 0x20 ) ;
F_13 ( V_2 , V_116 , 0x20 ) ;
F_13 ( V_2 , V_117 , 0x20 ) ;
F_13 ( V_2 , V_118 , 0x00 ) ;
F_13 ( V_2 , V_119 , 0x00 ) ;
return F_13 ( V_2 , V_120 , 0x00 ) ;
}
int F_31 ( struct V_1 * V_2 , int V_121 )
{
int V_28 ;
if ( V_2 -> V_86 == V_88 ||
V_2 -> V_86 == V_122 ||
V_2 -> V_86 == V_89 ) {
if ( ! V_121 ) {
V_28 = F_14 ( V_2 , V_123 ,
0x00 ,
V_124 ) ;
return V_28 ;
}
V_28 = F_14 ( V_2 , V_123 ,
V_124 ,
V_124 ) ;
return V_28 ;
}
V_28 = F_14 ( V_2 , V_125 ,
V_121 ? 0x10 : 0x00 , 0x10 ) ;
if ( V_28 < 0 )
return V_28 ;
if ( ! V_121 ) {
V_28 = F_13 ( V_2 , V_126 , 0x27 ) ;
return V_28 ;
}
if ( V_2 -> V_51 . V_127 )
V_28 = F_13 ( V_2 , 0x13 , 0x0c ) ;
V_28 = F_13 ( V_2 , 0x48 , 0x00 ) ;
if ( V_2 -> V_128 == V_129 )
V_28 = F_13 ( V_2 , V_126 , 0x67 ) ;
else
V_28 = F_13 ( V_2 , V_126 , 0x37 ) ;
F_11 ( 6 ) ;
return V_28 ;
}
int F_32 ( struct V_1 * V_2 )
{
if ( V_130 == 1 )
return 0 ;
if ( V_2 -> V_86 == V_131 ||
V_2 -> V_86 == V_132 )
return 1 ;
return 0 ;
}
int F_33 ( struct V_1 * V_2 )
{
int V_7 ;
T_1 V_133 ;
V_7 = F_14 ( V_2 , V_134 ,
V_2 -> V_135 -> V_4 | 0x20 , 0xff ) ;
if ( V_7 < 0 )
return V_7 ;
V_7 = F_13 ( V_2 , V_136 , V_2 -> V_137 ) ;
if ( V_7 < 0 )
return V_7 ;
V_133 = V_2 -> V_138 ;
if ( F_32 ( V_2 ) == 1 ) {
V_133 |= V_139 ;
F_13 ( V_2 , V_140 , 0x00 ) ;
F_13 ( V_2 , V_141 , V_2 -> V_142 / 4 ) ;
F_13 ( V_2 , V_143 , V_2 -> V_144 ) ;
if ( V_2 -> V_145 & V_146 ) {
F_13 ( V_2 , V_147 , 0x09 ) ;
} else if ( V_2 -> V_145 & V_148 ) {
F_13 ( V_2 , V_147 , 0x07 ) ;
}
}
return F_13 ( V_2 , V_149 , V_133 ) ;
}
static int F_34 ( struct V_1 * V_2 , T_1 V_150 , T_1 V_151 ,
T_1 V_152 , T_1 V_153 )
{
F_35 ( L_20 ,
V_150 , V_152 , V_151 , V_153 ) ;
F_12 ( V_2 , V_154 , & V_150 , 1 ) ;
F_12 ( V_2 , V_155 , & V_151 , 1 ) ;
F_12 ( V_2 , V_156 , & V_152 , 1 ) ;
return F_12 ( V_2 , V_157 , & V_153 , 1 ) ;
}
static int F_36 ( struct V_1 * V_2 , T_1 V_158 , T_1 V_159 ,
T_2 V_160 , T_2 V_161 )
{
T_1 V_162 = V_160 ;
T_1 V_163 = V_161 ;
T_1 V_164 = ( V_161 >> 7 & 0x02 ) | ( V_160 >> 8 & 0x01 ) ;
F_35 ( L_21 ,
( V_160 | ( V_164 & 2 ) << 7 ) ,
( V_161 | ( V_164 & 1 ) << 8 ) ) ;
F_12 ( V_2 , V_165 , & V_158 , 1 ) ;
F_12 ( V_2 , V_166 , & V_159 , 1 ) ;
F_12 ( V_2 , V_167 , & V_162 , 1 ) ;
F_12 ( V_2 , V_168 , & V_163 , 1 ) ;
return F_12 ( V_2 , V_169 , & V_164 , 1 ) ;
}
static int F_37 ( struct V_1 * V_2 , T_2 V_170 , T_2 V_171 )
{
T_1 V_128 ;
if ( V_2 -> V_51 . V_52 ) {
V_128 = ( V_171 ? 0x20 : 0x00 ) | ( V_170 ? 0x10 : 0x00 ) ;
} else {
T_1 V_5 [ 2 ] ;
V_5 [ 0 ] = V_170 ;
V_5 [ 1 ] = V_170 >> 8 ;
F_12 ( V_2 , V_172 , ( char * ) V_5 , 2 ) ;
V_5 [ 0 ] = V_171 ;
V_5 [ 1 ] = V_171 >> 8 ;
F_12 ( V_2 , V_173 , ( char * ) V_5 , 2 ) ;
V_128 = ( V_170 || V_171 ) ? 0x30 : 0x00 ;
}
return F_14 ( V_2 , V_174 , V_128 , 0x30 ) ;
}
int F_38 ( struct V_1 * V_2 )
{
int V_160 , V_161 ;
V_160 = F_39 ( V_2 ) ;
V_161 = F_40 ( V_2 ) ;
V_2 -> V_142 = 720 ;
if ( V_2 -> V_145 & V_146 )
V_2 -> V_144 = 12 ;
else
V_2 -> V_144 = 18 ;
if ( ! V_2 -> V_175 )
V_161 >>= F_40 ( V_2 ) ;
F_33 ( V_2 ) ;
F_34 ( V_2 , 1 , ( V_160 - 4 ) >> 2 , 1 , ( V_161 - 4 ) >> 2 ) ;
if ( F_32 ( V_2 ) == 1 )
F_36 ( V_2 , 0 , 2 , V_160 >> 2 , V_161 >> 2 ) ;
else
F_36 ( V_2 , 0 , 0 , V_160 >> 2 , V_161 >> 2 ) ;
return F_37 ( V_2 , V_2 -> V_176 , V_2 -> V_177 ) ;
}
int F_41 ( struct V_1 * V_2 )
{
int V_178 , V_179 = V_2 -> V_180 ;
int V_36 ;
unsigned int V_181 = V_2 -> V_160 * 2 + 4 ;
if ( V_180 && V_180 < V_2 -> V_182 ) {
F_35 ( L_22 , V_2 -> V_180 ) ;
V_2 -> V_180 = V_180 ;
goto V_183;
}
if ( V_2 -> V_160 * 2 * V_2 -> V_161 > 720 * 240 * 2 )
V_181 *= 2 ;
for ( V_36 = 0 ; V_36 < V_2 -> V_182 ; V_36 ++ ) {
if ( V_2 -> V_184 [ V_36 ] >= V_181 ) {
V_2 -> V_180 = V_36 ;
break;
} else if ( V_2 -> V_184 [ V_36 ] >
V_2 -> V_184 [ V_2 -> V_180 ] )
V_2 -> V_180 = V_36 ;
}
V_183:
if ( V_2 -> V_180 != V_179 ) {
F_35 ( L_23 ,
V_181 , V_2 -> V_180 ) ;
V_2 -> V_185 = V_2 -> V_184 [ V_2 -> V_180 ] ;
F_35 ( L_24 ,
V_2 -> V_180 , V_2 -> V_185 ) ;
V_178 = F_42 ( V_2 -> V_9 , 0 , V_2 -> V_180 ) ;
if ( V_178 < 0 ) {
F_43 ( L_25 ,
V_2 -> V_180 , V_178 ) ;
return V_178 ;
}
}
return 0 ;
}
int F_24 ( struct V_1 * V_2 , struct V_186 * V_62 )
{
int V_28 = 0 ;
if ( ! V_62 )
return V_28 ;
if ( V_2 -> V_128 != V_187 ) {
F_13 ( V_2 , 0x48 , 0x00 ) ;
if ( V_2 -> V_128 == V_129 )
F_13 ( V_2 , V_126 , 0x67 ) ;
else
F_13 ( V_2 , V_126 , 0x37 ) ;
F_11 ( 6 ) ;
}
while ( V_62 -> V_188 >= 0 ) {
if ( V_62 -> V_4 >= 0 ) {
V_28 = F_14 ( V_2 ,
V_62 -> V_4 ,
V_62 -> V_24 ,
V_62 -> V_189 ) ;
if ( V_28 < 0 )
return V_28 ;
}
if ( V_62 -> V_188 > 0 )
F_11 ( V_62 -> V_188 ) ;
V_62 ++ ;
}
return V_28 ;
}
int F_44 ( struct V_1 * V_2 , enum V_190 V_191 )
{
if ( V_2 -> V_128 == V_191 )
return 0 ;
if ( V_191 == V_187 ) {
V_2 -> V_128 = V_191 ;
return F_24 ( V_2 , V_2 -> V_51 . V_192 ) ;
}
V_2 -> V_128 = V_191 ;
if ( V_2 -> V_128 == V_193 )
return F_24 ( V_2 , V_2 -> V_51 . V_194 ) ;
else
return F_24 ( V_2 , F_25 ( V_2 -> V_61 ) -> V_62 ) ;
}
static void F_45 ( struct V_195 * V_195 )
{
struct V_1 * V_2 = V_195 -> V_196 ;
int V_36 ;
switch ( V_195 -> V_197 ) {
case 0 :
case - V_198 :
break;
case - V_199 :
case - V_200 :
case - V_201 :
return;
default:
F_46 ( L_26 , V_195 -> V_197 ) ;
break;
}
F_47 ( & V_2 -> V_202 ) ;
V_2 -> V_203 . V_204 ( V_2 , V_195 ) ;
F_48 ( & V_2 -> V_202 ) ;
for ( V_36 = 0 ; V_36 < V_195 -> V_205 ; V_36 ++ ) {
V_195 -> V_206 [ V_36 ] . V_197 = 0 ;
V_195 -> V_206 [ V_36 ] . V_207 = 0 ;
}
V_195 -> V_197 = 0 ;
V_195 -> V_197 = F_49 ( V_195 , V_208 ) ;
if ( V_195 -> V_197 ) {
F_46 ( L_27 ,
V_195 -> V_197 ) ;
}
}
void F_50 ( struct V_1 * V_2 )
{
struct V_195 * V_195 ;
int V_36 ;
F_46 ( L_28 ) ;
V_2 -> V_203 . V_209 = - 1 ;
for ( V_36 = 0 ; V_36 < V_2 -> V_203 . V_210 ; V_36 ++ ) {
V_195 = V_2 -> V_203 . V_195 [ V_36 ] ;
if ( V_195 ) {
if ( ! F_51 () )
F_52 ( V_195 ) ;
else
F_53 ( V_195 ) ;
if ( V_2 -> V_203 . V_211 [ V_36 ] ) {
F_54 ( V_2 -> V_9 ,
V_195 -> V_212 ,
V_2 -> V_203 . V_211 [ V_36 ] ,
V_195 -> V_213 ) ;
}
F_55 ( V_195 ) ;
V_2 -> V_203 . V_195 [ V_36 ] = NULL ;
}
V_2 -> V_203 . V_211 [ V_36 ] = NULL ;
}
F_56 ( V_2 -> V_203 . V_195 ) ;
F_56 ( V_2 -> V_203 . V_211 ) ;
V_2 -> V_203 . V_195 = NULL ;
V_2 -> V_203 . V_211 = NULL ;
V_2 -> V_203 . V_210 = 0 ;
F_31 ( V_2 , 0 ) ;
}
int F_57 ( struct V_1 * V_2 , int V_214 ,
int V_210 , int V_185 ,
int (* V_204) ( struct V_1 * V_2 , struct V_195 * V_195 ) )
{
struct V_215 * V_216 = & V_2 -> V_217 ;
struct V_215 * V_218 = & V_2 -> V_219 ;
int V_36 ;
int V_220 , V_8 ;
struct V_195 * V_195 ;
int V_221 , V_222 ;
int V_28 ;
F_46 ( L_29 ) ;
F_50 ( V_2 ) ;
V_2 -> V_203 . V_204 = V_204 ;
V_2 -> V_203 . V_210 = V_210 ;
V_2 -> V_203 . V_195 = F_58 ( sizeof( void * ) * V_210 , V_223 ) ;
if ( ! V_2 -> V_203 . V_195 ) {
F_43 ( L_30 ) ;
return - V_224 ;
}
V_2 -> V_203 . V_211 = F_58 ( sizeof( void * ) * V_210 ,
V_223 ) ;
if ( ! V_2 -> V_203 . V_211 ) {
F_43 ( L_31 ) ;
F_56 ( V_2 -> V_203 . V_195 ) ;
return - V_224 ;
}
V_2 -> V_203 . V_185 = V_185 ;
V_2 -> V_203 . V_225 = NULL ;
V_2 -> V_203 . V_226 = NULL ;
V_220 = V_214 * V_2 -> V_203 . V_185 ;
for ( V_36 = 0 ; V_36 < V_2 -> V_203 . V_210 ; V_36 ++ ) {
V_195 = F_59 ( V_214 , V_223 ) ;
if ( ! V_195 ) {
F_60 ( L_32 , V_36 ) ;
F_50 ( V_2 ) ;
return - V_224 ;
}
V_2 -> V_203 . V_195 [ V_36 ] = V_195 ;
V_2 -> V_203 . V_211 [ V_36 ] = F_61 ( V_2 -> V_9 ,
V_220 , V_223 , & V_195 -> V_213 ) ;
if ( ! V_2 -> V_203 . V_211 [ V_36 ] ) {
F_60 ( L_33
L_34 ,
V_220 , V_36 ,
F_62 () ? L_35 : L_36 ) ;
F_50 ( V_2 ) ;
return - V_224 ;
}
memset ( V_2 -> V_203 . V_211 [ V_36 ] , 0 , V_220 ) ;
V_8 = F_63 ( V_2 -> V_9 ,
V_2 -> V_128 == V_129 ? 0x82 : 0x84 ) ;
F_64 ( V_195 , V_2 -> V_9 , V_8 ,
V_2 -> V_203 . V_211 [ V_36 ] , V_220 ,
F_45 , V_2 , 1 ) ;
V_195 -> V_205 = V_214 ;
V_195 -> V_227 = V_228 | V_229 ;
V_222 = 0 ;
for ( V_221 = 0 ; V_221 < V_214 ; V_221 ++ ) {
V_195 -> V_206 [ V_221 ] . V_230 = V_222 ;
V_195 -> V_206 [ V_221 ] . V_231 =
V_2 -> V_203 . V_185 ;
V_222 += V_2 -> V_203 . V_185 ;
}
}
F_65 ( & V_216 -> V_232 ) ;
F_65 ( & V_218 -> V_232 ) ;
F_31 ( V_2 , 1 ) ;
for ( V_36 = 0 ; V_36 < V_2 -> V_203 . V_210 ; V_36 ++ ) {
V_28 = F_49 ( V_2 -> V_203 . V_195 [ V_36 ] , V_208 ) ;
if ( V_28 ) {
F_60 ( L_37 , V_36 ,
V_28 ) ;
F_50 ( V_2 ) ;
return V_28 ;
}
}
return 0 ;
}
int F_66 ( struct V_1 * V_2 )
{
unsigned int V_233 ;
unsigned int V_234 ;
switch ( V_2 -> V_86 ) {
case V_235 :
case V_236 :
case V_237 :
case V_238 :
case V_239 :
case V_131 :
return - V_14 ;
case V_87 :
case V_132 :
V_233 = F_8 ( V_2 , V_240 ) ;
switch ( V_233 & V_241 ) {
case V_242 :
V_234 = 188 ;
break;
case V_243 :
V_234 = 376 ;
break;
case V_244 :
V_234 = 564 ;
break;
case V_245 :
V_234 = 752 ;
break;
}
break;
case V_88 :
V_234 = 564 ;
break;
case V_122 :
case V_89 :
default:
V_234 = 752 ;
}
return V_234 ;
}
void F_67 ( struct V_1 * V_2 )
{
F_68 ( & V_2 -> V_246 , 0 , V_247 , V_248 , 0 ) ;
F_68 ( & V_2 -> V_246 , 0 , V_249 , V_250 ,
F_25 ( V_2 -> V_61 ) -> V_251 , 0 , 0 ) ;
F_68 ( & V_2 -> V_246 , 0 , V_249 , V_252 , 0 ) ;
}
int F_69 ( struct V_253 * V_254 )
{
struct V_1 * V_2 = NULL ;
F_4 ( & V_255 ) ;
F_70 ( & V_254 -> V_256 , & V_257 ) ;
F_71 (dev, &em28xx_devlist, devlist) {
V_254 -> V_258 ( V_2 ) ;
}
F_6 ( & V_255 ) ;
F_3 ( V_259 L_38 , V_254 -> V_260 ) ;
return 0 ;
}
void F_72 ( struct V_253 * V_254 )
{
struct V_1 * V_2 = NULL ;
F_4 ( & V_255 ) ;
F_71 (dev, &em28xx_devlist, devlist) {
V_254 -> V_261 ( V_2 ) ;
}
F_73 ( & V_254 -> V_256 ) ;
F_6 ( & V_255 ) ;
F_3 ( V_259 L_39 , V_254 -> V_260 ) ;
}
void F_74 ( struct V_1 * V_2 )
{
const struct V_253 * V_254 = NULL ;
F_4 ( & V_255 ) ;
F_70 ( & V_2 -> V_262 , & V_263 ) ;
F_71 (ops, &em28xx_extension_devlist, next) {
if ( V_254 -> V_258 )
V_254 -> V_258 ( V_2 ) ;
}
F_6 ( & V_255 ) ;
}
void F_75 ( struct V_1 * V_2 )
{
const struct V_253 * V_254 = NULL ;
F_4 ( & V_255 ) ;
F_71 (ops, &em28xx_extension_devlist, next) {
if ( V_254 -> V_261 )
V_254 -> V_261 ( V_2 ) ;
}
F_73 ( & V_2 -> V_262 ) ;
F_6 ( & V_255 ) ;
}
