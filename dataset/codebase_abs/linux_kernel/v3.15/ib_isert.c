static void
F_1 ( struct V_1 * V_2 , void * V_3 )
{
struct V_4 * V_4 = (struct V_4 * ) V_3 ;
F_2 ( L_1 , V_2 -> V_5 ) ;
switch ( V_2 -> V_5 ) {
case V_6 :
F_3 ( V_4 -> V_7 , V_6 ) ;
break;
case V_8 :
F_4 ( L_2 ) ;
break;
default:
break;
}
}
static int
F_5 ( struct V_9 * V_10 , struct V_11 * V_12 )
{
int V_13 ;
V_13 = F_6 ( V_10 , V_12 ) ;
if ( V_13 ) {
F_2 ( L_3 , V_13 ) ;
return V_13 ;
}
F_7 ( L_4 , V_12 -> V_14 ) ;
F_7 ( L_5 , V_12 -> V_15 ) ;
return 0 ;
}
static int
F_8 ( struct V_4 * V_4 , struct V_16 * V_17 ,
T_1 V_18 )
{
struct V_19 * V_20 = V_4 -> V_21 ;
struct V_22 V_23 ;
int V_13 , V_24 , V_25 = 0 ;
F_9 ( & V_26 ) ;
for ( V_24 = 0 ; V_24 < V_20 -> V_27 ; V_24 ++ )
if ( V_20 -> V_28 [ V_24 ] <
V_20 -> V_28 [ V_25 ] )
V_25 = V_24 ;
V_20 -> V_28 [ V_25 ] ++ ;
F_7 ( L_6 , V_25 ) ;
F_10 ( & V_26 ) ;
memset ( & V_23 , 0 , sizeof( struct V_22 ) ) ;
V_23 . V_29 = F_1 ;
V_23 . V_30 = V_4 ;
V_23 . V_31 = V_20 -> V_32 [ V_25 ] ;
V_23 . V_33 = V_20 -> V_34 [ V_25 ] ;
V_23 . V_35 . V_36 = V_37 ;
V_23 . V_35 . V_38 = V_39 ;
V_23 . V_35 . V_40 = V_20 -> V_41 . V_14 - 2 ;
V_4 -> V_14 = V_23 . V_35 . V_40 ;
V_23 . V_35 . V_42 = 1 ;
V_23 . V_43 = V_44 ;
V_23 . V_45 = V_46 ;
if ( V_18 )
V_23 . V_47 |= V_48 ;
F_7 ( L_7 ,
V_17 -> V_20 ) ;
F_7 ( L_8 ,
V_4 -> V_49 -> V_20 ) ;
V_13 = F_11 ( V_17 , V_4 -> V_49 , & V_23 ) ;
if ( V_13 ) {
F_2 ( L_9 , V_13 ) ;
return V_13 ;
}
V_4 -> V_50 = V_17 -> V_51 ;
F_7 ( L_10 ) ;
return 0 ;
}
static void
F_12 ( struct V_1 * V_2 , void * V_3 )
{
F_7 ( L_11 , V_2 -> V_5 ) ;
}
static int
F_13 ( struct V_4 * V_4 )
{
struct V_9 * V_10 = V_4 -> V_7 -> V_20 ;
struct V_52 * V_53 ;
struct V_54 * V_55 ;
T_2 V_56 ;
int V_57 , V_58 ;
V_4 -> V_59 = F_14 ( V_39 *
sizeof( struct V_52 ) , V_60 ) ;
if ( ! V_4 -> V_59 )
goto V_61;
V_53 = V_4 -> V_59 ;
for ( V_57 = 0 ; V_57 < V_39 ; V_57 ++ , V_53 ++ ) {
V_56 = F_15 ( V_10 , ( void * ) V_53 ,
V_62 , V_63 ) ;
if ( F_16 ( V_10 , V_56 ) )
goto V_64;
V_53 -> V_56 = V_56 ;
V_55 = & V_53 -> V_55 ;
V_55 -> V_65 = V_53 -> V_56 ;
V_55 -> V_66 = V_62 ;
V_55 -> V_67 = V_4 -> V_68 -> V_67 ;
}
V_4 -> V_69 = 0 ;
return 0 ;
V_64:
V_53 = V_4 -> V_59 ;
for ( V_58 = 0 ; V_58 < V_57 ; V_58 ++ , V_53 ++ ) {
F_17 ( V_10 , V_53 -> V_56 ,
V_62 , V_63 ) ;
}
F_18 ( V_4 -> V_59 ) ;
V_4 -> V_59 = NULL ;
V_61:
return - V_70 ;
}
static void
F_19 ( struct V_4 * V_4 )
{
struct V_9 * V_10 = V_4 -> V_7 -> V_20 ;
struct V_52 * V_53 ;
int V_57 ;
if ( ! V_4 -> V_59 )
return;
V_53 = V_4 -> V_59 ;
for ( V_57 = 0 ; V_57 < V_39 ; V_57 ++ , V_53 ++ ) {
F_17 ( V_10 , V_53 -> V_56 ,
V_62 , V_63 ) ;
}
F_18 ( V_4 -> V_59 ) ;
V_4 -> V_59 = NULL ;
}
static int
F_20 ( struct V_19 * V_20 )
{
struct V_9 * V_10 = V_20 -> V_9 ;
struct V_71 * V_72 ;
struct V_11 * V_41 ;
int V_13 = 0 , V_57 , V_58 ;
V_41 = & V_20 -> V_41 ;
V_13 = F_5 ( V_10 , V_41 ) ;
if ( V_13 )
return V_13 ;
if ( V_41 -> V_73 & V_74 &&
V_41 -> V_73 & V_75 ) {
V_20 -> V_76 = 1 ;
V_20 -> V_77 = V_78 ;
V_20 -> V_79 = V_80 ;
} else {
V_20 -> V_76 = 0 ;
V_20 -> V_77 = V_81 ;
V_20 -> V_79 = V_82 ;
}
V_20 -> V_83 = V_41 -> V_73 &
V_75 ? true : false ;
V_20 -> V_27 = F_21 ( int , F_22 () ,
V_20 -> V_9 -> V_84 ) ;
V_20 -> V_27 = F_23 ( V_85 , V_20 -> V_27 ) ;
F_7 ( L_12
L_13 ,
V_20 -> V_27 , V_20 -> V_9 -> V_86 ,
V_20 -> V_9 -> V_84 , V_20 -> V_76 ,
V_20 -> V_83 ) ;
V_20 -> V_72 = F_14 ( sizeof( struct V_71 ) *
V_20 -> V_27 , V_60 ) ;
if ( ! V_20 -> V_72 ) {
F_2 ( L_14 ) ;
return - V_70 ;
}
V_72 = V_20 -> V_72 ;
for ( V_57 = 0 ; V_57 < V_20 -> V_27 ; V_57 ++ ) {
V_72 [ V_57 ] . V_20 = V_20 ;
V_72 [ V_57 ] . V_87 = V_57 ;
F_24 ( & V_72 [ V_57 ] . V_88 , V_89 ) ;
V_20 -> V_34 [ V_57 ] = F_25 ( V_20 -> V_9 ,
V_90 ,
F_12 ,
( void * ) & V_72 [ V_57 ] ,
V_91 , V_57 ) ;
if ( F_26 ( V_20 -> V_34 [ V_57 ] ) ) {
V_13 = F_27 ( V_20 -> V_34 [ V_57 ] ) ;
V_20 -> V_34 [ V_57 ] = NULL ;
goto V_92;
}
F_24 ( & V_72 [ V_57 ] . V_93 , V_94 ) ;
V_20 -> V_32 [ V_57 ] = F_25 ( V_20 -> V_9 ,
V_95 ,
F_12 ,
( void * ) & V_72 [ V_57 ] ,
V_96 , V_57 ) ;
if ( F_26 ( V_20 -> V_32 [ V_57 ] ) ) {
V_13 = F_27 ( V_20 -> V_32 [ V_57 ] ) ;
V_20 -> V_32 [ V_57 ] = NULL ;
goto V_92;
}
V_13 = F_28 ( V_20 -> V_34 [ V_57 ] , V_97 ) ;
if ( V_13 )
goto V_92;
V_13 = F_28 ( V_20 -> V_32 [ V_57 ] , V_97 ) ;
if ( V_13 )
goto V_92;
}
return 0 ;
V_92:
for ( V_58 = 0 ; V_58 < V_57 ; V_58 ++ ) {
V_72 = & V_20 -> V_72 [ V_58 ] ;
if ( V_20 -> V_34 [ V_58 ] ) {
F_29 ( & V_72 -> V_88 ) ;
F_30 ( V_20 -> V_34 [ V_58 ] ) ;
}
if ( V_20 -> V_32 [ V_58 ] ) {
F_29 ( & V_72 -> V_93 ) ;
F_30 ( V_20 -> V_32 [ V_58 ] ) ;
}
}
F_18 ( V_20 -> V_72 ) ;
return V_13 ;
}
static void
F_31 ( struct V_19 * V_20 )
{
struct V_71 * V_72 ;
int V_57 ;
for ( V_57 = 0 ; V_57 < V_20 -> V_27 ; V_57 ++ ) {
V_72 = & V_20 -> V_72 [ V_57 ] ;
F_29 ( & V_72 -> V_88 ) ;
F_29 ( & V_72 -> V_93 ) ;
F_30 ( V_20 -> V_34 [ V_57 ] ) ;
F_30 ( V_20 -> V_32 [ V_57 ] ) ;
V_20 -> V_34 [ V_57 ] = NULL ;
V_20 -> V_32 [ V_57 ] = NULL ;
}
F_18 ( V_20 -> V_72 ) ;
}
static void
F_32 ( struct V_19 * V_20 )
{
F_9 ( & V_26 ) ;
V_20 -> V_98 -- ;
if ( ! V_20 -> V_98 ) {
F_31 ( V_20 ) ;
F_33 ( & V_20 -> V_99 ) ;
F_18 ( V_20 ) ;
}
F_10 ( & V_26 ) ;
}
static struct V_19 *
F_34 ( struct V_16 * V_17 )
{
struct V_19 * V_20 ;
int V_13 ;
F_9 ( & V_26 ) ;
F_35 (device, &device_list, dev_node) {
if ( V_20 -> V_9 -> V_100 == V_17 -> V_20 -> V_100 ) {
V_20 -> V_98 ++ ;
F_10 ( & V_26 ) ;
return V_20 ;
}
}
V_20 = F_14 ( sizeof( struct V_19 ) , V_60 ) ;
if ( ! V_20 ) {
F_10 ( & V_26 ) ;
return F_36 ( - V_70 ) ;
}
F_37 ( & V_20 -> V_99 ) ;
V_20 -> V_9 = V_17 -> V_20 ;
V_13 = F_20 ( V_20 ) ;
if ( V_13 ) {
F_18 ( V_20 ) ;
F_10 ( & V_26 ) ;
return F_36 ( V_13 ) ;
}
V_20 -> V_98 ++ ;
F_38 ( & V_20 -> V_99 , & V_101 ) ;
F_10 ( & V_26 ) ;
return V_20 ;
}
static void
F_39 ( struct V_4 * V_4 )
{
struct V_102 * V_103 , * V_104 ;
int V_57 = 0 ;
if ( F_40 ( & V_4 -> V_105 ) )
return;
F_7 ( L_15 , V_4 ) ;
F_41 (fr_desc, tmp,
&isert_conn->conn_fr_pool, list) {
F_33 ( & V_103 -> V_106 ) ;
F_42 ( V_103 -> V_107 ) ;
F_43 ( V_103 -> V_108 ) ;
if ( V_103 -> V_109 ) {
F_42 ( V_103 -> V_109 -> V_110 ) ;
F_43 ( V_103 -> V_109 -> V_111 ) ;
F_44 ( V_103 -> V_109 -> V_112 ) ;
F_18 ( V_103 -> V_109 ) ;
}
F_18 ( V_103 ) ;
++ V_57 ;
}
if ( V_57 < V_4 -> V_113 )
F_4 ( L_16 ,
V_4 -> V_113 - V_57 ) ;
}
static int
F_45 ( struct V_9 * V_9 , struct V_114 * V_115 ,
struct V_102 * V_103 , T_1 V_18 )
{
int V_13 ;
V_103 -> V_107 = F_46 ( V_9 ,
V_116 ) ;
if ( F_26 ( V_103 -> V_107 ) ) {
F_2 ( L_17 ,
F_27 ( V_103 -> V_107 ) ) ;
return F_27 ( V_103 -> V_107 ) ;
}
V_103 -> V_108 = F_47 ( V_115 , V_116 ) ;
if ( F_26 ( V_103 -> V_108 ) ) {
F_2 ( L_18 ,
F_27 ( V_103 -> V_108 ) ) ;
V_13 = F_27 ( V_103 -> V_108 ) ;
goto V_117;
}
F_7 ( L_19 ,
V_103 , V_103 -> V_107 -> V_118 ) ;
V_103 -> V_119 |= V_120 ;
if ( V_18 ) {
struct V_121 V_122 = { 0 } ;
struct V_123 * V_109 ;
V_103 -> V_109 = F_14 ( sizeof( * V_103 -> V_109 ) , V_60 ) ;
if ( ! V_103 -> V_109 ) {
F_2 ( L_20 ) ;
V_13 = - V_70 ;
goto V_124;
}
V_109 = V_103 -> V_109 ;
V_109 -> V_110 = F_46 ( V_9 ,
V_116 ) ;
if ( F_26 ( V_109 -> V_110 ) ) {
F_2 ( L_21 ,
F_27 ( V_109 -> V_110 ) ) ;
V_13 = F_27 ( V_109 -> V_110 ) ;
goto V_125;
}
V_109 -> V_111 = F_47 ( V_115 , V_116 ) ;
if ( F_26 ( V_109 -> V_111 ) ) {
F_2 ( L_22 ,
F_27 ( V_109 -> V_111 ) ) ;
V_13 = F_27 ( V_109 -> V_111 ) ;
goto V_126;
}
V_103 -> V_119 |= V_127 ;
V_122 . V_128 = 2 ;
V_122 . V_129 |= V_130 ;
V_109 -> V_112 = F_48 ( V_115 , & V_122 ) ;
if ( F_26 ( V_109 -> V_112 ) ) {
F_2 ( L_23 ,
F_27 ( V_109 -> V_112 ) ) ;
V_13 = F_27 ( V_109 -> V_112 ) ;
goto V_131;
}
V_103 -> V_119 |= V_132 ;
}
V_103 -> V_119 &= ~ V_133 ;
return 0 ;
V_131:
F_43 ( V_103 -> V_109 -> V_111 ) ;
V_126:
F_42 ( V_103 -> V_109 -> V_110 ) ;
V_125:
F_18 ( V_103 -> V_109 ) ;
V_124:
F_43 ( V_103 -> V_108 ) ;
V_117:
F_42 ( V_103 -> V_107 ) ;
return V_13 ;
}
static int
F_49 ( struct V_4 * V_4 , T_1 V_134 )
{
struct V_102 * V_103 ;
struct V_19 * V_20 = V_4 -> V_21 ;
struct V_135 * V_136 = V_4 -> V_137 -> V_138 -> V_136 ;
struct V_139 * V_140 = V_136 -> V_139 ;
int V_57 , V_13 , V_141 ;
V_141 = F_50 ( V_142 , V_143 , V_140 -> V_144 ) ;
V_141 = ( V_141 * 2 ) + V_145 ;
V_4 -> V_113 = 0 ;
for ( V_57 = 0 ; V_57 < V_141 ; V_57 ++ ) {
V_103 = F_14 ( sizeof( * V_103 ) , V_60 ) ;
if ( ! V_103 ) {
F_2 ( L_24 ) ;
V_13 = - V_70 ;
goto V_146;
}
V_13 = F_45 ( V_20 -> V_9 ,
V_4 -> V_49 , V_103 ,
V_134 ) ;
if ( V_13 ) {
F_2 ( L_25 ,
V_13 ) ;
F_18 ( V_103 ) ;
goto V_146;
}
F_38 ( & V_103 -> V_106 , & V_4 -> V_105 ) ;
V_4 -> V_113 ++ ;
}
F_7 ( L_26 ,
V_4 , V_4 -> V_113 ) ;
return 0 ;
V_146:
F_39 ( V_4 ) ;
return V_13 ;
}
static int
F_51 ( struct V_16 * V_17 , struct V_147 * V_5 )
{
struct V_148 * V_149 = V_17 -> V_3 ;
struct V_150 * V_150 = V_149 -> V_151 ;
struct V_4 * V_4 ;
struct V_19 * V_20 ;
struct V_9 * V_10 = V_17 -> V_20 ;
int V_13 = 0 ;
T_1 V_134 ;
F_52 ( & V_149 -> V_152 ) ;
if ( ! V_149 -> V_153 ) {
F_53 ( & V_149 -> V_152 ) ;
F_7 ( L_27 ) ;
return F_54 ( V_17 , NULL , 0 ) ;
}
F_53 ( & V_149 -> V_152 ) ;
F_7 ( L_28 ,
V_17 , V_17 -> V_3 ) ;
V_4 = F_14 ( sizeof( struct V_4 ) , V_60 ) ;
if ( ! V_4 ) {
F_2 ( L_29 ) ;
return - V_70 ;
}
V_4 -> V_154 = V_155 ;
F_37 ( & V_4 -> V_156 ) ;
F_55 ( & V_4 -> V_157 ) ;
F_55 ( & V_4 -> V_158 ) ;
F_55 ( & V_4 -> V_159 ) ;
F_56 ( & V_4 -> V_160 ) ;
F_57 ( & V_4 -> V_160 ) ;
F_58 ( & V_4 -> V_161 ) ;
F_59 ( & V_4 -> V_162 ) ;
F_37 ( & V_4 -> V_105 ) ;
V_17 -> V_3 = V_4 ;
V_4 -> V_7 = V_17 ;
V_4 -> V_163 = V_5 -> V_164 . V_137 . V_163 ;
V_4 -> V_165 = V_5 -> V_164 . V_137 . V_165 ;
F_7 ( L_30 ,
V_4 -> V_163 , V_4 -> V_165 ) ;
V_4 -> V_166 = F_14 ( V_167 +
V_168 , V_60 ) ;
if ( ! V_4 -> V_166 ) {
F_2 ( L_31 ) ;
V_13 = - V_70 ;
goto V_169;
}
V_4 -> V_170 = V_4 -> V_166 ;
V_4 -> V_171 = V_4 -> V_166 +
V_167 ;
F_7 ( L_32 ,
V_4 -> V_166 , V_4 -> V_170 ,
V_4 -> V_171 ) ;
V_4 -> V_172 = F_15 ( V_10 ,
( void * ) V_4 -> V_170 ,
V_167 , V_63 ) ;
V_13 = F_16 ( V_10 , V_4 -> V_172 ) ;
if ( V_13 ) {
F_2 ( L_33 ,
V_13 ) ;
V_4 -> V_172 = 0 ;
goto V_173;
}
V_4 -> V_174 = F_15 ( V_10 ,
( void * ) V_4 -> V_171 ,
V_168 , V_175 ) ;
V_13 = F_16 ( V_10 , V_4 -> V_174 ) ;
if ( V_13 ) {
F_2 ( L_34 ,
V_13 ) ;
V_4 -> V_174 = 0 ;
goto V_176;
}
V_20 = F_34 ( V_17 ) ;
if ( F_26 ( V_20 ) ) {
V_13 = F_27 ( V_20 ) ;
goto V_177;
}
V_4 -> V_21 = V_20 ;
V_4 -> V_49 = F_60 ( V_4 -> V_21 -> V_9 ) ;
if ( F_26 ( V_4 -> V_49 ) ) {
V_13 = F_27 ( V_4 -> V_49 ) ;
F_2 ( L_35 ,
V_4 , V_13 ) ;
goto V_178;
}
V_4 -> V_68 = F_61 ( V_4 -> V_49 ,
V_179 ) ;
if ( F_26 ( V_4 -> V_68 ) ) {
V_13 = F_27 ( V_4 -> V_68 ) ;
F_2 ( L_36 ,
V_4 , V_13 ) ;
goto V_180;
}
V_134 = V_149 -> V_181 -> V_182 -> V_183 . V_184 ;
if ( V_134 && ! V_20 -> V_83 ) {
F_2 ( L_37 ) ;
V_13 = - V_185 ;
goto V_180;
}
V_13 = F_8 ( V_4 , V_17 , V_134 ) ;
if ( V_13 )
goto V_186;
F_9 ( & V_150 -> V_187 ) ;
F_38 ( & V_4 -> V_156 , & V_150 -> V_188 ) ;
F_10 ( & V_150 -> V_187 ) ;
F_7 ( L_38 , V_149 ) ;
F_62 ( & V_150 -> V_189 ) ;
return 0 ;
V_186:
F_43 ( V_4 -> V_68 ) ;
V_180:
F_63 ( V_4 -> V_49 ) ;
V_178:
F_32 ( V_20 ) ;
V_177:
F_17 ( V_10 , V_4 -> V_174 ,
V_168 , V_175 ) ;
V_176:
F_17 ( V_10 , V_4 -> V_172 ,
V_167 , V_63 ) ;
V_173:
F_18 ( V_4 -> V_166 ) ;
V_169:
F_18 ( V_4 ) ;
return V_13 ;
}
static void
F_64 ( struct V_4 * V_4 )
{
struct V_9 * V_10 = V_4 -> V_7 -> V_20 ;
struct V_19 * V_20 = V_4 -> V_21 ;
int V_87 ;
F_7 ( L_39 ) ;
if ( V_20 && V_20 -> V_76 )
F_39 ( V_4 ) ;
if ( V_4 -> V_50 ) {
V_87 = ( (struct V_71 * )
V_4 -> V_50 -> V_33 -> V_190 ) -> V_87 ;
F_7 ( L_40 , V_87 ) ;
V_4 -> V_21 -> V_28 [ V_87 ] -- ;
F_65 ( V_4 -> V_7 ) ;
}
F_19 ( V_4 ) ;
F_66 ( V_4 -> V_7 ) ;
F_43 ( V_4 -> V_68 ) ;
F_63 ( V_4 -> V_49 ) ;
if ( V_4 -> V_166 ) {
F_17 ( V_10 , V_4 -> V_174 ,
V_168 , V_175 ) ;
F_17 ( V_10 , V_4 -> V_172 ,
V_167 ,
V_63 ) ;
F_18 ( V_4 -> V_166 ) ;
}
F_18 ( V_4 ) ;
if ( V_20 )
F_32 ( V_20 ) ;
F_7 ( L_41 ) ;
}
static void
F_67 ( struct V_16 * V_17 )
{
return;
}
static void
F_68 ( struct V_191 * V_191 )
{
struct V_4 * V_4 = F_69 ( V_191 ,
struct V_4 , V_160 ) ;
F_7 ( L_42 ,
V_192 -> V_193 , V_192 -> V_194 ) ;
F_64 ( V_4 ) ;
}
static void
F_70 ( struct V_4 * V_4 )
{
F_71 ( & V_4 -> V_160 , F_68 ) ;
}
static void
F_72 ( struct V_195 * V_196 )
{
struct V_4 * V_4 = F_69 ( V_196 ,
struct V_4 , V_197 ) ;
F_7 ( L_43 ) ;
F_9 ( & V_4 -> V_161 ) ;
if ( V_4 -> V_154 == V_198 )
V_4 -> V_154 = V_199 ;
if ( V_4 -> V_200 == 0 &&
F_73 ( & V_4 -> V_201 ) == 0 ) {
F_10 ( & V_4 -> V_161 ) ;
goto V_202;
}
if ( ! V_4 -> V_7 ) {
F_10 ( & V_4 -> V_161 ) ;
F_70 ( V_4 ) ;
return;
}
if ( ! V_4 -> V_203 ) {
F_7 ( L_44
L_45 ) ;
F_74 ( V_4 -> V_7 ) ;
F_10 ( & V_4 -> V_161 ) ;
F_75 ( V_4 -> V_137 , 0 ) ;
goto V_202;
}
F_10 ( & V_4 -> V_161 ) ;
V_202:
F_76 ( & V_4 -> V_158 ) ;
F_70 ( V_4 ) ;
}
static void
F_77 ( struct V_16 * V_17 )
{
struct V_4 * V_4 = (struct V_4 * ) V_17 -> V_3 ;
F_24 ( & V_4 -> V_197 , F_72 ) ;
F_78 ( & V_4 -> V_197 ) ;
}
static int
F_79 ( struct V_16 * V_17 , struct V_147 * V_5 )
{
int V_13 = 0 ;
F_7 ( L_46 ,
V_5 -> V_5 , V_5 -> V_204 , V_17 -> V_3 , V_17 ) ;
switch ( V_5 -> V_5 ) {
case V_205 :
F_7 ( L_47 ) ;
V_13 = F_51 ( V_17 , V_5 ) ;
break;
case V_206 :
F_7 ( L_48 ) ;
F_67 ( V_17 ) ;
break;
case V_207 :
F_7 ( L_49 ) ;
F_77 ( V_17 ) ;
break;
case V_208 :
case V_209 :
break;
case V_210 :
default:
F_2 ( L_50 , V_5 -> V_5 ) ;
break;
}
if ( V_13 != 0 ) {
F_2 ( L_51 ,
V_5 -> V_5 , V_13 ) ;
F_80 () ;
}
return V_13 ;
}
static int
F_81 ( struct V_4 * V_4 , V_142 V_211 )
{
struct V_212 * V_213 , * V_214 ;
int V_57 , V_13 ;
unsigned int V_215 = V_4 -> V_69 ;
struct V_52 * V_53 ;
for ( V_213 = V_4 -> V_216 , V_57 = 0 ; V_57 < V_211 ; V_57 ++ , V_213 ++ ) {
V_53 = & V_4 -> V_59 [ V_215 ] ;
V_213 -> V_217 = ( unsigned long ) V_53 ;
V_213 -> V_218 = & V_53 -> V_55 ;
V_213 -> V_219 = 1 ;
V_213 -> V_220 = V_213 + 1 ;
V_215 = ( V_215 + 1 ) & ( V_39 - 1 ) ;
}
V_213 -- ;
V_213 -> V_220 = NULL ;
V_4 -> V_200 += V_211 ;
V_13 = F_82 ( V_4 -> V_50 , V_4 -> V_216 ,
& V_214 ) ;
if ( V_13 ) {
F_2 ( L_52 , V_13 ) ;
V_4 -> V_200 -= V_211 ;
} else {
F_7 ( L_53 , V_211 ) ;
V_4 -> V_69 = V_215 ;
}
return V_13 ;
}
static int
F_83 ( struct V_4 * V_4 , struct V_221 * V_222 )
{
struct V_9 * V_10 = V_4 -> V_7 -> V_20 ;
struct V_223 V_224 , * V_225 ;
int V_13 ;
F_84 ( V_10 , V_222 -> V_56 ,
V_226 , V_175 ) ;
V_224 . V_220 = NULL ;
V_224 . V_217 = ( unsigned long ) V_222 ;
V_224 . V_218 = V_222 -> V_227 ;
V_224 . V_219 = V_222 -> V_219 ;
V_224 . V_228 = V_229 ;
V_224 . V_230 = V_231 ;
F_85 ( & V_4 -> V_201 ) ;
V_13 = F_86 ( V_4 -> V_50 , & V_224 , & V_225 ) ;
if ( V_13 ) {
F_2 ( L_54 , V_13 ) ;
F_87 ( & V_4 -> V_201 ) ;
}
return V_13 ;
}
static void
F_88 ( struct V_4 * V_4 ,
struct V_232 * V_232 ,
struct V_221 * V_222 )
{
struct V_9 * V_10 = V_4 -> V_7 -> V_20 ;
F_89 ( V_10 , V_222 -> V_56 ,
V_226 , V_175 ) ;
memset ( & V_222 -> V_233 , 0 , sizeof( struct V_234 ) ) ;
V_222 -> V_233 . V_129 = V_235 ;
V_222 -> V_219 = 1 ;
V_222 -> V_232 = V_232 ;
if ( V_222 -> V_227 [ 0 ] . V_67 != V_4 -> V_68 -> V_67 ) {
V_222 -> V_227 [ 0 ] . V_67 = V_4 -> V_68 -> V_67 ;
F_7 ( L_55 , V_222 ) ;
}
}
static int
F_90 ( struct V_4 * V_4 ,
struct V_221 * V_222 )
{
struct V_9 * V_10 = V_4 -> V_7 -> V_20 ;
T_2 V_56 ;
V_56 = F_15 ( V_10 , ( void * ) V_222 ,
V_226 , V_175 ) ;
if ( F_16 ( V_10 , V_56 ) ) {
F_2 ( L_56 ) ;
return - V_70 ;
}
V_222 -> V_56 = V_56 ;
V_222 -> V_227 [ 0 ] . V_65 = V_222 -> V_56 ;
V_222 -> V_227 [ 0 ] . V_66 = V_226 ;
V_222 -> V_227 [ 0 ] . V_67 = V_4 -> V_68 -> V_67 ;
F_7 ( L_57
L_58 , V_222 -> V_227 [ 0 ] . V_65 ,
V_222 -> V_227 [ 0 ] . V_66 , V_222 -> V_227 [ 0 ] . V_67 ) ;
return 0 ;
}
static void
F_91 ( struct V_4 * V_4 , struct V_232 * V_232 ,
struct V_223 * V_224 , bool V_236 )
{
struct V_221 * V_222 = & V_232 -> V_222 ;
V_232 -> V_237 . V_238 = V_239 ;
V_224 -> V_217 = ( unsigned long ) & V_232 -> V_222 ;
V_224 -> V_228 = V_229 ;
V_224 -> V_218 = & V_222 -> V_227 [ 0 ] ;
V_224 -> V_219 = V_232 -> V_222 . V_219 ;
F_9 ( & V_4 -> V_161 ) ;
if ( V_236 && V_4 -> V_154 == V_198 &&
++ V_4 -> V_240 < V_241 ) {
V_222 -> V_242 = true ;
F_92 ( & V_222 -> V_243 , & V_4 -> V_244 ) ;
F_10 ( & V_4 -> V_161 ) ;
return;
}
V_4 -> V_240 = 0 ;
V_222 -> V_245 = F_93 ( & V_4 -> V_244 ) ;
F_10 ( & V_4 -> V_161 ) ;
V_224 -> V_230 = V_231 ;
}
static int
F_94 ( struct V_4 * V_4 )
{
struct V_212 V_213 , * V_246 ;
struct V_54 V_247 ;
int V_13 ;
memset ( & V_247 , 0 , sizeof( struct V_54 ) ) ;
V_247 . V_65 = V_4 -> V_172 ;
V_247 . V_66 = V_168 ;
V_247 . V_67 = V_4 -> V_68 -> V_67 ;
F_7 ( L_59 ,
V_247 . V_65 , V_247 . V_66 , V_247 . V_67 ) ;
memset ( & V_213 , 0 , sizeof( struct V_212 ) ) ;
V_213 . V_217 = ( unsigned long ) V_4 -> V_170 ;
V_213 . V_218 = & V_247 ;
V_213 . V_219 = 1 ;
V_4 -> V_200 ++ ;
V_13 = F_82 ( V_4 -> V_50 , & V_213 , & V_246 ) ;
if ( V_13 ) {
F_2 ( L_60 , V_13 ) ;
V_4 -> V_200 -- ;
}
F_7 ( L_61 ) ;
return V_13 ;
}
static int
F_95 ( struct V_248 * V_137 , struct V_249 * V_250 ,
V_142 V_66 )
{
struct V_4 * V_4 = V_137 -> V_3 ;
struct V_9 * V_10 = V_4 -> V_7 -> V_20 ;
struct V_221 * V_222 = & V_4 -> V_251 ;
int V_13 ;
F_88 ( V_4 , NULL , V_222 ) ;
memcpy ( & V_222 -> V_252 , & V_250 -> V_253 [ 0 ] ,
sizeof( struct V_254 ) ) ;
F_90 ( V_4 , V_222 ) ;
if ( V_66 > 0 ) {
struct V_54 * V_255 = & V_222 -> V_227 [ 1 ] ;
F_89 ( V_10 , V_4 -> V_174 ,
V_66 , V_175 ) ;
memcpy ( V_4 -> V_171 , V_250 -> V_256 , V_66 ) ;
F_84 ( V_10 , V_4 -> V_174 ,
V_66 , V_175 ) ;
V_255 -> V_65 = V_4 -> V_174 ;
V_255 -> V_66 = V_66 ;
V_255 -> V_67 = V_4 -> V_68 -> V_67 ;
V_222 -> V_219 = 2 ;
}
if ( ! V_250 -> V_257 ) {
if ( V_250 -> V_258 ) {
if ( V_4 -> V_21 -> V_76 ) {
T_1 V_134 = V_250 -> V_149 -> V_181 -> V_182 -> V_183 . V_184 ;
V_13 = F_49 ( V_4 ,
V_134 ) ;
if ( V_13 ) {
F_2 ( L_62
L_63 , V_4 ) ;
return V_13 ;
}
}
V_13 = F_13 ( V_4 ) ;
if ( V_13 )
return V_13 ;
V_13 = F_81 ( V_4 , V_259 ) ;
if ( V_13 )
return V_13 ;
V_4 -> V_154 = V_198 ;
goto V_260;
}
V_13 = F_94 ( V_4 ) ;
if ( V_13 )
return V_13 ;
}
V_260:
V_13 = F_83 ( V_4 , V_222 ) ;
if ( V_13 )
return V_13 ;
return 0 ;
}
static void
F_96 ( struct V_52 * V_53 , int V_261 ,
struct V_4 * V_4 )
{
struct V_248 * V_137 = V_4 -> V_137 ;
struct V_249 * V_250 = V_137 -> V_262 ;
int V_263 ;
if ( ! V_250 ) {
F_2 ( L_64 ) ;
F_80 () ;
return;
}
if ( V_250 -> V_264 ) {
struct V_265 * V_266 =
(struct V_265 * ) & V_53 -> V_252 ;
V_250 -> V_267 = ( ! V_266 -> V_268 ) ? 1 : 0 ;
V_250 -> V_269 =
( V_266 -> V_129 & V_270 )
>> 2 ;
V_250 -> V_271 = V_266 -> V_272 ;
V_250 -> V_273 = V_266 -> V_274 ;
memcpy ( V_250 -> V_275 , V_266 -> V_275 , 6 ) ;
V_250 -> V_276 = F_97 ( V_266 -> V_277 ) ;
V_250 -> V_278 = V_266 -> V_279 ;
V_250 -> V_280 = F_97 ( V_266 -> V_281 ) ;
V_250 -> V_282 = F_98 ( V_266 -> V_282 ) ;
V_250 -> V_268 = F_98 ( V_266 -> V_268 ) ;
}
memcpy ( & V_250 -> V_283 [ 0 ] , ( void * ) & V_53 -> V_252 , V_284 ) ;
V_263 = F_23 ( V_261 , V_285 ) ;
F_7 ( L_65 ,
V_263 , V_261 , V_285 ) ;
memcpy ( V_250 -> V_286 , & V_53 -> V_287 [ 0 ] , V_263 ) ;
if ( V_250 -> V_264 ) {
F_76 ( & V_4 -> V_157 ) ;
return;
}
F_99 ( & V_137 -> V_288 , 0 ) ;
}
static struct V_289
* F_100 ( struct V_248 * V_137 )
{
struct V_4 * V_4 = (struct V_4 * ) V_137 -> V_3 ;
struct V_232 * V_232 ;
struct V_289 * V_290 ;
V_290 = F_101 ( V_137 , V_291 ) ;
if ( ! V_290 ) {
F_2 ( L_66 ) ;
return NULL ;
}
V_232 = F_102 ( V_290 ) ;
V_232 -> V_137 = V_4 ;
V_232 -> V_289 = V_290 ;
return V_290 ;
}
static int
F_103 ( struct V_4 * V_4 ,
struct V_232 * V_232 , struct V_289 * V_290 ,
struct V_52 * V_53 , unsigned char * V_292 )
{
struct V_248 * V_137 = V_4 -> V_137 ;
struct V_293 * V_294 = (struct V_293 * ) V_292 ;
struct V_295 * V_296 ;
int V_297 , V_298 , V_299 , V_300 , V_301 ;
bool V_302 = false ;
V_301 = F_104 ( V_137 , V_290 , V_292 ) ;
if ( V_301 < 0 )
return V_301 ;
V_297 = V_290 -> V_303 ;
V_298 = V_290 -> V_304 ;
V_299 = V_290 -> V_305 ;
V_301 = F_105 ( V_137 , V_290 , V_294 ) ;
if ( V_301 < 0 ) {
return 0 ;
} else if ( V_301 > 0 ) {
V_302 = true ;
goto V_306;
}
if ( ! V_297 )
return 0 ;
V_296 = & V_290 -> V_307 . V_308 [ 0 ] ;
V_300 = F_106 ( 1UL , F_107 ( V_298 , V_309 ) ) ;
F_7 ( L_67 ,
V_296 , V_300 , & V_53 -> V_287 [ 0 ] , V_298 ) ;
F_108 ( V_296 , V_300 , & V_53 -> V_287 [ 0 ] , V_298 ) ;
V_290 -> V_310 += V_298 ;
if ( V_290 -> V_310 == V_290 -> V_307 . V_311 ) {
F_52 ( & V_290 -> V_312 ) ;
V_290 -> V_313 |= V_314 ;
V_290 -> V_315 = V_316 ;
F_53 ( & V_290 -> V_312 ) ;
}
V_306:
V_301 = F_109 ( V_137 , V_290 , V_292 , V_294 -> V_277 ) ;
if ( ! V_301 && V_302 == false && V_299 )
F_110 ( V_290 ) ;
else if ( V_302 && V_297 )
F_111 ( V_137 -> V_138 -> V_136 , & V_290 -> V_307 ) ;
return 0 ;
}
static int
F_112 ( struct V_4 * V_4 ,
struct V_52 * V_53 , unsigned char * V_292 )
{
struct V_295 * V_317 ;
struct V_248 * V_137 = V_4 -> V_137 ;
struct V_289 * V_290 = NULL ;
struct V_318 * V_294 = (struct V_318 * ) V_292 ;
V_142 V_319 = F_113 ( V_294 -> V_320 ) ;
int V_301 , V_300 , V_321 , V_322 ;
V_301 = F_114 ( V_137 , V_292 , & V_290 ) ;
if ( V_301 < 0 )
return V_301 ;
else if ( ! V_290 )
return 0 ;
if ( ! V_290 -> V_305 ) {
F_2 ( L_68 ) ;
F_80 () ;
return - 1 ;
}
F_7 ( L_69 ,
V_319 , V_290 -> V_310 , V_290 -> V_307 . V_311 ) ;
V_321 = V_290 -> V_310 / V_309 ;
V_317 = & V_290 -> V_307 . V_308 [ V_321 ] ;
V_300 = F_106 ( 1UL , F_107 ( V_319 , V_309 ) ) ;
V_322 = V_290 -> V_310 % V_309 ;
if ( V_322 ) {
F_2 ( L_70 ) ;
F_80 () ;
return - 1 ;
}
F_7 ( L_71 ,
V_317 , V_321 , V_300 , & V_53 -> V_287 [ 0 ] , V_319 ) ;
F_108 ( V_317 , V_300 , & V_53 -> V_287 [ 0 ] ,
V_319 ) ;
V_301 = F_115 ( V_290 , V_294 , false ) ;
if ( V_301 < 0 )
return V_301 ;
return 0 ;
}
static int
F_116 ( struct V_4 * V_4 , struct V_232 * V_232 ,
struct V_289 * V_290 , struct V_52 * V_53 ,
unsigned char * V_292 )
{
struct V_248 * V_137 = V_4 -> V_137 ;
struct V_323 * V_294 = (struct V_323 * ) V_292 ;
int V_301 ;
V_301 = F_117 ( V_137 , V_290 , V_294 ) ;
if ( V_301 < 0 )
return V_301 ;
return F_118 ( V_137 , V_290 , V_294 ) ;
}
static int
F_119 ( struct V_4 * V_4 , struct V_232 * V_232 ,
struct V_289 * V_290 , struct V_52 * V_53 ,
struct V_324 * V_294 )
{
struct V_248 * V_137 = V_4 -> V_137 ;
V_142 V_325 = F_113 ( V_294 -> V_320 ) ;
int V_301 ;
unsigned char * V_326 ;
V_301 = F_120 ( V_137 , V_290 , V_294 ) ;
if ( V_301 < 0 )
return V_301 ;
V_326 = F_14 ( V_325 , V_60 ) ;
if ( ! V_326 ) {
F_2 ( L_72 ,
V_325 ) ;
return - V_70 ;
}
V_290 -> V_327 = V_326 ;
memcpy ( V_290 -> V_327 , & V_53 -> V_287 [ 0 ] , V_325 ) ;
return F_121 ( V_137 , V_290 , V_294 ) ;
}
static int
F_122 ( struct V_4 * V_4 , struct V_52 * V_53 ,
T_3 V_328 , T_4 V_329 ,
T_3 V_330 , T_4 V_331 )
{
struct V_254 * V_294 = & V_53 -> V_252 ;
struct V_248 * V_137 = V_4 -> V_137 ;
struct V_332 * V_138 = V_137 -> V_138 ;
struct V_289 * V_290 ;
struct V_232 * V_232 ;
int V_13 = - V_185 ;
T_1 V_228 = ( V_294 -> V_228 & V_333 ) ;
if ( V_138 -> V_334 -> V_335 &&
( ! ( V_228 & V_336 ) || ! ( V_228 & V_337 ) ) ) {
F_2 ( L_73
L_74 , V_228 ) ;
return 0 ;
}
switch ( V_228 ) {
case V_338 :
V_290 = F_100 ( V_137 ) ;
if ( ! V_290 )
break;
V_232 = F_102 ( V_290 ) ;
V_232 -> V_328 = V_328 ;
V_232 -> V_329 = V_329 ;
V_232 -> V_330 = V_330 ;
V_232 -> V_331 = V_331 ;
V_13 = F_103 ( V_4 , V_232 , V_290 ,
V_53 , ( unsigned char * ) V_294 ) ;
break;
case V_339 :
V_290 = F_100 ( V_137 ) ;
if ( ! V_290 )
break;
V_232 = F_102 ( V_290 ) ;
V_13 = F_116 ( V_4 , V_232 , V_290 ,
V_53 , ( unsigned char * ) V_294 ) ;
break;
case V_340 :
V_13 = F_112 ( V_4 , V_53 ,
( unsigned char * ) V_294 ) ;
break;
case V_341 :
V_290 = F_100 ( V_137 ) ;
if ( ! V_290 )
break;
V_13 = F_123 ( V_137 , V_290 ,
( unsigned char * ) V_294 ) ;
break;
case V_337 :
V_290 = F_100 ( V_137 ) ;
if ( ! V_290 )
break;
V_13 = F_124 ( V_137 , V_290 , ( unsigned char * ) V_294 ) ;
if ( V_13 > 0 )
F_125 ( & V_137 -> V_342 ,
V_343 *
V_344 ) ;
break;
case V_336 :
V_290 = F_100 ( V_137 ) ;
if ( ! V_290 )
break;
V_232 = F_102 ( V_290 ) ;
V_13 = F_119 ( V_4 , V_232 , V_290 ,
V_53 , (struct V_324 * ) V_294 ) ;
break;
default:
F_2 ( L_75 , V_228 ) ;
F_80 () ;
break;
}
return V_13 ;
}
static void
F_126 ( struct V_52 * V_53 , struct V_4 * V_4 )
{
struct V_234 * V_234 = & V_53 -> V_233 ;
T_4 V_329 = 0 , V_331 = 0 ;
T_3 V_328 = 0 , V_330 = 0 ;
int V_301 ;
switch ( V_234 -> V_129 & 0xF0 ) {
case V_345 :
if ( V_234 -> V_129 & V_346 ) {
V_328 = F_97 ( V_234 -> V_328 ) ;
V_329 = F_127 ( V_234 -> V_329 ) ;
F_7 ( L_76 ,
V_328 , ( unsigned long long ) V_329 ) ;
}
if ( V_234 -> V_129 & V_347 ) {
V_330 = F_97 ( V_234 -> V_330 ) ;
V_331 = F_127 ( V_234 -> V_331 ) ;
F_7 ( L_77 ,
V_330 , ( unsigned long long ) V_331 ) ;
}
F_7 ( L_78 ) ;
break;
case V_348 :
F_2 ( L_79 ) ;
break;
default:
F_4 ( L_80 , V_234 -> V_129 ) ;
break;
}
V_301 = F_122 ( V_4 , V_53 ,
V_328 , V_329 , V_330 , V_331 ) ;
}
static void
F_128 ( struct V_52 * V_349 , struct V_4 * V_4 ,
unsigned long V_350 )
{
struct V_9 * V_10 = V_4 -> V_7 -> V_20 ;
struct V_254 * V_294 ;
T_2 V_351 ;
int V_261 , V_352 ;
if ( ( char * ) V_349 == V_4 -> V_170 ) {
V_351 = V_4 -> V_172 ;
V_261 = V_168 ;
F_7 ( L_81 ,
V_351 , V_261 ) ;
} else {
V_351 = V_349 -> V_56 ;
V_261 = V_62 ;
F_7 ( L_82 ,
V_351 , V_261 ) ;
}
F_89 ( V_10 , V_351 , V_261 , V_63 ) ;
V_294 = & V_349 -> V_252 ;
F_7 ( L_83 ,
V_294 -> V_228 , V_294 -> V_279 , V_294 -> V_129 ,
( int ) ( V_350 - V_226 ) ) ;
if ( ( char * ) V_349 == V_4 -> V_170 )
F_96 ( V_349 , V_350 - V_226 ,
V_4 ) ;
else
F_126 ( V_349 , V_4 ) ;
F_84 ( V_10 , V_351 , V_261 ,
V_63 ) ;
V_4 -> V_200 -- ;
F_7 ( L_84 ,
V_4 -> V_200 ) ;
if ( ( char * ) V_349 == V_4 -> V_170 )
return;
V_352 = V_4 -> V_200 ;
if ( V_352 + V_259 <= V_39 ) {
int V_146 , V_211 = F_23 ( V_39 - V_352 ,
V_259 ) ;
V_146 = F_81 ( V_4 , V_211 ) ;
if ( V_146 ) {
F_2 ( L_85 ,
V_211 , V_146 ) ;
}
}
}
static int
F_129 ( struct V_4 * V_4 , struct V_232 * V_232 ,
struct V_295 * V_296 , V_142 V_353 , V_142 V_66 , V_142 V_354 ,
enum V_355 V_356 , struct V_357 * V_287 )
{
struct V_9 * V_10 = V_4 -> V_7 -> V_20 ;
V_287 -> V_358 = V_356 == V_359 ?
V_175 : V_63 ;
V_287 -> V_360 = V_66 - V_354 ;
V_287 -> V_354 = V_354 ;
V_287 -> V_321 = V_287 -> V_354 / V_309 ;
V_287 -> V_296 = & V_296 [ V_287 -> V_321 ] ;
V_287 -> V_353 = F_21 (unsigned int, nents - data->sg_off,
ISCSI_ISER_SG_TABLESIZE) ;
V_287 -> V_360 = F_21 (unsigned int, data->len, ISCSI_ISER_SG_TABLESIZE *
PAGE_SIZE) ;
V_287 -> V_361 = F_130 ( V_10 , V_287 -> V_296 , V_287 -> V_353 ,
V_287 -> V_358 ) ;
if ( F_131 ( ! V_287 -> V_361 ) ) {
F_2 ( L_86 , V_296 ) ;
return - V_185 ;
}
F_7 ( L_87 ,
V_232 , V_287 -> V_361 , V_287 -> V_296 , V_287 -> V_353 , V_287 -> V_360 ) ;
return 0 ;
}
static void
F_132 ( struct V_4 * V_4 , struct V_357 * V_287 )
{
struct V_9 * V_10 = V_4 -> V_7 -> V_20 ;
F_133 ( V_10 , V_287 -> V_296 , V_287 -> V_353 , V_287 -> V_358 ) ;
memset ( V_287 , 0 , sizeof( * V_287 ) ) ;
}
static void
V_82 ( struct V_232 * V_232 , struct V_4 * V_4 )
{
struct V_362 * V_363 = & V_232 -> V_237 ;
F_7 ( L_88 , V_232 ) ;
if ( V_363 -> V_287 . V_296 ) {
F_7 ( L_89 , V_232 ) ;
F_132 ( V_4 , & V_363 -> V_287 ) ;
}
if ( V_363 -> V_224 ) {
F_7 ( L_90 , V_232 ) ;
F_18 ( V_363 -> V_224 ) ;
V_363 -> V_224 = NULL ;
}
if ( V_363 -> V_54 ) {
F_7 ( L_91 , V_232 ) ;
F_18 ( V_363 -> V_54 ) ;
V_363 -> V_54 = NULL ;
}
}
static void
V_80 ( struct V_232 * V_232 , struct V_4 * V_4 )
{
struct V_362 * V_363 = & V_232 -> V_237 ;
F_134 ( V_364 ) ;
F_7 ( L_92 , V_232 ) ;
if ( V_363 -> V_103 ) {
F_7 ( L_93 ,
V_232 , V_363 -> V_103 ) ;
if ( V_363 -> V_103 -> V_119 & V_133 ) {
F_132 ( V_4 , & V_363 -> V_365 ) ;
V_363 -> V_103 -> V_119 &= ~ V_133 ;
}
F_52 ( & V_4 -> V_162 ) ;
F_38 ( & V_363 -> V_103 -> V_106 , & V_4 -> V_105 ) ;
F_53 ( & V_4 -> V_162 ) ;
V_363 -> V_103 = NULL ;
}
if ( V_363 -> V_287 . V_296 ) {
F_7 ( L_94 , V_232 ) ;
F_132 ( V_4 , & V_363 -> V_287 ) ;
}
V_363 -> V_54 = NULL ;
V_363 -> V_224 = NULL ;
}
static void
F_135 ( struct V_232 * V_232 , bool V_366 )
{
struct V_289 * V_290 = V_232 -> V_289 ;
struct V_4 * V_4 = V_232 -> V_137 ;
struct V_248 * V_137 = V_4 -> V_137 ;
struct V_19 * V_20 = V_4 -> V_21 ;
F_7 ( L_95 , V_232 ) ;
switch ( V_290 -> V_367 ) {
case V_338 :
F_52 ( & V_137 -> V_368 ) ;
if ( ! F_40 ( & V_290 -> V_369 ) )
F_136 ( & V_290 -> V_369 ) ;
F_53 ( & V_137 -> V_368 ) ;
if ( V_290 -> V_370 == V_175 ) {
F_137 ( V_290 ) ;
if ( V_366 &&
V_290 -> V_307 . V_371 == V_372 ) {
struct V_307 * V_307 = & V_290 -> V_307 ;
F_111 ( V_307 -> V_136 , V_307 ) ;
}
}
V_20 -> V_79 ( V_232 , V_4 ) ;
F_138 ( & V_290 -> V_307 , 0 ) ;
break;
case V_341 :
F_52 ( & V_137 -> V_368 ) ;
if ( ! F_40 ( & V_290 -> V_369 ) )
F_136 ( & V_290 -> V_369 ) ;
F_53 ( & V_137 -> V_368 ) ;
F_138 ( & V_290 -> V_307 , 0 ) ;
break;
case V_373 :
case V_339 :
case V_336 :
F_52 ( & V_137 -> V_368 ) ;
if ( ! F_40 ( & V_290 -> V_369 ) )
F_136 ( & V_290 -> V_369 ) ;
F_53 ( & V_137 -> V_368 ) ;
if ( V_290 -> V_307 . V_374 != NULL ) {
F_7 ( L_96
L_97 ,
V_290 -> V_367 ) ;
F_138 ( & V_290 -> V_307 , 0 ) ;
break;
}
default:
F_139 ( V_290 ) ;
break;
}
}
static void
F_140 ( struct V_221 * V_222 , struct V_9 * V_10 )
{
if ( V_222 -> V_56 != 0 ) {
F_7 ( L_98 ) ;
F_17 ( V_10 , V_222 -> V_56 ,
V_226 , V_175 ) ;
V_222 -> V_56 = 0 ;
}
}
static void
F_141 ( struct V_221 * V_222 , struct V_232 * V_232 ,
struct V_9 * V_10 , bool V_366 )
{
if ( V_232 -> V_375 != 0 ) {
F_7 ( L_99 ) ;
F_17 ( V_10 , V_232 -> V_375 ,
V_232 -> V_376 , V_175 ) ;
V_232 -> V_375 = 0 ;
}
F_140 ( V_222 , V_10 ) ;
F_135 ( V_232 , V_366 ) ;
}
static int
F_142 ( struct V_307 * V_307 , struct V_377 * V_112 )
{
struct V_378 V_379 ;
int V_13 ;
V_13 = F_143 ( V_112 , V_380 , & V_379 ) ;
if ( V_13 ) {
F_2 ( L_100 , V_13 ) ;
goto V_381;
}
if ( V_379 . V_382 & V_380 ) {
T_2 V_383 ;
V_142 V_384 = V_307 -> V_385 -> V_386 . V_384 + 8 ;
switch ( V_379 . V_387 . V_388 ) {
case V_389 :
V_307 -> V_390 = V_391 ;
break;
case V_392 :
V_307 -> V_390 = V_393 ;
break;
case V_394 :
V_307 -> V_390 = V_395 ;
break;
}
V_383 = V_379 . V_387 . V_396 ;
F_144 ( V_383 , V_384 ) ;
V_307 -> V_397 = V_383 + V_307 -> V_398 ;
F_2 ( L_101
L_102 ,
V_379 . V_387 . V_388 ,
( unsigned long long ) V_307 -> V_397 ,
V_379 . V_387 . V_399 ,
V_379 . V_387 . V_400 ) ;
V_13 = 1 ;
}
V_381:
return V_13 ;
}
static void
F_145 ( struct V_221 * V_222 ,
struct V_232 * V_232 )
{
struct V_362 * V_363 = & V_232 -> V_237 ;
struct V_289 * V_290 = V_232 -> V_289 ;
struct V_307 * V_307 = & V_290 -> V_307 ;
struct V_4 * V_4 = V_232 -> V_137 ;
struct V_19 * V_20 = V_4 -> V_21 ;
int V_13 = 0 ;
if ( V_363 -> V_103 && V_363 -> V_103 -> V_119 & V_133 ) {
V_13 = F_142 ( V_307 ,
V_363 -> V_103 -> V_109 -> V_112 ) ;
V_363 -> V_103 -> V_119 &= ~ V_133 ;
}
V_20 -> V_79 ( V_232 , V_4 ) ;
V_363 -> V_401 = 0 ;
if ( V_13 )
F_146 ( V_307 ,
V_307 -> V_390 , 0 ) ;
else
F_147 ( V_4 -> V_137 , V_290 ) ;
}
static void
F_148 ( struct V_221 * V_222 ,
struct V_232 * V_232 )
{
struct V_362 * V_363 = & V_232 -> V_237 ;
struct V_289 * V_290 = V_232 -> V_289 ;
struct V_307 * V_307 = & V_290 -> V_307 ;
struct V_4 * V_4 = V_232 -> V_137 ;
struct V_19 * V_20 = V_4 -> V_21 ;
int V_13 = 0 ;
if ( V_363 -> V_103 && V_363 -> V_103 -> V_119 & V_133 ) {
V_13 = F_142 ( V_307 ,
V_363 -> V_103 -> V_109 -> V_112 ) ;
V_363 -> V_103 -> V_119 &= ~ V_133 ;
}
F_137 ( V_290 ) ;
V_20 -> V_79 ( V_232 , V_4 ) ;
V_290 -> V_310 = V_363 -> V_287 . V_360 ;
V_363 -> V_401 = 0 ;
F_7 ( L_103 , V_232 ) ;
F_52 ( & V_290 -> V_312 ) ;
V_290 -> V_313 |= V_314 ;
V_290 -> V_315 = V_316 ;
F_53 ( & V_290 -> V_312 ) ;
if ( V_13 )
F_146 ( V_307 ,
V_307 -> V_390 , 0 ) ;
else
F_149 ( V_307 ) ;
}
static void
F_150 ( struct V_195 * V_196 )
{
struct V_232 * V_232 = F_69 ( V_196 ,
struct V_232 , V_402 ) ;
struct V_4 * V_4 = V_232 -> V_137 ;
struct V_9 * V_10 = V_4 -> V_7 -> V_20 ;
struct V_289 * V_290 = V_232 -> V_289 ;
switch ( V_290 -> V_315 ) {
case V_403 :
F_7 ( L_104 ) ;
F_87 ( & V_4 -> V_201 ) ;
F_151 ( V_290 , V_290 -> V_137 ) ;
V_290 -> V_315 = V_404 ;
F_141 ( & V_232 -> V_222 , V_232 , V_10 , false ) ;
break;
case V_405 :
F_7 ( L_105 ) ;
F_87 ( & V_4 -> V_201 ) ;
V_290 -> V_315 = V_404 ;
F_141 ( & V_232 -> V_222 , V_232 , V_10 , false ) ;
break;
case V_406 :
F_7 ( L_106 ) ;
V_4 -> V_203 = true ;
F_152 ( V_290 , V_290 -> V_137 ) ;
break;
case V_407 :
F_87 ( & V_4 -> V_201 ) ;
V_290 -> V_315 = V_404 ;
F_141 ( & V_232 -> V_222 , V_232 , V_10 , false ) ;
break;
default:
F_2 ( L_107 , V_290 -> V_315 ) ;
F_80 () ;
break;
}
}
static void
F_153 ( struct V_221 * V_222 ,
struct V_232 * V_232 ,
struct V_4 * V_4 ,
struct V_9 * V_10 )
{
struct V_289 * V_290 = V_232 -> V_289 ;
struct V_362 * V_363 = & V_232 -> V_237 ;
if ( V_290 -> V_315 == V_403 ||
V_290 -> V_315 == V_406 ||
V_290 -> V_315 == V_405 ||
V_290 -> V_315 == V_407 ) {
F_140 ( V_222 , V_10 ) ;
F_24 ( & V_232 -> V_402 , F_150 ) ;
F_154 ( V_408 , & V_232 -> V_402 ) ;
return;
}
if ( V_363 -> V_401 )
F_155 ( V_363 -> V_401 , & V_4 -> V_201 ) ;
else
F_87 ( & V_4 -> V_201 ) ;
V_290 -> V_315 = V_404 ;
F_141 ( V_222 , V_232 , V_10 , false ) ;
}
static void
F_156 ( struct V_221 * V_222 ,
struct V_4 * V_4 )
{
struct V_9 * V_10 = V_4 -> V_7 -> V_20 ;
struct V_232 * V_232 = V_222 -> V_232 ;
struct V_362 * V_363 ;
if ( ! V_232 ) {
F_87 ( & V_4 -> V_201 ) ;
F_140 ( V_222 , V_10 ) ;
return;
}
V_363 = & V_232 -> V_237 ;
switch ( V_363 -> V_238 ) {
case V_409 :
F_2 ( L_108 ) ;
F_80 () ;
break;
case V_239 :
F_7 ( L_109 ) ;
F_153 ( V_222 , V_232 ,
V_4 , V_10 ) ;
break;
case V_359 :
F_7 ( L_110 ) ;
F_155 ( V_363 -> V_401 , & V_4 -> V_201 ) ;
F_145 ( V_222 , V_232 ) ;
break;
case V_410 :
F_7 ( L_111 ) ;
F_155 ( V_363 -> V_401 , & V_4 -> V_201 ) ;
F_148 ( V_222 , V_232 ) ;
break;
default:
F_2 ( L_112 , V_363 -> V_238 ) ;
F_80 () ;
break;
}
}
static void
F_157 ( struct V_221 * V_222 ,
struct V_4 * V_4 )
{
struct V_411 * V_412 = V_222 -> V_245 ;
struct V_221 * V_413 ;
while ( V_412 ) {
V_413 = F_158 ( V_412 , struct V_221 , V_243 ) ;
V_412 = F_159 ( V_412 ) ;
F_156 ( V_413 , V_4 ) ;
}
F_156 ( V_222 , V_4 ) ;
}
static void
F_160 ( struct V_4 * V_4 , struct V_9 * V_10 )
{
struct V_411 * V_412 ;
struct V_362 * V_363 ;
struct V_221 * V_413 ;
F_9 ( & V_4 -> V_161 ) ;
V_412 = F_93 ( & V_4 -> V_244 ) ;
V_4 -> V_240 = 0 ;
F_10 ( & V_4 -> V_161 ) ;
while ( V_412 ) {
V_413 = F_158 ( V_412 , struct V_221 , V_243 ) ;
V_412 = F_159 ( V_412 ) ;
V_363 = & V_413 -> V_232 -> V_237 ;
if ( V_363 -> V_401 )
F_155 ( V_363 -> V_401 ,
& V_4 -> V_201 ) ;
else
F_87 ( & V_4 -> V_201 ) ;
F_141 ( V_413 , V_413 -> V_232 , V_10 , true ) ;
}
}
static void
F_161 ( struct V_221 * V_222 , struct V_4 * V_4 )
{
struct V_9 * V_10 = V_4 -> V_7 -> V_20 ;
struct V_232 * V_232 = V_222 -> V_232 ;
struct V_411 * V_412 = V_222 -> V_245 ;
struct V_362 * V_363 ;
struct V_221 * V_413 ;
while ( V_412 ) {
V_413 = F_158 ( V_412 , struct V_221 , V_243 ) ;
V_412 = F_159 ( V_412 ) ;
V_363 = & V_413 -> V_232 -> V_237 ;
if ( V_363 -> V_401 )
F_155 ( V_363 -> V_401 ,
& V_4 -> V_201 ) ;
else
F_87 ( & V_4 -> V_201 ) ;
F_141 ( V_413 , V_413 -> V_232 , V_10 , true ) ;
}
V_222 -> V_245 = NULL ;
if ( ! V_232 )
F_140 ( V_222 , V_10 ) ;
else
F_141 ( V_222 , V_232 , V_10 , true ) ;
}
static void
F_162 ( struct V_4 * V_4 )
{
struct V_9 * V_10 = V_4 -> V_7 -> V_20 ;
struct V_248 * V_137 = V_4 -> V_137 ;
if ( V_4 -> V_200 )
return;
F_160 ( V_4 , V_10 ) ;
if ( V_137 -> V_138 ) {
F_163 ( V_137 -> V_138 -> V_136 ) ;
F_164 ( V_137 -> V_138 -> V_136 ) ;
}
while ( F_73 ( & V_4 -> V_201 ) )
F_165 ( 3000 ) ;
F_9 ( & V_4 -> V_161 ) ;
V_4 -> V_154 = V_414 ;
F_10 ( & V_4 -> V_161 ) ;
F_76 ( & V_4 -> V_159 ) ;
}
static void
V_94 ( struct V_195 * V_196 )
{
struct V_71 * V_72 = F_69 ( V_196 ,
struct V_71 , V_93 ) ;
struct V_19 * V_20 = V_72 -> V_20 ;
int V_87 = V_72 -> V_87 ;
struct V_415 * V_416 = V_20 -> V_32 [ V_87 ] ;
struct V_4 * V_4 ;
struct V_221 * V_222 ;
struct V_417 V_418 ;
while ( F_166 ( V_416 , 1 , & V_418 ) == 1 ) {
V_222 = (struct V_221 * ) ( unsigned long ) V_418 . V_217 ;
V_4 = V_418 . V_51 -> V_30 ;
if ( V_418 . V_204 == V_419 ) {
F_157 ( V_222 , V_4 ) ;
} else {
F_7 ( L_113 ) ;
F_7 ( L_114 , V_418 . V_204 ) ;
F_7 ( L_115 , V_418 . V_420 ) ;
if ( V_418 . V_217 != V_421 ) {
if ( V_222 -> V_242 )
continue;
F_87 ( & V_4 -> V_201 ) ;
F_161 ( V_222 , V_4 ) ;
}
}
}
F_28 ( V_416 , V_97 ) ;
}
static void
V_95 ( struct V_415 * V_422 , void * V_3 )
{
struct V_71 * V_72 = (struct V_71 * ) V_3 ;
F_154 ( V_408 , & V_72 -> V_93 ) ;
}
static void
V_89 ( struct V_195 * V_196 )
{
struct V_71 * V_72 = F_69 ( V_196 ,
struct V_71 , V_88 ) ;
struct V_19 * V_20 = V_72 -> V_20 ;
int V_87 = V_72 -> V_87 ;
struct V_415 * V_423 = V_20 -> V_34 [ V_87 ] ;
struct V_4 * V_4 ;
struct V_52 * V_53 ;
struct V_417 V_418 ;
unsigned long V_350 ;
while ( F_166 ( V_423 , 1 , & V_418 ) == 1 ) {
V_53 = (struct V_52 * ) ( unsigned long ) V_418 . V_217 ;
V_4 = V_418 . V_51 -> V_30 ;
if ( V_418 . V_204 == V_419 ) {
V_350 = ( unsigned long ) V_418 . V_424 ;
F_128 ( V_53 , V_4 , V_350 ) ;
} else {
F_7 ( L_116 ) ;
if ( V_418 . V_204 != V_425 ) {
F_7 ( L_117 , V_418 . V_204 ) ;
F_7 ( L_118 ,
V_418 . V_420 ) ;
}
V_4 -> V_200 -- ;
F_162 ( V_4 ) ;
}
}
F_28 ( V_423 , V_97 ) ;
}
static void
V_90 ( struct V_415 * V_422 , void * V_3 )
{
struct V_71 * V_72 = (struct V_71 * ) V_3 ;
F_154 ( V_426 , & V_72 -> V_88 ) ;
}
static int
F_167 ( struct V_4 * V_4 , struct V_232 * V_232 )
{
struct V_223 * V_427 ;
int V_13 ;
F_85 ( & V_4 -> V_201 ) ;
V_13 = F_86 ( V_4 -> V_50 , & V_232 -> V_222 . V_224 ,
& V_427 ) ;
if ( V_13 ) {
F_2 ( L_119 , V_13 ) ;
F_87 ( & V_4 -> V_201 ) ;
return V_13 ;
}
return V_13 ;
}
static int
F_147 ( struct V_248 * V_137 , struct V_289 * V_290 )
{
struct V_232 * V_232 = F_102 ( V_290 ) ;
struct V_4 * V_4 = (struct V_4 * ) V_137 -> V_3 ;
struct V_223 * V_224 = & V_232 -> V_222 . V_224 ;
struct V_428 * V_294 = (struct V_428 * )
& V_232 -> V_222 . V_252 ;
F_88 ( V_4 , V_232 , & V_232 -> V_222 ) ;
F_168 ( V_290 , V_137 , true , V_294 ) ;
F_90 ( V_4 , & V_232 -> V_222 ) ;
if ( V_290 -> V_307 . V_429 &&
( ( V_290 -> V_307 . V_430 & V_431 ) ||
( V_290 -> V_307 . V_430 & V_432 ) ) ) {
struct V_9 * V_10 = V_4 -> V_7 -> V_20 ;
struct V_54 * V_255 = & V_232 -> V_222 . V_227 [ 1 ] ;
V_142 V_433 , V_434 ;
F_169 ( V_290 -> V_307 . V_435 ,
V_290 -> V_429 ) ;
V_290 -> V_307 . V_435 += sizeof( V_436 ) ;
V_433 = - ( V_290 -> V_307 . V_435 ) & 3 ;
F_170 ( V_294 -> V_320 , ( V_142 ) V_290 -> V_307 . V_435 ) ;
V_434 = V_290 -> V_307 . V_435 + V_433 ;
V_232 -> V_375 = F_15 ( V_10 ,
( void * ) V_290 -> V_429 , V_434 ,
V_175 ) ;
V_232 -> V_376 = V_434 ;
V_255 -> V_65 = V_232 -> V_375 ;
V_255 -> V_66 = V_434 ;
V_255 -> V_67 = V_4 -> V_68 -> V_67 ;
V_232 -> V_222 . V_219 = 2 ;
}
F_91 ( V_4 , V_232 , V_224 , true ) ;
F_7 ( L_120 ) ;
return F_167 ( V_4 , V_232 ) ;
}
static void
F_171 ( struct V_248 * V_137 , struct V_289 * V_290 )
{
struct V_232 * V_232 = F_102 ( V_290 ) ;
struct V_4 * V_4 = (struct V_4 * ) V_137 -> V_3 ;
struct V_19 * V_20 = V_4 -> V_21 ;
F_52 ( & V_137 -> V_368 ) ;
if ( ! F_40 ( & V_290 -> V_369 ) )
F_136 ( & V_290 -> V_369 ) ;
F_53 ( & V_137 -> V_368 ) ;
if ( V_290 -> V_370 == V_175 )
F_137 ( V_290 ) ;
V_20 -> V_79 ( V_232 , V_4 ) ;
}
static enum V_437
F_172 ( struct V_248 * V_137 )
{
struct V_4 * V_4 = (struct V_4 * ) V_137 -> V_3 ;
struct V_19 * V_20 = V_4 -> V_21 ;
if ( V_20 -> V_83 )
return V_438 ;
return V_439 ;
}
static int
F_173 ( struct V_289 * V_290 , struct V_248 * V_137 ,
bool V_440 )
{
struct V_232 * V_232 = F_102 ( V_290 ) ;
struct V_4 * V_4 = (struct V_4 * ) V_137 -> V_3 ;
struct V_223 * V_224 = & V_232 -> V_222 . V_224 ;
F_88 ( V_4 , V_232 , & V_232 -> V_222 ) ;
F_174 ( V_290 , V_137 , (struct V_441 * )
& V_232 -> V_222 . V_252 ,
V_440 ) ;
F_90 ( V_4 , & V_232 -> V_222 ) ;
F_91 ( V_4 , V_232 , V_224 , false ) ;
F_7 ( L_121 ) ;
return F_167 ( V_4 , V_232 ) ;
}
static int
F_175 ( struct V_289 * V_290 , struct V_248 * V_137 )
{
struct V_232 * V_232 = F_102 ( V_290 ) ;
struct V_4 * V_4 = (struct V_4 * ) V_137 -> V_3 ;
struct V_223 * V_224 = & V_232 -> V_222 . V_224 ;
F_88 ( V_4 , V_232 , & V_232 -> V_222 ) ;
F_176 ( V_290 , V_137 , (struct V_442 * )
& V_232 -> V_222 . V_252 ) ;
F_90 ( V_4 , & V_232 -> V_222 ) ;
F_91 ( V_4 , V_232 , V_224 , false ) ;
F_7 ( L_122 ) ;
return F_167 ( V_4 , V_232 ) ;
}
static int
F_177 ( struct V_289 * V_290 , struct V_248 * V_137 )
{
struct V_232 * V_232 = F_102 ( V_290 ) ;
struct V_4 * V_4 = (struct V_4 * ) V_137 -> V_3 ;
struct V_223 * V_224 = & V_232 -> V_222 . V_224 ;
F_88 ( V_4 , V_232 , & V_232 -> V_222 ) ;
F_178 ( V_290 , V_137 , (struct V_443 * )
& V_232 -> V_222 . V_252 ) ;
F_90 ( V_4 , & V_232 -> V_222 ) ;
F_91 ( V_4 , V_232 , V_224 , false ) ;
F_7 ( L_123 ) ;
return F_167 ( V_4 , V_232 ) ;
}
static int
F_179 ( struct V_289 * V_290 , struct V_248 * V_137 )
{
struct V_232 * V_232 = F_102 ( V_290 ) ;
struct V_4 * V_4 = (struct V_4 * ) V_137 -> V_3 ;
struct V_223 * V_224 = & V_232 -> V_222 . V_224 ;
struct V_9 * V_10 = V_4 -> V_7 -> V_20 ;
struct V_54 * V_255 = & V_232 -> V_222 . V_227 [ 1 ] ;
struct V_444 * V_294 =
(struct V_444 * ) & V_232 -> V_222 . V_252 ;
F_88 ( V_4 , V_232 , & V_232 -> V_222 ) ;
F_180 ( V_290 , V_137 , V_294 ) ;
F_90 ( V_4 , & V_232 -> V_222 ) ;
F_170 ( V_294 -> V_320 , V_284 ) ;
V_232 -> V_375 = F_15 ( V_10 ,
( void * ) V_290 -> V_445 , V_284 ,
V_175 ) ;
V_232 -> V_376 = V_284 ;
V_255 -> V_65 = V_232 -> V_375 ;
V_255 -> V_66 = V_284 ;
V_255 -> V_67 = V_4 -> V_68 -> V_67 ;
V_232 -> V_222 . V_219 = 2 ;
F_91 ( V_4 , V_232 , V_224 , false ) ;
F_7 ( L_124 ) ;
return F_167 ( V_4 , V_232 ) ;
}
static int
F_181 ( struct V_289 * V_290 , struct V_248 * V_137 )
{
struct V_232 * V_232 = F_102 ( V_290 ) ;
struct V_4 * V_4 = (struct V_4 * ) V_137 -> V_3 ;
struct V_223 * V_224 = & V_232 -> V_222 . V_224 ;
struct V_446 * V_294 =
(struct V_446 * ) & V_232 -> V_222 . V_252 ;
V_142 V_447 ;
int V_301 ;
F_88 ( V_4 , V_232 , & V_232 -> V_222 ) ;
V_301 = F_182 ( V_290 , V_137 , V_294 ) ;
if ( V_301 < 0 )
return V_301 ;
V_447 = V_301 ;
F_90 ( V_4 , & V_232 -> V_222 ) ;
if ( V_447 ) {
struct V_9 * V_10 = V_4 -> V_7 -> V_20 ;
struct V_54 * V_255 = & V_232 -> V_222 . V_227 [ 1 ] ;
void * V_448 = V_290 -> V_445 ;
V_232 -> V_375 = F_15 ( V_10 ,
V_448 , V_447 , V_175 ) ;
V_232 -> V_376 = V_447 ;
V_255 -> V_65 = V_232 -> V_375 ;
V_255 -> V_66 = V_447 ;
V_255 -> V_67 = V_4 -> V_68 -> V_67 ;
V_232 -> V_222 . V_219 = 2 ;
}
F_91 ( V_4 , V_232 , V_224 , false ) ;
F_7 ( L_125 ) ;
return F_167 ( V_4 , V_232 ) ;
}
static int
F_183 ( struct V_4 * V_4 , struct V_232 * V_232 ,
struct V_54 * V_54 , struct V_223 * V_224 ,
V_142 V_449 , V_142 V_354 )
{
struct V_289 * V_290 = V_232 -> V_289 ;
struct V_295 * V_317 , * V_450 ;
struct V_9 * V_10 = V_4 -> V_7 -> V_20 ;
V_142 V_321 , V_322 ;
int V_57 = 0 , V_300 ;
V_321 = V_354 / V_309 ;
V_317 = & V_290 -> V_307 . V_308 [ V_321 ] ;
V_300 = F_23 ( V_290 -> V_307 . V_451 - V_321 , V_4 -> V_14 ) ;
V_322 = V_354 % V_309 ;
V_224 -> V_218 = V_54 ;
V_224 -> V_219 = V_300 ;
V_224 -> V_217 = ( unsigned long ) & V_232 -> V_222 ;
F_184 (sg_start, tmp_sg, sg_nents, i) {
F_7 ( L_126 ,
( unsigned long long ) V_450 -> V_452 ,
V_450 -> V_66 , V_322 ) ;
V_54 -> V_65 = F_185 ( V_10 , V_450 ) + V_322 ;
V_54 -> V_66 = F_21 ( V_142 , V_449 ,
F_186 ( V_10 , V_450 ) - V_322 ) ;
V_54 -> V_67 = V_4 -> V_68 -> V_67 ;
F_7 ( L_127 ,
V_54 -> V_65 , V_54 -> V_66 , V_54 -> V_67 ) ;
V_322 = 0 ;
V_449 -= V_54 -> V_66 ;
V_54 ++ ;
F_7 ( L_128 , V_54 ) ;
}
F_7 ( L_129 ,
V_224 -> V_218 , V_224 -> V_219 ) ;
return V_300 ;
}
static int
V_81 ( struct V_248 * V_137 , struct V_289 * V_290 ,
struct V_362 * V_363 )
{
struct V_307 * V_307 = & V_290 -> V_307 ;
struct V_232 * V_232 = F_102 ( V_290 ) ;
struct V_4 * V_4 = (struct V_4 * ) V_137 -> V_3 ;
struct V_357 * V_287 = & V_363 -> V_287 ;
struct V_223 * V_224 ;
struct V_54 * V_54 ;
V_142 V_354 , V_453 , V_449 , V_454 , V_455 = 0 ;
int V_13 = 0 , V_57 , V_456 ;
V_232 -> V_222 . V_232 = V_232 ;
V_354 = V_363 -> V_238 == V_410 ? V_290 -> V_310 : 0 ;
V_13 = F_129 ( V_4 , V_232 , V_307 -> V_308 ,
V_307 -> V_451 , V_307 -> V_311 ,
V_354 , V_363 -> V_238 , & V_363 -> V_287 ) ;
if ( V_13 )
return V_13 ;
V_449 = V_287 -> V_360 ;
V_354 = V_287 -> V_354 ;
V_54 = F_14 ( sizeof( struct V_54 ) * V_287 -> V_353 , V_60 ) ;
if ( ! V_54 ) {
F_4 ( L_130 ) ;
V_13 = - V_70 ;
goto V_457;
}
V_363 -> V_54 = V_54 ;
V_363 -> V_401 = F_107 ( V_287 -> V_353 , V_4 -> V_14 ) ;
V_363 -> V_224 = F_14 ( sizeof( struct V_223 ) * V_363 -> V_401 ,
V_60 ) ;
if ( ! V_363 -> V_224 ) {
F_7 ( L_131 ) ;
V_13 = - V_70 ;
goto V_457;
}
V_363 -> V_232 = V_232 ;
V_454 = V_4 -> V_14 * V_309 ;
for ( V_57 = 0 ; V_57 < V_363 -> V_401 ; V_57 ++ ) {
V_224 = & V_232 -> V_237 . V_224 [ V_57 ] ;
V_453 = F_23 ( V_449 , V_454 ) ;
V_224 -> V_230 = 0 ;
if ( V_363 -> V_238 == V_359 ) {
V_224 -> V_228 = V_458 ;
V_224 -> V_363 . V_459 . V_460 = V_232 -> V_329 + V_354 ;
V_224 -> V_363 . V_459 . V_461 = V_232 -> V_328 ;
if ( V_57 + 1 == V_363 -> V_401 )
V_224 -> V_220 = & V_232 -> V_222 . V_224 ;
else
V_224 -> V_220 = & V_363 -> V_224 [ V_57 + 1 ] ;
} else {
V_224 -> V_228 = V_462 ;
V_224 -> V_363 . V_459 . V_460 = V_232 -> V_331 + V_455 ;
V_224 -> V_363 . V_459 . V_461 = V_232 -> V_330 ;
if ( V_57 + 1 == V_363 -> V_401 )
V_224 -> V_230 = V_231 ;
else
V_224 -> V_220 = & V_363 -> V_224 [ V_57 + 1 ] ;
}
V_456 = F_183 ( V_4 , V_232 , V_54 ,
V_224 , V_453 , V_354 ) ;
V_54 += V_456 ;
V_354 += V_453 ;
V_455 += V_453 ;
V_449 -= V_453 ;
}
return 0 ;
V_457:
F_132 ( V_4 , V_287 ) ;
return V_13 ;
}
static int
F_187 ( struct V_9 * V_10 ,
struct V_295 * V_317 , int V_300 , T_2 * V_463 )
{
T_2 V_464 , V_465 , V_466 , V_467 = 0 ;
struct V_295 * V_450 ;
int V_57 = 0 , V_468 , V_469 , V_470 ;
V_470 = 0 ;
V_468 = 1 ;
V_469 = V_300 - 1 ;
F_184 (sg_start, tmp_sg, sg_nents, i) {
V_464 = F_185 ( V_10 , V_450 ) ;
if ( V_468 )
V_467 = V_464 ;
V_465 = V_464 + F_186 ( V_10 , V_450 ) ;
F_7 ( L_132 ,
V_57 , ( unsigned long long ) V_450 -> V_452 ,
V_450 -> V_66 ) ;
if ( ( V_465 & ~ V_471 ) && V_57 < V_469 ) {
V_468 = 0 ;
continue;
}
V_468 = 1 ;
V_466 = V_467 & V_471 ;
do {
V_463 [ V_470 ++ ] = V_466 ;
F_7 ( L_133 ,
V_470 - 1 , V_466 ) ;
V_466 += V_309 ;
} while ( V_466 < V_465 );
}
return V_470 ;
}
static int
F_188 ( struct V_4 * V_4 ,
struct V_102 * V_103 ,
struct V_357 * V_472 ,
enum V_473 V_119 ,
struct V_54 * V_247 )
{
struct V_9 * V_10 = V_4 -> V_7 -> V_20 ;
struct V_377 * V_474 ;
struct V_475 * V_476 ;
struct V_223 V_477 , V_478 ;
struct V_223 * V_479 , * V_363 = NULL ;
int V_13 , V_480 ;
V_142 V_322 ;
T_1 V_481 ;
if ( V_472 -> V_361 == 1 ) {
V_247 -> V_67 = V_4 -> V_68 -> V_67 ;
V_247 -> V_65 = F_185 ( V_10 , & V_472 -> V_296 [ 0 ] ) ;
V_247 -> V_66 = F_186 ( V_10 , & V_472 -> V_296 [ 0 ] ) ;
F_7 ( L_134 ,
V_482 , __LINE__ , V_247 -> V_65 , V_247 -> V_66 ,
V_247 -> V_67 ) ;
return 0 ;
}
if ( V_119 == V_120 ) {
V_474 = V_103 -> V_108 ;
V_476 = V_103 -> V_107 ;
} else {
V_474 = V_103 -> V_109 -> V_111 ;
V_476 = V_103 -> V_109 -> V_110 ;
}
V_322 = V_472 -> V_354 % V_309 ;
F_7 ( L_135 ,
V_103 , V_472 -> V_353 , V_472 -> V_354 ) ;
V_480 = F_187 ( V_10 , V_472 -> V_296 , V_472 -> V_353 ,
& V_476 -> V_118 [ 0 ] ) ;
if ( ! ( V_103 -> V_119 & V_120 ) ) {
memset ( & V_478 , 0 , sizeof( V_478 ) ) ;
V_478 . V_217 = V_421 ;
V_478 . V_228 = V_483 ;
V_478 . V_484 . V_485 = V_474 -> V_461 ;
V_363 = & V_478 ;
V_481 = ( T_1 ) ( V_474 -> V_461 & 0x000000FF ) ;
F_189 ( V_474 , ++ V_481 ) ;
}
memset ( & V_477 , 0 , sizeof( V_477 ) ) ;
V_477 . V_217 = V_421 ;
V_477 . V_228 = V_486 ;
V_477 . V_363 . V_487 . V_488 = V_476 -> V_118 [ 0 ] + V_322 ;
V_477 . V_363 . V_487 . V_118 = V_476 ;
V_477 . V_363 . V_487 . V_489 = V_480 ;
V_477 . V_363 . V_487 . V_490 = V_491 ;
V_477 . V_363 . V_487 . V_66 = V_472 -> V_360 ;
V_477 . V_363 . V_487 . V_461 = V_474 -> V_461 ;
V_477 . V_363 . V_487 . V_492 = V_179 ;
if ( ! V_363 )
V_363 = & V_477 ;
else
V_363 -> V_220 = & V_477 ;
V_13 = F_86 ( V_4 -> V_50 , V_363 , & V_479 ) ;
if ( V_13 ) {
F_2 ( L_136 , V_13 ) ;
return V_13 ;
}
V_103 -> V_119 &= ~ V_119 ;
V_247 -> V_67 = V_474 -> V_67 ;
V_247 -> V_65 = V_476 -> V_118 [ 0 ] + V_322 ;
V_247 -> V_66 = V_472 -> V_360 ;
F_7 ( L_134 ,
V_482 , __LINE__ , V_247 -> V_65 , V_247 -> V_66 ,
V_247 -> V_67 ) ;
return V_13 ;
}
static inline enum V_493
F_190 ( enum V_494 V_495 )
{
switch ( V_495 ) {
case V_496 :
return V_497 ;
case V_498 :
return V_499 ;
case V_500 :
return V_501 ;
case V_502 :
return V_503 ;
default:
return V_497 ;
}
}
static int
F_191 ( struct V_307 * V_307 , struct V_504 * V_505 )
{
enum V_493 V_506 = F_190 ( V_307 -> V_495 ) ;
V_505 -> V_472 . V_507 = V_508 ;
V_505 -> V_509 . V_507 = V_508 ;
V_505 -> V_472 . V_510 . V_511 . V_512 =
V_307 -> V_385 -> V_386 . V_384 ;
V_505 -> V_509 . V_510 . V_511 . V_512 =
V_307 -> V_385 -> V_386 . V_384 ;
switch ( V_307 -> V_513 ) {
case V_514 :
case V_515 :
V_505 -> V_472 . V_510 . V_511 . type = V_497 ;
V_505 -> V_509 . V_510 . V_511 . type = V_506 ;
V_505 -> V_509 . V_510 . V_511 . V_516 = V_517 ;
V_505 -> V_509 . V_510 . V_511 . V_518 = V_307 -> V_519 ;
break;
case V_520 :
case V_521 :
V_505 -> V_472 . V_510 . V_511 . type = V_506 ;
V_505 -> V_472 . V_510 . V_511 . V_516 = V_517 ;
V_505 -> V_472 . V_510 . V_511 . V_518 = V_307 -> V_519 ;
V_505 -> V_509 . V_510 . V_511 . type = V_497 ;
break;
case V_522 :
case V_523 :
V_505 -> V_472 . V_510 . V_511 . type = V_506 ;
V_505 -> V_472 . V_510 . V_511 . V_516 = V_517 ;
V_505 -> V_472 . V_510 . V_511 . V_518 = V_307 -> V_519 ;
V_505 -> V_509 . V_510 . V_511 . type = V_506 ;
V_505 -> V_509 . V_510 . V_511 . V_516 = V_517 ;
V_505 -> V_509 . V_510 . V_511 . V_518 = V_307 -> V_519 ;
break;
default:
F_2 ( L_137 , V_307 -> V_513 ) ;
return - V_185 ;
}
return 0 ;
}
static inline T_1
F_192 ( T_1 V_524 )
{
return ( V_524 & V_525 ? 0xc0 : 0 ) |
( V_524 & V_526 ? 0x30 : 0 ) |
( V_524 & V_526 ? 0x0f : 0 ) ;
}
static int
F_193 ( struct V_4 * V_4 , struct V_307 * V_307 ,
struct V_102 * V_103 ,
struct V_54 * V_527 , struct V_54 * V_528 ,
struct V_54 * V_529 )
{
struct V_223 V_530 , V_478 ;
struct V_223 * V_479 , * V_363 = NULL ;
struct V_123 * V_109 = V_103 -> V_109 ;
struct V_504 V_505 ;
int V_13 ;
V_142 V_481 ;
memset ( & V_505 , 0 , sizeof( V_505 ) ) ;
V_13 = F_191 ( V_307 , & V_505 ) ;
if ( V_13 )
goto V_146;
V_505 . V_531 = F_192 ( V_307 -> V_524 ) ;
if ( ! ( V_103 -> V_119 & V_132 ) ) {
memset ( & V_478 , 0 , sizeof( V_478 ) ) ;
V_478 . V_228 = V_483 ;
V_478 . V_217 = V_421 ;
V_478 . V_484 . V_485 = V_109 -> V_112 -> V_461 ;
V_363 = & V_478 ;
V_481 = ( T_1 ) ( V_109 -> V_112 -> V_461 & 0x000000FF ) ;
F_189 ( V_109 -> V_112 , ++ V_481 ) ;
}
memset ( & V_530 , 0 , sizeof( V_530 ) ) ;
V_530 . V_228 = V_532 ;
V_530 . V_217 = V_421 ;
V_530 . V_218 = V_527 ;
V_530 . V_219 = 1 ;
V_530 . V_363 . V_533 . V_492 = V_179 ;
V_530 . V_363 . V_533 . V_505 = & V_505 ;
V_530 . V_363 . V_533 . V_112 = V_109 -> V_112 ;
if ( V_307 -> V_534 )
V_530 . V_363 . V_533 . V_365 = V_528 ;
if ( ! V_363 )
V_363 = & V_530 ;
else
V_363 -> V_220 = & V_530 ;
V_13 = F_86 ( V_4 -> V_50 , V_363 , & V_479 ) ;
if ( V_13 ) {
F_2 ( L_136 , V_13 ) ;
goto V_146;
}
V_103 -> V_119 &= ~ V_132 ;
V_529 -> V_67 = V_109 -> V_112 -> V_67 ;
V_529 -> V_65 = 0 ;
V_529 -> V_66 = V_307 -> V_311 ;
if ( V_307 -> V_513 != V_521 &&
V_307 -> V_513 != V_520 )
V_529 -> V_66 += V_307 -> V_535 ;
F_7 ( L_138 ,
V_529 -> V_65 , V_529 -> V_66 ,
V_529 -> V_67 ) ;
V_146:
return V_13 ;
}
static int
V_78 ( struct V_248 * V_137 , struct V_289 * V_290 ,
struct V_362 * V_363 )
{
struct V_307 * V_307 = & V_290 -> V_307 ;
struct V_232 * V_232 = F_102 ( V_290 ) ;
struct V_4 * V_4 = V_137 -> V_3 ;
struct V_54 V_527 ;
struct V_223 * V_224 ;
struct V_102 * V_103 = NULL ;
V_142 V_354 ;
int V_13 = 0 ;
unsigned long V_129 ;
V_232 -> V_222 . V_232 = V_232 ;
V_354 = V_363 -> V_238 == V_410 ? V_290 -> V_310 : 0 ;
V_13 = F_129 ( V_4 , V_232 , V_307 -> V_308 ,
V_307 -> V_451 , V_307 -> V_311 ,
V_354 , V_363 -> V_238 , & V_363 -> V_287 ) ;
if ( V_13 )
return V_13 ;
if ( V_363 -> V_287 . V_361 != 1 ||
V_307 -> V_513 != V_439 ) {
F_194 ( & V_4 -> V_162 , V_129 ) ;
V_103 = F_195 ( & V_4 -> V_105 ,
struct V_102 , V_106 ) ;
F_33 ( & V_103 -> V_106 ) ;
F_196 ( & V_4 -> V_162 , V_129 ) ;
V_363 -> V_103 = V_103 ;
}
V_13 = F_188 ( V_4 , V_103 , & V_363 -> V_287 ,
V_120 , & V_527 ) ;
if ( V_13 )
goto V_457;
if ( V_307 -> V_513 != V_439 ) {
struct V_54 V_528 , V_529 ;
if ( V_307 -> V_534 ) {
V_13 = F_129 ( V_4 , V_232 ,
V_307 -> V_534 ,
V_307 -> V_536 ,
V_307 -> V_535 ,
0 , V_363 -> V_238 , & V_363 -> V_365 ) ;
if ( V_13 )
goto V_457;
V_13 = F_188 ( V_4 , V_103 , & V_363 -> V_365 ,
V_127 , & V_528 ) ;
if ( V_13 )
goto V_537;
}
V_13 = F_193 ( V_4 , V_307 , V_103 ,
& V_527 , & V_528 , & V_529 ) ;
if ( V_13 )
goto V_537;
V_103 -> V_119 |= V_133 ;
memcpy ( & V_363 -> V_538 , & V_529 , sizeof( V_529 ) ) ;
} else
memcpy ( & V_363 -> V_538 , & V_527 , sizeof( V_527 ) ) ;
V_363 -> V_54 = & V_363 -> V_538 ;
V_363 -> V_401 = 1 ;
memset ( & V_363 -> V_539 , 0 , sizeof( * V_224 ) ) ;
V_363 -> V_224 = & V_363 -> V_539 ;
V_363 -> V_232 = V_232 ;
V_224 = & V_232 -> V_237 . V_539 ;
V_224 -> V_218 = & V_363 -> V_538 ;
V_224 -> V_219 = 1 ;
V_224 -> V_217 = ( unsigned long ) & V_232 -> V_222 ;
if ( V_363 -> V_238 == V_359 ) {
V_224 -> V_228 = V_458 ;
V_224 -> V_363 . V_459 . V_460 = V_232 -> V_329 ;
V_224 -> V_363 . V_459 . V_461 = V_232 -> V_328 ;
V_224 -> V_230 = V_307 -> V_513 == V_439 ?
0 : V_231 ;
} else {
V_224 -> V_228 = V_462 ;
V_224 -> V_363 . V_459 . V_460 = V_232 -> V_331 ;
V_224 -> V_363 . V_459 . V_461 = V_232 -> V_330 ;
V_224 -> V_230 = V_231 ;
}
return 0 ;
V_537:
if ( V_307 -> V_534 )
F_132 ( V_4 , & V_363 -> V_365 ) ;
V_457:
if ( V_103 ) {
F_194 ( & V_4 -> V_162 , V_129 ) ;
F_38 ( & V_103 -> V_106 , & V_4 -> V_105 ) ;
F_196 ( & V_4 -> V_162 , V_129 ) ;
}
F_132 ( V_4 , & V_363 -> V_287 ) ;
return V_13 ;
}
static int
F_197 ( struct V_248 * V_137 , struct V_289 * V_290 )
{
struct V_307 * V_307 = & V_290 -> V_307 ;
struct V_232 * V_232 = F_102 ( V_290 ) ;
struct V_362 * V_363 = & V_232 -> V_237 ;
struct V_4 * V_4 = (struct V_4 * ) V_137 -> V_3 ;
struct V_19 * V_20 = V_4 -> V_21 ;
struct V_223 * V_427 ;
int V_301 ;
F_7 ( L_139 ,
V_232 , V_307 -> V_311 ) ;
V_363 -> V_238 = V_359 ;
V_301 = V_20 -> V_77 ( V_137 , V_290 , V_363 ) ;
if ( V_301 ) {
F_2 ( L_140 , V_232 ) ;
return V_301 ;
}
if ( V_307 -> V_513 == V_439 ) {
F_88 ( V_4 , V_232 ,
& V_232 -> V_222 ) ;
F_168 ( V_290 , V_137 , true , (struct V_428 * )
& V_232 -> V_222 . V_252 ) ;
F_90 ( V_4 , & V_232 -> V_222 ) ;
F_91 ( V_4 , V_232 ,
& V_232 -> V_222 . V_224 , true ) ;
V_232 -> V_237 . V_539 . V_220 = & V_232 -> V_222 . V_224 ;
V_363 -> V_401 += 1 ;
}
F_198 ( V_363 -> V_401 , & V_4 -> V_201 ) ;
V_301 = F_86 ( V_4 -> V_50 , V_363 -> V_224 , & V_427 ) ;
if ( V_301 ) {
F_4 ( L_141 ) ;
F_155 ( V_363 -> V_401 , & V_4 -> V_201 ) ;
}
if ( V_307 -> V_513 == V_439 )
F_7 ( L_142
L_143 , V_232 ) ;
else
F_7 ( L_144 ,
V_232 ) ;
return 1 ;
}
static int
F_199 ( struct V_248 * V_137 , struct V_289 * V_290 , bool V_540 )
{
struct V_307 * V_307 = & V_290 -> V_307 ;
struct V_232 * V_232 = F_102 ( V_290 ) ;
struct V_362 * V_363 = & V_232 -> V_237 ;
struct V_4 * V_4 = (struct V_4 * ) V_137 -> V_3 ;
struct V_19 * V_20 = V_4 -> V_21 ;
struct V_223 * V_427 ;
int V_301 ;
F_7 ( L_145 ,
V_232 , V_307 -> V_311 , V_290 -> V_310 ) ;
V_363 -> V_238 = V_410 ;
V_301 = V_20 -> V_77 ( V_137 , V_290 , V_363 ) ;
if ( V_301 ) {
F_2 ( L_140 , V_232 ) ;
return V_301 ;
}
F_198 ( V_363 -> V_401 , & V_4 -> V_201 ) ;
V_301 = F_86 ( V_4 -> V_50 , V_363 -> V_224 , & V_427 ) ;
if ( V_301 ) {
F_4 ( L_146 ) ;
F_155 ( V_363 -> V_401 , & V_4 -> V_201 ) ;
}
F_7 ( L_147 ,
V_232 ) ;
return 0 ;
}
static int
F_200 ( struct V_248 * V_137 , struct V_289 * V_290 , int V_154 )
{
int V_13 ;
switch ( V_154 ) {
case V_541 :
V_13 = F_173 ( V_290 , V_137 , false ) ;
break;
default:
F_2 ( L_148 , V_154 ) ;
V_13 = - V_185 ;
break;
}
return V_13 ;
}
static int
F_201 ( struct V_248 * V_137 , struct V_289 * V_290 , int V_154 )
{
int V_13 ;
switch ( V_154 ) {
case V_406 :
V_13 = F_175 ( V_290 , V_137 ) ;
if ( ! V_13 ) {
F_7 ( L_149 ) ;
V_13 = - V_542 ;
}
break;
case V_543 :
V_13 = F_173 ( V_290 , V_137 , true ) ;
break;
case V_403 :
V_13 = F_177 ( V_290 , V_137 ) ;
break;
case V_405 :
V_13 = F_179 ( V_290 , V_137 ) ;
break;
case V_407 :
V_13 = F_181 ( V_290 , V_137 ) ;
break;
case V_544 :
V_13 = F_147 ( V_137 , V_290 ) ;
break;
default:
F_2 ( L_150 , V_154 ) ;
V_13 = - V_185 ;
break;
}
return V_13 ;
}
static int
F_202 ( struct V_148 * V_149 ,
struct V_545 * V_546 )
{
struct V_150 * V_150 ;
struct V_16 * V_547 ;
struct V_548 * V_549 ;
int V_13 ;
V_150 = F_14 ( sizeof( struct V_150 ) , V_60 ) ;
if ( ! V_150 ) {
F_2 ( L_151 ) ;
return - V_70 ;
}
F_203 ( & V_150 -> V_189 , 0 ) ;
F_58 ( & V_150 -> V_187 ) ;
F_37 ( & V_150 -> V_188 ) ;
F_55 ( & V_150 -> V_550 ) ;
V_549 = (struct V_548 * ) V_546 ;
F_7 ( L_152 , V_546 , V_549 ) ;
memcpy ( & V_149 -> V_551 , V_546 ,
sizeof( struct V_545 ) ) ;
V_547 = F_204 ( F_79 , V_149 , V_552 ,
V_46 ) ;
if ( F_26 ( V_547 ) ) {
F_2 ( L_153 ,
F_27 ( V_547 ) ) ;
V_13 = F_27 ( V_547 ) ;
goto V_169;
}
V_13 = F_205 ( V_547 , V_549 ) ;
if ( V_13 ) {
F_2 ( L_154 , V_13 ) ;
goto V_553;
}
V_13 = F_206 ( V_547 , V_554 ) ;
if ( V_13 ) {
F_2 ( L_155 , V_13 ) ;
goto V_553;
}
V_150 -> V_555 = V_547 ;
V_149 -> V_151 = V_150 ;
F_7 ( L_156 , V_547 -> V_3 ) ;
return 0 ;
V_553:
F_66 ( V_547 ) ;
V_169:
F_18 ( V_150 ) ;
return V_13 ;
}
static int
F_207 ( struct V_4 * V_4 )
{
struct V_16 * V_556 = V_4 -> V_7 ;
struct V_557 V_558 ;
int V_13 ;
memset ( & V_558 , 0 , sizeof( struct V_557 ) ) ;
V_558 . V_163 = V_4 -> V_163 ;
V_558 . V_165 = V_4 -> V_165 ;
V_558 . V_559 = 7 ;
V_558 . V_560 = 7 ;
F_7 ( L_157 ) ;
V_13 = F_208 ( V_556 , & V_558 ) ;
if ( V_13 ) {
F_2 ( L_158 , V_13 ) ;
return V_13 ;
}
F_7 ( L_159 ) ;
return 0 ;
}
static int
F_209 ( struct V_248 * V_137 , struct V_249 * V_250 )
{
struct V_4 * V_4 = (struct V_4 * ) V_137 -> V_3 ;
int V_13 ;
F_7 ( L_160 , V_137 ) ;
if ( ! V_250 -> V_264 )
return 0 ;
V_13 = F_210 ( & V_4 -> V_157 ) ;
if ( V_13 )
return V_13 ;
F_7 ( L_161 , V_250 -> V_283 ) ;
return 0 ;
}
static void
F_211 ( struct V_148 * V_149 , struct V_248 * V_137 ,
struct V_4 * V_4 )
{
struct V_16 * V_556 = V_4 -> V_7 ;
struct V_561 * V_562 = & V_556 -> V_563 ;
struct V_564 * V_565 ;
struct V_566 * V_567 ;
V_137 -> V_568 = V_149 -> V_551 . V_569 ;
if ( V_149 -> V_551 . V_569 == V_570 ) {
V_567 = (struct V_566 * ) & V_562 -> V_65 . V_571 ;
snprintf ( V_137 -> V_572 , sizeof( V_137 -> V_572 ) , L_162 ,
& V_567 -> V_573 . V_574 ) ;
V_137 -> V_575 = F_212 ( V_567 -> V_576 ) ;
V_567 = (struct V_566 * ) & V_562 -> V_65 . V_577 ;
snprintf ( V_137 -> V_578 , sizeof( V_137 -> V_578 ) , L_162 ,
& V_567 -> V_573 . V_574 ) ;
V_137 -> V_579 = F_212 ( V_567 -> V_576 ) ;
} else {
V_565 = (struct V_564 * ) & V_562 -> V_65 . V_571 ;
sprintf ( V_137 -> V_572 , L_163 ,
& V_565 -> V_580 . V_581 ) ;
V_137 -> V_575 = F_212 ( V_565 -> V_582 ) ;
V_565 = (struct V_564 * ) & V_562 -> V_65 . V_577 ;
sprintf ( V_137 -> V_578 , L_163 ,
& V_565 -> V_580 . V_581 ) ;
V_137 -> V_579 = F_212 ( V_565 -> V_582 ) ;
}
}
static int
F_213 ( struct V_148 * V_149 , struct V_248 * V_137 )
{
struct V_150 * V_150 = (struct V_150 * ) V_149 -> V_151 ;
struct V_4 * V_4 ;
int V_583 = 0 , V_13 ;
V_584:
V_13 = F_214 ( & V_150 -> V_189 ) ;
if ( V_583 > 5 )
return - V_585 ;
F_52 ( & V_149 -> V_152 ) ;
if ( V_149 -> V_586 == V_587 ) {
F_53 ( & V_149 -> V_152 ) ;
F_7 ( L_164 ) ;
return - V_585 ;
}
F_53 ( & V_149 -> V_152 ) ;
F_9 ( & V_150 -> V_187 ) ;
if ( F_40 ( & V_150 -> V_188 ) ) {
F_10 ( & V_150 -> V_187 ) ;
V_583 ++ ;
goto V_584;
}
V_4 = F_195 ( & V_150 -> V_188 ,
struct V_4 , V_156 ) ;
F_136 ( & V_4 -> V_156 ) ;
F_10 ( & V_150 -> V_187 ) ;
V_137 -> V_3 = V_4 ;
V_4 -> V_137 = V_137 ;
V_583 = 0 ;
V_13 = F_94 ( V_4 ) ;
if ( V_13 )
return V_13 ;
V_13 = F_207 ( V_4 ) ;
if ( V_13 )
return V_13 ;
F_211 ( V_149 , V_137 , V_4 ) ;
F_7 ( L_165 , V_4 ) ;
return 0 ;
}
static void
F_215 ( struct V_148 * V_149 )
{
struct V_150 * V_150 = (struct V_150 * ) V_149 -> V_151 ;
F_66 ( V_150 -> V_555 ) ;
V_149 -> V_151 = NULL ;
F_18 ( V_150 ) ;
}
static void F_216 ( struct V_248 * V_137 )
{
struct V_4 * V_4 = V_137 -> V_3 ;
F_7 ( L_166 ) ;
F_9 ( & V_4 -> V_161 ) ;
if ( V_4 -> V_203 )
F_87 ( & V_4 -> V_201 ) ;
if ( V_4 -> V_7 && V_4 -> V_154 != V_414 ) {
F_7 ( L_167 ) ;
F_74 ( V_4 -> V_7 ) ;
}
if ( V_4 -> V_154 == V_155 ) {
F_10 ( & V_4 -> V_161 ) ;
return;
}
if ( V_4 -> V_154 == V_198 )
V_4 -> V_154 = V_199 ;
F_10 ( & V_4 -> V_161 ) ;
F_217 ( & V_4 -> V_159 ) ;
F_217 ( & V_4 -> V_158 ) ;
}
static void F_218 ( struct V_248 * V_137 )
{
struct V_4 * V_4 = V_137 -> V_3 ;
F_70 ( V_4 ) ;
}
static int T_5 F_219 ( void )
{
int V_13 ;
V_426 = F_220 ( L_168 , 0 , 0 ) ;
if ( ! V_426 ) {
F_2 ( L_169 ) ;
return - V_70 ;
}
V_408 = F_220 ( L_170 , 0 , 0 ) ;
if ( ! V_408 ) {
F_2 ( L_171 ) ;
V_13 = - V_70 ;
goto V_588;
}
F_221 ( & V_589 ) ;
F_7 ( L_172 ) ;
return 0 ;
V_588:
F_222 ( V_426 ) ;
return V_13 ;
}
static void T_6 F_223 ( void )
{
F_222 ( V_408 ) ;
F_222 ( V_426 ) ;
F_224 ( & V_589 ) ;
F_7 ( L_173 ) ;
}
