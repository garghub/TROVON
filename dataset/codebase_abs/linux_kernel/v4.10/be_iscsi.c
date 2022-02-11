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
F_2 ( L_1 ) ;
return NULL ;
}
V_10 = V_3 -> V_20 ;
V_13 = V_10 -> V_13 ;
if ( ! F_3 ( V_13 ) ) {
F_4 ( V_13 , V_21 , V_22 ,
L_2 , V_13 -> V_23 ) ;
return NULL ;
}
F_4 ( V_13 , V_21 , V_22 ,
L_3 ) ;
if ( V_4 > V_10 -> V_13 -> V_24 . V_25 ) {
F_4 ( V_13 , V_26 , V_22 ,
L_4
L_5
L_6 , V_4 ,
V_10 -> V_13 -> V_24 . V_25 ,
V_10 -> V_13 -> V_24 . V_25 ) ;
V_4 = V_10 -> V_13 -> V_24 . V_25 ;
}
V_8 = V_13 -> V_8 ;
V_11 = F_5 ( & V_27 ,
V_8 , V_4 ,
sizeof( * V_17 ) ,
sizeof( * V_19 ) ,
V_6 , V_28 ) ;
if ( ! V_11 )
return NULL ;
V_15 = V_11 -> V_20 ;
V_17 = V_15 -> V_20 ;
V_17 -> V_29 = F_6 ( L_7 ,
V_13 -> V_30 ,
sizeof( struct V_31 ) ,
64 , 0 ) ;
if ( ! V_17 -> V_29 )
goto V_32;
return V_11 ;
V_32:
F_7 ( V_11 ) ;
return NULL ;
}
void F_8 ( struct V_1 * V_11 )
{
struct V_14 * V_15 = V_11 -> V_20 ;
struct V_16 * V_17 = V_15 -> V_20 ;
F_9 ( V_21 L_8 ) ;
F_10 ( V_17 -> V_29 ) ;
F_7 ( V_11 ) ;
}
void F_11 ( struct V_1 * V_11 )
{
F_12 ( V_11 -> V_20 , V_33 ) ;
}
struct V_34 *
F_13 ( struct V_1 * V_11 , T_2 V_35 )
{
struct V_12 * V_13 ;
struct V_7 * V_8 ;
struct V_34 * V_36 ;
struct V_37 * V_37 ;
struct V_38 * V_39 ;
struct V_14 * V_15 ;
struct V_16 * V_17 ;
V_8 = F_14 ( V_11 ) ;
V_13 = F_15 ( V_8 ) ;
F_4 ( V_13 , V_21 , V_22 ,
L_9
L_10 , V_35 ) ;
V_36 = F_16 ( V_11 , sizeof( * V_37 ) , V_35 ) ;
if ( ! V_36 )
return NULL ;
V_39 = V_36 -> V_20 ;
V_37 = V_39 -> V_20 ;
V_37 -> V_3 = NULL ;
V_37 -> V_13 = V_13 ;
V_37 -> V_39 = V_39 ;
V_15 = V_11 -> V_20 ;
V_17 = V_15 -> V_20 ;
V_37 -> V_17 = V_17 ;
return V_36 ;
}
static int F_17 ( struct V_12 * V_13 ,
struct V_37 * V_37 ,
unsigned int V_35 )
{
T_3 V_40 = F_18 ( V_35 ) ;
if ( V_13 -> V_41 [ V_40 ] ) {
F_4 ( V_13 , V_26 , V_22 ,
L_11 ) ;
return - V_42 ;
} else {
F_4 ( V_13 , V_21 , V_22 ,
L_12 ,
V_40 , V_37 ) ;
V_13 -> V_41 [ V_40 ] = V_37 ;
}
return 0 ;
}
int F_19 ( struct V_1 * V_11 ,
struct V_34 * V_36 ,
T_4 V_43 , int V_44 )
{
struct V_38 * V_39 = V_36 -> V_20 ;
struct V_37 * V_37 = V_39 -> V_20 ;
struct V_7 * V_8 = F_14 ( V_11 ) ;
struct V_12 * V_13 = F_15 ( V_8 ) ;
struct V_45 * V_46 = V_13 -> V_46 ;
struct V_47 * V_48 ;
struct V_9 * V_10 ;
struct V_2 * V_3 ;
V_3 = F_20 ( V_43 ) ;
if ( ! V_3 )
return - V_42 ;
V_10 = V_3 -> V_20 ;
if ( F_21 ( V_11 , V_36 , V_44 ) )
return - V_42 ;
if ( V_10 -> V_13 != V_13 ) {
F_4 ( V_13 , V_26 , V_22 ,
L_13 ,
V_10 -> V_13 , V_13 ) ;
return - V_49 ;
}
V_48 = & V_46 -> V_50 [ F_18 (
V_10 -> V_51 ) ] ;
V_37 -> V_52 = V_10 -> V_51 ;
V_37 -> V_3 = V_10 ;
V_10 -> V_39 = V_37 ;
V_37 -> V_53 = V_48 -> V_53 ;
F_4 ( V_13 , V_21 , V_22 ,
L_14 ,
V_37 , V_39 , V_10 -> V_51 ) ;
return F_17 ( V_13 , V_37 , V_10 -> V_51 ) ;
}
static int F_22 ( struct V_12 * V_13 )
{
if ( V_13 -> V_54 )
return 0 ;
V_13 -> V_54 = F_23 ( V_13 -> V_8 ,
& V_27 ,
V_55 ,
0 , 0 ) ;
if ( ! V_13 -> V_54 ) {
F_4 ( V_13 , V_26 , V_22 ,
L_15
L_16 ) ;
return - V_56 ;
}
return 0 ;
}
static int F_24 ( struct V_12 * V_13 )
{
if ( V_13 -> V_57 )
return 0 ;
V_13 -> V_57 = F_23 ( V_13 -> V_8 ,
& V_27 ,
V_58 ,
0 , 0 ) ;
if ( ! V_13 -> V_57 ) {
F_4 ( V_13 , V_26 , V_22 ,
L_15
L_17 ) ;
return - V_56 ;
}
return 0 ;
}
void F_25 ( struct V_12 * V_13 )
{
struct V_59 * V_60 ;
if ( ! F_26 ( V_13 , V_61 , & V_60 ) ) {
F_22 ( V_13 ) ;
F_27 ( V_60 ) ;
}
if ( ! F_26 ( V_13 , V_62 , & V_60 ) ) {
F_24 ( V_13 ) ;
F_27 ( V_60 ) ;
}
}
void F_28 ( struct V_12 * V_13 )
{
if ( V_13 -> V_57 ) {
F_29 ( V_13 -> V_57 ) ;
V_13 -> V_57 = NULL ;
}
if ( V_13 -> V_54 ) {
F_29 ( V_13 -> V_54 ) ;
V_13 -> V_54 = NULL ;
}
}
static int
F_30 ( struct V_7 * V_8 ,
struct V_63 * V_64 )
{
struct V_12 * V_13 = F_15 ( V_8 ) ;
int V_65 = - V_66 ;
switch ( V_64 -> V_67 ) {
case V_68 :
V_65 = 0 ;
if ( V_64 -> V_69 [ 0 ] != V_70 )
V_65 = F_31 ( V_13 , V_71 ) ;
break;
case V_72 :
V_65 = F_31 ( V_13 ,
* ( ( T_3 * ) V_64 -> V_69 ) ) ;
break;
}
return V_65 ;
}
static int
F_32 ( struct V_7 * V_8 ,
struct V_63 * V_73 ,
void * V_74 , T_5 V_75 )
{
struct V_12 * V_13 = F_15 ( V_8 ) ;
T_6 * V_76 = NULL , * V_77 = NULL , * V_78 ;
struct V_79 * V_80 ;
int V_65 = - V_66 ;
switch ( V_73 -> V_67 ) {
case V_81 :
if ( V_73 -> V_69 [ 0 ] == V_82 )
V_65 = F_22 ( V_13 ) ;
else {
F_29 ( V_13 -> V_54 ) ;
V_13 -> V_54 = NULL ;
}
break;
case V_83 :
V_78 = V_73 -> V_69 ;
V_65 = F_33 ( V_13 , V_61 , V_78 ) ;
break;
case V_84 :
if ( V_73 -> V_69 [ 0 ] == V_85 )
V_65 = F_34 ( V_13 , V_61 ) ;
else if ( V_73 -> V_69 [ 0 ] == V_86 )
V_65 = F_35 ( V_13 , V_61 ,
NULL , NULL ) ;
else
F_4 ( V_13 , V_26 , V_22 ,
L_18 ,
V_73 -> V_69 [ 0 ] ) ;
break;
case V_87 :
V_76 = V_73 -> V_69 ;
V_80 = F_36 ( V_74 , V_75 , V_88 ) ;
if ( V_80 ) {
V_73 = F_37 ( V_80 ) ;
V_77 = V_73 -> V_69 ;
}
V_65 = F_35 ( V_13 , V_61 ,
V_76 , V_77 ) ;
break;
case V_88 :
V_77 = V_73 -> V_69 ;
V_80 = F_36 ( V_74 , V_75 , V_87 ) ;
if ( V_80 ) {
V_73 = F_37 ( V_80 ) ;
V_76 = V_73 -> V_69 ;
}
V_65 = F_35 ( V_13 , V_61 ,
V_76 , V_77 ) ;
break;
}
return V_65 ;
}
static int
F_38 ( struct V_7 * V_8 ,
struct V_63 * V_64 ,
void * V_74 , T_5 V_75 )
{
struct V_12 * V_13 = F_15 ( V_8 ) ;
int V_65 = - V_66 ;
switch ( V_64 -> V_67 ) {
case V_81 :
if ( V_64 -> V_69 [ 0 ] == V_82 )
V_65 = F_24 ( V_13 ) ;
else {
F_29 ( V_13 -> V_57 ) ;
V_13 -> V_57 = NULL ;
}
break;
case V_89 :
V_65 = F_35 ( V_13 , V_62 ,
V_64 -> V_69 , NULL ) ;
break;
}
return V_65 ;
}
int F_39 ( struct V_7 * V_8 ,
void * V_74 , T_5 V_75 )
{
struct V_63 * V_64 = NULL ;
struct V_12 * V_13 = F_15 ( V_8 ) ;
struct V_79 * V_90 ;
T_5 V_91 = V_75 ;
int V_65 ;
if ( ! F_3 ( V_13 ) ) {
F_4 ( V_13 , V_21 , V_22 ,
L_2 , V_13 -> V_23 ) ;
return - V_92 ;
}
V_65 = F_40 ( V_13 ) ;
if ( V_65 ) {
F_4 ( V_13 , V_26 , V_22 ,
L_19 ) ;
return V_65 ;
}
F_41 (attrib, data, dt_len, rm_len) {
V_64 = F_37 ( V_90 ) ;
if ( V_64 -> V_93 != V_94 )
continue;
if ( V_64 -> V_95 ) {
F_4 ( V_13 , V_26 , V_22 ,
L_20
L_21 ,
V_64 -> V_95 ) ;
return - V_42 ;
}
F_4 ( V_13 , V_21 , V_22 ,
L_22 ,
( V_64 -> V_96 == V_55 ) ?
L_23 : L_24 , V_64 -> V_67 ) ;
V_65 = - V_66 ;
switch ( V_64 -> V_67 ) {
case V_68 :
case V_72 :
V_65 = F_30 ( V_8 , V_64 ) ;
break;
default:
switch ( V_64 -> V_96 ) {
case V_55 :
V_65 = F_32 ( V_8 ,
V_64 ,
V_74 , V_75 ) ;
break;
case V_58 :
V_65 = F_38 ( V_8 ,
V_64 ,
V_74 , V_75 ) ;
break;
}
}
if ( V_65 == - V_66 ) {
F_42 ( V_13 , V_26 ,
L_25 ,
( V_64 -> V_96 ==
V_55 ) ? L_23 : L_24 ,
V_64 -> V_67 ) ;
V_65 = 0 ;
}
if ( V_65 )
break;
}
return V_65 ;
}
static int F_43 ( struct V_12 * V_13 ,
struct V_97 * V_98 ,
int V_67 , char * V_99 )
{
struct V_59 * V_60 ;
int V_100 , V_101 = V_61 ;
if ( V_98 -> V_96 == V_58 )
V_101 = V_62 ;
V_100 = F_26 ( V_13 , V_101 , & V_60 ) ;
if ( V_100 )
return V_100 ;
switch ( V_67 ) {
case V_87 :
V_100 = sprintf ( V_99 , L_26 , V_60 -> V_102 . V_103 ) ;
break;
case V_89 :
V_100 = sprintf ( V_99 , L_27 , V_60 -> V_102 . V_103 ) ;
break;
case V_84 :
if ( ! V_60 -> V_104 )
V_100 = sprintf ( V_99 , L_28 ) ;
else
V_100 = sprintf ( V_99 , L_29 ) ;
break;
case V_88 :
V_100 = sprintf ( V_99 , L_26 , V_60 -> V_102 . V_105 ) ;
break;
case V_68 :
V_100 = sprintf ( V_99 , L_30 ,
( V_60 -> V_106 == V_71 ) ?
L_31 : L_32 ) ;
break;
case V_107 :
if ( V_60 -> V_106 == V_71 )
V_100 = - V_42 ;
else
V_100 = sprintf ( V_99 , L_33 ,
( V_60 -> V_106 &
V_108 ) ) ;
break;
case V_109 :
if ( V_60 -> V_106 == V_71 )
V_100 = - V_42 ;
else
V_100 = sprintf ( V_99 , L_33 ,
( ( V_60 -> V_106 >> 13 ) &
V_110 ) ) ;
break;
default:
F_44 ( 1 ) ;
}
F_27 ( V_60 ) ;
return V_100 ;
}
int F_45 ( struct V_97 * V_98 ,
enum V_111 V_93 ,
int V_67 , char * V_99 )
{
struct V_7 * V_8 = F_46 ( V_98 ) ;
struct V_12 * V_13 = F_15 ( V_8 ) ;
struct V_112 V_113 ;
int V_100 = - V_66 ;
if ( V_93 != V_94 )
return 0 ;
if ( ! F_3 ( V_13 ) ) {
F_4 ( V_13 , V_21 , V_22 ,
L_2 , V_13 -> V_23 ) ;
return - V_92 ;
}
switch ( V_67 ) {
case V_87 :
case V_88 :
case V_84 :
case V_89 :
case V_68 :
case V_107 :
case V_109 :
V_100 = F_43 ( V_13 , V_98 , V_67 , V_99 ) ;
break;
case V_81 :
if ( V_98 -> V_96 == V_55 )
V_100 = sprintf ( V_99 , L_30 ,
V_13 -> V_54 ? L_32 : L_31 ) ;
else if ( V_98 -> V_96 == V_58 )
V_100 = sprintf ( V_99 , L_30 ,
V_13 -> V_57 ? L_32 : L_31 ) ;
break;
case V_83 :
memset ( & V_113 , 0 , sizeof( V_113 ) ) ;
V_100 = F_47 ( V_13 , V_61 , & V_113 ) ;
if ( ! V_100 )
V_100 = sprintf ( V_99 , L_26 , & V_113 . V_102 . V_103 ) ;
break;
}
return V_100 ;
}
int F_48 ( struct V_2 * V_3 ,
enum V_114 V_67 , char * V_99 )
{
struct V_9 * V_10 = V_3 -> V_20 ;
int V_100 ;
F_4 ( V_10 -> V_13 , V_21 ,
V_22 ,
L_34
L_35 , V_67 ) ;
switch ( V_67 ) {
case V_115 :
V_100 = sprintf ( V_99 , L_36 , V_10 -> V_116 ) ;
break;
case V_117 :
if ( V_10 -> V_101 == V_61 )
V_100 = sprintf ( V_99 , L_26 , & V_10 -> V_118 ) ;
else
V_100 = sprintf ( V_99 , L_27 , & V_10 -> V_119 ) ;
break;
default:
V_100 = - V_66 ;
}
return V_100 ;
}
int F_49 ( struct V_34 * V_36 ,
enum V_114 V_67 , char * V_99 , int V_120 )
{
struct V_38 * V_39 = V_36 -> V_20 ;
struct V_14 * V_121 = V_39 -> V_121 ;
struct V_12 * V_13 = NULL ;
int V_65 ;
V_13 = ( (struct V_37 * ) V_39 -> V_20 ) -> V_13 ;
F_4 ( V_13 , V_21 , V_22 ,
L_37
L_35 , V_67 ) ;
V_65 = F_50 ( V_36 , V_67 , V_99 , V_120 ) ;
if ( V_65 )
return V_65 ;
switch ( V_67 ) {
case V_122 :
if ( V_121 -> V_123 > 8192 )
V_121 -> V_123 = 8192 ;
break;
case V_124 :
if ( V_39 -> V_125 > 65536 )
V_39 -> V_125 = 65536 ;
break;
case V_126 :
if ( V_121 -> V_127 > 262144 )
V_121 -> V_127 = 262144 ;
break;
case V_128 :
if ( V_39 -> V_129 > 65536 )
V_39 -> V_129 = 65536 ;
default:
return 0 ;
}
return 0 ;
}
static int F_51 ( char * V_99 , struct V_12 * V_13 )
{
int V_130 ;
unsigned int V_131 ;
struct V_132 * V_133 ;
struct V_134 * V_135 ;
V_131 = F_52 ( V_13 ) ;
if ( ! V_131 ) {
F_4 ( V_13 , V_26 , V_22 ,
L_38 ) ;
return - V_92 ;
}
V_130 = F_53 ( V_13 , V_131 , & V_133 , NULL ) ;
if ( V_130 ) {
F_4 ( V_13 , V_26 ,
V_22 | V_136 ,
L_39 ) ;
return V_130 ;
}
V_135 = F_54 ( V_133 ) ;
V_130 = sprintf ( V_99 , L_30 , V_135 -> V_137 ) ;
return V_130 ;
}
static void F_55 ( struct V_7 * V_8 )
{
struct V_12 * V_13 = F_15 ( V_8 ) ;
struct V_138 * V_139 = V_8 -> V_140 ;
V_139 -> V_141 = F_56 ( V_142 , & V_13 -> V_23 ) ?
V_143 : V_144 ;
}
static void F_57 ( struct V_7 * V_8 )
{
struct V_12 * V_13 = F_15 ( V_8 ) ;
struct V_138 * V_139 = V_8 -> V_140 ;
switch ( V_13 -> V_145 ) {
case V_146 :
V_139 -> V_145 = V_147 ;
break;
case V_148 :
V_139 -> V_145 = V_149 ;
break;
case V_150 :
V_139 -> V_145 = V_151 ;
break;
case V_152 :
V_139 -> V_145 = V_153 ;
break;
case V_154 :
V_139 -> V_145 = V_155 ;
break;
case V_156 :
V_139 -> V_145 = V_157 ;
break;
default:
V_139 -> V_145 = V_158 ;
}
}
int F_58 ( struct V_7 * V_8 ,
enum V_159 V_67 , char * V_99 )
{
struct V_12 * V_13 = F_15 ( V_8 ) ;
int V_160 = 0 ;
if ( ! F_3 ( V_13 ) ) {
F_4 ( V_13 , V_21 , V_22 ,
L_2 , V_13 -> V_23 ) ;
return - V_92 ;
}
F_4 ( V_13 , V_21 , V_22 ,
L_40 , V_67 ) ;
switch ( V_67 ) {
case V_161 :
V_160 = F_59 ( V_99 , V_13 ) ;
if ( V_160 < 0 ) {
F_4 ( V_13 , V_26 , V_22 ,
L_41 ) ;
return V_160 ;
}
break;
case V_162 :
V_160 = F_51 ( V_99 , V_13 ) ;
if ( V_160 < 0 ) {
F_4 ( V_13 , V_26 , V_22 ,
L_42 ) ;
return V_160 ;
}
break;
case V_163 :
F_55 ( V_8 ) ;
V_160 = sprintf ( V_99 , L_30 , F_60 ( V_8 ) ) ;
break;
case V_164 :
F_57 ( V_8 ) ;
V_160 = sprintf ( V_99 , L_30 , F_61 ( V_8 ) ) ;
break;
default:
return F_62 ( V_8 , V_67 , V_99 ) ;
}
return V_160 ;
}
int F_59 ( char * V_99 , struct V_12 * V_13 )
{
struct V_165 V_135 ;
int V_130 ;
if ( V_13 -> V_166 )
return F_63 ( V_99 , V_13 -> V_167 , V_168 ) ;
memset ( & V_135 , 0 , sizeof( V_135 ) ) ;
V_130 = F_64 ( V_13 , & V_135 ) ;
if ( V_130 )
return V_130 ;
V_13 -> V_166 = true ;
memcpy ( V_13 -> V_167 , V_135 . V_167 , V_168 ) ;
return F_63 ( V_99 , V_13 -> V_167 , V_168 ) ;
}
void F_65 ( struct V_34 * V_36 ,
struct V_169 * V_170 )
{
struct V_38 * V_39 = V_36 -> V_20 ;
struct V_12 * V_13 = NULL ;
V_13 = ( (struct V_37 * ) V_39 -> V_20 ) -> V_13 ;
F_4 ( V_13 , V_21 , V_22 ,
L_43 ) ;
V_170 -> V_171 = V_39 -> V_171 ;
V_170 -> V_172 = V_39 -> V_172 ;
V_170 -> V_173 = V_39 -> V_174 ;
V_170 -> V_175 = V_39 -> V_176 ;
V_170 -> V_177 = V_39 -> V_178 ;
V_170 -> V_179 = V_39 -> V_180 ;
V_170 -> V_181 = V_39 -> V_182 ;
V_170 -> V_183 = V_39 -> V_184 ;
V_170 -> V_185 = V_39 -> V_186 ;
V_170 -> V_187 = 0 ;
V_170 -> V_188 = 0 ;
V_170 -> V_189 = 1 ;
strcpy ( V_170 -> V_190 [ 0 ] . V_191 , L_44 ) ;
V_170 -> V_190 [ 0 ] . V_69 = V_39 -> V_192 ;
}
static void F_66 ( struct V_37 * V_37 ,
struct V_193 * V_24 )
{
struct V_38 * V_39 = V_37 -> V_39 ;
struct V_14 * V_121 = V_39 -> V_121 ;
F_67 ( struct V_194 , V_195 ,
V_24 , V_121 -> V_127 ) ;
F_67 ( struct V_194 ,
V_196 , V_24 ,
V_39 -> V_129 ) ;
F_67 ( struct V_194 , V_197 ,
V_24 , V_121 -> V_123 ) ;
F_67 ( struct V_194 , V_198 , V_24 ,
V_121 -> V_198 ) ;
F_67 ( struct V_194 , V_199 , V_24 ,
V_39 -> V_200 ) ;
F_67 ( struct V_194 , V_201 , V_24 ,
V_39 -> V_202 ) ;
F_67 ( struct V_194 , V_203 , V_24 ,
V_121 -> V_204 ) ;
F_67 ( struct V_194 , V_205 , V_24 ,
V_121 -> V_206 ) ;
F_67 ( struct V_194 ,
V_207 , V_24 ,
V_121 -> V_208 ) ;
F_67 ( struct V_194 ,
V_209 , V_24 ,
V_121 -> V_210 ) ;
F_67 ( struct V_194 , V_211 , V_24 ,
V_121 -> V_211 ) ;
F_67 ( struct V_194 , V_212 , V_24 ,
( V_39 -> V_212 - 1 ) ) ;
F_67 ( struct V_194 ,
V_213 , V_24 ,
V_39 -> V_125 ) ;
}
int F_68 ( struct V_34 * V_36 )
{
struct V_38 * V_39 = V_36 -> V_20 ;
struct V_37 * V_37 = V_39 -> V_20 ;
struct V_9 * V_10 ;
struct V_193 V_24 ;
struct V_12 * V_13 ;
V_13 = ( (struct V_37 * ) V_39 -> V_20 ) -> V_13 ;
if ( ! F_3 ( V_13 ) ) {
F_4 ( V_13 , V_21 , V_22 ,
L_2 , V_13 -> V_23 ) ;
return - V_92 ;
}
F_4 ( V_37 -> V_13 , V_21 , V_22 ,
L_45 ) ;
memset ( & V_24 , 0 , sizeof( struct V_193 ) ) ;
V_10 = V_37 -> V_3 ;
if ( ! V_10 )
F_4 ( V_37 -> V_13 , V_26 ,
V_22 ,
L_46 ) ;
V_37 -> V_214 = 0 ;
F_66 ( V_37 , & V_24 ) ;
F_69 ( V_37 , & V_24 ) ;
F_70 ( V_36 ) ;
return 0 ;
}
static int F_71 ( struct V_12 * V_13 )
{
unsigned short V_35 = 0xFFFF , V_215 ;
struct V_216 * V_217 = NULL ;
T_3 V_218 , V_219 ;
V_218 = ( V_13 -> V_220 [ V_221 ] ) ?
F_72 ( V_13 ) : 0 ;
V_219 = ( V_13 -> V_220 [ V_222 ] ) ?
F_73 ( V_13 ) : 0 ;
V_215 = ( V_218 > V_219 ) ?
V_221 : V_222 ;
if ( F_56 ( V_215 , ( void * ) & V_13 -> V_223 . V_224 ) ) {
V_217 = V_13 -> V_220 [ V_215 ] ;
if ( ! V_217 -> V_225 )
return V_35 ;
V_35 = V_217 -> V_226 [ V_217 -> V_227 ++ ] ;
if ( V_217 -> V_227 == F_74 (
V_13 , V_215 ) )
V_217 -> V_227 = 0 ;
V_217 -> V_225 -- ;
}
return V_35 ;
}
static void F_75 ( struct V_12 * V_13 , unsigned short V_35 )
{
T_3 V_228 ;
struct V_45 * V_46 ;
struct V_47 * V_48 ;
struct V_216 * V_217 = NULL ;
T_3 V_40 = F_18 ( V_35 ) ;
V_46 = V_13 -> V_46 ;
V_48 = & V_46 -> V_50 [ V_40 ] ;
V_228 = V_48 -> V_229 ;
V_217 = V_13 -> V_220 [ V_228 ] ;
V_217 -> V_225 ++ ;
V_217 -> V_226 [ V_217 -> V_230 ++ ] = V_35 ;
if ( V_217 -> V_230 == F_74 ( V_13 , V_228 ) )
V_217 -> V_230 = 0 ;
}
static void F_76 ( struct V_9 * V_10 )
{
struct V_12 * V_13 = V_10 -> V_13 ;
struct V_37 * V_37 ;
F_75 ( V_13 , V_10 -> V_51 ) ;
V_10 -> V_13 = NULL ;
V_13 -> V_231 [ F_18
( V_10 -> V_51 ) ] = NULL ;
if ( ! V_10 -> V_39 )
return;
V_37 = V_10 -> V_39 ;
if ( V_37 -> V_214 ) {
F_77 ( V_37 ,
V_37 -> V_232 ) ;
V_37 -> V_214 = 0 ;
}
}
static int F_78 ( struct V_2 * V_3 ,
struct V_233 * V_234 ,
struct V_233 * V_118 , int V_235 )
{
struct V_9 * V_10 = V_3 -> V_20 ;
struct V_12 * V_13 = V_10 -> V_13 ;
struct V_236 * V_237 ;
struct V_238 V_239 ;
unsigned int V_131 , V_240 ;
int V_65 = - V_241 ;
F_4 ( V_13 , V_21 , V_22 ,
L_47 ) ;
V_10 -> V_51 = F_71 ( V_13 ) ;
if ( V_10 -> V_51 == 0xFFFF ) {
F_4 ( V_13 , V_26 , V_22 ,
L_48 ) ;
return V_65 ;
}
F_4 ( V_13 , V_21 , V_22 ,
L_49 ,
V_10 -> V_51 ) ;
V_13 -> V_231 [ F_18
( V_10 -> V_51 ) ] = V_3 ;
V_10 -> V_242 = 0 ;
if ( F_79 ( V_13 ) )
V_240 = sizeof( struct V_243 ) ;
else
V_240 = sizeof( struct V_244 ) ;
V_239 . V_245 = F_80 ( V_13 -> V_246 . V_247 ,
V_240 ,
& V_239 . V_248 ) ;
if ( V_239 . V_245 == NULL ) {
F_4 ( V_13 , V_26 , V_22 ,
L_50
L_51 ) ;
F_76 ( V_10 ) ;
return - V_241 ;
}
V_239 . V_249 = V_240 ;
memset ( V_239 . V_245 , 0 , V_239 . V_249 ) ;
V_131 = F_81 ( V_13 , V_118 , V_10 , & V_239 ) ;
if ( V_131 <= 0 ) {
F_4 ( V_13 , V_26 , V_22 ,
L_52 ,
V_10 -> V_51 ) ;
F_82 ( V_13 -> V_246 . V_247 , V_239 . V_249 ,
V_239 . V_245 , V_239 . V_248 ) ;
F_76 ( V_10 ) ;
return - V_250 ;
}
V_65 = F_53 ( V_13 , V_131 , NULL , & V_239 ) ;
if ( V_65 ) {
F_4 ( V_13 , V_26 ,
V_22 | V_136 ,
L_53 ) ;
if ( V_65 != - V_92 )
F_82 ( V_13 -> V_246 . V_247 , V_239 . V_249 ,
V_239 . V_245 , V_239 . V_248 ) ;
F_76 ( V_10 ) ;
return V_65 ;
}
V_237 = (struct V_236 * ) V_239 . V_245 ;
V_10 = V_3 -> V_20 ;
V_10 -> V_251 = V_237 -> V_252 ;
V_10 -> V_242 = 1 ;
F_4 ( V_13 , V_21 , V_22 ,
L_54 ) ;
F_82 ( V_13 -> V_246 . V_247 , V_239 . V_249 ,
V_239 . V_245 , V_239 . V_248 ) ;
return 0 ;
}
struct V_2 *
F_83 ( struct V_7 * V_8 , struct V_233 * V_118 ,
int V_235 )
{
struct V_12 * V_13 ;
struct V_9 * V_10 ;
struct V_2 * V_3 ;
int V_65 ;
if ( ! V_8 ) {
V_65 = - V_253 ;
F_2 ( L_55 ) ;
return F_84 ( V_65 ) ;
}
V_13 = F_15 ( V_8 ) ;
if ( ! F_3 ( V_13 ) ) {
V_65 = - V_254 ;
F_4 ( V_13 , V_21 , V_22 ,
L_2 , V_13 -> V_23 ) ;
return F_84 ( V_65 ) ;
}
if ( ! F_56 ( V_142 , & V_13 -> V_23 ) ) {
V_65 = - V_92 ;
F_4 ( V_13 , V_255 , V_22 ,
L_56 ) ;
return F_84 ( V_65 ) ;
}
V_3 = F_85 ( sizeof( struct V_9 ) ) ;
if ( ! V_3 ) {
V_65 = - V_241 ;
return F_84 ( V_65 ) ;
}
V_10 = V_3 -> V_20 ;
V_10 -> V_13 = V_13 ;
V_10 -> V_256 = V_3 ;
V_65 = F_78 ( V_3 , NULL , V_118 , V_235 ) ;
if ( V_65 ) {
F_4 ( V_13 , V_26 , V_22 ,
L_57 ) ;
goto V_257;
}
return V_3 ;
V_257:
F_86 ( V_3 ) ;
return F_84 ( V_65 ) ;
}
int F_87 ( struct V_2 * V_3 , int V_258 )
{
struct V_9 * V_10 = V_3 -> V_20 ;
F_4 ( V_10 -> V_13 , V_21 , V_22 ,
L_58 ) ;
if ( V_10 -> V_242 == 1 )
return 1 ;
else
return 0 ;
}
static void F_88 ( struct V_12 * V_13 )
{
T_3 V_259 ;
struct V_260 * V_261 ;
struct V_45 * V_46 ;
struct V_262 * V_263 ;
V_46 = V_13 -> V_46 ;
V_263 = V_46 -> V_264 ;
for ( V_259 = 0 ; V_259 < V_13 -> V_265 ; V_259 ++ ) {
V_261 = & V_263 -> V_266 [ V_259 ] ;
F_89 ( & V_261 -> V_267 ) ;
F_90 ( V_261 , V_268 ) ;
F_91 ( & V_261 -> V_267 ) ;
}
}
static int F_92 ( struct V_9 * V_10 , int V_269 )
{
int V_65 = 0 ;
unsigned int V_131 ;
struct V_12 * V_13 = V_10 -> V_13 ;
V_131 = F_93 ( V_13 , V_10 -> V_51 , V_269 ) ;
if ( ! V_131 ) {
F_4 ( V_13 , V_21 , V_22 ,
L_59 ,
V_10 -> V_51 ) ;
V_65 = - V_250 ;
}
V_65 = F_53 ( V_13 , V_131 , NULL , NULL ) ;
F_88 ( V_13 ) ;
return V_65 ;
}
static int F_94 ( struct V_12 * V_13 ,
unsigned int V_35 )
{
T_3 V_40 = F_18 ( V_35 ) ;
if ( V_13 -> V_41 [ V_40 ] )
V_13 -> V_41 [ V_40 ] = NULL ;
else {
F_4 ( V_13 , V_21 , V_22 ,
L_60 ) ;
return - V_42 ;
}
return 0 ;
}
void F_95 ( struct V_2 * V_3 )
{
struct V_37 * V_37 ;
struct V_9 * V_10 ;
struct V_12 * V_13 ;
unsigned int V_131 ;
T_7 V_270 , V_271 ;
unsigned short V_272 = V_273 ;
V_10 = V_3 -> V_20 ;
V_13 = V_10 -> V_13 ;
F_4 ( V_13 , V_21 , V_22 ,
L_61 ,
V_10 -> V_51 ) ;
if ( V_10 -> V_39 ) {
V_37 = V_10 -> V_39 ;
F_96 ( V_37 -> V_39 ) ;
V_270 = ~ V_274 ;
V_271 = V_275 ;
} else {
V_270 = V_274 ;
V_271 = V_276 ;
}
if ( ! F_3 ( V_13 ) ) {
F_4 ( V_13 , V_21 , V_22 ,
L_2 , V_13 -> V_23 ) ;
goto V_257;
}
V_131 = F_97 ( V_13 , V_10 ,
V_10 -> V_51 ,
V_270 ,
V_272 ) ;
if ( ! V_131 ) {
F_4 ( V_13 , V_26 , V_22 ,
L_62 ,
V_10 -> V_51 ) ;
}
F_53 ( V_13 , V_131 , NULL , NULL ) ;
F_92 ( V_10 , V_271 ) ;
V_257:
F_98 ( V_277 ) ;
F_76 ( V_10 ) ;
F_94 ( V_13 , V_10 -> V_51 ) ;
F_86 ( V_10 -> V_256 ) ;
}
T_8 F_99 ( int V_93 , int V_67 )
{
switch ( V_93 ) {
case V_94 :
switch ( V_67 ) {
case V_81 :
case V_87 :
case V_88 :
case V_84 :
case V_83 :
case V_89 :
case V_107 :
case V_109 :
case V_68 :
return V_278 ;
default:
return 0 ;
}
case V_279 :
switch ( V_67 ) {
case V_161 :
case V_162 :
case V_163 :
case V_164 :
return V_278 ;
default:
return 0 ;
}
case V_280 :
switch ( V_67 ) {
case V_124 :
case V_128 :
case V_281 :
case V_282 :
case V_117 :
case V_115 :
case V_283 :
case V_284 :
case V_285 :
case V_286 :
case V_287 :
case V_288 :
case V_289 :
case V_290 :
case V_122 :
case V_126 :
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
case V_304 :
return V_278 ;
default:
return 0 ;
}
}
return 0 ;
}
