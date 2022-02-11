static int F_1 ( struct V_1 * V_2 ,
unsigned int * V_3 , unsigned int * V_4 ,
unsigned int V_5 [] , struct V_6 * V_7 [] )
{
struct V_8 * V_9 = V_2 -> V_10 ;
* V_4 = 1 ;
V_9 -> V_11 = 188 * 4 ;
V_9 -> V_12 = V_13 ;
V_5 [ 0 ] = V_9 -> V_11 * V_9 -> V_12 ;
* V_3 = V_13 ;
return 0 ;
}
static int F_2 ( struct V_14 * V_15 )
{
struct V_16 * V_17 = F_3 ( V_15 ) ;
struct V_8 * V_9 = V_15 -> V_1 -> V_10 ;
struct V_18 * V_19 = F_4 ( V_17 , struct V_18 , V_15 ) ;
return F_5 ( V_15 -> V_1 , V_9 , V_19 ) ;
}
static void F_6 ( struct V_14 * V_15 )
{
struct V_16 * V_17 = F_3 ( V_15 ) ;
struct V_8 * V_9 = V_15 -> V_1 -> V_10 ;
struct V_18 * V_19 = F_4 ( V_17 , struct V_18 , V_15 ) ;
struct V_20 * V_21 = & V_19 -> V_21 ;
if ( V_21 -> V_22 )
F_7 ( V_9 -> V_23 , V_21 -> V_24 , V_21 -> V_22 , V_21 -> V_25 ) ;
memset ( V_21 , 0 , sizeof( * V_21 ) ) ;
}
static void F_8 ( struct V_14 * V_15 )
{
struct V_16 * V_17 = F_3 ( V_15 ) ;
struct V_8 * V_9 = V_15 -> V_1 -> V_10 ;
struct V_18 * V_19 = F_4 ( V_17 , struct V_18 , V_15 ) ;
F_9 ( V_9 , V_19 ) ;
}
static int F_10 ( struct V_1 * V_2 , unsigned int V_26 )
{
struct V_8 * V_9 = V_2 -> V_10 ;
struct V_27 * V_28 = & V_9 -> V_29 ;
struct V_18 * V_19 ;
V_19 = F_11 ( V_28 -> V_30 . V_31 , struct V_18 , V_32 ) ;
F_12 ( V_9 , V_28 , V_19 ) ;
return 0 ;
}
static void F_13 ( struct V_1 * V_2 )
{
struct V_8 * V_9 = V_2 -> V_10 ;
struct V_27 * V_28 = & V_9 -> V_29 ;
unsigned long V_33 ;
F_14 ( V_9 ) ;
F_15 ( & V_9 -> V_34 , V_33 ) ;
while ( ! F_16 ( & V_28 -> V_30 ) ) {
struct V_18 * V_19 = F_11 ( V_28 -> V_30 . V_31 ,
struct V_18 , V_32 ) ;
F_17 ( & V_19 -> V_32 ) ;
F_18 ( & V_19 -> V_15 . V_35 , V_36 ) ;
}
F_19 ( & V_9 -> V_34 , V_33 ) ;
}
static int F_20 ( struct V_37 * V_38 , int V_39 )
{
struct V_8 * V_9 = V_38 -> V_40 -> V_41 ;
struct V_42 * V_43 = NULL ;
int V_44 = 0 ;
int V_45 ;
V_45 = F_21 ( & V_9 -> V_46 , V_38 ) ;
if ( ! V_45 ) {
F_22 ( L_1 , V_47 ) ;
return - V_48 ;
}
F_23 ( & V_9 -> V_49 -> V_50 ) ;
V_43 = F_24 ( V_9 , V_51 ) ;
if ( V_43 ) {
if ( V_39 ) {
V_9 -> V_46 . V_52 = V_45 ;
V_44 = V_43 -> V_53 ( V_43 ) ;
} else {
V_44 = V_43 -> V_54 ( V_43 ) ;
V_9 -> V_46 . V_52 = 0 ;
}
}
F_25 ( & V_9 -> V_49 -> V_50 ) ;
return V_44 ;
}
static void F_26 ( struct V_55 * V_49 , int V_56 )
{
struct V_57 * V_58 ;
struct V_59 * V_38 ;
if ( ! V_49 -> V_60 )
return;
V_58 = & V_49 -> V_60 -> V_46 ;
if ( ! V_58 )
return;
if ( V_58 -> V_61 <= 1 )
V_38 = F_27 ( V_58 , 1 ) ;
else
V_38 = F_27 ( V_58 , V_58 -> V_61 ) ;
if ( V_38 && V_38 -> V_40 . V_62 && V_38 -> V_40 . V_62 -> V_63 . V_64 )
V_38 -> V_40 . V_62 -> V_63 . V_64 ( V_38 -> V_40 . V_62 , V_56 ) ;
}
static int F_28 ( struct V_37 * V_38 )
{
static const T_1 V_65 [] = { V_66 , 0x38 , 0x39 } ;
static const T_1 V_67 [] = { V_68 , 0x80 } ;
static const T_1 V_69 [] = { V_70 , 0x40 } ;
static const T_1 V_71 [] = { V_72 , 0x24 , 0x20 } ;
static const T_1 V_73 [] = { V_74 , 0x33 } ;
static const T_1 V_75 [] = { V_76 , 0x32 } ;
F_29 ( V_38 , V_65 , sizeof( V_65 ) ) ;
F_30 ( 200 ) ;
F_29 ( V_38 , V_67 , sizeof( V_67 ) ) ;
F_29 ( V_38 , V_69 , sizeof( V_69 ) ) ;
F_29 ( V_38 , V_71 , sizeof( V_71 ) ) ;
F_29 ( V_38 , V_73 , sizeof( V_73 ) ) ;
F_29 ( V_38 , V_75 , sizeof( V_75 ) ) ;
return 0 ;
}
static int F_31 ( struct V_37 * V_38 )
{
static const T_1 V_65 [] = { V_66 , 0x38 , 0x38 } ;
static const T_1 V_67 [] = { V_68 , 0x80 } ;
static const T_1 V_69 [] = { V_70 , 0x40 } ;
static const T_1 V_71 [] = { V_72 , 0x28 , 0x20 } ;
static const T_1 V_73 [] = { V_74 , 0x33 } ;
static const T_1 V_75 [] = { V_76 , 0x32 } ;
F_29 ( V_38 , V_65 , sizeof( V_65 ) ) ;
F_30 ( 200 ) ;
F_29 ( V_38 , V_67 , sizeof( V_67 ) ) ;
F_29 ( V_38 , V_69 , sizeof( V_69 ) ) ;
F_29 ( V_38 , V_71 , sizeof( V_71 ) ) ;
F_29 ( V_38 , V_73 , sizeof( V_73 ) ) ;
F_29 ( V_38 , V_75 , sizeof( V_75 ) ) ;
return 0 ;
}
static int F_32 ( struct V_37 * V_38 )
{
static const T_1 V_65 [] = { 0x89 , 0x38 , 0x39 } ;
static const T_1 V_67 [] = { 0x50 , 0x80 } ;
static const T_1 V_69 [] = { 0x8E , 0x40 } ;
static const T_1 V_71 [] = { 0x67 , 0x10 , 0x23 , 0x00 , 0xFF , 0xFF ,
0x00 , 0xFF , 0x00 , 0x40 , 0x40 } ;
static const T_1 V_77 [] = { 0xB5 , 0x7A } ;
static const T_1 V_75 [] = { 0x75 , 0x32 } ;
F_29 ( V_38 , V_65 , sizeof( V_65 ) ) ;
F_30 ( 2000 ) ;
F_29 ( V_38 , V_67 , sizeof( V_67 ) ) ;
F_29 ( V_38 , V_69 , sizeof( V_69 ) ) ;
F_29 ( V_38 , V_71 , sizeof( V_71 ) ) ;
F_30 ( 2000 ) ;
F_29 ( V_38 , V_77 , sizeof( V_77 ) ) ;
F_29 ( V_38 , V_75 , sizeof( V_75 ) ) ;
return 0 ;
}
static int F_33 ( struct V_37 * V_38 )
{
static const T_1 V_65 [] = { 0x89 , 0x38 , 0x38 } ;
static const T_1 V_67 [] = { 0x50 , 0x80 } ;
static const T_1 V_69 [] = { 0x8E , 0x40 } ;
static const T_1 V_71 [] = { 0x67 , 0x10 , 0x20 , 0x00 , 0xFF , 0xFF ,
0x00 , 0xFF , 0x00 , 0x40 , 0x40 } ;
static const T_1 V_77 [] = { 0xB5 , 0x7A } ;
static const T_1 V_75 [] = { 0x75 , 0x32 } ;
F_29 ( V_38 , V_65 , sizeof( V_65 ) ) ;
F_30 ( 2000 ) ;
F_29 ( V_38 , V_67 , sizeof( V_67 ) ) ;
F_29 ( V_38 , V_69 , sizeof( V_69 ) ) ;
F_29 ( V_38 , V_71 , sizeof( V_71 ) ) ;
F_30 ( 2000 ) ;
F_29 ( V_38 , V_77 , sizeof( V_77 ) ) ;
F_29 ( V_38 , V_75 , sizeof( V_75 ) ) ;
return 0 ;
}
static int F_34 ( struct V_37 * V_38 , int V_78 )
{
struct V_8 * V_9 = V_38 -> V_40 -> V_41 ;
V_9 -> V_79 = V_78 ? 0x04 : 0x00 ;
return 0 ;
}
static int F_35 ( struct V_37 * V_38 , int V_80 )
{
struct V_8 * V_9 = V_38 -> V_40 -> V_41 ;
struct V_55 * V_49 = V_9 -> V_49 ;
F_36 ( 1 , L_2 , V_47 , V_80 ) ;
if ( V_80 == 0 )
F_37 ( V_81 , 8 ) ;
else
F_38 ( V_81 , 8 ) ;
return 0 ;
}
static int F_39 ( struct V_37 * V_38 , int V_78 )
{
struct V_8 * V_9 = V_38 -> V_40 -> V_41 ;
if ( V_78 )
V_9 -> V_79 |= 0x04 ;
else
V_9 -> V_79 &= ~ 0x04 ;
return 0 ;
}
static int F_40 ( struct V_37 * V_38 , int V_78 )
{
struct V_8 * V_9 = V_38 -> V_40 -> V_41 ;
V_9 -> V_79 = V_78 ? 0x04 : 0x00 ;
return 0 ;
}
static int F_41 ( struct V_37 * V_38 ,
int V_78 )
{
struct V_8 * V_9 = V_38 -> V_40 -> V_41 ;
V_9 -> V_79 = 0x02 ;
return 0 ;
}
static int F_42 ( struct V_37 * V_38 ,
enum V_82 V_83 )
{
struct V_8 * V_9 = V_38 -> V_40 -> V_41 ;
struct V_55 * V_49 = V_9 -> V_49 ;
if ( V_83 == V_84 )
F_43 ( V_81 , 0x000006fb ) ;
else
F_43 ( V_81 , 0x000006f9 ) ;
if ( V_49 -> V_85 )
return V_49 -> V_85 ( V_38 , V_83 ) ;
return 0 ;
}
static int F_44 ( struct V_37 * V_38 ,
enum V_82 V_83 )
{
struct V_8 * V_9 = V_38 -> V_40 -> V_41 ;
struct V_55 * V_49 = V_9 -> V_49 ;
if ( V_83 == V_84 ) {
F_36 ( 1 , L_3 ) ;
F_43 ( V_81 , 0x0000efff ) ;
}
if ( V_49 -> V_85 )
return V_49 -> V_85 ( V_38 , V_83 ) ;
return 0 ;
}
static int F_45 ( struct V_37 * V_38 ,
enum V_82 V_83 )
{
struct V_8 * V_9 = V_38 -> V_40 -> V_41 ;
struct V_55 * V_49 = V_9 -> V_49 ;
F_38 ( V_81 , 0x6040 ) ;
switch ( V_83 ) {
case V_86 :
F_37 ( V_81 , 0x20 ) ;
break;
case V_87 :
F_38 ( V_81 , 0x20 ) ;
break;
case V_84 :
F_37 ( V_81 , 0x20 ) ;
break;
}
if ( V_49 -> V_85 )
return V_49 -> V_85 ( V_38 , V_83 ) ;
return 0 ;
}
static int F_46 ( struct V_37 * V_38 ,
enum V_82 V_83 )
{
struct V_8 * V_9 = V_38 -> V_40 -> V_41 ;
struct V_55 * V_49 = V_9 -> V_49 ;
switch ( V_83 ) {
case V_86 :
F_36 ( 1 , L_4 ) ;
F_43 ( V_81 , 0x00001220 ) ;
break;
case V_87 :
F_36 ( 1 , L_5 ) ;
F_43 ( V_81 , 0x00001222 ) ;
break;
case V_84 :
F_36 ( 1 , L_3 ) ;
F_43 ( V_81 , 0x00001230 ) ;
break;
}
if ( V_49 -> V_85 )
return V_49 -> V_85 ( V_38 , V_83 ) ;
return 0 ;
}
static int F_47 ( T_1 V_88 , struct V_8 * V_9 )
{
struct V_37 * V_38 ;
struct V_59 * V_89 = NULL ;
struct V_90 V_91 ;
struct V_92 V_93 = {
. V_94 = & V_9 -> V_49 -> V_94 ,
. V_95 = V_88 ,
. V_96 = & V_91 ,
} ;
V_89 = F_27 ( & V_9 -> V_46 , 1 ) ;
if ( ! V_89 )
return - V_48 ;
if ( ! V_89 -> V_40 . V_62 ) {
F_22 ( L_6 ) ;
return - V_48 ;
}
F_48 ( V_9 -> V_49 , & V_91 ) ;
V_38 = F_49 ( V_97 , V_89 -> V_40 . V_62 , & V_93 ) ;
if ( ! V_38 ) {
F_22 ( L_7 ) ;
F_50 ( V_89 -> V_40 . V_62 ) ;
F_51 ( V_89 -> V_40 . V_62 ) ;
V_89 -> V_40 . V_62 = NULL ;
return - V_48 ;
}
F_52 ( L_8 ) ;
return 0 ;
}
static int F_53 ( struct V_8 * V_9 , struct V_98 * V_93 )
{
struct V_37 * V_38 ;
struct V_59 * V_89 = NULL ;
V_89 = F_27 ( & V_9 -> V_46 , 1 ) ;
if ( ! V_89 )
return - V_48 ;
if ( ! V_89 -> V_40 . V_62 ) {
F_22 ( L_9 ) ;
return - V_48 ;
}
V_38 = F_49 ( V_99 , V_89 -> V_40 . V_62 , & V_9 -> V_49 -> V_94 ,
V_93 ) ;
if ( ! V_38 ) {
F_22 ( L_10 ) ;
F_50 ( V_89 -> V_40 . V_62 ) ;
F_51 ( V_89 -> V_40 . V_62 ) ;
V_89 -> V_40 . V_62 = NULL ;
return - V_48 ;
}
F_52 ( L_11 ) ;
return 0 ;
}
static int F_54 ( struct V_37 * V_38 ,
int V_78 )
{
struct V_8 * V_9 = V_38 -> V_40 -> V_41 ;
V_9 -> V_79 = 0x2 ;
return 0 ;
}
static int F_55 ( struct V_37 * V_38 ,
int V_78 )
{
struct V_8 * V_9 = V_38 -> V_40 -> V_41 ;
V_9 -> V_79 = 0 ;
return 0 ;
}
static int F_56 ( struct V_37 * V_38 )
{
struct V_8 * V_9 = V_38 -> V_40 -> V_41 ;
struct V_55 * V_49 = V_9 -> V_49 ;
F_43 ( V_100 , 0 ) ;
F_57 ( 10000 , 20000 ) ;
F_43 ( V_100 , 1 ) ;
F_57 ( 10000 , 20000 ) ;
return 0 ;
}
static int F_58 ( struct V_37 * V_38 ,
int V_78 )
{
struct V_8 * V_9 = V_38 -> V_40 -> V_41 ;
V_9 -> V_79 = 4 ;
return 0 ;
}
static int F_59 ( struct V_8 * V_9 )
{
struct V_55 * V_49 = V_9 -> V_49 ;
struct V_59 * V_38 = NULL ;
int V_101 ;
F_60 ( & V_9 -> V_46 . V_50 ) ;
F_61 ( & V_9 -> V_46 . V_102 ) ;
if ( ! V_49 -> V_103 . V_104 )
return - V_105 ;
F_52 ( L_12 , V_47 ,
V_49 -> V_103 . V_104 ) ;
for ( V_101 = 1 ; V_101 <= V_49 -> V_103 . V_104 ; V_101 ++ ) {
V_38 = F_62 ( & V_9 -> V_46 , V_101 ) ;
if ( ! V_38 ) {
F_22 ( L_13 , V_47 ) ;
F_63 ( & V_9 -> V_46 ) ;
return - V_106 ;
}
}
return 0 ;
}
static int F_64 ( struct V_37 * V_38 )
{
struct V_107 * V_108 = & V_38 -> V_109 ;
struct V_8 * V_9 = V_38 -> V_40 -> V_41 ;
T_1 V_19 [ 4 ] ;
T_2 div ;
struct V_110 V_111 = {
. V_88 = 0x61 ,
. V_33 = 0 ,
. V_19 = V_19 ,
. V_112 = sizeof( V_19 ) } ;
div = V_108 -> V_113 / 125 ;
V_19 [ 0 ] = ( div >> 8 ) & 0x7f ;
V_19 [ 1 ] = div & 0xff ;
V_19 [ 2 ] = 0x84 ;
V_19 [ 3 ] = 0x00 ;
if ( V_108 -> V_113 < 1500000 )
V_19 [ 3 ] |= 0x10 ;
if ( V_38 -> V_63 . V_64 )
V_38 -> V_63 . V_64 ( V_38 , 1 ) ;
if ( F_65 ( & V_9 -> V_49 -> V_94 , & V_111 , 1 ) != 1 )
return - V_114 ;
return 0 ;
}
static int F_66 ( struct V_37 * V_38 ,
enum V_115 V_116 )
{
struct V_8 * V_9 = V_38 -> V_40 -> V_41 ;
struct V_55 * V_49 = V_9 -> V_49 ;
F_38 ( V_81 , 0x0800 ) ;
switch ( V_116 ) {
case V_117 :
F_38 ( V_81 , 0x08 ) ;
break;
case V_118 :
F_37 ( V_81 , 0x08 ) ;
break;
default:
return - V_48 ;
}
return 0 ;
}
static int F_67 ( struct V_37 * V_38 ,
enum V_82 V_83 )
{
struct V_8 * V_9 = V_38 -> V_40 -> V_41 ;
struct V_55 * V_49 = V_9 -> V_49 ;
T_1 V_119 ;
struct V_110 V_111 = {
. V_88 = 8 ,
. V_33 = 0 ,
. V_19 = & V_119 ,
. V_112 = sizeof( V_119 ) } ;
F_38 ( V_81 , 0x8000 ) ;
switch ( V_83 ) {
case V_84 :
break;
case V_86 :
V_119 = V_120 | V_121 ;
F_37 ( V_81 , 0x80 ) ;
break;
case V_87 :
V_119 = V_120 | V_121 | V_122 ;
F_37 ( V_81 , 0x80 ) ;
break;
default:
return - V_48 ;
}
return ( F_65 ( & V_9 -> V_49 -> V_94 , & V_111 , 1 ) == 1 ) ? 0 : - V_114 ;
}
static int F_68 ( struct V_37 * V_38 ,
T_2 V_123 , T_2 V_124 )
{
T_1 V_125 = 0 ;
T_1 V_126 = 0 ;
if ( V_123 < 1500000 ) {
V_125 = 0xb7 ;
V_126 = 0x47 ;
} else if ( V_123 < 3000000 ) {
V_125 = 0xb7 ;
V_126 = 0x4b ;
} else if ( V_123 < 7000000 ) {
V_125 = 0xb7 ;
V_126 = 0x4f ;
} else if ( V_123 < 14000000 ) {
V_125 = 0xb7 ;
V_126 = 0x53 ;
} else if ( V_123 < 30000000 ) {
V_125 = 0xb6 ;
V_126 = 0x53 ;
} else if ( V_123 < 45000000 ) {
V_125 = 0xb4 ;
V_126 = 0x51 ;
}
F_69 ( V_38 , 0x13 , V_125 ) ;
F_69 ( V_38 , 0x14 , V_126 ) ;
F_69 ( V_38 , 0x1f , ( V_124 >> 16 ) & 0xff ) ;
F_69 ( V_38 , 0x20 , ( V_124 >> 8 ) & 0xff ) ;
F_69 ( V_38 , 0x21 , V_124 & 0xf0 ) ;
return 0 ;
}
static int F_70 ( struct V_8 * V_9 )
{
struct V_55 * V_49 = V_9 -> V_49 ;
struct V_59 * V_89 , * V_127 = NULL ;
int V_128 = 0 ;
int V_129 = - V_48 ;
if ( V_49 -> V_130 != 0 ) {
F_22 ( L_14 ) ;
goto V_131;
}
V_89 = F_27 ( & V_9 -> V_46 , 1 ) ;
if ( ! V_89 )
goto V_131;
V_9 -> V_46 . V_61 = 0 ;
V_49 -> V_132 = F_26 ;
switch ( V_49 -> V_133 ) {
case V_134 :
V_89 -> V_40 . V_62 = F_49 ( V_135 ,
& V_136 ,
& V_49 -> V_94 ) ;
if ( V_89 -> V_40 . V_62 ) {
if ( ! F_49 ( V_137 , V_89 -> V_40 . V_62 ,
0x61 , & V_49 -> V_94 ,
V_138 ) )
goto V_131;
}
break;
case V_139 :
case V_140 :
case V_141 :
case V_142 :
V_89 -> V_40 . V_62 = F_49 ( V_135 ,
& V_136 ,
& V_49 -> V_94 ) ;
if ( V_89 -> V_40 . V_62 ) {
if ( ! F_49 ( V_137 , V_89 -> V_40 . V_62 ,
0x60 , & V_49 -> V_94 ,
V_143 ) )
goto V_131;
}
break;
case V_144 :
case V_145 :
case V_146 :
case V_147 :
V_89 -> V_40 . V_62 = F_49 ( V_135 ,
& V_148 ,
& V_49 -> V_94 ) ;
if ( V_89 -> V_40 . V_62 ) {
if ( ! F_49 ( V_149 , V_89 -> V_40 . V_62 ,
& V_49 -> V_94 , 0x61 ,
V_150 ) )
goto V_131;
}
break;
case V_151 :
V_89 -> V_40 . V_62 = F_49 ( V_135 ,
& V_148 ,
& V_49 -> V_94 ) ;
if ( V_89 -> V_40 . V_62 ) {
if ( ! F_49 ( V_149 , V_89 -> V_40 . V_62 ,
& V_49 -> V_94 , 0x61 ,
V_152 ) )
goto V_131;
}
break;
case V_153 :
V_128 = 1 ;
V_9 -> V_46 . V_61 = 2 ;
V_89 -> V_40 . V_62 = F_49 ( V_154 ,
& V_155 ,
& V_9 -> V_49 -> V_94 ) ;
if ( V_89 -> V_40 . V_62 ) {
if ( ! F_49 ( V_156 ,
V_89 -> V_40 . V_62 ,
& V_9 -> V_49 -> V_94 ,
0x08 , V_157 , 0x00 , false ) )
goto V_131;
}
V_127 = F_27 ( & V_9 -> V_46 , 2 ) ;
if ( ! V_127 )
goto V_131;
V_127 -> V_40 . V_62 = F_49 ( V_135 ,
& V_148 ,
& V_9 -> V_49 -> V_94 ) ;
if ( V_127 -> V_40 . V_62 ) {
V_127 -> V_40 . V_62 -> V_158 = 1 ;
if ( ! F_49 ( V_149 ,
V_127 -> V_40 . V_62 ,
& V_9 -> V_49 -> V_94 ,
0x61 , V_150 ) )
goto V_131;
}
break;
case V_159 :
V_89 -> V_40 . V_62 = F_49 ( V_160 ,
& V_161 ,
& V_49 -> V_94 ) ;
if ( V_89 -> V_40 . V_62 ) {
if ( ! F_49 ( V_137 , V_89 -> V_40 . V_62 ,
0x60 , NULL , V_143 ) )
goto V_131;
break;
}
V_89 -> V_40 . V_62 = F_49 ( V_162 ,
& V_163 ,
& V_49 -> V_94 ) ;
if ( V_89 -> V_40 . V_62 ) {
if ( ! F_49 ( V_137 , V_89 -> V_40 . V_62 ,
0x60 , NULL , V_143 ) )
goto V_131;
}
break;
case V_164 :
V_89 -> V_40 . V_62 = F_49 ( V_160 ,
& V_165 ,
& V_49 -> V_94 ) ;
if ( V_89 -> V_40 . V_62 ) {
if ( ! F_49 ( V_137 , V_89 -> V_40 . V_62 ,
0x61 , NULL , V_143 ) )
goto V_131;
break;
}
V_89 -> V_40 . V_62 = F_49 ( V_162 ,
& V_163 ,
& V_49 -> V_94 ) ;
if ( V_89 -> V_40 . V_62 ) {
if ( ! F_49 ( V_137 , V_89 -> V_40 . V_62 ,
0x61 , NULL , V_143 ) )
goto V_131;
}
break;
case V_166 :
V_89 -> V_40 . V_62 = F_49 ( V_160 ,
& V_161 ,
& V_49 -> V_94 ) ;
if ( V_89 -> V_40 . V_62 ) {
if ( ! F_49 ( V_137 , V_89 -> V_40 . V_62 ,
0x61 , NULL , V_167 ) )
goto V_131;
}
break;
case V_168 :
case V_169 :
case V_170 :
V_89 -> V_40 . V_62 = F_49 ( V_160 ,
& V_171 ,
& V_49 -> V_94 ) ;
if ( V_89 -> V_40 . V_62 ) {
if ( ! F_49 ( V_137 , V_89 -> V_40 . V_62 ,
0x61 , NULL , V_172 ) )
goto V_131;
}
break;
case V_173 :
#if F_71 ( V_174 )
V_89 -> V_40 . V_62 = F_49 ( V_160 ,
& V_175 ,
& V_9 -> V_176 -> V_177 ) ;
if ( V_89 -> V_40 . V_62 ) {
if ( ! F_49 ( V_149 , V_89 -> V_40 . V_62 ,
& V_49 -> V_94 , 0x61 ,
V_150 ) )
goto V_131;
}
#else
F_22 ( L_15 ) ;
#endif
break;
case V_178 :
V_89 -> V_40 . V_62 = F_49 ( V_162 ,
& V_179 ,
& V_49 -> V_94 ) ;
if ( V_89 -> V_40 . V_62 ) {
if ( ! F_49 ( V_149 , V_89 -> V_40 . V_62 ,
& V_49 -> V_94 , 0x61 ,
V_180 ) )
goto V_131;
}
break;
case V_181 :
V_89 -> V_40 . V_62 = F_49 ( V_162 ,
& V_182 ,
& V_49 -> V_94 ) ;
if ( ! V_89 -> V_40 . V_62 )
V_89 -> V_40 . V_62 = F_49 ( V_160 ,
& V_183 ,
& V_49 -> V_94 ) ;
if ( V_89 -> V_40 . V_62 )
V_89 -> V_40 . V_62 -> V_63 . V_64 = NULL ;
if ( F_47 ( 0x61 , V_9 ) < 0 )
goto V_131;
break;
case V_184 :
V_89 -> V_40 . V_62 = F_49 ( V_185 , & V_186 ,
& V_49 -> V_94 ) ;
if ( V_89 -> V_40 . V_62 ) {
if ( ! F_49 ( V_149 , V_89 -> V_40 . V_62 ,
& V_49 -> V_94 , 0x61 ,
V_187 ) )
goto V_131;
}
break;
case V_188 :
V_9 -> V_79 = 0x08 ;
F_37 ( V_81 , 1 ) ;
F_72 ( 100 ) ;
F_38 ( V_81 , 1 ) ;
F_72 ( 200 ) ;
V_189 . V_190 = F_35 ;
V_89 -> V_40 . V_62 = F_49 ( V_191 ,
& V_189 ,
& V_49 -> V_94 ) ;
if ( V_89 -> V_40 . V_62 ) {
if ( ! F_49 ( V_149 , V_89 -> V_40 . V_62 ,
& V_49 -> V_94 , 0x61 ,
V_192 ) )
goto V_131;
}
break;
case V_193 :
V_9 -> V_79 = 0x08 ;
F_37 ( V_81 , 1 ) ;
F_72 ( 100 ) ;
F_38 ( V_81 , 9 ) ;
F_72 ( 200 ) ;
V_89 -> V_40 . V_62 = F_49 ( V_191 ,
& V_189 ,
& V_49 -> V_94 ) ;
if ( V_89 -> V_40 . V_62 ) {
if ( ! F_49 ( V_149 , V_89 -> V_40 . V_62 ,
& V_49 -> V_94 , 0x61 ,
V_187 ) )
goto V_131;
}
break;
case V_194 :
V_9 -> V_79 = 0x08 ;
F_37 ( V_81 , 1 ) ;
F_72 ( 100 ) ;
F_38 ( V_81 , 1 ) ;
F_72 ( 200 ) ;
V_89 -> V_40 . V_62 = F_49 ( V_191 ,
& V_195 ,
& V_49 -> V_94 ) ;
if ( V_89 -> V_40 . V_62 ) {
if ( ! F_49 ( V_149 , V_89 -> V_40 . V_62 ,
& V_49 -> V_94 , 0x61 ,
V_196 ) )
goto V_131;
if ( ! F_49 ( V_197 , V_89 -> V_40 . V_62 ,
& V_49 -> V_94 , 0x43 ) )
goto V_131;
}
break;
case V_198 :
V_9 -> V_79 = 0x08 ;
F_37 ( V_81 , 1 ) ;
F_72 ( 100 ) ;
F_38 ( V_81 , 1 ) ;
F_72 ( 200 ) ;
V_89 -> V_40 . V_62 = F_49 ( V_191 ,
& V_199 ,
& V_49 -> V_94 ) ;
if ( V_89 -> V_40 . V_62 ) {
if ( ! F_49 ( V_149 , V_89 -> V_40 . V_62 ,
& V_49 -> V_94 , 0x61 ,
V_196 ) )
goto V_131;
if ( ! F_49 ( V_197 , V_89 -> V_40 . V_62 ,
& V_49 -> V_94 , 0x43 ) )
goto V_131;
}
break;
case V_200 :
V_89 -> V_40 . V_62 = F_49 ( V_201 ,
& V_202 ,
& V_49 -> V_94 ) ;
if ( V_89 -> V_40 . V_62 ) {
if ( ! F_49 ( V_149 , V_89 -> V_40 . V_62 ,
& V_49 -> V_94 , 0x61 ,
V_203 ) )
goto V_131;
}
break;
case V_204 :
case V_205 :
V_89 -> V_40 . V_62 = F_49 ( V_154 ,
& V_155 ,
& V_49 -> V_94 ) ;
if ( V_89 -> V_40 . V_62 ) {
bool V_206 ;
if ( V_49 -> V_207 == 92001 )
V_206 = true ;
else
V_206 = false ;
if ( ! F_49 ( V_156 , V_89 -> V_40 . V_62 ,
& V_49 -> V_94 , 0x08 , V_157 ,
0x00 , V_206 ) )
goto V_131;
}
break;
case V_208 :
V_89 -> V_40 . V_62 = F_49 ( V_154 ,
& V_209 ,
& V_49 -> V_94 ) ;
if ( V_89 -> V_40 . V_62 ) {
V_49 -> V_85 = V_89 -> V_40 . V_62 -> V_63 . V_210 ;
V_89 -> V_40 . V_62 -> V_63 . V_210 = F_42 ;
}
break;
case V_211 :
V_89 -> V_40 . V_62 = F_49 ( V_154 ,
& V_212 ,
& V_49 -> V_94 ) ;
if ( V_89 -> V_40 . V_62 ) {
V_49 -> V_85 = V_89 -> V_40 . V_62 -> V_63 . V_210 ;
V_89 -> V_40 . V_62 -> V_63 . V_210 = F_44 ;
}
break;
case V_213 :
V_89 -> V_40 . V_62 = F_49 ( V_214 ,
& V_215 ,
& V_49 -> V_94 ) ;
if ( V_89 -> V_40 . V_62 ) {
if ( ! F_49 ( V_216 , V_89 -> V_40 . V_62 ,
& V_49 -> V_94 ,
& V_217 ) )
goto V_131;
}
break;
case V_218 :
V_89 -> V_40 . V_62 = F_49 ( V_214 ,
& V_219 ,
& V_49 -> V_94 ) ;
if ( V_89 -> V_40 . V_62 ) {
struct V_37 * V_38 ;
struct V_92 V_93 = {
. V_94 = & V_49 -> V_94 ,
. V_95 = 0x61 ,
} ;
static struct V_90 V_91 = {
. V_220 = V_221 ,
. V_222 = 64 ,
. V_223 = V_224 ,
} ;
V_38 = F_49 ( V_97 ,
V_89 -> V_40 . V_62 , & V_93 ) ;
if ( V_38 && V_38 -> V_63 . V_225 . V_226 )
V_38 -> V_63 . V_225 . V_226 ( V_38 , & V_91 ) ;
}
break;
case V_227 :
case V_228 :
V_89 -> V_40 . V_62 = F_49 ( V_162 ,
& V_229 ,
& V_49 -> V_94 ) ;
if ( V_89 -> V_40 . V_62 ) {
V_89 -> V_40 . V_62 -> V_63 . V_64 = NULL ;
if ( F_47 ( 0x61 , V_9 ) < 0 )
goto V_131;
}
break;
case V_230 :
case V_231 :
V_89 -> V_40 . V_62 = F_49 ( V_162 ,
& V_229 ,
& V_49 -> V_94 ) ;
if ( V_89 -> V_40 . V_62 ) {
struct V_98 V_93 = {
. V_232 = 0x61 ,
. V_233 = 0 ,
. V_234 = 134 ,
. V_235 = 1 ,
. V_236 = 4560
} ;
V_89 -> V_40 . V_62 -> V_63 . V_64 = NULL ;
if ( F_53 ( V_9 , & V_93 ) < 0 )
goto V_131;
}
break;
case V_237 :
V_9 -> V_79 = 0x00 ;
V_89 -> V_40 . V_62 = F_49 ( V_162 ,
& V_238 ,
& V_49 -> V_94 ) ;
if ( F_47 ( 0x61 , V_9 ) < 0 )
goto V_131;
break;
case V_239 :
V_89 -> V_40 . V_62 = F_49 ( V_214 ,
& V_240 ,
& V_49 -> V_94 ) ;
if ( F_47 ( 0x61 , V_9 ) < 0 )
goto V_131;
break;
case V_241 :
V_89 -> V_40 . V_62 = F_49 ( V_242 ,
& V_243 ,
& V_49 -> V_94 ) ;
if ( V_89 -> V_40 . V_62 ) {
if ( ! F_49 ( V_216 , V_89 -> V_40 . V_62 ,
& V_49 -> V_94 ,
& V_244 ) )
goto V_131;
}
break;
case V_245 :
V_128 = 1 ;
V_9 -> V_46 . V_61 = 2 ;
V_89 -> V_40 . V_62 = F_49 ( V_246 ,
& V_247 ,
& V_9 -> V_49 -> V_94 ) ;
if ( V_89 -> V_40 . V_62 ) {
if ( ! F_49 ( V_156 ,
V_89 -> V_40 . V_62 ,
& V_9 -> V_49 -> V_94 ,
0x08 , V_157 , 0x00 , false ) )
goto V_131;
}
V_127 = F_27 ( & V_9 -> V_46 , 2 ) ;
if ( ! V_127 )
goto V_131;
V_127 -> V_40 . V_62 = F_49 ( V_135 ,
& V_148 ,
& V_9 -> V_49 -> V_94 ) ;
if ( V_127 -> V_40 . V_62 ) {
V_127 -> V_40 . V_62 -> V_158 = 1 ;
if ( ! F_49 ( V_149 ,
V_127 -> V_40 . V_62 ,
& V_9 -> V_49 -> V_94 ,
0x61 , V_150 ) )
goto V_131;
}
break;
case V_248 :
V_89 -> V_40 . V_62 = F_49 ( V_246 ,
& V_247 ,
& V_9 -> V_49 -> V_94 ) ;
if ( V_89 -> V_40 . V_62 ) {
if ( ! F_49 ( V_156 ,
V_89 -> V_40 . V_62 ,
& V_9 -> V_49 -> V_94 ,
0x08 , V_157 , 0x00 , false ) )
goto V_131;
}
break;
case V_249 :
case V_250 :
case V_251 :
V_89 -> V_40 . V_62 = F_49 ( V_252 ,
& V_253 ,
& V_49 -> V_94 ) ;
if ( V_89 -> V_40 . V_62 ) {
if ( ! F_49 ( V_137 , V_89 -> V_40 . V_62 , 0x60 ,
& V_49 -> V_94 , V_254 ) )
goto V_131;
V_49 -> V_85 = V_89 -> V_40 . V_62 -> V_63 . V_210 ;
V_89 -> V_40 . V_62 -> V_63 . V_210 = F_45 ;
} else {
V_89 -> V_40 . V_62 = F_49 ( V_255 ,
& V_256 ,
& V_49 -> V_94 ) ;
if ( V_89 -> V_40 . V_62 ) {
if ( ! F_49 ( V_257 ,
V_89 -> V_40 . V_62 , 0x61 ,
& V_49 -> V_94 ) )
goto V_131;
V_49 -> V_85 = V_89 -> V_40 . V_62 -> V_63 . V_210 ;
V_89 -> V_40 . V_62 -> V_63 . V_210 = F_45 ;
}
}
break;
case V_258 :
V_89 -> V_40 . V_62 = F_49 ( V_246 ,
& V_259 ,
& V_49 -> V_94 ) ;
if ( V_89 -> V_40 . V_62 )
V_89 -> V_40 . V_62 -> V_63 . V_210 = F_45 ;
break;
case V_260 :
V_89 -> V_40 . V_62 = F_49 ( V_261 ,
& V_262 ,
& V_49 -> V_94 ) ;
if ( V_89 -> V_40 . V_62 ) {
F_49 ( V_263 , V_89 -> V_40 . V_62 ,
& V_264 , & V_49 -> V_94 ) ;
V_89 -> V_40 . V_62 -> V_63 . V_210 =
F_45 ;
}
break;
case V_265 :
case V_266 :
case V_267 :
case V_268 :
V_89 -> V_40 . V_62 = F_49 ( V_246 ,
& V_247 ,
& V_49 -> V_94 ) ;
if ( V_89 -> V_40 . V_62 )
V_89 -> V_40 . V_62 -> V_63 . V_210 = F_45 ;
break;
case V_269 :
V_89 -> V_40 . V_62 = F_49 ( V_162 ,
& V_270 ,
& V_49 -> V_94 ) ;
if ( V_89 -> V_40 . V_62 ) {
V_89 -> V_40 . V_62 -> V_63 . V_64 = NULL ;
if ( F_47 ( 0x61 , V_9 ) < 0 )
goto V_131;
}
break;
case V_271 : {
struct V_272 * V_225 = NULL ;
V_89 -> V_40 . V_62 = F_49 ( V_273 ,
& V_274 ,
& V_49 -> V_94 , 0 ) ;
if ( V_89 -> V_40 . V_62 ) {
if ( ! F_49 ( V_275 , V_89 -> V_40 . V_62 ,
& V_276 ,
& V_49 -> V_94 ) )
goto V_131;
V_225 = & V_89 -> V_40 . V_62 -> V_63 . V_225 ;
V_225 -> V_277 = V_278 ;
V_225 -> V_279 = V_280 ;
V_225 -> V_281 = V_282 ;
V_225 -> V_283 = V_284 ;
V_49 -> V_85 =
V_89 -> V_40 . V_62 -> V_63 . V_210 ;
V_89 -> V_40 . V_62 -> V_63 . V_210 =
F_45 ;
}
break;
}
case V_285 :
V_9 -> V_79 = 0x08 ;
F_38 ( V_81 , 0x0101 ) ;
F_37 ( V_81 , 0x01 ) ;
F_72 ( 100 ) ;
F_38 ( V_81 , 0x01 ) ;
F_72 ( 200 ) ;
V_89 -> V_40 . V_62 = F_49 ( V_252 ,
& V_286 ,
& V_9 -> V_49 -> V_94 ) ;
if ( V_89 -> V_40 . V_62 ) {
V_89 -> V_40 . V_62 -> V_63 . V_225 . V_287 =
F_64 ;
V_89 -> V_40 . V_62 -> V_288 =
& V_9 -> V_49 -> V_94 ;
V_89 -> V_40 . V_62 -> V_63 . V_210 =
F_67 ;
V_89 -> V_40 . V_62 -> V_63 . V_289 =
F_66 ;
}
break;
case V_290 :
V_9 -> V_79 = 0x00 ;
V_89 -> V_40 . V_62 = F_49 ( V_291 ,
& V_292 ,
& V_49 -> V_94 ) ;
if ( V_89 -> V_40 . V_62 ) {
V_49 -> V_85 =
V_89 -> V_40 . V_62 -> V_63 . V_210 ;
V_89 -> V_40 . V_62 -> V_63 . V_210 =
F_46 ;
}
break;
default:
F_22 ( L_16 ) ;
break;
}
if ( ( NULL == V_89 -> V_40 . V_62 ) || ( V_127 && NULL == V_127 -> V_40 . V_62 ) ) {
F_22 ( L_17 ) ;
goto V_131;
}
V_89 -> V_40 . V_62 -> V_293 = V_294 ;
V_89 -> V_40 . V_62 -> V_63 . V_295 = F_20 ;
if ( V_127 )
V_127 -> V_40 . V_62 -> V_63 . V_295 = F_20 ;
F_73 ( V_49 , V_49 , V_296 , 0 ) ;
V_129 = F_74 ( & V_9 -> V_46 , V_297 , V_9 ,
& V_9 -> V_23 -> V_9 , NULL , V_298 ,
V_128 ) ;
if ( V_129 )
goto V_131;
return V_129 ;
V_131:
V_49 -> V_132 = NULL ;
F_63 ( & V_9 -> V_46 ) ;
return V_129 ;
}
static int F_75 ( struct V_42 * V_43 )
{
struct V_55 * V_49 = V_43 -> V_49 ;
int V_299 = 0 ;
F_36 ( 1 , L_18 , V_47 ) ;
switch ( V_49 -> V_133 ) {
case V_147 :
F_38 ( V_81 , 0x00000080 ) ;
F_30 ( 1000 ) ;
F_37 ( V_81 , 0x00000080 ) ;
F_30 ( 50 ) ;
F_38 ( V_81 , 0x00000080 ) ;
F_30 ( 1000 ) ;
F_37 ( V_81 , 0x00000004 ) ;
F_30 ( 1000 ) ;
break;
case V_153 :
case V_245 :
F_38 ( V_81 , 0x00000080 ) ;
F_30 ( 1000 ) ;
F_37 ( V_81 , 0x00000080 ) ;
F_30 ( 50 ) ;
F_38 ( V_81 , 0x00000080 ) ;
F_30 ( 1000 ) ;
switch ( V_49 -> V_60 -> V_46 . V_52 ) {
case 1 :
F_38 ( V_81 , 0x00000004 ) ;
F_43 ( V_100 , 1 ) ;
V_49 -> V_60 -> V_79 = 0x02 ;
break;
case 2 :
F_43 ( V_100 , 0 ) ;
F_37 ( V_81 , 0x00000004 ) ;
V_49 -> V_60 -> V_79 = 0x0c ;
break;
}
F_30 ( 1000 ) ;
break;
case V_231 :
F_43 ( V_300 , 0x0101 ) ;
break;
default:
V_299 = - V_105 ;
}
return V_299 ;
}
static int F_76 ( struct V_42 * V_43 )
{
struct V_55 * V_49 = V_43 -> V_49 ;
int V_299 = 0 ;
F_36 ( 1 , L_18 , V_47 ) ;
switch ( V_49 -> V_133 ) {
case V_147 :
break;
case V_153 :
case V_245 :
break;
default:
V_299 = - V_105 ;
}
return V_299 ;
}
static int F_77 ( struct V_42 * V_43 )
{
struct V_55 * V_49 = V_43 -> V_49 ;
struct V_8 * V_9 = V_43 -> V_49 -> V_60 ;
int V_299 ;
struct V_59 * V_38 ;
int V_101 ;
F_36 ( 1 , L_18 , V_47 ) ;
F_36 ( 1 , L_19 ,
V_49 -> V_133 ,
V_49 -> V_301 ,
V_49 -> V_302 ,
V_49 -> V_303 ) ;
V_299 = - V_105 ;
if ( ! ( V_49 -> V_103 . V_304 & V_51 ) )
goto V_305;
V_299 = F_78 ( V_9 ) ;
if ( V_299 != 0 )
goto V_305;
F_52 ( L_20 ) ;
V_9 -> V_79 = 0x0c ;
V_299 = F_59 ( V_9 ) ;
if ( V_299 )
goto V_305;
for ( V_101 = 1 ; V_101 <= V_49 -> V_103 . V_104 ; V_101 ++ ) {
struct V_1 * V_2 ;
V_38 = F_27 ( & V_49 -> V_60 -> V_46 , V_101 ) ;
if ( ! V_38 ) {
F_22 ( L_21 ,
V_47 , V_101 ) ;
V_299 = - V_105 ;
goto V_306;
}
V_2 = & V_38 -> V_40 . V_307 ;
V_2 -> type = V_308 ;
V_2 -> V_309 = V_310 | V_311 | V_312 | V_313 ;
V_2 -> V_314 = V_315 ;
V_2 -> V_316 = 2 ;
V_2 -> V_10 = V_9 ;
V_2 -> V_317 = sizeof( struct V_18 ) ;
V_2 -> V_63 = & V_318 ;
V_2 -> V_319 = & V_320 ;
V_2 -> V_321 = V_322 ;
V_2 -> V_50 = & V_49 -> V_50 ;
V_2 -> V_9 = & V_9 -> V_23 -> V_9 ;
V_299 = F_79 ( V_2 ) ;
if ( V_299 < 0 )
goto V_306;
V_38 -> V_40 . V_301 = V_9 -> V_49 -> V_301 ;
}
V_299 = F_70 ( V_9 ) ;
if ( V_299 )
F_22 ( L_22 , V_299 ) ;
return V_299 ;
V_306:
F_63 ( & V_49 -> V_60 -> V_46 ) ;
V_305:
return V_299 ;
}
static int F_80 ( struct V_42 * V_43 )
{
struct V_55 * V_49 = V_43 -> V_49 ;
struct V_8 * V_9 = V_43 -> V_49 -> V_60 ;
F_36 ( 1 , L_18 , V_47 ) ;
F_81 ( & V_9 -> V_46 ) ;
F_82 ( V_9 ) ;
V_49 -> V_132 = NULL ;
return 0 ;
}
static int T_3 F_83 ( void )
{
F_52 ( L_23 , V_323 ) ;
return F_84 ( & V_324 ) ;
}
static void T_4 F_85 ( void )
{
F_86 ( & V_324 ) ;
}
