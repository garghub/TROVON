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
if ( V_13 -> V_22 & V_23 ) {
F_3 ( V_13 , V_20 , V_24 ,
L_2 ) ;
return NULL ;
} else {
F_3 ( V_13 , V_25 , V_24 ,
L_3 ) ;
}
if ( V_4 > V_10 -> V_13 -> V_26 . V_27 ) {
F_3 ( V_13 , V_20 , V_24 ,
L_4
L_5
L_6 , V_4 ,
V_10 -> V_13 -> V_26 . V_27 ,
V_10 -> V_13 -> V_26 . V_27 ) ;
V_4 = V_10 -> V_13 -> V_26 . V_27 ;
}
V_8 = V_13 -> V_8 ;
V_11 = F_4 ( & V_28 ,
V_8 , V_4 ,
sizeof( * V_17 ) ,
sizeof( * V_19 ) ,
V_6 , V_29 ) ;
if ( ! V_11 )
return NULL ;
V_15 = V_11 -> V_21 ;
V_17 = V_15 -> V_21 ;
V_17 -> V_30 = F_5 ( L_7 ,
V_13 -> V_31 ,
sizeof( struct V_32 ) ,
64 , 0 ) ;
if ( ! V_17 -> V_30 )
goto V_33;
return V_11 ;
V_33:
F_6 ( V_11 ) ;
return NULL ;
}
void F_7 ( struct V_1 * V_11 )
{
struct V_14 * V_15 = V_11 -> V_21 ;
struct V_16 * V_17 = V_15 -> V_21 ;
F_2 ( V_25 L_8 ) ;
F_8 ( V_17 -> V_30 ) ;
F_6 ( V_11 ) ;
}
struct V_34 *
F_9 ( struct V_1 * V_11 , T_2 V_35 )
{
struct V_12 * V_13 ;
struct V_7 * V_8 ;
struct V_34 * V_36 ;
struct V_37 * V_37 ;
struct V_38 * V_39 ;
struct V_14 * V_15 ;
struct V_16 * V_17 ;
V_8 = F_10 ( V_11 ) ;
V_13 = F_11 ( V_8 ) ;
F_3 ( V_13 , V_25 , V_24 ,
L_9
L_10 , V_35 ) ;
V_36 = F_12 ( V_11 , sizeof( * V_37 ) , V_35 ) ;
if ( ! V_36 )
return NULL ;
V_39 = V_36 -> V_21 ;
V_37 = V_39 -> V_21 ;
V_37 -> V_3 = NULL ;
V_37 -> V_13 = V_13 ;
V_37 -> V_39 = V_39 ;
V_15 = V_11 -> V_21 ;
V_17 = V_15 -> V_21 ;
V_37 -> V_17 = V_17 ;
return V_36 ;
}
static int F_13 ( struct V_12 * V_13 ,
struct V_37 * V_37 ,
unsigned int V_35 )
{
T_3 V_40 = F_14 ( V_35 ) ;
if ( V_13 -> V_41 [ V_40 ] ) {
F_3 ( V_13 , V_20 , V_24 ,
L_11 ) ;
return - V_42 ;
} else {
F_3 ( V_13 , V_25 , V_24 ,
L_12 ,
V_40 , V_37 ) ;
V_13 -> V_41 [ V_40 ] = V_37 ;
}
return 0 ;
}
int F_15 ( struct V_1 * V_11 ,
struct V_34 * V_36 ,
T_4 V_43 , int V_44 )
{
struct V_38 * V_39 = V_36 -> V_21 ;
struct V_37 * V_37 = V_39 -> V_21 ;
struct V_7 * V_8 = F_10 ( V_11 ) ;
struct V_12 * V_13 = F_11 ( V_8 ) ;
struct V_45 * V_46 = V_13 -> V_46 ;
struct V_47 * V_48 ;
struct V_9 * V_10 ;
struct V_2 * V_3 ;
V_3 = F_16 ( V_43 ) ;
if ( ! V_3 )
return - V_42 ;
V_10 = V_3 -> V_21 ;
if ( F_17 ( V_11 , V_36 , V_44 ) )
return - V_42 ;
if ( V_10 -> V_13 != V_13 ) {
F_3 ( V_13 , V_20 , V_24 ,
L_13 ,
V_10 -> V_13 , V_13 ) ;
return - V_49 ;
}
V_48 = & V_46 -> V_50 [ F_14 (
V_10 -> V_51 ) ] ;
V_37 -> V_52 = V_10 -> V_51 ;
V_37 -> V_3 = V_10 ;
V_10 -> V_39 = V_37 ;
V_37 -> V_53 = V_48 -> V_53 ;
F_3 ( V_13 , V_25 , V_24 ,
L_14 ,
V_37 , V_39 , V_10 -> V_51 ) ;
return F_13 ( V_13 , V_37 , V_10 -> V_51 ) ;
}
static int F_18 ( struct V_12 * V_13 )
{
if ( V_13 -> V_54 )
return 0 ;
V_13 -> V_54 = F_19 ( V_13 -> V_8 ,
& V_28 ,
V_55 ,
0 , 0 ) ;
if ( ! V_13 -> V_54 ) {
F_3 ( V_13 , V_20 , V_24 ,
L_15
L_16 ) ;
return - V_56 ;
}
return 0 ;
}
static int F_20 ( struct V_12 * V_13 )
{
if ( V_13 -> V_57 )
return 0 ;
V_13 -> V_57 = F_19 ( V_13 -> V_8 ,
& V_28 ,
V_58 ,
0 , 0 ) ;
if ( ! V_13 -> V_57 ) {
F_3 ( V_13 , V_20 , V_24 ,
L_15
L_17 ) ;
return - V_56 ;
}
return 0 ;
}
void F_21 ( struct V_12 * V_13 )
{
struct V_59 * V_60 ;
if ( ! F_22 ( V_13 , V_61 , & V_60 ) ) {
F_18 ( V_13 ) ;
F_23 ( V_60 ) ;
}
if ( ! F_22 ( V_13 , V_62 , & V_60 ) ) {
F_20 ( V_13 ) ;
F_23 ( V_60 ) ;
}
}
void F_24 ( struct V_12 * V_13 )
{
if ( V_13 -> V_57 )
F_25 ( V_13 -> V_57 ) ;
if ( V_13 -> V_54 )
F_25 ( V_13 -> V_54 ) ;
}
static int
F_26 ( struct V_7 * V_8 ,
struct V_63 * V_64 ,
void * V_65 , T_5 V_66 )
{
struct V_12 * V_13 = F_11 ( V_8 ) ;
struct V_63 * V_67 = NULL ;
struct V_63 * V_68 = NULL ;
struct V_69 * V_70 ;
int V_71 ;
switch ( V_64 -> V_72 ) {
case V_73 :
V_70 = F_27 ( V_65 , V_66 , V_74 ) ;
if ( V_70 )
V_67 = F_28 ( V_70 ) ;
V_70 = F_27 ( V_65 , V_66 , V_75 ) ;
if ( V_70 )
V_68 = F_28 ( V_70 ) ;
break;
case V_74 :
V_67 = V_64 ;
V_70 = F_27 ( V_65 , V_66 , V_75 ) ;
if ( V_70 )
V_68 = F_28 ( V_70 ) ;
break;
case V_75 :
V_68 = V_64 ;
V_70 = F_27 ( V_65 , V_66 , V_74 ) ;
if ( V_70 )
V_67 = F_28 ( V_70 ) ;
break;
default:
F_3 ( V_13 , V_20 , V_24 ,
L_18 ,
V_64 -> V_72 ) ;
}
if ( ! V_67 || ! V_68 ) {
F_3 ( V_13 , V_20 , V_24 ,
L_19 ) ;
return - V_42 ;
}
V_71 = F_29 ( V_13 , V_67 , V_68 ,
V_76 ) ;
return V_71 ;
}
static int
F_30 ( struct V_7 * V_8 ,
struct V_63 * V_64 )
{
struct V_12 * V_13 = F_11 ( V_8 ) ;
int V_71 ;
V_71 = F_31 ( V_13 ) ;
if ( V_71 ) {
F_3 ( V_13 , V_20 , V_24 ,
L_20 ) ;
return V_71 ;
}
switch ( V_64 -> V_72 ) {
case V_77 :
if ( V_64 -> V_78 [ 0 ] != V_79 )
V_71 = F_32 ( V_13 , V_80 ) ;
break;
case V_81 :
V_71 = F_32 ( V_13 ,
* ( ( T_3 * ) V_64 -> V_78 ) ) ;
break;
default:
F_3 ( V_13 , V_82 , V_24 ,
L_21 ,
V_64 -> V_72 ) ;
return - V_83 ;
}
return V_71 ;
}
static int
F_33 ( struct V_7 * V_8 ,
struct V_63 * V_64 ,
void * V_65 , T_5 V_66 )
{
struct V_12 * V_13 = F_11 ( V_8 ) ;
int V_71 = 0 ;
switch ( V_64 -> V_72 ) {
case V_84 :
V_71 = F_34 ( V_13 , V_64 ) ;
break;
case V_73 :
if ( V_64 -> V_78 [ 0 ] == V_85 )
V_71 = F_29 ( V_13 , V_64 ,
NULL , V_85 ) ;
else if ( V_64 -> V_78 [ 0 ] == V_76 )
V_71 = F_26 ( V_8 , V_64 ,
V_65 , V_66 ) ;
else
F_3 ( V_13 , V_20 , V_24 ,
L_22 ,
V_64 -> V_78 [ 0 ] ) ;
break;
case V_86 :
if ( V_64 -> V_78 [ 0 ] == V_87 )
V_71 = F_18 ( V_13 ) ;
else
F_25 ( V_13 -> V_54 ) ;
break;
case V_75 :
case V_74 :
V_71 = F_26 ( V_8 , V_64 ,
V_65 , V_66 ) ;
break;
case V_77 :
case V_81 :
V_71 = F_30 ( V_8 , V_64 ) ;
break;
default:
F_3 ( V_13 , V_20 , V_24 ,
L_23 ,
V_64 -> V_72 ) ;
}
return V_71 ;
}
static int
F_35 ( struct V_7 * V_8 ,
struct V_63 * V_64 ,
void * V_65 , T_5 V_66 )
{
struct V_12 * V_13 = F_11 ( V_8 ) ;
int V_71 = 0 ;
switch ( V_64 -> V_72 ) {
case V_86 :
if ( V_64 -> V_78 [ 0 ] == V_87 )
V_71 = F_20 ( V_13 ) ;
else {
F_25 ( V_13 -> V_57 ) ;
V_71 = 0 ;
}
break;
case V_88 :
V_71 = F_29 ( V_13 , V_64 , NULL ,
V_76 ) ;
break;
case V_77 :
case V_81 :
V_71 = F_30 ( V_8 , V_64 ) ;
break;
default:
F_3 ( V_13 , V_20 , V_24 ,
L_23 ,
V_64 -> V_72 ) ;
}
return V_71 ;
}
int F_36 ( struct V_7 * V_8 ,
void * V_65 , T_5 V_66 )
{
struct V_63 * V_64 = NULL ;
struct V_12 * V_13 = F_11 ( V_8 ) ;
struct V_69 * V_89 ;
T_5 V_90 = V_66 ;
int V_71 = 0 ;
if ( V_13 -> V_22 & V_23 ) {
F_3 ( V_13 , V_20 , V_24 ,
L_24 ) ;
return - V_91 ;
}
F_37 (attrib, data, dt_len, rm_len) {
V_64 = F_28 ( V_89 ) ;
if ( V_64 -> V_92 != V_93 )
continue;
if ( V_64 -> V_94 ) {
F_3 ( V_13 , V_20 , V_24 ,
L_25
L_26 ,
V_64 -> V_94 ) ;
return - V_42 ;
}
switch ( V_64 -> V_95 ) {
case V_55 :
V_71 = F_33 ( V_8 , V_64 ,
V_65 , V_66 ) ;
break;
case V_58 :
V_71 = F_35 ( V_8 , V_64 ,
V_65 , V_66 ) ;
break;
default:
F_3 ( V_13 , V_20 , V_24 ,
L_27 ,
V_64 -> V_95 ) ;
break;
}
if ( V_71 )
return V_71 ;
}
return V_71 ;
}
static int F_38 ( struct V_12 * V_13 ,
struct V_96 * V_97 , int V_72 ,
char * V_98 )
{
struct V_59 * V_60 ;
int V_99 , V_100 = V_61 ;
if ( V_97 -> V_95 == V_58 )
V_100 = V_62 ;
V_99 = F_22 ( V_13 , V_100 , & V_60 ) ;
if ( V_99 )
return V_99 ;
switch ( V_72 ) {
case V_74 :
V_99 = sprintf ( V_98 , L_28 , V_60 -> V_101 . V_102 ) ;
break;
case V_88 :
V_99 = sprintf ( V_98 , L_29 , V_60 -> V_101 . V_102 ) ;
break;
case V_73 :
if ( ! V_60 -> V_103 )
V_99 = sprintf ( V_98 , L_30 ) ;
else
V_99 = sprintf ( V_98 , L_31 ) ;
break;
case V_75 :
V_99 = sprintf ( V_98 , L_28 , V_60 -> V_101 . V_104 ) ;
break;
case V_77 :
V_99 = sprintf ( V_98 , L_32 ,
( V_60 -> V_105 == V_80 )
? L_33 : L_34 ) ;
break;
case V_106 :
if ( V_60 -> V_105 == V_80 )
V_99 = - V_42 ;
else
V_99 = sprintf ( V_98 , L_35 ,
( V_60 -> V_105 &
V_107 ) ) ;
break;
case V_108 :
if ( V_60 -> V_105 == V_80 )
V_99 = - V_42 ;
else
V_99 = sprintf ( V_98 , L_35 ,
( ( V_60 -> V_105 >> 13 ) &
V_109 ) ) ;
break;
default:
F_39 ( 1 ) ;
}
F_23 ( V_60 ) ;
return V_99 ;
}
int F_40 ( struct V_96 * V_97 ,
enum V_110 V_92 ,
int V_72 , char * V_98 )
{
struct V_7 * V_8 = F_41 ( V_97 ) ;
struct V_12 * V_13 = F_11 ( V_8 ) ;
struct V_111 V_112 ;
int V_99 = - V_83 ;
if ( V_13 -> V_22 & V_23 ) {
F_3 ( V_13 , V_20 , V_24 ,
L_24 ) ;
return - V_91 ;
}
switch ( V_72 ) {
case V_74 :
case V_75 :
case V_73 :
case V_88 :
case V_77 :
case V_106 :
case V_108 :
V_99 = F_38 ( V_13 , V_97 , V_72 , V_98 ) ;
break;
case V_86 :
V_99 = sprintf ( V_98 , L_36 ) ;
break;
case V_84 :
memset ( & V_112 , 0 , sizeof( V_112 ) ) ;
V_99 = F_42 ( V_13 , V_61 , & V_112 ) ;
if ( ! V_99 )
V_99 = sprintf ( V_98 , L_28 , & V_112 . V_101 . V_102 ) ;
break;
default:
V_99 = - V_83 ;
}
return V_99 ;
}
int F_43 ( struct V_2 * V_3 ,
enum V_113 V_72 , char * V_98 )
{
struct V_9 * V_10 = V_3 -> V_21 ;
int V_99 = 0 ;
F_3 ( V_10 -> V_13 , V_25 ,
V_24 ,
L_37
L_38 , V_72 ) ;
switch ( V_72 ) {
case V_114 :
V_99 = sprintf ( V_98 , L_39 , V_10 -> V_115 ) ;
break;
case V_116 :
if ( V_10 -> V_100 == V_61 )
V_99 = sprintf ( V_98 , L_28 , & V_10 -> V_117 ) ;
else
V_99 = sprintf ( V_98 , L_29 , & V_10 -> V_118 ) ;
break;
default:
return - V_83 ;
}
return V_99 ;
}
int F_44 ( struct V_34 * V_36 ,
enum V_113 V_72 , char * V_98 , int V_119 )
{
struct V_38 * V_39 = V_36 -> V_21 ;
struct V_14 * V_120 = V_39 -> V_120 ;
struct V_12 * V_13 = NULL ;
int V_71 ;
V_13 = ( (struct V_37 * ) V_39 -> V_21 ) -> V_13 ;
F_3 ( V_13 , V_25 , V_24 ,
L_40
L_38 , V_72 ) ;
V_71 = F_45 ( V_36 , V_72 , V_98 , V_119 ) ;
if ( V_71 )
return V_71 ;
switch ( V_72 ) {
case V_121 :
if ( V_120 -> V_122 > 8192 )
V_120 -> V_122 = 8192 ;
break;
case V_123 :
if ( V_39 -> V_124 > 65536 )
V_39 -> V_124 = 65536 ;
break;
case V_125 :
if ( V_120 -> V_126 > 262144 )
V_120 -> V_126 = 262144 ;
break;
case V_127 :
if ( V_39 -> V_128 > 65536 )
V_39 -> V_128 = 65536 ;
default:
return 0 ;
}
return 0 ;
}
static int F_46 ( char * V_98 , struct V_12 * V_13 )
{
int V_129 ;
unsigned int V_130 ;
struct V_131 * V_132 ;
struct V_133 * V_134 ;
V_130 = F_47 ( V_13 ) ;
if ( ! V_130 ) {
F_3 ( V_13 , V_20 , V_24 ,
L_41 ) ;
return - V_91 ;
}
V_129 = F_48 ( V_13 , V_130 , & V_132 , NULL ) ;
if ( V_129 ) {
F_3 ( V_13 , V_20 ,
V_24 | V_135 ,
L_42 ) ;
return V_129 ;
}
V_134 = F_49 ( V_132 ) ;
V_129 = sprintf ( V_98 , L_32 , V_134 -> V_136 ) ;
return V_129 ;
}
static void F_50 ( struct V_7 * V_8 )
{
struct V_12 * V_13 = F_11 ( V_8 ) ;
struct V_137 * V_138 = V_8 -> V_139 ;
V_138 -> V_140 = ( V_13 -> V_22 & V_141 ) ?
V_142 : V_143 ;
}
static void F_51 ( struct V_7 * V_8 )
{
struct V_12 * V_13 = F_11 ( V_8 ) ;
struct V_137 * V_138 = V_8 -> V_139 ;
switch ( V_13 -> V_144 ) {
case V_145 :
V_138 -> V_144 = V_146 ;
break;
case V_147 :
V_138 -> V_144 = V_148 ;
break;
case V_149 :
V_138 -> V_144 = V_150 ;
break;
case V_151 :
V_138 -> V_144 = V_152 ;
break;
case V_153 :
V_138 -> V_144 = V_154 ;
break;
case V_155 :
V_138 -> V_144 = V_156 ;
break;
default:
V_138 -> V_144 = V_157 ;
}
}
int F_52 ( struct V_7 * V_8 ,
enum V_158 V_72 , char * V_98 )
{
struct V_12 * V_13 = F_11 ( V_8 ) ;
int V_159 = 0 ;
if ( V_13 -> V_22 & V_23 ) {
F_3 ( V_13 , V_20 , V_24 ,
L_24 ) ;
return - V_91 ;
} else {
F_3 ( V_13 , V_25 , V_24 ,
L_43
L_44 , V_72 ) ;
}
switch ( V_72 ) {
case V_160 :
V_159 = F_53 ( V_98 , V_13 ) ;
if ( V_159 < 0 ) {
F_3 ( V_13 , V_20 , V_24 ,
L_45 ) ;
return V_159 ;
}
break;
case V_161 :
V_159 = F_46 ( V_98 , V_13 ) ;
if ( V_159 < 0 ) {
F_3 ( V_13 , V_20 , V_24 ,
L_46 ) ;
return V_159 ;
}
break;
case V_162 :
F_50 ( V_8 ) ;
V_159 = sprintf ( V_98 , L_32 , F_54 ( V_8 ) ) ;
break;
case V_163 :
F_51 ( V_8 ) ;
V_159 = sprintf ( V_98 , L_32 , F_55 ( V_8 ) ) ;
break;
default:
return F_56 ( V_8 , V_72 , V_98 ) ;
}
return V_159 ;
}
int F_53 ( char * V_98 , struct V_12 * V_13 )
{
struct V_164 V_134 ;
int V_129 ;
if ( V_13 -> V_165 )
return F_57 ( V_98 , V_13 -> V_166 , V_167 ) ;
memset ( & V_134 , 0 , sizeof( V_134 ) ) ;
V_129 = F_58 ( V_13 , & V_134 ) ;
if ( V_129 )
return V_129 ;
V_13 -> V_165 = true ;
memcpy ( V_13 -> V_166 , V_134 . V_166 , V_167 ) ;
return F_57 ( V_98 , V_13 -> V_166 , V_167 ) ;
}
void F_59 ( struct V_34 * V_36 ,
struct V_168 * V_169 )
{
struct V_38 * V_39 = V_36 -> V_21 ;
struct V_12 * V_13 = NULL ;
V_13 = ( (struct V_37 * ) V_39 -> V_21 ) -> V_13 ;
F_3 ( V_13 , V_25 , V_24 ,
L_47 ) ;
V_169 -> V_170 = V_39 -> V_170 ;
V_169 -> V_171 = V_39 -> V_171 ;
V_169 -> V_172 = V_39 -> V_173 ;
V_169 -> V_174 = V_39 -> V_175 ;
V_169 -> V_176 = V_39 -> V_177 ;
V_169 -> V_178 = V_39 -> V_179 ;
V_169 -> V_180 = V_39 -> V_181 ;
V_169 -> V_182 = V_39 -> V_183 ;
V_169 -> V_184 = V_39 -> V_185 ;
V_169 -> V_186 = 0 ;
V_169 -> V_187 = 0 ;
V_169 -> V_188 = 1 ;
strcpy ( V_169 -> V_189 [ 0 ] . V_190 , L_48 ) ;
V_169 -> V_189 [ 0 ] . V_78 = V_39 -> V_191 ;
}
static void F_60 ( struct V_37 * V_37 ,
struct V_192 * V_26 )
{
struct V_38 * V_39 = V_37 -> V_39 ;
struct V_14 * V_120 = V_39 -> V_120 ;
F_61 ( struct V_193 , V_194 ,
V_26 , V_120 -> V_126 ) ;
F_61 ( struct V_193 ,
V_195 , V_26 ,
V_39 -> V_128 ) ;
F_61 ( struct V_193 , V_196 ,
V_26 , V_120 -> V_122 ) ;
F_61 ( struct V_193 , V_197 , V_26 ,
V_120 -> V_197 ) ;
F_61 ( struct V_193 , V_198 , V_26 ,
V_39 -> V_199 ) ;
F_61 ( struct V_193 , V_200 , V_26 ,
V_39 -> V_201 ) ;
F_61 ( struct V_193 , V_202 , V_26 ,
V_120 -> V_203 ) ;
F_61 ( struct V_193 , V_204 , V_26 ,
V_120 -> V_205 ) ;
F_61 ( struct V_193 ,
V_206 , V_26 ,
V_120 -> V_207 ) ;
F_61 ( struct V_193 ,
V_208 , V_26 ,
V_120 -> V_209 ) ;
F_61 ( struct V_193 , V_210 , V_26 ,
V_120 -> V_210 ) ;
F_61 ( struct V_193 , V_211 , V_26 ,
( V_39 -> V_211 - 1 ) ) ;
F_61 ( struct V_193 ,
V_212 , V_26 ,
V_39 -> V_124 ) ;
}
int F_62 ( struct V_34 * V_36 )
{
struct V_38 * V_39 = V_36 -> V_21 ;
struct V_37 * V_37 = V_39 -> V_21 ;
struct V_9 * V_10 ;
struct V_192 V_26 ;
struct V_12 * V_13 ;
V_13 = ( (struct V_37 * ) V_39 -> V_21 ) -> V_13 ;
if ( V_13 -> V_22 & V_23 ) {
F_3 ( V_13 , V_20 , V_24 ,
L_24 ) ;
return - V_91 ;
} else {
F_3 ( V_37 -> V_13 , V_25 ,
V_24 ,
L_49 ) ;
}
memset ( & V_26 , 0 , sizeof( struct V_192 ) ) ;
V_10 = V_37 -> V_3 ;
if ( ! V_10 )
F_3 ( V_37 -> V_13 , V_20 ,
V_24 ,
L_50 ) ;
V_37 -> V_213 = 0 ;
F_60 ( V_37 , & V_26 ) ;
F_63 ( V_37 , & V_26 ) ;
F_64 ( V_36 ) ;
return 0 ;
}
static int F_65 ( struct V_12 * V_13 )
{
unsigned short V_35 = 0xFFFF , V_214 ;
struct V_215 * V_216 = NULL ;
T_3 V_217 , V_218 ;
V_217 = ( V_13 -> V_219 [ V_220 ] ) ?
F_66 ( V_13 ) : 0 ;
V_218 = ( V_13 -> V_219 [ V_221 ] ) ?
F_67 ( V_13 ) : 0 ;
V_214 = ( V_217 > V_218 ) ?
V_220 : V_221 ;
if ( F_68 ( V_214 , ( void * ) & V_13 -> V_222 . V_223 ) ) {
V_216 = V_13 -> V_219 [ V_214 ] ;
if ( ! V_216 -> V_224 )
return V_35 ;
V_35 = V_216 -> V_225 [ V_216 -> V_226 ++ ] ;
if ( V_216 -> V_226 == F_69 (
V_13 , V_214 ) )
V_216 -> V_226 = 0 ;
V_216 -> V_224 -- ;
}
return V_35 ;
}
static void F_70 ( struct V_12 * V_13 , unsigned short V_35 )
{
T_3 V_227 ;
struct V_45 * V_46 ;
struct V_47 * V_48 ;
struct V_215 * V_216 = NULL ;
T_3 V_40 = F_14 ( V_35 ) ;
V_46 = V_13 -> V_46 ;
V_48 = & V_46 -> V_50 [ V_40 ] ;
V_227 = V_48 -> V_228 ;
V_216 = V_13 -> V_219 [ V_227 ] ;
V_216 -> V_224 ++ ;
V_216 -> V_225 [ V_216 -> V_229 ++ ] = V_35 ;
if ( V_216 -> V_229 == F_69 ( V_13 , V_227 ) )
V_216 -> V_229 = 0 ;
}
static void F_71 ( struct V_9 * V_10 )
{
struct V_12 * V_13 = V_10 -> V_13 ;
struct V_37 * V_37 ;
F_70 ( V_13 , V_10 -> V_51 ) ;
V_10 -> V_13 = NULL ;
V_13 -> V_230 [ F_14
( V_10 -> V_51 ) ] = NULL ;
if ( ! V_10 -> V_39 )
return;
V_37 = V_10 -> V_39 ;
if ( V_37 -> V_213 ) {
F_72 ( V_37 ,
V_37 -> V_231 ) ;
V_37 -> V_213 = 0 ;
}
}
static int F_73 ( struct V_2 * V_3 ,
struct V_232 * V_233 ,
struct V_232 * V_117 , int V_234 )
{
struct V_9 * V_10 = V_3 -> V_21 ;
struct V_12 * V_13 = V_10 -> V_13 ;
struct V_235 * V_236 ;
struct V_237 V_238 ;
unsigned int V_130 , V_239 ;
int V_71 = - V_240 ;
F_3 ( V_13 , V_25 , V_24 ,
L_51 ) ;
V_10 -> V_51 = F_65 ( V_13 ) ;
if ( V_10 -> V_51 == 0xFFFF ) {
F_3 ( V_13 , V_20 , V_24 ,
L_52 ) ;
return V_71 ;
}
F_3 ( V_13 , V_25 , V_24 ,
L_53 ,
V_10 -> V_51 ) ;
V_13 -> V_230 [ F_14
( V_10 -> V_51 ) ] = V_3 ;
V_10 -> V_241 = 0 ;
if ( F_74 ( V_13 ) )
V_239 = sizeof( struct V_242 ) ;
else
V_239 = sizeof( struct V_243 ) ;
V_238 . V_244 = F_75 ( V_13 -> V_245 . V_246 ,
V_239 ,
& V_238 . V_247 ) ;
if ( V_238 . V_244 == NULL ) {
F_3 ( V_13 , V_20 , V_24 ,
L_54
L_55 ) ;
F_71 ( V_10 ) ;
return - V_240 ;
}
V_238 . V_248 = V_239 ;
memset ( V_238 . V_244 , 0 , V_238 . V_248 ) ;
V_130 = F_76 ( V_13 , V_117 , V_10 , & V_238 ) ;
if ( V_130 <= 0 ) {
F_3 ( V_13 , V_20 , V_24 ,
L_56 ,
V_10 -> V_51 ) ;
F_77 ( V_13 -> V_245 . V_246 , V_238 . V_248 ,
V_238 . V_244 , V_238 . V_247 ) ;
F_71 ( V_10 ) ;
return - V_249 ;
}
V_71 = F_48 ( V_13 , V_130 , NULL , & V_238 ) ;
if ( V_71 ) {
F_3 ( V_13 , V_20 ,
V_24 | V_135 ,
L_57 ) ;
if ( V_71 != - V_91 )
F_77 ( V_13 -> V_245 . V_246 , V_238 . V_248 ,
V_238 . V_244 , V_238 . V_247 ) ;
F_71 ( V_10 ) ;
return V_71 ;
}
V_236 = (struct V_235 * ) V_238 . V_244 ;
V_10 = V_3 -> V_21 ;
V_10 -> V_250 = V_236 -> V_251 ;
V_10 -> V_241 = 1 ;
F_3 ( V_13 , V_25 , V_24 ,
L_58 ) ;
F_77 ( V_13 -> V_245 . V_246 , V_238 . V_248 ,
V_238 . V_244 , V_238 . V_247 ) ;
return 0 ;
}
struct V_2 *
F_78 ( struct V_7 * V_8 , struct V_232 * V_117 ,
int V_234 )
{
struct V_12 * V_13 ;
struct V_9 * V_10 ;
struct V_2 * V_3 ;
int V_71 ;
if ( V_8 )
V_13 = F_11 ( V_8 ) ;
else {
V_71 = - V_252 ;
F_2 ( V_20
L_59 ) ;
return F_79 ( V_71 ) ;
}
if ( F_80 ( V_13 ) ) {
V_71 = - V_253 ;
F_3 ( V_13 , V_82 , V_24 ,
L_60 ) ;
return F_79 ( V_71 ) ;
}
if ( V_13 -> V_22 & V_23 ) {
V_71 = - V_91 ;
F_3 ( V_13 , V_20 , V_24 ,
L_24 ) ;
return F_79 ( V_71 ) ;
} else if ( V_13 -> V_22 & V_254 ) {
V_71 = - V_91 ;
F_3 ( V_13 , V_82 , V_24 ,
L_61 ) ;
return F_79 ( V_71 ) ;
}
V_3 = F_81 ( sizeof( struct V_9 ) ) ;
if ( ! V_3 ) {
V_71 = - V_240 ;
return F_79 ( V_71 ) ;
}
V_10 = V_3 -> V_21 ;
V_10 -> V_13 = V_13 ;
V_10 -> V_255 = V_3 ;
V_71 = F_73 ( V_3 , NULL , V_117 , V_234 ) ;
if ( V_71 ) {
F_3 ( V_13 , V_20 , V_24 ,
L_62 ) ;
goto V_256;
}
return V_3 ;
V_256:
F_82 ( V_3 ) ;
return F_79 ( V_71 ) ;
}
int F_83 ( struct V_2 * V_3 , int V_257 )
{
struct V_9 * V_10 = V_3 -> V_21 ;
F_3 ( V_10 -> V_13 , V_25 , V_24 ,
L_63 ) ;
if ( V_10 -> V_241 == 1 )
return 1 ;
else
return 0 ;
}
static void F_84 ( struct V_12 * V_13 )
{
T_3 V_258 ;
struct V_259 * V_260 ;
struct V_45 * V_46 ;
struct V_261 * V_262 ;
V_46 = V_13 -> V_46 ;
V_262 = V_46 -> V_263 ;
for ( V_258 = 0 ; V_258 < V_13 -> V_264 ; V_258 ++ ) {
V_260 = & V_262 -> V_265 [ V_258 ] ;
F_85 ( & V_260 -> V_266 ) ;
F_86 ( V_260 , V_267 ) ;
F_87 ( & V_260 -> V_266 ) ;
}
}
static int F_88 ( struct V_9 * V_10 , int V_268 )
{
int V_71 = 0 ;
unsigned int V_130 ;
struct V_12 * V_13 = V_10 -> V_13 ;
V_130 = F_89 ( V_13 , V_10 -> V_51 , V_268 ) ;
if ( ! V_130 ) {
F_3 ( V_13 , V_25 , V_24 ,
L_64 ,
V_10 -> V_51 ) ;
V_71 = - V_249 ;
}
V_71 = F_48 ( V_13 , V_130 , NULL , NULL ) ;
F_84 ( V_13 ) ;
return V_71 ;
}
static int F_90 ( struct V_12 * V_13 ,
unsigned int V_35 )
{
T_3 V_40 = F_14 ( V_35 ) ;
if ( V_13 -> V_41 [ V_40 ] )
V_13 -> V_41 [ V_40 ] = NULL ;
else {
F_3 ( V_13 , V_25 , V_24 ,
L_65 ) ;
return - V_42 ;
}
return 0 ;
}
void F_91 ( struct V_2 * V_3 )
{
struct V_37 * V_37 ;
struct V_9 * V_10 ;
struct V_12 * V_13 ;
unsigned int V_130 ;
T_6 V_269 , V_270 ;
unsigned short V_271 = V_272 ;
V_10 = V_3 -> V_21 ;
V_13 = V_10 -> V_13 ;
F_3 ( V_13 , V_25 , V_24 ,
L_66 ,
V_10 -> V_51 ) ;
if ( V_10 -> V_39 ) {
V_37 = V_10 -> V_39 ;
F_92 ( V_37 -> V_39 ) ;
V_269 = ~ V_273 ;
V_270 = V_274 ;
} else {
V_269 = V_273 ;
V_270 = V_275 ;
}
if ( V_13 -> V_22 & V_23 ) {
F_3 ( V_13 , V_20 , V_24 ,
L_2 ) ;
goto V_256;
}
V_130 = F_93 ( V_13 , V_10 ,
V_10 -> V_51 ,
V_269 ,
V_271 ) ;
if ( ! V_130 ) {
F_3 ( V_13 , V_20 , V_24 ,
L_67 ,
V_10 -> V_51 ) ;
}
F_48 ( V_13 , V_130 , NULL , NULL ) ;
F_88 ( V_10 , V_270 ) ;
V_256:
F_94 ( V_276 ) ;
F_71 ( V_10 ) ;
F_90 ( V_13 , V_10 -> V_51 ) ;
F_82 ( V_10 -> V_255 ) ;
}
T_7 F_95 ( int V_92 , int V_72 )
{
switch ( V_92 ) {
case V_93 :
switch ( V_72 ) {
case V_86 :
case V_74 :
case V_75 :
case V_73 :
case V_84 :
case V_88 :
case V_106 :
case V_108 :
case V_77 :
return V_277 ;
default:
return 0 ;
}
case V_278 :
switch ( V_72 ) {
case V_160 :
case V_161 :
case V_162 :
case V_163 :
return V_277 ;
default:
return 0 ;
}
case V_279 :
switch ( V_72 ) {
case V_123 :
case V_127 :
case V_280 :
case V_281 :
case V_116 :
case V_114 :
case V_282 :
case V_283 :
case V_284 :
case V_285 :
case V_286 :
case V_287 :
case V_288 :
case V_289 :
case V_121 :
case V_125 :
case V_290 :
case V_291 :
case V_292 :
case V_293 :
case V_294 :
case V_295 :
case V_296 :
case V_297 :
case V_298 :
case V_299 :
case V_300 :
case V_301 :
case V_302 :
case V_303 :
return V_277 ;
default:
return 0 ;
}
}
return 0 ;
}
