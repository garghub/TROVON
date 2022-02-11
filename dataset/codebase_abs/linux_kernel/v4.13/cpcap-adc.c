static T_1 F_1 ( int V_1 , void * V_2 )
{
struct V_3 * V_4 = V_2 ;
struct V_5 * V_6 = F_2 ( V_4 ) ;
int error ;
error = F_3 ( V_6 -> V_7 , V_8 ,
V_9 ,
V_9 ) ;
if ( error )
return V_10 ;
V_6 -> V_11 = true ;
F_4 ( & V_6 -> V_12 ) ;
return V_13 ;
}
static void F_5 ( struct V_5 * V_6 ,
enum V_14 V_15 )
{
unsigned int V_16 = 0 ;
unsigned long V_17 = V_18 + F_6 ( 3000 ) ;
int error ;
if ( ( V_15 != V_19 ) &&
( V_15 != V_20 ) )
return;
V_16 |= V_21 | V_22 ;
V_16 |= ( ( V_15 << 4 ) &
( V_23 | V_24 | V_25 ) ) ;
error = F_3 ( V_6 -> V_7 , V_26 ,
V_21 | V_27 |
V_28 | V_29 |
V_30 | V_31 |
V_23 | V_24 |
V_25 | V_32 |
V_33 | V_22 ,
V_16 ) ;
if ( error )
return;
error = F_3 ( V_6 -> V_7 , V_8 ,
V_34 |
V_35 |
V_36 ,
0 ) ;
if ( error )
return;
error = F_3 ( V_6 -> V_7 , V_8 ,
V_9 ,
V_9 ) ;
if ( error )
return;
error = F_3 ( V_6 -> V_7 , V_8 ,
V_37 ,
V_37 ) ;
if ( error )
return;
do {
F_7 ( 1 ) ;
error = F_8 ( V_6 -> V_7 , V_8 , & V_16 ) ;
if ( error )
return;
} while ( ( V_16 & V_37 ) && F_9 ( V_18 , V_17 ) );
if ( V_16 & V_37 )
F_10 ( V_6 -> V_38 ,
L_1 ) ;
error = F_3 ( V_6 -> V_7 , V_26 ,
V_21 , 0 ) ;
if ( error )
return;
}
static int F_11 ( struct V_5 * V_6 ,
int V_39 ,
T_2 V_40 ,
int V_41 ,
int V_42 )
{
unsigned int V_43 [ 2 ] ;
unsigned short V_44 ;
int V_45 , error ;
for ( V_45 = 0 ; V_45 < V_46 ; V_45 ++ ) {
V_43 [ 0 ] = 0 ;
V_43 [ 1 ] = 0 ;
V_44 = 0 ;
F_5 ( V_6 , V_39 ) ;
error = F_8 ( V_6 -> V_7 , V_40 ,
& V_43 [ 0 ] ) ;
if ( error )
return error ;
F_5 ( V_6 , V_39 ) ;
error = F_8 ( V_6 -> V_7 , V_40 ,
& V_43 [ 1 ] ) ;
if ( error )
return error ;
if ( V_43 [ 0 ] > V_43 [ 1 ] )
V_44 =
V_43 [ 0 ] - V_43 [ 1 ] ;
else
V_44 =
V_43 [ 1 ] - V_43 [ 0 ] ;
if ( ( ( V_43 [ 1 ] >= V_41 ) &&
( V_43 [ 1 ] <= V_42 ) &&
( V_44 <= V_47 ) ) ||
( V_6 -> V_48 == V_49 ) ) {
V_50 [ V_39 ] . V_51 =
( ( short ) V_43 [ 1 ] * - 1 ) + 512 ;
F_12 ( V_6 -> V_38 , L_2 ,
V_39 , V_50 [ V_39 ] . V_51 ) ;
break;
}
F_13 ( 5000 , 10000 ) ;
}
return 0 ;
}
static int F_14 ( struct V_5 * V_6 )
{
int error ;
error = F_11 ( V_6 , V_19 ,
V_52 ,
V_53 ,
V_54 ) ;
if ( error )
return error ;
error = F_11 ( V_6 , V_20 ,
V_55 ,
V_56 ,
V_57 ) ;
if ( error )
return error ;
return 0 ;
}
static void F_15 ( struct V_5 * V_6 ,
struct V_58 * V_59 )
{
const struct V_60 * V_61 = V_6 -> V_61 ;
unsigned short V_62 = 0 ;
unsigned short V_63 = 0 ;
int error ;
if ( ! V_61 )
return;
switch ( V_59 -> V_39 ) {
case V_64 :
V_63 |= V_65 ;
error = F_3 ( V_6 -> V_7 , V_8 ,
V_65 ,
V_63 ) ;
if ( error )
return;
F_13 ( 800 , 1000 ) ;
break;
case V_66 ... V_67 :
V_62 |= V_32 ;
break;
case V_68 ... V_69 :
V_62 |= V_33 ;
default:
break;
}
switch ( V_59 -> V_70 ) {
case V_71 :
V_62 |= V_61 -> V_72 ;
V_62 |= V_61 -> V_73 ;
V_63 |= V_61 -> V_74 ;
V_63 |= V_61 -> V_75 ;
break;
case V_76 :
V_62 |= V_61 -> V_77 ;
V_62 |= V_61 -> V_78 ;
V_63 |= V_61 -> V_79 ;
V_63 |= V_61 -> V_80 ;
break;
case V_81 :
default:
break;
}
error = F_3 ( V_6 -> V_7 , V_26 ,
V_21 | V_27 |
V_28 | V_29 |
V_30 | V_31 |
V_23 | V_24 |
V_25 | V_32 |
V_33 | V_22 ,
V_62 ) ;
if ( error )
return;
error = F_3 ( V_6 -> V_7 , V_8 ,
V_34 |
V_35 |
V_36 |
V_65 ,
V_63 ) ;
if ( error )
return;
if ( V_59 -> V_70 == V_81 ) {
error = F_3 ( V_6 -> V_7 , V_8 ,
V_9 ,
V_9 ) ;
if ( error )
return;
error = F_3 ( V_6 -> V_7 , V_8 ,
V_37 ,
V_37 ) ;
if ( error )
return;
} else {
error = F_3 ( V_6 -> V_7 , V_8 ,
V_82 ,
V_82 ) ;
if ( error )
return;
error = F_3 ( V_6 -> V_7 , V_8 ,
V_9 , 0 ) ;
if ( error )
return;
}
}
static int F_16 ( struct V_5 * V_6 ,
struct V_58 * V_59 )
{
int V_45 , error ;
V_59 -> V_70 = V_81 ;
V_6 -> V_11 = false ;
for ( V_45 = 0 ; V_45 < V_46 ; V_45 ++ ) {
F_15 ( V_6 , V_59 ) ;
error = F_17 ( V_6 -> V_12 ,
V_6 -> V_11 ,
F_6 ( 50 ) ) ;
if ( error > 0 )
return 0 ;
if ( error == 0 ) {
error = - V_83 ;
continue;
}
if ( error < 0 )
return error ;
}
return error ;
}
static int F_18 ( struct V_5 * V_6 )
{
int error ;
error = F_3 ( V_6 -> V_7 , V_26 ,
0xffff ,
V_84 ) ;
if ( error )
return error ;
return F_3 ( V_6 -> V_7 , V_8 ,
0xffff ,
V_85 ) ;
}
static void F_19 ( struct V_58 * V_59 )
{
const struct V_86 * V_87 = V_59 -> V_87 ;
const struct V_88 * V_89 = V_59 -> V_89 ;
int V_90 = V_59 -> V_39 ;
switch ( V_59 -> V_39 ) {
case V_91 :
case V_68 :
V_90 = V_59 -> V_92 ;
V_59 -> V_93 -= V_89 [ V_90 ] . V_94 ;
V_59 -> V_93 -= V_95 ;
V_59 -> V_93 *= V_89 [ V_90 ] . V_96 ;
if ( V_89 [ V_90 ] . V_97 == 0 )
return;
V_59 -> V_93 /= V_89 [ V_90 ] . V_97 ;
V_59 -> V_93 += V_95 ;
break;
case V_69 :
V_90 = V_59 -> V_92 ;
default:
V_59 -> V_93 += V_87 [ V_90 ] . V_51 ;
V_59 -> V_93 += V_87 [ V_90 ] . V_98 ;
V_59 -> V_93 *= V_89 [ V_90 ] . V_96 ;
if ( V_89 [ V_90 ] . V_97 == 0 )
return;
V_59 -> V_93 /= V_89 [ V_90 ] . V_97 ;
V_59 -> V_93 += V_89 [ V_90 ] . V_94 ;
break;
}
if ( V_59 -> V_93 < V_89 [ V_90 ] . V_99 )
V_59 -> V_93 = V_89 [ V_90 ] . V_99 ;
else if ( V_59 -> V_93 > V_89 [ V_90 ] . V_100 )
V_59 -> V_93 = V_89 [ V_90 ] . V_100 ;
}
static int F_20 ( unsigned short V_16 )
{
int V_45 , V_93 = 0 , V_101 ;
if ( V_16 <= V_102 [ V_103 - 1 ] [ 0 ] )
return V_102 [ V_103 - 1 ] [ 1 ] ;
if ( V_16 >= V_102 [ 0 ] [ 0 ] )
return V_102 [ 0 ] [ 1 ] ;
for ( V_45 = 0 ; V_45 < V_103 - 1 ; V_45 ++ ) {
if ( ( V_16 <= V_102 [ V_45 ] [ 0 ] ) &&
( V_16 >= V_102 [ V_45 + 1 ] [ 0 ] ) ) {
if ( V_16 == V_102 [ V_45 ] [ 0 ] ) {
V_93 = V_102 [ V_45 ] [ 1 ] ;
} else if ( V_16 == V_102 [ V_45 + 1 ] [ 0 ] ) {
V_93 = V_102 [ V_45 + 1 ] [ 1 ] ;
} else {
V_101 = ( ( V_16 - V_102 [ V_45 ] [ 0 ] ) * 1000 ) /
( V_102 [ V_45 + 1 ] [ 0 ] - V_102 [ V_45 ] [ 0 ] ) ;
V_93 = V_102 [ V_45 ] [ 1 ] +
( ( V_101 * ( V_102 [ V_45 + 1 ] [ 1 ] -
V_102 [ V_45 ] [ 1 ] ) ) / 1000 ) ;
}
break;
}
}
return V_93 ;
}
static void F_21 ( struct V_58 * V_59 )
{
const struct V_86 * V_87 = V_59 -> V_87 ;
int V_90 = V_59 -> V_39 ;
switch ( V_59 -> V_39 ) {
case V_68 :
V_90 = V_91 ;
break;
case V_69 :
V_90 = V_20 ;
break;
default:
break;
}
if ( V_87 [ V_90 ] . V_104 == V_105 )
return;
if ( ( V_59 -> V_39 == V_64 ) ||
( V_59 -> V_39 == V_106 ) ) {
V_59 -> V_93 =
F_20 ( V_59 -> V_93 ) ;
return;
}
V_59 -> V_93 *= V_87 [ V_90 ] . V_96 ;
if ( V_87 [ V_90 ] . V_97 == 0 )
return;
V_59 -> V_93 /= V_87 [ V_90 ] . V_97 ;
V_59 -> V_93 += V_87 [ V_90 ] . V_107 ;
}
static int F_22 ( struct V_5 * V_6 ,
struct V_58 * V_59 )
{
int V_43 , error , V_108 ;
if ( V_6 -> V_48 == V_49 ) {
error = F_8 ( V_6 -> V_7 , V_52 ,
& V_43 ) ;
if ( error )
return error ;
V_50 [ V_19 ] . V_51 =
( ( short ) V_43 * - 1 ) + 512 ;
error = F_8 ( V_6 -> V_7 , V_55 ,
& V_43 ) ;
if ( error )
return error ;
V_50 [ V_20 ] . V_51 =
( ( short ) V_43 * - 1 ) + 512 ;
}
V_108 = V_109 + V_59 -> V_92 * 4 ;
error = F_8 ( V_6 -> V_7 , V_108 , & V_59 -> V_93 ) ;
if ( error )
return error ;
V_59 -> V_93 &= 0x3ff ;
F_19 ( V_59 ) ;
F_21 ( V_59 ) ;
return 0 ;
}
static int F_23 ( struct V_58 * V_59 ,
int V_39 )
{
V_59 -> V_39 = V_39 ;
V_59 -> V_89 = V_110 ;
V_59 -> V_87 = V_50 ;
switch ( V_39 ) {
case V_64 ... V_111 :
V_59 -> V_92 = V_39 ;
break;
case V_66 ... V_67 :
V_59 -> V_92 = V_39 - 8 ;
break;
case V_68 :
V_59 -> V_92 = V_91 ;
break;
case V_69 :
V_59 -> V_92 = V_20 ;
break;
default:
return - V_112 ;
}
return 0 ;
}
static int F_24 ( struct V_5 * V_6 ,
int V_108 , int * V_113 )
{
int error ;
error = F_8 ( V_6 -> V_7 , V_108 , V_113 ) ;
if ( error )
return error ;
* V_113 -= 282 ;
* V_113 *= 114 ;
* V_113 += 25000 ;
return 0 ;
}
static int F_25 ( struct V_3 * V_4 ,
struct V_114 const * V_15 ,
int * V_113 , int * V_115 , long V_116 )
{
struct V_5 * V_6 = F_2 ( V_4 ) ;
struct V_58 V_59 ;
int error ;
error = F_23 ( & V_59 , V_15 -> V_39 ) ;
if ( error )
return error ;
switch ( V_116 ) {
case V_105 :
F_26 ( & V_6 -> V_117 ) ;
error = F_16 ( V_6 , & V_59 ) ;
if ( error )
goto V_118;
error = F_8 ( V_6 -> V_7 , V_15 -> V_119 , V_113 ) ;
if ( error )
goto V_118;
error = F_18 ( V_6 ) ;
if ( error )
goto V_118;
F_27 ( & V_6 -> V_117 ) ;
break;
case V_120 :
F_26 ( & V_6 -> V_117 ) ;
error = F_16 ( V_6 , & V_59 ) ;
if ( error )
goto V_118;
if ( ( V_6 -> V_48 == V_121 ) &&
( V_15 -> V_39 == V_106 ) ) {
error = F_24 ( V_6 ,
V_15 -> V_119 ,
& V_59 . V_93 ) ;
if ( error )
goto V_118;
} else {
error = F_22 ( V_6 , & V_59 ) ;
if ( error )
goto V_118;
}
error = F_18 ( V_6 ) ;
if ( error )
goto V_118;
F_27 ( & V_6 -> V_117 ) ;
* V_113 = V_59 . V_93 ;
break;
default:
return - V_112 ;
}
return V_122 ;
V_118:
F_27 ( & V_6 -> V_117 ) ;
F_10 ( V_6 -> V_38 , L_3 , error ) ;
return error ;
}
static int F_28 ( struct V_123 * V_124 )
{
const struct V_125 * V_126 ;
struct V_5 * V_6 ;
struct V_3 * V_4 ;
int error ;
V_126 = F_29 ( F_30 ( V_127 ) ,
& V_124 -> V_38 ) ;
if ( ! V_126 )
return - V_112 ;
if ( ! V_126 -> V_2 ) {
F_10 ( & V_124 -> V_38 , L_4 ) ;
return - V_128 ;
}
V_4 = F_31 ( & V_124 -> V_38 , sizeof( * V_6 ) ) ;
if ( ! V_4 ) {
F_10 ( & V_124 -> V_38 , L_5 ) ;
return - V_129 ;
}
V_6 = F_2 ( V_4 ) ;
V_6 -> V_61 = V_126 -> V_2 ;
V_6 -> V_38 = & V_124 -> V_38 ;
F_32 ( & V_6 -> V_117 ) ;
F_33 ( & V_6 -> V_12 ) ;
V_4 -> V_130 = V_131 | V_132 ;
V_4 -> V_38 . V_133 = & V_124 -> V_38 ;
V_4 -> V_38 . V_134 = V_124 -> V_38 . V_134 ;
V_4 -> V_135 = V_136 ;
V_4 -> V_137 = F_34 ( V_136 ) ;
V_4 -> V_138 = F_35 ( & V_124 -> V_38 ) ;
V_4 -> V_139 = & V_140 ;
V_6 -> V_7 = F_36 ( V_124 -> V_38 . V_133 , NULL ) ;
if ( ! V_6 -> V_7 )
return - V_128 ;
error = F_37 ( V_6 -> V_38 , V_6 -> V_7 , & V_6 -> V_48 ) ;
if ( error )
return error ;
F_38 ( V_124 , V_4 ) ;
V_6 -> V_1 = F_39 ( V_124 , L_6 ) ;
if ( ! V_6 -> V_1 )
return - V_128 ;
error = F_40 ( & V_124 -> V_38 , V_6 -> V_1 , NULL ,
F_1 ,
V_141 ,
L_7 , V_4 ) ;
if ( error ) {
F_10 ( & V_124 -> V_38 , L_8 ,
error ) ;
return error ;
}
error = F_14 ( V_6 ) ;
if ( error )
return error ;
F_41 ( & V_124 -> V_38 , L_9 ) ;
return F_42 ( & V_124 -> V_38 , V_4 ) ;
}
