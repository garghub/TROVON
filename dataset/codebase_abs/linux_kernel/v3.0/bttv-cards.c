void T_1 F_1 ( struct V_1 * V_2 )
{
unsigned int V_3 ;
int V_4 , type ;
unsigned short V_5 ;
F_2 ( V_2 -> V_6 . V_7 , V_8 , & V_5 ) ;
V_2 -> V_9 = V_5 << 16 ;
F_2 ( V_2 -> V_6 . V_7 , V_10 , & V_5 ) ;
V_2 -> V_9 |= V_5 ;
if ( 0 != V_2 -> V_9 && 0xffffffff != V_2 -> V_9 ) {
for ( type = - 1 , V_4 = 0 ; V_11 [ V_4 ] . V_12 != 0 ; V_4 ++ )
if ( V_11 [ V_4 ] . V_12 == V_2 -> V_9 )
type = V_4 ;
if ( type != - 1 ) {
F_3 ( V_13 L_1
L_2 ,
V_2 -> V_6 . V_14 , V_11 [ type ] . V_15 , V_11 [ type ] . V_16 ,
V_2 -> V_9 & 0xffff ,
( V_2 -> V_9 >> 16 ) & 0xffff ) ;
V_2 -> V_6 . type = V_11 [ type ] . V_16 ;
} else {
F_3 ( V_13 L_3 ,
V_2 -> V_6 . V_14 , V_2 -> V_9 & 0xffff ,
( V_2 -> V_9 >> 16 ) & 0xffff ) ;
F_3 ( V_17 L_4
L_5 ) ;
}
}
if ( V_18 [ V_2 -> V_6 . V_14 ] < V_19 )
V_2 -> V_6 . type = V_18 [ V_2 -> V_6 . V_14 ] ;
F_3 ( V_13 L_6 , V_2 -> V_6 . V_14 ,
V_20 [ V_2 -> V_6 . type ] . V_15 , V_2 -> V_6 . type ,
V_18 [ V_2 -> V_6 . V_14 ] < V_19
? L_7 : L_8 ) ;
if ( V_21 == V_22 && V_21 == V_23 [ 0 ] )
return;
if ( V_21 != V_23 [ 0 ] ) {
V_3 = 0 ;
for ( V_4 = 0 ; V_4 < F_4 ( V_20 -> V_24 ) ; V_4 ++ ) {
V_20 [ V_2 -> V_6 . type ] . V_24 [ V_4 ] = V_23 [ V_4 ] ;
V_3 |= V_23 [ V_4 ] ;
}
} else {
V_3 = V_22 ;
for ( V_4 = 0 ; V_4 < F_4 ( V_20 -> V_24 ) ; V_4 ++ ) {
V_20 [ V_2 -> V_6 . type ] . V_24 [ V_4 ] = V_22 ;
}
}
V_20 [ V_2 -> V_6 . type ] . V_25 = ( V_21 != V_25 ) ? V_25 : V_3 ;
F_3 ( V_13 L_9 ,
V_2 -> V_6 . V_14 , V_20 [ V_2 -> V_6 . type ] . V_25 ) ;
for ( V_4 = 0 ; V_4 < F_4 ( V_20 -> V_24 ) ; V_4 ++ ) {
F_3 ( L_10 , V_4 ? L_11 : L_12 , V_20 [ V_2 -> V_6 . type ] . V_24 [ V_4 ] ) ;
}
F_3 ( L_13 ) ;
}
static void F_5 ( struct V_1 * V_2 , unsigned char V_26 [ 256 ] )
{
int type = - 1 ;
if ( 0 == strncmp ( V_26 , L_14 , 13 ) )
type = V_27 ;
else if ( 0 == strncmp ( V_26 + 20 , L_15 , 7 ) )
type = V_28 ;
else if ( V_26 [ 0 ] == 0x84 && V_26 [ 2 ] == 0 )
type = V_29 ;
if ( - 1 != type ) {
V_2 -> V_6 . type = type ;
F_3 ( L_16 ,
V_2 -> V_6 . V_14 , V_20 [ V_2 -> V_6 . type ] . V_15 , V_2 -> V_6 . type ) ;
}
}
static void F_6 ( struct V_1 * V_2 )
{
int V_30 , V_31 , V_32 , V_33 ;
int V_34 , V_35 ;
int V_36 = V_21 , V_37 ;
F_7 ( 0xffffff , 0 ) ;
F_8 ( 8 ) ;
V_30 = F_9 () ;
V_37 = ( V_30 & 0x0f0000 ) >> 16 ;
switch ( V_37 ) {
case 0x0 :
V_36 = 2 ;
break;
case 0x2 :
V_36 = 39 ;
break;
case 0x4 :
V_36 = 5 ;
break;
case 0x6 :
V_36 = 37 ;
break;
case 0xC :
V_36 = 3 ;
break;
default:
F_3 ( V_13 L_17 , V_2 -> V_6 . V_14 ) ;
break;
}
V_31 = V_30 & 0x800000 ;
V_32 = V_30 & 0x400000 ;
V_33 = ! ( V_30 & 0x008000 ) ;
V_35 = ! ( V_30 & 0x004000 ) ;
V_34 = ! ( V_30 & 0x002000 ) ;
if ( V_33 )
V_36 = V_38 ;
F_3 ( V_13 L_18 ,
V_2 -> V_6 . V_14 , V_32 ? L_19 : L_20 ,
V_31 ? L_19 : L_20 , V_36 , V_30 ) ;
F_3 ( V_13 L_21 ,
V_2 -> V_6 . V_14 , V_34 ? L_19 : L_20 ,
V_35 ? L_19 : L_20 ,
V_33 ? L_19 : L_20 ) ;
if ( V_36 != V_21 )
V_2 -> V_36 = V_36 ;
V_2 -> V_32 = V_32 ;
if ( V_35 )
V_2 -> V_39 = V_40 ;
}
static void F_10 ( struct V_1 * V_2 )
{
int V_12 , V_41 , V_30 ;
char * V_42 ;
F_7 ( 0xffffff , 0 ) ;
V_30 = F_9 () ;
V_12 = ( ( V_30 >> 10 ) & 63 ) - 1 ;
V_41 = F_11 ( V_2 , V_43 , L_22 ) ;
if ( V_12 < 32 ) {
V_2 -> V_36 = V_44 [ V_12 ] ;
if ( 0 == ( V_30 & 0x20 ) ) {
V_2 -> V_32 = 1 ;
if ( ! V_45 [ V_12 ] ) {
V_2 -> V_46 = 1 ;
V_2 -> V_47 = ( 1 << 6 ) ;
V_2 -> V_48 = ( 1 << 7 ) ;
V_2 -> V_49 = ( 1 << 8 ) ;
V_2 -> V_50 = ( 1 << 9 ) ;
V_2 -> V_51 = ( 1 << 6 ) | ( 1 << 7 ) | ( 1 << 8 ) | ( 1 << 9 ) ;
}
} else {
V_2 -> V_32 = 0 ;
}
if ( - 1 != V_41 ) {
if ( V_2 -> V_6 . type == V_52 )
V_2 -> V_6 . type = V_53 ;
if ( V_2 -> V_6 . type == V_54 )
V_2 -> V_6 . type = V_55 ;
}
F_3 ( V_13
L_23 ,
V_2 -> V_6 . V_14 , V_12 + 1 , V_2 -> V_36 ,
! V_2 -> V_32 ? L_24 :
( V_2 -> V_46 ? L_25 : L_26 ) ,
( - 1 == V_41 ) ? L_24 : L_19 ) ;
} else {
V_12 = 63 - V_12 ;
V_2 -> V_32 = 0 ;
switch ( V_12 ) {
case 1 :
V_42 = L_27 ;
V_2 -> V_56 = V_57 ;
break;
case 2 :
V_42 = L_28 ;
V_2 -> V_32 = 1 ;
V_2 -> V_56 = V_58 ;
break;
case 3 :
V_42 = L_29 ;
V_2 -> V_32 = 1 ;
V_2 -> V_56 = V_58 ;
break;
case 4 :
V_42 = L_30 ;
V_2 -> V_56 = V_58 ;
break;
case 5 :
V_42 = L_31 ;
V_2 -> V_56 = V_57 ;
break;
case 6 :
V_42 = L_29 ;
V_2 -> V_56 = V_57 ;
break;
case 7 :
V_42 = L_32 ;
V_2 -> V_56 = V_57 ;
break;
default:
V_42 = L_33 ;
break;
}
if ( - 1 != V_41 )
V_2 -> V_6 . type = V_55 ;
F_3 ( V_13
L_34 ,
V_2 -> V_6 . V_14 , V_12 , V_42 , V_2 -> V_32 ? L_19 : L_24 ) ;
V_2 -> V_36 = V_59 ;
}
}
static void F_12 ( struct V_1 * V_2 )
{
F_7 ( 0xffffff , 0xFFFF37 ) ;
F_13 ( 0x200020 ) ;
F_13 ( 0x200024 ) ;
F_14 ( V_60 , V_60 ) ;
F_15 ( ( 2 ) << 5 , ~ ( 2 << 5 ) , V_61 ) ;
}
static void F_16 ( struct V_1 * V_2 , unsigned int V_62 )
{
F_14 ( 3 , V_62 & 3 ) ;
F_17 ( V_63 , V_64 ) ;
F_18 ( ~ V_65 , V_66 ) ;
F_18 ( ~ V_65 , V_67 ) ;
F_14 ( V_60 , V_60 ) ;
}
static void F_19 ( struct V_1 * V_2 , unsigned int V_62 )
{
static const int V_68 [] = { 0x30 , 0x01 , 0x12 , 0x23 } ;
F_13 ( V_68 [ V_62 % 4 ] ) ;
}
static void F_20 ( struct V_1 * V_2 )
{
F_3 ( V_17 L_35 ) ;
F_21 ( 0x000000 , V_69 ) ;
F_7 ( 0xffffff , 0x0006C0 ) ;
F_13 ( 0x000000 ) ;
}
static void F_22 ( struct V_1 * V_2 , unsigned int V_62 )
{
unsigned int V_70 = V_62 % 8 ;
F_7 ( 0xf , 0xf ) ;
F_14 ( 0xf , V_70 ) ;
}
static void F_23 ( struct V_1 * V_2 , unsigned int V_62 )
{
unsigned int V_70 = V_62 % 4 ;
F_7 ( 3 << 9 , 3 << 9 ) ;
F_14 ( 3 << 9 , V_70 << 9 ) ;
}
static void F_24 ( struct V_1 * V_2 , unsigned int V_62 )
{
unsigned int V_70 = V_62 % 16 ;
F_7 ( 0xf , 0xf ) ;
F_14 ( 0xf , V_70 ) ;
}
static void F_25 ( struct V_1 * V_2 )
{
if ( V_2 -> V_12 != 878 )
return;
if ( V_71 )
F_3 ( L_36 , V_2 -> V_6 . V_14 ) ;
F_21 ( ( 1 << 7 ) , 0x058 ) ;
F_8 ( 10 ) ;
F_21 ( 0 , 0x058 ) ;
}
void T_1 F_26 ( struct V_1 * V_2 )
{
switch ( V_2 -> V_6 . type ) {
case V_29 :
case V_72 :
F_27 ( V_2 , 5 ) ;
break;
case V_73 :
case V_74 :
F_27 ( V_2 , 20 ) ;
break;
case V_75 :
F_27 ( V_2 , 11 ) ;
break;
case V_76 :
F_28 ( V_2 ) ;
break;
case V_77 :
case V_78 :
case V_79 :
V_2 -> V_80 = 1 ;
break;
case V_81 :
F_29 ( V_2 ) ;
break;
}
if ( ! V_20 [ V_2 -> V_6 . type ] . V_82 )
F_25 ( V_2 ) ;
}
void T_1 F_30 ( struct V_1 * V_2 )
{
V_2 -> V_36 = V_21 ;
if ( V_83 == V_2 -> V_6 . type ) {
F_31 ( V_2 , V_26 , 0xa0 ) ;
F_5 ( V_2 , V_26 ) ;
}
switch ( V_2 -> V_6 . type ) {
case V_52 :
case V_53 :
case V_54 :
case V_55 :
F_10 ( V_2 ) ;
break;
case V_84 :
case V_85 :
case V_86 :
case V_87 :
case V_88 :
case V_89 :
case V_90 :
case V_91 :
case V_92 :
case V_93 :
case V_94 :
F_6 ( V_2 ) ;
break;
case V_29 :
case V_72 :
case V_76 :
F_31 ( V_2 , V_26 , 0xa0 ) ;
F_32 ( V_2 ) ;
break;
case V_75 :
case V_95 :
F_31 ( V_2 , V_26 , 0xa0 ) ;
F_33 ( V_2 ) ;
break;
case V_96 :
F_34 ( V_2 ) ;
break;
case V_97 :
F_35 ( V_2 ) ;
break;
case V_98 :
V_2 -> V_32 = 1 ;
V_2 -> V_46 = 1 ;
V_2 -> V_47 = 0x20 ;
V_2 -> V_48 = 0 ;
V_2 -> V_49 = 0x08 ;
V_2 -> V_50 = 0x10 ;
V_2 -> V_51 = 0x38 ;
break;
case V_99 :
case V_100 :
F_36 ( V_2 ) ;
break;
case V_101 :
if ( V_2 -> V_9 == 0x3002144f ) {
V_2 -> V_32 = 1 ;
F_3 ( L_37 , V_2 -> V_6 . V_14 ) ;
}
break;
case V_102 :
if ( V_2 -> V_9 == 0x3060121a ) {
V_2 -> V_32 = 0 ;
V_2 -> V_36 = V_103 ;
}
break;
case V_104 :
case V_105 :
case V_106 :
case V_107 :
case V_108 :
case V_109 :
case V_110 :
case V_111 :
case V_112 :
case V_113 :
case V_114 :
case V_115 :
F_31 ( V_2 , V_26 , 0xa0 ) ;
F_37 ( V_2 , V_26 ) ;
break;
case V_116 :
F_12 ( V_2 ) ;
break;
case V_27 :
F_31 ( V_2 , V_26 , 0xa0 ) ;
F_38 ( V_2 ) ;
break;
case V_117 :
F_20 ( V_2 ) ;
break;
case V_118 :
F_39 ( V_2 ) ;
break;
case V_119 :
F_40 ( V_2 ) ;
break;
case V_120 :
F_41 ( V_2 ) ;
break;
}
if ( ! ( V_2 -> V_12 == 848 && V_2 -> V_121 == 0x11 ) ) {
if ( V_122 == V_20 [ V_2 -> V_6 . type ] . V_123 ) {
V_2 -> V_123 . V_124 = 28636363 ;
V_2 -> V_123 . V_125 = V_126 ;
}
if ( V_127 == V_20 [ V_2 -> V_6 . type ] . V_123 ) {
V_2 -> V_123 . V_124 = 35468950 ;
V_2 -> V_123 . V_125 = V_128 ;
}
switch ( V_123 [ V_2 -> V_6 . V_14 ] ) {
case 0 :
V_2 -> V_123 . V_125 = 0 ;
V_2 -> V_123 . V_124 = 0 ;
V_2 -> V_123 . V_129 = 0 ;
break;
case 1 :
case 28 :
V_2 -> V_123 . V_124 = 28636363 ;
V_2 -> V_123 . V_129 = 0 ;
V_2 -> V_123 . V_125 = V_126 ;
break;
case 2 :
case 35 :
V_2 -> V_123 . V_124 = 35468950 ;
V_2 -> V_123 . V_129 = 0 ;
V_2 -> V_123 . V_125 = V_128 ;
break;
}
}
V_2 -> V_123 . V_130 = - 1 ;
if ( V_21 != V_20 [ V_2 -> V_6 . type ] . V_36 )
if ( V_21 == V_2 -> V_36 )
V_2 -> V_36 = V_20 [ V_2 -> V_6 . type ] . V_36 ;
if ( V_21 != V_131 [ V_2 -> V_6 . V_14 ] )
V_2 -> V_36 = V_131 [ V_2 -> V_6 . V_14 ] ;
if ( V_2 -> V_36 == V_38 )
F_3 ( V_13 L_38 , V_2 -> V_6 . V_14 ) ;
else if( V_2 -> V_36 == V_21 )
F_3 ( V_132 L_39 , V_2 -> V_6 . V_14 ) ;
else
F_3 ( V_13 L_40 , V_2 -> V_6 . V_14 ,
V_2 -> V_36 ) ;
if ( V_133 != V_21 ) {
F_3 ( V_132 L_41 , V_2 -> V_6 . V_14 ) ;
F_3 ( V_132 L_42 , V_2 -> V_6 . V_14 ) ;
F_3 ( V_132 L_43 , V_2 -> V_6 . V_14 ) ;
}
if ( V_21 == V_2 -> V_36 )
V_2 -> V_36 = V_38 ;
V_2 -> V_134 = V_20 [ V_2 -> V_6 . type ] . V_135 ?
V_20 [ V_2 -> V_6 . type ] . V_136 - 1 : V_21 ;
V_2 -> V_137 = V_20 [ V_2 -> V_6 . type ] . V_137 == V_138 ?
V_21 : V_20 [ V_2 -> V_6 . type ] . V_137 ;
if ( V_137 [ V_2 -> V_6 . V_14 ] != V_21 )
V_2 -> V_137 = V_137 [ V_2 -> V_6 . V_14 ] ;
if ( V_139 [ V_2 -> V_6 . V_14 ] != V_21 )
V_2 -> V_31 = V_139 [ V_2 -> V_6 . V_14 ] ;
if ( V_20 [ V_2 -> V_6 . type ] . V_32 )
V_2 -> V_32 = 1 ;
if ( V_20 [ V_2 -> V_6 . type ] . V_31 )
V_2 -> V_31 = 1 ;
if ( ! V_20 [ V_2 -> V_6 . type ] . V_140 )
V_2 -> V_141 = 1 ;
if ( V_20 [ V_2 -> V_6 . type ] . V_142 )
V_2 -> V_142 = V_20 [ V_2 -> V_6 . type ] . V_142 ;
if ( V_20 [ V_2 -> V_6 . type ] . V_39 )
V_2 -> V_39 = V_20 [ V_2 -> V_6 . type ] . V_39 ;
if ( V_2 -> V_36 == V_38 )
return;
if ( V_2 -> V_143 || V_144 [ V_2 -> V_6 . V_14 ] ) {
static const unsigned short V_145 [] = {
0x20 >> 1 ,
0x22 >> 1 ,
V_146
} ;
struct V_147 * V_148 ;
V_148 = F_42 ( & V_2 -> V_6 . V_149 ,
& V_2 -> V_6 . V_150 , L_44 , 0 , V_145 ) ;
V_2 -> V_143 = ( V_148 != NULL ) ;
}
switch ( V_151 [ V_2 -> V_6 . V_14 ] ) {
case - 1 :
return;
case 0 :
break;
case 1 : {
static const unsigned short V_145 [] = {
V_43 >> 1 ,
V_152 >> 1 ,
V_146
} ;
V_2 -> V_153 = F_42 ( & V_2 -> V_6 . V_149 ,
& V_2 -> V_6 . V_150 , L_45 , 0 , V_145 ) ;
if ( V_2 -> V_153 )
return;
goto V_154;
}
case 2 : {
static const unsigned short V_145 [] = {
V_155 >> 1 ,
V_146
} ;
if ( F_42 ( & V_2 -> V_6 . V_149 ,
& V_2 -> V_6 . V_150 , L_46 , 0 , V_145 ) )
return;
goto V_154;
}
case 3 : {
V_2 -> V_156 = F_42 ( & V_2 -> V_6 . V_149 ,
& V_2 -> V_6 . V_150 , L_47 , 0 , F_43 () ) ;
if ( V_2 -> V_156 )
return;
goto V_154;
}
default:
F_3 ( V_132 L_48 ,
V_2 -> V_6 . V_14 ) ;
return;
}
if ( ! V_20 [ V_2 -> V_6 . type ] . V_157 ) {
V_2 -> V_153 = F_42 ( & V_2 -> V_6 . V_149 ,
& V_2 -> V_6 . V_150 , L_45 ,
0 , F_44 ( V_43 >> 1 ) ) ;
} else if ( V_20 [ V_2 -> V_6 . type ] . V_158 ) {
V_2 -> V_153 = F_42 ( & V_2 -> V_6 . V_149 ,
& V_2 -> V_6 . V_150 , L_45 ,
0 , F_44 ( V_152 >> 1 ) ) ;
}
if ( V_2 -> V_153 )
return;
if ( ! V_20 [ V_2 -> V_6 . type ] . V_159 ) {
static const unsigned short V_145 [] = {
V_155 >> 1 ,
V_146
} ;
if ( F_42 ( & V_2 -> V_6 . V_149 ,
& V_2 -> V_6 . V_150 , L_46 , 0 , V_145 ) )
return;
}
V_2 -> V_156 = F_42 ( & V_2 -> V_6 . V_149 ,
& V_2 -> V_6 . V_150 , L_47 , 0 , F_43 () ) ;
if ( V_2 -> V_156 )
return;
V_154:
F_3 ( V_132 L_49 ,
V_2 -> V_6 . V_14 ) ;
}
void T_1 F_45 ( struct V_1 * V_2 )
{
int V_160 = V_161 ;
if ( V_161 != V_20 [ V_2 -> V_6 . type ] . V_162 )
V_160 = V_20 [ V_2 -> V_6 . type ] . V_162 ;
if ( V_2 -> V_36 != V_38 ) {
struct V_163 V_164 ;
if ( V_20 [ V_2 -> V_6 . type ] . V_32 )
F_42 ( & V_2 -> V_6 . V_149 ,
& V_2 -> V_6 . V_150 , L_50 ,
0 , F_46 ( V_165 ) ) ;
F_42 ( & V_2 -> V_6 . V_149 ,
& V_2 -> V_6 . V_150 , L_50 ,
0 , F_46 ( V_166 ) ) ;
F_42 ( & V_2 -> V_6 . V_149 ,
& V_2 -> V_6 . V_150 , L_50 ,
0 , F_46 ( V_167 ) ) ;
V_164 . V_168 = V_169 ;
V_164 . type = V_2 -> V_36 ;
V_164 . V_160 = V_160 ;
if ( V_20 [ V_2 -> V_6 . type ] . V_32 )
V_164 . V_168 |= V_170 ;
F_47 ( V_2 , V_131 , V_171 , & V_164 ) ;
}
if ( V_2 -> V_56 ) {
struct V_172 V_173 ;
V_173 . V_131 = V_174 ;
V_173 . V_175 = & V_2 -> V_56 ;
F_47 ( V_2 , V_131 , V_176 , & V_173 ) ;
}
}
static void F_38 ( struct V_1 * V_2 )
{
if( strncmp ( & ( V_26 [ 0x1e ] ) , L_51 , 14 ) == 0 ) {
V_2 -> V_36 = V_177 ;
F_3 ( L_52 ,
V_2 -> V_6 . V_14 , & V_26 [ 0x1e ] ) ;
} else if ( strncmp ( & ( V_26 [ 0x1e ] ) , L_53 , 10 ) == 0 ) {
V_2 -> V_36 = V_178 ;
F_3 ( L_52 ,
V_2 -> V_6 . V_14 , & V_26 [ 0x1e ] ) ;
} else if ( strncmp ( & ( V_26 [ 0x1e ] ) , L_54 , 14 ) == 0 ) {
V_2 -> V_36 = V_179 ;
F_3 ( L_52 ,
V_2 -> V_6 . V_14 , & V_26 [ 0x1e ] ) ;
} else {
F_3 ( L_55 ,
V_2 -> V_6 . V_14 , & V_26 [ 0x1e ] ) ;
}
}
static void T_1 F_32 ( struct V_1 * V_2 )
{
struct V_180 V_181 ;
F_48 ( & V_2 -> V_182 , & V_181 , V_26 ) ;
V_2 -> V_36 = V_181 . V_36 ;
V_2 -> V_32 = V_181 . V_32 ;
F_3 ( L_56 ,
V_2 -> V_6 . V_14 , V_181 . V_183 ) ;
if( V_181 . V_183 == 64900 ) {
F_3 ( L_57 ,
V_2 -> V_6 . V_14 ,
V_20 [ V_2 -> V_6 . type ] . V_15 ,
V_20 [ V_184 ] . V_15 ) ;
V_2 -> V_6 . type = V_184 ;
}
}
static int F_36 ( struct V_1 * V_2 )
{
int V_185 ;
V_2 -> V_32 = 1 ;
V_2 -> V_46 = 1 ;
V_2 -> V_47 = 0x10 ;
V_2 -> V_48 = 0x20 ;
V_2 -> V_49 = 0x08 ;
V_2 -> V_50 = 0x04 ;
V_2 -> V_51 = 0x3c ;
V_2 -> V_186 = 1 << 8 ;
V_2 -> V_187 = 1 << 9 ;
V_2 -> V_188 = 1 << 10 ;
V_185 = 88000 / 62.5 ;
F_49 ( V_2 , 5 * V_185 + 0x358 ) ;
if ( 0x1ed8 == F_50 ( V_2 ) ) {
F_3 ( L_58 ,
V_2 -> V_6 . V_14 ) ;
V_2 -> V_32 = 1 ;
V_2 -> V_143 = 1 ;
V_2 -> V_46 = 1 ;
} else {
V_2 -> V_32 = 0 ;
V_2 -> V_46 = 0 ;
}
return 0 ;
}
static int T_1 F_51 ( struct V_1 * V_2 , const T_2 * V_189 ,
T_3 V_190 )
{
T_3 V_191 ;
T_2 V_192 ;
int V_4 ;
F_7 ( 0xffffff , V_193 | V_194 | V_195 ) ;
F_13 ( 0 ) ;
F_8 ( V_196 ) ;
F_13 ( V_195 ) ;
F_8 ( V_196 ) ;
for ( V_191 = 0 ; V_191 < V_190 ; V_191 ++ ) {
V_192 = V_189 [ V_191 ] ;
for ( V_4 = 0 ; V_4 < 8 ; V_4 ++ ) {
F_14 ( V_194 , 0 ) ;
if ( V_192 & 0x01 )
F_14 ( V_193 , V_193 ) ;
else
F_14 ( V_193 , 0 ) ;
F_14 ( V_194 , V_194 ) ;
V_192 >>= 1 ;
}
}
F_14 ( V_194 , 0 ) ;
F_8 ( V_196 ) ;
for ( V_4 = 0 ; V_4 < 30 ; V_4 ++ ) {
F_14 ( V_194 , 0 ) ;
F_14 ( V_194 , V_194 ) ;
}
F_14 ( V_194 , 0 ) ;
return 0 ;
}
static int T_1 F_28 ( struct V_1 * V_2 )
{
const struct V_197 * V_198 ;
int V_199 ;
V_199 = F_52 ( & V_198 , L_59 , & V_2 -> V_6 . V_7 -> V_200 ) ;
if ( V_199 != 0 ) {
F_3 ( V_132 L_60 ,
V_2 -> V_6 . V_14 ) ;
return V_199 ;
}
V_199 = F_51 ( V_2 , V_198 -> V_201 , V_198 -> V_202 ) ;
F_3 ( V_13 L_61 ,
V_2 -> V_6 . V_14 , ( V_199 < 0 ) ? L_62 : L_63 ) ;
F_53 ( V_198 ) ;
return V_199 ;
}
static void T_1 F_37 ( struct V_1 * V_2 , const T_2 V_203 [ 256 ] )
{
int V_4 ;
T_3 V_204 = 0 ;
int V_9 = - 1 ;
if ( V_2 -> V_6 . type == V_83 ) {
if ( ! strncmp ( V_203 , L_64 , 4 ) ) {
T_2 V_205 = 0 ;
for ( V_4 = 0 ; V_4 < 21 ; V_4 ++ )
V_205 += V_203 [ V_4 ] ;
if ( V_205 != V_203 [ 21 ] )
return;
V_9 = V_105 ;
for ( V_4 = 12 ; V_4 < 21 ; V_4 ++ )
V_204 *= 10 , V_204 += V_203 [ V_4 ] - '0' ;
}
} else {
unsigned short type ;
for ( V_4 = 4 * 16 ; V_4 < 8 * 16 ; V_4 += 16 ) {
T_4 V_205 = F_54 ( V_203 + V_4 , 16 ) ;
if ( ( V_205 & 0xff ) + ( V_205 >> 8 ) == 0xff )
break;
}
if ( V_4 >= 8 * 16 )
return;
V_203 += V_4 ;
type = F_55 ( ( V_206 * ) ( V_203 + 4 ) ) ;
switch( type ) {
case 0x0004 :
V_9 = V_105 ;
break;
case 0x0005 :
V_9 = V_106 ;
break;
case 0x0012 :
case 0x0013 :
V_9 = V_104 ;
break;
case 0x0014 :
case 0x0015 :
V_9 = V_107 ;
break;
case 0x0016 :
case 0x0017 :
case 0x0020 :
V_9 = V_108 ;
break;
case 0x0018 :
case 0x0019 :
case 0x001E :
case 0x001F :
V_9 = V_109 ;
break;
case 0x001A :
case 0x001B :
V_9 = V_110 ;
break;
case 0x0040 :
V_9 = V_113 ;
break;
case 0x0050 :
case 0x0056 :
V_9 = V_114 ;
break;
case 0x0060 :
case 0x0070 :
case 0x00A0 :
V_9 = V_111 ;
F_7 ( 0xffffff , 0x000303 ) ;
break;
case 0x00D8 :
V_9 = V_112 ;
break;
default:
F_3 ( V_13 L_65
L_66 ,
V_2 -> V_6 . V_14 , type ) ;
break;
}
V_204 = F_56 ( ( V_207 * ) ( V_203 + 6 ) ) ;
}
F_3 ( V_13 L_67 ,
V_2 -> V_6 . V_14 , V_9 ,
V_9 > 0 ? V_20 [ V_9 ] . V_15 : L_68 , V_204 ) ;
if ( V_9 < 0 || V_2 -> V_6 . type == V_9 )
return;
if ( V_18 [ V_2 -> V_6 . V_14 ] < V_19 ) {
F_3 ( V_132 L_69
L_70 , V_2 -> V_6 . V_14 ) ;
} else {
F_3 ( V_13 L_69
L_71 , V_2 -> V_6 . V_14 ,
V_2 -> V_6 . type , V_9 ) ;
V_2 -> V_6 . type = V_9 ;
}
}
static void T_1 F_33 ( struct V_1 * V_2 )
{
int V_208 , V_209 , V_210 , V_36 = 0 ;
V_208 = ( V_26 [ 0x41 ] & 0x7 ) ;
V_209 = ( V_26 [ 0x41 ] & 0x18 ) >> 3 ;
V_210 = ( V_26 [ 0x42 ] & 0xf0 ) >> 4 ;
V_2 -> V_31 = ( V_26 [ 0x42 ] & 0x01 ) ;
if ( V_208 == 0 || V_208 == 2 )
if ( V_210 <= 0x0a )
V_36 = V_211 [ V_210 ] ;
if ( V_208 == 1 )
if ( V_210 <= 9 )
V_36 = V_212 [ V_210 ] ;
if ( V_208 == 4 )
if ( V_210 == 0x09 )
V_36 = V_213 ;
F_3 ( V_13 L_72 ,
V_2 -> V_6 . V_14 , V_26 [ 0x41 ] , V_26 [ 0x42 ] ) ;
if ( V_36 ) {
V_2 -> V_36 = V_36 ;
F_3 ( V_214 L_73 , V_36 ) ;
} else
F_3 ( V_214 L_74 ) ;
F_3 ( V_214 L_75 ,
V_209 ? L_19 : L_24 ,
V_2 -> V_31 ? L_19 : L_24 ) ;
}
T_3 F_57 ( struct V_1 * V_2 , T_3 V_3 )
{
if ( V_2 -> V_215 == V_216 ) {
if ( V_217 [ V_2 -> V_218 ] . V_219 & V_220 )
V_3 |= 0x10000 ;
else
V_3 &= ~ 0x10000 ;
}
F_14 ( V_20 [ V_2 -> V_6 . type ] . V_25 , V_3 ) ;
return V_3 ;
}
static void T_1 F_27 ( struct V_1 * V_2 , int V_221 )
{
int V_222 = ( 1 << V_221 ) ;
F_7 ( V_222 , V_222 ) ;
F_14 ( V_222 , 0 ) ;
F_58 ( 2 ) ;
F_8 ( 500 ) ;
F_14 ( V_222 , V_222 ) ;
if ( V_223 )
F_59 ( V_2 , L_76 ) ;
if ( V_224 )
F_3 ( V_13 L_77
L_78 , V_2 -> V_6 . V_14 , V_221 ) ;
}
static void T_1 F_34 ( struct V_1 * V_2 )
{
static int V_225 [] V_226 = { 0x08 , 0x09 , 0x0a , 0x0b , 0x0d , 0x0d ,
0x01 , 0x02 , 0x03 , 0x04 , 0x05 , 0x06 ,
0x00 } ;
unsigned int V_4 ;
int V_5 ;
T_3 V_227 ;
F_7 ( 0xffffff , ( 1 << 13 ) ) ;
F_13 ( 0 ) ;
F_8 ( 3 ) ;
F_13 ( 1 << 13 ) ;
F_14 ( 0xffffff , 0 ) ;
if ( V_223 )
F_59 ( V_2 , L_79 ) ;
F_21 ( V_228 | V_229 , V_64 ) ;
F_3 ( V_13 L_80 ) ;
F_60 ( V_2 , 0x5E , 0 , 0x80 , 1 ) ;
F_3 ( V_13 L_81 ) ;
V_227 = F_61 ( V_230 ) ;
V_227 |= V_231 ;
F_21 ( V_227 , V_230 ) ;
F_7 ( 0xffffff , ( 1 << 2 ) ) ;
F_13 ( 0 ) ;
F_8 ( 10 ) ;
F_13 ( 1 << 2 ) ;
for ( V_4 = 0 ; V_4 < F_4 ( V_225 ) ; V_4 ++ ) {
V_5 = F_60 ( V_2 , 0x1E , 0 , V_225 [ V_4 ] , 1 ) ;
if ( V_5 != - 1 ) {
F_3 ( V_13
L_82 ,
V_225 [ V_4 ] , V_5 , F_11 ( V_2 , 0x1F , NULL ) ) ;
}
}
F_3 ( V_13 L_83 ) ;
}
static void
F_29 ( struct V_1 * V_2 )
{
T_5 V_232 = 0 ;
long V_233 = 0x0E ;
F_3 ( V_13
L_84 ,
V_2 -> V_6 . V_14 ) ;
F_21 ( 0x00c3feff , V_234 ) ;
F_21 ( 0 + V_233 , V_235 ) ;
F_62 ( 1 ) ;
F_21 ( 0x10 + V_233 , V_235 ) ;
F_62 ( 10 ) ;
F_21 ( 0 + V_233 , V_235 ) ;
V_232 = F_61 ( V_235 ) ;
if ( ( ( ( V_232 >> 18 ) & 0x01 ) != 0 ) || ( ( ( V_232 >> 19 ) & 0x01 ) != 1 ) ) {
F_3 ( V_13
L_85 ,
V_2 -> V_6 . V_14 , V_232 ) ;
}
F_21 ( 0x4400 + V_233 , V_235 ) ;
F_62 ( 10 ) ;
F_21 ( 0x4410 + V_233 , V_235 ) ;
F_62 ( 1 ) ;
F_21 ( V_233 , V_235 ) ;
F_62 ( 1 ) ;
V_232 = F_61 ( V_235 ) ;
if ( ( ( ( V_232 >> 18 ) & 0x01 ) != 0 ) || ( ( ( V_232 >> 19 ) & 0x01 ) != 0 ) ) {
F_3 ( V_13
L_86 ,
V_2 -> V_6 . V_14 , V_232 ) ;
return;
}
F_3 ( V_13
L_87 , V_2 -> V_6 . V_14 ) ;
}
static void F_63 ( struct V_1 * V_2 , int V_236 )
{
if ( V_2 -> V_187 ) {
F_14 ( V_2 -> V_187 | V_2 -> V_186 | V_2 -> V_188 ,
V_2 -> V_187 | V_2 -> V_186 | V_2 -> V_188 ) ;
F_8 ( 5 ) ;
}
F_14 ( V_236 , 0 ) ;
F_8 ( 5 ) ;
if ( V_2 -> V_187 ) {
F_14 ( V_2 -> V_186 | V_2 -> V_188 , 0 ) ;
F_8 ( 5 ) ;
}
}
static void F_64 ( struct V_1 * V_2 , int V_236 )
{
if ( V_2 -> V_187 ) {
F_14 ( V_2 -> V_187 | V_2 -> V_186 | V_2 -> V_188 ,
V_2 -> V_187 | V_2 -> V_186 | V_2 -> V_188 ) ;
F_8 ( 5 ) ;
}
F_14 ( V_236 , V_236 ) ;
F_8 ( 5 ) ;
if ( V_2 -> V_187 ) {
F_14 ( V_2 -> V_186 | V_2 -> V_188 , 0 ) ;
F_8 ( 5 ) ;
}
}
static int F_65 ( struct V_1 * V_2 , int V_236 )
{
if ( V_2 -> V_187 ) {
F_14 ( V_2 -> V_187 | V_2 -> V_186 | V_2 -> V_188 ,
V_2 -> V_187 | V_2 -> V_186 | V_2 -> V_188 ) ;
F_8 ( 5 ) ;
F_14 ( V_2 -> V_186 | V_2 -> V_188 , 0 ) ;
F_8 ( 5 ) ;
}
return F_9 () & ( V_236 ) ;
}
static int F_50 ( struct V_1 * V_2 )
{
unsigned long V_237 ;
int V_238 = 0 ;
int V_4 ;
F_7 ( V_2 -> V_51 , V_2 -> V_49 | V_2 -> V_47 ) ;
if ( V_2 -> V_187 ) {
F_14 ( V_2 -> V_187 | V_2 -> V_186 | V_2 -> V_188 ,
V_2 -> V_187 | V_2 -> V_186 | V_2 -> V_188 ) ;
F_8 ( 5 ) ;
}
if ( V_223 )
F_59 ( V_2 , L_88 ) ;
F_63 ( V_2 , V_2 -> V_47 ) ;
F_63 ( V_2 , V_2 -> V_49 ) ;
F_8 ( 10 ) ;
V_237 = V_239 + F_66 ( 1000 ) ;
while ( F_65 ( V_2 , V_2 -> V_50 ) && F_67 ( V_239 , V_237 ) )
F_68 () ;
if ( F_65 ( V_2 , V_2 -> V_50 ) ) {
F_3 ( V_132 L_89 , V_2 -> V_6 . V_14 ) ;
return - 1 ;
}
F_69 ( L_90 , V_2 -> V_6 . V_14 ) ;
for ( V_4 = 0 ; V_4 < 24 ; V_4 ++ ) {
F_8 ( 5 ) ;
F_64 ( V_2 , V_2 -> V_49 ) ;
F_8 ( 5 ) ;
F_69 ( L_91 , ( F_65 ( V_2 , V_2 -> V_48 ) == 0 ) ? 'T' : '-' ) ;
F_63 ( V_2 , V_2 -> V_49 ) ;
V_238 <<= 1 ;
V_238 |= ( F_65 ( V_2 , V_2 -> V_50 ) == 0 ) ? 0 : 1 ;
F_69 ( L_91 , ( F_65 ( V_2 , V_2 -> V_48 ) == 0 ) ? 'S' : 'M' ) ;
}
F_69 ( L_92 , V_2 -> V_6 . V_14 , V_238 ) ;
return V_238 ;
}
static int F_49 ( struct V_1 * V_2 , int V_238 )
{
int V_4 ;
int V_240 = V_238 ;
F_7 ( V_2 -> V_51 , V_2 -> V_49 | V_2 -> V_47 | V_2 -> V_50 ) ;
if ( V_2 -> V_187 ) {
F_14 ( V_2 -> V_187 | V_2 -> V_186 | V_2 -> V_188 ,
V_2 -> V_187 | V_2 -> V_186 | V_2 -> V_188 ) ;
F_8 ( 5 ) ;
}
if ( V_223 )
F_59 ( V_2 , L_93 ) ;
F_69 ( L_94 , V_2 -> V_6 . V_14 , V_238 ) ;
F_63 ( V_2 , V_2 -> V_49 ) ;
F_64 ( V_2 , V_2 -> V_47 ) ;
for ( V_4 = 0 ; V_4 < 25 ; V_4 ++ ) {
if ( V_240 & 0x1000000 )
F_64 ( V_2 , V_2 -> V_50 ) ;
else
F_63 ( V_2 , V_2 -> V_50 ) ;
V_240 <<= 1 ;
F_64 ( V_2 , V_2 -> V_49 ) ;
F_8 ( 10 ) ;
F_63 ( V_2 , V_2 -> V_49 ) ;
F_8 ( 10 ) ;
}
F_63 ( V_2 , V_2 -> V_47 ) ;
return 0 ;
}
void F_70 ( struct V_1 * V_2 , unsigned short V_185 )
{
F_69 ( L_95 , V_185 ) ;
F_49 ( V_2 , 5 * V_185 + 0x358 ) ;
}
static void F_71 ( struct V_1 * V_2 , unsigned int V_62 )
{
static const T_2 V_241 [] = { 0x3 , 0x1 , 0x2 , 0x4 , 0xf , 0x7 , 0xe , 0x0 ,
0xd , 0xb , 0xc , 0x6 , 0x9 , 0x5 , 0x8 , 0xa } ;
F_14 ( 0x07f , V_241 [ V_62 ] ) ;
F_14 ( 0x200 , 0x200 ) ;
F_58 ( 1 ) ;
F_14 ( 0x200 , 0x000 ) ;
F_58 ( 1 ) ;
F_14 ( 0x480 , 0x480 ) ;
F_58 ( 1 ) ;
F_14 ( 0x480 , 0x080 ) ;
F_58 ( 1 ) ;
}
static void F_72 ( struct V_1 * V_2 , unsigned int V_62 )
{
F_14 ( 0x0f0000 , V_62 << 16 ) ;
}
static void F_39 ( struct V_1 * V_2 )
{
F_7 ( 0xffffff , 0x0f7fff ) ;
F_13 ( 0x0f7fff ) ;
}
static void F_73 ( struct V_1 * V_2 ,
unsigned char V_242 ,
unsigned char V_243 ,
unsigned char V_201 ) {
unsigned int V_244 ;
V_244 = ( V_201 << 7 ) | ( ( V_243 & 3 ) << 4 ) | ( V_242 & 0xf ) ;
F_14 ( 0x1ff , V_244 ) ;
F_14 ( 0x1ff , V_244 | ( 1 << 8 ) ) ;
F_14 ( 0x1ff , V_244 ) ;
}
static void F_74 ( struct V_1 * V_2 , unsigned int V_62 )
{
char * V_245 ;
int V_242 , V_243 ;
struct V_1 * V_246 ;
static unsigned char V_247 [ 4 ] = { 3 , 0 , 2 , 1 } ;
V_246 = V_248 [ V_2 -> V_6 . V_14 ] ;
if ( V_246 == NULL ) {
return;
}
V_243 = ( V_2 -> V_6 . V_14 - V_246 -> V_6 . V_14 + 1 ) & 3 ;
V_243 = V_247 [ V_243 ] ;
V_245 = ( char * ) ( & V_246 -> V_47 ) ;
V_242 = V_62 & 0xf ;
if ( V_245 [ V_243 ] != V_242 )
{
F_73 ( V_246 , V_245 [ V_243 ] , V_243 , 0 ) ;
V_245 [ V_243 ] = V_242 ;
F_73 ( V_246 , V_242 , V_243 , 1 ) ;
}
}
static void F_40 ( struct V_1 * V_2 )
{
char * V_245 = ( char * ) ( & V_2 -> V_47 ) ;
int V_249 ;
F_7 ( 0x0003ff , 0x0003ff ) ;
F_13 ( 1 << 9 ) ;
F_13 ( 0 ) ;
for ( V_249 = 0 ; V_249 < 4 ; V_249 ++ ) {
V_245 [ V_249 ] = V_249 ;
F_73 ( V_2 , V_249 , V_249 , 1 ) ;
}
if ( ( V_2 -> V_6 . V_14 < 1 ) || ( V_2 -> V_6 . V_14 > V_250 - 3 ) )
return;
V_248 [ V_2 -> V_6 . V_14 - 1 ] = V_2 ;
V_248 [ V_2 -> V_6 . V_14 ] = V_2 ;
V_248 [ V_2 -> V_6 . V_14 + 1 ] = V_2 ;
V_248 [ V_2 -> V_6 . V_14 + 2 ] = V_2 ;
}
static void F_75 ( struct V_1 * V_2 , unsigned int V_62 )
{
static const int V_68 [] = {
V_251 , V_251 | V_252 , V_251 | V_253 , V_251 | V_252 | V_253 ,
V_254 , V_254 | V_252 , V_254 | V_253 , V_254 | V_252 | V_253 ,
V_255 , V_255 | V_256 , V_255 | V_257 , V_255 | V_256 | V_257 ,
V_258 , V_258 | V_256 , V_258 | V_257 , V_258 | V_256 | V_257 ,
} ;
F_13 ( V_68 [ V_62 % 16 ] ) ;
}
static void F_35 ( struct V_1 * V_2 )
{
F_21 ( 0x08 << 16 , V_235 ) ;
F_21 ( 0x04 << 16 , V_235 ) ;
}
static void F_76 ( struct V_1 * V_2 , unsigned int V_62 )
{
F_69 ( V_17 L_96 , V_2 -> V_6 . V_14 , V_62 ) ;
F_21 ( V_62 << 20 , V_235 ) ;
}
static void F_77 ( struct V_1 * V_2 , unsigned int V_62 )
{
int V_259 = V_62 % 4 ;
int V_260 = V_62 / 4 ;
F_69 ( L_97 ,
V_2 -> V_6 . V_14 , V_62 , V_260 , V_259 ) ;
F_60 ( V_2 , V_261 , 0x00 ,
( ( V_260 == 3 ) ? ( V_259 | V_259 << 2 ) : 0x00 ) , 1 ) ;
F_60 ( V_2 , V_262 , 0x00 ,
( ( V_260 == 0 ) ? ( V_259 | V_259 << 2 ) : 0x00 ) , 1 ) ;
F_60 ( V_2 , V_263 , 0x00 ,
( ( V_260 == 1 ) ? ( V_259 | V_259 << 2 ) : 0x00 ) , 1 ) ;
F_60 ( V_2 , V_264 , 0x00 ,
( ( V_260 == 2 ) ? ( V_259 | V_259 << 2 ) : 0x00 ) , 1 ) ;
F_60 ( V_2 , V_261 , 0x02 ,
( ( V_260 == 3 ) ? 0x03 : 0x00 ) , 1 ) ;
F_60 ( V_2 , V_262 , 0x02 ,
( ( V_260 == 0 ) ? 0x03 : 0x00 ) , 1 ) ;
F_60 ( V_2 , V_263 , 0x02 ,
( ( V_260 == 1 ) ? 0x03 : 0x00 ) , 1 ) ;
F_60 ( V_2 , V_264 , 0x02 ,
( ( V_260 == 2 ) ? 0x03 : 0x00 ) , 1 ) ;
}
static void F_78 ( struct V_1 * V_2 , unsigned int V_62 )
{
int V_199 ;
long V_265 ;
int V_266 ;
unsigned char V_267 [ 2 ] ;
V_267 [ 0 ] = 0 ;
V_267 [ 1 ] = 0 ;
V_199 = F_60 ( V_2 , ( V_268 << 1 ) , V_267 [ 0 ] , V_267 [ 1 ] , 1 ) ;
if ( V_199 ) {
F_3 ( V_17 L_98 , V_2 -> V_6 . V_14 , V_199 ) ;
return;
}
V_199 = F_11 ( V_2 , ( V_268 << 1 ) , NULL ) ;
if ( ! ( V_199 & V_269 ) ) {
F_3 ( V_17 L_99 , V_2 -> V_6 . V_14 , V_199 ) ;
return;
}
V_265 = V_62 ;
V_266 = 0x302 ;
if ( V_2 -> V_9 == V_270 ) {
V_266 ^= 0x180 ;
V_266 |= 7 << 4 ;
}
F_21 ( V_266 , V_234 ) ;
V_266 = F_61 ( V_235 ) ;
if ( V_2 -> V_9 == V_270 )
V_266 = ( V_266 & ~ 0x280 ) | ( ( V_265 & 2 ) << 8 ) | ( ( V_265 & 1 ) << 7 ) ;
else
V_266 = ( V_266 & ~ 0x300 ) | ( ( V_265 & 3 ) << 8 ) ;
F_21 ( V_266 , V_235 ) ;
if ( V_2 -> V_9 == V_270 )
F_15 ( 2 << 5 , ~ V_271 , V_61 ) ;
else
F_18 ( ~ V_271 , V_61 ) ;
F_3 ( V_17 L_100 , V_2 -> V_6 . V_14 , ( int ) V_265 ) ;
}
static void F_79 ( struct V_1 * V_2 , unsigned int V_62 )
{
unsigned int V_265 = V_62 % 4 ;
if ( V_62 == V_2 -> V_137 )
V_265 = 0 ;
F_14 ( 0x3 , V_265 ) ;
}
static void F_80 ( struct V_1 * V_2 ,
unsigned char V_242 ,
unsigned char V_243 ,
unsigned char V_201 ) {
const T_3 V_272 = ( ( V_242 & 0xf ) | ( V_243 & 3 ) << 4 ) ;
const T_3 V_273 = 1 << 16 ;
const T_3 V_274 = 1 << 17 ;
const T_3 V_275 = V_201 << 18 ;
F_14 ( 0x1007f , V_272 | V_273 ) ;
F_14 ( 0x20000 , V_274 ) ;
F_14 ( 0x40000 , V_275 ) ;
F_14 ( 0x20000 , ~ V_274 ) ;
}
static void F_81 ( struct V_1 * V_2 , unsigned int V_62 )
{
struct V_1 * V_246 ;
char * V_245 ;
int V_242 , V_243 ;
static unsigned int V_247 [ 4 ] [ 4 ] = { { 0x0 , 0x4 , 0xa , 0x6 } ,
{ 0x1 , 0x5 , 0xb , 0x7 } ,
{ 0x2 , 0x8 , 0xc , 0xe } ,
{ 0x3 , 0x9 , 0xd , 0xf } } ;
V_62 = V_62 % 4 ;
V_246 = V_248 [ V_2 -> V_6 . V_14 ] ;
if ( V_246 == NULL ) {
return;
}
V_243 = ( V_2 -> V_6 . V_14 - V_246 -> V_6 . V_14 ) & 3 ;
V_245 = ( char * ) ( & V_246 -> V_47 ) ;
V_242 = V_247 [ V_243 ] [ V_62 ] & 0xf ;
if ( V_245 [ V_243 ] != V_242 ) {
F_80 ( V_246 , V_245 [ V_243 ] , V_243 , 0 ) ;
V_245 [ V_243 ] = V_242 ;
F_80 ( V_246 , V_242 , V_243 , 1 ) ;
}
}
static void F_41 ( struct V_1 * V_2 )
{
char * V_245 = ( char * ) ( & V_2 -> V_47 ) ;
int V_249 ;
F_7 ( 0xf107f , 0xf107f ) ;
F_13 ( 1 << 19 ) ;
F_13 ( 0 ) ;
for ( V_249 = 0 ; V_249 < 4 ; V_249 ++ ) {
V_245 [ V_249 ] = V_249 ;
F_80 ( V_2 , V_249 , V_249 , 1 ) ;
}
F_60 ( V_2 , 0x18 , 0x5 , 0x90 , 1 ) ;
if ( V_2 -> V_6 . V_14 > V_250 - 4 )
return;
V_248 [ V_2 -> V_6 . V_14 ] = V_2 ;
V_248 [ V_2 -> V_6 . V_14 + 1 ] = V_2 ;
V_248 [ V_2 -> V_6 . V_14 + 2 ] = V_2 ;
V_248 [ V_2 -> V_6 . V_14 + 3 ] = V_2 ;
}
void T_6 F_82 ( void )
{
int V_276 = 0 ;
struct V_277 * V_200 = NULL ;
if ( V_278 & ( V_279 | V_280 ) )
V_276 = 1 ;
if ( V_278 & ( V_281 | V_282 | V_283 ) )
V_284 = 1 ;
if ( V_278 & V_285 )
V_286 = 1 ;
#ifdef F_83
if ( V_278 & F_83 )
V_287 = 0x0A ;
#endif
if ( V_284 )
F_3 ( V_13 L_101 ) ;
if ( V_286 )
F_3 ( V_13 L_102 ) ;
if ( V_276 ) {
F_3 ( V_13 L_103
L_104 ) ;
if ( ! V_288 ) {
F_3 ( V_13 L_105 ) ;
V_288 = 1 ;
} else {
F_3 ( V_13 L_106
L_107 ) ;
}
}
if ( V_21 != V_287 )
F_3 ( V_13 L_108 , V_287 ) ;
while ( ( V_200 = F_84 ( V_289 ,
V_290 , V_200 ) ) ) {
unsigned char V_291 ;
F_85 ( V_200 , 0x53 , & V_291 ) ;
if ( V_71 )
F_3 ( V_13 L_109
L_110 , V_291 ) ;
}
}
int T_1 F_86 ( struct V_1 * V_2 )
{
unsigned char V_292 ;
if ( ! V_284 && ! V_286 && V_21 == V_287 )
return 0 ;
if ( V_224 ) {
if ( V_284 )
F_3 ( V_13 L_111 , V_2 -> V_6 . V_14 ) ;
if ( V_286 && V_2 -> V_12 >= 878 )
F_3 ( V_13 L_112 , V_2 -> V_6 . V_14 ) ;
if ( V_21 != V_287 )
F_3 ( V_13 L_113 ,
V_2 -> V_6 . V_14 , V_287 ) ;
}
if ( V_2 -> V_12 < 878 ) {
if ( V_284 )
V_2 -> V_284 = V_293 ;
} else {
F_85 ( V_2 -> V_6 . V_7 , V_294 , & V_292 ) ;
if ( V_284 )
V_292 |= V_295 ;
if ( V_286 )
V_292 |= V_296 ;
F_87 ( V_2 -> V_6 . V_7 , V_294 , V_292 ) ;
}
if ( V_21 != V_287 )
F_87 ( V_2 -> V_6 . V_7 , V_297 , V_287 ) ;
return 0 ;
}
