inline int F_1 ( T_1 * V_1 , T_2 V_2 )
{
struct V_3 * V_4 ;
T_1 * V_5 ;
V_4 = (struct V_3 * ) V_1 ;
V_4 -> V_6 = 0xaa ;
V_4 -> V_7 = 0xaa ;
V_4 -> V_8 = 0x03 ;
if ( V_2 == 0x8137 || V_2 == 0x80f3 )
V_5 = V_9 ;
else
V_5 = V_10 ;
V_4 -> V_5 [ 0 ] = V_5 [ 0 ] ;
V_4 -> V_5 [ 1 ] = V_5 [ 1 ] ;
V_4 -> V_5 [ 2 ] = V_5 [ 2 ] ;
* ( V_11 * ) ( V_1 + V_12 ) = F_2 ( V_2 ) ;
return V_12 + sizeof( T_2 ) ;
}
int F_3 ( struct V_13 * V_14 , struct V_15 * V_16 ,
int V_17 )
{
struct V_18 * V_19 = NULL ;
int V_20 ;
V_19 = V_14 -> V_21 . V_19 [ V_14 -> V_21 . V_22 ] ;
if ( ! ( V_19 && V_19 -> V_23 ) ) {
F_4 ( V_24 L_1 , V_25 ) ;
return - 1 ;
}
F_5 ( & V_19 -> V_26 ) ;
V_20 = 0 ;
if ( V_19 -> V_23 -> V_27 )
V_20 = V_19 -> V_23 -> V_27 ( V_16 , V_17 , V_19 -> V_28 ) ;
if ( V_20 == 0 && V_19 -> V_23 -> V_29 )
V_20 = V_19 -> V_23 -> V_29 ( V_16 , V_17 , V_19 -> V_28 ) ;
F_6 ( & V_19 -> V_26 ) ;
if ( V_20 < 0 ) {
F_4 ( V_24 L_2 ,
V_14 -> V_30 -> V_31 , V_16 -> V_32 ) ;
V_14 -> V_33 . V_34 ++ ;
return - 1 ;
}
return 0 ;
}
void F_7 ( struct V_35 * V_36 )
{
if ( F_8 ( ! V_36 ) )
return;
F_9 ( V_36 ) ;
}
static struct V_35 * F_10 ( int V_37 , int V_38 ,
T_3 V_39 )
{
struct V_35 * V_36 ;
int V_40 ;
V_36 = F_11 ( sizeof( struct V_35 ) + ( sizeof( T_1 * ) * V_37 ) ,
V_39 ) ;
if ( ! V_36 )
return NULL ;
memset ( V_36 , 0 , sizeof( struct V_35 ) ) ;
V_36 -> V_37 = V_37 ;
V_36 -> V_41 = F_12 ( V_38 ) ;
for ( V_40 = 0 ; V_40 < V_37 ; V_40 ++ ) {
V_36 -> V_42 [ V_40 ] = F_13 ( V_38 ) ;
if ( F_8 ( ! V_36 -> V_42 [ V_40 ] ) ) {
V_40 -- ;
break;
}
memset ( V_36 -> V_42 [ V_40 ] -> V_43 , 0 , sizeof( V_36 -> V_42 [ V_40 ] -> V_43 ) ) ;
}
if ( F_8 ( V_40 != V_37 ) ) {
while ( V_40 >= 0 )
F_14 ( V_36 -> V_42 [ V_40 -- ] ) ;
F_9 ( V_36 ) ;
return NULL ;
}
return V_36 ;
}
static int F_15 ( struct V_15 * V_44 , T_1 V_45 )
{
struct V_46 * V_47 ;
struct V_48 * V_49 ;
V_47 = (struct V_46 * ) V_44 -> V_1 ;
if ( V_47 -> V_2 != F_2 ( V_50 ) )
return 0 ;
F_16 ( V_51 , V_44 -> V_1 , V_44 -> V_32 ) ;
V_49 = F_17 ( V_44 ) ;
switch ( V_49 -> V_52 & 0xfc ) {
case 0x20 :
return 2 ;
case 0x40 :
return 1 ;
case 0x60 :
return 3 ;
case 0x80 :
return 4 ;
case 0xa0 :
return 5 ;
case 0xc0 :
return 6 ;
case 0xe0 :
return 7 ;
default:
return 0 ;
}
}
static void F_18 ( struct V_13 * V_14 ,
struct V_15 * V_44 ,
struct V_53 * V_54 )
{
struct V_55 * V_56 = V_14 -> V_56 ;
struct V_57 * V_58 = NULL ;
struct V_59 * V_60 = (struct V_59 * ) V_44 -> V_1 ;
if ( F_19 ( V_14 , false ) )
return;
if ( ! V_56 -> V_61 || ! V_56 -> V_62 )
return;
if ( ! F_20 ( V_44 -> V_1 ) )
return;
if ( F_21 ( V_60 -> V_63 ) )
return;
if ( V_54 -> V_64 || V_14 -> V_65 < 2 )
return;
if ( V_56 -> V_66 & V_67 )
return;
if ( ! V_14 -> V_68 ( V_14 -> V_30 ) )
return;
if ( V_56 -> V_69 ) {
if ( ! F_22 ( V_14 , (struct V_70 * * ) ( & V_58 ) , V_60 -> V_63 ,
V_44 -> V_71 , V_72 , true ) ) {
F_4 ( V_24 L_3 , V_25 ) ;
return;
}
if ( V_58 -> V_73 . V_74 == false ) {
if ( V_14 -> V_75 && ( V_14 -> V_76 ==
V_77 ) ) {
;
} else if ( V_54 -> V_64 == 1 ) {
;
} else if ( ! V_58 -> V_78 ) {
F_23 ( V_14 , V_58 ) ;
}
goto V_79;
} else if ( V_58 -> V_80 == false ) {
if ( F_24 ( V_58 -> V_73 . V_81 . V_82 . V_83 ,
( V_58 -> V_84 + 1 ) % 4096 ) )
V_58 -> V_80 = true ;
else
goto V_79;
}
if ( V_14 -> V_85 == V_86 ) {
V_54 -> V_87 = true ;
V_54 -> V_88 = V_56 -> V_89 ;
V_54 -> V_90 = V_56 -> V_91 ;
}
}
V_79:
switch ( V_56 -> V_92 ) {
case V_93 :
break;
case V_94 :
V_54 -> V_87 = true ;
V_54 -> V_90 = V_56 -> V_95 ;
V_54 -> V_88 = V_56 -> V_96 ;
break;
case V_97 :
V_54 -> V_87 = false ;
V_54 -> V_90 = 0 ;
V_54 -> V_88 = 0 ;
break;
}
return;
}
static void F_25 ( struct V_13 * V_14 ,
struct V_53 * V_54 )
{
V_54 -> V_98 = false ;
if ( V_54 -> V_99 == 2 )
return;
else if ( V_14 -> V_100 . V_101 &
V_102 )
V_54 -> V_98 = true ;
return;
}
static void F_26 ( struct V_13 * V_14 ,
struct V_53 * V_54 )
{
struct V_55 * V_56 = V_14 -> V_56 ;
V_54 -> V_103 = false ;
if ( ! V_56 -> V_61 || ! V_56 -> V_62 )
return;
if ( V_56 -> V_104 ) {
V_54 -> V_103 = true ;
return;
}
if ( ( V_56 -> V_105 == true ) && V_56 -> V_106 )
V_54 -> V_103 = true ;
else if ( ( V_56 -> V_105 == false ) && V_56 -> V_107 )
V_54 -> V_103 = true ;
}
static void F_27 ( struct V_13 * V_14 ,
struct V_53 * V_54 )
{
struct V_55 * V_56 = V_14 -> V_56 ;
V_54 -> V_108 = false ;
if ( ! V_56 -> V_61 || ! V_56 -> V_62 )
return;
if ( V_54 -> V_109 || V_54 -> V_110 )
return;
if ( ( V_54 -> V_99 & 0x80 ) == 0 )
return;
if ( V_56 -> V_105 && V_56 -> V_111 &&
! V_14 -> V_112 . V_113 )
V_54 -> V_108 = true ;
return;
}
static void F_28 ( struct V_13 * V_14 ,
struct V_53 * V_54 ,
struct V_15 * V_44 )
{
V_54 -> V_114 = false ;
V_54 -> V_115 = false ;
V_54 -> V_116 = false ;
V_54 -> V_117 = 0 ;
V_54 -> V_118 = false ;
if ( V_54 -> V_110 || V_54 -> V_109 )
return;
if ( F_29 ( V_44 -> V_1 + 16 ) )
return;
if ( V_14 -> V_119 < V_120 ) {
if ( V_44 -> V_32 > V_14 -> V_121 ) {
V_54 -> V_122 = true ;
V_54 -> V_123 = V_124 ;
} else if ( V_14 -> V_100 . V_125 ) {
V_54 -> V_122 = true ;
V_54 -> V_116 = true ;
V_54 -> V_123 = V_124 ;
}
return;
} else {
struct V_55 * V_56 = V_14 -> V_56 ;
while ( true ) {
if ( V_56 -> V_66 & V_126 ) {
V_54 -> V_116 = true ;
V_54 -> V_123 = V_124 ;
V_54 -> V_122 = true ;
break;
} else if ( V_56 -> V_66 & ( V_127 |
V_128 ) ) {
V_54 -> V_122 = true ;
V_54 -> V_123 = V_124 ;
break;
}
if ( V_14 -> V_100 . V_125 ) {
V_54 -> V_122 = true ;
V_54 -> V_116 = true ;
V_54 -> V_123 = V_124 ;
break;
}
if ( V_56 -> V_61 && V_56 -> V_62 ) {
T_1 V_129 = V_56 -> V_130 ;
if ( ( V_56 -> V_105 && ( V_129 == 2 ||
V_129 == 3 ) ) ||
( ! V_56 -> V_105 && V_129 == 3 ) ) {
V_54 -> V_123 = V_124 ;
V_54 -> V_122 = true ;
break;
}
}
if ( V_44 -> V_32 > V_14 -> V_121 ) {
V_54 -> V_123 = V_124 ;
V_54 -> V_122 = true ;
break;
}
if ( V_54 -> V_87 ) {
V_54 -> V_123 = V_124 ;
V_54 -> V_122 = false ;
break;
}
goto V_131;
}
}
if ( V_14 -> V_100 . V_101 & V_102 )
V_54 -> V_98 = true ;
if ( V_14 -> V_85 == V_132 )
goto V_131;
return;
V_131:
V_54 -> V_122 = false ;
V_54 -> V_116 = false ;
V_54 -> V_123 = 0 ;
V_54 -> V_117 = 0 ;
V_54 -> V_118 = false ;
}
static void F_30 ( struct V_13 * V_14 ,
struct V_53 * V_54 )
{
if ( V_14 -> V_133 )
V_54 -> V_133 = true ;
if ( V_14 -> V_134 )
V_54 -> V_134 = true ;
if ( ! V_54 -> V_133 ||
! V_54 -> V_134 ) {
if ( V_14 -> V_85 == V_86 ||
V_14 -> V_85 == V_135 )
V_54 -> V_136 = 0 ;
}
}
T_2 F_31 ( struct V_13 * V_14 , struct V_15 * V_44 ,
T_1 * V_137 )
{
T_2 V_138 = 0 ;
if ( F_21 ( V_137 ) )
return 0 ;
if ( F_20 ( V_44 -> V_1 ) ) {
struct V_57 * V_139 = NULL ;
if ( ! F_22 ( V_14 , (struct V_70 * * ) ( & V_139 ) , V_137 ,
V_44 -> V_71 , V_72 , true ) )
return 0 ;
V_138 = V_139 -> V_84 ;
V_139 -> V_84 = ( V_139 -> V_84 + 1 ) % 4096 ;
return V_138 ;
}
return 0 ;
}
static int F_32 ( struct V_15 * V_44 )
{
switch ( V_44 -> V_71 ) {
case 6 :
case 7 :
V_44 -> V_71 = 5 ;
return 0 ;
case 4 :
case 5 :
V_44 -> V_71 = 3 ;
return 0 ;
case 0 :
case 3 :
V_44 -> V_71 = 1 ;
return 0 ;
default:
return - 1 ;
}
}
int F_33 ( struct V_15 * V_44 , struct V_140 * V_30 )
{
struct V_13 * V_14 = (struct V_13 * )
F_34 ( V_30 ) ;
struct V_35 * V_36 = NULL ;
struct V_141 * V_142 ;
int V_40 , V_143 , V_37 , V_144 , V_41 ;
unsigned long V_145 ;
struct V_146 * V_147 = & V_14 -> V_147 ;
int V_148 = 0 , V_149 ;
int V_150 , V_151 , V_152 = 0 , V_17 ;
struct V_15 * V_153 ;
struct V_141 V_154 = {
. V_155 = 0 ,
. V_156 = 0 ,
. V_152 = 0
} ;
T_1 V_157 [ V_158 ] , V_159 [ V_158 ] ;
int V_160 = V_14 -> V_100 . V_161 . V_162 ;
struct V_18 * V_19 = NULL ;
struct V_53 * V_54 ;
T_1 V_163 = false ;
T_1 V_164 = false ;
bool V_64 = false ;
F_35 ( & V_14 -> V_165 , V_145 ) ;
if ( ( ! V_14 -> V_166 && ! ( V_14 -> V_167 &
V_168 ) ) ||
( ( ! V_14 -> V_169 &&
( V_14 -> V_167 & V_168 ) ) ) ) {
F_4 ( V_170 L_4 ,
V_14 -> V_30 -> V_31 ) ;
goto V_171;
}
if ( F_36 ( V_14 -> V_172 == 0 ) ) {
if ( F_8 ( V_44 -> V_32 < V_12 + sizeof( T_2 ) ) ) {
F_4 ( V_170 L_5 ,
V_14 -> V_30 -> V_31 , V_44 -> V_32 ) ;
goto V_171;
}
memcpy ( V_157 , V_44 -> V_1 , V_158 ) ;
memcpy ( V_159 , V_44 -> V_1 + V_158 , V_158 ) ;
memset ( V_44 -> V_43 , 0 , sizeof( V_44 -> V_43 ) ) ;
V_148 = F_37 ( ( (struct V_46 * ) V_44 -> V_1 ) -> V_2 ) ;
if ( V_14 -> V_85 == V_173 ) {
V_36 = F_10 ( 1 , V_44 -> V_32 , V_174 ) ;
if ( F_8 ( ! V_36 ) ) {
F_4 ( V_170 L_6
L_7 ,
V_14 -> V_30 -> V_31 ) ;
goto V_175;
}
V_36 -> V_176 = 0 ;
V_36 -> V_177 = F_12 ( V_44 -> V_32 ) ;
memcpy ( F_38 ( V_36 -> V_42 [ 0 ] , V_44 -> V_32 ) , V_44 -> V_1 ,
V_44 -> V_32 ) ;
goto V_171;
}
if ( V_44 -> V_32 > 282 ) {
if ( V_50 == V_148 ) {
const struct V_48 * V_49 = (struct V_48 * )
( ( T_1 * ) V_44 -> V_1 + 14 ) ;
if ( V_178 == V_49 -> V_179 ) {
struct V_180 * V_181 ;
V_181 = (struct V_180 * ) ( ( T_1 * ) V_49 +
( V_49 -> V_182 << 2 ) ) ;
if ( ( ( ( ( T_1 * ) V_181 ) [ 1 ] == 68 ) &&
( ( ( T_1 * ) V_181 ) [ 3 ] == 67 ) ) ||
( ( ( ( T_1 * ) V_181 ) [ 1 ] == 67 ) &&
( ( ( T_1 * ) V_181 ) [ 3 ] == 68 ) ) ) {
V_64 = true ;
V_14 -> V_183 = 200 ;
}
}
} else if ( V_184 == V_148 ) {
F_4 ( V_24 L_8
L_9 ) ;
V_64 = true ;
V_14 -> V_183 =
V_14 -> V_100 . V_185 . V_186 ;
}
}
V_44 -> V_71 = F_15 ( V_44 , V_164 ) ;
V_19 = V_14 -> V_21 . V_19 [ V_14 -> V_21 . V_22 ] ;
V_149 = ! ( V_148 == V_187 && V_14 -> V_188 ) &&
V_14 -> V_189 && V_19 && V_19 -> V_23 ;
if ( ! V_149 && V_14 -> V_188 &&
V_14 -> V_190 && V_148 != V_187 ) {
V_147 -> V_191 ++ ;
goto V_171;
}
if ( V_19 && ! V_149 && V_148 == V_187 ) {
struct V_192 * V_193 = (struct V_192 * ) ( V_44 -> V_1 +
sizeof( struct V_46 ) - V_12 -
sizeof( T_2 ) ) ;
F_39 ( L_10 ,
F_40 ( V_193 -> type ) ) ;
}
F_41 ( V_44 , sizeof( struct V_46 ) ) ;
V_150 = V_44 -> V_32 + V_12 + sizeof( T_2 ) ;
if ( V_149 )
V_151 = V_194 | V_195 ;
else
V_151 = V_194 ;
if ( V_160 )
V_151 |= V_196 ;
else
V_151 |= V_197 ;
if ( V_14 -> V_85 == V_86 ) {
V_151 |= V_198 ;
memcpy ( & V_154 . V_63 , V_14 -> V_100 . V_199 ,
V_158 ) ;
memcpy ( & V_154 . V_200 , & V_159 , V_158 ) ;
if ( V_164 )
memcpy ( & V_154 . V_201 ,
V_14 -> V_100 . V_199 , V_158 ) ;
else
memcpy ( & V_154 . V_201 , & V_157 , V_158 ) ;
} else if ( V_14 -> V_85 == V_135 ) {
memcpy ( & V_154 . V_63 , V_157 , V_158 ) ;
memcpy ( & V_154 . V_200 , V_159 , V_158 ) ;
memcpy ( & V_154 . V_201 , V_14 -> V_100 . V_199 ,
V_158 ) ;
}
V_163 = F_21 ( V_154 . V_63 ) ;
V_154 . V_202 = F_12 ( V_151 ) ;
if ( V_163 ) {
V_41 = V_203 ;
V_152 |= V_204 ;
} else {
V_41 = V_14 -> V_205 ;
V_152 = 0 ;
}
if ( V_160 ) {
V_17 = V_206 + 2 ;
while ( F_8 ( V_14 -> V_207 & ( 0x01 << V_44 -> V_71 ) ) ) {
F_4 ( V_24 L_11 , V_44 -> V_71 ) ;
if ( F_32 ( V_44 ) )
break;
F_4 ( V_24 L_12 ,
V_44 -> V_71 ) ;
}
V_152 |= V_44 -> V_71 ;
V_154 . V_152 = F_12 ( V_152 & V_208 ) ;
} else {
V_17 = V_206 ;
}
V_143 = V_41 - V_17 ;
if ( V_14 -> V_209 &
( V_210 | V_211 ) )
V_143 -= V_212 ;
if ( V_149 ) {
V_143 -= V_19 -> V_23 -> V_213 +
V_19 -> V_23 -> V_214 +
V_19 -> V_23 -> V_215 +
V_19 -> V_23 -> V_216 ;
}
V_37 = V_150 / V_143 ;
V_144 = V_150 % V_143 ;
if ( V_144 )
V_37 ++ ;
else
V_144 = V_143 ;
V_36 = F_10 ( V_37 , V_41 +
V_14 -> V_217 , V_174 ) ;
if ( F_8 ( ! V_36 ) ) {
F_4 ( V_170 L_13 ,
V_14 -> V_30 -> V_31 ) ;
goto V_175;
}
V_36 -> V_176 = V_149 ;
V_36 -> V_177 = F_12 ( V_150 ) ;
if ( V_160 )
V_36 -> V_218 = F_42 ( V_44 -> V_71 ) ;
else
V_36 -> V_218 = V_219 ;
for ( V_40 = 0 ; V_40 < V_37 ; V_40 ++ ) {
V_153 = V_36 -> V_42 [ V_40 ] ;
V_54 = (struct V_53 * ) ( V_153 -> V_43 +
V_220 ) ;
if ( V_160 ) {
V_153 -> V_71 = V_44 -> V_71 ;
V_54 -> V_218 = F_42 ( V_44 -> V_71 ) ;
} else {
V_153 -> V_71 = V_219 ;
V_54 -> V_218 = V_219 ;
}
F_43 ( V_153 , V_14 -> V_217 ) ;
if ( V_149 ) {
if ( V_14 -> V_221 )
V_54 -> V_222 = 1 ;
else
V_54 -> V_222 = 0 ;
F_43 ( V_153 ,
V_19 -> V_23 -> V_213 +
V_19 -> V_23 -> V_215 ) ;
} else {
V_54 -> V_222 = 0 ;
}
V_142 = (struct V_141 * )
F_38 ( V_153 , V_17 ) ;
memcpy ( V_142 , & V_154 , V_17 ) ;
if ( V_40 != V_37 - 1 ) {
V_142 -> V_202 = F_12 (
V_151 | V_223 ) ;
V_150 = V_143 ;
} else {
V_150 = V_144 ;
}
if ( ( V_160 ) && ( ! V_163 ) ) {
V_142 -> V_156 =
F_12 ( F_31 ( V_14 , V_153 ,
V_154 . V_63 ) ) ;
V_142 -> V_156 =
F_12 ( F_44 ( V_142 -> V_156 ) << 4 | V_40 ) ;
} else {
V_142 -> V_156 =
F_12 ( V_14 -> V_224 [ 0 ] << 4 | V_40 ) ;
}
if ( V_40 == 0 ) {
F_1 (
F_38 ( V_153 , V_12 +
sizeof( T_2 ) ) , V_148 ) ;
V_150 -= V_12 + sizeof( T_2 ) ;
}
memcpy ( F_38 ( V_153 , V_150 ) , V_44 -> V_1 , V_150 ) ;
F_41 ( V_44 , V_150 ) ;
if ( V_149 )
F_3 ( V_14 , V_153 ,
V_17 ) ;
if ( V_14 -> V_209 &
( V_210 | V_211 ) )
F_38 ( V_153 , 4 ) ;
}
if ( ( V_160 ) && ( ! V_163 ) ) {
if ( V_14 -> V_224 [ F_42 ( V_44 -> V_71 ) + 1 ] == 0xFFF )
V_14 -> V_224 [ F_42 ( V_44 -> V_71 ) + 1 ] = 0 ;
else
V_14 -> V_224 [ F_42 ( V_44 -> V_71 ) + 1 ] ++ ;
} else {
if ( V_14 -> V_224 [ 0 ] == 0xFFF )
V_14 -> V_224 [ 0 ] = 0 ;
else
V_14 -> V_224 [ 0 ] ++ ;
}
} else {
if ( F_8 ( V_44 -> V_32 < sizeof( struct V_225 ) ) ) {
F_4 ( V_170 L_5 ,
V_14 -> V_30 -> V_31 , V_44 -> V_32 ) ;
goto V_171;
}
V_36 = F_10 ( 1 , V_44 -> V_32 , V_174 ) ;
if ( ! V_36 ) {
F_4 ( V_170 L_13 ,
V_14 -> V_30 -> V_31 ) ;
goto V_175;
}
V_36 -> V_176 = 0 ;
V_36 -> V_177 = F_12 ( V_44 -> V_32 ) ;
memcpy ( F_38 ( V_36 -> V_42 [ 0 ] , V_44 -> V_32 ) , V_44 -> V_1 ,
V_44 -> V_32 ) ;
}
V_171:
if ( V_36 ) {
struct V_53 * V_54 = (struct V_53 * )
( V_36 -> V_42 [ 0 ] -> V_43 + V_220 ) ;
V_54 -> V_226 = 1 ;
V_54 -> V_71 = V_44 -> V_71 ;
if ( V_148 == V_187 ) {
if ( V_14 -> V_56 -> V_66 &
V_227 ) {
V_54 -> V_99 =
F_45 ( V_14 ) ;
V_54 -> V_133 = false ;
} else {
V_54 -> V_99 = V_14 -> V_228 ;
V_54 -> V_133 = 1 ;
}
V_54 -> V_136 = 7 ;
V_54 -> V_134 = 1 ;
} else {
if ( F_21 ( V_154 . V_63 ) )
V_54 -> V_109 = 1 ;
if ( F_29 ( V_154 . V_63 ) )
V_54 -> V_110 = 1 ;
F_30 ( V_14 , V_54 ) ;
if ( V_54 -> V_109 || V_54 -> V_110 )
V_54 -> V_99 = V_14 -> V_228 ;
else
V_54 -> V_99 = F_46 ( V_14 -> V_119 ,
V_14 -> V_229 , V_14 -> V_230 ) ;
if ( V_64 ) {
if ( V_14 -> V_56 -> V_66 &
V_227 ) {
V_54 -> V_99 =
F_45 ( V_14 ) ;
V_54 -> V_133 = false ;
} else {
V_54 -> V_99 = V_231 ;
V_54 -> V_133 = 1 ;
}
V_54 -> V_136 = 7 ;
V_54 -> V_134 = 1 ;
V_54 -> V_64 = 1 ;
}
F_25 ( V_14 , V_54 ) ;
F_18 ( V_14 , V_36 -> V_42 [ 0 ] ,
V_54 ) ;
F_26 ( V_14 , V_54 ) ;
F_27 ( V_14 , V_54 ) ;
F_28 ( V_14 , V_54 ,
V_36 -> V_42 [ 0 ] ) ;
}
}
F_47 ( & V_14 -> V_165 , V_145 ) ;
F_14 ( V_44 ) ;
if ( V_36 ) {
if ( V_14 -> V_167 & V_168 ) {
V_30 -> V_147 . V_232 ++ ;
V_30 -> V_147 . V_233 += F_44 ( V_36 -> V_177 ) ;
F_48 ( V_36 , V_14 ) ;
} else {
if ( (* V_14 -> V_166 )( V_36 , V_30 ) == 0 ) {
V_147 -> V_232 ++ ;
V_147 -> V_233 += F_44 ( V_36 -> V_177 ) ;
return 0 ;
}
F_7 ( V_36 ) ;
}
}
return 0 ;
V_175:
F_47 ( & V_14 -> V_165 , V_145 ) ;
F_49 ( V_30 ) ;
V_147 -> V_234 ++ ;
return 1 ;
}
int F_50 ( struct V_15 * V_44 , struct V_140 * V_30 )
{
memset ( V_44 -> V_43 , 0 , sizeof( V_44 -> V_43 ) ) ;
return F_33 ( V_44 , V_30 ) ;
}
