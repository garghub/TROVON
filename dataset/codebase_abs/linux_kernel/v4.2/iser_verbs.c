static void F_1 ( struct V_1 * V_2 , void * V_3 )
{
F_2 ( L_1 ,
F_3 ( V_2 -> V_4 ) , V_2 -> V_4 ) ;
}
static void F_4 ( struct V_1 * V_2 , void * V_3 )
{
F_2 ( L_2 ,
F_3 ( V_2 -> V_4 ) , V_2 -> V_4 ) ;
}
static void F_5 ( struct V_5 * V_6 ,
struct V_1 * V_4 )
{
F_2 ( L_3 ,
F_3 ( V_4 -> V_4 ) , V_4 -> V_4 ,
V_4 -> V_7 -> V_8 , V_4 -> V_9 . V_10 ) ;
}
static int F_6 ( struct V_11 * V_7 )
{
struct V_12 * V_13 = & V_7 -> V_13 ;
int V_14 , V_15 , V_16 ;
V_14 = F_7 ( V_7 -> V_17 , V_13 ) ;
if ( V_14 ) {
F_8 ( L_4 , V_7 -> V_17 -> V_8 ) ;
return V_14 ;
}
if ( V_7 -> V_17 -> V_18 && V_7 -> V_17 -> V_19 &&
V_7 -> V_17 -> V_20 && V_7 -> V_17 -> V_21 ) {
F_9 ( L_5 ) ;
V_7 -> V_22 = V_23 ;
V_7 -> V_24 = V_25 ;
V_7 -> V_26 = V_27 ;
V_7 -> V_28 = V_29 ;
} else
if ( V_13 -> V_30 & V_31 ) {
F_9 ( L_6 ) ;
V_7 -> V_22 = V_32 ;
V_7 -> V_24 = V_33 ;
V_7 -> V_26 = V_34 ;
V_7 -> V_28 = V_35 ;
} else {
F_2 ( L_7 ) ;
return - 1 ;
}
V_7 -> V_36 = F_10 ( int , F_11 () ,
V_7 -> V_17 -> V_37 ) ;
V_7 -> V_38 = F_12 ( V_7 -> V_36 , sizeof( * V_7 -> V_38 ) ,
V_39 ) ;
if ( ! V_7 -> V_38 )
goto V_40;
V_16 = F_13 ( V_41 , V_13 -> V_16 ) ;
F_9 ( L_8 ,
V_7 -> V_36 , V_7 -> V_17 -> V_8 ,
V_7 -> V_17 -> V_37 , V_16 ) ;
V_7 -> V_42 = F_14 ( V_7 -> V_17 ) ;
if ( F_15 ( V_7 -> V_42 ) )
goto V_43;
for ( V_15 = 0 ; V_15 < V_7 -> V_36 ; V_15 ++ ) {
struct V_44 V_45 = {} ;
struct V_46 * V_47 = & V_7 -> V_38 [ V_15 ] ;
V_47 -> V_7 = V_7 ;
V_45 . V_48 = V_16 ;
V_45 . V_49 = V_15 ;
V_47 -> V_50 = F_16 ( V_7 -> V_17 ,
V_51 ,
F_1 ,
( void * ) V_47 ,
& V_45 ) ;
if ( F_15 ( V_47 -> V_50 ) ) {
V_47 -> V_50 = NULL ;
goto V_52;
}
if ( F_17 ( V_47 -> V_50 , V_53 ) )
goto V_52;
F_18 ( & V_47 -> V_54 , V_55 ,
( unsigned long ) V_47 ) ;
}
V_7 -> V_56 = F_19 ( V_7 -> V_42 , V_57 |
V_58 |
V_59 ) ;
if ( F_15 ( V_7 -> V_56 ) )
goto V_60;
F_20 ( & V_7 -> V_61 , V_7 -> V_17 ,
F_5 ) ;
if ( F_21 ( & V_7 -> V_61 ) )
goto V_62;
return 0 ;
V_62:
F_22 ( V_7 -> V_56 ) ;
V_60:
for ( V_15 = 0 ; V_15 < V_7 -> V_36 ; V_15 ++ )
F_23 ( & V_7 -> V_38 [ V_15 ] . V_54 ) ;
V_52:
for ( V_15 = 0 ; V_15 < V_7 -> V_36 ; V_15 ++ ) {
struct V_46 * V_47 = & V_7 -> V_38 [ V_15 ] ;
if ( V_47 -> V_50 )
F_24 ( V_47 -> V_50 ) ;
}
F_25 ( V_7 -> V_42 ) ;
V_43:
F_26 ( V_7 -> V_38 ) ;
V_40:
F_2 ( L_9 ) ;
return - 1 ;
}
static void F_27 ( struct V_11 * V_7 )
{
int V_15 ;
F_28 ( V_7 -> V_56 == NULL ) ;
for ( V_15 = 0 ; V_15 < V_7 -> V_36 ; V_15 ++ ) {
struct V_46 * V_47 = & V_7 -> V_38 [ V_15 ] ;
F_23 ( & V_47 -> V_54 ) ;
F_24 ( V_47 -> V_50 ) ;
V_47 -> V_50 = NULL ;
}
( void ) F_29 ( & V_7 -> V_61 ) ;
( void ) F_22 ( V_7 -> V_56 ) ;
( void ) F_25 ( V_7 -> V_42 ) ;
F_26 ( V_7 -> V_38 ) ;
V_7 -> V_38 = NULL ;
V_7 -> V_56 = NULL ;
V_7 -> V_42 = NULL ;
}
int V_23 ( struct V_63 * V_63 , unsigned V_64 )
{
struct V_11 * V_7 = V_63 -> V_7 ;
struct V_65 V_66 ;
int V_14 = - V_67 ;
V_63 -> V_68 . V_69 = F_30 ( sizeof( * V_63 -> V_68 . V_69 ) +
( sizeof( V_70 ) * ( V_71 + 1 ) ) ,
V_39 ) ;
if ( ! V_63 -> V_68 . V_69 )
return V_14 ;
V_63 -> V_68 . V_69 -> V_72 = ( V_70 * ) ( V_63 -> V_68 . V_69 + 1 ) ;
V_66 . V_73 = V_74 ;
V_66 . V_75 = V_71 + 1 ;
V_66 . V_76 = V_64 * 2 ;
V_66 . V_77 = V_64 ;
V_66 . V_78 = 0 ;
V_66 . V_79 = NULL ;
V_66 . V_80 = ( V_57 |
V_58 |
V_59 ) ;
V_63 -> V_68 . V_81 = F_31 ( V_7 -> V_42 , & V_66 ) ;
if ( ! F_15 ( V_63 -> V_68 . V_81 ) )
return 0 ;
F_26 ( V_63 -> V_68 . V_69 ) ;
V_63 -> V_68 . V_69 = NULL ;
V_14 = F_32 ( V_63 -> V_68 . V_81 ) ;
V_63 -> V_68 . V_81 = NULL ;
if ( V_14 != - V_82 ) {
F_2 ( L_10 , V_14 ) ;
return V_14 ;
} else {
F_33 ( L_11 ) ;
return 0 ;
}
}
void V_25 ( struct V_63 * V_63 )
{
F_9 ( L_12 ,
V_63 , V_63 -> V_68 . V_81 ) ;
if ( V_63 -> V_68 . V_81 != NULL )
F_34 ( V_63 -> V_68 . V_81 ) ;
V_63 -> V_68 . V_81 = NULL ;
F_26 ( V_63 -> V_68 . V_69 ) ;
V_63 -> V_68 . V_69 = NULL ;
}
static int
F_35 ( struct V_17 * V_17 , struct V_83 * V_42 ,
struct V_84 * V_85 )
{
struct V_86 * V_87 = NULL ;
struct V_88 V_89 = { . V_90 = 2 ,
. V_91 = V_92 } ;
int V_14 = 0 ;
V_85 -> V_87 = F_36 ( sizeof( * V_85 -> V_87 ) , V_39 ) ;
if ( ! V_85 -> V_87 )
return - V_67 ;
V_87 = V_85 -> V_87 ;
V_87 -> V_93 = F_37 ( V_17 ,
V_71 ) ;
if ( F_15 ( V_87 -> V_93 ) ) {
V_14 = F_32 ( V_87 -> V_93 ) ;
goto V_94;
}
V_87 -> V_95 = F_38 ( V_42 ,
V_71 + 1 ) ;
if ( F_15 ( V_87 -> V_95 ) ) {
V_14 = F_32 ( V_87 -> V_95 ) ;
goto V_96;
}
V_85 -> V_97 |= V_98 ;
V_87 -> V_99 = F_39 ( V_42 , & V_89 ) ;
if ( F_15 ( V_87 -> V_99 ) ) {
V_14 = F_32 ( V_87 -> V_99 ) ;
goto V_100;
}
V_85 -> V_97 |= V_101 ;
V_85 -> V_97 &= ~ V_102 ;
return 0 ;
V_100:
F_22 ( V_85 -> V_87 -> V_95 ) ;
V_96:
F_40 ( V_85 -> V_87 -> V_93 ) ;
V_94:
F_26 ( V_85 -> V_87 ) ;
return V_14 ;
}
static void
F_41 ( struct V_86 * V_87 )
{
F_40 ( V_87 -> V_93 ) ;
F_22 ( V_87 -> V_95 ) ;
F_42 ( V_87 -> V_99 ) ;
F_26 ( V_87 ) ;
}
static int
F_43 ( struct V_17 * V_17 , struct V_83 * V_42 ,
bool V_103 , struct V_84 * V_85 )
{
int V_14 ;
V_85 -> V_104 = F_37 ( V_17 ,
V_71 + 1 ) ;
if ( F_15 ( V_85 -> V_104 ) ) {
V_14 = F_32 ( V_85 -> V_104 ) ;
F_2 ( L_13 ,
V_14 ) ;
return F_32 ( V_85 -> V_104 ) ;
}
V_85 -> V_105 = F_38 ( V_42 , V_71 + 1 ) ;
if ( F_15 ( V_85 -> V_105 ) ) {
V_14 = F_32 ( V_85 -> V_105 ) ;
F_2 ( L_14 , V_14 ) ;
goto V_106;
}
V_85 -> V_97 |= V_107 ;
if ( V_103 ) {
V_14 = F_35 ( V_17 , V_42 , V_85 ) ;
if ( V_14 )
goto V_108;
}
return 0 ;
V_108:
F_22 ( V_85 -> V_105 ) ;
V_106:
F_40 ( V_85 -> V_104 ) ;
return V_14 ;
}
int V_32 ( struct V_63 * V_63 , unsigned V_64 )
{
struct V_11 * V_7 = V_63 -> V_7 ;
struct V_84 * V_85 ;
int V_15 , V_14 ;
F_44 ( & V_63 -> V_109 . V_81 ) ;
V_63 -> V_109 . V_76 = 0 ;
for ( V_15 = 0 ; V_15 < V_64 ; V_15 ++ ) {
V_85 = F_36 ( sizeof( * V_85 ) , V_39 ) ;
if ( ! V_85 ) {
F_2 ( L_15 ) ;
V_14 = - V_67 ;
goto V_110;
}
V_14 = F_43 ( V_7 -> V_17 , V_7 -> V_42 ,
V_63 -> V_111 , V_85 ) ;
if ( V_14 ) {
F_2 ( L_16 ,
V_14 ) ;
F_26 ( V_85 ) ;
goto V_110;
}
F_45 ( & V_85 -> V_112 , & V_63 -> V_109 . V_81 ) ;
V_63 -> V_109 . V_76 ++ ;
}
return 0 ;
V_110:
V_33 ( V_63 ) ;
return V_14 ;
}
void V_33 ( struct V_63 * V_63 )
{
struct V_84 * V_85 , * V_113 ;
int V_15 = 0 ;
if ( F_46 ( & V_63 -> V_109 . V_81 ) )
return;
F_9 ( L_17 , V_63 ) ;
F_47 (desc, tmp, &ib_conn->fastreg.pool, list) {
F_48 ( & V_85 -> V_112 ) ;
F_40 ( V_85 -> V_104 ) ;
F_22 ( V_85 -> V_105 ) ;
if ( V_85 -> V_87 )
F_41 ( V_85 -> V_87 ) ;
F_26 ( V_85 ) ;
++ V_15 ;
}
if ( V_15 < V_63 -> V_109 . V_76 )
F_33 ( L_18 ,
V_63 -> V_109 . V_76 - V_15 ) ;
}
static int F_49 ( struct V_63 * V_63 )
{
struct V_114 * V_114 = F_50 ( V_63 , struct V_114 ,
V_63 ) ;
struct V_11 * V_7 ;
struct V_12 * V_13 ;
struct V_115 V_116 ;
int V_14 = - V_67 ;
int V_117 , V_118 = 0 ;
F_28 ( V_63 -> V_7 == NULL ) ;
V_7 = V_63 -> V_7 ;
V_13 = & V_7 -> V_13 ;
memset ( & V_116 , 0 , sizeof V_116 ) ;
F_51 ( & V_119 . V_120 ) ;
for ( V_117 = 0 ; V_117 < V_7 -> V_36 ; V_117 ++ ) {
if ( V_7 -> V_38 [ V_117 ] . V_121 <
V_7 -> V_38 [ V_118 ] . V_121 )
V_118 = V_117 ;
}
V_63 -> V_47 = & V_7 -> V_38 [ V_118 ] ;
V_63 -> V_47 -> V_121 ++ ;
F_52 ( & V_119 . V_120 ) ;
F_9 ( L_19 , V_118 , V_63 ) ;
V_116 . V_61 = F_4 ;
V_116 . V_122 = ( void * ) V_63 ;
V_116 . V_123 = V_63 -> V_47 -> V_50 ;
V_116 . V_124 = V_63 -> V_47 -> V_50 ;
V_116 . V_125 . V_126 = V_127 ;
V_116 . V_125 . V_128 = 2 ;
V_116 . V_125 . V_129 = 1 ;
V_116 . V_130 = V_131 ;
V_116 . V_132 = V_133 ;
if ( V_63 -> V_111 ) {
V_116 . V_125 . V_134 = V_135 + 1 ;
V_116 . V_136 |= V_137 ;
V_114 -> V_138 =
F_53 ( V_135 ) ;
} else {
if ( V_13 -> V_139 > V_140 ) {
V_116 . V_125 . V_134 = V_140 + 1 ;
V_114 -> V_138 =
F_53 ( V_140 ) ;
} else {
V_116 . V_125 . V_134 = V_13 -> V_139 ;
V_114 -> V_138 =
F_53 ( V_13 -> V_139 ) ;
F_54 ( L_20 ,
V_7 -> V_17 -> V_8 , V_13 -> V_139 ) ;
}
}
V_14 = F_55 ( V_63 -> V_141 , V_7 -> V_42 , & V_116 ) ;
if ( V_14 )
goto V_142;
V_63 -> V_143 = V_63 -> V_141 -> V_143 ;
F_9 ( L_21 ,
V_63 , V_63 -> V_141 ,
V_63 -> V_141 -> V_143 ) ;
return V_14 ;
V_142:
F_51 ( & V_119 . V_120 ) ;
V_63 -> V_47 -> V_121 -- ;
F_52 ( & V_119 . V_120 ) ;
F_2 ( L_22 , V_14 ) ;
return V_14 ;
}
static
struct V_11 * F_56 ( struct V_144 * V_141 )
{
struct V_11 * V_7 ;
F_51 ( & V_119 . V_145 ) ;
F_57 (device, &ig.device_list, ig_list)
if ( V_7 -> V_17 -> V_146 == V_141 -> V_7 -> V_146 )
goto V_147;
V_7 = F_36 ( sizeof *V_7 , V_39 ) ;
if ( V_7 == NULL )
goto V_148;
V_7 -> V_17 = V_141 -> V_7 ;
if ( F_6 ( V_7 ) ) {
F_26 ( V_7 ) ;
V_7 = NULL ;
goto V_148;
}
F_58 ( & V_7 -> V_149 , & V_119 . V_150 ) ;
V_147:
V_7 -> V_151 ++ ;
V_148:
F_52 ( & V_119 . V_145 ) ;
return V_7 ;
}
static void F_59 ( struct V_11 * V_7 )
{
F_51 ( & V_119 . V_145 ) ;
V_7 -> V_151 -- ;
F_9 ( L_23 , V_7 , V_7 -> V_151 ) ;
if ( ! V_7 -> V_151 ) {
F_27 ( V_7 ) ;
F_48 ( & V_7 -> V_149 ) ;
F_26 ( V_7 ) ;
}
F_52 ( & V_119 . V_145 ) ;
}
static int F_60 ( struct V_114 * V_114 ,
enum V_152 V_47 ,
enum V_152 V_153 )
{
int V_14 ;
V_14 = ( V_114 -> V_154 == V_47 ) ;
if ( V_14 )
V_114 -> V_154 = V_153 ;
return V_14 ;
}
void F_61 ( struct V_155 * V_156 )
{
struct V_114 * V_114 ;
V_114 = F_50 ( V_156 , struct V_114 , V_157 ) ;
F_62 ( & V_114 -> V_158 ) ;
F_62 ( & V_114 -> V_159 ) ;
F_51 ( & V_114 -> V_160 ) ;
V_114 -> V_154 = V_161 ;
F_52 ( & V_114 -> V_160 ) ;
F_63 ( V_114 ) ;
}
static void F_64 ( struct V_114 * V_114 ,
bool V_162 )
{
struct V_63 * V_63 = & V_114 -> V_63 ;
struct V_11 * V_7 = V_63 -> V_7 ;
F_9 ( L_24 ,
V_114 , V_63 -> V_141 , V_63 -> V_143 ) ;
if ( V_63 -> V_143 != NULL ) {
V_63 -> V_47 -> V_121 -- ;
F_65 ( V_63 -> V_141 ) ;
V_63 -> V_143 = NULL ;
}
if ( V_162 ) {
if ( V_114 -> V_163 )
F_66 ( V_114 ) ;
if ( V_7 != NULL ) {
F_59 ( V_7 ) ;
V_63 -> V_7 = NULL ;
}
}
}
void F_63 ( struct V_114 * V_114 )
{
struct V_63 * V_63 = & V_114 -> V_63 ;
F_51 ( & V_119 . V_120 ) ;
F_48 ( & V_114 -> V_164 ) ;
F_52 ( & V_119 . V_120 ) ;
F_51 ( & V_114 -> V_160 ) ;
if ( V_114 -> V_154 != V_161 ) {
F_33 ( L_25 ,
V_114 , V_114 -> V_154 ) ;
F_67 ( V_114 -> V_165 ) ;
V_114 -> V_154 = V_161 ;
}
F_64 ( V_114 , true ) ;
F_52 ( & V_114 -> V_160 ) ;
if ( V_63 -> V_141 != NULL ) {
F_68 ( V_63 -> V_141 ) ;
V_63 -> V_141 = NULL ;
}
F_26 ( V_114 ) ;
}
int F_69 ( struct V_114 * V_114 )
{
struct V_63 * V_63 = & V_114 -> V_63 ;
struct V_166 * V_167 ;
int V_110 = 0 ;
if ( ! F_60 ( V_114 , V_168 ,
V_169 ) )
return 0 ;
F_9 ( L_26 , V_114 , V_114 -> V_154 ) ;
if ( V_114 -> V_170 )
F_70 ( V_114 -> V_170 ) ;
if ( V_63 -> V_141 ) {
V_110 = F_71 ( V_63 -> V_141 ) ;
if ( V_110 )
F_2 ( L_27 ,
V_114 , V_110 ) ;
V_110 = F_72 ( V_63 -> V_143 , & V_63 -> V_171 , & V_167 ) ;
if ( V_110 ) {
F_2 ( L_28 , V_63 ) ;
return 1 ;
}
F_62 ( & V_63 -> V_172 ) ;
}
return 1 ;
}
static void F_73 ( struct V_144 * V_141 )
{
struct V_114 * V_114 ;
V_114 = (struct V_114 * ) V_141 -> V_3 ;
V_114 -> V_154 = V_169 ;
}
static void F_74 ( struct V_144 * V_141 )
{
struct V_11 * V_7 ;
struct V_114 * V_114 ;
struct V_63 * V_63 ;
int V_14 ;
V_114 = (struct V_114 * ) V_141 -> V_3 ;
if ( V_114 -> V_154 != V_173 )
return;
V_63 = & V_114 -> V_63 ;
V_7 = F_56 ( V_141 ) ;
if ( ! V_7 ) {
F_2 ( L_29 ) ;
F_73 ( V_141 ) ;
return;
}
V_63 -> V_7 = V_7 ;
if ( V_174 ) {
if ( ! ( V_7 -> V_13 . V_30 &
V_175 ) ) {
F_33 ( L_30
L_31 ,
V_63 -> V_7 -> V_17 -> V_8 ) ;
V_63 -> V_111 = false ;
} else {
V_63 -> V_111 = true ;
}
}
V_14 = F_75 ( V_141 , 1000 ) ;
if ( V_14 ) {
F_2 ( L_32 , V_14 ) ;
F_73 ( V_141 ) ;
return;
}
}
static void F_76 ( struct V_144 * V_141 )
{
struct V_176 V_177 ;
int V_14 ;
struct V_178 V_179 ;
struct V_114 * V_114 = (struct V_114 * ) V_141 -> V_3 ;
struct V_63 * V_63 = & V_114 -> V_63 ;
struct V_11 * V_7 = V_63 -> V_7 ;
if ( V_114 -> V_154 != V_173 )
return;
V_14 = F_49 ( V_63 ) ;
if ( V_14 )
goto V_180;
memset ( & V_177 , 0 , sizeof V_177 ) ;
V_177 . V_181 = V_7 -> V_13 . V_182 ;
V_177 . V_183 = 1 ;
V_177 . V_184 = 7 ;
V_177 . V_185 = 6 ;
memset ( & V_179 , 0 , sizeof( V_179 ) ) ;
V_179 . V_91 = ( V_186 |
V_187 ) ;
V_177 . V_188 = ( void * ) & V_179 ;
V_177 . V_189 = sizeof( struct V_178 ) ;
V_14 = F_77 ( V_141 , & V_177 ) ;
if ( V_14 ) {
F_2 ( L_33 , V_14 ) ;
goto V_180;
}
return;
V_180:
F_73 ( V_141 ) ;
}
static void F_78 ( struct V_144 * V_141 )
{
struct V_114 * V_114 ;
struct V_190 V_191 ;
struct V_115 V_116 ;
V_114 = (struct V_114 * ) V_141 -> V_3 ;
if ( V_114 -> V_154 != V_173 )
return;
( void ) F_79 ( V_141 -> V_143 , & V_191 , ~ 0 , & V_116 ) ;
F_9 ( L_34 , V_191 . V_192 , V_141 -> V_143 -> V_193 ) ;
V_114 -> V_154 = V_168 ;
F_80 ( & V_114 -> V_194 ) ;
}
static void F_81 ( struct V_144 * V_141 )
{
struct V_114 * V_114 = (struct V_114 * ) V_141 -> V_3 ;
if ( F_69 ( V_114 ) ) {
if ( V_114 -> V_170 )
F_82 ( V_114 -> V_170 ,
V_195 ) ;
else
F_2 ( L_35 ) ;
}
}
static void F_83 ( struct V_144 * V_141 ,
bool V_162 )
{
struct V_114 * V_114 = (struct V_114 * ) V_141 -> V_3 ;
F_81 ( V_141 ) ;
F_64 ( V_114 , V_162 ) ;
F_80 ( & V_114 -> V_159 ) ;
}
static int F_84 ( struct V_144 * V_141 , struct V_196 * V_4 )
{
struct V_114 * V_114 ;
int V_14 = 0 ;
V_114 = (struct V_114 * ) V_141 -> V_3 ;
F_9 ( L_36 ,
F_85 ( V_4 -> V_4 ) , V_4 -> V_4 ,
V_4 -> V_197 , V_141 -> V_3 , V_141 ) ;
F_51 ( & V_114 -> V_160 ) ;
switch ( V_4 -> V_4 ) {
case V_198 :
F_74 ( V_141 ) ;
break;
case V_199 :
F_76 ( V_141 ) ;
break;
case V_200 :
F_78 ( V_141 ) ;
break;
case V_201 :
case V_202 :
case V_203 :
case V_204 :
case V_205 :
F_73 ( V_141 ) ;
break;
case V_206 :
case V_207 :
case V_208 :
F_83 ( V_141 , false ) ;
break;
case V_209 :
F_83 ( V_141 , true ) ;
if ( V_114 -> V_154 != V_161 ) {
V_114 -> V_63 . V_141 = NULL ;
V_14 = 1 ;
}
break;
default:
F_2 ( L_37 ,
F_85 ( V_4 -> V_4 ) , V_4 -> V_4 ) ;
break;
}
F_52 ( & V_114 -> V_160 ) ;
return V_14 ;
}
void F_86 ( struct V_114 * V_114 )
{
V_114 -> V_154 = V_210 ;
V_114 -> V_63 . V_211 = 0 ;
F_87 ( & V_114 -> V_63 . V_172 ) ;
F_87 ( & V_114 -> V_158 ) ;
F_87 ( & V_114 -> V_159 ) ;
F_87 ( & V_114 -> V_194 ) ;
F_44 ( & V_114 -> V_164 ) ;
F_88 ( & V_114 -> V_63 . V_212 ) ;
F_89 ( & V_114 -> V_160 ) ;
}
int F_90 ( struct V_114 * V_114 ,
struct V_213 * V_214 ,
struct V_213 * V_215 ,
int V_216 )
{
struct V_63 * V_63 = & V_114 -> V_63 ;
int V_110 = 0 ;
F_51 ( & V_114 -> V_160 ) ;
sprintf ( V_114 -> V_8 , L_38 , V_215 ) ;
F_9 ( L_39 , V_114 -> V_8 ) ;
V_63 -> V_7 = NULL ;
V_114 -> V_154 = V_173 ;
V_63 -> V_171 . V_217 = V_218 ;
V_63 -> V_171 . V_219 = V_220 ;
V_63 -> V_141 = F_91 ( F_84 ,
( void * ) V_114 ,
V_221 , V_133 ) ;
if ( F_15 ( V_63 -> V_141 ) ) {
V_110 = F_32 ( V_63 -> V_141 ) ;
F_2 ( L_40 , V_110 ) ;
goto V_222;
}
V_110 = F_92 ( V_63 -> V_141 , V_214 , V_215 , 1000 ) ;
if ( V_110 ) {
F_2 ( L_41 , V_110 ) ;
goto V_223;
}
if ( ! V_216 ) {
F_93 ( & V_114 -> V_194 ) ;
if ( V_114 -> V_154 != V_168 ) {
V_110 = - V_224 ;
goto V_225;
}
}
F_52 ( & V_114 -> V_160 ) ;
F_51 ( & V_119 . V_120 ) ;
F_58 ( & V_114 -> V_164 , & V_119 . V_226 ) ;
F_52 ( & V_119 . V_120 ) ;
return 0 ;
V_222:
V_63 -> V_141 = NULL ;
V_223:
V_114 -> V_154 = V_161 ;
V_225:
F_52 ( & V_114 -> V_160 ) ;
F_63 ( V_114 ) ;
return V_110 ;
}
int F_94 ( struct V_114 * V_114 )
{
struct V_227 V_228 , * V_229 ;
struct V_63 * V_63 = & V_114 -> V_63 ;
struct V_230 V_231 ;
int V_232 ;
V_231 . V_233 = V_114 -> V_234 ;
V_231 . V_235 = V_236 ;
V_231 . V_237 = V_63 -> V_7 -> V_56 -> V_237 ;
V_228 . V_217 = ( V_238 ) V_114 -> V_239 ;
V_228 . V_240 = & V_231 ;
V_228 . V_241 = 1 ;
V_228 . V_242 = NULL ;
V_63 -> V_211 ++ ;
V_232 = F_95 ( V_63 -> V_143 , & V_228 , & V_229 ) ;
if ( V_232 ) {
F_2 ( L_42 , V_232 ) ;
V_63 -> V_211 -- ;
}
return V_232 ;
}
int F_96 ( struct V_114 * V_114 , int V_243 )
{
struct V_227 * V_228 , * V_229 ;
int V_15 , V_232 ;
struct V_63 * V_63 = & V_114 -> V_63 ;
unsigned int V_244 = V_114 -> V_245 ;
struct V_246 * V_247 ;
for ( V_228 = V_63 -> V_228 , V_15 = 0 ; V_15 < V_243 ; V_15 ++ , V_228 ++ ) {
V_247 = & V_114 -> V_163 [ V_244 ] ;
V_228 -> V_217 = ( V_238 ) V_247 ;
V_228 -> V_240 = & V_247 -> V_248 ;
V_228 -> V_241 = 1 ;
V_228 -> V_242 = V_228 + 1 ;
V_244 = ( V_244 + 1 ) & V_114 -> V_249 ;
}
V_228 -- ;
V_228 -> V_242 = NULL ;
V_63 -> V_211 += V_243 ;
V_232 = F_95 ( V_63 -> V_143 , V_63 -> V_228 , & V_229 ) ;
if ( V_232 ) {
F_2 ( L_42 , V_232 ) ;
V_63 -> V_211 -= V_243 ;
} else
V_114 -> V_245 = V_244 ;
return V_232 ;
}
int F_97 ( struct V_63 * V_63 , struct V_250 * V_251 ,
bool signal )
{
int V_232 ;
struct V_166 V_252 , * V_253 ;
F_98 ( V_63 -> V_7 -> V_17 ,
V_251 -> V_254 , V_255 ,
V_256 ) ;
V_252 . V_242 = NULL ;
V_252 . V_217 = ( V_238 ) V_251 ;
V_252 . V_240 = V_251 -> V_257 ;
V_252 . V_241 = V_251 -> V_241 ;
V_252 . V_219 = V_220 ;
V_252 . V_258 = signal ? V_259 : 0 ;
V_232 = F_72 ( V_63 -> V_143 , & V_252 , & V_253 ) ;
if ( V_232 )
F_2 ( L_43 , V_232 ) ;
return V_232 ;
}
static inline bool
F_99 ( struct V_114 * V_114 , void * V_217 )
{
void * V_260 = V_114 -> V_163 ;
int V_261 = V_114 -> V_262 * sizeof( * V_114 -> V_163 ) ;
if ( V_217 >= V_260 && V_217 < V_260 + V_261 )
return false ;
return true ;
}
static void
F_100 ( struct V_63 * V_63 ,
struct V_263 * V_264 )
{
void * V_217 = ( void * ) ( V_238 ) V_264 -> V_217 ;
struct V_114 * V_114 = F_50 ( V_63 , struct V_114 ,
V_63 ) ;
if ( V_264 -> V_197 != V_265 )
if ( V_114 -> V_170 )
F_82 ( V_114 -> V_170 ,
V_195 ) ;
if ( V_264 -> V_217 == V_266 )
return;
if ( F_99 ( V_114 , V_217 ) ) {
struct V_250 * V_85 = V_217 ;
if ( V_85 -> type == V_267 )
F_101 ( V_119 . V_268 , V_85 ) ;
} else {
V_63 -> V_211 -- ;
}
}
static void F_102 ( struct V_263 * V_264 )
{
struct V_63 * V_63 ;
struct V_250 * V_251 ;
struct V_246 * V_247 ;
V_63 = V_264 -> V_143 -> V_122 ;
if ( F_103 ( V_264 -> V_197 == V_269 ) ) {
if ( V_264 -> V_219 == V_270 ) {
V_247 = (struct V_246 * ) ( V_238 ) V_264 -> V_217 ;
F_104 ( V_247 , V_264 -> V_271 ,
V_63 ) ;
} else
if ( V_264 -> V_219 == V_272 ) {
V_251 = (struct V_250 * ) ( V_238 ) V_264 -> V_217 ;
F_105 ( V_251 , V_63 ) ;
} else {
F_2 ( L_44 , V_264 -> V_219 ) ;
}
} else {
if ( V_264 -> V_197 != V_265 )
F_2 ( L_45 ,
F_106 ( V_264 -> V_197 ) , V_264 -> V_197 ,
V_264 -> V_217 , V_264 -> V_273 ) ;
else
F_54 ( L_46 ,
F_106 ( V_264 -> V_197 ) , V_264 -> V_197 ,
V_264 -> V_217 ) ;
if ( V_264 -> V_217 == V_218 )
F_80 ( & V_63 -> V_172 ) ;
else
F_100 ( V_63 , V_264 ) ;
}
}
static void V_55 ( unsigned long V_274 )
{
struct V_46 * V_47 = (struct V_46 * ) V_274 ;
struct V_275 * V_50 = V_47 -> V_50 ;
struct V_263 * const V_276 = V_47 -> V_276 ;
int V_15 , V_277 , V_278 = 0 ;
while ( ( V_277 = F_107 ( V_50 , F_108 ( V_47 -> V_276 ) , V_276 ) ) > 0 ) {
for ( V_15 = 0 ; V_15 < V_277 ; V_15 ++ )
F_102 ( & V_276 [ V_15 ] ) ;
V_278 += V_277 ;
if ( V_278 >= V_279 )
break;
}
F_17 ( V_50 , V_53 ) ;
F_54 ( L_47 , V_278 ) ;
}
static void V_51 ( struct V_275 * V_50 , void * V_280 )
{
struct V_46 * V_47 = V_280 ;
F_109 ( & V_47 -> V_54 ) ;
}
T_1 F_110 ( struct V_281 * V_282 ,
enum V_283 V_284 , T_2 * V_285 )
{
struct V_286 * V_287 = & V_282 -> V_288 [ V_284 ] ;
struct V_84 * V_85 = V_287 -> V_289 ;
unsigned long V_290 = V_282 -> V_291 -> V_7 -> V_290 ;
struct V_292 V_293 ;
int V_14 ;
if ( V_85 && V_85 -> V_97 & V_102 ) {
V_85 -> V_97 &= ~ V_102 ;
V_14 = F_111 ( V_85 -> V_87 -> V_99 ,
V_294 , & V_293 ) ;
if ( V_14 ) {
F_112 ( L_48 , V_14 ) ;
goto V_110;
}
if ( V_293 . V_295 & V_294 ) {
T_2 V_296 = V_293 . V_297 . V_298 ;
F_113 ( V_296 , V_290 + 8 ) ;
* V_285 = F_114 ( V_282 -> V_291 ) + V_296 ;
F_112 ( L_49
L_50 ,
V_293 . V_297 . V_299 ,
( unsigned long long ) * V_285 ,
V_293 . V_297 . V_300 ,
V_293 . V_297 . V_301 ) ;
switch ( V_293 . V_297 . V_299 ) {
case V_302 :
return 0x1 ;
case V_303 :
return 0x3 ;
case V_304 :
return 0x2 ;
}
}
}
return 0 ;
V_110:
return 0x1 ;
}
