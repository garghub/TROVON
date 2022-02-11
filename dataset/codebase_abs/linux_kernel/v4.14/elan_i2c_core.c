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
& V_8 -> V_20 , & V_8 -> V_21 ) ;
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
struct V_22 * V_12 = V_8 -> V_12 ;
bool V_23 = false ;
int error ;
error = V_8 -> V_14 -> V_24 ( V_12 ) ;
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
V_23 = true ;
}
V_8 -> V_25 |= V_26 ;
error = V_8 -> V_14 -> V_27 ( V_12 , V_8 -> V_25 ) ;
if ( error ) {
F_4 ( & V_12 -> V_13 ,
L_7 , error ) ;
return error ;
}
if ( ! V_23 ) {
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
error = V_8 -> V_14 -> V_28 ( V_8 -> V_12 , false , & V_8 -> V_29 ) ;
if ( error )
return error ;
error = V_8 -> V_14 -> V_30 ( V_8 -> V_12 , false ,
& V_8 -> V_31 ) ;
if ( error )
return error ;
error = V_8 -> V_14 -> V_28 ( V_8 -> V_12 , true , & V_8 -> V_32 ) ;
if ( error )
return error ;
error = V_8 -> V_14 -> V_33 ( V_8 -> V_12 ,
& V_8 -> V_34 ) ;
if ( error )
return error ;
error = V_8 -> V_14 -> V_35 ( V_8 -> V_12 , & V_8 -> V_36 ) ;
if ( error )
return error ;
if ( V_8 -> V_36 == 0x01 )
V_1 = V_8 -> V_1 ;
else
V_1 = V_8 -> V_32 ;
error = F_1 ( V_1 , & V_8 -> V_37 ,
& V_8 -> V_38 ) ;
if ( error )
F_14 ( & V_8 -> V_12 -> V_13 ,
L_8 ,
V_8 -> V_32 , V_8 -> V_1 ) ;
return 0 ;
}
static unsigned int F_15 ( T_2 V_39 )
{
return ( ( int ) ( char ) V_39 * 10 + 790 ) * 10 / 254 ;
}
static int F_16 ( struct V_7 * V_8 )
{
unsigned int V_40 , V_41 ;
T_2 V_42 , V_43 ;
int error ;
error = V_8 -> V_14 -> V_44 ( V_8 -> V_12 , & V_8 -> V_45 , & V_8 -> V_46 ) ;
if ( error )
return error ;
error = V_8 -> V_14 -> V_47 ( V_8 -> V_12 , & V_40 , & V_41 ) ;
if ( error )
return error ;
V_8 -> V_48 = V_8 -> V_45 / V_40 ;
V_8 -> V_49 = V_8 -> V_46 / V_41 ;
error = V_8 -> V_14 -> V_50 ( V_8 -> V_12 , & V_42 , & V_43 ) ;
if ( error )
return error ;
V_8 -> V_51 = F_15 ( V_42 ) ;
V_8 -> V_52 = F_15 ( V_43 ) ;
return 0 ;
}
static int F_17 ( struct V_7 * V_8 ,
const T_2 * V_53 , T_1 V_54 , int V_55 )
{
int V_56 = V_10 ;
int error ;
do {
error = V_8 -> V_14 -> V_57 ( V_8 -> V_12 ,
V_53 , V_54 , V_55 ) ;
if ( ! error )
return 0 ;
F_18 ( & V_8 -> V_12 -> V_13 ,
L_9 , V_55 , error ) ;
} while ( -- V_56 > 0 );
return error ;
}
static int F_19 ( struct V_7 * V_8 ,
const struct V_58 * V_59 )
{
struct V_22 * V_12 = V_8 -> V_12 ;
struct V_60 * V_13 = & V_12 -> V_13 ;
int V_61 , V_62 ;
int error ;
T_1 V_63 ;
T_1 V_64 ;
T_1 V_65 = 0 , V_31 = 0 ;
error = V_8 -> V_14 -> V_66 ( V_12 ) ;
if ( error )
return error ;
V_63 = F_20 ( & V_59 -> V_8 [ V_67 * 2 ] ) ;
V_64 = ( V_63 * 2 ) / V_5 ;
for ( V_61 = V_64 ; V_61 < V_8 -> V_37 ; V_61 ++ ) {
T_1 V_54 = 0 ;
const T_2 * V_53 = & V_59 -> V_8 [ V_61 * V_5 ] ;
for ( V_62 = 0 ; V_62 < V_5 ; V_62 += 2 )
V_54 += ( ( V_53 [ V_62 + 1 ] << 8 ) | V_53 [ V_62 ] ) ;
error = F_17 ( V_8 , V_53 , V_54 , V_61 ) ;
if ( error ) {
F_4 ( V_13 , L_10 , V_61 , error ) ;
return error ;
}
V_65 += V_54 ;
}
F_5 ( 600 ) ;
error = V_8 -> V_14 -> V_68 ( V_12 , & V_8 -> V_69 ) ;
if ( error )
return error ;
error = V_8 -> V_14 -> V_30 ( V_12 , true , & V_31 ) ;
if ( error )
return error ;
if ( V_65 != V_31 ) {
F_4 ( V_13 , L_11 ,
V_65 , V_31 ) ;
return - V_70 ;
}
return 0 ;
}
static int F_21 ( struct V_7 * V_8 ,
const struct V_58 * V_59 )
{
struct V_22 * V_12 = V_8 -> V_12 ;
int V_71 ;
F_18 ( & V_12 -> V_13 , L_12 ) ;
F_22 ( V_12 -> V_72 ) ;
V_8 -> V_73 = true ;
V_71 = F_19 ( V_8 , V_59 ) ;
if ( V_71 ) {
F_4 ( & V_12 -> V_13 , L_13 , V_71 ) ;
V_8 -> V_14 -> V_74 ( V_12 ) ;
} else {
F_12 ( V_8 ) ;
F_13 ( V_8 ) ;
}
V_8 -> V_73 = false ;
F_23 ( V_12 -> V_72 ) ;
return V_71 ;
}
static T_3 F_24 ( struct V_60 * V_13 ,
struct V_75 * V_76 ,
char * V_77 )
{
struct V_22 * V_12 = F_25 ( V_13 ) ;
struct V_7 * V_8 = F_26 ( V_12 ) ;
return sprintf ( V_77 , L_14 , V_8 -> V_31 ) ;
}
static T_3 F_27 ( struct V_60 * V_13 ,
struct V_75 * V_76 ,
char * V_77 )
{
struct V_22 * V_12 = F_25 ( V_13 ) ;
struct V_7 * V_8 = F_26 ( V_12 ) ;
return sprintf ( V_77 , V_78 L_15 ,
V_8 -> V_18 ) ;
}
static T_3 F_28 ( struct V_60 * V_13 ,
struct V_75 * V_76 ,
char * V_77 )
{
struct V_22 * V_12 = F_25 ( V_13 ) ;
struct V_7 * V_8 = F_26 ( V_12 ) ;
return sprintf ( V_77 , L_16 , V_8 -> V_29 ) ;
}
static T_3 F_29 ( struct V_60 * V_13 ,
struct V_75 * V_76 ,
char * V_77 )
{
struct V_22 * V_12 = F_25 ( V_13 ) ;
struct V_7 * V_8 = F_26 ( V_12 ) ;
return sprintf ( V_77 , L_16 , V_8 -> V_20 ) ;
}
static T_3 F_30 ( struct V_60 * V_13 ,
struct V_75 * V_76 ,
char * V_77 )
{
struct V_22 * V_12 = F_25 ( V_13 ) ;
struct V_7 * V_8 = F_26 ( V_12 ) ;
return sprintf ( V_77 , L_16 , V_8 -> V_32 ) ;
}
static T_3 F_31 ( struct V_60 * V_13 ,
struct V_75 * V_76 ,
const char * V_77 , T_4 V_79 )
{
struct V_7 * V_8 = F_32 ( V_13 ) ;
const struct V_58 * V_59 ;
char * V_80 ;
int error ;
const T_2 * V_81 ;
static const T_2 V_82 [] = { 0xAA , 0x55 , 0xCC , 0x33 , 0xFF , 0xFF } ;
if ( V_8 -> V_37 == 0 )
return - V_83 ;
V_80 = F_33 ( V_84 , V_85 , V_8 -> V_18 ) ;
if ( ! V_80 ) {
F_4 ( V_13 , L_17 ) ;
return - V_86 ;
}
F_34 ( V_13 , L_18 , V_80 ) ;
error = F_35 ( & V_59 , V_80 , V_13 ) ;
F_36 ( V_80 ) ;
if ( error ) {
F_4 ( V_13 , L_19 , error ) ;
return error ;
}
V_81 = & V_59 -> V_8 [ V_8 -> V_38 ] ;
if ( memcmp ( V_81 , V_82 , sizeof( V_82 ) ) != 0 ) {
F_4 ( V_13 , L_20 ,
( int ) sizeof( V_82 ) , V_82 ,
( int ) sizeof( V_82 ) , V_81 ) ;
error = - V_87 ;
goto V_88;
}
error = F_37 ( & V_8 -> V_89 ) ;
if ( error )
goto V_88;
error = F_21 ( V_8 , V_59 ) ;
F_38 ( & V_8 -> V_89 ) ;
V_88:
F_39 ( V_59 ) ;
return error ? : V_79 ;
}
static T_3 F_40 ( struct V_60 * V_13 ,
struct V_75 * V_76 ,
const char * V_77 , T_4 V_79 )
{
struct V_22 * V_12 = F_25 ( V_13 ) ;
struct V_7 * V_8 = F_26 ( V_12 ) ;
int V_90 = 20 ;
int V_71 ;
int error ;
T_2 V_39 [ 3 ] ;
V_71 = F_37 ( & V_8 -> V_89 ) ;
if ( V_71 )
return V_71 ;
F_22 ( V_12 -> V_72 ) ;
V_8 -> V_25 |= V_91 ;
V_71 = V_8 -> V_14 -> V_27 ( V_12 , V_8 -> V_25 ) ;
if ( V_71 ) {
F_4 ( V_13 , L_21 ,
V_71 ) ;
goto V_92;
}
V_71 = V_8 -> V_14 -> V_93 ( V_12 ) ;
if ( V_71 ) {
F_4 ( V_13 , L_22 ,
V_71 ) ;
goto V_94;
}
V_39 [ 0 ] = 0xff ;
do {
F_5 ( 250 ) ;
V_71 = V_8 -> V_14 -> V_95 ( V_12 , V_39 ) ;
if ( V_71 )
F_4 ( V_13 , L_23 ,
V_71 ) ;
else if ( V_39 [ 0 ] == 0 )
break;
} while ( -- V_90 );
if ( V_90 == 0 ) {
F_4 ( V_13 , L_24 ) ;
V_71 = - V_96 ;
}
V_94:
V_8 -> V_25 &= ~ V_91 ;
error = V_8 -> V_14 -> V_27 ( V_8 -> V_12 , V_8 -> V_25 ) ;
if ( error ) {
F_4 ( V_13 , L_25 ,
error ) ;
if ( ! V_71 )
V_71 = error ;
}
V_92:
F_23 ( V_12 -> V_72 ) ;
F_38 ( & V_8 -> V_89 ) ;
return V_71 ? : V_79 ;
}
static T_3 F_41 ( struct V_60 * V_13 ,
struct V_75 * V_76 ,
char * V_77 )
{
struct V_22 * V_12 = F_25 ( V_13 ) ;
struct V_7 * V_8 = F_26 ( V_12 ) ;
int error ;
enum V_97 V_25 ;
error = F_37 ( & V_8 -> V_89 ) ;
if ( error )
return error ;
error = V_8 -> V_14 -> V_98 ( V_8 -> V_12 , & V_25 ) ;
F_38 ( & V_8 -> V_89 ) ;
if ( error )
return error ;
return sprintf ( V_77 , L_26 , ( int ) V_25 ) ;
}
static T_3 F_42 ( struct V_60 * V_13 , struct V_75 * V_76 ,
const char * V_77 , T_4 V_79 )
{
struct V_22 * V_12 = F_25 ( V_13 ) ;
struct V_7 * V_8 = F_26 ( V_12 ) ;
int error ;
int V_71 ;
V_71 = F_37 ( & V_8 -> V_89 ) ;
if ( V_71 )
return V_71 ;
F_22 ( V_12 -> V_72 ) ;
V_8 -> V_99 = false ;
V_8 -> V_25 |= V_91 ;
V_71 = V_8 -> V_14 -> V_27 ( V_8 -> V_12 , V_8 -> V_25 ) ;
if ( V_71 ) {
F_4 ( V_13 , L_27 ,
V_71 ) ;
goto V_92;
}
F_5 ( 250 ) ;
V_71 = V_8 -> V_14 -> V_100 ( V_8 -> V_12 , true ,
& V_8 -> V_101 ) ;
if ( V_71 ) {
F_4 ( V_13 , L_28 ,
V_71 ) ;
goto V_94;
}
V_71 = V_8 -> V_14 -> V_100 ( V_8 -> V_12 , false ,
& V_8 -> V_102 ) ;
if ( V_71 ) {
F_4 ( V_13 , L_29 ,
V_71 ) ;
goto V_94;
}
V_8 -> V_99 = true ;
V_94:
V_8 -> V_25 &= ~ V_91 ;
error = V_8 -> V_14 -> V_27 ( V_8 -> V_12 , V_8 -> V_25 ) ;
if ( error ) {
F_4 ( V_13 , L_30 ,
error ) ;
if ( ! V_71 )
V_71 = error ;
}
V_92:
F_23 ( V_12 -> V_72 ) ;
F_38 ( & V_8 -> V_89 ) ;
return V_71 ? : V_79 ;
}
static T_3 F_43 ( struct V_60 * V_13 ,
struct V_75 * V_76 , char * V_77 )
{
struct V_22 * V_12 = F_25 ( V_13 ) ;
struct V_7 * V_8 = F_26 ( V_12 ) ;
int V_71 ;
V_71 = F_37 ( & V_8 -> V_89 ) ;
if ( V_71 )
return V_71 ;
if ( ! V_8 -> V_99 ) {
V_71 = - V_103 ;
goto V_92;
}
V_71 = snprintf ( V_77 , V_104 , L_31 , V_8 -> V_102 ) ;
V_92:
F_38 ( & V_8 -> V_89 ) ;
return V_71 ;
}
static T_3 F_44 ( struct V_60 * V_13 ,
struct V_75 * V_76 , char * V_77 )
{
struct V_22 * V_12 = F_25 ( V_13 ) ;
struct V_7 * V_8 = F_26 ( V_12 ) ;
int V_71 ;
V_71 = F_37 ( & V_8 -> V_89 ) ;
if ( V_71 )
return V_71 ;
if ( ! V_8 -> V_99 ) {
V_71 = - V_103 ;
goto V_92;
}
V_71 = snprintf ( V_77 , V_104 , L_31 , V_8 -> V_101 ) ;
V_92:
F_38 ( & V_8 -> V_89 ) ;
return V_71 ;
}
static void F_45 ( struct V_7 * V_8 ,
int V_105 , bool V_106 ,
T_2 * V_107 )
{
struct V_108 * V_109 = V_8 -> V_109 ;
unsigned int V_110 , V_111 ;
unsigned int V_112 , V_113 , V_114 ;
unsigned int V_115 , V_116 , V_117 , V_118 ;
unsigned int V_119 ;
if ( V_106 ) {
V_110 = ( ( V_107 [ 0 ] & 0xf0 ) << 4 ) |
V_107 [ 1 ] ;
V_111 = ( ( V_107 [ 0 ] & 0x0f ) << 8 ) |
V_107 [ 2 ] ;
V_113 = ( V_107 [ 3 ] & 0x0f ) ;
V_114 = ( V_107 [ 3 ] >> 4 ) ;
V_112 = V_107 [ 4 ] ;
if ( V_110 > V_8 -> V_45 || V_111 > V_8 -> V_46 ) {
F_18 ( V_109 -> V_13 . V_120 ,
L_32 ,
V_105 , V_110 , V_111 ,
V_8 -> V_45 , V_8 -> V_46 ) ;
return;
}
V_115 = V_113 * ( V_8 -> V_48 - V_121 ) ;
V_116 = V_114 * ( V_8 -> V_49 - V_121 ) ;
V_117 = F_46 ( V_115 , V_116 ) ;
V_118 = F_47 ( V_115 , V_116 ) ;
V_119 = V_112 + V_8 -> V_34 ;
if ( V_119 > V_122 )
V_119 = V_122 ;
F_48 ( V_109 , V_105 ) ;
F_49 ( V_109 , V_123 , true ) ;
F_50 ( V_109 , V_124 , V_110 ) ;
F_50 ( V_109 , V_125 , V_8 -> V_46 - V_111 ) ;
F_50 ( V_109 , V_126 , V_119 ) ;
F_50 ( V_109 , V_127 , V_113 ) ;
F_50 ( V_109 , V_128 , V_117 ) ;
F_50 ( V_109 , V_129 , V_118 ) ;
} else {
F_48 ( V_109 , V_105 ) ;
F_49 ( V_109 , V_123 , false ) ;
}
}
static void F_51 ( struct V_7 * V_8 , T_2 * V_130 )
{
struct V_108 * V_109 = V_8 -> V_109 ;
T_2 * V_107 = & V_130 [ V_131 ] ;
int V_61 ;
T_2 V_132 = V_130 [ V_133 ] ;
T_2 V_134 = V_130 [ V_135 ] ;
bool V_106 , V_136 ;
V_136 = V_134 & 0x40 ;
for ( V_61 = 0 ; V_61 < V_137 ; V_61 ++ ) {
V_106 = V_132 & ( 1U << ( 3 + V_61 ) ) ;
F_45 ( V_8 , V_61 , V_106 , V_107 ) ;
if ( V_106 )
V_107 += V_138 ;
}
F_52 ( V_109 , V_139 , V_132 & 0x01 ) ;
F_52 ( V_109 , V_140 , V_132 & 0x02 ) ;
F_50 ( V_109 , V_141 , V_136 != 0 ) ;
F_53 ( V_109 , true ) ;
F_54 ( V_109 ) ;
}
static T_5 F_55 ( int V_72 , void * V_142 )
{
struct V_7 * V_8 = V_142 ;
struct V_60 * V_13 = & V_8 -> V_12 -> V_13 ;
int error ;
T_2 V_143 [ V_144 ] ;
if ( V_8 -> V_73 ) {
F_56 ( & V_8 -> V_69 ) ;
goto V_92;
}
error = V_8 -> V_14 -> V_145 ( V_8 -> V_12 , V_143 ) ;
if ( error )
goto V_92;
if ( V_143 [ V_146 ] != V_147 )
F_4 ( V_13 , L_33 ,
V_143 [ V_146 ] ) ;
else
F_51 ( V_8 , V_143 ) ;
V_92:
return V_148 ;
}
static int F_57 ( struct V_7 * V_8 )
{
struct V_60 * V_13 = & V_8 -> V_12 -> V_13 ;
struct V_108 * V_109 ;
unsigned int V_149 = F_46 ( V_8 -> V_48 , V_8 -> V_49 ) ;
unsigned int V_150 = F_47 ( V_8 -> V_48 , V_8 -> V_49 ) ;
int error ;
V_109 = F_58 ( V_13 ) ;
if ( ! V_109 )
return - V_86 ;
V_109 -> V_151 = L_34 ;
V_109 -> V_152 . V_153 = V_154 ;
V_109 -> V_152 . V_155 = V_156 ;
V_109 -> V_152 . V_157 = V_8 -> V_18 ;
F_59 ( V_109 , V_8 ) ;
error = F_60 ( V_109 , V_137 ,
V_158 | V_159 ) ;
if ( error ) {
F_4 ( V_13 , L_35 , error ) ;
return error ;
}
F_61 ( V_160 , V_109 -> V_161 ) ;
F_61 ( V_162 , V_109 -> V_163 ) ;
if ( V_8 -> V_21 )
F_61 ( V_164 , V_109 -> V_163 ) ;
else
F_61 ( V_140 , V_109 -> V_165 ) ;
F_61 ( V_139 , V_109 -> V_165 ) ;
F_62 ( V_109 , V_166 , 0 , V_8 -> V_45 , 0 , 0 ) ;
F_62 ( V_109 , V_167 , 0 , V_8 -> V_46 , 0 , 0 ) ;
F_63 ( V_109 , V_166 , V_8 -> V_51 ) ;
F_63 ( V_109 , V_167 , V_8 -> V_52 ) ;
F_62 ( V_109 , V_168 , 0 , V_122 , 0 , 0 ) ;
F_62 ( V_109 , V_127 , 0 , V_169 , 0 , 0 ) ;
F_62 ( V_109 , V_141 , 0 , 1 , 0 , 0 ) ;
F_62 ( V_109 , V_124 , 0 , V_8 -> V_45 , 0 , 0 ) ;
F_62 ( V_109 , V_125 , 0 , V_8 -> V_46 , 0 , 0 ) ;
F_63 ( V_109 , V_124 , V_8 -> V_51 ) ;
F_63 ( V_109 , V_125 , V_8 -> V_52 ) ;
F_62 ( V_109 , V_126 , 0 ,
V_122 , 0 , 0 ) ;
F_62 ( V_109 , V_128 , 0 ,
V_169 * V_149 , 0 , 0 ) ;
F_62 ( V_109 , V_129 , 0 ,
V_169 * V_150 , 0 , 0 ) ;
V_8 -> V_109 = V_109 ;
return 0 ;
}
static void F_64 ( void * V_170 )
{
struct V_7 * V_8 = V_170 ;
F_7 ( V_8 -> V_11 ) ;
}
static void F_65 ( void * V_170 )
{
struct V_7 * V_8 = V_170 ;
F_66 ( & V_8 -> V_12 -> V_13 . V_171 , V_172 ) ;
}
static int F_67 ( struct V_22 * V_12 ,
const struct V_173 * V_142 )
{
const struct V_174 * V_175 ;
struct V_60 * V_13 = & V_12 -> V_13 ;
struct V_7 * V_8 ;
unsigned long V_176 ;
int error ;
if ( F_68 ( V_177 ) &&
F_69 ( V_12 -> V_178 , V_179 ) ) {
V_175 = & V_180 ;
} else if ( F_68 ( V_181 ) &&
F_69 ( V_12 -> V_178 ,
V_182 |
V_183 |
V_184 ) ) {
V_175 = & V_185 ;
} else {
F_4 ( V_13 , L_36 ) ;
return - V_70 ;
}
V_8 = F_70 ( V_13 , sizeof( struct V_7 ) , V_84 ) ;
if ( ! V_8 )
return - V_86 ;
F_71 ( V_12 , V_8 ) ;
V_8 -> V_14 = V_175 ;
V_8 -> V_12 = V_12 ;
F_72 ( & V_8 -> V_69 ) ;
F_73 ( & V_8 -> V_89 ) ;
V_8 -> V_11 = F_74 ( V_13 , L_37 ) ;
if ( F_75 ( V_8 -> V_11 ) ) {
error = F_76 ( V_8 -> V_11 ) ;
if ( error != - V_186 )
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
V_8 -> V_29 ,
V_8 -> V_20 ,
V_8 -> V_32 ) ;
F_18 ( V_13 ,
L_43
L_44
L_45
L_46
L_47
L_48 ,
V_8 -> V_45 , V_8 -> V_46 ,
V_8 -> V_48 , V_8 -> V_49 ,
V_8 -> V_51 , V_8 -> V_52 ,
V_8 -> V_1 , V_8 -> V_36 ) ;
error = F_57 ( V_8 ) ;
if ( error )
return error ;
V_176 = V_13 -> V_187 ? 0 : V_188 ;
error = F_79 ( V_13 , V_12 -> V_72 , NULL , F_55 ,
V_176 | V_189 ,
V_12 -> V_151 , V_8 ) ;
if ( error ) {
F_4 ( V_13 , L_49 , V_12 -> V_72 ) ;
return error ;
}
error = F_80 ( & V_13 -> V_171 , V_172 ) ;
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
error = F_81 ( V_8 -> V_109 ) ;
if ( error ) {
F_4 ( V_13 , L_52 , error ) ;
return error ;
}
if ( ! V_13 -> V_187 )
F_82 ( V_13 , true ) ;
return 0 ;
}
static int T_6 F_83 ( struct V_60 * V_13 )
{
struct V_22 * V_12 = F_25 ( V_13 ) ;
struct V_7 * V_8 = F_26 ( V_12 ) ;
int V_190 ;
V_190 = F_37 ( & V_8 -> V_89 ) ;
if ( V_190 )
return V_190 ;
F_22 ( V_12 -> V_72 ) ;
if ( F_84 ( V_13 ) ) {
V_190 = F_8 ( V_8 ) ;
V_8 -> V_191 = ( F_85 ( V_12 -> V_72 ) == 0 ) ;
} else {
V_190 = F_6 ( V_8 ) ;
}
F_38 ( & V_8 -> V_89 ) ;
return V_190 ;
}
static int T_6 F_86 ( struct V_60 * V_13 )
{
struct V_22 * V_12 = F_25 ( V_13 ) ;
struct V_7 * V_8 = F_26 ( V_12 ) ;
int error ;
if ( F_84 ( V_13 ) && V_8 -> V_191 ) {
F_87 ( V_12 -> V_72 ) ;
V_8 -> V_191 = false ;
}
error = F_2 ( V_8 ) ;
if ( error ) {
F_4 ( V_13 , L_53 , error ) ;
goto V_192;
}
error = F_12 ( V_8 ) ;
if ( error )
F_4 ( V_13 , L_54 , error ) ;
V_192:
F_23 ( V_8 -> V_12 -> V_72 ) ;
return error ;
}
