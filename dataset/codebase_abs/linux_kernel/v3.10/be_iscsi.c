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
if ( ! V_3 ) {
F_2 ( V_20
L_1 ) ;
return NULL ;
}
V_10 = V_3 -> V_21 ;
V_13 = V_10 -> V_13 ;
V_8 = V_13 -> V_8 ;
F_3 ( V_13 , V_22 , V_23 ,
L_2 ) ;
if ( V_4 > V_10 -> V_13 -> V_24 . V_25 ) {
F_3 ( V_13 , V_20 , V_23 ,
L_3
L_4
L_5 , V_4 ,
V_10 -> V_13 -> V_24 . V_25 ,
V_10 -> V_13 -> V_24 . V_25 ) ;
V_4 = V_10 -> V_13 -> V_24 . V_25 ;
}
V_11 = F_4 ( & V_26 ,
V_8 , V_4 ,
sizeof( * V_17 ) ,
sizeof( * V_19 ) ,
V_6 , V_27 ) ;
if ( ! V_11 )
return NULL ;
V_15 = V_11 -> V_21 ;
V_17 = V_15 -> V_21 ;
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
struct V_14 * V_15 = V_11 -> V_21 ;
struct V_16 * V_17 = V_15 -> V_21 ;
F_2 ( V_22 L_7 ) ;
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
V_8 = F_10 ( V_11 ) ;
V_13 = F_11 ( V_8 ) ;
F_3 ( V_13 , V_22 , V_23 ,
L_8
L_9 , V_33 ) ;
V_34 = F_12 ( V_11 , sizeof( * V_35 ) , V_33 ) ;
if ( ! V_34 )
return NULL ;
V_37 = V_34 -> V_21 ;
V_35 = V_37 -> V_21 ;
V_35 -> V_3 = NULL ;
V_35 -> V_13 = V_13 ;
V_35 -> V_37 = V_37 ;
V_15 = V_11 -> V_21 ;
V_17 = V_15 -> V_21 ;
V_35 -> V_17 = V_17 ;
return V_34 ;
}
static int F_13 ( struct V_12 * V_13 ,
struct V_35 * V_35 ,
unsigned int V_33 )
{
T_3 V_38 = F_14 ( V_33 ) ;
if ( V_13 -> V_39 [ V_38 ] ) {
F_3 ( V_13 , V_20 , V_23 ,
L_10 ) ;
return - V_40 ;
} else {
F_3 ( V_13 , V_22 , V_23 ,
L_11 ,
V_38 , V_35 ) ;
V_13 -> V_39 [ V_38 ] = V_35 ;
}
return 0 ;
}
int F_15 ( struct V_1 * V_11 ,
struct V_32 * V_34 ,
T_4 V_41 , int V_42 )
{
struct V_36 * V_37 = V_34 -> V_21 ;
struct V_35 * V_35 = V_37 -> V_21 ;
struct V_7 * V_8 = F_10 ( V_11 ) ;
struct V_12 * V_13 = F_11 ( V_8 ) ;
struct V_9 * V_10 ;
struct V_2 * V_3 ;
V_3 = F_16 ( V_41 ) ;
if ( ! V_3 )
return - V_40 ;
V_10 = V_3 -> V_21 ;
if ( F_17 ( V_11 , V_34 , V_42 ) )
return - V_40 ;
if ( V_10 -> V_13 != V_13 ) {
F_3 ( V_13 , V_20 , V_23 ,
L_12 ,
V_10 -> V_13 , V_13 ) ;
return - V_43 ;
}
V_35 -> V_44 = V_10 -> V_45 ;
V_35 -> V_3 = V_10 ;
V_10 -> V_37 = V_35 ;
F_3 ( V_13 , V_22 , V_23 ,
L_13 ,
V_35 , V_37 , V_10 -> V_45 ) ;
return F_13 ( V_13 , V_35 , V_10 -> V_45 ) ;
}
static int F_18 ( struct V_12 * V_13 )
{
if ( V_13 -> V_46 )
return 0 ;
V_13 -> V_46 = F_19 ( V_13 -> V_8 ,
& V_26 ,
V_47 ,
0 , 0 ) ;
if ( ! V_13 -> V_46 ) {
F_3 ( V_13 , V_20 , V_23 ,
L_14
L_15 ) ;
return - V_48 ;
}
return 0 ;
}
static int F_20 ( struct V_12 * V_13 )
{
if ( V_13 -> V_49 )
return 0 ;
V_13 -> V_49 = F_19 ( V_13 -> V_8 ,
& V_26 ,
V_50 ,
0 , 0 ) ;
if ( ! V_13 -> V_49 ) {
F_3 ( V_13 , V_20 , V_23 ,
L_14
L_16 ) ;
return - V_48 ;
}
return 0 ;
}
void F_21 ( struct V_12 * V_13 )
{
struct V_51 V_52 ;
if ( ! F_22 ( V_13 , V_53 , & V_52 ) )
F_18 ( V_13 ) ;
if ( ! F_22 ( V_13 , V_54 , & V_52 ) )
F_20 ( V_13 ) ;
}
void F_23 ( struct V_12 * V_13 )
{
if ( V_13 -> V_49 )
F_24 ( V_13 -> V_49 ) ;
if ( V_13 -> V_46 )
F_24 ( V_13 -> V_46 ) ;
}
static int
F_25 ( struct V_7 * V_8 ,
struct V_55 * V_56 ,
void * V_57 , T_5 V_58 )
{
struct V_12 * V_13 = F_11 ( V_8 ) ;
struct V_55 * V_59 = NULL ;
struct V_55 * V_60 = NULL ;
struct V_61 * V_62 ;
int V_63 ;
switch ( V_56 -> V_64 ) {
case V_65 :
V_62 = F_26 ( V_57 , V_58 , V_66 ) ;
if ( V_62 )
V_59 = F_27 ( V_62 ) ;
V_62 = F_26 ( V_57 , V_58 , V_67 ) ;
if ( V_62 )
V_60 = F_27 ( V_62 ) ;
break;
case V_66 :
V_59 = V_56 ;
V_62 = F_26 ( V_57 , V_58 , V_67 ) ;
if ( V_62 )
V_60 = F_27 ( V_62 ) ;
break;
case V_67 :
V_60 = V_56 ;
V_62 = F_26 ( V_57 , V_58 , V_66 ) ;
if ( V_62 )
V_59 = F_27 ( V_62 ) ;
break;
default:
F_3 ( V_13 , V_20 , V_23 ,
L_17 ,
V_56 -> V_64 ) ;
}
if ( ! V_59 || ! V_60 ) {
F_3 ( V_13 , V_20 , V_23 ,
L_18 ) ;
return - V_40 ;
}
V_63 = F_28 ( V_13 , V_59 , V_60 ,
V_68 ) ;
return V_63 ;
}
static int
F_29 ( struct V_7 * V_8 ,
struct V_55 * V_56 )
{
struct V_12 * V_13 = F_11 ( V_8 ) ;
int V_63 = 0 ;
if ( F_30 ( V_13 ) ) {
F_3 ( V_13 , V_20 , V_23 ,
L_19 ) ;
return - V_69 ;
}
switch ( V_56 -> V_64 ) {
case V_70 :
if ( V_56 -> V_71 [ 0 ] != V_72 )
V_63 = F_31 ( V_13 , V_73 ) ;
break;
case V_74 :
V_63 = F_31 ( V_13 ,
* ( ( T_3 * ) V_56 -> V_71 ) ) ;
break;
default:
F_3 ( V_13 , V_75 , V_23 ,
L_20 ,
V_56 -> V_64 ) ;
return - V_76 ;
}
return V_63 ;
}
static int
F_32 ( struct V_7 * V_8 ,
struct V_55 * V_56 ,
void * V_57 , T_5 V_58 )
{
struct V_12 * V_13 = F_11 ( V_8 ) ;
int V_63 = 0 ;
switch ( V_56 -> V_64 ) {
case V_77 :
V_63 = F_33 ( V_13 , V_56 ) ;
break;
case V_65 :
if ( V_56 -> V_71 [ 0 ] == V_78 )
V_63 = F_28 ( V_13 , V_56 ,
NULL , V_78 ) ;
else if ( V_56 -> V_71 [ 0 ] == V_68 )
V_63 = F_25 ( V_8 , V_56 ,
V_57 , V_58 ) ;
else
F_3 ( V_13 , V_20 , V_23 ,
L_21 ,
V_56 -> V_71 [ 0 ] ) ;
break;
case V_79 :
if ( V_56 -> V_71 [ 0 ] == V_80 )
V_63 = F_18 ( V_13 ) ;
else
F_24 ( V_13 -> V_46 ) ;
break;
case V_67 :
case V_66 :
V_63 = F_25 ( V_8 , V_56 ,
V_57 , V_58 ) ;
break;
case V_70 :
case V_74 :
V_63 = F_29 ( V_8 , V_56 ) ;
break;
default:
F_3 ( V_13 , V_20 , V_23 ,
L_22 ,
V_56 -> V_64 ) ;
}
return V_63 ;
}
static int
F_34 ( struct V_7 * V_8 ,
struct V_55 * V_56 ,
void * V_57 , T_5 V_58 )
{
struct V_12 * V_13 = F_11 ( V_8 ) ;
int V_63 = 0 ;
switch ( V_56 -> V_64 ) {
case V_79 :
if ( V_56 -> V_71 [ 0 ] == V_80 )
V_63 = F_20 ( V_13 ) ;
else {
F_24 ( V_13 -> V_49 ) ;
V_63 = 0 ;
}
break;
case V_81 :
V_63 = F_28 ( V_13 , V_56 , NULL ,
V_68 ) ;
break;
default:
F_3 ( V_13 , V_20 , V_23 ,
L_22 ,
V_56 -> V_64 ) ;
}
return V_63 ;
}
int F_35 ( struct V_7 * V_8 ,
void * V_57 , T_5 V_58 )
{
struct V_55 * V_56 = NULL ;
struct V_12 * V_13 = F_11 ( V_8 ) ;
struct V_61 * V_82 ;
T_5 V_83 = V_58 ;
int V_63 = 0 ;
F_36 (attrib, data, dt_len, rm_len) {
V_56 = F_27 ( V_82 ) ;
if ( V_56 -> V_84 != V_85 )
continue;
if ( V_56 -> V_86 ) {
F_3 ( V_13 , V_20 , V_23 ,
L_23
L_24 ,
V_56 -> V_86 ) ;
return - V_40 ;
}
switch ( V_56 -> V_87 ) {
case V_47 :
V_63 = F_32 ( V_8 , V_56 ,
V_57 , V_58 ) ;
break;
case V_50 :
V_63 = F_34 ( V_8 , V_56 ,
V_57 , V_58 ) ;
break;
default:
F_3 ( V_13 , V_20 , V_23 ,
L_25 ,
V_56 -> V_87 ) ;
break;
}
if ( V_63 )
return V_63 ;
}
return V_63 ;
}
static int F_37 ( struct V_12 * V_13 ,
struct V_88 * V_89 , int V_64 ,
char * V_90 )
{
struct V_51 V_52 ;
int V_91 , V_92 = V_53 ;
memset ( & V_52 , 0 , sizeof( V_52 ) ) ;
if ( V_89 -> V_87 == V_50 )
V_92 = V_54 ;
V_91 = F_22 ( V_13 , V_92 , & V_52 ) ;
if ( V_91 )
return V_91 ;
switch ( V_64 ) {
case V_66 :
V_91 = sprintf ( V_90 , L_26 , & V_52 . V_93 . V_94 ) ;
break;
case V_81 :
V_91 = sprintf ( V_90 , L_27 , & V_52 . V_93 . V_94 ) ;
break;
case V_65 :
if ( ! V_52 . V_95 )
V_91 = sprintf ( V_90 , L_28 ) ;
else
V_91 = sprintf ( V_90 , L_29 ) ;
break;
case V_67 :
V_91 = sprintf ( V_90 , L_26 , & V_52 . V_93 . V_96 ) ;
break;
case V_70 :
V_91 = sprintf ( V_90 , L_30 ,
( V_52 . V_97 == V_73 )
? L_31 : L_32 ) ;
break;
case V_98 :
if ( V_52 . V_97 == V_73 )
return - V_40 ;
else
V_91 = sprintf ( V_90 , L_33 ,
( V_52 . V_97 &
V_99 ) ) ;
break;
case V_100 :
if ( V_52 . V_97 == V_73 )
return - V_40 ;
else
V_91 = sprintf ( V_90 , L_33 ,
( ( V_52 . V_97 >> 13 ) &
V_101 ) ) ;
break;
default:
F_38 ( 1 ) ;
}
return V_91 ;
}
int F_39 ( struct V_88 * V_89 ,
enum V_102 V_84 ,
int V_64 , char * V_90 )
{
struct V_7 * V_8 = F_40 ( V_89 ) ;
struct V_12 * V_13 = F_11 ( V_8 ) ;
struct V_103 V_104 ;
int V_91 = - V_76 ;
switch ( V_64 ) {
case V_66 :
case V_67 :
case V_65 :
case V_81 :
case V_70 :
case V_98 :
case V_100 :
V_91 = F_37 ( V_13 , V_89 , V_64 , V_90 ) ;
break;
case V_79 :
V_91 = sprintf ( V_90 , L_34 ) ;
break;
case V_77 :
memset ( & V_104 , 0 , sizeof( V_104 ) ) ;
V_91 = F_41 ( V_13 , V_53 , & V_104 ) ;
if ( ! V_91 )
V_91 = sprintf ( V_90 , L_26 , & V_104 . V_93 . V_94 ) ;
break;
default:
V_91 = - V_76 ;
}
return V_91 ;
}
int F_42 ( struct V_2 * V_3 ,
enum V_105 V_64 , char * V_90 )
{
struct V_9 * V_10 = V_3 -> V_21 ;
int V_91 = 0 ;
F_3 ( V_10 -> V_13 , V_22 ,
V_23 ,
L_35
L_36 , V_64 ) ;
switch ( V_64 ) {
case V_106 :
V_91 = sprintf ( V_90 , L_37 , V_10 -> V_107 ) ;
break;
case V_108 :
if ( V_10 -> V_92 == V_53 )
V_91 = sprintf ( V_90 , L_26 , & V_10 -> V_109 ) ;
else
V_91 = sprintf ( V_90 , L_27 , & V_10 -> V_110 ) ;
break;
default:
return - V_76 ;
}
return V_91 ;
}
int F_43 ( struct V_32 * V_34 ,
enum V_105 V_64 , char * V_90 , int V_111 )
{
struct V_36 * V_37 = V_34 -> V_21 ;
struct V_14 * V_112 = V_37 -> V_112 ;
struct V_12 * V_13 = NULL ;
int V_63 ;
V_13 = ( (struct V_35 * ) V_37 -> V_21 ) -> V_13 ;
F_3 ( V_13 , V_22 , V_23 ,
L_38
L_36 , V_64 ) ;
V_63 = F_44 ( V_34 , V_64 , V_90 , V_111 ) ;
if ( V_63 )
return V_63 ;
switch ( V_64 ) {
case V_113 :
if ( V_112 -> V_114 > 8192 )
V_112 -> V_114 = 8192 ;
break;
case V_115 :
if ( V_37 -> V_116 > 65536 )
V_37 -> V_116 = 65536 ;
break;
case V_117 :
if ( V_112 -> V_118 > 262144 )
V_112 -> V_118 = 262144 ;
break;
case V_119 :
if ( ( V_37 -> V_120 > 65536 ) ||
( V_37 -> V_120 == 0 ) )
V_37 -> V_120 = 65536 ;
default:
return 0 ;
}
return 0 ;
}
static int F_45 ( char * V_90 , struct V_12 * V_13 )
{
int V_121 ;
unsigned int V_122 ;
struct V_123 * V_124 ;
struct V_125 * V_126 ;
V_122 = F_46 ( V_13 ) ;
if ( ! V_122 ) {
F_3 ( V_13 , V_20 , V_23 ,
L_39 ) ;
return - V_127 ;
}
V_121 = F_47 ( V_13 , V_122 , & V_124 , NULL ) ;
if ( V_121 ) {
F_3 ( V_13 , V_20 ,
V_23 | V_128 ,
L_40 ) ;
return V_121 ;
}
V_126 = F_48 ( V_124 ) ;
V_121 = sprintf ( V_90 , L_30 , V_126 -> V_129 ) ;
return V_121 ;
}
static void F_49 ( struct V_7 * V_8 )
{
struct V_12 * V_13 = F_11 ( V_8 ) ;
struct V_130 * V_131 = V_8 -> V_132 ;
V_131 -> V_133 = ( V_13 -> V_134 == V_135 ) ?
V_136 : V_137 ;
}
static int F_50 ( struct V_7 * V_8 )
{
int V_121 ;
unsigned int V_122 ;
struct V_123 * V_124 ;
struct V_138 * V_126 ;
struct V_12 * V_13 = F_11 ( V_8 ) ;
struct V_130 * V_131 = V_8 -> V_132 ;
V_122 = F_51 ( V_13 ) ;
if ( ! V_122 ) {
F_3 ( V_13 , V_20 , V_23 ,
L_41 ) ;
return - V_127 ;
}
V_121 = F_47 ( V_13 , V_122 , & V_124 , NULL ) ;
if ( V_121 ) {
F_3 ( V_13 , V_20 ,
V_23 | V_128 ,
L_42 ) ;
return V_121 ;
}
V_126 = F_48 ( V_124 ) ;
switch ( V_126 -> V_139 ) {
case V_140 :
V_131 -> V_141 = V_142 ;
break;
case V_143 :
V_131 -> V_141 = V_143 ;
break;
case V_144 :
V_131 -> V_141 = V_145 ;
break;
case V_146 :
V_131 -> V_141 = V_147 ;
break;
default:
V_131 -> V_141 = V_148 ;
}
return 0 ;
}
int F_52 ( struct V_7 * V_8 ,
enum V_149 V_64 , char * V_90 )
{
struct V_12 * V_13 = F_11 ( V_8 ) ;
int V_150 = 0 ;
F_3 ( V_13 , V_22 , V_23 ,
L_43
L_36 , V_64 ) ;
switch ( V_64 ) {
case V_151 :
V_150 = F_53 ( V_90 , V_13 ) ;
if ( V_150 < 0 ) {
F_3 ( V_13 , V_20 , V_23 ,
L_44 ) ;
return V_150 ;
}
break;
case V_152 :
V_150 = F_45 ( V_90 , V_13 ) ;
if ( V_150 < 0 ) {
F_3 ( V_13 , V_20 , V_23 ,
L_45 ) ;
return V_150 ;
}
break;
case V_153 :
F_49 ( V_8 ) ;
V_150 = sprintf ( V_90 , L_30 , F_54 ( V_8 ) ) ;
break;
case V_154 :
V_150 = F_50 ( V_8 ) ;
if ( V_150 ) {
F_3 ( V_13 , V_20 , V_23 ,
L_46 ) ;
return V_150 ;
}
V_150 = sprintf ( V_90 , L_30 , F_55 ( V_8 ) ) ;
break;
default:
return F_56 ( V_8 , V_64 , V_90 ) ;
}
return V_150 ;
}
int F_53 ( char * V_90 , struct V_12 * V_13 )
{
struct V_155 V_126 ;
int V_121 ;
if ( strlen ( V_13 -> V_156 ) )
return F_57 ( V_90 , V_13 -> V_156 , V_157 ) ;
memset ( & V_126 , 0 , sizeof( V_126 ) ) ;
V_121 = F_58 ( V_13 , & V_126 ) ;
if ( V_121 )
return V_121 ;
memcpy ( V_13 -> V_156 , V_126 . V_156 , V_157 ) ;
return F_57 ( V_90 , V_13 -> V_156 , V_157 ) ;
}
void F_59 ( struct V_32 * V_34 ,
struct V_158 * V_159 )
{
struct V_36 * V_37 = V_34 -> V_21 ;
struct V_12 * V_13 = NULL ;
V_13 = ( (struct V_35 * ) V_37 -> V_21 ) -> V_13 ;
F_3 ( V_13 , V_22 , V_23 ,
L_47 ) ;
V_159 -> V_160 = V_37 -> V_160 ;
V_159 -> V_161 = V_37 -> V_161 ;
V_159 -> V_162 = V_37 -> V_163 ;
V_159 -> V_164 = V_37 -> V_165 ;
V_159 -> V_166 = V_37 -> V_167 ;
V_159 -> V_168 = V_37 -> V_169 ;
V_159 -> V_170 = V_37 -> V_171 ;
V_159 -> V_172 = V_37 -> V_173 ;
V_159 -> V_174 = V_37 -> V_175 ;
V_159 -> V_176 = 0 ;
V_159 -> V_177 = 0 ;
V_159 -> V_178 = 0 ;
strcpy ( V_159 -> V_179 [ 0 ] . V_180 , L_48 ) ;
V_159 -> V_179 [ 0 ] . V_71 = V_37 -> V_181 ;
}
static void F_60 ( struct V_35 * V_35 ,
struct V_182 * V_24 )
{
struct V_36 * V_37 = V_35 -> V_37 ;
struct V_14 * V_112 = V_37 -> V_112 ;
F_61 ( struct V_183 , V_184 ,
V_24 , V_112 -> V_118 ) ;
F_61 ( struct V_183 ,
V_185 , V_24 ,
V_37 -> V_120 ) ;
F_61 ( struct V_183 , V_186 ,
V_24 , V_112 -> V_114 ) ;
F_61 ( struct V_183 , V_187 , V_24 ,
V_112 -> V_187 ) ;
F_61 ( struct V_183 , V_188 , V_24 ,
V_37 -> V_189 ) ;
F_61 ( struct V_183 , V_190 , V_24 ,
V_37 -> V_191 ) ;
F_61 ( struct V_183 , V_192 , V_24 ,
V_112 -> V_193 ) ;
F_61 ( struct V_183 , V_194 , V_24 ,
V_112 -> V_195 ) ;
F_61 ( struct V_183 ,
V_196 , V_24 ,
V_112 -> V_197 ) ;
F_61 ( struct V_183 ,
V_198 , V_24 ,
V_112 -> V_199 ) ;
F_61 ( struct V_183 , V_200 , V_24 ,
V_112 -> V_200 ) ;
F_61 ( struct V_183 , V_201 , V_24 ,
( V_37 -> V_201 - 1 ) ) ;
}
int F_62 ( struct V_32 * V_34 )
{
struct V_36 * V_37 = V_34 -> V_21 ;
struct V_35 * V_35 = V_37 -> V_21 ;
struct V_9 * V_10 ;
struct V_182 V_24 ;
F_3 ( V_35 -> V_13 , V_22 ,
V_23 ,
L_49 ) ;
memset ( & V_24 , 0 , sizeof( struct V_182 ) ) ;
V_10 = V_35 -> V_3 ;
if ( ! V_10 )
F_3 ( V_35 -> V_13 , V_20 ,
V_23 ,
L_50 ) ;
V_35 -> V_202 = 0 ;
F_60 ( V_35 , & V_24 ) ;
F_63 ( V_35 , & V_24 ) ;
F_64 ( V_34 ) ;
return 0 ;
}
static int F_65 ( struct V_12 * V_13 )
{
unsigned short V_33 = 0xFFFF ;
if ( ! V_13 -> V_203 )
return V_33 ;
V_33 = V_13 -> V_204 [ V_13 -> V_205 ++ ] ;
if ( V_13 -> V_205 == V_13 -> V_24 . V_206 )
V_13 -> V_205 = 0 ;
V_13 -> V_203 -- ;
return V_33 ;
}
static void F_66 ( struct V_12 * V_13 , unsigned short V_33 )
{
V_13 -> V_203 ++ ;
V_13 -> V_204 [ V_13 -> V_207 ++ ] = V_33 ;
if ( V_13 -> V_207 == V_13 -> V_24 . V_206 )
V_13 -> V_207 = 0 ;
}
static void F_67 ( struct V_9 * V_10 )
{
struct V_12 * V_13 = V_10 -> V_13 ;
struct V_35 * V_35 ;
F_66 ( V_13 , V_10 -> V_45 ) ;
V_10 -> V_13 = NULL ;
V_13 -> V_208 [ F_14
( V_10 -> V_45 ) ] = NULL ;
if ( ! V_10 -> V_37 )
return;
V_35 = V_10 -> V_37 ;
if ( V_35 -> V_202 ) {
F_68 ( V_35 ,
V_35 -> V_209 ) ;
V_35 -> V_202 = 0 ;
}
}
static int F_69 ( struct V_2 * V_3 ,
struct V_210 * V_211 ,
struct V_210 * V_109 , int V_212 )
{
struct V_9 * V_10 = V_3 -> V_21 ;
struct V_12 * V_13 = V_10 -> V_13 ;
struct V_213 * V_214 ;
struct V_215 V_216 ;
unsigned int V_122 ;
int V_63 = - V_217 ;
F_3 ( V_13 , V_22 , V_23 ,
L_51 ) ;
V_10 -> V_45 = F_65 ( V_13 ) ;
if ( V_10 -> V_45 == 0xFFFF ) {
F_3 ( V_13 , V_20 , V_23 ,
L_52 ) ;
return V_63 ;
}
F_3 ( V_13 , V_22 , V_23 ,
L_53 ,
V_10 -> V_45 ) ;
V_13 -> V_208 [ F_14
( V_10 -> V_45 ) ] = V_3 ;
V_10 -> V_218 = 0 ;
V_216 . V_219 = F_70 ( V_13 -> V_220 . V_221 ,
sizeof( struct V_222 ) ,
& V_216 . V_223 ) ;
if ( V_216 . V_219 == NULL ) {
F_3 ( V_13 , V_20 , V_23 ,
L_54
L_55 ) ;
F_67 ( V_10 ) ;
return - V_217 ;
}
V_216 . V_224 = sizeof( struct V_222 ) ;
memset ( V_216 . V_219 , 0 , V_216 . V_224 ) ;
V_122 = F_71 ( V_13 , V_109 , V_10 , & V_216 ) ;
if ( V_122 <= 0 ) {
F_3 ( V_13 , V_20 , V_23 ,
L_56 ,
V_10 -> V_45 ) ;
F_72 ( V_13 -> V_220 . V_221 , V_216 . V_224 ,
V_216 . V_219 , V_216 . V_223 ) ;
F_67 ( V_10 ) ;
return - V_225 ;
}
V_63 = F_47 ( V_13 , V_122 , NULL , V_216 . V_219 ) ;
if ( V_63 ) {
F_3 ( V_13 , V_20 ,
V_23 | V_128 ,
L_57 ) ;
F_72 ( V_13 -> V_220 . V_221 , V_216 . V_224 ,
V_216 . V_219 , V_216 . V_223 ) ;
F_67 ( V_10 ) ;
return - V_127 ;
}
V_214 = (struct V_213 * ) V_216 . V_219 ;
V_10 = V_3 -> V_21 ;
V_10 -> V_226 = V_214 -> V_227 ;
V_10 -> V_218 = 1 ;
F_3 ( V_13 , V_22 , V_23 ,
L_58 ) ;
F_72 ( V_13 -> V_220 . V_221 , V_216 . V_224 ,
V_216 . V_219 , V_216 . V_223 ) ;
return 0 ;
}
struct V_2 *
F_73 ( struct V_7 * V_8 , struct V_210 * V_109 ,
int V_212 )
{
struct V_12 * V_13 ;
struct V_9 * V_10 ;
struct V_2 * V_3 ;
int V_63 ;
if ( V_8 )
V_13 = F_11 ( V_8 ) ;
else {
V_63 = - V_228 ;
F_2 ( V_20
L_59 ) ;
return F_74 ( V_63 ) ;
}
if ( F_75 ( V_13 ) ) {
V_63 = - V_69 ;
F_3 ( V_13 , V_75 , V_23 ,
L_60 ) ;
return F_74 ( V_63 ) ;
}
if ( V_13 -> V_134 != V_135 ) {
V_63 = - V_127 ;
F_3 ( V_13 , V_75 , V_23 ,
L_61 ) ;
return F_74 ( V_63 ) ;
}
V_3 = F_76 ( sizeof( struct V_9 ) ) ;
if ( ! V_3 ) {
V_63 = - V_217 ;
return F_74 ( V_63 ) ;
}
V_10 = V_3 -> V_21 ;
V_10 -> V_13 = V_13 ;
V_10 -> V_229 = V_3 ;
V_63 = F_69 ( V_3 , NULL , V_109 , V_212 ) ;
if ( V_63 ) {
F_3 ( V_13 , V_20 , V_23 ,
L_62 ) ;
goto V_230;
}
return V_3 ;
V_230:
F_77 ( V_3 ) ;
return F_74 ( V_63 ) ;
}
int F_78 ( struct V_2 * V_3 , int V_231 )
{
struct V_9 * V_10 = V_3 -> V_21 ;
F_3 ( V_10 -> V_13 , V_22 , V_23 ,
L_63 ) ;
if ( V_10 -> V_218 == 1 )
return 1 ;
else
return 0 ;
}
static int F_79 ( struct V_9 * V_10 , int V_232 )
{
int V_63 = 0 ;
unsigned int V_122 ;
struct V_12 * V_13 = V_10 -> V_13 ;
V_122 = F_80 ( V_13 , V_10 -> V_45 , V_232 ) ;
if ( ! V_122 ) {
F_3 ( V_13 , V_22 , V_23 ,
L_64 ,
V_10 -> V_45 ) ;
V_63 = - V_225 ;
}
V_63 = F_47 ( V_13 , V_122 , NULL , NULL ) ;
return V_63 ;
}
static int F_81 ( struct V_12 * V_13 ,
unsigned int V_33 )
{
T_3 V_38 = F_14 ( V_33 ) ;
if ( V_13 -> V_39 [ V_38 ] )
V_13 -> V_39 [ V_38 ] = NULL ;
else {
F_3 ( V_13 , V_22 , V_23 ,
L_65 ) ;
return - V_40 ;
}
return 0 ;
}
void F_82 ( struct V_2 * V_3 )
{
struct V_35 * V_35 ;
struct V_9 * V_10 ;
struct V_12 * V_13 ;
unsigned int V_122 ;
T_6 V_233 , V_234 ;
unsigned short V_235 = V_236 ;
V_10 = V_3 -> V_21 ;
V_13 = V_10 -> V_13 ;
F_3 ( V_13 , V_22 , V_23 ,
L_66 ,
V_10 -> V_45 ) ;
if ( V_10 -> V_37 ) {
V_35 = V_10 -> V_37 ;
F_83 ( V_35 -> V_37 ) ;
V_233 = ~ V_237 ;
V_234 = V_238 ;
} else {
V_233 = V_237 ;
V_234 = V_239 ;
}
V_122 = F_84 ( V_13 , V_10 ,
V_10 -> V_45 ,
V_233 ,
V_235 ) ;
if ( ! V_122 ) {
F_3 ( V_13 , V_20 , V_23 ,
L_67 ,
V_10 -> V_45 ) ;
}
F_47 ( V_13 , V_122 , NULL , NULL ) ;
F_79 ( V_10 , V_234 ) ;
F_67 ( V_10 ) ;
F_81 ( V_13 , V_10 -> V_45 ) ;
F_77 ( V_10 -> V_229 ) ;
}
T_7 F_85 ( int V_84 , int V_64 )
{
switch ( V_84 ) {
case V_85 :
switch ( V_64 ) {
case V_79 :
case V_66 :
case V_67 :
case V_65 :
case V_77 :
case V_81 :
case V_98 :
case V_100 :
case V_70 :
return V_240 ;
default:
return 0 ;
}
case V_241 :
switch ( V_64 ) {
case V_151 :
case V_152 :
case V_153 :
case V_154 :
return V_240 ;
default:
return 0 ;
}
case V_242 :
switch ( V_64 ) {
case V_115 :
case V_119 :
case V_243 :
case V_244 :
case V_108 :
case V_106 :
case V_245 :
case V_246 :
case V_247 :
case V_248 :
case V_249 :
case V_250 :
case V_251 :
case V_252 :
case V_113 :
case V_117 :
case V_253 :
case V_254 :
case V_255 :
case V_256 :
case V_257 :
case V_258 :
case V_259 :
case V_260 :
case V_261 :
case V_262 :
case V_263 :
case V_264 :
case V_265 :
case V_266 :
return V_240 ;
default:
return 0 ;
}
}
return 0 ;
}
