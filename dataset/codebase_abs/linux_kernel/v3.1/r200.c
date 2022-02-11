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
struct V_23 * V_24 )
{
T_1 V_25 ;
T_1 V_26 ;
int V_3 , V_27 ;
int V_28 = 0 ;
V_25 = V_22 << V_29 ;
V_27 = F_3 ( V_25 , 0x1FFFFF ) ;
V_28 = F_4 ( V_19 , V_27 * 4 + 64 ) ;
if ( V_28 ) {
F_5 ( L_1 , V_28 ) ;
return V_28 ;
}
F_6 ( V_19 , F_7 ( V_30 , 0 ) ) ;
F_6 ( V_19 , ( 1 << 16 ) ) ;
for ( V_3 = 0 ; V_3 < V_27 ; V_3 ++ ) {
V_26 = V_25 ;
if ( V_26 > 0x1FFFFF ) {
V_26 = 0x1FFFFF ;
}
V_25 -= V_26 ;
F_6 ( V_19 , F_7 ( 0x720 , 2 ) ) ;
F_6 ( V_19 , V_20 ) ;
F_6 ( V_19 , V_21 ) ;
F_6 ( V_19 , V_26 | ( 1 << 31 ) | ( 1 << 30 ) ) ;
V_20 += V_26 ;
V_21 += V_26 ;
}
F_6 ( V_19 , F_7 ( V_30 , 0 ) ) ;
F_6 ( V_19 , V_31 ) ;
if ( V_24 ) {
V_28 = F_8 ( V_19 , V_24 ) ;
}
F_9 ( V_19 ) ;
return V_28 ;
}
static int F_10 ( T_1 V_32 )
{
int V_2 , V_3 , V_33 ;
V_2 = 0 ;
for ( V_3 = 0 ; V_3 < 6 ; V_3 ++ ) {
V_33 = ( V_32 >> ( V_3 * 3 ) ) & 0x7 ;
if ( V_33 > 4 )
continue;
V_2 += V_33 ;
}
return V_2 ;
}
int F_11 ( struct V_34 * V_35 ,
struct V_36 * V_37 ,
unsigned V_38 , unsigned V_39 )
{
struct V_40 * V_41 ;
struct V_42 * V_43 ;
volatile T_1 * V_44 ;
T_1 V_45 ;
int V_28 ;
int V_3 ;
int V_46 ;
T_3 V_47 = 0 ;
T_3 V_48 ;
V_44 = V_35 -> V_44 -> V_49 ;
V_43 = (struct V_42 * ) V_35 -> V_43 ;
V_48 = F_12 ( V_35 , V_38 ) ;
switch ( V_39 ) {
case V_50 :
V_28 = F_13 ( V_35 ) ;
if ( V_28 ) {
F_5 ( L_2 ,
V_38 , V_39 ) ;
F_14 ( V_35 , V_37 ) ;
return V_28 ;
}
break;
case V_51 :
case V_52 :
V_28 = F_15 ( V_35 , V_37 , V_38 , V_39 ) ;
if ( V_28 )
return V_28 ;
break;
case V_53 :
V_28 = F_16 ( V_35 , & V_41 ) ;
if ( V_28 ) {
F_5 ( L_2 ,
V_38 , V_39 ) ;
F_14 ( V_35 , V_37 ) ;
return V_28 ;
}
V_43 -> V_54 . V_55 = V_41 -> V_55 ;
V_43 -> V_54 . V_56 = V_48 ;
V_43 -> V_57 = true ;
V_44 [ V_38 ] = V_48 + ( ( T_3 ) V_41 -> V_58 . V_59 ) ;
break;
case V_60 :
V_28 = F_16 ( V_35 , & V_41 ) ;
if ( V_28 ) {
F_5 ( L_2 ,
V_38 , V_39 ) ;
F_14 ( V_35 , V_37 ) ;
return V_28 ;
}
V_43 -> V_61 [ 0 ] . V_55 = V_41 -> V_55 ;
V_43 -> V_61 [ 0 ] . V_56 = V_48 ;
V_43 -> V_62 = true ;
V_44 [ V_38 ] = V_48 + ( ( T_3 ) V_41 -> V_58 . V_59 ) ;
break;
case V_63 :
case V_64 :
case V_65 :
case V_66 :
case V_67 :
case V_68 :
V_3 = ( V_39 - V_63 ) / 24 ;
V_28 = F_16 ( V_35 , & V_41 ) ;
if ( V_28 ) {
F_5 ( L_2 ,
V_38 , V_39 ) ;
F_14 ( V_35 , V_37 ) ;
return V_28 ;
}
V_44 [ V_38 ] = V_48 + ( ( T_3 ) V_41 -> V_58 . V_59 ) ;
V_43 -> V_69 [ V_3 ] . V_55 = V_41 -> V_55 ;
V_43 -> V_70 = true ;
break;
case V_71 :
case V_72 :
case V_73 :
case V_74 :
case V_75 :
case V_76 :
case V_77 :
case V_78 :
case V_79 :
case V_80 :
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
V_3 = ( V_39 - V_63 ) / 24 ;
V_46 = ( V_39 - ( ( V_3 * 24 ) + V_63 ) ) / 4 ;
V_28 = F_16 ( V_35 , & V_41 ) ;
if ( V_28 ) {
F_5 ( L_2 ,
V_38 , V_39 ) ;
F_14 ( V_35 , V_37 ) ;
return V_28 ;
}
V_43 -> V_69 [ V_3 ] . V_101 [ V_46 - 1 ] . V_56 = V_48 ;
V_44 [ V_38 ] = V_48 + ( ( T_3 ) V_41 -> V_58 . V_59 ) ;
V_43 -> V_69 [ V_3 ] . V_101 [ V_46 - 1 ] . V_55 = V_41 -> V_55 ;
V_43 -> V_70 = true ;
break;
case V_102 :
V_43 -> V_103 = ( ( V_48 >> 16 ) & 0x7FF ) ;
V_43 -> V_62 = true ;
V_43 -> V_57 = true ;
break;
case V_104 :
V_28 = F_16 ( V_35 , & V_41 ) ;
if ( V_28 ) {
F_5 ( L_2 ,
V_38 , V_39 ) ;
F_14 ( V_35 , V_37 ) ;
return V_28 ;
}
if ( V_41 -> V_58 . V_105 & V_106 )
V_47 |= V_107 ;
if ( V_41 -> V_58 . V_105 & V_108 )
V_47 |= V_109 ;
V_45 = V_48 & ~ ( 0x7 << 16 ) ;
V_45 |= V_47 ;
V_44 [ V_38 ] = V_45 ;
V_43 -> V_61 [ 0 ] . V_110 = V_48 & V_111 ;
V_43 -> V_62 = true ;
break;
case V_112 :
V_43 -> V_54 . V_110 = V_48 & V_113 ;
V_43 -> V_57 = true ;
break;
case V_114 :
switch ( ( V_48 >> V_115 ) & 0x1f ) {
case 7 :
case 8 :
case 9 :
case 11 :
case 12 :
V_43 -> V_61 [ 0 ] . V_116 = 1 ;
break;
case 3 :
case 4 :
case 15 :
V_43 -> V_61 [ 0 ] . V_116 = 2 ;
break;
case 6 :
V_43 -> V_61 [ 0 ] . V_116 = 4 ;
break;
default:
F_5 ( L_3 ,
( ( V_48 >> V_115 ) & 0x1f ) ) ;
return - V_117 ;
}
if ( V_48 & V_118 ) {
F_5 ( L_4 ) ;
return - V_117 ;
}
V_43 -> V_119 = ! ! ( V_48 & V_120 ) ;
V_43 -> V_62 = true ;
V_43 -> V_57 = true ;
break;
case V_121 :
switch ( V_48 & 0xf ) {
case 0 :
V_43 -> V_54 . V_116 = 2 ;
break;
case 2 :
case 3 :
case 4 :
case 5 :
case 9 :
case 11 :
V_43 -> V_54 . V_116 = 4 ;
break;
default:
break;
}
V_43 -> V_57 = true ;
break;
case V_122 :
V_28 = F_16 ( V_35 , & V_41 ) ;
if ( V_28 ) {
F_5 ( L_2 ,
V_38 , V_39 ) ;
F_14 ( V_35 , V_37 ) ;
return V_28 ;
}
V_44 [ V_38 ] = V_48 + ( ( T_3 ) V_41 -> V_58 . V_59 ) ;
break;
case V_123 :
{
T_1 V_124 = V_48 >> 4 ;
for ( V_3 = 0 ; V_3 < V_43 -> V_125 ; V_3 ++ )
V_43 -> V_69 [ V_3 ] . V_126 = ! ! ( V_124 & ( 1 << V_3 ) ) ;
V_43 -> V_70 = true ;
}
break;
case V_127 :
V_43 -> V_128 = V_48 ;
break;
case 0x210c :
V_43 -> V_129 = V_48 & 0x00FFFFFFUL ;
break;
case V_130 :
V_43 -> V_2 = F_1 ( V_48 ) ;
break;
case V_131 :
V_43 -> V_2 += F_10 ( V_48 ) ;
break;
case V_132 :
case V_133 :
case V_134 :
case V_135 :
case V_136 :
case V_137 :
V_3 = ( V_39 - V_132 ) / 32 ;
V_43 -> V_69 [ V_3 ] . V_138 = ( V_48 & V_139 ) + 1 ;
V_43 -> V_69 [ V_3 ] . V_140 = ( ( V_48 & V_141 ) >> V_142 ) + 1 ;
V_43 -> V_70 = true ;
break;
case V_143 :
case V_144 :
case V_145 :
case V_146 :
case V_147 :
case V_148 :
V_3 = ( V_39 - V_143 ) / 32 ;
V_43 -> V_69 [ V_3 ] . V_110 = V_48 + 32 ;
V_43 -> V_70 = true ;
break;
case V_149 :
case V_150 :
case V_151 :
case V_152 :
case V_153 :
case V_154 :
V_3 = ( V_39 - V_149 ) / 32 ;
V_43 -> V_69 [ V_3 ] . V_155 = ( ( V_48 & V_156 )
>> V_157 ) ;
V_45 = ( V_48 >> 23 ) & 0x7 ;
if ( V_45 == 2 || V_45 == 6 )
V_43 -> V_69 [ V_3 ] . V_158 = false ;
V_45 = ( V_48 >> 27 ) & 0x7 ;
if ( V_45 == 2 || V_45 == 6 )
V_43 -> V_69 [ V_3 ] . V_159 = false ;
V_43 -> V_70 = true ;
break;
case V_160 :
case V_161 :
case V_162 :
case V_163 :
case V_164 :
case V_165 :
V_3 = ( V_39 - V_160 ) / 32 ;
break;
case V_166 :
case V_167 :
case V_168 :
case V_169 :
case V_170 :
case V_171 :
V_3 = ( V_39 - V_166 ) / 32 ;
V_43 -> V_69 [ V_3 ] . V_172 = V_48 & 0x7 ;
V_45 = ( V_48 >> 16 ) & 0x3 ;
switch ( V_45 ) {
case 0 :
case 3 :
case 4 :
case 5 :
case 6 :
case 7 :
V_43 -> V_69 [ V_3 ] . V_173 = 0 ;
break;
case 1 :
V_43 -> V_69 [ V_3 ] . V_173 = 2 ;
break;
case 2 :
V_43 -> V_69 [ V_3 ] . V_173 = 1 ;
break;
}
V_43 -> V_70 = true ;
break;
case V_174 :
case V_175 :
case V_176 :
case V_177 :
case V_178 :
case V_179 :
V_3 = ( V_39 - V_174 ) / 32 ;
if ( V_48 & V_180 ) {
V_43 -> V_69 [ V_3 ] . V_181 = 1 ;
} else {
V_43 -> V_69 [ V_3 ] . V_181 = 0 ;
V_43 -> V_69 [ V_3 ] . V_138 = 1 << ( ( V_48 >> V_182 ) & V_183 ) ;
V_43 -> V_69 [ V_3 ] . V_140 = 1 << ( ( V_48 >> V_184 ) & V_185 ) ;
}
if ( V_48 & V_186 )
V_43 -> V_69 [ V_3 ] . V_187 = true ;
switch ( ( V_48 & V_188 ) ) {
case V_189 :
case V_190 :
case V_191 :
V_43 -> V_69 [ V_3 ] . V_116 = 1 ;
V_43 -> V_69 [ V_3 ] . V_192 = V_193 ;
break;
case V_194 :
case V_195 :
case V_196 :
case V_197 :
case V_198 :
case V_199 :
case V_200 :
case V_201 :
case V_202 :
V_43 -> V_69 [ V_3 ] . V_116 = 2 ;
V_43 -> V_69 [ V_3 ] . V_192 = V_193 ;
break;
case V_203 :
case V_204 :
case V_205 :
case V_206 :
case V_207 :
V_43 -> V_69 [ V_3 ] . V_116 = 4 ;
V_43 -> V_69 [ V_3 ] . V_192 = V_193 ;
break;
case V_208 :
V_43 -> V_69 [ V_3 ] . V_116 = 1 ;
V_43 -> V_69 [ V_3 ] . V_192 = V_209 ;
break;
case V_210 :
case V_211 :
V_43 -> V_69 [ V_3 ] . V_116 = 1 ;
V_43 -> V_69 [ V_3 ] . V_192 = V_209 ;
break;
}
V_43 -> V_69 [ V_3 ] . V_101 [ 4 ] . V_138 = 1 << ( ( V_48 >> 16 ) & 0xf ) ;
V_43 -> V_69 [ V_3 ] . V_101 [ 4 ] . V_140 = 1 << ( ( V_48 >> 20 ) & 0xf ) ;
V_43 -> V_70 = true ;
break;
case V_212 :
case V_213 :
case V_214 :
case V_215 :
case V_216 :
case V_217 :
V_45 = V_48 ;
V_3 = ( V_39 - V_212 ) / 32 ;
for ( V_46 = 0 ; V_46 < 4 ; V_46 ++ ) {
V_43 -> V_69 [ V_3 ] . V_101 [ V_46 ] . V_138 = 1 << ( ( V_45 >> ( V_46 * 8 ) ) & 0xf ) ;
V_43 -> V_69 [ V_3 ] . V_101 [ V_46 ] . V_140 = 1 << ( ( V_45 >> ( ( V_46 * 8 ) + 4 ) ) & 0xf ) ;
}
V_43 -> V_70 = true ;
break;
default:
F_17 ( V_218 L_5 ,
V_39 , V_38 ) ;
return - V_117 ;
}
return 0 ;
}
void F_18 ( struct V_18 * V_19 )
{
V_19 -> V_219 . V_220 . V_221 = V_222 ;
V_19 -> V_219 . V_220 . V_223 = F_19 ( V_222 ) ;
}
