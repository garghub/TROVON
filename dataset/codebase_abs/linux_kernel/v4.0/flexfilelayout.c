static struct V_1 *
F_1 ( struct V_2 * V_2 , T_1 V_3 )
{
struct V_4 * V_5 ;
V_5 = F_2 ( sizeof( * V_5 ) , V_3 ) ;
if ( V_5 ) {
F_3 ( & V_5 -> V_6 ) ;
return & V_5 -> V_7 ;
} else
return NULL ;
}
static void
F_4 ( struct V_1 * V_8 )
{
struct V_9 * V_10 , * V_11 ;
F_5 (err, n, &FF_LAYOUT_FROM_HDR(lo)->error_list,
list) {
F_6 ( & V_10 -> V_12 ) ;
F_7 ( V_10 ) ;
}
F_7 ( F_8 ( V_8 ) ) ;
}
static int F_9 ( struct V_13 * V_14 , T_2 * V_15 )
{
T_3 * V_16 ;
V_16 = F_10 ( V_14 , V_17 ) ;
if ( F_11 ( V_16 == NULL ) )
return - V_18 ;
memcpy ( V_15 , V_16 , V_17 ) ;
F_12 ( L_1 , V_19 ,
V_16 [ 0 ] , V_16 [ 1 ] , V_16 [ 2 ] , V_16 [ 3 ] ) ;
return 0 ;
}
static int F_13 ( struct V_13 * V_14 , struct V_20 * V_21 )
{
T_3 * V_16 ;
V_16 = F_10 ( V_14 , V_22 ) ;
if ( F_11 ( ! V_16 ) )
return - V_18 ;
memcpy ( V_21 , V_16 , V_22 ) ;
F_14 ( V_21 ) ;
return 0 ;
}
static int F_15 ( struct V_13 * V_14 , struct V_23 * V_24 )
{
T_3 * V_16 ;
V_16 = F_10 ( V_14 , 4 ) ;
if ( F_11 ( ! V_16 ) )
return - V_18 ;
V_24 -> V_25 = F_16 ( V_16 ++ ) ;
if ( V_24 -> V_25 > sizeof( struct V_23 ) ) {
F_17 ( V_26 L_2 ,
V_24 -> V_25 ) ;
return - V_27 ;
}
V_16 = F_10 ( V_14 , V_24 -> V_25 ) ;
if ( F_11 ( ! V_16 ) )
return - V_18 ;
memcpy ( & V_24 -> V_28 , V_16 , V_24 -> V_25 ) ;
F_12 ( L_3 , V_19 , V_24 -> V_25 ) ;
return 0 ;
}
static int
F_18 ( struct V_13 * V_14 , T_4 * V_29 )
{
T_3 * V_16 ;
int V_30 ;
V_16 = F_10 ( V_14 , 4 ) ;
if ( F_11 ( ! V_16 ) )
return - V_18 ;
V_30 = F_16 ( V_16 ++ ) ;
if ( V_30 < 0 )
return - V_31 ;
F_12 ( L_4 , V_19 , V_30 ) ;
V_16 = F_10 ( V_14 , V_30 ) ;
if ( F_11 ( ! V_16 ) )
return - V_18 ;
if ( ! F_19 ( ( char * ) V_16 , V_30 , V_29 ) )
return - V_31 ;
return 0 ;
}
static void F_20 ( struct V_32 * V_33 )
{
int V_34 ;
if ( V_33 -> V_35 ) {
for ( V_34 = 0 ; V_34 < V_33 -> V_36 ; V_34 ++ ) {
if ( V_33 -> V_35 [ V_34 ] ) {
F_7 ( V_33 -> V_35 [ V_34 ] -> V_37 ) ;
F_21 ( V_33 -> V_35 [ V_34 ] -> V_38 ) ;
F_7 ( V_33 -> V_35 [ V_34 ] ) ;
}
}
F_7 ( V_33 -> V_35 ) ;
V_33 -> V_35 = NULL ;
}
}
static int F_22 ( struct V_39 * V_40 )
{
int V_41 = 0 ;
F_12 ( L_5 , V_19 ) ;
if ( V_40 -> V_42 . V_43 != 0 ||
V_40 -> V_42 . V_44 != V_45 ) {
F_12 ( L_6 ,
V_19 ) ;
V_41 = - V_31 ;
}
F_12 ( L_7 , V_19 , V_41 ) ;
return V_41 ;
}
static void F_23 ( struct V_32 * V_33 )
{
if ( V_33 ) {
F_20 ( V_33 ) ;
F_7 ( V_33 ) ;
}
}
static void F_24 ( struct V_32 * V_33 )
{
struct V_46 * V_47 ;
int V_34 , V_48 ;
for ( V_34 = 0 ; V_34 < V_33 -> V_36 - 1 ; V_34 ++ ) {
for ( V_48 = V_34 + 1 ; V_48 < V_33 -> V_36 ; V_48 ++ )
if ( V_33 -> V_35 [ V_34 ] -> V_49 <
V_33 -> V_35 [ V_48 ] -> V_49 ) {
V_47 = V_33 -> V_35 [ V_34 ] ;
V_33 -> V_35 [ V_34 ] = V_33 -> V_35 [ V_48 ] ;
V_33 -> V_35 [ V_48 ] = V_47 ;
}
}
}
static struct V_50 *
F_25 ( struct V_1 * V_51 ,
struct V_39 * V_40 ,
T_1 V_3 )
{
struct V_50 * V_41 ;
struct V_32 * V_33 = NULL ;
struct V_13 V_52 ;
struct V_53 V_54 ;
struct V_55 * V_56 ;
T_5 V_57 ;
T_4 V_36 ;
T_3 * V_16 ;
int V_34 , V_58 ;
F_12 ( L_5 , V_19 ) ;
V_56 = F_26 ( V_3 ) ;
if ( ! V_56 )
return F_27 ( - V_59 ) ;
F_28 ( & V_52 , & V_54 , V_40 -> V_60 -> V_61 ,
V_40 -> V_60 -> V_30 ) ;
F_29 ( & V_52 , F_30 ( V_56 ) , V_62 ) ;
V_58 = - V_63 ;
V_16 = F_10 ( & V_52 , 8 + 4 ) ;
if ( ! V_16 )
goto V_64;
V_16 = F_31 ( V_16 , & V_57 ) ;
V_36 = F_16 ( V_16 ++ ) ;
F_12 ( L_8 , V_19 ,
V_57 , V_36 ) ;
if ( V_36 > V_65 ||
V_36 == 0 )
goto V_64;
V_58 = - V_59 ;
V_33 = F_2 ( sizeof( * V_33 ) , V_3 ) ;
if ( ! V_33 )
goto V_64;
V_33 -> V_36 = V_36 ;
V_33 -> V_57 = V_57 ;
V_33 -> V_35 = F_32 ( V_33 -> V_36 ,
sizeof( V_33 -> V_35 [ 0 ] ) , V_3 ) ;
if ( V_33 -> V_35 == NULL )
goto V_64;
for ( V_34 = 0 ; V_34 < V_33 -> V_36 ; V_34 ++ ) {
struct V_20 V_21 ;
struct V_66 * V_67 ;
T_4 V_68 ;
T_4 V_69 ;
int V_48 ;
V_58 = - V_63 ;
V_16 = F_10 ( & V_52 , 4 ) ;
if ( ! V_16 )
goto V_64;
V_68 = F_16 ( V_16 ) ;
if ( V_68 != 1 )
goto V_64;
V_33 -> V_35 [ V_34 ] =
F_2 ( sizeof( struct V_46 ) ,
V_3 ) ;
if ( V_33 -> V_35 [ V_34 ] == NULL ) {
V_58 = - V_59 ;
goto V_64;
}
F_33 ( & V_33 -> V_35 [ V_34 ] -> V_70 ) ;
V_33 -> V_35 [ V_34 ] -> V_68 = V_68 ;
V_58 = F_13 ( & V_52 , & V_21 ) ;
if ( V_58 )
goto V_64;
V_67 = F_34 ( F_35 ( V_51 -> V_71 ) ,
& V_21 , V_51 -> V_72 ,
V_3 ) ;
if ( V_67 )
V_33 -> V_35 [ V_34 ] -> V_38 =
F_36 ( V_67 ) ;
else
goto V_64;
V_58 = - V_63 ;
V_16 = F_10 ( & V_52 , 4 ) ;
if ( ! V_16 )
goto V_64;
V_33 -> V_35 [ V_34 ] -> V_49 = F_16 ( V_16 ) ;
V_58 = F_9 ( & V_52 , & V_33 -> V_35 [ V_34 ] -> V_15 ) ;
if ( V_58 )
goto V_64;
V_16 = F_10 ( & V_52 , 4 ) ;
if ( ! V_16 )
goto V_64;
V_69 = F_16 ( V_16 ) ;
V_33 -> V_35 [ V_34 ] -> V_37 =
F_2 ( V_69 * sizeof( struct V_23 ) ,
V_3 ) ;
if ( V_33 -> V_35 [ V_34 ] -> V_37 == NULL ) {
V_58 = - V_59 ;
goto V_64;
}
for ( V_48 = 0 ; V_48 < V_69 ; V_48 ++ ) {
V_58 = F_15 ( & V_52 ,
& V_33 -> V_35 [ V_34 ] -> V_37 [ V_48 ] ) ;
if ( V_58 )
goto V_64;
}
V_33 -> V_35 [ V_34 ] -> V_73 = V_69 ;
V_58 = F_18 ( & V_52 , & V_33 -> V_35 [ V_34 ] -> V_74 ) ;
if ( V_58 )
goto V_64;
V_58 = F_18 ( & V_52 , & V_33 -> V_35 [ V_34 ] -> V_75 ) ;
if ( V_58 )
goto V_64;
F_12 ( L_9 , V_19 ,
V_33 -> V_35 [ V_34 ] -> V_74 ,
V_33 -> V_35 [ V_34 ] -> V_75 ) ;
}
F_24 ( V_33 ) ;
V_58 = F_22 ( V_40 ) ;
if ( V_58 )
goto V_64;
V_41 = & V_33 -> V_7 ;
F_12 ( L_10 , V_19 ) ;
V_76:
F_37 ( V_56 ) ;
return V_41 ;
V_64:
F_23 ( V_33 ) ;
V_41 = F_27 ( V_58 ) ;
F_12 ( L_11 , V_19 , V_58 ) ;
goto V_76;
}
static bool F_38 ( struct V_1 * V_77 )
{
struct V_50 * V_78 ;
F_39 (lseg, &layout->plh_segs, pls_list)
if ( V_78 -> V_79 . V_80 == V_81 )
return true ;
return false ;
}
static void
F_40 ( struct V_50 * V_78 )
{
struct V_32 * V_33 = F_41 ( V_78 ) ;
int V_34 ;
F_12 ( L_5 , V_19 ) ;
for ( V_34 = 0 ; V_34 < V_33 -> V_36 ; V_34 ++ ) {
if ( V_33 -> V_35 [ V_34 ] ) {
F_21 ( V_33 -> V_35 [ V_34 ] -> V_38 ) ;
V_33 -> V_35 [ V_34 ] -> V_38 = NULL ;
if ( V_33 -> V_35 [ V_34 ] -> V_82 ) {
F_42 ( V_33 -> V_35 [ V_34 ] -> V_82 ) ;
V_33 -> V_35 [ V_34 ] -> V_82 = NULL ;
}
}
}
if ( V_78 -> V_79 . V_80 == V_81 ) {
struct V_4 * V_5 ;
struct V_2 * V_2 ;
V_5 = F_8 ( V_78 -> V_83 ) ;
V_2 = V_5 -> V_7 . V_71 ;
F_43 ( & V_2 -> V_84 ) ;
if ( ! F_38 ( V_78 -> V_83 ) ) {
V_5 -> V_85 . V_86 = 0 ;
F_7 ( V_5 -> V_85 . V_87 ) ;
V_5 -> V_85 . V_87 = NULL ;
}
F_44 ( & V_2 -> V_84 ) ;
}
F_23 ( V_33 ) ;
}
static int
F_45 ( struct V_32 * V_33 )
{
return 1 ;
}
static int
F_46 ( struct V_50 * V_78 ,
struct V_88 * V_89 ,
T_1 V_3 )
{
struct V_32 * V_33 = F_41 ( V_78 ) ;
struct V_90 * V_87 ;
int V_25 ;
if ( V_89 -> V_91 -> V_86 != 0 ) {
return 0 ;
}
V_25 = F_45 ( V_33 ) * F_47 ( V_78 ) ;
V_87 = F_32 ( V_25 , sizeof( struct V_90 ) ,
V_3 ) ;
if ( ! V_87 )
return - V_59 ;
else {
int V_34 ;
F_43 ( V_89 -> V_70 ) ;
if ( V_89 -> V_91 -> V_86 != 0 )
F_7 ( V_87 ) ;
else {
V_89 -> V_91 -> V_87 = V_87 ;
V_89 -> V_91 -> V_86 = V_25 ;
for ( V_34 = 0 ; V_34 < V_25 ; V_34 ++ ) {
F_3 ( & V_87 [ V_34 ] . V_92 ) ;
F_3 ( & V_87 [ V_34 ] . V_93 ) ;
V_87 [ V_34 ] . V_94 . V_95 =
V_96 ;
}
}
F_44 ( V_89 -> V_70 ) ;
return 0 ;
}
}
static struct V_97 *
F_48 ( struct V_98 * V_99 ,
int * V_100 )
{
struct V_32 * V_33 ;
struct V_97 * V_91 ;
int V_101 ;
V_33 = F_41 ( V_99 -> V_102 ) ;
for ( V_101 = 0 ; V_101 < V_33 -> V_36 ; V_101 ++ ) {
V_91 = F_49 ( V_99 -> V_102 , V_101 , false ) ;
if ( V_91 ) {
* V_100 = V_101 ;
return V_91 ;
}
}
return NULL ;
}
static void
F_50 ( struct V_98 * V_99 ,
struct V_103 * V_104 )
{
struct V_105 * V_106 ;
struct V_46 * V_107 ;
struct V_97 * V_91 ;
int V_108 ;
if ( ! V_99 -> V_102 )
V_99 -> V_102 = F_51 ( V_99 -> V_109 ,
V_104 -> V_110 ,
0 ,
V_45 ,
V_111 ,
V_112 ) ;
if ( V_99 -> V_102 == NULL )
goto V_113;
V_91 = F_48 ( V_99 , & V_108 ) ;
if ( ! V_91 )
goto V_113;
V_107 = F_52 ( V_99 -> V_102 , V_108 ) ;
V_99 -> V_114 = V_108 ;
V_106 = & V_99 -> V_115 [ 0 ] ;
V_106 -> V_116 = V_107 -> V_38 -> V_117 [ 0 ] . V_118 ;
return;
V_113:
F_53 ( V_99 -> V_102 ) ;
V_99 -> V_102 = NULL ;
F_54 ( V_99 ) ;
}
static void
F_55 ( struct V_98 * V_99 ,
struct V_103 * V_104 )
{
struct V_46 * V_107 ;
struct V_105 * V_106 ;
struct V_88 V_89 ;
struct V_97 * V_91 ;
int V_34 ;
int V_119 ;
if ( ! V_99 -> V_102 )
V_99 -> V_102 = F_51 ( V_99 -> V_109 ,
V_104 -> V_110 ,
0 ,
V_45 ,
V_81 ,
V_120 ) ;
if ( V_99 -> V_102 == NULL )
goto V_113;
F_56 ( & V_89 , V_99 -> V_109 , V_99 -> V_121 ) ;
V_119 = F_46 ( V_99 -> V_102 , & V_89 , V_120 ) ;
if ( V_119 < 0 )
goto V_113;
if ( F_57 ( V_99 -> V_122 !=
F_47 ( V_99 -> V_102 ) ) )
goto V_113;
for ( V_34 = 0 ; V_34 < V_99 -> V_122 ; V_34 ++ ) {
V_91 = F_49 ( V_99 -> V_102 , V_34 , true ) ;
if ( ! V_91 )
goto V_113;
V_106 = & V_99 -> V_115 [ V_34 ] ;
V_107 = F_52 ( V_99 -> V_102 , V_34 ) ;
V_106 -> V_116 = V_107 -> V_38 -> V_117 [ 0 ] . V_123 ;
}
return;
V_113:
F_53 ( V_99 -> V_102 ) ;
V_99 -> V_102 = NULL ;
F_58 ( V_99 ) ;
}
static unsigned int
F_59 ( struct V_98 * V_99 ,
struct V_103 * V_104 )
{
if ( ! V_99 -> V_102 )
V_99 -> V_102 = F_51 ( V_99 -> V_109 ,
V_104 -> V_110 ,
0 ,
V_45 ,
V_81 ,
V_120 ) ;
if ( V_99 -> V_102 )
return F_47 ( V_99 -> V_102 ) ;
F_53 ( V_99 -> V_102 ) ;
V_99 -> V_102 = NULL ;
F_58 ( V_99 ) ;
return 1 ;
}
static void F_60 ( struct V_124 * V_125 , bool V_126 )
{
struct V_127 * V_128 = & V_125 -> V_128 ;
F_61 ( V_125 -> V_2 , false ) ;
if ( V_126 ) {
F_12 ( L_12
L_13 , V_19 ,
V_125 -> V_128 . V_129 ,
V_125 -> V_2 -> V_130 -> V_131 ,
( unsigned long long ) F_62 ( V_125 -> V_2 ) ,
V_125 -> args . V_132 ,
( unsigned long long ) V_125 -> args . V_43 ) ;
if ( ! V_125 -> V_133 ) {
struct V_134 * V_135 ;
V_135 = F_63 ( V_125 -> V_61 . V_136 ) -> V_110 ;
F_64 ( V_137 , & V_135 -> V_138 ) ;
V_125 -> V_139 -> V_140 ( & V_125 -> V_61 ) ;
} else {
F_65 ( V_125 -> V_133 ) ;
V_125 -> V_141 . V_95 = V_142 ;
V_125 -> V_143 = 0 ;
}
return;
}
if ( ! F_66 ( V_144 , & V_125 -> V_138 ) ) {
F_12 ( L_14
L_13 , V_19 ,
V_125 -> V_128 . V_129 ,
V_125 -> V_2 -> V_130 -> V_131 ,
( unsigned long long ) F_62 ( V_125 -> V_2 ) ,
V_125 -> args . V_132 ,
( unsigned long long ) V_125 -> args . V_43 ) ;
V_128 -> V_145 = F_67 ( V_125 ) ;
}
}
static void F_68 ( struct V_124 * V_125 )
{
struct V_127 * V_128 = & V_125 -> V_128 ;
F_61 ( V_125 -> V_2 , false ) ;
if ( ! F_66 ( V_144 , & V_125 -> V_138 ) ) {
F_12 ( L_14
L_13 , V_19 ,
V_125 -> V_128 . V_129 ,
V_125 -> V_2 -> V_130 -> V_131 ,
( unsigned long long ) F_62 ( V_125 -> V_2 ) ,
V_125 -> args . V_132 ,
( unsigned long long ) V_125 -> args . V_43 ) ;
V_128 -> V_145 = F_69 ( V_125 ) ;
}
}
static int F_70 ( struct V_127 * V_128 ,
struct V_146 * V_147 ,
struct V_148 * V_149 ,
struct V_50 * V_78 ,
int V_101 )
{
struct V_1 * V_8 = V_78 -> V_83 ;
struct V_2 * V_2 = V_8 -> V_71 ;
struct V_150 * V_151 = F_35 ( V_2 ) ;
struct V_66 * V_21 = F_71 ( V_78 , V_101 ) ;
struct V_148 * V_152 = V_151 -> V_148 ;
struct V_153 * V_154 = & V_149 -> V_155 -> V_156 ;
if ( V_128 -> V_145 >= 0 )
return 0 ;
switch ( V_128 -> V_145 ) {
case - V_157 :
case - V_158 :
case - V_159 :
if ( V_147 == NULL )
break;
F_72 ( V_147 -> V_2 ) ;
case - V_160 :
if ( V_147 == NULL )
break;
if ( F_73 ( V_151 , V_147 ) < 0 )
goto V_161;
goto V_162;
case - V_163 :
if ( V_147 != NULL ) {
if ( F_73 ( V_151 , V_147 ) < 0 )
goto V_161;
}
F_74 ( V_152 ) ;
goto V_162;
case - V_164 :
case - V_165 :
case - V_166 :
case - V_167 :
case - V_168 :
case - V_169 :
case - V_170 :
F_12 ( L_15
L_16 , V_19 , V_128 -> V_145 ,
V_149 -> V_171 ) ;
F_75 ( V_149 -> V_155 , V_128 -> V_145 ) ;
break;
case - V_172 :
case - V_173 :
F_76 ( V_128 , V_174 ) ;
break;
case - V_175 :
break;
case - V_176 :
case - V_177 :
case - V_178 :
case - V_179 :
case - V_180 :
case - V_181 :
F_12 ( L_17 , V_19 ,
V_128 -> V_145 ) ;
F_77 ( F_78 ( V_2 ) ) ;
F_79 ( & V_154 -> V_182 ) ;
goto V_183;
case - V_184 :
case - V_185 :
case - V_186 :
case - V_187 :
case - V_63 :
case - V_188 :
case - V_189 :
F_12 ( L_18 , V_19 ,
V_128 -> V_145 ) ;
F_80 ( V_21 ) ;
F_79 ( & V_154 -> V_182 ) ;
default:
if ( F_81 ( V_78 ) )
return - V_190 ;
V_183:
F_12 ( L_19 , V_19 ,
V_128 -> V_145 ) ;
return - V_191 ;
}
V_192:
V_128 -> V_145 = 0 ;
return - V_193 ;
V_161:
V_128 -> V_145 = - V_63 ;
return 0 ;
V_162:
F_82 ( & V_152 -> V_194 , V_128 , NULL ) ;
if ( F_83 ( V_195 , & V_152 -> V_196 ) == 0 )
F_84 ( & V_152 -> V_194 , V_128 ) ;
goto V_192;
}
static int F_85 ( struct V_127 * V_128 ,
struct V_50 * V_78 ,
int V_101 )
{
struct V_66 * V_21 = F_71 ( V_78 , V_101 ) ;
if ( V_128 -> V_145 >= 0 )
return 0 ;
if ( V_128 -> V_145 != - V_197 ) {
F_12 ( L_18 , V_19 ,
V_128 -> V_145 ) ;
F_80 ( V_21 ) ;
if ( F_81 ( V_78 ) )
return - V_190 ;
else
return - V_191 ;
}
if ( V_128 -> V_145 == - V_197 )
F_86 ( V_78 -> V_83 -> V_71 , V_198 ) ;
V_128 -> V_145 = 0 ;
F_87 ( V_128 ) ;
F_76 ( V_128 , V_199 ) ;
return - V_193 ;
}
static int F_88 ( struct V_127 * V_128 ,
struct V_146 * V_147 ,
struct V_148 * V_149 ,
struct V_50 * V_78 ,
int V_101 )
{
int V_200 = V_149 -> V_201 -> V_202 -> V_203 ;
switch ( V_200 ) {
case 3 :
return F_85 ( V_128 , V_78 , V_101 ) ;
case 4 :
return F_70 ( V_128 , V_147 , V_149 ,
V_78 , V_101 ) ;
default:
F_57 ( 1 ) ;
return 0 ;
}
}
static void F_89 ( struct V_50 * V_78 ,
int V_101 , T_5 V_43 , T_5 V_44 ,
T_4 V_119 , int V_204 )
{
struct V_46 * V_107 ;
int V_10 ;
V_107 = F_52 ( V_78 , V_101 ) ;
V_10 = F_90 ( F_8 ( V_78 -> V_83 ) ,
V_107 , V_43 , V_44 , V_119 , V_204 ,
V_205 ) ;
F_12 ( L_20 , V_19 , V_10 , V_204 , V_119 ) ;
}
static int F_91 ( struct V_127 * V_128 ,
struct V_124 * V_125 )
{
struct V_2 * V_2 ;
int V_10 ;
F_92 ( V_125 , V_128 -> V_145 ) ;
if ( V_128 -> V_145 == - V_188 && ! V_125 -> V_206 . V_207 )
V_125 -> V_206 . V_207 = V_208 ;
if ( V_128 -> V_145 < 0 && V_125 -> V_206 . V_207 )
F_89 ( V_125 -> V_78 , V_125 -> V_209 ,
V_125 -> args . V_43 , V_125 -> args . V_132 ,
V_125 -> V_206 . V_207 , V_210 ) ;
V_10 = F_88 ( V_128 , V_125 -> args . V_211 -> V_147 ,
V_125 -> V_212 , V_125 -> V_78 ,
V_125 -> V_209 ) ;
switch ( V_10 ) {
case - V_190 :
F_64 ( V_213 ,
& V_125 -> V_78 -> V_83 -> V_214 ) ;
F_93 ( V_125 ) ;
return V_128 -> V_145 ;
case - V_191 :
V_2 = V_125 -> V_78 -> V_83 -> V_71 ;
F_94 ( V_2 , V_125 -> V_78 ) ;
F_68 ( V_125 ) ;
return V_128 -> V_145 ;
case - V_193 :
F_95 ( V_128 ) ;
return - V_193 ;
}
return 0 ;
}
static void
F_96 ( struct V_124 * V_125 )
{
F_97 ( V_125 ) ;
F_12 ( L_21 , V_19 , V_125 -> V_2 -> V_215 ,
( unsigned long ) F_78 ( V_125 -> V_2 ) -> V_77 -> V_216 ) ;
}
static bool
F_98 ( struct V_50 * V_78 , int V_101 )
{
struct V_66 * V_217 = F_71 ( V_78 , V_101 ) ;
return F_99 ( V_217 ) ;
}
static int F_100 ( struct V_127 * V_128 ,
struct V_124 * V_125 )
{
if ( F_11 ( F_83 ( V_218 , & V_125 -> args . V_211 -> V_138 ) ) ) {
F_101 ( V_128 , - V_63 ) ;
return - V_63 ;
}
if ( F_98 ( V_125 -> V_78 , V_125 -> V_209 ) ) {
F_12 ( L_22 , V_19 , V_128 -> V_129 ) ;
if ( F_81 ( V_125 -> V_78 ) )
F_93 ( V_125 ) ;
else
F_68 ( V_125 ) ;
F_101 ( V_128 , 0 ) ;
return - V_193 ;
}
V_125 -> V_219 = F_91 ;
return 0 ;
}
static void F_102 ( struct V_127 * V_128 , void * V_28 )
{
struct V_124 * V_125 = V_28 ;
if ( F_100 ( V_128 , V_125 ) )
return;
F_103 ( V_128 ) ;
}
static int F_104 ( struct V_148 * V_212 ,
struct V_220 * args ,
struct V_221 * V_206 ,
struct V_127 * V_128 )
{
if ( V_212 -> V_155 )
return F_105 ( V_212 -> V_155 ,
args ,
V_206 ,
V_128 ) ;
return F_106 ( V_212 -> V_222 ,
args ,
V_206 ,
V_128 ) ;
}
static void F_107 ( struct V_127 * V_128 , void * V_28 )
{
struct V_124 * V_125 = V_28 ;
if ( F_100 ( V_128 , V_125 ) )
return;
if ( F_104 ( V_125 -> V_212 ,
& V_125 -> args . V_223 ,
& V_125 -> V_206 . V_224 ,
V_128 ) )
return;
if ( F_108 ( & V_125 -> args . V_15 , V_125 -> args . V_211 ,
V_125 -> args . V_225 , V_226 ) == - V_63 )
F_101 ( V_128 , - V_63 ) ;
}
static void F_109 ( struct V_127 * V_128 , void * V_28 )
{
struct V_124 * V_125 = V_28 ;
F_12 ( L_23 , V_19 , V_128 -> V_145 ) ;
if ( F_83 ( V_144 , & V_125 -> V_138 ) &&
V_128 -> V_145 == 0 ) {
F_110 ( V_128 , & V_125 -> V_206 . V_224 ) ;
return;
}
V_125 -> V_227 -> V_228 ( V_128 , V_125 ) ;
}
static void F_111 ( struct V_127 * V_128 , void * V_28 )
{
struct V_124 * V_125 = V_28 ;
F_112 ( V_128 ,
& F_113 ( V_125 -> V_2 ) -> V_229 [ V_230 ] ) ;
}
static int F_114 ( struct V_127 * V_128 ,
struct V_124 * V_125 )
{
struct V_2 * V_2 ;
int V_10 ;
F_115 ( V_125 , V_128 -> V_145 ) ;
if ( V_128 -> V_145 == - V_188 && ! V_125 -> V_206 . V_207 )
V_125 -> V_206 . V_207 = V_208 ;
if ( V_128 -> V_145 < 0 && V_125 -> V_206 . V_207 )
F_89 ( V_125 -> V_78 , V_125 -> V_209 ,
V_125 -> args . V_43 , V_125 -> args . V_132 ,
V_125 -> V_206 . V_207 , V_231 ) ;
V_10 = F_88 ( V_128 , V_125 -> args . V_211 -> V_147 ,
V_125 -> V_212 , V_125 -> V_78 ,
V_125 -> V_209 ) ;
switch ( V_10 ) {
case - V_190 :
case - V_191 :
V_2 = V_125 -> V_78 -> V_83 -> V_71 ;
F_94 ( V_2 , V_125 -> V_78 ) ;
if ( V_10 == - V_190 ) {
F_116 ( V_125 -> V_78 -> V_83 ) ;
F_60 ( V_125 , true ) ;
} else {
F_117 ( V_125 -> V_78 -> V_83 ) ;
F_60 ( V_125 , false ) ;
}
return V_128 -> V_145 ;
case - V_193 :
F_95 ( V_128 ) ;
return - V_193 ;
}
if ( V_125 -> V_206 . V_141 -> V_95 == V_232 ||
V_125 -> V_206 . V_141 -> V_95 == V_233 )
F_96 ( V_125 ) ;
return 0 ;
}
static int F_118 ( struct V_127 * V_128 ,
struct V_234 * V_28 )
{
struct V_2 * V_2 ;
int V_10 ;
F_119 ( V_28 , V_128 -> V_145 ) ;
if ( V_128 -> V_145 == - V_188 && ! V_28 -> V_206 . V_207 )
V_28 -> V_206 . V_207 = V_208 ;
if ( V_128 -> V_145 < 0 && V_28 -> V_206 . V_207 )
F_89 ( V_28 -> V_78 , V_28 -> V_235 ,
V_28 -> args . V_43 , V_28 -> args . V_132 ,
V_28 -> V_206 . V_207 , V_236 ) ;
V_10 = F_88 ( V_128 , NULL , V_28 -> V_212 ,
V_28 -> V_78 , V_28 -> V_235 ) ;
switch ( V_10 ) {
case - V_190 :
case - V_191 :
V_2 = V_28 -> V_78 -> V_83 -> V_71 ;
F_94 ( V_2 , V_28 -> V_78 ) ;
if ( V_10 == - V_190 )
F_116 ( V_28 -> V_78 -> V_83 ) ;
else
F_117 ( V_28 -> V_78 -> V_83 ) ;
F_120 ( V_28 ) ;
return - V_193 ;
case - V_193 :
F_95 ( V_128 ) ;
return - V_193 ;
}
if ( V_28 -> V_141 . V_95 == V_142 )
F_121 ( V_28 ) ;
return 0 ;
}
static int F_122 ( struct V_127 * V_128 ,
struct V_124 * V_125 )
{
if ( F_11 ( F_83 ( V_218 , & V_125 -> args . V_211 -> V_138 ) ) ) {
F_101 ( V_128 , - V_63 ) ;
return - V_63 ;
}
if ( F_98 ( V_125 -> V_78 , V_125 -> V_209 ) ) {
bool V_126 ;
V_126 = F_81 ( V_125 -> V_78 ) ;
F_12 ( L_24 , V_19 ,
V_128 -> V_129 , V_126 ? L_25 : L_26 ) ;
F_60 ( V_125 , V_126 ) ;
F_101 ( V_128 , 0 ) ;
return - V_193 ;
}
return 0 ;
}
static void F_123 ( struct V_127 * V_128 , void * V_28 )
{
struct V_124 * V_125 = V_28 ;
if ( F_122 ( V_128 , V_125 ) )
return;
F_103 ( V_128 ) ;
}
static void F_124 ( struct V_127 * V_128 , void * V_28 )
{
struct V_124 * V_125 = V_28 ;
if ( F_122 ( V_128 , V_125 ) )
return;
if ( F_104 ( V_125 -> V_212 ,
& V_125 -> args . V_223 ,
& V_125 -> V_206 . V_224 ,
V_128 ) )
return;
if ( F_108 ( & V_125 -> args . V_15 , V_125 -> args . V_211 ,
V_125 -> args . V_225 , V_237 ) == - V_63 )
F_101 ( V_128 , - V_63 ) ;
}
static void F_125 ( struct V_127 * V_128 , void * V_28 )
{
struct V_124 * V_125 = V_28 ;
if ( F_83 ( V_144 , & V_125 -> V_138 ) &&
V_128 -> V_145 == 0 ) {
F_110 ( V_128 , & V_125 -> V_206 . V_224 ) ;
return;
}
V_125 -> V_227 -> V_228 ( V_128 , V_125 ) ;
}
static void F_126 ( struct V_127 * V_128 , void * V_28 )
{
struct V_124 * V_125 = V_28 ;
F_112 ( V_128 ,
& F_113 ( V_125 -> V_2 ) -> V_229 [ V_238 ] ) ;
}
static void F_127 ( struct V_127 * V_128 , void * V_28 )
{
F_103 ( V_128 ) ;
}
static void F_128 ( struct V_127 * V_128 , void * V_28 )
{
struct V_234 * V_239 = V_28 ;
F_104 ( V_239 -> V_212 ,
& V_239 -> args . V_223 ,
& V_239 -> V_206 . V_224 ,
V_128 ) ;
}
static void F_129 ( struct V_127 * V_128 , void * V_28 )
{
struct V_234 * V_240 = V_28 ;
F_112 ( V_128 ,
& F_113 ( V_240 -> V_2 ) -> V_229 [ V_241 ] ) ;
}
static enum V_242
F_130 ( struct V_124 * V_125 )
{
struct V_50 * V_78 = V_125 -> V_78 ;
struct V_97 * V_91 ;
struct V_243 * V_244 ;
struct V_245 * V_246 ;
T_6 V_43 = V_125 -> args . V_43 ;
T_4 V_101 = V_125 -> V_209 ;
int V_200 ;
struct V_23 * V_24 ;
F_12 ( L_27 ,
V_19 , V_125 -> V_2 -> V_215 ,
V_125 -> args . V_247 , ( V_248 ) V_125 -> args . V_132 , V_43 ) ;
V_91 = F_49 ( V_78 , V_101 , false ) ;
if ( ! V_91 )
goto V_249;
V_244 = F_131 ( V_78 , V_101 , V_91 -> V_212 ,
V_125 -> V_2 ) ;
if ( F_132 ( V_244 ) )
goto V_249;
V_246 = F_133 ( V_78 , V_101 , V_125 -> V_82 ) ;
if ( F_132 ( V_246 ) )
goto V_249;
V_200 = F_134 ( V_78 , V_101 ) ;
F_12 ( L_28 , V_19 ,
V_91 -> V_250 , F_135 ( & V_91 -> V_212 -> V_251 ) , V_200 ) ;
F_136 ( & V_91 -> V_212 -> V_251 ) ;
V_125 -> V_212 = V_91 -> V_212 ;
V_24 = F_137 ( V_78 , V_101 ) ;
if ( V_24 )
V_125 -> args . V_24 = V_24 ;
V_125 -> args . V_43 = V_43 ;
V_125 -> V_252 = V_43 ;
F_138 ( V_244 , V_125 , V_246 , V_91 -> V_212 -> V_253 ,
V_200 == 3 ? & V_254 :
& V_255 ,
0 , V_256 ) ;
return V_257 ;
V_249:
if ( F_81 ( V_78 ) )
return V_258 ;
return V_259 ;
}
static enum V_242
F_139 ( struct V_124 * V_125 , int V_260 )
{
struct V_50 * V_78 = V_125 -> V_78 ;
struct V_97 * V_91 ;
struct V_243 * V_244 ;
struct V_245 * V_246 ;
T_6 V_43 = V_125 -> args . V_43 ;
int V_200 ;
struct V_23 * V_24 ;
int V_101 = V_125 -> V_209 ;
V_91 = F_49 ( V_78 , V_101 , true ) ;
if ( ! V_91 )
return V_259 ;
V_244 = F_131 ( V_78 , V_101 , V_91 -> V_212 ,
V_125 -> V_2 ) ;
if ( F_132 ( V_244 ) )
return V_259 ;
V_246 = F_133 ( V_78 , V_101 , V_125 -> V_82 ) ;
if ( F_132 ( V_246 ) )
return V_259 ;
V_200 = F_134 ( V_78 , V_101 ) ;
F_12 ( L_29 ,
V_19 , V_125 -> V_2 -> V_215 , V_260 , ( V_248 ) V_125 -> args . V_132 ,
V_43 , V_91 -> V_250 , F_135 ( & V_91 -> V_212 -> V_251 ) ,
V_200 ) ;
V_125 -> V_219 = F_114 ;
F_136 ( & V_91 -> V_212 -> V_251 ) ;
V_125 -> V_212 = V_91 -> V_212 ;
V_125 -> V_261 = V_101 ;
V_24 = F_137 ( V_78 , V_101 ) ;
if ( V_24 )
V_125 -> args . V_24 = V_24 ;
V_125 -> args . V_43 = V_43 ;
F_138 ( V_244 , V_125 , V_246 , V_91 -> V_212 -> V_253 ,
V_200 == 3 ? & V_262 :
& V_263 ,
V_260 , V_256 ) ;
return V_257 ;
}
static T_4 F_140 ( struct V_50 * V_78 , T_4 V_34 )
{
return V_34 ;
}
static struct V_23 *
F_141 ( struct V_50 * V_78 , T_4 V_34 )
{
struct V_32 * V_264 = F_41 ( V_78 ) ;
return & V_264 -> V_35 [ V_34 ] -> V_37 [ 0 ] ;
}
static int F_142 ( struct V_234 * V_28 , int V_265 )
{
struct V_50 * V_78 = V_28 -> V_78 ;
struct V_97 * V_91 ;
struct V_243 * V_244 ;
struct V_245 * V_246 ;
T_4 V_101 ;
int V_200 ;
struct V_23 * V_24 ;
V_101 = F_140 ( V_78 , V_28 -> V_235 ) ;
V_91 = F_49 ( V_78 , V_101 , true ) ;
if ( ! V_91 )
goto V_266;
V_244 = F_131 ( V_78 , V_101 , V_91 -> V_212 ,
V_28 -> V_2 ) ;
if ( F_132 ( V_244 ) )
goto V_266;
V_246 = F_133 ( V_78 , V_101 , V_28 -> V_82 ) ;
if ( F_132 ( V_246 ) )
goto V_266;
V_200 = F_134 ( V_78 , V_101 ) ;
F_12 ( L_30 , V_19 ,
V_28 -> V_2 -> V_215 , V_265 , F_135 ( & V_91 -> V_212 -> V_251 ) ,
V_200 ) ;
V_28 -> V_267 = F_118 ;
V_28 -> V_82 = V_246 ;
F_136 ( & V_91 -> V_212 -> V_251 ) ;
V_28 -> V_212 = V_91 -> V_212 ;
V_24 = F_141 ( V_78 , V_28 -> V_235 ) ;
if ( V_24 )
V_28 -> args . V_24 = V_24 ;
return F_143 ( V_244 , V_28 , V_91 -> V_212 -> V_253 ,
V_200 == 3 ? & V_268 :
& V_269 ,
V_265 , V_256 ) ;
V_266:
F_120 ( V_28 ) ;
F_144 ( V_28 ) ;
return - V_193 ;
}
static int
F_145 ( struct V_2 * V_2 , struct V_270 * V_271 ,
int V_265 , struct V_88 * V_89 )
{
return F_146 ( V_2 , V_271 , V_265 , V_89 ,
F_142 ) ;
}
static struct V_272 *
F_147 ( struct V_2 * V_2 )
{
struct V_1 * V_77 = F_78 ( V_2 ) -> V_77 ;
if ( V_77 == NULL )
return NULL ;
return & F_8 ( V_77 ) -> V_85 ;
}
static void
F_148 ( struct V_66 * V_273 )
{
F_149 ( F_150 ( V_273 , struct V_274 ,
V_275 ) ) ;
}
static int F_151 ( struct V_4 * V_276 ,
struct V_13 * V_14 ,
const struct V_277 * args )
{
struct V_1 * V_125 = & V_276 -> V_7 ;
T_3 * V_278 ;
int V_132 = 0 , V_41 = 0 ;
V_278 = F_152 ( V_14 , 4 ) ;
if ( F_11 ( ! V_278 ) )
return - V_279 ;
F_43 ( & V_125 -> V_71 -> V_84 ) ;
V_41 = F_153 ( V_276 , V_14 , & V_132 , & args -> V_42 ) ;
F_44 ( & V_125 -> V_71 -> V_84 ) ;
* V_278 = F_154 ( V_132 ) ;
return V_41 ;
}
static void F_155 ( struct V_4 * V_276 ,
struct V_13 * V_14 ,
const struct V_277 * args )
{
T_3 * V_16 ;
V_16 = F_152 ( V_14 , 4 ) ;
if ( F_156 ( V_16 ) )
* V_16 = F_154 ( 0 ) ;
}
static struct V_66 *
F_157 ( struct V_150 * V_280 ,
struct V_281 * V_282 , T_1 V_3 )
{
struct V_274 * V_283 ;
V_283 = F_158 ( V_280 , V_282 , V_3 ) ;
if ( ! V_283 )
return NULL ;
return & V_283 -> V_275 ;
}
static void
F_159 ( struct V_1 * V_8 ,
struct V_13 * V_14 ,
const struct V_277 * args )
{
struct V_4 * V_276 = F_8 ( V_8 ) ;
T_3 * V_278 ;
F_12 ( L_31 , V_19 ) ;
V_278 = F_152 ( V_14 , 4 ) ;
F_160 ( ! V_278 ) ;
if ( F_151 ( V_276 , V_14 , args ) )
goto V_192;
F_155 ( V_276 , V_14 , args ) ;
V_192:
* V_278 = F_154 ( ( V_14 -> V_16 - V_278 - 1 ) * 4 ) ;
F_12 ( L_32 , V_19 ) ;
}
static int T_7 F_161 ( void )
{
F_17 ( V_284 L_33 ,
V_19 ) ;
return F_162 ( & V_285 ) ;
}
static void T_8 F_163 ( void )
{
F_17 ( V_284 L_34 ,
V_19 ) ;
F_164 ( & V_285 ) ;
}
