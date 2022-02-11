static int F_1 ( struct V_1 * V_2 ,
unsigned int * V_3 , unsigned int * V_4 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
V_6 -> V_8 = 188 * 4 ;
V_6 -> V_9 = V_10 ;
* V_4 = V_6 -> V_8 * V_6 -> V_9 ;
* V_3 = V_10 ;
return 0 ;
}
static int F_2 ( struct V_1 * V_2 ,
struct V_11 * V_12 , enum V_13 V_14 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
return F_3 ( V_2 , V_6 , (struct V_15 * ) V_12 , V_14 ) ;
}
static void F_4 ( struct V_1 * V_2 , struct V_11 * V_12 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
F_5 ( V_6 , (struct V_15 * ) V_12 ) ;
}
static void F_6 ( struct V_1 * V_2 ,
struct V_11 * V_12 )
{
F_7 ( V_2 , (struct V_15 * ) V_12 ) ;
}
static int F_8 ( struct V_16 * V_17 , int V_18 )
{
struct V_5 * V_6 = V_17 -> V_19 -> V_20 ;
struct V_21 * V_22 = NULL ;
int V_23 = 0 ;
int V_24 ;
V_24 = F_9 ( & V_6 -> V_25 , V_17 ) ;
if ( ! V_24 ) {
F_10 ( V_26 L_1 , V_27 ) ;
return - V_28 ;
}
F_11 ( & V_6 -> V_29 -> V_30 ) ;
V_22 = F_12 ( V_6 , V_31 ) ;
if ( V_22 ) {
if ( V_18 ) {
V_6 -> V_25 . V_32 = V_24 ;
V_23 = V_22 -> V_33 ( V_22 ) ;
} else {
V_23 = V_22 -> V_34 ( V_22 ) ;
V_6 -> V_25 . V_32 = 0 ;
}
}
F_13 ( & V_6 -> V_29 -> V_30 ) ;
return V_23 ;
}
static void F_14 ( struct V_35 * V_29 , int V_36 )
{
struct V_37 * V_38 ;
struct V_39 * V_17 ;
if ( ! V_29 -> V_40 )
return;
V_38 = & V_29 -> V_40 -> V_25 ;
if ( ! V_38 )
return;
if ( V_38 -> V_41 <= 1 )
V_17 = F_15 ( V_38 , 1 ) ;
else
V_17 = F_15 ( V_38 , V_38 -> V_41 ) ;
if ( V_17 && V_17 -> V_19 . V_42 && V_17 -> V_19 . V_42 -> V_43 . V_44 )
V_17 -> V_19 . V_42 -> V_43 . V_44 ( V_17 -> V_19 . V_42 , V_36 ) ;
}
static int F_16 ( struct V_16 * V_17 )
{
static const T_1 V_45 [] = { V_46 , 0x38 , 0x39 } ;
static const T_1 V_47 [] = { V_48 , 0x80 } ;
static const T_1 V_49 [] = { V_50 , 0x40 } ;
static const T_1 V_51 [] = { V_52 , 0x24 , 0x20 } ;
static const T_1 V_53 [] = { V_54 , 0x33 } ;
static const T_1 V_55 [] = { V_56 , 0x32 } ;
F_17 ( V_17 , V_45 , sizeof( V_45 ) ) ;
F_18 ( 200 ) ;
F_17 ( V_17 , V_47 , sizeof( V_47 ) ) ;
F_17 ( V_17 , V_49 , sizeof( V_49 ) ) ;
F_17 ( V_17 , V_51 , sizeof( V_51 ) ) ;
F_17 ( V_17 , V_53 , sizeof( V_53 ) ) ;
F_17 ( V_17 , V_55 , sizeof( V_55 ) ) ;
return 0 ;
}
static int F_19 ( struct V_16 * V_17 )
{
static const T_1 V_45 [] = { V_46 , 0x38 , 0x38 } ;
static const T_1 V_47 [] = { V_48 , 0x80 } ;
static const T_1 V_49 [] = { V_50 , 0x40 } ;
static const T_1 V_51 [] = { V_52 , 0x28 , 0x20 } ;
static const T_1 V_53 [] = { V_54 , 0x33 } ;
static const T_1 V_55 [] = { V_56 , 0x32 } ;
F_17 ( V_17 , V_45 , sizeof( V_45 ) ) ;
F_18 ( 200 ) ;
F_17 ( V_17 , V_47 , sizeof( V_47 ) ) ;
F_17 ( V_17 , V_49 , sizeof( V_49 ) ) ;
F_17 ( V_17 , V_51 , sizeof( V_51 ) ) ;
F_17 ( V_17 , V_53 , sizeof( V_53 ) ) ;
F_17 ( V_17 , V_55 , sizeof( V_55 ) ) ;
return 0 ;
}
static int F_20 ( struct V_16 * V_17 )
{
static const T_1 V_45 [] = { 0x89 , 0x38 , 0x39 } ;
static const T_1 V_47 [] = { 0x50 , 0x80 } ;
static const T_1 V_49 [] = { 0x8E , 0x40 } ;
static const T_1 V_51 [] = { 0x67 , 0x10 , 0x23 , 0x00 , 0xFF , 0xFF ,
0x00 , 0xFF , 0x00 , 0x40 , 0x40 } ;
static const T_1 V_57 [] = { 0xB5 , 0x7A } ;
static const T_1 V_55 [] = { 0x75 , 0x32 } ;
F_17 ( V_17 , V_45 , sizeof( V_45 ) ) ;
F_18 ( 2000 ) ;
F_17 ( V_17 , V_47 , sizeof( V_47 ) ) ;
F_17 ( V_17 , V_49 , sizeof( V_49 ) ) ;
F_17 ( V_17 , V_51 , sizeof( V_51 ) ) ;
F_18 ( 2000 ) ;
F_17 ( V_17 , V_57 , sizeof( V_57 ) ) ;
F_17 ( V_17 , V_55 , sizeof( V_55 ) ) ;
return 0 ;
}
static int F_21 ( struct V_16 * V_17 )
{
static const T_1 V_45 [] = { 0x89 , 0x38 , 0x38 } ;
static const T_1 V_47 [] = { 0x50 , 0x80 } ;
static const T_1 V_49 [] = { 0x8E , 0x40 } ;
static const T_1 V_51 [] = { 0x67 , 0x10 , 0x20 , 0x00 , 0xFF , 0xFF ,
0x00 , 0xFF , 0x00 , 0x40 , 0x40 } ;
static const T_1 V_57 [] = { 0xB5 , 0x7A } ;
static const T_1 V_55 [] = { 0x75 , 0x32 } ;
F_17 ( V_17 , V_45 , sizeof( V_45 ) ) ;
F_18 ( 2000 ) ;
F_17 ( V_17 , V_47 , sizeof( V_47 ) ) ;
F_17 ( V_17 , V_49 , sizeof( V_49 ) ) ;
F_17 ( V_17 , V_51 , sizeof( V_51 ) ) ;
F_18 ( 2000 ) ;
F_17 ( V_17 , V_57 , sizeof( V_57 ) ) ;
F_17 ( V_17 , V_55 , sizeof( V_55 ) ) ;
return 0 ;
}
static int F_22 ( struct V_16 * V_17 , int V_58 )
{
struct V_5 * V_6 = V_17 -> V_19 -> V_20 ;
V_6 -> V_59 = V_58 ? 0x04 : 0x00 ;
return 0 ;
}
static int F_23 ( struct V_16 * V_17 , int V_60 )
{
struct V_5 * V_6 = V_17 -> V_19 -> V_20 ;
struct V_35 * V_29 = V_6 -> V_29 ;
F_24 ( 1 , L_2 , V_27 , V_60 ) ;
if ( V_60 == 0 )
F_25 ( V_61 , 8 ) ;
else
F_26 ( V_61 , 8 ) ;
return 0 ;
}
static int F_27 ( struct V_16 * V_17 , int V_58 )
{
struct V_5 * V_6 = V_17 -> V_19 -> V_20 ;
if ( V_58 )
V_6 -> V_59 |= 0x04 ;
else
V_6 -> V_59 &= ~ 0x04 ;
return 0 ;
}
static int F_28 ( struct V_16 * V_17 , int V_58 )
{
struct V_5 * V_6 = V_17 -> V_19 -> V_20 ;
V_6 -> V_59 = V_58 ? 0x04 : 0x00 ;
return 0 ;
}
static int F_29 ( struct V_16 * V_17 ,
int V_58 )
{
struct V_5 * V_6 = V_17 -> V_19 -> V_20 ;
V_6 -> V_59 = 0x02 ;
return 0 ;
}
static int F_30 ( struct V_16 * V_17 ,
T_2 V_62 )
{
struct V_5 * V_6 = V_17 -> V_19 -> V_20 ;
struct V_35 * V_29 = V_6 -> V_29 ;
if ( V_62 == V_63 )
F_31 ( V_61 , 0x000006fb ) ;
else
F_31 ( V_61 , 0x000006f9 ) ;
if ( V_29 -> V_64 )
return V_29 -> V_64 ( V_17 , V_62 ) ;
return 0 ;
}
static int F_32 ( struct V_16 * V_17 ,
T_2 V_62 )
{
struct V_5 * V_6 = V_17 -> V_19 -> V_20 ;
struct V_35 * V_29 = V_6 -> V_29 ;
if ( V_62 == V_63 ) {
F_24 ( 1 , L_3 ) ;
F_31 ( V_61 , 0x0000efff ) ;
}
if ( V_29 -> V_64 )
return V_29 -> V_64 ( V_17 , V_62 ) ;
return 0 ;
}
static int F_33 ( struct V_16 * V_17 ,
T_2 V_62 )
{
struct V_5 * V_6 = V_17 -> V_19 -> V_20 ;
struct V_35 * V_29 = V_6 -> V_29 ;
F_26 ( V_61 , 0x6040 ) ;
switch ( V_62 ) {
case V_65 :
F_25 ( V_61 , 0x20 ) ;
break;
case V_66 :
F_26 ( V_61 , 0x20 ) ;
break;
case V_63 :
F_25 ( V_61 , 0x20 ) ;
break;
}
if ( V_29 -> V_64 )
return V_29 -> V_64 ( V_17 , V_62 ) ;
return 0 ;
}
static int F_34 ( struct V_16 * V_17 ,
T_2 V_62 )
{
struct V_5 * V_6 = V_17 -> V_19 -> V_20 ;
struct V_35 * V_29 = V_6 -> V_29 ;
switch ( V_62 ) {
case V_65 :
F_24 ( 1 , L_4 ) ;
F_31 ( V_61 , 0x00001220 ) ;
break;
case V_66 :
F_24 ( 1 , L_5 ) ;
F_31 ( V_61 , 0x00001222 ) ;
break;
case V_63 :
F_24 ( 1 , L_3 ) ;
F_31 ( V_61 , 0x00001230 ) ;
break;
}
if ( V_29 -> V_64 )
return V_29 -> V_64 ( V_17 , V_62 ) ;
return 0 ;
}
static int F_35 ( T_1 V_67 , struct V_5 * V_6 )
{
struct V_16 * V_17 ;
struct V_39 * V_68 = NULL ;
struct V_69 V_70 ;
struct V_71 V_72 = {
. V_73 = & V_6 -> V_29 -> V_73 ,
. V_74 = V_67 ,
. V_75 = & V_70 ,
} ;
V_68 = F_15 ( & V_6 -> V_25 , 1 ) ;
if ( ! V_68 )
return - V_28 ;
if ( ! V_68 -> V_19 . V_42 ) {
F_10 ( V_26 L_6
L_7 ,
V_6 -> V_29 -> V_76 ) ;
return - V_28 ;
}
F_36 ( V_6 -> V_29 , & V_70 ) ;
V_17 = F_37 ( V_77 , V_68 -> V_19 . V_42 , & V_72 ) ;
if ( ! V_17 ) {
F_10 ( V_26 L_8 ,
V_6 -> V_29 -> V_76 ) ;
F_38 ( V_68 -> V_19 . V_42 ) ;
F_39 ( V_68 -> V_19 . V_42 ) ;
V_68 -> V_19 . V_42 = NULL ;
return - V_28 ;
}
F_10 ( V_78 L_9 ,
V_6 -> V_29 -> V_76 ) ;
return 0 ;
}
static int F_40 ( struct V_5 * V_6 , struct V_79 * V_72 )
{
struct V_16 * V_17 ;
struct V_39 * V_68 = NULL ;
V_68 = F_15 ( & V_6 -> V_25 , 1 ) ;
if ( ! V_68 )
return - V_28 ;
if ( ! V_68 -> V_19 . V_42 ) {
F_10 ( V_26 L_6
L_10 ,
V_6 -> V_29 -> V_76 ) ;
return - V_28 ;
}
V_17 = F_37 ( V_80 , V_68 -> V_19 . V_42 , & V_6 -> V_29 -> V_73 ,
V_72 ) ;
if ( ! V_17 ) {
F_10 ( V_26 L_11 ,
V_6 -> V_29 -> V_76 ) ;
F_38 ( V_68 -> V_19 . V_42 ) ;
F_39 ( V_68 -> V_19 . V_42 ) ;
V_68 -> V_19 . V_42 = NULL ;
return - V_28 ;
}
F_10 ( V_78 L_12 , V_6 -> V_29 -> V_76 ) ;
return 0 ;
}
static int F_41 ( struct V_16 * V_17 ,
int V_58 )
{
struct V_5 * V_6 = V_17 -> V_19 -> V_20 ;
V_6 -> V_59 = 0x2 ;
return 0 ;
}
static int F_42 ( struct V_16 * V_17 ,
int V_58 )
{
struct V_5 * V_6 = V_17 -> V_19 -> V_20 ;
V_6 -> V_59 = 0 ;
return 0 ;
}
static int F_43 ( struct V_16 * V_17 )
{
struct V_5 * V_6 = V_17 -> V_19 -> V_20 ;
struct V_35 * V_29 = V_6 -> V_29 ;
F_31 ( V_81 , 0 ) ;
F_44 ( 10 ) ;
F_31 ( V_81 , 1 ) ;
F_44 ( 10 ) ;
return 0 ;
}
static int F_45 ( struct V_16 * V_17 ,
int V_58 )
{
struct V_5 * V_6 = V_17 -> V_19 -> V_20 ;
V_6 -> V_59 = 4 ;
return 0 ;
}
static int F_46 ( struct V_5 * V_6 )
{
struct V_35 * V_29 = V_6 -> V_29 ;
struct V_39 * V_17 = NULL ;
int V_82 ;
F_47 ( & V_6 -> V_25 . V_30 ) ;
F_48 ( & V_6 -> V_25 . V_83 ) ;
if ( ! V_29 -> V_84 . V_85 )
return - V_86 ;
F_10 ( V_78 L_13 , V_27 ,
V_29 -> V_84 . V_85 ) ;
for ( V_82 = 1 ; V_82 <= V_29 -> V_84 . V_85 ; V_82 ++ ) {
V_17 = F_49 ( & V_6 -> V_25 , V_82 ) ;
if ( ! V_17 ) {
F_10 ( V_26 L_14 , V_27 ) ;
F_50 ( & V_6 -> V_25 ) ;
return - V_87 ;
}
}
return 0 ;
}
static int F_51 ( struct V_16 * V_17 )
{
struct V_88 * V_89 = & V_17 -> V_90 ;
struct V_5 * V_6 = V_17 -> V_19 -> V_20 ;
T_1 V_91 [ 4 ] ;
T_3 div ;
struct V_92 V_93 = {
. V_67 = 0x61 ,
. V_94 = 0 ,
. V_91 = V_91 ,
. V_95 = sizeof( V_91 ) } ;
div = V_89 -> V_96 / 125 ;
V_91 [ 0 ] = ( div >> 8 ) & 0x7f ;
V_91 [ 1 ] = div & 0xff ;
V_91 [ 2 ] = 0x84 ;
V_91 [ 3 ] = 0x00 ;
if ( V_89 -> V_96 < 1500000 )
V_91 [ 3 ] |= 0x10 ;
if ( V_17 -> V_43 . V_44 )
V_17 -> V_43 . V_44 ( V_17 , 1 ) ;
if ( F_52 ( & V_6 -> V_29 -> V_73 , & V_93 , 1 ) != 1 )
return - V_97 ;
return 0 ;
}
static int F_53 ( struct V_16 * V_17 ,
T_4 V_98 )
{
struct V_5 * V_6 = V_17 -> V_19 -> V_20 ;
struct V_35 * V_29 = V_6 -> V_29 ;
F_26 ( V_61 , 0x0800 ) ;
switch ( V_98 ) {
case V_99 :
F_26 ( V_61 , 0x08 ) ;
break;
case V_100 :
F_25 ( V_61 , 0x08 ) ;
break;
default:
return - V_28 ;
}
return 0 ;
}
static int F_54 ( struct V_16 * V_17 ,
T_2 V_62 )
{
struct V_5 * V_6 = V_17 -> V_19 -> V_20 ;
struct V_35 * V_29 = V_6 -> V_29 ;
T_1 V_101 ;
struct V_92 V_93 = {
. V_67 = 8 ,
. V_94 = 0 ,
. V_91 = & V_101 ,
. V_95 = sizeof( V_101 ) } ;
F_26 ( V_61 , 0x8000 ) ;
switch ( V_62 ) {
case V_63 :
break;
case V_65 :
V_101 = V_102 | V_103 ;
F_25 ( V_61 , 0x80 ) ;
break;
case V_66 :
V_101 = V_102 | V_103 | V_104 ;
F_25 ( V_61 , 0x80 ) ;
break;
default:
return - V_28 ;
}
return ( F_52 ( & V_6 -> V_29 -> V_73 , & V_93 , 1 ) == 1 ) ? 0 : - V_97 ;
}
static int F_55 ( struct V_16 * V_17 ,
T_3 V_105 , T_3 V_106 )
{
T_1 V_107 = 0 ;
T_1 V_108 = 0 ;
if ( V_105 < 1500000 ) {
V_107 = 0xb7 ;
V_108 = 0x47 ;
} else if ( V_105 < 3000000 ) {
V_107 = 0xb7 ;
V_108 = 0x4b ;
} else if ( V_105 < 7000000 ) {
V_107 = 0xb7 ;
V_108 = 0x4f ;
} else if ( V_105 < 14000000 ) {
V_107 = 0xb7 ;
V_108 = 0x53 ;
} else if ( V_105 < 30000000 ) {
V_107 = 0xb6 ;
V_108 = 0x53 ;
} else if ( V_105 < 45000000 ) {
V_107 = 0xb4 ;
V_108 = 0x51 ;
}
F_56 ( V_17 , 0x13 , V_107 ) ;
F_56 ( V_17 , 0x14 , V_108 ) ;
F_56 ( V_17 , 0x1f , ( V_106 >> 16 ) & 0xff ) ;
F_56 ( V_17 , 0x20 , ( V_106 >> 8 ) & 0xff ) ;
F_56 ( V_17 , 0x21 , V_106 & 0xf0 ) ;
return 0 ;
}
static int F_57 ( struct V_5 * V_6 )
{
struct V_35 * V_29 = V_6 -> V_29 ;
struct V_39 * V_68 , * V_109 = NULL ;
int V_110 = 0 ;
int V_111 = - V_28 ;
if ( 0 != V_29 -> V_112 ) {
F_10 ( V_26 L_15 , V_29 -> V_76 ) ;
goto V_113;
}
V_68 = F_15 ( & V_6 -> V_25 , 1 ) ;
if ( ! V_68 )
goto V_113;
V_6 -> V_25 . V_41 = 0 ;
V_29 -> V_114 = F_14 ;
switch ( V_29 -> V_115 ) {
case V_116 :
V_68 -> V_19 . V_42 = F_37 ( V_117 ,
& V_118 ,
& V_29 -> V_73 ) ;
if ( V_68 -> V_19 . V_42 != NULL ) {
if ( ! F_37 ( V_119 , V_68 -> V_19 . V_42 ,
0x61 , & V_29 -> V_73 ,
V_120 ) )
goto V_113;
}
break;
case V_121 :
case V_122 :
case V_123 :
case V_124 :
V_68 -> V_19 . V_42 = F_37 ( V_117 ,
& V_118 ,
& V_29 -> V_73 ) ;
if ( V_68 -> V_19 . V_42 != NULL ) {
if ( ! F_37 ( V_119 , V_68 -> V_19 . V_42 ,
0x60 , & V_29 -> V_73 ,
V_125 ) )
goto V_113;
}
break;
case V_126 :
case V_127 :
case V_128 :
case V_129 :
V_68 -> V_19 . V_42 = F_37 ( V_117 ,
& V_130 ,
& V_29 -> V_73 ) ;
if ( V_68 -> V_19 . V_42 != NULL ) {
if ( ! F_37 ( V_131 , V_68 -> V_19 . V_42 ,
& V_29 -> V_73 , 0x61 ,
V_132 ) )
goto V_113;
}
break;
case V_133 :
V_68 -> V_19 . V_42 = F_37 ( V_117 ,
& V_130 ,
& V_29 -> V_73 ) ;
if ( V_68 -> V_19 . V_42 != NULL ) {
if ( ! F_37 ( V_131 , V_68 -> V_19 . V_42 ,
& V_29 -> V_73 , 0x61 ,
V_134 ) )
goto V_113;
}
break;
case V_135 :
V_110 = 1 ;
V_6 -> V_25 . V_41 = 2 ;
V_68 -> V_19 . V_42 = F_37 ( V_136 ,
& V_137 ,
& V_6 -> V_29 -> V_73 ) ;
if ( V_68 -> V_19 . V_42 ) {
if ( ! F_37 ( V_138 ,
V_68 -> V_19 . V_42 ,
& V_6 -> V_29 -> V_73 ,
0x08 , V_139 , 0x00 ) )
goto V_113;
}
V_109 = F_15 ( & V_6 -> V_25 , 2 ) ;
if ( ! V_109 )
goto V_113;
V_109 -> V_19 . V_42 = F_37 ( V_117 ,
& V_130 ,
& V_6 -> V_29 -> V_73 ) ;
if ( V_109 -> V_19 . V_42 ) {
V_109 -> V_19 . V_42 -> V_140 = 1 ;
if ( ! F_37 ( V_131 ,
V_109 -> V_19 . V_42 ,
& V_6 -> V_29 -> V_73 ,
0x61 , V_132 ) )
goto V_113;
}
break;
case V_141 :
V_68 -> V_19 . V_42 = F_37 ( V_142 ,
& V_143 ,
& V_29 -> V_73 ) ;
if ( V_68 -> V_19 . V_42 != NULL ) {
if ( ! F_37 ( V_119 , V_68 -> V_19 . V_42 ,
0x60 , NULL , V_125 ) )
goto V_113;
break;
}
V_68 -> V_19 . V_42 = F_37 ( V_144 ,
& V_145 ,
& V_29 -> V_73 ) ;
if ( V_68 -> V_19 . V_42 != NULL ) {
if ( ! F_37 ( V_119 , V_68 -> V_19 . V_42 ,
0x60 , NULL , V_125 ) )
goto V_113;
}
break;
case V_146 :
V_68 -> V_19 . V_42 = F_37 ( V_142 ,
& V_147 ,
& V_29 -> V_73 ) ;
if ( V_68 -> V_19 . V_42 != NULL ) {
if ( ! F_37 ( V_119 , V_68 -> V_19 . V_42 ,
0x61 , NULL , V_125 ) )
goto V_113;
break;
}
V_68 -> V_19 . V_42 = F_37 ( V_144 ,
& V_145 ,
& V_29 -> V_73 ) ;
if ( V_68 -> V_19 . V_42 != NULL ) {
if ( ! F_37 ( V_119 , V_68 -> V_19 . V_42 ,
0x61 , NULL , V_125 ) )
goto V_113;
}
break;
case V_148 :
V_68 -> V_19 . V_42 = F_37 ( V_142 ,
& V_143 ,
& V_29 -> V_73 ) ;
if ( V_68 -> V_19 . V_42 != NULL ) {
if ( ! F_37 ( V_119 , V_68 -> V_19 . V_42 ,
0x61 , NULL , V_149 ) )
goto V_113;
}
break;
case V_150 :
case V_151 :
case V_152 :
V_68 -> V_19 . V_42 = F_37 ( V_142 ,
& V_153 ,
& V_29 -> V_73 ) ;
if ( V_68 -> V_19 . V_42 != NULL ) {
if ( ! F_37 ( V_119 , V_68 -> V_19 . V_42 ,
0x61 , NULL , V_154 ) )
goto V_113;
}
break;
case V_155 :
#if F_58 ( V_156 )
V_68 -> V_19 . V_42 = F_37 ( V_142 , & V_157 ,
& V_6 -> V_158 -> V_159 ) ;
if ( V_68 -> V_19 . V_42 != NULL ) {
if ( ! F_37 ( V_131 , V_68 -> V_19 . V_42 ,
& V_29 -> V_73 , 0x61 ,
V_132 ) )
goto V_113;
}
#else
F_10 ( V_26 L_16 ,
V_29 -> V_76 ) ;
#endif
break;
case V_160 :
V_68 -> V_19 . V_42 = F_37 ( V_144 ,
& V_161 ,
& V_29 -> V_73 ) ;
if ( V_68 -> V_19 . V_42 != NULL ) {
if ( ! F_37 ( V_131 , V_68 -> V_19 . V_42 ,
& V_29 -> V_73 , 0x61 ,
V_162 ) )
goto V_113;
}
break;
case V_163 :
V_68 -> V_19 . V_42 = F_37 ( V_144 ,
& V_164 ,
& V_29 -> V_73 ) ;
if ( V_68 -> V_19 . V_42 == NULL )
V_68 -> V_19 . V_42 = F_37 ( V_142 ,
& V_165 ,
& V_29 -> V_73 ) ;
if ( V_68 -> V_19 . V_42 )
V_68 -> V_19 . V_42 -> V_43 . V_44 = NULL ;
if ( F_35 ( 0x61 , V_6 ) < 0 )
goto V_113;
break;
case V_166 :
V_68 -> V_19 . V_42 = F_37 ( V_167 , & V_168 ,
& V_29 -> V_73 ) ;
if ( V_68 -> V_19 . V_42 != NULL ) {
if ( ! F_37 ( V_131 , V_68 -> V_19 . V_42 ,
& V_29 -> V_73 , 0x61 ,
V_169 ) )
goto V_113;
}
break;
case V_170 :
V_6 -> V_59 = 0x08 ;
F_25 ( V_61 , 1 ) ;
F_59 ( 100 ) ;
F_26 ( V_61 , 1 ) ;
F_59 ( 200 ) ;
V_171 . V_172 = F_23 ;
V_68 -> V_19 . V_42 = F_37 ( V_173 ,
& V_171 ,
& V_29 -> V_73 ) ;
if ( V_68 -> V_19 . V_42 != NULL ) {
if ( ! F_37 ( V_131 , V_68 -> V_19 . V_42 ,
& V_29 -> V_73 , 0x61 ,
V_174 ) )
goto V_113;
}
break;
case V_175 :
V_6 -> V_59 = 0x08 ;
F_25 ( V_61 , 1 ) ;
F_59 ( 100 ) ;
F_26 ( V_61 , 9 ) ;
F_59 ( 200 ) ;
V_68 -> V_19 . V_42 = F_37 ( V_173 ,
& V_171 ,
& V_29 -> V_73 ) ;
if ( V_68 -> V_19 . V_42 != NULL ) {
if ( ! F_37 ( V_131 , V_68 -> V_19 . V_42 ,
& V_29 -> V_73 , 0x61 ,
V_169 ) )
goto V_113;
}
break;
case V_176 :
V_6 -> V_59 = 0x08 ;
F_25 ( V_61 , 1 ) ;
F_59 ( 100 ) ;
F_26 ( V_61 , 1 ) ;
F_59 ( 200 ) ;
V_68 -> V_19 . V_42 = F_37 ( V_173 ,
& V_177 ,
& V_29 -> V_73 ) ;
if ( V_68 -> V_19 . V_42 != NULL ) {
if ( ! F_37 ( V_131 , V_68 -> V_19 . V_42 ,
& V_29 -> V_73 , 0x61 ,
V_178 ) )
goto V_113;
if ( ! F_37 ( V_179 , V_68 -> V_19 . V_42 ,
& V_29 -> V_73 , 0x43 ) )
goto V_113;
}
break;
case V_180 :
V_6 -> V_59 = 0x08 ;
F_25 ( V_61 , 1 ) ;
F_59 ( 100 ) ;
F_26 ( V_61 , 1 ) ;
F_59 ( 200 ) ;
V_68 -> V_19 . V_42 = F_37 ( V_173 ,
& V_181 ,
& V_29 -> V_73 ) ;
if ( V_68 -> V_19 . V_42 != NULL ) {
if ( ! F_37 ( V_131 , V_68 -> V_19 . V_42 ,
& V_29 -> V_73 , 0x61 ,
V_178 ) )
goto V_113;
if ( ! F_37 ( V_179 , V_68 -> V_19 . V_42 ,
& V_29 -> V_73 , 0x43 ) )
goto V_113;
}
break;
case V_182 :
V_68 -> V_19 . V_42 = F_37 ( V_183 ,
& V_184 ,
& V_29 -> V_73 ) ;
if ( V_68 -> V_19 . V_42 != NULL ) {
if ( ! F_37 ( V_131 , V_68 -> V_19 . V_42 ,
& V_29 -> V_73 , 0x61 ,
V_185 ) )
goto V_113;
}
break;
case V_186 :
case V_187 :
V_68 -> V_19 . V_42 = F_37 ( V_136 ,
& V_137 ,
& V_29 -> V_73 ) ;
if ( V_68 -> V_19 . V_42 ) {
if ( ! F_37 ( V_138 , V_68 -> V_19 . V_42 ,
& V_29 -> V_73 , 0x08 , V_139 , 0x00 ) )
goto V_113;
}
break;
case V_188 :
V_68 -> V_19 . V_42 = F_37 ( V_136 ,
& V_189 ,
& V_29 -> V_73 ) ;
if ( V_68 -> V_19 . V_42 ) {
V_29 -> V_64 = V_68 -> V_19 . V_42 -> V_43 . V_190 ;
V_68 -> V_19 . V_42 -> V_43 . V_190 = F_30 ;
}
break;
case V_191 :
V_68 -> V_19 . V_42 = F_37 ( V_136 ,
& V_192 ,
& V_29 -> V_73 ) ;
if ( V_68 -> V_19 . V_42 ) {
V_29 -> V_64 = V_68 -> V_19 . V_42 -> V_43 . V_190 ;
V_68 -> V_19 . V_42 -> V_43 . V_190 = F_32 ;
}
break;
case V_193 :
V_68 -> V_19 . V_42 = F_37 ( V_194 ,
& V_195 ,
& V_29 -> V_73 ) ;
if ( V_68 -> V_19 . V_42 != NULL ) {
if ( ! F_37 ( V_196 , V_68 -> V_19 . V_42 ,
& V_29 -> V_73 ,
& V_197 ) )
goto V_113;
}
break;
case V_198 :
V_68 -> V_19 . V_42 = F_37 ( V_194 ,
& V_199 ,
& V_29 -> V_73 ) ;
if ( V_68 -> V_19 . V_42 != NULL ) {
struct V_16 * V_17 ;
struct V_71 V_72 = {
. V_73 = & V_29 -> V_73 ,
. V_74 = 0x61 ,
} ;
static struct V_69 V_70 = {
. V_200 = V_201 ,
. V_202 = 64 ,
. V_203 = V_204 ,
} ;
V_17 = F_37 ( V_77 ,
V_68 -> V_19 . V_42 , & V_72 ) ;
if ( V_17 != NULL && V_17 -> V_43 . V_205 . V_206 != NULL )
V_17 -> V_43 . V_205 . V_206 ( V_17 , & V_70 ) ;
}
break;
case V_207 :
case V_208 :
V_68 -> V_19 . V_42 = F_37 ( V_144 ,
& V_209 ,
& V_29 -> V_73 ) ;
if ( V_68 -> V_19 . V_42 ) {
V_68 -> V_19 . V_42 -> V_43 . V_44 = NULL ;
if ( F_35 ( 0x61 , V_6 ) < 0 )
goto V_113;
}
break;
case V_210 :
case V_211 :
V_68 -> V_19 . V_42 = F_37 ( V_144 ,
& V_209 ,
& V_29 -> V_73 ) ;
if ( V_68 -> V_19 . V_42 ) {
struct V_79 V_72 = {
. V_212 = 0x61 ,
. V_213 = 0 ,
. V_214 = 134 ,
. V_215 = 1 ,
. V_216 = 4560
} ;
V_68 -> V_19 . V_42 -> V_43 . V_44 = NULL ;
if ( F_40 ( V_6 , & V_72 ) < 0 )
goto V_113;
}
break;
case V_217 :
V_6 -> V_59 = 0x00 ;
V_68 -> V_19 . V_42 = F_37 ( V_144 ,
& V_218 ,
& V_29 -> V_73 ) ;
if ( F_35 ( 0x61 , V_6 ) < 0 )
goto V_113;
break;
case V_219 :
V_68 -> V_19 . V_42 = F_37 ( V_194 ,
& V_220 ,
& V_29 -> V_73 ) ;
if ( F_35 ( 0x61 , V_6 ) < 0 )
goto V_113;
break;
case V_221 :
V_68 -> V_19 . V_42 = F_37 ( V_222 ,
& V_223 ,
& V_29 -> V_73 ) ;
if ( V_68 -> V_19 . V_42 != NULL ) {
if ( ! F_37 ( V_196 , V_68 -> V_19 . V_42 ,
& V_29 -> V_73 ,
& V_224 ) )
goto V_113;
}
break;
case V_225 :
V_110 = 1 ;
V_6 -> V_25 . V_41 = 2 ;
V_68 -> V_19 . V_42 = F_37 ( V_226 ,
& V_227 ,
& V_6 -> V_29 -> V_73 ) ;
if ( V_68 -> V_19 . V_42 ) {
if ( ! F_37 ( V_138 ,
V_68 -> V_19 . V_42 ,
& V_6 -> V_29 -> V_73 ,
0x08 , V_139 , 0x00 ) )
goto V_113;
}
V_109 = F_15 ( & V_6 -> V_25 , 2 ) ;
if ( ! V_109 )
goto V_113;
V_109 -> V_19 . V_42 = F_37 ( V_117 ,
& V_130 ,
& V_6 -> V_29 -> V_73 ) ;
if ( V_109 -> V_19 . V_42 ) {
V_109 -> V_19 . V_42 -> V_140 = 1 ;
if ( ! F_37 ( V_131 ,
V_109 -> V_19 . V_42 ,
& V_6 -> V_29 -> V_73 ,
0x61 , V_132 ) )
goto V_113;
}
break;
case V_228 :
V_68 -> V_19 . V_42 = F_37 ( V_226 ,
& V_227 ,
& V_6 -> V_29 -> V_73 ) ;
if ( V_68 -> V_19 . V_42 ) {
if ( ! F_37 ( V_138 ,
V_68 -> V_19 . V_42 ,
& V_6 -> V_29 -> V_73 ,
0x08 , V_139 , 0x00 ) )
goto V_113;
}
break;
case V_229 :
case V_230 :
case V_231 :
V_68 -> V_19 . V_42 = F_37 ( V_232 ,
& V_233 ,
& V_29 -> V_73 ) ;
if ( V_68 -> V_19 . V_42 != NULL ) {
if ( ! F_37 ( V_119 , V_68 -> V_19 . V_42 , 0x60 ,
& V_29 -> V_73 , V_234 ) )
goto V_113;
V_29 -> V_64 = V_68 -> V_19 . V_42 -> V_43 . V_190 ;
V_68 -> V_19 . V_42 -> V_43 . V_190 = F_33 ;
} else {
V_68 -> V_19 . V_42 = F_37 ( V_235 ,
& V_236 ,
& V_29 -> V_73 ) ;
if ( V_68 -> V_19 . V_42 != NULL ) {
if ( ! F_37 ( V_237 , V_68 -> V_19 . V_42 , 0x61 ,
& V_29 -> V_73 ) )
goto V_113;
V_29 -> V_64 = V_68 -> V_19 . V_42 -> V_43 . V_190 ;
V_68 -> V_19 . V_42 -> V_43 . V_190 = F_33 ;
}
}
break;
case V_238 :
V_68 -> V_19 . V_42 = F_37 ( V_226 ,
& V_239 ,
& V_29 -> V_73 ) ;
if ( V_68 -> V_19 . V_42 != NULL )
V_68 -> V_19 . V_42 -> V_43 . V_190 = F_33 ;
break;
case V_240 :
V_68 -> V_19 . V_42 = F_37 ( V_241 ,
& V_242 ,
& V_29 -> V_73 ) ;
if ( V_68 -> V_19 . V_42 != NULL ) {
F_37 ( V_243 , V_68 -> V_19 . V_42 ,
& V_244 , & V_29 -> V_73 ) ;
V_68 -> V_19 . V_42 -> V_43 . V_190 =
F_33 ;
}
break;
case V_245 :
case V_246 :
case V_247 :
case V_248 :
V_68 -> V_19 . V_42 = F_37 ( V_226 ,
& V_227 ,
& V_29 -> V_73 ) ;
if ( V_68 -> V_19 . V_42 != NULL )
V_68 -> V_19 . V_42 -> V_43 . V_190 = F_33 ;
break;
case V_249 :
V_68 -> V_19 . V_42 = F_37 ( V_144 ,
& V_250 ,
& V_29 -> V_73 ) ;
if ( V_68 -> V_19 . V_42 ) {
V_68 -> V_19 . V_42 -> V_43 . V_44 = NULL ;
if ( F_35 ( 0x61 , V_6 ) < 0 )
goto V_113;
}
break;
case V_251 : {
struct V_252 * V_205 = NULL ;
V_68 -> V_19 . V_42 = F_37 ( V_253 ,
& V_254 ,
& V_29 -> V_73 , 0 ) ;
if ( V_68 -> V_19 . V_42 != NULL ) {
if ( ! F_37 ( V_255 , V_68 -> V_19 . V_42 ,
& V_256 ,
& V_29 -> V_73 ) )
goto V_113;
V_205 = & V_68 -> V_19 . V_42 -> V_43 . V_205 ;
V_205 -> V_257 = V_258 ;
V_205 -> V_259 = V_260 ;
V_205 -> V_261 = V_262 ;
V_205 -> V_263 = V_264 ;
V_29 -> V_64 =
V_68 -> V_19 . V_42 -> V_43 . V_190 ;
V_68 -> V_19 . V_42 -> V_43 . V_190 =
F_33 ;
}
break;
}
case V_265 :
V_6 -> V_59 = 0x08 ;
F_26 ( V_61 , 0x0101 ) ;
F_25 ( V_61 , 0x01 ) ;
F_59 ( 100 ) ;
F_26 ( V_61 , 0x01 ) ;
F_59 ( 200 ) ;
V_68 -> V_19 . V_42 = F_37 ( V_232 ,
& V_266 ,
& V_6 -> V_29 -> V_73 ) ;
if ( V_68 -> V_19 . V_42 ) {
V_68 -> V_19 . V_42 -> V_43 . V_205 . V_267 =
F_51 ;
V_68 -> V_19 . V_42 -> V_268 =
& V_6 -> V_29 -> V_73 ;
V_68 -> V_19 . V_42 -> V_43 . V_190 =
F_54 ;
V_68 -> V_19 . V_42 -> V_43 . V_269 =
F_53 ;
}
break;
case V_270 :
V_6 -> V_59 = 0x00 ;
V_68 -> V_19 . V_42 = F_37 ( V_271 ,
& V_272 ,
& V_29 -> V_73 ) ;
if ( V_68 -> V_19 . V_42 ) {
V_29 -> V_64 =
V_68 -> V_19 . V_42 -> V_43 . V_190 ;
V_68 -> V_19 . V_42 -> V_43 . V_190 =
F_34 ;
}
break;
default:
F_10 ( V_26 L_17 ,
V_29 -> V_76 ) ;
break;
}
if ( ( NULL == V_68 -> V_19 . V_42 ) || ( V_109 && NULL == V_109 -> V_19 . V_42 ) ) {
F_10 ( V_26
L_18 ,
V_29 -> V_76 ) ;
goto V_113;
}
V_68 -> V_19 . V_42 -> V_273 = V_274 ;
V_68 -> V_19 . V_42 -> V_43 . V_275 = F_8 ;
if ( V_109 )
V_109 -> V_19 . V_42 -> V_43 . V_275 = F_8 ;
F_60 ( V_29 , V_29 , V_276 , 0 ) ;
V_111 = F_61 ( & V_6 -> V_25 , V_277 , V_6 ,
& V_6 -> V_278 -> V_6 , V_279 , V_110 ) ;
if ( V_111 )
goto V_113;
return V_111 ;
V_113:
V_29 -> V_114 = NULL ;
F_50 ( & V_6 -> V_25 ) ;
return V_111 ;
}
static int F_62 ( struct V_21 * V_22 )
{
struct V_35 * V_29 = V_22 -> V_29 ;
int V_280 = 0 ;
F_24 ( 1 , L_19 , V_27 ) ;
switch ( V_29 -> V_115 ) {
case V_129 :
F_26 ( V_61 , 0x00000080 ) ;
F_18 ( 1000 ) ;
F_25 ( V_61 , 0x00000080 ) ;
F_18 ( 50 ) ;
F_26 ( V_61 , 0x00000080 ) ;
F_18 ( 1000 ) ;
F_25 ( V_61 , 0x00000004 ) ;
F_18 ( 1000 ) ;
break;
case V_135 :
case V_225 :
F_26 ( V_61 , 0x00000080 ) ;
F_18 ( 1000 ) ;
F_25 ( V_61 , 0x00000080 ) ;
F_18 ( 50 ) ;
F_26 ( V_61 , 0x00000080 ) ;
F_18 ( 1000 ) ;
switch ( V_29 -> V_40 -> V_25 . V_32 ) {
case 1 :
F_26 ( V_61 , 0x00000004 ) ;
F_31 ( V_81 , 1 ) ;
V_29 -> V_40 -> V_59 = 0x02 ;
break;
case 2 :
F_31 ( V_81 , 0 ) ;
F_25 ( V_61 , 0x00000004 ) ;
V_29 -> V_40 -> V_59 = 0x0c ;
break;
}
F_18 ( 1000 ) ;
break;
case V_211 :
F_31 ( V_281 , 0x0101 ) ;
break;
default:
V_280 = - V_86 ;
}
return V_280 ;
}
static int F_63 ( struct V_21 * V_22 )
{
struct V_35 * V_29 = V_22 -> V_29 ;
int V_280 = 0 ;
F_24 ( 1 , L_19 , V_27 ) ;
switch ( V_29 -> V_115 ) {
case V_129 :
break;
case V_135 :
case V_225 :
break;
default:
V_280 = - V_86 ;
}
return V_280 ;
}
static int F_64 ( struct V_21 * V_22 )
{
struct V_35 * V_29 = V_22 -> V_29 ;
struct V_5 * V_6 = V_22 -> V_29 -> V_40 ;
int V_280 ;
struct V_39 * V_17 ;
int V_82 ;
F_24 ( 1 , L_19 , V_27 ) ;
F_24 ( 1 , L_20 ,
V_29 -> V_115 ,
V_29 -> V_76 ,
V_29 -> V_282 ,
V_29 -> V_283 ) ;
V_280 = - V_86 ;
if ( ! ( V_29 -> V_84 . V_284 & V_31 ) )
goto V_285;
V_280 = F_65 ( V_6 ) ;
if ( 0 != V_280 )
goto V_285;
F_10 ( V_78 L_21 , V_29 -> V_76 ) ;
V_6 -> V_59 = 0x0c ;
V_280 = F_46 ( V_6 ) ;
if ( V_280 )
goto V_285;
V_280 = - V_86 ;
for ( V_82 = 1 ; V_82 <= V_29 -> V_84 . V_85 ; V_82 ++ ) {
V_17 = F_15 ( & V_29 -> V_40 -> V_25 , V_82 ) ;
if ( V_17 == NULL ) {
F_10 ( V_26 L_22 ,
V_27 , V_82 ) ;
goto V_286;
}
F_66 ( & V_17 -> V_19 . V_287 , & V_288 ,
& V_6 -> V_278 -> V_6 , & V_6 -> V_289 ,
V_290 ,
V_291 ,
sizeof( struct V_15 ) ,
V_6 , NULL ) ;
V_17 -> V_19 . V_76 = V_6 -> V_29 -> V_76 ;
}
V_280 = F_57 ( V_6 ) ;
if ( V_280 )
F_10 ( V_26 L_23 ,
V_29 -> V_76 , V_280 ) ;
return V_280 ;
V_286:
F_50 ( & V_29 -> V_40 -> V_25 ) ;
V_285:
return V_280 ;
}
static int F_67 ( struct V_21 * V_22 )
{
struct V_35 * V_29 = V_22 -> V_29 ;
struct V_5 * V_6 = V_22 -> V_29 -> V_40 ;
F_24 ( 1 , L_19 , V_27 ) ;
F_68 ( & V_6 -> V_25 ) ;
F_69 ( V_6 ) ;
V_29 -> V_114 = NULL ;
return 0 ;
}
static int T_5 F_70 ( void )
{
F_10 ( V_78 L_24 ,
V_292 ) ;
return F_71 ( & V_293 ) ;
}
static void T_6 F_72 ( void )
{
F_73 ( & V_293 ) ;
}
