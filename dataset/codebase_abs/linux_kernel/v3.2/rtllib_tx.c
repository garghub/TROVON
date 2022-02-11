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
V_18 = V_13 -> V_18 [ V_13 -> V_20 ] ;
if ( ! ( V_18 && V_18 -> V_21 ) ) {
F_4 ( V_22 L_1 , V_23 ) ;
return - 1 ;
}
F_5 ( & V_18 -> V_24 ) ;
V_19 = 0 ;
if ( V_18 -> V_21 -> V_25 )
V_19 = V_18 -> V_21 -> V_25 ( V_15 , V_16 , V_18 -> V_26 ) ;
if ( V_19 == 0 && V_18 -> V_21 -> V_27 )
V_19 = V_18 -> V_21 -> V_27 ( V_15 , V_16 , V_18 -> V_26 ) ;
F_6 ( & V_18 -> V_24 ) ;
if ( V_19 < 0 ) {
F_4 ( V_22 L_2 ,
V_13 -> V_28 -> V_29 , V_15 -> V_30 ) ;
V_13 -> V_31 . V_32 ++ ;
return - 1 ;
}
return 0 ;
}
void F_7 ( struct V_33 * V_34 )
{
if ( F_8 ( ! V_34 ) )
return;
F_9 ( V_34 ) ;
}
static struct V_33 * F_10 ( int V_35 , int V_36 ,
T_3 V_37 )
{
struct V_33 * V_34 ;
int V_38 ;
V_34 = F_11 ( sizeof( struct V_33 ) + ( sizeof( T_1 * ) * V_35 ) ,
V_37 ) ;
if ( ! V_34 )
return NULL ;
memset ( V_34 , 0 , sizeof( struct V_33 ) ) ;
V_34 -> V_35 = V_35 ;
V_34 -> V_39 = V_36 ;
for ( V_38 = 0 ; V_38 < V_35 ; V_38 ++ ) {
V_34 -> V_40 [ V_38 ] = F_12 ( V_36 ) ;
if ( F_8 ( ! V_34 -> V_40 [ V_38 ] ) ) {
V_38 -- ;
break;
}
memset ( V_34 -> V_40 [ V_38 ] -> V_41 , 0 , sizeof( V_34 -> V_40 [ V_38 ] -> V_41 ) ) ;
}
if ( F_8 ( V_38 != V_35 ) ) {
while ( V_38 >= 0 )
F_13 ( V_34 -> V_40 [ V_38 -- ] ) ;
F_9 ( V_34 ) ;
return NULL ;
}
return V_34 ;
}
static int F_14 ( struct V_14 * V_42 , T_1 V_43 )
{
struct V_44 * V_45 ;
struct V_46 * V_47 ;
V_45 = (struct V_44 * ) V_42 -> V_1 ;
if ( V_45 -> V_2 != F_2 ( V_48 ) )
return 0 ;
F_15 ( V_49 , V_42 -> V_1 , V_42 -> V_30 ) ;
V_47 = F_16 ( V_42 ) ;
switch ( V_47 -> V_50 & 0xfc ) {
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
struct V_14 * V_42 ,
struct V_51 * V_52 )
{
struct V_53 * V_54 = V_13 -> V_54 ;
struct V_55 * V_56 = NULL ;
struct V_57 * V_58 = (struct V_57 * ) V_42 -> V_1 ;
if ( F_18 ( V_13 , false ) )
return;
if ( ! V_54 -> V_59 || ! V_54 -> V_60 )
return;
if ( ! F_19 ( V_42 -> V_1 ) )
return;
if ( F_20 ( V_58 -> V_61 ) ||
F_21 ( V_58 -> V_61 ) )
return;
if ( V_52 -> V_62 || V_13 -> V_63 < 2 )
return;
if ( V_54 -> V_64 & V_65 )
return;
if ( ! V_13 -> V_66 ( V_13 -> V_28 ) )
return;
if ( V_54 -> V_67 ) {
if ( ! F_22 ( V_13 , (struct V_68 * * ) ( & V_56 ) , V_58 -> V_61 ,
V_42 -> V_69 , V_70 , true ) ) {
F_4 ( V_22 L_3 , V_23 ) ;
return;
}
if ( V_56 -> V_71 . V_72 == false ) {
if ( V_13 -> V_73 && ( V_13 -> V_74 ==
V_75 ) ) {
;
} else if ( V_52 -> V_62 == 1 ) {
;
} else if ( ! V_56 -> V_76 ) {
F_23 ( V_13 , V_56 ) ;
}
goto V_77;
} else if ( V_56 -> V_78 == false ) {
if ( F_24 ( V_56 -> V_71 . V_79 . V_80 . V_81 ,
( V_56 -> V_82 + 1 ) % 4096 ) )
V_56 -> V_78 = true ;
else
goto V_77;
}
if ( V_13 -> V_83 == V_84 ) {
V_52 -> V_85 = true ;
V_52 -> V_86 = V_54 -> V_87 ;
V_52 -> V_88 = V_54 -> V_89 ;
}
}
V_77:
switch ( V_54 -> V_90 ) {
case V_91 :
break;
case V_92 :
V_52 -> V_85 = true ;
V_52 -> V_88 = V_54 -> V_93 ;
V_52 -> V_86 = V_54 -> V_94 ;
break;
case V_95 :
V_52 -> V_85 = false ;
V_52 -> V_88 = 0 ;
V_52 -> V_86 = 0 ;
break;
}
return;
}
static void F_25 ( struct V_12 * V_13 ,
struct V_51 * V_52 )
{
V_52 -> V_96 = false ;
if ( V_52 -> V_97 == 2 )
return;
else if ( V_13 -> V_98 . V_99 &
V_100 )
V_52 -> V_96 = true ;
return;
}
static void F_26 ( struct V_12 * V_13 ,
struct V_51 * V_52 )
{
struct V_53 * V_54 = V_13 -> V_54 ;
V_52 -> V_101 = false ;
if ( ! V_54 -> V_59 || ! V_54 -> V_60 )
return;
if ( V_54 -> V_102 ) {
V_52 -> V_101 = true ;
return;
}
if ( ( V_54 -> V_103 == true ) && V_54 -> V_104 )
V_52 -> V_101 = true ;
else if ( ( V_54 -> V_103 == false ) && V_54 -> V_105 )
V_52 -> V_101 = true ;
}
static void F_27 ( struct V_12 * V_13 ,
struct V_51 * V_52 )
{
struct V_53 * V_54 = V_13 -> V_54 ;
V_52 -> V_106 = false ;
if ( ! V_54 -> V_59 || ! V_54 -> V_60 )
return;
if ( V_52 -> V_107 || V_52 -> V_108 )
return;
if ( ( V_52 -> V_97 & 0x80 ) == 0 )
return;
if ( V_54 -> V_103 && V_54 -> V_109 &&
! V_13 -> V_110 . V_111 )
V_52 -> V_106 = true ;
return;
}
static void F_28 ( struct V_12 * V_13 ,
struct V_51 * V_52 ,
struct V_14 * V_42 )
{
V_52 -> V_112 = false ;
V_52 -> V_113 = false ;
V_52 -> V_114 = false ;
V_52 -> V_115 = 0 ;
V_52 -> V_116 = false ;
if ( V_52 -> V_108 || V_52 -> V_107 )
return;
if ( F_21 ( V_42 -> V_1 + 16 ) )
return;
if ( V_13 -> V_117 < V_118 ) {
if ( V_42 -> V_30 > V_13 -> V_119 ) {
V_52 -> V_120 = true ;
V_52 -> V_121 = V_122 ;
} else if ( V_13 -> V_98 . V_123 ) {
V_52 -> V_120 = true ;
V_52 -> V_114 = true ;
V_52 -> V_121 = V_122 ;
}
return;
} else {
struct V_53 * V_54 = V_13 -> V_54 ;
while ( true ) {
if ( V_54 -> V_64 & V_124 ) {
V_52 -> V_114 = true ;
V_52 -> V_121 = V_122 ;
V_52 -> V_120 = true ;
break;
} else if ( V_54 -> V_64 & ( V_125 |
V_126 ) ) {
V_52 -> V_120 = true ;
V_52 -> V_121 = V_122 ;
break;
}
if ( V_13 -> V_98 . V_123 ) {
V_52 -> V_120 = true ;
V_52 -> V_114 = true ;
V_52 -> V_121 = V_122 ;
break;
}
if ( V_54 -> V_59 && V_54 -> V_60 ) {
T_1 V_127 = V_54 -> V_128 ;
if ( ( V_54 -> V_103 && ( V_127 == 2 ||
V_127 == 3 ) ) ||
( ! V_54 -> V_103 && V_127 == 3 ) ) {
V_52 -> V_121 = V_122 ;
V_52 -> V_120 = true ;
break;
}
}
if ( V_42 -> V_30 > V_13 -> V_119 ) {
V_52 -> V_121 = V_122 ;
V_52 -> V_120 = true ;
break;
}
if ( V_52 -> V_85 ) {
V_52 -> V_121 = V_122 ;
V_52 -> V_120 = false ;
break;
}
goto V_129;
}
}
if ( V_13 -> V_98 . V_99 & V_100 )
V_52 -> V_96 = true ;
if ( V_13 -> V_83 == V_130 )
goto V_129;
return;
V_129:
V_52 -> V_120 = false ;
V_52 -> V_114 = false ;
V_52 -> V_121 = 0 ;
V_52 -> V_115 = 0 ;
V_52 -> V_116 = false ;
}
static void F_29 ( struct V_12 * V_13 ,
struct V_51 * V_52 )
{
if ( V_13 -> V_131 )
V_52 -> V_131 = true ;
if ( V_13 -> V_132 )
V_52 -> V_132 = true ;
if ( ! V_52 -> V_131 ||
! V_52 -> V_132 ) {
if ( V_13 -> V_83 == V_84 ||
V_13 -> V_83 == V_133 )
V_52 -> V_134 = 0 ;
}
}
T_2 F_30 ( struct V_12 * V_13 , struct V_14 * V_42 ,
T_1 * V_135 )
{
T_2 V_136 = 0 ;
if ( F_20 ( V_135 ) || F_21 ( V_135 ) )
return 0 ;
if ( F_19 ( V_42 -> V_1 ) ) {
struct V_55 * V_137 = NULL ;
if ( ! F_22 ( V_13 , (struct V_68 * * ) ( & V_137 ) , V_135 ,
V_42 -> V_69 , V_70 , true ) )
return 0 ;
V_136 = V_137 -> V_82 ;
V_137 -> V_82 = ( V_137 -> V_82 + 1 ) % 4096 ;
return V_136 ;
}
return 0 ;
}
static int F_31 ( struct V_14 * V_42 )
{
switch ( V_42 -> V_69 ) {
case 6 :
case 7 :
V_42 -> V_69 = 5 ;
return 0 ;
case 4 :
case 5 :
V_42 -> V_69 = 3 ;
return 0 ;
case 0 :
case 3 :
V_42 -> V_69 = 1 ;
return 0 ;
default:
return - 1 ;
}
}
int F_32 ( struct V_14 * V_42 , struct V_138 * V_28 )
{
struct V_12 * V_13 = (struct V_12 * )
F_33 ( V_28 ) ;
struct V_33 * V_34 = NULL ;
struct V_139 * V_140 ;
int V_38 , V_141 , V_35 , V_142 , V_39 ;
unsigned long V_143 ;
struct V_144 * V_145 = & V_13 -> V_145 ;
int V_146 = 0 , V_147 ;
int V_148 , V_149 , V_150 = 0 , V_16 ;
struct V_14 * V_151 ;
struct V_139 V_152 = {
. V_153 = 0 ,
. V_154 = 0 ,
. V_150 = 0
} ;
T_1 V_155 [ V_156 ] , V_157 [ V_156 ] ;
int V_158 = V_13 -> V_98 . V_159 . V_160 ;
struct V_17 * V_18 = NULL ;
struct V_51 * V_52 ;
T_1 V_161 = false ;
T_1 V_162 = false ;
bool V_62 = false ;
F_34 ( & V_13 -> V_163 , V_143 ) ;
if ( ( ! V_13 -> V_164 && ! ( V_13 -> V_165 &
V_166 ) ) ||
( ( ! V_13 -> V_167 &&
( V_13 -> V_165 & V_166 ) ) ) ) {
F_4 ( V_168 L_4 ,
V_13 -> V_28 -> V_29 ) ;
goto V_169;
}
if ( F_35 ( V_13 -> V_170 == 0 ) ) {
if ( F_8 ( V_42 -> V_30 < V_11 + sizeof( T_2 ) ) ) {
F_4 ( V_168 L_5 ,
V_13 -> V_28 -> V_29 , V_42 -> V_30 ) ;
goto V_169;
}
memcpy ( V_155 , V_42 -> V_1 , V_156 ) ;
memcpy ( V_157 , V_42 -> V_1 + V_156 , V_156 ) ;
memset ( V_42 -> V_41 , 0 , sizeof( V_42 -> V_41 ) ) ;
V_146 = F_36 ( ( (struct V_44 * ) V_42 -> V_1 ) -> V_2 ) ;
if ( V_13 -> V_83 == V_171 ) {
V_34 = F_10 ( 1 , V_42 -> V_30 , V_172 ) ;
if ( F_8 ( ! V_34 ) ) {
F_4 ( V_168 L_6
L_7 ,
V_13 -> V_28 -> V_29 ) ;
goto V_173;
}
V_34 -> V_174 = 0 ;
V_34 -> V_175 = V_42 -> V_30 ;
memcpy ( F_37 ( V_34 -> V_40 [ 0 ] , V_42 -> V_30 ) , V_42 -> V_1 ,
V_42 -> V_30 ) ;
goto V_169;
}
if ( V_42 -> V_30 > 282 ) {
if ( V_48 == V_146 ) {
const struct V_46 * V_47 = (struct V_46 * )
( ( T_1 * ) V_42 -> V_1 + 14 ) ;
if ( V_176 == V_47 -> V_177 ) {
struct V_178 * V_179 ;
V_179 = (struct V_178 * ) ( ( T_1 * ) V_47 +
( V_47 -> V_180 << 2 ) ) ;
if ( ( ( ( ( T_1 * ) V_179 ) [ 1 ] == 68 ) &&
( ( ( T_1 * ) V_179 ) [ 3 ] == 67 ) ) ||
( ( ( ( T_1 * ) V_179 ) [ 1 ] == 67 ) &&
( ( ( T_1 * ) V_179 ) [ 3 ] == 68 ) ) ) {
V_62 = true ;
V_13 -> V_181 = 200 ;
}
}
} else if ( V_182 == V_146 ) {
F_4 ( V_22 L_8
L_9 ) ;
V_62 = true ;
V_13 -> V_181 =
V_13 -> V_98 . V_183 . V_184 ;
}
}
V_42 -> V_69 = F_14 ( V_42 , V_162 ) ;
V_18 = V_13 -> V_18 [ V_13 -> V_20 ] ;
V_147 = ! ( V_146 == V_185 && V_13 -> V_186 ) &&
V_13 -> V_187 && V_18 && V_18 -> V_21 ;
if ( ! V_147 && V_13 -> V_186 &&
V_13 -> V_188 && V_146 != V_185 ) {
V_145 -> V_189 ++ ;
goto V_169;
}
if ( V_18 && ! V_147 && V_146 == V_185 ) {
struct V_190 * V_191 = (struct V_190 * ) ( V_42 -> V_1 +
sizeof( struct V_44 ) - V_11 -
sizeof( T_2 ) ) ;
F_38 ( L_10 ,
F_39 ( V_191 -> type ) ) ;
}
F_40 ( V_42 , sizeof( struct V_44 ) ) ;
V_148 = V_42 -> V_30 + V_11 + sizeof( T_2 ) ;
if ( V_147 )
V_149 = V_192 | V_193 ;
else
V_149 = V_192 ;
if ( V_158 )
V_149 |= V_194 ;
else
V_149 |= V_195 ;
if ( V_13 -> V_83 == V_84 ) {
V_149 |= V_196 ;
memcpy ( & V_152 . V_61 , V_13 -> V_98 . V_197 ,
V_156 ) ;
memcpy ( & V_152 . V_198 , & V_157 , V_156 ) ;
if ( V_162 )
memcpy ( & V_152 . V_199 ,
V_13 -> V_98 . V_197 , V_156 ) ;
else
memcpy ( & V_152 . V_199 , & V_155 , V_156 ) ;
} else if ( V_13 -> V_83 == V_133 ) {
memcpy ( & V_152 . V_61 , V_155 , V_156 ) ;
memcpy ( & V_152 . V_198 , V_157 , V_156 ) ;
memcpy ( & V_152 . V_199 , V_13 -> V_98 . V_197 ,
V_156 ) ;
}
V_161 = F_21 ( V_152 . V_61 ) ||
F_20 ( V_152 . V_61 ) ;
V_152 . V_200 = F_41 ( V_149 ) ;
if ( V_161 ) {
V_39 = V_201 ;
V_150 |= V_202 ;
} else {
V_39 = V_13 -> V_203 ;
V_150 = 0 ;
}
if ( V_158 ) {
V_16 = V_204 + 2 ;
while ( F_8 ( V_13 -> V_205 & ( 0x01 << V_42 -> V_69 ) ) ) {
F_4 ( V_22 L_11 , V_42 -> V_69 ) ;
if ( F_31 ( V_42 ) )
break;
F_4 ( V_22 L_12 ,
V_42 -> V_69 ) ;
}
V_150 |= V_42 -> V_69 ;
V_152 . V_150 = F_41 ( V_150 & V_206 ) ;
} else {
V_16 = V_204 ;
}
V_141 = V_39 - V_16 ;
if ( V_13 -> V_207 &
( V_208 | V_209 ) )
V_141 -= V_210 ;
if ( V_147 ) {
V_141 -= V_18 -> V_21 -> V_211 +
V_18 -> V_21 -> V_212 ;
}
V_35 = V_148 / V_141 ;
V_142 = V_148 % V_141 ;
if ( V_142 )
V_35 ++ ;
else
V_142 = V_141 ;
V_34 = F_10 ( V_35 , V_39 +
V_13 -> V_213 , V_172 ) ;
if ( F_8 ( ! V_34 ) ) {
F_4 ( V_168 L_13 ,
V_13 -> V_28 -> V_29 ) ;
goto V_173;
}
V_34 -> V_174 = V_147 ;
V_34 -> V_175 = V_148 ;
if ( V_158 )
V_34 -> V_214 = F_42 ( V_42 -> V_69 ) ;
else
V_34 -> V_214 = V_215 ;
for ( V_38 = 0 ; V_38 < V_35 ; V_38 ++ ) {
V_151 = V_34 -> V_40 [ V_38 ] ;
V_52 = (struct V_51 * ) ( V_151 -> V_41 +
V_216 ) ;
if ( V_158 ) {
V_151 -> V_69 = V_42 -> V_69 ;
V_52 -> V_214 = F_42 ( V_42 -> V_69 ) ;
} else {
V_151 -> V_69 = V_215 ;
V_52 -> V_214 = V_215 ;
}
F_43 ( V_151 , V_13 -> V_213 ) ;
if ( V_147 ) {
if ( V_13 -> V_217 )
V_52 -> V_218 = 1 ;
else
V_52 -> V_218 = 0 ;
F_43 ( V_151 ,
V_18 -> V_21 -> V_211 ) ;
} else {
V_52 -> V_218 = 0 ;
}
V_140 = (struct V_139 * )
F_37 ( V_151 , V_16 ) ;
memcpy ( V_140 , & V_152 , V_16 ) ;
if ( V_38 != V_35 - 1 ) {
V_140 -> V_200 = F_41 (
V_149 | V_219 ) ;
V_148 = V_141 ;
} else {
V_148 = V_142 ;
}
if ( ( V_158 ) && ( ! V_161 ) ) {
V_140 -> V_154 =
F_30 ( V_13 , V_151 ,
V_152 . V_61 ) ;
V_140 -> V_154 =
F_41 ( V_140 -> V_154 << 4 | V_38 ) ;
} else {
V_140 -> V_154 =
F_41 ( V_13 -> V_220 [ 0 ] << 4 | V_38 ) ;
}
if ( V_38 == 0 ) {
F_1 (
F_37 ( V_151 , V_11 +
sizeof( T_2 ) ) , V_146 ) ;
V_148 -= V_11 + sizeof( T_2 ) ;
}
memcpy ( F_37 ( V_151 , V_148 ) , V_42 -> V_1 , V_148 ) ;
F_40 ( V_42 , V_148 ) ;
if ( V_147 )
F_3 ( V_13 , V_151 ,
V_16 ) ;
if ( V_13 -> V_207 &
( V_208 | V_209 ) )
F_37 ( V_151 , 4 ) ;
}
if ( ( V_158 ) && ( ! V_161 ) ) {
if ( V_13 -> V_220 [ F_42 ( V_42 -> V_69 ) + 1 ] == 0xFFF )
V_13 -> V_220 [ F_42 ( V_42 -> V_69 ) + 1 ] = 0 ;
else
V_13 -> V_220 [ F_42 ( V_42 -> V_69 ) + 1 ] ++ ;
} else {
if ( V_13 -> V_220 [ 0 ] == 0xFFF )
V_13 -> V_220 [ 0 ] = 0 ;
else
V_13 -> V_220 [ 0 ] ++ ;
}
} else {
if ( F_8 ( V_42 -> V_30 < sizeof( struct V_221 ) ) ) {
F_4 ( V_168 L_5 ,
V_13 -> V_28 -> V_29 , V_42 -> V_30 ) ;
goto V_169;
}
V_34 = F_10 ( 1 , V_42 -> V_30 , V_172 ) ;
if ( ! V_34 ) {
F_4 ( V_168 L_13 ,
V_13 -> V_28 -> V_29 ) ;
goto V_173;
}
V_34 -> V_174 = 0 ;
V_34 -> V_175 = V_42 -> V_30 ;
memcpy ( F_37 ( V_34 -> V_40 [ 0 ] , V_42 -> V_30 ) , V_42 -> V_1 ,
V_42 -> V_30 ) ;
}
V_169:
if ( V_34 ) {
struct V_51 * V_52 = (struct V_51 * )
( V_34 -> V_40 [ 0 ] -> V_41 + V_216 ) ;
V_52 -> V_222 = 1 ;
V_52 -> V_69 = V_42 -> V_69 ;
if ( V_146 == V_185 ) {
if ( V_13 -> V_54 -> V_64 &
V_223 ) {
V_52 -> V_97 =
F_44 ( V_13 ) ;
V_52 -> V_131 = false ;
} else {
V_52 -> V_97 = V_13 -> V_224 ;
V_52 -> V_131 = 1 ;
}
V_52 -> V_134 = 7 ;
V_52 -> V_132 = 1 ;
} else {
if ( F_20 ( V_152 . V_61 ) )
V_52 -> V_107 = 1 ;
if ( F_21 ( V_152 . V_61 ) )
V_52 -> V_108 = 1 ;
F_29 ( V_13 , V_52 ) ;
if ( V_52 -> V_107 || V_52 -> V_108 )
V_52 -> V_97 = V_13 -> V_224 ;
else
V_52 -> V_97 = F_45 ( V_13 -> V_117 ,
V_13 -> V_225 , V_13 -> V_226 ) ;
if ( V_62 == true ) {
if ( V_13 -> V_54 -> V_64 &
V_223 ) {
V_52 -> V_97 =
F_44 ( V_13 ) ;
V_52 -> V_131 = false ;
} else {
V_52 -> V_97 = V_227 ;
V_52 -> V_131 = 1 ;
}
V_52 -> V_134 = 7 ;
V_52 -> V_132 = 1 ;
V_52 -> V_62 = 1 ;
}
F_25 ( V_13 , V_52 ) ;
F_17 ( V_13 , V_34 -> V_40 [ 0 ] ,
V_52 ) ;
F_26 ( V_13 , V_52 ) ;
F_27 ( V_13 , V_52 ) ;
F_28 ( V_13 , V_52 ,
V_34 -> V_40 [ 0 ] ) ;
}
}
F_46 ( & V_13 -> V_163 , V_143 ) ;
F_13 ( V_42 ) ;
if ( V_34 ) {
if ( V_13 -> V_165 & V_166 ) {
V_28 -> V_145 . V_228 ++ ;
V_28 -> V_145 . V_229 += V_34 -> V_175 ;
F_47 ( V_34 , V_13 ) ;
} else {
if ( (* V_13 -> V_164 )( V_34 , V_28 ) == 0 ) {
V_145 -> V_228 ++ ;
V_145 -> V_229 += V_34 -> V_175 ;
return 0 ;
}
F_7 ( V_34 ) ;
}
}
return 0 ;
V_173:
F_46 ( & V_13 -> V_163 , V_143 ) ;
F_48 ( V_28 ) ;
V_145 -> V_230 ++ ;
return 1 ;
}
int F_49 ( struct V_14 * V_42 , struct V_138 * V_28 )
{
memset ( V_42 -> V_41 , 0 , sizeof( V_42 -> V_41 ) ) ;
return F_32 ( V_42 , V_28 ) ;
}
