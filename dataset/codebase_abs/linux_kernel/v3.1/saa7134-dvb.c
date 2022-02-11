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
static int F_11 ( struct V_8 * V_9 ,
struct V_29 * V_30 )
{
T_2 V_31 [] = { 0x00 , 0xf1 } ;
T_2 V_3 [] = { 0x00 , 0x71 } ;
struct V_32 V_33 = { . V_34 = 0x43 , . V_35 = 0 , . V_36 = V_31 , . V_37 = sizeof( V_31 ) } ;
struct V_1 * V_2 = V_9 -> V_27 -> V_28 ;
struct V_38 V_39 ;
V_39 . V_40 = 0 ;
V_39 . type = V_41 ;
V_39 . V_42 = V_30 -> V_42 / 1000 * 16 / 1000 ;
if ( V_9 -> V_43 . V_44 )
V_9 -> V_43 . V_44 ( V_9 , 1 ) ;
F_12 ( & V_2 -> V_45 , & V_33 , 1 ) ;
F_13 ( V_2 , V_40 , V_46 , & V_39 ) ;
V_33 . V_36 = V_3 ;
if ( V_9 -> V_43 . V_44 )
V_9 -> V_43 . V_44 ( V_9 , 1 ) ;
F_12 ( & V_2 -> V_45 , & V_33 , 1 ) ;
F_1 ( V_2 , V_47 ) ;
return F_7 ( V_9 ) ;
}
static int F_14 ( struct V_8 * V_9 , int V_48 )
{
struct V_1 * V_2 = V_9 -> V_27 -> V_28 ;
unsigned char V_49 [] = { 0x45 , 0x97 } ;
unsigned char V_50 [] = { 0x45 , 0xc1 } ;
unsigned char V_51 [] = { 0x45 , 0x81 } ;
struct V_32 V_33 = { . V_34 = 0x4b , . V_35 = 0 , . V_36 = V_49 , . V_37 = 2 } ;
if ( F_12 ( & V_2 -> V_45 , & V_33 , 1 ) != 1 ) {
F_15 ( L_5 ) ;
return - V_52 ;
}
if ( V_48 )
V_33 . V_36 = V_50 ;
else
V_33 . V_36 = V_51 ;
if ( F_12 ( & V_2 -> V_45 , & V_33 , 1 ) != 1 ) {
F_15 ( L_5 ) ;
return - V_52 ;
}
F_16 ( 20 ) ;
return 0 ;
}
static int F_17 ( struct V_8 * V_9 ,
const struct V_53 * * V_54 , char * V_55 )
{
struct V_1 * V_2 = V_9 -> V_27 -> V_28 ;
return F_18 ( V_54 , V_55 , & V_2 -> V_56 -> V_2 ) ;
}
static int F_19 ( struct V_8 * V_9 , struct V_29 * V_30 )
{
struct V_1 * V_2 = V_9 -> V_27 -> V_28 ;
struct V_57 * V_58 = V_9 -> V_59 ;
T_2 V_34 = V_58 -> V_60 -> V_61 ;
T_2 V_62 [ 4 ] ;
struct V_32 V_63 = { . V_34 = V_34 , . V_35 = 0 , . V_36 = V_62 , . V_37 =
sizeof( V_62 ) } ;
int V_64 = 0 ;
T_2 V_65 , V_66 , V_67 ;
V_64 = V_30 -> V_42 + 36166000 ;
if ( V_64 < 87000000 )
return - V_68 ;
else if ( V_64 < 130000000 )
V_66 = 3 ;
else if ( V_64 < 160000000 )
V_66 = 5 ;
else if ( V_64 < 200000000 )
V_66 = 6 ;
else if ( V_64 < 290000000 )
V_66 = 3 ;
else if ( V_64 < 420000000 )
V_66 = 5 ;
else if ( V_64 < 480000000 )
V_66 = 6 ;
else if ( V_64 < 620000000 )
V_66 = 3 ;
else if ( V_64 < 830000000 )
V_66 = 5 ;
else if ( V_64 < 895000000 )
V_66 = 7 ;
else
return - V_68 ;
if ( V_30 -> V_42 < 49000000 )
return - V_68 ;
else if ( V_30 -> V_42 < 161000000 )
V_65 = 1 ;
else if ( V_30 -> V_42 < 444000000 )
V_65 = 2 ;
else if ( V_30 -> V_42 < 861000000 )
V_65 = 4 ;
else
return - V_68 ;
switch ( V_30 -> V_69 . V_70 . V_71 ) {
case V_72 :
V_67 = 0 ;
break;
case V_73 :
V_67 = 0 ;
break;
case V_74 :
V_67 = 1 ;
break;
default:
return - V_68 ;
}
V_64 = ( ( ( V_30 -> V_42 / 1000 ) * 6 ) + 217496 ) / 1000 ;
V_62 [ 0 ] = ( V_64 >> 8 ) & 0x7f ;
V_62 [ 1 ] = V_64 & 0xff ;
V_62 [ 2 ] = 0xca ;
V_62 [ 3 ] = ( V_66 << 5 ) | ( V_67 << 3 ) | V_65 ;
if ( V_9 -> V_43 . V_44 )
V_9 -> V_43 . V_44 ( V_9 , 1 ) ;
if ( F_12 ( & V_2 -> V_45 , & V_63 , 1 ) != 1 ) {
F_15 ( L_6 ,
V_34 << 1 ) ;
return - V_52 ;
}
F_16 ( 1 ) ;
return 0 ;
}
static int F_20 ( struct V_8 * V_9 )
{
struct V_1 * V_2 = V_9 -> V_27 -> V_28 ;
struct V_57 * V_58 = V_9 -> V_59 ;
T_2 V_34 = V_58 -> V_60 -> V_61 ;
static T_2 V_75 [] = { 0x0b , 0xf5 , 0x85 , 0xab } ;
struct V_32 V_63 = { . V_34 = V_34 , . V_35 = 0 , . V_36 = V_75 , . V_37 = sizeof( V_75 ) } ;
if ( V_9 -> V_43 . V_44 )
V_9 -> V_43 . V_44 ( V_9 , 1 ) ;
if ( F_12 ( & V_2 -> V_45 , & V_63 , 1 ) != 1 )
return - V_52 ;
F_16 ( 1 ) ;
return 0 ;
}
static int F_21 ( struct V_8 * V_9 )
{
struct V_1 * V_2 = V_9 -> V_27 -> V_28 ;
struct V_57 * V_58 = V_9 -> V_59 ;
T_2 V_34 = V_58 -> V_60 -> V_61 ;
static T_2 V_33 [] = { 0x0b , 0xf5 , 0x86 , 0xab } ;
struct V_32 V_76 = { . V_34 = V_34 , . V_35 = 0 , . V_36 = V_33 , . V_37 = sizeof( V_33 ) } ;
if ( V_9 -> V_43 . V_44 )
V_9 -> V_43 . V_44 ( V_9 , 1 ) ;
if ( F_12 ( & V_2 -> V_45 , & V_76 , 1 ) != 1 )
return - V_52 ;
return 0 ;
}
static int F_22 ( struct V_8 * V_9 , struct V_29 * V_30 )
{
return F_19 ( V_9 , V_30 ) ;
}
static int F_23 ( struct V_8 * V_9 )
{
struct V_1 * V_2 = V_9 -> V_27 -> V_28 ;
struct V_57 * V_58 = V_9 -> V_59 ;
T_2 V_34 = V_58 -> V_60 -> V_61 ;
static T_2 V_33 [] = { 0x0b , 0xdc , 0x86 , 0xa4 } ;
struct V_32 V_77 = { . V_34 = V_34 , . V_35 = 0 , . V_36 = V_33 , . V_37 = sizeof( V_33 ) } ;
if ( V_9 -> V_43 . V_44 )
V_9 -> V_43 . V_44 ( V_9 , 1 ) ;
if ( F_12 ( & V_2 -> V_45 , & V_77 , 1 ) != 1 )
return - V_52 ;
return 0 ;
}
static int F_24 ( struct V_8 * V_9 )
{
struct V_1 * V_2 = V_9 -> V_27 -> V_28 ;
static T_2 V_33 [] = { 0x00 , 0x40 } ;
struct V_32 V_76 = { . V_34 = 0x43 , . V_35 = 0 , . V_36 = V_33 , . V_37 = sizeof( V_33 ) } ;
if ( F_21 ( V_9 ) )
return - V_52 ;
F_16 ( 1 ) ;
if ( F_12 ( & V_2 -> V_45 , & V_76 , 1 ) != 1 )
return - V_52 ;
return 0 ;
}
static int F_25 ( struct V_8 * V_9 )
{
struct V_1 * V_2 = V_9 -> V_27 -> V_28 ;
static T_2 V_33 [] = { 0x00 , 0x14 } ;
struct V_32 V_77 = { . V_34 = 0x43 , . V_35 = 0 , . V_36 = V_33 , . V_37 = sizeof( V_33 ) } ;
if ( F_23 ( V_9 ) )
return - V_52 ;
if ( V_9 -> V_43 . V_44 )
V_9 -> V_43 . V_44 ( V_9 , 1 ) ;
F_12 ( & V_2 -> V_45 , & V_77 , 1 ) ;
return 0 ;
}
static int F_26 ( struct V_8 * V_9 )
{
struct V_1 * V_2 = V_9 -> V_27 -> V_28 ;
if ( V_2 -> V_78 )
V_2 -> V_78 ( V_9 ) ;
V_9 -> V_43 . V_44 ( V_9 , 1 ) ;
return 0 ;
}
static int F_27 ( struct V_8 * V_9 , int V_48 )
{
struct V_57 * V_58 = V_9 -> V_59 ;
T_2 V_34 = V_58 -> V_60 -> V_79 ;
static T_2 V_80 [] = { 0x21 , 0xc0 } ;
static T_2 V_81 [] = { 0x21 , 0x80 } ;
struct V_32 V_82 = { . V_34 = V_34 , . V_35 = 0 , . V_37 = 2 } ;
if ( V_48 ) {
V_82 . V_36 = V_80 ;
} else {
V_82 . V_36 = V_81 ;
}
if ( F_12 ( V_58 -> V_83 , & V_82 , 1 ) != 1 ) {
struct V_1 * V_2 = V_9 -> V_27 -> V_28 ;
F_15 ( L_7 ) ;
return - V_52 ;
}
F_16 ( 20 ) ;
return 0 ;
}
static int F_28 ( struct V_8 * V_9 )
{
struct V_1 * V_2 = V_9 -> V_27 -> V_28 ;
struct V_57 * V_58 = V_9 -> V_59 ;
switch ( V_58 -> V_60 -> V_84 ) {
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
struct V_57 * V_58 = V_9 -> V_59 ;
switch ( V_58 -> V_60 -> V_84 ) {
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
struct V_85 * V_86 ,
struct V_87 * V_88 )
{
struct V_89 * V_90 ;
V_90 = F_32 ( & V_2 -> V_91 , 1 ) ;
V_90 -> V_27 . V_92 = F_33 ( V_93 , V_86 , & V_2 -> V_45 ) ;
if ( V_90 -> V_27 . V_92 ) {
if ( V_86 -> V_79 )
V_90 -> V_27 . V_92 -> V_43 . V_44 = F_27 ;
if ( F_33 ( V_94 , V_90 -> V_27 . V_92 ,
V_86 -> V_61 ,
& V_2 -> V_45 , V_88 ) )
return 0 ;
F_15 ( L_10 ,
V_86 -> V_61 ) ;
}
return - V_68 ;
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
static int F_36 ( struct V_8 * V_9 , T_3 V_95 )
{
int V_96 = - V_52 ;
struct V_1 * V_2 = V_9 -> V_27 -> V_28 ;
if ( V_9 -> V_43 . V_44 ) {
V_9 -> V_43 . V_44 ( V_9 , 1 ) ;
if ( V_2 -> V_97 )
V_96 = V_2 -> V_97 ( V_9 , V_95 ) ;
V_9 -> V_43 . V_44 ( V_9 , 0 ) ;
}
return V_96 ;
}
static int F_37 ( struct V_8 * V_9 , long V_98 )
{
int V_96 = - V_52 ;
struct V_1 * V_2 = V_9 -> V_27 -> V_28 ;
if ( V_9 -> V_43 . V_44 ) {
V_9 -> V_43 . V_44 ( V_9 , 1 ) ;
if ( V_2 -> V_99 )
V_96 = V_2 -> V_99 ( V_9 , V_98 ) ;
V_9 -> V_43 . V_44 ( V_9 , 0 ) ;
}
return V_96 ;
}
static int F_38 ( struct V_8 * V_9 , T_3 V_95 )
{
struct V_1 * V_2 = V_9 -> V_27 -> V_28 ;
T_2 V_100 [ 2 ] = { 0x1f , 00 } ;
T_2 V_101 ;
struct V_32 V_33 [] = { { . V_34 = 0x08 , . V_35 = 0 , . V_36 = V_100 , . V_37 = 1 } ,
{ . V_34 = 0x08 , . V_35 = V_102 , . V_36 = & V_101 , . V_37 = 1 } } ;
if ( F_12 ( & V_2 -> V_45 , V_33 , 2 ) != 2 )
return - V_52 ;
if ( V_95 == V_103 )
V_100 [ 1 ] = V_101 | 0x10 ;
else
V_100 [ 1 ] = V_101 & 0xef ;
V_33 [ 0 ] . V_37 = 2 ;
F_12 ( & V_2 -> V_45 , V_33 , 1 ) ;
return 0 ;
}
static int F_39 ( struct V_8 * V_9 , long V_98 )
{
struct V_1 * V_2 = V_9 -> V_27 -> V_28 ;
F_15 ( L_11 , V_7 ) ;
return - V_52 ;
}
static int F_40 ( struct V_1 * V_2 )
{
int V_104 ;
int V_105 = 0 ;
struct V_89 * V_90 ;
F_41 ( & V_2 -> V_91 . V_106 ) ;
F_42 ( & V_2 -> V_91 . V_107 ) ;
F_43 ( V_108 L_12 , V_7 ) ;
V_90 = F_44 ( & V_2 -> V_91 , 1 ) ;
if ( ! V_90 ) {
F_43 ( V_109 L_13 , V_7 ) ;
return - V_110 ;
}
V_2 -> V_111 . V_112 = 32 ;
V_2 -> V_111 . V_113 = 32 * 4 ;
V_90 -> V_27 . V_55 = V_2 -> V_55 ;
F_45 ( & V_90 -> V_27 . V_114 , & V_115 ,
& V_2 -> V_56 -> V_2 , & V_2 -> V_116 ,
V_117 ,
V_118 ,
sizeof( struct V_119 ) ,
V_2 , NULL ) ;
switch ( V_2 -> V_120 ) {
case V_121 :
F_6 ( L_14 ) ;
V_90 -> V_27 . V_92 = F_33 ( V_122 , & V_123 ,
& V_2 -> V_45 ) ;
if ( V_90 -> V_27 . V_92 ) {
V_90 -> V_27 . V_92 -> V_43 . V_124 . V_125 = F_11 ;
}
break;
case V_126 :
case V_127 :
F_6 ( L_15 ) ;
V_90 -> V_27 . V_92 = F_33 ( V_122 , & V_128 ,
& V_2 -> V_45 ) ;
if ( V_90 -> V_27 . V_92 ) {
F_33 ( V_129 , V_90 -> V_27 . V_92 ,
& V_2 -> V_45 , 0x61 ,
V_130 ) ;
}
break;
case V_131 :
F_6 ( L_16 ) ;
V_90 -> V_27 . V_92 = F_33 ( V_122 ,
& V_132 ,
& V_2 -> V_45 ) ;
V_105 = 1 ;
break;
case V_133 :
V_90 -> V_27 . V_92 = F_33 ( V_93 ,
& V_134 ,
& V_2 -> V_45 ) ;
if ( V_90 -> V_27 . V_92 ) {
F_33 ( V_129 , V_90 -> V_27 . V_92 ,
& V_2 -> V_45 , V_134 . V_61 ,
V_135 ) ;
}
break;
case V_136 :
V_90 -> V_27 . V_92 = F_33 ( V_93 ,
& V_137 ,
& V_2 -> V_45 ) ;
if ( V_90 -> V_27 . V_92 ) {
V_90 -> V_27 . V_92 -> V_43 . V_124 . V_138 = F_20 ;
V_90 -> V_27 . V_92 -> V_43 . V_124 . V_125 = F_19 ;
}
break;
case V_139 :
case V_140 :
if ( F_31 ( V_2 , & V_141 ,
& V_142 ) < 0 )
goto V_143;
break;
case V_144 :
case V_145 :
case V_146 :
V_90 -> V_27 . V_92 = F_33 ( V_93 ,
& V_147 ,
& V_2 -> V_45 ) ;
if ( V_90 -> V_27 . V_92 ) {
V_2 -> V_78 = V_90 -> V_27 . V_92 -> V_43 . V_148 ;
V_90 -> V_27 . V_92 -> V_43 . V_148 = F_26 ;
V_90 -> V_27 . V_92 -> V_43 . V_124 . V_138 = F_24 ;
V_90 -> V_27 . V_92 -> V_43 . V_124 . V_148 = F_25 ;
V_90 -> V_27 . V_92 -> V_43 . V_124 . V_125 = F_22 ;
}
break;
case V_149 :
V_90 -> V_27 . V_92 = F_33 ( V_93 ,
& V_150 ,
& V_2 -> V_45 ) ;
if ( V_90 -> V_27 . V_92 ) {
V_2 -> V_78 = V_90 -> V_27 . V_92 -> V_43 . V_148 ;
V_90 -> V_27 . V_92 -> V_43 . V_148 = F_26 ;
V_90 -> V_27 . V_92 -> V_43 . V_124 . V_138 = F_24 ;
V_90 -> V_27 . V_92 -> V_43 . V_124 . V_148 = F_25 ;
V_90 -> V_27 . V_92 -> V_43 . V_124 . V_125 = F_22 ;
}
break;
case V_151 :
V_90 -> V_27 . V_92 = F_33 ( V_93 ,
& V_152 ,
& V_2 -> V_45 ) ;
if ( V_90 -> V_27 . V_92 ) {
V_90 -> V_27 . V_92 -> V_43 . V_124 . V_138 = F_20 ;
V_90 -> V_27 . V_92 -> V_43 . V_124 . V_125 = F_19 ;
}
break;
case V_153 :
if ( F_31 ( V_2 , & V_154 ,
& V_155 ) < 0 )
goto V_143;
break;
case V_156 :
V_90 -> V_27 . V_92 = F_33 ( V_157 ,
& V_158 ,
& V_2 -> V_45 ) ;
if ( V_90 -> V_27 . V_92 != NULL ) {
F_33 ( V_159 , V_90 -> V_27 . V_92 ,
& V_2 -> V_45 , 0x4b ,
& V_160 ) ;
F_33 ( V_161 , V_90 -> V_27 . V_92 ,
0x60 , & V_2 -> V_45 ,
& V_162 ) ;
}
break;
case V_163 :
if ( F_31 ( V_2 , & V_164 ,
& V_142 ) < 0 )
goto V_143;
break;
case V_165 :
if ( F_31 ( V_2 , & V_166 ,
& V_167 ) < 0 )
goto V_143;
break;
case V_168 :
if ( F_31 ( V_2 , & V_169 ,
& V_167 ) < 0 )
goto V_143;
break;
case V_170 :
V_90 -> V_27 . V_92 = F_33 ( V_171 ,
& V_172 ,
& V_2 -> V_45 ) ;
if ( V_90 -> V_27 . V_92 ) {
F_33 ( V_159 , V_90 -> V_27 . V_92 ,
& V_2 -> V_45 , 0x4b ,
& V_160 ) ;
F_33 ( V_161 , V_90 -> V_27 . V_92 ,
0x60 , & V_2 -> V_45 ,
& V_162 ) ;
}
break;
case V_173 :
if ( F_31 ( V_2 , & V_174 ,
& V_142 ) < 0 )
goto V_143;
break;
case V_175 :
if ( F_31 ( V_2 , & V_141 ,
& V_142 ) < 0 )
goto V_143;
break;
case V_176 :
if ( ! V_177 ) {
if ( F_31 ( V_2 , & V_178 ,
& V_142 ) < 0 )
goto V_143;
} else {
V_90 -> V_27 . V_92 = F_33 ( V_179 , & V_180 , & V_2 -> V_45 ) ;
if ( V_90 -> V_27 . V_92 ) {
if ( F_33 ( V_181 , V_90 -> V_27 . V_92 , 0x63 ,
& V_2 -> V_45 , 0 ) == NULL ) {
F_15 ( L_17 , V_7 ) ;
goto V_143;
}
if ( F_33 ( V_182 , V_90 -> V_27 . V_92 , & V_2 -> V_45 ,
0x08 , 0 , 0 ) == NULL ) {
F_15 ( L_18 , V_7 ) ;
goto V_143;
}
}
}
break;
case V_183 :
case V_184 :
V_90 -> V_27 . V_92 = F_33 ( V_93 ,
& V_185 ,
& V_2 -> V_45 ) ;
if ( V_90 -> V_27 . V_92 ) {
if ( F_33 ( V_94 , V_90 -> V_27 . V_92 ,
V_185 . V_61 , & V_2 -> V_45 ,
& V_186 ) == NULL ) {
F_15 ( L_10 ,
V_185 . V_61 ) ;
goto V_143;
}
} else
F_15 ( L_19 ) ;
break;
case V_187 :
if ( F_31 ( V_2 , & V_188 ,
& V_142 ) < 0 )
goto V_143;
break;
case V_189 :
if ( ! V_177 ) {
if ( F_31 ( V_2 , & V_190 ,
& V_142 ) < 0 )
goto V_143;
} else {
V_90 -> V_27 . V_92 = F_33 ( V_179 ,
& V_180 , & V_2 -> V_45 ) ;
if ( V_90 -> V_27 . V_92 ) {
struct V_8 * V_9 = V_90 -> V_27 . V_92 ;
T_2 V_191 = V_2 -> V_192 [ 2 ] ;
T_2 V_193 = 0xc4 ;
struct V_32 V_33 = { . V_34 = 0x08 , . V_35 = 0 , . V_37 = 1 } ;
if ( F_33 ( V_181 , V_90 -> V_27 . V_92 ,
0x60 , & V_2 -> V_45 , 0 ) == NULL ) {
F_15 ( L_20
L_21 , V_7 ) ;
goto V_143;
}
if ( V_191 != 0x08 ) {
V_9 -> V_43 . V_44 ( V_9 , 1 ) ;
if ( F_33 ( V_194 , V_9 ,
& V_2 -> V_45 , 0x08 , 0 , 0 ) == NULL ) {
F_15 ( L_22
L_21 , V_7 ) ;
goto V_143;
}
if ( V_191 == 0x07 ) {
V_33 . V_36 = & V_193 ;
F_12 ( & V_2 -> V_45 , & V_33 , 1 ) ;
}
V_9 -> V_43 . V_44 ( V_9 , 0 ) ;
V_2 -> V_97 = V_9 -> V_43 . V_195 ;
V_9 -> V_43 . V_195 = F_36 ;
V_2 -> V_99 = V_9 -> V_43 . V_196 ;
V_9 -> V_43 . V_196 = F_37 ;
} else {
V_9 -> V_43 . V_195 = F_38 ;
V_9 -> V_43 . V_196 = F_39 ;
}
}
}
break;
case V_197 :
V_90 -> V_27 . V_92 = F_33 ( V_198 , & V_199 ,
& V_2 -> V_45 ) ;
if ( V_90 -> V_27 . V_92 )
F_33 ( V_200 , V_90 -> V_27 . V_92 , 0x61 ,
NULL , V_201 ) ;
break;
case V_202 :
case V_203 :
V_90 -> V_27 . V_92 = F_33 ( V_198 , & V_204 ,
& V_2 -> V_45 ) ;
if ( V_90 -> V_27 . V_92 )
F_33 ( V_129 , V_90 -> V_27 . V_92 ,
& V_2 -> V_45 , 0x61 ,
V_205 ) ;
break;
case V_206 :
V_90 -> V_27 . V_92 = F_33 ( V_179 , & V_180 ,
& V_2 -> V_45 ) ;
if ( V_90 -> V_27 . V_92 ) {
if ( F_33 ( V_181 , V_90 -> V_27 . V_92 , 0x60 ,
& V_2 -> V_45 , 0 ) == NULL ) {
F_15 ( L_23 , V_7 ) ;
goto V_143;
}
if ( F_33 ( V_182 , V_90 -> V_27 . V_92 ,
& V_2 -> V_45 , 0x08 , 0 , 0 ) == NULL ) {
F_15 ( L_24 , V_7 ) ;
goto V_143;
}
}
break;
case V_207 :
V_90 -> V_27 . V_92 = F_33 ( V_93 ,
& V_134 ,
& V_2 -> V_45 ) ;
if ( V_90 -> V_27 . V_92 ) {
V_2 -> V_78 = V_90 -> V_27 . V_92 -> V_43 . V_148 ;
V_90 -> V_27 . V_92 -> V_43 . V_148 = F_26 ;
F_33 ( V_129 , V_90 -> V_27 . V_92 ,
& V_2 -> V_45 , V_134 . V_61 ,
V_135 ) ;
}
break;
case V_208 :
V_90 -> V_27 . V_92 = F_33 ( V_93 ,
& V_147 ,
& V_2 -> V_45 ) ;
if ( V_90 -> V_27 . V_92 ) {
V_90 -> V_27 . V_92 -> V_43 . V_124 . V_138 = F_21 ;
V_90 -> V_27 . V_92 -> V_43 . V_124 . V_125 = F_22 ;
}
break;
case V_209 :
if ( F_31 ( V_2 , & V_210 ,
& V_142 ) < 0 )
goto V_143;
break;
case V_211 :
if ( F_31 ( V_2 , & V_212 ,
& V_142 ) < 0 )
goto V_143;
break;
case V_213 :
if ( F_31 ( V_2 , & V_214 ,
& V_155 ) < 0 )
goto V_143;
break;
case V_215 :
if ( F_31 ( V_2 , & V_216 ,
& V_155 ) < 0 )
goto V_143;
break;
case V_217 :
if ( F_31 ( V_2 , & V_218 ,
& V_155 ) < 0 )
goto V_143;
break;
case V_219 :
if ( F_31 ( V_2 , & V_220 ,
& V_142 ) < 0 )
goto V_143;
break;
case V_221 :
if ( F_31 ( V_2 , & V_222 ,
& V_223 ) < 0 )
goto V_143;
break;
case V_224 :
V_90 -> V_27 . V_92 = F_33 ( V_179 , & V_180 ,
& V_2 -> V_45 ) ;
if ( V_90 -> V_27 . V_92 ) {
if ( F_33 ( V_181 , V_90 -> V_27 . V_92 , 0x60 ,
& V_2 -> V_45 , 0 ) == NULL ) {
F_15 ( L_23 , V_7 ) ;
goto V_143;
}
if ( F_33 ( V_225 , V_90 -> V_27 . V_92 ,
& V_2 -> V_45 , 0 , 0 ) == NULL ) {
F_15 ( L_25 , V_7 ) ;
goto V_143;
}
}
break;
case V_226 :
if ( F_31 ( V_2 , & V_190 ,
& V_142 ) < 0 )
goto V_143;
break;
case V_227 :
if ( F_31 ( V_2 , & V_214 ,
& V_155 ) < 0 )
goto V_143;
break;
case V_228 :
F_6 ( L_26 ) ;
F_29 ( V_2 , 25 , 0 ) ;
F_16 ( 10 ) ;
F_29 ( V_2 , 25 , 1 ) ;
V_90 -> V_27 . V_92 = F_33 ( V_122 ,
& V_132 ,
& V_2 -> V_45 ) ;
V_105 = 1 ;
break;
case V_229 :
V_90 -> V_27 . V_92 = F_33 ( V_179 ,
& V_230 , & V_2 -> V_45 ) ;
if ( V_90 -> V_27 . V_92 ) {
struct V_8 * V_9 ;
if ( F_33 ( V_200 , V_90 -> V_27 . V_92 , 0x60 ,
& V_2 -> V_45 , V_231 ) == NULL ) {
F_15 ( L_27
L_21 , V_7 ) ;
goto V_143;
}
V_9 = V_90 -> V_27 . V_92 ;
V_9 -> V_43 . V_44 ( V_9 , 1 ) ;
if ( F_33 ( V_194 , V_9 ,
& V_2 -> V_45 , 0x08 , 0 , 0 ) == NULL ) {
F_15 ( L_28
L_21 , V_7 ) ;
goto V_143;
}
V_9 -> V_43 . V_44 ( V_9 , 0 ) ;
V_2 -> V_97 = V_9 -> V_43 . V_195 ;
V_9 -> V_43 . V_195 = F_36 ;
V_2 -> V_99 = V_9 -> V_43 . V_196 ;
V_9 -> V_43 . V_196 = F_37 ;
}
break;
case V_232 :
F_29 ( V_2 , 25 , 0 ) ;
F_16 ( 10 ) ;
F_29 ( V_2 , 25 , 1 ) ;
V_90 -> V_27 . V_92 = F_33 ( V_122 ,
& V_132 ,
& V_2 -> V_45 ) ;
V_105 = 1 ;
break;
case V_233 :
if ( ! V_177 ) {
if ( F_31 ( V_2 , & V_234 ,
& V_155 ) < 0 )
goto V_143;
} else {
V_90 -> V_27 . V_92 = F_33 ( V_179 ,
& V_180 , & V_2 -> V_45 ) ;
if ( V_90 -> V_27 . V_92 ) {
if ( F_33 ( V_181 ,
V_90 -> V_27 . V_92 , 0x60 ,
& V_2 -> V_45 , 0 ) == NULL ) {
F_15 ( L_29
L_30 , V_7 ) ;
goto V_143;
}
if ( F_33 ( V_225 , V_90 -> V_27 . V_92 ,
& V_2 -> V_45 , 0 , 0 ) == NULL ) {
F_15 ( L_31
L_32 , V_7 ) ;
goto V_143;
}
}
}
break;
case V_235 :
if ( F_31 ( V_2 , & V_164 ,
& V_142 ) < 0 )
goto V_143;
break;
case V_236 :
V_90 -> V_27 . V_92 = F_33 ( V_237 ,
& V_238 ,
& V_2 -> V_45 ) ;
if ( V_90 -> V_27 . V_92 ) {
F_33 ( V_129 , V_90 -> V_27 . V_92 ,
& V_2 -> V_45 , 0x61 ,
V_239 ) ;
}
break;
case V_240 :
V_90 -> V_27 . V_92 = F_33 ( V_237 ,
& V_241 ,
& V_2 -> V_45 ) ;
if ( V_90 -> V_27 . V_92 ) {
F_33 ( V_242 , V_90 -> V_27 . V_92 ,
& V_2 -> V_45 , & V_243 ) ;
}
break;
case V_244 :
V_90 -> V_27 . V_92 = F_33 ( V_237 ,
& V_241 ,
& V_2 -> V_45 ) ;
if ( V_90 -> V_27 . V_92 ) {
F_33 ( V_242 , V_90 -> V_27 . V_92 ,
& V_2 -> V_45 , & V_243 ) ;
}
break;
case V_245 :
case V_246 :
V_90 -> V_27 . V_92 = F_33 ( V_247 ,
& V_248 , & V_2 -> V_45 ) ;
if ( V_90 -> V_27 . V_92 ) {
if ( F_33 ( V_249 , V_90 -> V_27 . V_92 ,
& V_250 , & V_2 -> V_45 ) == NULL ) {
F_15 ( L_33 ,
V_7 ) ;
}
}
break;
case V_251 :
V_90 -> V_27 . V_92 = F_33 ( V_247 ,
& V_252 , & V_2 -> V_45 ) ;
if ( V_90 -> V_27 . V_92 )
if ( F_33 ( V_253 , V_90 -> V_27 . V_92 ,
0x60 , & V_2 -> V_45 ) == NULL )
F_15 ( L_34 ,
V_7 ) ;
break;
case V_254 :
V_90 -> V_27 . V_92 = F_33 ( V_237 ,
& V_255 ,
& V_2 -> V_45 ) ;
if ( V_90 -> V_27 . V_92 != NULL ) {
if ( F_33 ( V_256 ,
V_90 -> V_27 . V_92 ,
& V_2 -> V_45 ,
& V_257 ) == NULL )
F_15 ( L_35 ) ;
}
break;
case V_258 :
V_90 -> V_27 . V_92 = F_33 ( V_157 ,
& V_259 ,
& V_2 -> V_45 ) ;
if ( V_90 -> V_27 . V_92 != NULL ) {
F_33 ( V_159 , V_90 -> V_27 . V_92 ,
& V_2 -> V_45 , 0x4b ,
& V_160 ) ;
F_33 ( V_161 , V_90 -> V_27 . V_92 ,
0x60 , & V_2 -> V_45 ,
& V_260 ) ;
}
break;
case V_261 :
V_90 -> V_27 . V_92 = F_33 ( V_157 ,
& V_262 ,
& V_2 -> V_45 ) ;
if ( V_90 -> V_27 . V_92 != NULL ) {
F_33 ( V_159 , V_90 -> V_27 . V_92 ,
& V_2 -> V_45 , 0x4b ,
& V_160 ) ;
F_33 ( V_161 , V_90 -> V_27 . V_92 ,
0x60 , & V_2 -> V_45 ,
& V_263 ) ;
}
break;
case V_264 :
F_46 ( V_2 , 0 ,
V_265 , 1 ) ;
V_90 -> V_27 . V_92 = F_33 ( V_266 ,
& V_267 ,
& V_2 -> V_45 ) ;
if ( V_90 -> V_27 . V_92 != NULL ) {
F_33 ( V_159 , V_90 -> V_27 . V_92 ,
& V_2 -> V_45 , 0x4b ,
& V_160 ) ;
F_33 ( V_161 , V_90 -> V_27 . V_92 ,
0x60 , & V_2 -> V_45 ,
& V_268 ) ;
V_90 -> V_27 . V_92 -> V_43 . V_44 = F_14 ;
}
break;
case V_269 :
V_90 -> V_27 . V_92 = F_33 ( V_270 ,
& V_271 ,
& V_2 -> V_45 ) ;
if ( V_90 -> V_27 . V_92 != NULL ) {
F_33 ( V_159 , V_90 -> V_27 . V_92 ,
& V_2 -> V_45 , 0x4b ,
& V_160 ) ;
F_33 ( V_161 , V_90 -> V_27 . V_92 ,
0x60 , & V_2 -> V_45 ,
& V_272 ) ;
}
break;
default:
F_15 ( L_36 ) ;
break;
}
if ( V_105 ) {
struct V_8 * V_9 ;
struct V_273 V_274 = {
. V_45 = & V_2 -> V_45 ,
. V_275 = 0x61 ,
} ;
if ( ! V_90 -> V_27 . V_92 )
goto V_143;
V_9 = F_33 ( V_276 , V_90 -> V_27 . V_92 , & V_274 ) ;
if ( ! V_9 ) {
F_43 ( V_109 L_37 ,
V_2 -> V_55 ) ;
goto V_143;
}
}
if ( NULL == V_90 -> V_27 . V_92 ) {
F_43 ( V_109 L_38 , V_2 -> V_55 ) ;
goto V_143;
}
V_90 -> V_27 . V_92 -> V_277 = F_46 ;
V_104 = F_47 ( & V_2 -> V_91 , V_278 , V_2 ,
& V_2 -> V_56 -> V_2 , V_279 , 0 , NULL ) ;
if ( ! V_104 ) {
if ( V_90 -> V_27 . V_92 -> V_43 . V_138 )
V_90 -> V_27 . V_92 -> V_43 . V_138 ( V_90 -> V_27 . V_92 ) ;
if ( V_90 -> V_27 . V_92 -> V_43 . V_148 )
V_90 -> V_27 . V_92 -> V_43 . V_148 ( V_90 -> V_27 . V_92 ) ;
if ( V_90 -> V_27 . V_92 -> V_43 . V_124 . V_148 )
V_90 -> V_27 . V_92 -> V_43 . V_124 . V_148 ( V_90 -> V_27 . V_92 ) ;
}
return V_104 ;
V_143:
F_48 ( & V_2 -> V_91 ) ;
return - V_68 ;
}
static int F_49 ( struct V_1 * V_2 )
{
struct V_89 * V_90 ;
V_90 = F_32 ( & V_2 -> V_91 , 1 ) ;
if ( ! V_90 )
return - V_68 ;
if ( V_2 -> V_120 == V_121 ) {
struct V_280 V_281 ;
static int V_3 = V_282 | V_283 ;
V_281 . V_40 = V_284 ;
V_281 . V_28 = & V_3 ;
F_13 ( V_2 , V_40 , V_285 , & V_281 ) ;
} else if ( V_2 -> V_120 == V_189 ) {
if ( ( V_2 -> V_192 [ 2 ] == 0x07 ) && V_177 ) {
T_2 V_193 = 0x80 ;
struct V_32 V_33 = { . V_34 = 0x08 , . V_36 = & V_193 , . V_35 = 0 , . V_37 = 1 } ;
struct V_8 * V_9 ;
V_9 = V_90 -> V_27 . V_92 ;
if ( V_9 -> V_43 . V_44 ) {
V_9 -> V_43 . V_44 ( V_9 , 1 ) ;
F_12 ( & V_2 -> V_45 , & V_33 , 1 ) ;
V_9 -> V_43 . V_44 ( V_9 , 0 ) ;
}
}
}
F_50 ( & V_2 -> V_91 ) ;
return 0 ;
}
static int T_4 F_51 ( void )
{
return F_52 ( & V_286 ) ;
}
static void T_5 F_53 ( void )
{
F_54 ( & V_286 ) ;
}
