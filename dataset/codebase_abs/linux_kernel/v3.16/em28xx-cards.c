int F_1 ( void * V_1 , int V_2 , int V_3 , int V_4 )
{
struct V_5 * V_6 = V_1 ;
struct V_7 * V_8 = V_6 -> V_8 ;
int V_9 = 0 ;
if ( V_8 -> V_10 != V_11 && V_8 -> V_10 != V_12 )
return 0 ;
if ( V_3 != V_13 && V_3 != V_14 )
return 0 ;
V_9 = F_2 ( V_8 , V_8 -> V_15 . V_16 ) ;
return V_9 ;
}
static inline void F_3 ( struct V_7 * V_8 )
{
V_8 -> V_15 = V_17 [ V_8 -> V_18 ] ;
if ( ! V_8 -> V_15 . V_19 )
V_8 -> V_15 . V_19 = V_20 |
V_21 ;
if ( ! V_8 -> V_15 . V_22 )
V_8 -> V_15 . V_22 = V_23 |
V_24 ;
V_8 -> V_25 = V_8 -> V_15 . V_25 ;
}
static void F_4 ( struct V_7 * V_8 )
{
F_5 ( V_8 , V_26 , V_8 -> V_15 . V_19 & 0x7f ) ;
if ( ! V_8 -> V_15 . V_27 )
F_5 ( V_8 , V_28 , V_8 -> V_15 . V_22 ) ;
F_6 ( 50 ) ;
switch ( V_8 -> V_18 ) {
case V_29 :
V_8 -> V_30 = 2048000 ;
break;
case V_31 :
case V_32 :
F_5 ( V_8 , V_33 , 0x6d ) ;
F_6 ( 10 ) ;
F_5 ( V_8 , V_33 , 0x7d ) ;
F_6 ( 10 ) ;
break;
case V_34 :
F_5 ( V_8 , V_35 , 0x00 ) ;
F_6 ( 10 ) ;
F_5 ( V_8 , V_35 , 0x01 ) ;
F_6 ( 10 ) ;
F_5 ( V_8 , V_33 , 0xfd ) ;
F_7 ( 70 ) ;
F_5 ( V_8 , V_33 , 0xfc ) ;
F_7 ( 70 ) ;
F_5 ( V_8 , V_33 , 0xdc ) ;
F_7 ( 70 ) ;
F_5 ( V_8 , V_33 , 0xfc ) ;
F_7 ( 70 ) ;
break;
case V_36 :
F_5 ( V_8 , V_33 , 0xfe ) ;
F_7 ( 70 ) ;
F_5 ( V_8 , V_33 , 0xde ) ;
F_7 ( 70 ) ;
F_5 ( V_8 , V_33 , 0xfe ) ;
F_7 ( 70 ) ;
break;
case V_37 :
F_5 ( V_8 , V_33 , 0xfe ) ;
F_7 ( 70 ) ;
F_5 ( V_8 , V_33 , 0xde ) ;
F_7 ( 70 ) ;
F_5 ( V_8 , V_33 , 0xfe ) ;
F_7 ( 70 ) ;
break;
case V_38 :
case V_39 :
F_5 ( V_8 , V_33 , 0xfd ) ;
break;
case V_40 :
F_5 ( V_8 , V_33 , 0xff ) ;
F_6 ( 10 ) ;
F_5 ( V_8 , V_33 , 0xfe ) ;
F_6 ( 10 ) ;
F_5 ( V_8 , V_35 , 0x00 ) ;
F_6 ( 10 ) ;
F_5 ( V_8 , V_35 , 0x08 ) ;
F_6 ( 10 ) ;
break;
case V_41 :
F_8 ( V_8 , V_26 , L_1 , 1 ) ;
F_8 ( V_8 , V_28 , L_2 , 1 ) ;
F_8 ( V_8 , 0x0d , L_3 , 1 ) ;
F_8 ( V_8 , 0x08 , L_4 , 1 ) ;
F_6 ( 10 ) ;
F_8 ( V_8 , 0x08 , L_5 , 1 ) ;
F_6 ( 10 ) ;
F_8 ( V_8 , 0x08 , L_6 , 1 ) ;
F_6 ( 10 ) ;
F_8 ( V_8 , 0x08 , L_7 , 1 ) ;
break;
case V_42 :
F_8 ( V_8 , 0x08 , L_8 , 1 ) ;
break;
case V_43 :
F_5 ( V_8 , V_33 , 0xff ) ;
F_6 ( 70 ) ;
F_5 ( V_8 , V_33 , 0xf7 ) ;
F_6 ( 10 ) ;
F_5 ( V_8 , V_33 , 0xfe ) ;
F_6 ( 70 ) ;
F_5 ( V_8 , V_33 , 0xfd ) ;
F_6 ( 70 ) ;
break;
}
F_2 ( V_8 , V_8 -> V_15 . V_16 ) ;
F_9 ( V_8 , V_44 ) ;
F_9 ( V_8 , V_45 ) ;
}
static int F_10 ( struct V_7 * V_8 )
{
int V_46 ;
if ( V_8 -> V_15 . V_47 ) {
if ( V_8 -> V_48 == V_49 ) {
V_8 -> V_18 = V_50 ;
} else if ( V_8 -> V_48 == V_51 ||
V_8 -> V_48 == V_52 ) {
V_8 -> V_18 = V_53 ;
}
return 0 ;
}
for ( V_46 = 0 ; V_46 < F_11 ( V_54 ) ; V_46 ++ ) {
if ( V_8 -> V_55 == V_54 [ V_46 ] . V_55 ) {
V_8 -> V_18 = V_54 [ V_46 ] . V_18 ;
V_8 -> V_10 = V_54 [ V_46 ] . V_56 ;
F_12 ( L_9 ) ;
F_12 ( L_10
L_11 ) ;
F_12 ( L_12 ) ;
F_12 ( L_13
L_14 ) ;
F_12 ( L_15
L_16 ) ;
F_12 ( L_17 ,
V_17 [ V_8 -> V_18 ] . V_57 ) ;
return 0 ;
}
}
if ( ! V_8 -> V_58 )
F_13 ( V_8 , V_8 -> V_25 ) ;
for ( V_46 = 0 ; V_46 < F_11 ( V_59 ) ; V_46 ++ ) {
if ( V_8 -> V_58 == V_59 [ V_46 ] . V_55 ) {
V_8 -> V_18 = V_59 [ V_46 ] . V_18 ;
V_8 -> V_10 = V_59 [ V_46 ] . V_56 ;
F_12 ( L_9 ) ;
F_12 ( L_10
L_18 ) ;
F_12 ( L_12 ) ;
F_12 ( L_13
L_14 ) ;
F_12 ( L_15
L_16 ) ;
F_12 ( L_17 ,
V_17 [ V_8 -> V_18 ] . V_57 ) ;
return 0 ;
}
}
F_12 ( L_19
L_20 ) ;
F_12 ( L_21
L_22 ) ;
F_12 ( L_23 ) ;
F_12 ( L_24 ) ;
F_12 ( L_25 , V_8 -> V_55 ) ;
F_12 ( L_26 , V_8 -> V_58 ) ;
F_12 ( L_27
L_28 ) ;
for ( V_46 = 0 ; V_46 < V_60 ; V_46 ++ ) {
F_12 ( L_29 ,
V_46 , V_17 [ V_46 ] . V_57 ) ;
}
return - 1 ;
}
static void F_14 ( struct V_7 * V_8 )
{
if ( V_8 -> V_15 . V_47 ) {
if ( F_15 ( V_8 ) < 0 )
V_8 -> V_15 . V_47 = 0 ;
}
switch ( V_8 -> V_18 ) {
case V_53 :
case V_61 :
case V_62 :
if ( F_10 ( V_8 ) < 0 )
F_12 ( L_30 ) ;
else {
F_3 ( V_8 ) ;
F_4 ( V_8 ) ;
}
break;
default:
F_3 ( V_8 ) ;
}
F_16 ( L_31 ,
V_8 -> V_15 . V_57 , V_8 -> V_18 ) ;
V_8 -> V_10 = V_17 [ V_8 -> V_18 ] . V_10 ;
switch ( V_8 -> V_18 ) {
case V_63 :
case V_64 :
case V_65 :
case V_66 :
case V_67 :
case V_68 :
{
struct V_69 V_70 ;
if ( V_8 -> V_71 == NULL )
break;
#if F_17 ( V_72 ) && F_17 ( V_73 )
F_18 ( L_32 ) ;
#endif
V_8 -> V_74 [ V_8 -> V_25 ] . V_75 = 0xa0 >> 1 ;
F_19 ( & V_8 -> V_74 [ V_8 -> V_25 ] , & V_70 , V_8 -> V_71 ) ;
V_8 -> V_10 = V_70 . V_10 ;
if ( V_70 . V_76 == V_77 ) {
V_8 -> V_30 = 2048000 ;
V_8 -> V_15 . V_78 = 1 ;
}
break;
}
case V_40 :
F_5 ( V_8 , 0x0d , 0x42 ) ;
F_6 ( 10 ) ;
F_5 ( V_8 , V_33 , 0xfd ) ;
F_6 ( 10 ) ;
break;
case V_79 :
F_5 ( V_8 , V_33 , 0xf9 ) ;
break;
case V_61 :
case V_62 :
case V_80 :
if ( ! F_10 ( V_8 ) )
F_3 ( V_8 ) ;
F_2 ( V_8 , V_8 -> V_15 . V_16 ) ;
F_9 ( V_8 , V_44 ) ;
break;
case V_81 :
if ( ! F_10 ( V_8 ) )
F_3 ( V_8 ) ;
F_2 ( V_8 , V_8 -> V_15 . V_16 ) ;
F_9 ( V_8 , V_44 ) ;
break;
}
if ( V_8 -> V_15 . V_82 == V_83 ) {
F_12 ( L_33 ) ;
F_12 ( L_34
L_35 ) ;
F_12 ( L_36 ) ;
F_12 ( L_37
L_38 ) ;
}
F_20 ( V_8 -> V_71 ) ;
V_8 -> V_71 = NULL ;
if ( V_56 >= 0 )
V_8 -> V_10 = V_56 ;
}
void F_21 ( struct V_7 * V_8 , struct V_84 * V_85 )
{
memset ( V_85 , 0 , sizeof( * V_85 ) ) ;
V_85 -> V_86 = V_87 ;
V_85 -> V_88 = 64 ;
V_85 -> V_89 = V_17 [ V_8 -> V_18 ] . V_90 ;
switch ( V_8 -> V_18 ) {
case V_91 :
case V_64 :
case V_92 :
V_85 -> V_93 = V_94 ;
break;
case V_95 :
case V_96 :
case V_97 :
V_85 -> V_93 = V_94 ;
break;
case V_65 :
case V_98 :
V_85 -> V_93 = V_99 ;
break;
case V_100 :
V_85 -> V_93 = V_99 ;
V_85 -> V_86 = V_101 ;
break;
case V_66 :
case V_67 :
case V_102 :
V_85 -> V_93 = V_99 ;
break;
case V_103 :
case V_104 :
case V_81 :
V_85 -> V_93 = V_105 ;
V_85 -> V_86 = V_87 ;
break;
case V_106 :
V_85 -> V_93 = V_105 ;
V_85 -> V_86 = V_101 ;
break;
default:
V_85 -> V_93 = V_107 ;
}
}
static void F_22 ( struct V_108 * V_109 )
{
struct V_7 * V_8 = F_23 ( V_109 ,
struct V_7 , V_110 ) ;
if ( V_8 -> V_111 ) {
#if F_17 ( V_72 ) && F_17 ( V_73 )
F_18 ( L_39 ) ;
#endif
return;
}
F_24 ( V_8 ) ;
#if F_17 ( V_72 ) && F_17 ( V_73 )
if ( V_8 -> V_112 )
F_18 ( L_40 ) ;
if ( V_8 -> V_113 )
F_18 ( L_41 ) ;
else if ( V_8 -> V_114 )
F_18 ( L_39 ) ;
if ( V_8 -> V_15 . V_115 )
F_18 ( L_42 ) ;
if ( V_8 -> V_15 . V_116 ||
( ( V_8 -> V_15 . V_117 || V_8 -> V_15 . V_118 ) && ! V_119 ) )
F_18 ( L_43 ) ;
#endif
}
static void F_25 ( struct V_7 * V_8 )
{
F_26 ( & V_8 -> V_110 , F_22 ) ;
F_27 ( & V_8 -> V_110 ) ;
}
static void F_28 ( struct V_7 * V_8 )
{
F_29 ( & V_8 -> V_110 ) ;
}
static void F_30 ( struct V_7 * V_8 )
{
F_31 ( & V_8 -> V_120 ) ;
if ( V_8 -> V_25 )
F_32 ( V_8 , 1 ) ;
F_32 ( V_8 , 0 ) ;
F_33 ( V_8 -> V_121 ) ;
F_34 ( V_8 -> V_122 , V_123 ) ;
F_35 ( & V_8 -> V_120 ) ;
}
void F_36 ( struct V_124 * V_125 )
{
struct V_7 * V_8 = F_37 ( V_125 ) ;
F_16 ( L_44 ) ;
if ( ! V_8 -> V_126 )
F_30 ( V_8 ) ;
F_20 ( V_8 -> V_127 ) ;
F_20 ( V_8 ) ;
}
static int F_38 ( struct V_7 * V_8 , struct V_128 * V_121 ,
struct V_129 * V_130 ,
int V_131 )
{
int V_132 ;
static const char * V_133 = L_45 ;
const char * V_134 = V_133 ;
V_8 -> V_121 = V_121 ;
F_39 ( & V_8 -> V_135 ) ;
F_40 ( & V_8 -> V_136 ) ;
V_8 -> F_8 = F_8 ;
V_8 -> V_137 = V_137 ;
V_8 -> V_138 = V_138 ;
V_8 -> V_139 = V_139 ;
V_8 -> V_140 = V_140 ;
V_8 -> V_15 . V_27 = V_17 [ V_8 -> V_18 ] . V_27 ;
F_3 ( V_8 ) ;
V_8 -> V_141 = 5 ;
V_132 = V_137 ( V_8 , V_142 ) ;
if ( V_132 > 0 ) {
V_8 -> V_143 = V_132 ;
switch ( V_8 -> V_143 ) {
case V_144 :
V_134 = L_46 ;
break;
case V_145 :
V_134 = L_47 ;
break;
case V_146 :
V_134 = L_48 ;
break;
case V_147 :
V_134 = L_49 ;
V_8 -> V_141 = 0 ;
V_8 -> V_148 = 1 ;
V_8 -> V_149 = 1 ;
break;
case V_150 :
V_134 = L_50 ;
if ( F_41 ( V_8 -> V_121 -> V_151 . V_152 )
== 0xeb1a ) {
T_1 V_153 = V_8 -> V_121 -> V_151 . V_154 ;
if ( F_41 ( V_153 ) == 0x2710 )
V_134 = L_47 ;
else if ( F_41 ( V_153 ) == 0x2820 )
V_134 = L_51 ;
}
break;
case V_155 :
V_134 = L_52 ;
break;
case V_156 :
V_134 = L_53 ;
break;
case V_157 :
V_134 = L_54 ;
V_8 -> V_141 = 0 ;
break;
case V_158 :
V_134 = L_55 ;
V_8 -> V_141 = 0 ;
V_8 -> V_149 = 1 ;
break;
case V_159 :
V_134 = L_56 ;
V_8 -> V_141 = 0 ;
V_8 -> V_149 = 1 ;
break;
case V_160 :
V_134 = L_57 ;
V_8 -> V_141 = 0 ;
V_8 -> V_149 = 1 ;
break;
case V_161 :
V_134 = L_58 ;
V_8 -> V_141 = 0 ;
break;
case V_162 :
V_134 = L_59 ;
V_8 -> V_141 = 0 ;
V_8 -> V_149 = 1 ;
break;
default:
F_42 (KERN_INFO DRIVER_NAME
L_60 , dev->chip_id) ;
}
}
if ( V_8 -> V_143 == V_157 ||
V_8 -> V_143 == V_158 ||
V_8 -> V_143 == V_159 ||
V_8 -> V_143 == V_160 ) {
V_8 -> V_163 . V_164 = false ;
V_8 -> V_113 = false ;
V_8 -> V_114 = false ;
}
if ( V_134 != V_133 )
F_42 (KERN_INFO DRIVER_NAME
L_61 , chip_name) ;
snprintf ( V_8 -> V_57 , sizeof( V_8 -> V_57 ) , L_62 , V_134 , V_8 -> V_122 ) ;
if ( V_8 -> V_111 ) {
V_132 = F_43 ( V_8 ) ;
if ( V_132 )
return - V_165 ;
F_24 ( V_8 ) ;
return 0 ;
}
F_4 ( V_8 ) ;
if ( ! V_8 -> V_15 . V_27 ) {
V_132 = F_5 ( V_8 , V_28 , V_8 -> V_15 . V_22 ) ;
if ( V_132 < 0 ) {
F_12 ( L_63
L_64 ,
V_166 , V_132 ) ;
return V_132 ;
}
}
F_44 ( & V_8 -> V_167 ) ;
if ( V_8 -> V_15 . V_27 )
V_132 = F_45 ( V_8 , 0 , V_168 ) ;
else
V_132 = F_45 ( V_8 , 0 , V_169 ) ;
if ( V_132 < 0 ) {
F_12 ( L_65 ,
V_166 , V_132 ) ;
return V_132 ;
}
if ( V_8 -> V_25 ) {
if ( V_8 -> V_148 )
V_132 = F_45 ( V_8 , 1 ,
V_170 ) ;
else
V_132 = F_45 ( V_8 , 1 ,
V_169 ) ;
if ( V_132 < 0 ) {
F_12 ( L_66 ,
V_166 , V_132 ) ;
F_32 ( V_8 , 0 ) ;
return V_132 ;
}
}
F_14 ( V_8 ) ;
return 0 ;
}
static int F_46 ( struct V_129 * V_130 ,
const struct V_171 * V_172 )
{
struct V_128 * V_121 ;
struct V_7 * V_8 = NULL ;
int V_132 ;
bool V_164 = false , V_112 = false , V_115 = false ;
int V_46 , V_173 , V_174 ;
const int V_175 = V_130 -> V_176 [ 0 ] . V_177 . V_178 ;
char * V_179 ;
V_121 = F_47 ( F_48 ( V_130 ) ) ;
do {
V_173 = F_49 ( V_123 , V_180 ) ;
if ( V_173 >= V_180 ) {
F_42 ( V_181 L_67 ,
V_180 ) ;
V_132 = - V_182 ;
goto V_183;
}
} while ( F_50 ( V_173 , V_123 ) );
if ( V_130 -> V_176 [ 0 ] . V_177 . V_184 == V_185 ) {
F_51 ( V_181 L_68
L_69 ,
F_41 ( V_121 -> V_151 . V_152 ) ,
F_41 ( V_121 -> V_151 . V_154 ) ,
V_175 ,
V_130 -> V_176 [ 0 ] . V_177 . V_184 ) ;
V_132 = - V_165 ;
goto V_186;
}
V_8 = F_52 ( sizeof( * V_8 ) , V_187 ) ;
if ( V_8 == NULL ) {
F_51 ( V_181 L_70 ) ;
V_132 = - V_182 ;
goto V_186;
}
V_8 -> V_127 =
F_53 ( sizeof( V_8 -> V_127 [ 0 ] ) *
V_130 -> V_188 , V_187 ) ;
if ( V_8 -> V_127 == NULL ) {
F_12 ( L_71 ) ;
F_20 ( V_8 ) ;
V_132 = - V_182 ;
goto V_186;
}
for ( V_46 = 0 ; V_46 < V_130 -> V_188 ; V_46 ++ ) {
int V_189 ;
for ( V_189 = 0 ; V_189 < V_130 -> V_176 [ V_46 ] . V_177 . V_190 ; V_189 ++ ) {
const struct V_191 * V_192 ;
int V_193 , V_194 ;
V_192 = & V_130 -> V_176 [ V_46 ] . V_195 [ V_189 ] . V_177 ;
V_193 = F_41 ( V_192 -> V_196 ) ;
V_194 = V_193 & 0x7ff ;
if ( V_121 -> V_179 == V_197 )
V_194 = V_194 * F_54 ( V_193 ) ;
if ( F_55 ( V_192 ) ) {
switch ( V_192 -> V_198 ) {
case 0x82 :
V_112 = true ;
if ( F_56 ( V_192 ) ) {
V_8 -> V_199 =
V_192 -> V_198 ;
V_8 -> V_127 [ V_46 ] = V_194 ;
} else if ( F_57 ( V_192 ) ) {
V_8 -> V_200 =
V_192 -> V_198 ;
}
break;
case 0x83 :
if ( F_56 ( V_192 ) ) {
V_164 = true ;
} else {
F_42 (KERN_INFO DRIVER_NAME
L_72 ) ;
}
break;
case 0x84 :
if ( V_112 &&
( F_57 ( V_192 ) ) ) {
V_8 -> V_200 =
V_192 -> V_198 ;
} else {
if ( F_56 ( V_192 ) ) {
if ( V_194 > V_8 -> V_201 ) {
V_115 = true ;
V_8 -> V_202 = V_192 -> V_198 ;
V_8 -> V_201 = V_194 ;
V_8 -> V_203 = V_46 ;
}
} else {
V_115 = true ;
V_8 -> V_204 = V_192 -> V_198 ;
}
}
break;
}
}
}
}
if ( ! ( V_164 || V_112 || V_115 ) ) {
V_132 = - V_165 ;
goto V_205;
}
switch ( V_121 -> V_179 ) {
case V_206 :
V_179 = L_73 ;
break;
case V_207 :
case V_208 :
V_179 = L_74 ;
break;
case V_197 :
V_179 = L_75 ;
break;
default:
V_179 = L_76 ;
}
F_42 (KERN_INFO DRIVER_NAME
L_77
L_78 ,
udev->manufacturer ? udev->manufacturer : L_79 ,
udev->product ? udev->product : L_79 ,
speed,
le16_to_cpu(udev->descriptor.idVendor),
le16_to_cpu(udev->descriptor.idProduct),
ifnum,
interface->altsetting->desc.bInterfaceNumber) ;
if ( V_121 -> V_179 != V_197 && V_209 == 0 ) {
F_42 ( V_181 L_80 ) ;
F_42 ( V_181 L_81
L_82 ) ;
V_132 = - V_165 ;
goto V_205;
}
V_8 -> V_122 = V_173 ;
V_8 -> V_18 = V_172 -> V_210 ;
V_8 -> V_211 = - 1 ;
V_8 -> V_111 = V_164 && ! ( V_112 || V_115 ) ;
V_8 -> V_114 = V_164 ;
V_8 -> V_163 . V_164 = V_164 ;
V_8 -> V_112 = V_112 ;
V_8 -> V_175 = V_175 ;
for ( V_46 = 0 ; V_46 < V_121 -> V_212 -> V_177 . V_213 ; V_46 ++ ) {
struct V_129 * V_214 = V_121 -> V_212 -> V_130 [ V_46 ] ;
if ( V_214 -> V_176 [ 0 ] . V_177 . V_184 == V_185 ) {
V_8 -> V_113 = 1 ;
break;
}
}
if ( V_164 )
F_42 (KERN_INFO DRIVER_NAME
L_83 ,
ifnum,
dev->has_audio_class ? L_84 : L_85 ) ;
if ( V_112 )
F_42 (KERN_INFO DRIVER_NAME
L_86 ,
ifnum,
dev->analog_ep_bulk ? L_87 : L_79 ,
dev->analog_ep_isoc ? L_88 : L_79 ) ;
if ( V_115 )
F_42 (KERN_INFO DRIVER_NAME
L_89 ,
ifnum,
dev->dvb_ep_bulk ? L_87 : L_79 ,
dev->dvb_ep_isoc ? L_88 : L_79 ) ;
V_8 -> V_215 = V_130 -> V_188 ;
if ( ( unsigned ) V_216 [ V_173 ] < V_60 )
V_8 -> V_18 = V_216 [ V_173 ] ;
F_58 ( V_130 , V_8 ) ;
F_39 ( & V_8 -> V_120 ) ;
V_132 = F_38 ( V_8 , V_121 , V_130 , V_173 ) ;
if ( V_132 ) {
goto V_205;
}
if ( V_217 < 0 ) {
if ( V_8 -> V_15 . V_47 )
V_174 = 1 ;
else
V_174 = 0 ;
} else {
V_174 = V_217 > 0 ;
}
if ( V_112 ) {
if ( ! V_8 -> V_199 || ( V_174 && V_8 -> V_200 ) )
V_8 -> V_218 = 1 ;
F_16 ( L_90 ,
V_8 -> V_218 ? L_91 : L_92 ) ;
}
if ( V_115 ) {
if ( ! V_8 -> V_202 || ( V_174 && V_8 -> V_204 ) )
V_8 -> V_219 = 1 ;
F_16 ( L_93 ,
V_8 -> V_219 ? L_91 : L_92 ) ;
}
F_59 ( & V_8 -> V_125 ) ;
F_25 ( V_8 ) ;
return 0 ;
V_205:
F_20 ( V_8 -> V_127 ) ;
F_20 ( V_8 ) ;
V_186:
F_34 ( V_173 , V_123 ) ;
V_183:
F_33 ( V_121 ) ;
return V_132 ;
}
static void F_60 ( struct V_129 * V_130 )
{
struct V_7 * V_8 ;
V_8 = F_61 ( V_130 ) ;
F_58 ( V_130 , NULL ) ;
if ( ! V_8 )
return;
V_8 -> V_126 = 1 ;
F_16 ( L_94 , V_8 -> V_57 ) ;
F_28 ( V_8 ) ;
F_62 ( V_8 ) ;
F_30 ( V_8 ) ;
F_63 ( & V_8 -> V_125 , F_36 ) ;
}
static int F_64 ( struct V_129 * V_130 ,
T_2 V_220 )
{
struct V_7 * V_8 ;
V_8 = F_61 ( V_130 ) ;
if ( ! V_8 )
return 0 ;
F_65 ( V_8 ) ;
return 0 ;
}
static int F_66 ( struct V_129 * V_130 )
{
struct V_7 * V_8 ;
V_8 = F_61 ( V_130 ) ;
if ( ! V_8 )
return 0 ;
F_67 ( V_8 ) ;
return 0 ;
}
