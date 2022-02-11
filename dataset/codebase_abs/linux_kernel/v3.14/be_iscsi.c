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
int V_71 = 0 ;
if ( F_31 ( V_13 ) ) {
F_3 ( V_13 , V_20 , V_24 ,
L_20 ) ;
return - V_77 ;
}
switch ( V_64 -> V_72 ) {
case V_78 :
if ( V_64 -> V_79 [ 0 ] != V_80 )
V_71 = F_32 ( V_13 , V_81 ) ;
break;
case V_82 :
V_71 = F_32 ( V_13 ,
* ( ( T_3 * ) V_64 -> V_79 ) ) ;
break;
default:
F_3 ( V_13 , V_83 , V_24 ,
L_21 ,
V_64 -> V_72 ) ;
return - V_84 ;
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
case V_85 :
V_71 = F_34 ( V_13 , V_64 ) ;
break;
case V_73 :
if ( V_64 -> V_79 [ 0 ] == V_86 )
V_71 = F_29 ( V_13 , V_64 ,
NULL , V_86 ) ;
else if ( V_64 -> V_79 [ 0 ] == V_76 )
V_71 = F_26 ( V_8 , V_64 ,
V_65 , V_66 ) ;
else
F_3 ( V_13 , V_20 , V_24 ,
L_22 ,
V_64 -> V_79 [ 0 ] ) ;
break;
case V_87 :
if ( V_64 -> V_79 [ 0 ] == V_88 )
V_71 = F_18 ( V_13 ) ;
else
F_25 ( V_13 -> V_54 ) ;
break;
case V_75 :
case V_74 :
V_71 = F_26 ( V_8 , V_64 ,
V_65 , V_66 ) ;
break;
case V_78 :
case V_82 :
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
case V_87 :
if ( V_64 -> V_79 [ 0 ] == V_88 )
V_71 = F_20 ( V_13 ) ;
else {
F_25 ( V_13 -> V_57 ) ;
V_71 = 0 ;
}
break;
case V_89 :
V_71 = F_29 ( V_13 , V_64 , NULL ,
V_76 ) ;
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
struct V_69 * V_90 ;
T_5 V_91 = V_66 ;
int V_71 = 0 ;
if ( V_13 -> V_22 & V_23 ) {
F_3 ( V_13 , V_20 , V_24 ,
L_24 ) ;
return - V_92 ;
}
F_37 (attrib, data, dt_len, rm_len) {
V_64 = F_28 ( V_90 ) ;
if ( V_64 -> V_93 != V_94 )
continue;
if ( V_64 -> V_95 ) {
F_3 ( V_13 , V_20 , V_24 ,
L_25
L_26 ,
V_64 -> V_95 ) ;
return - V_42 ;
}
switch ( V_64 -> V_96 ) {
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
V_64 -> V_96 ) ;
break;
}
if ( V_71 )
return V_71 ;
}
return V_71 ;
}
static int F_38 ( struct V_12 * V_13 ,
struct V_97 * V_98 , int V_72 ,
char * V_99 )
{
struct V_59 * V_60 ;
int V_100 , V_101 = V_61 ;
if ( V_98 -> V_96 == V_58 )
V_101 = V_62 ;
V_100 = F_22 ( V_13 , V_101 , & V_60 ) ;
if ( V_100 )
return V_100 ;
switch ( V_72 ) {
case V_74 :
V_100 = sprintf ( V_99 , L_28 , V_60 -> V_102 . V_103 ) ;
break;
case V_89 :
V_100 = sprintf ( V_99 , L_29 , V_60 -> V_102 . V_103 ) ;
break;
case V_73 :
if ( ! V_60 -> V_104 )
V_100 = sprintf ( V_99 , L_30 ) ;
else
V_100 = sprintf ( V_99 , L_31 ) ;
break;
case V_75 :
V_100 = sprintf ( V_99 , L_28 , V_60 -> V_102 . V_105 ) ;
break;
case V_78 :
V_100 = sprintf ( V_99 , L_32 ,
( V_60 -> V_106 == V_81 )
? L_33 : L_34 ) ;
break;
case V_107 :
if ( V_60 -> V_106 == V_81 )
V_100 = - V_42 ;
else
V_100 = sprintf ( V_99 , L_35 ,
( V_60 -> V_106 &
V_108 ) ) ;
break;
case V_109 :
if ( V_60 -> V_106 == V_81 )
V_100 = - V_42 ;
else
V_100 = sprintf ( V_99 , L_35 ,
( ( V_60 -> V_106 >> 13 ) &
V_110 ) ) ;
break;
default:
F_39 ( 1 ) ;
}
F_23 ( V_60 ) ;
return V_100 ;
}
int F_40 ( struct V_97 * V_98 ,
enum V_111 V_93 ,
int V_72 , char * V_99 )
{
struct V_7 * V_8 = F_41 ( V_98 ) ;
struct V_12 * V_13 = F_11 ( V_8 ) ;
struct V_112 V_113 ;
int V_100 = - V_84 ;
if ( V_13 -> V_22 & V_23 ) {
F_3 ( V_13 , V_20 , V_24 ,
L_24 ) ;
return - V_92 ;
}
switch ( V_72 ) {
case V_74 :
case V_75 :
case V_73 :
case V_89 :
case V_78 :
case V_107 :
case V_109 :
V_100 = F_38 ( V_13 , V_98 , V_72 , V_99 ) ;
break;
case V_87 :
V_100 = sprintf ( V_99 , L_36 ) ;
break;
case V_85 :
memset ( & V_113 , 0 , sizeof( V_113 ) ) ;
V_100 = F_42 ( V_13 , V_61 , & V_113 ) ;
if ( ! V_100 )
V_100 = sprintf ( V_99 , L_28 , & V_113 . V_102 . V_103 ) ;
break;
default:
V_100 = - V_84 ;
}
return V_100 ;
}
int F_43 ( struct V_2 * V_3 ,
enum V_114 V_72 , char * V_99 )
{
struct V_9 * V_10 = V_3 -> V_21 ;
int V_100 = 0 ;
F_3 ( V_10 -> V_13 , V_25 ,
V_24 ,
L_37
L_38 , V_72 ) ;
switch ( V_72 ) {
case V_115 :
V_100 = sprintf ( V_99 , L_39 , V_10 -> V_116 ) ;
break;
case V_117 :
if ( V_10 -> V_101 == V_61 )
V_100 = sprintf ( V_99 , L_28 , & V_10 -> V_118 ) ;
else
V_100 = sprintf ( V_99 , L_29 , & V_10 -> V_119 ) ;
break;
default:
return - V_84 ;
}
return V_100 ;
}
int F_44 ( struct V_34 * V_36 ,
enum V_114 V_72 , char * V_99 , int V_120 )
{
struct V_38 * V_39 = V_36 -> V_21 ;
struct V_14 * V_121 = V_39 -> V_121 ;
struct V_12 * V_13 = NULL ;
int V_71 ;
V_13 = ( (struct V_37 * ) V_39 -> V_21 ) -> V_13 ;
F_3 ( V_13 , V_25 , V_24 ,
L_40
L_38 , V_72 ) ;
V_71 = F_45 ( V_36 , V_72 , V_99 , V_120 ) ;
if ( V_71 )
return V_71 ;
switch ( V_72 ) {
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
static int F_46 ( char * V_99 , struct V_12 * V_13 )
{
int V_130 ;
unsigned int V_131 ;
struct V_132 * V_133 ;
struct V_134 * V_135 ;
V_131 = F_47 ( V_13 ) ;
if ( ! V_131 ) {
F_3 ( V_13 , V_20 , V_24 ,
L_41 ) ;
return - V_92 ;
}
V_130 = F_48 ( V_13 , V_131 , & V_133 , NULL ) ;
if ( V_130 ) {
F_3 ( V_13 , V_20 ,
V_24 | V_136 ,
L_42 ) ;
return V_130 ;
}
V_135 = F_49 ( V_133 ) ;
V_130 = sprintf ( V_99 , L_32 , V_135 -> V_137 ) ;
return V_130 ;
}
static void F_50 ( struct V_7 * V_8 )
{
struct V_12 * V_13 = F_11 ( V_8 ) ;
struct V_138 * V_139 = V_8 -> V_140 ;
V_139 -> V_141 = ( V_13 -> V_22 == V_142 ) ?
V_143 : V_144 ;
}
static int F_51 ( struct V_7 * V_8 )
{
int V_130 ;
unsigned int V_131 ;
struct V_132 * V_133 ;
struct V_145 * V_135 ;
struct V_12 * V_13 = F_11 ( V_8 ) ;
struct V_138 * V_139 = V_8 -> V_140 ;
V_131 = F_52 ( V_13 ) ;
if ( ! V_131 ) {
F_3 ( V_13 , V_20 , V_24 ,
L_43 ) ;
return - V_92 ;
}
V_130 = F_48 ( V_13 , V_131 , & V_133 , NULL ) ;
if ( V_130 ) {
F_3 ( V_13 , V_20 ,
V_24 | V_136 ,
L_44 ) ;
return V_130 ;
}
V_135 = F_49 ( V_133 ) ;
switch ( V_135 -> V_146 ) {
case V_147 :
V_139 -> V_148 = V_149 ;
break;
case V_150 :
V_139 -> V_148 = V_150 ;
break;
case V_151 :
V_139 -> V_148 = V_152 ;
break;
case V_153 :
V_139 -> V_148 = V_154 ;
break;
default:
V_139 -> V_148 = V_155 ;
}
return 0 ;
}
int F_53 ( struct V_7 * V_8 ,
enum V_156 V_72 , char * V_99 )
{
struct V_12 * V_13 = F_11 ( V_8 ) ;
int V_157 = 0 ;
if ( V_13 -> V_22 & V_23 ) {
F_3 ( V_13 , V_20 , V_24 ,
L_24 ) ;
return - V_92 ;
} else {
F_3 ( V_13 , V_25 , V_24 ,
L_45
L_46 , V_72 ) ;
}
switch ( V_72 ) {
case V_158 :
V_157 = F_54 ( V_99 , V_13 ) ;
if ( V_157 < 0 ) {
F_3 ( V_13 , V_20 , V_24 ,
L_47 ) ;
return V_157 ;
}
break;
case V_159 :
V_157 = F_46 ( V_99 , V_13 ) ;
if ( V_157 < 0 ) {
F_3 ( V_13 , V_20 , V_24 ,
L_48 ) ;
return V_157 ;
}
break;
case V_160 :
F_50 ( V_8 ) ;
V_157 = sprintf ( V_99 , L_32 , F_55 ( V_8 ) ) ;
break;
case V_161 :
V_157 = F_51 ( V_8 ) ;
if ( V_157 ) {
F_3 ( V_13 , V_20 , V_24 ,
L_49 ) ;
return V_157 ;
}
V_157 = sprintf ( V_99 , L_32 , F_56 ( V_8 ) ) ;
break;
default:
return F_57 ( V_8 , V_72 , V_99 ) ;
}
return V_157 ;
}
int F_54 ( char * V_99 , struct V_12 * V_13 )
{
struct V_162 V_135 ;
int V_130 ;
if ( V_13 -> V_163 )
return F_58 ( V_99 , V_13 -> V_164 , V_165 ) ;
memset ( & V_135 , 0 , sizeof( V_135 ) ) ;
V_130 = F_59 ( V_13 , & V_135 ) ;
if ( V_130 )
return V_130 ;
V_13 -> V_163 = true ;
memcpy ( V_13 -> V_164 , V_135 . V_164 , V_165 ) ;
return F_58 ( V_99 , V_13 -> V_164 , V_165 ) ;
}
void F_60 ( struct V_34 * V_36 ,
struct V_166 * V_167 )
{
struct V_38 * V_39 = V_36 -> V_21 ;
struct V_12 * V_13 = NULL ;
V_13 = ( (struct V_37 * ) V_39 -> V_21 ) -> V_13 ;
F_3 ( V_13 , V_25 , V_24 ,
L_50 ) ;
V_167 -> V_168 = V_39 -> V_168 ;
V_167 -> V_169 = V_39 -> V_169 ;
V_167 -> V_170 = V_39 -> V_171 ;
V_167 -> V_172 = V_39 -> V_173 ;
V_167 -> V_174 = V_39 -> V_175 ;
V_167 -> V_176 = V_39 -> V_177 ;
V_167 -> V_178 = V_39 -> V_179 ;
V_167 -> V_180 = V_39 -> V_181 ;
V_167 -> V_182 = V_39 -> V_183 ;
V_167 -> V_184 = 0 ;
V_167 -> V_185 = 0 ;
V_167 -> V_186 = 0 ;
strcpy ( V_167 -> V_187 [ 0 ] . V_188 , L_51 ) ;
V_167 -> V_187 [ 0 ] . V_79 = V_39 -> V_189 ;
}
static void F_61 ( struct V_37 * V_37 ,
struct V_190 * V_26 )
{
struct V_38 * V_39 = V_37 -> V_39 ;
struct V_14 * V_121 = V_39 -> V_121 ;
F_62 ( struct V_191 , V_192 ,
V_26 , V_121 -> V_127 ) ;
F_62 ( struct V_191 ,
V_193 , V_26 ,
V_39 -> V_129 ) ;
F_62 ( struct V_191 , V_194 ,
V_26 , V_121 -> V_123 ) ;
F_62 ( struct V_191 , V_195 , V_26 ,
V_121 -> V_195 ) ;
F_62 ( struct V_191 , V_196 , V_26 ,
V_39 -> V_197 ) ;
F_62 ( struct V_191 , V_198 , V_26 ,
V_39 -> V_199 ) ;
F_62 ( struct V_191 , V_200 , V_26 ,
V_121 -> V_201 ) ;
F_62 ( struct V_191 , V_202 , V_26 ,
V_121 -> V_203 ) ;
F_62 ( struct V_191 ,
V_204 , V_26 ,
V_121 -> V_205 ) ;
F_62 ( struct V_191 ,
V_206 , V_26 ,
V_121 -> V_207 ) ;
F_62 ( struct V_191 , V_208 , V_26 ,
V_121 -> V_208 ) ;
F_62 ( struct V_191 , V_209 , V_26 ,
( V_39 -> V_209 - 1 ) ) ;
F_62 ( struct V_191 ,
V_210 , V_26 ,
V_39 -> V_125 ) ;
}
int F_63 ( struct V_34 * V_36 )
{
struct V_38 * V_39 = V_36 -> V_21 ;
struct V_37 * V_37 = V_39 -> V_21 ;
struct V_9 * V_10 ;
struct V_190 V_26 ;
struct V_12 * V_13 ;
V_13 = ( (struct V_37 * ) V_39 -> V_21 ) -> V_13 ;
if ( V_13 -> V_22 & V_23 ) {
F_3 ( V_13 , V_20 , V_24 ,
L_24 ) ;
return - V_92 ;
} else {
F_3 ( V_37 -> V_13 , V_25 ,
V_24 ,
L_52 ) ;
}
memset ( & V_26 , 0 , sizeof( struct V_190 ) ) ;
V_10 = V_37 -> V_3 ;
if ( ! V_10 )
F_3 ( V_37 -> V_13 , V_20 ,
V_24 ,
L_53 ) ;
V_37 -> V_211 = 0 ;
F_61 ( V_37 , & V_26 ) ;
F_64 ( V_37 , & V_26 ) ;
F_65 ( V_36 ) ;
return 0 ;
}
static int F_66 ( struct V_12 * V_13 )
{
unsigned short V_35 = 0xFFFF , V_212 ;
struct V_213 * V_214 = NULL ;
T_3 V_215 , V_216 ;
V_215 = ( V_13 -> V_217 [ V_218 ] ) ?
F_67 ( V_13 ) : 0 ;
V_216 = ( V_13 -> V_217 [ V_219 ] ) ?
F_68 ( V_13 ) : 0 ;
V_212 = ( V_215 > V_216 ) ?
V_218 : V_219 ;
if ( F_69 ( V_212 , ( void * ) & V_13 -> V_220 . V_221 ) ) {
V_214 = V_13 -> V_217 [ V_212 ] ;
if ( ! V_214 -> V_222 )
return V_35 ;
V_35 = V_214 -> V_223 [ V_214 -> V_224 ++ ] ;
if ( V_214 -> V_224 == F_70 (
V_13 , V_212 ) )
V_214 -> V_224 = 0 ;
V_214 -> V_222 -- ;
}
return V_35 ;
}
static void F_71 ( struct V_12 * V_13 , unsigned short V_35 )
{
T_3 V_225 ;
struct V_45 * V_46 ;
struct V_47 * V_48 ;
struct V_213 * V_214 = NULL ;
T_3 V_40 = F_14 ( V_35 ) ;
V_46 = V_13 -> V_46 ;
V_48 = & V_46 -> V_50 [ V_40 ] ;
V_225 = V_48 -> V_226 ;
V_214 = V_13 -> V_217 [ V_225 ] ;
V_214 -> V_222 ++ ;
V_214 -> V_223 [ V_214 -> V_227 ++ ] = V_35 ;
if ( V_214 -> V_227 == F_70 ( V_13 , V_225 ) )
V_214 -> V_227 = 0 ;
}
static void F_72 ( struct V_9 * V_10 )
{
struct V_12 * V_13 = V_10 -> V_13 ;
struct V_37 * V_37 ;
F_71 ( V_13 , V_10 -> V_51 ) ;
V_10 -> V_13 = NULL ;
V_13 -> V_228 [ F_14
( V_10 -> V_51 ) ] = NULL ;
if ( ! V_10 -> V_39 )
return;
V_37 = V_10 -> V_39 ;
if ( V_37 -> V_211 ) {
F_73 ( V_37 ,
V_37 -> V_229 ) ;
V_37 -> V_211 = 0 ;
}
}
static int F_74 ( struct V_2 * V_3 ,
struct V_230 * V_231 ,
struct V_230 * V_118 , int V_232 )
{
struct V_9 * V_10 = V_3 -> V_21 ;
struct V_12 * V_13 = V_10 -> V_13 ;
struct V_233 * V_234 ;
struct V_235 V_236 ;
unsigned int V_131 ;
int V_71 = - V_237 ;
F_3 ( V_13 , V_25 , V_24 ,
L_54 ) ;
V_10 -> V_51 = F_66 ( V_13 ) ;
if ( V_10 -> V_51 == 0xFFFF ) {
F_3 ( V_13 , V_20 , V_24 ,
L_55 ) ;
return V_71 ;
}
F_3 ( V_13 , V_25 , V_24 ,
L_56 ,
V_10 -> V_51 ) ;
V_13 -> V_228 [ F_14
( V_10 -> V_51 ) ] = V_3 ;
V_10 -> V_238 = 0 ;
V_236 . V_239 = F_75 ( V_13 -> V_240 . V_241 ,
sizeof( struct V_242 ) ,
& V_236 . V_243 ) ;
if ( V_236 . V_239 == NULL ) {
F_3 ( V_13 , V_20 , V_24 ,
L_57
L_58 ) ;
F_72 ( V_10 ) ;
return - V_237 ;
}
V_236 . V_244 = sizeof( struct V_242 ) ;
memset ( V_236 . V_239 , 0 , V_236 . V_244 ) ;
V_131 = F_76 ( V_13 , V_118 , V_10 , & V_236 ) ;
if ( V_131 <= 0 ) {
F_3 ( V_13 , V_20 , V_24 ,
L_59 ,
V_10 -> V_51 ) ;
F_77 ( V_13 -> V_240 . V_241 , V_236 . V_244 ,
V_236 . V_239 , V_236 . V_243 ) ;
F_72 ( V_10 ) ;
return - V_245 ;
}
V_71 = F_48 ( V_13 , V_131 , NULL , V_236 . V_239 ) ;
if ( V_71 ) {
F_3 ( V_13 , V_20 ,
V_24 | V_136 ,
L_60 ) ;
F_77 ( V_13 -> V_240 . V_241 , V_236 . V_244 ,
V_236 . V_239 , V_236 . V_243 ) ;
F_72 ( V_10 ) ;
return - V_92 ;
}
V_234 = (struct V_233 * ) V_236 . V_239 ;
V_10 = V_3 -> V_21 ;
V_10 -> V_246 = V_234 -> V_247 ;
V_10 -> V_238 = 1 ;
F_3 ( V_13 , V_25 , V_24 ,
L_61 ) ;
F_77 ( V_13 -> V_240 . V_241 , V_236 . V_244 ,
V_236 . V_239 , V_236 . V_243 ) ;
return 0 ;
}
struct V_2 *
F_78 ( struct V_7 * V_8 , struct V_230 * V_118 ,
int V_232 )
{
struct V_12 * V_13 ;
struct V_9 * V_10 ;
struct V_2 * V_3 ;
int V_71 ;
if ( V_8 )
V_13 = F_11 ( V_8 ) ;
else {
V_71 = - V_248 ;
F_2 ( V_20
L_62 ) ;
return F_79 ( V_71 ) ;
}
if ( F_80 ( V_13 ) ) {
V_71 = - V_77 ;
F_3 ( V_13 , V_83 , V_24 ,
L_63 ) ;
return F_79 ( V_71 ) ;
}
if ( V_13 -> V_22 & V_23 ) {
V_71 = - V_92 ;
F_3 ( V_13 , V_20 , V_24 ,
L_24 ) ;
return F_79 ( V_71 ) ;
} else if ( V_13 -> V_22 & V_249 ) {
V_71 = - V_92 ;
F_3 ( V_13 , V_83 , V_24 ,
L_64 ) ;
return F_79 ( V_71 ) ;
}
V_3 = F_81 ( sizeof( struct V_9 ) ) ;
if ( ! V_3 ) {
V_71 = - V_237 ;
return F_79 ( V_71 ) ;
}
V_10 = V_3 -> V_21 ;
V_10 -> V_13 = V_13 ;
V_10 -> V_250 = V_3 ;
V_71 = F_74 ( V_3 , NULL , V_118 , V_232 ) ;
if ( V_71 ) {
F_3 ( V_13 , V_20 , V_24 ,
L_65 ) ;
goto V_251;
}
return V_3 ;
V_251:
F_82 ( V_3 ) ;
return F_79 ( V_71 ) ;
}
int F_83 ( struct V_2 * V_3 , int V_252 )
{
struct V_9 * V_10 = V_3 -> V_21 ;
F_3 ( V_10 -> V_13 , V_25 , V_24 ,
L_66 ) ;
if ( V_10 -> V_238 == 1 )
return 1 ;
else
return 0 ;
}
static int F_84 ( struct V_9 * V_10 , int V_253 )
{
int V_71 = 0 ;
unsigned int V_131 ;
struct V_12 * V_13 = V_10 -> V_13 ;
V_131 = F_85 ( V_13 , V_10 -> V_51 , V_253 ) ;
if ( ! V_131 ) {
F_3 ( V_13 , V_25 , V_24 ,
L_67 ,
V_10 -> V_51 ) ;
V_71 = - V_245 ;
}
V_71 = F_48 ( V_13 , V_131 , NULL , NULL ) ;
return V_71 ;
}
static int F_86 ( struct V_12 * V_13 ,
unsigned int V_35 )
{
T_3 V_40 = F_14 ( V_35 ) ;
if ( V_13 -> V_41 [ V_40 ] )
V_13 -> V_41 [ V_40 ] = NULL ;
else {
F_3 ( V_13 , V_25 , V_24 ,
L_68 ) ;
return - V_42 ;
}
return 0 ;
}
void F_87 ( struct V_2 * V_3 )
{
struct V_37 * V_37 ;
struct V_9 * V_10 ;
struct V_12 * V_13 ;
unsigned int V_131 ;
T_6 V_254 , V_255 ;
unsigned short V_256 = V_257 ;
V_10 = V_3 -> V_21 ;
V_13 = V_10 -> V_13 ;
F_3 ( V_13 , V_25 , V_24 ,
L_69 ,
V_10 -> V_51 ) ;
if ( V_10 -> V_39 ) {
V_37 = V_10 -> V_39 ;
F_88 ( V_37 -> V_39 ) ;
V_254 = ~ V_258 ;
V_255 = V_259 ;
} else {
V_254 = V_258 ;
V_255 = V_260 ;
}
if ( V_13 -> V_22 & V_23 ) {
F_3 ( V_13 , V_20 , V_24 ,
L_2 ) ;
goto V_251;
}
V_131 = F_89 ( V_13 , V_10 ,
V_10 -> V_51 ,
V_254 ,
V_256 ) ;
if ( ! V_131 ) {
F_3 ( V_13 , V_20 , V_24 ,
L_70 ,
V_10 -> V_51 ) ;
}
F_48 ( V_13 , V_131 , NULL , NULL ) ;
F_84 ( V_10 , V_255 ) ;
V_251:
F_72 ( V_10 ) ;
F_86 ( V_13 , V_10 -> V_51 ) ;
F_82 ( V_10 -> V_250 ) ;
}
T_7 F_90 ( int V_93 , int V_72 )
{
switch ( V_93 ) {
case V_94 :
switch ( V_72 ) {
case V_87 :
case V_74 :
case V_75 :
case V_73 :
case V_85 :
case V_89 :
case V_107 :
case V_109 :
case V_78 :
return V_261 ;
default:
return 0 ;
}
case V_262 :
switch ( V_72 ) {
case V_158 :
case V_159 :
case V_160 :
case V_161 :
return V_261 ;
default:
return 0 ;
}
case V_263 :
switch ( V_72 ) {
case V_124 :
case V_128 :
case V_264 :
case V_265 :
case V_117 :
case V_115 :
case V_266 :
case V_267 :
case V_268 :
case V_269 :
case V_270 :
case V_271 :
case V_272 :
case V_273 :
case V_122 :
case V_126 :
case V_274 :
case V_275 :
case V_276 :
case V_277 :
case V_278 :
case V_279 :
case V_280 :
case V_281 :
case V_282 :
case V_283 :
case V_284 :
case V_285 :
case V_286 :
case V_287 :
return V_261 ;
default:
return 0 ;
}
}
return 0 ;
}
