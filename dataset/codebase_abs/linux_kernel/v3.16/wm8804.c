static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_5 * V_6 ;
unsigned int V_7 ;
V_6 = F_2 ( V_2 ) ;
V_7 = F_3 ( V_6 , V_8 ) ;
if ( V_7 & 0x40 )
V_4 -> V_9 . integer . V_9 [ 0 ] = 1 ;
else
V_4 -> V_9 . integer . V_9 [ 0 ] = 0 ;
return 0 ;
}
static int F_4 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_5 * V_6 ;
unsigned int V_7 , V_10 ;
V_6 = F_2 ( V_2 ) ;
if ( V_4 -> V_9 . integer . V_9 [ 0 ] != 0
&& V_4 -> V_9 . integer . V_9 [ 0 ] != 1 )
return - V_11 ;
V_7 = F_3 ( V_6 , V_8 ) ;
switch ( ( V_7 & 0x40 ) >> 6 ) {
case 0 :
if ( ! V_4 -> V_9 . integer . V_9 [ 0 ] )
return 0 ;
break;
case 1 :
if ( V_4 -> V_9 . integer . V_9 [ 1 ] )
return 0 ;
break;
}
V_10 = F_3 ( V_6 , V_12 ) & 0x4 ;
F_5 ( V_6 , V_12 , 0x4 , 0x4 ) ;
F_5 ( V_6 , V_8 , 0x40 ,
V_4 -> V_9 . integer . V_9 [ 0 ] << 6 ) ;
if ( V_4 -> V_9 . integer . V_9 [ 0 ] ) {
F_5 ( V_6 , V_12 , 0x2 , 0x2 ) ;
F_5 ( V_6 , V_12 , 0x10 , 0 ) ;
} else {
F_5 ( V_6 , V_12 , 0x2 , 0 ) ;
}
F_5 ( V_6 , V_12 , 0x4 , V_10 ) ;
return 0 ;
}
static bool F_6 ( struct V_13 * V_14 , unsigned int V_15 )
{
switch ( V_15 ) {
case V_16 :
case V_17 :
case V_18 :
case V_19 :
case V_20 :
case V_21 :
case V_22 :
case V_23 :
case V_24 :
case V_25 :
return true ;
default:
return false ;
}
}
static int F_7 ( struct V_5 * V_6 )
{
return F_8 ( V_6 , V_16 , 0x0 ) ;
}
static int F_9 ( struct V_26 * V_27 , unsigned int V_28 )
{
struct V_5 * V_6 ;
T_1 V_29 , V_30 , V_31 , V_32 ;
V_6 = V_27 -> V_6 ;
switch ( V_28 & V_33 ) {
case V_34 :
V_29 = 0x2 ;
break;
case V_35 :
V_29 = 0x0 ;
break;
case V_36 :
V_29 = 0x1 ;
break;
case V_37 :
case V_38 :
V_29 = 0x3 ;
break;
default:
F_10 ( V_27 -> V_14 , L_1 ) ;
return - V_11 ;
}
F_5 ( V_6 , V_39 , 0x3 , V_29 ) ;
F_5 ( V_6 , V_40 , 0x3 , V_29 ) ;
switch ( V_28 & V_41 ) {
case V_42 :
V_30 = 1 ;
break;
case V_43 :
V_30 = 0 ;
break;
default:
F_10 ( V_27 -> V_14 , L_2 ) ;
return - V_11 ;
}
F_5 ( V_6 , V_40 , 0x40 , V_30 << 6 ) ;
V_31 = V_32 = 0 ;
switch ( V_28 & V_44 ) {
case V_45 :
break;
case V_46 :
V_31 = V_32 = 1 ;
break;
case V_47 :
V_31 = 1 ;
break;
case V_48 :
V_32 = 1 ;
break;
default:
F_10 ( V_27 -> V_14 , L_3 ) ;
return - V_11 ;
}
F_5 ( V_6 , V_39 , 0x10 | 0x20 ,
( V_31 << 4 ) | ( V_32 << 5 ) ) ;
F_5 ( V_6 , V_40 , 0x10 | 0x20 ,
( V_31 << 4 ) | ( V_32 << 5 ) ) ;
return 0 ;
}
static int F_11 ( struct V_49 * V_50 ,
struct V_51 * V_52 ,
struct V_26 * V_27 )
{
struct V_5 * V_6 ;
T_1 V_53 ;
V_6 = V_27 -> V_6 ;
switch ( F_12 ( V_52 ) ) {
case V_54 :
V_53 = 0x0 ;
break;
case V_55 :
V_53 = 0x1 ;
break;
case V_56 :
V_53 = 0x2 ;
break;
default:
F_10 ( V_27 -> V_14 , L_4 ,
F_12 ( V_52 ) ) ;
return - V_11 ;
}
F_5 ( V_6 , V_39 , 0xc , V_53 << 2 ) ;
F_5 ( V_6 , V_40 , 0xc , V_53 << 2 ) ;
return 0 ;
}
static int F_13 ( struct V_57 * V_57 , unsigned int V_58 ,
unsigned int V_59 , unsigned int V_60 )
{
T_2 V_61 ;
unsigned long int V_62 , V_63 , V_64 , V_65 ;
int V_66 ;
for ( V_66 = 0 ; V_66 < F_14 ( V_67 ) ; V_66 ++ ) {
V_65 = V_58 * V_67 [ V_66 ] . div ;
if ( ( V_65 >= 90000000 && V_65 <= 100000000 ) &&
( V_60 == V_67 [ V_66 ] . V_68 ) ) {
V_57 -> V_69 = V_67 [ V_66 ] . V_69 ;
V_57 -> V_68 = V_67 [ V_66 ] . V_68 ;
V_58 *= V_67 [ V_66 ] . div ;
break;
}
}
if ( V_66 == F_14 ( V_67 ) ) {
F_15 ( L_5 ,
V_70 , V_58 ) ;
return - V_11 ;
}
V_57 -> V_71 = 0 ;
V_63 = V_58 / V_59 ;
if ( V_63 < 5 ) {
V_59 >>= 1 ;
V_57 -> V_71 = 1 ;
V_63 = V_58 / V_59 ;
}
if ( V_63 < 5 || V_63 > 13 ) {
F_15 ( L_6 ,
V_70 , V_63 ) ;
return - V_11 ;
}
V_57 -> V_72 = V_63 ;
V_64 = V_58 % V_59 ;
V_61 = V_73 * ( T_2 ) V_64 ;
F_16 ( V_61 , V_59 ) ;
V_62 = V_61 & 0xffffffff ;
if ( ( V_62 % 10 ) >= 5 )
V_62 += 5 ;
V_62 /= 10 ;
V_57 -> V_74 = V_62 ;
return 0 ;
}
static int F_17 ( struct V_26 * V_27 , int V_75 ,
int V_59 , unsigned int V_76 ,
unsigned int V_77 )
{
struct V_5 * V_6 ;
V_6 = V_27 -> V_6 ;
if ( ! V_76 || ! V_77 ) {
F_5 ( V_6 , V_12 , 0x1 , 0x1 ) ;
return 0 ;
} else {
int V_78 ;
struct V_57 V_57 ;
struct V_79 * V_80 ;
V_80 = F_18 ( V_6 ) ;
V_78 = F_13 ( & V_57 , V_77 , V_76 ,
V_80 -> V_60 ) ;
if ( V_78 )
return V_78 ;
F_5 ( V_6 , V_12 , 0x1 , 0x1 ) ;
F_5 ( V_6 , V_81 , 0xf | 0x10 ,
V_57 . V_72 | ( V_57 . V_71 << 4 ) ) ;
F_5 ( V_6 , V_82 , 0x3 | 0x8 ,
V_57 . V_69 | ( V_57 . V_68 << 3 ) ) ;
F_8 ( V_6 , V_83 , V_57 . V_74 & 0xff ) ;
F_8 ( V_6 , V_84 , ( V_57 . V_74 >> 8 ) & 0xff ) ;
F_8 ( V_6 , V_85 , V_57 . V_74 >> 16 ) ;
F_5 ( V_6 , V_12 , 0x1 , 0 ) ;
}
return 0 ;
}
static int F_19 ( struct V_26 * V_27 ,
int V_86 , unsigned int V_87 , int V_88 )
{
struct V_5 * V_6 ;
V_6 = V_27 -> V_6 ;
switch ( V_86 ) {
case V_89 :
if ( ( V_87 >= 10000000 && V_87 <= 14400000 )
|| ( V_87 >= 16280000 && V_87 <= 27000000 ) )
F_5 ( V_6 , V_90 , 0x80 , 0x80 ) ;
else {
F_10 ( V_27 -> V_14 , L_7
L_8 , V_87 ) ;
return - V_11 ;
}
break;
case V_91 :
F_5 ( V_6 , V_90 , 0x80 , 0 ) ;
break;
case V_92 :
F_5 ( V_6 , V_90 , 0x8 , 0 ) ;
break;
case V_93 :
F_5 ( V_6 , V_90 , 0x8 , 0x8 ) ;
break;
default:
F_10 ( V_27 -> V_14 , L_9 , V_86 ) ;
return - V_11 ;
}
return 0 ;
}
static int F_20 ( struct V_26 * V_27 ,
int V_94 , int div )
{
struct V_5 * V_6 ;
struct V_79 * V_80 ;
V_6 = V_27 -> V_6 ;
switch ( V_94 ) {
case V_95 :
F_5 ( V_6 , V_82 , 0x30 ,
( div & 0x3 ) << 4 ) ;
break;
case V_96 :
V_80 = F_18 ( V_6 ) ;
V_80 -> V_60 = div ;
break;
default:
F_10 ( V_27 -> V_14 , L_10 , V_94 ) ;
return - V_11 ;
}
return 0 ;
}
static int F_21 ( struct V_5 * V_6 ,
enum V_97 V_98 )
{
int V_78 ;
struct V_79 * V_80 ;
V_80 = F_18 ( V_6 ) ;
switch ( V_98 ) {
case V_99 :
break;
case V_100 :
F_5 ( V_6 , V_12 , 0x9 , 0 ) ;
break;
case V_101 :
if ( V_6 -> V_102 . V_103 == V_104 ) {
V_78 = F_22 ( F_14 ( V_80 -> V_105 ) ,
V_80 -> V_105 ) ;
if ( V_78 ) {
F_10 ( V_6 -> V_14 ,
L_11 ,
V_78 ) ;
return V_78 ;
}
F_23 ( V_80 -> V_106 ) ;
}
F_5 ( V_6 , V_12 , 0x9 , 0x9 ) ;
break;
case V_104 :
F_5 ( V_6 , V_12 , 0x9 , 0x9 ) ;
F_24 ( F_14 ( V_80 -> V_105 ) ,
V_80 -> V_105 ) ;
break;
}
V_6 -> V_102 . V_103 = V_98 ;
return 0 ;
}
static int F_25 ( struct V_5 * V_6 )
{
F_21 ( V_6 , V_104 ) ;
return 0 ;
}
static int F_26 ( struct V_5 * V_6 )
{
F_21 ( V_6 , V_101 ) ;
return 0 ;
}
static int F_27 ( struct V_5 * V_6 )
{
struct V_79 * V_80 ;
int V_66 ;
V_80 = F_18 ( V_6 ) ;
F_21 ( V_6 , V_104 ) ;
for ( V_66 = 0 ; V_66 < F_14 ( V_80 -> V_105 ) ; ++ V_66 )
F_28 ( V_80 -> V_105 [ V_66 ] . V_107 ,
& V_80 -> V_108 [ V_66 ] ) ;
return 0 ;
}
static int F_29 ( struct V_5 * V_6 )
{
struct V_79 * V_80 ;
int V_66 , V_109 , V_110 , V_78 ;
V_80 = F_18 ( V_6 ) ;
for ( V_66 = 0 ; V_66 < F_14 ( V_80 -> V_105 ) ; V_66 ++ )
V_80 -> V_105 [ V_66 ] . V_111 = V_112 [ V_66 ] ;
V_78 = F_30 ( V_6 -> V_14 , F_14 ( V_80 -> V_105 ) ,
V_80 -> V_105 ) ;
if ( V_78 ) {
F_10 ( V_6 -> V_14 , L_12 , V_78 ) ;
return V_78 ;
}
V_80 -> V_108 [ 0 ] . V_113 = V_114 ;
V_80 -> V_108 [ 1 ] . V_113 = V_115 ;
for ( V_66 = 0 ; V_66 < F_14 ( V_80 -> V_105 ) ; V_66 ++ ) {
V_78 = F_31 ( V_80 -> V_105 [ V_66 ] . V_107 ,
& V_80 -> V_108 [ V_66 ] ) ;
if ( V_78 != 0 ) {
F_10 ( V_6 -> V_14 ,
L_13 ,
V_78 ) ;
}
}
V_78 = F_22 ( F_14 ( V_80 -> V_105 ) ,
V_80 -> V_105 ) ;
if ( V_78 ) {
F_10 ( V_6 -> V_14 , L_11 , V_78 ) ;
return V_78 ;
}
V_109 = F_3 ( V_6 , V_16 ) ;
if ( V_109 < 0 ) {
F_10 ( V_6 -> V_14 , L_14 , V_109 ) ;
V_78 = V_109 ;
goto V_116;
}
V_110 = F_3 ( V_6 , V_17 ) ;
if ( V_110 < 0 ) {
F_10 ( V_6 -> V_14 , L_14 , V_110 ) ;
V_78 = V_110 ;
goto V_116;
}
V_110 = ( V_110 << 8 ) | V_109 ;
if ( V_110 != 0x8805 ) {
F_10 ( V_6 -> V_14 , L_15 , V_110 ) ;
V_78 = - V_11 ;
goto V_116;
}
V_78 = F_3 ( V_6 , V_18 ) ;
if ( V_78 < 0 ) {
F_10 ( V_6 -> V_14 , L_16 ,
V_78 ) ;
goto V_116;
}
F_32 ( V_6 -> V_14 , L_17 , V_78 + 'A' ) ;
V_78 = F_7 ( V_6 ) ;
if ( V_78 < 0 ) {
F_10 ( V_6 -> V_14 , L_18 , V_78 ) ;
goto V_116;
}
F_21 ( V_6 , V_101 ) ;
return 0 ;
V_116:
F_24 ( F_14 ( V_80 -> V_105 ) , V_80 -> V_105 ) ;
return V_78 ;
}
static int F_33 ( struct V_117 * V_118 )
{
struct V_79 * V_80 ;
int V_78 ;
V_80 = F_34 ( & V_118 -> V_14 , sizeof *V_80 , V_119 ) ;
if ( ! V_80 )
return - V_120 ;
V_80 -> V_106 = F_35 ( V_118 , & V_121 ) ;
if ( F_36 ( V_80 -> V_106 ) ) {
V_78 = F_37 ( V_80 -> V_106 ) ;
return V_78 ;
}
F_38 ( V_118 , V_80 ) ;
V_78 = F_39 ( & V_118 -> V_14 ,
& V_122 , & V_123 , 1 ) ;
return V_78 ;
}
static int F_40 ( struct V_117 * V_118 )
{
F_41 ( & V_118 -> V_14 ) ;
return 0 ;
}
static int F_42 ( struct V_124 * V_125 ,
const struct V_126 * V_127 )
{
struct V_79 * V_80 ;
int V_78 ;
V_80 = F_34 ( & V_125 -> V_14 , sizeof *V_80 , V_119 ) ;
if ( ! V_80 )
return - V_120 ;
V_80 -> V_106 = F_43 ( V_125 , & V_121 ) ;
if ( F_36 ( V_80 -> V_106 ) ) {
V_78 = F_37 ( V_80 -> V_106 ) ;
return V_78 ;
}
F_44 ( V_125 , V_80 ) ;
V_78 = F_39 ( & V_125 -> V_14 ,
& V_122 , & V_123 , 1 ) ;
return V_78 ;
}
static int F_45 ( struct V_124 * V_125 )
{
F_41 ( & V_125 -> V_14 ) ;
return 0 ;
}
static int T_3 F_46 ( void )
{
int V_78 = 0 ;
#if F_47 ( V_128 )
V_78 = F_48 ( & V_129 ) ;
if ( V_78 ) {
F_49 ( V_130 L_19 ,
V_78 ) ;
}
#endif
#if F_50 ( V_131 )
V_78 = F_51 ( & V_132 ) ;
if ( V_78 != 0 ) {
F_49 ( V_130 L_20 ,
V_78 ) ;
}
#endif
return V_78 ;
}
static void T_4 F_52 ( void )
{
#if F_47 ( V_128 )
F_53 ( & V_129 ) ;
#endif
#if F_50 ( V_131 )
F_54 ( & V_132 ) ;
#endif
}
