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
* ( T_2 * ) ( V_1 + V_11 ) = F_2 ( V_2 ) ;
return V_11 + sizeof( T_2 ) ;
}
int F_3 ( struct V_12 * V_13 , struct V_14 * V_15 ,
int V_16 )
{
struct V_17 * V_18 = NULL ;
int V_19 ;
V_18 = V_13 -> V_20 . V_18 [ V_13 -> V_20 . V_21 ] ;
if ( ! ( V_18 && V_18 -> V_22 ) ) {
F_4 ( V_23 L_1 , V_24 ) ;
return - 1 ;
}
F_5 ( & V_18 -> V_25 ) ;
V_19 = 0 ;
if ( V_18 -> V_22 -> V_26 )
V_19 = V_18 -> V_22 -> V_26 ( V_15 , V_16 , V_18 -> V_27 ) ;
if ( V_19 == 0 && V_18 -> V_22 -> V_28 )
V_19 = V_18 -> V_22 -> V_28 ( V_15 , V_16 , V_18 -> V_27 ) ;
F_6 ( & V_18 -> V_25 ) ;
if ( V_19 < 0 ) {
F_4 ( V_23 L_2 ,
V_13 -> V_29 -> V_30 , V_15 -> V_31 ) ;
V_13 -> V_32 . V_33 ++ ;
return - 1 ;
}
return 0 ;
}
void F_7 ( struct V_34 * V_35 )
{
if ( F_8 ( ! V_35 ) )
return;
F_9 ( V_35 ) ;
}
static struct V_34 * F_10 ( int V_36 , int V_37 ,
T_3 V_38 )
{
struct V_34 * V_35 ;
int V_39 ;
V_35 = F_11 ( sizeof( struct V_34 ) + ( sizeof( T_1 * ) * V_36 ) ,
V_38 ) ;
if ( ! V_35 )
return NULL ;
memset ( V_35 , 0 , sizeof( struct V_34 ) ) ;
V_35 -> V_36 = V_36 ;
V_35 -> V_40 = V_37 ;
for ( V_39 = 0 ; V_39 < V_36 ; V_39 ++ ) {
V_35 -> V_41 [ V_39 ] = F_12 ( V_37 ) ;
if ( F_8 ( ! V_35 -> V_41 [ V_39 ] ) ) {
V_39 -- ;
break;
}
memset ( V_35 -> V_41 [ V_39 ] -> V_42 , 0 , sizeof( V_35 -> V_41 [ V_39 ] -> V_42 ) ) ;
}
if ( F_8 ( V_39 != V_36 ) ) {
while ( V_39 >= 0 )
F_13 ( V_35 -> V_41 [ V_39 -- ] ) ;
F_9 ( V_35 ) ;
return NULL ;
}
return V_35 ;
}
static int F_14 ( struct V_14 * V_43 , T_1 V_44 )
{
struct V_45 * V_46 ;
struct V_47 * V_48 ;
V_46 = (struct V_45 * ) V_43 -> V_1 ;
if ( V_46 -> V_2 != F_2 ( V_49 ) )
return 0 ;
F_15 ( V_50 , V_43 -> V_1 , V_43 -> V_31 ) ;
V_48 = F_16 ( V_43 ) ;
switch ( V_48 -> V_51 & 0xfc ) {
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
static void F_17 ( struct V_12 * V_13 ,
struct V_14 * V_43 ,
struct V_52 * V_53 )
{
struct V_54 * V_55 = V_13 -> V_55 ;
struct V_56 * V_57 = NULL ;
struct V_58 * V_59 = (struct V_58 * ) V_43 -> V_1 ;
if ( F_18 ( V_13 , false ) )
return;
if ( ! V_55 -> V_60 || ! V_55 -> V_61 )
return;
if ( ! F_19 ( V_43 -> V_1 ) )
return;
if ( F_20 ( V_59 -> V_62 ) )
return;
if ( V_53 -> V_63 || V_13 -> V_64 < 2 )
return;
if ( V_55 -> V_65 & V_66 )
return;
if ( ! V_13 -> V_67 ( V_13 -> V_29 ) )
return;
if ( V_55 -> V_68 ) {
if ( ! F_21 ( V_13 , (struct V_69 * * ) ( & V_57 ) , V_59 -> V_62 ,
V_43 -> V_70 , V_71 , true ) ) {
F_4 ( V_23 L_3 , V_24 ) ;
return;
}
if ( V_57 -> V_72 . V_73 == false ) {
if ( V_13 -> V_74 && ( V_13 -> V_75 ==
V_76 ) ) {
;
} else if ( V_53 -> V_63 == 1 ) {
;
} else if ( ! V_57 -> V_77 ) {
F_22 ( V_13 , V_57 ) ;
}
goto V_78;
} else if ( V_57 -> V_79 == false ) {
if ( F_23 ( V_57 -> V_72 . V_80 . V_81 . V_82 ,
( V_57 -> V_83 + 1 ) % 4096 ) )
V_57 -> V_79 = true ;
else
goto V_78;
}
if ( V_13 -> V_84 == V_85 ) {
V_53 -> V_86 = true ;
V_53 -> V_87 = V_55 -> V_88 ;
V_53 -> V_89 = V_55 -> V_90 ;
}
}
V_78:
switch ( V_55 -> V_91 ) {
case V_92 :
break;
case V_93 :
V_53 -> V_86 = true ;
V_53 -> V_89 = V_55 -> V_94 ;
V_53 -> V_87 = V_55 -> V_95 ;
break;
case V_96 :
V_53 -> V_86 = false ;
V_53 -> V_89 = 0 ;
V_53 -> V_87 = 0 ;
break;
}
return;
}
static void F_24 ( struct V_12 * V_13 ,
struct V_52 * V_53 )
{
V_53 -> V_97 = false ;
if ( V_53 -> V_98 == 2 )
return;
else if ( V_13 -> V_99 . V_100 &
V_101 )
V_53 -> V_97 = true ;
return;
}
static void F_25 ( struct V_12 * V_13 ,
struct V_52 * V_53 )
{
struct V_54 * V_55 = V_13 -> V_55 ;
V_53 -> V_102 = false ;
if ( ! V_55 -> V_60 || ! V_55 -> V_61 )
return;
if ( V_55 -> V_103 ) {
V_53 -> V_102 = true ;
return;
}
if ( ( V_55 -> V_104 == true ) && V_55 -> V_105 )
V_53 -> V_102 = true ;
else if ( ( V_55 -> V_104 == false ) && V_55 -> V_106 )
V_53 -> V_102 = true ;
}
static void F_26 ( struct V_12 * V_13 ,
struct V_52 * V_53 )
{
struct V_54 * V_55 = V_13 -> V_55 ;
V_53 -> V_107 = false ;
if ( ! V_55 -> V_60 || ! V_55 -> V_61 )
return;
if ( V_53 -> V_108 || V_53 -> V_109 )
return;
if ( ( V_53 -> V_98 & 0x80 ) == 0 )
return;
if ( V_55 -> V_104 && V_55 -> V_110 &&
! V_13 -> V_111 . V_112 )
V_53 -> V_107 = true ;
return;
}
static void F_27 ( struct V_12 * V_13 ,
struct V_52 * V_53 ,
struct V_14 * V_43 )
{
V_53 -> V_113 = false ;
V_53 -> V_114 = false ;
V_53 -> V_115 = false ;
V_53 -> V_116 = 0 ;
V_53 -> V_117 = false ;
if ( V_53 -> V_109 || V_53 -> V_108 )
return;
if ( F_28 ( V_43 -> V_1 + 16 ) )
return;
if ( V_13 -> V_118 < V_119 ) {
if ( V_43 -> V_31 > V_13 -> V_120 ) {
V_53 -> V_121 = true ;
V_53 -> V_122 = V_123 ;
} else if ( V_13 -> V_99 . V_124 ) {
V_53 -> V_121 = true ;
V_53 -> V_115 = true ;
V_53 -> V_122 = V_123 ;
}
return;
} else {
struct V_54 * V_55 = V_13 -> V_55 ;
while ( true ) {
if ( V_55 -> V_65 & V_125 ) {
V_53 -> V_115 = true ;
V_53 -> V_122 = V_123 ;
V_53 -> V_121 = true ;
break;
} else if ( V_55 -> V_65 & ( V_126 |
V_127 ) ) {
V_53 -> V_121 = true ;
V_53 -> V_122 = V_123 ;
break;
}
if ( V_13 -> V_99 . V_124 ) {
V_53 -> V_121 = true ;
V_53 -> V_115 = true ;
V_53 -> V_122 = V_123 ;
break;
}
if ( V_55 -> V_60 && V_55 -> V_61 ) {
T_1 V_128 = V_55 -> V_129 ;
if ( ( V_55 -> V_104 && ( V_128 == 2 ||
V_128 == 3 ) ) ||
( ! V_55 -> V_104 && V_128 == 3 ) ) {
V_53 -> V_122 = V_123 ;
V_53 -> V_121 = true ;
break;
}
}
if ( V_43 -> V_31 > V_13 -> V_120 ) {
V_53 -> V_122 = V_123 ;
V_53 -> V_121 = true ;
break;
}
if ( V_53 -> V_86 ) {
V_53 -> V_122 = V_123 ;
V_53 -> V_121 = false ;
break;
}
goto V_130;
}
}
if ( V_13 -> V_99 . V_100 & V_101 )
V_53 -> V_97 = true ;
if ( V_13 -> V_84 == V_131 )
goto V_130;
return;
V_130:
V_53 -> V_121 = false ;
V_53 -> V_115 = false ;
V_53 -> V_122 = 0 ;
V_53 -> V_116 = 0 ;
V_53 -> V_117 = false ;
}
static void F_29 ( struct V_12 * V_13 ,
struct V_52 * V_53 )
{
if ( V_13 -> V_132 )
V_53 -> V_132 = true ;
if ( V_13 -> V_133 )
V_53 -> V_133 = true ;
if ( ! V_53 -> V_132 ||
! V_53 -> V_133 ) {
if ( V_13 -> V_84 == V_85 ||
V_13 -> V_84 == V_134 )
V_53 -> V_135 = 0 ;
}
}
T_2 F_30 ( struct V_12 * V_13 , struct V_14 * V_43 ,
T_1 * V_136 )
{
T_2 V_137 = 0 ;
if ( F_20 ( V_136 ) )
return 0 ;
if ( F_19 ( V_43 -> V_1 ) ) {
struct V_56 * V_138 = NULL ;
if ( ! F_21 ( V_13 , (struct V_69 * * ) ( & V_138 ) , V_136 ,
V_43 -> V_70 , V_71 , true ) )
return 0 ;
V_137 = V_138 -> V_83 ;
V_138 -> V_83 = ( V_138 -> V_83 + 1 ) % 4096 ;
return V_137 ;
}
return 0 ;
}
static int F_31 ( struct V_14 * V_43 )
{
switch ( V_43 -> V_70 ) {
case 6 :
case 7 :
V_43 -> V_70 = 5 ;
return 0 ;
case 4 :
case 5 :
V_43 -> V_70 = 3 ;
return 0 ;
case 0 :
case 3 :
V_43 -> V_70 = 1 ;
return 0 ;
default:
return - 1 ;
}
}
int F_32 ( struct V_14 * V_43 , struct V_139 * V_29 )
{
struct V_12 * V_13 = (struct V_12 * )
F_33 ( V_29 ) ;
struct V_34 * V_35 = NULL ;
struct V_140 * V_141 ;
int V_39 , V_142 , V_36 , V_143 , V_40 ;
unsigned long V_144 ;
struct V_145 * V_146 = & V_13 -> V_146 ;
int V_147 = 0 , V_148 ;
int V_149 , V_150 , V_151 = 0 , V_16 ;
struct V_14 * V_152 ;
struct V_140 V_153 = {
. V_154 = 0 ,
. V_155 = 0 ,
. V_151 = 0
} ;
T_1 V_156 [ V_157 ] , V_158 [ V_157 ] ;
int V_159 = V_13 -> V_99 . V_160 . V_161 ;
struct V_17 * V_18 = NULL ;
struct V_52 * V_53 ;
T_1 V_162 = false ;
T_1 V_163 = false ;
bool V_63 = false ;
F_34 ( & V_13 -> V_164 , V_144 ) ;
if ( ( ! V_13 -> V_165 && ! ( V_13 -> V_166 &
V_167 ) ) ||
( ( ! V_13 -> V_168 &&
( V_13 -> V_166 & V_167 ) ) ) ) {
F_4 ( V_169 L_4 ,
V_13 -> V_29 -> V_30 ) ;
goto V_170;
}
if ( F_35 ( V_13 -> V_171 == 0 ) ) {
if ( F_8 ( V_43 -> V_31 < V_11 + sizeof( T_2 ) ) ) {
F_4 ( V_169 L_5 ,
V_13 -> V_29 -> V_30 , V_43 -> V_31 ) ;
goto V_170;
}
memcpy ( V_156 , V_43 -> V_1 , V_157 ) ;
memcpy ( V_158 , V_43 -> V_1 + V_157 , V_157 ) ;
memset ( V_43 -> V_42 , 0 , sizeof( V_43 -> V_42 ) ) ;
V_147 = F_36 ( ( (struct V_45 * ) V_43 -> V_1 ) -> V_2 ) ;
if ( V_13 -> V_84 == V_172 ) {
V_35 = F_10 ( 1 , V_43 -> V_31 , V_173 ) ;
if ( F_8 ( ! V_35 ) ) {
F_4 ( V_169 L_6
L_7 ,
V_13 -> V_29 -> V_30 ) ;
goto V_174;
}
V_35 -> V_175 = 0 ;
V_35 -> V_176 = V_43 -> V_31 ;
memcpy ( F_37 ( V_35 -> V_41 [ 0 ] , V_43 -> V_31 ) , V_43 -> V_1 ,
V_43 -> V_31 ) ;
goto V_170;
}
if ( V_43 -> V_31 > 282 ) {
if ( V_49 == V_147 ) {
const struct V_47 * V_48 = (struct V_47 * )
( ( T_1 * ) V_43 -> V_1 + 14 ) ;
if ( V_177 == V_48 -> V_178 ) {
struct V_179 * V_180 ;
V_180 = (struct V_179 * ) ( ( T_1 * ) V_48 +
( V_48 -> V_181 << 2 ) ) ;
if ( ( ( ( ( T_1 * ) V_180 ) [ 1 ] == 68 ) &&
( ( ( T_1 * ) V_180 ) [ 3 ] == 67 ) ) ||
( ( ( ( T_1 * ) V_180 ) [ 1 ] == 67 ) &&
( ( ( T_1 * ) V_180 ) [ 3 ] == 68 ) ) ) {
V_63 = true ;
V_13 -> V_182 = 200 ;
}
}
} else if ( V_183 == V_147 ) {
F_4 ( V_23 L_8
L_9 ) ;
V_63 = true ;
V_13 -> V_182 =
V_13 -> V_99 . V_184 . V_185 ;
}
}
V_43 -> V_70 = F_14 ( V_43 , V_163 ) ;
V_18 = V_13 -> V_20 . V_18 [ V_13 -> V_20 . V_21 ] ;
V_148 = ! ( V_147 == V_186 && V_13 -> V_187 ) &&
V_13 -> V_188 && V_18 && V_18 -> V_22 ;
if ( ! V_148 && V_13 -> V_187 &&
V_13 -> V_189 && V_147 != V_186 ) {
V_146 -> V_190 ++ ;
goto V_170;
}
if ( V_18 && ! V_148 && V_147 == V_186 ) {
struct V_191 * V_192 = (struct V_191 * ) ( V_43 -> V_1 +
sizeof( struct V_45 ) - V_11 -
sizeof( T_2 ) ) ;
F_38 ( L_10 ,
F_39 ( V_192 -> type ) ) ;
}
F_40 ( V_43 , sizeof( struct V_45 ) ) ;
V_149 = V_43 -> V_31 + V_11 + sizeof( T_2 ) ;
if ( V_148 )
V_150 = V_193 | V_194 ;
else
V_150 = V_193 ;
if ( V_159 )
V_150 |= V_195 ;
else
V_150 |= V_196 ;
if ( V_13 -> V_84 == V_85 ) {
V_150 |= V_197 ;
memcpy ( & V_153 . V_62 , V_13 -> V_99 . V_198 ,
V_157 ) ;
memcpy ( & V_153 . V_199 , & V_158 , V_157 ) ;
if ( V_163 )
memcpy ( & V_153 . V_200 ,
V_13 -> V_99 . V_198 , V_157 ) ;
else
memcpy ( & V_153 . V_200 , & V_156 , V_157 ) ;
} else if ( V_13 -> V_84 == V_134 ) {
memcpy ( & V_153 . V_62 , V_156 , V_157 ) ;
memcpy ( & V_153 . V_199 , V_158 , V_157 ) ;
memcpy ( & V_153 . V_200 , V_13 -> V_99 . V_198 ,
V_157 ) ;
}
V_162 = F_20 ( V_153 . V_62 ) ;
V_153 . V_201 = F_41 ( V_150 ) ;
if ( V_162 ) {
V_40 = V_202 ;
V_151 |= V_203 ;
} else {
V_40 = V_13 -> V_204 ;
V_151 = 0 ;
}
if ( V_159 ) {
V_16 = V_205 + 2 ;
while ( F_8 ( V_13 -> V_206 & ( 0x01 << V_43 -> V_70 ) ) ) {
F_4 ( V_23 L_11 , V_43 -> V_70 ) ;
if ( F_31 ( V_43 ) )
break;
F_4 ( V_23 L_12 ,
V_43 -> V_70 ) ;
}
V_151 |= V_43 -> V_70 ;
V_153 . V_151 = F_41 ( V_151 & V_207 ) ;
} else {
V_16 = V_205 ;
}
V_142 = V_40 - V_16 ;
if ( V_13 -> V_208 &
( V_209 | V_210 ) )
V_142 -= V_211 ;
if ( V_148 ) {
V_142 -= V_18 -> V_22 -> V_212 +
V_18 -> V_22 -> V_213 +
V_18 -> V_22 -> V_214 +
V_18 -> V_22 -> V_215 ;
}
V_36 = V_149 / V_142 ;
V_143 = V_149 % V_142 ;
if ( V_143 )
V_36 ++ ;
else
V_143 = V_142 ;
V_35 = F_10 ( V_36 , V_40 +
V_13 -> V_216 , V_173 ) ;
if ( F_8 ( ! V_35 ) ) {
F_4 ( V_169 L_13 ,
V_13 -> V_29 -> V_30 ) ;
goto V_174;
}
V_35 -> V_175 = V_148 ;
V_35 -> V_176 = V_149 ;
if ( V_159 )
V_35 -> V_217 = F_42 ( V_43 -> V_70 ) ;
else
V_35 -> V_217 = V_218 ;
for ( V_39 = 0 ; V_39 < V_36 ; V_39 ++ ) {
V_152 = V_35 -> V_41 [ V_39 ] ;
V_53 = (struct V_52 * ) ( V_152 -> V_42 +
V_219 ) ;
if ( V_159 ) {
V_152 -> V_70 = V_43 -> V_70 ;
V_53 -> V_217 = F_42 ( V_43 -> V_70 ) ;
} else {
V_152 -> V_70 = V_218 ;
V_53 -> V_217 = V_218 ;
}
F_43 ( V_152 , V_13 -> V_216 ) ;
if ( V_148 ) {
if ( V_13 -> V_220 )
V_53 -> V_221 = 1 ;
else
V_53 -> V_221 = 0 ;
F_43 ( V_152 ,
V_18 -> V_22 -> V_212 +
V_18 -> V_22 -> V_214 ) ;
} else {
V_53 -> V_221 = 0 ;
}
V_141 = (struct V_140 * )
F_37 ( V_152 , V_16 ) ;
memcpy ( V_141 , & V_153 , V_16 ) ;
if ( V_39 != V_36 - 1 ) {
V_141 -> V_201 = F_41 (
V_150 | V_222 ) ;
V_149 = V_142 ;
} else {
V_149 = V_143 ;
}
if ( ( V_159 ) && ( ! V_162 ) ) {
V_141 -> V_155 =
F_30 ( V_13 , V_152 ,
V_153 . V_62 ) ;
V_141 -> V_155 =
F_41 ( V_141 -> V_155 << 4 | V_39 ) ;
} else {
V_141 -> V_155 =
F_41 ( V_13 -> V_223 [ 0 ] << 4 | V_39 ) ;
}
if ( V_39 == 0 ) {
F_1 (
F_37 ( V_152 , V_11 +
sizeof( T_2 ) ) , V_147 ) ;
V_149 -= V_11 + sizeof( T_2 ) ;
}
memcpy ( F_37 ( V_152 , V_149 ) , V_43 -> V_1 , V_149 ) ;
F_40 ( V_43 , V_149 ) ;
if ( V_148 )
F_3 ( V_13 , V_152 ,
V_16 ) ;
if ( V_13 -> V_208 &
( V_209 | V_210 ) )
F_37 ( V_152 , 4 ) ;
}
if ( ( V_159 ) && ( ! V_162 ) ) {
if ( V_13 -> V_223 [ F_42 ( V_43 -> V_70 ) + 1 ] == 0xFFF )
V_13 -> V_223 [ F_42 ( V_43 -> V_70 ) + 1 ] = 0 ;
else
V_13 -> V_223 [ F_42 ( V_43 -> V_70 ) + 1 ] ++ ;
} else {
if ( V_13 -> V_223 [ 0 ] == 0xFFF )
V_13 -> V_223 [ 0 ] = 0 ;
else
V_13 -> V_223 [ 0 ] ++ ;
}
} else {
if ( F_8 ( V_43 -> V_31 < sizeof( struct V_224 ) ) ) {
F_4 ( V_169 L_5 ,
V_13 -> V_29 -> V_30 , V_43 -> V_31 ) ;
goto V_170;
}
V_35 = F_10 ( 1 , V_43 -> V_31 , V_173 ) ;
if ( ! V_35 ) {
F_4 ( V_169 L_13 ,
V_13 -> V_29 -> V_30 ) ;
goto V_174;
}
V_35 -> V_175 = 0 ;
V_35 -> V_176 = V_43 -> V_31 ;
memcpy ( F_37 ( V_35 -> V_41 [ 0 ] , V_43 -> V_31 ) , V_43 -> V_1 ,
V_43 -> V_31 ) ;
}
V_170:
if ( V_35 ) {
struct V_52 * V_53 = (struct V_52 * )
( V_35 -> V_41 [ 0 ] -> V_42 + V_219 ) ;
V_53 -> V_225 = 1 ;
V_53 -> V_70 = V_43 -> V_70 ;
if ( V_147 == V_186 ) {
if ( V_13 -> V_55 -> V_65 &
V_226 ) {
V_53 -> V_98 =
F_44 ( V_13 ) ;
V_53 -> V_132 = false ;
} else {
V_53 -> V_98 = V_13 -> V_227 ;
V_53 -> V_132 = 1 ;
}
V_53 -> V_135 = 7 ;
V_53 -> V_133 = 1 ;
} else {
if ( F_20 ( V_153 . V_62 ) )
V_53 -> V_108 = 1 ;
if ( F_28 ( V_153 . V_62 ) )
V_53 -> V_109 = 1 ;
F_29 ( V_13 , V_53 ) ;
if ( V_53 -> V_108 || V_53 -> V_109 )
V_53 -> V_98 = V_13 -> V_227 ;
else
V_53 -> V_98 = F_45 ( V_13 -> V_118 ,
V_13 -> V_228 , V_13 -> V_229 ) ;
if ( V_63 ) {
if ( V_13 -> V_55 -> V_65 &
V_226 ) {
V_53 -> V_98 =
F_44 ( V_13 ) ;
V_53 -> V_132 = false ;
} else {
V_53 -> V_98 = V_230 ;
V_53 -> V_132 = 1 ;
}
V_53 -> V_135 = 7 ;
V_53 -> V_133 = 1 ;
V_53 -> V_63 = 1 ;
}
F_24 ( V_13 , V_53 ) ;
F_17 ( V_13 , V_35 -> V_41 [ 0 ] ,
V_53 ) ;
F_25 ( V_13 , V_53 ) ;
F_26 ( V_13 , V_53 ) ;
F_27 ( V_13 , V_53 ,
V_35 -> V_41 [ 0 ] ) ;
}
}
F_46 ( & V_13 -> V_164 , V_144 ) ;
F_13 ( V_43 ) ;
if ( V_35 ) {
if ( V_13 -> V_166 & V_167 ) {
V_29 -> V_146 . V_231 ++ ;
V_29 -> V_146 . V_232 += V_35 -> V_176 ;
F_47 ( V_35 , V_13 ) ;
} else {
if ( (* V_13 -> V_165 )( V_35 , V_29 ) == 0 ) {
V_146 -> V_231 ++ ;
V_146 -> V_232 += V_35 -> V_176 ;
return 0 ;
}
F_7 ( V_35 ) ;
}
}
return 0 ;
V_174:
F_46 ( & V_13 -> V_164 , V_144 ) ;
F_48 ( V_29 ) ;
V_146 -> V_233 ++ ;
return 1 ;
}
int F_49 ( struct V_14 * V_43 , struct V_139 * V_29 )
{
memset ( V_43 -> V_42 , 0 , sizeof( V_43 -> V_42 ) ) ;
return F_32 ( V_43 , V_29 ) ;
}
