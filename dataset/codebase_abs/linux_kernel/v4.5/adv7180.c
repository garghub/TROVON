static int F_1 ( struct V_1 * V_2 , unsigned int V_3 )
{
if ( V_2 -> V_4 != V_3 ) {
F_2 ( V_2 -> V_5 , V_6 ,
V_3 ) ;
V_2 -> V_4 = V_3 ;
}
return 0 ;
}
static int F_3 ( struct V_1 * V_2 , unsigned int V_7 ,
unsigned int V_8 )
{
F_4 ( & V_2 -> V_9 ) ;
F_1 ( V_2 , V_7 >> 8 ) ;
return F_2 ( V_2 -> V_5 , V_7 & 0xff , V_8 ) ;
}
static int F_5 ( struct V_1 * V_2 , unsigned int V_7 )
{
F_4 ( & V_2 -> V_9 ) ;
F_1 ( V_2 , V_7 >> 8 ) ;
return F_6 ( V_2 -> V_5 , V_7 & 0xff ) ;
}
static int F_7 ( struct V_1 * V_2 , unsigned int V_7 ,
unsigned int V_8 )
{
return F_2 ( V_2 -> V_10 , V_7 , V_8 ) ;
}
static int F_8 ( struct V_1 * V_2 ,
unsigned int V_11 )
{
return V_2 -> V_12 -> V_13 ( V_2 , V_11 ) ;
}
static int F_9 ( struct V_1 * V_2 , unsigned int V_7 ,
unsigned int V_8 )
{
return F_2 ( V_2 -> V_14 , V_7 , V_8 ) ;
}
static T_1 F_10 ( T_2 V_15 )
{
if ( ! ( V_15 & V_16 ) )
return V_17 ;
switch ( V_15 & V_18 ) {
case V_19 :
return V_20 ;
case V_21 :
return V_22 ;
case V_23 :
return V_24 ;
case V_25 :
return V_26 ;
case V_27 :
return V_28 ;
case V_29 :
return V_30 ;
case V_31 :
return V_32 | V_33 ;
case V_34 :
return V_30 ;
default:
return V_17 ;
}
}
static int F_11 ( T_1 V_11 )
{
if ( V_11 == V_26 )
return V_35 ;
if ( V_11 == V_22 )
return V_36 ;
if ( V_11 == V_33 )
return V_37 ;
if ( V_11 == V_24 )
return V_38 ;
if ( V_11 == V_32 )
return V_39 ;
if ( V_11 & V_28 )
return V_40 ;
if ( V_11 & V_20 )
return V_41 ;
if ( V_11 & V_30 )
return V_42 ;
return - V_43 ;
}
static T_3 F_12 ( T_2 V_15 )
{
if ( ! ( V_15 & V_16 ) )
return V_44 ;
return 0 ;
}
static int F_13 ( struct V_1 * V_2 , T_3 * V_45 ,
T_1 * V_11 )
{
int V_15 = F_5 ( V_2 , V_46 ) ;
if ( V_15 < 0 )
return V_15 ;
if ( V_45 )
* V_45 = F_12 ( V_15 ) ;
if ( V_11 )
* V_11 = F_10 ( V_15 ) ;
return 0 ;
}
static inline struct V_1 * F_14 ( struct V_47 * V_48 )
{
return F_15 ( V_48 , struct V_1 , V_48 ) ;
}
static int F_16 ( struct V_47 * V_48 , T_1 * V_11 )
{
struct V_1 * V_2 = F_14 ( V_48 ) ;
int V_49 = F_17 ( & V_2 -> V_9 ) ;
if ( V_49 )
return V_49 ;
if ( ! V_2 -> V_50 || V_2 -> V_51 > 0 )
* V_11 = V_2 -> V_52 ;
else
V_49 = F_13 ( V_2 , NULL , V_11 ) ;
F_18 ( & V_2 -> V_9 ) ;
return V_49 ;
}
static int F_19 ( struct V_47 * V_48 , T_3 V_53 ,
T_3 V_54 , T_3 V_55 )
{
struct V_1 * V_2 = F_14 ( V_48 ) ;
int V_56 = F_17 ( & V_2 -> V_9 ) ;
if ( V_56 )
return V_56 ;
if ( V_53 > 31 || ! ( F_20 ( V_53 ) & V_2 -> V_12 -> V_57 ) ) {
V_56 = - V_43 ;
goto V_58;
}
V_56 = V_2 -> V_12 -> V_59 ( V_2 , V_53 ) ;
if ( V_56 == 0 )
V_2 -> V_53 = V_53 ;
V_58:
F_18 ( & V_2 -> V_9 ) ;
return V_56 ;
}
static int F_21 ( struct V_47 * V_48 , T_3 * V_45 )
{
struct V_1 * V_2 = F_14 ( V_48 ) ;
int V_56 = F_17 ( & V_2 -> V_9 ) ;
if ( V_56 )
return V_56 ;
V_56 = F_13 ( V_2 , V_45 , NULL ) ;
F_18 ( & V_2 -> V_9 ) ;
return V_56 ;
}
static int F_22 ( struct V_1 * V_2 )
{
int V_56 ;
if ( V_2 -> V_50 ) {
V_56 = F_8 ( V_2 ,
V_60 ) ;
if ( V_56 < 0 )
return V_56 ;
F_13 ( V_2 , NULL , & V_2 -> V_52 ) ;
} else {
V_56 = F_11 ( V_2 -> V_52 ) ;
if ( V_56 < 0 )
return V_56 ;
V_56 = F_8 ( V_2 , V_56 ) ;
if ( V_56 < 0 )
return V_56 ;
}
return 0 ;
}
static int F_23 ( struct V_47 * V_48 , T_1 V_11 )
{
struct V_1 * V_2 = F_14 ( V_48 ) ;
int V_56 = F_17 ( & V_2 -> V_9 ) ;
if ( V_56 )
return V_56 ;
if ( V_11 == V_61 ) {
V_2 -> V_50 = true ;
} else {
V_56 = F_11 ( V_11 ) ;
if ( V_56 < 0 )
goto V_58;
V_2 -> V_52 = V_11 ;
V_2 -> V_50 = false ;
}
V_56 = F_22 ( V_2 ) ;
V_58:
F_18 ( & V_2 -> V_9 ) ;
return V_56 ;
}
static int F_24 ( struct V_1 * V_2 , bool V_62 )
{
T_2 V_63 ;
int V_56 ;
if ( V_62 )
V_63 = V_64 ;
else
V_63 = V_65 ;
V_56 = F_3 ( V_2 , V_66 , V_63 ) ;
if ( V_56 )
return V_56 ;
if ( V_2 -> V_12 -> V_67 & V_68 ) {
if ( V_62 ) {
F_7 ( V_2 , 0xDE , 0x02 ) ;
F_7 ( V_2 , 0xD2 , 0xF7 ) ;
F_7 ( V_2 , 0xD8 , 0x65 ) ;
F_7 ( V_2 , 0xE0 , 0x09 ) ;
F_7 ( V_2 , 0x2C , 0x00 ) ;
if ( V_2 -> V_69 == V_70 )
F_7 ( V_2 , 0x1D , 0x80 ) ;
F_7 ( V_2 , 0x00 , 0x00 ) ;
} else {
F_7 ( V_2 , 0x00 , 0x80 ) ;
}
}
return 0 ;
}
static int F_25 ( struct V_47 * V_48 , int V_62 )
{
struct V_1 * V_2 = F_14 ( V_48 ) ;
int V_56 ;
V_56 = F_17 ( & V_2 -> V_9 ) ;
if ( V_56 )
return V_56 ;
V_56 = F_24 ( V_2 , V_62 ) ;
if ( V_56 == 0 )
V_2 -> V_71 = V_62 ;
F_18 ( & V_2 -> V_9 ) ;
return V_56 ;
}
static int F_26 ( struct V_72 * V_73 )
{
struct V_47 * V_48 = F_27 ( V_73 ) ;
struct V_1 * V_2 = F_14 ( V_48 ) ;
int V_56 = F_17 ( & V_2 -> V_9 ) ;
int V_63 ;
if ( V_56 )
return V_56 ;
V_63 = V_73 -> V_63 ;
switch ( V_73 -> V_74 ) {
case V_75 :
V_56 = F_3 ( V_2 , V_76 , V_63 ) ;
break;
case V_77 :
V_56 = F_3 ( V_2 , V_78 , - V_63 ) ;
break;
case V_79 :
V_56 = F_3 ( V_2 , V_80 , V_63 ) ;
break;
case V_81 :
V_56 = F_3 ( V_2 , V_82 , V_63 ) ;
if ( V_56 < 0 )
break;
V_56 = F_3 ( V_2 , V_83 , V_63 ) ;
break;
case V_84 :
if ( V_73 -> V_63 ) {
F_3 ( V_2 , 0x80d9 , 0x44 ) ;
F_3 ( V_2 , V_85 ,
V_86 ) ;
} else {
F_3 ( V_2 , 0x80d9 , 0xc4 ) ;
F_3 ( V_2 , V_85 , 0x00 ) ;
}
break;
default:
V_56 = - V_43 ;
}
F_18 ( & V_2 -> V_9 ) ;
return V_56 ;
}
static int F_28 ( struct V_1 * V_2 )
{
F_29 ( & V_2 -> V_87 , 4 ) ;
F_30 ( & V_2 -> V_87 , & V_88 ,
V_75 , V_89 ,
V_90 , 1 , V_91 ) ;
F_30 ( & V_2 -> V_87 , & V_88 ,
V_79 , V_92 ,
V_93 , 1 , V_94 ) ;
F_30 ( & V_2 -> V_87 , & V_88 ,
V_81 , V_95 ,
V_96 , 1 , V_97 ) ;
F_30 ( & V_2 -> V_87 , & V_88 ,
V_77 , V_98 ,
V_99 , 1 , V_100 ) ;
F_31 ( & V_2 -> V_87 , & V_101 , NULL ) ;
V_2 -> V_48 . V_102 = & V_2 -> V_87 ;
if ( V_2 -> V_87 . error ) {
int V_49 = V_2 -> V_87 . error ;
F_32 ( & V_2 -> V_87 ) ;
return V_49 ;
}
F_33 ( & V_2 -> V_87 ) ;
return 0 ;
}
static void F_34 ( struct V_1 * V_2 )
{
F_32 ( & V_2 -> V_87 ) ;
}
static int F_35 ( struct V_47 * V_48 ,
struct V_103 * V_104 ,
struct V_105 * V_106 )
{
if ( V_106 -> V_107 != 0 )
return - V_43 ;
V_106 -> V_106 = V_108 ;
return 0 ;
}
static int F_36 ( struct V_47 * V_48 ,
struct V_109 * V_110 )
{
struct V_1 * V_2 = F_14 ( V_48 ) ;
V_110 -> V_106 = V_108 ;
V_110 -> V_111 = V_112 ;
V_110 -> V_113 = 720 ;
V_110 -> V_114 = V_2 -> V_52 & V_115 ? 480 : 576 ;
return 0 ;
}
static int F_37 ( struct V_1 * V_2 )
{
if ( ! ( V_2 -> V_12 -> V_67 & V_116 ) )
return 0 ;
if ( V_2 -> V_69 == V_70 ) {
if ( V_2 -> V_12 -> V_67 & V_68 ) {
F_7 ( V_2 , 0x01 , 0x20 ) ;
F_7 ( V_2 , 0x02 , 0x28 ) ;
F_7 ( V_2 , 0x03 , 0x38 ) ;
F_7 ( V_2 , 0x04 , 0x30 ) ;
F_7 ( V_2 , 0x05 , 0x30 ) ;
F_7 ( V_2 , 0x06 , 0x80 ) ;
F_7 ( V_2 , 0x07 , 0x70 ) ;
F_7 ( V_2 , 0x08 , 0x50 ) ;
}
F_9 ( V_2 , 0xa3 , 0x00 ) ;
F_9 ( V_2 , 0x5b , 0x00 ) ;
F_9 ( V_2 , 0x55 , 0x80 ) ;
} else {
if ( V_2 -> V_12 -> V_67 & V_68 ) {
F_7 ( V_2 , 0x01 , 0x18 ) ;
F_7 ( V_2 , 0x02 , 0x18 ) ;
F_7 ( V_2 , 0x03 , 0x30 ) ;
F_7 ( V_2 , 0x04 , 0x20 ) ;
F_7 ( V_2 , 0x05 , 0x28 ) ;
F_7 ( V_2 , 0x06 , 0x40 ) ;
F_7 ( V_2 , 0x07 , 0x58 ) ;
F_7 ( V_2 , 0x08 , 0x30 ) ;
}
F_9 ( V_2 , 0xa3 , 0x70 ) ;
F_9 ( V_2 , 0x5b , 0x80 ) ;
F_9 ( V_2 , 0x55 , 0x00 ) ;
}
return 0 ;
}
static int F_38 ( struct V_47 * V_48 ,
struct V_103 * V_104 ,
struct V_117 * V_118 )
{
struct V_1 * V_2 = F_14 ( V_48 ) ;
if ( V_118 -> V_119 == V_120 ) {
V_118 -> V_118 = * F_39 ( V_48 , V_104 , 0 ) ;
} else {
F_36 ( V_48 , & V_118 -> V_118 ) ;
V_118 -> V_118 . V_69 = V_2 -> V_69 ;
}
return 0 ;
}
static int F_40 ( struct V_47 * V_48 ,
struct V_103 * V_104 ,
struct V_117 * V_118 )
{
struct V_1 * V_2 = F_14 ( V_48 ) ;
struct V_109 * V_121 ;
switch ( V_118 -> V_118 . V_69 ) {
case V_70 :
if ( ! ( V_2 -> V_12 -> V_67 & V_116 ) )
V_118 -> V_118 . V_69 = V_122 ;
break;
default:
V_118 -> V_118 . V_69 = V_122 ;
break;
}
if ( V_118 -> V_119 == V_123 ) {
V_121 = & V_118 -> V_118 ;
if ( V_2 -> V_69 != V_118 -> V_118 . V_69 ) {
V_2 -> V_69 = V_118 -> V_118 . V_69 ;
F_24 ( V_2 , false ) ;
F_37 ( V_2 ) ;
F_24 ( V_2 , true ) ;
}
} else {
V_121 = F_39 ( V_48 , V_104 , 0 ) ;
* V_121 = V_118 -> V_118 ;
}
return F_36 ( V_48 , V_121 ) ;
}
static int F_41 ( struct V_47 * V_48 ,
struct V_124 * V_104 )
{
struct V_1 * V_2 = F_14 ( V_48 ) ;
if ( V_2 -> V_12 -> V_67 & V_68 ) {
V_104 -> type = V_125 ;
V_104 -> V_67 = V_126 |
V_127 |
V_128 ;
} else {
V_104 -> V_67 = V_129 | V_130 |
V_131 ;
V_104 -> type = V_132 ;
}
return 0 ;
}
static T_4 F_42 ( int V_51 , void * V_133 )
{
struct V_1 * V_2 = V_133 ;
T_2 V_134 ;
F_43 ( & V_2 -> V_9 ) ;
V_134 = F_5 ( V_2 , V_135 ) ;
F_3 ( V_2 , V_136 , V_134 ) ;
if ( V_134 & V_137 && V_2 -> V_50 )
F_13 ( V_2 , NULL , & V_2 -> V_52 ) ;
F_18 ( & V_2 -> V_9 ) ;
return V_138 ;
}
static int F_44 ( struct V_1 * V_2 )
{
int V_56 ;
V_56 = F_3 ( V_2 , V_139 ,
V_140 ) ;
if ( V_56 < 0 )
return V_56 ;
return F_3 ( V_2 , V_141 ,
V_142 ) ;
}
static int F_45 ( struct V_1 * V_2 , unsigned int V_11 )
{
return F_3 ( V_2 , V_143 ,
( V_11 << 4 ) | V_2 -> V_53 ) ;
}
static int F_46 ( struct V_1 * V_2 , unsigned int V_53 )
{
int V_56 ;
V_56 = F_5 ( V_2 , V_143 ) ;
if ( V_56 < 0 )
return V_56 ;
V_56 &= ~ V_144 ;
V_56 |= V_53 ;
return F_3 ( V_2 , V_143 , V_56 ) ;
}
static int F_47 ( struct V_1 * V_2 )
{
if ( V_2 -> V_12 -> V_67 & V_68 )
F_3 ( V_2 , V_145 ,
V_146 << 1 ) ;
if ( V_2 -> V_12 -> V_67 & V_116 )
F_3 ( V_2 , V_147 ,
V_148 << 1 ) ;
if ( V_2 -> V_12 -> V_67 & V_149 ) {
F_3 ( V_2 , 0x0080 , 0x51 ) ;
F_3 ( V_2 , 0x0081 , 0x51 ) ;
F_3 ( V_2 , 0x0082 , 0x68 ) ;
}
if ( V_2 -> V_12 -> V_67 & V_68 ) {
F_3 ( V_2 , 0x0003 , 0x4e ) ;
F_3 ( V_2 , 0x0004 , 0x57 ) ;
F_3 ( V_2 , 0x001d , 0xc0 ) ;
} else {
if ( V_2 -> V_12 -> V_67 & V_149 )
F_3 ( V_2 , 0x0004 , 0x17 ) ;
else
F_3 ( V_2 , 0x0004 , 0x07 ) ;
F_3 ( V_2 , 0x0003 , 0x0c ) ;
F_3 ( V_2 , 0x001d , 0x40 ) ;
}
F_3 ( V_2 , 0x0013 , 0x00 ) ;
return 0 ;
}
static int F_48 ( struct V_1 * V_2 , unsigned int V_11 )
{
return F_3 ( V_2 , V_150 , V_11 << 4 ) ;
}
static enum V_151 F_49 ( unsigned int V_53 )
{
switch ( V_53 ) {
case V_152 :
case V_153 :
case V_154 :
case V_155 :
case V_156 :
case V_157 :
case V_158 :
case V_159 :
return V_160 ;
case V_161 :
case V_162 :
case V_163 :
case V_164 :
return V_165 ;
case V_166 :
case V_167 :
return V_168 ;
case V_169 :
case V_170 :
case V_171 :
case V_172 :
return V_173 ;
default:
return 0 ;
}
}
static int F_50 ( struct V_1 * V_2 , unsigned int V_53 )
{
enum V_151 V_174 ;
unsigned int * V_175 ;
unsigned int V_176 ;
int V_56 ;
V_56 = F_3 ( V_2 , V_143 , V_53 ) ;
if ( V_56 )
return V_56 ;
F_3 ( V_2 , 0x809c , 0x00 ) ;
F_3 ( V_2 , 0x809c , 0xff ) ;
V_174 = F_49 ( V_53 ) ;
switch ( V_174 ) {
case V_160 :
case V_173 :
F_3 ( V_2 , 0x0017 , 0x41 ) ;
break;
default:
F_3 ( V_2 , 0x0017 , 0x01 ) ;
break;
}
if ( V_2 -> V_12 -> V_67 & V_149 )
V_175 = V_177 [ V_174 ] ;
else
V_175 = V_178 [ V_174 ] ;
for ( V_176 = 0 ; V_176 < F_51 ( V_178 [ 0 ] ) ; V_176 ++ )
F_3 ( V_2 , 0x0052 + V_176 , V_175 [ V_176 ] ) ;
if ( V_174 == V_173 ) {
F_3 ( V_2 , 0x005f , 0xa8 ) ;
F_3 ( V_2 , 0x005a , 0x90 ) ;
F_3 ( V_2 , 0x0060 , 0xb0 ) ;
F_3 ( V_2 , 0x80b6 , 0x08 ) ;
F_3 ( V_2 , 0x80c0 , 0xa0 ) ;
} else {
F_3 ( V_2 , 0x005f , 0xf0 ) ;
F_3 ( V_2 , 0x005a , 0xd0 ) ;
F_3 ( V_2 , 0x0060 , 0x10 ) ;
F_3 ( V_2 , 0x80b6 , 0x9c ) ;
F_3 ( V_2 , 0x80c0 , 0x00 ) ;
}
return 0 ;
}
static int F_52 ( struct V_1 * V_2 )
{
int V_56 ;
F_43 ( & V_2 -> V_9 ) ;
F_3 ( V_2 , V_66 , V_179 ) ;
F_53 ( 5000 , 10000 ) ;
V_56 = V_2 -> V_12 -> V_180 ( V_2 ) ;
if ( V_56 )
goto V_181;
V_56 = F_22 ( V_2 ) ;
if ( V_56 )
goto V_181;
F_37 ( V_2 ) ;
if ( V_2 -> V_51 > 0 ) {
V_56 = F_3 ( V_2 , V_182 ,
V_183 |
V_184 ) ;
if ( V_56 < 0 )
goto V_181;
V_56 = F_3 ( V_2 , V_185 , 0 ) ;
if ( V_56 < 0 )
goto V_181;
V_56 = F_3 ( V_2 , V_186 , 0 ) ;
if ( V_56 < 0 )
goto V_181;
V_56 = F_3 ( V_2 , V_187 ,
V_137 ) ;
if ( V_56 < 0 )
goto V_181;
V_56 = F_3 ( V_2 , V_188 , 0 ) ;
if ( V_56 < 0 )
goto V_181;
}
V_181:
F_18 ( & V_2 -> V_9 ) ;
return V_56 ;
}
static int F_54 ( struct V_189 * V_5 ,
const struct V_190 * V_74 )
{
struct V_1 * V_2 ;
struct V_47 * V_48 ;
int V_56 ;
if ( ! F_55 ( V_5 -> V_191 , V_192 ) )
return - V_193 ;
F_56 ( V_5 , L_1 ,
V_5 -> V_194 , V_5 -> V_191 -> V_195 ) ;
V_2 = F_57 ( & V_5 -> V_196 , sizeof( * V_2 ) , V_197 ) ;
if ( V_2 == NULL )
return - V_198 ;
V_2 -> V_5 = V_5 ;
V_2 -> V_69 = V_122 ;
V_2 -> V_12 = (struct V_199 * ) V_74 -> V_200 ;
if ( V_2 -> V_12 -> V_67 & V_68 ) {
V_2 -> V_10 = F_58 ( V_5 -> V_191 ,
V_146 ) ;
if ( ! V_2 -> V_10 )
return - V_198 ;
}
if ( V_2 -> V_12 -> V_67 & V_116 ) {
V_2 -> V_14 = F_58 ( V_5 -> V_191 ,
V_148 ) ;
if ( ! V_2 -> V_14 ) {
V_56 = - V_198 ;
goto V_201;
}
}
V_2 -> V_51 = V_5 -> V_51 ;
F_59 ( & V_2 -> V_9 ) ;
V_2 -> V_50 = true ;
if ( V_2 -> V_12 -> V_67 & V_202 )
V_2 -> V_71 = true ;
else
V_2 -> V_71 = false ;
V_2 -> V_53 = 0 ;
V_48 = & V_2 -> V_48 ;
F_60 ( V_48 , V_5 , & V_203 ) ;
V_48 -> V_67 = V_204 ;
V_56 = F_28 ( V_2 ) ;
if ( V_56 )
goto V_205;
V_2 -> V_206 . V_67 = V_207 ;
V_48 -> V_208 . V_67 |= V_209 ;
V_56 = F_61 ( & V_48 -> V_208 , 1 , & V_2 -> V_206 ) ;
if ( V_56 )
goto V_210;
V_56 = F_52 ( V_2 ) ;
if ( V_56 )
goto V_211;
if ( V_2 -> V_51 ) {
V_56 = F_62 ( V_5 -> V_51 , NULL , F_42 ,
V_212 | V_213 ,
V_214 , V_2 ) ;
if ( V_56 )
goto V_211;
}
V_56 = F_63 ( V_48 ) ;
if ( V_56 )
goto V_215;
return 0 ;
V_215:
if ( V_2 -> V_51 > 0 )
F_64 ( V_5 -> V_51 , V_2 ) ;
V_211:
F_65 ( & V_48 -> V_208 ) ;
V_210:
F_34 ( V_2 ) ;
V_205:
if ( V_2 -> V_12 -> V_67 & V_116 )
F_66 ( V_2 -> V_14 ) ;
V_201:
if ( V_2 -> V_12 -> V_67 & V_68 )
F_66 ( V_2 -> V_10 ) ;
F_67 ( & V_2 -> V_9 ) ;
return V_56 ;
}
static int F_68 ( struct V_189 * V_5 )
{
struct V_47 * V_48 = F_69 ( V_5 ) ;
struct V_1 * V_2 = F_14 ( V_48 ) ;
F_70 ( V_48 ) ;
if ( V_2 -> V_51 > 0 )
F_64 ( V_5 -> V_51 , V_2 ) ;
F_65 ( & V_48 -> V_208 ) ;
F_34 ( V_2 ) ;
if ( V_2 -> V_12 -> V_67 & V_116 )
F_66 ( V_2 -> V_14 ) ;
if ( V_2 -> V_12 -> V_67 & V_68 )
F_66 ( V_2 -> V_10 ) ;
F_67 ( & V_2 -> V_9 ) ;
return 0 ;
}
static int F_71 ( struct V_216 * V_196 )
{
struct V_189 * V_5 = F_72 ( V_196 ) ;
struct V_47 * V_48 = F_69 ( V_5 ) ;
struct V_1 * V_2 = F_14 ( V_48 ) ;
return F_24 ( V_2 , false ) ;
}
static int F_73 ( struct V_216 * V_196 )
{
struct V_189 * V_5 = F_72 ( V_196 ) ;
struct V_47 * V_48 = F_69 ( V_5 ) ;
struct V_1 * V_2 = F_14 ( V_48 ) ;
int V_56 ;
V_56 = F_52 ( V_2 ) ;
if ( V_56 < 0 )
return V_56 ;
V_56 = F_24 ( V_2 , V_2 -> V_71 ) ;
if ( V_56 )
return V_56 ;
return 0 ;
}
