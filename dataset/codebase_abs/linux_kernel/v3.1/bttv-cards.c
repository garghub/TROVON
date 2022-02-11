void T_1 F_1 ( struct V_1 * V_2 )
{
unsigned int V_3 ;
int V_4 , type ;
V_2 -> V_5 = V_2 -> V_6 . V_7 -> V_8 << 16 ;
V_2 -> V_5 |= V_2 -> V_6 . V_7 -> V_9 ;
if ( 0 != V_2 -> V_5 && 0xffffffff != V_2 -> V_5 ) {
for ( type = - 1 , V_4 = 0 ; V_10 [ V_4 ] . V_11 != 0 ; V_4 ++ )
if ( V_10 [ V_4 ] . V_11 == V_2 -> V_5 )
type = V_4 ;
if ( type != - 1 ) {
F_2 ( V_12 L_1
L_2 ,
V_2 -> V_6 . V_13 , V_10 [ type ] . V_14 , V_10 [ type ] . V_15 ,
V_2 -> V_5 & 0xffff ,
( V_2 -> V_5 >> 16 ) & 0xffff ) ;
V_2 -> V_6 . type = V_10 [ type ] . V_15 ;
} else {
F_2 ( V_12 L_3 ,
V_2 -> V_6 . V_13 , V_2 -> V_5 & 0xffff ,
( V_2 -> V_5 >> 16 ) & 0xffff ) ;
F_2 ( V_16 L_4
L_5 ) ;
}
}
if ( V_17 [ V_2 -> V_6 . V_13 ] < V_18 )
V_2 -> V_6 . type = V_17 [ V_2 -> V_6 . V_13 ] ;
F_2 ( V_12 L_6 , V_2 -> V_6 . V_13 ,
V_19 [ V_2 -> V_6 . type ] . V_14 , V_2 -> V_6 . type ,
V_17 [ V_2 -> V_6 . V_13 ] < V_18
? L_7 : L_8 ) ;
if ( V_20 == V_21 && V_20 == V_22 [ 0 ] )
return;
if ( V_20 != V_22 [ 0 ] ) {
V_3 = 0 ;
for ( V_4 = 0 ; V_4 < F_3 ( V_19 -> V_23 ) ; V_4 ++ ) {
V_19 [ V_2 -> V_6 . type ] . V_23 [ V_4 ] = V_22 [ V_4 ] ;
V_3 |= V_22 [ V_4 ] ;
}
} else {
V_3 = V_21 ;
for ( V_4 = 0 ; V_4 < F_3 ( V_19 -> V_23 ) ; V_4 ++ ) {
V_19 [ V_2 -> V_6 . type ] . V_23 [ V_4 ] = V_21 ;
}
}
V_19 [ V_2 -> V_6 . type ] . V_24 = ( V_20 != V_24 ) ? V_24 : V_3 ;
F_2 ( V_12 L_9 ,
V_2 -> V_6 . V_13 , V_19 [ V_2 -> V_6 . type ] . V_24 ) ;
for ( V_4 = 0 ; V_4 < F_3 ( V_19 -> V_23 ) ; V_4 ++ ) {
F_2 ( L_10 , V_4 ? L_11 : L_12 , V_19 [ V_2 -> V_6 . type ] . V_23 [ V_4 ] ) ;
}
F_2 ( L_13 ) ;
}
static void F_4 ( struct V_1 * V_2 , unsigned char V_25 [ 256 ] )
{
int type = - 1 ;
if ( 0 == strncmp ( V_25 , L_14 , 13 ) )
type = V_26 ;
else if ( 0 == strncmp ( V_25 + 20 , L_15 , 7 ) )
type = V_27 ;
else if ( V_25 [ 0 ] == 0x84 && V_25 [ 2 ] == 0 )
type = V_28 ;
if ( - 1 != type ) {
V_2 -> V_6 . type = type ;
F_2 ( L_16 ,
V_2 -> V_6 . V_13 , V_19 [ V_2 -> V_6 . type ] . V_14 , V_2 -> V_6 . type ) ;
}
}
static void F_5 ( struct V_1 * V_2 )
{
int V_29 , V_30 , V_31 , V_32 ;
int V_33 , V_34 ;
int V_35 = V_20 , V_36 ;
F_6 ( 0xffffff , 0 ) ;
F_7 ( 8 ) ;
V_29 = F_8 () ;
V_36 = ( V_29 & 0x0f0000 ) >> 16 ;
switch ( V_36 ) {
case 0x0 :
V_35 = 2 ;
break;
case 0x2 :
V_35 = 39 ;
break;
case 0x4 :
V_35 = 5 ;
break;
case 0x6 :
V_35 = 37 ;
break;
case 0xC :
V_35 = 3 ;
break;
default:
F_2 ( V_12 L_17 , V_2 -> V_6 . V_13 ) ;
break;
}
V_30 = V_29 & 0x800000 ;
V_31 = V_29 & 0x400000 ;
V_32 = ! ( V_29 & 0x008000 ) ;
V_34 = ! ( V_29 & 0x004000 ) ;
V_33 = ! ( V_29 & 0x002000 ) ;
if ( V_32 )
V_35 = V_37 ;
F_2 ( V_12 L_18 ,
V_2 -> V_6 . V_13 , V_31 ? L_19 : L_20 ,
V_30 ? L_19 : L_20 , V_35 , V_29 ) ;
F_2 ( V_12 L_21 ,
V_2 -> V_6 . V_13 , V_33 ? L_19 : L_20 ,
V_34 ? L_19 : L_20 ,
V_32 ? L_19 : L_20 ) ;
if ( V_35 != V_20 )
V_2 -> V_35 = V_35 ;
V_2 -> V_31 = V_31 ;
if ( V_34 )
V_2 -> V_38 = V_39 ;
}
static void F_9 ( struct V_1 * V_2 )
{
int V_11 , V_40 , V_29 ;
char * V_41 ;
F_6 ( 0xffffff , 0 ) ;
V_29 = F_8 () ;
V_11 = ( ( V_29 >> 10 ) & 63 ) - 1 ;
V_40 = F_10 ( V_2 , V_42 , L_22 ) ;
if ( V_11 < 32 ) {
V_2 -> V_35 = V_43 [ V_11 ] ;
if ( 0 == ( V_29 & 0x20 ) ) {
V_2 -> V_31 = 1 ;
if ( ! V_44 [ V_11 ] ) {
V_2 -> V_45 = 1 ;
V_2 -> V_46 = ( 1 << 6 ) ;
V_2 -> V_47 = ( 1 << 7 ) ;
V_2 -> V_48 = ( 1 << 8 ) ;
V_2 -> V_49 = ( 1 << 9 ) ;
V_2 -> V_50 = ( 1 << 6 ) | ( 1 << 7 ) | ( 1 << 8 ) | ( 1 << 9 ) ;
}
} else {
V_2 -> V_31 = 0 ;
}
if ( - 1 != V_40 ) {
if ( V_2 -> V_6 . type == V_51 )
V_2 -> V_6 . type = V_52 ;
if ( V_2 -> V_6 . type == V_53 )
V_2 -> V_6 . type = V_54 ;
}
F_2 ( V_12
L_23 ,
V_2 -> V_6 . V_13 , V_11 + 1 , V_2 -> V_35 ,
! V_2 -> V_31 ? L_24 :
( V_2 -> V_45 ? L_25 : L_26 ) ,
( - 1 == V_40 ) ? L_24 : L_19 ) ;
} else {
V_11 = 63 - V_11 ;
V_2 -> V_31 = 0 ;
switch ( V_11 ) {
case 1 :
V_41 = L_27 ;
V_2 -> V_55 = V_56 ;
break;
case 2 :
V_41 = L_28 ;
V_2 -> V_31 = 1 ;
V_2 -> V_55 = V_57 ;
break;
case 3 :
V_41 = L_29 ;
V_2 -> V_31 = 1 ;
V_2 -> V_55 = V_57 ;
break;
case 4 :
V_41 = L_30 ;
V_2 -> V_55 = V_57 ;
break;
case 5 :
V_41 = L_31 ;
V_2 -> V_55 = V_56 ;
break;
case 6 :
V_41 = L_29 ;
V_2 -> V_55 = V_56 ;
break;
case 7 :
V_41 = L_32 ;
V_2 -> V_55 = V_56 ;
break;
default:
V_41 = L_33 ;
break;
}
if ( - 1 != V_40 )
V_2 -> V_6 . type = V_54 ;
F_2 ( V_12
L_34 ,
V_2 -> V_6 . V_13 , V_11 , V_41 , V_2 -> V_31 ? L_19 : L_24 ) ;
V_2 -> V_35 = V_58 ;
}
}
static void F_11 ( struct V_1 * V_2 )
{
F_6 ( 0xffffff , 0xFFFF37 ) ;
F_12 ( 0x200020 ) ;
F_12 ( 0x200024 ) ;
F_13 ( V_59 , V_59 ) ;
F_14 ( ( 2 ) << 5 , ~ ( 2 << 5 ) , V_60 ) ;
}
static void F_15 ( struct V_1 * V_2 , unsigned int V_61 )
{
F_13 ( 3 , V_61 & 3 ) ;
F_16 ( V_62 , V_63 ) ;
F_17 ( ~ V_64 , V_65 ) ;
F_17 ( ~ V_64 , V_66 ) ;
F_13 ( V_59 , V_59 ) ;
}
static void F_18 ( struct V_1 * V_2 , unsigned int V_61 )
{
static const int V_67 [] = { 0x30 , 0x01 , 0x12 , 0x23 } ;
F_12 ( V_67 [ V_61 % 4 ] ) ;
}
static void F_19 ( struct V_1 * V_2 )
{
F_2 ( V_16 L_35 ) ;
F_20 ( 0x000000 , V_68 ) ;
F_6 ( 0xffffff , 0x0006C0 ) ;
F_12 ( 0x000000 ) ;
}
static void F_21 ( struct V_1 * V_2 , unsigned int V_61 )
{
unsigned int V_69 = V_61 % 8 ;
F_6 ( 0xf , 0xf ) ;
F_13 ( 0xf , V_69 ) ;
}
static void F_22 ( struct V_1 * V_2 , unsigned int V_61 )
{
unsigned int V_69 = V_61 % 4 ;
F_6 ( 3 << 9 , 3 << 9 ) ;
F_13 ( 3 << 9 , V_69 << 9 ) ;
}
static void F_23 ( struct V_1 * V_2 , unsigned int V_61 )
{
unsigned int V_69 = V_61 % 16 ;
F_6 ( 0xf , 0xf ) ;
F_13 ( 0xf , V_69 ) ;
}
static void F_24 ( struct V_1 * V_2 )
{
if ( V_2 -> V_11 != 878 )
return;
if ( V_70 )
F_2 ( L_36 , V_2 -> V_6 . V_13 ) ;
F_20 ( ( 1 << 7 ) , 0x058 ) ;
F_7 ( 10 ) ;
F_20 ( 0 , 0x058 ) ;
}
void T_1 F_25 ( struct V_1 * V_2 )
{
switch ( V_2 -> V_6 . type ) {
case V_28 :
case V_71 :
F_26 ( V_2 , 5 ) ;
break;
case V_72 :
case V_73 :
F_26 ( V_2 , 20 ) ;
break;
case V_74 :
F_26 ( V_2 , 11 ) ;
break;
case V_75 :
F_27 ( V_2 ) ;
break;
case V_76 :
case V_77 :
case V_78 :
V_2 -> V_79 = 1 ;
break;
case V_80 :
F_28 ( V_2 ) ;
break;
}
if ( ! V_19 [ V_2 -> V_6 . type ] . V_81 )
F_24 ( V_2 ) ;
}
void T_1 F_29 ( struct V_1 * V_2 )
{
V_2 -> V_35 = V_20 ;
if ( V_82 == V_2 -> V_6 . type ) {
F_30 ( V_2 , V_25 , 0xa0 ) ;
F_4 ( V_2 , V_25 ) ;
}
switch ( V_2 -> V_6 . type ) {
case V_51 :
case V_52 :
case V_53 :
case V_54 :
F_9 ( V_2 ) ;
break;
case V_83 :
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
F_5 ( V_2 ) ;
break;
case V_28 :
case V_71 :
case V_75 :
F_30 ( V_2 , V_25 , 0xa0 ) ;
F_31 ( V_2 ) ;
break;
case V_74 :
case V_94 :
F_30 ( V_2 , V_25 , 0xa0 ) ;
F_32 ( V_2 ) ;
break;
case V_95 :
F_33 ( V_2 ) ;
break;
case V_96 :
F_34 ( V_2 ) ;
break;
case V_97 :
V_2 -> V_31 = 1 ;
V_2 -> V_45 = 1 ;
V_2 -> V_46 = 0x20 ;
V_2 -> V_47 = 0 ;
V_2 -> V_48 = 0x08 ;
V_2 -> V_49 = 0x10 ;
V_2 -> V_50 = 0x38 ;
break;
case V_98 :
case V_99 :
F_35 ( V_2 ) ;
break;
case V_100 :
if ( V_2 -> V_5 == 0x3002144f ) {
V_2 -> V_31 = 1 ;
F_2 ( L_37 , V_2 -> V_6 . V_13 ) ;
}
break;
case V_101 :
if ( V_2 -> V_5 == 0x3060121a ) {
V_2 -> V_31 = 0 ;
V_2 -> V_35 = V_102 ;
}
break;
case V_103 :
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
F_30 ( V_2 , V_25 , 0xa0 ) ;
F_36 ( V_2 , V_25 ) ;
break;
case V_115 :
F_11 ( V_2 ) ;
break;
case V_26 :
F_30 ( V_2 , V_25 , 0xa0 ) ;
F_37 ( V_2 ) ;
break;
case V_116 :
F_19 ( V_2 ) ;
break;
case V_117 :
F_38 ( V_2 ) ;
break;
case V_118 :
F_39 ( V_2 ) ;
break;
case V_119 :
F_40 ( V_2 ) ;
break;
}
if ( ! ( V_2 -> V_11 == 848 && V_2 -> V_120 == 0x11 ) ) {
if ( V_121 == V_19 [ V_2 -> V_6 . type ] . V_122 ) {
V_2 -> V_122 . V_123 = 28636363 ;
V_2 -> V_122 . V_124 = V_125 ;
}
if ( V_126 == V_19 [ V_2 -> V_6 . type ] . V_122 ) {
V_2 -> V_122 . V_123 = 35468950 ;
V_2 -> V_122 . V_124 = V_127 ;
}
switch ( V_122 [ V_2 -> V_6 . V_13 ] ) {
case 0 :
V_2 -> V_122 . V_124 = 0 ;
V_2 -> V_122 . V_123 = 0 ;
V_2 -> V_122 . V_128 = 0 ;
break;
case 1 :
case 28 :
V_2 -> V_122 . V_123 = 28636363 ;
V_2 -> V_122 . V_128 = 0 ;
V_2 -> V_122 . V_124 = V_125 ;
break;
case 2 :
case 35 :
V_2 -> V_122 . V_123 = 35468950 ;
V_2 -> V_122 . V_128 = 0 ;
V_2 -> V_122 . V_124 = V_127 ;
break;
}
}
V_2 -> V_122 . V_129 = - 1 ;
if ( V_20 != V_19 [ V_2 -> V_6 . type ] . V_35 )
if ( V_20 == V_2 -> V_35 )
V_2 -> V_35 = V_19 [ V_2 -> V_6 . type ] . V_35 ;
if ( V_20 != V_130 [ V_2 -> V_6 . V_13 ] )
V_2 -> V_35 = V_130 [ V_2 -> V_6 . V_13 ] ;
if ( V_2 -> V_35 == V_37 )
F_2 ( V_12 L_38 , V_2 -> V_6 . V_13 ) ;
else if( V_2 -> V_35 == V_20 )
F_2 ( V_131 L_39 , V_2 -> V_6 . V_13 ) ;
else
F_2 ( V_12 L_40 , V_2 -> V_6 . V_13 ,
V_2 -> V_35 ) ;
if ( V_132 != V_20 ) {
F_2 ( V_131 L_41 , V_2 -> V_6 . V_13 ) ;
F_2 ( V_131 L_42 , V_2 -> V_6 . V_13 ) ;
F_2 ( V_131 L_43 , V_2 -> V_6 . V_13 ) ;
}
if ( V_20 == V_2 -> V_35 )
V_2 -> V_35 = V_37 ;
V_2 -> V_133 = V_19 [ V_2 -> V_6 . type ] . V_134 ?
V_19 [ V_2 -> V_6 . type ] . V_135 - 1 : V_20 ;
V_2 -> V_136 = V_19 [ V_2 -> V_6 . type ] . V_136 == V_137 ?
V_20 : V_19 [ V_2 -> V_6 . type ] . V_136 ;
if ( V_136 [ V_2 -> V_6 . V_13 ] != V_20 )
V_2 -> V_136 = V_136 [ V_2 -> V_6 . V_13 ] ;
if ( V_138 [ V_2 -> V_6 . V_13 ] != V_20 )
V_2 -> V_30 = V_138 [ V_2 -> V_6 . V_13 ] ;
if ( V_19 [ V_2 -> V_6 . type ] . V_31 )
V_2 -> V_31 = 1 ;
if ( V_19 [ V_2 -> V_6 . type ] . V_30 )
V_2 -> V_30 = 1 ;
if ( ! V_19 [ V_2 -> V_6 . type ] . V_139 )
V_2 -> V_140 = 1 ;
if ( V_19 [ V_2 -> V_6 . type ] . V_141 )
V_2 -> V_141 = V_19 [ V_2 -> V_6 . type ] . V_141 ;
if ( V_19 [ V_2 -> V_6 . type ] . V_38 )
V_2 -> V_38 = V_19 [ V_2 -> V_6 . type ] . V_38 ;
if ( V_2 -> V_35 == V_37 )
return;
if ( V_2 -> V_142 || V_143 [ V_2 -> V_6 . V_13 ] ) {
static const unsigned short V_144 [] = {
0x20 >> 1 ,
0x22 >> 1 ,
V_145
} ;
struct V_146 * V_147 ;
V_147 = F_41 ( & V_2 -> V_6 . V_148 ,
& V_2 -> V_6 . V_149 , L_44 , 0 , V_144 ) ;
V_2 -> V_142 = ( V_147 != NULL ) ;
}
switch ( V_150 [ V_2 -> V_6 . V_13 ] ) {
case - 1 :
return;
case 0 :
break;
case 1 : {
static const unsigned short V_144 [] = {
V_42 >> 1 ,
V_151 >> 1 ,
V_145
} ;
V_2 -> V_152 = F_41 ( & V_2 -> V_6 . V_148 ,
& V_2 -> V_6 . V_149 , L_45 , 0 , V_144 ) ;
if ( V_2 -> V_152 )
return;
goto V_153;
}
case 2 : {
static const unsigned short V_144 [] = {
V_154 >> 1 ,
V_145
} ;
if ( F_41 ( & V_2 -> V_6 . V_148 ,
& V_2 -> V_6 . V_149 , L_46 , 0 , V_144 ) )
return;
goto V_153;
}
case 3 : {
V_2 -> V_155 = F_41 ( & V_2 -> V_6 . V_148 ,
& V_2 -> V_6 . V_149 , L_47 , 0 , F_42 () ) ;
if ( V_2 -> V_155 )
return;
goto V_153;
}
default:
F_2 ( V_131 L_48 ,
V_2 -> V_6 . V_13 ) ;
return;
}
if ( ! V_19 [ V_2 -> V_6 . type ] . V_156 ) {
V_2 -> V_152 = F_41 ( & V_2 -> V_6 . V_148 ,
& V_2 -> V_6 . V_149 , L_45 ,
0 , F_43 ( V_42 >> 1 ) ) ;
} else if ( V_19 [ V_2 -> V_6 . type ] . V_157 ) {
V_2 -> V_152 = F_41 ( & V_2 -> V_6 . V_148 ,
& V_2 -> V_6 . V_149 , L_45 ,
0 , F_43 ( V_151 >> 1 ) ) ;
}
if ( V_2 -> V_152 )
return;
if ( ! V_19 [ V_2 -> V_6 . type ] . V_158 ) {
static const unsigned short V_144 [] = {
V_154 >> 1 ,
V_145
} ;
if ( F_41 ( & V_2 -> V_6 . V_148 ,
& V_2 -> V_6 . V_149 , L_46 , 0 , V_144 ) )
return;
}
V_2 -> V_155 = F_41 ( & V_2 -> V_6 . V_148 ,
& V_2 -> V_6 . V_149 , L_47 , 0 , F_42 () ) ;
if ( V_2 -> V_155 )
return;
V_153:
F_2 ( V_131 L_49 ,
V_2 -> V_6 . V_13 ) ;
}
void T_1 F_44 ( struct V_1 * V_2 )
{
int V_159 = V_160 ;
if ( V_160 != V_19 [ V_2 -> V_6 . type ] . V_161 )
V_159 = V_19 [ V_2 -> V_6 . type ] . V_161 ;
if ( V_2 -> V_35 != V_37 ) {
struct V_162 V_163 ;
if ( V_19 [ V_2 -> V_6 . type ] . V_31 )
F_41 ( & V_2 -> V_6 . V_148 ,
& V_2 -> V_6 . V_149 , L_50 ,
0 , F_45 ( V_164 ) ) ;
F_41 ( & V_2 -> V_6 . V_148 ,
& V_2 -> V_6 . V_149 , L_50 ,
0 , F_45 ( V_165 ) ) ;
F_41 ( & V_2 -> V_6 . V_148 ,
& V_2 -> V_6 . V_149 , L_50 ,
0 , F_45 ( V_166 ) ) ;
V_163 . V_167 = V_168 ;
V_163 . type = V_2 -> V_35 ;
V_163 . V_159 = V_159 ;
if ( V_19 [ V_2 -> V_6 . type ] . V_31 )
V_163 . V_167 |= V_169 ;
F_46 ( V_2 , V_130 , V_170 , & V_163 ) ;
}
if ( V_2 -> V_55 ) {
struct V_171 V_172 ;
V_172 . V_130 = V_173 ;
V_172 . V_174 = & V_2 -> V_55 ;
F_46 ( V_2 , V_130 , V_175 , & V_172 ) ;
}
}
static void F_37 ( struct V_1 * V_2 )
{
if( strncmp ( & ( V_25 [ 0x1e ] ) , L_51 , 14 ) == 0 ) {
V_2 -> V_35 = V_176 ;
F_2 ( L_52 ,
V_2 -> V_6 . V_13 , & V_25 [ 0x1e ] ) ;
} else if ( strncmp ( & ( V_25 [ 0x1e ] ) , L_53 , 10 ) == 0 ) {
V_2 -> V_35 = V_177 ;
F_2 ( L_52 ,
V_2 -> V_6 . V_13 , & V_25 [ 0x1e ] ) ;
} else if ( strncmp ( & ( V_25 [ 0x1e ] ) , L_54 , 14 ) == 0 ) {
V_2 -> V_35 = V_178 ;
F_2 ( L_52 ,
V_2 -> V_6 . V_13 , & V_25 [ 0x1e ] ) ;
} else {
F_2 ( L_55 ,
V_2 -> V_6 . V_13 , & V_25 [ 0x1e ] ) ;
}
}
static void T_1 F_31 ( struct V_1 * V_2 )
{
struct V_179 V_180 ;
F_47 ( & V_2 -> V_181 , & V_180 , V_25 ) ;
V_2 -> V_35 = V_180 . V_35 ;
V_2 -> V_31 = V_180 . V_31 ;
F_2 ( L_56 ,
V_2 -> V_6 . V_13 , V_180 . V_182 ) ;
if( V_180 . V_182 == 64900 ) {
F_2 ( L_57 ,
V_2 -> V_6 . V_13 ,
V_19 [ V_2 -> V_6 . type ] . V_14 ,
V_19 [ V_183 ] . V_14 ) ;
V_2 -> V_6 . type = V_183 ;
}
}
static int F_35 ( struct V_1 * V_2 )
{
int V_184 ;
V_2 -> V_31 = 1 ;
V_2 -> V_45 = 1 ;
V_2 -> V_46 = 0x10 ;
V_2 -> V_47 = 0x20 ;
V_2 -> V_48 = 0x08 ;
V_2 -> V_49 = 0x04 ;
V_2 -> V_50 = 0x3c ;
V_2 -> V_185 = 1 << 8 ;
V_2 -> V_186 = 1 << 9 ;
V_2 -> V_187 = 1 << 10 ;
V_184 = 88000 / 62.5 ;
F_48 ( V_2 , 5 * V_184 + 0x358 ) ;
if ( 0x1ed8 == F_49 ( V_2 ) ) {
F_2 ( L_58 ,
V_2 -> V_6 . V_13 ) ;
V_2 -> V_31 = 1 ;
V_2 -> V_142 = 1 ;
V_2 -> V_45 = 1 ;
} else {
V_2 -> V_31 = 0 ;
V_2 -> V_45 = 0 ;
}
return 0 ;
}
static int T_1 F_50 ( struct V_1 * V_2 , const T_2 * V_188 ,
T_3 V_189 )
{
T_3 V_190 ;
T_2 V_191 ;
int V_4 ;
F_6 ( 0xffffff , V_192 | V_193 | V_194 ) ;
F_12 ( 0 ) ;
F_7 ( V_195 ) ;
F_12 ( V_194 ) ;
F_7 ( V_195 ) ;
for ( V_190 = 0 ; V_190 < V_189 ; V_190 ++ ) {
V_191 = V_188 [ V_190 ] ;
for ( V_4 = 0 ; V_4 < 8 ; V_4 ++ ) {
F_13 ( V_193 , 0 ) ;
if ( V_191 & 0x01 )
F_13 ( V_192 , V_192 ) ;
else
F_13 ( V_192 , 0 ) ;
F_13 ( V_193 , V_193 ) ;
V_191 >>= 1 ;
}
}
F_13 ( V_193 , 0 ) ;
F_7 ( V_195 ) ;
for ( V_4 = 0 ; V_4 < 30 ; V_4 ++ ) {
F_13 ( V_193 , 0 ) ;
F_13 ( V_193 , V_193 ) ;
}
F_13 ( V_193 , 0 ) ;
return 0 ;
}
static int T_1 F_27 ( struct V_1 * V_2 )
{
const struct V_196 * V_197 ;
int V_198 ;
V_198 = F_51 ( & V_197 , L_59 , & V_2 -> V_6 . V_7 -> V_199 ) ;
if ( V_198 != 0 ) {
F_2 ( V_131 L_60 ,
V_2 -> V_6 . V_13 ) ;
return V_198 ;
}
V_198 = F_50 ( V_2 , V_197 -> V_200 , V_197 -> V_201 ) ;
F_2 ( V_12 L_61 ,
V_2 -> V_6 . V_13 , ( V_198 < 0 ) ? L_62 : L_63 ) ;
F_52 ( V_197 ) ;
return V_198 ;
}
static void T_1 F_36 ( struct V_1 * V_2 , const T_2 V_202 [ 256 ] )
{
int V_4 ;
T_3 V_203 = 0 ;
int V_5 = - 1 ;
if ( V_2 -> V_6 . type == V_82 ) {
if ( ! strncmp ( V_202 , L_64 , 4 ) ) {
T_2 V_204 = 0 ;
for ( V_4 = 0 ; V_4 < 21 ; V_4 ++ )
V_204 += V_202 [ V_4 ] ;
if ( V_204 != V_202 [ 21 ] )
return;
V_5 = V_104 ;
for ( V_4 = 12 ; V_4 < 21 ; V_4 ++ )
V_203 *= 10 , V_203 += V_202 [ V_4 ] - '0' ;
}
} else {
unsigned short type ;
for ( V_4 = 4 * 16 ; V_4 < 8 * 16 ; V_4 += 16 ) {
T_4 V_204 = F_53 ( V_202 + V_4 , 16 ) ;
if ( ( V_204 & 0xff ) + ( V_204 >> 8 ) == 0xff )
break;
}
if ( V_4 >= 8 * 16 )
return;
V_202 += V_4 ;
type = F_54 ( ( V_205 * ) ( V_202 + 4 ) ) ;
switch( type ) {
case 0x0004 :
V_5 = V_104 ;
break;
case 0x0005 :
V_5 = V_105 ;
break;
case 0x0012 :
case 0x0013 :
V_5 = V_103 ;
break;
case 0x0014 :
case 0x0015 :
V_5 = V_106 ;
break;
case 0x0016 :
case 0x0017 :
case 0x0020 :
V_5 = V_107 ;
break;
case 0x0018 :
case 0x0019 :
case 0x001E :
case 0x001F :
V_5 = V_108 ;
break;
case 0x001A :
case 0x001B :
V_5 = V_109 ;
break;
case 0x0040 :
V_5 = V_112 ;
break;
case 0x0050 :
case 0x0056 :
V_5 = V_113 ;
break;
case 0x0060 :
case 0x0070 :
case 0x00A0 :
V_5 = V_110 ;
F_6 ( 0xffffff , 0x000303 ) ;
break;
case 0x00D8 :
V_5 = V_111 ;
break;
default:
F_2 ( V_12 L_65
L_66 ,
V_2 -> V_6 . V_13 , type ) ;
break;
}
V_203 = F_55 ( ( V_206 * ) ( V_202 + 6 ) ) ;
}
F_2 ( V_12 L_67 ,
V_2 -> V_6 . V_13 , V_5 ,
V_5 > 0 ? V_19 [ V_5 ] . V_14 : L_68 , V_203 ) ;
if ( V_5 < 0 || V_2 -> V_6 . type == V_5 )
return;
if ( V_17 [ V_2 -> V_6 . V_13 ] < V_18 ) {
F_2 ( V_131 L_69
L_70 , V_2 -> V_6 . V_13 ) ;
} else {
F_2 ( V_12 L_69
L_71 , V_2 -> V_6 . V_13 ,
V_2 -> V_6 . type , V_5 ) ;
V_2 -> V_6 . type = V_5 ;
}
}
static void T_1 F_32 ( struct V_1 * V_2 )
{
int V_207 , V_208 , V_209 , V_35 = 0 ;
V_207 = ( V_25 [ 0x41 ] & 0x7 ) ;
V_208 = ( V_25 [ 0x41 ] & 0x18 ) >> 3 ;
V_209 = ( V_25 [ 0x42 ] & 0xf0 ) >> 4 ;
V_2 -> V_30 = ( V_25 [ 0x42 ] & 0x01 ) ;
if ( V_207 == 0 || V_207 == 2 )
if ( V_209 <= 0x0a )
V_35 = V_210 [ V_209 ] ;
if ( V_207 == 1 )
if ( V_209 <= 9 )
V_35 = V_211 [ V_209 ] ;
if ( V_207 == 4 )
if ( V_209 == 0x09 )
V_35 = V_212 ;
F_2 ( V_12 L_72 ,
V_2 -> V_6 . V_13 , V_25 [ 0x41 ] , V_25 [ 0x42 ] ) ;
if ( V_35 ) {
V_2 -> V_35 = V_35 ;
F_2 ( V_213 L_73 , V_35 ) ;
} else
F_2 ( V_213 L_74 ) ;
F_2 ( V_213 L_75 ,
V_208 ? L_19 : L_24 ,
V_2 -> V_30 ? L_19 : L_24 ) ;
}
T_3 F_56 ( struct V_1 * V_2 , T_3 V_3 )
{
if ( V_2 -> V_214 == V_215 ) {
if ( V_216 [ V_2 -> V_217 ] . V_218 & V_219 )
V_3 |= 0x10000 ;
else
V_3 &= ~ 0x10000 ;
}
F_13 ( V_19 [ V_2 -> V_6 . type ] . V_24 , V_3 ) ;
return V_3 ;
}
static void T_1 F_26 ( struct V_1 * V_2 , int V_220 )
{
int V_221 = ( 1 << V_220 ) ;
F_6 ( V_221 , V_221 ) ;
F_13 ( V_221 , 0 ) ;
F_57 ( 2 ) ;
F_7 ( 500 ) ;
F_13 ( V_221 , V_221 ) ;
if ( V_222 )
F_58 ( V_2 , L_76 ) ;
if ( V_223 )
F_2 ( V_12 L_77
L_78 , V_2 -> V_6 . V_13 , V_220 ) ;
}
static void T_1 F_33 ( struct V_1 * V_2 )
{
static int V_224 [] V_225 = { 0x08 , 0x09 , 0x0a , 0x0b , 0x0d , 0x0d ,
0x01 , 0x02 , 0x03 , 0x04 , 0x05 , 0x06 ,
0x00 } ;
unsigned int V_4 ;
int V_226 ;
T_3 V_227 ;
F_6 ( 0xffffff , ( 1 << 13 ) ) ;
F_12 ( 0 ) ;
F_7 ( 3 ) ;
F_12 ( 1 << 13 ) ;
F_13 ( 0xffffff , 0 ) ;
if ( V_222 )
F_58 ( V_2 , L_79 ) ;
F_20 ( V_228 | V_229 , V_63 ) ;
F_2 ( V_12 L_80 ) ;
F_59 ( V_2 , 0x5E , 0 , 0x80 , 1 ) ;
F_2 ( V_12 L_81 ) ;
V_227 = F_60 ( V_230 ) ;
V_227 |= V_231 ;
F_20 ( V_227 , V_230 ) ;
F_6 ( 0xffffff , ( 1 << 2 ) ) ;
F_12 ( 0 ) ;
F_7 ( 10 ) ;
F_12 ( 1 << 2 ) ;
for ( V_4 = 0 ; V_4 < F_3 ( V_224 ) ; V_4 ++ ) {
V_226 = F_59 ( V_2 , 0x1E , 0 , V_224 [ V_4 ] , 1 ) ;
if ( V_226 != - 1 ) {
F_2 ( V_12
L_82 ,
V_224 [ V_4 ] , V_226 , F_10 ( V_2 , 0x1F , NULL ) ) ;
}
}
F_2 ( V_12 L_83 ) ;
}
static void
F_28 ( struct V_1 * V_2 )
{
T_5 V_232 = 0 ;
long V_233 = 0x0E ;
F_2 ( V_12
L_84 ,
V_2 -> V_6 . V_13 ) ;
F_20 ( 0x00c3feff , V_234 ) ;
F_20 ( 0 + V_233 , V_235 ) ;
F_61 ( 1 ) ;
F_20 ( 0x10 + V_233 , V_235 ) ;
F_61 ( 10 ) ;
F_20 ( 0 + V_233 , V_235 ) ;
V_232 = F_60 ( V_235 ) ;
if ( ( ( ( V_232 >> 18 ) & 0x01 ) != 0 ) || ( ( ( V_232 >> 19 ) & 0x01 ) != 1 ) ) {
F_2 ( V_12
L_85 ,
V_2 -> V_6 . V_13 , V_232 ) ;
}
F_20 ( 0x4400 + V_233 , V_235 ) ;
F_61 ( 10 ) ;
F_20 ( 0x4410 + V_233 , V_235 ) ;
F_61 ( 1 ) ;
F_20 ( V_233 , V_235 ) ;
F_61 ( 1 ) ;
V_232 = F_60 ( V_235 ) ;
if ( ( ( ( V_232 >> 18 ) & 0x01 ) != 0 ) || ( ( ( V_232 >> 19 ) & 0x01 ) != 0 ) ) {
F_2 ( V_12
L_86 ,
V_2 -> V_6 . V_13 , V_232 ) ;
return;
}
F_2 ( V_12
L_87 , V_2 -> V_6 . V_13 ) ;
}
static void F_62 ( struct V_1 * V_2 , int V_236 )
{
if ( V_2 -> V_186 ) {
F_13 ( V_2 -> V_186 | V_2 -> V_185 | V_2 -> V_187 ,
V_2 -> V_186 | V_2 -> V_185 | V_2 -> V_187 ) ;
F_7 ( 5 ) ;
}
F_13 ( V_236 , 0 ) ;
F_7 ( 5 ) ;
if ( V_2 -> V_186 ) {
F_13 ( V_2 -> V_185 | V_2 -> V_187 , 0 ) ;
F_7 ( 5 ) ;
}
}
static void F_63 ( struct V_1 * V_2 , int V_236 )
{
if ( V_2 -> V_186 ) {
F_13 ( V_2 -> V_186 | V_2 -> V_185 | V_2 -> V_187 ,
V_2 -> V_186 | V_2 -> V_185 | V_2 -> V_187 ) ;
F_7 ( 5 ) ;
}
F_13 ( V_236 , V_236 ) ;
F_7 ( 5 ) ;
if ( V_2 -> V_186 ) {
F_13 ( V_2 -> V_185 | V_2 -> V_187 , 0 ) ;
F_7 ( 5 ) ;
}
}
static int F_64 ( struct V_1 * V_2 , int V_236 )
{
if ( V_2 -> V_186 ) {
F_13 ( V_2 -> V_186 | V_2 -> V_185 | V_2 -> V_187 ,
V_2 -> V_186 | V_2 -> V_185 | V_2 -> V_187 ) ;
F_7 ( 5 ) ;
F_13 ( V_2 -> V_185 | V_2 -> V_187 , 0 ) ;
F_7 ( 5 ) ;
}
return F_8 () & ( V_236 ) ;
}
static int F_49 ( struct V_1 * V_2 )
{
unsigned long V_237 ;
int V_238 = 0 ;
int V_4 ;
F_6 ( V_2 -> V_50 , V_2 -> V_48 | V_2 -> V_46 ) ;
if ( V_2 -> V_186 ) {
F_13 ( V_2 -> V_186 | V_2 -> V_185 | V_2 -> V_187 ,
V_2 -> V_186 | V_2 -> V_185 | V_2 -> V_187 ) ;
F_7 ( 5 ) ;
}
if ( V_222 )
F_58 ( V_2 , L_88 ) ;
F_62 ( V_2 , V_2 -> V_46 ) ;
F_62 ( V_2 , V_2 -> V_48 ) ;
F_7 ( 10 ) ;
V_237 = V_239 + F_65 ( 1000 ) ;
while ( F_64 ( V_2 , V_2 -> V_49 ) && F_66 ( V_239 , V_237 ) )
F_67 () ;
if ( F_64 ( V_2 , V_2 -> V_49 ) ) {
F_2 ( V_131 L_89 , V_2 -> V_6 . V_13 ) ;
return - 1 ;
}
F_68 ( L_90 , V_2 -> V_6 . V_13 ) ;
for ( V_4 = 0 ; V_4 < 24 ; V_4 ++ ) {
F_7 ( 5 ) ;
F_63 ( V_2 , V_2 -> V_48 ) ;
F_7 ( 5 ) ;
F_68 ( L_91 , ( F_64 ( V_2 , V_2 -> V_47 ) == 0 ) ? 'T' : '-' ) ;
F_62 ( V_2 , V_2 -> V_48 ) ;
V_238 <<= 1 ;
V_238 |= ( F_64 ( V_2 , V_2 -> V_49 ) == 0 ) ? 0 : 1 ;
F_68 ( L_91 , ( F_64 ( V_2 , V_2 -> V_47 ) == 0 ) ? 'S' : 'M' ) ;
}
F_68 ( L_92 , V_2 -> V_6 . V_13 , V_238 ) ;
return V_238 ;
}
static int F_48 ( struct V_1 * V_2 , int V_238 )
{
int V_4 ;
int V_240 = V_238 ;
F_6 ( V_2 -> V_50 , V_2 -> V_48 | V_2 -> V_46 | V_2 -> V_49 ) ;
if ( V_2 -> V_186 ) {
F_13 ( V_2 -> V_186 | V_2 -> V_185 | V_2 -> V_187 ,
V_2 -> V_186 | V_2 -> V_185 | V_2 -> V_187 ) ;
F_7 ( 5 ) ;
}
if ( V_222 )
F_58 ( V_2 , L_93 ) ;
F_68 ( L_94 , V_2 -> V_6 . V_13 , V_238 ) ;
F_62 ( V_2 , V_2 -> V_48 ) ;
F_63 ( V_2 , V_2 -> V_46 ) ;
for ( V_4 = 0 ; V_4 < 25 ; V_4 ++ ) {
if ( V_240 & 0x1000000 )
F_63 ( V_2 , V_2 -> V_49 ) ;
else
F_62 ( V_2 , V_2 -> V_49 ) ;
V_240 <<= 1 ;
F_63 ( V_2 , V_2 -> V_48 ) ;
F_7 ( 10 ) ;
F_62 ( V_2 , V_2 -> V_48 ) ;
F_7 ( 10 ) ;
}
F_62 ( V_2 , V_2 -> V_46 ) ;
return 0 ;
}
void F_69 ( struct V_1 * V_2 , unsigned short V_184 )
{
F_68 ( L_95 , V_184 ) ;
F_48 ( V_2 , 5 * V_184 + 0x358 ) ;
}
static void F_70 ( struct V_1 * V_2 , unsigned int V_61 )
{
static const T_2 V_241 [] = { 0x3 , 0x1 , 0x2 , 0x4 , 0xf , 0x7 , 0xe , 0x0 ,
0xd , 0xb , 0xc , 0x6 , 0x9 , 0x5 , 0x8 , 0xa } ;
F_13 ( 0x07f , V_241 [ V_61 ] ) ;
F_13 ( 0x200 , 0x200 ) ;
F_57 ( 1 ) ;
F_13 ( 0x200 , 0x000 ) ;
F_57 ( 1 ) ;
F_13 ( 0x480 , 0x480 ) ;
F_57 ( 1 ) ;
F_13 ( 0x480 , 0x080 ) ;
F_57 ( 1 ) ;
}
static void F_71 ( struct V_1 * V_2 , unsigned int V_61 )
{
F_13 ( 0x0f0000 , V_61 << 16 ) ;
}
static void F_38 ( struct V_1 * V_2 )
{
F_6 ( 0xffffff , 0x0f7fff ) ;
F_12 ( 0x0f7fff ) ;
}
static void F_72 ( struct V_1 * V_2 ,
unsigned char V_242 ,
unsigned char V_243 ,
unsigned char V_200 ) {
unsigned int V_244 ;
V_244 = ( V_200 << 7 ) | ( ( V_243 & 3 ) << 4 ) | ( V_242 & 0xf ) ;
F_13 ( 0x1ff , V_244 ) ;
F_13 ( 0x1ff , V_244 | ( 1 << 8 ) ) ;
F_13 ( 0x1ff , V_244 ) ;
}
static void F_73 ( struct V_1 * V_2 , unsigned int V_61 )
{
char * V_245 ;
int V_242 , V_243 ;
struct V_1 * V_246 ;
static unsigned char V_247 [ 4 ] = { 3 , 0 , 2 , 1 } ;
V_246 = V_248 [ V_2 -> V_6 . V_13 ] ;
if ( V_246 == NULL ) {
return;
}
V_243 = ( V_2 -> V_6 . V_13 - V_246 -> V_6 . V_13 + 1 ) & 3 ;
V_243 = V_247 [ V_243 ] ;
V_245 = ( char * ) ( & V_246 -> V_46 ) ;
V_242 = V_61 & 0xf ;
if ( V_245 [ V_243 ] != V_242 )
{
F_72 ( V_246 , V_245 [ V_243 ] , V_243 , 0 ) ;
V_245 [ V_243 ] = V_242 ;
F_72 ( V_246 , V_242 , V_243 , 1 ) ;
}
}
static void F_39 ( struct V_1 * V_2 )
{
char * V_245 = ( char * ) ( & V_2 -> V_46 ) ;
int V_249 ;
F_6 ( 0x0003ff , 0x0003ff ) ;
F_12 ( 1 << 9 ) ;
F_12 ( 0 ) ;
for ( V_249 = 0 ; V_249 < 4 ; V_249 ++ ) {
V_245 [ V_249 ] = V_249 ;
F_72 ( V_2 , V_249 , V_249 , 1 ) ;
}
if ( ( V_2 -> V_6 . V_13 < 1 ) || ( V_2 -> V_6 . V_13 > V_250 - 3 ) )
return;
V_248 [ V_2 -> V_6 . V_13 - 1 ] = V_2 ;
V_248 [ V_2 -> V_6 . V_13 ] = V_2 ;
V_248 [ V_2 -> V_6 . V_13 + 1 ] = V_2 ;
V_248 [ V_2 -> V_6 . V_13 + 2 ] = V_2 ;
}
static void F_74 ( struct V_1 * V_2 , unsigned int V_61 )
{
static const int V_67 [] = {
V_251 , V_251 | V_252 , V_251 | V_253 , V_251 | V_252 | V_253 ,
V_254 , V_254 | V_252 , V_254 | V_253 , V_254 | V_252 | V_253 ,
V_255 , V_255 | V_256 , V_255 | V_257 , V_255 | V_256 | V_257 ,
V_258 , V_258 | V_256 , V_258 | V_257 , V_258 | V_256 | V_257 ,
} ;
F_12 ( V_67 [ V_61 % 16 ] ) ;
}
static void F_34 ( struct V_1 * V_2 )
{
F_20 ( 0x08 << 16 , V_235 ) ;
F_20 ( 0x04 << 16 , V_235 ) ;
}
static void F_75 ( struct V_1 * V_2 , unsigned int V_61 )
{
F_68 ( V_16 L_96 , V_2 -> V_6 . V_13 , V_61 ) ;
F_20 ( V_61 << 20 , V_235 ) ;
}
static void F_76 ( struct V_1 * V_2 , unsigned int V_61 )
{
int V_259 = V_61 % 4 ;
int V_260 = V_61 / 4 ;
F_68 ( L_97 ,
V_2 -> V_6 . V_13 , V_61 , V_260 , V_259 ) ;
F_59 ( V_2 , V_261 , 0x00 ,
( ( V_260 == 3 ) ? ( V_259 | V_259 << 2 ) : 0x00 ) , 1 ) ;
F_59 ( V_2 , V_262 , 0x00 ,
( ( V_260 == 0 ) ? ( V_259 | V_259 << 2 ) : 0x00 ) , 1 ) ;
F_59 ( V_2 , V_263 , 0x00 ,
( ( V_260 == 1 ) ? ( V_259 | V_259 << 2 ) : 0x00 ) , 1 ) ;
F_59 ( V_2 , V_264 , 0x00 ,
( ( V_260 == 2 ) ? ( V_259 | V_259 << 2 ) : 0x00 ) , 1 ) ;
F_59 ( V_2 , V_261 , 0x02 ,
( ( V_260 == 3 ) ? 0x03 : 0x00 ) , 1 ) ;
F_59 ( V_2 , V_262 , 0x02 ,
( ( V_260 == 0 ) ? 0x03 : 0x00 ) , 1 ) ;
F_59 ( V_2 , V_263 , 0x02 ,
( ( V_260 == 1 ) ? 0x03 : 0x00 ) , 1 ) ;
F_59 ( V_2 , V_264 , 0x02 ,
( ( V_260 == 2 ) ? 0x03 : 0x00 ) , 1 ) ;
}
static void F_77 ( struct V_1 * V_2 , unsigned int V_61 )
{
int V_198 ;
long V_265 ;
int V_266 ;
unsigned char V_267 [ 2 ] ;
V_267 [ 0 ] = 0 ;
V_267 [ 1 ] = 0 ;
V_198 = F_59 ( V_2 , ( V_268 << 1 ) , V_267 [ 0 ] , V_267 [ 1 ] , 1 ) ;
if ( V_198 ) {
F_2 ( V_16 L_98 , V_2 -> V_6 . V_13 , V_198 ) ;
return;
}
V_198 = F_10 ( V_2 , ( V_268 << 1 ) , NULL ) ;
if ( ! ( V_198 & V_269 ) ) {
F_2 ( V_16 L_99 , V_2 -> V_6 . V_13 , V_198 ) ;
return;
}
V_265 = V_61 ;
V_266 = 0x302 ;
if ( V_2 -> V_5 == V_270 ) {
V_266 ^= 0x180 ;
V_266 |= 7 << 4 ;
}
F_20 ( V_266 , V_234 ) ;
V_266 = F_60 ( V_235 ) ;
if ( V_2 -> V_5 == V_270 )
V_266 = ( V_266 & ~ 0x280 ) | ( ( V_265 & 2 ) << 8 ) | ( ( V_265 & 1 ) << 7 ) ;
else
V_266 = ( V_266 & ~ 0x300 ) | ( ( V_265 & 3 ) << 8 ) ;
F_20 ( V_266 , V_235 ) ;
if ( V_2 -> V_5 == V_270 )
F_14 ( 2 << 5 , ~ V_271 , V_60 ) ;
else
F_17 ( ~ V_271 , V_60 ) ;
F_2 ( V_16 L_100 , V_2 -> V_6 . V_13 , ( int ) V_265 ) ;
}
static void F_78 ( struct V_1 * V_2 , unsigned int V_61 )
{
unsigned int V_265 = V_61 % 4 ;
if ( V_61 == V_2 -> V_136 )
V_265 = 0 ;
F_13 ( 0x3 , V_265 ) ;
}
static void F_79 ( struct V_1 * V_2 ,
unsigned char V_242 ,
unsigned char V_243 ,
unsigned char V_200 ) {
const T_3 V_272 = ( ( V_242 & 0xf ) | ( V_243 & 3 ) << 4 ) ;
const T_3 V_273 = 1 << 16 ;
const T_3 V_274 = 1 << 17 ;
const T_3 V_275 = V_200 << 18 ;
F_13 ( 0x1007f , V_272 | V_273 ) ;
F_13 ( 0x20000 , V_274 ) ;
F_13 ( 0x40000 , V_275 ) ;
F_13 ( 0x20000 , ~ V_274 ) ;
}
static void F_80 ( struct V_1 * V_2 , unsigned int V_61 )
{
struct V_1 * V_246 ;
char * V_245 ;
int V_242 , V_243 ;
static unsigned int V_247 [ 4 ] [ 4 ] = { { 0x0 , 0x4 , 0xa , 0x6 } ,
{ 0x1 , 0x5 , 0xb , 0x7 } ,
{ 0x2 , 0x8 , 0xc , 0xe } ,
{ 0x3 , 0x9 , 0xd , 0xf } } ;
V_61 = V_61 % 4 ;
V_246 = V_248 [ V_2 -> V_6 . V_13 ] ;
if ( V_246 == NULL ) {
return;
}
V_243 = ( V_2 -> V_6 . V_13 - V_246 -> V_6 . V_13 ) & 3 ;
V_245 = ( char * ) ( & V_246 -> V_46 ) ;
V_242 = V_247 [ V_243 ] [ V_61 ] & 0xf ;
if ( V_245 [ V_243 ] != V_242 ) {
F_79 ( V_246 , V_245 [ V_243 ] , V_243 , 0 ) ;
V_245 [ V_243 ] = V_242 ;
F_79 ( V_246 , V_242 , V_243 , 1 ) ;
}
}
static void F_40 ( struct V_1 * V_2 )
{
char * V_245 = ( char * ) ( & V_2 -> V_46 ) ;
int V_249 ;
F_6 ( 0xf107f , 0xf107f ) ;
F_12 ( 1 << 19 ) ;
F_12 ( 0 ) ;
for ( V_249 = 0 ; V_249 < 4 ; V_249 ++ ) {
V_245 [ V_249 ] = V_249 ;
F_79 ( V_2 , V_249 , V_249 , 1 ) ;
}
F_59 ( V_2 , 0x18 , 0x5 , 0x90 , 1 ) ;
if ( V_2 -> V_6 . V_13 > V_250 - 4 )
return;
V_248 [ V_2 -> V_6 . V_13 ] = V_2 ;
V_248 [ V_2 -> V_6 . V_13 + 1 ] = V_2 ;
V_248 [ V_2 -> V_6 . V_13 + 2 ] = V_2 ;
V_248 [ V_2 -> V_6 . V_13 + 3 ] = V_2 ;
}
void T_6 F_81 ( void )
{
int V_276 = 0 ;
struct V_277 * V_199 = NULL ;
if ( V_278 & ( V_279 | V_280 ) )
V_276 = 1 ;
if ( V_278 & ( V_281 | V_282 | V_283 ) )
V_284 = 1 ;
if ( V_278 & V_285 )
V_286 = 1 ;
#ifdef F_82
if ( V_278 & F_82 )
V_287 = 0x0A ;
#endif
if ( V_284 )
F_2 ( V_12 L_101 ) ;
if ( V_286 )
F_2 ( V_12 L_102 ) ;
if ( V_276 ) {
F_2 ( V_12 L_103
L_104 ) ;
if ( ! V_288 ) {
F_2 ( V_12 L_105 ) ;
V_288 = 1 ;
} else {
F_2 ( V_12 L_106
L_107 ) ;
}
}
if ( V_20 != V_287 )
F_2 ( V_12 L_108 , V_287 ) ;
while ( ( V_199 = F_83 ( V_289 ,
V_290 , V_199 ) ) ) {
unsigned char V_291 ;
F_84 ( V_199 , 0x53 , & V_291 ) ;
if ( V_70 )
F_2 ( V_12 L_109
L_110 , V_291 ) ;
}
}
int T_1 F_85 ( struct V_1 * V_2 )
{
unsigned char V_292 ;
if ( ! V_284 && ! V_286 && V_20 == V_287 )
return 0 ;
if ( V_223 ) {
if ( V_284 )
F_2 ( V_12 L_111 , V_2 -> V_6 . V_13 ) ;
if ( V_286 && V_2 -> V_11 >= 878 )
F_2 ( V_12 L_112 , V_2 -> V_6 . V_13 ) ;
if ( V_20 != V_287 )
F_2 ( V_12 L_113 ,
V_2 -> V_6 . V_13 , V_287 ) ;
}
if ( V_2 -> V_11 < 878 ) {
if ( V_284 )
V_2 -> V_284 = V_293 ;
} else {
F_84 ( V_2 -> V_6 . V_7 , V_294 , & V_292 ) ;
if ( V_284 )
V_292 |= V_295 ;
if ( V_286 )
V_292 |= V_296 ;
F_86 ( V_2 -> V_6 . V_7 , V_294 , V_292 ) ;
}
if ( V_20 != V_287 )
F_86 ( V_2 -> V_6 . V_7 , V_297 , V_287 ) ;
return 0 ;
}
