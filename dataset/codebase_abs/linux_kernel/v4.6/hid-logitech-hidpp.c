static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_3 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
int V_6 , V_7 ;
V_5 = F_2 ( V_2 ) ;
switch ( V_3 -> V_8 ) {
case V_9 :
V_6 = V_10 ;
break;
case V_11 :
V_6 = V_12 ;
break;
case V_13 :
V_6 = V_14 ;
break;
default:
return - V_15 ;
}
V_3 -> V_16 = 0xff ;
if ( V_5 -> V_17 & V_18 ) {
V_7 = F_3 ( V_2 , ( V_19 * ) V_3 , V_6 ) ;
} else {
V_7 = F_4 ( V_2 , V_3 -> V_8 ,
( V_19 * ) V_3 , V_6 , V_20 ,
V_21 ) ;
}
return V_7 == V_6 ? 0 : - 1 ;
}
static int F_5 ( struct V_4 * V_5 ,
struct V_3 * V_22 ,
struct V_3 * V_23 )
{
int V_7 ;
F_6 ( & V_5 -> V_24 ) ;
V_5 -> V_25 = V_23 ;
V_5 -> V_26 = false ;
* V_23 = * V_22 ;
V_7 = F_1 ( V_5 -> V_27 , V_22 ) ;
if ( V_7 ) {
F_7 ( L_1 , V_7 ) ;
memset ( V_23 , 0 , sizeof( struct V_3 ) ) ;
goto exit;
}
if ( ! F_8 ( V_5 -> V_28 , V_5 -> V_26 ,
5 * V_29 ) ) {
F_7 ( L_2 , V_30 ) ;
memset ( V_23 , 0 , sizeof( struct V_3 ) ) ;
V_7 = - V_31 ;
}
if ( V_23 -> V_8 == V_9 &&
V_23 -> V_32 . V_33 == V_34 ) {
V_7 = V_23 -> V_32 . V_35 [ 1 ] ;
F_7 ( L_3 , V_30 , V_7 ) ;
goto exit;
}
if ( ( V_23 -> V_8 == V_11 ||
V_23 -> V_8 == V_13 ) &&
V_23 -> V_36 . V_37 == V_38 ) {
V_7 = V_23 -> V_36 . V_35 [ 1 ] ;
F_7 ( L_4 , V_30 , V_7 ) ;
goto exit;
}
exit:
F_9 ( & V_5 -> V_24 ) ;
return V_7 ;
}
static int F_10 ( struct V_4 * V_5 ,
V_19 V_39 , V_19 V_40 , V_19 * V_35 , int V_41 ,
struct V_3 * V_23 )
{
struct V_3 * V_22 ;
int V_7 ;
if ( V_41 > sizeof( V_22 -> V_36 . V_35 ) )
return - V_42 ;
V_22 = F_11 ( sizeof( struct V_3 ) , V_43 ) ;
if ( ! V_22 )
return - V_44 ;
if ( V_41 > ( V_12 - 4 ) )
V_22 -> V_8 = V_13 ;
else
V_22 -> V_8 = V_11 ;
V_22 -> V_36 . V_37 = V_39 ;
V_22 -> V_36 . V_40 = V_40 ;
memcpy ( & V_22 -> V_36 . V_35 , V_35 , V_41 ) ;
V_7 = F_5 ( V_5 , V_22 , V_23 ) ;
F_12 ( V_22 ) ;
return V_7 ;
}
static int F_13 ( struct V_4 * V_45 ,
V_19 V_8 , V_19 V_33 , V_19 V_46 , V_19 * V_35 , int V_41 ,
struct V_3 * V_23 )
{
struct V_3 * V_22 ;
int V_7 , V_47 ;
switch ( V_8 ) {
case V_9 :
V_47 = V_10 - 4 ;
break;
case V_11 :
V_47 = V_12 - 4 ;
break;
case V_13 :
V_47 = V_14 - 4 ;
break;
default:
return - V_42 ;
}
if ( V_41 > V_47 )
return - V_42 ;
V_22 = F_11 ( sizeof( struct V_3 ) , V_43 ) ;
if ( ! V_22 )
return - V_44 ;
V_22 -> V_8 = V_8 ;
V_22 -> V_32 . V_33 = V_33 ;
V_22 -> V_32 . V_46 = V_46 ;
memcpy ( & V_22 -> V_32 . V_35 , V_35 , V_41 ) ;
V_7 = F_5 ( V_45 , V_22 , V_23 ) ;
F_12 ( V_22 ) ;
return V_7 ;
}
static void F_14 ( struct V_48 * V_49 )
{
struct V_4 * V_5 = F_15 ( V_49 , struct V_4 ,
V_49 ) ;
F_16 ( V_5 ) ;
}
static inline bool F_17 ( struct V_3 * V_50 ,
struct V_3 * V_51 )
{
return ( V_51 -> V_36 . V_37 == V_50 -> V_36 . V_37 ) &&
( V_51 -> V_36 . V_40 == V_50 -> V_36 . V_40 ) ;
}
static inline bool F_18 ( struct V_3 * V_50 ,
struct V_3 * V_51 )
{
return ( ( V_51 -> V_32 . V_33 == V_34 ) ||
( V_51 -> V_36 . V_37 == V_38 ) ) &&
( V_51 -> V_36 . V_40 == V_50 -> V_36 . V_37 ) &&
( V_51 -> V_36 . V_35 [ 0 ] == V_50 -> V_36 . V_40 ) ;
}
static inline bool F_19 ( struct V_3 * V_52 )
{
return ( V_52 -> V_8 == V_9 ) &&
( V_52 -> V_32 . V_33 == 0x41 ) ;
}
static void F_20 ( char * * V_53 , int V_54 )
{
#define F_21 9
int V_55 ;
char * V_56 ;
if ( V_54 > F_21 &&
strncmp ( * V_53 , L_5 , F_21 ) == 0 )
return;
V_55 = F_21 + V_54 ;
V_56 = F_11 ( V_55 , V_43 ) ;
if ( ! V_56 )
return;
snprintf ( V_56 , V_55 , L_6 , * V_53 ) ;
F_12 ( * V_53 ) ;
* V_53 = V_56 ;
}
static char * F_22 ( struct V_4 * V_45 )
{
struct V_3 V_23 ;
int V_7 ;
V_19 V_35 [ 1 ] = { V_57 } ;
char * V_53 ;
int V_58 ;
V_7 = F_13 ( V_45 ,
V_9 ,
V_59 ,
V_60 ,
V_35 , 1 , & V_23 ) ;
if ( V_7 )
return NULL ;
V_58 = V_23 . V_32 . V_35 [ 1 ] ;
if ( 2 + V_58 > sizeof( V_23 . V_32 . V_35 ) )
return NULL ;
V_53 = F_11 ( V_58 + 1 , V_43 ) ;
if ( ! V_53 )
return NULL ;
memcpy ( V_53 , & V_23 . V_32 . V_35 [ 2 ] , V_58 ) ;
F_20 ( & V_53 , V_58 + 1 ) ;
return V_53 ;
}
static int F_23 ( struct V_4 * V_5 , T_1 V_61 ,
V_19 * V_37 , V_19 * V_62 )
{
struct V_3 V_23 ;
int V_7 ;
V_19 V_35 [ 2 ] = { V_61 >> 8 , V_61 & 0x00FF } ;
V_7 = F_10 ( V_5 ,
V_63 ,
V_64 ,
V_35 , 2 , & V_23 ) ;
if ( V_7 )
return V_7 ;
* V_37 = V_23 . V_36 . V_35 [ 0 ] ;
* V_62 = V_23 . V_36 . V_35 [ 1 ] ;
return V_7 ;
}
static int F_24 ( struct V_4 * V_5 )
{
struct V_3 V_23 ;
int V_7 ;
V_7 = F_10 ( V_5 ,
V_63 ,
V_65 ,
NULL , 0 , & V_23 ) ;
if ( V_7 == V_66 ) {
V_5 -> V_67 = 1 ;
V_5 -> V_68 = 0 ;
return 0 ;
}
if ( V_7 == V_69 )
return - V_70 ;
if ( V_7 > 0 ) {
F_25 ( V_5 -> V_27 , L_7 ,
V_30 , V_7 ) ;
return - V_71 ;
}
if ( V_7 )
return V_7 ;
V_5 -> V_67 = V_23 . V_36 . V_35 [ 0 ] ;
V_5 -> V_68 = V_23 . V_36 . V_35 [ 1 ] ;
return V_7 ;
}
static bool F_26 ( struct V_4 * V_5 )
{
int V_7 ;
V_7 = F_24 ( V_5 ) ;
if ( ! V_7 )
F_27 ( V_5 -> V_27 , L_8 ,
V_5 -> V_67 , V_5 -> V_68 ) ;
return V_7 == 0 ;
}
static int F_28 ( struct V_4 * V_5 ,
V_19 V_37 , V_19 * V_72 )
{
struct V_3 V_23 ;
int V_7 ;
V_7 = F_10 ( V_5 , V_37 ,
V_73 , NULL , 0 , & V_23 ) ;
if ( V_7 > 0 ) {
F_25 ( V_5 -> V_27 , L_7 ,
V_30 , V_7 ) ;
return - V_71 ;
}
if ( V_7 )
return V_7 ;
* V_72 = V_23 . V_36 . V_35 [ 0 ] ;
return V_7 ;
}
static int F_29 ( struct V_4 * V_5 ,
V_19 V_37 , V_19 V_74 , char * V_75 , int V_76 )
{
struct V_3 V_23 ;
int V_7 , V_77 ;
int V_78 ;
V_7 = F_10 ( V_5 , V_37 ,
V_79 , & V_74 , 1 ,
& V_23 ) ;
if ( V_7 > 0 ) {
F_25 ( V_5 -> V_27 , L_7 ,
V_30 , V_7 ) ;
return - V_71 ;
}
if ( V_7 )
return V_7 ;
switch ( V_23 . V_8 ) {
case V_13 :
V_78 = V_14 - 4 ;
break;
case V_11 :
V_78 = V_12 - 4 ;
break;
case V_9 :
V_78 = V_10 - 4 ;
break;
default:
return - V_71 ;
}
if ( V_76 < V_78 )
V_78 = V_76 ;
for ( V_77 = 0 ; V_77 < V_78 ; V_77 ++ )
V_75 [ V_77 ] = V_23 . V_36 . V_35 [ V_77 ] ;
return V_78 ;
}
static char * F_30 ( struct V_4 * V_5 )
{
V_19 V_62 ;
V_19 V_37 ;
V_19 V_80 ;
char * V_53 ;
unsigned V_81 = 0 ;
int V_7 ;
V_7 = F_23 ( V_5 , V_82 ,
& V_37 , & V_62 ) ;
if ( V_7 )
return NULL ;
V_7 = F_28 ( V_5 , V_37 ,
& V_80 ) ;
if ( V_7 )
return NULL ;
V_53 = F_11 ( V_80 + 1 , V_43 ) ;
if ( ! V_53 )
return NULL ;
while ( V_81 < V_80 ) {
V_7 = F_29 ( V_5 ,
V_37 , V_81 , V_53 + V_81 ,
V_80 - V_81 ) ;
if ( V_7 <= 0 ) {
F_12 ( V_53 ) ;
return NULL ;
}
V_81 += V_7 ;
}
F_20 ( & V_53 , V_80 + 1 ) ;
return V_53 ;
}
static int F_31 ( struct V_4 * V_5 ,
V_19 V_37 ,
struct V_83 * V_84 )
{
struct V_3 V_23 ;
int V_7 ;
V_19 * V_35 = ( V_19 * ) V_23 . V_36 . V_35 ;
V_7 = F_10 ( V_5 , V_37 ,
V_85 , & V_84 -> V_86 , 1 , & V_23 ) ;
if ( V_7 > 0 ) {
F_25 ( V_5 -> V_27 , L_7 ,
V_30 , V_7 ) ;
return - V_71 ;
}
if ( V_7 )
return V_7 ;
V_84 -> V_87 = V_35 [ 0 ] ;
V_84 -> V_88 = V_35 [ 1 ] ;
V_84 -> V_86 = V_35 [ 2 ] ;
V_84 -> V_89 = V_35 [ 3 ] ;
return 0 ;
}
static int F_32 ( struct V_4 * V_5 ,
V_19 V_37 , struct V_90 * V_91 )
{
struct V_3 V_23 ;
int V_7 ;
V_19 * V_35 = ( V_19 * ) V_23 . V_36 . V_35 ;
V_7 = F_10 ( V_5 , V_37 ,
V_92 , NULL , 0 , & V_23 ) ;
if ( V_7 > 0 ) {
F_25 ( V_5 -> V_27 , L_7 ,
V_30 , V_7 ) ;
return - V_71 ;
}
if ( V_7 )
return V_7 ;
V_91 -> V_93 = F_33 ( & V_35 [ 0 ] ) ;
V_91 -> V_94 = F_33 ( & V_35 [ 2 ] ) ;
V_91 -> V_95 = V_35 [ 4 ] ;
V_91 -> V_96 = V_35 [ 5 ] ;
V_91 -> V_97 = V_35 [ 7 ] ;
V_91 -> V_98 = V_35 [ 8 ] ;
V_91 -> V_99 = F_33 ( & V_35 [ 13 ] ) * 2 / 51 ;
return V_7 ;
}
static int F_34 ( struct V_4 * V_45 ,
V_19 V_37 , bool V_100 ,
bool V_101 )
{
struct V_3 V_23 ;
V_19 V_35 = V_100 | ( V_101 << 2 ) ;
return F_10 ( V_45 , V_37 ,
V_102 , & V_35 , 1 , & V_23 ) ;
}
static void F_35 ( V_19 * V_103 ,
struct V_104 * V_105 )
{
V_19 V_106 = V_103 [ 0 ] << 2 ;
V_19 V_107 = V_103 [ 2 ] << 2 ;
V_105 -> V_108 = V_106 << 6 | V_103 [ 1 ] ;
V_105 -> V_109 = V_107 << 6 | V_103 [ 3 ] ;
V_105 -> V_110 = V_103 [ 0 ] >> 6 ;
V_105 -> V_111 = V_103 [ 2 ] >> 6 ;
V_105 -> V_112 = V_103 [ 4 ] ;
V_105 -> V_113 = V_103 [ 5 ] ;
V_105 -> V_114 = V_103 [ 6 ] >> 4 ;
}
static void F_36 ( struct V_4 * V_45 ,
V_19 * V_103 , struct V_115 * V_116 )
{
memset ( V_116 , 0 , sizeof( struct V_115 ) ) ;
V_116 -> V_117 = V_103 [ 8 ] & 0x01 ;
V_116 -> V_118 = ( V_103 [ 8 ] >> 1 ) & 0x01 ;
V_116 -> V_119 = V_103 [ 15 ] & 0x0f ;
V_116 -> V_120 = ( V_103 [ 8 ] >> 2 ) & 0x01 ;
if ( V_116 -> V_119 ) {
F_35 ( & V_103 [ 2 ] , & V_116 -> V_121 [ 0 ] ) ;
F_35 ( & V_103 [ 9 ] , & V_116 -> V_121 [ 1 ] ) ;
}
}
static V_19 F_37 ( struct V_122 * V_103 , int V_123 )
{
int V_77 ;
for ( V_77 = 0 ; V_77 < V_103 -> V_124 ; V_77 ++ )
if ( V_103 -> V_125 [ V_77 ] == V_123 )
return V_77 + 1 ;
return 0 ;
}
static void F_38 ( struct V_48 * V_126 )
{
struct V_127 * V_128 = F_15 ( V_126 , struct V_127 , V_49 ) ;
struct V_122 * V_103 = V_128 -> V_103 ;
struct V_3 V_23 ;
V_19 V_129 ;
int V_7 ;
switch ( V_128 -> V_123 ) {
case V_130 :
V_128 -> V_35 [ 0 ] = V_103 -> V_131 ;
break;
case V_132 :
break;
default:
V_128 -> V_35 [ 0 ] = F_37 ( V_103 , V_128 -> V_123 ) ;
break;
}
V_7 = F_10 ( V_103 -> V_5 , V_103 -> V_37 ,
V_128 -> V_133 , V_128 -> V_35 , V_128 -> V_134 , & V_23 ) ;
if ( V_7 ) {
F_25 ( V_103 -> V_5 -> V_27 , L_9 ) ;
goto V_135;
}
switch ( V_128 -> V_133 ) {
case V_136 :
V_129 = V_23 . V_36 . V_35 [ 0 ] ;
if ( V_129 > 0 && V_129 <= V_103 -> V_124 ) {
if ( V_128 -> V_123 >= 0 )
V_103 -> V_125 [ V_129 - 1 ] = V_128 -> V_123 ;
else if ( V_128 -> V_123 >= V_130 )
V_103 -> V_131 = V_129 ;
}
break;
case V_137 :
if ( V_128 -> V_123 >= 0 )
V_103 -> V_125 [ V_128 -> V_35 [ 0 ] - 1 ] = - 1 ;
else if ( V_128 -> V_123 >= V_130 )
V_103 -> V_131 = 0 ;
break;
case V_138 :
V_103 -> V_139 = ( V_128 -> V_35 [ 0 ] << 8 ) + V_128 -> V_35 [ 1 ] ;
break;
case V_140 :
V_103 -> V_141 = ( V_128 -> V_35 [ 0 ] << 8 ) + V_128 -> V_35 [ 1 ] ;
break;
default:
break;
}
V_135:
F_39 ( & V_103 -> V_142 ) ;
F_12 ( V_128 ) ;
}
static int F_40 ( struct V_122 * V_103 , int V_123 , V_19 V_133 , V_19 * V_35 , V_19 V_134 )
{
struct V_127 * V_128 = F_11 ( sizeof( * V_128 ) , V_43 ) ;
int V_143 ;
if ( ! V_128 )
return - V_44 ;
F_41 ( & V_128 -> V_49 , F_38 ) ;
V_128 -> V_103 = V_103 ;
V_128 -> V_123 = V_123 ;
V_128 -> V_133 = V_133 ;
V_128 -> V_134 = V_134 ;
memcpy ( V_128 -> V_35 , V_35 , V_134 ) ;
F_42 ( & V_103 -> V_142 ) ;
F_43 ( V_103 -> V_144 , & V_128 -> V_49 ) ;
V_143 = F_44 ( & V_103 -> V_142 ) ;
if ( V_143 >= 20 && V_143 % 20 == 0 )
F_45 ( V_103 -> V_5 -> V_27 , L_10 , V_143 ) ;
return 0 ;
}
static int F_46 ( struct V_145 * V_146 , struct V_147 * V_148 , struct V_147 * V_149 )
{
struct V_122 * V_103 = V_146 -> V_150 -> V_151 ;
V_19 V_35 [ 20 ] ;
V_19 V_134 ;
int V_152 ;
V_35 [ 2 ] = V_148 -> V_153 . V_154 >> 8 ;
V_35 [ 3 ] = V_148 -> V_153 . V_154 & 255 ;
V_35 [ 4 ] = V_148 -> V_153 . V_155 >> 8 ;
V_35 [ 5 ] = V_148 -> V_153 . V_155 & 255 ;
switch ( V_148 -> type ) {
case V_156 :
V_152 = ( V_148 -> V_157 . V_158 . V_159 * F_47 ( ( V_148 -> V_160 * 360 ) >> 16 ) ) >> 15 ;
V_35 [ 1 ] = V_161 ;
V_35 [ 6 ] = V_152 >> 8 ;
V_35 [ 7 ] = V_152 & 255 ;
V_35 [ 8 ] = V_148 -> V_157 . V_158 . V_162 . V_163 >> 7 ;
V_35 [ 9 ] = V_148 -> V_157 . V_158 . V_162 . V_164 >> 8 ;
V_35 [ 10 ] = V_148 -> V_157 . V_158 . V_162 . V_164 & 255 ;
V_35 [ 11 ] = V_148 -> V_157 . V_158 . V_162 . V_165 >> 7 ;
V_35 [ 12 ] = V_148 -> V_157 . V_158 . V_162 . V_166 >> 8 ;
V_35 [ 13 ] = V_148 -> V_157 . V_158 . V_162 . V_166 & 255 ;
V_134 = 14 ;
F_7 ( L_11 ,
V_148 -> V_157 . V_158 . V_159 ,
V_148 -> V_160 , V_152 ) ;
F_7 ( L_12 ,
V_148 -> V_157 . V_158 . V_162 . V_163 ,
V_148 -> V_157 . V_158 . V_162 . V_164 ,
V_148 -> V_157 . V_158 . V_162 . V_165 ,
V_148 -> V_157 . V_158 . V_162 . V_166 ) ;
break;
case V_167 :
{
switch ( V_148 -> V_157 . V_168 . V_169 ) {
case V_170 :
V_35 [ 1 ] = V_171 ;
break;
case V_172 :
V_35 [ 1 ] = V_173 ;
break;
case V_174 :
V_35 [ 1 ] = V_175 ;
break;
case V_176 :
V_35 [ 1 ] = V_177 ;
break;
case V_178 :
V_35 [ 1 ] = V_179 ;
break;
default:
F_25 ( V_103 -> V_5 -> V_27 , L_13 , V_148 -> V_157 . V_168 . V_169 ) ;
return - V_42 ;
}
V_152 = ( V_148 -> V_157 . V_168 . V_180 * F_47 ( ( V_148 -> V_160 * 360 ) >> 16 ) ) >> 15 ;
V_35 [ 6 ] = V_148 -> V_157 . V_168 . V_180 >> 8 ;
V_35 [ 7 ] = V_148 -> V_157 . V_168 . V_180 & 255 ;
V_35 [ 8 ] = V_148 -> V_157 . V_168 . V_181 >> 8 ;
V_35 [ 9 ] = V_148 -> V_157 . V_168 . V_181 & 255 ;
V_35 [ 10 ] = V_148 -> V_157 . V_168 . V_182 >> 8 ;
V_35 [ 11 ] = V_148 -> V_157 . V_168 . V_182 & 255 ;
V_35 [ 12 ] = V_148 -> V_157 . V_168 . V_183 >> 8 ;
V_35 [ 13 ] = V_148 -> V_157 . V_168 . V_183 & 255 ;
V_35 [ 14 ] = V_148 -> V_157 . V_168 . V_162 . V_163 >> 7 ;
V_35 [ 15 ] = V_148 -> V_157 . V_168 . V_162 . V_164 >> 8 ;
V_35 [ 16 ] = V_148 -> V_157 . V_168 . V_162 . V_164 & 255 ;
V_35 [ 17 ] = V_148 -> V_157 . V_168 . V_162 . V_165 >> 7 ;
V_35 [ 18 ] = V_148 -> V_157 . V_168 . V_162 . V_166 >> 8 ;
V_35 [ 19 ] = V_148 -> V_157 . V_168 . V_162 . V_166 & 255 ;
V_134 = 20 ;
F_7 ( L_14 ,
V_148 -> V_157 . V_168 . V_180 , V_148 -> V_160 ,
V_148 -> V_157 . V_168 . V_181 ,
V_148 -> V_157 . V_168 . V_182 ,
V_148 -> V_157 . V_168 . V_183 ) ;
F_7 ( L_12 ,
V_148 -> V_157 . V_168 . V_162 . V_163 ,
V_148 -> V_157 . V_168 . V_162 . V_164 ,
V_148 -> V_157 . V_168 . V_162 . V_165 ,
V_148 -> V_157 . V_168 . V_162 . V_166 ) ;
break;
}
case V_184 :
V_35 [ 1 ] = V_185 ;
V_152 = ( V_148 -> V_157 . V_186 . V_187 * F_47 ( ( V_148 -> V_160 * 360 ) >> 16 ) ) >> 15 ;
V_35 [ 6 ] = V_152 >> 8 ;
V_35 [ 7 ] = V_152 & 255 ;
V_152 = ( V_148 -> V_157 . V_186 . V_188 * F_47 ( ( V_148 -> V_160 * 360 ) >> 16 ) ) >> 15 ;
V_35 [ 8 ] = V_152 >> 8 ;
V_35 [ 9 ] = V_152 & 255 ;
V_35 [ 10 ] = V_148 -> V_157 . V_186 . V_162 . V_163 >> 7 ;
V_35 [ 11 ] = V_148 -> V_157 . V_186 . V_162 . V_164 >> 8 ;
V_35 [ 12 ] = V_148 -> V_157 . V_186 . V_162 . V_164 & 255 ;
V_35 [ 13 ] = V_148 -> V_157 . V_186 . V_162 . V_165 >> 7 ;
V_35 [ 14 ] = V_148 -> V_157 . V_186 . V_162 . V_166 >> 8 ;
V_35 [ 15 ] = V_148 -> V_157 . V_186 . V_162 . V_166 & 255 ;
V_134 = 16 ;
F_7 ( L_15 ,
V_148 -> V_157 . V_186 . V_187 ,
V_148 -> V_157 . V_186 . V_188 ,
V_148 -> V_160 , V_152 ) ;
F_7 ( L_12 ,
V_148 -> V_157 . V_186 . V_162 . V_163 ,
V_148 -> V_157 . V_186 . V_162 . V_164 ,
V_148 -> V_157 . V_186 . V_162 . V_165 ,
V_148 -> V_157 . V_186 . V_162 . V_166 ) ;
break;
case V_189 :
case V_190 :
case V_191 :
case V_192 :
V_35 [ 1 ] = V_193 [ V_148 -> type - V_191 ] ;
V_35 [ 6 ] = V_148 -> V_157 . V_194 [ 0 ] . V_195 >> 9 ;
V_35 [ 7 ] = ( V_148 -> V_157 . V_194 [ 0 ] . V_195 >> 1 ) & 255 ;
V_35 [ 8 ] = V_148 -> V_157 . V_194 [ 0 ] . V_196 >> 8 ;
V_35 [ 9 ] = V_148 -> V_157 . V_194 [ 0 ] . V_196 & 255 ;
V_35 [ 10 ] = V_148 -> V_157 . V_194 [ 0 ] . V_197 >> 9 ;
V_35 [ 11 ] = ( V_148 -> V_157 . V_194 [ 0 ] . V_197 >> 1 ) & 255 ;
V_35 [ 12 ] = V_148 -> V_157 . V_194 [ 0 ] . V_198 >> 8 ;
V_35 [ 13 ] = V_148 -> V_157 . V_194 [ 0 ] . V_198 & 255 ;
V_35 [ 14 ] = V_148 -> V_157 . V_194 [ 0 ] . V_199 >> 8 ;
V_35 [ 15 ] = V_148 -> V_157 . V_194 [ 0 ] . V_199 & 255 ;
V_35 [ 16 ] = V_148 -> V_157 . V_194 [ 0 ] . V_200 >> 9 ;
V_35 [ 17 ] = ( V_148 -> V_157 . V_194 [ 0 ] . V_200 >> 1 ) & 255 ;
V_134 = 18 ;
F_7 ( L_16 ,
V_201 [ V_148 -> type - V_191 ] ,
V_148 -> V_157 . V_194 [ 0 ] . V_196 ,
V_148 -> V_157 . V_194 [ 0 ] . V_195 ,
V_148 -> V_157 . V_194 [ 0 ] . V_199 ,
V_148 -> V_157 . V_194 [ 0 ] . V_200 ) ;
F_7 ( L_17 ,
V_148 -> V_157 . V_194 [ 0 ] . V_197 ,
V_148 -> V_157 . V_194 [ 0 ] . V_198 ) ;
break;
default:
F_25 ( V_103 -> V_5 -> V_27 , L_18 , V_148 -> type ) ;
return - V_42 ;
}
return F_40 ( V_103 , V_148 -> V_202 , V_136 , V_35 , V_134 ) ;
}
static int F_48 ( struct V_145 * V_146 , int V_123 , int V_203 )
{
struct V_122 * V_103 = V_146 -> V_150 -> V_151 ;
V_19 V_35 [ 2 ] ;
V_35 [ 1 ] = V_203 ? V_204 : V_205 ;
F_7 ( L_19 , V_203 ? L_20 : L_21 , V_123 ) ;
return F_40 ( V_103 , V_123 , V_206 , V_35 , F_49 ( V_35 ) ) ;
}
static int F_50 ( struct V_145 * V_146 , int V_123 )
{
struct V_122 * V_103 = V_146 -> V_150 -> V_151 ;
V_19 V_129 = 0 ;
F_7 ( L_22 , V_123 ) ;
return F_40 ( V_103 , V_123 , V_137 , & V_129 , 1 ) ;
}
static void F_51 ( struct V_145 * V_146 , T_1 V_180 )
{
struct V_122 * V_103 = V_146 -> V_150 -> V_151 ;
V_19 V_35 [ 18 ] ;
F_7 ( L_23 , V_180 ) ;
V_35 [ 1 ] = V_207 | V_208 ;
V_35 [ 2 ] = V_35 [ 3 ] = V_35 [ 4 ] = V_35 [ 5 ] = 0 ;
V_35 [ 8 ] = V_35 [ 14 ] = V_180 >> 11 ;
V_35 [ 9 ] = V_35 [ 15 ] = ( V_180 >> 3 ) & 255 ;
V_35 [ 6 ] = V_35 [ 16 ] = V_180 >> 9 ;
V_35 [ 7 ] = V_35 [ 17 ] = ( V_180 >> 1 ) & 255 ;
V_35 [ 10 ] = V_35 [ 11 ] = V_35 [ 12 ] = V_35 [ 13 ] = 0 ;
F_40 ( V_103 , V_130 , V_136 , V_35 , F_49 ( V_35 ) ) ;
}
static void F_52 ( struct V_145 * V_146 , T_1 V_139 )
{
struct V_122 * V_103 = V_146 -> V_150 -> V_151 ;
V_19 V_35 [ 4 ] ;
F_7 ( L_24 , V_139 ) ;
V_35 [ 0 ] = V_139 >> 8 ;
V_35 [ 1 ] = V_139 & 255 ;
V_35 [ 2 ] = 0 ;
V_35 [ 3 ] = 0 ;
F_40 ( V_103 , V_132 , V_138 , V_35 , F_49 ( V_35 ) ) ;
}
static T_2 F_53 ( struct V_209 * V_146 , struct V_210 * V_211 , char * V_212 )
{
struct V_1 * V_213 = F_54 ( V_146 ) ;
struct V_214 * V_215 = F_55 ( V_213 -> V_216 . V_217 , struct V_214 , V_218 ) ;
struct V_145 * V_219 = V_215 -> V_220 ;
struct V_122 * V_103 = V_219 -> V_150 -> V_151 ;
return F_56 ( V_212 , V_221 , L_25 , V_103 -> V_141 ) ;
}
static T_2 F_57 ( struct V_209 * V_146 , struct V_210 * V_211 , const char * V_212 , T_3 V_78 )
{
struct V_1 * V_213 = F_54 ( V_146 ) ;
struct V_214 * V_215 = F_55 ( V_213 -> V_216 . V_217 , struct V_214 , V_218 ) ;
struct V_145 * V_219 = V_215 -> V_220 ;
struct V_122 * V_103 = V_219 -> V_150 -> V_151 ;
V_19 V_35 [ 2 ] ;
int V_141 = F_58 ( V_212 , NULL , 10 ) ;
V_141 = F_59 ( V_141 , 180 , 900 ) ;
V_35 [ 0 ] = V_141 >> 8 ;
V_35 [ 1 ] = V_141 & 0x00FF ;
F_40 ( V_103 , - 1 , V_140 , V_35 , F_49 ( V_35 ) ) ;
return V_78 ;
}
static void F_60 ( struct V_222 * V_150 )
{
struct V_122 * V_103 = V_150 -> V_151 ;
F_12 ( V_103 -> V_125 ) ;
}
static int F_61 ( struct V_4 * V_5 , V_19 V_37 )
{
struct V_1 * V_213 = V_5 -> V_27 ;
struct V_214 * V_215 = F_55 ( V_213 -> V_216 . V_217 , struct V_214 , V_218 ) ;
struct V_145 * V_146 = V_215 -> V_220 ;
const struct V_223 * V_224 = & ( F_62 ( V_213 ) -> V_225 ) ;
const T_1 V_226 = F_63 ( V_224 -> V_226 ) ;
struct V_222 * V_150 ;
struct V_3 V_23 ;
struct V_122 * V_103 ;
int error , V_227 , V_228 ;
V_19 V_229 ;
if ( ! V_146 ) {
F_25 ( V_213 , L_26 ) ;
return - V_42 ;
}
V_229 = V_226 & 255 ;
for ( V_227 = 0 ; V_230 [ V_227 ] >= 0 ; V_227 ++ )
F_64 ( V_230 [ V_227 ] , V_146 -> V_231 ) ;
if ( V_229 > 1 )
for ( V_227 = 0 ; V_232 [ V_227 ] >= 0 ; V_227 ++ )
F_64 ( V_232 [ V_227 ] , V_146 -> V_231 ) ;
error = F_10 ( V_5 , V_37 ,
V_233 , NULL , 0 , & V_23 ) ;
if ( error ) {
if ( error < 0 )
return error ;
F_25 ( V_5 -> V_27 , L_7 ,
V_30 , error ) ;
return - V_71 ;
}
V_228 = V_23 . V_36 . V_35 [ 0 ] - V_234 ;
error = F_65 ( V_146 , V_228 ) ;
if ( error ) {
F_25 ( V_146 , L_27 ) ;
return error ;
}
V_103 = F_11 ( sizeof( * V_103 ) , V_43 ) ;
if ( ! V_103 )
return - V_44 ;
V_103 -> V_125 = F_66 ( V_228 , sizeof( int ) , V_43 ) ;
if ( ! V_103 -> V_125 ) {
F_12 ( V_103 ) ;
return - V_44 ;
}
V_103 -> V_5 = V_5 ;
V_103 -> V_37 = V_37 ;
V_103 -> V_229 = V_229 ;
V_103 -> V_131 = 0 ;
V_103 -> V_124 = V_228 ;
for ( V_227 = 0 ; V_227 < V_228 ; V_227 ++ )
V_103 -> V_125 [ V_227 ] = - 1 ;
V_150 = V_146 -> V_150 ;
V_150 -> V_151 = V_103 ;
V_150 -> V_235 = F_46 ;
V_150 -> V_236 = F_50 ;
V_150 -> V_237 = F_48 ;
V_150 -> V_238 = F_52 ;
V_150 -> V_239 = F_51 ;
V_150 -> V_240 = F_60 ;
error = F_10 ( V_5 , V_37 ,
V_241 , NULL , 0 , & V_23 ) ;
error = F_10 ( V_5 , V_37 ,
V_242 , NULL , 0 , & V_23 ) ;
if ( error )
F_45 ( V_5 -> V_27 , L_28 ) ;
V_103 -> V_141 = error ? 900 : F_33 ( & V_23 . V_36 . V_35 [ 0 ] ) ;
error = F_67 ( & ( V_5 -> V_27 -> V_146 ) , & V_243 ) ;
if ( error )
F_45 ( V_5 -> V_27 , L_29 , error ) ;
error = F_10 ( V_5 , V_37 ,
V_244 , NULL , 0 , & V_23 ) ;
if ( error )
F_45 ( V_5 -> V_27 , L_30 ) ;
V_103 -> V_139 = error ? 0xffff : F_33 ( & V_23 . V_36 . V_35 [ 0 ] ) ;
V_103 -> V_144 = F_68 ( L_31 ) ;
F_69 ( & V_103 -> V_142 , 0 ) ;
F_51 ( V_146 , 0 ) ;
F_70 ( V_213 , L_32 , V_229 ) ;
return 0 ;
}
static int F_71 ( struct V_1 * V_213 )
{
struct V_214 * V_215 = F_55 ( V_213 -> V_216 . V_217 , struct V_214 , V_218 ) ;
struct V_145 * V_146 = V_215 -> V_220 ;
struct V_122 * V_103 ;
if ( ! V_146 ) {
F_25 ( V_213 , L_33 ) ;
return - V_42 ;
}
F_70 ( V_213 , L_34 ) ;
V_103 = V_146 -> V_150 -> V_151 ;
if ( ! V_103 ) {
F_25 ( V_213 , L_35 ) ;
return - V_42 ;
}
F_72 ( V_103 -> V_144 ) ;
F_73 ( & V_213 -> V_146 , & V_243 ) ;
return 0 ;
}
static int F_74 ( struct V_1 * V_2 , struct V_214 * V_245 ,
struct V_246 * V_247 , struct V_248 * V_249 ,
unsigned long * * V_250 , int * V_251 )
{
return - 1 ;
}
static void F_75 ( struct V_4 * V_5 ,
struct V_145 * V_145 , bool V_252 )
{
struct V_253 * V_128 = V_5 -> V_254 ;
F_76 ( V_255 , V_145 -> V_256 ) ;
F_76 ( V_257 , V_145 -> V_256 ) ;
F_77 ( V_258 , V_145 -> V_256 ) ;
F_77 ( V_259 , V_145 -> V_256 ) ;
F_78 ( V_145 , V_260 , 0 , V_128 -> V_93 , 0 , 0 ) ;
F_79 ( V_145 , V_260 , V_128 -> V_261 ) ;
F_78 ( V_145 , V_262 , 0 , V_128 -> V_94 , 0 , 0 ) ;
F_79 ( V_145 , V_262 , V_128 -> V_261 ) ;
F_78 ( V_145 , V_263 , 0 , 50 , 0 , 0 ) ;
F_80 ( V_145 , V_257 , V_264 ) ;
if ( V_5 -> V_17 & V_265 )
F_80 ( V_145 , V_257 , V_266 ) ;
else
F_76 ( V_267 , V_145 -> V_268 ) ;
F_81 ( V_145 , V_128 -> V_97 , V_269 |
V_270 ) ;
V_128 -> V_220 = V_145 ;
}
static void F_82 ( struct V_253 * V_128 ,
struct V_104 * V_271 )
{
int V_129 ;
if ( ! V_271 -> V_114 || V_271 -> V_110 )
return;
V_129 = F_83 ( V_128 -> V_220 , V_271 -> V_114 ) ;
F_84 ( V_128 -> V_220 , V_129 ) ;
F_85 ( V_128 -> V_220 , V_272 ,
V_271 -> V_111 ) ;
if ( V_271 -> V_111 ) {
F_86 ( V_128 -> V_220 , V_255 , V_260 ,
V_271 -> V_108 ) ;
F_86 ( V_128 -> V_220 , V_255 , V_262 ,
V_128 -> V_273 ? V_128 -> V_94 - V_271 -> V_109 :
V_271 -> V_109 ) ;
F_86 ( V_128 -> V_220 , V_255 , V_263 ,
V_271 -> V_113 ) ;
}
}
static void F_87 ( struct V_4 * V_5 ,
struct V_115 * V_274 )
{
struct V_253 * V_128 = V_5 -> V_254 ;
int V_77 ;
for ( V_77 = 0 ; V_77 < 2 ; V_77 ++ )
F_82 ( V_128 , & ( V_274 -> V_121 [ V_77 ] ) ) ;
if ( V_274 -> V_117 &&
! ( V_5 -> V_17 & V_265 ) )
F_86 ( V_128 -> V_220 , V_257 , V_264 , V_274 -> V_120 ) ;
if ( V_274 -> V_117 || V_274 -> V_119 <= 2 ) {
F_88 ( V_128 -> V_220 ) ;
F_89 ( V_128 -> V_220 ) ;
}
}
static int F_90 ( struct V_4 * V_5 , V_19 * V_103 )
{
struct V_253 * V_128 = V_5 -> V_254 ;
V_19 V_275 = ( ( V_103 [ 7 ] & 0xf ) * ( V_103 [ 7 ] & 0xf ) +
( V_103 [ 7 ] >> 4 ) * ( V_103 [ 7 ] >> 4 ) ) / 2 ;
V_19 V_276 = ( ( V_103 [ 13 ] & 0xf ) * ( V_103 [ 13 ] & 0xf ) +
( V_103 [ 13 ] >> 4 ) * ( V_103 [ 13 ] >> 4 ) ) / 2 ;
struct V_115 V_274 = {
. V_277 = V_103 [ 1 ] ,
. V_121 = {
{
. V_110 = 0 ,
. V_111 = ! ! V_103 [ 7 ] ,
. V_108 = F_91 ( & V_103 [ 3 ] ) ,
. V_109 = F_91 ( & V_103 [ 5 ] ) ,
. V_112 = V_275 ,
. V_113 = V_275 ,
. V_114 = V_103 [ 2 ] ,
} , {
. V_110 = 0 ,
. V_111 = ! ! V_103 [ 13 ] ,
. V_108 = F_91 ( & V_103 [ 9 ] ) ,
. V_109 = F_91 ( & V_103 [ 11 ] ) ,
. V_112 = V_276 ,
. V_113 = V_276 ,
. V_114 = V_103 [ 8 ] ,
}
} ,
. V_119 = V_128 -> V_97 ,
. V_118 = 0 ,
. V_117 = ( V_103 [ 0 ] >> 7 ) == 0 ,
. V_120 = V_103 [ 0 ] & 0x01 ,
} ;
F_87 ( V_5 , & V_274 ) ;
return 1 ;
}
static int F_92 ( struct V_1 * V_2 , V_19 * V_103 , int V_134 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
struct V_253 * V_128 = V_5 -> V_254 ;
struct V_3 * V_52 = (struct V_3 * ) V_103 ;
struct V_115 V_274 ;
if ( ! V_128 || ! V_128 -> V_220 )
return 1 ;
switch ( V_103 [ 0 ] ) {
case 0x02 :
if ( V_134 < 2 ) {
F_25 ( V_2 , L_36 ,
V_134 ) ;
return 1 ;
}
if ( V_5 -> V_17 & V_265 ) {
F_86 ( V_128 -> V_220 , V_257 , V_264 ,
! ! ( V_103 [ 1 ] & 0x01 ) ) ;
F_86 ( V_128 -> V_220 , V_257 , V_266 ,
! ! ( V_103 [ 1 ] & 0x02 ) ) ;
F_89 ( V_128 -> V_220 ) ;
return 0 ;
} else {
if ( V_134 < 21 )
return 1 ;
return F_90 ( V_5 , & V_103 [ 7 ] ) ;
}
case V_11 :
if ( ( V_52 -> V_36 . V_37 != V_128 -> V_278 ) ||
( V_52 -> V_36 . V_40 != V_279 ) )
return 1 ;
F_36 ( V_5 , V_103 + 4 , & V_274 ) ;
F_87 ( V_5 , & V_274 ) ;
return 0 ;
}
return 0 ;
}
static int F_93 ( struct V_4 * V_5 )
{
struct V_253 * V_128 = V_5 -> V_254 ;
struct V_90 V_91 = { 0 } ;
V_19 V_62 ;
int V_7 ;
V_7 = F_23 ( V_5 , V_280 ,
& V_128 -> V_278 , & V_62 ) ;
if ( V_7 )
return V_7 ;
V_7 = F_32 ( V_5 , V_128 -> V_278 ,
& V_91 ) ;
if ( V_7 )
return V_7 ;
V_128 -> V_93 = V_91 . V_93 ;
V_128 -> V_94 = V_91 . V_94 ;
V_128 -> V_97 = V_91 . V_97 ;
V_128 -> V_273 = V_91 . V_98 == V_281 ;
V_128 -> V_261 = V_91 . V_99 ;
if ( ! V_128 -> V_261 )
V_128 -> V_261 = V_282 ;
return 0 ;
}
static int F_94 ( struct V_1 * V_2 , const struct V_283 * V_202 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
struct V_253 * V_128 ;
V_128 = F_95 ( & V_2 -> V_146 , sizeof( struct V_253 ) ,
V_43 ) ;
if ( ! V_128 )
return - V_44 ;
V_5 -> V_254 = V_128 ;
return 0 ;
}
static int F_96 ( struct V_1 * V_2 , bool V_284 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
struct V_253 * V_128 = V_5 -> V_254 ;
int V_7 ;
if ( ! V_284 )
return 0 ;
if ( ! V_128 -> V_93 ) {
V_7 = F_93 ( V_5 ) ;
if ( V_7 ) {
F_25 ( V_2 , L_37 , V_7 ) ;
return V_7 ;
}
}
return F_34 ( V_5 , V_128 -> V_278 ,
true , true ) ;
}
static int F_97 ( struct V_1 * V_2 , bool V_284 )
{
struct V_3 V_23 ;
struct V_4 * V_45 ;
V_45 = F_2 ( V_2 ) ;
if ( ! V_284 )
return - V_15 ;
return F_13 (
V_45 ,
V_9 ,
V_285 ,
V_286 ,
( V_19 * ) V_287 ,
sizeof( V_287 ) ,
& V_23
) ;
}
static int F_98 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
struct V_288 * V_289 ;
V_289 = F_95 ( & V_2 -> V_146 , sizeof( struct V_288 ) ,
V_43 ) ;
if ( ! V_289 )
return - V_44 ;
V_5 -> V_254 = V_289 ;
return 0 ;
}
static int F_99 ( struct V_1 * V_2 , V_19 * V_103 , int V_134 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
struct V_288 * V_290 = V_5 -> V_254 ;
if ( ! V_290 || ! V_290 -> V_220 ) {
F_25 ( V_2 , L_38 ) ;
return - V_42 ;
}
if ( V_134 < 7 ) {
F_25 ( V_2 , L_39 ) ;
return 0 ;
}
if ( V_103 [ 0 ] == V_11 &&
V_103 [ 2 ] == V_285 && V_103 [ 6 ] == 0x00 ) {
switch ( V_103 [ 5 ] ) {
case 0xaf :
F_100 ( V_290 -> V_220 , V_291 , 1 ) ;
break;
case 0xb0 :
F_100 ( V_290 -> V_220 , V_292 , 1 ) ;
break;
case 0xae :
F_100 ( V_290 -> V_220 , V_293 , 1 ) ;
break;
case 0x00 :
F_100 ( V_290 -> V_220 , V_293 , 0 ) ;
F_100 ( V_290 -> V_220 , V_292 , 0 ) ;
F_100 ( V_290 -> V_220 , V_291 , 0 ) ;
break;
default:
F_25 ( V_2 , L_39 ) ;
return 0 ;
}
F_89 ( V_290 -> V_220 ) ;
} else if ( V_103 [ 0 ] == 0x02 ) {
int V_294 ;
F_100 ( V_290 -> V_220 , V_264 ,
! ! ( V_103 [ 1 ] & V_295 ) ) ;
F_100 ( V_290 -> V_220 , V_266 ,
! ! ( V_103 [ 1 ] & V_296 ) ) ;
if ( V_103 [ 1 ] & V_297 )
F_101 ( V_290 -> V_220 , V_298 , - 1 ) ;
else if ( V_103 [ 1 ] & V_299 )
F_101 ( V_290 -> V_220 , V_298 , 1 ) ;
V_294 = F_102 ( F_103 ( V_2 , V_103 + 3 , 0 , 12 ) , 12 ) ;
F_101 ( V_290 -> V_220 , V_300 , V_294 ) ;
V_294 = F_102 ( F_103 ( V_2 , V_103 + 3 , 12 , 12 ) , 12 ) ;
F_101 ( V_290 -> V_220 , V_301 , V_294 ) ;
V_294 = F_102 ( V_103 [ 6 ] , 8 ) ;
F_101 ( V_290 -> V_220 , V_302 , V_294 ) ;
F_89 ( V_290 -> V_220 ) ;
}
return 1 ;
}
static void F_104 ( struct V_4 * V_5 ,
struct V_145 * V_145 , bool V_252 )
{
struct V_288 * V_290 = V_5 -> V_254 ;
V_290 -> V_220 = V_145 ;
F_76 ( V_257 , V_290 -> V_220 -> V_256 ) ;
F_76 ( V_291 , V_290 -> V_220 -> V_303 ) ;
F_76 ( V_266 , V_290 -> V_220 -> V_303 ) ;
F_76 ( V_264 , V_290 -> V_220 -> V_303 ) ;
F_76 ( V_293 , V_290 -> V_220 -> V_303 ) ;
F_76 ( V_292 , V_290 -> V_220 -> V_303 ) ;
F_76 ( V_258 , V_290 -> V_220 -> V_256 ) ;
F_76 ( V_300 , V_290 -> V_220 -> V_304 ) ;
F_76 ( V_301 , V_290 -> V_220 -> V_304 ) ;
F_76 ( V_302 , V_290 -> V_220 -> V_304 ) ;
F_76 ( V_298 , V_290 -> V_220 -> V_304 ) ;
}
static int F_105 ( struct V_1 * V_2 , struct V_214 * V_245 ,
struct V_246 * V_247 , struct V_248 * V_249 ,
unsigned long * * V_250 , int * V_251 )
{
return - 1 ;
}
static int F_106 ( struct V_4 * V_5 )
{
struct V_305 * V_306 = V_5 -> V_254 ;
struct V_83 V_84 = {} ;
int V_7 ;
V_19 V_62 ;
if ( ! V_306 -> V_37 ) {
V_7 = F_23 ( V_5 ,
V_307 ,
& V_306 -> V_37 , & V_62 ) ;
if ( V_7 )
return V_7 ;
}
V_7 = F_31 ( V_5 , V_306 -> V_37 , & V_84 ) ;
if ( V_7 )
return V_7 ;
return 0 ;
}
static int F_107 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
struct V_305 * V_306 ;
V_306 = F_95 ( & V_2 -> V_146 , sizeof( struct V_305 ) ,
V_43 ) ;
if ( ! V_306 )
return - V_44 ;
V_5 -> V_254 = V_306 ;
return 0 ;
}
static int F_108 ( struct V_1 * V_2 , bool V_284 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
if ( ! V_284 )
return 0 ;
if ( ! V_308 )
return 0 ;
return F_106 ( V_5 ) ;
}
static int F_109 ( struct V_4 * V_5 )
{
V_19 V_62 ;
V_19 V_37 ;
int V_7 ;
V_7 = F_23 ( V_5 , V_309 ,
& V_37 , & V_62 ) ;
if ( V_7 )
return V_7 ;
V_7 = F_61 ( V_5 , V_37 ) ;
if ( V_7 )
F_45 ( V_5 -> V_27 , L_40 ,
V_7 ) ;
return 0 ;
}
static int F_110 ( struct V_1 * V_2 , struct V_214 * V_245 ,
struct V_246 * V_247 , struct V_248 * V_249 ,
unsigned long * * V_250 , int * V_251 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
if ( V_5 -> V_17 & V_310 )
return F_74 ( V_2 , V_245 , V_247 , V_249 , V_250 , V_251 ) ;
else if ( V_5 -> V_17 & V_311 &&
V_247 -> V_312 != V_313 )
return F_105 ( V_2 , V_245 , V_247 , V_249 , V_250 , V_251 ) ;
return 0 ;
}
static int F_111 ( struct V_1 * V_2 , struct V_214 * V_245 ,
struct V_246 * V_247 , struct V_248 * V_249 ,
unsigned long * * V_250 , int * V_251 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
if ( V_5 -> V_17 & V_314 ) {
if ( V_249 -> type == V_255 && ( V_249 -> V_315 == V_316 ||
V_249 -> V_315 == V_317 || V_249 -> V_315 == V_318 ||
V_249 -> V_315 == V_319 ) ) {
V_247 -> V_312 = V_320 ;
}
}
return 0 ;
}
static void F_112 ( struct V_4 * V_5 ,
struct V_145 * V_220 , bool V_252 )
{
if ( V_5 -> V_17 & V_310 )
F_75 ( V_5 , V_220 , V_252 ) ;
else if ( V_5 -> V_17 & V_311 )
F_104 ( V_5 , V_220 , V_252 ) ;
}
static int F_113 ( struct V_1 * V_2 ,
struct V_214 * V_215 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
struct V_145 * V_220 = V_215 -> V_220 ;
F_112 ( V_5 , V_220 , true ) ;
return 0 ;
}
static int F_114 ( struct V_4 * V_5 , V_19 * V_103 ,
int V_134 )
{
struct V_3 * V_50 = V_5 -> V_25 ;
struct V_3 * V_51 = V_5 -> V_25 ;
struct V_3 * V_52 = (struct V_3 * ) V_103 ;
if ( F_115 ( F_116 ( & V_5 -> V_24 ) ) ) {
if ( F_17 ( V_50 , V_52 ) ||
F_18 ( V_50 , V_52 ) ) {
* V_51 = * V_52 ;
V_5 -> V_26 = true ;
F_117 ( & V_5 -> V_28 ) ;
return 1 ;
}
}
if ( F_115 ( F_19 ( V_52 ) ) ) {
F_69 ( & V_5 -> V_284 ,
! ( V_52 -> V_32 . V_35 [ 0 ] & ( 1 << 6 ) ) ) ;
if ( ( V_5 -> V_17 & V_321 ) &&
( F_118 ( & V_5 -> V_49 ) == 0 ) )
F_7 ( L_41 , V_30 ) ;
return 1 ;
}
return 0 ;
}
static int F_119 ( struct V_1 * V_2 , struct V_322 * V_52 ,
V_19 * V_103 , int V_134 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
int V_7 = 0 ;
switch ( V_103 [ 0 ] ) {
case V_13 :
if ( V_134 != V_14 ) {
F_25 ( V_2 , L_42 ,
V_134 ) ;
return 1 ;
}
V_7 = F_114 ( V_5 , V_103 , V_134 ) ;
break;
case V_11 :
if ( V_134 != V_12 ) {
F_25 ( V_2 , L_42 ,
V_134 ) ;
return 1 ;
}
V_7 = F_114 ( V_5 , V_103 , V_134 ) ;
break;
case V_9 :
if ( V_134 != V_10 ) {
F_25 ( V_2 , L_42 ,
V_134 ) ;
return 1 ;
}
V_7 = F_114 ( V_5 , V_103 , V_134 ) ;
break;
}
if ( V_7 != 0 )
return V_7 ;
if ( V_5 -> V_17 & V_310 )
return F_92 ( V_2 , V_103 , V_134 ) ;
else if ( V_5 -> V_17 & V_311 )
return F_99 ( V_2 , V_103 , V_134 ) ;
return 0 ;
}
static void F_120 ( struct V_1 * V_2 , bool V_323 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
char * V_53 ;
if ( V_323 )
V_53 = F_22 ( V_5 ) ;
else
V_53 = F_30 ( V_5 ) ;
if ( ! V_53 ) {
F_25 ( V_2 , L_43 ) ;
} else {
F_7 ( L_44 , V_53 ) ;
snprintf ( V_2 -> V_53 , sizeof( V_2 -> V_53 ) , L_45 , V_53 ) ;
}
F_12 ( V_53 ) ;
}
static int F_121 ( struct V_145 * V_146 )
{
struct V_1 * V_213 = F_122 ( V_146 ) ;
return F_123 ( V_213 ) ;
}
static void F_124 ( struct V_145 * V_146 )
{
struct V_1 * V_213 = F_122 ( V_146 ) ;
F_125 ( V_213 ) ;
}
static struct V_145 * F_126 ( struct V_1 * V_2 )
{
struct V_145 * V_145 = F_127 ( & V_2 -> V_146 ) ;
struct V_4 * V_5 = F_2 ( V_2 ) ;
if ( ! V_145 )
return NULL ;
F_128 ( V_145 , V_2 ) ;
V_145 -> V_324 = F_121 ;
V_145 -> V_325 = F_124 ;
V_145 -> V_53 = V_5 -> V_53 ;
V_145 -> V_326 = V_2 -> V_326 ;
V_145 -> V_327 = V_2 -> V_327 ;
V_145 -> V_202 . V_328 = V_2 -> V_329 ;
V_145 -> V_202 . V_330 = V_2 -> V_330 ;
V_145 -> V_202 . V_331 = V_2 -> V_331 ;
V_145 -> V_202 . V_229 = V_2 -> V_229 ;
V_145 -> V_146 . V_332 = & V_2 -> V_146 ;
return V_145 ;
}
static void F_16 ( struct V_4 * V_5 )
{
struct V_1 * V_2 = V_5 -> V_27 ;
int V_7 = 0 ;
bool V_284 = F_44 ( & V_5 -> V_284 ) ;
struct V_145 * V_220 ;
char * V_53 , * V_333 ;
if ( V_5 -> V_17 & V_310 ) {
V_7 = F_96 ( V_2 , V_284 ) ;
if ( V_7 )
return;
} else if ( V_5 -> V_17 & V_311 ) {
V_7 = F_97 ( V_2 , V_284 ) ;
if ( V_7 )
return;
} else if ( V_5 -> V_17 & V_334 ) {
V_7 = F_108 ( V_2 , V_284 ) ;
if ( V_7 )
return;
}
if ( ! V_284 || V_5 -> V_335 )
return;
if ( ! V_5 -> V_67 ) {
V_7 = ! F_26 ( V_5 ) ;
if ( V_7 ) {
F_25 ( V_2 , L_46 ) ;
return;
}
F_70 ( V_2 , L_8 ,
V_5 -> V_67 , V_5 -> V_68 ) ;
}
if ( ! ( V_5 -> V_17 & V_336 ) )
return;
if ( ! V_5 -> V_53 || V_5 -> V_53 == V_2 -> V_53 ) {
V_53 = F_30 ( V_5 ) ;
if ( ! V_53 ) {
F_25 ( V_2 ,
L_43 ) ;
return;
}
V_333 = F_129 ( & V_2 -> V_146 , V_43 , L_45 , V_53 ) ;
F_12 ( V_53 ) ;
if ( ! V_333 )
return;
V_5 -> V_53 = V_333 ;
}
V_220 = F_126 ( V_2 ) ;
if ( ! V_220 ) {
F_25 ( V_2 , L_47 , V_7 ) ;
return;
}
F_112 ( V_5 , V_220 , false ) ;
V_7 = F_130 ( V_220 ) ;
if ( V_7 )
F_131 ( V_220 ) ;
V_5 -> V_335 = V_220 ;
}
static int F_132 ( struct V_1 * V_2 , const struct V_283 * V_202 )
{
struct V_4 * V_5 ;
int V_7 ;
bool V_284 ;
unsigned int V_337 = V_338 ;
V_5 = F_95 ( & V_2 -> V_146 , sizeof( struct V_4 ) ,
V_43 ) ;
if ( ! V_5 )
return - V_44 ;
V_5 -> V_27 = V_2 ;
V_5 -> V_53 = V_2 -> V_53 ;
F_133 ( V_2 , V_5 ) ;
V_5 -> V_17 = V_202 -> V_339 ;
if ( V_340 ) {
V_5 -> V_17 &= ~ V_310 ;
V_5 -> V_17 &= ~ V_321 ;
V_5 -> V_17 &= ~ V_336 ;
}
if ( V_5 -> V_17 & V_310 ) {
V_7 = F_94 ( V_2 , V_202 ) ;
if ( V_7 )
goto V_341;
} else if ( V_5 -> V_17 & V_311 ) {
V_7 = F_98 ( V_2 ) ;
if ( V_7 )
goto V_341;
} else if ( V_5 -> V_17 & V_334 ) {
V_7 = F_107 ( V_2 ) ;
if ( V_7 )
goto V_341;
}
F_41 ( & V_5 -> V_49 , F_14 ) ;
F_134 ( & V_5 -> V_24 ) ;
F_135 ( & V_5 -> V_28 ) ;
V_7 = F_136 ( V_2 ) ;
if ( V_7 ) {
F_25 ( V_2 , L_48 , V_30 ) ;
goto V_342;
}
if ( V_5 -> V_17 & V_336 )
V_337 &= ~ V_343 ;
if ( V_5 -> V_17 & V_314 ) {
V_7 = F_137 ( V_2 , V_337 ) ;
if ( V_7 ) {
F_25 ( V_2 , L_49 ) ;
goto V_344;
}
V_7 = F_123 ( V_2 ) ;
if ( V_7 < 0 ) {
F_138 ( & V_2 -> V_146 , L_50 ,
V_30 , V_7 ) ;
F_139 ( V_2 ) ;
goto V_344;
}
}
F_140 ( V_2 ) ;
V_284 = F_26 ( V_5 ) ;
if ( V_202 -> V_345 != V_346 ) {
if ( ! V_284 ) {
V_7 = - V_15 ;
F_25 ( V_2 , L_51 ) ;
goto V_347;
}
F_70 ( V_2 , L_8 ,
V_5 -> V_67 , V_5 -> V_68 ) ;
}
F_120 ( V_2 , V_202 -> V_345 == V_346 ) ;
F_69 ( & V_5 -> V_284 , V_284 ) ;
if ( V_284 && ( V_5 -> V_17 & V_310 ) ) {
V_7 = F_93 ( V_5 ) ;
if ( V_7 )
goto V_347;
} else if ( V_284 && ( V_5 -> V_17 & V_314 ) ) {
V_7 = F_109 ( V_5 ) ;
if ( V_7 )
goto V_347;
}
F_141 ( V_2 ) ;
if ( ! ( V_5 -> V_17 & V_314 ) ) {
V_7 = F_137 ( V_2 , V_337 ) ;
if ( V_7 ) {
F_25 ( V_2 , L_52 , V_30 ) ;
goto V_344;
}
}
if ( V_5 -> V_17 & V_321 ) {
F_140 ( V_2 ) ;
F_16 ( V_5 ) ;
}
return V_7 ;
V_347:
F_141 ( V_2 ) ;
if ( V_5 -> V_17 & V_314 ) {
F_125 ( V_2 ) ;
F_139 ( V_2 ) ;
}
V_344:
V_342:
F_142 ( & V_5 -> V_49 ) ;
F_143 ( & V_5 -> V_24 ) ;
V_341:
F_133 ( V_2 , NULL ) ;
return V_7 ;
}
static void F_144 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
if ( V_5 -> V_17 & V_314 ) {
F_71 ( V_2 ) ;
F_125 ( V_2 ) ;
}
F_139 ( V_2 ) ;
F_142 ( & V_5 -> V_49 ) ;
F_143 ( & V_5 -> V_24 ) ;
}
