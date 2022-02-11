static int F_1 ( struct V_1 * V_2 , const void * V_3 ,
unsigned int * V_4 , unsigned int * V_5 ,
unsigned int V_6 [] , void * V_7 [] )
{
struct V_8 * V_9 = V_2 -> V_10 ;
* V_5 = 1 ;
V_9 -> V_11 = 188 * 4 ;
V_9 -> V_12 = V_13 ;
V_6 [ 0 ] = V_9 -> V_11 * V_9 -> V_12 ;
V_7 [ 0 ] = V_9 -> V_14 ;
* V_4 = V_13 ;
return 0 ;
}
static int F_2 ( struct V_15 * V_16 )
{
struct V_17 * V_18 = F_3 ( V_16 ) ;
struct V_8 * V_9 = V_16 -> V_1 -> V_10 ;
struct V_19 * V_20 = F_4 ( V_18 , struct V_19 , V_16 ) ;
return F_5 ( V_16 -> V_1 , V_9 , V_20 ) ;
}
static void F_6 ( struct V_15 * V_16 )
{
struct V_17 * V_18 = F_3 ( V_16 ) ;
struct V_8 * V_9 = V_16 -> V_1 -> V_10 ;
struct V_19 * V_20 = F_4 ( V_18 , struct V_19 , V_16 ) ;
struct V_21 * V_22 = & V_20 -> V_22 ;
if ( V_22 -> V_23 )
F_7 ( V_9 -> V_24 , V_22 -> V_25 , V_22 -> V_23 , V_22 -> V_26 ) ;
memset ( V_22 , 0 , sizeof( * V_22 ) ) ;
}
static void F_8 ( struct V_15 * V_16 )
{
struct V_17 * V_18 = F_3 ( V_16 ) ;
struct V_8 * V_9 = V_16 -> V_1 -> V_10 ;
struct V_19 * V_20 = F_4 ( V_18 , struct V_19 , V_16 ) ;
F_9 ( V_9 , V_20 ) ;
}
static int F_10 ( struct V_1 * V_2 , unsigned int V_27 )
{
struct V_8 * V_9 = V_2 -> V_10 ;
struct V_28 * V_29 = & V_9 -> V_30 ;
struct V_19 * V_20 ;
V_20 = F_11 ( V_29 -> V_31 . V_32 , struct V_19 , V_33 ) ;
F_12 ( V_9 , V_29 , V_20 ) ;
return 0 ;
}
static void F_13 ( struct V_1 * V_2 )
{
struct V_8 * V_9 = V_2 -> V_10 ;
struct V_28 * V_29 = & V_9 -> V_30 ;
unsigned long V_34 ;
F_14 ( V_9 ) ;
F_15 ( & V_9 -> V_35 , V_34 ) ;
while ( ! F_16 ( & V_29 -> V_31 ) ) {
struct V_19 * V_20 = F_11 ( V_29 -> V_31 . V_32 ,
struct V_19 , V_33 ) ;
F_17 ( & V_20 -> V_33 ) ;
F_18 ( & V_20 -> V_16 . V_36 , V_37 ) ;
}
F_19 ( & V_9 -> V_35 , V_34 ) ;
}
static int F_20 ( struct V_38 * V_39 , int V_40 )
{
struct V_8 * V_9 = V_39 -> V_41 -> V_42 ;
struct V_43 * V_44 = NULL ;
int V_45 = 0 ;
int V_46 ;
V_46 = F_21 ( & V_9 -> V_47 , V_39 ) ;
if ( ! V_46 ) {
F_22 ( V_48 L_1 , V_49 ) ;
return - V_50 ;
}
F_23 ( & V_9 -> V_51 -> V_52 ) ;
V_44 = F_24 ( V_9 , V_53 ) ;
if ( V_44 ) {
if ( V_40 ) {
V_9 -> V_47 . V_54 = V_46 ;
V_45 = V_44 -> V_55 ( V_44 ) ;
} else {
V_45 = V_44 -> V_56 ( V_44 ) ;
V_9 -> V_47 . V_54 = 0 ;
}
}
F_25 ( & V_9 -> V_51 -> V_52 ) ;
return V_45 ;
}
static void F_26 ( struct V_57 * V_51 , int V_58 )
{
struct V_59 * V_60 ;
struct V_61 * V_39 ;
if ( ! V_51 -> V_62 )
return;
V_60 = & V_51 -> V_62 -> V_47 ;
if ( ! V_60 )
return;
if ( V_60 -> V_63 <= 1 )
V_39 = F_27 ( V_60 , 1 ) ;
else
V_39 = F_27 ( V_60 , V_60 -> V_63 ) ;
if ( V_39 && V_39 -> V_41 . V_64 && V_39 -> V_41 . V_64 -> V_65 . V_66 )
V_39 -> V_41 . V_64 -> V_65 . V_66 ( V_39 -> V_41 . V_64 , V_58 ) ;
}
static int F_28 ( struct V_38 * V_39 )
{
static const T_1 V_67 [] = { V_68 , 0x38 , 0x39 } ;
static const T_1 V_69 [] = { V_70 , 0x80 } ;
static const T_1 V_71 [] = { V_72 , 0x40 } ;
static const T_1 V_73 [] = { V_74 , 0x24 , 0x20 } ;
static const T_1 V_75 [] = { V_76 , 0x33 } ;
static const T_1 V_77 [] = { V_78 , 0x32 } ;
F_29 ( V_39 , V_67 , sizeof( V_67 ) ) ;
F_30 ( 200 ) ;
F_29 ( V_39 , V_69 , sizeof( V_69 ) ) ;
F_29 ( V_39 , V_71 , sizeof( V_71 ) ) ;
F_29 ( V_39 , V_73 , sizeof( V_73 ) ) ;
F_29 ( V_39 , V_75 , sizeof( V_75 ) ) ;
F_29 ( V_39 , V_77 , sizeof( V_77 ) ) ;
return 0 ;
}
static int F_31 ( struct V_38 * V_39 )
{
static const T_1 V_67 [] = { V_68 , 0x38 , 0x38 } ;
static const T_1 V_69 [] = { V_70 , 0x80 } ;
static const T_1 V_71 [] = { V_72 , 0x40 } ;
static const T_1 V_73 [] = { V_74 , 0x28 , 0x20 } ;
static const T_1 V_75 [] = { V_76 , 0x33 } ;
static const T_1 V_77 [] = { V_78 , 0x32 } ;
F_29 ( V_39 , V_67 , sizeof( V_67 ) ) ;
F_30 ( 200 ) ;
F_29 ( V_39 , V_69 , sizeof( V_69 ) ) ;
F_29 ( V_39 , V_71 , sizeof( V_71 ) ) ;
F_29 ( V_39 , V_73 , sizeof( V_73 ) ) ;
F_29 ( V_39 , V_75 , sizeof( V_75 ) ) ;
F_29 ( V_39 , V_77 , sizeof( V_77 ) ) ;
return 0 ;
}
static int F_32 ( struct V_38 * V_39 )
{
static const T_1 V_67 [] = { 0x89 , 0x38 , 0x39 } ;
static const T_1 V_69 [] = { 0x50 , 0x80 } ;
static const T_1 V_71 [] = { 0x8E , 0x40 } ;
static const T_1 V_73 [] = { 0x67 , 0x10 , 0x23 , 0x00 , 0xFF , 0xFF ,
0x00 , 0xFF , 0x00 , 0x40 , 0x40 } ;
static const T_1 V_79 [] = { 0xB5 , 0x7A } ;
static const T_1 V_77 [] = { 0x75 , 0x32 } ;
F_29 ( V_39 , V_67 , sizeof( V_67 ) ) ;
F_30 ( 2000 ) ;
F_29 ( V_39 , V_69 , sizeof( V_69 ) ) ;
F_29 ( V_39 , V_71 , sizeof( V_71 ) ) ;
F_29 ( V_39 , V_73 , sizeof( V_73 ) ) ;
F_30 ( 2000 ) ;
F_29 ( V_39 , V_79 , sizeof( V_79 ) ) ;
F_29 ( V_39 , V_77 , sizeof( V_77 ) ) ;
return 0 ;
}
static int F_33 ( struct V_38 * V_39 )
{
static const T_1 V_67 [] = { 0x89 , 0x38 , 0x38 } ;
static const T_1 V_69 [] = { 0x50 , 0x80 } ;
static const T_1 V_71 [] = { 0x8E , 0x40 } ;
static const T_1 V_73 [] = { 0x67 , 0x10 , 0x20 , 0x00 , 0xFF , 0xFF ,
0x00 , 0xFF , 0x00 , 0x40 , 0x40 } ;
static const T_1 V_79 [] = { 0xB5 , 0x7A } ;
static const T_1 V_77 [] = { 0x75 , 0x32 } ;
F_29 ( V_39 , V_67 , sizeof( V_67 ) ) ;
F_30 ( 2000 ) ;
F_29 ( V_39 , V_69 , sizeof( V_69 ) ) ;
F_29 ( V_39 , V_71 , sizeof( V_71 ) ) ;
F_29 ( V_39 , V_73 , sizeof( V_73 ) ) ;
F_30 ( 2000 ) ;
F_29 ( V_39 , V_79 , sizeof( V_79 ) ) ;
F_29 ( V_39 , V_77 , sizeof( V_77 ) ) ;
return 0 ;
}
static int F_34 ( struct V_38 * V_39 , int V_80 )
{
struct V_8 * V_9 = V_39 -> V_41 -> V_42 ;
V_9 -> V_81 = V_80 ? 0x04 : 0x00 ;
return 0 ;
}
static int F_35 ( struct V_38 * V_39 , int V_82 )
{
struct V_8 * V_9 = V_39 -> V_41 -> V_42 ;
struct V_57 * V_51 = V_9 -> V_51 ;
F_36 ( 1 , L_2 , V_49 , V_82 ) ;
if ( V_82 == 0 )
F_37 ( V_83 , 8 ) ;
else
F_38 ( V_83 , 8 ) ;
return 0 ;
}
static int F_39 ( struct V_38 * V_39 , int V_80 )
{
struct V_8 * V_9 = V_39 -> V_41 -> V_42 ;
if ( V_80 )
V_9 -> V_81 |= 0x04 ;
else
V_9 -> V_81 &= ~ 0x04 ;
return 0 ;
}
static int F_40 ( struct V_38 * V_39 , int V_80 )
{
struct V_8 * V_9 = V_39 -> V_41 -> V_42 ;
V_9 -> V_81 = V_80 ? 0x04 : 0x00 ;
return 0 ;
}
static int F_41 ( struct V_38 * V_39 ,
int V_80 )
{
struct V_8 * V_9 = V_39 -> V_41 -> V_42 ;
V_9 -> V_81 = 0x02 ;
return 0 ;
}
static int F_42 ( struct V_38 * V_39 ,
enum V_84 V_85 )
{
struct V_8 * V_9 = V_39 -> V_41 -> V_42 ;
struct V_57 * V_51 = V_9 -> V_51 ;
if ( V_85 == V_86 )
F_43 ( V_83 , 0x000006fb ) ;
else
F_43 ( V_83 , 0x000006f9 ) ;
if ( V_51 -> V_87 )
return V_51 -> V_87 ( V_39 , V_85 ) ;
return 0 ;
}
static int F_44 ( struct V_38 * V_39 ,
enum V_84 V_85 )
{
struct V_8 * V_9 = V_39 -> V_41 -> V_42 ;
struct V_57 * V_51 = V_9 -> V_51 ;
if ( V_85 == V_86 ) {
F_36 ( 1 , L_3 ) ;
F_43 ( V_83 , 0x0000efff ) ;
}
if ( V_51 -> V_87 )
return V_51 -> V_87 ( V_39 , V_85 ) ;
return 0 ;
}
static int F_45 ( struct V_38 * V_39 ,
enum V_84 V_85 )
{
struct V_8 * V_9 = V_39 -> V_41 -> V_42 ;
struct V_57 * V_51 = V_9 -> V_51 ;
F_38 ( V_83 , 0x6040 ) ;
switch ( V_85 ) {
case V_88 :
F_37 ( V_83 , 0x20 ) ;
break;
case V_89 :
F_38 ( V_83 , 0x20 ) ;
break;
case V_86 :
F_37 ( V_83 , 0x20 ) ;
break;
}
if ( V_51 -> V_87 )
return V_51 -> V_87 ( V_39 , V_85 ) ;
return 0 ;
}
static int F_46 ( struct V_38 * V_39 ,
enum V_84 V_85 )
{
struct V_8 * V_9 = V_39 -> V_41 -> V_42 ;
struct V_57 * V_51 = V_9 -> V_51 ;
switch ( V_85 ) {
case V_88 :
F_36 ( 1 , L_4 ) ;
F_43 ( V_83 , 0x00001220 ) ;
break;
case V_89 :
F_36 ( 1 , L_5 ) ;
F_43 ( V_83 , 0x00001222 ) ;
break;
case V_86 :
F_36 ( 1 , L_3 ) ;
F_43 ( V_83 , 0x00001230 ) ;
break;
}
if ( V_51 -> V_87 )
return V_51 -> V_87 ( V_39 , V_85 ) ;
return 0 ;
}
static int F_47 ( T_1 V_90 , struct V_8 * V_9 )
{
struct V_38 * V_39 ;
struct V_61 * V_91 = NULL ;
struct V_92 V_93 ;
struct V_94 V_95 = {
. V_96 = & V_9 -> V_51 -> V_96 ,
. V_97 = V_90 ,
. V_98 = & V_93 ,
} ;
V_91 = F_27 ( & V_9 -> V_47 , 1 ) ;
if ( ! V_91 )
return - V_50 ;
if ( ! V_91 -> V_41 . V_64 ) {
F_22 ( V_48 L_6
L_7 ,
V_9 -> V_51 -> V_99 ) ;
return - V_50 ;
}
F_48 ( V_9 -> V_51 , & V_93 ) ;
V_39 = F_49 ( V_100 , V_91 -> V_41 . V_64 , & V_95 ) ;
if ( ! V_39 ) {
F_22 ( V_48 L_8 ,
V_9 -> V_51 -> V_99 ) ;
F_50 ( V_91 -> V_41 . V_64 ) ;
F_51 ( V_91 -> V_41 . V_64 ) ;
V_91 -> V_41 . V_64 = NULL ;
return - V_50 ;
}
F_22 ( V_101 L_9 ,
V_9 -> V_51 -> V_99 ) ;
return 0 ;
}
static int F_52 ( struct V_8 * V_9 , struct V_102 * V_95 )
{
struct V_38 * V_39 ;
struct V_61 * V_91 = NULL ;
V_91 = F_27 ( & V_9 -> V_47 , 1 ) ;
if ( ! V_91 )
return - V_50 ;
if ( ! V_91 -> V_41 . V_64 ) {
F_22 ( V_48 L_6
L_10 ,
V_9 -> V_51 -> V_99 ) ;
return - V_50 ;
}
V_39 = F_49 ( V_103 , V_91 -> V_41 . V_64 , & V_9 -> V_51 -> V_96 ,
V_95 ) ;
if ( ! V_39 ) {
F_22 ( V_48 L_11 ,
V_9 -> V_51 -> V_99 ) ;
F_50 ( V_91 -> V_41 . V_64 ) ;
F_51 ( V_91 -> V_41 . V_64 ) ;
V_91 -> V_41 . V_64 = NULL ;
return - V_50 ;
}
F_22 ( V_101 L_12 , V_9 -> V_51 -> V_99 ) ;
return 0 ;
}
static int F_53 ( struct V_38 * V_39 ,
int V_80 )
{
struct V_8 * V_9 = V_39 -> V_41 -> V_42 ;
V_9 -> V_81 = 0x2 ;
return 0 ;
}
static int F_54 ( struct V_38 * V_39 ,
int V_80 )
{
struct V_8 * V_9 = V_39 -> V_41 -> V_42 ;
V_9 -> V_81 = 0 ;
return 0 ;
}
static int F_55 ( struct V_38 * V_39 )
{
struct V_8 * V_9 = V_39 -> V_41 -> V_42 ;
struct V_57 * V_51 = V_9 -> V_51 ;
F_43 ( V_104 , 0 ) ;
F_56 ( 10 ) ;
F_43 ( V_104 , 1 ) ;
F_56 ( 10 ) ;
return 0 ;
}
static int F_57 ( struct V_38 * V_39 ,
int V_80 )
{
struct V_8 * V_9 = V_39 -> V_41 -> V_42 ;
V_9 -> V_81 = 4 ;
return 0 ;
}
static int F_58 ( struct V_8 * V_9 )
{
struct V_57 * V_51 = V_9 -> V_51 ;
struct V_61 * V_39 = NULL ;
int V_105 ;
F_59 ( & V_9 -> V_47 . V_52 ) ;
F_60 ( & V_9 -> V_47 . V_106 ) ;
if ( ! V_51 -> V_107 . V_108 )
return - V_109 ;
F_22 ( V_101 L_13 , V_49 ,
V_51 -> V_107 . V_108 ) ;
for ( V_105 = 1 ; V_105 <= V_51 -> V_107 . V_108 ; V_105 ++ ) {
V_39 = F_61 ( & V_9 -> V_47 , V_105 ) ;
if ( ! V_39 ) {
F_22 ( V_48 L_14 , V_49 ) ;
F_62 ( & V_9 -> V_47 ) ;
return - V_110 ;
}
}
return 0 ;
}
static int F_63 ( struct V_38 * V_39 )
{
struct V_111 * V_112 = & V_39 -> V_113 ;
struct V_8 * V_9 = V_39 -> V_41 -> V_42 ;
T_1 V_20 [ 4 ] ;
T_2 div ;
struct V_114 V_115 = {
. V_90 = 0x61 ,
. V_34 = 0 ,
. V_20 = V_20 ,
. V_116 = sizeof( V_20 ) } ;
div = V_112 -> V_117 / 125 ;
V_20 [ 0 ] = ( div >> 8 ) & 0x7f ;
V_20 [ 1 ] = div & 0xff ;
V_20 [ 2 ] = 0x84 ;
V_20 [ 3 ] = 0x00 ;
if ( V_112 -> V_117 < 1500000 )
V_20 [ 3 ] |= 0x10 ;
if ( V_39 -> V_65 . V_66 )
V_39 -> V_65 . V_66 ( V_39 , 1 ) ;
if ( F_64 ( & V_9 -> V_51 -> V_96 , & V_115 , 1 ) != 1 )
return - V_118 ;
return 0 ;
}
static int F_65 ( struct V_38 * V_39 ,
enum V_119 V_120 )
{
struct V_8 * V_9 = V_39 -> V_41 -> V_42 ;
struct V_57 * V_51 = V_9 -> V_51 ;
F_38 ( V_83 , 0x0800 ) ;
switch ( V_120 ) {
case V_121 :
F_38 ( V_83 , 0x08 ) ;
break;
case V_122 :
F_37 ( V_83 , 0x08 ) ;
break;
default:
return - V_50 ;
}
return 0 ;
}
static int F_66 ( struct V_38 * V_39 ,
enum V_84 V_85 )
{
struct V_8 * V_9 = V_39 -> V_41 -> V_42 ;
struct V_57 * V_51 = V_9 -> V_51 ;
T_1 V_123 ;
struct V_114 V_115 = {
. V_90 = 8 ,
. V_34 = 0 ,
. V_20 = & V_123 ,
. V_116 = sizeof( V_123 ) } ;
F_38 ( V_83 , 0x8000 ) ;
switch ( V_85 ) {
case V_86 :
break;
case V_88 :
V_123 = V_124 | V_125 ;
F_37 ( V_83 , 0x80 ) ;
break;
case V_89 :
V_123 = V_124 | V_125 | V_126 ;
F_37 ( V_83 , 0x80 ) ;
break;
default:
return - V_50 ;
}
return ( F_64 ( & V_9 -> V_51 -> V_96 , & V_115 , 1 ) == 1 ) ? 0 : - V_118 ;
}
static int F_67 ( struct V_38 * V_39 ,
T_2 V_127 , T_2 V_128 )
{
T_1 V_129 = 0 ;
T_1 V_130 = 0 ;
if ( V_127 < 1500000 ) {
V_129 = 0xb7 ;
V_130 = 0x47 ;
} else if ( V_127 < 3000000 ) {
V_129 = 0xb7 ;
V_130 = 0x4b ;
} else if ( V_127 < 7000000 ) {
V_129 = 0xb7 ;
V_130 = 0x4f ;
} else if ( V_127 < 14000000 ) {
V_129 = 0xb7 ;
V_130 = 0x53 ;
} else if ( V_127 < 30000000 ) {
V_129 = 0xb6 ;
V_130 = 0x53 ;
} else if ( V_127 < 45000000 ) {
V_129 = 0xb4 ;
V_130 = 0x51 ;
}
F_68 ( V_39 , 0x13 , V_129 ) ;
F_68 ( V_39 , 0x14 , V_130 ) ;
F_68 ( V_39 , 0x1f , ( V_128 >> 16 ) & 0xff ) ;
F_68 ( V_39 , 0x20 , ( V_128 >> 8 ) & 0xff ) ;
F_68 ( V_39 , 0x21 , V_128 & 0xf0 ) ;
return 0 ;
}
static int F_69 ( struct V_8 * V_9 )
{
struct V_57 * V_51 = V_9 -> V_51 ;
struct V_61 * V_91 , * V_131 = NULL ;
int V_132 = 0 ;
int V_133 = - V_50 ;
if ( 0 != V_51 -> V_134 ) {
F_22 ( V_48 L_15 , V_51 -> V_99 ) ;
goto V_135;
}
V_91 = F_27 ( & V_9 -> V_47 , 1 ) ;
if ( ! V_91 )
goto V_135;
V_9 -> V_47 . V_63 = 0 ;
V_51 -> V_136 = F_26 ;
switch ( V_51 -> V_137 ) {
case V_138 :
V_91 -> V_41 . V_64 = F_49 ( V_139 ,
& V_140 ,
& V_51 -> V_96 ) ;
if ( V_91 -> V_41 . V_64 != NULL ) {
if ( ! F_49 ( V_141 , V_91 -> V_41 . V_64 ,
0x61 , & V_51 -> V_96 ,
V_142 ) )
goto V_135;
}
break;
case V_143 :
case V_144 :
case V_145 :
case V_146 :
V_91 -> V_41 . V_64 = F_49 ( V_139 ,
& V_140 ,
& V_51 -> V_96 ) ;
if ( V_91 -> V_41 . V_64 != NULL ) {
if ( ! F_49 ( V_141 , V_91 -> V_41 . V_64 ,
0x60 , & V_51 -> V_96 ,
V_147 ) )
goto V_135;
}
break;
case V_148 :
case V_149 :
case V_150 :
case V_151 :
V_91 -> V_41 . V_64 = F_49 ( V_139 ,
& V_152 ,
& V_51 -> V_96 ) ;
if ( V_91 -> V_41 . V_64 != NULL ) {
if ( ! F_49 ( V_153 , V_91 -> V_41 . V_64 ,
& V_51 -> V_96 , 0x61 ,
V_154 ) )
goto V_135;
}
break;
case V_155 :
V_91 -> V_41 . V_64 = F_49 ( V_139 ,
& V_152 ,
& V_51 -> V_96 ) ;
if ( V_91 -> V_41 . V_64 != NULL ) {
if ( ! F_49 ( V_153 , V_91 -> V_41 . V_64 ,
& V_51 -> V_96 , 0x61 ,
V_156 ) )
goto V_135;
}
break;
case V_157 :
V_132 = 1 ;
V_9 -> V_47 . V_63 = 2 ;
V_91 -> V_41 . V_64 = F_49 ( V_158 ,
& V_159 ,
& V_9 -> V_51 -> V_96 ) ;
if ( V_91 -> V_41 . V_64 ) {
if ( ! F_49 ( V_160 ,
V_91 -> V_41 . V_64 ,
& V_9 -> V_51 -> V_96 ,
0x08 , V_161 , 0x00 , false ) )
goto V_135;
}
V_131 = F_27 ( & V_9 -> V_47 , 2 ) ;
if ( ! V_131 )
goto V_135;
V_131 -> V_41 . V_64 = F_49 ( V_139 ,
& V_152 ,
& V_9 -> V_51 -> V_96 ) ;
if ( V_131 -> V_41 . V_64 ) {
V_131 -> V_41 . V_64 -> V_162 = 1 ;
if ( ! F_49 ( V_153 ,
V_131 -> V_41 . V_64 ,
& V_9 -> V_51 -> V_96 ,
0x61 , V_154 ) )
goto V_135;
}
break;
case V_163 :
V_91 -> V_41 . V_64 = F_49 ( V_164 ,
& V_165 ,
& V_51 -> V_96 ) ;
if ( V_91 -> V_41 . V_64 != NULL ) {
if ( ! F_49 ( V_141 , V_91 -> V_41 . V_64 ,
0x60 , NULL , V_147 ) )
goto V_135;
break;
}
V_91 -> V_41 . V_64 = F_49 ( V_166 ,
& V_167 ,
& V_51 -> V_96 ) ;
if ( V_91 -> V_41 . V_64 != NULL ) {
if ( ! F_49 ( V_141 , V_91 -> V_41 . V_64 ,
0x60 , NULL , V_147 ) )
goto V_135;
}
break;
case V_168 :
V_91 -> V_41 . V_64 = F_49 ( V_164 ,
& V_169 ,
& V_51 -> V_96 ) ;
if ( V_91 -> V_41 . V_64 != NULL ) {
if ( ! F_49 ( V_141 , V_91 -> V_41 . V_64 ,
0x61 , NULL , V_147 ) )
goto V_135;
break;
}
V_91 -> V_41 . V_64 = F_49 ( V_166 ,
& V_167 ,
& V_51 -> V_96 ) ;
if ( V_91 -> V_41 . V_64 != NULL ) {
if ( ! F_49 ( V_141 , V_91 -> V_41 . V_64 ,
0x61 , NULL , V_147 ) )
goto V_135;
}
break;
case V_170 :
V_91 -> V_41 . V_64 = F_49 ( V_164 ,
& V_165 ,
& V_51 -> V_96 ) ;
if ( V_91 -> V_41 . V_64 != NULL ) {
if ( ! F_49 ( V_141 , V_91 -> V_41 . V_64 ,
0x61 , NULL , V_171 ) )
goto V_135;
}
break;
case V_172 :
case V_173 :
case V_174 :
V_91 -> V_41 . V_64 = F_49 ( V_164 ,
& V_175 ,
& V_51 -> V_96 ) ;
if ( V_91 -> V_41 . V_64 != NULL ) {
if ( ! F_49 ( V_141 , V_91 -> V_41 . V_64 ,
0x61 , NULL , V_176 ) )
goto V_135;
}
break;
case V_177 :
#if F_70 ( V_178 )
V_91 -> V_41 . V_64 = F_49 ( V_164 , & V_179 ,
& V_9 -> V_180 -> V_181 ) ;
if ( V_91 -> V_41 . V_64 != NULL ) {
if ( ! F_49 ( V_153 , V_91 -> V_41 . V_64 ,
& V_51 -> V_96 , 0x61 ,
V_154 ) )
goto V_135;
}
#else
F_22 ( V_48 L_16 ,
V_51 -> V_99 ) ;
#endif
break;
case V_182 :
V_91 -> V_41 . V_64 = F_49 ( V_166 ,
& V_183 ,
& V_51 -> V_96 ) ;
if ( V_91 -> V_41 . V_64 != NULL ) {
if ( ! F_49 ( V_153 , V_91 -> V_41 . V_64 ,
& V_51 -> V_96 , 0x61 ,
V_184 ) )
goto V_135;
}
break;
case V_185 :
V_91 -> V_41 . V_64 = F_49 ( V_166 ,
& V_186 ,
& V_51 -> V_96 ) ;
if ( V_91 -> V_41 . V_64 == NULL )
V_91 -> V_41 . V_64 = F_49 ( V_164 ,
& V_187 ,
& V_51 -> V_96 ) ;
if ( V_91 -> V_41 . V_64 )
V_91 -> V_41 . V_64 -> V_65 . V_66 = NULL ;
if ( F_47 ( 0x61 , V_9 ) < 0 )
goto V_135;
break;
case V_188 :
V_91 -> V_41 . V_64 = F_49 ( V_189 , & V_190 ,
& V_51 -> V_96 ) ;
if ( V_91 -> V_41 . V_64 != NULL ) {
if ( ! F_49 ( V_153 , V_91 -> V_41 . V_64 ,
& V_51 -> V_96 , 0x61 ,
V_191 ) )
goto V_135;
}
break;
case V_192 :
V_9 -> V_81 = 0x08 ;
F_37 ( V_83 , 1 ) ;
F_71 ( 100 ) ;
F_38 ( V_83 , 1 ) ;
F_71 ( 200 ) ;
V_193 . V_194 = F_35 ;
V_91 -> V_41 . V_64 = F_49 ( V_195 ,
& V_193 ,
& V_51 -> V_96 ) ;
if ( V_91 -> V_41 . V_64 != NULL ) {
if ( ! F_49 ( V_153 , V_91 -> V_41 . V_64 ,
& V_51 -> V_96 , 0x61 ,
V_196 ) )
goto V_135;
}
break;
case V_197 :
V_9 -> V_81 = 0x08 ;
F_37 ( V_83 , 1 ) ;
F_71 ( 100 ) ;
F_38 ( V_83 , 9 ) ;
F_71 ( 200 ) ;
V_91 -> V_41 . V_64 = F_49 ( V_195 ,
& V_193 ,
& V_51 -> V_96 ) ;
if ( V_91 -> V_41 . V_64 != NULL ) {
if ( ! F_49 ( V_153 , V_91 -> V_41 . V_64 ,
& V_51 -> V_96 , 0x61 ,
V_191 ) )
goto V_135;
}
break;
case V_198 :
V_9 -> V_81 = 0x08 ;
F_37 ( V_83 , 1 ) ;
F_71 ( 100 ) ;
F_38 ( V_83 , 1 ) ;
F_71 ( 200 ) ;
V_91 -> V_41 . V_64 = F_49 ( V_195 ,
& V_199 ,
& V_51 -> V_96 ) ;
if ( V_91 -> V_41 . V_64 != NULL ) {
if ( ! F_49 ( V_153 , V_91 -> V_41 . V_64 ,
& V_51 -> V_96 , 0x61 ,
V_200 ) )
goto V_135;
if ( ! F_49 ( V_201 , V_91 -> V_41 . V_64 ,
& V_51 -> V_96 , 0x43 ) )
goto V_135;
}
break;
case V_202 :
V_9 -> V_81 = 0x08 ;
F_37 ( V_83 , 1 ) ;
F_71 ( 100 ) ;
F_38 ( V_83 , 1 ) ;
F_71 ( 200 ) ;
V_91 -> V_41 . V_64 = F_49 ( V_195 ,
& V_203 ,
& V_51 -> V_96 ) ;
if ( V_91 -> V_41 . V_64 != NULL ) {
if ( ! F_49 ( V_153 , V_91 -> V_41 . V_64 ,
& V_51 -> V_96 , 0x61 ,
V_200 ) )
goto V_135;
if ( ! F_49 ( V_201 , V_91 -> V_41 . V_64 ,
& V_51 -> V_96 , 0x43 ) )
goto V_135;
}
break;
case V_204 :
V_91 -> V_41 . V_64 = F_49 ( V_205 ,
& V_206 ,
& V_51 -> V_96 ) ;
if ( V_91 -> V_41 . V_64 != NULL ) {
if ( ! F_49 ( V_153 , V_91 -> V_41 . V_64 ,
& V_51 -> V_96 , 0x61 ,
V_207 ) )
goto V_135;
}
break;
case V_208 :
case V_209 :
V_91 -> V_41 . V_64 = F_49 ( V_158 ,
& V_159 ,
& V_51 -> V_96 ) ;
if ( V_91 -> V_41 . V_64 ) {
bool V_210 ;
if ( V_51 -> V_211 == 92001 )
V_210 = true ;
else
V_210 = false ;
if ( ! F_49 ( V_160 , V_91 -> V_41 . V_64 ,
& V_51 -> V_96 , 0x08 , V_161 , 0x00 ,
V_210 ) )
goto V_135;
}
break;
case V_212 :
V_91 -> V_41 . V_64 = F_49 ( V_158 ,
& V_213 ,
& V_51 -> V_96 ) ;
if ( V_91 -> V_41 . V_64 ) {
V_51 -> V_87 = V_91 -> V_41 . V_64 -> V_65 . V_214 ;
V_91 -> V_41 . V_64 -> V_65 . V_214 = F_42 ;
}
break;
case V_215 :
V_91 -> V_41 . V_64 = F_49 ( V_158 ,
& V_216 ,
& V_51 -> V_96 ) ;
if ( V_91 -> V_41 . V_64 ) {
V_51 -> V_87 = V_91 -> V_41 . V_64 -> V_65 . V_214 ;
V_91 -> V_41 . V_64 -> V_65 . V_214 = F_44 ;
}
break;
case V_217 :
V_91 -> V_41 . V_64 = F_49 ( V_218 ,
& V_219 ,
& V_51 -> V_96 ) ;
if ( V_91 -> V_41 . V_64 != NULL ) {
if ( ! F_49 ( V_220 , V_91 -> V_41 . V_64 ,
& V_51 -> V_96 ,
& V_221 ) )
goto V_135;
}
break;
case V_222 :
V_91 -> V_41 . V_64 = F_49 ( V_218 ,
& V_223 ,
& V_51 -> V_96 ) ;
if ( V_91 -> V_41 . V_64 != NULL ) {
struct V_38 * V_39 ;
struct V_94 V_95 = {
. V_96 = & V_51 -> V_96 ,
. V_97 = 0x61 ,
} ;
static struct V_92 V_93 = {
. V_224 = V_225 ,
. V_226 = 64 ,
. V_227 = V_228 ,
} ;
V_39 = F_49 ( V_100 ,
V_91 -> V_41 . V_64 , & V_95 ) ;
if ( V_39 != NULL && V_39 -> V_65 . V_229 . V_230 != NULL )
V_39 -> V_65 . V_229 . V_230 ( V_39 , & V_93 ) ;
}
break;
case V_231 :
case V_232 :
V_91 -> V_41 . V_64 = F_49 ( V_166 ,
& V_233 ,
& V_51 -> V_96 ) ;
if ( V_91 -> V_41 . V_64 ) {
V_91 -> V_41 . V_64 -> V_65 . V_66 = NULL ;
if ( F_47 ( 0x61 , V_9 ) < 0 )
goto V_135;
}
break;
case V_234 :
case V_235 :
V_91 -> V_41 . V_64 = F_49 ( V_166 ,
& V_233 ,
& V_51 -> V_96 ) ;
if ( V_91 -> V_41 . V_64 ) {
struct V_102 V_95 = {
. V_236 = 0x61 ,
. V_237 = 0 ,
. V_238 = 134 ,
. V_239 = 1 ,
. V_240 = 4560
} ;
V_91 -> V_41 . V_64 -> V_65 . V_66 = NULL ;
if ( F_52 ( V_9 , & V_95 ) < 0 )
goto V_135;
}
break;
case V_241 :
V_9 -> V_81 = 0x00 ;
V_91 -> V_41 . V_64 = F_49 ( V_166 ,
& V_242 ,
& V_51 -> V_96 ) ;
if ( F_47 ( 0x61 , V_9 ) < 0 )
goto V_135;
break;
case V_243 :
V_91 -> V_41 . V_64 = F_49 ( V_218 ,
& V_244 ,
& V_51 -> V_96 ) ;
if ( F_47 ( 0x61 , V_9 ) < 0 )
goto V_135;
break;
case V_245 :
V_91 -> V_41 . V_64 = F_49 ( V_246 ,
& V_247 ,
& V_51 -> V_96 ) ;
if ( V_91 -> V_41 . V_64 != NULL ) {
if ( ! F_49 ( V_220 , V_91 -> V_41 . V_64 ,
& V_51 -> V_96 ,
& V_248 ) )
goto V_135;
}
break;
case V_249 :
V_132 = 1 ;
V_9 -> V_47 . V_63 = 2 ;
V_91 -> V_41 . V_64 = F_49 ( V_250 ,
& V_251 ,
& V_9 -> V_51 -> V_96 ) ;
if ( V_91 -> V_41 . V_64 ) {
if ( ! F_49 ( V_160 ,
V_91 -> V_41 . V_64 ,
& V_9 -> V_51 -> V_96 ,
0x08 , V_161 , 0x00 , false ) )
goto V_135;
}
V_131 = F_27 ( & V_9 -> V_47 , 2 ) ;
if ( ! V_131 )
goto V_135;
V_131 -> V_41 . V_64 = F_49 ( V_139 ,
& V_152 ,
& V_9 -> V_51 -> V_96 ) ;
if ( V_131 -> V_41 . V_64 ) {
V_131 -> V_41 . V_64 -> V_162 = 1 ;
if ( ! F_49 ( V_153 ,
V_131 -> V_41 . V_64 ,
& V_9 -> V_51 -> V_96 ,
0x61 , V_154 ) )
goto V_135;
}
break;
case V_252 :
V_91 -> V_41 . V_64 = F_49 ( V_250 ,
& V_251 ,
& V_9 -> V_51 -> V_96 ) ;
if ( V_91 -> V_41 . V_64 ) {
if ( ! F_49 ( V_160 ,
V_91 -> V_41 . V_64 ,
& V_9 -> V_51 -> V_96 ,
0x08 , V_161 , 0x00 , false ) )
goto V_135;
}
break;
case V_253 :
case V_254 :
case V_255 :
V_91 -> V_41 . V_64 = F_49 ( V_256 ,
& V_257 ,
& V_51 -> V_96 ) ;
if ( V_91 -> V_41 . V_64 != NULL ) {
if ( ! F_49 ( V_141 , V_91 -> V_41 . V_64 , 0x60 ,
& V_51 -> V_96 , V_258 ) )
goto V_135;
V_51 -> V_87 = V_91 -> V_41 . V_64 -> V_65 . V_214 ;
V_91 -> V_41 . V_64 -> V_65 . V_214 = F_45 ;
} else {
V_91 -> V_41 . V_64 = F_49 ( V_259 ,
& V_260 ,
& V_51 -> V_96 ) ;
if ( V_91 -> V_41 . V_64 != NULL ) {
if ( ! F_49 ( V_261 , V_91 -> V_41 . V_64 , 0x61 ,
& V_51 -> V_96 ) )
goto V_135;
V_51 -> V_87 = V_91 -> V_41 . V_64 -> V_65 . V_214 ;
V_91 -> V_41 . V_64 -> V_65 . V_214 = F_45 ;
}
}
break;
case V_262 :
V_91 -> V_41 . V_64 = F_49 ( V_250 ,
& V_263 ,
& V_51 -> V_96 ) ;
if ( V_91 -> V_41 . V_64 != NULL )
V_91 -> V_41 . V_64 -> V_65 . V_214 = F_45 ;
break;
case V_264 :
V_91 -> V_41 . V_64 = F_49 ( V_265 ,
& V_266 ,
& V_51 -> V_96 ) ;
if ( V_91 -> V_41 . V_64 != NULL ) {
F_49 ( V_267 , V_91 -> V_41 . V_64 ,
& V_268 , & V_51 -> V_96 ) ;
V_91 -> V_41 . V_64 -> V_65 . V_214 =
F_45 ;
}
break;
case V_269 :
case V_270 :
case V_271 :
case V_272 :
V_91 -> V_41 . V_64 = F_49 ( V_250 ,
& V_251 ,
& V_51 -> V_96 ) ;
if ( V_91 -> V_41 . V_64 != NULL )
V_91 -> V_41 . V_64 -> V_65 . V_214 = F_45 ;
break;
case V_273 :
V_91 -> V_41 . V_64 = F_49 ( V_166 ,
& V_274 ,
& V_51 -> V_96 ) ;
if ( V_91 -> V_41 . V_64 ) {
V_91 -> V_41 . V_64 -> V_65 . V_66 = NULL ;
if ( F_47 ( 0x61 , V_9 ) < 0 )
goto V_135;
}
break;
case V_275 : {
struct V_276 * V_229 = NULL ;
V_91 -> V_41 . V_64 = F_49 ( V_277 ,
& V_278 ,
& V_51 -> V_96 , 0 ) ;
if ( V_91 -> V_41 . V_64 != NULL ) {
if ( ! F_49 ( V_279 , V_91 -> V_41 . V_64 ,
& V_280 ,
& V_51 -> V_96 ) )
goto V_135;
V_229 = & V_91 -> V_41 . V_64 -> V_65 . V_229 ;
V_229 -> V_281 = V_282 ;
V_229 -> V_283 = V_284 ;
V_229 -> V_285 = V_286 ;
V_229 -> V_287 = V_288 ;
V_51 -> V_87 =
V_91 -> V_41 . V_64 -> V_65 . V_214 ;
V_91 -> V_41 . V_64 -> V_65 . V_214 =
F_45 ;
}
break;
}
case V_289 :
V_9 -> V_81 = 0x08 ;
F_38 ( V_83 , 0x0101 ) ;
F_37 ( V_83 , 0x01 ) ;
F_71 ( 100 ) ;
F_38 ( V_83 , 0x01 ) ;
F_71 ( 200 ) ;
V_91 -> V_41 . V_64 = F_49 ( V_256 ,
& V_290 ,
& V_9 -> V_51 -> V_96 ) ;
if ( V_91 -> V_41 . V_64 ) {
V_91 -> V_41 . V_64 -> V_65 . V_229 . V_291 =
F_63 ;
V_91 -> V_41 . V_64 -> V_292 =
& V_9 -> V_51 -> V_96 ;
V_91 -> V_41 . V_64 -> V_65 . V_214 =
F_66 ;
V_91 -> V_41 . V_64 -> V_65 . V_293 =
F_65 ;
}
break;
case V_294 :
V_9 -> V_81 = 0x00 ;
V_91 -> V_41 . V_64 = F_49 ( V_295 ,
& V_296 ,
& V_51 -> V_96 ) ;
if ( V_91 -> V_41 . V_64 ) {
V_51 -> V_87 =
V_91 -> V_41 . V_64 -> V_65 . V_214 ;
V_91 -> V_41 . V_64 -> V_65 . V_214 =
F_46 ;
}
break;
default:
F_22 ( V_48 L_17 ,
V_51 -> V_99 ) ;
break;
}
if ( ( NULL == V_91 -> V_41 . V_64 ) || ( V_131 && NULL == V_131 -> V_41 . V_64 ) ) {
F_22 ( V_48
L_18 ,
V_51 -> V_99 ) ;
goto V_135;
}
V_91 -> V_41 . V_64 -> V_297 = V_298 ;
V_91 -> V_41 . V_64 -> V_65 . V_299 = F_20 ;
if ( V_131 )
V_131 -> V_41 . V_64 -> V_65 . V_299 = F_20 ;
F_72 ( V_51 , V_51 , V_300 , 0 ) ;
V_133 = F_73 ( & V_9 -> V_47 , V_301 , V_9 ,
& V_9 -> V_24 -> V_9 , V_302 , V_132 ) ;
if ( V_133 )
goto V_135;
return V_133 ;
V_135:
V_51 -> V_136 = NULL ;
F_62 ( & V_9 -> V_47 ) ;
return V_133 ;
}
static int F_74 ( struct V_43 * V_44 )
{
struct V_57 * V_51 = V_44 -> V_51 ;
int V_303 = 0 ;
F_36 ( 1 , L_19 , V_49 ) ;
switch ( V_51 -> V_137 ) {
case V_151 :
F_38 ( V_83 , 0x00000080 ) ;
F_30 ( 1000 ) ;
F_37 ( V_83 , 0x00000080 ) ;
F_30 ( 50 ) ;
F_38 ( V_83 , 0x00000080 ) ;
F_30 ( 1000 ) ;
F_37 ( V_83 , 0x00000004 ) ;
F_30 ( 1000 ) ;
break;
case V_157 :
case V_249 :
F_38 ( V_83 , 0x00000080 ) ;
F_30 ( 1000 ) ;
F_37 ( V_83 , 0x00000080 ) ;
F_30 ( 50 ) ;
F_38 ( V_83 , 0x00000080 ) ;
F_30 ( 1000 ) ;
switch ( V_51 -> V_62 -> V_47 . V_54 ) {
case 1 :
F_38 ( V_83 , 0x00000004 ) ;
F_43 ( V_104 , 1 ) ;
V_51 -> V_62 -> V_81 = 0x02 ;
break;
case 2 :
F_43 ( V_104 , 0 ) ;
F_37 ( V_83 , 0x00000004 ) ;
V_51 -> V_62 -> V_81 = 0x0c ;
break;
}
F_30 ( 1000 ) ;
break;
case V_235 :
F_43 ( V_304 , 0x0101 ) ;
break;
default:
V_303 = - V_109 ;
}
return V_303 ;
}
static int F_75 ( struct V_43 * V_44 )
{
struct V_57 * V_51 = V_44 -> V_51 ;
int V_303 = 0 ;
F_36 ( 1 , L_19 , V_49 ) ;
switch ( V_51 -> V_137 ) {
case V_151 :
break;
case V_157 :
case V_249 :
break;
default:
V_303 = - V_109 ;
}
return V_303 ;
}
static int F_76 ( struct V_43 * V_44 )
{
struct V_57 * V_51 = V_44 -> V_51 ;
struct V_8 * V_9 = V_44 -> V_51 -> V_62 ;
int V_303 ;
struct V_61 * V_39 ;
int V_105 ;
F_36 ( 1 , L_19 , V_49 ) ;
F_36 ( 1 , L_20 ,
V_51 -> V_137 ,
V_51 -> V_99 ,
V_51 -> V_305 ,
V_51 -> V_306 ) ;
V_303 = - V_109 ;
if ( ! ( V_51 -> V_107 . V_307 & V_53 ) )
goto V_308;
V_303 = F_77 ( V_9 ) ;
if ( 0 != V_303 )
goto V_308;
F_22 ( V_101 L_21 , V_51 -> V_99 ) ;
V_9 -> V_81 = 0x0c ;
V_303 = F_58 ( V_9 ) ;
if ( V_303 )
goto V_308;
V_303 = - V_109 ;
for ( V_105 = 1 ; V_105 <= V_51 -> V_107 . V_108 ; V_105 ++ ) {
struct V_1 * V_2 ;
V_39 = F_27 ( & V_51 -> V_62 -> V_47 , V_105 ) ;
if ( V_39 == NULL ) {
F_22 ( V_48 L_22 ,
V_49 , V_105 ) ;
goto V_309;
}
V_2 = & V_39 -> V_41 . V_310 ;
V_2 -> type = V_311 ;
V_2 -> V_312 = V_313 | V_314 | V_315 | V_316 ;
V_2 -> V_317 = V_318 ;
V_2 -> V_319 = 2 ;
V_2 -> V_10 = V_9 ;
V_2 -> V_320 = sizeof( struct V_19 ) ;
V_2 -> V_65 = & V_321 ;
V_2 -> V_322 = & V_323 ;
V_2 -> V_324 = V_325 ;
V_2 -> V_52 = & V_51 -> V_52 ;
V_303 = F_78 ( V_2 ) ;
if ( V_303 < 0 )
goto V_309;
V_39 -> V_41 . V_99 = V_9 -> V_51 -> V_99 ;
}
V_303 = F_69 ( V_9 ) ;
if ( V_303 )
F_22 ( V_48 L_23 ,
V_51 -> V_99 , V_303 ) ;
return V_303 ;
V_309:
F_62 ( & V_51 -> V_62 -> V_47 ) ;
V_308:
return V_303 ;
}
static int F_79 ( struct V_43 * V_44 )
{
struct V_57 * V_51 = V_44 -> V_51 ;
struct V_8 * V_9 = V_44 -> V_51 -> V_62 ;
F_36 ( 1 , L_19 , V_49 ) ;
F_80 ( & V_9 -> V_47 ) ;
F_81 ( V_9 ) ;
V_51 -> V_136 = NULL ;
return 0 ;
}
static int T_3 F_82 ( void )
{
F_22 ( V_101 L_24 ,
V_326 ) ;
return F_83 ( & V_327 ) ;
}
static void T_4 F_84 ( void )
{
F_85 ( & V_327 ) ;
}
