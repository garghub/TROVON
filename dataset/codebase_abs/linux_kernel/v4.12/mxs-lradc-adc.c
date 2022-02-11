static int F_1 ( struct V_1 * V_1 , int V_2 ,
int * V_3 )
{
struct V_4 * V_5 = F_2 ( V_1 ) ;
struct V_6 * V_7 = V_5 -> V_7 ;
int V_8 ;
V_8 = F_3 ( V_1 ) ;
if ( V_8 )
return V_8 ;
F_4 ( & V_5 -> V_9 ) ;
if ( V_7 -> V_10 == V_11 )
F_5 ( F_6 ( 0 ) ,
V_5 -> V_12 + V_13 + V_14 ) ;
F_5 ( 0x1 , V_5 -> V_12 + V_15 + V_14 ) ;
if ( F_7 ( V_2 , & V_5 -> V_16 ) )
F_5 ( 1 << V_17 ,
V_5 -> V_12 + V_18 + V_19 ) ;
else
F_5 ( 1 << V_17 ,
V_5 -> V_12 + V_18 + V_14 ) ;
F_5 ( F_8 ( 0 ) ,
V_5 -> V_12 + V_20 + V_14 ) ;
F_5 ( V_2 , V_5 -> V_12 + V_20 + V_19 ) ;
F_5 ( 0 , V_5 -> V_12 + F_9 ( 0 ) ) ;
F_5 ( F_6 ( 0 ) ,
V_5 -> V_12 + V_13 + V_19 ) ;
F_5 ( F_10 ( 0 ) , V_5 -> V_12 + V_15 + V_19 ) ;
V_8 = F_11 ( & V_5 -> V_9 , V_21 ) ;
if ( ! V_8 )
V_8 = - V_22 ;
if ( V_8 < 0 )
goto V_23;
* V_3 = F_12 ( V_5 -> V_12 + F_9 ( 0 ) ) & V_24 ;
V_8 = V_25 ;
V_23:
F_5 ( F_6 ( 0 ) ,
V_5 -> V_12 + V_13 + V_14 ) ;
F_13 ( V_1 ) ;
return V_8 ;
}
static int F_14 ( struct V_1 * V_1 , int * V_3 )
{
int V_8 , V_26 , V_27 ;
V_8 = F_1 ( V_1 , 8 , & V_26 ) ;
if ( V_8 != V_25 )
return V_8 ;
V_8 = F_1 ( V_1 , 9 , & V_27 ) ;
if ( V_8 != V_25 )
return V_8 ;
* V_3 = V_27 - V_26 ;
return V_25 ;
}
static int F_15 ( struct V_1 * V_1 ,
const struct V_28 * V_2 ,
int * V_3 , int * V_29 , long V_30 )
{
struct V_4 * V_5 = F_2 ( V_1 ) ;
switch ( V_30 ) {
case V_31 :
if ( V_2 -> type == V_32 )
return F_14 ( V_1 , V_3 ) ;
return F_1 ( V_1 , V_2 -> V_33 , V_3 ) ;
case V_34 :
if ( V_2 -> type == V_32 ) {
* V_3 = 0 ;
* V_29 = 253000 ;
return V_35 ;
}
* V_3 = V_5 -> V_36 [ V_2 -> V_33 ] ;
* V_29 = V_2 -> V_37 . V_38 -
F_7 ( V_2 -> V_33 , & V_5 -> V_16 ) ;
return V_39 ;
case V_40 :
if ( V_2 -> type == V_32 ) {
* V_3 = - 1079 ;
* V_29 = 644268 ;
return V_35 ;
}
return - V_41 ;
default:
break;
}
return - V_41 ;
}
static int F_16 ( struct V_1 * V_1 ,
const struct V_28 * V_2 ,
int V_3 , int V_29 , long V_30 )
{
struct V_4 * V_5 = F_2 ( V_1 ) ;
struct V_42 * V_43 =
V_5 -> V_43 [ V_2 -> V_33 ] ;
int V_8 ;
V_8 = F_3 ( V_1 ) ;
if ( V_8 )
return V_8 ;
switch ( V_30 ) {
case V_34 :
V_8 = - V_41 ;
if ( V_3 == V_43 [ V_44 ] . integer &&
V_29 == V_43 [ V_44 ] . V_45 ) {
F_17 ( V_2 -> V_33 , & V_5 -> V_16 ) ;
V_8 = 0 ;
} else if ( V_3 == V_43 [ V_46 ] . integer &&
V_29 == V_43 [ V_46 ] . V_45 ) {
F_18 ( V_2 -> V_33 , & V_5 -> V_16 ) ;
V_8 = 0 ;
}
break;
default:
V_8 = - V_41 ;
break;
}
F_13 ( V_1 ) ;
return V_8 ;
}
static int F_19 ( struct V_1 * V_1 ,
const struct V_28 * V_2 ,
long V_30 )
{
return V_47 ;
}
static T_1 F_20 ( struct V_48 * V_49 ,
struct V_50 * V_51 ,
char * V_52 )
{
struct V_1 * V_53 = F_21 ( V_49 ) ;
struct V_4 * V_5 = F_2 ( V_53 ) ;
struct V_54 * V_55 = F_22 ( V_51 ) ;
int V_56 , V_57 , V_58 = 0 ;
V_57 = V_55 -> V_59 ;
for ( V_56 = 0 ; V_56 < F_23 ( V_5 -> V_43 [ V_57 ] ) ; V_56 ++ )
V_58 += sprintf ( V_52 + V_58 , L_1 ,
V_5 -> V_43 [ V_57 ] [ V_56 ] . integer ,
V_5 -> V_43 [ V_57 ] [ V_56 ] . V_45 ) ;
V_58 += sprintf ( V_52 + V_58 , L_2 ) ;
return V_58 ;
}
static T_2 F_24 ( int V_60 , void * V_61 )
{
struct V_1 * V_53 = V_61 ;
struct V_4 * V_5 = F_2 ( V_53 ) ;
struct V_6 * V_7 = V_5 -> V_7 ;
unsigned long V_62 = F_12 ( V_5 -> V_12 + V_13 ) ;
unsigned long V_63 ;
if ( ! ( V_62 & F_25 ( V_7 ) ) )
return V_64 ;
if ( F_26 ( V_53 ) ) {
if ( V_62 & V_7 -> V_65 ) {
F_27 ( & V_5 -> V_66 , V_63 ) ;
F_28 ( V_53 -> V_67 ) ;
F_29 ( & V_5 -> V_66 , V_63 ) ;
}
} else if ( V_62 & F_30 ( 0 ) ) {
F_31 ( & V_5 -> V_9 ) ;
}
F_5 ( V_62 & F_25 ( V_7 ) ,
V_5 -> V_12 + V_13 + V_14 ) ;
return V_68 ;
}
static T_2 F_32 ( int V_60 , void * V_69 )
{
struct V_70 * V_71 = V_69 ;
struct V_1 * V_53 = V_71 -> V_72 ;
struct V_4 * V_5 = F_2 ( V_53 ) ;
const T_3 V_73 = V_74 |
( ( V_75 - 1 ) << V_76 ) ;
unsigned int V_56 , V_77 = 0 ;
F_33 (i, iio->active_scan_mask, LRADC_MAX_TOTAL_CHANS) {
V_5 -> V_78 [ V_77 ] = F_12 ( V_5 -> V_12 + F_9 ( V_77 ) ) ;
F_5 ( V_73 , V_5 -> V_12 + F_9 ( V_77 ) ) ;
V_5 -> V_78 [ V_77 ] &= V_24 ;
V_5 -> V_78 [ V_77 ] /= V_75 ;
V_77 ++ ;
}
F_34 ( V_53 , V_5 -> V_78 , V_71 -> V_79 ) ;
F_35 ( V_53 -> V_67 ) ;
return V_68 ;
}
static int F_36 ( struct V_80 * V_67 , bool V_81 )
{
struct V_1 * V_53 = F_37 ( V_67 ) ;
struct V_4 * V_5 = F_2 ( V_53 ) ;
const T_3 V_82 = V_81 ? V_19 : V_14 ;
F_5 ( V_83 , V_5 -> V_12 + ( F_38 ( 0 ) + V_82 ) ) ;
return 0 ;
}
static int F_39 ( struct V_1 * V_53 )
{
int V_8 ;
struct V_80 * V_67 ;
struct V_4 * V_5 = F_2 ( V_53 ) ;
V_67 = F_40 ( & V_53 -> V_49 , L_3 , V_53 -> V_84 ,
V_53 -> V_85 ) ;
V_67 -> V_49 . V_86 = V_5 -> V_49 ;
F_41 ( V_67 , V_53 ) ;
V_67 -> V_87 = & V_88 ;
V_8 = F_42 ( V_67 ) ;
if ( V_8 )
return V_8 ;
V_5 -> V_67 = V_67 ;
return 0 ;
}
static void F_43 ( struct V_1 * V_53 )
{
struct V_4 * V_5 = F_2 ( V_53 ) ;
F_44 ( V_5 -> V_67 ) ;
}
static int F_45 ( struct V_1 * V_53 )
{
struct V_4 * V_5 = F_2 ( V_53 ) ;
struct V_6 * V_7 = V_5 -> V_7 ;
int V_2 , V_89 = 0 ;
unsigned long V_90 = 0 ;
T_3 V_91 = 0 ;
T_3 V_92 = 0 ;
T_3 V_93 = 0 ;
const T_3 V_73 = V_74 |
( ( V_75 - 1 ) << V_76 ) ;
if ( V_7 -> V_10 == V_11 )
F_5 ( V_7 -> V_65 << V_94 ,
V_5 -> V_12 + V_13 + V_14 ) ;
F_5 ( V_7 -> V_65 ,
V_5 -> V_12 + V_15 + V_14 ) ;
F_33 (chan, iio->active_scan_mask, LRADC_MAX_TOTAL_CHANS) {
V_91 |= V_2 << F_46 ( V_89 ) ;
V_92 |= F_8 ( V_89 ) ;
V_93 |= F_6 ( V_89 ) ;
F_5 ( V_73 , V_5 -> V_12 + F_9 ( V_89 ) ) ;
F_47 ( & V_90 , V_89 , 1 ) ;
V_89 ++ ;
}
F_5 ( V_95 | V_83 ,
V_5 -> V_12 + F_38 ( 0 ) + V_14 ) ;
F_5 ( V_92 , V_5 -> V_12 + V_20 + V_14 ) ;
F_5 ( V_91 , V_5 -> V_12 + V_20 + V_19 ) ;
F_5 ( V_93 , V_5 -> V_12 + V_13 + V_19 ) ;
F_5 ( V_90 << V_96 ,
V_5 -> V_12 + F_38 ( 0 ) + V_19 ) ;
return 0 ;
}
static int F_48 ( struct V_1 * V_53 )
{
struct V_4 * V_5 = F_2 ( V_53 ) ;
struct V_6 * V_7 = V_5 -> V_7 ;
F_5 ( V_95 | V_83 ,
V_5 -> V_12 + F_38 ( 0 ) + V_14 ) ;
F_5 ( V_7 -> V_65 ,
V_5 -> V_12 + V_15 + V_14 ) ;
if ( V_7 -> V_10 == V_11 )
F_5 ( V_7 -> V_65 << V_94 ,
V_5 -> V_12 + V_13 + V_14 ) ;
return 0 ;
}
static bool F_49 ( struct V_1 * V_53 ,
const unsigned long * V_97 )
{
struct V_4 * V_5 = F_2 ( V_53 ) ;
struct V_6 * V_7 = V_5 -> V_7 ;
const int V_98 = F_50 ( V_97 , V_99 ) ;
int V_100 = 0 ;
unsigned long V_101 = 0 ;
if ( V_7 -> V_102 )
V_101 |= V_103 ;
if ( V_7 -> V_104 == V_105 )
V_101 |= V_106 ;
if ( V_7 -> V_104 == V_107 )
V_101 |= V_108 ;
if ( V_7 -> V_102 )
V_100 ++ ;
if ( V_7 -> V_104 )
V_100 += 2 ;
if ( F_51 ( V_97 , & V_101 , V_99 ) )
return false ;
if ( V_98 + V_100 > V_109 )
return false ;
return true ;
}
static void F_52 ( struct V_4 * V_5 )
{
const T_3 V_110 =
( 1 << ( V_111 + 0 ) ) |
( V_112 << V_113 ) ;
F_5 ( V_110 , V_5 -> V_12 + F_38 ( 0 ) ) ;
F_5 ( 0 , V_5 -> V_12 + V_18 ) ;
}
static void F_53 ( struct V_4 * V_5 )
{
F_5 ( 0 , V_5 -> V_12 + F_38 ( 0 ) ) ;
}
static int F_54 ( struct V_114 * V_115 )
{
struct V_48 * V_49 = & V_115 -> V_49 ;
struct V_6 * V_7 = F_55 ( V_49 -> V_86 ) ;
struct V_4 * V_5 ;
struct V_1 * V_53 ;
struct V_116 * V_117 ;
int V_8 , V_60 , V_118 , V_56 , V_119 , V_120 ;
T_4 V_121 ;
const char * * V_122 ;
V_53 = F_56 ( V_49 , sizeof( * V_5 ) ) ;
if ( ! V_53 ) {
F_57 ( V_49 , L_4 ) ;
return - V_123 ;
}
V_5 = F_2 ( V_53 ) ;
V_5 -> V_7 = V_7 ;
V_5 -> V_49 = V_49 ;
V_117 = F_58 ( V_115 , V_124 , 0 ) ;
if ( ! V_117 )
return - V_41 ;
V_5 -> V_12 = F_59 ( V_49 , V_117 -> V_125 , F_60 ( V_117 ) ) ;
if ( ! V_5 -> V_12 )
return - V_123 ;
F_61 ( & V_5 -> V_9 ) ;
F_62 ( & V_5 -> V_66 ) ;
F_63 ( V_115 , V_53 ) ;
V_53 -> V_84 = V_115 -> V_84 ;
V_53 -> V_49 . V_86 = V_49 ;
V_53 -> V_49 . V_126 = V_49 -> V_86 -> V_126 ;
V_53 -> V_127 = & V_128 ;
V_53 -> V_129 = V_130 ;
V_53 -> V_131 = V_99 ;
if ( V_7 -> V_10 == V_132 ) {
V_53 -> V_133 = V_134 ;
V_53 -> V_135 = F_23 ( V_134 ) ;
V_122 = V_136 ;
V_120 = F_23 ( V_136 ) ;
} else {
V_53 -> V_133 = V_137 ;
V_53 -> V_135 = F_23 ( V_137 ) ;
V_122 = V_138 ;
V_120 = F_23 ( V_138 ) ;
}
V_8 = F_64 ( V_5 -> V_12 ) ;
if ( V_8 )
return V_8 ;
for ( V_56 = 0 ; V_56 < V_120 ; V_56 ++ ) {
V_60 = F_65 ( V_115 , V_122 [ V_56 ] ) ;
if ( V_60 < 0 )
return V_60 ;
V_118 = F_66 ( V_49 -> V_86 -> V_126 , V_60 ) ;
V_8 = F_67 ( V_49 , V_118 , F_24 ,
0 , V_122 [ V_56 ] , V_53 ) ;
if ( V_8 )
return V_8 ;
}
V_8 = F_39 ( V_53 ) ;
if ( V_8 )
goto V_139;
V_8 = F_68 ( V_53 , & V_140 ,
& F_32 ,
& V_141 ) ;
if ( V_8 )
return V_8 ;
V_5 -> V_36 = V_142 [ V_7 -> V_10 ] ;
for ( V_56 = 0 ; V_56 < V_99 ; V_56 ++ ) {
for ( V_119 = 0 ; V_119 < F_23 ( V_5 -> V_43 [ V_56 ] ) ; V_119 ++ ) {
V_121 = ( ( T_4 ) V_5 -> V_36 [ V_56 ] * 100000000 ) >>
( V_143 - V_119 ) ;
V_5 -> V_43 [ V_56 ] [ V_119 ] . V_45 =
F_69 ( V_121 , 100000000 ) * 10 ;
V_5 -> V_43 [ V_56 ] [ V_119 ] . integer = V_121 ;
}
}
F_52 ( V_5 ) ;
V_8 = F_70 ( V_53 ) ;
if ( V_8 ) {
F_57 ( V_49 , L_5 ) ;
goto V_144;
}
return 0 ;
V_144:
F_53 ( V_5 ) ;
F_43 ( V_53 ) ;
V_139:
F_71 ( V_53 ) ;
return V_8 ;
}
static int F_72 ( struct V_114 * V_115 )
{
struct V_1 * V_53 = F_73 ( V_115 ) ;
struct V_4 * V_5 = F_2 ( V_53 ) ;
F_74 ( V_53 ) ;
F_53 ( V_5 ) ;
F_43 ( V_53 ) ;
F_71 ( V_53 ) ;
return 0 ;
}
