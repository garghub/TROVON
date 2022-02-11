static int F_1 ( struct V_1 * V_2 ,
T_1 V_3 , T_2 V_4 , void * V_5 , T_2 V_6 )
{
return F_2 ( V_2 -> V_7 , F_3 ( V_2 -> V_7 , 0 ) ,
V_3 ,
V_8 | V_9 | V_10 ,
0x00 , V_4 , V_5 , V_6 , 1000 ) ;
}
static int F_4 ( struct V_1 * V_2 )
{
int V_11 ;
T_1 * V_5 ;
V_5 = F_5 ( 24 , V_12 ) ;
if ( ! V_5 ) {
V_11 = - V_13 ;
goto error;
}
V_11 = F_1 ( V_2 , V_14 , 0x00 , V_5 , 12 ) ;
if ( V_11 < 0 )
goto error;
V_11 = F_1 ( V_2 , V_14 , 0x01 , V_5 , 12 ) ;
if ( V_11 < 0 )
goto error;
V_11 = F_1 ( V_2 , V_14 , 0x02 , V_5 , 12 ) ;
if ( V_11 < 0 )
goto error;
V_11 = F_1 ( V_2 , V_15 , 0x00 , V_5 , 24 ) ;
if ( V_11 < 0 )
goto error;
V_11 = F_1 ( V_2 , V_16 , 0x00 , V_5 , 5 ) ;
if ( V_11 < 0 )
goto error;
V_11 = F_1 ( V_2 , V_14 , 0x03 , V_5 , 12 ) ;
error:
F_6 ( V_5 ) ;
return V_11 ;
}
static void F_7 ( struct V_17 * V_18 )
{
struct V_1 * V_19 = V_18 -> V_20 ;
F_8 ( V_19 -> V_2 , L_1 ) ;
F_4 ( V_19 ) ;
}
static void F_9 ( struct V_17 * V_18 )
{
struct V_1 * V_19 = V_18 -> V_20 ;
F_8 ( V_19 -> V_2 , L_2 ) ;
}
static void F_10 ( struct V_21 * V_22 , struct V_23 * V_24 )
{
int V_25 , V_26 , V_27 ;
int V_28 = F_11 ( V_22 -> V_28 ) ;
int V_29 = F_11 ( V_22 -> V_29 ) ;
int V_30 = F_11 ( V_22 -> V_30 ) ;
int V_31 = F_11 ( V_22 -> V_31 ) ;
int V_32 = F_11 ( V_22 -> V_32 ) ;
int V_33 = F_11 ( V_22 -> V_33 ) ;
int V_34 = F_12 ( V_24 , V_22 -> V_35 ) ;
if ( V_34 < 0 || V_34 >= V_36 )
return;
F_13 ( V_24 , V_34 ) ;
F_14 ( V_24 , V_37 , 1 ) ;
V_25 = ( V_28 > V_29 ) ;
V_26 = F_15 ( V_28 , V_29 ) ;
V_27 = F_16 ( V_28 , V_29 ) ;
F_17 ( V_24 , V_38 , V_30 ) ;
F_17 ( V_24 , V_39 , V_31 ) ;
F_17 ( V_24 , V_40 , V_32 ) ;
F_17 ( V_24 , V_41 , V_33 ) ;
F_17 ( V_24 , V_42 , V_25 ) ;
F_17 ( V_24 , V_43 , V_26 ) ;
F_17 ( V_24 , V_44 , V_27 ) ;
}
static void F_18 ( struct V_17 * V_18 )
{
struct V_1 * V_19 = V_18 -> V_20 ;
struct V_23 * V_24 = V_18 -> V_24 ;
int V_11 , V_45 , V_46 , V_47 , V_48 ;
T_3 V_49 ( V_50 ) ;
struct V_51 * V_52 = & V_19 -> V_53 -> V_52 ;
struct V_21 * V_54 = & V_19 -> V_53 -> V_55 [ 0 ] ;
F_8 ( V_19 -> V_2 , L_3 ) ;
V_46 = - 1 ;
do {
V_11 = F_19 ( V_19 -> V_7 ,
F_20 ( V_19 -> V_7 , V_19 -> V_56 ) ,
V_19 -> V_53 , V_19 -> V_57 ,
& V_45 , 1000 ) ;
F_8 ( V_19 -> V_2 , L_4 , V_45 ) ;
if ( V_11 < 0 ) {
F_21 ( V_19 -> V_2 , L_5 ) ;
return;
}
V_11 = V_45 - sizeof( struct V_51 ) ;
if ( V_11 % sizeof( struct V_21 ) != 0 ) {
F_21 ( V_19 -> V_2 , L_6 ) ;
return;
}
if ( V_46 == - 1 ) {
V_46 = F_11 ( V_52 -> V_58 ) ;
F_8 ( V_19 -> V_2 , L_7 , V_46 ) ;
V_50 = F_22 ( V_52 -> V_50 ) ;
}
if ( V_50 != V_52 -> V_50 )
F_8 ( V_19 -> V_2 , L_8 ) ;
V_47 = V_11 / sizeof( struct V_21 ) ;
F_8 ( V_19 -> V_2 , L_9 , V_47 ) ;
if ( V_47 > V_46 )
V_47 = V_46 ;
for ( V_48 = 0 ; V_48 < V_47 ; V_48 ++ ) {
V_46 -- ;
F_8 ( V_19 -> V_2 , L_10 ) ;
F_10 ( & ( V_54 [ V_48 ] ) , V_24 ) ;
}
} while ( V_46 > 0 );
F_23 ( V_24 ) ;
F_24 ( V_24 ) ;
F_25 ( V_19 ) ;
}
static void F_25 ( struct V_1 * V_19 )
{
struct V_59 * V_60 = ( void * ) ( V_19 -> V_53 ) ;
struct V_61 * V_62 ;
struct V_63 V_64 ;
struct V_65 * V_66 ;
int V_11 , V_45 ;
if ( ! F_26 ( & V_19 -> V_67 ) )
return;
F_27 ( & V_19 -> V_68 ) ;
if ( F_28 ( & V_19 -> V_69 ) ) {
F_8 ( V_19 -> V_2 , L_11 ) ;
F_29 ( & V_19 -> V_68 ) ;
return;
}
V_62 = F_30 ( V_19 -> V_69 . V_70 , struct V_61 , V_71 ) ;
F_31 ( & V_62 -> V_71 ) ;
F_29 ( & V_19 -> V_68 ) ;
F_8 ( V_19 -> V_2 , L_12 ) ;
V_11 = F_19 ( V_19 -> V_7 ,
F_20 ( V_19 -> V_7 , V_72 ) ,
V_19 -> V_53 , V_19 -> V_57 ,
& V_45 , 1000 ) ;
if ( V_11 < 0 ) {
F_21 ( V_19 -> V_2 , L_5 ) ;
goto V_73;
}
if ( V_45 != sizeof( struct V_59 ) ) {
F_21 ( V_19 -> V_2 , L_13 ,
V_45 , sizeof( struct V_59 ) ) ;
goto V_73;
}
if ( F_22 ( V_60 -> V_74 ) != V_75 ) {
F_21 ( V_19 -> V_2 , L_14 ) ;
goto V_73;
}
if ( F_22 ( V_60 -> V_6 ) != V_19 -> V_76 . V_77 ) {
F_21 ( V_19 -> V_2 , L_15 ) ;
goto V_73;
}
F_8 ( V_19 -> V_2 , L_16 ) ;
V_66 = F_32 ( & V_62 -> V_78 . V_79 , 0 ) ;
V_11 = F_33 ( & V_64 , V_19 -> V_7 ,
F_20 ( V_19 -> V_7 , V_72 ) , 0 ,
V_66 -> V_80 , V_66 -> V_81 , V_19 -> V_76 . V_77 , 0 ) ;
if ( V_11 < 0 ) {
F_21 ( V_19 -> V_2 , L_17 , V_11 ) ;
goto V_73;
}
F_34 ( & V_64 ) ;
if ( V_64 . V_82 < 0 ) {
F_21 ( V_19 -> V_2 , L_18 , V_64 . V_82 ) ;
goto V_73;
}
F_8 ( V_19 -> V_2 , L_19 ) ;
if ( V_19 -> V_83 == - 1 )
return;
V_62 -> V_78 . V_79 . V_84 = F_35 () ;
V_62 -> V_78 . V_83 = V_19 -> V_83 ++ ;
V_62 -> V_78 . V_85 = V_86 ;
F_36 ( & V_62 -> V_78 . V_79 , V_87 ) ;
F_8 ( V_19 -> V_2 , L_20 ) ;
return;
V_73:
F_36 ( & V_62 -> V_78 . V_79 , V_88 ) ;
}
static void F_37 ( struct V_23 * V_23 )
{
F_38 ( V_89 , V_23 -> V_90 ) ;
F_38 ( V_91 , V_23 -> V_90 ) ;
F_39 ( V_23 , V_38 ,
0 , V_92 , 0 , 0 ) ;
F_39 ( V_23 , V_39 ,
0 , V_93 , 0 , 0 ) ;
F_39 ( V_23 , V_40 ,
0 , V_92 , 0 , 0 ) ;
F_39 ( V_23 , V_41 ,
0 , V_93 , 0 , 0 ) ;
F_39 ( V_23 , V_43 ,
0 , V_92 , 0 , 0 ) ;
F_39 ( V_23 , V_44 ,
0 , V_93 , 0 , 0 ) ;
F_39 ( V_23 , V_42 , 0 , 1 , 0 , 0 ) ;
F_40 ( V_23 , V_36 ,
V_94 | V_95 ) ;
}
static int F_41 ( struct V_96 * V_97 ,
const struct V_98 * V_99 )
{
struct V_100 * V_7 = F_42 ( V_97 ) ;
struct V_1 * V_19 ;
struct V_101 * V_102 ;
struct V_103 * V_104 ;
struct V_17 * V_105 ;
int error ;
V_102 = & V_97 -> V_106 [ 0 ] ;
if ( V_102 -> V_107 . V_108 != 0xFF )
return - V_109 ;
if ( V_102 -> V_107 . V_110 < 5 )
return - V_109 ;
V_104 = & V_102 -> V_104 [ 4 ] . V_107 ;
if ( V_104 -> V_111 != V_112 )
return - V_109 ;
V_19 = F_43 ( sizeof( struct V_1 ) , V_12 ) ;
if ( ! V_19 )
return - V_13 ;
V_105 = F_44 () ;
if ( ! V_105 ) {
error = - V_13 ;
goto V_113;
}
F_45 ( & V_19 -> V_69 ) ;
F_46 ( & V_19 -> V_68 ) ;
F_47 ( & V_19 -> V_114 ) ;
V_105 -> V_20 = V_19 ;
V_105 -> V_115 = V_116 ;
V_105 -> V_117 = F_7 ;
V_105 -> V_118 = F_18 ;
V_105 -> V_119 = F_9 ;
F_37 ( V_105 -> V_24 ) ;
V_105 -> V_24 -> V_120 = V_121 ;
F_48 ( V_7 , & V_105 -> V_24 -> V_99 ) ;
F_49 ( V_7 , V_19 -> V_122 , sizeof( V_19 -> V_122 ) ) ;
F_50 ( V_19 -> V_122 , L_21 , sizeof( V_19 -> V_122 ) ) ;
V_105 -> V_24 -> V_122 = V_19 -> V_122 ;
V_105 -> V_24 -> V_2 . V_123 = & V_97 -> V_2 ;
V_19 -> V_7 = V_7 ;
V_19 -> V_2 = & V_97 -> V_2 ;
V_19 -> V_24 = V_105 ;
V_19 -> V_57 = F_51 ( V_104 ) ;
V_19 -> V_56 = V_104 -> V_111 ;
V_19 -> V_53 = F_5 ( V_19 -> V_57 , V_12 ) ;
if ( ! V_19 -> V_53 ) {
F_21 ( & V_97 -> V_2 , L_22 ) ;
error = - V_13 ;
goto V_124;
}
error = F_52 ( V_105 ) ;
if ( error ) {
F_21 ( & V_97 -> V_2 ,
L_23 ) ;
goto V_125;
}
snprintf ( V_19 -> V_126 . V_120 , sizeof( V_19 -> V_126 . V_120 ) , L_24 , V_121 ) ;
error = F_53 ( V_19 -> V_2 , & V_19 -> V_126 ) ;
if ( error ) {
F_21 ( & V_97 -> V_2 ,
L_25 ) ;
goto V_127;
}
V_19 -> V_67 = V_128 ;
V_19 -> V_67 . V_129 = V_19 ;
V_19 -> V_67 . V_114 = & V_19 -> V_114 ;
V_19 -> V_67 . V_2 = V_19 -> V_2 ;
error = F_54 ( & V_19 -> V_67 ) ;
if ( error )
goto V_127;
V_19 -> V_76 = V_130 [ 0 ] ;
V_19 -> V_131 = V_132 ;
V_19 -> V_131 . V_133 = & V_19 -> V_126 ;
V_19 -> V_131 . V_114 = & V_19 -> V_114 ;
V_19 -> V_131 . V_67 = & V_19 -> V_67 ;
F_55 ( & V_19 -> V_131 , V_19 ) ;
error = F_56 ( & V_19 -> V_131 , V_134 , - 1 ) ;
if ( error ) {
F_21 ( & V_97 -> V_2 ,
L_26 ) ;
goto V_135;
}
F_57 ( V_97 , V_19 ) ;
F_8 ( & V_97 -> V_2 , L_27 , V_136 ) ;
return 0 ;
V_135:
F_58 ( & V_19 -> V_131 ) ;
V_127:
F_59 ( & V_19 -> V_126 ) ;
V_125:
F_6 ( V_19 -> V_53 ) ;
V_124:
F_60 ( V_19 -> V_24 ) ;
V_113:
F_6 ( V_19 ) ;
return error ;
}
static void F_61 ( struct V_96 * V_97 )
{
struct V_1 * V_19 = F_62 ( V_97 ) ;
F_58 ( & V_19 -> V_131 ) ;
F_59 ( & V_19 -> V_126 ) ;
F_63 ( V_19 -> V_24 ) ;
F_60 ( V_19 -> V_24 ) ;
F_6 ( V_19 -> V_53 ) ;
F_6 ( V_19 ) ;
F_57 ( V_97 , NULL ) ;
F_8 ( & V_97 -> V_2 , L_28 , V_136 ) ;
}
static int F_64 ( struct V_137 * V_138 ,
unsigned int * V_139 , unsigned int * V_140 ,
unsigned int V_141 [] , struct V_142 * V_143 [] )
{
struct V_1 * V_19 = F_65 ( V_138 ) ;
if ( V_138 -> V_144 + * V_139 < 3 )
* V_139 = 3 - V_138 -> V_144 ;
if ( * V_140 )
return V_141 [ 0 ] < V_19 -> V_76 . V_77 ? - V_145 : 0 ;
* V_140 = 1 ;
V_141 [ 0 ] = V_19 -> V_76 . V_77 ;
return 0 ;
}
static int F_66 ( struct V_146 * V_78 )
{
struct V_1 * V_19 = F_65 ( V_78 -> V_137 ) ;
unsigned long V_6 = V_19 -> V_76 . V_77 ;
if ( F_67 ( V_78 , 0 ) < V_6 ) {
F_21 ( & V_19 -> V_7 -> V_2 , L_29 ,
F_67 ( V_78 , 0 ) , V_6 ) ;
return - V_145 ;
}
F_68 ( V_78 , 0 , V_6 ) ;
return 0 ;
}
static void F_69 ( struct V_146 * V_78 )
{
struct V_1 * V_19 = F_65 ( V_78 -> V_137 ) ;
struct V_61 * V_147 = (struct V_61 * ) V_78 ;
F_27 ( & V_19 -> V_68 ) ;
F_70 ( & V_147 -> V_71 , & V_19 -> V_69 ) ;
F_29 ( & V_19 -> V_68 ) ;
}
static void F_71 ( struct V_1 * V_19 ,
enum V_148 V_149 )
{
struct V_61 * V_147 , * V_150 ;
F_27 ( & V_19 -> V_68 ) ;
F_72 (buf, node, &sur40->buf_list, list) {
F_36 ( & V_147 -> V_78 . V_79 , V_149 ) ;
F_31 ( & V_147 -> V_71 ) ;
}
F_29 ( & V_19 -> V_68 ) ;
}
static int F_73 ( struct V_137 * V_151 , unsigned int V_58 )
{
struct V_1 * V_19 = F_65 ( V_151 ) ;
V_19 -> V_83 = 0 ;
return 0 ;
}
static void F_74 ( struct V_137 * V_151 )
{
struct V_1 * V_19 = F_65 ( V_151 ) ;
F_75 ( V_151 ) ;
V_19 -> V_83 = - 1 ;
F_71 ( V_19 , V_88 ) ;
}
static int F_76 ( struct V_152 * V_152 , void * V_153 ,
struct V_154 * V_155 )
{
struct V_1 * V_19 = F_77 ( V_152 ) ;
F_78 ( V_155 -> V_156 , V_157 , sizeof( V_155 -> V_156 ) ) ;
F_78 ( V_155 -> V_158 , V_121 , sizeof( V_155 -> V_158 ) ) ;
F_49 ( V_19 -> V_7 , V_155 -> V_159 , sizeof( V_155 -> V_159 ) ) ;
V_155 -> V_160 = V_161 | V_162 |
V_163 |
V_164 ;
V_155 -> V_165 = V_155 -> V_160 | V_166 ;
return 0 ;
}
static int F_79 ( struct V_152 * V_152 , void * V_153 ,
struct V_167 * V_48 )
{
if ( V_48 -> V_4 != 0 )
return - V_145 ;
V_48 -> type = V_168 ;
V_48 -> V_169 = V_170 ;
F_78 ( V_48 -> V_120 , L_30 , sizeof( V_48 -> V_120 ) ) ;
V_48 -> V_165 = 0 ;
return 0 ;
}
static int F_80 ( struct V_152 * V_152 , void * V_153 , unsigned int V_48 )
{
return ( V_48 == 0 ) ? 0 : - V_145 ;
}
static int F_81 ( struct V_152 * V_152 , void * V_153 , unsigned int * V_48 )
{
* V_48 = 0 ;
return 0 ;
}
static int F_82 ( struct V_152 * V_152 , void * V_153 ,
struct V_171 * V_172 )
{
switch ( V_172 -> V_173 . V_174 . V_175 ) {
case V_176 :
V_172 -> V_173 . V_174 = V_130 [ 1 ] ;
break;
default:
V_172 -> V_173 . V_174 = V_130 [ 0 ] ;
break;
}
return 0 ;
}
static int F_83 ( struct V_152 * V_152 , void * V_153 ,
struct V_171 * V_172 )
{
struct V_1 * V_19 = F_77 ( V_152 ) ;
switch ( V_172 -> V_173 . V_174 . V_175 ) {
case V_176 :
V_19 -> V_76 = V_130 [ 1 ] ;
break;
default:
V_19 -> V_76 = V_130 [ 0 ] ;
break;
}
V_172 -> V_173 . V_174 = V_19 -> V_76 ;
return 0 ;
}
static int F_84 ( struct V_152 * V_152 , void * V_153 ,
struct V_171 * V_172 )
{
struct V_1 * V_19 = F_77 ( V_152 ) ;
V_172 -> V_173 . V_174 = V_19 -> V_76 ;
return 0 ;
}
static int F_85 ( struct V_152 * V_152 , void * V_153 ,
struct V_177 * V_178 )
{
if ( V_178 -> type != V_179 )
return - V_145 ;
V_178 -> V_180 . V_181 . V_182 = V_183 ;
V_178 -> V_180 . V_181 . V_184 . V_185 = 1 ;
V_178 -> V_180 . V_181 . V_184 . V_186 = 60 ;
V_178 -> V_180 . V_181 . V_187 = 3 ;
return 0 ;
}
static int F_86 ( struct V_152 * V_152 , void * V_153 ,
struct V_188 * V_172 )
{
if ( V_172 -> V_4 >= F_87 ( V_130 ) )
return - V_145 ;
V_172 -> V_175 = V_130 [ V_172 -> V_4 ] . V_175 ;
V_172 -> V_189 = 0 ;
return 0 ;
}
static int F_88 ( struct V_152 * V_152 , void * V_153 ,
struct V_190 * V_172 )
{
struct V_1 * V_19 = F_77 ( V_152 ) ;
if ( ( V_172 -> V_4 != 0 ) || ( ( V_172 -> V_191 != V_192 )
&& ( V_172 -> V_191 != V_176 ) ) )
return - V_145 ;
V_172 -> type = V_193 ;
V_172 -> V_194 . V_195 = V_19 -> V_76 . V_195 ;
V_172 -> V_194 . V_196 = V_19 -> V_76 . V_196 ;
return 0 ;
}
static int F_89 ( struct V_152 * V_152 , void * V_153 ,
struct V_197 * V_172 )
{
struct V_1 * V_19 = F_77 ( V_152 ) ;
if ( ( V_172 -> V_4 > 0 ) || ( ( V_172 -> V_191 != V_192 )
&& ( V_172 -> V_191 != V_176 ) )
|| ( V_172 -> V_195 != V_19 -> V_76 . V_195 )
|| ( V_172 -> V_196 != V_19 -> V_76 . V_196 ) )
return - V_145 ;
V_172 -> type = V_198 ;
V_172 -> V_194 . V_186 = 60 ;
V_172 -> V_194 . V_185 = 1 ;
return 0 ;
}
