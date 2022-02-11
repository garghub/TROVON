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
case 16 :
V_53 = 0x0 ;
break;
case 20 :
V_53 = 0x1 ;
break;
case 24 :
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
static int F_13 ( struct V_54 * V_54 , unsigned int V_55 ,
unsigned int V_56 , unsigned int V_57 )
{
T_2 V_58 ;
unsigned long int V_59 , V_60 , V_61 , V_62 ;
int V_63 ;
for ( V_63 = 0 ; V_63 < F_14 ( V_64 ) ; V_63 ++ ) {
V_62 = V_55 * V_64 [ V_63 ] . div ;
if ( ( V_62 >= 90000000 && V_62 <= 100000000 ) &&
( V_57 == V_64 [ V_63 ] . V_65 ) ) {
V_54 -> V_66 = V_64 [ V_63 ] . V_66 ;
V_54 -> V_65 = V_64 [ V_63 ] . V_65 ;
V_55 *= V_64 [ V_63 ] . div ;
break;
}
}
if ( V_63 == F_14 ( V_64 ) ) {
F_15 ( L_5 ,
V_67 , V_55 ) ;
return - V_11 ;
}
V_54 -> V_68 = 0 ;
V_60 = V_55 / V_56 ;
if ( V_60 < 5 ) {
V_56 >>= 1 ;
V_54 -> V_68 = 1 ;
V_60 = V_55 / V_56 ;
}
if ( V_60 < 5 || V_60 > 13 ) {
F_15 ( L_6 ,
V_67 , V_60 ) ;
return - V_11 ;
}
V_54 -> V_69 = V_60 ;
V_61 = V_55 % V_56 ;
V_58 = V_70 * ( T_2 ) V_61 ;
F_16 ( V_58 , V_56 ) ;
V_59 = V_58 & 0xffffffff ;
if ( ( V_59 % 10 ) >= 5 )
V_59 += 5 ;
V_59 /= 10 ;
V_54 -> V_71 = V_59 ;
return 0 ;
}
static int F_17 ( struct V_26 * V_27 , int V_72 ,
int V_56 , unsigned int V_73 ,
unsigned int V_74 )
{
struct V_5 * V_6 ;
V_6 = V_27 -> V_6 ;
if ( ! V_73 || ! V_74 ) {
F_5 ( V_6 , V_12 , 0x1 , 0x1 ) ;
return 0 ;
} else {
int V_75 ;
struct V_54 V_54 ;
struct V_76 * V_77 ;
V_77 = F_18 ( V_6 ) ;
V_75 = F_13 ( & V_54 , V_74 , V_73 ,
V_77 -> V_57 ) ;
if ( V_75 )
return V_75 ;
F_5 ( V_6 , V_12 , 0x1 , 0x1 ) ;
F_5 ( V_6 , V_78 , 0xf | 0x10 ,
V_54 . V_69 | ( V_54 . V_68 << 4 ) ) ;
F_5 ( V_6 , V_79 , 0x3 | 0x8 ,
V_54 . V_66 | ( V_54 . V_65 << 3 ) ) ;
F_8 ( V_6 , V_80 , V_54 . V_71 & 0xff ) ;
F_8 ( V_6 , V_81 , ( V_54 . V_71 >> 8 ) & 0xff ) ;
F_8 ( V_6 , V_82 , V_54 . V_71 >> 16 ) ;
F_5 ( V_6 , V_12 , 0x1 , 0 ) ;
}
return 0 ;
}
static int F_19 ( struct V_26 * V_27 ,
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
static int F_20 ( struct V_26 * V_27 ,
int V_91 , int div )
{
struct V_5 * V_6 ;
struct V_76 * V_77 ;
V_6 = V_27 -> V_6 ;
switch ( V_91 ) {
case V_92 :
F_5 ( V_6 , V_79 , 0x30 ,
( div & 0x3 ) << 4 ) ;
break;
case V_93 :
V_77 = F_18 ( V_6 ) ;
V_77 -> V_57 = div ;
break;
default:
F_10 ( V_27 -> V_14 , L_10 , V_91 ) ;
return - V_11 ;
}
return 0 ;
}
static int F_21 ( struct V_5 * V_6 ,
enum V_94 V_95 )
{
int V_75 ;
struct V_76 * V_77 ;
V_77 = F_18 ( V_6 ) ;
switch ( V_95 ) {
case V_96 :
break;
case V_97 :
F_5 ( V_6 , V_12 , 0x9 , 0 ) ;
break;
case V_98 :
if ( V_6 -> V_99 . V_100 == V_101 ) {
V_75 = F_22 ( F_14 ( V_77 -> V_102 ) ,
V_77 -> V_102 ) ;
if ( V_75 ) {
F_10 ( V_6 -> V_14 ,
L_11 ,
V_75 ) ;
return V_75 ;
}
F_23 ( V_77 -> V_103 ) ;
}
F_5 ( V_6 , V_12 , 0x9 , 0x9 ) ;
break;
case V_101 :
F_5 ( V_6 , V_12 , 0x9 , 0x9 ) ;
F_24 ( F_14 ( V_77 -> V_102 ) ,
V_77 -> V_102 ) ;
break;
}
V_6 -> V_99 . V_100 = V_95 ;
return 0 ;
}
static int F_25 ( struct V_5 * V_6 )
{
struct V_76 * V_77 ;
int V_63 ;
V_77 = F_18 ( V_6 ) ;
F_21 ( V_6 , V_101 ) ;
for ( V_63 = 0 ; V_63 < F_14 ( V_77 -> V_102 ) ; ++ V_63 )
F_26 ( V_77 -> V_102 [ V_63 ] . V_104 ,
& V_77 -> V_105 [ V_63 ] ) ;
return 0 ;
}
static int F_27 ( struct V_5 * V_6 )
{
struct V_76 * V_77 ;
int V_63 , V_106 , V_107 , V_75 ;
V_77 = F_18 ( V_6 ) ;
for ( V_63 = 0 ; V_63 < F_14 ( V_77 -> V_102 ) ; V_63 ++ )
V_77 -> V_102 [ V_63 ] . V_108 = V_109 [ V_63 ] ;
V_75 = F_28 ( V_6 -> V_14 , F_14 ( V_77 -> V_102 ) ,
V_77 -> V_102 ) ;
if ( V_75 ) {
F_10 ( V_6 -> V_14 , L_12 , V_75 ) ;
return V_75 ;
}
V_77 -> V_105 [ 0 ] . V_110 = V_111 ;
V_77 -> V_105 [ 1 ] . V_110 = V_112 ;
for ( V_63 = 0 ; V_63 < F_14 ( V_77 -> V_102 ) ; V_63 ++ ) {
V_75 = F_29 ( V_77 -> V_102 [ V_63 ] . V_104 ,
& V_77 -> V_105 [ V_63 ] ) ;
if ( V_75 != 0 ) {
F_10 ( V_6 -> V_14 ,
L_13 ,
V_75 ) ;
}
}
V_75 = F_22 ( F_14 ( V_77 -> V_102 ) ,
V_77 -> V_102 ) ;
if ( V_75 ) {
F_10 ( V_6 -> V_14 , L_11 , V_75 ) ;
return V_75 ;
}
V_106 = F_3 ( V_6 , V_16 ) ;
if ( V_106 < 0 ) {
F_10 ( V_6 -> V_14 , L_14 , V_106 ) ;
V_75 = V_106 ;
goto V_113;
}
V_107 = F_3 ( V_6 , V_17 ) ;
if ( V_107 < 0 ) {
F_10 ( V_6 -> V_14 , L_14 , V_107 ) ;
V_75 = V_107 ;
goto V_113;
}
V_107 = ( V_107 << 8 ) | V_106 ;
if ( V_107 != 0x8805 ) {
F_10 ( V_6 -> V_14 , L_15 , V_107 ) ;
V_75 = - V_11 ;
goto V_113;
}
V_75 = F_3 ( V_6 , V_18 ) ;
if ( V_75 < 0 ) {
F_10 ( V_6 -> V_14 , L_16 ,
V_75 ) ;
goto V_113;
}
F_30 ( V_6 -> V_14 , L_17 , V_75 + 'A' ) ;
V_75 = F_7 ( V_6 ) ;
if ( V_75 < 0 ) {
F_10 ( V_6 -> V_14 , L_18 , V_75 ) ;
goto V_113;
}
F_21 ( V_6 , V_98 ) ;
return 0 ;
V_113:
F_24 ( F_14 ( V_77 -> V_102 ) , V_77 -> V_102 ) ;
return V_75 ;
}
static int F_31 ( struct V_114 * V_115 )
{
struct V_76 * V_77 ;
int V_75 ;
V_77 = F_32 ( & V_115 -> V_14 , sizeof *V_77 , V_116 ) ;
if ( ! V_77 )
return - V_117 ;
V_77 -> V_103 = F_33 ( V_115 , & V_118 ) ;
if ( F_34 ( V_77 -> V_103 ) ) {
V_75 = F_35 ( V_77 -> V_103 ) ;
return V_75 ;
}
F_36 ( V_115 , V_77 ) ;
V_75 = F_37 ( & V_115 -> V_14 ,
& V_119 , & V_120 , 1 ) ;
return V_75 ;
}
static int F_38 ( struct V_114 * V_115 )
{
F_39 ( & V_115 -> V_14 ) ;
return 0 ;
}
static int F_40 ( struct V_121 * V_122 ,
const struct V_123 * V_124 )
{
struct V_76 * V_77 ;
int V_75 ;
V_77 = F_32 ( & V_122 -> V_14 , sizeof *V_77 , V_116 ) ;
if ( ! V_77 )
return - V_117 ;
V_77 -> V_103 = F_41 ( V_122 , & V_118 ) ;
if ( F_34 ( V_77 -> V_103 ) ) {
V_75 = F_35 ( V_77 -> V_103 ) ;
return V_75 ;
}
F_42 ( V_122 , V_77 ) ;
V_75 = F_37 ( & V_122 -> V_14 ,
& V_119 , & V_120 , 1 ) ;
return V_75 ;
}
static int F_43 ( struct V_121 * V_122 )
{
F_39 ( & V_122 -> V_14 ) ;
return 0 ;
}
static int T_3 F_44 ( void )
{
int V_75 = 0 ;
#if F_45 ( V_125 )
V_75 = F_46 ( & V_126 ) ;
if ( V_75 ) {
F_47 ( V_127 L_19 ,
V_75 ) ;
}
#endif
#if F_48 ( V_128 )
V_75 = F_49 ( & V_129 ) ;
if ( V_75 != 0 ) {
F_47 ( V_127 L_20 ,
V_75 ) ;
}
#endif
return V_75 ;
}
static void T_4 F_50 ( void )
{
#if F_45 ( V_125 )
F_51 ( & V_126 ) ;
#endif
#if F_48 ( V_128 )
F_52 ( & V_129 ) ;
#endif
}
