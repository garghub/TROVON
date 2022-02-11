static int F_1 ( enum V_1 V_2 )
{
switch ( V_2 ) {
case V_3 :
return V_4 ;
case V_5 :
return V_6 ;
case V_7 :
return V_8 ;
default:
return - V_9 ;
} ;
return - V_9 ;
}
static int F_2 ( struct V_10 * V_11 ,
struct V_12 * V_13 ,
const T_1 * V_14 ,
unsigned int V_15 )
{
F_3 ( V_16 , V_13 -> V_17 ) ;
struct V_18 V_19 ;
struct V_20 V_21 ;
struct V_22 V_23 ;
int V_24 = F_4 ( V_13 -> V_17 ) ;
int V_25 = F_5 ( V_13 -> V_17 ) ;
char V_26 [ V_24 ] ;
char V_27 [ V_24 ] ;
T_2 * V_28 ;
T_3 * V_29 ;
int V_30 , V_31 ;
memset ( V_26 , 0 , V_24 ) ;
memset ( V_27 , 0 , V_24 ) ;
V_16 -> V_32 = V_13 -> V_17 ;
V_16 -> V_33 = 0x0 ;
if ( V_15 > V_24 ) {
int V_34 = F_6 ( V_16 , V_14 ,
V_15 , V_26 ) ;
if ( V_34 )
return V_34 ;
memcpy ( V_27 , V_26 , V_25 ) ;
} else {
memcpy ( V_26 , V_14 , V_15 ) ;
memcpy ( V_27 , V_14 , V_15 ) ;
}
for ( V_30 = 0 ; V_30 < V_24 ; V_30 ++ ) {
char * V_35 = V_26 + V_30 ;
char * V_36 = V_27 + V_30 ;
* V_35 ^= V_37 ;
* V_36 ^= V_38 ;
}
if ( F_7 ( V_16 ) )
return - V_9 ;
if ( F_8 ( V_16 , V_26 , V_24 ) )
return - V_9 ;
V_28 = ( T_2 * ) V_11 -> V_39 . V_40 ;
V_29 = ( T_3 * ) V_28 ;
switch ( V_13 -> V_2 ) {
case V_3 :
if ( F_9 ( V_16 , & V_19 ) )
return - V_9 ;
for ( V_30 = 0 ; V_30 < V_25 > > 2 ; V_30 ++ , V_28 ++ )
* V_28 = F_10 ( * ( V_19 . V_41 + V_30 ) ) ;
break;
case V_5 :
if ( F_9 ( V_16 , & V_21 ) )
return - V_9 ;
for ( V_30 = 0 ; V_30 < V_25 > > 2 ; V_30 ++ , V_28 ++ )
* V_28 = F_10 ( * ( V_21 . V_41 + V_30 ) ) ;
break;
case V_7 :
if ( F_9 ( V_16 , & V_23 ) )
return - V_9 ;
for ( V_30 = 0 ; V_30 < V_25 > > 3 ; V_30 ++ , V_29 ++ )
* V_29 = F_11 ( * ( V_23 . V_41 + V_30 ) ) ;
break;
default:
return - V_9 ;
}
if ( F_7 ( V_16 ) )
return - V_9 ;
if ( F_8 ( V_16 , V_27 , V_24 ) )
return - V_9 ;
V_31 = F_12 ( F_1 ( V_13 -> V_2 ) , 8 ) ;
V_28 = ( T_2 * ) ( V_11 -> V_39 . V_40 + V_31 ) ;
V_29 = ( T_3 * ) V_28 ;
switch ( V_13 -> V_2 ) {
case V_3 :
if ( F_9 ( V_16 , & V_19 ) )
return - V_9 ;
for ( V_30 = 0 ; V_30 < V_25 > > 2 ; V_30 ++ , V_28 ++ )
* V_28 = F_10 ( * ( V_19 . V_41 + V_30 ) ) ;
break;
case V_5 :
if ( F_9 ( V_16 , & V_21 ) )
return - V_9 ;
for ( V_30 = 0 ; V_30 < V_25 > > 2 ; V_30 ++ , V_28 ++ )
* V_28 = F_10 ( * ( V_21 . V_41 + V_30 ) ) ;
break;
case V_7 :
if ( F_9 ( V_16 , & V_23 ) )
return - V_9 ;
for ( V_30 = 0 ; V_30 < V_25 > > 3 ; V_30 ++ , V_29 ++ )
* V_29 = F_11 ( * ( V_23 . V_41 + V_30 ) ) ;
break;
default:
return - V_9 ;
}
F_13 ( V_26 , V_24 ) ;
F_13 ( V_27 , V_24 ) ;
return 0 ;
}
static void F_14 ( struct V_42 * V_43 )
{
V_43 -> V_44 =
F_15 ( V_45 ) ;
V_43 -> V_46 = V_47 ;
V_43 -> V_48 =
F_16 ( V_49 ,
V_50 ) ;
F_17 ( V_43 -> V_51 ,
V_52 ) ;
F_18 ( V_43 -> V_51 ,
V_53 ) ;
F_19 ( V_43 -> V_51 ,
V_54 ) ;
F_20 ( V_43 -> V_51 ,
V_55 ) ;
}
static int F_21 ( struct V_56 * V_57 ,
int V_58 ,
struct V_59 * V_60 ,
int V_61 )
{
struct V_12 * V_13 = F_22 ( V_57 ) ;
unsigned int V_62 = F_23 ( V_57 ) ;
struct V_63 * V_64 = & V_13 -> V_65 -> V_66 ;
struct V_67 * V_68 = & V_64 -> V_68 ;
struct V_10 * V_11 =
(struct V_10 * ) ( ( char * ) V_64 +
sizeof( struct V_69 ) + V_60 -> V_70 ) ;
struct V_71 * V_72 = & V_13 -> V_73 ;
struct V_74 * V_75 = & V_72 -> V_75 ;
struct V_42 * V_43 = & V_72 -> V_76 ;
void * V_77 = & V_72 -> V_78 ;
struct V_79 * V_80 = V_77 ;
struct V_81 * V_82 = V_77 ;
V_68 -> V_83 . V_84 . V_85 = F_24 ( V_58 , V_61 ) ;
memcpy ( V_68 -> V_83 . V_86 , V_60 -> V_87 , V_60 -> V_70 ) ;
V_11 -> V_39 . V_88 . V_89 . V_90 =
F_25 ( V_91 ,
V_13 -> V_2 , V_62 ) ;
V_11 -> V_39 . V_88 . V_92 . V_93 =
F_10 ( F_4 ( V_13 -> V_17 ) ) ;
if ( F_2 ( V_11 , V_13 , V_60 -> V_94 , V_60 -> V_95 ) )
return - V_9 ;
F_14 ( V_43 ) ;
V_43 -> V_96 = V_97 ;
F_26 ( V_43 -> V_51 ,
V_98 ) ;
F_27 ( V_43 -> V_51 ,
V_99 ) ;
F_28 ( V_43 -> V_51 ,
V_100 ) ;
V_75 -> V_101 . V_102 . V_103 = V_13 -> V_104 ;
V_75 -> V_101 . V_102 . V_105 = sizeof( struct V_106 ) >> 3 ;
V_80 -> V_107 = V_60 -> V_70 >> 3 ;
V_80 -> V_108 = V_109 >> 3 ;
V_80 -> V_110 = 0 ;
F_29 ( V_80 , V_111 ) ;
F_30 ( V_80 , V_112 ) ;
V_82 -> V_113 = ( ( char * ) V_11 - ( char * ) V_68 ) >> 3 ;
V_82 -> V_114 = V_115 ;
V_82 -> V_116 = V_62 ;
V_82 -> V_117 = V_62 ;
switch ( V_13 -> V_2 ) {
case V_3 :
V_82 -> V_118 =
F_12 ( V_4 , 8 ) ;
V_82 -> V_119 =
F_12 ( V_120 , 8 ) ;
break;
case V_5 :
V_82 -> V_118 = V_6 ;
V_82 -> V_119 = V_121 ;
break;
case V_7 :
V_82 -> V_118 = V_8 ;
V_82 -> V_119 = V_122 ;
break;
default:
break;
}
V_82 -> V_123 = V_82 -> V_113 +
( ( sizeof( struct V_69 ) +
F_12 ( V_82 -> V_118 , 8 ) ) >> 3 ) ;
F_29 ( V_82 , V_112 ) ;
F_30 ( V_82 , V_124 ) ;
return 0 ;
}
static int F_31 ( struct V_56 * V_57 ,
int V_58 ,
struct V_59 * V_60 ,
int V_61 )
{
struct V_12 * V_13 = F_22 ( V_57 ) ;
unsigned int V_62 = F_23 ( V_57 ) ;
struct V_125 * V_126 = & V_13 -> V_127 -> V_128 ;
struct V_10 * V_11 = & V_126 -> V_11 ;
struct V_67 * V_68 =
(struct V_67 * ) ( ( char * ) V_126 +
sizeof( struct V_69 ) +
F_32 ( F_5 ( V_13 -> V_17 ) , 8 ) * 2 ) ;
struct V_71 * V_72 = & V_13 -> V_129 ;
struct V_74 * V_75 = & V_72 -> V_75 ;
struct V_42 * V_43 = & V_72 -> V_76 ;
void * V_77 = & V_72 -> V_78 ;
struct V_79 * V_80 = V_77 ;
struct V_81 * V_82 = V_77 ;
struct V_130 * V_131 =
(struct V_130 * )
( ( char * ) & V_72 -> V_132 +
sizeof( struct V_133 ) ) ;
V_68 -> V_83 . V_84 . V_85 = F_33 ( V_58 , V_61 ) ;
memcpy ( V_68 -> V_83 . V_86 , V_60 -> V_87 , V_60 -> V_70 ) ;
V_11 -> V_39 . V_88 . V_89 . V_90 =
F_25 ( V_91 ,
V_13 -> V_2 ,
V_62 ) ;
V_11 -> V_39 . V_88 . V_92 . V_93 =
F_10 ( F_4 ( V_13 -> V_17 ) ) ;
if ( F_2 ( V_11 , V_13 , V_60 -> V_94 , V_60 -> V_95 ) )
return - V_9 ;
F_14 ( V_43 ) ;
V_43 -> V_96 = V_134 ;
F_26 ( V_43 -> V_51 ,
V_98 ) ;
F_27 ( V_43 -> V_51 ,
V_135 ) ;
F_28 ( V_43 -> V_51 ,
V_136 ) ;
V_75 -> V_101 . V_102 . V_103 = V_13 -> V_137 ;
V_75 -> V_101 . V_102 . V_105 = sizeof( struct V_106 ) >> 3 ;
V_80 -> V_107 = V_60 -> V_70 >> 3 ;
V_80 -> V_108 = V_109 >> 3 ;
V_80 -> V_110 =
( sizeof( struct V_69 ) +
F_32 ( F_5 ( V_13 -> V_17 ) , 8 ) * 2 ) >> 3 ;
F_29 ( V_80 , V_111 ) ;
F_30 ( V_80 , V_124 ) ;
V_82 -> V_113 = 0 ;
V_82 -> V_114 = V_115 ;
V_82 -> V_116 = V_62 ;
V_82 -> V_117 = V_62 ;
switch ( V_13 -> V_2 ) {
case V_3 :
V_82 -> V_118 =
F_12 ( V_4 , 8 ) ;
V_82 -> V_119 =
F_12 ( V_120 , 8 ) ;
break;
case V_5 :
V_82 -> V_118 = V_6 ;
V_82 -> V_119 = V_121 ;
break;
case V_7 :
V_82 -> V_118 = V_8 ;
V_82 -> V_119 = V_122 ;
break;
default:
break;
}
V_82 -> V_123 = V_82 -> V_113 +
( ( sizeof( struct V_69 ) +
F_12 ( V_82 -> V_118 , 8 ) ) >> 3 ) ;
V_131 -> V_138 = V_62 ;
F_29 ( V_82 , V_112 ) ;
F_30 ( V_82 , V_111 ) ;
return 0 ;
}
static void F_34 ( struct V_139 * V_13 ,
struct V_71 * V_140 ,
struct V_67 * V_141 ,
const T_1 * V_86 , unsigned int V_142 )
{
struct V_74 * V_75 = & V_140 -> V_75 ;
struct V_42 * V_43 = & V_140 -> V_76 ;
struct V_79 * V_78 = ( void * ) & V_140 -> V_78 ;
memcpy ( V_141 -> V_83 . V_86 , V_86 , V_142 ) ;
F_14 ( V_43 ) ;
V_43 -> V_96 = V_143 ;
V_75 -> V_101 . V_102 . V_105 =
sizeof( struct V_67 ) >> 3 ;
V_78 -> V_107 = V_142 >> 3 ;
V_78 -> V_108 = V_109 >> 3 ;
V_78 -> V_110 = 0 ;
F_29 ( V_78 , V_111 ) ;
F_30 ( V_78 , V_124 ) ;
}
static void F_35 ( struct V_139 * V_13 ,
int V_58 , const T_1 * V_86 ,
unsigned int V_142 , int V_61 )
{
struct V_67 * V_65 = V_13 -> V_65 ;
struct V_71 * V_140 = & V_13 -> V_73 ;
struct V_74 * V_75 = & V_140 -> V_75 ;
F_34 ( V_13 , V_140 , V_65 , V_86 , V_142 ) ;
V_75 -> V_101 . V_102 . V_103 = V_13 -> V_104 ;
V_65 -> V_83 . V_84 . V_85 = F_24 ( V_58 , V_61 ) ;
}
static void F_36 ( struct V_139 * V_13 ,
int V_58 , const T_1 * V_86 ,
unsigned int V_142 , int V_61 )
{
struct V_67 * V_127 = V_13 -> V_127 ;
struct V_71 * V_140 = & V_13 -> V_129 ;
struct V_74 * V_75 = & V_140 -> V_75 ;
F_34 ( V_13 , V_140 , V_127 , V_86 , V_142 ) ;
V_75 -> V_101 . V_102 . V_103 = V_13 -> V_137 ;
if ( V_61 != V_144 )
V_127 -> V_83 . V_84 . V_85 =
F_33 ( V_58 , V_61 ) ;
else
V_127 -> V_83 . V_84 . V_85 =
F_24 ( V_58 , V_61 ) ;
}
static int F_37 ( int V_145 , int * V_58 , int V_61 )
{
if ( V_61 != V_146 ) {
switch ( V_145 ) {
case V_147 :
* V_58 = V_148 ;
break;
case V_149 :
* V_58 = V_150 ;
break;
case V_151 :
* V_58 = V_152 ;
break;
default:
return - V_153 ;
}
} else {
switch ( V_145 ) {
case V_147 << 1 :
* V_58 = V_148 ;
break;
case V_151 << 1 :
* V_58 = V_152 ;
break;
default:
return - V_153 ;
}
}
return 0 ;
}
static int F_38 ( struct V_56 * V_32 , const T_4 * V_86 ,
unsigned int V_142 , int V_61 )
{
struct V_59 V_60 ;
int V_58 ;
if ( F_39 ( & V_60 , V_86 , V_142 ) )
goto V_154;
if ( F_37 ( V_60 . V_70 , & V_58 , V_61 ) )
goto V_154;
if ( F_21 ( V_32 , V_58 , & V_60 , V_61 ) )
goto error;
if ( F_31 ( V_32 , V_58 , & V_60 , V_61 ) )
goto error;
return 0 ;
V_154:
F_40 ( V_32 , V_155 ) ;
return - V_153 ;
error:
return - V_9 ;
}
static int F_41 ( struct V_139 * V_13 ,
const T_1 * V_86 ,
unsigned int V_142 ,
int V_61 )
{
int V_58 ;
if ( F_37 ( V_142 , & V_58 , V_61 ) )
goto V_154;
F_35 ( V_13 , V_58 , V_86 , V_142 , V_61 ) ;
F_36 ( V_13 , V_58 , V_86 , V_142 , V_61 ) ;
return 0 ;
V_154:
F_42 ( V_13 -> V_32 , V_155 ) ;
return - V_153 ;
}
static int F_43 ( struct V_56 * V_32 , const T_1 * V_86 ,
unsigned int V_142 )
{
struct V_12 * V_13 = F_22 ( V_32 ) ;
struct V_156 * V_157 ;
if ( V_13 -> V_65 ) {
V_157 = & F_44 ( V_13 -> V_158 -> V_159 ) ;
memset ( V_13 -> V_65 , 0 , sizeof( * V_13 -> V_65 ) ) ;
memset ( V_13 -> V_127 , 0 , sizeof( * V_13 -> V_127 ) ) ;
memset ( & V_13 -> V_73 , 0 , sizeof( V_13 -> V_73 ) ) ;
memset ( & V_13 -> V_129 , 0 , sizeof( V_13 -> V_129 ) ) ;
} else {
int V_160 = F_45 () ;
struct V_161 * V_158 =
F_46 ( V_160 ) ;
if ( ! V_158 ) {
return - V_153 ;
}
V_157 = & F_44 ( V_158 -> V_159 ) ;
V_13 -> V_158 = V_158 ;
V_13 -> V_65 = F_47 ( V_157 , sizeof( * V_13 -> V_65 ) ,
& V_13 -> V_104 ,
V_162 ) ;
if ( ! V_13 -> V_65 ) {
return - V_163 ;
}
V_13 -> V_127 = F_47 ( V_157 , sizeof( * V_13 -> V_127 ) ,
& V_13 -> V_137 ,
V_162 ) ;
if ( ! V_13 -> V_127 ) {
goto V_164;
}
}
if ( F_38 ( V_32 , V_86 , V_142 ,
V_165 ) )
goto V_166;
return 0 ;
V_166:
memset ( V_13 -> V_127 , 0 , sizeof( struct V_106 ) ) ;
F_48 ( V_157 , sizeof( struct V_106 ) ,
V_13 -> V_127 , V_13 -> V_137 ) ;
V_13 -> V_127 = NULL ;
V_164:
memset ( V_13 -> V_65 , 0 , sizeof( struct V_106 ) ) ;
F_48 ( V_157 , sizeof( struct V_106 ) ,
V_13 -> V_65 , V_13 -> V_104 ) ;
V_13 -> V_65 = NULL ;
return - V_163 ;
}
static void F_49 ( struct V_161 * V_158 ,
struct V_167 * V_168 )
{
struct V_156 * V_157 = & F_44 ( V_158 -> V_159 ) ;
struct V_169 * V_170 = V_168 -> V_171 . V_170 ;
struct V_169 * V_172 = V_168 -> V_171 . V_172 ;
T_5 V_173 = V_168 -> V_171 . V_173 ;
T_5 V_174 = V_168 -> V_171 . V_175 ;
T_6 V_176 = V_168 -> V_171 . V_176 ;
T_6 V_177 = V_168 -> V_171 . V_177 ;
int V_30 ;
for ( V_30 = 0 ; V_30 < V_170 -> V_178 ; V_30 ++ )
F_50 ( V_157 , V_170 -> V_179 [ V_30 ] . V_180 ,
V_170 -> V_179 [ V_30 ] . V_181 , V_182 ) ;
F_50 ( V_157 , V_173 , V_176 , V_183 ) ;
F_51 ( V_170 ) ;
if ( V_173 != V_174 ) {
int V_184 = V_172 -> V_178 - V_172 -> V_185 ;
for ( V_30 = V_184 ; V_30 < V_172 -> V_178 ; V_30 ++ ) {
F_50 ( V_157 , V_172 -> V_179 [ V_30 ] . V_180 ,
V_172 -> V_179 [ V_30 ] . V_181 ,
V_182 ) ;
}
F_50 ( V_157 , V_174 , V_177 , V_183 ) ;
F_51 ( V_172 ) ;
}
}
static int F_52 ( struct V_161 * V_158 ,
struct V_186 * V_187 ,
struct V_186 * V_188 ,
struct V_167 * V_168 )
{
struct V_156 * V_157 = & F_44 ( V_158 -> V_159 ) ;
int V_30 , V_189 = 0 ;
int V_190 = F_53 ( V_187 ) ;
struct V_169 * V_191 ;
struct V_169 * V_192 = NULL ;
T_5 V_173 ;
T_5 V_175 = 0 ;
struct V_186 * V_193 ;
T_6 V_177 , V_176 = sizeof( struct V_169 ) +
( ( 1 + V_190 ) * sizeof( struct V_194 ) ) ;
if ( F_54 ( ! V_190 ) )
return - V_153 ;
V_191 = F_55 ( V_176 , V_162 ,
F_56 ( & F_44 ( V_158 -> V_159 ) ) ) ;
if ( F_54 ( ! V_191 ) )
return - V_163 ;
V_173 = F_57 ( V_157 , V_191 , V_176 , V_183 ) ;
if ( F_54 ( F_58 ( V_157 , V_173 ) ) )
goto V_195;
F_59 (sgl, sg, n, i) {
int V_196 = V_189 ;
if ( ! V_193 -> V_197 )
continue;
V_191 -> V_179 [ V_196 ] . V_180 = F_57 ( V_157 , F_60 ( V_193 ) ,
V_193 -> V_197 ,
V_182 ) ;
V_191 -> V_179 [ V_196 ] . V_181 = V_193 -> V_197 ;
if ( F_54 ( F_58 ( V_157 , V_191 -> V_179 [ V_196 ] . V_180 ) ) )
goto V_195;
V_189 ++ ;
}
V_191 -> V_178 = V_189 ;
V_168 -> V_171 . V_170 = V_191 ;
V_168 -> V_171 . V_173 = V_173 ;
V_168 -> V_171 . V_176 = V_176 ;
if ( V_187 != V_188 ) {
struct V_194 * V_179 ;
V_190 = F_53 ( V_188 ) ;
V_177 = sizeof( struct V_169 ) +
( ( 1 + V_190 ) * sizeof( struct V_194 ) ) ;
V_189 = 0 ;
V_192 = F_55 ( V_177 , V_162 ,
F_56 ( & F_44 ( V_158 -> V_159 ) ) ) ;
if ( F_54 ( ! V_192 ) )
goto V_195;
V_175 = F_57 ( V_157 , V_192 , V_177 , V_183 ) ;
if ( F_54 ( F_58 ( V_157 , V_175 ) ) )
goto V_198;
V_179 = V_192 -> V_179 ;
F_59 (sglout, sg, n, i) {
int V_196 = V_189 ;
if ( ! V_193 -> V_197 )
continue;
V_179 [ V_196 ] . V_180 = F_57 ( V_157 , F_60 ( V_193 ) ,
V_193 -> V_197 ,
V_182 ) ;
if ( F_54 ( F_58 ( V_157 , V_179 [ V_196 ] . V_180 ) ) )
goto V_198;
V_179 [ V_196 ] . V_181 = V_193 -> V_197 ;
V_189 ++ ;
}
V_192 -> V_178 = V_189 ;
V_192 -> V_185 = V_189 ;
V_168 -> V_171 . V_172 = V_192 ;
V_168 -> V_171 . V_175 = V_175 ;
V_168 -> V_171 . V_177 = V_177 ;
} else {
V_168 -> V_171 . V_175 = V_168 -> V_171 . V_173 ;
V_168 -> V_171 . V_177 = 0 ;
}
return 0 ;
V_198:
V_190 = F_53 ( V_188 ) ;
for ( V_30 = 0 ; V_30 < V_190 ; V_30 ++ )
if ( ! F_58 ( V_157 , V_192 -> V_179 [ V_30 ] . V_180 ) )
F_50 ( V_157 , V_192 -> V_179 [ V_30 ] . V_180 ,
V_192 -> V_179 [ V_30 ] . V_181 ,
V_182 ) ;
if ( ! F_58 ( V_157 , V_175 ) )
F_50 ( V_157 , V_175 , V_177 , V_183 ) ;
F_51 ( V_192 ) ;
V_195:
V_190 = F_53 ( V_187 ) ;
for ( V_30 = 0 ; V_30 < V_190 ; V_30 ++ )
if ( ! F_58 ( V_157 , V_191 -> V_179 [ V_30 ] . V_180 ) )
F_50 ( V_157 , V_191 -> V_179 [ V_30 ] . V_180 ,
V_191 -> V_179 [ V_30 ] . V_181 ,
V_182 ) ;
if ( ! F_58 ( V_157 , V_173 ) )
F_50 ( V_157 , V_173 , V_176 , V_183 ) ;
F_51 ( V_191 ) ;
F_61 ( V_157 , L_1 ) ;
return - V_163 ;
}
static void F_62 ( struct V_199 * V_200 ,
struct V_167 * V_168 )
{
struct V_12 * V_13 = V_168 -> V_201 ;
struct V_161 * V_158 = V_13 -> V_158 ;
struct V_202 * V_203 = V_168 -> V_204 ;
T_1 V_205 = V_200 -> V_206 . V_207 ;
int V_208 = 0 , V_209 = F_63 ( V_205 ) ;
F_49 ( V_158 , V_168 ) ;
if ( F_54 ( V_209 != V_210 ) )
V_208 = - V_211 ;
V_203 -> V_212 . V_213 ( & V_203 -> V_212 , V_208 ) ;
}
static void F_64 ( struct V_199 * V_200 ,
struct V_167 * V_168 )
{
struct V_139 * V_13 = V_168 -> V_214 ;
struct V_161 * V_158 = V_13 -> V_158 ;
struct V_215 * V_203 = V_168 -> V_216 ;
T_1 V_205 = V_200 -> V_206 . V_207 ;
int V_208 = 0 , V_209 = F_63 ( V_205 ) ;
F_49 ( V_158 , V_168 ) ;
if ( F_54 ( V_209 != V_210 ) )
V_208 = - V_153 ;
V_203 -> V_212 . V_213 ( & V_203 -> V_212 , V_208 ) ;
}
void F_65 ( void * V_217 )
{
struct V_199 * V_200 = V_217 ;
struct V_167 * V_168 =
( void * ) ( V_218 long ) V_200 -> V_219 ;
V_168 -> V_220 ( V_200 , V_168 ) ;
}
static int F_66 ( struct V_202 * V_203 )
{
struct V_56 * V_57 = F_67 ( V_203 ) ;
struct V_221 * V_32 = F_68 ( V_57 ) ;
struct V_12 * V_13 = F_69 ( V_32 ) ;
struct V_167 * V_168 = F_70 ( V_203 ) ;
struct V_133 * V_222 ;
struct V_130 * V_131 ;
struct V_71 * V_223 ;
int V_224 = F_23 ( V_57 ) ;
int V_34 , V_225 = 0 ;
V_34 = F_52 ( V_13 -> V_158 , V_203 -> V_226 , V_203 -> V_227 , V_168 ) ;
if ( F_54 ( V_34 ) )
return V_34 ;
V_223 = & V_168 -> V_140 ;
* V_223 = V_13 -> V_129 ;
V_168 -> V_201 = V_13 ;
V_168 -> V_204 = V_203 ;
V_168 -> V_220 = F_62 ;
V_168 -> V_140 . V_228 . V_219 = ( V_229 ) ( V_218 long ) V_168 ;
V_168 -> V_140 . V_228 . V_230 = V_168 -> V_171 . V_173 ;
V_168 -> V_140 . V_228 . V_231 = V_168 -> V_171 . V_175 ;
V_222 = ( void * ) & V_168 -> V_140 . V_132 ;
V_222 -> V_232 = V_203 -> V_233 - V_224 ;
V_222 -> V_234 = V_203 -> V_235 ;
memcpy ( V_222 -> V_101 . V_236 , V_203 -> V_237 , V_109 ) ;
V_131 = ( void * ) ( ( T_1 * ) V_222 + sizeof( * V_222 ) ) ;
V_131 -> V_238 = 0 ;
V_131 -> V_239 = V_203 -> V_235 + V_222 -> V_232 ;
do {
V_34 = F_71 ( V_13 -> V_158 -> V_240 , ( V_241 * ) V_223 ) ;
} while ( V_34 == - V_242 && V_225 ++ < 10 );
if ( V_34 == - V_242 ) {
F_49 ( V_13 -> V_158 , V_168 ) ;
return - V_243 ;
}
return - V_244 ;
}
static int F_72 ( struct V_202 * V_203 )
{
struct V_56 * V_57 = F_67 ( V_203 ) ;
struct V_221 * V_32 = F_68 ( V_57 ) ;
struct V_12 * V_13 = F_69 ( V_32 ) ;
struct V_167 * V_168 = F_70 ( V_203 ) ;
struct V_133 * V_222 ;
struct V_130 * V_131 ;
struct V_71 * V_223 ;
T_1 * V_237 = V_203 -> V_237 ;
int V_34 , V_225 = 0 ;
V_34 = F_52 ( V_13 -> V_158 , V_203 -> V_226 , V_203 -> V_227 , V_168 ) ;
if ( F_54 ( V_34 ) )
return V_34 ;
V_223 = & V_168 -> V_140 ;
* V_223 = V_13 -> V_73 ;
V_168 -> V_201 = V_13 ;
V_168 -> V_204 = V_203 ;
V_168 -> V_220 = F_62 ;
V_168 -> V_140 . V_228 . V_219 = ( V_229 ) ( V_218 long ) V_168 ;
V_168 -> V_140 . V_228 . V_230 = V_168 -> V_171 . V_173 ;
V_168 -> V_140 . V_228 . V_231 = V_168 -> V_171 . V_175 ;
V_222 = ( void * ) & V_168 -> V_140 . V_132 ;
V_131 = ( void * ) ( ( T_1 * ) V_222 + sizeof( * V_222 ) ) ;
memcpy ( V_222 -> V_101 . V_236 , V_237 , V_109 ) ;
V_222 -> V_232 = V_203 -> V_233 ;
V_222 -> V_234 = V_203 -> V_235 ;
V_131 -> V_238 = 0 ;
V_131 -> V_239 = V_203 -> V_235 + V_203 -> V_233 ;
do {
V_34 = F_71 ( V_13 -> V_158 -> V_240 , ( V_241 * ) V_223 ) ;
} while ( V_34 == - V_242 && V_225 ++ < 10 );
if ( V_34 == - V_242 ) {
F_49 ( V_13 -> V_158 , V_168 ) ;
return - V_243 ;
}
return - V_244 ;
}
static int F_73 ( struct V_245 * V_32 ,
const T_4 * V_86 , unsigned int V_142 ,
int V_61 )
{
struct V_139 * V_13 = F_74 ( V_32 ) ;
struct V_156 * V_157 ;
F_75 ( & V_13 -> V_246 ) ;
if ( V_13 -> V_65 ) {
V_157 = & F_44 ( V_13 -> V_158 -> V_159 ) ;
memset ( V_13 -> V_65 , 0 , sizeof( * V_13 -> V_65 ) ) ;
memset ( V_13 -> V_127 , 0 , sizeof( * V_13 -> V_127 ) ) ;
memset ( & V_13 -> V_73 , 0 , sizeof( V_13 -> V_73 ) ) ;
memset ( & V_13 -> V_129 , 0 , sizeof( V_13 -> V_129 ) ) ;
} else {
int V_160 = F_45 () ;
struct V_161 * V_158 =
F_46 ( V_160 ) ;
if ( ! V_158 ) {
F_76 ( & V_13 -> V_246 ) ;
return - V_153 ;
}
V_157 = & F_44 ( V_158 -> V_159 ) ;
V_13 -> V_158 = V_158 ;
V_13 -> V_65 = F_47 ( V_157 , sizeof( * V_13 -> V_65 ) ,
& V_13 -> V_104 ,
V_162 ) ;
if ( ! V_13 -> V_65 ) {
F_76 ( & V_13 -> V_246 ) ;
return - V_163 ;
}
V_13 -> V_127 = F_47 ( V_157 , sizeof( * V_13 -> V_127 ) ,
& V_13 -> V_137 ,
V_162 ) ;
if ( ! V_13 -> V_127 ) {
F_76 ( & V_13 -> V_246 ) ;
goto V_164;
}
}
F_76 ( & V_13 -> V_246 ) ;
if ( F_41 ( V_13 , V_86 , V_142 , V_61 ) )
goto V_166;
return 0 ;
V_166:
memset ( V_13 -> V_127 , 0 , sizeof( * V_13 -> V_127 ) ) ;
F_48 ( V_157 , sizeof( * V_13 -> V_127 ) ,
V_13 -> V_127 , V_13 -> V_137 ) ;
V_13 -> V_127 = NULL ;
V_164:
memset ( V_13 -> V_65 , 0 , sizeof( * V_13 -> V_65 ) ) ;
F_48 ( V_157 , sizeof( * V_13 -> V_65 ) ,
V_13 -> V_65 , V_13 -> V_104 ) ;
V_13 -> V_65 = NULL ;
return - V_163 ;
}
static int F_77 ( struct V_245 * V_32 ,
const T_4 * V_86 , unsigned int V_142 )
{
return F_73 ( V_32 , V_86 , V_142 ,
V_165 ) ;
}
static int F_78 ( struct V_245 * V_32 ,
const T_4 * V_86 , unsigned int V_142 )
{
return F_73 ( V_32 , V_86 , V_142 ,
V_144 ) ;
}
static int F_79 ( struct V_245 * V_32 ,
const T_4 * V_86 , unsigned int V_142 )
{
return F_73 ( V_32 , V_86 , V_142 ,
V_146 ) ;
}
static int F_80 ( struct V_215 * V_140 )
{
struct V_245 * V_247 = F_81 ( V_140 ) ;
struct V_221 * V_32 = F_82 ( V_247 ) ;
struct V_139 * V_13 = F_69 ( V_32 ) ;
struct V_167 * V_168 = F_83 ( V_140 ) ;
struct V_133 * V_222 ;
struct V_71 * V_223 ;
int V_34 , V_225 = 0 ;
V_34 = F_52 ( V_13 -> V_158 , V_140 -> V_226 , V_140 -> V_227 , V_168 ) ;
if ( F_54 ( V_34 ) )
return V_34 ;
V_223 = & V_168 -> V_140 ;
* V_223 = V_13 -> V_73 ;
V_168 -> V_214 = V_13 ;
V_168 -> V_216 = V_140 ;
V_168 -> V_220 = F_64 ;
V_168 -> V_140 . V_228 . V_219 = ( V_229 ) ( V_218 long ) V_168 ;
V_168 -> V_140 . V_228 . V_230 = V_168 -> V_171 . V_173 ;
V_168 -> V_140 . V_228 . V_231 = V_168 -> V_171 . V_175 ;
V_222 = ( void * ) & V_168 -> V_140 . V_132 ;
V_222 -> V_232 = V_140 -> V_248 ;
V_222 -> V_234 = 0 ;
memcpy ( V_222 -> V_101 . V_236 , V_140 -> V_249 , V_109 ) ;
do {
V_34 = F_71 ( V_13 -> V_158 -> V_240 , ( V_241 * ) V_223 ) ;
} while ( V_34 == - V_242 && V_225 ++ < 10 );
if ( V_34 == - V_242 ) {
F_49 ( V_13 -> V_158 , V_168 ) ;
return - V_243 ;
}
return - V_244 ;
}
static int F_84 ( struct V_215 * V_140 )
{
struct V_245 * V_247 = F_81 ( V_140 ) ;
struct V_221 * V_32 = F_82 ( V_247 ) ;
struct V_139 * V_13 = F_69 ( V_32 ) ;
struct V_167 * V_168 = F_83 ( V_140 ) ;
struct V_133 * V_222 ;
struct V_71 * V_223 ;
int V_34 , V_225 = 0 ;
V_34 = F_52 ( V_13 -> V_158 , V_140 -> V_226 , V_140 -> V_227 , V_168 ) ;
if ( F_54 ( V_34 ) )
return V_34 ;
V_223 = & V_168 -> V_140 ;
* V_223 = V_13 -> V_129 ;
V_168 -> V_214 = V_13 ;
V_168 -> V_216 = V_140 ;
V_168 -> V_220 = F_64 ;
V_168 -> V_140 . V_228 . V_219 = ( V_229 ) ( V_218 long ) V_168 ;
V_168 -> V_140 . V_228 . V_230 = V_168 -> V_171 . V_173 ;
V_168 -> V_140 . V_228 . V_231 = V_168 -> V_171 . V_175 ;
V_222 = ( void * ) & V_168 -> V_140 . V_132 ;
V_222 -> V_232 = V_140 -> V_248 ;
V_222 -> V_234 = 0 ;
memcpy ( V_222 -> V_101 . V_236 , V_140 -> V_249 , V_109 ) ;
do {
V_34 = F_71 ( V_13 -> V_158 -> V_240 , ( V_241 * ) V_223 ) ;
} while ( V_34 == - V_242 && V_225 ++ < 10 );
if ( V_34 == - V_242 ) {
F_49 ( V_13 -> V_158 , V_168 ) ;
return - V_243 ;
}
return - V_244 ;
}
static int F_85 ( struct V_56 * V_32 ,
enum V_1 V_11 ,
const char * V_250 )
{
struct V_12 * V_13 = F_22 ( V_32 ) ;
V_13 -> V_17 = F_86 ( V_250 , 0 , 0 ) ;
if ( F_87 ( V_13 -> V_17 ) )
return F_88 ( V_13 -> V_17 ) ;
V_13 -> V_2 = V_11 ;
F_89 ( V_32 , sizeof( struct V_167 ) ) ;
return 0 ;
}
static int F_90 ( struct V_56 * V_32 )
{
return F_85 ( V_32 , V_3 , L_2 ) ;
}
static int F_91 ( struct V_56 * V_32 )
{
return F_85 ( V_32 , V_5 , L_3 ) ;
}
static int F_92 ( struct V_56 * V_32 )
{
return F_85 ( V_32 , V_7 , L_4 ) ;
}
static void F_93 ( struct V_56 * V_32 )
{
struct V_12 * V_13 = F_22 ( V_32 ) ;
struct V_161 * V_158 = V_13 -> V_158 ;
struct V_156 * V_157 ;
F_94 ( V_13 -> V_17 ) ;
if ( ! V_158 )
return;
V_157 = & F_44 ( V_158 -> V_159 ) ;
if ( V_13 -> V_65 ) {
memset ( V_13 -> V_65 , 0 , sizeof( struct V_106 ) ) ;
F_48 ( V_157 , sizeof( struct V_106 ) ,
V_13 -> V_65 , V_13 -> V_104 ) ;
}
if ( V_13 -> V_127 ) {
memset ( V_13 -> V_127 , 0 , sizeof( struct V_106 ) ) ;
F_48 ( V_157 , sizeof( struct V_106 ) ,
V_13 -> V_127 , V_13 -> V_137 ) ;
}
F_95 ( V_158 ) ;
}
static int F_96 ( struct V_221 * V_32 )
{
struct V_139 * V_13 = F_69 ( V_32 ) ;
F_97 ( & V_13 -> V_246 ) ;
V_32 -> V_251 . V_252 = sizeof( struct V_167 ) ;
V_13 -> V_32 = V_32 ;
return 0 ;
}
static void F_98 ( struct V_221 * V_32 )
{
struct V_139 * V_13 = F_69 ( V_32 ) ;
struct V_161 * V_158 = V_13 -> V_158 ;
struct V_156 * V_157 ;
if ( ! V_158 )
return;
V_157 = & F_44 ( V_158 -> V_159 ) ;
if ( V_13 -> V_65 ) {
memset ( V_13 -> V_65 , 0 ,
sizeof( struct V_67 ) ) ;
F_48 ( V_157 ,
sizeof( struct V_67 ) ,
V_13 -> V_65 , V_13 -> V_104 ) ;
}
if ( V_13 -> V_127 ) {
memset ( V_13 -> V_127 , 0 ,
sizeof( struct V_67 ) ) ;
F_48 ( V_157 ,
sizeof( struct V_67 ) ,
V_13 -> V_127 , V_13 -> V_137 ) ;
}
F_95 ( V_158 ) ;
}
int F_99 ( void )
{
int V_34 = 0 , V_30 ;
F_100 ( & V_253 ) ;
if ( ++ V_254 != 1 )
goto V_255;
for ( V_30 = 0 ; V_30 < F_101 ( V_256 ) ; V_30 ++ )
V_256 [ V_30 ] . V_257 = V_258 | V_259 ;
V_34 = F_102 ( V_256 , F_101 ( V_256 ) ) ;
if ( V_34 )
goto V_255;
for ( V_30 = 0 ; V_30 < F_101 ( V_260 ) ; V_30 ++ )
V_260 [ V_30 ] . V_212 . V_257 = V_259 ;
V_34 = F_103 ( V_260 , F_101 ( V_260 ) ) ;
if ( V_34 )
goto V_261;
V_255:
F_104 ( & V_253 ) ;
return V_34 ;
V_261:
F_105 ( V_256 , F_101 ( V_256 ) ) ;
goto V_255;
}
void F_106 ( void )
{
F_100 ( & V_253 ) ;
if ( -- V_254 != 0 )
goto V_255;
F_107 ( V_260 , F_101 ( V_260 ) ) ;
F_105 ( V_256 , F_101 ( V_256 ) ) ;
V_255:
F_104 ( & V_253 ) ;
}
