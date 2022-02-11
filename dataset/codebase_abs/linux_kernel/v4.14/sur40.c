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
int V_28 , V_29 , V_30 , V_31 , V_32 , V_33 , V_34 ;
if ( V_22 -> type != V_35 )
return;
V_34 = F_11 ( V_24 , V_22 -> V_36 ) ;
if ( V_34 < 0 || V_34 >= V_37 )
return;
V_28 = F_12 ( V_22 -> V_28 ) ;
V_29 = F_12 ( V_22 -> V_29 ) ;
V_30 = F_12 ( V_22 -> V_30 ) ;
V_31 = F_12 ( V_22 -> V_31 ) ;
V_32 = F_12 ( V_22 -> V_32 ) ;
V_33 = F_12 ( V_22 -> V_33 ) ;
F_13 ( V_24 , V_34 ) ;
F_14 ( V_24 , V_38 , 1 ) ;
V_25 = ( V_28 > V_29 ) ;
V_26 = F_15 ( V_28 , V_29 ) ;
V_27 = F_16 ( V_28 , V_29 ) ;
F_17 ( V_24 , V_39 , V_30 ) ;
F_17 ( V_24 , V_40 , V_31 ) ;
F_17 ( V_24 , V_41 , V_32 ) ;
F_17 ( V_24 , V_42 , V_33 ) ;
F_17 ( V_24 , V_43 , V_25 ) ;
F_17 ( V_24 , V_44 , V_26 ) ;
F_17 ( V_24 , V_45 , V_27 ) ;
}
static void F_18 ( struct V_17 * V_18 )
{
struct V_1 * V_19 = V_18 -> V_20 ;
struct V_23 * V_24 = V_18 -> V_24 ;
int V_11 , V_46 , V_47 , V_48 , V_49 ;
T_3 V_50 ( V_51 ) ;
struct V_52 * V_53 = & V_19 -> V_54 -> V_53 ;
struct V_21 * V_55 = & V_19 -> V_54 -> V_56 [ 0 ] ;
F_8 ( V_19 -> V_2 , L_3 ) ;
V_47 = - 1 ;
do {
V_11 = F_19 ( V_19 -> V_7 ,
F_20 ( V_19 -> V_7 , V_19 -> V_57 ) ,
V_19 -> V_54 , V_19 -> V_58 ,
& V_46 , 1000 ) ;
F_8 ( V_19 -> V_2 , L_4 , V_46 ) ;
if ( V_11 < 0 ) {
F_21 ( V_19 -> V_2 , L_5 ) ;
return;
}
V_11 = V_46 - sizeof( struct V_52 ) ;
if ( V_11 % sizeof( struct V_21 ) != 0 ) {
F_21 ( V_19 -> V_2 , L_6 ) ;
return;
}
if ( V_47 == - 1 ) {
V_47 = F_12 ( V_53 -> V_59 ) ;
F_8 ( V_19 -> V_2 , L_7 , V_47 ) ;
V_51 = F_22 ( V_53 -> V_51 ) ;
}
V_48 = V_11 / sizeof( struct V_21 ) ;
F_8 ( V_19 -> V_2 , L_8 , V_48 ) ;
if ( V_48 > V_47 )
V_48 = V_47 ;
for ( V_49 = 0 ; V_49 < V_48 ; V_49 ++ ) {
V_47 -- ;
F_8 ( V_19 -> V_2 , L_9 ) ;
F_10 ( & ( V_55 [ V_49 ] ) , V_24 ) ;
}
} while ( V_47 > 0 );
F_23 ( V_24 ) ;
F_24 ( V_24 ) ;
F_25 ( V_19 ) ;
}
static void F_25 ( struct V_1 * V_19 )
{
struct V_60 * V_61 = ( void * ) ( V_19 -> V_54 ) ;
struct V_62 * V_63 ;
struct V_64 V_65 ;
struct V_66 * V_67 ;
int V_11 , V_46 ;
if ( ! F_26 ( & V_19 -> V_68 ) )
return;
F_27 ( & V_19 -> V_69 ) ;
if ( F_28 ( & V_19 -> V_70 ) ) {
F_8 ( V_19 -> V_2 , L_10 ) ;
F_29 ( & V_19 -> V_69 ) ;
return;
}
V_63 = F_30 ( V_19 -> V_70 . V_71 , struct V_62 , V_72 ) ;
F_31 ( & V_63 -> V_72 ) ;
F_29 ( & V_19 -> V_69 ) ;
F_8 ( V_19 -> V_2 , L_11 ) ;
V_11 = F_19 ( V_19 -> V_7 ,
F_20 ( V_19 -> V_7 , V_73 ) ,
V_19 -> V_54 , V_19 -> V_58 ,
& V_46 , 1000 ) ;
if ( V_11 < 0 ) {
F_21 ( V_19 -> V_2 , L_5 ) ;
goto V_74;
}
if ( V_46 != sizeof( struct V_60 ) ) {
F_21 ( V_19 -> V_2 , L_12 ,
V_46 , sizeof( struct V_60 ) ) ;
goto V_74;
}
if ( F_22 ( V_61 -> V_75 ) != V_76 ) {
F_21 ( V_19 -> V_2 , L_13 ) ;
goto V_74;
}
if ( F_22 ( V_61 -> V_6 ) != V_19 -> V_77 . V_78 ) {
F_21 ( V_19 -> V_2 , L_14 ) ;
goto V_74;
}
F_8 ( V_19 -> V_2 , L_15 ) ;
V_67 = F_32 ( & V_63 -> V_79 . V_80 , 0 ) ;
V_11 = F_33 ( & V_65 , V_19 -> V_7 ,
F_20 ( V_19 -> V_7 , V_73 ) , 0 ,
V_67 -> V_81 , V_67 -> V_82 , V_19 -> V_77 . V_78 , 0 ) ;
if ( V_11 < 0 ) {
F_21 ( V_19 -> V_2 , L_16 , V_11 ) ;
goto V_74;
}
F_34 ( & V_65 ) ;
if ( V_65 . V_83 < 0 ) {
F_21 ( V_19 -> V_2 , L_17 , V_65 . V_83 ) ;
goto V_74;
}
F_8 ( V_19 -> V_2 , L_18 ) ;
if ( V_19 -> V_84 == - 1 )
return;
V_63 -> V_79 . V_80 . V_85 = F_35 () ;
V_63 -> V_79 . V_84 = V_19 -> V_84 ++ ;
V_63 -> V_79 . V_86 = V_87 ;
F_36 ( & V_63 -> V_79 . V_80 , V_88 ) ;
F_8 ( V_19 -> V_2 , L_19 ) ;
return;
V_74:
F_36 ( & V_63 -> V_79 . V_80 , V_89 ) ;
}
static void F_37 ( struct V_23 * V_23 )
{
F_38 ( V_90 , V_23 -> V_91 ) ;
F_38 ( V_92 , V_23 -> V_91 ) ;
F_39 ( V_23 , V_39 ,
0 , V_93 , 0 , 0 ) ;
F_39 ( V_23 , V_40 ,
0 , V_94 , 0 , 0 ) ;
F_39 ( V_23 , V_41 ,
0 , V_93 , 0 , 0 ) ;
F_39 ( V_23 , V_42 ,
0 , V_94 , 0 , 0 ) ;
F_39 ( V_23 , V_44 ,
0 , V_93 , 0 , 0 ) ;
F_39 ( V_23 , V_45 ,
0 , V_94 , 0 , 0 ) ;
F_39 ( V_23 , V_43 , 0 , 1 , 0 , 0 ) ;
F_40 ( V_23 , V_37 ,
V_95 | V_96 ) ;
}
static int F_41 ( struct V_97 * V_98 ,
const struct V_99 * V_100 )
{
struct V_101 * V_7 = F_42 ( V_98 ) ;
struct V_1 * V_19 ;
struct V_102 * V_103 ;
struct V_104 * V_105 ;
struct V_17 * V_106 ;
int error ;
V_103 = & V_98 -> V_107 [ 0 ] ;
if ( V_103 -> V_108 . V_109 != 0xFF )
return - V_110 ;
if ( V_103 -> V_108 . V_111 < 5 )
return - V_110 ;
V_105 = & V_103 -> V_105 [ 4 ] . V_108 ;
if ( V_105 -> V_112 != V_113 )
return - V_110 ;
V_19 = F_43 ( sizeof( struct V_1 ) , V_12 ) ;
if ( ! V_19 )
return - V_13 ;
V_106 = F_44 () ;
if ( ! V_106 ) {
error = - V_13 ;
goto V_114;
}
F_45 ( & V_19 -> V_70 ) ;
F_46 ( & V_19 -> V_69 ) ;
F_47 ( & V_19 -> V_115 ) ;
V_106 -> V_20 = V_19 ;
V_106 -> V_116 = V_117 ;
V_106 -> V_118 = F_7 ;
V_106 -> V_119 = F_18 ;
V_106 -> V_120 = F_9 ;
F_37 ( V_106 -> V_24 ) ;
V_106 -> V_24 -> V_121 = V_122 ;
F_48 ( V_7 , & V_106 -> V_24 -> V_100 ) ;
F_49 ( V_7 , V_19 -> V_123 , sizeof( V_19 -> V_123 ) ) ;
F_50 ( V_19 -> V_123 , L_20 , sizeof( V_19 -> V_123 ) ) ;
V_106 -> V_24 -> V_123 = V_19 -> V_123 ;
V_106 -> V_24 -> V_2 . V_124 = & V_98 -> V_2 ;
V_19 -> V_7 = V_7 ;
V_19 -> V_2 = & V_98 -> V_2 ;
V_19 -> V_24 = V_106 ;
V_19 -> V_58 = F_51 ( V_105 ) ;
V_19 -> V_57 = V_105 -> V_112 ;
V_19 -> V_54 = F_5 ( V_19 -> V_58 , V_12 ) ;
if ( ! V_19 -> V_54 ) {
F_21 ( & V_98 -> V_2 , L_21 ) ;
error = - V_13 ;
goto V_125;
}
error = F_52 ( V_106 ) ;
if ( error ) {
F_21 ( & V_98 -> V_2 ,
L_22 ) ;
goto V_126;
}
snprintf ( V_19 -> V_127 . V_121 , sizeof( V_19 -> V_127 . V_121 ) , L_23 , V_122 ) ;
error = F_53 ( V_19 -> V_2 , & V_19 -> V_127 ) ;
if ( error ) {
F_21 ( & V_98 -> V_2 ,
L_24 ) ;
goto V_128;
}
V_19 -> V_68 = V_129 ;
V_19 -> V_68 . V_130 = V_19 ;
V_19 -> V_68 . V_115 = & V_19 -> V_115 ;
V_19 -> V_68 . V_2 = V_19 -> V_2 ;
error = F_54 ( & V_19 -> V_68 ) ;
if ( error )
goto V_128;
V_19 -> V_77 = V_131 [ 0 ] ;
V_19 -> V_132 = V_133 ;
V_19 -> V_132 . V_134 = & V_19 -> V_127 ;
V_19 -> V_132 . V_115 = & V_19 -> V_115 ;
V_19 -> V_132 . V_68 = & V_19 -> V_68 ;
F_55 ( & V_19 -> V_132 , V_19 ) ;
error = F_56 ( & V_19 -> V_132 , V_135 , - 1 ) ;
if ( error ) {
F_21 ( & V_98 -> V_2 ,
L_25 ) ;
goto V_136;
}
F_57 ( V_98 , V_19 ) ;
F_8 ( & V_98 -> V_2 , L_26 , V_137 ) ;
return 0 ;
V_136:
F_58 ( & V_19 -> V_132 ) ;
V_128:
F_59 ( & V_19 -> V_127 ) ;
V_126:
F_6 ( V_19 -> V_54 ) ;
V_125:
F_60 ( V_19 -> V_24 ) ;
V_114:
F_6 ( V_19 ) ;
return error ;
}
static void F_61 ( struct V_97 * V_98 )
{
struct V_1 * V_19 = F_62 ( V_98 ) ;
F_58 ( & V_19 -> V_132 ) ;
F_59 ( & V_19 -> V_127 ) ;
F_63 ( V_19 -> V_24 ) ;
F_60 ( V_19 -> V_24 ) ;
F_6 ( V_19 -> V_54 ) ;
F_6 ( V_19 ) ;
F_57 ( V_98 , NULL ) ;
F_8 ( & V_98 -> V_2 , L_27 , V_137 ) ;
}
static int F_64 ( struct V_138 * V_139 ,
unsigned int * V_140 , unsigned int * V_141 ,
unsigned int V_142 [] , struct V_143 * V_144 [] )
{
struct V_1 * V_19 = F_65 ( V_139 ) ;
if ( V_139 -> V_145 + * V_140 < 3 )
* V_140 = 3 - V_139 -> V_145 ;
if ( * V_141 )
return V_142 [ 0 ] < V_19 -> V_77 . V_78 ? - V_146 : 0 ;
* V_141 = 1 ;
V_142 [ 0 ] = V_19 -> V_77 . V_78 ;
return 0 ;
}
static int F_66 ( struct V_147 * V_79 )
{
struct V_1 * V_19 = F_65 ( V_79 -> V_138 ) ;
unsigned long V_6 = V_19 -> V_77 . V_78 ;
if ( F_67 ( V_79 , 0 ) < V_6 ) {
F_21 ( & V_19 -> V_7 -> V_2 , L_28 ,
F_67 ( V_79 , 0 ) , V_6 ) ;
return - V_146 ;
}
F_68 ( V_79 , 0 , V_6 ) ;
return 0 ;
}
static void F_69 ( struct V_147 * V_79 )
{
struct V_1 * V_19 = F_65 ( V_79 -> V_138 ) ;
struct V_62 * V_148 = (struct V_62 * ) V_79 ;
F_27 ( & V_19 -> V_69 ) ;
F_70 ( & V_148 -> V_72 , & V_19 -> V_70 ) ;
F_29 ( & V_19 -> V_69 ) ;
}
static void F_71 ( struct V_1 * V_19 ,
enum V_149 V_150 )
{
struct V_62 * V_148 , * V_151 ;
F_27 ( & V_19 -> V_69 ) ;
F_72 (buf, node, &sur40->buf_list, list) {
F_36 ( & V_148 -> V_79 . V_80 , V_150 ) ;
F_31 ( & V_148 -> V_72 ) ;
}
F_29 ( & V_19 -> V_69 ) ;
}
static int F_73 ( struct V_138 * V_152 , unsigned int V_59 )
{
struct V_1 * V_19 = F_65 ( V_152 ) ;
V_19 -> V_84 = 0 ;
return 0 ;
}
static void F_74 ( struct V_138 * V_152 )
{
struct V_1 * V_19 = F_65 ( V_152 ) ;
F_75 ( V_152 ) ;
V_19 -> V_84 = - 1 ;
F_71 ( V_19 , V_89 ) ;
}
static int F_76 ( struct V_153 * V_153 , void * V_154 ,
struct V_155 * V_156 )
{
struct V_1 * V_19 = F_77 ( V_153 ) ;
F_78 ( V_156 -> V_157 , V_158 , sizeof( V_156 -> V_157 ) ) ;
F_78 ( V_156 -> V_159 , V_122 , sizeof( V_156 -> V_159 ) ) ;
F_49 ( V_19 -> V_7 , V_156 -> V_160 , sizeof( V_156 -> V_160 ) ) ;
V_156 -> V_161 = V_162 | V_163 |
V_164 |
V_165 ;
V_156 -> V_166 = V_156 -> V_161 | V_167 ;
return 0 ;
}
static int F_79 ( struct V_153 * V_153 , void * V_154 ,
struct V_168 * V_49 )
{
if ( V_49 -> V_4 != 0 )
return - V_146 ;
V_49 -> type = V_169 ;
V_49 -> V_170 = V_171 ;
F_78 ( V_49 -> V_121 , L_29 , sizeof( V_49 -> V_121 ) ) ;
V_49 -> V_166 = 0 ;
return 0 ;
}
static int F_80 ( struct V_153 * V_153 , void * V_154 , unsigned int V_49 )
{
return ( V_49 == 0 ) ? 0 : - V_146 ;
}
static int F_81 ( struct V_153 * V_153 , void * V_154 , unsigned int * V_49 )
{
* V_49 = 0 ;
return 0 ;
}
static int F_82 ( struct V_153 * V_153 , void * V_154 ,
struct V_172 * V_173 )
{
switch ( V_173 -> V_174 . V_175 . V_176 ) {
case V_177 :
V_173 -> V_174 . V_175 = V_131 [ 1 ] ;
break;
default:
V_173 -> V_174 . V_175 = V_131 [ 0 ] ;
break;
}
return 0 ;
}
static int F_83 ( struct V_153 * V_153 , void * V_154 ,
struct V_172 * V_173 )
{
struct V_1 * V_19 = F_77 ( V_153 ) ;
switch ( V_173 -> V_174 . V_175 . V_176 ) {
case V_177 :
V_19 -> V_77 = V_131 [ 1 ] ;
break;
default:
V_19 -> V_77 = V_131 [ 0 ] ;
break;
}
V_173 -> V_174 . V_175 = V_19 -> V_77 ;
return 0 ;
}
static int F_84 ( struct V_153 * V_153 , void * V_154 ,
struct V_172 * V_173 )
{
struct V_1 * V_19 = F_77 ( V_153 ) ;
V_173 -> V_174 . V_175 = V_19 -> V_77 ;
return 0 ;
}
static int F_85 ( struct V_153 * V_153 , void * V_154 ,
struct V_178 * V_179 )
{
if ( V_179 -> type != V_180 )
return - V_146 ;
V_179 -> V_181 . V_182 . V_183 = V_184 ;
V_179 -> V_181 . V_182 . V_185 . V_186 = 1 ;
V_179 -> V_181 . V_182 . V_185 . V_187 = 60 ;
V_179 -> V_181 . V_182 . V_188 = 3 ;
return 0 ;
}
static int F_86 ( struct V_153 * V_153 , void * V_154 ,
struct V_189 * V_173 )
{
if ( V_173 -> V_4 >= F_87 ( V_131 ) )
return - V_146 ;
V_173 -> V_176 = V_131 [ V_173 -> V_4 ] . V_176 ;
V_173 -> V_190 = 0 ;
return 0 ;
}
static int F_88 ( struct V_153 * V_153 , void * V_154 ,
struct V_191 * V_173 )
{
struct V_1 * V_19 = F_77 ( V_153 ) ;
if ( ( V_173 -> V_4 != 0 ) || ( ( V_173 -> V_192 != V_193 )
&& ( V_173 -> V_192 != V_177 ) ) )
return - V_146 ;
V_173 -> type = V_194 ;
V_173 -> V_195 . V_196 = V_19 -> V_77 . V_196 ;
V_173 -> V_195 . V_197 = V_19 -> V_77 . V_197 ;
return 0 ;
}
static int F_89 ( struct V_153 * V_153 , void * V_154 ,
struct V_198 * V_173 )
{
struct V_1 * V_19 = F_77 ( V_153 ) ;
if ( ( V_173 -> V_4 > 0 ) || ( ( V_173 -> V_192 != V_193 )
&& ( V_173 -> V_192 != V_177 ) )
|| ( V_173 -> V_196 != V_19 -> V_77 . V_196 )
|| ( V_173 -> V_197 != V_19 -> V_77 . V_197 ) )
return - V_146 ;
V_173 -> type = V_199 ;
V_173 -> V_195 . V_187 = 60 ;
V_173 -> V_195 . V_186 = 1 ;
return 0 ;
}
