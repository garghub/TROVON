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
case V_81 :
F_33 ( V_2 ) ;
break;
}
if ( ! V_17 [ V_2 -> V_6 . type ] . V_82 )
F_28 ( V_2 ) ;
}
void F_34 ( struct V_1 * V_2 )
{
V_2 -> V_33 = V_18 ;
if ( V_83 == V_2 -> V_6 . type ) {
F_35 ( V_2 , V_23 , 0xa0 ) ;
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
F_35 ( V_2 , V_23 , 0xa0 ) ;
F_36 ( V_2 ) ;
break;
case V_74 :
case V_95 :
F_35 ( V_2 , V_23 , 0xa0 ) ;
F_37 ( V_2 ) ;
break;
case V_96 :
F_38 ( V_2 ) ;
break;
case V_97 :
F_39 ( V_2 ) ;
break;
case V_98 :
V_2 -> V_29 = 1 ;
V_2 -> V_43 = 1 ;
V_2 -> V_44 = 0x20 ;
V_2 -> V_45 = 0 ;
V_2 -> V_46 = 0x08 ;
V_2 -> V_47 = 0x10 ;
V_2 -> V_48 = 0x38 ;
break;
case V_99 :
case V_100 :
F_40 ( V_2 ) ;
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
F_35 ( V_2 , V_23 , 0xa0 ) ;
F_41 ( V_2 , V_23 ) ;
break;
case V_116 :
F_13 ( V_2 ) ;
break;
case V_24 :
F_35 ( V_2 , V_23 , 0xa0 ) ;
F_42 ( V_2 ) ;
break;
case V_117 :
F_21 ( V_2 ) ;
break;
case V_118 :
F_43 ( V_2 ) ;
break;
case V_119 :
F_44 ( V_2 ) ;
break;
case V_120 :
F_45 ( V_2 ) ;
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
F_46 ( L_36 , V_2 -> V_6 . V_12 ) ;
else
F_2 ( L_37 , V_2 -> V_6 . V_12 , V_2 -> V_33 ) ;
if ( V_133 != V_18 ) {
F_46 ( L_38 , V_2 -> V_6 . V_12 ) ;
F_46 ( L_39 ,
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
V_148 = F_47 ( & V_2 -> V_6 . V_149 ,
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
V_2 -> V_153 = F_47 ( & V_2 -> V_6 . V_149 ,
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
if ( F_47 ( & V_2 -> V_6 . V_149 ,
& V_2 -> V_6 . V_150 , L_42 , 0 , V_145 ) )
return;
goto V_154;
}
case 3 : {
V_2 -> V_156 = F_47 ( & V_2 -> V_6 . V_149 ,
& V_2 -> V_6 . V_150 , L_43 , 0 , F_48 () ) ;
if ( V_2 -> V_156 )
return;
goto V_154;
}
default:
F_46 ( L_44 , V_2 -> V_6 . V_12 ) ;
return;
}
if ( ! V_17 [ V_2 -> V_6 . type ] . V_157 ) {
V_2 -> V_153 = F_47 ( & V_2 -> V_6 . V_149 ,
& V_2 -> V_6 . V_150 , L_41 ,
0 , F_49 ( V_40 >> 1 ) ) ;
} else if ( V_17 [ V_2 -> V_6 . type ] . V_158 ) {
V_2 -> V_153 = F_47 ( & V_2 -> V_6 . V_149 ,
& V_2 -> V_6 . V_150 , L_41 ,
0 , F_49 ( V_152 >> 1 ) ) ;
}
if ( V_2 -> V_153 )
return;
V_2 -> V_156 = F_47 ( & V_2 -> V_6 . V_149 ,
& V_2 -> V_6 . V_150 , L_43 , 0 , F_48 () ) ;
if ( V_2 -> V_156 ) {
F_47 ( & V_2 -> V_6 . V_149 ,
& V_2 -> V_6 . V_150 , L_43 , 0 , F_48 () ) ;
}
if ( ! V_17 [ V_2 -> V_6 . type ] . V_159 ) {
static const unsigned short V_145 [] = {
V_155 >> 1 ,
V_146
} ;
V_2 -> V_160 = F_47 ( & V_2 -> V_6 . V_149 ,
& V_2 -> V_6 . V_150 , L_42 , 0 , V_145 ) ;
if ( V_2 -> V_160 )
return;
}
if ( V_2 -> V_156 )
return;
V_154:
F_46 ( L_45 , V_2 -> V_6 . V_12 ) ;
}
void F_50 ( struct V_1 * V_2 )
{
int V_161 = V_162 ;
if ( V_162 != V_17 [ V_2 -> V_6 . type ] . V_163 )
V_161 = V_17 [ V_2 -> V_6 . type ] . V_163 ;
if ( V_2 -> V_33 != V_35 ) {
struct V_164 V_165 ;
if ( V_2 -> V_29 )
F_47 ( & V_2 -> V_6 . V_149 ,
& V_2 -> V_6 . V_150 , L_46 ,
0 , F_51 ( V_166 ) ) ;
F_47 ( & V_2 -> V_6 . V_149 ,
& V_2 -> V_6 . V_150 , L_46 ,
0 , F_51 ( V_167 ) ) ;
F_47 ( & V_2 -> V_6 . V_149 ,
& V_2 -> V_6 . V_150 , L_46 ,
0 , F_51 ( V_168 ) ) ;
V_165 . V_169 = V_170 ;
V_165 . type = V_2 -> V_33 ;
V_165 . V_161 = V_161 ;
if ( V_2 -> V_29 )
V_165 . V_169 |= V_171 ;
F_52 ( V_2 , V_132 , V_172 , & V_165 ) ;
}
if ( V_2 -> V_53 ) {
struct V_173 V_174 ;
V_174 . V_132 = V_175 ;
V_174 . V_176 = & V_2 -> V_53 ;
F_52 ( V_2 , V_132 , V_177 , & V_174 ) ;
}
}
static void F_42 ( struct V_1 * V_2 )
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
static void F_36 ( struct V_1 * V_2 )
{
struct V_181 V_182 ;
F_53 ( & V_2 -> V_183 , & V_182 , V_23 ) ;
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
static int F_40 ( struct V_1 * V_2 )
{
int V_187 ;
V_2 -> V_29 = 1 ;
V_2 -> V_43 = 1 ;
V_2 -> V_44 = 0x10 ;
V_2 -> V_45 = 0x20 ;
V_2 -> V_46 = 0x08 ;
V_2 -> V_47 = 0x04 ;
V_2 -> V_48 = 0x3c ;
V_2 -> V_188 = 1 << 8 ;
V_2 -> V_189 = 1 << 9 ;
V_2 -> V_190 = 1 << 10 ;
V_187 = 88000 / 62.5 ;
F_54 ( V_2 , 5 * V_187 + 0x358 ) ;
if ( 0x1ed8 == F_55 ( V_2 ) ) {
F_2 ( L_54 , V_2 -> V_6 . V_12 ) ;
V_2 -> V_29 = 1 ;
V_2 -> V_143 = 1 ;
V_2 -> V_43 = 1 ;
} else {
V_2 -> V_29 = 0 ;
V_2 -> V_43 = 0 ;
}
return 0 ;
}
static int F_56 ( struct V_1 * V_2 , const T_2 * V_191 , T_1 V_192 )
{
T_1 V_193 ;
T_2 V_194 ;
int V_4 ;
F_8 ( 0xffffff , V_195 | V_196 | V_197 ) ;
F_14 ( 0 ) ;
F_9 ( V_198 ) ;
F_14 ( V_197 ) ;
F_9 ( V_198 ) ;
for ( V_193 = 0 ; V_193 < V_192 ; V_193 ++ ) {
V_194 = V_191 [ V_193 ] ;
for ( V_4 = 0 ; V_4 < 8 ; V_4 ++ ) {
F_15 ( V_196 , 0 ) ;
if ( V_194 & 0x01 )
F_15 ( V_195 , V_195 ) ;
else
F_15 ( V_195 , 0 ) ;
F_15 ( V_196 , V_196 ) ;
V_194 >>= 1 ;
}
}
F_15 ( V_196 , 0 ) ;
F_9 ( V_198 ) ;
for ( V_4 = 0 ; V_4 < 30 ; V_4 ++ ) {
F_15 ( V_196 , 0 ) ;
F_15 ( V_196 , V_196 ) ;
}
F_15 ( V_196 , 0 ) ;
return 0 ;
}
static int F_31 ( struct V_1 * V_2 )
{
const struct V_199 * V_200 ;
int V_201 ;
V_201 = F_57 ( & V_200 , L_55 , & V_2 -> V_6 . V_7 -> V_202 ) ;
if ( V_201 != 0 ) {
F_46 ( L_56 , V_2 -> V_6 . V_12 ) ;
return V_201 ;
}
V_201 = F_56 ( V_2 , V_200 -> V_203 , V_200 -> V_204 ) ;
F_2 ( L_57 ,
V_2 -> V_6 . V_12 , ( V_201 < 0 ) ? L_58 : L_59 ) ;
F_58 ( V_200 ) ;
return V_201 ;
}
static void F_41 ( struct V_1 * V_2 , const T_2 V_205 [ 256 ] )
{
int V_4 ;
T_1 V_206 = 0 ;
int V_5 = - 1 ;
if ( V_2 -> V_6 . type == V_83 ) {
if ( ! strncmp ( V_205 , L_60 , 4 ) ) {
T_2 V_207 = 0 ;
for ( V_4 = 0 ; V_4 < 21 ; V_4 ++ )
V_207 += V_205 [ V_4 ] ;
if ( V_207 != V_205 [ 21 ] )
return;
V_5 = V_105 ;
for ( V_4 = 12 ; V_4 < 21 ; V_4 ++ )
V_206 *= 10 , V_206 += V_205 [ V_4 ] - '0' ;
}
} else {
unsigned short type ;
for ( V_4 = 4 * 16 ; V_4 < 8 * 16 ; V_4 += 16 ) {
T_3 V_207 = ( V_208 T_3 ) F_59 ( V_205 + V_4 , 16 ) ;
if ( ( V_207 & 0xff ) + ( V_207 >> 8 ) == 0xff )
break;
}
if ( V_4 >= 8 * 16 )
return;
V_205 += V_4 ;
type = F_60 ( ( V_209 * ) ( V_205 + 4 ) ) ;
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
F_2 ( L_61 ,
V_2 -> V_6 . V_12 , type ) ;
break;
}
V_206 = F_61 ( ( V_210 * ) ( V_205 + 6 ) ) ;
}
F_2 ( L_62 ,
V_2 -> V_6 . V_12 , V_5 ,
V_5 > 0 ? V_17 [ V_5 ] . V_13 : L_63 , V_206 ) ;
if ( V_5 < 0 || V_2 -> V_6 . type == V_5 )
return;
if ( V_15 [ V_2 -> V_6 . V_12 ] < V_16 ) {
F_46 ( L_64 ,
V_2 -> V_6 . V_12 ) ;
} else {
F_2 ( L_65 ,
V_2 -> V_6 . V_12 , V_2 -> V_6 . type , V_5 ) ;
V_2 -> V_6 . type = V_5 ;
}
}
static void F_37 ( struct V_1 * V_2 )
{
int V_211 , V_212 , V_213 , V_33 = 0 ;
V_211 = ( V_23 [ 0x41 ] & 0x7 ) ;
V_212 = ( V_23 [ 0x41 ] & 0x18 ) >> 3 ;
V_213 = ( V_23 [ 0x42 ] & 0xf0 ) >> 4 ;
V_2 -> V_28 = ( V_23 [ 0x42 ] & 0x01 ) ;
if ( V_211 == 0 || V_211 == 2 )
if ( V_213 <= 0x0a )
V_33 = V_214 [ V_213 ] ;
if ( V_211 == 1 )
if ( V_213 <= 9 )
V_33 = V_215 [ V_213 ] ;
if ( V_211 == 4 )
if ( V_213 == 0x09 )
V_33 = V_216 ;
F_2 ( L_66 ,
V_2 -> V_6 . V_12 , V_23 [ 0x41 ] , V_23 [ 0x42 ] ) ;
if ( V_33 ) {
V_2 -> V_33 = V_33 ;
F_5 ( L_67 , V_33 ) ;
} else
F_5 ( L_68 ) ;
F_5 ( L_69 ,
V_212 ? L_17 : L_18 ,
V_2 -> V_28 ? L_17 : L_18 ) ;
}
T_1 F_62 ( struct V_1 * V_2 , T_1 V_3 )
{
if ( V_2 -> V_217 == V_218 ) {
if ( V_219 [ V_2 -> V_220 ] . V_221 & V_222 )
V_3 |= 0x10000 ;
else
V_3 &= ~ 0x10000 ;
}
F_15 ( V_17 [ V_2 -> V_6 . type ] . V_22 , V_3 ) ;
return V_3 ;
}
static void F_30 ( struct V_1 * V_2 , int V_223 )
{
int V_224 = ( 1 << V_223 ) ;
F_8 ( V_224 , V_224 ) ;
F_15 ( V_224 , 0 ) ;
F_63 ( 2 ) ;
F_9 ( 500 ) ;
F_15 ( V_224 , V_224 ) ;
if ( V_225 )
F_64 ( V_2 , L_70 ) ;
if ( V_226 )
F_2 ( L_71 ,
V_2 -> V_6 . V_12 , V_223 ) ;
}
static void F_38 ( struct V_1 * V_2 )
{
static int V_227 [] = { 0x08 , 0x09 , 0x0a , 0x0b , 0x0d , 0x0d , 0x01 , 0x02 ,
0x03 , 0x04 , 0x05 , 0x06 , 0x00 } ;
unsigned int V_4 ;
int V_228 ;
T_1 V_229 ;
F_8 ( 0xffffff , ( 1 << 13 ) ) ;
F_14 ( 0 ) ;
F_9 ( 3 ) ;
F_14 ( 1 << 13 ) ;
F_15 ( 0xffffff , 0 ) ;
if ( V_225 )
F_64 ( V_2 , L_72 ) ;
F_22 ( V_230 | V_231 , V_61 ) ;
F_2 ( L_73 ) ;
F_65 ( V_2 , 0x5E , 0 , 0x80 , 1 ) ;
F_2 ( L_74 ) ;
V_229 = F_66 ( V_232 ) ;
V_229 |= V_233 ;
F_22 ( V_229 , V_232 ) ;
F_8 ( 0xffffff , ( 1 << 2 ) ) ;
F_14 ( 0 ) ;
F_9 ( 10 ) ;
F_14 ( 1 << 2 ) ;
for ( V_4 = 0 ; V_4 < F_4 ( V_227 ) ; V_4 ++ ) {
V_228 = F_65 ( V_2 , 0x1E , 0 , V_227 [ V_4 ] , 1 ) ;
if ( V_228 != - 1 ) {
F_2 ( L_75 ,
V_227 [ V_4 ] , V_228 , F_12 ( V_2 , 0x1F , NULL ) ) ;
}
}
F_2 ( L_76 ) ;
}
static void
F_32 ( struct V_1 * V_2 )
{
T_4 V_234 = 0 ;
long V_235 = 0x0E ;
F_2 ( L_77 ,
V_2 -> V_6 . V_12 ) ;
F_22 ( 0x00c3feff , V_236 ) ;
F_22 ( 0 + V_235 , V_237 ) ;
F_67 ( 1 ) ;
F_22 ( 0x10 + V_235 , V_237 ) ;
F_67 ( 10 ) ;
F_22 ( 0 + V_235 , V_237 ) ;
V_234 = F_66 ( V_237 ) ;
if ( ( ( ( V_234 >> 18 ) & 0x01 ) != 0 ) || ( ( ( V_234 >> 19 ) & 0x01 ) != 1 ) ) {
F_2 ( L_78 ,
V_2 -> V_6 . V_12 , V_234 ) ;
}
F_22 ( 0x4400 + V_235 , V_237 ) ;
F_67 ( 10 ) ;
F_22 ( 0x4410 + V_235 , V_237 ) ;
F_67 ( 1 ) ;
F_22 ( V_235 , V_237 ) ;
F_67 ( 1 ) ;
V_234 = F_66 ( V_237 ) ;
if ( ( ( ( V_234 >> 18 ) & 0x01 ) != 0 ) || ( ( ( V_234 >> 19 ) & 0x01 ) != 0 ) ) {
F_2 ( L_79 ,
V_2 -> V_6 . V_12 , V_234 ) ;
return;
}
F_2 ( L_80 , V_2 -> V_6 . V_12 ) ;
}
static void
F_33 ( struct V_1 * V_2 )
{
int V_238 ;
if ( ( F_68 ( V_2 -> V_6 . V_7 -> V_239 ) & ~ 3 ) != 0xC ) {
F_46 ( L_81 ) ;
return;
}
if ( F_68 ( V_2 -> V_6 . V_7 -> V_239 ) != 0xD )
return;
F_22 ( 0x080002 , V_236 ) ;
V_238 = ( F_66 ( V_237 ) >> 21 ) & 7 ;
for (; ; ) {
switch ( V_238 ) {
case 1 :
case 5 :
case 6 :
case 4 :
F_3 ( L_82 ,
V_238 ) ;
F_22 ( 0x080000 , V_237 ) ;
F_67 ( 1 ) ;
F_22 ( 0x000000 , V_237 ) ;
F_67 ( 1 ) ;
break;
case 7 :
F_2 ( L_83 ) ;
return;
case 0 :
F_69 ( L_84 ) ;
return;
default:
F_69 ( L_85 , V_238 ) ;
return;
}
V_238 = ( V_238 << 4 ) | ( ( F_66 ( V_237 ) >> 21 ) & 7 ) ;
switch ( V_238 ) {
case 0x15 :
case 0x56 :
case 0x64 :
case 0x47 :
break;
default:
F_69 ( L_86 ,
V_238 >> 4 , V_238 & 7 ) ;
return;
}
V_238 &= 7 ;
}
}
static void F_70 ( struct V_1 * V_2 , int V_240 )
{
if ( V_2 -> V_189 ) {
F_15 ( V_2 -> V_189 | V_2 -> V_188 | V_2 -> V_190 ,
V_2 -> V_189 | V_2 -> V_188 | V_2 -> V_190 ) ;
F_9 ( 5 ) ;
}
F_15 ( V_240 , 0 ) ;
F_9 ( 5 ) ;
if ( V_2 -> V_189 ) {
F_15 ( V_2 -> V_188 | V_2 -> V_190 , 0 ) ;
F_9 ( 5 ) ;
}
}
static void F_71 ( struct V_1 * V_2 , int V_240 )
{
if ( V_2 -> V_189 ) {
F_15 ( V_2 -> V_189 | V_2 -> V_188 | V_2 -> V_190 ,
V_2 -> V_189 | V_2 -> V_188 | V_2 -> V_190 ) ;
F_9 ( 5 ) ;
}
F_15 ( V_240 , V_240 ) ;
F_9 ( 5 ) ;
if ( V_2 -> V_189 ) {
F_15 ( V_2 -> V_188 | V_2 -> V_190 , 0 ) ;
F_9 ( 5 ) ;
}
}
static int F_72 ( struct V_1 * V_2 , int V_240 )
{
if ( V_2 -> V_189 ) {
F_15 ( V_2 -> V_189 | V_2 -> V_188 | V_2 -> V_190 ,
V_2 -> V_189 | V_2 -> V_188 | V_2 -> V_190 ) ;
F_9 ( 5 ) ;
F_15 ( V_2 -> V_188 | V_2 -> V_190 , 0 ) ;
F_9 ( 5 ) ;
}
return F_10 () & ( V_240 ) ;
}
static int F_55 ( struct V_1 * V_2 )
{
unsigned long V_241 ;
int V_68 = 0 ;
int V_4 ;
F_8 ( V_2 -> V_48 , V_2 -> V_46 | V_2 -> V_44 ) ;
if ( V_2 -> V_189 ) {
F_15 ( V_2 -> V_189 | V_2 -> V_188 | V_2 -> V_190 ,
V_2 -> V_189 | V_2 -> V_188 | V_2 -> V_190 ) ;
F_9 ( 5 ) ;
}
if ( V_225 )
F_64 ( V_2 , L_87 ) ;
F_70 ( V_2 , V_2 -> V_44 ) ;
F_70 ( V_2 , V_2 -> V_46 ) ;
F_9 ( 10 ) ;
V_241 = V_242 + F_73 ( 1000 ) ;
while ( F_72 ( V_2 , V_2 -> V_47 ) && F_74 ( V_242 , V_241 ) )
F_75 () ;
if ( F_72 ( V_2 , V_2 -> V_47 ) ) {
F_46 ( L_88 , V_2 -> V_6 . V_12 ) ;
return - 1 ;
}
F_76 ( L_89 , V_2 -> V_6 . V_12 ) ;
for ( V_4 = 0 ; V_4 < 24 ; V_4 ++ ) {
F_9 ( 5 ) ;
F_71 ( V_2 , V_2 -> V_46 ) ;
F_9 ( 5 ) ;
F_77 ( L_90 ,
F_72 ( V_2 , V_2 -> V_45 ) == 0 ? 'T' : '-' ) ;
F_70 ( V_2 , V_2 -> V_46 ) ;
V_68 <<= 1 ;
V_68 |= ( F_72 ( V_2 , V_2 -> V_47 ) == 0 ) ? 0 : 1 ;
F_77 ( L_90 ,
F_72 ( V_2 , V_2 -> V_45 ) == 0 ? 'S' : 'M' ) ;
}
F_77 ( L_11 ) ;
F_76 ( L_91 , V_2 -> V_6 . V_12 , V_68 ) ;
return V_68 ;
}
static int F_54 ( struct V_1 * V_2 , int V_68 )
{
int V_4 ;
int V_243 = V_68 ;
F_8 ( V_2 -> V_48 , V_2 -> V_46 | V_2 -> V_44 | V_2 -> V_47 ) ;
if ( V_2 -> V_189 ) {
F_15 ( V_2 -> V_189 | V_2 -> V_188 | V_2 -> V_190 ,
V_2 -> V_189 | V_2 -> V_188 | V_2 -> V_190 ) ;
F_9 ( 5 ) ;
}
if ( V_225 )
F_64 ( V_2 , L_92 ) ;
F_76 ( L_93 , V_2 -> V_6 . V_12 , V_68 ) ;
F_70 ( V_2 , V_2 -> V_46 ) ;
F_71 ( V_2 , V_2 -> V_44 ) ;
for ( V_4 = 0 ; V_4 < 25 ; V_4 ++ ) {
if ( V_243 & 0x1000000 )
F_71 ( V_2 , V_2 -> V_47 ) ;
else
F_70 ( V_2 , V_2 -> V_47 ) ;
V_243 <<= 1 ;
F_71 ( V_2 , V_2 -> V_46 ) ;
F_9 ( 10 ) ;
F_70 ( V_2 , V_2 -> V_46 ) ;
F_9 ( 10 ) ;
}
F_70 ( V_2 , V_2 -> V_44 ) ;
return 0 ;
}
void F_78 ( struct V_1 * V_2 , unsigned short V_187 )
{
F_76 ( L_94 , V_187 ) ;
F_54 ( V_2 , 5 * V_187 + 0x358 ) ;
}
static void F_79 ( struct V_1 * V_2 , unsigned int V_59 )
{
static const T_2 V_244 [] = { 0x3 , 0x1 , 0x2 , 0x4 , 0xf , 0x7 , 0xe , 0x0 ,
0xd , 0xb , 0xc , 0x6 , 0x9 , 0x5 , 0x8 , 0xa } ;
F_15 ( 0x07f , V_244 [ V_59 ] ) ;
F_15 ( 0x200 , 0x200 ) ;
F_63 ( 1 ) ;
F_15 ( 0x200 , 0x000 ) ;
F_63 ( 1 ) ;
F_15 ( 0x480 , 0x480 ) ;
F_63 ( 1 ) ;
F_15 ( 0x480 , 0x080 ) ;
F_63 ( 1 ) ;
}
static void F_80 ( struct V_1 * V_2 , unsigned int V_59 )
{
F_15 ( 0x0f0000 , V_59 << 16 ) ;
}
static void F_43 ( struct V_1 * V_2 )
{
F_8 ( 0xffffff , 0x0f7fff ) ;
F_14 ( 0x0f7fff ) ;
}
static void F_81 ( struct V_1 * V_2 ,
unsigned char V_245 ,
unsigned char V_246 ,
unsigned char V_203 ) {
unsigned int V_247 ;
V_247 = ( V_203 << 7 ) | ( ( V_246 & 3 ) << 4 ) | ( V_245 & 0xf ) ;
F_15 ( 0x1ff , V_247 ) ;
F_15 ( 0x1ff , V_247 | ( 1 << 8 ) ) ;
F_15 ( 0x1ff , V_247 ) ;
}
static void F_82 ( struct V_1 * V_2 , unsigned int V_59 )
{
int V_245 , V_246 ;
struct V_1 * V_248 ;
static unsigned char V_249 [ 4 ] = { 3 , 0 , 2 , 1 } ;
V_248 = V_250 [ V_2 -> V_6 . V_12 ] ;
if ( V_248 == NULL ) {
return;
}
V_246 = ( V_2 -> V_6 . V_12 - V_248 -> V_6 . V_12 + 1 ) & 3 ;
V_246 = V_249 [ V_246 ] ;
V_245 = V_59 & 0xf ;
if ( V_248 -> V_251 [ V_246 ] != V_245 )
{
F_81 ( V_248 , V_248 -> V_251 [ V_246 ] , V_246 , 0 ) ;
V_248 -> V_251 [ V_246 ] = V_245 ;
F_81 ( V_248 , V_245 , V_246 , 1 ) ;
}
}
static void F_44 ( struct V_1 * V_2 )
{
int V_252 ;
F_8 ( 0x0003ff , 0x0003ff ) ;
F_14 ( 1 << 9 ) ;
F_14 ( 0 ) ;
for ( V_252 = 0 ; V_252 < 4 ; V_252 ++ ) {
V_2 -> V_251 [ V_252 ] = V_252 ;
F_81 ( V_2 , V_252 , V_252 , 1 ) ;
}
if ( ( V_2 -> V_6 . V_12 < 1 ) || ( V_2 -> V_6 . V_12 > V_253 - 3 ) )
return;
V_250 [ V_2 -> V_6 . V_12 - 1 ] = V_2 ;
V_250 [ V_2 -> V_6 . V_12 ] = V_2 ;
V_250 [ V_2 -> V_6 . V_12 + 1 ] = V_2 ;
V_250 [ V_2 -> V_6 . V_12 + 2 ] = V_2 ;
}
static void F_83 ( struct V_1 * V_2 , unsigned int V_59 )
{
static const int V_65 [] = {
V_254 , V_254 | V_255 , V_254 | V_256 , V_254 | V_255 | V_256 ,
V_257 , V_257 | V_255 , V_257 | V_256 , V_257 | V_255 | V_256 ,
V_258 , V_258 | V_259 , V_258 | V_260 , V_258 | V_259 | V_260 ,
V_261 , V_261 | V_259 , V_261 | V_260 , V_261 | V_259 | V_260 ,
} ;
F_14 ( V_65 [ V_59 % 16 ] ) ;
}
static void F_39 ( struct V_1 * V_2 )
{
F_22 ( 0x08 << 16 , V_237 ) ;
F_22 ( 0x04 << 16 , V_237 ) ;
}
static void F_84 ( struct V_1 * V_2 , unsigned int V_59 )
{
F_76 ( L_95 , V_2 -> V_6 . V_12 , V_59 ) ;
F_22 ( V_59 << 20 , V_237 ) ;
}
static void F_85 ( struct V_1 * V_2 , unsigned int V_59 )
{
int V_262 = V_59 % 4 ;
int V_263 = V_59 / 4 ;
F_76 ( L_96 ,
V_2 -> V_6 . V_12 , V_59 , V_263 , V_262 ) ;
F_65 ( V_2 , V_264 , 0x00 ,
( ( V_263 == 3 ) ? ( V_262 | V_262 << 2 ) : 0x00 ) , 1 ) ;
F_65 ( V_2 , V_265 , 0x00 ,
( ( V_263 == 0 ) ? ( V_262 | V_262 << 2 ) : 0x00 ) , 1 ) ;
F_65 ( V_2 , V_266 , 0x00 ,
( ( V_263 == 1 ) ? ( V_262 | V_262 << 2 ) : 0x00 ) , 1 ) ;
F_65 ( V_2 , V_267 , 0x00 ,
( ( V_263 == 2 ) ? ( V_262 | V_262 << 2 ) : 0x00 ) , 1 ) ;
F_65 ( V_2 , V_264 , 0x02 ,
( ( V_263 == 3 ) ? 0x03 : 0x00 ) , 1 ) ;
F_65 ( V_2 , V_265 , 0x02 ,
( ( V_263 == 0 ) ? 0x03 : 0x00 ) , 1 ) ;
F_65 ( V_2 , V_266 , 0x02 ,
( ( V_263 == 1 ) ? 0x03 : 0x00 ) , 1 ) ;
F_65 ( V_2 , V_267 , 0x02 ,
( ( V_263 == 2 ) ? 0x03 : 0x00 ) , 1 ) ;
}
static void F_86 ( struct V_1 * V_2 , unsigned int V_59 )
{
int V_201 ;
long V_268 ;
int V_269 ;
unsigned char V_270 [ 2 ] ;
V_270 [ 0 ] = 0 ;
V_270 [ 1 ] = 0 ;
V_201 = F_65 ( V_2 , ( V_271 << 1 ) , V_270 [ 0 ] , V_270 [ 1 ] , 1 ) ;
if ( V_201 ) {
F_3 ( L_97 ,
V_2 -> V_6 . V_12 , V_201 ) ;
return;
}
V_201 = F_12 ( V_2 , ( V_271 << 1 ) , NULL ) ;
if ( ! ( V_201 & V_272 ) ) {
F_3 ( L_98 ,
V_2 -> V_6 . V_12 , V_201 ) ;
return;
}
V_268 = V_59 ;
V_269 = 0x302 ;
if ( V_2 -> V_5 == V_273 ) {
V_269 ^= 0x180 ;
V_269 |= 7 << 4 ;
}
F_22 ( V_269 , V_236 ) ;
V_269 = F_66 ( V_237 ) ;
if ( V_2 -> V_5 == V_273 )
V_269 = ( V_269 & ~ 0x280 ) | ( ( V_268 & 2 ) << 8 ) | ( ( V_268 & 1 ) << 7 ) ;
else
V_269 = ( V_269 & ~ 0x300 ) | ( ( V_268 & 3 ) << 8 ) ;
F_22 ( V_269 , V_237 ) ;
if ( V_2 -> V_5 == V_273 )
F_16 ( 2 << 5 , ~ V_274 , V_58 ) ;
else
F_19 ( ~ V_274 , V_58 ) ;
F_3 ( L_99 , V_2 -> V_6 . V_12 , ( int ) V_268 ) ;
}
static void F_87 ( struct V_1 * V_2 , unsigned int V_59 )
{
unsigned int V_268 = V_59 % 4 ;
if ( V_59 == V_2 -> V_137 )
V_268 = 0 ;
F_15 ( 0x3 , V_268 ) ;
}
static void F_88 ( struct V_1 * V_2 ,
unsigned char V_245 ,
unsigned char V_246 ,
unsigned char V_203 ) {
const T_1 V_275 = ( ( V_245 & 0xf ) | ( V_246 & 3 ) << 4 ) ;
const T_1 V_276 = 1 << 16 ;
const T_1 V_277 = 1 << 17 ;
const T_1 V_278 = V_203 << 18 ;
F_15 ( 0x1007f , V_275 | V_276 ) ;
F_15 ( 0x20000 , V_277 ) ;
F_15 ( 0x40000 , V_278 ) ;
F_15 ( 0x20000 , ~ V_277 ) ;
}
static void F_89 ( struct V_1 * V_2 , unsigned int V_59 )
{
struct V_1 * V_248 ;
int V_245 , V_246 ;
static unsigned int V_249 [ 4 ] [ 4 ] = { { 0x0 , 0x4 , 0xa , 0x6 } ,
{ 0x1 , 0x5 , 0xb , 0x7 } ,
{ 0x2 , 0x8 , 0xc , 0xe } ,
{ 0x3 , 0x9 , 0xd , 0xf } } ;
V_59 = V_59 % 4 ;
V_248 = V_250 [ V_2 -> V_6 . V_12 ] ;
if ( V_248 == NULL ) {
return;
}
V_246 = ( V_2 -> V_6 . V_12 - V_248 -> V_6 . V_12 ) & 3 ;
V_245 = V_249 [ V_246 ] [ V_59 ] & 0xf ;
if ( V_248 -> V_251 [ V_246 ] != V_245 ) {
F_88 ( V_248 , V_248 -> V_251 [ V_246 ] , V_246 , 0 ) ;
V_248 -> V_251 [ V_246 ] = V_245 ;
F_88 ( V_248 , V_245 , V_246 , 1 ) ;
}
}
static void F_45 ( struct V_1 * V_2 )
{
int V_252 ;
F_8 ( 0xf107f , 0xf107f ) ;
F_14 ( 1 << 19 ) ;
F_14 ( 0 ) ;
for ( V_252 = 0 ; V_252 < 4 ; V_252 ++ ) {
V_2 -> V_251 [ V_252 ] = V_252 ;
F_88 ( V_2 , V_252 , V_252 , 1 ) ;
}
F_65 ( V_2 , 0x18 , 0x5 , 0x90 , 1 ) ;
if ( V_2 -> V_6 . V_12 > V_253 - 4 )
return;
V_250 [ V_2 -> V_6 . V_12 ] = V_2 ;
V_250 [ V_2 -> V_6 . V_12 + 1 ] = V_2 ;
V_250 [ V_2 -> V_6 . V_12 + 2 ] = V_2 ;
V_250 [ V_2 -> V_6 . V_12 + 3 ] = V_2 ;
}
void T_5 F_90 ( void )
{
int V_279 = 0 ;
struct V_280 * V_202 = NULL ;
if ( V_281 & ( V_282 | V_283 ) )
V_279 = 1 ;
if ( V_281 & ( V_284 | V_285 | V_286 ) )
V_287 = 1 ;
if ( V_281 & V_288 )
V_289 = 1 ;
#ifdef F_91
if ( V_281 & F_91 )
V_290 = 0x0A ;
#endif
if ( V_287 )
F_2 ( L_100 ) ;
if ( V_289 )
F_2 ( L_101 ) ;
if ( V_279 ) {
F_2 ( L_102 ) ;
if ( ! V_291 ) {
F_2 ( L_103 ) ;
V_291 = 1 ;
} else {
F_2 ( L_104 ) ;
}
}
if ( V_18 != V_290 )
F_2 ( L_105 , V_290 ) ;
while ( ( V_202 = F_92 ( V_292 ,
V_293 , V_202 ) ) ) {
unsigned char V_294 ;
F_93 ( V_202 , 0x53 , & V_294 ) ;
if ( V_70 )
F_2 ( L_106 ,
V_294 ) ;
}
}
int F_94 ( struct V_1 * V_2 )
{
unsigned char V_295 ;
if ( ! V_287 && ! V_289 && V_18 == V_290 )
return 0 ;
if ( V_226 ) {
if ( V_287 )
F_2 ( L_107 ,
V_2 -> V_6 . V_12 ) ;
if ( V_289 && V_2 -> V_11 >= 878 )
F_2 ( L_108 , V_2 -> V_6 . V_12 ) ;
if ( V_18 != V_290 )
F_2 ( L_109 ,
V_2 -> V_6 . V_12 , V_290 ) ;
}
if ( V_2 -> V_11 < 878 ) {
if ( V_287 )
V_2 -> V_287 = V_296 ;
} else {
F_93 ( V_2 -> V_6 . V_7 , V_297 , & V_295 ) ;
if ( V_287 )
V_295 |= V_298 ;
if ( V_289 )
V_295 |= V_299 ;
F_95 ( V_2 -> V_6 . V_7 , V_297 , V_295 ) ;
}
if ( V_18 != V_290 )
F_95 ( V_2 -> V_6 . V_7 , V_300 , V_290 ) ;
return 0 ;
}
