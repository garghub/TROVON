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
extern void V_30 ( struct V_31 * V_32 ) ;
extern void V_33 ( struct V_31 * V_32 ) ;
V_13 = F_20 ( sizeof( * V_13 ) + V_5 -> V_34 -> V_35 ,
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
F_21 ( & V_13 -> V_49 ) ;
F_21 ( & V_13 -> V_50 ) ;
F_21 ( & V_13 -> V_51 ) ;
F_21 ( & V_13 -> V_52 ) ;
F_21 ( & V_13 -> V_53 ) ;
F_22 ( & V_13 -> V_54 ) ;
F_23 ( & V_13 -> V_55 , V_30 ) ;
F_23 ( & V_13 -> V_56 , V_33 ) ;
V_13 -> V_57 . V_29 = F_24 ( & V_22 -> V_28 ) ;
V_13 -> V_58 = V_22 ;
V_13 -> V_24 = V_24 ;
V_13 -> V_59 = V_60 ;
V_13 -> type = - 1 ;
V_13 -> V_61 = 1 ;
if ( F_25 ( V_5 ) )
V_13 -> V_62 = F_26 ( V_13 ) ;
else
V_13 -> V_62 = F_27 ( V_13 ) ;
if ( ! V_13 -> V_62 ) {
F_28 ( & V_22 -> V_28 ) ;
F_14 ( V_13 ) ;
goto V_37;
}
F_29 ( ! F_30 ( V_13 -> V_62 ) ) ;
V_13 -> V_62 -> V_63 = V_13 ;
if ( ! F_25 ( V_13 -> V_42 ) &&
( V_5 -> V_64 || V_5 -> V_65 -> V_66 ) ) {
F_31 ( V_13 -> V_62 ,
V_13 -> V_42 -> V_67 , V_5 -> V_64 ,
V_5 -> V_65 -> V_68 ) ;
}
F_32 ( V_13 , V_13 -> V_42 -> V_67 ?
V_13 -> V_42 -> V_67 : 1 ) ;
F_33 ( V_13 ) ;
if ( V_5 -> V_65 -> V_69 ) {
V_26 = V_5 -> V_65 -> V_69 ( V_13 ) ;
if ( V_26 ) {
if ( V_26 == - V_70 )
V_25 = 0 ;
goto V_71;
}
}
return V_13 ;
V_71:
F_34 ( V_13 ) ;
V_37:
if ( V_25 )
F_9 ( V_72 , V_73 ) ;
return NULL ;
}
static void F_35 ( struct V_21 * V_22 )
{
struct V_74 * V_28 = & V_22 -> V_28 ;
struct V_27 * V_5 = F_19 ( V_28 -> V_29 ) ;
unsigned long V_75 ;
V_22 -> V_76 = V_77 ;
F_36 ( V_28 ) ;
F_37 ( V_5 -> V_78 , V_75 ) ;
if ( V_5 -> V_65 -> V_79 )
V_5 -> V_65 -> V_79 ( V_22 ) ;
F_38 ( & V_22 -> V_49 ) ;
F_39 ( V_5 -> V_78 , V_75 ) ;
F_28 ( V_28 ) ;
}
static void F_40 ( struct V_74 * V_28 )
{
struct V_74 * V_29 = V_28 -> V_29 ;
struct V_21 * V_22 = F_41 ( V_28 ) ;
F_14 ( V_22 ) ;
F_28 ( V_29 ) ;
}
int F_42 ( const struct V_74 * V_28 )
{
return V_28 -> type == & V_80 ;
}
static struct V_21 * F_43 ( struct V_74 * V_29 ,
int V_46 , T_2 V_45 )
{
struct V_21 * V_22 , * V_81 = NULL ;
struct V_27 * V_5 = F_19 ( V_29 ) ;
F_44 (starget, &shost->__targets, siblings) {
if ( V_22 -> V_45 == V_45 &&
V_22 -> V_46 == V_46 ) {
V_81 = V_22 ;
break;
}
}
if ( V_81 )
F_24 ( & V_81 -> V_28 ) ;
return V_81 ;
}
static void F_45 ( struct V_82 * V_82 )
{
struct V_21 * V_22
= F_46 ( V_82 , struct V_21 , V_83 ) ;
if ( V_22 -> V_76 != V_84 ) {
F_47 ( & V_22 -> V_28 ) ;
F_48 ( & V_22 -> V_28 ) ;
}
F_35 ( V_22 ) ;
}
static void F_49 ( struct V_21 * V_22 )
{
F_50 ( & V_22 -> V_83 , F_45 ) ;
}
static struct V_21 * F_51 ( struct V_74 * V_29 ,
int V_46 , T_2 V_45 )
{
struct V_27 * V_5 = F_19 ( V_29 ) ;
struct V_74 * V_28 = NULL ;
unsigned long V_75 ;
const int V_85 = sizeof( struct V_21 )
+ V_5 -> V_34 -> V_86 ;
struct V_21 * V_22 ;
struct V_21 * V_87 ;
int error , V_88 ;
V_22 = F_20 ( V_85 , V_4 ) ;
if ( ! V_22 ) {
F_9 ( V_89 L_3 , V_73 ) ;
return NULL ;
}
V_28 = & V_22 -> V_28 ;
F_52 ( V_28 ) ;
F_53 ( & V_22 -> V_83 ) ;
V_28 -> V_29 = F_24 ( V_29 ) ;
F_54 ( V_28 , L_4 , V_5 -> V_90 , V_46 , V_45 ) ;
V_28 -> V_91 = & V_92 ;
V_28 -> type = & V_80 ;
V_22 -> V_45 = V_45 ;
V_22 -> V_46 = V_46 ;
V_22 -> V_93 = 0 ;
F_21 ( & V_22 -> V_49 ) ;
F_21 ( & V_22 -> V_94 ) ;
V_22 -> V_76 = V_84 ;
V_22 -> V_95 = V_96 ;
V_22 -> V_97 = V_98 ;
V_99:
F_37 ( V_5 -> V_78 , V_75 ) ;
V_87 = F_43 ( V_29 , V_46 , V_45 ) ;
if ( V_87 )
goto V_100;
F_7 ( & V_22 -> V_49 , & V_5 -> V_101 ) ;
F_39 ( V_5 -> V_78 , V_75 ) ;
F_55 ( V_28 ) ;
if ( V_5 -> V_65 -> V_102 ) {
error = V_5 -> V_65 -> V_102 ( V_22 ) ;
if( error ) {
F_56 ( V_89 , V_28 , L_5 , error ) ;
F_35 ( V_22 ) ;
return NULL ;
}
}
F_24 ( V_28 ) ;
return V_22 ;
V_100:
V_88 = F_57 ( & V_87 -> V_83 ) ;
F_39 ( V_5 -> V_78 , V_75 ) ;
if ( V_88 ) {
F_28 ( V_28 ) ;
return V_87 ;
}
F_28 ( & V_87 -> V_28 ) ;
F_4 ( 1 ) ;
goto V_99;
}
void F_58 ( struct V_21 * V_22 )
{
F_59 ( V_22 -> V_76 == V_77 ) ;
F_49 ( V_22 ) ;
}
static void F_60 ( unsigned char * V_103 , int V_104 )
{
int V_105 = 0 ;
for (; V_104 > 0 ; ( -- V_104 , ++ V_103 ) ) {
if ( * V_103 == 0 )
V_105 = 1 ;
if ( V_105 || * V_103 < 0x20 || * V_103 > 0x7e )
* V_103 = ' ' ;
}
}
static int F_61 ( struct V_12 * V_13 , unsigned char * V_106 ,
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
F_62 ( 3 , F_16 ( V_10 , V_13 ,
L_6 ,
V_113 , V_110 ) ) ;
for ( V_114 = 0 ; V_114 < 3 ; ++ V_114 ) {
int V_119 ;
memset ( V_15 , 0 , 6 ) ;
V_15 [ 0 ] = V_120 ;
V_15 [ 4 ] = ( unsigned char ) V_110 ;
memset ( V_106 , 0 , V_110 ) ;
V_14 = F_17 ( V_13 , V_15 , V_19 ,
V_106 , V_110 , & V_116 ,
V_121 / 2 + V_121 * V_122 , 3 ,
& V_119 ) ;
F_62 ( 3 , F_16 ( V_10 , V_13 ,
L_7 ,
V_14 ? L_8 : L_9 , V_14 ) ) ;
if ( V_14 ) {
if ( ( F_63 ( V_14 ) & V_123 ) &&
F_64 ( & V_116 ) ) {
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
F_60 ( & V_106 [ 8 ] , 8 ) ;
F_60 ( & V_106 [ 16 ] , 16 ) ;
F_60 ( & V_106 [ 32 ] , 4 ) ;
V_112 = V_106 [ 4 ] + 5 ;
if ( V_112 > 255 )
V_112 = V_109 ;
* V_108 = F_65 ( V_13 , & V_106 [ 8 ] ,
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
F_16 ( V_10 , V_13 ,
L_10
L_11 ,
V_110 ) ;
V_110 = V_109 ;
V_113 = 3 ;
goto V_118;
}
if ( V_14 )
return - V_130 ;
V_13 -> V_117 = F_66 ( V_110 , V_112 ) ;
if ( V_13 -> V_117 < 36 ) {
F_16 ( V_10 , V_13 ,
L_12
L_13 , V_13 -> V_117 ) ;
V_13 -> V_117 = 36 ;
}
V_13 -> V_95 = V_106 [ 2 ] & 0x07 ;
if ( V_13 -> V_95 >= 2 ||
( V_13 -> V_95 == 1 && ( V_106 [ 3 ] & 0x0f ) == 1 ) )
V_13 -> V_95 ++ ;
V_13 -> V_58 -> V_95 = V_13 -> V_95 ;
V_13 -> V_131 = 0 ;
if ( V_13 -> V_95 <= V_96 &&
V_13 -> V_95 != V_132 &&
! V_13 -> V_42 -> V_133 )
V_13 -> V_131 = 1 ;
return 0 ;
}
static int F_67 ( struct V_12 * V_13 , unsigned char * V_106 ,
int * V_108 , int V_134 )
{
int V_26 ;
V_13 -> V_135 = F_68 ( V_106 ,
F_69 ( V_136 , V_13 -> V_117 , 36 ) ,
V_36 ) ;
if ( V_13 -> V_135 == NULL )
return V_137 ;
V_13 -> V_38 = ( char * ) ( V_13 -> V_135 + 8 ) ;
V_13 -> V_40 = ( char * ) ( V_13 -> V_135 + 16 ) ;
V_13 -> V_41 = ( char * ) ( V_13 -> V_135 + 32 ) ;
if ( strncmp ( V_13 -> V_38 , L_14 , 8 ) == 0 ) {
V_13 -> V_138 = 1 ;
}
if ( * V_108 & V_139 ) {
V_13 -> type = V_140 ;
V_13 -> V_141 = 1 ;
} else {
V_13 -> type = ( V_106 [ 0 ] & 0x1f ) ;
V_13 -> V_141 = ( V_106 [ 1 ] & 0x80 ) >> 7 ;
if ( F_70 ( V_13 -> V_23 ) && V_13 -> type != V_142 ) {
F_16 ( V_143 , V_13 ,
L_15 ,
V_73 , V_13 -> type , ( unsigned int ) V_13 -> V_23 ) ;
V_13 -> type = V_142 ;
}
}
if ( V_13 -> type == V_144 || V_13 -> type == V_140 ) {
if ( ( * V_108 & V_145 ) == 0 )
* V_108 |= V_146 ;
}
V_13 -> V_147 = ( V_106 [ 0 ] >> 5 ) & 7 ;
V_13 -> V_148 = V_13 -> V_141 ;
V_13 -> V_149 = ( V_106 [ 7 ] & 1 ) && ( ( V_106 [ 3 ] & 7 ) == 2 ) ;
if ( V_13 -> V_95 >= V_150 ||
( V_13 -> V_117 > 56 && V_106 [ 56 ] & 0x04 ) )
V_13 -> V_151 = 1 ;
if ( V_106 [ 7 ] & 0x60 )
V_13 -> V_152 = 1 ;
if ( V_106 [ 7 ] & 0x10 )
V_13 -> V_153 = 1 ;
F_16 ( V_17 , V_13 , L_16
L_17 , F_71 ( V_13 -> type ) ,
V_13 -> V_38 , V_13 -> V_40 , V_13 -> V_41 ,
V_13 -> V_147 , V_106 [ 2 ] & 0x07 ,
( V_106 [ 3 ] & 0x0f ) == 1 ? L_18 : L_19 ) ;
if ( ( V_13 -> V_95 >= V_96 ) && ( V_106 [ 7 ] & 2 ) &&
! ( * V_108 & V_154 ) ) {
V_13 -> V_155 = 1 ;
V_13 -> V_156 = 1 ;
}
if ( ( * V_108 & V_157 ) == 0 )
V_13 -> V_61 = 0 ;
if ( * V_108 & V_158 )
V_13 -> V_159 = 1 ;
if ( * V_108 & V_160 )
V_13 -> V_161 = 1 ;
if ( * V_108 & V_162 )
F_72 ( V_13 -> V_62 , 512 ) ;
else if ( * V_108 & V_163 )
F_72 ( V_13 -> V_62 , 1024 ) ;
if ( * V_108 & V_164 )
V_13 -> V_165 = 1 ;
if ( * V_108 & V_166 )
V_21 ( V_13 ) -> V_167 = 1 ;
V_13 -> V_168 = 1 ;
if ( * V_108 & V_169 )
V_13 -> V_170 = 1 ;
if ( * V_108 & V_171 )
V_13 -> V_172 = 1 ;
if ( * V_108 & V_173 )
V_13 -> V_174 = 1 ;
if ( * V_108 & V_175 )
V_13 -> V_176 = 1 ;
V_26 = F_73 ( V_13 , V_177 ) ;
if ( V_26 ) {
V_26 = F_73 ( V_13 , V_178 ) ;
if ( V_26 ) {
F_16 ( V_89 , V_13 ,
L_20 ,
F_74 ( V_13 -> V_47 ) ) ;
return V_137 ;
}
}
if ( * V_108 & V_179 )
V_13 -> V_180 = 1 ;
if ( * V_108 & V_181 )
V_13 -> V_148 = 0 ;
if ( * V_108 & V_182 )
V_13 -> V_183 = 1 ;
if ( * V_108 & V_184 )
V_13 -> V_185 = 1 ;
V_13 -> V_186 = V_187 ;
if ( * V_108 & V_188 )
V_13 -> V_189 = 1 ;
else if ( * V_108 & V_190 )
V_13 -> V_191 = 1 ;
F_75 ( & V_13 -> V_57 ) ;
if ( V_13 -> V_42 -> V_65 -> V_192 ) {
V_26 = V_13 -> V_42 -> V_65 -> V_192 ( V_13 ) ;
if ( V_26 ) {
if ( V_26 != - V_70 ) {
F_16 ( V_89 , V_13 ,
L_21 ) ;
}
return V_137 ;
}
}
if ( V_13 -> V_95 >= V_150 )
F_76 ( V_13 ) ;
V_13 -> V_193 = V_13 -> V_194 ;
if ( ! V_134 && F_77 ( V_13 ) != 0 )
return V_137 ;
return V_195 ;
}
static unsigned char * F_78 ( unsigned char * V_196 , unsigned char * V_197 ,
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
static int F_79 ( struct V_21 * V_22 ,
T_1 V_23 , int * V_202 ,
struct V_12 * * V_203 , int V_204 ,
void * V_24 )
{
struct V_12 * V_13 ;
unsigned char * V_14 ;
int V_108 , V_205 = V_137 , V_107 = 256 ;
struct V_27 * V_5 = F_19 ( V_22 -> V_28 . V_29 ) ;
V_13 = F_80 ( V_22 , V_23 ) ;
if ( V_13 ) {
if ( V_204 || ! F_81 ( V_13 ) ) {
F_62 ( 3 , F_16 ( V_10 , V_13 ,
L_22 ,
F_82 ( & V_13 -> V_57 ) ) ) ;
if ( V_203 )
* V_203 = V_13 ;
else
F_83 ( V_13 ) ;
if ( V_202 )
* V_202 = F_65 ( V_13 ,
V_13 -> V_38 ,
V_13 -> V_40 ) ;
return V_195 ;
}
F_83 ( V_13 ) ;
} else
V_13 = F_18 ( V_22 , V_23 , V_24 ) ;
if ( ! V_13 )
goto V_37;
V_14 = F_3 ( V_107 , V_36 |
( ( V_5 -> V_206 ) ? V_207 : 0 ) ) ;
if ( ! V_14 )
goto V_208;
if ( F_61 ( V_13 , V_14 , V_107 , & V_108 ) )
goto V_209;
if ( V_202 )
* V_202 = V_108 ;
if ( ( ( V_14 [ 0 ] >> 5 ) == 3 ) && ! ( V_108 & V_210 ) ) {
F_62 ( 2 , sdev_printk(KERN_INFO, sdev, L_23
L_24
L_25))
if ( V_23 == 0 ) {
F_62 ( 1 , {
unsigned char vend[9];
unsigned char mod[17];
sdev_printk(KERN_INFO, sdev,
L_26
L_27,
scsi_inq_str(vend, result, 8, 16),
scsi_inq_str(mod, result, 16, 32));
}) ;
}
V_205 = V_211 ;
goto V_209;
}
if ( ( ( V_14 [ 0 ] >> 5 ) == 1 || V_22 -> V_212 ) &&
( V_14 [ 0 ] & 0x1f ) == 0x1f &&
! F_70 ( V_23 ) ) {
F_62 ( 3 , F_16 ( V_10 , V_13 ,
L_28
L_29 ) ) ;
V_205 = V_211 ;
goto V_209;
}
V_205 = F_67 ( V_13 , V_14 , & V_108 , V_5 -> V_213 ) ;
if ( V_205 == V_195 ) {
if ( V_108 & V_214 ) {
V_13 -> V_148 = 0 ;
F_15 ( V_13 , V_14 ) ;
}
}
V_209:
F_14 ( V_14 ) ;
V_208:
if ( V_205 == V_195 ) {
if ( V_203 ) {
if ( F_84 ( V_13 ) == 0 ) {
* V_203 = V_13 ;
} else {
F_34 ( V_13 ) ;
V_205 = V_137 ;
}
}
} else
F_34 ( V_13 ) ;
V_37:
return V_205 ;
}
static void F_85 ( struct V_21 * V_22 ,
int V_108 , int V_95 , int V_204 )
{
T_2 V_215 ;
T_1 V_216 , V_23 ;
struct V_27 * V_5 = F_19 ( V_22 -> V_28 . V_29 ) ;
F_62 ( 3 , F_86 ( V_10 , V_22 ,
L_30 ) ) ;
V_215 = F_66 ( V_217 , V_5 -> V_218 ) ;
if ( V_108 & V_219 ) {
V_215 = V_5 -> V_218 ;
V_216 = 1 ;
} else
V_216 = 0 ;
if ( V_108 & V_220 )
V_215 = V_5 -> V_218 ;
if ( V_108 & V_221 )
V_215 = F_66 ( 5U , V_215 ) ;
if ( V_95 < V_150 && ! ( V_108 & V_222 ) )
V_215 = F_66 ( 8U , V_215 ) ;
if ( ! ( V_108 & V_223 ) )
V_215 = F_66 ( 256U , V_215 ) ;
for ( V_23 = 1 ; V_23 < V_215 ; ++ V_23 )
if ( ( F_79 ( V_22 , V_23 , NULL , NULL , V_204 ,
NULL ) != V_195 ) &&
! V_216 )
return;
}
static int F_87 ( struct V_21 * V_22 , int V_108 ,
int V_204 )
{
char V_224 [ 64 ] ;
unsigned char V_15 [ V_16 ] ;
unsigned int V_225 ;
T_1 V_23 ;
unsigned int V_226 ;
unsigned int V_227 ;
int V_14 ;
struct V_228 * V_229 , * V_230 ;
struct V_115 V_116 ;
struct V_12 * V_13 ;
struct V_27 * V_5 = F_19 ( & V_22 -> V_28 ) ;
int V_26 = 0 ;
if ( V_108 & V_146 )
return 1 ;
if ( V_22 -> V_95 < V_96 &&
V_22 -> V_95 != V_132 )
return 1 ;
if ( V_22 -> V_95 < V_150 &&
( ! ( V_108 & V_145 ) || V_5 -> V_218 <= 8 ) )
return 1 ;
if ( V_108 & V_231 )
return 0 ;
if ( V_22 -> V_232 )
return 1 ;
if ( ! ( V_13 = F_80 ( V_22 , 0 ) ) ) {
V_13 = F_18 ( V_22 , 0 , NULL ) ;
if ( ! V_13 )
return 0 ;
if ( F_84 ( V_13 ) ) {
F_34 ( V_13 ) ;
return 0 ;
}
}
sprintf ( V_224 , L_31 ,
V_5 -> V_90 , V_13 -> V_46 , V_13 -> V_45 ) ;
V_225 = ( 511 + 1 ) * sizeof( struct V_228 ) ;
V_99:
V_230 = F_3 ( V_225 , V_4 |
( V_13 -> V_42 -> V_206 ? V_207 : 0 ) ) ;
if ( ! V_230 ) {
F_9 ( V_72 , V_73 ) ;
goto V_37;
}
V_15 [ 0 ] = V_233 ;
memset ( & V_15 [ 1 ] , 0 , 5 ) ;
F_88 ( V_225 , & V_15 [ 6 ] ) ;
V_15 [ 10 ] = 0 ;
V_15 [ 11 ] = 0 ;
for ( V_227 = 0 ; V_227 < 3 ; V_227 ++ ) {
F_62 ( 3 , F_16 ( V_10 , V_13 ,
L_32 ,
V_227 ) ) ;
V_14 = F_17 ( V_13 , V_15 , V_19 ,
V_230 , V_225 , & V_116 ,
V_20 + 4 * V_121 , 3 , NULL ) ;
F_62 ( 3 , F_16 ( V_10 , V_13 ,
L_33
L_34 ,
V_14 ? L_8 : L_9 ,
V_227 , V_14 ) ) ;
if ( V_14 == 0 )
break;
else if ( F_64 ( & V_116 ) ) {
if ( V_116 . V_124 != V_125 )
break;
}
}
if ( V_14 ) {
V_26 = 1 ;
goto V_234;
}
if ( F_89 ( V_230 -> V_228 ) +
sizeof( struct V_228 ) > V_225 ) {
V_225 = F_89 ( V_230 -> V_228 ) +
sizeof( struct V_228 ) ;
F_14 ( V_230 ) ;
goto V_99;
}
V_225 = F_89 ( V_230 -> V_228 ) ;
V_226 = ( V_225 / sizeof( struct V_228 ) ) ;
F_62 ( 3 , F_16 ( V_10 , V_13 ,
L_35 ) ) ;
for ( V_229 = & V_230 [ 1 ] ; V_229 <= & V_230 [ V_226 ] ; V_229 ++ ) {
V_23 = F_90 ( V_229 ) ;
if ( V_23 > V_13 -> V_42 -> V_218 ) {
F_16 ( V_143 , V_13 ,
L_36
L_37 , V_23 ) ;
} else {
int V_205 ;
V_205 = F_79 ( V_22 ,
V_23 , NULL , NULL , V_204 , NULL ) ;
if ( V_205 == V_137 ) {
F_16 ( V_89 , V_13 ,
L_38
L_39
L_40 , ( unsigned long long ) V_23 ) ;
break;
}
}
}
V_234:
F_14 ( V_230 ) ;
V_37:
F_83 ( V_13 ) ;
if ( F_81 ( V_13 ) )
F_34 ( V_13 ) ;
return V_26 ;
}
struct V_12 * F_91 ( struct V_27 * V_5 , T_2 V_46 ,
T_2 V_45 , T_1 V_23 , void * V_24 )
{
struct V_12 * V_13 = F_92 ( - V_235 ) ;
struct V_74 * V_29 = & V_5 -> V_236 ;
struct V_21 * V_22 ;
if ( strncmp ( V_237 , L_41 , 4 ) == 0 )
return F_92 ( - V_235 ) ;
V_22 = F_51 ( V_29 , V_46 , V_45 ) ;
if ( ! V_22 )
return F_92 ( - V_238 ) ;
F_93 ( V_22 ) ;
F_94 ( & V_5 -> V_239 ) ;
if ( ! V_5 -> V_213 )
F_1 () ;
if ( F_95 ( V_5 ) && F_96 ( V_5 ) == 0 ) {
F_79 ( V_22 , V_23 , NULL , & V_13 , 1 , V_24 ) ;
F_97 ( V_5 ) ;
}
F_98 ( & V_5 -> V_239 ) ;
F_99 ( V_22 ) ;
F_58 ( V_22 ) ;
F_28 ( & V_22 -> V_28 ) ;
return V_13 ;
}
int F_100 ( struct V_27 * V_42 , T_2 V_46 ,
T_2 V_240 , T_1 V_23 )
{
struct V_12 * V_13 =
F_91 ( V_42 , V_46 , V_240 , V_23 , NULL ) ;
if ( F_101 ( V_13 ) )
return F_102 ( V_13 ) ;
F_83 ( V_13 ) ;
return 0 ;
}
void F_103 ( struct V_74 * V_28 )
{
F_104 ( V_28 ) ;
if ( V_28 -> V_241 && F_105 ( V_28 -> V_241 -> V_242 ) ) {
struct V_243 * V_244 = F_106 ( V_28 -> V_241 ) ;
if ( V_244 -> V_204 )
V_244 -> V_204 ( V_28 ) ;
F_107 ( V_28 -> V_241 -> V_242 ) ;
}
F_108 ( V_28 ) ;
}
static void F_109 ( struct V_74 * V_29 , unsigned int V_46 ,
unsigned int V_45 , T_1 V_23 , int V_204 )
{
struct V_27 * V_5 = F_19 ( V_29 ) ;
int V_108 = 0 ;
int V_205 ;
struct V_21 * V_22 ;
if ( V_5 -> V_245 == V_45 )
return;
V_22 = F_51 ( V_29 , V_46 , V_45 ) ;
if ( ! V_22 )
return;
F_93 ( V_22 ) ;
if ( V_23 != V_246 ) {
F_79 ( V_22 , V_23 , NULL , NULL , V_204 , NULL ) ;
goto V_247;
}
V_205 = F_79 ( V_22 , 0 , & V_108 , NULL , V_204 , NULL ) ;
if ( V_205 == V_195 || V_205 == V_211 ) {
if ( F_87 ( V_22 , V_108 , V_204 ) != 0 )
F_85 ( V_22 , V_108 ,
V_22 -> V_95 , V_204 ) ;
}
V_247:
F_99 ( V_22 ) ;
F_58 ( V_22 ) ;
F_28 ( & V_22 -> V_28 ) ;
}
void F_110 ( struct V_74 * V_29 , unsigned int V_46 ,
unsigned int V_45 , T_1 V_23 , int V_204 )
{
struct V_27 * V_5 = F_19 ( V_29 ) ;
if ( strncmp ( V_237 , L_41 , 4 ) == 0 )
return;
F_94 ( & V_5 -> V_239 ) ;
if ( ! V_5 -> V_213 )
F_1 () ;
if ( F_95 ( V_5 ) && F_96 ( V_5 ) == 0 ) {
F_109 ( V_29 , V_46 , V_45 , V_23 , V_204 ) ;
F_97 ( V_5 ) ;
}
F_98 ( & V_5 -> V_239 ) ;
}
static void F_111 ( struct V_27 * V_5 , unsigned int V_46 ,
unsigned int V_45 , T_1 V_23 , int V_204 )
{
T_2 V_248 ;
if ( V_45 == V_246 )
for ( V_45 = 0 ; V_45 < V_5 -> V_249 ; ++ V_45 ) {
if ( V_5 -> V_250 )
V_248 = V_5 -> V_249 - V_45 - 1 ;
else
V_248 = V_45 ;
F_109 ( & V_5 -> V_236 , V_46 ,
V_248 , V_23 , V_204 ) ;
}
else
F_109 ( & V_5 -> V_236 , V_46 ,
V_45 , V_23 , V_204 ) ;
}
int F_112 ( struct V_27 * V_5 , unsigned int V_46 ,
unsigned int V_45 , T_1 V_23 , int V_204 )
{
F_62 ( 3 , F_113 ( V_10 , V_5 ,
L_42 ,
V_73 , V_46 , V_45 , V_23 ) ) ;
if ( ( ( V_46 != V_246 ) && ( V_46 > V_5 -> V_251 ) ) ||
( ( V_45 != V_246 ) && ( V_45 >= V_5 -> V_249 ) ) ||
( ( V_23 != V_246 ) && ( V_23 >= V_5 -> V_218 ) ) )
return - V_252 ;
F_94 ( & V_5 -> V_239 ) ;
if ( ! V_5 -> V_213 )
F_1 () ;
if ( F_95 ( V_5 ) && F_96 ( V_5 ) == 0 ) {
if ( V_46 == V_246 )
for ( V_46 = 0 ; V_46 <= V_5 -> V_251 ;
V_46 ++ )
F_111 ( V_5 , V_46 , V_45 , V_23 ,
V_204 ) ;
else
F_111 ( V_5 , V_46 , V_45 , V_23 , V_204 ) ;
F_97 ( V_5 ) ;
}
F_98 ( & V_5 -> V_239 ) ;
return 0 ;
}
static void F_114 ( struct V_27 * V_5 )
{
struct V_12 * V_13 ;
F_115 (sdev, shost) {
if ( V_13 -> V_47 == V_253 )
continue;
if ( V_13 -> V_254 )
continue;
if ( ! F_95 ( V_5 ) ||
F_77 ( V_13 ) != 0 )
F_34 ( V_13 ) ;
}
}
static struct V_1 * F_116 ( struct V_27 * V_5 )
{
struct V_1 * V_2 ;
unsigned long V_75 ;
if ( strncmp ( V_237 , L_43 , 4 ) == 0 )
return NULL ;
if ( V_5 -> V_213 ) {
F_113 ( V_10 , V_5 , L_44 , V_73 ) ;
F_117 () ;
return NULL ;
}
V_2 = F_3 ( sizeof( * V_2 ) , V_4 ) ;
if ( ! V_2 )
goto V_255;
V_2 -> V_5 = F_118 ( V_5 ) ;
if ( ! V_2 -> V_5 )
goto V_255;
F_5 ( & V_2 -> V_6 ) ;
F_94 ( & V_5 -> V_239 ) ;
F_37 ( V_5 -> V_78 , V_75 ) ;
V_5 -> V_213 = 1 ;
F_39 ( V_5 -> V_78 , V_75 ) ;
F_98 ( & V_5 -> V_239 ) ;
F_6 ( & V_7 ) ;
if ( F_2 ( & V_3 ) )
F_13 ( & V_2 -> V_6 ) ;
F_7 ( & V_2 -> V_9 , & V_3 ) ;
F_8 ( & V_7 ) ;
return V_2 ;
V_255:
F_14 ( V_2 ) ;
return NULL ;
}
static void F_119 ( struct V_1 * V_2 )
{
struct V_27 * V_5 ;
unsigned long V_75 ;
if ( ! V_2 )
return;
V_5 = V_2 -> V_5 ;
F_94 ( & V_5 -> V_239 ) ;
if ( ! V_5 -> V_213 ) {
F_113 ( V_10 , V_5 , L_44 , V_73 ) ;
F_117 () ;
F_98 ( & V_5 -> V_239 ) ;
return;
}
F_10 ( & V_2 -> V_6 ) ;
F_114 ( V_5 ) ;
F_37 ( V_5 -> V_78 , V_75 ) ;
V_5 -> V_213 = 0 ;
F_39 ( V_5 -> V_78 , V_75 ) ;
F_98 ( & V_5 -> V_239 ) ;
F_6 ( & V_7 ) ;
F_11 ( & V_2 -> V_9 ) ;
if ( ! F_2 ( & V_3 ) ) {
struct V_1 * V_11 = F_12 ( V_3 . V_11 ,
struct V_1 , V_9 ) ;
F_13 ( & V_11 -> V_6 ) ;
}
F_8 ( & V_7 ) ;
F_97 ( V_5 ) ;
F_120 ( V_5 ) ;
F_14 ( V_2 ) ;
}
static void F_121 ( struct V_27 * V_5 )
{
if ( V_5 -> V_65 -> V_256 ) {
unsigned long V_257 = V_258 ;
if ( V_5 -> V_65 -> V_259 )
V_5 -> V_65 -> V_259 ( V_5 ) ;
while ( ! V_5 -> V_65 -> V_256 ( V_5 , V_258 - V_257 ) )
F_4 ( 10 ) ;
} else {
F_112 ( V_5 , V_246 , V_246 ,
V_246 , 0 ) ;
}
}
static void F_122 ( void * V_260 , T_3 V_261 )
{
struct V_1 * V_2 = V_260 ;
struct V_27 * V_5 = V_2 -> V_5 ;
F_121 ( V_5 ) ;
F_119 ( V_2 ) ;
}
void F_123 ( struct V_27 * V_5 )
{
struct V_1 * V_2 ;
if ( strncmp ( V_237 , L_41 , 4 ) == 0 )
return;
if ( F_96 ( V_5 ) < 0 )
return;
V_2 = F_116 ( V_5 ) ;
if ( ! V_2 ) {
F_121 ( V_5 ) ;
F_97 ( V_5 ) ;
return;
}
F_124 ( F_122 , V_2 ) ;
}
void F_125 ( struct V_27 * V_5 )
{
struct V_12 * V_13 ;
unsigned long V_75 ;
V_262:
F_37 ( V_5 -> V_78 , V_75 ) ;
F_44 (sdev, &shost->__devices, siblings) {
if ( V_13 -> V_47 == V_253 )
continue;
F_39 ( V_5 -> V_78 , V_75 ) ;
F_34 ( V_13 ) ;
goto V_262;
}
F_39 ( V_5 -> V_78 , V_75 ) ;
}
struct V_12 * F_126 ( struct V_27 * V_5 )
{
struct V_12 * V_13 = NULL ;
struct V_21 * V_22 ;
F_94 ( & V_5 -> V_239 ) ;
if ( ! F_95 ( V_5 ) )
goto V_37;
V_22 = F_51 ( & V_5 -> V_236 , 0 , V_5 -> V_245 ) ;
if ( ! V_22 )
goto V_37;
V_13 = F_18 ( V_22 , 0 , NULL ) ;
if ( V_13 )
V_13 -> V_61 = 0 ;
else
F_58 ( V_22 ) ;
F_28 ( & V_22 -> V_28 ) ;
V_37:
F_98 ( & V_5 -> V_239 ) ;
return V_13 ;
}
void F_127 ( struct V_12 * V_13 )
{
F_59 ( V_13 -> V_45 != V_13 -> V_42 -> V_245 ) ;
F_34 ( V_13 ) ;
}
