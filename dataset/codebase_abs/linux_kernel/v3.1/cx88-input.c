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
V_5 = ( V_5 & 0x6ff ) | ( ( F_2 ( V_11 ) << 8 ) & 0x900 ) ;
V_7 = V_5 ;
break;
default:
V_7 = V_5 ;
}
if ( V_2 -> V_17 ) {
if ( V_2 -> V_18 == V_7 )
return;
V_2 -> V_18 = V_7 ;
}
V_6 = F_3 ( V_5 , V_2 -> V_19 ) ;
F_4 ( L_1 ,
V_5 , V_6 ,
V_2 -> V_17 ? L_2 : L_3 ,
( V_5 & V_2 -> V_20 ) ? L_4 : L_5 ,
( V_5 & V_2 -> V_21 ) ? L_6 : L_5 ) ;
if ( V_2 -> V_4 -> V_9 == V_22 ) {
T_1 V_23 = F_2 ( V_24 ) ;
V_6 = ( V_6 << 4 ) | ( ( V_23 & 0xf0 ) >> 4 ) ;
F_5 ( V_2 -> V_25 , V_6 , 0 ) ;
} else if ( V_2 -> V_20 ) {
if ( V_5 & V_2 -> V_20 )
F_6 ( V_2 -> V_25 , V_6 , 0 ) ;
else
F_7 ( V_2 -> V_25 ) ;
} else if ( V_2 -> V_21 ) {
if ( 0 == ( V_5 & V_2 -> V_21 ) )
F_6 ( V_2 -> V_25 , V_6 , 0 ) ;
else
F_7 ( V_2 -> V_25 ) ;
} else {
F_6 ( V_2 -> V_25 , V_6 , 0 ) ;
F_7 ( V_2 -> V_25 ) ;
}
}
static enum V_26 F_8 ( struct V_27 * V_28 )
{
unsigned long V_29 ;
struct V_1 * V_2 = F_9 ( V_28 , struct V_1 , V_28 ) ;
F_1 ( V_2 ) ;
V_29 = F_10 ( & V_2 -> V_28 ,
F_11 ( 0 , V_2 -> V_17 * 1000000 ) ) ;
if ( V_29 > 1 )
F_4 ( L_7 , V_29 - 1 ) ;
return V_30 ;
}
static int F_12 ( void * V_31 )
{
struct V_3 * V_4 = V_31 ;
struct V_1 * V_2 ;
if ( ! V_4 || ! V_4 -> V_2 )
return - V_32 ;
V_2 = V_4 -> V_2 ;
if ( V_2 -> V_17 ) {
F_13 ( & V_2 -> V_28 , V_33 , V_34 ) ;
V_2 -> V_28 . V_35 = F_8 ;
F_14 ( & V_2 -> V_28 ,
F_11 ( 0 , V_2 -> V_17 * 1000000 ) ,
V_34 ) ;
}
if ( V_2 -> V_36 ) {
V_4 -> V_37 |= V_38 ;
F_15 ( V_39 , 0x33F286 * V_40 ) ;
F_15 ( V_41 , 0x5 ) ;
}
return 0 ;
}
static void F_16 ( void * V_31 )
{
struct V_3 * V_4 = V_31 ;
struct V_1 * V_2 ;
if ( ! V_4 || ! V_4 -> V_2 )
return;
V_2 = V_4 -> V_2 ;
if ( V_2 -> V_36 ) {
F_15 ( V_41 , 0x0 ) ;
V_4 -> V_37 &= ~ V_38 ;
}
if ( V_2 -> V_17 )
F_17 ( & V_2 -> V_28 ) ;
}
int F_18 ( struct V_3 * V_4 )
{
if ( V_4 -> V_2 -> V_42 )
return F_12 ( V_4 ) ;
return 0 ;
}
void F_19 ( struct V_3 * V_4 )
{
if ( V_4 -> V_2 -> V_42 )
F_16 ( V_4 ) ;
}
static int F_20 ( struct V_43 * V_44 )
{
struct V_3 * V_4 = V_44 -> V_31 ;
V_4 -> V_2 -> V_42 ++ ;
return F_12 ( V_4 ) ;
}
static void F_21 ( struct V_43 * V_44 )
{
struct V_3 * V_4 = V_44 -> V_31 ;
V_4 -> V_2 -> V_42 -- ;
if ( ! V_4 -> V_2 -> V_42 )
F_16 ( V_4 ) ;
}
int F_22 ( struct V_3 * V_4 , struct V_45 * V_46 )
{
struct V_1 * V_2 ;
struct V_43 * V_25 ;
char * V_47 = NULL ;
T_2 V_48 = V_49 ;
int V_50 = - V_51 ;
T_1 V_52 = 0 ;
V_2 = F_23 ( sizeof( * V_2 ) , V_53 ) ;
V_25 = F_24 () ;
if ( ! V_2 || ! V_25 )
goto V_54;
V_2 -> V_25 = V_25 ;
switch ( V_4 -> V_9 ) {
case V_55 :
case V_56 :
case V_57 :
V_47 = V_58 ;
V_2 -> V_8 = V_11 ;
V_2 -> V_19 = 0x1f ;
V_2 -> V_21 = 0x60 ;
V_2 -> V_17 = 50 ;
break;
case V_59 :
V_47 = V_60 ;
V_2 -> V_36 = 0xeb04 ;
break;
case V_61 :
case V_62 :
case V_63 :
case V_64 :
case V_65 :
case V_66 :
case V_67 :
case V_68 :
case V_69 :
case V_70 :
case V_71 :
V_47 = V_72 ;
V_2 -> V_36 = 1 ;
break;
case V_73 :
case V_74 :
case V_13 :
case V_14 :
case V_15 :
V_47 = V_75 ;
V_2 -> V_8 = V_24 ;
V_2 -> V_19 = 0x8f8 ;
V_2 -> V_21 = 0x100 ;
V_2 -> V_17 = 50 ;
break;
case V_76 :
case V_12 :
case V_16 :
V_47 = V_75 ;
V_2 -> V_8 = V_24 ;
V_2 -> V_19 = 0x8f8 ;
V_2 -> V_21 = 0x100 ;
V_2 -> V_17 = 1 ;
break;
case V_77 :
V_47 = V_78 ;
V_2 -> V_8 = V_24 ;
V_2 -> V_19 = 0xfd ;
V_2 -> V_20 = 0x02 ;
V_2 -> V_17 = 5 ;
break;
case V_79 :
case V_80 :
V_47 = V_81 ;
V_2 -> V_8 = V_11 ;
V_2 -> V_21 = 0x80 ;
V_2 -> V_17 = 10 ;
V_52 = 0x3f ;
break;
case V_82 :
case V_83 :
V_47 = V_84 ;
V_2 -> V_8 = V_11 ;
V_2 -> V_19 = 0x3f ;
V_2 -> V_21 = 0x80 ;
V_2 -> V_17 = 1 ;
break;
case V_85 :
V_47 = V_86 ;
V_2 -> V_8 = V_11 ;
V_2 -> V_19 = 0x1f ;
V_2 -> V_21 = 0x60 ;
V_2 -> V_17 = 1 ;
break;
case V_87 :
V_47 = V_88 ;
V_2 -> V_8 = V_11 ;
V_2 -> V_19 = 0xbf ;
V_2 -> V_21 = 0x40 ;
V_2 -> V_17 = 50 ;
break;
case V_89 :
V_47 = V_90 ;
V_2 -> V_8 = V_11 ;
V_2 -> V_19 = 0x1f ;
V_2 -> V_21 = 0x40 ;
V_2 -> V_17 = 1 ;
break;
case V_91 :
case V_92 :
V_47 = V_93 ;
V_2 -> V_8 = V_94 ;
V_2 -> V_19 = 0xfb ;
V_2 -> V_20 = 0x02 ;
V_2 -> V_17 = 50 ;
break;
case V_95 :
case V_96 :
case V_97 :
case V_98 :
case V_99 :
case V_100 :
case V_101 :
V_47 = V_102 ;
V_2 -> V_36 = 0xff00 ;
break;
case V_103 :
case V_104 :
case V_105 :
V_47 = V_106 ;
V_2 -> V_36 = 0xff00 ;
break;
case V_107 :
V_47 = V_108 ;
V_2 -> V_36 = 0xff00 ;
break;
case V_22 :
V_47 = V_109 ;
V_2 -> V_8 = V_11 ;
V_2 -> V_19 = 0x0e ;
V_2 -> V_21 = 0x80 ;
V_2 -> V_17 = 50 ;
break;
case V_10 :
V_47 = V_110 ;
V_2 -> V_8 = V_24 ;
V_2 -> V_19 = 0xfa ;
V_2 -> V_17 = 50 ;
break;
case V_111 :
V_47 = V_112 ;
V_2 -> V_36 = 1 ;
break;
case V_113 :
V_47 = V_114 ;
V_2 -> V_8 = V_94 ;
V_2 -> V_19 = 0x7e ;
V_2 -> V_17 = 100 ;
break;
case V_115 :
V_47 = V_116 ;
V_48 = V_117 ;
V_2 -> V_36 = 0xff00 ;
break;
}
if ( ! V_47 ) {
V_50 = - V_118 ;
goto V_54;
}
if ( V_52 && ! V_2 -> V_19 )
V_2 -> V_19 = V_52 ;
snprintf ( V_2 -> V_119 , sizeof( V_2 -> V_119 ) , L_8 , V_4 -> V_120 . V_119 ) ;
snprintf ( V_2 -> V_121 , sizeof( V_2 -> V_121 ) , L_9 , F_25 ( V_46 ) ) ;
V_25 -> V_122 = V_2 -> V_119 ;
V_25 -> V_123 = V_2 -> V_121 ;
V_25 -> V_124 . V_125 = V_126 ;
V_25 -> V_124 . V_127 = 1 ;
if ( V_46 -> V_128 ) {
V_25 -> V_124 . V_129 = V_46 -> V_128 ;
V_25 -> V_124 . V_130 = V_46 -> V_131 ;
} else {
V_25 -> V_124 . V_129 = V_46 -> V_129 ;
V_25 -> V_124 . V_130 = V_46 -> V_132 ;
}
V_25 -> V_25 . V_133 = & V_46 -> V_25 ;
V_25 -> V_134 = V_47 ;
V_25 -> V_135 = V_136 ;
V_25 -> V_31 = V_4 ;
V_25 -> V_137 = F_20 ;
V_25 -> V_138 = F_21 ;
V_25 -> V_139 = V_52 ;
if ( V_2 -> V_36 ) {
V_25 -> V_140 = V_141 ;
V_25 -> V_142 = 10 * 1000 * 1000 ;
} else {
V_25 -> V_140 = V_143 ;
V_25 -> V_144 = V_48 ;
}
V_2 -> V_4 = V_4 ;
V_4 -> V_2 = V_2 ;
V_50 = F_26 ( V_25 ) ;
if ( V_50 )
goto V_54;
return 0 ;
V_54:
F_27 ( V_25 ) ;
V_4 -> V_2 = NULL ;
F_28 ( V_2 ) ;
return V_50 ;
}
int F_29 ( struct V_3 * V_4 )
{
struct V_1 * V_2 = V_4 -> V_2 ;
if ( NULL == V_2 )
return 0 ;
F_19 ( V_4 ) ;
F_30 ( V_2 -> V_25 ) ;
F_28 ( V_2 ) ;
V_4 -> V_2 = NULL ;
return 0 ;
}
void F_31 ( struct V_3 * V_4 )
{
struct V_1 * V_2 = V_4 -> V_2 ;
T_1 V_145 ;
unsigned V_146 , V_147 ;
struct V_148 V_149 ;
if ( ! V_2 || ! V_2 -> V_36 )
return;
V_145 = F_2 ( V_150 ) ;
if ( V_145 == 0xff && V_2 -> V_25 -> V_151 )
return;
F_32 ( & V_149 ) ;
for ( V_146 = 32 ; V_146 > 0 ; V_146 -= V_147 ) {
V_149 . V_152 = V_145 & 0x80000000 ? false : true ;
V_147 = F_33 ( V_146 , 32U - F_34 ( V_149 . V_152 ? V_145 : ~ V_145 ) ) ;
V_149 . V_153 = ( V_147 * ( V_154 / 1000 ) ) / V_40 ;
F_35 ( V_2 -> V_25 , & V_149 ) ;
V_145 <<= V_147 ;
}
F_36 ( V_2 -> V_25 ) ;
}
static int F_37 ( struct V_155 * V_2 , T_1 * V_156 , T_1 * V_157 )
{
int V_158 , V_159 ;
V_158 = F_38 ( V_2 -> V_160 , 0x10 ) ;
if ( V_158 < 0 ) {
F_39 ( L_10 ) ;
return 0 ;
}
if ( 0 == ( V_158 & 0x80 ) )
return 0 ;
V_159 = F_38 ( V_2 -> V_160 , 0x00 ) ;
if ( V_159 < 0 ) {
F_39 ( L_10 ) ;
return 0 ;
}
F_39 ( L_11 ,
V_159 & 0xff , V_158 & 0xff ) ;
* V_156 = V_159 & 0xff ;
* V_157 = V_159 ;
return 1 ;
}
void F_40 ( struct V_3 * V_4 )
{
struct V_161 V_162 ;
const unsigned short V_163 [] = {
0x18 , 0x6b , 0x71 ,
V_164
} ;
const unsigned short V_165 [] = {
0x18 , 0x1a ,
V_164
} ;
const unsigned short * V_166 = V_163 ;
const unsigned short * V_167 ;
if ( 0 != V_4 -> V_168 )
return;
memset ( & V_162 , 0 , sizeof( struct V_161 ) ) ;
F_41 ( V_162 . type , L_12 , V_169 ) ;
switch ( V_4 -> V_9 ) {
case V_170 :
V_166 = V_165 ;
V_4 -> V_171 . V_119 = L_13 ;
V_4 -> V_171 . type = V_172 ;
V_4 -> V_171 . V_173 = F_37 ;
V_4 -> V_171 . V_47 = V_174 ;
break;
}
for ( V_167 = V_166 ; * V_167 != V_164 ; V_167 ++ ) {
V_162 . V_175 = NULL ;
memset ( & V_4 -> V_171 , 0 , sizeof( V_4 -> V_171 ) ) ;
if ( * V_167 == 0x71 ) {
V_4 -> V_171 . V_119 = L_14 ;
V_4 -> V_171 . V_47 = V_72 ;
V_4 -> V_171 . type = V_176 ;
V_4 -> V_171 . V_177 = V_178 ;
V_162 . V_175 = & V_4 -> V_171 ;
}
if ( F_42 ( & V_4 -> V_179 , * V_167 , 0 ,
V_180 , 0 ,
V_181 , NULL ) >= 0 ) {
V_162 . V_182 = * V_167 ;
F_43 ( & V_4 -> V_179 , & V_162 ) ;
break;
}
}
}
