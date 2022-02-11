static void F_1 ( struct V_1 * V_2 , void * V_3 )
{
F_2 ( L_1 , V_2 -> V_4 ) ;
}
static void F_3 ( struct V_1 * V_2 , void * V_3 )
{
F_2 ( L_2 , V_2 -> V_4 ) ;
}
static void F_4 ( struct V_5 * V_6 ,
struct V_1 * V_4 )
{
F_2 ( L_3 , V_4 -> V_4 ,
V_4 -> V_7 -> V_8 , V_4 -> V_9 . V_10 ) ;
}
static int F_5 ( struct V_11 * V_7 )
{
struct V_12 * V_13 ;
struct V_14 * V_15 = & V_7 -> V_15 ;
int V_16 , V_17 , V_18 ;
V_16 = F_6 ( V_7 -> V_19 , V_15 ) ;
if ( V_16 ) {
F_7 ( L_4 , V_7 -> V_19 -> V_8 ) ;
return V_16 ;
}
if ( V_7 -> V_19 -> V_20 && V_7 -> V_19 -> V_21 &&
V_7 -> V_19 -> V_22 && V_7 -> V_19 -> V_23 ) {
F_8 ( L_5 ) ;
V_7 -> V_24 = V_25 ;
V_7 -> V_26 = V_27 ;
V_7 -> V_28 = V_29 ;
V_7 -> V_30 = V_31 ;
} else
if ( V_15 -> V_32 & V_33 ) {
F_8 ( L_6 ) ;
V_7 -> V_24 = V_34 ;
V_7 -> V_26 = V_35 ;
V_7 -> V_28 = V_36 ;
V_7 -> V_30 = V_37 ;
} else {
F_2 ( L_7 ) ;
return - 1 ;
}
V_7 -> V_38 = F_9 ( V_39 , V_7 -> V_19 -> V_40 ) ;
F_8 ( L_8 ,
V_7 -> V_38 , V_7 -> V_19 -> V_8 ,
V_7 -> V_19 -> V_40 ) ;
V_7 -> V_13 = F_10 ( sizeof( struct V_12 ) * V_7 -> V_38 ,
V_41 ) ;
if ( V_7 -> V_13 == NULL )
goto V_42;
V_13 = V_7 -> V_13 ;
V_7 -> V_43 = F_11 ( V_7 -> V_19 ) ;
if ( F_12 ( V_7 -> V_43 ) )
goto V_44;
for ( V_17 = 0 ; V_17 < V_7 -> V_38 ; V_17 ++ ) {
V_13 [ V_17 ] . V_7 = V_7 ;
V_13 [ V_17 ] . V_45 = V_17 ;
V_7 -> V_46 [ V_17 ] = F_13 ( V_7 -> V_19 ,
V_47 ,
F_1 ,
( void * ) & V_13 [ V_17 ] ,
V_48 , V_17 ) ;
if ( F_12 ( V_7 -> V_46 [ V_17 ] ) )
goto V_49;
V_7 -> V_50 [ V_17 ] = F_13 ( V_7 -> V_19 ,
NULL , F_1 ,
( void * ) & V_13 [ V_17 ] ,
V_51 , V_17 ) ;
if ( F_12 ( V_7 -> V_50 [ V_17 ] ) )
goto V_49;
if ( F_14 ( V_7 -> V_46 [ V_17 ] , V_52 ) )
goto V_49;
F_15 ( & V_7 -> V_53 [ V_17 ] ,
V_54 ,
( unsigned long ) & V_13 [ V_17 ] ) ;
}
V_7 -> V_55 = F_16 ( V_7 -> V_43 , V_56 |
V_57 |
V_58 ) ;
if ( F_12 ( V_7 -> V_55 ) )
goto V_59;
F_17 ( & V_7 -> V_60 , V_7 -> V_19 ,
F_4 ) ;
if ( F_18 ( & V_7 -> V_60 ) )
goto V_61;
return 0 ;
V_61:
F_19 ( V_7 -> V_55 ) ;
V_59:
for ( V_18 = 0 ; V_18 < V_7 -> V_38 ; V_18 ++ )
F_20 ( & V_7 -> V_53 [ V_18 ] ) ;
V_49:
for ( V_18 = 0 ; V_18 < V_17 ; V_18 ++ ) {
if ( V_7 -> V_50 [ V_18 ] )
F_21 ( V_7 -> V_50 [ V_18 ] ) ;
if ( V_7 -> V_46 [ V_18 ] )
F_21 ( V_7 -> V_46 [ V_18 ] ) ;
}
F_22 ( V_7 -> V_43 ) ;
V_44:
F_23 ( V_7 -> V_13 ) ;
V_42:
F_2 ( L_9 ) ;
return - 1 ;
}
static void F_24 ( struct V_11 * V_7 )
{
int V_17 ;
F_25 ( V_7 -> V_55 == NULL ) ;
for ( V_17 = 0 ; V_17 < V_7 -> V_38 ; V_17 ++ ) {
F_20 ( & V_7 -> V_53 [ V_17 ] ) ;
( void ) F_21 ( V_7 -> V_50 [ V_17 ] ) ;
( void ) F_21 ( V_7 -> V_46 [ V_17 ] ) ;
V_7 -> V_50 [ V_17 ] = NULL ;
V_7 -> V_46 [ V_17 ] = NULL ;
}
( void ) F_26 ( & V_7 -> V_60 ) ;
( void ) F_19 ( V_7 -> V_55 ) ;
( void ) F_22 ( V_7 -> V_43 ) ;
F_23 ( V_7 -> V_13 ) ;
V_7 -> V_55 = NULL ;
V_7 -> V_43 = NULL ;
}
int V_25 ( struct V_62 * V_63 , unsigned V_64 )
{
struct V_11 * V_7 = V_63 -> V_7 ;
struct V_65 V_66 ;
int V_16 = - V_67 ;
V_63 -> V_68 . V_69 = F_10 ( sizeof( * V_63 -> V_68 . V_69 ) +
( sizeof( V_70 ) * ( V_71 + 1 ) ) ,
V_41 ) ;
if ( ! V_63 -> V_68 . V_69 )
return V_16 ;
V_63 -> V_68 . V_69 -> V_72 = ( V_70 * ) ( V_63 -> V_68 . V_69 + 1 ) ;
V_66 . V_73 = V_74 ;
V_66 . V_75 = V_71 + 1 ;
V_66 . V_76 = V_64 * 2 ;
V_66 . V_77 = V_64 ;
V_66 . V_78 = 0 ;
V_66 . V_79 = NULL ;
V_66 . V_80 = ( V_56 |
V_57 |
V_58 ) ;
V_63 -> V_68 . V_81 = F_27 ( V_7 -> V_43 , & V_66 ) ;
if ( ! F_12 ( V_63 -> V_68 . V_81 ) )
return 0 ;
F_23 ( V_63 -> V_68 . V_69 ) ;
V_63 -> V_68 . V_69 = NULL ;
V_16 = F_28 ( V_63 -> V_68 . V_81 ) ;
V_63 -> V_68 . V_81 = NULL ;
if ( V_16 != - V_82 ) {
F_2 ( L_10 , V_16 ) ;
return V_16 ;
} else {
F_29 ( L_11 ) ;
return 0 ;
}
}
void V_27 ( struct V_62 * V_63 )
{
F_8 ( L_12 ,
V_63 , V_63 -> V_68 . V_81 ) ;
if ( V_63 -> V_68 . V_81 != NULL )
F_30 ( V_63 -> V_68 . V_81 ) ;
V_63 -> V_68 . V_81 = NULL ;
F_23 ( V_63 -> V_68 . V_69 ) ;
V_63 -> V_68 . V_69 = NULL ;
}
static int
F_31 ( struct V_19 * V_19 , struct V_83 * V_43 ,
bool V_84 , struct V_85 * V_86 )
{
int V_16 ;
V_86 -> V_87 = F_32 ( V_19 ,
V_71 + 1 ) ;
if ( F_12 ( V_86 -> V_87 ) ) {
V_16 = F_28 ( V_86 -> V_87 ) ;
F_2 ( L_13 ,
V_16 ) ;
return F_28 ( V_86 -> V_87 ) ;
}
V_86 -> V_88 = F_33 ( V_43 , V_71 + 1 ) ;
if ( F_12 ( V_86 -> V_88 ) ) {
V_16 = F_28 ( V_86 -> V_88 ) ;
F_2 ( L_14 , V_16 ) ;
goto V_89;
}
V_86 -> V_90 |= V_91 ;
if ( V_84 ) {
struct V_92 V_93 = { 0 } ;
struct V_94 * V_95 = NULL ;
V_86 -> V_95 = F_34 ( sizeof( * V_86 -> V_95 ) , V_41 ) ;
if ( ! V_86 -> V_95 ) {
F_2 ( L_15 ) ;
V_16 = - V_67 ;
goto V_96;
}
V_95 = V_86 -> V_95 ;
V_95 -> V_97 = F_32 ( V_19 ,
V_71 ) ;
if ( F_12 ( V_95 -> V_97 ) ) {
V_16 = F_28 ( V_95 -> V_97 ) ;
F_2 ( L_16 ,
V_16 ) ;
goto V_98;
}
V_95 -> V_99 = F_33 ( V_43 ,
V_71 + 1 ) ;
if ( F_12 ( V_95 -> V_99 ) ) {
V_16 = F_28 ( V_95 -> V_99 ) ;
F_2 ( L_17 ,
V_16 ) ;
goto V_100;
}
V_86 -> V_90 |= V_101 ;
V_93 . V_102 = 2 ;
V_93 . V_103 |= V_104 ;
V_95 -> V_105 = F_35 ( V_43 , & V_93 ) ;
if ( F_12 ( V_95 -> V_105 ) ) {
V_16 = F_28 ( V_95 -> V_105 ) ;
F_2 ( L_18 ,
V_16 ) ;
goto V_106;
}
V_86 -> V_90 |= V_107 ;
}
V_86 -> V_90 &= ~ V_108 ;
F_36 ( L_19 ,
V_86 , V_86 -> V_87 -> V_109 ) ;
return 0 ;
V_106:
F_19 ( V_86 -> V_95 -> V_99 ) ;
V_100:
F_37 ( V_86 -> V_95 -> V_97 ) ;
V_98:
F_23 ( V_86 -> V_95 ) ;
V_96:
F_19 ( V_86 -> V_88 ) ;
V_89:
F_37 ( V_86 -> V_87 ) ;
return V_16 ;
}
int V_34 ( struct V_62 * V_63 , unsigned V_64 )
{
struct V_11 * V_7 = V_63 -> V_7 ;
struct V_85 * V_86 ;
int V_17 , V_16 ;
F_38 ( & V_63 -> V_110 . V_81 ) ;
V_63 -> V_110 . V_76 = 0 ;
for ( V_17 = 0 ; V_17 < V_64 ; V_17 ++ ) {
V_86 = F_34 ( sizeof( * V_86 ) , V_41 ) ;
if ( ! V_86 ) {
F_2 ( L_20 ) ;
V_16 = - V_67 ;
goto V_111;
}
V_16 = F_31 ( V_7 -> V_19 , V_7 -> V_43 ,
V_63 -> V_112 , V_86 ) ;
if ( V_16 ) {
F_2 ( L_21 ,
V_16 ) ;
F_23 ( V_86 ) ;
goto V_111;
}
F_39 ( & V_86 -> V_113 , & V_63 -> V_110 . V_81 ) ;
V_63 -> V_110 . V_76 ++ ;
}
return 0 ;
V_111:
V_35 ( V_63 ) ;
return V_16 ;
}
void V_35 ( struct V_62 * V_63 )
{
struct V_85 * V_86 , * V_114 ;
int V_17 = 0 ;
if ( F_40 ( & V_63 -> V_110 . V_81 ) )
return;
F_8 ( L_22 , V_63 ) ;
F_41 (desc, tmp, &ib_conn->fastreg.pool, list) {
F_42 ( & V_86 -> V_113 ) ;
F_37 ( V_86 -> V_87 ) ;
F_19 ( V_86 -> V_88 ) ;
if ( V_86 -> V_95 ) {
F_37 ( V_86 -> V_95 -> V_97 ) ;
F_19 ( V_86 -> V_95 -> V_99 ) ;
F_43 ( V_86 -> V_95 -> V_105 ) ;
F_23 ( V_86 -> V_95 ) ;
}
F_23 ( V_86 ) ;
++ V_17 ;
}
if ( V_17 < V_63 -> V_110 . V_76 )
F_29 ( L_23 ,
V_63 -> V_110 . V_76 - V_17 ) ;
}
static int F_44 ( struct V_62 * V_63 )
{
struct V_11 * V_7 ;
struct V_115 V_116 ;
int V_16 = - V_67 ;
int V_117 , V_118 = 0 ;
F_25 ( V_63 -> V_7 == NULL ) ;
V_7 = V_63 -> V_7 ;
memset ( & V_116 , 0 , sizeof V_116 ) ;
F_45 ( & V_119 . V_120 ) ;
for ( V_117 = 0 ; V_117 < V_7 -> V_38 ; V_117 ++ )
if ( V_7 -> V_121 [ V_117 ] <
V_7 -> V_121 [ V_118 ] )
V_118 = V_117 ;
V_7 -> V_121 [ V_118 ] ++ ;
F_46 ( & V_119 . V_120 ) ;
F_8 ( L_24 , V_118 , V_63 ) ;
V_116 . V_60 = F_3 ;
V_116 . V_122 = ( void * ) V_63 ;
V_116 . V_123 = V_7 -> V_50 [ V_118 ] ;
V_116 . V_124 = V_7 -> V_46 [ V_118 ] ;
V_116 . V_125 . V_126 = V_127 ;
V_116 . V_125 . V_128 = 2 ;
V_116 . V_125 . V_129 = 1 ;
V_116 . V_130 = V_131 ;
V_116 . V_132 = V_133 ;
if ( V_63 -> V_112 ) {
V_116 . V_125 . V_134 = V_135 ;
V_116 . V_136 |= V_137 ;
} else {
V_116 . V_125 . V_134 = V_138 ;
}
V_16 = F_47 ( V_63 -> V_139 , V_7 -> V_43 , & V_116 ) ;
if ( V_16 )
goto V_140;
V_63 -> V_141 = V_63 -> V_139 -> V_141 ;
F_8 ( L_25 ,
V_63 , V_63 -> V_139 ,
V_63 -> V_139 -> V_141 ) ;
return V_16 ;
V_140:
F_2 ( L_26 , V_16 ) ;
return V_16 ;
}
static int F_48 ( struct V_62 * V_63 )
{
int V_45 ;
F_25 ( V_63 == NULL ) ;
F_8 ( L_27 ,
V_63 , V_63 -> V_139 ,
V_63 -> V_141 ) ;
if ( V_63 -> V_141 != NULL ) {
V_45 = ( (struct V_12 * ) V_63 -> V_141 -> V_124 -> V_142 ) -> V_45 ;
V_63 -> V_7 -> V_121 [ V_45 ] -- ;
F_49 ( V_63 -> V_139 ) ;
}
V_63 -> V_141 = NULL ;
return 0 ;
}
static
struct V_11 * F_50 ( struct V_143 * V_139 )
{
struct V_11 * V_7 ;
F_45 ( & V_119 . V_144 ) ;
F_51 (device, &ig.device_list, ig_list)
if ( V_7 -> V_19 -> V_145 == V_139 -> V_7 -> V_145 )
goto V_146;
V_7 = F_34 ( sizeof *V_7 , V_41 ) ;
if ( V_7 == NULL )
goto V_147;
V_7 -> V_19 = V_139 -> V_7 ;
if ( F_5 ( V_7 ) ) {
F_23 ( V_7 ) ;
V_7 = NULL ;
goto V_147;
}
F_52 ( & V_7 -> V_148 , & V_119 . V_149 ) ;
V_146:
V_7 -> V_150 ++ ;
V_147:
F_46 ( & V_119 . V_144 ) ;
return V_7 ;
}
static void F_53 ( struct V_11 * V_7 )
{
F_45 ( & V_119 . V_144 ) ;
V_7 -> V_150 -- ;
F_8 ( L_28 , V_7 , V_7 -> V_150 ) ;
if ( ! V_7 -> V_150 ) {
F_24 ( V_7 ) ;
F_42 ( & V_7 -> V_148 ) ;
F_23 ( V_7 ) ;
}
F_46 ( & V_119 . V_144 ) ;
}
static int F_54 ( struct V_62 * V_63 ,
enum V_151 V_152 ,
enum V_151 V_153 )
{
int V_16 ;
F_55 ( & V_63 -> V_154 ) ;
if ( ( V_16 = ( V_63 -> V_155 == V_152 ) ) )
V_63 -> V_155 = V_153 ;
F_56 ( & V_63 -> V_154 ) ;
return V_16 ;
}
void F_57 ( struct V_156 * V_157 )
{
struct V_62 * V_63 ;
V_63 = F_58 ( V_157 , struct V_62 , V_158 ) ;
F_59 ( & V_63 -> V_159 ) ;
F_60 ( V_63 -> V_160 ,
V_63 -> V_155 == V_161 ) ;
F_61 ( V_63 ) ;
}
void F_61 ( struct V_62 * V_63 )
{
struct V_11 * V_7 = V_63 -> V_7 ;
F_25 ( V_63 -> V_155 == V_162 ) ;
F_45 ( & V_119 . V_120 ) ;
F_42 ( & V_63 -> V_163 ) ;
F_46 ( & V_119 . V_120 ) ;
F_62 ( V_63 ) ;
F_48 ( V_63 ) ;
V_63 -> V_7 = NULL ;
if ( V_7 != NULL )
F_53 ( V_7 ) ;
if ( V_63 -> V_139 != NULL ) {
F_63 ( V_63 -> V_139 ) ;
V_63 -> V_139 = NULL ;
}
F_64 ( V_63 -> V_164 ) ;
}
void F_65 ( struct V_62 * V_63 )
{
int V_111 = 0 ;
F_54 ( V_63 , V_162 , V_165 ) ;
V_111 = F_66 ( V_63 -> V_139 ) ;
if ( V_111 )
F_2 ( L_29 ,
V_63 , V_111 ) ;
}
static void F_67 ( struct V_143 * V_139 )
{
struct V_62 * V_63 ;
V_63 = (struct V_62 * ) V_139 -> V_3 ;
V_63 -> V_155 = V_161 ;
F_68 ( & V_63 -> V_160 ) ;
}
static void F_69 ( struct V_143 * V_139 )
{
struct V_11 * V_7 ;
struct V_62 * V_63 ;
int V_16 ;
V_7 = F_50 ( V_139 ) ;
if ( ! V_7 ) {
F_2 ( L_30 ) ;
F_67 ( V_139 ) ;
return;
}
V_63 = (struct V_62 * ) V_139 -> V_3 ;
V_63 -> V_7 = V_7 ;
if ( V_166 ) {
if ( ! ( V_7 -> V_15 . V_32 &
V_167 ) ) {
F_29 ( L_31
L_32 ,
V_63 -> V_7 -> V_19 -> V_8 ) ;
V_63 -> V_112 = false ;
} else {
V_63 -> V_112 = true ;
}
}
V_16 = F_70 ( V_139 , 1000 ) ;
if ( V_16 ) {
F_2 ( L_33 , V_16 ) ;
F_67 ( V_139 ) ;
return;
}
}
static void F_71 ( struct V_143 * V_139 )
{
struct V_168 V_169 ;
int V_16 ;
struct V_170 V_171 ;
V_16 = F_44 ( (struct V_62 * ) V_139 -> V_3 ) ;
if ( V_16 )
goto V_172;
memset ( & V_169 , 0 , sizeof V_169 ) ;
V_169 . V_173 = 4 ;
V_169 . V_174 = 1 ;
V_169 . V_175 = 7 ;
V_169 . V_176 = 6 ;
memset ( & V_171 , 0 , sizeof( V_171 ) ) ;
V_171 . V_103 = ( V_177 |
V_178 ) ;
V_169 . V_179 = ( void * ) & V_171 ;
V_169 . V_180 = sizeof( struct V_170 ) ;
V_16 = F_72 ( V_139 , & V_169 ) ;
if ( V_16 ) {
F_2 ( L_34 , V_16 ) ;
goto V_172;
}
return;
V_172:
F_67 ( V_139 ) ;
}
static void F_73 ( struct V_143 * V_139 )
{
struct V_62 * V_63 ;
struct V_181 V_182 ;
struct V_115 V_116 ;
( void ) F_74 ( V_139 -> V_141 , & V_182 , ~ 0 , & V_116 ) ;
F_8 ( L_35 , V_182 . V_183 , V_139 -> V_141 -> V_184 ) ;
V_63 = (struct V_62 * ) V_139 -> V_3 ;
if ( F_54 ( V_63 , V_185 , V_162 ) )
F_68 ( & V_63 -> V_160 ) ;
}
static void F_75 ( struct V_143 * V_139 )
{
struct V_62 * V_63 ;
V_63 = (struct V_62 * ) V_139 -> V_3 ;
if ( F_54 ( V_63 , V_162 ,
V_165 ) ) {
if ( V_63 -> V_186 )
F_76 ( V_63 -> V_186 , V_187 ) ;
else
F_2 ( L_36 ) ;
}
if ( V_63 -> V_188 == 0 &&
( F_77 ( & V_63 -> V_189 ) == 0 ) ) {
V_63 -> V_155 = V_161 ;
F_68 ( & V_63 -> V_160 ) ;
}
}
static int F_78 ( struct V_143 * V_139 , struct V_190 * V_4 )
{
F_8 ( L_37 ,
V_4 -> V_4 , V_4 -> V_191 , V_139 -> V_3 , V_139 ) ;
switch ( V_4 -> V_4 ) {
case V_192 :
F_69 ( V_139 ) ;
break;
case V_193 :
F_71 ( V_139 ) ;
break;
case V_194 :
F_73 ( V_139 ) ;
break;
case V_195 :
case V_196 :
case V_197 :
case V_198 :
case V_199 :
F_67 ( V_139 ) ;
break;
case V_200 :
case V_201 :
case V_202 :
F_75 ( V_139 ) ;
break;
default:
F_2 ( L_38 , V_4 -> V_4 ) ;
break;
}
return 0 ;
}
void F_79 ( struct V_62 * V_63 )
{
V_63 -> V_155 = V_203 ;
F_80 ( & V_63 -> V_160 ) ;
V_63 -> V_188 = 0 ;
F_81 ( & V_63 -> V_189 , 0 ) ;
F_82 ( & V_63 -> V_159 ) ;
F_38 ( & V_63 -> V_163 ) ;
F_83 ( & V_63 -> V_154 ) ;
}
int F_84 ( struct V_62 * V_63 ,
struct V_204 * V_205 ,
struct V_204 * V_206 ,
int V_207 )
{
struct V_208 * V_209 , * V_210 ;
int V_111 = 0 ;
sprintf ( V_63 -> V_8 , L_39 ,
& V_206 -> V_211 . V_212 , V_206 -> V_213 ) ;
V_63 -> V_7 = NULL ;
F_8 ( L_40 ,
& V_206 -> V_211 , V_206 -> V_213 ) ;
V_63 -> V_155 = V_185 ;
V_63 -> V_139 = F_85 ( F_78 ,
( void * ) V_63 ,
V_214 , V_133 ) ;
if ( F_12 ( V_63 -> V_139 ) ) {
V_111 = F_28 ( V_63 -> V_139 ) ;
F_2 ( L_41 , V_111 ) ;
goto V_215;
}
V_209 = (struct V_208 * ) V_205 ;
V_210 = (struct V_208 * ) V_206 ;
V_111 = F_86 ( V_63 -> V_139 , V_209 , V_210 , 1000 ) ;
if ( V_111 ) {
F_2 ( L_42 , V_111 ) ;
goto V_216;
}
if ( ! V_207 ) {
F_60 ( V_63 -> V_160 ,
( V_63 -> V_155 != V_185 ) ) ;
if ( V_63 -> V_155 != V_162 ) {
V_111 = - V_217 ;
goto V_218;
}
}
F_45 ( & V_119 . V_120 ) ;
F_52 ( & V_63 -> V_163 , & V_119 . V_219 ) ;
F_46 ( & V_119 . V_120 ) ;
return 0 ;
V_215:
V_63 -> V_139 = NULL ;
V_216:
V_63 -> V_155 = V_161 ;
V_218:
F_61 ( V_63 ) ;
return V_111 ;
}
int F_87 ( struct V_62 * V_63 ,
struct V_220 * V_69 ,
struct V_221 * V_222 )
{
struct V_223 * V_224 ;
V_70 V_225 ;
V_70 * V_109 ;
int V_191 ;
V_109 = V_69 -> V_72 ;
V_225 = V_109 [ 0 ] ;
V_224 = F_88 ( V_63 -> V_68 . V_81 ,
V_109 ,
V_69 -> V_226 ,
V_225 ) ;
if ( F_12 ( V_224 ) ) {
V_191 = ( int ) F_28 ( V_224 ) ;
F_2 ( L_43 , V_191 ) ;
return V_191 ;
}
V_222 -> V_227 = V_224 -> V_68 -> V_227 ;
V_222 -> V_228 = V_224 -> V_68 -> V_228 ;
V_222 -> V_229 = V_69 -> V_226 * V_230 ;
V_222 -> V_231 = V_225 ;
V_222 -> V_232 = 1 ;
V_222 -> V_233 = ( void * ) V_224 ;
V_222 -> V_231 += V_69 -> V_234 ;
V_222 -> V_229 = V_69 -> V_235 ;
F_36 ( L_44
L_45
L_46 ,
V_69 , V_69 -> V_226 ,
( unsigned long ) V_69 -> V_72 [ 0 ] ,
( unsigned long ) V_69 -> V_235 ,
( unsigned int ) V_222 -> V_227 , V_222 -> V_233 ,
( unsigned long ) V_222 -> V_231 , ( unsigned long ) V_222 -> V_229 ) ;
return 0 ;
}
void V_31 ( struct V_236 * V_237 ,
enum V_238 V_239 )
{
struct V_221 * V_240 = & V_237 -> V_241 [ V_239 ] . V_240 ;
int V_16 ;
if ( ! V_240 -> V_232 )
return;
F_36 ( L_47 , V_240 -> V_233 ) ;
V_16 = F_89 ( (struct V_223 * ) V_240 -> V_233 ) ;
if ( V_16 )
F_2 ( L_48 , V_16 ) ;
V_240 -> V_233 = NULL ;
}
void V_37 ( struct V_236 * V_237 ,
enum V_238 V_239 )
{
struct V_221 * V_240 = & V_237 -> V_241 [ V_239 ] . V_240 ;
struct V_62 * V_63 = V_237 -> V_63 ;
struct V_85 * V_86 = V_240 -> V_233 ;
if ( ! V_240 -> V_232 )
return;
V_240 -> V_233 = NULL ;
V_240 -> V_232 = 0 ;
F_55 ( & V_63 -> V_154 ) ;
F_39 ( & V_86 -> V_113 , & V_63 -> V_110 . V_81 ) ;
F_56 ( & V_63 -> V_154 ) ;
}
int F_90 ( struct V_62 * V_63 )
{
struct V_242 V_243 , * V_244 ;
struct V_245 V_246 ;
int V_247 ;
V_246 . V_248 = V_63 -> V_249 ;
V_246 . V_226 = V_250 ;
V_246 . V_227 = V_63 -> V_7 -> V_55 -> V_227 ;
V_243 . V_251 = ( unsigned long ) V_63 -> V_252 ;
V_243 . V_253 = & V_246 ;
V_243 . V_254 = 1 ;
V_243 . V_255 = NULL ;
V_63 -> V_188 ++ ;
V_247 = F_91 ( V_63 -> V_141 , & V_243 , & V_244 ) ;
if ( V_247 ) {
F_2 ( L_49 , V_247 ) ;
V_63 -> V_188 -- ;
}
return V_247 ;
}
int F_92 ( struct V_62 * V_63 , int V_256 )
{
struct V_242 * V_243 , * V_244 ;
int V_17 , V_247 ;
unsigned int V_257 = V_63 -> V_258 ;
struct V_259 * V_260 ;
for ( V_243 = V_63 -> V_243 , V_17 = 0 ; V_17 < V_256 ; V_17 ++ , V_243 ++ ) {
V_260 = & V_63 -> V_261 [ V_257 ] ;
V_243 -> V_251 = ( unsigned long ) V_260 ;
V_243 -> V_253 = & V_260 -> V_262 ;
V_243 -> V_254 = 1 ;
V_243 -> V_255 = V_243 + 1 ;
V_257 = ( V_257 + 1 ) & V_63 -> V_263 ;
}
V_243 -- ;
V_243 -> V_255 = NULL ;
V_63 -> V_188 += V_256 ;
V_247 = F_91 ( V_63 -> V_141 , V_63 -> V_243 , & V_244 ) ;
if ( V_247 ) {
F_2 ( L_49 , V_247 ) ;
V_63 -> V_188 -= V_256 ;
} else
V_63 -> V_258 = V_257 ;
return V_247 ;
}
int F_93 ( struct V_62 * V_63 , struct V_264 * V_265 )
{
int V_247 ;
struct V_266 V_267 , * V_268 ;
F_94 ( V_63 -> V_7 -> V_19 ,
V_265 -> V_269 , V_270 , V_271 ) ;
V_267 . V_255 = NULL ;
V_267 . V_251 = ( unsigned long ) V_265 ;
V_267 . V_253 = V_265 -> V_272 ;
V_267 . V_254 = V_265 -> V_254 ;
V_267 . V_273 = V_274 ;
V_267 . V_275 = V_276 ;
F_95 ( & V_63 -> V_189 ) ;
V_247 = F_96 ( V_63 -> V_141 , & V_267 , & V_268 ) ;
if ( V_247 ) {
F_2 ( L_50 , V_247 ) ;
F_97 ( & V_63 -> V_189 ) ;
}
return V_247 ;
}
static void F_98 ( struct V_264 * V_86 ,
struct V_62 * V_63 )
{
if ( V_86 && V_86 -> type == V_277 )
F_99 ( V_119 . V_278 , V_86 ) ;
if ( V_63 -> V_188 == 0 &&
F_77 ( & V_63 -> V_189 ) == 0 ) {
if ( F_54 ( V_63 , V_162 ,
V_165 ) )
F_76 ( V_63 -> V_186 ,
V_187 ) ;
V_63 -> V_155 = V_161 ;
F_68 ( & V_63 -> V_160 ) ;
}
}
static int F_100 ( struct V_11 * V_7 , int V_45 )
{
struct V_279 * V_280 = V_7 -> V_50 [ V_45 ] ;
struct V_281 V_282 ;
struct V_264 * V_265 ;
struct V_62 * V_63 ;
int V_283 = 0 ;
while ( F_101 ( V_280 , 1 , & V_282 ) == 1 ) {
V_265 = (struct V_264 * ) ( unsigned long ) V_282 . V_251 ;
V_63 = V_282 . V_141 -> V_122 ;
if ( V_282 . V_191 == V_284 ) {
if ( V_282 . V_273 == V_285 )
F_102 ( V_265 , V_63 ) ;
else
F_2 ( L_51 ,
V_285 , V_282 . V_273 ) ;
} else {
F_2 ( L_52 ,
V_282 . V_251 , V_282 . V_191 , V_282 . V_286 ) ;
if ( V_282 . V_251 != V_287 ) {
F_97 ( & V_63 -> V_189 ) ;
F_98 ( V_265 , V_63 ) ;
}
}
V_283 ++ ;
}
return V_283 ;
}
static void V_54 ( unsigned long V_288 )
{
struct V_12 * V_13 = (struct V_12 * ) V_288 ;
struct V_11 * V_7 = V_13 -> V_7 ;
int V_45 = V_13 -> V_45 ;
struct V_279 * V_280 = V_7 -> V_46 [ V_45 ] ;
struct V_281 V_282 ;
struct V_259 * V_86 ;
unsigned long V_289 ;
struct V_62 * V_63 ;
int V_283 , V_290 = 0 ;
V_283 = F_100 ( V_7 , V_45 ) ;
while ( F_101 ( V_280 , 1 , & V_282 ) == 1 ) {
V_86 = (struct V_259 * ) ( unsigned long ) V_282 . V_251 ;
F_25 ( V_86 == NULL ) ;
V_63 = V_282 . V_141 -> V_122 ;
if ( V_282 . V_191 == V_284 ) {
if ( V_282 . V_273 == V_291 ) {
V_289 = ( unsigned long ) V_282 . V_292 ;
F_103 ( V_86 , V_289 , V_63 ) ;
} else
F_2 ( L_51 ,
V_291 , V_282 . V_273 ) ;
} else {
if ( V_282 . V_191 != V_293 )
F_2 ( L_53 ,
V_282 . V_251 , V_282 . V_191 , V_282 . V_286 ) ;
V_63 -> V_188 -- ;
F_98 ( NULL , V_63 ) ;
}
V_290 ++ ;
if ( ! ( V_290 & 63 ) )
V_283 += F_100 ( V_7 , V_45 ) ;
}
F_14 ( V_280 , V_52 ) ;
F_36 ( L_54 , V_290 , V_283 ) ;
}
static void V_47 ( struct V_279 * V_280 , void * V_142 )
{
struct V_12 * V_13 = (struct V_12 * ) V_142 ;
struct V_11 * V_7 = V_13 -> V_7 ;
int V_45 = V_13 -> V_45 ;
F_104 ( & V_7 -> V_53 [ V_45 ] ) ;
}
T_1 F_105 ( struct V_236 * V_237 ,
enum V_238 V_239 , T_2 * V_294 )
{
struct V_221 * V_240 = & V_237 -> V_241 [ V_239 ] . V_240 ;
struct V_85 * V_86 = V_240 -> V_233 ;
unsigned long V_295 = V_237 -> V_296 -> V_7 -> V_295 ;
struct V_297 V_298 ;
int V_16 ;
if ( V_86 && V_86 -> V_90 & V_108 ) {
V_86 -> V_90 &= ~ V_108 ;
V_16 = F_106 ( V_86 -> V_95 -> V_105 ,
V_299 , & V_298 ) ;
if ( V_16 ) {
F_107 ( L_55 , V_16 ) ;
goto V_111;
}
if ( V_298 . V_300 & V_299 ) {
T_2 V_301 = V_298 . V_302 . V_303 ;
F_108 ( V_301 , V_295 + 8 ) ;
* V_294 = F_109 ( V_237 -> V_296 ) + V_301 ;
F_107 ( L_56
L_57 ,
V_298 . V_302 . V_304 ,
( unsigned long long ) * V_294 ,
V_298 . V_302 . V_305 ,
V_298 . V_302 . V_306 ) ;
switch ( V_298 . V_302 . V_304 ) {
case V_307 :
return 0x1 ;
case V_308 :
return 0x3 ;
case V_309 :
return 0x2 ;
}
}
}
return 0 ;
V_111:
return 0x1 ;
}
