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
F_26 ( V_13 -> V_62 ) ;
V_13 -> V_62 -> V_63 = V_13 ;
F_27 ( V_13 , 0 , V_13 -> V_42 -> V_64 ) ;
F_28 ( V_13 ) ;
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
F_29 ( V_13 , V_69 ) ;
F_30 ( & V_13 -> V_57 ) ;
F_25 ( & V_13 -> V_70 ) ;
F_25 ( & V_13 -> V_57 ) ;
V_37:
if ( V_25 )
F_9 ( V_71 , V_72 ) ;
return NULL ;
}
static void F_31 ( struct V_21 * V_22 )
{
struct V_73 * V_28 = & V_22 -> V_28 ;
struct V_27 * V_5 = F_18 ( V_28 -> V_29 ) ;
unsigned long V_74 ;
F_30 ( V_28 ) ;
F_32 ( V_5 -> V_75 , V_74 ) ;
if ( V_5 -> V_65 -> V_76 )
V_5 -> V_65 -> V_76 ( V_22 ) ;
F_33 ( & V_22 -> V_49 ) ;
F_34 ( V_5 -> V_75 , V_74 ) ;
F_25 ( V_28 ) ;
}
static void F_35 ( struct V_73 * V_28 )
{
struct V_73 * V_29 = V_28 -> V_29 ;
struct V_21 * V_22 = F_36 ( V_28 ) ;
F_14 ( V_22 ) ;
F_25 ( V_29 ) ;
}
int F_37 ( const struct V_73 * V_28 )
{
return V_28 -> type == & V_77 ;
}
static struct V_21 * F_38 ( struct V_73 * V_29 ,
int V_46 , T_1 V_45 )
{
struct V_21 * V_22 , * V_78 = NULL ;
struct V_27 * V_5 = F_18 ( V_29 ) ;
F_39 (starget, &shost->__targets, siblings) {
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
static struct V_21 * F_40 ( struct V_73 * V_29 ,
int V_46 , T_1 V_45 )
{
struct V_27 * V_5 = F_18 ( V_29 ) ;
struct V_73 * V_28 = NULL ;
unsigned long V_74 ;
const int V_79 = sizeof( struct V_21 )
+ V_5 -> V_34 -> V_80 ;
struct V_21 * V_22 ;
struct V_21 * V_81 ;
int error ;
V_22 = F_19 ( V_79 , V_4 ) ;
if ( ! V_22 ) {
F_9 ( V_82 L_3 , V_72 ) ;
return NULL ;
}
V_28 = & V_22 -> V_28 ;
F_41 ( V_28 ) ;
V_22 -> V_83 = 1 ;
V_28 -> V_29 = F_23 ( V_29 ) ;
F_42 ( V_28 , L_4 , V_5 -> V_84 , V_46 , V_45 ) ;
V_28 -> V_85 = & V_86 ;
V_28 -> type = & V_77 ;
V_22 -> V_45 = V_45 ;
V_22 -> V_46 = V_46 ;
V_22 -> V_87 = 0 ;
F_20 ( & V_22 -> V_49 ) ;
F_20 ( & V_22 -> V_88 ) ;
V_22 -> V_89 = V_90 ;
V_22 -> V_91 = V_92 ;
V_22 -> V_93 = V_94 ;
V_95:
F_32 ( V_5 -> V_75 , V_74 ) ;
V_81 = F_38 ( V_29 , V_46 , V_45 ) ;
if ( V_81 )
goto V_96;
F_7 ( & V_22 -> V_49 , & V_5 -> V_97 ) ;
F_34 ( V_5 -> V_75 , V_74 ) ;
F_43 ( V_28 ) ;
if ( V_5 -> V_65 -> V_98 ) {
error = V_5 -> V_65 -> V_98 ( V_22 ) ;
if( error ) {
F_44 ( V_82 , V_28 , L_5 , error ) ;
F_31 ( V_22 ) ;
return NULL ;
}
}
F_23 ( V_28 ) ;
return V_22 ;
V_96:
V_81 -> V_83 ++ ;
F_34 ( V_5 -> V_75 , V_74 ) ;
if ( V_81 -> V_89 != V_99 ) {
F_25 ( V_28 ) ;
return V_81 ;
}
F_25 ( & V_81 -> V_28 ) ;
F_45 () ;
goto V_95;
}
static void F_46 ( struct V_31 * V_32 )
{
struct V_21 * V_22 =
F_47 ( V_32 , struct V_21 , V_100 . V_32 ) ;
F_48 ( & V_22 -> V_28 ) ;
F_49 ( & V_22 -> V_28 ) ;
F_31 ( V_22 ) ;
}
void F_50 ( struct V_21 * V_22 )
{
struct V_27 * V_5 = F_18 ( V_22 -> V_28 . V_29 ) ;
unsigned long V_74 ;
enum V_101 V_89 ;
int V_102 = 0 ;
F_32 ( V_5 -> V_75 , V_74 ) ;
V_89 = V_22 -> V_89 ;
if ( -- V_22 -> V_83 == 0 && F_2 ( & V_22 -> V_88 ) ) {
V_102 = 1 ;
V_22 -> V_89 = V_99 ;
}
F_34 ( V_5 -> V_75 , V_74 ) ;
if ( ! V_102 )
return;
F_51 ( V_89 == V_99 ) ;
if ( V_89 == V_90 )
F_31 ( V_22 ) ;
else
F_52 ( F_46 ,
& V_22 -> V_100 ) ;
}
static void F_53 ( unsigned char * V_103 , int V_104 )
{
int V_105 = 0 ;
for (; V_104 > 0 ; ( -- V_104 , ++ V_103 ) ) {
if ( * V_103 == 0 )
V_105 = 1 ;
if ( V_105 || * V_103 < 0x20 || * V_103 > 0x7e )
* V_103 = ' ' ;
}
}
static int F_54 ( struct V_12 * V_13 , unsigned char * V_106 ,
int V_107 , int * V_108 )
{
unsigned char V_15 [ V_16 ] ;
int V_109 , V_110 , V_111 ;
int V_112 = 0 ;
int V_113 , V_114 , V_14 ;
struct V_115 V_116 ;
* V_108 = 0 ;
V_109 = V_13 -> V_117 ? V_13 -> V_117 : 36 ;
V_110 = V_109 ;
V_113 = 1 ;
V_118:
F_55 ( 3 , F_56 ( V_10 , V_13 ,
L_6 ,
V_113 , V_110 ) ) ;
for ( V_114 = 0 ; V_114 < 3 ; ++ V_114 ) {
int V_119 ;
memset ( V_15 , 0 , 6 ) ;
V_15 [ 0 ] = V_120 ;
V_15 [ 4 ] = ( unsigned char ) V_110 ;
memset ( V_106 , 0 , V_110 ) ;
V_14 = F_16 ( V_13 , V_15 , V_19 ,
V_106 , V_110 , & V_116 ,
V_121 / 2 + V_121 * V_122 , 3 ,
& V_119 ) ;
F_55 ( 3 , F_9 ( V_10 L_7
L_8 ,
V_14 ? L_9 : L_10 , V_14 ) ) ;
if ( V_14 ) {
if ( ( F_57 ( V_14 ) & V_123 ) &&
F_58 ( & V_116 ) ) {
if ( ( V_116 . V_124 == V_125 ) &&
( ( V_116 . V_126 == 0x28 ) ||
( V_116 . V_126 == 0x29 ) ) &&
( V_116 . V_127 == 0 ) )
continue;
}
} else {
if ( V_119 == V_110 )
continue;
}
break;
}
if ( V_14 == 0 ) {
F_53 ( & V_106 [ 8 ] , 8 ) ;
F_53 ( & V_106 [ 16 ] , 16 ) ;
F_53 ( & V_106 [ 32 ] , 4 ) ;
V_112 = V_106 [ 4 ] + 5 ;
if ( V_112 > 255 )
V_112 = V_109 ;
* V_108 = F_59 ( V_13 , & V_106 [ 8 ] ,
& V_106 [ 16 ] ) ;
if ( V_113 == 1 ) {
if ( V_128 & * V_108 )
V_111 = 36 ;
else if ( V_129 & * V_108 )
V_111 = 58 ;
else if ( V_13 -> V_117 )
V_111 = V_13 -> V_117 ;
else
V_111 = V_112 ;
if ( V_111 > V_110 ) {
V_110 = V_111 ;
V_113 = 2 ;
goto V_118;
}
}
} else if ( V_113 == 2 ) {
F_9 ( V_10 L_11
L_12 ,
V_110 ) ;
V_110 = V_109 ;
V_113 = 3 ;
goto V_118;
}
if ( V_14 )
return - V_130 ;
V_13 -> V_117 = F_60 ( V_110 , V_112 ) ;
if ( V_13 -> V_117 < 36 ) {
F_9 ( V_10 L_13
L_14 , V_13 -> V_117 ) ;
V_13 -> V_117 = 36 ;
}
V_13 -> V_91 = V_106 [ 2 ] & 0x07 ;
if ( V_13 -> V_91 >= 2 ||
( V_13 -> V_91 == 1 && ( V_106 [ 3 ] & 0x0f ) == 1 ) )
V_13 -> V_91 ++ ;
V_13 -> V_58 -> V_91 = V_13 -> V_91 ;
return 0 ;
}
static int F_61 ( struct V_12 * V_13 , unsigned char * V_106 ,
int * V_108 , int V_131 )
{
int V_26 ;
V_13 -> V_132 = F_62 ( V_106 ,
F_63 ( V_133 , V_13 -> V_117 , 36 ) ,
V_36 ) ;
if ( V_13 -> V_132 == NULL )
return V_134 ;
V_13 -> V_38 = ( char * ) ( V_13 -> V_132 + 8 ) ;
V_13 -> V_40 = ( char * ) ( V_13 -> V_132 + 16 ) ;
V_13 -> V_41 = ( char * ) ( V_13 -> V_132 + 32 ) ;
if ( * V_108 & V_135 ) {
V_13 -> type = V_136 ;
V_13 -> V_137 = 1 ;
} else {
V_13 -> type = ( V_106 [ 0 ] & 0x1f ) ;
V_13 -> V_137 = ( V_106 [ 1 ] & 0x80 ) >> 7 ;
}
switch ( V_13 -> type ) {
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
case V_149 :
V_13 -> V_150 = 1 ;
break;
case V_136 :
case V_151 :
V_13 -> V_150 = 0 ;
break;
default:
F_9 ( V_10 L_15 , V_13 -> type ) ;
}
if ( V_13 -> type == V_138 || V_13 -> type == V_136 ) {
if ( ( * V_108 & V_152 ) == 0 )
* V_108 |= V_153 ;
}
V_13 -> V_154 = ( V_106 [ 0 ] >> 5 ) & 7 ;
V_13 -> V_155 = V_13 -> V_137 ;
V_13 -> V_156 = ( V_106 [ 7 ] & 1 ) && ( ( V_106 [ 3 ] & 7 ) == 2 ) ;
if ( V_13 -> V_91 >= V_157 ||
( V_13 -> V_117 > 56 && V_106 [ 56 ] & 0x04 ) )
V_13 -> V_158 = 1 ;
if ( V_106 [ 7 ] & 0x60 )
V_13 -> V_159 = 1 ;
if ( V_106 [ 7 ] & 0x10 )
V_13 -> V_160 = 1 ;
F_56 ( V_17 , V_13 , L_16
L_17 , F_64 ( V_13 -> type ) ,
V_13 -> V_38 , V_13 -> V_40 , V_13 -> V_41 ,
V_13 -> V_154 , V_106 [ 2 ] & 0x07 ,
( V_106 [ 3 ] & 0x0f ) == 1 ? L_18 : L_19 ) ;
if ( ( V_13 -> V_91 >= V_92 ) && ( V_106 [ 7 ] & 2 ) &&
! ( * V_108 & V_161 ) )
V_13 -> V_162 = 1 ;
if ( ( * V_108 & V_163 ) == 0 )
V_13 -> V_61 = 0 ;
if ( * V_108 & V_164 )
V_13 -> V_165 = 1 ;
if ( * V_108 & V_166 )
V_13 -> V_167 = 1 ;
if ( * V_108 & V_168 )
F_65 ( V_13 -> V_62 , 512 ) ;
if ( * V_108 & V_169 )
V_13 -> V_170 = 1 ;
if ( * V_108 & V_171 )
V_21 ( V_13 ) -> V_172 = 1 ;
V_13 -> V_173 = 1 ;
if ( * V_108 & V_174 )
V_13 -> V_175 = 1 ;
if ( * V_108 & V_176 )
V_13 -> V_177 = 1 ;
if ( * V_108 & V_178 )
V_13 -> V_179 = 1 ;
V_26 = F_29 ( V_13 , V_180 ) ;
if ( V_26 ) {
V_26 = F_29 ( V_13 , V_181 ) ;
if ( V_26 ) {
F_56 ( V_82 , V_13 ,
L_20 ,
F_66 ( V_13 -> V_47 ) ) ;
return V_134 ;
}
}
if ( * V_108 & V_182 )
V_13 -> V_183 = 1 ;
if ( * V_108 & V_184 )
V_13 -> V_155 = 0 ;
if ( * V_108 & V_185 )
V_13 -> V_186 = 1 ;
F_67 ( & V_13 -> V_57 ) ;
if ( V_13 -> V_42 -> V_65 -> V_187 ) {
V_26 = V_13 -> V_42 -> V_65 -> V_187 ( V_13 ) ;
if ( V_26 ) {
if ( V_26 != - V_67 ) {
F_56 ( V_82 , V_13 ,
L_21 ) ;
}
return V_134 ;
}
}
V_13 -> V_188 = V_13 -> V_189 ;
if ( ! V_131 && F_68 ( V_13 ) != 0 )
return V_134 ;
return V_190 ;
}
static unsigned char * F_69 ( unsigned char * V_191 , unsigned char * V_192 ,
unsigned V_193 , unsigned V_194 )
{
unsigned V_195 = 0 , V_196 ;
for ( V_196 = 0 ; V_196 + V_193 < V_194 && V_196 + V_193 < V_192 [ 4 ] + 5 ; V_196 ++ ) {
if ( V_192 [ V_196 + V_193 ] > ' ' ) {
V_191 [ V_196 ] = V_192 [ V_196 + V_193 ] ;
V_195 = V_196 + 1 ;
} else {
V_191 [ V_196 ] = ' ' ;
}
}
V_191 [ V_195 ] = 0 ;
return V_191 ;
}
static int F_70 ( struct V_21 * V_22 ,
T_1 V_23 , int * V_197 ,
struct V_12 * * V_198 , int V_199 ,
void * V_24 )
{
struct V_12 * V_13 ;
unsigned char * V_14 ;
int V_108 , V_200 = V_134 , V_107 = 256 ;
struct V_27 * V_5 = F_18 ( V_22 -> V_28 . V_29 ) ;
V_13 = F_71 ( V_22 , V_23 ) ;
if ( V_13 ) {
if ( V_199 || ! F_72 ( V_13 ) ) {
F_55 ( 3 , F_9 ( V_10
L_22 ,
F_73 ( & V_13 -> V_57 ) ) ) ;
if ( V_198 )
* V_198 = V_13 ;
else
F_74 ( V_13 ) ;
if ( V_197 )
* V_197 = F_59 ( V_13 ,
V_13 -> V_38 ,
V_13 -> V_40 ) ;
return V_190 ;
}
F_74 ( V_13 ) ;
} else
V_13 = F_17 ( V_22 , V_23 , V_24 ) ;
if ( ! V_13 )
goto V_37;
V_14 = F_3 ( V_107 , V_36 |
( ( V_5 -> V_201 ) ? V_202 : 0 ) ) ;
if ( ! V_14 )
goto V_203;
if ( F_54 ( V_13 , V_14 , V_107 , & V_108 ) )
goto V_204;
if ( V_197 )
* V_197 = V_108 ;
if ( ( ( V_14 [ 0 ] >> 5 ) == 3 ) && ! ( V_108 & V_205 ) ) {
F_55 ( 2 , sdev_printk(KERN_INFO, sdev, L_23
L_24
L_25))
if ( V_23 == 0 ) {
F_55 ( 1 , {
unsigned char vend[9];
unsigned char mod[17];
sdev_printk(KERN_INFO, sdev,
L_26
L_27,
scsi_inq_str(vend, result, 8, 16),
scsi_inq_str(mod, result, 16, 32));
}) ;
}
V_200 = V_206 ;
goto V_204;
}
if ( ( ( V_14 [ 0 ] >> 5 ) == 1 || V_22 -> V_207 ) &&
( V_14 [ 0 ] & 0x1f ) == 0x1f &&
! F_75 ( V_23 ) ) {
F_55 ( 3 , F_9 ( V_10
L_28
L_29 ) ) ;
V_200 = V_206 ;
goto V_204;
}
V_200 = F_61 ( V_13 , V_14 , & V_108 , V_5 -> V_208 ) ;
if ( V_200 == V_190 ) {
if ( V_108 & V_209 ) {
V_13 -> V_155 = 0 ;
F_15 ( V_13 , V_14 ) ;
}
}
V_204:
F_14 ( V_14 ) ;
V_203:
if ( V_200 == V_190 ) {
if ( V_198 ) {
if ( F_76 ( V_13 ) == 0 ) {
* V_198 = V_13 ;
} else {
F_77 ( V_13 ) ;
V_200 = V_134 ;
}
}
} else
F_77 ( V_13 ) ;
V_37:
return V_200 ;
}
static void F_78 ( struct V_21 * V_22 ,
int V_108 , int V_91 , int V_199 )
{
unsigned int V_210 , V_23 , V_211 ;
struct V_27 * V_5 = F_18 ( V_22 -> V_28 . V_29 ) ;
F_55 ( 3 , F_9 ( V_10 L_30
L_31 , F_73 ( & V_22 -> V_28 ) ) ) ;
V_211 = F_60 ( V_212 , V_5 -> V_213 ) ;
if ( V_108 & V_214 ) {
V_211 = V_5 -> V_213 ;
V_210 = 1 ;
} else
V_210 = 0 ;
if ( V_108 & V_215 )
V_211 = V_5 -> V_213 ;
if ( V_108 & V_216 )
V_211 = F_60 ( 5U , V_211 ) ;
if ( V_91 < V_157 && ! ( V_108 & V_217 ) )
V_211 = F_60 ( 8U , V_211 ) ;
for ( V_23 = 1 ; V_23 < V_211 ; ++ V_23 )
if ( ( F_70 ( V_22 , V_23 , NULL , NULL , V_199 ,
NULL ) != V_190 ) &&
! V_210 )
return;
}
int F_79 ( struct V_218 * V_219 )
{
int V_220 ;
unsigned int V_23 ;
V_23 = 0 ;
for ( V_220 = 0 ; V_220 < sizeof( V_23 ) ; V_220 += 2 )
V_23 = V_23 | ( ( ( V_219 -> V_218 [ V_220 ] << 8 ) |
V_219 -> V_218 [ V_220 + 1 ] ) << ( V_220 * 8 ) ) ;
return V_23 ;
}
void F_80 ( unsigned int V_23 , struct V_218 * V_219 )
{
int V_220 ;
memset ( V_219 -> V_218 , 0 , sizeof( V_219 -> V_218 ) ) ;
for ( V_220 = 0 ; V_220 < sizeof( V_23 ) ; V_220 += 2 ) {
V_219 -> V_218 [ V_220 ] = ( V_23 >> 8 ) & 0xFF ;
V_219 -> V_218 [ V_220 + 1 ] = V_23 & 0xFF ;
V_23 = V_23 >> 16 ;
}
}
static int F_81 ( struct V_21 * V_22 , int V_108 ,
int V_199 )
{
char V_221 [ 64 ] ;
unsigned char V_15 [ V_16 ] ;
unsigned int V_222 ;
unsigned int V_23 ;
unsigned int V_223 ;
unsigned int V_224 ;
int V_14 ;
struct V_218 * V_225 , * V_226 ;
T_2 * V_2 ;
struct V_115 V_116 ;
struct V_12 * V_13 ;
struct V_27 * V_5 = F_18 ( & V_22 -> V_28 ) ;
int V_26 = 0 ;
if ( V_108 & V_153 )
return 1 ;
if ( V_22 -> V_91 < V_92 &&
V_22 -> V_91 != V_227 )
return 1 ;
if ( V_22 -> V_91 < V_157 &&
( ! ( V_108 & V_152 ) || V_5 -> V_213 <= 8 ) )
return 1 ;
if ( V_108 & V_228 )
return 0 ;
if ( ! ( V_13 = F_71 ( V_22 , 0 ) ) ) {
V_13 = F_17 ( V_22 , 0 , NULL ) ;
if ( ! V_13 )
return 0 ;
if ( F_76 ( V_13 ) ) {
F_77 ( V_13 ) ;
return 0 ;
}
}
sprintf ( V_221 , L_32 ,
V_5 -> V_84 , V_13 -> V_46 , V_13 -> V_45 ) ;
V_222 = ( V_229 + 1 ) * sizeof( struct V_218 ) ;
V_226 = F_3 ( V_222 , V_36 |
( V_13 -> V_42 -> V_201 ? V_202 : 0 ) ) ;
if ( ! V_226 ) {
F_9 ( V_71 , V_72 ) ;
goto V_37;
}
V_15 [ 0 ] = V_230 ;
memset ( & V_15 [ 1 ] , 0 , 5 ) ;
V_15 [ 6 ] = ( unsigned char ) ( V_222 >> 24 ) & 0xff ;
V_15 [ 7 ] = ( unsigned char ) ( V_222 >> 16 ) & 0xff ;
V_15 [ 8 ] = ( unsigned char ) ( V_222 >> 8 ) & 0xff ;
V_15 [ 9 ] = ( unsigned char ) V_222 & 0xff ;
V_15 [ 10 ] = 0 ;
V_15 [ 11 ] = 0 ;
for ( V_224 = 0 ; V_224 < 3 ; V_224 ++ ) {
F_55 ( 3 , F_9 ( V_10 L_33
L_34 , V_221 ,
V_224 ) ) ;
V_14 = F_16 ( V_13 , V_15 , V_19 ,
V_226 , V_222 , & V_116 ,
V_20 + 4 * V_121 , 3 , NULL ) ;
F_55 ( 3 , F_9 ( V_10 L_35
L_36 , V_14
? L_9 : L_10 , V_224 , V_14 ) ) ;
if ( V_14 == 0 )
break;
else if ( F_58 ( & V_116 ) ) {
if ( V_116 . V_124 != V_125 )
break;
}
}
if ( V_14 ) {
V_26 = 1 ;
goto V_231;
}
V_2 = ( T_2 * ) V_226 -> V_218 ;
V_222 = ( ( V_2 [ 0 ] << 24 ) | ( V_2 [ 1 ] << 16 ) |
( V_2 [ 2 ] << 8 ) | ( V_2 [ 3 ] << 0 ) ) ;
V_223 = ( V_222 / sizeof( struct V_218 ) ) ;
if ( V_223 > V_229 ) {
F_9 ( V_232 L_37
L_38
L_39 , V_221 ,
V_229 , V_223 ) ;
V_223 = V_229 ;
}
F_55 ( 3 , F_56 ( V_10 , V_13 ,
L_40 ) ) ;
for ( V_225 = & V_226 [ 1 ] ; V_225 <= & V_226 [ V_223 ] ; V_225 ++ ) {
V_23 = F_79 ( V_225 ) ;
if ( memcmp ( & V_225 -> V_218 [ sizeof( V_23 ) ] , L_41 , 4 ) ) {
int V_220 ;
F_9 ( V_232 L_42 , V_221 ) ;
V_2 = ( char * ) V_225 -> V_218 ;
for ( V_220 = 0 ; V_220 < sizeof( struct V_218 ) ; V_220 ++ )
F_9 ( L_43 , V_2 [ V_220 ] ) ;
F_9 ( L_44 ) ;
} else if ( V_23 > V_13 -> V_42 -> V_213 ) {
F_9 ( V_232 L_45
L_46 ,
V_221 , V_23 ) ;
} else {
int V_200 ;
V_200 = F_70 ( V_22 ,
V_23 , NULL , NULL , V_199 , NULL ) ;
if ( V_200 == V_134 ) {
F_56 ( V_82 , V_13 ,
L_47
L_48
L_49 , V_23 ) ;
break;
}
}
}
V_231:
F_14 ( V_226 ) ;
V_37:
F_74 ( V_13 ) ;
if ( F_72 ( V_13 ) )
F_77 ( V_13 ) ;
return V_26 ;
}
struct V_12 * F_82 ( struct V_27 * V_5 , T_1 V_46 ,
T_1 V_45 , T_1 V_23 , void * V_24 )
{
struct V_12 * V_13 = F_83 ( - V_233 ) ;
struct V_73 * V_29 = & V_5 -> V_234 ;
struct V_21 * V_22 ;
if ( strncmp ( V_235 , L_50 , 4 ) == 0 )
return F_83 ( - V_233 ) ;
V_22 = F_40 ( V_29 , V_46 , V_45 ) ;
if ( ! V_22 )
return F_83 ( - V_236 ) ;
F_84 ( V_22 ) ;
F_85 ( & V_5 -> V_237 ) ;
if ( ! V_5 -> V_208 )
F_1 () ;
if ( F_86 ( V_5 ) && F_87 ( V_5 ) == 0 ) {
F_70 ( V_22 , V_23 , NULL , & V_13 , 1 , V_24 ) ;
F_88 ( V_5 ) ;
}
F_89 ( & V_5 -> V_237 ) ;
F_90 ( V_22 ) ;
F_50 ( V_22 ) ;
F_25 ( & V_22 -> V_28 ) ;
return V_13 ;
}
int F_91 ( struct V_27 * V_42 , T_1 V_46 ,
T_1 V_238 , T_1 V_23 )
{
struct V_12 * V_13 =
F_82 ( V_42 , V_46 , V_238 , V_23 , NULL ) ;
if ( F_92 ( V_13 ) )
return F_93 ( V_13 ) ;
F_74 ( V_13 ) ;
return 0 ;
}
void F_94 ( struct V_73 * V_28 )
{
struct V_239 * V_240 ;
if ( ! V_28 -> V_241 )
return;
V_240 = F_95 ( V_28 -> V_241 ) ;
if ( F_96 ( V_240 -> V_242 ) ) {
if ( V_240 -> V_199 )
V_240 -> V_199 ( V_28 ) ;
F_97 ( V_240 -> V_242 ) ;
}
}
static void F_98 ( struct V_73 * V_29 , unsigned int V_46 ,
unsigned int V_45 , unsigned int V_23 , int V_199 )
{
struct V_27 * V_5 = F_18 ( V_29 ) ;
int V_108 = 0 ;
int V_200 ;
struct V_21 * V_22 ;
if ( V_5 -> V_243 == V_45 )
return;
V_22 = F_40 ( V_29 , V_46 , V_45 ) ;
if ( ! V_22 )
return;
F_84 ( V_22 ) ;
if ( V_23 != V_244 ) {
F_70 ( V_22 , V_23 , NULL , NULL , V_199 , NULL ) ;
goto V_245;
}
V_200 = F_70 ( V_22 , 0 , & V_108 , NULL , V_199 , NULL ) ;
if ( V_200 == V_190 || V_200 == V_206 ) {
if ( F_81 ( V_22 , V_108 , V_199 ) != 0 )
F_78 ( V_22 , V_108 ,
V_22 -> V_91 , V_199 ) ;
}
V_245:
F_90 ( V_22 ) ;
F_50 ( V_22 ) ;
F_25 ( & V_22 -> V_28 ) ;
}
void F_99 ( struct V_73 * V_29 , unsigned int V_46 ,
unsigned int V_45 , unsigned int V_23 , int V_199 )
{
struct V_27 * V_5 = F_18 ( V_29 ) ;
if ( strncmp ( V_235 , L_50 , 4 ) == 0 )
return;
F_85 ( & V_5 -> V_237 ) ;
if ( ! V_5 -> V_208 )
F_1 () ;
if ( F_86 ( V_5 ) && F_87 ( V_5 ) == 0 ) {
F_98 ( V_29 , V_46 , V_45 , V_23 , V_199 ) ;
F_88 ( V_5 ) ;
}
F_89 ( & V_5 -> V_237 ) ;
}
static void F_100 ( struct V_27 * V_5 , unsigned int V_46 ,
unsigned int V_45 , unsigned int V_23 , int V_199 )
{
T_1 V_246 ;
if ( V_45 == V_244 )
for ( V_45 = 0 ; V_45 < V_5 -> V_247 ; ++ V_45 ) {
if ( V_5 -> V_248 )
V_246 = V_5 -> V_247 - V_45 - 1 ;
else
V_246 = V_45 ;
F_98 ( & V_5 -> V_234 , V_46 ,
V_246 , V_23 , V_199 ) ;
}
else
F_98 ( & V_5 -> V_234 , V_46 ,
V_45 , V_23 , V_199 ) ;
}
int F_101 ( struct V_27 * V_5 , unsigned int V_46 ,
unsigned int V_45 , unsigned int V_23 , int V_199 )
{
F_55 ( 3 , F_102 ( V_10 , V_5 ,
L_51 ,
V_72 , V_46 , V_45 , V_23 ) ) ;
if ( ( ( V_46 != V_244 ) && ( V_46 > V_5 -> V_249 ) ) ||
( ( V_45 != V_244 ) && ( V_45 >= V_5 -> V_247 ) ) ||
( ( V_23 != V_244 ) && ( V_23 > V_5 -> V_213 ) ) )
return - V_250 ;
F_85 ( & V_5 -> V_237 ) ;
if ( ! V_5 -> V_208 )
F_1 () ;
if ( F_86 ( V_5 ) && F_87 ( V_5 ) == 0 ) {
if ( V_46 == V_244 )
for ( V_46 = 0 ; V_46 <= V_5 -> V_249 ;
V_46 ++ )
F_100 ( V_5 , V_46 , V_45 , V_23 ,
V_199 ) ;
else
F_100 ( V_5 , V_46 , V_45 , V_23 , V_199 ) ;
F_88 ( V_5 ) ;
}
F_89 ( & V_5 -> V_237 ) ;
return 0 ;
}
static void F_103 ( struct V_27 * V_5 )
{
struct V_12 * V_13 ;
F_104 (sdev, shost) {
if ( ! F_86 ( V_5 ) ||
F_68 ( V_13 ) != 0 )
F_77 ( V_13 ) ;
}
}
static struct V_1 * F_105 ( struct V_27 * V_5 )
{
struct V_1 * V_2 ;
unsigned long V_74 ;
if ( strncmp ( V_235 , L_52 , 4 ) == 0 )
return NULL ;
if ( V_5 -> V_208 ) {
F_9 ( L_53 , V_72 ,
V_5 -> V_84 ) ;
F_106 () ;
return NULL ;
}
V_2 = F_3 ( sizeof( * V_2 ) , V_4 ) ;
if ( ! V_2 )
goto V_251;
V_2 -> V_5 = F_107 ( V_5 ) ;
if ( ! V_2 -> V_5 )
goto V_251;
F_5 ( & V_2 -> V_6 ) ;
F_85 ( & V_5 -> V_237 ) ;
F_32 ( V_5 -> V_75 , V_74 ) ;
V_5 -> V_208 = 1 ;
F_34 ( V_5 -> V_75 , V_74 ) ;
F_89 ( & V_5 -> V_237 ) ;
F_6 ( & V_7 ) ;
if ( F_2 ( & V_3 ) )
F_13 ( & V_2 -> V_6 ) ;
F_7 ( & V_2 -> V_9 , & V_3 ) ;
F_8 ( & V_7 ) ;
return V_2 ;
V_251:
F_14 ( V_2 ) ;
return NULL ;
}
static void F_108 ( struct V_1 * V_2 )
{
struct V_27 * V_5 ;
unsigned long V_74 ;
if ( ! V_2 )
return;
V_5 = V_2 -> V_5 ;
F_85 ( & V_5 -> V_237 ) ;
if ( ! V_5 -> V_208 ) {
F_9 ( L_53 , V_72 ,
V_5 -> V_84 ) ;
F_106 () ;
F_89 ( & V_5 -> V_237 ) ;
return;
}
F_10 ( & V_2 -> V_6 ) ;
F_103 ( V_5 ) ;
F_32 ( V_5 -> V_75 , V_74 ) ;
V_5 -> V_208 = 0 ;
F_34 ( V_5 -> V_75 , V_74 ) ;
F_89 ( & V_5 -> V_237 ) ;
F_6 ( & V_7 ) ;
F_11 ( & V_2 -> V_9 ) ;
if ( ! F_2 ( & V_3 ) ) {
struct V_1 * V_11 = F_12 ( V_3 . V_11 ,
struct V_1 , V_9 ) ;
F_13 ( & V_11 -> V_6 ) ;
}
F_8 ( & V_7 ) ;
F_109 ( V_5 ) ;
F_14 ( V_2 ) ;
}
static void F_110 ( struct V_27 * V_5 )
{
if ( V_5 -> V_65 -> V_252 ) {
unsigned long V_253 = V_254 ;
if ( V_5 -> V_65 -> V_255 )
V_5 -> V_65 -> V_255 ( V_5 ) ;
while ( ! V_5 -> V_65 -> V_252 ( V_5 , V_254 - V_253 ) )
F_4 ( 10 ) ;
} else {
F_101 ( V_5 , V_244 , V_244 ,
V_244 , 0 ) ;
}
}
static int F_111 ( void * V_256 )
{
struct V_1 * V_2 = V_256 ;
struct V_27 * V_5 = V_2 -> V_5 ;
F_110 ( V_5 ) ;
F_108 ( V_2 ) ;
F_88 ( V_5 ) ;
return 0 ;
}
void F_112 ( struct V_27 * V_5 )
{
struct V_257 * V_258 ;
struct V_1 * V_2 ;
if ( strncmp ( V_235 , L_50 , 4 ) == 0 )
return;
if ( F_87 ( V_5 ) < 0 )
return;
V_2 = F_105 ( V_5 ) ;
if ( ! V_2 ) {
F_110 ( V_5 ) ;
F_88 ( V_5 ) ;
return;
}
V_258 = F_113 ( F_111 , V_2 , L_54 , V_5 -> V_84 ) ;
if ( F_92 ( V_258 ) )
F_111 ( V_2 ) ;
}
void F_114 ( struct V_27 * V_5 )
{
struct V_12 * V_13 ;
unsigned long V_74 ;
V_259:
F_32 ( V_5 -> V_75 , V_74 ) ;
F_39 (sdev, &shost->__devices, siblings) {
if ( V_13 -> V_47 == V_69 )
continue;
F_34 ( V_5 -> V_75 , V_74 ) ;
F_77 ( V_13 ) ;
goto V_259;
}
F_34 ( V_5 -> V_75 , V_74 ) ;
}
struct V_12 * F_115 ( struct V_27 * V_5 )
{
struct V_12 * V_13 = NULL ;
struct V_21 * V_22 ;
F_85 ( & V_5 -> V_237 ) ;
if ( ! F_86 ( V_5 ) )
goto V_37;
V_22 = F_40 ( & V_5 -> V_234 , 0 , V_5 -> V_243 ) ;
if ( ! V_22 )
goto V_37;
V_13 = F_17 ( V_22 , 0 , NULL ) ;
if ( V_13 )
V_13 -> V_61 = 0 ;
else
F_50 ( V_22 ) ;
F_25 ( & V_22 -> V_28 ) ;
V_37:
F_89 ( & V_5 -> V_237 ) ;
return V_13 ;
}
void F_116 ( struct V_12 * V_13 )
{
F_51 ( V_13 -> V_45 != V_13 -> V_42 -> V_243 ) ;
F_77 ( V_13 ) ;
}
