void F_1 ( struct V_1 * V_2 )
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
F_2 ( L_1 ,
V_2 -> V_6 . V_12 , V_10 [ type ] . V_13 , V_10 [ type ] . V_14 ,
V_2 -> V_5 & 0xffff ,
( V_2 -> V_5 >> 16 ) & 0xffff ) ;
V_2 -> V_6 . type = V_10 [ type ] . V_14 ;
} else {
F_2 ( L_2 ,
V_2 -> V_6 . V_12 , V_2 -> V_5 & 0xffff ,
( V_2 -> V_5 >> 16 ) & 0xffff ) ;
F_3 ( L_3 ) ;
}
}
if ( V_15 [ V_2 -> V_6 . V_12 ] < V_16 )
V_2 -> V_6 . type = V_15 [ V_2 -> V_6 . V_12 ] ;
F_2 ( L_4 ,
V_2 -> V_6 . V_12 , V_17 [ V_2 -> V_6 . type ] . V_13 , V_2 -> V_6 . type ,
V_15 [ V_2 -> V_6 . V_12 ] < V_16
? L_5 : L_6 ) ;
if ( V_18 == V_19 && V_18 == V_20 [ 0 ] )
return;
if ( V_18 != V_20 [ 0 ] ) {
V_3 = 0 ;
for ( V_4 = 0 ; V_4 < F_4 ( V_17 -> V_21 ) ; V_4 ++ ) {
V_17 [ V_2 -> V_6 . type ] . V_21 [ V_4 ] = V_20 [ V_4 ] ;
V_3 |= V_20 [ V_4 ] ;
}
} else {
V_3 = V_19 ;
for ( V_4 = 0 ; V_4 < F_4 ( V_17 -> V_21 ) ; V_4 ++ ) {
V_17 [ V_2 -> V_6 . type ] . V_21 [ V_4 ] = V_19 ;
}
}
V_17 [ V_2 -> V_6 . type ] . V_22 = ( V_18 != V_22 ) ? V_22 : V_3 ;
F_2 ( L_7 ,
V_2 -> V_6 . V_12 , V_17 [ V_2 -> V_6 . type ] . V_22 ) ;
for ( V_4 = 0 ; V_4 < F_4 ( V_17 -> V_21 ) ; V_4 ++ ) {
F_5 ( L_8 ,
V_4 ? L_9 : L_10 , V_17 [ V_2 -> V_6 . type ] . V_21 [ V_4 ] ) ;
}
F_5 ( L_11 ) ;
}
static void F_6 ( struct V_1 * V_2 , unsigned char V_23 [ 256 ] )
{
int type = - 1 ;
if ( 0 == strncmp ( V_23 , L_12 , 13 ) )
type = V_24 ;
else if ( 0 == strncmp ( V_23 + 20 , L_13 , 7 ) )
type = V_25 ;
else if ( V_23 [ 0 ] == 0x84 && V_23 [ 2 ] == 0 )
type = V_26 ;
if ( - 1 != type ) {
V_2 -> V_6 . type = type ;
F_2 ( L_14 ,
V_2 -> V_6 . V_12 , V_17 [ V_2 -> V_6 . type ] . V_13 , V_2 -> V_6 . type ) ;
}
}
static void F_7 ( struct V_1 * V_2 )
{
int V_27 , V_28 , V_29 , V_30 ;
int V_31 , V_32 ;
int V_33 = V_18 , V_34 ;
F_8 ( 0xffffff , 0 ) ;
F_9 ( 8 ) ;
V_27 = F_10 () ;
V_34 = ( V_27 & 0x0f0000 ) >> 16 ;
switch ( V_34 ) {
case 0x0 :
V_33 = 2 ;
break;
case 0x2 :
V_33 = 39 ;
break;
case 0x4 :
V_33 = 5 ;
break;
case 0x6 :
V_33 = 37 ;
break;
case 0xC :
V_33 = 3 ;
break;
default:
F_2 ( L_15 , V_2 -> V_6 . V_12 ) ;
break;
}
V_28 = V_27 & 0x800000 ;
V_29 = V_27 & 0x400000 ;
V_30 = ! ( V_27 & 0x008000 ) ;
V_32 = ! ( V_27 & 0x004000 ) ;
V_31 = ! ( V_27 & 0x002000 ) ;
if ( V_30 )
V_33 = V_35 ;
F_2 ( L_16 ,
V_2 -> V_6 . V_12 , V_29 ? L_17 : L_18 ,
V_28 ? L_17 : L_18 , V_33 , V_27 ) ;
F_2 ( L_19 ,
V_2 -> V_6 . V_12 , V_31 ? L_17 : L_18 ,
V_32 ? L_17 : L_18 ,
V_30 ? L_17 : L_18 ) ;
if ( V_33 != V_18 )
V_2 -> V_33 = V_33 ;
V_2 -> V_29 = V_29 ;
if ( V_32 )
V_2 -> V_36 = V_37 ;
}
static void F_11 ( struct V_1 * V_2 )
{
int V_11 , V_38 , V_27 ;
char * V_39 ;
F_8 ( 0xffffff , 0 ) ;
V_27 = F_10 () ;
V_11 = ( ( V_27 >> 10 ) & 63 ) - 1 ;
V_38 = F_12 ( V_2 , V_40 , L_20 ) ;
if ( V_11 < 32 ) {
V_2 -> V_33 = V_41 [ V_11 ] ;
if ( 0 == ( V_27 & 0x20 ) ) {
V_2 -> V_29 = 1 ;
if ( ! V_42 [ V_11 ] ) {
V_2 -> V_43 = 1 ;
V_2 -> V_44 = ( 1 << 6 ) ;
V_2 -> V_45 = ( 1 << 7 ) ;
V_2 -> V_46 = ( 1 << 8 ) ;
V_2 -> V_47 = ( 1 << 9 ) ;
V_2 -> V_48 = ( 1 << 6 ) | ( 1 << 7 ) | ( 1 << 8 ) | ( 1 << 9 ) ;
}
} else {
V_2 -> V_29 = 0 ;
}
if ( - 1 != V_38 ) {
if ( V_2 -> V_6 . type == V_49 )
V_2 -> V_6 . type = V_50 ;
if ( V_2 -> V_6 . type == V_51 )
V_2 -> V_6 . type = V_52 ;
}
F_2 ( L_21 ,
V_2 -> V_6 . V_12 , V_11 + 1 , V_2 -> V_33 ,
! V_2 -> V_29 ? L_18 :
( V_2 -> V_43 ? L_22 : L_23 ) ,
( - 1 == V_38 ) ? L_18 : L_17 ) ;
} else {
V_11 = 63 - V_11 ;
V_2 -> V_29 = 0 ;
switch ( V_11 ) {
case 1 :
V_39 = L_24 ;
V_2 -> V_53 = V_54 ;
break;
case 2 :
V_39 = L_25 ;
V_2 -> V_29 = 1 ;
V_2 -> V_53 = V_55 ;
break;
case 3 :
V_39 = L_26 ;
V_2 -> V_29 = 1 ;
V_2 -> V_53 = V_55 ;
break;
case 4 :
V_39 = L_27 ;
V_2 -> V_53 = V_55 ;
break;
case 5 :
V_39 = L_28 ;
V_2 -> V_53 = V_54 ;
break;
case 6 :
V_39 = L_26 ;
V_2 -> V_53 = V_54 ;
break;
case 7 :
V_39 = L_29 ;
V_2 -> V_53 = V_54 ;
break;
default:
V_39 = L_30 ;
break;
}
if ( - 1 != V_38 )
V_2 -> V_6 . type = V_52 ;
F_2 ( L_31 ,
V_2 -> V_6 . V_12 , V_11 , V_39 , V_2 -> V_29 ? L_17 : L_18 ) ;
V_2 -> V_33 = V_56 ;
}
}
static void F_13 ( struct V_1 * V_2 )
{
F_8 ( 0xffffff , 0xFFFF37 ) ;
F_14 ( 0x200020 ) ;
F_14 ( 0x200024 ) ;
F_15 ( V_57 , V_57 ) ;
F_16 ( ( 2 ) << 5 , ~ ( 2 << 5 ) , V_58 ) ;
}
static void F_17 ( struct V_1 * V_2 , unsigned int V_59 )
{
F_15 ( 3 , V_59 & 3 ) ;
F_18 ( V_60 , V_61 ) ;
F_19 ( ~ V_62 , V_63 ) ;
F_19 ( ~ V_62 , V_64 ) ;
F_15 ( V_57 , V_57 ) ;
}
static void F_20 ( struct V_1 * V_2 , unsigned int V_59 )
{
static const int V_65 [] = { 0x30 , 0x01 , 0x12 , 0x23 } ;
F_14 ( V_65 [ V_59 % 4 ] ) ;
}
static void F_21 ( struct V_1 * V_2 )
{
F_3 ( L_32 ) ;
F_22 ( 0x000000 , V_66 ) ;
F_8 ( 0xffffff , 0x0006C0 ) ;
F_14 ( 0x000000 ) ;
}
static void F_23 ( struct V_1 * V_2 , unsigned int V_59 )
{
unsigned int V_67 = V_59 % 8 ;
F_8 ( 0xf , 0xf ) ;
F_15 ( 0xf , V_67 ) ;
}
static void F_24 ( struct V_1 * V_2 , unsigned int V_59 )
{
unsigned int V_67 = V_59 % 4 ;
F_8 ( 3 << 9 , 3 << 9 ) ;
F_15 ( 3 << 9 , V_67 << 9 ) ;
}
static void F_25 ( struct V_1 * V_2 , unsigned int V_59 )
{
unsigned int V_67 = V_59 % 16 ;
F_8 ( 0xf , 0xf ) ;
F_15 ( 0xf , V_67 ) ;
}
static void F_26 ( struct V_1 * V_2 , T_1 V_68 )
{
F_15 ( ( 1 << 18 ) | 0xff , V_68 ) ;
F_15 ( ( 1 << 18 ) | 0xff , ( 1 << 18 ) | V_68 ) ;
F_9 ( 1 ) ;
F_15 ( ( 1 << 18 ) | 0xff , V_68 ) ;
}
static void F_27 ( struct V_1 * V_2 , unsigned int V_59 )
{
T_1 V_68 ;
T_1 V_69 ;
V_69 = ( V_59 & 0x8 ) >> 3 ;
V_68 = 0x11 ;
V_68 |= ( ( V_59 & 0x7 ) << 1 ) << ( 4 * V_69 ) ;
F_26 ( V_2 , V_68 ) ;
V_68 &= ~ 0x11 ;
V_68 |= ( ( V_69 ^ 0x1 ) << 4 ) | V_69 ;
F_26 ( V_2 , V_68 ) ;
}
static void F_28 ( struct V_1 * V_2 )
{
if ( V_2 -> V_11 != 878 )
return;
if ( V_70 )
F_3 ( L_33 , V_2 -> V_6 . V_12 ) ;
F_22 ( ( 1 << 7 ) , 0x058 ) ;
F_9 ( 10 ) ;
F_22 ( 0 , 0x058 ) ;
}
void F_29 ( struct V_1 * V_2 )
{
switch ( V_2 -> V_6 . type ) {
case V_26 :
case V_71 :
F_30 ( V_2 , 5 ) ;
break;
case V_72 :
case V_73 :
F_30 ( V_2 , 20 ) ;
break;
case V_74 :
F_30 ( V_2 , 11 ) ;
break;
case V_75 :
F_31 ( V_2 ) ;
break;
case V_76 :
case V_77 :
case V_78 :
V_2 -> V_79 = 1 ;
break;
case V_80 :
F_32 ( V_2 ) ;
break;
}
if ( ! V_17 [ V_2 -> V_6 . type ] . V_81 )
F_28 ( V_2 ) ;
}
void F_33 ( struct V_1 * V_2 )
{
V_2 -> V_33 = V_18 ;
if ( V_82 == V_2 -> V_6 . type ) {
F_34 ( V_2 , V_23 , 0xa0 ) ;
F_6 ( V_2 , V_23 ) ;
}
switch ( V_2 -> V_6 . type ) {
case V_49 :
case V_50 :
case V_51 :
case V_52 :
F_11 ( V_2 ) ;
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
F_7 ( V_2 ) ;
break;
case V_26 :
case V_71 :
case V_75 :
F_34 ( V_2 , V_23 , 0xa0 ) ;
F_35 ( V_2 ) ;
break;
case V_74 :
case V_94 :
F_34 ( V_2 , V_23 , 0xa0 ) ;
F_36 ( V_2 ) ;
break;
case V_95 :
F_37 ( V_2 ) ;
break;
case V_96 :
F_38 ( V_2 ) ;
break;
case V_97 :
V_2 -> V_29 = 1 ;
V_2 -> V_43 = 1 ;
V_2 -> V_44 = 0x20 ;
V_2 -> V_45 = 0 ;
V_2 -> V_46 = 0x08 ;
V_2 -> V_47 = 0x10 ;
V_2 -> V_48 = 0x38 ;
break;
case V_98 :
case V_99 :
F_39 ( V_2 ) ;
break;
case V_100 :
if ( V_2 -> V_5 == 0x3002144f ) {
V_2 -> V_29 = 1 ;
F_2 ( L_34 ,
V_2 -> V_6 . V_12 ) ;
}
break;
case V_101 :
if ( V_2 -> V_5 == 0x3060121a ) {
V_2 -> V_29 = 0 ;
V_2 -> V_33 = V_102 ;
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
F_34 ( V_2 , V_23 , 0xa0 ) ;
F_40 ( V_2 , V_23 ) ;
break;
case V_115 :
F_13 ( V_2 ) ;
break;
case V_24 :
F_34 ( V_2 , V_23 , 0xa0 ) ;
F_41 ( V_2 ) ;
break;
case V_116 :
F_21 ( V_2 ) ;
break;
case V_117 :
F_42 ( V_2 ) ;
break;
case V_118 :
F_43 ( V_2 ) ;
break;
case V_119 :
F_44 ( V_2 ) ;
break;
}
if ( ! ( V_2 -> V_11 == 848 && V_2 -> V_120 == 0x11 ) ) {
if ( V_121 == V_17 [ V_2 -> V_6 . type ] . V_122 ) {
V_2 -> V_122 . V_123 = 28636363 ;
V_2 -> V_122 . V_124 = V_125 ;
}
if ( V_126 == V_17 [ V_2 -> V_6 . type ] . V_122 ) {
V_2 -> V_122 . V_123 = 35468950 ;
V_2 -> V_122 . V_124 = V_127 ;
}
switch ( V_122 [ V_2 -> V_6 . V_12 ] ) {
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
if ( V_18 != V_17 [ V_2 -> V_6 . type ] . V_33 )
if ( V_18 == V_2 -> V_33 )
V_2 -> V_33 = V_17 [ V_2 -> V_6 . type ] . V_33 ;
if ( V_18 != V_130 [ V_2 -> V_6 . V_12 ] )
V_2 -> V_33 = V_130 [ V_2 -> V_6 . V_12 ] ;
if ( V_2 -> V_33 == V_35 )
F_2 ( L_35 , V_2 -> V_6 . V_12 ) ;
else if ( V_2 -> V_33 == V_18 )
F_45 ( L_36 , V_2 -> V_6 . V_12 ) ;
else
F_2 ( L_37 , V_2 -> V_6 . V_12 , V_2 -> V_33 ) ;
if ( V_131 != V_18 ) {
F_45 ( L_38 , V_2 -> V_6 . V_12 ) ;
F_45 ( L_39 ,
V_2 -> V_6 . V_12 ) ;
}
if ( V_18 == V_2 -> V_33 )
V_2 -> V_33 = V_35 ;
V_2 -> V_132 = V_17 [ V_2 -> V_6 . type ] . V_133 ?
V_17 [ V_2 -> V_6 . type ] . V_134 - 1 : V_18 ;
V_2 -> V_135 = V_17 [ V_2 -> V_6 . type ] . V_135 == V_136 ?
V_18 : V_17 [ V_2 -> V_6 . type ] . V_135 ;
if ( V_135 [ V_2 -> V_6 . V_12 ] != V_18 )
V_2 -> V_135 = V_135 [ V_2 -> V_6 . V_12 ] ;
if ( V_137 [ V_2 -> V_6 . V_12 ] != V_18 )
V_2 -> V_28 = V_137 [ V_2 -> V_6 . V_12 ] ;
if ( V_17 [ V_2 -> V_6 . type ] . V_29 )
V_2 -> V_29 = 1 ;
if ( V_17 [ V_2 -> V_6 . type ] . V_28 )
V_2 -> V_28 = 1 ;
if ( ! V_17 [ V_2 -> V_6 . type ] . V_138 )
V_2 -> V_139 = 1 ;
if ( V_17 [ V_2 -> V_6 . type ] . V_140 )
V_2 -> V_140 = V_17 [ V_2 -> V_6 . type ] . V_140 ;
if ( V_17 [ V_2 -> V_6 . type ] . V_36 )
V_2 -> V_36 = V_17 [ V_2 -> V_6 . type ] . V_36 ;
if ( V_2 -> V_33 == V_35 )
return;
if ( V_2 -> V_141 || V_142 [ V_2 -> V_6 . V_12 ] ) {
static const unsigned short V_143 [] = {
0x20 >> 1 ,
0x22 >> 1 ,
V_144
} ;
struct V_145 * V_146 ;
V_146 = F_46 ( & V_2 -> V_6 . V_147 ,
& V_2 -> V_6 . V_148 , L_40 , 0 , V_143 ) ;
V_2 -> V_141 = ( V_146 != NULL ) ;
}
switch ( V_149 [ V_2 -> V_6 . V_12 ] ) {
case - 1 :
return;
case 0 :
break;
case 1 : {
static const unsigned short V_143 [] = {
V_40 >> 1 ,
V_150 >> 1 ,
V_144
} ;
V_2 -> V_151 = F_46 ( & V_2 -> V_6 . V_147 ,
& V_2 -> V_6 . V_148 , L_41 , 0 , V_143 ) ;
if ( V_2 -> V_151 )
return;
goto V_152;
}
case 2 : {
static const unsigned short V_143 [] = {
V_153 >> 1 ,
V_144
} ;
if ( F_46 ( & V_2 -> V_6 . V_147 ,
& V_2 -> V_6 . V_148 , L_42 , 0 , V_143 ) )
return;
goto V_152;
}
case 3 : {
V_2 -> V_154 = F_46 ( & V_2 -> V_6 . V_147 ,
& V_2 -> V_6 . V_148 , L_43 , 0 , F_47 () ) ;
if ( V_2 -> V_154 )
return;
goto V_152;
}
default:
F_45 ( L_44 , V_2 -> V_6 . V_12 ) ;
return;
}
if ( ! V_17 [ V_2 -> V_6 . type ] . V_155 ) {
V_2 -> V_151 = F_46 ( & V_2 -> V_6 . V_147 ,
& V_2 -> V_6 . V_148 , L_41 ,
0 , F_48 ( V_40 >> 1 ) ) ;
} else if ( V_17 [ V_2 -> V_6 . type ] . V_156 ) {
V_2 -> V_151 = F_46 ( & V_2 -> V_6 . V_147 ,
& V_2 -> V_6 . V_148 , L_41 ,
0 , F_48 ( V_150 >> 1 ) ) ;
}
if ( V_2 -> V_151 )
return;
if ( ! V_17 [ V_2 -> V_6 . type ] . V_157 ) {
static const unsigned short V_143 [] = {
V_153 >> 1 ,
V_144
} ;
if ( F_46 ( & V_2 -> V_6 . V_147 ,
& V_2 -> V_6 . V_148 , L_42 , 0 , V_143 ) )
return;
}
V_2 -> V_154 = F_46 ( & V_2 -> V_6 . V_147 ,
& V_2 -> V_6 . V_148 , L_43 , 0 , F_47 () ) ;
if ( V_2 -> V_154 )
return;
V_152:
F_45 ( L_45 , V_2 -> V_6 . V_12 ) ;
}
void F_49 ( struct V_1 * V_2 )
{
int V_158 = V_159 ;
if ( V_159 != V_17 [ V_2 -> V_6 . type ] . V_160 )
V_158 = V_17 [ V_2 -> V_6 . type ] . V_160 ;
if ( V_2 -> V_33 != V_35 ) {
struct V_161 V_162 ;
if ( V_2 -> V_29 )
F_46 ( & V_2 -> V_6 . V_147 ,
& V_2 -> V_6 . V_148 , L_46 ,
0 , F_50 ( V_163 ) ) ;
F_46 ( & V_2 -> V_6 . V_147 ,
& V_2 -> V_6 . V_148 , L_46 ,
0 , F_50 ( V_164 ) ) ;
F_46 ( & V_2 -> V_6 . V_147 ,
& V_2 -> V_6 . V_148 , L_46 ,
0 , F_50 ( V_165 ) ) ;
V_162 . V_166 = V_167 ;
V_162 . type = V_2 -> V_33 ;
V_162 . V_158 = V_158 ;
if ( V_2 -> V_29 )
V_162 . V_166 |= V_168 ;
F_51 ( V_2 , V_130 , V_169 , & V_162 ) ;
}
if ( V_2 -> V_53 ) {
struct V_170 V_171 ;
V_171 . V_130 = V_172 ;
V_171 . V_173 = & V_2 -> V_53 ;
F_51 ( V_2 , V_130 , V_174 , & V_171 ) ;
}
}
static void F_41 ( struct V_1 * V_2 )
{
if( strncmp ( & ( V_23 [ 0x1e ] ) , L_47 , 14 ) == 0 ) {
V_2 -> V_33 = V_175 ;
F_2 ( L_48 ,
V_2 -> V_6 . V_12 , & V_23 [ 0x1e ] ) ;
} else if ( strncmp ( & ( V_23 [ 0x1e ] ) , L_49 , 10 ) == 0 ) {
V_2 -> V_33 = V_176 ;
F_2 ( L_48 ,
V_2 -> V_6 . V_12 , & V_23 [ 0x1e ] ) ;
} else if ( strncmp ( & ( V_23 [ 0x1e ] ) , L_50 , 14 ) == 0 ) {
V_2 -> V_33 = V_177 ;
F_2 ( L_48 ,
V_2 -> V_6 . V_12 , & V_23 [ 0x1e ] ) ;
} else {
F_2 ( L_51 ,
V_2 -> V_6 . V_12 , & V_23 [ 0x1e ] ) ;
}
}
static void F_35 ( struct V_1 * V_2 )
{
struct V_178 V_179 ;
F_52 ( & V_2 -> V_180 , & V_179 , V_23 ) ;
V_2 -> V_33 = V_179 . V_33 ;
V_2 -> V_29 = V_179 . V_29 ;
F_2 ( L_52 ,
V_2 -> V_6 . V_12 , V_179 . V_181 ) ;
if( V_179 . V_181 == 64900 ) {
F_2 ( L_53 ,
V_2 -> V_6 . V_12 ,
V_17 [ V_2 -> V_6 . type ] . V_13 ,
V_17 [ V_182 ] . V_13 ) ;
V_2 -> V_6 . type = V_182 ;
}
if ( V_179 . V_181 == 61334 )
V_2 -> V_183 = 1 ;
}
static int F_39 ( struct V_1 * V_2 )
{
int V_184 ;
V_2 -> V_29 = 1 ;
V_2 -> V_43 = 1 ;
V_2 -> V_44 = 0x10 ;
V_2 -> V_45 = 0x20 ;
V_2 -> V_46 = 0x08 ;
V_2 -> V_47 = 0x04 ;
V_2 -> V_48 = 0x3c ;
V_2 -> V_185 = 1 << 8 ;
V_2 -> V_186 = 1 << 9 ;
V_2 -> V_187 = 1 << 10 ;
V_184 = 88000 / 62.5 ;
F_53 ( V_2 , 5 * V_184 + 0x358 ) ;
if ( 0x1ed8 == F_54 ( V_2 ) ) {
F_2 ( L_54 , V_2 -> V_6 . V_12 ) ;
V_2 -> V_29 = 1 ;
V_2 -> V_141 = 1 ;
V_2 -> V_43 = 1 ;
} else {
V_2 -> V_29 = 0 ;
V_2 -> V_43 = 0 ;
}
return 0 ;
}
static int F_55 ( struct V_1 * V_2 , const T_2 * V_188 , T_1 V_189 )
{
T_1 V_190 ;
T_2 V_191 ;
int V_4 ;
F_8 ( 0xffffff , V_192 | V_193 | V_194 ) ;
F_14 ( 0 ) ;
F_9 ( V_195 ) ;
F_14 ( V_194 ) ;
F_9 ( V_195 ) ;
for ( V_190 = 0 ; V_190 < V_189 ; V_190 ++ ) {
V_191 = V_188 [ V_190 ] ;
for ( V_4 = 0 ; V_4 < 8 ; V_4 ++ ) {
F_15 ( V_193 , 0 ) ;
if ( V_191 & 0x01 )
F_15 ( V_192 , V_192 ) ;
else
F_15 ( V_192 , 0 ) ;
F_15 ( V_193 , V_193 ) ;
V_191 >>= 1 ;
}
}
F_15 ( V_193 , 0 ) ;
F_9 ( V_195 ) ;
for ( V_4 = 0 ; V_4 < 30 ; V_4 ++ ) {
F_15 ( V_193 , 0 ) ;
F_15 ( V_193 , V_193 ) ;
}
F_15 ( V_193 , 0 ) ;
return 0 ;
}
static int F_31 ( struct V_1 * V_2 )
{
const struct V_196 * V_197 ;
int V_198 ;
V_198 = F_56 ( & V_197 , L_55 , & V_2 -> V_6 . V_7 -> V_199 ) ;
if ( V_198 != 0 ) {
F_45 ( L_56 , V_2 -> V_6 . V_12 ) ;
return V_198 ;
}
V_198 = F_55 ( V_2 , V_197 -> V_200 , V_197 -> V_201 ) ;
F_2 ( L_57 ,
V_2 -> V_6 . V_12 , ( V_198 < 0 ) ? L_58 : L_59 ) ;
F_57 ( V_197 ) ;
return V_198 ;
}
static void F_40 ( struct V_1 * V_2 , const T_2 V_202 [ 256 ] )
{
int V_4 ;
T_1 V_203 = 0 ;
int V_5 = - 1 ;
if ( V_2 -> V_6 . type == V_82 ) {
if ( ! strncmp ( V_202 , L_60 , 4 ) ) {
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
T_3 V_204 = F_58 ( V_202 + V_4 , 16 ) ;
if ( ( V_204 & 0xff ) + ( V_204 >> 8 ) == 0xff )
break;
}
if ( V_4 >= 8 * 16 )
return;
V_202 += V_4 ;
type = F_59 ( ( V_205 * ) ( V_202 + 4 ) ) ;
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
F_8 ( 0xffffff , 0x000303 ) ;
break;
case 0x00D8 :
V_5 = V_111 ;
break;
default:
F_2 ( L_61 ,
V_2 -> V_6 . V_12 , type ) ;
break;
}
V_203 = F_60 ( ( V_206 * ) ( V_202 + 6 ) ) ;
}
F_2 ( L_62 ,
V_2 -> V_6 . V_12 , V_5 ,
V_5 > 0 ? V_17 [ V_5 ] . V_13 : L_63 , V_203 ) ;
if ( V_5 < 0 || V_2 -> V_6 . type == V_5 )
return;
if ( V_15 [ V_2 -> V_6 . V_12 ] < V_16 ) {
F_45 ( L_64 ,
V_2 -> V_6 . V_12 ) ;
} else {
F_2 ( L_65 ,
V_2 -> V_6 . V_12 , V_2 -> V_6 . type , V_5 ) ;
V_2 -> V_6 . type = V_5 ;
}
}
static void F_36 ( struct V_1 * V_2 )
{
int V_207 , V_208 , V_209 , V_33 = 0 ;
V_207 = ( V_23 [ 0x41 ] & 0x7 ) ;
V_208 = ( V_23 [ 0x41 ] & 0x18 ) >> 3 ;
V_209 = ( V_23 [ 0x42 ] & 0xf0 ) >> 4 ;
V_2 -> V_28 = ( V_23 [ 0x42 ] & 0x01 ) ;
if ( V_207 == 0 || V_207 == 2 )
if ( V_209 <= 0x0a )
V_33 = V_210 [ V_209 ] ;
if ( V_207 == 1 )
if ( V_209 <= 9 )
V_33 = V_211 [ V_209 ] ;
if ( V_207 == 4 )
if ( V_209 == 0x09 )
V_33 = V_212 ;
F_2 ( L_66 ,
V_2 -> V_6 . V_12 , V_23 [ 0x41 ] , V_23 [ 0x42 ] ) ;
if ( V_33 ) {
V_2 -> V_33 = V_33 ;
F_5 ( L_67 , V_33 ) ;
} else
F_5 ( L_68 ) ;
F_5 ( L_69 ,
V_208 ? L_17 : L_18 ,
V_2 -> V_28 ? L_17 : L_18 ) ;
}
T_1 F_61 ( struct V_1 * V_2 , T_1 V_3 )
{
if ( V_2 -> V_213 == V_214 ) {
if ( V_215 [ V_2 -> V_216 ] . V_217 & V_218 )
V_3 |= 0x10000 ;
else
V_3 &= ~ 0x10000 ;
}
F_15 ( V_17 [ V_2 -> V_6 . type ] . V_22 , V_3 ) ;
return V_3 ;
}
static void F_30 ( struct V_1 * V_2 , int V_219 )
{
int V_220 = ( 1 << V_219 ) ;
F_8 ( V_220 , V_220 ) ;
F_15 ( V_220 , 0 ) ;
F_62 ( 2 ) ;
F_9 ( 500 ) ;
F_15 ( V_220 , V_220 ) ;
if ( V_221 )
F_63 ( V_2 , L_70 ) ;
if ( V_222 )
F_2 ( L_71 ,
V_2 -> V_6 . V_12 , V_219 ) ;
}
static void F_37 ( struct V_1 * V_2 )
{
static int V_223 [] = { 0x08 , 0x09 , 0x0a , 0x0b , 0x0d , 0x0d , 0x01 , 0x02 ,
0x03 , 0x04 , 0x05 , 0x06 , 0x00 } ;
unsigned int V_4 ;
int V_224 ;
T_1 V_225 ;
F_8 ( 0xffffff , ( 1 << 13 ) ) ;
F_14 ( 0 ) ;
F_9 ( 3 ) ;
F_14 ( 1 << 13 ) ;
F_15 ( 0xffffff , 0 ) ;
if ( V_221 )
F_63 ( V_2 , L_72 ) ;
F_22 ( V_226 | V_227 , V_61 ) ;
F_2 ( L_73 ) ;
F_64 ( V_2 , 0x5E , 0 , 0x80 , 1 ) ;
F_2 ( L_74 ) ;
V_225 = F_65 ( V_228 ) ;
V_225 |= V_229 ;
F_22 ( V_225 , V_228 ) ;
F_8 ( 0xffffff , ( 1 << 2 ) ) ;
F_14 ( 0 ) ;
F_9 ( 10 ) ;
F_14 ( 1 << 2 ) ;
for ( V_4 = 0 ; V_4 < F_4 ( V_223 ) ; V_4 ++ ) {
V_224 = F_64 ( V_2 , 0x1E , 0 , V_223 [ V_4 ] , 1 ) ;
if ( V_224 != - 1 ) {
F_2 ( L_75 ,
V_223 [ V_4 ] , V_224 , F_12 ( V_2 , 0x1F , NULL ) ) ;
}
}
F_2 ( L_76 ) ;
}
static void
F_32 ( struct V_1 * V_2 )
{
T_4 V_230 = 0 ;
long V_231 = 0x0E ;
F_2 ( L_77 ,
V_2 -> V_6 . V_12 ) ;
F_22 ( 0x00c3feff , V_232 ) ;
F_22 ( 0 + V_231 , V_233 ) ;
F_66 ( 1 ) ;
F_22 ( 0x10 + V_231 , V_233 ) ;
F_66 ( 10 ) ;
F_22 ( 0 + V_231 , V_233 ) ;
V_230 = F_65 ( V_233 ) ;
if ( ( ( ( V_230 >> 18 ) & 0x01 ) != 0 ) || ( ( ( V_230 >> 19 ) & 0x01 ) != 1 ) ) {
F_2 ( L_78 ,
V_2 -> V_6 . V_12 , V_230 ) ;
}
F_22 ( 0x4400 + V_231 , V_233 ) ;
F_66 ( 10 ) ;
F_22 ( 0x4410 + V_231 , V_233 ) ;
F_66 ( 1 ) ;
F_22 ( V_231 , V_233 ) ;
F_66 ( 1 ) ;
V_230 = F_65 ( V_233 ) ;
if ( ( ( ( V_230 >> 18 ) & 0x01 ) != 0 ) || ( ( ( V_230 >> 19 ) & 0x01 ) != 0 ) ) {
F_2 ( L_79 ,
V_2 -> V_6 . V_12 , V_230 ) ;
return;
}
F_2 ( L_80 , V_2 -> V_6 . V_12 ) ;
}
static void F_67 ( struct V_1 * V_2 , int V_234 )
{
if ( V_2 -> V_186 ) {
F_15 ( V_2 -> V_186 | V_2 -> V_185 | V_2 -> V_187 ,
V_2 -> V_186 | V_2 -> V_185 | V_2 -> V_187 ) ;
F_9 ( 5 ) ;
}
F_15 ( V_234 , 0 ) ;
F_9 ( 5 ) ;
if ( V_2 -> V_186 ) {
F_15 ( V_2 -> V_185 | V_2 -> V_187 , 0 ) ;
F_9 ( 5 ) ;
}
}
static void F_68 ( struct V_1 * V_2 , int V_234 )
{
if ( V_2 -> V_186 ) {
F_15 ( V_2 -> V_186 | V_2 -> V_185 | V_2 -> V_187 ,
V_2 -> V_186 | V_2 -> V_185 | V_2 -> V_187 ) ;
F_9 ( 5 ) ;
}
F_15 ( V_234 , V_234 ) ;
F_9 ( 5 ) ;
if ( V_2 -> V_186 ) {
F_15 ( V_2 -> V_185 | V_2 -> V_187 , 0 ) ;
F_9 ( 5 ) ;
}
}
static int F_69 ( struct V_1 * V_2 , int V_234 )
{
if ( V_2 -> V_186 ) {
F_15 ( V_2 -> V_186 | V_2 -> V_185 | V_2 -> V_187 ,
V_2 -> V_186 | V_2 -> V_185 | V_2 -> V_187 ) ;
F_9 ( 5 ) ;
F_15 ( V_2 -> V_185 | V_2 -> V_187 , 0 ) ;
F_9 ( 5 ) ;
}
return F_10 () & ( V_234 ) ;
}
static int F_54 ( struct V_1 * V_2 )
{
unsigned long V_235 ;
int V_68 = 0 ;
int V_4 ;
F_8 ( V_2 -> V_48 , V_2 -> V_46 | V_2 -> V_44 ) ;
if ( V_2 -> V_186 ) {
F_15 ( V_2 -> V_186 | V_2 -> V_185 | V_2 -> V_187 ,
V_2 -> V_186 | V_2 -> V_185 | V_2 -> V_187 ) ;
F_9 ( 5 ) ;
}
if ( V_221 )
F_63 ( V_2 , L_81 ) ;
F_67 ( V_2 , V_2 -> V_44 ) ;
F_67 ( V_2 , V_2 -> V_46 ) ;
F_9 ( 10 ) ;
V_235 = V_236 + F_70 ( 1000 ) ;
while ( F_69 ( V_2 , V_2 -> V_47 ) && F_71 ( V_236 , V_235 ) )
F_72 () ;
if ( F_69 ( V_2 , V_2 -> V_47 ) ) {
F_45 ( L_82 , V_2 -> V_6 . V_12 ) ;
return - 1 ;
}
F_73 ( L_83 , V_2 -> V_6 . V_12 ) ;
for ( V_4 = 0 ; V_4 < 24 ; V_4 ++ ) {
F_9 ( 5 ) ;
F_68 ( V_2 , V_2 -> V_46 ) ;
F_9 ( 5 ) ;
F_74 ( L_84 ,
F_69 ( V_2 , V_2 -> V_45 ) == 0 ? 'T' : '-' ) ;
F_67 ( V_2 , V_2 -> V_46 ) ;
V_68 <<= 1 ;
V_68 |= ( F_69 ( V_2 , V_2 -> V_47 ) == 0 ) ? 0 : 1 ;
F_74 ( L_84 ,
F_69 ( V_2 , V_2 -> V_45 ) == 0 ? 'S' : 'M' ) ;
}
F_74 ( L_11 ) ;
F_73 ( L_85 , V_2 -> V_6 . V_12 , V_68 ) ;
return V_68 ;
}
static int F_53 ( struct V_1 * V_2 , int V_68 )
{
int V_4 ;
int V_237 = V_68 ;
F_8 ( V_2 -> V_48 , V_2 -> V_46 | V_2 -> V_44 | V_2 -> V_47 ) ;
if ( V_2 -> V_186 ) {
F_15 ( V_2 -> V_186 | V_2 -> V_185 | V_2 -> V_187 ,
V_2 -> V_186 | V_2 -> V_185 | V_2 -> V_187 ) ;
F_9 ( 5 ) ;
}
if ( V_221 )
F_63 ( V_2 , L_86 ) ;
F_73 ( L_87 , V_2 -> V_6 . V_12 , V_68 ) ;
F_67 ( V_2 , V_2 -> V_46 ) ;
F_68 ( V_2 , V_2 -> V_44 ) ;
for ( V_4 = 0 ; V_4 < 25 ; V_4 ++ ) {
if ( V_237 & 0x1000000 )
F_68 ( V_2 , V_2 -> V_47 ) ;
else
F_67 ( V_2 , V_2 -> V_47 ) ;
V_237 <<= 1 ;
F_68 ( V_2 , V_2 -> V_46 ) ;
F_9 ( 10 ) ;
F_67 ( V_2 , V_2 -> V_46 ) ;
F_9 ( 10 ) ;
}
F_67 ( V_2 , V_2 -> V_44 ) ;
return 0 ;
}
void F_75 ( struct V_1 * V_2 , unsigned short V_184 )
{
F_73 ( L_88 , V_184 ) ;
F_53 ( V_2 , 5 * V_184 + 0x358 ) ;
}
static void F_76 ( struct V_1 * V_2 , unsigned int V_59 )
{
static const T_2 V_238 [] = { 0x3 , 0x1 , 0x2 , 0x4 , 0xf , 0x7 , 0xe , 0x0 ,
0xd , 0xb , 0xc , 0x6 , 0x9 , 0x5 , 0x8 , 0xa } ;
F_15 ( 0x07f , V_238 [ V_59 ] ) ;
F_15 ( 0x200 , 0x200 ) ;
F_62 ( 1 ) ;
F_15 ( 0x200 , 0x000 ) ;
F_62 ( 1 ) ;
F_15 ( 0x480 , 0x480 ) ;
F_62 ( 1 ) ;
F_15 ( 0x480 , 0x080 ) ;
F_62 ( 1 ) ;
}
static void F_77 ( struct V_1 * V_2 , unsigned int V_59 )
{
F_15 ( 0x0f0000 , V_59 << 16 ) ;
}
static void F_42 ( struct V_1 * V_2 )
{
F_8 ( 0xffffff , 0x0f7fff ) ;
F_14 ( 0x0f7fff ) ;
}
static void F_78 ( struct V_1 * V_2 ,
unsigned char V_239 ,
unsigned char V_240 ,
unsigned char V_200 ) {
unsigned int V_241 ;
V_241 = ( V_200 << 7 ) | ( ( V_240 & 3 ) << 4 ) | ( V_239 & 0xf ) ;
F_15 ( 0x1ff , V_241 ) ;
F_15 ( 0x1ff , V_241 | ( 1 << 8 ) ) ;
F_15 ( 0x1ff , V_241 ) ;
}
static void F_79 ( struct V_1 * V_2 , unsigned int V_59 )
{
char * V_242 ;
int V_239 , V_240 ;
struct V_1 * V_243 ;
static unsigned char V_244 [ 4 ] = { 3 , 0 , 2 , 1 } ;
V_243 = V_245 [ V_2 -> V_6 . V_12 ] ;
if ( V_243 == NULL ) {
return;
}
V_240 = ( V_2 -> V_6 . V_12 - V_243 -> V_6 . V_12 + 1 ) & 3 ;
V_240 = V_244 [ V_240 ] ;
V_242 = ( char * ) ( & V_243 -> V_44 ) ;
V_239 = V_59 & 0xf ;
if ( V_242 [ V_240 ] != V_239 )
{
F_78 ( V_243 , V_242 [ V_240 ] , V_240 , 0 ) ;
V_242 [ V_240 ] = V_239 ;
F_78 ( V_243 , V_239 , V_240 , 1 ) ;
}
}
static void F_43 ( struct V_1 * V_2 )
{
char * V_242 = ( char * ) ( & V_2 -> V_44 ) ;
int V_246 ;
F_8 ( 0x0003ff , 0x0003ff ) ;
F_14 ( 1 << 9 ) ;
F_14 ( 0 ) ;
for ( V_246 = 0 ; V_246 < 4 ; V_246 ++ ) {
V_242 [ V_246 ] = V_246 ;
F_78 ( V_2 , V_246 , V_246 , 1 ) ;
}
if ( ( V_2 -> V_6 . V_12 < 1 ) || ( V_2 -> V_6 . V_12 > V_247 - 3 ) )
return;
V_245 [ V_2 -> V_6 . V_12 - 1 ] = V_2 ;
V_245 [ V_2 -> V_6 . V_12 ] = V_2 ;
V_245 [ V_2 -> V_6 . V_12 + 1 ] = V_2 ;
V_245 [ V_2 -> V_6 . V_12 + 2 ] = V_2 ;
}
static void F_80 ( struct V_1 * V_2 , unsigned int V_59 )
{
static const int V_65 [] = {
V_248 , V_248 | V_249 , V_248 | V_250 , V_248 | V_249 | V_250 ,
V_251 , V_251 | V_249 , V_251 | V_250 , V_251 | V_249 | V_250 ,
V_252 , V_252 | V_253 , V_252 | V_254 , V_252 | V_253 | V_254 ,
V_255 , V_255 | V_253 , V_255 | V_254 , V_255 | V_253 | V_254 ,
} ;
F_14 ( V_65 [ V_59 % 16 ] ) ;
}
static void F_38 ( struct V_1 * V_2 )
{
F_22 ( 0x08 << 16 , V_233 ) ;
F_22 ( 0x04 << 16 , V_233 ) ;
}
static void F_81 ( struct V_1 * V_2 , unsigned int V_59 )
{
F_73 ( L_89 , V_2 -> V_6 . V_12 , V_59 ) ;
F_22 ( V_59 << 20 , V_233 ) ;
}
static void F_82 ( struct V_1 * V_2 , unsigned int V_59 )
{
int V_256 = V_59 % 4 ;
int V_257 = V_59 / 4 ;
F_73 ( L_90 ,
V_2 -> V_6 . V_12 , V_59 , V_257 , V_256 ) ;
F_64 ( V_2 , V_258 , 0x00 ,
( ( V_257 == 3 ) ? ( V_256 | V_256 << 2 ) : 0x00 ) , 1 ) ;
F_64 ( V_2 , V_259 , 0x00 ,
( ( V_257 == 0 ) ? ( V_256 | V_256 << 2 ) : 0x00 ) , 1 ) ;
F_64 ( V_2 , V_260 , 0x00 ,
( ( V_257 == 1 ) ? ( V_256 | V_256 << 2 ) : 0x00 ) , 1 ) ;
F_64 ( V_2 , V_261 , 0x00 ,
( ( V_257 == 2 ) ? ( V_256 | V_256 << 2 ) : 0x00 ) , 1 ) ;
F_64 ( V_2 , V_258 , 0x02 ,
( ( V_257 == 3 ) ? 0x03 : 0x00 ) , 1 ) ;
F_64 ( V_2 , V_259 , 0x02 ,
( ( V_257 == 0 ) ? 0x03 : 0x00 ) , 1 ) ;
F_64 ( V_2 , V_260 , 0x02 ,
( ( V_257 == 1 ) ? 0x03 : 0x00 ) , 1 ) ;
F_64 ( V_2 , V_261 , 0x02 ,
( ( V_257 == 2 ) ? 0x03 : 0x00 ) , 1 ) ;
}
static void F_83 ( struct V_1 * V_2 , unsigned int V_59 )
{
int V_198 ;
long V_262 ;
int V_263 ;
unsigned char V_264 [ 2 ] ;
V_264 [ 0 ] = 0 ;
V_264 [ 1 ] = 0 ;
V_198 = F_64 ( V_2 , ( V_265 << 1 ) , V_264 [ 0 ] , V_264 [ 1 ] , 1 ) ;
if ( V_198 ) {
F_3 ( L_91 ,
V_2 -> V_6 . V_12 , V_198 ) ;
return;
}
V_198 = F_12 ( V_2 , ( V_265 << 1 ) , NULL ) ;
if ( ! ( V_198 & V_266 ) ) {
F_3 ( L_92 ,
V_2 -> V_6 . V_12 , V_198 ) ;
return;
}
V_262 = V_59 ;
V_263 = 0x302 ;
if ( V_2 -> V_5 == V_267 ) {
V_263 ^= 0x180 ;
V_263 |= 7 << 4 ;
}
F_22 ( V_263 , V_232 ) ;
V_263 = F_65 ( V_233 ) ;
if ( V_2 -> V_5 == V_267 )
V_263 = ( V_263 & ~ 0x280 ) | ( ( V_262 & 2 ) << 8 ) | ( ( V_262 & 1 ) << 7 ) ;
else
V_263 = ( V_263 & ~ 0x300 ) | ( ( V_262 & 3 ) << 8 ) ;
F_22 ( V_263 , V_233 ) ;
if ( V_2 -> V_5 == V_267 )
F_16 ( 2 << 5 , ~ V_268 , V_58 ) ;
else
F_19 ( ~ V_268 , V_58 ) ;
F_3 ( L_93 , V_2 -> V_6 . V_12 , ( int ) V_262 ) ;
}
static void F_84 ( struct V_1 * V_2 , unsigned int V_59 )
{
unsigned int V_262 = V_59 % 4 ;
if ( V_59 == V_2 -> V_135 )
V_262 = 0 ;
F_15 ( 0x3 , V_262 ) ;
}
static void F_85 ( struct V_1 * V_2 ,
unsigned char V_239 ,
unsigned char V_240 ,
unsigned char V_200 ) {
const T_1 V_269 = ( ( V_239 & 0xf ) | ( V_240 & 3 ) << 4 ) ;
const T_1 V_270 = 1 << 16 ;
const T_1 V_271 = 1 << 17 ;
const T_1 V_272 = V_200 << 18 ;
F_15 ( 0x1007f , V_269 | V_270 ) ;
F_15 ( 0x20000 , V_271 ) ;
F_15 ( 0x40000 , V_272 ) ;
F_15 ( 0x20000 , ~ V_271 ) ;
}
static void F_86 ( struct V_1 * V_2 , unsigned int V_59 )
{
struct V_1 * V_243 ;
char * V_242 ;
int V_239 , V_240 ;
static unsigned int V_244 [ 4 ] [ 4 ] = { { 0x0 , 0x4 , 0xa , 0x6 } ,
{ 0x1 , 0x5 , 0xb , 0x7 } ,
{ 0x2 , 0x8 , 0xc , 0xe } ,
{ 0x3 , 0x9 , 0xd , 0xf } } ;
V_59 = V_59 % 4 ;
V_243 = V_245 [ V_2 -> V_6 . V_12 ] ;
if ( V_243 == NULL ) {
return;
}
V_240 = ( V_2 -> V_6 . V_12 - V_243 -> V_6 . V_12 ) & 3 ;
V_242 = ( char * ) ( & V_243 -> V_44 ) ;
V_239 = V_244 [ V_240 ] [ V_59 ] & 0xf ;
if ( V_242 [ V_240 ] != V_239 ) {
F_85 ( V_243 , V_242 [ V_240 ] , V_240 , 0 ) ;
V_242 [ V_240 ] = V_239 ;
F_85 ( V_243 , V_239 , V_240 , 1 ) ;
}
}
static void F_44 ( struct V_1 * V_2 )
{
char * V_242 = ( char * ) ( & V_2 -> V_44 ) ;
int V_246 ;
F_8 ( 0xf107f , 0xf107f ) ;
F_14 ( 1 << 19 ) ;
F_14 ( 0 ) ;
for ( V_246 = 0 ; V_246 < 4 ; V_246 ++ ) {
V_242 [ V_246 ] = V_246 ;
F_85 ( V_2 , V_246 , V_246 , 1 ) ;
}
F_64 ( V_2 , 0x18 , 0x5 , 0x90 , 1 ) ;
if ( V_2 -> V_6 . V_12 > V_247 - 4 )
return;
V_245 [ V_2 -> V_6 . V_12 ] = V_2 ;
V_245 [ V_2 -> V_6 . V_12 + 1 ] = V_2 ;
V_245 [ V_2 -> V_6 . V_12 + 2 ] = V_2 ;
V_245 [ V_2 -> V_6 . V_12 + 3 ] = V_2 ;
}
void T_5 F_87 ( void )
{
int V_273 = 0 ;
struct V_274 * V_199 = NULL ;
if ( V_275 & ( V_276 | V_277 ) )
V_273 = 1 ;
if ( V_275 & ( V_278 | V_279 | V_280 ) )
V_281 = 1 ;
if ( V_275 & V_282 )
V_283 = 1 ;
#ifdef F_88
if ( V_275 & F_88 )
V_284 = 0x0A ;
#endif
if ( V_281 )
F_2 ( L_94 ) ;
if ( V_283 )
F_2 ( L_95 ) ;
if ( V_273 ) {
F_2 ( L_96 ) ;
if ( ! V_285 ) {
F_2 ( L_97 ) ;
V_285 = 1 ;
} else {
F_2 ( L_98 ) ;
}
}
if ( V_18 != V_284 )
F_2 ( L_99 , V_284 ) ;
while ( ( V_199 = F_89 ( V_286 ,
V_287 , V_199 ) ) ) {
unsigned char V_288 ;
F_90 ( V_199 , 0x53 , & V_288 ) ;
if ( V_70 )
F_2 ( L_100 ,
V_288 ) ;
}
}
int F_91 ( struct V_1 * V_2 )
{
unsigned char V_289 ;
if ( ! V_281 && ! V_283 && V_18 == V_284 )
return 0 ;
if ( V_222 ) {
if ( V_281 )
F_2 ( L_101 ,
V_2 -> V_6 . V_12 ) ;
if ( V_283 && V_2 -> V_11 >= 878 )
F_2 ( L_102 , V_2 -> V_6 . V_12 ) ;
if ( V_18 != V_284 )
F_2 ( L_103 ,
V_2 -> V_6 . V_12 , V_284 ) ;
}
if ( V_2 -> V_11 < 878 ) {
if ( V_281 )
V_2 -> V_281 = V_290 ;
} else {
F_90 ( V_2 -> V_6 . V_7 , V_291 , & V_289 ) ;
if ( V_281 )
V_289 |= V_292 ;
if ( V_283 )
V_289 |= V_293 ;
F_92 ( V_2 -> V_6 . V_7 , V_291 , V_289 ) ;
}
if ( V_18 != V_284 )
F_92 ( V_2 -> V_6 . V_7 , V_294 , V_284 ) ;
return 0 ;
}
