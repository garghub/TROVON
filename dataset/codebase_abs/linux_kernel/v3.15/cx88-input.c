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
F_5 ( V_2 -> V_27 , V_6 , 0 ) ;
} else if ( V_2 -> V_22 ) {
if ( V_5 & V_2 -> V_22 )
F_6 ( V_2 -> V_27 , V_6 , 0 ) ;
else
F_7 ( V_2 -> V_27 ) ;
} else if ( V_2 -> V_23 ) {
if ( 0 == ( V_5 & V_2 -> V_23 ) )
F_6 ( V_2 -> V_27 , V_6 , 0 ) ;
else
F_7 ( V_2 -> V_27 ) ;
} else {
F_6 ( V_2 -> V_27 , V_6 , 0 ) ;
F_7 ( V_2 -> V_27 ) ;
}
}
static enum V_28 F_8 ( struct V_29 * V_30 )
{
unsigned long V_31 ;
struct V_1 * V_2 = F_9 ( V_30 , struct V_1 , V_30 ) ;
F_1 ( V_2 ) ;
V_31 = F_10 ( & V_2 -> V_30 ,
F_11 ( 0 , V_2 -> V_19 * 1000000 ) ) ;
if ( V_31 > 1 )
F_4 ( L_7 , V_31 - 1 ) ;
return V_32 ;
}
static int F_12 ( void * V_33 )
{
struct V_3 * V_4 = V_33 ;
struct V_1 * V_2 ;
if ( ! V_4 || ! V_4 -> V_2 )
return - V_34 ;
V_2 = V_4 -> V_2 ;
if ( V_2 -> V_19 ) {
F_13 ( & V_2 -> V_30 , V_35 , V_36 ) ;
V_2 -> V_30 . V_37 = F_8 ;
F_14 ( & V_2 -> V_30 ,
F_11 ( 0 , V_2 -> V_19 * 1000000 ) ,
V_36 ) ;
}
if ( V_2 -> V_38 ) {
V_4 -> V_39 |= V_40 ;
F_15 ( V_41 , 0x33F286 * V_42 ) ;
F_15 ( V_43 , 0x5 ) ;
}
return 0 ;
}
static void F_16 ( void * V_33 )
{
struct V_3 * V_4 = V_33 ;
struct V_1 * V_2 ;
if ( ! V_4 || ! V_4 -> V_2 )
return;
V_2 = V_4 -> V_2 ;
if ( V_2 -> V_38 ) {
F_15 ( V_43 , 0x0 ) ;
V_4 -> V_39 &= ~ V_40 ;
}
if ( V_2 -> V_19 )
F_17 ( & V_2 -> V_30 ) ;
}
int F_18 ( struct V_3 * V_4 )
{
if ( V_4 -> V_2 -> V_44 )
return F_12 ( V_4 ) ;
return 0 ;
}
void F_19 ( struct V_3 * V_4 )
{
if ( V_4 -> V_2 -> V_44 )
F_16 ( V_4 ) ;
}
static int F_20 ( struct V_45 * V_46 )
{
struct V_3 * V_4 = V_46 -> V_33 ;
V_4 -> V_2 -> V_44 ++ ;
return F_12 ( V_4 ) ;
}
static void F_21 ( struct V_45 * V_46 )
{
struct V_3 * V_4 = V_46 -> V_33 ;
V_4 -> V_2 -> V_44 -- ;
if ( ! V_4 -> V_2 -> V_44 )
F_16 ( V_4 ) ;
}
int F_22 ( struct V_3 * V_4 , struct V_47 * V_48 )
{
struct V_1 * V_2 ;
struct V_45 * V_27 ;
char * V_49 = NULL ;
T_2 V_50 = V_51 ;
int V_52 = - V_53 ;
T_1 V_54 = 0 ;
V_2 = F_23 ( sizeof( * V_2 ) , V_55 ) ;
V_27 = F_24 () ;
if ( ! V_2 || ! V_27 )
goto V_56;
V_2 -> V_27 = V_27 ;
switch ( V_4 -> V_9 ) {
case V_57 :
case V_58 :
case V_59 :
V_49 = V_60 ;
V_2 -> V_8 = V_11 ;
V_2 -> V_21 = 0x1f ;
V_2 -> V_23 = 0x60 ;
V_2 -> V_19 = 50 ;
break;
case V_61 :
V_49 = V_62 ;
V_2 -> V_38 = 0xeb04 ;
break;
case V_63 :
case V_64 :
case V_65 :
case V_66 :
case V_67 :
case V_68 :
case V_69 :
case V_70 :
case V_71 :
case V_72 :
case V_73 :
V_49 = V_74 ;
V_2 -> V_38 = 1 ;
break;
case V_75 :
case V_76 :
case V_13 :
case V_14 :
case V_15 :
V_49 = V_77 ;
V_2 -> V_8 = V_26 ;
V_2 -> V_21 = 0x8f8 ;
V_2 -> V_23 = 0x100 ;
V_2 -> V_19 = 50 ;
break;
case V_78 :
case V_12 :
case V_16 :
case V_17 :
case V_18 :
V_49 = V_77 ;
V_2 -> V_8 = V_26 ;
V_2 -> V_21 = 0x8f8 ;
V_2 -> V_23 = 0x100 ;
V_2 -> V_19 = 1 ;
break;
case V_79 :
V_49 = V_80 ;
V_2 -> V_8 = V_26 ;
V_2 -> V_21 = 0xfd ;
V_2 -> V_22 = 0x02 ;
V_2 -> V_19 = 5 ;
break;
case V_81 :
case V_82 :
V_49 = V_83 ;
V_2 -> V_8 = V_11 ;
V_2 -> V_23 = 0x80 ;
V_2 -> V_19 = 10 ;
V_54 = 0x3f ;
break;
case V_84 :
case V_85 :
V_49 = V_86 ;
V_2 -> V_8 = V_11 ;
V_2 -> V_21 = 0x3f ;
V_2 -> V_23 = 0x80 ;
V_2 -> V_19 = 1 ;
break;
case V_87 :
V_49 = V_88 ;
V_2 -> V_8 = V_11 ;
V_2 -> V_21 = 0x1f ;
V_2 -> V_23 = 0x60 ;
V_2 -> V_19 = 1 ;
break;
case V_89 :
V_49 = V_90 ;
V_2 -> V_8 = V_11 ;
V_2 -> V_21 = 0xbf ;
V_2 -> V_23 = 0x40 ;
V_2 -> V_19 = 50 ;
break;
case V_91 :
V_49 = V_92 ;
V_2 -> V_8 = V_11 ;
V_2 -> V_21 = 0x1f ;
V_2 -> V_23 = 0x40 ;
V_2 -> V_19 = 1 ;
break;
case V_93 :
case V_94 :
V_49 = V_95 ;
V_2 -> V_8 = V_96 ;
V_2 -> V_21 = 0xfb ;
V_2 -> V_22 = 0x02 ;
V_2 -> V_19 = 50 ;
break;
case V_97 :
case V_98 :
case V_99 :
case V_100 :
case V_101 :
case V_102 :
case V_103 :
V_49 = V_104 ;
V_2 -> V_38 = 0xff00 ;
break;
case V_105 :
case V_106 :
case V_107 :
V_49 = V_108 ;
V_2 -> V_38 = 0xff00 ;
break;
case V_109 :
V_49 = V_110 ;
V_2 -> V_38 = 0xff00 ;
break;
case V_24 :
V_49 = V_111 ;
V_2 -> V_8 = V_11 ;
V_2 -> V_21 = 0x0e ;
V_2 -> V_23 = 0x80 ;
V_2 -> V_19 = 50 ;
break;
case V_10 :
V_49 = V_112 ;
V_2 -> V_8 = V_26 ;
V_2 -> V_21 = 0xfa ;
V_2 -> V_19 = 50 ;
break;
case V_113 :
V_49 = V_114 ;
V_2 -> V_38 = 1 ;
break;
case V_115 :
V_49 = V_116 ;
V_2 -> V_8 = V_96 ;
V_2 -> V_21 = 0x7e ;
V_2 -> V_19 = 100 ;
break;
case V_117 :
V_49 = V_118 ;
V_50 = V_119 ;
V_2 -> V_38 = 0xff00 ;
break;
}
if ( ! V_49 ) {
V_52 = - V_120 ;
goto V_56;
}
if ( V_54 && ! V_2 -> V_21 )
V_2 -> V_21 = V_54 ;
snprintf ( V_2 -> V_121 , sizeof( V_2 -> V_121 ) , L_8 , V_4 -> V_122 . V_121 ) ;
snprintf ( V_2 -> V_123 , sizeof( V_2 -> V_123 ) , L_9 , F_25 ( V_48 ) ) ;
V_27 -> V_124 = V_2 -> V_121 ;
V_27 -> V_125 = V_2 -> V_123 ;
V_27 -> V_126 . V_127 = V_128 ;
V_27 -> V_126 . V_129 = 1 ;
if ( V_48 -> V_130 ) {
V_27 -> V_126 . V_131 = V_48 -> V_130 ;
V_27 -> V_126 . V_132 = V_48 -> V_133 ;
} else {
V_27 -> V_126 . V_131 = V_48 -> V_131 ;
V_27 -> V_126 . V_132 = V_48 -> V_134 ;
}
V_27 -> V_27 . V_135 = & V_48 -> V_27 ;
V_27 -> V_136 = V_49 ;
V_27 -> V_137 = V_138 ;
V_27 -> V_33 = V_4 ;
V_27 -> V_139 = F_20 ;
V_27 -> V_140 = F_21 ;
V_27 -> V_141 = V_54 ;
if ( V_2 -> V_38 ) {
V_27 -> V_142 = V_143 ;
V_27 -> V_144 = 10 * 1000 * 1000 ;
} else {
V_27 -> V_142 = V_145 ;
F_26 ( V_27 , V_50 ) ;
}
V_2 -> V_4 = V_4 ;
V_4 -> V_2 = V_2 ;
V_52 = F_27 ( V_27 ) ;
if ( V_52 )
goto V_56;
return 0 ;
V_56:
F_28 ( V_27 ) ;
V_4 -> V_2 = NULL ;
F_29 ( V_2 ) ;
return V_52 ;
}
int F_30 ( struct V_3 * V_4 )
{
struct V_1 * V_2 = V_4 -> V_2 ;
if ( NULL == V_2 )
return 0 ;
F_19 ( V_4 ) ;
F_31 ( V_2 -> V_27 ) ;
F_29 ( V_2 ) ;
V_4 -> V_2 = NULL ;
return 0 ;
}
void F_32 ( struct V_3 * V_4 )
{
struct V_1 * V_2 = V_4 -> V_2 ;
T_1 V_146 ;
unsigned V_147 , V_148 ;
struct V_149 V_150 ;
if ( ! V_2 || ! V_2 -> V_38 )
return;
V_146 = F_2 ( V_151 ) ;
if ( V_146 == 0xff && V_2 -> V_27 -> V_152 )
return;
F_33 ( & V_150 ) ;
for ( V_147 = 32 ; V_147 > 0 ; V_147 -= V_148 ) {
V_150 . V_153 = V_146 & 0x80000000 ? false : true ;
V_148 = F_34 ( V_147 , 32U - F_35 ( V_150 . V_153 ? V_146 : ~ V_146 ) ) ;
V_150 . V_154 = ( V_148 * ( V_155 / 1000 ) ) / V_42 ;
F_36 ( V_2 -> V_27 , & V_150 ) ;
V_146 <<= V_148 ;
}
F_37 ( V_2 -> V_27 ) ;
}
static int F_38 ( struct V_156 * V_2 , T_1 * V_157 , T_1 * V_158 )
{
int V_159 , V_160 ;
V_159 = F_39 ( V_2 -> V_161 , 0x10 ) ;
if ( V_159 < 0 ) {
F_40 ( L_10 ) ;
return 0 ;
}
if ( 0 == ( V_159 & 0x80 ) )
return 0 ;
V_160 = F_39 ( V_2 -> V_161 , 0x00 ) ;
if ( V_160 < 0 ) {
F_40 ( L_10 ) ;
return 0 ;
}
F_40 ( L_11 ,
V_160 & 0xff , V_159 & 0xff ) ;
* V_157 = V_160 & 0xff ;
* V_158 = V_160 ;
return 1 ;
}
void F_41 ( struct V_3 * V_4 )
{
struct V_162 V_163 ;
const unsigned short V_164 [] = {
0x18 , 0x6b , 0x71 ,
V_165
} ;
const unsigned short V_166 [] = {
0x18 , 0x1a ,
V_165
} ;
const unsigned short * V_167 = V_164 ;
const unsigned short * V_168 ;
if ( 0 != V_4 -> V_169 )
return;
memset ( & V_163 , 0 , sizeof( struct V_162 ) ) ;
F_42 ( V_163 . type , L_12 , V_170 ) ;
switch ( V_4 -> V_9 ) {
case V_171 :
V_167 = V_166 ;
V_4 -> V_172 . V_121 = L_13 ;
V_4 -> V_172 . type = V_173 ;
V_4 -> V_172 . V_174 = F_38 ;
V_4 -> V_172 . V_49 = V_175 ;
break;
}
for ( V_168 = V_167 ; * V_168 != V_165 ; V_168 ++ ) {
V_163 . V_176 = NULL ;
memset ( & V_4 -> V_172 , 0 , sizeof( V_4 -> V_172 ) ) ;
if ( * V_168 == 0x71 ) {
V_4 -> V_172 . V_121 = L_14 ;
V_4 -> V_172 . V_49 = V_74 ;
V_4 -> V_172 . type = V_177 ;
V_4 -> V_172 . V_178 = V_179 ;
V_163 . V_176 = & V_4 -> V_172 ;
}
if ( F_43 ( & V_4 -> V_180 , * V_168 , 0 ,
V_181 , 0 ,
V_182 , NULL ) >= 0 ) {
V_163 . V_183 = * V_168 ;
F_44 ( & V_4 -> V_180 , & V_163 ) ;
break;
}
}
}
