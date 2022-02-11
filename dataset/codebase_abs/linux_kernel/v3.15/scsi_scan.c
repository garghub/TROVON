int F_1 ( void )
{
struct V_1 * V_2 ;
do {
if ( F_2 ( & V_3 ) )
return 0 ;
V_2 = F_3 ( sizeof( * V_2 ) , V_4 ) ;
if ( ! V_2 )
F_4 ( 1 ) ;
} while ( ! V_2 );
V_2 -> V_5 = NULL ;
F_5 ( & V_2 -> V_6 ) ;
F_6 ( & V_7 ) ;
if ( F_2 ( & V_3 ) )
goto V_8;
F_7 ( & V_2 -> V_9 , & V_3 ) ;
F_8 ( & V_7 ) ;
F_9 ( V_10 L_1 ) ;
F_10 ( & V_2 -> V_6 ) ;
F_6 ( & V_7 ) ;
F_11 ( & V_2 -> V_9 ) ;
if ( ! F_2 ( & V_3 ) ) {
struct V_1 * V_11 = F_12 ( V_3 . V_11 ,
struct V_1 , V_9 ) ;
F_13 ( & V_11 -> V_6 ) ;
}
V_8:
F_8 ( & V_7 ) ;
F_14 ( V_2 ) ;
return 0 ;
}
static void F_15 ( struct V_12 * V_13 ,
unsigned char * V_14 )
{
unsigned char V_15 [ V_16 ] ;
F_9 ( V_17 L_2 ) ;
V_15 [ 0 ] = V_18 ;
V_15 [ 1 ] = 0 ;
V_15 [ 2 ] = 0x2e ;
V_15 [ 3 ] = 0 ;
V_15 [ 4 ] = 0x2a ;
V_15 [ 5 ] = 0 ;
F_16 ( V_13 , V_15 , V_19 , V_14 , 0x2a , NULL ,
V_20 , 3 , NULL ) ;
}
static struct V_12 * F_17 ( struct V_21 * V_22 ,
unsigned int V_23 , void * V_24 )
{
struct V_12 * V_13 ;
int V_25 = 1 , V_26 ;
struct V_27 * V_5 = F_18 ( V_22 -> V_28 . V_29 ) ;
extern void V_30 ( struct V_31 * V_32 ) ;
extern void V_33 ( struct V_31 * V_32 ) ;
V_13 = F_19 ( sizeof( * V_13 ) + V_5 -> V_34 -> V_35 ,
V_36 ) ;
if ( ! V_13 )
goto V_37;
V_13 -> V_38 = V_39 ;
V_13 -> V_40 = V_39 ;
V_13 -> V_41 = V_39 ;
V_13 -> V_42 = V_5 ;
V_13 -> V_43 = V_44 ;
V_13 -> V_45 = V_22 -> V_45 ;
V_13 -> V_23 = V_23 ;
V_13 -> V_46 = V_22 -> V_46 ;
V_13 -> V_47 = V_48 ;
F_20 ( & V_13 -> V_49 ) ;
F_20 ( & V_13 -> V_50 ) ;
F_20 ( & V_13 -> V_51 ) ;
F_20 ( & V_13 -> V_52 ) ;
F_20 ( & V_13 -> V_53 ) ;
F_21 ( & V_13 -> V_54 ) ;
F_22 ( & V_13 -> V_55 , V_30 ) ;
F_22 ( & V_13 -> V_56 , V_33 ) ;
V_13 -> V_57 . V_29 = F_23 ( & V_22 -> V_28 ) ;
V_13 -> V_58 = V_22 ;
V_13 -> V_24 = V_24 ;
V_13 -> V_59 = V_60 ;
V_13 -> type = - 1 ;
V_13 -> V_61 = 1 ;
V_13 -> V_62 = F_24 ( V_13 ) ;
if ( ! V_13 -> V_62 ) {
F_25 ( & V_22 -> V_28 ) ;
F_14 ( V_13 ) ;
goto V_37;
}
F_26 ( ! F_27 ( V_13 -> V_62 ) ) ;
V_13 -> V_62 -> V_63 = V_13 ;
F_28 ( V_13 , 0 , V_13 -> V_42 -> V_64 ) ;
F_29 ( V_13 ) ;
if ( V_5 -> V_65 -> V_66 ) {
V_26 = V_5 -> V_65 -> V_66 ( V_13 ) ;
if ( V_26 ) {
if ( V_26 == - V_67 )
V_25 = 0 ;
goto V_68;
}
}
return V_13 ;
V_68:
F_30 ( V_13 ) ;
V_37:
if ( V_25 )
F_9 ( V_69 , V_70 ) ;
return NULL ;
}
static void F_31 ( struct V_21 * V_22 )
{
struct V_71 * V_28 = & V_22 -> V_28 ;
struct V_27 * V_5 = F_18 ( V_28 -> V_29 ) ;
unsigned long V_72 ;
V_22 -> V_73 = V_74 ;
F_32 ( V_28 ) ;
F_33 ( V_5 -> V_75 , V_72 ) ;
if ( V_5 -> V_65 -> V_76 )
V_5 -> V_65 -> V_76 ( V_22 ) ;
F_34 ( & V_22 -> V_49 ) ;
F_35 ( V_5 -> V_75 , V_72 ) ;
F_25 ( V_28 ) ;
}
static void F_36 ( struct V_71 * V_28 )
{
struct V_71 * V_29 = V_28 -> V_29 ;
struct V_21 * V_22 = F_37 ( V_28 ) ;
F_14 ( V_22 ) ;
F_25 ( V_29 ) ;
}
int F_38 ( const struct V_71 * V_28 )
{
return V_28 -> type == & V_77 ;
}
static struct V_21 * F_39 ( struct V_71 * V_29 ,
int V_46 , T_1 V_45 )
{
struct V_21 * V_22 , * V_78 = NULL ;
struct V_27 * V_5 = F_18 ( V_29 ) ;
F_40 (starget, &shost->__targets, siblings) {
if ( V_22 -> V_45 == V_45 &&
V_22 -> V_46 == V_46 ) {
V_78 = V_22 ;
break;
}
}
if ( V_78 )
F_23 ( & V_78 -> V_28 ) ;
return V_78 ;
}
static void F_41 ( struct V_79 * V_79 )
{
struct V_21 * V_22
= F_42 ( V_79 , struct V_21 , V_80 ) ;
if ( V_22 -> V_73 != V_81 ) {
F_43 ( & V_22 -> V_28 ) ;
F_44 ( & V_22 -> V_28 ) ;
}
F_31 ( V_22 ) ;
}
static void F_45 ( struct V_21 * V_22 )
{
F_46 ( & V_22 -> V_80 , F_41 ) ;
}
static struct V_21 * F_47 ( struct V_71 * V_29 ,
int V_46 , T_1 V_45 )
{
struct V_27 * V_5 = F_18 ( V_29 ) ;
struct V_71 * V_28 = NULL ;
unsigned long V_72 ;
const int V_82 = sizeof( struct V_21 )
+ V_5 -> V_34 -> V_83 ;
struct V_21 * V_22 ;
struct V_21 * V_84 ;
int error , V_85 ;
V_22 = F_19 ( V_82 , V_4 ) ;
if ( ! V_22 ) {
F_9 ( V_86 L_3 , V_70 ) ;
return NULL ;
}
V_28 = & V_22 -> V_28 ;
F_48 ( V_28 ) ;
F_49 ( & V_22 -> V_80 ) ;
V_28 -> V_29 = F_23 ( V_29 ) ;
F_50 ( V_28 , L_4 , V_5 -> V_87 , V_46 , V_45 ) ;
V_28 -> V_88 = & V_89 ;
V_28 -> type = & V_77 ;
V_22 -> V_45 = V_45 ;
V_22 -> V_46 = V_46 ;
V_22 -> V_90 = 0 ;
F_20 ( & V_22 -> V_49 ) ;
F_20 ( & V_22 -> V_91 ) ;
V_22 -> V_73 = V_81 ;
V_22 -> V_92 = V_93 ;
V_22 -> V_94 = V_95 ;
V_96:
F_33 ( V_5 -> V_75 , V_72 ) ;
V_84 = F_39 ( V_29 , V_46 , V_45 ) ;
if ( V_84 )
goto V_97;
F_7 ( & V_22 -> V_49 , & V_5 -> V_98 ) ;
F_35 ( V_5 -> V_75 , V_72 ) ;
F_51 ( V_28 ) ;
if ( V_5 -> V_65 -> V_99 ) {
error = V_5 -> V_65 -> V_99 ( V_22 ) ;
if( error ) {
F_52 ( V_86 , V_28 , L_5 , error ) ;
F_31 ( V_22 ) ;
return NULL ;
}
}
F_23 ( V_28 ) ;
return V_22 ;
V_97:
V_85 = F_53 ( & V_84 -> V_80 ) ;
F_35 ( V_5 -> V_75 , V_72 ) ;
if ( V_85 ) {
F_25 ( V_28 ) ;
return V_84 ;
}
F_25 ( & V_84 -> V_28 ) ;
F_4 ( 1 ) ;
goto V_96;
}
void F_54 ( struct V_21 * V_22 )
{
F_55 ( V_22 -> V_73 == V_74 ) ;
F_45 ( V_22 ) ;
}
static void F_56 ( unsigned char * V_100 , int V_101 )
{
int V_102 = 0 ;
for (; V_101 > 0 ; ( -- V_101 , ++ V_100 ) ) {
if ( * V_100 == 0 )
V_102 = 1 ;
if ( V_102 || * V_100 < 0x20 || * V_100 > 0x7e )
* V_100 = ' ' ;
}
}
static int F_57 ( struct V_12 * V_13 , unsigned char * V_103 ,
int V_104 , int * V_105 )
{
unsigned char V_15 [ V_16 ] ;
int V_106 , V_107 , V_108 ;
int V_109 = 0 ;
int V_110 , V_111 , V_14 ;
struct V_112 V_113 ;
* V_105 = 0 ;
V_106 = V_13 -> V_114 ? V_13 -> V_114 : 36 ;
V_107 = V_106 ;
V_110 = 1 ;
V_115:
F_58 ( 3 , F_59 ( V_10 , V_13 ,
L_6 ,
V_110 , V_107 ) ) ;
for ( V_111 = 0 ; V_111 < 3 ; ++ V_111 ) {
int V_116 ;
memset ( V_15 , 0 , 6 ) ;
V_15 [ 0 ] = V_117 ;
V_15 [ 4 ] = ( unsigned char ) V_107 ;
memset ( V_103 , 0 , V_107 ) ;
V_14 = F_16 ( V_13 , V_15 , V_19 ,
V_103 , V_107 , & V_113 ,
V_118 / 2 + V_118 * V_119 , 3 ,
& V_116 ) ;
F_58 ( 3 , F_9 ( V_10 L_7
L_8 ,
V_14 ? L_9 : L_10 , V_14 ) ) ;
if ( V_14 ) {
if ( ( F_60 ( V_14 ) & V_120 ) &&
F_61 ( & V_113 ) ) {
if ( ( V_113 . V_121 == V_122 ) &&
( ( V_113 . V_123 == 0x28 ) ||
( V_113 . V_123 == 0x29 ) ) &&
( V_113 . V_124 == 0 ) )
continue;
}
} else {
if ( V_116 == V_107 )
continue;
}
break;
}
if ( V_14 == 0 ) {
F_56 ( & V_103 [ 8 ] , 8 ) ;
F_56 ( & V_103 [ 16 ] , 16 ) ;
F_56 ( & V_103 [ 32 ] , 4 ) ;
V_109 = V_103 [ 4 ] + 5 ;
if ( V_109 > 255 )
V_109 = V_106 ;
* V_105 = F_62 ( V_13 , & V_103 [ 8 ] ,
& V_103 [ 16 ] ) ;
if ( V_110 == 1 ) {
if ( V_125 & * V_105 )
V_108 = 36 ;
else if ( V_126 & * V_105 )
V_108 = 58 ;
else if ( V_13 -> V_114 )
V_108 = V_13 -> V_114 ;
else
V_108 = V_109 ;
if ( V_108 > V_107 ) {
V_107 = V_108 ;
V_110 = 2 ;
goto V_115;
}
}
} else if ( V_110 == 2 ) {
F_9 ( V_10 L_11
L_12 ,
V_107 ) ;
V_107 = V_106 ;
V_110 = 3 ;
goto V_115;
}
if ( V_14 )
return - V_127 ;
V_13 -> V_114 = F_63 ( V_107 , V_109 ) ;
if ( V_13 -> V_114 < 36 ) {
F_9 ( V_10 L_13
L_14 , V_13 -> V_114 ) ;
V_13 -> V_114 = 36 ;
}
V_13 -> V_92 = V_103 [ 2 ] & 0x07 ;
if ( V_13 -> V_92 >= 2 ||
( V_13 -> V_92 == 1 && ( V_103 [ 3 ] & 0x0f ) == 1 ) )
V_13 -> V_92 ++ ;
V_13 -> V_58 -> V_92 = V_13 -> V_92 ;
return 0 ;
}
static int F_64 ( struct V_12 * V_13 , unsigned char * V_103 ,
int * V_105 , int V_128 )
{
int V_26 ;
V_13 -> V_129 = F_65 ( V_103 ,
F_66 ( V_130 , V_13 -> V_114 , 36 ) ,
V_36 ) ;
if ( V_13 -> V_129 == NULL )
return V_131 ;
V_13 -> V_38 = ( char * ) ( V_13 -> V_129 + 8 ) ;
V_13 -> V_40 = ( char * ) ( V_13 -> V_129 + 16 ) ;
V_13 -> V_41 = ( char * ) ( V_13 -> V_129 + 32 ) ;
if ( strncmp ( V_13 -> V_38 , L_15 , 8 ) == 0 ) {
V_13 -> V_132 = 1 ;
}
if ( * V_105 & V_133 ) {
V_13 -> type = V_134 ;
V_13 -> V_135 = 1 ;
} else {
V_13 -> type = ( V_103 [ 0 ] & 0x1f ) ;
V_13 -> V_135 = ( V_103 [ 1 ] & 0x80 ) >> 7 ;
}
switch ( V_13 -> type ) {
case V_136 :
case V_137 :
case V_138 :
case V_139 :
case V_140 :
case V_141 :
case V_142 :
case V_143 :
case V_144 :
case V_145 :
case V_146 :
case V_147 :
V_13 -> V_148 = 1 ;
break;
case V_134 :
case V_149 :
V_13 -> V_148 = 0 ;
break;
default:
F_9 ( V_10 L_16 , V_13 -> type ) ;
}
if ( V_13 -> type == V_136 || V_13 -> type == V_134 ) {
if ( ( * V_105 & V_150 ) == 0 )
* V_105 |= V_151 ;
}
V_13 -> V_152 = ( V_103 [ 0 ] >> 5 ) & 7 ;
V_13 -> V_153 = V_13 -> V_135 ;
V_13 -> V_154 = ( V_103 [ 7 ] & 1 ) && ( ( V_103 [ 3 ] & 7 ) == 2 ) ;
if ( V_13 -> V_92 >= V_155 ||
( V_13 -> V_114 > 56 && V_103 [ 56 ] & 0x04 ) )
V_13 -> V_156 = 1 ;
if ( V_103 [ 7 ] & 0x60 )
V_13 -> V_157 = 1 ;
if ( V_103 [ 7 ] & 0x10 )
V_13 -> V_158 = 1 ;
F_59 ( V_17 , V_13 , L_17
L_18 , F_67 ( V_13 -> type ) ,
V_13 -> V_38 , V_13 -> V_40 , V_13 -> V_41 ,
V_13 -> V_152 , V_103 [ 2 ] & 0x07 ,
( V_103 [ 3 ] & 0x0f ) == 1 ? L_19 : L_20 ) ;
if ( ( V_13 -> V_92 >= V_93 ) && ( V_103 [ 7 ] & 2 ) &&
! ( * V_105 & V_159 ) )
V_13 -> V_160 = 1 ;
if ( ( * V_105 & V_161 ) == 0 )
V_13 -> V_61 = 0 ;
if ( * V_105 & V_162 )
V_13 -> V_163 = 1 ;
if ( * V_105 & V_164 )
V_13 -> V_165 = 1 ;
if ( * V_105 & V_166 )
F_68 ( V_13 -> V_62 , 512 ) ;
if ( * V_105 & V_167 )
V_13 -> V_168 = 1 ;
if ( * V_105 & V_169 )
V_21 ( V_13 ) -> V_170 = 1 ;
V_13 -> V_171 = 1 ;
if ( * V_105 & V_172 )
V_13 -> V_173 = 1 ;
if ( * V_105 & V_174 )
V_13 -> V_175 = 1 ;
if ( * V_105 & V_176 )
V_13 -> V_177 = 1 ;
V_26 = F_69 ( V_13 , V_178 ) ;
if ( V_26 ) {
V_26 = F_69 ( V_13 , V_179 ) ;
if ( V_26 ) {
F_59 ( V_86 , V_13 ,
L_21 ,
F_70 ( V_13 -> V_47 ) ) ;
return V_131 ;
}
}
if ( * V_105 & V_180 )
V_13 -> V_181 = 1 ;
if ( * V_105 & V_182 )
V_13 -> V_153 = 0 ;
if ( * V_105 & V_183 )
V_13 -> V_184 = 1 ;
if ( * V_105 & V_185 )
V_13 -> V_186 = 1 ;
V_13 -> V_187 = V_188 ;
if ( * V_105 & V_189 )
V_13 -> V_190 = 1 ;
F_71 ( & V_13 -> V_57 ) ;
if ( V_13 -> V_42 -> V_65 -> V_191 ) {
V_26 = V_13 -> V_42 -> V_65 -> V_191 ( V_13 ) ;
if ( V_26 ) {
if ( V_26 != - V_67 ) {
F_59 ( V_86 , V_13 ,
L_22 ) ;
}
return V_131 ;
}
}
if ( V_13 -> V_92 >= V_155 )
F_72 ( V_13 ) ;
V_13 -> V_192 = V_13 -> V_193 ;
if ( ! V_128 && F_73 ( V_13 ) != 0 )
return V_131 ;
return V_194 ;
}
static unsigned char * F_74 ( unsigned char * V_195 , unsigned char * V_196 ,
unsigned V_197 , unsigned V_198 )
{
unsigned V_199 = 0 , V_200 ;
for ( V_200 = 0 ; V_200 + V_197 < V_198 && V_200 + V_197 < V_196 [ 4 ] + 5 ; V_200 ++ ) {
if ( V_196 [ V_200 + V_197 ] > ' ' ) {
V_195 [ V_200 ] = V_196 [ V_200 + V_197 ] ;
V_199 = V_200 + 1 ;
} else {
V_195 [ V_200 ] = ' ' ;
}
}
V_195 [ V_199 ] = 0 ;
return V_195 ;
}
static int F_75 ( struct V_21 * V_22 ,
T_1 V_23 , int * V_201 ,
struct V_12 * * V_202 , int V_203 ,
void * V_24 )
{
struct V_12 * V_13 ;
unsigned char * V_14 ;
int V_105 , V_204 = V_131 , V_104 = 256 ;
struct V_27 * V_5 = F_18 ( V_22 -> V_28 . V_29 ) ;
V_13 = F_76 ( V_22 , V_23 ) ;
if ( V_13 ) {
if ( V_203 || ! F_77 ( V_13 ) ) {
F_58 ( 3 , F_9 ( V_10
L_23 ,
F_78 ( & V_13 -> V_57 ) ) ) ;
if ( V_202 )
* V_202 = V_13 ;
else
F_79 ( V_13 ) ;
if ( V_201 )
* V_201 = F_62 ( V_13 ,
V_13 -> V_38 ,
V_13 -> V_40 ) ;
return V_194 ;
}
F_79 ( V_13 ) ;
} else
V_13 = F_17 ( V_22 , V_23 , V_24 ) ;
if ( ! V_13 )
goto V_37;
V_14 = F_3 ( V_104 , V_36 |
( ( V_5 -> V_205 ) ? V_206 : 0 ) ) ;
if ( ! V_14 )
goto V_207;
if ( F_57 ( V_13 , V_14 , V_104 , & V_105 ) )
goto V_208;
if ( V_201 )
* V_201 = V_105 ;
if ( ( ( V_14 [ 0 ] >> 5 ) == 3 ) && ! ( V_105 & V_209 ) ) {
F_58 ( 2 , sdev_printk(KERN_INFO, sdev, L_24
L_25
L_26))
if ( V_23 == 0 ) {
F_58 ( 1 , {
unsigned char vend[9];
unsigned char mod[17];
sdev_printk(KERN_INFO, sdev,
L_27
L_28,
scsi_inq_str(vend, result, 8, 16),
scsi_inq_str(mod, result, 16, 32));
}) ;
}
V_204 = V_210 ;
goto V_208;
}
if ( ( ( V_14 [ 0 ] >> 5 ) == 1 || V_22 -> V_211 ) &&
( V_14 [ 0 ] & 0x1f ) == 0x1f &&
! F_80 ( V_23 ) ) {
F_58 ( 3 , F_9 ( V_10
L_29
L_30 ) ) ;
V_204 = V_210 ;
goto V_208;
}
V_204 = F_64 ( V_13 , V_14 , & V_105 , V_5 -> V_212 ) ;
if ( V_204 == V_194 ) {
if ( V_105 & V_213 ) {
V_13 -> V_153 = 0 ;
F_15 ( V_13 , V_14 ) ;
}
}
V_208:
F_14 ( V_14 ) ;
V_207:
if ( V_204 == V_194 ) {
if ( V_202 ) {
if ( F_81 ( V_13 ) == 0 ) {
* V_202 = V_13 ;
} else {
F_30 ( V_13 ) ;
V_204 = V_131 ;
}
}
} else
F_30 ( V_13 ) ;
V_37:
return V_204 ;
}
static void F_82 ( struct V_21 * V_22 ,
int V_105 , int V_92 , int V_203 )
{
unsigned int V_214 , V_23 , V_215 ;
struct V_27 * V_5 = F_18 ( V_22 -> V_28 . V_29 ) ;
F_58 ( 3 , F_9 ( V_10 L_31
L_32 , F_78 ( & V_22 -> V_28 ) ) ) ;
V_215 = F_63 ( V_216 , V_5 -> V_217 ) ;
if ( V_105 & V_218 ) {
V_215 = V_5 -> V_217 ;
V_214 = 1 ;
} else
V_214 = 0 ;
if ( V_105 & V_219 )
V_215 = V_5 -> V_217 ;
if ( V_105 & V_220 )
V_215 = F_63 ( 5U , V_215 ) ;
if ( V_92 < V_155 && ! ( V_105 & V_221 ) )
V_215 = F_63 ( 8U , V_215 ) ;
for ( V_23 = 1 ; V_23 < V_215 ; ++ V_23 )
if ( ( F_75 ( V_22 , V_23 , NULL , NULL , V_203 ,
NULL ) != V_194 ) &&
! V_214 )
return;
}
int F_83 ( struct V_222 * V_223 )
{
int V_224 ;
unsigned int V_23 ;
V_23 = 0 ;
for ( V_224 = 0 ; V_224 < sizeof( V_23 ) ; V_224 += 2 )
V_23 = V_23 | ( ( ( V_223 -> V_222 [ V_224 ] << 8 ) |
V_223 -> V_222 [ V_224 + 1 ] ) << ( V_224 * 8 ) ) ;
return V_23 ;
}
void F_84 ( unsigned int V_23 , struct V_222 * V_223 )
{
int V_224 ;
memset ( V_223 -> V_222 , 0 , sizeof( V_223 -> V_222 ) ) ;
for ( V_224 = 0 ; V_224 < sizeof( V_23 ) ; V_224 += 2 ) {
V_223 -> V_222 [ V_224 ] = ( V_23 >> 8 ) & 0xFF ;
V_223 -> V_222 [ V_224 + 1 ] = V_23 & 0xFF ;
V_23 = V_23 >> 16 ;
}
}
static int F_85 ( struct V_21 * V_22 , int V_105 ,
int V_203 )
{
char V_225 [ 64 ] ;
unsigned char V_15 [ V_16 ] ;
unsigned int V_226 ;
unsigned int V_23 ;
unsigned int V_227 ;
unsigned int V_228 ;
int V_14 ;
struct V_222 * V_229 , * V_230 ;
T_2 * V_2 ;
struct V_112 V_113 ;
struct V_12 * V_13 ;
struct V_27 * V_5 = F_18 ( & V_22 -> V_28 ) ;
int V_26 = 0 ;
if ( V_105 & V_151 )
return 1 ;
if ( V_22 -> V_92 < V_93 &&
V_22 -> V_92 != V_231 )
return 1 ;
if ( V_22 -> V_92 < V_155 &&
( ! ( V_105 & V_150 ) || V_5 -> V_217 <= 8 ) )
return 1 ;
if ( V_105 & V_232 )
return 0 ;
if ( V_22 -> V_233 )
return 1 ;
if ( ! ( V_13 = F_76 ( V_22 , 0 ) ) ) {
V_13 = F_17 ( V_22 , 0 , NULL ) ;
if ( ! V_13 )
return 0 ;
if ( F_81 ( V_13 ) ) {
F_30 ( V_13 ) ;
return 0 ;
}
}
sprintf ( V_225 , L_33 ,
V_5 -> V_87 , V_13 -> V_46 , V_13 -> V_45 ) ;
V_226 = ( V_234 + 1 ) * sizeof( struct V_222 ) ;
V_230 = F_3 ( V_226 , V_36 |
( V_13 -> V_42 -> V_205 ? V_206 : 0 ) ) ;
if ( ! V_230 ) {
F_9 ( V_69 , V_70 ) ;
goto V_37;
}
V_15 [ 0 ] = V_235 ;
memset ( & V_15 [ 1 ] , 0 , 5 ) ;
V_15 [ 6 ] = ( unsigned char ) ( V_226 >> 24 ) & 0xff ;
V_15 [ 7 ] = ( unsigned char ) ( V_226 >> 16 ) & 0xff ;
V_15 [ 8 ] = ( unsigned char ) ( V_226 >> 8 ) & 0xff ;
V_15 [ 9 ] = ( unsigned char ) V_226 & 0xff ;
V_15 [ 10 ] = 0 ;
V_15 [ 11 ] = 0 ;
for ( V_228 = 0 ; V_228 < 3 ; V_228 ++ ) {
F_58 ( 3 , F_9 ( V_10 L_34
L_35 , V_225 ,
V_228 ) ) ;
V_14 = F_16 ( V_13 , V_15 , V_19 ,
V_230 , V_226 , & V_113 ,
V_20 + 4 * V_118 , 3 , NULL ) ;
F_58 ( 3 , F_9 ( V_10 L_36
L_37 , V_14
? L_9 : L_10 , V_228 , V_14 ) ) ;
if ( V_14 == 0 )
break;
else if ( F_61 ( & V_113 ) ) {
if ( V_113 . V_121 != V_122 )
break;
}
}
if ( V_14 ) {
V_26 = 1 ;
goto V_236;
}
V_2 = ( T_2 * ) V_230 -> V_222 ;
V_226 = ( ( V_2 [ 0 ] << 24 ) | ( V_2 [ 1 ] << 16 ) |
( V_2 [ 2 ] << 8 ) | ( V_2 [ 3 ] << 0 ) ) ;
V_227 = ( V_226 / sizeof( struct V_222 ) ) ;
if ( V_227 > V_234 ) {
F_9 ( V_237 L_38
L_39
L_40 , V_225 ,
V_234 , V_227 ) ;
V_227 = V_234 ;
}
F_58 ( 3 , F_59 ( V_10 , V_13 ,
L_41 ) ) ;
for ( V_229 = & V_230 [ 1 ] ; V_229 <= & V_230 [ V_227 ] ; V_229 ++ ) {
V_23 = F_83 ( V_229 ) ;
if ( memcmp ( & V_229 -> V_222 [ sizeof( V_23 ) ] , L_42 , 4 ) ) {
int V_224 ;
F_9 ( V_237 L_43 , V_225 ) ;
V_2 = ( char * ) V_229 -> V_222 ;
for ( V_224 = 0 ; V_224 < sizeof( struct V_222 ) ; V_224 ++ )
F_9 ( L_44 , V_2 [ V_224 ] ) ;
F_9 ( L_45 ) ;
} else if ( V_23 > V_13 -> V_42 -> V_217 ) {
F_9 ( V_237 L_46
L_47 ,
V_225 , V_23 ) ;
} else {
int V_204 ;
V_204 = F_75 ( V_22 ,
V_23 , NULL , NULL , V_203 , NULL ) ;
if ( V_204 == V_131 ) {
F_59 ( V_86 , V_13 ,
L_48
L_49
L_50 , V_23 ) ;
break;
}
}
}
V_236:
F_14 ( V_230 ) ;
V_37:
F_79 ( V_13 ) ;
if ( F_77 ( V_13 ) )
F_30 ( V_13 ) ;
return V_26 ;
}
struct V_12 * F_86 ( struct V_27 * V_5 , T_1 V_46 ,
T_1 V_45 , T_1 V_23 , void * V_24 )
{
struct V_12 * V_13 = F_87 ( - V_238 ) ;
struct V_71 * V_29 = & V_5 -> V_239 ;
struct V_21 * V_22 ;
if ( strncmp ( V_240 , L_51 , 4 ) == 0 )
return F_87 ( - V_238 ) ;
V_22 = F_47 ( V_29 , V_46 , V_45 ) ;
if ( ! V_22 )
return F_87 ( - V_241 ) ;
F_88 ( V_22 ) ;
F_89 ( & V_5 -> V_242 ) ;
if ( ! V_5 -> V_212 )
F_1 () ;
if ( F_90 ( V_5 ) && F_91 ( V_5 ) == 0 ) {
F_75 ( V_22 , V_23 , NULL , & V_13 , 1 , V_24 ) ;
F_92 ( V_5 ) ;
}
F_93 ( & V_5 -> V_242 ) ;
F_94 ( V_22 ) ;
F_54 ( V_22 ) ;
F_25 ( & V_22 -> V_28 ) ;
return V_13 ;
}
int F_95 ( struct V_27 * V_42 , T_1 V_46 ,
T_1 V_243 , T_1 V_23 )
{
struct V_12 * V_13 =
F_86 ( V_42 , V_46 , V_243 , V_23 , NULL ) ;
if ( F_96 ( V_13 ) )
return F_97 ( V_13 ) ;
F_79 ( V_13 ) ;
return 0 ;
}
void F_98 ( struct V_71 * V_28 )
{
struct V_244 * V_245 ;
if ( ! V_28 -> V_246 )
return;
V_245 = F_99 ( V_28 -> V_246 ) ;
if ( F_100 ( V_245 -> V_247 ) ) {
if ( V_245 -> V_203 )
V_245 -> V_203 ( V_28 ) ;
F_101 ( V_245 -> V_247 ) ;
}
}
static void F_102 ( struct V_71 * V_29 , unsigned int V_46 ,
unsigned int V_45 , unsigned int V_23 , int V_203 )
{
struct V_27 * V_5 = F_18 ( V_29 ) ;
int V_105 = 0 ;
int V_204 ;
struct V_21 * V_22 ;
if ( V_5 -> V_248 == V_45 )
return;
V_22 = F_47 ( V_29 , V_46 , V_45 ) ;
if ( ! V_22 )
return;
F_88 ( V_22 ) ;
if ( V_23 != V_249 ) {
F_75 ( V_22 , V_23 , NULL , NULL , V_203 , NULL ) ;
goto V_250;
}
V_204 = F_75 ( V_22 , 0 , & V_105 , NULL , V_203 , NULL ) ;
if ( V_204 == V_194 || V_204 == V_210 ) {
if ( F_85 ( V_22 , V_105 , V_203 ) != 0 )
F_82 ( V_22 , V_105 ,
V_22 -> V_92 , V_203 ) ;
}
V_250:
F_94 ( V_22 ) ;
F_54 ( V_22 ) ;
F_25 ( & V_22 -> V_28 ) ;
}
void F_103 ( struct V_71 * V_29 , unsigned int V_46 ,
unsigned int V_45 , unsigned int V_23 , int V_203 )
{
struct V_27 * V_5 = F_18 ( V_29 ) ;
if ( strncmp ( V_240 , L_51 , 4 ) == 0 )
return;
F_89 ( & V_5 -> V_242 ) ;
if ( ! V_5 -> V_212 )
F_1 () ;
if ( F_90 ( V_5 ) && F_91 ( V_5 ) == 0 ) {
F_102 ( V_29 , V_46 , V_45 , V_23 , V_203 ) ;
F_92 ( V_5 ) ;
}
F_93 ( & V_5 -> V_242 ) ;
}
static void F_104 ( struct V_27 * V_5 , unsigned int V_46 ,
unsigned int V_45 , unsigned int V_23 , int V_203 )
{
T_1 V_251 ;
if ( V_45 == V_249 )
for ( V_45 = 0 ; V_45 < V_5 -> V_252 ; ++ V_45 ) {
if ( V_5 -> V_253 )
V_251 = V_5 -> V_252 - V_45 - 1 ;
else
V_251 = V_45 ;
F_102 ( & V_5 -> V_239 , V_46 ,
V_251 , V_23 , V_203 ) ;
}
else
F_102 ( & V_5 -> V_239 , V_46 ,
V_45 , V_23 , V_203 ) ;
}
int F_105 ( struct V_27 * V_5 , unsigned int V_46 ,
unsigned int V_45 , unsigned int V_23 , int V_203 )
{
F_58 ( 3 , F_106 ( V_10 , V_5 ,
L_52 ,
V_70 , V_46 , V_45 , V_23 ) ) ;
if ( ( ( V_46 != V_249 ) && ( V_46 > V_5 -> V_254 ) ) ||
( ( V_45 != V_249 ) && ( V_45 >= V_5 -> V_252 ) ) ||
( ( V_23 != V_249 ) && ( V_23 > V_5 -> V_217 ) ) )
return - V_255 ;
F_89 ( & V_5 -> V_242 ) ;
if ( ! V_5 -> V_212 )
F_1 () ;
if ( F_90 ( V_5 ) && F_91 ( V_5 ) == 0 ) {
if ( V_46 == V_249 )
for ( V_46 = 0 ; V_46 <= V_5 -> V_254 ;
V_46 ++ )
F_104 ( V_5 , V_46 , V_45 , V_23 ,
V_203 ) ;
else
F_104 ( V_5 , V_46 , V_45 , V_23 , V_203 ) ;
F_92 ( V_5 ) ;
}
F_93 ( & V_5 -> V_242 ) ;
return 0 ;
}
static void F_107 ( struct V_27 * V_5 )
{
struct V_12 * V_13 ;
F_108 (sdev, shost) {
if ( V_13 -> V_47 == V_256 )
continue;
if ( ! F_90 ( V_5 ) ||
F_73 ( V_13 ) != 0 )
F_30 ( V_13 ) ;
}
}
static struct V_1 * F_109 ( struct V_27 * V_5 )
{
struct V_1 * V_2 ;
unsigned long V_72 ;
if ( strncmp ( V_240 , L_53 , 4 ) == 0 )
return NULL ;
if ( V_5 -> V_212 ) {
F_9 ( L_54 , V_70 ,
V_5 -> V_87 ) ;
F_110 () ;
return NULL ;
}
V_2 = F_3 ( sizeof( * V_2 ) , V_4 ) ;
if ( ! V_2 )
goto V_257;
V_2 -> V_5 = F_111 ( V_5 ) ;
if ( ! V_2 -> V_5 )
goto V_257;
F_5 ( & V_2 -> V_6 ) ;
F_89 ( & V_5 -> V_242 ) ;
F_33 ( V_5 -> V_75 , V_72 ) ;
V_5 -> V_212 = 1 ;
F_35 ( V_5 -> V_75 , V_72 ) ;
F_93 ( & V_5 -> V_242 ) ;
F_6 ( & V_7 ) ;
if ( F_2 ( & V_3 ) )
F_13 ( & V_2 -> V_6 ) ;
F_7 ( & V_2 -> V_9 , & V_3 ) ;
F_8 ( & V_7 ) ;
return V_2 ;
V_257:
F_14 ( V_2 ) ;
return NULL ;
}
static void F_112 ( struct V_1 * V_2 )
{
struct V_27 * V_5 ;
unsigned long V_72 ;
if ( ! V_2 )
return;
V_5 = V_2 -> V_5 ;
F_89 ( & V_5 -> V_242 ) ;
if ( ! V_5 -> V_212 ) {
F_9 ( L_54 , V_70 ,
V_5 -> V_87 ) ;
F_110 () ;
F_93 ( & V_5 -> V_242 ) ;
return;
}
F_10 ( & V_2 -> V_6 ) ;
F_107 ( V_5 ) ;
F_33 ( V_5 -> V_75 , V_72 ) ;
V_5 -> V_212 = 0 ;
F_35 ( V_5 -> V_75 , V_72 ) ;
F_93 ( & V_5 -> V_242 ) ;
F_6 ( & V_7 ) ;
F_11 ( & V_2 -> V_9 ) ;
if ( ! F_2 ( & V_3 ) ) {
struct V_1 * V_11 = F_12 ( V_3 . V_11 ,
struct V_1 , V_9 ) ;
F_13 ( & V_11 -> V_6 ) ;
}
F_8 ( & V_7 ) ;
F_92 ( V_5 ) ;
F_113 ( V_5 ) ;
F_14 ( V_2 ) ;
}
static void F_114 ( struct V_27 * V_5 )
{
if ( V_5 -> V_65 -> V_258 ) {
unsigned long V_259 = V_260 ;
if ( V_5 -> V_65 -> V_261 )
V_5 -> V_65 -> V_261 ( V_5 ) ;
while ( ! V_5 -> V_65 -> V_258 ( V_5 , V_260 - V_259 ) )
F_4 ( 10 ) ;
} else {
F_105 ( V_5 , V_249 , V_249 ,
V_249 , 0 ) ;
}
}
static void F_115 ( void * V_262 , T_3 V_263 )
{
struct V_1 * V_2 = V_262 ;
struct V_27 * V_5 = V_2 -> V_5 ;
F_114 ( V_5 ) ;
F_112 ( V_2 ) ;
}
void F_116 ( struct V_27 * V_5 )
{
struct V_1 * V_2 ;
if ( strncmp ( V_240 , L_51 , 4 ) == 0 )
return;
if ( F_91 ( V_5 ) < 0 )
return;
V_2 = F_109 ( V_5 ) ;
if ( ! V_2 ) {
F_114 ( V_5 ) ;
F_92 ( V_5 ) ;
return;
}
F_117 ( F_115 , V_2 ) ;
}
void F_118 ( struct V_27 * V_5 )
{
struct V_12 * V_13 ;
unsigned long V_72 ;
V_264:
F_33 ( V_5 -> V_75 , V_72 ) ;
F_40 (sdev, &shost->__devices, siblings) {
if ( V_13 -> V_47 == V_256 )
continue;
F_35 ( V_5 -> V_75 , V_72 ) ;
F_30 ( V_13 ) ;
goto V_264;
}
F_35 ( V_5 -> V_75 , V_72 ) ;
}
struct V_12 * F_119 ( struct V_27 * V_5 )
{
struct V_12 * V_13 = NULL ;
struct V_21 * V_22 ;
F_89 ( & V_5 -> V_242 ) ;
if ( ! F_90 ( V_5 ) )
goto V_37;
V_22 = F_47 ( & V_5 -> V_239 , 0 , V_5 -> V_248 ) ;
if ( ! V_22 )
goto V_37;
V_13 = F_17 ( V_22 , 0 , NULL ) ;
if ( V_13 )
V_13 -> V_61 = 0 ;
else
F_54 ( V_22 ) ;
F_25 ( & V_22 -> V_28 ) ;
V_37:
F_93 ( & V_5 -> V_242 ) ;
return V_13 ;
}
void F_120 ( struct V_12 * V_13 )
{
F_55 ( V_13 -> V_45 != V_13 -> V_42 -> V_248 ) ;
F_30 ( V_13 ) ;
}
