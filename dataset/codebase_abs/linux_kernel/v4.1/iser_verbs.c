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
int V_14 , V_15 , V_16 ;
V_14 = F_6 ( V_7 -> V_17 , V_13 ) ;
if ( V_14 ) {
F_7 ( L_4 , V_7 -> V_17 -> V_8 ) ;
return V_14 ;
}
if ( V_7 -> V_17 -> V_18 && V_7 -> V_17 -> V_19 &&
V_7 -> V_17 -> V_20 && V_7 -> V_17 -> V_21 ) {
F_8 ( L_5 ) ;
V_7 -> V_22 = V_23 ;
V_7 -> V_24 = V_25 ;
V_7 -> V_26 = V_27 ;
V_7 -> V_28 = V_29 ;
} else
if ( V_13 -> V_30 & V_31 ) {
F_8 ( L_6 ) ;
V_7 -> V_22 = V_32 ;
V_7 -> V_24 = V_33 ;
V_7 -> V_26 = V_34 ;
V_7 -> V_28 = V_35 ;
} else {
F_2 ( L_7 ) ;
return - 1 ;
}
V_7 -> V_36 = F_9 ( int , F_10 () ,
V_7 -> V_17 -> V_37 ) ;
V_7 -> V_38 = F_11 ( V_7 -> V_36 , sizeof( * V_7 -> V_38 ) ,
V_39 ) ;
if ( ! V_7 -> V_38 )
goto V_40;
V_16 = F_12 ( V_41 , V_13 -> V_16 ) ;
F_8 ( L_8 ,
V_7 -> V_36 , V_7 -> V_17 -> V_8 ,
V_7 -> V_17 -> V_37 , V_16 ) ;
V_7 -> V_42 = F_13 ( V_7 -> V_17 ) ;
if ( F_14 ( V_7 -> V_42 ) )
goto V_43;
for ( V_15 = 0 ; V_15 < V_7 -> V_36 ; V_15 ++ ) {
struct V_44 * V_45 = & V_7 -> V_38 [ V_15 ] ;
V_45 -> V_7 = V_7 ;
V_45 -> V_46 = F_15 ( V_7 -> V_17 ,
V_47 ,
F_1 ,
( void * ) V_45 ,
V_16 , V_15 ) ;
if ( F_14 ( V_45 -> V_46 ) ) {
V_45 -> V_46 = NULL ;
goto V_48;
}
if ( F_16 ( V_45 -> V_46 , V_49 ) )
goto V_48;
F_17 ( & V_45 -> V_50 , V_51 ,
( unsigned long ) V_45 ) ;
}
V_7 -> V_52 = F_18 ( V_7 -> V_42 , V_53 |
V_54 |
V_55 ) ;
if ( F_14 ( V_7 -> V_52 ) )
goto V_56;
F_19 ( & V_7 -> V_57 , V_7 -> V_17 ,
F_4 ) ;
if ( F_20 ( & V_7 -> V_57 ) )
goto V_58;
return 0 ;
V_58:
F_21 ( V_7 -> V_52 ) ;
V_56:
for ( V_15 = 0 ; V_15 < V_7 -> V_36 ; V_15 ++ )
F_22 ( & V_7 -> V_38 [ V_15 ] . V_50 ) ;
V_48:
for ( V_15 = 0 ; V_15 < V_7 -> V_36 ; V_15 ++ ) {
struct V_44 * V_45 = & V_7 -> V_38 [ V_15 ] ;
if ( V_45 -> V_46 )
F_23 ( V_45 -> V_46 ) ;
}
F_24 ( V_7 -> V_42 ) ;
V_43:
F_25 ( V_7 -> V_38 ) ;
V_40:
F_2 ( L_9 ) ;
return - 1 ;
}
static void F_26 ( struct V_11 * V_7 )
{
int V_15 ;
F_27 ( V_7 -> V_52 == NULL ) ;
for ( V_15 = 0 ; V_15 < V_7 -> V_36 ; V_15 ++ ) {
struct V_44 * V_45 = & V_7 -> V_38 [ V_15 ] ;
F_22 ( & V_45 -> V_50 ) ;
F_23 ( V_45 -> V_46 ) ;
V_45 -> V_46 = NULL ;
}
( void ) F_28 ( & V_7 -> V_57 ) ;
( void ) F_21 ( V_7 -> V_52 ) ;
( void ) F_24 ( V_7 -> V_42 ) ;
F_25 ( V_7 -> V_38 ) ;
V_7 -> V_38 = NULL ;
V_7 -> V_52 = NULL ;
V_7 -> V_42 = NULL ;
}
int V_23 ( struct V_59 * V_59 , unsigned V_60 )
{
struct V_11 * V_7 = V_59 -> V_7 ;
struct V_61 V_62 ;
int V_14 = - V_63 ;
V_59 -> V_64 . V_65 = F_29 ( sizeof( * V_59 -> V_64 . V_65 ) +
( sizeof( V_66 ) * ( V_67 + 1 ) ) ,
V_39 ) ;
if ( ! V_59 -> V_64 . V_65 )
return V_14 ;
V_59 -> V_64 . V_65 -> V_68 = ( V_66 * ) ( V_59 -> V_64 . V_65 + 1 ) ;
V_62 . V_69 = V_70 ;
V_62 . V_71 = V_67 + 1 ;
V_62 . V_72 = V_60 * 2 ;
V_62 . V_73 = V_60 ;
V_62 . V_74 = 0 ;
V_62 . V_75 = NULL ;
V_62 . V_76 = ( V_53 |
V_54 |
V_55 ) ;
V_59 -> V_64 . V_77 = F_30 ( V_7 -> V_42 , & V_62 ) ;
if ( ! F_14 ( V_59 -> V_64 . V_77 ) )
return 0 ;
F_25 ( V_59 -> V_64 . V_65 ) ;
V_59 -> V_64 . V_65 = NULL ;
V_14 = F_31 ( V_59 -> V_64 . V_77 ) ;
V_59 -> V_64 . V_77 = NULL ;
if ( V_14 != - V_78 ) {
F_2 ( L_10 , V_14 ) ;
return V_14 ;
} else {
F_32 ( L_11 ) ;
return 0 ;
}
}
void V_25 ( struct V_59 * V_59 )
{
F_8 ( L_12 ,
V_59 , V_59 -> V_64 . V_77 ) ;
if ( V_59 -> V_64 . V_77 != NULL )
F_33 ( V_59 -> V_64 . V_77 ) ;
V_59 -> V_64 . V_77 = NULL ;
F_25 ( V_59 -> V_64 . V_65 ) ;
V_59 -> V_64 . V_65 = NULL ;
}
static int
F_34 ( struct V_17 * V_17 , struct V_79 * V_42 ,
struct V_80 * V_81 )
{
struct V_82 * V_83 = NULL ;
struct V_84 V_85 = { . V_86 = 2 ,
. V_87 = V_88 } ;
int V_14 = 0 ;
V_81 -> V_83 = F_35 ( sizeof( * V_81 -> V_83 ) , V_39 ) ;
if ( ! V_81 -> V_83 )
return - V_63 ;
V_83 = V_81 -> V_83 ;
V_83 -> V_89 = F_36 ( V_17 ,
V_67 ) ;
if ( F_14 ( V_83 -> V_89 ) ) {
V_14 = F_31 ( V_83 -> V_89 ) ;
goto V_90;
}
V_83 -> V_91 = F_37 ( V_42 ,
V_67 + 1 ) ;
if ( F_14 ( V_83 -> V_91 ) ) {
V_14 = F_31 ( V_83 -> V_91 ) ;
goto V_92;
}
V_81 -> V_93 |= V_94 ;
V_83 -> V_95 = F_38 ( V_42 , & V_85 ) ;
if ( F_14 ( V_83 -> V_95 ) ) {
V_14 = F_31 ( V_83 -> V_95 ) ;
goto V_96;
}
V_81 -> V_93 |= V_97 ;
V_81 -> V_93 &= ~ V_98 ;
return 0 ;
V_96:
F_21 ( V_81 -> V_83 -> V_91 ) ;
V_92:
F_39 ( V_81 -> V_83 -> V_89 ) ;
V_90:
F_25 ( V_81 -> V_83 ) ;
return V_14 ;
}
static void
F_40 ( struct V_82 * V_83 )
{
F_39 ( V_83 -> V_89 ) ;
F_21 ( V_83 -> V_91 ) ;
F_41 ( V_83 -> V_95 ) ;
F_25 ( V_83 ) ;
}
static int
F_42 ( struct V_17 * V_17 , struct V_79 * V_42 ,
bool V_99 , struct V_80 * V_81 )
{
int V_14 ;
V_81 -> V_100 = F_36 ( V_17 ,
V_67 + 1 ) ;
if ( F_14 ( V_81 -> V_100 ) ) {
V_14 = F_31 ( V_81 -> V_100 ) ;
F_2 ( L_13 ,
V_14 ) ;
return F_31 ( V_81 -> V_100 ) ;
}
V_81 -> V_101 = F_37 ( V_42 , V_67 + 1 ) ;
if ( F_14 ( V_81 -> V_101 ) ) {
V_14 = F_31 ( V_81 -> V_101 ) ;
F_2 ( L_14 , V_14 ) ;
goto V_102;
}
V_81 -> V_93 |= V_103 ;
if ( V_99 ) {
V_14 = F_34 ( V_17 , V_42 , V_81 ) ;
if ( V_14 )
goto V_104;
}
return 0 ;
V_104:
F_21 ( V_81 -> V_101 ) ;
V_102:
F_39 ( V_81 -> V_100 ) ;
return V_14 ;
}
int V_32 ( struct V_59 * V_59 , unsigned V_60 )
{
struct V_11 * V_7 = V_59 -> V_7 ;
struct V_80 * V_81 ;
int V_15 , V_14 ;
F_43 ( & V_59 -> V_105 . V_77 ) ;
V_59 -> V_105 . V_72 = 0 ;
for ( V_15 = 0 ; V_15 < V_60 ; V_15 ++ ) {
V_81 = F_35 ( sizeof( * V_81 ) , V_39 ) ;
if ( ! V_81 ) {
F_2 ( L_15 ) ;
V_14 = - V_63 ;
goto V_106;
}
V_14 = F_42 ( V_7 -> V_17 , V_7 -> V_42 ,
V_59 -> V_107 , V_81 ) ;
if ( V_14 ) {
F_2 ( L_16 ,
V_14 ) ;
F_25 ( V_81 ) ;
goto V_106;
}
F_44 ( & V_81 -> V_108 , & V_59 -> V_105 . V_77 ) ;
V_59 -> V_105 . V_72 ++ ;
}
return 0 ;
V_106:
V_33 ( V_59 ) ;
return V_14 ;
}
void V_33 ( struct V_59 * V_59 )
{
struct V_80 * V_81 , * V_109 ;
int V_15 = 0 ;
if ( F_45 ( & V_59 -> V_105 . V_77 ) )
return;
F_8 ( L_17 , V_59 ) ;
F_46 (desc, tmp, &ib_conn->fastreg.pool, list) {
F_47 ( & V_81 -> V_108 ) ;
F_39 ( V_81 -> V_100 ) ;
F_21 ( V_81 -> V_101 ) ;
if ( V_81 -> V_83 )
F_40 ( V_81 -> V_83 ) ;
F_25 ( V_81 ) ;
++ V_15 ;
}
if ( V_15 < V_59 -> V_105 . V_72 )
F_32 ( L_18 ,
V_59 -> V_105 . V_72 - V_15 ) ;
}
static int F_48 ( struct V_59 * V_59 )
{
struct V_110 * V_110 = F_49 ( V_59 , struct V_110 ,
V_59 ) ;
struct V_11 * V_7 ;
struct V_12 * V_13 ;
struct V_111 V_112 ;
int V_14 = - V_63 ;
int V_113 , V_114 = 0 ;
F_27 ( V_59 -> V_7 == NULL ) ;
V_7 = V_59 -> V_7 ;
V_13 = & V_7 -> V_13 ;
memset ( & V_112 , 0 , sizeof V_112 ) ;
F_50 ( & V_115 . V_116 ) ;
for ( V_113 = 0 ; V_113 < V_7 -> V_36 ; V_113 ++ ) {
if ( V_7 -> V_38 [ V_113 ] . V_117 <
V_7 -> V_38 [ V_114 ] . V_117 )
V_114 = V_113 ;
}
V_59 -> V_45 = & V_7 -> V_38 [ V_114 ] ;
V_59 -> V_45 -> V_117 ++ ;
F_51 ( & V_115 . V_116 ) ;
F_8 ( L_19 , V_114 , V_59 ) ;
V_112 . V_57 = F_3 ;
V_112 . V_118 = ( void * ) V_59 ;
V_112 . V_119 = V_59 -> V_45 -> V_46 ;
V_112 . V_120 = V_59 -> V_45 -> V_46 ;
V_112 . V_121 . V_122 = V_123 ;
V_112 . V_121 . V_124 = 2 ;
V_112 . V_121 . V_125 = 1 ;
V_112 . V_126 = V_127 ;
V_112 . V_128 = V_129 ;
if ( V_59 -> V_107 ) {
V_112 . V_121 . V_130 = V_131 + 1 ;
V_112 . V_132 |= V_133 ;
V_110 -> V_134 =
F_52 ( V_131 ) ;
} else {
if ( V_13 -> V_135 > V_136 ) {
V_112 . V_121 . V_130 = V_136 + 1 ;
V_110 -> V_134 =
F_52 ( V_136 ) ;
} else {
V_112 . V_121 . V_130 = V_13 -> V_135 ;
V_110 -> V_134 =
F_52 ( V_13 -> V_135 ) ;
F_53 ( L_20 ,
V_7 -> V_17 -> V_8 , V_13 -> V_135 ) ;
}
}
V_14 = F_54 ( V_59 -> V_137 , V_7 -> V_42 , & V_112 ) ;
if ( V_14 )
goto V_138;
V_59 -> V_139 = V_59 -> V_137 -> V_139 ;
F_8 ( L_21 ,
V_59 , V_59 -> V_137 ,
V_59 -> V_137 -> V_139 ) ;
return V_14 ;
V_138:
F_50 ( & V_115 . V_116 ) ;
V_59 -> V_45 -> V_117 -- ;
F_51 ( & V_115 . V_116 ) ;
F_2 ( L_22 , V_14 ) ;
return V_14 ;
}
static
struct V_11 * F_55 ( struct V_140 * V_137 )
{
struct V_11 * V_7 ;
F_50 ( & V_115 . V_141 ) ;
F_56 (device, &ig.device_list, ig_list)
if ( V_7 -> V_17 -> V_142 == V_137 -> V_7 -> V_142 )
goto V_143;
V_7 = F_35 ( sizeof *V_7 , V_39 ) ;
if ( V_7 == NULL )
goto V_144;
V_7 -> V_17 = V_137 -> V_7 ;
if ( F_5 ( V_7 ) ) {
F_25 ( V_7 ) ;
V_7 = NULL ;
goto V_144;
}
F_57 ( & V_7 -> V_145 , & V_115 . V_146 ) ;
V_143:
V_7 -> V_147 ++ ;
V_144:
F_51 ( & V_115 . V_141 ) ;
return V_7 ;
}
static void F_58 ( struct V_11 * V_7 )
{
F_50 ( & V_115 . V_141 ) ;
V_7 -> V_147 -- ;
F_8 ( L_23 , V_7 , V_7 -> V_147 ) ;
if ( ! V_7 -> V_147 ) {
F_26 ( V_7 ) ;
F_47 ( & V_7 -> V_145 ) ;
F_25 ( V_7 ) ;
}
F_51 ( & V_115 . V_141 ) ;
}
static int F_59 ( struct V_110 * V_110 ,
enum V_148 V_45 ,
enum V_148 V_149 )
{
int V_14 ;
V_14 = ( V_110 -> V_150 == V_45 ) ;
if ( V_14 )
V_110 -> V_150 = V_149 ;
return V_14 ;
}
void F_60 ( struct V_151 * V_152 )
{
struct V_110 * V_110 ;
V_110 = F_49 ( V_152 , struct V_110 , V_153 ) ;
F_61 ( & V_110 -> V_154 ) ;
F_61 ( & V_110 -> V_155 ) ;
F_50 ( & V_110 -> V_156 ) ;
V_110 -> V_150 = V_157 ;
F_51 ( & V_110 -> V_156 ) ;
F_62 ( V_110 ) ;
}
static void F_63 ( struct V_110 * V_110 ,
bool V_158 )
{
struct V_59 * V_59 = & V_110 -> V_59 ;
struct V_11 * V_7 = V_59 -> V_7 ;
F_8 ( L_24 ,
V_110 , V_59 -> V_137 , V_59 -> V_139 ) ;
if ( V_59 -> V_139 != NULL ) {
V_59 -> V_45 -> V_117 -- ;
F_64 ( V_59 -> V_137 ) ;
V_59 -> V_139 = NULL ;
}
if ( V_158 ) {
if ( V_110 -> V_159 )
F_65 ( V_110 ) ;
if ( V_7 != NULL ) {
F_58 ( V_7 ) ;
V_59 -> V_7 = NULL ;
}
}
}
void F_62 ( struct V_110 * V_110 )
{
struct V_59 * V_59 = & V_110 -> V_59 ;
F_50 ( & V_115 . V_116 ) ;
F_47 ( & V_110 -> V_160 ) ;
F_51 ( & V_115 . V_116 ) ;
F_50 ( & V_110 -> V_156 ) ;
if ( V_110 -> V_150 != V_157 ) {
F_32 ( L_25 ,
V_110 , V_110 -> V_150 ) ;
F_66 ( V_110 -> V_161 ) ;
V_110 -> V_150 = V_157 ;
}
F_63 ( V_110 , true ) ;
F_51 ( & V_110 -> V_156 ) ;
if ( V_59 -> V_137 != NULL ) {
F_67 ( V_59 -> V_137 ) ;
V_59 -> V_137 = NULL ;
}
F_25 ( V_110 ) ;
}
int F_68 ( struct V_110 * V_110 )
{
struct V_59 * V_59 = & V_110 -> V_59 ;
struct V_162 * V_163 ;
int V_106 = 0 ;
if ( ! F_59 ( V_110 , V_164 ,
V_165 ) )
return 0 ;
F_8 ( L_26 , V_110 , V_110 -> V_150 ) ;
if ( V_110 -> V_166 )
F_69 ( V_110 -> V_166 ) ;
if ( V_59 -> V_137 ) {
V_106 = F_70 ( V_59 -> V_137 ) ;
if ( V_106 )
F_2 ( L_27 ,
V_110 , V_106 ) ;
V_106 = F_71 ( V_59 -> V_139 , & V_59 -> V_167 , & V_163 ) ;
if ( V_106 ) {
F_2 ( L_28 , V_59 ) ;
return 1 ;
}
F_61 ( & V_59 -> V_168 ) ;
}
return 1 ;
}
static void F_72 ( struct V_140 * V_137 )
{
struct V_110 * V_110 ;
V_110 = (struct V_110 * ) V_137 -> V_3 ;
V_110 -> V_150 = V_165 ;
}
static void F_73 ( struct V_140 * V_137 )
{
struct V_11 * V_7 ;
struct V_110 * V_110 ;
struct V_59 * V_59 ;
int V_14 ;
V_110 = (struct V_110 * ) V_137 -> V_3 ;
if ( V_110 -> V_150 != V_169 )
return;
V_59 = & V_110 -> V_59 ;
V_7 = F_55 ( V_137 ) ;
if ( ! V_7 ) {
F_2 ( L_29 ) ;
F_72 ( V_137 ) ;
return;
}
V_59 -> V_7 = V_7 ;
if ( V_170 ) {
if ( ! ( V_7 -> V_13 . V_30 &
V_171 ) ) {
F_32 ( L_30
L_31 ,
V_59 -> V_7 -> V_17 -> V_8 ) ;
V_59 -> V_107 = false ;
} else {
V_59 -> V_107 = true ;
}
}
V_14 = F_74 ( V_137 , 1000 ) ;
if ( V_14 ) {
F_2 ( L_32 , V_14 ) ;
F_72 ( V_137 ) ;
return;
}
}
static void F_75 ( struct V_140 * V_137 )
{
struct V_172 V_173 ;
int V_14 ;
struct V_174 V_175 ;
struct V_110 * V_110 = (struct V_110 * ) V_137 -> V_3 ;
struct V_59 * V_59 = & V_110 -> V_59 ;
struct V_11 * V_7 = V_59 -> V_7 ;
if ( V_110 -> V_150 != V_169 )
return;
V_14 = F_48 ( V_59 ) ;
if ( V_14 )
goto V_176;
memset ( & V_173 , 0 , sizeof V_173 ) ;
V_173 . V_177 = V_7 -> V_13 . V_178 ;
V_173 . V_179 = 1 ;
V_173 . V_180 = 7 ;
V_173 . V_181 = 6 ;
memset ( & V_175 , 0 , sizeof( V_175 ) ) ;
V_175 . V_87 = ( V_182 |
V_183 ) ;
V_173 . V_184 = ( void * ) & V_175 ;
V_173 . V_185 = sizeof( struct V_174 ) ;
V_14 = F_76 ( V_137 , & V_173 ) ;
if ( V_14 ) {
F_2 ( L_33 , V_14 ) ;
goto V_176;
}
return;
V_176:
F_72 ( V_137 ) ;
}
static void F_77 ( struct V_140 * V_137 )
{
struct V_110 * V_110 ;
struct V_186 V_187 ;
struct V_111 V_112 ;
V_110 = (struct V_110 * ) V_137 -> V_3 ;
if ( V_110 -> V_150 != V_169 )
return;
( void ) F_78 ( V_137 -> V_139 , & V_187 , ~ 0 , & V_112 ) ;
F_8 ( L_34 , V_187 . V_188 , V_137 -> V_139 -> V_189 ) ;
V_110 -> V_150 = V_164 ;
F_79 ( & V_110 -> V_190 ) ;
}
static void F_80 ( struct V_140 * V_137 )
{
struct V_110 * V_110 = (struct V_110 * ) V_137 -> V_3 ;
if ( F_68 ( V_110 ) ) {
if ( V_110 -> V_166 )
F_81 ( V_110 -> V_166 ,
V_191 ) ;
else
F_2 ( L_35 ) ;
}
}
static void F_82 ( struct V_140 * V_137 ,
bool V_158 )
{
struct V_110 * V_110 = (struct V_110 * ) V_137 -> V_3 ;
F_80 ( V_137 ) ;
F_63 ( V_110 , V_158 ) ;
F_79 ( & V_110 -> V_155 ) ;
}
static int F_83 ( struct V_140 * V_137 , struct V_192 * V_4 )
{
struct V_110 * V_110 ;
int V_14 = 0 ;
V_110 = (struct V_110 * ) V_137 -> V_3 ;
F_8 ( L_36 ,
V_4 -> V_4 , V_4 -> V_193 , V_137 -> V_3 , V_137 ) ;
F_50 ( & V_110 -> V_156 ) ;
switch ( V_4 -> V_4 ) {
case V_194 :
F_73 ( V_137 ) ;
break;
case V_195 :
F_75 ( V_137 ) ;
break;
case V_196 :
F_77 ( V_137 ) ;
break;
case V_197 :
case V_198 :
case V_199 :
case V_200 :
case V_201 :
F_72 ( V_137 ) ;
break;
case V_202 :
case V_203 :
case V_204 :
F_82 ( V_137 , false ) ;
break;
case V_205 :
F_82 ( V_137 , true ) ;
if ( V_110 -> V_150 != V_157 ) {
V_110 -> V_59 . V_137 = NULL ;
V_14 = 1 ;
}
break;
default:
F_2 ( L_37 , V_4 -> V_4 ) ;
break;
}
F_51 ( & V_110 -> V_156 ) ;
return V_14 ;
}
void F_84 ( struct V_110 * V_110 )
{
V_110 -> V_150 = V_206 ;
V_110 -> V_59 . V_207 = 0 ;
F_85 ( & V_110 -> V_59 . V_168 ) ;
F_85 ( & V_110 -> V_154 ) ;
F_85 ( & V_110 -> V_155 ) ;
F_85 ( & V_110 -> V_190 ) ;
F_43 ( & V_110 -> V_160 ) ;
F_86 ( & V_110 -> V_59 . V_208 ) ;
F_87 ( & V_110 -> V_156 ) ;
}
int F_88 ( struct V_110 * V_110 ,
struct V_209 * V_210 ,
struct V_209 * V_211 ,
int V_212 )
{
struct V_59 * V_59 = & V_110 -> V_59 ;
int V_106 = 0 ;
F_50 ( & V_110 -> V_156 ) ;
sprintf ( V_110 -> V_8 , L_38 , V_211 ) ;
F_8 ( L_39 , V_110 -> V_8 ) ;
V_59 -> V_7 = NULL ;
V_110 -> V_150 = V_169 ;
V_59 -> V_167 . V_213 = V_214 ;
V_59 -> V_167 . V_215 = V_216 ;
V_59 -> V_137 = F_89 ( F_83 ,
( void * ) V_110 ,
V_217 , V_129 ) ;
if ( F_14 ( V_59 -> V_137 ) ) {
V_106 = F_31 ( V_59 -> V_137 ) ;
F_2 ( L_40 , V_106 ) ;
goto V_218;
}
V_106 = F_90 ( V_59 -> V_137 , V_210 , V_211 , 1000 ) ;
if ( V_106 ) {
F_2 ( L_41 , V_106 ) ;
goto V_219;
}
if ( ! V_212 ) {
F_91 ( & V_110 -> V_190 ) ;
if ( V_110 -> V_150 != V_164 ) {
V_106 = - V_220 ;
goto V_221;
}
}
F_51 ( & V_110 -> V_156 ) ;
F_50 ( & V_115 . V_116 ) ;
F_57 ( & V_110 -> V_160 , & V_115 . V_222 ) ;
F_51 ( & V_115 . V_116 ) ;
return 0 ;
V_218:
V_59 -> V_137 = NULL ;
V_219:
V_110 -> V_150 = V_157 ;
V_221:
F_51 ( & V_110 -> V_156 ) ;
F_62 ( V_110 ) ;
return V_106 ;
}
int F_92 ( struct V_110 * V_110 )
{
struct V_223 V_224 , * V_225 ;
struct V_59 * V_59 = & V_110 -> V_59 ;
struct V_226 V_227 ;
int V_228 ;
V_227 . V_229 = V_110 -> V_230 ;
V_227 . V_231 = V_232 ;
V_227 . V_233 = V_59 -> V_7 -> V_52 -> V_233 ;
V_224 . V_213 = ( V_234 ) V_110 -> V_235 ;
V_224 . V_236 = & V_227 ;
V_224 . V_237 = 1 ;
V_224 . V_238 = NULL ;
V_59 -> V_207 ++ ;
V_228 = F_93 ( V_59 -> V_139 , & V_224 , & V_225 ) ;
if ( V_228 ) {
F_2 ( L_42 , V_228 ) ;
V_59 -> V_207 -- ;
}
return V_228 ;
}
int F_94 ( struct V_110 * V_110 , int V_239 )
{
struct V_223 * V_224 , * V_225 ;
int V_15 , V_228 ;
struct V_59 * V_59 = & V_110 -> V_59 ;
unsigned int V_240 = V_110 -> V_241 ;
struct V_242 * V_243 ;
for ( V_224 = V_59 -> V_224 , V_15 = 0 ; V_15 < V_239 ; V_15 ++ , V_224 ++ ) {
V_243 = & V_110 -> V_159 [ V_240 ] ;
V_224 -> V_213 = ( V_234 ) V_243 ;
V_224 -> V_236 = & V_243 -> V_244 ;
V_224 -> V_237 = 1 ;
V_224 -> V_238 = V_224 + 1 ;
V_240 = ( V_240 + 1 ) & V_110 -> V_245 ;
}
V_224 -- ;
V_224 -> V_238 = NULL ;
V_59 -> V_207 += V_239 ;
V_228 = F_93 ( V_59 -> V_139 , V_59 -> V_224 , & V_225 ) ;
if ( V_228 ) {
F_2 ( L_42 , V_228 ) ;
V_59 -> V_207 -= V_239 ;
} else
V_110 -> V_241 = V_240 ;
return V_228 ;
}
int F_95 ( struct V_59 * V_59 , struct V_246 * V_247 ,
bool signal )
{
int V_228 ;
struct V_162 V_248 , * V_249 ;
F_96 ( V_59 -> V_7 -> V_17 ,
V_247 -> V_250 , V_251 ,
V_252 ) ;
V_248 . V_238 = NULL ;
V_248 . V_213 = ( V_234 ) V_247 ;
V_248 . V_236 = V_247 -> V_253 ;
V_248 . V_237 = V_247 -> V_237 ;
V_248 . V_215 = V_216 ;
V_248 . V_254 = signal ? V_255 : 0 ;
V_228 = F_71 ( V_59 -> V_139 , & V_248 , & V_249 ) ;
if ( V_228 )
F_2 ( L_43 , V_228 ) ;
return V_228 ;
}
static inline bool
F_97 ( struct V_110 * V_110 , void * V_213 )
{
void * V_256 = V_110 -> V_159 ;
int V_257 = V_110 -> V_258 * sizeof( * V_110 -> V_159 ) ;
if ( V_213 >= V_256 && V_213 < V_256 + V_257 )
return false ;
return true ;
}
static void
F_98 ( struct V_59 * V_59 ,
struct V_259 * V_260 )
{
void * V_213 = ( void * ) ( V_234 ) V_260 -> V_213 ;
struct V_110 * V_110 = F_49 ( V_59 , struct V_110 ,
V_59 ) ;
if ( V_260 -> V_193 != V_261 )
if ( V_110 -> V_166 )
F_81 ( V_110 -> V_166 ,
V_191 ) ;
if ( V_260 -> V_213 == V_262 )
return;
if ( F_97 ( V_110 , V_213 ) ) {
struct V_246 * V_81 = V_213 ;
if ( V_81 -> type == V_263 )
F_99 ( V_115 . V_264 , V_81 ) ;
} else {
V_59 -> V_207 -- ;
}
}
static void F_100 ( struct V_259 * V_260 )
{
struct V_59 * V_59 ;
struct V_246 * V_247 ;
struct V_242 * V_243 ;
V_59 = V_260 -> V_139 -> V_118 ;
if ( F_101 ( V_260 -> V_193 == V_265 ) ) {
if ( V_260 -> V_215 == V_266 ) {
V_243 = (struct V_242 * ) ( V_234 ) V_260 -> V_213 ;
F_102 ( V_243 , V_260 -> V_267 ,
V_59 ) ;
} else
if ( V_260 -> V_215 == V_268 ) {
V_247 = (struct V_246 * ) ( V_234 ) V_260 -> V_213 ;
F_103 ( V_247 , V_59 ) ;
} else {
F_2 ( L_44 , V_260 -> V_215 ) ;
}
} else {
if ( V_260 -> V_193 != V_261 )
F_2 ( L_45 ,
V_260 -> V_213 , V_260 -> V_193 , V_260 -> V_269 ) ;
else
F_53 ( L_46 , V_260 -> V_213 ) ;
if ( V_260 -> V_213 == V_214 )
F_79 ( & V_59 -> V_168 ) ;
else
F_98 ( V_59 , V_260 ) ;
}
}
static void V_51 ( unsigned long V_270 )
{
struct V_44 * V_45 = (struct V_44 * ) V_270 ;
struct V_271 * V_46 = V_45 -> V_46 ;
struct V_259 * const V_272 = V_45 -> V_272 ;
int V_15 , V_273 , V_274 = 0 ;
while ( ( V_273 = F_104 ( V_46 , F_105 ( V_45 -> V_272 ) , V_272 ) ) > 0 ) {
for ( V_15 = 0 ; V_15 < V_273 ; V_15 ++ )
F_100 ( & V_272 [ V_15 ] ) ;
V_274 += V_273 ;
if ( V_274 >= V_275 )
break;
}
F_16 ( V_46 , V_49 ) ;
F_53 ( L_47 , V_274 ) ;
}
static void V_47 ( struct V_271 * V_46 , void * V_276 )
{
struct V_44 * V_45 = V_276 ;
F_106 ( & V_45 -> V_50 ) ;
}
T_1 F_107 ( struct V_277 * V_278 ,
enum V_279 V_280 , T_2 * V_281 )
{
struct V_282 * V_283 = & V_278 -> V_284 [ V_280 ] ;
struct V_80 * V_81 = V_283 -> V_285 ;
unsigned long V_286 = V_278 -> V_287 -> V_7 -> V_286 ;
struct V_288 V_289 ;
int V_14 ;
if ( V_81 && V_81 -> V_93 & V_98 ) {
V_81 -> V_93 &= ~ V_98 ;
V_14 = F_108 ( V_81 -> V_83 -> V_95 ,
V_290 , & V_289 ) ;
if ( V_14 ) {
F_109 ( L_48 , V_14 ) ;
goto V_106;
}
if ( V_289 . V_291 & V_290 ) {
T_2 V_292 = V_289 . V_293 . V_294 ;
F_110 ( V_292 , V_286 + 8 ) ;
* V_281 = F_111 ( V_278 -> V_287 ) + V_292 ;
F_109 ( L_49
L_50 ,
V_289 . V_293 . V_295 ,
( unsigned long long ) * V_281 ,
V_289 . V_293 . V_296 ,
V_289 . V_293 . V_297 ) ;
switch ( V_289 . V_293 . V_295 ) {
case V_298 :
return 0x1 ;
case V_299 :
return 0x3 ;
case V_300 :
return 0x2 ;
}
}
}
return 0 ;
V_106:
return 0x1 ;
}
