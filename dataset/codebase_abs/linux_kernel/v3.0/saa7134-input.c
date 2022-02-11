static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
T_1 V_6 , V_7 ;
switch ( V_2 -> V_8 ) {
case V_9 :
F_2 ( V_10 , 0x80 ) ;
F_3 ( V_10 , 0x80 ) ;
break;
}
F_3 ( V_11 , V_12 ) ;
F_2 ( V_11 , V_12 ) ;
V_6 = F_4 ( V_13 >> 2 ) ;
if ( V_4 -> V_14 ) {
if ( V_4 -> V_15 == V_6 )
return 0 ;
V_4 -> V_15 = V_6 ;
}
V_7 = F_5 ( V_6 , V_4 -> V_16 ) ;
F_6 ( L_1 ,
V_6 , V_4 -> V_16 , V_7 ) ;
switch ( V_2 -> V_8 ) {
case V_17 :
if ( V_7 == V_4 -> V_16 )
F_7 ( V_4 -> V_2 ) ;
else
F_8 ( V_4 -> V_2 , V_7 , 0 ) ;
return 0 ;
}
if ( V_4 -> V_14 ) {
if ( ( V_4 -> V_18 && ( 0 != ( V_6 & V_4 -> V_18 ) ) ) ||
( V_4 -> V_19 && ( 0 == ( V_6 & V_4 -> V_19 ) ) ) ) {
F_8 ( V_4 -> V_2 , V_7 , 0 ) ;
} else {
F_7 ( V_4 -> V_2 ) ;
}
}
else {
if ( ( V_4 -> V_18 && ( 0 != ( V_6 & V_4 -> V_18 ) ) ) ||
( V_4 -> V_19 && ( 0 == ( V_6 & V_4 -> V_19 ) ) ) ) {
F_8 ( V_4 -> V_2 , V_7 , 0 ) ;
F_7 ( V_4 -> V_2 ) ;
}
}
return 0 ;
}
static int F_9 ( struct V_20 * V_4 , T_1 * V_21 , T_1 * V_22 )
{
int V_6 ;
int V_23 = 0 ;
unsigned char V_24 ;
struct V_1 * V_2 = V_4 -> V_25 -> V_26 -> V_27 ;
if ( V_2 == NULL ) {
F_10 ( L_2
L_3 ) ;
return - V_28 ;
}
F_3 ( V_11 , V_12 ) ;
F_2 ( V_11 , V_12 ) ;
V_6 = F_4 ( V_13 >> 2 ) ;
if ( 0x40000 & ~ V_6 )
return 0 ;
if ( V_24 == 0xFF )
return 0 ;
V_24 = 0 ;
while ( 1 != F_11 ( V_4 -> V_25 , & V_24 , 1 ) ) {
if ( ( V_23 ++ ) < 10 ) {
F_12 ( 10 ) ;
continue;
}
F_10 ( L_4
L_5 , V_23 ) ;
return - V_28 ;
}
if ( 1 != F_13 ( V_4 -> V_25 , & V_24 , 1 ) ) {
F_10 ( L_6 ) ;
return - V_28 ;
}
* V_21 = V_24 ;
* V_22 = V_24 ;
return 1 ;
}
static int F_14 ( struct V_20 * V_4 , T_1 * V_21 ,
T_1 * V_22 )
{
unsigned char V_24 ;
int V_6 ;
struct V_1 * V_2 = V_4 -> V_25 -> V_26 -> V_27 ;
if ( V_2 == NULL ) {
F_10 ( L_7
L_3 ) ;
return - V_28 ;
}
F_3 ( V_11 , V_12 ) ;
F_2 ( V_11 , V_12 ) ;
V_6 = F_4 ( V_13 >> 2 ) ;
if ( V_6 & 0x40 )
return 0 ;
if ( 1 != F_13 ( V_4 -> V_25 , & V_24 , 1 ) ) {
F_10 ( L_6 ) ;
return - V_28 ;
}
if ( V_24 == 0xff )
return 0 ;
F_6 ( L_8 , V_24 ) ;
* V_21 = V_24 ;
* V_22 = V_24 ;
return 1 ;
}
static int F_15 ( struct V_20 * V_4 , T_1 * V_21 , T_1 * V_22 )
{
unsigned char V_24 ;
if ( 1 != F_13 ( V_4 -> V_25 , & V_24 , 1 ) ) {
F_10 ( L_6 ) ;
return - V_28 ;
}
if ( V_24 == 0 )
return 0 ;
if ( V_24 & 0x80 )
return 1 ;
* V_21 = V_24 ;
* V_22 = V_24 ;
return 1 ;
}
static int F_16 ( struct V_20 * V_4 , T_1 * V_21 , T_1 * V_22 )
{
unsigned char V_29 [ 5 ] , V_30 , V_31 , V_32 ;
if ( 5 != F_13 ( V_4 -> V_25 , V_29 , 5 ) )
return - V_28 ;
V_30 = V_29 [ 4 ] ;
V_32 = ( V_30 >> 2 ) ;
V_31 = V_29 [ 3 ] ;
if ( V_31 == 0 )
return 0 ;
* V_21 = V_32 ;
* V_22 = V_32 ;
return 1 ;
}
static int F_17 ( struct V_20 * V_4 , T_1 * V_21 , T_1 * V_22 )
{
unsigned char V_7 [ 12 ] ;
T_1 V_6 ;
struct V_1 * V_2 = V_4 -> V_25 -> V_26 -> V_27 ;
F_3 ( V_11 , V_12 ) ;
F_2 ( V_11 , V_12 ) ;
V_6 = F_4 ( V_13 >> 2 ) ;
if ( 0x400000 & ~ V_6 )
return 0 ;
V_4 -> V_25 -> V_33 = 0x5a >> 1 ;
if ( 12 != F_13 ( V_4 -> V_25 , V_7 , 12 ) ) {
F_10 ( L_6 ) ;
return - V_28 ;
}
if ( V_7 [ 9 ] != ( unsigned char ) ( ~ V_7 [ 8 ] ) )
return 0 ;
* V_22 = ( ( V_7 [ 10 ] << 16 ) | ( V_7 [ 11 ] << 8 ) | ( V_7 [ 9 ] << 0 ) ) ;
* V_21 = * V_22 ;
return 1 ;
}
static int F_18 ( struct V_20 * V_4 , T_1 * V_21 , T_1 * V_22 ,
int V_34 , int V_35 , int V_36 )
{
unsigned char V_24 [ 4 ] ;
unsigned int V_37 = 0 , V_38 = 0 , V_39 = 0 ;
if ( 4 != F_13 ( V_4 -> V_25 , V_24 , 4 ) ) {
F_10 ( L_6 ) ;
return - V_28 ;
}
for ( V_37 = 0 ; V_37 < F_19 ( V_24 ) ; V_37 ++ ) {
if ( V_24 [ V_37 ] == V_35 ) {
V_39 = V_24 [ ( V_37 + V_34 + 1 ) % 4 ] ;
V_38 = V_24 [ ( V_37 + V_34 ) % 4 ] ;
}
}
if ( V_38 == 0 )
return 0 ;
if ( V_4 -> V_40 == V_38 )
return 0 ;
V_4 -> V_40 = V_38 ;
if ( V_35 == 0xfe && ( V_39 & 0x40 ) )
return 0 ;
V_39 %= V_36 ;
* V_22 = V_39 ;
* V_21 = V_39 ;
F_10 ( L_9 , V_39 ) ;
return 1 ;
}
static int F_20 ( struct V_20 * V_4 , T_1 * V_21 , T_1 * V_22 )
{
return F_18 ( V_4 , V_21 , V_22 , 1 , 0xfe , 0xff ) ;
}
static int F_21 ( struct V_20 * V_4 , T_1 * V_21 , T_1 * V_22 )
{
return F_18 ( V_4 , V_21 , V_22 , 2 , 0x80 , 0x88 ) ;
}
void F_22 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
if ( ! V_2 || ! V_2 -> V_5 )
return;
V_4 = V_2 -> V_5 ;
if ( ! V_4 -> V_41 )
return;
if ( ! V_4 -> V_14 && ! V_4 -> V_42 ) {
F_1 ( V_2 ) ;
} else if ( V_4 -> V_42 ) {
F_23 ( V_2 ) ;
}
}
static void F_24 ( unsigned long V_7 )
{
struct V_1 * V_2 = (struct V_1 * ) V_7 ;
struct V_3 * V_4 = V_2 -> V_5 ;
F_1 ( V_2 ) ;
F_25 ( & V_4 -> V_43 , V_44 + F_26 ( V_4 -> V_14 ) ) ;
}
static void F_27 ( unsigned long V_7 )
{
struct V_1 * V_2 = (struct V_1 * ) V_7 ;
struct V_3 * V_4 = V_2 -> V_5 ;
F_28 ( V_2 -> V_5 -> V_2 ) ;
V_4 -> V_45 = false ;
}
static int F_29 ( void * V_46 )
{
struct V_1 * V_2 = V_46 ;
struct V_3 * V_4 ;
if ( ! V_2 || ! V_2 -> V_5 )
return - V_47 ;
V_4 = V_2 -> V_5 ;
if ( V_4 -> V_41 )
return 0 ;
switch ( V_2 -> V_8 ) {
case V_48 :
case V_49 :
case V_50 :
case V_51 :
case V_52 :
case V_53 :
case V_54 :
case V_55 :
case V_56 :
case V_57 :
case V_58 :
case V_59 :
F_2 ( V_60 , 0x4 ) ;
F_2 ( V_13 , 0x4 ) ;
break;
case V_61 :
case V_62 :
F_2 ( V_63 , 0x1 ) ;
F_2 ( V_10 , 0x1 ) ;
break;
case V_64 :
F_2 ( V_63 , 0x1 ) ;
F_2 ( V_10 , 0x1 ) ;
break;
case V_9 :
F_2 ( V_63 , 0x80 ) ;
break;
}
V_4 -> V_41 = true ;
V_4 -> V_45 = false ;
if ( V_4 -> V_14 ) {
F_30 ( & V_4 -> V_43 , F_24 ,
( unsigned long ) V_2 ) ;
V_4 -> V_43 . V_65 = V_44 + V_66 ;
F_31 ( & V_4 -> V_43 ) ;
} else if ( V_4 -> V_42 ) {
F_30 ( & V_4 -> V_43 , F_27 ,
( unsigned long ) V_2 ) ;
}
return 0 ;
}
static void F_32 ( void * V_46 )
{
struct V_1 * V_2 = V_46 ;
struct V_3 * V_4 ;
if ( ! V_2 || ! V_2 -> V_5 )
return;
V_4 = V_2 -> V_5 ;
if ( ! V_4 -> V_41 )
return;
if ( V_4 -> V_14 || V_4 -> V_42 )
F_33 ( & V_4 -> V_43 ) ;
V_4 -> V_45 = false ;
V_4 -> V_41 = false ;
return;
}
int F_34 ( struct V_1 * V_2 )
{
if ( V_2 -> V_5 -> V_67 )
return F_29 ( V_2 ) ;
return 0 ;
}
void F_35 ( struct V_1 * V_2 )
{
if ( V_2 -> V_5 -> V_67 )
F_32 ( V_2 ) ;
}
static int F_36 ( struct V_68 * V_69 )
{
struct V_1 * V_2 = V_69 -> V_46 ;
V_2 -> V_5 -> V_67 ++ ;
return F_29 ( V_2 ) ;
}
static void F_37 ( struct V_68 * V_69 )
{
struct V_1 * V_2 = V_69 -> V_46 ;
V_2 -> V_5 -> V_67 -- ;
if ( ! V_2 -> V_5 -> V_67 )
F_32 ( V_2 ) ;
}
int F_38 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
struct V_68 * V_69 ;
char * V_70 = NULL ;
T_1 V_16 = 0 ;
T_1 V_18 = 0 ;
T_1 V_19 = 0 ;
unsigned V_14 = 0 ;
bool V_42 = false ;
int V_71 ;
if ( V_2 -> V_72 != V_73 )
return - V_74 ;
if ( V_75 )
return - V_74 ;
switch ( V_2 -> V_8 ) {
case V_76 :
case V_77 :
case V_78 :
case V_79 :
case V_80 :
V_70 = V_81 ;
V_16 = 0xEC00000 ;
V_18 = 0x0040000 ;
break;
case V_82 :
case V_83 :
case V_84 :
V_70 = V_85 ;
V_16 = 0x00003f ;
V_19 = 0x040000 ;
break;
case V_86 :
case V_87 :
V_70 = V_88 ;
V_16 = 0x00017c ;
V_19 = 0x000002 ;
V_14 = 50 ;
break;
case V_89 :
case V_90 :
V_70 = V_91 ;
V_16 = 0x00001F ;
V_19 = 0x000020 ;
V_14 = 50 ;
break;
case V_48 :
case V_49 :
case V_50 :
case V_51 :
case V_52 :
case V_53 :
case V_54 :
case V_55 :
case V_56 :
case V_57 :
case V_58 :
case V_59 :
V_70 = V_92 ;
V_16 = 0x0007C8 ;
V_18 = 0x000010 ;
V_14 = 50 ;
break;
case V_93 :
V_70 = V_94 ;
V_18 = 0x0040000 ;
V_19 = 0x0040000 ;
V_16 = 0xffff ;
V_42 = true ;
break;
case V_95 :
V_70 = V_96 ;
V_18 = 0x0040000 ;
V_19 = 0x0040000 ;
V_16 = 0xffff ;
V_42 = true ;
break;
case V_61 :
case V_62 :
V_70 = V_92 ;
V_16 = 0x02F200 ;
V_18 = 0x000400 ;
V_14 = 50 ;
break;
case V_64 :
V_70 = V_97 ;
V_16 = 0x02F200 ;
V_18 = 0x000400 ;
V_14 = 50 ;
break;
case V_98 :
V_70 = V_91 ;
V_16 = 0x00001f ;
V_19 = 0x000060 ;
V_14 = 50 ;
break;
case V_99 :
case V_100 :
V_70 = V_101 ;
V_16 = 0x001f00 ;
V_19 = 0x004000 ;
V_14 = 50 ;
break;
case V_102 :
case V_103 :
case V_104 :
case V_105 :
case V_106 :
case V_107 :
case V_108 :
case V_109 :
case V_110 :
case V_111 :
case V_112 :
case V_113 :
case V_114 :
case V_115 :
case V_116 :
V_70 = V_101 ;
V_16 = 0x003f00 ;
V_19 = 0x004000 ;
V_14 = 50 ;
break;
case V_117 :
V_70 = V_118 ;
V_16 = 0x003f00 ;
V_19 = 0x004000 ;
V_14 = 50 ;
break;
case V_119 :
V_70 = V_120 ;
V_16 = 0x001f00 ;
V_19 = 0x004000 ;
V_14 = 50 ;
break;
case V_9 :
V_70 = V_121 ;
V_16 = 0x0003CC ;
V_18 = 0x000010 ;
V_14 = 5 ;
break;
case V_122 :
case V_123 :
case V_124 :
V_70 = V_125 ;
V_16 = 0x00003F ;
V_19 = 0x400000 ;
V_14 = 50 ;
break;
case V_126 :
V_70 = V_127 ;
V_16 = 0x00007F ;
V_19 = 0x000080 ;
V_14 = 50 ;
break;
case V_128 :
case V_129 :
V_70 = V_125 ;
V_16 = 0x003F00 ;
V_19 = 0x040000 ;
break;
case V_130 :
case V_131 :
case V_132 :
V_70 = V_133 ;
V_16 = 0x0001F00 ;
V_18 = 0x0040000 ;
break;
case V_134 :
case V_135 :
case V_136 :
V_70 = V_137 ;
V_18 = 0x0040000 ;
V_19 = 0x0040000 ;
V_16 = 0xffff ;
V_42 = true ;
break;
case V_138 :
case V_139 :
V_70 = V_140 ;
V_16 = 0x00007f ;
V_19 = 0x040000 ;
V_14 = 50 ;
break;
case V_141 :
case V_142 :
V_70 = V_143 ;
V_18 = 0x0040000 ;
V_19 = 0x0040000 ;
V_16 = 0xffff ;
V_42 = true ;
break;
case V_144 :
V_70 = V_140 ;
V_16 = 0x5f80000 ;
V_19 = 0x8000000 ;
V_14 = 50 ;
break;
case V_145 :
V_70 = V_146 ;
V_16 = 0xff ;
V_18 = 0xf00000 ;
V_14 = 50 ;
break;
case V_147 :
V_70 = V_148 ;
V_16 = 0x3f00 ;
V_19 = 0x4000 ;
V_14 = 50 ;
break;
case V_17 :
V_70 = V_149 ;
V_16 = 0x7f ;
V_14 = 40 ;
break;
case V_150 :
V_70 = V_151 ;
V_16 = 0x003f00 ;
V_18 = 0x040000 ;
break;
case V_152 :
V_70 = V_153 ;
V_16 = 0x5f00 ;
V_19 = 0x020000 ;
V_14 = 50 ;
break;
case V_154 :
V_70 = V_155 ;
V_16 = 0x0ff00 ;
V_19 = 0x040000 ;
break;
case V_156 :
case V_157 :
V_70 = V_158 ;
V_18 = 0x0040000 ;
V_19 = 0x0040000 ;
V_16 = 0xffff ;
V_42 = true ;
break;
}
if ( NULL == V_70 ) {
F_39 ( L_10 ,
V_2 -> V_159 , V_2 -> V_8 ) ;
return - V_74 ;
}
V_4 = F_40 ( sizeof( * V_4 ) , V_160 ) ;
V_69 = F_41 () ;
if ( ! V_4 || ! V_69 ) {
V_71 = - V_161 ;
goto V_162;
}
V_4 -> V_2 = V_69 ;
V_2 -> V_5 = V_4 ;
V_4 -> V_16 = V_16 ;
V_4 -> V_18 = V_18 ;
V_4 -> V_19 = V_19 ;
V_4 -> V_14 = V_14 ;
V_4 -> V_42 = V_42 ;
snprintf ( V_4 -> V_159 , sizeof( V_4 -> V_159 ) , L_11 ,
V_163 [ V_2 -> V_8 ] . V_159 ) ;
snprintf ( V_4 -> V_164 , sizeof( V_4 -> V_164 ) , L_12 ,
F_42 ( V_2 -> V_165 ) ) ;
V_69 -> V_46 = V_2 ;
V_69 -> V_166 = F_36 ;
V_69 -> V_167 = F_37 ;
if ( V_42 )
V_69 -> V_168 = V_169 ;
V_69 -> V_170 = V_4 -> V_159 ;
V_69 -> V_171 = V_4 -> V_164 ;
V_69 -> V_172 . V_173 = V_174 ;
V_69 -> V_172 . V_175 = 1 ;
if ( V_2 -> V_165 -> V_176 ) {
V_69 -> V_172 . V_177 = V_2 -> V_165 -> V_176 ;
V_69 -> V_172 . V_178 = V_2 -> V_165 -> V_179 ;
} else {
V_69 -> V_172 . V_177 = V_2 -> V_165 -> V_177 ;
V_69 -> V_172 . V_178 = V_2 -> V_165 -> V_180 ;
}
V_69 -> V_2 . V_181 = & V_2 -> V_165 -> V_2 ;
V_69 -> V_182 = V_70 ;
V_69 -> V_183 = V_184 ;
V_71 = F_43 ( V_69 ) ;
if ( V_71 )
goto V_162;
return 0 ;
V_162:
F_44 ( V_69 ) ;
V_2 -> V_5 = NULL ;
F_45 ( V_4 ) ;
return V_71 ;
}
void F_46 ( struct V_1 * V_2 )
{
if ( NULL == V_2 -> V_5 )
return;
F_35 ( V_2 ) ;
F_47 ( V_2 -> V_5 -> V_2 ) ;
F_45 ( V_2 -> V_5 ) ;
V_2 -> V_5 = NULL ;
}
void F_48 ( struct V_1 * V_2 )
{
struct V_185 V_186 ;
struct V_187 V_188 = {
. V_33 = 0x50 ,
. V_189 = V_190 ,
. V_191 = 0 ,
. V_29 = NULL ,
} ;
int V_69 ;
if ( V_75 ) {
F_6 ( L_13 ) ;
return;
}
memset ( & V_186 , 0 , sizeof( struct V_185 ) ) ;
memset ( & V_2 -> V_192 , 0 , sizeof( V_2 -> V_192 ) ) ;
F_49 ( V_186 . type , L_14 , V_193 ) ;
switch ( V_2 -> V_8 ) {
case V_194 :
case V_195 :
V_2 -> V_192 . V_159 = L_15 ;
if ( V_196 == 0 ) {
V_2 -> V_192 . V_197 = F_21 ;
V_2 -> V_192 . V_70 = V_198 ;
V_186 . V_33 = 0x47 ;
} else {
V_2 -> V_192 . V_197 = F_20 ;
V_2 -> V_192 . V_70 = V_199 ;
V_186 . V_33 = 0x47 ;
}
break;
case V_200 :
V_2 -> V_192 . V_159 = L_16 ;
V_2 -> V_192 . V_197 = F_15 ;
V_2 -> V_192 . V_70 = V_201 ;
V_186 . V_33 = 0x7a ;
break;
case V_202 :
V_2 -> V_192 . V_159 = L_17 ;
V_2 -> V_192 . V_197 = F_14 ;
V_2 -> V_192 . V_70 = V_203 ;
V_2 -> V_192 . V_204 = 50 ;
V_186 . V_33 = 0x30 ;
V_69 = F_50 ( & V_2 -> V_205 , & V_188 , 1 ) ;
F_6 ( L_18 ,
V_188 . V_33 , V_2 -> V_205 . V_159 ,
( 1 == V_69 ) ? L_19 : L_20 ) ;
break;
case V_206 :
V_2 -> V_192 . V_159 = L_21 ;
V_2 -> V_192 . V_197 = F_16 ;
V_2 -> V_192 . V_70 = V_158 ;
V_186 . V_33 = 0x71 ;
break;
case V_207 :
case V_208 :
case V_209 :
case V_210 :
case V_211 :
case V_212 :
case V_213 :
case V_214 :
case V_215 :
case V_216 :
case V_217 :
case V_218 :
case V_219 :
case V_220 :
case V_221 :
V_2 -> V_192 . V_159 = L_22 ;
V_2 -> V_192 . V_197 = F_17 ;
V_2 -> V_192 . V_70 = V_222 ;
V_2 -> V_192 . type = V_223 ;
V_186 . V_33 = 0x2d ;
break;
case V_224 :
case V_225 :
V_186 . V_33 = 0x40 ;
break;
case V_226 :
V_2 -> V_192 . V_159 = L_23 ;
V_2 -> V_192 . V_197 = F_9 ;
V_2 -> V_192 . V_70 = V_133 ;
V_186 . V_33 = 0x0b ;
break;
default:
F_6 ( L_24 , V_2 -> V_8 ) ;
return;
}
if ( V_2 -> V_192 . V_159 )
V_186 . V_227 = & V_2 -> V_192 ;
F_51 ( & V_2 -> V_205 , & V_186 ) ;
}
static int F_23 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
unsigned long V_228 ;
int V_229 ;
F_3 ( V_11 , V_12 ) ;
F_2 ( V_11 , V_12 ) ;
V_229 = F_4 ( V_13 >> 2 ) & V_4 -> V_18 ;
F_52 ( V_2 -> V_5 -> V_2 , V_229 ? V_230 : V_231 ) ;
if ( ! V_4 -> V_45 ) {
V_228 = V_44 + F_26 ( 15 ) ;
F_25 ( & V_4 -> V_43 , V_228 ) ;
V_4 -> V_45 = true ;
}
return 1 ;
}
