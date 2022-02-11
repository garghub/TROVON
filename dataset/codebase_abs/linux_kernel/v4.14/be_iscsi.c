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
& V_13 -> V_30 -> V_31 ,
sizeof( struct V_32 ) ,
64 , 0 ) ;
if ( ! V_17 -> V_29 )
goto V_33;
return V_11 ;
V_33:
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
F_12 ( V_11 -> V_20 , V_34 ) ;
}
struct V_35 *
F_13 ( struct V_1 * V_11 , T_2 V_36 )
{
struct V_12 * V_13 ;
struct V_7 * V_8 ;
struct V_35 * V_37 ;
struct V_38 * V_38 ;
struct V_39 * V_40 ;
struct V_14 * V_15 ;
struct V_16 * V_17 ;
V_8 = F_14 ( V_11 ) ;
V_13 = F_15 ( V_8 ) ;
F_4 ( V_13 , V_21 , V_22 ,
L_9
L_10 , V_36 ) ;
V_37 = F_16 ( V_11 , sizeof( * V_38 ) , V_36 ) ;
if ( ! V_37 )
return NULL ;
V_40 = V_37 -> V_20 ;
V_38 = V_40 -> V_20 ;
V_38 -> V_3 = NULL ;
V_38 -> V_13 = V_13 ;
V_38 -> V_40 = V_40 ;
V_15 = V_11 -> V_20 ;
V_17 = V_15 -> V_20 ;
V_38 -> V_17 = V_17 ;
return V_37 ;
}
int F_17 ( struct V_1 * V_11 ,
struct V_35 * V_37 ,
T_3 V_41 , int V_42 )
{
struct V_39 * V_40 = V_37 -> V_20 ;
struct V_38 * V_38 = V_40 -> V_20 ;
struct V_7 * V_8 = F_14 ( V_11 ) ;
struct V_12 * V_13 = F_15 ( V_8 ) ;
struct V_43 * V_44 = V_13 -> V_44 ;
struct V_45 * V_46 ;
struct V_9 * V_10 ;
struct V_2 * V_3 ;
T_4 V_47 ;
V_3 = F_18 ( V_41 ) ;
if ( ! V_3 )
return - V_48 ;
V_10 = V_3 -> V_20 ;
if ( F_19 ( V_11 , V_37 , V_42 ) )
return - V_48 ;
if ( V_10 -> V_13 != V_13 ) {
F_4 ( V_13 , V_26 , V_22 ,
L_11 ,
V_10 -> V_13 , V_13 ) ;
return - V_49 ;
}
V_47 = F_20 ( V_10 -> V_50 ) ;
if ( V_13 -> V_51 [ V_47 ] ) {
if ( V_38 != V_13 -> V_51 [ V_47 ] ||
V_10 != V_13 -> V_51 [ V_47 ] -> V_3 ) {
F_21 ( V_13 , V_26 ,
L_12 ,
V_47 ,
V_10 -> V_50 ,
V_38 ,
V_13 -> V_51 [ V_47 ] ) ;
return - V_48 ;
}
}
V_38 -> V_52 = V_10 -> V_50 ;
V_38 -> V_3 = V_10 ;
V_10 -> V_40 = V_38 ;
V_46 = & V_44 -> V_53 [ V_47 ] ;
V_38 -> V_54 = V_46 -> V_54 ;
F_4 ( V_13 , V_21 , V_22 ,
L_13 ,
V_10 -> V_50 , V_47 , V_38 ) ;
V_13 -> V_51 [ V_47 ] = V_38 ;
return 0 ;
}
static int F_22 ( struct V_12 * V_13 )
{
if ( V_13 -> V_55 )
return 0 ;
V_13 -> V_55 = F_23 ( V_13 -> V_8 ,
& V_27 ,
V_56 ,
0 , 0 ) ;
if ( ! V_13 -> V_55 ) {
F_4 ( V_13 , V_26 , V_22 ,
L_14
L_15 ) ;
return - V_57 ;
}
return 0 ;
}
static int F_24 ( struct V_12 * V_13 )
{
if ( V_13 -> V_58 )
return 0 ;
V_13 -> V_58 = F_23 ( V_13 -> V_8 ,
& V_27 ,
V_59 ,
0 , 0 ) ;
if ( ! V_13 -> V_58 ) {
F_4 ( V_13 , V_26 , V_22 ,
L_14
L_16 ) ;
return - V_57 ;
}
return 0 ;
}
void F_25 ( struct V_12 * V_13 )
{
struct V_60 * V_61 ;
if ( ! F_26 ( V_13 , V_62 , & V_61 ) ) {
F_22 ( V_13 ) ;
F_27 ( V_61 ) ;
}
if ( ! F_26 ( V_13 , V_63 , & V_61 ) ) {
F_24 ( V_13 ) ;
F_27 ( V_61 ) ;
}
}
void F_28 ( struct V_12 * V_13 )
{
if ( V_13 -> V_58 ) {
F_29 ( V_13 -> V_58 ) ;
V_13 -> V_58 = NULL ;
}
if ( V_13 -> V_55 ) {
F_29 ( V_13 -> V_55 ) ;
V_13 -> V_55 = NULL ;
}
}
static int
F_30 ( struct V_7 * V_8 ,
struct V_64 * V_65 )
{
struct V_12 * V_13 = F_15 ( V_8 ) ;
int V_66 = - V_67 ;
switch ( V_65 -> V_68 ) {
case V_69 :
V_66 = 0 ;
if ( V_65 -> V_70 [ 0 ] != V_71 )
V_66 = F_31 ( V_13 , V_72 ) ;
break;
case V_73 :
V_66 = F_31 ( V_13 ,
* ( ( T_4 * ) V_65 -> V_70 ) ) ;
break;
}
return V_66 ;
}
static int
F_32 ( struct V_7 * V_8 ,
struct V_64 * V_74 ,
void * V_75 , T_5 V_76 )
{
struct V_12 * V_13 = F_15 ( V_8 ) ;
T_6 * V_77 = NULL , * V_78 = NULL , * V_79 ;
struct V_80 * V_81 ;
int V_66 = - V_67 ;
switch ( V_74 -> V_68 ) {
case V_82 :
if ( V_74 -> V_70 [ 0 ] == V_83 )
V_66 = F_22 ( V_13 ) ;
else {
F_29 ( V_13 -> V_55 ) ;
V_13 -> V_55 = NULL ;
}
break;
case V_84 :
V_79 = V_74 -> V_70 ;
V_66 = F_33 ( V_13 , V_62 , V_79 ) ;
break;
case V_85 :
if ( V_74 -> V_70 [ 0 ] == V_86 )
V_66 = F_34 ( V_13 , V_62 ) ;
else if ( V_74 -> V_70 [ 0 ] == V_87 )
V_66 = F_35 ( V_13 , V_62 ,
NULL , NULL ) ;
else
F_4 ( V_13 , V_26 , V_22 ,
L_17 ,
V_74 -> V_70 [ 0 ] ) ;
break;
case V_88 :
V_77 = V_74 -> V_70 ;
V_81 = F_36 ( V_75 , V_76 , V_89 ) ;
if ( V_81 ) {
V_74 = F_37 ( V_81 ) ;
V_78 = V_74 -> V_70 ;
}
V_66 = F_35 ( V_13 , V_62 ,
V_77 , V_78 ) ;
break;
case V_89 :
V_78 = V_74 -> V_70 ;
V_81 = F_36 ( V_75 , V_76 , V_88 ) ;
if ( V_81 ) {
V_74 = F_37 ( V_81 ) ;
V_77 = V_74 -> V_70 ;
}
V_66 = F_35 ( V_13 , V_62 ,
V_77 , V_78 ) ;
break;
}
return V_66 ;
}
static int
F_38 ( struct V_7 * V_8 ,
struct V_64 * V_65 ,
void * V_75 , T_5 V_76 )
{
struct V_12 * V_13 = F_15 ( V_8 ) ;
int V_66 = - V_67 ;
switch ( V_65 -> V_68 ) {
case V_82 :
if ( V_65 -> V_70 [ 0 ] == V_83 )
V_66 = F_24 ( V_13 ) ;
else {
F_29 ( V_13 -> V_58 ) ;
V_13 -> V_58 = NULL ;
}
break;
case V_90 :
V_66 = F_35 ( V_13 , V_63 ,
V_65 -> V_70 , NULL ) ;
break;
}
return V_66 ;
}
int F_39 ( struct V_7 * V_8 ,
void * V_75 , T_5 V_76 )
{
struct V_64 * V_65 = NULL ;
struct V_12 * V_13 = F_15 ( V_8 ) ;
struct V_80 * V_91 ;
T_5 V_92 = V_76 ;
int V_66 ;
if ( ! F_3 ( V_13 ) ) {
F_4 ( V_13 , V_21 , V_22 ,
L_2 , V_13 -> V_23 ) ;
return - V_93 ;
}
V_66 = F_40 ( V_13 ) ;
if ( V_66 ) {
F_4 ( V_13 , V_26 , V_22 ,
L_18 ) ;
return V_66 ;
}
F_41 (attrib, data, dt_len, rm_len) {
V_65 = F_37 ( V_91 ) ;
if ( V_65 -> V_94 != V_95 )
continue;
if ( V_65 -> V_96 ) {
F_4 ( V_13 , V_26 , V_22 ,
L_19
L_20 ,
V_65 -> V_96 ) ;
return - V_48 ;
}
F_4 ( V_13 , V_21 , V_22 ,
L_21 ,
( V_65 -> V_97 == V_56 ) ?
L_22 : L_23 , V_65 -> V_68 ) ;
V_66 = - V_67 ;
switch ( V_65 -> V_68 ) {
case V_69 :
case V_73 :
V_66 = F_30 ( V_8 , V_65 ) ;
break;
default:
switch ( V_65 -> V_97 ) {
case V_56 :
V_66 = F_32 ( V_8 ,
V_65 ,
V_75 , V_76 ) ;
break;
case V_59 :
V_66 = F_38 ( V_8 ,
V_65 ,
V_75 , V_76 ) ;
break;
}
}
if ( V_66 == - V_67 ) {
F_21 ( V_13 , V_26 ,
L_24 ,
( V_65 -> V_97 ==
V_56 ) ? L_22 : L_23 ,
V_65 -> V_68 ) ;
V_66 = 0 ;
}
if ( V_66 )
break;
}
return V_66 ;
}
static int F_42 ( struct V_12 * V_13 ,
struct V_98 * V_99 ,
int V_68 , char * V_100 )
{
struct V_60 * V_61 ;
int V_101 , V_102 = V_62 ;
if ( V_99 -> V_97 == V_59 )
V_102 = V_63 ;
V_101 = F_26 ( V_13 , V_102 , & V_61 ) ;
if ( V_101 )
return V_101 ;
switch ( V_68 ) {
case V_88 :
V_101 = sprintf ( V_100 , L_25 , V_61 -> V_103 . V_104 ) ;
break;
case V_90 :
V_101 = sprintf ( V_100 , L_26 , V_61 -> V_103 . V_104 ) ;
break;
case V_85 :
if ( ! V_61 -> V_105 )
V_101 = sprintf ( V_100 , L_27 ) ;
else
V_101 = sprintf ( V_100 , L_28 ) ;
break;
case V_89 :
V_101 = sprintf ( V_100 , L_25 , V_61 -> V_103 . V_106 ) ;
break;
case V_69 :
V_101 = sprintf ( V_100 , L_29 ,
( V_61 -> V_107 == V_72 ) ?
L_30 : L_31 ) ;
break;
case V_108 :
if ( V_61 -> V_107 == V_72 )
V_101 = - V_48 ;
else
V_101 = sprintf ( V_100 , L_32 ,
( V_61 -> V_107 &
V_109 ) ) ;
break;
case V_110 :
if ( V_61 -> V_107 == V_72 )
V_101 = - V_48 ;
else
V_101 = sprintf ( V_100 , L_32 ,
( ( V_61 -> V_107 >> 13 ) &
V_111 ) ) ;
break;
default:
F_43 ( 1 ) ;
}
F_27 ( V_61 ) ;
return V_101 ;
}
int F_44 ( struct V_98 * V_99 ,
enum V_112 V_94 ,
int V_68 , char * V_100 )
{
struct V_7 * V_8 = F_45 ( V_99 ) ;
struct V_12 * V_13 = F_15 ( V_8 ) ;
struct V_113 V_114 ;
int V_101 = - V_67 ;
if ( V_94 != V_95 )
return 0 ;
if ( ! F_3 ( V_13 ) ) {
F_4 ( V_13 , V_21 , V_22 ,
L_2 , V_13 -> V_23 ) ;
return - V_93 ;
}
switch ( V_68 ) {
case V_88 :
case V_89 :
case V_85 :
case V_90 :
case V_69 :
case V_108 :
case V_110 :
V_101 = F_42 ( V_13 , V_99 , V_68 , V_100 ) ;
break;
case V_82 :
if ( V_99 -> V_97 == V_56 )
V_101 = sprintf ( V_100 , L_29 ,
V_13 -> V_55 ? L_31 : L_30 ) ;
else if ( V_99 -> V_97 == V_59 )
V_101 = sprintf ( V_100 , L_29 ,
V_13 -> V_58 ? L_31 : L_30 ) ;
break;
case V_84 :
memset ( & V_114 , 0 , sizeof( V_114 ) ) ;
V_101 = F_46 ( V_13 , V_62 , & V_114 ) ;
if ( ! V_101 )
V_101 = sprintf ( V_100 , L_25 , & V_114 . V_103 . V_104 ) ;
break;
}
return V_101 ;
}
int F_47 ( struct V_2 * V_3 ,
enum V_115 V_68 , char * V_100 )
{
struct V_9 * V_10 = V_3 -> V_20 ;
int V_101 ;
F_4 ( V_10 -> V_13 , V_21 ,
V_22 ,
L_33
L_34 , V_68 ) ;
switch ( V_68 ) {
case V_116 :
V_101 = sprintf ( V_100 , L_35 , V_10 -> V_117 ) ;
break;
case V_118 :
if ( V_10 -> V_102 == V_62 )
V_101 = sprintf ( V_100 , L_25 , & V_10 -> V_119 ) ;
else
V_101 = sprintf ( V_100 , L_26 , & V_10 -> V_120 ) ;
break;
default:
V_101 = - V_67 ;
}
return V_101 ;
}
int F_48 ( struct V_35 * V_37 ,
enum V_115 V_68 , char * V_100 , int V_121 )
{
struct V_39 * V_40 = V_37 -> V_20 ;
struct V_14 * V_122 = V_40 -> V_122 ;
struct V_12 * V_13 = NULL ;
int V_66 ;
V_13 = ( (struct V_38 * ) V_40 -> V_20 ) -> V_13 ;
F_4 ( V_13 , V_21 , V_22 ,
L_36
L_34 , V_68 ) ;
V_66 = F_49 ( V_37 , V_68 , V_100 , V_121 ) ;
if ( V_66 )
return V_66 ;
switch ( V_68 ) {
case V_123 :
if ( V_122 -> V_124 > 8192 )
V_122 -> V_124 = 8192 ;
break;
case V_125 :
if ( V_40 -> V_126 > 65536 )
V_40 -> V_126 = 65536 ;
break;
case V_127 :
if ( V_122 -> V_128 > 262144 )
V_122 -> V_128 = 262144 ;
break;
case V_129 :
if ( V_40 -> V_130 > 65536 )
V_40 -> V_130 = 65536 ;
default:
return 0 ;
}
return 0 ;
}
static int F_50 ( char * V_100 , struct V_12 * V_13 )
{
int V_131 ;
unsigned int V_132 ;
struct V_133 * V_134 ;
struct V_135 * V_136 ;
V_132 = F_51 ( V_13 ) ;
if ( ! V_132 ) {
F_4 ( V_13 , V_26 , V_22 ,
L_37 ) ;
return - V_93 ;
}
V_131 = F_52 ( V_13 , V_132 , & V_134 , NULL ) ;
if ( V_131 ) {
F_4 ( V_13 , V_26 ,
V_22 | V_137 ,
L_38 ) ;
return V_131 ;
}
V_136 = F_53 ( V_134 ) ;
V_131 = sprintf ( V_100 , L_29 , V_136 -> V_138 ) ;
return V_131 ;
}
static void F_54 ( struct V_7 * V_8 )
{
struct V_12 * V_13 = F_15 ( V_8 ) ;
struct V_139 * V_140 = V_8 -> V_141 ;
V_140 -> V_142 = F_55 ( V_143 , & V_13 -> V_23 ) ?
V_144 : V_145 ;
}
static void F_56 ( struct V_7 * V_8 )
{
struct V_12 * V_13 = F_15 ( V_8 ) ;
struct V_139 * V_140 = V_8 -> V_141 ;
switch ( V_13 -> V_146 ) {
case V_147 :
V_140 -> V_146 = V_148 ;
break;
case V_149 :
V_140 -> V_146 = V_150 ;
break;
case V_151 :
V_140 -> V_146 = V_152 ;
break;
case V_153 :
V_140 -> V_146 = V_154 ;
break;
case V_155 :
V_140 -> V_146 = V_156 ;
break;
case V_157 :
V_140 -> V_146 = V_158 ;
break;
default:
V_140 -> V_146 = V_159 ;
}
}
int F_57 ( struct V_7 * V_8 ,
enum V_160 V_68 , char * V_100 )
{
struct V_12 * V_13 = F_15 ( V_8 ) ;
int V_161 = 0 ;
if ( ! F_3 ( V_13 ) ) {
F_4 ( V_13 , V_21 , V_22 ,
L_2 , V_13 -> V_23 ) ;
return - V_93 ;
}
F_4 ( V_13 , V_21 , V_22 ,
L_39 , V_68 ) ;
switch ( V_68 ) {
case V_162 :
V_161 = F_58 ( V_100 , V_13 ) ;
if ( V_161 < 0 ) {
F_4 ( V_13 , V_26 , V_22 ,
L_40 ) ;
return V_161 ;
}
break;
case V_163 :
V_161 = F_50 ( V_100 , V_13 ) ;
if ( V_161 < 0 ) {
F_4 ( V_13 , V_26 , V_22 ,
L_41 ) ;
return V_161 ;
}
break;
case V_164 :
F_54 ( V_8 ) ;
V_161 = sprintf ( V_100 , L_29 , F_59 ( V_8 ) ) ;
break;
case V_165 :
F_56 ( V_8 ) ;
V_161 = sprintf ( V_100 , L_29 , F_60 ( V_8 ) ) ;
break;
default:
return F_61 ( V_8 , V_68 , V_100 ) ;
}
return V_161 ;
}
int F_58 ( char * V_100 , struct V_12 * V_13 )
{
struct V_166 V_136 ;
int V_131 ;
if ( V_13 -> V_167 )
return F_62 ( V_100 , V_13 -> V_168 , V_169 ) ;
memset ( & V_136 , 0 , sizeof( V_136 ) ) ;
V_131 = F_63 ( V_13 , & V_136 ) ;
if ( V_131 )
return V_131 ;
V_13 -> V_167 = true ;
memcpy ( V_13 -> V_168 , V_136 . V_168 , V_169 ) ;
return F_62 ( V_100 , V_13 -> V_168 , V_169 ) ;
}
void F_64 ( struct V_35 * V_37 ,
struct V_170 * V_171 )
{
struct V_39 * V_40 = V_37 -> V_20 ;
struct V_12 * V_13 = NULL ;
V_13 = ( (struct V_38 * ) V_40 -> V_20 ) -> V_13 ;
F_4 ( V_13 , V_21 , V_22 ,
L_42 ) ;
V_171 -> V_172 = V_40 -> V_172 ;
V_171 -> V_173 = V_40 -> V_173 ;
V_171 -> V_174 = V_40 -> V_175 ;
V_171 -> V_176 = V_40 -> V_177 ;
V_171 -> V_178 = V_40 -> V_179 ;
V_171 -> V_180 = V_40 -> V_181 ;
V_171 -> V_182 = V_40 -> V_183 ;
V_171 -> V_184 = V_40 -> V_185 ;
V_171 -> V_186 = V_40 -> V_187 ;
V_171 -> V_188 = 0 ;
V_171 -> V_189 = 0 ;
V_171 -> V_190 = 1 ;
strcpy ( V_171 -> V_191 [ 0 ] . V_192 , L_43 ) ;
V_171 -> V_191 [ 0 ] . V_70 = V_40 -> V_193 ;
}
static void F_65 ( struct V_38 * V_38 ,
struct V_194 * V_24 )
{
struct V_39 * V_40 = V_38 -> V_40 ;
struct V_14 * V_122 = V_40 -> V_122 ;
F_66 ( struct V_195 , V_196 ,
V_24 , V_122 -> V_128 ) ;
F_66 ( struct V_195 ,
V_197 , V_24 ,
V_40 -> V_130 ) ;
F_66 ( struct V_195 , V_198 ,
V_24 , V_122 -> V_124 ) ;
F_66 ( struct V_195 , V_199 , V_24 ,
V_122 -> V_199 ) ;
F_66 ( struct V_195 , V_200 , V_24 ,
V_40 -> V_201 ) ;
F_66 ( struct V_195 , V_202 , V_24 ,
V_40 -> V_203 ) ;
F_66 ( struct V_195 , V_204 , V_24 ,
V_122 -> V_205 ) ;
F_66 ( struct V_195 , V_206 , V_24 ,
V_122 -> V_207 ) ;
F_66 ( struct V_195 ,
V_208 , V_24 ,
V_122 -> V_209 ) ;
F_66 ( struct V_195 ,
V_210 , V_24 ,
V_122 -> V_211 ) ;
F_66 ( struct V_195 , V_212 , V_24 ,
V_122 -> V_212 ) ;
F_66 ( struct V_195 , V_213 , V_24 ,
( V_40 -> V_213 - 1 ) ) ;
F_66 ( struct V_195 ,
V_214 , V_24 ,
V_40 -> V_126 ) ;
}
int F_67 ( struct V_35 * V_37 )
{
struct V_39 * V_40 = V_37 -> V_20 ;
struct V_38 * V_38 = V_40 -> V_20 ;
struct V_9 * V_10 ;
struct V_194 V_24 ;
struct V_12 * V_13 ;
V_13 = ( (struct V_38 * ) V_40 -> V_20 ) -> V_13 ;
if ( ! F_3 ( V_13 ) ) {
F_4 ( V_13 , V_21 , V_22 ,
L_2 , V_13 -> V_23 ) ;
return - V_93 ;
}
F_4 ( V_38 -> V_13 , V_21 , V_22 ,
L_44 ) ;
memset ( & V_24 , 0 , sizeof( struct V_194 ) ) ;
V_10 = V_38 -> V_3 ;
if ( ! V_10 )
F_4 ( V_38 -> V_13 , V_26 ,
V_22 ,
L_45 ) ;
V_38 -> V_215 = 0 ;
F_65 ( V_38 , & V_24 ) ;
F_68 ( V_38 , & V_24 ) ;
F_69 ( V_37 ) ;
return 0 ;
}
static int F_70 ( struct V_12 * V_13 )
{
T_4 V_216 , V_217 ;
unsigned short V_36 , V_218 ;
struct V_219 * V_220 ;
V_216 = ( V_13 -> V_221 [ V_222 ] ) ?
F_71 ( V_13 ) : 0 ;
V_217 = ( V_13 -> V_221 [ V_223 ] ) ?
F_72 ( V_13 ) : 0 ;
V_218 = ( V_216 > V_217 ) ?
V_222 : V_223 ;
if ( ! F_55 ( V_218 , ( void * ) & V_13 -> V_224 . V_225 ) )
return V_226 ;
V_220 = V_13 -> V_221 [ V_218 ] ;
V_36 = V_220 -> V_227 [ V_220 -> V_228 ] ;
if ( ! V_220 -> V_229 || V_36 == V_226 ) {
F_21 ( V_13 , V_26 ,
L_46 ,
V_220 -> V_229 , V_220 -> V_230 ) ;
return V_226 ;
}
V_220 -> V_227 [ V_220 -> V_228 ++ ] = V_226 ;
if ( V_220 -> V_228 == F_73 ( V_13 , V_218 ) )
V_220 -> V_228 = 0 ;
V_220 -> V_229 -- ;
return V_36 ;
}
static void F_74 ( struct V_12 * V_13 , unsigned short V_36 )
{
T_4 V_47 = F_20 ( V_36 ) ;
struct V_45 * V_46 ;
struct V_43 * V_44 ;
struct V_219 * V_220 ;
T_4 V_231 ;
V_44 = V_13 -> V_44 ;
V_46 = & V_44 -> V_53 [ V_47 ] ;
V_231 = V_46 -> V_232 ;
V_220 = V_13 -> V_221 [ V_231 ] ;
if ( V_220 -> V_227 [ V_220 -> V_230 ] != V_226 ) {
F_21 ( V_13 , V_26 ,
L_47 ,
V_36 , V_220 -> V_229 , V_220 -> V_230 ) ;
return;
}
V_220 -> V_227 [ V_220 -> V_230 ++ ] = V_36 ;
if ( V_220 -> V_230 == F_73 ( V_13 , V_231 ) )
V_220 -> V_230 = 0 ;
V_220 -> V_229 ++ ;
}
static void F_75 ( struct V_9 * V_10 )
{
struct V_12 * V_13 = V_10 -> V_13 ;
struct V_38 * V_38 ;
F_74 ( V_13 , V_10 -> V_50 ) ;
V_10 -> V_13 = NULL ;
V_13 -> V_233 [ F_20 ( V_10 -> V_50 ) ] = NULL ;
if ( ! V_10 -> V_40 )
return;
V_38 = V_10 -> V_40 ;
V_10 -> V_40 = NULL ;
if ( V_38 -> V_215 ) {
F_76 ( V_38 ,
V_38 -> V_234 ) ;
V_38 -> V_215 = 0 ;
}
}
static int F_77 ( struct V_2 * V_3 ,
struct V_235 * V_236 ,
struct V_235 * V_119 , int V_237 )
{
struct V_9 * V_10 = V_3 -> V_20 ;
struct V_12 * V_13 = V_10 -> V_13 ;
struct V_238 * V_239 ;
struct V_240 V_241 ;
unsigned int V_132 , V_242 ;
int V_66 = - V_243 ;
F_4 ( V_13 , V_21 , V_22 ,
L_48 ) ;
V_10 -> V_50 = F_70 ( V_13 ) ;
if ( V_10 -> V_50 == V_226 ) {
F_4 ( V_13 , V_26 , V_22 ,
L_49 ) ;
return V_66 ;
}
F_4 ( V_13 , V_21 , V_22 ,
L_50 ,
V_10 -> V_50 ) ;
V_13 -> V_233 [ F_20
( V_10 -> V_50 ) ] = V_3 ;
V_10 -> V_244 = 0 ;
if ( F_78 ( V_13 ) )
V_242 = sizeof( struct V_245 ) ;
else
V_242 = sizeof( struct V_246 ) ;
V_241 . V_247 = F_79 ( V_13 -> V_248 . V_249 ,
V_242 ,
& V_241 . V_250 ) ;
if ( V_241 . V_247 == NULL ) {
F_4 ( V_13 , V_26 , V_22 ,
L_51
L_52 ) ;
F_75 ( V_10 ) ;
return - V_243 ;
}
V_241 . V_251 = V_242 ;
memset ( V_241 . V_247 , 0 , V_241 . V_251 ) ;
V_132 = F_80 ( V_13 , V_119 , V_10 , & V_241 ) ;
if ( ! V_132 ) {
F_4 ( V_13 , V_26 , V_22 ,
L_53 ,
V_10 -> V_50 ) ;
F_81 ( V_13 -> V_248 . V_249 , V_241 . V_251 ,
V_241 . V_247 , V_241 . V_250 ) ;
F_75 ( V_10 ) ;
return - V_252 ;
}
V_66 = F_52 ( V_13 , V_132 , NULL , & V_241 ) ;
if ( V_66 ) {
F_4 ( V_13 , V_26 ,
V_22 | V_137 ,
L_54 ) ;
if ( V_66 != - V_93 )
F_81 ( V_13 -> V_248 . V_249 , V_241 . V_251 ,
V_241 . V_247 , V_241 . V_250 ) ;
F_75 ( V_10 ) ;
return V_66 ;
}
V_239 = (struct V_238 * ) V_241 . V_247 ;
V_10 = V_3 -> V_20 ;
V_10 -> V_253 = V_239 -> V_254 ;
V_10 -> V_244 = 1 ;
F_4 ( V_13 , V_21 , V_22 ,
L_55 ) ;
F_81 ( V_13 -> V_248 . V_249 , V_241 . V_251 ,
V_241 . V_247 , V_241 . V_250 ) ;
return 0 ;
}
struct V_2 *
F_82 ( struct V_7 * V_8 , struct V_235 * V_119 ,
int V_237 )
{
struct V_12 * V_13 ;
struct V_9 * V_10 ;
struct V_2 * V_3 ;
int V_66 ;
if ( ! V_8 ) {
V_66 = - V_255 ;
F_2 ( L_56 ) ;
return F_83 ( V_66 ) ;
}
V_13 = F_15 ( V_8 ) ;
if ( ! F_3 ( V_13 ) ) {
V_66 = - V_256 ;
F_4 ( V_13 , V_21 , V_22 ,
L_2 , V_13 -> V_23 ) ;
return F_83 ( V_66 ) ;
}
if ( ! F_55 ( V_143 , & V_13 -> V_23 ) ) {
V_66 = - V_93 ;
F_4 ( V_13 , V_257 , V_22 ,
L_57 ) ;
return F_83 ( V_66 ) ;
}
V_3 = F_84 ( sizeof( struct V_9 ) ) ;
if ( ! V_3 ) {
V_66 = - V_243 ;
return F_83 ( V_66 ) ;
}
V_10 = V_3 -> V_20 ;
V_10 -> V_13 = V_13 ;
V_10 -> V_258 = V_3 ;
V_66 = F_77 ( V_3 , NULL , V_119 , V_237 ) ;
if ( V_66 ) {
F_4 ( V_13 , V_26 , V_22 ,
L_58 ) ;
goto V_259;
}
return V_3 ;
V_259:
F_85 ( V_3 ) ;
return F_83 ( V_66 ) ;
}
int F_86 ( struct V_2 * V_3 , int V_260 )
{
struct V_9 * V_10 = V_3 -> V_20 ;
F_4 ( V_10 -> V_13 , V_21 , V_22 ,
L_59 ) ;
if ( V_10 -> V_244 == 1 )
return 1 ;
else
return 0 ;
}
static void F_87 ( struct V_12 * V_13 )
{
T_4 V_261 ;
struct V_262 * V_263 ;
struct V_43 * V_44 ;
struct V_264 * V_265 ;
V_44 = V_13 -> V_44 ;
V_265 = V_44 -> V_266 ;
for ( V_261 = 0 ; V_261 < V_13 -> V_267 ; V_261 ++ ) {
V_263 = & V_265 -> V_268 [ V_261 ] ;
F_88 ( & V_263 -> V_269 ) ;
F_89 ( V_263 , V_270 ) ;
F_90 ( & V_263 -> V_269 ) ;
}
}
static int F_91 ( struct V_9 * V_10 )
{
struct V_12 * V_13 = V_10 -> V_13 ;
unsigned int V_132 , V_271 ;
int V_66 ;
V_271 = 0 ;
while ( V_271 ++ < 3 ) {
V_132 = F_92 ( V_13 , V_10 ) ;
if ( V_132 ) {
V_66 = F_52 ( V_13 , V_132 , NULL , NULL ) ;
if ( ! V_66 )
break;
F_4 ( V_13 , V_21 , V_22 ,
L_60 ,
V_10 -> V_50 ) ;
}
}
F_93 ( 250 ) ;
F_87 ( V_13 ) ;
if ( V_271 > 3 )
return - 1 ;
V_271 = 0 ;
while ( V_271 ++ < 3 ) {
V_132 = F_94 ( V_13 , V_10 ) ;
if ( V_132 ) {
V_66 = F_52 ( V_13 , V_132 , NULL , NULL ) ;
if ( ! V_66 )
break;
F_4 ( V_13 , V_21 , V_22 ,
L_61 ,
V_10 -> V_50 ) ;
}
}
if ( V_271 > 3 )
return - 1 ;
return 0 ;
}
void F_95 ( struct V_2 * V_3 )
{
struct V_9 * V_10 ;
struct V_38 * V_38 ;
struct V_12 * V_13 ;
T_4 V_47 ;
V_10 = V_3 -> V_20 ;
V_13 = V_10 -> V_13 ;
F_4 ( V_13 , V_21 , V_22 ,
L_62 ,
V_10 -> V_50 ) ;
V_47 = F_20 ( V_10 -> V_50 ) ;
if ( ! V_13 -> V_233 [ V_47 ] ) {
F_21 ( V_13 , V_26 ,
L_63 ,
V_47 ,
V_10 -> V_50 ) ;
return;
}
if ( V_10 -> V_40 ) {
V_38 = V_10 -> V_40 ;
F_96 ( V_38 -> V_40 ) ;
}
if ( ! F_3 ( V_13 ) ) {
F_4 ( V_13 , V_21 , V_22 ,
L_2 , V_13 -> V_23 ) ;
} else {
if ( F_91 ( V_10 ) < 0 )
F_21 ( V_13 , V_26 ,
L_64 ,
V_10 -> V_50 ) ;
}
F_75 ( V_10 ) ;
if ( ! V_13 -> V_51 [ V_47 ] )
F_21 ( V_13 , V_26 ,
L_65 ,
V_47 , V_10 -> V_50 ) ;
V_13 -> V_51 [ V_47 ] = NULL ;
F_85 ( V_10 -> V_258 ) ;
}
T_7 F_97 ( int V_94 , int V_68 )
{
switch ( V_94 ) {
case V_95 :
switch ( V_68 ) {
case V_82 :
case V_88 :
case V_89 :
case V_85 :
case V_84 :
case V_90 :
case V_108 :
case V_110 :
case V_69 :
return V_272 ;
default:
return 0 ;
}
case V_273 :
switch ( V_68 ) {
case V_162 :
case V_163 :
case V_164 :
case V_165 :
return V_272 ;
default:
return 0 ;
}
case V_274 :
switch ( V_68 ) {
case V_125 :
case V_129 :
case V_275 :
case V_276 :
case V_118 :
case V_116 :
case V_277 :
case V_278 :
case V_279 :
case V_280 :
case V_281 :
case V_282 :
case V_283 :
case V_284 :
case V_123 :
case V_127 :
case V_285 :
case V_286 :
case V_287 :
case V_288 :
case V_289 :
case V_290 :
case V_291 :
case V_292 :
case V_293 :
case V_294 :
case V_295 :
case V_296 :
case V_297 :
case V_298 :
return V_272 ;
default:
return 0 ;
}
}
return 0 ;
}
