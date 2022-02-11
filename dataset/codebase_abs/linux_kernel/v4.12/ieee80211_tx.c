static inline int F_1 ( T_1 * V_1 , T_2 V_2 )
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
int F_3 (
struct V_13 * V_14 ,
struct V_15 * V_16 ,
int V_17 )
{
struct V_18 * V_19 = V_14 -> V_19 [ V_14 -> V_20 ] ;
int V_21 ;
if ( ! ( V_19 && V_19 -> V_22 ) )
{
F_4 ( L_1 , V_23 ) ;
return - 1 ;
}
if ( V_14 -> V_24 &&
V_19 && V_19 -> V_22 && strcmp ( V_19 -> V_22 -> V_25 , L_2 ) == 0 ) {
if ( F_5 () ) {
struct V_26 * V_27 ;
V_27 = (struct V_26 * ) V_16 -> V_1 ;
F_4 ( V_28 L_3
L_4 ,
V_14 -> V_29 -> V_25 , V_27 -> V_30 ) ;
}
return - 1 ;
}
F_6 ( & V_19 -> V_31 ) ;
V_21 = 0 ;
if ( V_19 -> V_22 -> V_32 )
V_21 = V_19 -> V_22 -> V_32 ( V_16 , V_17 , V_19 -> V_33 ) ;
if ( V_21 == 0 && V_19 -> V_22 -> V_34 )
V_21 = V_19 -> V_22 -> V_34 ( V_16 , V_17 , V_19 -> V_33 ) ;
F_7 ( & V_19 -> V_31 ) ;
if ( V_21 < 0 ) {
F_4 ( V_35 L_5 ,
V_14 -> V_29 -> V_25 , V_16 -> V_36 ) ;
V_14 -> V_37 . V_38 ++ ;
return - 1 ;
}
return 0 ;
}
void F_8 ( struct V_39 * V_40 ) {
if ( F_9 ( ! V_40 ) )
return;
F_10 ( V_40 ) ;
}
static struct V_39 * F_11 ( int V_41 , int V_42 ,
T_3 V_43 )
{
struct V_39 * V_40 ;
int V_44 ;
V_40 = F_12 (
sizeof( struct V_39 ) + ( sizeof( T_1 * ) * V_41 ) ,
V_43 ) ;
if ( ! V_40 )
return NULL ;
memset ( V_40 , 0 , sizeof( struct V_39 ) ) ;
V_40 -> V_41 = V_41 ;
V_40 -> V_45 = F_13 ( V_42 ) ;
for ( V_44 = 0 ; V_44 < V_41 ; V_44 ++ ) {
V_40 -> V_46 [ V_44 ] = F_14 ( V_42 ) ;
if ( F_9 ( ! V_40 -> V_46 [ V_44 ] ) ) {
V_44 -- ;
break;
}
memset ( V_40 -> V_46 [ V_44 ] -> V_47 , 0 , sizeof( V_40 -> V_46 [ V_44 ] -> V_47 ) ) ;
}
if ( F_9 ( V_44 != V_41 ) ) {
while ( V_44 >= 0 )
F_15 ( V_40 -> V_46 [ V_44 -- ] ) ;
F_10 ( V_40 ) ;
return NULL ;
}
return V_40 ;
}
static int
F_16 ( struct V_15 * V_48 , struct V_49 * V_50 )
{
struct V_51 * V_52 ;
struct V_53 * V_54 ;
V_52 = (struct V_51 * ) V_48 -> V_1 ;
if ( V_52 -> V_2 != F_2 ( V_55 ) )
return 0 ;
V_54 = F_17 ( V_48 ) ;
switch ( V_54 -> V_56 & 0xfc ) {
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
struct V_15 * V_48 , struct V_57 * V_58 )
{
T_4 V_59 = V_14 -> V_59 ;
T_5 V_60 = NULL ;
struct V_61 * V_62 = (struct V_61 * ) V_48 -> V_1 ;
if ( ! V_59 -> V_63 || ! V_59 -> V_64 )
return;
if ( ! F_19 ( V_48 -> V_1 ) )
return;
if ( F_20 ( V_62 -> V_30 ) )
return;
#ifdef F_21
if( V_65 -> V_66 >= 4096 )
return;
if( ! V_67 -> V_68 . V_69 ( V_67 ) )
return;
#endif
if( ! V_14 -> V_70 ( V_14 -> V_29 ) )
{
return;
}
if( V_59 -> V_71 )
{
if ( ! F_22 ( V_14 , ( V_72 * ) ( & V_60 ) , V_62 -> V_30 , V_48 -> V_73 , V_74 , true ) )
{
F_4 ( L_6 ) ;
return;
}
if ( ! V_60 -> V_75 . V_76 )
{
F_23 ( V_14 , V_60 ) ;
goto V_77;
}
else if ( ! V_60 -> V_78 )
{
if ( F_24 ( V_60 -> V_75 . V_79 . V_80 . V_81 , ( V_60 -> V_82 + 1 ) % 4096 ) )
V_60 -> V_78 = true ;
else
goto V_77;
}
if ( V_14 -> V_83 == V_84 )
{
V_58 -> V_85 = true ;
V_58 -> V_86 = V_59 -> V_87 ;
V_58 -> V_88 = V_59 -> V_89 ;
}
}
V_77:
switch ( V_59 -> V_90 )
{
case V_91 :
break;
case V_92 :
V_58 -> V_85 = true ;
V_58 -> V_88 = V_59 -> V_93 ;
V_58 -> V_86 = V_59 -> V_94 ;
break;
case V_95 :
V_58 -> V_85 = false ;
V_58 -> V_88 = 0 ;
V_58 -> V_86 = 0 ;
break;
}
return;
}
static void F_25 ( struct V_13 * V_14 ,
struct V_57 * V_58 )
{
V_58 -> V_96 = false ;
if ( V_58 -> V_97 == 2 )
{
return;
}
else if ( V_14 -> V_98 . V_99 & V_100 )
{
V_58 -> V_96 = true ;
}
return;
}
static void
F_26 ( struct V_13 * V_14 , struct V_57 * V_58 )
{
T_4 V_59 = V_14 -> V_59 ;
V_58 -> V_101 = false ;
if( ! V_59 -> V_63 || ! V_59 -> V_64 )
return;
if( V_59 -> V_102 )
{
V_58 -> V_101 = true ;
return;
}
if( ( V_59 -> V_103 == true ) && V_59 -> V_104 )
V_58 -> V_101 = true ;
else if( ( V_59 -> V_103 == false ) && V_59 -> V_105 )
V_58 -> V_101 = true ;
}
static void F_27 ( struct V_13 * V_14 ,
struct V_57 * V_58 )
{
T_4 V_59 = V_14 -> V_59 ;
V_58 -> V_106 = false ;
if( ! V_59 -> V_63 || ! V_59 -> V_64 )
return;
if( V_58 -> V_107 || V_58 -> V_108 )
return;
if( ( V_58 -> V_97 & 0x80 ) == 0 )
return;
if( V_59 -> V_103 && V_59 -> V_109 && ! V_14 -> V_110 . V_111 )
V_58 -> V_106 = true ;
return;
}
static void F_28 ( struct V_13 * V_14 ,
struct V_57 * V_58 ,
struct V_15 * V_48 )
{
V_58 -> V_112 = false ;
V_58 -> V_113 = false ;
V_58 -> V_114 = false ;
V_58 -> V_115 = 0 ;
V_58 -> V_116 = false ;
if( V_58 -> V_108 || V_58 -> V_107 )
return;
if ( F_29 ( V_48 -> V_1 + 16 ) )
return;
if ( V_14 -> V_117 < V_118 )
{
if ( V_48 -> V_36 > V_14 -> V_119 )
{
V_58 -> V_120 = true ;
V_58 -> V_121 = V_122 ;
}
else if ( V_14 -> V_98 . V_123 )
{
V_58 -> V_120 = true ;
V_58 -> V_114 = true ;
V_58 -> V_121 = V_122 ;
}
return;
}
else
{
T_4 V_59 = V_14 -> V_59 ;
while ( true )
{
if ( V_14 -> V_98 . V_123 )
{
V_58 -> V_120 = true ;
V_58 -> V_114 = true ;
V_58 -> V_121 = V_122 ;
break;
}
if( V_59 -> V_63 && V_59 -> V_64 )
{
T_1 V_124 = V_59 -> V_125 ;
if( ( V_59 -> V_103 && ( V_124 == 2 || V_124 == 3 ) ) ||
( ! V_59 -> V_103 && V_124 == 3 ) )
{
V_58 -> V_121 = V_122 ;
V_58 -> V_120 = true ;
break;
}
}
if ( V_48 -> V_36 > V_14 -> V_119 )
{
V_58 -> V_121 = V_122 ;
V_58 -> V_120 = true ;
break;
}
if( V_58 -> V_85 )
{
V_58 -> V_121 = V_122 ;
V_58 -> V_120 = false ;
break;
}
if( V_59 -> V_126 & V_127 )
{
V_58 -> V_114 = true ;
V_58 -> V_121 = V_122 ;
V_58 -> V_120 = true ;
break;
}
goto V_128;
}
}
if ( 0 ) {
V_58 -> V_114 = true ;
V_58 -> V_121 = V_122 ;
V_58 -> V_120 = true ;
}
if ( V_14 -> V_98 . V_99 & V_100 )
V_58 -> V_96 = true ;
if ( V_14 -> V_117 == V_129 )
goto V_128;
return;
V_128:
V_58 -> V_120 = false ;
V_58 -> V_114 = false ;
V_58 -> V_121 = 0 ;
V_58 -> V_115 = 0 ;
V_58 -> V_116 = false ;
}
static void F_30 ( struct V_13 * V_14 ,
struct V_57 * V_58 )
{
#ifdef F_21
if( ! F_31 ( V_130 ) )
{
V_65 -> V_131 = true ;
V_65 -> V_132 = true ;
V_65 -> V_133 = 7 ;
return;
}
if( V_134 -> V_135 != 0 )
{
V_65 -> V_131 = true ;
V_65 -> V_132 = true ;
return;
}
#endif
if( V_14 -> V_131 )
V_58 -> V_131 = true ;
if( V_14 -> V_132 )
V_58 -> V_132 = true ;
if( ! V_58 -> V_131 || ! V_58 -> V_132 )
{
if ( V_14 -> V_83 == V_84 || V_14 -> V_83 == V_136 )
V_58 -> V_133 = 0 ;
}
}
static void F_32 ( struct V_13 * V_14 ,
struct V_15 * V_48 , T_1 * V_137 )
{
if ( F_20 ( V_137 ) )
return;
if ( F_19 ( V_48 -> V_1 ) )
{
T_5 V_138 = NULL ;
if ( ! F_22 ( V_14 , ( V_72 * ) ( & V_138 ) , V_137 , V_48 -> V_73 , V_74 , true ) )
{
return;
}
V_138 -> V_82 = ( V_138 -> V_82 + 1 ) % 4096 ;
}
}
int F_33 ( struct V_15 * V_48 , struct V_139 * V_29 )
{
struct V_13 * V_14 = F_34 ( V_29 ) ;
struct V_39 * V_40 = NULL ;
struct V_26 * V_140 ;
int V_44 , V_141 , V_41 , V_142 , V_45 ;
unsigned long V_143 ;
struct V_144 * V_145 = & V_14 -> V_145 ;
int V_146 = 0 , V_147 ;
int V_148 , V_149 , V_150 = 0 , V_17 ;
struct V_15 * V_151 ;
struct V_26 V_27 = {
. V_152 = 0 ,
. V_153 = 0 ,
. V_150 = 0
} ;
T_1 V_154 [ V_155 ] , V_156 [ V_155 ] ;
int V_157 = V_14 -> V_98 . V_158 . V_159 ;
struct V_18 * V_19 ;
struct V_57 * V_58 ;
F_35 ( & V_14 -> V_160 , V_143 ) ;
if ( ( ! V_14 -> V_161 && ! ( V_14 -> V_162 & V_163 ) ) ||
( ( ! V_14 -> V_164 && ( V_14 -> V_162 & V_163 ) ) ) ) {
F_4 ( V_165 L_7 ,
V_14 -> V_29 -> V_25 ) ;
goto V_166;
}
if( F_36 ( V_14 -> V_167 == 0 ) ) {
if ( F_9 ( V_48 -> V_36 < V_12 + sizeof( T_2 ) ) ) {
F_4 ( V_165 L_8 ,
V_14 -> V_29 -> V_25 , V_48 -> V_36 ) ;
goto V_166;
}
memset ( V_48 -> V_47 , 0 , sizeof( V_48 -> V_47 ) ) ;
V_146 = F_37 ( ( (struct V_51 * ) V_48 -> V_1 ) -> V_2 ) ;
V_19 = V_14 -> V_19 [ V_14 -> V_20 ] ;
V_147 = ! ( V_146 == V_168 && V_14 -> V_169 ) &&
V_14 -> V_170 && V_19 && V_19 -> V_22 ;
if ( ! V_147 && V_14 -> V_169 &&
V_14 -> V_171 && V_146 != V_168 ) {
V_145 -> V_172 ++ ;
goto V_166;
}
#ifdef F_38
if ( V_19 && ! V_147 && V_146 == V_168 ) {
struct V_173 * V_174 = (struct V_173 * ) ( V_48 -> V_1 +
sizeof( struct V_51 ) - V_12 - sizeof( T_2 ) ) ;
F_39 ( L_9 ,
F_40 ( V_174 -> type ) ) ;
}
#endif
memcpy ( & V_154 , V_48 -> V_1 , V_155 ) ;
memcpy ( & V_156 , V_48 -> V_1 + V_155 , V_155 ) ;
F_41 ( V_48 , sizeof( struct V_51 ) ) ;
V_148 = V_48 -> V_36 + V_12 + sizeof( T_2 ) ;
if ( V_147 )
V_149 = V_175 | V_176 ;
else
V_149 = V_175 ;
if( V_157 )
V_149 |= V_177 ;
else
V_149 |= V_178 ;
if ( V_14 -> V_83 == V_84 ) {
V_149 |= V_179 ;
memcpy ( & V_27 . V_30 , V_14 -> V_98 . V_180 , V_155 ) ;
memcpy ( & V_27 . V_181 , & V_156 , V_155 ) ;
memcpy ( & V_27 . V_182 , & V_154 , V_155 ) ;
} else if ( V_14 -> V_83 == V_136 ) {
memcpy ( & V_27 . V_30 , V_154 , V_155 ) ;
memcpy ( & V_27 . V_181 , V_156 , V_155 ) ;
memcpy ( & V_27 . V_182 , V_14 -> V_98 . V_180 , V_155 ) ;
}
V_27 . V_183 = F_42 ( V_149 ) ;
if ( F_20 ( V_27 . V_30 ) ) {
V_45 = V_184 ;
V_150 |= V_185 ;
}
else {
V_45 = V_14 -> V_186 ;
V_150 = 0 ;
}
if( V_157 )
{
V_17 = V_187 + 2 ;
V_48 -> V_73 = F_16 ( V_48 , & V_14 -> V_98 ) ;
V_150 |= V_48 -> V_73 ;
V_27 . V_150 = F_42 ( V_150 & V_188 ) ;
} else {
V_17 = V_187 ;
}
V_141 = V_45 - V_17 ;
if ( V_14 -> V_189 &
( V_190 | V_191 ) )
V_141 -= V_192 ;
if ( V_147 )
V_141 -= V_19 -> V_22 -> V_193 +
V_19 -> V_22 -> V_194 ;
V_41 = V_148 / V_141 ;
V_142 = V_148 % V_141 ;
if ( V_142 )
V_41 ++ ;
else
V_142 = V_141 ;
V_40 = F_11 ( V_41 , V_45 + V_14 -> V_195 , V_196 ) ;
if ( F_9 ( ! V_40 ) ) {
F_4 ( V_165 L_10 ,
V_14 -> V_29 -> V_25 ) ;
goto V_197;
}
V_40 -> V_198 = V_147 ;
V_40 -> V_199 = F_13 ( V_148 ) ;
if( V_157 )
{
V_40 -> V_200 = F_43 ( V_48 -> V_73 ) ;
} else {
V_40 -> V_200 = V_201 ;
}
for ( V_44 = 0 ; V_44 < V_41 ; V_44 ++ ) {
V_151 = V_40 -> V_46 [ V_44 ] ;
V_58 = (struct V_57 * ) ( V_151 -> V_47 + V_202 ) ;
if( V_157 ) {
V_151 -> V_73 = V_48 -> V_73 ;
V_58 -> V_200 = F_43 ( V_48 -> V_73 ) ;
} else {
V_151 -> V_73 = V_201 ;
V_58 -> V_200 = V_201 ;
}
F_44 ( V_151 , V_14 -> V_195 ) ;
if ( V_147 ) {
if ( V_14 -> V_203 )
V_58 -> V_204 = 1 ;
else
V_58 -> V_204 = 0 ;
F_44 ( V_151 , V_19 -> V_22 -> V_193 ) ;
}
else
{
V_58 -> V_204 = 0 ;
}
V_140 = (struct V_26 * ) F_45 ( V_151 , V_17 ) ;
memcpy ( V_140 , & V_27 , V_17 ) ;
if ( V_44 != V_41 - 1 ) {
V_140 -> V_183 = F_42 (
V_149 | V_205 ) ;
V_148 = V_141 ;
} else {
V_148 = V_142 ;
}
if( V_157 )
{
V_140 -> V_153 = F_42 ( V_14 -> V_206 [ F_43 ( V_48 -> V_73 ) + 1 ] << 4 | V_44 ) ;
} else {
V_140 -> V_153 = F_42 ( V_14 -> V_206 [ 0 ] << 4 | V_44 ) ;
}
if ( V_44 == 0 ) {
F_1 (
F_45 ( V_151 , V_12 + sizeof( T_2 ) ) ,
V_146 ) ;
V_148 -= V_12 + sizeof( T_2 ) ;
}
memcpy ( F_45 ( V_151 , V_148 ) , V_48 -> V_1 , V_148 ) ;
F_41 ( V_48 , V_148 ) ;
if ( V_147 )
F_3 ( V_14 , V_151 , V_17 ) ;
if ( V_14 -> V_189 &
( V_190 | V_191 ) )
F_45 ( V_151 , 4 ) ;
}
if( V_157 )
{
if ( V_14 -> V_206 [ F_43 ( V_48 -> V_73 ) + 1 ] == 0xFFF )
V_14 -> V_206 [ F_43 ( V_48 -> V_73 ) + 1 ] = 0 ;
else
V_14 -> V_206 [ F_43 ( V_48 -> V_73 ) + 1 ] ++ ;
} else {
if ( V_14 -> V_206 [ 0 ] == 0xFFF )
V_14 -> V_206 [ 0 ] = 0 ;
else
V_14 -> V_206 [ 0 ] ++ ;
}
} else{
if ( F_9 ( V_48 -> V_36 < sizeof( struct V_207 ) ) ) {
F_4 ( V_165 L_8 ,
V_14 -> V_29 -> V_25 , V_48 -> V_36 ) ;
goto V_166;
}
V_40 = F_11 ( 1 , V_48 -> V_36 , V_196 ) ;
if( ! V_40 ) {
F_4 ( V_165 L_10 ,
V_14 -> V_29 -> V_25 ) ;
goto V_197;
}
V_40 -> V_198 = 0 ;
V_40 -> V_199 = F_13 ( V_48 -> V_36 ) ;
memcpy ( F_45 ( V_40 -> V_46 [ 0 ] , V_48 -> V_36 ) , V_48 -> V_1 , V_48 -> V_36 ) ;
}
V_166:
if ( V_40 )
{
struct V_57 * V_58 = (struct V_57 * ) ( V_40 -> V_46 [ 0 ] -> V_47 + V_202 ) ;
V_58 -> V_208 = 1 ;
if ( F_20 ( V_27 . V_30 ) )
V_58 -> V_107 = 1 ;
if ( F_29 ( V_27 . V_30 ) )
V_58 -> V_108 = 1 ;
F_30 ( V_14 , V_58 ) ;
if ( V_58 -> V_107 || V_58 -> V_108 )
V_58 -> V_97 = V_14 -> V_209 ;
else
V_58 -> V_97 = F_46 ( V_14 -> V_117 , V_14 -> V_210 , V_14 -> V_211 ) ;
F_25 ( V_14 , V_58 ) ;
F_18 ( V_14 , V_40 -> V_46 [ 0 ] , V_58 ) ;
F_26 ( V_14 , V_58 ) ;
F_27 ( V_14 , V_58 ) ;
F_28 ( V_14 , V_58 , V_40 -> V_46 [ 0 ] ) ;
F_32 ( V_14 , V_40 -> V_46 [ 0 ] , V_27 . V_30 ) ;
}
F_47 ( & V_14 -> V_160 , V_143 ) ;
F_15 ( V_48 ) ;
if ( V_40 ) {
if ( V_14 -> V_162 & V_163 ) {
F_48 ( V_40 , V_14 ) ;
} else{
if ( (* V_14 -> V_161 )( V_40 , V_29 ) == 0 ) {
V_145 -> V_212 ++ ;
V_145 -> V_213 += F_49 ( V_40 -> V_199 ) ;
return 0 ;
}
F_8 ( V_40 ) ;
}
}
return 0 ;
V_197:
F_47 ( & V_14 -> V_160 , V_143 ) ;
F_50 ( V_29 ) ;
V_145 -> V_214 ++ ;
return 1 ;
}
