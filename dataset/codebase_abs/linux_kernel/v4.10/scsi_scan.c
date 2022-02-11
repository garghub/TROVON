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
F_16 ( V_17 , V_13 , L_2 ) ;
V_15 [ 0 ] = V_18 ;
V_15 [ 1 ] = 0 ;
V_15 [ 2 ] = 0x2e ;
V_15 [ 3 ] = 0 ;
V_15 [ 4 ] = 0x2a ;
V_15 [ 5 ] = 0 ;
F_17 ( V_13 , V_15 , V_19 , V_14 , 0x2a , NULL ,
V_20 , 3 , NULL ) ;
}
static struct V_12 * F_18 ( struct V_21 * V_22 ,
T_1 V_23 , void * V_24 )
{
struct V_12 * V_13 ;
int V_25 = 1 , V_26 ;
struct V_27 * V_5 = F_19 ( V_22 -> V_28 . V_29 ) ;
V_13 = F_20 ( sizeof( * V_13 ) + V_5 -> V_30 -> V_31 ,
V_32 ) ;
if ( ! V_13 )
goto V_33;
V_13 -> V_34 = V_35 ;
V_13 -> V_36 = V_35 ;
V_13 -> V_37 = V_35 ;
V_13 -> V_38 = V_5 ;
V_13 -> V_39 = V_40 ;
V_13 -> V_41 = V_22 -> V_41 ;
V_13 -> V_23 = V_23 ;
V_13 -> V_42 = V_22 -> V_42 ;
V_13 -> V_43 = V_44 ;
F_21 ( & V_13 -> V_45 ) ;
F_21 ( & V_13 -> V_46 ) ;
F_21 ( & V_13 -> V_47 ) ;
F_21 ( & V_13 -> V_48 ) ;
F_21 ( & V_13 -> V_49 ) ;
F_22 ( & V_13 -> V_50 ) ;
F_23 ( & V_13 -> V_51 ) ;
F_24 ( & V_13 -> V_52 , V_53 ) ;
F_24 ( & V_13 -> V_54 , V_55 ) ;
V_13 -> V_56 . V_29 = F_25 ( & V_22 -> V_28 ) ;
V_13 -> V_57 = V_22 ;
V_13 -> V_24 = V_24 ;
V_13 -> V_58 = V_59 ;
V_13 -> type = - 1 ;
V_13 -> V_60 = 1 ;
if ( F_26 ( V_5 ) )
V_13 -> V_61 = F_27 ( V_13 ) ;
else
V_13 -> V_61 = F_28 ( V_13 ) ;
if ( ! V_13 -> V_61 ) {
F_29 ( & V_22 -> V_28 ) ;
F_14 ( V_13 ) ;
goto V_33;
}
F_30 ( ! F_31 ( V_13 -> V_61 ) ) ;
V_13 -> V_61 -> V_62 = V_13 ;
if ( ! F_26 ( V_13 -> V_38 ) ) {
F_32 ( V_13 -> V_61 ,
V_13 -> V_38 -> V_63 , V_5 -> V_64 ,
V_5 -> V_65 -> V_66 ) ;
}
F_33 ( V_13 , V_13 -> V_38 -> V_63 ?
V_13 -> V_38 -> V_63 : 1 ) ;
F_34 ( V_13 ) ;
if ( V_5 -> V_65 -> V_67 ) {
V_26 = V_5 -> V_65 -> V_67 ( V_13 ) ;
if ( V_26 ) {
if ( V_26 == - V_68 )
V_25 = 0 ;
goto V_69;
}
}
return V_13 ;
V_69:
F_35 ( V_13 ) ;
V_33:
if ( V_25 )
F_9 ( V_70 , V_71 ) ;
return NULL ;
}
static void F_36 ( struct V_21 * V_22 )
{
struct V_72 * V_28 = & V_22 -> V_28 ;
struct V_27 * V_5 = F_19 ( V_28 -> V_29 ) ;
unsigned long V_73 ;
F_37 ( V_22 -> V_74 == V_75 ) ;
V_22 -> V_74 = V_75 ;
F_38 ( V_28 ) ;
F_39 ( V_5 -> V_76 , V_73 ) ;
if ( V_5 -> V_65 -> V_77 )
V_5 -> V_65 -> V_77 ( V_22 ) ;
F_40 ( & V_22 -> V_45 ) ;
F_41 ( V_5 -> V_76 , V_73 ) ;
F_29 ( V_28 ) ;
}
static void F_42 ( struct V_72 * V_28 )
{
struct V_72 * V_29 = V_28 -> V_29 ;
struct V_21 * V_22 = F_43 ( V_28 ) ;
F_14 ( V_22 ) ;
F_29 ( V_29 ) ;
}
int F_44 ( const struct V_72 * V_28 )
{
return V_28 -> type == & V_78 ;
}
static struct V_21 * F_45 ( struct V_72 * V_29 ,
int V_42 , T_2 V_41 )
{
struct V_21 * V_22 , * V_79 = NULL ;
struct V_27 * V_5 = F_19 ( V_29 ) ;
F_46 (starget, &shost->__targets, siblings) {
if ( V_22 -> V_41 == V_41 &&
V_22 -> V_42 == V_42 ) {
V_79 = V_22 ;
break;
}
}
if ( V_79 )
F_25 ( & V_79 -> V_28 ) ;
return V_79 ;
}
static void F_47 ( struct V_80 * V_80 )
{
struct V_21 * V_22
= F_48 ( V_80 , struct V_21 , V_81 ) ;
if ( V_22 -> V_74 != V_82 ) {
F_49 ( & V_22 -> V_28 ) ;
F_50 ( & V_22 -> V_28 ) ;
}
F_36 ( V_22 ) ;
}
static void F_51 ( struct V_21 * V_22 )
{
F_52 ( & V_22 -> V_81 , F_47 ) ;
}
static struct V_21 * F_53 ( struct V_72 * V_29 ,
int V_42 , T_2 V_41 )
{
struct V_27 * V_5 = F_19 ( V_29 ) ;
struct V_72 * V_28 = NULL ;
unsigned long V_73 ;
const int V_83 = sizeof( struct V_21 )
+ V_5 -> V_30 -> V_84 ;
struct V_21 * V_22 ;
struct V_21 * V_85 ;
int error , V_86 ;
V_22 = F_20 ( V_83 , V_4 ) ;
if ( ! V_22 ) {
F_9 ( V_87 L_3 , V_71 ) ;
return NULL ;
}
V_28 = & V_22 -> V_28 ;
F_54 ( V_28 ) ;
F_55 ( & V_22 -> V_81 ) ;
V_28 -> V_29 = F_25 ( V_29 ) ;
F_56 ( V_28 , L_4 , V_5 -> V_88 , V_42 , V_41 ) ;
V_28 -> V_89 = & V_90 ;
V_28 -> type = & V_78 ;
V_22 -> V_41 = V_41 ;
V_22 -> V_42 = V_42 ;
V_22 -> V_91 = 0 ;
F_21 ( & V_22 -> V_45 ) ;
F_21 ( & V_22 -> V_92 ) ;
V_22 -> V_74 = V_82 ;
V_22 -> V_93 = V_94 ;
V_22 -> V_95 = V_96 ;
V_97:
F_39 ( V_5 -> V_76 , V_73 ) ;
V_85 = F_45 ( V_29 , V_42 , V_41 ) ;
if ( V_85 )
goto V_98;
F_7 ( & V_22 -> V_45 , & V_5 -> V_99 ) ;
F_41 ( V_5 -> V_76 , V_73 ) ;
F_57 ( V_28 ) ;
if ( V_5 -> V_65 -> V_100 ) {
error = V_5 -> V_65 -> V_100 ( V_22 ) ;
if( error ) {
F_58 ( V_87 , V_28 , L_5 , error ) ;
F_36 ( V_22 ) ;
return NULL ;
}
}
F_25 ( V_28 ) ;
return V_22 ;
V_98:
V_86 = F_59 ( & V_85 -> V_81 ) ;
F_41 ( V_5 -> V_76 , V_73 ) ;
if ( V_86 ) {
F_29 ( V_28 ) ;
return V_85 ;
}
F_29 ( & V_85 -> V_28 ) ;
F_4 ( 1 ) ;
goto V_97;
}
void F_60 ( struct V_21 * V_22 )
{
F_37 ( V_22 -> V_74 == V_75 ) ;
F_51 ( V_22 ) ;
}
void F_61 ( unsigned char * V_101 , int V_102 )
{
int V_103 = 0 ;
for (; V_102 > 0 ; ( -- V_102 , ++ V_101 ) ) {
if ( * V_101 == 0 )
V_103 = 1 ;
if ( V_103 || * V_101 < 0x20 || * V_101 > 0x7e )
* V_101 = ' ' ;
}
}
static int F_62 ( struct V_12 * V_13 , unsigned char * V_104 ,
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
F_63 ( 3 , F_16 ( V_10 , V_13 ,
L_6 ,
V_111 , V_108 ) ) ;
for ( V_112 = 0 ; V_112 < 3 ; ++ V_112 ) {
int V_117 ;
memset ( V_15 , 0 , 6 ) ;
V_15 [ 0 ] = V_118 ;
V_15 [ 4 ] = ( unsigned char ) V_108 ;
memset ( V_104 , 0 , V_108 ) ;
V_14 = F_17 ( V_13 , V_15 , V_19 ,
V_104 , V_108 , & V_114 ,
V_119 / 2 + V_119 * V_120 , 3 ,
& V_117 ) ;
F_63 ( 3 , F_16 ( V_10 , V_13 ,
L_7 ,
V_14 ? L_8 : L_9 , V_14 ) ) ;
if ( V_14 ) {
if ( ( F_64 ( V_14 ) & V_121 ) &&
F_65 ( & V_114 ) ) {
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
F_61 ( & V_104 [ 8 ] , 8 ) ;
F_61 ( & V_104 [ 16 ] , 16 ) ;
F_61 ( & V_104 [ 32 ] , 4 ) ;
V_110 = V_104 [ 4 ] + 5 ;
if ( V_110 > 255 )
V_110 = V_107 ;
* V_106 = F_66 ( V_13 , & V_104 [ 8 ] ,
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
F_16 ( V_10 , V_13 ,
L_10
L_11 ,
V_108 ) ;
V_108 = V_107 ;
V_111 = 3 ;
goto V_116;
}
if ( V_14 )
return - V_128 ;
V_13 -> V_115 = F_67 ( V_108 , V_110 ) ;
if ( V_13 -> V_115 < 36 ) {
if ( ! V_13 -> V_38 -> V_129 ) {
F_68 ( V_10 , V_13 -> V_38 ,
L_12
L_13 , V_13 -> V_115 ) ;
V_13 -> V_38 -> V_129 = 1 ;
}
V_13 -> V_115 = 36 ;
}
V_13 -> V_93 = V_104 [ 2 ] & 0x07 ;
if ( V_13 -> V_93 >= 2 ||
( V_13 -> V_93 == 1 && ( V_104 [ 3 ] & 0x0f ) == 1 ) )
V_13 -> V_93 ++ ;
V_13 -> V_57 -> V_93 = V_13 -> V_93 ;
V_13 -> V_130 = 0 ;
if ( V_13 -> V_93 <= V_94 &&
V_13 -> V_93 != V_131 &&
! V_13 -> V_38 -> V_132 )
V_13 -> V_130 = 1 ;
return 0 ;
}
static int F_69 ( struct V_12 * V_13 , unsigned char * V_104 ,
int * V_106 , int V_133 )
{
int V_26 ;
V_13 -> V_134 = F_70 ( V_104 ,
F_71 ( V_135 , V_13 -> V_115 , 36 ) ,
V_32 ) ;
if ( V_13 -> V_134 == NULL )
return V_136 ;
V_13 -> V_34 = ( char * ) ( V_13 -> V_134 + 8 ) ;
V_13 -> V_36 = ( char * ) ( V_13 -> V_134 + 16 ) ;
V_13 -> V_37 = ( char * ) ( V_13 -> V_134 + 32 ) ;
if ( strncmp ( V_13 -> V_34 , L_14 , 8 ) == 0 ) {
V_13 -> V_137 = 1 ;
}
if ( * V_106 & V_138 ) {
V_13 -> type = V_139 ;
V_13 -> V_140 = 1 ;
} else {
V_13 -> type = ( V_104 [ 0 ] & 0x1f ) ;
V_13 -> V_140 = ( V_104 [ 1 ] & 0x80 ) >> 7 ;
if ( F_72 ( V_13 -> V_23 ) && V_13 -> type != V_141 ) {
F_16 ( V_142 , V_13 ,
L_15 ,
V_71 , V_13 -> type , ( unsigned int ) V_13 -> V_23 ) ;
V_13 -> type = V_141 ;
}
}
if ( V_13 -> type == V_143 || V_13 -> type == V_139 ) {
if ( ( * V_106 & V_144 ) == 0 )
* V_106 |= V_145 ;
}
V_13 -> V_146 = ( V_104 [ 0 ] >> 5 ) & 7 ;
V_13 -> V_147 = V_13 -> V_140 ;
V_13 -> V_148 = ( V_104 [ 7 ] & 1 ) && ( ( V_104 [ 3 ] & 7 ) == 2 ) ;
if ( V_13 -> V_93 >= V_149 ||
( V_13 -> V_115 > 56 && V_104 [ 56 ] & 0x04 ) )
V_13 -> V_150 = 1 ;
if ( V_104 [ 7 ] & 0x60 )
V_13 -> V_151 = 1 ;
if ( V_104 [ 7 ] & 0x10 )
V_13 -> V_152 = 1 ;
F_16 ( V_17 , V_13 , L_16
L_17 , F_73 ( V_13 -> type ) ,
V_13 -> V_34 , V_13 -> V_36 , V_13 -> V_37 ,
V_13 -> V_146 , V_104 [ 2 ] & 0x07 ,
( V_104 [ 3 ] & 0x0f ) == 1 ? L_18 : L_19 ) ;
if ( ( V_13 -> V_93 >= V_94 ) && ( V_104 [ 7 ] & 2 ) &&
! ( * V_106 & V_153 ) ) {
V_13 -> V_154 = 1 ;
V_13 -> V_155 = 1 ;
}
if ( ( * V_106 & V_156 ) == 0 )
V_13 -> V_60 = 0 ;
if ( * V_106 & V_157 )
V_13 -> V_158 = 1 ;
if ( * V_106 & V_159 )
V_13 -> V_160 = 1 ;
if ( * V_106 & V_161 )
F_74 ( V_13 -> V_61 , 512 ) ;
else if ( * V_106 & V_162 )
F_74 ( V_13 -> V_61 , 1024 ) ;
if ( * V_106 & V_163 )
V_13 -> V_164 = 1 ;
if ( * V_106 & V_165 )
V_21 ( V_13 ) -> V_166 = 1 ;
V_13 -> V_167 = 1 ;
if ( * V_106 & V_168 )
V_13 -> V_169 = 1 ;
if ( * V_106 & V_170 )
V_13 -> V_171 = 1 ;
if ( * V_106 & V_172 )
V_13 -> V_173 = 1 ;
if ( * V_106 & V_174 )
V_13 -> V_175 = 1 ;
V_26 = F_75 ( V_13 , V_176 ) ;
if ( V_26 ) {
V_26 = F_75 ( V_13 , V_177 ) ;
if ( V_26 ) {
F_16 ( V_87 , V_13 ,
L_20 ,
F_76 ( V_13 -> V_43 ) ) ;
return V_136 ;
}
}
if ( * V_106 & V_178 )
V_13 -> V_179 = 1 ;
if ( * V_106 & V_180 )
V_13 -> V_147 = 0 ;
if ( * V_106 & V_181 )
V_13 -> V_182 = 1 ;
if ( * V_106 & V_183 )
V_13 -> V_184 = 1 ;
if ( * V_106 & V_185 )
V_13 -> V_186 = 1 ;
V_13 -> V_187 = V_188 ;
if ( * V_106 & V_189 )
V_13 -> V_190 = 1 ;
else if ( * V_106 & V_191 )
V_13 -> V_192 = 1 ;
F_77 ( & V_13 -> V_56 ) ;
if ( V_13 -> V_38 -> V_65 -> V_193 ) {
V_26 = V_13 -> V_38 -> V_65 -> V_193 ( V_13 ) ;
if ( V_26 ) {
if ( V_26 != - V_68 ) {
F_16 ( V_87 , V_13 ,
L_21 ) ;
}
return V_136 ;
}
}
if ( V_13 -> V_93 >= V_149 )
F_78 ( V_13 ) ;
V_13 -> V_194 = V_13 -> V_195 ;
if ( ! V_133 && F_79 ( V_13 ) != 0 )
return V_136 ;
return V_196 ;
}
static unsigned char * F_80 ( unsigned char * V_197 , unsigned char * V_198 ,
unsigned V_199 , unsigned V_200 )
{
unsigned V_201 = 0 , V_202 ;
for ( V_202 = 0 ; V_202 + V_199 < V_200 && V_202 + V_199 < V_198 [ 4 ] + 5 ; V_202 ++ ) {
if ( V_198 [ V_202 + V_199 ] > ' ' ) {
V_197 [ V_202 ] = V_198 [ V_202 + V_199 ] ;
V_201 = V_202 + 1 ;
} else {
V_197 [ V_202 ] = ' ' ;
}
}
V_197 [ V_201 ] = 0 ;
return V_197 ;
}
static int F_81 ( struct V_21 * V_22 ,
T_1 V_23 , int * V_203 ,
struct V_12 * * V_204 ,
enum V_205 V_206 ,
void * V_24 )
{
struct V_12 * V_13 ;
unsigned char * V_14 ;
int V_106 , V_207 = V_136 , V_105 = 256 ;
struct V_27 * V_5 = F_19 ( V_22 -> V_28 . V_29 ) ;
V_13 = F_82 ( V_22 , V_23 ) ;
if ( V_13 ) {
if ( V_206 != V_208 || ! F_83 ( V_13 ) ) {
F_63 ( 3 , F_16 ( V_10 , V_13 ,
L_22 ,
F_84 ( & V_13 -> V_56 ) ) ) ;
if ( V_204 )
* V_204 = V_13 ;
else
F_85 ( V_13 ) ;
if ( V_203 )
* V_203 = F_66 ( V_13 ,
V_13 -> V_34 ,
V_13 -> V_36 ) ;
return V_196 ;
}
F_85 ( V_13 ) ;
} else
V_13 = F_18 ( V_22 , V_23 , V_24 ) ;
if ( ! V_13 )
goto V_33;
V_14 = F_3 ( V_105 , V_32 |
( ( V_5 -> V_209 ) ? V_210 : 0 ) ) ;
if ( ! V_14 )
goto V_211;
if ( F_62 ( V_13 , V_14 , V_105 , & V_106 ) )
goto V_212;
if ( V_203 )
* V_203 = V_106 ;
if ( ( ( V_14 [ 0 ] >> 5 ) == 3 ) && ! ( V_106 & V_213 ) ) {
F_63 ( 2 , sdev_printk(KERN_INFO, sdev, L_23
L_24
L_25))
if ( V_23 == 0 ) {
F_63 ( 1 , {
unsigned char vend[9];
unsigned char mod[17];
sdev_printk(KERN_INFO, sdev,
L_26
L_27,
scsi_inq_str(vend, result, 8, 16),
scsi_inq_str(mod, result, 16, 32));
}) ;
}
V_207 = V_214 ;
goto V_212;
}
if ( ( ( V_14 [ 0 ] >> 5 ) == 1 || V_22 -> V_215 ) &&
( V_14 [ 0 ] & 0x1f ) == 0x1f &&
! F_72 ( V_23 ) ) {
F_63 ( 3 , F_16 ( V_10 , V_13 ,
L_28
L_29 ) ) ;
V_207 = V_214 ;
goto V_212;
}
V_207 = F_69 ( V_13 , V_14 , & V_106 , V_5 -> V_216 ) ;
if ( V_207 == V_196 ) {
if ( V_106 & V_217 ) {
V_13 -> V_147 = 0 ;
F_15 ( V_13 , V_14 ) ;
}
}
V_212:
F_14 ( V_14 ) ;
V_211:
if ( V_207 == V_196 ) {
if ( V_204 ) {
if ( F_86 ( V_13 ) == 0 ) {
* V_204 = V_13 ;
} else {
F_35 ( V_13 ) ;
V_207 = V_136 ;
}
}
} else
F_35 ( V_13 ) ;
V_33:
return V_207 ;
}
static void F_87 ( struct V_21 * V_22 ,
int V_106 , int V_93 ,
enum V_205 V_206 )
{
T_2 V_218 ;
T_1 V_219 , V_23 ;
struct V_27 * V_5 = F_19 ( V_22 -> V_28 . V_29 ) ;
F_63 ( 3 , F_88 ( V_10 , V_22 ,
L_30 ) ) ;
V_218 = F_67 ( V_220 , V_5 -> V_221 ) ;
if ( V_106 & V_222 ) {
V_218 = V_5 -> V_221 ;
V_219 = 1 ;
} else
V_219 = 0 ;
if ( V_106 & V_223 )
V_218 = V_5 -> V_221 ;
if ( V_106 & V_224 )
V_218 = F_67 ( 5U , V_218 ) ;
if ( V_93 < V_149 && ! ( V_106 & V_225 ) )
V_218 = F_67 ( 8U , V_218 ) ;
if ( ! ( V_106 & V_226 ) )
V_218 = F_67 ( 256U , V_218 ) ;
for ( V_23 = 1 ; V_23 < V_218 ; ++ V_23 )
if ( ( F_81 ( V_22 , V_23 , NULL , NULL , V_206 ,
NULL ) != V_196 ) &&
! V_219 )
return;
}
static int F_89 ( struct V_21 * V_22 , int V_106 ,
enum V_205 V_206 )
{
unsigned char V_15 [ V_16 ] ;
unsigned int V_227 ;
T_1 V_23 ;
unsigned int V_228 ;
unsigned int V_229 ;
int V_14 ;
struct V_230 * V_231 , * V_232 ;
struct V_113 V_114 ;
struct V_12 * V_13 ;
struct V_27 * V_5 = F_19 ( & V_22 -> V_28 ) ;
int V_26 = 0 ;
if ( V_106 & V_145 )
return 1 ;
if ( V_22 -> V_93 < V_94 &&
V_22 -> V_93 != V_131 )
return 1 ;
if ( V_22 -> V_93 < V_149 &&
( ! ( V_106 & V_144 ) || V_5 -> V_221 <= 8 ) )
return 1 ;
if ( V_106 & V_233 )
return 0 ;
if ( V_22 -> V_234 )
return 1 ;
if ( ! ( V_13 = F_82 ( V_22 , 0 ) ) ) {
V_13 = F_18 ( V_22 , 0 , NULL ) ;
if ( ! V_13 )
return 0 ;
if ( F_86 ( V_13 ) ) {
F_35 ( V_13 ) ;
return 0 ;
}
}
V_227 = ( 511 + 1 ) * sizeof( struct V_230 ) ;
V_97:
V_232 = F_3 ( V_227 , V_4 |
( V_13 -> V_38 -> V_209 ? V_210 : 0 ) ) ;
if ( ! V_232 ) {
F_9 ( V_70 , V_71 ) ;
goto V_33;
}
V_15 [ 0 ] = V_235 ;
memset ( & V_15 [ 1 ] , 0 , 5 ) ;
F_90 ( V_227 , & V_15 [ 6 ] ) ;
V_15 [ 10 ] = 0 ;
V_15 [ 11 ] = 0 ;
for ( V_229 = 0 ; V_229 < 3 ; V_229 ++ ) {
F_63 ( 3 , F_16 ( V_10 , V_13 ,
L_31 ,
V_229 ) ) ;
V_14 = F_17 ( V_13 , V_15 , V_19 ,
V_232 , V_227 , & V_114 ,
V_236 , 3 , NULL ) ;
F_63 ( 3 , F_16 ( V_10 , V_13 ,
L_32
L_33 ,
V_14 ? L_8 : L_9 ,
V_229 , V_14 ) ) ;
if ( V_14 == 0 )
break;
else if ( F_65 ( & V_114 ) ) {
if ( V_114 . V_122 != V_123 )
break;
}
}
if ( V_14 ) {
V_26 = 1 ;
goto V_237;
}
if ( F_91 ( V_232 -> V_230 ) +
sizeof( struct V_230 ) > V_227 ) {
V_227 = F_91 ( V_232 -> V_230 ) +
sizeof( struct V_230 ) ;
F_14 ( V_232 ) ;
goto V_97;
}
V_227 = F_91 ( V_232 -> V_230 ) ;
V_228 = ( V_227 / sizeof( struct V_230 ) ) ;
F_63 ( 3 , F_16 ( V_10 , V_13 ,
L_34 ) ) ;
for ( V_231 = & V_232 [ 1 ] ; V_231 <= & V_232 [ V_228 ] ; V_231 ++ ) {
V_23 = F_92 ( V_231 ) ;
if ( V_23 > V_13 -> V_38 -> V_221 ) {
F_16 ( V_142 , V_13 ,
L_35
L_36 , V_23 ) ;
} else {
int V_207 ;
V_207 = F_81 ( V_22 ,
V_23 , NULL , NULL , V_206 , NULL ) ;
if ( V_207 == V_136 ) {
F_16 ( V_87 , V_13 ,
L_37
L_38
L_39 , ( unsigned long long ) V_23 ) ;
break;
}
}
}
V_237:
F_14 ( V_232 ) ;
V_33:
if ( F_83 ( V_13 ) )
F_35 ( V_13 ) ;
F_85 ( V_13 ) ;
return V_26 ;
}
struct V_12 * F_93 ( struct V_27 * V_5 , T_2 V_42 ,
T_2 V_41 , T_1 V_23 , void * V_24 )
{
struct V_12 * V_13 = F_94 ( - V_238 ) ;
struct V_72 * V_29 = & V_5 -> V_239 ;
struct V_21 * V_22 ;
if ( strncmp ( V_240 , L_40 , 4 ) == 0 )
return F_94 ( - V_238 ) ;
V_22 = F_53 ( V_29 , V_42 , V_41 ) ;
if ( ! V_22 )
return F_94 ( - V_241 ) ;
F_95 ( V_22 ) ;
F_96 ( & V_5 -> V_242 ) ;
if ( ! V_5 -> V_216 )
F_1 () ;
if ( F_97 ( V_5 ) && F_98 ( V_5 ) == 0 ) {
F_81 ( V_22 , V_23 , NULL , & V_13 , 1 , V_24 ) ;
F_99 ( V_5 ) ;
}
F_100 ( & V_5 -> V_242 ) ;
F_101 ( V_22 ) ;
F_60 ( V_22 ) ;
F_29 ( & V_22 -> V_28 ) ;
return V_13 ;
}
int F_102 ( struct V_27 * V_38 , T_2 V_42 ,
T_2 V_243 , T_1 V_23 )
{
struct V_12 * V_13 =
F_93 ( V_38 , V_42 , V_243 , V_23 , NULL ) ;
if ( F_103 ( V_13 ) )
return F_104 ( V_13 ) ;
F_85 ( V_13 ) ;
return 0 ;
}
void F_105 ( struct V_72 * V_28 )
{
struct V_12 * V_13 = F_106 ( V_28 ) ;
F_107 ( V_28 ) ;
F_78 ( V_13 ) ;
if ( V_13 -> V_244 && V_13 -> V_244 -> V_206 )
V_13 -> V_244 -> V_206 ( V_13 ) ;
if ( V_28 -> V_245 && F_108 ( V_28 -> V_245 -> V_246 ) ) {
struct V_247 * V_248 = F_109 ( V_28 -> V_245 ) ;
if ( V_248 -> V_206 )
V_248 -> V_206 ( V_28 ) ;
F_110 ( V_28 -> V_245 -> V_246 ) ;
}
F_111 ( V_28 ) ;
}
static void F_112 ( struct V_72 * V_29 , unsigned int V_42 ,
unsigned int V_41 , T_1 V_23 , enum V_205 V_206 )
{
struct V_27 * V_5 = F_19 ( V_29 ) ;
int V_106 = 0 ;
int V_207 ;
struct V_21 * V_22 ;
if ( V_5 -> V_249 == V_41 )
return;
V_22 = F_53 ( V_29 , V_42 , V_41 ) ;
if ( ! V_22 )
return;
F_95 ( V_22 ) ;
if ( V_23 != V_250 ) {
F_81 ( V_22 , V_23 , NULL , NULL , V_206 , NULL ) ;
goto V_251;
}
V_207 = F_81 ( V_22 , 0 , & V_106 , NULL , V_206 , NULL ) ;
if ( V_207 == V_196 || V_207 == V_214 ) {
if ( F_89 ( V_22 , V_106 , V_206 ) != 0 )
F_87 ( V_22 , V_106 ,
V_22 -> V_93 , V_206 ) ;
}
V_251:
F_101 ( V_22 ) ;
F_60 ( V_22 ) ;
F_29 ( & V_22 -> V_28 ) ;
}
void F_113 ( struct V_72 * V_29 , unsigned int V_42 ,
unsigned int V_41 , T_1 V_23 , enum V_205 V_206 )
{
struct V_27 * V_5 = F_19 ( V_29 ) ;
if ( strncmp ( V_240 , L_40 , 4 ) == 0 )
return;
if ( V_206 != V_252 &&
strncmp ( V_240 , L_41 , 6 ) == 0 )
return;
F_96 ( & V_5 -> V_242 ) ;
if ( ! V_5 -> V_216 )
F_1 () ;
if ( F_97 ( V_5 ) && F_98 ( V_5 ) == 0 ) {
F_112 ( V_29 , V_42 , V_41 , V_23 , V_206 ) ;
F_99 ( V_5 ) ;
}
F_100 ( & V_5 -> V_242 ) ;
}
static void F_114 ( struct V_27 * V_5 , unsigned int V_42 ,
unsigned int V_41 , T_1 V_23 ,
enum V_205 V_206 )
{
T_2 V_253 ;
if ( V_41 == V_250 )
for ( V_41 = 0 ; V_41 < V_5 -> V_254 ; ++ V_41 ) {
if ( V_5 -> V_255 )
V_253 = V_5 -> V_254 - V_41 - 1 ;
else
V_253 = V_41 ;
F_112 ( & V_5 -> V_239 , V_42 ,
V_253 , V_23 , V_206 ) ;
}
else
F_112 ( & V_5 -> V_239 , V_42 ,
V_41 , V_23 , V_206 ) ;
}
int F_115 ( struct V_27 * V_5 , unsigned int V_42 ,
unsigned int V_41 , T_1 V_23 ,
enum V_205 V_206 )
{
F_63 ( 3 , F_68 ( V_10 , V_5 ,
L_42 ,
V_71 , V_42 , V_41 , V_23 ) ) ;
if ( ( ( V_42 != V_250 ) && ( V_42 > V_5 -> V_256 ) ) ||
( ( V_41 != V_250 ) && ( V_41 >= V_5 -> V_254 ) ) ||
( ( V_23 != V_250 ) && ( V_23 >= V_5 -> V_221 ) ) )
return - V_257 ;
F_96 ( & V_5 -> V_242 ) ;
if ( ! V_5 -> V_216 )
F_1 () ;
if ( F_97 ( V_5 ) && F_98 ( V_5 ) == 0 ) {
if ( V_42 == V_250 )
for ( V_42 = 0 ; V_42 <= V_5 -> V_256 ;
V_42 ++ )
F_114 ( V_5 , V_42 , V_41 , V_23 ,
V_206 ) ;
else
F_114 ( V_5 , V_42 , V_41 , V_23 , V_206 ) ;
F_99 ( V_5 ) ;
}
F_100 ( & V_5 -> V_242 ) ;
return 0 ;
}
static void F_116 ( struct V_27 * V_5 )
{
struct V_12 * V_13 ;
F_117 (sdev, shost) {
if ( V_13 -> V_43 == V_258 )
continue;
if ( V_13 -> V_259 )
continue;
if ( ! F_97 ( V_5 ) ||
F_79 ( V_13 ) != 0 )
F_35 ( V_13 ) ;
}
}
static struct V_1 * F_118 ( struct V_27 * V_5 )
{
struct V_1 * V_2 ;
unsigned long V_73 ;
if ( strncmp ( V_240 , L_43 , 4 ) == 0 )
return NULL ;
if ( V_5 -> V_216 ) {
F_68 ( V_260 , V_5 , L_44 , V_71 ) ;
return NULL ;
}
V_2 = F_3 ( sizeof( * V_2 ) , V_4 ) ;
if ( ! V_2 )
goto V_261;
V_2 -> V_5 = F_119 ( V_5 ) ;
if ( ! V_2 -> V_5 )
goto V_261;
F_5 ( & V_2 -> V_6 ) ;
F_96 ( & V_5 -> V_242 ) ;
F_39 ( V_5 -> V_76 , V_73 ) ;
V_5 -> V_216 = 1 ;
F_41 ( V_5 -> V_76 , V_73 ) ;
F_100 ( & V_5 -> V_242 ) ;
F_6 ( & V_7 ) ;
if ( F_2 ( & V_3 ) )
F_13 ( & V_2 -> V_6 ) ;
F_7 ( & V_2 -> V_9 , & V_3 ) ;
F_8 ( & V_7 ) ;
return V_2 ;
V_261:
F_14 ( V_2 ) ;
return NULL ;
}
static void F_120 ( struct V_1 * V_2 )
{
struct V_27 * V_5 ;
unsigned long V_73 ;
if ( ! V_2 )
return;
V_5 = V_2 -> V_5 ;
F_96 ( & V_5 -> V_242 ) ;
if ( ! V_5 -> V_216 ) {
F_68 ( V_10 , V_5 , L_44 , V_71 ) ;
F_121 () ;
F_100 ( & V_5 -> V_242 ) ;
return;
}
F_10 ( & V_2 -> V_6 ) ;
F_116 ( V_5 ) ;
F_39 ( V_5 -> V_76 , V_73 ) ;
V_5 -> V_216 = 0 ;
F_41 ( V_5 -> V_76 , V_73 ) ;
F_100 ( & V_5 -> V_242 ) ;
F_6 ( & V_7 ) ;
F_11 ( & V_2 -> V_9 ) ;
if ( ! F_2 ( & V_3 ) ) {
struct V_1 * V_11 = F_12 ( V_3 . V_11 ,
struct V_1 , V_9 ) ;
F_13 ( & V_11 -> V_6 ) ;
}
F_8 ( & V_7 ) ;
F_99 ( V_5 ) ;
F_122 ( V_5 ) ;
F_14 ( V_2 ) ;
}
static void F_123 ( struct V_27 * V_5 )
{
if ( V_5 -> V_65 -> V_262 ) {
unsigned long V_263 = V_264 ;
if ( V_5 -> V_65 -> V_265 )
V_5 -> V_65 -> V_265 ( V_5 ) ;
while ( ! V_5 -> V_65 -> V_262 ( V_5 , V_264 - V_263 ) )
F_4 ( 10 ) ;
} else {
F_115 ( V_5 , V_250 , V_250 ,
V_250 , 0 ) ;
}
}
static void F_124 ( void * V_266 , T_3 V_267 )
{
struct V_1 * V_2 = V_266 ;
struct V_27 * V_5 = V_2 -> V_5 ;
F_123 ( V_5 ) ;
F_120 ( V_2 ) ;
}
void F_125 ( struct V_27 * V_5 )
{
struct V_1 * V_2 ;
if ( strncmp ( V_240 , L_40 , 4 ) == 0 ||
strncmp ( V_240 , L_41 , 6 ) == 0 )
return;
if ( F_98 ( V_5 ) < 0 )
return;
V_2 = F_118 ( V_5 ) ;
if ( ! V_2 ) {
F_123 ( V_5 ) ;
F_99 ( V_5 ) ;
return;
}
F_126 ( F_124 , V_2 ) ;
}
void F_127 ( struct V_27 * V_5 )
{
struct V_12 * V_13 ;
unsigned long V_73 ;
V_268:
F_39 ( V_5 -> V_76 , V_73 ) ;
F_46 (sdev, &shost->__devices, siblings) {
if ( V_13 -> V_43 == V_258 )
continue;
F_41 ( V_5 -> V_76 , V_73 ) ;
F_35 ( V_13 ) ;
goto V_268;
}
F_41 ( V_5 -> V_76 , V_73 ) ;
}
struct V_12 * F_128 ( struct V_27 * V_5 )
{
struct V_12 * V_13 = NULL ;
struct V_21 * V_22 ;
F_96 ( & V_5 -> V_242 ) ;
if ( ! F_97 ( V_5 ) )
goto V_33;
V_22 = F_53 ( & V_5 -> V_239 , 0 , V_5 -> V_249 ) ;
if ( ! V_22 )
goto V_33;
V_13 = F_18 ( V_22 , 0 , NULL ) ;
if ( V_13 )
V_13 -> V_60 = 0 ;
else
F_60 ( V_22 ) ;
F_29 ( & V_22 -> V_28 ) ;
V_33:
F_100 ( & V_5 -> V_242 ) ;
return V_13 ;
}
void F_129 ( struct V_12 * V_13 )
{
F_37 ( V_13 -> V_41 != V_13 -> V_38 -> V_249 ) ;
F_35 ( V_13 ) ;
}
