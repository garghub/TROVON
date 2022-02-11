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
* ( T_2 * ) ( V_1 + V_11 ) = F_2 ( V_2 ) ;
return V_11 + sizeof( T_2 ) ;
}
int F_3 (
struct V_12 * V_13 ,
struct V_14 * V_15 ,
int V_16 )
{
struct V_17 * V_18 = V_13 -> V_18 [ V_13 -> V_19 ] ;
int V_20 ;
if ( ! ( V_18 && V_18 -> V_21 ) )
{
F_4 ( L_1 , V_22 ) ;
return - 1 ;
}
if ( V_13 -> V_23 &&
V_18 && V_18 -> V_21 && strcmp ( V_18 -> V_21 -> V_24 , L_2 ) == 0 ) {
if ( F_5 () ) {
struct V_25 * V_26 ;
V_26 = (struct V_25 * ) V_15 -> V_1 ;
F_4 ( V_27 L_3
L_4 ,
V_13 -> V_28 -> V_24 , V_26 -> V_29 ) ;
}
return - 1 ;
}
F_6 ( & V_18 -> V_30 ) ;
V_20 = 0 ;
if ( V_18 -> V_21 -> V_31 )
V_20 = V_18 -> V_21 -> V_31 ( V_15 , V_16 , V_18 -> V_32 ) ;
if ( V_20 == 0 && V_18 -> V_21 -> V_33 )
V_20 = V_18 -> V_21 -> V_33 ( V_15 , V_16 , V_18 -> V_32 ) ;
F_7 ( & V_18 -> V_30 ) ;
if ( V_20 < 0 ) {
F_4 ( V_34 L_5 ,
V_13 -> V_28 -> V_24 , V_15 -> V_35 ) ;
V_13 -> V_36 . V_37 ++ ;
return - 1 ;
}
return 0 ;
}
void F_8 ( struct V_38 * V_39 ) {
if ( F_9 ( ! V_39 ) )
return;
F_10 ( V_39 ) ;
}
static struct V_38 * F_11 ( int V_40 , int V_41 ,
T_3 V_42 )
{
struct V_38 * V_39 ;
int V_43 ;
V_39 = F_12 (
sizeof( struct V_38 ) + ( sizeof( T_1 * ) * V_40 ) ,
V_42 ) ;
if ( ! V_39 )
return NULL ;
memset ( V_39 , 0 , sizeof( struct V_38 ) ) ;
V_39 -> V_40 = V_40 ;
V_39 -> V_44 = F_13 ( V_41 ) ;
for ( V_43 = 0 ; V_43 < V_40 ; V_43 ++ ) {
V_39 -> V_45 [ V_43 ] = F_14 ( V_41 ) ;
if ( F_9 ( ! V_39 -> V_45 [ V_43 ] ) ) {
V_43 -- ;
break;
}
memset ( V_39 -> V_45 [ V_43 ] -> V_46 , 0 , sizeof( V_39 -> V_45 [ V_43 ] -> V_46 ) ) ;
}
if ( F_9 ( V_43 != V_40 ) ) {
while ( V_43 >= 0 )
F_15 ( V_39 -> V_45 [ V_43 -- ] ) ;
F_10 ( V_39 ) ;
return NULL ;
}
return V_39 ;
}
static int
F_16 ( struct V_14 * V_47 , struct V_48 * V_49 )
{
struct V_50 * V_51 ;
struct V_52 * V_53 ;
V_51 = (struct V_50 * ) V_47 -> V_1 ;
if ( V_51 -> V_2 != F_2 ( V_54 ) )
return 0 ;
V_53 = F_17 ( V_47 ) ;
switch ( V_53 -> V_55 & 0xfc ) {
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
static void F_18 ( struct V_12 * V_13 ,
struct V_14 * V_47 , struct V_56 * V_57 )
{
T_4 V_58 = V_13 -> V_58 ;
T_5 V_59 = NULL ;
struct V_60 * V_61 = (struct V_60 * ) V_47 -> V_1 ;
if ( ! V_58 -> V_62 || ! V_58 -> V_63 )
return;
if ( ! F_19 ( V_47 -> V_1 ) )
return;
if ( F_20 ( V_61 -> V_29 ) )
return;
#ifdef F_21
if( V_64 -> V_65 >= 4096 )
return;
if( ! V_66 -> V_67 . V_68 ( V_66 ) )
return;
#endif
if( ! V_13 -> V_69 ( V_13 -> V_28 ) )
{
return;
}
if( V_58 -> V_70 )
{
if ( ! F_22 ( V_13 , ( V_71 * ) ( & V_59 ) , V_61 -> V_29 , V_47 -> V_72 , V_73 , true ) )
{
F_4 ( L_6 ) ;
return;
}
if ( ! V_59 -> V_74 . V_75 )
{
F_23 ( V_13 , V_59 ) ;
goto V_76;
}
else if ( ! V_59 -> V_77 )
{
if ( F_24 ( V_59 -> V_74 . V_78 . V_79 . V_80 , ( V_59 -> V_81 + 1 ) % 4096 ) )
V_59 -> V_77 = true ;
else
goto V_76;
}
if ( V_13 -> V_82 == V_83 )
{
V_57 -> V_84 = true ;
V_57 -> V_85 = V_58 -> V_86 ;
V_57 -> V_87 = V_58 -> V_88 ;
}
}
V_76:
switch ( V_58 -> V_89 )
{
case V_90 :
break;
case V_91 :
V_57 -> V_84 = true ;
V_57 -> V_87 = V_58 -> V_92 ;
V_57 -> V_85 = V_58 -> V_93 ;
break;
case V_94 :
V_57 -> V_84 = false ;
V_57 -> V_87 = 0 ;
V_57 -> V_85 = 0 ;
break;
}
return;
}
static void F_25 ( struct V_12 * V_13 ,
struct V_56 * V_57 )
{
V_57 -> V_95 = false ;
if ( V_57 -> V_96 == 2 )
{
return;
}
else if ( V_13 -> V_97 . V_98 & V_99 )
{
V_57 -> V_95 = true ;
}
return;
}
static void
F_26 ( struct V_12 * V_13 , struct V_56 * V_57 )
{
T_4 V_58 = V_13 -> V_58 ;
V_57 -> V_100 = false ;
if( ! V_58 -> V_62 || ! V_58 -> V_63 )
return;
if( V_58 -> V_101 )
{
V_57 -> V_100 = true ;
return;
}
if( ( V_58 -> V_102 == true ) && V_58 -> V_103 )
V_57 -> V_100 = true ;
else if( ( V_58 -> V_102 == false ) && V_58 -> V_104 )
V_57 -> V_100 = true ;
}
static void F_27 ( struct V_12 * V_13 ,
struct V_56 * V_57 )
{
T_4 V_58 = V_13 -> V_58 ;
V_57 -> V_105 = false ;
if( ! V_58 -> V_62 || ! V_58 -> V_63 )
return;
if( V_57 -> V_106 || V_57 -> V_107 )
return;
if( ( V_57 -> V_96 & 0x80 ) == 0 )
return;
if( V_58 -> V_102 && V_58 -> V_108 && ! V_13 -> V_109 . V_110 )
V_57 -> V_105 = true ;
return;
}
static void F_28 ( struct V_12 * V_13 ,
struct V_56 * V_57 ,
struct V_14 * V_47 )
{
V_57 -> V_111 = false ;
V_57 -> V_112 = false ;
V_57 -> V_113 = false ;
V_57 -> V_114 = 0 ;
V_57 -> V_115 = false ;
if( V_57 -> V_107 || V_57 -> V_106 )
return;
if ( F_29 ( V_47 -> V_1 + 16 ) )
return;
if ( V_13 -> V_116 < V_117 )
{
if ( V_47 -> V_35 > V_13 -> V_118 )
{
V_57 -> V_119 = true ;
V_57 -> V_120 = V_121 ;
}
else if ( V_13 -> V_97 . V_122 )
{
V_57 -> V_119 = true ;
V_57 -> V_113 = true ;
V_57 -> V_120 = V_121 ;
}
return;
}
else
{
T_4 V_58 = V_13 -> V_58 ;
while ( true )
{
if ( V_13 -> V_97 . V_122 )
{
V_57 -> V_119 = true ;
V_57 -> V_113 = true ;
V_57 -> V_120 = V_121 ;
break;
}
if( V_58 -> V_62 && V_58 -> V_63 )
{
T_1 V_123 = V_58 -> V_124 ;
if( ( V_58 -> V_102 && ( V_123 == 2 || V_123 == 3 ) ) ||
( ! V_58 -> V_102 && V_123 == 3 ) )
{
V_57 -> V_120 = V_121 ;
V_57 -> V_119 = true ;
break;
}
}
if ( V_47 -> V_35 > V_13 -> V_118 )
{
V_57 -> V_120 = V_121 ;
V_57 -> V_119 = true ;
break;
}
if( V_57 -> V_84 )
{
V_57 -> V_120 = V_121 ;
V_57 -> V_119 = false ;
break;
}
if( V_58 -> V_125 & V_126 )
{
V_57 -> V_113 = true ;
V_57 -> V_120 = V_121 ;
V_57 -> V_119 = true ;
break;
}
goto V_127;
}
}
if ( 0 ) {
V_57 -> V_113 = true ;
V_57 -> V_120 = V_121 ;
V_57 -> V_119 = true ;
}
if ( V_13 -> V_97 . V_98 & V_99 )
V_57 -> V_95 = true ;
if ( V_13 -> V_116 == V_128 )
goto V_127;
return;
V_127:
V_57 -> V_119 = false ;
V_57 -> V_113 = false ;
V_57 -> V_120 = 0 ;
V_57 -> V_114 = 0 ;
V_57 -> V_115 = false ;
}
static void F_30 ( struct V_12 * V_13 ,
struct V_56 * V_57 )
{
#ifdef F_21
if( ! F_31 ( V_129 ) )
{
V_64 -> V_130 = true ;
V_64 -> V_131 = true ;
V_64 -> V_132 = 7 ;
return;
}
if( V_133 -> V_134 != 0 )
{
V_64 -> V_130 = true ;
V_64 -> V_131 = true ;
return;
}
#endif
if( V_13 -> V_130 )
V_57 -> V_130 = true ;
if( V_13 -> V_131 )
V_57 -> V_131 = true ;
if( ! V_57 -> V_130 || ! V_57 -> V_131 )
{
if ( V_13 -> V_82 == V_83 || V_13 -> V_82 == V_135 )
V_57 -> V_132 = 0 ;
}
}
static void F_32 ( struct V_12 * V_13 ,
struct V_14 * V_47 , T_1 * V_136 )
{
if ( F_20 ( V_136 ) )
return;
if ( F_19 ( V_47 -> V_1 ) )
{
T_5 V_137 = NULL ;
if ( ! F_22 ( V_13 , ( V_71 * ) ( & V_137 ) , V_136 , V_47 -> V_72 , V_73 , true ) )
{
return;
}
V_137 -> V_81 = ( V_137 -> V_81 + 1 ) % 4096 ;
}
}
int F_33 ( struct V_14 * V_47 , struct V_138 * V_28 )
{
struct V_12 * V_13 = F_34 ( V_28 ) ;
struct V_38 * V_39 = NULL ;
struct V_25 * V_139 ;
int V_43 , V_140 , V_40 , V_141 , V_44 ;
unsigned long V_142 ;
struct V_143 * V_144 = & V_13 -> V_144 ;
int V_145 = 0 , V_146 ;
int V_147 , V_148 , V_149 = 0 , V_16 ;
struct V_14 * V_150 ;
struct V_25 V_26 = {
. V_151 = 0 ,
. V_152 = 0 ,
. V_149 = 0
} ;
T_1 V_153 [ V_154 ] , V_155 [ V_154 ] ;
int V_156 = V_13 -> V_97 . V_157 . V_158 ;
struct V_17 * V_18 ;
struct V_56 * V_57 ;
F_35 ( & V_13 -> V_159 , V_142 ) ;
if ( ( ! V_13 -> V_160 && ! ( V_13 -> V_161 & V_162 ) ) ||
( ( ! V_13 -> V_163 && ( V_13 -> V_161 & V_162 ) ) ) ) {
F_4 ( V_164 L_7 ,
V_13 -> V_28 -> V_24 ) ;
goto V_165;
}
if( F_36 ( V_13 -> V_166 == 0 ) ) {
if ( F_9 ( V_47 -> V_35 < V_11 + sizeof( T_2 ) ) ) {
F_4 ( V_164 L_8 ,
V_13 -> V_28 -> V_24 , V_47 -> V_35 ) ;
goto V_165;
}
memset ( V_47 -> V_46 , 0 , sizeof( V_47 -> V_46 ) ) ;
V_145 = F_37 ( ( (struct V_50 * ) V_47 -> V_1 ) -> V_2 ) ;
V_18 = V_13 -> V_18 [ V_13 -> V_19 ] ;
V_146 = ! ( V_145 == V_167 && V_13 -> V_168 ) &&
V_13 -> V_169 && V_18 && V_18 -> V_21 ;
if ( ! V_146 && V_13 -> V_168 &&
V_13 -> V_170 && V_145 != V_167 ) {
V_144 -> V_171 ++ ;
goto V_165;
}
#ifdef F_38
if ( V_18 && ! V_146 && V_145 == V_167 ) {
struct V_172 * V_173 = (struct V_172 * ) ( V_47 -> V_1 +
sizeof( struct V_50 ) - V_11 - sizeof( T_2 ) ) ;
F_39 ( L_9 ,
F_40 ( V_173 -> type ) ) ;
}
#endif
memcpy ( & V_153 , V_47 -> V_1 , V_154 ) ;
memcpy ( & V_155 , V_47 -> V_1 + V_154 , V_154 ) ;
F_41 ( V_47 , sizeof( struct V_50 ) ) ;
V_147 = V_47 -> V_35 + V_11 + sizeof( T_2 ) ;
if ( V_146 )
V_148 = V_174 | V_175 ;
else
V_148 = V_174 ;
if( V_156 )
V_148 |= V_176 ;
else
V_148 |= V_177 ;
if ( V_13 -> V_82 == V_83 ) {
V_148 |= V_178 ;
memcpy ( & V_26 . V_29 , V_13 -> V_97 . V_179 , V_154 ) ;
memcpy ( & V_26 . V_180 , & V_155 , V_154 ) ;
memcpy ( & V_26 . V_181 , & V_153 , V_154 ) ;
} else if ( V_13 -> V_82 == V_135 ) {
memcpy ( & V_26 . V_29 , V_153 , V_154 ) ;
memcpy ( & V_26 . V_180 , V_155 , V_154 ) ;
memcpy ( & V_26 . V_181 , V_13 -> V_97 . V_179 , V_154 ) ;
}
V_26 . V_182 = F_42 ( V_148 ) ;
if ( F_20 ( V_26 . V_29 ) ) {
V_44 = V_183 ;
V_149 |= V_184 ;
}
else {
V_44 = V_13 -> V_185 ;
V_149 = 0 ;
}
if( V_156 )
{
V_16 = V_186 + 2 ;
V_47 -> V_72 = F_16 ( V_47 , & V_13 -> V_97 ) ;
V_149 |= V_47 -> V_72 ;
V_26 . V_149 = F_42 ( V_149 & V_187 ) ;
} else {
V_16 = V_186 ;
}
V_140 = V_44 - V_16 ;
if ( V_13 -> V_188 &
( V_189 | V_190 ) )
V_140 -= V_191 ;
if ( V_146 )
V_140 -= V_18 -> V_21 -> V_192 +
V_18 -> V_21 -> V_193 ;
V_40 = V_147 / V_140 ;
V_141 = V_147 % V_140 ;
if ( V_141 )
V_40 ++ ;
else
V_141 = V_140 ;
V_39 = F_11 ( V_40 , V_44 + V_13 -> V_194 , V_195 ) ;
if ( F_9 ( ! V_39 ) ) {
F_4 ( V_164 L_10 ,
V_13 -> V_28 -> V_24 ) ;
goto V_196;
}
V_39 -> V_197 = V_146 ;
V_39 -> V_198 = F_13 ( V_147 ) ;
if( V_156 )
{
V_39 -> V_199 = F_43 ( V_47 -> V_72 ) ;
} else {
V_39 -> V_199 = V_200 ;
}
for ( V_43 = 0 ; V_43 < V_40 ; V_43 ++ ) {
V_150 = V_39 -> V_45 [ V_43 ] ;
V_57 = (struct V_56 * ) ( V_150 -> V_46 + V_201 ) ;
if( V_156 ) {
V_150 -> V_72 = V_47 -> V_72 ;
V_57 -> V_199 = F_43 ( V_47 -> V_72 ) ;
} else {
V_150 -> V_72 = V_200 ;
V_57 -> V_199 = V_200 ;
}
F_44 ( V_150 , V_13 -> V_194 ) ;
if ( V_146 ) {
if ( V_13 -> V_202 )
V_57 -> V_203 = 1 ;
else
V_57 -> V_203 = 0 ;
F_44 ( V_150 , V_18 -> V_21 -> V_192 ) ;
}
else
{
V_57 -> V_203 = 0 ;
}
V_139 = (struct V_25 * ) F_45 ( V_150 , V_16 ) ;
memcpy ( V_139 , & V_26 , V_16 ) ;
if ( V_43 != V_40 - 1 ) {
V_139 -> V_182 = F_42 (
V_148 | V_204 ) ;
V_147 = V_140 ;
} else {
V_147 = V_141 ;
}
if( V_156 )
{
V_139 -> V_152 = F_42 ( V_13 -> V_205 [ F_43 ( V_47 -> V_72 ) + 1 ] << 4 | V_43 ) ;
} else {
V_139 -> V_152 = F_42 ( V_13 -> V_205 [ 0 ] << 4 | V_43 ) ;
}
if ( V_43 == 0 ) {
F_1 (
F_45 ( V_150 , V_11 + sizeof( T_2 ) ) ,
V_145 ) ;
V_147 -= V_11 + sizeof( T_2 ) ;
}
memcpy ( F_45 ( V_150 , V_147 ) , V_47 -> V_1 , V_147 ) ;
F_41 ( V_47 , V_147 ) ;
if ( V_146 )
F_3 ( V_13 , V_150 , V_16 ) ;
if ( V_13 -> V_188 &
( V_189 | V_190 ) )
F_45 ( V_150 , 4 ) ;
}
if( V_156 )
{
if ( V_13 -> V_205 [ F_43 ( V_47 -> V_72 ) + 1 ] == 0xFFF )
V_13 -> V_205 [ F_43 ( V_47 -> V_72 ) + 1 ] = 0 ;
else
V_13 -> V_205 [ F_43 ( V_47 -> V_72 ) + 1 ] ++ ;
} else {
if ( V_13 -> V_205 [ 0 ] == 0xFFF )
V_13 -> V_205 [ 0 ] = 0 ;
else
V_13 -> V_205 [ 0 ] ++ ;
}
} else{
if ( F_9 ( V_47 -> V_35 < sizeof( struct V_206 ) ) ) {
F_4 ( V_164 L_8 ,
V_13 -> V_28 -> V_24 , V_47 -> V_35 ) ;
goto V_165;
}
V_39 = F_11 ( 1 , V_47 -> V_35 , V_195 ) ;
if( ! V_39 ) {
F_4 ( V_164 L_10 ,
V_13 -> V_28 -> V_24 ) ;
goto V_196;
}
V_39 -> V_197 = 0 ;
V_39 -> V_198 = F_13 ( V_47 -> V_35 ) ;
memcpy ( F_45 ( V_39 -> V_45 [ 0 ] , V_47 -> V_35 ) , V_47 -> V_1 , V_47 -> V_35 ) ;
}
V_165:
if ( V_39 )
{
struct V_56 * V_57 = (struct V_56 * ) ( V_39 -> V_45 [ 0 ] -> V_46 + V_201 ) ;
V_57 -> V_207 = 1 ;
if ( F_20 ( V_26 . V_29 ) )
V_57 -> V_106 = 1 ;
if ( F_29 ( V_26 . V_29 ) )
V_57 -> V_107 = 1 ;
F_30 ( V_13 , V_57 ) ;
if ( V_57 -> V_106 || V_57 -> V_107 )
V_57 -> V_96 = V_13 -> V_208 ;
else
V_57 -> V_96 = F_46 ( V_13 -> V_116 , V_13 -> V_209 , V_13 -> V_210 ) ;
F_25 ( V_13 , V_57 ) ;
F_18 ( V_13 , V_39 -> V_45 [ 0 ] , V_57 ) ;
F_26 ( V_13 , V_57 ) ;
F_27 ( V_13 , V_57 ) ;
F_28 ( V_13 , V_57 , V_39 -> V_45 [ 0 ] ) ;
F_32 ( V_13 , V_39 -> V_45 [ 0 ] , V_26 . V_29 ) ;
}
F_47 ( & V_13 -> V_159 , V_142 ) ;
F_15 ( V_47 ) ;
if ( V_39 ) {
if ( V_13 -> V_161 & V_162 ) {
F_48 ( V_39 , V_13 ) ;
} else{
if ( (* V_13 -> V_160 )( V_39 , V_28 ) == 0 ) {
V_144 -> V_211 ++ ;
V_144 -> V_212 += F_49 ( V_39 -> V_198 ) ;
return 0 ;
}
F_8 ( V_39 ) ;
}
}
return 0 ;
V_196:
F_47 ( & V_13 -> V_159 , V_142 ) ;
F_50 ( V_28 ) ;
V_144 -> V_213 ++ ;
return 1 ;
}
