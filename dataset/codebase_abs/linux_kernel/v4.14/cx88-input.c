static void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
T_1 V_5 , V_6 , V_7 ;
V_5 = F_2 ( V_2 -> V_8 ) ;
switch ( V_4 -> V_9 ) {
case V_10 :
V_7 = F_2 ( V_11 ) ;
V_5 = ( V_5 & 0x7fd ) + ( V_7 & 0xef ) ;
break;
case V_12 :
case V_13 :
case V_14 :
case V_15 :
case V_16 :
case V_17 :
case V_18 :
V_5 = ( V_5 & 0x6ff ) | ( ( F_2 ( V_11 ) << 8 ) & 0x900 ) ;
V_7 = V_5 ;
break;
default:
V_7 = V_5 ;
}
if ( V_2 -> V_19 ) {
if ( V_2 -> V_20 == V_7 )
return;
V_2 -> V_20 = V_7 ;
}
V_6 = F_3 ( V_5 , V_2 -> V_21 ) ;
F_4 ( L_1 ,
V_5 , V_6 ,
V_2 -> V_19 ? L_2 : L_3 ,
( V_5 & V_2 -> V_22 ) ? L_4 : L_5 ,
( V_5 & V_2 -> V_23 ) ? L_6 : L_5 ) ;
if ( V_2 -> V_4 -> V_9 == V_24 ) {
T_1 V_25 = F_2 ( V_26 ) ;
V_6 = ( V_6 << 4 ) | ( ( V_25 & 0xf0 ) >> 4 ) ;
F_5 ( V_2 -> V_27 , V_28 , V_6 , 0 ) ;
} else if ( V_2 -> V_4 -> V_9 == V_29 ||
V_2 -> V_4 -> V_9 == V_30 ) {
T_2 V_31 ;
T_3 V_32 ;
T_1 V_33 ;
V_31 = ( V_6 >> 8 ) & 0xffff ;
V_32 = ( V_6 >> 0 ) & 0x00ff ;
V_33 = F_6 ( V_31 , V_32 ) ;
if ( 0 == ( V_5 & V_2 -> V_23 ) )
F_7 ( V_2 -> V_27 , V_34 , V_33 ,
0 ) ;
else
F_8 ( V_2 -> V_27 ) ;
} else if ( V_2 -> V_22 ) {
if ( V_5 & V_2 -> V_22 )
F_7 ( V_2 -> V_27 , V_28 , V_6 ,
0 ) ;
else
F_8 ( V_2 -> V_27 ) ;
} else if ( V_2 -> V_23 ) {
if ( 0 == ( V_5 & V_2 -> V_23 ) )
F_7 ( V_2 -> V_27 , V_28 , V_6 ,
0 ) ;
else
F_8 ( V_2 -> V_27 ) ;
} else {
F_7 ( V_2 -> V_27 , V_28 , V_6 , 0 ) ;
F_8 ( V_2 -> V_27 ) ;
}
}
static enum V_35 F_9 ( struct V_36 * V_37 )
{
unsigned long V_38 ;
struct V_1 * V_2 = F_10 ( V_37 , struct V_1 , V_37 ) ;
F_1 ( V_2 ) ;
V_38 = F_11 ( & V_2 -> V_37 , V_2 -> V_19 * 1000000 ) ;
if ( V_38 > 1 )
F_4 ( L_7 , V_38 - 1 ) ;
return V_39 ;
}
static int F_12 ( void * V_40 )
{
struct V_3 * V_4 = V_40 ;
struct V_1 * V_2 ;
if ( ! V_4 || ! V_4 -> V_2 )
return - V_41 ;
V_2 = V_4 -> V_2 ;
if ( V_2 -> V_19 ) {
F_13 ( & V_2 -> V_37 , V_42 , V_43 ) ;
V_2 -> V_37 . V_44 = F_9 ;
F_14 ( & V_2 -> V_37 , V_2 -> V_19 * 1000000 ,
V_43 ) ;
}
if ( V_2 -> V_45 ) {
V_4 -> V_46 |= V_47 ;
F_15 ( V_48 , 0x33F286 * V_49 ) ;
F_15 ( V_50 , 0x5 ) ;
}
return 0 ;
}
static void F_16 ( void * V_40 )
{
struct V_3 * V_4 = V_40 ;
struct V_1 * V_2 ;
if ( ! V_4 || ! V_4 -> V_2 )
return;
V_2 = V_4 -> V_2 ;
if ( V_2 -> V_45 ) {
F_15 ( V_50 , 0x0 ) ;
V_4 -> V_46 &= ~ V_47 ;
}
if ( V_2 -> V_19 )
F_17 ( & V_2 -> V_37 ) ;
}
int F_18 ( struct V_3 * V_4 )
{
if ( V_4 -> V_2 -> V_51 )
return F_12 ( V_4 ) ;
return 0 ;
}
void F_19 ( struct V_3 * V_4 )
{
if ( V_4 -> V_2 -> V_51 )
F_16 ( V_4 ) ;
}
static int F_20 ( struct V_52 * V_53 )
{
struct V_3 * V_4 = V_53 -> V_40 ;
V_4 -> V_2 -> V_51 ++ ;
return F_12 ( V_4 ) ;
}
static void F_21 ( struct V_52 * V_53 )
{
struct V_3 * V_4 = V_53 -> V_40 ;
V_4 -> V_2 -> V_51 -- ;
if ( ! V_4 -> V_2 -> V_51 )
F_16 ( V_4 ) ;
}
int F_22 ( struct V_3 * V_4 , struct V_54 * V_55 )
{
struct V_1 * V_2 ;
struct V_52 * V_27 ;
char * V_56 = NULL ;
T_4 V_57 = V_58 ;
int V_59 = - V_60 ;
T_1 V_61 = 0 ;
V_2 = F_23 ( sizeof( * V_2 ) , V_62 ) ;
V_27 = F_24 ( V_63 ) ;
if ( ! V_2 || ! V_27 )
goto V_64;
V_2 -> V_27 = V_27 ;
switch ( V_4 -> V_9 ) {
case V_65 :
case V_66 :
case V_67 :
V_56 = V_68 ;
V_2 -> V_8 = V_11 ;
V_2 -> V_21 = 0x1f ;
V_2 -> V_23 = 0x60 ;
V_2 -> V_19 = 50 ;
break;
case V_69 :
V_56 = V_70 ;
V_2 -> V_45 = 0xeb04 ;
break;
case V_71 :
case V_72 :
case V_73 :
case V_74 :
case V_75 :
case V_76 :
case V_77 :
case V_78 :
case V_79 :
case V_80 :
case V_81 :
V_56 = V_82 ;
V_2 -> V_45 = 1 ;
break;
case V_83 :
case V_84 :
case V_13 :
case V_14 :
case V_15 :
V_56 = V_85 ;
V_2 -> V_8 = V_26 ;
V_2 -> V_21 = 0x8f8 ;
V_2 -> V_23 = 0x100 ;
V_2 -> V_19 = 50 ;
break;
case V_86 :
case V_12 :
case V_16 :
case V_17 :
case V_18 :
V_56 = V_85 ;
V_2 -> V_8 = V_26 ;
V_2 -> V_21 = 0x8f8 ;
V_2 -> V_23 = 0x100 ;
V_2 -> V_19 = 1 ;
break;
case V_87 :
V_56 = V_88 ;
V_2 -> V_8 = V_26 ;
V_2 -> V_21 = 0xfd ;
V_2 -> V_22 = 0x02 ;
V_2 -> V_19 = 5 ;
break;
case V_29 :
case V_30 :
V_56 = V_89 ;
V_57 = V_90 ;
V_2 -> V_8 = V_11 ;
V_2 -> V_23 = 0x80 ;
V_2 -> V_19 = 10 ;
V_61 = 0x3f ;
break;
case V_91 :
case V_92 :
V_56 = V_93 ;
V_2 -> V_8 = V_11 ;
V_2 -> V_21 = 0x3f ;
V_2 -> V_23 = 0x80 ;
V_2 -> V_19 = 1 ;
break;
case V_94 :
V_56 = V_95 ;
V_2 -> V_8 = V_11 ;
V_2 -> V_21 = 0x1f ;
V_2 -> V_23 = 0x60 ;
V_2 -> V_19 = 1 ;
break;
case V_96 :
V_56 = V_97 ;
V_2 -> V_8 = V_11 ;
V_2 -> V_21 = 0xbf ;
V_2 -> V_23 = 0x40 ;
V_2 -> V_19 = 50 ;
break;
case V_98 :
V_56 = V_99 ;
V_2 -> V_8 = V_11 ;
V_2 -> V_21 = 0x1f ;
V_2 -> V_23 = 0x40 ;
V_2 -> V_19 = 1 ;
break;
case V_100 :
case V_101 :
V_56 = V_102 ;
V_2 -> V_8 = V_103 ;
V_2 -> V_21 = 0xfb ;
V_2 -> V_22 = 0x02 ;
V_2 -> V_19 = 50 ;
break;
case V_104 :
case V_105 :
case V_106 :
case V_107 :
case V_108 :
case V_109 :
case V_110 :
V_56 = V_111 ;
V_2 -> V_45 = 0xff00 ;
break;
case V_112 :
case V_113 :
case V_114 :
V_56 = V_115 ;
V_2 -> V_45 = 0xff00 ;
break;
case V_116 :
V_56 = V_117 ;
V_2 -> V_45 = 0xff00 ;
break;
case V_24 :
V_56 = V_118 ;
V_2 -> V_8 = V_11 ;
V_2 -> V_21 = 0x0e ;
V_2 -> V_23 = 0x80 ;
V_2 -> V_19 = 50 ;
break;
case V_10 :
V_56 = V_119 ;
V_2 -> V_8 = V_26 ;
V_2 -> V_21 = 0xfa ;
V_2 -> V_19 = 50 ;
break;
case V_120 :
V_56 = V_121 ;
V_2 -> V_45 = 1 ;
break;
case V_122 :
V_56 = V_123 ;
V_2 -> V_8 = V_103 ;
V_2 -> V_21 = 0x7e ;
V_2 -> V_19 = 100 ;
break;
case V_124 :
V_56 = V_125 ;
V_2 -> V_45 = 0xff00 ;
break;
}
if ( ! V_56 ) {
V_59 = - V_126 ;
goto V_64;
}
if ( V_61 && ! V_2 -> V_21 )
V_2 -> V_21 = V_61 ;
snprintf ( V_2 -> V_127 , sizeof( V_2 -> V_127 ) , L_8 , V_4 -> V_128 . V_127 ) ;
snprintf ( V_2 -> V_129 , sizeof( V_2 -> V_129 ) , L_9 , F_25 ( V_55 ) ) ;
V_27 -> V_130 = V_2 -> V_127 ;
V_27 -> V_131 = V_2 -> V_129 ;
V_27 -> V_132 . V_133 = V_134 ;
V_27 -> V_132 . V_135 = 1 ;
if ( V_55 -> V_136 ) {
V_27 -> V_132 . V_137 = V_55 -> V_136 ;
V_27 -> V_132 . V_138 = V_55 -> V_139 ;
} else {
V_27 -> V_132 . V_137 = V_55 -> V_137 ;
V_27 -> V_132 . V_138 = V_55 -> V_140 ;
}
V_27 -> V_27 . V_141 = & V_55 -> V_27 ;
V_27 -> V_142 = V_56 ;
V_27 -> V_143 = V_144 ;
V_27 -> V_40 = V_4 ;
V_27 -> V_145 = F_20 ;
V_27 -> V_146 = F_21 ;
V_27 -> V_147 = V_61 ;
if ( V_2 -> V_45 ) {
V_27 -> V_148 = 10 * 1000 * 1000 ;
} else {
V_27 -> V_149 = V_150 ;
V_27 -> V_151 = V_57 ;
}
V_2 -> V_4 = V_4 ;
V_4 -> V_2 = V_2 ;
V_59 = F_26 ( V_27 ) ;
if ( V_59 )
goto V_64;
return 0 ;
V_64:
F_27 ( V_27 ) ;
V_4 -> V_2 = NULL ;
F_28 ( V_2 ) ;
return V_59 ;
}
int F_29 ( struct V_3 * V_4 )
{
struct V_1 * V_2 = V_4 -> V_2 ;
if ( ! V_2 )
return 0 ;
F_19 ( V_4 ) ;
F_30 ( V_2 -> V_27 ) ;
F_28 ( V_2 ) ;
V_4 -> V_2 = NULL ;
return 0 ;
}
void F_31 ( struct V_3 * V_4 )
{
struct V_1 * V_2 = V_4 -> V_2 ;
T_1 V_152 ;
unsigned int V_153 , V_154 ;
struct V_155 V_156 ;
if ( ! V_2 || ! V_2 -> V_45 )
return;
V_152 = F_2 ( V_157 ) ;
if ( V_152 == 0xff && V_2 -> V_27 -> V_158 )
return;
F_32 ( & V_156 ) ;
for ( V_153 = 32 ; V_153 > 0 ; V_153 -= V_154 ) {
V_156 . V_159 = V_152 & 0x80000000 ? false : true ;
V_154 = F_33 ( V_153 , 32U - F_34 ( V_156 . V_159 ? V_152 : ~ V_152 ) ) ;
V_156 . V_160 = ( V_154 * ( V_161 / 1000 ) ) / V_49 ;
F_35 ( V_2 -> V_27 , & V_156 ) ;
V_152 <<= V_154 ;
}
F_36 ( V_2 -> V_27 ) ;
}
static int F_37 ( struct V_162 * V_2 , enum V_57 * V_163 ,
T_1 * V_33 , T_3 * V_164 )
{
int V_165 , V_166 ;
V_165 = F_38 ( V_2 -> V_167 , 0x10 ) ;
if ( V_165 < 0 ) {
F_39 ( L_10 ) ;
return 0 ;
}
if ( 0 == ( V_165 & 0x80 ) )
return 0 ;
V_166 = F_38 ( V_2 -> V_167 , 0x00 ) ;
if ( V_166 < 0 ) {
F_39 ( L_10 ) ;
return 0 ;
}
F_39 ( L_11 ,
V_166 & 0xff , V_165 & 0xff ) ;
* V_163 = V_28 ;
* V_33 = V_166 & 0xff ;
* V_164 = 0 ;
return 1 ;
}
void F_40 ( struct V_3 * V_4 )
{
struct V_168 V_169 ;
const unsigned short V_170 [] = {
0x18 , 0x6b , 0x71 ,
V_171
} ;
const unsigned short V_172 [] = {
0x18 , 0x1a ,
V_171
} ;
const unsigned short * V_173 = V_170 ;
const unsigned short * V_174 ;
if ( V_4 -> V_175 != 0 )
return;
memset ( & V_169 , 0 , sizeof( struct V_168 ) ) ;
F_41 ( V_169 . type , L_12 , V_176 ) ;
switch ( V_4 -> V_9 ) {
case V_177 :
V_173 = V_172 ;
V_4 -> V_178 . V_127 = L_13 ;
V_4 -> V_178 . type = V_179 ;
V_4 -> V_178 . V_180 = F_37 ;
V_4 -> V_178 . V_56 = V_181 ;
break;
}
for ( V_174 = V_173 ; * V_174 != V_171 ; V_174 ++ ) {
V_169 . V_182 = NULL ;
memset ( & V_4 -> V_178 , 0 , sizeof( V_4 -> V_178 ) ) ;
if ( * V_174 == 0x71 ) {
V_4 -> V_178 . V_127 = L_14 ;
V_4 -> V_178 . V_56 = V_82 ;
V_4 -> V_178 . type = V_183 |
V_184 | V_185 ;
V_4 -> V_178 . V_186 = V_187 ;
V_169 . V_182 = & V_4 -> V_178 ;
}
if ( F_42 ( & V_4 -> V_188 , * V_174 , 0 ,
V_189 , 0 ,
V_190 , NULL ) >= 0 ) {
V_169 . V_31 = * V_174 ;
F_43 ( & V_4 -> V_188 , & V_169 ) ;
break;
}
}
}
