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
static int F_40 ( struct V_16 * V_17 ,
int V_58 )
{
struct V_5 * V_6 = V_17 -> V_19 -> V_20 ;
V_6 -> V_59 = 0x2 ;
return 0 ;
}
static int F_41 ( struct V_16 * V_17 ,
int V_58 )
{
struct V_5 * V_6 = V_17 -> V_19 -> V_20 ;
V_6 -> V_59 = 0 ;
return 0 ;
}
static int F_42 ( struct V_16 * V_17 )
{
struct V_5 * V_6 = V_17 -> V_19 -> V_20 ;
struct V_35 * V_29 = V_6 -> V_29 ;
F_31 ( V_79 , 0 ) ;
F_43 ( 10 ) ;
F_31 ( V_79 , 1 ) ;
F_43 ( 10 ) ;
return 0 ;
}
static int F_44 ( struct V_16 * V_17 ,
int V_58 )
{
struct V_5 * V_6 = V_17 -> V_19 -> V_20 ;
V_6 -> V_59 = 4 ;
return 0 ;
}
static int F_45 ( struct V_5 * V_6 )
{
struct V_35 * V_29 = V_6 -> V_29 ;
struct V_39 * V_17 = NULL ;
int V_80 ;
F_46 ( & V_6 -> V_25 . V_30 ) ;
F_47 ( & V_6 -> V_25 . V_81 ) ;
if ( ! V_29 -> V_82 . V_83 )
return - V_84 ;
F_10 ( V_78 L_10 , V_27 ,
V_29 -> V_82 . V_83 ) ;
for ( V_80 = 1 ; V_80 <= V_29 -> V_82 . V_83 ; V_80 ++ ) {
V_17 = F_48 ( & V_6 -> V_25 , V_80 ) ;
if ( ! V_17 ) {
F_10 ( V_26 L_11 , V_27 ) ;
F_49 ( & V_6 -> V_25 ) ;
return - V_85 ;
}
}
return 0 ;
}
static int F_50 ( struct V_16 * V_17 ,
struct V_86 * V_87 )
{
struct V_5 * V_6 = V_17 -> V_19 -> V_20 ;
T_1 V_88 [ 4 ] ;
T_3 div ;
struct V_89 V_90 = {
. V_67 = 0x61 ,
. V_91 = 0 ,
. V_88 = V_88 ,
. V_92 = sizeof( V_88 ) } ;
div = V_87 -> V_93 / 125 ;
V_88 [ 0 ] = ( div >> 8 ) & 0x7f ;
V_88 [ 1 ] = div & 0xff ;
V_88 [ 2 ] = 0x84 ;
V_88 [ 3 ] = 0x00 ;
if ( V_87 -> V_93 < 1500000 )
V_88 [ 3 ] |= 0x10 ;
if ( V_17 -> V_43 . V_44 )
V_17 -> V_43 . V_44 ( V_17 , 1 ) ;
if ( F_51 ( & V_6 -> V_29 -> V_73 , & V_90 , 1 ) != 1 )
return - V_94 ;
return 0 ;
}
static int F_52 ( struct V_16 * V_17 ,
T_4 V_95 )
{
struct V_5 * V_6 = V_17 -> V_19 -> V_20 ;
struct V_35 * V_29 = V_6 -> V_29 ;
F_26 ( V_61 , 0x0800 ) ;
switch ( V_95 ) {
case V_96 :
F_26 ( V_61 , 0x08 ) ;
break;
case V_97 :
F_25 ( V_61 , 0x08 ) ;
break;
default:
return - V_28 ;
}
return 0 ;
}
static int F_53 ( struct V_16 * V_17 ,
T_2 V_62 )
{
struct V_5 * V_6 = V_17 -> V_19 -> V_20 ;
struct V_35 * V_29 = V_6 -> V_29 ;
T_1 V_98 ;
struct V_89 V_90 = {
. V_67 = 8 ,
. V_91 = 0 ,
. V_88 = & V_98 ,
. V_92 = sizeof( V_98 ) } ;
F_26 ( V_61 , 0x8000 ) ;
switch ( V_62 ) {
case V_63 :
break;
case V_65 :
V_98 = V_99 | V_100 ;
F_25 ( V_61 , 0x80 ) ;
break;
case V_66 :
V_98 = V_99 | V_100 | V_101 ;
F_25 ( V_61 , 0x80 ) ;
break;
default:
return - V_28 ;
} ;
return ( F_51 ( & V_6 -> V_29 -> V_73 , & V_90 , 1 ) == 1 ) ? 0 : - V_94 ;
}
static int F_54 ( struct V_16 * V_17 ,
T_3 V_102 , T_3 V_103 )
{
T_1 V_104 = 0 ;
T_1 V_105 = 0 ;
if ( V_102 < 1500000 ) {
V_104 = 0xb7 ;
V_105 = 0x47 ;
} else if ( V_102 < 3000000 ) {
V_104 = 0xb7 ;
V_105 = 0x4b ;
} else if ( V_102 < 7000000 ) {
V_104 = 0xb7 ;
V_105 = 0x4f ;
} else if ( V_102 < 14000000 ) {
V_104 = 0xb7 ;
V_105 = 0x53 ;
} else if ( V_102 < 30000000 ) {
V_104 = 0xb6 ;
V_105 = 0x53 ;
} else if ( V_102 < 45000000 ) {
V_104 = 0xb4 ;
V_105 = 0x51 ;
}
F_55 ( V_17 , 0x13 , V_104 ) ;
F_55 ( V_17 , 0x14 , V_105 ) ;
F_55 ( V_17 , 0x1f , ( V_103 >> 16 ) & 0xff ) ;
F_55 ( V_17 , 0x20 , ( V_103 >> 8 ) & 0xff ) ;
F_55 ( V_17 , 0x21 , V_103 & 0xf0 ) ;
return 0 ;
}
static int F_56 ( struct V_5 * V_6 )
{
struct V_35 * V_29 = V_6 -> V_29 ;
struct V_39 * V_68 , * V_106 = NULL ;
int V_107 = 0 ;
if ( 0 != V_29 -> V_108 ) {
F_10 ( V_26 L_12 , V_29 -> V_76 ) ;
goto V_109;
}
V_68 = F_15 ( & V_6 -> V_25 , 1 ) ;
if ( ! V_68 )
goto V_109;
V_6 -> V_25 . V_41 = 0 ;
V_29 -> V_110 = F_14 ;
switch ( V_29 -> V_111 ) {
case V_112 :
V_68 -> V_19 . V_42 = F_37 ( V_113 ,
& V_114 ,
& V_29 -> V_73 ) ;
if ( V_68 -> V_19 . V_42 != NULL ) {
if ( ! F_37 ( V_115 , V_68 -> V_19 . V_42 ,
0x61 , & V_29 -> V_73 ,
V_116 ) )
goto V_109;
}
break;
case V_117 :
case V_118 :
case V_119 :
case V_120 :
V_68 -> V_19 . V_42 = F_37 ( V_113 ,
& V_114 ,
& V_29 -> V_73 ) ;
if ( V_68 -> V_19 . V_42 != NULL ) {
if ( ! F_37 ( V_115 , V_68 -> V_19 . V_42 ,
0x60 , & V_29 -> V_73 ,
V_121 ) )
goto V_109;
}
break;
case V_122 :
case V_123 :
case V_124 :
case V_125 :
case V_126 :
V_68 -> V_19 . V_42 = F_37 ( V_113 ,
& V_127 ,
& V_29 -> V_73 ) ;
if ( V_68 -> V_19 . V_42 != NULL ) {
if ( ! F_37 ( V_128 , V_68 -> V_19 . V_42 ,
& V_29 -> V_73 , 0x61 ,
V_129 ) )
goto V_109;
}
break;
case V_130 :
V_107 = 1 ;
V_6 -> V_25 . V_41 = 2 ;
V_68 -> V_19 . V_42 = F_37 ( V_131 ,
& V_132 ,
& V_6 -> V_29 -> V_73 ) ;
if ( V_68 -> V_19 . V_42 ) {
if ( ! F_37 ( V_133 ,
V_68 -> V_19 . V_42 ,
& V_6 -> V_29 -> V_73 ,
0x08 , V_134 , 0x00 ) )
goto V_109;
}
V_106 = F_15 ( & V_6 -> V_25 , 2 ) ;
if ( ! V_106 )
goto V_109;
V_106 -> V_19 . V_42 = F_37 ( V_113 ,
& V_127 ,
& V_6 -> V_29 -> V_73 ) ;
if ( V_106 -> V_19 . V_42 ) {
V_106 -> V_19 . V_42 -> V_135 = 1 ;
if ( ! F_37 ( V_128 ,
V_106 -> V_19 . V_42 ,
& V_6 -> V_29 -> V_73 ,
0x61 , V_129 ) )
goto V_109;
}
break;
case V_136 :
V_68 -> V_19 . V_42 = F_37 ( V_137 ,
& V_138 ,
& V_29 -> V_73 ) ;
if ( V_68 -> V_19 . V_42 != NULL ) {
if ( ! F_37 ( V_115 , V_68 -> V_19 . V_42 ,
0x60 , NULL , V_121 ) )
goto V_109;
break;
}
V_68 -> V_19 . V_42 = F_37 ( V_139 ,
& V_140 ,
& V_29 -> V_73 ) ;
if ( V_68 -> V_19 . V_42 != NULL ) {
if ( ! F_37 ( V_115 , V_68 -> V_19 . V_42 ,
0x60 , NULL , V_121 ) )
goto V_109;
}
break;
case V_141 :
V_68 -> V_19 . V_42 = F_37 ( V_137 ,
& V_142 ,
& V_29 -> V_73 ) ;
if ( V_68 -> V_19 . V_42 != NULL ) {
if ( ! F_37 ( V_115 , V_68 -> V_19 . V_42 ,
0x61 , NULL , V_121 ) )
goto V_109;
break;
}
V_68 -> V_19 . V_42 = F_37 ( V_139 ,
& V_140 ,
& V_29 -> V_73 ) ;
if ( V_68 -> V_19 . V_42 != NULL ) {
if ( ! F_37 ( V_115 , V_68 -> V_19 . V_42 ,
0x61 , NULL , V_121 ) )
goto V_109;
}
break;
case V_143 :
V_68 -> V_19 . V_42 = F_37 ( V_137 ,
& V_138 ,
& V_29 -> V_73 ) ;
if ( V_68 -> V_19 . V_42 != NULL ) {
if ( ! F_37 ( V_115 , V_68 -> V_19 . V_42 ,
0x61 , NULL , V_144 ) )
goto V_109;
}
break;
case V_145 :
case V_146 :
case V_147 :
V_68 -> V_19 . V_42 = F_37 ( V_137 ,
& V_148 ,
& V_29 -> V_73 ) ;
if ( V_68 -> V_19 . V_42 != NULL ) {
if ( ! F_37 ( V_115 , V_68 -> V_19 . V_42 ,
0x61 , NULL , V_149 ) )
goto V_109;
}
break;
case V_150 :
#if F_57 ( V_151 ) || ( F_57 ( V_152 ) && F_57 ( V_153 ) )
V_68 -> V_19 . V_42 = F_37 ( V_137 , & V_154 ,
& V_6 -> V_155 -> V_156 ) ;
if ( V_68 -> V_19 . V_42 != NULL ) {
if ( ! F_37 ( V_128 , V_68 -> V_19 . V_42 ,
& V_29 -> V_73 , 0x61 ,
V_129 ) )
goto V_109;
}
#else
F_10 ( V_26 L_13 ,
V_29 -> V_76 ) ;
#endif
break;
case V_157 :
V_68 -> V_19 . V_42 = F_37 ( V_139 ,
& V_158 ,
& V_29 -> V_73 ) ;
if ( V_68 -> V_19 . V_42 != NULL ) {
if ( ! F_37 ( V_128 , V_68 -> V_19 . V_42 ,
& V_29 -> V_73 , 0x61 ,
V_159 ) )
goto V_109;
}
break;
case V_160 :
V_68 -> V_19 . V_42 = F_37 ( V_139 ,
& V_161 ,
& V_29 -> V_73 ) ;
if ( V_68 -> V_19 . V_42 == NULL )
V_68 -> V_19 . V_42 = F_37 ( V_137 ,
& V_162 ,
& V_29 -> V_73 ) ;
if ( V_68 -> V_19 . V_42 )
V_68 -> V_19 . V_42 -> V_43 . V_44 = NULL ;
if ( F_35 ( 0x61 , V_6 ) < 0 )
goto V_109;
break;
case V_163 :
V_68 -> V_19 . V_42 = F_37 ( V_164 , & V_165 ,
& V_29 -> V_73 ) ;
if ( V_68 -> V_19 . V_42 != NULL ) {
if ( ! F_37 ( V_128 , V_68 -> V_19 . V_42 ,
& V_29 -> V_73 , 0x61 ,
V_166 ) )
goto V_109;
}
break;
case V_167 :
V_6 -> V_59 = 0x08 ;
F_25 ( V_61 , 1 ) ;
F_58 ( 100 ) ;
F_26 ( V_61 , 1 ) ;
F_58 ( 200 ) ;
V_168 . V_169 = F_23 ;
V_68 -> V_19 . V_42 = F_37 ( V_170 ,
& V_168 ,
& V_29 -> V_73 ) ;
if ( V_68 -> V_19 . V_42 != NULL ) {
if ( ! F_37 ( V_128 , V_68 -> V_19 . V_42 ,
& V_29 -> V_73 , 0x61 ,
V_171 ) )
goto V_109;
}
break;
case V_172 :
V_6 -> V_59 = 0x08 ;
F_25 ( V_61 , 1 ) ;
F_58 ( 100 ) ;
F_26 ( V_61 , 9 ) ;
F_58 ( 200 ) ;
V_68 -> V_19 . V_42 = F_37 ( V_170 ,
& V_168 ,
& V_29 -> V_73 ) ;
if ( V_68 -> V_19 . V_42 != NULL ) {
if ( ! F_37 ( V_128 , V_68 -> V_19 . V_42 ,
& V_29 -> V_73 , 0x61 ,
V_166 ) )
goto V_109;
}
break;
case V_173 :
V_6 -> V_59 = 0x08 ;
F_25 ( V_61 , 1 ) ;
F_58 ( 100 ) ;
F_26 ( V_61 , 1 ) ;
F_58 ( 200 ) ;
V_68 -> V_19 . V_42 = F_37 ( V_170 ,
& V_174 ,
& V_29 -> V_73 ) ;
if ( V_68 -> V_19 . V_42 != NULL ) {
if ( ! F_37 ( V_128 , V_68 -> V_19 . V_42 ,
& V_29 -> V_73 , 0x61 ,
V_175 ) )
goto V_109;
if ( ! F_37 ( V_176 , V_68 -> V_19 . V_42 ,
& V_29 -> V_73 , 0x43 ) )
goto V_109;
}
break;
case V_177 :
V_6 -> V_59 = 0x08 ;
F_25 ( V_61 , 1 ) ;
F_58 ( 100 ) ;
F_26 ( V_61 , 1 ) ;
F_58 ( 200 ) ;
V_68 -> V_19 . V_42 = F_37 ( V_170 ,
& V_178 ,
& V_29 -> V_73 ) ;
if ( V_68 -> V_19 . V_42 != NULL ) {
if ( ! F_37 ( V_128 , V_68 -> V_19 . V_42 ,
& V_29 -> V_73 , 0x61 ,
V_175 ) )
goto V_109;
if ( ! F_37 ( V_176 , V_68 -> V_19 . V_42 ,
& V_29 -> V_73 , 0x43 ) )
goto V_109;
}
break;
case V_179 :
V_68 -> V_19 . V_42 = F_37 ( V_180 ,
& V_181 ,
& V_29 -> V_73 ) ;
if ( V_68 -> V_19 . V_42 != NULL ) {
if ( ! F_37 ( V_128 , V_68 -> V_19 . V_42 ,
& V_29 -> V_73 , 0x61 ,
V_182 ) )
goto V_109;
}
break;
case V_183 :
case V_184 :
V_68 -> V_19 . V_42 = F_37 ( V_131 ,
& V_132 ,
& V_29 -> V_73 ) ;
if ( V_68 -> V_19 . V_42 ) {
if ( ! F_37 ( V_133 , V_68 -> V_19 . V_42 ,
& V_29 -> V_73 , 0x08 , V_134 , 0x00 ) )
goto V_109;
}
break;
case V_185 :
V_68 -> V_19 . V_42 = F_37 ( V_131 ,
& V_186 ,
& V_29 -> V_73 ) ;
if ( V_68 -> V_19 . V_42 ) {
V_29 -> V_64 = V_68 -> V_19 . V_42 -> V_43 . V_187 ;
V_68 -> V_19 . V_42 -> V_43 . V_187 = F_30 ;
}
break;
case V_188 :
V_68 -> V_19 . V_42 = F_37 ( V_131 ,
& V_189 ,
& V_29 -> V_73 ) ;
if ( V_68 -> V_19 . V_42 ) {
V_29 -> V_64 = V_68 -> V_19 . V_42 -> V_43 . V_187 ;
V_68 -> V_19 . V_42 -> V_43 . V_187 = F_32 ;
}
break;
case V_190 :
V_68 -> V_19 . V_42 = F_37 ( V_191 ,
& V_192 ,
& V_29 -> V_73 ) ;
if ( V_68 -> V_19 . V_42 != NULL ) {
if ( ! F_37 ( V_193 , V_68 -> V_19 . V_42 ,
& V_29 -> V_73 ,
& V_194 ) )
goto V_109;
}
break;
case V_195 :
V_68 -> V_19 . V_42 = F_37 ( V_191 ,
& V_196 ,
& V_29 -> V_73 ) ;
if ( V_68 -> V_19 . V_42 != NULL ) {
struct V_16 * V_17 ;
struct V_71 V_72 = {
. V_73 = & V_29 -> V_73 ,
. V_74 = 0x61 ,
} ;
static struct V_69 V_70 = {
. V_197 = V_198 ,
. V_199 = 64 ,
. V_200 = V_201 ,
} ;
V_17 = F_37 ( V_77 ,
V_68 -> V_19 . V_42 , & V_72 ) ;
if ( V_17 != NULL && V_17 -> V_43 . V_202 . V_203 != NULL )
V_17 -> V_43 . V_202 . V_203 ( V_17 , & V_70 ) ;
}
break;
case V_204 :
case V_205 :
V_68 -> V_19 . V_42 = F_37 ( V_139 ,
& V_206 ,
& V_29 -> V_73 ) ;
if ( V_68 -> V_19 . V_42 ) {
V_68 -> V_19 . V_42 -> V_43 . V_44 = NULL ;
if ( F_35 ( 0x61 , V_6 ) < 0 )
goto V_109;
}
break;
case V_207 :
V_6 -> V_59 = 0x00 ;
V_68 -> V_19 . V_42 = F_37 ( V_139 ,
& V_208 ,
& V_29 -> V_73 ) ;
if ( F_35 ( 0x61 , V_6 ) < 0 )
goto V_109;
break;
case V_209 :
V_68 -> V_19 . V_42 = F_37 ( V_191 ,
& V_210 ,
& V_29 -> V_73 ) ;
if ( F_35 ( 0x61 , V_6 ) < 0 )
goto V_109;
break;
case V_211 :
V_68 -> V_19 . V_42 = F_37 ( V_212 ,
& V_213 ,
& V_29 -> V_73 ) ;
if ( V_68 -> V_19 . V_42 != NULL ) {
if ( ! F_37 ( V_193 , V_68 -> V_19 . V_42 ,
& V_29 -> V_73 ,
& V_214 ) )
goto V_109;
}
break;
case V_215 :
V_107 = 1 ;
V_6 -> V_25 . V_41 = 2 ;
V_68 -> V_19 . V_42 = F_37 ( V_216 ,
& V_217 ,
& V_6 -> V_29 -> V_73 ) ;
if ( V_68 -> V_19 . V_42 ) {
if ( ! F_37 ( V_133 ,
V_68 -> V_19 . V_42 ,
& V_6 -> V_29 -> V_73 ,
0x08 , V_134 , 0x00 ) )
goto V_109;
}
V_106 = F_15 ( & V_6 -> V_25 , 2 ) ;
if ( ! V_106 )
goto V_109;
V_106 -> V_19 . V_42 = F_37 ( V_113 ,
& V_127 ,
& V_6 -> V_29 -> V_73 ) ;
if ( V_106 -> V_19 . V_42 ) {
V_106 -> V_19 . V_42 -> V_135 = 1 ;
if ( ! F_37 ( V_128 ,
V_106 -> V_19 . V_42 ,
& V_6 -> V_29 -> V_73 ,
0x61 , V_129 ) )
goto V_109;
}
break;
case V_218 :
V_68 -> V_19 . V_42 = F_37 ( V_216 ,
& V_217 ,
& V_6 -> V_29 -> V_73 ) ;
if ( V_68 -> V_19 . V_42 ) {
if ( ! F_37 ( V_133 ,
V_68 -> V_19 . V_42 ,
& V_6 -> V_29 -> V_73 ,
0x08 , V_134 , 0x00 ) )
goto V_109;
}
break;
case V_219 :
case V_220 :
case V_221 :
V_68 -> V_19 . V_42 = F_37 ( V_222 ,
& V_223 ,
& V_29 -> V_73 ) ;
if ( V_68 -> V_19 . V_42 != NULL ) {
if ( ! F_37 ( V_115 , V_68 -> V_19 . V_42 , 0x60 ,
& V_29 -> V_73 , V_224 ) )
goto V_109;
V_29 -> V_64 = V_68 -> V_19 . V_42 -> V_43 . V_187 ;
V_68 -> V_19 . V_42 -> V_43 . V_187 = F_33 ;
} else {
V_68 -> V_19 . V_42 = F_37 ( V_225 ,
& V_226 ,
& V_29 -> V_73 ) ;
if ( V_68 -> V_19 . V_42 != NULL ) {
if ( ! F_37 ( V_227 , V_68 -> V_19 . V_42 , 0x61 ,
& V_29 -> V_73 ) )
goto V_109;
V_29 -> V_64 = V_68 -> V_19 . V_42 -> V_43 . V_187 ;
V_68 -> V_19 . V_42 -> V_43 . V_187 = F_33 ;
}
}
break;
case V_228 :
V_68 -> V_19 . V_42 = F_37 ( V_216 ,
& V_229 ,
& V_29 -> V_73 ) ;
if ( V_68 -> V_19 . V_42 != NULL )
V_68 -> V_19 . V_42 -> V_43 . V_187 = F_33 ;
break;
case V_230 :
V_68 -> V_19 . V_42 = F_37 ( V_231 ,
& V_232 ,
& V_29 -> V_73 ) ;
if ( V_68 -> V_19 . V_42 != NULL )
V_68 -> V_19 . V_42 -> V_43 . V_187 =
F_33 ;
break;
case V_233 :
case V_234 :
case V_235 :
case V_236 :
V_68 -> V_19 . V_42 = F_37 ( V_216 ,
& V_217 ,
& V_29 -> V_73 ) ;
if ( V_68 -> V_19 . V_42 != NULL )
V_68 -> V_19 . V_42 -> V_43 . V_187 = F_33 ;
break;
case V_237 :
V_68 -> V_19 . V_42 = F_37 ( V_139 ,
& V_238 ,
& V_29 -> V_73 ) ;
if ( V_68 -> V_19 . V_42 ) {
V_68 -> V_19 . V_42 -> V_43 . V_44 = NULL ;
if ( F_35 ( 0x61 , V_6 ) < 0 )
goto V_109;
}
break;
case V_239 : {
struct V_240 * V_202 = NULL ;
V_68 -> V_19 . V_42 = F_37 ( V_241 ,
& V_242 ,
& V_29 -> V_73 , 0 ) ;
if ( V_68 -> V_19 . V_42 != NULL ) {
if ( ! F_37 ( V_243 , V_68 -> V_19 . V_42 ,
& V_244 ,
& V_29 -> V_73 ) )
goto V_109;
V_202 = & V_68 -> V_19 . V_42 -> V_43 . V_202 ;
V_202 -> V_245 = V_246 ;
V_202 -> V_247 = V_248 ;
V_202 -> V_249 = V_250 ;
V_202 -> V_251 = V_252 ;
V_29 -> V_64 =
V_68 -> V_19 . V_42 -> V_43 . V_187 ;
V_68 -> V_19 . V_42 -> V_43 . V_187 =
F_33 ;
}
break;
}
case V_253 :
V_6 -> V_59 = 0x08 ;
F_26 ( V_61 , 0x0101 ) ;
F_25 ( V_61 , 0x01 ) ;
F_58 ( 100 ) ;
F_26 ( V_61 , 0x01 ) ;
F_58 ( 200 ) ;
V_68 -> V_19 . V_42 = F_37 ( V_222 ,
& V_254 ,
& V_6 -> V_29 -> V_73 ) ;
if ( V_68 -> V_19 . V_42 ) {
V_68 -> V_19 . V_42 -> V_43 . V_202 . V_255 =
F_50 ;
V_68 -> V_19 . V_42 -> V_256 =
& V_6 -> V_29 -> V_73 ;
V_68 -> V_19 . V_42 -> V_43 . V_187 =
F_53 ;
V_68 -> V_19 . V_42 -> V_43 . V_257 =
F_52 ;
}
break;
case V_258 :
V_6 -> V_59 = 0x00 ;
V_68 -> V_19 . V_42 = F_37 ( V_259 ,
& V_260 ,
& V_29 -> V_73 ) ;
if ( V_68 -> V_19 . V_42 ) {
V_29 -> V_64 =
V_68 -> V_19 . V_42 -> V_43 . V_187 ;
V_68 -> V_19 . V_42 -> V_43 . V_187 =
F_34 ;
}
break;
default:
F_10 ( V_26 L_14 ,
V_29 -> V_76 ) ;
break;
}
if ( ( NULL == V_68 -> V_19 . V_42 ) || ( V_106 && NULL == V_106 -> V_19 . V_42 ) ) {
F_10 ( V_26
L_15 ,
V_29 -> V_76 ) ;
goto V_109;
}
V_68 -> V_19 . V_42 -> V_261 = V_262 ;
V_68 -> V_19 . V_42 -> V_43 . V_263 = F_8 ;
if ( V_106 )
V_106 -> V_19 . V_42 -> V_43 . V_263 = F_8 ;
F_59 ( V_29 , V_29 , V_264 , 0 ) ;
return F_60 ( & V_6 -> V_25 , V_265 , V_6 ,
& V_6 -> V_266 -> V_6 , V_267 , V_107 , NULL ) ;
V_109:
V_29 -> V_110 = NULL ;
F_49 ( & V_6 -> V_25 ) ;
return - V_28 ;
}
static int F_61 ( struct V_21 * V_22 )
{
struct V_35 * V_29 = V_22 -> V_29 ;
int V_268 = 0 ;
F_24 ( 1 , L_16 , V_27 ) ;
switch ( V_29 -> V_111 ) {
case V_126 :
F_26 ( V_61 , 0x00000080 ) ;
F_18 ( 1000 ) ;
F_25 ( V_61 , 0x00000080 ) ;
F_18 ( 50 ) ;
F_26 ( V_61 , 0x00000080 ) ;
F_18 ( 1000 ) ;
F_25 ( V_61 , 0x00000004 ) ;
F_18 ( 1000 ) ;
break;
case V_130 :
case V_215 :
F_26 ( V_61 , 0x00000080 ) ;
F_18 ( 1000 ) ;
F_25 ( V_61 , 0x00000080 ) ;
F_18 ( 50 ) ;
F_26 ( V_61 , 0x00000080 ) ;
F_18 ( 1000 ) ;
switch ( V_29 -> V_40 -> V_25 . V_32 ) {
case 1 :
F_26 ( V_61 , 0x00000004 ) ;
F_31 ( V_79 , 1 ) ;
V_29 -> V_40 -> V_59 = 0x02 ;
break;
case 2 :
F_31 ( V_79 , 0 ) ;
F_25 ( V_61 , 0x00000004 ) ;
V_29 -> V_40 -> V_59 = 0x0c ;
break;
}
F_18 ( 1000 ) ;
break;
default:
V_268 = - V_84 ;
}
return V_268 ;
}
static int F_62 ( struct V_21 * V_22 )
{
struct V_35 * V_29 = V_22 -> V_29 ;
int V_268 = 0 ;
F_24 ( 1 , L_16 , V_27 ) ;
switch ( V_29 -> V_111 ) {
case V_126 :
break;
case V_130 :
case V_215 :
break;
default:
V_268 = - V_84 ;
}
return V_268 ;
}
static int F_63 ( struct V_21 * V_22 )
{
struct V_35 * V_29 = V_22 -> V_29 ;
struct V_5 * V_6 = V_22 -> V_29 -> V_40 ;
int V_268 ;
struct V_39 * V_17 ;
int V_80 ;
F_24 ( 1 , L_16 , V_27 ) ;
F_24 ( 1 , L_17 ,
V_29 -> V_111 ,
V_29 -> V_76 ,
V_29 -> V_269 ,
V_29 -> V_270 ) ;
V_268 = - V_84 ;
if ( ! ( V_29 -> V_82 . V_271 & V_31 ) )
goto V_272;
V_268 = F_64 ( V_6 ) ;
if ( 0 != V_268 )
goto V_272;
F_10 ( V_78 L_18 , V_29 -> V_76 ) ;
V_6 -> V_59 = 0x0c ;
V_268 = F_45 ( V_6 ) ;
if ( V_268 )
goto V_272;
V_268 = - V_84 ;
for ( V_80 = 1 ; V_80 <= V_29 -> V_82 . V_83 ; V_80 ++ ) {
V_17 = F_15 ( & V_29 -> V_40 -> V_25 , V_80 ) ;
if ( V_17 == NULL ) {
F_10 ( V_26 L_19 ,
V_27 , V_80 ) ;
goto V_273;
}
F_65 ( & V_17 -> V_19 . V_274 , & V_275 ,
& V_6 -> V_266 -> V_6 , & V_6 -> V_276 ,
V_277 ,
V_278 ,
sizeof( struct V_15 ) ,
V_6 , NULL ) ;
V_17 -> V_19 . V_76 = V_6 -> V_29 -> V_76 ;
}
V_268 = F_56 ( V_6 ) ;
if ( V_268 )
F_10 ( V_26 L_20 ,
V_29 -> V_76 , V_268 ) ;
return V_268 ;
V_273:
F_49 ( & V_29 -> V_40 -> V_25 ) ;
V_272:
return V_268 ;
}
static int F_66 ( struct V_21 * V_22 )
{
struct V_35 * V_29 = V_22 -> V_29 ;
struct V_5 * V_6 = V_22 -> V_29 -> V_40 ;
F_24 ( 1 , L_16 , V_27 ) ;
F_67 ( & V_6 -> V_25 ) ;
F_68 ( V_6 ) ;
V_29 -> V_110 = NULL ;
return 0 ;
}
static int T_5 F_69 ( void )
{
F_10 ( V_78 L_21 ,
( V_279 >> 16 ) & 0xff ,
( V_279 >> 8 ) & 0xff ,
V_279 & 0xff ) ;
#ifdef F_70
F_10 ( V_78 L_22 ,
F_70 / 10000 , ( F_70 / 100 ) % 100 , F_70 % 100 ) ;
#endif
return F_71 ( & V_280 ) ;
}
static void T_6 F_72 ( void )
{
F_73 ( & V_280 ) ;
}
