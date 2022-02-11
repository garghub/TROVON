static int F_1 ( struct V_1 * V_2 ,
unsigned int * V_3 , unsigned int * V_4 ,
unsigned int V_5 [] , void * V_6 [] )
{
struct V_7 * V_8 = V_2 -> V_9 ;
* V_4 = 1 ;
V_8 -> V_10 = 188 * 4 ;
V_8 -> V_11 = V_12 ;
V_5 [ 0 ] = V_8 -> V_10 * V_8 -> V_11 ;
V_6 [ 0 ] = V_8 -> V_13 ;
* V_3 = V_12 ;
return 0 ;
}
static int F_2 ( struct V_14 * V_15 )
{
struct V_16 * V_17 = F_3 ( V_15 ) ;
struct V_7 * V_8 = V_15 -> V_1 -> V_9 ;
struct V_18 * V_19 = F_4 ( V_17 , struct V_18 , V_15 ) ;
return F_5 ( V_15 -> V_1 , V_8 , V_19 ) ;
}
static void F_6 ( struct V_14 * V_15 )
{
struct V_16 * V_17 = F_3 ( V_15 ) ;
struct V_7 * V_8 = V_15 -> V_1 -> V_9 ;
struct V_18 * V_19 = F_4 ( V_17 , struct V_18 , V_15 ) ;
struct V_20 * V_21 = & V_19 -> V_21 ;
if ( V_21 -> V_22 )
F_7 ( V_8 -> V_23 , V_21 -> V_24 , V_21 -> V_22 , V_21 -> V_25 ) ;
memset ( V_21 , 0 , sizeof( * V_21 ) ) ;
}
static void F_8 ( struct V_14 * V_15 )
{
struct V_16 * V_17 = F_3 ( V_15 ) ;
struct V_7 * V_8 = V_15 -> V_1 -> V_9 ;
struct V_18 * V_19 = F_4 ( V_17 , struct V_18 , V_15 ) ;
F_9 ( V_8 , V_19 ) ;
}
static int F_10 ( struct V_1 * V_2 , unsigned int V_26 )
{
struct V_7 * V_8 = V_2 -> V_9 ;
struct V_27 * V_28 = & V_8 -> V_29 ;
struct V_18 * V_19 ;
V_19 = F_11 ( V_28 -> V_30 . V_31 , struct V_18 , V_32 ) ;
F_12 ( V_8 , V_28 , V_19 ) ;
return 0 ;
}
static void F_13 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = V_2 -> V_9 ;
struct V_27 * V_28 = & V_8 -> V_29 ;
unsigned long V_33 ;
F_14 ( V_8 ) ;
F_15 ( & V_8 -> V_34 , V_33 ) ;
while ( ! F_16 ( & V_28 -> V_30 ) ) {
struct V_18 * V_19 = F_11 ( V_28 -> V_30 . V_31 ,
struct V_18 , V_32 ) ;
F_17 ( & V_19 -> V_32 ) ;
F_18 ( & V_19 -> V_15 . V_35 , V_36 ) ;
}
F_19 ( & V_8 -> V_34 , V_33 ) ;
}
static int F_20 ( struct V_37 * V_38 , int V_39 )
{
struct V_7 * V_8 = V_38 -> V_40 -> V_41 ;
struct V_42 * V_43 = NULL ;
int V_44 = 0 ;
int V_45 ;
V_45 = F_21 ( & V_8 -> V_46 , V_38 ) ;
if ( ! V_45 ) {
F_22 ( V_47 L_1 , V_48 ) ;
return - V_49 ;
}
F_23 ( & V_8 -> V_50 -> V_51 ) ;
V_43 = F_24 ( V_8 , V_52 ) ;
if ( V_43 ) {
if ( V_39 ) {
V_8 -> V_46 . V_53 = V_45 ;
V_44 = V_43 -> V_54 ( V_43 ) ;
} else {
V_44 = V_43 -> V_55 ( V_43 ) ;
V_8 -> V_46 . V_53 = 0 ;
}
}
F_25 ( & V_8 -> V_50 -> V_51 ) ;
return V_44 ;
}
static void F_26 ( struct V_56 * V_50 , int V_57 )
{
struct V_58 * V_59 ;
struct V_60 * V_38 ;
if ( ! V_50 -> V_61 )
return;
V_59 = & V_50 -> V_61 -> V_46 ;
if ( ! V_59 )
return;
if ( V_59 -> V_62 <= 1 )
V_38 = F_27 ( V_59 , 1 ) ;
else
V_38 = F_27 ( V_59 , V_59 -> V_62 ) ;
if ( V_38 && V_38 -> V_40 . V_63 && V_38 -> V_40 . V_63 -> V_64 . V_65 )
V_38 -> V_40 . V_63 -> V_64 . V_65 ( V_38 -> V_40 . V_63 , V_57 ) ;
}
static int F_28 ( struct V_37 * V_38 )
{
static const T_1 V_66 [] = { V_67 , 0x38 , 0x39 } ;
static const T_1 V_68 [] = { V_69 , 0x80 } ;
static const T_1 V_70 [] = { V_71 , 0x40 } ;
static const T_1 V_72 [] = { V_73 , 0x24 , 0x20 } ;
static const T_1 V_74 [] = { V_75 , 0x33 } ;
static const T_1 V_76 [] = { V_77 , 0x32 } ;
F_29 ( V_38 , V_66 , sizeof( V_66 ) ) ;
F_30 ( 200 ) ;
F_29 ( V_38 , V_68 , sizeof( V_68 ) ) ;
F_29 ( V_38 , V_70 , sizeof( V_70 ) ) ;
F_29 ( V_38 , V_72 , sizeof( V_72 ) ) ;
F_29 ( V_38 , V_74 , sizeof( V_74 ) ) ;
F_29 ( V_38 , V_76 , sizeof( V_76 ) ) ;
return 0 ;
}
static int F_31 ( struct V_37 * V_38 )
{
static const T_1 V_66 [] = { V_67 , 0x38 , 0x38 } ;
static const T_1 V_68 [] = { V_69 , 0x80 } ;
static const T_1 V_70 [] = { V_71 , 0x40 } ;
static const T_1 V_72 [] = { V_73 , 0x28 , 0x20 } ;
static const T_1 V_74 [] = { V_75 , 0x33 } ;
static const T_1 V_76 [] = { V_77 , 0x32 } ;
F_29 ( V_38 , V_66 , sizeof( V_66 ) ) ;
F_30 ( 200 ) ;
F_29 ( V_38 , V_68 , sizeof( V_68 ) ) ;
F_29 ( V_38 , V_70 , sizeof( V_70 ) ) ;
F_29 ( V_38 , V_72 , sizeof( V_72 ) ) ;
F_29 ( V_38 , V_74 , sizeof( V_74 ) ) ;
F_29 ( V_38 , V_76 , sizeof( V_76 ) ) ;
return 0 ;
}
static int F_32 ( struct V_37 * V_38 )
{
static const T_1 V_66 [] = { 0x89 , 0x38 , 0x39 } ;
static const T_1 V_68 [] = { 0x50 , 0x80 } ;
static const T_1 V_70 [] = { 0x8E , 0x40 } ;
static const T_1 V_72 [] = { 0x67 , 0x10 , 0x23 , 0x00 , 0xFF , 0xFF ,
0x00 , 0xFF , 0x00 , 0x40 , 0x40 } ;
static const T_1 V_78 [] = { 0xB5 , 0x7A } ;
static const T_1 V_76 [] = { 0x75 , 0x32 } ;
F_29 ( V_38 , V_66 , sizeof( V_66 ) ) ;
F_30 ( 2000 ) ;
F_29 ( V_38 , V_68 , sizeof( V_68 ) ) ;
F_29 ( V_38 , V_70 , sizeof( V_70 ) ) ;
F_29 ( V_38 , V_72 , sizeof( V_72 ) ) ;
F_30 ( 2000 ) ;
F_29 ( V_38 , V_78 , sizeof( V_78 ) ) ;
F_29 ( V_38 , V_76 , sizeof( V_76 ) ) ;
return 0 ;
}
static int F_33 ( struct V_37 * V_38 )
{
static const T_1 V_66 [] = { 0x89 , 0x38 , 0x38 } ;
static const T_1 V_68 [] = { 0x50 , 0x80 } ;
static const T_1 V_70 [] = { 0x8E , 0x40 } ;
static const T_1 V_72 [] = { 0x67 , 0x10 , 0x20 , 0x00 , 0xFF , 0xFF ,
0x00 , 0xFF , 0x00 , 0x40 , 0x40 } ;
static const T_1 V_78 [] = { 0xB5 , 0x7A } ;
static const T_1 V_76 [] = { 0x75 , 0x32 } ;
F_29 ( V_38 , V_66 , sizeof( V_66 ) ) ;
F_30 ( 2000 ) ;
F_29 ( V_38 , V_68 , sizeof( V_68 ) ) ;
F_29 ( V_38 , V_70 , sizeof( V_70 ) ) ;
F_29 ( V_38 , V_72 , sizeof( V_72 ) ) ;
F_30 ( 2000 ) ;
F_29 ( V_38 , V_78 , sizeof( V_78 ) ) ;
F_29 ( V_38 , V_76 , sizeof( V_76 ) ) ;
return 0 ;
}
static int F_34 ( struct V_37 * V_38 , int V_79 )
{
struct V_7 * V_8 = V_38 -> V_40 -> V_41 ;
V_8 -> V_80 = V_79 ? 0x04 : 0x00 ;
return 0 ;
}
static int F_35 ( struct V_37 * V_38 , int V_81 )
{
struct V_7 * V_8 = V_38 -> V_40 -> V_41 ;
struct V_56 * V_50 = V_8 -> V_50 ;
F_36 ( 1 , L_2 , V_48 , V_81 ) ;
if ( V_81 == 0 )
F_37 ( V_82 , 8 ) ;
else
F_38 ( V_82 , 8 ) ;
return 0 ;
}
static int F_39 ( struct V_37 * V_38 , int V_79 )
{
struct V_7 * V_8 = V_38 -> V_40 -> V_41 ;
if ( V_79 )
V_8 -> V_80 |= 0x04 ;
else
V_8 -> V_80 &= ~ 0x04 ;
return 0 ;
}
static int F_40 ( struct V_37 * V_38 , int V_79 )
{
struct V_7 * V_8 = V_38 -> V_40 -> V_41 ;
V_8 -> V_80 = V_79 ? 0x04 : 0x00 ;
return 0 ;
}
static int F_41 ( struct V_37 * V_38 ,
int V_79 )
{
struct V_7 * V_8 = V_38 -> V_40 -> V_41 ;
V_8 -> V_80 = 0x02 ;
return 0 ;
}
static int F_42 ( struct V_37 * V_38 ,
enum V_83 V_84 )
{
struct V_7 * V_8 = V_38 -> V_40 -> V_41 ;
struct V_56 * V_50 = V_8 -> V_50 ;
if ( V_84 == V_85 )
F_43 ( V_82 , 0x000006fb ) ;
else
F_43 ( V_82 , 0x000006f9 ) ;
if ( V_50 -> V_86 )
return V_50 -> V_86 ( V_38 , V_84 ) ;
return 0 ;
}
static int F_44 ( struct V_37 * V_38 ,
enum V_83 V_84 )
{
struct V_7 * V_8 = V_38 -> V_40 -> V_41 ;
struct V_56 * V_50 = V_8 -> V_50 ;
if ( V_84 == V_85 ) {
F_36 ( 1 , L_3 ) ;
F_43 ( V_82 , 0x0000efff ) ;
}
if ( V_50 -> V_86 )
return V_50 -> V_86 ( V_38 , V_84 ) ;
return 0 ;
}
static int F_45 ( struct V_37 * V_38 ,
enum V_83 V_84 )
{
struct V_7 * V_8 = V_38 -> V_40 -> V_41 ;
struct V_56 * V_50 = V_8 -> V_50 ;
F_38 ( V_82 , 0x6040 ) ;
switch ( V_84 ) {
case V_87 :
F_37 ( V_82 , 0x20 ) ;
break;
case V_88 :
F_38 ( V_82 , 0x20 ) ;
break;
case V_85 :
F_37 ( V_82 , 0x20 ) ;
break;
}
if ( V_50 -> V_86 )
return V_50 -> V_86 ( V_38 , V_84 ) ;
return 0 ;
}
static int F_46 ( struct V_37 * V_38 ,
enum V_83 V_84 )
{
struct V_7 * V_8 = V_38 -> V_40 -> V_41 ;
struct V_56 * V_50 = V_8 -> V_50 ;
switch ( V_84 ) {
case V_87 :
F_36 ( 1 , L_4 ) ;
F_43 ( V_82 , 0x00001220 ) ;
break;
case V_88 :
F_36 ( 1 , L_5 ) ;
F_43 ( V_82 , 0x00001222 ) ;
break;
case V_85 :
F_36 ( 1 , L_3 ) ;
F_43 ( V_82 , 0x00001230 ) ;
break;
}
if ( V_50 -> V_86 )
return V_50 -> V_86 ( V_38 , V_84 ) ;
return 0 ;
}
static int F_47 ( T_1 V_89 , struct V_7 * V_8 )
{
struct V_37 * V_38 ;
struct V_60 * V_90 = NULL ;
struct V_91 V_92 ;
struct V_93 V_94 = {
. V_95 = & V_8 -> V_50 -> V_95 ,
. V_96 = V_89 ,
. V_97 = & V_92 ,
} ;
V_90 = F_27 ( & V_8 -> V_46 , 1 ) ;
if ( ! V_90 )
return - V_49 ;
if ( ! V_90 -> V_40 . V_63 ) {
F_22 ( V_47 L_6
L_7 ,
V_8 -> V_50 -> V_98 ) ;
return - V_49 ;
}
F_48 ( V_8 -> V_50 , & V_92 ) ;
V_38 = F_49 ( V_99 , V_90 -> V_40 . V_63 , & V_94 ) ;
if ( ! V_38 ) {
F_22 ( V_47 L_8 ,
V_8 -> V_50 -> V_98 ) ;
F_50 ( V_90 -> V_40 . V_63 ) ;
F_51 ( V_90 -> V_40 . V_63 ) ;
V_90 -> V_40 . V_63 = NULL ;
return - V_49 ;
}
F_22 ( V_100 L_9 ,
V_8 -> V_50 -> V_98 ) ;
return 0 ;
}
static int F_52 ( struct V_7 * V_8 , struct V_101 * V_94 )
{
struct V_37 * V_38 ;
struct V_60 * V_90 = NULL ;
V_90 = F_27 ( & V_8 -> V_46 , 1 ) ;
if ( ! V_90 )
return - V_49 ;
if ( ! V_90 -> V_40 . V_63 ) {
F_22 ( V_47 L_6
L_10 ,
V_8 -> V_50 -> V_98 ) ;
return - V_49 ;
}
V_38 = F_49 ( V_102 , V_90 -> V_40 . V_63 , & V_8 -> V_50 -> V_95 ,
V_94 ) ;
if ( ! V_38 ) {
F_22 ( V_47 L_11 ,
V_8 -> V_50 -> V_98 ) ;
F_50 ( V_90 -> V_40 . V_63 ) ;
F_51 ( V_90 -> V_40 . V_63 ) ;
V_90 -> V_40 . V_63 = NULL ;
return - V_49 ;
}
F_22 ( V_100 L_12 , V_8 -> V_50 -> V_98 ) ;
return 0 ;
}
static int F_53 ( struct V_37 * V_38 ,
int V_79 )
{
struct V_7 * V_8 = V_38 -> V_40 -> V_41 ;
V_8 -> V_80 = 0x2 ;
return 0 ;
}
static int F_54 ( struct V_37 * V_38 ,
int V_79 )
{
struct V_7 * V_8 = V_38 -> V_40 -> V_41 ;
V_8 -> V_80 = 0 ;
return 0 ;
}
static int F_55 ( struct V_37 * V_38 )
{
struct V_7 * V_8 = V_38 -> V_40 -> V_41 ;
struct V_56 * V_50 = V_8 -> V_50 ;
F_43 ( V_103 , 0 ) ;
F_56 ( 10 ) ;
F_43 ( V_103 , 1 ) ;
F_56 ( 10 ) ;
return 0 ;
}
static int F_57 ( struct V_37 * V_38 ,
int V_79 )
{
struct V_7 * V_8 = V_38 -> V_40 -> V_41 ;
V_8 -> V_80 = 4 ;
return 0 ;
}
static int F_58 ( struct V_7 * V_8 )
{
struct V_56 * V_50 = V_8 -> V_50 ;
struct V_60 * V_38 = NULL ;
int V_104 ;
F_59 ( & V_8 -> V_46 . V_51 ) ;
F_60 ( & V_8 -> V_46 . V_105 ) ;
if ( ! V_50 -> V_106 . V_107 )
return - V_108 ;
F_22 ( V_100 L_13 , V_48 ,
V_50 -> V_106 . V_107 ) ;
for ( V_104 = 1 ; V_104 <= V_50 -> V_106 . V_107 ; V_104 ++ ) {
V_38 = F_61 ( & V_8 -> V_46 , V_104 ) ;
if ( ! V_38 ) {
F_22 ( V_47 L_14 , V_48 ) ;
F_62 ( & V_8 -> V_46 ) ;
return - V_109 ;
}
}
return 0 ;
}
static int F_63 ( struct V_37 * V_38 )
{
struct V_110 * V_111 = & V_38 -> V_112 ;
struct V_7 * V_8 = V_38 -> V_40 -> V_41 ;
T_1 V_19 [ 4 ] ;
T_2 div ;
struct V_113 V_114 = {
. V_89 = 0x61 ,
. V_33 = 0 ,
. V_19 = V_19 ,
. V_115 = sizeof( V_19 ) } ;
div = V_111 -> V_116 / 125 ;
V_19 [ 0 ] = ( div >> 8 ) & 0x7f ;
V_19 [ 1 ] = div & 0xff ;
V_19 [ 2 ] = 0x84 ;
V_19 [ 3 ] = 0x00 ;
if ( V_111 -> V_116 < 1500000 )
V_19 [ 3 ] |= 0x10 ;
if ( V_38 -> V_64 . V_65 )
V_38 -> V_64 . V_65 ( V_38 , 1 ) ;
if ( F_64 ( & V_8 -> V_50 -> V_95 , & V_114 , 1 ) != 1 )
return - V_117 ;
return 0 ;
}
static int F_65 ( struct V_37 * V_38 ,
enum V_118 V_119 )
{
struct V_7 * V_8 = V_38 -> V_40 -> V_41 ;
struct V_56 * V_50 = V_8 -> V_50 ;
F_38 ( V_82 , 0x0800 ) ;
switch ( V_119 ) {
case V_120 :
F_38 ( V_82 , 0x08 ) ;
break;
case V_121 :
F_37 ( V_82 , 0x08 ) ;
break;
default:
return - V_49 ;
}
return 0 ;
}
static int F_66 ( struct V_37 * V_38 ,
enum V_83 V_84 )
{
struct V_7 * V_8 = V_38 -> V_40 -> V_41 ;
struct V_56 * V_50 = V_8 -> V_50 ;
T_1 V_122 ;
struct V_113 V_114 = {
. V_89 = 8 ,
. V_33 = 0 ,
. V_19 = & V_122 ,
. V_115 = sizeof( V_122 ) } ;
F_38 ( V_82 , 0x8000 ) ;
switch ( V_84 ) {
case V_85 :
break;
case V_87 :
V_122 = V_123 | V_124 ;
F_37 ( V_82 , 0x80 ) ;
break;
case V_88 :
V_122 = V_123 | V_124 | V_125 ;
F_37 ( V_82 , 0x80 ) ;
break;
default:
return - V_49 ;
}
return ( F_64 ( & V_8 -> V_50 -> V_95 , & V_114 , 1 ) == 1 ) ? 0 : - V_117 ;
}
static int F_67 ( struct V_37 * V_38 ,
T_2 V_126 , T_2 V_127 )
{
T_1 V_128 = 0 ;
T_1 V_129 = 0 ;
if ( V_126 < 1500000 ) {
V_128 = 0xb7 ;
V_129 = 0x47 ;
} else if ( V_126 < 3000000 ) {
V_128 = 0xb7 ;
V_129 = 0x4b ;
} else if ( V_126 < 7000000 ) {
V_128 = 0xb7 ;
V_129 = 0x4f ;
} else if ( V_126 < 14000000 ) {
V_128 = 0xb7 ;
V_129 = 0x53 ;
} else if ( V_126 < 30000000 ) {
V_128 = 0xb6 ;
V_129 = 0x53 ;
} else if ( V_126 < 45000000 ) {
V_128 = 0xb4 ;
V_129 = 0x51 ;
}
F_68 ( V_38 , 0x13 , V_128 ) ;
F_68 ( V_38 , 0x14 , V_129 ) ;
F_68 ( V_38 , 0x1f , ( V_127 >> 16 ) & 0xff ) ;
F_68 ( V_38 , 0x20 , ( V_127 >> 8 ) & 0xff ) ;
F_68 ( V_38 , 0x21 , V_127 & 0xf0 ) ;
return 0 ;
}
static int F_69 ( struct V_7 * V_8 )
{
struct V_56 * V_50 = V_8 -> V_50 ;
struct V_60 * V_90 , * V_130 = NULL ;
int V_131 = 0 ;
int V_132 = - V_49 ;
if ( 0 != V_50 -> V_133 ) {
F_22 ( V_47 L_15 , V_50 -> V_98 ) ;
goto V_134;
}
V_90 = F_27 ( & V_8 -> V_46 , 1 ) ;
if ( ! V_90 )
goto V_134;
V_8 -> V_46 . V_62 = 0 ;
V_50 -> V_135 = F_26 ;
switch ( V_50 -> V_136 ) {
case V_137 :
V_90 -> V_40 . V_63 = F_49 ( V_138 ,
& V_139 ,
& V_50 -> V_95 ) ;
if ( V_90 -> V_40 . V_63 != NULL ) {
if ( ! F_49 ( V_140 , V_90 -> V_40 . V_63 ,
0x61 , & V_50 -> V_95 ,
V_141 ) )
goto V_134;
}
break;
case V_142 :
case V_143 :
case V_144 :
case V_145 :
V_90 -> V_40 . V_63 = F_49 ( V_138 ,
& V_139 ,
& V_50 -> V_95 ) ;
if ( V_90 -> V_40 . V_63 != NULL ) {
if ( ! F_49 ( V_140 , V_90 -> V_40 . V_63 ,
0x60 , & V_50 -> V_95 ,
V_146 ) )
goto V_134;
}
break;
case V_147 :
case V_148 :
case V_149 :
case V_150 :
V_90 -> V_40 . V_63 = F_49 ( V_138 ,
& V_151 ,
& V_50 -> V_95 ) ;
if ( V_90 -> V_40 . V_63 != NULL ) {
if ( ! F_49 ( V_152 , V_90 -> V_40 . V_63 ,
& V_50 -> V_95 , 0x61 ,
V_153 ) )
goto V_134;
}
break;
case V_154 :
V_90 -> V_40 . V_63 = F_49 ( V_138 ,
& V_151 ,
& V_50 -> V_95 ) ;
if ( V_90 -> V_40 . V_63 != NULL ) {
if ( ! F_49 ( V_152 , V_90 -> V_40 . V_63 ,
& V_50 -> V_95 , 0x61 ,
V_155 ) )
goto V_134;
}
break;
case V_156 :
V_131 = 1 ;
V_8 -> V_46 . V_62 = 2 ;
V_90 -> V_40 . V_63 = F_49 ( V_157 ,
& V_158 ,
& V_8 -> V_50 -> V_95 ) ;
if ( V_90 -> V_40 . V_63 ) {
if ( ! F_49 ( V_159 ,
V_90 -> V_40 . V_63 ,
& V_8 -> V_50 -> V_95 ,
0x08 , V_160 , 0x00 , false ) )
goto V_134;
}
V_130 = F_27 ( & V_8 -> V_46 , 2 ) ;
if ( ! V_130 )
goto V_134;
V_130 -> V_40 . V_63 = F_49 ( V_138 ,
& V_151 ,
& V_8 -> V_50 -> V_95 ) ;
if ( V_130 -> V_40 . V_63 ) {
V_130 -> V_40 . V_63 -> V_161 = 1 ;
if ( ! F_49 ( V_152 ,
V_130 -> V_40 . V_63 ,
& V_8 -> V_50 -> V_95 ,
0x61 , V_153 ) )
goto V_134;
}
break;
case V_162 :
V_90 -> V_40 . V_63 = F_49 ( V_163 ,
& V_164 ,
& V_50 -> V_95 ) ;
if ( V_90 -> V_40 . V_63 != NULL ) {
if ( ! F_49 ( V_140 , V_90 -> V_40 . V_63 ,
0x60 , NULL , V_146 ) )
goto V_134;
break;
}
V_90 -> V_40 . V_63 = F_49 ( V_165 ,
& V_166 ,
& V_50 -> V_95 ) ;
if ( V_90 -> V_40 . V_63 != NULL ) {
if ( ! F_49 ( V_140 , V_90 -> V_40 . V_63 ,
0x60 , NULL , V_146 ) )
goto V_134;
}
break;
case V_167 :
V_90 -> V_40 . V_63 = F_49 ( V_163 ,
& V_168 ,
& V_50 -> V_95 ) ;
if ( V_90 -> V_40 . V_63 != NULL ) {
if ( ! F_49 ( V_140 , V_90 -> V_40 . V_63 ,
0x61 , NULL , V_146 ) )
goto V_134;
break;
}
V_90 -> V_40 . V_63 = F_49 ( V_165 ,
& V_166 ,
& V_50 -> V_95 ) ;
if ( V_90 -> V_40 . V_63 != NULL ) {
if ( ! F_49 ( V_140 , V_90 -> V_40 . V_63 ,
0x61 , NULL , V_146 ) )
goto V_134;
}
break;
case V_169 :
V_90 -> V_40 . V_63 = F_49 ( V_163 ,
& V_164 ,
& V_50 -> V_95 ) ;
if ( V_90 -> V_40 . V_63 != NULL ) {
if ( ! F_49 ( V_140 , V_90 -> V_40 . V_63 ,
0x61 , NULL , V_170 ) )
goto V_134;
}
break;
case V_171 :
case V_172 :
case V_173 :
V_90 -> V_40 . V_63 = F_49 ( V_163 ,
& V_174 ,
& V_50 -> V_95 ) ;
if ( V_90 -> V_40 . V_63 != NULL ) {
if ( ! F_49 ( V_140 , V_90 -> V_40 . V_63 ,
0x61 , NULL , V_175 ) )
goto V_134;
}
break;
case V_176 :
#if F_70 ( V_177 )
V_90 -> V_40 . V_63 = F_49 ( V_163 , & V_178 ,
& V_8 -> V_179 -> V_180 ) ;
if ( V_90 -> V_40 . V_63 != NULL ) {
if ( ! F_49 ( V_152 , V_90 -> V_40 . V_63 ,
& V_50 -> V_95 , 0x61 ,
V_153 ) )
goto V_134;
}
#else
F_22 ( V_47 L_16 ,
V_50 -> V_98 ) ;
#endif
break;
case V_181 :
V_90 -> V_40 . V_63 = F_49 ( V_165 ,
& V_182 ,
& V_50 -> V_95 ) ;
if ( V_90 -> V_40 . V_63 != NULL ) {
if ( ! F_49 ( V_152 , V_90 -> V_40 . V_63 ,
& V_50 -> V_95 , 0x61 ,
V_183 ) )
goto V_134;
}
break;
case V_184 :
V_90 -> V_40 . V_63 = F_49 ( V_165 ,
& V_185 ,
& V_50 -> V_95 ) ;
if ( V_90 -> V_40 . V_63 == NULL )
V_90 -> V_40 . V_63 = F_49 ( V_163 ,
& V_186 ,
& V_50 -> V_95 ) ;
if ( V_90 -> V_40 . V_63 )
V_90 -> V_40 . V_63 -> V_64 . V_65 = NULL ;
if ( F_47 ( 0x61 , V_8 ) < 0 )
goto V_134;
break;
case V_187 :
V_90 -> V_40 . V_63 = F_49 ( V_188 , & V_189 ,
& V_50 -> V_95 ) ;
if ( V_90 -> V_40 . V_63 != NULL ) {
if ( ! F_49 ( V_152 , V_90 -> V_40 . V_63 ,
& V_50 -> V_95 , 0x61 ,
V_190 ) )
goto V_134;
}
break;
case V_191 :
V_8 -> V_80 = 0x08 ;
F_37 ( V_82 , 1 ) ;
F_71 ( 100 ) ;
F_38 ( V_82 , 1 ) ;
F_71 ( 200 ) ;
V_192 . V_193 = F_35 ;
V_90 -> V_40 . V_63 = F_49 ( V_194 ,
& V_192 ,
& V_50 -> V_95 ) ;
if ( V_90 -> V_40 . V_63 != NULL ) {
if ( ! F_49 ( V_152 , V_90 -> V_40 . V_63 ,
& V_50 -> V_95 , 0x61 ,
V_195 ) )
goto V_134;
}
break;
case V_196 :
V_8 -> V_80 = 0x08 ;
F_37 ( V_82 , 1 ) ;
F_71 ( 100 ) ;
F_38 ( V_82 , 9 ) ;
F_71 ( 200 ) ;
V_90 -> V_40 . V_63 = F_49 ( V_194 ,
& V_192 ,
& V_50 -> V_95 ) ;
if ( V_90 -> V_40 . V_63 != NULL ) {
if ( ! F_49 ( V_152 , V_90 -> V_40 . V_63 ,
& V_50 -> V_95 , 0x61 ,
V_190 ) )
goto V_134;
}
break;
case V_197 :
V_8 -> V_80 = 0x08 ;
F_37 ( V_82 , 1 ) ;
F_71 ( 100 ) ;
F_38 ( V_82 , 1 ) ;
F_71 ( 200 ) ;
V_90 -> V_40 . V_63 = F_49 ( V_194 ,
& V_198 ,
& V_50 -> V_95 ) ;
if ( V_90 -> V_40 . V_63 != NULL ) {
if ( ! F_49 ( V_152 , V_90 -> V_40 . V_63 ,
& V_50 -> V_95 , 0x61 ,
V_199 ) )
goto V_134;
if ( ! F_49 ( V_200 , V_90 -> V_40 . V_63 ,
& V_50 -> V_95 , 0x43 ) )
goto V_134;
}
break;
case V_201 :
V_8 -> V_80 = 0x08 ;
F_37 ( V_82 , 1 ) ;
F_71 ( 100 ) ;
F_38 ( V_82 , 1 ) ;
F_71 ( 200 ) ;
V_90 -> V_40 . V_63 = F_49 ( V_194 ,
& V_202 ,
& V_50 -> V_95 ) ;
if ( V_90 -> V_40 . V_63 != NULL ) {
if ( ! F_49 ( V_152 , V_90 -> V_40 . V_63 ,
& V_50 -> V_95 , 0x61 ,
V_199 ) )
goto V_134;
if ( ! F_49 ( V_200 , V_90 -> V_40 . V_63 ,
& V_50 -> V_95 , 0x43 ) )
goto V_134;
}
break;
case V_203 :
V_90 -> V_40 . V_63 = F_49 ( V_204 ,
& V_205 ,
& V_50 -> V_95 ) ;
if ( V_90 -> V_40 . V_63 != NULL ) {
if ( ! F_49 ( V_152 , V_90 -> V_40 . V_63 ,
& V_50 -> V_95 , 0x61 ,
V_206 ) )
goto V_134;
}
break;
case V_207 :
case V_208 :
V_90 -> V_40 . V_63 = F_49 ( V_157 ,
& V_158 ,
& V_50 -> V_95 ) ;
if ( V_90 -> V_40 . V_63 ) {
bool V_209 ;
if ( V_50 -> V_210 == 92001 )
V_209 = true ;
else
V_209 = false ;
if ( ! F_49 ( V_159 , V_90 -> V_40 . V_63 ,
& V_50 -> V_95 , 0x08 , V_160 , 0x00 ,
V_209 ) )
goto V_134;
}
break;
case V_211 :
V_90 -> V_40 . V_63 = F_49 ( V_157 ,
& V_212 ,
& V_50 -> V_95 ) ;
if ( V_90 -> V_40 . V_63 ) {
V_50 -> V_86 = V_90 -> V_40 . V_63 -> V_64 . V_213 ;
V_90 -> V_40 . V_63 -> V_64 . V_213 = F_42 ;
}
break;
case V_214 :
V_90 -> V_40 . V_63 = F_49 ( V_157 ,
& V_215 ,
& V_50 -> V_95 ) ;
if ( V_90 -> V_40 . V_63 ) {
V_50 -> V_86 = V_90 -> V_40 . V_63 -> V_64 . V_213 ;
V_90 -> V_40 . V_63 -> V_64 . V_213 = F_44 ;
}
break;
case V_216 :
V_90 -> V_40 . V_63 = F_49 ( V_217 ,
& V_218 ,
& V_50 -> V_95 ) ;
if ( V_90 -> V_40 . V_63 != NULL ) {
if ( ! F_49 ( V_219 , V_90 -> V_40 . V_63 ,
& V_50 -> V_95 ,
& V_220 ) )
goto V_134;
}
break;
case V_221 :
V_90 -> V_40 . V_63 = F_49 ( V_217 ,
& V_222 ,
& V_50 -> V_95 ) ;
if ( V_90 -> V_40 . V_63 != NULL ) {
struct V_37 * V_38 ;
struct V_93 V_94 = {
. V_95 = & V_50 -> V_95 ,
. V_96 = 0x61 ,
} ;
static struct V_91 V_92 = {
. V_223 = V_224 ,
. V_225 = 64 ,
. V_226 = V_227 ,
} ;
V_38 = F_49 ( V_99 ,
V_90 -> V_40 . V_63 , & V_94 ) ;
if ( V_38 != NULL && V_38 -> V_64 . V_228 . V_229 != NULL )
V_38 -> V_64 . V_228 . V_229 ( V_38 , & V_92 ) ;
}
break;
case V_230 :
case V_231 :
V_90 -> V_40 . V_63 = F_49 ( V_165 ,
& V_232 ,
& V_50 -> V_95 ) ;
if ( V_90 -> V_40 . V_63 ) {
V_90 -> V_40 . V_63 -> V_64 . V_65 = NULL ;
if ( F_47 ( 0x61 , V_8 ) < 0 )
goto V_134;
}
break;
case V_233 :
case V_234 :
V_90 -> V_40 . V_63 = F_49 ( V_165 ,
& V_232 ,
& V_50 -> V_95 ) ;
if ( V_90 -> V_40 . V_63 ) {
struct V_101 V_94 = {
. V_235 = 0x61 ,
. V_236 = 0 ,
. V_237 = 134 ,
. V_238 = 1 ,
. V_239 = 4560
} ;
V_90 -> V_40 . V_63 -> V_64 . V_65 = NULL ;
if ( F_52 ( V_8 , & V_94 ) < 0 )
goto V_134;
}
break;
case V_240 :
V_8 -> V_80 = 0x00 ;
V_90 -> V_40 . V_63 = F_49 ( V_165 ,
& V_241 ,
& V_50 -> V_95 ) ;
if ( F_47 ( 0x61 , V_8 ) < 0 )
goto V_134;
break;
case V_242 :
V_90 -> V_40 . V_63 = F_49 ( V_217 ,
& V_243 ,
& V_50 -> V_95 ) ;
if ( F_47 ( 0x61 , V_8 ) < 0 )
goto V_134;
break;
case V_244 :
V_90 -> V_40 . V_63 = F_49 ( V_245 ,
& V_246 ,
& V_50 -> V_95 ) ;
if ( V_90 -> V_40 . V_63 != NULL ) {
if ( ! F_49 ( V_219 , V_90 -> V_40 . V_63 ,
& V_50 -> V_95 ,
& V_247 ) )
goto V_134;
}
break;
case V_248 :
V_131 = 1 ;
V_8 -> V_46 . V_62 = 2 ;
V_90 -> V_40 . V_63 = F_49 ( V_249 ,
& V_250 ,
& V_8 -> V_50 -> V_95 ) ;
if ( V_90 -> V_40 . V_63 ) {
if ( ! F_49 ( V_159 ,
V_90 -> V_40 . V_63 ,
& V_8 -> V_50 -> V_95 ,
0x08 , V_160 , 0x00 , false ) )
goto V_134;
}
V_130 = F_27 ( & V_8 -> V_46 , 2 ) ;
if ( ! V_130 )
goto V_134;
V_130 -> V_40 . V_63 = F_49 ( V_138 ,
& V_151 ,
& V_8 -> V_50 -> V_95 ) ;
if ( V_130 -> V_40 . V_63 ) {
V_130 -> V_40 . V_63 -> V_161 = 1 ;
if ( ! F_49 ( V_152 ,
V_130 -> V_40 . V_63 ,
& V_8 -> V_50 -> V_95 ,
0x61 , V_153 ) )
goto V_134;
}
break;
case V_251 :
V_90 -> V_40 . V_63 = F_49 ( V_249 ,
& V_250 ,
& V_8 -> V_50 -> V_95 ) ;
if ( V_90 -> V_40 . V_63 ) {
if ( ! F_49 ( V_159 ,
V_90 -> V_40 . V_63 ,
& V_8 -> V_50 -> V_95 ,
0x08 , V_160 , 0x00 , false ) )
goto V_134;
}
break;
case V_252 :
case V_253 :
case V_254 :
V_90 -> V_40 . V_63 = F_49 ( V_255 ,
& V_256 ,
& V_50 -> V_95 ) ;
if ( V_90 -> V_40 . V_63 != NULL ) {
if ( ! F_49 ( V_140 , V_90 -> V_40 . V_63 , 0x60 ,
& V_50 -> V_95 , V_257 ) )
goto V_134;
V_50 -> V_86 = V_90 -> V_40 . V_63 -> V_64 . V_213 ;
V_90 -> V_40 . V_63 -> V_64 . V_213 = F_45 ;
} else {
V_90 -> V_40 . V_63 = F_49 ( V_258 ,
& V_259 ,
& V_50 -> V_95 ) ;
if ( V_90 -> V_40 . V_63 != NULL ) {
if ( ! F_49 ( V_260 , V_90 -> V_40 . V_63 , 0x61 ,
& V_50 -> V_95 ) )
goto V_134;
V_50 -> V_86 = V_90 -> V_40 . V_63 -> V_64 . V_213 ;
V_90 -> V_40 . V_63 -> V_64 . V_213 = F_45 ;
}
}
break;
case V_261 :
V_90 -> V_40 . V_63 = F_49 ( V_249 ,
& V_262 ,
& V_50 -> V_95 ) ;
if ( V_90 -> V_40 . V_63 != NULL )
V_90 -> V_40 . V_63 -> V_64 . V_213 = F_45 ;
break;
case V_263 :
V_90 -> V_40 . V_63 = F_49 ( V_264 ,
& V_265 ,
& V_50 -> V_95 ) ;
if ( V_90 -> V_40 . V_63 != NULL ) {
F_49 ( V_266 , V_90 -> V_40 . V_63 ,
& V_267 , & V_50 -> V_95 ) ;
V_90 -> V_40 . V_63 -> V_64 . V_213 =
F_45 ;
}
break;
case V_268 :
case V_269 :
case V_270 :
case V_271 :
V_90 -> V_40 . V_63 = F_49 ( V_249 ,
& V_250 ,
& V_50 -> V_95 ) ;
if ( V_90 -> V_40 . V_63 != NULL )
V_90 -> V_40 . V_63 -> V_64 . V_213 = F_45 ;
break;
case V_272 :
V_90 -> V_40 . V_63 = F_49 ( V_165 ,
& V_273 ,
& V_50 -> V_95 ) ;
if ( V_90 -> V_40 . V_63 ) {
V_90 -> V_40 . V_63 -> V_64 . V_65 = NULL ;
if ( F_47 ( 0x61 , V_8 ) < 0 )
goto V_134;
}
break;
case V_274 : {
struct V_275 * V_228 = NULL ;
V_90 -> V_40 . V_63 = F_49 ( V_276 ,
& V_277 ,
& V_50 -> V_95 , 0 ) ;
if ( V_90 -> V_40 . V_63 != NULL ) {
if ( ! F_49 ( V_278 , V_90 -> V_40 . V_63 ,
& V_279 ,
& V_50 -> V_95 ) )
goto V_134;
V_228 = & V_90 -> V_40 . V_63 -> V_64 . V_228 ;
V_228 -> V_280 = V_281 ;
V_228 -> V_282 = V_283 ;
V_228 -> V_284 = V_285 ;
V_228 -> V_286 = V_287 ;
V_50 -> V_86 =
V_90 -> V_40 . V_63 -> V_64 . V_213 ;
V_90 -> V_40 . V_63 -> V_64 . V_213 =
F_45 ;
}
break;
}
case V_288 :
V_8 -> V_80 = 0x08 ;
F_38 ( V_82 , 0x0101 ) ;
F_37 ( V_82 , 0x01 ) ;
F_71 ( 100 ) ;
F_38 ( V_82 , 0x01 ) ;
F_71 ( 200 ) ;
V_90 -> V_40 . V_63 = F_49 ( V_255 ,
& V_289 ,
& V_8 -> V_50 -> V_95 ) ;
if ( V_90 -> V_40 . V_63 ) {
V_90 -> V_40 . V_63 -> V_64 . V_228 . V_290 =
F_63 ;
V_90 -> V_40 . V_63 -> V_291 =
& V_8 -> V_50 -> V_95 ;
V_90 -> V_40 . V_63 -> V_64 . V_213 =
F_66 ;
V_90 -> V_40 . V_63 -> V_64 . V_292 =
F_65 ;
}
break;
case V_293 :
V_8 -> V_80 = 0x00 ;
V_90 -> V_40 . V_63 = F_49 ( V_294 ,
& V_295 ,
& V_50 -> V_95 ) ;
if ( V_90 -> V_40 . V_63 ) {
V_50 -> V_86 =
V_90 -> V_40 . V_63 -> V_64 . V_213 ;
V_90 -> V_40 . V_63 -> V_64 . V_213 =
F_46 ;
}
break;
default:
F_22 ( V_47 L_17 ,
V_50 -> V_98 ) ;
break;
}
if ( ( NULL == V_90 -> V_40 . V_63 ) || ( V_130 && NULL == V_130 -> V_40 . V_63 ) ) {
F_22 ( V_47
L_18 ,
V_50 -> V_98 ) ;
goto V_134;
}
V_90 -> V_40 . V_63 -> V_296 = V_297 ;
V_90 -> V_40 . V_63 -> V_64 . V_298 = F_20 ;
if ( V_130 )
V_130 -> V_40 . V_63 -> V_64 . V_298 = F_20 ;
F_72 ( V_50 , V_50 , V_299 , 0 ) ;
V_132 = F_73 ( & V_8 -> V_46 , V_300 , V_8 ,
& V_8 -> V_23 -> V_8 , V_301 , V_131 ) ;
if ( V_132 )
goto V_134;
return V_132 ;
V_134:
V_50 -> V_135 = NULL ;
F_62 ( & V_8 -> V_46 ) ;
return V_132 ;
}
static int F_74 ( struct V_42 * V_43 )
{
struct V_56 * V_50 = V_43 -> V_50 ;
int V_302 = 0 ;
F_36 ( 1 , L_19 , V_48 ) ;
switch ( V_50 -> V_136 ) {
case V_150 :
F_38 ( V_82 , 0x00000080 ) ;
F_30 ( 1000 ) ;
F_37 ( V_82 , 0x00000080 ) ;
F_30 ( 50 ) ;
F_38 ( V_82 , 0x00000080 ) ;
F_30 ( 1000 ) ;
F_37 ( V_82 , 0x00000004 ) ;
F_30 ( 1000 ) ;
break;
case V_156 :
case V_248 :
F_38 ( V_82 , 0x00000080 ) ;
F_30 ( 1000 ) ;
F_37 ( V_82 , 0x00000080 ) ;
F_30 ( 50 ) ;
F_38 ( V_82 , 0x00000080 ) ;
F_30 ( 1000 ) ;
switch ( V_50 -> V_61 -> V_46 . V_53 ) {
case 1 :
F_38 ( V_82 , 0x00000004 ) ;
F_43 ( V_103 , 1 ) ;
V_50 -> V_61 -> V_80 = 0x02 ;
break;
case 2 :
F_43 ( V_103 , 0 ) ;
F_37 ( V_82 , 0x00000004 ) ;
V_50 -> V_61 -> V_80 = 0x0c ;
break;
}
F_30 ( 1000 ) ;
break;
case V_234 :
F_43 ( V_303 , 0x0101 ) ;
break;
default:
V_302 = - V_108 ;
}
return V_302 ;
}
static int F_75 ( struct V_42 * V_43 )
{
struct V_56 * V_50 = V_43 -> V_50 ;
int V_302 = 0 ;
F_36 ( 1 , L_19 , V_48 ) ;
switch ( V_50 -> V_136 ) {
case V_150 :
break;
case V_156 :
case V_248 :
break;
default:
V_302 = - V_108 ;
}
return V_302 ;
}
static int F_76 ( struct V_42 * V_43 )
{
struct V_56 * V_50 = V_43 -> V_50 ;
struct V_7 * V_8 = V_43 -> V_50 -> V_61 ;
int V_302 ;
struct V_60 * V_38 ;
int V_104 ;
F_36 ( 1 , L_19 , V_48 ) ;
F_36 ( 1 , L_20 ,
V_50 -> V_136 ,
V_50 -> V_98 ,
V_50 -> V_304 ,
V_50 -> V_305 ) ;
V_302 = - V_108 ;
if ( ! ( V_50 -> V_106 . V_306 & V_52 ) )
goto V_307;
V_302 = F_77 ( V_8 ) ;
if ( 0 != V_302 )
goto V_307;
F_22 ( V_100 L_21 , V_50 -> V_98 ) ;
V_8 -> V_80 = 0x0c ;
V_302 = F_58 ( V_8 ) ;
if ( V_302 )
goto V_307;
V_302 = - V_108 ;
for ( V_104 = 1 ; V_104 <= V_50 -> V_106 . V_107 ; V_104 ++ ) {
struct V_1 * V_2 ;
V_38 = F_27 ( & V_50 -> V_61 -> V_46 , V_104 ) ;
if ( V_38 == NULL ) {
F_22 ( V_47 L_22 ,
V_48 , V_104 ) ;
goto V_308;
}
V_2 = & V_38 -> V_40 . V_309 ;
V_2 -> type = V_310 ;
V_2 -> V_311 = V_312 | V_313 | V_314 | V_315 ;
V_2 -> V_316 = V_317 ;
V_2 -> V_318 = 2 ;
V_2 -> V_9 = V_8 ;
V_2 -> V_319 = sizeof( struct V_18 ) ;
V_2 -> V_64 = & V_320 ;
V_2 -> V_321 = & V_322 ;
V_2 -> V_323 = V_324 ;
V_2 -> V_51 = & V_50 -> V_51 ;
V_302 = F_78 ( V_2 ) ;
if ( V_302 < 0 )
goto V_308;
V_38 -> V_40 . V_98 = V_8 -> V_50 -> V_98 ;
}
V_302 = F_69 ( V_8 ) ;
if ( V_302 )
F_22 ( V_47 L_23 ,
V_50 -> V_98 , V_302 ) ;
return V_302 ;
V_308:
F_62 ( & V_50 -> V_61 -> V_46 ) ;
V_307:
return V_302 ;
}
static int F_79 ( struct V_42 * V_43 )
{
struct V_56 * V_50 = V_43 -> V_50 ;
struct V_7 * V_8 = V_43 -> V_50 -> V_61 ;
F_36 ( 1 , L_19 , V_48 ) ;
F_80 ( & V_8 -> V_46 ) ;
F_81 ( V_8 ) ;
V_50 -> V_135 = NULL ;
return 0 ;
}
static int T_3 F_82 ( void )
{
F_22 ( V_100 L_24 ,
V_325 ) ;
return F_83 ( & V_326 ) ;
}
static void T_4 F_84 ( void )
{
F_85 ( & V_326 ) ;
}
