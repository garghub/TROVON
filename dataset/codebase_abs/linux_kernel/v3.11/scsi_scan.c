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
F_32 ( V_28 ) ;
F_33 ( V_5 -> V_73 , V_72 ) ;
if ( V_5 -> V_65 -> V_74 )
V_5 -> V_65 -> V_74 ( V_22 ) ;
F_34 ( & V_22 -> V_49 ) ;
F_35 ( V_5 -> V_73 , V_72 ) ;
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
return V_28 -> type == & V_75 ;
}
static struct V_21 * F_39 ( struct V_71 * V_29 ,
int V_46 , T_1 V_45 )
{
struct V_21 * V_22 , * V_76 = NULL ;
struct V_27 * V_5 = F_18 ( V_29 ) ;
F_40 (starget, &shost->__targets, siblings) {
if ( V_22 -> V_45 == V_45 &&
V_22 -> V_46 == V_46 ) {
V_76 = V_22 ;
break;
}
}
if ( V_76 )
F_23 ( & V_76 -> V_28 ) ;
return V_76 ;
}
static struct V_21 * F_41 ( struct V_71 * V_29 ,
int V_46 , T_1 V_45 )
{
struct V_27 * V_5 = F_18 ( V_29 ) ;
struct V_71 * V_28 = NULL ;
unsigned long V_72 ;
const int V_77 = sizeof( struct V_21 )
+ V_5 -> V_34 -> V_78 ;
struct V_21 * V_22 ;
struct V_21 * V_79 ;
int error ;
V_22 = F_19 ( V_77 , V_4 ) ;
if ( ! V_22 ) {
F_9 ( V_80 L_3 , V_70 ) ;
return NULL ;
}
V_28 = & V_22 -> V_28 ;
F_42 ( V_28 ) ;
V_22 -> V_81 = 1 ;
V_28 -> V_29 = F_23 ( V_29 ) ;
F_43 ( V_28 , L_4 , V_5 -> V_82 , V_46 , V_45 ) ;
V_28 -> V_83 = & V_84 ;
V_28 -> type = & V_75 ;
V_22 -> V_45 = V_45 ;
V_22 -> V_46 = V_46 ;
V_22 -> V_85 = 0 ;
F_20 ( & V_22 -> V_49 ) ;
F_20 ( & V_22 -> V_86 ) ;
V_22 -> V_87 = V_88 ;
V_22 -> V_89 = V_90 ;
V_22 -> V_91 = V_92 ;
V_93:
F_33 ( V_5 -> V_73 , V_72 ) ;
V_79 = F_39 ( V_29 , V_46 , V_45 ) ;
if ( V_79 )
goto V_94;
F_7 ( & V_22 -> V_49 , & V_5 -> V_95 ) ;
F_35 ( V_5 -> V_73 , V_72 ) ;
F_44 ( V_28 ) ;
if ( V_5 -> V_65 -> V_96 ) {
error = V_5 -> V_65 -> V_96 ( V_22 ) ;
if( error ) {
F_45 ( V_80 , V_28 , L_5 , error ) ;
F_31 ( V_22 ) ;
return NULL ;
}
}
F_23 ( V_28 ) ;
return V_22 ;
V_94:
V_79 -> V_81 ++ ;
F_35 ( V_5 -> V_73 , V_72 ) ;
if ( V_79 -> V_87 != V_97 ) {
F_25 ( V_28 ) ;
return V_79 ;
}
F_25 ( & V_79 -> V_28 ) ;
F_46 () ;
goto V_93;
}
static void F_47 ( struct V_31 * V_32 )
{
struct V_21 * V_22 =
F_48 ( V_32 , struct V_21 , V_98 . V_32 ) ;
F_49 ( & V_22 -> V_28 ) ;
F_50 ( & V_22 -> V_28 ) ;
F_31 ( V_22 ) ;
}
void F_51 ( struct V_21 * V_22 )
{
struct V_27 * V_5 = F_18 ( V_22 -> V_28 . V_29 ) ;
unsigned long V_72 ;
enum V_99 V_87 ;
int V_100 = 0 ;
F_33 ( V_5 -> V_73 , V_72 ) ;
V_87 = V_22 -> V_87 ;
if ( -- V_22 -> V_81 == 0 && F_2 ( & V_22 -> V_86 ) ) {
V_100 = 1 ;
V_22 -> V_87 = V_97 ;
}
F_35 ( V_5 -> V_73 , V_72 ) ;
if ( ! V_100 )
return;
F_52 ( V_87 == V_97 ) ;
if ( V_87 == V_88 )
F_31 ( V_22 ) ;
else
F_53 ( F_47 ,
& V_22 -> V_98 ) ;
}
static void F_54 ( unsigned char * V_101 , int V_102 )
{
int V_103 = 0 ;
for (; V_102 > 0 ; ( -- V_102 , ++ V_101 ) ) {
if ( * V_101 == 0 )
V_103 = 1 ;
if ( V_103 || * V_101 < 0x20 || * V_101 > 0x7e )
* V_101 = ' ' ;
}
}
static int F_55 ( struct V_12 * V_13 , unsigned char * V_104 ,
int V_105 , int * V_106 )
{
unsigned char V_15 [ V_16 ] ;
int V_107 , V_108 , V_109 ;
int V_110 = 0 ;
int V_111 , V_112 , V_14 ;
struct V_113 V_114 ;
* V_106 = 0 ;
V_107 = V_13 -> V_115 ? V_13 -> V_115 : 36 ;
V_108 = V_107 ;
V_111 = 1 ;
V_116:
F_56 ( 3 , F_57 ( V_10 , V_13 ,
L_6 ,
V_111 , V_108 ) ) ;
for ( V_112 = 0 ; V_112 < 3 ; ++ V_112 ) {
int V_117 ;
memset ( V_15 , 0 , 6 ) ;
V_15 [ 0 ] = V_118 ;
V_15 [ 4 ] = ( unsigned char ) V_108 ;
memset ( V_104 , 0 , V_108 ) ;
V_14 = F_16 ( V_13 , V_15 , V_19 ,
V_104 , V_108 , & V_114 ,
V_119 / 2 + V_119 * V_120 , 3 ,
& V_117 ) ;
F_56 ( 3 , F_9 ( V_10 L_7
L_8 ,
V_14 ? L_9 : L_10 , V_14 ) ) ;
if ( V_14 ) {
if ( ( F_58 ( V_14 ) & V_121 ) &&
F_59 ( & V_114 ) ) {
if ( ( V_114 . V_122 == V_123 ) &&
( ( V_114 . V_124 == 0x28 ) ||
( V_114 . V_124 == 0x29 ) ) &&
( V_114 . V_125 == 0 ) )
continue;
}
} else {
if ( V_117 == V_108 )
continue;
}
break;
}
if ( V_14 == 0 ) {
F_54 ( & V_104 [ 8 ] , 8 ) ;
F_54 ( & V_104 [ 16 ] , 16 ) ;
F_54 ( & V_104 [ 32 ] , 4 ) ;
V_110 = V_104 [ 4 ] + 5 ;
if ( V_110 > 255 )
V_110 = V_107 ;
* V_106 = F_60 ( V_13 , & V_104 [ 8 ] ,
& V_104 [ 16 ] ) ;
if ( V_111 == 1 ) {
if ( V_126 & * V_106 )
V_109 = 36 ;
else if ( V_127 & * V_106 )
V_109 = 58 ;
else if ( V_13 -> V_115 )
V_109 = V_13 -> V_115 ;
else
V_109 = V_110 ;
if ( V_109 > V_108 ) {
V_108 = V_109 ;
V_111 = 2 ;
goto V_116;
}
}
} else if ( V_111 == 2 ) {
F_9 ( V_10 L_11
L_12 ,
V_108 ) ;
V_108 = V_107 ;
V_111 = 3 ;
goto V_116;
}
if ( V_14 )
return - V_128 ;
V_13 -> V_115 = F_61 ( V_108 , V_110 ) ;
if ( V_13 -> V_115 < 36 ) {
F_9 ( V_10 L_13
L_14 , V_13 -> V_115 ) ;
V_13 -> V_115 = 36 ;
}
V_13 -> V_89 = V_104 [ 2 ] & 0x07 ;
if ( V_13 -> V_89 >= 2 ||
( V_13 -> V_89 == 1 && ( V_104 [ 3 ] & 0x0f ) == 1 ) )
V_13 -> V_89 ++ ;
V_13 -> V_58 -> V_89 = V_13 -> V_89 ;
return 0 ;
}
static int F_62 ( struct V_12 * V_13 , unsigned char * V_104 ,
int * V_106 , int V_129 )
{
int V_26 ;
V_13 -> V_130 = F_63 ( V_104 ,
F_64 ( V_131 , V_13 -> V_115 , 36 ) ,
V_36 ) ;
if ( V_13 -> V_130 == NULL )
return V_132 ;
V_13 -> V_38 = ( char * ) ( V_13 -> V_130 + 8 ) ;
V_13 -> V_40 = ( char * ) ( V_13 -> V_130 + 16 ) ;
V_13 -> V_41 = ( char * ) ( V_13 -> V_130 + 32 ) ;
if ( strncmp ( V_13 -> V_38 , L_15 , 8 ) == 0 ) {
V_13 -> V_133 = 1 ;
}
if ( * V_106 & V_134 ) {
V_13 -> type = V_135 ;
V_13 -> V_136 = 1 ;
} else {
V_13 -> type = ( V_104 [ 0 ] & 0x1f ) ;
V_13 -> V_136 = ( V_104 [ 1 ] & 0x80 ) >> 7 ;
}
switch ( V_13 -> type ) {
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
case V_148 :
V_13 -> V_149 = 1 ;
break;
case V_135 :
case V_150 :
V_13 -> V_149 = 0 ;
break;
default:
F_9 ( V_10 L_16 , V_13 -> type ) ;
}
if ( V_13 -> type == V_137 || V_13 -> type == V_135 ) {
if ( ( * V_106 & V_151 ) == 0 )
* V_106 |= V_152 ;
}
V_13 -> V_153 = ( V_104 [ 0 ] >> 5 ) & 7 ;
V_13 -> V_154 = V_13 -> V_136 ;
V_13 -> V_155 = ( V_104 [ 7 ] & 1 ) && ( ( V_104 [ 3 ] & 7 ) == 2 ) ;
if ( V_13 -> V_89 >= V_156 ||
( V_13 -> V_115 > 56 && V_104 [ 56 ] & 0x04 ) )
V_13 -> V_157 = 1 ;
if ( V_104 [ 7 ] & 0x60 )
V_13 -> V_158 = 1 ;
if ( V_104 [ 7 ] & 0x10 )
V_13 -> V_159 = 1 ;
F_57 ( V_17 , V_13 , L_17
L_18 , F_65 ( V_13 -> type ) ,
V_13 -> V_38 , V_13 -> V_40 , V_13 -> V_41 ,
V_13 -> V_153 , V_104 [ 2 ] & 0x07 ,
( V_104 [ 3 ] & 0x0f ) == 1 ? L_19 : L_20 ) ;
if ( ( V_13 -> V_89 >= V_90 ) && ( V_104 [ 7 ] & 2 ) &&
! ( * V_106 & V_160 ) )
V_13 -> V_161 = 1 ;
if ( ( * V_106 & V_162 ) == 0 )
V_13 -> V_61 = 0 ;
if ( * V_106 & V_163 )
V_13 -> V_164 = 1 ;
if ( * V_106 & V_165 )
V_13 -> V_166 = 1 ;
if ( * V_106 & V_167 )
F_66 ( V_13 -> V_62 , 512 ) ;
if ( * V_106 & V_168 )
V_13 -> V_169 = 1 ;
if ( * V_106 & V_170 )
V_21 ( V_13 ) -> V_171 = 1 ;
V_13 -> V_172 = 1 ;
if ( * V_106 & V_173 )
V_13 -> V_174 = 1 ;
if ( * V_106 & V_175 )
V_13 -> V_176 = 1 ;
if ( * V_106 & V_177 )
V_13 -> V_178 = 1 ;
V_26 = F_67 ( V_13 , V_179 ) ;
if ( V_26 ) {
V_26 = F_67 ( V_13 , V_180 ) ;
if ( V_26 ) {
F_57 ( V_80 , V_13 ,
L_21 ,
F_68 ( V_13 -> V_47 ) ) ;
return V_132 ;
}
}
if ( * V_106 & V_181 )
V_13 -> V_182 = 1 ;
if ( * V_106 & V_183 )
V_13 -> V_154 = 0 ;
if ( * V_106 & V_184 )
V_13 -> V_185 = 1 ;
if ( * V_106 & V_186 )
V_13 -> V_187 = 1 ;
V_13 -> V_188 = V_189 ;
if ( * V_106 & V_190 )
V_13 -> V_191 = 1 ;
F_69 ( & V_13 -> V_57 ) ;
if ( V_13 -> V_42 -> V_65 -> V_192 ) {
V_26 = V_13 -> V_42 -> V_65 -> V_192 ( V_13 ) ;
if ( V_26 ) {
if ( V_26 != - V_67 ) {
F_57 ( V_80 , V_13 ,
L_22 ) ;
}
return V_132 ;
}
}
V_13 -> V_193 = V_13 -> V_194 ;
if ( ! V_129 && F_70 ( V_13 ) != 0 )
return V_132 ;
return V_195 ;
}
static unsigned char * F_71 ( unsigned char * V_196 , unsigned char * V_197 ,
unsigned V_198 , unsigned V_199 )
{
unsigned V_200 = 0 , V_201 ;
for ( V_201 = 0 ; V_201 + V_198 < V_199 && V_201 + V_198 < V_197 [ 4 ] + 5 ; V_201 ++ ) {
if ( V_197 [ V_201 + V_198 ] > ' ' ) {
V_196 [ V_201 ] = V_197 [ V_201 + V_198 ] ;
V_200 = V_201 + 1 ;
} else {
V_196 [ V_201 ] = ' ' ;
}
}
V_196 [ V_200 ] = 0 ;
return V_196 ;
}
static int F_72 ( struct V_21 * V_22 ,
T_1 V_23 , int * V_202 ,
struct V_12 * * V_203 , int V_204 ,
void * V_24 )
{
struct V_12 * V_13 ;
unsigned char * V_14 ;
int V_106 , V_205 = V_132 , V_105 = 256 ;
struct V_27 * V_5 = F_18 ( V_22 -> V_28 . V_29 ) ;
V_13 = F_73 ( V_22 , V_23 ) ;
if ( V_13 ) {
if ( V_204 || ! F_74 ( V_13 ) ) {
F_56 ( 3 , F_9 ( V_10
L_23 ,
F_75 ( & V_13 -> V_57 ) ) ) ;
if ( V_203 )
* V_203 = V_13 ;
else
F_76 ( V_13 ) ;
if ( V_202 )
* V_202 = F_60 ( V_13 ,
V_13 -> V_38 ,
V_13 -> V_40 ) ;
return V_195 ;
}
F_76 ( V_13 ) ;
} else
V_13 = F_17 ( V_22 , V_23 , V_24 ) ;
if ( ! V_13 )
goto V_37;
V_14 = F_3 ( V_105 , V_36 |
( ( V_5 -> V_206 ) ? V_207 : 0 ) ) ;
if ( ! V_14 )
goto V_208;
if ( F_55 ( V_13 , V_14 , V_105 , & V_106 ) )
goto V_209;
if ( V_202 )
* V_202 = V_106 ;
if ( ( ( V_14 [ 0 ] >> 5 ) == 3 ) && ! ( V_106 & V_210 ) ) {
F_56 ( 2 , sdev_printk(KERN_INFO, sdev, L_24
L_25
L_26))
if ( V_23 == 0 ) {
F_56 ( 1 , {
unsigned char vend[9];
unsigned char mod[17];
sdev_printk(KERN_INFO, sdev,
L_27
L_28,
scsi_inq_str(vend, result, 8, 16),
scsi_inq_str(mod, result, 16, 32));
}) ;
}
V_205 = V_211 ;
goto V_209;
}
if ( ( ( V_14 [ 0 ] >> 5 ) == 1 || V_22 -> V_212 ) &&
( V_14 [ 0 ] & 0x1f ) == 0x1f &&
! F_77 ( V_23 ) ) {
F_56 ( 3 , F_9 ( V_10
L_29
L_30 ) ) ;
V_205 = V_211 ;
goto V_209;
}
V_205 = F_62 ( V_13 , V_14 , & V_106 , V_5 -> V_213 ) ;
if ( V_205 == V_195 ) {
if ( V_106 & V_214 ) {
V_13 -> V_154 = 0 ;
F_15 ( V_13 , V_14 ) ;
}
}
V_209:
F_14 ( V_14 ) ;
V_208:
if ( V_205 == V_195 ) {
if ( V_203 ) {
if ( F_78 ( V_13 ) == 0 ) {
* V_203 = V_13 ;
} else {
F_30 ( V_13 ) ;
V_205 = V_132 ;
}
}
} else
F_30 ( V_13 ) ;
V_37:
return V_205 ;
}
static void F_79 ( struct V_21 * V_22 ,
int V_106 , int V_89 , int V_204 )
{
unsigned int V_215 , V_23 , V_216 ;
struct V_27 * V_5 = F_18 ( V_22 -> V_28 . V_29 ) ;
F_56 ( 3 , F_9 ( V_10 L_31
L_32 , F_75 ( & V_22 -> V_28 ) ) ) ;
V_216 = F_61 ( V_217 , V_5 -> V_218 ) ;
if ( V_106 & V_219 ) {
V_216 = V_5 -> V_218 ;
V_215 = 1 ;
} else
V_215 = 0 ;
if ( V_106 & V_220 )
V_216 = V_5 -> V_218 ;
if ( V_106 & V_221 )
V_216 = F_61 ( 5U , V_216 ) ;
if ( V_89 < V_156 && ! ( V_106 & V_222 ) )
V_216 = F_61 ( 8U , V_216 ) ;
for ( V_23 = 1 ; V_23 < V_216 ; ++ V_23 )
if ( ( F_72 ( V_22 , V_23 , NULL , NULL , V_204 ,
NULL ) != V_195 ) &&
! V_215 )
return;
}
int F_80 ( struct V_223 * V_224 )
{
int V_225 ;
unsigned int V_23 ;
V_23 = 0 ;
for ( V_225 = 0 ; V_225 < sizeof( V_23 ) ; V_225 += 2 )
V_23 = V_23 | ( ( ( V_224 -> V_223 [ V_225 ] << 8 ) |
V_224 -> V_223 [ V_225 + 1 ] ) << ( V_225 * 8 ) ) ;
return V_23 ;
}
void F_81 ( unsigned int V_23 , struct V_223 * V_224 )
{
int V_225 ;
memset ( V_224 -> V_223 , 0 , sizeof( V_224 -> V_223 ) ) ;
for ( V_225 = 0 ; V_225 < sizeof( V_23 ) ; V_225 += 2 ) {
V_224 -> V_223 [ V_225 ] = ( V_23 >> 8 ) & 0xFF ;
V_224 -> V_223 [ V_225 + 1 ] = V_23 & 0xFF ;
V_23 = V_23 >> 16 ;
}
}
static int F_82 ( struct V_21 * V_22 , int V_106 ,
int V_204 )
{
char V_226 [ 64 ] ;
unsigned char V_15 [ V_16 ] ;
unsigned int V_227 ;
unsigned int V_23 ;
unsigned int V_228 ;
unsigned int V_229 ;
int V_14 ;
struct V_223 * V_230 , * V_231 ;
T_2 * V_2 ;
struct V_113 V_114 ;
struct V_12 * V_13 ;
struct V_27 * V_5 = F_18 ( & V_22 -> V_28 ) ;
int V_26 = 0 ;
if ( V_106 & V_152 )
return 1 ;
if ( V_22 -> V_89 < V_90 &&
V_22 -> V_89 != V_232 )
return 1 ;
if ( V_22 -> V_89 < V_156 &&
( ! ( V_106 & V_151 ) || V_5 -> V_218 <= 8 ) )
return 1 ;
if ( V_106 & V_233 )
return 0 ;
if ( V_22 -> V_234 )
return 1 ;
if ( ! ( V_13 = F_73 ( V_22 , 0 ) ) ) {
V_13 = F_17 ( V_22 , 0 , NULL ) ;
if ( ! V_13 )
return 0 ;
if ( F_78 ( V_13 ) ) {
F_30 ( V_13 ) ;
return 0 ;
}
}
sprintf ( V_226 , L_33 ,
V_5 -> V_82 , V_13 -> V_46 , V_13 -> V_45 ) ;
V_227 = ( V_235 + 1 ) * sizeof( struct V_223 ) ;
V_231 = F_3 ( V_227 , V_36 |
( V_13 -> V_42 -> V_206 ? V_207 : 0 ) ) ;
if ( ! V_231 ) {
F_9 ( V_69 , V_70 ) ;
goto V_37;
}
V_15 [ 0 ] = V_236 ;
memset ( & V_15 [ 1 ] , 0 , 5 ) ;
V_15 [ 6 ] = ( unsigned char ) ( V_227 >> 24 ) & 0xff ;
V_15 [ 7 ] = ( unsigned char ) ( V_227 >> 16 ) & 0xff ;
V_15 [ 8 ] = ( unsigned char ) ( V_227 >> 8 ) & 0xff ;
V_15 [ 9 ] = ( unsigned char ) V_227 & 0xff ;
V_15 [ 10 ] = 0 ;
V_15 [ 11 ] = 0 ;
for ( V_229 = 0 ; V_229 < 3 ; V_229 ++ ) {
F_56 ( 3 , F_9 ( V_10 L_34
L_35 , V_226 ,
V_229 ) ) ;
V_14 = F_16 ( V_13 , V_15 , V_19 ,
V_231 , V_227 , & V_114 ,
V_20 + 4 * V_119 , 3 , NULL ) ;
F_56 ( 3 , F_9 ( V_10 L_36
L_37 , V_14
? L_9 : L_10 , V_229 , V_14 ) ) ;
if ( V_14 == 0 )
break;
else if ( F_59 ( & V_114 ) ) {
if ( V_114 . V_122 != V_123 )
break;
}
}
if ( V_14 ) {
V_26 = 1 ;
goto V_237;
}
V_2 = ( T_2 * ) V_231 -> V_223 ;
V_227 = ( ( V_2 [ 0 ] << 24 ) | ( V_2 [ 1 ] << 16 ) |
( V_2 [ 2 ] << 8 ) | ( V_2 [ 3 ] << 0 ) ) ;
V_228 = ( V_227 / sizeof( struct V_223 ) ) ;
if ( V_228 > V_235 ) {
F_9 ( V_238 L_38
L_39
L_40 , V_226 ,
V_235 , V_228 ) ;
V_228 = V_235 ;
}
F_56 ( 3 , F_57 ( V_10 , V_13 ,
L_41 ) ) ;
for ( V_230 = & V_231 [ 1 ] ; V_230 <= & V_231 [ V_228 ] ; V_230 ++ ) {
V_23 = F_80 ( V_230 ) ;
if ( memcmp ( & V_230 -> V_223 [ sizeof( V_23 ) ] , L_42 , 4 ) ) {
int V_225 ;
F_9 ( V_238 L_43 , V_226 ) ;
V_2 = ( char * ) V_230 -> V_223 ;
for ( V_225 = 0 ; V_225 < sizeof( struct V_223 ) ; V_225 ++ )
F_9 ( L_44 , V_2 [ V_225 ] ) ;
F_9 ( L_45 ) ;
} else if ( V_23 > V_13 -> V_42 -> V_218 ) {
F_9 ( V_238 L_46
L_47 ,
V_226 , V_23 ) ;
} else {
int V_205 ;
V_205 = F_72 ( V_22 ,
V_23 , NULL , NULL , V_204 , NULL ) ;
if ( V_205 == V_132 ) {
F_57 ( V_80 , V_13 ,
L_48
L_49
L_50 , V_23 ) ;
break;
}
}
}
V_237:
F_14 ( V_231 ) ;
V_37:
F_76 ( V_13 ) ;
if ( F_74 ( V_13 ) )
F_30 ( V_13 ) ;
return V_26 ;
}
struct V_12 * F_83 ( struct V_27 * V_5 , T_1 V_46 ,
T_1 V_45 , T_1 V_23 , void * V_24 )
{
struct V_12 * V_13 = F_84 ( - V_239 ) ;
struct V_71 * V_29 = & V_5 -> V_240 ;
struct V_21 * V_22 ;
if ( strncmp ( V_241 , L_51 , 4 ) == 0 )
return F_84 ( - V_239 ) ;
V_22 = F_41 ( V_29 , V_46 , V_45 ) ;
if ( ! V_22 )
return F_84 ( - V_242 ) ;
F_85 ( V_22 ) ;
F_86 ( & V_5 -> V_243 ) ;
if ( ! V_5 -> V_213 )
F_1 () ;
if ( F_87 ( V_5 ) && F_88 ( V_5 ) == 0 ) {
F_72 ( V_22 , V_23 , NULL , & V_13 , 1 , V_24 ) ;
F_89 ( V_5 ) ;
}
F_90 ( & V_5 -> V_243 ) ;
F_91 ( V_22 ) ;
F_51 ( V_22 ) ;
F_25 ( & V_22 -> V_28 ) ;
return V_13 ;
}
int F_92 ( struct V_27 * V_42 , T_1 V_46 ,
T_1 V_244 , T_1 V_23 )
{
struct V_12 * V_13 =
F_83 ( V_42 , V_46 , V_244 , V_23 , NULL ) ;
if ( F_93 ( V_13 ) )
return F_94 ( V_13 ) ;
F_76 ( V_13 ) ;
return 0 ;
}
void F_95 ( struct V_71 * V_28 )
{
struct V_245 * V_246 ;
if ( ! V_28 -> V_247 )
return;
V_246 = F_96 ( V_28 -> V_247 ) ;
if ( F_97 ( V_246 -> V_248 ) ) {
if ( V_246 -> V_204 )
V_246 -> V_204 ( V_28 ) ;
F_98 ( V_246 -> V_248 ) ;
}
}
static void F_99 ( struct V_71 * V_29 , unsigned int V_46 ,
unsigned int V_45 , unsigned int V_23 , int V_204 )
{
struct V_27 * V_5 = F_18 ( V_29 ) ;
int V_106 = 0 ;
int V_205 ;
struct V_21 * V_22 ;
if ( V_5 -> V_249 == V_45 )
return;
V_22 = F_41 ( V_29 , V_46 , V_45 ) ;
if ( ! V_22 )
return;
F_85 ( V_22 ) ;
if ( V_23 != V_250 ) {
F_72 ( V_22 , V_23 , NULL , NULL , V_204 , NULL ) ;
goto V_251;
}
V_205 = F_72 ( V_22 , 0 , & V_106 , NULL , V_204 , NULL ) ;
if ( V_205 == V_195 || V_205 == V_211 ) {
if ( F_82 ( V_22 , V_106 , V_204 ) != 0 )
F_79 ( V_22 , V_106 ,
V_22 -> V_89 , V_204 ) ;
}
V_251:
F_91 ( V_22 ) ;
F_51 ( V_22 ) ;
F_25 ( & V_22 -> V_28 ) ;
}
void F_100 ( struct V_71 * V_29 , unsigned int V_46 ,
unsigned int V_45 , unsigned int V_23 , int V_204 )
{
struct V_27 * V_5 = F_18 ( V_29 ) ;
if ( strncmp ( V_241 , L_51 , 4 ) == 0 )
return;
F_86 ( & V_5 -> V_243 ) ;
if ( ! V_5 -> V_213 )
F_1 () ;
if ( F_87 ( V_5 ) && F_88 ( V_5 ) == 0 ) {
F_99 ( V_29 , V_46 , V_45 , V_23 , V_204 ) ;
F_89 ( V_5 ) ;
}
F_90 ( & V_5 -> V_243 ) ;
}
static void F_101 ( struct V_27 * V_5 , unsigned int V_46 ,
unsigned int V_45 , unsigned int V_23 , int V_204 )
{
T_1 V_252 ;
if ( V_45 == V_250 )
for ( V_45 = 0 ; V_45 < V_5 -> V_253 ; ++ V_45 ) {
if ( V_5 -> V_254 )
V_252 = V_5 -> V_253 - V_45 - 1 ;
else
V_252 = V_45 ;
F_99 ( & V_5 -> V_240 , V_46 ,
V_252 , V_23 , V_204 ) ;
}
else
F_99 ( & V_5 -> V_240 , V_46 ,
V_45 , V_23 , V_204 ) ;
}
int F_102 ( struct V_27 * V_5 , unsigned int V_46 ,
unsigned int V_45 , unsigned int V_23 , int V_204 )
{
F_56 ( 3 , F_103 ( V_10 , V_5 ,
L_52 ,
V_70 , V_46 , V_45 , V_23 ) ) ;
if ( ( ( V_46 != V_250 ) && ( V_46 > V_5 -> V_255 ) ) ||
( ( V_45 != V_250 ) && ( V_45 >= V_5 -> V_253 ) ) ||
( ( V_23 != V_250 ) && ( V_23 > V_5 -> V_218 ) ) )
return - V_256 ;
F_86 ( & V_5 -> V_243 ) ;
if ( ! V_5 -> V_213 )
F_1 () ;
if ( F_87 ( V_5 ) && F_88 ( V_5 ) == 0 ) {
if ( V_46 == V_250 )
for ( V_46 = 0 ; V_46 <= V_5 -> V_255 ;
V_46 ++ )
F_101 ( V_5 , V_46 , V_45 , V_23 ,
V_204 ) ;
else
F_101 ( V_5 , V_46 , V_45 , V_23 , V_204 ) ;
F_89 ( V_5 ) ;
}
F_90 ( & V_5 -> V_243 ) ;
return 0 ;
}
static void F_104 ( struct V_27 * V_5 )
{
struct V_12 * V_13 ;
F_105 (sdev, shost) {
if ( V_13 -> V_47 == V_257 )
continue;
if ( ! F_87 ( V_5 ) ||
F_70 ( V_13 ) != 0 )
F_30 ( V_13 ) ;
}
}
static struct V_1 * F_106 ( struct V_27 * V_5 )
{
struct V_1 * V_2 ;
unsigned long V_72 ;
if ( strncmp ( V_241 , L_53 , 4 ) == 0 )
return NULL ;
if ( V_5 -> V_213 ) {
F_9 ( L_54 , V_70 ,
V_5 -> V_82 ) ;
F_107 () ;
return NULL ;
}
V_2 = F_3 ( sizeof( * V_2 ) , V_4 ) ;
if ( ! V_2 )
goto V_258;
V_2 -> V_5 = F_108 ( V_5 ) ;
if ( ! V_2 -> V_5 )
goto V_258;
F_5 ( & V_2 -> V_6 ) ;
F_86 ( & V_5 -> V_243 ) ;
F_33 ( V_5 -> V_73 , V_72 ) ;
V_5 -> V_213 = 1 ;
F_35 ( V_5 -> V_73 , V_72 ) ;
F_90 ( & V_5 -> V_243 ) ;
F_6 ( & V_7 ) ;
if ( F_2 ( & V_3 ) )
F_13 ( & V_2 -> V_6 ) ;
F_7 ( & V_2 -> V_9 , & V_3 ) ;
F_8 ( & V_7 ) ;
return V_2 ;
V_258:
F_14 ( V_2 ) ;
return NULL ;
}
static void F_109 ( struct V_1 * V_2 )
{
struct V_27 * V_5 ;
unsigned long V_72 ;
if ( ! V_2 )
return;
V_5 = V_2 -> V_5 ;
F_86 ( & V_5 -> V_243 ) ;
if ( ! V_5 -> V_213 ) {
F_9 ( L_54 , V_70 ,
V_5 -> V_82 ) ;
F_107 () ;
F_90 ( & V_5 -> V_243 ) ;
return;
}
F_10 ( & V_2 -> V_6 ) ;
F_104 ( V_5 ) ;
F_33 ( V_5 -> V_73 , V_72 ) ;
V_5 -> V_213 = 0 ;
F_35 ( V_5 -> V_73 , V_72 ) ;
F_90 ( & V_5 -> V_243 ) ;
F_6 ( & V_7 ) ;
F_11 ( & V_2 -> V_9 ) ;
if ( ! F_2 ( & V_3 ) ) {
struct V_1 * V_11 = F_12 ( V_3 . V_11 ,
struct V_1 , V_9 ) ;
F_13 ( & V_11 -> V_6 ) ;
}
F_8 ( & V_7 ) ;
F_89 ( V_5 ) ;
F_110 ( V_5 ) ;
F_14 ( V_2 ) ;
}
static void F_111 ( struct V_27 * V_5 )
{
if ( V_5 -> V_65 -> V_259 ) {
unsigned long V_260 = V_261 ;
if ( V_5 -> V_65 -> V_262 )
V_5 -> V_65 -> V_262 ( V_5 ) ;
while ( ! V_5 -> V_65 -> V_259 ( V_5 , V_261 - V_260 ) )
F_4 ( 10 ) ;
} else {
F_102 ( V_5 , V_250 , V_250 ,
V_250 , 0 ) ;
}
}
static void F_112 ( void * V_263 , T_3 V_264 )
{
struct V_1 * V_2 = V_263 ;
struct V_27 * V_5 = V_2 -> V_5 ;
F_111 ( V_5 ) ;
F_109 ( V_2 ) ;
}
void F_113 ( struct V_27 * V_5 )
{
struct V_1 * V_2 ;
if ( strncmp ( V_241 , L_51 , 4 ) == 0 )
return;
if ( F_88 ( V_5 ) < 0 )
return;
V_2 = F_106 ( V_5 ) ;
if ( ! V_2 ) {
F_111 ( V_5 ) ;
F_89 ( V_5 ) ;
return;
}
F_114 ( F_112 , V_2 ) ;
}
void F_115 ( struct V_27 * V_5 )
{
struct V_12 * V_13 ;
unsigned long V_72 ;
V_265:
F_33 ( V_5 -> V_73 , V_72 ) ;
F_40 (sdev, &shost->__devices, siblings) {
if ( V_13 -> V_47 == V_257 )
continue;
F_35 ( V_5 -> V_73 , V_72 ) ;
F_30 ( V_13 ) ;
goto V_265;
}
F_35 ( V_5 -> V_73 , V_72 ) ;
}
struct V_12 * F_116 ( struct V_27 * V_5 )
{
struct V_12 * V_13 = NULL ;
struct V_21 * V_22 ;
F_86 ( & V_5 -> V_243 ) ;
if ( ! F_87 ( V_5 ) )
goto V_37;
V_22 = F_41 ( & V_5 -> V_240 , 0 , V_5 -> V_249 ) ;
if ( ! V_22 )
goto V_37;
V_13 = F_17 ( V_22 , 0 , NULL ) ;
if ( V_13 )
V_13 -> V_61 = 0 ;
else
F_51 ( V_22 ) ;
F_25 ( & V_22 -> V_28 ) ;
V_37:
F_90 ( & V_5 -> V_243 ) ;
return V_13 ;
}
void F_117 ( struct V_12 * V_13 )
{
F_52 ( V_13 -> V_45 != V_13 -> V_42 -> V_249 ) ;
F_30 ( V_13 ) ;
}
