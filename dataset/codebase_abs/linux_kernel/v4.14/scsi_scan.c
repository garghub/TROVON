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
F_21 ( & V_13 -> V_43 ) ;
V_13 -> V_44 = V_45 ;
F_22 ( & V_13 -> V_46 ) ;
F_22 ( & V_13 -> V_47 ) ;
F_22 ( & V_13 -> V_48 ) ;
F_22 ( & V_13 -> V_49 ) ;
F_22 ( & V_13 -> V_50 ) ;
F_23 ( & V_13 -> V_51 ) ;
F_21 ( & V_13 -> V_52 ) ;
F_24 ( & V_13 -> V_53 , V_54 ) ;
F_24 ( & V_13 -> V_55 , V_56 ) ;
V_13 -> V_57 . V_29 = F_25 ( & V_22 -> V_28 ) ;
V_13 -> V_58 = V_22 ;
V_13 -> V_24 = V_24 ;
V_13 -> V_59 = V_60 ;
V_13 -> type = - 1 ;
V_13 -> V_61 = 1 ;
if ( F_26 ( V_5 ) )
V_13 -> V_62 = F_27 ( V_13 ) ;
else
V_13 -> V_62 = F_28 ( V_13 ) ;
if ( ! V_13 -> V_62 ) {
F_29 ( & V_22 -> V_28 ) ;
F_14 ( V_13 ) ;
goto V_33;
}
F_30 ( ! F_31 ( V_13 -> V_62 ) ) ;
V_13 -> V_62 -> V_63 = V_13 ;
if ( ! F_26 ( V_13 -> V_38 ) ) {
F_32 ( V_13 -> V_62 ,
V_13 -> V_38 -> V_64 , V_5 -> V_65 ,
V_5 -> V_66 -> V_67 ) ;
}
F_33 ( V_13 , V_13 -> V_38 -> V_64 ?
V_13 -> V_38 -> V_64 : 1 ) ;
F_34 ( V_13 ) ;
if ( V_5 -> V_66 -> V_68 ) {
V_26 = V_5 -> V_66 -> V_68 ( V_13 ) ;
if ( V_26 ) {
if ( V_26 == - V_69 )
V_25 = 0 ;
goto V_70;
}
}
return V_13 ;
V_70:
F_35 ( V_13 ) ;
V_33:
if ( V_25 )
F_9 ( V_71 , V_72 ) ;
return NULL ;
}
static void F_36 ( struct V_21 * V_22 )
{
struct V_73 * V_28 = & V_22 -> V_28 ;
struct V_27 * V_5 = F_19 ( V_28 -> V_29 ) ;
unsigned long V_74 ;
F_37 ( V_22 -> V_75 == V_76 ) ;
V_22 -> V_75 = V_76 ;
F_38 ( V_28 ) ;
F_39 ( V_5 -> V_77 , V_74 ) ;
if ( V_5 -> V_66 -> V_78 )
V_5 -> V_66 -> V_78 ( V_22 ) ;
F_40 ( & V_22 -> V_46 ) ;
F_41 ( V_5 -> V_77 , V_74 ) ;
F_29 ( V_28 ) ;
}
static void F_42 ( struct V_73 * V_28 )
{
struct V_73 * V_29 = V_28 -> V_29 ;
struct V_21 * V_22 = F_43 ( V_28 ) ;
F_14 ( V_22 ) ;
F_29 ( V_29 ) ;
}
int F_44 ( const struct V_73 * V_28 )
{
return V_28 -> type == & V_79 ;
}
static struct V_21 * F_45 ( struct V_73 * V_29 ,
int V_42 , T_2 V_41 )
{
struct V_21 * V_22 , * V_80 = NULL ;
struct V_27 * V_5 = F_19 ( V_29 ) ;
F_46 (starget, &shost->__targets, siblings) {
if ( V_22 -> V_41 == V_41 &&
V_22 -> V_42 == V_42 ) {
V_80 = V_22 ;
break;
}
}
if ( V_80 )
F_25 ( & V_80 -> V_28 ) ;
return V_80 ;
}
static void F_47 ( struct V_81 * V_81 )
{
struct V_21 * V_22
= F_48 ( V_81 , struct V_21 , V_82 ) ;
if ( ( V_22 -> V_75 != V_83 ) &&
( V_22 -> V_75 != V_84 ) ) {
F_49 ( & V_22 -> V_28 ) ;
F_50 ( & V_22 -> V_28 ) ;
}
F_36 ( V_22 ) ;
}
static void F_51 ( struct V_21 * V_22 )
{
F_52 ( & V_22 -> V_82 , F_47 ) ;
}
static struct V_21 * F_53 ( struct V_73 * V_29 ,
int V_42 , T_2 V_41 )
{
struct V_27 * V_5 = F_19 ( V_29 ) ;
struct V_73 * V_28 = NULL ;
unsigned long V_74 ;
const int V_85 = sizeof( struct V_21 )
+ V_5 -> V_30 -> V_86 ;
struct V_21 * V_22 ;
struct V_21 * V_87 ;
int error , V_88 ;
V_22 = F_20 ( V_85 , V_4 ) ;
if ( ! V_22 ) {
F_9 ( V_89 L_3 , V_72 ) ;
return NULL ;
}
V_28 = & V_22 -> V_28 ;
F_54 ( V_28 ) ;
F_55 ( & V_22 -> V_82 ) ;
V_28 -> V_29 = F_25 ( V_29 ) ;
F_56 ( V_28 , L_4 , V_5 -> V_90 , V_42 , V_41 ) ;
V_28 -> V_91 = & V_92 ;
V_28 -> type = & V_79 ;
V_22 -> V_41 = V_41 ;
V_22 -> V_42 = V_42 ;
V_22 -> V_93 = 0 ;
F_22 ( & V_22 -> V_46 ) ;
F_22 ( & V_22 -> V_94 ) ;
V_22 -> V_75 = V_83 ;
V_22 -> V_95 = V_96 ;
V_22 -> V_97 = V_98 ;
V_99:
F_39 ( V_5 -> V_77 , V_74 ) ;
V_87 = F_45 ( V_29 , V_42 , V_41 ) ;
if ( V_87 )
goto V_100;
F_7 ( & V_22 -> V_46 , & V_5 -> V_101 ) ;
F_41 ( V_5 -> V_77 , V_74 ) ;
F_57 ( V_28 ) ;
if ( V_5 -> V_66 -> V_102 ) {
error = V_5 -> V_66 -> V_102 ( V_22 ) ;
if( error ) {
F_58 ( V_89 , V_28 , L_5 , error ) ;
F_36 ( V_22 ) ;
return NULL ;
}
}
F_25 ( V_28 ) ;
return V_22 ;
V_100:
V_88 = F_59 ( & V_87 -> V_82 ) ;
F_41 ( V_5 -> V_77 , V_74 ) ;
if ( V_88 ) {
F_29 ( V_28 ) ;
return V_87 ;
}
F_29 ( & V_87 -> V_28 ) ;
F_4 ( 1 ) ;
goto V_99;
}
void F_60 ( struct V_21 * V_22 )
{
F_37 ( V_22 -> V_75 == V_76 ) ;
F_51 ( V_22 ) ;
}
void F_61 ( unsigned char * V_103 , int V_104 )
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
return - V_129 ;
V_13 -> V_117 = F_67 ( V_110 , V_112 ) ;
if ( V_13 -> V_117 < 36 ) {
if ( ! V_13 -> V_38 -> V_130 ) {
F_68 ( V_10 , V_13 -> V_38 ,
L_12
L_13 , V_13 -> V_117 ) ;
V_13 -> V_38 -> V_130 = 1 ;
}
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
! V_13 -> V_38 -> V_133 )
V_13 -> V_131 = 1 ;
return 0 ;
}
static int F_69 ( struct V_12 * V_13 , unsigned char * V_106 ,
int * V_108 , int V_134 )
{
int V_26 ;
V_13 -> V_135 = F_70 ( V_106 ,
F_71 ( V_136 , V_13 -> V_117 , 36 ) ,
V_32 ) ;
if ( V_13 -> V_135 == NULL )
return V_137 ;
V_13 -> V_34 = ( char * ) ( V_13 -> V_135 + 8 ) ;
V_13 -> V_36 = ( char * ) ( V_13 -> V_135 + 16 ) ;
V_13 -> V_37 = ( char * ) ( V_13 -> V_135 + 32 ) ;
if ( strncmp ( V_13 -> V_34 , L_14 , 8 ) == 0 ) {
V_13 -> V_138 = 1 ;
}
if ( * V_108 & V_139 ) {
V_13 -> type = V_140 ;
V_13 -> V_141 = 1 ;
} else {
V_13 -> type = ( V_106 [ 0 ] & 0x1f ) ;
V_13 -> V_141 = ( V_106 [ 1 ] & 0x80 ) >> 7 ;
if ( F_72 ( V_13 -> V_23 ) && V_13 -> type != V_142 ) {
F_16 ( V_143 , V_13 ,
L_15 ,
V_72 , V_13 -> type , ( unsigned int ) V_13 -> V_23 ) ;
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
L_17 , F_73 ( V_13 -> type ) ,
V_13 -> V_34 , V_13 -> V_36 , V_13 -> V_37 ,
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
F_74 ( V_13 -> V_62 , 512 ) ;
else if ( * V_108 & V_163 )
F_74 ( V_13 -> V_62 , 1024 ) ;
if ( * V_108 & V_164 )
V_13 -> V_165 = 1 ;
if ( * V_108 & V_166 )
V_21 ( V_13 ) -> V_167 = 1 ;
V_13 -> V_168 = 1 ;
if ( * V_108 & V_169 )
V_13 -> V_170 = 1 ;
F_75 ( & V_13 -> V_43 ) ;
V_26 = F_76 ( V_13 , V_171 ) ;
if ( V_26 )
V_26 = F_76 ( V_13 , V_172 ) ;
F_77 ( & V_13 -> V_43 ) ;
if ( V_26 ) {
F_16 ( V_89 , V_13 ,
L_20 ,
F_78 ( V_13 -> V_44 ) ) ;
return V_137 ;
}
if ( * V_108 & V_173 )
V_13 -> V_148 = 0 ;
if ( * V_108 & V_174 )
V_13 -> V_175 = 1 ;
if ( * V_108 & V_176 )
V_13 -> V_177 = 1 ;
if ( * V_108 & V_178 )
V_13 -> V_179 = 1 ;
V_13 -> V_180 = V_181 ;
if ( * V_108 & V_182 )
V_13 -> V_183 = 1 ;
else if ( * V_108 & V_184 )
V_13 -> V_185 = 1 ;
F_79 ( & V_13 -> V_57 ) ;
if ( V_13 -> V_38 -> V_66 -> V_186 ) {
V_26 = V_13 -> V_38 -> V_66 -> V_186 ( V_13 ) ;
if ( V_26 ) {
if ( V_26 != - V_69 ) {
F_16 ( V_89 , V_13 ,
L_21 ) ;
}
return V_137 ;
}
}
if ( V_13 -> V_95 >= V_150 )
F_80 ( V_13 ) ;
V_13 -> V_187 = V_13 -> V_188 ;
if ( ! V_134 && F_81 ( V_13 ) != 0 )
return V_137 ;
return V_189 ;
}
static unsigned char * F_82 ( unsigned char * V_190 , unsigned char * V_191 ,
unsigned V_192 , unsigned V_193 )
{
unsigned V_194 = 0 , V_195 ;
for ( V_195 = 0 ; V_195 + V_192 < V_193 && V_195 + V_192 < V_191 [ 4 ] + 5 ; V_195 ++ ) {
if ( V_191 [ V_195 + V_192 ] > ' ' ) {
V_190 [ V_195 ] = V_191 [ V_195 + V_192 ] ;
V_194 = V_195 + 1 ;
} else {
V_190 [ V_195 ] = ' ' ;
}
}
V_190 [ V_194 ] = 0 ;
return V_190 ;
}
static int F_83 ( struct V_21 * V_22 ,
T_1 V_23 , int * V_196 ,
struct V_12 * * V_197 ,
enum V_198 V_199 ,
void * V_24 )
{
struct V_12 * V_13 ;
unsigned char * V_14 ;
int V_108 , V_200 = V_137 , V_107 = 256 ;
struct V_27 * V_5 = F_19 ( V_22 -> V_28 . V_29 ) ;
V_13 = F_84 ( V_22 , V_23 ) ;
if ( V_13 ) {
if ( V_199 != V_201 || ! F_85 ( V_13 ) ) {
F_63 ( 3 , F_16 ( V_10 , V_13 ,
L_22 ,
F_86 ( & V_13 -> V_57 ) ) ) ;
if ( V_197 )
* V_197 = V_13 ;
else
F_87 ( V_13 ) ;
if ( V_196 )
* V_196 = F_66 ( V_13 ,
V_13 -> V_34 ,
V_13 -> V_36 ) ;
return V_189 ;
}
F_87 ( V_13 ) ;
} else
V_13 = F_18 ( V_22 , V_23 , V_24 ) ;
if ( ! V_13 )
goto V_33;
V_14 = F_3 ( V_107 , V_32 |
( ( V_5 -> V_202 ) ? V_203 : 0 ) ) ;
if ( ! V_14 )
goto V_204;
if ( F_62 ( V_13 , V_14 , V_107 , & V_108 ) )
goto V_205;
if ( V_196 )
* V_196 = V_108 ;
if ( ( V_14 [ 0 ] >> 5 ) == 3 ) {
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
V_200 = V_206 ;
goto V_205;
}
if ( ( ( V_14 [ 0 ] >> 5 ) == 1 || V_22 -> V_207 ) &&
( V_14 [ 0 ] & 0x1f ) == 0x1f &&
! F_72 ( V_23 ) ) {
F_63 ( 3 , F_16 ( V_10 , V_13 ,
L_28
L_29 ) ) ;
V_200 = V_206 ;
goto V_205;
}
V_200 = F_69 ( V_13 , V_14 , & V_108 , V_5 -> V_208 ) ;
if ( V_200 == V_189 ) {
if ( V_108 & V_209 ) {
V_13 -> V_148 = 0 ;
F_15 ( V_13 , V_14 ) ;
}
}
V_205:
F_14 ( V_14 ) ;
V_204:
if ( V_200 == V_189 ) {
if ( V_197 ) {
if ( F_88 ( V_13 ) == 0 ) {
* V_197 = V_13 ;
} else {
F_35 ( V_13 ) ;
V_200 = V_137 ;
}
}
} else
F_35 ( V_13 ) ;
V_33:
return V_200 ;
}
static void F_89 ( struct V_21 * V_22 ,
int V_108 , int V_95 ,
enum V_198 V_199 )
{
T_2 V_210 ;
T_1 V_211 , V_23 ;
struct V_27 * V_5 = F_19 ( V_22 -> V_28 . V_29 ) ;
F_63 ( 3 , F_90 ( V_10 , V_22 ,
L_30 ) ) ;
V_210 = F_67 ( V_212 , V_5 -> V_213 ) ;
if ( V_108 & V_214 ) {
V_210 = V_5 -> V_213 ;
V_211 = 1 ;
} else
V_211 = 0 ;
if ( V_108 & V_215 )
V_210 = V_5 -> V_213 ;
if ( V_108 & V_216 )
V_210 = F_67 ( 5U , V_210 ) ;
if ( V_95 < V_150 && ! ( V_108 & V_217 ) )
V_210 = F_67 ( 8U , V_210 ) ;
else
V_210 = F_67 ( 256U , V_210 ) ;
for ( V_23 = 1 ; V_23 < V_210 ; ++ V_23 )
if ( ( F_83 ( V_22 , V_23 , NULL , NULL , V_199 ,
NULL ) != V_189 ) &&
! V_211 )
return;
}
static int F_91 ( struct V_21 * V_22 , int V_108 ,
enum V_198 V_199 )
{
unsigned char V_15 [ V_16 ] ;
unsigned int V_218 ;
T_1 V_23 ;
unsigned int V_219 ;
unsigned int V_220 ;
int V_14 ;
struct V_221 * V_222 , * V_223 ;
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
( ! ( V_108 & V_145 ) || V_5 -> V_213 <= 8 ) )
return 1 ;
if ( V_108 & V_224 )
return 0 ;
if ( V_22 -> V_225 )
return 1 ;
if ( ! ( V_13 = F_84 ( V_22 , 0 ) ) ) {
V_13 = F_18 ( V_22 , 0 , NULL ) ;
if ( ! V_13 )
return 0 ;
if ( F_88 ( V_13 ) ) {
F_35 ( V_13 ) ;
return 0 ;
}
}
V_218 = ( 511 + 1 ) * sizeof( struct V_221 ) ;
V_99:
V_223 = F_3 ( V_218 , V_4 |
( V_13 -> V_38 -> V_202 ? V_203 : 0 ) ) ;
if ( ! V_223 ) {
F_9 ( V_71 , V_72 ) ;
goto V_33;
}
V_15 [ 0 ] = V_226 ;
memset ( & V_15 [ 1 ] , 0 , 5 ) ;
F_92 ( V_218 , & V_15 [ 6 ] ) ;
V_15 [ 10 ] = 0 ;
V_15 [ 11 ] = 0 ;
for ( V_220 = 0 ; V_220 < 3 ; V_220 ++ ) {
F_63 ( 3 , F_16 ( V_10 , V_13 ,
L_31 ,
V_220 ) ) ;
V_14 = F_17 ( V_13 , V_15 , V_19 ,
V_223 , V_218 , & V_116 ,
V_227 , 3 , NULL ) ;
F_63 ( 3 , F_16 ( V_10 , V_13 ,
L_32
L_33 ,
V_14 ? L_8 : L_9 ,
V_220 , V_14 ) ) ;
if ( V_14 == 0 )
break;
else if ( F_65 ( & V_116 ) ) {
if ( V_116 . V_124 != V_125 )
break;
}
}
if ( V_14 ) {
V_26 = 1 ;
goto V_228;
}
if ( F_93 ( V_223 -> V_221 ) +
sizeof( struct V_221 ) > V_218 ) {
V_218 = F_93 ( V_223 -> V_221 ) +
sizeof( struct V_221 ) ;
F_14 ( V_223 ) ;
goto V_99;
}
V_218 = F_93 ( V_223 -> V_221 ) ;
V_219 = ( V_218 / sizeof( struct V_221 ) ) ;
F_63 ( 3 , F_16 ( V_10 , V_13 ,
L_34 ) ) ;
for ( V_222 = & V_223 [ 1 ] ; V_222 <= & V_223 [ V_219 ] ; V_222 ++ ) {
V_23 = F_94 ( V_222 ) ;
if ( V_23 > V_13 -> V_38 -> V_213 ) {
F_16 ( V_143 , V_13 ,
L_35
L_36 , V_23 ) ;
} else {
int V_200 ;
V_200 = F_83 ( V_22 ,
V_23 , NULL , NULL , V_199 , NULL ) ;
if ( V_200 == V_137 ) {
F_16 ( V_89 , V_13 ,
L_37
L_38
L_39 , ( unsigned long long ) V_23 ) ;
break;
}
}
}
V_228:
F_14 ( V_223 ) ;
V_33:
if ( F_85 ( V_13 ) )
F_35 ( V_13 ) ;
F_87 ( V_13 ) ;
return V_26 ;
}
struct V_12 * F_95 ( struct V_27 * V_5 , T_2 V_42 ,
T_2 V_41 , T_1 V_23 , void * V_24 )
{
struct V_12 * V_13 = F_96 ( - V_229 ) ;
struct V_73 * V_29 = & V_5 -> V_230 ;
struct V_21 * V_22 ;
if ( strncmp ( V_231 , L_40 , 4 ) == 0 )
return F_96 ( - V_229 ) ;
V_22 = F_53 ( V_29 , V_42 , V_41 ) ;
if ( ! V_22 )
return F_96 ( - V_232 ) ;
F_97 ( V_22 ) ;
F_75 ( & V_5 -> V_233 ) ;
if ( ! V_5 -> V_208 )
F_1 () ;
if ( F_98 ( V_5 ) && F_99 ( V_5 ) == 0 ) {
F_83 ( V_22 , V_23 , NULL , & V_13 , 1 , V_24 ) ;
F_100 ( V_5 ) ;
}
F_77 ( & V_5 -> V_233 ) ;
F_101 ( V_22 ) ;
F_60 ( V_22 ) ;
F_29 ( & V_22 -> V_28 ) ;
return V_13 ;
}
int F_102 ( struct V_27 * V_38 , T_2 V_42 ,
T_2 V_234 , T_1 V_23 )
{
struct V_12 * V_13 =
F_95 ( V_38 , V_42 , V_234 , V_23 , NULL ) ;
if ( F_103 ( V_13 ) )
return F_104 ( V_13 ) ;
F_87 ( V_13 ) ;
return 0 ;
}
void F_105 ( struct V_73 * V_28 )
{
struct V_12 * V_13 = F_106 ( V_28 ) ;
F_107 ( V_28 ) ;
F_80 ( V_13 ) ;
if ( V_13 -> V_235 && V_13 -> V_235 -> V_199 )
V_13 -> V_235 -> V_199 ( V_13 ) ;
if ( V_28 -> V_236 && F_108 ( V_28 -> V_236 -> V_237 ) ) {
struct V_238 * V_239 = F_109 ( V_28 -> V_236 ) ;
if ( V_239 -> V_199 )
V_239 -> V_199 ( V_28 ) ;
F_110 ( V_28 -> V_236 -> V_237 ) ;
}
F_111 ( V_28 ) ;
}
static void F_112 ( struct V_73 * V_29 , unsigned int V_42 ,
unsigned int V_41 , T_1 V_23 , enum V_198 V_199 )
{
struct V_27 * V_5 = F_19 ( V_29 ) ;
int V_108 = 0 ;
int V_200 ;
struct V_21 * V_22 ;
if ( V_5 -> V_240 == V_41 )
return;
V_22 = F_53 ( V_29 , V_42 , V_41 ) ;
if ( ! V_22 )
return;
F_97 ( V_22 ) ;
if ( V_23 != V_241 ) {
F_83 ( V_22 , V_23 , NULL , NULL , V_199 , NULL ) ;
goto V_242;
}
V_200 = F_83 ( V_22 , 0 , & V_108 , NULL , V_199 , NULL ) ;
if ( V_200 == V_189 || V_200 == V_206 ) {
if ( F_91 ( V_22 , V_108 , V_199 ) != 0 )
F_89 ( V_22 , V_108 ,
V_22 -> V_95 , V_199 ) ;
}
V_242:
F_101 ( V_22 ) ;
F_60 ( V_22 ) ;
F_29 ( & V_22 -> V_28 ) ;
}
void F_113 ( struct V_73 * V_29 , unsigned int V_42 ,
unsigned int V_41 , T_1 V_23 , enum V_198 V_199 )
{
struct V_27 * V_5 = F_19 ( V_29 ) ;
if ( strncmp ( V_231 , L_40 , 4 ) == 0 )
return;
if ( V_199 != V_243 &&
strncmp ( V_231 , L_41 , 6 ) == 0 )
return;
F_75 ( & V_5 -> V_233 ) ;
if ( ! V_5 -> V_208 )
F_1 () ;
if ( F_98 ( V_5 ) && F_99 ( V_5 ) == 0 ) {
F_112 ( V_29 , V_42 , V_41 , V_23 , V_199 ) ;
F_100 ( V_5 ) ;
}
F_77 ( & V_5 -> V_233 ) ;
}
static void F_114 ( struct V_27 * V_5 , unsigned int V_42 ,
unsigned int V_41 , T_1 V_23 ,
enum V_198 V_199 )
{
T_2 V_244 ;
if ( V_41 == V_241 )
for ( V_41 = 0 ; V_41 < V_5 -> V_245 ; ++ V_41 ) {
if ( V_5 -> V_246 )
V_244 = V_5 -> V_245 - V_41 - 1 ;
else
V_244 = V_41 ;
F_112 ( & V_5 -> V_230 , V_42 ,
V_244 , V_23 , V_199 ) ;
}
else
F_112 ( & V_5 -> V_230 , V_42 ,
V_41 , V_23 , V_199 ) ;
}
int F_115 ( struct V_27 * V_5 , unsigned int V_42 ,
unsigned int V_41 , T_1 V_23 ,
enum V_198 V_199 )
{
F_63 ( 3 , F_68 ( V_10 , V_5 ,
L_42 ,
V_72 , V_42 , V_41 , V_23 ) ) ;
if ( ( ( V_42 != V_241 ) && ( V_42 > V_5 -> V_247 ) ) ||
( ( V_41 != V_241 ) && ( V_41 >= V_5 -> V_245 ) ) ||
( ( V_23 != V_241 ) && ( V_23 >= V_5 -> V_213 ) ) )
return - V_248 ;
F_75 ( & V_5 -> V_233 ) ;
if ( ! V_5 -> V_208 )
F_1 () ;
if ( F_98 ( V_5 ) && F_99 ( V_5 ) == 0 ) {
if ( V_42 == V_241 )
for ( V_42 = 0 ; V_42 <= V_5 -> V_247 ;
V_42 ++ )
F_114 ( V_5 , V_42 , V_41 , V_23 ,
V_199 ) ;
else
F_114 ( V_5 , V_42 , V_41 , V_23 , V_199 ) ;
F_100 ( V_5 ) ;
}
F_77 ( & V_5 -> V_233 ) ;
return 0 ;
}
static void F_116 ( struct V_27 * V_5 )
{
struct V_12 * V_13 ;
F_117 (sdev, shost) {
if ( V_13 -> V_44 == V_249 )
continue;
if ( V_13 -> V_250 )
continue;
if ( ! F_98 ( V_5 ) ||
F_81 ( V_13 ) != 0 )
F_35 ( V_13 ) ;
}
}
static struct V_1 * F_118 ( struct V_27 * V_5 )
{
struct V_1 * V_2 ;
unsigned long V_74 ;
if ( strncmp ( V_231 , L_43 , 4 ) == 0 )
return NULL ;
if ( V_5 -> V_208 ) {
F_68 ( V_251 , V_5 , L_44 , V_72 ) ;
return NULL ;
}
V_2 = F_3 ( sizeof( * V_2 ) , V_4 ) ;
if ( ! V_2 )
goto V_252;
V_2 -> V_5 = F_119 ( V_5 ) ;
if ( ! V_2 -> V_5 )
goto V_252;
F_5 ( & V_2 -> V_6 ) ;
F_75 ( & V_5 -> V_233 ) ;
F_39 ( V_5 -> V_77 , V_74 ) ;
V_5 -> V_208 = 1 ;
F_41 ( V_5 -> V_77 , V_74 ) ;
F_77 ( & V_5 -> V_233 ) ;
F_6 ( & V_7 ) ;
if ( F_2 ( & V_3 ) )
F_13 ( & V_2 -> V_6 ) ;
F_7 ( & V_2 -> V_9 , & V_3 ) ;
F_8 ( & V_7 ) ;
return V_2 ;
V_252:
F_14 ( V_2 ) ;
return NULL ;
}
static void F_120 ( struct V_1 * V_2 )
{
struct V_27 * V_5 ;
unsigned long V_74 ;
if ( ! V_2 )
return;
V_5 = V_2 -> V_5 ;
F_75 ( & V_5 -> V_233 ) ;
if ( ! V_5 -> V_208 ) {
F_68 ( V_10 , V_5 , L_44 , V_72 ) ;
F_121 () ;
F_77 ( & V_5 -> V_233 ) ;
return;
}
F_10 ( & V_2 -> V_6 ) ;
F_116 ( V_5 ) ;
F_39 ( V_5 -> V_77 , V_74 ) ;
V_5 -> V_208 = 0 ;
F_41 ( V_5 -> V_77 , V_74 ) ;
F_77 ( & V_5 -> V_233 ) ;
F_6 ( & V_7 ) ;
F_11 ( & V_2 -> V_9 ) ;
if ( ! F_2 ( & V_3 ) ) {
struct V_1 * V_11 = F_12 ( V_3 . V_11 ,
struct V_1 , V_9 ) ;
F_13 ( & V_11 -> V_6 ) ;
}
F_8 ( & V_7 ) ;
F_100 ( V_5 ) ;
F_122 ( V_5 ) ;
F_14 ( V_2 ) ;
}
static void F_123 ( struct V_27 * V_5 )
{
if ( V_5 -> V_66 -> V_253 ) {
unsigned long V_254 = V_255 ;
if ( V_5 -> V_66 -> V_256 )
V_5 -> V_66 -> V_256 ( V_5 ) ;
while ( ! V_5 -> V_66 -> V_253 ( V_5 , V_255 - V_254 ) )
F_4 ( 10 ) ;
} else {
F_115 ( V_5 , V_241 , V_241 ,
V_241 , 0 ) ;
}
}
static void F_124 ( void * V_257 , T_3 V_258 )
{
struct V_1 * V_2 = V_257 ;
struct V_27 * V_5 = V_2 -> V_5 ;
F_123 ( V_5 ) ;
F_120 ( V_2 ) ;
}
void F_125 ( struct V_27 * V_5 )
{
struct V_1 * V_2 ;
if ( strncmp ( V_231 , L_40 , 4 ) == 0 ||
strncmp ( V_231 , L_41 , 6 ) == 0 )
return;
if ( F_99 ( V_5 ) < 0 )
return;
V_2 = F_118 ( V_5 ) ;
if ( ! V_2 ) {
F_123 ( V_5 ) ;
F_100 ( V_5 ) ;
return;
}
F_126 ( F_124 , V_2 ) ;
}
void F_127 ( struct V_27 * V_5 )
{
struct V_12 * V_13 ;
unsigned long V_74 ;
V_259:
F_39 ( V_5 -> V_77 , V_74 ) ;
F_46 (sdev, &shost->__devices, siblings) {
if ( V_13 -> V_44 == V_249 )
continue;
F_41 ( V_5 -> V_77 , V_74 ) ;
F_35 ( V_13 ) ;
goto V_259;
}
F_41 ( V_5 -> V_77 , V_74 ) ;
}
struct V_12 * F_128 ( struct V_27 * V_5 )
{
struct V_12 * V_13 = NULL ;
struct V_21 * V_22 ;
F_75 ( & V_5 -> V_233 ) ;
if ( ! F_98 ( V_5 ) )
goto V_33;
V_22 = F_53 ( & V_5 -> V_230 , 0 , V_5 -> V_240 ) ;
if ( ! V_22 )
goto V_33;
V_13 = F_18 ( V_22 , 0 , NULL ) ;
if ( V_13 )
V_13 -> V_61 = 0 ;
else
F_60 ( V_22 ) ;
F_29 ( & V_22 -> V_28 ) ;
V_33:
F_77 ( & V_5 -> V_233 ) ;
return V_13 ;
}
void F_129 ( struct V_12 * V_13 )
{
F_37 ( V_13 -> V_41 != V_13 -> V_38 -> V_240 ) ;
F_35 ( V_13 ) ;
}
