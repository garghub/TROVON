static int F_1 ( struct V_1 * V_2 , int V_3 )
{
T_1 V_4 ;
if ( ! V_3 ) {
F_2 ( V_5 >> 2 , ( 1 << 26 ) ) ;
F_3 ( V_6 >> 2 , ( 1 << 26 ) ) ;
return 0 ;
}
F_2 ( V_5 >> 2 , ( 1 << 26 ) ) ;
F_2 ( V_6 >> 2 , ( 1 << 26 ) ) ;
F_4 ( 10 ) ;
F_2 ( V_5 >> 2 , ( 1 << 28 ) ) ;
F_3 ( V_6 >> 2 , ( 1 << 28 ) ) ;
F_4 ( 10 ) ;
F_2 ( V_6 >> 2 , ( 1 << 28 ) ) ;
F_4 ( 10 ) ;
V_4 = F_5 ( V_6 ) & ( 1 << 27 ) ;
F_6 ( L_1 , V_7 , V_4 ? L_2 : L_3 ) ;
if ( ! V_4 )
F_3 ( V_6 >> 2 , ( 1 << 26 ) ) ;
return V_4 ;
}
static int F_7 ( struct V_8 * V_9 )
{
static T_2 V_10 [] = { V_11 , 0x3d , 0x28 } ;
static T_2 V_12 [] = { V_13 , 0x80 } ;
static T_2 V_14 [] = { V_15 , 0x40 } ;
static T_2 V_16 [] = { V_17 , 0x28 , 0xa0 } ;
static T_2 V_18 [] = { V_19 , 0x31 } ;
static T_2 V_20 [] = { 0x7b , 0x04 } ;
static T_2 V_21 [] = { V_22 , 0x0f } ;
static T_2 V_23 [] = { V_24 , 0x0d } ;
static T_2 V_25 [] = { V_26 , 0x00 , 0x00 , 0x00 , 0x00 } ;
struct V_1 * V_2 = V_9 -> V_27 -> V_28 ;
F_6 ( L_4 , V_7 ) ;
F_8 ( V_9 , V_10 , sizeof( V_10 ) ) ;
F_4 ( 200 ) ;
F_8 ( V_9 , V_12 , sizeof( V_12 ) ) ;
F_8 ( V_9 , V_14 , sizeof( V_14 ) ) ;
F_8 ( V_9 , V_16 , sizeof( V_16 ) ) ;
F_8 ( V_9 , V_18 , sizeof( V_18 ) ) ;
F_8 ( V_9 , V_21 , sizeof( V_21 ) ) ;
F_8 ( V_9 , V_20 , sizeof( V_20 ) ) ;
F_8 ( V_9 , V_23 , sizeof( V_23 ) ) ;
F_8 ( V_9 , V_25 , sizeof( V_25 ) ) ;
return 0 ;
}
static int F_9 ( struct V_8 * V_9 )
{
static T_2 V_10 [] = { V_11 , 0x38 , 0x2d } ;
static T_2 V_12 [] = { V_13 , 0x80 } ;
static T_2 V_14 [] = { V_15 , 0x40 } ;
static T_2 V_16 [] = { V_17 , 0x28 , 0xa0 } ;
static T_2 V_18 [] = { V_19 , 0x33 } ;
F_8 ( V_9 , V_10 , sizeof( V_10 ) ) ;
F_4 ( 200 ) ;
F_8 ( V_9 , V_12 , sizeof( V_12 ) ) ;
F_8 ( V_9 , V_14 , sizeof( V_14 ) ) ;
F_8 ( V_9 , V_16 , sizeof( V_16 ) ) ;
F_8 ( V_9 , V_18 , sizeof( V_18 ) ) ;
return 0 ;
}
static int F_10 ( struct V_8 * V_9 )
{
static T_2 V_10 [] = { V_11 , 0x38 , 0x2d } ;
static T_2 V_12 [] = { V_13 , 0x80 } ;
static T_2 V_14 [] = { V_15 , 0x40 } ;
static T_2 V_16 [] = { V_17 , 0xe } ;
static T_2 V_18 [] = { V_19 , 0x33 } ;
F_8 ( V_9 , V_10 , sizeof( V_10 ) ) ;
F_4 ( 200 ) ;
F_8 ( V_9 , V_12 , sizeof( V_12 ) ) ;
F_8 ( V_9 , V_14 , sizeof( V_14 ) ) ;
F_8 ( V_9 , V_16 , sizeof( V_16 ) ) ;
F_8 ( V_9 , V_18 , sizeof( V_18 ) ) ;
return 0 ;
}
static int F_11 ( struct V_8 * V_9 )
{
struct V_29 * V_30 = & V_9 -> V_31 ;
T_2 V_32 [] = { 0x00 , 0xf1 } ;
T_2 V_3 [] = { 0x00 , 0x71 } ;
struct V_33 V_34 = { . V_35 = 0x43 , . V_36 = 0 , . V_37 = V_32 , . V_38 = sizeof( V_32 ) } ;
struct V_1 * V_2 = V_9 -> V_27 -> V_28 ;
struct V_39 V_40 ;
V_40 . V_41 = 0 ;
V_40 . type = V_42 ;
V_40 . V_43 = V_30 -> V_43 / 1000 * 16 / 1000 ;
if ( V_9 -> V_44 . V_45 )
V_9 -> V_44 . V_45 ( V_9 , 1 ) ;
F_12 ( & V_2 -> V_46 , & V_34 , 1 ) ;
F_13 ( V_2 , V_41 , V_47 , & V_40 ) ;
V_34 . V_37 = V_3 ;
if ( V_9 -> V_44 . V_45 )
V_9 -> V_44 . V_45 ( V_9 , 1 ) ;
F_12 ( & V_2 -> V_46 , & V_34 , 1 ) ;
F_1 ( V_2 , V_48 ) ;
return F_7 ( V_9 ) ;
}
static int F_14 ( struct V_8 * V_9 , int V_49 )
{
struct V_1 * V_2 = V_9 -> V_27 -> V_28 ;
unsigned char V_50 [] = { 0x45 , 0x97 } ;
unsigned char V_51 [] = { 0x45 , 0xc1 } ;
unsigned char V_52 [] = { 0x45 , 0x81 } ;
struct V_33 V_34 = { . V_35 = 0x4b , . V_36 = 0 , . V_37 = V_50 , . V_38 = 2 } ;
if ( F_12 ( & V_2 -> V_46 , & V_34 , 1 ) != 1 ) {
F_15 ( L_5 ) ;
return - V_53 ;
}
if ( V_49 )
V_34 . V_37 = V_51 ;
else
V_34 . V_37 = V_52 ;
if ( F_12 ( & V_2 -> V_46 , & V_34 , 1 ) != 1 ) {
F_15 ( L_5 ) ;
return - V_53 ;
}
F_16 ( 20 ) ;
return 0 ;
}
static int F_17 ( struct V_8 * V_9 ,
const struct V_54 * * V_55 , char * V_56 )
{
struct V_1 * V_2 = V_9 -> V_27 -> V_28 ;
return F_18 ( V_55 , V_56 , & V_2 -> V_57 -> V_2 ) ;
}
static int F_19 ( struct V_8 * V_9 )
{
struct V_29 * V_30 = & V_9 -> V_31 ;
struct V_1 * V_2 = V_9 -> V_27 -> V_28 ;
struct V_58 * V_59 = V_9 -> V_60 ;
T_2 V_35 = V_59 -> V_61 -> V_62 ;
T_2 V_63 [ 4 ] ;
struct V_33 V_64 = { . V_35 = V_35 , . V_36 = 0 , . V_37 = V_63 , . V_38 =
sizeof( V_63 ) } ;
int V_65 = 0 ;
T_2 V_66 , V_67 , V_68 ;
V_65 = V_30 -> V_43 + 36166000 ;
if ( V_65 < 87000000 )
return - V_69 ;
else if ( V_65 < 130000000 )
V_67 = 3 ;
else if ( V_65 < 160000000 )
V_67 = 5 ;
else if ( V_65 < 200000000 )
V_67 = 6 ;
else if ( V_65 < 290000000 )
V_67 = 3 ;
else if ( V_65 < 420000000 )
V_67 = 5 ;
else if ( V_65 < 480000000 )
V_67 = 6 ;
else if ( V_65 < 620000000 )
V_67 = 3 ;
else if ( V_65 < 830000000 )
V_67 = 5 ;
else if ( V_65 < 895000000 )
V_67 = 7 ;
else
return - V_69 ;
if ( V_30 -> V_43 < 49000000 )
return - V_69 ;
else if ( V_30 -> V_43 < 161000000 )
V_66 = 1 ;
else if ( V_30 -> V_43 < 444000000 )
V_66 = 2 ;
else if ( V_30 -> V_43 < 861000000 )
V_66 = 4 ;
else
return - V_69 ;
switch ( V_30 -> V_70 ) {
case 6000000 :
V_68 = 0 ;
break;
case 7000000 :
V_68 = 0 ;
break;
case 8000000 :
V_68 = 1 ;
break;
default:
return - V_69 ;
}
V_65 = ( ( ( V_30 -> V_43 / 1000 ) * 6 ) + 217496 ) / 1000 ;
V_63 [ 0 ] = ( V_65 >> 8 ) & 0x7f ;
V_63 [ 1 ] = V_65 & 0xff ;
V_63 [ 2 ] = 0xca ;
V_63 [ 3 ] = ( V_67 << 5 ) | ( V_68 << 3 ) | V_66 ;
if ( V_9 -> V_44 . V_45 )
V_9 -> V_44 . V_45 ( V_9 , 1 ) ;
if ( F_12 ( & V_2 -> V_46 , & V_64 , 1 ) != 1 ) {
F_15 ( L_6 ,
V_35 << 1 ) ;
return - V_53 ;
}
F_16 ( 1 ) ;
return 0 ;
}
static int F_20 ( struct V_8 * V_9 )
{
struct V_1 * V_2 = V_9 -> V_27 -> V_28 ;
struct V_58 * V_59 = V_9 -> V_60 ;
T_2 V_35 = V_59 -> V_61 -> V_62 ;
static T_2 V_71 [] = { 0x0b , 0xf5 , 0x85 , 0xab } ;
struct V_33 V_64 = { . V_35 = V_35 , . V_36 = 0 , . V_37 = V_71 , . V_38 = sizeof( V_71 ) } ;
if ( V_9 -> V_44 . V_45 )
V_9 -> V_44 . V_45 ( V_9 , 1 ) ;
if ( F_12 ( & V_2 -> V_46 , & V_64 , 1 ) != 1 )
return - V_53 ;
F_16 ( 1 ) ;
return 0 ;
}
static int F_21 ( struct V_8 * V_9 )
{
struct V_1 * V_2 = V_9 -> V_27 -> V_28 ;
struct V_58 * V_59 = V_9 -> V_60 ;
T_2 V_35 = V_59 -> V_61 -> V_62 ;
static T_2 V_34 [] = { 0x0b , 0xf5 , 0x86 , 0xab } ;
struct V_33 V_72 = { . V_35 = V_35 , . V_36 = 0 , . V_37 = V_34 , . V_38 = sizeof( V_34 ) } ;
if ( V_9 -> V_44 . V_45 )
V_9 -> V_44 . V_45 ( V_9 , 1 ) ;
if ( F_12 ( & V_2 -> V_46 , & V_72 , 1 ) != 1 )
return - V_53 ;
return 0 ;
}
static int F_22 ( struct V_8 * V_9 )
{
return F_19 ( V_9 ) ;
}
static int F_23 ( struct V_8 * V_9 )
{
struct V_1 * V_2 = V_9 -> V_27 -> V_28 ;
struct V_58 * V_59 = V_9 -> V_60 ;
T_2 V_35 = V_59 -> V_61 -> V_62 ;
static T_2 V_34 [] = { 0x0b , 0xdc , 0x86 , 0xa4 } ;
struct V_33 V_73 = { . V_35 = V_35 , . V_36 = 0 , . V_37 = V_34 , . V_38 = sizeof( V_34 ) } ;
if ( V_9 -> V_44 . V_45 )
V_9 -> V_44 . V_45 ( V_9 , 1 ) ;
if ( F_12 ( & V_2 -> V_46 , & V_73 , 1 ) != 1 )
return - V_53 ;
return 0 ;
}
static int F_24 ( struct V_8 * V_9 )
{
struct V_1 * V_2 = V_9 -> V_27 -> V_28 ;
static T_2 V_34 [] = { 0x00 , 0x40 } ;
struct V_33 V_72 = { . V_35 = 0x43 , . V_36 = 0 , . V_37 = V_34 , . V_38 = sizeof( V_34 ) } ;
if ( F_21 ( V_9 ) )
return - V_53 ;
F_16 ( 1 ) ;
if ( F_12 ( & V_2 -> V_46 , & V_72 , 1 ) != 1 )
return - V_53 ;
return 0 ;
}
static int F_25 ( struct V_8 * V_9 )
{
struct V_1 * V_2 = V_9 -> V_27 -> V_28 ;
static T_2 V_34 [] = { 0x00 , 0x14 } ;
struct V_33 V_73 = { . V_35 = 0x43 , . V_36 = 0 , . V_37 = V_34 , . V_38 = sizeof( V_34 ) } ;
if ( F_23 ( V_9 ) )
return - V_53 ;
if ( V_9 -> V_44 . V_45 )
V_9 -> V_44 . V_45 ( V_9 , 1 ) ;
F_12 ( & V_2 -> V_46 , & V_73 , 1 ) ;
return 0 ;
}
static int F_26 ( struct V_8 * V_9 )
{
struct V_1 * V_2 = V_9 -> V_27 -> V_28 ;
if ( V_2 -> V_74 )
V_2 -> V_74 ( V_9 ) ;
V_9 -> V_44 . V_45 ( V_9 , 1 ) ;
return 0 ;
}
static int F_27 ( struct V_8 * V_9 , int V_49 )
{
struct V_58 * V_59 = V_9 -> V_60 ;
T_2 V_35 = V_59 -> V_61 -> V_75 ;
static T_2 V_76 [] = { 0x21 , 0xc0 } ;
static T_2 V_77 [] = { 0x21 , 0x80 } ;
struct V_33 V_78 = { . V_35 = V_35 , . V_36 = 0 , . V_38 = 2 } ;
if ( V_49 ) {
V_78 . V_37 = V_76 ;
} else {
V_78 . V_37 = V_77 ;
}
if ( F_12 ( V_59 -> V_79 , & V_78 , 1 ) != 1 ) {
struct V_1 * V_2 = V_9 -> V_27 -> V_28 ;
F_15 ( L_7 ) ;
return - V_53 ;
}
F_16 ( 20 ) ;
return 0 ;
}
static int F_28 ( struct V_8 * V_9 )
{
struct V_1 * V_2 = V_9 -> V_27 -> V_28 ;
struct V_58 * V_59 = V_9 -> V_60 ;
switch ( V_59 -> V_61 -> V_80 ) {
case 0 : break;
case 1 : F_6 ( L_8 ) ;
F_29 ( V_2 , 21 , 0 ) ;
break;
case 2 : F_6 ( L_9 ) ;
F_29 ( V_2 , 21 , 1 ) ;
break;
}
return 0 ;
}
static int F_30 ( struct V_8 * V_9 )
{
struct V_1 * V_2 = V_9 -> V_27 -> V_28 ;
struct V_58 * V_59 = V_9 -> V_60 ;
switch ( V_59 -> V_61 -> V_80 ) {
case 0 : break;
case 1 : F_6 ( L_9 ) ;
F_29 ( V_2 , 21 , 1 ) ;
break;
case 2 : F_6 ( L_8 ) ;
F_29 ( V_2 , 21 , 0 ) ;
break;
}
return 0 ;
}
static int F_31 ( struct V_1 * V_2 ,
struct V_81 * V_82 ,
struct V_83 * V_84 )
{
struct V_85 * V_86 ;
V_86 = F_32 ( & V_2 -> V_87 , 1 ) ;
if ( ! V_86 )
return - V_69 ;
V_86 -> V_27 . V_88 = F_33 ( V_89 , V_82 , & V_2 -> V_46 ) ;
if ( V_86 -> V_27 . V_88 ) {
if ( V_82 -> V_75 )
V_86 -> V_27 . V_88 -> V_44 . V_45 = F_27 ;
if ( F_33 ( V_90 , V_86 -> V_27 . V_88 ,
V_82 -> V_62 ,
& V_2 -> V_46 , V_84 ) )
return 0 ;
F_15 ( L_10 ,
V_82 -> V_62 ) ;
}
return - V_69 ;
}
static int F_34 ( struct V_8 * V_9 )
{
struct V_1 * V_2 = V_9 -> V_27 -> V_28 ;
F_28 ( V_9 ) ;
F_29 ( V_2 , 22 , 1 ) ;
return 0 ;
}
static int F_35 ( struct V_8 * V_9 )
{
struct V_1 * V_2 = V_9 -> V_27 -> V_28 ;
F_29 ( V_2 , 22 , 0 ) ;
F_30 ( V_9 ) ;
return 0 ;
}
static int F_36 ( struct V_8 * V_9 , T_3 V_91 )
{
int V_92 = - V_53 ;
struct V_1 * V_2 = V_9 -> V_27 -> V_28 ;
if ( V_9 -> V_44 . V_45 ) {
V_9 -> V_44 . V_45 ( V_9 , 1 ) ;
if ( V_2 -> V_93 )
V_92 = V_2 -> V_93 ( V_9 , V_91 ) ;
V_9 -> V_44 . V_45 ( V_9 , 0 ) ;
}
return V_92 ;
}
static int F_37 ( struct V_8 * V_9 , long V_94 )
{
int V_92 = - V_53 ;
struct V_1 * V_2 = V_9 -> V_27 -> V_28 ;
if ( V_9 -> V_44 . V_45 ) {
V_9 -> V_44 . V_45 ( V_9 , 1 ) ;
if ( V_2 -> V_95 )
V_92 = V_2 -> V_95 ( V_9 , V_94 ) ;
V_9 -> V_44 . V_45 ( V_9 , 0 ) ;
}
return V_92 ;
}
static int F_38 ( struct V_8 * V_9 , T_3 V_91 )
{
struct V_1 * V_2 = V_9 -> V_27 -> V_28 ;
T_2 V_96 [ 2 ] = { 0x1f , 00 } ;
T_2 V_97 ;
struct V_33 V_34 [] = { { . V_35 = 0x08 , . V_36 = 0 , . V_37 = V_96 , . V_38 = 1 } ,
{ . V_35 = 0x08 , . V_36 = V_98 , . V_37 = & V_97 , . V_38 = 1 } } ;
if ( F_12 ( & V_2 -> V_46 , V_34 , 2 ) != 2 )
return - V_53 ;
if ( V_91 == V_99 )
V_96 [ 1 ] = V_97 | 0x10 ;
else
V_96 [ 1 ] = V_97 & 0xef ;
V_34 [ 0 ] . V_38 = 2 ;
F_12 ( & V_2 -> V_46 , V_34 , 1 ) ;
return 0 ;
}
static int F_39 ( struct V_8 * V_9 , long V_94 )
{
struct V_1 * V_2 = V_9 -> V_27 -> V_28 ;
F_15 ( L_11 , V_7 ) ;
return - V_53 ;
}
static int F_40 ( struct V_1 * V_2 )
{
int V_100 ;
int V_101 = 0 ;
struct V_85 * V_86 ;
struct V_102 * V_103 ;
F_41 ( & V_2 -> V_87 . V_104 ) ;
F_42 ( & V_2 -> V_87 . V_105 ) ;
F_43 ( V_106 L_12 , V_7 ) ;
V_86 = F_44 ( & V_2 -> V_87 , 1 ) ;
if ( ! V_86 ) {
F_43 ( V_107 L_13 , V_7 ) ;
return - V_108 ;
}
V_2 -> V_109 . V_110 = 32 ;
V_2 -> V_109 . V_111 = 32 * 4 ;
V_86 -> V_27 . V_56 = V_2 -> V_56 ;
V_103 = & V_86 -> V_27 . V_112 ;
V_103 -> type = V_113 ;
V_103 -> V_114 = V_115 | V_116 ;
V_103 -> V_117 = & V_2 -> V_118 ;
V_103 -> V_44 = & V_119 ;
V_103 -> V_120 = & V_121 ;
V_103 -> V_122 = sizeof( struct V_123 ) ;
V_103 -> V_124 = V_125 ;
V_103 -> V_104 = & V_2 -> V_104 ;
V_100 = F_45 ( V_103 ) ;
if ( V_100 ) {
F_46 ( & V_2 -> V_87 ) ;
return V_100 ;
}
switch ( V_2 -> V_126 ) {
case V_127 :
F_6 ( L_14 ) ;
V_86 -> V_27 . V_88 = F_33 ( V_128 , & V_129 ,
& V_2 -> V_46 ) ;
if ( V_86 -> V_27 . V_88 ) {
V_86 -> V_27 . V_88 -> V_44 . V_130 . V_131 = F_11 ;
}
break;
case V_132 :
case V_133 :
F_6 ( L_15 ) ;
V_86 -> V_27 . V_88 = F_33 ( V_128 , & V_134 ,
& V_2 -> V_46 ) ;
if ( V_86 -> V_27 . V_88 ) {
F_33 ( V_135 , V_86 -> V_27 . V_88 ,
& V_2 -> V_46 , 0x61 ,
V_136 ) ;
}
break;
case V_137 :
F_6 ( L_16 ) ;
V_86 -> V_27 . V_88 = F_33 ( V_128 ,
& V_138 ,
& V_2 -> V_46 ) ;
V_101 = 1 ;
break;
case V_139 :
V_86 -> V_27 . V_88 = F_33 ( V_89 ,
& V_140 ,
& V_2 -> V_46 ) ;
if ( V_86 -> V_27 . V_88 ) {
F_33 ( V_135 , V_86 -> V_27 . V_88 ,
& V_2 -> V_46 , V_140 . V_62 ,
V_141 ) ;
}
break;
case V_142 :
V_86 -> V_27 . V_88 = F_33 ( V_89 ,
& V_143 ,
& V_2 -> V_46 ) ;
if ( V_86 -> V_27 . V_88 ) {
V_86 -> V_27 . V_88 -> V_44 . V_130 . V_144 = F_20 ;
V_86 -> V_27 . V_88 -> V_44 . V_130 . V_131 = F_19 ;
}
break;
case V_145 :
case V_146 :
if ( F_31 ( V_2 , & V_147 ,
& V_148 ) < 0 )
goto V_149;
break;
case V_150 :
case V_151 :
case V_152 :
V_86 -> V_27 . V_88 = F_33 ( V_89 ,
& V_153 ,
& V_2 -> V_46 ) ;
if ( V_86 -> V_27 . V_88 ) {
V_2 -> V_74 = V_86 -> V_27 . V_88 -> V_44 . V_154 ;
V_86 -> V_27 . V_88 -> V_44 . V_154 = F_26 ;
V_86 -> V_27 . V_88 -> V_44 . V_130 . V_144 = F_24 ;
V_86 -> V_27 . V_88 -> V_44 . V_130 . V_154 = F_25 ;
V_86 -> V_27 . V_88 -> V_44 . V_130 . V_131 = F_22 ;
}
break;
case V_155 :
V_86 -> V_27 . V_88 = F_33 ( V_89 ,
& V_156 ,
& V_2 -> V_46 ) ;
if ( V_86 -> V_27 . V_88 ) {
V_2 -> V_74 = V_86 -> V_27 . V_88 -> V_44 . V_154 ;
V_86 -> V_27 . V_88 -> V_44 . V_154 = F_26 ;
V_86 -> V_27 . V_88 -> V_44 . V_130 . V_144 = F_24 ;
V_86 -> V_27 . V_88 -> V_44 . V_130 . V_154 = F_25 ;
V_86 -> V_27 . V_88 -> V_44 . V_130 . V_131 = F_22 ;
}
break;
case V_157 :
V_86 -> V_27 . V_88 = F_33 ( V_89 ,
& V_158 ,
& V_2 -> V_46 ) ;
if ( V_86 -> V_27 . V_88 ) {
V_86 -> V_27 . V_88 -> V_44 . V_130 . V_144 = F_20 ;
V_86 -> V_27 . V_88 -> V_44 . V_130 . V_131 = F_19 ;
}
break;
case V_159 :
if ( F_31 ( V_2 , & V_160 ,
& V_161 ) < 0 )
goto V_149;
break;
case V_162 :
V_86 -> V_27 . V_88 = F_33 ( V_163 ,
& V_164 ,
& V_2 -> V_46 ) ;
if ( V_86 -> V_27 . V_88 != NULL ) {
F_33 ( V_165 , V_86 -> V_27 . V_88 ,
& V_2 -> V_46 , 0x4b ,
& V_166 ) ;
F_33 ( V_167 , V_86 -> V_27 . V_88 ,
0x60 , & V_2 -> V_46 ,
& V_168 ) ;
}
break;
case V_169 :
if ( F_31 ( V_2 , & V_170 ,
& V_148 ) < 0 )
goto V_149;
break;
case V_171 :
if ( F_31 ( V_2 , & V_172 ,
& V_173 ) < 0 )
goto V_149;
break;
case V_174 :
if ( F_31 ( V_2 , & V_175 ,
& V_173 ) < 0 )
goto V_149;
break;
case V_176 :
V_86 -> V_27 . V_88 = F_33 ( V_177 ,
& V_178 ,
& V_2 -> V_46 ) ;
if ( V_86 -> V_27 . V_88 ) {
F_33 ( V_165 , V_86 -> V_27 . V_88 ,
& V_2 -> V_46 , 0x4b ,
& V_166 ) ;
F_33 ( V_167 , V_86 -> V_27 . V_88 ,
0x60 , & V_2 -> V_46 ,
& V_168 ) ;
}
break;
case V_179 :
if ( F_31 ( V_2 , & V_180 ,
& V_148 ) < 0 )
goto V_149;
break;
case V_181 :
if ( F_31 ( V_2 , & V_147 ,
& V_148 ) < 0 )
goto V_149;
break;
case V_182 :
if ( ! V_183 ) {
if ( F_31 ( V_2 , & V_184 ,
& V_148 ) < 0 )
goto V_149;
} else {
V_86 -> V_27 . V_88 = F_33 ( V_185 , & V_186 , & V_2 -> V_46 ) ;
if ( V_86 -> V_27 . V_88 ) {
if ( F_33 ( V_187 , V_86 -> V_27 . V_88 , 0x63 ,
& V_2 -> V_46 , 0 ) == NULL ) {
F_15 ( L_17 , V_7 ) ;
goto V_149;
}
if ( F_33 ( V_188 , V_86 -> V_27 . V_88 ,
& V_2 -> V_46 ,
0x08 , 0 , 0 , false ) == NULL ) {
F_15 ( L_18 , V_7 ) ;
goto V_149;
}
}
}
break;
case V_189 :
case V_190 :
V_86 -> V_27 . V_88 = F_33 ( V_89 ,
& V_191 ,
& V_2 -> V_46 ) ;
if ( V_86 -> V_27 . V_88 ) {
if ( F_33 ( V_90 , V_86 -> V_27 . V_88 ,
V_191 . V_62 , & V_2 -> V_46 ,
& V_192 ) == NULL ) {
F_15 ( L_10 ,
V_191 . V_62 ) ;
goto V_149;
}
} else
F_15 ( L_19 ) ;
break;
case V_193 :
if ( F_31 ( V_2 , & V_194 ,
& V_148 ) < 0 )
goto V_149;
break;
case V_195 :
if ( ! V_183 ) {
if ( F_31 ( V_2 , & V_196 ,
& V_148 ) < 0 )
goto V_149;
} else {
V_86 -> V_27 . V_88 = F_33 ( V_185 ,
& V_186 , & V_2 -> V_46 ) ;
if ( V_86 -> V_27 . V_88 ) {
struct V_8 * V_9 = V_86 -> V_27 . V_88 ;
T_2 V_197 = V_2 -> V_198 [ 2 ] ;
T_2 V_199 = 0xc4 ;
struct V_33 V_34 = { . V_35 = 0x08 , . V_36 = 0 , . V_38 = 1 } ;
if ( F_33 ( V_187 , V_86 -> V_27 . V_88 ,
0x60 , & V_2 -> V_46 , 0 ) == NULL ) {
F_15 ( L_20
L_21 , V_7 ) ;
goto V_149;
}
if ( V_197 != 0x08 ) {
V_9 -> V_44 . V_45 ( V_9 , 1 ) ;
if ( F_33 ( V_200 , V_9 ,
& V_2 -> V_46 , 0x08 , 0 , 0 ) == NULL ) {
F_15 ( L_22
L_21 , V_7 ) ;
goto V_149;
}
if ( V_197 == 0x07 ) {
V_34 . V_37 = & V_199 ;
F_12 ( & V_2 -> V_46 , & V_34 , 1 ) ;
}
V_9 -> V_44 . V_45 ( V_9 , 0 ) ;
V_2 -> V_93 = V_9 -> V_44 . V_201 ;
V_9 -> V_44 . V_201 = F_36 ;
V_2 -> V_95 = V_9 -> V_44 . V_202 ;
V_9 -> V_44 . V_202 = F_37 ;
} else {
V_9 -> V_44 . V_201 = F_38 ;
V_9 -> V_44 . V_202 = F_39 ;
}
}
}
break;
case V_203 :
V_86 -> V_27 . V_88 = F_33 ( V_204 , & V_205 ,
& V_2 -> V_46 ) ;
if ( V_86 -> V_27 . V_88 )
F_33 ( V_206 , V_86 -> V_27 . V_88 , 0x61 ,
NULL , V_207 ) ;
break;
case V_208 :
case V_209 :
V_86 -> V_27 . V_88 = F_33 ( V_204 , & V_210 ,
& V_2 -> V_46 ) ;
if ( V_86 -> V_27 . V_88 )
F_33 ( V_135 , V_86 -> V_27 . V_88 ,
& V_2 -> V_46 , 0x61 ,
V_211 ) ;
break;
case V_212 :
F_29 ( V_2 , 18 , 1 ) ;
F_47 ( V_2 , 0 ,
V_213 , 1 ) ;
V_86 -> V_27 . V_88 = F_33 ( V_214 ,
& V_215 ,
& V_2 -> V_46 ) ;
if ( V_86 -> V_27 . V_88 != NULL ) {
F_33 ( V_165 , V_86 -> V_27 . V_88 ,
& V_2 -> V_46 , 0x4b ,
& V_166 ) ;
F_33 ( V_167 , V_86 -> V_27 . V_88 ,
0x60 , & V_2 -> V_46 ,
& V_216 ) ;
}
break;
case V_217 :
V_86 -> V_27 . V_88 = F_33 ( V_185 , & V_186 ,
& V_2 -> V_46 ) ;
if ( V_86 -> V_27 . V_88 ) {
if ( F_33 ( V_187 , V_86 -> V_27 . V_88 , 0x60 ,
& V_2 -> V_46 , 0 ) == NULL ) {
F_15 ( L_23 , V_7 ) ;
goto V_149;
}
if ( F_33 ( V_188 , V_86 -> V_27 . V_88 ,
& V_2 -> V_46 ,
0x08 , 0 , 0 , false ) == NULL ) {
F_15 ( L_24 , V_7 ) ;
goto V_149;
}
}
break;
case V_218 :
V_86 -> V_27 . V_88 = F_33 ( V_89 ,
& V_140 ,
& V_2 -> V_46 ) ;
if ( V_86 -> V_27 . V_88 ) {
V_2 -> V_74 = V_86 -> V_27 . V_88 -> V_44 . V_154 ;
V_86 -> V_27 . V_88 -> V_44 . V_154 = F_26 ;
F_33 ( V_135 , V_86 -> V_27 . V_88 ,
& V_2 -> V_46 , V_140 . V_62 ,
V_141 ) ;
}
break;
case V_219 :
V_86 -> V_27 . V_88 = F_33 ( V_89 ,
& V_153 ,
& V_2 -> V_46 ) ;
if ( V_86 -> V_27 . V_88 ) {
V_86 -> V_27 . V_88 -> V_44 . V_130 . V_144 = F_21 ;
V_86 -> V_27 . V_88 -> V_44 . V_130 . V_131 = F_22 ;
}
break;
case V_220 :
if ( F_31 ( V_2 , & V_221 ,
& V_148 ) < 0 )
goto V_149;
break;
case V_222 :
if ( F_31 ( V_2 , & V_223 ,
& V_148 ) < 0 )
goto V_149;
break;
case V_224 :
if ( F_31 ( V_2 , & V_225 ,
& V_161 ) < 0 )
goto V_149;
break;
case V_226 :
if ( F_31 ( V_2 , & V_227 ,
& V_161 ) < 0 )
goto V_149;
break;
case V_228 :
if ( F_31 ( V_2 , & V_229 ,
& V_161 ) < 0 )
goto V_149;
break;
case V_230 :
if ( F_31 ( V_2 , & V_231 ,
& V_148 ) < 0 )
goto V_149;
break;
case V_232 :
if ( F_31 ( V_2 , & V_233 ,
& V_234 ) < 0 )
goto V_149;
break;
case V_235 :
V_86 -> V_27 . V_88 = F_33 ( V_185 , & V_186 ,
& V_2 -> V_46 ) ;
if ( V_86 -> V_27 . V_88 ) {
if ( F_33 ( V_187 , V_86 -> V_27 . V_88 , 0x60 ,
& V_2 -> V_46 , 0 ) == NULL ) {
F_15 ( L_23 , V_7 ) ;
goto V_149;
}
if ( F_33 ( V_236 , V_86 -> V_27 . V_88 ,
& V_2 -> V_46 , 0 , 0 ) == NULL ) {
F_15 ( L_25 , V_7 ) ;
goto V_149;
}
}
break;
case V_237 :
if ( F_31 ( V_2 , & V_196 ,
& V_148 ) < 0 )
goto V_149;
break;
case V_238 :
if ( F_31 ( V_2 , & V_225 ,
& V_161 ) < 0 )
goto V_149;
break;
case V_239 :
F_6 ( L_26 ) ;
F_29 ( V_2 , 25 , 0 ) ;
F_16 ( 10 ) ;
F_29 ( V_2 , 25 , 1 ) ;
V_86 -> V_27 . V_88 = F_33 ( V_128 ,
& V_138 ,
& V_2 -> V_46 ) ;
V_101 = 1 ;
break;
case V_240 :
V_86 -> V_27 . V_88 = F_33 ( V_185 ,
& V_241 , & V_2 -> V_46 ) ;
if ( V_86 -> V_27 . V_88 ) {
struct V_8 * V_9 ;
if ( F_33 ( V_206 , V_86 -> V_27 . V_88 , 0x60 ,
& V_2 -> V_46 , V_242 ) == NULL ) {
F_15 ( L_27
L_21 , V_7 ) ;
goto V_149;
}
V_9 = V_86 -> V_27 . V_88 ;
V_9 -> V_44 . V_45 ( V_9 , 1 ) ;
if ( F_33 ( V_200 , V_9 ,
& V_2 -> V_46 , 0x08 , 0 , 0 ) == NULL ) {
F_15 ( L_28
L_21 , V_7 ) ;
goto V_149;
}
V_9 -> V_44 . V_45 ( V_9 , 0 ) ;
V_2 -> V_93 = V_9 -> V_44 . V_201 ;
V_9 -> V_44 . V_201 = F_36 ;
V_2 -> V_95 = V_9 -> V_44 . V_202 ;
V_9 -> V_44 . V_202 = F_37 ;
}
break;
case V_243 :
F_29 ( V_2 , 25 , 0 ) ;
F_16 ( 10 ) ;
F_29 ( V_2 , 25 , 1 ) ;
V_86 -> V_27 . V_88 = F_33 ( V_128 ,
& V_138 ,
& V_2 -> V_46 ) ;
V_101 = 1 ;
break;
case V_244 :
if ( ! V_183 ) {
if ( F_31 ( V_2 , & V_245 ,
& V_161 ) < 0 )
goto V_149;
} else {
V_86 -> V_27 . V_88 = F_33 ( V_185 ,
& V_186 , & V_2 -> V_46 ) ;
if ( V_86 -> V_27 . V_88 ) {
if ( F_33 ( V_187 ,
V_86 -> V_27 . V_88 , 0x60 ,
& V_2 -> V_46 , 0 ) == NULL ) {
F_15 ( L_29
L_30 , V_7 ) ;
goto V_149;
}
if ( F_33 ( V_236 , V_86 -> V_27 . V_88 ,
& V_2 -> V_46 , 0 , 0 ) == NULL ) {
F_15 ( L_31
L_32 , V_7 ) ;
goto V_149;
}
}
}
break;
case V_246 :
if ( ! V_183 ) {
if ( F_31 ( V_2 , & V_247 ,
& V_161 ) < 0 )
goto V_149;
} else {
V_86 -> V_27 . V_88 = F_33 ( V_185 ,
& V_186 , & V_2 -> V_46 ) ;
if ( V_86 -> V_27 . V_88 ) {
if ( F_33 ( V_187 ,
V_86 -> V_27 . V_88 , 0x60 ,
& V_2 -> V_46 , 0 ) == NULL ) {
F_15 ( L_33
L_30 , V_7 ) ;
goto V_149;
}
if ( F_33 ( V_236 , V_86 -> V_27 . V_88 ,
& V_2 -> V_46 , 0 , 0 ) == NULL ) {
F_15 ( L_34
L_32 , V_7 ) ;
goto V_149;
}
}
}
break;
case V_248 :
if ( F_31 ( V_2 , & V_170 ,
& V_148 ) < 0 )
goto V_149;
break;
case V_249 :
V_86 -> V_27 . V_88 = F_33 ( V_250 ,
& V_251 ,
& V_2 -> V_46 ) ;
if ( V_86 -> V_27 . V_88 ) {
F_33 ( V_135 , V_86 -> V_27 . V_88 ,
& V_2 -> V_46 , 0x61 ,
V_252 ) ;
}
break;
case V_253 :
V_86 -> V_27 . V_88 = F_33 ( V_250 ,
& V_254 ,
& V_2 -> V_46 ) ;
if ( V_86 -> V_27 . V_88 ) {
F_33 ( V_255 , V_86 -> V_27 . V_88 ,
& V_2 -> V_46 , & V_256 ) ;
}
break;
case V_257 :
V_86 -> V_27 . V_88 = F_33 ( V_250 ,
& V_254 ,
& V_2 -> V_46 ) ;
if ( V_86 -> V_27 . V_88 ) {
F_33 ( V_255 , V_86 -> V_27 . V_88 ,
& V_2 -> V_46 , & V_256 ) ;
}
break;
case V_258 :
case V_259 :
V_86 -> V_27 . V_88 = F_33 ( V_260 ,
& V_261 , & V_2 -> V_46 ) ;
if ( V_86 -> V_27 . V_88 ) {
if ( F_33 ( V_262 , V_86 -> V_27 . V_88 ,
& V_263 , & V_2 -> V_46 ) == NULL ) {
F_15 ( L_35 ,
V_7 ) ;
}
}
break;
case V_264 :
V_86 -> V_27 . V_88 = F_33 ( V_260 ,
& V_265 , & V_2 -> V_46 ) ;
if ( V_86 -> V_27 . V_88 )
if ( F_33 ( V_266 , V_86 -> V_27 . V_88 ,
0x60 , & V_2 -> V_46 ) == NULL )
F_15 ( L_36 ,
V_7 ) ;
break;
case V_267 :
V_86 -> V_27 . V_88 = F_33 ( V_250 ,
& V_268 ,
& V_2 -> V_46 ) ;
if ( V_86 -> V_27 . V_88 != NULL ) {
if ( F_33 ( V_269 ,
V_86 -> V_27 . V_88 ,
& V_2 -> V_46 ,
& V_270 ) == NULL )
F_15 ( L_37 ) ;
}
break;
case V_271 :
V_86 -> V_27 . V_88 = F_33 ( V_163 ,
& V_272 ,
& V_2 -> V_46 ) ;
if ( V_86 -> V_27 . V_88 != NULL ) {
F_33 ( V_165 , V_86 -> V_27 . V_88 ,
& V_2 -> V_46 , 0x4b ,
& V_166 ) ;
F_33 ( V_167 , V_86 -> V_27 . V_88 ,
0x60 , & V_2 -> V_46 ,
& V_273 ) ;
}
break;
case V_274 :
V_86 -> V_27 . V_88 = F_33 ( V_163 ,
& V_275 ,
& V_2 -> V_46 ) ;
if ( V_86 -> V_27 . V_88 != NULL ) {
F_33 ( V_165 , V_86 -> V_27 . V_88 ,
& V_2 -> V_46 , 0x4b ,
& V_166 ) ;
F_33 ( V_167 , V_86 -> V_27 . V_88 ,
0x60 , & V_2 -> V_46 ,
& V_276 ) ;
}
break;
case V_277 :
F_47 ( V_2 , 0 ,
V_213 , 1 ) ;
V_86 -> V_27 . V_88 = F_33 ( V_278 ,
& V_279 ,
& V_2 -> V_46 ) ;
if ( V_86 -> V_27 . V_88 != NULL ) {
F_33 ( V_165 , V_86 -> V_27 . V_88 ,
& V_2 -> V_46 , 0x4b ,
& V_166 ) ;
V_86 -> V_27 . V_88 -> V_44 . V_45 = F_14 ;
F_33 ( V_167 , V_86 -> V_27 . V_88 ,
0x60 , & V_2 -> V_46 ,
& V_280 ) ;
}
break;
case V_281 :
V_86 -> V_27 . V_88 = F_33 ( V_282 ,
& V_283 ,
& V_2 -> V_46 ) ;
if ( V_86 -> V_27 . V_88 != NULL ) {
F_33 ( V_165 , V_86 -> V_27 . V_88 ,
& V_2 -> V_46 , 0x4b ,
& V_166 ) ;
F_33 ( V_167 , V_86 -> V_27 . V_88 ,
0x60 , & V_2 -> V_46 ,
& V_284 ) ;
}
break;
case V_285 :
F_29 ( V_2 , 23 , 0 ) ;
F_29 ( V_2 , 9 , 0 ) ;
F_29 ( V_2 , 25 , 1 ) ;
F_16 ( 1 ) ;
V_86 -> V_27 . V_88 = F_33 ( V_260 ,
& V_286 , & V_2 -> V_46 ) ;
if ( V_86 -> V_27 . V_88 ) {
V_86 -> V_27 . V_88 -> V_44 . V_45 = NULL ;
if ( F_33 ( V_266 , V_86 -> V_27 . V_88 ,
0x60 , & V_2 -> V_46 ) == NULL )
F_15 ( L_36 ,
V_7 ) ;
}
break;
default:
F_15 ( L_38 ) ;
break;
}
if ( V_101 ) {
struct V_8 * V_9 ;
struct V_287 V_288 = {
. V_46 = & V_2 -> V_46 ,
. V_289 = 0x61 ,
} ;
if ( ! V_86 -> V_27 . V_88 )
goto V_149;
V_9 = F_33 ( V_290 , V_86 -> V_27 . V_88 , & V_288 ) ;
if ( ! V_9 ) {
F_43 ( V_107 L_39 ,
V_2 -> V_56 ) ;
goto V_149;
}
}
if ( NULL == V_86 -> V_27 . V_88 ) {
F_43 ( V_107 L_40 , V_2 -> V_56 ) ;
goto V_149;
}
V_86 -> V_27 . V_88 -> V_291 = F_47 ;
V_100 = F_48 ( & V_2 -> V_87 , V_292 , V_2 ,
& V_2 -> V_57 -> V_2 , V_293 , 0 ) ;
if ( ! V_100 ) {
if ( V_86 -> V_27 . V_88 -> V_44 . V_144 )
V_86 -> V_27 . V_88 -> V_44 . V_144 ( V_86 -> V_27 . V_88 ) ;
if ( V_86 -> V_27 . V_88 -> V_44 . V_154 )
V_86 -> V_27 . V_88 -> V_44 . V_154 ( V_86 -> V_27 . V_88 ) ;
if ( V_86 -> V_27 . V_88 -> V_44 . V_130 . V_154 )
V_86 -> V_27 . V_88 -> V_44 . V_130 . V_154 ( V_86 -> V_27 . V_88 ) ;
}
return V_100 ;
V_149:
F_46 ( & V_2 -> V_87 ) ;
F_49 ( & V_86 -> V_27 . V_112 ) ;
return - V_69 ;
}
static int F_50 ( struct V_1 * V_2 )
{
struct V_85 * V_86 ;
V_86 = F_32 ( & V_2 -> V_87 , 1 ) ;
if ( ! V_86 )
return - V_69 ;
if ( V_2 -> V_126 == V_127 ) {
struct V_294 V_295 ;
static int V_3 = V_296 | V_297 ;
V_295 . V_41 = V_298 ;
V_295 . V_28 = & V_3 ;
F_13 ( V_2 , V_41 , V_299 , & V_295 ) ;
} else if ( V_2 -> V_126 == V_195 ) {
if ( ( V_2 -> V_198 [ 2 ] == 0x07 ) && V_183 ) {
T_2 V_199 = 0x80 ;
struct V_33 V_34 = { . V_35 = 0x08 , . V_37 = & V_199 , . V_36 = 0 , . V_38 = 1 } ;
struct V_8 * V_9 ;
V_9 = V_86 -> V_27 . V_88 ;
if ( V_9 -> V_44 . V_45 ) {
V_9 -> V_44 . V_45 ( V_9 , 1 ) ;
F_12 ( & V_2 -> V_46 , & V_34 , 1 ) ;
V_9 -> V_44 . V_45 ( V_9 , 0 ) ;
}
}
}
F_51 ( & V_2 -> V_87 ) ;
F_49 ( & V_86 -> V_27 . V_112 ) ;
return 0 ;
}
static int T_4 F_52 ( void )
{
return F_53 ( & V_300 ) ;
}
static void T_5 F_54 ( void )
{
F_55 ( & V_300 ) ;
}
