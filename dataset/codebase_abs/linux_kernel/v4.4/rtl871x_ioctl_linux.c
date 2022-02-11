void F_1 ( struct V_1 * V_2 )
{
union V_3 V_4 ;
struct V_5 * V_6 = & V_2 -> V_7 ;
V_4 . V_8 . V_9 = V_10 ;
memcpy ( V_4 . V_8 . V_11 , V_6 -> V_12 . V_13 . V_14 ,
V_15 ) ;
F_2 ( V_2 -> V_16 , V_17 , & V_4 , NULL ) ;
}
void F_3 ( struct V_1 * V_2 )
{
union V_3 V_4 ;
V_4 . V_8 . V_9 = V_10 ;
F_4 ( V_4 . V_8 . V_11 ) ;
F_2 ( V_2 -> V_16 , V_17 , & V_4 , NULL ) ;
}
static inline void F_5 ( struct V_18 * V_19 ,
struct V_20 * V_21 ,
struct V_1 * V_2 )
{
memcpy ( V_19 -> V_22 . V_23 , V_21 -> V_24 . V_25 . V_26 ,
( V_21 -> V_24 . V_25 . V_27 > 16 ? 16 : V_21 -> V_24 . V_25 . V_27 ) ) ;
if ( strcmp ( V_21 -> V_24 . V_25 . V_28 , L_1 ) == 0 ) {
memcpy ( V_19 -> V_29 . V_23 , & ( V_21 -> V_24 . V_25 .
V_26 [ 16 ] ) , 8 ) ;
memcpy ( V_19 -> V_30 . V_23 , & ( V_21 -> V_24 . V_25 .
V_26 [ 24 ] ) , 8 ) ;
V_2 -> V_31 . V_32 = false ;
F_6 ( & V_2 -> V_31 . V_33 ,
V_34 + F_7 ( 50 ) ) ;
}
F_8 ( V_2 , ( unsigned char * ) V_19 , true ) ;
}
static inline void F_9 ( struct V_20 * V_21 ,
struct V_1 * V_2 )
{
if ( V_21 -> V_24 . V_25 . V_35 > 0 &&
V_21 -> V_24 . V_25 . V_35 < 3 ) {
memcpy ( V_2 -> V_31 . V_36 [ V_21 -> V_24 . V_25 .
V_35 - 1 ] . V_23 , V_21 -> V_24 . V_25 . V_26 ,
( V_21 -> V_24 . V_25 . V_27 > 16 ? 16 :
V_21 -> V_24 . V_25 . V_27 ) ) ;
memcpy ( V_2 -> V_31 . V_37 [ V_21 ->
V_24 . V_25 . V_35 - 1 ] . V_23 , & ( V_21 -> V_24 . V_25 . V_26 [ 16 ] ) , 8 ) ;
memcpy ( V_2 -> V_31 . V_38 [ V_21 ->
V_24 . V_25 . V_35 - 1 ] . V_23 , & ( V_21 -> V_24 . V_25 . V_26 [ 24 ] ) , 8 ) ;
V_2 -> V_31 . V_39 = true ;
F_10 ( V_2 , & V_2 -> V_31 ,
V_21 -> V_24 . V_25 . V_35 ) ;
if ( V_2 -> V_40 . V_41 > V_42 ) {
if ( V_2 -> V_40 . V_41 != V_2 ->
V_43 . V_44 )
F_6 ( & V_2 -> V_7 . V_45 ,
V_34 + F_7 ( 60000 ) ) ;
}
}
}
static inline char * F_11 ( struct V_1 * V_2 ,
struct V_46 * V_47 ,
struct V_48 * V_49 ,
char * V_50 , char * V_51 )
{
struct V_52 V_53 ;
struct V_54 * V_55 ;
char * V_56 ;
T_1 * V_57 ;
T_2 V_58 = 0 , V_59 = 0 ;
T_3 V_60 , V_61 = false , V_62 ;
T_4 V_63 ;
if ( ( V_49 -> V_13 . V_64 . V_65 < 1 ) ||
( V_49 -> V_13 . V_64 . V_65 > 14 ) ) {
if ( V_49 -> V_13 . V_64 . V_65 < 1 )
V_49 -> V_13 . V_64 . V_65 = 1 ;
else
V_49 -> V_13 . V_64 . V_65 = 14 ;
}
V_53 . V_66 = V_17 ;
V_53 . V_24 . V_8 . V_9 = V_10 ;
F_12 ( V_53 . V_24 . V_8 . V_11 , V_49 -> V_13 . V_14 ) ;
V_50 = F_13 ( V_47 , V_50 , V_51 , & V_53 , V_67 ) ;
V_53 . V_66 = V_68 ;
V_53 . V_24 . V_69 . V_70 = 1 ;
V_53 . V_24 . V_69 . V_71 = F_14 ( T_2 , V_49 -> V_13 . V_72 . V_73 , 32 ) ;
V_50 = F_15 ( V_47 , V_50 , V_51 , & V_53 ,
V_49 -> V_13 . V_72 . V_72 ) ;
V_57 = F_16 ( & V_49 -> V_13 . V_74 [ 12 ] , V_75 ,
& V_59 , V_49 -> V_13 . V_76 - 12 ) ;
if ( V_57 && V_59 > 0 ) {
V_61 = true ;
V_55 = (struct V_54 * ) ( V_57 + 2 ) ;
memcpy ( & V_62 , V_55 -> V_77 , 2 ) ;
}
V_53 . V_66 = V_78 ;
if ( F_17 ( V_49 -> V_13 . V_79 ) ) {
if ( V_61 )
snprintf ( V_53 . V_24 . V_80 , V_81 , L_2 ) ;
else
snprintf ( V_53 . V_24 . V_80 , V_81 , L_3 ) ;
} else if ( F_18 ( V_49 -> V_13 . V_79 ) ) {
if ( V_61 )
snprintf ( V_53 . V_24 . V_80 , V_81 , L_4 ) ;
else
snprintf ( V_53 . V_24 . V_80 , V_81 , L_5 ) ;
} else {
if ( V_61 )
snprintf ( V_53 . V_24 . V_80 , V_81 , L_6 ) ;
else
snprintf ( V_53 . V_24 . V_80 , V_81 , L_7 ) ;
}
V_50 = F_13 ( V_47 , V_50 , V_51 , & V_53 , V_82 ) ;
V_53 . V_66 = V_83 ;
memcpy ( ( T_4 * ) & V_60 , F_19 ( V_49 -> V_13 . V_74 ) ,
2 ) ;
V_60 = F_20 ( V_60 ) ;
if ( V_60 & ( V_84 | V_85 ) ) {
if ( V_60 & V_85 )
V_53 . V_24 . V_86 = ( T_2 ) V_87 ;
else
V_53 . V_24 . V_86 = ( T_2 ) V_88 ;
V_50 = F_13 ( V_47 , V_50 , V_51 , & V_53 ,
V_89 ) ;
}
V_53 . V_66 = V_90 ;
{
T_4 V_91 = V_49 -> V_13 . V_64 . V_65 ;
if ( V_91 >= 1 && V_91 <= sizeof(
V_92 ) / sizeof( long ) )
V_53 . V_24 . V_93 . V_94 = ( V_95 ) ( V_92 [
V_49 -> V_13 . V_64 .
V_65 - 1 ] * 100000 ) ;
else
V_53 . V_24 . V_93 . V_94 = 0 ;
}
V_53 . V_24 . V_93 . V_96 = ( V_97 ) 1 ;
V_53 . V_24 . V_93 . V_58 = ( T_4 ) V_49 -> V_13 . V_64 . V_65 ;
V_50 = F_13 ( V_47 , V_50 , V_51 , & V_53 ,
V_98 ) ;
V_53 . V_66 = V_99 ;
if ( V_60 & V_100 )
V_53 . V_24 . V_69 . V_70 = ( T_3 ) ( V_101 |
V_102 ) ;
else
V_53 . V_24 . V_69 . V_70 = ( T_3 ) ( V_103 ) ;
V_53 . V_24 . V_69 . V_71 = ( T_3 ) 0 ;
V_50 = F_15 ( V_47 , V_50 , V_51 , & V_53 ,
V_49 -> V_13 . V_72 . V_72 ) ;
V_56 = V_50 + F_21 ( V_47 ) ;
V_53 . V_66 = V_104 ;
V_53 . V_24 . V_105 . V_106 = 0 ;
V_53 . V_24 . V_105 . V_107 = 0 ;
V_53 . V_24 . V_105 . V_108 = 0 ;
V_58 = 0 ;
while ( V_49 -> V_13 . V_79 [ V_58 ] != 0 ) {
V_53 . V_24 . V_105 . V_108 = ( V_49 -> V_13 . V_79 [ V_58 ++ ] &
0x7F ) * 500000 ;
V_56 = F_22 ( V_47 , V_50 , V_56 ,
V_51 , & V_53 , V_109 ) ;
}
if ( ( V_56 - V_50 ) > F_21 ( V_47 ) )
V_50 = V_56 ;
{
T_4 V_110 [ V_111 ] ;
T_4 V_112 [ 255 ] , V_113 [ 255 ] ;
T_3 V_114 = 0 , V_115 = 0 ;
int V_116 ;
F_23 ( V_49 -> V_13 . V_74 ,
V_49 -> V_13 . V_76 , V_113 , & V_115 ,
V_112 , & V_114 ) ;
if ( V_114 > 0 ) {
memset ( V_110 , 0 , V_111 ) ;
V_116 = sprintf ( V_110 , L_8 ) ;
for ( V_58 = 0 ; V_58 < V_114 ; V_58 ++ ) {
V_116 += snprintf ( V_110 + V_116 , V_111 - V_116 ,
L_9 , V_112 [ V_58 ] ) ;
if ( V_116 >= V_111 )
break;
}
memset ( & V_53 , 0 , sizeof( V_53 ) ) ;
V_53 . V_66 = V_117 ;
V_53 . V_24 . V_69 . V_71 = ( T_3 ) strlen ( V_110 ) ;
V_50 = F_15 ( V_47 , V_50 , V_51 ,
& V_53 , V_110 ) ;
memset ( & V_53 , 0 , sizeof( V_53 ) ) ;
V_53 . V_66 = V_118 ;
V_53 . V_24 . V_69 . V_71 = ( T_3 ) V_114 ;
V_50 = F_15 ( V_47 , V_50 , V_51 ,
& V_53 , V_112 ) ;
}
if ( V_115 > 0 ) {
memset ( V_110 , 0 , V_111 ) ;
V_116 = sprintf ( V_110 , L_10 ) ;
for ( V_58 = 0 ; V_58 < V_115 ; V_58 ++ ) {
V_116 += snprintf ( V_110 + V_116 , V_111 - V_116 ,
L_9 , V_113 [ V_58 ] ) ;
if ( V_116 >= V_111 )
break;
}
memset ( & V_53 , 0 , sizeof( V_53 ) ) ;
V_53 . V_66 = V_117 ;
V_53 . V_24 . V_69 . V_71 = strlen ( V_110 ) ;
V_50 = F_15 ( V_47 , V_50 , V_51 ,
& V_53 , V_110 ) ;
memset ( & V_53 , 0 , sizeof( V_53 ) ) ;
V_53 . V_66 = V_118 ;
V_53 . V_24 . V_69 . V_71 = V_115 ;
V_50 = F_15 ( V_47 , V_50 , V_51 , & V_53 ,
V_113 ) ;
}
}
{
T_4 V_119 [ 512 ] ;
T_5 V_120 ;
if ( F_24 ( V_49 -> V_13 . V_74 ,
V_49 -> V_13 . V_76 ,
V_119 , & V_120 ) ) {
if ( V_120 > 2 ) {
V_53 . V_66 = V_118 ;
V_53 . V_24 . V_69 . V_71 = ( T_3 ) V_120 ;
V_50 = F_15 ( V_47 , V_50 , V_51 ,
& V_53 , V_119 ) ;
}
}
}
V_53 . V_66 = V_121 ;
V_63 = F_25 ( V_49 -> V_13 . V_122 ) ;
V_53 . V_24 . V_123 . V_124 = ( T_4 ) ( V_125 | V_126 |
V_127 ) ;
V_53 . V_24 . V_123 . V_128 = V_63 ;
V_53 . V_24 . V_123 . V_123 = 0 ;
V_53 . V_24 . V_123 . V_129 = 0 ;
V_50 = F_13 ( V_47 , V_50 , V_51 , & V_53 , V_130 ) ;
return V_50 ;
}
static int F_26 ( struct V_131 * V_132 , T_2 V_108 )
{
struct V_1 * V_2 = F_27 ( V_132 ) ;
int V_133 = 0 ;
if ( ( V_108 & V_134 ) && ( V_108 & V_135 ) ) {
V_2 -> V_31 . V_136 =
V_137 ;
V_2 -> V_31 . V_138 =
V_139 ;
V_2 -> V_31 . V_140 = 3 ;
} else if ( V_108 & V_134 ) {
V_2 -> V_31 . V_136 =
V_137 ;
V_2 -> V_31 . V_138 = V_141 ;
V_2 -> V_31 . V_140 = 1 ;
} else if ( V_108 & V_135 ) {
if ( V_2 -> V_31 . V_138 <
V_142 ) {
V_2 -> V_31 . V_138 =
V_143 ;
V_2 -> V_31 . V_140 = 0 ;
}
} else {
V_133 = - V_144 ;
}
return V_133 ;
}
static int F_28 ( struct V_131 * V_132 , struct V_20 * V_21 ,
T_2 V_145 )
{
int V_133 = 0 ;
T_2 V_146 , V_147 = 0 ;
struct V_148 * V_149 = NULL ;
struct V_1 * V_2 = F_27 ( V_132 ) ;
struct V_5 * V_6 = & V_2 -> V_7 ;
struct V_150 * V_151 = & V_2 -> V_31 ;
V_21 -> V_24 . V_25 . V_152 = 0 ;
V_21 -> V_24 . V_25 . V_28 [ V_153 - 1 ] = '\0' ;
if ( V_145 != ( T_2 ) ( ( T_4 * ) V_21 -> V_24 . V_25 . V_26 - ( T_4 * ) V_21 ) +
V_21 -> V_24 . V_25 . V_27 )
return - V_144 ;
if ( F_29 ( V_21 -> V_154 ) ) {
if ( V_21 -> V_24 . V_25 . V_35 >= V_155 ) {
V_21 -> V_24 . V_25 . V_35 = 0 ;
}
} else {
return - V_144 ;
}
if ( strcmp ( V_21 -> V_24 . V_25 . V_28 , L_11 ) == 0 ) {
F_30 ( V_132 , L_12 , V_156 ) ;
V_2 -> V_31 . V_136 =
V_137 ;
V_2 -> V_31 . V_157 = V_158 ;
V_2 -> V_31 . V_159 = V_158 ;
V_146 = V_21 -> V_24 . V_25 . V_35 ;
V_147 = V_21 -> V_24 . V_25 . V_27 ;
if ( V_146 >= V_155 )
V_146 = 0 ;
if ( V_147 > 0 ) {
V_147 = V_147 <= 5 ? 5 : 13 ;
V_149 = F_31 ( ( T_2 ) ( V_147 +
F_32 ( struct V_148 ,
V_160 ) ) , V_161 ) ;
if ( V_149 == NULL )
return - V_162 ;
memset ( V_149 , 0 , sizeof( struct V_148 ) ) ;
V_149 -> V_163 = V_147 ;
V_149 -> V_164 = V_147 +
F_32 ( struct V_148 ,
V_160 ) ;
if ( V_147 == 13 ) {
V_2 -> V_31 . V_157 =
V_165 ;
V_2 -> V_31 . V_159 =
V_165 ;
}
} else {
return - V_144 ;
}
V_149 -> V_166 = V_146 ;
V_149 -> V_166 |= 0x80000000 ;
memcpy ( V_149 -> V_160 , V_21 -> V_24 . V_25 . V_26 , V_149 -> V_163 ) ;
if ( V_21 -> V_24 . V_25 . V_167 ) {
if ( F_33 ( V_2 , V_149 ) ==
( T_4 ) V_168 )
V_133 = - V_169 ;
} else {
if ( V_146 >= V_155 ) {
V_133 = - V_169 ;
goto exit;
}
memcpy ( & ( V_151 -> V_170 [ V_146 ] .
V_23 [ 0 ] ) , V_149 -> V_160 ,
V_149 -> V_163 ) ;
V_151 -> V_171 [ V_146 ] =
V_149 -> V_163 ;
F_10 ( V_2 , V_151 , V_146 ) ;
}
goto exit;
}
if ( V_2 -> V_31 . V_140 == 2 ) {
struct V_18 * V_19 , * V_172 ;
struct V_173 * V_174 = & V_2 -> V_175 ;
if ( F_34 ( V_6 , V_176 |
V_177 ) ) {
V_19 = F_35 ( V_174 ,
F_36 ( V_6 ) ) ;
if ( V_19 ) {
V_19 -> V_178 = false ;
if ( ( V_2 -> V_31 . V_136 ==
V_179 ) ||
( V_2 -> V_31 . V_136 ==
V_180 ) )
V_19 -> V_181 = V_2 ->
V_31 . V_157 ;
if ( V_21 -> V_24 . V_25 . V_167 == 1 )
F_5 ( V_19 , V_21 ,
V_2 ) ;
else
F_9 ( V_21 , V_2 ) ;
}
V_172 = F_37 ( V_2 ) ;
if ( V_172 ) {
V_172 -> V_178 = false ;
if ( ( V_2 -> V_31 . V_136 ==
V_179 ) ||
( V_2 -> V_31 . V_136 ==
V_180 ) )
V_172 -> V_181 =
V_2 -> V_31 .
V_157 ;
}
}
}
exit:
F_38 ( V_149 ) ;
return V_133 ;
}
static int F_39 ( struct V_1 * V_2 , char * V_182 ,
unsigned short V_183 )
{
T_4 * V_110 = NULL ;
int V_184 = 0 , V_185 = 0 ;
int V_133 = 0 ;
if ( ( V_183 > V_111 ) || ( V_182 == NULL ) )
return - V_144 ;
if ( V_183 ) {
V_110 = F_40 ( V_182 , V_183 , V_161 ) ;
if ( V_110 == NULL )
return - V_162 ;
if ( V_183 < V_186 ) {
V_133 = - V_144 ;
goto exit;
}
if ( F_41 ( V_110 , V_183 , & V_184 ,
& V_185 ) == V_187 ) {
V_2 -> V_31 . V_140 = 2 ;
V_2 -> V_31 . V_138 =
V_142 ;
}
if ( F_42 ( V_110 , V_183 , & V_184 ,
& V_185 ) == V_187 ) {
V_2 -> V_31 . V_140 = 2 ;
V_2 -> V_31 . V_138 =
V_188 ;
}
switch ( V_184 ) {
case V_189 :
V_2 -> V_31 . V_159 =
V_190 ;
V_2 -> V_31 . V_136 =
V_191 ;
break;
case V_192 :
V_2 -> V_31 . V_159 = V_158 ;
V_2 -> V_31 . V_136 =
V_137 ;
break;
case V_193 :
V_2 -> V_31 . V_159 = V_194 ;
V_2 -> V_31 . V_136 =
V_179 ;
break;
case V_195 :
V_2 -> V_31 . V_159 = V_196 ;
V_2 -> V_31 . V_136 =
V_180 ;
break;
case V_197 :
V_2 -> V_31 . V_159 = V_165 ;
V_2 -> V_31 . V_136 =
V_137 ;
break;
}
switch ( V_185 ) {
case V_189 :
V_2 -> V_31 . V_157 =
V_190 ;
V_2 -> V_31 . V_136 =
V_191 ;
break;
case V_192 :
V_2 -> V_31 . V_157 = V_158 ;
V_2 -> V_31 . V_136 =
V_137 ;
break;
case V_193 :
V_2 -> V_31 . V_157 = V_194 ;
V_2 -> V_31 . V_136 =
V_179 ;
break;
case V_195 :
V_2 -> V_31 . V_157 = V_196 ;
V_2 -> V_31 . V_136 =
V_180 ;
break;
case V_197 :
V_2 -> V_31 . V_157 = V_165 ;
V_2 -> V_31 . V_136 =
V_137 ;
break;
}
V_2 -> V_31 . V_198 = false ;
{
T_3 V_199 = 0 ;
T_4 V_200 , V_201 [ 4 ] = { 0x0 , 0x50 , 0xf2 , 0x04 } ;
while ( V_199 < V_183 ) {
V_200 = V_110 [ V_199 ] ;
if ( ( V_200 == V_202 ) &&
( ! memcmp ( & V_110 [ V_199 + 2 ] , V_201 , 4 ) ) ) {
F_30 ( V_2 -> V_16 , L_13 ) ;
V_2 -> V_31 . V_203 =
( ( V_110 [ V_199 + 1 ] + 2 ) <
( V_111 << 2 ) ) ?
( V_110 [ V_199 + 1 ] + 2 ) :
( V_111 << 2 ) ;
memcpy ( V_2 -> V_31 . V_119 ,
& V_110 [ V_199 ] ,
V_2 -> V_31 . V_203 ) ;
V_2 -> V_31 . V_198 =
true ;
F_30 ( V_2 -> V_16 , L_14 ) ;
V_199 += V_110 [ V_199 + 1 ] + 2 ;
break;
} else {
V_199 += V_110 [ V_199 + 1 ] + 2 ;
}
}
}
}
exit:
F_38 ( V_110 ) ;
return V_133 ;
}
static int F_43 ( struct V_131 * V_132 ,
struct V_46 * V_47 ,
union V_3 * V_4 , char * V_204 )
{
struct V_1 * V_2 = F_27 ( V_132 ) ;
T_2 V_59 = 0 ;
char * V_57 ;
T_4 V_61 = false ;
struct V_5 * V_6 = & ( V_2 -> V_7 ) ;
struct V_205 * V_206 = & V_6 -> V_12 . V_13 ;
T_4 * V_207 ;
if ( F_34 ( V_6 , V_208 | V_209 ) ==
true ) {
V_57 = F_16 ( & V_206 -> V_74 [ 12 ] , V_75 ,
& V_59 , V_206 -> V_76 - 12 ) ;
if ( V_57 && V_59 > 0 )
V_61 = true ;
V_207 = V_206 -> V_79 ;
if ( F_17 ( V_207 ) ) {
if ( V_61 )
snprintf ( V_4 -> V_80 , V_81 ,
L_2 ) ;
else
snprintf ( V_4 -> V_80 , V_81 ,
L_3 ) ;
} else if ( F_18 ( V_207 ) ) {
if ( V_61 )
snprintf ( V_4 -> V_80 , V_81 ,
L_4 ) ;
else
snprintf ( V_4 -> V_80 , V_81 ,
L_5 ) ;
} else {
if ( V_61 )
snprintf ( V_4 -> V_80 , V_81 ,
L_6 ) ;
else
snprintf ( V_4 -> V_80 , V_81 ,
L_7 ) ;
}
} else {
snprintf ( V_4 -> V_80 , V_81 , L_15 ) ;
}
return 0 ;
}
static int F_44 ( struct V_131 * V_132 ,
struct V_46 * V_47 ,
union V_3 * V_4 , char * V_204 )
{
struct V_1 * V_2 = F_27 ( V_132 ) ;
struct V_210 * V_211 = & V_4 -> V_93 ;
int V_212 = 0 ;
if ( ( V_211 -> V_96 == 1 ) &&
( V_211 -> V_94 >= ( int ) 2.412e8 ) &&
( V_211 -> V_94 <= ( int ) 2.487e8 ) ) {
int V_213 = V_211 -> V_94 / 100000 ;
int V_214 = 0 ;
while ( ( V_214 < 14 ) && ( V_213 != V_215 [ V_214 ] ) )
V_214 ++ ;
V_211 -> V_96 = 0 ;
V_211 -> V_94 = V_214 + 1 ;
}
if ( ( V_211 -> V_94 > 14 ) || ( V_211 -> V_96 > 0 ) ) {
V_212 = - V_169 ;
} else {
int V_216 = V_211 -> V_94 ;
if ( ( V_216 < 1 ) || ( V_216 > 14 ) ) {
V_212 = - V_144 ;
} else {
V_2 -> V_40 . V_216 = V_216 ;
}
}
return V_212 ;
}
static int F_45 ( struct V_131 * V_132 ,
struct V_46 * V_47 ,
union V_3 * V_4 , char * V_204 )
{
struct V_1 * V_2 = F_27 ( V_132 ) ;
struct V_5 * V_6 = & V_2 -> V_7 ;
struct V_205 * V_206 = & V_6 -> V_12 . V_13 ;
if ( F_34 ( V_6 , V_208 ) ) {
V_4 -> V_93 . V_94 = V_92 [
V_206 -> V_64 . V_65 - 1 ] * 100000 ;
V_4 -> V_93 . V_96 = 1 ;
V_4 -> V_93 . V_58 = V_206 -> V_64 . V_65 ;
} else {
return - V_217 ;
}
return 0 ;
}
static int F_46 ( struct V_131 * V_132 ,
struct V_46 * V_218 ,
union V_3 * V_4 , char * V_219 )
{
struct V_1 * V_2 = F_27 ( V_132 ) ;
enum V_220 V_221 ;
switch ( V_4 -> V_86 ) {
case V_222 :
V_221 = V_223 ;
break;
case V_88 :
V_221 = V_224 ;
break;
case V_87 :
V_221 = V_225 ;
break;
case V_226 :
V_221 = V_227 ;
break;
default:
return - V_144 ;
}
if ( V_225 == V_221 )
F_47 ( V_2 , V_221 ) ;
else
F_47 ( V_2 , V_223 ) ;
F_48 ( V_2 , V_221 ) ;
return 0 ;
}
static int F_49 ( struct V_131 * V_132 , struct V_46 * V_218 ,
union V_3 * V_4 , char * V_219 )
{
struct V_1 * V_2 = F_27 ( V_132 ) ;
struct V_5 * V_6 = & V_2 -> V_7 ;
if ( F_34 ( V_6 , V_176 ) )
V_4 -> V_86 = V_226 ;
else if ( F_34 ( V_6 ,
V_209 | V_228 ) )
V_4 -> V_86 = V_88 ;
else if ( F_34 ( V_6 , V_229 ) )
V_4 -> V_86 = V_87 ;
else
V_4 -> V_86 = V_222 ;
return 0 ;
}
static int F_50 ( struct V_131 * V_132 ,
struct V_46 * V_218 ,
union V_3 * V_4 , char * V_204 )
{
struct V_1 * V_2 = F_27 ( V_132 ) ;
struct V_150 * V_151 = & V_2 -> V_31 ;
struct V_230 * V_231 = (struct V_230 * ) V_204 ;
T_4 V_232 [ V_15 ] = { 0x00 } ;
T_4 V_233 [ V_15 ] = { 0x00 } ;
T_4 V_234 , V_235 = false ;
int V_236 = false ;
if ( V_231 == NULL )
return - V_144 ;
memcpy ( V_233 , V_231 -> V_237 . V_11 , V_15 ) ;
switch ( V_231 -> V_66 ) {
case V_238 :
if ( ! memcmp ( V_233 , V_232 , V_15 ) )
return V_236 ;
V_236 = true ;
V_235 = false ;
for ( V_234 = 0 ; V_234 < V_239 ; V_234 ++ ) {
if ( ! memcmp ( V_151 -> V_240 [ V_234 ] . V_241 ,
V_233 , V_15 ) ) {
F_30 ( V_132 , L_16 ,
V_156 ) ;
memcpy ( V_151 -> V_240 [ V_234 ] . V_242 ,
V_231 -> V_243 , V_244 ) ;
V_151 -> V_240 [ V_234 ] . V_245 = true ;
V_151 -> V_246 = V_234 + 1 ;
V_235 = true ;
break;
}
}
if ( ! V_235 ) {
F_30 ( V_132 , L_17 ,
V_156 , V_151 -> V_246 ) ;
memcpy ( V_151 -> V_240 [ V_151 ->
V_246 ] . V_241 , V_233 , V_15 ) ;
memcpy ( V_151 -> V_240 [ V_151 ->
V_246 ] . V_242 , V_231 -> V_243 , V_244 ) ;
V_151 -> V_240 [ V_151 -> V_246 ] .
V_245 = true ;
V_151 -> V_246 ++ ;
if ( V_151 -> V_246 == V_239 )
V_151 -> V_246 = 0 ;
}
break;
case V_247 :
V_236 = true ;
for ( V_234 = 0 ; V_234 < V_239 ; V_234 ++ ) {
if ( ! memcmp ( V_151 -> V_240 [ V_234 ] . V_241 ,
V_233 , V_15 ) ) {
F_4 ( V_151 -> V_240 [ V_234 ] . V_241 ) ;
V_151 -> V_240 [ V_234 ] . V_245 = false ;
break;
}
}
break;
case V_248 :
memset ( V_151 -> V_240 , 0 ,
sizeof( struct V_249 ) * V_239 ) ;
V_151 -> V_246 = 0 ;
V_236 = true ;
break;
default:
F_30 ( V_132 , L_18 , V_156 ) ;
V_236 = false ;
break;
}
return V_236 ;
}
static int F_51 ( struct V_131 * V_132 ,
struct V_46 * V_47 ,
union V_3 * V_4 , char * V_204 )
{
V_4 -> V_250 . V_108 = 0 ;
V_4 -> V_250 . V_106 = 0 ;
V_4 -> V_250 . V_107 = 1 ;
return 0 ;
}
static int F_52 ( struct V_131 * V_132 ,
struct V_46 * V_47 ,
union V_3 * V_4 , char * V_204 )
{
struct V_251 * V_252 = (struct V_251 * ) V_204 ;
T_3 V_253 ;
int V_58 ;
V_4 -> V_69 . V_71 = sizeof( * V_252 ) ;
memset ( V_252 , 0 , sizeof( * V_252 ) ) ;
V_252 -> V_254 = 5 * 1000 * 1000 ;
V_252 -> V_255 . V_123 = 100 ;
V_252 -> V_255 . V_128 = 100 ;
V_252 -> V_255 . V_129 = 100 ;
V_252 -> V_255 . V_124 = 7 ;
V_252 -> V_256 . V_123 = 92 ;
V_252 -> V_256 . V_128 = 0x100 - 78 ;
V_252 -> V_256 . V_129 = 0 ;
V_252 -> V_256 . V_124 = 7 ;
V_252 -> V_257 = V_258 ;
for ( V_58 = 0 ; V_58 < V_258 && V_58 < V_259 ; V_58 ++ )
V_252 -> V_105 [ V_58 ] = V_260 [ V_58 ] ;
V_252 -> V_261 = V_262 ;
V_252 -> V_263 = V_264 ;
V_252 -> V_265 = 0 ;
V_252 -> V_266 = V_267 ;
V_252 -> V_268 = 16 ;
V_252 -> V_269 = 14 ;
for ( V_58 = 0 , V_253 = 0 ; V_58 < 14 ; V_58 ++ ) {
V_252 -> V_93 [ V_253 ] . V_58 = V_58 + 1 ;
V_252 -> V_93 [ V_253 ] . V_94 = V_92 [ V_58 ] * 100000 ;
V_252 -> V_93 [ V_253 ] . V_96 = 1 ;
V_253 ++ ;
if ( V_253 == V_270 )
break;
}
V_252 -> V_271 = V_253 ;
V_252 -> V_272 = V_273 |
V_274 |
V_275 |
V_276 ;
return 0 ;
}
static int F_53 ( struct V_131 * V_132 ,
struct V_46 * V_47 ,
union V_3 * V_277 ,
char * V_204 )
{
int V_133 = 0 , V_278 = 0 ;
char * V_279 ;
struct V_1 * V_2 = F_27 ( V_132 ) ;
struct V_280 * V_281 = (struct V_280 * ) V_277 ;
V_278 = V_281 -> V_71 ;
V_279 = F_54 ( V_281 -> V_282 , V_278 ) ;
if ( F_55 ( V_279 ) )
return F_56 ( V_279 ) ;
if ( ! strcasecmp ( V_279 , L_19 ) ) {
struct V_5 * V_6 = & ( V_2 -> V_7 ) ;
struct V_48 * V_283 = & V_6 -> V_12 ;
if ( F_34 ( V_6 , V_208 ) ) {
sprintf ( V_279 , L_20 ,
V_283 -> V_13 . V_72 . V_72 ,
( ( V_2 -> V_284 . V_285 ) >> 1 ) - 95
) ;
} else {
sprintf ( V_279 , L_21 ) ;
}
} else if ( ! strcasecmp ( V_279 , L_22 ) ) {
union V_3 V_286 ;
int V_287 ;
int V_288 ;
V_287 = F_57 ( V_132 , V_47 , & V_286 , V_204 ) ;
if ( V_287 != 0 )
V_288 = 0 ;
else
V_288 = V_286 . V_105 . V_108 / 1000000 ;
sprintf ( V_279 , L_23 , V_288 ) ;
} else if ( ! strcasecmp ( V_279 , L_24 ) ) {
sprintf ( V_279 , L_25 , V_132 -> V_289 ) ;
} else if ( ! strcasecmp ( V_279 , L_26 ) ) {
struct V_5 * V_6 = & V_2 -> V_7 ;
V_6 -> V_290 = 1 ;
sprintf ( V_279 , L_21 ) ;
} else if ( ! strcasecmp ( V_279 , L_27 ) ) {
struct V_5 * V_6 = & V_2 -> V_7 ;
V_6 -> V_290 = 0 ;
sprintf ( V_279 , L_21 ) ;
} else if ( ! strncmp ( V_279 , L_28 , 5 ) ) {
F_58 ( V_2
, 1
, 5
, 100
, 5000
) ;
sprintf ( V_279 , L_21 ) ;
} else if ( ! strncmp ( V_279 , L_29 , 5 ) ) {
F_58 ( V_2
, 0
, 5
, 100
, 5000
) ;
sprintf ( V_279 , L_21 ) ;
} else {
F_30 ( V_132 , L_30 ,
V_156 , V_279 ) ;
goto V_291;
}
if ( F_59 ( V_281 -> V_282 , V_279 ,
F_60 ( V_281 -> V_71 , ( V_292 ) ( strlen ( V_279 ) + 1 ) ) ) )
V_133 = - V_293 ;
V_291:
F_38 ( V_279 ) ;
return V_133 ;
}
static int F_61 ( struct V_131 * V_132 ,
struct V_46 * V_47 ,
union V_3 * V_277 ,
char * V_204 )
{
int V_133 = - V_294 ;
struct V_1 * V_2 = F_27 ( V_132 ) ;
struct V_5 * V_6 = & V_2 -> V_7 ;
struct V_295 * V_296 = & V_6 -> V_297 ;
struct V_298 * V_299 = (struct V_298 * ) V_277 ;
unsigned long V_300 ;
struct V_301 * V_302 ;
T_4 * V_303 ;
struct V_48 * V_49 = NULL ;
enum V_304 V_305 ;
if ( F_34 ( V_6 , V_306 ) )
return - V_307 ;
if ( F_34 ( V_6 , V_308 ) )
return V_133 ;
if ( V_299 -> V_9 != V_10 )
return - V_144 ;
V_305 = V_2 -> V_31 . V_138 ;
F_62 ( & V_296 -> V_309 , V_300 ) ;
V_302 = & V_296 -> V_296 ;
V_6 -> V_310 = V_302 -> V_311 ;
while ( 1 ) {
if ( F_63 ( V_302 , V_6 -> V_310 ) )
break;
V_49 = F_64 ( V_6 -> V_310 ,
struct V_48 , V_312 ) ;
V_6 -> V_310 = V_6 -> V_310 -> V_311 ;
V_303 = V_49 -> V_13 . V_14 ;
if ( ! memcmp ( V_303 , V_299 -> V_11 , V_15 ) ) {
F_48 ( V_2 ,
V_49 -> V_13 . V_313 ) ;
break;
}
}
F_65 ( & V_296 -> V_309 , V_300 ) ;
if ( ! V_133 ) {
if ( ! F_66 ( V_2 , V_305 ) ) {
V_133 = - V_162 ;
} else {
if ( ! F_67 ( V_2 , V_299 -> V_11 ) )
V_133 = - 1 ;
}
}
return V_133 ;
}
static int F_68 ( struct V_131 * V_132 ,
struct V_46 * V_47 ,
union V_3 * V_4 , char * V_204 )
{
struct V_1 * V_2 = F_27 ( V_132 ) ;
struct V_5 * V_6 = & V_2 -> V_7 ;
struct V_205 * V_206 = & V_6 -> V_12 . V_13 ;
V_4 -> V_8 . V_9 = V_10 ;
if ( F_34 ( V_6 , V_208 | V_209 |
V_229 ) )
F_12 ( V_4 -> V_8 . V_11 , V_206 -> V_14 ) ;
else
F_4 ( V_4 -> V_8 . V_11 ) ;
return 0 ;
}
static int F_69 ( struct V_131 * V_132 ,
struct V_46 * V_47 ,
union V_3 * V_4 , char * V_204 )
{
int V_133 = 0 ;
struct V_1 * V_2 = F_27 ( V_132 ) ;
struct V_314 * V_315 = (struct V_314 * ) V_204 ;
if ( V_315 == NULL )
return - 1 ;
switch ( V_315 -> V_66 ) {
case V_316 :
if ( ! F_70 ( V_2 ) )
V_133 = - 1 ;
break;
case V_317 :
if ( ! F_70 ( V_2 ) )
V_133 = - 1 ;
break;
default:
return - V_169 ;
}
return V_133 ;
}
static int F_71 ( struct V_131 * V_132 ,
struct V_46 * V_218 ,
union V_3 * V_4 , char * V_204 )
{
struct V_1 * V_2 = F_27 ( V_132 ) ;
struct V_5 * V_6 = & V_2 -> V_7 ;
T_4 V_318 = true ;
if ( V_2 -> V_319 ) {
F_30 ( V_132 , L_31 ,
V_156 , V_2 -> V_319 ) ;
return - 1 ;
}
if ( ! V_2 -> V_320 )
return - V_321 ;
if ( ! V_2 -> V_322 )
return - 1 ;
if ( ( F_34 ( V_6 , V_306 | V_308 ) ) ||
( V_6 -> V_323 . V_324 ) )
return 0 ;
if ( V_4 -> V_69 . V_71 == sizeof( struct V_325 ) ) {
struct V_325 * V_326 = (struct V_325 * ) V_204 ;
if ( V_4 -> V_69 . V_70 & V_327 ) {
struct V_328 V_329 ;
unsigned long V_300 ;
T_2 V_278 = F_14 ( T_4 , V_326 -> V_330 , V_331 ) ;
memset ( ( unsigned char * ) & V_329 , 0 ,
sizeof( struct V_328 ) ) ;
memcpy ( V_329 . V_72 , V_326 -> V_332 , V_278 ) ;
V_329 . V_73 = V_278 ;
F_62 ( & V_6 -> V_309 , V_300 ) ;
if ( ( F_34 ( V_6 , V_306 |
V_308 ) ) ||
( V_6 -> V_323 . V_324 ) ) {
if ( F_34 ( V_6 , V_308 ) )
V_318 = false ;
} else {
V_318 = F_72 ( V_2 , & V_329 ) ;
}
F_65 ( & V_6 -> V_309 , V_300 ) ;
}
} else {
V_318 = F_73 ( V_2 ) ;
}
if ( ! V_318 )
return - 1 ;
return 0 ;
}
static int F_74 ( struct V_131 * V_132 ,
struct V_46 * V_218 ,
union V_3 * V_4 , char * V_204 )
{
struct V_1 * V_2 = F_27 ( V_132 ) ;
struct V_5 * V_6 = & V_2 -> V_7 ;
struct V_295 * V_296 = & V_6 -> V_297 ;
struct V_48 * V_49 = NULL ;
unsigned long V_300 ;
struct V_301 * V_333 , * V_302 ;
char * V_334 = V_204 ;
char * V_51 = V_334 + V_4 -> V_69 . V_71 ;
T_2 V_133 = 0 , V_199 = 0 ;
if ( V_2 -> V_319 )
return - V_144 ;
while ( F_34 ( V_6 , V_306 |
V_308 ) ) {
F_75 ( 30 ) ;
V_199 ++ ;
if ( V_199 > 100 )
break;
}
F_62 ( & V_296 -> V_309 , V_300 ) ;
V_302 = & V_296 -> V_296 ;
V_333 = V_302 -> V_311 ;
while ( 1 ) {
if ( F_63 ( V_302 , V_333 ) )
break;
if ( ( V_51 - V_334 ) < V_335 ) {
V_133 = - V_336 ;
break;
}
V_49 = F_64 ( V_333 , struct V_48 , V_312 ) ;
V_334 = F_11 ( V_2 , V_218 , V_49 , V_334 , V_51 ) ;
V_333 = V_333 -> V_311 ;
}
F_65 ( & V_296 -> V_309 , V_300 ) ;
V_4 -> V_69 . V_71 = V_334 - V_204 ;
V_4 -> V_69 . V_70 = 0 ;
return V_133 ;
}
static int F_76 ( struct V_131 * V_132 ,
struct V_46 * V_218 ,
union V_3 * V_4 , char * V_204 )
{
struct V_1 * V_2 = F_27 ( V_132 ) ;
struct V_5 * V_6 = & V_2 -> V_7 ;
struct V_295 * V_296 = & V_6 -> V_297 ;
struct V_48 * V_49 = NULL ;
enum V_304 V_305 ;
struct V_328 V_337 ;
T_4 * V_338 , * V_339 ;
struct V_301 * V_302 ;
T_2 V_278 ;
if ( F_34 ( V_6 , V_306 ) )
return - V_307 ;
if ( F_34 ( V_6 , V_308 ) )
return 0 ;
if ( V_4 -> V_332 . V_71 > V_331 )
return - V_336 ;
V_305 = V_2 -> V_31 . V_138 ;
if ( V_4 -> V_332 . V_70 && V_4 -> V_332 . V_71 ) {
V_278 = ( V_4 -> V_332 . V_71 < V_331 ) ?
V_4 -> V_332 . V_71 : V_331 ;
memset ( & V_337 , 0 , sizeof( struct V_328 ) ) ;
V_337 . V_73 = V_278 ;
memcpy ( V_337 . V_72 , V_204 , V_278 ) ;
V_339 = V_337 . V_72 ;
V_302 = & V_296 -> V_296 ;
V_6 -> V_310 = V_302 -> V_311 ;
while ( 1 ) {
if ( F_63 ( V_302 , V_6 -> V_310 ) )
break;
V_49 = F_64 ( V_6 -> V_310 ,
struct V_48 , V_312 ) ;
V_6 -> V_310 = V_6 -> V_310 -> V_311 ;
V_338 = V_49 -> V_13 . V_72 . V_72 ;
if ( ( ! memcmp ( V_338 , V_339 , V_337 . V_73 ) )
&& ( V_49 -> V_13 . V_72 . V_73 ==
V_337 . V_73 ) ) {
if ( F_34 ( V_6 ,
V_228 ) ) {
if ( V_49 -> V_13 .
V_313
!=
V_2 -> V_7 .
V_12 . V_13 .
V_313 )
continue;
}
F_48 (
V_2 ,
V_49 -> V_13 . V_313 ) ;
break;
}
}
F_66 ( V_2 , V_305 ) ;
F_77 ( V_2 , & V_337 ) ;
}
return - V_294 ;
}
static int F_78 ( struct V_131 * V_132 ,
struct V_46 * V_218 ,
union V_3 * V_4 , char * V_204 )
{
struct V_1 * V_2 = F_27 ( V_132 ) ;
struct V_5 * V_6 = & V_2 -> V_7 ;
struct V_205 * V_206 = & V_6 -> V_12 . V_13 ;
T_2 V_278 , V_133 = 0 ;
if ( F_34 ( V_6 , V_208 | V_209 ) ) {
V_278 = V_206 -> V_72 . V_73 ;
V_4 -> V_332 . V_71 = V_278 ;
memcpy ( V_204 , V_206 -> V_72 . V_72 , V_278 ) ;
V_4 -> V_332 . V_70 = 1 ;
} else {
V_133 = - V_217 ;
}
return V_133 ;
}
static int F_79 ( struct V_131 * V_132 ,
struct V_46 * V_218 ,
union V_3 * V_4 , char * V_204 )
{
struct V_1 * V_2 = F_27 ( V_132 ) ;
T_2 V_340 = V_4 -> V_105 . V_108 ;
T_2 V_106 = V_4 -> V_105 . V_106 ;
T_2 V_341 = 0 ;
T_4 V_342 [ V_343 ] ;
T_4 V_344 [ V_343 ] = { 11 , 10 , 9 , 8 , 7 , 6 , 5 , 4 , 3 , 2 , 1 , 0 , 0xff } ;
int V_58 , V_133 = 0 ;
if ( V_340 == - 1 ) {
V_341 = 11 ;
goto V_345;
}
V_340 = V_340 / 100000 ;
switch ( V_340 ) {
case 10 :
V_341 = 0 ;
break;
case 20 :
V_341 = 1 ;
break;
case 55 :
V_341 = 2 ;
break;
case 60 :
V_341 = 3 ;
break;
case 90 :
V_341 = 4 ;
break;
case 110 :
V_341 = 5 ;
break;
case 120 :
V_341 = 6 ;
break;
case 180 :
V_341 = 7 ;
break;
case 240 :
V_341 = 8 ;
break;
case 360 :
V_341 = 9 ;
break;
case 480 :
V_341 = 10 ;
break;
case 540 :
V_341 = 11 ;
break;
default:
V_341 = 11 ;
break;
}
V_345:
for ( V_58 = 0 ; V_58 < V_343 ; V_58 ++ ) {
if ( V_341 == V_344 [ V_58 ] ) {
V_342 [ V_58 ] = V_344 [ V_58 ] ;
if ( V_106 == 0 )
break;
} else {
V_342 [ V_58 ] = 0xff ;
}
}
if ( F_80 ( V_2 , V_342 ) != V_187 )
V_133 = - V_162 ;
return V_133 ;
}
static int F_57 ( struct V_131 * V_132 ,
struct V_46 * V_47 ,
union V_3 * V_4 , char * V_204 )
{
struct V_1 * V_2 = F_27 ( V_132 ) ;
struct V_5 * V_6 = & V_2 -> V_7 ;
struct V_205 * V_206 = & V_6 -> V_12 . V_13 ;
struct V_54 * V_55 ;
unsigned char V_346 = V_2 -> V_40 . V_347 ;
int V_58 ;
T_4 * V_57 ;
T_3 V_348 , V_349 = 0 , V_61 = false ;
T_2 V_59 = 0 ;
T_4 V_350 = 0 , V_351 = 0 ;
T_3 V_62 = 0 ;
V_58 = 0 ;
if ( F_34 ( V_6 , V_208 | V_209 ) ) {
V_57 = F_16 ( & V_206 -> V_74 [ 12 ] ,
V_75 , & V_59 ,
V_206 -> V_76 - 12 ) ;
if ( V_57 && V_59 > 0 ) {
V_61 = true ;
V_55 = (struct V_54 * ) ( V_57 + 2 ) ;
memcpy ( & V_62 , V_55 -> V_77 , 2 ) ;
V_350 = ( V_55 -> V_352 &
V_353 ) ? 1 : 0 ;
V_351 = ( V_55 -> V_352 &
( V_354 |
V_355 ) ) ? 1 : 0 ;
}
while ( ( V_206 -> V_79 [ V_58 ] != 0 ) &&
( V_206 -> V_79 [ V_58 ] != 0xFF ) ) {
V_348 = V_206 -> V_79 [ V_58 ] & 0x7F ;
if ( V_348 > V_349 )
V_349 = V_348 ;
V_4 -> V_105 . V_106 = 0 ;
V_4 -> V_105 . V_108 = V_348 * 500000 ;
V_58 ++ ;
}
if ( V_61 ) {
if ( V_62 & 0x8000
&&
V_346 == V_356 )
V_349 = ( V_350 ) ? ( ( V_351 ) ? 300 :
270 ) : ( ( V_351 ) ? 144 : 130 ) ;
else
V_349 = ( V_350 ) ? ( ( V_351 ) ? 150 :
135 ) : ( ( V_351 ) ? 72 : 65 ) ;
V_349 *= 2 ;
}
V_4 -> V_105 . V_108 = V_349 * 500000 ;
} else {
return - V_217 ;
}
return 0 ;
}
static int F_81 ( struct V_131 * V_132 ,
struct V_46 * V_47 ,
union V_3 * V_4 , char * V_204 )
{
struct V_1 * V_2 = F_27 ( V_132 ) ;
V_4 -> V_357 . V_108 = V_2 -> V_40 . V_358 ;
V_4 -> V_357 . V_106 = 0 ;
return 0 ;
}
static int F_82 ( struct V_131 * V_132 ,
struct V_46 * V_47 ,
union V_3 * V_4 , char * V_204 )
{
struct V_1 * V_2 = F_27 ( V_132 ) ;
if ( V_4 -> V_359 . V_107 ) {
V_2 -> V_360 . V_361 = V_264 ;
} else {
if ( V_4 -> V_359 . V_108 < V_262 ||
V_4 -> V_359 . V_108 > V_264 )
return - V_144 ;
V_2 -> V_360 . V_361 = V_4 -> V_359 . V_108 & ~ 0x1 ;
}
return 0 ;
}
static int F_83 ( struct V_131 * V_132 ,
struct V_46 * V_47 ,
union V_3 * V_4 , char * V_204 )
{
struct V_1 * V_2 = F_27 ( V_132 ) ;
V_4 -> V_359 . V_108 = V_2 -> V_360 . V_361 ;
V_4 -> V_359 . V_106 = 0 ;
return 0 ;
}
static int F_84 ( struct V_131 * V_132 ,
struct V_46 * V_47 ,
union V_3 * V_4 , char * V_204 )
{
V_4 -> V_362 . V_108 = 7 ;
V_4 -> V_362 . V_106 = 0 ;
V_4 -> V_362 . V_107 = 1 ;
return 0 ;
}
static int F_85 ( struct V_131 * V_132 ,
struct V_46 * V_47 ,
union V_3 * V_4 , char * V_363 )
{
T_2 V_26 ;
T_2 V_364 ;
struct V_148 V_365 ;
enum V_304 V_305 ;
struct V_280 * V_366 = & ( V_4 -> V_367 ) ;
struct V_1 * V_2 = F_27 ( V_132 ) ;
V_26 = V_366 -> V_70 & V_368 ;
memset ( & V_365 , 0 , sizeof( struct V_148 ) ) ;
if ( V_366 -> V_70 & V_103 ) {
F_30 ( V_132 , L_32 , V_156 ) ;
V_2 -> V_31 . V_136 =
V_191 ;
V_2 -> V_31 . V_157 = V_190 ;
V_2 -> V_31 . V_159 = V_190 ;
V_2 -> V_31 . V_140 = 0 ;
V_305 = V_143 ;
V_2 -> V_31 . V_138 = V_305 ;
return 0 ;
}
if ( V_26 ) {
if ( V_26 > V_155 )
return - V_144 ;
V_26 -- ;
V_364 = 1 ;
} else {
V_364 = 0 ;
V_26 = V_2 -> V_31 . V_369 ;
}
if ( V_366 -> V_70 & V_370 ) {
F_30 ( V_132 , L_33 , V_156 ) ;
V_2 -> V_31 . V_136 =
V_137 ;
V_2 -> V_31 . V_140 = 0 ;
V_2 -> V_31 . V_157 = V_190 ;
V_2 -> V_31 . V_159 = V_190 ;
V_305 = V_143 ;
V_2 -> V_31 . V_138 = V_305 ;
} else if ( V_366 -> V_70 & V_371 ) {
F_30 ( V_132 ,
L_34 , V_156 ) ;
V_2 -> V_31 . V_136 =
V_137 ;
V_2 -> V_31 . V_140 = 1 ;
V_2 -> V_31 . V_157 = V_158 ;
V_2 -> V_31 . V_159 = V_158 ;
V_305 = V_141 ;
V_2 -> V_31 . V_138 = V_305 ;
} else {
V_2 -> V_31 . V_136 =
V_137 ;
V_2 -> V_31 . V_140 = 0 ;
V_2 -> V_31 . V_157 = V_190 ;
V_2 -> V_31 . V_159 = V_190 ;
V_305 = V_143 ;
V_2 -> V_31 . V_138 = V_305 ;
}
V_365 . V_166 = V_26 ;
if ( V_366 -> V_71 > 0 ) {
V_365 . V_163 = V_366 -> V_71 <= 5 ? 5 : 13 ;
V_365 . V_164 = V_365 . V_163 +
F_32 ( struct V_148 , V_160 ) ;
} else {
V_365 . V_163 = 0 ;
if ( V_364 == 1 ) {
V_2 -> V_31 . V_369 = V_26 ;
switch ( V_2 -> V_31 . V_171 [ V_26 ] ) {
case 5 :
V_2 -> V_31 . V_157 =
V_158 ;
break;
case 13 :
V_2 -> V_31 . V_157 =
V_165 ;
break;
default:
V_2 -> V_31 . V_157 =
V_190 ;
break;
}
return 0 ;
}
}
V_365 . V_166 |= 0x80000000 ;
memcpy ( V_365 . V_160 , V_363 , V_365 . V_163 ) ;
if ( F_33 ( V_2 , & V_365 ) == V_168 )
return - V_169 ;
return 0 ;
}
static int F_86 ( struct V_131 * V_132 ,
struct V_46 * V_47 ,
union V_3 * V_4 , char * V_363 )
{
T_5 V_26 , V_133 = 0 ;
struct V_1 * V_2 = F_27 ( V_132 ) ;
struct V_280 * V_366 = & ( V_4 -> V_367 ) ;
struct V_5 * V_6 = & ( V_2 -> V_7 ) ;
if ( ! F_34 ( V_6 , V_208 ) ) {
if ( ! F_34 ( V_6 , V_209 ) ) {
V_366 -> V_71 = 0 ;
V_366 -> V_70 |= V_103 ;
return 0 ;
}
}
V_26 = V_366 -> V_70 & V_368 ;
if ( V_26 ) {
if ( V_26 > V_155 )
return - V_144 ;
V_26 -- ;
} else {
V_26 = V_2 -> V_31 . V_369 ;
}
V_366 -> V_70 = V_26 + 1 ;
switch ( V_2 -> V_31 . V_136 ) {
case V_372 :
case V_191 :
V_366 -> V_71 = 0 ;
V_366 -> V_70 |= V_103 ;
break;
case V_137 :
V_366 -> V_71 = V_2 -> V_31 . V_171 [ V_26 ] ;
if ( V_366 -> V_71 ) {
memcpy ( V_363 , V_2 -> V_31 . V_170 [
V_26 ] . V_23 , V_2 -> V_31 .
V_171 [ V_26 ] ) ;
V_366 -> V_70 |= V_101 ;
if ( V_2 -> V_31 . V_138 ==
V_143 )
V_366 -> V_70 |= V_370 ;
else if ( V_2 -> V_31 . V_138 ==
V_141 )
V_366 -> V_70 |= V_371 ;
} else {
V_366 -> V_71 = 0 ;
V_366 -> V_70 |= V_103 ;
}
break;
case V_179 :
case V_180 :
V_366 -> V_71 = 16 ;
V_366 -> V_70 |= ( V_101 | V_370 |
V_102 ) ;
break;
default:
V_366 -> V_71 = 0 ;
V_366 -> V_70 |= V_103 ;
break;
}
return V_133 ;
}
static int F_87 ( struct V_131 * V_132 ,
struct V_46 * V_47 ,
union V_3 * V_4 , char * V_204 )
{
V_4 -> V_373 . V_108 = 0 ;
V_4 -> V_373 . V_106 = 0 ;
V_4 -> V_373 . V_107 = 1 ;
return 0 ;
}
static int F_88 ( struct V_131 * V_132 ,
struct V_46 * V_47 ,
union V_3 * V_4 , char * V_204 )
{
struct V_1 * V_2 = F_27 ( V_132 ) ;
return F_39 ( V_2 , V_204 , V_4 -> V_69 . V_71 ) ;
}
static int F_89 ( struct V_131 * V_132 ,
struct V_46 * V_47 ,
union V_3 * V_4 , char * V_204 )
{
struct V_1 * V_2 = F_27 ( V_132 ) ;
struct V_374 * V_21 = (struct V_374 * ) & ( V_4 -> V_21 ) ;
int V_375 ;
int V_376 ;
int V_133 = 0 ;
V_375 = V_21 -> V_70 & V_377 ;
V_376 = V_21 -> V_108 ;
switch ( V_375 ) {
case V_378 :
break;
case V_379 :
break;
case V_380 :
break;
case V_381 :
break;
case V_382 :
if ( V_376 ) {
V_2 -> V_31 . V_383 = true ;
} else {
V_2 -> V_31 . V_383 = false ;
}
break;
case V_384 :
if ( V_2 -> V_31 . V_136 ==
V_137 ) {
break;
}
if ( V_376 ) {
V_2 -> V_31 . V_136 =
V_191 ;
V_2 -> V_31 . V_157 =
V_190 ;
V_2 -> V_31 . V_159 =
V_190 ;
V_2 -> V_31 . V_140 = 0 ;
V_2 -> V_31 . V_138 =
V_143 ;
}
break;
case V_385 :
V_133 = F_26 ( V_132 , ( T_2 ) V_376 ) ;
break;
case V_386 :
break;
case V_387 :
break;
case V_388 :
break;
default:
return - V_169 ;
}
return V_133 ;
}
static int F_90 ( struct V_131 * V_132 ,
struct V_46 * V_47 ,
union V_3 * V_4 , char * V_204 )
{
struct V_280 * V_389 = & V_4 -> V_367 ;
struct V_390 * V_391 = (struct V_390 * ) V_204 ;
struct V_20 * V_21 = NULL ;
char * V_392 ;
T_2 V_145 ;
int V_133 = 0 ;
switch ( V_391 -> V_28 ) {
case V_393 :
V_392 = L_35 ;
break;
case V_394 :
V_392 = L_11 ;
break;
case V_395 :
V_392 = L_1 ;
break;
case V_396 :
V_392 = L_36 ;
break;
default:
return - V_144 ;
}
V_145 = sizeof( struct V_20 ) + V_391 -> V_27 ;
V_21 = F_91 ( V_145 , V_161 ) ;
if ( V_21 == NULL )
return - V_162 ;
V_21 -> V_66 = V_397 ;
F_92 ( V_21 -> V_154 ) ;
strncpy ( ( char * ) V_21 -> V_24 . V_25 . V_28 , V_392 , V_153 ) ;
if ( V_391 -> V_398 & V_399 )
V_21 -> V_24 . V_25 . V_167 = 0 ;
if ( V_391 -> V_398 & V_400 )
V_21 -> V_24 . V_25 . V_167 = 1 ;
V_21 -> V_24 . V_25 . V_35 = ( V_389 -> V_70 & 0x00FF ) - 1 ;
if ( V_391 -> V_398 & V_401 )
memcpy ( V_21 -> V_24 . V_25 . V_402 , V_391 -> V_403 , 8 ) ;
if ( V_391 -> V_27 ) {
V_21 -> V_24 . V_25 . V_27 = V_391 -> V_27 ;
memcpy ( V_21 + 1 , V_391 + 1 , V_391 -> V_27 ) ;
}
V_133 = F_28 ( V_132 , V_21 , V_145 ) ;
F_38 ( V_21 ) ;
return V_133 ;
}
static int F_93 ( struct V_131 * V_132 ,
struct V_46 * V_47 ,
union V_3 * V_4 , char * V_204 )
{
if ( V_204 ) {
V_4 -> V_69 . V_71 = 8 ;
V_4 -> V_69 . V_70 = 1 ;
memcpy ( V_204 , L_37 , 8 ) ;
}
return 0 ;
}
static int F_94 ( struct V_131 * V_132 ,
struct V_46 * V_47 ,
union V_3 * V_4 , char * V_363 )
{
struct V_1 * V_2 = F_27 ( V_132 ) ;
T_2 V_404 ;
T_2 V_405 ;
F_95 ( V_404 , ( T_2 V_406 * ) V_4 -> V_69 . V_282 ) ;
V_405 = F_96 ( V_2 , V_404 ) ;
F_97 ( V_405 , ( T_2 V_406 * ) V_4 -> V_69 . V_282 ) ;
V_4 -> V_69 . V_71 = ( V_405 & 0xffff0000 ) >> 16 ;
V_4 -> V_69 . V_70 = V_405 & 0xffff ;
F_95 ( V_404 , ( T_2 V_406 * ) V_4 -> V_69 . V_282 ) ;
return 0 ;
}
static int F_98 ( struct V_131 * V_132 ,
struct V_46 * V_47 ,
union V_3 * V_4 , char * V_363 )
{
struct V_1 * V_2 = F_27 ( V_132 ) ;
T_2 V_404 ;
T_2 V_405 ;
F_95 ( V_404 , ( T_2 V_406 * ) V_4 -> V_69 . V_282 ) ;
V_405 = ( ( T_2 ) V_4 -> V_69 . V_71 << 16 ) | ( T_2 ) V_4 -> V_69 . V_70 ;
F_99 ( V_2 , V_404 , V_405 ) ;
return 0 ;
}
static int F_100 ( struct V_131 * V_132 ,
struct V_46 * V_218 ,
union V_3 * V_4 , char * V_219 )
{
return - V_407 ;
}
static int F_101 ( struct V_131 * V_132 ,
struct V_46 * V_47 ,
union V_3 * V_4 , char * V_204 )
{
return 0 ;
}
static int F_102 ( struct V_131 * V_132 ,
struct V_46 * V_47 ,
union V_3 * V_4 , char * V_204 )
{
struct V_1 * V_2 = F_27 ( V_132 ) ;
struct V_280 * V_57 = & V_4 -> V_69 ;
struct V_408 V_409 ;
struct V_410 * V_411 ;
struct V_412 * V_413 ;
unsigned long V_414 , V_415 , V_416 ;
T_4 * V_417 , V_418 ;
T_3 V_278 ;
T_5 V_318 ;
int V_133 = 0 ;
if ( ( ! V_57 -> V_71 ) || ( ! V_57 -> V_282 ) )
return - V_144 ;
V_418 = ( T_4 ) ( V_57 -> V_70 & 0xFFFF ) ;
V_278 = V_57 -> V_71 ;
V_417 = F_54 ( V_57 -> V_282 , V_278 ) ;
if ( F_55 ( V_417 ) )
return F_56 ( V_417 ) ;
V_413 = (struct V_412 * ) V_417 ;
if ( V_413 -> V_419 >= V_420 ) {
V_133 = - V_144 ;
goto V_421;
}
V_411 = V_422 + V_413 -> V_419 ;
if ( ( V_411 -> V_423 != 0 ) &&
( V_413 -> V_278 < V_411 -> V_423 ) ) {
V_133 = - V_144 ;
goto V_421;
}
if ( V_411 -> V_424 == 0 && V_411 -> V_425 ) {
V_318 = V_411 -> V_425 ( & V_409 ) ;
} else if ( V_411 -> V_425 ) {
V_409 . V_426 = V_2 ;
V_409 . V_424 = V_411 -> V_424 ;
V_409 . V_427 = V_413 -> V_69 ;
V_409 . V_428 = V_413 -> V_278 ;
V_409 . V_429 = 0 ;
V_415 = 0 ;
V_416 = 0 ;
if ( V_418 ) {
V_409 . V_430 = & V_414 ;
V_409 . V_431 = & V_416 ;
V_409 . V_432 = V_433 ;
} else {
V_409 . V_430 = & V_415 ;
V_409 . V_431 = & V_416 ;
V_409 . V_432 = V_434 ;
}
V_318 = V_411 -> V_425 ( & V_409 ) ;
} else {
F_30 ( V_132 , L_38 ,
V_156 , V_413 -> V_419 , V_411 -> V_424 ,
V_411 -> V_425 ) ;
V_133 = - V_293 ;
goto V_421;
}
if ( V_418 == 0x00 ) {
if ( F_59 ( V_57 -> V_282 , V_417 , V_278 ) )
V_133 = - V_293 ;
}
if ( V_318 ) {
V_133 = - V_293 ;
goto V_421;
}
V_421:
F_38 ( V_417 ) ;
return V_133 ;
}
static int F_103 ( struct V_131 * V_132 ,
struct V_46 * V_47 ,
union V_3 * V_4 , char * V_204 )
{
struct V_1 * V_2 = F_27 ( V_132 ) ;
struct V_5 * V_6 = & V_2 -> V_7 ;
struct V_295 * V_296 = & V_6 -> V_297 ;
struct V_280 * V_435 = & V_4 -> V_69 ;
struct V_48 * V_49 = NULL ;
T_2 V_199 = 0 , V_436 ;
unsigned long V_300 ;
struct V_301 * V_333 , * V_302 ;
unsigned char * V_437 ;
T_4 V_237 [ V_15 ] ;
char V_69 [ 32 ] ;
if ( V_2 -> V_319 || ( V_435 == NULL ) )
return - V_144 ;
while ( F_34 ( V_6 , V_306 |
V_308 ) ) {
F_75 ( 30 ) ;
V_199 ++ ;
if ( V_199 > 100 )
break;
}
V_435 -> V_70 = 0 ;
if ( V_435 -> V_71 >= 32 ) {
if ( F_104 ( V_69 , V_435 -> V_282 , 32 ) )
return - V_144 ;
} else {
return - V_144 ;
}
F_62 ( & ( V_6 -> V_297 . V_309 ) , V_300 ) ;
V_302 = & V_296 -> V_296 ;
V_333 = V_302 -> V_311 ;
while ( 1 ) {
if ( F_63 ( V_302 , V_333 ) )
break;
V_49 = F_64 ( V_333 , struct V_48 , V_312 ) ;
if ( ! F_105 ( V_69 , V_237 ) ) {
F_30 ( V_132 , L_39 ,
( T_4 * ) V_69 ) ;
F_65 ( & ( V_6 -> V_297 . V_309 ) ,
V_300 ) ;
return - V_144 ;
}
F_30 ( V_132 , L_40 , V_237 ) ;
if ( F_106 ( V_237 , V_49 -> V_13 . V_14 ) ) {
V_437 = F_107 ( & V_49 -> V_13 . V_74 [ 12 ] ,
& V_436 , V_49 -> V_13 . V_76 - 12 ) ;
if ( V_437 && ( V_436 > 0 ) ) {
V_435 -> V_70 = 1 ;
break;
}
V_437 = F_108 ( & V_49 -> V_13 . V_74 [ 12 ] ,
& V_436 , V_49 -> V_13 . V_76 - 12 ) ;
if ( V_437 && ( V_436 > 0 ) ) {
V_435 -> V_70 = 2 ;
break;
}
}
V_333 = V_333 -> V_311 ;
}
F_65 ( & ( V_6 -> V_297 . V_309 ) , V_300 ) ;
if ( V_435 -> V_71 >= 34 ) {
if ( F_59 ( ( T_4 V_406 * ) V_435 -> V_282 + 32 ,
( T_4 * ) & V_435 -> V_70 , 1 ) )
return - V_144 ;
}
return 0 ;
}
static int F_109 ( struct V_131 * V_132 ,
struct V_46 * V_47 ,
union V_3 * V_4 , char * V_204 )
{
struct V_1 * V_2 = F_27 ( V_132 ) ;
struct V_280 * V_435 = & V_4 -> V_69 ;
if ( ( V_2 -> V_319 ) || ( V_435 == NULL ) )
return - V_144 ;
if ( F_104 ( & V_2 -> V_438 , V_435 -> V_282 , sizeof( int ) ) )
return - V_144 ;
return 0 ;
}
static int F_110 ( struct V_131 * V_132 ,
struct V_46 * V_47 ,
union V_3 * V_4 , char * V_204 )
{
int V_133 = 0 ;
struct V_1 * V_2 = F_27 ( V_132 ) ;
struct V_280 * V_435 = & V_4 -> V_69 ;
int V_439 = - 1 ;
if ( ( V_2 -> V_319 ) || ( V_435 == NULL ) ) {
V_133 = - V_144 ;
goto exit;
}
V_439 = ( int ) * V_204 ;
F_111 ( V_2 , V_439 ) ;
exit:
return V_133 ;
}
static int F_112 ( struct V_131 * V_132 ,
struct V_46 * V_47 ,
union V_3 * V_4 , char * V_204 )
{
struct V_1 * V_2 = F_27 ( V_132 ) ;
struct V_280 * V_435 = & V_4 -> V_69 ;
T_2 V_440 = 0 ;
if ( ( V_2 -> V_319 ) || ( V_435 == NULL ) )
return - V_144 ;
if ( F_104 ( ( void * ) & V_440 , V_435 -> V_282 , 4 ) )
return - V_293 ;
if ( V_440 == 0 )
V_440 = * V_204 ;
if ( V_440 == 1 )
V_2 -> V_441 . V_442 ( V_2 ,
V_443 ) ;
else if ( V_440 == 2 )
V_2 -> V_441 . V_442 ( V_2 ,
V_444 ) ;
else if ( V_440 == 3 )
V_2 -> V_441 . V_442 ( V_2 ,
V_445 ) ;
return 0 ;
}
static int F_113 ( struct V_131 * V_132 , T_4 V_80 , T_2 V_108 )
{
struct V_1 * V_2 = F_27 ( V_132 ) ;
switch ( V_80 ) {
case V_446 :
V_2 -> V_31 . V_140 = 2 ;
switch ( ( V_108 ) & 0xff ) {
case 1 :
V_2 -> V_31 . V_138 =
V_142 ;
V_2 -> V_31 . V_136 =
V_179 ;
break;
case 2 :
V_2 -> V_31 . V_138 =
V_188 ;
V_2 -> V_31 . V_136 =
V_180 ;
break;
}
break;
case V_447 :
break;
case V_448 :
break;
case V_449 :
break;
case V_450 :
return F_26 ( V_132 , V_108 ) ;
case V_451 :
break;
case V_452 :
break;
default:
return - V_169 ;
}
return 0 ;
}
static int F_114 ( struct V_131 * V_132 , T_2 V_453 , T_2 V_454 )
{
struct V_1 * V_2 = F_27 ( V_132 ) ;
switch ( V_453 ) {
case V_455 :
if ( ! F_70 ( V_2 ) )
return - 1 ;
break;
case V_456 :
if ( ! F_70 ( V_2 ) )
return - 1 ;
break;
default:
return - V_169 ;
}
return 0 ;
}
static int F_115 ( struct V_131 * V_132 , struct V_280 * V_57 )
{
struct V_20 * V_21 ;
int V_133 = 0 ;
struct V_1 * V_2 = F_27 ( V_132 ) ;
if ( V_57 -> V_71 < sizeof( struct V_20 ) || ! V_57 -> V_282 )
return - V_144 ;
V_21 = F_54 ( V_57 -> V_282 , V_57 -> V_71 ) ;
if ( F_55 ( V_21 ) )
return F_56 ( V_21 ) ;
switch ( V_21 -> V_66 ) {
case V_457 :
V_133 = F_113 ( V_132 , V_21 -> V_24 . V_458 . V_80 ,
V_21 -> V_24 . V_458 . V_108 ) ;
break;
case V_459 :
V_133 = F_39 ( V_2 , ( char * ) V_21 -> V_24 . V_112 . V_69 ,
( T_3 ) V_21 -> V_24 . V_112 . V_278 ) ;
break;
case V_397 :
V_133 = F_28 ( V_132 , V_21 , V_57 -> V_71 ) ;
break;
case V_460 :
V_133 = F_114 ( V_132 , V_21 -> V_24 . V_315 . V_453 ,
V_21 -> V_24 . V_315 . V_461 ) ;
break;
default:
V_133 = - V_169 ;
break;
}
if ( V_133 == 0 && F_59 ( V_57 -> V_282 , V_21 , V_57 -> V_71 ) )
V_133 = - V_293 ;
F_38 ( V_21 ) ;
return V_133 ;
}
int F_116 ( struct V_131 * V_132 , struct V_462 * V_463 , int V_66 )
{
struct V_464 * V_465 = (struct V_464 * ) V_463 ;
switch ( V_66 ) {
case V_466 :
return F_115 ( V_132 , & V_465 -> V_24 . V_69 ) ;
default:
return - V_169 ;
}
return 0 ;
}
static struct V_467 * F_117 ( struct V_131 * V_132 )
{
struct V_1 * V_2 = F_27 ( V_132 ) ;
struct V_467 * V_468 = & V_2 -> V_469 ;
int V_470 = 0 ;
int V_471 = 0 ;
int V_472 = 0 ;
if ( F_34 ( & V_2 -> V_7 , V_208 ) != true ) {
V_468 -> V_123 . V_123 = 0 ;
V_468 -> V_123 . V_128 = 0 ;
V_468 -> V_123 . V_129 = 0 ;
} else {
V_470 = V_2 -> V_284 . V_285 ;
V_471 = V_2 -> V_284 . signal ;
V_472 = V_2 -> V_284 . V_129 ;
V_468 -> V_123 . V_128 = V_470 ;
V_468 -> V_123 . V_123 = V_471 ;
V_468 -> V_123 . V_129 = V_472 ;
}
V_468 -> V_123 . V_124 = V_473 ;
return & V_2 -> V_469 ;
}
