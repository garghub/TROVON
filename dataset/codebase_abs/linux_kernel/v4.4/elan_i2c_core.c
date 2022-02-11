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
struct V_17 * V_12 = V_8 -> V_12 ;
int error ;
error = V_8 -> V_14 -> V_18 ( V_12 ) ;
if ( error ) {
F_4 ( & V_12 -> V_13 , L_5 , error ) ;
return error ;
}
V_8 -> V_19 |= V_20 ;
error = V_8 -> V_14 -> V_21 ( V_12 , V_8 -> V_19 ) ;
if ( error ) {
F_4 ( & V_12 -> V_13 ,
L_6 , error ) ;
return error ;
}
error = V_8 -> V_14 -> V_16 ( V_12 , false ) ;
if ( error ) {
F_4 ( & V_12 -> V_13 ,
L_7 , error ) ;
return error ;
}
return 0 ;
}
static int F_10 ( struct V_7 * V_8 )
{
int V_9 = V_10 ;
int error ;
do {
error = F_9 ( V_8 ) ;
if ( ! error )
return 0 ;
F_5 ( 30 ) ;
} while ( -- V_9 > 0 );
return error ;
}
static int F_11 ( struct V_7 * V_8 )
{
int error ;
error = V_8 -> V_14 -> V_22 ( V_8 -> V_12 , & V_8 -> V_23 ) ;
if ( error )
return error ;
error = V_8 -> V_14 -> V_24 ( V_8 -> V_12 , false , & V_8 -> V_25 ) ;
if ( error )
return error ;
error = V_8 -> V_14 -> V_26 ( V_8 -> V_12 , false ,
& V_8 -> V_27 ) ;
if ( error )
return error ;
error = V_8 -> V_14 -> V_28 ( V_8 -> V_12 , & V_8 -> V_29 ,
& V_8 -> V_30 ) ;
if ( error )
return error ;
error = V_8 -> V_14 -> V_24 ( V_8 -> V_12 , true , & V_8 -> V_1 ) ;
if ( error )
return error ;
error = V_8 -> V_14 -> V_31 ( V_8 -> V_12 ,
& V_8 -> V_32 ) ;
if ( error )
return error ;
error = F_1 ( V_8 -> V_1 , & V_8 -> V_33 ,
& V_8 -> V_34 ) ;
if ( error )
F_12 ( & V_8 -> V_12 -> V_13 ,
L_8 ,
V_8 -> V_1 , V_8 -> V_29 ) ;
return 0 ;
}
static unsigned int F_13 ( T_1 V_35 )
{
return ( ( int ) ( char ) V_35 * 10 + 790 ) * 10 / 254 ;
}
static int F_14 ( struct V_7 * V_8 )
{
unsigned int V_36 , V_37 ;
T_1 V_38 , V_39 ;
int error ;
error = V_8 -> V_14 -> V_40 ( V_8 -> V_12 , & V_8 -> V_41 , & V_8 -> V_42 ) ;
if ( error )
return error ;
error = V_8 -> V_14 -> V_43 ( V_8 -> V_12 , & V_36 , & V_37 ) ;
if ( error )
return error ;
V_8 -> V_44 = V_8 -> V_41 / V_36 ;
V_8 -> V_45 = V_8 -> V_42 / V_37 ;
error = V_8 -> V_14 -> V_46 ( V_8 -> V_12 , & V_38 , & V_39 ) ;
if ( error )
return error ;
V_8 -> V_47 = F_13 ( V_38 ) ;
V_8 -> V_48 = F_13 ( V_39 ) ;
return 0 ;
}
static int F_15 ( struct V_7 * V_8 ,
const T_1 * V_49 , T_2 V_50 , int V_51 )
{
int V_52 = V_10 ;
int error ;
do {
error = V_8 -> V_14 -> V_53 ( V_8 -> V_12 ,
V_49 , V_50 , V_51 ) ;
if ( ! error )
return 0 ;
F_16 ( & V_8 -> V_12 -> V_13 ,
L_9 , V_51 , error ) ;
} while ( -- V_52 > 0 );
return error ;
}
static int F_17 ( struct V_7 * V_8 ,
const struct V_54 * V_55 )
{
struct V_17 * V_12 = V_8 -> V_12 ;
struct V_56 * V_13 = & V_12 -> V_13 ;
int V_57 , V_58 ;
int error ;
T_2 V_59 ;
T_2 V_60 ;
T_2 V_61 = 0 , V_27 = 0 ;
error = V_8 -> V_14 -> V_62 ( V_12 ) ;
if ( error )
return error ;
V_59 = F_18 ( & V_55 -> V_8 [ V_63 * 2 ] ) ;
V_60 = ( V_59 * 2 ) / V_5 ;
for ( V_57 = V_60 ; V_57 < V_8 -> V_33 ; V_57 ++ ) {
T_2 V_50 = 0 ;
const T_1 * V_49 = & V_55 -> V_8 [ V_57 * V_5 ] ;
for ( V_58 = 0 ; V_58 < V_5 ; V_58 += 2 )
V_50 += ( ( V_49 [ V_58 + 1 ] << 8 ) | V_49 [ V_58 ] ) ;
error = F_15 ( V_8 , V_49 , V_50 , V_57 ) ;
if ( error ) {
F_4 ( V_13 , L_10 , V_57 , error ) ;
return error ;
}
V_61 += V_50 ;
}
F_5 ( 600 ) ;
error = V_8 -> V_14 -> V_64 ( V_12 , & V_8 -> V_65 ) ;
if ( error )
return error ;
error = V_8 -> V_14 -> V_26 ( V_12 , true , & V_27 ) ;
if ( error )
return error ;
if ( V_61 != V_27 ) {
F_4 ( V_13 , L_11 ,
V_61 , V_27 ) ;
return - V_66 ;
}
return 0 ;
}
static int F_19 ( struct V_7 * V_8 ,
const struct V_54 * V_55 )
{
struct V_17 * V_12 = V_8 -> V_12 ;
int V_67 ;
F_16 ( & V_12 -> V_13 , L_12 ) ;
F_20 ( V_12 -> V_68 ) ;
V_8 -> V_69 = true ;
V_67 = F_17 ( V_8 , V_55 ) ;
if ( V_67 ) {
F_4 ( & V_12 -> V_13 , L_13 , V_67 ) ;
V_8 -> V_14 -> V_70 ( V_12 ) ;
} else {
F_10 ( V_8 ) ;
F_11 ( V_8 ) ;
}
V_8 -> V_69 = false ;
F_21 ( V_12 -> V_68 ) ;
return V_67 ;
}
static T_3 F_22 ( struct V_56 * V_13 ,
struct V_71 * V_72 ,
char * V_73 )
{
struct V_17 * V_12 = F_23 ( V_13 ) ;
struct V_7 * V_8 = F_24 ( V_12 ) ;
return sprintf ( V_73 , L_14 , V_8 -> V_27 ) ;
}
static T_3 F_25 ( struct V_56 * V_13 ,
struct V_71 * V_72 ,
char * V_73 )
{
struct V_17 * V_12 = F_23 ( V_13 ) ;
struct V_7 * V_8 = F_24 ( V_12 ) ;
return sprintf ( V_73 , V_74 L_15 ,
V_8 -> V_23 ) ;
}
static T_3 F_26 ( struct V_56 * V_13 ,
struct V_71 * V_72 ,
char * V_73 )
{
struct V_17 * V_12 = F_23 ( V_13 ) ;
struct V_7 * V_8 = F_24 ( V_12 ) ;
return sprintf ( V_73 , L_16 , V_8 -> V_25 ) ;
}
static T_3 F_27 ( struct V_56 * V_13 ,
struct V_71 * V_72 ,
char * V_73 )
{
struct V_17 * V_12 = F_23 ( V_13 ) ;
struct V_7 * V_8 = F_24 ( V_12 ) ;
return sprintf ( V_73 , L_16 , V_8 -> V_30 ) ;
}
static T_3 F_28 ( struct V_56 * V_13 ,
struct V_71 * V_72 ,
char * V_73 )
{
struct V_17 * V_12 = F_23 ( V_13 ) ;
struct V_7 * V_8 = F_24 ( V_12 ) ;
return sprintf ( V_73 , L_16 , V_8 -> V_1 ) ;
}
static T_3 F_29 ( struct V_56 * V_13 ,
struct V_71 * V_72 ,
const char * V_73 , T_4 V_75 )
{
struct V_7 * V_8 = F_30 ( V_13 ) ;
const struct V_54 * V_55 ;
char * V_76 ;
int error ;
const T_1 * V_77 ;
static const T_1 V_78 [] = { 0xAA , 0x55 , 0xCC , 0x33 , 0xFF , 0xFF } ;
if ( V_8 -> V_33 == 0 )
return - V_79 ;
V_76 = F_31 ( V_80 , V_81 , V_8 -> V_23 ) ;
if ( ! V_76 ) {
F_4 ( V_13 , L_17 ) ;
return - V_82 ;
}
F_32 ( V_13 , L_18 , V_76 ) ;
error = F_33 ( & V_55 , V_76 , V_13 ) ;
F_34 ( V_76 ) ;
if ( error ) {
F_4 ( V_13 , L_19 , error ) ;
return error ;
}
V_77 = & V_55 -> V_8 [ V_8 -> V_34 ] ;
if ( memcmp ( V_77 , V_78 , sizeof( V_78 ) ) != 0 ) {
F_4 ( V_13 , L_20 ,
( int ) sizeof( V_78 ) , V_78 ,
( int ) sizeof( V_78 ) , V_77 ) ;
error = - V_83 ;
goto V_84;
}
error = F_35 ( & V_8 -> V_85 ) ;
if ( error )
goto V_84;
error = F_19 ( V_8 , V_55 ) ;
F_36 ( & V_8 -> V_85 ) ;
V_84:
F_37 ( V_55 ) ;
return error ? : V_75 ;
}
static T_3 F_38 ( struct V_56 * V_13 ,
struct V_71 * V_72 ,
const char * V_73 , T_4 V_75 )
{
struct V_17 * V_12 = F_23 ( V_13 ) ;
struct V_7 * V_8 = F_24 ( V_12 ) ;
int V_86 = 20 ;
int V_67 ;
int error ;
T_1 V_35 [ 3 ] ;
V_67 = F_35 ( & V_8 -> V_85 ) ;
if ( V_67 )
return V_67 ;
F_20 ( V_12 -> V_68 ) ;
V_8 -> V_19 |= V_87 ;
V_67 = V_8 -> V_14 -> V_21 ( V_12 , V_8 -> V_19 ) ;
if ( V_67 ) {
F_4 ( V_13 , L_21 ,
V_67 ) ;
goto V_88;
}
V_67 = V_8 -> V_14 -> V_89 ( V_12 ) ;
if ( V_67 ) {
F_4 ( V_13 , L_22 ,
V_67 ) ;
goto V_90;
}
V_35 [ 0 ] = 0xff ;
do {
F_5 ( 250 ) ;
V_67 = V_8 -> V_14 -> V_91 ( V_12 , V_35 ) ;
if ( V_67 )
F_4 ( V_13 , L_23 ,
V_67 ) ;
else if ( V_35 [ 0 ] == 0 )
break;
} while ( -- V_86 );
if ( V_86 == 0 ) {
F_4 ( V_13 , L_24 ) ;
V_67 = - V_92 ;
}
V_90:
V_8 -> V_19 &= ~ V_87 ;
error = V_8 -> V_14 -> V_21 ( V_8 -> V_12 , V_8 -> V_19 ) ;
if ( error ) {
F_4 ( V_13 , L_25 ,
error ) ;
if ( ! V_67 )
V_67 = error ;
}
V_88:
F_21 ( V_12 -> V_68 ) ;
F_36 ( & V_8 -> V_85 ) ;
return V_67 ? : V_75 ;
}
static T_3 F_39 ( struct V_56 * V_13 ,
struct V_71 * V_72 ,
char * V_73 )
{
struct V_17 * V_12 = F_23 ( V_13 ) ;
struct V_7 * V_8 = F_24 ( V_12 ) ;
int error ;
enum V_93 V_19 ;
error = F_35 ( & V_8 -> V_85 ) ;
if ( error )
return error ;
error = V_8 -> V_14 -> V_94 ( V_8 -> V_12 , & V_19 ) ;
F_36 ( & V_8 -> V_85 ) ;
if ( error )
return error ;
return sprintf ( V_73 , L_26 , ( int ) V_19 ) ;
}
static T_3 F_40 ( struct V_56 * V_13 , struct V_71 * V_72 ,
const char * V_73 , T_4 V_75 )
{
struct V_17 * V_12 = F_23 ( V_13 ) ;
struct V_7 * V_8 = F_24 ( V_12 ) ;
int error ;
int V_67 ;
V_67 = F_35 ( & V_8 -> V_85 ) ;
if ( V_67 )
return V_67 ;
F_20 ( V_12 -> V_68 ) ;
V_8 -> V_95 = false ;
V_8 -> V_19 |= V_87 ;
V_67 = V_8 -> V_14 -> V_21 ( V_8 -> V_12 , V_8 -> V_19 ) ;
if ( V_67 ) {
F_4 ( V_13 , L_27 ,
V_67 ) ;
goto V_88;
}
F_5 ( 250 ) ;
V_67 = V_8 -> V_14 -> V_96 ( V_8 -> V_12 , true ,
& V_8 -> V_97 ) ;
if ( V_67 ) {
F_4 ( V_13 , L_28 ,
V_67 ) ;
goto V_90;
}
V_67 = V_8 -> V_14 -> V_96 ( V_8 -> V_12 , false ,
& V_8 -> V_98 ) ;
if ( V_67 ) {
F_4 ( V_13 , L_29 ,
V_67 ) ;
goto V_90;
}
V_8 -> V_95 = true ;
V_90:
V_8 -> V_19 &= ~ V_87 ;
error = V_8 -> V_14 -> V_21 ( V_8 -> V_12 , V_8 -> V_19 ) ;
if ( error ) {
F_4 ( V_13 , L_30 ,
error ) ;
if ( ! V_67 )
V_67 = error ;
}
V_88:
F_21 ( V_12 -> V_68 ) ;
F_36 ( & V_8 -> V_85 ) ;
return V_67 ? : V_75 ;
}
static T_3 F_41 ( struct V_56 * V_13 ,
struct V_71 * V_72 , char * V_73 )
{
struct V_17 * V_12 = F_23 ( V_13 ) ;
struct V_7 * V_8 = F_24 ( V_12 ) ;
int V_67 ;
V_67 = F_35 ( & V_8 -> V_85 ) ;
if ( V_67 )
return V_67 ;
if ( ! V_8 -> V_95 ) {
V_67 = - V_99 ;
goto V_88;
}
V_67 = snprintf ( V_73 , V_100 , L_31 , V_8 -> V_98 ) ;
V_88:
F_36 ( & V_8 -> V_85 ) ;
return V_67 ;
}
static T_3 F_42 ( struct V_56 * V_13 ,
struct V_71 * V_72 , char * V_73 )
{
struct V_17 * V_12 = F_23 ( V_13 ) ;
struct V_7 * V_8 = F_24 ( V_12 ) ;
int V_67 ;
V_67 = F_35 ( & V_8 -> V_85 ) ;
if ( V_67 )
return V_67 ;
if ( ! V_8 -> V_95 ) {
V_67 = - V_99 ;
goto V_88;
}
V_67 = snprintf ( V_73 , V_100 , L_31 , V_8 -> V_97 ) ;
V_88:
F_36 ( & V_8 -> V_85 ) ;
return V_67 ;
}
static void F_43 ( struct V_7 * V_8 ,
int V_101 , bool V_102 ,
T_1 * V_103 )
{
struct V_104 * V_105 = V_8 -> V_105 ;
unsigned int V_106 , V_107 ;
unsigned int V_108 , V_109 , V_110 ;
unsigned int V_111 , V_112 , V_113 , V_114 ;
unsigned int V_115 ;
if ( V_102 ) {
V_106 = ( ( V_103 [ 0 ] & 0xf0 ) << 4 ) |
V_103 [ 1 ] ;
V_107 = ( ( V_103 [ 0 ] & 0x0f ) << 8 ) |
V_103 [ 2 ] ;
V_109 = ( V_103 [ 3 ] & 0x0f ) ;
V_110 = ( V_103 [ 3 ] >> 4 ) ;
V_108 = V_103 [ 4 ] ;
if ( V_106 > V_8 -> V_41 || V_107 > V_8 -> V_42 ) {
F_16 ( V_105 -> V_13 . V_116 ,
L_32 ,
V_101 , V_106 , V_107 ,
V_8 -> V_41 , V_8 -> V_42 ) ;
return;
}
V_111 = V_109 * ( V_8 -> V_44 - V_117 ) ;
V_112 = V_110 * ( V_8 -> V_45 - V_117 ) ;
V_113 = F_44 ( V_111 , V_112 ) ;
V_114 = F_45 ( V_111 , V_112 ) ;
V_115 = V_108 + V_8 -> V_32 ;
if ( V_115 > V_118 )
V_115 = V_118 ;
F_46 ( V_105 , V_101 ) ;
F_47 ( V_105 , V_119 , true ) ;
F_48 ( V_105 , V_120 , V_106 ) ;
F_48 ( V_105 , V_121 , V_8 -> V_42 - V_107 ) ;
F_48 ( V_105 , V_122 , V_115 ) ;
F_48 ( V_105 , V_123 , V_109 ) ;
F_48 ( V_105 , V_124 , V_113 ) ;
F_48 ( V_105 , V_125 , V_114 ) ;
} else {
F_46 ( V_105 , V_101 ) ;
F_47 ( V_105 , V_119 , false ) ;
}
}
static void F_49 ( struct V_7 * V_8 , T_1 * V_126 )
{
struct V_104 * V_105 = V_8 -> V_105 ;
T_1 * V_103 = & V_126 [ V_127 ] ;
int V_57 ;
T_1 V_128 = V_126 [ V_129 ] ;
T_1 V_130 = V_126 [ V_131 ] ;
bool V_102 , V_132 ;
V_132 = V_130 & 0x40 ;
for ( V_57 = 0 ; V_57 < V_133 ; V_57 ++ ) {
V_102 = V_128 & ( 1U << ( 3 + V_57 ) ) ;
F_43 ( V_8 , V_57 , V_102 , V_103 ) ;
if ( V_102 )
V_103 += V_134 ;
}
F_50 ( V_105 , V_135 , V_128 & 0x01 ) ;
F_48 ( V_105 , V_136 , V_132 != 0 ) ;
F_51 ( V_105 , true ) ;
F_52 ( V_105 ) ;
}
static T_5 F_53 ( int V_68 , void * V_137 )
{
struct V_7 * V_8 = V_137 ;
struct V_56 * V_13 = & V_8 -> V_12 -> V_13 ;
int error ;
T_1 V_138 [ V_139 ] ;
if ( V_8 -> V_69 ) {
F_54 ( & V_8 -> V_65 ) ;
goto V_88;
}
error = V_8 -> V_14 -> V_140 ( V_8 -> V_12 , V_138 ) ;
if ( error )
goto V_88;
if ( V_138 [ V_141 ] != V_142 )
F_4 ( V_13 , L_33 ,
V_138 [ V_141 ] ) ;
else
F_49 ( V_8 , V_138 ) ;
V_88:
return V_143 ;
}
static int F_55 ( struct V_7 * V_8 )
{
struct V_56 * V_13 = & V_8 -> V_12 -> V_13 ;
struct V_104 * V_105 ;
unsigned int V_144 = F_44 ( V_8 -> V_44 , V_8 -> V_45 ) ;
unsigned int V_145 = F_45 ( V_8 -> V_44 , V_8 -> V_45 ) ;
int error ;
V_105 = F_56 ( V_13 ) ;
if ( ! V_105 )
return - V_82 ;
V_105 -> V_146 = L_34 ;
V_105 -> V_147 . V_148 = V_149 ;
V_105 -> V_147 . V_150 = V_151 ;
V_105 -> V_147 . V_152 = V_8 -> V_23 ;
F_57 ( V_105 , V_8 ) ;
error = F_58 ( V_105 , V_133 ,
V_153 | V_154 ) ;
if ( error ) {
F_4 ( V_13 , L_35 , error ) ;
return error ;
}
F_59 ( V_155 , V_105 -> V_156 ) ;
F_59 ( V_157 , V_105 -> V_158 ) ;
F_59 ( V_159 , V_105 -> V_158 ) ;
F_59 ( V_135 , V_105 -> V_160 ) ;
F_60 ( V_105 , V_161 , 0 , V_8 -> V_41 , 0 , 0 ) ;
F_60 ( V_105 , V_162 , 0 , V_8 -> V_42 , 0 , 0 ) ;
F_61 ( V_105 , V_161 , V_8 -> V_47 ) ;
F_61 ( V_105 , V_162 , V_8 -> V_48 ) ;
F_60 ( V_105 , V_163 , 0 , V_118 , 0 , 0 ) ;
F_60 ( V_105 , V_123 , 0 , V_164 , 0 , 0 ) ;
F_60 ( V_105 , V_136 , 0 , 1 , 0 , 0 ) ;
F_60 ( V_105 , V_120 , 0 , V_8 -> V_41 , 0 , 0 ) ;
F_60 ( V_105 , V_121 , 0 , V_8 -> V_42 , 0 , 0 ) ;
F_61 ( V_105 , V_120 , V_8 -> V_47 ) ;
F_61 ( V_105 , V_121 , V_8 -> V_48 ) ;
F_60 ( V_105 , V_122 , 0 ,
V_118 , 0 , 0 ) ;
F_60 ( V_105 , V_124 , 0 ,
V_164 * V_144 , 0 , 0 ) ;
F_60 ( V_105 , V_125 , 0 ,
V_164 * V_145 , 0 , 0 ) ;
V_8 -> V_105 = V_105 ;
return 0 ;
}
static void F_62 ( void * V_165 )
{
struct V_7 * V_8 = V_165 ;
F_7 ( V_8 -> V_11 ) ;
}
static void F_63 ( void * V_165 )
{
struct V_7 * V_8 = V_165 ;
F_64 ( & V_8 -> V_12 -> V_13 . V_166 , V_167 ) ;
}
static int F_65 ( struct V_17 * V_12 ,
const struct V_168 * V_137 )
{
const struct V_169 * V_170 ;
struct V_56 * V_13 = & V_12 -> V_13 ;
struct V_7 * V_8 ;
unsigned long V_171 ;
int error ;
if ( F_66 ( V_172 ) &&
F_67 ( V_12 -> V_173 , V_174 ) ) {
V_170 = & V_175 ;
} else if ( F_66 ( V_176 ) &&
F_67 ( V_12 -> V_173 ,
V_177 |
V_178 |
V_179 ) ) {
V_170 = & V_180 ;
} else {
F_4 ( V_13 , L_36 ) ;
return - V_66 ;
}
V_8 = F_68 ( & V_12 -> V_13 , sizeof( struct V_7 ) ,
V_80 ) ;
if ( ! V_8 )
return - V_82 ;
F_69 ( V_12 , V_8 ) ;
V_8 -> V_14 = V_170 ;
V_8 -> V_12 = V_12 ;
F_70 ( & V_8 -> V_65 ) ;
F_71 ( & V_8 -> V_85 ) ;
V_8 -> V_11 = F_72 ( & V_12 -> V_13 , L_37 ) ;
if ( F_73 ( V_8 -> V_11 ) ) {
error = F_74 ( V_8 -> V_11 ) ;
if ( error != - V_181 )
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
error = F_75 ( & V_12 -> V_13 ,
F_62 , V_8 ) ;
if ( error ) {
F_7 ( V_8 -> V_11 ) ;
F_4 ( & V_12 -> V_13 ,
L_40 ,
error ) ;
return error ;
}
error = F_10 ( V_8 ) ;
if ( error )
return error ;
error = F_11 ( V_8 ) ;
if ( error )
return error ;
error = F_14 ( V_8 ) ;
if ( error )
return error ;
F_16 ( & V_12 -> V_13 ,
L_41
L_42
L_43
L_44
L_45
L_46
L_47
L_48 ,
V_8 -> V_23 ,
V_8 -> V_25 ,
V_8 -> V_30 ,
V_8 -> V_1 ,
V_8 -> V_41 , V_8 -> V_42 ,
V_8 -> V_44 , V_8 -> V_45 ,
V_8 -> V_47 , V_8 -> V_48 ) ;
error = F_55 ( V_8 ) ;
if ( error )
return error ;
V_171 = V_12 -> V_13 . V_182 ? 0 : V_183 ;
error = F_76 ( & V_12 -> V_13 , V_12 -> V_68 ,
NULL , F_53 ,
V_171 | V_184 ,
V_12 -> V_146 , V_8 ) ;
if ( error ) {
F_4 ( & V_12 -> V_13 , L_49 , V_12 -> V_68 ) ;
return error ;
}
error = F_77 ( & V_12 -> V_13 . V_166 , V_167 ) ;
if ( error ) {
F_4 ( & V_12 -> V_13 , L_50 ,
error ) ;
return error ;
}
error = F_75 ( & V_12 -> V_13 ,
F_63 , V_8 ) ;
if ( error ) {
F_63 ( V_8 ) ;
F_4 ( & V_12 -> V_13 ,
L_51 ,
error ) ;
return error ;
}
error = F_78 ( V_8 -> V_105 ) ;
if ( error ) {
F_4 ( & V_12 -> V_13 , L_52 ,
error ) ;
return error ;
}
if ( ! V_12 -> V_13 . V_182 )
F_79 ( & V_12 -> V_13 , true ) ;
return 0 ;
}
static int T_6 F_80 ( struct V_56 * V_13 )
{
struct V_17 * V_12 = F_23 ( V_13 ) ;
struct V_7 * V_8 = F_24 ( V_12 ) ;
int V_185 ;
V_185 = F_35 ( & V_8 -> V_85 ) ;
if ( V_185 )
return V_185 ;
F_20 ( V_12 -> V_68 ) ;
if ( F_81 ( V_13 ) ) {
V_185 = F_8 ( V_8 ) ;
V_8 -> V_186 = ( F_82 ( V_12 -> V_68 ) == 0 ) ;
} else {
V_185 = F_6 ( V_8 ) ;
}
F_36 ( & V_8 -> V_85 ) ;
return V_185 ;
}
static int T_6 F_83 ( struct V_56 * V_13 )
{
struct V_17 * V_12 = F_23 ( V_13 ) ;
struct V_7 * V_8 = F_24 ( V_12 ) ;
int error ;
if ( F_81 ( V_13 ) && V_8 -> V_186 ) {
F_84 ( V_12 -> V_68 ) ;
V_8 -> V_186 = false ;
}
error = F_2 ( V_8 ) ;
if ( error ) {
F_4 ( V_13 , L_53 , error ) ;
goto V_187;
}
error = F_10 ( V_8 ) ;
if ( error )
F_4 ( V_13 , L_54 , error ) ;
V_187:
F_21 ( V_8 -> V_12 -> V_68 ) ;
return error ;
}
