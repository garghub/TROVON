struct V_1 * F_1 ( struct V_2 * V_3 ,
T_1 V_4 ,
T_1 V_5 ,
T_2 V_6 )
{
struct V_7 * V_8 ;
struct V_9 * V_10 ;
struct V_1 * V_11 ;
struct V_12 * V_13 ;
struct V_14 * V_15 ;
struct V_16 * V_17 ;
struct V_18 * V_19 ;
F_2 ( V_20 , L_1 ) ;
if ( ! V_3 ) {
F_2 ( V_21 , L_2 ) ;
return NULL ;
}
V_10 = V_3 -> V_22 ;
V_13 = V_10 -> V_13 ;
V_8 = V_13 -> V_8 ;
if ( V_4 > V_10 -> V_13 -> V_23 . V_24 ) {
F_3 ( V_25 , V_8 , L_3
L_4
L_5 , V_4 ,
V_10 -> V_13 -> V_23 . V_24 ,
V_10 -> V_13 -> V_23 . V_24 ) ;
V_4 = V_10 -> V_13 -> V_23 . V_24 ;
}
V_11 = F_4 ( & V_26 ,
V_8 , V_4 ,
sizeof( * V_17 ) ,
sizeof( * V_19 ) ,
V_6 , V_27 ) ;
if ( ! V_11 )
return NULL ;
V_15 = V_11 -> V_22 ;
V_17 = V_15 -> V_22 ;
V_17 -> V_28 = F_5 ( L_6 ,
V_13 -> V_29 ,
sizeof( struct V_30 ) ,
64 , 0 ) ;
if ( ! V_17 -> V_28 )
goto V_31;
return V_11 ;
V_31:
F_6 ( V_11 ) ;
return NULL ;
}
void F_7 ( struct V_1 * V_11 )
{
struct V_14 * V_15 = V_11 -> V_22 ;
struct V_16 * V_17 = V_15 -> V_22 ;
F_2 ( V_20 , L_7 ) ;
F_8 ( V_17 -> V_28 ) ;
F_6 ( V_11 ) ;
}
struct V_32 *
F_9 ( struct V_1 * V_11 , T_2 V_33 )
{
struct V_12 * V_13 ;
struct V_7 * V_8 ;
struct V_32 * V_34 ;
struct V_35 * V_35 ;
struct V_36 * V_37 ;
struct V_14 * V_15 ;
struct V_16 * V_17 ;
F_2 ( V_20 , L_8
L_9 , V_33 ) ;
V_8 = F_10 ( V_11 ) ;
V_13 = F_11 ( V_8 ) ;
V_34 = F_12 ( V_11 , sizeof( * V_35 ) , V_33 ) ;
if ( ! V_34 )
return NULL ;
V_37 = V_34 -> V_22 ;
V_35 = V_37 -> V_22 ;
V_35 -> V_3 = NULL ;
V_35 -> V_13 = V_13 ;
V_35 -> V_37 = V_37 ;
V_15 = V_11 -> V_22 ;
V_17 = V_15 -> V_22 ;
V_35 -> V_17 = V_17 ;
return V_34 ;
}
static int F_13 ( struct V_12 * V_13 ,
struct V_35 * V_35 ,
unsigned int V_33 )
{
if ( V_13 -> V_38 [ V_33 ] ) {
F_2 ( V_21 ,
L_10 ) ;
return - V_39 ;
} else {
F_2 ( V_20 , L_11 ,
V_33 , V_35 ) ;
V_13 -> V_38 [ V_33 ] = V_35 ;
}
return 0 ;
}
int F_14 ( struct V_1 * V_11 ,
struct V_32 * V_34 ,
T_3 V_40 , int V_41 )
{
struct V_36 * V_37 = V_34 -> V_22 ;
struct V_35 * V_35 = V_37 -> V_22 ;
struct V_7 * V_8 = F_10 ( V_11 ) ;
struct V_12 * V_13 = F_11 ( V_8 ) ;
struct V_9 * V_10 ;
struct V_2 * V_3 ;
F_2 ( V_20 , L_12 ) ;
V_3 = F_15 ( V_40 ) ;
if ( ! V_3 )
return - V_39 ;
V_10 = V_3 -> V_22 ;
if ( F_16 ( V_11 , V_34 , V_41 ) )
return - V_39 ;
if ( V_10 -> V_13 != V_13 ) {
F_2 ( V_20 ,
L_13 ,
V_10 -> V_13 , V_13 ) ;
return - V_42 ;
}
V_35 -> V_43 = V_10 -> V_44 ;
V_35 -> V_3 = V_10 ;
V_10 -> V_37 = V_35 ;
F_2 ( V_20 , L_14 ,
V_35 , V_37 , V_10 -> V_44 ) ;
return F_13 ( V_13 , V_35 , V_10 -> V_44 ) ;
}
static int F_17 ( struct V_12 * V_13 )
{
if ( V_13 -> V_45 )
return 0 ;
V_13 -> V_45 = F_18 ( V_13 -> V_8 ,
& V_26 ,
V_46 ,
0 , 0 ) ;
if ( ! V_13 -> V_45 ) {
F_3 ( V_25 , V_13 -> V_8 , L_15
L_16 ) ;
return - V_47 ;
}
return 0 ;
}
static int F_19 ( struct V_12 * V_13 )
{
if ( V_13 -> V_48 )
return 0 ;
V_13 -> V_48 = F_18 ( V_13 -> V_8 ,
& V_26 ,
V_49 ,
0 , 0 ) ;
if ( ! V_13 -> V_48 ) {
F_3 ( V_25 , V_13 -> V_8 , L_15
L_17 ) ;
return - V_47 ;
}
return 0 ;
}
void F_20 ( struct V_12 * V_13 )
{
struct V_50 V_51 ;
if ( ! F_21 ( V_13 , V_52 , & V_51 ) )
F_17 ( V_13 ) ;
if ( ! F_21 ( V_13 , V_53 , & V_51 ) )
F_19 ( V_13 ) ;
}
void F_22 ( struct V_12 * V_13 )
{
if ( V_13 -> V_48 )
F_23 ( V_13 -> V_48 ) ;
if ( V_13 -> V_45 )
F_23 ( V_13 -> V_45 ) ;
}
static int
F_24 ( struct V_7 * V_8 ,
struct V_54 * V_55 ,
void * V_56 , T_4 V_57 )
{
struct V_12 * V_13 = F_11 ( V_8 ) ;
struct V_54 * V_58 = NULL ;
struct V_54 * V_59 = NULL ;
struct V_60 * V_61 ;
int V_62 ;
switch ( V_55 -> V_63 ) {
case V_64 :
V_61 = F_25 ( V_56 , V_57 , V_65 ) ;
if ( V_61 )
V_58 = F_26 ( V_61 ) ;
V_61 = F_25 ( V_56 , V_57 , V_66 ) ;
if ( V_61 )
V_59 = F_26 ( V_61 ) ;
break;
case V_65 :
V_58 = V_55 ;
V_61 = F_25 ( V_56 , V_57 , V_66 ) ;
if ( V_61 )
V_59 = F_26 ( V_61 ) ;
break;
case V_66 :
V_59 = V_55 ;
V_61 = F_25 ( V_56 , V_57 , V_65 ) ;
if ( V_61 )
V_58 = F_26 ( V_61 ) ;
break;
default:
F_3 ( V_25 , V_8 , L_18 ,
V_55 -> V_63 ) ;
}
if ( ! V_58 || ! V_59 ) {
F_3 ( V_25 , V_8 , L_19 ) ;
return - V_39 ;
}
V_62 = F_27 ( V_13 , V_58 , V_59 ,
V_67 ) ;
return V_62 ;
}
static int
F_28 ( struct V_7 * V_8 ,
struct V_54 * V_55 ,
void * V_56 , T_4 V_57 )
{
struct V_12 * V_13 = F_11 ( V_8 ) ;
int V_62 = 0 ;
switch ( V_55 -> V_63 ) {
case V_68 :
V_62 = F_29 ( V_13 , V_55 ) ;
break;
case V_64 :
if ( V_55 -> V_69 [ 0 ] == V_70 )
V_62 = F_27 ( V_13 , V_55 ,
NULL , V_70 ) ;
else if ( V_55 -> V_69 [ 0 ] == V_67 )
V_62 = F_24 ( V_8 , V_55 ,
V_56 , V_57 ) ;
else
F_3 ( V_25 , V_8 , L_20 ,
V_55 -> V_69 [ 0 ] ) ;
break;
case V_71 :
if ( V_55 -> V_69 [ 0 ] == V_72 )
V_62 = F_17 ( V_13 ) ;
else
F_23 ( V_13 -> V_45 ) ;
break;
case V_66 :
case V_65 :
V_62 = F_24 ( V_8 , V_55 ,
V_56 , V_57 ) ;
break;
default:
F_3 ( V_25 , V_8 , L_21 ,
V_55 -> V_63 ) ;
}
return V_62 ;
}
static int
F_30 ( struct V_7 * V_8 ,
struct V_54 * V_55 ,
void * V_56 , T_4 V_57 )
{
struct V_12 * V_13 = F_11 ( V_8 ) ;
int V_62 = 0 ;
switch ( V_55 -> V_63 ) {
case V_71 :
if ( V_55 -> V_69 [ 0 ] == V_72 )
V_62 = F_19 ( V_13 ) ;
else {
F_23 ( V_13 -> V_48 ) ;
V_62 = 0 ;
}
break;
case V_73 :
V_62 = F_27 ( V_13 , V_55 , NULL ,
V_67 ) ;
break;
default:
F_3 ( V_25 , V_8 , L_21 ,
V_55 -> V_63 ) ;
}
return V_62 ;
}
int F_31 ( struct V_7 * V_8 ,
void * V_56 , T_4 V_57 )
{
struct V_54 * V_55 = NULL ;
struct V_60 * V_74 ;
T_4 V_75 = V_57 ;
int V_62 = 0 ;
F_32 (attrib, data, dt_len, rm_len) {
V_55 = F_26 ( V_74 ) ;
if ( V_55 -> V_76 != V_77 )
continue;
if ( V_55 -> V_78 ) {
F_3 ( V_25 , V_8 , L_22
L_23 ,
V_55 -> V_78 ) ;
return - V_39 ;
}
switch ( V_55 -> V_79 ) {
case V_46 :
V_62 = F_28 ( V_8 , V_55 ,
V_56 , V_57 ) ;
break;
case V_49 :
V_62 = F_30 ( V_8 , V_55 ,
V_56 , V_57 ) ;
break;
default:
F_3 ( V_25 , V_8 ,
L_24 ,
V_55 -> V_79 ) ;
break;
}
if ( V_62 )
return V_62 ;
}
return V_62 ;
}
static int F_33 ( struct V_12 * V_13 ,
struct V_80 * V_81 , int V_63 ,
char * V_82 )
{
struct V_50 V_51 ;
int V_83 , V_84 = V_52 ;
memset ( & V_51 , 0 , sizeof( V_51 ) ) ;
if ( V_81 -> V_79 == V_49 )
V_84 = V_53 ;
V_83 = F_21 ( V_13 , V_84 , & V_51 ) ;
if ( V_83 )
return V_83 ;
switch ( V_63 ) {
case V_65 :
V_83 = sprintf ( V_82 , L_25 , & V_51 . V_85 . V_86 ) ;
break;
case V_73 :
V_83 = sprintf ( V_82 , L_26 , & V_51 . V_85 . V_86 ) ;
break;
case V_64 :
if ( ! V_51 . V_87 )
V_83 = sprintf ( V_82 , L_27 ) ;
else
V_83 = sprintf ( V_82 , L_28 ) ;
break;
case V_66 :
V_83 = sprintf ( V_82 , L_25 , & V_51 . V_85 . V_88 ) ;
break;
default:
F_34 ( 1 ) ;
}
return V_83 ;
}
int F_35 ( struct V_80 * V_81 ,
enum V_89 V_76 ,
int V_63 , char * V_82 )
{
struct V_7 * V_8 = F_36 ( V_81 ) ;
struct V_12 * V_13 = F_11 ( V_8 ) ;
struct V_90 V_91 ;
int V_83 = - V_92 ;
switch ( V_63 ) {
case V_65 :
case V_66 :
case V_64 :
case V_73 :
V_83 = F_33 ( V_13 , V_81 , V_63 , V_82 ) ;
break;
case V_71 :
V_83 = sprintf ( V_82 , L_29 ) ;
break;
case V_68 :
memset ( & V_91 , 0 , sizeof( V_91 ) ) ;
V_83 = F_37 ( V_13 , V_52 , & V_91 ) ;
if ( ! V_83 )
V_83 = sprintf ( V_82 , L_25 , & V_91 . V_85 . V_86 ) ;
break;
default:
V_83 = - V_92 ;
}
return V_83 ;
}
int F_38 ( struct V_2 * V_3 ,
enum V_93 V_63 , char * V_82 )
{
struct V_9 * V_10 = V_3 -> V_22 ;
int V_83 = 0 ;
F_2 ( V_20 , L_30 , V_63 ) ;
switch ( V_63 ) {
case V_94 :
V_83 = sprintf ( V_82 , L_31 , V_10 -> V_95 ) ;
break;
case V_96 :
if ( V_10 -> V_84 == V_52 )
V_83 = sprintf ( V_82 , L_25 , & V_10 -> V_97 ) ;
else
V_83 = sprintf ( V_82 , L_26 , & V_10 -> V_98 ) ;
break;
default:
return - V_92 ;
}
return V_83 ;
}
int F_39 ( struct V_32 * V_34 ,
enum V_93 V_63 , char * V_82 , int V_99 )
{
struct V_36 * V_37 = V_34 -> V_22 ;
struct V_14 * V_100 = V_37 -> V_100 ;
int V_62 ;
F_2 ( V_20 , L_32 , V_63 ) ;
V_62 = F_40 ( V_34 , V_63 , V_82 , V_99 ) ;
if ( V_62 )
return V_62 ;
switch ( V_63 ) {
case V_101 :
if ( V_100 -> V_102 > 8192 )
V_100 -> V_102 = 8192 ;
break;
case V_103 :
if ( V_37 -> V_104 > 65536 )
V_37 -> V_104 = 65536 ;
break;
case V_105 :
if ( V_100 -> V_106 > 262144 )
V_100 -> V_106 = 262144 ;
break;
case V_107 :
if ( ( V_37 -> V_108 > 65536 ) ||
( V_37 -> V_108 == 0 ) )
V_37 -> V_108 = 65536 ;
default:
return 0 ;
}
return 0 ;
}
static int F_41 ( char * V_82 , struct V_12 * V_13 )
{
int V_109 ;
unsigned int V_110 , V_111 ;
unsigned short V_112 , V_113 ;
struct V_114 * V_115 ;
struct V_116 * V_117 ;
struct V_118 * V_119 = & V_13 -> V_120 . V_121 . V_122 ;
V_110 = F_42 ( V_13 ) ;
if ( ! V_110 ) {
F_2 ( V_21 , L_33 ) ;
return - V_123 ;
} else
F_43 ( V_13 -> V_120 . V_124 [ V_110 ] ,
V_13 -> V_120 . V_125 [ V_110 ] ) ;
V_111 = ( V_13 -> V_120 . V_125 [ V_110 ] & 0x00FF0000 ) >> 16 ;
V_113 = ( V_13 -> V_120 . V_125 [ V_110 ] & 0x0000FF00 ) >> 8 ;
V_112 = V_13 -> V_120 . V_125 [ V_110 ] & 0x000000FF ;
if ( V_112 || V_113 ) {
F_2 ( V_21 , L_34
L_35 ,
V_112 , V_113 ) ;
F_44 ( & V_13 -> V_120 , V_110 ) ;
return - V_126 ;
}
V_115 = F_45 ( V_119 , V_111 ) ;
F_44 ( & V_13 -> V_120 , V_110 ) ;
V_117 = F_46 ( V_115 ) ;
V_109 = sprintf ( V_82 , L_36 , V_117 -> V_127 ) ;
return V_109 ;
}
static void F_47 ( struct V_7 * V_8 )
{
struct V_12 * V_13 = F_11 ( V_8 ) ;
struct V_128 * V_129 = V_8 -> V_130 ;
V_129 -> V_131 = ( V_13 -> V_132 == V_133 ) ?
V_134 : V_135 ;
}
static int F_48 ( struct V_7 * V_8 )
{
unsigned int V_110 , V_111 ;
unsigned short V_112 , V_113 ;
struct V_114 * V_115 ;
struct V_136 * V_117 ;
struct V_12 * V_13 = F_11 ( V_8 ) ;
struct V_128 * V_129 = V_8 -> V_130 ;
struct V_118 * V_119 = & V_13 -> V_120 . V_121 . V_122 ;
V_110 = F_49 ( V_13 ) ;
if ( ! V_110 ) {
F_2 ( V_21 , L_37 ) ;
return - V_123 ;
} else
F_43 ( V_13 -> V_120 . V_124 [ V_110 ] ,
V_13 -> V_120 . V_125 [ V_110 ] ) ;
V_111 = ( V_13 -> V_120 . V_125 [ V_110 ] & 0x00FF0000 ) >> 16 ;
V_113 = ( V_13 -> V_120 . V_125 [ V_110 ] & 0x0000FF00 ) >> 8 ;
V_112 = V_13 -> V_120 . V_125 [ V_110 ] & 0x000000FF ;
if ( V_112 || V_113 ) {
F_2 ( V_21 , L_34
L_35 ,
V_112 , V_113 ) ;
F_44 ( & V_13 -> V_120 , V_110 ) ;
return - V_126 ;
}
V_115 = F_45 ( V_119 , V_111 ) ;
F_44 ( & V_13 -> V_120 , V_110 ) ;
V_117 = F_46 ( V_115 ) ;
switch ( V_117 -> V_137 ) {
case V_138 :
V_129 -> V_139 = V_140 ;
break;
case V_141 :
V_129 -> V_139 = V_141 ;
break;
case V_142 :
V_129 -> V_139 = V_143 ;
break;
case V_144 :
V_129 -> V_139 = V_145 ;
break;
default:
V_129 -> V_139 = V_146 ;
}
return 0 ;
}
int F_50 ( struct V_7 * V_8 ,
enum V_147 V_63 , char * V_82 )
{
struct V_12 * V_13 = F_11 ( V_8 ) ;
int V_112 = 0 ;
F_2 ( V_20 , L_38 , V_63 ) ;
switch ( V_63 ) {
case V_148 :
V_112 = F_51 ( V_82 , V_13 ) ;
if ( V_112 < 0 ) {
F_2 ( V_21 , L_39 ) ;
return V_112 ;
}
break;
case V_149 :
V_112 = F_41 ( V_82 , V_13 ) ;
if ( V_112 < 0 ) {
F_2 ( V_21 ,
L_40 ) ;
return V_112 ;
}
break;
case V_150 :
F_47 ( V_8 ) ;
V_112 = sprintf ( V_82 , L_36 , F_52 ( V_8 ) ) ;
break;
case V_151 :
V_112 = F_48 ( V_8 ) ;
if ( V_112 ) {
F_2 ( V_21 ,
L_41 ) ;
return V_112 ;
}
V_112 = sprintf ( V_82 , L_36 , F_53 ( V_8 ) ) ;
break;
default:
return F_54 ( V_8 , V_63 , V_82 ) ;
}
return V_112 ;
}
int F_51 ( char * V_82 , struct V_12 * V_13 )
{
struct V_152 V_117 ;
int V_109 ;
if ( strlen ( V_13 -> V_153 ) )
return F_55 ( V_82 , V_13 -> V_153 , V_154 ) ;
memset ( & V_117 , 0 , sizeof( V_117 ) ) ;
V_109 = F_56 ( V_13 , & V_117 ) ;
if ( V_109 )
return V_109 ;
memcpy ( V_13 -> V_153 , V_117 . V_153 , V_155 ) ;
return F_57 ( V_82 , V_13 -> V_153 , V_155 ) ;
}
void F_58 ( struct V_32 * V_34 ,
struct V_156 * V_157 )
{
struct V_36 * V_37 = V_34 -> V_22 ;
F_2 ( V_20 , L_42 ) ;
V_157 -> V_158 = V_37 -> V_158 ;
V_157 -> V_159 = V_37 -> V_159 ;
V_157 -> V_160 = V_37 -> V_161 ;
V_157 -> V_162 = V_37 -> V_163 ;
V_157 -> V_164 = V_37 -> V_165 ;
V_157 -> V_166 = V_37 -> V_167 ;
V_157 -> V_168 = V_37 -> V_169 ;
V_157 -> V_170 = V_37 -> V_171 ;
V_157 -> V_172 = V_37 -> V_173 ;
V_157 -> V_174 = 0 ;
V_157 -> V_175 = 0 ;
V_157 -> V_176 = 0 ;
strcpy ( V_157 -> V_177 [ 0 ] . V_178 , L_43 ) ;
V_157 -> V_177 [ 0 ] . V_69 = V_37 -> V_179 ;
}
static void F_59 ( struct V_35 * V_35 ,
struct V_180 * V_23 )
{
struct V_36 * V_37 = V_35 -> V_37 ;
struct V_14 * V_100 = V_37 -> V_100 ;
F_60 ( struct V_181 , V_182 ,
V_23 , V_100 -> V_106 ) ;
F_60 ( struct V_181 ,
V_183 , V_23 ,
V_37 -> V_108 ) ;
F_60 ( struct V_181 , V_184 ,
V_23 , V_100 -> V_102 ) ;
F_60 ( struct V_181 , V_185 , V_23 ,
V_100 -> V_185 ) ;
F_60 ( struct V_181 , V_186 , V_23 ,
V_37 -> V_187 ) ;
F_60 ( struct V_181 , V_188 , V_23 ,
V_37 -> V_189 ) ;
F_60 ( struct V_181 , V_190 , V_23 ,
V_100 -> V_191 ) ;
F_60 ( struct V_181 , V_192 , V_23 ,
V_100 -> V_193 ) ;
F_60 ( struct V_181 , V_194 , V_23 ,
( V_37 -> V_194 - 1 ) ) ;
}
int F_61 ( struct V_32 * V_34 )
{
struct V_36 * V_37 = V_34 -> V_22 ;
struct V_35 * V_35 = V_37 -> V_22 ;
struct V_9 * V_10 ;
struct V_180 V_23 ;
F_2 ( V_20 , L_44 ) ;
memset ( & V_23 , 0 , sizeof( struct V_180 ) ) ;
V_10 = V_35 -> V_3 ;
if ( ! V_10 )
F_2 ( V_21 , L_45 ) ;
V_35 -> V_195 = 0 ;
F_59 ( V_35 , & V_23 ) ;
F_62 ( V_35 , & V_23 ) ;
F_63 ( V_34 ) ;
return 0 ;
}
static int F_64 ( struct V_12 * V_13 )
{
unsigned short V_33 = 0xFFFF ;
if ( ! V_13 -> V_196 )
return V_33 ;
V_33 = V_13 -> V_197 [ V_13 -> V_198 ++ ] ;
if ( V_13 -> V_198 == V_13 -> V_23 . V_199 )
V_13 -> V_198 = 0 ;
V_13 -> V_196 -- ;
return V_33 ;
}
static void F_65 ( struct V_12 * V_13 , unsigned short V_33 )
{
V_13 -> V_196 ++ ;
V_13 -> V_197 [ V_13 -> V_200 ++ ] = V_33 ;
if ( V_13 -> V_200 == V_13 -> V_23 . V_199 )
V_13 -> V_200 = 0 ;
}
static void F_66 ( struct V_9 * V_10 )
{
struct V_12 * V_13 = V_10 -> V_13 ;
F_65 ( V_13 , V_10 -> V_44 ) ;
V_10 -> V_13 = NULL ;
}
static int F_67 ( struct V_2 * V_3 ,
struct V_201 * V_202 ,
struct V_201 * V_97 , int V_203 )
{
struct V_9 * V_10 = V_3 -> V_22 ;
struct V_12 * V_13 = V_10 -> V_13 ;
struct V_118 * V_119 = & V_13 -> V_120 . V_121 . V_122 ;
struct V_114 * V_115 ;
struct V_204 * V_205 ;
unsigned short V_112 , V_113 ;
struct V_206 V_207 ;
unsigned int V_110 , V_111 ;
int V_62 = - V_208 ;
F_2 ( V_20 , L_46 ) ;
V_10 -> V_44 = F_64 ( V_13 ) ;
if ( V_10 -> V_44 == 0xFFFF ) {
F_2 ( V_21 , L_47 ) ;
return V_62 ;
}
F_2 ( V_20 , L_48 ,
V_10 -> V_44 ) ;
V_13 -> V_209 [ V_10 -> V_44 -
V_13 -> V_210 . V_211 ] = V_3 ;
if ( V_10 -> V_44 > ( V_13 -> V_210 . V_211 +
V_13 -> V_23 . V_199 * 2 ) ) {
F_2 ( V_21 , L_49 ) ;
goto V_212;
}
V_10 -> V_213 = 0 ;
V_207 . V_214 = F_68 ( V_13 -> V_120 . V_215 ,
sizeof( struct V_216 ) ,
& V_207 . V_217 ) ;
if ( V_207 . V_214 == NULL ) {
F_2 ( V_21 ,
L_50
L_5 ) ;
F_65 ( V_13 , V_10 -> V_44 ) ;
return - V_208 ;
}
V_207 . V_218 = sizeof( struct V_216 ) ;
memset ( V_207 . V_214 , 0 , V_207 . V_218 ) ;
V_110 = F_69 ( V_13 , V_97 , V_10 , & V_207 ) ;
if ( ! V_110 ) {
F_2 ( V_21 ,
L_51 ,
V_10 -> V_44 ) ;
F_65 ( V_13 , V_10 -> V_44 ) ;
F_70 ( V_13 -> V_120 . V_215 , V_207 . V_218 ,
V_207 . V_214 , V_207 . V_217 ) ;
return - V_126 ;
} else {
F_43 ( V_13 -> V_120 . V_124 [ V_110 ] ,
V_13 -> V_120 . V_125 [ V_110 ] ) ;
}
V_111 = ( V_13 -> V_120 . V_125 [ V_110 ] & 0x00FF0000 ) >> 16 ;
V_113 = ( V_13 -> V_120 . V_125 [ V_110 ] & 0x0000FF00 ) >> 8 ;
V_112 = V_13 -> V_120 . V_125 [ V_110 ] & 0x000000FF ;
if ( V_112 || V_113 ) {
F_2 ( V_21 , L_52
L_53 ,
V_112 , V_113 ) ;
F_44 ( & V_13 -> V_120 , V_110 ) ;
F_70 ( V_13 -> V_120 . V_215 , V_207 . V_218 ,
V_207 . V_214 , V_207 . V_217 ) ;
goto V_212;
} else {
V_115 = F_45 ( V_119 , V_111 ) ;
F_44 ( & V_13 -> V_120 , V_110 ) ;
V_205 = F_46 ( V_115 ) ;
V_10 = V_3 -> V_22 ;
V_10 -> V_219 = V_205 -> V_220 ;
V_10 -> V_213 = 1 ;
F_2 ( V_20 , L_54 ) ;
}
F_70 ( V_13 -> V_120 . V_215 , V_207 . V_218 ,
V_207 . V_214 , V_207 . V_217 ) ;
return 0 ;
V_212:
F_66 ( V_10 ) ;
return - V_123 ;
}
struct V_2 *
F_71 ( struct V_7 * V_8 , struct V_201 * V_97 ,
int V_203 )
{
struct V_12 * V_13 ;
struct V_9 * V_10 ;
struct V_2 * V_3 ;
int V_62 ;
F_2 ( V_20 , L_55 ) ;
if ( V_8 )
V_13 = F_11 ( V_8 ) ;
else {
V_62 = - V_221 ;
F_2 ( V_21 , L_56 ) ;
return F_72 ( V_62 ) ;
}
if ( V_13 -> V_132 != V_133 ) {
V_62 = - V_123 ;
F_2 ( V_21 , L_57 ) ;
return F_72 ( V_62 ) ;
}
V_3 = F_73 ( sizeof( struct V_9 ) ) ;
if ( ! V_3 ) {
V_62 = - V_208 ;
return F_72 ( V_62 ) ;
}
V_10 = V_3 -> V_22 ;
V_10 -> V_13 = V_13 ;
V_10 -> V_222 = V_3 ;
V_62 = F_67 ( V_3 , NULL , V_97 , V_203 ) ;
if ( V_62 ) {
F_2 ( V_21 , L_58 ) ;
goto V_212;
}
return V_3 ;
V_212:
F_74 ( V_3 ) ;
return F_72 ( V_62 ) ;
}
int F_75 ( struct V_2 * V_3 , int V_223 )
{
struct V_9 * V_10 = V_3 -> V_22 ;
F_2 ( V_20 , L_59 ) ;
if ( V_10 -> V_213 == 1 )
return 1 ;
else
return 0 ;
}
static int F_76 ( struct V_9 * V_10 , int V_224 )
{
int V_62 = 0 ;
unsigned int V_110 ;
struct V_12 * V_13 = V_10 -> V_13 ;
V_110 = F_77 ( V_13 , V_10 -> V_44 , V_224 ) ;
if ( ! V_110 ) {
F_2 ( V_20 , L_60 ,
V_10 -> V_44 ) ;
V_62 = - V_126 ;
} else {
F_43 ( V_13 -> V_120 . V_124 [ V_110 ] ,
V_13 -> V_120 . V_125 [ V_110 ] ) ;
F_44 ( & V_13 -> V_120 , V_110 ) ;
}
return V_62 ;
}
static int F_78 ( struct V_12 * V_13 ,
unsigned int V_33 )
{
if ( V_13 -> V_38 [ V_33 ] )
V_13 -> V_38 [ V_33 ] = NULL ;
else {
F_2 ( V_20 , L_61 ) ;
return - V_39 ;
}
return 0 ;
}
void F_79 ( struct V_2 * V_3 )
{
struct V_35 * V_35 ;
struct V_9 * V_10 ;
struct V_12 * V_13 ;
unsigned int V_110 ;
unsigned short V_225 = V_226 ;
V_10 = V_3 -> V_22 ;
V_13 = V_10 -> V_13 ;
F_2 ( V_20 , L_62 ,
V_10 -> V_44 ) ;
if ( ! V_10 -> V_37 ) {
F_2 ( V_20 , L_63
L_64 ) ;
return;
}
V_35 = V_10 -> V_37 ;
F_80 ( V_35 -> V_37 ) ;
F_2 ( V_20 , L_65 ,
V_10 -> V_44 ) ;
V_110 = F_81 ( V_13 , V_10 ,
V_10 -> V_44 , 1 ,
V_225 ) ;
if ( ! V_110 ) {
F_2 ( V_21 ,
L_66 ,
V_10 -> V_44 ) ;
} else {
F_43 ( V_13 -> V_120 . V_124 [ V_110 ] ,
V_13 -> V_120 . V_125 [ V_110 ] ) ;
F_44 ( & V_13 -> V_120 , V_110 ) ;
}
F_76 ( V_10 , V_227 ) ;
F_66 ( V_10 ) ;
F_78 ( V_13 , V_10 -> V_44 ) ;
F_74 ( V_10 -> V_222 ) ;
}
T_5 F_82 ( int V_76 , int V_63 )
{
switch ( V_76 ) {
case V_77 :
switch ( V_63 ) {
case V_71 :
case V_65 :
case V_66 :
case V_64 :
case V_68 :
case V_73 :
return V_228 ;
default:
return 0 ;
}
case V_229 :
switch ( V_63 ) {
case V_148 :
case V_149 :
case V_150 :
case V_151 :
return V_228 ;
default:
return 0 ;
}
case V_230 :
switch ( V_63 ) {
case V_103 :
case V_107 :
case V_231 :
case V_232 :
case V_96 :
case V_94 :
case V_233 :
case V_234 :
case V_235 :
case V_236 :
case V_237 :
case V_238 :
case V_239 :
case V_240 :
case V_101 :
case V_105 :
case V_241 :
case V_242 :
case V_243 :
case V_244 :
case V_245 :
case V_246 :
case V_247 :
case V_248 :
case V_249 :
case V_250 :
case V_251 :
case V_252 :
case V_253 :
case V_254 :
return V_228 ;
default:
return 0 ;
}
}
return 0 ;
}
