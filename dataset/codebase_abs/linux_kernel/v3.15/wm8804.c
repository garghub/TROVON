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
unsigned int V_59 )
{
T_2 V_60 ;
unsigned long int V_61 , V_62 , V_63 , V_64 ;
int V_65 ;
for ( V_65 = 0 ; V_65 < F_14 ( V_66 ) ; V_65 ++ ) {
V_64 = V_58 * V_66 [ V_65 ] . div ;
if ( V_64 >= 90000000 && V_64 <= 100000000 ) {
V_57 -> V_67 = V_66 [ V_65 ] . V_67 ;
V_57 -> V_68 = V_66 [ V_65 ] . V_68 ;
V_58 *= V_66 [ V_65 ] . div ;
break;
}
}
if ( V_65 == F_14 ( V_66 ) ) {
F_15 ( L_5 ,
V_69 , V_58 ) ;
return - V_11 ;
}
V_57 -> V_70 = 0 ;
V_62 = V_58 / V_59 ;
if ( V_62 < 5 ) {
V_59 >>= 1 ;
V_57 -> V_70 = 1 ;
V_62 = V_58 / V_59 ;
}
if ( V_62 < 5 || V_62 > 13 ) {
F_15 ( L_6 ,
V_69 , V_62 ) ;
return - V_11 ;
}
V_57 -> V_71 = V_62 ;
V_63 = V_58 % V_59 ;
V_60 = V_72 * ( T_2 ) V_63 ;
F_16 ( V_60 , V_59 ) ;
V_61 = V_60 & 0xffffffff ;
if ( ( V_61 % 10 ) >= 5 )
V_61 += 5 ;
V_61 /= 10 ;
V_57 -> V_73 = V_61 ;
return 0 ;
}
static int F_17 ( struct V_26 * V_27 , int V_74 ,
int V_59 , unsigned int V_75 ,
unsigned int V_76 )
{
struct V_5 * V_6 ;
V_6 = V_27 -> V_6 ;
if ( ! V_75 || ! V_76 ) {
F_5 ( V_6 , V_12 , 0x1 , 0x1 ) ;
return 0 ;
} else {
int V_77 ;
struct V_57 V_57 ;
V_77 = F_13 ( & V_57 , V_76 , V_75 ) ;
if ( V_77 )
return V_77 ;
F_5 ( V_6 , V_12 , 0x1 , 0x1 ) ;
F_5 ( V_6 , V_78 , 0xf | 0x10 ,
V_57 . V_71 | ( V_57 . V_70 << 4 ) ) ;
F_5 ( V_6 , V_79 , 0x3 | 0x8 ,
V_57 . V_67 | ( V_57 . V_68 << 3 ) ) ;
F_8 ( V_6 , V_80 , V_57 . V_73 & 0xff ) ;
F_8 ( V_6 , V_81 , ( V_57 . V_73 >> 8 ) & 0xff ) ;
F_8 ( V_6 , V_82 , V_57 . V_73 >> 16 ) ;
F_5 ( V_6 , V_12 , 0x1 , 0 ) ;
}
return 0 ;
}
static int F_18 ( struct V_26 * V_27 ,
int V_83 , unsigned int V_84 , int V_85 )
{
struct V_5 * V_6 ;
V_6 = V_27 -> V_6 ;
switch ( V_83 ) {
case V_86 :
if ( ( V_84 >= 10000000 && V_84 <= 14400000 )
|| ( V_84 >= 16280000 && V_84 <= 27000000 ) )
F_5 ( V_6 , V_87 , 0x80 , 0x80 ) ;
else {
F_10 ( V_27 -> V_14 , L_7
L_8 , V_84 ) ;
return - V_11 ;
}
break;
case V_88 :
F_5 ( V_6 , V_87 , 0x80 , 0 ) ;
break;
case V_89 :
F_5 ( V_6 , V_87 , 0x8 , 0 ) ;
break;
case V_90 :
F_5 ( V_6 , V_87 , 0x8 , 0x8 ) ;
break;
default:
F_10 ( V_27 -> V_14 , L_9 , V_83 ) ;
return - V_11 ;
}
return 0 ;
}
static int F_19 ( struct V_26 * V_27 ,
int V_91 , int div )
{
struct V_5 * V_6 ;
V_6 = V_27 -> V_6 ;
switch ( V_91 ) {
case V_92 :
F_5 ( V_6 , V_79 , 0x30 ,
( div & 0x3 ) << 4 ) ;
break;
default:
F_10 ( V_27 -> V_14 , L_10 , V_91 ) ;
return - V_11 ;
}
return 0 ;
}
static int F_20 ( struct V_5 * V_6 ,
enum V_93 V_94 )
{
int V_77 ;
struct V_95 * V_96 ;
V_96 = F_21 ( V_6 ) ;
switch ( V_94 ) {
case V_97 :
break;
case V_98 :
F_5 ( V_6 , V_12 , 0x9 , 0 ) ;
break;
case V_99 :
if ( V_6 -> V_100 . V_101 == V_102 ) {
V_77 = F_22 ( F_14 ( V_96 -> V_103 ) ,
V_96 -> V_103 ) ;
if ( V_77 ) {
F_10 ( V_6 -> V_14 ,
L_11 ,
V_77 ) ;
return V_77 ;
}
F_23 ( V_96 -> V_104 ) ;
}
F_5 ( V_6 , V_12 , 0x9 , 0x9 ) ;
break;
case V_102 :
F_5 ( V_6 , V_12 , 0x9 , 0x9 ) ;
F_24 ( F_14 ( V_96 -> V_103 ) ,
V_96 -> V_103 ) ;
break;
}
V_6 -> V_100 . V_101 = V_94 ;
return 0 ;
}
static int F_25 ( struct V_5 * V_6 )
{
F_20 ( V_6 , V_102 ) ;
return 0 ;
}
static int F_26 ( struct V_5 * V_6 )
{
F_20 ( V_6 , V_99 ) ;
return 0 ;
}
static int F_27 ( struct V_5 * V_6 )
{
struct V_95 * V_96 ;
int V_65 ;
V_96 = F_21 ( V_6 ) ;
F_20 ( V_6 , V_102 ) ;
for ( V_65 = 0 ; V_65 < F_14 ( V_96 -> V_103 ) ; ++ V_65 )
F_28 ( V_96 -> V_103 [ V_65 ] . V_105 ,
& V_96 -> V_106 [ V_65 ] ) ;
F_29 ( F_14 ( V_96 -> V_103 ) , V_96 -> V_103 ) ;
return 0 ;
}
static int F_30 ( struct V_5 * V_6 )
{
struct V_95 * V_96 ;
int V_65 , V_107 , V_108 , V_77 ;
V_96 = F_21 ( V_6 ) ;
for ( V_65 = 0 ; V_65 < F_14 ( V_96 -> V_103 ) ; V_65 ++ )
V_96 -> V_103 [ V_65 ] . V_109 = V_110 [ V_65 ] ;
V_77 = F_31 ( V_6 -> V_14 , F_14 ( V_96 -> V_103 ) ,
V_96 -> V_103 ) ;
if ( V_77 ) {
F_10 ( V_6 -> V_14 , L_12 , V_77 ) ;
return V_77 ;
}
V_96 -> V_106 [ 0 ] . V_111 = V_112 ;
V_96 -> V_106 [ 1 ] . V_111 = V_113 ;
for ( V_65 = 0 ; V_65 < F_14 ( V_96 -> V_103 ) ; V_65 ++ ) {
V_77 = F_32 ( V_96 -> V_103 [ V_65 ] . V_105 ,
& V_96 -> V_106 [ V_65 ] ) ;
if ( V_77 != 0 ) {
F_10 ( V_6 -> V_14 ,
L_13 ,
V_77 ) ;
}
}
V_77 = F_22 ( F_14 ( V_96 -> V_103 ) ,
V_96 -> V_103 ) ;
if ( V_77 ) {
F_10 ( V_6 -> V_14 , L_11 , V_77 ) ;
goto V_114;
}
V_107 = F_3 ( V_6 , V_16 ) ;
if ( V_107 < 0 ) {
F_10 ( V_6 -> V_14 , L_14 , V_107 ) ;
V_77 = V_107 ;
goto V_115;
}
V_108 = F_3 ( V_6 , V_17 ) ;
if ( V_108 < 0 ) {
F_10 ( V_6 -> V_14 , L_14 , V_108 ) ;
V_77 = V_108 ;
goto V_115;
}
V_108 = ( V_108 << 8 ) | V_107 ;
if ( V_108 != 0x8805 ) {
F_10 ( V_6 -> V_14 , L_15 , V_108 ) ;
V_77 = - V_11 ;
goto V_115;
}
V_77 = F_3 ( V_6 , V_18 ) ;
if ( V_77 < 0 ) {
F_10 ( V_6 -> V_14 , L_16 ,
V_77 ) ;
goto V_115;
}
F_33 ( V_6 -> V_14 , L_17 , V_77 + 'A' ) ;
V_77 = F_7 ( V_6 ) ;
if ( V_77 < 0 ) {
F_10 ( V_6 -> V_14 , L_18 , V_77 ) ;
goto V_115;
}
F_20 ( V_6 , V_99 ) ;
return 0 ;
V_115:
F_24 ( F_14 ( V_96 -> V_103 ) , V_96 -> V_103 ) ;
V_114:
F_29 ( F_14 ( V_96 -> V_103 ) , V_96 -> V_103 ) ;
return V_77 ;
}
static int F_34 ( struct V_116 * V_117 )
{
struct V_95 * V_96 ;
int V_77 ;
V_96 = F_35 ( & V_117 -> V_14 , sizeof *V_96 , V_118 ) ;
if ( ! V_96 )
return - V_119 ;
V_96 -> V_104 = F_36 ( V_117 , & V_120 ) ;
if ( F_37 ( V_96 -> V_104 ) ) {
V_77 = F_38 ( V_96 -> V_104 ) ;
return V_77 ;
}
F_39 ( V_117 , V_96 ) ;
V_77 = F_40 ( & V_117 -> V_14 ,
& V_121 , & V_122 , 1 ) ;
return V_77 ;
}
static int F_41 ( struct V_116 * V_117 )
{
F_42 ( & V_117 -> V_14 ) ;
return 0 ;
}
static int F_43 ( struct V_123 * V_124 ,
const struct V_125 * V_126 )
{
struct V_95 * V_96 ;
int V_77 ;
V_96 = F_35 ( & V_124 -> V_14 , sizeof *V_96 , V_118 ) ;
if ( ! V_96 )
return - V_119 ;
V_96 -> V_104 = F_44 ( V_124 , & V_120 ) ;
if ( F_37 ( V_96 -> V_104 ) ) {
V_77 = F_38 ( V_96 -> V_104 ) ;
return V_77 ;
}
F_45 ( V_124 , V_96 ) ;
V_77 = F_40 ( & V_124 -> V_14 ,
& V_121 , & V_122 , 1 ) ;
return V_77 ;
}
static int F_46 ( struct V_123 * V_124 )
{
F_42 ( & V_124 -> V_14 ) ;
return 0 ;
}
static int T_3 F_47 ( void )
{
int V_77 = 0 ;
#if F_48 ( V_127 )
V_77 = F_49 ( & V_128 ) ;
if ( V_77 ) {
F_50 ( V_129 L_19 ,
V_77 ) ;
}
#endif
#if F_51 ( V_130 )
V_77 = F_52 ( & V_131 ) ;
if ( V_77 != 0 ) {
F_50 ( V_129 L_20 ,
V_77 ) ;
}
#endif
return V_77 ;
}
static void T_4 F_53 ( void )
{
#if F_48 ( V_127 )
F_54 ( & V_128 ) ;
#endif
#if F_51 ( V_130 )
F_55 ( & V_131 ) ;
#endif
}
