void F_1 ( struct V_1 * V_2 )
{
union V_3 V_4 ;
memset ( & V_4 , 0 , sizeof( union V_3 ) ) ;
F_2 ( V_2 -> V_5 , V_6 , & V_4 , NULL ) ;
}
void F_3 ( struct V_1 * V_2 )
{
union V_3 V_4 ;
struct V_7 * V_8 = & V_2 -> V_9 ;
memset ( & V_4 , 0 , sizeof( union V_3 ) ) ;
V_4 . V_10 . V_11 = V_12 ;
memcpy ( V_4 . V_10 . V_13 , V_8 -> V_14 . V_15 . V_16 , V_17 ) ;
F_4 ( V_18 , L_1 ) ;
F_2 ( V_2 -> V_5 , V_19 , & V_4 , NULL ) ;
}
void F_5 ( struct V_1 * V_2 )
{
union V_3 V_4 ;
memset ( & V_4 , 0 , sizeof( union V_3 ) ) ;
V_4 . V_10 . V_11 = V_12 ;
F_6 ( V_4 . V_10 . V_13 ) ;
F_4 ( V_18 , L_2 ) ;
F_2 ( V_2 -> V_5 , V_19 , & V_4 , NULL ) ;
}
static char * F_7 ( struct V_1 * V_2 ,
struct V_20 * V_21 ,
struct V_22 * V_23 ,
char * V_24 , char * V_25 )
{
struct V_7 * V_8 = & ( V_2 -> V_9 ) ;
struct V_26 V_27 ;
T_1 V_28 ;
T_2 V_29 ;
T_3 V_30 = 0 ;
char V_31 [ V_32 ] ;
char * V_33 ;
T_1 V_34 = 0 , V_35 , V_36 = false ;
T_3 V_37 = 0 ;
T_4 V_38 = 0 , V_39 = 0 ;
T_1 V_40 = 0 ;
T_4 V_41 , V_42 ;
V_27 . V_43 = V_19 ;
V_27 . V_44 . V_10 . V_11 = V_12 ;
memcpy ( V_27 . V_44 . V_10 . V_13 , V_23 -> V_15 . V_16 , V_17 ) ;
V_24 = F_8 ( V_21 , V_24 , V_25 , & V_27 , V_45 ) ;
V_27 . V_43 = V_46 ;
V_27 . V_44 . V_47 . V_48 = 1 ;
V_27 . V_44 . V_47 . V_49 = F_9 ( T_1 , V_23 -> V_15 . V_50 . V_51 , 32 ) ;
V_24 = F_10 ( V_21 , V_24 , V_25 , & V_27 , V_23 -> V_15 . V_50 . V_50 ) ;
V_33 = F_11 ( & V_23 -> V_15 . V_52 [ 12 ] , V_53 , & V_30 , V_23 -> V_15 . V_54 - 12 ) ;
if ( V_33 && V_30 > 0 ) {
struct V_55 * V_56 ;
V_36 = true ;
V_56 = (struct V_55 * ) ( V_33 + 2 ) ;
memcpy ( & V_40 , V_56 -> V_57 . V_58 , 2 ) ;
V_38 = ! ! ( F_12 ( V_56 -> V_59 ) &
V_60 ) ;
V_39 = ! ! ( F_12 ( V_56 -> V_59 ) &
( V_61 |
V_62 ) ) ;
}
V_27 . V_43 = V_63 ;
if ( ( F_13 ( ( T_4 * ) & V_23 -> V_15 . V_64 ) ) ) {
if ( V_36 )
snprintf ( V_27 . V_44 . V_65 , V_66 , L_3 ) ;
else
snprintf ( V_27 . V_44 . V_65 , V_66 , L_4 ) ;
} else if ( ( F_14 ( ( T_4 * ) & V_23 -> V_15 . V_64 ) ) ) {
if ( V_36 )
snprintf ( V_27 . V_44 . V_65 , V_66 , L_5 ) ;
else
snprintf ( V_27 . V_44 . V_65 , V_66 , L_6 ) ;
} else {
if ( V_23 -> V_15 . V_67 . V_68 > 14 ) {
if ( V_36 )
snprintf ( V_27 . V_44 . V_65 , V_66 , L_7 ) ;
else
snprintf ( V_27 . V_44 . V_65 , V_66 , L_8 ) ;
} else {
if ( V_36 )
snprintf ( V_27 . V_44 . V_65 , V_66 , L_9 ) ;
else
snprintf ( V_27 . V_44 . V_65 , V_66 , L_10 ) ;
}
}
V_24 = F_8 ( V_21 , V_24 , V_25 , & V_27 , V_69 ) ;
V_27 . V_43 = V_70 ;
memcpy ( & V_29 , F_15 ( V_23 -> V_15 . V_52 ) , 2 ) ;
V_28 = F_12 ( V_29 ) ;
if ( ! F_16 ( V_28 ) ) {
if ( V_28 & V_71 )
V_27 . V_44 . V_72 = V_73 ;
else
V_27 . V_44 . V_72 = V_74 ;
V_24 = F_8 ( V_21 , V_24 , V_25 , & V_27 , V_75 ) ;
}
if ( V_23 -> V_15 . V_67 . V_68 < 1 )
V_23 -> V_15 . V_67 . V_68 = 1 ;
V_27 . V_43 = V_76 ;
V_27 . V_44 . V_77 . V_78 = F_17 ( V_23 -> V_15 . V_67 . V_68 ) * 100000 ;
V_27 . V_44 . V_77 . V_79 = 1 ;
V_27 . V_44 . V_77 . V_37 = V_23 -> V_15 . V_67 . V_68 ;
V_24 = F_8 ( V_21 , V_24 , V_25 , & V_27 , V_80 ) ;
V_27 . V_43 = V_81 ;
if ( V_28 & V_82 )
V_27 . V_44 . V_47 . V_48 = V_83 | V_84 ;
else
V_27 . V_44 . V_47 . V_48 = V_85 ;
V_27 . V_44 . V_47 . V_49 = 0 ;
V_24 = F_10 ( V_21 , V_24 , V_25 , & V_27 , V_23 -> V_15 . V_50 . V_50 ) ;
V_34 = 0 ;
V_33 = V_31 ;
V_33 += snprintf ( V_33 , V_32 - ( V_33 - V_31 ) , L_11 ) ;
while ( V_23 -> V_15 . V_64 [ V_37 ] != 0 ) {
V_35 = V_23 -> V_15 . V_64 [ V_37 ] & 0x7F ;
if ( V_35 > V_34 )
V_34 = V_35 ;
V_33 += snprintf ( V_33 , V_32 - ( V_33 - V_31 ) ,
L_12 , V_35 >> 1 , ( V_35 & 1 ) ? L_13 : L_14 ) ;
V_37 ++ ;
}
if ( V_36 ) {
if ( V_40 & 0x8000 )
V_34 = ( V_38 ) ? ( ( V_39 ) ? 300 : 270 ) : ( ( V_39 ) ? 144 : 130 ) ;
else if ( V_40 & 0x0080 )
;
else
V_34 = ( V_38 ) ? ( ( V_39 ) ? 150 : 135 ) : ( ( V_39 ) ? 72 : 65 ) ;
V_34 = V_34 * 2 ;
}
V_27 . V_43 = V_86 ;
V_27 . V_44 . V_87 . V_88 = 0 ;
V_27 . V_44 . V_87 . V_89 = 0 ;
V_27 . V_44 . V_87 . V_90 = V_34 * 500000 ;
V_24 = F_8 ( V_21 , V_24 , V_25 , & V_27 , V_91 ) ;
{
T_4 V_92 [ V_93 ] ;
T_4 V_94 [ 255 ] , V_95 [ 255 ] ;
T_1 V_96 = 0 , V_97 = 0 ;
T_4 * V_33 ;
F_18 ( V_23 -> V_15 . V_52 , V_23 -> V_15 . V_54 , V_95 , & V_97 , V_94 , & V_96 ) ;
F_19 ( V_98 , V_99 , ( L_15 , V_23 -> V_15 . V_50 . V_50 ) ) ;
F_19 ( V_98 , V_99 , ( L_16 , V_96 , V_97 ) ) ;
if ( V_96 > 0 ) {
V_33 = V_92 ;
memset ( V_92 , 0 , V_93 ) ;
V_33 += sprintf ( V_33 , L_17 ) ;
for ( V_37 = 0 ; V_37 < V_96 ; V_37 ++ )
V_33 += sprintf ( V_33 , L_18 , V_94 [ V_37 ] ) ;
memset ( & V_27 , 0 , sizeof( V_27 ) ) ;
V_27 . V_43 = V_100 ;
V_27 . V_44 . V_47 . V_49 = strlen ( V_92 ) ;
V_24 = F_10 ( V_21 , V_24 , V_25 , & V_27 , V_92 ) ;
memset ( & V_27 , 0 , sizeof( V_27 ) ) ;
V_27 . V_43 = V_101 ;
V_27 . V_44 . V_47 . V_49 = V_96 ;
V_24 = F_10 ( V_21 , V_24 , V_25 , & V_27 , V_94 ) ;
}
if ( V_97 > 0 ) {
V_33 = V_92 ;
memset ( V_92 , 0 , V_93 ) ;
V_33 += sprintf ( V_33 , L_19 ) ;
for ( V_37 = 0 ; V_37 < V_97 ; V_37 ++ )
V_33 += sprintf ( V_33 , L_18 , V_95 [ V_37 ] ) ;
memset ( & V_27 , 0 , sizeof( V_27 ) ) ;
V_27 . V_43 = V_100 ;
V_27 . V_44 . V_47 . V_49 = strlen ( V_92 ) ;
V_24 = F_10 ( V_21 , V_24 , V_25 , & V_27 , V_92 ) ;
memset ( & V_27 , 0 , sizeof( V_27 ) ) ;
V_27 . V_43 = V_101 ;
V_27 . V_44 . V_47 . V_49 = V_97 ;
V_24 = F_10 ( V_21 , V_24 , V_25 , & V_27 , V_95 ) ;
}
}
{
T_5 V_102 = 0 , V_103 ;
T_4 * V_104 = NULL ;
T_5 V_105 = 0 ;
T_4 * V_106 = V_23 -> V_15 . V_52 + V_107 ;
V_103 = V_23 -> V_15 . V_54 - V_107 ;
while ( V_102 < V_103 ) {
if ( F_20 ( & V_106 [ V_102 ] , & V_105 ) && ( V_105 > 2 ) ) {
V_104 = & V_106 [ V_102 ] ;
V_27 . V_43 = V_101 ;
V_27 . V_44 . V_47 . V_49 = ( T_1 ) V_105 ;
V_24 = F_10 ( V_21 , V_24 , V_25 , & V_27 , V_104 ) ;
}
V_102 += V_106 [ V_102 + 1 ] + 2 ;
}
}
V_27 . V_43 = V_108 ;
V_27 . V_44 . V_109 . V_110 = V_111 | V_112 | V_113 ;
if ( F_21 ( V_8 , V_114 ) == true &&
F_22 ( & V_8 -> V_14 . V_15 , & V_23 -> V_15 ) ) {
V_41 = V_2 -> V_115 . V_116 ;
V_42 = V_2 -> V_115 . V_117 ;
} else {
V_41 = V_23 -> V_15 . V_118 . V_119 ;
V_42 = V_23 -> V_15 . V_118 . V_120 ;
}
V_27 . V_44 . V_109 . V_121 = ( T_4 ) V_41 ;
V_27 . V_44 . V_109 . V_109 = ( T_4 ) V_42 ;
V_27 . V_44 . V_109 . V_122 = 0 ;
V_24 = F_8 ( V_21 , V_24 , V_25 , & V_27 , V_123 ) ;
return V_24 ;
}
static int F_23 ( struct V_124 * V_125 , T_3 V_90 )
{
struct V_1 * V_2 = (struct V_1 * ) F_24 ( V_125 ) ;
int V_126 = 0 ;
if ( ( V_90 & V_127 ) && ( V_90 & V_128 ) ) {
F_25 ( L_20 , V_90 ) ;
V_2 -> V_129 . V_130 = V_131 ;
V_2 -> V_129 . V_132 = V_133 ;
V_2 -> V_129 . V_134 = V_135 ;
} else if ( V_90 & V_127 ) {
F_25 ( L_21 , V_90 ) ;
V_2 -> V_129 . V_130 = V_131 ;
V_2 -> V_129 . V_132 = V_136 ;
V_2 -> V_129 . V_134 = V_137 ;
} else if ( V_90 & V_128 ) {
F_25 ( L_22 ) ;
if ( V_2 -> V_129 . V_132 < V_138 ) {
V_2 -> V_129 . V_132 = V_139 ;
V_2 -> V_129 . V_134 = V_140 ;
}
} else if ( V_90 & V_141 ) {
F_25 ( L_23 ) ;
} else {
F_25 ( L_24 ) ;
V_126 = - V_142 ;
}
return V_126 ;
}
static int F_26 ( struct V_124 * V_125 , struct V_143 * V_144 , T_3 V_145 )
{
int V_126 = 0 ;
T_3 V_146 , V_147 , V_148 ;
struct V_149 * V_150 = NULL ;
struct V_1 * V_2 = (struct V_1 * ) F_24 ( V_125 ) ;
struct V_7 * V_8 = & V_2 -> V_9 ;
struct V_151 * V_152 = & V_2 -> V_129 ;
V_144 -> V_44 . V_153 . V_154 = 0 ;
V_144 -> V_44 . V_153 . V_155 [ V_156 - 1 ] = '\0' ;
if ( V_145 < ( T_3 ) ( ( T_4 * ) V_144 -> V_44 . V_153 . V_157 - ( T_4 * ) V_144 ) + V_144 -> V_44 . V_153 . V_158 ) {
V_126 = - V_142 ;
goto exit;
}
if ( V_144 -> V_159 [ 0 ] == 0xff && V_144 -> V_159 [ 1 ] == 0xff &&
V_144 -> V_159 [ 2 ] == 0xff && V_144 -> V_159 [ 3 ] == 0xff &&
V_144 -> V_159 [ 4 ] == 0xff && V_144 -> V_159 [ 5 ] == 0xff ) {
if ( V_144 -> V_44 . V_153 . V_160 >= V_161 ) {
V_126 = - V_142 ;
goto exit;
}
} else {
V_126 = - V_142 ;
goto exit;
}
if ( strcmp ( V_144 -> V_44 . V_153 . V_155 , L_25 ) == 0 ) {
F_19 ( V_162 , V_163 , ( L_26 ) ) ;
F_25 ( L_26 ) ;
V_2 -> V_129 . V_130 = V_131 ;
V_2 -> V_129 . V_164 = V_165 ;
V_2 -> V_129 . V_166 = V_165 ;
V_146 = V_144 -> V_44 . V_153 . V_160 ;
V_147 = V_144 -> V_44 . V_153 . V_158 ;
F_19 ( V_162 , V_99 , ( L_27 , V_146 ) ) ;
F_25 ( L_27 , V_146 ) ;
if ( V_146 > V_161 )
return - V_142 ;
F_19 ( V_162 , V_99 , ( L_28 , V_146 ) ) ;
if ( V_147 > 0 ) {
V_147 = V_147 <= 5 ? 5 : 13 ;
V_148 = V_147 + F_27 ( struct V_149 , V_167 ) ;
V_150 = (struct V_149 * ) F_28 ( V_148 ) ;
if ( ! V_150 ) {
F_19 ( V_162 , V_163 , ( L_29 ) ) ;
goto exit;
}
memset ( V_150 , 0 , V_148 ) ;
V_150 -> V_168 = V_147 ;
V_150 -> V_169 = V_148 ;
if ( V_147 == 13 ) {
V_2 -> V_129 . V_164 = V_170 ;
V_2 -> V_129 . V_166 = V_170 ;
}
} else {
V_126 = - V_142 ;
goto exit;
}
V_150 -> V_171 = V_146 ;
V_150 -> V_171 |= 0x80000000 ;
memcpy ( V_150 -> V_167 , V_144 -> V_44 . V_153 . V_157 , V_150 -> V_168 ) ;
if ( V_144 -> V_44 . V_153 . V_172 ) {
F_25 ( L_30 ) ;
if ( F_29 ( V_2 , V_150 ) == ( T_4 ) V_173 )
V_126 = - V_174 ;
} else {
F_25 ( L_31 ) ;
if ( V_146 >= V_161 ) {
V_126 = - V_174 ;
goto exit;
}
memcpy ( & ( V_152 -> V_175 [ V_146 ] . V_176 [ 0 ] ) , V_150 -> V_167 , V_150 -> V_168 ) ;
V_152 -> V_177 [ V_146 ] = V_150 -> V_168 ;
F_30 ( V_2 , V_152 , V_146 , 0 ) ;
}
goto exit;
}
if ( V_2 -> V_129 . V_134 == V_178 ) {
struct V_179 * V_180 , * V_181 ;
struct V_182 * V_183 = & V_2 -> V_184 ;
if ( F_21 ( V_8 , V_185 | V_186 ) ) {
V_180 = F_31 ( V_183 , F_32 ( V_8 ) ) ;
if ( ! V_180 ) {
;
} else {
if ( strcmp ( V_144 -> V_44 . V_153 . V_155 , L_32 ) != 0 )
V_180 -> V_187 = false ;
if ( ( V_2 -> V_129 . V_130 == V_188 ) ||
( V_2 -> V_129 . V_130 == V_189 ) )
V_180 -> V_190 = V_2 -> V_129 . V_164 ;
if ( V_144 -> V_44 . V_153 . V_172 == 1 ) {
memcpy ( V_180 -> V_191 . V_176 , V_144 -> V_44 . V_153 . V_157 , F_9 ( T_1 , V_144 -> V_44 . V_153 . V_158 , 16 ) ) ;
if ( strcmp ( V_144 -> V_44 . V_153 . V_155 , L_33 ) == 0 ) {
memcpy ( V_180 -> V_192 . V_176 , & ( V_144 -> V_44 . V_153 . V_157 [ 16 ] ) , 8 ) ;
memcpy ( V_180 -> V_193 . V_176 , & ( V_144 -> V_44 . V_153 . V_157 [ 24 ] ) , 8 ) ;
V_2 -> V_129 . V_194 = false ;
}
F_25 ( L_34 ) ;
F_33 ( V_2 , ( unsigned char * ) V_180 , true ) ;
} else {
memcpy ( V_2 -> V_129 . V_195 [ V_144 -> V_44 . V_153 . V_160 ] . V_176 , V_144 -> V_44 . V_153 . V_157 , F_9 ( T_1 , V_144 -> V_44 . V_153 . V_158 , 16 ) ) ;
memcpy ( V_2 -> V_129 . V_196 [ V_144 -> V_44 . V_153 . V_160 ] . V_176 , & ( V_144 -> V_44 . V_153 . V_157 [ 16 ] ) , 8 ) ;
memcpy ( V_2 -> V_129 . V_197 [ V_144 -> V_44 . V_153 . V_160 ] . V_176 , & ( V_144 -> V_44 . V_153 . V_157 [ 24 ] ) , 8 ) ;
V_2 -> V_129 . V_198 = true ;
F_25 ( L_35 ) ;
V_2 -> V_129 . V_199 = V_144 -> V_44 . V_153 . V_160 ;
F_30 ( V_2 , & V_2 -> V_129 , V_144 -> V_44 . V_153 . V_160 , 1 ) ;
}
}
V_181 = F_34 ( V_2 ) ;
if ( ! V_181 ) {
;
} else {
if ( strcmp ( V_144 -> V_44 . V_153 . V_155 , L_32 ) != 0 )
V_181 -> V_187 = false ;
if ( ( V_2 -> V_129 . V_130 == V_188 ) ||
( V_2 -> V_129 . V_130 == V_189 ) )
V_181 -> V_190 = V_2 -> V_129 . V_164 ;
}
}
}
exit:
F_35 ( V_150 ) ;
return V_126 ;
}
static int F_36 ( struct V_1 * V_2 , char * V_200 , unsigned short V_201 )
{
T_4 * V_92 = NULL ;
int V_202 = 0 , V_203 = 0 ;
int V_126 = 0 ;
if ( ( V_201 > V_93 ) || ( ! V_200 ) ) {
F_37 ( & V_2 -> V_9 , V_204 ) ;
if ( ! V_200 )
return V_126 ;
else
return - V_142 ;
}
if ( V_201 ) {
V_92 = F_38 ( V_200 , V_201 , V_205 ) ;
if ( ! V_92 ) {
V_126 = - V_206 ;
goto exit;
}
{
int V_37 ;
F_25 ( L_36 , V_201 ) ;
for ( V_37 = 0 ; V_37 < V_201 ; V_37 += 8 )
F_25 ( L_37 , V_92 [ V_37 ] , V_92 [ V_37 + 1 ] , V_92 [ V_37 + 2 ] , V_92 [ V_37 + 3 ] , V_92 [ V_37 + 4 ] , V_92 [ V_37 + 5 ] , V_92 [ V_37 + 6 ] , V_92 [ V_37 + 7 ] ) ;
}
if ( V_201 < V_207 ) {
F_19 ( V_162 , V_163 , ( L_38 , V_201 ) ) ;
V_126 = - 1 ;
goto exit;
}
if ( F_39 ( V_92 , V_201 , & V_202 , & V_203 , NULL ) == V_208 ) {
V_2 -> V_129 . V_134 = V_178 ;
V_2 -> V_129 . V_132 = V_138 ;
memcpy ( V_2 -> V_129 . V_209 , & V_92 [ 0 ] , V_201 ) ;
}
if ( F_40 ( V_92 , V_201 , & V_202 , & V_203 , NULL ) == V_208 ) {
V_2 -> V_129 . V_134 = V_178 ;
V_2 -> V_129 . V_132 = V_210 ;
memcpy ( V_2 -> V_129 . V_209 , & V_92 [ 0 ] , V_201 ) ;
}
switch ( V_202 ) {
case V_211 :
V_2 -> V_129 . V_166 = V_212 ;
V_2 -> V_129 . V_130 = V_213 ;
break;
case V_214 :
V_2 -> V_129 . V_166 = V_165 ;
V_2 -> V_129 . V_130 = V_131 ;
break;
case V_215 :
V_2 -> V_129 . V_166 = V_216 ;
V_2 -> V_129 . V_130 = V_188 ;
break;
case V_217 :
V_2 -> V_129 . V_166 = V_218 ;
V_2 -> V_129 . V_130 = V_189 ;
break;
case V_219 :
V_2 -> V_129 . V_166 = V_170 ;
V_2 -> V_129 . V_130 = V_131 ;
break;
}
switch ( V_203 ) {
case V_211 :
V_2 -> V_129 . V_164 = V_212 ;
V_2 -> V_129 . V_130 = V_213 ;
break;
case V_214 :
V_2 -> V_129 . V_164 = V_165 ;
V_2 -> V_129 . V_130 = V_131 ;
break;
case V_215 :
V_2 -> V_129 . V_164 = V_216 ;
V_2 -> V_129 . V_130 = V_188 ;
break;
case V_217 :
V_2 -> V_129 . V_164 = V_218 ;
V_2 -> V_129 . V_130 = V_189 ;
break;
case V_219 :
V_2 -> V_129 . V_164 = V_170 ;
V_2 -> V_129 . V_130 = V_131 ;
break;
}
F_37 ( & V_2 -> V_9 , V_204 ) ;
{
T_1 V_102 = 0 ;
T_4 V_220 , V_221 [ 4 ] = { 0x0 , 0x50 , 0xf2 , 0x04 } ;
while ( V_102 < V_201 ) {
V_220 = V_92 [ V_102 ] ;
if ( ( V_220 == V_222 ) && ( ! memcmp ( & V_92 [ V_102 + 2 ] , V_221 , 4 ) ) ) {
F_25 ( L_39 ) ;
V_2 -> V_129 . V_223 = F_41 ( V_92 [ V_102 + 1 ] + 2 , V_93 << 2 ) ;
memcpy ( V_2 -> V_129 . V_224 , & V_92 [ V_102 ] , V_2 -> V_129 . V_223 ) ;
F_42 ( & V_2 -> V_9 , V_204 ) ;
V_102 += V_92 [ V_102 + 1 ] + 2 ;
break;
} else {
V_102 += V_92 [ V_102 + 1 ] + 2 ;
}
}
}
}
F_19 ( V_162 , V_99 ,
( L_40 ,
V_203 , V_2 -> V_129 . V_130 , V_2 -> V_129 . V_132 ) ) ;
exit:
F_35 ( V_92 ) ;
return V_126 ;
}
static int F_43 ( struct V_124 * V_125 ,
struct V_20 * V_21 ,
union V_3 * V_4 , char * V_225 )
{
struct V_1 * V_2 = (struct V_1 * ) F_24 ( V_125 ) ;
T_3 V_30 = 0 ;
char * V_33 ;
T_4 V_36 = false ;
struct V_7 * V_8 = & ( V_2 -> V_9 ) ;
struct V_226 * V_227 = & V_8 -> V_14 . V_15 ;
T_6 * V_228 = NULL ;
F_19 ( V_98 , V_99 , ( L_41 , V_21 -> V_43 ) ) ;
if ( F_21 ( V_8 , V_114 | V_229 ) == true ) {
V_33 = F_11 ( & V_227 -> V_52 [ 12 ] , V_53 , & V_30 , V_227 -> V_54 - 12 ) ;
if ( V_33 && V_30 > 0 )
V_36 = true ;
V_228 = & V_227 -> V_64 ;
if ( F_13 ( ( T_4 * ) V_228 ) == true ) {
if ( V_36 )
snprintf ( V_4 -> V_65 , V_66 , L_3 ) ;
else
snprintf ( V_4 -> V_65 , V_66 , L_4 ) ;
} else if ( ( F_14 ( ( T_4 * ) V_228 ) ) == true ) {
if ( V_36 )
snprintf ( V_4 -> V_65 , V_66 , L_5 ) ;
else
snprintf ( V_4 -> V_65 , V_66 , L_6 ) ;
} else {
if ( V_227 -> V_67 . V_68 > 14 ) {
if ( V_36 )
snprintf ( V_4 -> V_65 , V_66 , L_7 ) ;
else
snprintf ( V_4 -> V_65 , V_66 , L_8 ) ;
} else {
if ( V_36 )
snprintf ( V_4 -> V_65 , V_66 , L_9 ) ;
else
snprintf ( V_4 -> V_65 , V_66 , L_10 ) ;
}
}
} else {
snprintf ( V_4 -> V_65 , V_66 , L_42 ) ;
}
return 0 ;
}
static int F_44 ( struct V_124 * V_125 ,
struct V_20 * V_21 ,
union V_3 * V_4 , char * V_225 )
{
F_19 ( V_98 , V_230 , ( L_43 ) ) ;
return 0 ;
}
static int F_45 ( struct V_124 * V_125 ,
struct V_20 * V_21 ,
union V_3 * V_4 , char * V_225 )
{
struct V_1 * V_2 = (struct V_1 * ) F_24 ( V_125 ) ;
struct V_7 * V_8 = & ( V_2 -> V_9 ) ;
struct V_226 * V_227 = & V_8 -> V_14 . V_15 ;
if ( F_21 ( V_8 , V_114 ) ) {
V_4 -> V_77 . V_78 = F_17 ( V_227 -> V_67 . V_68 ) * 100000 ;
V_4 -> V_77 . V_79 = 1 ;
V_4 -> V_77 . V_37 = V_227 -> V_67 . V_68 ;
} else {
V_4 -> V_77 . V_78 = F_17 ( V_2 -> V_231 . V_232 ) * 100000 ;
V_4 -> V_77 . V_79 = 1 ;
V_4 -> V_77 . V_37 = V_2 -> V_231 . V_232 ;
}
return 0 ;
}
static int F_46 ( struct V_124 * V_125 , struct V_20 * V_233 ,
union V_3 * V_4 , char * V_234 )
{
struct V_1 * V_2 = (struct V_1 * ) F_24 ( V_125 ) ;
enum V_235 V_236 ;
int V_126 = 0 ;
if ( V_173 == F_47 ( V_2 ) ) {
V_126 = - V_237 ;
goto exit;
}
if ( ! V_2 -> V_238 ) {
V_126 = - V_237 ;
goto exit;
}
switch ( V_4 -> V_72 ) {
case V_239 :
V_236 = V_240 ;
F_25 ( L_44 ) ;
break;
case V_74 :
V_236 = V_241 ;
F_25 ( L_45 ) ;
break;
case V_73 :
V_236 = V_242 ;
F_25 ( L_46 ) ;
break;
case V_243 :
V_236 = V_244 ;
F_25 ( L_47 ) ;
break;
default:
V_126 = - V_142 ;
F_19 ( V_162 , V_163 , ( L_48 , V_245 [ V_4 -> V_72 ] ) ) ;
goto exit;
}
if ( F_48 ( V_2 , V_236 ) == false ) {
V_126 = - V_237 ;
goto exit;
}
F_49 ( V_2 , V_236 ) ;
exit:
return V_126 ;
}
static int F_50 ( struct V_124 * V_125 , struct V_20 * V_233 ,
union V_3 * V_4 , char * V_234 )
{
struct V_1 * V_2 = (struct V_1 * ) F_24 ( V_125 ) ;
struct V_7 * V_8 = & ( V_2 -> V_9 ) ;
F_19 ( V_98 , V_99 , ( L_49 ) ) ;
if ( F_21 ( V_8 , V_185 ) )
V_4 -> V_72 = V_243 ;
else if ( ( F_21 ( V_8 , V_229 ) ) ||
( F_21 ( V_8 , V_246 ) ) )
V_4 -> V_72 = V_74 ;
else if ( F_21 ( V_8 , V_247 ) )
V_4 -> V_72 = V_73 ;
else
V_4 -> V_72 = V_239 ;
return 0 ;
}
static int F_51 ( struct V_124 * V_125 ,
struct V_20 * V_233 ,
union V_3 * V_4 , char * V_225 )
{
struct V_1 * V_2 = (struct V_1 * ) F_24 ( V_125 ) ;
T_4 V_248 , V_249 = false ;
int V_126 = false ;
struct V_151 * V_152 = & V_2 -> V_129 ;
struct V_250 * V_251 = (struct V_250 * ) V_225 ;
T_4 V_252 [ V_17 ] = { 0x00 } ;
T_4 V_253 [ V_17 ] = { 0x00 } ;
memcpy ( V_253 , V_251 -> V_254 . V_13 , V_17 ) ;
if ( V_251 -> V_43 == V_255 ) {
F_25 ( L_50 ) ;
if ( ! memcmp ( V_253 , V_252 , V_17 ) )
return V_126 ;
else
V_126 = true ;
V_249 = false ;
for ( V_248 = 0 ; V_248 < V_256 ; V_248 ++ ) {
if ( ! memcmp ( V_152 -> V_257 [ V_248 ] . V_258 , V_253 , V_17 ) ) {
F_25 ( L_51 ) ;
memcpy ( V_152 -> V_257 [ V_248 ] . V_259 , V_251 -> V_260 , V_261 ) ;
V_152 -> V_257 [ V_248 ] . V_262 = true ;
V_152 -> V_263 = V_248 + 1 ;
V_249 = true ;
break;
}
}
if ( ! V_249 ) {
F_25 ( L_52 ,
V_152 -> V_263 ) ;
memcpy ( V_152 -> V_257 [ V_152 -> V_263 ] . V_258 , V_253 , V_17 ) ;
memcpy ( V_152 -> V_257 [ V_152 -> V_263 ] . V_259 , V_251 -> V_260 , V_261 ) ;
V_152 -> V_257 [ V_152 -> V_263 ] . V_262 = true ;
V_152 -> V_263 ++ ;
if ( V_152 -> V_263 == 16 )
V_152 -> V_263 = 0 ;
}
} else if ( V_251 -> V_43 == V_264 ) {
F_25 ( L_53 ) ;
V_126 = true ;
for ( V_248 = 0 ; V_248 < V_256 ; V_248 ++ ) {
if ( ! memcmp ( V_152 -> V_257 [ V_248 ] . V_258 , V_253 , V_17 ) ) {
F_6 ( V_152 -> V_257 [ V_248 ] . V_258 ) ;
V_152 -> V_257 [ V_248 ] . V_262 = false ;
break;
}
}
} else if ( V_251 -> V_43 == V_265 ) {
F_25 ( L_54 ) ;
memset ( & V_152 -> V_257 [ 0 ] , 0x00 , sizeof( struct V_266 ) * V_256 ) ;
V_152 -> V_263 = 0 ;
V_126 = true ;
}
return V_126 ;
}
static int F_52 ( struct V_124 * V_125 ,
struct V_20 * V_21 ,
union V_3 * V_4 , char * V_225 )
{
V_4 -> V_267 . V_90 = 0 ;
V_4 -> V_267 . V_88 = 0 ;
V_4 -> V_267 . V_89 = 1 ;
return 0 ;
}
static int F_53 ( struct V_124 * V_125 ,
struct V_20 * V_21 ,
union V_3 * V_4 , char * V_225 )
{
struct V_268 * V_269 = (struct V_268 * ) V_225 ;
struct V_1 * V_2 = (struct V_1 * ) F_24 ( V_125 ) ;
struct V_270 * V_271 = & V_2 -> V_231 ;
T_1 V_272 ;
int V_37 ;
F_19 ( V_98 , V_99 , ( L_55 , V_21 -> V_43 ) ) ;
V_4 -> V_47 . V_49 = sizeof( * V_269 ) ;
memset ( V_269 , 0 , sizeof( * V_269 ) ) ;
V_269 -> V_273 = 5 * 1000 * 1000 ;
V_269 -> V_274 . V_109 = 100 ;
V_269 -> V_274 . V_121 = 100 ;
V_269 -> V_274 . V_122 = 100 ;
V_269 -> V_274 . V_110 = 7 ;
V_269 -> V_275 . V_109 = 92 ;
V_269 -> V_275 . V_121 = 178 ;
V_269 -> V_275 . V_122 = 0 ;
V_269 -> V_275 . V_110 = 7 ;
V_269 -> V_276 = V_277 ;
for ( V_37 = 0 ; V_37 < V_277 && V_37 < V_278 ; V_37 ++ )
V_269 -> V_87 [ V_37 ] = V_279 [ V_37 ] ;
V_269 -> V_280 = V_281 ;
V_269 -> V_282 = V_283 ;
V_269 -> V_284 = 0 ;
V_269 -> V_285 = V_286 ;
V_269 -> V_287 = 16 ;
for ( V_37 = 0 , V_272 = 0 ; V_37 < V_288 ; V_37 ++ ) {
if ( V_271 -> V_289 [ V_37 ] . V_290 != 0 ) {
V_269 -> V_77 [ V_272 ] . V_37 = V_271 -> V_289 [ V_37 ] . V_290 ;
V_269 -> V_77 [ V_272 ] . V_78 = F_17 ( V_271 -> V_289 [ V_37 ] . V_290 ) * 100000 ;
V_269 -> V_77 [ V_272 ] . V_79 = 1 ;
V_272 ++ ;
}
if ( V_272 == V_291 )
break;
}
V_269 -> V_292 = V_272 ;
V_269 -> V_293 = V_272 ;
V_269 -> V_294 = V_295 | V_296 |
V_297 | V_298 ;
V_269 -> V_299 = V_300 | V_301 |
V_302 | V_303 |
V_304 | V_305 ;
return 0 ;
}
static int F_54 ( struct V_124 * V_125 ,
struct V_20 * V_21 ,
union V_3 * V_306 ,
char * V_225 )
{
T_5 V_126 = 0 ;
struct V_1 * V_2 = (struct V_1 * ) F_24 ( V_125 ) ;
struct V_307 * V_308 = (struct V_307 * ) V_306 ;
struct V_7 * V_8 = & ( V_2 -> V_9 ) ;
struct V_309 * V_310 ;
T_4 * V_311 , * V_312 ;
struct V_313 * V_314 = & ( V_8 -> V_315 ) ;
struct V_22 * V_23 = NULL ;
enum V_316 V_317 ;
if ( V_173 == F_47 ( V_2 ) ) {
V_126 = - 1 ;
goto exit;
}
if ( ! V_2 -> V_318 ) {
V_126 = - 1 ;
goto exit;
}
if ( V_308 -> V_11 != V_12 ) {
V_126 = - V_142 ;
goto exit;
}
V_317 = V_2 -> V_129 . V_132 ;
F_55 ( & V_314 -> V_319 ) ;
V_310 = F_56 ( V_314 ) ;
V_8 -> V_320 = V_310 -> V_321 ;
while ( V_310 != V_8 -> V_320 ) {
V_23 = F_57 ( V_8 -> V_320 , struct V_22 , V_322 ) ;
V_8 -> V_320 = V_8 -> V_320 -> V_321 ;
V_311 = V_23 -> V_15 . V_16 ;
V_312 = V_308 -> V_13 ;
if ( ( ! memcmp ( V_311 , V_312 , V_17 ) ) ) {
if ( ! F_48 ( V_2 , V_23 -> V_15 . V_323 ) ) {
V_126 = - 1 ;
F_58 ( & V_314 -> V_319 ) ;
goto exit;
}
break;
}
}
F_58 ( & V_314 -> V_319 ) ;
F_59 ( V_2 , V_317 ) ;
if ( F_60 ( V_2 , V_308 -> V_13 ) == false ) {
V_126 = - 1 ;
goto exit;
}
exit:
return V_126 ;
}
static int F_61 ( struct V_124 * V_125 ,
struct V_20 * V_21 ,
union V_3 * V_4 , char * V_225 )
{
struct V_1 * V_2 = (struct V_1 * ) F_24 ( V_125 ) ;
struct V_7 * V_8 = & ( V_2 -> V_9 ) ;
struct V_226 * V_227 = & V_8 -> V_14 . V_15 ;
V_4 -> V_10 . V_11 = V_12 ;
F_6 ( V_4 -> V_10 . V_13 ) ;
F_19 ( V_98 , V_99 , ( L_56 ) ) ;
if ( ( ( F_21 ( V_8 , V_114 ) ) == true ) ||
( ( F_21 ( V_8 , V_229 ) ) == true ) ||
( ( F_21 ( V_8 , V_247 ) ) == true ) )
memcpy ( V_4 -> V_10 . V_13 , V_227 -> V_16 , V_17 ) ;
else
F_6 ( V_4 -> V_10 . V_13 ) ;
return 0 ;
}
static int F_62 ( struct V_124 * V_125 ,
struct V_20 * V_21 ,
union V_3 * V_4 , char * V_225 )
{
int V_126 = 0 ;
T_1 V_324 ;
struct V_1 * V_2 = (struct V_1 * ) F_24 ( V_125 ) ;
struct V_325 * V_326 = (struct V_325 * ) V_225 ;
if ( ! V_326 )
return - 1 ;
F_25 ( L_57 , V_327 ) ;
V_324 = V_326 -> V_328 ;
F_25 ( L_58 , V_327 , V_326 -> V_43 , V_324 ) ;
switch ( V_326 -> V_43 ) {
case V_329 :
if ( ! F_63 ( V_2 ) )
V_126 = - 1 ;
break;
case V_330 :
if ( ! F_63 ( V_2 ) )
V_126 = - 1 ;
break;
default:
return - V_174 ;
}
return V_126 ;
}
static int F_64 ( struct V_124 * V_125 , struct V_20 * V_233 ,
union V_3 * V_4 , char * V_225 )
{
T_4 V_331 = false ;
int V_126 = 0 ;
struct V_1 * V_2 = (struct V_1 * ) F_24 ( V_125 ) ;
struct V_7 * V_8 = & V_2 -> V_9 ;
struct V_332 V_333 [ V_334 ] ;
F_19 ( V_98 , V_99 , ( L_59 ) ) ;
if ( V_2 -> V_335 . V_336 == 1 ) {
if ( F_21 ( V_8 , V_186 ) ) {
V_126 = - 1 ;
goto exit;
}
}
if ( V_173 == F_47 ( V_2 ) ) {
V_126 = - 1 ;
goto exit;
}
if ( V_2 -> V_337 ) {
F_25 ( L_60 , V_2 -> V_337 ) ;
V_126 = - 1 ;
goto exit;
}
if ( ! V_2 -> V_318 ) {
V_126 = - 1 ;
goto exit;
}
if ( ! V_2 -> V_238 ) {
V_126 = - 1 ;
goto exit;
}
if ( V_8 -> V_338 . V_339 ) {
F_1 ( V_2 ) ;
goto exit;
}
if ( F_21 ( V_8 , V_340 | V_341 ) ) {
F_1 ( V_2 ) ;
goto exit;
}
memset ( V_333 , 0 , sizeof( struct V_332 ) * V_334 ) ;
if ( V_4 -> V_47 . V_49 == sizeof( struct V_342 ) ) {
struct V_342 * V_343 = (struct V_342 * ) V_225 ;
if ( V_4 -> V_47 . V_48 & V_344 ) {
int V_345 = F_9 ( int , V_343 -> V_346 ,
V_347 ) ;
memcpy ( V_333 [ 0 ] . V_50 , V_343 -> V_348 , V_345 ) ;
V_333 [ 0 ] . V_51 = V_345 ;
F_25 ( L_61 , V_343 -> V_348 , V_343 -> V_346 ) ;
F_55 ( & V_8 -> V_319 ) ;
V_331 = F_65 ( V_2 , V_333 , 1 , NULL , 0 ) ;
F_58 ( & V_8 -> V_319 ) ;
} else if ( V_343 -> V_349 == V_350 ) {
F_25 ( L_62 ) ;
}
} else {
if ( V_4 -> V_47 . V_49 >= V_351 &&
! memcmp ( V_225 , V_352 , V_351 ) ) {
int V_345 = V_4 -> V_47 . V_49 - V_351 ;
char * V_353 = V_225 + V_351 ;
char V_354 ;
char V_355 ;
int V_356 = 0 ;
while ( V_345 >= 1 ) {
V_354 = * ( V_353 ++ ) ;
V_345 -= 1 ;
switch ( V_354 ) {
case V_357 :
if ( V_345 < 1 ) {
V_345 = 0 ;
break;
}
V_355 = * ( V_353 ++ ) ; V_345 -= 1 ;
if ( V_355 > 0 && V_355 <= V_345 ) {
V_333 [ V_356 ] . V_51 = V_355 ;
memcpy ( V_333 [ V_356 ] . V_50 , V_353 , V_333 [ V_356 ] . V_51 ) ;
V_356 ++ ;
}
V_353 += V_355 ;
V_345 -= V_355 ;
break;
case V_358 :
case V_359 :
V_353 += 1 ;
V_345 -= 1 ;
break;
case V_360 :
case V_361 :
case V_362 :
V_353 += 2 ;
V_345 -= 2 ;
break;
default:
V_345 = 0 ;
}
}
V_331 = F_66 ( V_2 , V_333 , V_334 ) ;
} else {
V_331 = F_66 ( V_2 , NULL , 0 ) ;
}
}
if ( ! V_331 )
V_126 = - 1 ;
exit:
return V_126 ;
}
static int F_67 ( struct V_124 * V_125 , struct V_20 * V_233 ,
union V_3 * V_4 , char * V_225 )
{
struct V_309 * V_363 , * V_310 ;
struct V_1 * V_2 = (struct V_1 * ) F_24 ( V_125 ) ;
struct V_7 * V_8 = & ( V_2 -> V_9 ) ;
struct V_313 * V_314 = & ( V_8 -> V_315 ) ;
struct V_22 * V_23 = NULL ;
char * V_364 = V_225 ;
char * V_25 = V_364 + V_4 -> V_47 . V_49 ;
T_3 V_126 = 0 ;
T_3 V_102 = 0 ;
T_3 V_365 ;
int V_366 ;
F_19 ( V_98 , V_99 , ( L_63 ) ) ;
F_19 ( V_162 , V_99 , ( L_64 ) ) ;
if ( V_2 -> V_367 . V_368 && V_2 -> V_337 ) {
V_126 = - V_142 ;
goto exit;
}
V_365 = 100 ;
V_366 = V_340 | V_341 ;
while ( F_21 ( V_8 , V_366 ) ) {
F_68 ( 30 ) ;
V_102 ++ ;
if ( V_102 > V_365 )
break;
}
F_55 ( & ( V_8 -> V_315 . V_319 ) ) ;
V_310 = F_56 ( V_314 ) ;
V_363 = V_310 -> V_321 ;
while ( V_310 != V_363 ) {
if ( ( V_25 - V_364 ) < V_369 ) {
V_126 = - V_370 ;
break;
}
V_23 = F_57 ( V_363 , struct V_22 , V_322 ) ;
if ( F_69 ( V_2 -> V_231 . V_289 , V_23 -> V_15 . V_67 . V_68 ) >= 0 )
V_364 = F_7 ( V_2 , V_233 , V_23 , V_364 , V_25 ) ;
V_363 = V_363 -> V_321 ;
}
F_58 ( & V_8 -> V_315 . V_319 ) ;
V_4 -> V_47 . V_49 = V_364 - V_225 ;
V_4 -> V_47 . V_48 = 0 ;
exit:
return V_126 ;
}
static int F_70 ( struct V_124 * V_125 ,
struct V_20 * V_233 ,
union V_3 * V_4 , char * V_225 )
{
struct V_1 * V_2 = (struct V_1 * ) F_24 ( V_125 ) ;
struct V_7 * V_8 = & V_2 -> V_9 ;
struct V_313 * V_314 = & V_8 -> V_315 ;
struct V_309 * V_310 ;
struct V_22 * V_23 = NULL ;
enum V_316 V_317 ;
struct V_332 V_371 ;
T_4 * V_372 , * V_373 ;
T_5 V_126 = 0 , V_345 ;
F_19 ( V_162 , V_99 ,
( L_65 , F_71 ( V_8 ) ) ) ;
if ( V_173 == F_47 ( V_2 ) ) {
V_126 = - 1 ;
goto exit;
}
if ( ! V_2 -> V_318 ) {
V_126 = - 1 ;
goto exit;
}
if ( V_4 -> V_348 . V_49 > V_347 ) {
V_126 = - V_370 ;
goto exit;
}
if ( F_21 ( V_8 , V_247 ) ) {
V_126 = - 1 ;
goto exit;
}
V_317 = V_2 -> V_129 . V_132 ;
F_25 ( L_66 , V_327 ) ;
if ( V_4 -> V_348 . V_48 && V_4 -> V_348 . V_49 ) {
V_345 = F_9 ( T_5 , V_4 -> V_348 . V_49 , V_347 ) ;
if ( V_4 -> V_348 . V_49 != 33 )
F_25 ( L_67 , V_225 , V_4 -> V_348 . V_49 ) ;
memset ( & V_371 , 0 , sizeof( struct V_332 ) ) ;
V_371 . V_51 = V_345 ;
memcpy ( V_371 . V_50 , V_225 , V_345 ) ;
V_373 = V_371 . V_50 ;
F_19 ( V_162 , V_99 , ( L_68 , V_373 ) ) ;
F_55 ( & V_314 -> V_319 ) ;
V_310 = F_56 ( V_314 ) ;
V_8 -> V_320 = V_310 -> V_321 ;
while ( V_310 != V_8 -> V_320 ) {
V_23 = F_57 ( V_8 -> V_320 , struct V_22 , V_322 ) ;
V_8 -> V_320 = V_8 -> V_320 -> V_321 ;
V_372 = V_23 -> V_15 . V_50 . V_50 ;
F_19 ( V_162 , V_99 ,
( L_69 ,
V_23 -> V_15 . V_50 . V_50 ) ) ;
if ( ( ! memcmp ( V_372 , V_373 , V_371 . V_51 ) ) &&
( V_23 -> V_15 . V_50 . V_51 == V_371 . V_51 ) ) {
F_19 ( V_162 , V_99 ,
( L_70 ) ) ;
if ( F_21 ( V_8 , V_246 ) == true ) {
if ( V_23 -> V_15 . V_323 != V_8 -> V_14 . V_15 . V_323 )
continue;
}
if ( ! F_48 ( V_2 , V_23 -> V_15 . V_323 ) ) {
V_126 = - 1 ;
F_58 ( & V_314 -> V_319 ) ;
goto exit;
}
break;
}
}
F_58 ( & V_314 -> V_319 ) ;
F_19 ( V_162 , V_99 ,
( L_71 , V_317 ) ) ;
F_59 ( V_2 , V_317 ) ;
if ( F_72 ( V_2 , & V_371 ) == false ) {
V_126 = - 1 ;
goto exit;
}
}
exit:
F_25 ( L_72 , V_327 , V_126 ) ;
return V_126 ;
}
static int F_73 ( struct V_124 * V_125 ,
struct V_20 * V_233 ,
union V_3 * V_4 , char * V_225 )
{
T_3 V_345 , V_126 = 0 ;
struct V_1 * V_2 = (struct V_1 * ) F_24 ( V_125 ) ;
struct V_7 * V_8 = & ( V_2 -> V_9 ) ;
struct V_226 * V_227 = & V_8 -> V_14 . V_15 ;
F_19 ( V_98 , V_99 , ( L_73 ) ) ;
if ( ( F_21 ( V_8 , V_114 ) ) ||
( F_21 ( V_8 , V_229 ) ) ) {
V_345 = V_227 -> V_50 . V_51 ;
V_4 -> V_348 . V_49 = V_345 ;
memcpy ( V_225 , V_227 -> V_50 . V_50 , V_345 ) ;
V_4 -> V_348 . V_48 = 1 ;
} else {
V_126 = - 1 ;
goto exit;
}
exit:
return V_126 ;
}
static int F_74 ( struct V_124 * V_125 ,
struct V_20 * V_233 ,
union V_3 * V_4 , char * V_225 )
{
int V_37 ;
T_4 V_374 [ V_375 ] ;
T_3 V_376 = V_4 -> V_87 . V_90 ;
T_3 V_88 = V_4 -> V_87 . V_88 ;
T_3 V_377 = 0 ;
T_4 V_378 [ V_375 ] = { 11 , 10 , 9 , 8 , 7 , 6 , 5 , 4 , 3 , 2 , 1 , 0 , 0xff } ;
F_19 ( V_98 , V_99 , ( L_74 ) ) ;
F_19 ( V_162 , V_99 , ( L_75 , V_376 , V_88 ) ) ;
if ( V_376 == - 1 ) {
V_377 = 11 ;
goto V_379;
}
V_376 = V_376 / 100000 ;
switch ( V_376 ) {
case 10 :
V_377 = 0 ;
break;
case 20 :
V_377 = 1 ;
break;
case 55 :
V_377 = 2 ;
break;
case 60 :
V_377 = 3 ;
break;
case 90 :
V_377 = 4 ;
break;
case 110 :
V_377 = 5 ;
break;
case 120 :
V_377 = 6 ;
break;
case 180 :
V_377 = 7 ;
break;
case 240 :
V_377 = 8 ;
break;
case 360 :
V_377 = 9 ;
break;
case 480 :
V_377 = 10 ;
break;
case 540 :
V_377 = 11 ;
break;
default:
V_377 = 11 ;
break;
}
V_379:
for ( V_37 = 0 ; V_37 < V_375 ; V_37 ++ ) {
if ( V_377 == V_378 [ V_37 ] ) {
V_374 [ V_37 ] = V_378 [ V_37 ] ;
if ( V_88 == 0 )
break;
} else {
V_374 [ V_37 ] = 0xff ;
}
F_19 ( V_162 , V_99 , ( L_76 , V_374 [ V_37 ] ) ) ;
}
return 0 ;
}
static int F_75 ( struct V_124 * V_125 ,
struct V_20 * V_21 ,
union V_3 * V_4 , char * V_225 )
{
T_1 V_34 = 0 ;
V_34 = F_76 ( (struct V_1 * ) F_24 ( V_125 ) ) ;
if ( V_34 == 0 )
return - V_237 ;
V_4 -> V_87 . V_88 = 0 ;
V_4 -> V_87 . V_90 = V_34 * 100000 ;
return 0 ;
}
static int F_77 ( struct V_124 * V_125 ,
struct V_20 * V_21 ,
union V_3 * V_4 , char * V_225 )
{
struct V_1 * V_2 = (struct V_1 * ) F_24 ( V_125 ) ;
if ( V_4 -> V_380 . V_89 ) {
V_2 -> V_335 . V_381 = 2347 ;
} else {
if ( V_4 -> V_380 . V_90 < 0 ||
V_4 -> V_380 . V_90 > 2347 )
return - V_142 ;
V_2 -> V_335 . V_381 = V_4 -> V_380 . V_90 ;
}
F_25 ( L_77 , V_327 , V_2 -> V_335 . V_381 ) ;
return 0 ;
}
static int F_78 ( struct V_124 * V_125 ,
struct V_20 * V_21 ,
union V_3 * V_4 , char * V_225 )
{
struct V_1 * V_2 = (struct V_1 * ) F_24 ( V_125 ) ;
F_25 ( L_77 , V_327 , V_2 -> V_335 . V_381 ) ;
V_4 -> V_380 . V_90 = V_2 -> V_335 . V_381 ;
V_4 -> V_380 . V_88 = 0 ;
return 0 ;
}
static int F_79 ( struct V_124 * V_125 ,
struct V_20 * V_21 ,
union V_3 * V_4 , char * V_225 )
{
struct V_1 * V_2 = (struct V_1 * ) F_24 ( V_125 ) ;
if ( V_4 -> V_382 . V_89 ) {
V_2 -> V_383 . V_384 = V_283 ;
} else {
if ( V_4 -> V_382 . V_90 < V_281 ||
V_4 -> V_382 . V_90 > V_283 )
return - V_142 ;
V_2 -> V_383 . V_384 = V_4 -> V_382 . V_90 & ~ 0x1 ;
}
F_25 ( L_78 , V_327 , V_2 -> V_383 . V_384 ) ;
return 0 ;
}
static int F_80 ( struct V_124 * V_125 ,
struct V_20 * V_21 ,
union V_3 * V_4 , char * V_225 )
{
struct V_1 * V_2 = (struct V_1 * ) F_24 ( V_125 ) ;
F_25 ( L_78 , V_327 , V_2 -> V_383 . V_384 ) ;
V_4 -> V_382 . V_90 = V_2 -> V_383 . V_384 ;
V_4 -> V_382 . V_88 = 0 ;
return 0 ;
}
static int F_81 ( struct V_124 * V_125 ,
struct V_20 * V_21 ,
union V_3 * V_4 , char * V_225 )
{
V_4 -> V_385 . V_90 = 7 ;
V_4 -> V_385 . V_88 = 0 ;
V_4 -> V_385 . V_89 = 1 ;
return 0 ;
}
static int F_82 ( struct V_124 * V_125 ,
struct V_20 * V_21 ,
union V_3 * V_4 , char * V_386 )
{
T_3 V_157 , V_126 = 0 ;
T_3 V_387 ;
struct V_149 V_388 ;
enum V_316 V_317 ;
struct V_389 * V_390 = & ( V_4 -> V_391 ) ;
struct V_1 * V_2 = (struct V_1 * ) F_24 ( V_125 ) ;
struct V_392 * V_393 = & V_2 -> V_367 ;
F_25 ( L_79 , V_390 -> V_48 ) ;
memset ( & V_388 , 0 , sizeof( struct V_149 ) ) ;
V_157 = V_390 -> V_48 & V_394 ;
if ( V_390 -> V_48 & V_85 ) {
F_25 ( L_80 ) ;
V_2 -> V_129 . V_130 = V_213 ;
V_2 -> V_129 . V_164 = V_212 ;
V_2 -> V_129 . V_166 = V_212 ;
V_2 -> V_129 . V_134 = V_140 ;
V_317 = V_139 ;
V_2 -> V_129 . V_132 = V_317 ;
goto exit;
}
if ( V_157 ) {
if ( V_157 > V_161 )
return - V_142 ;
V_157 -- ;
V_387 = 1 ;
} else {
V_387 = 0 ;
V_157 = V_2 -> V_129 . V_395 ;
F_25 ( L_81 , V_157 ) ;
}
if ( V_390 -> V_48 & V_396 ) {
F_25 ( L_82 ) ;
V_2 -> V_129 . V_130 = V_131 ;
V_2 -> V_129 . V_134 = V_140 ;
V_2 -> V_129 . V_164 = V_212 ;
V_2 -> V_129 . V_166 = V_212 ;
V_317 = V_139 ;
V_2 -> V_129 . V_132 = V_317 ;
} else if ( V_390 -> V_48 & V_397 ) {
F_25 ( L_83 ) ;
V_2 -> V_129 . V_130 = V_131 ;
V_2 -> V_129 . V_134 = V_137 ;
V_2 -> V_129 . V_164 = V_165 ;
V_2 -> V_129 . V_166 = V_165 ;
V_317 = V_136 ;
V_2 -> V_129 . V_132 = V_317 ;
} else {
F_25 ( L_84 , V_390 -> V_48 ) ;
V_2 -> V_129 . V_130 = V_131 ;
V_2 -> V_129 . V_134 = V_140 ;
V_2 -> V_129 . V_164 = V_212 ;
V_2 -> V_129 . V_166 = V_212 ;
V_317 = V_139 ;
V_2 -> V_129 . V_132 = V_317 ;
}
V_388 . V_171 = V_157 ;
if ( V_390 -> V_49 > 0 ) {
V_388 . V_168 = V_390 -> V_49 <= 5 ? 5 : 13 ;
V_388 . V_169 = V_388 . V_168 + F_27 ( struct V_149 , V_167 ) ;
} else {
V_388 . V_168 = 0 ;
if ( V_387 == 1 ) {
V_2 -> V_129 . V_395 = V_157 ;
F_25 ( L_85 , V_157 , V_2 -> V_129 . V_177 [ V_157 ] ) ;
switch ( V_2 -> V_129 . V_177 [ V_157 ] ) {
case 5 :
V_2 -> V_129 . V_164 = V_165 ;
break;
case 13 :
V_2 -> V_129 . V_164 = V_170 ;
break;
default:
V_2 -> V_129 . V_164 = V_212 ;
break;
}
goto exit;
}
}
V_388 . V_171 |= 0x80000000 ;
memcpy ( V_388 . V_167 , V_386 , V_388 . V_168 ) ;
if ( F_29 ( V_2 , & V_388 ) == false ) {
if ( V_398 == V_393 -> V_399 )
V_126 = - V_174 ;
goto exit;
}
exit:
return V_126 ;
}
static int F_83 ( struct V_124 * V_125 ,
struct V_20 * V_21 ,
union V_3 * V_4 , char * V_386 )
{
T_5 V_157 , V_126 = 0 ;
struct V_1 * V_2 = (struct V_1 * ) F_24 ( V_125 ) ;
struct V_389 * V_390 = & ( V_4 -> V_391 ) ;
struct V_7 * V_8 = & ( V_2 -> V_9 ) ;
if ( F_21 ( V_8 , V_114 ) != true ) {
if ( ! F_21 ( V_8 , V_229 ) ) {
V_390 -> V_49 = 0 ;
V_390 -> V_48 |= V_85 ;
return 0 ;
}
}
V_157 = V_390 -> V_48 & V_394 ;
if ( V_157 ) {
if ( V_157 > V_161 )
return - V_142 ;
V_157 -- ;
} else {
V_157 = V_2 -> V_129 . V_395 ;
}
V_390 -> V_48 = V_157 + 1 ;
switch ( V_2 -> V_129 . V_130 ) {
case V_400 :
case V_213 :
V_390 -> V_49 = 0 ;
V_390 -> V_48 |= V_85 ;
break;
case V_131 :
V_390 -> V_49 = V_2 -> V_129 . V_177 [ V_157 ] ;
if ( V_390 -> V_49 ) {
memcpy ( V_386 , V_2 -> V_129 . V_175 [ V_157 ] . V_176 , V_2 -> V_129 . V_177 [ V_157 ] ) ;
V_390 -> V_48 |= V_83 ;
if ( V_2 -> V_129 . V_132 == V_139 )
V_390 -> V_48 |= V_396 ;
else if ( V_2 -> V_129 . V_132 == V_136 )
V_390 -> V_48 |= V_397 ;
} else {
V_390 -> V_49 = 0 ;
V_390 -> V_48 |= V_85 ;
}
break;
case V_188 :
case V_189 :
V_390 -> V_49 = 16 ;
V_390 -> V_48 |= ( V_83 | V_396 | V_84 ) ;
break;
default:
V_390 -> V_49 = 0 ;
V_390 -> V_48 |= V_85 ;
break;
}
return V_126 ;
}
static int F_84 ( struct V_124 * V_125 ,
struct V_20 * V_21 ,
union V_3 * V_4 , char * V_225 )
{
V_4 -> V_401 . V_90 = 0 ;
V_4 -> V_401 . V_88 = 0 ;
V_4 -> V_401 . V_89 = 1 ;
return 0 ;
}
static int F_85 ( struct V_124 * V_125 ,
struct V_20 * V_21 ,
union V_3 * V_4 , char * V_225 )
{
struct V_1 * V_2 = (struct V_1 * ) F_24 ( V_125 ) ;
return F_36 ( V_2 , V_225 , V_4 -> V_47 . V_49 ) ;
}
static int F_86 ( struct V_124 * V_125 ,
struct V_20 * V_21 ,
union V_3 * V_4 , char * V_225 )
{
struct V_1 * V_2 = (struct V_1 * ) F_24 ( V_125 ) ;
struct V_402 * V_144 = (struct V_402 * ) & ( V_4 -> V_144 ) ;
int V_126 = 0 ;
switch ( V_144 -> V_48 & V_403 ) {
case V_404 :
break;
case V_405 :
break;
case V_406 :
break;
case V_407 :
break;
case V_408 :
if ( V_144 -> V_90 ) {
V_2 -> V_129 . V_409 = true ;
} else {
V_2 -> V_129 . V_409 = false ;
}
break;
case V_410 :
if ( V_2 -> V_129 . V_130 == V_131 )
break;
if ( V_144 -> V_90 ) {
V_2 -> V_129 . V_130 = V_213 ;
V_2 -> V_129 . V_164 = V_212 ;
V_2 -> V_129 . V_166 = V_212 ;
V_2 -> V_129 . V_134 = V_140 ;
V_2 -> V_129 . V_132 = V_139 ;
}
break;
case V_411 :
if ( F_21 ( & V_2 -> V_9 , V_114 ) ) {
F_87 ( V_2 ) ;
F_88 ( V_2 , 500 , false ) ;
F_25 ( L_86 , V_327 ) ;
F_89 ( V_2 ) ;
F_90 ( V_2 ) ;
}
V_126 = F_23 ( V_125 , ( T_3 ) V_144 -> V_90 ) ;
break;
case V_412 :
break;
case V_413 :
break;
case V_414 :
break;
default:
return - V_174 ;
}
return V_126 ;
}
static int F_91 ( struct V_124 * V_125 ,
struct V_20 * V_21 ,
union V_3 * V_4 , char * V_225 )
{
char * V_415 ;
T_3 V_145 ;
struct V_143 * V_144 = NULL ;
struct V_389 * V_416 = & V_4 -> V_391 ;
struct V_417 * V_418 = (struct V_417 * ) V_225 ;
int V_126 = 0 ;
V_145 = sizeof( struct V_143 ) + V_418 -> V_158 ;
V_144 = (struct V_143 * ) F_28 ( V_145 ) ;
if ( ! V_144 )
return - 1 ;
memset ( V_144 , 0 , V_145 ) ;
V_144 -> V_43 = V_419 ;
F_92 ( V_144 -> V_159 ) ;
switch ( V_418 -> V_155 ) {
case V_420 :
V_415 = L_32 ;
break;
case V_421 :
V_415 = L_25 ;
break;
case V_422 :
V_415 = L_33 ;
break;
case V_423 :
V_415 = L_87 ;
break;
default:
V_126 = - 1 ;
goto exit;
}
strncpy ( ( char * ) V_144 -> V_44 . V_153 . V_155 , V_415 , V_156 ) ;
if ( V_418 -> V_424 & V_425 )
V_144 -> V_44 . V_153 . V_172 = 1 ;
if ( ( V_418 -> V_155 != V_421 ) &&
( V_418 -> V_424 & V_426 ) )
V_144 -> V_44 . V_153 . V_172 = 0 ;
V_144 -> V_44 . V_153 . V_160 = ( V_416 -> V_48 & 0x00FF ) - 1 ;
if ( V_418 -> V_424 & V_427 )
memcpy ( V_144 -> V_44 . V_153 . V_428 , V_418 -> V_429 , 8 ) ;
if ( V_418 -> V_158 ) {
V_144 -> V_44 . V_153 . V_158 = V_418 -> V_158 ;
memcpy ( V_144 -> V_44 . V_153 . V_157 , V_418 + 1 , V_418 -> V_158 ) ;
}
V_126 = F_26 ( V_125 , V_144 , V_145 ) ;
exit:
F_35 ( V_144 ) ;
return V_126 ;
}
static int F_93 ( struct V_124 * V_125 ,
struct V_20 * V_21 ,
union V_3 * V_4 , char * V_225 )
{
if ( V_225 ) {
V_4 -> V_47 . V_49 = 14 ;
V_4 -> V_47 . V_48 = 1 ;
memcpy ( V_225 , L_88 , 14 ) ;
}
return 0 ;
}
static int F_94 ( struct V_124 * V_125 , struct V_20 * V_233 ,
union V_3 * V_4 , char * V_234 )
{
return - 1 ;
}
static int F_95 ( struct V_124 * V_125 , T_4 V_65 , T_3 V_90 )
{
T_5 V_126 = 0 ;
struct V_1 * V_2 = (struct V_1 * ) F_24 ( V_125 ) ;
switch ( V_65 ) {
case V_430 :
V_2 -> V_129 . V_134 = V_178 ;
switch ( ( V_90 ) & 0xff ) {
case 1 :
V_2 -> V_129 . V_132 = V_138 ;
V_2 -> V_129 . V_130 = V_188 ;
break;
case 2 :
V_2 -> V_129 . V_132 = V_210 ;
V_2 -> V_129 . V_130 = V_189 ;
break;
}
F_19 ( V_162 , V_99 ,
( L_89 , V_2 -> V_129 . V_132 ) ) ;
break;
case V_431 :
break;
case V_432 : {
break;
}
case V_433 :
break;
case V_434 :
V_126 = F_23 ( V_125 , V_90 ) ;
break;
case V_435 :
break;
case V_436 :
break;
default:
V_126 = - V_174 ;
break;
}
return V_126 ;
}
static int F_96 ( struct V_124 * V_125 , T_3 V_437 , T_3 V_324 )
{
int V_126 = 0 ;
struct V_1 * V_2 = (struct V_1 * ) F_24 ( V_125 ) ;
switch ( V_437 ) {
case V_438 :
if ( ! F_63 ( V_2 ) )
V_126 = - 1 ;
break;
case V_439 :
if ( ! F_63 ( V_2 ) )
V_126 = - 1 ;
break;
default:
V_126 = - V_174 ;
break;
}
return V_126 ;
}
static int F_97 ( struct V_124 * V_125 , struct V_389 * V_33 )
{
struct V_143 * V_144 ;
T_5 V_126 = 0 ;
if ( V_33 -> V_49 < sizeof( struct V_143 ) || ! V_33 -> V_440 ) {
V_126 = - V_142 ;
goto V_441;
}
V_144 = (struct V_143 * ) F_28 ( V_33 -> V_49 ) ;
if ( ! V_144 ) {
V_126 = - V_206 ;
goto V_441;
}
if ( F_98 ( V_144 , V_33 -> V_440 , V_33 -> V_49 ) ) {
F_35 ( V_144 ) ;
V_126 = - V_442 ;
goto V_441;
}
switch ( V_144 -> V_43 ) {
case V_443 :
V_126 = F_95 ( V_125 , V_144 -> V_44 . V_444 . V_65 , V_144 -> V_44 . V_444 . V_90 ) ;
break;
case V_445 :
V_126 = F_36 ( (struct V_1 * ) F_24 ( V_125 ) ,
( char * ) V_144 -> V_44 . V_94 . V_47 , ( T_1 ) V_144 -> V_44 . V_94 . V_345 ) ;
break;
case V_419 :
V_126 = F_26 ( V_125 , V_144 , V_33 -> V_49 ) ;
break;
case V_446 :
V_126 = F_96 ( V_125 , V_144 -> V_44 . V_326 . V_437 , V_144 -> V_44 . V_326 . V_328 ) ;
break;
default:
F_25 ( L_90 , V_144 -> V_43 ) ;
V_126 = - V_174 ;
break;
}
if ( V_126 == 0 && F_99 ( V_33 -> V_440 , V_144 , V_33 -> V_49 ) )
V_126 = - V_442 ;
F_35 ( V_144 ) ;
V_441:
return V_126 ;
}
static T_4 F_100 ( struct V_1 * V_2 , struct V_179 * V_180 )
{
struct V_447 * V_448 ;
struct V_449 * V_450 ;
struct V_451 * V_452 = & V_2 -> V_453 ;
T_4 V_454 = V_208 ;
V_448 = F_101 ( sizeof( struct V_447 ) , V_205 ) ;
if ( ! V_448 ) {
V_454 = V_173 ;
goto exit;
}
V_450 = F_101 ( sizeof( struct V_449 ) , V_205 ) ;
if ( ! V_450 ) {
F_35 ( V_448 ) ;
V_454 = V_173 ;
goto exit;
}
F_102 ( V_448 , V_450 , V_455 ) ;
V_450 -> V_456 = ( T_4 ) V_180 -> V_190 ;
memcpy ( V_450 -> V_457 , V_180 -> V_458 , V_17 ) ;
memcpy ( V_450 -> V_157 , & V_180 -> V_191 , 16 ) ;
V_454 = F_103 ( V_452 , V_448 ) ;
exit:
return V_454 ;
}
static int F_104 ( struct V_1 * V_2 , T_4 * V_157 , T_4 V_155 , int V_459 )
{
T_4 V_460 ;
struct V_447 * V_461 ;
struct V_462 * V_463 ;
struct V_451 * V_452 = & ( V_2 -> V_453 ) ;
int V_454 = V_208 ;
F_25 ( L_57 , V_327 ) ;
V_461 = F_101 ( sizeof( struct V_447 ) , V_205 ) ;
if ( ! V_461 ) {
V_454 = V_173 ;
goto exit;
}
V_463 = F_101 ( sizeof( struct V_462 ) , V_205 ) ;
if ( ! V_463 ) {
F_35 ( V_461 ) ;
V_454 = V_173 ;
goto exit;
}
memset ( V_463 , 0 , sizeof( struct V_462 ) ) ;
V_463 -> V_459 = ( T_4 ) V_459 ;
V_463 -> V_456 = V_155 ;
V_463 -> V_172 = 1 ;
switch ( V_155 ) {
case V_165 :
V_460 = 5 ;
break;
case V_170 :
V_460 = 13 ;
break;
case V_216 :
case V_464 :
case V_218 :
default:
V_460 = 16 ;
}
memcpy ( & ( V_463 -> V_157 [ 0 ] ) , V_157 , V_460 ) ;
V_461 -> V_465 = V_466 ;
V_461 -> V_467 = ( T_4 * ) V_463 ;
V_461 -> V_468 = ( sizeof( struct V_462 ) ) ;
V_461 -> V_469 = NULL ;
V_461 -> V_470 = 0 ;
F_105 ( & V_461 -> V_322 ) ;
V_454 = F_103 ( V_452 , V_461 ) ;
exit:
return V_454 ;
}
static int F_106 ( struct V_1 * V_2 , T_4 * V_157 , T_4 V_460 , int V_459 )
{
T_4 V_155 ;
switch ( V_460 ) {
case 5 :
V_155 = V_165 ;
break;
case 13 :
V_155 = V_170 ;
break;
default:
V_155 = V_212 ;
}
return F_104 ( V_2 , V_157 , V_155 , V_459 ) ;
}
static int F_107 ( struct V_124 * V_125 , struct V_143 * V_144 , T_3 V_145 )
{
int V_126 = 0 ;
T_3 V_146 , V_147 , V_148 ;
struct V_149 * V_150 = NULL ;
struct V_179 * V_180 = NULL , * V_181 = NULL ;
struct V_1 * V_2 = (struct V_1 * ) F_24 ( V_125 ) ;
struct V_7 * V_8 = & V_2 -> V_9 ;
struct V_151 * V_152 = & ( V_2 -> V_129 ) ;
struct V_182 * V_183 = & V_2 -> V_184 ;
F_25 ( L_57 , V_327 ) ;
V_144 -> V_44 . V_153 . V_154 = 0 ;
V_144 -> V_44 . V_153 . V_155 [ V_156 - 1 ] = '\0' ;
if ( V_145 != sizeof( struct V_143 ) + V_144 -> V_44 . V_153 . V_158 ) {
V_126 = - V_142 ;
goto exit;
}
if ( V_144 -> V_159 [ 0 ] == 0xff && V_144 -> V_159 [ 1 ] == 0xff &&
V_144 -> V_159 [ 2 ] == 0xff && V_144 -> V_159 [ 3 ] == 0xff &&
V_144 -> V_159 [ 4 ] == 0xff && V_144 -> V_159 [ 5 ] == 0xff ) {
if ( V_144 -> V_44 . V_153 . V_160 >= V_161 ) {
V_126 = - V_142 ;
goto exit;
}
} else {
V_180 = F_31 ( V_183 , V_144 -> V_159 ) ;
if ( ! V_180 ) {
F_25 ( L_91 ) ;
goto exit;
}
}
if ( strcmp ( V_144 -> V_44 . V_153 . V_155 , L_32 ) == 0 && ( ! V_180 ) ) {
F_25 ( L_92 , V_144 -> V_44 . V_153 . V_160 ) ;
goto exit;
}
if ( strcmp ( V_144 -> V_44 . V_153 . V_155 , L_25 ) == 0 && ( ! V_180 ) ) {
F_25 ( L_93 ) ;
V_146 = V_144 -> V_44 . V_153 . V_160 ;
V_147 = V_144 -> V_44 . V_153 . V_158 ;
F_25 ( L_94 , V_146 , V_147 ) ;
if ( ( V_146 >= V_161 ) || ( V_147 <= 0 ) ) {
V_126 = - V_142 ;
goto exit;
}
if ( V_147 > 0 ) {
V_147 = V_147 <= 5 ? 5 : 13 ;
V_148 = V_147 + F_27 ( struct V_149 , V_167 ) ;
V_150 = (struct V_149 * ) F_28 ( V_148 ) ;
if ( ! V_150 ) {
F_25 ( L_95 ) ;
goto exit;
}
memset ( V_150 , 0 , V_148 ) ;
V_150 -> V_168 = V_147 ;
V_150 -> V_169 = V_148 ;
}
V_150 -> V_171 = V_146 ;
memcpy ( V_150 -> V_167 , V_144 -> V_44 . V_153 . V_157 , V_150 -> V_168 ) ;
if ( V_144 -> V_44 . V_153 . V_172 ) {
F_25 ( L_30 ) ;
V_152 -> V_130 = V_131 ;
V_152 -> V_164 = V_165 ;
V_152 -> V_166 = V_165 ;
if ( V_150 -> V_168 == 13 ) {
V_152 -> V_164 = V_170 ;
V_152 -> V_166 = V_170 ;
}
V_152 -> V_395 = V_146 ;
memcpy ( & ( V_152 -> V_175 [ V_146 ] . V_176 [ 0 ] ) , V_150 -> V_167 , V_150 -> V_168 ) ;
V_152 -> V_177 [ V_146 ] = V_150 -> V_168 ;
F_106 ( V_2 , V_150 -> V_167 , V_150 -> V_168 , V_146 ) ;
} else {
F_25 ( L_31 ) ;
memcpy ( & ( V_152 -> V_175 [ V_146 ] . V_176 [ 0 ] ) , V_150 -> V_167 , V_150 -> V_168 ) ;
V_152 -> V_177 [ V_146 ] = V_150 -> V_168 ;
F_106 ( V_2 , V_150 -> V_167 , V_150 -> V_168 , V_146 ) ;
}
goto exit;
}
if ( ! V_180 && F_21 ( V_8 , V_247 ) ) {
if ( V_144 -> V_44 . V_153 . V_172 == 1 ) {
if ( strcmp ( V_144 -> V_44 . V_153 . V_155 , L_25 ) == 0 ) {
F_25 ( L_96 , V_327 ) ;
memcpy ( V_152 -> V_195 [ V_144 -> V_44 . V_153 . V_160 ] . V_176 ,
V_144 -> V_44 . V_153 . V_157 , F_9 ( T_1 , V_144 -> V_44 . V_153 . V_158 , 16 ) ) ;
V_152 -> V_166 = V_165 ;
if ( V_144 -> V_44 . V_153 . V_158 == 13 )
V_152 -> V_166 = V_170 ;
} else if ( strcmp ( V_144 -> V_44 . V_153 . V_155 , L_33 ) == 0 ) {
F_25 ( L_97 , V_327 ) ;
V_152 -> V_166 = V_216 ;
memcpy ( V_152 -> V_195 [ V_144 -> V_44 . V_153 . V_160 ] . V_176 ,
V_144 -> V_44 . V_153 . V_157 , F_9 ( T_1 , V_144 -> V_44 . V_153 . V_158 , 16 ) ) ;
memcpy ( V_152 -> V_196 [ V_144 -> V_44 . V_153 . V_160 ] . V_176 , & ( V_144 -> V_44 . V_153 . V_157 [ 16 ] ) , 8 ) ;
memcpy ( V_152 -> V_197 [ V_144 -> V_44 . V_153 . V_160 ] . V_176 , & ( V_144 -> V_44 . V_153 . V_157 [ 24 ] ) , 8 ) ;
V_152 -> V_194 = true ;
} else if ( strcmp ( V_144 -> V_44 . V_153 . V_155 , L_87 ) == 0 ) {
F_25 ( L_98 , V_327 ) ;
V_152 -> V_166 = V_218 ;
memcpy ( V_152 -> V_195 [ V_144 -> V_44 . V_153 . V_160 ] . V_176 ,
V_144 -> V_44 . V_153 . V_157 , F_9 ( T_1 , V_144 -> V_44 . V_153 . V_158 , 16 ) ) ;
} else {
F_25 ( L_99 , V_327 ) ;
V_152 -> V_166 = V_212 ;
}
V_152 -> V_199 = V_144 -> V_44 . V_153 . V_160 ;
V_152 -> V_198 = true ;
V_152 -> V_164 = V_152 -> V_166 ;
F_104 ( V_2 , V_144 -> V_44 . V_153 . V_157 , V_152 -> V_166 , V_144 -> V_44 . V_153 . V_160 ) ;
V_181 = F_34 ( V_2 ) ;
if ( V_181 ) {
V_181 -> V_187 = false ;
V_181 -> V_190 = V_152 -> V_166 ;
}
}
goto exit;
}
if ( V_152 -> V_134 == V_178 && V_180 ) {
if ( F_21 ( V_8 , V_247 ) ) {
if ( V_144 -> V_44 . V_153 . V_172 == 1 ) {
memcpy ( V_180 -> V_191 . V_176 , V_144 -> V_44 . V_153 . V_157 , F_9 ( T_1 , V_144 -> V_44 . V_153 . V_158 , 16 ) ) ;
if ( strcmp ( V_144 -> V_44 . V_153 . V_155 , L_25 ) == 0 ) {
F_25 ( L_100 , V_327 ) ;
V_180 -> V_190 = V_165 ;
if ( V_144 -> V_44 . V_153 . V_158 == 13 )
V_180 -> V_190 = V_170 ;
} else if ( strcmp ( V_144 -> V_44 . V_153 . V_155 , L_33 ) == 0 ) {
F_25 ( L_101 , V_327 ) ;
V_180 -> V_190 = V_216 ;
memcpy ( V_180 -> V_192 . V_176 , & ( V_144 -> V_44 . V_153 . V_157 [ 16 ] ) , 8 ) ;
memcpy ( V_180 -> V_193 . V_176 , & ( V_144 -> V_44 . V_153 . V_157 [ 24 ] ) , 8 ) ;
V_152 -> V_194 = true ;
} else if ( strcmp ( V_144 -> V_44 . V_153 . V_155 , L_87 ) == 0 ) {
F_25 ( L_102 , V_327 ) ;
V_180 -> V_190 = V_218 ;
} else {
F_25 ( L_103 , V_327 ) ;
V_180 -> V_190 = V_212 ;
}
F_100 ( V_2 , V_180 ) ;
V_180 -> V_187 = false ;
} else {
if ( strcmp ( V_144 -> V_44 . V_153 . V_155 , L_25 ) == 0 ) {
memcpy ( V_152 -> V_195 [ V_144 -> V_44 . V_153 . V_160 ] . V_176 ,
V_144 -> V_44 . V_153 . V_157 , F_9 ( T_1 , V_144 -> V_44 . V_153 . V_158 , 16 ) ) ;
V_152 -> V_166 = V_165 ;
if ( V_144 -> V_44 . V_153 . V_158 == 13 )
V_152 -> V_166 = V_170 ;
} else if ( strcmp ( V_144 -> V_44 . V_153 . V_155 , L_33 ) == 0 ) {
V_152 -> V_166 = V_216 ;
memcpy ( V_152 -> V_195 [ V_144 -> V_44 . V_153 . V_160 ] . V_176 ,
V_144 -> V_44 . V_153 . V_157 , F_9 ( T_1 , V_144 -> V_44 . V_153 . V_158 , 16 ) ) ;
memcpy ( V_152 -> V_196 [ V_144 -> V_44 . V_153 . V_160 ] . V_176 , & ( V_144 -> V_44 . V_153 . V_157 [ 16 ] ) , 8 ) ;
memcpy ( V_152 -> V_197 [ V_144 -> V_44 . V_153 . V_160 ] . V_176 , & ( V_144 -> V_44 . V_153 . V_157 [ 24 ] ) , 8 ) ;
V_152 -> V_194 = true ;
} else if ( strcmp ( V_144 -> V_44 . V_153 . V_155 , L_87 ) == 0 ) {
V_152 -> V_166 = V_218 ;
memcpy ( V_152 -> V_195 [ V_144 -> V_44 . V_153 . V_160 ] . V_176 ,
V_144 -> V_44 . V_153 . V_157 , F_9 ( T_1 , V_144 -> V_44 . V_153 . V_158 , 16 ) ) ;
} else {
V_152 -> V_166 = V_212 ;
}
V_152 -> V_199 = V_144 -> V_44 . V_153 . V_160 ;
V_152 -> V_198 = true ;
V_152 -> V_164 = V_152 -> V_166 ;
F_104 ( V_2 , V_144 -> V_44 . V_153 . V_157 , V_152 -> V_166 , V_144 -> V_44 . V_153 . V_160 ) ;
V_181 = F_34 ( V_2 ) ;
if ( V_181 ) {
V_181 -> V_187 = false ;
V_181 -> V_190 = V_152 -> V_166 ;
}
}
}
}
exit:
F_35 ( V_150 ) ;
return V_126 ;
}
static int F_108 ( struct V_124 * V_125 , struct V_143 * V_144 , int V_345 )
{
int V_126 = 0 ;
struct V_1 * V_2 = (struct V_1 * ) F_24 ( V_125 ) ;
struct V_7 * V_8 = & ( V_2 -> V_9 ) ;
struct V_182 * V_183 = & V_2 -> V_184 ;
unsigned char * V_471 = V_144 -> V_44 . V_472 . V_92 ;
F_25 ( L_104 , V_327 , V_345 ) ;
if ( F_21 ( V_8 , V_247 ) != true )
return - V_142 ;
memcpy ( & V_183 -> V_473 , V_144 -> V_44 . V_472 . V_474 , 2 ) ;
if ( ( V_183 -> V_473 > V_475 ) || ( V_183 -> V_473 <= 0 ) )
V_183 -> V_473 = V_475 ;
if ( F_109 ( V_2 , V_471 , ( V_345 - 12 - 2 ) ) == V_208 )
V_126 = 0 ;
else
V_126 = - V_142 ;
return V_126 ;
}
static int F_110 ( struct V_124 * V_125 )
{
struct V_1 * V_2 = (struct V_1 * ) F_24 ( V_125 ) ;
F_25 ( L_57 , V_327 ) ;
F_111 ( V_2 ) ;
return F_112 ( V_2 ) ;
}
static int F_113 ( struct V_124 * V_125 , struct V_143 * V_144 )
{
int V_126 = 0 ;
struct V_179 * V_180 = NULL ;
struct V_1 * V_2 = (struct V_1 * ) F_24 ( V_125 ) ;
struct V_7 * V_8 = & ( V_2 -> V_9 ) ;
struct V_182 * V_183 = & V_2 -> V_184 ;
F_25 ( L_105 , V_144 -> V_44 . V_476 . V_477 , ( V_144 -> V_159 ) ) ;
if ( ! F_21 ( V_8 , ( V_114 | V_247 ) ) )
return - V_142 ;
if ( V_144 -> V_159 [ 0 ] == 0xff && V_144 -> V_159 [ 1 ] == 0xff &&
V_144 -> V_159 [ 2 ] == 0xff && V_144 -> V_159 [ 3 ] == 0xff &&
V_144 -> V_159 [ 4 ] == 0xff && V_144 -> V_159 [ 5 ] == 0xff )
return - V_142 ;
V_180 = F_31 ( V_183 , V_144 -> V_159 ) ;
if ( V_180 ) {
int V_48 = V_144 -> V_44 . V_476 . V_48 ;
V_180 -> V_477 = V_144 -> V_44 . V_476 . V_477 ;
memcpy ( V_180 -> V_478 , V_144 -> V_44 . V_476 . V_479 , 16 ) ;
if ( V_480 & V_48 )
V_180 -> V_481 = 1 ;
else
V_180 -> V_481 = 0 ;
if ( V_8 -> V_482 . V_481 == 0 )
V_180 -> V_481 = 0 ;
if ( V_483 & V_48 ) {
V_180 -> V_484 . V_485 = true ;
V_180 -> V_481 = 1 ;
memcpy ( & V_180 -> V_484 . V_36 , & V_144 -> V_44 . V_476 . V_36 ,
sizeof( struct V_55 ) ) ;
} else {
V_180 -> V_484 . V_485 = false ;
}
if ( V_8 -> V_484 . V_485 == false )
V_180 -> V_484 . V_485 = false ;
F_114 ( V_2 , V_180 ) ;
} else {
V_126 = - V_206 ;
}
return V_126 ;
}
static int F_115 ( struct V_124 * V_125 , struct V_143 * V_144 )
{
int V_126 = 0 ;
struct V_179 * V_180 = NULL ;
struct V_1 * V_2 = (struct V_1 * ) F_24 ( V_125 ) ;
struct V_7 * V_8 = & ( V_2 -> V_9 ) ;
struct V_182 * V_183 = & V_2 -> V_184 ;
int V_110 = 0 ;
F_25 ( L_106 , ( V_144 -> V_159 ) ) ;
if ( F_21 ( V_8 , ( V_114 | V_247 ) ) != true )
return - V_142 ;
if ( V_144 -> V_159 [ 0 ] == 0xff && V_144 -> V_159 [ 1 ] == 0xff &&
V_144 -> V_159 [ 2 ] == 0xff && V_144 -> V_159 [ 3 ] == 0xff &&
V_144 -> V_159 [ 4 ] == 0xff && V_144 -> V_159 [ 5 ] == 0xff )
return - V_142 ;
V_180 = F_31 ( V_183 , V_144 -> V_159 ) ;
if ( V_180 ) {
F_55 ( & V_183 -> V_486 ) ;
if ( ! F_116 ( & V_180 -> V_487 ) ) {
F_117 ( & V_180 -> V_487 ) ;
V_183 -> V_488 -- ;
V_110 = F_118 ( V_2 , V_180 , true , V_489 ) ;
}
F_58 ( & V_183 -> V_486 ) ;
F_119 ( V_2 , V_110 ) ;
V_180 = NULL ;
} else {
F_25 ( L_107 ) ;
}
return V_126 ;
}
static int F_120 ( struct V_124 * V_125 , struct V_143 * V_144 , int V_345 )
{
int V_126 = 0 ;
struct V_179 * V_180 = NULL ;
struct V_1 * V_2 = (struct V_1 * ) F_24 ( V_125 ) ;
struct V_7 * V_8 = & ( V_2 -> V_9 ) ;
struct V_182 * V_183 = & V_2 -> V_184 ;
struct V_490 * V_491 = (struct V_490 * ) V_144 ;
struct V_492 * V_493 = (struct V_492 * ) V_491 -> V_47 ;
F_25 ( L_108 , ( V_491 -> V_159 ) ) ;
if ( F_21 ( V_8 , ( V_114 | V_247 ) ) != true )
return - V_142 ;
if ( V_491 -> V_159 [ 0 ] == 0xff && V_491 -> V_159 [ 1 ] == 0xff &&
V_491 -> V_159 [ 2 ] == 0xff && V_491 -> V_159 [ 3 ] == 0xff &&
V_491 -> V_159 [ 4 ] == 0xff && V_491 -> V_159 [ 5 ] == 0xff )
return - V_142 ;
V_180 = F_31 ( V_183 , V_491 -> V_159 ) ;
if ( V_180 ) {
V_493 -> V_477 = ( T_1 ) V_180 -> V_477 ;
V_493 -> V_494 = V_180 -> V_494 ;
V_493 -> V_48 = V_180 -> V_48 ;
V_493 -> V_495 = ( ( V_180 -> V_496 ) |
( V_180 -> V_497 << 1 ) |
( V_180 -> V_498 << 2 ) |
( V_180 -> V_499 << 3 ) |
( V_180 -> V_500 << 4 ) |
( V_180 -> V_501 << 5 ) ) ;
V_493 -> V_502 = V_180 -> V_503 ;
memcpy ( V_493 -> V_479 , V_180 -> V_478 , V_180 -> V_503 ) ;
memcpy ( & V_493 -> V_36 ,
& V_180 -> V_484 . V_36 , sizeof( struct V_55 ) ) ;
V_493 -> V_504 = V_180 -> V_505 . V_506 ;
V_493 -> V_507 = V_180 -> V_505 . V_507 ;
V_493 -> V_508 = V_180 -> V_505 . V_508 ;
V_493 -> V_509 = V_180 -> V_505 . V_509 ;
V_493 -> V_510 = V_180 -> V_505 . V_510 ;
V_493 -> V_511 = V_180 -> V_505 . V_511 ;
} else {
V_126 = - 1 ;
}
return V_126 ;
}
static int F_121 ( struct V_124 * V_125 , struct V_143 * V_144 )
{
int V_126 = 0 ;
struct V_179 * V_180 = NULL ;
struct V_1 * V_2 = (struct V_1 * ) F_24 ( V_125 ) ;
struct V_7 * V_8 = & ( V_2 -> V_9 ) ;
struct V_182 * V_183 = & V_2 -> V_184 ;
F_25 ( L_109 , ( V_144 -> V_159 ) ) ;
if ( F_21 ( V_8 , ( V_114 | V_247 ) ) != true )
return - V_142 ;
if ( V_144 -> V_159 [ 0 ] == 0xff && V_144 -> V_159 [ 1 ] == 0xff &&
V_144 -> V_159 [ 2 ] == 0xff && V_144 -> V_159 [ 3 ] == 0xff &&
V_144 -> V_159 [ 4 ] == 0xff && V_144 -> V_159 [ 5 ] == 0xff )
return - V_142 ;
V_180 = F_31 ( V_183 , V_144 -> V_159 ) ;
if ( V_180 ) {
if ( V_180 -> V_94 [ 0 ] == V_512 ||
V_180 -> V_94 [ 0 ] == V_513 ) {
int V_514 ;
int V_515 ;
V_514 = V_180 -> V_94 [ 1 ] ;
V_515 = F_9 ( int , V_514 + 2 , sizeof( V_180 -> V_94 ) ) ;
V_144 -> V_44 . V_94 . V_345 = V_515 ;
memcpy ( V_144 -> V_44 . V_94 . V_474 , V_180 -> V_94 , V_515 ) ;
} else {
F_25 ( L_110 ) ;
}
} else {
V_126 = - 1 ;
}
return V_126 ;
}
static int F_122 ( struct V_124 * V_125 , struct V_143 * V_144 , int V_345 )
{
int V_126 = 0 ;
unsigned char V_221 [ 4 ] = { 0x0 , 0x50 , 0xf2 , 0x04 } ;
struct V_1 * V_2 = (struct V_1 * ) F_24 ( V_125 ) ;
struct V_7 * V_8 = & ( V_2 -> V_9 ) ;
struct V_270 * V_271 = & ( V_2 -> V_231 ) ;
int V_516 ;
F_25 ( L_104 , V_327 , V_345 ) ;
if ( F_21 ( V_8 , V_247 ) != true )
return - V_142 ;
V_516 = V_345 - 12 - 2 ;
F_35 ( V_8 -> V_517 ) ;
V_8 -> V_517 = NULL ;
if ( V_516 > 0 ) {
V_8 -> V_517 = F_28 ( V_516 ) ;
V_8 -> V_518 = V_516 ;
if ( ! V_8 -> V_517 ) {
F_25 ( L_111 , V_327 , __LINE__ ) ;
return - V_142 ;
}
memcpy ( V_8 -> V_517 , V_144 -> V_44 . V_472 . V_92 , V_516 ) ;
F_123 ( V_2 , V_222 , V_221 , true ) ;
V_271 -> V_519 = true ;
}
return V_126 ;
}
static int F_124 ( struct V_124 * V_125 , struct V_143 * V_144 , int V_345 )
{
int V_126 = 0 ;
struct V_1 * V_2 = (struct V_1 * ) F_24 ( V_125 ) ;
struct V_7 * V_8 = & ( V_2 -> V_9 ) ;
int V_516 ;
F_25 ( L_104 , V_327 , V_345 ) ;
if ( F_21 ( V_8 , V_247 ) != true )
return - V_142 ;
V_516 = V_345 - 12 - 2 ;
F_35 ( V_8 -> V_520 ) ;
V_8 -> V_520 = NULL ;
if ( V_516 > 0 ) {
V_8 -> V_520 = F_28 ( V_516 ) ;
V_8 -> V_521 = V_516 ;
if ( ! V_8 -> V_520 ) {
F_25 ( L_111 , V_327 , __LINE__ ) ;
return - V_142 ;
}
memcpy ( V_8 -> V_520 , V_144 -> V_44 . V_472 . V_92 , V_516 ) ;
}
return V_126 ;
}
static int F_125 ( struct V_124 * V_125 , struct V_143 * V_144 , int V_345 )
{
int V_126 = 0 ;
struct V_1 * V_2 = (struct V_1 * ) F_24 ( V_125 ) ;
struct V_7 * V_8 = & ( V_2 -> V_9 ) ;
int V_516 ;
F_25 ( L_104 , V_327 , V_345 ) ;
if ( F_21 ( V_8 , V_247 ) != true )
return - V_142 ;
V_516 = V_345 - 12 - 2 ;
F_35 ( V_8 -> V_522 ) ;
V_8 -> V_522 = NULL ;
if ( V_516 > 0 ) {
V_8 -> V_522 = F_28 ( V_516 ) ;
V_8 -> V_523 = V_516 ;
if ( ! V_8 -> V_522 ) {
F_25 ( L_111 , V_327 , __LINE__ ) ;
return - V_142 ;
}
memcpy ( V_8 -> V_522 , V_144 -> V_44 . V_472 . V_92 , V_516 ) ;
}
return V_126 ;
}
static int F_126 ( struct V_124 * V_125 , struct V_143 * V_144 , int V_345 )
{
int V_126 = 0 ;
struct V_1 * V_2 = (struct V_1 * ) F_24 ( V_125 ) ;
struct V_7 * V_8 = & ( V_2 -> V_9 ) ;
struct V_270 * V_271 = & ( V_2 -> V_231 ) ;
struct V_524 * V_525 = & ( V_271 -> V_526 ) ;
T_4 V_90 ;
if ( F_21 ( V_8 , V_247 ) != true )
return - V_142 ;
if ( V_144 -> V_44 . V_444 . V_65 != 0 )
F_25 ( L_112 , V_327 , V_144 -> V_44 . V_444 . V_65 ) ;
V_90 = V_144 -> V_44 . V_444 . V_90 ;
if ( V_90 != 1 && V_90 != 2 )
V_90 = 0 ;
F_25 ( L_113 , V_327 , V_90 ) ;
V_525 -> V_527 = V_90 ;
return V_126 ;
}
static int F_127 ( struct V_124 * V_125 , struct V_143 * V_144 , int V_345 )
{
struct V_1 * V_2 = (struct V_1 * ) F_24 ( V_125 ) ;
struct V_7 * V_8 = & ( V_2 -> V_9 ) ;
if ( F_21 ( V_8 , V_247 ) != true )
return - V_142 ;
if ( V_144 -> V_159 [ 0 ] == 0xff && V_144 -> V_159 [ 1 ] == 0xff &&
V_144 -> V_159 [ 2 ] == 0xff && V_144 -> V_159 [ 3 ] == 0xff &&
V_144 -> V_159 [ 4 ] == 0xff && V_144 -> V_159 [ 5 ] == 0xff )
return - V_142 ;
return F_128 ( V_2 , V_144 -> V_159 ) ;
}
static int F_129 ( struct V_124 * V_125 , struct V_143 * V_144 , int V_345 )
{
struct V_1 * V_2 = (struct V_1 * ) F_24 ( V_125 ) ;
struct V_7 * V_8 = & ( V_2 -> V_9 ) ;
if ( F_21 ( V_8 , V_247 ) != true )
return - V_142 ;
if ( V_144 -> V_159 [ 0 ] == 0xff && V_144 -> V_159 [ 1 ] == 0xff &&
V_144 -> V_159 [ 2 ] == 0xff && V_144 -> V_159 [ 3 ] == 0xff &&
V_144 -> V_159 [ 4 ] == 0xff && V_144 -> V_159 [ 5 ] == 0xff )
return - V_142 ;
return F_130 ( V_2 , V_144 -> V_159 ) ;
}
static int F_131 ( struct V_124 * V_125 , struct V_143 * V_144 , int V_345 )
{
int V_126 = 0 ;
struct V_1 * V_2 = (struct V_1 * ) F_24 ( V_125 ) ;
struct V_7 * V_8 = & ( V_2 -> V_9 ) ;
if ( F_21 ( V_8 , V_247 ) != true )
return - V_142 ;
F_132 ( V_2 , V_144 -> V_44 . V_326 . V_437 ) ;
return V_126 ;
}
static int F_133 ( struct V_124 * V_125 , struct V_389 * V_33 )
{
struct V_143 * V_144 ;
int V_126 = 0 ;
struct V_1 * V_2 = (struct V_1 * ) F_24 ( V_125 ) ;
if ( ! V_2 -> V_238 ) {
V_126 = - V_237 ;
goto V_441;
}
if ( ! V_33 -> V_440 ) {
V_126 = - V_142 ;
goto V_441;
}
V_144 = (struct V_143 * ) F_28 ( V_33 -> V_49 ) ;
if ( ! V_144 ) {
V_126 = - V_206 ;
goto V_441;
}
if ( F_98 ( V_144 , V_33 -> V_440 , V_33 -> V_49 ) ) {
F_35 ( V_144 ) ;
V_126 = - V_442 ;
goto V_441;
}
switch ( V_144 -> V_43 ) {
case V_528 :
V_126 = F_110 ( V_125 ) ;
break;
case V_529 :
V_126 = F_113 ( V_125 , V_144 ) ;
break;
case V_530 :
V_126 = F_115 ( V_125 , V_144 ) ;
break;
case V_531 :
V_126 = F_108 ( V_125 , V_144 , V_33 -> V_49 ) ;
break;
case V_532 :
V_126 = F_107 ( V_125 , V_144 , V_33 -> V_49 ) ;
break;
case V_533 :
V_126 = F_121 ( V_125 , V_144 ) ;
break;
case V_534 :
V_126 = F_122 ( V_125 , V_144 , V_33 -> V_49 ) ;
break;
case V_535 :
V_126 = F_124 ( V_125 , V_144 , V_33 -> V_49 ) ;
break;
case V_536 :
V_126 = F_125 ( V_125 , V_144 , V_33 -> V_49 ) ;
break;
case V_537 :
V_126 = F_126 ( V_125 , V_144 , V_33 -> V_49 ) ;
break;
case V_538 :
V_126 = F_120 ( V_125 , V_144 , V_33 -> V_49 ) ;
break;
case V_539 :
V_126 = F_131 ( V_125 , V_144 , V_33 -> V_49 ) ;
break;
case V_540 :
V_126 = F_129 ( V_125 , V_144 , V_33 -> V_49 ) ;
break;
case V_541 :
V_126 = F_127 ( V_125 , V_144 , V_33 -> V_49 ) ;
break;
default:
F_25 ( L_114 , V_144 -> V_43 ) ;
V_126 = - V_174 ;
break;
}
if ( V_126 == 0 && F_99 ( V_33 -> V_440 , V_144 , V_33 -> V_49 ) )
V_126 = - V_442 ;
F_35 ( V_144 ) ;
V_441:
return V_126 ;
}
static int F_134 ( struct V_124 * V_125 ,
struct V_20 * V_21 ,
union V_3 * V_306 ,
char * V_225 )
{
int V_126 = 0 ;
int V_345 = 0 ;
char * V_542 ;
struct V_1 * V_2 = (struct V_1 * ) F_24 ( V_125 ) ;
struct V_389 * V_543 = (struct V_389 * ) V_306 ;
if ( V_543 -> V_49 == 0 )
return - V_442 ;
V_345 = V_543 -> V_49 ;
V_542 = F_135 ( V_345 ) ;
if ( ! V_542 )
return - V_206 ;
if ( F_98 ( V_542 , V_543 -> V_440 , V_345 ) ) {
F_136 ( V_542 ) ;
return - V_442 ;
}
if ( V_543 -> V_48 == 0x8766 && V_345 > 8 ) {
T_3 V_544 ;
struct V_7 * V_8 = & ( V_2 -> V_9 ) ;
T_4 * V_545 = V_542 ;
int V_546 = V_345 ;
T_4 V_221 [ 4 ] = { 0x0 , 0x50 , 0xf2 , 0x04 } ;
if ( ( V_222 == V_545 [ 0 ] ) &&
( ! memcmp ( & V_545 [ 2 ] , V_221 , 4 ) ) ) {
V_544 = F_41 ( V_546 , V_547 ) ;
V_8 -> V_548 = 0 ;
F_35 ( V_8 -> V_549 ) ;
V_8 -> V_549 = NULL ;
V_8 -> V_549 = F_28 ( V_544 ) ;
if ( ! V_8 -> V_549 ) {
F_137 ( L_111 , V_327 , __LINE__ ) ;
V_126 = - V_142 ;
goto V_550;
}
memcpy ( V_8 -> V_549 , V_545 , V_544 ) ;
V_8 -> V_548 = V_544 ;
}
goto V_550;
}
if ( V_345 >= V_351 &&
! memcmp ( V_542 , V_352 , V_351 ) ) {
V_126 = F_64 ( V_125 , V_21 , V_306 , V_542 ) ;
goto V_550;
}
V_550:
F_136 ( V_542 ) ;
return V_126 ;
}
static struct V_551 * F_138 ( struct V_124 * V_125 )
{
struct V_1 * V_2 = (struct V_1 * ) F_24 ( V_125 ) ;
struct V_551 * V_552 = & V_2 -> V_553 ;
int V_554 = 0 ;
int V_555 = 0 ;
int V_556 = 0 ;
if ( ! F_21 ( & V_2 -> V_9 , V_114 ) ) {
V_552 -> V_109 . V_109 = 0 ;
V_552 -> V_109 . V_121 = 0 ;
V_552 -> V_109 . V_122 = 0 ;
} else {
V_554 = V_2 -> V_115 . V_116 ;
V_555 = V_2 -> V_115 . V_117 ;
V_556 = V_2 -> V_115 . V_122 ;
V_552 -> V_109 . V_121 = V_554 ;
V_552 -> V_109 . V_109 = V_555 ;
V_552 -> V_109 . V_122 = V_556 ;
}
V_552 -> V_109 . V_110 = V_557 ;
return & V_2 -> V_553 ;
}
int F_139 ( struct V_124 * V_125 , struct V_558 * V_559 , int V_43 )
{
struct V_560 * V_561 = (struct V_560 * ) V_559 ;
int V_126 = 0 ;
switch ( V_43 ) {
case V_562 :
V_126 = F_97 ( V_125 , & V_561 -> V_44 . V_47 ) ;
break;
#ifdef F_140
case V_563 :
V_126 = F_133 ( V_125 , & V_561 -> V_44 . V_47 ) ;
break;
#endif
case ( V_564 + 1 ) :
V_126 = F_141 ( V_125 , V_559 , V_43 ) ;
break;
default:
V_126 = - V_174 ;
break;
}
return V_126 ;
}
