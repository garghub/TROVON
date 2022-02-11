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
V_13 -> V_42 -> V_67 , V_5 -> V_64 ) ;
}
F_32 ( V_13 , V_13 -> V_42 -> V_67 ) ;
F_33 ( V_13 ) ;
if ( V_5 -> V_65 -> V_68 ) {
V_26 = V_5 -> V_65 -> V_68 ( V_13 ) ;
if ( V_26 ) {
if ( V_26 == - V_69 )
V_25 = 0 ;
goto V_70;
}
}
return V_13 ;
V_70:
F_34 ( V_13 ) ;
V_37:
if ( V_25 )
F_9 ( V_71 , V_72 ) ;
return NULL ;
}
static void F_35 ( struct V_21 * V_22 )
{
struct V_73 * V_28 = & V_22 -> V_28 ;
struct V_27 * V_5 = F_19 ( V_28 -> V_29 ) ;
unsigned long V_74 ;
V_22 -> V_75 = V_76 ;
F_36 ( V_28 ) ;
F_37 ( V_5 -> V_77 , V_74 ) ;
if ( V_5 -> V_65 -> V_78 )
V_5 -> V_65 -> V_78 ( V_22 ) ;
F_38 ( & V_22 -> V_49 ) ;
F_39 ( V_5 -> V_77 , V_74 ) ;
F_28 ( V_28 ) ;
}
static void F_40 ( struct V_73 * V_28 )
{
struct V_73 * V_29 = V_28 -> V_29 ;
struct V_21 * V_22 = F_41 ( V_28 ) ;
F_14 ( V_22 ) ;
F_28 ( V_29 ) ;
}
int F_42 ( const struct V_73 * V_28 )
{
return V_28 -> type == & V_79 ;
}
static struct V_21 * F_43 ( struct V_73 * V_29 ,
int V_46 , T_2 V_45 )
{
struct V_21 * V_22 , * V_80 = NULL ;
struct V_27 * V_5 = F_19 ( V_29 ) ;
F_44 (starget, &shost->__targets, siblings) {
if ( V_22 -> V_45 == V_45 &&
V_22 -> V_46 == V_46 ) {
V_80 = V_22 ;
break;
}
}
if ( V_80 )
F_24 ( & V_80 -> V_28 ) ;
return V_80 ;
}
static void F_45 ( struct V_81 * V_81 )
{
struct V_21 * V_22
= F_46 ( V_81 , struct V_21 , V_82 ) ;
if ( V_22 -> V_75 != V_83 ) {
F_47 ( & V_22 -> V_28 ) ;
F_48 ( & V_22 -> V_28 ) ;
}
F_35 ( V_22 ) ;
}
static void F_49 ( struct V_21 * V_22 )
{
F_50 ( & V_22 -> V_82 , F_45 ) ;
}
static struct V_21 * F_51 ( struct V_73 * V_29 ,
int V_46 , T_2 V_45 )
{
struct V_27 * V_5 = F_19 ( V_29 ) ;
struct V_73 * V_28 = NULL ;
unsigned long V_74 ;
const int V_84 = sizeof( struct V_21 )
+ V_5 -> V_34 -> V_85 ;
struct V_21 * V_22 ;
struct V_21 * V_86 ;
int error , V_87 ;
V_22 = F_20 ( V_84 , V_4 ) ;
if ( ! V_22 ) {
F_9 ( V_88 L_3 , V_72 ) ;
return NULL ;
}
V_28 = & V_22 -> V_28 ;
F_52 ( V_28 ) ;
F_53 ( & V_22 -> V_82 ) ;
V_28 -> V_29 = F_24 ( V_29 ) ;
F_54 ( V_28 , L_4 , V_5 -> V_89 , V_46 , V_45 ) ;
V_28 -> V_90 = & V_91 ;
V_28 -> type = & V_79 ;
V_22 -> V_45 = V_45 ;
V_22 -> V_46 = V_46 ;
V_22 -> V_92 = 0 ;
F_21 ( & V_22 -> V_49 ) ;
F_21 ( & V_22 -> V_93 ) ;
V_22 -> V_75 = V_83 ;
V_22 -> V_94 = V_95 ;
V_22 -> V_96 = V_97 ;
V_98:
F_37 ( V_5 -> V_77 , V_74 ) ;
V_86 = F_43 ( V_29 , V_46 , V_45 ) ;
if ( V_86 )
goto V_99;
F_7 ( & V_22 -> V_49 , & V_5 -> V_100 ) ;
F_39 ( V_5 -> V_77 , V_74 ) ;
F_55 ( V_28 ) ;
if ( V_5 -> V_65 -> V_101 ) {
error = V_5 -> V_65 -> V_101 ( V_22 ) ;
if( error ) {
F_56 ( V_88 , V_28 , L_5 , error ) ;
F_35 ( V_22 ) ;
return NULL ;
}
}
F_24 ( V_28 ) ;
return V_22 ;
V_99:
V_87 = F_57 ( & V_86 -> V_82 ) ;
F_39 ( V_5 -> V_77 , V_74 ) ;
if ( V_87 ) {
F_28 ( V_28 ) ;
return V_86 ;
}
F_28 ( & V_86 -> V_28 ) ;
F_4 ( 1 ) ;
goto V_98;
}
void F_58 ( struct V_21 * V_22 )
{
F_59 ( V_22 -> V_75 == V_76 ) ;
F_49 ( V_22 ) ;
}
static void F_60 ( unsigned char * V_102 , int V_103 )
{
int V_104 = 0 ;
for (; V_103 > 0 ; ( -- V_103 , ++ V_102 ) ) {
if ( * V_102 == 0 )
V_104 = 1 ;
if ( V_104 || * V_102 < 0x20 || * V_102 > 0x7e )
* V_102 = ' ' ;
}
}
static int F_61 ( struct V_12 * V_13 , unsigned char * V_105 ,
int V_106 , int * V_107 )
{
unsigned char V_15 [ V_16 ] ;
int V_108 , V_109 , V_110 ;
int V_111 = 0 ;
int V_112 , V_113 , V_14 ;
struct V_114 V_115 ;
* V_107 = 0 ;
V_108 = V_13 -> V_116 ? V_13 -> V_116 : 36 ;
V_109 = V_108 ;
V_112 = 1 ;
V_117:
F_62 ( 3 , F_16 ( V_10 , V_13 ,
L_6 ,
V_112 , V_109 ) ) ;
for ( V_113 = 0 ; V_113 < 3 ; ++ V_113 ) {
int V_118 ;
memset ( V_15 , 0 , 6 ) ;
V_15 [ 0 ] = V_119 ;
V_15 [ 4 ] = ( unsigned char ) V_109 ;
memset ( V_105 , 0 , V_109 ) ;
V_14 = F_17 ( V_13 , V_15 , V_19 ,
V_105 , V_109 , & V_115 ,
V_120 / 2 + V_120 * V_121 , 3 ,
& V_118 ) ;
F_62 ( 3 , F_16 ( V_10 , V_13 ,
L_7 ,
V_14 ? L_8 : L_9 , V_14 ) ) ;
if ( V_14 ) {
if ( ( F_63 ( V_14 ) & V_122 ) &&
F_64 ( & V_115 ) ) {
if ( ( V_115 . V_123 == V_124 ) &&
( ( V_115 . V_125 == 0x28 ) ||
( V_115 . V_125 == 0x29 ) ) &&
( V_115 . V_126 == 0 ) )
continue;
}
} else {
if ( V_118 == V_109 )
continue;
}
break;
}
if ( V_14 == 0 ) {
F_60 ( & V_105 [ 8 ] , 8 ) ;
F_60 ( & V_105 [ 16 ] , 16 ) ;
F_60 ( & V_105 [ 32 ] , 4 ) ;
V_111 = V_105 [ 4 ] + 5 ;
if ( V_111 > 255 )
V_111 = V_108 ;
* V_107 = F_65 ( V_13 , & V_105 [ 8 ] ,
& V_105 [ 16 ] ) ;
if ( V_112 == 1 ) {
if ( V_127 & * V_107 )
V_110 = 36 ;
else if ( V_128 & * V_107 )
V_110 = 58 ;
else if ( V_13 -> V_116 )
V_110 = V_13 -> V_116 ;
else
V_110 = V_111 ;
if ( V_110 > V_109 ) {
V_109 = V_110 ;
V_112 = 2 ;
goto V_117;
}
}
} else if ( V_112 == 2 ) {
F_16 ( V_10 , V_13 ,
L_10
L_11 ,
V_109 ) ;
V_109 = V_108 ;
V_112 = 3 ;
goto V_117;
}
if ( V_14 )
return - V_129 ;
V_13 -> V_116 = F_66 ( V_109 , V_111 ) ;
if ( V_13 -> V_116 < 36 ) {
F_16 ( V_10 , V_13 ,
L_12
L_13 , V_13 -> V_116 ) ;
V_13 -> V_116 = 36 ;
}
V_13 -> V_94 = V_105 [ 2 ] & 0x07 ;
if ( V_13 -> V_94 >= 2 ||
( V_13 -> V_94 == 1 && ( V_105 [ 3 ] & 0x0f ) == 1 ) )
V_13 -> V_94 ++ ;
V_13 -> V_58 -> V_94 = V_13 -> V_94 ;
V_13 -> V_130 = 0 ;
if ( V_13 -> V_94 <= V_95 &&
V_13 -> V_94 != V_131 &&
! V_13 -> V_42 -> V_132 )
V_13 -> V_130 = 1 ;
return 0 ;
}
static int F_67 ( struct V_12 * V_13 , unsigned char * V_105 ,
int * V_107 , int V_133 )
{
int V_26 ;
V_13 -> V_134 = F_68 ( V_105 ,
F_69 ( V_135 , V_13 -> V_116 , 36 ) ,
V_36 ) ;
if ( V_13 -> V_134 == NULL )
return V_136 ;
V_13 -> V_38 = ( char * ) ( V_13 -> V_134 + 8 ) ;
V_13 -> V_40 = ( char * ) ( V_13 -> V_134 + 16 ) ;
V_13 -> V_41 = ( char * ) ( V_13 -> V_134 + 32 ) ;
if ( strncmp ( V_13 -> V_38 , L_14 , 8 ) == 0 ) {
V_13 -> V_137 = 1 ;
}
if ( * V_107 & V_138 ) {
V_13 -> type = V_139 ;
V_13 -> V_140 = 1 ;
} else {
V_13 -> type = ( V_105 [ 0 ] & 0x1f ) ;
V_13 -> V_140 = ( V_105 [ 1 ] & 0x80 ) >> 7 ;
if ( F_70 ( V_13 -> V_23 ) && V_13 -> type != V_141 ) {
F_16 ( V_142 , V_13 ,
L_15 ,
V_72 , V_13 -> type , ( unsigned int ) V_13 -> V_23 ) ;
V_13 -> type = V_141 ;
}
}
if ( V_13 -> type == V_143 || V_13 -> type == V_139 ) {
if ( ( * V_107 & V_144 ) == 0 )
* V_107 |= V_145 ;
}
V_13 -> V_146 = ( V_105 [ 0 ] >> 5 ) & 7 ;
V_13 -> V_147 = V_13 -> V_140 ;
V_13 -> V_148 = ( V_105 [ 7 ] & 1 ) && ( ( V_105 [ 3 ] & 7 ) == 2 ) ;
if ( V_13 -> V_94 >= V_149 ||
( V_13 -> V_116 > 56 && V_105 [ 56 ] & 0x04 ) )
V_13 -> V_150 = 1 ;
if ( V_105 [ 7 ] & 0x60 )
V_13 -> V_151 = 1 ;
if ( V_105 [ 7 ] & 0x10 )
V_13 -> V_152 = 1 ;
F_16 ( V_17 , V_13 , L_16
L_17 , F_71 ( V_13 -> type ) ,
V_13 -> V_38 , V_13 -> V_40 , V_13 -> V_41 ,
V_13 -> V_146 , V_105 [ 2 ] & 0x07 ,
( V_105 [ 3 ] & 0x0f ) == 1 ? L_18 : L_19 ) ;
if ( ( V_13 -> V_94 >= V_95 ) && ( V_105 [ 7 ] & 2 ) &&
! ( * V_107 & V_153 ) ) {
V_13 -> V_154 = 1 ;
V_13 -> V_155 = 1 ;
}
if ( ( * V_107 & V_156 ) == 0 )
V_13 -> V_61 = 0 ;
if ( * V_107 & V_157 )
V_13 -> V_158 = 1 ;
if ( * V_107 & V_159 )
V_13 -> V_160 = 1 ;
if ( * V_107 & V_161 )
F_72 ( V_13 -> V_62 , 512 ) ;
if ( * V_107 & V_162 )
V_13 -> V_163 = 1 ;
if ( * V_107 & V_164 )
V_21 ( V_13 ) -> V_165 = 1 ;
V_13 -> V_166 = 1 ;
if ( * V_107 & V_167 )
V_13 -> V_168 = 1 ;
if ( * V_107 & V_169 )
V_13 -> V_170 = 1 ;
if ( * V_107 & V_171 )
V_13 -> V_172 = 1 ;
if ( * V_107 & V_173 )
V_13 -> V_174 = 1 ;
V_26 = F_73 ( V_13 , V_175 ) ;
if ( V_26 ) {
V_26 = F_73 ( V_13 , V_176 ) ;
if ( V_26 ) {
F_16 ( V_88 , V_13 ,
L_20 ,
F_74 ( V_13 -> V_47 ) ) ;
return V_136 ;
}
}
if ( * V_107 & V_177 )
V_13 -> V_178 = 1 ;
if ( * V_107 & V_179 )
V_13 -> V_147 = 0 ;
if ( * V_107 & V_180 )
V_13 -> V_181 = 1 ;
if ( * V_107 & V_182 )
V_13 -> V_183 = 1 ;
V_13 -> V_184 = V_185 ;
if ( * V_107 & V_186 )
V_13 -> V_187 = 1 ;
else if ( * V_107 & V_188 )
V_13 -> V_189 = 1 ;
F_75 ( & V_13 -> V_57 ) ;
if ( V_13 -> V_42 -> V_65 -> V_190 ) {
V_26 = V_13 -> V_42 -> V_65 -> V_190 ( V_13 ) ;
if ( V_26 ) {
if ( V_26 != - V_69 ) {
F_16 ( V_88 , V_13 ,
L_21 ) ;
}
return V_136 ;
}
}
if ( V_13 -> V_94 >= V_149 )
F_76 ( V_13 ) ;
V_13 -> V_191 = V_13 -> V_192 ;
if ( ! V_133 && F_77 ( V_13 ) != 0 )
return V_136 ;
return V_193 ;
}
static unsigned char * F_78 ( unsigned char * V_194 , unsigned char * V_195 ,
unsigned V_196 , unsigned V_197 )
{
unsigned V_198 = 0 , V_199 ;
for ( V_199 = 0 ; V_199 + V_196 < V_197 && V_199 + V_196 < V_195 [ 4 ] + 5 ; V_199 ++ ) {
if ( V_195 [ V_199 + V_196 ] > ' ' ) {
V_194 [ V_199 ] = V_195 [ V_199 + V_196 ] ;
V_198 = V_199 + 1 ;
} else {
V_194 [ V_199 ] = ' ' ;
}
}
V_194 [ V_198 ] = 0 ;
return V_194 ;
}
static int F_79 ( struct V_21 * V_22 ,
T_1 V_23 , int * V_200 ,
struct V_12 * * V_201 , int V_202 ,
void * V_24 )
{
struct V_12 * V_13 ;
unsigned char * V_14 ;
int V_107 , V_203 = V_136 , V_106 = 256 ;
struct V_27 * V_5 = F_19 ( V_22 -> V_28 . V_29 ) ;
V_13 = F_80 ( V_22 , V_23 ) ;
if ( V_13 ) {
if ( V_202 || ! F_81 ( V_13 ) ) {
F_62 ( 3 , F_16 ( V_10 , V_13 ,
L_22 ,
F_82 ( & V_13 -> V_57 ) ) ) ;
if ( V_201 )
* V_201 = V_13 ;
else
F_83 ( V_13 ) ;
if ( V_200 )
* V_200 = F_65 ( V_13 ,
V_13 -> V_38 ,
V_13 -> V_40 ) ;
return V_193 ;
}
F_83 ( V_13 ) ;
} else
V_13 = F_18 ( V_22 , V_23 , V_24 ) ;
if ( ! V_13 )
goto V_37;
V_14 = F_3 ( V_106 , V_36 |
( ( V_5 -> V_204 ) ? V_205 : 0 ) ) ;
if ( ! V_14 )
goto V_206;
if ( F_61 ( V_13 , V_14 , V_106 , & V_107 ) )
goto V_207;
if ( V_200 )
* V_200 = V_107 ;
if ( ( ( V_14 [ 0 ] >> 5 ) == 3 ) && ! ( V_107 & V_208 ) ) {
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
V_203 = V_209 ;
goto V_207;
}
if ( ( ( V_14 [ 0 ] >> 5 ) == 1 || V_22 -> V_210 ) &&
( V_14 [ 0 ] & 0x1f ) == 0x1f &&
! F_70 ( V_23 ) ) {
F_62 ( 3 , F_16 ( V_10 , V_13 ,
L_28
L_29 ) ) ;
V_203 = V_209 ;
goto V_207;
}
V_203 = F_67 ( V_13 , V_14 , & V_107 , V_5 -> V_211 ) ;
if ( V_203 == V_193 ) {
if ( V_107 & V_212 ) {
V_13 -> V_147 = 0 ;
F_15 ( V_13 , V_14 ) ;
}
}
V_207:
F_14 ( V_14 ) ;
V_206:
if ( V_203 == V_193 ) {
if ( V_201 ) {
if ( F_84 ( V_13 ) == 0 ) {
* V_201 = V_13 ;
} else {
F_34 ( V_13 ) ;
V_203 = V_136 ;
}
}
} else
F_34 ( V_13 ) ;
V_37:
return V_203 ;
}
static void F_85 ( struct V_21 * V_22 ,
int V_107 , int V_94 , int V_202 )
{
T_2 V_213 ;
T_1 V_214 , V_23 ;
struct V_27 * V_5 = F_19 ( V_22 -> V_28 . V_29 ) ;
F_62 ( 3 , F_86 ( V_10 , V_22 ,
L_30 ) ) ;
V_213 = F_66 ( V_215 , V_5 -> V_216 ) ;
if ( V_107 & V_217 ) {
V_213 = V_5 -> V_216 ;
V_214 = 1 ;
} else
V_214 = 0 ;
if ( V_107 & V_218 )
V_213 = V_5 -> V_216 ;
if ( V_107 & V_219 )
V_213 = F_66 ( 5U , V_213 ) ;
if ( V_94 < V_149 && ! ( V_107 & V_220 ) )
V_213 = F_66 ( 8U , V_213 ) ;
if ( ! ( V_107 & V_221 ) )
V_213 = F_66 ( 256U , V_213 ) ;
for ( V_23 = 1 ; V_23 < V_213 ; ++ V_23 )
if ( ( F_79 ( V_22 , V_23 , NULL , NULL , V_202 ,
NULL ) != V_193 ) &&
! V_214 )
return;
}
T_1 F_87 ( struct V_222 * V_223 )
{
int V_224 ;
T_1 V_23 ;
V_23 = 0 ;
for ( V_224 = 0 ; V_224 < sizeof( V_23 ) ; V_224 += 2 )
V_23 = V_23 | ( ( ( T_1 ) V_223 -> V_222 [ V_224 ] << ( ( V_224 + 1 ) * 8 ) ) |
( ( T_1 ) V_223 -> V_222 [ V_224 + 1 ] << ( V_224 * 8 ) ) ) ;
return V_23 ;
}
void F_88 ( T_1 V_23 , struct V_222 * V_223 )
{
int V_224 ;
memset ( V_223 -> V_222 , 0 , sizeof( V_223 -> V_222 ) ) ;
for ( V_224 = 0 ; V_224 < sizeof( V_23 ) ; V_224 += 2 ) {
V_223 -> V_222 [ V_224 ] = ( V_23 >> 8 ) & 0xFF ;
V_223 -> V_222 [ V_224 + 1 ] = V_23 & 0xFF ;
V_23 = V_23 >> 16 ;
}
}
static int F_89 ( struct V_21 * V_22 , int V_107 ,
int V_202 )
{
char V_225 [ 64 ] ;
unsigned char V_15 [ V_16 ] ;
unsigned int V_226 ;
T_1 V_23 ;
unsigned int V_227 ;
unsigned int V_228 ;
int V_14 ;
struct V_222 * V_229 , * V_230 ;
T_3 * V_2 ;
struct V_114 V_115 ;
struct V_12 * V_13 ;
struct V_27 * V_5 = F_19 ( & V_22 -> V_28 ) ;
int V_26 = 0 ;
if ( V_107 & V_145 )
return 1 ;
if ( V_22 -> V_94 < V_95 &&
V_22 -> V_94 != V_131 )
return 1 ;
if ( V_22 -> V_94 < V_149 &&
( ! ( V_107 & V_144 ) || V_5 -> V_216 <= 8 ) )
return 1 ;
if ( V_107 & V_231 )
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
sprintf ( V_225 , L_31 ,
V_5 -> V_89 , V_13 -> V_46 , V_13 -> V_45 ) ;
V_226 = ( V_233 + 1 ) * sizeof( struct V_222 ) ;
V_230 = F_3 ( V_226 , V_36 |
( V_13 -> V_42 -> V_204 ? V_205 : 0 ) ) ;
if ( ! V_230 ) {
F_9 ( V_71 , V_72 ) ;
goto V_37;
}
V_15 [ 0 ] = V_234 ;
memset ( & V_15 [ 1 ] , 0 , 5 ) ;
V_15 [ 6 ] = ( unsigned char ) ( V_226 >> 24 ) & 0xff ;
V_15 [ 7 ] = ( unsigned char ) ( V_226 >> 16 ) & 0xff ;
V_15 [ 8 ] = ( unsigned char ) ( V_226 >> 8 ) & 0xff ;
V_15 [ 9 ] = ( unsigned char ) V_226 & 0xff ;
V_15 [ 10 ] = 0 ;
V_15 [ 11 ] = 0 ;
for ( V_228 = 0 ; V_228 < 3 ; V_228 ++ ) {
F_62 ( 3 , F_16 ( V_10 , V_13 ,
L_32 ,
V_228 ) ) ;
V_14 = F_17 ( V_13 , V_15 , V_19 ,
V_230 , V_226 , & V_115 ,
V_20 + 4 * V_120 , 3 , NULL ) ;
F_62 ( 3 , F_16 ( V_10 , V_13 ,
L_33
L_34 ,
V_14 ? L_8 : L_9 ,
V_228 , V_14 ) ) ;
if ( V_14 == 0 )
break;
else if ( F_64 ( & V_115 ) ) {
if ( V_115 . V_123 != V_124 )
break;
}
}
if ( V_14 ) {
V_26 = 1 ;
goto V_235;
}
V_2 = ( T_3 * ) V_230 -> V_222 ;
V_226 = ( ( V_2 [ 0 ] << 24 ) | ( V_2 [ 1 ] << 16 ) |
( V_2 [ 2 ] << 8 ) | ( V_2 [ 3 ] << 0 ) ) ;
V_227 = ( V_226 / sizeof( struct V_222 ) ) ;
if ( V_227 > V_233 ) {
F_16 ( V_142 , V_13 ,
L_35
L_36
L_37 ,
V_233 , V_227 ) ;
V_227 = V_233 ;
}
F_62 ( 3 , F_16 ( V_10 , V_13 ,
L_38 ) ) ;
for ( V_229 = & V_230 [ 1 ] ; V_229 <= & V_230 [ V_227 ] ; V_229 ++ ) {
V_23 = F_87 ( V_229 ) ;
if ( V_23 > V_13 -> V_42 -> V_216 ) {
F_16 ( V_142 , V_13 ,
L_39
L_40 , V_23 ) ;
} else {
int V_203 ;
V_203 = F_79 ( V_22 ,
V_23 , NULL , NULL , V_202 , NULL ) ;
if ( V_203 == V_136 ) {
F_16 ( V_88 , V_13 ,
L_41
L_42
L_43 , ( unsigned long long ) V_23 ) ;
break;
}
}
}
V_235:
F_14 ( V_230 ) ;
V_37:
F_83 ( V_13 ) ;
if ( F_81 ( V_13 ) )
F_34 ( V_13 ) ;
return V_26 ;
}
struct V_12 * F_90 ( struct V_27 * V_5 , T_2 V_46 ,
T_2 V_45 , T_1 V_23 , void * V_24 )
{
struct V_12 * V_13 = F_91 ( - V_236 ) ;
struct V_73 * V_29 = & V_5 -> V_237 ;
struct V_21 * V_22 ;
if ( strncmp ( V_238 , L_44 , 4 ) == 0 )
return F_91 ( - V_236 ) ;
V_22 = F_51 ( V_29 , V_46 , V_45 ) ;
if ( ! V_22 )
return F_91 ( - V_239 ) ;
F_92 ( V_22 ) ;
F_93 ( & V_5 -> V_240 ) ;
if ( ! V_5 -> V_211 )
F_1 () ;
if ( F_94 ( V_5 ) && F_95 ( V_5 ) == 0 ) {
F_79 ( V_22 , V_23 , NULL , & V_13 , 1 , V_24 ) ;
F_96 ( V_5 ) ;
}
F_97 ( & V_5 -> V_240 ) ;
F_98 ( V_22 ) ;
F_58 ( V_22 ) ;
F_28 ( & V_22 -> V_28 ) ;
return V_13 ;
}
int F_99 ( struct V_27 * V_42 , T_2 V_46 ,
T_2 V_241 , T_1 V_23 )
{
struct V_12 * V_13 =
F_90 ( V_42 , V_46 , V_241 , V_23 , NULL ) ;
if ( F_100 ( V_13 ) )
return F_101 ( V_13 ) ;
F_83 ( V_13 ) ;
return 0 ;
}
void F_102 ( struct V_73 * V_28 )
{
if ( ! V_28 -> V_242 )
return;
if ( F_103 ( V_28 -> V_242 -> V_243 ) ) {
struct V_244 * V_245 = F_104 ( V_28 -> V_242 ) ;
if ( V_245 -> V_202 )
V_245 -> V_202 ( V_28 ) ;
F_105 ( V_28 -> V_242 -> V_243 ) ;
}
}
static void F_106 ( struct V_73 * V_29 , unsigned int V_46 ,
unsigned int V_45 , T_1 V_23 , int V_202 )
{
struct V_27 * V_5 = F_19 ( V_29 ) ;
int V_107 = 0 ;
int V_203 ;
struct V_21 * V_22 ;
if ( V_5 -> V_246 == V_45 )
return;
V_22 = F_51 ( V_29 , V_46 , V_45 ) ;
if ( ! V_22 )
return;
F_92 ( V_22 ) ;
if ( V_23 != V_247 ) {
F_79 ( V_22 , V_23 , NULL , NULL , V_202 , NULL ) ;
goto V_248;
}
V_203 = F_79 ( V_22 , 0 , & V_107 , NULL , V_202 , NULL ) ;
if ( V_203 == V_193 || V_203 == V_209 ) {
if ( F_89 ( V_22 , V_107 , V_202 ) != 0 )
F_85 ( V_22 , V_107 ,
V_22 -> V_94 , V_202 ) ;
}
V_248:
F_98 ( V_22 ) ;
F_58 ( V_22 ) ;
F_28 ( & V_22 -> V_28 ) ;
}
void F_107 ( struct V_73 * V_29 , unsigned int V_46 ,
unsigned int V_45 , T_1 V_23 , int V_202 )
{
struct V_27 * V_5 = F_19 ( V_29 ) ;
if ( strncmp ( V_238 , L_44 , 4 ) == 0 )
return;
F_93 ( & V_5 -> V_240 ) ;
if ( ! V_5 -> V_211 )
F_1 () ;
if ( F_94 ( V_5 ) && F_95 ( V_5 ) == 0 ) {
F_106 ( V_29 , V_46 , V_45 , V_23 , V_202 ) ;
F_96 ( V_5 ) ;
}
F_97 ( & V_5 -> V_240 ) ;
}
static void F_108 ( struct V_27 * V_5 , unsigned int V_46 ,
unsigned int V_45 , T_1 V_23 , int V_202 )
{
T_2 V_249 ;
if ( V_45 == V_247 )
for ( V_45 = 0 ; V_45 < V_5 -> V_250 ; ++ V_45 ) {
if ( V_5 -> V_251 )
V_249 = V_5 -> V_250 - V_45 - 1 ;
else
V_249 = V_45 ;
F_106 ( & V_5 -> V_237 , V_46 ,
V_249 , V_23 , V_202 ) ;
}
else
F_106 ( & V_5 -> V_237 , V_46 ,
V_45 , V_23 , V_202 ) ;
}
int F_109 ( struct V_27 * V_5 , unsigned int V_46 ,
unsigned int V_45 , T_1 V_23 , int V_202 )
{
F_62 ( 3 , F_110 ( V_10 , V_5 ,
L_45 ,
V_72 , V_46 , V_45 , V_23 ) ) ;
if ( ( ( V_46 != V_247 ) && ( V_46 > V_5 -> V_252 ) ) ||
( ( V_45 != V_247 ) && ( V_45 >= V_5 -> V_250 ) ) ||
( ( V_23 != V_247 ) && ( V_23 >= V_5 -> V_216 ) ) )
return - V_253 ;
F_93 ( & V_5 -> V_240 ) ;
if ( ! V_5 -> V_211 )
F_1 () ;
if ( F_94 ( V_5 ) && F_95 ( V_5 ) == 0 ) {
if ( V_46 == V_247 )
for ( V_46 = 0 ; V_46 <= V_5 -> V_252 ;
V_46 ++ )
F_108 ( V_5 , V_46 , V_45 , V_23 ,
V_202 ) ;
else
F_108 ( V_5 , V_46 , V_45 , V_23 , V_202 ) ;
F_96 ( V_5 ) ;
}
F_97 ( & V_5 -> V_240 ) ;
return 0 ;
}
static void F_111 ( struct V_27 * V_5 )
{
struct V_12 * V_13 ;
F_112 (sdev, shost) {
if ( V_13 -> V_47 == V_254 )
continue;
if ( V_13 -> V_255 )
continue;
if ( ! F_94 ( V_5 ) ||
F_77 ( V_13 ) != 0 )
F_34 ( V_13 ) ;
}
}
static struct V_1 * F_113 ( struct V_27 * V_5 )
{
struct V_1 * V_2 ;
unsigned long V_74 ;
if ( strncmp ( V_238 , L_46 , 4 ) == 0 )
return NULL ;
if ( V_5 -> V_211 ) {
F_110 ( V_10 , V_5 , L_47 , V_72 ) ;
F_114 () ;
return NULL ;
}
V_2 = F_3 ( sizeof( * V_2 ) , V_4 ) ;
if ( ! V_2 )
goto V_256;
V_2 -> V_5 = F_115 ( V_5 ) ;
if ( ! V_2 -> V_5 )
goto V_256;
F_5 ( & V_2 -> V_6 ) ;
F_93 ( & V_5 -> V_240 ) ;
F_37 ( V_5 -> V_77 , V_74 ) ;
V_5 -> V_211 = 1 ;
F_39 ( V_5 -> V_77 , V_74 ) ;
F_97 ( & V_5 -> V_240 ) ;
F_6 ( & V_7 ) ;
if ( F_2 ( & V_3 ) )
F_13 ( & V_2 -> V_6 ) ;
F_7 ( & V_2 -> V_9 , & V_3 ) ;
F_8 ( & V_7 ) ;
return V_2 ;
V_256:
F_14 ( V_2 ) ;
return NULL ;
}
static void F_116 ( struct V_1 * V_2 )
{
struct V_27 * V_5 ;
unsigned long V_74 ;
if ( ! V_2 )
return;
V_5 = V_2 -> V_5 ;
F_93 ( & V_5 -> V_240 ) ;
if ( ! V_5 -> V_211 ) {
F_110 ( V_10 , V_5 , L_47 , V_72 ) ;
F_114 () ;
F_97 ( & V_5 -> V_240 ) ;
return;
}
F_10 ( & V_2 -> V_6 ) ;
F_111 ( V_5 ) ;
F_37 ( V_5 -> V_77 , V_74 ) ;
V_5 -> V_211 = 0 ;
F_39 ( V_5 -> V_77 , V_74 ) ;
F_97 ( & V_5 -> V_240 ) ;
F_6 ( & V_7 ) ;
F_11 ( & V_2 -> V_9 ) ;
if ( ! F_2 ( & V_3 ) ) {
struct V_1 * V_11 = F_12 ( V_3 . V_11 ,
struct V_1 , V_9 ) ;
F_13 ( & V_11 -> V_6 ) ;
}
F_8 ( & V_7 ) ;
F_96 ( V_5 ) ;
F_117 ( V_5 ) ;
F_14 ( V_2 ) ;
}
static void F_118 ( struct V_27 * V_5 )
{
if ( V_5 -> V_65 -> V_257 ) {
unsigned long V_258 = V_259 ;
if ( V_5 -> V_65 -> V_260 )
V_5 -> V_65 -> V_260 ( V_5 ) ;
while ( ! V_5 -> V_65 -> V_257 ( V_5 , V_259 - V_258 ) )
F_4 ( 10 ) ;
} else {
F_109 ( V_5 , V_247 , V_247 ,
V_247 , 0 ) ;
}
}
static void F_119 ( void * V_261 , T_4 V_262 )
{
struct V_1 * V_2 = V_261 ;
struct V_27 * V_5 = V_2 -> V_5 ;
F_118 ( V_5 ) ;
F_116 ( V_2 ) ;
}
void F_120 ( struct V_27 * V_5 )
{
struct V_1 * V_2 ;
if ( strncmp ( V_238 , L_44 , 4 ) == 0 )
return;
if ( F_95 ( V_5 ) < 0 )
return;
V_2 = F_113 ( V_5 ) ;
if ( ! V_2 ) {
F_118 ( V_5 ) ;
F_96 ( V_5 ) ;
return;
}
F_121 ( F_119 , V_2 ) ;
}
void F_122 ( struct V_27 * V_5 )
{
struct V_12 * V_13 ;
unsigned long V_74 ;
V_263:
F_37 ( V_5 -> V_77 , V_74 ) ;
F_44 (sdev, &shost->__devices, siblings) {
if ( V_13 -> V_47 == V_254 )
continue;
F_39 ( V_5 -> V_77 , V_74 ) ;
F_34 ( V_13 ) ;
goto V_263;
}
F_39 ( V_5 -> V_77 , V_74 ) ;
}
struct V_12 * F_123 ( struct V_27 * V_5 )
{
struct V_12 * V_13 = NULL ;
struct V_21 * V_22 ;
F_93 ( & V_5 -> V_240 ) ;
if ( ! F_94 ( V_5 ) )
goto V_37;
V_22 = F_51 ( & V_5 -> V_237 , 0 , V_5 -> V_246 ) ;
if ( ! V_22 )
goto V_37;
V_13 = F_18 ( V_22 , 0 , NULL ) ;
if ( V_13 )
V_13 -> V_61 = 0 ;
else
F_58 ( V_22 ) ;
F_28 ( & V_22 -> V_28 ) ;
V_37:
F_97 ( & V_5 -> V_240 ) ;
return V_13 ;
}
void F_124 ( struct V_12 * V_13 )
{
F_59 ( V_13 -> V_45 != V_13 -> V_42 -> V_246 ) ;
F_34 ( V_13 ) ;
}
