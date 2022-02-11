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
int F_2 ( struct V_18 * V_19 ,
T_2 V_20 ,
T_2 V_21 ,
unsigned V_22 ,
struct V_23 * * V_24 )
{
struct V_25 * V_26 = & V_19 -> V_26 [ V_27 ] ;
T_1 V_28 ;
T_1 V_29 ;
int V_3 , V_30 ;
int V_31 = 0 ;
V_28 = V_22 << V_32 ;
V_30 = F_3 ( V_28 , 0x1FFFFF ) ;
V_31 = F_4 ( V_19 , V_26 , V_30 * 4 + 64 ) ;
if ( V_31 ) {
F_5 ( L_1 , V_31 ) ;
return V_31 ;
}
F_6 ( V_26 , F_7 ( V_33 , 0 ) ) ;
F_6 ( V_26 , ( 1 << 16 ) ) ;
for ( V_3 = 0 ; V_3 < V_30 ; V_3 ++ ) {
V_29 = V_28 ;
if ( V_29 > 0x1FFFFF ) {
V_29 = 0x1FFFFF ;
}
V_28 -= V_29 ;
F_6 ( V_26 , F_7 ( 0x720 , 2 ) ) ;
F_6 ( V_26 , V_20 ) ;
F_6 ( V_26 , V_21 ) ;
F_6 ( V_26 , V_29 | ( 1 << 31 ) | ( 1 << 30 ) ) ;
V_20 += V_29 ;
V_21 += V_29 ;
}
F_6 ( V_26 , F_7 ( V_33 , 0 ) ) ;
F_6 ( V_26 , V_34 ) ;
if ( V_24 ) {
V_31 = F_8 ( V_19 , V_24 , V_27 ) ;
}
F_9 ( V_19 , V_26 ) ;
return V_31 ;
}
static int F_10 ( T_1 V_35 )
{
int V_2 , V_3 , V_36 ;
V_2 = 0 ;
for ( V_3 = 0 ; V_3 < 6 ; V_3 ++ ) {
V_36 = ( V_35 >> ( V_3 * 3 ) ) & 0x7 ;
if ( V_36 > 4 )
continue;
V_2 += V_36 ;
}
return V_2 ;
}
int F_11 ( struct V_37 * V_38 ,
struct V_39 * V_40 ,
unsigned V_41 , unsigned V_42 )
{
struct V_43 * V_44 ;
struct V_45 * V_46 ;
volatile T_1 * V_47 ;
T_1 V_48 ;
int V_31 ;
int V_3 ;
int V_49 ;
T_3 V_50 = 0 ;
T_3 V_51 ;
V_47 = V_38 -> V_47 . V_52 ;
V_46 = (struct V_45 * ) V_38 -> V_46 ;
V_51 = F_12 ( V_38 , V_41 ) ;
switch ( V_42 ) {
case V_53 :
V_31 = F_13 ( V_38 ) ;
if ( V_31 ) {
F_5 ( L_2 ,
V_41 , V_42 ) ;
F_14 ( V_38 , V_40 ) ;
return V_31 ;
}
break;
case V_54 :
case V_55 :
V_31 = F_15 ( V_38 , V_40 , V_41 , V_42 ) ;
if ( V_31 )
return V_31 ;
break;
case V_56 :
V_31 = F_16 ( V_38 , & V_44 ) ;
if ( V_31 ) {
F_5 ( L_2 ,
V_41 , V_42 ) ;
F_14 ( V_38 , V_40 ) ;
return V_31 ;
}
V_46 -> V_57 . V_58 = V_44 -> V_58 ;
V_46 -> V_57 . V_59 = V_51 ;
V_46 -> V_60 = true ;
V_47 [ V_41 ] = V_51 + ( ( T_3 ) V_44 -> V_61 . V_62 ) ;
break;
case V_63 :
V_31 = F_16 ( V_38 , & V_44 ) ;
if ( V_31 ) {
F_5 ( L_2 ,
V_41 , V_42 ) ;
F_14 ( V_38 , V_40 ) ;
return V_31 ;
}
V_46 -> V_64 [ 0 ] . V_58 = V_44 -> V_58 ;
V_46 -> V_64 [ 0 ] . V_59 = V_51 ;
V_46 -> V_65 = true ;
V_47 [ V_41 ] = V_51 + ( ( T_3 ) V_44 -> V_61 . V_62 ) ;
break;
case V_66 :
case V_67 :
case V_68 :
case V_69 :
case V_70 :
case V_71 :
V_3 = ( V_42 - V_66 ) / 24 ;
V_31 = F_16 ( V_38 , & V_44 ) ;
if ( V_31 ) {
F_5 ( L_2 ,
V_41 , V_42 ) ;
F_14 ( V_38 , V_40 ) ;
return V_31 ;
}
if ( ! ( V_38 -> V_72 & V_73 ) ) {
if ( V_44 -> V_61 . V_74 & V_75 )
V_50 |= V_76 ;
if ( V_44 -> V_61 . V_74 & V_77 )
V_50 |= V_78 ;
V_48 = V_51 & ~ ( 0x7 << 2 ) ;
V_48 |= V_50 ;
V_47 [ V_41 ] = V_48 + ( ( T_3 ) V_44 -> V_61 . V_62 ) ;
} else
V_47 [ V_41 ] = V_51 + ( ( T_3 ) V_44 -> V_61 . V_62 ) ;
V_46 -> V_79 [ V_3 ] . V_58 = V_44 -> V_58 ;
V_46 -> V_80 = true ;
break;
case V_81 :
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
V_3 = ( V_42 - V_66 ) / 24 ;
V_49 = ( V_42 - ( ( V_3 * 24 ) + V_66 ) ) / 4 ;
V_31 = F_16 ( V_38 , & V_44 ) ;
if ( V_31 ) {
F_5 ( L_2 ,
V_41 , V_42 ) ;
F_14 ( V_38 , V_40 ) ;
return V_31 ;
}
V_46 -> V_79 [ V_3 ] . V_111 [ V_49 - 1 ] . V_59 = V_51 ;
V_47 [ V_41 ] = V_51 + ( ( T_3 ) V_44 -> V_61 . V_62 ) ;
V_46 -> V_79 [ V_3 ] . V_111 [ V_49 - 1 ] . V_58 = V_44 -> V_58 ;
V_46 -> V_80 = true ;
break;
case V_112 :
V_46 -> V_113 = ( ( V_51 >> 16 ) & 0x7FF ) ;
V_46 -> V_65 = true ;
V_46 -> V_60 = true ;
break;
case V_114 :
V_31 = F_16 ( V_38 , & V_44 ) ;
if ( V_31 ) {
F_5 ( L_2 ,
V_41 , V_42 ) ;
F_14 ( V_38 , V_40 ) ;
return V_31 ;
}
if ( ! ( V_38 -> V_72 & V_73 ) ) {
if ( V_44 -> V_61 . V_74 & V_75 )
V_50 |= V_115 ;
if ( V_44 -> V_61 . V_74 & V_77 )
V_50 |= V_116 ;
V_48 = V_51 & ~ ( 0x7 << 16 ) ;
V_48 |= V_50 ;
V_47 [ V_41 ] = V_48 ;
} else
V_47 [ V_41 ] = V_51 ;
V_46 -> V_64 [ 0 ] . V_117 = V_51 & V_118 ;
V_46 -> V_65 = true ;
break;
case V_119 :
V_46 -> V_57 . V_117 = V_51 & V_120 ;
V_46 -> V_60 = true ;
break;
case V_121 :
switch ( ( V_51 >> V_122 ) & 0x1f ) {
case 7 :
case 8 :
case 9 :
case 11 :
case 12 :
V_46 -> V_64 [ 0 ] . V_123 = 1 ;
break;
case 3 :
case 4 :
case 15 :
V_46 -> V_64 [ 0 ] . V_123 = 2 ;
break;
case 6 :
V_46 -> V_64 [ 0 ] . V_123 = 4 ;
break;
default:
F_5 ( L_3 ,
( ( V_51 >> V_122 ) & 0x1f ) ) ;
return - V_124 ;
}
if ( V_51 & V_125 ) {
F_5 ( L_4 ) ;
return - V_124 ;
}
V_46 -> V_126 = ! ! ( V_51 & V_127 ) ;
V_46 -> V_65 = true ;
V_46 -> V_60 = true ;
break;
case V_128 :
switch ( V_51 & 0xf ) {
case 0 :
V_46 -> V_57 . V_123 = 2 ;
break;
case 2 :
case 3 :
case 4 :
case 5 :
case 9 :
case 11 :
V_46 -> V_57 . V_123 = 4 ;
break;
default:
break;
}
V_46 -> V_60 = true ;
break;
case V_129 :
V_31 = F_16 ( V_38 , & V_44 ) ;
if ( V_31 ) {
F_5 ( L_2 ,
V_41 , V_42 ) ;
F_14 ( V_38 , V_40 ) ;
return V_31 ;
}
V_47 [ V_41 ] = V_51 + ( ( T_3 ) V_44 -> V_61 . V_62 ) ;
break;
case V_130 :
{
T_1 V_131 = V_51 >> 4 ;
for ( V_3 = 0 ; V_3 < V_46 -> V_132 ; V_3 ++ )
V_46 -> V_79 [ V_3 ] . V_133 = ! ! ( V_131 & ( 1 << V_3 ) ) ;
V_46 -> V_80 = true ;
}
break;
case V_134 :
V_46 -> V_135 = V_51 ;
break;
case 0x210c :
V_46 -> V_136 = V_51 & 0x00FFFFFFUL ;
break;
case V_137 :
V_46 -> V_2 = F_1 ( V_51 ) ;
break;
case V_138 :
V_46 -> V_2 += F_10 ( V_51 ) ;
break;
case V_139 :
case V_140 :
case V_141 :
case V_142 :
case V_143 :
case V_144 :
V_3 = ( V_42 - V_139 ) / 32 ;
V_46 -> V_79 [ V_3 ] . V_145 = ( V_51 & V_146 ) + 1 ;
V_46 -> V_79 [ V_3 ] . V_147 = ( ( V_51 & V_148 ) >> V_149 ) + 1 ;
V_46 -> V_80 = true ;
break;
case V_150 :
case V_151 :
case V_152 :
case V_153 :
case V_154 :
case V_155 :
V_3 = ( V_42 - V_150 ) / 32 ;
V_46 -> V_79 [ V_3 ] . V_117 = V_51 + 32 ;
V_46 -> V_80 = true ;
break;
case V_156 :
case V_157 :
case V_158 :
case V_159 :
case V_160 :
case V_161 :
V_3 = ( V_42 - V_156 ) / 32 ;
V_46 -> V_79 [ V_3 ] . V_162 = ( ( V_51 & V_163 )
>> V_164 ) ;
V_48 = ( V_51 >> 23 ) & 0x7 ;
if ( V_48 == 2 || V_48 == 6 )
V_46 -> V_79 [ V_3 ] . V_165 = false ;
V_48 = ( V_51 >> 27 ) & 0x7 ;
if ( V_48 == 2 || V_48 == 6 )
V_46 -> V_79 [ V_3 ] . V_166 = false ;
V_46 -> V_80 = true ;
break;
case V_167 :
case V_168 :
case V_169 :
case V_170 :
case V_171 :
case V_172 :
V_3 = ( V_42 - V_167 ) / 32 ;
break;
case V_173 :
case V_174 :
case V_175 :
case V_176 :
case V_177 :
case V_178 :
V_3 = ( V_42 - V_173 ) / 32 ;
V_46 -> V_79 [ V_3 ] . V_179 = V_51 & 0x7 ;
V_48 = ( V_51 >> 16 ) & 0x3 ;
switch ( V_48 ) {
case 0 :
case 3 :
case 4 :
case 5 :
case 6 :
case 7 :
V_46 -> V_79 [ V_3 ] . V_180 = 0 ;
break;
case 1 :
V_46 -> V_79 [ V_3 ] . V_180 = 2 ;
break;
case 2 :
V_46 -> V_79 [ V_3 ] . V_180 = 1 ;
break;
}
V_46 -> V_80 = true ;
break;
case V_181 :
case V_182 :
case V_183 :
case V_184 :
case V_185 :
case V_186 :
V_3 = ( V_42 - V_181 ) / 32 ;
if ( V_51 & V_187 ) {
V_46 -> V_79 [ V_3 ] . V_188 = 1 ;
} else {
V_46 -> V_79 [ V_3 ] . V_188 = 0 ;
V_46 -> V_79 [ V_3 ] . V_145 = 1 << ( ( V_51 >> V_189 ) & V_190 ) ;
V_46 -> V_79 [ V_3 ] . V_147 = 1 << ( ( V_51 >> V_191 ) & V_192 ) ;
}
if ( V_51 & V_193 )
V_46 -> V_79 [ V_3 ] . V_194 = true ;
switch ( ( V_51 & V_195 ) ) {
case V_196 :
case V_197 :
case V_198 :
V_46 -> V_79 [ V_3 ] . V_123 = 1 ;
V_46 -> V_79 [ V_3 ] . V_199 = V_200 ;
break;
case V_201 :
case V_202 :
case V_203 :
case V_204 :
case V_205 :
case V_206 :
case V_207 :
case V_208 :
case V_209 :
V_46 -> V_79 [ V_3 ] . V_123 = 2 ;
V_46 -> V_79 [ V_3 ] . V_199 = V_200 ;
break;
case V_210 :
case V_211 :
case V_212 :
case V_213 :
case V_214 :
V_46 -> V_79 [ V_3 ] . V_123 = 4 ;
V_46 -> V_79 [ V_3 ] . V_199 = V_200 ;
break;
case V_215 :
V_46 -> V_79 [ V_3 ] . V_123 = 1 ;
V_46 -> V_79 [ V_3 ] . V_199 = V_216 ;
break;
case V_217 :
case V_218 :
V_46 -> V_79 [ V_3 ] . V_123 = 1 ;
V_46 -> V_79 [ V_3 ] . V_199 = V_216 ;
break;
}
V_46 -> V_79 [ V_3 ] . V_111 [ 4 ] . V_145 = 1 << ( ( V_51 >> 16 ) & 0xf ) ;
V_46 -> V_79 [ V_3 ] . V_111 [ 4 ] . V_147 = 1 << ( ( V_51 >> 20 ) & 0xf ) ;
V_46 -> V_80 = true ;
break;
case V_219 :
case V_220 :
case V_221 :
case V_222 :
case V_223 :
case V_224 :
V_48 = V_51 ;
V_3 = ( V_42 - V_219 ) / 32 ;
for ( V_49 = 0 ; V_49 < 4 ; V_49 ++ ) {
V_46 -> V_79 [ V_3 ] . V_111 [ V_49 ] . V_145 = 1 << ( ( V_48 >> ( V_49 * 8 ) ) & 0xf ) ;
V_46 -> V_79 [ V_3 ] . V_111 [ V_49 ] . V_147 = 1 << ( ( V_48 >> ( ( V_49 * 8 ) + 4 ) ) & 0xf ) ;
}
V_46 -> V_80 = true ;
break;
default:
F_17 ( V_225 L_5 ,
V_42 , V_41 ) ;
return - V_124 ;
}
return 0 ;
}
void F_18 ( struct V_18 * V_19 )
{
V_19 -> V_226 . V_227 . V_228 = V_229 ;
V_19 -> V_226 . V_227 . V_230 = F_19 ( V_229 ) ;
}
