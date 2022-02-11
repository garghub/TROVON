static int F_1 ( T_1 V_1 )
{
int V_2 , V_3 ;
V_2 = 2 ;
if ( V_1 & V_4 )
V_2 ++ ;
if ( V_1 & V_5 )
V_2 ++ ;
if ( V_1 & ( 0x7 << V_6 ) )
V_2 += ( V_1 >> V_6 ) & 0x7 ;
if ( V_1 & V_7 )
V_2 ++ ;
if ( V_1 & V_8 )
V_2 += 3 ;
if ( V_1 & V_9 )
V_2 ++ ;
if ( V_1 & V_10 )
V_2 ++ ;
if ( V_1 & V_11 )
V_2 ++ ;
if ( V_1 & V_12 )
V_2 ++ ;
for ( V_3 = 0 ; V_3 < 8 ; V_3 ++ ) {
int V_13 = ( V_1 >> ( 11 + 2 * V_3 ) ) & 0x3 ;
switch ( V_13 ) {
case 0 : break;
case 1 : V_2 ++ ; break;
case 2 : V_2 += 3 ; break;
case 3 : V_2 += 4 ; break;
}
}
if ( V_1 & V_14 )
V_2 += 2 ;
if ( V_1 & V_15 )
V_2 ++ ;
if ( V_1 & V_16 )
V_2 ++ ;
if ( V_1 & V_17 )
V_2 += 3 ;
return V_2 ;
}
struct V_18 * F_2 ( struct V_19 * V_20 ,
T_2 V_21 ,
T_2 V_22 ,
unsigned V_23 ,
struct V_24 * V_25 )
{
struct V_26 * V_27 = & V_20 -> V_27 [ V_28 ] ;
struct V_18 * V_29 ;
T_1 V_30 ;
T_1 V_31 ;
int V_3 , V_32 ;
int V_33 = 0 ;
V_30 = V_23 << V_34 ;
V_32 = F_3 ( V_30 , 0x1FFFFF ) ;
V_33 = F_4 ( V_20 , V_27 , V_32 * 4 + 64 ) ;
if ( V_33 ) {
F_5 ( L_1 , V_33 ) ;
return F_6 ( V_33 ) ;
}
F_7 ( V_27 , F_8 ( V_35 , 0 ) ) ;
F_7 ( V_27 , ( 1 << 16 ) ) ;
for ( V_3 = 0 ; V_3 < V_32 ; V_3 ++ ) {
V_31 = V_30 ;
if ( V_31 > 0x1FFFFF ) {
V_31 = 0x1FFFFF ;
}
V_30 -= V_31 ;
F_7 ( V_27 , F_8 ( 0x720 , 2 ) ) ;
F_7 ( V_27 , V_21 ) ;
F_7 ( V_27 , V_22 ) ;
F_7 ( V_27 , V_31 | ( 1 << 31 ) | ( 1 << 30 ) ) ;
V_21 += V_31 ;
V_22 += V_31 ;
}
F_7 ( V_27 , F_8 ( V_35 , 0 ) ) ;
F_7 ( V_27 , V_36 ) ;
V_33 = F_9 ( V_20 , & V_29 , V_28 ) ;
if ( V_33 ) {
F_10 ( V_20 , V_27 ) ;
return F_6 ( V_33 ) ;
}
F_11 ( V_20 , V_27 , false ) ;
return V_29 ;
}
static int F_12 ( T_1 V_37 )
{
int V_2 , V_3 , V_38 ;
V_2 = 0 ;
for ( V_3 = 0 ; V_3 < 6 ; V_3 ++ ) {
V_38 = ( V_37 >> ( V_3 * 3 ) ) & 0x7 ;
if ( V_38 > 4 )
continue;
V_2 += V_38 ;
}
return V_2 ;
}
int F_13 ( struct V_39 * V_40 ,
struct V_41 * V_42 ,
unsigned V_43 , unsigned V_44 )
{
struct V_45 * V_46 ;
struct V_47 * V_48 ;
volatile T_1 * V_49 ;
T_1 V_50 ;
int V_33 ;
int V_3 ;
int V_51 ;
T_3 V_52 = 0 ;
T_3 V_53 ;
V_49 = V_40 -> V_49 . V_54 ;
V_48 = (struct V_47 * ) V_40 -> V_48 ;
V_53 = F_14 ( V_40 , V_43 ) ;
switch ( V_44 ) {
case V_55 :
V_33 = F_15 ( V_40 ) ;
if ( V_33 ) {
F_5 ( L_2 ,
V_43 , V_44 ) ;
F_16 ( V_40 , V_42 ) ;
return V_33 ;
}
break;
case V_56 :
case V_57 :
V_33 = F_17 ( V_40 , V_42 , V_43 , V_44 ) ;
if ( V_33 )
return V_33 ;
break;
case V_58 :
V_33 = F_18 ( V_40 , & V_46 , 0 ) ;
if ( V_33 ) {
F_5 ( L_2 ,
V_43 , V_44 ) ;
F_16 ( V_40 , V_42 ) ;
return V_33 ;
}
V_48 -> V_59 . V_60 = V_46 -> V_60 ;
V_48 -> V_59 . V_61 = V_53 ;
V_48 -> V_62 = true ;
V_49 [ V_43 ] = V_53 + ( ( T_3 ) V_46 -> V_63 ) ;
break;
case V_64 :
V_33 = F_18 ( V_40 , & V_46 , 0 ) ;
if ( V_33 ) {
F_5 ( L_2 ,
V_43 , V_44 ) ;
F_16 ( V_40 , V_42 ) ;
return V_33 ;
}
V_48 -> V_65 [ 0 ] . V_60 = V_46 -> V_60 ;
V_48 -> V_65 [ 0 ] . V_61 = V_53 ;
V_48 -> V_66 = true ;
V_49 [ V_43 ] = V_53 + ( ( T_3 ) V_46 -> V_63 ) ;
break;
case V_67 :
case V_68 :
case V_69 :
case V_70 :
case V_71 :
case V_72 :
V_3 = ( V_44 - V_67 ) / 24 ;
V_33 = F_18 ( V_40 , & V_46 , 0 ) ;
if ( V_33 ) {
F_5 ( L_2 ,
V_43 , V_44 ) ;
F_16 ( V_40 , V_42 ) ;
return V_33 ;
}
if ( ! ( V_40 -> V_73 & V_74 ) ) {
if ( V_46 -> V_75 & V_76 )
V_52 |= V_77 ;
if ( V_46 -> V_75 & V_78 )
V_52 |= V_79 ;
V_50 = V_53 & ~ ( 0x7 << 2 ) ;
V_50 |= V_52 ;
V_49 [ V_43 ] = V_50 + ( ( T_3 ) V_46 -> V_63 ) ;
} else
V_49 [ V_43 ] = V_53 + ( ( T_3 ) V_46 -> V_63 ) ;
V_48 -> V_80 [ V_3 ] . V_60 = V_46 -> V_60 ;
V_48 -> V_81 = true ;
break;
case V_82 :
case V_83 :
case V_84 :
case V_85 :
case V_86 :
case V_87 :
case V_88 :
case V_89 :
case V_90 :
case V_91 :
case V_92 :
case V_93 :
case V_94 :
case V_95 :
case V_96 :
case V_97 :
case V_98 :
case V_99 :
case V_100 :
case V_101 :
case V_102 :
case V_103 :
case V_104 :
case V_105 :
case V_106 :
case V_107 :
case V_108 :
case V_109 :
case V_110 :
case V_111 :
V_3 = ( V_44 - V_67 ) / 24 ;
V_51 = ( V_44 - ( ( V_3 * 24 ) + V_67 ) ) / 4 ;
V_33 = F_18 ( V_40 , & V_46 , 0 ) ;
if ( V_33 ) {
F_5 ( L_2 ,
V_43 , V_44 ) ;
F_16 ( V_40 , V_42 ) ;
return V_33 ;
}
V_48 -> V_80 [ V_3 ] . V_112 [ V_51 - 1 ] . V_61 = V_53 ;
V_49 [ V_43 ] = V_53 + ( ( T_3 ) V_46 -> V_63 ) ;
V_48 -> V_80 [ V_3 ] . V_112 [ V_51 - 1 ] . V_60 = V_46 -> V_60 ;
V_48 -> V_81 = true ;
break;
case V_113 :
V_48 -> V_114 = ( ( V_53 >> 16 ) & 0x7FF ) ;
V_48 -> V_66 = true ;
V_48 -> V_62 = true ;
break;
case V_115 :
V_33 = F_18 ( V_40 , & V_46 , 0 ) ;
if ( V_33 ) {
F_5 ( L_2 ,
V_43 , V_44 ) ;
F_16 ( V_40 , V_42 ) ;
return V_33 ;
}
if ( ! ( V_40 -> V_73 & V_74 ) ) {
if ( V_46 -> V_75 & V_76 )
V_52 |= V_116 ;
if ( V_46 -> V_75 & V_78 )
V_52 |= V_117 ;
V_50 = V_53 & ~ ( 0x7 << 16 ) ;
V_50 |= V_52 ;
V_49 [ V_43 ] = V_50 ;
} else
V_49 [ V_43 ] = V_53 ;
V_48 -> V_65 [ 0 ] . V_118 = V_53 & V_119 ;
V_48 -> V_66 = true ;
break;
case V_120 :
V_48 -> V_59 . V_118 = V_53 & V_121 ;
V_48 -> V_62 = true ;
break;
case V_122 :
switch ( ( V_53 >> V_123 ) & 0x1f ) {
case 7 :
case 8 :
case 9 :
case 11 :
case 12 :
V_48 -> V_65 [ 0 ] . V_124 = 1 ;
break;
case 3 :
case 4 :
case 15 :
V_48 -> V_65 [ 0 ] . V_124 = 2 ;
break;
case 6 :
V_48 -> V_65 [ 0 ] . V_124 = 4 ;
break;
default:
F_5 ( L_3 ,
( ( V_53 >> V_123 ) & 0x1f ) ) ;
return - V_125 ;
}
if ( V_53 & V_126 ) {
F_5 ( L_4 ) ;
return - V_125 ;
}
V_48 -> V_127 = ! ! ( V_53 & V_128 ) ;
V_48 -> V_66 = true ;
V_48 -> V_62 = true ;
break;
case V_129 :
switch ( V_53 & 0xf ) {
case 0 :
V_48 -> V_59 . V_124 = 2 ;
break;
case 2 :
case 3 :
case 4 :
case 5 :
case 9 :
case 11 :
V_48 -> V_59 . V_124 = 4 ;
break;
default:
break;
}
V_48 -> V_62 = true ;
break;
case V_130 :
V_33 = F_18 ( V_40 , & V_46 , 0 ) ;
if ( V_33 ) {
F_5 ( L_2 ,
V_43 , V_44 ) ;
F_16 ( V_40 , V_42 ) ;
return V_33 ;
}
V_49 [ V_43 ] = V_53 + ( ( T_3 ) V_46 -> V_63 ) ;
break;
case V_131 :
{
T_1 V_132 = V_53 >> 4 ;
for ( V_3 = 0 ; V_3 < V_48 -> V_133 ; V_3 ++ )
V_48 -> V_80 [ V_3 ] . V_134 = ! ! ( V_132 & ( 1 << V_3 ) ) ;
V_48 -> V_81 = true ;
}
break;
case V_135 :
V_48 -> V_136 = V_53 ;
break;
case 0x210c :
V_48 -> V_137 = V_53 & 0x00FFFFFFUL ;
break;
case V_138 :
V_48 -> V_2 = F_1 ( V_53 ) ;
break;
case V_139 :
V_48 -> V_2 += F_12 ( V_53 ) ;
break;
case V_140 :
case V_141 :
case V_142 :
case V_143 :
case V_144 :
case V_145 :
V_3 = ( V_44 - V_140 ) / 32 ;
V_48 -> V_80 [ V_3 ] . V_146 = ( V_53 & V_147 ) + 1 ;
V_48 -> V_80 [ V_3 ] . V_148 = ( ( V_53 & V_149 ) >> V_150 ) + 1 ;
V_48 -> V_81 = true ;
break;
case V_151 :
case V_152 :
case V_153 :
case V_154 :
case V_155 :
case V_156 :
V_3 = ( V_44 - V_151 ) / 32 ;
V_48 -> V_80 [ V_3 ] . V_118 = V_53 + 32 ;
V_48 -> V_81 = true ;
break;
case V_157 :
case V_158 :
case V_159 :
case V_160 :
case V_161 :
case V_162 :
V_3 = ( V_44 - V_157 ) / 32 ;
V_48 -> V_80 [ V_3 ] . V_163 = ( ( V_53 & V_164 )
>> V_165 ) ;
V_50 = ( V_53 >> 23 ) & 0x7 ;
if ( V_50 == 2 || V_50 == 6 )
V_48 -> V_80 [ V_3 ] . V_166 = false ;
V_50 = ( V_53 >> 27 ) & 0x7 ;
if ( V_50 == 2 || V_50 == 6 )
V_48 -> V_80 [ V_3 ] . V_167 = false ;
V_48 -> V_81 = true ;
break;
case V_168 :
case V_169 :
case V_170 :
case V_171 :
case V_172 :
case V_173 :
V_3 = ( V_44 - V_168 ) / 32 ;
break;
case V_174 :
case V_175 :
case V_176 :
case V_177 :
case V_178 :
case V_179 :
V_3 = ( V_44 - V_174 ) / 32 ;
V_48 -> V_80 [ V_3 ] . V_180 = V_53 & 0x7 ;
V_50 = ( V_53 >> 16 ) & 0x3 ;
switch ( V_50 ) {
case 0 :
case 3 :
case 4 :
case 5 :
case 6 :
case 7 :
V_48 -> V_80 [ V_3 ] . V_181 = 0 ;
break;
case 1 :
V_48 -> V_80 [ V_3 ] . V_181 = 2 ;
break;
case 2 :
V_48 -> V_80 [ V_3 ] . V_181 = 1 ;
break;
}
V_48 -> V_81 = true ;
break;
case V_182 :
case V_183 :
case V_184 :
case V_185 :
case V_186 :
case V_187 :
V_3 = ( V_44 - V_182 ) / 32 ;
if ( V_53 & V_188 ) {
V_48 -> V_80 [ V_3 ] . V_189 = 1 ;
} else {
V_48 -> V_80 [ V_3 ] . V_189 = 0 ;
V_48 -> V_80 [ V_3 ] . V_146 = 1 << ( ( V_53 >> V_190 ) & V_191 ) ;
V_48 -> V_80 [ V_3 ] . V_148 = 1 << ( ( V_53 >> V_192 ) & V_193 ) ;
}
if ( V_53 & V_194 )
V_48 -> V_80 [ V_3 ] . V_195 = true ;
switch ( ( V_53 & V_196 ) ) {
case V_197 :
case V_198 :
case V_199 :
V_48 -> V_80 [ V_3 ] . V_124 = 1 ;
V_48 -> V_80 [ V_3 ] . V_200 = V_201 ;
break;
case V_202 :
case V_203 :
case V_204 :
case V_205 :
case V_206 :
case V_207 :
case V_208 :
case V_209 :
case V_210 :
V_48 -> V_80 [ V_3 ] . V_124 = 2 ;
V_48 -> V_80 [ V_3 ] . V_200 = V_201 ;
break;
case V_211 :
case V_212 :
case V_213 :
case V_214 :
case V_215 :
V_48 -> V_80 [ V_3 ] . V_124 = 4 ;
V_48 -> V_80 [ V_3 ] . V_200 = V_201 ;
break;
case V_216 :
V_48 -> V_80 [ V_3 ] . V_124 = 1 ;
V_48 -> V_80 [ V_3 ] . V_200 = V_217 ;
break;
case V_218 :
case V_219 :
V_48 -> V_80 [ V_3 ] . V_124 = 1 ;
V_48 -> V_80 [ V_3 ] . V_200 = V_217 ;
break;
}
V_48 -> V_80 [ V_3 ] . V_112 [ 4 ] . V_146 = 1 << ( ( V_53 >> 16 ) & 0xf ) ;
V_48 -> V_80 [ V_3 ] . V_112 [ 4 ] . V_148 = 1 << ( ( V_53 >> 20 ) & 0xf ) ;
V_48 -> V_81 = true ;
break;
case V_220 :
case V_221 :
case V_222 :
case V_223 :
case V_224 :
case V_225 :
V_50 = V_53 ;
V_3 = ( V_44 - V_220 ) / 32 ;
for ( V_51 = 0 ; V_51 < 4 ; V_51 ++ ) {
V_48 -> V_80 [ V_3 ] . V_112 [ V_51 ] . V_146 = 1 << ( ( V_50 >> ( V_51 * 8 ) ) & 0xf ) ;
V_48 -> V_80 [ V_3 ] . V_112 [ V_51 ] . V_148 = 1 << ( ( V_50 >> ( ( V_51 * 8 ) + 4 ) ) & 0xf ) ;
}
V_48 -> V_81 = true ;
break;
default:
F_19 ( V_226 L_5 ,
V_44 , V_43 ) ;
return - V_125 ;
}
return 0 ;
}
void F_20 ( struct V_19 * V_20 )
{
V_20 -> V_227 . V_228 . V_229 = V_230 ;
V_20 -> V_227 . V_228 . V_231 = F_21 ( V_230 ) ;
}
