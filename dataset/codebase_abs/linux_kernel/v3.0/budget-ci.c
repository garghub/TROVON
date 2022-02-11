static void F_1 ( unsigned long V_1 )
{
struct V_2 * V_2 = (struct V_2 * ) V_1 ;
struct V_3 * V_4 = V_2 -> V_5 . V_4 ;
T_1 V_6 = F_2 ( & V_2 -> V_7 , V_8 , V_9 , 2 , 1 , 0 ) >> 8 ;
if ( V_10 )
F_3 ( L_1 , V_6 ) ;
V_6 = V_6 & 0x7f ;
if ( V_6 & 0x40 ) {
V_2 -> V_5 . V_11 = true ;
V_2 -> V_5 . V_12 = V_6 & 0x3f ;
return;
}
if ( ! V_2 -> V_5 . V_11 )
return;
V_2 -> V_5 . V_11 = false ;
if ( V_2 -> V_5 . V_13 != V_14 &&
V_2 -> V_5 . V_13 != ( V_6 & 0x1f ) )
return;
if ( V_2 -> V_5 . V_15 ) {
F_4 ( V_4 ,
V_2 -> V_5 . V_13 << 8 | V_2 -> V_5 . V_12 ,
( V_6 & 0x20 ) ? 1 : 0 ) ;
return;
}
F_4 ( V_4 , V_2 -> V_5 . V_12 , ( V_6 & 0x20 ) ? 1 : 0 ) ;
}
static int F_5 ( struct V_2 * V_2 )
{
struct V_16 * V_17 = V_2 -> V_7 . V_4 ;
struct V_3 * V_4 ;
int error ;
V_4 = F_6 () ;
if ( ! V_4 ) {
F_3 ( V_18 L_2 ) ;
return - V_19 ;
}
snprintf ( V_2 -> V_5 . V_20 , sizeof( V_2 -> V_5 . V_20 ) ,
L_3 , V_17 -> V_20 ) ;
snprintf ( V_2 -> V_5 . V_21 , sizeof( V_2 -> V_5 . V_21 ) ,
L_4 , F_7 ( V_17 -> V_22 ) ) ;
V_4 -> V_23 = V_24 ;
V_4 -> V_25 = V_2 -> V_5 . V_20 ;
V_4 -> V_26 = V_2 -> V_5 . V_21 ;
V_4 -> V_27 . V_28 = V_29 ;
V_4 -> V_27 . V_30 = 1 ;
V_4 -> V_31 = 0xff ;
if ( V_17 -> V_22 -> V_32 ) {
V_4 -> V_27 . V_33 = V_17 -> V_22 -> V_32 ;
V_4 -> V_27 . V_34 = V_17 -> V_22 -> V_35 ;
} else {
V_4 -> V_27 . V_33 = V_17 -> V_22 -> V_33 ;
V_4 -> V_27 . V_34 = V_17 -> V_22 -> V_36 ;
}
V_4 -> V_4 . V_37 = & V_17 -> V_22 -> V_4 ;
if ( V_13 < 0 )
V_2 -> V_5 . V_13 = V_14 ;
else
V_2 -> V_5 . V_13 = V_13 ;
switch ( V_2 -> V_7 . V_4 -> V_22 -> V_35 ) {
case 0x100c :
case 0x100f :
case 0x1011 :
case 0x1012 :
V_4 -> V_38 = V_39 ;
V_2 -> V_5 . V_15 = true ;
if ( V_13 < 0 )
V_2 -> V_5 . V_13 = 0x1f ;
break;
case 0x1010 :
case 0x1017 :
case 0x1019 :
case 0x101a :
case 0x101b :
V_4 -> V_38 = V_40 ;
break;
default:
V_4 -> V_38 = V_41 ;
break;
}
error = F_8 ( V_4 ) ;
if ( error ) {
F_3 ( V_18 L_5 , error ) ;
F_9 ( V_4 ) ;
return error ;
}
V_2 -> V_5 . V_4 = V_4 ;
F_10 ( & V_2 -> V_5 . V_42 , F_1 ,
( unsigned long ) V_2 ) ;
F_11 ( V_17 , V_43 ) ;
F_12 ( V_17 , 3 , V_44 ) ;
return 0 ;
}
static void F_13 ( struct V_2 * V_2 )
{
struct V_16 * V_17 = V_2 -> V_7 . V_4 ;
F_14 ( V_17 , V_43 ) ;
F_12 ( V_17 , 3 , V_45 ) ;
F_15 ( & V_2 -> V_5 . V_42 ) ;
F_16 ( V_2 -> V_5 . V_4 ) ;
}
static int F_17 ( struct V_46 * V_47 , int V_48 , int V_49 )
{
struct V_2 * V_2 = (struct V_2 * ) V_47 -> V_1 ;
if ( V_48 != 0 )
return - V_50 ;
return F_2 ( & V_2 -> V_7 , V_51 ,
V_52 | ( V_49 & 0xfff ) , 1 , 1 , 0 ) ;
}
static int F_18 ( struct V_46 * V_47 , int V_48 , int V_49 , T_2 V_53 )
{
struct V_2 * V_2 = (struct V_2 * ) V_47 -> V_1 ;
if ( V_48 != 0 )
return - V_50 ;
return F_19 ( & V_2 -> V_7 , V_51 ,
V_52 | ( V_49 & 0xfff ) , 1 , V_53 , 1 , 0 ) ;
}
static int F_20 ( struct V_46 * V_47 , int V_48 , T_2 V_49 )
{
struct V_2 * V_2 = (struct V_2 * ) V_47 -> V_1 ;
if ( V_48 != 0 )
return - V_50 ;
return F_2 ( & V_2 -> V_7 , V_51 ,
V_54 | ( V_49 & 3 ) , 1 , 1 , 0 ) ;
}
static int F_21 ( struct V_46 * V_47 , int V_48 , T_2 V_49 , T_2 V_53 )
{
struct V_2 * V_2 = (struct V_2 * ) V_47 -> V_1 ;
if ( V_48 != 0 )
return - V_50 ;
return F_19 ( & V_2 -> V_7 , V_51 ,
V_54 | ( V_49 & 3 ) , 1 , V_53 , 1 , 0 ) ;
}
static int F_22 ( struct V_46 * V_47 , int V_48 )
{
struct V_2 * V_2 = (struct V_2 * ) V_47 -> V_1 ;
struct V_16 * V_17 = V_2 -> V_7 . V_4 ;
if ( V_48 != 0 )
return - V_50 ;
if ( V_2 -> V_55 ) {
F_12 ( V_17 , 0 , V_44 ) ;
}
V_2 -> V_56 = V_57 ;
F_19 ( & V_2 -> V_7 , V_58 , V_59 , 1 , 0 , 1 , 0 ) ;
F_23 ( 1 ) ;
F_19 ( & V_2 -> V_7 , V_58 , V_59 , 1 ,
V_60 , 1 , 0 ) ;
F_12 ( V_17 , 1 , V_61 ) ;
F_24 ( V_17 , V_62 ) ;
return 0 ;
}
static int F_25 ( struct V_46 * V_47 , int V_48 )
{
struct V_2 * V_2 = (struct V_2 * ) V_47 -> V_1 ;
struct V_16 * V_17 = V_2 -> V_7 . V_4 ;
if ( V_48 != 0 )
return - V_50 ;
F_12 ( V_17 , 1 , V_61 ) ;
F_24 ( V_17 , V_62 ) ;
return 0 ;
}
static int F_26 ( struct V_46 * V_47 , int V_48 )
{
struct V_2 * V_2 = (struct V_2 * ) V_47 -> V_1 ;
struct V_16 * V_17 = V_2 -> V_7 . V_4 ;
int V_63 ;
if ( V_48 != 0 )
return - V_50 ;
F_12 ( V_17 , 1 , V_64 ) ;
V_63 = F_2 ( & V_2 -> V_7 , V_58 , V_59 , 1 , 1 , 0 ) ;
F_19 ( & V_2 -> V_7 , V_58 , V_59 , 1 ,
V_63 | V_65 , 1 , 0 ) ;
F_24 ( V_17 , V_66 ) ;
return 0 ;
}
static void F_27 ( unsigned long V_1 )
{
struct V_2 * V_2 = (struct V_2 * ) V_1 ;
struct V_16 * V_17 = V_2 -> V_7 . V_4 ;
unsigned int V_67 ;
if ( ! V_2 -> V_7 . V_68 )
return;
V_67 = F_2 ( & V_2 -> V_7 , V_58 , V_59 , 1 , 1 , 0 ) ;
if ( V_67 & V_69 ) {
F_12 ( V_17 , 0 , V_70 ) ;
if ( V_2 -> V_56 & V_71 ) {
V_2 -> V_56 = V_72 ;
F_28 ( & V_2 -> V_47 , 0 ,
V_73 ) ;
} else if ( V_2 -> V_56 & V_57 ) {
V_2 -> V_56 = V_74 ;
F_29 ( & V_2 -> V_47 , 0 ) ;
} else if ( V_2 -> V_56 & V_74 ) {
F_30 ( & V_2 -> V_47 , 0 ) ;
}
} else {
F_12 ( V_17 , 0 , V_44 ) ;
if ( V_2 -> V_56 & V_75 ) {
V_2 -> V_56 = V_71 ;
F_28 ( & V_2 -> V_47 , 0 ,
V_76 ) ;
}
}
}
static int F_31 ( struct V_46 * V_47 , int V_48 , int V_77 )
{
struct V_2 * V_2 = (struct V_2 * ) V_47 -> V_1 ;
unsigned int V_67 ;
if ( ! V_2 -> V_7 . V_68 )
return - V_50 ;
V_67 = F_2 ( & V_2 -> V_7 , V_58 , V_59 , 1 , 1 , 0 ) ;
if ( V_67 & V_69 ) {
if ( V_2 -> V_56 & V_71 ) {
V_2 -> V_56 = V_72 ;
}
if ( V_2 -> V_56 & V_57 ) {
if ( F_17 ( V_47 , V_48 , 0 ) == 0x1d ) {
V_2 -> V_56 = V_74 ;
}
}
} else {
V_2 -> V_56 = V_71 ;
}
if ( V_2 -> V_56 != V_71 ) {
if ( V_2 -> V_56 & V_74 ) {
return V_78 | V_79 ;
}
return V_78 ;
}
return 0 ;
}
static int F_32 ( struct V_2 * V_2 )
{
struct V_16 * V_17 = V_2 -> V_7 . V_4 ;
int V_67 ;
int V_80 ;
int V_81 ;
int V_82 ;
memset ( & V_2 -> V_47 , 0 , sizeof( struct V_46 ) ) ;
F_33 ( V_17 , V_83 , V_84 | V_85 ) ;
V_81 = F_2 ( & V_2 -> V_7 , V_58 , V_86 , 1 , 1 , 0 ) ;
if ( ( V_81 & 0xa0 ) != 0xa0 ) {
V_80 = - V_87 ;
goto error;
}
V_67 = F_2 ( & V_2 -> V_7 , V_58 , V_59 , 1 , 1 , 0 ) ;
V_2 -> V_56 = V_71 ;
if ( V_67 & V_69 )
V_2 -> V_56 = V_72 ;
if ( V_81 == 0xa2 ) {
V_82 = 0 ;
V_2 -> V_55 = 0 ;
} else {
V_82 = V_88 |
V_89 |
V_90 ;
V_2 -> V_55 = 1 ;
}
V_2 -> V_47 . V_91 = V_92 ;
V_2 -> V_47 . V_93 = F_17 ;
V_2 -> V_47 . V_94 = F_18 ;
V_2 -> V_47 . V_95 = F_20 ;
V_2 -> V_47 . V_96 = F_21 ;
V_2 -> V_47 . V_97 = F_22 ;
V_2 -> V_47 . V_98 = F_25 ;
V_2 -> V_47 . V_99 = F_26 ;
V_2 -> V_47 . V_100 = F_31 ;
V_2 -> V_47 . V_1 = V_2 ;
if ( ( V_80 = F_34 ( & V_2 -> V_7 . V_101 ,
& V_2 -> V_47 ,
V_82 , 1 ) ) != 0 ) {
F_3 ( L_6 ) ;
goto error;
}
if ( V_2 -> V_55 ) {
F_10 ( & V_2 -> V_102 , F_27 , ( unsigned long ) V_2 ) ;
if ( V_2 -> V_56 != V_71 ) {
F_12 ( V_17 , 0 , V_70 ) ;
} else {
F_12 ( V_17 , 0 , V_44 ) ;
}
F_11 ( V_17 , V_103 ) ;
}
F_19 ( & V_2 -> V_7 , V_58 , V_59 , 1 ,
V_60 , 1 , 0 ) ;
F_3 ( L_7 ) ;
V_2 -> V_7 . V_68 = 1 ;
if ( V_2 -> V_55 ) {
V_67 = V_76 ;
if ( V_2 -> V_56 != V_71 )
V_67 = V_73 ;
F_28 ( & V_2 -> V_47 , 0 , V_67 ) ;
}
return 0 ;
error:
F_33 ( V_17 , V_83 , V_84 ) ;
return V_80 ;
}
static void F_35 ( struct V_2 * V_2 )
{
struct V_16 * V_17 = V_2 -> V_7 . V_4 ;
if ( V_2 -> V_55 ) {
F_14 ( V_17 , V_103 ) ;
F_12 ( V_17 , 0 , V_45 ) ;
F_15 ( & V_2 -> V_102 ) ;
}
F_19 ( & V_2 -> V_7 , V_58 , V_59 , 1 , 0 , 1 , 0 ) ;
F_23 ( 1 ) ;
F_19 ( & V_2 -> V_7 , V_58 , V_59 , 1 ,
V_60 , 1 , 0 ) ;
F_12 ( V_17 , 1 , V_45 ) ;
F_36 ( & V_2 -> V_47 ) ;
F_33 ( V_17 , V_83 , V_84 ) ;
}
static void F_37 ( struct V_16 * V_4 , T_1 * V_104 )
{
struct V_2 * V_2 = (struct V_2 * ) V_4 -> V_105 ;
F_38 ( 8 , L_8 , V_4 , V_2 ) ;
if ( * V_104 & V_43 )
F_39 ( & V_2 -> V_5 . V_42 ) ;
if ( * V_104 & V_106 )
F_40 ( V_4 , V_104 ) ;
if ( ( * V_104 & V_103 ) && ( V_2 -> V_7 . V_68 ) && ( V_2 -> V_55 ) )
F_39 ( & V_2 -> V_102 ) ;
}
static int F_41 ( struct V_107 * V_108 , T_1 V_109 , T_1 V_110 )
{
F_42 ( V_108 , 0x0e , 0x44 ) ;
if ( V_109 >= 10000000 ) {
F_42 ( V_108 , 0x13 , 0x97 ) ;
F_42 ( V_108 , 0x14 , 0x95 ) ;
F_42 ( V_108 , 0x15 , 0xc9 ) ;
F_42 ( V_108 , 0x17 , 0x8c ) ;
F_42 ( V_108 , 0x1a , 0xfe ) ;
F_42 ( V_108 , 0x1c , 0x7f ) ;
F_42 ( V_108 , 0x2d , 0x09 ) ;
} else {
F_42 ( V_108 , 0x13 , 0x99 ) ;
F_42 ( V_108 , 0x14 , 0x8d ) ;
F_42 ( V_108 , 0x15 , 0xce ) ;
F_42 ( V_108 , 0x17 , 0x43 ) ;
F_42 ( V_108 , 0x1a , 0x1d ) ;
F_42 ( V_108 , 0x1c , 0x12 ) ;
F_42 ( V_108 , 0x2d , 0x05 ) ;
}
F_42 ( V_108 , 0x0e , 0x23 ) ;
F_42 ( V_108 , 0x0f , 0x94 ) ;
F_42 ( V_108 , 0x10 , 0x39 ) ;
F_42 ( V_108 , 0x15 , 0xc9 ) ;
F_42 ( V_108 , 0x1f , ( V_110 >> 16 ) & 0xff ) ;
F_42 ( V_108 , 0x20 , ( V_110 >> 8 ) & 0xff ) ;
F_42 ( V_108 , 0x21 , ( V_110 ) & 0xf0 ) ;
return 0 ;
}
static int F_43 ( struct V_107 * V_108 ,
struct V_111 * V_112 )
{
struct V_2 * V_2 = (struct V_2 * ) V_108 -> V_113 -> V_114 ;
T_1 div ;
T_2 V_115 [ 4 ] ;
struct V_116 V_117 = { . V_118 = 0x60 , . V_67 = 0 , . V_115 = V_115 , . V_119 = sizeof( V_115 ) } ;
if ( ( V_112 -> V_120 < 950000 ) || ( V_112 -> V_120 > 2150000 ) )
return - V_50 ;
div = ( V_112 -> V_120 + ( 500 - 1 ) ) / 500 ;
V_115 [ 0 ] = ( div >> 8 ) & 0x7f ;
V_115 [ 1 ] = div & 0xff ;
V_115 [ 2 ] = 0x80 | ( ( div & 0x18000 ) >> 10 ) | 2 ;
V_115 [ 3 ] = 0x20 ;
if ( V_112 -> V_121 . V_122 . V_123 < 4000000 )
V_115 [ 3 ] |= 1 ;
if ( V_112 -> V_120 < 1250000 )
V_115 [ 3 ] |= 0 ;
else if ( V_112 -> V_120 < 1550000 )
V_115 [ 3 ] |= 0x40 ;
else if ( V_112 -> V_120 < 2050000 )
V_115 [ 3 ] |= 0x80 ;
else if ( V_112 -> V_120 < 2150000 )
V_115 [ 3 ] |= 0xC0 ;
if ( V_108 -> V_124 . V_125 )
V_108 -> V_124 . V_125 ( V_108 , 1 ) ;
if ( F_44 ( & V_2 -> V_7 . V_126 , & V_117 , 1 ) != 1 )
return - V_127 ;
return 0 ;
}
static int F_45 ( struct V_107 * V_108 )
{
struct V_2 * V_2 = (struct V_2 * ) V_108 -> V_113 -> V_114 ;
static T_2 V_128 [] = { 0x0b , 0xf5 , 0x85 , 0xab } ;
static T_2 V_129 [] = { 0x1d , 0x74 , 0xa0 , 0x68 } ;
struct V_116 V_130 = { . V_118 = V_2 -> V_131 , . V_67 = 0 , . V_115 = V_128 , . V_119 =
sizeof( V_128 ) } ;
if ( V_108 -> V_124 . V_125 )
V_108 -> V_124 . V_125 ( V_108 , 1 ) ;
if ( F_44 ( & V_2 -> V_7 . V_126 , & V_130 , 1 ) != 1 )
return - V_127 ;
F_23 ( 1 ) ;
V_130 . V_118 = 0x65 ;
V_130 . V_115 = V_129 ;
V_130 . V_119 = sizeof( V_129 ) ;
if ( V_108 -> V_124 . V_125 )
V_108 -> V_124 . V_125 ( V_108 , 1 ) ;
if ( F_44 ( & V_2 -> V_7 . V_126 , & V_130 , 1 ) != 1 ) {
if ( V_108 -> V_124 . V_125 )
V_108 -> V_124 . V_125 ( V_108 , 1 ) ;
F_44 ( & V_2 -> V_7 . V_126 , & V_130 , 1 ) ;
}
return 0 ;
}
static int F_46 ( struct V_107 * V_108 , struct V_111 * V_112 )
{
struct V_2 * V_2 = (struct V_2 * ) V_108 -> V_113 -> V_114 ;
T_2 V_132 [ 4 ] ;
struct V_116 V_130 = { . V_118 = V_2 -> V_131 , . V_67 = 0 , . V_115 = V_132 , . V_119 = sizeof( V_132 ) } ;
int V_133 = 0 ;
T_2 V_134 , V_135 , V_136 ;
V_133 = V_112 -> V_120 + 36130000 ;
if ( V_133 < 87000000 )
return - V_50 ;
else if ( V_133 < 130000000 )
V_135 = 3 ;
else if ( V_133 < 160000000 )
V_135 = 5 ;
else if ( V_133 < 200000000 )
V_135 = 6 ;
else if ( V_133 < 290000000 )
V_135 = 3 ;
else if ( V_133 < 420000000 )
V_135 = 5 ;
else if ( V_133 < 480000000 )
V_135 = 6 ;
else if ( V_133 < 620000000 )
V_135 = 3 ;
else if ( V_133 < 830000000 )
V_135 = 5 ;
else if ( V_133 < 895000000 )
V_135 = 7 ;
else
return - V_50 ;
if ( V_112 -> V_120 < 49000000 )
return - V_50 ;
else if ( V_112 -> V_120 < 159000000 )
V_134 = 1 ;
else if ( V_112 -> V_120 < 444000000 )
V_134 = 2 ;
else if ( V_112 -> V_120 < 861000000 )
V_134 = 4 ;
else
return - V_50 ;
switch ( V_112 -> V_121 . V_137 . V_138 ) {
case V_139 :
F_47 ( V_108 , 0x0C , 0x14 ) ;
V_136 = 0 ;
break;
case V_140 :
F_47 ( V_108 , 0x0C , 0x80 ) ;
V_136 = 0 ;
break;
case V_141 :
F_47 ( V_108 , 0x0C , 0x14 ) ;
V_136 = 1 ;
break;
default:
return - V_50 ;
}
V_133 = ( ( ( V_112 -> V_120 / 1000 ) * 6 ) + 217280 ) / 1000 ;
V_132 [ 0 ] = V_133 >> 8 ;
V_132 [ 1 ] = V_133 & 0xff ;
V_132 [ 2 ] = 0xca ;
V_132 [ 3 ] = ( V_135 << 5 ) | ( V_136 << 3 ) | V_134 ;
if ( V_108 -> V_124 . V_125 )
V_108 -> V_124 . V_125 ( V_108 , 1 ) ;
if ( F_44 ( & V_2 -> V_7 . V_126 , & V_130 , 1 ) != 1 )
return - V_127 ;
F_23 ( 1 ) ;
return 0 ;
}
static int F_48 ( struct V_107 * V_108 ,
const struct V_142 * * V_143 , char * V_20 )
{
struct V_2 * V_2 = (struct V_2 * ) V_108 -> V_113 -> V_114 ;
return F_49 ( V_143 , V_20 , & V_2 -> V_7 . V_4 -> V_22 -> V_4 ) ;
}
static int F_50 ( struct V_107 * V_108 , struct V_111 * V_112 )
{
struct V_2 * V_2 = (struct V_2 * ) V_108 -> V_113 -> V_114 ;
T_2 V_132 [ 5 ] ;
struct V_116 V_130 = { . V_118 = V_2 -> V_131 ,
. V_67 = 0 ,
. V_115 = V_132 ,
. V_119 = sizeof( V_132 ) } ;
int V_133 = 0 ;
T_2 V_134 , V_135 , V_136 ;
V_133 = V_112 -> V_120 + 36125000 ;
if ( V_133 < 87000000 )
return - V_50 ;
else if ( V_133 < 130000000 ) {
V_135 = 3 ;
V_134 = 1 ;
} else if ( V_133 < 160000000 ) {
V_135 = 5 ;
V_134 = 1 ;
} else if ( V_133 < 200000000 ) {
V_135 = 6 ;
V_134 = 1 ;
} else if ( V_133 < 290000000 ) {
V_135 = 3 ;
V_134 = 2 ;
} else if ( V_133 < 420000000 ) {
V_135 = 5 ;
V_134 = 2 ;
} else if ( V_133 < 480000000 ) {
V_135 = 6 ;
V_134 = 2 ;
} else if ( V_133 < 620000000 ) {
V_135 = 3 ;
V_134 = 4 ;
} else if ( V_133 < 830000000 ) {
V_135 = 5 ;
V_134 = 4 ;
} else if ( V_133 < 895000000 ) {
V_135 = 7 ;
V_134 = 4 ;
} else
return - V_50 ;
V_136 = 1 ;
V_133 = ( V_112 -> V_120 + 36125000 + ( 62500 / 2 ) ) / 62500 ;
V_132 [ 0 ] = V_133 >> 8 ;
V_132 [ 1 ] = V_133 & 0xff ;
V_132 [ 2 ] = 0xc8 ;
V_132 [ 3 ] = ( V_135 << 5 ) | ( V_136 << 3 ) | V_134 ;
V_132 [ 4 ] = 0x80 ;
if ( V_108 -> V_124 . V_125 )
V_108 -> V_124 . V_125 ( V_108 , 1 ) ;
if ( F_44 ( & V_2 -> V_7 . V_126 , & V_130 , 1 ) != 1 )
return - V_127 ;
F_23 ( 50 ) ;
if ( V_108 -> V_124 . V_125 )
V_108 -> V_124 . V_125 ( V_108 , 1 ) ;
if ( F_44 ( & V_2 -> V_7 . V_126 , & V_130 , 1 ) != 1 )
return - V_127 ;
F_23 ( 1 ) ;
return 0 ;
}
static void F_51 ( struct V_2 * V_2 )
{
switch ( V_2 -> V_7 . V_4 -> V_22 -> V_35 ) {
case 0x100c :
V_2 -> V_7 . V_107 =
F_52 ( V_144 , & V_145 , & V_2 -> V_7 . V_126 ) ;
if ( V_2 -> V_7 . V_107 ) {
V_2 -> V_7 . V_107 -> V_124 . V_146 . V_147 = V_148 ;
V_2 -> V_7 . V_107 -> V_149 = & V_2 -> V_7 . V_126 ;
break;
}
break;
case 0x100f :
V_2 -> V_7 . V_107 =
F_52 ( V_144 , & V_150 , & V_2 -> V_7 . V_126 ) ;
if ( V_2 -> V_7 . V_107 ) {
V_2 -> V_7 . V_107 -> V_124 . V_146 . V_147 = F_43 ;
break;
}
break;
case 0x1010 :
V_2 -> V_131 = 0x61 ;
V_2 -> V_7 . V_107 =
F_52 ( V_151 , & V_152 , & V_2 -> V_7 . V_126 ) ;
if ( V_2 -> V_7 . V_107 ) {
V_2 -> V_7 . V_107 -> V_124 . V_146 . V_147 = F_50 ;
break;
}
break;
case 0x1011 :
V_2 -> V_131 = 0x63 ;
V_2 -> V_7 . V_107 =
F_52 ( V_153 , & V_154 , & V_2 -> V_7 . V_126 ) ;
if ( V_2 -> V_7 . V_107 ) {
V_2 -> V_7 . V_107 -> V_124 . V_146 . V_155 = F_45 ;
V_2 -> V_7 . V_107 -> V_124 . V_146 . V_147 = F_46 ;
break;
}
break;
case 0x1012 :
V_2 -> V_131 = 0x60 ;
V_2 -> V_7 . V_107 =
F_52 ( V_156 , & V_157 , & V_2 -> V_7 . V_126 ) ;
if ( V_2 -> V_7 . V_107 ) {
V_2 -> V_7 . V_107 -> V_124 . V_146 . V_155 = F_45 ;
V_2 -> V_7 . V_107 -> V_124 . V_146 . V_147 = F_46 ;
break;
}
break;
case 0x1017 :
V_2 -> V_7 . V_107 = F_52 ( V_144 , & V_158 , & V_2 -> V_7 . V_126 ) ;
if ( V_2 -> V_7 . V_107 ) {
V_2 -> V_7 . V_107 -> V_124 . V_146 . V_147 = V_159 ;
V_2 -> V_7 . V_107 -> V_149 = & V_2 -> V_7 . V_126 ;
V_2 -> V_7 . V_107 -> V_124 . V_160 = NULL ;
if ( F_52 ( V_161 , V_2 -> V_7 . V_107 , & V_2 -> V_7 . V_126 , V_162 , 0 ) == NULL ) {
F_3 ( L_9 , V_163 ) ;
F_53 ( V_2 -> V_7 . V_107 ) ;
V_2 -> V_7 . V_107 = NULL ;
}
}
break;
case 0x101a :
V_2 -> V_7 . V_107 = F_52 ( V_164 , & V_165 , & V_2 -> V_7 . V_126 , 0x48 ) ;
if ( V_2 -> V_7 . V_107 ) {
if ( F_52 ( V_166 , V_2 -> V_7 . V_107 , 0x61 , & V_2 -> V_7 . V_126 , & V_167 ) == NULL ) {
F_3 ( V_18 L_10 , V_163 ) ;
F_53 ( V_2 -> V_7 . V_107 ) ;
V_2 -> V_7 . V_107 = NULL ;
}
}
break;
case 0x101b :
V_2 -> V_7 . V_107 = F_52 ( V_168 , & V_169 , & V_2 -> V_7 . V_126 ) ;
if ( V_2 -> V_7 . V_107 ) {
if ( F_52 ( V_170 , V_2 -> V_7 . V_107 , 0x63 , & V_2 -> V_7 . V_126 ) ) {
if ( ! F_52 ( V_161 , V_2 -> V_7 . V_107 , & V_2 -> V_7 . V_126 , 0 , 0 ) ) {
F_3 ( V_18 L_9 , V_163 ) ;
F_53 ( V_2 -> V_7 . V_107 ) ;
V_2 -> V_7 . V_107 = NULL ;
}
} else {
F_3 ( V_18 L_11 , V_163 ) ;
F_53 ( V_2 -> V_7 . V_107 ) ;
V_2 -> V_7 . V_107 = NULL ;
}
}
break;
case 0x1019 :
F_12 ( V_2 -> V_7 . V_4 , 2 , V_64 ) ;
F_23 ( 50 ) ;
F_12 ( V_2 -> V_7 . V_4 , 2 , V_61 ) ;
F_23 ( 250 ) ;
V_2 -> V_7 . V_107 = F_52 ( V_171 , & V_172 , & V_2 -> V_7 . V_126 ) ;
if ( V_2 -> V_7 . V_107 ) {
if ( F_52 ( V_173 , V_2 -> V_7 . V_107 , & V_174 , & V_2 -> V_7 . V_126 ) ) {
if ( ! F_52 ( V_161 , V_2 -> V_7 . V_107 , & V_2 -> V_7 . V_126 , 0 , 0 ) ) {
F_3 ( L_9 , V_163 ) ;
F_53 ( V_2 -> V_7 . V_107 ) ;
V_2 -> V_7 . V_107 = NULL ;
}
} else {
F_53 ( V_2 -> V_7 . V_107 ) ;
V_2 -> V_7 . V_107 = NULL ;
}
}
break;
}
if ( V_2 -> V_7 . V_107 == NULL ) {
F_3 ( L_12 ,
V_2 -> V_7 . V_4 -> V_22 -> V_33 ,
V_2 -> V_7 . V_4 -> V_22 -> V_36 ,
V_2 -> V_7 . V_4 -> V_22 -> V_32 ,
V_2 -> V_7 . V_4 -> V_22 -> V_35 ) ;
} else {
if ( F_54
( & V_2 -> V_7 . V_101 , V_2 -> V_7 . V_107 ) ) {
F_3 ( L_13 ) ;
F_53 ( V_2 -> V_7 . V_107 ) ;
V_2 -> V_7 . V_107 = NULL ;
}
}
}
static int F_55 ( struct V_16 * V_4 , struct V_175 * V_176 )
{
struct V_2 * V_2 ;
int V_177 ;
V_2 = F_56 ( sizeof( struct V_2 ) , V_178 ) ;
if ( ! V_2 ) {
V_177 = - V_19 ;
goto V_179;
}
F_38 ( 2 , L_14 , V_2 ) ;
V_4 -> V_105 = V_2 ;
V_177 = F_57 ( & V_2 -> V_7 , V_4 , V_176 , V_92 ,
V_180 ) ;
if ( V_177 )
goto V_181;
V_177 = F_5 ( V_2 ) ;
if ( V_177 )
goto V_182;
F_32 ( V_2 ) ;
V_2 -> V_7 . V_101 . V_114 = V_2 ;
F_51 ( V_2 ) ;
F_58 ( & V_2 -> V_7 ) ;
return 0 ;
V_182:
F_59 ( & V_2 -> V_7 ) ;
V_181:
F_60 ( V_2 ) ;
V_179:
return V_177 ;
}
static int F_61 ( struct V_16 * V_4 )
{
struct V_2 * V_2 = (struct V_2 * ) V_4 -> V_105 ;
struct V_16 * V_17 = V_2 -> V_7 . V_4 ;
int V_177 ;
if ( V_2 -> V_7 . V_68 )
F_35 ( V_2 ) ;
F_13 ( V_2 ) ;
if ( V_2 -> V_7 . V_107 ) {
F_62 ( V_2 -> V_7 . V_107 ) ;
F_53 ( V_2 -> V_7 . V_107 ) ;
}
V_177 = F_59 ( & V_2 -> V_7 ) ;
F_12 ( V_17 , 2 , V_45 ) ;
F_60 ( V_2 ) ;
return V_177 ;
}
static int T_3 F_63 ( void )
{
return F_64 ( & V_183 ) ;
}
static void T_4 F_65 ( void )
{
F_66 ( & V_183 ) ;
}
