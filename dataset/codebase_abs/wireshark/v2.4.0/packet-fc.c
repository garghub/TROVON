static T_1
F_1 ( T_2 V_1 , T_2 V_2 )
{
const T_3 * V_3 = ( const T_3 * ) V_1 ;
const T_3 * V_4 = ( const T_3 * ) V_2 ;
return ( V_3 -> V_5 == V_4 -> V_5 ) ;
}
static T_4
F_2 ( T_2 V_1 )
{
const T_3 * V_6 = ( const T_3 * ) V_1 ;
T_4 V_7 ;
V_7 = V_6 -> V_5 ;
return V_7 ;
}
static const char * F_3 ( T_5 * V_8 , T_6 V_9 )
{
if ( ( V_9 == V_10 ) && ( V_8 -> V_11 . type == V_12 ) )
return L_1 ;
if ( ( V_9 == V_13 ) && ( V_8 -> V_14 . type == V_12 ) )
return L_2 ;
if ( ( V_9 == V_15 ) && ( V_8 -> V_11 . type == V_12 ) )
return L_3 ;
return V_16 ;
}
static int
F_4 ( void * V_17 , T_7 * V_18 , T_8 * T_9 V_19 , const void * V_20 )
{
T_10 * V_21 = ( T_10 * ) V_17 ;
const T_11 * V_22 = ( const T_11 * ) V_20 ;
F_5 ( V_21 , & V_22 -> V_23 , & V_22 -> V_24 , 0 , 0 , 1 , V_18 -> V_25 -> V_26 , & V_18 -> V_27 , & V_18 -> V_28 , & V_29 , V_30 ) ;
return 1 ;
}
static const char * F_6 ( T_12 * V_31 , T_6 V_9 )
{
if ( ( V_9 == V_15 ) && ( V_31 -> V_32 . type == V_12 ) )
return L_3 ;
return V_16 ;
}
static int
F_7 ( void * V_33 , T_7 * V_18 , T_8 * T_9 V_19 , const void * V_20 )
{
T_10 * V_21 = ( T_10 * ) V_33 ;
const T_11 * V_22 = ( const T_11 * ) V_20 ;
F_8 ( V_21 , & V_22 -> V_23 , 0 , TRUE , 1 , V_18 -> V_25 -> V_26 , & V_34 , V_30 ) ;
F_8 ( V_21 , & V_22 -> V_24 , 0 , FALSE , 1 , V_18 -> V_25 -> V_26 , & V_34 , V_30 ) ;
return 1 ;
}
static void
F_9 ( struct V_35 * T_13 V_19 , T_14 * V_36 , T_15 V_37 , void * V_38 )
{
T_16 * V_39 ;
T_17 V_40 ;
V_39 = F_10 ( L_4 , NULL , V_36 , V_41 , NULL , NULL , V_37 , V_38 , NULL ) ;
for ( V_40 = 0 ; V_40 < V_41 ; V_40 ++ )
{
T_18 * V_42 = F_11 ( NULL , V_40 , V_43 , L_5 ) ;
F_12 ( V_39 , V_40 , V_42 ) ;
F_13 ( NULL , V_42 ) ;
}
}
static int
F_14 ( void * V_44 , T_7 * V_18 , T_8 * T_9 V_19 , const void * V_45 )
{
T_4 V_40 = 0 ;
T_16 * V_39 ;
T_19 * V_46 = ( T_19 * ) V_44 ;
const T_11 * V_47 = ( const T_11 * ) V_45 ;
if( ! ( V_47 -> V_48 & V_49 ) ) {
return 0 ;
}
if ( ( ! V_47 -> V_50 ) || ( V_47 -> V_50 -> V_51 == 0 ) ) {
return 0 ;
}
V_39 = F_15 ( V_46 -> V_36 , T_16 * , V_40 ) ;
F_16 ( V_39 , V_47 -> type , & V_47 -> V_50 -> V_52 , V_18 ) ;
return 1 ;
}
static void
F_17 ( T_20 * V_53 , T_7 * V_18 , T_21 * V_54 )
{
T_21 * V_55 ;
int V_56 = 0 ;
F_18 ( V_18 -> V_57 , V_58 , L_6 ) ;
F_18 ( V_18 -> V_57 , V_59 , L_7 ) ;
if ( V_54 ) {
V_55 = F_19 ( V_54 , V_53 , 0 , - 1 , V_60 , NULL , L_8 ) ;
F_20 ( V_55 , V_61 , V_53 , V_56 ++ , 1 , V_62 ) ;
F_20 ( V_55 , V_63 , V_53 , V_56 ++ , 1 , V_62 ) ;
V_56 += 2 ;
F_20 ( V_55 , V_64 , V_53 , V_56 , 2 , V_62 ) ;
V_56 += 2 ;
F_20 ( V_55 , V_65 , V_53 , V_56 , 2 , V_62 ) ;
V_56 += 2 ;
F_20 ( V_55 , V_66 , V_53 , V_56 , 2 , V_62 ) ;
V_56 += 2 ;
F_20 ( V_55 , V_67 , V_53 , V_56 , 2 , V_62 ) ;
}
}
static void
F_21 ( T_20 * V_53 , T_7 * V_18 , T_21 * V_54 )
{
T_21 * V_68 ;
int V_56 = 0 ;
F_18 ( V_18 -> V_57 , V_58 , L_6 ) ;
F_18 ( V_18 -> V_57 , V_59 , L_9 ) ;
if ( V_54 ) {
V_68 = F_19 ( V_54 , V_53 , 0 , - 1 , V_60 , NULL , L_8 ) ;
F_20 ( V_68 , V_69 , V_53 , V_56 + 1 , 1 , V_62 ) ;
F_20 ( V_68 , V_70 , V_53 , V_56 + 2 , 1 , V_62 ) ;
F_20 ( V_68 , V_71 , V_53 , V_56 + 3 , 1 , V_62 ) ;
}
}
static T_22
F_22 ( T_22 V_72 , T_22 type )
{
switch ( V_72 & 0xF0 ) {
case V_73 :
switch ( type ) {
case V_74 :
if ( ( V_72 == 0x2 ) || ( V_72 == 0x3 ) )
return V_75 ;
else
return V_76 ;
case V_77 :
return V_78 ;
case V_79 :
return V_80 ;
case V_81 :
return V_82 ;
case V_83 :
case V_84 :
return V_85 ;
case V_86 :
return V_87 ;
default:
return V_76 ;
}
case V_88 :
if ( ( ( V_72 & 0x0F ) == 0x2 ) || ( ( V_72 & 0x0F ) == 0x3 ) )
return V_89 ;
else if ( type == V_90 )
return V_87 ;
else
return V_76 ;
case V_91 :
switch ( type ) {
case V_79 :
return V_80 ;
default:
return V_92 ;
}
case V_93 :
return V_94 ;
case V_95 :
if ( type == 0 )
return V_96 ;
else
return V_76 ;
case V_97 :
return V_98 ;
default:
return V_76 ;
}
}
static void
F_23 ( T_21 * V_99 ,
T_20 * V_53 , int V_56 )
{
T_23 * V_100 ;
T_21 * V_54 ;
T_22 V_101 ;
T_22 V_102 ;
T_22 type ;
T_22 V_103 ;
T_24 V_104 ;
T_22 V_105 ;
V_101 = F_24 ( V_53 , V_56 ) ;
type = F_24 ( V_53 , V_56 + 1 ) ;
V_102 = ( type >> 6 ) & 3 ;
type = ( type >> 2 ) & 0xf ;
V_104 = F_25 ( V_53 , V_56 + 2 ) ;
V_103 = ( V_104 >> 13 ) & 7 ;
V_104 = ( V_104 >> 1 ) & 0xfff ;
V_105 = F_24 ( V_53 , V_56 + 4 ) ;
V_100 = F_26 ( V_99 , V_106 , V_53 , V_56 ,
8 , V_104 , L_10 ,
V_104 , V_103 , V_105 ) ;
V_54 = F_27 ( V_100 , V_107 ) ;
F_28 ( V_54 , V_108 , V_53 , V_56 , 1 , V_101 ) ;
F_28 ( V_54 , V_109 , V_53 , V_56 + 1 , 1 , V_102 ) ;
F_28 ( V_54 , V_110 , V_53 , V_56 + 1 , 1 , type ) ;
F_28 ( V_54 , V_111 , V_53 , V_56 + 2 , 1 , V_103 ) ;
F_28 ( V_54 , V_112 , V_53 , V_56 + 2 , 2 , V_104 ) ;
F_28 ( V_54 , V_113 , V_53 , V_56 + 4 , 1 , V_105 ) ;
}
static void
F_29 ( T_7 * V_18 V_19 , T_21 * V_99 , T_20 * V_53 , int V_56 )
{
static const int * V_114 [] = {
& V_115 ,
& V_116 ,
& V_117 ,
& V_118 ,
& V_119 ,
& V_120 ,
& V_121 ,
& V_122 ,
& V_123 ,
& V_124 ,
& V_125 ,
& V_126 ,
NULL
} ;
F_30 ( V_99 , V_53 , V_56 , V_127 ,
V_128 , V_114 , V_62 , V_129 ) ;
}
static void
F_31 ( T_20 * V_53 , T_7 * V_18 , T_21 * V_54 , T_25 V_130 , T_26 * V_131 )
{
T_23 * V_132 , * V_133 ;
T_21 * V_134 ;
T_20 * V_135 ;
int V_56 = 0 , V_136 ;
int V_137 = - 1 ;
T_25 V_138 , V_139 , V_140 = 0 ;
T_27 * V_141 ;
T_17 V_142 , V_143 ;
T_22 V_144 , V_145 ;
T_17 V_146 ;
T_28 V_147 ;
T_17 V_148 , V_149 ;
T_24 V_150 ;
T_22 V_151 ;
T_11 * V_22 = F_32 ( F_33 () , T_11 ) ;
T_29 * V_50 ;
T_30 * V_152 = NULL ;
T_31 * V_153 ;
T_32 * V_154 ;
T_3 V_155 , * V_156 ;
F_18 ( V_18 -> V_57 , V_58 , L_11 ) ;
V_22 -> V_72 = F_24 ( V_53 , V_56 ) ;
V_22 -> V_50 = NULL ;
if ( V_22 -> V_72 == V_157 ) {
V_137 = V_56 ;
V_56 += 8 ;
V_22 -> V_72 = F_24 ( V_53 , V_56 ) ;
}
if( ! V_130 ) {
F_34 ( & V_18 -> V_158 , V_12 , 3 , V_53 , V_56 + 1 ) ;
F_34 ( & V_18 -> V_159 , V_12 , 3 , V_53 , V_56 + 5 ) ;
V_18 -> V_160 = 0 ;
V_18 -> V_161 = 0 ;
}
F_35 ( & V_22 -> V_24 , V_18 -> V_158 . type , V_18 -> V_158 . V_162 , V_18 -> V_158 . V_46 ) ;
F_35 ( & V_22 -> V_23 , V_18 -> V_159 . type , V_18 -> V_159 . V_162 , V_18 -> V_159 . V_46 ) ;
V_22 -> V_163 = F_24 ( V_53 , V_56 + 4 ) ;
V_22 -> type = F_24 ( V_53 , V_56 + 8 ) ;
V_22 -> V_48 = F_36 ( V_53 , V_56 + 9 ) ;
V_22 -> V_164 = F_25 ( V_53 , V_56 + 14 ) ;
V_22 -> V_165 = F_25 ( V_53 , V_56 + 16 ) ;
V_22 -> V_166 = F_25 ( V_53 , V_56 + 18 ) ;
V_22 -> V_167 = 0 ;
V_148 = F_37 ( V_53 , V_56 + 20 ) ;
V_145 = F_24 ( V_53 , V_56 + 12 ) ;
V_18 -> V_168 = V_169 ;
V_153 = F_38 ( V_18 ) ;
V_152 = ( T_30 * ) F_39 ( V_153 , V_170 ) ;
if( ! V_152 ) {
V_152 = F_32 ( F_40 () , T_30 ) ;
V_152 -> V_171 = F_41 ( F_40 () ) ;
V_152 -> V_172 = F_41 ( F_40 () ) ;
F_42 ( V_153 , V_170 , V_152 ) ;
}
V_22 -> V_173 = 0xFFFF ;
if ( ! V_18 -> V_25 -> V_114 . V_174 ) {
V_22 -> V_173 = ( T_24 ) F_43 ( F_44 ( V_152 -> V_172 , V_22 -> V_165 ) ) ;
}
V_132 = F_45 ( V_54 , V_170 , V_53 , V_56 , V_175 , L_12 ) ;
V_134 = F_27 ( V_132 , V_176 ) ;
V_139 = ( ( ( V_131 -> V_177 & V_178 ) == V_178 ) ||
( ( ( V_131 -> V_177 & V_179 ) == V_179 ) &&
( V_22 -> V_164 == 0 ) ) ) ;
V_138 = ( ( V_131 -> V_177 & V_180 ) == V_180 ) ;
V_138 |= V_22 -> V_48 & V_181 ;
V_151 = F_22 ( V_22 -> V_72 , V_22 -> type ) ;
F_46 ( V_18 -> V_57 , V_59 , F_47 ( V_151 , V_182 ,
L_13 ) ) ;
if ( V_151 == V_98 )
F_48 ( V_18 -> V_57 , V_59 , L_14 ,
F_47 ( ( V_22 -> V_72 & 0x0F ) ,
V_183 ,
L_15 ) ) ;
if ( V_137 >= 0 ) {
F_23 ( V_134 , V_53 , V_137 ) ;
}
switch ( V_22 -> V_72 & 0xF0 ) {
case V_73 :
case V_91 :
case V_93 :
F_26 ( V_134 , V_184 , V_53 , V_56 ,
V_185 , V_22 -> V_72 ,
L_16 ,
V_22 -> V_72 ,
F_47 ( ( V_22 -> V_72 & 0xF0 ) ,
V_186 , L_17 ) ,
F_47 ( ( V_22 -> V_72 & 0x0F ) ,
V_187 , L_17 ) ) ;
break;
case V_97 :
F_26 ( V_134 , V_184 , V_53 , V_56 ,
V_185 , V_22 -> V_72 ,
L_16 ,
V_22 -> V_72 ,
F_47 ( ( V_22 -> V_72 & 0xF0 ) ,
V_186 , L_17 ) ,
F_47 ( ( V_22 -> V_72 & 0x0F ) ,
V_183 , L_17 ) ) ;
break;
case V_95 :
switch ( V_22 -> type ) {
case 0x00 :
F_26 ( V_134 , V_184 , V_53 , V_56 ,
V_185 , V_22 -> V_72 ,
L_16 ,
V_22 -> V_72 ,
F_47 ( ( V_22 -> V_72 & 0xF0 ) ,
V_186 , L_17 ) ,
F_47 ( ( V_22 -> V_72 & 0x0F ) ,
V_188 , L_17 ) ) ;
break;
default:
F_26 ( V_134 , V_184 , V_53 , V_56 ,
V_185 , V_22 -> V_72 ,
L_18 ,
V_22 -> V_72 ,
F_47 ( ( V_22 -> V_72 & 0xF0 ) ,
V_186 , L_17 ) ,
V_22 -> V_72 & 0x0F ) ;
break;
}
break;
case V_88 :
switch ( V_22 -> type ) {
case 0x01 :
F_26 ( V_134 , V_184 , V_53 , V_56 ,
V_185 , V_22 -> V_72 ,
L_16 ,
V_22 -> V_72 ,
F_47 ( ( V_22 -> V_72 & 0xF0 ) ,
V_186 , L_17 ) ,
F_47 ( ( V_22 -> V_72 & 0x0F ) ,
V_189 , L_17 ) ) ;
break;
default:
F_26 ( V_134 , V_184 , V_53 , V_56 ,
V_185 , V_22 -> V_72 ,
L_18 ,
V_22 -> V_72 ,
F_47 ( ( V_22 -> V_72 & 0xF0 ) ,
V_186 , L_17 ) ,
V_22 -> V_72 & 0x0F ) ;
break;
}
break;
default:
F_26 ( V_134 , V_184 , V_53 , V_56 ,
V_185 , V_22 -> V_72 ,
L_18 ,
V_22 -> V_72 ,
F_47 ( ( V_22 -> V_72 & 0xF0 ) ,
V_186 , L_17 ) ,
V_22 -> V_72 & 0x0F ) ;
break;
}
V_133 = F_28 ( V_134 , V_190 , V_53 , V_56 , 1 ,
V_151 ) ;
F_49 ( V_133 ) ;
F_35 ( & V_147 , V_12 , 3 , V_22 -> V_24 . V_46 ) ;
F_20 ( V_134 , V_191 , V_53 , V_56 + 1 , 3 , V_192 ) ;
V_133 = F_20 ( V_134 , V_193 , V_53 , V_56 + 1 , 3 , V_192 ) ;
F_49 ( V_133 ) ;
F_28 ( V_134 , V_194 , V_53 , V_56 + 4 , 1 , V_22 -> V_163 ) ;
F_35 ( & V_147 , V_12 , 3 , V_22 -> V_23 . V_46 ) ;
F_20 ( V_134 , V_195 , V_53 , V_56 + 5 , 3 , V_192 ) ;
V_133 = F_20 ( V_134 , V_193 , V_53 , V_56 + 5 , 3 , V_192 ) ;
F_49 ( V_133 ) ;
if ( V_151 == V_98 ) {
if ( ( ( V_22 -> V_72 & 0x0F ) == V_196 ) ||
( ( V_22 -> V_72 & 0x0F ) == V_197 ) ) {
F_26 ( V_134 , V_198 , V_53 ,
V_56 + 8 , V_199 ,
V_22 -> type , L_19 , V_22 -> type ,
F_50 ( ( T_22 ) ( V_22 -> V_72 & 0x0F ) ,
V_22 -> type ) ) ;
} else {
F_20 ( V_134 , V_198 , V_53 , V_56 + 8 , 1 , V_62 ) ;
}
} else {
F_20 ( V_134 , V_198 , V_53 , V_56 + 8 , 1 , V_62 ) ;
}
F_29 ( V_18 , V_134 , V_53 , V_56 + 9 ) ;
V_146 = F_36 ( V_53 , V_56 + 9 ) ;
F_20 ( V_134 , V_200 , V_53 , V_56 + 12 , 1 , V_62 ) ;
V_144 = F_24 ( V_53 , V_56 + 13 ) ;
F_28 ( V_134 , V_201 , V_53 , V_56 + 13 , 1 , V_144 ) ;
F_28 ( V_134 , V_202 , V_53 , V_56 + 14 , 2 , V_22 -> V_164 ) ;
F_28 ( V_134 , V_203 , V_53 , V_56 + 16 , 2 , V_22 -> V_165 ) ;
F_28 ( V_134 , V_204 , V_53 , V_56 + 18 , 2 , V_22 -> V_166 ) ;
if ( V_151 == V_98 ) {
if ( ( ( V_22 -> V_72 & 0x0F ) == V_205 ) ||
( ( V_22 -> V_72 & 0x0F ) == V_206 ) ||
( ( V_22 -> V_72 & 0x0F ) == V_207 ) ) {
F_26 ( V_134 , V_208 , V_53 ,
V_56 + 20 , 4 , V_148 ,
L_19 , V_148 ,
F_51 ( ( V_22 -> V_72 & 0x0F ) ,
V_148 ) ) ;
} else {
F_20 ( V_134 , V_208 , V_53 , V_56 + 20 , 4 , V_62 ) ;
}
} else if ( V_151 == V_96 ) {
if ( ( V_22 -> V_72 & 0x0F ) == V_209 ) {
F_26 ( V_134 , V_208 , V_53 ,
V_56 + 20 , 4 , V_148 ,
L_19 , V_148 ,
( ( V_148 & 0x0F ) == 1 ? L_20 :
L_21 ) ) ;
} else {
F_20 ( V_134 , V_208 , V_53 , V_56 + 20 ,
4 , V_62 ) ;
}
} else if ( V_151 == V_80 ) {
if ( V_146 & V_210 ) {
F_20 ( V_134 , V_211 , V_53 , V_56 + 20 , 4 , V_62 ) ;
V_22 -> V_167 = F_37 ( V_53 , V_56 + 20 ) ;
} else {
F_20 ( V_134 , V_208 , V_53 , V_56 + 20 , 4 , V_62 ) ;
}
} else {
F_20 ( V_134 , V_208 , V_53 , V_56 + 20 , 4 , V_62 ) ;
}
V_136 = V_56 + V_175 ;
if ( V_144 & V_212 ) {
F_20 ( V_134 , V_213 , V_53 , V_136 , 8 , V_192 ) ;
F_20 ( V_134 , V_214 , V_53 , V_136 + 8 , 8 , V_192 ) ;
V_136 += 16 ;
}
if ( V_151 == V_98 ) {
V_138 = TRUE ;
} else {
V_140 = ( V_146 & V_49 ) != 0 ;
}
if ( F_52 ( V_53 ) < V_175 ) {
F_53 ( V_134 , V_18 , & V_215 ,
V_53 , 0 , F_52 ( V_53 ) ) ;
return;
}
V_143 = F_52 ( V_53 ) - V_175 ;
if ( ( V_131 -> V_216 == V_217 ) || ( V_131 -> V_216 == V_218 ) ) {
if ( ( V_143 < V_219 ) ||
( ( V_143 == V_219 ) && ( V_151 != V_98 ) &&
( V_151 != V_96 ) && ( V_151 != V_87 ) ) ) {
F_53 ( V_134 , V_18 , & V_215 ,
V_53 , V_175 , V_143 ) ;
return;
}
V_143 -= V_219 ;
} else if ( V_131 -> V_216 == V_220 ) {
if ( V_143 <= 8 ) {
F_53 ( V_134 , V_18 , & V_215 ,
V_53 , V_175 , V_143 ) ;
return;
}
V_143 -= 8 ;
}
if ( ! V_138 ) {
F_54 ( V_18 -> V_57 , V_59 , L_22 ) ;
}
if ( ( V_151 != V_98 ) && ( V_151 != V_96 ) &&
( V_151 != V_87 ) &&
( ! V_138 || ! V_139 ) && V_221 &&
F_55 ( V_53 , V_175 , V_143 ) && V_54 ) {
V_155 . V_5 = V_153 -> V_222 ;
V_154 = ( T_32 * ) F_56 ( V_223 ,
& V_155 ) ;
if ( V_139 ) {
if ( V_154 ) {
V_154 -> V_224 = V_22 -> V_164 ;
}
else {
V_156 = F_32 ( F_40 () , T_3 ) ;
V_156 -> V_5 = V_153 -> V_222 ;
V_154 = F_32 ( F_40 () , T_32 ) ;
V_154 -> V_224 = V_22 -> V_164 ;
F_57 ( V_223 , V_156 , V_154 ) ;
}
V_150 = 0 ;
}
else if ( V_154 != NULL ) {
V_150 = V_22 -> V_164 - V_154 -> V_224 ;
}
else {
V_150 = V_22 -> V_164 ;
}
if ( V_138 && ! V_139 && ! V_150 ) {
V_135 = F_58 ( V_53 , V_136 ) ;
F_54 ( V_18 -> V_57 , V_59 , L_23 ) ;
} else {
V_142 = ( ( V_22 -> V_165 << 16 ) ^ V_145 ) | V_140 ;
V_141 = F_59 ( & V_225 ,
V_53 , V_175 ,
V_18 , V_142 , NULL ,
V_150 * V_226 ,
V_143 ,
! V_138 ) ;
if ( V_141 ) {
V_135 = F_60 ( V_53 , V_141 -> V_227 ) ;
F_61 ( V_18 , V_135 , L_24 ) ;
V_133 = F_62 ( V_134 , V_228 ,
V_53 , V_56 + 9 , 1 , 1 ) ;
F_49 ( V_133 ) ;
}
else {
V_133 = F_62 ( V_134 , V_228 ,
V_53 , V_56 + 9 , 1 , 0 ) ;
F_49 ( V_133 ) ;
V_135 = F_58 ( V_53 , V_136 ) ;
F_63 ( V_135 , V_18 , V_54 ) ;
return;
}
}
} else {
V_133 = F_62 ( V_134 , V_228 ,
V_53 , V_56 + 9 , 1 , 0 ) ;
F_49 ( V_133 ) ;
V_135 = F_58 ( V_53 , V_136 ) ;
}
if ( ( V_151 != V_98 ) && ( V_151 != V_96 ) ) {
if( ( V_22 -> V_48 & V_210 ) && V_148 ) {
F_63 ( V_135 , V_18 , V_54 ) ;
} else {
if ( ! F_64 ( V_229 , V_151 ,
V_135 , V_18 , V_54 , FALSE , V_22 ) ) {
F_63 ( V_135 , V_18 , V_54 ) ;
}
}
} else if ( V_151 == V_96 ) {
if ( ( V_22 -> V_72 & 0x0F ) == V_230 ) {
F_17 ( V_135 , V_18 , V_54 ) ;
} else if ( ( V_22 -> V_72 & 0x0F ) == V_231 ) {
F_21 ( V_135 , V_18 , V_54 ) ;
} else if ( ( V_22 -> V_72 & 0x0F ) == V_209 ) {
F_18 ( V_18 -> V_57 , V_58 , L_6 ) ;
F_18 ( V_18 -> V_57 , V_59 , L_25 ) ;
}
}
if ( ! V_18 -> V_25 -> V_114 . V_174 ) {
F_65 ( V_152 -> V_172 , V_22 -> V_165 , F_66 ( ( T_4 ) V_22 -> V_173 ) ) ;
}
V_149 = ( ( V_22 -> V_165 & 0xFFFF ) | ( ( V_22 -> V_173 << 16 ) & 0xFFFF0000 ) ) ;
V_50 = ( T_29 * ) F_44 ( V_152 -> V_171 , V_149 ) ;
if( ! V_50 ) {
V_50 = F_32 ( F_40 () , T_29 ) ;
V_50 -> V_51 = 0 ;
V_50 -> V_232 = 0 ;
V_50 -> V_52 = V_18 -> V_28 ;
F_65 ( V_152 -> V_171 , V_149 , V_50 ) ;
}
V_22 -> V_50 = V_50 ;
if( ! V_18 -> V_25 -> V_114 . V_174 ) {
if( V_22 -> V_48 & V_233 ) {
V_50 -> V_51 = V_18 -> V_234 ;
V_50 -> V_52 = V_18 -> V_28 ;
}
if( V_22 -> V_48 & V_235 ) {
V_50 -> V_232 = V_18 -> V_234 ;
}
}
if( ! ( V_22 -> V_48 & V_233 ) ) {
T_23 * V_236 ;
V_236 = F_28 ( V_134 , V_237 , V_53 , 0 , 0 , V_50 -> V_51 ) ;
F_67 ( V_236 ) ;
if( V_22 -> V_48 & V_235 ) {
T_33 V_238 ;
F_68 ( & V_238 , & V_18 -> V_28 , & V_50 -> V_52 ) ;
V_236 = F_69 ( V_132 , V_239 , V_53 , 0 , 0 , & V_238 ) ;
F_67 ( V_236 ) ;
}
}
if( ! ( V_22 -> V_48 & V_235 ) ) {
T_23 * V_236 ;
V_236 = F_28 ( V_134 , V_240 , V_53 , 0 , 0 , V_50 -> V_232 ) ;
F_67 ( V_236 ) ;
}
F_70 ( V_241 , V_18 , V_22 ) ;
}
static int
F_71 ( T_20 * V_53 , T_7 * V_18 , T_21 * V_54 , void * V_46 )
{
T_26 * V_131 = ( T_26 * ) V_46 ;
if ( ! V_131 )
return 0 ;
F_31 ( V_53 , V_18 , V_54 , FALSE , V_131 ) ;
return F_72 ( V_53 ) ;
}
static int
F_73 ( T_20 * V_53 , T_7 * V_18 , T_21 * V_54 , void * V_46 V_19 )
{
T_26 V_131 ;
V_131 . V_216 = V_217 ;
V_131 . V_177 = 0 ;
F_31 ( V_53 , V_18 , V_54 , FALSE , & V_131 ) ;
return F_72 ( V_53 ) ;
}
static int
F_74 ( T_20 * V_53 , T_7 * V_18 , T_21 * V_54 , void * V_46 )
{
T_26 * V_131 = ( T_26 * ) V_46 ;
if ( ! V_131 )
return 0 ;
F_31 ( V_53 , V_18 , V_54 , TRUE , V_131 ) ;
return F_72 ( V_53 ) ;
}
static int
F_75 ( T_20 * V_53 , T_7 * V_18 , T_21 * V_54 , void * V_46 V_19 ) {
T_23 * V_236 ;
T_21 * V_242 ;
T_20 * V_135 ;
T_17 V_243 ;
T_17 V_244 ;
T_17 V_245 ;
const T_1 V_246 = 8 ;
const T_1 V_247 = 4 ;
T_1 V_248 = F_52 ( V_53 ) - V_246 ;
T_1 V_249 = V_248 + 4 ;
T_1 V_250 = 0 ;
T_1 V_251 ;
T_26 V_131 ;
F_18 ( V_18 -> V_57 , V_58 , L_11 ) ;
V_243 = F_37 ( V_53 , 0 ) ;
V_251 = V_248 - V_247 ;
V_244 = F_76 ( F_77 ( V_53 , 4 , V_251 ) , V_251 ) ;
V_245 = F_37 ( V_53 , V_249 ) ;
V_236 = F_45 ( V_54 , V_252 , V_53 , 0 ,
4 , L_26 ,
F_47 ( V_243 , V_253 , L_17 ) ,
F_47 ( V_245 , V_254 , L_17 ) ) ;
V_242 = F_27 ( V_236 , V_255 ) ;
F_28 ( V_242 , V_256 , V_53 , V_250 , 4 , V_243 ) ;
F_78 ( V_242 , V_53 , V_248 , V_257 , V_258 , & V_259 , V_18 , V_244 , V_62 , V_260 ) ;
F_28 ( V_242 , V_261 , V_53 , V_249 , 4 , V_245 ) ;
V_135 = F_58 ( V_53 , 4 ) ;
V_131 . V_216 = 0 ;
V_131 . V_177 = 0 ;
if ( V_243 == V_262 || V_243 == V_263 ) {
V_131 . V_177 = V_178 ;
} else if ( V_243 == V_264 ) {
V_131 . V_177 = V_179 ;
}
if ( V_245 == V_265 || V_245 == V_266 ) {
V_131 . V_177 |= V_180 ;
} else if ( V_245 == V_267 || V_245 == V_268 ) {
V_131 . V_177 |= V_269 ;
}
F_79 ( V_270 , V_135 , V_18 , V_54 , & V_131 ) ;
return F_72 ( V_53 ) ;
}
void
F_80 ( void )
{
static T_34 V_271 [] = {
{ & V_184 ,
{ L_27 , L_28 , V_272 , V_273 , NULL , 0x0 ,
NULL , V_274 } } ,
{ & V_190 ,
{ L_29 , L_30 , V_272 , V_273 , F_81 ( V_182 ) ,
0x0 , L_31 , V_274 } } ,
{ & V_191 ,
{ L_32 , L_2 , V_275 , V_276 , NULL , 0x0 ,
L_33 , V_274 } } ,
{ & V_194 ,
{ L_34 , L_35 , V_272 , V_273 , NULL , 0x0 ,
NULL , V_274 } } ,
{ & V_195 ,
{ L_36 , L_1 , V_275 , V_276 , NULL , 0x0 ,
L_37 , V_274 } } ,
{ & V_193 ,
{ L_38 , L_3 , V_275 , V_276 , NULL , 0x0 ,
L_39 , V_274 } } ,
{ & V_198 ,
{ L_40 , L_41 , V_272 , V_273 , F_81 ( V_43 ) , 0x0 ,
NULL , V_274 } } ,
{ & V_127 ,
{ L_42 , L_43 , V_277 , V_273 , NULL , 0x0 , NULL , V_274 } } ,
{ & V_200 ,
{ L_44 , L_45 , V_272 , V_273 , NULL , 0x0 ,
L_46 , V_274 } } ,
{ & V_201 ,
{ L_47 , L_48 , V_272 , V_273 , NULL , 0x0 , NULL , V_274 } } ,
{ & V_202 ,
{ L_49 , L_50 , V_278 , V_279 , NULL , 0x0 ,
L_51 , V_274 } } ,
{ & V_203 ,
{ L_52 , L_53 , V_278 , V_273 , NULL , 0x0 , L_54 ,
V_274 } } ,
{ & V_204 ,
{ L_55 , L_56 , V_278 , V_273 , NULL , 0x0 , L_57 ,
V_274 } } ,
{ & V_208 ,
{ L_58 , L_59 , V_280 , V_273 , NULL , 0x0 , NULL ,
V_274 } } ,
{ & V_228 ,
{ L_60 , L_61 , V_281 , V_282 , NULL ,
0x0 , NULL , V_274 } } ,
{ & V_213 ,
{ L_62 , L_63 , V_283 , V_282 , NULL ,
0x0 , NULL , V_274 } } ,
{ & V_214 ,
{ L_64 , L_65 , V_283 , V_282 , NULL ,
0x0 , NULL , V_274 } } ,
{ & V_61 ,
{ L_66 , L_67 , V_272 , V_273 ,
F_81 ( V_284 ) , 0x0 , NULL , V_274 } } ,
{ & V_63 ,
{ L_68 , L_69 , V_272 , V_273 , NULL ,
0x0 , NULL , V_274 } } ,
{ & V_64 ,
{ L_70 , L_71 , V_278 , V_273 , NULL , 0x0 , NULL , V_274 } } ,
{ & V_65 ,
{ L_72 , L_73 , V_278 , V_273 , NULL , 0x0 , NULL , V_274 } } ,
{ & V_66 ,
{ L_74 , L_75 , V_278 , V_273 , NULL , 0x0 , NULL ,
V_274 } } ,
{ & V_67 ,
{ L_76 , L_77 , V_278 , V_273 , NULL , 0x0 , NULL ,
V_274 } } ,
{ & V_69 ,
{ L_78 , L_79 , V_272 , V_273 , F_81 ( V_285 ) ,
0x0 , NULL , V_274 } } ,
{ & V_70 ,
{ L_80 , L_81 , V_272 , V_273 ,
F_81 ( V_286 ) , 0x0 , NULL , V_274 } } ,
{ & V_71 ,
{ L_82 , L_83 , V_272 , V_273 , NULL ,
0x0 , NULL , V_274 } } ,
{ & V_115 ,
{ L_84 , L_85 , V_281 , 24 , F_82 ( & V_287 ) ,
V_49 , L_86 , V_274 } } ,
{ & V_116 ,
{ L_87 , L_88 , V_281 , 24 , F_82 ( & V_288 ) ,
V_289 , L_89 , V_274 } } ,
{ & V_117 ,
{ L_90 , L_91 , V_281 , 24 , F_82 ( & V_290 ) ,
V_233 , L_92 , V_274 } } ,
{ & V_118 ,
{ L_93 , L_94 , V_281 , 24 , F_82 ( & V_291 ) ,
V_235 , L_95 , V_274 } } ,
{ & V_119 ,
{ L_96 , L_97 , V_281 , 24 , F_82 ( & V_292 ) ,
V_181 , L_98 , V_274 } } ,
{ & V_120 ,
{ L_99 , L_100 , V_281 , 24 , F_82 ( & V_293 ) ,
V_294 , L_101 , V_274 } } ,
{ & V_121 ,
{ L_102 , L_103 , V_281 , 24 , F_82 ( & V_295 ) ,
V_296 , L_104 , V_274 } } ,
{ & V_124 ,
{ L_105 , L_106 , V_281 , 24 , F_82 ( & V_297 ) ,
V_298 , L_107 , V_274 } } ,
{ & V_126 ,
{ L_108 , L_109 , V_281 , 24 , F_82 ( & V_299 ) ,
V_210 , L_110 , V_274 } } ,
{ & V_122 ,
{ L_111 , L_112 , V_277 , V_273 , F_81 ( V_300 ) ,
V_301 , L_113 , V_274 } } ,
{ & V_123 ,
{ L_114 , L_115 , V_277 , V_273 , F_81 ( V_302 ) ,
V_303 , L_116 , V_274 } } ,
{ & V_125 ,
{ L_117 , L_118 , V_277 , V_273 , F_81 ( V_304 ) ,
V_305 , L_119 , V_274 } } ,
#if 0
{ &hf_fc_fctl_abts_not_ack,
{"AnA", "fc.fctl.abts_not_ack", FT_UINT24, BASE_HEX, VALS(abts_not_ack_vals),
FC_FCTL_ABTS_MASK, "ABTS not ACK vals", HFILL}},
#endif
{ & V_237 ,
{ L_120 , L_121 , V_306 , V_282 , NULL ,
0 , L_122 , V_274 } } ,
{ & V_240 ,
{ L_123 , L_124 , V_306 , V_282 , NULL ,
0 , L_125 , V_274 } } ,
{ & V_239 ,
{ L_126 , L_127 , V_307 , V_282 , NULL ,
0 , L_128 , V_274 } } ,
{ & V_211 ,
{ L_129 , L_130 , V_280 , V_279 , NULL ,
0 , L_131 , V_274 } } ,
{ & V_106 ,
{ L_132 , L_133 , V_278 , V_279 , NULL ,
0 , NULL , V_274 } } ,
{ & V_108 ,
{ L_27 , L_134 , V_272 , V_273 , NULL ,
0 , NULL , V_274 } } ,
{ & V_109 ,
{ L_135 , L_136 , V_272 , V_279 , NULL ,
0 , L_137 , V_274 } } ,
{ & V_110 ,
{ L_40 , L_138 , V_272 , V_279 , NULL ,
0 , L_139 , V_274 } } ,
{ & V_111 ,
{ L_101 , L_138 , V_272 , V_279 , NULL ,
0 , L_140 , V_274 } } ,
{ & V_112 ,
{ L_141 , L_142 , V_278 , V_279 , NULL ,
0 , L_143 , V_274 } } ,
{ & V_113 ,
{ L_144 , L_145 , V_272 , V_279 , NULL ,
0 , L_146 , V_274 } } ,
} ;
static T_1 * V_308 [] = {
& V_176 ,
& V_60 ,
& V_107 ,
& V_128
} ;
static T_35 V_309 [] = {
{ & V_259 ,
{ L_147 , V_310 , V_311 , L_148 , V_312 } } ,
{ & V_215 ,
{ L_149 , V_313 , V_311 ,
L_150 , V_312 } } ,
#if 0
{ &ei_frag_size,
{ "fc.frag_size", PI_MALFORMED, PI_ERROR,
"Invalid fragment size", EXPFILL }}
#endif
} ;
T_36 * V_314 ;
T_37 * V_315 ;
static T_34 V_316 [] = {
{ & V_256 ,
{ L_151 , L_152 , V_280 , V_273 , F_81 ( V_253 ) , 0 ,
NULL , V_274 } } ,
{ & V_261 ,
{ L_153 , L_154 , V_280 , V_273 , F_81 ( V_254 ) , 0 ,
NULL , V_274 } } ,
{ & V_257 ,
{ L_155 , L_156 , V_280 , V_273 , NULL , 0 , NULL , V_274 } } ,
{ & V_258 ,
{ L_157 , L_158 , V_272 , V_282 , F_81 ( V_317 ) , 0 , NULL , V_274 } } ,
} ;
static T_1 * V_318 [] = {
& V_255 ,
& V_319 ,
& V_320
} ;
V_170 = F_83 ( L_12 , L_11 , L_159 ) ;
V_270 = F_84 ( L_159 , F_71 , V_170 ) ;
F_84 ( L_160 , F_74 , V_170 ) ;
V_241 = F_85 ( L_159 ) ;
F_86 ( V_170 , V_271 , F_87 ( V_271 ) ) ;
F_88 ( V_308 , F_87 ( V_308 ) ) ;
V_315 = F_89 ( V_170 ) ;
F_90 ( V_315 , V_309 , F_87 ( V_309 ) ) ;
V_229 = F_91 ( L_30 ,
L_161 ,
V_170 , V_272 , V_273 ) ;
V_314 = F_92 ( V_170 , NULL ) ;
F_93 ( V_314 ,
L_162 ,
L_163 ,
L_164
L_165 ,
& V_221 ) ;
F_94 ( V_314 ,
L_166 , L_167 ,
L_168
L_169 , 10 ,
& V_226 ) ;
V_223 = F_95 ( F_96 () , F_40 () , F_2 , F_1 ) ;
F_97 ( & V_225 ,
& V_321 ) ;
V_252 = F_83 ( L_170 , L_171 , L_172 ) ;
F_86 ( V_252 , V_316 , F_87 ( V_316 ) ) ;
F_88 ( V_318 , F_87 ( V_318 ) ) ;
V_322 = F_84 ( L_172 , F_75 , V_252 ) ;
F_98 ( V_170 , TRUE , F_4 , F_7 ) ;
F_99 ( V_170 , NULL , 1 , F_14 , F_9 , NULL ) ;
}
void
F_100 ( void )
{
F_101 ( L_173 , V_323 ,
F_102 ( F_73 , V_170 ) ) ;
F_101 ( L_173 , V_324 , V_322 ) ;
}
