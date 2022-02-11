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
F_57 ( & V_4 -> V_161 ) ;
F_58 ( & V_4 -> V_162 ) ;
F_37 ( & V_4 -> V_105 ) ;
V_17 -> V_3 = V_4 ;
V_4 -> V_7 = V_17 ;
V_4 -> V_163 = F_14 ( V_164 +
V_165 , V_60 ) ;
if ( ! V_4 -> V_163 ) {
F_2 ( L_30 ) ;
V_13 = - V_70 ;
goto V_166;
}
V_4 -> V_167 = V_4 -> V_163 ;
V_4 -> V_168 = V_4 -> V_163 +
V_164 ;
F_7 ( L_31 ,
V_4 -> V_163 , V_4 -> V_167 ,
V_4 -> V_168 ) ;
V_4 -> V_169 = F_15 ( V_10 ,
( void * ) V_4 -> V_167 ,
V_164 , V_63 ) ;
V_13 = F_16 ( V_10 , V_4 -> V_169 ) ;
if ( V_13 ) {
F_2 ( L_32 ,
V_13 ) ;
V_4 -> V_169 = 0 ;
goto V_170;
}
V_4 -> V_171 = F_15 ( V_10 ,
( void * ) V_4 -> V_168 ,
V_165 , V_172 ) ;
V_13 = F_16 ( V_10 , V_4 -> V_171 ) ;
if ( V_13 ) {
F_2 ( L_33 ,
V_13 ) ;
V_4 -> V_171 = 0 ;
goto V_173;
}
V_20 = F_34 ( V_17 ) ;
if ( F_26 ( V_20 ) ) {
V_13 = F_27 ( V_20 ) ;
goto V_174;
}
V_4 -> V_175 = F_21 ( T_1 ,
V_5 -> V_176 . V_137 . V_175 ,
V_20 -> V_41 . V_177 ) ;
F_7 ( L_34 , V_4 -> V_175 ) ;
V_4 -> V_21 = V_20 ;
V_4 -> V_49 = F_59 ( V_4 -> V_21 -> V_9 ) ;
if ( F_26 ( V_4 -> V_49 ) ) {
V_13 = F_27 ( V_4 -> V_49 ) ;
F_2 ( L_35 ,
V_4 , V_13 ) ;
goto V_178;
}
V_4 -> V_68 = F_60 ( V_4 -> V_49 ,
V_179 ) ;
if ( F_26 ( V_4 -> V_68 ) ) {
V_13 = F_27 ( V_4 -> V_68 ) ;
F_2 ( L_36 ,
V_4 , V_13 ) ;
goto V_180;
}
V_134 = V_149 -> V_181 -> V_182 -> V_183 . V_184 ;
if ( V_134 && ! V_20 -> V_83 ) {
F_2 ( L_37
L_38 ) ;
V_13 = F_54 ( V_17 , NULL , 0 ) ;
goto V_180;
}
V_13 = F_8 ( V_4 , V_17 , V_134 ) ;
if ( V_13 )
goto V_185;
F_9 ( & V_150 -> V_186 ) ;
F_38 ( & V_4 -> V_156 , & V_150 -> V_187 ) ;
F_10 ( & V_150 -> V_186 ) ;
F_7 ( L_39 , V_149 ) ;
F_61 ( & V_150 -> V_188 ) ;
return 0 ;
V_185:
F_43 ( V_4 -> V_68 ) ;
V_180:
F_62 ( V_4 -> V_49 ) ;
V_178:
F_32 ( V_20 ) ;
V_174:
F_17 ( V_10 , V_4 -> V_171 ,
V_165 , V_172 ) ;
V_173:
F_17 ( V_10 , V_4 -> V_169 ,
V_164 , V_63 ) ;
V_170:
F_18 ( V_4 -> V_163 ) ;
V_166:
F_18 ( V_4 ) ;
return V_13 ;
}
static void
F_63 ( struct V_4 * V_4 )
{
struct V_9 * V_10 = V_4 -> V_7 -> V_20 ;
struct V_19 * V_20 = V_4 -> V_21 ;
int V_87 ;
F_7 ( L_40 ) ;
if ( V_20 && V_20 -> V_76 )
F_39 ( V_4 ) ;
if ( V_4 -> V_50 ) {
V_87 = ( (struct V_71 * )
V_4 -> V_50 -> V_33 -> V_189 ) -> V_87 ;
F_7 ( L_41 , V_87 ) ;
V_4 -> V_21 -> V_28 [ V_87 ] -- ;
F_64 ( V_4 -> V_7 ) ;
}
F_19 ( V_4 ) ;
F_65 ( V_4 -> V_7 ) ;
F_43 ( V_4 -> V_68 ) ;
F_62 ( V_4 -> V_49 ) ;
if ( V_4 -> V_163 ) {
F_17 ( V_10 , V_4 -> V_171 ,
V_165 , V_172 ) ;
F_17 ( V_10 , V_4 -> V_169 ,
V_164 ,
V_63 ) ;
F_18 ( V_4 -> V_163 ) ;
}
F_18 ( V_4 ) ;
if ( V_20 )
F_32 ( V_20 ) ;
F_7 ( L_42 ) ;
}
static void
F_66 ( struct V_16 * V_17 )
{
struct V_4 * V_4 = V_17 -> V_3 ;
F_67 ( & V_4 -> V_160 ) ;
}
static void
F_68 ( struct V_190 * V_190 )
{
struct V_4 * V_4 = F_69 ( V_190 ,
struct V_4 , V_160 ) ;
F_7 ( L_43 ,
V_191 -> V_192 , V_191 -> V_193 ) ;
F_63 ( V_4 ) ;
}
static void
F_70 ( struct V_4 * V_4 )
{
F_71 ( & V_4 -> V_160 , F_68 ) ;
}
static void
F_72 ( struct V_194 * V_195 )
{
struct V_4 * V_4 = F_69 ( V_195 ,
struct V_4 , V_196 ) ;
F_7 ( L_44 ) ;
F_9 ( & V_4 -> V_161 ) ;
if ( V_4 -> V_154 == V_197 )
V_4 -> V_154 = V_198 ;
if ( V_4 -> V_199 == 0 &&
F_73 ( & V_4 -> V_200 ) == 0 ) {
F_10 ( & V_4 -> V_161 ) ;
goto V_201;
}
if ( ! V_4 -> V_7 ) {
F_10 ( & V_4 -> V_161 ) ;
F_70 ( V_4 ) ;
return;
}
if ( V_4 -> V_202 ) {
F_74 ( V_4 -> V_7 ) ;
}
F_10 ( & V_4 -> V_161 ) ;
V_201:
F_75 ( & V_4 -> V_158 ) ;
}
static void
F_76 ( struct V_16 * V_17 , bool V_202 )
{
struct V_4 * V_4 = (struct V_4 * ) V_17 -> V_3 ;
V_4 -> V_202 = V_202 ;
F_24 ( & V_4 -> V_196 , F_72 ) ;
F_77 ( & V_4 -> V_196 ) ;
}
static int
F_78 ( struct V_16 * V_17 , struct V_147 * V_5 )
{
int V_13 = 0 ;
bool V_202 = false ;
F_7 ( L_45 ,
V_5 -> V_5 , V_5 -> V_203 , V_17 -> V_3 , V_17 ) ;
switch ( V_5 -> V_5 ) {
case V_204 :
V_13 = F_51 ( V_17 , V_5 ) ;
break;
case V_205 :
F_66 ( V_17 ) ;
break;
case V_206 :
case V_207 :
case V_208 :
V_202 = true ;
case V_209 :
F_76 ( V_17 , V_202 ) ;
break;
case V_210 :
default:
F_2 ( L_46 , V_5 -> V_5 ) ;
break;
}
if ( V_13 != 0 ) {
F_2 ( L_47 ,
V_5 -> V_5 , V_13 ) ;
F_79 () ;
}
return V_13 ;
}
static int
F_80 ( struct V_4 * V_4 , V_142 V_211 )
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
V_4 -> V_199 += V_211 ;
V_13 = F_81 ( V_4 -> V_50 , V_4 -> V_216 ,
& V_214 ) ;
if ( V_13 ) {
F_2 ( L_48 , V_13 ) ;
V_4 -> V_199 -= V_211 ;
} else {
F_7 ( L_49 , V_211 ) ;
V_4 -> V_69 = V_215 ;
}
return V_13 ;
}
static int
F_82 ( struct V_4 * V_4 , struct V_221 * V_222 )
{
struct V_9 * V_10 = V_4 -> V_7 -> V_20 ;
struct V_223 V_224 , * V_225 ;
int V_13 ;
F_83 ( V_10 , V_222 -> V_56 ,
V_226 , V_172 ) ;
V_224 . V_220 = NULL ;
V_224 . V_217 = ( unsigned long ) V_222 ;
V_224 . V_218 = V_222 -> V_227 ;
V_224 . V_219 = V_222 -> V_219 ;
V_224 . V_228 = V_229 ;
V_224 . V_230 = V_231 ;
F_84 ( & V_4 -> V_200 ) ;
V_13 = F_85 ( V_4 -> V_50 , & V_224 , & V_225 ) ;
if ( V_13 ) {
F_2 ( L_50 , V_13 ) ;
F_86 ( & V_4 -> V_200 ) ;
}
return V_13 ;
}
static void
F_87 ( struct V_4 * V_4 ,
struct V_232 * V_232 ,
struct V_221 * V_222 )
{
struct V_9 * V_10 = V_4 -> V_7 -> V_20 ;
F_88 ( V_10 , V_222 -> V_56 ,
V_226 , V_172 ) ;
memset ( & V_222 -> V_233 , 0 , sizeof( struct V_234 ) ) ;
V_222 -> V_233 . V_129 = V_235 ;
V_222 -> V_219 = 1 ;
V_222 -> V_232 = V_232 ;
if ( V_222 -> V_227 [ 0 ] . V_67 != V_4 -> V_68 -> V_67 ) {
V_222 -> V_227 [ 0 ] . V_67 = V_4 -> V_68 -> V_67 ;
F_7 ( L_51 , V_222 ) ;
}
}
static int
F_89 ( struct V_4 * V_4 ,
struct V_221 * V_222 )
{
struct V_9 * V_10 = V_4 -> V_7 -> V_20 ;
T_2 V_56 ;
V_56 = F_15 ( V_10 , ( void * ) V_222 ,
V_226 , V_172 ) ;
if ( F_16 ( V_10 , V_56 ) ) {
F_2 ( L_52 ) ;
return - V_70 ;
}
V_222 -> V_56 = V_56 ;
V_222 -> V_227 [ 0 ] . V_65 = V_222 -> V_56 ;
V_222 -> V_227 [ 0 ] . V_66 = V_226 ;
V_222 -> V_227 [ 0 ] . V_67 = V_4 -> V_68 -> V_67 ;
F_7 ( L_53
L_54 , V_222 -> V_227 [ 0 ] . V_65 ,
V_222 -> V_227 [ 0 ] . V_66 , V_222 -> V_227 [ 0 ] . V_67 ) ;
return 0 ;
}
static void
F_90 ( struct V_4 * V_4 , struct V_232 * V_232 ,
struct V_223 * V_224 , bool V_236 )
{
struct V_221 * V_222 = & V_232 -> V_222 ;
V_232 -> V_237 . V_238 = V_239 ;
V_224 -> V_217 = ( unsigned long ) & V_232 -> V_222 ;
V_224 -> V_228 = V_229 ;
V_224 -> V_218 = & V_222 -> V_227 [ 0 ] ;
V_224 -> V_219 = V_232 -> V_222 . V_219 ;
F_9 ( & V_4 -> V_161 ) ;
if ( V_236 && V_4 -> V_154 == V_197 &&
++ V_4 -> V_240 < V_241 ) {
V_222 -> V_242 = true ;
F_91 ( & V_222 -> V_243 , & V_4 -> V_244 ) ;
F_10 ( & V_4 -> V_161 ) ;
return;
}
V_4 -> V_240 = 0 ;
V_222 -> V_245 = F_92 ( & V_4 -> V_244 ) ;
F_10 ( & V_4 -> V_161 ) ;
V_224 -> V_230 = V_231 ;
}
static int
F_93 ( struct V_4 * V_4 )
{
struct V_212 V_213 , * V_246 ;
struct V_54 V_247 ;
int V_13 ;
memset ( & V_247 , 0 , sizeof( struct V_54 ) ) ;
V_247 . V_65 = V_4 -> V_169 ;
V_247 . V_66 = V_165 ;
V_247 . V_67 = V_4 -> V_68 -> V_67 ;
F_7 ( L_55 ,
V_247 . V_65 , V_247 . V_66 , V_247 . V_67 ) ;
memset ( & V_213 , 0 , sizeof( struct V_212 ) ) ;
V_213 . V_217 = ( unsigned long ) V_4 -> V_167 ;
V_213 . V_218 = & V_247 ;
V_213 . V_219 = 1 ;
V_4 -> V_199 ++ ;
V_13 = F_81 ( V_4 -> V_50 , & V_213 , & V_246 ) ;
if ( V_13 ) {
F_2 ( L_56 , V_13 ) ;
V_4 -> V_199 -- ;
}
F_7 ( L_57 ) ;
return V_13 ;
}
static int
F_94 ( struct V_248 * V_137 , struct V_249 * V_250 ,
V_142 V_66 )
{
struct V_4 * V_4 = V_137 -> V_3 ;
struct V_9 * V_10 = V_4 -> V_7 -> V_20 ;
struct V_221 * V_222 = & V_4 -> V_251 ;
int V_13 ;
F_87 ( V_4 , NULL , V_222 ) ;
memcpy ( & V_222 -> V_252 , & V_250 -> V_253 [ 0 ] ,
sizeof( struct V_254 ) ) ;
F_89 ( V_4 , V_222 ) ;
if ( V_66 > 0 ) {
struct V_54 * V_255 = & V_222 -> V_227 [ 1 ] ;
F_88 ( V_10 , V_4 -> V_171 ,
V_66 , V_172 ) ;
memcpy ( V_4 -> V_168 , V_250 -> V_256 , V_66 ) ;
F_83 ( V_10 , V_4 -> V_171 ,
V_66 , V_172 ) ;
V_255 -> V_65 = V_4 -> V_171 ;
V_255 -> V_66 = V_66 ;
V_255 -> V_67 = V_4 -> V_68 -> V_67 ;
V_222 -> V_219 = 2 ;
}
if ( ! V_250 -> V_257 ) {
if ( V_250 -> V_258 ) {
if ( ! V_137 -> V_138 -> V_259 -> V_260 &&
V_4 -> V_21 -> V_76 ) {
T_1 V_134 = V_250 -> V_149 -> V_181 -> V_182 -> V_183 . V_184 ;
V_13 = F_49 ( V_4 ,
V_134 ) ;
if ( V_13 ) {
F_2 ( L_58
L_59 , V_4 ) ;
return V_13 ;
}
}
V_13 = F_13 ( V_4 ) ;
if ( V_13 )
return V_13 ;
V_13 = F_80 ( V_4 , V_261 ) ;
if ( V_13 )
return V_13 ;
V_4 -> V_154 = V_197 ;
goto V_262;
}
V_13 = F_93 ( V_4 ) ;
if ( V_13 )
return V_13 ;
}
V_262:
V_13 = F_82 ( V_4 , V_222 ) ;
if ( V_13 )
return V_13 ;
return 0 ;
}
static void
F_95 ( struct V_52 * V_53 , int V_263 ,
struct V_4 * V_4 )
{
struct V_248 * V_137 = V_4 -> V_137 ;
struct V_249 * V_250 = V_137 -> V_264 ;
int V_265 ;
if ( ! V_250 ) {
F_2 ( L_60 ) ;
F_79 () ;
return;
}
if ( V_250 -> V_266 ) {
struct V_267 * V_268 =
(struct V_267 * ) & V_53 -> V_252 ;
V_250 -> V_269 = ( ! V_268 -> V_270 ) ? 1 : 0 ;
V_250 -> V_271 =
( V_268 -> V_129 & V_272 )
>> 2 ;
V_250 -> V_273 = V_268 -> V_274 ;
V_250 -> V_275 = V_268 -> V_276 ;
memcpy ( V_250 -> V_277 , V_268 -> V_277 , 6 ) ;
V_250 -> V_278 = F_96 ( V_268 -> V_279 ) ;
V_250 -> V_280 = V_268 -> V_281 ;
V_250 -> V_282 = F_96 ( V_268 -> V_283 ) ;
V_250 -> V_284 = F_97 ( V_268 -> V_284 ) ;
V_250 -> V_270 = F_97 ( V_268 -> V_270 ) ;
}
memcpy ( & V_250 -> V_285 [ 0 ] , ( void * ) & V_53 -> V_252 , V_286 ) ;
V_265 = F_23 ( V_263 , V_287 ) ;
F_7 ( L_61 ,
V_265 , V_263 , V_287 ) ;
memcpy ( V_250 -> V_288 , & V_53 -> V_289 [ 0 ] , V_265 ) ;
if ( V_250 -> V_266 ) {
F_75 ( & V_4 -> V_157 ) ;
return;
}
F_98 ( & V_137 -> V_290 , 0 ) ;
}
static struct V_291
* F_99 ( struct V_248 * V_137 )
{
struct V_4 * V_4 = (struct V_4 * ) V_137 -> V_3 ;
struct V_232 * V_232 ;
struct V_291 * V_292 ;
V_292 = F_100 ( V_137 , V_293 ) ;
if ( ! V_292 ) {
F_2 ( L_62 ) ;
return NULL ;
}
V_232 = F_101 ( V_292 ) ;
V_232 -> V_137 = V_4 ;
V_232 -> V_291 = V_292 ;
return V_292 ;
}
static int
F_102 ( struct V_4 * V_4 ,
struct V_232 * V_232 , struct V_291 * V_292 ,
struct V_52 * V_53 , unsigned char * V_294 )
{
struct V_248 * V_137 = V_4 -> V_137 ;
struct V_295 * V_296 = (struct V_295 * ) V_294 ;
struct V_297 * V_298 ;
int V_299 , V_300 , V_301 , V_302 , V_303 ;
bool V_304 = false ;
V_303 = F_103 ( V_137 , V_292 , V_294 ) ;
if ( V_303 < 0 )
return V_303 ;
V_299 = V_292 -> V_305 ;
V_300 = V_292 -> V_306 ;
V_301 = V_292 -> V_307 ;
V_303 = F_104 ( V_137 , V_292 , V_296 ) ;
if ( V_303 < 0 ) {
return 0 ;
} else if ( V_303 > 0 ) {
V_304 = true ;
goto V_308;
}
if ( ! V_299 )
return 0 ;
V_298 = & V_292 -> V_309 . V_310 [ 0 ] ;
V_302 = F_105 ( 1UL , F_106 ( V_300 , V_311 ) ) ;
F_7 ( L_63 ,
V_298 , V_302 , & V_53 -> V_289 [ 0 ] , V_300 ) ;
F_107 ( V_298 , V_302 , & V_53 -> V_289 [ 0 ] , V_300 ) ;
V_292 -> V_312 += V_300 ;
if ( V_292 -> V_312 == V_292 -> V_309 . V_313 ) {
F_52 ( & V_292 -> V_314 ) ;
V_292 -> V_315 |= V_316 ;
V_292 -> V_317 = V_318 ;
F_53 ( & V_292 -> V_314 ) ;
}
V_308:
V_303 = F_108 ( V_137 , V_292 , V_294 , V_296 -> V_279 ) ;
if ( ! V_303 && V_304 == false && V_301 )
F_109 ( V_292 ) ;
else if ( V_304 && V_299 )
F_110 ( V_137 -> V_138 -> V_136 , & V_292 -> V_309 ) ;
return 0 ;
}
static int
F_111 ( struct V_4 * V_4 ,
struct V_52 * V_53 , unsigned char * V_294 )
{
struct V_297 * V_319 ;
struct V_248 * V_137 = V_4 -> V_137 ;
struct V_291 * V_292 = NULL ;
struct V_320 * V_296 = (struct V_320 * ) V_294 ;
V_142 V_321 = F_112 ( V_296 -> V_322 ) ;
int V_303 , V_302 , V_323 , V_324 ;
V_303 = F_113 ( V_137 , V_294 , & V_292 ) ;
if ( V_303 < 0 )
return V_303 ;
else if ( ! V_292 )
return 0 ;
if ( ! V_292 -> V_307 ) {
F_2 ( L_64 ) ;
F_79 () ;
return - 1 ;
}
F_7 ( L_65 ,
V_321 , V_292 -> V_312 , V_292 -> V_309 . V_313 ) ;
V_323 = V_292 -> V_312 / V_311 ;
V_319 = & V_292 -> V_309 . V_310 [ V_323 ] ;
V_302 = F_105 ( 1UL , F_106 ( V_321 , V_311 ) ) ;
V_324 = V_292 -> V_312 % V_311 ;
if ( V_324 ) {
F_2 ( L_66 ) ;
F_79 () ;
return - 1 ;
}
F_7 ( L_67 ,
V_319 , V_323 , V_302 , & V_53 -> V_289 [ 0 ] , V_321 ) ;
F_107 ( V_319 , V_302 , & V_53 -> V_289 [ 0 ] ,
V_321 ) ;
V_303 = F_114 ( V_292 , V_296 , false ) ;
if ( V_303 < 0 )
return V_303 ;
return 0 ;
}
static int
F_115 ( struct V_4 * V_4 , struct V_232 * V_232 ,
struct V_291 * V_292 , struct V_52 * V_53 ,
unsigned char * V_294 )
{
struct V_248 * V_137 = V_4 -> V_137 ;
struct V_325 * V_296 = (struct V_325 * ) V_294 ;
int V_303 ;
V_303 = F_116 ( V_137 , V_292 , V_296 ) ;
if ( V_303 < 0 )
return V_303 ;
return F_117 ( V_137 , V_292 , V_296 ) ;
}
static int
F_118 ( struct V_4 * V_4 , struct V_232 * V_232 ,
struct V_291 * V_292 , struct V_52 * V_53 ,
struct V_326 * V_296 )
{
struct V_248 * V_137 = V_4 -> V_137 ;
V_142 V_327 = F_112 ( V_296 -> V_322 ) ;
int V_303 ;
unsigned char * V_328 ;
V_303 = F_119 ( V_137 , V_292 , V_296 ) ;
if ( V_303 < 0 )
return V_303 ;
V_328 = F_14 ( V_327 , V_60 ) ;
if ( ! V_328 ) {
F_2 ( L_68 ,
V_327 ) ;
return - V_70 ;
}
V_292 -> V_329 = V_328 ;
memcpy ( V_292 -> V_329 , & V_53 -> V_289 [ 0 ] , V_327 ) ;
return F_120 ( V_137 , V_292 , V_296 ) ;
}
static int
F_121 ( struct V_4 * V_4 , struct V_52 * V_53 ,
T_3 V_330 , T_4 V_331 ,
T_3 V_332 , T_4 V_333 )
{
struct V_254 * V_296 = & V_53 -> V_252 ;
struct V_248 * V_137 = V_4 -> V_137 ;
struct V_334 * V_138 = V_137 -> V_138 ;
struct V_291 * V_292 ;
struct V_232 * V_232 ;
int V_13 = - V_335 ;
T_1 V_228 = ( V_296 -> V_228 & V_336 ) ;
if ( V_138 -> V_259 -> V_260 &&
( ! ( V_228 & V_337 ) || ! ( V_228 & V_338 ) ) ) {
F_2 ( L_69
L_70 , V_228 ) ;
return 0 ;
}
switch ( V_228 ) {
case V_339 :
V_292 = F_99 ( V_137 ) ;
if ( ! V_292 )
break;
V_232 = F_101 ( V_292 ) ;
V_232 -> V_330 = V_330 ;
V_232 -> V_331 = V_331 ;
V_232 -> V_332 = V_332 ;
V_232 -> V_333 = V_333 ;
V_13 = F_102 ( V_4 , V_232 , V_292 ,
V_53 , ( unsigned char * ) V_296 ) ;
break;
case V_340 :
V_292 = F_99 ( V_137 ) ;
if ( ! V_292 )
break;
V_232 = F_101 ( V_292 ) ;
V_13 = F_115 ( V_4 , V_232 , V_292 ,
V_53 , ( unsigned char * ) V_296 ) ;
break;
case V_341 :
V_13 = F_111 ( V_4 , V_53 ,
( unsigned char * ) V_296 ) ;
break;
case V_342 :
V_292 = F_99 ( V_137 ) ;
if ( ! V_292 )
break;
V_13 = F_122 ( V_137 , V_292 ,
( unsigned char * ) V_296 ) ;
break;
case V_338 :
V_292 = F_99 ( V_137 ) ;
if ( ! V_292 )
break;
V_13 = F_123 ( V_137 , V_292 , ( unsigned char * ) V_296 ) ;
if ( V_13 > 0 )
F_124 ( & V_137 -> V_343 ,
V_344 *
V_345 ) ;
break;
case V_337 :
V_292 = F_99 ( V_137 ) ;
if ( ! V_292 )
break;
V_232 = F_101 ( V_292 ) ;
V_13 = F_118 ( V_4 , V_232 , V_292 ,
V_53 , (struct V_326 * ) V_296 ) ;
break;
default:
F_2 ( L_71 , V_228 ) ;
F_79 () ;
break;
}
return V_13 ;
}
static void
F_125 ( struct V_52 * V_53 , struct V_4 * V_4 )
{
struct V_234 * V_234 = & V_53 -> V_233 ;
T_4 V_331 = 0 , V_333 = 0 ;
T_3 V_330 = 0 , V_332 = 0 ;
int V_303 ;
switch ( V_234 -> V_129 & 0xF0 ) {
case V_346 :
if ( V_234 -> V_129 & V_347 ) {
V_330 = F_96 ( V_234 -> V_330 ) ;
V_331 = F_126 ( V_234 -> V_331 ) ;
F_7 ( L_72 ,
V_330 , ( unsigned long long ) V_331 ) ;
}
if ( V_234 -> V_129 & V_348 ) {
V_332 = F_96 ( V_234 -> V_332 ) ;
V_333 = F_126 ( V_234 -> V_333 ) ;
F_7 ( L_73 ,
V_332 , ( unsigned long long ) V_333 ) ;
}
F_7 ( L_74 ) ;
break;
case V_349 :
F_2 ( L_75 ) ;
break;
default:
F_4 ( L_76 , V_234 -> V_129 ) ;
break;
}
V_303 = F_121 ( V_4 , V_53 ,
V_330 , V_331 , V_332 , V_333 ) ;
}
static void
F_127 ( struct V_52 * V_350 , struct V_4 * V_4 ,
unsigned long V_351 )
{
struct V_9 * V_10 = V_4 -> V_7 -> V_20 ;
struct V_254 * V_296 ;
T_2 V_352 ;
int V_263 , V_353 ;
if ( ( char * ) V_350 == V_4 -> V_167 ) {
V_352 = V_4 -> V_169 ;
V_263 = V_165 ;
F_7 ( L_77 ,
V_352 , V_263 ) ;
} else {
V_352 = V_350 -> V_56 ;
V_263 = V_62 ;
F_7 ( L_78 ,
V_352 , V_263 ) ;
}
F_88 ( V_10 , V_352 , V_263 , V_63 ) ;
V_296 = & V_350 -> V_252 ;
F_7 ( L_79 ,
V_296 -> V_228 , V_296 -> V_281 , V_296 -> V_129 ,
( int ) ( V_351 - V_226 ) ) ;
if ( ( char * ) V_350 == V_4 -> V_167 )
F_95 ( V_350 , V_351 - V_226 ,
V_4 ) ;
else
F_125 ( V_350 , V_4 ) ;
F_83 ( V_10 , V_352 , V_263 ,
V_63 ) ;
V_4 -> V_199 -- ;
F_7 ( L_80 ,
V_4 -> V_199 ) ;
if ( ( char * ) V_350 == V_4 -> V_167 )
return;
V_353 = V_4 -> V_199 ;
if ( V_353 + V_261 <= V_39 ) {
int V_146 , V_211 = F_23 ( V_39 - V_353 ,
V_261 ) ;
V_146 = F_80 ( V_4 , V_211 ) ;
if ( V_146 ) {
F_2 ( L_81 ,
V_211 , V_146 ) ;
}
}
}
static int
F_128 ( struct V_4 * V_4 , struct V_232 * V_232 ,
struct V_297 * V_298 , V_142 V_354 , V_142 V_66 , V_142 V_355 ,
enum V_356 V_357 , struct V_358 * V_289 )
{
struct V_9 * V_10 = V_4 -> V_7 -> V_20 ;
V_289 -> V_359 = V_357 == V_360 ?
V_172 : V_63 ;
V_289 -> V_361 = V_66 - V_355 ;
V_289 -> V_355 = V_355 ;
V_289 -> V_323 = V_289 -> V_355 / V_311 ;
V_289 -> V_298 = & V_298 [ V_289 -> V_323 ] ;
V_289 -> V_354 = F_21 (unsigned int, nents - data->sg_off,
ISCSI_ISER_SG_TABLESIZE) ;
V_289 -> V_361 = F_21 (unsigned int, data->len, ISCSI_ISER_SG_TABLESIZE *
PAGE_SIZE) ;
V_289 -> V_362 = F_129 ( V_10 , V_289 -> V_298 , V_289 -> V_354 ,
V_289 -> V_359 ) ;
if ( F_130 ( ! V_289 -> V_362 ) ) {
F_2 ( L_82 , V_298 ) ;
return - V_335 ;
}
F_7 ( L_83 ,
V_232 , V_289 -> V_362 , V_289 -> V_298 , V_289 -> V_354 , V_289 -> V_361 ) ;
return 0 ;
}
static void
F_131 ( struct V_4 * V_4 , struct V_358 * V_289 )
{
struct V_9 * V_10 = V_4 -> V_7 -> V_20 ;
F_132 ( V_10 , V_289 -> V_298 , V_289 -> V_354 , V_289 -> V_359 ) ;
memset ( V_289 , 0 , sizeof( * V_289 ) ) ;
}
static void
V_82 ( struct V_232 * V_232 , struct V_4 * V_4 )
{
struct V_363 * V_364 = & V_232 -> V_237 ;
F_7 ( L_84 , V_232 ) ;
if ( V_364 -> V_289 . V_298 ) {
F_7 ( L_85 , V_232 ) ;
F_131 ( V_4 , & V_364 -> V_289 ) ;
}
if ( V_364 -> V_224 ) {
F_7 ( L_86 , V_232 ) ;
F_18 ( V_364 -> V_224 ) ;
V_364 -> V_224 = NULL ;
}
if ( V_364 -> V_54 ) {
F_7 ( L_87 , V_232 ) ;
F_18 ( V_364 -> V_54 ) ;
V_364 -> V_54 = NULL ;
}
}
static void
V_80 ( struct V_232 * V_232 , struct V_4 * V_4 )
{
struct V_363 * V_364 = & V_232 -> V_237 ;
F_133 ( V_365 ) ;
F_7 ( L_88 , V_232 ) ;
if ( V_364 -> V_103 ) {
F_7 ( L_89 ,
V_232 , V_364 -> V_103 ) ;
if ( V_364 -> V_103 -> V_119 & V_133 ) {
F_131 ( V_4 , & V_364 -> V_366 ) ;
V_364 -> V_103 -> V_119 &= ~ V_133 ;
}
F_52 ( & V_4 -> V_162 ) ;
F_38 ( & V_364 -> V_103 -> V_106 , & V_4 -> V_105 ) ;
F_53 ( & V_4 -> V_162 ) ;
V_364 -> V_103 = NULL ;
}
if ( V_364 -> V_289 . V_298 ) {
F_7 ( L_90 , V_232 ) ;
F_131 ( V_4 , & V_364 -> V_289 ) ;
}
V_364 -> V_54 = NULL ;
V_364 -> V_224 = NULL ;
}
static void
F_134 ( struct V_232 * V_232 , bool V_367 )
{
struct V_291 * V_292 = V_232 -> V_291 ;
struct V_4 * V_4 = V_232 -> V_137 ;
struct V_248 * V_137 = V_4 -> V_137 ;
struct V_19 * V_20 = V_4 -> V_21 ;
F_7 ( L_91 , V_232 ) ;
switch ( V_292 -> V_368 ) {
case V_339 :
F_52 ( & V_137 -> V_369 ) ;
if ( ! F_40 ( & V_292 -> V_370 ) )
F_135 ( & V_292 -> V_370 ) ;
F_53 ( & V_137 -> V_369 ) ;
if ( V_292 -> V_371 == V_172 ) {
F_136 ( V_292 ) ;
if ( V_367 &&
V_292 -> V_309 . V_372 == V_373 ) {
struct V_309 * V_309 = & V_292 -> V_309 ;
F_110 ( V_309 -> V_136 , V_309 ) ;
}
}
V_20 -> V_79 ( V_232 , V_4 ) ;
F_137 ( & V_292 -> V_309 , 0 ) ;
break;
case V_342 :
F_52 ( & V_137 -> V_369 ) ;
if ( ! F_40 ( & V_292 -> V_370 ) )
F_135 ( & V_292 -> V_370 ) ;
F_53 ( & V_137 -> V_369 ) ;
F_137 ( & V_292 -> V_309 , 0 ) ;
break;
case V_374 :
case V_340 :
case V_337 :
F_52 ( & V_137 -> V_369 ) ;
if ( ! F_40 ( & V_292 -> V_370 ) )
F_135 ( & V_292 -> V_370 ) ;
F_53 ( & V_137 -> V_369 ) ;
if ( V_292 -> V_309 . V_375 != NULL ) {
F_7 ( L_92
L_93 ,
V_292 -> V_368 ) ;
F_137 ( & V_292 -> V_309 , 0 ) ;
break;
}
default:
F_138 ( V_292 ) ;
break;
}
}
static void
F_139 ( struct V_221 * V_222 , struct V_9 * V_10 )
{
if ( V_222 -> V_56 != 0 ) {
F_7 ( L_94 ) ;
F_17 ( V_10 , V_222 -> V_56 ,
V_226 , V_172 ) ;
V_222 -> V_56 = 0 ;
}
}
static void
F_140 ( struct V_221 * V_222 , struct V_232 * V_232 ,
struct V_9 * V_10 , bool V_367 )
{
if ( V_232 -> V_376 != 0 ) {
F_7 ( L_95 ) ;
F_17 ( V_10 , V_232 -> V_376 ,
V_232 -> V_377 , V_172 ) ;
V_232 -> V_376 = 0 ;
}
F_139 ( V_222 , V_10 ) ;
F_134 ( V_232 , V_367 ) ;
}
static int
F_141 ( struct V_309 * V_309 , struct V_378 * V_112 )
{
struct V_379 V_380 ;
int V_13 ;
V_13 = F_142 ( V_112 , V_381 , & V_380 ) ;
if ( V_13 ) {
F_2 ( L_96 , V_13 ) ;
goto V_382;
}
if ( V_380 . V_383 & V_381 ) {
T_2 V_384 ;
V_142 V_385 = V_309 -> V_386 -> V_387 . V_385 + 8 ;
switch ( V_380 . V_388 . V_389 ) {
case V_390 :
V_309 -> V_391 = V_392 ;
break;
case V_393 :
V_309 -> V_391 = V_394 ;
break;
case V_395 :
V_309 -> V_391 = V_396 ;
break;
}
V_384 = V_380 . V_388 . V_397 ;
F_143 ( V_384 , V_385 ) ;
V_309 -> V_398 = V_384 + V_309 -> V_399 ;
F_2 ( L_97
L_98 ,
V_380 . V_388 . V_389 ,
( unsigned long long ) V_309 -> V_398 ,
V_380 . V_388 . V_400 ,
V_380 . V_388 . V_401 ) ;
V_13 = 1 ;
}
V_382:
return V_13 ;
}
static void
F_144 ( struct V_221 * V_222 ,
struct V_232 * V_232 )
{
struct V_363 * V_364 = & V_232 -> V_237 ;
struct V_291 * V_292 = V_232 -> V_291 ;
struct V_309 * V_309 = & V_292 -> V_309 ;
struct V_4 * V_4 = V_232 -> V_137 ;
struct V_19 * V_20 = V_4 -> V_21 ;
int V_13 = 0 ;
if ( V_364 -> V_103 && V_364 -> V_103 -> V_119 & V_133 ) {
V_13 = F_141 ( V_309 ,
V_364 -> V_103 -> V_109 -> V_112 ) ;
V_364 -> V_103 -> V_119 &= ~ V_133 ;
}
V_20 -> V_79 ( V_232 , V_4 ) ;
V_364 -> V_402 = 0 ;
if ( V_13 )
F_145 ( V_309 ,
V_309 -> V_391 , 0 ) ;
else
F_146 ( V_4 -> V_137 , V_292 ) ;
}
static void
F_147 ( struct V_221 * V_222 ,
struct V_232 * V_232 )
{
struct V_363 * V_364 = & V_232 -> V_237 ;
struct V_291 * V_292 = V_232 -> V_291 ;
struct V_309 * V_309 = & V_292 -> V_309 ;
struct V_4 * V_4 = V_232 -> V_137 ;
struct V_19 * V_20 = V_4 -> V_21 ;
int V_13 = 0 ;
if ( V_364 -> V_103 && V_364 -> V_103 -> V_119 & V_133 ) {
V_13 = F_141 ( V_309 ,
V_364 -> V_103 -> V_109 -> V_112 ) ;
V_364 -> V_103 -> V_119 &= ~ V_133 ;
}
F_136 ( V_292 ) ;
V_20 -> V_79 ( V_232 , V_4 ) ;
V_292 -> V_312 = V_364 -> V_289 . V_361 ;
V_364 -> V_402 = 0 ;
F_7 ( L_99 , V_232 ) ;
F_52 ( & V_292 -> V_314 ) ;
V_292 -> V_315 |= V_316 ;
V_292 -> V_317 = V_318 ;
F_53 ( & V_292 -> V_314 ) ;
if ( V_13 )
F_145 ( V_309 ,
V_309 -> V_391 , 0 ) ;
else
F_148 ( V_309 ) ;
}
static void
F_149 ( struct V_194 * V_195 )
{
struct V_232 * V_232 = F_69 ( V_195 ,
struct V_232 , V_403 ) ;
struct V_4 * V_4 = V_232 -> V_137 ;
struct V_9 * V_10 = V_4 -> V_7 -> V_20 ;
struct V_291 * V_292 = V_232 -> V_291 ;
switch ( V_292 -> V_317 ) {
case V_404 :
F_7 ( L_100 ) ;
F_86 ( & V_4 -> V_200 ) ;
F_150 ( V_292 , V_292 -> V_137 ) ;
V_292 -> V_317 = V_405 ;
F_140 ( & V_232 -> V_222 , V_232 , V_10 , false ) ;
break;
case V_406 :
F_7 ( L_101 ) ;
F_86 ( & V_4 -> V_200 ) ;
V_292 -> V_317 = V_405 ;
F_140 ( & V_232 -> V_222 , V_232 , V_10 , false ) ;
break;
case V_407 :
F_7 ( L_102 ) ;
F_86 ( & V_4 -> V_200 ) ;
F_151 ( V_292 , V_292 -> V_137 ) ;
break;
case V_408 :
F_86 ( & V_4 -> V_200 ) ;
V_292 -> V_317 = V_405 ;
F_140 ( & V_232 -> V_222 , V_232 , V_10 , false ) ;
break;
default:
F_2 ( L_103 , V_292 -> V_317 ) ;
F_79 () ;
break;
}
}
static void
F_152 ( struct V_221 * V_222 ,
struct V_232 * V_232 ,
struct V_4 * V_4 ,
struct V_9 * V_10 )
{
struct V_291 * V_292 = V_232 -> V_291 ;
struct V_363 * V_364 = & V_232 -> V_237 ;
if ( V_292 -> V_317 == V_404 ||
V_292 -> V_317 == V_407 ||
V_292 -> V_317 == V_406 ||
V_292 -> V_317 == V_408 ) {
F_139 ( V_222 , V_10 ) ;
F_24 ( & V_232 -> V_403 , F_149 ) ;
F_153 ( V_409 , & V_232 -> V_403 ) ;
return;
}
if ( V_364 -> V_402 )
F_154 ( V_364 -> V_402 , & V_4 -> V_200 ) ;
else
F_86 ( & V_4 -> V_200 ) ;
V_292 -> V_317 = V_405 ;
F_140 ( V_222 , V_232 , V_10 , false ) ;
}
static void
F_155 ( struct V_221 * V_222 ,
struct V_4 * V_4 )
{
struct V_9 * V_10 = V_4 -> V_7 -> V_20 ;
struct V_232 * V_232 = V_222 -> V_232 ;
struct V_363 * V_364 ;
if ( ! V_232 ) {
F_86 ( & V_4 -> V_200 ) ;
F_139 ( V_222 , V_10 ) ;
return;
}
V_364 = & V_232 -> V_237 ;
switch ( V_364 -> V_238 ) {
case V_410 :
F_2 ( L_104 ) ;
F_79 () ;
break;
case V_239 :
F_7 ( L_105 ) ;
F_152 ( V_222 , V_232 ,
V_4 , V_10 ) ;
break;
case V_360 :
F_7 ( L_106 ) ;
F_154 ( V_364 -> V_402 , & V_4 -> V_200 ) ;
F_144 ( V_222 , V_232 ) ;
break;
case V_411 :
F_7 ( L_107 ) ;
F_154 ( V_364 -> V_402 , & V_4 -> V_200 ) ;
F_147 ( V_222 , V_232 ) ;
break;
default:
F_2 ( L_108 , V_364 -> V_238 ) ;
F_79 () ;
break;
}
}
static void
F_156 ( struct V_221 * V_222 ,
struct V_4 * V_4 )
{
struct V_412 * V_413 = V_222 -> V_245 ;
struct V_221 * V_414 ;
while ( V_413 ) {
V_414 = F_157 ( V_413 , struct V_221 , V_243 ) ;
V_413 = F_158 ( V_413 ) ;
F_155 ( V_414 , V_4 ) ;
}
F_155 ( V_222 , V_4 ) ;
}
static void
F_159 ( struct V_4 * V_4 , struct V_9 * V_10 )
{
struct V_412 * V_413 ;
struct V_363 * V_364 ;
struct V_221 * V_414 ;
F_9 ( & V_4 -> V_161 ) ;
V_413 = F_92 ( & V_4 -> V_244 ) ;
V_4 -> V_240 = 0 ;
F_10 ( & V_4 -> V_161 ) ;
while ( V_413 ) {
V_414 = F_157 ( V_413 , struct V_221 , V_243 ) ;
V_413 = F_158 ( V_413 ) ;
V_364 = & V_414 -> V_232 -> V_237 ;
if ( V_364 -> V_402 )
F_154 ( V_364 -> V_402 ,
& V_4 -> V_200 ) ;
else
F_86 ( & V_4 -> V_200 ) ;
F_140 ( V_414 , V_414 -> V_232 , V_10 , true ) ;
}
}
static void
F_160 ( struct V_221 * V_222 , struct V_4 * V_4 )
{
struct V_9 * V_10 = V_4 -> V_7 -> V_20 ;
struct V_232 * V_232 = V_222 -> V_232 ;
struct V_412 * V_413 = V_222 -> V_245 ;
struct V_363 * V_364 ;
struct V_221 * V_414 ;
while ( V_413 ) {
V_414 = F_157 ( V_413 , struct V_221 , V_243 ) ;
V_413 = F_158 ( V_413 ) ;
V_364 = & V_414 -> V_232 -> V_237 ;
if ( V_364 -> V_402 )
F_154 ( V_364 -> V_402 ,
& V_4 -> V_200 ) ;
else
F_86 ( & V_4 -> V_200 ) ;
F_140 ( V_414 , V_414 -> V_232 , V_10 , true ) ;
}
V_222 -> V_245 = NULL ;
if ( ! V_232 )
F_139 ( V_222 , V_10 ) ;
else
F_140 ( V_222 , V_232 , V_10 , true ) ;
}
static void
F_161 ( struct V_4 * V_4 )
{
struct V_9 * V_10 = V_4 -> V_7 -> V_20 ;
struct V_248 * V_137 = V_4 -> V_137 ;
if ( V_4 -> V_199 )
return;
F_159 ( V_4 , V_10 ) ;
if ( V_137 -> V_138 ) {
F_162 ( V_137 -> V_138 -> V_136 ) ;
F_163 ( V_137 -> V_138 -> V_136 ) ;
}
while ( F_73 ( & V_4 -> V_200 ) )
F_164 ( 3000 ) ;
F_9 ( & V_4 -> V_161 ) ;
V_4 -> V_154 = V_415 ;
F_10 ( & V_4 -> V_161 ) ;
F_165 ( V_4 -> V_137 , 0 ) ;
F_75 ( & V_4 -> V_159 ) ;
}
static void
V_94 ( struct V_194 * V_195 )
{
struct V_71 * V_72 = F_69 ( V_195 ,
struct V_71 , V_93 ) ;
struct V_19 * V_20 = V_72 -> V_20 ;
int V_87 = V_72 -> V_87 ;
struct V_416 * V_417 = V_20 -> V_32 [ V_87 ] ;
struct V_4 * V_4 ;
struct V_221 * V_222 ;
struct V_418 V_419 ;
while ( F_166 ( V_417 , 1 , & V_419 ) == 1 ) {
V_222 = (struct V_221 * ) ( unsigned long ) V_419 . V_217 ;
V_4 = V_419 . V_51 -> V_30 ;
if ( V_419 . V_203 == V_420 ) {
F_156 ( V_222 , V_4 ) ;
} else {
F_7 ( L_109 ) ;
F_7 ( L_110 , V_419 . V_203 ) ;
F_7 ( L_111 , V_419 . V_421 ) ;
if ( V_419 . V_217 != V_422 ) {
if ( V_222 -> V_242 )
continue;
F_86 ( & V_4 -> V_200 ) ;
F_160 ( V_222 , V_4 ) ;
}
}
}
F_28 ( V_417 , V_97 ) ;
}
static void
V_95 ( struct V_416 * V_423 , void * V_3 )
{
struct V_71 * V_72 = (struct V_71 * ) V_3 ;
F_153 ( V_409 , & V_72 -> V_93 ) ;
}
static void
V_89 ( struct V_194 * V_195 )
{
struct V_71 * V_72 = F_69 ( V_195 ,
struct V_71 , V_88 ) ;
struct V_19 * V_20 = V_72 -> V_20 ;
int V_87 = V_72 -> V_87 ;
struct V_416 * V_424 = V_20 -> V_34 [ V_87 ] ;
struct V_4 * V_4 ;
struct V_52 * V_53 ;
struct V_418 V_419 ;
unsigned long V_351 ;
while ( F_166 ( V_424 , 1 , & V_419 ) == 1 ) {
V_53 = (struct V_52 * ) ( unsigned long ) V_419 . V_217 ;
V_4 = V_419 . V_51 -> V_30 ;
if ( V_419 . V_203 == V_420 ) {
V_351 = ( unsigned long ) V_419 . V_425 ;
F_127 ( V_53 , V_4 , V_351 ) ;
} else {
F_7 ( L_112 ) ;
if ( V_419 . V_203 != V_426 ) {
F_7 ( L_113 , V_419 . V_203 ) ;
F_7 ( L_114 ,
V_419 . V_421 ) ;
}
V_4 -> V_199 -- ;
F_161 ( V_4 ) ;
}
}
F_28 ( V_424 , V_97 ) ;
}
static void
V_90 ( struct V_416 * V_423 , void * V_3 )
{
struct V_71 * V_72 = (struct V_71 * ) V_3 ;
F_153 ( V_427 , & V_72 -> V_88 ) ;
}
static int
F_167 ( struct V_4 * V_4 , struct V_232 * V_232 )
{
struct V_223 * V_428 ;
int V_13 ;
F_84 ( & V_4 -> V_200 ) ;
V_13 = F_85 ( V_4 -> V_50 , & V_232 -> V_222 . V_224 ,
& V_428 ) ;
if ( V_13 ) {
F_2 ( L_115 , V_13 ) ;
F_86 ( & V_4 -> V_200 ) ;
return V_13 ;
}
return V_13 ;
}
static int
F_146 ( struct V_248 * V_137 , struct V_291 * V_292 )
{
struct V_232 * V_232 = F_101 ( V_292 ) ;
struct V_4 * V_4 = (struct V_4 * ) V_137 -> V_3 ;
struct V_223 * V_224 = & V_232 -> V_222 . V_224 ;
struct V_429 * V_296 = (struct V_429 * )
& V_232 -> V_222 . V_252 ;
F_87 ( V_4 , V_232 , & V_232 -> V_222 ) ;
F_168 ( V_292 , V_137 , true , V_296 ) ;
F_89 ( V_4 , & V_232 -> V_222 ) ;
if ( V_292 -> V_309 . V_430 &&
( ( V_292 -> V_309 . V_431 & V_432 ) ||
( V_292 -> V_309 . V_431 & V_433 ) ) ) {
struct V_9 * V_10 = V_4 -> V_7 -> V_20 ;
struct V_54 * V_255 = & V_232 -> V_222 . V_227 [ 1 ] ;
V_142 V_434 , V_435 ;
F_169 ( V_292 -> V_309 . V_436 ,
V_292 -> V_430 ) ;
V_292 -> V_309 . V_436 += sizeof( V_437 ) ;
V_434 = - ( V_292 -> V_309 . V_436 ) & 3 ;
F_170 ( V_296 -> V_322 , ( V_142 ) V_292 -> V_309 . V_436 ) ;
V_435 = V_292 -> V_309 . V_436 + V_434 ;
V_232 -> V_376 = F_15 ( V_10 ,
( void * ) V_292 -> V_430 , V_435 ,
V_172 ) ;
V_232 -> V_377 = V_435 ;
V_255 -> V_65 = V_232 -> V_376 ;
V_255 -> V_66 = V_435 ;
V_255 -> V_67 = V_4 -> V_68 -> V_67 ;
V_232 -> V_222 . V_219 = 2 ;
}
F_90 ( V_4 , V_232 , V_224 , true ) ;
F_7 ( L_116 ) ;
return F_167 ( V_4 , V_232 ) ;
}
static void
F_171 ( struct V_248 * V_137 , struct V_291 * V_292 )
{
struct V_232 * V_232 = F_101 ( V_292 ) ;
struct V_4 * V_4 = (struct V_4 * ) V_137 -> V_3 ;
struct V_19 * V_20 = V_4 -> V_21 ;
F_52 ( & V_137 -> V_369 ) ;
if ( ! F_40 ( & V_292 -> V_370 ) )
F_135 ( & V_292 -> V_370 ) ;
F_53 ( & V_137 -> V_369 ) ;
if ( V_292 -> V_371 == V_172 )
F_136 ( V_292 ) ;
V_20 -> V_79 ( V_232 , V_4 ) ;
}
static enum V_438
F_172 ( struct V_248 * V_137 )
{
struct V_4 * V_4 = (struct V_4 * ) V_137 -> V_3 ;
struct V_19 * V_20 = V_4 -> V_21 ;
if ( V_20 -> V_83 )
return V_439 ;
return V_440 ;
}
static int
F_173 ( struct V_291 * V_292 , struct V_248 * V_137 ,
bool V_441 )
{
struct V_232 * V_232 = F_101 ( V_292 ) ;
struct V_4 * V_4 = (struct V_4 * ) V_137 -> V_3 ;
struct V_223 * V_224 = & V_232 -> V_222 . V_224 ;
F_87 ( V_4 , V_232 , & V_232 -> V_222 ) ;
F_174 ( V_292 , V_137 , (struct V_442 * )
& V_232 -> V_222 . V_252 ,
V_441 ) ;
F_89 ( V_4 , & V_232 -> V_222 ) ;
F_90 ( V_4 , V_232 , V_224 , false ) ;
F_7 ( L_117 ) ;
return F_167 ( V_4 , V_232 ) ;
}
static int
F_175 ( struct V_291 * V_292 , struct V_248 * V_137 )
{
struct V_232 * V_232 = F_101 ( V_292 ) ;
struct V_4 * V_4 = (struct V_4 * ) V_137 -> V_3 ;
struct V_223 * V_224 = & V_232 -> V_222 . V_224 ;
F_87 ( V_4 , V_232 , & V_232 -> V_222 ) ;
F_176 ( V_292 , V_137 , (struct V_443 * )
& V_232 -> V_222 . V_252 ) ;
F_89 ( V_4 , & V_232 -> V_222 ) ;
F_90 ( V_4 , V_232 , V_224 , false ) ;
F_7 ( L_118 ) ;
return F_167 ( V_4 , V_232 ) ;
}
static int
F_177 ( struct V_291 * V_292 , struct V_248 * V_137 )
{
struct V_232 * V_232 = F_101 ( V_292 ) ;
struct V_4 * V_4 = (struct V_4 * ) V_137 -> V_3 ;
struct V_223 * V_224 = & V_232 -> V_222 . V_224 ;
F_87 ( V_4 , V_232 , & V_232 -> V_222 ) ;
F_178 ( V_292 , V_137 , (struct V_444 * )
& V_232 -> V_222 . V_252 ) ;
F_89 ( V_4 , & V_232 -> V_222 ) ;
F_90 ( V_4 , V_232 , V_224 , false ) ;
F_7 ( L_119 ) ;
return F_167 ( V_4 , V_232 ) ;
}
static int
F_179 ( struct V_291 * V_292 , struct V_248 * V_137 )
{
struct V_232 * V_232 = F_101 ( V_292 ) ;
struct V_4 * V_4 = (struct V_4 * ) V_137 -> V_3 ;
struct V_223 * V_224 = & V_232 -> V_222 . V_224 ;
struct V_9 * V_10 = V_4 -> V_7 -> V_20 ;
struct V_54 * V_255 = & V_232 -> V_222 . V_227 [ 1 ] ;
struct V_445 * V_296 =
(struct V_445 * ) & V_232 -> V_222 . V_252 ;
F_87 ( V_4 , V_232 , & V_232 -> V_222 ) ;
F_180 ( V_292 , V_137 , V_296 ) ;
F_89 ( V_4 , & V_232 -> V_222 ) ;
F_170 ( V_296 -> V_322 , V_286 ) ;
V_232 -> V_376 = F_15 ( V_10 ,
( void * ) V_292 -> V_446 , V_286 ,
V_172 ) ;
V_232 -> V_377 = V_286 ;
V_255 -> V_65 = V_232 -> V_376 ;
V_255 -> V_66 = V_286 ;
V_255 -> V_67 = V_4 -> V_68 -> V_67 ;
V_232 -> V_222 . V_219 = 2 ;
F_90 ( V_4 , V_232 , V_224 , false ) ;
F_7 ( L_120 ) ;
return F_167 ( V_4 , V_232 ) ;
}
static int
F_181 ( struct V_291 * V_292 , struct V_248 * V_137 )
{
struct V_232 * V_232 = F_101 ( V_292 ) ;
struct V_4 * V_4 = (struct V_4 * ) V_137 -> V_3 ;
struct V_223 * V_224 = & V_232 -> V_222 . V_224 ;
struct V_447 * V_296 =
(struct V_447 * ) & V_232 -> V_222 . V_252 ;
V_142 V_448 ;
int V_303 ;
F_87 ( V_4 , V_232 , & V_232 -> V_222 ) ;
V_303 = F_182 ( V_292 , V_137 , V_296 , V_449 ) ;
if ( V_303 < 0 )
return V_303 ;
V_448 = V_303 ;
F_89 ( V_4 , & V_232 -> V_222 ) ;
if ( V_448 ) {
struct V_9 * V_10 = V_4 -> V_7 -> V_20 ;
struct V_54 * V_255 = & V_232 -> V_222 . V_227 [ 1 ] ;
void * V_450 = V_292 -> V_446 ;
V_232 -> V_376 = F_15 ( V_10 ,
V_450 , V_448 , V_172 ) ;
V_232 -> V_377 = V_448 ;
V_255 -> V_65 = V_232 -> V_376 ;
V_255 -> V_66 = V_448 ;
V_255 -> V_67 = V_4 -> V_68 -> V_67 ;
V_232 -> V_222 . V_219 = 2 ;
}
F_90 ( V_4 , V_232 , V_224 , false ) ;
F_7 ( L_121 ) ;
return F_167 ( V_4 , V_232 ) ;
}
static int
F_183 ( struct V_4 * V_4 , struct V_232 * V_232 ,
struct V_54 * V_54 , struct V_223 * V_224 ,
V_142 V_451 , V_142 V_355 )
{
struct V_291 * V_292 = V_232 -> V_291 ;
struct V_297 * V_319 , * V_452 ;
struct V_9 * V_10 = V_4 -> V_7 -> V_20 ;
V_142 V_323 , V_324 ;
int V_57 = 0 , V_302 ;
V_323 = V_355 / V_311 ;
V_319 = & V_292 -> V_309 . V_310 [ V_323 ] ;
V_302 = F_23 ( V_292 -> V_309 . V_453 - V_323 , V_4 -> V_14 ) ;
V_324 = V_355 % V_311 ;
V_224 -> V_218 = V_54 ;
V_224 -> V_219 = V_302 ;
V_224 -> V_217 = ( unsigned long ) & V_232 -> V_222 ;
F_184 (sg_start, tmp_sg, sg_nents, i) {
F_7 ( L_122 ,
( unsigned long long ) V_452 -> V_454 ,
V_452 -> V_66 , V_324 ) ;
V_54 -> V_65 = F_185 ( V_10 , V_452 ) + V_324 ;
V_54 -> V_66 = F_21 ( V_142 , V_451 ,
F_186 ( V_10 , V_452 ) - V_324 ) ;
V_54 -> V_67 = V_4 -> V_68 -> V_67 ;
F_7 ( L_123 ,
V_54 -> V_65 , V_54 -> V_66 , V_54 -> V_67 ) ;
V_324 = 0 ;
V_451 -= V_54 -> V_66 ;
V_54 ++ ;
F_7 ( L_124 , V_54 ) ;
}
F_7 ( L_125 ,
V_224 -> V_218 , V_224 -> V_219 ) ;
return V_302 ;
}
static int
V_81 ( struct V_248 * V_137 , struct V_291 * V_292 ,
struct V_363 * V_364 )
{
struct V_309 * V_309 = & V_292 -> V_309 ;
struct V_232 * V_232 = F_101 ( V_292 ) ;
struct V_4 * V_4 = (struct V_4 * ) V_137 -> V_3 ;
struct V_358 * V_289 = & V_364 -> V_289 ;
struct V_223 * V_224 ;
struct V_54 * V_54 ;
V_142 V_355 , V_455 , V_451 , V_456 , V_457 = 0 ;
int V_13 = 0 , V_57 , V_458 ;
V_232 -> V_222 . V_232 = V_232 ;
V_355 = V_364 -> V_238 == V_411 ? V_292 -> V_312 : 0 ;
V_13 = F_128 ( V_4 , V_232 , V_309 -> V_310 ,
V_309 -> V_453 , V_309 -> V_313 ,
V_355 , V_364 -> V_238 , & V_364 -> V_289 ) ;
if ( V_13 )
return V_13 ;
V_451 = V_289 -> V_361 ;
V_355 = V_289 -> V_355 ;
V_54 = F_14 ( sizeof( struct V_54 ) * V_289 -> V_354 , V_60 ) ;
if ( ! V_54 ) {
F_4 ( L_126 ) ;
V_13 = - V_70 ;
goto V_459;
}
V_364 -> V_54 = V_54 ;
V_364 -> V_402 = F_106 ( V_289 -> V_354 , V_4 -> V_14 ) ;
V_364 -> V_224 = F_14 ( sizeof( struct V_223 ) * V_364 -> V_402 ,
V_60 ) ;
if ( ! V_364 -> V_224 ) {
F_7 ( L_127 ) ;
V_13 = - V_70 ;
goto V_459;
}
V_364 -> V_232 = V_232 ;
V_456 = V_4 -> V_14 * V_311 ;
for ( V_57 = 0 ; V_57 < V_364 -> V_402 ; V_57 ++ ) {
V_224 = & V_232 -> V_237 . V_224 [ V_57 ] ;
V_455 = F_23 ( V_451 , V_456 ) ;
V_224 -> V_230 = 0 ;
if ( V_364 -> V_238 == V_360 ) {
V_224 -> V_228 = V_460 ;
V_224 -> V_364 . V_461 . V_462 = V_232 -> V_331 + V_355 ;
V_224 -> V_364 . V_461 . V_463 = V_232 -> V_330 ;
if ( V_57 + 1 == V_364 -> V_402 )
V_224 -> V_220 = & V_232 -> V_222 . V_224 ;
else
V_224 -> V_220 = & V_364 -> V_224 [ V_57 + 1 ] ;
} else {
V_224 -> V_228 = V_464 ;
V_224 -> V_364 . V_461 . V_462 = V_232 -> V_333 + V_457 ;
V_224 -> V_364 . V_461 . V_463 = V_232 -> V_332 ;
if ( V_57 + 1 == V_364 -> V_402 )
V_224 -> V_230 = V_231 ;
else
V_224 -> V_220 = & V_364 -> V_224 [ V_57 + 1 ] ;
}
V_458 = F_183 ( V_4 , V_232 , V_54 ,
V_224 , V_455 , V_355 ) ;
V_54 += V_458 ;
V_355 += V_455 ;
V_457 += V_455 ;
V_451 -= V_455 ;
}
return 0 ;
V_459:
F_131 ( V_4 , V_289 ) ;
return V_13 ;
}
static int
F_187 ( struct V_9 * V_10 ,
struct V_297 * V_319 , int V_302 , T_2 * V_465 )
{
T_2 V_466 , V_467 , V_468 , V_469 = 0 ;
struct V_297 * V_452 ;
int V_57 = 0 , V_470 , V_471 , V_472 ;
V_472 = 0 ;
V_470 = 1 ;
V_471 = V_302 - 1 ;
F_184 (sg_start, tmp_sg, sg_nents, i) {
V_466 = F_185 ( V_10 , V_452 ) ;
if ( V_470 )
V_469 = V_466 ;
V_467 = V_466 + F_186 ( V_10 , V_452 ) ;
F_7 ( L_128 ,
V_57 , ( unsigned long long ) V_452 -> V_454 ,
V_452 -> V_66 ) ;
if ( ( V_467 & ~ V_473 ) && V_57 < V_471 ) {
V_470 = 0 ;
continue;
}
V_470 = 1 ;
V_468 = V_469 & V_473 ;
do {
V_465 [ V_472 ++ ] = V_468 ;
F_7 ( L_129 ,
V_472 - 1 , V_468 ) ;
V_468 += V_311 ;
} while ( V_468 < V_467 );
}
return V_472 ;
}
static int
F_188 ( struct V_4 * V_4 ,
struct V_102 * V_103 ,
struct V_358 * V_474 ,
enum V_475 V_119 ,
struct V_54 * V_247 )
{
struct V_9 * V_10 = V_4 -> V_7 -> V_20 ;
struct V_378 * V_476 ;
struct V_477 * V_478 ;
struct V_223 V_479 , V_480 ;
struct V_223 * V_481 , * V_364 = NULL ;
int V_13 , V_482 ;
V_142 V_324 ;
T_1 V_483 ;
if ( V_474 -> V_362 == 1 ) {
V_247 -> V_67 = V_4 -> V_68 -> V_67 ;
V_247 -> V_65 = F_185 ( V_10 , & V_474 -> V_298 [ 0 ] ) ;
V_247 -> V_66 = F_186 ( V_10 , & V_474 -> V_298 [ 0 ] ) ;
F_7 ( L_130 ,
V_484 , __LINE__ , V_247 -> V_65 , V_247 -> V_66 ,
V_247 -> V_67 ) ;
return 0 ;
}
if ( V_119 == V_120 ) {
V_476 = V_103 -> V_108 ;
V_478 = V_103 -> V_107 ;
} else {
V_476 = V_103 -> V_109 -> V_111 ;
V_478 = V_103 -> V_109 -> V_110 ;
}
V_324 = V_474 -> V_355 % V_311 ;
F_7 ( L_131 ,
V_103 , V_474 -> V_354 , V_474 -> V_355 ) ;
V_482 = F_187 ( V_10 , V_474 -> V_298 , V_474 -> V_354 ,
& V_478 -> V_118 [ 0 ] ) ;
if ( ! ( V_103 -> V_119 & V_120 ) ) {
memset ( & V_480 , 0 , sizeof( V_480 ) ) ;
V_480 . V_217 = V_422 ;
V_480 . V_228 = V_485 ;
V_480 . V_486 . V_487 = V_476 -> V_463 ;
V_364 = & V_480 ;
V_483 = ( T_1 ) ( V_476 -> V_463 & 0x000000FF ) ;
F_189 ( V_476 , ++ V_483 ) ;
}
memset ( & V_479 , 0 , sizeof( V_479 ) ) ;
V_479 . V_217 = V_422 ;
V_479 . V_228 = V_488 ;
V_479 . V_364 . V_489 . V_490 = V_478 -> V_118 [ 0 ] + V_324 ;
V_479 . V_364 . V_489 . V_118 = V_478 ;
V_479 . V_364 . V_489 . V_491 = V_482 ;
V_479 . V_364 . V_489 . V_492 = V_493 ;
V_479 . V_364 . V_489 . V_66 = V_474 -> V_361 ;
V_479 . V_364 . V_489 . V_463 = V_476 -> V_463 ;
V_479 . V_364 . V_489 . V_494 = V_179 ;
if ( ! V_364 )
V_364 = & V_479 ;
else
V_364 -> V_220 = & V_479 ;
V_13 = F_85 ( V_4 -> V_50 , V_364 , & V_481 ) ;
if ( V_13 ) {
F_2 ( L_132 , V_13 ) ;
return V_13 ;
}
V_103 -> V_119 &= ~ V_119 ;
V_247 -> V_67 = V_476 -> V_67 ;
V_247 -> V_65 = V_478 -> V_118 [ 0 ] + V_324 ;
V_247 -> V_66 = V_474 -> V_361 ;
F_7 ( L_130 ,
V_484 , __LINE__ , V_247 -> V_65 , V_247 -> V_66 ,
V_247 -> V_67 ) ;
return V_13 ;
}
static inline enum V_495
F_190 ( enum V_496 V_497 )
{
switch ( V_497 ) {
case V_498 :
return V_499 ;
case V_500 :
return V_501 ;
case V_502 :
return V_503 ;
case V_504 :
return V_505 ;
default:
return V_499 ;
}
}
static int
F_191 ( struct V_309 * V_309 , struct V_506 * V_507 )
{
enum V_495 V_508 = F_190 ( V_309 -> V_497 ) ;
V_507 -> V_474 . V_509 = V_510 ;
V_507 -> V_511 . V_509 = V_510 ;
V_507 -> V_474 . V_512 . V_513 . V_514 =
V_309 -> V_386 -> V_387 . V_385 ;
V_507 -> V_511 . V_512 . V_513 . V_514 =
V_309 -> V_386 -> V_387 . V_385 ;
switch ( V_309 -> V_515 ) {
case V_516 :
case V_517 :
V_507 -> V_474 . V_512 . V_513 . type = V_499 ;
V_507 -> V_511 . V_512 . V_513 . type = V_508 ;
V_507 -> V_511 . V_512 . V_513 . V_518 = V_519 ;
V_507 -> V_511 . V_512 . V_513 . V_520 = V_309 -> V_521 ;
break;
case V_522 :
case V_523 :
V_507 -> V_474 . V_512 . V_513 . type = V_508 ;
V_507 -> V_474 . V_512 . V_513 . V_518 = V_519 ;
V_507 -> V_474 . V_512 . V_513 . V_520 = V_309 -> V_521 ;
V_507 -> V_511 . V_512 . V_513 . type = V_499 ;
break;
case V_524 :
case V_525 :
V_507 -> V_474 . V_512 . V_513 . type = V_508 ;
V_507 -> V_474 . V_512 . V_513 . V_518 = V_519 ;
V_507 -> V_474 . V_512 . V_513 . V_520 = V_309 -> V_521 ;
V_507 -> V_511 . V_512 . V_513 . type = V_508 ;
V_507 -> V_511 . V_512 . V_513 . V_518 = V_519 ;
V_507 -> V_511 . V_512 . V_513 . V_520 = V_309 -> V_521 ;
break;
default:
F_2 ( L_133 , V_309 -> V_515 ) ;
return - V_335 ;
}
return 0 ;
}
static inline T_1
F_192 ( T_1 V_526 )
{
return ( V_526 & V_527 ? 0xc0 : 0 ) |
( V_526 & V_528 ? 0x30 : 0 ) |
( V_526 & V_528 ? 0x0f : 0 ) ;
}
static int
F_193 ( struct V_4 * V_4 , struct V_309 * V_309 ,
struct V_102 * V_103 ,
struct V_54 * V_529 , struct V_54 * V_530 ,
struct V_54 * V_531 )
{
struct V_223 V_532 , V_480 ;
struct V_223 * V_481 , * V_364 = NULL ;
struct V_123 * V_109 = V_103 -> V_109 ;
struct V_506 V_507 ;
int V_13 ;
V_142 V_483 ;
memset ( & V_507 , 0 , sizeof( V_507 ) ) ;
V_13 = F_191 ( V_309 , & V_507 ) ;
if ( V_13 )
goto V_146;
V_507 . V_533 = F_192 ( V_309 -> V_526 ) ;
if ( ! ( V_103 -> V_119 & V_132 ) ) {
memset ( & V_480 , 0 , sizeof( V_480 ) ) ;
V_480 . V_228 = V_485 ;
V_480 . V_217 = V_422 ;
V_480 . V_486 . V_487 = V_109 -> V_112 -> V_463 ;
V_364 = & V_480 ;
V_483 = ( T_1 ) ( V_109 -> V_112 -> V_463 & 0x000000FF ) ;
F_189 ( V_109 -> V_112 , ++ V_483 ) ;
}
memset ( & V_532 , 0 , sizeof( V_532 ) ) ;
V_532 . V_228 = V_534 ;
V_532 . V_217 = V_422 ;
V_532 . V_218 = V_529 ;
V_532 . V_219 = 1 ;
V_532 . V_364 . V_535 . V_494 = V_179 ;
V_532 . V_364 . V_535 . V_507 = & V_507 ;
V_532 . V_364 . V_535 . V_112 = V_109 -> V_112 ;
if ( V_309 -> V_536 )
V_532 . V_364 . V_535 . V_366 = V_530 ;
if ( ! V_364 )
V_364 = & V_532 ;
else
V_364 -> V_220 = & V_532 ;
V_13 = F_85 ( V_4 -> V_50 , V_364 , & V_481 ) ;
if ( V_13 ) {
F_2 ( L_132 , V_13 ) ;
goto V_146;
}
V_103 -> V_119 &= ~ V_132 ;
V_531 -> V_67 = V_109 -> V_112 -> V_67 ;
V_531 -> V_65 = 0 ;
V_531 -> V_66 = V_309 -> V_313 ;
if ( V_309 -> V_515 != V_523 &&
V_309 -> V_515 != V_522 )
V_531 -> V_66 += V_309 -> V_537 ;
F_7 ( L_134 ,
V_531 -> V_65 , V_531 -> V_66 ,
V_531 -> V_67 ) ;
V_146:
return V_13 ;
}
static int
V_78 ( struct V_248 * V_137 , struct V_291 * V_292 ,
struct V_363 * V_364 )
{
struct V_309 * V_309 = & V_292 -> V_309 ;
struct V_232 * V_232 = F_101 ( V_292 ) ;
struct V_4 * V_4 = V_137 -> V_3 ;
struct V_54 V_529 ;
struct V_223 * V_224 ;
struct V_102 * V_103 = NULL ;
V_142 V_355 ;
int V_13 = 0 ;
unsigned long V_129 ;
V_232 -> V_222 . V_232 = V_232 ;
V_355 = V_364 -> V_238 == V_411 ? V_292 -> V_312 : 0 ;
V_13 = F_128 ( V_4 , V_232 , V_309 -> V_310 ,
V_309 -> V_453 , V_309 -> V_313 ,
V_355 , V_364 -> V_238 , & V_364 -> V_289 ) ;
if ( V_13 )
return V_13 ;
if ( V_364 -> V_289 . V_362 != 1 ||
V_309 -> V_515 != V_440 ) {
F_194 ( & V_4 -> V_162 , V_129 ) ;
V_103 = F_195 ( & V_4 -> V_105 ,
struct V_102 , V_106 ) ;
F_33 ( & V_103 -> V_106 ) ;
F_196 ( & V_4 -> V_162 , V_129 ) ;
V_364 -> V_103 = V_103 ;
}
V_13 = F_188 ( V_4 , V_103 , & V_364 -> V_289 ,
V_120 , & V_529 ) ;
if ( V_13 )
goto V_459;
if ( V_309 -> V_515 != V_440 ) {
struct V_54 V_530 , V_531 ;
if ( V_309 -> V_536 ) {
V_13 = F_128 ( V_4 , V_232 ,
V_309 -> V_536 ,
V_309 -> V_538 ,
V_309 -> V_537 ,
0 , V_364 -> V_238 , & V_364 -> V_366 ) ;
if ( V_13 )
goto V_459;
V_13 = F_188 ( V_4 , V_103 , & V_364 -> V_366 ,
V_127 , & V_530 ) ;
if ( V_13 )
goto V_539;
}
V_13 = F_193 ( V_4 , V_309 , V_103 ,
& V_529 , & V_530 , & V_531 ) ;
if ( V_13 )
goto V_539;
V_103 -> V_119 |= V_133 ;
memcpy ( & V_364 -> V_540 , & V_531 , sizeof( V_531 ) ) ;
} else
memcpy ( & V_364 -> V_540 , & V_529 , sizeof( V_529 ) ) ;
V_364 -> V_54 = & V_364 -> V_540 ;
V_364 -> V_402 = 1 ;
memset ( & V_364 -> V_541 , 0 , sizeof( * V_224 ) ) ;
V_364 -> V_224 = & V_364 -> V_541 ;
V_364 -> V_232 = V_232 ;
V_224 = & V_232 -> V_237 . V_541 ;
V_224 -> V_218 = & V_364 -> V_540 ;
V_224 -> V_219 = 1 ;
V_224 -> V_217 = ( unsigned long ) & V_232 -> V_222 ;
if ( V_364 -> V_238 == V_360 ) {
V_224 -> V_228 = V_460 ;
V_224 -> V_364 . V_461 . V_462 = V_232 -> V_331 ;
V_224 -> V_364 . V_461 . V_463 = V_232 -> V_330 ;
V_224 -> V_230 = V_309 -> V_515 == V_440 ?
0 : V_231 ;
} else {
V_224 -> V_228 = V_464 ;
V_224 -> V_364 . V_461 . V_462 = V_232 -> V_333 ;
V_224 -> V_364 . V_461 . V_463 = V_232 -> V_332 ;
V_224 -> V_230 = V_231 ;
}
return 0 ;
V_539:
if ( V_309 -> V_536 )
F_131 ( V_4 , & V_364 -> V_366 ) ;
V_459:
if ( V_103 ) {
F_194 ( & V_4 -> V_162 , V_129 ) ;
F_38 ( & V_103 -> V_106 , & V_4 -> V_105 ) ;
F_196 ( & V_4 -> V_162 , V_129 ) ;
}
F_131 ( V_4 , & V_364 -> V_289 ) ;
return V_13 ;
}
static int
F_197 ( struct V_248 * V_137 , struct V_291 * V_292 )
{
struct V_309 * V_309 = & V_292 -> V_309 ;
struct V_232 * V_232 = F_101 ( V_292 ) ;
struct V_363 * V_364 = & V_232 -> V_237 ;
struct V_4 * V_4 = (struct V_4 * ) V_137 -> V_3 ;
struct V_19 * V_20 = V_4 -> V_21 ;
struct V_223 * V_428 ;
int V_303 ;
F_7 ( L_135 ,
V_232 , V_309 -> V_313 ) ;
V_364 -> V_238 = V_360 ;
V_303 = V_20 -> V_77 ( V_137 , V_292 , V_364 ) ;
if ( V_303 ) {
F_2 ( L_136 , V_232 ) ;
return V_303 ;
}
if ( V_309 -> V_515 == V_440 ) {
F_87 ( V_4 , V_232 ,
& V_232 -> V_222 ) ;
F_168 ( V_292 , V_137 , true , (struct V_429 * )
& V_232 -> V_222 . V_252 ) ;
F_89 ( V_4 , & V_232 -> V_222 ) ;
F_90 ( V_4 , V_232 ,
& V_232 -> V_222 . V_224 , true ) ;
V_232 -> V_237 . V_541 . V_220 = & V_232 -> V_222 . V_224 ;
V_364 -> V_402 += 1 ;
}
F_198 ( V_364 -> V_402 , & V_4 -> V_200 ) ;
V_303 = F_85 ( V_4 -> V_50 , V_364 -> V_224 , & V_428 ) ;
if ( V_303 ) {
F_4 ( L_137 ) ;
F_154 ( V_364 -> V_402 , & V_4 -> V_200 ) ;
}
if ( V_309 -> V_515 == V_440 )
F_7 ( L_138
L_139 , V_232 ) ;
else
F_7 ( L_140 ,
V_232 ) ;
return 1 ;
}
static int
F_199 ( struct V_248 * V_137 , struct V_291 * V_292 , bool V_542 )
{
struct V_309 * V_309 = & V_292 -> V_309 ;
struct V_232 * V_232 = F_101 ( V_292 ) ;
struct V_363 * V_364 = & V_232 -> V_237 ;
struct V_4 * V_4 = (struct V_4 * ) V_137 -> V_3 ;
struct V_19 * V_20 = V_4 -> V_21 ;
struct V_223 * V_428 ;
int V_303 ;
F_7 ( L_141 ,
V_232 , V_309 -> V_313 , V_292 -> V_312 ) ;
V_364 -> V_238 = V_411 ;
V_303 = V_20 -> V_77 ( V_137 , V_292 , V_364 ) ;
if ( V_303 ) {
F_2 ( L_136 , V_232 ) ;
return V_303 ;
}
F_198 ( V_364 -> V_402 , & V_4 -> V_200 ) ;
V_303 = F_85 ( V_4 -> V_50 , V_364 -> V_224 , & V_428 ) ;
if ( V_303 ) {
F_4 ( L_142 ) ;
F_154 ( V_364 -> V_402 , & V_4 -> V_200 ) ;
}
F_7 ( L_143 ,
V_232 ) ;
return 0 ;
}
static int
F_200 ( struct V_248 * V_137 , struct V_291 * V_292 , int V_154 )
{
int V_13 ;
switch ( V_154 ) {
case V_543 :
V_13 = F_173 ( V_292 , V_137 , false ) ;
break;
default:
F_2 ( L_144 , V_154 ) ;
V_13 = - V_335 ;
break;
}
return V_13 ;
}
static int
F_201 ( struct V_248 * V_137 , struct V_291 * V_292 , int V_154 )
{
int V_13 ;
switch ( V_154 ) {
case V_407 :
V_13 = F_175 ( V_292 , V_137 ) ;
if ( ! V_13 ) {
F_7 ( L_145 ) ;
V_13 = - V_544 ;
}
break;
case V_545 :
V_13 = F_173 ( V_292 , V_137 , true ) ;
break;
case V_404 :
V_13 = F_177 ( V_292 , V_137 ) ;
break;
case V_406 :
V_13 = F_179 ( V_292 , V_137 ) ;
break;
case V_408 :
V_13 = F_181 ( V_292 , V_137 ) ;
break;
case V_546 :
V_13 = F_146 ( V_137 , V_292 ) ;
break;
default:
F_2 ( L_146 , V_154 ) ;
V_13 = - V_335 ;
break;
}
return V_13 ;
}
static int
F_202 ( struct V_148 * V_149 ,
struct V_547 * V_548 )
{
struct V_150 * V_150 ;
struct V_16 * V_549 ;
struct V_550 * V_551 ;
int V_13 ;
V_150 = F_14 ( sizeof( struct V_150 ) , V_60 ) ;
if ( ! V_150 ) {
F_2 ( L_147 ) ;
return - V_70 ;
}
F_203 ( & V_150 -> V_188 , 0 ) ;
F_57 ( & V_150 -> V_186 ) ;
F_37 ( & V_150 -> V_187 ) ;
F_55 ( & V_150 -> V_552 ) ;
V_551 = (struct V_550 * ) V_548 ;
F_7 ( L_148 , V_548 , V_551 ) ;
memcpy ( & V_149 -> V_553 , V_548 ,
sizeof( struct V_547 ) ) ;
V_549 = F_204 ( F_78 , V_149 , V_554 ,
V_46 ) ;
if ( F_26 ( V_549 ) ) {
F_2 ( L_149 ,
F_27 ( V_549 ) ) ;
V_13 = F_27 ( V_549 ) ;
goto V_166;
}
V_13 = F_205 ( V_549 , V_551 ) ;
if ( V_13 ) {
F_2 ( L_150 , V_13 ) ;
goto V_555;
}
V_13 = F_206 ( V_549 , V_556 ) ;
if ( V_13 ) {
F_2 ( L_151 , V_13 ) ;
goto V_555;
}
V_150 -> V_557 = V_549 ;
V_149 -> V_151 = V_150 ;
F_7 ( L_152 , V_549 -> V_3 ) ;
return 0 ;
V_555:
F_65 ( V_549 ) ;
V_166:
F_18 ( V_150 ) ;
return V_13 ;
}
static int
F_207 ( struct V_4 * V_4 )
{
struct V_16 * V_558 = V_4 -> V_7 ;
struct V_559 V_560 ;
int V_13 ;
memset ( & V_560 , 0 , sizeof( struct V_559 ) ) ;
V_560 . V_175 = V_4 -> V_175 ;
V_560 . V_561 = 7 ;
V_560 . V_562 = 7 ;
F_7 ( L_153 ) ;
V_13 = F_208 ( V_558 , & V_560 ) ;
if ( V_13 ) {
F_2 ( L_154 , V_13 ) ;
return V_13 ;
}
F_7 ( L_155 ) ;
return 0 ;
}
static int
F_209 ( struct V_248 * V_137 , struct V_249 * V_250 )
{
struct V_4 * V_4 = (struct V_4 * ) V_137 -> V_3 ;
int V_13 ;
F_7 ( L_156 , V_137 ) ;
if ( ! V_250 -> V_266 )
return 0 ;
V_13 = F_210 ( & V_4 -> V_157 ) ;
if ( V_13 )
return V_13 ;
F_7 ( L_157 , V_250 -> V_285 ) ;
return 0 ;
}
static void
F_211 ( struct V_148 * V_149 , struct V_248 * V_137 ,
struct V_4 * V_4 )
{
struct V_16 * V_558 = V_4 -> V_7 ;
struct V_563 * V_564 = & V_558 -> V_565 ;
struct V_566 * V_567 ;
struct V_568 * V_569 ;
V_137 -> V_570 = V_149 -> V_553 . V_571 ;
if ( V_149 -> V_553 . V_571 == V_572 ) {
V_569 = (struct V_568 * ) & V_564 -> V_65 . V_573 ;
snprintf ( V_137 -> V_574 , sizeof( V_137 -> V_574 ) , L_158 ,
& V_569 -> V_575 . V_576 ) ;
V_137 -> V_577 = F_212 ( V_569 -> V_578 ) ;
V_569 = (struct V_568 * ) & V_564 -> V_65 . V_579 ;
snprintf ( V_137 -> V_580 , sizeof( V_137 -> V_580 ) , L_158 ,
& V_569 -> V_575 . V_576 ) ;
V_137 -> V_581 = F_212 ( V_569 -> V_578 ) ;
} else {
V_567 = (struct V_566 * ) & V_564 -> V_65 . V_573 ;
sprintf ( V_137 -> V_574 , L_159 ,
& V_567 -> V_582 . V_583 ) ;
V_137 -> V_577 = F_212 ( V_567 -> V_584 ) ;
V_567 = (struct V_566 * ) & V_564 -> V_65 . V_579 ;
sprintf ( V_137 -> V_580 , L_159 ,
& V_567 -> V_582 . V_583 ) ;
V_137 -> V_581 = F_212 ( V_567 -> V_584 ) ;
}
}
static int
F_213 ( struct V_148 * V_149 , struct V_248 * V_137 )
{
struct V_150 * V_150 = (struct V_150 * ) V_149 -> V_151 ;
struct V_4 * V_4 ;
int V_585 = 0 , V_13 ;
V_586:
V_13 = F_214 ( & V_150 -> V_188 ) ;
if ( V_585 > 5 )
return - V_587 ;
F_52 ( & V_149 -> V_152 ) ;
if ( V_149 -> V_588 >= V_589 ) {
F_53 ( & V_149 -> V_152 ) ;
F_7 ( L_160 ,
V_149 -> V_588 ) ;
return - V_587 ;
}
F_53 ( & V_149 -> V_152 ) ;
F_9 ( & V_150 -> V_186 ) ;
if ( F_40 ( & V_150 -> V_187 ) ) {
F_10 ( & V_150 -> V_186 ) ;
V_585 ++ ;
goto V_586;
}
V_4 = F_195 ( & V_150 -> V_187 ,
struct V_4 , V_156 ) ;
F_135 ( & V_4 -> V_156 ) ;
F_10 ( & V_150 -> V_186 ) ;
V_137 -> V_3 = V_4 ;
V_4 -> V_137 = V_137 ;
V_585 = 0 ;
V_13 = F_93 ( V_4 ) ;
if ( V_13 )
return V_13 ;
V_13 = F_207 ( V_4 ) ;
if ( V_13 )
return V_13 ;
F_211 ( V_149 , V_137 , V_4 ) ;
F_7 ( L_161 , V_4 ) ;
return 0 ;
}
static void
F_215 ( struct V_148 * V_149 )
{
struct V_150 * V_150 = (struct V_150 * ) V_149 -> V_151 ;
F_65 ( V_150 -> V_557 ) ;
V_149 -> V_151 = NULL ;
F_18 ( V_150 ) ;
}
static void F_216 ( struct V_248 * V_137 )
{
struct V_4 * V_4 = V_137 -> V_3 ;
F_7 ( L_162 ) ;
F_9 ( & V_4 -> V_161 ) ;
if ( V_4 -> V_7 && ! V_4 -> V_202 ) {
F_7 ( L_163 ) ;
F_74 ( V_4 -> V_7 ) ;
}
if ( V_4 -> V_154 == V_155 ) {
F_10 ( & V_4 -> V_161 ) ;
return;
}
if ( V_4 -> V_154 == V_197 )
V_4 -> V_154 = V_198 ;
F_10 ( & V_4 -> V_161 ) ;
F_217 ( & V_4 -> V_159 ) ;
F_217 ( & V_4 -> V_158 ) ;
F_70 ( V_4 ) ;
}
static void F_218 ( struct V_248 * V_137 )
{
struct V_4 * V_4 = V_137 -> V_3 ;
F_70 ( V_4 ) ;
}
static int T_5 F_219 ( void )
{
int V_13 ;
V_427 = F_220 ( L_164 , 0 , 0 ) ;
if ( ! V_427 ) {
F_2 ( L_165 ) ;
return - V_70 ;
}
V_409 = F_220 ( L_166 , 0 , 0 ) ;
if ( ! V_409 ) {
F_2 ( L_167 ) ;
V_13 = - V_70 ;
goto V_590;
}
F_221 ( & V_591 ) ;
F_7 ( L_168 ) ;
return 0 ;
V_590:
F_222 ( V_427 ) ;
return V_13 ;
}
static void T_6 F_223 ( void )
{
F_224 () ;
F_222 ( V_409 ) ;
F_222 ( V_427 ) ;
F_225 ( & V_591 ) ;
F_7 ( L_169 ) ;
}
