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
case V_64 ... V_65 :
V_62 |= V_32 ;
break;
case V_66 ... V_67 :
V_62 |= V_33 ;
default:
break;
}
switch ( V_59 -> V_68 ) {
case V_69 :
V_62 |= V_61 -> V_70 ;
V_62 |= V_61 -> V_71 ;
V_63 |= V_61 -> V_72 ;
V_63 |= V_61 -> V_73 ;
break;
case V_74 :
V_62 |= V_61 -> V_75 ;
V_62 |= V_61 -> V_76 ;
V_63 |= V_61 -> V_77 ;
V_63 |= V_61 -> V_78 ;
break;
case V_79 :
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
V_36 ,
V_63 ) ;
if ( error )
return;
if ( V_59 -> V_68 == V_79 ) {
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
V_80 ,
V_80 ) ;
if ( error )
return;
error = F_3 ( V_6 -> V_7 , V_8 ,
V_9 , 0 ) ;
if ( error )
return;
}
}
static void F_16 ( struct V_5 * V_6 )
{
int error ;
F_17 ( V_6 -> V_38 , L_3 ) ;
F_18 ( V_6 -> V_1 ) ;
error = F_3 ( V_6 -> V_7 , V_8 ,
V_9 ,
V_9 ) ;
if ( error )
F_19 ( V_6 -> V_38 , L_4 ,
V_81 , error ) ;
F_20 ( V_6 -> V_1 ) ;
}
static int F_21 ( struct V_5 * V_6 ,
struct V_58 * V_59 )
{
int V_45 , error ;
V_59 -> V_68 = V_79 ;
V_6 -> V_11 = false ;
for ( V_45 = 0 ; V_45 < V_46 ; V_45 ++ ) {
F_15 ( V_6 , V_59 ) ;
error = F_22 ( V_6 -> V_12 ,
V_6 -> V_11 ,
F_6 ( 50 ) ) ;
if ( error > 0 )
return 0 ;
if ( error == 0 ) {
F_16 ( V_6 ) ;
error = - V_82 ;
continue;
}
if ( error < 0 )
return error ;
}
return error ;
}
static void F_23 ( struct V_58 * V_59 )
{
const struct V_83 * V_84 = V_59 -> V_84 ;
const struct V_85 * V_86 = V_59 -> V_86 ;
int V_87 = V_59 -> V_39 ;
switch ( V_59 -> V_39 ) {
case V_88 :
case V_66 :
V_87 = V_59 -> V_89 ;
V_59 -> V_90 -= V_86 [ V_87 ] . V_91 ;
V_59 -> V_90 -= V_92 ;
V_59 -> V_90 *= V_86 [ V_87 ] . V_93 ;
if ( V_86 [ V_87 ] . V_94 == 0 )
return;
V_59 -> V_90 /= V_86 [ V_87 ] . V_94 ;
V_59 -> V_90 += V_92 ;
break;
case V_67 :
V_87 = V_59 -> V_89 ;
default:
V_59 -> V_90 += V_84 [ V_87 ] . V_51 ;
V_59 -> V_90 += V_84 [ V_87 ] . V_95 ;
V_59 -> V_90 *= V_86 [ V_87 ] . V_93 ;
if ( V_86 [ V_87 ] . V_94 == 0 )
return;
V_59 -> V_90 /= V_86 [ V_87 ] . V_94 ;
V_59 -> V_90 += V_86 [ V_87 ] . V_91 ;
break;
}
if ( V_59 -> V_90 < V_86 [ V_87 ] . V_96 )
V_59 -> V_90 = V_86 [ V_87 ] . V_96 ;
else if ( V_59 -> V_90 > V_86 [ V_87 ] . V_97 )
V_59 -> V_90 = V_86 [ V_87 ] . V_97 ;
}
static int F_24 ( unsigned short V_16 )
{
int V_45 , V_90 = 0 , V_98 ;
if ( V_16 <= V_99 [ V_100 - 1 ] [ 0 ] )
return V_99 [ V_100 - 1 ] [ 1 ] ;
if ( V_16 >= V_99 [ 0 ] [ 0 ] )
return V_99 [ 0 ] [ 1 ] ;
for ( V_45 = 0 ; V_45 < V_100 - 1 ; V_45 ++ ) {
if ( ( V_16 <= V_99 [ V_45 ] [ 0 ] ) &&
( V_16 >= V_99 [ V_45 + 1 ] [ 0 ] ) ) {
if ( V_16 == V_99 [ V_45 ] [ 0 ] ) {
V_90 = V_99 [ V_45 ] [ 1 ] ;
} else if ( V_16 == V_99 [ V_45 + 1 ] [ 0 ] ) {
V_90 = V_99 [ V_45 + 1 ] [ 1 ] ;
} else {
V_98 = ( ( V_16 - V_99 [ V_45 ] [ 0 ] ) * 1000 ) /
( V_99 [ V_45 + 1 ] [ 0 ] - V_99 [ V_45 ] [ 0 ] ) ;
V_90 = V_99 [ V_45 ] [ 1 ] +
( ( V_98 * ( V_99 [ V_45 + 1 ] [ 1 ] -
V_99 [ V_45 ] [ 1 ] ) ) / 1000 ) ;
}
break;
}
}
return V_90 ;
}
static void F_25 ( struct V_58 * V_59 )
{
const struct V_83 * V_84 = V_59 -> V_84 ;
int V_87 = V_59 -> V_39 ;
switch ( V_59 -> V_39 ) {
case V_66 :
V_87 = V_88 ;
break;
case V_67 :
V_87 = V_20 ;
break;
default:
break;
}
if ( V_84 [ V_87 ] . V_101 == V_102 )
return;
if ( ( V_59 -> V_39 == V_103 ) ||
( V_59 -> V_39 == V_104 ) ) {
V_59 -> V_90 =
F_24 ( V_59 -> V_90 ) ;
return;
}
V_59 -> V_90 *= V_84 [ V_87 ] . V_93 ;
if ( V_84 [ V_87 ] . V_94 == 0 )
return;
V_59 -> V_90 /= V_84 [ V_87 ] . V_94 ;
V_59 -> V_90 += V_84 [ V_87 ] . V_105 ;
}
static int F_26 ( struct V_5 * V_6 ,
struct V_58 * V_59 )
{
int V_43 , error , V_106 ;
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
V_106 = V_107 + V_59 -> V_89 * 4 ;
error = F_8 ( V_6 -> V_7 , V_106 , & V_59 -> V_90 ) ;
if ( error )
return error ;
V_59 -> V_90 &= 0x3ff ;
F_23 ( V_59 ) ;
F_25 ( V_59 ) ;
return 0 ;
}
static int F_27 ( struct V_58 * V_59 ,
int V_39 )
{
V_59 -> V_39 = V_39 ;
V_59 -> V_86 = V_108 ;
V_59 -> V_84 = V_50 ;
switch ( V_39 ) {
case V_103 ... V_109 :
V_59 -> V_89 = V_39 ;
break;
case V_64 ... V_65 :
V_59 -> V_89 = V_39 - 8 ;
break;
case V_66 :
V_59 -> V_89 = V_88 ;
break;
case V_67 :
V_59 -> V_89 = V_20 ;
break;
default:
return - V_110 ;
}
return 0 ;
}
static int F_28 ( struct V_3 * V_4 ,
struct V_111 const * V_15 ,
int * V_112 , int * V_113 , long V_114 )
{
struct V_5 * V_6 = F_2 ( V_4 ) ;
struct V_58 V_59 ;
int error ;
error = F_27 ( & V_59 , V_15 -> V_39 ) ;
if ( error )
return error ;
switch ( V_114 ) {
case V_102 :
F_29 ( & V_6 -> V_115 ) ;
error = F_21 ( V_6 , & V_59 ) ;
if ( error )
goto V_116;
error = F_8 ( V_6 -> V_7 , V_15 -> V_117 , V_112 ) ;
if ( error )
goto V_116;
F_30 ( & V_6 -> V_115 ) ;
break;
case V_118 :
F_29 ( & V_6 -> V_115 ) ;
error = F_21 ( V_6 , & V_59 ) ;
if ( error )
goto V_116;
error = F_26 ( V_6 , & V_59 ) ;
if ( error )
goto V_116;
F_30 ( & V_6 -> V_115 ) ;
* V_112 = V_59 . V_90 ;
break;
default:
return - V_110 ;
}
return V_119 ;
V_116:
F_30 ( & V_6 -> V_115 ) ;
F_10 ( V_6 -> V_38 , L_5 , error ) ;
return error ;
}
static int F_31 ( struct V_120 * V_121 )
{
const struct V_122 * V_123 ;
struct V_5 * V_6 ;
struct V_3 * V_4 ;
int error ;
V_123 = F_32 ( F_33 ( V_124 ) ,
& V_121 -> V_38 ) ;
if ( ! V_123 )
return - V_110 ;
if ( ! V_123 -> V_2 ) {
F_10 ( & V_121 -> V_38 , L_6 ) ;
return - V_125 ;
}
V_4 = F_34 ( & V_121 -> V_38 , sizeof( * V_6 ) ) ;
if ( ! V_4 ) {
F_10 ( & V_121 -> V_38 , L_7 ) ;
return - V_126 ;
}
V_6 = F_2 ( V_4 ) ;
V_6 -> V_61 = V_123 -> V_2 ;
V_6 -> V_38 = & V_121 -> V_38 ;
F_35 ( & V_6 -> V_115 ) ;
F_36 ( & V_6 -> V_12 ) ;
V_4 -> V_127 = V_128 | V_129 ;
V_4 -> V_38 . V_130 = & V_121 -> V_38 ;
V_4 -> V_38 . V_131 = V_121 -> V_38 . V_131 ;
V_4 -> V_132 = V_133 ;
V_4 -> V_134 = F_37 ( V_133 ) ;
V_4 -> V_135 = F_38 ( & V_121 -> V_38 ) ;
V_4 -> V_136 = & V_137 ;
V_6 -> V_7 = F_39 ( V_121 -> V_38 . V_130 , NULL ) ;
if ( ! V_6 -> V_7 )
return - V_125 ;
error = F_40 ( V_6 -> V_38 , V_6 -> V_7 , & V_6 -> V_48 ) ;
if ( error )
return error ;
F_41 ( V_121 , V_4 ) ;
V_6 -> V_1 = F_42 ( V_121 , L_8 ) ;
if ( ! V_6 -> V_1 )
return - V_125 ;
error = F_43 ( & V_121 -> V_38 , V_6 -> V_1 , NULL ,
F_1 ,
V_138 ,
L_9 , V_4 ) ;
if ( error ) {
F_10 ( & V_121 -> V_38 , L_10 ,
error ) ;
return error ;
}
error = F_14 ( V_6 ) ;
if ( error )
return error ;
F_17 ( & V_121 -> V_38 , L_11 ) ;
return F_44 ( & V_121 -> V_38 , V_4 ) ;
}
