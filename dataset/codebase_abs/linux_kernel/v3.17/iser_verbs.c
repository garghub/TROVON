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
int V_16 , V_17 ;
V_16 = F_6 ( V_7 -> V_18 , V_15 ) ;
if ( V_16 ) {
F_7 ( L_4 , V_7 -> V_18 -> V_8 ) ;
return V_16 ;
}
if ( V_7 -> V_18 -> V_19 && V_7 -> V_18 -> V_20 &&
V_7 -> V_18 -> V_21 && V_7 -> V_18 -> V_22 ) {
F_8 ( L_5 ) ;
V_7 -> V_23 = V_24 ;
V_7 -> V_25 = V_26 ;
V_7 -> V_27 = V_28 ;
V_7 -> V_29 = V_30 ;
} else
if ( V_15 -> V_31 & V_32 ) {
F_8 ( L_6 ) ;
V_7 -> V_23 = V_33 ;
V_7 -> V_25 = V_34 ;
V_7 -> V_27 = V_35 ;
V_7 -> V_29 = V_36 ;
} else {
F_2 ( L_7 ) ;
return - 1 ;
}
V_7 -> V_37 = F_9 ( V_38 , V_7 -> V_18 -> V_39 ) ;
F_8 ( L_8 ,
V_7 -> V_37 , V_7 -> V_18 -> V_8 ,
V_7 -> V_18 -> V_39 ) ;
V_7 -> V_13 = F_10 ( sizeof( struct V_12 ) * V_7 -> V_37 ,
V_40 ) ;
if ( V_7 -> V_13 == NULL )
goto V_41;
V_13 = V_7 -> V_13 ;
V_7 -> V_42 = F_11 ( V_7 -> V_18 ) ;
if ( F_12 ( V_7 -> V_42 ) )
goto V_43;
for ( V_17 = 0 ; V_17 < V_7 -> V_37 ; V_17 ++ ) {
V_13 [ V_17 ] . V_7 = V_7 ;
V_13 [ V_17 ] . V_44 = V_17 ;
V_7 -> V_45 [ V_17 ] = F_13 ( V_7 -> V_18 ,
V_46 ,
F_1 ,
( void * ) & V_13 [ V_17 ] ,
V_47 , V_17 ) ;
if ( F_12 ( V_7 -> V_45 [ V_17 ] ) ) {
V_7 -> V_45 [ V_17 ] = NULL ;
goto V_48;
}
V_7 -> V_49 [ V_17 ] = F_13 ( V_7 -> V_18 ,
NULL , F_1 ,
( void * ) & V_13 [ V_17 ] ,
V_50 , V_17 ) ;
if ( F_12 ( V_7 -> V_49 [ V_17 ] ) ) {
V_7 -> V_49 [ V_17 ] = NULL ;
goto V_48;
}
if ( F_14 ( V_7 -> V_45 [ V_17 ] , V_51 ) )
goto V_48;
F_15 ( & V_7 -> V_52 [ V_17 ] ,
V_53 ,
( unsigned long ) & V_13 [ V_17 ] ) ;
}
V_7 -> V_54 = F_16 ( V_7 -> V_42 , V_55 |
V_56 |
V_57 ) ;
if ( F_12 ( V_7 -> V_54 ) )
goto V_58;
F_17 ( & V_7 -> V_59 , V_7 -> V_18 ,
F_4 ) ;
if ( F_18 ( & V_7 -> V_59 ) )
goto V_60;
return 0 ;
V_60:
F_19 ( V_7 -> V_54 ) ;
V_58:
for ( V_17 = 0 ; V_17 < V_7 -> V_37 ; V_17 ++ )
F_20 ( & V_7 -> V_52 [ V_17 ] ) ;
V_48:
for ( V_17 = 0 ; V_17 < V_7 -> V_37 ; V_17 ++ ) {
if ( V_7 -> V_49 [ V_17 ] )
F_21 ( V_7 -> V_49 [ V_17 ] ) ;
if ( V_7 -> V_45 [ V_17 ] )
F_21 ( V_7 -> V_45 [ V_17 ] ) ;
}
F_22 ( V_7 -> V_42 ) ;
V_43:
F_23 ( V_7 -> V_13 ) ;
V_41:
F_2 ( L_9 ) ;
return - 1 ;
}
static void F_24 ( struct V_11 * V_7 )
{
int V_17 ;
F_25 ( V_7 -> V_54 == NULL ) ;
for ( V_17 = 0 ; V_17 < V_7 -> V_37 ; V_17 ++ ) {
F_20 ( & V_7 -> V_52 [ V_17 ] ) ;
( void ) F_21 ( V_7 -> V_49 [ V_17 ] ) ;
( void ) F_21 ( V_7 -> V_45 [ V_17 ] ) ;
V_7 -> V_49 [ V_17 ] = NULL ;
V_7 -> V_45 [ V_17 ] = NULL ;
}
( void ) F_26 ( & V_7 -> V_59 ) ;
( void ) F_19 ( V_7 -> V_54 ) ;
( void ) F_22 ( V_7 -> V_42 ) ;
F_23 ( V_7 -> V_13 ) ;
V_7 -> V_54 = NULL ;
V_7 -> V_42 = NULL ;
}
int V_24 ( struct V_61 * V_62 , unsigned V_63 )
{
struct V_11 * V_7 = V_62 -> V_7 ;
struct V_64 V_65 ;
int V_16 = - V_66 ;
V_62 -> V_67 . V_68 = F_10 ( sizeof( * V_62 -> V_67 . V_68 ) +
( sizeof( V_69 ) * ( V_70 + 1 ) ) ,
V_40 ) ;
if ( ! V_62 -> V_67 . V_68 )
return V_16 ;
V_62 -> V_67 . V_68 -> V_71 = ( V_69 * ) ( V_62 -> V_67 . V_68 + 1 ) ;
V_65 . V_72 = V_73 ;
V_65 . V_74 = V_70 + 1 ;
V_65 . V_75 = V_63 * 2 ;
V_65 . V_76 = V_63 ;
V_65 . V_77 = 0 ;
V_65 . V_78 = NULL ;
V_65 . V_79 = ( V_55 |
V_56 |
V_57 ) ;
V_62 -> V_67 . V_80 = F_27 ( V_7 -> V_42 , & V_65 ) ;
if ( ! F_12 ( V_62 -> V_67 . V_80 ) )
return 0 ;
F_23 ( V_62 -> V_67 . V_68 ) ;
V_62 -> V_67 . V_68 = NULL ;
V_16 = F_28 ( V_62 -> V_67 . V_80 ) ;
V_62 -> V_67 . V_80 = NULL ;
if ( V_16 != - V_81 ) {
F_2 ( L_10 , V_16 ) ;
return V_16 ;
} else {
F_29 ( L_11 ) ;
return 0 ;
}
}
void V_26 ( struct V_61 * V_62 )
{
F_8 ( L_12 ,
V_62 , V_62 -> V_67 . V_80 ) ;
if ( V_62 -> V_67 . V_80 != NULL )
F_30 ( V_62 -> V_67 . V_80 ) ;
V_62 -> V_67 . V_80 = NULL ;
F_23 ( V_62 -> V_67 . V_68 ) ;
V_62 -> V_67 . V_68 = NULL ;
}
static int
F_31 ( struct V_18 * V_18 , struct V_82 * V_42 ,
bool V_83 , struct V_84 * V_85 )
{
int V_16 ;
V_85 -> V_86 = F_32 ( V_18 ,
V_70 + 1 ) ;
if ( F_12 ( V_85 -> V_86 ) ) {
V_16 = F_28 ( V_85 -> V_86 ) ;
F_2 ( L_13 ,
V_16 ) ;
return F_28 ( V_85 -> V_86 ) ;
}
V_85 -> V_87 = F_33 ( V_42 , V_70 + 1 ) ;
if ( F_12 ( V_85 -> V_87 ) ) {
V_16 = F_28 ( V_85 -> V_87 ) ;
F_2 ( L_14 , V_16 ) ;
goto V_88;
}
V_85 -> V_89 |= V_90 ;
if ( V_83 ) {
struct V_91 V_92 = { 0 } ;
struct V_93 * V_94 = NULL ;
V_85 -> V_94 = F_34 ( sizeof( * V_85 -> V_94 ) , V_40 ) ;
if ( ! V_85 -> V_94 ) {
F_2 ( L_15 ) ;
V_16 = - V_66 ;
goto V_95;
}
V_94 = V_85 -> V_94 ;
V_94 -> V_96 = F_32 ( V_18 ,
V_70 ) ;
if ( F_12 ( V_94 -> V_96 ) ) {
V_16 = F_28 ( V_94 -> V_96 ) ;
F_2 ( L_16 ,
V_16 ) ;
goto V_97;
}
V_94 -> V_98 = F_33 ( V_42 ,
V_70 + 1 ) ;
if ( F_12 ( V_94 -> V_98 ) ) {
V_16 = F_28 ( V_94 -> V_98 ) ;
F_2 ( L_17 ,
V_16 ) ;
goto V_99;
}
V_85 -> V_89 |= V_100 ;
V_92 . V_101 = 2 ;
V_92 . V_102 |= V_103 ;
V_94 -> V_104 = F_35 ( V_42 , & V_92 ) ;
if ( F_12 ( V_94 -> V_104 ) ) {
V_16 = F_28 ( V_94 -> V_104 ) ;
F_2 ( L_18 ,
V_16 ) ;
goto V_105;
}
V_85 -> V_89 |= V_106 ;
}
V_85 -> V_89 &= ~ V_107 ;
F_36 ( L_19 ,
V_85 , V_85 -> V_86 -> V_108 ) ;
return 0 ;
V_105:
F_19 ( V_85 -> V_94 -> V_98 ) ;
V_99:
F_37 ( V_85 -> V_94 -> V_96 ) ;
V_97:
F_23 ( V_85 -> V_94 ) ;
V_95:
F_19 ( V_85 -> V_87 ) ;
V_88:
F_37 ( V_85 -> V_86 ) ;
return V_16 ;
}
int V_33 ( struct V_61 * V_62 , unsigned V_63 )
{
struct V_11 * V_7 = V_62 -> V_7 ;
struct V_84 * V_85 ;
int V_17 , V_16 ;
F_38 ( & V_62 -> V_109 . V_80 ) ;
V_62 -> V_109 . V_75 = 0 ;
for ( V_17 = 0 ; V_17 < V_63 ; V_17 ++ ) {
V_85 = F_34 ( sizeof( * V_85 ) , V_40 ) ;
if ( ! V_85 ) {
F_2 ( L_20 ) ;
V_16 = - V_66 ;
goto V_110;
}
V_16 = F_31 ( V_7 -> V_18 , V_7 -> V_42 ,
V_62 -> V_111 , V_85 ) ;
if ( V_16 ) {
F_2 ( L_21 ,
V_16 ) ;
F_23 ( V_85 ) ;
goto V_110;
}
F_39 ( & V_85 -> V_112 , & V_62 -> V_109 . V_80 ) ;
V_62 -> V_109 . V_75 ++ ;
}
return 0 ;
V_110:
V_34 ( V_62 ) ;
return V_16 ;
}
void V_34 ( struct V_61 * V_62 )
{
struct V_84 * V_85 , * V_113 ;
int V_17 = 0 ;
if ( F_40 ( & V_62 -> V_109 . V_80 ) )
return;
F_8 ( L_22 , V_62 ) ;
F_41 (desc, tmp, &ib_conn->fastreg.pool, list) {
F_42 ( & V_85 -> V_112 ) ;
F_37 ( V_85 -> V_86 ) ;
F_19 ( V_85 -> V_87 ) ;
if ( V_85 -> V_94 ) {
F_37 ( V_85 -> V_94 -> V_96 ) ;
F_19 ( V_85 -> V_94 -> V_98 ) ;
F_43 ( V_85 -> V_94 -> V_104 ) ;
F_23 ( V_85 -> V_94 ) ;
}
F_23 ( V_85 ) ;
++ V_17 ;
}
if ( V_17 < V_62 -> V_109 . V_75 )
F_29 ( L_23 ,
V_62 -> V_109 . V_75 - V_17 ) ;
}
static int F_44 ( struct V_61 * V_62 )
{
struct V_11 * V_7 ;
struct V_114 V_115 ;
int V_16 = - V_66 ;
int V_116 , V_117 = 0 ;
F_25 ( V_62 -> V_7 == NULL ) ;
V_7 = V_62 -> V_7 ;
memset ( & V_115 , 0 , sizeof V_115 ) ;
F_45 ( & V_118 . V_119 ) ;
for ( V_116 = 0 ; V_116 < V_7 -> V_37 ; V_116 ++ )
if ( V_7 -> V_120 [ V_116 ] <
V_7 -> V_120 [ V_117 ] )
V_117 = V_116 ;
V_7 -> V_120 [ V_117 ] ++ ;
F_46 ( & V_118 . V_119 ) ;
F_8 ( L_24 , V_117 , V_62 ) ;
V_115 . V_59 = F_3 ;
V_115 . V_121 = ( void * ) V_62 ;
V_115 . V_122 = V_7 -> V_49 [ V_117 ] ;
V_115 . V_123 = V_7 -> V_45 [ V_117 ] ;
V_115 . V_124 . V_125 = V_126 ;
V_115 . V_124 . V_127 = 2 ;
V_115 . V_124 . V_128 = 1 ;
V_115 . V_129 = V_130 ;
V_115 . V_131 = V_132 ;
if ( V_62 -> V_111 ) {
V_115 . V_124 . V_133 = V_134 ;
V_115 . V_135 |= V_136 ;
} else {
V_115 . V_124 . V_133 = V_137 ;
}
V_16 = F_47 ( V_62 -> V_138 , V_7 -> V_42 , & V_115 ) ;
if ( V_16 )
goto V_139;
V_62 -> V_140 = V_62 -> V_138 -> V_140 ;
F_8 ( L_25 ,
V_62 , V_62 -> V_138 ,
V_62 -> V_138 -> V_140 ) ;
return V_16 ;
V_139:
F_2 ( L_26 , V_16 ) ;
return V_16 ;
}
static void F_48 ( struct V_61 * V_62 )
{
int V_44 ;
F_25 ( V_62 == NULL ) ;
F_8 ( L_27 ,
V_62 , V_62 -> V_138 ,
V_62 -> V_140 ) ;
if ( V_62 -> V_140 != NULL ) {
V_44 = ( (struct V_12 * ) V_62 -> V_140 -> V_123 -> V_141 ) -> V_44 ;
V_62 -> V_7 -> V_120 [ V_44 ] -- ;
F_49 ( V_62 -> V_138 ) ;
}
V_62 -> V_140 = NULL ;
}
static
struct V_11 * F_50 ( struct V_142 * V_138 )
{
struct V_11 * V_7 ;
F_45 ( & V_118 . V_143 ) ;
F_51 (device, &ig.device_list, ig_list)
if ( V_7 -> V_18 -> V_144 == V_138 -> V_7 -> V_144 )
goto V_145;
V_7 = F_34 ( sizeof *V_7 , V_40 ) ;
if ( V_7 == NULL )
goto V_146;
V_7 -> V_18 = V_138 -> V_7 ;
if ( F_5 ( V_7 ) ) {
F_23 ( V_7 ) ;
V_7 = NULL ;
goto V_146;
}
F_52 ( & V_7 -> V_147 , & V_118 . V_148 ) ;
V_145:
V_7 -> V_149 ++ ;
V_146:
F_46 ( & V_118 . V_143 ) ;
return V_7 ;
}
static void F_53 ( struct V_11 * V_7 )
{
F_45 ( & V_118 . V_143 ) ;
V_7 -> V_149 -- ;
F_8 ( L_28 , V_7 , V_7 -> V_149 ) ;
if ( ! V_7 -> V_149 ) {
F_24 ( V_7 ) ;
F_42 ( & V_7 -> V_147 ) ;
F_23 ( V_7 ) ;
}
F_46 ( & V_118 . V_143 ) ;
}
static int F_54 ( struct V_61 * V_62 ,
enum V_150 V_151 ,
enum V_150 V_152 )
{
int V_16 ;
if ( ( V_16 = ( V_62 -> V_153 == V_151 ) ) )
V_62 -> V_153 = V_152 ;
return V_16 ;
}
void F_55 ( struct V_154 * V_155 )
{
struct V_61 * V_62 ;
int V_156 ;
V_62 = F_56 ( V_155 , struct V_61 , V_157 ) ;
V_156 = F_57 ( & V_62 -> V_158 , 30 * V_159 ) ;
F_58 ( V_156 == 0 ) ;
V_156 = F_57 ( & V_62 -> V_160 , 30 * V_159 ) ;
F_58 ( V_156 == 0 ) ;
V_62 -> V_153 = V_161 ;
F_45 ( & V_62 -> V_162 ) ;
V_62 -> V_153 = V_161 ;
F_46 ( & V_62 -> V_162 ) ;
F_59 ( V_62 ) ;
}
void F_59 ( struct V_61 * V_62 )
{
struct V_11 * V_7 = V_62 -> V_7 ;
F_45 ( & V_118 . V_119 ) ;
F_42 ( & V_62 -> V_163 ) ;
F_46 ( & V_118 . V_119 ) ;
F_45 ( & V_62 -> V_162 ) ;
F_25 ( V_62 -> V_153 != V_161 ) ;
F_60 ( V_62 ) ;
F_48 ( V_62 ) ;
V_62 -> V_7 = NULL ;
if ( V_7 != NULL )
F_53 ( V_7 ) ;
F_46 ( & V_62 -> V_162 ) ;
if ( V_62 -> V_138 != NULL ) {
F_61 ( V_62 -> V_138 ) ;
V_62 -> V_138 = NULL ;
}
F_23 ( V_62 ) ;
}
void F_62 ( struct V_61 * V_62 )
{
int V_110 = 0 ;
F_54 ( V_62 , V_164 , V_165 ) ;
V_110 = F_63 ( V_62 -> V_138 ) ;
if ( V_110 )
F_2 ( L_29 ,
V_62 , V_110 ) ;
}
static void F_64 ( struct V_142 * V_138 )
{
struct V_61 * V_62 ;
V_62 = (struct V_61 * ) V_138 -> V_3 ;
V_62 -> V_153 = V_161 ;
}
static void F_65 ( struct V_142 * V_138 )
{
struct V_11 * V_7 ;
struct V_61 * V_62 ;
int V_16 ;
V_62 = (struct V_61 * ) V_138 -> V_3 ;
if ( V_62 -> V_153 != V_166 )
return;
V_7 = F_50 ( V_138 ) ;
if ( ! V_7 ) {
F_2 ( L_30 ) ;
F_64 ( V_138 ) ;
return;
}
V_62 -> V_7 = V_7 ;
if ( V_167 ) {
if ( ! ( V_7 -> V_15 . V_31 &
V_168 ) ) {
F_29 ( L_31
L_32 ,
V_62 -> V_7 -> V_18 -> V_8 ) ;
V_62 -> V_111 = false ;
} else {
V_62 -> V_111 = true ;
}
}
V_16 = F_66 ( V_138 , 1000 ) ;
if ( V_16 ) {
F_2 ( L_33 , V_16 ) ;
F_64 ( V_138 ) ;
return;
}
}
static void F_67 ( struct V_142 * V_138 )
{
struct V_169 V_170 ;
int V_16 ;
struct V_171 V_172 ;
struct V_61 * V_62 = (struct V_61 * ) V_138 -> V_3 ;
struct V_11 * V_7 = V_62 -> V_7 ;
if ( V_62 -> V_153 != V_166 )
return;
V_16 = F_44 ( (struct V_61 * ) V_138 -> V_3 ) ;
if ( V_16 )
goto V_173;
memset ( & V_170 , 0 , sizeof V_170 ) ;
V_170 . V_174 = V_7 -> V_15 . V_175 ;
V_170 . V_176 = 1 ;
V_170 . V_177 = 7 ;
V_170 . V_178 = 6 ;
memset ( & V_172 , 0 , sizeof( V_172 ) ) ;
V_172 . V_102 = ( V_179 |
V_180 ) ;
V_170 . V_181 = ( void * ) & V_172 ;
V_170 . V_182 = sizeof( struct V_171 ) ;
V_16 = F_68 ( V_138 , & V_170 ) ;
if ( V_16 ) {
F_2 ( L_34 , V_16 ) ;
goto V_173;
}
return;
V_173:
F_64 ( V_138 ) ;
}
static void F_69 ( struct V_142 * V_138 )
{
struct V_61 * V_62 ;
struct V_183 V_184 ;
struct V_114 V_115 ;
V_62 = (struct V_61 * ) V_138 -> V_3 ;
if ( V_62 -> V_153 != V_166 )
return;
( void ) F_70 ( V_138 -> V_140 , & V_184 , ~ 0 , & V_115 ) ;
F_8 ( L_35 , V_184 . V_185 , V_138 -> V_140 -> V_186 ) ;
V_62 -> V_153 = V_164 ;
F_71 ( & V_62 -> V_187 ) ;
}
static void F_72 ( struct V_142 * V_138 )
{
struct V_61 * V_62 ;
V_62 = (struct V_61 * ) V_138 -> V_3 ;
if ( F_54 ( V_62 , V_164 ,
V_165 ) ) {
if ( V_62 -> V_188 )
F_73 ( V_62 -> V_188 , V_189 ) ;
else
F_2 ( L_36 ) ;
}
if ( V_62 -> V_190 == 0 &&
( F_74 ( & V_62 -> V_191 ) == 0 ) ) {
F_71 ( & V_62 -> V_160 ) ;
}
}
static int F_75 ( struct V_142 * V_138 , struct V_192 * V_4 )
{
struct V_61 * V_62 ;
V_62 = (struct V_61 * ) V_138 -> V_3 ;
F_8 ( L_37 ,
V_4 -> V_4 , V_4 -> V_193 , V_138 -> V_3 , V_138 ) ;
F_45 ( & V_62 -> V_162 ) ;
switch ( V_4 -> V_4 ) {
case V_194 :
F_65 ( V_138 ) ;
break;
case V_195 :
F_67 ( V_138 ) ;
break;
case V_196 :
F_69 ( V_138 ) ;
break;
case V_197 :
case V_198 :
case V_199 :
case V_200 :
case V_201 :
F_64 ( V_138 ) ;
break;
case V_202 :
case V_203 :
case V_204 :
case V_205 :
F_72 ( V_138 ) ;
break;
default:
F_2 ( L_38 , V_4 -> V_4 ) ;
break;
}
F_46 ( & V_62 -> V_162 ) ;
return 0 ;
}
void F_76 ( struct V_61 * V_62 )
{
V_62 -> V_153 = V_206 ;
V_62 -> V_190 = 0 ;
F_77 ( & V_62 -> V_191 , 0 ) ;
F_78 ( & V_62 -> V_158 ) ;
F_78 ( & V_62 -> V_160 ) ;
F_78 ( & V_62 -> V_187 ) ;
F_38 ( & V_62 -> V_163 ) ;
F_79 ( & V_62 -> V_207 ) ;
F_80 ( & V_62 -> V_162 ) ;
}
int F_81 ( struct V_61 * V_62 ,
struct V_208 * V_209 ,
struct V_208 * V_210 ,
int V_211 )
{
int V_110 = 0 ;
F_45 ( & V_62 -> V_162 ) ;
sprintf ( V_62 -> V_8 , L_39 , V_210 ) ;
F_8 ( L_40 , V_62 -> V_8 ) ;
V_62 -> V_7 = NULL ;
V_62 -> V_153 = V_166 ;
V_62 -> V_138 = F_82 ( F_75 ,
( void * ) V_62 ,
V_212 , V_132 ) ;
if ( F_12 ( V_62 -> V_138 ) ) {
V_110 = F_28 ( V_62 -> V_138 ) ;
F_2 ( L_41 , V_110 ) ;
goto V_213;
}
V_110 = F_83 ( V_62 -> V_138 , V_209 , V_210 , 1000 ) ;
if ( V_110 ) {
F_2 ( L_42 , V_110 ) ;
goto V_214;
}
if ( ! V_211 ) {
F_84 ( & V_62 -> V_187 ) ;
if ( V_62 -> V_153 != V_164 ) {
V_110 = - V_215 ;
goto V_216;
}
}
F_46 ( & V_62 -> V_162 ) ;
F_45 ( & V_118 . V_119 ) ;
F_52 ( & V_62 -> V_163 , & V_118 . V_217 ) ;
F_46 ( & V_118 . V_119 ) ;
return 0 ;
V_213:
V_62 -> V_138 = NULL ;
V_214:
V_62 -> V_153 = V_161 ;
V_216:
F_46 ( & V_62 -> V_162 ) ;
F_59 ( V_62 ) ;
return V_110 ;
}
int F_85 ( struct V_61 * V_62 ,
struct V_218 * V_68 ,
struct V_219 * V_220 )
{
struct V_221 * V_222 ;
V_69 V_223 ;
V_69 * V_108 ;
int V_193 ;
V_108 = V_68 -> V_71 ;
V_223 = V_108 [ 0 ] ;
V_222 = F_86 ( V_62 -> V_67 . V_80 ,
V_108 ,
V_68 -> V_224 ,
V_223 ) ;
if ( F_12 ( V_222 ) ) {
V_193 = ( int ) F_28 ( V_222 ) ;
F_2 ( L_43 , V_193 ) ;
return V_193 ;
}
V_220 -> V_225 = V_222 -> V_67 -> V_225 ;
V_220 -> V_226 = V_222 -> V_67 -> V_226 ;
V_220 -> V_227 = V_68 -> V_224 * V_228 ;
V_220 -> V_229 = V_223 ;
V_220 -> V_230 = 1 ;
V_220 -> V_231 = ( void * ) V_222 ;
V_220 -> V_229 += V_68 -> V_232 ;
V_220 -> V_227 = V_68 -> V_233 ;
F_36 ( L_44
L_45
L_46 ,
V_68 , V_68 -> V_224 ,
( unsigned long ) V_68 -> V_71 [ 0 ] ,
( unsigned long ) V_68 -> V_233 ,
( unsigned int ) V_220 -> V_225 , V_220 -> V_231 ,
( unsigned long ) V_220 -> V_229 , ( unsigned long ) V_220 -> V_227 ) ;
return 0 ;
}
void V_30 ( struct V_234 * V_235 ,
enum V_236 V_237 )
{
struct V_219 * V_238 = & V_235 -> V_239 [ V_237 ] . V_238 ;
int V_16 ;
if ( ! V_238 -> V_230 )
return;
F_36 ( L_47 , V_238 -> V_231 ) ;
V_16 = F_87 ( (struct V_221 * ) V_238 -> V_231 ) ;
if ( V_16 )
F_2 ( L_48 , V_16 ) ;
V_238 -> V_231 = NULL ;
}
void V_36 ( struct V_234 * V_235 ,
enum V_236 V_237 )
{
struct V_219 * V_238 = & V_235 -> V_239 [ V_237 ] . V_238 ;
struct V_61 * V_62 = V_235 -> V_62 ;
struct V_84 * V_85 = V_238 -> V_231 ;
if ( ! V_238 -> V_230 )
return;
V_238 -> V_231 = NULL ;
V_238 -> V_230 = 0 ;
F_88 ( & V_62 -> V_207 ) ;
F_39 ( & V_85 -> V_112 , & V_62 -> V_109 . V_80 ) ;
F_89 ( & V_62 -> V_207 ) ;
}
int F_90 ( struct V_61 * V_62 )
{
struct V_240 V_241 , * V_242 ;
struct V_243 V_244 ;
int V_245 ;
V_244 . V_246 = V_62 -> V_247 ;
V_244 . V_224 = V_248 ;
V_244 . V_225 = V_62 -> V_7 -> V_54 -> V_225 ;
V_241 . V_249 = ( unsigned long ) V_62 -> V_250 ;
V_241 . V_251 = & V_244 ;
V_241 . V_252 = 1 ;
V_241 . V_253 = NULL ;
V_62 -> V_190 ++ ;
V_245 = F_91 ( V_62 -> V_140 , & V_241 , & V_242 ) ;
if ( V_245 ) {
F_2 ( L_49 , V_245 ) ;
V_62 -> V_190 -- ;
}
return V_245 ;
}
int F_92 ( struct V_61 * V_62 , int V_254 )
{
struct V_240 * V_241 , * V_242 ;
int V_17 , V_245 ;
unsigned int V_255 = V_62 -> V_256 ;
struct V_257 * V_258 ;
for ( V_241 = V_62 -> V_241 , V_17 = 0 ; V_17 < V_254 ; V_17 ++ , V_241 ++ ) {
V_258 = & V_62 -> V_259 [ V_255 ] ;
V_241 -> V_249 = ( unsigned long ) V_258 ;
V_241 -> V_251 = & V_258 -> V_260 ;
V_241 -> V_252 = 1 ;
V_241 -> V_253 = V_241 + 1 ;
V_255 = ( V_255 + 1 ) & V_62 -> V_261 ;
}
V_241 -- ;
V_241 -> V_253 = NULL ;
V_62 -> V_190 += V_254 ;
V_245 = F_91 ( V_62 -> V_140 , V_62 -> V_241 , & V_242 ) ;
if ( V_245 ) {
F_2 ( L_49 , V_245 ) ;
V_62 -> V_190 -= V_254 ;
} else
V_62 -> V_256 = V_255 ;
return V_245 ;
}
int F_93 ( struct V_61 * V_62 , struct V_262 * V_263 )
{
int V_245 ;
struct V_264 V_265 , * V_266 ;
F_94 ( V_62 -> V_7 -> V_18 ,
V_263 -> V_267 , V_268 , V_269 ) ;
V_265 . V_253 = NULL ;
V_265 . V_249 = ( unsigned long ) V_263 ;
V_265 . V_251 = V_263 -> V_270 ;
V_265 . V_252 = V_263 -> V_252 ;
V_265 . V_271 = V_272 ;
V_265 . V_273 = V_274 ;
F_95 ( & V_62 -> V_191 ) ;
V_245 = F_96 ( V_62 -> V_140 , & V_265 , & V_266 ) ;
if ( V_245 ) {
F_2 ( L_50 , V_245 ) ;
F_97 ( & V_62 -> V_191 ) ;
}
return V_245 ;
}
static void F_98 ( struct V_262 * V_85 ,
struct V_61 * V_62 )
{
if ( V_85 && V_85 -> type == V_275 )
F_99 ( V_118 . V_276 , V_85 ) ;
if ( V_62 -> V_190 == 0 &&
F_74 ( & V_62 -> V_191 ) == 0 ) {
if ( V_62 -> V_153 == V_164 )
F_73 ( V_62 -> V_188 ,
V_189 ) ;
F_71 ( & V_62 -> V_160 ) ;
}
}
static int F_100 ( struct V_11 * V_7 , int V_44 )
{
struct V_277 * V_278 = V_7 -> V_49 [ V_44 ] ;
struct V_279 V_280 ;
struct V_262 * V_263 ;
struct V_61 * V_62 ;
int V_281 = 0 ;
while ( F_101 ( V_278 , 1 , & V_280 ) == 1 ) {
V_263 = (struct V_262 * ) ( unsigned long ) V_280 . V_249 ;
V_62 = V_280 . V_140 -> V_121 ;
if ( V_280 . V_193 == V_282 ) {
if ( V_280 . V_271 == V_283 )
F_102 ( V_263 , V_62 ) ;
else
F_2 ( L_51 ,
V_283 , V_280 . V_271 ) ;
} else {
F_2 ( L_52 ,
V_280 . V_249 , V_280 . V_193 , V_280 . V_284 ) ;
if ( V_280 . V_249 != V_285 ) {
F_97 ( & V_62 -> V_191 ) ;
F_98 ( V_263 , V_62 ) ;
}
}
V_281 ++ ;
}
return V_281 ;
}
static void V_53 ( unsigned long V_286 )
{
struct V_12 * V_13 = (struct V_12 * ) V_286 ;
struct V_11 * V_7 = V_13 -> V_7 ;
int V_44 = V_13 -> V_44 ;
struct V_277 * V_278 = V_7 -> V_45 [ V_44 ] ;
struct V_279 V_280 ;
struct V_257 * V_85 ;
unsigned long V_287 ;
struct V_61 * V_62 ;
int V_281 , V_288 = 0 ;
V_281 = F_100 ( V_7 , V_44 ) ;
while ( F_101 ( V_278 , 1 , & V_280 ) == 1 ) {
V_85 = (struct V_257 * ) ( unsigned long ) V_280 . V_249 ;
F_25 ( V_85 == NULL ) ;
V_62 = V_280 . V_140 -> V_121 ;
if ( V_280 . V_193 == V_282 ) {
if ( V_280 . V_271 == V_289 ) {
V_287 = ( unsigned long ) V_280 . V_290 ;
F_103 ( V_85 , V_287 , V_62 ) ;
} else
F_2 ( L_51 ,
V_289 , V_280 . V_271 ) ;
} else {
if ( V_280 . V_193 != V_291 )
F_2 ( L_53 ,
V_280 . V_249 , V_280 . V_193 , V_280 . V_284 ) ;
V_62 -> V_190 -- ;
F_98 ( NULL , V_62 ) ;
}
V_288 ++ ;
if ( ! ( V_288 & 63 ) )
V_281 += F_100 ( V_7 , V_44 ) ;
}
F_14 ( V_278 , V_51 ) ;
F_36 ( L_54 , V_288 , V_281 ) ;
}
static void V_46 ( struct V_277 * V_278 , void * V_141 )
{
struct V_12 * V_13 = (struct V_12 * ) V_141 ;
struct V_11 * V_7 = V_13 -> V_7 ;
int V_44 = V_13 -> V_44 ;
F_104 ( & V_7 -> V_52 [ V_44 ] ) ;
}
T_1 F_105 ( struct V_234 * V_235 ,
enum V_236 V_237 , T_2 * V_292 )
{
struct V_219 * V_238 = & V_235 -> V_239 [ V_237 ] . V_238 ;
struct V_84 * V_85 = V_238 -> V_231 ;
unsigned long V_293 = V_235 -> V_294 -> V_7 -> V_293 ;
struct V_295 V_296 ;
int V_16 ;
if ( V_85 && V_85 -> V_89 & V_107 ) {
V_85 -> V_89 &= ~ V_107 ;
V_16 = F_106 ( V_85 -> V_94 -> V_104 ,
V_297 , & V_296 ) ;
if ( V_16 ) {
F_107 ( L_55 , V_16 ) ;
goto V_110;
}
if ( V_296 . V_298 & V_297 ) {
T_2 V_299 = V_296 . V_300 . V_301 ;
F_108 ( V_299 , V_293 + 8 ) ;
* V_292 = F_109 ( V_235 -> V_294 ) + V_299 ;
F_107 ( L_56
L_57 ,
V_296 . V_300 . V_302 ,
( unsigned long long ) * V_292 ,
V_296 . V_300 . V_303 ,
V_296 . V_300 . V_304 ) ;
switch ( V_296 . V_300 . V_302 ) {
case V_305 :
return 0x1 ;
case V_306 :
return 0x3 ;
case V_307 :
return 0x2 ;
}
}
}
return 0 ;
V_110:
return 0x1 ;
}
