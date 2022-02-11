static int F_1 ( T_1 V_1 , T_1 * V_2 ,
T_1 * V_3 )
{
switch ( V_1 ) {
case 0x00 :
case 0x06 :
case 0x08 :
* V_2 = 512 ;
break;
case 0x03 :
case 0x07 :
case 0x09 :
case 0x0A :
case 0x0B :
case 0x0C :
* V_2 = 768 ;
break;
case 0x0D :
* V_2 = 896 ;
break;
case 0x0E :
* V_2 = 640 ;
break;
case 0x10 :
* V_2 = 1024 ;
break;
default:
* V_2 = 0 ;
* V_3 = 0 ;
return - V_4 ;
}
* V_3 =
( * V_2 * V_5 ) - V_6 ;
return 0 ;
}
static int F_2 ( struct V_7 * V_8 )
{
int V_9 = V_10 ;
int error ;
error = F_3 ( V_8 -> V_11 ) ;
if ( error ) {
F_4 ( & V_8 -> V_12 -> V_13 ,
L_1 , error ) ;
return error ;
}
do {
error = V_8 -> V_14 -> V_15 ( V_8 -> V_12 , true ) ;
if ( error >= 0 )
return 0 ;
F_5 ( 30 ) ;
} while ( -- V_9 > 0 );
F_4 ( & V_8 -> V_12 -> V_13 , L_2 , error ) ;
return error ;
}
static int F_6 ( struct V_7 * V_8 )
{
int V_9 = V_10 ;
int error ;
do {
error = V_8 -> V_14 -> V_15 ( V_8 -> V_12 , false ) ;
if ( ! error ) {
error = F_7 ( V_8 -> V_11 ) ;
if ( error ) {
F_4 ( & V_8 -> V_12 -> V_13 ,
L_3 ,
error ) ;
V_8 -> V_14 -> V_15 ( V_8 -> V_12 , true ) ;
break;
}
return 0 ;
}
F_5 ( 30 ) ;
} while ( -- V_9 > 0 );
F_4 ( & V_8 -> V_12 -> V_13 , L_4 , error ) ;
return error ;
}
static int F_8 ( struct V_7 * V_8 )
{
int V_9 = V_10 ;
int error ;
do {
error = V_8 -> V_14 -> V_16 ( V_8 -> V_12 , true ) ;
if ( ! error )
return 0 ;
F_5 ( 30 ) ;
} while ( -- V_9 > 0 );
return error ;
}
static int F_9 ( struct V_7 * V_8 )
{
int error ;
error = V_8 -> V_14 -> V_17 ( V_8 -> V_12 , & V_8 -> V_18 ) ;
if ( error )
return error ;
error = V_8 -> V_14 -> V_19 ( V_8 -> V_12 , & V_8 -> V_1 ,
& V_8 -> V_20 ) ;
if ( error )
return error ;
return 0 ;
}
static int F_10 ( struct V_7 * V_8 )
{
if ( V_8 -> V_1 == 0x0E ) {
switch ( V_8 -> V_18 ) {
case 0x05 ... 0x07 :
case 0x09 :
case 0x13 :
return true ;
}
} else if ( V_8 -> V_1 == 0x08 && V_8 -> V_18 == 0x26 ) {
return true ;
}
return false ;
}
static int F_11 ( struct V_7 * V_8 )
{
struct V_21 * V_12 = V_8 -> V_12 ;
bool V_22 = false ;
int error ;
error = V_8 -> V_14 -> V_23 ( V_12 ) ;
if ( error ) {
F_4 ( & V_12 -> V_13 , L_5 , error ) ;
return error ;
}
error = F_9 ( V_8 ) ;
if ( error )
return error ;
if ( F_10 ( V_8 ) ) {
error = V_8 -> V_14 -> V_16 ( V_12 , false ) ;
if ( error ) {
F_4 ( & V_12 -> V_13 ,
L_6 , error ) ;
return error ;
}
F_5 ( 200 ) ;
V_22 = true ;
}
V_8 -> V_24 |= V_25 ;
error = V_8 -> V_14 -> V_26 ( V_12 , V_8 -> V_24 ) ;
if ( error ) {
F_4 ( & V_12 -> V_13 ,
L_7 , error ) ;
return error ;
}
if ( ! V_22 ) {
error = V_8 -> V_14 -> V_16 ( V_12 , false ) ;
if ( error ) {
F_4 ( & V_12 -> V_13 ,
L_6 , error ) ;
return error ;
}
}
return 0 ;
}
static int F_12 ( struct V_7 * V_8 )
{
int V_9 = V_10 ;
int error ;
do {
error = F_11 ( V_8 ) ;
if ( ! error )
return 0 ;
F_5 ( 30 ) ;
} while ( -- V_9 > 0 );
return error ;
}
static int F_13 ( struct V_7 * V_8 )
{
int error ;
T_1 V_1 ;
error = V_8 -> V_14 -> V_27 ( V_8 -> V_12 , false , & V_8 -> V_28 ) ;
if ( error )
return error ;
error = V_8 -> V_14 -> V_29 ( V_8 -> V_12 , false ,
& V_8 -> V_30 ) ;
if ( error )
return error ;
error = V_8 -> V_14 -> V_27 ( V_8 -> V_12 , true , & V_8 -> V_31 ) ;
if ( error )
return error ;
error = V_8 -> V_14 -> V_32 ( V_8 -> V_12 ,
& V_8 -> V_33 ) ;
if ( error )
return error ;
error = V_8 -> V_14 -> V_34 ( V_8 -> V_12 , & V_8 -> V_35 ) ;
if ( error )
return error ;
if ( V_8 -> V_35 == 0x01 )
V_1 = V_8 -> V_1 ;
else
V_1 = V_8 -> V_31 ;
error = F_1 ( V_1 , & V_8 -> V_36 ,
& V_8 -> V_37 ) ;
if ( error )
F_14 ( & V_8 -> V_12 -> V_13 ,
L_8 ,
V_8 -> V_31 , V_8 -> V_1 ) ;
return 0 ;
}
static unsigned int F_15 ( T_2 V_38 )
{
return ( ( int ) ( char ) V_38 * 10 + 790 ) * 10 / 254 ;
}
static int F_16 ( struct V_7 * V_8 )
{
unsigned int V_39 , V_40 ;
T_2 V_41 , V_42 ;
int error ;
error = V_8 -> V_14 -> V_43 ( V_8 -> V_12 , & V_8 -> V_44 , & V_8 -> V_45 ) ;
if ( error )
return error ;
error = V_8 -> V_14 -> V_46 ( V_8 -> V_12 , & V_39 , & V_40 ) ;
if ( error )
return error ;
V_8 -> V_47 = V_8 -> V_44 / V_39 ;
V_8 -> V_48 = V_8 -> V_45 / V_40 ;
error = V_8 -> V_14 -> V_49 ( V_8 -> V_12 , & V_41 , & V_42 ) ;
if ( error )
return error ;
V_8 -> V_50 = F_15 ( V_41 ) ;
V_8 -> V_51 = F_15 ( V_42 ) ;
return 0 ;
}
static int F_17 ( struct V_7 * V_8 ,
const T_2 * V_52 , T_1 V_53 , int V_54 )
{
int V_55 = V_10 ;
int error ;
do {
error = V_8 -> V_14 -> V_56 ( V_8 -> V_12 ,
V_52 , V_53 , V_54 ) ;
if ( ! error )
return 0 ;
F_18 ( & V_8 -> V_12 -> V_13 ,
L_9 , V_54 , error ) ;
} while ( -- V_55 > 0 );
return error ;
}
static int F_19 ( struct V_7 * V_8 ,
const struct V_57 * V_58 )
{
struct V_21 * V_12 = V_8 -> V_12 ;
struct V_59 * V_13 = & V_12 -> V_13 ;
int V_60 , V_61 ;
int error ;
T_1 V_62 ;
T_1 V_63 ;
T_1 V_64 = 0 , V_30 = 0 ;
error = V_8 -> V_14 -> V_65 ( V_12 ) ;
if ( error )
return error ;
V_62 = F_20 ( & V_58 -> V_8 [ V_66 * 2 ] ) ;
V_63 = ( V_62 * 2 ) / V_5 ;
for ( V_60 = V_63 ; V_60 < V_8 -> V_36 ; V_60 ++ ) {
T_1 V_53 = 0 ;
const T_2 * V_52 = & V_58 -> V_8 [ V_60 * V_5 ] ;
for ( V_61 = 0 ; V_61 < V_5 ; V_61 += 2 )
V_53 += ( ( V_52 [ V_61 + 1 ] << 8 ) | V_52 [ V_61 ] ) ;
error = F_17 ( V_8 , V_52 , V_53 , V_60 ) ;
if ( error ) {
F_4 ( V_13 , L_10 , V_60 , error ) ;
return error ;
}
V_64 += V_53 ;
}
F_5 ( 600 ) ;
error = V_8 -> V_14 -> V_67 ( V_12 , & V_8 -> V_68 ) ;
if ( error )
return error ;
error = V_8 -> V_14 -> V_29 ( V_12 , true , & V_30 ) ;
if ( error )
return error ;
if ( V_64 != V_30 ) {
F_4 ( V_13 , L_11 ,
V_64 , V_30 ) ;
return - V_69 ;
}
return 0 ;
}
static int F_21 ( struct V_7 * V_8 ,
const struct V_57 * V_58 )
{
struct V_21 * V_12 = V_8 -> V_12 ;
int V_70 ;
F_18 ( & V_12 -> V_13 , L_12 ) ;
F_22 ( V_12 -> V_71 ) ;
V_8 -> V_72 = true ;
V_70 = F_19 ( V_8 , V_58 ) ;
if ( V_70 ) {
F_4 ( & V_12 -> V_13 , L_13 , V_70 ) ;
V_8 -> V_14 -> V_73 ( V_12 ) ;
} else {
F_12 ( V_8 ) ;
F_13 ( V_8 ) ;
}
V_8 -> V_72 = false ;
F_23 ( V_12 -> V_71 ) ;
return V_70 ;
}
static T_3 F_24 ( struct V_59 * V_13 ,
struct V_74 * V_75 ,
char * V_76 )
{
struct V_21 * V_12 = F_25 ( V_13 ) ;
struct V_7 * V_8 = F_26 ( V_12 ) ;
return sprintf ( V_76 , L_14 , V_8 -> V_30 ) ;
}
static T_3 F_27 ( struct V_59 * V_13 ,
struct V_74 * V_75 ,
char * V_76 )
{
struct V_21 * V_12 = F_25 ( V_13 ) ;
struct V_7 * V_8 = F_26 ( V_12 ) ;
return sprintf ( V_76 , V_77 L_15 ,
V_8 -> V_18 ) ;
}
static T_3 F_28 ( struct V_59 * V_13 ,
struct V_74 * V_75 ,
char * V_76 )
{
struct V_21 * V_12 = F_25 ( V_13 ) ;
struct V_7 * V_8 = F_26 ( V_12 ) ;
return sprintf ( V_76 , L_16 , V_8 -> V_28 ) ;
}
static T_3 F_29 ( struct V_59 * V_13 ,
struct V_74 * V_75 ,
char * V_76 )
{
struct V_21 * V_12 = F_25 ( V_13 ) ;
struct V_7 * V_8 = F_26 ( V_12 ) ;
return sprintf ( V_76 , L_16 , V_8 -> V_20 ) ;
}
static T_3 F_30 ( struct V_59 * V_13 ,
struct V_74 * V_75 ,
char * V_76 )
{
struct V_21 * V_12 = F_25 ( V_13 ) ;
struct V_7 * V_8 = F_26 ( V_12 ) ;
return sprintf ( V_76 , L_16 , V_8 -> V_31 ) ;
}
static T_3 F_31 ( struct V_59 * V_13 ,
struct V_74 * V_75 ,
const char * V_76 , T_4 V_78 )
{
struct V_7 * V_8 = F_32 ( V_13 ) ;
const struct V_57 * V_58 ;
char * V_79 ;
int error ;
const T_2 * V_80 ;
static const T_2 V_81 [] = { 0xAA , 0x55 , 0xCC , 0x33 , 0xFF , 0xFF } ;
if ( V_8 -> V_36 == 0 )
return - V_82 ;
V_79 = F_33 ( V_83 , V_84 , V_8 -> V_18 ) ;
if ( ! V_79 ) {
F_4 ( V_13 , L_17 ) ;
return - V_85 ;
}
F_34 ( V_13 , L_18 , V_79 ) ;
error = F_35 ( & V_58 , V_79 , V_13 ) ;
F_36 ( V_79 ) ;
if ( error ) {
F_4 ( V_13 , L_19 , error ) ;
return error ;
}
V_80 = & V_58 -> V_8 [ V_8 -> V_37 ] ;
if ( memcmp ( V_80 , V_81 , sizeof( V_81 ) ) != 0 ) {
F_4 ( V_13 , L_20 ,
( int ) sizeof( V_81 ) , V_81 ,
( int ) sizeof( V_81 ) , V_80 ) ;
error = - V_86 ;
goto V_87;
}
error = F_37 ( & V_8 -> V_88 ) ;
if ( error )
goto V_87;
error = F_21 ( V_8 , V_58 ) ;
F_38 ( & V_8 -> V_88 ) ;
V_87:
F_39 ( V_58 ) ;
return error ? : V_78 ;
}
static T_3 F_40 ( struct V_59 * V_13 ,
struct V_74 * V_75 ,
const char * V_76 , T_4 V_78 )
{
struct V_21 * V_12 = F_25 ( V_13 ) ;
struct V_7 * V_8 = F_26 ( V_12 ) ;
int V_89 = 20 ;
int V_70 ;
int error ;
T_2 V_38 [ 3 ] ;
V_70 = F_37 ( & V_8 -> V_88 ) ;
if ( V_70 )
return V_70 ;
F_22 ( V_12 -> V_71 ) ;
V_8 -> V_24 |= V_90 ;
V_70 = V_8 -> V_14 -> V_26 ( V_12 , V_8 -> V_24 ) ;
if ( V_70 ) {
F_4 ( V_13 , L_21 ,
V_70 ) ;
goto V_91;
}
V_70 = V_8 -> V_14 -> V_92 ( V_12 ) ;
if ( V_70 ) {
F_4 ( V_13 , L_22 ,
V_70 ) ;
goto V_93;
}
V_38 [ 0 ] = 0xff ;
do {
F_5 ( 250 ) ;
V_70 = V_8 -> V_14 -> V_94 ( V_12 , V_38 ) ;
if ( V_70 )
F_4 ( V_13 , L_23 ,
V_70 ) ;
else if ( V_38 [ 0 ] == 0 )
break;
} while ( -- V_89 );
if ( V_89 == 0 ) {
F_4 ( V_13 , L_24 ) ;
V_70 = - V_95 ;
}
V_93:
V_8 -> V_24 &= ~ V_90 ;
error = V_8 -> V_14 -> V_26 ( V_8 -> V_12 , V_8 -> V_24 ) ;
if ( error ) {
F_4 ( V_13 , L_25 ,
error ) ;
if ( ! V_70 )
V_70 = error ;
}
V_91:
F_23 ( V_12 -> V_71 ) ;
F_38 ( & V_8 -> V_88 ) ;
return V_70 ? : V_78 ;
}
static T_3 F_41 ( struct V_59 * V_13 ,
struct V_74 * V_75 ,
char * V_76 )
{
struct V_21 * V_12 = F_25 ( V_13 ) ;
struct V_7 * V_8 = F_26 ( V_12 ) ;
int error ;
enum V_96 V_24 ;
error = F_37 ( & V_8 -> V_88 ) ;
if ( error )
return error ;
error = V_8 -> V_14 -> V_97 ( V_8 -> V_12 , & V_24 ) ;
F_38 ( & V_8 -> V_88 ) ;
if ( error )
return error ;
return sprintf ( V_76 , L_26 , ( int ) V_24 ) ;
}
static T_3 F_42 ( struct V_59 * V_13 , struct V_74 * V_75 ,
const char * V_76 , T_4 V_78 )
{
struct V_21 * V_12 = F_25 ( V_13 ) ;
struct V_7 * V_8 = F_26 ( V_12 ) ;
int error ;
int V_70 ;
V_70 = F_37 ( & V_8 -> V_88 ) ;
if ( V_70 )
return V_70 ;
F_22 ( V_12 -> V_71 ) ;
V_8 -> V_98 = false ;
V_8 -> V_24 |= V_90 ;
V_70 = V_8 -> V_14 -> V_26 ( V_8 -> V_12 , V_8 -> V_24 ) ;
if ( V_70 ) {
F_4 ( V_13 , L_27 ,
V_70 ) ;
goto V_91;
}
F_5 ( 250 ) ;
V_70 = V_8 -> V_14 -> V_99 ( V_8 -> V_12 , true ,
& V_8 -> V_100 ) ;
if ( V_70 ) {
F_4 ( V_13 , L_28 ,
V_70 ) ;
goto V_93;
}
V_70 = V_8 -> V_14 -> V_99 ( V_8 -> V_12 , false ,
& V_8 -> V_101 ) ;
if ( V_70 ) {
F_4 ( V_13 , L_29 ,
V_70 ) ;
goto V_93;
}
V_8 -> V_98 = true ;
V_93:
V_8 -> V_24 &= ~ V_90 ;
error = V_8 -> V_14 -> V_26 ( V_8 -> V_12 , V_8 -> V_24 ) ;
if ( error ) {
F_4 ( V_13 , L_30 ,
error ) ;
if ( ! V_70 )
V_70 = error ;
}
V_91:
F_23 ( V_12 -> V_71 ) ;
F_38 ( & V_8 -> V_88 ) ;
return V_70 ? : V_78 ;
}
static T_3 F_43 ( struct V_59 * V_13 ,
struct V_74 * V_75 , char * V_76 )
{
struct V_21 * V_12 = F_25 ( V_13 ) ;
struct V_7 * V_8 = F_26 ( V_12 ) ;
int V_70 ;
V_70 = F_37 ( & V_8 -> V_88 ) ;
if ( V_70 )
return V_70 ;
if ( ! V_8 -> V_98 ) {
V_70 = - V_102 ;
goto V_91;
}
V_70 = snprintf ( V_76 , V_103 , L_31 , V_8 -> V_101 ) ;
V_91:
F_38 ( & V_8 -> V_88 ) ;
return V_70 ;
}
static T_3 F_44 ( struct V_59 * V_13 ,
struct V_74 * V_75 , char * V_76 )
{
struct V_21 * V_12 = F_25 ( V_13 ) ;
struct V_7 * V_8 = F_26 ( V_12 ) ;
int V_70 ;
V_70 = F_37 ( & V_8 -> V_88 ) ;
if ( V_70 )
return V_70 ;
if ( ! V_8 -> V_98 ) {
V_70 = - V_102 ;
goto V_91;
}
V_70 = snprintf ( V_76 , V_103 , L_31 , V_8 -> V_100 ) ;
V_91:
F_38 ( & V_8 -> V_88 ) ;
return V_70 ;
}
static void F_45 ( struct V_7 * V_8 ,
int V_104 , bool V_105 ,
T_2 * V_106 )
{
struct V_107 * V_108 = V_8 -> V_108 ;
unsigned int V_109 , V_110 ;
unsigned int V_111 , V_112 , V_113 ;
unsigned int V_114 , V_115 , V_116 , V_117 ;
unsigned int V_118 ;
if ( V_105 ) {
V_109 = ( ( V_106 [ 0 ] & 0xf0 ) << 4 ) |
V_106 [ 1 ] ;
V_110 = ( ( V_106 [ 0 ] & 0x0f ) << 8 ) |
V_106 [ 2 ] ;
V_112 = ( V_106 [ 3 ] & 0x0f ) ;
V_113 = ( V_106 [ 3 ] >> 4 ) ;
V_111 = V_106 [ 4 ] ;
if ( V_109 > V_8 -> V_44 || V_110 > V_8 -> V_45 ) {
F_18 ( V_108 -> V_13 . V_119 ,
L_32 ,
V_104 , V_109 , V_110 ,
V_8 -> V_44 , V_8 -> V_45 ) ;
return;
}
V_114 = V_112 * ( V_8 -> V_47 - V_120 ) ;
V_115 = V_113 * ( V_8 -> V_48 - V_120 ) ;
V_116 = F_46 ( V_114 , V_115 ) ;
V_117 = F_47 ( V_114 , V_115 ) ;
V_118 = V_111 + V_8 -> V_33 ;
if ( V_118 > V_121 )
V_118 = V_121 ;
F_48 ( V_108 , V_104 ) ;
F_49 ( V_108 , V_122 , true ) ;
F_50 ( V_108 , V_123 , V_109 ) ;
F_50 ( V_108 , V_124 , V_8 -> V_45 - V_110 ) ;
F_50 ( V_108 , V_125 , V_118 ) ;
F_50 ( V_108 , V_126 , V_112 ) ;
F_50 ( V_108 , V_127 , V_116 ) ;
F_50 ( V_108 , V_128 , V_117 ) ;
} else {
F_48 ( V_108 , V_104 ) ;
F_49 ( V_108 , V_122 , false ) ;
}
}
static void F_51 ( struct V_7 * V_8 , T_2 * V_129 )
{
struct V_107 * V_108 = V_8 -> V_108 ;
T_2 * V_106 = & V_129 [ V_130 ] ;
int V_60 ;
T_2 V_131 = V_129 [ V_132 ] ;
T_2 V_133 = V_129 [ V_134 ] ;
bool V_105 , V_135 ;
V_135 = V_133 & 0x40 ;
for ( V_60 = 0 ; V_60 < V_136 ; V_60 ++ ) {
V_105 = V_131 & ( 1U << ( 3 + V_60 ) ) ;
F_45 ( V_8 , V_60 , V_105 , V_106 ) ;
if ( V_105 )
V_106 += V_137 ;
}
F_52 ( V_108 , V_138 , V_131 & 0x01 ) ;
F_50 ( V_108 , V_139 , V_135 != 0 ) ;
F_53 ( V_108 , true ) ;
F_54 ( V_108 ) ;
}
static T_5 F_55 ( int V_71 , void * V_140 )
{
struct V_7 * V_8 = V_140 ;
struct V_59 * V_13 = & V_8 -> V_12 -> V_13 ;
int error ;
T_2 V_141 [ V_142 ] ;
if ( V_8 -> V_72 ) {
F_56 ( & V_8 -> V_68 ) ;
goto V_91;
}
error = V_8 -> V_14 -> V_143 ( V_8 -> V_12 , V_141 ) ;
if ( error )
goto V_91;
if ( V_141 [ V_144 ] != V_145 )
F_4 ( V_13 , L_33 ,
V_141 [ V_144 ] ) ;
else
F_51 ( V_8 , V_141 ) ;
V_91:
return V_146 ;
}
static int F_57 ( struct V_7 * V_8 )
{
struct V_59 * V_13 = & V_8 -> V_12 -> V_13 ;
struct V_107 * V_108 ;
unsigned int V_147 = F_46 ( V_8 -> V_47 , V_8 -> V_48 ) ;
unsigned int V_148 = F_47 ( V_8 -> V_47 , V_8 -> V_48 ) ;
int error ;
V_108 = F_58 ( V_13 ) ;
if ( ! V_108 )
return - V_85 ;
V_108 -> V_149 = L_34 ;
V_108 -> V_150 . V_151 = V_152 ;
V_108 -> V_150 . V_153 = V_154 ;
V_108 -> V_150 . V_155 = V_8 -> V_18 ;
F_59 ( V_108 , V_8 ) ;
error = F_60 ( V_108 , V_136 ,
V_156 | V_157 ) ;
if ( error ) {
F_4 ( V_13 , L_35 , error ) ;
return error ;
}
F_61 ( V_158 , V_108 -> V_159 ) ;
F_61 ( V_160 , V_108 -> V_161 ) ;
F_61 ( V_162 , V_108 -> V_161 ) ;
F_61 ( V_138 , V_108 -> V_163 ) ;
F_62 ( V_108 , V_164 , 0 , V_8 -> V_44 , 0 , 0 ) ;
F_62 ( V_108 , V_165 , 0 , V_8 -> V_45 , 0 , 0 ) ;
F_63 ( V_108 , V_164 , V_8 -> V_50 ) ;
F_63 ( V_108 , V_165 , V_8 -> V_51 ) ;
F_62 ( V_108 , V_166 , 0 , V_121 , 0 , 0 ) ;
F_62 ( V_108 , V_126 , 0 , V_167 , 0 , 0 ) ;
F_62 ( V_108 , V_139 , 0 , 1 , 0 , 0 ) ;
F_62 ( V_108 , V_123 , 0 , V_8 -> V_44 , 0 , 0 ) ;
F_62 ( V_108 , V_124 , 0 , V_8 -> V_45 , 0 , 0 ) ;
F_63 ( V_108 , V_123 , V_8 -> V_50 ) ;
F_63 ( V_108 , V_124 , V_8 -> V_51 ) ;
F_62 ( V_108 , V_125 , 0 ,
V_121 , 0 , 0 ) ;
F_62 ( V_108 , V_127 , 0 ,
V_167 * V_147 , 0 , 0 ) ;
F_62 ( V_108 , V_128 , 0 ,
V_167 * V_148 , 0 , 0 ) ;
V_8 -> V_108 = V_108 ;
return 0 ;
}
static void F_64 ( void * V_168 )
{
struct V_7 * V_8 = V_168 ;
F_7 ( V_8 -> V_11 ) ;
}
static void F_65 ( void * V_168 )
{
struct V_7 * V_8 = V_168 ;
F_66 ( & V_8 -> V_12 -> V_13 . V_169 , V_170 ) ;
}
static int F_67 ( struct V_21 * V_12 ,
const struct V_171 * V_140 )
{
const struct V_172 * V_173 ;
struct V_59 * V_13 = & V_12 -> V_13 ;
struct V_7 * V_8 ;
unsigned long V_174 ;
int error ;
if ( F_68 ( V_175 ) &&
F_69 ( V_12 -> V_176 , V_177 ) ) {
V_173 = & V_178 ;
} else if ( F_68 ( V_179 ) &&
F_69 ( V_12 -> V_176 ,
V_180 |
V_181 |
V_182 ) ) {
V_173 = & V_183 ;
} else {
F_4 ( V_13 , L_36 ) ;
return - V_69 ;
}
V_8 = F_70 ( V_13 , sizeof( struct V_7 ) , V_83 ) ;
if ( ! V_8 )
return - V_85 ;
F_71 ( V_12 , V_8 ) ;
V_8 -> V_14 = V_173 ;
V_8 -> V_12 = V_12 ;
F_72 ( & V_8 -> V_68 ) ;
F_73 ( & V_8 -> V_88 ) ;
V_8 -> V_11 = F_74 ( V_13 , L_37 ) ;
if ( F_75 ( V_8 -> V_11 ) ) {
error = F_76 ( V_8 -> V_11 ) ;
if ( error != - V_184 )
F_4 ( V_13 , L_38 ,
error ) ;
return error ;
}
error = F_3 ( V_8 -> V_11 ) ;
if ( error ) {
F_4 ( V_13 , L_39 , error ) ;
return error ;
}
error = F_77 ( V_13 , F_64 , V_8 ) ;
if ( error ) {
F_7 ( V_8 -> V_11 ) ;
F_4 ( V_13 , L_40 ,
error ) ;
return error ;
}
error = F_78 ( V_12 ) ;
if ( error < 0 ) {
F_18 ( & V_12 -> V_13 , L_41 , error ) ;
return - V_4 ;
}
error = F_12 ( V_8 ) ;
if ( error )
return error ;
error = F_13 ( V_8 ) ;
if ( error )
return error ;
error = F_16 ( V_8 ) ;
if ( error )
return error ;
F_34 ( V_13 ,
L_42 ,
V_8 -> V_18 ,
V_8 -> V_28 ,
V_8 -> V_20 ,
V_8 -> V_31 ) ;
F_18 ( V_13 ,
L_43
L_44
L_45
L_46
L_47
L_48 ,
V_8 -> V_44 , V_8 -> V_45 ,
V_8 -> V_47 , V_8 -> V_48 ,
V_8 -> V_50 , V_8 -> V_51 ,
V_8 -> V_1 , V_8 -> V_35 ) ;
error = F_57 ( V_8 ) ;
if ( error )
return error ;
V_174 = V_13 -> V_185 ? 0 : V_186 ;
error = F_79 ( V_13 , V_12 -> V_71 , NULL , F_55 ,
V_174 | V_187 ,
V_12 -> V_149 , V_8 ) ;
if ( error ) {
F_4 ( V_13 , L_49 , V_12 -> V_71 ) ;
return error ;
}
error = F_80 ( & V_13 -> V_169 , V_170 ) ;
if ( error ) {
F_4 ( V_13 , L_50 , error ) ;
return error ;
}
error = F_77 ( V_13 , F_65 , V_8 ) ;
if ( error ) {
F_65 ( V_8 ) ;
F_4 ( V_13 , L_51 ,
error ) ;
return error ;
}
error = F_81 ( V_8 -> V_108 ) ;
if ( error ) {
F_4 ( V_13 , L_52 , error ) ;
return error ;
}
if ( ! V_13 -> V_185 )
F_82 ( V_13 , true ) ;
return 0 ;
}
static int T_6 F_83 ( struct V_59 * V_13 )
{
struct V_21 * V_12 = F_25 ( V_13 ) ;
struct V_7 * V_8 = F_26 ( V_12 ) ;
int V_188 ;
V_188 = F_37 ( & V_8 -> V_88 ) ;
if ( V_188 )
return V_188 ;
F_22 ( V_12 -> V_71 ) ;
if ( F_84 ( V_13 ) ) {
V_188 = F_8 ( V_8 ) ;
V_8 -> V_189 = ( F_85 ( V_12 -> V_71 ) == 0 ) ;
} else {
V_188 = F_6 ( V_8 ) ;
}
F_38 ( & V_8 -> V_88 ) ;
return V_188 ;
}
static int T_6 F_86 ( struct V_59 * V_13 )
{
struct V_21 * V_12 = F_25 ( V_13 ) ;
struct V_7 * V_8 = F_26 ( V_12 ) ;
int error ;
if ( F_84 ( V_13 ) && V_8 -> V_189 ) {
F_87 ( V_12 -> V_71 ) ;
V_8 -> V_189 = false ;
}
error = F_2 ( V_8 ) ;
if ( error ) {
F_4 ( V_13 , L_53 , error ) ;
goto V_190;
}
error = F_12 ( V_8 ) ;
if ( error )
F_4 ( V_13 , L_54 , error ) ;
V_190:
F_23 ( V_8 -> V_12 -> V_71 ) ;
return error ;
}
