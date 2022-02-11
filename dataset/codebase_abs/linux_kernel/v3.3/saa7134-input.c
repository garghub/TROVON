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
unsigned char V_29 [ 5 ] ;
if ( 5 != F_13 ( V_4 -> V_25 , V_29 , 5 ) )
return - V_28 ;
if ( ! ( V_29 [ 0 ] & 0x80 ) )
return 0 ;
* V_21 = 0x1fff & ( ( V_29 [ 3 ] << 8 ) | ( V_29 [ 4 ] >> 2 ) ) ;
* V_22 = * V_21 ;
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
V_4 -> V_25 -> V_30 = 0x5a >> 1 ;
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
int V_31 , int V_32 , int V_33 )
{
unsigned char V_24 [ 4 ] ;
unsigned int V_34 = 0 , V_35 = 0 , V_36 = 0 ;
if ( 4 != F_13 ( V_4 -> V_25 , V_24 , 4 ) ) {
F_10 ( L_6 ) ;
return - V_28 ;
}
for ( V_34 = 0 ; V_34 < F_19 ( V_24 ) ; V_34 ++ ) {
if ( V_24 [ V_34 ] == V_32 ) {
V_36 = V_24 [ ( V_34 + V_31 + 1 ) % 4 ] ;
V_35 = V_24 [ ( V_34 + V_31 ) % 4 ] ;
}
}
if ( V_35 == 0 )
return 0 ;
if ( V_4 -> V_37 == V_35 )
return 0 ;
V_4 -> V_37 = V_35 ;
if ( V_32 == 0xfe && ( V_36 & 0x40 ) )
return 0 ;
V_36 %= V_33 ;
* V_22 = V_36 ;
* V_21 = V_36 ;
F_10 ( L_9 , V_36 ) ;
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
if ( ! V_4 -> V_38 )
return;
if ( ! V_4 -> V_14 && ! V_4 -> V_39 ) {
F_1 ( V_2 ) ;
} else if ( V_4 -> V_39 ) {
F_23 ( V_2 ) ;
}
}
static void F_24 ( unsigned long V_7 )
{
struct V_1 * V_2 = (struct V_1 * ) V_7 ;
struct V_3 * V_4 = V_2 -> V_5 ;
F_1 ( V_2 ) ;
F_25 ( & V_4 -> V_40 , V_41 + F_26 ( V_4 -> V_14 ) ) ;
}
static void F_27 ( unsigned long V_7 )
{
struct V_1 * V_2 = (struct V_1 * ) V_7 ;
struct V_3 * V_4 = V_2 -> V_5 ;
F_28 ( V_2 -> V_5 -> V_2 ) ;
V_4 -> V_42 = false ;
}
static int F_29 ( void * V_43 )
{
struct V_1 * V_2 = V_43 ;
struct V_3 * V_4 ;
if ( ! V_2 || ! V_2 -> V_5 )
return - V_44 ;
V_4 = V_2 -> V_5 ;
if ( V_4 -> V_38 )
return 0 ;
switch ( V_2 -> V_8 ) {
case V_45 :
case V_46 :
case V_47 :
case V_48 :
case V_49 :
case V_50 :
case V_51 :
case V_52 :
case V_53 :
case V_54 :
case V_55 :
case V_56 :
F_2 ( V_57 , 0x4 ) ;
F_2 ( V_13 , 0x4 ) ;
break;
case V_58 :
case V_59 :
F_2 ( V_60 , 0x1 ) ;
F_2 ( V_10 , 0x1 ) ;
break;
case V_61 :
F_2 ( V_60 , 0x1 ) ;
F_2 ( V_10 , 0x1 ) ;
break;
case V_9 :
F_2 ( V_60 , 0x80 ) ;
break;
}
V_4 -> V_38 = true ;
V_4 -> V_42 = false ;
if ( V_4 -> V_14 ) {
F_30 ( & V_4 -> V_40 , F_24 ,
( unsigned long ) V_2 ) ;
V_4 -> V_40 . V_62 = V_41 + V_63 ;
F_31 ( & V_4 -> V_40 ) ;
} else if ( V_4 -> V_39 ) {
F_30 ( & V_4 -> V_40 , F_27 ,
( unsigned long ) V_2 ) ;
}
return 0 ;
}
static void F_32 ( void * V_43 )
{
struct V_1 * V_2 = V_43 ;
struct V_3 * V_4 ;
if ( ! V_2 || ! V_2 -> V_5 )
return;
V_4 = V_2 -> V_5 ;
if ( ! V_4 -> V_38 )
return;
if ( V_4 -> V_14 || V_4 -> V_39 )
F_33 ( & V_4 -> V_40 ) ;
V_4 -> V_42 = false ;
V_4 -> V_38 = false ;
return;
}
int F_34 ( struct V_1 * V_2 )
{
if ( V_2 -> V_5 -> V_64 )
return F_29 ( V_2 ) ;
return 0 ;
}
void F_35 ( struct V_1 * V_2 )
{
if ( V_2 -> V_5 -> V_64 )
F_32 ( V_2 ) ;
}
static int F_36 ( struct V_65 * V_66 )
{
struct V_1 * V_2 = V_66 -> V_43 ;
V_2 -> V_5 -> V_64 ++ ;
return F_29 ( V_2 ) ;
}
static void F_37 ( struct V_65 * V_66 )
{
struct V_1 * V_2 = V_66 -> V_43 ;
V_2 -> V_5 -> V_64 -- ;
if ( ! V_2 -> V_5 -> V_64 )
F_32 ( V_2 ) ;
}
int F_38 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
struct V_65 * V_66 ;
char * V_67 = NULL ;
T_1 V_16 = 0 ;
T_1 V_18 = 0 ;
T_1 V_19 = 0 ;
unsigned V_14 = 0 ;
bool V_39 = false ;
int V_68 ;
if ( V_2 -> V_69 != V_70 )
return - V_71 ;
if ( V_72 )
return - V_71 ;
switch ( V_2 -> V_8 ) {
case V_73 :
case V_74 :
case V_75 :
case V_76 :
case V_77 :
V_67 = V_78 ;
V_16 = 0xEC00000 ;
V_18 = 0x0040000 ;
break;
case V_79 :
case V_80 :
case V_81 :
V_67 = V_82 ;
V_16 = 0x00003f ;
V_19 = 0x040000 ;
break;
case V_83 :
case V_84 :
V_67 = V_85 ;
V_16 = 0x00017c ;
V_19 = 0x000002 ;
V_14 = 50 ;
break;
case V_86 :
case V_87 :
V_67 = V_88 ;
V_16 = 0x00001F ;
V_19 = 0x000020 ;
V_14 = 50 ;
break;
case V_45 :
case V_46 :
case V_47 :
case V_48 :
case V_49 :
case V_50 :
case V_51 :
case V_52 :
case V_53 :
case V_54 :
case V_55 :
case V_56 :
V_67 = V_89 ;
V_16 = 0x0007C8 ;
V_18 = 0x000010 ;
V_14 = 50 ;
break;
case V_90 :
V_67 = V_91 ;
V_18 = 0x0040000 ;
V_19 = 0x0040000 ;
V_16 = 0xffff ;
V_39 = true ;
break;
case V_92 :
V_67 = V_93 ;
V_18 = 0x0040000 ;
V_19 = 0x0040000 ;
V_16 = 0xffff ;
V_39 = true ;
break;
case V_58 :
case V_59 :
V_67 = V_89 ;
V_16 = 0x02F200 ;
V_18 = 0x000400 ;
V_14 = 50 ;
break;
case V_61 :
V_67 = V_94 ;
V_16 = 0x02F200 ;
V_18 = 0x000400 ;
V_14 = 50 ;
break;
case V_95 :
V_67 = V_88 ;
V_16 = 0x00001f ;
V_19 = 0x000060 ;
V_14 = 50 ;
break;
case V_96 :
case V_97 :
V_67 = V_98 ;
V_16 = 0x001f00 ;
V_19 = 0x004000 ;
V_14 = 50 ;
break;
case V_99 :
case V_100 :
case V_101 :
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
V_67 = V_98 ;
V_16 = 0x003f00 ;
V_19 = 0x004000 ;
V_14 = 50 ;
break;
case V_114 :
V_67 = V_115 ;
V_16 = 0x003f00 ;
V_19 = 0x004000 ;
V_14 = 50 ;
break;
case V_116 :
V_67 = V_117 ;
V_16 = 0x001f00 ;
V_19 = 0x004000 ;
V_14 = 50 ;
break;
case V_9 :
V_67 = V_118 ;
V_16 = 0x0003CC ;
V_18 = 0x000010 ;
V_14 = 5 ;
break;
case V_119 :
case V_120 :
case V_121 :
V_67 = V_122 ;
V_16 = 0x00003F ;
V_19 = 0x400000 ;
V_14 = 50 ;
break;
case V_123 :
V_67 = V_124 ;
V_16 = 0x00007F ;
V_19 = 0x000080 ;
V_14 = 50 ;
break;
case V_125 :
case V_126 :
V_67 = V_122 ;
V_16 = 0x003F00 ;
V_19 = 0x040000 ;
break;
case V_127 :
case V_128 :
case V_129 :
V_67 = V_130 ;
V_16 = 0x0001F00 ;
V_18 = 0x0040000 ;
break;
case V_131 :
case V_132 :
case V_133 :
V_67 = V_134 ;
V_18 = 0x0040000 ;
V_19 = 0x0040000 ;
V_16 = 0xffff ;
V_39 = true ;
break;
case V_135 :
case V_136 :
V_67 = V_137 ;
V_16 = 0x00007f ;
V_19 = 0x040000 ;
V_14 = 50 ;
break;
case V_138 :
case V_139 :
V_67 = V_140 ;
V_18 = 0x0040000 ;
V_19 = 0x0040000 ;
V_16 = 0xffff ;
V_39 = true ;
break;
case V_141 :
V_67 = V_137 ;
V_16 = 0x5f80000 ;
V_19 = 0x8000000 ;
V_14 = 50 ;
break;
case V_142 :
V_67 = V_143 ;
V_16 = 0xff ;
V_18 = 0xf00000 ;
V_14 = 50 ;
break;
case V_144 :
V_67 = V_145 ;
V_16 = 0x3f00 ;
V_19 = 0x4000 ;
V_14 = 50 ;
break;
case V_17 :
V_67 = V_146 ;
V_16 = 0x7f ;
V_14 = 40 ;
break;
case V_147 :
V_67 = V_148 ;
V_16 = 0x003f00 ;
V_18 = 0x040000 ;
break;
case V_149 :
V_67 = V_150 ;
V_16 = 0x5f00 ;
V_19 = 0x020000 ;
V_14 = 50 ;
break;
case V_151 :
V_67 = V_152 ;
V_16 = 0x0ff00 ;
V_19 = 0x040000 ;
break;
case V_153 :
case V_154 :
V_67 = V_155 ;
V_18 = 0x0040000 ;
V_19 = 0x0040000 ;
V_16 = 0xffff ;
V_39 = true ;
break;
}
if ( NULL == V_67 ) {
F_39 ( L_10 ,
V_2 -> V_156 , V_2 -> V_8 ) ;
return - V_71 ;
}
V_4 = F_40 ( sizeof( * V_4 ) , V_157 ) ;
V_66 = F_41 () ;
if ( ! V_4 || ! V_66 ) {
V_68 = - V_158 ;
goto V_159;
}
V_4 -> V_2 = V_66 ;
V_2 -> V_5 = V_4 ;
V_4 -> V_16 = V_16 ;
V_4 -> V_18 = V_18 ;
V_4 -> V_19 = V_19 ;
V_4 -> V_14 = V_14 ;
V_4 -> V_39 = V_39 ;
snprintf ( V_4 -> V_156 , sizeof( V_4 -> V_156 ) , L_11 ,
V_160 [ V_2 -> V_8 ] . V_156 ) ;
snprintf ( V_4 -> V_161 , sizeof( V_4 -> V_161 ) , L_12 ,
F_42 ( V_2 -> V_162 ) ) ;
V_66 -> V_43 = V_2 ;
V_66 -> V_163 = F_36 ;
V_66 -> V_164 = F_37 ;
if ( V_39 )
V_66 -> V_165 = V_166 ;
V_66 -> V_167 = V_4 -> V_156 ;
V_66 -> V_168 = V_4 -> V_161 ;
V_66 -> V_169 . V_170 = V_171 ;
V_66 -> V_169 . V_172 = 1 ;
if ( V_2 -> V_162 -> V_173 ) {
V_66 -> V_169 . V_174 = V_2 -> V_162 -> V_173 ;
V_66 -> V_169 . V_175 = V_2 -> V_162 -> V_176 ;
} else {
V_66 -> V_169 . V_174 = V_2 -> V_162 -> V_174 ;
V_66 -> V_169 . V_175 = V_2 -> V_162 -> V_177 ;
}
V_66 -> V_2 . V_178 = & V_2 -> V_162 -> V_2 ;
V_66 -> V_179 = V_67 ;
V_66 -> V_180 = V_181 ;
V_68 = F_43 ( V_66 ) ;
if ( V_68 )
goto V_159;
return 0 ;
V_159:
F_44 ( V_66 ) ;
V_2 -> V_5 = NULL ;
F_45 ( V_4 ) ;
return V_68 ;
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
struct V_182 V_183 ;
struct V_184 V_185 = {
. V_30 = 0x50 ,
. V_186 = V_187 ,
. V_188 = 0 ,
. V_29 = NULL ,
} ;
int V_66 ;
if ( V_72 ) {
F_6 ( L_13 ) ;
return;
}
memset ( & V_183 , 0 , sizeof( struct V_182 ) ) ;
memset ( & V_2 -> V_189 , 0 , sizeof( V_2 -> V_189 ) ) ;
F_49 ( V_183 . type , L_14 , V_190 ) ;
switch ( V_2 -> V_8 ) {
case V_191 :
case V_192 :
V_2 -> V_189 . V_156 = L_15 ;
if ( V_193 == 0 ) {
V_2 -> V_189 . V_194 = F_21 ;
V_2 -> V_189 . V_67 = V_195 ;
V_183 . V_30 = 0x47 ;
} else {
V_2 -> V_189 . V_194 = F_20 ;
V_2 -> V_189 . V_67 = V_196 ;
V_183 . V_30 = 0x47 ;
}
break;
case V_197 :
V_2 -> V_189 . V_156 = L_16 ;
V_2 -> V_189 . V_194 = F_15 ;
V_2 -> V_189 . V_67 = V_198 ;
V_183 . V_30 = 0x7a ;
break;
case V_199 :
V_2 -> V_189 . V_156 = L_17 ;
V_2 -> V_189 . V_194 = F_14 ;
V_2 -> V_189 . V_67 = V_200 ;
V_2 -> V_189 . V_201 = 50 ;
V_183 . V_30 = 0x30 ;
V_66 = F_50 ( & V_2 -> V_202 , & V_185 , 1 ) ;
F_6 ( L_18 ,
V_185 . V_30 , V_2 -> V_202 . V_156 ,
( 1 == V_66 ) ? L_19 : L_20 ) ;
break;
case V_203 :
V_2 -> V_189 . V_156 = L_21 ;
V_2 -> V_189 . V_194 = F_16 ;
V_2 -> V_189 . V_67 = V_155 ;
V_183 . V_30 = 0x71 ;
break;
case V_204 :
case V_205 :
case V_206 :
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
V_2 -> V_189 . V_156 = L_22 ;
V_2 -> V_189 . V_194 = F_17 ;
V_2 -> V_189 . V_67 = V_219 ;
V_2 -> V_189 . type = V_220 ;
V_183 . V_30 = 0x2d ;
break;
case V_221 :
case V_222 :
V_183 . V_30 = 0x40 ;
break;
case V_223 :
V_2 -> V_189 . V_156 = L_23 ;
V_2 -> V_189 . V_194 = F_9 ;
V_2 -> V_189 . V_67 = V_130 ;
V_183 . V_30 = 0x0b ;
break;
default:
F_6 ( L_24 , V_2 -> V_8 ) ;
return;
}
if ( V_2 -> V_189 . V_156 )
V_183 . V_224 = & V_2 -> V_189 ;
F_51 ( & V_2 -> V_202 , & V_183 ) ;
}
static int F_23 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
unsigned long V_225 ;
int V_226 ;
F_3 ( V_11 , V_12 ) ;
F_2 ( V_11 , V_12 ) ;
V_226 = F_4 ( V_13 >> 2 ) & V_4 -> V_18 ;
F_52 ( V_2 -> V_5 -> V_2 , V_226 ? V_227 : V_228 ) ;
if ( ! V_4 -> V_42 ) {
V_225 = V_41 + F_26 ( 15 ) ;
F_25 ( & V_4 -> V_40 , V_225 ) ;
V_4 -> V_42 = true ;
}
return 1 ;
}
