static int F_1 ( struct V_1 * V_2 , const struct V_3 * V_4 ,
unsigned int * V_5 , unsigned int * V_6 ,
unsigned int V_7 [] , void * V_8 [] )
{
struct V_9 * V_10 = V_2 -> V_11 ;
* V_6 = 1 ;
V_10 -> V_12 = 188 * 4 ;
V_10 -> V_13 = V_14 ;
V_7 [ 0 ] = V_10 -> V_12 * V_10 -> V_13 ;
V_8 [ 0 ] = V_10 -> V_15 ;
* V_5 = V_14 ;
return 0 ;
}
static int F_2 ( struct V_16 * V_17 )
{
struct V_9 * V_10 = V_17 -> V_1 -> V_11 ;
struct V_18 * V_19 = F_3 ( V_17 , struct V_18 , V_17 ) ;
return F_4 ( V_17 -> V_1 , V_10 , V_19 ) ;
}
static void F_5 ( struct V_16 * V_17 )
{
struct V_9 * V_10 = V_17 -> V_1 -> V_11 ;
struct V_18 * V_19 = F_3 ( V_17 , struct V_18 , V_17 ) ;
struct V_20 * V_21 = & V_19 -> V_21 ;
if ( V_21 -> V_22 )
F_6 ( V_10 -> V_23 , V_21 -> V_24 , V_21 -> V_22 , V_21 -> V_25 ) ;
memset ( V_21 , 0 , sizeof( * V_21 ) ) ;
}
static void F_7 ( struct V_16 * V_17 )
{
struct V_9 * V_10 = V_17 -> V_1 -> V_11 ;
struct V_18 * V_19 = F_3 ( V_17 , struct V_18 , V_17 ) ;
F_8 ( V_10 , V_19 ) ;
}
static int F_9 ( struct V_1 * V_2 , unsigned int V_26 )
{
struct V_9 * V_10 = V_2 -> V_11 ;
struct V_27 * V_28 = & V_10 -> V_29 ;
struct V_18 * V_19 ;
V_19 = F_10 ( V_28 -> V_30 . V_31 , struct V_18 , V_32 ) ;
F_11 ( V_10 , V_28 , V_19 ) ;
return 0 ;
}
static void F_12 ( struct V_1 * V_2 )
{
struct V_9 * V_10 = V_2 -> V_11 ;
struct V_27 * V_28 = & V_10 -> V_29 ;
unsigned long V_33 ;
F_13 ( V_10 ) ;
F_14 ( & V_10 -> V_34 , V_33 ) ;
while ( ! F_15 ( & V_28 -> V_30 ) ) {
struct V_18 * V_19 = F_10 ( V_28 -> V_30 . V_31 ,
struct V_18 , V_32 ) ;
F_16 ( & V_19 -> V_32 ) ;
F_17 ( & V_19 -> V_17 , V_35 ) ;
}
F_18 ( & V_10 -> V_34 , V_33 ) ;
}
static int F_19 ( struct V_36 * V_37 , int V_38 )
{
struct V_9 * V_10 = V_37 -> V_39 -> V_40 ;
struct V_41 * V_42 = NULL ;
int V_43 = 0 ;
int V_44 ;
V_44 = F_20 ( & V_10 -> V_45 , V_37 ) ;
if ( ! V_44 ) {
F_21 ( V_46 L_1 , V_47 ) ;
return - V_48 ;
}
F_22 ( & V_10 -> V_49 -> V_50 ) ;
V_42 = F_23 ( V_10 , V_51 ) ;
if ( V_42 ) {
if ( V_38 ) {
V_10 -> V_45 . V_52 = V_44 ;
V_43 = V_42 -> V_53 ( V_42 ) ;
} else {
V_43 = V_42 -> V_54 ( V_42 ) ;
V_10 -> V_45 . V_52 = 0 ;
}
}
F_24 ( & V_10 -> V_49 -> V_50 ) ;
return V_43 ;
}
static void F_25 ( struct V_55 * V_49 , int V_56 )
{
struct V_57 * V_58 ;
struct V_59 * V_37 ;
if ( ! V_49 -> V_60 )
return;
V_58 = & V_49 -> V_60 -> V_45 ;
if ( ! V_58 )
return;
if ( V_58 -> V_61 <= 1 )
V_37 = F_26 ( V_58 , 1 ) ;
else
V_37 = F_26 ( V_58 , V_58 -> V_61 ) ;
if ( V_37 && V_37 -> V_39 . V_62 && V_37 -> V_39 . V_62 -> V_63 . V_64 )
V_37 -> V_39 . V_62 -> V_63 . V_64 ( V_37 -> V_39 . V_62 , V_56 ) ;
}
static int F_27 ( struct V_36 * V_37 )
{
static const T_1 V_65 [] = { V_66 , 0x38 , 0x39 } ;
static const T_1 V_67 [] = { V_68 , 0x80 } ;
static const T_1 V_69 [] = { V_70 , 0x40 } ;
static const T_1 V_71 [] = { V_72 , 0x24 , 0x20 } ;
static const T_1 V_73 [] = { V_74 , 0x33 } ;
static const T_1 V_75 [] = { V_76 , 0x32 } ;
F_28 ( V_37 , V_65 , sizeof( V_65 ) ) ;
F_29 ( 200 ) ;
F_28 ( V_37 , V_67 , sizeof( V_67 ) ) ;
F_28 ( V_37 , V_69 , sizeof( V_69 ) ) ;
F_28 ( V_37 , V_71 , sizeof( V_71 ) ) ;
F_28 ( V_37 , V_73 , sizeof( V_73 ) ) ;
F_28 ( V_37 , V_75 , sizeof( V_75 ) ) ;
return 0 ;
}
static int F_30 ( struct V_36 * V_37 )
{
static const T_1 V_65 [] = { V_66 , 0x38 , 0x38 } ;
static const T_1 V_67 [] = { V_68 , 0x80 } ;
static const T_1 V_69 [] = { V_70 , 0x40 } ;
static const T_1 V_71 [] = { V_72 , 0x28 , 0x20 } ;
static const T_1 V_73 [] = { V_74 , 0x33 } ;
static const T_1 V_75 [] = { V_76 , 0x32 } ;
F_28 ( V_37 , V_65 , sizeof( V_65 ) ) ;
F_29 ( 200 ) ;
F_28 ( V_37 , V_67 , sizeof( V_67 ) ) ;
F_28 ( V_37 , V_69 , sizeof( V_69 ) ) ;
F_28 ( V_37 , V_71 , sizeof( V_71 ) ) ;
F_28 ( V_37 , V_73 , sizeof( V_73 ) ) ;
F_28 ( V_37 , V_75 , sizeof( V_75 ) ) ;
return 0 ;
}
static int F_31 ( struct V_36 * V_37 )
{
static const T_1 V_65 [] = { 0x89 , 0x38 , 0x39 } ;
static const T_1 V_67 [] = { 0x50 , 0x80 } ;
static const T_1 V_69 [] = { 0x8E , 0x40 } ;
static const T_1 V_71 [] = { 0x67 , 0x10 , 0x23 , 0x00 , 0xFF , 0xFF ,
0x00 , 0xFF , 0x00 , 0x40 , 0x40 } ;
static const T_1 V_77 [] = { 0xB5 , 0x7A } ;
static const T_1 V_75 [] = { 0x75 , 0x32 } ;
F_28 ( V_37 , V_65 , sizeof( V_65 ) ) ;
F_29 ( 2000 ) ;
F_28 ( V_37 , V_67 , sizeof( V_67 ) ) ;
F_28 ( V_37 , V_69 , sizeof( V_69 ) ) ;
F_28 ( V_37 , V_71 , sizeof( V_71 ) ) ;
F_29 ( 2000 ) ;
F_28 ( V_37 , V_77 , sizeof( V_77 ) ) ;
F_28 ( V_37 , V_75 , sizeof( V_75 ) ) ;
return 0 ;
}
static int F_32 ( struct V_36 * V_37 )
{
static const T_1 V_65 [] = { 0x89 , 0x38 , 0x38 } ;
static const T_1 V_67 [] = { 0x50 , 0x80 } ;
static const T_1 V_69 [] = { 0x8E , 0x40 } ;
static const T_1 V_71 [] = { 0x67 , 0x10 , 0x20 , 0x00 , 0xFF , 0xFF ,
0x00 , 0xFF , 0x00 , 0x40 , 0x40 } ;
static const T_1 V_77 [] = { 0xB5 , 0x7A } ;
static const T_1 V_75 [] = { 0x75 , 0x32 } ;
F_28 ( V_37 , V_65 , sizeof( V_65 ) ) ;
F_29 ( 2000 ) ;
F_28 ( V_37 , V_67 , sizeof( V_67 ) ) ;
F_28 ( V_37 , V_69 , sizeof( V_69 ) ) ;
F_28 ( V_37 , V_71 , sizeof( V_71 ) ) ;
F_29 ( 2000 ) ;
F_28 ( V_37 , V_77 , sizeof( V_77 ) ) ;
F_28 ( V_37 , V_75 , sizeof( V_75 ) ) ;
return 0 ;
}
static int F_33 ( struct V_36 * V_37 , int V_78 )
{
struct V_9 * V_10 = V_37 -> V_39 -> V_40 ;
V_10 -> V_79 = V_78 ? 0x04 : 0x00 ;
return 0 ;
}
static int F_34 ( struct V_36 * V_37 , int V_80 )
{
struct V_9 * V_10 = V_37 -> V_39 -> V_40 ;
struct V_55 * V_49 = V_10 -> V_49 ;
F_35 ( 1 , L_2 , V_47 , V_80 ) ;
if ( V_80 == 0 )
F_36 ( V_81 , 8 ) ;
else
F_37 ( V_81 , 8 ) ;
return 0 ;
}
static int F_38 ( struct V_36 * V_37 , int V_78 )
{
struct V_9 * V_10 = V_37 -> V_39 -> V_40 ;
if ( V_78 )
V_10 -> V_79 |= 0x04 ;
else
V_10 -> V_79 &= ~ 0x04 ;
return 0 ;
}
static int F_39 ( struct V_36 * V_37 , int V_78 )
{
struct V_9 * V_10 = V_37 -> V_39 -> V_40 ;
V_10 -> V_79 = V_78 ? 0x04 : 0x00 ;
return 0 ;
}
static int F_40 ( struct V_36 * V_37 ,
int V_78 )
{
struct V_9 * V_10 = V_37 -> V_39 -> V_40 ;
V_10 -> V_79 = 0x02 ;
return 0 ;
}
static int F_41 ( struct V_36 * V_37 ,
enum V_82 V_83 )
{
struct V_9 * V_10 = V_37 -> V_39 -> V_40 ;
struct V_55 * V_49 = V_10 -> V_49 ;
if ( V_83 == V_84 )
F_42 ( V_81 , 0x000006fb ) ;
else
F_42 ( V_81 , 0x000006f9 ) ;
if ( V_49 -> V_85 )
return V_49 -> V_85 ( V_37 , V_83 ) ;
return 0 ;
}
static int F_43 ( struct V_36 * V_37 ,
enum V_82 V_83 )
{
struct V_9 * V_10 = V_37 -> V_39 -> V_40 ;
struct V_55 * V_49 = V_10 -> V_49 ;
if ( V_83 == V_84 ) {
F_35 ( 1 , L_3 ) ;
F_42 ( V_81 , 0x0000efff ) ;
}
if ( V_49 -> V_85 )
return V_49 -> V_85 ( V_37 , V_83 ) ;
return 0 ;
}
static int F_44 ( struct V_36 * V_37 ,
enum V_82 V_83 )
{
struct V_9 * V_10 = V_37 -> V_39 -> V_40 ;
struct V_55 * V_49 = V_10 -> V_49 ;
F_37 ( V_81 , 0x6040 ) ;
switch ( V_83 ) {
case V_86 :
F_36 ( V_81 , 0x20 ) ;
break;
case V_87 :
F_37 ( V_81 , 0x20 ) ;
break;
case V_84 :
F_36 ( V_81 , 0x20 ) ;
break;
}
if ( V_49 -> V_85 )
return V_49 -> V_85 ( V_37 , V_83 ) ;
return 0 ;
}
static int F_45 ( struct V_36 * V_37 ,
enum V_82 V_83 )
{
struct V_9 * V_10 = V_37 -> V_39 -> V_40 ;
struct V_55 * V_49 = V_10 -> V_49 ;
switch ( V_83 ) {
case V_86 :
F_35 ( 1 , L_4 ) ;
F_42 ( V_81 , 0x00001220 ) ;
break;
case V_87 :
F_35 ( 1 , L_5 ) ;
F_42 ( V_81 , 0x00001222 ) ;
break;
case V_84 :
F_35 ( 1 , L_3 ) ;
F_42 ( V_81 , 0x00001230 ) ;
break;
}
if ( V_49 -> V_85 )
return V_49 -> V_85 ( V_37 , V_83 ) ;
return 0 ;
}
static int F_46 ( T_1 V_88 , struct V_9 * V_10 )
{
struct V_36 * V_37 ;
struct V_59 * V_89 = NULL ;
struct V_90 V_91 ;
struct V_92 V_93 = {
. V_94 = & V_10 -> V_49 -> V_94 ,
. V_95 = V_88 ,
. V_96 = & V_91 ,
} ;
V_89 = F_26 ( & V_10 -> V_45 , 1 ) ;
if ( ! V_89 )
return - V_48 ;
if ( ! V_89 -> V_39 . V_62 ) {
F_21 ( V_46 L_6
L_7 ,
V_10 -> V_49 -> V_97 ) ;
return - V_48 ;
}
F_47 ( V_10 -> V_49 , & V_91 ) ;
V_37 = F_48 ( V_98 , V_89 -> V_39 . V_62 , & V_93 ) ;
if ( ! V_37 ) {
F_21 ( V_46 L_8 ,
V_10 -> V_49 -> V_97 ) ;
F_49 ( V_89 -> V_39 . V_62 ) ;
F_50 ( V_89 -> V_39 . V_62 ) ;
V_89 -> V_39 . V_62 = NULL ;
return - V_48 ;
}
F_21 ( V_99 L_9 ,
V_10 -> V_49 -> V_97 ) ;
return 0 ;
}
static int F_51 ( struct V_9 * V_10 , struct V_100 * V_93 )
{
struct V_36 * V_37 ;
struct V_59 * V_89 = NULL ;
V_89 = F_26 ( & V_10 -> V_45 , 1 ) ;
if ( ! V_89 )
return - V_48 ;
if ( ! V_89 -> V_39 . V_62 ) {
F_21 ( V_46 L_6
L_10 ,
V_10 -> V_49 -> V_97 ) ;
return - V_48 ;
}
V_37 = F_48 ( V_101 , V_89 -> V_39 . V_62 , & V_10 -> V_49 -> V_94 ,
V_93 ) ;
if ( ! V_37 ) {
F_21 ( V_46 L_11 ,
V_10 -> V_49 -> V_97 ) ;
F_49 ( V_89 -> V_39 . V_62 ) ;
F_50 ( V_89 -> V_39 . V_62 ) ;
V_89 -> V_39 . V_62 = NULL ;
return - V_48 ;
}
F_21 ( V_99 L_12 , V_10 -> V_49 -> V_97 ) ;
return 0 ;
}
static int F_52 ( struct V_36 * V_37 ,
int V_78 )
{
struct V_9 * V_10 = V_37 -> V_39 -> V_40 ;
V_10 -> V_79 = 0x2 ;
return 0 ;
}
static int F_53 ( struct V_36 * V_37 ,
int V_78 )
{
struct V_9 * V_10 = V_37 -> V_39 -> V_40 ;
V_10 -> V_79 = 0 ;
return 0 ;
}
static int F_54 ( struct V_36 * V_37 )
{
struct V_9 * V_10 = V_37 -> V_39 -> V_40 ;
struct V_55 * V_49 = V_10 -> V_49 ;
F_42 ( V_102 , 0 ) ;
F_55 ( 10 ) ;
F_42 ( V_102 , 1 ) ;
F_55 ( 10 ) ;
return 0 ;
}
static int F_56 ( struct V_36 * V_37 ,
int V_78 )
{
struct V_9 * V_10 = V_37 -> V_39 -> V_40 ;
V_10 -> V_79 = 4 ;
return 0 ;
}
static int F_57 ( struct V_9 * V_10 )
{
struct V_55 * V_49 = V_10 -> V_49 ;
struct V_59 * V_37 = NULL ;
int V_103 ;
F_58 ( & V_10 -> V_45 . V_50 ) ;
F_59 ( & V_10 -> V_45 . V_104 ) ;
if ( ! V_49 -> V_105 . V_106 )
return - V_107 ;
F_21 ( V_99 L_13 , V_47 ,
V_49 -> V_105 . V_106 ) ;
for ( V_103 = 1 ; V_103 <= V_49 -> V_105 . V_106 ; V_103 ++ ) {
V_37 = F_60 ( & V_10 -> V_45 , V_103 ) ;
if ( ! V_37 ) {
F_21 ( V_46 L_14 , V_47 ) ;
F_61 ( & V_10 -> V_45 ) ;
return - V_108 ;
}
}
return 0 ;
}
static int F_62 ( struct V_36 * V_37 )
{
struct V_109 * V_110 = & V_37 -> V_111 ;
struct V_9 * V_10 = V_37 -> V_39 -> V_40 ;
T_1 V_19 [ 4 ] ;
T_2 div ;
struct V_112 V_113 = {
. V_88 = 0x61 ,
. V_33 = 0 ,
. V_19 = V_19 ,
. V_114 = sizeof( V_19 ) } ;
div = V_110 -> V_115 / 125 ;
V_19 [ 0 ] = ( div >> 8 ) & 0x7f ;
V_19 [ 1 ] = div & 0xff ;
V_19 [ 2 ] = 0x84 ;
V_19 [ 3 ] = 0x00 ;
if ( V_110 -> V_115 < 1500000 )
V_19 [ 3 ] |= 0x10 ;
if ( V_37 -> V_63 . V_64 )
V_37 -> V_63 . V_64 ( V_37 , 1 ) ;
if ( F_63 ( & V_10 -> V_49 -> V_94 , & V_113 , 1 ) != 1 )
return - V_116 ;
return 0 ;
}
static int F_64 ( struct V_36 * V_37 ,
enum V_117 V_118 )
{
struct V_9 * V_10 = V_37 -> V_39 -> V_40 ;
struct V_55 * V_49 = V_10 -> V_49 ;
F_37 ( V_81 , 0x0800 ) ;
switch ( V_118 ) {
case V_119 :
F_37 ( V_81 , 0x08 ) ;
break;
case V_120 :
F_36 ( V_81 , 0x08 ) ;
break;
default:
return - V_48 ;
}
return 0 ;
}
static int F_65 ( struct V_36 * V_37 ,
enum V_82 V_83 )
{
struct V_9 * V_10 = V_37 -> V_39 -> V_40 ;
struct V_55 * V_49 = V_10 -> V_49 ;
T_1 V_121 ;
struct V_112 V_113 = {
. V_88 = 8 ,
. V_33 = 0 ,
. V_19 = & V_121 ,
. V_114 = sizeof( V_121 ) } ;
F_37 ( V_81 , 0x8000 ) ;
switch ( V_83 ) {
case V_84 :
break;
case V_86 :
V_121 = V_122 | V_123 ;
F_36 ( V_81 , 0x80 ) ;
break;
case V_87 :
V_121 = V_122 | V_123 | V_124 ;
F_36 ( V_81 , 0x80 ) ;
break;
default:
return - V_48 ;
}
return ( F_63 ( & V_10 -> V_49 -> V_94 , & V_113 , 1 ) == 1 ) ? 0 : - V_116 ;
}
static int F_66 ( struct V_36 * V_37 ,
T_2 V_125 , T_2 V_126 )
{
T_1 V_127 = 0 ;
T_1 V_128 = 0 ;
if ( V_125 < 1500000 ) {
V_127 = 0xb7 ;
V_128 = 0x47 ;
} else if ( V_125 < 3000000 ) {
V_127 = 0xb7 ;
V_128 = 0x4b ;
} else if ( V_125 < 7000000 ) {
V_127 = 0xb7 ;
V_128 = 0x4f ;
} else if ( V_125 < 14000000 ) {
V_127 = 0xb7 ;
V_128 = 0x53 ;
} else if ( V_125 < 30000000 ) {
V_127 = 0xb6 ;
V_128 = 0x53 ;
} else if ( V_125 < 45000000 ) {
V_127 = 0xb4 ;
V_128 = 0x51 ;
}
F_67 ( V_37 , 0x13 , V_127 ) ;
F_67 ( V_37 , 0x14 , V_128 ) ;
F_67 ( V_37 , 0x1f , ( V_126 >> 16 ) & 0xff ) ;
F_67 ( V_37 , 0x20 , ( V_126 >> 8 ) & 0xff ) ;
F_67 ( V_37 , 0x21 , V_126 & 0xf0 ) ;
return 0 ;
}
static int F_68 ( struct V_9 * V_10 )
{
struct V_55 * V_49 = V_10 -> V_49 ;
struct V_59 * V_89 , * V_129 = NULL ;
int V_130 = 0 ;
int V_131 = - V_48 ;
if ( 0 != V_49 -> V_132 ) {
F_21 ( V_46 L_15 , V_49 -> V_97 ) ;
goto V_133;
}
V_89 = F_26 ( & V_10 -> V_45 , 1 ) ;
if ( ! V_89 )
goto V_133;
V_10 -> V_45 . V_61 = 0 ;
V_49 -> V_134 = F_25 ;
switch ( V_49 -> V_135 ) {
case V_136 :
V_89 -> V_39 . V_62 = F_48 ( V_137 ,
& V_138 ,
& V_49 -> V_94 ) ;
if ( V_89 -> V_39 . V_62 != NULL ) {
if ( ! F_48 ( V_139 , V_89 -> V_39 . V_62 ,
0x61 , & V_49 -> V_94 ,
V_140 ) )
goto V_133;
}
break;
case V_141 :
case V_142 :
case V_143 :
case V_144 :
V_89 -> V_39 . V_62 = F_48 ( V_137 ,
& V_138 ,
& V_49 -> V_94 ) ;
if ( V_89 -> V_39 . V_62 != NULL ) {
if ( ! F_48 ( V_139 , V_89 -> V_39 . V_62 ,
0x60 , & V_49 -> V_94 ,
V_145 ) )
goto V_133;
}
break;
case V_146 :
case V_147 :
case V_148 :
case V_149 :
V_89 -> V_39 . V_62 = F_48 ( V_137 ,
& V_150 ,
& V_49 -> V_94 ) ;
if ( V_89 -> V_39 . V_62 != NULL ) {
if ( ! F_48 ( V_151 , V_89 -> V_39 . V_62 ,
& V_49 -> V_94 , 0x61 ,
V_152 ) )
goto V_133;
}
break;
case V_153 :
V_89 -> V_39 . V_62 = F_48 ( V_137 ,
& V_150 ,
& V_49 -> V_94 ) ;
if ( V_89 -> V_39 . V_62 != NULL ) {
if ( ! F_48 ( V_151 , V_89 -> V_39 . V_62 ,
& V_49 -> V_94 , 0x61 ,
V_154 ) )
goto V_133;
}
break;
case V_155 :
V_130 = 1 ;
V_10 -> V_45 . V_61 = 2 ;
V_89 -> V_39 . V_62 = F_48 ( V_156 ,
& V_157 ,
& V_10 -> V_49 -> V_94 ) ;
if ( V_89 -> V_39 . V_62 ) {
if ( ! F_48 ( V_158 ,
V_89 -> V_39 . V_62 ,
& V_10 -> V_49 -> V_94 ,
0x08 , V_159 , 0x00 , false ) )
goto V_133;
}
V_129 = F_26 ( & V_10 -> V_45 , 2 ) ;
if ( ! V_129 )
goto V_133;
V_129 -> V_39 . V_62 = F_48 ( V_137 ,
& V_150 ,
& V_10 -> V_49 -> V_94 ) ;
if ( V_129 -> V_39 . V_62 ) {
V_129 -> V_39 . V_62 -> V_160 = 1 ;
if ( ! F_48 ( V_151 ,
V_129 -> V_39 . V_62 ,
& V_10 -> V_49 -> V_94 ,
0x61 , V_152 ) )
goto V_133;
}
break;
case V_161 :
V_89 -> V_39 . V_62 = F_48 ( V_162 ,
& V_163 ,
& V_49 -> V_94 ) ;
if ( V_89 -> V_39 . V_62 != NULL ) {
if ( ! F_48 ( V_139 , V_89 -> V_39 . V_62 ,
0x60 , NULL , V_145 ) )
goto V_133;
break;
}
V_89 -> V_39 . V_62 = F_48 ( V_164 ,
& V_165 ,
& V_49 -> V_94 ) ;
if ( V_89 -> V_39 . V_62 != NULL ) {
if ( ! F_48 ( V_139 , V_89 -> V_39 . V_62 ,
0x60 , NULL , V_145 ) )
goto V_133;
}
break;
case V_166 :
V_89 -> V_39 . V_62 = F_48 ( V_162 ,
& V_167 ,
& V_49 -> V_94 ) ;
if ( V_89 -> V_39 . V_62 != NULL ) {
if ( ! F_48 ( V_139 , V_89 -> V_39 . V_62 ,
0x61 , NULL , V_145 ) )
goto V_133;
break;
}
V_89 -> V_39 . V_62 = F_48 ( V_164 ,
& V_165 ,
& V_49 -> V_94 ) ;
if ( V_89 -> V_39 . V_62 != NULL ) {
if ( ! F_48 ( V_139 , V_89 -> V_39 . V_62 ,
0x61 , NULL , V_145 ) )
goto V_133;
}
break;
case V_168 :
V_89 -> V_39 . V_62 = F_48 ( V_162 ,
& V_163 ,
& V_49 -> V_94 ) ;
if ( V_89 -> V_39 . V_62 != NULL ) {
if ( ! F_48 ( V_139 , V_89 -> V_39 . V_62 ,
0x61 , NULL , V_169 ) )
goto V_133;
}
break;
case V_170 :
case V_171 :
case V_172 :
V_89 -> V_39 . V_62 = F_48 ( V_162 ,
& V_173 ,
& V_49 -> V_94 ) ;
if ( V_89 -> V_39 . V_62 != NULL ) {
if ( ! F_48 ( V_139 , V_89 -> V_39 . V_62 ,
0x61 , NULL , V_174 ) )
goto V_133;
}
break;
case V_175 :
#if F_69 ( V_176 )
V_89 -> V_39 . V_62 = F_48 ( V_162 , & V_177 ,
& V_10 -> V_178 -> V_179 ) ;
if ( V_89 -> V_39 . V_62 != NULL ) {
if ( ! F_48 ( V_151 , V_89 -> V_39 . V_62 ,
& V_49 -> V_94 , 0x61 ,
V_152 ) )
goto V_133;
}
#else
F_21 ( V_46 L_16 ,
V_49 -> V_97 ) ;
#endif
break;
case V_180 :
V_89 -> V_39 . V_62 = F_48 ( V_164 ,
& V_181 ,
& V_49 -> V_94 ) ;
if ( V_89 -> V_39 . V_62 != NULL ) {
if ( ! F_48 ( V_151 , V_89 -> V_39 . V_62 ,
& V_49 -> V_94 , 0x61 ,
V_182 ) )
goto V_133;
}
break;
case V_183 :
V_89 -> V_39 . V_62 = F_48 ( V_164 ,
& V_184 ,
& V_49 -> V_94 ) ;
if ( V_89 -> V_39 . V_62 == NULL )
V_89 -> V_39 . V_62 = F_48 ( V_162 ,
& V_185 ,
& V_49 -> V_94 ) ;
if ( V_89 -> V_39 . V_62 )
V_89 -> V_39 . V_62 -> V_63 . V_64 = NULL ;
if ( F_46 ( 0x61 , V_10 ) < 0 )
goto V_133;
break;
case V_186 :
V_89 -> V_39 . V_62 = F_48 ( V_187 , & V_188 ,
& V_49 -> V_94 ) ;
if ( V_89 -> V_39 . V_62 != NULL ) {
if ( ! F_48 ( V_151 , V_89 -> V_39 . V_62 ,
& V_49 -> V_94 , 0x61 ,
V_189 ) )
goto V_133;
}
break;
case V_190 :
V_10 -> V_79 = 0x08 ;
F_36 ( V_81 , 1 ) ;
F_70 ( 100 ) ;
F_37 ( V_81 , 1 ) ;
F_70 ( 200 ) ;
V_191 . V_192 = F_34 ;
V_89 -> V_39 . V_62 = F_48 ( V_193 ,
& V_191 ,
& V_49 -> V_94 ) ;
if ( V_89 -> V_39 . V_62 != NULL ) {
if ( ! F_48 ( V_151 , V_89 -> V_39 . V_62 ,
& V_49 -> V_94 , 0x61 ,
V_194 ) )
goto V_133;
}
break;
case V_195 :
V_10 -> V_79 = 0x08 ;
F_36 ( V_81 , 1 ) ;
F_70 ( 100 ) ;
F_37 ( V_81 , 9 ) ;
F_70 ( 200 ) ;
V_89 -> V_39 . V_62 = F_48 ( V_193 ,
& V_191 ,
& V_49 -> V_94 ) ;
if ( V_89 -> V_39 . V_62 != NULL ) {
if ( ! F_48 ( V_151 , V_89 -> V_39 . V_62 ,
& V_49 -> V_94 , 0x61 ,
V_189 ) )
goto V_133;
}
break;
case V_196 :
V_10 -> V_79 = 0x08 ;
F_36 ( V_81 , 1 ) ;
F_70 ( 100 ) ;
F_37 ( V_81 , 1 ) ;
F_70 ( 200 ) ;
V_89 -> V_39 . V_62 = F_48 ( V_193 ,
& V_197 ,
& V_49 -> V_94 ) ;
if ( V_89 -> V_39 . V_62 != NULL ) {
if ( ! F_48 ( V_151 , V_89 -> V_39 . V_62 ,
& V_49 -> V_94 , 0x61 ,
V_198 ) )
goto V_133;
if ( ! F_48 ( V_199 , V_89 -> V_39 . V_62 ,
& V_49 -> V_94 , 0x43 ) )
goto V_133;
}
break;
case V_200 :
V_10 -> V_79 = 0x08 ;
F_36 ( V_81 , 1 ) ;
F_70 ( 100 ) ;
F_37 ( V_81 , 1 ) ;
F_70 ( 200 ) ;
V_89 -> V_39 . V_62 = F_48 ( V_193 ,
& V_201 ,
& V_49 -> V_94 ) ;
if ( V_89 -> V_39 . V_62 != NULL ) {
if ( ! F_48 ( V_151 , V_89 -> V_39 . V_62 ,
& V_49 -> V_94 , 0x61 ,
V_198 ) )
goto V_133;
if ( ! F_48 ( V_199 , V_89 -> V_39 . V_62 ,
& V_49 -> V_94 , 0x43 ) )
goto V_133;
}
break;
case V_202 :
V_89 -> V_39 . V_62 = F_48 ( V_203 ,
& V_204 ,
& V_49 -> V_94 ) ;
if ( V_89 -> V_39 . V_62 != NULL ) {
if ( ! F_48 ( V_151 , V_89 -> V_39 . V_62 ,
& V_49 -> V_94 , 0x61 ,
V_205 ) )
goto V_133;
}
break;
case V_206 :
case V_207 :
V_89 -> V_39 . V_62 = F_48 ( V_156 ,
& V_157 ,
& V_49 -> V_94 ) ;
if ( V_89 -> V_39 . V_62 ) {
bool V_208 ;
if ( V_49 -> V_209 == 92001 )
V_208 = true ;
else
V_208 = false ;
if ( ! F_48 ( V_158 , V_89 -> V_39 . V_62 ,
& V_49 -> V_94 , 0x08 , V_159 , 0x00 ,
V_208 ) )
goto V_133;
}
break;
case V_210 :
V_89 -> V_39 . V_62 = F_48 ( V_156 ,
& V_211 ,
& V_49 -> V_94 ) ;
if ( V_89 -> V_39 . V_62 ) {
V_49 -> V_85 = V_89 -> V_39 . V_62 -> V_63 . V_212 ;
V_89 -> V_39 . V_62 -> V_63 . V_212 = F_41 ;
}
break;
case V_213 :
V_89 -> V_39 . V_62 = F_48 ( V_156 ,
& V_214 ,
& V_49 -> V_94 ) ;
if ( V_89 -> V_39 . V_62 ) {
V_49 -> V_85 = V_89 -> V_39 . V_62 -> V_63 . V_212 ;
V_89 -> V_39 . V_62 -> V_63 . V_212 = F_43 ;
}
break;
case V_215 :
V_89 -> V_39 . V_62 = F_48 ( V_216 ,
& V_217 ,
& V_49 -> V_94 ) ;
if ( V_89 -> V_39 . V_62 != NULL ) {
if ( ! F_48 ( V_218 , V_89 -> V_39 . V_62 ,
& V_49 -> V_94 ,
& V_219 ) )
goto V_133;
}
break;
case V_220 :
V_89 -> V_39 . V_62 = F_48 ( V_216 ,
& V_221 ,
& V_49 -> V_94 ) ;
if ( V_89 -> V_39 . V_62 != NULL ) {
struct V_36 * V_37 ;
struct V_92 V_93 = {
. V_94 = & V_49 -> V_94 ,
. V_95 = 0x61 ,
} ;
static struct V_90 V_91 = {
. V_222 = V_223 ,
. V_224 = 64 ,
. V_225 = V_226 ,
} ;
V_37 = F_48 ( V_98 ,
V_89 -> V_39 . V_62 , & V_93 ) ;
if ( V_37 != NULL && V_37 -> V_63 . V_227 . V_228 != NULL )
V_37 -> V_63 . V_227 . V_228 ( V_37 , & V_91 ) ;
}
break;
case V_229 :
case V_230 :
V_89 -> V_39 . V_62 = F_48 ( V_164 ,
& V_231 ,
& V_49 -> V_94 ) ;
if ( V_89 -> V_39 . V_62 ) {
V_89 -> V_39 . V_62 -> V_63 . V_64 = NULL ;
if ( F_46 ( 0x61 , V_10 ) < 0 )
goto V_133;
}
break;
case V_232 :
case V_233 :
V_89 -> V_39 . V_62 = F_48 ( V_164 ,
& V_231 ,
& V_49 -> V_94 ) ;
if ( V_89 -> V_39 . V_62 ) {
struct V_100 V_93 = {
. V_234 = 0x61 ,
. V_235 = 0 ,
. V_236 = 134 ,
. V_237 = 1 ,
. V_238 = 4560
} ;
V_89 -> V_39 . V_62 -> V_63 . V_64 = NULL ;
if ( F_51 ( V_10 , & V_93 ) < 0 )
goto V_133;
}
break;
case V_239 :
V_10 -> V_79 = 0x00 ;
V_89 -> V_39 . V_62 = F_48 ( V_164 ,
& V_240 ,
& V_49 -> V_94 ) ;
if ( F_46 ( 0x61 , V_10 ) < 0 )
goto V_133;
break;
case V_241 :
V_89 -> V_39 . V_62 = F_48 ( V_216 ,
& V_242 ,
& V_49 -> V_94 ) ;
if ( F_46 ( 0x61 , V_10 ) < 0 )
goto V_133;
break;
case V_243 :
V_89 -> V_39 . V_62 = F_48 ( V_244 ,
& V_245 ,
& V_49 -> V_94 ) ;
if ( V_89 -> V_39 . V_62 != NULL ) {
if ( ! F_48 ( V_218 , V_89 -> V_39 . V_62 ,
& V_49 -> V_94 ,
& V_246 ) )
goto V_133;
}
break;
case V_247 :
V_130 = 1 ;
V_10 -> V_45 . V_61 = 2 ;
V_89 -> V_39 . V_62 = F_48 ( V_248 ,
& V_249 ,
& V_10 -> V_49 -> V_94 ) ;
if ( V_89 -> V_39 . V_62 ) {
if ( ! F_48 ( V_158 ,
V_89 -> V_39 . V_62 ,
& V_10 -> V_49 -> V_94 ,
0x08 , V_159 , 0x00 , false ) )
goto V_133;
}
V_129 = F_26 ( & V_10 -> V_45 , 2 ) ;
if ( ! V_129 )
goto V_133;
V_129 -> V_39 . V_62 = F_48 ( V_137 ,
& V_150 ,
& V_10 -> V_49 -> V_94 ) ;
if ( V_129 -> V_39 . V_62 ) {
V_129 -> V_39 . V_62 -> V_160 = 1 ;
if ( ! F_48 ( V_151 ,
V_129 -> V_39 . V_62 ,
& V_10 -> V_49 -> V_94 ,
0x61 , V_152 ) )
goto V_133;
}
break;
case V_250 :
V_89 -> V_39 . V_62 = F_48 ( V_248 ,
& V_249 ,
& V_10 -> V_49 -> V_94 ) ;
if ( V_89 -> V_39 . V_62 ) {
if ( ! F_48 ( V_158 ,
V_89 -> V_39 . V_62 ,
& V_10 -> V_49 -> V_94 ,
0x08 , V_159 , 0x00 , false ) )
goto V_133;
}
break;
case V_251 :
case V_252 :
case V_253 :
V_89 -> V_39 . V_62 = F_48 ( V_254 ,
& V_255 ,
& V_49 -> V_94 ) ;
if ( V_89 -> V_39 . V_62 != NULL ) {
if ( ! F_48 ( V_139 , V_89 -> V_39 . V_62 , 0x60 ,
& V_49 -> V_94 , V_256 ) )
goto V_133;
V_49 -> V_85 = V_89 -> V_39 . V_62 -> V_63 . V_212 ;
V_89 -> V_39 . V_62 -> V_63 . V_212 = F_44 ;
} else {
V_89 -> V_39 . V_62 = F_48 ( V_257 ,
& V_258 ,
& V_49 -> V_94 ) ;
if ( V_89 -> V_39 . V_62 != NULL ) {
if ( ! F_48 ( V_259 , V_89 -> V_39 . V_62 , 0x61 ,
& V_49 -> V_94 ) )
goto V_133;
V_49 -> V_85 = V_89 -> V_39 . V_62 -> V_63 . V_212 ;
V_89 -> V_39 . V_62 -> V_63 . V_212 = F_44 ;
}
}
break;
case V_260 :
V_89 -> V_39 . V_62 = F_48 ( V_248 ,
& V_261 ,
& V_49 -> V_94 ) ;
if ( V_89 -> V_39 . V_62 != NULL )
V_89 -> V_39 . V_62 -> V_63 . V_212 = F_44 ;
break;
case V_262 :
V_89 -> V_39 . V_62 = F_48 ( V_263 ,
& V_264 ,
& V_49 -> V_94 ) ;
if ( V_89 -> V_39 . V_62 != NULL ) {
F_48 ( V_265 , V_89 -> V_39 . V_62 ,
& V_266 , & V_49 -> V_94 ) ;
V_89 -> V_39 . V_62 -> V_63 . V_212 =
F_44 ;
}
break;
case V_267 :
case V_268 :
case V_269 :
case V_270 :
V_89 -> V_39 . V_62 = F_48 ( V_248 ,
& V_249 ,
& V_49 -> V_94 ) ;
if ( V_89 -> V_39 . V_62 != NULL )
V_89 -> V_39 . V_62 -> V_63 . V_212 = F_44 ;
break;
case V_271 :
V_89 -> V_39 . V_62 = F_48 ( V_164 ,
& V_272 ,
& V_49 -> V_94 ) ;
if ( V_89 -> V_39 . V_62 ) {
V_89 -> V_39 . V_62 -> V_63 . V_64 = NULL ;
if ( F_46 ( 0x61 , V_10 ) < 0 )
goto V_133;
}
break;
case V_273 : {
struct V_274 * V_227 = NULL ;
V_89 -> V_39 . V_62 = F_48 ( V_275 ,
& V_276 ,
& V_49 -> V_94 , 0 ) ;
if ( V_89 -> V_39 . V_62 != NULL ) {
if ( ! F_48 ( V_277 , V_89 -> V_39 . V_62 ,
& V_278 ,
& V_49 -> V_94 ) )
goto V_133;
V_227 = & V_89 -> V_39 . V_62 -> V_63 . V_227 ;
V_227 -> V_279 = V_280 ;
V_227 -> V_281 = V_282 ;
V_227 -> V_283 = V_284 ;
V_227 -> V_285 = V_286 ;
V_49 -> V_85 =
V_89 -> V_39 . V_62 -> V_63 . V_212 ;
V_89 -> V_39 . V_62 -> V_63 . V_212 =
F_44 ;
}
break;
}
case V_287 :
V_10 -> V_79 = 0x08 ;
F_37 ( V_81 , 0x0101 ) ;
F_36 ( V_81 , 0x01 ) ;
F_70 ( 100 ) ;
F_37 ( V_81 , 0x01 ) ;
F_70 ( 200 ) ;
V_89 -> V_39 . V_62 = F_48 ( V_254 ,
& V_288 ,
& V_10 -> V_49 -> V_94 ) ;
if ( V_89 -> V_39 . V_62 ) {
V_89 -> V_39 . V_62 -> V_63 . V_227 . V_289 =
F_62 ;
V_89 -> V_39 . V_62 -> V_290 =
& V_10 -> V_49 -> V_94 ;
V_89 -> V_39 . V_62 -> V_63 . V_212 =
F_65 ;
V_89 -> V_39 . V_62 -> V_63 . V_291 =
F_64 ;
}
break;
case V_292 :
V_10 -> V_79 = 0x00 ;
V_89 -> V_39 . V_62 = F_48 ( V_293 ,
& V_294 ,
& V_49 -> V_94 ) ;
if ( V_89 -> V_39 . V_62 ) {
V_49 -> V_85 =
V_89 -> V_39 . V_62 -> V_63 . V_212 ;
V_89 -> V_39 . V_62 -> V_63 . V_212 =
F_45 ;
}
break;
default:
F_21 ( V_46 L_17 ,
V_49 -> V_97 ) ;
break;
}
if ( ( NULL == V_89 -> V_39 . V_62 ) || ( V_129 && NULL == V_129 -> V_39 . V_62 ) ) {
F_21 ( V_46
L_18 ,
V_49 -> V_97 ) ;
goto V_133;
}
V_89 -> V_39 . V_62 -> V_295 = V_296 ;
V_89 -> V_39 . V_62 -> V_63 . V_297 = F_19 ;
if ( V_129 )
V_129 -> V_39 . V_62 -> V_63 . V_297 = F_19 ;
F_71 ( V_49 , V_49 , V_298 , 0 ) ;
V_131 = F_72 ( & V_10 -> V_45 , V_299 , V_10 ,
& V_10 -> V_23 -> V_10 , V_300 , V_130 ) ;
if ( V_131 )
goto V_133;
return V_131 ;
V_133:
V_49 -> V_134 = NULL ;
F_61 ( & V_10 -> V_45 ) ;
return V_131 ;
}
static int F_73 ( struct V_41 * V_42 )
{
struct V_55 * V_49 = V_42 -> V_49 ;
int V_301 = 0 ;
F_35 ( 1 , L_19 , V_47 ) ;
switch ( V_49 -> V_135 ) {
case V_149 :
F_37 ( V_81 , 0x00000080 ) ;
F_29 ( 1000 ) ;
F_36 ( V_81 , 0x00000080 ) ;
F_29 ( 50 ) ;
F_37 ( V_81 , 0x00000080 ) ;
F_29 ( 1000 ) ;
F_36 ( V_81 , 0x00000004 ) ;
F_29 ( 1000 ) ;
break;
case V_155 :
case V_247 :
F_37 ( V_81 , 0x00000080 ) ;
F_29 ( 1000 ) ;
F_36 ( V_81 , 0x00000080 ) ;
F_29 ( 50 ) ;
F_37 ( V_81 , 0x00000080 ) ;
F_29 ( 1000 ) ;
switch ( V_49 -> V_60 -> V_45 . V_52 ) {
case 1 :
F_37 ( V_81 , 0x00000004 ) ;
F_42 ( V_102 , 1 ) ;
V_49 -> V_60 -> V_79 = 0x02 ;
break;
case 2 :
F_42 ( V_102 , 0 ) ;
F_36 ( V_81 , 0x00000004 ) ;
V_49 -> V_60 -> V_79 = 0x0c ;
break;
}
F_29 ( 1000 ) ;
break;
case V_233 :
F_42 ( V_302 , 0x0101 ) ;
break;
default:
V_301 = - V_107 ;
}
return V_301 ;
}
static int F_74 ( struct V_41 * V_42 )
{
struct V_55 * V_49 = V_42 -> V_49 ;
int V_301 = 0 ;
F_35 ( 1 , L_19 , V_47 ) ;
switch ( V_49 -> V_135 ) {
case V_149 :
break;
case V_155 :
case V_247 :
break;
default:
V_301 = - V_107 ;
}
return V_301 ;
}
static int F_75 ( struct V_41 * V_42 )
{
struct V_55 * V_49 = V_42 -> V_49 ;
struct V_9 * V_10 = V_42 -> V_49 -> V_60 ;
int V_301 ;
struct V_59 * V_37 ;
int V_103 ;
F_35 ( 1 , L_19 , V_47 ) ;
F_35 ( 1 , L_20 ,
V_49 -> V_135 ,
V_49 -> V_97 ,
V_49 -> V_303 ,
V_49 -> V_304 ) ;
V_301 = - V_107 ;
if ( ! ( V_49 -> V_105 . V_305 & V_51 ) )
goto V_306;
V_301 = F_76 ( V_10 ) ;
if ( 0 != V_301 )
goto V_306;
F_21 ( V_99 L_21 , V_49 -> V_97 ) ;
V_10 -> V_79 = 0x0c ;
V_301 = F_57 ( V_10 ) ;
if ( V_301 )
goto V_306;
V_301 = - V_107 ;
for ( V_103 = 1 ; V_103 <= V_49 -> V_105 . V_106 ; V_103 ++ ) {
struct V_1 * V_2 ;
V_37 = F_26 ( & V_49 -> V_60 -> V_45 , V_103 ) ;
if ( V_37 == NULL ) {
F_21 ( V_46 L_22 ,
V_47 , V_103 ) ;
goto V_307;
}
V_2 = & V_37 -> V_39 . V_308 ;
V_2 -> type = V_309 ;
V_2 -> V_310 = V_311 | V_312 | V_313 | V_314 ;
V_2 -> V_315 = V_316 ;
V_2 -> V_317 = 2 ;
V_2 -> V_11 = V_10 ;
V_2 -> V_318 = sizeof( struct V_18 ) ;
V_2 -> V_63 = & V_319 ;
V_2 -> V_320 = & V_321 ;
V_2 -> V_322 = V_323 ;
V_2 -> V_50 = & V_49 -> V_50 ;
V_301 = F_77 ( V_2 ) ;
if ( V_301 < 0 )
goto V_307;
V_37 -> V_39 . V_97 = V_10 -> V_49 -> V_97 ;
}
V_301 = F_68 ( V_10 ) ;
if ( V_301 )
F_21 ( V_46 L_23 ,
V_49 -> V_97 , V_301 ) ;
return V_301 ;
V_307:
F_61 ( & V_49 -> V_60 -> V_45 ) ;
V_306:
return V_301 ;
}
static int F_78 ( struct V_41 * V_42 )
{
struct V_55 * V_49 = V_42 -> V_49 ;
struct V_9 * V_10 = V_42 -> V_49 -> V_60 ;
F_35 ( 1 , L_19 , V_47 ) ;
F_79 ( & V_10 -> V_45 ) ;
F_80 ( V_10 ) ;
V_49 -> V_134 = NULL ;
return 0 ;
}
static int T_3 F_81 ( void )
{
F_21 ( V_99 L_24 ,
V_324 ) ;
return F_82 ( & V_325 ) ;
}
static void T_4 F_83 ( void )
{
F_84 ( & V_325 ) ;
}
