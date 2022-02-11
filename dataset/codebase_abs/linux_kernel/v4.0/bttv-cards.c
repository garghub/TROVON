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
V_2 -> V_44 . V_45 = 6 ;
V_2 -> V_44 . V_46 = 7 ;
V_2 -> V_44 . V_47 = 8 ;
V_2 -> V_44 . V_48 = 9 ;
F_13 ( V_2 ) ;
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
static void F_14 ( struct V_1 * V_2 )
{
F_8 ( 0xffffff , 0xFFFF37 ) ;
F_15 ( 0x200020 ) ;
F_15 ( 0x200024 ) ;
F_16 ( V_57 , V_57 ) ;
F_17 ( ( 2 ) << 5 , ~ ( 2 << 5 ) , V_58 ) ;
}
static void F_18 ( struct V_1 * V_2 , unsigned int V_59 )
{
F_16 ( 3 , V_59 & 3 ) ;
F_19 ( V_60 , V_61 ) ;
F_20 ( ~ V_62 , V_63 ) ;
F_20 ( ~ V_62 , V_64 ) ;
F_16 ( V_57 , V_57 ) ;
}
static void F_21 ( struct V_1 * V_2 , unsigned int V_59 )
{
static const int V_65 [] = { 0x30 , 0x01 , 0x12 , 0x23 } ;
F_15 ( V_65 [ V_59 % 4 ] ) ;
}
static void F_22 ( struct V_1 * V_2 )
{
F_3 ( L_32 ) ;
F_23 ( 0x000000 , V_66 ) ;
F_8 ( 0xffffff , 0x0006C0 ) ;
F_15 ( 0x000000 ) ;
}
static void F_24 ( struct V_1 * V_2 , unsigned int V_59 )
{
unsigned int V_67 = V_59 % 8 ;
F_8 ( 0xf , 0xf ) ;
F_16 ( 0xf , V_67 ) ;
}
static void F_25 ( struct V_1 * V_2 , unsigned int V_59 )
{
unsigned int V_67 = V_59 % 4 ;
F_8 ( 3 << 9 , 3 << 9 ) ;
F_16 ( 3 << 9 , V_67 << 9 ) ;
}
static void F_26 ( struct V_1 * V_2 , unsigned int V_59 )
{
unsigned int V_67 = V_59 % 16 ;
F_8 ( 0xf , 0xf ) ;
F_16 ( 0xf , V_67 ) ;
}
static void F_27 ( struct V_1 * V_2 , T_1 V_68 )
{
F_16 ( ( 1 << 18 ) | 0xff , V_68 ) ;
F_16 ( ( 1 << 18 ) | 0xff , ( 1 << 18 ) | V_68 ) ;
F_9 ( 1 ) ;
F_16 ( ( 1 << 18 ) | 0xff , V_68 ) ;
}
static void F_28 ( struct V_1 * V_2 , unsigned int V_59 )
{
T_1 V_68 ;
T_1 V_69 ;
V_69 = ( V_59 & 0x8 ) >> 3 ;
V_68 = 0x11 ;
V_68 |= ( ( V_59 & 0x7 ) << 1 ) << ( 4 * V_69 ) ;
F_27 ( V_2 , V_68 ) ;
V_68 &= ~ 0x11 ;
V_68 |= ( ( V_69 ^ 0x1 ) << 4 ) | V_69 ;
F_27 ( V_2 , V_68 ) ;
}
static void F_29 ( struct V_1 * V_2 )
{
if ( V_2 -> V_11 != 878 )
return;
if ( V_70 )
F_3 ( L_33 , V_2 -> V_6 . V_12 ) ;
F_23 ( ( 1 << 7 ) , 0x058 ) ;
F_9 ( 10 ) ;
F_23 ( 0 , 0x058 ) ;
}
void F_30 ( struct V_1 * V_2 )
{
switch ( V_2 -> V_6 . type ) {
case V_26 :
case V_71 :
F_31 ( V_2 , 5 ) ;
break;
case V_72 :
case V_73 :
F_31 ( V_2 , 20 ) ;
break;
case V_74 :
F_31 ( V_2 , 11 ) ;
break;
case V_75 :
F_32 ( V_2 ) ;
break;
case V_76 :
case V_77 :
case V_78 :
V_2 -> V_79 = 1 ;
break;
case V_80 :
F_33 ( V_2 ) ;
break;
case V_81 :
F_34 ( V_2 ) ;
break;
}
if ( ! V_17 [ V_2 -> V_6 . type ] . V_82 )
F_29 ( V_2 ) ;
}
void F_35 ( struct V_1 * V_2 )
{
V_2 -> V_33 = V_18 ;
if ( V_83 == V_2 -> V_6 . type ) {
F_36 ( V_2 , V_23 , 0xa0 ) ;
F_6 ( V_2 , V_23 ) ;
}
switch ( V_2 -> V_6 . type ) {
case V_49 :
case V_50 :
case V_51 :
case V_52 :
F_11 ( V_2 ) ;
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
F_7 ( V_2 ) ;
break;
case V_26 :
case V_71 :
case V_75 :
F_36 ( V_2 , V_23 , 0xa0 ) ;
F_37 ( V_2 ) ;
break;
case V_74 :
case V_95 :
F_36 ( V_2 , V_23 , 0xa0 ) ;
F_38 ( V_2 ) ;
break;
case V_96 :
F_39 ( V_2 ) ;
break;
case V_97 :
F_40 ( V_2 ) ;
break;
case V_98 :
V_2 -> V_29 = 1 ;
V_2 -> V_43 = 1 ;
V_2 -> V_44 . V_45 = 5 ;
V_2 -> V_44 . V_46 = 6 ;
V_2 -> V_44 . V_47 = 3 ;
V_2 -> V_44 . V_48 = 4 ;
F_13 ( V_2 ) ;
break;
case V_99 :
case V_100 :
F_41 ( V_2 ) ;
break;
case V_101 :
if ( V_2 -> V_5 == 0x3002144f ) {
V_2 -> V_29 = 1 ;
F_2 ( L_34 ,
V_2 -> V_6 . V_12 ) ;
}
break;
case V_102 :
if ( V_2 -> V_5 == 0x3060121a ) {
V_2 -> V_29 = 0 ;
V_2 -> V_33 = V_103 ;
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
F_36 ( V_2 , V_23 , 0xa0 ) ;
F_42 ( V_2 , V_23 ) ;
break;
case V_116 :
F_14 ( V_2 ) ;
break;
case V_24 :
F_36 ( V_2 , V_23 , 0xa0 ) ;
F_43 ( V_2 ) ;
break;
case V_117 :
F_22 ( V_2 ) ;
break;
case V_118 :
F_44 ( V_2 ) ;
break;
case V_119 :
F_45 ( V_2 ) ;
break;
case V_120 :
F_46 ( V_2 ) ;
break;
}
if ( ! ( V_2 -> V_11 == 848 && V_2 -> V_121 == 0x11 ) ) {
if ( V_122 == V_17 [ V_2 -> V_6 . type ] . V_123 ) {
V_2 -> V_123 . V_124 = 28636363 ;
V_2 -> V_123 . V_125 = V_126 ;
}
if ( V_127 == V_17 [ V_2 -> V_6 . type ] . V_123 ) {
V_2 -> V_123 . V_124 = 35468950 ;
V_2 -> V_123 . V_125 = V_128 ;
}
if ( V_129 == V_17 [ V_2 -> V_6 . type ] . V_123 ) {
V_2 -> V_123 . V_124 = 14318181 ;
V_2 -> V_123 . V_125 = V_126 ;
}
switch ( V_123 [ V_2 -> V_6 . V_12 ] ) {
case 0 :
V_2 -> V_123 . V_125 = 0 ;
V_2 -> V_123 . V_124 = 0 ;
V_2 -> V_123 . V_130 = 0 ;
break;
case 1 :
case 28 :
V_2 -> V_123 . V_124 = 28636363 ;
V_2 -> V_123 . V_130 = 0 ;
V_2 -> V_123 . V_125 = V_126 ;
break;
case 2 :
case 35 :
V_2 -> V_123 . V_124 = 35468950 ;
V_2 -> V_123 . V_130 = 0 ;
V_2 -> V_123 . V_125 = V_128 ;
break;
case 3 :
case 14 :
V_2 -> V_123 . V_124 = 14318181 ;
V_2 -> V_123 . V_130 = 0 ;
V_2 -> V_123 . V_125 = V_126 ;
break;
}
}
V_2 -> V_123 . V_131 = - 1 ;
if ( V_18 != V_17 [ V_2 -> V_6 . type ] . V_33 )
if ( V_18 == V_2 -> V_33 )
V_2 -> V_33 = V_17 [ V_2 -> V_6 . type ] . V_33 ;
if ( V_18 != V_132 [ V_2 -> V_6 . V_12 ] )
V_2 -> V_33 = V_132 [ V_2 -> V_6 . V_12 ] ;
if ( V_2 -> V_33 == V_35 )
F_2 ( L_35 , V_2 -> V_6 . V_12 ) ;
else if ( V_2 -> V_33 == V_18 )
F_47 ( L_36 , V_2 -> V_6 . V_12 ) ;
else
F_2 ( L_37 , V_2 -> V_6 . V_12 , V_2 -> V_33 ) ;
if ( V_133 != V_18 ) {
F_47 ( L_38 , V_2 -> V_6 . V_12 ) ;
F_47 ( L_39 ,
V_2 -> V_6 . V_12 ) ;
}
if ( V_18 == V_2 -> V_33 )
V_2 -> V_33 = V_35 ;
V_2 -> V_134 = V_17 [ V_2 -> V_6 . type ] . V_135 ?
V_17 [ V_2 -> V_6 . type ] . V_136 - 1 : V_18 ;
V_2 -> V_137 = V_17 [ V_2 -> V_6 . type ] . V_137 == V_138 ?
V_18 : V_17 [ V_2 -> V_6 . type ] . V_137 ;
if ( V_137 [ V_2 -> V_6 . V_12 ] != V_18 )
V_2 -> V_137 = V_137 [ V_2 -> V_6 . V_12 ] ;
if ( V_139 [ V_2 -> V_6 . V_12 ] != V_18 )
V_2 -> V_28 = V_139 [ V_2 -> V_6 . V_12 ] ;
if ( V_17 [ V_2 -> V_6 . type ] . V_29 )
V_2 -> V_29 = 1 ;
if ( V_17 [ V_2 -> V_6 . type ] . V_28 )
V_2 -> V_28 = 1 ;
if ( ! V_17 [ V_2 -> V_6 . type ] . V_140 )
V_2 -> V_141 = 1 ;
if ( V_17 [ V_2 -> V_6 . type ] . V_142 )
V_2 -> V_142 = V_17 [ V_2 -> V_6 . type ] . V_142 ;
if ( V_17 [ V_2 -> V_6 . type ] . V_36 )
V_2 -> V_36 = V_17 [ V_2 -> V_6 . type ] . V_36 ;
if ( V_2 -> V_33 == V_35 )
return;
if ( V_2 -> V_143 || V_144 [ V_2 -> V_6 . V_12 ] ) {
static const unsigned short V_145 [] = {
0x20 >> 1 ,
0x22 >> 1 ,
V_146
} ;
struct V_147 * V_148 ;
V_148 = F_48 ( & V_2 -> V_6 . V_149 ,
& V_2 -> V_6 . V_150 , L_40 , 0 , V_145 ) ;
V_2 -> V_143 = ( V_148 != NULL ) ;
}
switch ( V_151 [ V_2 -> V_6 . V_12 ] ) {
case - 1 :
return;
case 0 :
break;
case 1 : {
static const unsigned short V_145 [] = {
V_40 >> 1 ,
V_152 >> 1 ,
V_146
} ;
V_2 -> V_153 = F_48 ( & V_2 -> V_6 . V_149 ,
& V_2 -> V_6 . V_150 , L_41 , 0 , V_145 ) ;
if ( V_2 -> V_153 )
return;
goto V_154;
}
case 2 : {
static const unsigned short V_145 [] = {
V_155 >> 1 ,
V_146
} ;
if ( F_48 ( & V_2 -> V_6 . V_149 ,
& V_2 -> V_6 . V_150 , L_42 , 0 , V_145 ) )
return;
goto V_154;
}
case 3 : {
V_2 -> V_156 = F_48 ( & V_2 -> V_6 . V_149 ,
& V_2 -> V_6 . V_150 , L_43 , 0 , F_49 () ) ;
if ( V_2 -> V_156 )
return;
goto V_154;
}
default:
F_47 ( L_44 , V_2 -> V_6 . V_12 ) ;
return;
}
if ( ! V_17 [ V_2 -> V_6 . type ] . V_157 ) {
V_2 -> V_153 = F_48 ( & V_2 -> V_6 . V_149 ,
& V_2 -> V_6 . V_150 , L_41 ,
0 , F_50 ( V_40 >> 1 ) ) ;
} else if ( V_17 [ V_2 -> V_6 . type ] . V_158 ) {
V_2 -> V_153 = F_48 ( & V_2 -> V_6 . V_149 ,
& V_2 -> V_6 . V_150 , L_41 ,
0 , F_50 ( V_152 >> 1 ) ) ;
}
if ( V_2 -> V_153 )
return;
V_2 -> V_156 = F_48 ( & V_2 -> V_6 . V_149 ,
& V_2 -> V_6 . V_150 , L_43 , 0 , F_49 () ) ;
if ( V_2 -> V_156 ) {
F_48 ( & V_2 -> V_6 . V_149 ,
& V_2 -> V_6 . V_150 , L_43 , 0 , F_49 () ) ;
}
if ( ! V_17 [ V_2 -> V_6 . type ] . V_159 ) {
static const unsigned short V_145 [] = {
V_155 >> 1 ,
V_146
} ;
V_2 -> V_160 = F_48 ( & V_2 -> V_6 . V_149 ,
& V_2 -> V_6 . V_150 , L_42 , 0 , V_145 ) ;
if ( V_2 -> V_160 )
return;
}
if ( V_2 -> V_156 )
return;
V_154:
F_47 ( L_45 , V_2 -> V_6 . V_12 ) ;
}
void F_51 ( struct V_1 * V_2 )
{
int V_161 = V_162 ;
if ( V_162 != V_17 [ V_2 -> V_6 . type ] . V_163 )
V_161 = V_17 [ V_2 -> V_6 . type ] . V_163 ;
if ( V_2 -> V_33 != V_35 ) {
struct V_164 V_165 ;
if ( V_2 -> V_29 )
F_48 ( & V_2 -> V_6 . V_149 ,
& V_2 -> V_6 . V_150 , L_46 ,
0 , F_52 ( V_166 ) ) ;
F_48 ( & V_2 -> V_6 . V_149 ,
& V_2 -> V_6 . V_150 , L_46 ,
0 , F_52 ( V_167 ) ) ;
F_48 ( & V_2 -> V_6 . V_149 ,
& V_2 -> V_6 . V_150 , L_46 ,
0 , F_52 ( V_168 ) ) ;
V_165 . V_169 = V_170 ;
V_165 . type = V_2 -> V_33 ;
V_165 . V_161 = V_161 ;
if ( V_2 -> V_29 )
V_165 . V_169 |= V_171 ;
F_53 ( V_2 , V_132 , V_172 , & V_165 ) ;
}
if ( V_2 -> V_53 ) {
struct V_173 V_174 ;
V_174 . V_132 = V_175 ;
V_174 . V_176 = & V_2 -> V_53 ;
F_53 ( V_2 , V_132 , V_177 , & V_174 ) ;
}
}
static void F_43 ( struct V_1 * V_2 )
{
if( strncmp ( & ( V_23 [ 0x1e ] ) , L_47 , 14 ) == 0 ) {
V_2 -> V_33 = V_178 ;
F_2 ( L_48 ,
V_2 -> V_6 . V_12 , & V_23 [ 0x1e ] ) ;
} else if ( strncmp ( & ( V_23 [ 0x1e ] ) , L_49 , 10 ) == 0 ) {
V_2 -> V_33 = V_179 ;
F_2 ( L_48 ,
V_2 -> V_6 . V_12 , & V_23 [ 0x1e ] ) ;
} else if ( strncmp ( & ( V_23 [ 0x1e ] ) , L_50 , 14 ) == 0 ) {
V_2 -> V_33 = V_180 ;
F_2 ( L_48 ,
V_2 -> V_6 . V_12 , & V_23 [ 0x1e ] ) ;
} else {
F_2 ( L_51 ,
V_2 -> V_6 . V_12 , & V_23 [ 0x1e ] ) ;
}
}
static void F_37 ( struct V_1 * V_2 )
{
struct V_181 V_182 ;
F_54 ( & V_2 -> V_183 , & V_182 , V_23 ) ;
V_2 -> V_33 = V_182 . V_33 ;
V_2 -> V_29 = V_182 . V_29 ;
F_2 ( L_52 ,
V_2 -> V_6 . V_12 , V_182 . V_184 ) ;
if( V_182 . V_184 == 64900 ) {
F_2 ( L_53 ,
V_2 -> V_6 . V_12 ,
V_17 [ V_2 -> V_6 . type ] . V_13 ,
V_17 [ V_185 ] . V_13 ) ;
V_2 -> V_6 . type = V_185 ;
}
if ( V_182 . V_184 == 61334 )
V_2 -> V_186 = 1 ;
}
static void F_55 ( struct V_187 * V_188 , T_2 V_189 )
{
struct V_1 * V_2 = V_188 -> V_190 ;
struct V_191 V_27 = V_2 -> V_44 ;
T_3 V_192 = 0 ;
V_192 |= ( V_189 & V_193 ) ? ( 1 << V_27 . V_48 ) : 0 ;
V_192 |= ( V_189 & V_194 ) ? ( 1 << V_27 . V_47 ) : 0 ;
V_192 |= ( V_189 & V_195 ) ? ( 1 << V_27 . V_45 ) : 0 ;
F_16 ( ( 1 << V_27 . V_48 ) | ( 1 << V_27 . V_47 ) | ( 1 << V_27 . V_45 ) , V_192 ) ;
if ( V_2 -> V_196 ) {
F_16 ( V_2 -> V_197 | V_2 -> V_198 , 0 ) ;
F_9 ( 5 ) ;
F_16 ( V_2 -> V_196 | V_2 -> V_197 | V_2 -> V_198 ,
V_2 -> V_196 | V_2 -> V_197 | V_2 -> V_198 ) ;
}
}
static T_2 F_56 ( struct V_187 * V_188 )
{
struct V_1 * V_2 = V_188 -> V_190 ;
struct V_191 V_27 = V_2 -> V_44 ;
T_2 V_199 = 0 ;
T_3 V_192 ;
if ( V_2 -> V_196 ) {
F_16 ( V_2 -> V_196 | V_2 -> V_198 , 0 ) ;
F_9 ( 5 ) ;
}
V_192 = F_10 () ;
if ( V_2 -> V_196 ) {
F_16 ( V_2 -> V_196 | V_2 -> V_197 | V_2 -> V_198 ,
V_2 -> V_196 | V_2 -> V_197 | V_2 -> V_198 ) ;
}
if ( V_192 & ( 1 << V_27 . V_48 ) )
V_199 |= V_193 ;
if ( V_192 & ( 1 << V_27 . V_46 ) )
V_199 |= V_200 ;
return V_199 ;
}
static void F_57 ( struct V_187 * V_188 , bool V_201 )
{
struct V_1 * V_2 = V_188 -> V_190 ;
struct V_191 V_27 = V_2 -> V_44 ;
T_1 V_202 = ( 1 << V_27 . V_47 ) | ( 1 << V_27 . V_45 ) | ( 1 << V_27 . V_48 ) |
( 1 << V_27 . V_46 ) ;
if ( V_201 )
F_8 ( V_202 , ( 1 << V_27 . V_48 ) | ( 1 << V_27 . V_47 ) |
( 1 << V_27 . V_45 ) ) ;
else
F_8 ( V_202 , ( 1 << V_27 . V_47 ) | ( 1 << V_27 . V_45 ) ) ;
}
static int F_13 ( struct V_1 * V_2 )
{
V_2 -> V_188 . V_190 = V_2 ;
V_2 -> V_188 . V_203 = & V_204 ;
if ( ! F_58 ( & V_2 -> V_188 ) ) {
F_2 ( L_54 , V_2 -> V_6 . V_12 ) ;
V_2 -> V_188 . V_205 = false ;
return 0 ;
}
V_2 -> V_43 = 0 ;
V_2 -> V_29 = 0 ;
return - V_206 ;
}
static int F_41 ( struct V_1 * V_2 )
{
V_2 -> V_29 = 1 ;
V_2 -> V_43 = 1 ;
V_2 -> V_44 . V_45 = 4 ;
V_2 -> V_44 . V_46 = 5 ;
V_2 -> V_44 . V_47 = 3 ;
V_2 -> V_44 . V_48 = 2 ;
V_2 -> V_197 = 1 << 8 ;
V_2 -> V_196 = 1 << 9 ;
V_2 -> V_198 = 1 << 10 ;
if ( ! F_13 ( V_2 ) ) {
F_2 ( L_55 , V_2 -> V_6 . V_12 ) ;
V_2 -> V_143 = 1 ;
}
return 0 ;
}
static int F_59 ( struct V_1 * V_2 , const T_2 * V_207 , T_1 V_208 )
{
T_1 V_209 ;
T_2 V_210 ;
int V_4 ;
F_8 ( 0xffffff , V_211 | V_212 | V_213 ) ;
F_15 ( 0 ) ;
F_9 ( V_214 ) ;
F_15 ( V_213 ) ;
F_9 ( V_214 ) ;
for ( V_209 = 0 ; V_209 < V_208 ; V_209 ++ ) {
V_210 = V_207 [ V_209 ] ;
for ( V_4 = 0 ; V_4 < 8 ; V_4 ++ ) {
F_16 ( V_212 , 0 ) ;
if ( V_210 & 0x01 )
F_16 ( V_211 , V_211 ) ;
else
F_16 ( V_211 , 0 ) ;
F_16 ( V_212 , V_212 ) ;
V_210 >>= 1 ;
}
}
F_16 ( V_212 , 0 ) ;
F_9 ( V_214 ) ;
for ( V_4 = 0 ; V_4 < 30 ; V_4 ++ ) {
F_16 ( V_212 , 0 ) ;
F_16 ( V_212 , V_212 ) ;
}
F_16 ( V_212 , 0 ) ;
return 0 ;
}
static int F_32 ( struct V_1 * V_2 )
{
const struct V_215 * V_216 ;
int V_217 ;
V_217 = F_60 ( & V_216 , L_56 , & V_2 -> V_6 . V_7 -> V_218 ) ;
if ( V_217 != 0 ) {
F_47 ( L_57 , V_2 -> V_6 . V_12 ) ;
return V_217 ;
}
V_217 = F_59 ( V_2 , V_216 -> V_48 , V_216 -> V_219 ) ;
F_2 ( L_58 ,
V_2 -> V_6 . V_12 , ( V_217 < 0 ) ? L_59 : L_60 ) ;
F_61 ( V_216 ) ;
return V_217 ;
}
static void F_42 ( struct V_1 * V_2 , const T_2 V_220 [ 256 ] )
{
int V_4 ;
T_1 V_221 = 0 ;
int V_5 = - 1 ;
if ( V_2 -> V_6 . type == V_83 ) {
if ( ! strncmp ( V_220 , L_61 , 4 ) ) {
T_2 V_222 = 0 ;
for ( V_4 = 0 ; V_4 < 21 ; V_4 ++ )
V_222 += V_220 [ V_4 ] ;
if ( V_222 != V_220 [ 21 ] )
return;
V_5 = V_105 ;
for ( V_4 = 12 ; V_4 < 21 ; V_4 ++ )
V_221 *= 10 , V_221 += V_220 [ V_4 ] - '0' ;
}
} else {
unsigned short type ;
for ( V_4 = 4 * 16 ; V_4 < 8 * 16 ; V_4 += 16 ) {
T_3 V_222 = ( V_223 T_3 ) F_62 ( V_220 + V_4 , 16 ) ;
if ( ( V_222 & 0xff ) + ( V_222 >> 8 ) == 0xff )
break;
}
if ( V_4 >= 8 * 16 )
return;
V_220 += V_4 ;
type = F_63 ( ( V_224 * ) ( V_220 + 4 ) ) ;
switch( type ) {
case 0x0004 :
V_5 = V_105 ;
break;
case 0x0005 :
V_5 = V_106 ;
break;
case 0x0012 :
case 0x0013 :
V_5 = V_104 ;
break;
case 0x0014 :
case 0x0015 :
V_5 = V_107 ;
break;
case 0x0016 :
case 0x0017 :
case 0x0020 :
V_5 = V_108 ;
break;
case 0x0018 :
case 0x0019 :
case 0x001E :
case 0x001F :
V_5 = V_109 ;
break;
case 0x001A :
case 0x001B :
V_5 = V_110 ;
break;
case 0x0040 :
V_5 = V_113 ;
break;
case 0x0050 :
case 0x0056 :
V_5 = V_114 ;
break;
case 0x0060 :
case 0x0070 :
case 0x00A0 :
V_5 = V_111 ;
F_8 ( 0xffffff , 0x000303 ) ;
break;
case 0x00D8 :
V_5 = V_112 ;
break;
default:
F_2 ( L_62 ,
V_2 -> V_6 . V_12 , type ) ;
break;
}
V_221 = F_64 ( ( V_225 * ) ( V_220 + 6 ) ) ;
}
F_2 ( L_63 ,
V_2 -> V_6 . V_12 , V_5 ,
V_5 > 0 ? V_17 [ V_5 ] . V_13 : L_64 , V_221 ) ;
if ( V_5 < 0 || V_2 -> V_6 . type == V_5 )
return;
if ( V_15 [ V_2 -> V_6 . V_12 ] < V_16 ) {
F_47 ( L_65 ,
V_2 -> V_6 . V_12 ) ;
} else {
F_2 ( L_66 ,
V_2 -> V_6 . V_12 , V_2 -> V_6 . type , V_5 ) ;
V_2 -> V_6 . type = V_5 ;
}
}
static void F_38 ( struct V_1 * V_2 )
{
int V_226 , V_227 , V_228 , V_33 = 0 ;
V_226 = ( V_23 [ 0x41 ] & 0x7 ) ;
V_227 = ( V_23 [ 0x41 ] & 0x18 ) >> 3 ;
V_228 = ( V_23 [ 0x42 ] & 0xf0 ) >> 4 ;
V_2 -> V_28 = ( V_23 [ 0x42 ] & 0x01 ) ;
if ( V_226 == 0 || V_226 == 2 )
if ( V_228 <= 0x0a )
V_33 = V_229 [ V_228 ] ;
if ( V_226 == 1 )
if ( V_228 <= 9 )
V_33 = V_230 [ V_228 ] ;
if ( V_226 == 4 )
if ( V_228 == 0x09 )
V_33 = V_231 ;
F_2 ( L_67 ,
V_2 -> V_6 . V_12 , V_23 [ 0x41 ] , V_23 [ 0x42 ] ) ;
if ( V_33 ) {
V_2 -> V_33 = V_33 ;
F_5 ( L_68 , V_33 ) ;
} else
F_5 ( L_69 ) ;
F_5 ( L_70 ,
V_227 ? L_17 : L_18 ,
V_2 -> V_28 ? L_17 : L_18 ) ;
}
T_1 F_65 ( struct V_1 * V_2 , T_1 V_3 )
{
if ( V_2 -> V_232 == V_233 ) {
if ( V_234 [ V_2 -> V_235 ] . V_236 & V_237 )
V_3 |= 0x10000 ;
else
V_3 &= ~ 0x10000 ;
}
F_16 ( V_17 [ V_2 -> V_6 . type ] . V_22 , V_3 ) ;
return V_3 ;
}
static void F_31 ( struct V_1 * V_2 , int V_238 )
{
int V_202 = ( 1 << V_238 ) ;
F_8 ( V_202 , V_202 ) ;
F_16 ( V_202 , 0 ) ;
F_66 ( 2 ) ;
F_9 ( 500 ) ;
F_16 ( V_202 , V_202 ) ;
if ( V_239 )
F_67 ( V_2 , L_71 ) ;
if ( V_240 )
F_2 ( L_72 ,
V_2 -> V_6 . V_12 , V_238 ) ;
}
static void F_39 ( struct V_1 * V_2 )
{
static int V_241 [] = { 0x08 , 0x09 , 0x0a , 0x0b , 0x0d , 0x0d , 0x01 , 0x02 ,
0x03 , 0x04 , 0x05 , 0x06 , 0x00 } ;
unsigned int V_4 ;
int V_242 ;
T_1 V_192 ;
F_8 ( 0xffffff , ( 1 << 13 ) ) ;
F_15 ( 0 ) ;
F_9 ( 3 ) ;
F_15 ( 1 << 13 ) ;
F_16 ( 0xffffff , 0 ) ;
if ( V_239 )
F_67 ( V_2 , L_73 ) ;
F_23 ( V_243 | V_244 , V_61 ) ;
F_2 ( L_74 ) ;
F_68 ( V_2 , 0x5E , 0 , 0x80 , 1 ) ;
F_2 ( L_75 ) ;
V_192 = F_69 ( V_245 ) ;
V_192 |= V_246 ;
F_23 ( V_192 , V_245 ) ;
F_8 ( 0xffffff , ( 1 << 2 ) ) ;
F_15 ( 0 ) ;
F_9 ( 10 ) ;
F_15 ( 1 << 2 ) ;
for ( V_4 = 0 ; V_4 < F_4 ( V_241 ) ; V_4 ++ ) {
V_242 = F_68 ( V_2 , 0x1E , 0 , V_241 [ V_4 ] , 1 ) ;
if ( V_242 != - 1 ) {
F_2 ( L_76 ,
V_241 [ V_4 ] , V_242 , F_12 ( V_2 , 0x1F , NULL ) ) ;
}
}
F_2 ( L_77 ) ;
}
static void
F_33 ( struct V_1 * V_2 )
{
T_4 V_247 = 0 ;
long V_248 = 0x0E ;
F_2 ( L_78 ,
V_2 -> V_6 . V_12 ) ;
F_23 ( 0x00c3feff , V_249 ) ;
F_23 ( 0 + V_248 , V_250 ) ;
F_70 ( 1 ) ;
F_23 ( 0x10 + V_248 , V_250 ) ;
F_70 ( 10 ) ;
F_23 ( 0 + V_248 , V_250 ) ;
V_247 = F_69 ( V_250 ) ;
if ( ( ( ( V_247 >> 18 ) & 0x01 ) != 0 ) || ( ( ( V_247 >> 19 ) & 0x01 ) != 1 ) ) {
F_2 ( L_79 ,
V_2 -> V_6 . V_12 , V_247 ) ;
}
F_23 ( 0x4400 + V_248 , V_250 ) ;
F_70 ( 10 ) ;
F_23 ( 0x4410 + V_248 , V_250 ) ;
F_70 ( 1 ) ;
F_23 ( V_248 , V_250 ) ;
F_70 ( 1 ) ;
V_247 = F_69 ( V_250 ) ;
if ( ( ( ( V_247 >> 18 ) & 0x01 ) != 0 ) || ( ( ( V_247 >> 19 ) & 0x01 ) != 0 ) ) {
F_2 ( L_80 ,
V_2 -> V_6 . V_12 , V_247 ) ;
return;
}
F_2 ( L_81 , V_2 -> V_6 . V_12 ) ;
}
static void
F_34 ( struct V_1 * V_2 )
{
int V_251 ;
if ( ( F_71 ( V_2 -> V_6 . V_7 -> V_252 ) & ~ 3 ) != 0xC ) {
F_47 ( L_82 ) ;
return;
}
if ( F_71 ( V_2 -> V_6 . V_7 -> V_252 ) != 0xD )
return;
F_23 ( 0x080002 , V_249 ) ;
V_251 = ( F_69 ( V_250 ) >> 21 ) & 7 ;
for (; ; ) {
switch ( V_251 ) {
case 1 :
case 5 :
case 6 :
case 4 :
F_3 ( L_83 ,
V_251 ) ;
F_23 ( 0x080000 , V_250 ) ;
F_70 ( 1 ) ;
F_23 ( 0x000000 , V_250 ) ;
F_70 ( 1 ) ;
break;
case 7 :
F_2 ( L_84 ) ;
return;
case 0 :
F_72 ( L_85 ) ;
return;
default:
F_72 ( L_86 , V_251 ) ;
return;
}
V_251 = ( V_251 << 4 ) | ( ( F_69 ( V_250 ) >> 21 ) & 7 ) ;
switch ( V_251 ) {
case 0x15 :
case 0x56 :
case 0x64 :
case 0x47 :
break;
default:
F_72 ( L_87 ,
V_251 >> 4 , V_251 & 7 ) ;
return;
}
V_251 &= 7 ;
}
}
static void F_73 ( struct V_1 * V_2 , unsigned int V_59 )
{
static const T_2 V_253 [] = { 0x3 , 0x1 , 0x2 , 0x4 , 0xf , 0x7 , 0xe , 0x0 ,
0xd , 0xb , 0xc , 0x6 , 0x9 , 0x5 , 0x8 , 0xa } ;
F_16 ( 0x07f , V_253 [ V_59 ] ) ;
F_16 ( 0x200 , 0x200 ) ;
F_66 ( 1 ) ;
F_16 ( 0x200 , 0x000 ) ;
F_66 ( 1 ) ;
F_16 ( 0x480 , 0x480 ) ;
F_66 ( 1 ) ;
F_16 ( 0x480 , 0x080 ) ;
F_66 ( 1 ) ;
}
static void F_74 ( struct V_1 * V_2 , unsigned int V_59 )
{
F_16 ( 0x0f0000 , V_59 << 16 ) ;
}
static void F_44 ( struct V_1 * V_2 )
{
F_8 ( 0xffffff , 0x0f7fff ) ;
F_15 ( 0x0f7fff ) ;
}
static void F_75 ( struct V_1 * V_2 ,
unsigned char V_254 ,
unsigned char V_255 ,
unsigned char V_48 ) {
unsigned int V_256 ;
V_256 = ( V_48 << 7 ) | ( ( V_255 & 3 ) << 4 ) | ( V_254 & 0xf ) ;
F_16 ( 0x1ff , V_256 ) ;
F_16 ( 0x1ff , V_256 | ( 1 << 8 ) ) ;
F_16 ( 0x1ff , V_256 ) ;
}
static void F_76 ( struct V_1 * V_2 , unsigned int V_59 )
{
int V_254 , V_255 ;
struct V_1 * V_257 ;
static unsigned char V_258 [ 4 ] = { 3 , 0 , 2 , 1 } ;
V_257 = V_259 [ V_2 -> V_6 . V_12 ] ;
if ( V_257 == NULL ) {
return;
}
V_255 = ( V_2 -> V_6 . V_12 - V_257 -> V_6 . V_12 + 1 ) & 3 ;
V_255 = V_258 [ V_255 ] ;
V_254 = V_59 & 0xf ;
if ( V_257 -> V_260 [ V_255 ] != V_254 )
{
F_75 ( V_257 , V_257 -> V_260 [ V_255 ] , V_255 , 0 ) ;
V_257 -> V_260 [ V_255 ] = V_254 ;
F_75 ( V_257 , V_254 , V_255 , 1 ) ;
}
}
static void F_45 ( struct V_1 * V_2 )
{
int V_261 ;
F_8 ( 0x0003ff , 0x0003ff ) ;
F_15 ( 1 << 9 ) ;
F_15 ( 0 ) ;
for ( V_261 = 0 ; V_261 < 4 ; V_261 ++ ) {
V_2 -> V_260 [ V_261 ] = V_261 ;
F_75 ( V_2 , V_261 , V_261 , 1 ) ;
}
if ( ( V_2 -> V_6 . V_12 < 1 ) || ( V_2 -> V_6 . V_12 > V_262 - 3 ) )
return;
V_259 [ V_2 -> V_6 . V_12 - 1 ] = V_2 ;
V_259 [ V_2 -> V_6 . V_12 ] = V_2 ;
V_259 [ V_2 -> V_6 . V_12 + 1 ] = V_2 ;
V_259 [ V_2 -> V_6 . V_12 + 2 ] = V_2 ;
}
static void F_77 ( struct V_1 * V_2 , unsigned int V_59 )
{
static const int V_65 [] = {
V_263 , V_263 | V_264 , V_263 | V_265 , V_263 | V_264 | V_265 ,
V_266 , V_266 | V_264 , V_266 | V_265 , V_266 | V_264 | V_265 ,
V_267 , V_267 | V_268 , V_267 | V_269 , V_267 | V_268 | V_269 ,
V_270 , V_270 | V_268 , V_270 | V_269 , V_270 | V_268 | V_269 ,
} ;
F_15 ( V_65 [ V_59 % 16 ] ) ;
}
static void F_40 ( struct V_1 * V_2 )
{
F_23 ( 0x08 << 16 , V_250 ) ;
F_23 ( 0x04 << 16 , V_250 ) ;
}
static void F_78 ( struct V_1 * V_2 , unsigned int V_59 )
{
F_79 ( L_88 , V_2 -> V_6 . V_12 , V_59 ) ;
F_23 ( V_59 << 20 , V_250 ) ;
}
static void F_80 ( struct V_1 * V_2 , unsigned int V_59 )
{
int V_271 = V_59 % 4 ;
int V_272 = V_59 / 4 ;
F_79 ( L_89 ,
V_2 -> V_6 . V_12 , V_59 , V_272 , V_271 ) ;
F_68 ( V_2 , V_273 , 0x00 ,
( ( V_272 == 3 ) ? ( V_271 | V_271 << 2 ) : 0x00 ) , 1 ) ;
F_68 ( V_2 , V_274 , 0x00 ,
( ( V_272 == 0 ) ? ( V_271 | V_271 << 2 ) : 0x00 ) , 1 ) ;
F_68 ( V_2 , V_275 , 0x00 ,
( ( V_272 == 1 ) ? ( V_271 | V_271 << 2 ) : 0x00 ) , 1 ) ;
F_68 ( V_2 , V_276 , 0x00 ,
( ( V_272 == 2 ) ? ( V_271 | V_271 << 2 ) : 0x00 ) , 1 ) ;
F_68 ( V_2 , V_273 , 0x02 ,
( ( V_272 == 3 ) ? 0x03 : 0x00 ) , 1 ) ;
F_68 ( V_2 , V_274 , 0x02 ,
( ( V_272 == 0 ) ? 0x03 : 0x00 ) , 1 ) ;
F_68 ( V_2 , V_275 , 0x02 ,
( ( V_272 == 1 ) ? 0x03 : 0x00 ) , 1 ) ;
F_68 ( V_2 , V_276 , 0x02 ,
( ( V_272 == 2 ) ? 0x03 : 0x00 ) , 1 ) ;
}
static void F_81 ( struct V_1 * V_2 , unsigned int V_59 )
{
int V_217 ;
long V_277 ;
int V_278 ;
unsigned char V_279 [ 2 ] ;
V_279 [ 0 ] = 0 ;
V_279 [ 1 ] = 0 ;
V_217 = F_68 ( V_2 , ( V_280 << 1 ) , V_279 [ 0 ] , V_279 [ 1 ] , 1 ) ;
if ( V_217 ) {
F_3 ( L_90 ,
V_2 -> V_6 . V_12 , V_217 ) ;
return;
}
V_217 = F_12 ( V_2 , ( V_280 << 1 ) , NULL ) ;
if ( ! ( V_217 & V_281 ) ) {
F_3 ( L_91 ,
V_2 -> V_6 . V_12 , V_217 ) ;
return;
}
V_277 = V_59 ;
V_278 = 0x302 ;
if ( V_2 -> V_5 == V_282 ) {
V_278 ^= 0x180 ;
V_278 |= 7 << 4 ;
}
F_23 ( V_278 , V_249 ) ;
V_278 = F_69 ( V_250 ) ;
if ( V_2 -> V_5 == V_282 )
V_278 = ( V_278 & ~ 0x280 ) | ( ( V_277 & 2 ) << 8 ) | ( ( V_277 & 1 ) << 7 ) ;
else
V_278 = ( V_278 & ~ 0x300 ) | ( ( V_277 & 3 ) << 8 ) ;
F_23 ( V_278 , V_250 ) ;
if ( V_2 -> V_5 == V_282 )
F_17 ( 2 << 5 , ~ V_283 , V_58 ) ;
else
F_20 ( ~ V_283 , V_58 ) ;
F_3 ( L_92 , V_2 -> V_6 . V_12 , ( int ) V_277 ) ;
}
static void F_82 ( struct V_1 * V_2 , unsigned int V_59 )
{
unsigned int V_277 = V_59 % 4 ;
if ( V_59 == V_2 -> V_137 )
V_277 = 0 ;
F_16 ( 0x3 , V_277 ) ;
}
static void F_83 ( struct V_1 * V_2 ,
unsigned char V_254 ,
unsigned char V_255 ,
unsigned char V_48 ) {
const T_1 V_284 = ( ( V_254 & 0xf ) | ( V_255 & 3 ) << 4 ) ;
const T_1 V_285 = 1 << 16 ;
const T_1 V_286 = 1 << 17 ;
const T_1 V_287 = V_48 << 18 ;
F_16 ( 0x1007f , V_284 | V_285 ) ;
F_16 ( 0x20000 , V_286 ) ;
F_16 ( 0x40000 , V_287 ) ;
F_16 ( 0x20000 , ~ V_286 ) ;
}
static void F_84 ( struct V_1 * V_2 , unsigned int V_59 )
{
struct V_1 * V_257 ;
int V_254 , V_255 ;
static unsigned int V_258 [ 4 ] [ 4 ] = { { 0x0 , 0x4 , 0xa , 0x6 } ,
{ 0x1 , 0x5 , 0xb , 0x7 } ,
{ 0x2 , 0x8 , 0xc , 0xe } ,
{ 0x3 , 0x9 , 0xd , 0xf } } ;
V_59 = V_59 % 4 ;
V_257 = V_259 [ V_2 -> V_6 . V_12 ] ;
if ( V_257 == NULL ) {
return;
}
V_255 = ( V_2 -> V_6 . V_12 - V_257 -> V_6 . V_12 ) & 3 ;
V_254 = V_258 [ V_255 ] [ V_59 ] & 0xf ;
if ( V_257 -> V_260 [ V_255 ] != V_254 ) {
F_83 ( V_257 , V_257 -> V_260 [ V_255 ] , V_255 , 0 ) ;
V_257 -> V_260 [ V_255 ] = V_254 ;
F_83 ( V_257 , V_254 , V_255 , 1 ) ;
}
}
static void F_46 ( struct V_1 * V_2 )
{
int V_261 ;
F_8 ( 0xf107f , 0xf107f ) ;
F_15 ( 1 << 19 ) ;
F_15 ( 0 ) ;
for ( V_261 = 0 ; V_261 < 4 ; V_261 ++ ) {
V_2 -> V_260 [ V_261 ] = V_261 ;
F_83 ( V_2 , V_261 , V_261 , 1 ) ;
}
F_68 ( V_2 , 0x18 , 0x5 , 0x90 , 1 ) ;
if ( V_2 -> V_6 . V_12 > V_262 - 4 )
return;
V_259 [ V_2 -> V_6 . V_12 ] = V_2 ;
V_259 [ V_2 -> V_6 . V_12 + 1 ] = V_2 ;
V_259 [ V_2 -> V_6 . V_12 + 2 ] = V_2 ;
V_259 [ V_2 -> V_6 . V_12 + 3 ] = V_2 ;
}
void T_5 F_85 ( void )
{
int V_288 = 0 ;
struct V_289 * V_218 = NULL ;
if ( V_290 & ( V_291 | V_292 ) )
V_288 = 1 ;
if ( V_290 & ( V_293 | V_294 | V_295 ) )
V_296 = 1 ;
if ( V_290 & V_297 )
V_298 = 1 ;
#ifdef F_86
if ( V_290 & F_86 )
V_299 = 0x0A ;
#endif
if ( V_296 )
F_2 ( L_93 ) ;
if ( V_298 )
F_2 ( L_94 ) ;
if ( V_288 ) {
F_2 ( L_95 ) ;
if ( ! V_300 ) {
F_2 ( L_96 ) ;
V_300 = 1 ;
} else {
F_2 ( L_97 ) ;
}
}
if ( V_18 != V_299 )
F_2 ( L_98 , V_299 ) ;
while ( ( V_218 = F_87 ( V_301 ,
V_302 , V_218 ) ) ) {
unsigned char V_303 ;
F_88 ( V_218 , 0x53 , & V_303 ) ;
if ( V_70 )
F_2 ( L_99 ,
V_303 ) ;
}
}
int F_89 ( struct V_1 * V_2 )
{
unsigned char V_304 ;
if ( ! V_296 && ! V_298 && V_18 == V_299 )
return 0 ;
if ( V_240 ) {
if ( V_296 )
F_2 ( L_100 ,
V_2 -> V_6 . V_12 ) ;
if ( V_298 && V_2 -> V_11 >= 878 )
F_2 ( L_101 , V_2 -> V_6 . V_12 ) ;
if ( V_18 != V_299 )
F_2 ( L_102 ,
V_2 -> V_6 . V_12 , V_299 ) ;
}
if ( V_2 -> V_11 < 878 ) {
if ( V_296 )
V_2 -> V_296 = V_305 ;
} else {
F_88 ( V_2 -> V_6 . V_7 , V_306 , & V_304 ) ;
if ( V_296 )
V_304 |= V_307 ;
if ( V_298 )
V_304 |= V_308 ;
F_90 ( V_2 -> V_6 . V_7 , V_306 , V_304 ) ;
}
if ( V_18 != V_299 )
F_90 ( V_2 -> V_6 . V_7 , V_309 , V_299 ) ;
return 0 ;
}
