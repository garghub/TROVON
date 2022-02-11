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
if ( F_21 ( V_8 , V_185 ) ) {
V_180 = F_31 ( V_183 , F_32 ( V_8 ) ) ;
if ( ! V_180 ) {
;
} else {
if ( strcmp ( V_144 -> V_44 . V_153 . V_155 , L_32 ) != 0 )
V_180 -> V_186 = false ;
if ( ( V_2 -> V_129 . V_130 == V_187 ) ||
( V_2 -> V_129 . V_130 == V_188 ) )
V_180 -> V_189 = V_2 -> V_129 . V_164 ;
if ( V_144 -> V_44 . V_153 . V_172 == 1 ) {
memcpy ( V_180 -> V_190 . V_176 , V_144 -> V_44 . V_153 . V_157 , F_9 ( T_1 , V_144 -> V_44 . V_153 . V_158 , 16 ) ) ;
if ( strcmp ( V_144 -> V_44 . V_153 . V_155 , L_33 ) == 0 ) {
memcpy ( V_180 -> V_191 . V_176 , & ( V_144 -> V_44 . V_153 . V_157 [ 16 ] ) , 8 ) ;
memcpy ( V_180 -> V_192 . V_176 , & ( V_144 -> V_44 . V_153 . V_157 [ 24 ] ) , 8 ) ;
V_2 -> V_129 . V_193 = false ;
}
F_25 ( L_34 ) ;
F_33 ( V_2 , ( unsigned char * ) V_180 , true ) ;
} else {
memcpy ( V_2 -> V_129 . V_194 [ V_144 -> V_44 . V_153 . V_160 ] . V_176 , V_144 -> V_44 . V_153 . V_157 , F_9 ( T_1 , V_144 -> V_44 . V_153 . V_158 , 16 ) ) ;
memcpy ( V_2 -> V_129 . V_195 [ V_144 -> V_44 . V_153 . V_160 ] . V_176 , & ( V_144 -> V_44 . V_153 . V_157 [ 16 ] ) , 8 ) ;
memcpy ( V_2 -> V_129 . V_196 [ V_144 -> V_44 . V_153 . V_160 ] . V_176 , & ( V_144 -> V_44 . V_153 . V_157 [ 24 ] ) , 8 ) ;
V_2 -> V_129 . V_197 = true ;
F_25 ( L_35 ) ;
V_2 -> V_129 . V_198 = V_144 -> V_44 . V_153 . V_160 ;
F_30 ( V_2 , & V_2 -> V_129 , V_144 -> V_44 . V_153 . V_160 , 1 ) ;
}
}
V_181 = F_34 ( V_2 ) ;
if ( ! V_181 ) {
;
} else {
if ( strcmp ( V_144 -> V_44 . V_153 . V_155 , L_32 ) != 0 )
V_181 -> V_186 = false ;
if ( ( V_2 -> V_129 . V_130 == V_187 ) ||
( V_2 -> V_129 . V_130 == V_188 ) )
V_181 -> V_189 = V_2 -> V_129 . V_164 ;
}
}
}
exit:
F_35 ( V_150 ) ;
return V_126 ;
}
static int F_36 ( struct V_1 * V_2 , char * V_199 , unsigned short V_200 )
{
T_4 * V_92 = NULL ;
int V_201 = 0 , V_202 = 0 ;
int V_126 = 0 ;
if ( ( V_200 > V_93 ) || ( ! V_199 ) ) {
F_37 ( & V_2 -> V_9 , V_203 ) ;
if ( ! V_199 )
return V_126 ;
else
return - V_142 ;
}
if ( V_200 ) {
V_92 = F_38 ( V_199 , V_200 , V_204 ) ;
if ( ! V_92 ) {
V_126 = - V_205 ;
goto exit;
}
{
int V_37 ;
F_25 ( L_36 , V_200 ) ;
for ( V_37 = 0 ; V_37 < V_200 ; V_37 += 8 )
F_25 ( L_37 , V_92 [ V_37 ] , V_92 [ V_37 + 1 ] , V_92 [ V_37 + 2 ] , V_92 [ V_37 + 3 ] , V_92 [ V_37 + 4 ] , V_92 [ V_37 + 5 ] , V_92 [ V_37 + 6 ] , V_92 [ V_37 + 7 ] ) ;
}
if ( V_200 < V_206 ) {
F_19 ( V_162 , V_163 , ( L_38 , V_200 ) ) ;
V_126 = - 1 ;
goto exit;
}
if ( F_39 ( V_92 , V_200 , & V_201 , & V_202 , NULL ) == V_207 ) {
V_2 -> V_129 . V_134 = V_178 ;
V_2 -> V_129 . V_132 = V_138 ;
memcpy ( V_2 -> V_129 . V_208 , & V_92 [ 0 ] , V_200 ) ;
}
if ( F_40 ( V_92 , V_200 , & V_201 , & V_202 , NULL ) == V_207 ) {
V_2 -> V_129 . V_134 = V_178 ;
V_2 -> V_129 . V_132 = V_209 ;
memcpy ( V_2 -> V_129 . V_208 , & V_92 [ 0 ] , V_200 ) ;
}
switch ( V_201 ) {
case V_210 :
V_2 -> V_129 . V_166 = V_211 ;
V_2 -> V_129 . V_130 = V_212 ;
break;
case V_213 :
V_2 -> V_129 . V_166 = V_165 ;
V_2 -> V_129 . V_130 = V_131 ;
break;
case V_214 :
V_2 -> V_129 . V_166 = V_215 ;
V_2 -> V_129 . V_130 = V_187 ;
break;
case V_216 :
V_2 -> V_129 . V_166 = V_217 ;
V_2 -> V_129 . V_130 = V_188 ;
break;
case V_218 :
V_2 -> V_129 . V_166 = V_170 ;
V_2 -> V_129 . V_130 = V_131 ;
break;
}
switch ( V_202 ) {
case V_210 :
V_2 -> V_129 . V_164 = V_211 ;
V_2 -> V_129 . V_130 = V_212 ;
break;
case V_213 :
V_2 -> V_129 . V_164 = V_165 ;
V_2 -> V_129 . V_130 = V_131 ;
break;
case V_214 :
V_2 -> V_129 . V_164 = V_215 ;
V_2 -> V_129 . V_130 = V_187 ;
break;
case V_216 :
V_2 -> V_129 . V_164 = V_217 ;
V_2 -> V_129 . V_130 = V_188 ;
break;
case V_218 :
V_2 -> V_129 . V_164 = V_170 ;
V_2 -> V_129 . V_130 = V_131 ;
break;
}
F_37 ( & V_2 -> V_9 , V_203 ) ;
{
T_1 V_102 = 0 ;
T_4 V_219 , V_220 [ 4 ] = { 0x0 , 0x50 , 0xf2 , 0x04 } ;
while ( V_102 < V_200 ) {
V_219 = V_92 [ V_102 ] ;
if ( ( V_219 == V_221 ) && ( ! memcmp ( & V_92 [ V_102 + 2 ] , V_220 , 4 ) ) ) {
F_25 ( L_39 ) ;
V_2 -> V_129 . V_222 = F_41 ( V_92 [ V_102 + 1 ] + 2 , V_93 << 2 ) ;
memcpy ( V_2 -> V_129 . V_223 , & V_92 [ V_102 ] , V_2 -> V_129 . V_222 ) ;
F_42 ( & V_2 -> V_9 , V_203 ) ;
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
V_202 , V_2 -> V_129 . V_130 , V_2 -> V_129 . V_132 ) ) ;
exit:
F_35 ( V_92 ) ;
return V_126 ;
}
static int F_43 ( struct V_124 * V_125 ,
struct V_20 * V_21 ,
union V_3 * V_4 , char * V_224 )
{
struct V_1 * V_2 = (struct V_1 * ) F_24 ( V_125 ) ;
T_3 V_30 = 0 ;
char * V_33 ;
T_4 V_36 = false ;
struct V_7 * V_8 = & ( V_2 -> V_9 ) ;
struct V_225 * V_226 = & V_8 -> V_14 . V_15 ;
T_6 * V_227 = NULL ;
F_19 ( V_98 , V_99 , ( L_41 , V_21 -> V_43 ) ) ;
if ( F_21 ( V_8 , V_114 | V_228 ) == true ) {
V_33 = F_11 ( & V_226 -> V_52 [ 12 ] , V_53 , & V_30 , V_226 -> V_54 - 12 ) ;
if ( V_33 && V_30 > 0 )
V_36 = true ;
V_227 = & V_226 -> V_64 ;
if ( F_13 ( ( T_4 * ) V_227 ) == true ) {
if ( V_36 )
snprintf ( V_4 -> V_65 , V_66 , L_3 ) ;
else
snprintf ( V_4 -> V_65 , V_66 , L_4 ) ;
} else if ( ( F_14 ( ( T_4 * ) V_227 ) ) == true ) {
if ( V_36 )
snprintf ( V_4 -> V_65 , V_66 , L_5 ) ;
else
snprintf ( V_4 -> V_65 , V_66 , L_6 ) ;
} else {
if ( V_226 -> V_67 . V_68 > 14 ) {
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
union V_3 * V_4 , char * V_224 )
{
F_19 ( V_98 , V_229 , ( L_43 ) ) ;
return 0 ;
}
static int F_45 ( struct V_124 * V_125 ,
struct V_20 * V_21 ,
union V_3 * V_4 , char * V_224 )
{
struct V_1 * V_2 = (struct V_1 * ) F_24 ( V_125 ) ;
struct V_7 * V_8 = & ( V_2 -> V_9 ) ;
struct V_225 * V_226 = & V_8 -> V_14 . V_15 ;
if ( F_21 ( V_8 , V_114 ) ) {
V_4 -> V_77 . V_78 = F_17 ( V_226 -> V_67 . V_68 ) * 100000 ;
V_4 -> V_77 . V_79 = 1 ;
V_4 -> V_77 . V_37 = V_226 -> V_67 . V_68 ;
} else {
V_4 -> V_77 . V_78 = F_17 ( V_2 -> V_230 . V_231 ) * 100000 ;
V_4 -> V_77 . V_79 = 1 ;
V_4 -> V_77 . V_37 = V_2 -> V_230 . V_231 ;
}
return 0 ;
}
static int F_46 ( struct V_124 * V_125 , struct V_20 * V_232 ,
union V_3 * V_4 , char * V_233 )
{
struct V_1 * V_2 = (struct V_1 * ) F_24 ( V_125 ) ;
enum V_234 V_235 ;
int V_126 = 0 ;
if ( V_173 == F_47 ( V_2 ) ) {
V_126 = - V_236 ;
goto exit;
}
if ( ! V_2 -> V_237 ) {
V_126 = - V_236 ;
goto exit;
}
switch ( V_4 -> V_72 ) {
case V_238 :
V_235 = V_239 ;
F_25 ( L_44 ) ;
break;
case V_74 :
V_235 = V_240 ;
F_25 ( L_45 ) ;
break;
case V_73 :
V_235 = V_241 ;
F_25 ( L_46 ) ;
break;
case V_242 :
V_235 = V_243 ;
F_25 ( L_47 ) ;
break;
default:
V_126 = - V_142 ;
F_19 ( V_162 , V_163 , ( L_48 , V_244 [ V_4 -> V_72 ] ) ) ;
goto exit;
}
if ( F_48 ( V_2 , V_235 ) == false ) {
V_126 = - V_236 ;
goto exit;
}
F_49 ( V_2 , V_235 ) ;
exit:
return V_126 ;
}
static int F_50 ( struct V_124 * V_125 , struct V_20 * V_232 ,
union V_3 * V_4 , char * V_233 )
{
struct V_1 * V_2 = (struct V_1 * ) F_24 ( V_125 ) ;
struct V_7 * V_8 = & ( V_2 -> V_9 ) ;
F_19 ( V_98 , V_99 , ( L_49 ) ) ;
if ( F_21 ( V_8 , V_185 ) )
V_4 -> V_72 = V_242 ;
else if ( ( F_21 ( V_8 , V_228 ) ) ||
( F_21 ( V_8 , V_245 ) ) )
V_4 -> V_72 = V_74 ;
else if ( F_21 ( V_8 , V_246 ) )
V_4 -> V_72 = V_73 ;
else
V_4 -> V_72 = V_238 ;
return 0 ;
}
static int F_51 ( struct V_124 * V_125 ,
struct V_20 * V_232 ,
union V_3 * V_4 , char * V_224 )
{
struct V_1 * V_2 = (struct V_1 * ) F_24 ( V_125 ) ;
T_4 V_247 , V_248 = false ;
int V_126 = false ;
struct V_151 * V_152 = & V_2 -> V_129 ;
struct V_249 * V_250 = (struct V_249 * ) V_224 ;
T_4 V_251 [ V_17 ] = { 0x00 } ;
T_4 V_252 [ V_17 ] = { 0x00 } ;
memcpy ( V_252 , V_250 -> V_253 . V_13 , V_17 ) ;
if ( V_250 -> V_43 == V_254 ) {
F_25 ( L_50 ) ;
if ( ! memcmp ( V_252 , V_251 , V_17 ) )
return V_126 ;
else
V_126 = true ;
V_248 = false ;
for ( V_247 = 0 ; V_247 < V_255 ; V_247 ++ ) {
if ( ! memcmp ( V_152 -> V_256 [ V_247 ] . V_257 , V_252 , V_17 ) ) {
F_25 ( L_51 ) ;
memcpy ( V_152 -> V_256 [ V_247 ] . V_258 , V_250 -> V_259 , V_260 ) ;
V_152 -> V_256 [ V_247 ] . V_261 = true ;
V_152 -> V_262 = V_247 + 1 ;
V_248 = true ;
break;
}
}
if ( ! V_248 ) {
F_25 ( L_52 ,
V_152 -> V_262 ) ;
memcpy ( V_152 -> V_256 [ V_152 -> V_262 ] . V_257 , V_252 , V_17 ) ;
memcpy ( V_152 -> V_256 [ V_152 -> V_262 ] . V_258 , V_250 -> V_259 , V_260 ) ;
V_152 -> V_256 [ V_152 -> V_262 ] . V_261 = true ;
V_152 -> V_262 ++ ;
if ( V_152 -> V_262 == 16 )
V_152 -> V_262 = 0 ;
}
} else if ( V_250 -> V_43 == V_263 ) {
F_25 ( L_53 ) ;
V_126 = true ;
for ( V_247 = 0 ; V_247 < V_255 ; V_247 ++ ) {
if ( ! memcmp ( V_152 -> V_256 [ V_247 ] . V_257 , V_252 , V_17 ) ) {
F_6 ( V_152 -> V_256 [ V_247 ] . V_257 ) ;
V_152 -> V_256 [ V_247 ] . V_261 = false ;
break;
}
}
} else if ( V_250 -> V_43 == V_264 ) {
F_25 ( L_54 ) ;
memset ( & V_152 -> V_256 [ 0 ] , 0x00 , sizeof( struct V_265 ) * V_255 ) ;
V_152 -> V_262 = 0 ;
V_126 = true ;
}
return V_126 ;
}
static int F_52 ( struct V_124 * V_125 ,
struct V_20 * V_21 ,
union V_3 * V_4 , char * V_224 )
{
V_4 -> V_266 . V_90 = 0 ;
V_4 -> V_266 . V_88 = 0 ;
V_4 -> V_266 . V_89 = 1 ;
return 0 ;
}
static int F_53 ( struct V_124 * V_125 ,
struct V_20 * V_21 ,
union V_3 * V_4 , char * V_224 )
{
struct V_267 * V_268 = (struct V_267 * ) V_224 ;
struct V_1 * V_2 = (struct V_1 * ) F_24 ( V_125 ) ;
struct V_269 * V_270 = & V_2 -> V_230 ;
T_1 V_271 ;
int V_37 ;
F_19 ( V_98 , V_99 , ( L_55 , V_21 -> V_43 ) ) ;
V_4 -> V_47 . V_49 = sizeof( * V_268 ) ;
memset ( V_268 , 0 , sizeof( * V_268 ) ) ;
V_268 -> V_272 = 5 * 1000 * 1000 ;
V_268 -> V_273 . V_109 = 100 ;
V_268 -> V_273 . V_121 = 100 ;
V_268 -> V_273 . V_122 = 100 ;
V_268 -> V_273 . V_110 = 7 ;
V_268 -> V_274 . V_109 = 92 ;
V_268 -> V_274 . V_121 = 178 ;
V_268 -> V_274 . V_122 = 0 ;
V_268 -> V_274 . V_110 = 7 ;
V_268 -> V_275 = V_276 ;
for ( V_37 = 0 ; V_37 < V_276 && V_37 < V_277 ; V_37 ++ )
V_268 -> V_87 [ V_37 ] = V_278 [ V_37 ] ;
V_268 -> V_279 = V_280 ;
V_268 -> V_281 = V_282 ;
V_268 -> V_283 = 0 ;
V_268 -> V_284 = V_285 ;
V_268 -> V_286 = 16 ;
for ( V_37 = 0 , V_271 = 0 ; V_37 < V_287 ; V_37 ++ ) {
if ( V_270 -> V_288 [ V_37 ] . V_289 != 0 ) {
V_268 -> V_77 [ V_271 ] . V_37 = V_270 -> V_288 [ V_37 ] . V_289 ;
V_268 -> V_77 [ V_271 ] . V_78 = F_17 ( V_270 -> V_288 [ V_37 ] . V_289 ) * 100000 ;
V_268 -> V_77 [ V_271 ] . V_79 = 1 ;
V_271 ++ ;
}
if ( V_271 == V_290 )
break;
}
V_268 -> V_291 = V_271 ;
V_268 -> V_292 = V_271 ;
V_268 -> V_293 = V_294 | V_295 |
V_296 | V_297 ;
V_268 -> V_298 = V_299 | V_300 |
V_301 | V_302 |
V_303 | V_304 ;
return 0 ;
}
static int F_54 ( struct V_124 * V_125 ,
struct V_20 * V_21 ,
union V_3 * V_305 ,
char * V_224 )
{
T_5 V_126 = 0 ;
struct V_1 * V_2 = (struct V_1 * ) F_24 ( V_125 ) ;
struct V_306 * V_307 = (struct V_306 * ) V_305 ;
struct V_7 * V_8 = & ( V_2 -> V_9 ) ;
struct V_308 * V_309 ;
T_4 * V_310 , * V_311 ;
struct V_312 * V_313 = & ( V_8 -> V_314 ) ;
struct V_22 * V_23 = NULL ;
enum V_315 V_316 ;
if ( V_173 == F_47 ( V_2 ) ) {
V_126 = - 1 ;
goto exit;
}
if ( ! V_2 -> V_317 ) {
V_126 = - 1 ;
goto exit;
}
if ( V_307 -> V_11 != V_12 ) {
V_126 = - V_142 ;
goto exit;
}
V_316 = V_2 -> V_129 . V_132 ;
F_55 ( & V_313 -> V_318 ) ;
V_309 = F_56 ( V_313 ) ;
V_8 -> V_319 = V_309 -> V_320 ;
while ( V_309 != V_8 -> V_319 ) {
V_23 = F_57 ( V_8 -> V_319 , struct V_22 , V_321 ) ;
V_8 -> V_319 = V_8 -> V_319 -> V_320 ;
V_310 = V_23 -> V_15 . V_16 ;
V_311 = V_307 -> V_13 ;
if ( ( ! memcmp ( V_310 , V_311 , V_17 ) ) ) {
if ( ! F_48 ( V_2 , V_23 -> V_15 . V_322 ) ) {
V_126 = - 1 ;
F_58 ( & V_313 -> V_318 ) ;
goto exit;
}
break;
}
}
F_58 ( & V_313 -> V_318 ) ;
F_59 ( V_2 , V_316 ) ;
if ( F_60 ( V_2 , V_307 -> V_13 ) == false ) {
V_126 = - 1 ;
goto exit;
}
exit:
return V_126 ;
}
static int F_61 ( struct V_124 * V_125 ,
struct V_20 * V_21 ,
union V_3 * V_4 , char * V_224 )
{
struct V_1 * V_2 = (struct V_1 * ) F_24 ( V_125 ) ;
struct V_7 * V_8 = & ( V_2 -> V_9 ) ;
struct V_225 * V_226 = & V_8 -> V_14 . V_15 ;
V_4 -> V_10 . V_11 = V_12 ;
F_6 ( V_4 -> V_10 . V_13 ) ;
F_19 ( V_98 , V_99 , ( L_56 ) ) ;
if ( ( ( F_21 ( V_8 , V_114 ) ) == true ) ||
( ( F_21 ( V_8 , V_228 ) ) == true ) ||
( ( F_21 ( V_8 , V_246 ) ) == true ) )
memcpy ( V_4 -> V_10 . V_13 , V_226 -> V_16 , V_17 ) ;
else
F_6 ( V_4 -> V_10 . V_13 ) ;
return 0 ;
}
static int F_62 ( struct V_124 * V_125 ,
struct V_20 * V_21 ,
union V_3 * V_4 , char * V_224 )
{
int V_126 = 0 ;
T_1 V_323 ;
struct V_1 * V_2 = (struct V_1 * ) F_24 ( V_125 ) ;
struct V_324 * V_325 = (struct V_324 * ) V_224 ;
if ( ! V_325 )
return - 1 ;
F_25 ( L_57 , V_326 ) ;
V_323 = V_325 -> V_327 ;
F_25 ( L_58 , V_326 , V_325 -> V_43 , V_323 ) ;
switch ( V_325 -> V_43 ) {
case V_328 :
if ( ! F_63 ( V_2 ) )
V_126 = - 1 ;
break;
case V_329 :
if ( ! F_63 ( V_2 ) )
V_126 = - 1 ;
break;
default:
return - V_174 ;
}
return V_126 ;
}
static int F_64 ( struct V_124 * V_125 , struct V_20 * V_232 ,
union V_3 * V_4 , char * V_224 )
{
T_4 V_330 = false ;
int V_126 = 0 ;
struct V_1 * V_2 = (struct V_1 * ) F_24 ( V_125 ) ;
struct V_7 * V_8 = & V_2 -> V_9 ;
struct V_331 V_332 [ V_333 ] ;
F_19 ( V_98 , V_99 , ( L_59 ) ) ;
if ( V_173 == F_47 ( V_2 ) ) {
V_126 = - 1 ;
goto exit;
}
if ( V_2 -> V_334 ) {
F_25 ( L_60 , V_2 -> V_334 ) ;
V_126 = - 1 ;
goto exit;
}
if ( ! V_2 -> V_317 ) {
V_126 = - 1 ;
goto exit;
}
if ( ! V_2 -> V_237 ) {
V_126 = - 1 ;
goto exit;
}
if ( V_8 -> V_335 . V_336 ) {
F_1 ( V_2 ) ;
goto exit;
}
if ( F_21 ( V_8 , V_337 | V_338 ) ) {
F_1 ( V_2 ) ;
goto exit;
}
memset ( V_332 , 0 , sizeof( struct V_331 ) * V_333 ) ;
if ( V_4 -> V_47 . V_49 == sizeof( struct V_339 ) ) {
struct V_339 * V_340 = (struct V_339 * ) V_224 ;
if ( V_4 -> V_47 . V_48 & V_341 ) {
int V_342 = F_9 ( int , V_340 -> V_343 ,
V_344 ) ;
memcpy ( V_332 [ 0 ] . V_50 , V_340 -> V_345 , V_342 ) ;
V_332 [ 0 ] . V_51 = V_342 ;
F_25 ( L_61 , V_340 -> V_345 , V_340 -> V_343 ) ;
F_55 ( & V_8 -> V_318 ) ;
V_330 = F_65 ( V_2 , V_332 , 1 , NULL , 0 ) ;
F_58 ( & V_8 -> V_318 ) ;
} else if ( V_340 -> V_346 == V_347 ) {
F_25 ( L_62 ) ;
}
} else {
if ( V_4 -> V_47 . V_49 >= V_348 &&
! memcmp ( V_224 , V_349 , V_348 ) ) {
int V_342 = V_4 -> V_47 . V_49 - V_348 ;
char * V_350 = V_224 + V_348 ;
char V_351 ;
char V_352 ;
int V_353 = 0 ;
while ( V_342 >= 1 ) {
V_351 = * ( V_350 ++ ) ;
V_342 -= 1 ;
switch ( V_351 ) {
case V_354 :
if ( V_342 < 1 ) {
V_342 = 0 ;
break;
}
V_352 = * ( V_350 ++ ) ; V_342 -= 1 ;
if ( V_352 > 0 && V_352 <= V_342 ) {
V_332 [ V_353 ] . V_51 = V_352 ;
memcpy ( V_332 [ V_353 ] . V_50 , V_350 , V_332 [ V_353 ] . V_51 ) ;
V_353 ++ ;
}
V_350 += V_352 ;
V_342 -= V_352 ;
break;
case V_355 :
case V_356 :
V_350 += 1 ;
V_342 -= 1 ;
break;
case V_357 :
case V_358 :
case V_359 :
V_350 += 2 ;
V_342 -= 2 ;
break;
default:
V_342 = 0 ;
}
}
V_330 = F_66 ( V_2 , V_332 , V_333 ) ;
} else {
V_330 = F_66 ( V_2 , NULL , 0 ) ;
}
}
if ( ! V_330 )
V_126 = - 1 ;
exit:
return V_126 ;
}
static int F_67 ( struct V_124 * V_125 , struct V_20 * V_232 ,
union V_3 * V_4 , char * V_224 )
{
struct V_308 * V_360 , * V_309 ;
struct V_1 * V_2 = (struct V_1 * ) F_24 ( V_125 ) ;
struct V_7 * V_8 = & ( V_2 -> V_9 ) ;
struct V_312 * V_313 = & ( V_8 -> V_314 ) ;
struct V_22 * V_23 = NULL ;
char * V_361 = V_224 ;
char * V_25 = V_361 + V_4 -> V_47 . V_49 ;
T_3 V_126 = 0 ;
T_3 V_102 = 0 ;
T_3 V_362 ;
int V_363 ;
F_19 ( V_98 , V_99 , ( L_63 ) ) ;
F_19 ( V_162 , V_99 , ( L_64 ) ) ;
if ( V_2 -> V_364 . V_365 && V_2 -> V_334 ) {
V_126 = - V_142 ;
goto exit;
}
V_362 = 100 ;
V_363 = V_337 | V_338 ;
while ( F_21 ( V_8 , V_363 ) ) {
F_68 ( 30 ) ;
V_102 ++ ;
if ( V_102 > V_362 )
break;
}
F_55 ( & ( V_8 -> V_314 . V_318 ) ) ;
V_309 = F_56 ( V_313 ) ;
V_360 = V_309 -> V_320 ;
while ( V_309 != V_360 ) {
if ( ( V_25 - V_361 ) < V_366 ) {
V_126 = - V_367 ;
break;
}
V_23 = F_57 ( V_360 , struct V_22 , V_321 ) ;
if ( F_69 ( V_2 -> V_230 . V_288 , V_23 -> V_15 . V_67 . V_68 ) >= 0 )
V_361 = F_7 ( V_2 , V_232 , V_23 , V_361 , V_25 ) ;
V_360 = V_360 -> V_320 ;
}
F_58 ( & V_8 -> V_314 . V_318 ) ;
V_4 -> V_47 . V_49 = V_361 - V_224 ;
V_4 -> V_47 . V_48 = 0 ;
exit:
return V_126 ;
}
static int F_70 ( struct V_124 * V_125 ,
struct V_20 * V_232 ,
union V_3 * V_4 , char * V_224 )
{
struct V_1 * V_2 = (struct V_1 * ) F_24 ( V_125 ) ;
struct V_7 * V_8 = & V_2 -> V_9 ;
struct V_312 * V_313 = & V_8 -> V_314 ;
struct V_308 * V_309 ;
struct V_22 * V_23 = NULL ;
enum V_315 V_316 ;
struct V_331 V_368 ;
T_4 * V_369 , * V_370 ;
T_5 V_126 = 0 , V_342 ;
F_19 ( V_162 , V_99 ,
( L_65 , F_71 ( V_8 ) ) ) ;
if ( V_173 == F_47 ( V_2 ) ) {
V_126 = - 1 ;
goto exit;
}
if ( ! V_2 -> V_317 ) {
V_126 = - 1 ;
goto exit;
}
if ( V_4 -> V_345 . V_49 > V_344 ) {
V_126 = - V_367 ;
goto exit;
}
if ( F_21 ( V_8 , V_246 ) ) {
V_126 = - 1 ;
goto exit;
}
V_316 = V_2 -> V_129 . V_132 ;
F_25 ( L_66 , V_326 ) ;
if ( V_4 -> V_345 . V_48 && V_4 -> V_345 . V_49 ) {
V_342 = F_9 ( T_5 , V_4 -> V_345 . V_49 , V_344 ) ;
if ( V_4 -> V_345 . V_49 != 33 )
F_25 ( L_67 , V_224 , V_4 -> V_345 . V_49 ) ;
memset ( & V_368 , 0 , sizeof( struct V_331 ) ) ;
V_368 . V_51 = V_342 ;
memcpy ( V_368 . V_50 , V_224 , V_342 ) ;
V_370 = V_368 . V_50 ;
F_19 ( V_162 , V_99 , ( L_68 , V_370 ) ) ;
F_55 ( & V_313 -> V_318 ) ;
V_309 = F_56 ( V_313 ) ;
V_8 -> V_319 = V_309 -> V_320 ;
while ( V_309 != V_8 -> V_319 ) {
V_23 = F_57 ( V_8 -> V_319 , struct V_22 , V_321 ) ;
V_8 -> V_319 = V_8 -> V_319 -> V_320 ;
V_369 = V_23 -> V_15 . V_50 . V_50 ;
F_19 ( V_162 , V_99 ,
( L_69 ,
V_23 -> V_15 . V_50 . V_50 ) ) ;
if ( ( ! memcmp ( V_369 , V_370 , V_368 . V_51 ) ) &&
( V_23 -> V_15 . V_50 . V_51 == V_368 . V_51 ) ) {
F_19 ( V_162 , V_99 ,
( L_70 ) ) ;
if ( F_21 ( V_8 , V_245 ) == true ) {
if ( V_23 -> V_15 . V_322 != V_8 -> V_14 . V_15 . V_322 )
continue;
}
if ( ! F_48 ( V_2 , V_23 -> V_15 . V_322 ) ) {
V_126 = - 1 ;
F_58 ( & V_313 -> V_318 ) ;
goto exit;
}
break;
}
}
F_58 ( & V_313 -> V_318 ) ;
F_19 ( V_162 , V_99 ,
( L_71 , V_316 ) ) ;
F_59 ( V_2 , V_316 ) ;
if ( F_72 ( V_2 , & V_368 ) == false ) {
V_126 = - 1 ;
goto exit;
}
}
exit:
F_25 ( L_72 , V_326 , V_126 ) ;
return V_126 ;
}
static int F_73 ( struct V_124 * V_125 ,
struct V_20 * V_232 ,
union V_3 * V_4 , char * V_224 )
{
T_3 V_342 , V_126 = 0 ;
struct V_1 * V_2 = (struct V_1 * ) F_24 ( V_125 ) ;
struct V_7 * V_8 = & ( V_2 -> V_9 ) ;
struct V_225 * V_226 = & V_8 -> V_14 . V_15 ;
F_19 ( V_98 , V_99 , ( L_73 ) ) ;
if ( ( F_21 ( V_8 , V_114 ) ) ||
( F_21 ( V_8 , V_228 ) ) ) {
V_342 = V_226 -> V_50 . V_51 ;
V_4 -> V_345 . V_49 = V_342 ;
memcpy ( V_224 , V_226 -> V_50 . V_50 , V_342 ) ;
V_4 -> V_345 . V_48 = 1 ;
} else {
V_126 = - 1 ;
goto exit;
}
exit:
return V_126 ;
}
static int F_74 ( struct V_124 * V_125 ,
struct V_20 * V_232 ,
union V_3 * V_4 , char * V_224 )
{
int V_37 ;
T_4 V_371 [ V_372 ] ;
T_3 V_373 = V_4 -> V_87 . V_90 ;
T_3 V_88 = V_4 -> V_87 . V_88 ;
T_3 V_374 = 0 ;
T_4 V_375 [ V_372 ] = { 11 , 10 , 9 , 8 , 7 , 6 , 5 , 4 , 3 , 2 , 1 , 0 , 0xff } ;
F_19 ( V_98 , V_99 , ( L_74 ) ) ;
F_19 ( V_162 , V_99 , ( L_75 , V_373 , V_88 ) ) ;
if ( V_373 == - 1 ) {
V_374 = 11 ;
goto V_376;
}
V_373 = V_373 / 100000 ;
switch ( V_373 ) {
case 10 :
V_374 = 0 ;
break;
case 20 :
V_374 = 1 ;
break;
case 55 :
V_374 = 2 ;
break;
case 60 :
V_374 = 3 ;
break;
case 90 :
V_374 = 4 ;
break;
case 110 :
V_374 = 5 ;
break;
case 120 :
V_374 = 6 ;
break;
case 180 :
V_374 = 7 ;
break;
case 240 :
V_374 = 8 ;
break;
case 360 :
V_374 = 9 ;
break;
case 480 :
V_374 = 10 ;
break;
case 540 :
V_374 = 11 ;
break;
default:
V_374 = 11 ;
break;
}
V_376:
for ( V_37 = 0 ; V_37 < V_372 ; V_37 ++ ) {
if ( V_374 == V_375 [ V_37 ] ) {
V_371 [ V_37 ] = V_375 [ V_37 ] ;
if ( V_88 == 0 )
break;
} else {
V_371 [ V_37 ] = 0xff ;
}
F_19 ( V_162 , V_99 , ( L_76 , V_371 [ V_37 ] ) ) ;
}
return 0 ;
}
static int F_75 ( struct V_124 * V_125 ,
struct V_20 * V_21 ,
union V_3 * V_4 , char * V_224 )
{
T_1 V_34 = 0 ;
V_34 = F_76 ( (struct V_1 * ) F_24 ( V_125 ) ) ;
if ( V_34 == 0 )
return - V_236 ;
V_4 -> V_87 . V_88 = 0 ;
V_4 -> V_87 . V_90 = V_34 * 100000 ;
return 0 ;
}
static int F_77 ( struct V_124 * V_125 ,
struct V_20 * V_21 ,
union V_3 * V_4 , char * V_224 )
{
struct V_1 * V_2 = (struct V_1 * ) F_24 ( V_125 ) ;
if ( V_4 -> V_377 . V_89 ) {
V_2 -> V_378 . V_379 = 2347 ;
} else {
if ( V_4 -> V_377 . V_90 < 0 ||
V_4 -> V_377 . V_90 > 2347 )
return - V_142 ;
V_2 -> V_378 . V_379 = V_4 -> V_377 . V_90 ;
}
F_25 ( L_77 , V_326 , V_2 -> V_378 . V_379 ) ;
return 0 ;
}
static int F_78 ( struct V_124 * V_125 ,
struct V_20 * V_21 ,
union V_3 * V_4 , char * V_224 )
{
struct V_1 * V_2 = (struct V_1 * ) F_24 ( V_125 ) ;
F_25 ( L_77 , V_326 , V_2 -> V_378 . V_379 ) ;
V_4 -> V_377 . V_90 = V_2 -> V_378 . V_379 ;
V_4 -> V_377 . V_88 = 0 ;
return 0 ;
}
static int F_79 ( struct V_124 * V_125 ,
struct V_20 * V_21 ,
union V_3 * V_4 , char * V_224 )
{
struct V_1 * V_2 = (struct V_1 * ) F_24 ( V_125 ) ;
if ( V_4 -> V_380 . V_89 ) {
V_2 -> V_381 . V_382 = V_282 ;
} else {
if ( V_4 -> V_380 . V_90 < V_280 ||
V_4 -> V_380 . V_90 > V_282 )
return - V_142 ;
V_2 -> V_381 . V_382 = V_4 -> V_380 . V_90 & ~ 0x1 ;
}
F_25 ( L_78 , V_326 , V_2 -> V_381 . V_382 ) ;
return 0 ;
}
static int F_80 ( struct V_124 * V_125 ,
struct V_20 * V_21 ,
union V_3 * V_4 , char * V_224 )
{
struct V_1 * V_2 = (struct V_1 * ) F_24 ( V_125 ) ;
F_25 ( L_78 , V_326 , V_2 -> V_381 . V_382 ) ;
V_4 -> V_380 . V_90 = V_2 -> V_381 . V_382 ;
V_4 -> V_380 . V_88 = 0 ;
return 0 ;
}
static int F_81 ( struct V_124 * V_125 ,
struct V_20 * V_21 ,
union V_3 * V_4 , char * V_224 )
{
V_4 -> V_383 . V_90 = 7 ;
V_4 -> V_383 . V_88 = 0 ;
V_4 -> V_383 . V_89 = 1 ;
return 0 ;
}
static int F_82 ( struct V_124 * V_125 ,
struct V_20 * V_21 ,
union V_3 * V_4 , char * V_384 )
{
T_3 V_157 , V_126 = 0 ;
T_3 V_385 ;
struct V_149 V_386 ;
enum V_315 V_316 ;
struct V_387 * V_388 = & ( V_4 -> V_389 ) ;
struct V_1 * V_2 = (struct V_1 * ) F_24 ( V_125 ) ;
struct V_390 * V_391 = & V_2 -> V_364 ;
F_25 ( L_79 , V_388 -> V_48 ) ;
memset ( & V_386 , 0 , sizeof( struct V_149 ) ) ;
V_157 = V_388 -> V_48 & V_392 ;
if ( V_388 -> V_48 & V_85 ) {
F_25 ( L_80 ) ;
V_2 -> V_129 . V_130 = V_212 ;
V_2 -> V_129 . V_164 = V_211 ;
V_2 -> V_129 . V_166 = V_211 ;
V_2 -> V_129 . V_134 = V_140 ;
V_316 = V_139 ;
V_2 -> V_129 . V_132 = V_316 ;
goto exit;
}
if ( V_157 ) {
if ( V_157 > V_161 )
return - V_142 ;
V_157 -- ;
V_385 = 1 ;
} else {
V_385 = 0 ;
V_157 = V_2 -> V_129 . V_393 ;
F_25 ( L_81 , V_157 ) ;
}
if ( V_388 -> V_48 & V_394 ) {
F_25 ( L_82 ) ;
V_2 -> V_129 . V_130 = V_131 ;
V_2 -> V_129 . V_134 = V_140 ;
V_2 -> V_129 . V_164 = V_211 ;
V_2 -> V_129 . V_166 = V_211 ;
V_316 = V_139 ;
V_2 -> V_129 . V_132 = V_316 ;
} else if ( V_388 -> V_48 & V_395 ) {
F_25 ( L_83 ) ;
V_2 -> V_129 . V_130 = V_131 ;
V_2 -> V_129 . V_134 = V_137 ;
V_2 -> V_129 . V_164 = V_165 ;
V_2 -> V_129 . V_166 = V_165 ;
V_316 = V_136 ;
V_2 -> V_129 . V_132 = V_316 ;
} else {
F_25 ( L_84 , V_388 -> V_48 ) ;
V_2 -> V_129 . V_130 = V_131 ;
V_2 -> V_129 . V_134 = V_140 ;
V_2 -> V_129 . V_164 = V_211 ;
V_2 -> V_129 . V_166 = V_211 ;
V_316 = V_139 ;
V_2 -> V_129 . V_132 = V_316 ;
}
V_386 . V_171 = V_157 ;
if ( V_388 -> V_49 > 0 ) {
V_386 . V_168 = V_388 -> V_49 <= 5 ? 5 : 13 ;
V_386 . V_169 = V_386 . V_168 + F_27 ( struct V_149 , V_167 ) ;
} else {
V_386 . V_168 = 0 ;
if ( V_385 == 1 ) {
V_2 -> V_129 . V_393 = V_157 ;
F_25 ( L_85 , V_157 , V_2 -> V_129 . V_177 [ V_157 ] ) ;
switch ( V_2 -> V_129 . V_177 [ V_157 ] ) {
case 5 :
V_2 -> V_129 . V_164 = V_165 ;
break;
case 13 :
V_2 -> V_129 . V_164 = V_170 ;
break;
default:
V_2 -> V_129 . V_164 = V_211 ;
break;
}
goto exit;
}
}
V_386 . V_171 |= 0x80000000 ;
memcpy ( V_386 . V_167 , V_384 , V_386 . V_168 ) ;
if ( F_29 ( V_2 , & V_386 ) == false ) {
if ( V_396 == V_391 -> V_397 )
V_126 = - V_174 ;
goto exit;
}
exit:
return V_126 ;
}
static int F_83 ( struct V_124 * V_125 ,
struct V_20 * V_21 ,
union V_3 * V_4 , char * V_384 )
{
T_5 V_157 , V_126 = 0 ;
struct V_1 * V_2 = (struct V_1 * ) F_24 ( V_125 ) ;
struct V_387 * V_388 = & ( V_4 -> V_389 ) ;
struct V_7 * V_8 = & ( V_2 -> V_9 ) ;
if ( F_21 ( V_8 , V_114 ) != true ) {
if ( ! F_21 ( V_8 , V_228 ) ) {
V_388 -> V_49 = 0 ;
V_388 -> V_48 |= V_85 ;
return 0 ;
}
}
V_157 = V_388 -> V_48 & V_392 ;
if ( V_157 ) {
if ( V_157 > V_161 )
return - V_142 ;
V_157 -- ;
} else {
V_157 = V_2 -> V_129 . V_393 ;
}
V_388 -> V_48 = V_157 + 1 ;
switch ( V_2 -> V_129 . V_130 ) {
case V_398 :
case V_212 :
V_388 -> V_49 = 0 ;
V_388 -> V_48 |= V_85 ;
break;
case V_131 :
V_388 -> V_49 = V_2 -> V_129 . V_177 [ V_157 ] ;
if ( V_388 -> V_49 ) {
memcpy ( V_384 , V_2 -> V_129 . V_175 [ V_157 ] . V_176 , V_2 -> V_129 . V_177 [ V_157 ] ) ;
V_388 -> V_48 |= V_83 ;
if ( V_2 -> V_129 . V_132 == V_139 )
V_388 -> V_48 |= V_394 ;
else if ( V_2 -> V_129 . V_132 == V_136 )
V_388 -> V_48 |= V_395 ;
} else {
V_388 -> V_49 = 0 ;
V_388 -> V_48 |= V_85 ;
}
break;
case V_187 :
case V_188 :
V_388 -> V_49 = 16 ;
V_388 -> V_48 |= ( V_83 | V_394 | V_84 ) ;
break;
default:
V_388 -> V_49 = 0 ;
V_388 -> V_48 |= V_85 ;
break;
}
return V_126 ;
}
static int F_84 ( struct V_124 * V_125 ,
struct V_20 * V_21 ,
union V_3 * V_4 , char * V_224 )
{
V_4 -> V_399 . V_90 = 0 ;
V_4 -> V_399 . V_88 = 0 ;
V_4 -> V_399 . V_89 = 1 ;
return 0 ;
}
static int F_85 ( struct V_124 * V_125 ,
struct V_20 * V_21 ,
union V_3 * V_4 , char * V_224 )
{
struct V_1 * V_2 = (struct V_1 * ) F_24 ( V_125 ) ;
return F_36 ( V_2 , V_224 , V_4 -> V_47 . V_49 ) ;
}
static int F_86 ( struct V_124 * V_125 ,
struct V_20 * V_21 ,
union V_3 * V_4 , char * V_224 )
{
struct V_1 * V_2 = (struct V_1 * ) F_24 ( V_125 ) ;
struct V_400 * V_144 = (struct V_400 * ) & ( V_4 -> V_144 ) ;
int V_126 = 0 ;
switch ( V_144 -> V_48 & V_401 ) {
case V_402 :
break;
case V_403 :
break;
case V_404 :
break;
case V_405 :
break;
case V_406 :
if ( V_144 -> V_90 ) {
V_2 -> V_129 . V_407 = true ;
} else {
V_2 -> V_129 . V_407 = false ;
}
break;
case V_408 :
if ( V_2 -> V_129 . V_130 == V_131 )
break;
if ( V_144 -> V_90 ) {
V_2 -> V_129 . V_130 = V_212 ;
V_2 -> V_129 . V_164 = V_211 ;
V_2 -> V_129 . V_166 = V_211 ;
V_2 -> V_129 . V_134 = V_140 ;
V_2 -> V_129 . V_132 = V_139 ;
}
break;
case V_409 :
if ( F_21 ( & V_2 -> V_9 , V_114 ) ) {
F_87 ( V_2 ) ;
F_88 ( V_2 , 500 , false ) ;
F_25 ( L_86 , V_326 ) ;
F_89 ( V_2 ) ;
F_90 ( V_2 ) ;
}
V_126 = F_23 ( V_125 , ( T_3 ) V_144 -> V_90 ) ;
break;
case V_410 :
break;
case V_411 :
break;
case V_412 :
break;
default:
return - V_174 ;
}
return V_126 ;
}
static int F_91 ( struct V_124 * V_125 ,
struct V_20 * V_21 ,
union V_3 * V_4 , char * V_224 )
{
char * V_413 ;
T_3 V_145 ;
struct V_143 * V_144 = NULL ;
struct V_387 * V_414 = & V_4 -> V_389 ;
struct V_415 * V_416 = (struct V_415 * ) V_224 ;
int V_126 = 0 ;
V_145 = sizeof( struct V_143 ) + V_416 -> V_158 ;
V_144 = (struct V_143 * ) F_28 ( V_145 ) ;
if ( ! V_144 )
return - 1 ;
memset ( V_144 , 0 , V_145 ) ;
V_144 -> V_43 = V_417 ;
F_92 ( V_144 -> V_159 ) ;
switch ( V_416 -> V_155 ) {
case V_418 :
V_413 = L_32 ;
break;
case V_419 :
V_413 = L_25 ;
break;
case V_420 :
V_413 = L_33 ;
break;
case V_421 :
V_413 = L_87 ;
break;
default:
V_126 = - 1 ;
goto exit;
}
strncpy ( ( char * ) V_144 -> V_44 . V_153 . V_155 , V_413 , V_156 ) ;
if ( V_416 -> V_422 & V_423 )
V_144 -> V_44 . V_153 . V_172 = 1 ;
if ( ( V_416 -> V_155 != V_419 ) &&
( V_416 -> V_422 & V_424 ) )
V_144 -> V_44 . V_153 . V_172 = 0 ;
V_144 -> V_44 . V_153 . V_160 = ( V_414 -> V_48 & 0x00FF ) - 1 ;
if ( V_416 -> V_422 & V_425 )
memcpy ( V_144 -> V_44 . V_153 . V_426 , V_416 -> V_427 , 8 ) ;
if ( V_416 -> V_158 ) {
V_144 -> V_44 . V_153 . V_158 = V_416 -> V_158 ;
memcpy ( V_144 -> V_44 . V_153 . V_157 , V_416 + 1 , V_416 -> V_158 ) ;
}
V_126 = F_26 ( V_125 , V_144 , V_145 ) ;
exit:
F_35 ( V_144 ) ;
return V_126 ;
}
static int F_93 ( struct V_124 * V_125 ,
struct V_20 * V_21 ,
union V_3 * V_4 , char * V_224 )
{
if ( V_224 ) {
V_4 -> V_47 . V_49 = 14 ;
V_4 -> V_47 . V_48 = 1 ;
memcpy ( V_224 , L_88 , 14 ) ;
}
return 0 ;
}
static int F_94 ( struct V_124 * V_125 , struct V_20 * V_232 ,
union V_3 * V_4 , char * V_233 )
{
return - 1 ;
}
static int F_95 ( struct V_124 * V_125 , T_4 V_65 , T_3 V_90 )
{
T_5 V_126 = 0 ;
struct V_1 * V_2 = (struct V_1 * ) F_24 ( V_125 ) ;
switch ( V_65 ) {
case V_428 :
V_2 -> V_129 . V_134 = V_178 ;
switch ( ( V_90 ) & 0xff ) {
case 1 :
V_2 -> V_129 . V_132 = V_138 ;
V_2 -> V_129 . V_130 = V_187 ;
break;
case 2 :
V_2 -> V_129 . V_132 = V_209 ;
V_2 -> V_129 . V_130 = V_188 ;
break;
}
F_19 ( V_162 , V_99 ,
( L_89 , V_2 -> V_129 . V_132 ) ) ;
break;
case V_429 :
break;
case V_430 : {
break;
}
case V_431 :
break;
case V_432 :
V_126 = F_23 ( V_125 , V_90 ) ;
break;
case V_433 :
break;
case V_434 :
break;
default:
V_126 = - V_174 ;
break;
}
return V_126 ;
}
static int F_96 ( struct V_124 * V_125 , T_3 V_435 , T_3 V_323 )
{
int V_126 = 0 ;
struct V_1 * V_2 = (struct V_1 * ) F_24 ( V_125 ) ;
switch ( V_435 ) {
case V_436 :
if ( ! F_63 ( V_2 ) )
V_126 = - 1 ;
break;
case V_437 :
if ( ! F_63 ( V_2 ) )
V_126 = - 1 ;
break;
default:
V_126 = - V_174 ;
break;
}
return V_126 ;
}
static int F_97 ( struct V_124 * V_125 , struct V_387 * V_33 )
{
struct V_143 * V_144 ;
T_5 V_126 = 0 ;
if ( V_33 -> V_49 < sizeof( struct V_143 ) || ! V_33 -> V_438 ) {
V_126 = - V_142 ;
goto V_439;
}
V_144 = (struct V_143 * ) F_28 ( V_33 -> V_49 ) ;
if ( ! V_144 ) {
V_126 = - V_205 ;
goto V_439;
}
if ( F_98 ( V_144 , V_33 -> V_438 , V_33 -> V_49 ) ) {
F_35 ( V_144 ) ;
V_126 = - V_440 ;
goto V_439;
}
switch ( V_144 -> V_43 ) {
case V_441 :
V_126 = F_95 ( V_125 , V_144 -> V_44 . V_442 . V_65 , V_144 -> V_44 . V_442 . V_90 ) ;
break;
case V_443 :
V_126 = F_36 ( (struct V_1 * ) F_24 ( V_125 ) ,
( char * ) V_144 -> V_44 . V_94 . V_47 , ( T_1 ) V_144 -> V_44 . V_94 . V_342 ) ;
break;
case V_417 :
V_126 = F_26 ( V_125 , V_144 , V_33 -> V_49 ) ;
break;
case V_444 :
V_126 = F_96 ( V_125 , V_144 -> V_44 . V_325 . V_435 , V_144 -> V_44 . V_325 . V_327 ) ;
break;
default:
F_25 ( L_90 , V_144 -> V_43 ) ;
V_126 = - V_174 ;
break;
}
if ( V_126 == 0 && F_99 ( V_33 -> V_438 , V_144 , V_33 -> V_49 ) )
V_126 = - V_440 ;
F_35 ( V_144 ) ;
V_439:
return V_126 ;
}
static T_4 F_100 ( struct V_1 * V_2 , struct V_179 * V_180 )
{
struct V_445 * V_446 ;
struct V_447 * V_448 ;
struct V_449 * V_450 = & V_2 -> V_451 ;
T_4 V_452 = V_207 ;
V_446 = F_101 ( sizeof( struct V_445 ) , V_204 ) ;
if ( ! V_446 ) {
V_452 = V_173 ;
goto exit;
}
V_448 = F_101 ( sizeof( struct V_447 ) , V_204 ) ;
if ( ! V_448 ) {
F_35 ( V_446 ) ;
V_452 = V_173 ;
goto exit;
}
F_102 ( V_446 , V_448 , V_453 ) ;
V_448 -> V_454 = ( T_4 ) V_180 -> V_189 ;
memcpy ( V_448 -> V_455 , V_180 -> V_456 , V_17 ) ;
memcpy ( V_448 -> V_157 , & V_180 -> V_190 , 16 ) ;
V_452 = F_103 ( V_450 , V_446 ) ;
exit:
return V_452 ;
}
static int F_104 ( struct V_1 * V_2 , T_4 * V_157 , T_4 V_155 , int V_457 )
{
T_4 V_458 ;
struct V_445 * V_459 ;
struct V_460 * V_461 ;
struct V_449 * V_450 = & ( V_2 -> V_451 ) ;
int V_452 = V_207 ;
F_25 ( L_57 , V_326 ) ;
V_459 = F_101 ( sizeof( struct V_445 ) , V_204 ) ;
if ( ! V_459 ) {
V_452 = V_173 ;
goto exit;
}
V_461 = F_101 ( sizeof( struct V_460 ) , V_204 ) ;
if ( ! V_461 ) {
F_35 ( V_459 ) ;
V_452 = V_173 ;
goto exit;
}
V_461 -> V_457 = ( T_4 ) V_457 ;
V_461 -> V_454 = V_155 ;
V_461 -> V_172 = 1 ;
switch ( V_155 ) {
case V_165 :
V_458 = 5 ;
break;
case V_170 :
V_458 = 13 ;
break;
case V_215 :
case V_462 :
case V_217 :
default:
V_458 = 16 ;
}
memcpy ( & ( V_461 -> V_157 [ 0 ] ) , V_157 , V_458 ) ;
V_459 -> V_463 = V_464 ;
V_459 -> V_465 = ( T_4 * ) V_461 ;
V_459 -> V_466 = ( sizeof( struct V_460 ) ) ;
V_459 -> V_467 = NULL ;
V_459 -> V_468 = 0 ;
F_105 ( & V_459 -> V_321 ) ;
V_452 = F_103 ( V_450 , V_459 ) ;
exit:
return V_452 ;
}
static int F_106 ( struct V_1 * V_2 , T_4 * V_157 , T_4 V_458 , int V_457 )
{
T_4 V_155 ;
switch ( V_458 ) {
case 5 :
V_155 = V_165 ;
break;
case 13 :
V_155 = V_170 ;
break;
default:
V_155 = V_211 ;
}
return F_104 ( V_2 , V_157 , V_155 , V_457 ) ;
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
F_25 ( L_57 , V_326 ) ;
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
V_152 -> V_393 = V_146 ;
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
if ( ! V_180 && F_21 ( V_8 , V_246 ) ) {
if ( V_144 -> V_44 . V_153 . V_172 == 1 ) {
if ( strcmp ( V_144 -> V_44 . V_153 . V_155 , L_25 ) == 0 ) {
F_25 ( L_96 , V_326 ) ;
memcpy ( V_152 -> V_194 [ V_144 -> V_44 . V_153 . V_160 ] . V_176 ,
V_144 -> V_44 . V_153 . V_157 , F_9 ( T_1 , V_144 -> V_44 . V_153 . V_158 , 16 ) ) ;
V_152 -> V_166 = V_165 ;
if ( V_144 -> V_44 . V_153 . V_158 == 13 )
V_152 -> V_166 = V_170 ;
} else if ( strcmp ( V_144 -> V_44 . V_153 . V_155 , L_33 ) == 0 ) {
F_25 ( L_97 , V_326 ) ;
V_152 -> V_166 = V_215 ;
memcpy ( V_152 -> V_194 [ V_144 -> V_44 . V_153 . V_160 ] . V_176 ,
V_144 -> V_44 . V_153 . V_157 , F_9 ( T_1 , V_144 -> V_44 . V_153 . V_158 , 16 ) ) ;
memcpy ( V_152 -> V_195 [ V_144 -> V_44 . V_153 . V_160 ] . V_176 , & ( V_144 -> V_44 . V_153 . V_157 [ 16 ] ) , 8 ) ;
memcpy ( V_152 -> V_196 [ V_144 -> V_44 . V_153 . V_160 ] . V_176 , & ( V_144 -> V_44 . V_153 . V_157 [ 24 ] ) , 8 ) ;
V_152 -> V_193 = true ;
} else if ( strcmp ( V_144 -> V_44 . V_153 . V_155 , L_87 ) == 0 ) {
F_25 ( L_98 , V_326 ) ;
V_152 -> V_166 = V_217 ;
memcpy ( V_152 -> V_194 [ V_144 -> V_44 . V_153 . V_160 ] . V_176 ,
V_144 -> V_44 . V_153 . V_157 , F_9 ( T_1 , V_144 -> V_44 . V_153 . V_158 , 16 ) ) ;
} else {
F_25 ( L_99 , V_326 ) ;
V_152 -> V_166 = V_211 ;
}
V_152 -> V_198 = V_144 -> V_44 . V_153 . V_160 ;
V_152 -> V_197 = true ;
V_152 -> V_164 = V_152 -> V_166 ;
F_104 ( V_2 , V_144 -> V_44 . V_153 . V_157 , V_152 -> V_166 , V_144 -> V_44 . V_153 . V_160 ) ;
V_181 = F_34 ( V_2 ) ;
if ( V_181 ) {
V_181 -> V_186 = false ;
V_181 -> V_189 = V_152 -> V_166 ;
}
}
goto exit;
}
if ( V_152 -> V_134 == V_178 && V_180 ) {
if ( F_21 ( V_8 , V_246 ) ) {
if ( V_144 -> V_44 . V_153 . V_172 == 1 ) {
memcpy ( V_180 -> V_190 . V_176 , V_144 -> V_44 . V_153 . V_157 , F_9 ( T_1 , V_144 -> V_44 . V_153 . V_158 , 16 ) ) ;
if ( strcmp ( V_144 -> V_44 . V_153 . V_155 , L_25 ) == 0 ) {
F_25 ( L_100 , V_326 ) ;
V_180 -> V_189 = V_165 ;
if ( V_144 -> V_44 . V_153 . V_158 == 13 )
V_180 -> V_189 = V_170 ;
} else if ( strcmp ( V_144 -> V_44 . V_153 . V_155 , L_33 ) == 0 ) {
F_25 ( L_101 , V_326 ) ;
V_180 -> V_189 = V_215 ;
memcpy ( V_180 -> V_191 . V_176 , & ( V_144 -> V_44 . V_153 . V_157 [ 16 ] ) , 8 ) ;
memcpy ( V_180 -> V_192 . V_176 , & ( V_144 -> V_44 . V_153 . V_157 [ 24 ] ) , 8 ) ;
V_152 -> V_193 = true ;
} else if ( strcmp ( V_144 -> V_44 . V_153 . V_155 , L_87 ) == 0 ) {
F_25 ( L_102 , V_326 ) ;
V_180 -> V_189 = V_217 ;
} else {
F_25 ( L_103 , V_326 ) ;
V_180 -> V_189 = V_211 ;
}
F_100 ( V_2 , V_180 ) ;
V_180 -> V_186 = false ;
} else {
if ( strcmp ( V_144 -> V_44 . V_153 . V_155 , L_25 ) == 0 ) {
memcpy ( V_152 -> V_194 [ V_144 -> V_44 . V_153 . V_160 ] . V_176 ,
V_144 -> V_44 . V_153 . V_157 , F_9 ( T_1 , V_144 -> V_44 . V_153 . V_158 , 16 ) ) ;
V_152 -> V_166 = V_165 ;
if ( V_144 -> V_44 . V_153 . V_158 == 13 )
V_152 -> V_166 = V_170 ;
} else if ( strcmp ( V_144 -> V_44 . V_153 . V_155 , L_33 ) == 0 ) {
V_152 -> V_166 = V_215 ;
memcpy ( V_152 -> V_194 [ V_144 -> V_44 . V_153 . V_160 ] . V_176 ,
V_144 -> V_44 . V_153 . V_157 , F_9 ( T_1 , V_144 -> V_44 . V_153 . V_158 , 16 ) ) ;
memcpy ( V_152 -> V_195 [ V_144 -> V_44 . V_153 . V_160 ] . V_176 , & ( V_144 -> V_44 . V_153 . V_157 [ 16 ] ) , 8 ) ;
memcpy ( V_152 -> V_196 [ V_144 -> V_44 . V_153 . V_160 ] . V_176 , & ( V_144 -> V_44 . V_153 . V_157 [ 24 ] ) , 8 ) ;
V_152 -> V_193 = true ;
} else if ( strcmp ( V_144 -> V_44 . V_153 . V_155 , L_87 ) == 0 ) {
V_152 -> V_166 = V_217 ;
memcpy ( V_152 -> V_194 [ V_144 -> V_44 . V_153 . V_160 ] . V_176 ,
V_144 -> V_44 . V_153 . V_157 , F_9 ( T_1 , V_144 -> V_44 . V_153 . V_158 , 16 ) ) ;
} else {
V_152 -> V_166 = V_211 ;
}
V_152 -> V_198 = V_144 -> V_44 . V_153 . V_160 ;
V_152 -> V_197 = true ;
V_152 -> V_164 = V_152 -> V_166 ;
F_104 ( V_2 , V_144 -> V_44 . V_153 . V_157 , V_152 -> V_166 , V_144 -> V_44 . V_153 . V_160 ) ;
V_181 = F_34 ( V_2 ) ;
if ( V_181 ) {
V_181 -> V_186 = false ;
V_181 -> V_189 = V_152 -> V_166 ;
}
}
}
}
exit:
F_35 ( V_150 ) ;
return V_126 ;
}
static int F_108 ( struct V_124 * V_125 , struct V_143 * V_144 , int V_342 )
{
int V_126 = 0 ;
struct V_1 * V_2 = (struct V_1 * ) F_24 ( V_125 ) ;
struct V_7 * V_8 = & ( V_2 -> V_9 ) ;
struct V_182 * V_183 = & V_2 -> V_184 ;
unsigned char * V_469 = V_144 -> V_44 . V_470 . V_92 ;
F_25 ( L_104 , V_326 , V_342 ) ;
if ( F_21 ( V_8 , V_246 ) != true )
return - V_142 ;
memcpy ( & V_183 -> V_471 , V_144 -> V_44 . V_470 . V_472 , 2 ) ;
if ( ( V_183 -> V_471 > V_473 ) || ( V_183 -> V_471 <= 0 ) )
V_183 -> V_471 = V_473 ;
if ( F_109 ( V_2 , V_469 , ( V_342 - 12 - 2 ) ) == V_207 )
V_126 = 0 ;
else
V_126 = - V_142 ;
return V_126 ;
}
static int F_110 ( struct V_124 * V_125 )
{
struct V_1 * V_2 = (struct V_1 * ) F_24 ( V_125 ) ;
F_25 ( L_57 , V_326 ) ;
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
F_25 ( L_105 , V_144 -> V_44 . V_474 . V_475 , ( V_144 -> V_159 ) ) ;
if ( ! F_21 ( V_8 , ( V_114 | V_246 ) ) )
return - V_142 ;
if ( V_144 -> V_159 [ 0 ] == 0xff && V_144 -> V_159 [ 1 ] == 0xff &&
V_144 -> V_159 [ 2 ] == 0xff && V_144 -> V_159 [ 3 ] == 0xff &&
V_144 -> V_159 [ 4 ] == 0xff && V_144 -> V_159 [ 5 ] == 0xff )
return - V_142 ;
V_180 = F_31 ( V_183 , V_144 -> V_159 ) ;
if ( V_180 ) {
int V_48 = V_144 -> V_44 . V_474 . V_48 ;
V_180 -> V_475 = V_144 -> V_44 . V_474 . V_475 ;
memcpy ( V_180 -> V_476 , V_144 -> V_44 . V_474 . V_477 , 16 ) ;
if ( V_478 & V_48 )
V_180 -> V_479 = 1 ;
else
V_180 -> V_479 = 0 ;
if ( V_8 -> V_480 . V_479 == 0 )
V_180 -> V_479 = 0 ;
if ( V_481 & V_48 ) {
V_180 -> V_482 . V_483 = true ;
V_180 -> V_479 = 1 ;
memcpy ( & V_180 -> V_482 . V_36 , & V_144 -> V_44 . V_474 . V_36 ,
sizeof( struct V_55 ) ) ;
} else {
V_180 -> V_482 . V_483 = false ;
}
if ( V_8 -> V_482 . V_483 == false )
V_180 -> V_482 . V_483 = false ;
F_114 ( V_2 , V_180 ) ;
} else {
V_126 = - V_205 ;
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
if ( F_21 ( V_8 , ( V_114 | V_246 ) ) != true )
return - V_142 ;
if ( V_144 -> V_159 [ 0 ] == 0xff && V_144 -> V_159 [ 1 ] == 0xff &&
V_144 -> V_159 [ 2 ] == 0xff && V_144 -> V_159 [ 3 ] == 0xff &&
V_144 -> V_159 [ 4 ] == 0xff && V_144 -> V_159 [ 5 ] == 0xff )
return - V_142 ;
V_180 = F_31 ( V_183 , V_144 -> V_159 ) ;
if ( V_180 ) {
F_55 ( & V_183 -> V_484 ) ;
if ( ! F_116 ( & V_180 -> V_485 ) ) {
F_117 ( & V_180 -> V_485 ) ;
V_183 -> V_486 -- ;
V_110 = F_118 ( V_2 , V_180 , true , V_487 ) ;
}
F_58 ( & V_183 -> V_484 ) ;
F_119 ( V_2 , V_110 ) ;
V_180 = NULL ;
} else {
F_25 ( L_107 ) ;
}
return V_126 ;
}
static int F_120 ( struct V_124 * V_125 , struct V_143 * V_144 , int V_342 )
{
int V_126 = 0 ;
struct V_179 * V_180 = NULL ;
struct V_1 * V_2 = (struct V_1 * ) F_24 ( V_125 ) ;
struct V_7 * V_8 = & ( V_2 -> V_9 ) ;
struct V_182 * V_183 = & V_2 -> V_184 ;
struct V_488 * V_489 = (struct V_488 * ) V_144 ;
struct V_490 * V_491 = (struct V_490 * ) V_489 -> V_47 ;
F_25 ( L_108 , ( V_489 -> V_159 ) ) ;
if ( F_21 ( V_8 , ( V_114 | V_246 ) ) != true )
return - V_142 ;
if ( V_489 -> V_159 [ 0 ] == 0xff && V_489 -> V_159 [ 1 ] == 0xff &&
V_489 -> V_159 [ 2 ] == 0xff && V_489 -> V_159 [ 3 ] == 0xff &&
V_489 -> V_159 [ 4 ] == 0xff && V_489 -> V_159 [ 5 ] == 0xff )
return - V_142 ;
V_180 = F_31 ( V_183 , V_489 -> V_159 ) ;
if ( V_180 ) {
V_491 -> V_475 = ( T_1 ) V_180 -> V_475 ;
V_491 -> V_492 = V_180 -> V_492 ;
V_491 -> V_48 = V_180 -> V_48 ;
V_491 -> V_493 = ( ( V_180 -> V_494 ) |
( V_180 -> V_495 << 1 ) |
( V_180 -> V_496 << 2 ) |
( V_180 -> V_497 << 3 ) |
( V_180 -> V_498 << 4 ) |
( V_180 -> V_499 << 5 ) ) ;
V_491 -> V_500 = V_180 -> V_501 ;
memcpy ( V_491 -> V_477 , V_180 -> V_476 , V_180 -> V_501 ) ;
memcpy ( & V_491 -> V_36 ,
& V_180 -> V_482 . V_36 , sizeof( struct V_55 ) ) ;
V_491 -> V_502 = V_180 -> V_503 . V_504 ;
V_491 -> V_505 = V_180 -> V_503 . V_505 ;
V_491 -> V_506 = V_180 -> V_503 . V_506 ;
V_491 -> V_507 = V_180 -> V_503 . V_507 ;
V_491 -> V_508 = V_180 -> V_503 . V_508 ;
V_491 -> V_509 = V_180 -> V_503 . V_509 ;
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
if ( F_21 ( V_8 , ( V_114 | V_246 ) ) != true )
return - V_142 ;
if ( V_144 -> V_159 [ 0 ] == 0xff && V_144 -> V_159 [ 1 ] == 0xff &&
V_144 -> V_159 [ 2 ] == 0xff && V_144 -> V_159 [ 3 ] == 0xff &&
V_144 -> V_159 [ 4 ] == 0xff && V_144 -> V_159 [ 5 ] == 0xff )
return - V_142 ;
V_180 = F_31 ( V_183 , V_144 -> V_159 ) ;
if ( V_180 ) {
if ( V_180 -> V_94 [ 0 ] == V_510 ||
V_180 -> V_94 [ 0 ] == V_511 ) {
int V_512 ;
int V_513 ;
V_512 = V_180 -> V_94 [ 1 ] ;
V_513 = F_9 ( int , V_512 + 2 , sizeof( V_180 -> V_94 ) ) ;
V_144 -> V_44 . V_94 . V_342 = V_513 ;
memcpy ( V_144 -> V_44 . V_94 . V_472 , V_180 -> V_94 , V_513 ) ;
} else {
F_25 ( L_110 ) ;
}
} else {
V_126 = - 1 ;
}
return V_126 ;
}
static int F_122 ( struct V_124 * V_125 , struct V_143 * V_144 , int V_342 )
{
int V_126 = 0 ;
unsigned char V_220 [ 4 ] = { 0x0 , 0x50 , 0xf2 , 0x04 } ;
struct V_1 * V_2 = (struct V_1 * ) F_24 ( V_125 ) ;
struct V_7 * V_8 = & ( V_2 -> V_9 ) ;
struct V_269 * V_270 = & ( V_2 -> V_230 ) ;
int V_514 ;
F_25 ( L_104 , V_326 , V_342 ) ;
if ( F_21 ( V_8 , V_246 ) != true )
return - V_142 ;
V_514 = V_342 - 12 - 2 ;
F_35 ( V_8 -> V_515 ) ;
V_8 -> V_515 = NULL ;
if ( V_514 > 0 ) {
V_8 -> V_515 = F_28 ( V_514 ) ;
V_8 -> V_516 = V_514 ;
if ( ! V_8 -> V_515 ) {
F_25 ( L_111 , V_326 , __LINE__ ) ;
return - V_142 ;
}
memcpy ( V_8 -> V_515 , V_144 -> V_44 . V_470 . V_92 , V_514 ) ;
F_123 ( V_2 , V_221 , V_220 , true ) ;
V_270 -> V_517 = true ;
}
return V_126 ;
}
static int F_124 ( struct V_124 * V_125 , struct V_143 * V_144 , int V_342 )
{
int V_126 = 0 ;
struct V_1 * V_2 = (struct V_1 * ) F_24 ( V_125 ) ;
struct V_7 * V_8 = & ( V_2 -> V_9 ) ;
int V_514 ;
F_25 ( L_104 , V_326 , V_342 ) ;
if ( F_21 ( V_8 , V_246 ) != true )
return - V_142 ;
V_514 = V_342 - 12 - 2 ;
F_35 ( V_8 -> V_518 ) ;
V_8 -> V_518 = NULL ;
if ( V_514 > 0 ) {
V_8 -> V_518 = F_28 ( V_514 ) ;
V_8 -> V_519 = V_514 ;
if ( ! V_8 -> V_518 ) {
F_25 ( L_111 , V_326 , __LINE__ ) ;
return - V_142 ;
}
memcpy ( V_8 -> V_518 , V_144 -> V_44 . V_470 . V_92 , V_514 ) ;
}
return V_126 ;
}
static int F_125 ( struct V_124 * V_125 , struct V_143 * V_144 , int V_342 )
{
int V_126 = 0 ;
struct V_1 * V_2 = (struct V_1 * ) F_24 ( V_125 ) ;
struct V_7 * V_8 = & ( V_2 -> V_9 ) ;
int V_514 ;
F_25 ( L_104 , V_326 , V_342 ) ;
if ( F_21 ( V_8 , V_246 ) != true )
return - V_142 ;
V_514 = V_342 - 12 - 2 ;
F_35 ( V_8 -> V_520 ) ;
V_8 -> V_520 = NULL ;
if ( V_514 > 0 ) {
V_8 -> V_520 = F_28 ( V_514 ) ;
V_8 -> V_521 = V_514 ;
if ( ! V_8 -> V_520 ) {
F_25 ( L_111 , V_326 , __LINE__ ) ;
return - V_142 ;
}
memcpy ( V_8 -> V_520 , V_144 -> V_44 . V_470 . V_92 , V_514 ) ;
}
return V_126 ;
}
static int F_126 ( struct V_124 * V_125 , struct V_143 * V_144 , int V_342 )
{
int V_126 = 0 ;
struct V_1 * V_2 = (struct V_1 * ) F_24 ( V_125 ) ;
struct V_7 * V_8 = & ( V_2 -> V_9 ) ;
struct V_269 * V_270 = & ( V_2 -> V_230 ) ;
struct V_522 * V_523 = & ( V_270 -> V_524 ) ;
T_4 V_90 ;
if ( F_21 ( V_8 , V_246 ) != true )
return - V_142 ;
if ( V_144 -> V_44 . V_442 . V_65 != 0 )
F_25 ( L_112 , V_326 , V_144 -> V_44 . V_442 . V_65 ) ;
V_90 = V_144 -> V_44 . V_442 . V_90 ;
if ( V_90 != 1 && V_90 != 2 )
V_90 = 0 ;
F_25 ( L_113 , V_326 , V_90 ) ;
V_523 -> V_525 = V_90 ;
return V_126 ;
}
static int F_127 ( struct V_124 * V_125 , struct V_143 * V_144 , int V_342 )
{
struct V_1 * V_2 = (struct V_1 * ) F_24 ( V_125 ) ;
struct V_7 * V_8 = & ( V_2 -> V_9 ) ;
if ( F_21 ( V_8 , V_246 ) != true )
return - V_142 ;
if ( V_144 -> V_159 [ 0 ] == 0xff && V_144 -> V_159 [ 1 ] == 0xff &&
V_144 -> V_159 [ 2 ] == 0xff && V_144 -> V_159 [ 3 ] == 0xff &&
V_144 -> V_159 [ 4 ] == 0xff && V_144 -> V_159 [ 5 ] == 0xff )
return - V_142 ;
return F_128 ( V_2 , V_144 -> V_159 ) ;
}
static int F_129 ( struct V_124 * V_125 , struct V_143 * V_144 , int V_342 )
{
struct V_1 * V_2 = (struct V_1 * ) F_24 ( V_125 ) ;
struct V_7 * V_8 = & ( V_2 -> V_9 ) ;
if ( F_21 ( V_8 , V_246 ) != true )
return - V_142 ;
if ( V_144 -> V_159 [ 0 ] == 0xff && V_144 -> V_159 [ 1 ] == 0xff &&
V_144 -> V_159 [ 2 ] == 0xff && V_144 -> V_159 [ 3 ] == 0xff &&
V_144 -> V_159 [ 4 ] == 0xff && V_144 -> V_159 [ 5 ] == 0xff )
return - V_142 ;
return F_130 ( V_2 , V_144 -> V_159 ) ;
}
static int F_131 ( struct V_124 * V_125 , struct V_143 * V_144 , int V_342 )
{
int V_126 = 0 ;
struct V_1 * V_2 = (struct V_1 * ) F_24 ( V_125 ) ;
struct V_7 * V_8 = & ( V_2 -> V_9 ) ;
if ( F_21 ( V_8 , V_246 ) != true )
return - V_142 ;
F_132 ( V_2 , V_144 -> V_44 . V_325 . V_435 ) ;
return V_126 ;
}
static int F_133 ( struct V_124 * V_125 , struct V_387 * V_33 )
{
struct V_143 * V_144 ;
int V_126 = 0 ;
struct V_1 * V_2 = (struct V_1 * ) F_24 ( V_125 ) ;
if ( ! V_2 -> V_237 ) {
V_126 = - V_236 ;
goto V_439;
}
if ( ! V_33 -> V_438 ) {
V_126 = - V_142 ;
goto V_439;
}
V_144 = (struct V_143 * ) F_28 ( V_33 -> V_49 ) ;
if ( ! V_144 ) {
V_126 = - V_205 ;
goto V_439;
}
if ( F_98 ( V_144 , V_33 -> V_438 , V_33 -> V_49 ) ) {
F_35 ( V_144 ) ;
V_126 = - V_440 ;
goto V_439;
}
switch ( V_144 -> V_43 ) {
case V_526 :
V_126 = F_110 ( V_125 ) ;
break;
case V_527 :
V_126 = F_113 ( V_125 , V_144 ) ;
break;
case V_528 :
V_126 = F_115 ( V_125 , V_144 ) ;
break;
case V_529 :
V_126 = F_108 ( V_125 , V_144 , V_33 -> V_49 ) ;
break;
case V_530 :
V_126 = F_107 ( V_125 , V_144 , V_33 -> V_49 ) ;
break;
case V_531 :
V_126 = F_121 ( V_125 , V_144 ) ;
break;
case V_532 :
V_126 = F_122 ( V_125 , V_144 , V_33 -> V_49 ) ;
break;
case V_533 :
V_126 = F_124 ( V_125 , V_144 , V_33 -> V_49 ) ;
break;
case V_534 :
V_126 = F_125 ( V_125 , V_144 , V_33 -> V_49 ) ;
break;
case V_535 :
V_126 = F_126 ( V_125 , V_144 , V_33 -> V_49 ) ;
break;
case V_536 :
V_126 = F_120 ( V_125 , V_144 , V_33 -> V_49 ) ;
break;
case V_537 :
V_126 = F_131 ( V_125 , V_144 , V_33 -> V_49 ) ;
break;
case V_538 :
V_126 = F_129 ( V_125 , V_144 , V_33 -> V_49 ) ;
break;
case V_539 :
V_126 = F_127 ( V_125 , V_144 , V_33 -> V_49 ) ;
break;
default:
F_25 ( L_114 , V_144 -> V_43 ) ;
V_126 = - V_174 ;
break;
}
if ( V_126 == 0 && F_99 ( V_33 -> V_438 , V_144 , V_33 -> V_49 ) )
V_126 = - V_440 ;
F_35 ( V_144 ) ;
V_439:
return V_126 ;
}
static int F_134 ( struct V_124 * V_125 ,
struct V_20 * V_21 ,
union V_3 * V_305 ,
char * V_224 )
{
int V_126 = 0 ;
int V_342 = 0 ;
char * V_540 ;
struct V_1 * V_2 = (struct V_1 * ) F_24 ( V_125 ) ;
struct V_387 * V_541 = (struct V_387 * ) V_305 ;
if ( V_541 -> V_49 == 0 )
return - V_440 ;
V_342 = V_541 -> V_49 ;
V_540 = F_135 ( V_342 ) ;
if ( ! V_540 )
return - V_205 ;
if ( F_98 ( V_540 , V_541 -> V_438 , V_342 ) ) {
F_136 ( V_540 ) ;
return - V_440 ;
}
if ( V_541 -> V_48 == 0x8766 && V_342 > 8 ) {
T_3 V_542 ;
struct V_7 * V_8 = & ( V_2 -> V_9 ) ;
T_4 * V_543 = V_540 ;
int V_544 = V_342 ;
T_4 V_220 [ 4 ] = { 0x0 , 0x50 , 0xf2 , 0x04 } ;
if ( ( V_221 == V_543 [ 0 ] ) &&
( ! memcmp ( & V_543 [ 2 ] , V_220 , 4 ) ) ) {
V_542 = F_41 ( V_544 , V_545 ) ;
V_8 -> V_546 = 0 ;
F_35 ( V_8 -> V_547 ) ;
V_8 -> V_547 = NULL ;
V_8 -> V_547 = F_28 ( V_542 ) ;
if ( ! V_8 -> V_547 ) {
F_137 ( L_111 , V_326 , __LINE__ ) ;
V_126 = - V_142 ;
goto V_548;
}
memcpy ( V_8 -> V_547 , V_543 , V_542 ) ;
V_8 -> V_546 = V_542 ;
}
goto V_548;
}
if ( V_342 >= V_348 &&
! memcmp ( V_540 , V_349 , V_348 ) ) {
V_126 = F_64 ( V_125 , V_21 , V_305 , V_540 ) ;
goto V_548;
}
V_548:
F_136 ( V_540 ) ;
return V_126 ;
}
static struct V_549 * F_138 ( struct V_124 * V_125 )
{
struct V_1 * V_2 = (struct V_1 * ) F_24 ( V_125 ) ;
struct V_549 * V_550 = & V_2 -> V_551 ;
int V_552 = 0 ;
int V_553 = 0 ;
int V_554 = 0 ;
if ( ! F_21 ( & V_2 -> V_9 , V_114 ) ) {
V_550 -> V_109 . V_109 = 0 ;
V_550 -> V_109 . V_121 = 0 ;
V_550 -> V_109 . V_122 = 0 ;
} else {
V_552 = V_2 -> V_115 . V_116 ;
V_553 = V_2 -> V_115 . V_117 ;
V_554 = V_2 -> V_115 . V_122 ;
V_550 -> V_109 . V_121 = V_552 ;
V_550 -> V_109 . V_109 = V_553 ;
V_550 -> V_109 . V_122 = V_554 ;
}
V_550 -> V_109 . V_110 = V_555 ;
return & V_2 -> V_551 ;
}
int F_139 ( struct V_124 * V_125 , struct V_556 * V_557 , int V_43 )
{
struct V_558 * V_559 = (struct V_558 * ) V_557 ;
int V_126 = 0 ;
switch ( V_43 ) {
case V_560 :
V_126 = F_97 ( V_125 , & V_559 -> V_44 . V_47 ) ;
break;
#ifdef F_140
case V_561 :
V_126 = F_133 ( V_125 , & V_559 -> V_44 . V_47 ) ;
break;
#endif
case ( V_562 + 1 ) :
V_126 = F_141 ( V_125 , V_557 , V_43 ) ;
break;
default:
V_126 = - V_174 ;
break;
}
return V_126 ;
}
