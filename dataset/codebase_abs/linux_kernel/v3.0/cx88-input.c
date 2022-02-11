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
V_5 = ( V_5 & 0x6ff ) | ( ( F_2 ( V_11 ) << 8 ) & 0x900 ) ;
V_7 = V_5 ;
break;
default:
V_7 = V_5 ;
}
if ( V_2 -> V_15 ) {
if ( V_2 -> V_16 == V_7 )
return;
V_2 -> V_16 = V_7 ;
}
V_6 = F_3 ( V_5 , V_2 -> V_17 ) ;
F_4 ( L_1 ,
V_5 , V_6 ,
V_2 -> V_15 ? L_2 : L_3 ,
( V_5 & V_2 -> V_18 ) ? L_4 : L_5 ,
( V_5 & V_2 -> V_19 ) ? L_6 : L_5 ) ;
if ( V_2 -> V_4 -> V_9 == V_20 ) {
T_1 V_21 = F_2 ( V_22 ) ;
V_6 = ( V_6 << 4 ) | ( ( V_21 & 0xf0 ) >> 4 ) ;
F_5 ( V_2 -> V_23 , V_6 , 0 ) ;
} else if ( V_2 -> V_18 ) {
if ( V_5 & V_2 -> V_18 )
F_6 ( V_2 -> V_23 , V_6 , 0 ) ;
else
F_7 ( V_2 -> V_23 ) ;
} else if ( V_2 -> V_19 ) {
if ( 0 == ( V_5 & V_2 -> V_19 ) )
F_6 ( V_2 -> V_23 , V_6 , 0 ) ;
else
F_7 ( V_2 -> V_23 ) ;
} else {
F_6 ( V_2 -> V_23 , V_6 , 0 ) ;
F_7 ( V_2 -> V_23 ) ;
}
}
static enum V_24 F_8 ( struct V_25 * V_26 )
{
unsigned long V_27 ;
struct V_1 * V_2 = F_9 ( V_26 , struct V_1 , V_26 ) ;
F_1 ( V_2 ) ;
V_27 = F_10 ( & V_2 -> V_26 ,
F_11 ( 0 , V_2 -> V_15 * 1000000 ) ) ;
if ( V_27 > 1 )
F_4 ( L_7 , V_27 - 1 ) ;
return V_28 ;
}
static int F_12 ( void * V_29 )
{
struct V_3 * V_4 = V_29 ;
struct V_1 * V_2 ;
if ( ! V_4 || ! V_4 -> V_2 )
return - V_30 ;
V_2 = V_4 -> V_2 ;
if ( V_2 -> V_15 ) {
F_13 ( & V_2 -> V_26 , V_31 , V_32 ) ;
V_2 -> V_26 . V_33 = F_8 ;
F_14 ( & V_2 -> V_26 ,
F_11 ( 0 , V_2 -> V_15 * 1000000 ) ,
V_32 ) ;
}
if ( V_2 -> V_34 ) {
V_4 -> V_35 |= V_36 ;
F_15 ( V_37 , 0x33F286 * V_38 ) ;
F_15 ( V_39 , 0x5 ) ;
}
return 0 ;
}
static void F_16 ( void * V_29 )
{
struct V_3 * V_4 = V_29 ;
struct V_1 * V_2 ;
if ( ! V_4 || ! V_4 -> V_2 )
return;
V_2 = V_4 -> V_2 ;
if ( V_2 -> V_34 ) {
F_15 ( V_39 , 0x0 ) ;
V_4 -> V_35 &= ~ V_36 ;
}
if ( V_2 -> V_15 )
F_17 ( & V_2 -> V_26 ) ;
}
int F_18 ( struct V_3 * V_4 )
{
if ( V_4 -> V_2 -> V_40 )
return F_12 ( V_4 ) ;
return 0 ;
}
void F_19 ( struct V_3 * V_4 )
{
if ( V_4 -> V_2 -> V_40 )
F_16 ( V_4 ) ;
}
static int F_20 ( struct V_41 * V_42 )
{
struct V_3 * V_4 = V_42 -> V_29 ;
V_4 -> V_2 -> V_40 ++ ;
return F_12 ( V_4 ) ;
}
static void F_21 ( struct V_41 * V_42 )
{
struct V_3 * V_4 = V_42 -> V_29 ;
V_4 -> V_2 -> V_40 -- ;
if ( ! V_4 -> V_2 -> V_40 )
F_16 ( V_4 ) ;
}
int F_22 ( struct V_3 * V_4 , struct V_43 * V_44 )
{
struct V_1 * V_2 ;
struct V_41 * V_23 ;
char * V_45 = NULL ;
T_2 V_46 = V_47 ;
int V_48 = - V_49 ;
T_1 V_50 = 0 ;
V_2 = F_23 ( sizeof( * V_2 ) , V_51 ) ;
V_23 = F_24 () ;
if ( ! V_2 || ! V_23 )
goto V_52;
V_2 -> V_23 = V_23 ;
switch ( V_4 -> V_9 ) {
case V_53 :
case V_54 :
case V_55 :
V_45 = V_56 ;
V_2 -> V_8 = V_11 ;
V_2 -> V_17 = 0x1f ;
V_2 -> V_19 = 0x60 ;
V_2 -> V_15 = 50 ;
break;
case V_57 :
V_45 = V_58 ;
V_2 -> V_34 = 0xeb04 ;
break;
case V_59 :
case V_60 :
case V_61 :
case V_62 :
case V_63 :
case V_64 :
case V_65 :
case V_66 :
case V_67 :
case V_68 :
case V_69 :
V_45 = V_70 ;
V_2 -> V_34 = 1 ;
break;
case V_71 :
case V_72 :
case V_13 :
V_45 = V_73 ;
V_2 -> V_8 = V_22 ;
V_2 -> V_17 = 0x8f8 ;
V_2 -> V_19 = 0x100 ;
V_2 -> V_15 = 50 ;
break;
case V_74 :
case V_12 :
case V_14 :
V_45 = V_73 ;
V_2 -> V_8 = V_22 ;
V_2 -> V_17 = 0x8f8 ;
V_2 -> V_19 = 0x100 ;
V_2 -> V_15 = 1 ;
break;
case V_75 :
V_45 = V_76 ;
V_2 -> V_8 = V_22 ;
V_2 -> V_17 = 0xfd ;
V_2 -> V_18 = 0x02 ;
V_2 -> V_15 = 5 ;
break;
case V_77 :
case V_78 :
V_45 = V_79 ;
V_2 -> V_8 = V_11 ;
V_2 -> V_19 = 0x80 ;
V_2 -> V_15 = 10 ;
V_50 = 0x3f ;
break;
case V_80 :
case V_81 :
V_45 = V_82 ;
V_2 -> V_8 = V_11 ;
V_2 -> V_17 = 0x3f ;
V_2 -> V_19 = 0x80 ;
V_2 -> V_15 = 1 ;
break;
case V_83 :
V_45 = V_84 ;
V_2 -> V_8 = V_11 ;
V_2 -> V_17 = 0x1f ;
V_2 -> V_19 = 0x60 ;
V_2 -> V_15 = 1 ;
break;
case V_85 :
V_45 = V_86 ;
V_2 -> V_8 = V_11 ;
V_2 -> V_17 = 0xbf ;
V_2 -> V_19 = 0x40 ;
V_2 -> V_15 = 50 ;
break;
case V_87 :
V_45 = V_88 ;
V_2 -> V_8 = V_11 ;
V_2 -> V_17 = 0x1f ;
V_2 -> V_19 = 0x40 ;
V_2 -> V_15 = 1 ;
break;
case V_89 :
case V_90 :
V_45 = V_91 ;
V_2 -> V_8 = V_92 ;
V_2 -> V_17 = 0xfb ;
V_2 -> V_18 = 0x02 ;
V_2 -> V_15 = 50 ;
break;
case V_93 :
case V_94 :
case V_95 :
case V_96 :
case V_97 :
case V_98 :
case V_99 :
V_45 = V_100 ;
V_2 -> V_34 = 0xff00 ;
break;
case V_101 :
case V_102 :
case V_103 :
V_45 = V_104 ;
V_2 -> V_34 = 0xff00 ;
break;
case V_105 :
V_45 = V_106 ;
V_2 -> V_34 = 0xff00 ;
break;
case V_20 :
V_45 = V_107 ;
V_2 -> V_8 = V_11 ;
V_2 -> V_17 = 0x0e ;
V_2 -> V_19 = 0x80 ;
V_2 -> V_15 = 50 ;
break;
case V_10 :
V_45 = V_108 ;
V_2 -> V_8 = V_22 ;
V_2 -> V_17 = 0xfa ;
V_2 -> V_15 = 50 ;
break;
case V_109 :
V_45 = V_110 ;
V_2 -> V_34 = 1 ;
break;
case V_111 :
V_45 = V_112 ;
V_2 -> V_8 = V_92 ;
V_2 -> V_17 = 0x7e ;
V_2 -> V_15 = 100 ;
break;
case V_113 :
V_45 = V_114 ;
V_46 = V_115 ;
V_2 -> V_34 = 0xff00 ;
break;
}
if ( ! V_45 ) {
V_48 = - V_116 ;
goto V_52;
}
if ( V_50 && ! V_2 -> V_17 )
V_2 -> V_17 = V_50 ;
snprintf ( V_2 -> V_117 , sizeof( V_2 -> V_117 ) , L_8 , V_4 -> V_118 . V_117 ) ;
snprintf ( V_2 -> V_119 , sizeof( V_2 -> V_119 ) , L_9 , F_25 ( V_44 ) ) ;
V_23 -> V_120 = V_2 -> V_117 ;
V_23 -> V_121 = V_2 -> V_119 ;
V_23 -> V_122 . V_123 = V_124 ;
V_23 -> V_122 . V_125 = 1 ;
if ( V_44 -> V_126 ) {
V_23 -> V_122 . V_127 = V_44 -> V_126 ;
V_23 -> V_122 . V_128 = V_44 -> V_129 ;
} else {
V_23 -> V_122 . V_127 = V_44 -> V_127 ;
V_23 -> V_122 . V_128 = V_44 -> V_130 ;
}
V_23 -> V_23 . V_131 = & V_44 -> V_23 ;
V_23 -> V_132 = V_45 ;
V_23 -> V_133 = V_134 ;
V_23 -> V_29 = V_4 ;
V_23 -> V_135 = F_20 ;
V_23 -> V_136 = F_21 ;
V_23 -> V_137 = V_50 ;
if ( V_2 -> V_34 ) {
V_23 -> V_138 = V_139 ;
V_23 -> V_140 = 10 * 1000 * 1000 ;
} else {
V_23 -> V_138 = V_141 ;
V_23 -> V_142 = V_46 ;
}
V_2 -> V_4 = V_4 ;
V_4 -> V_2 = V_2 ;
V_48 = F_26 ( V_23 ) ;
if ( V_48 )
goto V_52;
return 0 ;
V_52:
F_27 ( V_23 ) ;
V_4 -> V_2 = NULL ;
F_28 ( V_2 ) ;
return V_48 ;
}
int F_29 ( struct V_3 * V_4 )
{
struct V_1 * V_2 = V_4 -> V_2 ;
if ( NULL == V_2 )
return 0 ;
F_19 ( V_4 ) ;
F_30 ( V_2 -> V_23 ) ;
F_28 ( V_2 ) ;
V_4 -> V_2 = NULL ;
return 0 ;
}
void F_31 ( struct V_3 * V_4 )
{
struct V_1 * V_2 = V_4 -> V_2 ;
T_1 V_143 ;
unsigned V_144 , V_145 ;
struct V_146 V_147 ;
if ( ! V_2 || ! V_2 -> V_34 )
return;
V_143 = F_2 ( V_148 ) ;
if ( V_143 == 0xff && V_2 -> V_23 -> V_149 )
return;
F_32 ( & V_147 ) ;
for ( V_144 = 32 ; V_144 > 0 ; V_144 -= V_145 ) {
V_147 . V_150 = V_143 & 0x80000000 ? false : true ;
V_145 = F_33 ( V_144 , 32U - F_34 ( V_147 . V_150 ? V_143 : ~ V_143 ) ) ;
V_147 . V_151 = ( V_145 * ( V_152 / 1000 ) ) / V_38 ;
F_35 ( V_2 -> V_23 , & V_147 ) ;
V_143 <<= V_145 ;
}
F_36 ( V_2 -> V_23 ) ;
}
static int F_37 ( struct V_153 * V_2 , T_1 * V_154 , T_1 * V_155 )
{
int V_156 , V_157 ;
V_156 = F_38 ( V_2 -> V_158 , 0x10 ) ;
if ( V_156 < 0 ) {
F_39 ( L_10 ) ;
return 0 ;
}
if ( 0 == ( V_156 & 0x80 ) )
return 0 ;
V_157 = F_38 ( V_2 -> V_158 , 0x00 ) ;
if ( V_157 < 0 ) {
F_39 ( L_10 ) ;
return 0 ;
}
F_39 ( L_11 ,
V_157 & 0xff , V_156 & 0xff ) ;
* V_154 = V_157 & 0xff ;
* V_155 = V_157 ;
return 1 ;
}
void F_40 ( struct V_3 * V_4 )
{
struct V_159 V_160 ;
const unsigned short V_161 [] = {
0x18 , 0x6b , 0x71 ,
V_162
} ;
const unsigned short V_163 [] = {
0x18 , 0x1a ,
V_162
} ;
const unsigned short * V_164 = V_161 ;
const unsigned short * V_165 ;
if ( 0 != V_4 -> V_166 )
return;
memset ( & V_160 , 0 , sizeof( struct V_159 ) ) ;
F_41 ( V_160 . type , L_12 , V_167 ) ;
switch ( V_4 -> V_9 ) {
case V_168 :
V_164 = V_163 ;
V_4 -> V_169 . V_117 = L_13 ;
V_4 -> V_169 . type = V_170 ;
V_4 -> V_169 . V_171 = F_37 ;
V_4 -> V_169 . V_45 = V_172 ;
break;
}
for ( V_165 = V_164 ; * V_165 != V_162 ; V_165 ++ ) {
V_160 . V_173 = NULL ;
memset ( & V_4 -> V_169 , 0 , sizeof( V_4 -> V_169 ) ) ;
if ( * V_165 == 0x71 ) {
V_4 -> V_169 . V_117 = L_14 ;
V_4 -> V_169 . V_45 = V_70 ;
V_4 -> V_169 . type = V_174 ;
V_4 -> V_169 . V_175 = V_176 ;
V_160 . V_173 = & V_4 -> V_169 ;
}
if ( F_42 ( & V_4 -> V_177 , * V_165 , 0 ,
V_178 , 0 ,
V_179 , NULL ) >= 0 ) {
V_160 . V_180 = * V_165 ;
F_43 ( & V_4 -> V_177 , & V_160 ) ;
break;
}
}
}
