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
static int F_6 ( struct V_5 * V_6 , unsigned int V_13 )
{
switch ( V_13 ) {
case V_14 :
case V_15 :
case V_16 :
case V_17 :
case V_18 :
case V_19 :
case V_20 :
case V_21 :
case V_22 :
case V_23 :
return 1 ;
default:
break;
}
return 0 ;
}
static int F_7 ( struct V_5 * V_6 )
{
return F_8 ( V_6 , V_14 , 0x0 ) ;
}
static int F_9 ( struct V_24 * V_25 , unsigned int V_26 )
{
struct V_5 * V_6 ;
T_1 V_27 , V_28 , V_29 , V_30 ;
V_6 = V_25 -> V_6 ;
switch ( V_26 & V_31 ) {
case V_32 :
V_27 = 0x2 ;
break;
case V_33 :
V_27 = 0x0 ;
break;
case V_34 :
V_27 = 0x1 ;
break;
case V_35 :
case V_36 :
V_27 = 0x3 ;
break;
default:
F_10 ( V_25 -> V_37 , L_1 ) ;
return - V_11 ;
}
F_5 ( V_6 , V_38 , 0x3 , V_27 ) ;
F_5 ( V_6 , V_39 , 0x3 , V_27 ) ;
switch ( V_26 & V_40 ) {
case V_41 :
V_28 = 1 ;
break;
case V_42 :
V_28 = 0 ;
break;
default:
F_10 ( V_25 -> V_37 , L_2 ) ;
return - V_11 ;
}
F_5 ( V_6 , V_39 , 0x40 , V_28 << 6 ) ;
V_29 = V_30 = 0 ;
switch ( V_26 & V_43 ) {
case V_44 :
break;
case V_45 :
V_29 = V_30 = 1 ;
break;
case V_46 :
V_29 = 1 ;
break;
case V_47 :
V_30 = 1 ;
break;
default:
F_10 ( V_25 -> V_37 , L_3 ) ;
return - V_11 ;
}
F_5 ( V_6 , V_38 , 0x10 | 0x20 ,
( V_29 << 4 ) | ( V_30 << 5 ) ) ;
F_5 ( V_6 , V_39 , 0x10 | 0x20 ,
( V_29 << 4 ) | ( V_30 << 5 ) ) ;
return 0 ;
}
static int F_11 ( struct V_48 * V_49 ,
struct V_50 * V_51 ,
struct V_24 * V_25 )
{
struct V_5 * V_6 ;
T_1 V_52 ;
V_6 = V_25 -> V_6 ;
switch ( F_12 ( V_51 ) ) {
case V_53 :
V_52 = 0x0 ;
break;
case V_54 :
V_52 = 0x1 ;
break;
case V_55 :
V_52 = 0x2 ;
break;
default:
F_10 ( V_25 -> V_37 , L_4 ,
F_12 ( V_51 ) ) ;
return - V_11 ;
}
F_5 ( V_6 , V_38 , 0xc , V_52 << 2 ) ;
F_5 ( V_6 , V_39 , 0xc , V_52 << 2 ) ;
return 0 ;
}
static int F_13 ( struct V_56 * V_56 , unsigned int V_57 ,
unsigned int V_58 )
{
T_2 V_59 ;
unsigned long int V_60 , V_61 , V_62 , V_63 ;
int V_64 ;
for ( V_64 = 0 ; V_64 < F_14 ( V_65 ) ; V_64 ++ ) {
V_63 = V_57 * V_65 [ V_64 ] . div ;
if ( V_63 >= 90000000 && V_63 <= 100000000 ) {
V_56 -> V_66 = V_65 [ V_64 ] . V_66 ;
V_56 -> V_67 = V_65 [ V_64 ] . V_67 ;
V_57 *= V_65 [ V_64 ] . div ;
break;
}
}
if ( V_64 == F_14 ( V_65 ) ) {
F_15 ( L_5 ,
V_68 , V_57 ) ;
return - V_11 ;
}
V_56 -> V_69 = 0 ;
V_61 = V_57 / V_58 ;
if ( V_61 < 5 ) {
V_58 >>= 1 ;
V_56 -> V_69 = 1 ;
V_61 = V_57 / V_58 ;
}
if ( V_61 < 5 || V_61 > 13 ) {
F_15 ( L_6 ,
V_68 , V_61 ) ;
return - V_11 ;
}
V_56 -> V_70 = V_61 ;
V_62 = V_57 % V_58 ;
V_59 = V_71 * ( T_2 ) V_62 ;
F_16 ( V_59 , V_58 ) ;
V_60 = V_59 & 0xffffffff ;
if ( ( V_60 % 10 ) >= 5 )
V_60 += 5 ;
V_60 /= 10 ;
V_56 -> V_72 = V_60 ;
return 0 ;
}
static int F_17 ( struct V_24 * V_25 , int V_73 ,
int V_58 , unsigned int V_74 ,
unsigned int V_75 )
{
struct V_5 * V_6 ;
V_6 = V_25 -> V_6 ;
if ( ! V_74 || ! V_75 ) {
F_5 ( V_6 , V_12 , 0x1 , 0x1 ) ;
return 0 ;
} else {
int V_76 ;
struct V_56 V_56 ;
V_76 = F_13 ( & V_56 , V_75 , V_74 ) ;
if ( V_76 )
return V_76 ;
F_5 ( V_6 , V_12 , 0x1 , 0x1 ) ;
if ( ! V_74 || ! V_75 )
return 0 ;
F_5 ( V_6 , V_77 , 0xf | 0x10 ,
V_56 . V_70 | ( V_56 . V_69 << 4 ) ) ;
F_5 ( V_6 , V_78 , 0x3 | 0x8 ,
V_56 . V_66 | ( V_56 . V_67 << 3 ) ) ;
F_8 ( V_6 , V_79 , V_56 . V_72 & 0xff ) ;
F_8 ( V_6 , V_80 , ( V_56 . V_72 >> 8 ) & 0xff ) ;
F_8 ( V_6 , V_81 , V_56 . V_72 >> 16 ) ;
F_5 ( V_6 , V_12 , 0x1 , 0 ) ;
}
return 0 ;
}
static int F_18 ( struct V_24 * V_25 ,
int V_82 , unsigned int V_83 , int V_84 )
{
struct V_5 * V_6 ;
V_6 = V_25 -> V_6 ;
switch ( V_82 ) {
case V_85 :
if ( ( V_83 >= 10000000 && V_83 <= 14400000 )
|| ( V_83 >= 16280000 && V_83 <= 27000000 ) )
F_5 ( V_6 , V_86 , 0x80 , 0x80 ) ;
else {
F_10 ( V_25 -> V_37 , L_7
L_8 , V_83 ) ;
return - V_11 ;
}
break;
case V_87 :
F_5 ( V_6 , V_86 , 0x80 , 0 ) ;
break;
case V_88 :
F_5 ( V_6 , V_86 , 0x8 , 0 ) ;
break;
case V_89 :
F_5 ( V_6 , V_86 , 0x8 , 0x8 ) ;
break;
default:
F_10 ( V_25 -> V_37 , L_9 , V_82 ) ;
return - V_11 ;
}
return 0 ;
}
static int F_19 ( struct V_24 * V_25 ,
int V_90 , int div )
{
struct V_5 * V_6 ;
V_6 = V_25 -> V_6 ;
switch ( V_90 ) {
case V_91 :
F_5 ( V_6 , V_78 , 0x30 ,
( div & 0x3 ) << 4 ) ;
break;
default:
F_10 ( V_25 -> V_37 , L_10 , V_90 ) ;
return - V_11 ;
}
return 0 ;
}
static void F_20 ( struct V_5 * V_6 )
{
short V_64 ;
T_3 * V_92 ;
if ( ! V_6 -> V_93 )
return;
V_6 -> V_94 = 0 ;
V_92 = V_6 -> V_95 ;
for ( V_64 = 0 ; V_64 < V_6 -> V_96 -> V_97 ; V_64 ++ ) {
if ( V_64 == V_14 || V_92 [ V_64 ] == V_98 [ V_64 ] )
continue;
F_8 ( V_6 , V_64 , V_92 [ V_64 ] ) ;
}
V_6 -> V_93 = 0 ;
}
static int F_21 ( struct V_5 * V_6 ,
enum V_99 V_100 )
{
int V_76 ;
struct V_101 * V_102 ;
V_102 = F_22 ( V_6 ) ;
switch ( V_100 ) {
case V_103 :
break;
case V_104 :
F_5 ( V_6 , V_12 , 0x9 , 0 ) ;
break;
case V_105 :
if ( V_6 -> V_106 . V_107 == V_108 ) {
V_76 = F_23 ( F_14 ( V_102 -> V_109 ) ,
V_102 -> V_109 ) ;
if ( V_76 ) {
F_10 ( V_6 -> V_37 ,
L_11 ,
V_76 ) ;
return V_76 ;
}
F_20 ( V_6 ) ;
}
F_5 ( V_6 , V_12 , 0x9 , 0x9 ) ;
break;
case V_108 :
F_5 ( V_6 , V_12 , 0x9 , 0x9 ) ;
F_24 ( F_14 ( V_102 -> V_109 ) ,
V_102 -> V_109 ) ;
break;
}
V_6 -> V_106 . V_107 = V_100 ;
return 0 ;
}
static int F_25 ( struct V_5 * V_6 , T_4 V_110 )
{
F_21 ( V_6 , V_108 ) ;
return 0 ;
}
static int F_26 ( struct V_5 * V_6 )
{
F_21 ( V_6 , V_105 ) ;
return 0 ;
}
static int F_27 ( struct V_5 * V_6 )
{
struct V_101 * V_102 ;
int V_64 ;
V_102 = F_22 ( V_6 ) ;
F_21 ( V_6 , V_108 ) ;
for ( V_64 = 0 ; V_64 < F_14 ( V_102 -> V_109 ) ; ++ V_64 )
F_28 ( V_102 -> V_109 [ V_64 ] . V_111 ,
& V_102 -> V_112 [ V_64 ] ) ;
F_29 ( F_14 ( V_102 -> V_109 ) , V_102 -> V_109 ) ;
return 0 ;
}
static int F_30 ( struct V_5 * V_6 )
{
struct V_101 * V_102 ;
int V_64 , V_113 , V_114 , V_76 ;
V_102 = F_22 ( V_6 ) ;
V_102 -> V_6 = V_6 ;
V_6 -> V_106 . V_115 = 1 ;
V_76 = F_31 ( V_6 , 8 , 8 , V_102 -> V_116 ) ;
if ( V_76 < 0 ) {
F_10 ( V_6 -> V_37 , L_12 , V_76 ) ;
return V_76 ;
}
for ( V_64 = 0 ; V_64 < F_14 ( V_102 -> V_109 ) ; V_64 ++ )
V_102 -> V_109 [ V_64 ] . V_117 = V_118 [ V_64 ] ;
V_76 = F_32 ( V_6 -> V_37 , F_14 ( V_102 -> V_109 ) ,
V_102 -> V_109 ) ;
if ( V_76 ) {
F_10 ( V_6 -> V_37 , L_13 , V_76 ) ;
return V_76 ;
}
V_102 -> V_112 [ 0 ] . V_119 = V_120 ;
V_102 -> V_112 [ 1 ] . V_119 = V_121 ;
for ( V_64 = 0 ; V_64 < F_14 ( V_102 -> V_109 ) ; V_64 ++ ) {
V_76 = F_33 ( V_102 -> V_109 [ V_64 ] . V_111 ,
& V_102 -> V_112 [ V_64 ] ) ;
if ( V_76 != 0 ) {
F_10 ( V_6 -> V_37 ,
L_14 ,
V_76 ) ;
}
}
V_76 = F_23 ( F_14 ( V_102 -> V_109 ) ,
V_102 -> V_109 ) ;
if ( V_76 ) {
F_10 ( V_6 -> V_37 , L_11 , V_76 ) ;
goto V_122;
}
V_113 = F_3 ( V_6 , V_14 ) ;
if ( V_113 < 0 ) {
F_10 ( V_6 -> V_37 , L_15 , V_113 ) ;
V_76 = V_113 ;
goto V_123;
}
V_114 = F_3 ( V_6 , V_15 ) ;
if ( V_114 < 0 ) {
F_10 ( V_6 -> V_37 , L_15 , V_114 ) ;
V_76 = V_114 ;
goto V_123;
}
V_114 = ( V_114 << 8 ) | V_113 ;
if ( V_114 != ( ( V_98 [ V_15 ] << 8 )
| V_98 [ V_14 ] ) ) {
F_10 ( V_6 -> V_37 , L_16 , V_114 ) ;
V_76 = - V_11 ;
goto V_123;
}
V_76 = F_3 ( V_6 , V_16 ) ;
if ( V_76 < 0 ) {
F_10 ( V_6 -> V_37 , L_17 ,
V_76 ) ;
goto V_123;
}
F_34 ( V_6 -> V_37 , L_18 , V_76 + 'A' ) ;
V_76 = F_7 ( V_6 ) ;
if ( V_76 < 0 ) {
F_10 ( V_6 -> V_37 , L_19 , V_76 ) ;
goto V_123;
}
F_21 ( V_6 , V_105 ) ;
F_35 ( V_6 , V_124 ,
F_14 ( V_124 ) ) ;
return 0 ;
V_123:
F_24 ( F_14 ( V_102 -> V_109 ) , V_102 -> V_109 ) ;
V_122:
F_29 ( F_14 ( V_102 -> V_109 ) , V_102 -> V_109 ) ;
return V_76 ;
}
static int T_5 F_36 ( struct V_125 * V_126 )
{
struct V_101 * V_102 ;
int V_76 ;
V_102 = F_37 ( sizeof *V_102 , V_127 ) ;
if ( ! V_102 )
return - V_128 ;
V_102 -> V_116 = V_129 ;
F_38 ( V_126 , V_102 ) ;
V_76 = F_39 ( & V_126 -> V_37 ,
& V_130 , & V_131 , 1 ) ;
if ( V_76 < 0 )
F_40 ( V_102 ) ;
return V_76 ;
}
static int T_6 F_41 ( struct V_125 * V_126 )
{
F_42 ( & V_126 -> V_37 ) ;
F_40 ( F_43 ( V_126 ) ) ;
return 0 ;
}
static T_5 int F_44 ( struct V_132 * V_133 ,
const struct V_134 * V_135 )
{
struct V_101 * V_102 ;
int V_76 ;
V_102 = F_37 ( sizeof *V_102 , V_127 ) ;
if ( ! V_102 )
return - V_128 ;
V_102 -> V_116 = V_136 ;
F_45 ( V_133 , V_102 ) ;
V_76 = F_39 ( & V_133 -> V_37 ,
& V_130 , & V_131 , 1 ) ;
if ( V_76 < 0 )
F_40 ( V_102 ) ;
return V_76 ;
}
static T_6 int F_46 ( struct V_132 * V_137 )
{
F_42 ( & V_137 -> V_37 ) ;
F_40 ( F_47 ( V_137 ) ) ;
return 0 ;
}
static int T_7 F_48 ( void )
{
int V_76 = 0 ;
#if F_49 ( V_138 ) || F_49 ( V_139 )
V_76 = F_50 ( & V_140 ) ;
if ( V_76 ) {
F_51 ( V_141 L_20 ,
V_76 ) ;
}
#endif
#if F_49 ( V_142 )
V_76 = F_52 ( & V_143 ) ;
if ( V_76 != 0 ) {
F_51 ( V_141 L_21 ,
V_76 ) ;
}
#endif
return V_76 ;
}
static void T_8 F_53 ( void )
{
#if F_49 ( V_138 ) || F_49 ( V_139 )
F_54 ( & V_140 ) ;
#endif
#if F_49 ( V_142 )
F_55 ( & V_143 ) ;
#endif
}
