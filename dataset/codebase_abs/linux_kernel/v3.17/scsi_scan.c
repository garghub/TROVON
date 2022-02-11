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
F_31 ( V_13 , 0 , V_13 -> V_42 -> V_64 ) ;
F_32 ( V_13 ) ;
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
F_33 ( V_13 ) ;
V_37:
if ( V_25 )
F_9 ( V_69 , V_70 ) ;
return NULL ;
}
static void F_34 ( struct V_21 * V_22 )
{
struct V_71 * V_28 = & V_22 -> V_28 ;
struct V_27 * V_5 = F_19 ( V_28 -> V_29 ) ;
unsigned long V_72 ;
V_22 -> V_73 = V_74 ;
F_35 ( V_28 ) ;
F_36 ( V_5 -> V_75 , V_72 ) ;
if ( V_5 -> V_65 -> V_76 )
V_5 -> V_65 -> V_76 ( V_22 ) ;
F_37 ( & V_22 -> V_49 ) ;
F_38 ( V_5 -> V_75 , V_72 ) ;
F_28 ( V_28 ) ;
}
static void F_39 ( struct V_71 * V_28 )
{
struct V_71 * V_29 = V_28 -> V_29 ;
struct V_21 * V_22 = F_40 ( V_28 ) ;
F_14 ( V_22 ) ;
F_28 ( V_29 ) ;
}
int F_41 ( const struct V_71 * V_28 )
{
return V_28 -> type == & V_77 ;
}
static struct V_21 * F_42 ( struct V_71 * V_29 ,
int V_46 , T_2 V_45 )
{
struct V_21 * V_22 , * V_78 = NULL ;
struct V_27 * V_5 = F_19 ( V_29 ) ;
F_43 (starget, &shost->__targets, siblings) {
if ( V_22 -> V_45 == V_45 &&
V_22 -> V_46 == V_46 ) {
V_78 = V_22 ;
break;
}
}
if ( V_78 )
F_24 ( & V_78 -> V_28 ) ;
return V_78 ;
}
static void F_44 ( struct V_79 * V_79 )
{
struct V_21 * V_22
= F_45 ( V_79 , struct V_21 , V_80 ) ;
if ( V_22 -> V_73 != V_81 ) {
F_46 ( & V_22 -> V_28 ) ;
F_47 ( & V_22 -> V_28 ) ;
}
F_34 ( V_22 ) ;
}
static void F_48 ( struct V_21 * V_22 )
{
F_49 ( & V_22 -> V_80 , F_44 ) ;
}
static struct V_21 * F_50 ( struct V_71 * V_29 ,
int V_46 , T_2 V_45 )
{
struct V_27 * V_5 = F_19 ( V_29 ) ;
struct V_71 * V_28 = NULL ;
unsigned long V_72 ;
const int V_82 = sizeof( struct V_21 )
+ V_5 -> V_34 -> V_83 ;
struct V_21 * V_22 ;
struct V_21 * V_84 ;
int error , V_85 ;
V_22 = F_20 ( V_82 , V_4 ) ;
if ( ! V_22 ) {
F_9 ( V_86 L_3 , V_70 ) ;
return NULL ;
}
V_28 = & V_22 -> V_28 ;
F_51 ( V_28 ) ;
F_52 ( & V_22 -> V_80 ) ;
V_28 -> V_29 = F_24 ( V_29 ) ;
F_53 ( V_28 , L_4 , V_5 -> V_87 , V_46 , V_45 ) ;
V_28 -> V_88 = & V_89 ;
V_28 -> type = & V_77 ;
V_22 -> V_45 = V_45 ;
V_22 -> V_46 = V_46 ;
V_22 -> V_90 = 0 ;
F_21 ( & V_22 -> V_49 ) ;
F_21 ( & V_22 -> V_91 ) ;
V_22 -> V_73 = V_81 ;
V_22 -> V_92 = V_93 ;
V_22 -> V_94 = V_95 ;
V_96:
F_36 ( V_5 -> V_75 , V_72 ) ;
V_84 = F_42 ( V_29 , V_46 , V_45 ) ;
if ( V_84 )
goto V_97;
F_7 ( & V_22 -> V_49 , & V_5 -> V_98 ) ;
F_38 ( V_5 -> V_75 , V_72 ) ;
F_54 ( V_28 ) ;
if ( V_5 -> V_65 -> V_99 ) {
error = V_5 -> V_65 -> V_99 ( V_22 ) ;
if( error ) {
F_55 ( V_86 , V_28 , L_5 , error ) ;
F_34 ( V_22 ) ;
return NULL ;
}
}
F_24 ( V_28 ) ;
return V_22 ;
V_97:
V_85 = F_56 ( & V_84 -> V_80 ) ;
F_38 ( V_5 -> V_75 , V_72 ) ;
if ( V_85 ) {
F_28 ( V_28 ) ;
return V_84 ;
}
F_28 ( & V_84 -> V_28 ) ;
F_4 ( 1 ) ;
goto V_96;
}
void F_57 ( struct V_21 * V_22 )
{
F_58 ( V_22 -> V_73 == V_74 ) ;
F_48 ( V_22 ) ;
}
static void F_59 ( unsigned char * V_100 , int V_101 )
{
int V_102 = 0 ;
for (; V_101 > 0 ; ( -- V_101 , ++ V_100 ) ) {
if ( * V_100 == 0 )
V_102 = 1 ;
if ( V_102 || * V_100 < 0x20 || * V_100 > 0x7e )
* V_100 = ' ' ;
}
}
static int F_60 ( struct V_12 * V_13 , unsigned char * V_103 ,
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
F_61 ( 3 , F_16 ( V_10 , V_13 ,
L_6 ,
V_110 , V_107 ) ) ;
for ( V_111 = 0 ; V_111 < 3 ; ++ V_111 ) {
int V_116 ;
memset ( V_15 , 0 , 6 ) ;
V_15 [ 0 ] = V_117 ;
V_15 [ 4 ] = ( unsigned char ) V_107 ;
memset ( V_103 , 0 , V_107 ) ;
V_14 = F_17 ( V_13 , V_15 , V_19 ,
V_103 , V_107 , & V_113 ,
V_118 / 2 + V_118 * V_119 , 3 ,
& V_116 ) ;
F_61 ( 3 , F_16 ( V_10 , V_13 ,
L_7 ,
V_14 ? L_8 : L_9 , V_14 ) ) ;
if ( V_14 ) {
if ( ( F_62 ( V_14 ) & V_120 ) &&
F_63 ( & V_113 ) ) {
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
F_59 ( & V_103 [ 8 ] , 8 ) ;
F_59 ( & V_103 [ 16 ] , 16 ) ;
F_59 ( & V_103 [ 32 ] , 4 ) ;
V_109 = V_103 [ 4 ] + 5 ;
if ( V_109 > 255 )
V_109 = V_106 ;
* V_105 = F_64 ( V_13 , & V_103 [ 8 ] ,
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
F_16 ( V_10 , V_13 ,
L_10
L_11 ,
V_107 ) ;
V_107 = V_106 ;
V_110 = 3 ;
goto V_115;
}
if ( V_14 )
return - V_127 ;
V_13 -> V_114 = F_65 ( V_107 , V_109 ) ;
if ( V_13 -> V_114 < 36 ) {
F_16 ( V_10 , V_13 ,
L_12
L_13 , V_13 -> V_114 ) ;
V_13 -> V_114 = 36 ;
}
V_13 -> V_92 = V_103 [ 2 ] & 0x07 ;
if ( V_13 -> V_92 >= 2 ||
( V_13 -> V_92 == 1 && ( V_103 [ 3 ] & 0x0f ) == 1 ) )
V_13 -> V_92 ++ ;
V_13 -> V_58 -> V_92 = V_13 -> V_92 ;
return 0 ;
}
static int F_66 ( struct V_12 * V_13 , unsigned char * V_103 ,
int * V_105 , int V_128 )
{
int V_26 ;
V_13 -> V_129 = F_67 ( V_103 ,
F_68 ( V_130 , V_13 -> V_114 , 36 ) ,
V_36 ) ;
if ( V_13 -> V_129 == NULL )
return V_131 ;
V_13 -> V_38 = ( char * ) ( V_13 -> V_129 + 8 ) ;
V_13 -> V_40 = ( char * ) ( V_13 -> V_129 + 16 ) ;
V_13 -> V_41 = ( char * ) ( V_13 -> V_129 + 32 ) ;
if ( strncmp ( V_13 -> V_38 , L_14 , 8 ) == 0 ) {
V_13 -> V_132 = 1 ;
}
if ( * V_105 & V_133 ) {
V_13 -> type = V_134 ;
V_13 -> V_135 = 1 ;
} else {
V_13 -> type = ( V_103 [ 0 ] & 0x1f ) ;
V_13 -> V_135 = ( V_103 [ 1 ] & 0x80 ) >> 7 ;
}
if ( V_13 -> type == V_136 || V_13 -> type == V_134 ) {
if ( ( * V_105 & V_137 ) == 0 )
* V_105 |= V_138 ;
}
V_13 -> V_139 = ( V_103 [ 0 ] >> 5 ) & 7 ;
V_13 -> V_140 = V_13 -> V_135 ;
V_13 -> V_141 = ( V_103 [ 7 ] & 1 ) && ( ( V_103 [ 3 ] & 7 ) == 2 ) ;
if ( V_13 -> V_92 >= V_142 ||
( V_13 -> V_114 > 56 && V_103 [ 56 ] & 0x04 ) )
V_13 -> V_143 = 1 ;
if ( V_103 [ 7 ] & 0x60 )
V_13 -> V_144 = 1 ;
if ( V_103 [ 7 ] & 0x10 )
V_13 -> V_145 = 1 ;
F_16 ( V_17 , V_13 , L_15
L_16 , F_69 ( V_13 -> type ) ,
V_13 -> V_38 , V_13 -> V_40 , V_13 -> V_41 ,
V_13 -> V_139 , V_103 [ 2 ] & 0x07 ,
( V_103 [ 3 ] & 0x0f ) == 1 ? L_17 : L_18 ) ;
if ( ( V_13 -> V_92 >= V_93 ) && ( V_103 [ 7 ] & 2 ) &&
! ( * V_105 & V_146 ) )
V_13 -> V_147 = 1 ;
if ( ( * V_105 & V_148 ) == 0 )
V_13 -> V_61 = 0 ;
if ( * V_105 & V_149 )
V_13 -> V_150 = 1 ;
if ( * V_105 & V_151 )
V_13 -> V_152 = 1 ;
if ( * V_105 & V_153 )
F_70 ( V_13 -> V_62 , 512 ) ;
if ( * V_105 & V_154 )
V_13 -> V_155 = 1 ;
if ( * V_105 & V_156 )
V_21 ( V_13 ) -> V_157 = 1 ;
V_13 -> V_158 = 1 ;
if ( * V_105 & V_159 )
V_13 -> V_160 = 1 ;
if ( * V_105 & V_161 )
V_13 -> V_162 = 1 ;
if ( * V_105 & V_163 )
V_13 -> V_164 = 1 ;
if ( * V_105 & V_165 )
V_13 -> V_166 = 1 ;
V_26 = F_71 ( V_13 , V_167 ) ;
if ( V_26 ) {
V_26 = F_71 ( V_13 , V_168 ) ;
if ( V_26 ) {
F_16 ( V_86 , V_13 ,
L_19 ,
F_72 ( V_13 -> V_47 ) ) ;
return V_131 ;
}
}
if ( * V_105 & V_169 )
V_13 -> V_170 = 1 ;
if ( * V_105 & V_171 )
V_13 -> V_140 = 0 ;
if ( * V_105 & V_172 )
V_13 -> V_173 = 1 ;
if ( * V_105 & V_174 )
V_13 -> V_175 = 1 ;
V_13 -> V_176 = V_177 ;
if ( * V_105 & V_178 )
V_13 -> V_179 = 1 ;
else if ( * V_105 & V_180 )
V_13 -> V_181 = 1 ;
F_73 ( & V_13 -> V_57 ) ;
if ( V_13 -> V_42 -> V_65 -> V_182 ) {
V_26 = V_13 -> V_42 -> V_65 -> V_182 ( V_13 ) ;
if ( V_26 ) {
if ( V_26 != - V_67 ) {
F_16 ( V_86 , V_13 ,
L_20 ) ;
}
return V_131 ;
}
}
if ( V_13 -> V_92 >= V_142 )
F_74 ( V_13 ) ;
V_13 -> V_183 = V_13 -> V_184 ;
if ( ! V_128 && F_75 ( V_13 ) != 0 )
return V_131 ;
return V_185 ;
}
static unsigned char * F_76 ( unsigned char * V_186 , unsigned char * V_187 ,
unsigned V_188 , unsigned V_189 )
{
unsigned V_190 = 0 , V_191 ;
for ( V_191 = 0 ; V_191 + V_188 < V_189 && V_191 + V_188 < V_187 [ 4 ] + 5 ; V_191 ++ ) {
if ( V_187 [ V_191 + V_188 ] > ' ' ) {
V_186 [ V_191 ] = V_187 [ V_191 + V_188 ] ;
V_190 = V_191 + 1 ;
} else {
V_186 [ V_191 ] = ' ' ;
}
}
V_186 [ V_190 ] = 0 ;
return V_186 ;
}
static int F_77 ( struct V_21 * V_22 ,
T_1 V_23 , int * V_192 ,
struct V_12 * * V_193 , int V_194 ,
void * V_24 )
{
struct V_12 * V_13 ;
unsigned char * V_14 ;
int V_105 , V_195 = V_131 , V_104 = 256 ;
struct V_27 * V_5 = F_19 ( V_22 -> V_28 . V_29 ) ;
V_13 = F_78 ( V_22 , V_23 ) ;
if ( V_13 ) {
if ( V_194 || ! F_79 ( V_13 ) ) {
F_61 ( 3 , F_16 ( V_10 , V_13 ,
L_21 ,
F_80 ( & V_13 -> V_57 ) ) ) ;
if ( V_193 )
* V_193 = V_13 ;
else
F_81 ( V_13 ) ;
if ( V_192 )
* V_192 = F_64 ( V_13 ,
V_13 -> V_38 ,
V_13 -> V_40 ) ;
return V_185 ;
}
F_81 ( V_13 ) ;
} else
V_13 = F_18 ( V_22 , V_23 , V_24 ) ;
if ( ! V_13 )
goto V_37;
V_14 = F_3 ( V_104 , V_36 |
( ( V_5 -> V_196 ) ? V_197 : 0 ) ) ;
if ( ! V_14 )
goto V_198;
if ( F_60 ( V_13 , V_14 , V_104 , & V_105 ) )
goto V_199;
if ( V_192 )
* V_192 = V_105 ;
if ( ( ( V_14 [ 0 ] >> 5 ) == 3 ) && ! ( V_105 & V_200 ) ) {
F_61 ( 2 , sdev_printk(KERN_INFO, sdev, L_22
L_23
L_24))
if ( V_23 == 0 ) {
F_61 ( 1 , {
unsigned char vend[9];
unsigned char mod[17];
sdev_printk(KERN_INFO, sdev,
L_25
L_26,
scsi_inq_str(vend, result, 8, 16),
scsi_inq_str(mod, result, 16, 32));
}) ;
}
V_195 = V_201 ;
goto V_199;
}
if ( ( ( V_14 [ 0 ] >> 5 ) == 1 || V_22 -> V_202 ) &&
( V_14 [ 0 ] & 0x1f ) == 0x1f &&
! F_82 ( V_23 ) ) {
F_61 ( 3 , F_16 ( V_10 , V_13 ,
L_27
L_28 ) ) ;
V_195 = V_201 ;
goto V_199;
}
V_195 = F_66 ( V_13 , V_14 , & V_105 , V_5 -> V_203 ) ;
if ( V_195 == V_185 ) {
if ( V_105 & V_204 ) {
V_13 -> V_140 = 0 ;
F_15 ( V_13 , V_14 ) ;
}
}
V_199:
F_14 ( V_14 ) ;
V_198:
if ( V_195 == V_185 ) {
if ( V_193 ) {
if ( F_83 ( V_13 ) == 0 ) {
* V_193 = V_13 ;
} else {
F_33 ( V_13 ) ;
V_195 = V_131 ;
}
}
} else
F_33 ( V_13 ) ;
V_37:
return V_195 ;
}
static void F_84 ( struct V_21 * V_22 ,
int V_105 , int V_92 , int V_194 )
{
T_2 V_205 ;
T_1 V_206 , V_23 ;
struct V_27 * V_5 = F_19 ( V_22 -> V_28 . V_29 ) ;
F_61 ( 3 , F_85 ( V_10 , V_22 ,
L_29 ) ) ;
V_205 = F_65 ( V_207 , V_5 -> V_208 ) ;
if ( V_105 & V_209 ) {
V_205 = V_5 -> V_208 ;
V_206 = 1 ;
} else
V_206 = 0 ;
if ( V_105 & V_210 )
V_205 = V_5 -> V_208 ;
if ( V_105 & V_211 )
V_205 = F_65 ( 5U , V_205 ) ;
if ( V_92 < V_142 && ! ( V_105 & V_212 ) )
V_205 = F_65 ( 8U , V_205 ) ;
if ( ! ( V_105 & V_213 ) )
V_205 = F_65 ( 256U , V_205 ) ;
for ( V_23 = 1 ; V_23 < V_205 ; ++ V_23 )
if ( ( F_77 ( V_22 , V_23 , NULL , NULL , V_194 ,
NULL ) != V_185 ) &&
! V_206 )
return;
}
T_1 F_86 ( struct V_214 * V_215 )
{
int V_216 ;
T_1 V_23 ;
V_23 = 0 ;
for ( V_216 = 0 ; V_216 < sizeof( V_23 ) ; V_216 += 2 )
V_23 = V_23 | ( ( ( T_1 ) V_215 -> V_214 [ V_216 ] << ( ( V_216 + 1 ) * 8 ) ) |
( ( T_1 ) V_215 -> V_214 [ V_216 + 1 ] << ( V_216 * 8 ) ) ) ;
return V_23 ;
}
void F_87 ( T_1 V_23 , struct V_214 * V_215 )
{
int V_216 ;
memset ( V_215 -> V_214 , 0 , sizeof( V_215 -> V_214 ) ) ;
for ( V_216 = 0 ; V_216 < sizeof( V_23 ) ; V_216 += 2 ) {
V_215 -> V_214 [ V_216 ] = ( V_23 >> 8 ) & 0xFF ;
V_215 -> V_214 [ V_216 + 1 ] = V_23 & 0xFF ;
V_23 = V_23 >> 16 ;
}
}
static int F_88 ( struct V_21 * V_22 , int V_105 ,
int V_194 )
{
char V_217 [ 64 ] ;
unsigned char V_15 [ V_16 ] ;
unsigned int V_218 ;
T_1 V_23 ;
unsigned int V_219 ;
unsigned int V_220 ;
int V_14 ;
struct V_214 * V_221 , * V_222 ;
T_3 * V_2 ;
struct V_112 V_113 ;
struct V_12 * V_13 ;
struct V_27 * V_5 = F_19 ( & V_22 -> V_28 ) ;
int V_26 = 0 ;
if ( V_105 & V_138 )
return 1 ;
if ( V_22 -> V_92 < V_93 &&
V_22 -> V_92 != V_223 )
return 1 ;
if ( V_22 -> V_92 < V_142 &&
( ! ( V_105 & V_137 ) || V_5 -> V_208 <= 8 ) )
return 1 ;
if ( V_105 & V_224 )
return 0 ;
if ( V_22 -> V_225 )
return 1 ;
if ( ! ( V_13 = F_78 ( V_22 , 0 ) ) ) {
V_13 = F_18 ( V_22 , 0 , NULL ) ;
if ( ! V_13 )
return 0 ;
if ( F_83 ( V_13 ) ) {
F_33 ( V_13 ) ;
return 0 ;
}
}
sprintf ( V_217 , L_30 ,
V_5 -> V_87 , V_13 -> V_46 , V_13 -> V_45 ) ;
V_218 = ( V_226 + 1 ) * sizeof( struct V_214 ) ;
V_222 = F_3 ( V_218 , V_36 |
( V_13 -> V_42 -> V_196 ? V_197 : 0 ) ) ;
if ( ! V_222 ) {
F_9 ( V_69 , V_70 ) ;
goto V_37;
}
V_15 [ 0 ] = V_227 ;
memset ( & V_15 [ 1 ] , 0 , 5 ) ;
V_15 [ 6 ] = ( unsigned char ) ( V_218 >> 24 ) & 0xff ;
V_15 [ 7 ] = ( unsigned char ) ( V_218 >> 16 ) & 0xff ;
V_15 [ 8 ] = ( unsigned char ) ( V_218 >> 8 ) & 0xff ;
V_15 [ 9 ] = ( unsigned char ) V_218 & 0xff ;
V_15 [ 10 ] = 0 ;
V_15 [ 11 ] = 0 ;
for ( V_220 = 0 ; V_220 < 3 ; V_220 ++ ) {
F_61 ( 3 , F_16 ( V_10 , V_13 ,
L_31 ,
V_220 ) ) ;
V_14 = F_17 ( V_13 , V_15 , V_19 ,
V_222 , V_218 , & V_113 ,
V_20 + 4 * V_118 , 3 , NULL ) ;
F_61 ( 3 , F_16 ( V_10 , V_13 ,
L_32
L_33 ,
V_14 ? L_8 : L_9 ,
V_220 , V_14 ) ) ;
if ( V_14 == 0 )
break;
else if ( F_63 ( & V_113 ) ) {
if ( V_113 . V_121 != V_122 )
break;
}
}
if ( V_14 ) {
V_26 = 1 ;
goto V_228;
}
V_2 = ( T_3 * ) V_222 -> V_214 ;
V_218 = ( ( V_2 [ 0 ] << 24 ) | ( V_2 [ 1 ] << 16 ) |
( V_2 [ 2 ] << 8 ) | ( V_2 [ 3 ] << 0 ) ) ;
V_219 = ( V_218 / sizeof( struct V_214 ) ) ;
if ( V_219 > V_226 ) {
F_16 ( V_229 , V_13 ,
L_34
L_35
L_36 ,
V_226 , V_219 ) ;
V_219 = V_226 ;
}
F_61 ( 3 , F_16 ( V_10 , V_13 ,
L_37 ) ) ;
for ( V_221 = & V_222 [ 1 ] ; V_221 <= & V_222 [ V_219 ] ; V_221 ++ ) {
V_23 = F_86 ( V_221 ) ;
if ( V_23 > V_13 -> V_42 -> V_208 ) {
F_16 ( V_229 , V_13 ,
L_38
L_39 , V_23 ) ;
} else {
int V_195 ;
V_195 = F_77 ( V_22 ,
V_23 , NULL , NULL , V_194 , NULL ) ;
if ( V_195 == V_131 ) {
F_16 ( V_86 , V_13 ,
L_40
L_41
L_42 , ( unsigned long long ) V_23 ) ;
break;
}
}
}
V_228:
F_14 ( V_222 ) ;
V_37:
F_81 ( V_13 ) ;
if ( F_79 ( V_13 ) )
F_33 ( V_13 ) ;
return V_26 ;
}
struct V_12 * F_89 ( struct V_27 * V_5 , T_2 V_46 ,
T_2 V_45 , T_1 V_23 , void * V_24 )
{
struct V_12 * V_13 = F_90 ( - V_230 ) ;
struct V_71 * V_29 = & V_5 -> V_231 ;
struct V_21 * V_22 ;
if ( strncmp ( V_232 , L_43 , 4 ) == 0 )
return F_90 ( - V_230 ) ;
V_22 = F_50 ( V_29 , V_46 , V_45 ) ;
if ( ! V_22 )
return F_90 ( - V_233 ) ;
F_91 ( V_22 ) ;
F_92 ( & V_5 -> V_234 ) ;
if ( ! V_5 -> V_203 )
F_1 () ;
if ( F_93 ( V_5 ) && F_94 ( V_5 ) == 0 ) {
F_77 ( V_22 , V_23 , NULL , & V_13 , 1 , V_24 ) ;
F_95 ( V_5 ) ;
}
F_96 ( & V_5 -> V_234 ) ;
F_97 ( V_22 ) ;
F_57 ( V_22 ) ;
F_28 ( & V_22 -> V_28 ) ;
return V_13 ;
}
int F_98 ( struct V_27 * V_42 , T_2 V_46 ,
T_2 V_235 , T_1 V_23 )
{
struct V_12 * V_13 =
F_89 ( V_42 , V_46 , V_235 , V_23 , NULL ) ;
if ( F_99 ( V_13 ) )
return F_100 ( V_13 ) ;
F_81 ( V_13 ) ;
return 0 ;
}
void F_101 ( struct V_71 * V_28 )
{
struct V_236 * V_237 ;
if ( ! V_28 -> V_238 )
return;
V_237 = F_102 ( V_28 -> V_238 ) ;
if ( F_103 ( V_237 -> V_239 ) ) {
if ( V_237 -> V_194 )
V_237 -> V_194 ( V_28 ) ;
F_104 ( V_237 -> V_239 ) ;
}
}
static void F_105 ( struct V_71 * V_29 , unsigned int V_46 ,
unsigned int V_45 , T_1 V_23 , int V_194 )
{
struct V_27 * V_5 = F_19 ( V_29 ) ;
int V_105 = 0 ;
int V_195 ;
struct V_21 * V_22 ;
if ( V_5 -> V_240 == V_45 )
return;
V_22 = F_50 ( V_29 , V_46 , V_45 ) ;
if ( ! V_22 )
return;
F_91 ( V_22 ) ;
if ( V_23 != V_241 ) {
F_77 ( V_22 , V_23 , NULL , NULL , V_194 , NULL ) ;
goto V_242;
}
V_195 = F_77 ( V_22 , 0 , & V_105 , NULL , V_194 , NULL ) ;
if ( V_195 == V_185 || V_195 == V_201 ) {
if ( F_88 ( V_22 , V_105 , V_194 ) != 0 )
F_84 ( V_22 , V_105 ,
V_22 -> V_92 , V_194 ) ;
}
V_242:
F_97 ( V_22 ) ;
F_57 ( V_22 ) ;
F_28 ( & V_22 -> V_28 ) ;
}
void F_106 ( struct V_71 * V_29 , unsigned int V_46 ,
unsigned int V_45 , T_1 V_23 , int V_194 )
{
struct V_27 * V_5 = F_19 ( V_29 ) ;
if ( strncmp ( V_232 , L_43 , 4 ) == 0 )
return;
F_92 ( & V_5 -> V_234 ) ;
if ( ! V_5 -> V_203 )
F_1 () ;
if ( F_93 ( V_5 ) && F_94 ( V_5 ) == 0 ) {
F_105 ( V_29 , V_46 , V_45 , V_23 , V_194 ) ;
F_95 ( V_5 ) ;
}
F_96 ( & V_5 -> V_234 ) ;
}
static void F_107 ( struct V_27 * V_5 , unsigned int V_46 ,
unsigned int V_45 , T_1 V_23 , int V_194 )
{
T_2 V_243 ;
if ( V_45 == V_241 )
for ( V_45 = 0 ; V_45 < V_5 -> V_244 ; ++ V_45 ) {
if ( V_5 -> V_245 )
V_243 = V_5 -> V_244 - V_45 - 1 ;
else
V_243 = V_45 ;
F_105 ( & V_5 -> V_231 , V_46 ,
V_243 , V_23 , V_194 ) ;
}
else
F_105 ( & V_5 -> V_231 , V_46 ,
V_45 , V_23 , V_194 ) ;
}
int F_108 ( struct V_27 * V_5 , unsigned int V_46 ,
unsigned int V_45 , T_1 V_23 , int V_194 )
{
F_61 ( 3 , F_109 ( V_10 , V_5 ,
L_44 ,
V_70 , V_46 , V_45 , V_23 ) ) ;
if ( ( ( V_46 != V_241 ) && ( V_46 > V_5 -> V_246 ) ) ||
( ( V_45 != V_241 ) && ( V_45 >= V_5 -> V_244 ) ) ||
( ( V_23 != V_241 ) && ( V_23 > V_5 -> V_208 ) ) )
return - V_247 ;
F_92 ( & V_5 -> V_234 ) ;
if ( ! V_5 -> V_203 )
F_1 () ;
if ( F_93 ( V_5 ) && F_94 ( V_5 ) == 0 ) {
if ( V_46 == V_241 )
for ( V_46 = 0 ; V_46 <= V_5 -> V_246 ;
V_46 ++ )
F_107 ( V_5 , V_46 , V_45 , V_23 ,
V_194 ) ;
else
F_107 ( V_5 , V_46 , V_45 , V_23 , V_194 ) ;
F_95 ( V_5 ) ;
}
F_96 ( & V_5 -> V_234 ) ;
return 0 ;
}
static void F_110 ( struct V_27 * V_5 )
{
struct V_12 * V_13 ;
F_111 (sdev, shost) {
if ( V_13 -> V_47 == V_248 )
continue;
if ( ! F_93 ( V_5 ) ||
F_75 ( V_13 ) != 0 )
F_33 ( V_13 ) ;
}
}
static struct V_1 * F_112 ( struct V_27 * V_5 )
{
struct V_1 * V_2 ;
unsigned long V_72 ;
if ( strncmp ( V_232 , L_45 , 4 ) == 0 )
return NULL ;
if ( V_5 -> V_203 ) {
F_109 ( V_10 , V_5 , L_46 , V_70 ) ;
F_113 () ;
return NULL ;
}
V_2 = F_3 ( sizeof( * V_2 ) , V_4 ) ;
if ( ! V_2 )
goto V_249;
V_2 -> V_5 = F_114 ( V_5 ) ;
if ( ! V_2 -> V_5 )
goto V_249;
F_5 ( & V_2 -> V_6 ) ;
F_92 ( & V_5 -> V_234 ) ;
F_36 ( V_5 -> V_75 , V_72 ) ;
V_5 -> V_203 = 1 ;
F_38 ( V_5 -> V_75 , V_72 ) ;
F_96 ( & V_5 -> V_234 ) ;
F_6 ( & V_7 ) ;
if ( F_2 ( & V_3 ) )
F_13 ( & V_2 -> V_6 ) ;
F_7 ( & V_2 -> V_9 , & V_3 ) ;
F_8 ( & V_7 ) ;
return V_2 ;
V_249:
F_14 ( V_2 ) ;
return NULL ;
}
static void F_115 ( struct V_1 * V_2 )
{
struct V_27 * V_5 ;
unsigned long V_72 ;
if ( ! V_2 )
return;
V_5 = V_2 -> V_5 ;
F_92 ( & V_5 -> V_234 ) ;
if ( ! V_5 -> V_203 ) {
F_109 ( V_10 , V_5 , L_46 , V_70 ) ;
F_113 () ;
F_96 ( & V_5 -> V_234 ) ;
return;
}
F_10 ( & V_2 -> V_6 ) ;
F_110 ( V_5 ) ;
F_36 ( V_5 -> V_75 , V_72 ) ;
V_5 -> V_203 = 0 ;
F_38 ( V_5 -> V_75 , V_72 ) ;
F_96 ( & V_5 -> V_234 ) ;
F_6 ( & V_7 ) ;
F_11 ( & V_2 -> V_9 ) ;
if ( ! F_2 ( & V_3 ) ) {
struct V_1 * V_11 = F_12 ( V_3 . V_11 ,
struct V_1 , V_9 ) ;
F_13 ( & V_11 -> V_6 ) ;
}
F_8 ( & V_7 ) ;
F_95 ( V_5 ) ;
F_116 ( V_5 ) ;
F_14 ( V_2 ) ;
}
static void F_117 ( struct V_27 * V_5 )
{
if ( V_5 -> V_65 -> V_250 ) {
unsigned long V_251 = V_252 ;
if ( V_5 -> V_65 -> V_253 )
V_5 -> V_65 -> V_253 ( V_5 ) ;
while ( ! V_5 -> V_65 -> V_250 ( V_5 , V_252 - V_251 ) )
F_4 ( 10 ) ;
} else {
F_108 ( V_5 , V_241 , V_241 ,
V_241 , 0 ) ;
}
}
static void F_118 ( void * V_254 , T_4 V_255 )
{
struct V_1 * V_2 = V_254 ;
struct V_27 * V_5 = V_2 -> V_5 ;
F_117 ( V_5 ) ;
F_115 ( V_2 ) ;
}
void F_119 ( struct V_27 * V_5 )
{
struct V_1 * V_2 ;
if ( strncmp ( V_232 , L_43 , 4 ) == 0 )
return;
if ( F_94 ( V_5 ) < 0 )
return;
V_2 = F_112 ( V_5 ) ;
if ( ! V_2 ) {
F_117 ( V_5 ) ;
F_95 ( V_5 ) ;
return;
}
F_120 ( F_118 , V_2 ) ;
}
void F_121 ( struct V_27 * V_5 )
{
struct V_12 * V_13 ;
unsigned long V_72 ;
V_256:
F_36 ( V_5 -> V_75 , V_72 ) ;
F_43 (sdev, &shost->__devices, siblings) {
if ( V_13 -> V_47 == V_248 )
continue;
F_38 ( V_5 -> V_75 , V_72 ) ;
F_33 ( V_13 ) ;
goto V_256;
}
F_38 ( V_5 -> V_75 , V_72 ) ;
}
struct V_12 * F_122 ( struct V_27 * V_5 )
{
struct V_12 * V_13 = NULL ;
struct V_21 * V_22 ;
F_92 ( & V_5 -> V_234 ) ;
if ( ! F_93 ( V_5 ) )
goto V_37;
V_22 = F_50 ( & V_5 -> V_231 , 0 , V_5 -> V_240 ) ;
if ( ! V_22 )
goto V_37;
V_13 = F_18 ( V_22 , 0 , NULL ) ;
if ( V_13 )
V_13 -> V_61 = 0 ;
else
F_57 ( V_22 ) ;
F_28 ( & V_22 -> V_28 ) ;
V_37:
F_96 ( & V_5 -> V_234 ) ;
return V_13 ;
}
void F_123 ( struct V_12 * V_13 )
{
F_58 ( V_13 -> V_45 != V_13 -> V_42 -> V_240 ) ;
F_33 ( V_13 ) ;
}
