static int F_1 ( void )
{
return F_2 ( F_3 () -> V_1 ) . V_2 ;
}
static int F_4 ( enum V_3 V_4 )
{
switch ( V_4 ) {
case V_5 :
return V_6 ;
case V_7 :
return V_8 ;
case V_9 :
return V_10 ;
default:
return - V_11 ;
} ;
return - V_11 ;
}
static int F_5 ( struct V_12 * V_13 ,
struct V_14 * V_15 ,
const T_1 * V_16 ,
unsigned int V_17 )
{
F_6 ( V_18 , V_15 -> V_19 ) ;
struct V_20 V_21 ;
struct V_22 V_23 ;
struct V_24 V_25 ;
int V_26 = F_7 ( V_15 -> V_19 ) ;
int V_27 = F_8 ( V_15 -> V_19 ) ;
char V_28 [ V_26 ] ;
char V_29 [ V_26 ] ;
T_2 * V_30 ;
T_3 * V_31 ;
int V_32 , V_33 ;
memset ( V_28 , 0 , V_26 ) ;
memset ( V_29 , 0 , V_26 ) ;
V_18 -> V_34 = V_15 -> V_19 ;
V_18 -> V_35 = 0x0 ;
if ( V_17 > V_26 ) {
int V_36 = F_9 ( V_18 , V_16 ,
V_17 , V_28 ) ;
if ( V_36 )
return V_36 ;
memcpy ( V_29 , V_28 , V_27 ) ;
} else {
memcpy ( V_28 , V_16 , V_17 ) ;
memcpy ( V_29 , V_16 , V_17 ) ;
}
for ( V_32 = 0 ; V_32 < V_26 ; V_32 ++ ) {
char * V_37 = V_28 + V_32 ;
char * V_38 = V_29 + V_32 ;
* V_37 ^= 0x36 ;
* V_38 ^= 0x5C ;
}
if ( F_10 ( V_18 ) )
return - V_11 ;
if ( F_11 ( V_18 , V_28 , V_26 ) )
return - V_11 ;
V_30 = ( T_2 * ) V_13 -> V_39 . V_40 ;
V_31 = ( T_3 * ) V_30 ;
switch ( V_15 -> V_4 ) {
case V_5 :
if ( F_12 ( V_18 , & V_21 ) )
return - V_11 ;
for ( V_32 = 0 ; V_32 < V_27 > > 2 ; V_32 ++ , V_30 ++ )
* V_30 = F_13 ( * ( V_21 . V_41 + V_32 ) ) ;
break;
case V_7 :
if ( F_12 ( V_18 , & V_23 ) )
return - V_11 ;
for ( V_32 = 0 ; V_32 < V_27 > > 2 ; V_32 ++ , V_30 ++ )
* V_30 = F_13 ( * ( V_23 . V_41 + V_32 ) ) ;
break;
case V_9 :
if ( F_12 ( V_18 , & V_25 ) )
return - V_11 ;
for ( V_32 = 0 ; V_32 < V_27 > > 3 ; V_32 ++ , V_31 ++ )
* V_31 = F_14 ( * ( V_25 . V_41 + V_32 ) ) ;
break;
default:
return - V_11 ;
}
if ( F_10 ( V_18 ) )
return - V_11 ;
if ( F_11 ( V_18 , V_29 , V_26 ) )
return - V_11 ;
V_33 = F_15 ( F_4 ( V_15 -> V_4 ) , 8 ) ;
V_30 = ( T_2 * ) ( V_13 -> V_39 . V_40 + V_33 ) ;
V_31 = ( T_3 * ) V_30 ;
switch ( V_15 -> V_4 ) {
case V_5 :
if ( F_12 ( V_18 , & V_21 ) )
return - V_11 ;
for ( V_32 = 0 ; V_32 < V_27 > > 2 ; V_32 ++ , V_30 ++ )
* V_30 = F_13 ( * ( V_21 . V_41 + V_32 ) ) ;
break;
case V_7 :
if ( F_12 ( V_18 , & V_23 ) )
return - V_11 ;
for ( V_32 = 0 ; V_32 < V_27 > > 2 ; V_32 ++ , V_30 ++ )
* V_30 = F_13 ( * ( V_23 . V_41 + V_32 ) ) ;
break;
case V_9 :
if ( F_12 ( V_18 , & V_25 ) )
return - V_11 ;
for ( V_32 = 0 ; V_32 < V_27 > > 3 ; V_32 ++ , V_31 ++ )
* V_31 = F_14 ( * ( V_25 . V_41 + V_32 ) ) ;
break;
default:
return - V_11 ;
}
F_16 ( V_28 , V_26 ) ;
F_16 ( V_29 , V_26 ) ;
return 0 ;
}
static void F_17 ( struct V_42 * V_43 )
{
V_43 -> V_44 =
F_18 ( V_45 ) ;
V_43 -> V_46 = V_47 ;
V_43 -> V_48 =
F_19 ( V_49 ,
V_50 ) ;
F_20 ( V_43 -> V_51 ,
V_52 ) ;
F_21 ( V_43 -> V_51 ,
V_53 ) ;
F_22 ( V_43 -> V_51 ,
V_54 ) ;
F_23 ( V_43 -> V_51 ,
V_55 ) ;
}
static int F_24 ( struct V_14 * V_15 ,
int V_56 ,
struct V_57 * V_58 )
{
struct V_59 * V_60 = F_25 ( V_15 -> V_34 ) ;
unsigned int V_61 = F_26 ( V_60 ) -> V_62 ;
struct V_63 * V_64 = & V_15 -> V_65 -> V_66 ;
struct V_67 * V_68 = & V_64 -> V_68 ;
struct V_12 * V_13 =
(struct V_12 * ) ( ( char * ) V_64 +
sizeof( struct V_69 ) + V_58 -> V_70 ) ;
struct V_71 * V_72 = & V_15 -> V_73 ;
struct V_74 * V_75 = & V_72 -> V_75 ;
struct V_42 * V_43 = & V_72 -> V_76 ;
void * V_77 = & V_72 -> V_78 ;
struct V_79 * V_80 = V_77 ;
struct V_81 * V_82 = V_77 ;
V_68 -> V_83 . V_84 . V_85 = F_27 ( V_56 ) ;
memcpy ( V_68 -> V_83 . V_86 , V_58 -> V_87 , V_58 -> V_70 ) ;
V_13 -> V_39 . V_88 . V_89 . V_90 =
F_28 ( V_91 ,
V_15 -> V_4 , V_61 ) ;
V_13 -> V_39 . V_88 . V_92 . V_93 =
F_13 ( F_7 ( V_15 -> V_19 ) ) ;
if ( F_5 ( V_13 , V_15 , V_58 -> V_94 , V_58 -> V_95 ) )
return - V_11 ;
F_17 ( V_43 ) ;
V_43 -> V_96 = V_97 ;
F_29 ( V_43 -> V_51 ,
V_98 ) ;
F_30 ( V_43 -> V_51 ,
V_99 ) ;
F_31 ( V_43 -> V_51 ,
V_100 ) ;
V_75 -> V_101 . V_102 . V_103 = V_15 -> V_104 ;
V_75 -> V_101 . V_102 . V_105 = sizeof( struct V_106 ) >> 3 ;
V_80 -> V_107 = V_58 -> V_70 >> 3 ;
V_80 -> V_108 = V_109 >> 3 ;
V_80 -> V_110 = 0 ;
F_32 ( V_80 , V_111 ) ;
F_33 ( V_80 , V_112 ) ;
V_82 -> V_113 = ( ( char * ) V_13 - ( char * ) V_68 ) >> 3 ;
V_82 -> V_114 = V_115 ;
V_82 -> V_116 = V_61 ;
V_82 -> V_117 = V_61 ;
switch ( V_15 -> V_4 ) {
case V_5 :
V_82 -> V_118 =
F_15 ( V_6 , 8 ) ;
V_82 -> V_119 =
F_15 ( V_120 , 8 ) ;
break;
case V_7 :
V_82 -> V_118 = V_8 ;
V_82 -> V_119 = V_121 ;
break;
case V_9 :
V_82 -> V_118 = V_10 ;
V_82 -> V_119 = V_122 ;
break;
default:
break;
}
V_82 -> V_123 = V_82 -> V_113 +
( ( sizeof( struct V_69 ) +
F_15 ( V_82 -> V_118 , 8 ) ) >> 3 ) ;
F_32 ( V_82 , V_112 ) ;
F_33 ( V_82 , V_124 ) ;
return 0 ;
}
static int F_34 ( struct V_14 * V_15 ,
int V_56 ,
struct V_57 * V_58 )
{
struct V_59 * V_60 = F_25 ( V_15 -> V_34 ) ;
unsigned int V_61 = F_26 ( V_60 ) -> V_62 ;
struct V_125 * V_126 = & V_15 -> V_127 -> V_128 ;
struct V_12 * V_13 = & V_126 -> V_13 ;
struct V_67 * V_68 =
(struct V_67 * ) ( ( char * ) V_126 +
sizeof( struct V_69 ) +
F_35 ( F_8 ( V_15 -> V_19 ) , 8 ) * 2 ) ;
struct V_71 * V_72 = & V_15 -> V_129 ;
struct V_74 * V_75 = & V_72 -> V_75 ;
struct V_42 * V_43 = & V_72 -> V_76 ;
void * V_77 = & V_72 -> V_78 ;
struct V_79 * V_80 = V_77 ;
struct V_81 * V_82 = V_77 ;
struct V_130 * V_131 =
(struct V_130 * )
( ( char * ) & V_72 -> V_132 +
sizeof( struct V_133 ) ) ;
V_68 -> V_83 . V_84 . V_85 = F_36 ( V_56 ) ;
memcpy ( V_68 -> V_83 . V_86 , V_58 -> V_87 , V_58 -> V_70 ) ;
V_13 -> V_39 . V_88 . V_89 . V_90 =
F_28 ( V_91 ,
V_15 -> V_4 ,
V_61 ) ;
V_13 -> V_39 . V_88 . V_92 . V_93 =
F_13 ( F_7 ( V_15 -> V_19 ) ) ;
if ( F_5 ( V_13 , V_15 , V_58 -> V_94 , V_58 -> V_95 ) )
return - V_11 ;
F_17 ( V_43 ) ;
V_43 -> V_96 = V_134 ;
F_29 ( V_43 -> V_51 ,
V_98 ) ;
F_30 ( V_43 -> V_51 ,
V_135 ) ;
F_31 ( V_43 -> V_51 ,
V_136 ) ;
V_75 -> V_101 . V_102 . V_103 = V_15 -> V_137 ;
V_75 -> V_101 . V_102 . V_105 = sizeof( struct V_106 ) >> 3 ;
V_80 -> V_107 = V_58 -> V_70 >> 3 ;
V_80 -> V_108 = V_109 >> 3 ;
V_80 -> V_110 =
( sizeof( struct V_69 ) +
F_35 ( F_8 ( V_15 -> V_19 ) , 8 ) * 2 ) >> 3 ;
F_32 ( V_80 , V_111 ) ;
F_33 ( V_80 , V_124 ) ;
V_82 -> V_113 = 0 ;
V_82 -> V_114 = V_115 ;
V_82 -> V_116 = V_61 ;
V_82 -> V_117 = V_61 ;
switch ( V_15 -> V_4 ) {
case V_5 :
V_82 -> V_118 =
F_15 ( V_6 , 8 ) ;
V_82 -> V_119 =
F_15 ( V_120 , 8 ) ;
break;
case V_7 :
V_82 -> V_118 = V_8 ;
V_82 -> V_119 = V_121 ;
break;
case V_9 :
V_82 -> V_118 = V_10 ;
V_82 -> V_119 = V_122 ;
break;
default:
break;
}
V_82 -> V_123 = V_82 -> V_113 +
( ( sizeof( struct V_69 ) +
F_15 ( V_82 -> V_118 , 8 ) ) >> 3 ) ;
V_131 -> V_138 = V_61 ;
F_32 ( V_82 , V_112 ) ;
F_33 ( V_82 , V_111 ) ;
return 0 ;
}
static void F_37 ( struct V_139 * V_15 ,
struct V_71 * V_140 ,
struct V_67 * V_141 ,
const T_1 * V_86 , unsigned int V_142 )
{
struct V_74 * V_75 = & V_140 -> V_75 ;
struct V_42 * V_43 = & V_140 -> V_76 ;
struct V_79 * V_78 = ( void * ) & V_140 -> V_78 ;
memcpy ( V_141 -> V_83 . V_86 , V_86 , V_142 ) ;
F_17 ( V_43 ) ;
V_43 -> V_96 = V_143 ;
V_75 -> V_101 . V_102 . V_105 =
sizeof( struct V_67 ) >> 3 ;
V_78 -> V_107 = V_142 >> 3 ;
V_78 -> V_108 = V_109 >> 3 ;
V_78 -> V_110 = 0 ;
F_32 ( V_78 , V_111 ) ;
F_33 ( V_78 , V_124 ) ;
}
static void F_38 ( struct V_139 * V_15 ,
int V_56 , const T_1 * V_86 ,
unsigned int V_142 )
{
struct V_67 * V_65 = V_15 -> V_65 ;
struct V_71 * V_140 = & V_15 -> V_73 ;
struct V_74 * V_75 = & V_140 -> V_75 ;
F_37 ( V_15 , V_140 , V_65 , V_86 , V_142 ) ;
V_75 -> V_101 . V_102 . V_103 = V_15 -> V_104 ;
V_65 -> V_83 . V_84 . V_85 = F_27 ( V_56 ) ;
}
static void F_39 ( struct V_139 * V_15 ,
int V_56 , const T_1 * V_86 ,
unsigned int V_142 )
{
struct V_67 * V_127 = V_15 -> V_127 ;
struct V_71 * V_140 = & V_15 -> V_129 ;
struct V_74 * V_75 = & V_140 -> V_75 ;
F_37 ( V_15 , V_140 , V_127 , V_86 , V_142 ) ;
V_75 -> V_101 . V_102 . V_103 = V_15 -> V_137 ;
V_127 -> V_83 . V_84 . V_85 = F_36 ( V_56 ) ;
}
static int F_40 ( int V_144 , int * V_56 )
{
switch ( V_144 ) {
case V_145 :
* V_56 = V_146 ;
break;
case V_147 :
* V_56 = V_148 ;
break;
case V_149 :
* V_56 = V_150 ;
break;
default:
return - V_151 ;
}
return 0 ;
}
static int F_41 ( struct V_14 * V_15 ,
const T_1 * V_86 , unsigned int V_142 )
{
struct V_57 V_58 ;
int V_56 ;
if ( F_42 ( V_152 , V_15 -> V_153 , V_109 ) )
return - V_11 ;
if ( F_43 ( & V_58 , V_86 , V_142 ) )
goto V_154;
if ( F_40 ( V_58 . V_70 , & V_56 ) )
goto V_154;
if ( F_24 ( V_15 , V_56 , & V_58 ) )
goto error;
if ( F_34 ( V_15 , V_56 , & V_58 ) )
goto error;
return 0 ;
V_154:
F_44 ( V_15 -> V_34 , V_155 ) ;
return - V_151 ;
error:
return - V_11 ;
}
static int F_45 ( struct V_139 * V_15 ,
const T_1 * V_86 ,
unsigned int V_142 )
{
int V_56 ;
if ( F_40 ( V_142 , & V_56 ) )
goto V_154;
F_38 ( V_15 , V_56 , V_86 , V_142 ) ;
F_39 ( V_15 , V_56 , V_86 , V_142 ) ;
return 0 ;
V_154:
F_44 ( V_15 -> V_34 , V_155 ) ;
return - V_151 ;
}
static int F_46 ( struct V_59 * V_34 , const T_1 * V_86 ,
unsigned int V_142 )
{
struct V_14 * V_15 = F_47 ( V_34 ) ;
struct V_156 * V_157 ;
F_48 ( & V_15 -> V_158 ) ;
if ( V_15 -> V_65 ) {
V_157 = & F_49 ( V_15 -> V_159 -> V_160 ) ;
memset ( V_15 -> V_65 , 0 , sizeof( * V_15 -> V_65 ) ) ;
memset ( V_15 -> V_127 , 0 , sizeof( * V_15 -> V_127 ) ) ;
memset ( & V_15 -> V_73 , 0 , sizeof( V_15 -> V_73 ) ) ;
memset ( & V_15 -> V_129 , 0 , sizeof( V_15 -> V_129 ) ) ;
} else {
int V_161 = F_1 () ;
struct V_162 * V_159 =
F_50 ( V_161 ) ;
if ( ! V_159 ) {
F_51 ( & V_15 -> V_158 ) ;
return - V_151 ;
}
V_157 = & F_49 ( V_159 -> V_160 ) ;
V_15 -> V_159 = V_159 ;
V_15 -> V_65 = F_52 ( V_157 , sizeof( * V_15 -> V_65 ) ,
& V_15 -> V_104 ,
V_163 ) ;
if ( ! V_15 -> V_65 ) {
F_51 ( & V_15 -> V_158 ) ;
return - V_164 ;
}
V_15 -> V_127 = F_52 ( V_157 , sizeof( * V_15 -> V_127 ) ,
& V_15 -> V_137 ,
V_163 ) ;
if ( ! V_15 -> V_127 ) {
F_51 ( & V_15 -> V_158 ) ;
goto V_165;
}
}
F_51 ( & V_15 -> V_158 ) ;
if ( F_41 ( V_15 , V_86 , V_142 ) )
goto V_166;
return 0 ;
V_166:
memset ( V_15 -> V_127 , 0 , sizeof( struct V_106 ) ) ;
F_53 ( V_157 , sizeof( struct V_106 ) ,
V_15 -> V_127 , V_15 -> V_137 ) ;
V_15 -> V_127 = NULL ;
V_165:
memset ( V_15 -> V_65 , 0 , sizeof( struct V_106 ) ) ;
F_53 ( V_157 , sizeof( struct V_106 ) ,
V_15 -> V_65 , V_15 -> V_104 ) ;
V_15 -> V_65 = NULL ;
return - V_164 ;
}
static void F_54 ( struct V_162 * V_159 ,
struct V_167 * V_168 )
{
struct V_156 * V_157 = & F_49 ( V_159 -> V_160 ) ;
struct V_169 * V_170 = V_168 -> V_171 . V_170 ;
struct V_169 * V_172 = V_168 -> V_171 . V_172 ;
T_4 V_173 = V_168 -> V_171 . V_173 ;
T_4 V_174 = V_168 -> V_171 . V_175 ;
T_5 V_176 = V_168 -> V_171 . V_176 ;
T_5 V_177 = V_168 -> V_171 . V_177 ;
int V_32 ;
for ( V_32 = 0 ; V_32 < V_170 -> V_178 ; V_32 ++ )
F_55 ( V_157 , V_170 -> V_179 [ V_32 ] . V_180 ,
V_170 -> V_179 [ V_32 ] . V_181 , V_182 ) ;
F_55 ( V_157 , V_173 , V_176 , V_183 ) ;
F_56 ( V_170 ) ;
if ( V_173 != V_174 ) {
int V_184 = V_172 -> V_178 - V_172 -> V_185 ;
for ( V_32 = V_184 ; V_32 < V_172 -> V_178 ; V_32 ++ ) {
F_55 ( V_157 , V_172 -> V_179 [ V_32 ] . V_180 ,
V_172 -> V_179 [ V_32 ] . V_181 ,
V_182 ) ;
}
F_55 ( V_157 , V_174 , V_177 , V_183 ) ;
F_56 ( V_172 ) ;
}
}
static int F_57 ( struct V_162 * V_159 ,
struct V_186 * V_187 , int V_188 ,
struct V_186 * V_189 ,
struct V_186 * V_190 , T_1 * V_191 ,
T_1 V_192 ,
struct V_167 * V_168 )
{
struct V_156 * V_157 = & F_49 ( V_159 -> V_160 ) ;
int V_32 , V_193 = 0 , V_194 = 0 ;
int V_195 = F_58 ( V_189 ) , V_196 = F_58 ( V_187 ) ;
struct V_169 * V_197 ;
struct V_169 * V_198 = NULL ;
T_4 V_173 ;
T_4 V_175 = 0 ;
struct V_186 * V_199 ;
T_5 V_177 , V_176 = sizeof( struct V_169 ) +
( ( 1 + V_195 + V_196 ) * sizeof( struct V_200 ) ) ;
if ( F_59 ( ! V_195 ) )
return - V_151 ;
V_197 = F_60 ( V_176 , V_163 ,
F_61 ( & F_49 ( V_159 -> V_160 ) ) ) ;
if ( F_59 ( ! V_197 ) )
return - V_164 ;
V_173 = F_62 ( V_157 , V_197 , V_176 , V_183 ) ;
if ( F_59 ( F_63 ( V_157 , V_173 ) ) )
goto V_201;
F_64 (assoc, sg, assoc_n, i) {
if ( ! V_199 -> V_202 )
continue;
if ( ! ( V_188 > 0 ) )
break;
V_197 -> V_179 [ V_193 ] . V_180 =
F_62 ( V_157 , F_65 ( V_199 ) ,
F_66 ( int , V_188 , V_199 -> V_202 ) ,
V_182 ) ;
V_197 -> V_179 [ V_193 ] . V_181 = F_66 ( int , V_188 , V_199 -> V_202 ) ;
if ( F_59 ( F_63 ( V_157 , V_197 -> V_179 [ V_193 ] . V_180 ) ) )
goto V_201;
V_193 ++ ;
V_188 -= V_199 -> V_202 ;
}
if ( V_192 ) {
V_197 -> V_179 [ V_193 ] . V_180 = F_62 ( V_157 , V_191 , V_192 ,
V_182 ) ;
V_197 -> V_179 [ V_193 ] . V_181 = V_192 ;
if ( F_59 ( F_63 ( V_157 , V_197 -> V_179 [ V_193 ] . V_180 ) ) )
goto V_201;
V_193 ++ ;
}
F_64 (sgl, sg, n, i) {
int V_203 = V_194 + V_193 ;
if ( ! V_199 -> V_202 )
continue;
V_197 -> V_179 [ V_203 ] . V_180 = F_62 ( V_157 , F_65 ( V_199 ) ,
V_199 -> V_202 ,
V_182 ) ;
V_197 -> V_179 [ V_203 ] . V_181 = V_199 -> V_202 ;
if ( F_59 ( F_63 ( V_157 , V_197 -> V_179 [ V_203 ] . V_180 ) ) )
goto V_201;
V_194 ++ ;
}
V_197 -> V_178 = V_194 + V_193 ;
V_168 -> V_171 . V_170 = V_197 ;
V_168 -> V_171 . V_173 = V_173 ;
V_168 -> V_171 . V_176 = V_176 ;
if ( V_189 != V_190 ) {
struct V_200 * V_179 ;
V_195 = F_58 ( V_190 ) ;
V_177 = sizeof( struct V_169 ) +
( ( 1 + V_195 + V_196 ) * sizeof( struct V_200 ) ) ;
V_194 = 0 ;
V_198 = F_60 ( V_177 , V_163 ,
F_61 ( & F_49 ( V_159 -> V_160 ) ) ) ;
if ( F_59 ( ! V_198 ) )
goto V_201;
V_175 = F_62 ( V_157 , V_198 , V_177 , V_183 ) ;
if ( F_59 ( F_63 ( V_157 , V_175 ) ) )
goto V_201;
V_179 = V_198 -> V_179 ;
for ( V_32 = 0 ; V_32 < V_193 ; V_32 ++ ) {
V_179 [ V_32 ] . V_181 = V_197 -> V_179 [ V_32 ] . V_181 ;
V_179 [ V_32 ] . V_180 = V_197 -> V_179 [ V_32 ] . V_180 ;
}
F_64 (sglout, sg, n, i) {
int V_203 = V_194 + V_193 ;
if ( ! V_199 -> V_202 )
continue;
V_179 [ V_203 ] . V_180 = F_62 ( V_157 , F_65 ( V_199 ) ,
V_199 -> V_202 ,
V_182 ) ;
if ( F_59 ( F_63 ( V_157 , V_179 [ V_203 ] . V_180 ) ) )
goto V_201;
V_179 [ V_203 ] . V_181 = V_199 -> V_202 ;
V_194 ++ ;
}
V_198 -> V_178 = V_194 + V_193 ;
V_198 -> V_185 = V_194 ;
V_168 -> V_171 . V_172 = V_198 ;
V_168 -> V_171 . V_175 = V_175 ;
V_168 -> V_171 . V_177 = V_177 ;
} else {
V_168 -> V_171 . V_175 = V_168 -> V_171 . V_173 ;
V_168 -> V_171 . V_177 = 0 ;
}
return 0 ;
V_201:
F_67 ( V_157 , L_1 ) ;
V_194 = 0 ;
for ( V_32 = 0 ; V_32 < V_195 + V_193 ; V_32 ++ )
if ( ! F_63 ( V_157 , V_197 -> V_179 [ V_32 ] . V_180 ) )
F_55 ( V_157 , V_197 -> V_179 [ V_32 ] . V_180 ,
V_197 -> V_179 [ V_32 ] . V_181 ,
V_182 ) ;
if ( ! F_63 ( V_157 , V_173 ) )
F_55 ( V_157 , V_173 , V_176 , V_183 ) ;
F_56 ( V_197 ) ;
if ( V_189 != V_190 && V_198 ) {
V_195 = F_58 ( V_190 ) ;
for ( V_32 = V_193 ; V_32 < V_195 + V_193 ; V_32 ++ )
if ( ! F_63 ( V_157 , V_198 -> V_179 [ V_32 ] . V_180 ) )
F_55 ( V_157 , V_198 -> V_179 [ V_32 ] . V_180 ,
V_198 -> V_179 [ V_32 ] . V_181 ,
V_182 ) ;
if ( ! F_63 ( V_157 , V_175 ) )
F_55 ( V_157 , V_175 , V_177 , V_183 ) ;
F_56 ( V_198 ) ;
}
return - V_164 ;
}
static void F_68 ( struct V_204 * V_205 ,
struct V_167 * V_168 )
{
struct V_14 * V_15 = V_168 -> V_206 ;
struct V_162 * V_159 = V_15 -> V_159 ;
struct V_207 * V_208 = V_168 -> V_209 ;
T_1 V_210 = V_205 -> V_211 . V_212 ;
int V_213 = 0 , V_214 = F_69 ( V_210 ) ;
F_54 ( V_159 , V_168 ) ;
if ( F_59 ( V_214 != V_215 ) )
V_213 = - V_216 ;
V_208 -> V_217 . V_218 ( & V_208 -> V_217 , V_213 ) ;
}
static void F_70 ( struct V_204 * V_205 ,
struct V_167 * V_168 )
{
struct V_139 * V_15 = V_168 -> V_219 ;
struct V_162 * V_159 = V_15 -> V_159 ;
struct V_220 * V_208 = V_168 -> V_221 ;
T_1 V_210 = V_205 -> V_211 . V_212 ;
int V_213 = 0 , V_214 = F_69 ( V_210 ) ;
F_54 ( V_159 , V_168 ) ;
if ( F_59 ( V_214 != V_215 ) )
V_213 = - V_151 ;
V_208 -> V_217 . V_218 ( & V_208 -> V_217 , V_213 ) ;
}
void F_71 ( void * V_222 )
{
struct V_204 * V_205 = V_222 ;
struct V_167 * V_168 =
( void * ) ( V_223 long ) V_205 -> V_224 ;
V_168 -> V_225 ( V_205 , V_168 ) ;
}
static int F_72 ( struct V_207 * V_208 )
{
struct V_59 * V_60 = F_73 ( V_208 ) ;
struct V_226 * V_34 = F_74 ( V_60 ) ;
struct V_14 * V_15 = F_75 ( V_34 ) ;
struct V_167 * V_168 = F_76 ( V_208 ) ;
struct V_133 * V_227 ;
struct V_130 * V_131 ;
struct V_71 * V_228 ;
int V_229 = F_26 ( V_60 ) -> V_62 ;
int V_36 , V_230 = 0 ;
V_36 = F_57 ( V_15 -> V_159 , V_208 -> V_187 , V_208 -> V_188 ,
V_208 -> V_231 , V_208 -> V_232 , V_208 -> V_191 ,
V_109 , V_168 ) ;
if ( F_59 ( V_36 ) )
return V_36 ;
V_228 = & V_168 -> V_140 ;
* V_228 = V_15 -> V_129 ;
V_168 -> V_206 = V_15 ;
V_168 -> V_209 = V_208 ;
V_168 -> V_225 = F_68 ;
V_168 -> V_140 . V_233 . V_224 = ( V_234 ) ( V_223 long ) V_168 ;
V_168 -> V_140 . V_233 . V_235 = V_168 -> V_171 . V_173 ;
V_168 -> V_140 . V_233 . V_236 = V_168 -> V_171 . V_175 ;
V_227 = ( void * ) & V_168 -> V_140 . V_132 ;
V_227 -> V_237 = V_208 -> V_238 - V_229 ;
V_227 -> V_239 = V_208 -> V_188 + V_109 ;
memcpy ( V_227 -> V_101 . V_240 , V_208 -> V_191 , V_109 ) ;
V_131 = ( void * ) ( ( T_1 * ) V_227 + sizeof( * V_227 ) ) ;
V_131 -> V_241 = 0 ;
V_131 -> V_242 = V_208 -> V_188 +
V_227 -> V_237 + V_109 ;
do {
V_36 = F_77 ( V_15 -> V_159 -> V_243 , ( V_244 * ) V_228 ) ;
} while ( V_36 == - V_245 && V_230 ++ < 10 );
if ( V_36 == - V_245 ) {
F_54 ( V_15 -> V_159 , V_168 ) ;
return - V_246 ;
}
return - V_247 ;
}
static int F_78 ( struct V_207 * V_208 , T_1 * V_191 ,
int V_248 )
{
struct V_59 * V_60 = F_73 ( V_208 ) ;
struct V_226 * V_34 = F_74 ( V_60 ) ;
struct V_14 * V_15 = F_75 ( V_34 ) ;
struct V_167 * V_168 = F_76 ( V_208 ) ;
struct V_133 * V_227 ;
struct V_130 * V_131 ;
struct V_71 * V_228 ;
int V_36 , V_230 = 0 ;
V_36 = F_57 ( V_15 -> V_159 , V_208 -> V_187 , V_208 -> V_188 ,
V_208 -> V_231 , V_208 -> V_232 , V_191 , V_109 ,
V_168 ) ;
if ( F_59 ( V_36 ) )
return V_36 ;
V_228 = & V_168 -> V_140 ;
* V_228 = V_15 -> V_73 ;
V_168 -> V_206 = V_15 ;
V_168 -> V_209 = V_208 ;
V_168 -> V_225 = F_68 ;
V_168 -> V_140 . V_233 . V_224 = ( V_234 ) ( V_223 long ) V_168 ;
V_168 -> V_140 . V_233 . V_235 = V_168 -> V_171 . V_173 ;
V_168 -> V_140 . V_233 . V_236 = V_168 -> V_171 . V_175 ;
V_227 = ( void * ) & V_168 -> V_140 . V_132 ;
V_131 = ( void * ) ( ( T_1 * ) V_227 + sizeof( * V_227 ) ) ;
if ( V_248 ) {
V_227 -> V_237 = V_208 -> V_238 + V_109 ;
V_227 -> V_239 = V_208 -> V_188 ;
} else {
memcpy ( V_227 -> V_101 . V_240 , V_191 , V_109 ) ;
V_227 -> V_237 = V_208 -> V_238 ;
V_227 -> V_239 = V_208 -> V_188 + V_109 ;
}
V_131 -> V_241 = 0 ;
V_131 -> V_242 = V_208 -> V_188 + V_208 -> V_238 + V_109 ;
do {
V_36 = F_77 ( V_15 -> V_159 -> V_243 , ( V_244 * ) V_228 ) ;
} while ( V_36 == - V_245 && V_230 ++ < 10 );
if ( V_36 == - V_245 ) {
F_54 ( V_15 -> V_159 , V_168 ) ;
return - V_246 ;
}
return - V_247 ;
}
static int F_79 ( struct V_207 * V_208 )
{
return F_78 ( V_208 , V_208 -> V_191 , 0 ) ;
}
static int F_80 ( struct V_249 * V_140 )
{
struct V_59 * V_60 = F_73 ( & V_140 -> V_208 ) ;
struct V_226 * V_34 = F_74 ( V_60 ) ;
struct V_14 * V_15 = F_75 ( V_34 ) ;
T_3 V_250 ;
memcpy ( V_140 -> V_251 , V_15 -> V_153 , V_109 ) ;
V_250 = F_14 ( V_140 -> V_250 ) ;
memcpy ( V_140 -> V_251 + V_109 - sizeof( V_234 ) ,
& V_250 , sizeof( V_234 ) ) ;
return F_78 ( & V_140 -> V_208 , V_140 -> V_251 , 1 ) ;
}
static int F_81 ( struct V_252 * V_34 ,
const T_1 * V_86 ,
unsigned int V_142 )
{
struct V_139 * V_15 = F_82 ( V_34 ) ;
struct V_156 * V_157 ;
F_48 ( & V_15 -> V_158 ) ;
if ( V_15 -> V_65 ) {
V_157 = & F_49 ( V_15 -> V_159 -> V_160 ) ;
memset ( V_15 -> V_65 , 0 , sizeof( * V_15 -> V_65 ) ) ;
memset ( V_15 -> V_127 , 0 , sizeof( * V_15 -> V_127 ) ) ;
memset ( & V_15 -> V_73 , 0 , sizeof( V_15 -> V_73 ) ) ;
memset ( & V_15 -> V_129 , 0 , sizeof( V_15 -> V_129 ) ) ;
} else {
int V_161 = F_1 () ;
struct V_162 * V_159 =
F_50 ( V_161 ) ;
if ( ! V_159 ) {
F_51 ( & V_15 -> V_158 ) ;
return - V_151 ;
}
V_157 = & F_49 ( V_159 -> V_160 ) ;
V_15 -> V_159 = V_159 ;
V_15 -> V_65 = F_52 ( V_157 , sizeof( * V_15 -> V_65 ) ,
& V_15 -> V_104 ,
V_163 ) ;
if ( ! V_15 -> V_65 ) {
F_51 ( & V_15 -> V_158 ) ;
return - V_164 ;
}
V_15 -> V_127 = F_52 ( V_157 , sizeof( * V_15 -> V_127 ) ,
& V_15 -> V_137 ,
V_163 ) ;
if ( ! V_15 -> V_127 ) {
F_51 ( & V_15 -> V_158 ) ;
goto V_165;
}
}
F_51 ( & V_15 -> V_158 ) ;
if ( F_45 ( V_15 , V_86 , V_142 ) )
goto V_166;
return 0 ;
V_166:
memset ( V_15 -> V_127 , 0 , sizeof( * V_15 -> V_65 ) ) ;
F_53 ( V_157 , sizeof( * V_15 -> V_65 ) ,
V_15 -> V_127 , V_15 -> V_137 ) ;
V_15 -> V_127 = NULL ;
V_165:
memset ( V_15 -> V_65 , 0 , sizeof( * V_15 -> V_127 ) ) ;
F_53 ( V_157 , sizeof( * V_15 -> V_127 ) ,
V_15 -> V_65 , V_15 -> V_104 ) ;
V_15 -> V_65 = NULL ;
return - V_164 ;
}
static int F_83 ( struct V_220 * V_140 )
{
struct V_252 * V_253 = F_84 ( V_140 ) ;
struct V_226 * V_34 = F_85 ( V_253 ) ;
struct V_139 * V_15 = F_75 ( V_34 ) ;
struct V_167 * V_168 = F_86 ( V_140 ) ;
struct V_133 * V_227 ;
struct V_71 * V_228 ;
int V_36 , V_230 = 0 ;
V_36 = F_57 ( V_15 -> V_159 , NULL , 0 , V_140 -> V_231 , V_140 -> V_232 ,
NULL , 0 , V_168 ) ;
if ( F_59 ( V_36 ) )
return V_36 ;
V_228 = & V_168 -> V_140 ;
* V_228 = V_15 -> V_73 ;
V_168 -> V_219 = V_15 ;
V_168 -> V_221 = V_140 ;
V_168 -> V_225 = F_70 ;
V_168 -> V_140 . V_233 . V_224 = ( V_234 ) ( V_223 long ) V_168 ;
V_168 -> V_140 . V_233 . V_235 = V_168 -> V_171 . V_173 ;
V_168 -> V_140 . V_233 . V_236 = V_168 -> V_171 . V_175 ;
V_227 = ( void * ) & V_168 -> V_140 . V_132 ;
V_227 -> V_237 = V_140 -> V_254 ;
V_227 -> V_239 = 0 ;
memcpy ( V_227 -> V_101 . V_240 , V_140 -> V_255 , V_109 ) ;
do {
V_36 = F_77 ( V_15 -> V_159 -> V_243 , ( V_244 * ) V_228 ) ;
} while ( V_36 == - V_245 && V_230 ++ < 10 );
if ( V_36 == - V_245 ) {
F_54 ( V_15 -> V_159 , V_168 ) ;
return - V_246 ;
}
return - V_247 ;
}
static int F_87 ( struct V_220 * V_140 )
{
struct V_252 * V_253 = F_84 ( V_140 ) ;
struct V_226 * V_34 = F_85 ( V_253 ) ;
struct V_139 * V_15 = F_75 ( V_34 ) ;
struct V_167 * V_168 = F_86 ( V_140 ) ;
struct V_133 * V_227 ;
struct V_71 * V_228 ;
int V_36 , V_230 = 0 ;
V_36 = F_57 ( V_15 -> V_159 , NULL , 0 , V_140 -> V_231 , V_140 -> V_232 ,
NULL , 0 , V_168 ) ;
if ( F_59 ( V_36 ) )
return V_36 ;
V_228 = & V_168 -> V_140 ;
* V_228 = V_15 -> V_129 ;
V_168 -> V_219 = V_15 ;
V_168 -> V_221 = V_140 ;
V_168 -> V_225 = F_70 ;
V_168 -> V_140 . V_233 . V_224 = ( V_234 ) ( V_223 long ) V_168 ;
V_168 -> V_140 . V_233 . V_235 = V_168 -> V_171 . V_173 ;
V_168 -> V_140 . V_233 . V_236 = V_168 -> V_171 . V_175 ;
V_227 = ( void * ) & V_168 -> V_140 . V_132 ;
V_227 -> V_237 = V_140 -> V_254 ;
V_227 -> V_239 = 0 ;
memcpy ( V_227 -> V_101 . V_240 , V_140 -> V_255 , V_109 ) ;
do {
V_36 = F_77 ( V_15 -> V_159 -> V_243 , ( V_244 * ) V_228 ) ;
} while ( V_36 == - V_245 && V_230 ++ < 10 );
if ( V_36 == - V_245 ) {
F_54 ( V_15 -> V_159 , V_168 ) ;
return - V_246 ;
}
return - V_247 ;
}
static int F_88 ( struct V_226 * V_34 ,
enum V_3 V_13 ,
const char * V_256 )
{
struct V_14 * V_15 = F_75 ( V_34 ) ;
V_15 -> V_19 = F_89 ( V_256 , 0 , 0 ) ;
if ( F_90 ( V_15 -> V_19 ) )
return - V_11 ;
F_91 ( & V_15 -> V_158 ) ;
V_15 -> V_4 = V_13 ;
F_92 ( F_25 ( V_34 ) ,
sizeof( struct V_207 ) +
sizeof( struct V_167 ) ) ;
V_15 -> V_34 = V_34 ;
return 0 ;
}
static int F_93 ( struct V_226 * V_34 )
{
return F_88 ( V_34 , V_5 , L_2 ) ;
}
static int F_94 ( struct V_226 * V_34 )
{
return F_88 ( V_34 , V_7 , L_3 ) ;
}
static int F_95 ( struct V_226 * V_34 )
{
return F_88 ( V_34 , V_9 , L_4 ) ;
}
static void F_96 ( struct V_226 * V_34 )
{
struct V_14 * V_15 = F_75 ( V_34 ) ;
struct V_162 * V_159 = V_15 -> V_159 ;
struct V_156 * V_157 ;
if ( ! F_90 ( V_15 -> V_19 ) )
F_97 ( V_15 -> V_19 ) ;
if ( ! V_159 )
return;
V_157 = & F_49 ( V_159 -> V_160 ) ;
if ( V_15 -> V_65 ) {
memset ( V_15 -> V_65 , 0 , sizeof( struct V_106 ) ) ;
F_53 ( V_157 , sizeof( struct V_106 ) ,
V_15 -> V_65 , V_15 -> V_104 ) ;
}
if ( V_15 -> V_127 ) {
memset ( V_15 -> V_127 , 0 , sizeof( struct V_106 ) ) ;
F_53 ( V_157 , sizeof( struct V_106 ) ,
V_15 -> V_127 , V_15 -> V_137 ) ;
}
F_98 ( V_159 ) ;
}
static int F_99 ( struct V_226 * V_34 )
{
struct V_139 * V_15 = F_75 ( V_34 ) ;
F_91 ( & V_15 -> V_158 ) ;
V_34 -> V_257 . V_258 = sizeof( struct V_220 ) +
sizeof( struct V_167 ) ;
V_15 -> V_34 = V_34 ;
return 0 ;
}
static void F_100 ( struct V_226 * V_34 )
{
struct V_139 * V_15 = F_75 ( V_34 ) ;
struct V_162 * V_159 = V_15 -> V_159 ;
struct V_156 * V_157 ;
if ( ! V_159 )
return;
V_157 = & F_49 ( V_159 -> V_160 ) ;
if ( V_15 -> V_65 ) {
memset ( V_15 -> V_65 , 0 ,
sizeof( struct V_67 ) ) ;
F_53 ( V_157 ,
sizeof( struct V_67 ) ,
V_15 -> V_65 , V_15 -> V_104 ) ;
}
if ( V_15 -> V_127 ) {
memset ( V_15 -> V_127 , 0 ,
sizeof( struct V_67 ) ) ;
F_53 ( V_157 ,
sizeof( struct V_67 ) ,
V_15 -> V_127 , V_15 -> V_137 ) ;
}
F_98 ( V_159 ) ;
}
int F_101 ( void )
{
int V_36 = 0 ;
F_102 ( & V_259 ) ;
if ( ++ V_260 == 1 ) {
int V_32 ;
for ( V_32 = 0 ; V_32 < F_103 ( V_261 ) ; V_32 ++ )
V_261 [ V_32 ] . V_262 =
( V_261 [ V_32 ] . V_263 == & V_264 ) ?
V_265 | V_266 :
V_267 | V_266 ;
V_36 = F_104 ( V_261 , F_103 ( V_261 ) ) ;
}
F_105 ( & V_259 ) ;
return V_36 ;
}
int F_106 ( void )
{
int V_36 = 0 ;
F_102 ( & V_259 ) ;
if ( -- V_260 == 0 )
V_36 = F_107 ( V_261 , F_103 ( V_261 ) ) ;
F_105 ( & V_259 ) ;
return V_36 ;
}
int F_108 ( void )
{
F_109 () ;
return 0 ;
}
void F_110 ( void )
{
F_111 () ;
}
