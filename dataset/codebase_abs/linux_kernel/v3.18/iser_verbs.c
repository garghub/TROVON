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
struct V_12 * V_13 = & V_7 -> V_13 ;
int V_14 , V_15 ;
V_14 = F_6 ( V_7 -> V_16 , V_13 ) ;
if ( V_14 ) {
F_7 ( L_4 , V_7 -> V_16 -> V_8 ) ;
return V_14 ;
}
if ( V_7 -> V_16 -> V_17 && V_7 -> V_16 -> V_18 &&
V_7 -> V_16 -> V_19 && V_7 -> V_16 -> V_20 ) {
F_8 ( L_5 ) ;
V_7 -> V_21 = V_22 ;
V_7 -> V_23 = V_24 ;
V_7 -> V_25 = V_26 ;
V_7 -> V_27 = V_28 ;
} else
if ( V_13 -> V_29 & V_30 ) {
F_8 ( L_6 ) ;
V_7 -> V_21 = V_31 ;
V_7 -> V_23 = V_32 ;
V_7 -> V_25 = V_33 ;
V_7 -> V_27 = V_34 ;
} else {
F_2 ( L_7 ) ;
return - 1 ;
}
V_7 -> V_35 = F_9 ( V_36 ,
V_7 -> V_16 -> V_37 ) ;
F_8 ( L_8 ,
V_7 -> V_35 , V_7 -> V_16 -> V_8 ,
V_7 -> V_16 -> V_37 ) ;
V_7 -> V_38 = F_10 ( V_7 -> V_16 ) ;
if ( F_11 ( V_7 -> V_38 ) )
goto V_39;
for ( V_15 = 0 ; V_15 < V_7 -> V_35 ; V_15 ++ ) {
struct V_40 * V_41 = & V_7 -> V_42 [ V_15 ] ;
V_41 -> V_7 = V_7 ;
V_41 -> V_43 = F_12 ( V_7 -> V_16 ,
V_44 ,
F_1 ,
( void * ) V_41 ,
V_45 , V_15 ) ;
if ( F_11 ( V_41 -> V_43 ) ) {
V_41 -> V_43 = NULL ;
goto V_46;
}
if ( F_13 ( V_41 -> V_43 , V_47 ) )
goto V_46;
F_14 ( & V_41 -> V_48 , V_49 ,
( unsigned long ) V_41 ) ;
}
V_7 -> V_50 = F_15 ( V_7 -> V_38 , V_51 |
V_52 |
V_53 ) ;
if ( F_11 ( V_7 -> V_50 ) )
goto V_54;
F_16 ( & V_7 -> V_55 , V_7 -> V_16 ,
F_4 ) ;
if ( F_17 ( & V_7 -> V_55 ) )
goto V_56;
return 0 ;
V_56:
F_18 ( V_7 -> V_50 ) ;
V_54:
for ( V_15 = 0 ; V_15 < V_7 -> V_35 ; V_15 ++ )
F_19 ( & V_7 -> V_42 [ V_15 ] . V_48 ) ;
V_46:
for ( V_15 = 0 ; V_15 < V_7 -> V_35 ; V_15 ++ ) {
struct V_40 * V_41 = & V_7 -> V_42 [ V_15 ] ;
if ( V_41 -> V_43 )
F_20 ( V_41 -> V_43 ) ;
}
F_21 ( V_7 -> V_38 ) ;
V_39:
F_2 ( L_9 ) ;
return - 1 ;
}
static void F_22 ( struct V_11 * V_7 )
{
int V_15 ;
F_23 ( V_7 -> V_50 == NULL ) ;
for ( V_15 = 0 ; V_15 < V_7 -> V_35 ; V_15 ++ ) {
struct V_40 * V_41 = & V_7 -> V_42 [ V_15 ] ;
F_19 ( & V_41 -> V_48 ) ;
F_20 ( V_41 -> V_43 ) ;
V_41 -> V_43 = NULL ;
}
( void ) F_24 ( & V_7 -> V_55 ) ;
( void ) F_18 ( V_7 -> V_50 ) ;
( void ) F_21 ( V_7 -> V_38 ) ;
V_7 -> V_50 = NULL ;
V_7 -> V_38 = NULL ;
}
int V_22 ( struct V_57 * V_57 , unsigned V_58 )
{
struct V_11 * V_7 = V_57 -> V_7 ;
struct V_59 V_60 ;
int V_14 = - V_61 ;
V_57 -> V_62 . V_63 = F_25 ( sizeof( * V_57 -> V_62 . V_63 ) +
( sizeof( V_64 ) * ( V_65 + 1 ) ) ,
V_66 ) ;
if ( ! V_57 -> V_62 . V_63 )
return V_14 ;
V_57 -> V_62 . V_63 -> V_67 = ( V_64 * ) ( V_57 -> V_62 . V_63 + 1 ) ;
V_60 . V_68 = V_69 ;
V_60 . V_70 = V_65 + 1 ;
V_60 . V_71 = V_58 * 2 ;
V_60 . V_72 = V_58 ;
V_60 . V_73 = 0 ;
V_60 . V_74 = NULL ;
V_60 . V_75 = ( V_51 |
V_52 |
V_53 ) ;
V_57 -> V_62 . V_76 = F_26 ( V_7 -> V_38 , & V_60 ) ;
if ( ! F_11 ( V_57 -> V_62 . V_76 ) )
return 0 ;
F_27 ( V_57 -> V_62 . V_63 ) ;
V_57 -> V_62 . V_63 = NULL ;
V_14 = F_28 ( V_57 -> V_62 . V_76 ) ;
V_57 -> V_62 . V_76 = NULL ;
if ( V_14 != - V_77 ) {
F_2 ( L_10 , V_14 ) ;
return V_14 ;
} else {
F_29 ( L_11 ) ;
return 0 ;
}
}
void V_24 ( struct V_57 * V_57 )
{
F_8 ( L_12 ,
V_57 , V_57 -> V_62 . V_76 ) ;
if ( V_57 -> V_62 . V_76 != NULL )
F_30 ( V_57 -> V_62 . V_76 ) ;
V_57 -> V_62 . V_76 = NULL ;
F_27 ( V_57 -> V_62 . V_63 ) ;
V_57 -> V_62 . V_63 = NULL ;
}
static int
F_31 ( struct V_16 * V_16 , struct V_78 * V_38 ,
bool V_79 , struct V_80 * V_81 )
{
int V_14 ;
V_81 -> V_82 = F_32 ( V_16 ,
V_65 + 1 ) ;
if ( F_11 ( V_81 -> V_82 ) ) {
V_14 = F_28 ( V_81 -> V_82 ) ;
F_2 ( L_13 ,
V_14 ) ;
return F_28 ( V_81 -> V_82 ) ;
}
V_81 -> V_83 = F_33 ( V_38 , V_65 + 1 ) ;
if ( F_11 ( V_81 -> V_83 ) ) {
V_14 = F_28 ( V_81 -> V_83 ) ;
F_2 ( L_14 , V_14 ) ;
goto V_84;
}
V_81 -> V_85 |= V_86 ;
if ( V_79 ) {
struct V_87 V_88 = { 0 } ;
struct V_89 * V_90 = NULL ;
V_81 -> V_90 = F_34 ( sizeof( * V_81 -> V_90 ) , V_66 ) ;
if ( ! V_81 -> V_90 ) {
F_2 ( L_15 ) ;
V_14 = - V_61 ;
goto V_91;
}
V_90 = V_81 -> V_90 ;
V_90 -> V_92 = F_32 ( V_16 ,
V_65 ) ;
if ( F_11 ( V_90 -> V_92 ) ) {
V_14 = F_28 ( V_90 -> V_92 ) ;
F_2 ( L_16 ,
V_14 ) ;
goto V_93;
}
V_90 -> V_94 = F_33 ( V_38 ,
V_65 + 1 ) ;
if ( F_11 ( V_90 -> V_94 ) ) {
V_14 = F_28 ( V_90 -> V_94 ) ;
F_2 ( L_17 ,
V_14 ) ;
goto V_95;
}
V_81 -> V_85 |= V_96 ;
V_88 . V_97 = 2 ;
V_88 . V_98 |= V_99 ;
V_90 -> V_100 = F_35 ( V_38 , & V_88 ) ;
if ( F_11 ( V_90 -> V_100 ) ) {
V_14 = F_28 ( V_90 -> V_100 ) ;
F_2 ( L_18 ,
V_14 ) ;
goto V_101;
}
V_81 -> V_85 |= V_102 ;
}
V_81 -> V_85 &= ~ V_103 ;
F_36 ( L_19 ,
V_81 , V_81 -> V_82 -> V_104 ) ;
return 0 ;
V_101:
F_18 ( V_81 -> V_90 -> V_94 ) ;
V_95:
F_37 ( V_81 -> V_90 -> V_92 ) ;
V_93:
F_27 ( V_81 -> V_90 ) ;
V_91:
F_18 ( V_81 -> V_83 ) ;
V_84:
F_37 ( V_81 -> V_82 ) ;
return V_14 ;
}
int V_31 ( struct V_57 * V_57 , unsigned V_58 )
{
struct V_11 * V_7 = V_57 -> V_7 ;
struct V_80 * V_81 ;
int V_15 , V_14 ;
F_38 ( & V_57 -> V_105 . V_76 ) ;
V_57 -> V_105 . V_71 = 0 ;
for ( V_15 = 0 ; V_15 < V_58 ; V_15 ++ ) {
V_81 = F_34 ( sizeof( * V_81 ) , V_66 ) ;
if ( ! V_81 ) {
F_2 ( L_20 ) ;
V_14 = - V_61 ;
goto V_106;
}
V_14 = F_31 ( V_7 -> V_16 , V_7 -> V_38 ,
V_57 -> V_107 , V_81 ) ;
if ( V_14 ) {
F_2 ( L_21 ,
V_14 ) ;
F_27 ( V_81 ) ;
goto V_106;
}
F_39 ( & V_81 -> V_108 , & V_57 -> V_105 . V_76 ) ;
V_57 -> V_105 . V_71 ++ ;
}
return 0 ;
V_106:
V_32 ( V_57 ) ;
return V_14 ;
}
void V_32 ( struct V_57 * V_57 )
{
struct V_80 * V_81 , * V_109 ;
int V_15 = 0 ;
if ( F_40 ( & V_57 -> V_105 . V_76 ) )
return;
F_8 ( L_22 , V_57 ) ;
F_41 (desc, tmp, &ib_conn->fastreg.pool, list) {
F_42 ( & V_81 -> V_108 ) ;
F_37 ( V_81 -> V_82 ) ;
F_18 ( V_81 -> V_83 ) ;
if ( V_81 -> V_90 ) {
F_37 ( V_81 -> V_90 -> V_92 ) ;
F_18 ( V_81 -> V_90 -> V_94 ) ;
F_43 ( V_81 -> V_90 -> V_100 ) ;
F_27 ( V_81 -> V_90 ) ;
}
F_27 ( V_81 ) ;
++ V_15 ;
}
if ( V_15 < V_57 -> V_105 . V_71 )
F_29 ( L_23 ,
V_57 -> V_105 . V_71 - V_15 ) ;
}
static int F_44 ( struct V_57 * V_57 )
{
struct V_11 * V_7 ;
struct V_110 V_111 ;
int V_14 = - V_61 ;
int V_112 , V_113 = 0 ;
F_23 ( V_57 -> V_7 == NULL ) ;
V_7 = V_57 -> V_7 ;
memset ( & V_111 , 0 , sizeof V_111 ) ;
F_45 ( & V_114 . V_115 ) ;
for ( V_112 = 0 ; V_112 < V_7 -> V_35 ; V_112 ++ ) {
if ( V_7 -> V_42 [ V_112 ] . V_116 <
V_7 -> V_42 [ V_113 ] . V_116 )
V_113 = V_112 ;
}
V_57 -> V_41 = & V_7 -> V_42 [ V_113 ] ;
V_57 -> V_41 -> V_116 ++ ;
F_46 ( & V_114 . V_115 ) ;
F_8 ( L_24 , V_113 , V_57 ) ;
V_111 . V_55 = F_3 ;
V_111 . V_117 = ( void * ) V_57 ;
V_111 . V_118 = V_57 -> V_41 -> V_43 ;
V_111 . V_119 = V_57 -> V_41 -> V_43 ;
V_111 . V_120 . V_121 = V_122 ;
V_111 . V_120 . V_123 = 2 ;
V_111 . V_120 . V_124 = 1 ;
V_111 . V_125 = V_126 ;
V_111 . V_127 = V_128 ;
if ( V_57 -> V_107 ) {
V_111 . V_120 . V_129 = V_130 + 1 ;
V_111 . V_131 |= V_132 ;
} else {
V_111 . V_120 . V_129 = V_133 + 1 ;
}
V_14 = F_47 ( V_57 -> V_134 , V_7 -> V_38 , & V_111 ) ;
if ( V_14 )
goto V_135;
V_57 -> V_136 = V_57 -> V_134 -> V_136 ;
F_8 ( L_25 ,
V_57 , V_57 -> V_134 ,
V_57 -> V_134 -> V_136 ) ;
return V_14 ;
V_135:
F_2 ( L_26 , V_14 ) ;
return V_14 ;
}
static
struct V_11 * F_48 ( struct V_137 * V_134 )
{
struct V_11 * V_7 ;
F_45 ( & V_114 . V_138 ) ;
F_49 (device, &ig.device_list, ig_list)
if ( V_7 -> V_16 -> V_139 == V_134 -> V_7 -> V_139 )
goto V_140;
V_7 = F_34 ( sizeof *V_7 , V_66 ) ;
if ( V_7 == NULL )
goto V_141;
V_7 -> V_16 = V_134 -> V_7 ;
if ( F_5 ( V_7 ) ) {
F_27 ( V_7 ) ;
V_7 = NULL ;
goto V_141;
}
F_50 ( & V_7 -> V_142 , & V_114 . V_143 ) ;
V_140:
V_7 -> V_144 ++ ;
V_141:
F_46 ( & V_114 . V_138 ) ;
return V_7 ;
}
static void F_51 ( struct V_11 * V_7 )
{
F_45 ( & V_114 . V_138 ) ;
V_7 -> V_144 -- ;
F_8 ( L_27 , V_7 , V_7 -> V_144 ) ;
if ( ! V_7 -> V_144 ) {
F_22 ( V_7 ) ;
F_42 ( & V_7 -> V_142 ) ;
F_27 ( V_7 ) ;
}
F_46 ( & V_114 . V_138 ) ;
}
static int F_52 ( struct V_145 * V_145 ,
enum V_146 V_41 ,
enum V_146 V_147 )
{
int V_14 ;
V_14 = ( V_145 -> V_148 == V_41 ) ;
if ( V_14 )
V_145 -> V_148 = V_147 ;
return V_14 ;
}
void F_53 ( struct V_149 * V_150 )
{
struct V_145 * V_145 ;
V_145 = F_54 ( V_150 , struct V_145 , V_151 ) ;
F_55 ( & V_145 -> V_152 ) ;
F_55 ( & V_145 -> V_153 ) ;
F_45 ( & V_145 -> V_154 ) ;
V_145 -> V_148 = V_155 ;
F_46 ( & V_145 -> V_154 ) ;
F_56 ( V_145 ) ;
}
static void F_57 ( struct V_145 * V_145 ,
bool V_156 )
{
struct V_57 * V_57 = & V_145 -> V_57 ;
struct V_11 * V_7 = V_57 -> V_7 ;
F_8 ( L_28 ,
V_145 , V_57 -> V_134 , V_57 -> V_136 ) ;
F_58 ( V_145 ) ;
if ( V_57 -> V_136 != NULL ) {
V_57 -> V_41 -> V_116 -- ;
F_59 ( V_57 -> V_134 ) ;
V_57 -> V_136 = NULL ;
}
if ( V_156 && V_7 != NULL ) {
F_51 ( V_7 ) ;
V_57 -> V_7 = NULL ;
}
}
void F_56 ( struct V_145 * V_145 )
{
struct V_57 * V_57 = & V_145 -> V_57 ;
F_45 ( & V_114 . V_115 ) ;
F_42 ( & V_145 -> V_157 ) ;
F_46 ( & V_114 . V_115 ) ;
F_45 ( & V_145 -> V_154 ) ;
if ( V_145 -> V_148 != V_155 )
F_29 ( L_29 ,
V_145 , V_145 -> V_148 ) ;
F_57 ( V_145 , true ) ;
F_46 ( & V_145 -> V_154 ) ;
if ( V_57 -> V_134 != NULL ) {
F_60 ( V_57 -> V_134 ) ;
V_57 -> V_134 = NULL ;
}
F_27 ( V_145 ) ;
}
int F_61 ( struct V_145 * V_145 )
{
struct V_57 * V_57 = & V_145 -> V_57 ;
struct V_158 * V_159 ;
int V_106 = 0 ;
if ( ! F_52 ( V_145 , V_160 ,
V_161 ) )
return 0 ;
F_8 ( L_30 , V_145 , V_145 -> V_148 ) ;
if ( V_145 -> V_162 )
F_62 ( V_145 -> V_162 ) ;
if ( V_57 -> V_134 ) {
V_106 = F_63 ( V_57 -> V_134 ) ;
if ( V_106 )
F_2 ( L_31 ,
V_145 , V_106 ) ;
V_106 = F_64 ( V_57 -> V_136 , & V_57 -> V_163 , & V_159 ) ;
if ( V_106 )
F_2 ( L_32 , V_57 ) ;
F_55 ( & V_57 -> V_164 ) ;
}
return 1 ;
}
static void F_65 ( struct V_137 * V_134 )
{
struct V_145 * V_145 ;
V_145 = (struct V_145 * ) V_134 -> V_3 ;
V_145 -> V_148 = V_155 ;
}
static void F_66 ( struct V_137 * V_134 )
{
struct V_11 * V_7 ;
struct V_145 * V_145 ;
struct V_57 * V_57 ;
int V_14 ;
V_145 = (struct V_145 * ) V_134 -> V_3 ;
if ( V_145 -> V_148 != V_165 )
return;
V_57 = & V_145 -> V_57 ;
V_7 = F_48 ( V_134 ) ;
if ( ! V_7 ) {
F_2 ( L_33 ) ;
F_65 ( V_134 ) ;
return;
}
V_57 -> V_7 = V_7 ;
if ( V_166 ) {
if ( ! ( V_7 -> V_13 . V_29 &
V_167 ) ) {
F_29 ( L_34
L_35 ,
V_57 -> V_7 -> V_16 -> V_8 ) ;
V_57 -> V_107 = false ;
} else {
V_57 -> V_107 = true ;
}
}
V_14 = F_67 ( V_134 , 1000 ) ;
if ( V_14 ) {
F_2 ( L_36 , V_14 ) ;
F_65 ( V_134 ) ;
return;
}
}
static void F_68 ( struct V_137 * V_134 )
{
struct V_168 V_169 ;
int V_14 ;
struct V_170 V_171 ;
struct V_145 * V_145 = (struct V_145 * ) V_134 -> V_3 ;
struct V_57 * V_57 = & V_145 -> V_57 ;
struct V_11 * V_7 = V_57 -> V_7 ;
if ( V_145 -> V_148 != V_165 )
return;
V_14 = F_44 ( V_57 ) ;
if ( V_14 )
goto V_172;
memset ( & V_169 , 0 , sizeof V_169 ) ;
V_169 . V_173 = V_7 -> V_13 . V_174 ;
V_169 . V_175 = 1 ;
V_169 . V_176 = 7 ;
V_169 . V_177 = 6 ;
memset ( & V_171 , 0 , sizeof( V_171 ) ) ;
V_171 . V_98 = ( V_178 |
V_179 ) ;
V_169 . V_180 = ( void * ) & V_171 ;
V_169 . V_181 = sizeof( struct V_170 ) ;
V_14 = F_69 ( V_134 , & V_169 ) ;
if ( V_14 ) {
F_2 ( L_37 , V_14 ) ;
goto V_172;
}
return;
V_172:
F_65 ( V_134 ) ;
}
static void F_70 ( struct V_137 * V_134 )
{
struct V_145 * V_145 ;
struct V_182 V_183 ;
struct V_110 V_111 ;
V_145 = (struct V_145 * ) V_134 -> V_3 ;
if ( V_145 -> V_148 != V_165 )
return;
( void ) F_71 ( V_134 -> V_136 , & V_183 , ~ 0 , & V_111 ) ;
F_8 ( L_38 , V_183 . V_184 , V_134 -> V_136 -> V_185 ) ;
V_145 -> V_148 = V_160 ;
F_72 ( & V_145 -> V_186 ) ;
}
static void F_73 ( struct V_137 * V_134 )
{
struct V_145 * V_145 = (struct V_145 * ) V_134 -> V_3 ;
if ( F_61 ( V_145 ) ) {
if ( V_145 -> V_162 )
F_74 ( V_145 -> V_162 ,
V_187 ) ;
else
F_2 ( L_39 ) ;
}
}
static void F_75 ( struct V_137 * V_134 ,
bool V_156 )
{
struct V_145 * V_145 = (struct V_145 * ) V_134 -> V_3 ;
F_73 ( V_134 ) ;
F_57 ( V_145 , V_156 ) ;
F_72 ( & V_145 -> V_153 ) ;
}
static int F_76 ( struct V_137 * V_134 , struct V_188 * V_4 )
{
struct V_145 * V_145 ;
int V_14 = 0 ;
V_145 = (struct V_145 * ) V_134 -> V_3 ;
F_8 ( L_40 ,
V_4 -> V_4 , V_4 -> V_189 , V_134 -> V_3 , V_134 ) ;
F_45 ( & V_145 -> V_154 ) ;
switch ( V_4 -> V_4 ) {
case V_190 :
F_66 ( V_134 ) ;
break;
case V_191 :
F_68 ( V_134 ) ;
break;
case V_192 :
F_70 ( V_134 ) ;
break;
case V_193 :
case V_194 :
case V_195 :
case V_196 :
case V_197 :
F_65 ( V_134 ) ;
break;
case V_198 :
case V_199 :
F_73 ( V_134 ) ;
break;
case V_200 :
F_75 ( V_134 , true ) ;
V_145 -> V_57 . V_134 = NULL ;
V_14 = 1 ;
break;
case V_201 :
F_75 ( V_134 , false ) ;
break;
default:
F_2 ( L_41 , V_4 -> V_4 ) ;
break;
}
F_46 ( & V_145 -> V_154 ) ;
return V_14 ;
}
void F_77 ( struct V_145 * V_145 )
{
V_145 -> V_148 = V_202 ;
V_145 -> V_57 . V_203 = 0 ;
F_78 ( & V_145 -> V_57 . V_164 ) ;
F_78 ( & V_145 -> V_152 ) ;
F_78 ( & V_145 -> V_153 ) ;
F_78 ( & V_145 -> V_186 ) ;
F_38 ( & V_145 -> V_157 ) ;
F_79 ( & V_145 -> V_57 . V_204 ) ;
F_80 ( & V_145 -> V_154 ) ;
}
int F_81 ( struct V_145 * V_145 ,
struct V_205 * V_206 ,
struct V_205 * V_207 ,
int V_208 )
{
struct V_57 * V_57 = & V_145 -> V_57 ;
int V_106 = 0 ;
F_45 ( & V_145 -> V_154 ) ;
sprintf ( V_145 -> V_8 , L_42 , V_207 ) ;
F_8 ( L_43 , V_145 -> V_8 ) ;
V_57 -> V_7 = NULL ;
V_145 -> V_148 = V_165 ;
V_57 -> V_163 . V_209 = V_210 ;
V_57 -> V_163 . V_211 = V_212 ;
V_57 -> V_134 = F_82 ( F_76 ,
( void * ) V_145 ,
V_213 , V_128 ) ;
if ( F_11 ( V_57 -> V_134 ) ) {
V_106 = F_28 ( V_57 -> V_134 ) ;
F_2 ( L_44 , V_106 ) ;
goto V_214;
}
V_106 = F_83 ( V_57 -> V_134 , V_206 , V_207 , 1000 ) ;
if ( V_106 ) {
F_2 ( L_45 , V_106 ) ;
goto V_215;
}
if ( ! V_208 ) {
F_84 ( & V_145 -> V_186 ) ;
if ( V_145 -> V_148 != V_160 ) {
V_106 = - V_216 ;
goto V_217;
}
}
F_46 ( & V_145 -> V_154 ) ;
F_45 ( & V_114 . V_115 ) ;
F_50 ( & V_145 -> V_157 , & V_114 . V_218 ) ;
F_46 ( & V_114 . V_115 ) ;
return 0 ;
V_214:
V_57 -> V_134 = NULL ;
V_215:
V_145 -> V_148 = V_155 ;
V_217:
F_46 ( & V_145 -> V_154 ) ;
F_56 ( V_145 ) ;
return V_106 ;
}
int F_85 ( struct V_57 * V_57 ,
struct V_219 * V_63 ,
struct V_220 * V_221 )
{
struct V_222 * V_223 ;
V_64 V_224 ;
V_64 * V_104 ;
int V_189 ;
V_104 = V_63 -> V_67 ;
V_224 = V_104 [ 0 ] ;
V_223 = F_86 ( V_57 -> V_62 . V_76 ,
V_104 ,
V_63 -> V_225 ,
V_224 ) ;
if ( F_11 ( V_223 ) ) {
V_189 = ( int ) F_28 ( V_223 ) ;
F_2 ( L_46 , V_189 ) ;
return V_189 ;
}
V_221 -> V_226 = V_223 -> V_62 -> V_226 ;
V_221 -> V_227 = V_223 -> V_62 -> V_227 ;
V_221 -> V_228 = V_63 -> V_225 * V_229 ;
V_221 -> V_230 = V_224 ;
V_221 -> V_231 = 1 ;
V_221 -> V_232 = ( void * ) V_223 ;
V_221 -> V_230 += V_63 -> V_233 ;
V_221 -> V_228 = V_63 -> V_234 ;
F_36 ( L_47
L_48
L_49 ,
V_63 , V_63 -> V_225 ,
( unsigned long ) V_63 -> V_67 [ 0 ] ,
( unsigned long ) V_63 -> V_234 ,
( unsigned int ) V_221 -> V_226 , V_221 -> V_232 ,
( unsigned long ) V_221 -> V_230 , ( unsigned long ) V_221 -> V_228 ) ;
return 0 ;
}
void V_28 ( struct V_235 * V_236 ,
enum V_237 V_238 )
{
struct V_220 * V_239 = & V_236 -> V_240 [ V_238 ] . V_239 ;
int V_14 ;
if ( ! V_239 -> V_231 )
return;
F_36 ( L_50 , V_239 -> V_232 ) ;
V_14 = F_87 ( (struct V_222 * ) V_239 -> V_232 ) ;
if ( V_14 )
F_2 ( L_51 , V_14 ) ;
V_239 -> V_232 = NULL ;
}
void V_34 ( struct V_235 * V_236 ,
enum V_237 V_238 )
{
struct V_220 * V_239 = & V_236 -> V_240 [ V_238 ] . V_239 ;
struct V_145 * V_145 = V_236 -> V_145 ;
struct V_57 * V_57 = & V_145 -> V_57 ;
struct V_80 * V_81 = V_239 -> V_232 ;
if ( ! V_239 -> V_231 )
return;
V_239 -> V_232 = NULL ;
V_239 -> V_231 = 0 ;
F_88 ( & V_57 -> V_204 ) ;
F_39 ( & V_81 -> V_108 , & V_57 -> V_105 . V_76 ) ;
F_89 ( & V_57 -> V_204 ) ;
}
int F_90 ( struct V_145 * V_145 )
{
struct V_241 V_242 , * V_243 ;
struct V_57 * V_57 = & V_145 -> V_57 ;
struct V_244 V_245 ;
int V_246 ;
V_245 . V_247 = V_145 -> V_248 ;
V_245 . V_225 = V_249 ;
V_245 . V_226 = V_57 -> V_7 -> V_50 -> V_226 ;
V_242 . V_209 = ( unsigned long ) V_145 -> V_250 ;
V_242 . V_251 = & V_245 ;
V_242 . V_252 = 1 ;
V_242 . V_253 = NULL ;
V_57 -> V_203 ++ ;
V_246 = F_91 ( V_57 -> V_136 , & V_242 , & V_243 ) ;
if ( V_246 ) {
F_2 ( L_52 , V_246 ) ;
V_57 -> V_203 -- ;
}
return V_246 ;
}
int F_92 ( struct V_145 * V_145 , int V_254 )
{
struct V_241 * V_242 , * V_243 ;
int V_15 , V_246 ;
struct V_57 * V_57 = & V_145 -> V_57 ;
unsigned int V_255 = V_145 -> V_256 ;
struct V_257 * V_258 ;
for ( V_242 = V_57 -> V_242 , V_15 = 0 ; V_15 < V_254 ; V_15 ++ , V_242 ++ ) {
V_258 = & V_145 -> V_259 [ V_255 ] ;
V_242 -> V_209 = ( unsigned long ) V_258 ;
V_242 -> V_251 = & V_258 -> V_260 ;
V_242 -> V_252 = 1 ;
V_242 -> V_253 = V_242 + 1 ;
V_255 = ( V_255 + 1 ) & V_145 -> V_261 ;
}
V_242 -- ;
V_242 -> V_253 = NULL ;
V_57 -> V_203 += V_254 ;
V_246 = F_91 ( V_57 -> V_136 , V_57 -> V_242 , & V_243 ) ;
if ( V_246 ) {
F_2 ( L_52 , V_246 ) ;
V_57 -> V_203 -= V_254 ;
} else
V_145 -> V_256 = V_255 ;
return V_246 ;
}
int F_93 ( struct V_57 * V_57 , struct V_262 * V_263 ,
bool signal )
{
int V_246 ;
struct V_158 V_264 , * V_265 ;
F_94 ( V_57 -> V_7 -> V_16 ,
V_263 -> V_266 , V_267 ,
V_268 ) ;
V_264 . V_253 = NULL ;
V_264 . V_209 = ( unsigned long ) V_263 ;
V_264 . V_251 = V_263 -> V_269 ;
V_264 . V_252 = V_263 -> V_252 ;
V_264 . V_211 = V_212 ;
V_264 . V_270 = signal ? V_271 : 0 ;
V_246 = F_64 ( V_57 -> V_136 , & V_264 , & V_265 ) ;
if ( V_246 )
F_2 ( L_53 , V_246 ) ;
return V_246 ;
}
static inline bool
F_95 ( struct V_145 * V_145 , void * V_209 )
{
void * V_272 = V_145 -> V_259 ;
int V_228 = V_145 -> V_273 * sizeof( * V_145 -> V_259 ) ;
if ( V_209 >= V_272 && V_209 < V_272 + V_228 )
return false ;
return true ;
}
static void
F_96 ( struct V_57 * V_57 ,
struct V_274 * V_275 )
{
struct V_145 * V_145 = F_54 ( V_57 , struct V_145 ,
V_57 ) ;
if ( V_275 -> V_189 != V_276 )
if ( V_145 -> V_162 )
F_74 ( V_145 -> V_162 ,
V_187 ) ;
if ( F_95 ( V_145 , ( void * ) V_275 -> V_209 ) ) {
struct V_262 * V_81 = (struct V_262 * ) V_275 -> V_209 ;
if ( V_81 -> type == V_277 )
F_97 ( V_114 . V_278 , V_81 ) ;
} else {
V_57 -> V_203 -- ;
}
}
static void F_98 ( struct V_274 * V_275 )
{
struct V_57 * V_57 ;
struct V_262 * V_263 ;
struct V_257 * V_258 ;
V_57 = V_275 -> V_136 -> V_117 ;
if ( V_275 -> V_189 == V_279 ) {
if ( V_275 -> V_211 == V_280 ) {
V_258 = (struct V_257 * ) V_275 -> V_209 ;
F_99 ( V_258 , V_275 -> V_281 ,
V_57 ) ;
} else
if ( V_275 -> V_211 == V_282 ) {
V_263 = (struct V_262 * ) V_275 -> V_209 ;
F_100 ( V_263 , V_57 ) ;
} else {
F_2 ( L_54 , V_275 -> V_211 ) ;
}
} else {
if ( V_275 -> V_189 != V_276 )
F_2 ( L_55 ,
V_275 -> V_209 , V_275 -> V_189 , V_275 -> V_283 ) ;
else
F_36 ( L_56 , V_275 -> V_209 ) ;
if ( V_275 -> V_209 != V_284 &&
V_275 -> V_209 != V_210 )
F_96 ( V_57 , V_275 ) ;
if ( V_275 -> V_209 == V_210 )
F_72 ( & V_57 -> V_164 ) ;
}
}
static void V_49 ( unsigned long V_285 )
{
struct V_40 * V_41 = (struct V_40 * ) V_285 ;
struct V_286 * V_43 = V_41 -> V_43 ;
struct V_274 * const V_287 = V_41 -> V_287 ;
int V_15 , V_288 , V_289 = 0 ;
while ( ( V_288 = F_101 ( V_43 , F_102 ( V_41 -> V_287 ) , V_287 ) ) > 0 ) {
for ( V_15 = 0 ; V_15 < V_288 ; V_15 ++ )
F_98 ( & V_287 [ V_15 ] ) ;
V_289 += V_288 ;
if ( V_289 >= V_290 )
break;
}
F_13 ( V_43 , V_47 ) ;
F_36 ( L_57 , V_289 ) ;
}
static void V_44 ( struct V_286 * V_43 , void * V_291 )
{
struct V_40 * V_41 = V_291 ;
F_103 ( & V_41 -> V_48 ) ;
}
T_1 F_104 ( struct V_235 * V_236 ,
enum V_237 V_238 , T_2 * V_292 )
{
struct V_220 * V_239 = & V_236 -> V_240 [ V_238 ] . V_239 ;
struct V_80 * V_81 = V_239 -> V_232 ;
unsigned long V_293 = V_236 -> V_294 -> V_7 -> V_293 ;
struct V_295 V_296 ;
int V_14 ;
if ( V_81 && V_81 -> V_85 & V_103 ) {
V_81 -> V_85 &= ~ V_103 ;
V_14 = F_105 ( V_81 -> V_90 -> V_100 ,
V_297 , & V_296 ) ;
if ( V_14 ) {
F_106 ( L_58 , V_14 ) ;
goto V_106;
}
if ( V_296 . V_298 & V_297 ) {
T_2 V_299 = V_296 . V_300 . V_301 ;
F_107 ( V_299 , V_293 + 8 ) ;
* V_292 = F_108 ( V_236 -> V_294 ) + V_299 ;
F_106 ( L_59
L_60 ,
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
V_106:
return 0x1 ;
}
