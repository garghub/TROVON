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
F_23 ( & V_13 -> V_55 ) ;
F_24 ( & V_13 -> V_56 , V_30 ) ;
F_24 ( & V_13 -> V_57 , V_33 ) ;
V_13 -> V_58 . V_29 = F_25 ( & V_22 -> V_28 ) ;
V_13 -> V_59 = V_22 ;
V_13 -> V_24 = V_24 ;
V_13 -> V_60 = V_61 ;
V_13 -> type = - 1 ;
V_13 -> V_62 = 1 ;
if ( F_26 ( V_5 ) )
V_13 -> V_63 = F_27 ( V_13 ) ;
else
V_13 -> V_63 = F_28 ( V_13 ) ;
if ( ! V_13 -> V_63 ) {
F_29 ( & V_22 -> V_28 ) ;
F_14 ( V_13 ) ;
goto V_37;
}
F_30 ( ! F_31 ( V_13 -> V_63 ) ) ;
V_13 -> V_63 -> V_64 = V_13 ;
if ( ! F_26 ( V_13 -> V_42 ) ) {
F_32 ( V_13 -> V_63 ,
V_13 -> V_42 -> V_65 , V_5 -> V_66 ,
V_5 -> V_67 -> V_68 ) ;
}
F_33 ( V_13 , V_13 -> V_42 -> V_65 ?
V_13 -> V_42 -> V_65 : 1 ) ;
F_34 ( V_13 ) ;
if ( V_5 -> V_67 -> V_69 ) {
V_26 = V_5 -> V_67 -> V_69 ( V_13 ) ;
if ( V_26 ) {
if ( V_26 == - V_70 )
V_25 = 0 ;
goto V_71;
}
}
return V_13 ;
V_71:
F_35 ( V_13 ) ;
V_37:
if ( V_25 )
F_9 ( V_72 , V_73 ) ;
return NULL ;
}
static void F_36 ( struct V_21 * V_22 )
{
struct V_74 * V_28 = & V_22 -> V_28 ;
struct V_27 * V_5 = F_19 ( V_28 -> V_29 ) ;
unsigned long V_75 ;
V_22 -> V_76 = V_77 ;
F_37 ( V_28 ) ;
F_38 ( V_5 -> V_78 , V_75 ) ;
if ( V_5 -> V_67 -> V_79 )
V_5 -> V_67 -> V_79 ( V_22 ) ;
F_39 ( & V_22 -> V_49 ) ;
F_40 ( V_5 -> V_78 , V_75 ) ;
F_29 ( V_28 ) ;
}
static void F_41 ( struct V_74 * V_28 )
{
struct V_74 * V_29 = V_28 -> V_29 ;
struct V_21 * V_22 = F_42 ( V_28 ) ;
F_14 ( V_22 ) ;
F_29 ( V_29 ) ;
}
int F_43 ( const struct V_74 * V_28 )
{
return V_28 -> type == & V_80 ;
}
static struct V_21 * F_44 ( struct V_74 * V_29 ,
int V_46 , T_2 V_45 )
{
struct V_21 * V_22 , * V_81 = NULL ;
struct V_27 * V_5 = F_19 ( V_29 ) ;
F_45 (starget, &shost->__targets, siblings) {
if ( V_22 -> V_45 == V_45 &&
V_22 -> V_46 == V_46 ) {
V_81 = V_22 ;
break;
}
}
if ( V_81 )
F_25 ( & V_81 -> V_28 ) ;
return V_81 ;
}
static void F_46 ( struct V_82 * V_82 )
{
struct V_21 * V_22
= F_47 ( V_82 , struct V_21 , V_83 ) ;
if ( V_22 -> V_76 != V_84 ) {
F_48 ( & V_22 -> V_28 ) ;
F_49 ( & V_22 -> V_28 ) ;
}
F_36 ( V_22 ) ;
}
static void F_50 ( struct V_21 * V_22 )
{
F_51 ( & V_22 -> V_83 , F_46 ) ;
}
static struct V_21 * F_52 ( struct V_74 * V_29 ,
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
F_53 ( V_28 ) ;
F_54 ( & V_22 -> V_83 ) ;
V_28 -> V_29 = F_25 ( V_29 ) ;
F_55 ( V_28 , L_4 , V_5 -> V_90 , V_46 , V_45 ) ;
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
F_38 ( V_5 -> V_78 , V_75 ) ;
V_87 = F_44 ( V_29 , V_46 , V_45 ) ;
if ( V_87 )
goto V_100;
F_7 ( & V_22 -> V_49 , & V_5 -> V_101 ) ;
F_40 ( V_5 -> V_78 , V_75 ) ;
F_56 ( V_28 ) ;
if ( V_5 -> V_67 -> V_102 ) {
error = V_5 -> V_67 -> V_102 ( V_22 ) ;
if( error ) {
F_57 ( V_89 , V_28 , L_5 , error ) ;
F_36 ( V_22 ) ;
return NULL ;
}
}
F_25 ( V_28 ) ;
return V_22 ;
V_100:
V_88 = F_58 ( & V_87 -> V_83 ) ;
F_40 ( V_5 -> V_78 , V_75 ) ;
if ( V_88 ) {
F_29 ( V_28 ) ;
return V_87 ;
}
F_29 ( & V_87 -> V_28 ) ;
F_4 ( 1 ) ;
goto V_99;
}
void F_59 ( struct V_21 * V_22 )
{
F_60 ( V_22 -> V_76 == V_77 ) ;
F_50 ( V_22 ) ;
}
static void F_61 ( unsigned char * V_103 , int V_104 )
{
int V_105 = 0 ;
for (; V_104 > 0 ; ( -- V_104 , ++ V_103 ) ) {
if ( * V_103 == 0 )
V_105 = 1 ;
if ( V_105 || * V_103 < 0x20 || * V_103 > 0x7e )
* V_103 = ' ' ;
}
}
static int F_62 ( struct V_12 * V_13 , unsigned char * V_106 ,
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
F_63 ( 3 , F_16 ( V_10 , V_13 ,
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
F_63 ( 3 , F_16 ( V_10 , V_13 ,
L_7 ,
V_14 ? L_8 : L_9 , V_14 ) ) ;
if ( V_14 ) {
if ( ( F_64 ( V_14 ) & V_123 ) &&
F_65 ( & V_116 ) ) {
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
F_61 ( & V_106 [ 8 ] , 8 ) ;
F_61 ( & V_106 [ 16 ] , 16 ) ;
F_61 ( & V_106 [ 32 ] , 4 ) ;
V_112 = V_106 [ 4 ] + 5 ;
if ( V_112 > 255 )
V_112 = V_109 ;
* V_108 = F_66 ( V_13 , & V_106 [ 8 ] ,
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
V_13 -> V_117 = F_67 ( V_110 , V_112 ) ;
if ( V_13 -> V_117 < 36 ) {
if ( ! V_13 -> V_42 -> V_131 ) {
F_68 ( V_10 , V_13 -> V_42 ,
L_12
L_13 , V_13 -> V_117 ) ;
V_13 -> V_42 -> V_131 = 1 ;
}
V_13 -> V_117 = 36 ;
}
V_13 -> V_95 = V_106 [ 2 ] & 0x07 ;
if ( V_13 -> V_95 >= 2 ||
( V_13 -> V_95 == 1 && ( V_106 [ 3 ] & 0x0f ) == 1 ) )
V_13 -> V_95 ++ ;
V_13 -> V_59 -> V_95 = V_13 -> V_95 ;
V_13 -> V_132 = 0 ;
if ( V_13 -> V_95 <= V_96 &&
V_13 -> V_95 != V_133 &&
! V_13 -> V_42 -> V_134 )
V_13 -> V_132 = 1 ;
return 0 ;
}
static int F_69 ( struct V_12 * V_13 , unsigned char * V_106 ,
int * V_108 , int V_135 )
{
int V_26 ;
V_13 -> V_136 = F_70 ( V_106 ,
F_71 ( V_137 , V_13 -> V_117 , 36 ) ,
V_36 ) ;
if ( V_13 -> V_136 == NULL )
return V_138 ;
V_13 -> V_38 = ( char * ) ( V_13 -> V_136 + 8 ) ;
V_13 -> V_40 = ( char * ) ( V_13 -> V_136 + 16 ) ;
V_13 -> V_41 = ( char * ) ( V_13 -> V_136 + 32 ) ;
if ( strncmp ( V_13 -> V_38 , L_14 , 8 ) == 0 ) {
V_13 -> V_139 = 1 ;
}
if ( * V_108 & V_140 ) {
V_13 -> type = V_141 ;
V_13 -> V_142 = 1 ;
} else {
V_13 -> type = ( V_106 [ 0 ] & 0x1f ) ;
V_13 -> V_142 = ( V_106 [ 1 ] & 0x80 ) >> 7 ;
if ( F_72 ( V_13 -> V_23 ) && V_13 -> type != V_143 ) {
F_16 ( V_144 , V_13 ,
L_15 ,
V_73 , V_13 -> type , ( unsigned int ) V_13 -> V_23 ) ;
V_13 -> type = V_143 ;
}
}
if ( V_13 -> type == V_145 || V_13 -> type == V_141 ) {
if ( ( * V_108 & V_146 ) == 0 )
* V_108 |= V_147 ;
}
V_13 -> V_148 = ( V_106 [ 0 ] >> 5 ) & 7 ;
V_13 -> V_149 = V_13 -> V_142 ;
V_13 -> V_150 = ( V_106 [ 7 ] & 1 ) && ( ( V_106 [ 3 ] & 7 ) == 2 ) ;
if ( V_13 -> V_95 >= V_151 ||
( V_13 -> V_117 > 56 && V_106 [ 56 ] & 0x04 ) )
V_13 -> V_152 = 1 ;
if ( V_106 [ 7 ] & 0x60 )
V_13 -> V_153 = 1 ;
if ( V_106 [ 7 ] & 0x10 )
V_13 -> V_154 = 1 ;
F_16 ( V_17 , V_13 , L_16
L_17 , F_73 ( V_13 -> type ) ,
V_13 -> V_38 , V_13 -> V_40 , V_13 -> V_41 ,
V_13 -> V_148 , V_106 [ 2 ] & 0x07 ,
( V_106 [ 3 ] & 0x0f ) == 1 ? L_18 : L_19 ) ;
if ( ( V_13 -> V_95 >= V_96 ) && ( V_106 [ 7 ] & 2 ) &&
! ( * V_108 & V_155 ) ) {
V_13 -> V_156 = 1 ;
V_13 -> V_157 = 1 ;
}
if ( ( * V_108 & V_158 ) == 0 )
V_13 -> V_62 = 0 ;
if ( * V_108 & V_159 )
V_13 -> V_160 = 1 ;
if ( * V_108 & V_161 )
V_13 -> V_162 = 1 ;
if ( * V_108 & V_163 )
F_74 ( V_13 -> V_63 , 512 ) ;
else if ( * V_108 & V_164 )
F_74 ( V_13 -> V_63 , 1024 ) ;
if ( * V_108 & V_165 )
V_13 -> V_166 = 1 ;
if ( * V_108 & V_167 )
V_21 ( V_13 ) -> V_168 = 1 ;
V_13 -> V_169 = 1 ;
if ( * V_108 & V_170 )
V_13 -> V_171 = 1 ;
if ( * V_108 & V_172 )
V_13 -> V_173 = 1 ;
if ( * V_108 & V_174 )
V_13 -> V_175 = 1 ;
if ( * V_108 & V_176 )
V_13 -> V_177 = 1 ;
V_26 = F_75 ( V_13 , V_178 ) ;
if ( V_26 ) {
V_26 = F_75 ( V_13 , V_179 ) ;
if ( V_26 ) {
F_16 ( V_89 , V_13 ,
L_20 ,
F_76 ( V_13 -> V_47 ) ) ;
return V_138 ;
}
}
if ( * V_108 & V_180 )
V_13 -> V_181 = 1 ;
if ( * V_108 & V_182 )
V_13 -> V_149 = 0 ;
if ( * V_108 & V_183 )
V_13 -> V_184 = 1 ;
if ( * V_108 & V_185 )
V_13 -> V_186 = 1 ;
V_13 -> V_187 = V_188 ;
if ( * V_108 & V_189 )
V_13 -> V_190 = 1 ;
else if ( * V_108 & V_191 )
V_13 -> V_192 = 1 ;
F_77 ( & V_13 -> V_58 ) ;
if ( V_13 -> V_42 -> V_67 -> V_193 ) {
V_26 = V_13 -> V_42 -> V_67 -> V_193 ( V_13 ) ;
if ( V_26 ) {
if ( V_26 != - V_70 ) {
F_16 ( V_89 , V_13 ,
L_21 ) ;
}
return V_138 ;
}
}
if ( V_13 -> V_95 >= V_151 )
F_78 ( V_13 ) ;
V_13 -> V_194 = V_13 -> V_195 ;
if ( ! V_135 && F_79 ( V_13 ) != 0 )
return V_138 ;
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
struct V_12 * * V_204 , int V_205 ,
void * V_24 )
{
struct V_12 * V_13 ;
unsigned char * V_14 ;
int V_108 , V_206 = V_138 , V_107 = 256 ;
struct V_27 * V_5 = F_19 ( V_22 -> V_28 . V_29 ) ;
V_13 = F_82 ( V_22 , V_23 ) ;
if ( V_13 ) {
if ( V_205 || ! F_83 ( V_13 ) ) {
F_63 ( 3 , F_16 ( V_10 , V_13 ,
L_22 ,
F_84 ( & V_13 -> V_58 ) ) ) ;
if ( V_204 )
* V_204 = V_13 ;
else
F_85 ( V_13 ) ;
if ( V_203 )
* V_203 = F_66 ( V_13 ,
V_13 -> V_38 ,
V_13 -> V_40 ) ;
return V_196 ;
}
F_85 ( V_13 ) ;
} else
V_13 = F_18 ( V_22 , V_23 , V_24 ) ;
if ( ! V_13 )
goto V_37;
V_14 = F_3 ( V_107 , V_36 |
( ( V_5 -> V_207 ) ? V_208 : 0 ) ) ;
if ( ! V_14 )
goto V_209;
if ( F_62 ( V_13 , V_14 , V_107 , & V_108 ) )
goto V_210;
if ( V_203 )
* V_203 = V_108 ;
if ( ( ( V_14 [ 0 ] >> 5 ) == 3 ) && ! ( V_108 & V_211 ) ) {
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
V_206 = V_212 ;
goto V_210;
}
if ( ( ( V_14 [ 0 ] >> 5 ) == 1 || V_22 -> V_213 ) &&
( V_14 [ 0 ] & 0x1f ) == 0x1f &&
! F_72 ( V_23 ) ) {
F_63 ( 3 , F_16 ( V_10 , V_13 ,
L_28
L_29 ) ) ;
V_206 = V_212 ;
goto V_210;
}
V_206 = F_69 ( V_13 , V_14 , & V_108 , V_5 -> V_214 ) ;
if ( V_206 == V_196 ) {
if ( V_108 & V_215 ) {
V_13 -> V_149 = 0 ;
F_15 ( V_13 , V_14 ) ;
}
}
V_210:
F_14 ( V_14 ) ;
V_209:
if ( V_206 == V_196 ) {
if ( V_204 ) {
if ( F_86 ( V_13 ) == 0 ) {
* V_204 = V_13 ;
} else {
F_35 ( V_13 ) ;
V_206 = V_138 ;
}
}
} else
F_35 ( V_13 ) ;
V_37:
return V_206 ;
}
static void F_87 ( struct V_21 * V_22 ,
int V_108 , int V_95 , int V_205 )
{
T_2 V_216 ;
T_1 V_217 , V_23 ;
struct V_27 * V_5 = F_19 ( V_22 -> V_28 . V_29 ) ;
F_63 ( 3 , F_88 ( V_10 , V_22 ,
L_30 ) ) ;
V_216 = F_67 ( V_218 , V_5 -> V_219 ) ;
if ( V_108 & V_220 ) {
V_216 = V_5 -> V_219 ;
V_217 = 1 ;
} else
V_217 = 0 ;
if ( V_108 & V_221 )
V_216 = V_5 -> V_219 ;
if ( V_108 & V_222 )
V_216 = F_67 ( 5U , V_216 ) ;
if ( V_95 < V_151 && ! ( V_108 & V_223 ) )
V_216 = F_67 ( 8U , V_216 ) ;
if ( ! ( V_108 & V_224 ) )
V_216 = F_67 ( 256U , V_216 ) ;
for ( V_23 = 1 ; V_23 < V_216 ; ++ V_23 )
if ( ( F_81 ( V_22 , V_23 , NULL , NULL , V_205 ,
NULL ) != V_196 ) &&
! V_217 )
return;
}
static int F_89 ( struct V_21 * V_22 , int V_108 ,
int V_205 )
{
char V_225 [ 64 ] ;
unsigned char V_15 [ V_16 ] ;
unsigned int V_226 ;
T_1 V_23 ;
unsigned int V_227 ;
unsigned int V_228 ;
int V_14 ;
struct V_229 * V_230 , * V_231 ;
struct V_115 V_116 ;
struct V_12 * V_13 ;
struct V_27 * V_5 = F_19 ( & V_22 -> V_28 ) ;
int V_26 = 0 ;
if ( V_108 & V_147 )
return 1 ;
if ( V_22 -> V_95 < V_96 &&
V_22 -> V_95 != V_133 )
return 1 ;
if ( V_22 -> V_95 < V_151 &&
( ! ( V_108 & V_146 ) || V_5 -> V_219 <= 8 ) )
return 1 ;
if ( V_108 & V_232 )
return 0 ;
if ( V_22 -> V_233 )
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
sprintf ( V_225 , L_31 ,
V_5 -> V_90 , V_13 -> V_46 , V_13 -> V_45 ) ;
V_226 = ( 511 + 1 ) * sizeof( struct V_229 ) ;
V_99:
V_231 = F_3 ( V_226 , V_4 |
( V_13 -> V_42 -> V_207 ? V_208 : 0 ) ) ;
if ( ! V_231 ) {
F_9 ( V_72 , V_73 ) ;
goto V_37;
}
V_15 [ 0 ] = V_234 ;
memset ( & V_15 [ 1 ] , 0 , 5 ) ;
F_90 ( V_226 , & V_15 [ 6 ] ) ;
V_15 [ 10 ] = 0 ;
V_15 [ 11 ] = 0 ;
for ( V_228 = 0 ; V_228 < 3 ; V_228 ++ ) {
F_63 ( 3 , F_16 ( V_10 , V_13 ,
L_32 ,
V_228 ) ) ;
V_14 = F_17 ( V_13 , V_15 , V_19 ,
V_231 , V_226 , & V_116 ,
V_235 , 3 , NULL ) ;
F_63 ( 3 , F_16 ( V_10 , V_13 ,
L_33
L_34 ,
V_14 ? L_8 : L_9 ,
V_228 , V_14 ) ) ;
if ( V_14 == 0 )
break;
else if ( F_65 ( & V_116 ) ) {
if ( V_116 . V_124 != V_125 )
break;
}
}
if ( V_14 ) {
V_26 = 1 ;
goto V_236;
}
if ( F_91 ( V_231 -> V_229 ) +
sizeof( struct V_229 ) > V_226 ) {
V_226 = F_91 ( V_231 -> V_229 ) +
sizeof( struct V_229 ) ;
F_14 ( V_231 ) ;
goto V_99;
}
V_226 = F_91 ( V_231 -> V_229 ) ;
V_227 = ( V_226 / sizeof( struct V_229 ) ) ;
F_63 ( 3 , F_16 ( V_10 , V_13 ,
L_35 ) ) ;
for ( V_230 = & V_231 [ 1 ] ; V_230 <= & V_231 [ V_227 ] ; V_230 ++ ) {
V_23 = F_92 ( V_230 ) ;
if ( V_23 > V_13 -> V_42 -> V_219 ) {
F_16 ( V_144 , V_13 ,
L_36
L_37 , V_23 ) ;
} else {
int V_206 ;
V_206 = F_81 ( V_22 ,
V_23 , NULL , NULL , V_205 , NULL ) ;
if ( V_206 == V_138 ) {
F_16 ( V_89 , V_13 ,
L_38
L_39
L_40 , ( unsigned long long ) V_23 ) ;
break;
}
}
}
V_236:
F_14 ( V_231 ) ;
V_37:
F_85 ( V_13 ) ;
if ( F_83 ( V_13 ) )
F_35 ( V_13 ) ;
return V_26 ;
}
struct V_12 * F_93 ( struct V_27 * V_5 , T_2 V_46 ,
T_2 V_45 , T_1 V_23 , void * V_24 )
{
struct V_12 * V_13 = F_94 ( - V_237 ) ;
struct V_74 * V_29 = & V_5 -> V_238 ;
struct V_21 * V_22 ;
if ( strncmp ( V_239 , L_41 , 4 ) == 0 )
return F_94 ( - V_237 ) ;
V_22 = F_52 ( V_29 , V_46 , V_45 ) ;
if ( ! V_22 )
return F_94 ( - V_240 ) ;
F_95 ( V_22 ) ;
F_96 ( & V_5 -> V_241 ) ;
if ( ! V_5 -> V_214 )
F_1 () ;
if ( F_97 ( V_5 ) && F_98 ( V_5 ) == 0 ) {
F_81 ( V_22 , V_23 , NULL , & V_13 , 1 , V_24 ) ;
F_99 ( V_5 ) ;
}
F_100 ( & V_5 -> V_241 ) ;
F_101 ( V_22 ) ;
F_59 ( V_22 ) ;
F_29 ( & V_22 -> V_28 ) ;
return V_13 ;
}
int F_102 ( struct V_27 * V_42 , T_2 V_46 ,
T_2 V_242 , T_1 V_23 )
{
struct V_12 * V_13 =
F_93 ( V_42 , V_46 , V_242 , V_23 , NULL ) ;
if ( F_103 ( V_13 ) )
return F_104 ( V_13 ) ;
F_85 ( V_13 ) ;
return 0 ;
}
void F_105 ( struct V_74 * V_28 )
{
F_106 ( V_28 ) ;
F_78 ( F_107 ( V_28 ) ) ;
if ( V_28 -> V_243 && F_108 ( V_28 -> V_243 -> V_244 ) ) {
struct V_245 * V_246 = F_109 ( V_28 -> V_243 ) ;
if ( V_246 -> V_205 )
V_246 -> V_205 ( V_28 ) ;
F_110 ( V_28 -> V_243 -> V_244 ) ;
}
F_111 ( V_28 ) ;
}
static void F_112 ( struct V_74 * V_29 , unsigned int V_46 ,
unsigned int V_45 , T_1 V_23 , int V_205 )
{
struct V_27 * V_5 = F_19 ( V_29 ) ;
int V_108 = 0 ;
int V_206 ;
struct V_21 * V_22 ;
if ( V_5 -> V_247 == V_45 )
return;
V_22 = F_52 ( V_29 , V_46 , V_45 ) ;
if ( ! V_22 )
return;
F_95 ( V_22 ) ;
if ( V_23 != V_248 ) {
F_81 ( V_22 , V_23 , NULL , NULL , V_205 , NULL ) ;
goto V_249;
}
V_206 = F_81 ( V_22 , 0 , & V_108 , NULL , V_205 , NULL ) ;
if ( V_206 == V_196 || V_206 == V_212 ) {
if ( F_89 ( V_22 , V_108 , V_205 ) != 0 )
F_87 ( V_22 , V_108 ,
V_22 -> V_95 , V_205 ) ;
}
V_249:
F_101 ( V_22 ) ;
F_59 ( V_22 ) ;
F_29 ( & V_22 -> V_28 ) ;
}
void F_113 ( struct V_74 * V_29 , unsigned int V_46 ,
unsigned int V_45 , T_1 V_23 , int V_205 )
{
struct V_27 * V_5 = F_19 ( V_29 ) ;
if ( strncmp ( V_239 , L_41 , 4 ) == 0 )
return;
F_96 ( & V_5 -> V_241 ) ;
if ( ! V_5 -> V_214 )
F_1 () ;
if ( F_97 ( V_5 ) && F_98 ( V_5 ) == 0 ) {
F_112 ( V_29 , V_46 , V_45 , V_23 , V_205 ) ;
F_99 ( V_5 ) ;
}
F_100 ( & V_5 -> V_241 ) ;
}
static void F_114 ( struct V_27 * V_5 , unsigned int V_46 ,
unsigned int V_45 , T_1 V_23 , int V_205 )
{
T_2 V_250 ;
if ( V_45 == V_248 )
for ( V_45 = 0 ; V_45 < V_5 -> V_251 ; ++ V_45 ) {
if ( V_5 -> V_252 )
V_250 = V_5 -> V_251 - V_45 - 1 ;
else
V_250 = V_45 ;
F_112 ( & V_5 -> V_238 , V_46 ,
V_250 , V_23 , V_205 ) ;
}
else
F_112 ( & V_5 -> V_238 , V_46 ,
V_45 , V_23 , V_205 ) ;
}
int F_115 ( struct V_27 * V_5 , unsigned int V_46 ,
unsigned int V_45 , T_1 V_23 , int V_205 )
{
F_63 ( 3 , F_68 ( V_10 , V_5 ,
L_42 ,
V_73 , V_46 , V_45 , V_23 ) ) ;
if ( ( ( V_46 != V_248 ) && ( V_46 > V_5 -> V_253 ) ) ||
( ( V_45 != V_248 ) && ( V_45 >= V_5 -> V_251 ) ) ||
( ( V_23 != V_248 ) && ( V_23 >= V_5 -> V_219 ) ) )
return - V_254 ;
F_96 ( & V_5 -> V_241 ) ;
if ( ! V_5 -> V_214 )
F_1 () ;
if ( F_97 ( V_5 ) && F_98 ( V_5 ) == 0 ) {
if ( V_46 == V_248 )
for ( V_46 = 0 ; V_46 <= V_5 -> V_253 ;
V_46 ++ )
F_114 ( V_5 , V_46 , V_45 , V_23 ,
V_205 ) ;
else
F_114 ( V_5 , V_46 , V_45 , V_23 , V_205 ) ;
F_99 ( V_5 ) ;
}
F_100 ( & V_5 -> V_241 ) ;
return 0 ;
}
static void F_116 ( struct V_27 * V_5 )
{
struct V_12 * V_13 ;
F_117 (sdev, shost) {
if ( V_13 -> V_47 == V_255 )
continue;
if ( V_13 -> V_256 )
continue;
if ( ! F_97 ( V_5 ) ||
F_79 ( V_13 ) != 0 )
F_35 ( V_13 ) ;
}
}
static struct V_1 * F_118 ( struct V_27 * V_5 )
{
struct V_1 * V_2 ;
unsigned long V_75 ;
if ( strncmp ( V_239 , L_43 , 4 ) == 0 )
return NULL ;
if ( V_5 -> V_214 ) {
F_68 ( V_257 , V_5 , L_44 , V_73 ) ;
return NULL ;
}
V_2 = F_3 ( sizeof( * V_2 ) , V_4 ) ;
if ( ! V_2 )
goto V_258;
V_2 -> V_5 = F_119 ( V_5 ) ;
if ( ! V_2 -> V_5 )
goto V_258;
F_5 ( & V_2 -> V_6 ) ;
F_96 ( & V_5 -> V_241 ) ;
F_38 ( V_5 -> V_78 , V_75 ) ;
V_5 -> V_214 = 1 ;
F_40 ( V_5 -> V_78 , V_75 ) ;
F_100 ( & V_5 -> V_241 ) ;
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
static void F_120 ( struct V_1 * V_2 )
{
struct V_27 * V_5 ;
unsigned long V_75 ;
if ( ! V_2 )
return;
V_5 = V_2 -> V_5 ;
F_96 ( & V_5 -> V_241 ) ;
if ( ! V_5 -> V_214 ) {
F_68 ( V_10 , V_5 , L_44 , V_73 ) ;
F_121 () ;
F_100 ( & V_5 -> V_241 ) ;
return;
}
F_10 ( & V_2 -> V_6 ) ;
F_116 ( V_5 ) ;
F_38 ( V_5 -> V_78 , V_75 ) ;
V_5 -> V_214 = 0 ;
F_40 ( V_5 -> V_78 , V_75 ) ;
F_100 ( & V_5 -> V_241 ) ;
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
if ( V_5 -> V_67 -> V_259 ) {
unsigned long V_260 = V_261 ;
if ( V_5 -> V_67 -> V_262 )
V_5 -> V_67 -> V_262 ( V_5 ) ;
while ( ! V_5 -> V_67 -> V_259 ( V_5 , V_261 - V_260 ) )
F_4 ( 10 ) ;
} else {
F_115 ( V_5 , V_248 , V_248 ,
V_248 , 0 ) ;
}
}
static void F_124 ( void * V_263 , T_3 V_264 )
{
struct V_1 * V_2 = V_263 ;
struct V_27 * V_5 = V_2 -> V_5 ;
F_123 ( V_5 ) ;
F_120 ( V_2 ) ;
}
void F_125 ( struct V_27 * V_5 )
{
struct V_1 * V_2 ;
if ( strncmp ( V_239 , L_41 , 4 ) == 0 )
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
unsigned long V_75 ;
V_265:
F_38 ( V_5 -> V_78 , V_75 ) ;
F_45 (sdev, &shost->__devices, siblings) {
if ( V_13 -> V_47 == V_255 )
continue;
F_40 ( V_5 -> V_78 , V_75 ) ;
F_35 ( V_13 ) ;
goto V_265;
}
F_40 ( V_5 -> V_78 , V_75 ) ;
}
struct V_12 * F_128 ( struct V_27 * V_5 )
{
struct V_12 * V_13 = NULL ;
struct V_21 * V_22 ;
F_96 ( & V_5 -> V_241 ) ;
if ( ! F_97 ( V_5 ) )
goto V_37;
V_22 = F_52 ( & V_5 -> V_238 , 0 , V_5 -> V_247 ) ;
if ( ! V_22 )
goto V_37;
V_13 = F_18 ( V_22 , 0 , NULL ) ;
if ( V_13 )
V_13 -> V_62 = 0 ;
else
F_59 ( V_22 ) ;
F_29 ( & V_22 -> V_28 ) ;
V_37:
F_100 ( & V_5 -> V_241 ) ;
return V_13 ;
}
void F_129 ( struct V_12 * V_13 )
{
F_60 ( V_13 -> V_45 != V_13 -> V_42 -> V_247 ) ;
F_35 ( V_13 ) ;
}
