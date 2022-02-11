static int F_1 ( T_1 V_1 , T_2 * V_2 ,
T_2 * V_3 )
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
error = V_8 -> V_14 -> V_19 ( V_8 -> V_12 , & V_8 -> V_20 ,
& V_8 -> V_21 ) ;
if ( error )
return error ;
return 0 ;
}
static int F_10 ( struct V_7 * V_8 )
{
if ( V_8 -> V_20 != 0x0E )
return false ;
switch ( V_8 -> V_18 ) {
case 0x05 ... 0x07 :
case 0x09 :
case 0x13 :
return true ;
default:
return false ;
}
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
error = V_8 -> V_14 -> V_28 ( V_8 -> V_12 , false , & V_8 -> V_29 ) ;
if ( error )
return error ;
error = V_8 -> V_14 -> V_30 ( V_8 -> V_12 , false ,
& V_8 -> V_31 ) ;
if ( error )
return error ;
error = V_8 -> V_14 -> V_28 ( V_8 -> V_12 , true , & V_8 -> V_1 ) ;
if ( error )
return error ;
error = V_8 -> V_14 -> V_32 ( V_8 -> V_12 ,
& V_8 -> V_33 ) ;
if ( error )
return error ;
error = F_1 ( V_8 -> V_1 , & V_8 -> V_34 ,
& V_8 -> V_35 ) ;
if ( error )
F_14 ( & V_8 -> V_12 -> V_13 ,
L_8 ,
V_8 -> V_1 , V_8 -> V_20 ) ;
return 0 ;
}
static unsigned int F_15 ( T_1 V_36 )
{
return ( ( int ) ( char ) V_36 * 10 + 790 ) * 10 / 254 ;
}
static int F_16 ( struct V_7 * V_8 )
{
unsigned int V_37 , V_38 ;
T_1 V_39 , V_40 ;
int error ;
error = V_8 -> V_14 -> V_41 ( V_8 -> V_12 , & V_8 -> V_42 , & V_8 -> V_43 ) ;
if ( error )
return error ;
error = V_8 -> V_14 -> V_44 ( V_8 -> V_12 , & V_37 , & V_38 ) ;
if ( error )
return error ;
V_8 -> V_45 = V_8 -> V_42 / V_37 ;
V_8 -> V_46 = V_8 -> V_43 / V_38 ;
error = V_8 -> V_14 -> V_47 ( V_8 -> V_12 , & V_39 , & V_40 ) ;
if ( error )
return error ;
V_8 -> V_48 = F_15 ( V_39 ) ;
V_8 -> V_49 = F_15 ( V_40 ) ;
return 0 ;
}
static int F_17 ( struct V_7 * V_8 ,
const T_1 * V_50 , T_2 V_51 , int V_52 )
{
int V_53 = V_10 ;
int error ;
do {
error = V_8 -> V_14 -> V_54 ( V_8 -> V_12 ,
V_50 , V_51 , V_52 ) ;
if ( ! error )
return 0 ;
F_18 ( & V_8 -> V_12 -> V_13 ,
L_9 , V_52 , error ) ;
} while ( -- V_53 > 0 );
return error ;
}
static int F_19 ( struct V_7 * V_8 ,
const struct V_55 * V_56 )
{
struct V_22 * V_12 = V_8 -> V_12 ;
struct V_57 * V_13 = & V_12 -> V_13 ;
int V_58 , V_59 ;
int error ;
T_2 V_60 ;
T_2 V_61 ;
T_2 V_62 = 0 , V_31 = 0 ;
error = V_8 -> V_14 -> V_63 ( V_12 ) ;
if ( error )
return error ;
V_60 = F_20 ( & V_56 -> V_8 [ V_64 * 2 ] ) ;
V_61 = ( V_60 * 2 ) / V_5 ;
for ( V_58 = V_61 ; V_58 < V_8 -> V_34 ; V_58 ++ ) {
T_2 V_51 = 0 ;
const T_1 * V_50 = & V_56 -> V_8 [ V_58 * V_5 ] ;
for ( V_59 = 0 ; V_59 < V_5 ; V_59 += 2 )
V_51 += ( ( V_50 [ V_59 + 1 ] << 8 ) | V_50 [ V_59 ] ) ;
error = F_17 ( V_8 , V_50 , V_51 , V_58 ) ;
if ( error ) {
F_4 ( V_13 , L_10 , V_58 , error ) ;
return error ;
}
V_62 += V_51 ;
}
F_5 ( 600 ) ;
error = V_8 -> V_14 -> V_65 ( V_12 , & V_8 -> V_66 ) ;
if ( error )
return error ;
error = V_8 -> V_14 -> V_30 ( V_12 , true , & V_31 ) ;
if ( error )
return error ;
if ( V_62 != V_31 ) {
F_4 ( V_13 , L_11 ,
V_62 , V_31 ) ;
return - V_67 ;
}
return 0 ;
}
static int F_21 ( struct V_7 * V_8 ,
const struct V_55 * V_56 )
{
struct V_22 * V_12 = V_8 -> V_12 ;
int V_68 ;
F_18 ( & V_12 -> V_13 , L_12 ) ;
F_22 ( V_12 -> V_69 ) ;
V_8 -> V_70 = true ;
V_68 = F_19 ( V_8 , V_56 ) ;
if ( V_68 ) {
F_4 ( & V_12 -> V_13 , L_13 , V_68 ) ;
V_8 -> V_14 -> V_71 ( V_12 ) ;
} else {
F_12 ( V_8 ) ;
F_13 ( V_8 ) ;
}
V_8 -> V_70 = false ;
F_23 ( V_12 -> V_69 ) ;
return V_68 ;
}
static T_3 F_24 ( struct V_57 * V_13 ,
struct V_72 * V_73 ,
char * V_74 )
{
struct V_22 * V_12 = F_25 ( V_13 ) ;
struct V_7 * V_8 = F_26 ( V_12 ) ;
return sprintf ( V_74 , L_14 , V_8 -> V_31 ) ;
}
static T_3 F_27 ( struct V_57 * V_13 ,
struct V_72 * V_73 ,
char * V_74 )
{
struct V_22 * V_12 = F_25 ( V_13 ) ;
struct V_7 * V_8 = F_26 ( V_12 ) ;
return sprintf ( V_74 , V_75 L_15 ,
V_8 -> V_18 ) ;
}
static T_3 F_28 ( struct V_57 * V_13 ,
struct V_72 * V_73 ,
char * V_74 )
{
struct V_22 * V_12 = F_25 ( V_13 ) ;
struct V_7 * V_8 = F_26 ( V_12 ) ;
return sprintf ( V_74 , L_16 , V_8 -> V_29 ) ;
}
static T_3 F_29 ( struct V_57 * V_13 ,
struct V_72 * V_73 ,
char * V_74 )
{
struct V_22 * V_12 = F_25 ( V_13 ) ;
struct V_7 * V_8 = F_26 ( V_12 ) ;
return sprintf ( V_74 , L_16 , V_8 -> V_21 ) ;
}
static T_3 F_30 ( struct V_57 * V_13 ,
struct V_72 * V_73 ,
char * V_74 )
{
struct V_22 * V_12 = F_25 ( V_13 ) ;
struct V_7 * V_8 = F_26 ( V_12 ) ;
return sprintf ( V_74 , L_16 , V_8 -> V_1 ) ;
}
static T_3 F_31 ( struct V_57 * V_13 ,
struct V_72 * V_73 ,
const char * V_74 , T_4 V_76 )
{
struct V_7 * V_8 = F_32 ( V_13 ) ;
const struct V_55 * V_56 ;
char * V_77 ;
int error ;
const T_1 * V_78 ;
static const T_1 V_79 [] = { 0xAA , 0x55 , 0xCC , 0x33 , 0xFF , 0xFF } ;
if ( V_8 -> V_34 == 0 )
return - V_80 ;
V_77 = F_33 ( V_81 , V_82 , V_8 -> V_18 ) ;
if ( ! V_77 ) {
F_4 ( V_13 , L_17 ) ;
return - V_83 ;
}
F_34 ( V_13 , L_18 , V_77 ) ;
error = F_35 ( & V_56 , V_77 , V_13 ) ;
F_36 ( V_77 ) ;
if ( error ) {
F_4 ( V_13 , L_19 , error ) ;
return error ;
}
V_78 = & V_56 -> V_8 [ V_8 -> V_35 ] ;
if ( memcmp ( V_78 , V_79 , sizeof( V_79 ) ) != 0 ) {
F_4 ( V_13 , L_20 ,
( int ) sizeof( V_79 ) , V_79 ,
( int ) sizeof( V_79 ) , V_78 ) ;
error = - V_84 ;
goto V_85;
}
error = F_37 ( & V_8 -> V_86 ) ;
if ( error )
goto V_85;
error = F_21 ( V_8 , V_56 ) ;
F_38 ( & V_8 -> V_86 ) ;
V_85:
F_39 ( V_56 ) ;
return error ? : V_76 ;
}
static T_3 F_40 ( struct V_57 * V_13 ,
struct V_72 * V_73 ,
const char * V_74 , T_4 V_76 )
{
struct V_22 * V_12 = F_25 ( V_13 ) ;
struct V_7 * V_8 = F_26 ( V_12 ) ;
int V_87 = 20 ;
int V_68 ;
int error ;
T_1 V_36 [ 3 ] ;
V_68 = F_37 ( & V_8 -> V_86 ) ;
if ( V_68 )
return V_68 ;
F_22 ( V_12 -> V_69 ) ;
V_8 -> V_25 |= V_88 ;
V_68 = V_8 -> V_14 -> V_27 ( V_12 , V_8 -> V_25 ) ;
if ( V_68 ) {
F_4 ( V_13 , L_21 ,
V_68 ) ;
goto V_89;
}
V_68 = V_8 -> V_14 -> V_90 ( V_12 ) ;
if ( V_68 ) {
F_4 ( V_13 , L_22 ,
V_68 ) ;
goto V_91;
}
V_36 [ 0 ] = 0xff ;
do {
F_5 ( 250 ) ;
V_68 = V_8 -> V_14 -> V_92 ( V_12 , V_36 ) ;
if ( V_68 )
F_4 ( V_13 , L_23 ,
V_68 ) ;
else if ( V_36 [ 0 ] == 0 )
break;
} while ( -- V_87 );
if ( V_87 == 0 ) {
F_4 ( V_13 , L_24 ) ;
V_68 = - V_93 ;
}
V_91:
V_8 -> V_25 &= ~ V_88 ;
error = V_8 -> V_14 -> V_27 ( V_8 -> V_12 , V_8 -> V_25 ) ;
if ( error ) {
F_4 ( V_13 , L_25 ,
error ) ;
if ( ! V_68 )
V_68 = error ;
}
V_89:
F_23 ( V_12 -> V_69 ) ;
F_38 ( & V_8 -> V_86 ) ;
return V_68 ? : V_76 ;
}
static T_3 F_41 ( struct V_57 * V_13 ,
struct V_72 * V_73 ,
char * V_74 )
{
struct V_22 * V_12 = F_25 ( V_13 ) ;
struct V_7 * V_8 = F_26 ( V_12 ) ;
int error ;
enum V_94 V_25 ;
error = F_37 ( & V_8 -> V_86 ) ;
if ( error )
return error ;
error = V_8 -> V_14 -> V_95 ( V_8 -> V_12 , & V_25 ) ;
F_38 ( & V_8 -> V_86 ) ;
if ( error )
return error ;
return sprintf ( V_74 , L_26 , ( int ) V_25 ) ;
}
static T_3 F_42 ( struct V_57 * V_13 , struct V_72 * V_73 ,
const char * V_74 , T_4 V_76 )
{
struct V_22 * V_12 = F_25 ( V_13 ) ;
struct V_7 * V_8 = F_26 ( V_12 ) ;
int error ;
int V_68 ;
V_68 = F_37 ( & V_8 -> V_86 ) ;
if ( V_68 )
return V_68 ;
F_22 ( V_12 -> V_69 ) ;
V_8 -> V_96 = false ;
V_8 -> V_25 |= V_88 ;
V_68 = V_8 -> V_14 -> V_27 ( V_8 -> V_12 , V_8 -> V_25 ) ;
if ( V_68 ) {
F_4 ( V_13 , L_27 ,
V_68 ) ;
goto V_89;
}
F_5 ( 250 ) ;
V_68 = V_8 -> V_14 -> V_97 ( V_8 -> V_12 , true ,
& V_8 -> V_98 ) ;
if ( V_68 ) {
F_4 ( V_13 , L_28 ,
V_68 ) ;
goto V_91;
}
V_68 = V_8 -> V_14 -> V_97 ( V_8 -> V_12 , false ,
& V_8 -> V_99 ) ;
if ( V_68 ) {
F_4 ( V_13 , L_29 ,
V_68 ) ;
goto V_91;
}
V_8 -> V_96 = true ;
V_91:
V_8 -> V_25 &= ~ V_88 ;
error = V_8 -> V_14 -> V_27 ( V_8 -> V_12 , V_8 -> V_25 ) ;
if ( error ) {
F_4 ( V_13 , L_30 ,
error ) ;
if ( ! V_68 )
V_68 = error ;
}
V_89:
F_23 ( V_12 -> V_69 ) ;
F_38 ( & V_8 -> V_86 ) ;
return V_68 ? : V_76 ;
}
static T_3 F_43 ( struct V_57 * V_13 ,
struct V_72 * V_73 , char * V_74 )
{
struct V_22 * V_12 = F_25 ( V_13 ) ;
struct V_7 * V_8 = F_26 ( V_12 ) ;
int V_68 ;
V_68 = F_37 ( & V_8 -> V_86 ) ;
if ( V_68 )
return V_68 ;
if ( ! V_8 -> V_96 ) {
V_68 = - V_100 ;
goto V_89;
}
V_68 = snprintf ( V_74 , V_101 , L_31 , V_8 -> V_99 ) ;
V_89:
F_38 ( & V_8 -> V_86 ) ;
return V_68 ;
}
static T_3 F_44 ( struct V_57 * V_13 ,
struct V_72 * V_73 , char * V_74 )
{
struct V_22 * V_12 = F_25 ( V_13 ) ;
struct V_7 * V_8 = F_26 ( V_12 ) ;
int V_68 ;
V_68 = F_37 ( & V_8 -> V_86 ) ;
if ( V_68 )
return V_68 ;
if ( ! V_8 -> V_96 ) {
V_68 = - V_100 ;
goto V_89;
}
V_68 = snprintf ( V_74 , V_101 , L_31 , V_8 -> V_98 ) ;
V_89:
F_38 ( & V_8 -> V_86 ) ;
return V_68 ;
}
static void F_45 ( struct V_7 * V_8 ,
int V_102 , bool V_103 ,
T_1 * V_104 )
{
struct V_105 * V_106 = V_8 -> V_106 ;
unsigned int V_107 , V_108 ;
unsigned int V_109 , V_110 , V_111 ;
unsigned int V_112 , V_113 , V_114 , V_115 ;
unsigned int V_116 ;
if ( V_103 ) {
V_107 = ( ( V_104 [ 0 ] & 0xf0 ) << 4 ) |
V_104 [ 1 ] ;
V_108 = ( ( V_104 [ 0 ] & 0x0f ) << 8 ) |
V_104 [ 2 ] ;
V_110 = ( V_104 [ 3 ] & 0x0f ) ;
V_111 = ( V_104 [ 3 ] >> 4 ) ;
V_109 = V_104 [ 4 ] ;
if ( V_107 > V_8 -> V_42 || V_108 > V_8 -> V_43 ) {
F_18 ( V_106 -> V_13 . V_117 ,
L_32 ,
V_102 , V_107 , V_108 ,
V_8 -> V_42 , V_8 -> V_43 ) ;
return;
}
V_112 = V_110 * ( V_8 -> V_45 - V_118 ) ;
V_113 = V_111 * ( V_8 -> V_46 - V_118 ) ;
V_114 = F_46 ( V_112 , V_113 ) ;
V_115 = F_47 ( V_112 , V_113 ) ;
V_116 = V_109 + V_8 -> V_33 ;
if ( V_116 > V_119 )
V_116 = V_119 ;
F_48 ( V_106 , V_102 ) ;
F_49 ( V_106 , V_120 , true ) ;
F_50 ( V_106 , V_121 , V_107 ) ;
F_50 ( V_106 , V_122 , V_8 -> V_43 - V_108 ) ;
F_50 ( V_106 , V_123 , V_116 ) ;
F_50 ( V_106 , V_124 , V_110 ) ;
F_50 ( V_106 , V_125 , V_114 ) ;
F_50 ( V_106 , V_126 , V_115 ) ;
} else {
F_48 ( V_106 , V_102 ) ;
F_49 ( V_106 , V_120 , false ) ;
}
}
static void F_51 ( struct V_7 * V_8 , T_1 * V_127 )
{
struct V_105 * V_106 = V_8 -> V_106 ;
T_1 * V_104 = & V_127 [ V_128 ] ;
int V_58 ;
T_1 V_129 = V_127 [ V_130 ] ;
T_1 V_131 = V_127 [ V_132 ] ;
bool V_103 , V_133 ;
V_133 = V_131 & 0x40 ;
for ( V_58 = 0 ; V_58 < V_134 ; V_58 ++ ) {
V_103 = V_129 & ( 1U << ( 3 + V_58 ) ) ;
F_45 ( V_8 , V_58 , V_103 , V_104 ) ;
if ( V_103 )
V_104 += V_135 ;
}
F_52 ( V_106 , V_136 , V_129 & 0x01 ) ;
F_50 ( V_106 , V_137 , V_133 != 0 ) ;
F_53 ( V_106 , true ) ;
F_54 ( V_106 ) ;
}
static T_5 F_55 ( int V_69 , void * V_138 )
{
struct V_7 * V_8 = V_138 ;
struct V_57 * V_13 = & V_8 -> V_12 -> V_13 ;
int error ;
T_1 V_139 [ V_140 ] ;
if ( V_8 -> V_70 ) {
F_56 ( & V_8 -> V_66 ) ;
goto V_89;
}
error = V_8 -> V_14 -> V_141 ( V_8 -> V_12 , V_139 ) ;
if ( error )
goto V_89;
if ( V_139 [ V_142 ] != V_143 )
F_4 ( V_13 , L_33 ,
V_139 [ V_142 ] ) ;
else
F_51 ( V_8 , V_139 ) ;
V_89:
return V_144 ;
}
static int F_57 ( struct V_7 * V_8 )
{
struct V_57 * V_13 = & V_8 -> V_12 -> V_13 ;
struct V_105 * V_106 ;
unsigned int V_145 = F_46 ( V_8 -> V_45 , V_8 -> V_46 ) ;
unsigned int V_146 = F_47 ( V_8 -> V_45 , V_8 -> V_46 ) ;
int error ;
V_106 = F_58 ( V_13 ) ;
if ( ! V_106 )
return - V_83 ;
V_106 -> V_147 = L_34 ;
V_106 -> V_148 . V_149 = V_150 ;
V_106 -> V_148 . V_151 = V_152 ;
V_106 -> V_148 . V_153 = V_8 -> V_18 ;
F_59 ( V_106 , V_8 ) ;
error = F_60 ( V_106 , V_134 ,
V_154 | V_155 ) ;
if ( error ) {
F_4 ( V_13 , L_35 , error ) ;
return error ;
}
F_61 ( V_156 , V_106 -> V_157 ) ;
F_61 ( V_158 , V_106 -> V_159 ) ;
F_61 ( V_160 , V_106 -> V_159 ) ;
F_61 ( V_136 , V_106 -> V_161 ) ;
F_62 ( V_106 , V_162 , 0 , V_8 -> V_42 , 0 , 0 ) ;
F_62 ( V_106 , V_163 , 0 , V_8 -> V_43 , 0 , 0 ) ;
F_63 ( V_106 , V_162 , V_8 -> V_48 ) ;
F_63 ( V_106 , V_163 , V_8 -> V_49 ) ;
F_62 ( V_106 , V_164 , 0 , V_119 , 0 , 0 ) ;
F_62 ( V_106 , V_124 , 0 , V_165 , 0 , 0 ) ;
F_62 ( V_106 , V_137 , 0 , 1 , 0 , 0 ) ;
F_62 ( V_106 , V_121 , 0 , V_8 -> V_42 , 0 , 0 ) ;
F_62 ( V_106 , V_122 , 0 , V_8 -> V_43 , 0 , 0 ) ;
F_63 ( V_106 , V_121 , V_8 -> V_48 ) ;
F_63 ( V_106 , V_122 , V_8 -> V_49 ) ;
F_62 ( V_106 , V_123 , 0 ,
V_119 , 0 , 0 ) ;
F_62 ( V_106 , V_125 , 0 ,
V_165 * V_145 , 0 , 0 ) ;
F_62 ( V_106 , V_126 , 0 ,
V_165 * V_146 , 0 , 0 ) ;
V_8 -> V_106 = V_106 ;
return 0 ;
}
static void F_64 ( void * V_166 )
{
struct V_7 * V_8 = V_166 ;
F_7 ( V_8 -> V_11 ) ;
}
static void F_65 ( void * V_166 )
{
struct V_7 * V_8 = V_166 ;
F_66 ( & V_8 -> V_12 -> V_13 . V_167 , V_168 ) ;
}
static int F_67 ( struct V_22 * V_12 ,
const struct V_169 * V_138 )
{
const struct V_170 * V_171 ;
struct V_57 * V_13 = & V_12 -> V_13 ;
struct V_7 * V_8 ;
unsigned long V_172 ;
int error ;
if ( F_68 ( V_173 ) &&
F_69 ( V_12 -> V_174 , V_175 ) ) {
V_171 = & V_176 ;
} else if ( F_68 ( V_177 ) &&
F_69 ( V_12 -> V_174 ,
V_178 |
V_179 |
V_180 ) ) {
V_171 = & V_181 ;
} else {
F_4 ( V_13 , L_36 ) ;
return - V_67 ;
}
V_8 = F_70 ( & V_12 -> V_13 , sizeof( struct V_7 ) ,
V_81 ) ;
if ( ! V_8 )
return - V_83 ;
F_71 ( V_12 , V_8 ) ;
V_8 -> V_14 = V_171 ;
V_8 -> V_12 = V_12 ;
F_72 ( & V_8 -> V_66 ) ;
F_73 ( & V_8 -> V_86 ) ;
V_8 -> V_11 = F_74 ( & V_12 -> V_13 , L_37 ) ;
if ( F_75 ( V_8 -> V_11 ) ) {
error = F_76 ( V_8 -> V_11 ) ;
if ( error != - V_182 )
F_4 ( & V_12 -> V_13 ,
L_38 ,
error ) ;
return error ;
}
error = F_3 ( V_8 -> V_11 ) ;
if ( error ) {
F_4 ( & V_12 -> V_13 ,
L_39 , error ) ;
return error ;
}
error = F_77 ( & V_12 -> V_13 ,
F_64 , V_8 ) ;
if ( error ) {
F_7 ( V_8 -> V_11 ) ;
F_4 ( & V_12 -> V_13 ,
L_40 ,
error ) ;
return error ;
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
F_34 ( & V_12 -> V_13 ,
L_41 ,
V_8 -> V_18 ,
V_8 -> V_29 ,
V_8 -> V_21 ,
V_8 -> V_1 ) ;
F_18 ( & V_12 -> V_13 ,
L_42
L_43
L_44
L_45 ,
V_8 -> V_42 , V_8 -> V_43 ,
V_8 -> V_45 , V_8 -> V_46 ,
V_8 -> V_48 , V_8 -> V_49 ) ;
error = F_57 ( V_8 ) ;
if ( error )
return error ;
V_172 = V_12 -> V_13 . V_183 ? 0 : V_184 ;
error = F_78 ( & V_12 -> V_13 , V_12 -> V_69 ,
NULL , F_55 ,
V_172 | V_185 ,
V_12 -> V_147 , V_8 ) ;
if ( error ) {
F_4 ( & V_12 -> V_13 , L_46 , V_12 -> V_69 ) ;
return error ;
}
error = F_79 ( & V_12 -> V_13 . V_167 , V_168 ) ;
if ( error ) {
F_4 ( & V_12 -> V_13 , L_47 ,
error ) ;
return error ;
}
error = F_77 ( & V_12 -> V_13 ,
F_65 , V_8 ) ;
if ( error ) {
F_65 ( V_8 ) ;
F_4 ( & V_12 -> V_13 ,
L_48 ,
error ) ;
return error ;
}
error = F_80 ( V_8 -> V_106 ) ;
if ( error ) {
F_4 ( & V_12 -> V_13 , L_49 ,
error ) ;
return error ;
}
if ( ! V_12 -> V_13 . V_183 )
F_81 ( & V_12 -> V_13 , true ) ;
return 0 ;
}
static int T_6 F_82 ( struct V_57 * V_13 )
{
struct V_22 * V_12 = F_25 ( V_13 ) ;
struct V_7 * V_8 = F_26 ( V_12 ) ;
int V_186 ;
V_186 = F_37 ( & V_8 -> V_86 ) ;
if ( V_186 )
return V_186 ;
F_22 ( V_12 -> V_69 ) ;
if ( F_83 ( V_13 ) ) {
V_186 = F_8 ( V_8 ) ;
V_8 -> V_187 = ( F_84 ( V_12 -> V_69 ) == 0 ) ;
} else {
V_186 = F_6 ( V_8 ) ;
}
F_38 ( & V_8 -> V_86 ) ;
return V_186 ;
}
static int T_6 F_85 ( struct V_57 * V_13 )
{
struct V_22 * V_12 = F_25 ( V_13 ) ;
struct V_7 * V_8 = F_26 ( V_12 ) ;
int error ;
if ( F_83 ( V_13 ) && V_8 -> V_187 ) {
F_86 ( V_12 -> V_69 ) ;
V_8 -> V_187 = false ;
}
error = F_2 ( V_8 ) ;
if ( error ) {
F_4 ( V_13 , L_50 , error ) ;
goto V_188;
}
error = F_12 ( V_8 ) ;
if ( error )
F_4 ( V_13 , L_51 , error ) ;
V_188:
F_23 ( V_8 -> V_12 -> V_69 ) ;
return error ;
}
