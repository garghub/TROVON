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
struct V_57 * V_58 )
{
struct V_12 * V_13 = F_22 ( V_55 ) ;
unsigned int V_59 = F_23 ( V_55 ) ;
struct V_60 * V_61 = & V_13 -> V_62 -> V_63 ;
struct V_64 * V_65 = & V_61 -> V_65 ;
struct V_10 * V_11 =
(struct V_10 * ) ( ( char * ) V_61 +
sizeof( struct V_66 ) + V_58 -> V_67 ) ;
struct V_68 * V_69 = & V_13 -> V_70 ;
struct V_71 * V_72 = & V_69 -> V_72 ;
struct V_40 * V_41 = & V_69 -> V_73 ;
void * V_74 = & V_69 -> V_75 ;
struct V_76 * V_77 = V_74 ;
struct V_78 * V_79 = V_74 ;
V_65 -> V_80 . V_81 . V_82 = F_24 ( V_56 ) ;
memcpy ( V_65 -> V_80 . V_83 , V_58 -> V_84 , V_58 -> V_67 ) ;
V_11 -> V_37 . V_85 . V_86 . V_87 =
F_25 ( V_88 ,
V_13 -> V_2 , V_59 ) ;
V_11 -> V_37 . V_85 . V_89 . V_90 =
F_10 ( F_4 ( V_13 -> V_17 ) ) ;
if ( F_2 ( V_11 , V_13 , V_58 -> V_91 , V_58 -> V_92 ) )
return - V_9 ;
F_14 ( V_41 ) ;
V_41 -> V_93 = V_94 ;
F_26 ( V_41 -> V_49 ,
V_95 ) ;
F_27 ( V_41 -> V_49 ,
V_96 ) ;
F_28 ( V_41 -> V_49 ,
V_97 ) ;
V_72 -> V_98 . V_99 . V_100 = V_13 -> V_101 ;
V_72 -> V_98 . V_99 . V_102 = sizeof( struct V_103 ) >> 3 ;
V_77 -> V_104 = V_58 -> V_67 >> 3 ;
V_77 -> V_105 = V_106 >> 3 ;
V_77 -> V_107 = 0 ;
F_29 ( V_77 , V_108 ) ;
F_30 ( V_77 , V_109 ) ;
V_79 -> V_110 = ( ( char * ) V_11 - ( char * ) V_65 ) >> 3 ;
V_79 -> V_111 = V_112 ;
V_79 -> V_113 = V_59 ;
V_79 -> V_114 = V_59 ;
switch ( V_13 -> V_2 ) {
case V_3 :
V_79 -> V_115 =
F_12 ( V_4 , 8 ) ;
V_79 -> V_116 =
F_12 ( V_117 , 8 ) ;
break;
case V_5 :
V_79 -> V_115 = V_6 ;
V_79 -> V_116 = V_118 ;
break;
case V_7 :
V_79 -> V_115 = V_8 ;
V_79 -> V_116 = V_119 ;
break;
default:
break;
}
V_79 -> V_120 = V_79 -> V_110 +
( ( sizeof( struct V_66 ) +
F_12 ( V_79 -> V_115 , 8 ) ) >> 3 ) ;
F_29 ( V_79 , V_109 ) ;
F_30 ( V_79 , V_121 ) ;
return 0 ;
}
static int F_31 ( struct V_54 * V_55 ,
int V_56 ,
struct V_57 * V_58 )
{
struct V_12 * V_13 = F_22 ( V_55 ) ;
unsigned int V_59 = F_23 ( V_55 ) ;
struct V_122 * V_123 = & V_13 -> V_124 -> V_125 ;
struct V_10 * V_11 = & V_123 -> V_11 ;
struct V_64 * V_65 =
(struct V_64 * ) ( ( char * ) V_123 +
sizeof( struct V_66 ) +
F_32 ( F_5 ( V_13 -> V_17 ) , 8 ) * 2 ) ;
struct V_68 * V_69 = & V_13 -> V_126 ;
struct V_71 * V_72 = & V_69 -> V_72 ;
struct V_40 * V_41 = & V_69 -> V_73 ;
void * V_74 = & V_69 -> V_75 ;
struct V_76 * V_77 = V_74 ;
struct V_78 * V_79 = V_74 ;
struct V_127 * V_128 =
(struct V_127 * )
( ( char * ) & V_69 -> V_129 +
sizeof( struct V_130 ) ) ;
V_65 -> V_80 . V_81 . V_82 = F_33 ( V_56 ) ;
memcpy ( V_65 -> V_80 . V_83 , V_58 -> V_84 , V_58 -> V_67 ) ;
V_11 -> V_37 . V_85 . V_86 . V_87 =
F_25 ( V_88 ,
V_13 -> V_2 ,
V_59 ) ;
V_11 -> V_37 . V_85 . V_89 . V_90 =
F_10 ( F_4 ( V_13 -> V_17 ) ) ;
if ( F_2 ( V_11 , V_13 , V_58 -> V_91 , V_58 -> V_92 ) )
return - V_9 ;
F_14 ( V_41 ) ;
V_41 -> V_93 = V_131 ;
F_26 ( V_41 -> V_49 ,
V_95 ) ;
F_27 ( V_41 -> V_49 ,
V_132 ) ;
F_28 ( V_41 -> V_49 ,
V_133 ) ;
V_72 -> V_98 . V_99 . V_100 = V_13 -> V_134 ;
V_72 -> V_98 . V_99 . V_102 = sizeof( struct V_103 ) >> 3 ;
V_77 -> V_104 = V_58 -> V_67 >> 3 ;
V_77 -> V_105 = V_106 >> 3 ;
V_77 -> V_107 =
( sizeof( struct V_66 ) +
F_32 ( F_5 ( V_13 -> V_17 ) , 8 ) * 2 ) >> 3 ;
F_29 ( V_77 , V_108 ) ;
F_30 ( V_77 , V_121 ) ;
V_79 -> V_110 = 0 ;
V_79 -> V_111 = V_112 ;
V_79 -> V_113 = V_59 ;
V_79 -> V_114 = V_59 ;
switch ( V_13 -> V_2 ) {
case V_3 :
V_79 -> V_115 =
F_12 ( V_4 , 8 ) ;
V_79 -> V_116 =
F_12 ( V_117 , 8 ) ;
break;
case V_5 :
V_79 -> V_115 = V_6 ;
V_79 -> V_116 = V_118 ;
break;
case V_7 :
V_79 -> V_115 = V_8 ;
V_79 -> V_116 = V_119 ;
break;
default:
break;
}
V_79 -> V_120 = V_79 -> V_110 +
( ( sizeof( struct V_66 ) +
F_12 ( V_79 -> V_115 , 8 ) ) >> 3 ) ;
V_128 -> V_135 = V_59 ;
F_29 ( V_79 , V_109 ) ;
F_30 ( V_79 , V_108 ) ;
return 0 ;
}
static void F_34 ( struct V_136 * V_13 ,
struct V_68 * V_137 ,
struct V_64 * V_138 ,
const T_1 * V_83 , unsigned int V_139 )
{
struct V_71 * V_72 = & V_137 -> V_72 ;
struct V_40 * V_41 = & V_137 -> V_73 ;
struct V_76 * V_75 = ( void * ) & V_137 -> V_75 ;
memcpy ( V_138 -> V_80 . V_83 , V_83 , V_139 ) ;
F_14 ( V_41 ) ;
V_41 -> V_93 = V_140 ;
V_72 -> V_98 . V_99 . V_102 =
sizeof( struct V_64 ) >> 3 ;
V_75 -> V_104 = V_139 >> 3 ;
V_75 -> V_105 = V_106 >> 3 ;
V_75 -> V_107 = 0 ;
F_29 ( V_75 , V_108 ) ;
F_30 ( V_75 , V_121 ) ;
}
static void F_35 ( struct V_136 * V_13 ,
int V_56 , const T_1 * V_83 ,
unsigned int V_139 )
{
struct V_64 * V_62 = V_13 -> V_62 ;
struct V_68 * V_137 = & V_13 -> V_70 ;
struct V_71 * V_72 = & V_137 -> V_72 ;
F_34 ( V_13 , V_137 , V_62 , V_83 , V_139 ) ;
V_72 -> V_98 . V_99 . V_100 = V_13 -> V_101 ;
V_62 -> V_80 . V_81 . V_82 = F_24 ( V_56 ) ;
}
static void F_36 ( struct V_136 * V_13 ,
int V_56 , const T_1 * V_83 ,
unsigned int V_139 )
{
struct V_64 * V_124 = V_13 -> V_124 ;
struct V_68 * V_137 = & V_13 -> V_126 ;
struct V_71 * V_72 = & V_137 -> V_72 ;
F_34 ( V_13 , V_137 , V_124 , V_83 , V_139 ) ;
V_72 -> V_98 . V_99 . V_100 = V_13 -> V_134 ;
V_124 -> V_80 . V_81 . V_82 = F_33 ( V_56 ) ;
}
static int F_37 ( int V_141 , int * V_56 )
{
switch ( V_141 ) {
case V_142 :
* V_56 = V_143 ;
break;
case V_144 :
* V_56 = V_145 ;
break;
case V_146 :
* V_56 = V_147 ;
break;
default:
return - V_148 ;
}
return 0 ;
}
static int F_38 ( struct V_54 * V_32 ,
const T_1 * V_83 , unsigned int V_139 )
{
struct V_57 V_58 ;
int V_56 ;
if ( F_39 ( & V_58 , V_83 , V_139 ) )
goto V_149;
if ( F_37 ( V_58 . V_67 , & V_56 ) )
goto V_149;
if ( F_21 ( V_32 , V_56 , & V_58 ) )
goto error;
if ( F_31 ( V_32 , V_56 , & V_58 ) )
goto error;
return 0 ;
V_149:
F_40 ( V_32 , V_150 ) ;
return - V_148 ;
error:
return - V_9 ;
}
static int F_41 ( struct V_136 * V_13 ,
const T_1 * V_83 ,
unsigned int V_139 )
{
int V_56 ;
if ( F_37 ( V_139 , & V_56 ) )
goto V_149;
F_35 ( V_13 , V_56 , V_83 , V_139 ) ;
F_36 ( V_13 , V_56 , V_83 , V_139 ) ;
return 0 ;
V_149:
F_42 ( V_13 -> V_32 , V_150 ) ;
return - V_148 ;
}
static int F_43 ( struct V_54 * V_32 , const T_1 * V_83 ,
unsigned int V_139 )
{
struct V_12 * V_13 = F_22 ( V_32 ) ;
struct V_151 * V_152 ;
if ( V_13 -> V_62 ) {
V_152 = & F_44 ( V_13 -> V_153 -> V_154 ) ;
memset ( V_13 -> V_62 , 0 , sizeof( * V_13 -> V_62 ) ) ;
memset ( V_13 -> V_124 , 0 , sizeof( * V_13 -> V_124 ) ) ;
memset ( & V_13 -> V_70 , 0 , sizeof( V_13 -> V_70 ) ) ;
memset ( & V_13 -> V_126 , 0 , sizeof( V_13 -> V_126 ) ) ;
} else {
int V_155 = F_45 () ;
struct V_156 * V_153 =
F_46 ( V_155 ) ;
if ( ! V_153 ) {
return - V_148 ;
}
V_152 = & F_44 ( V_153 -> V_154 ) ;
V_13 -> V_153 = V_153 ;
V_13 -> V_62 = F_47 ( V_152 , sizeof( * V_13 -> V_62 ) ,
& V_13 -> V_101 ,
V_157 ) ;
if ( ! V_13 -> V_62 ) {
return - V_158 ;
}
V_13 -> V_124 = F_47 ( V_152 , sizeof( * V_13 -> V_124 ) ,
& V_13 -> V_134 ,
V_157 ) ;
if ( ! V_13 -> V_124 ) {
goto V_159;
}
}
if ( F_38 ( V_32 , V_83 , V_139 ) )
goto V_160;
return 0 ;
V_160:
memset ( V_13 -> V_124 , 0 , sizeof( struct V_103 ) ) ;
F_48 ( V_152 , sizeof( struct V_103 ) ,
V_13 -> V_124 , V_13 -> V_134 ) ;
V_13 -> V_124 = NULL ;
V_159:
memset ( V_13 -> V_62 , 0 , sizeof( struct V_103 ) ) ;
F_48 ( V_152 , sizeof( struct V_103 ) ,
V_13 -> V_62 , V_13 -> V_101 ) ;
V_13 -> V_62 = NULL ;
return - V_158 ;
}
static void F_49 ( struct V_156 * V_153 ,
struct V_161 * V_162 )
{
struct V_151 * V_152 = & F_44 ( V_153 -> V_154 ) ;
struct V_163 * V_164 = V_162 -> V_165 . V_164 ;
struct V_163 * V_166 = V_162 -> V_165 . V_166 ;
T_4 V_167 = V_162 -> V_165 . V_167 ;
T_4 V_168 = V_162 -> V_165 . V_169 ;
T_5 V_170 = V_162 -> V_165 . V_170 ;
T_5 V_171 = V_162 -> V_165 . V_171 ;
int V_30 ;
for ( V_30 = 0 ; V_30 < V_164 -> V_172 ; V_30 ++ )
F_50 ( V_152 , V_164 -> V_173 [ V_30 ] . V_174 ,
V_164 -> V_173 [ V_30 ] . V_175 , V_176 ) ;
F_50 ( V_152 , V_167 , V_170 , V_177 ) ;
F_51 ( V_164 ) ;
if ( V_167 != V_168 ) {
int V_178 = V_166 -> V_172 - V_166 -> V_179 ;
for ( V_30 = V_178 ; V_30 < V_166 -> V_172 ; V_30 ++ ) {
F_50 ( V_152 , V_166 -> V_173 [ V_30 ] . V_174 ,
V_166 -> V_173 [ V_30 ] . V_175 ,
V_176 ) ;
}
F_50 ( V_152 , V_168 , V_171 , V_177 ) ;
F_51 ( V_166 ) ;
}
}
static int F_52 ( struct V_156 * V_153 ,
struct V_180 * V_181 ,
struct V_180 * V_182 ,
struct V_161 * V_162 )
{
struct V_151 * V_152 = & F_44 ( V_153 -> V_154 ) ;
int V_30 , V_183 = 0 ;
int V_184 = F_53 ( V_181 ) ;
struct V_163 * V_185 ;
struct V_163 * V_186 = NULL ;
T_4 V_167 ;
T_4 V_169 = 0 ;
struct V_180 * V_187 ;
T_5 V_171 , V_170 = sizeof( struct V_163 ) +
( ( 1 + V_184 ) * sizeof( struct V_188 ) ) ;
if ( F_54 ( ! V_184 ) )
return - V_148 ;
V_185 = F_55 ( V_170 , V_157 ,
F_56 ( & F_44 ( V_153 -> V_154 ) ) ) ;
if ( F_54 ( ! V_185 ) )
return - V_158 ;
V_167 = F_57 ( V_152 , V_185 , V_170 , V_177 ) ;
if ( F_54 ( F_58 ( V_152 , V_167 ) ) )
goto V_189;
F_59 (sgl, sg, n, i) {
int V_190 = V_183 ;
if ( ! V_187 -> V_191 )
continue;
V_185 -> V_173 [ V_190 ] . V_174 = F_57 ( V_152 , F_60 ( V_187 ) ,
V_187 -> V_191 ,
V_176 ) ;
V_185 -> V_173 [ V_190 ] . V_175 = V_187 -> V_191 ;
if ( F_54 ( F_58 ( V_152 , V_185 -> V_173 [ V_190 ] . V_174 ) ) )
goto V_189;
V_183 ++ ;
}
V_185 -> V_172 = V_183 ;
V_162 -> V_165 . V_164 = V_185 ;
V_162 -> V_165 . V_167 = V_167 ;
V_162 -> V_165 . V_170 = V_170 ;
if ( V_181 != V_182 ) {
struct V_188 * V_173 ;
V_184 = F_53 ( V_182 ) ;
V_171 = sizeof( struct V_163 ) +
( ( 1 + V_184 ) * sizeof( struct V_188 ) ) ;
V_183 = 0 ;
V_186 = F_55 ( V_171 , V_157 ,
F_56 ( & F_44 ( V_153 -> V_154 ) ) ) ;
if ( F_54 ( ! V_186 ) )
goto V_189;
V_169 = F_57 ( V_152 , V_186 , V_171 , V_177 ) ;
if ( F_54 ( F_58 ( V_152 , V_169 ) ) )
goto V_189;
V_173 = V_186 -> V_173 ;
F_59 (sglout, sg, n, i) {
int V_190 = V_183 ;
if ( ! V_187 -> V_191 )
continue;
V_173 [ V_190 ] . V_174 = F_57 ( V_152 , F_60 ( V_187 ) ,
V_187 -> V_191 ,
V_176 ) ;
if ( F_54 ( F_58 ( V_152 , V_173 [ V_190 ] . V_174 ) ) )
goto V_189;
V_173 [ V_190 ] . V_175 = V_187 -> V_191 ;
V_183 ++ ;
}
V_186 -> V_172 = V_183 ;
V_186 -> V_179 = V_183 ;
V_162 -> V_165 . V_166 = V_186 ;
V_162 -> V_165 . V_169 = V_169 ;
V_162 -> V_165 . V_171 = V_171 ;
} else {
V_162 -> V_165 . V_169 = V_162 -> V_165 . V_167 ;
V_162 -> V_165 . V_171 = 0 ;
}
return 0 ;
V_189:
F_61 ( V_152 , L_1 ) ;
V_183 = 0 ;
for ( V_30 = 0 ; V_30 < V_184 ; V_30 ++ )
if ( ! F_58 ( V_152 , V_185 -> V_173 [ V_30 ] . V_174 ) )
F_50 ( V_152 , V_185 -> V_173 [ V_30 ] . V_174 ,
V_185 -> V_173 [ V_30 ] . V_175 ,
V_176 ) ;
if ( ! F_58 ( V_152 , V_167 ) )
F_50 ( V_152 , V_167 , V_170 , V_177 ) ;
F_51 ( V_185 ) ;
if ( V_181 != V_182 && V_186 ) {
V_184 = F_53 ( V_182 ) ;
for ( V_30 = 0 ; V_30 < V_184 ; V_30 ++ )
if ( ! F_58 ( V_152 , V_186 -> V_173 [ V_30 ] . V_174 ) )
F_50 ( V_152 , V_186 -> V_173 [ V_30 ] . V_174 ,
V_186 -> V_173 [ V_30 ] . V_175 ,
V_176 ) ;
if ( ! F_58 ( V_152 , V_169 ) )
F_50 ( V_152 , V_169 , V_171 , V_177 ) ;
F_51 ( V_186 ) ;
}
return - V_158 ;
}
static void F_62 ( struct V_192 * V_193 ,
struct V_161 * V_162 )
{
struct V_12 * V_13 = V_162 -> V_194 ;
struct V_156 * V_153 = V_13 -> V_153 ;
struct V_195 * V_196 = V_162 -> V_197 ;
T_1 V_198 = V_193 -> V_199 . V_200 ;
int V_201 = 0 , V_202 = F_63 ( V_198 ) ;
F_49 ( V_153 , V_162 ) ;
if ( F_54 ( V_202 != V_203 ) )
V_201 = - V_204 ;
V_196 -> V_205 . V_206 ( & V_196 -> V_205 , V_201 ) ;
}
static void F_64 ( struct V_192 * V_193 ,
struct V_161 * V_162 )
{
struct V_136 * V_13 = V_162 -> V_207 ;
struct V_156 * V_153 = V_13 -> V_153 ;
struct V_208 * V_196 = V_162 -> V_209 ;
T_1 V_198 = V_193 -> V_199 . V_200 ;
int V_201 = 0 , V_202 = F_63 ( V_198 ) ;
F_49 ( V_153 , V_162 ) ;
if ( F_54 ( V_202 != V_203 ) )
V_201 = - V_148 ;
V_196 -> V_205 . V_206 ( & V_196 -> V_205 , V_201 ) ;
}
void F_65 ( void * V_210 )
{
struct V_192 * V_193 = V_210 ;
struct V_161 * V_162 =
( void * ) ( V_211 long ) V_193 -> V_212 ;
V_162 -> V_213 ( V_193 , V_162 ) ;
}
static int F_66 ( struct V_195 * V_196 )
{
struct V_54 * V_55 = F_67 ( V_196 ) ;
struct V_214 * V_32 = F_68 ( V_55 ) ;
struct V_12 * V_13 = F_69 ( V_32 ) ;
struct V_161 * V_162 = F_70 ( V_196 ) ;
struct V_130 * V_215 ;
struct V_127 * V_128 ;
struct V_68 * V_216 ;
int V_217 = F_23 ( V_55 ) ;
int V_34 , V_218 = 0 ;
V_34 = F_52 ( V_13 -> V_153 , V_196 -> V_219 , V_196 -> V_220 , V_162 ) ;
if ( F_54 ( V_34 ) )
return V_34 ;
V_216 = & V_162 -> V_137 ;
* V_216 = V_13 -> V_126 ;
V_162 -> V_194 = V_13 ;
V_162 -> V_197 = V_196 ;
V_162 -> V_213 = F_62 ;
V_162 -> V_137 . V_221 . V_212 = ( V_222 ) ( V_211 long ) V_162 ;
V_162 -> V_137 . V_221 . V_223 = V_162 -> V_165 . V_167 ;
V_162 -> V_137 . V_221 . V_224 = V_162 -> V_165 . V_169 ;
V_215 = ( void * ) & V_162 -> V_137 . V_129 ;
V_215 -> V_225 = V_196 -> V_226 - V_217 ;
V_215 -> V_227 = V_196 -> V_228 ;
memcpy ( V_215 -> V_98 . V_229 , V_196 -> V_230 , V_106 ) ;
V_128 = ( void * ) ( ( T_1 * ) V_215 + sizeof( * V_215 ) ) ;
V_128 -> V_231 = 0 ;
V_128 -> V_232 = V_196 -> V_228 + V_215 -> V_225 ;
do {
V_34 = F_71 ( V_13 -> V_153 -> V_233 , ( V_234 * ) V_216 ) ;
} while ( V_34 == - V_235 && V_218 ++ < 10 );
if ( V_34 == - V_235 ) {
F_49 ( V_13 -> V_153 , V_162 ) ;
return - V_236 ;
}
return - V_237 ;
}
static int F_72 ( struct V_195 * V_196 )
{
struct V_54 * V_55 = F_67 ( V_196 ) ;
struct V_214 * V_32 = F_68 ( V_55 ) ;
struct V_12 * V_13 = F_69 ( V_32 ) ;
struct V_161 * V_162 = F_70 ( V_196 ) ;
struct V_130 * V_215 ;
struct V_127 * V_128 ;
struct V_68 * V_216 ;
T_1 * V_230 = V_196 -> V_230 ;
int V_34 , V_218 = 0 ;
V_34 = F_52 ( V_13 -> V_153 , V_196 -> V_219 , V_196 -> V_220 , V_162 ) ;
if ( F_54 ( V_34 ) )
return V_34 ;
V_216 = & V_162 -> V_137 ;
* V_216 = V_13 -> V_70 ;
V_162 -> V_194 = V_13 ;
V_162 -> V_197 = V_196 ;
V_162 -> V_213 = F_62 ;
V_162 -> V_137 . V_221 . V_212 = ( V_222 ) ( V_211 long ) V_162 ;
V_162 -> V_137 . V_221 . V_223 = V_162 -> V_165 . V_167 ;
V_162 -> V_137 . V_221 . V_224 = V_162 -> V_165 . V_169 ;
V_215 = ( void * ) & V_162 -> V_137 . V_129 ;
V_128 = ( void * ) ( ( T_1 * ) V_215 + sizeof( * V_215 ) ) ;
memcpy ( V_215 -> V_98 . V_229 , V_230 , V_106 ) ;
V_215 -> V_225 = V_196 -> V_226 ;
V_215 -> V_227 = V_196 -> V_228 ;
V_128 -> V_231 = 0 ;
V_128 -> V_232 = V_196 -> V_228 + V_196 -> V_226 ;
do {
V_34 = F_71 ( V_13 -> V_153 -> V_233 , ( V_234 * ) V_216 ) ;
} while ( V_34 == - V_235 && V_218 ++ < 10 );
if ( V_34 == - V_235 ) {
F_49 ( V_13 -> V_153 , V_162 ) ;
return - V_236 ;
}
return - V_237 ;
}
static int F_73 ( struct V_238 * V_32 ,
const T_1 * V_83 ,
unsigned int V_139 )
{
struct V_136 * V_13 = F_74 ( V_32 ) ;
struct V_151 * V_152 ;
F_75 ( & V_13 -> V_239 ) ;
if ( V_13 -> V_62 ) {
V_152 = & F_44 ( V_13 -> V_153 -> V_154 ) ;
memset ( V_13 -> V_62 , 0 , sizeof( * V_13 -> V_62 ) ) ;
memset ( V_13 -> V_124 , 0 , sizeof( * V_13 -> V_124 ) ) ;
memset ( & V_13 -> V_70 , 0 , sizeof( V_13 -> V_70 ) ) ;
memset ( & V_13 -> V_126 , 0 , sizeof( V_13 -> V_126 ) ) ;
} else {
int V_155 = F_45 () ;
struct V_156 * V_153 =
F_46 ( V_155 ) ;
if ( ! V_153 ) {
F_76 ( & V_13 -> V_239 ) ;
return - V_148 ;
}
V_152 = & F_44 ( V_153 -> V_154 ) ;
V_13 -> V_153 = V_153 ;
V_13 -> V_62 = F_47 ( V_152 , sizeof( * V_13 -> V_62 ) ,
& V_13 -> V_101 ,
V_157 ) ;
if ( ! V_13 -> V_62 ) {
F_76 ( & V_13 -> V_239 ) ;
return - V_158 ;
}
V_13 -> V_124 = F_47 ( V_152 , sizeof( * V_13 -> V_124 ) ,
& V_13 -> V_134 ,
V_157 ) ;
if ( ! V_13 -> V_124 ) {
F_76 ( & V_13 -> V_239 ) ;
goto V_159;
}
}
F_76 ( & V_13 -> V_239 ) ;
if ( F_41 ( V_13 , V_83 , V_139 ) )
goto V_160;
return 0 ;
V_160:
memset ( V_13 -> V_124 , 0 , sizeof( * V_13 -> V_62 ) ) ;
F_48 ( V_152 , sizeof( * V_13 -> V_62 ) ,
V_13 -> V_124 , V_13 -> V_134 ) ;
V_13 -> V_124 = NULL ;
V_159:
memset ( V_13 -> V_62 , 0 , sizeof( * V_13 -> V_124 ) ) ;
F_48 ( V_152 , sizeof( * V_13 -> V_124 ) ,
V_13 -> V_62 , V_13 -> V_101 ) ;
V_13 -> V_62 = NULL ;
return - V_158 ;
}
static int F_77 ( struct V_208 * V_137 )
{
struct V_238 * V_240 = F_78 ( V_137 ) ;
struct V_214 * V_32 = F_79 ( V_240 ) ;
struct V_136 * V_13 = F_69 ( V_32 ) ;
struct V_161 * V_162 = F_80 ( V_137 ) ;
struct V_130 * V_215 ;
struct V_68 * V_216 ;
int V_34 , V_218 = 0 ;
V_34 = F_52 ( V_13 -> V_153 , V_137 -> V_219 , V_137 -> V_220 , V_162 ) ;
if ( F_54 ( V_34 ) )
return V_34 ;
V_216 = & V_162 -> V_137 ;
* V_216 = V_13 -> V_70 ;
V_162 -> V_207 = V_13 ;
V_162 -> V_209 = V_137 ;
V_162 -> V_213 = F_64 ;
V_162 -> V_137 . V_221 . V_212 = ( V_222 ) ( V_211 long ) V_162 ;
V_162 -> V_137 . V_221 . V_223 = V_162 -> V_165 . V_167 ;
V_162 -> V_137 . V_221 . V_224 = V_162 -> V_165 . V_169 ;
V_215 = ( void * ) & V_162 -> V_137 . V_129 ;
V_215 -> V_225 = V_137 -> V_241 ;
V_215 -> V_227 = 0 ;
memcpy ( V_215 -> V_98 . V_229 , V_137 -> V_242 , V_106 ) ;
do {
V_34 = F_71 ( V_13 -> V_153 -> V_233 , ( V_234 * ) V_216 ) ;
} while ( V_34 == - V_235 && V_218 ++ < 10 );
if ( V_34 == - V_235 ) {
F_49 ( V_13 -> V_153 , V_162 ) ;
return - V_236 ;
}
return - V_237 ;
}
static int F_81 ( struct V_208 * V_137 )
{
struct V_238 * V_240 = F_78 ( V_137 ) ;
struct V_214 * V_32 = F_79 ( V_240 ) ;
struct V_136 * V_13 = F_69 ( V_32 ) ;
struct V_161 * V_162 = F_80 ( V_137 ) ;
struct V_130 * V_215 ;
struct V_68 * V_216 ;
int V_34 , V_218 = 0 ;
V_34 = F_52 ( V_13 -> V_153 , V_137 -> V_219 , V_137 -> V_220 , V_162 ) ;
if ( F_54 ( V_34 ) )
return V_34 ;
V_216 = & V_162 -> V_137 ;
* V_216 = V_13 -> V_126 ;
V_162 -> V_207 = V_13 ;
V_162 -> V_209 = V_137 ;
V_162 -> V_213 = F_64 ;
V_162 -> V_137 . V_221 . V_212 = ( V_222 ) ( V_211 long ) V_162 ;
V_162 -> V_137 . V_221 . V_223 = V_162 -> V_165 . V_167 ;
V_162 -> V_137 . V_221 . V_224 = V_162 -> V_165 . V_169 ;
V_215 = ( void * ) & V_162 -> V_137 . V_129 ;
V_215 -> V_225 = V_137 -> V_241 ;
V_215 -> V_227 = 0 ;
memcpy ( V_215 -> V_98 . V_229 , V_137 -> V_242 , V_106 ) ;
do {
V_34 = F_71 ( V_13 -> V_153 -> V_233 , ( V_234 * ) V_216 ) ;
} while ( V_34 == - V_235 && V_218 ++ < 10 );
if ( V_34 == - V_235 ) {
F_49 ( V_13 -> V_153 , V_162 ) ;
return - V_236 ;
}
return - V_237 ;
}
static int F_82 ( struct V_54 * V_32 ,
enum V_1 V_11 ,
const char * V_243 )
{
struct V_12 * V_13 = F_22 ( V_32 ) ;
V_13 -> V_17 = F_83 ( V_243 , 0 , 0 ) ;
if ( F_84 ( V_13 -> V_17 ) )
return F_85 ( V_13 -> V_17 ) ;
V_13 -> V_2 = V_11 ;
F_86 ( V_32 , sizeof( struct V_195 ) +
sizeof( struct V_161 ) ) ;
return 0 ;
}
static int F_87 ( struct V_54 * V_32 )
{
return F_82 ( V_32 , V_3 , L_2 ) ;
}
static int F_88 ( struct V_54 * V_32 )
{
return F_82 ( V_32 , V_5 , L_3 ) ;
}
static int F_89 ( struct V_54 * V_32 )
{
return F_82 ( V_32 , V_7 , L_4 ) ;
}
static void F_90 ( struct V_54 * V_32 )
{
struct V_12 * V_13 = F_22 ( V_32 ) ;
struct V_156 * V_153 = V_13 -> V_153 ;
struct V_151 * V_152 ;
F_91 ( V_13 -> V_17 ) ;
if ( ! V_153 )
return;
V_152 = & F_44 ( V_153 -> V_154 ) ;
if ( V_13 -> V_62 ) {
memset ( V_13 -> V_62 , 0 , sizeof( struct V_103 ) ) ;
F_48 ( V_152 , sizeof( struct V_103 ) ,
V_13 -> V_62 , V_13 -> V_101 ) ;
}
if ( V_13 -> V_124 ) {
memset ( V_13 -> V_124 , 0 , sizeof( struct V_103 ) ) ;
F_48 ( V_152 , sizeof( struct V_103 ) ,
V_13 -> V_124 , V_13 -> V_134 ) ;
}
F_92 ( V_153 ) ;
}
static int F_93 ( struct V_214 * V_32 )
{
struct V_136 * V_13 = F_69 ( V_32 ) ;
F_94 ( & V_13 -> V_239 ) ;
V_32 -> V_244 . V_245 = sizeof( struct V_208 ) +
sizeof( struct V_161 ) ;
V_13 -> V_32 = V_32 ;
return 0 ;
}
static void F_95 ( struct V_214 * V_32 )
{
struct V_136 * V_13 = F_69 ( V_32 ) ;
struct V_156 * V_153 = V_13 -> V_153 ;
struct V_151 * V_152 ;
if ( ! V_153 )
return;
V_152 = & F_44 ( V_153 -> V_154 ) ;
if ( V_13 -> V_62 ) {
memset ( V_13 -> V_62 , 0 ,
sizeof( struct V_64 ) ) ;
F_48 ( V_152 ,
sizeof( struct V_64 ) ,
V_13 -> V_62 , V_13 -> V_101 ) ;
}
if ( V_13 -> V_124 ) {
memset ( V_13 -> V_124 , 0 ,
sizeof( struct V_64 ) ) ;
F_48 ( V_152 ,
sizeof( struct V_64 ) ,
V_13 -> V_124 , V_13 -> V_134 ) ;
}
F_92 ( V_153 ) ;
}
int F_96 ( void )
{
int V_34 = 0 , V_30 ;
F_97 ( & V_246 ) ;
if ( ++ V_247 != 1 )
goto V_248;
for ( V_30 = 0 ; V_30 < F_98 ( V_249 ) ; V_30 ++ )
V_249 [ V_30 ] . V_250 = V_251 | V_252 ;
V_34 = F_99 ( V_249 , F_98 ( V_249 ) ) ;
if ( V_34 )
goto V_248;
for ( V_30 = 0 ; V_30 < F_98 ( V_253 ) ; V_30 ++ )
V_253 [ V_30 ] . V_205 . V_250 = V_252 ;
V_34 = F_100 ( V_253 , F_98 ( V_253 ) ) ;
if ( V_34 )
goto V_254;
V_248:
F_101 ( & V_246 ) ;
return V_34 ;
V_254:
F_102 ( V_249 , F_98 ( V_249 ) ) ;
goto V_248;
}
int F_103 ( void )
{
F_97 ( & V_246 ) ;
if ( -- V_247 != 0 )
goto V_248;
F_104 ( V_253 , F_98 ( V_253 ) ) ;
F_102 ( V_249 , F_98 ( V_249 ) ) ;
V_248:
F_101 ( & V_246 ) ;
return 0 ;
}
int F_105 ( void )
{
return 0 ;
}
void F_106 ( void )
{
}
