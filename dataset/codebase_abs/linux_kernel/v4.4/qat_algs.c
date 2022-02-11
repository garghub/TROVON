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
* V_35 ^= 0x36 ;
* V_36 ^= 0x5C ;
}
if ( F_7 ( V_16 ) )
return - V_9 ;
if ( F_8 ( V_16 , V_26 , V_24 ) )
return - V_9 ;
V_28 = ( T_2 * ) V_11 -> V_37 . V_38 ;
V_29 = ( T_3 * ) V_28 ;
switch ( V_13 -> V_2 ) {
case V_3 :
if ( F_9 ( V_16 , & V_19 ) )
return - V_9 ;
for ( V_30 = 0 ; V_30 < V_25 > > 2 ; V_30 ++ , V_28 ++ )
* V_28 = F_10 ( * ( V_19 . V_39 + V_30 ) ) ;
break;
case V_5 :
if ( F_9 ( V_16 , & V_21 ) )
return - V_9 ;
for ( V_30 = 0 ; V_30 < V_25 > > 2 ; V_30 ++ , V_28 ++ )
* V_28 = F_10 ( * ( V_21 . V_39 + V_30 ) ) ;
break;
case V_7 :
if ( F_9 ( V_16 , & V_23 ) )
return - V_9 ;
for ( V_30 = 0 ; V_30 < V_25 > > 3 ; V_30 ++ , V_29 ++ )
* V_29 = F_11 ( * ( V_23 . V_39 + V_30 ) ) ;
break;
default:
return - V_9 ;
}
if ( F_7 ( V_16 ) )
return - V_9 ;
if ( F_8 ( V_16 , V_27 , V_24 ) )
return - V_9 ;
V_31 = F_12 ( F_1 ( V_13 -> V_2 ) , 8 ) ;
V_28 = ( T_2 * ) ( V_11 -> V_37 . V_38 + V_31 ) ;
V_29 = ( T_3 * ) V_28 ;
switch ( V_13 -> V_2 ) {
case V_3 :
if ( F_9 ( V_16 , & V_19 ) )
return - V_9 ;
for ( V_30 = 0 ; V_30 < V_25 > > 2 ; V_30 ++ , V_28 ++ )
* V_28 = F_10 ( * ( V_19 . V_39 + V_30 ) ) ;
break;
case V_5 :
if ( F_9 ( V_16 , & V_21 ) )
return - V_9 ;
for ( V_30 = 0 ; V_30 < V_25 > > 2 ; V_30 ++ , V_28 ++ )
* V_28 = F_10 ( * ( V_21 . V_39 + V_30 ) ) ;
break;
case V_7 :
if ( F_9 ( V_16 , & V_23 ) )
return - V_9 ;
for ( V_30 = 0 ; V_30 < V_25 > > 3 ; V_30 ++ , V_29 ++ )
* V_29 = F_11 ( * ( V_23 . V_39 + V_30 ) ) ;
break;
default:
return - V_9 ;
}
F_13 ( V_26 , V_24 ) ;
F_13 ( V_27 , V_24 ) ;
return 0 ;
}
static void F_14 ( struct V_40 * V_41 )
{
V_41 -> V_42 =
F_15 ( V_43 ) ;
V_41 -> V_44 = V_45 ;
V_41 -> V_46 =
F_16 ( V_47 ,
V_48 ) ;
F_17 ( V_41 -> V_49 ,
V_50 ) ;
F_18 ( V_41 -> V_49 ,
V_51 ) ;
F_19 ( V_41 -> V_49 ,
V_52 ) ;
F_20 ( V_41 -> V_49 ,
V_53 ) ;
}
static int F_21 ( struct V_54 * V_55 ,
int V_56 ,
struct V_57 * V_58 ,
int V_59 )
{
struct V_12 * V_13 = F_22 ( V_55 ) ;
unsigned int V_60 = F_23 ( V_55 ) ;
struct V_61 * V_62 = & V_13 -> V_63 -> V_64 ;
struct V_65 * V_66 = & V_62 -> V_66 ;
struct V_10 * V_11 =
(struct V_10 * ) ( ( char * ) V_62 +
sizeof( struct V_67 ) + V_58 -> V_68 ) ;
struct V_69 * V_70 = & V_13 -> V_71 ;
struct V_72 * V_73 = & V_70 -> V_73 ;
struct V_40 * V_41 = & V_70 -> V_74 ;
void * V_75 = & V_70 -> V_76 ;
struct V_77 * V_78 = V_75 ;
struct V_79 * V_80 = V_75 ;
V_66 -> V_81 . V_82 . V_83 = F_24 ( V_56 , V_59 ) ;
memcpy ( V_66 -> V_81 . V_84 , V_58 -> V_85 , V_58 -> V_68 ) ;
V_11 -> V_37 . V_86 . V_87 . V_88 =
F_25 ( V_89 ,
V_13 -> V_2 , V_60 ) ;
V_11 -> V_37 . V_86 . V_90 . V_91 =
F_10 ( F_4 ( V_13 -> V_17 ) ) ;
if ( F_2 ( V_11 , V_13 , V_58 -> V_92 , V_58 -> V_93 ) )
return - V_9 ;
F_14 ( V_41 ) ;
V_41 -> V_94 = V_95 ;
F_26 ( V_41 -> V_49 ,
V_96 ) ;
F_27 ( V_41 -> V_49 ,
V_97 ) ;
F_28 ( V_41 -> V_49 ,
V_98 ) ;
V_73 -> V_99 . V_100 . V_101 = V_13 -> V_102 ;
V_73 -> V_99 . V_100 . V_103 = sizeof( struct V_104 ) >> 3 ;
V_78 -> V_105 = V_58 -> V_68 >> 3 ;
V_78 -> V_106 = V_107 >> 3 ;
V_78 -> V_108 = 0 ;
F_29 ( V_78 , V_109 ) ;
F_30 ( V_78 , V_110 ) ;
V_80 -> V_111 = ( ( char * ) V_11 - ( char * ) V_66 ) >> 3 ;
V_80 -> V_112 = V_113 ;
V_80 -> V_114 = V_60 ;
V_80 -> V_115 = V_60 ;
switch ( V_13 -> V_2 ) {
case V_3 :
V_80 -> V_116 =
F_12 ( V_4 , 8 ) ;
V_80 -> V_117 =
F_12 ( V_118 , 8 ) ;
break;
case V_5 :
V_80 -> V_116 = V_6 ;
V_80 -> V_117 = V_119 ;
break;
case V_7 :
V_80 -> V_116 = V_8 ;
V_80 -> V_117 = V_120 ;
break;
default:
break;
}
V_80 -> V_121 = V_80 -> V_111 +
( ( sizeof( struct V_67 ) +
F_12 ( V_80 -> V_116 , 8 ) ) >> 3 ) ;
F_29 ( V_80 , V_110 ) ;
F_30 ( V_80 , V_122 ) ;
return 0 ;
}
static int F_31 ( struct V_54 * V_55 ,
int V_56 ,
struct V_57 * V_58 ,
int V_59 )
{
struct V_12 * V_13 = F_22 ( V_55 ) ;
unsigned int V_60 = F_23 ( V_55 ) ;
struct V_123 * V_124 = & V_13 -> V_125 -> V_126 ;
struct V_10 * V_11 = & V_124 -> V_11 ;
struct V_65 * V_66 =
(struct V_65 * ) ( ( char * ) V_124 +
sizeof( struct V_67 ) +
F_32 ( F_5 ( V_13 -> V_17 ) , 8 ) * 2 ) ;
struct V_69 * V_70 = & V_13 -> V_127 ;
struct V_72 * V_73 = & V_70 -> V_73 ;
struct V_40 * V_41 = & V_70 -> V_74 ;
void * V_75 = & V_70 -> V_76 ;
struct V_77 * V_78 = V_75 ;
struct V_79 * V_80 = V_75 ;
struct V_128 * V_129 =
(struct V_128 * )
( ( char * ) & V_70 -> V_130 +
sizeof( struct V_131 ) ) ;
V_66 -> V_81 . V_82 . V_83 = F_33 ( V_56 , V_59 ) ;
memcpy ( V_66 -> V_81 . V_84 , V_58 -> V_85 , V_58 -> V_68 ) ;
V_11 -> V_37 . V_86 . V_87 . V_88 =
F_25 ( V_89 ,
V_13 -> V_2 ,
V_60 ) ;
V_11 -> V_37 . V_86 . V_90 . V_91 =
F_10 ( F_4 ( V_13 -> V_17 ) ) ;
if ( F_2 ( V_11 , V_13 , V_58 -> V_92 , V_58 -> V_93 ) )
return - V_9 ;
F_14 ( V_41 ) ;
V_41 -> V_94 = V_132 ;
F_26 ( V_41 -> V_49 ,
V_96 ) ;
F_27 ( V_41 -> V_49 ,
V_133 ) ;
F_28 ( V_41 -> V_49 ,
V_134 ) ;
V_73 -> V_99 . V_100 . V_101 = V_13 -> V_135 ;
V_73 -> V_99 . V_100 . V_103 = sizeof( struct V_104 ) >> 3 ;
V_78 -> V_105 = V_58 -> V_68 >> 3 ;
V_78 -> V_106 = V_107 >> 3 ;
V_78 -> V_108 =
( sizeof( struct V_67 ) +
F_32 ( F_5 ( V_13 -> V_17 ) , 8 ) * 2 ) >> 3 ;
F_29 ( V_78 , V_109 ) ;
F_30 ( V_78 , V_122 ) ;
V_80 -> V_111 = 0 ;
V_80 -> V_112 = V_113 ;
V_80 -> V_114 = V_60 ;
V_80 -> V_115 = V_60 ;
switch ( V_13 -> V_2 ) {
case V_3 :
V_80 -> V_116 =
F_12 ( V_4 , 8 ) ;
V_80 -> V_117 =
F_12 ( V_118 , 8 ) ;
break;
case V_5 :
V_80 -> V_116 = V_6 ;
V_80 -> V_117 = V_119 ;
break;
case V_7 :
V_80 -> V_116 = V_8 ;
V_80 -> V_117 = V_120 ;
break;
default:
break;
}
V_80 -> V_121 = V_80 -> V_111 +
( ( sizeof( struct V_67 ) +
F_12 ( V_80 -> V_116 , 8 ) ) >> 3 ) ;
V_129 -> V_136 = V_60 ;
F_29 ( V_80 , V_110 ) ;
F_30 ( V_80 , V_109 ) ;
return 0 ;
}
static void F_34 ( struct V_137 * V_13 ,
struct V_69 * V_138 ,
struct V_65 * V_139 ,
const T_1 * V_84 , unsigned int V_140 )
{
struct V_72 * V_73 = & V_138 -> V_73 ;
struct V_40 * V_41 = & V_138 -> V_74 ;
struct V_77 * V_76 = ( void * ) & V_138 -> V_76 ;
memcpy ( V_139 -> V_81 . V_84 , V_84 , V_140 ) ;
F_14 ( V_41 ) ;
V_41 -> V_94 = V_141 ;
V_73 -> V_99 . V_100 . V_103 =
sizeof( struct V_65 ) >> 3 ;
V_76 -> V_105 = V_140 >> 3 ;
V_76 -> V_106 = V_107 >> 3 ;
V_76 -> V_108 = 0 ;
F_29 ( V_76 , V_109 ) ;
F_30 ( V_76 , V_122 ) ;
}
static void F_35 ( struct V_137 * V_13 ,
int V_56 , const T_1 * V_84 ,
unsigned int V_140 , int V_59 )
{
struct V_65 * V_63 = V_13 -> V_63 ;
struct V_69 * V_138 = & V_13 -> V_71 ;
struct V_72 * V_73 = & V_138 -> V_73 ;
F_34 ( V_13 , V_138 , V_63 , V_84 , V_140 ) ;
V_73 -> V_99 . V_100 . V_101 = V_13 -> V_102 ;
V_63 -> V_81 . V_82 . V_83 = F_24 ( V_56 , V_59 ) ;
}
static void F_36 ( struct V_137 * V_13 ,
int V_56 , const T_1 * V_84 ,
unsigned int V_140 , int V_59 )
{
struct V_65 * V_125 = V_13 -> V_125 ;
struct V_69 * V_138 = & V_13 -> V_127 ;
struct V_72 * V_73 = & V_138 -> V_73 ;
F_34 ( V_13 , V_138 , V_125 , V_84 , V_140 ) ;
V_73 -> V_99 . V_100 . V_101 = V_13 -> V_135 ;
if ( V_59 != V_142 )
V_125 -> V_81 . V_82 . V_83 =
F_33 ( V_56 , V_59 ) ;
else
V_125 -> V_81 . V_82 . V_83 =
F_24 ( V_56 , V_59 ) ;
}
static int F_37 ( int V_143 , int * V_56 , int V_59 )
{
if ( V_59 != V_144 ) {
switch ( V_143 ) {
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
} else {
switch ( V_143 ) {
case V_145 << 1 :
* V_56 = V_146 ;
break;
case V_149 << 1 :
* V_56 = V_150 ;
break;
default:
return - V_151 ;
}
}
return 0 ;
}
static int F_38 ( struct V_54 * V_32 , const T_4 * V_84 ,
unsigned int V_140 , int V_59 )
{
struct V_57 V_58 ;
int V_56 ;
if ( F_39 ( & V_58 , V_84 , V_140 ) )
goto V_152;
if ( F_37 ( V_58 . V_68 , & V_56 , V_59 ) )
goto V_152;
if ( F_21 ( V_32 , V_56 , & V_58 , V_59 ) )
goto error;
if ( F_31 ( V_32 , V_56 , & V_58 , V_59 ) )
goto error;
return 0 ;
V_152:
F_40 ( V_32 , V_153 ) ;
return - V_151 ;
error:
return - V_9 ;
}
static int F_41 ( struct V_137 * V_13 ,
const T_1 * V_84 ,
unsigned int V_140 ,
int V_59 )
{
int V_56 ;
if ( F_37 ( V_140 , & V_56 , V_59 ) )
goto V_152;
F_35 ( V_13 , V_56 , V_84 , V_140 , V_59 ) ;
F_36 ( V_13 , V_56 , V_84 , V_140 , V_59 ) ;
return 0 ;
V_152:
F_42 ( V_13 -> V_32 , V_153 ) ;
return - V_151 ;
}
static int F_43 ( struct V_54 * V_32 , const T_1 * V_84 ,
unsigned int V_140 )
{
struct V_12 * V_13 = F_22 ( V_32 ) ;
struct V_154 * V_155 ;
if ( V_13 -> V_63 ) {
V_155 = & F_44 ( V_13 -> V_156 -> V_157 ) ;
memset ( V_13 -> V_63 , 0 , sizeof( * V_13 -> V_63 ) ) ;
memset ( V_13 -> V_125 , 0 , sizeof( * V_13 -> V_125 ) ) ;
memset ( & V_13 -> V_71 , 0 , sizeof( V_13 -> V_71 ) ) ;
memset ( & V_13 -> V_127 , 0 , sizeof( V_13 -> V_127 ) ) ;
} else {
int V_158 = F_45 () ;
struct V_159 * V_156 =
F_46 ( V_158 ) ;
if ( ! V_156 ) {
return - V_151 ;
}
V_155 = & F_44 ( V_156 -> V_157 ) ;
V_13 -> V_156 = V_156 ;
V_13 -> V_63 = F_47 ( V_155 , sizeof( * V_13 -> V_63 ) ,
& V_13 -> V_102 ,
V_160 ) ;
if ( ! V_13 -> V_63 ) {
return - V_161 ;
}
V_13 -> V_125 = F_47 ( V_155 , sizeof( * V_13 -> V_125 ) ,
& V_13 -> V_135 ,
V_160 ) ;
if ( ! V_13 -> V_125 ) {
goto V_162;
}
}
if ( F_38 ( V_32 , V_84 , V_140 ,
V_163 ) )
goto V_164;
return 0 ;
V_164:
memset ( V_13 -> V_125 , 0 , sizeof( struct V_104 ) ) ;
F_48 ( V_155 , sizeof( struct V_104 ) ,
V_13 -> V_125 , V_13 -> V_135 ) ;
V_13 -> V_125 = NULL ;
V_162:
memset ( V_13 -> V_63 , 0 , sizeof( struct V_104 ) ) ;
F_48 ( V_155 , sizeof( struct V_104 ) ,
V_13 -> V_63 , V_13 -> V_102 ) ;
V_13 -> V_63 = NULL ;
return - V_161 ;
}
static void F_49 ( struct V_159 * V_156 ,
struct V_165 * V_166 )
{
struct V_154 * V_155 = & F_44 ( V_156 -> V_157 ) ;
struct V_167 * V_168 = V_166 -> V_169 . V_168 ;
struct V_167 * V_170 = V_166 -> V_169 . V_170 ;
T_5 V_171 = V_166 -> V_169 . V_171 ;
T_5 V_172 = V_166 -> V_169 . V_173 ;
T_6 V_174 = V_166 -> V_169 . V_174 ;
T_6 V_175 = V_166 -> V_169 . V_175 ;
int V_30 ;
for ( V_30 = 0 ; V_30 < V_168 -> V_176 ; V_30 ++ )
F_50 ( V_155 , V_168 -> V_177 [ V_30 ] . V_178 ,
V_168 -> V_177 [ V_30 ] . V_179 , V_180 ) ;
F_50 ( V_155 , V_171 , V_174 , V_181 ) ;
F_51 ( V_168 ) ;
if ( V_171 != V_172 ) {
int V_182 = V_170 -> V_176 - V_170 -> V_183 ;
for ( V_30 = V_182 ; V_30 < V_170 -> V_176 ; V_30 ++ ) {
F_50 ( V_155 , V_170 -> V_177 [ V_30 ] . V_178 ,
V_170 -> V_177 [ V_30 ] . V_179 ,
V_180 ) ;
}
F_50 ( V_155 , V_172 , V_175 , V_181 ) ;
F_51 ( V_170 ) ;
}
}
static int F_52 ( struct V_159 * V_156 ,
struct V_184 * V_185 ,
struct V_184 * V_186 ,
struct V_165 * V_166 )
{
struct V_154 * V_155 = & F_44 ( V_156 -> V_157 ) ;
int V_30 , V_187 = 0 ;
int V_188 = F_53 ( V_185 ) ;
struct V_167 * V_189 ;
struct V_167 * V_190 = NULL ;
T_5 V_171 ;
T_5 V_173 = 0 ;
struct V_184 * V_191 ;
T_6 V_175 , V_174 = sizeof( struct V_167 ) +
( ( 1 + V_188 ) * sizeof( struct V_192 ) ) ;
if ( F_54 ( ! V_188 ) )
return - V_151 ;
V_189 = F_55 ( V_174 , V_160 ,
F_56 ( & F_44 ( V_156 -> V_157 ) ) ) ;
if ( F_54 ( ! V_189 ) )
return - V_161 ;
V_171 = F_57 ( V_155 , V_189 , V_174 , V_181 ) ;
if ( F_54 ( F_58 ( V_155 , V_171 ) ) )
goto V_193;
F_59 (sgl, sg, n, i) {
int V_194 = V_187 ;
if ( ! V_191 -> V_195 )
continue;
V_189 -> V_177 [ V_194 ] . V_178 = F_57 ( V_155 , F_60 ( V_191 ) ,
V_191 -> V_195 ,
V_180 ) ;
V_189 -> V_177 [ V_194 ] . V_179 = V_191 -> V_195 ;
if ( F_54 ( F_58 ( V_155 , V_189 -> V_177 [ V_194 ] . V_178 ) ) )
goto V_193;
V_187 ++ ;
}
V_189 -> V_176 = V_187 ;
V_166 -> V_169 . V_168 = V_189 ;
V_166 -> V_169 . V_171 = V_171 ;
V_166 -> V_169 . V_174 = V_174 ;
if ( V_185 != V_186 ) {
struct V_192 * V_177 ;
V_188 = F_53 ( V_186 ) ;
V_175 = sizeof( struct V_167 ) +
( ( 1 + V_188 ) * sizeof( struct V_192 ) ) ;
V_187 = 0 ;
V_190 = F_55 ( V_175 , V_160 ,
F_56 ( & F_44 ( V_156 -> V_157 ) ) ) ;
if ( F_54 ( ! V_190 ) )
goto V_193;
V_173 = F_57 ( V_155 , V_190 , V_175 , V_181 ) ;
if ( F_54 ( F_58 ( V_155 , V_173 ) ) )
goto V_193;
V_177 = V_190 -> V_177 ;
F_59 (sglout, sg, n, i) {
int V_194 = V_187 ;
if ( ! V_191 -> V_195 )
continue;
V_177 [ V_194 ] . V_178 = F_57 ( V_155 , F_60 ( V_191 ) ,
V_191 -> V_195 ,
V_180 ) ;
if ( F_54 ( F_58 ( V_155 , V_177 [ V_194 ] . V_178 ) ) )
goto V_193;
V_177 [ V_194 ] . V_179 = V_191 -> V_195 ;
V_187 ++ ;
}
V_190 -> V_176 = V_187 ;
V_190 -> V_183 = V_187 ;
V_166 -> V_169 . V_170 = V_190 ;
V_166 -> V_169 . V_173 = V_173 ;
V_166 -> V_169 . V_175 = V_175 ;
} else {
V_166 -> V_169 . V_173 = V_166 -> V_169 . V_171 ;
V_166 -> V_169 . V_175 = 0 ;
}
return 0 ;
V_193:
F_61 ( V_155 , L_1 ) ;
V_187 = 0 ;
for ( V_30 = 0 ; V_30 < V_188 ; V_30 ++ )
if ( ! F_58 ( V_155 , V_189 -> V_177 [ V_30 ] . V_178 ) )
F_50 ( V_155 , V_189 -> V_177 [ V_30 ] . V_178 ,
V_189 -> V_177 [ V_30 ] . V_179 ,
V_180 ) ;
if ( ! F_58 ( V_155 , V_171 ) )
F_50 ( V_155 , V_171 , V_174 , V_181 ) ;
F_51 ( V_189 ) ;
if ( V_185 != V_186 && V_190 ) {
V_188 = F_53 ( V_186 ) ;
for ( V_30 = 0 ; V_30 < V_188 ; V_30 ++ )
if ( ! F_58 ( V_155 , V_190 -> V_177 [ V_30 ] . V_178 ) )
F_50 ( V_155 , V_190 -> V_177 [ V_30 ] . V_178 ,
V_190 -> V_177 [ V_30 ] . V_179 ,
V_180 ) ;
if ( ! F_58 ( V_155 , V_173 ) )
F_50 ( V_155 , V_173 , V_175 , V_181 ) ;
F_51 ( V_190 ) ;
}
return - V_161 ;
}
static void F_62 ( struct V_196 * V_197 ,
struct V_165 * V_166 )
{
struct V_12 * V_13 = V_166 -> V_198 ;
struct V_159 * V_156 = V_13 -> V_156 ;
struct V_199 * V_200 = V_166 -> V_201 ;
T_1 V_202 = V_197 -> V_203 . V_204 ;
int V_205 = 0 , V_206 = F_63 ( V_202 ) ;
F_49 ( V_156 , V_166 ) ;
if ( F_54 ( V_206 != V_207 ) )
V_205 = - V_208 ;
V_200 -> V_209 . V_210 ( & V_200 -> V_209 , V_205 ) ;
}
static void F_64 ( struct V_196 * V_197 ,
struct V_165 * V_166 )
{
struct V_137 * V_13 = V_166 -> V_211 ;
struct V_159 * V_156 = V_13 -> V_156 ;
struct V_212 * V_200 = V_166 -> V_213 ;
T_1 V_202 = V_197 -> V_203 . V_204 ;
int V_205 = 0 , V_206 = F_63 ( V_202 ) ;
F_49 ( V_156 , V_166 ) ;
if ( F_54 ( V_206 != V_207 ) )
V_205 = - V_151 ;
V_200 -> V_209 . V_210 ( & V_200 -> V_209 , V_205 ) ;
}
void F_65 ( void * V_214 )
{
struct V_196 * V_197 = V_214 ;
struct V_165 * V_166 =
( void * ) ( V_215 long ) V_197 -> V_216 ;
V_166 -> V_217 ( V_197 , V_166 ) ;
}
static int F_66 ( struct V_199 * V_200 )
{
struct V_54 * V_55 = F_67 ( V_200 ) ;
struct V_218 * V_32 = F_68 ( V_55 ) ;
struct V_12 * V_13 = F_69 ( V_32 ) ;
struct V_165 * V_166 = F_70 ( V_200 ) ;
struct V_131 * V_219 ;
struct V_128 * V_129 ;
struct V_69 * V_220 ;
int V_221 = F_23 ( V_55 ) ;
int V_34 , V_222 = 0 ;
V_34 = F_52 ( V_13 -> V_156 , V_200 -> V_223 , V_200 -> V_224 , V_166 ) ;
if ( F_54 ( V_34 ) )
return V_34 ;
V_220 = & V_166 -> V_138 ;
* V_220 = V_13 -> V_127 ;
V_166 -> V_198 = V_13 ;
V_166 -> V_201 = V_200 ;
V_166 -> V_217 = F_62 ;
V_166 -> V_138 . V_225 . V_216 = ( V_226 ) ( V_215 long ) V_166 ;
V_166 -> V_138 . V_225 . V_227 = V_166 -> V_169 . V_171 ;
V_166 -> V_138 . V_225 . V_228 = V_166 -> V_169 . V_173 ;
V_219 = ( void * ) & V_166 -> V_138 . V_130 ;
V_219 -> V_229 = V_200 -> V_230 - V_221 ;
V_219 -> V_231 = V_200 -> V_232 ;
memcpy ( V_219 -> V_99 . V_233 , V_200 -> V_234 , V_107 ) ;
V_129 = ( void * ) ( ( T_1 * ) V_219 + sizeof( * V_219 ) ) ;
V_129 -> V_235 = 0 ;
V_129 -> V_236 = V_200 -> V_232 + V_219 -> V_229 ;
do {
V_34 = F_71 ( V_13 -> V_156 -> V_237 , ( V_238 * ) V_220 ) ;
} while ( V_34 == - V_239 && V_222 ++ < 10 );
if ( V_34 == - V_239 ) {
F_49 ( V_13 -> V_156 , V_166 ) ;
return - V_240 ;
}
return - V_241 ;
}
static int F_72 ( struct V_199 * V_200 )
{
struct V_54 * V_55 = F_67 ( V_200 ) ;
struct V_218 * V_32 = F_68 ( V_55 ) ;
struct V_12 * V_13 = F_69 ( V_32 ) ;
struct V_165 * V_166 = F_70 ( V_200 ) ;
struct V_131 * V_219 ;
struct V_128 * V_129 ;
struct V_69 * V_220 ;
T_1 * V_234 = V_200 -> V_234 ;
int V_34 , V_222 = 0 ;
V_34 = F_52 ( V_13 -> V_156 , V_200 -> V_223 , V_200 -> V_224 , V_166 ) ;
if ( F_54 ( V_34 ) )
return V_34 ;
V_220 = & V_166 -> V_138 ;
* V_220 = V_13 -> V_71 ;
V_166 -> V_198 = V_13 ;
V_166 -> V_201 = V_200 ;
V_166 -> V_217 = F_62 ;
V_166 -> V_138 . V_225 . V_216 = ( V_226 ) ( V_215 long ) V_166 ;
V_166 -> V_138 . V_225 . V_227 = V_166 -> V_169 . V_171 ;
V_166 -> V_138 . V_225 . V_228 = V_166 -> V_169 . V_173 ;
V_219 = ( void * ) & V_166 -> V_138 . V_130 ;
V_129 = ( void * ) ( ( T_1 * ) V_219 + sizeof( * V_219 ) ) ;
memcpy ( V_219 -> V_99 . V_233 , V_234 , V_107 ) ;
V_219 -> V_229 = V_200 -> V_230 ;
V_219 -> V_231 = V_200 -> V_232 ;
V_129 -> V_235 = 0 ;
V_129 -> V_236 = V_200 -> V_232 + V_200 -> V_230 ;
do {
V_34 = F_71 ( V_13 -> V_156 -> V_237 , ( V_238 * ) V_220 ) ;
} while ( V_34 == - V_239 && V_222 ++ < 10 );
if ( V_34 == - V_239 ) {
F_49 ( V_13 -> V_156 , V_166 ) ;
return - V_240 ;
}
return - V_241 ;
}
static int F_73 ( struct V_242 * V_32 ,
const T_4 * V_84 , unsigned int V_140 ,
int V_59 )
{
struct V_137 * V_13 = F_74 ( V_32 ) ;
struct V_154 * V_155 ;
F_75 ( & V_13 -> V_243 ) ;
if ( V_13 -> V_63 ) {
V_155 = & F_44 ( V_13 -> V_156 -> V_157 ) ;
memset ( V_13 -> V_63 , 0 , sizeof( * V_13 -> V_63 ) ) ;
memset ( V_13 -> V_125 , 0 , sizeof( * V_13 -> V_125 ) ) ;
memset ( & V_13 -> V_71 , 0 , sizeof( V_13 -> V_71 ) ) ;
memset ( & V_13 -> V_127 , 0 , sizeof( V_13 -> V_127 ) ) ;
} else {
int V_158 = F_45 () ;
struct V_159 * V_156 =
F_46 ( V_158 ) ;
if ( ! V_156 ) {
F_76 ( & V_13 -> V_243 ) ;
return - V_151 ;
}
V_155 = & F_44 ( V_156 -> V_157 ) ;
V_13 -> V_156 = V_156 ;
V_13 -> V_63 = F_47 ( V_155 , sizeof( * V_13 -> V_63 ) ,
& V_13 -> V_102 ,
V_160 ) ;
if ( ! V_13 -> V_63 ) {
F_76 ( & V_13 -> V_243 ) ;
return - V_161 ;
}
V_13 -> V_125 = F_47 ( V_155 , sizeof( * V_13 -> V_125 ) ,
& V_13 -> V_135 ,
V_160 ) ;
if ( ! V_13 -> V_125 ) {
F_76 ( & V_13 -> V_243 ) ;
goto V_162;
}
}
F_76 ( & V_13 -> V_243 ) ;
if ( F_41 ( V_13 , V_84 , V_140 , V_59 ) )
goto V_164;
return 0 ;
V_164:
memset ( V_13 -> V_125 , 0 , sizeof( * V_13 -> V_63 ) ) ;
F_48 ( V_155 , sizeof( * V_13 -> V_63 ) ,
V_13 -> V_125 , V_13 -> V_135 ) ;
V_13 -> V_125 = NULL ;
V_162:
memset ( V_13 -> V_63 , 0 , sizeof( * V_13 -> V_125 ) ) ;
F_48 ( V_155 , sizeof( * V_13 -> V_125 ) ,
V_13 -> V_63 , V_13 -> V_102 ) ;
V_13 -> V_63 = NULL ;
return - V_161 ;
}
static int F_77 ( struct V_242 * V_32 ,
const T_4 * V_84 , unsigned int V_140 )
{
return F_73 ( V_32 , V_84 , V_140 ,
V_163 ) ;
}
static int F_78 ( struct V_242 * V_32 ,
const T_4 * V_84 , unsigned int V_140 )
{
return F_73 ( V_32 , V_84 , V_140 ,
V_142 ) ;
}
static int F_79 ( struct V_242 * V_32 ,
const T_4 * V_84 , unsigned int V_140 )
{
return F_73 ( V_32 , V_84 , V_140 ,
V_144 ) ;
}
static int F_80 ( struct V_212 * V_138 )
{
struct V_242 * V_244 = F_81 ( V_138 ) ;
struct V_218 * V_32 = F_82 ( V_244 ) ;
struct V_137 * V_13 = F_69 ( V_32 ) ;
struct V_165 * V_166 = F_83 ( V_138 ) ;
struct V_131 * V_219 ;
struct V_69 * V_220 ;
int V_34 , V_222 = 0 ;
V_34 = F_52 ( V_13 -> V_156 , V_138 -> V_223 , V_138 -> V_224 , V_166 ) ;
if ( F_54 ( V_34 ) )
return V_34 ;
V_220 = & V_166 -> V_138 ;
* V_220 = V_13 -> V_71 ;
V_166 -> V_211 = V_13 ;
V_166 -> V_213 = V_138 ;
V_166 -> V_217 = F_64 ;
V_166 -> V_138 . V_225 . V_216 = ( V_226 ) ( V_215 long ) V_166 ;
V_166 -> V_138 . V_225 . V_227 = V_166 -> V_169 . V_171 ;
V_166 -> V_138 . V_225 . V_228 = V_166 -> V_169 . V_173 ;
V_219 = ( void * ) & V_166 -> V_138 . V_130 ;
V_219 -> V_229 = V_138 -> V_245 ;
V_219 -> V_231 = 0 ;
memcpy ( V_219 -> V_99 . V_233 , V_138 -> V_246 , V_107 ) ;
do {
V_34 = F_71 ( V_13 -> V_156 -> V_237 , ( V_238 * ) V_220 ) ;
} while ( V_34 == - V_239 && V_222 ++ < 10 );
if ( V_34 == - V_239 ) {
F_49 ( V_13 -> V_156 , V_166 ) ;
return - V_240 ;
}
return - V_241 ;
}
static int F_84 ( struct V_212 * V_138 )
{
struct V_242 * V_244 = F_81 ( V_138 ) ;
struct V_218 * V_32 = F_82 ( V_244 ) ;
struct V_137 * V_13 = F_69 ( V_32 ) ;
struct V_165 * V_166 = F_83 ( V_138 ) ;
struct V_131 * V_219 ;
struct V_69 * V_220 ;
int V_34 , V_222 = 0 ;
V_34 = F_52 ( V_13 -> V_156 , V_138 -> V_223 , V_138 -> V_224 , V_166 ) ;
if ( F_54 ( V_34 ) )
return V_34 ;
V_220 = & V_166 -> V_138 ;
* V_220 = V_13 -> V_127 ;
V_166 -> V_211 = V_13 ;
V_166 -> V_213 = V_138 ;
V_166 -> V_217 = F_64 ;
V_166 -> V_138 . V_225 . V_216 = ( V_226 ) ( V_215 long ) V_166 ;
V_166 -> V_138 . V_225 . V_227 = V_166 -> V_169 . V_171 ;
V_166 -> V_138 . V_225 . V_228 = V_166 -> V_169 . V_173 ;
V_219 = ( void * ) & V_166 -> V_138 . V_130 ;
V_219 -> V_229 = V_138 -> V_245 ;
V_219 -> V_231 = 0 ;
memcpy ( V_219 -> V_99 . V_233 , V_138 -> V_246 , V_107 ) ;
do {
V_34 = F_71 ( V_13 -> V_156 -> V_237 , ( V_238 * ) V_220 ) ;
} while ( V_34 == - V_239 && V_222 ++ < 10 );
if ( V_34 == - V_239 ) {
F_49 ( V_13 -> V_156 , V_166 ) ;
return - V_240 ;
}
return - V_241 ;
}
static int F_85 ( struct V_54 * V_32 ,
enum V_1 V_11 ,
const char * V_247 )
{
struct V_12 * V_13 = F_22 ( V_32 ) ;
V_13 -> V_17 = F_86 ( V_247 , 0 , 0 ) ;
if ( F_87 ( V_13 -> V_17 ) )
return F_88 ( V_13 -> V_17 ) ;
V_13 -> V_2 = V_11 ;
F_89 ( V_32 , sizeof( struct V_199 ) +
sizeof( struct V_165 ) ) ;
return 0 ;
}
static int F_90 ( struct V_54 * V_32 )
{
return F_85 ( V_32 , V_3 , L_2 ) ;
}
static int F_91 ( struct V_54 * V_32 )
{
return F_85 ( V_32 , V_5 , L_3 ) ;
}
static int F_92 ( struct V_54 * V_32 )
{
return F_85 ( V_32 , V_7 , L_4 ) ;
}
static void F_93 ( struct V_54 * V_32 )
{
struct V_12 * V_13 = F_22 ( V_32 ) ;
struct V_159 * V_156 = V_13 -> V_156 ;
struct V_154 * V_155 ;
F_94 ( V_13 -> V_17 ) ;
if ( ! V_156 )
return;
V_155 = & F_44 ( V_156 -> V_157 ) ;
if ( V_13 -> V_63 ) {
memset ( V_13 -> V_63 , 0 , sizeof( struct V_104 ) ) ;
F_48 ( V_155 , sizeof( struct V_104 ) ,
V_13 -> V_63 , V_13 -> V_102 ) ;
}
if ( V_13 -> V_125 ) {
memset ( V_13 -> V_125 , 0 , sizeof( struct V_104 ) ) ;
F_48 ( V_155 , sizeof( struct V_104 ) ,
V_13 -> V_125 , V_13 -> V_135 ) ;
}
F_95 ( V_156 ) ;
}
static int F_96 ( struct V_218 * V_32 )
{
struct V_137 * V_13 = F_69 ( V_32 ) ;
F_97 ( & V_13 -> V_243 ) ;
V_32 -> V_248 . V_249 = sizeof( struct V_212 ) +
sizeof( struct V_165 ) ;
V_13 -> V_32 = V_32 ;
return 0 ;
}
static void F_98 ( struct V_218 * V_32 )
{
struct V_137 * V_13 = F_69 ( V_32 ) ;
struct V_159 * V_156 = V_13 -> V_156 ;
struct V_154 * V_155 ;
if ( ! V_156 )
return;
V_155 = & F_44 ( V_156 -> V_157 ) ;
if ( V_13 -> V_63 ) {
memset ( V_13 -> V_63 , 0 ,
sizeof( struct V_65 ) ) ;
F_48 ( V_155 ,
sizeof( struct V_65 ) ,
V_13 -> V_63 , V_13 -> V_102 ) ;
}
if ( V_13 -> V_125 ) {
memset ( V_13 -> V_125 , 0 ,
sizeof( struct V_65 ) ) ;
F_48 ( V_155 ,
sizeof( struct V_65 ) ,
V_13 -> V_125 , V_13 -> V_135 ) ;
}
F_95 ( V_156 ) ;
}
int F_99 ( void )
{
int V_34 = 0 , V_30 ;
F_100 ( & V_250 ) ;
if ( ++ V_251 != 1 )
goto V_252;
for ( V_30 = 0 ; V_30 < F_101 ( V_253 ) ; V_30 ++ )
V_253 [ V_30 ] . V_254 = V_255 | V_256 ;
V_34 = F_102 ( V_253 , F_101 ( V_253 ) ) ;
if ( V_34 )
goto V_252;
for ( V_30 = 0 ; V_30 < F_101 ( V_257 ) ; V_30 ++ )
V_257 [ V_30 ] . V_209 . V_254 = V_256 ;
V_34 = F_103 ( V_257 , F_101 ( V_257 ) ) ;
if ( V_34 )
goto V_258;
V_252:
F_104 ( & V_250 ) ;
return V_34 ;
V_258:
F_105 ( V_253 , F_101 ( V_253 ) ) ;
goto V_252;
}
void F_106 ( void )
{
F_100 ( & V_250 ) ;
if ( -- V_251 != 0 )
goto V_252;
F_107 ( V_257 , F_101 ( V_257 ) ) ;
F_105 ( V_253 , F_101 ( V_253 ) ) ;
V_252:
F_104 ( & V_250 ) ;
}
