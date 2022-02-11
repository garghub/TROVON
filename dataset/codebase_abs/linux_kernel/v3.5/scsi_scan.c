int F_1 ( void )
{
struct V_1 * V_2 ;
do {
if ( F_2 ( & V_3 ) )
goto V_4;
V_2 = F_3 ( sizeof( * V_2 ) , V_5 ) ;
if ( ! V_2 )
F_4 ( 1 ) ;
} while ( ! V_2 );
V_2 -> V_6 = NULL ;
F_5 ( & V_2 -> V_7 ) ;
F_6 ( & V_8 ) ;
if ( F_2 ( & V_3 ) )
goto V_9;
F_7 ( & V_2 -> V_10 , & V_3 ) ;
F_8 ( & V_8 ) ;
F_9 ( V_11 L_1 ) ;
F_10 ( & V_2 -> V_7 ) ;
F_6 ( & V_8 ) ;
F_11 ( & V_2 -> V_10 ) ;
if ( ! F_2 ( & V_3 ) ) {
struct V_1 * V_12 = F_12 ( V_3 . V_12 ,
struct V_1 , V_10 ) ;
F_13 ( & V_12 -> V_7 ) ;
}
V_9:
F_8 ( & V_8 ) ;
F_14 ( V_2 ) ;
V_4:
F_15 ( & V_13 ) ;
return 0 ;
}
static void F_16 ( struct V_14 * V_15 ,
unsigned char * V_16 )
{
unsigned char V_17 [ V_18 ] ;
F_9 ( V_19 L_2 ) ;
V_17 [ 0 ] = V_20 ;
V_17 [ 1 ] = 0 ;
V_17 [ 2 ] = 0x2e ;
V_17 [ 3 ] = 0 ;
V_17 [ 4 ] = 0x2a ;
V_17 [ 5 ] = 0 ;
F_17 ( V_15 , V_17 , V_21 , V_16 , 0x2a , NULL ,
V_22 , 3 , NULL ) ;
}
static struct V_14 * F_18 ( struct V_23 * V_24 ,
unsigned int V_25 , void * V_26 )
{
struct V_14 * V_15 ;
int V_27 = 1 , V_28 ;
struct V_29 * V_6 = F_19 ( V_24 -> V_30 . V_31 ) ;
extern void V_32 ( struct V_33 * V_34 ) ;
extern void V_35 ( struct V_33 * V_34 ) ;
V_15 = F_20 ( sizeof( * V_15 ) + V_6 -> V_36 -> V_37 ,
V_38 ) ;
if ( ! V_15 )
goto V_4;
V_15 -> V_39 = V_40 ;
V_15 -> V_41 = V_40 ;
V_15 -> V_42 = V_40 ;
V_15 -> V_43 = V_6 ;
V_15 -> V_44 = V_45 ;
V_15 -> V_46 = V_24 -> V_46 ;
V_15 -> V_25 = V_25 ;
V_15 -> V_47 = V_24 -> V_47 ;
V_15 -> V_48 = V_49 ;
F_21 ( & V_15 -> V_50 ) ;
F_21 ( & V_15 -> V_51 ) ;
F_21 ( & V_15 -> V_52 ) ;
F_21 ( & V_15 -> V_53 ) ;
F_21 ( & V_15 -> V_54 ) ;
F_22 ( & V_15 -> V_55 ) ;
F_23 ( & V_15 -> V_56 , V_32 ) ;
F_23 ( & V_15 -> V_57 , V_35 ) ;
V_15 -> V_58 . V_31 = F_24 ( & V_24 -> V_30 ) ;
V_15 -> V_59 = V_24 ;
V_15 -> V_26 = V_26 ;
V_15 -> V_60 = V_61 ;
V_15 -> type = - 1 ;
V_15 -> V_62 = 1 ;
V_15 -> V_63 = F_25 ( V_15 ) ;
if ( ! V_15 -> V_63 ) {
F_26 ( & V_24 -> V_30 ) ;
F_14 ( V_15 ) ;
goto V_4;
}
F_27 ( ! F_28 ( V_15 -> V_63 ) ) ;
V_15 -> V_63 -> V_64 = V_15 ;
F_29 ( V_15 , 0 , V_15 -> V_43 -> V_65 ) ;
F_30 ( V_15 ) ;
if ( V_6 -> V_66 -> V_67 ) {
V_28 = V_6 -> V_66 -> V_67 ( V_15 ) ;
if ( V_28 ) {
if ( V_28 == - V_68 )
V_27 = 0 ;
goto V_69;
}
}
return V_15 ;
V_69:
F_31 ( V_15 ) ;
V_4:
if ( V_27 )
F_9 ( V_70 , V_71 ) ;
return NULL ;
}
static void F_32 ( struct V_23 * V_24 )
{
struct V_72 * V_30 = & V_24 -> V_30 ;
struct V_29 * V_6 = F_19 ( V_30 -> V_31 ) ;
unsigned long V_73 ;
F_33 ( V_30 ) ;
F_34 ( V_6 -> V_74 , V_73 ) ;
if ( V_6 -> V_66 -> V_75 )
V_6 -> V_66 -> V_75 ( V_24 ) ;
F_35 ( & V_24 -> V_50 ) ;
F_36 ( V_6 -> V_74 , V_73 ) ;
F_26 ( V_30 ) ;
}
static void F_37 ( struct V_72 * V_30 )
{
struct V_72 * V_31 = V_30 -> V_31 ;
struct V_23 * V_24 = F_38 ( V_30 ) ;
F_14 ( V_24 ) ;
F_26 ( V_31 ) ;
}
int F_39 ( const struct V_72 * V_30 )
{
return V_30 -> type == & V_76 ;
}
static struct V_23 * F_40 ( struct V_72 * V_31 ,
int V_47 , T_1 V_46 )
{
struct V_23 * V_24 , * V_77 = NULL ;
struct V_29 * V_6 = F_19 ( V_31 ) ;
F_41 (starget, &shost->__targets, siblings) {
if ( V_24 -> V_46 == V_46 &&
V_24 -> V_47 == V_47 ) {
V_77 = V_24 ;
break;
}
}
if ( V_77 )
F_24 ( & V_77 -> V_30 ) ;
return V_77 ;
}
static struct V_23 * F_42 ( struct V_72 * V_31 ,
int V_47 , T_1 V_46 )
{
struct V_29 * V_6 = F_19 ( V_31 ) ;
struct V_72 * V_30 = NULL ;
unsigned long V_73 ;
const int V_78 = sizeof( struct V_23 )
+ V_6 -> V_36 -> V_79 ;
struct V_23 * V_24 ;
struct V_23 * V_80 ;
int error ;
V_24 = F_20 ( V_78 , V_5 ) ;
if ( ! V_24 ) {
F_9 ( V_81 L_3 , V_71 ) ;
return NULL ;
}
V_30 = & V_24 -> V_30 ;
F_43 ( V_30 ) ;
V_24 -> V_82 = 1 ;
V_30 -> V_31 = F_24 ( V_31 ) ;
F_44 ( V_30 , L_4 , V_6 -> V_83 , V_47 , V_46 ) ;
V_30 -> V_84 = & V_85 ;
V_30 -> type = & V_76 ;
V_24 -> V_46 = V_46 ;
V_24 -> V_47 = V_47 ;
V_24 -> V_86 = 0 ;
F_21 ( & V_24 -> V_50 ) ;
F_21 ( & V_24 -> V_87 ) ;
V_24 -> V_88 = V_89 ;
V_24 -> V_90 = V_91 ;
V_24 -> V_92 = V_93 ;
V_94:
F_34 ( V_6 -> V_74 , V_73 ) ;
V_80 = F_40 ( V_31 , V_47 , V_46 ) ;
if ( V_80 )
goto V_95;
F_7 ( & V_24 -> V_50 , & V_6 -> V_96 ) ;
F_36 ( V_6 -> V_74 , V_73 ) ;
F_45 ( V_30 ) ;
if ( V_6 -> V_66 -> V_97 ) {
error = V_6 -> V_66 -> V_97 ( V_24 ) ;
if( error ) {
F_46 ( V_81 , V_30 , L_5 , error ) ;
F_32 ( V_24 ) ;
return NULL ;
}
}
F_24 ( V_30 ) ;
return V_24 ;
V_95:
V_80 -> V_82 ++ ;
F_36 ( V_6 -> V_74 , V_73 ) ;
if ( V_80 -> V_88 != V_98 ) {
F_26 ( V_30 ) ;
return V_80 ;
}
F_26 ( & V_80 -> V_30 ) ;
F_47 () ;
goto V_94;
}
static void F_48 ( struct V_33 * V_34 )
{
struct V_23 * V_24 =
F_49 ( V_34 , struct V_23 , V_99 . V_34 ) ;
F_50 ( & V_24 -> V_30 ) ;
F_51 ( & V_24 -> V_30 ) ;
F_32 ( V_24 ) ;
}
void F_52 ( struct V_23 * V_24 )
{
struct V_29 * V_6 = F_19 ( V_24 -> V_30 . V_31 ) ;
unsigned long V_73 ;
enum V_100 V_88 ;
int V_101 = 0 ;
F_34 ( V_6 -> V_74 , V_73 ) ;
V_88 = V_24 -> V_88 ;
if ( -- V_24 -> V_82 == 0 && F_2 ( & V_24 -> V_87 ) ) {
V_101 = 1 ;
V_24 -> V_88 = V_98 ;
}
F_36 ( V_6 -> V_74 , V_73 ) ;
if ( ! V_101 )
return;
F_53 ( V_88 == V_98 ) ;
if ( V_88 == V_89 )
F_32 ( V_24 ) ;
else
F_54 ( F_48 ,
& V_24 -> V_99 ) ;
}
static void F_55 ( unsigned char * V_102 , int V_103 )
{
int V_104 = 0 ;
for (; V_103 > 0 ; ( -- V_103 , ++ V_102 ) ) {
if ( * V_102 == 0 )
V_104 = 1 ;
if ( V_104 || * V_102 < 0x20 || * V_102 > 0x7e )
* V_102 = ' ' ;
}
}
static int F_56 ( struct V_14 * V_15 , unsigned char * V_105 ,
int V_106 , int * V_107 )
{
unsigned char V_17 [ V_18 ] ;
int V_108 , V_109 , V_110 ;
int V_111 = 0 ;
int V_112 , V_113 , V_16 ;
struct V_114 V_115 ;
* V_107 = 0 ;
V_108 = V_15 -> V_116 ? V_15 -> V_116 : 36 ;
V_109 = V_108 ;
V_112 = 1 ;
V_117:
F_57 ( 3 , F_58 ( V_11 , V_15 ,
L_6 ,
V_112 , V_109 ) ) ;
for ( V_113 = 0 ; V_113 < 3 ; ++ V_113 ) {
int V_118 ;
memset ( V_17 , 0 , 6 ) ;
V_17 [ 0 ] = V_119 ;
V_17 [ 4 ] = ( unsigned char ) V_109 ;
memset ( V_105 , 0 , V_109 ) ;
V_16 = F_17 ( V_15 , V_17 , V_21 ,
V_105 , V_109 , & V_115 ,
V_120 / 2 + V_120 * V_121 , 3 ,
& V_118 ) ;
F_57 ( 3 , F_9 ( V_11 L_7
L_8 ,
V_16 ? L_9 : L_10 , V_16 ) ) ;
if ( V_16 ) {
if ( ( F_59 ( V_16 ) & V_122 ) &&
F_60 ( & V_115 ) ) {
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
if ( V_16 == 0 ) {
F_55 ( & V_105 [ 8 ] , 8 ) ;
F_55 ( & V_105 [ 16 ] , 16 ) ;
F_55 ( & V_105 [ 32 ] , 4 ) ;
V_111 = V_105 [ 4 ] + 5 ;
if ( V_111 > 255 )
V_111 = V_108 ;
* V_107 = F_61 ( V_15 , & V_105 [ 8 ] ,
& V_105 [ 16 ] ) ;
if ( V_112 == 1 ) {
if ( V_127 & * V_107 )
V_110 = 36 ;
else if ( V_128 & * V_107 )
V_110 = 58 ;
else if ( V_15 -> V_116 )
V_110 = V_15 -> V_116 ;
else
V_110 = V_111 ;
if ( V_110 > V_109 ) {
V_109 = V_110 ;
V_112 = 2 ;
goto V_117;
}
}
} else if ( V_112 == 2 ) {
F_9 ( V_11 L_11
L_12 ,
V_109 ) ;
V_109 = V_108 ;
V_112 = 3 ;
goto V_117;
}
if ( V_16 )
return - V_129 ;
V_15 -> V_116 = F_62 ( V_109 , V_111 ) ;
if ( V_15 -> V_116 < 36 ) {
F_9 ( V_11 L_13
L_14 , V_15 -> V_116 ) ;
V_15 -> V_116 = 36 ;
}
V_15 -> V_90 = V_105 [ 2 ] & 0x07 ;
if ( V_15 -> V_90 >= 2 ||
( V_15 -> V_90 == 1 && ( V_105 [ 3 ] & 0x0f ) == 1 ) )
V_15 -> V_90 ++ ;
V_15 -> V_59 -> V_90 = V_15 -> V_90 ;
return 0 ;
}
static int F_63 ( struct V_14 * V_15 , unsigned char * V_105 ,
int * V_107 , int V_130 )
{
int V_28 ;
V_15 -> V_131 = F_64 ( V_105 ,
F_65 ( V_132 , V_15 -> V_116 , 36 ) ,
V_38 ) ;
if ( V_15 -> V_131 == NULL )
return V_133 ;
V_15 -> V_39 = ( char * ) ( V_15 -> V_131 + 8 ) ;
V_15 -> V_41 = ( char * ) ( V_15 -> V_131 + 16 ) ;
V_15 -> V_42 = ( char * ) ( V_15 -> V_131 + 32 ) ;
if ( * V_107 & V_134 ) {
V_15 -> type = V_135 ;
V_15 -> V_136 = 1 ;
} else {
V_15 -> type = ( V_105 [ 0 ] & 0x1f ) ;
V_15 -> V_136 = ( V_105 [ 1 ] & 0x80 ) >> 7 ;
}
switch ( V_15 -> type ) {
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
V_15 -> V_149 = 1 ;
break;
case V_135 :
case V_150 :
V_15 -> V_149 = 0 ;
break;
default:
F_9 ( V_11 L_15 , V_15 -> type ) ;
}
if ( V_15 -> type == V_137 || V_15 -> type == V_135 ) {
if ( ( * V_107 & V_151 ) == 0 )
* V_107 |= V_152 ;
}
V_15 -> V_153 = ( V_105 [ 0 ] >> 5 ) & 7 ;
V_15 -> V_154 = V_15 -> V_136 ;
V_15 -> V_155 = ( V_105 [ 7 ] & 1 ) && ( ( V_105 [ 3 ] & 7 ) == 2 ) ;
if ( V_15 -> V_90 >= V_156 ||
( V_15 -> V_116 > 56 && V_105 [ 56 ] & 0x04 ) )
V_15 -> V_157 = 1 ;
if ( V_105 [ 7 ] & 0x60 )
V_15 -> V_158 = 1 ;
if ( V_105 [ 7 ] & 0x10 )
V_15 -> V_159 = 1 ;
F_58 ( V_19 , V_15 , L_16
L_17 , F_66 ( V_15 -> type ) ,
V_15 -> V_39 , V_15 -> V_41 , V_15 -> V_42 ,
V_15 -> V_153 , V_105 [ 2 ] & 0x07 ,
( V_105 [ 3 ] & 0x0f ) == 1 ? L_18 : L_19 ) ;
if ( ( V_15 -> V_90 >= V_91 ) && ( V_105 [ 7 ] & 2 ) &&
! ( * V_107 & V_160 ) )
V_15 -> V_161 = 1 ;
if ( ( * V_107 & V_162 ) == 0 )
V_15 -> V_62 = 0 ;
if ( * V_107 & V_163 )
V_15 -> V_164 = 1 ;
if ( * V_107 & V_165 )
V_15 -> V_166 = 1 ;
if ( * V_107 & V_167 )
F_67 ( V_15 -> V_63 , 512 ) ;
if ( * V_107 & V_168 )
V_15 -> V_169 = 1 ;
if ( * V_107 & V_170 )
V_23 ( V_15 ) -> V_171 = 1 ;
V_15 -> V_172 = 1 ;
if ( * V_107 & V_173 )
V_15 -> V_174 = 1 ;
if ( * V_107 & V_175 )
V_15 -> V_176 = 1 ;
if ( * V_107 & V_177 )
V_15 -> V_178 = 1 ;
V_28 = F_68 ( V_15 , V_179 ) ;
if ( V_28 ) {
V_28 = F_68 ( V_15 , V_180 ) ;
if ( V_28 ) {
F_58 ( V_81 , V_15 ,
L_20 ,
F_69 ( V_15 -> V_48 ) ) ;
return V_133 ;
}
}
if ( * V_107 & V_181 )
V_15 -> V_182 = 1 ;
if ( * V_107 & V_183 )
V_15 -> V_154 = 0 ;
if ( * V_107 & V_184 )
V_15 -> V_185 = 1 ;
F_70 ( & V_15 -> V_58 ) ;
if ( V_15 -> V_43 -> V_66 -> V_186 ) {
V_28 = V_15 -> V_43 -> V_66 -> V_186 ( V_15 ) ;
if ( V_28 ) {
if ( V_28 != - V_68 ) {
F_58 ( V_81 , V_15 ,
L_21 ) ;
}
return V_133 ;
}
}
V_15 -> V_187 = V_15 -> V_188 ;
if ( ! V_130 && F_71 ( V_15 ) != 0 )
return V_133 ;
return V_189 ;
}
static unsigned char * F_72 ( unsigned char * V_190 , unsigned char * V_191 ,
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
static int F_73 ( struct V_23 * V_24 ,
T_1 V_25 , int * V_196 ,
struct V_14 * * V_197 , int V_198 ,
void * V_26 )
{
struct V_14 * V_15 ;
unsigned char * V_16 ;
int V_107 , V_199 = V_133 , V_106 = 256 ;
struct V_29 * V_6 = F_19 ( V_24 -> V_30 . V_31 ) ;
V_15 = F_74 ( V_24 , V_25 ) ;
if ( V_15 ) {
if ( V_198 || ! F_75 ( V_15 ) ) {
F_57 ( 3 , F_9 ( V_11
L_22 ,
F_76 ( & V_15 -> V_58 ) ) ) ;
if ( V_197 )
* V_197 = V_15 ;
else
F_77 ( V_15 ) ;
if ( V_196 )
* V_196 = F_61 ( V_15 ,
V_15 -> V_39 ,
V_15 -> V_41 ) ;
return V_189 ;
}
F_77 ( V_15 ) ;
} else
V_15 = F_18 ( V_24 , V_25 , V_26 ) ;
if ( ! V_15 )
goto V_4;
V_16 = F_3 ( V_106 , V_38 |
( ( V_6 -> V_200 ) ? V_201 : 0 ) ) ;
if ( ! V_16 )
goto V_202;
if ( F_56 ( V_15 , V_16 , V_106 , & V_107 ) )
goto V_203;
if ( V_196 )
* V_196 = V_107 ;
if ( ( ( V_16 [ 0 ] >> 5 ) == 3 ) && ! ( V_107 & V_204 ) ) {
F_57 ( 2 , sdev_printk(KERN_INFO, sdev, L_23
L_24
L_25))
if ( V_25 == 0 ) {
F_57 ( 1 , {
unsigned char vend[9];
unsigned char mod[17];
sdev_printk(KERN_INFO, sdev,
L_26
L_27,
scsi_inq_str(vend, result, 8, 16),
scsi_inq_str(mod, result, 16, 32));
}) ;
}
V_199 = V_205 ;
goto V_203;
}
if ( ( ( V_16 [ 0 ] >> 5 ) == 1 || V_24 -> V_206 ) &&
( V_16 [ 0 ] & 0x1f ) == 0x1f &&
! F_78 ( V_25 ) ) {
F_57 ( 3 , F_9 ( V_11
L_28
L_29 ) ) ;
V_199 = V_205 ;
goto V_203;
}
V_199 = F_63 ( V_15 , V_16 , & V_107 , V_6 -> V_207 ) ;
if ( V_199 == V_189 ) {
if ( V_107 & V_208 ) {
V_15 -> V_154 = 0 ;
F_16 ( V_15 , V_16 ) ;
}
}
V_203:
F_14 ( V_16 ) ;
V_202:
if ( V_199 == V_189 ) {
if ( V_197 ) {
if ( F_79 ( V_15 ) == 0 ) {
* V_197 = V_15 ;
} else {
F_31 ( V_15 ) ;
V_199 = V_133 ;
}
}
} else
F_31 ( V_15 ) ;
V_4:
return V_199 ;
}
static void F_80 ( struct V_23 * V_24 ,
int V_107 , int V_90 , int V_198 )
{
unsigned int V_209 , V_25 , V_210 ;
struct V_29 * V_6 = F_19 ( V_24 -> V_30 . V_31 ) ;
F_57 ( 3 , F_9 ( V_11 L_30
L_31 , F_76 ( & V_24 -> V_30 ) ) ) ;
V_210 = F_62 ( V_211 , V_6 -> V_212 ) ;
if ( V_107 & V_213 ) {
V_210 = V_6 -> V_212 ;
V_209 = 1 ;
} else
V_209 = 0 ;
if ( V_107 & V_214 )
V_210 = V_6 -> V_212 ;
if ( V_107 & V_215 )
V_210 = F_62 ( 5U , V_210 ) ;
if ( V_90 < V_156 && ! ( V_107 & V_216 ) )
V_210 = F_62 ( 8U , V_210 ) ;
for ( V_25 = 1 ; V_25 < V_210 ; ++ V_25 )
if ( ( F_73 ( V_24 , V_25 , NULL , NULL , V_198 ,
NULL ) != V_189 ) &&
! V_209 )
return;
}
int F_81 ( struct V_217 * V_218 )
{
int V_219 ;
unsigned int V_25 ;
V_25 = 0 ;
for ( V_219 = 0 ; V_219 < sizeof( V_25 ) ; V_219 += 2 )
V_25 = V_25 | ( ( ( V_218 -> V_217 [ V_219 ] << 8 ) |
V_218 -> V_217 [ V_219 + 1 ] ) << ( V_219 * 8 ) ) ;
return V_25 ;
}
void F_82 ( unsigned int V_25 , struct V_217 * V_218 )
{
int V_219 ;
memset ( V_218 -> V_217 , 0 , sizeof( V_218 -> V_217 ) ) ;
for ( V_219 = 0 ; V_219 < sizeof( V_25 ) ; V_219 += 2 ) {
V_218 -> V_217 [ V_219 ] = ( V_25 >> 8 ) & 0xFF ;
V_218 -> V_217 [ V_219 + 1 ] = V_25 & 0xFF ;
V_25 = V_25 >> 16 ;
}
}
static int F_83 ( struct V_23 * V_24 , int V_107 ,
int V_198 )
{
char V_220 [ 64 ] ;
unsigned char V_17 [ V_18 ] ;
unsigned int V_221 ;
unsigned int V_25 ;
unsigned int V_222 ;
unsigned int V_223 ;
int V_16 ;
struct V_217 * V_224 , * V_225 ;
T_2 * V_2 ;
struct V_114 V_115 ;
struct V_14 * V_15 ;
struct V_29 * V_6 = F_19 ( & V_24 -> V_30 ) ;
int V_28 = 0 ;
if ( V_107 & V_152 )
return 1 ;
if ( V_24 -> V_90 < V_91 &&
V_24 -> V_90 != V_226 )
return 1 ;
if ( V_24 -> V_90 < V_156 &&
( ! ( V_107 & V_151 ) || V_6 -> V_212 <= 8 ) )
return 1 ;
if ( V_107 & V_227 )
return 0 ;
if ( V_24 -> V_228 )
return 1 ;
if ( ! ( V_15 = F_74 ( V_24 , 0 ) ) ) {
V_15 = F_18 ( V_24 , 0 , NULL ) ;
if ( ! V_15 )
return 0 ;
if ( F_79 ( V_15 ) ) {
F_31 ( V_15 ) ;
return 0 ;
}
}
sprintf ( V_220 , L_32 ,
V_6 -> V_83 , V_15 -> V_47 , V_15 -> V_46 ) ;
V_221 = ( V_229 + 1 ) * sizeof( struct V_217 ) ;
V_225 = F_3 ( V_221 , V_38 |
( V_15 -> V_43 -> V_200 ? V_201 : 0 ) ) ;
if ( ! V_225 ) {
F_9 ( V_70 , V_71 ) ;
goto V_4;
}
V_17 [ 0 ] = V_230 ;
memset ( & V_17 [ 1 ] , 0 , 5 ) ;
V_17 [ 6 ] = ( unsigned char ) ( V_221 >> 24 ) & 0xff ;
V_17 [ 7 ] = ( unsigned char ) ( V_221 >> 16 ) & 0xff ;
V_17 [ 8 ] = ( unsigned char ) ( V_221 >> 8 ) & 0xff ;
V_17 [ 9 ] = ( unsigned char ) V_221 & 0xff ;
V_17 [ 10 ] = 0 ;
V_17 [ 11 ] = 0 ;
for ( V_223 = 0 ; V_223 < 3 ; V_223 ++ ) {
F_57 ( 3 , F_9 ( V_11 L_33
L_34 , V_220 ,
V_223 ) ) ;
V_16 = F_17 ( V_15 , V_17 , V_21 ,
V_225 , V_221 , & V_115 ,
V_22 + 4 * V_120 , 3 , NULL ) ;
F_57 ( 3 , F_9 ( V_11 L_35
L_36 , V_16
? L_9 : L_10 , V_223 , V_16 ) ) ;
if ( V_16 == 0 )
break;
else if ( F_60 ( & V_115 ) ) {
if ( V_115 . V_123 != V_124 )
break;
}
}
if ( V_16 ) {
V_28 = 1 ;
goto V_231;
}
V_2 = ( T_2 * ) V_225 -> V_217 ;
V_221 = ( ( V_2 [ 0 ] << 24 ) | ( V_2 [ 1 ] << 16 ) |
( V_2 [ 2 ] << 8 ) | ( V_2 [ 3 ] << 0 ) ) ;
V_222 = ( V_221 / sizeof( struct V_217 ) ) ;
if ( V_222 > V_229 ) {
F_9 ( V_232 L_37
L_38
L_39 , V_220 ,
V_229 , V_222 ) ;
V_222 = V_229 ;
}
F_57 ( 3 , F_58 ( V_11 , V_15 ,
L_40 ) ) ;
for ( V_224 = & V_225 [ 1 ] ; V_224 <= & V_225 [ V_222 ] ; V_224 ++ ) {
V_25 = F_81 ( V_224 ) ;
if ( memcmp ( & V_224 -> V_217 [ sizeof( V_25 ) ] , L_41 , 4 ) ) {
int V_219 ;
F_9 ( V_232 L_42 , V_220 ) ;
V_2 = ( char * ) V_224 -> V_217 ;
for ( V_219 = 0 ; V_219 < sizeof( struct V_217 ) ; V_219 ++ )
F_9 ( L_43 , V_2 [ V_219 ] ) ;
F_9 ( L_44 ) ;
} else if ( V_25 > V_15 -> V_43 -> V_212 ) {
F_9 ( V_232 L_45
L_46 ,
V_220 , V_25 ) ;
} else {
int V_199 ;
V_199 = F_73 ( V_24 ,
V_25 , NULL , NULL , V_198 , NULL ) ;
if ( V_199 == V_133 ) {
F_58 ( V_81 , V_15 ,
L_47
L_48
L_49 , V_25 ) ;
break;
}
}
}
V_231:
F_14 ( V_225 ) ;
V_4:
F_77 ( V_15 ) ;
if ( F_75 ( V_15 ) )
F_31 ( V_15 ) ;
return V_28 ;
}
struct V_14 * F_84 ( struct V_29 * V_6 , T_1 V_47 ,
T_1 V_46 , T_1 V_25 , void * V_26 )
{
struct V_14 * V_15 = F_85 ( - V_233 ) ;
struct V_72 * V_31 = & V_6 -> V_234 ;
struct V_23 * V_24 ;
if ( strncmp ( V_235 , L_50 , 4 ) == 0 )
return F_85 ( - V_233 ) ;
V_24 = F_42 ( V_31 , V_47 , V_46 ) ;
if ( ! V_24 )
return F_85 ( - V_236 ) ;
F_86 ( V_24 ) ;
F_87 ( & V_6 -> V_237 ) ;
if ( ! V_6 -> V_207 )
F_1 () ;
if ( F_88 ( V_6 ) && F_89 ( V_6 ) == 0 ) {
F_73 ( V_24 , V_25 , NULL , & V_15 , 1 , V_26 ) ;
F_90 ( V_6 ) ;
}
F_91 ( & V_6 -> V_237 ) ;
F_92 ( V_24 ) ;
F_52 ( V_24 ) ;
F_26 ( & V_24 -> V_30 ) ;
return V_15 ;
}
int F_93 ( struct V_29 * V_43 , T_1 V_47 ,
T_1 V_238 , T_1 V_25 )
{
struct V_14 * V_15 =
F_84 ( V_43 , V_47 , V_238 , V_25 , NULL ) ;
if ( F_94 ( V_15 ) )
return F_95 ( V_15 ) ;
F_77 ( V_15 ) ;
return 0 ;
}
void F_96 ( struct V_72 * V_30 )
{
struct V_239 * V_240 ;
if ( ! V_30 -> V_241 )
return;
V_240 = F_97 ( V_30 -> V_241 ) ;
if ( F_98 ( V_240 -> V_242 ) ) {
if ( V_240 -> V_198 )
V_240 -> V_198 ( V_30 ) ;
F_99 ( V_240 -> V_242 ) ;
}
}
static void F_100 ( struct V_72 * V_31 , unsigned int V_47 ,
unsigned int V_46 , unsigned int V_25 , int V_198 )
{
struct V_29 * V_6 = F_19 ( V_31 ) ;
int V_107 = 0 ;
int V_199 ;
struct V_23 * V_24 ;
if ( V_6 -> V_243 == V_46 )
return;
V_24 = F_42 ( V_31 , V_47 , V_46 ) ;
if ( ! V_24 )
return;
F_86 ( V_24 ) ;
if ( V_25 != V_244 ) {
F_73 ( V_24 , V_25 , NULL , NULL , V_198 , NULL ) ;
goto V_245;
}
V_199 = F_73 ( V_24 , 0 , & V_107 , NULL , V_198 , NULL ) ;
if ( V_199 == V_189 || V_199 == V_205 ) {
if ( F_83 ( V_24 , V_107 , V_198 ) != 0 )
F_80 ( V_24 , V_107 ,
V_24 -> V_90 , V_198 ) ;
}
V_245:
F_92 ( V_24 ) ;
F_52 ( V_24 ) ;
F_26 ( & V_24 -> V_30 ) ;
}
void F_101 ( struct V_72 * V_31 , unsigned int V_47 ,
unsigned int V_46 , unsigned int V_25 , int V_198 )
{
struct V_29 * V_6 = F_19 ( V_31 ) ;
if ( strncmp ( V_235 , L_50 , 4 ) == 0 )
return;
F_87 ( & V_6 -> V_237 ) ;
if ( ! V_6 -> V_207 )
F_1 () ;
if ( F_88 ( V_6 ) && F_89 ( V_6 ) == 0 ) {
F_100 ( V_31 , V_47 , V_46 , V_25 , V_198 ) ;
F_90 ( V_6 ) ;
}
F_91 ( & V_6 -> V_237 ) ;
}
static void F_102 ( struct V_29 * V_6 , unsigned int V_47 ,
unsigned int V_46 , unsigned int V_25 , int V_198 )
{
T_1 V_246 ;
if ( V_46 == V_244 )
for ( V_46 = 0 ; V_46 < V_6 -> V_247 ; ++ V_46 ) {
if ( V_6 -> V_248 )
V_246 = V_6 -> V_247 - V_46 - 1 ;
else
V_246 = V_46 ;
F_100 ( & V_6 -> V_234 , V_47 ,
V_246 , V_25 , V_198 ) ;
}
else
F_100 ( & V_6 -> V_234 , V_47 ,
V_46 , V_25 , V_198 ) ;
}
int F_103 ( struct V_29 * V_6 , unsigned int V_47 ,
unsigned int V_46 , unsigned int V_25 , int V_198 )
{
F_57 ( 3 , F_104 ( V_11 , V_6 ,
L_51 ,
V_71 , V_47 , V_46 , V_25 ) ) ;
if ( ( ( V_47 != V_244 ) && ( V_47 > V_6 -> V_249 ) ) ||
( ( V_46 != V_244 ) && ( V_46 >= V_6 -> V_247 ) ) ||
( ( V_25 != V_244 ) && ( V_25 > V_6 -> V_212 ) ) )
return - V_250 ;
F_87 ( & V_6 -> V_237 ) ;
if ( ! V_6 -> V_207 )
F_1 () ;
if ( F_88 ( V_6 ) && F_89 ( V_6 ) == 0 ) {
if ( V_47 == V_244 )
for ( V_47 = 0 ; V_47 <= V_6 -> V_249 ;
V_47 ++ )
F_102 ( V_6 , V_47 , V_46 , V_25 ,
V_198 ) ;
else
F_102 ( V_6 , V_47 , V_46 , V_25 , V_198 ) ;
F_90 ( V_6 ) ;
}
F_91 ( & V_6 -> V_237 ) ;
return 0 ;
}
static void F_105 ( struct V_29 * V_6 )
{
struct V_14 * V_15 ;
F_106 (sdev, shost) {
if ( ! F_88 ( V_6 ) ||
F_71 ( V_15 ) != 0 )
F_31 ( V_15 ) ;
}
}
static struct V_1 * F_107 ( struct V_29 * V_6 )
{
struct V_1 * V_2 ;
unsigned long V_73 ;
if ( strncmp ( V_235 , L_52 , 4 ) == 0 )
return NULL ;
if ( V_6 -> V_207 ) {
F_9 ( L_53 , V_71 ,
V_6 -> V_83 ) ;
F_108 () ;
return NULL ;
}
V_2 = F_3 ( sizeof( * V_2 ) , V_5 ) ;
if ( ! V_2 )
goto V_251;
V_2 -> V_6 = F_109 ( V_6 ) ;
if ( ! V_2 -> V_6 )
goto V_251;
F_5 ( & V_2 -> V_7 ) ;
F_87 ( & V_6 -> V_237 ) ;
F_34 ( V_6 -> V_74 , V_73 ) ;
V_6 -> V_207 = 1 ;
F_36 ( V_6 -> V_74 , V_73 ) ;
F_91 ( & V_6 -> V_237 ) ;
F_6 ( & V_8 ) ;
if ( F_2 ( & V_3 ) )
F_13 ( & V_2 -> V_7 ) ;
F_7 ( & V_2 -> V_10 , & V_3 ) ;
F_8 ( & V_8 ) ;
return V_2 ;
V_251:
F_14 ( V_2 ) ;
return NULL ;
}
static void F_110 ( struct V_1 * V_2 )
{
struct V_29 * V_6 ;
unsigned long V_73 ;
if ( ! V_2 )
return;
V_6 = V_2 -> V_6 ;
F_87 ( & V_6 -> V_237 ) ;
if ( ! V_6 -> V_207 ) {
F_9 ( L_53 , V_71 ,
V_6 -> V_83 ) ;
F_108 () ;
F_91 ( & V_6 -> V_237 ) ;
return;
}
F_10 ( & V_2 -> V_7 ) ;
F_105 ( V_6 ) ;
F_34 ( V_6 -> V_74 , V_73 ) ;
V_6 -> V_207 = 0 ;
F_36 ( V_6 -> V_74 , V_73 ) ;
F_91 ( & V_6 -> V_237 ) ;
F_6 ( & V_8 ) ;
F_11 ( & V_2 -> V_10 ) ;
if ( ! F_2 ( & V_3 ) ) {
struct V_1 * V_12 = F_12 ( V_3 . V_12 ,
struct V_1 , V_10 ) ;
F_13 ( & V_12 -> V_7 ) ;
}
F_8 ( & V_8 ) ;
F_90 ( V_6 ) ;
F_111 ( V_6 ) ;
F_14 ( V_2 ) ;
}
static void F_112 ( struct V_29 * V_6 )
{
if ( V_6 -> V_66 -> V_252 ) {
unsigned long V_253 = V_254 ;
if ( V_6 -> V_66 -> V_255 )
V_6 -> V_66 -> V_255 ( V_6 ) ;
while ( ! V_6 -> V_66 -> V_252 ( V_6 , V_254 - V_253 ) )
F_4 ( 10 ) ;
} else {
F_103 ( V_6 , V_244 , V_244 ,
V_244 , 0 ) ;
}
}
static int F_113 ( void * V_256 )
{
struct V_1 * V_2 = V_256 ;
struct V_29 * V_6 = V_2 -> V_6 ;
F_112 ( V_6 ) ;
F_110 ( V_2 ) ;
return 0 ;
}
void F_114 ( struct V_29 * V_6 )
{
struct V_257 * V_258 ;
struct V_1 * V_2 ;
if ( strncmp ( V_235 , L_50 , 4 ) == 0 )
return;
if ( F_89 ( V_6 ) < 0 )
return;
V_2 = F_107 ( V_6 ) ;
if ( ! V_2 ) {
F_112 ( V_6 ) ;
F_90 ( V_6 ) ;
return;
}
V_258 = F_115 ( F_113 , V_2 , L_54 , V_6 -> V_83 ) ;
if ( F_94 ( V_258 ) )
F_113 ( V_2 ) ;
}
void F_116 ( struct V_29 * V_6 )
{
struct V_14 * V_15 ;
unsigned long V_73 ;
V_259:
F_34 ( V_6 -> V_74 , V_73 ) ;
F_41 (sdev, &shost->__devices, siblings) {
if ( V_15 -> V_48 == V_260 )
continue;
F_36 ( V_6 -> V_74 , V_73 ) ;
F_31 ( V_15 ) ;
goto V_259;
}
F_36 ( V_6 -> V_74 , V_73 ) ;
}
struct V_14 * F_117 ( struct V_29 * V_6 )
{
struct V_14 * V_15 = NULL ;
struct V_23 * V_24 ;
F_87 ( & V_6 -> V_237 ) ;
if ( ! F_88 ( V_6 ) )
goto V_4;
V_24 = F_42 ( & V_6 -> V_234 , 0 , V_6 -> V_243 ) ;
if ( ! V_24 )
goto V_4;
V_15 = F_18 ( V_24 , 0 , NULL ) ;
if ( V_15 )
V_15 -> V_62 = 0 ;
else
F_52 ( V_24 ) ;
F_26 ( & V_24 -> V_30 ) ;
V_4:
F_91 ( & V_6 -> V_237 ) ;
return V_15 ;
}
void F_118 ( struct V_14 * V_15 )
{
F_53 ( V_15 -> V_46 != V_15 -> V_43 -> V_243 ) ;
F_31 ( V_15 ) ;
}
