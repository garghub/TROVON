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
int F_17 ( struct V_1 * V_11 ,
struct V_34 * V_36 ,
T_3 V_40 , int V_41 )
{
struct V_38 * V_39 = V_36 -> V_20 ;
struct V_37 * V_37 = V_39 -> V_20 ;
struct V_7 * V_8 = F_14 ( V_11 ) ;
struct V_12 * V_13 = F_15 ( V_8 ) ;
struct V_42 * V_43 = V_13 -> V_43 ;
struct V_44 * V_45 ;
struct V_9 * V_10 ;
struct V_2 * V_3 ;
T_4 V_46 ;
V_3 = F_18 ( V_40 ) ;
if ( ! V_3 )
return - V_47 ;
V_10 = V_3 -> V_20 ;
if ( F_19 ( V_11 , V_36 , V_41 ) )
return - V_47 ;
if ( V_10 -> V_13 != V_13 ) {
F_4 ( V_13 , V_26 , V_22 ,
L_11 ,
V_10 -> V_13 , V_13 ) ;
return - V_48 ;
}
V_46 = F_20 ( V_10 -> V_49 ) ;
if ( V_13 -> V_50 [ V_46 ] ) {
if ( V_37 != V_13 -> V_50 [ V_46 ] ||
V_10 != V_13 -> V_50 [ V_46 ] -> V_3 ) {
F_21 ( V_13 , V_26 ,
L_12 ,
V_46 ,
V_10 -> V_49 ,
V_37 ,
V_13 -> V_50 [ V_46 ] ) ;
return - V_47 ;
}
}
V_37 -> V_51 = V_10 -> V_49 ;
V_37 -> V_3 = V_10 ;
V_10 -> V_39 = V_37 ;
V_45 = & V_43 -> V_52 [ V_46 ] ;
V_37 -> V_53 = V_45 -> V_53 ;
F_4 ( V_13 , V_21 , V_22 ,
L_13 ,
V_10 -> V_49 , V_46 , V_37 ) ;
V_13 -> V_50 [ V_46 ] = V_37 ;
return 0 ;
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
L_14
L_15 ) ;
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
L_14
L_16 ) ;
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
* ( ( T_4 * ) V_64 -> V_69 ) ) ;
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
L_17 ,
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
L_18 ) ;
return V_65 ;
}
F_41 (attrib, data, dt_len, rm_len) {
V_64 = F_37 ( V_90 ) ;
if ( V_64 -> V_93 != V_94 )
continue;
if ( V_64 -> V_95 ) {
F_4 ( V_13 , V_26 , V_22 ,
L_19
L_20 ,
V_64 -> V_95 ) ;
return - V_47 ;
}
F_4 ( V_13 , V_21 , V_22 ,
L_21 ,
( V_64 -> V_96 == V_55 ) ?
L_22 : L_23 , V_64 -> V_67 ) ;
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
F_21 ( V_13 , V_26 ,
L_24 ,
( V_64 -> V_96 ==
V_55 ) ? L_22 : L_23 ,
V_64 -> V_67 ) ;
V_65 = 0 ;
}
if ( V_65 )
break;
}
return V_65 ;
}
static int F_42 ( struct V_12 * V_13 ,
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
V_100 = sprintf ( V_99 , L_25 , V_60 -> V_102 . V_103 ) ;
break;
case V_89 :
V_100 = sprintf ( V_99 , L_26 , V_60 -> V_102 . V_103 ) ;
break;
case V_84 :
if ( ! V_60 -> V_104 )
V_100 = sprintf ( V_99 , L_27 ) ;
else
V_100 = sprintf ( V_99 , L_28 ) ;
break;
case V_88 :
V_100 = sprintf ( V_99 , L_25 , V_60 -> V_102 . V_105 ) ;
break;
case V_68 :
V_100 = sprintf ( V_99 , L_29 ,
( V_60 -> V_106 == V_71 ) ?
L_30 : L_31 ) ;
break;
case V_107 :
if ( V_60 -> V_106 == V_71 )
V_100 = - V_47 ;
else
V_100 = sprintf ( V_99 , L_32 ,
( V_60 -> V_106 &
V_108 ) ) ;
break;
case V_109 :
if ( V_60 -> V_106 == V_71 )
V_100 = - V_47 ;
else
V_100 = sprintf ( V_99 , L_32 ,
( ( V_60 -> V_106 >> 13 ) &
V_110 ) ) ;
break;
default:
F_43 ( 1 ) ;
}
F_27 ( V_60 ) ;
return V_100 ;
}
int F_44 ( struct V_97 * V_98 ,
enum V_111 V_93 ,
int V_67 , char * V_99 )
{
struct V_7 * V_8 = F_45 ( V_98 ) ;
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
V_100 = F_42 ( V_13 , V_98 , V_67 , V_99 ) ;
break;
case V_81 :
if ( V_98 -> V_96 == V_55 )
V_100 = sprintf ( V_99 , L_29 ,
V_13 -> V_54 ? L_31 : L_30 ) ;
else if ( V_98 -> V_96 == V_58 )
V_100 = sprintf ( V_99 , L_29 ,
V_13 -> V_57 ? L_31 : L_30 ) ;
break;
case V_83 :
memset ( & V_113 , 0 , sizeof( V_113 ) ) ;
V_100 = F_46 ( V_13 , V_61 , & V_113 ) ;
if ( ! V_100 )
V_100 = sprintf ( V_99 , L_25 , & V_113 . V_102 . V_103 ) ;
break;
}
return V_100 ;
}
int F_47 ( struct V_2 * V_3 ,
enum V_114 V_67 , char * V_99 )
{
struct V_9 * V_10 = V_3 -> V_20 ;
int V_100 ;
F_4 ( V_10 -> V_13 , V_21 ,
V_22 ,
L_33
L_34 , V_67 ) ;
switch ( V_67 ) {
case V_115 :
V_100 = sprintf ( V_99 , L_35 , V_10 -> V_116 ) ;
break;
case V_117 :
if ( V_10 -> V_101 == V_61 )
V_100 = sprintf ( V_99 , L_25 , & V_10 -> V_118 ) ;
else
V_100 = sprintf ( V_99 , L_26 , & V_10 -> V_119 ) ;
break;
default:
V_100 = - V_66 ;
}
return V_100 ;
}
int F_48 ( struct V_34 * V_36 ,
enum V_114 V_67 , char * V_99 , int V_120 )
{
struct V_38 * V_39 = V_36 -> V_20 ;
struct V_14 * V_121 = V_39 -> V_121 ;
struct V_12 * V_13 = NULL ;
int V_65 ;
V_13 = ( (struct V_37 * ) V_39 -> V_20 ) -> V_13 ;
F_4 ( V_13 , V_21 , V_22 ,
L_36
L_34 , V_67 ) ;
V_65 = F_49 ( V_36 , V_67 , V_99 , V_120 ) ;
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
static int F_50 ( char * V_99 , struct V_12 * V_13 )
{
int V_130 ;
unsigned int V_131 ;
struct V_132 * V_133 ;
struct V_134 * V_135 ;
V_131 = F_51 ( V_13 ) ;
if ( ! V_131 ) {
F_4 ( V_13 , V_26 , V_22 ,
L_37 ) ;
return - V_92 ;
}
V_130 = F_52 ( V_13 , V_131 , & V_133 , NULL ) ;
if ( V_130 ) {
F_4 ( V_13 , V_26 ,
V_22 | V_136 ,
L_38 ) ;
return V_130 ;
}
V_135 = F_53 ( V_133 ) ;
V_130 = sprintf ( V_99 , L_29 , V_135 -> V_137 ) ;
return V_130 ;
}
static void F_54 ( struct V_7 * V_8 )
{
struct V_12 * V_13 = F_15 ( V_8 ) ;
struct V_138 * V_139 = V_8 -> V_140 ;
V_139 -> V_141 = F_55 ( V_142 , & V_13 -> V_23 ) ?
V_143 : V_144 ;
}
static void F_56 ( struct V_7 * V_8 )
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
int F_57 ( struct V_7 * V_8 ,
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
L_39 , V_67 ) ;
switch ( V_67 ) {
case V_161 :
V_160 = F_58 ( V_99 , V_13 ) ;
if ( V_160 < 0 ) {
F_4 ( V_13 , V_26 , V_22 ,
L_40 ) ;
return V_160 ;
}
break;
case V_162 :
V_160 = F_50 ( V_99 , V_13 ) ;
if ( V_160 < 0 ) {
F_4 ( V_13 , V_26 , V_22 ,
L_41 ) ;
return V_160 ;
}
break;
case V_163 :
F_54 ( V_8 ) ;
V_160 = sprintf ( V_99 , L_29 , F_59 ( V_8 ) ) ;
break;
case V_164 :
F_56 ( V_8 ) ;
V_160 = sprintf ( V_99 , L_29 , F_60 ( V_8 ) ) ;
break;
default:
return F_61 ( V_8 , V_67 , V_99 ) ;
}
return V_160 ;
}
int F_58 ( char * V_99 , struct V_12 * V_13 )
{
struct V_165 V_135 ;
int V_130 ;
if ( V_13 -> V_166 )
return F_62 ( V_99 , V_13 -> V_167 , V_168 ) ;
memset ( & V_135 , 0 , sizeof( V_135 ) ) ;
V_130 = F_63 ( V_13 , & V_135 ) ;
if ( V_130 )
return V_130 ;
V_13 -> V_166 = true ;
memcpy ( V_13 -> V_167 , V_135 . V_167 , V_168 ) ;
return F_62 ( V_99 , V_13 -> V_167 , V_168 ) ;
}
void F_64 ( struct V_34 * V_36 ,
struct V_169 * V_170 )
{
struct V_38 * V_39 = V_36 -> V_20 ;
struct V_12 * V_13 = NULL ;
V_13 = ( (struct V_37 * ) V_39 -> V_20 ) -> V_13 ;
F_4 ( V_13 , V_21 , V_22 ,
L_42 ) ;
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
strcpy ( V_170 -> V_190 [ 0 ] . V_191 , L_43 ) ;
V_170 -> V_190 [ 0 ] . V_69 = V_39 -> V_192 ;
}
static void F_65 ( struct V_37 * V_37 ,
struct V_193 * V_24 )
{
struct V_38 * V_39 = V_37 -> V_39 ;
struct V_14 * V_121 = V_39 -> V_121 ;
F_66 ( struct V_194 , V_195 ,
V_24 , V_121 -> V_127 ) ;
F_66 ( struct V_194 ,
V_196 , V_24 ,
V_39 -> V_129 ) ;
F_66 ( struct V_194 , V_197 ,
V_24 , V_121 -> V_123 ) ;
F_66 ( struct V_194 , V_198 , V_24 ,
V_121 -> V_198 ) ;
F_66 ( struct V_194 , V_199 , V_24 ,
V_39 -> V_200 ) ;
F_66 ( struct V_194 , V_201 , V_24 ,
V_39 -> V_202 ) ;
F_66 ( struct V_194 , V_203 , V_24 ,
V_121 -> V_204 ) ;
F_66 ( struct V_194 , V_205 , V_24 ,
V_121 -> V_206 ) ;
F_66 ( struct V_194 ,
V_207 , V_24 ,
V_121 -> V_208 ) ;
F_66 ( struct V_194 ,
V_209 , V_24 ,
V_121 -> V_210 ) ;
F_66 ( struct V_194 , V_211 , V_24 ,
V_121 -> V_211 ) ;
F_66 ( struct V_194 , V_212 , V_24 ,
( V_39 -> V_212 - 1 ) ) ;
F_66 ( struct V_194 ,
V_213 , V_24 ,
V_39 -> V_125 ) ;
}
int F_67 ( struct V_34 * V_36 )
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
L_44 ) ;
memset ( & V_24 , 0 , sizeof( struct V_193 ) ) ;
V_10 = V_37 -> V_3 ;
if ( ! V_10 )
F_4 ( V_37 -> V_13 , V_26 ,
V_22 ,
L_45 ) ;
V_37 -> V_214 = 0 ;
F_65 ( V_37 , & V_24 ) ;
F_68 ( V_37 , & V_24 ) ;
F_69 ( V_36 ) ;
return 0 ;
}
static int F_70 ( struct V_12 * V_13 )
{
T_4 V_215 , V_216 ;
unsigned short V_35 , V_217 ;
struct V_218 * V_219 ;
V_215 = ( V_13 -> V_220 [ V_221 ] ) ?
F_71 ( V_13 ) : 0 ;
V_216 = ( V_13 -> V_220 [ V_222 ] ) ?
F_72 ( V_13 ) : 0 ;
V_217 = ( V_215 > V_216 ) ?
V_221 : V_222 ;
if ( ! F_55 ( V_217 , ( void * ) & V_13 -> V_223 . V_224 ) )
return V_225 ;
V_219 = V_13 -> V_220 [ V_217 ] ;
V_35 = V_219 -> V_226 [ V_219 -> V_227 ] ;
if ( ! V_219 -> V_228 || V_35 == V_225 ) {
F_21 ( V_13 , V_26 ,
L_46 ,
V_219 -> V_228 , V_219 -> V_229 ) ;
return V_225 ;
}
V_219 -> V_226 [ V_219 -> V_227 ++ ] = V_225 ;
if ( V_219 -> V_227 == F_73 ( V_13 , V_217 ) )
V_219 -> V_227 = 0 ;
V_219 -> V_228 -- ;
return V_35 ;
}
static void F_74 ( struct V_12 * V_13 , unsigned short V_35 )
{
T_4 V_46 = F_20 ( V_35 ) ;
struct V_44 * V_45 ;
struct V_42 * V_43 ;
struct V_218 * V_219 ;
T_4 V_230 ;
V_43 = V_13 -> V_43 ;
V_45 = & V_43 -> V_52 [ V_46 ] ;
V_230 = V_45 -> V_231 ;
V_219 = V_13 -> V_220 [ V_230 ] ;
if ( V_219 -> V_226 [ V_219 -> V_229 ] != V_225 ) {
F_21 ( V_13 , V_26 ,
L_47 ,
V_35 , V_219 -> V_228 , V_219 -> V_229 ) ;
return;
}
V_219 -> V_226 [ V_219 -> V_229 ++ ] = V_35 ;
if ( V_219 -> V_229 == F_73 ( V_13 , V_230 ) )
V_219 -> V_229 = 0 ;
V_219 -> V_228 ++ ;
}
static void F_75 ( struct V_9 * V_10 )
{
struct V_12 * V_13 = V_10 -> V_13 ;
struct V_37 * V_37 ;
F_74 ( V_13 , V_10 -> V_49 ) ;
V_10 -> V_13 = NULL ;
V_13 -> V_232 [ F_20 ( V_10 -> V_49 ) ] = NULL ;
if ( ! V_10 -> V_39 )
return;
V_37 = V_10 -> V_39 ;
V_10 -> V_39 = NULL ;
if ( V_37 -> V_214 ) {
F_76 ( V_37 ,
V_37 -> V_233 ) ;
V_37 -> V_214 = 0 ;
}
}
static int F_77 ( struct V_2 * V_3 ,
struct V_234 * V_235 ,
struct V_234 * V_118 , int V_236 )
{
struct V_9 * V_10 = V_3 -> V_20 ;
struct V_12 * V_13 = V_10 -> V_13 ;
struct V_237 * V_238 ;
struct V_239 V_240 ;
unsigned int V_131 , V_241 ;
int V_65 = - V_242 ;
F_4 ( V_13 , V_21 , V_22 ,
L_48 ) ;
V_10 -> V_49 = F_70 ( V_13 ) ;
if ( V_10 -> V_49 == V_225 ) {
F_4 ( V_13 , V_26 , V_22 ,
L_49 ) ;
return V_65 ;
}
F_4 ( V_13 , V_21 , V_22 ,
L_50 ,
V_10 -> V_49 ) ;
V_13 -> V_232 [ F_20
( V_10 -> V_49 ) ] = V_3 ;
V_10 -> V_243 = 0 ;
if ( F_78 ( V_13 ) )
V_241 = sizeof( struct V_244 ) ;
else
V_241 = sizeof( struct V_245 ) ;
V_240 . V_246 = F_79 ( V_13 -> V_247 . V_248 ,
V_241 ,
& V_240 . V_249 ) ;
if ( V_240 . V_246 == NULL ) {
F_4 ( V_13 , V_26 , V_22 ,
L_51
L_52 ) ;
F_75 ( V_10 ) ;
return - V_242 ;
}
V_240 . V_250 = V_241 ;
memset ( V_240 . V_246 , 0 , V_240 . V_250 ) ;
V_131 = F_80 ( V_13 , V_118 , V_10 , & V_240 ) ;
if ( ! V_131 ) {
F_4 ( V_13 , V_26 , V_22 ,
L_53 ,
V_10 -> V_49 ) ;
F_81 ( V_13 -> V_247 . V_248 , V_240 . V_250 ,
V_240 . V_246 , V_240 . V_249 ) ;
F_75 ( V_10 ) ;
return - V_251 ;
}
V_65 = F_52 ( V_13 , V_131 , NULL , & V_240 ) ;
if ( V_65 ) {
F_4 ( V_13 , V_26 ,
V_22 | V_136 ,
L_54 ) ;
if ( V_65 != - V_92 )
F_81 ( V_13 -> V_247 . V_248 , V_240 . V_250 ,
V_240 . V_246 , V_240 . V_249 ) ;
F_75 ( V_10 ) ;
return V_65 ;
}
V_238 = (struct V_237 * ) V_240 . V_246 ;
V_10 = V_3 -> V_20 ;
V_10 -> V_252 = V_238 -> V_253 ;
V_10 -> V_243 = 1 ;
F_4 ( V_13 , V_21 , V_22 ,
L_55 ) ;
F_81 ( V_13 -> V_247 . V_248 , V_240 . V_250 ,
V_240 . V_246 , V_240 . V_249 ) ;
return 0 ;
}
struct V_2 *
F_82 ( struct V_7 * V_8 , struct V_234 * V_118 ,
int V_236 )
{
struct V_12 * V_13 ;
struct V_9 * V_10 ;
struct V_2 * V_3 ;
int V_65 ;
if ( ! V_8 ) {
V_65 = - V_254 ;
F_2 ( L_56 ) ;
return F_83 ( V_65 ) ;
}
V_13 = F_15 ( V_8 ) ;
if ( ! F_3 ( V_13 ) ) {
V_65 = - V_255 ;
F_4 ( V_13 , V_21 , V_22 ,
L_2 , V_13 -> V_23 ) ;
return F_83 ( V_65 ) ;
}
if ( ! F_55 ( V_142 , & V_13 -> V_23 ) ) {
V_65 = - V_92 ;
F_4 ( V_13 , V_256 , V_22 ,
L_57 ) ;
return F_83 ( V_65 ) ;
}
V_3 = F_84 ( sizeof( struct V_9 ) ) ;
if ( ! V_3 ) {
V_65 = - V_242 ;
return F_83 ( V_65 ) ;
}
V_10 = V_3 -> V_20 ;
V_10 -> V_13 = V_13 ;
V_10 -> V_257 = V_3 ;
V_65 = F_77 ( V_3 , NULL , V_118 , V_236 ) ;
if ( V_65 ) {
F_4 ( V_13 , V_26 , V_22 ,
L_58 ) ;
goto V_258;
}
return V_3 ;
V_258:
F_85 ( V_3 ) ;
return F_83 ( V_65 ) ;
}
int F_86 ( struct V_2 * V_3 , int V_259 )
{
struct V_9 * V_10 = V_3 -> V_20 ;
F_4 ( V_10 -> V_13 , V_21 , V_22 ,
L_59 ) ;
if ( V_10 -> V_243 == 1 )
return 1 ;
else
return 0 ;
}
static void F_87 ( struct V_12 * V_13 )
{
T_4 V_260 ;
struct V_261 * V_262 ;
struct V_42 * V_43 ;
struct V_263 * V_264 ;
V_43 = V_13 -> V_43 ;
V_264 = V_43 -> V_265 ;
for ( V_260 = 0 ; V_260 < V_13 -> V_266 ; V_260 ++ ) {
V_262 = & V_264 -> V_267 [ V_260 ] ;
F_88 ( & V_262 -> V_268 ) ;
F_89 ( V_262 , V_269 ) ;
F_90 ( & V_262 -> V_268 ) ;
}
}
static int F_91 ( struct V_9 * V_10 , int V_270 )
{
int V_65 = 0 ;
unsigned int V_131 ;
struct V_12 * V_13 = V_10 -> V_13 ;
V_131 = F_92 ( V_13 , V_10 -> V_49 , V_270 ) ;
if ( ! V_131 ) {
F_4 ( V_13 , V_21 , V_22 ,
L_60 ,
V_10 -> V_49 ) ;
V_65 = - V_251 ;
}
V_65 = F_52 ( V_13 , V_131 , NULL , NULL ) ;
F_87 ( V_13 ) ;
return V_65 ;
}
void F_93 ( struct V_2 * V_3 )
{
struct V_37 * V_37 ;
struct V_9 * V_10 ;
struct V_12 * V_13 ;
unsigned int V_131 ;
T_7 V_271 , V_272 ;
unsigned short V_273 = V_274 ;
T_4 V_46 ;
V_10 = V_3 -> V_20 ;
V_13 = V_10 -> V_13 ;
F_4 ( V_13 , V_21 , V_22 ,
L_61 ,
V_10 -> V_49 ) ;
V_46 = F_20 ( V_10 -> V_49 ) ;
if ( ! V_13 -> V_232 [ V_46 ] ) {
F_21 ( V_13 , V_26 ,
L_62 ,
V_46 ,
V_10 -> V_49 ) ;
return;
}
if ( V_10 -> V_39 ) {
V_37 = V_10 -> V_39 ;
F_94 ( V_37 -> V_39 ) ;
V_271 = ~ V_275 ;
V_272 = V_276 ;
} else {
V_271 = V_275 ;
V_272 = V_277 ;
}
if ( ! F_3 ( V_13 ) ) {
F_4 ( V_13 , V_21 , V_22 ,
L_2 , V_13 -> V_23 ) ;
goto V_258;
}
V_131 = F_95 ( V_13 , V_10 ,
V_10 -> V_49 ,
V_271 ,
V_273 ) ;
if ( ! V_131 ) {
F_4 ( V_13 , V_26 , V_22 ,
L_63 ,
V_10 -> V_49 ) ;
}
F_52 ( V_13 , V_131 , NULL , NULL ) ;
F_91 ( V_10 , V_272 ) ;
V_258:
F_96 ( V_278 ) ;
F_75 ( V_10 ) ;
if ( ! V_13 -> V_50 [ V_46 ] )
F_21 ( V_13 , V_26 ,
L_64 ,
V_46 ,
V_10 -> V_49 ) ;
V_13 -> V_50 [ V_46 ] = NULL ;
F_85 ( V_10 -> V_257 ) ;
}
T_8 F_97 ( int V_93 , int V_67 )
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
return V_279 ;
default:
return 0 ;
}
case V_280 :
switch ( V_67 ) {
case V_161 :
case V_162 :
case V_163 :
case V_164 :
return V_279 ;
default:
return 0 ;
}
case V_281 :
switch ( V_67 ) {
case V_124 :
case V_128 :
case V_282 :
case V_283 :
case V_117 :
case V_115 :
case V_284 :
case V_285 :
case V_286 :
case V_287 :
case V_288 :
case V_289 :
case V_290 :
case V_291 :
case V_122 :
case V_126 :
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
case V_305 :
return V_279 ;
default:
return 0 ;
}
}
return 0 ;
}
