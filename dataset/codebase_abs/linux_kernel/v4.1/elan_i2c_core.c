static int F_1 ( struct V_1 * V_2 )
{
int V_3 = V_4 ;
int error ;
error = F_2 ( V_2 -> V_5 ) ;
if ( error ) {
F_3 ( & V_2 -> V_6 -> V_7 ,
L_1 , error ) ;
return error ;
}
do {
error = V_2 -> V_8 -> V_9 ( V_2 -> V_6 , true ) ;
if ( error >= 0 )
return 0 ;
F_4 ( 30 ) ;
} while ( -- V_3 > 0 );
F_3 ( & V_2 -> V_6 -> V_7 , L_2 , error ) ;
return error ;
}
static int F_5 ( struct V_1 * V_2 )
{
int V_3 = V_4 ;
int error ;
do {
error = V_2 -> V_8 -> V_9 ( V_2 -> V_6 , false ) ;
if ( ! error ) {
error = F_6 ( V_2 -> V_5 ) ;
if ( error ) {
F_3 ( & V_2 -> V_6 -> V_7 ,
L_3 ,
error ) ;
V_2 -> V_8 -> V_9 ( V_2 -> V_6 , true ) ;
break;
}
return 0 ;
}
F_4 ( 30 ) ;
} while ( -- V_3 > 0 );
F_3 ( & V_2 -> V_6 -> V_7 , L_4 , error ) ;
return error ;
}
static int F_7 ( struct V_1 * V_2 )
{
int V_3 = V_4 ;
int error ;
do {
error = V_2 -> V_8 -> V_10 ( V_2 -> V_6 , true ) ;
if ( ! error )
return 0 ;
F_4 ( 30 ) ;
} while ( -- V_3 > 0 );
return error ;
}
static int F_8 ( struct V_1 * V_2 )
{
struct V_11 * V_6 = V_2 -> V_6 ;
int error ;
error = V_2 -> V_8 -> V_12 ( V_6 ) ;
if ( error ) {
F_3 ( & V_6 -> V_7 , L_5 , error ) ;
return error ;
}
V_2 -> V_13 |= V_14 ;
error = V_2 -> V_8 -> V_15 ( V_6 , V_2 -> V_13 ) ;
if ( error ) {
F_3 ( & V_6 -> V_7 ,
L_6 , error ) ;
return error ;
}
error = V_2 -> V_8 -> V_10 ( V_6 , false ) ;
if ( error ) {
F_3 ( & V_6 -> V_7 ,
L_7 , error ) ;
return error ;
}
return 0 ;
}
static int F_9 ( struct V_1 * V_2 )
{
int V_3 = V_4 ;
int error ;
do {
error = F_8 ( V_2 ) ;
if ( ! error )
return 0 ;
F_4 ( 30 ) ;
} while ( -- V_3 > 0 );
return error ;
}
static int F_10 ( struct V_1 * V_2 )
{
int error ;
error = V_2 -> V_8 -> V_16 ( V_2 -> V_6 , & V_2 -> V_17 ) ;
if ( error )
return error ;
error = V_2 -> V_8 -> V_18 ( V_2 -> V_6 , false , & V_2 -> V_19 ) ;
if ( error )
return error ;
error = V_2 -> V_8 -> V_20 ( V_2 -> V_6 , false ,
& V_2 -> V_21 ) ;
if ( error )
return error ;
error = V_2 -> V_8 -> V_22 ( V_2 -> V_6 , & V_2 -> V_23 ) ;
if ( error )
return error ;
error = V_2 -> V_8 -> V_18 ( V_2 -> V_6 , true , & V_2 -> V_24 ) ;
if ( error )
return error ;
error = V_2 -> V_8 -> V_25 ( V_2 -> V_6 ,
& V_2 -> V_26 ) ;
if ( error )
return error ;
return 0 ;
}
static unsigned int F_11 ( T_1 V_27 )
{
return ( ( int ) ( char ) V_27 * 10 + 790 ) * 10 / 254 ;
}
static int F_12 ( struct V_1 * V_2 )
{
unsigned int V_28 , V_29 ;
T_1 V_30 , V_31 ;
int error ;
error = V_2 -> V_8 -> V_32 ( V_2 -> V_6 , & V_2 -> V_33 , & V_2 -> V_34 ) ;
if ( error )
return error ;
error = V_2 -> V_8 -> V_35 ( V_2 -> V_6 , & V_28 , & V_29 ) ;
if ( error )
return error ;
V_2 -> V_36 = V_2 -> V_33 / V_28 ;
V_2 -> V_37 = V_2 -> V_34 / V_29 ;
error = V_2 -> V_8 -> V_38 ( V_2 -> V_6 , & V_30 , & V_31 ) ;
if ( error )
return error ;
V_2 -> V_39 = F_11 ( V_30 ) ;
V_2 -> V_40 = F_11 ( V_31 ) ;
return 0 ;
}
static int F_13 ( struct V_1 * V_2 ,
const T_1 * V_41 , T_2 V_42 , int V_43 )
{
int V_44 = V_4 ;
int error ;
do {
error = V_2 -> V_8 -> V_45 ( V_2 -> V_6 ,
V_41 , V_42 , V_43 ) ;
if ( ! error )
return 0 ;
F_14 ( & V_2 -> V_6 -> V_7 ,
L_8 , V_43 , error ) ;
} while ( -- V_44 > 0 );
return error ;
}
static int F_15 ( struct V_1 * V_2 ,
const struct V_46 * V_47 )
{
struct V_11 * V_6 = V_2 -> V_6 ;
struct V_48 * V_7 = & V_6 -> V_7 ;
int V_49 , V_50 ;
int error ;
T_2 V_51 ;
T_2 V_52 ;
T_2 V_53 = 0 , V_21 = 0 ;
error = V_2 -> V_8 -> V_54 ( V_6 ) ;
if ( error )
return error ;
V_51 = F_16 ( & V_47 -> V_2 [ V_55 * 2 ] ) ;
V_52 = ( V_51 * 2 ) / V_56 ;
for ( V_49 = V_52 ; V_49 < V_57 ; V_49 ++ ) {
T_2 V_42 = 0 ;
const T_1 * V_41 = & V_47 -> V_2 [ V_49 * V_56 ] ;
for ( V_50 = 0 ; V_50 < V_56 ; V_50 += 2 )
V_42 += ( ( V_41 [ V_50 + 1 ] << 8 ) | V_41 [ V_50 ] ) ;
error = F_13 ( V_2 , V_41 , V_42 , V_49 ) ;
if ( error ) {
F_3 ( V_7 , L_9 , V_49 , error ) ;
return error ;
}
V_53 += V_42 ;
}
F_4 ( 600 ) ;
error = V_2 -> V_8 -> V_58 ( V_6 , & V_2 -> V_59 ) ;
if ( error )
return error ;
error = V_2 -> V_8 -> V_20 ( V_6 , true , & V_21 ) ;
if ( error )
return error ;
if ( V_53 != V_21 ) {
F_3 ( V_7 , L_10 ,
V_53 , V_21 ) ;
return - V_60 ;
}
return 0 ;
}
static int F_17 ( struct V_1 * V_2 ,
const struct V_46 * V_47 )
{
struct V_11 * V_6 = V_2 -> V_6 ;
int V_61 ;
F_14 ( & V_6 -> V_7 , L_11 ) ;
F_18 ( V_6 -> V_62 ) ;
V_2 -> V_63 = true ;
V_61 = F_15 ( V_2 , V_47 ) ;
if ( V_61 ) {
F_3 ( & V_6 -> V_7 , L_12 , V_61 ) ;
V_2 -> V_8 -> V_64 ( V_6 ) ;
} else {
F_9 ( V_2 ) ;
F_10 ( V_2 ) ;
}
V_2 -> V_63 = false ;
F_19 ( V_6 -> V_62 ) ;
return V_61 ;
}
static T_3 F_20 ( struct V_48 * V_7 ,
struct V_65 * V_66 ,
char * V_67 )
{
struct V_11 * V_6 = F_21 ( V_7 ) ;
struct V_1 * V_2 = F_22 ( V_6 ) ;
return sprintf ( V_67 , L_13 , V_2 -> V_21 ) ;
}
static T_3 F_23 ( struct V_48 * V_7 ,
struct V_65 * V_66 ,
char * V_67 )
{
struct V_11 * V_6 = F_21 ( V_7 ) ;
struct V_1 * V_2 = F_22 ( V_6 ) ;
return sprintf ( V_67 , L_14 , V_2 -> V_17 ) ;
}
static T_3 F_24 ( struct V_48 * V_7 ,
struct V_65 * V_66 ,
char * V_67 )
{
struct V_11 * V_6 = F_21 ( V_7 ) ;
struct V_1 * V_2 = F_22 ( V_6 ) ;
return sprintf ( V_67 , L_14 , V_2 -> V_19 ) ;
}
static T_3 F_25 ( struct V_48 * V_7 ,
struct V_65 * V_66 ,
char * V_67 )
{
struct V_11 * V_6 = F_21 ( V_7 ) ;
struct V_1 * V_2 = F_22 ( V_6 ) ;
return sprintf ( V_67 , L_14 , V_2 -> V_23 ) ;
}
static T_3 F_26 ( struct V_48 * V_7 ,
struct V_65 * V_66 ,
char * V_67 )
{
struct V_11 * V_6 = F_21 ( V_7 ) ;
struct V_1 * V_2 = F_22 ( V_6 ) ;
return sprintf ( V_67 , L_14 , V_2 -> V_24 ) ;
}
static T_3 F_27 ( struct V_48 * V_7 ,
struct V_65 * V_66 ,
const char * V_67 , T_4 V_68 )
{
struct V_1 * V_2 = F_28 ( V_7 ) ;
const struct V_46 * V_47 ;
int error ;
const T_1 * V_69 ;
static const T_1 V_70 [] = { 0xAA , 0x55 , 0xCC , 0x33 , 0xFF , 0xFF } ;
error = F_29 ( & V_47 , V_71 , V_7 ) ;
if ( error ) {
F_3 ( V_7 , L_15 ,
V_71 , error ) ;
return error ;
}
V_69 = & V_47 -> V_2 [ V_72 ] ;
if ( memcmp ( V_69 , V_70 , sizeof( V_70 ) ) != 0 ) {
F_3 ( V_7 , L_16 ,
( int ) sizeof( V_70 ) , V_70 ,
( int ) sizeof( V_70 ) , V_69 ) ;
error = - V_73 ;
goto V_74;
}
error = F_30 ( & V_2 -> V_75 ) ;
if ( error )
goto V_74;
error = F_17 ( V_2 , V_47 ) ;
F_31 ( & V_2 -> V_75 ) ;
V_74:
F_32 ( V_47 ) ;
return error ? : V_68 ;
}
static T_3 F_33 ( struct V_48 * V_7 ,
struct V_65 * V_66 ,
const char * V_67 , T_4 V_68 )
{
struct V_11 * V_6 = F_21 ( V_7 ) ;
struct V_1 * V_2 = F_22 ( V_6 ) ;
int V_76 = 20 ;
int V_61 ;
int error ;
T_1 V_27 [ 3 ] ;
V_61 = F_30 ( & V_2 -> V_75 ) ;
if ( V_61 )
return V_61 ;
F_18 ( V_6 -> V_62 ) ;
V_2 -> V_13 |= V_77 ;
V_61 = V_2 -> V_8 -> V_15 ( V_6 , V_2 -> V_13 ) ;
if ( V_61 ) {
F_3 ( V_7 , L_17 ,
V_61 ) ;
goto V_78;
}
V_61 = V_2 -> V_8 -> V_79 ( V_6 ) ;
if ( V_61 ) {
F_3 ( V_7 , L_18 ,
V_61 ) ;
goto V_80;
}
V_27 [ 0 ] = 0xff ;
do {
F_4 ( 250 ) ;
V_61 = V_2 -> V_8 -> V_81 ( V_6 , V_27 ) ;
if ( V_61 )
F_3 ( V_7 , L_19 ,
V_61 ) ;
else if ( V_27 [ 0 ] == 0 )
break;
} while ( -- V_76 );
if ( V_76 == 0 ) {
F_3 ( V_7 , L_20 ) ;
V_61 = - V_82 ;
}
V_80:
V_2 -> V_13 &= ~ V_77 ;
error = V_2 -> V_8 -> V_15 ( V_2 -> V_6 , V_2 -> V_13 ) ;
if ( error ) {
F_3 ( V_7 , L_21 ,
error ) ;
if ( ! V_61 )
V_61 = error ;
}
V_78:
F_19 ( V_6 -> V_62 ) ;
F_31 ( & V_2 -> V_75 ) ;
return V_61 ? : V_68 ;
}
static T_3 F_34 ( struct V_48 * V_7 ,
struct V_65 * V_66 ,
char * V_67 )
{
struct V_11 * V_6 = F_21 ( V_7 ) ;
struct V_1 * V_2 = F_22 ( V_6 ) ;
int error ;
enum V_83 V_13 ;
error = F_30 ( & V_2 -> V_75 ) ;
if ( error )
return error ;
error = V_2 -> V_8 -> V_84 ( V_2 -> V_6 , & V_13 ) ;
F_31 ( & V_2 -> V_75 ) ;
if ( error )
return error ;
return sprintf ( V_67 , L_22 , ( int ) V_13 ) ;
}
static T_3 F_35 ( struct V_48 * V_7 , struct V_65 * V_66 ,
const char * V_67 , T_4 V_68 )
{
struct V_11 * V_6 = F_21 ( V_7 ) ;
struct V_1 * V_2 = F_22 ( V_6 ) ;
int error ;
int V_61 ;
V_61 = F_30 ( & V_2 -> V_75 ) ;
if ( V_61 )
return V_61 ;
F_18 ( V_6 -> V_62 ) ;
V_2 -> V_85 = false ;
V_2 -> V_13 |= V_77 ;
V_61 = V_2 -> V_8 -> V_15 ( V_2 -> V_6 , V_2 -> V_13 ) ;
if ( V_61 ) {
F_3 ( V_7 , L_23 ,
V_61 ) ;
goto V_78;
}
F_4 ( 250 ) ;
V_61 = V_2 -> V_8 -> V_86 ( V_2 -> V_6 , true ,
& V_2 -> V_87 ) ;
if ( V_61 ) {
F_3 ( V_7 , L_24 ,
V_61 ) ;
goto V_80;
}
V_61 = V_2 -> V_8 -> V_86 ( V_2 -> V_6 , false ,
& V_2 -> V_88 ) ;
if ( V_61 ) {
F_3 ( V_7 , L_25 ,
V_61 ) ;
goto V_80;
}
V_2 -> V_85 = true ;
V_80:
V_2 -> V_13 &= ~ V_77 ;
error = V_2 -> V_8 -> V_15 ( V_2 -> V_6 , V_2 -> V_13 ) ;
if ( error ) {
F_3 ( V_7 , L_26 ,
error ) ;
if ( ! V_61 )
V_61 = error ;
}
V_78:
F_19 ( V_6 -> V_62 ) ;
F_31 ( & V_2 -> V_75 ) ;
return V_61 ? : V_68 ;
}
static T_3 F_36 ( struct V_48 * V_7 ,
struct V_65 * V_66 , char * V_67 )
{
struct V_11 * V_6 = F_21 ( V_7 ) ;
struct V_1 * V_2 = F_22 ( V_6 ) ;
int V_61 ;
V_61 = F_30 ( & V_2 -> V_75 ) ;
if ( V_61 )
return V_61 ;
if ( ! V_2 -> V_85 ) {
V_61 = - V_89 ;
goto V_78;
}
V_61 = snprintf ( V_67 , V_90 , L_27 , V_2 -> V_88 ) ;
V_78:
F_31 ( & V_2 -> V_75 ) ;
return V_61 ;
}
static T_3 F_37 ( struct V_48 * V_7 ,
struct V_65 * V_66 , char * V_67 )
{
struct V_11 * V_6 = F_21 ( V_7 ) ;
struct V_1 * V_2 = F_22 ( V_6 ) ;
int V_61 ;
V_61 = F_30 ( & V_2 -> V_75 ) ;
if ( V_61 )
return V_61 ;
if ( ! V_2 -> V_85 ) {
V_61 = - V_89 ;
goto V_78;
}
V_61 = snprintf ( V_67 , V_90 , L_27 , V_2 -> V_87 ) ;
V_78:
F_31 ( & V_2 -> V_75 ) ;
return V_61 ;
}
static void F_38 ( struct V_1 * V_2 ,
int V_91 , bool V_92 ,
bool V_93 , T_1 * V_94 )
{
struct V_95 * V_96 = V_2 -> V_96 ;
unsigned int V_97 , V_98 ;
unsigned int V_99 , V_100 , V_101 ;
unsigned int V_102 , V_103 , V_104 , V_105 ;
unsigned int V_106 ;
if ( V_92 ) {
V_97 = ( ( V_94 [ 0 ] & 0xf0 ) << 4 ) |
V_94 [ 1 ] ;
V_98 = ( ( V_94 [ 0 ] & 0x0f ) << 8 ) |
V_94 [ 2 ] ;
V_100 = ( V_94 [ 3 ] & 0x0f ) ;
V_101 = ( V_94 [ 3 ] >> 4 ) ;
V_99 = V_94 [ 4 ] ;
if ( V_97 > V_2 -> V_33 || V_98 > V_2 -> V_34 ) {
F_14 ( V_96 -> V_7 . V_107 ,
L_28 ,
V_91 , V_97 , V_98 ,
V_2 -> V_33 , V_2 -> V_34 ) ;
return;
}
V_102 = V_100 * ( V_2 -> V_36 - V_108 ) ;
V_103 = V_101 * ( V_2 -> V_37 - V_108 ) ;
V_104 = F_39 ( V_102 , V_103 ) ;
V_105 = F_40 ( V_102 , V_103 ) ;
V_106 = V_99 + V_2 -> V_26 ;
if ( V_106 > V_109 )
V_106 = V_109 ;
F_41 ( V_96 , V_91 ) ;
F_42 ( V_96 , V_110 , true ) ;
F_43 ( V_96 , V_111 , V_97 ) ;
F_43 ( V_96 , V_112 , V_2 -> V_34 - V_98 ) ;
F_43 ( V_96 , V_113 , V_93 ) ;
F_43 ( V_96 , V_114 ,
V_93 ? 0 : V_106 ) ;
F_43 ( V_96 , V_115 , V_100 ) ;
F_43 ( V_96 , V_116 , V_104 ) ;
F_43 ( V_96 , V_117 , V_105 ) ;
} else {
F_41 ( V_96 , V_91 ) ;
F_42 ( V_96 , V_110 , false ) ;
}
}
static void F_44 ( struct V_1 * V_2 , T_1 * V_118 )
{
struct V_95 * V_96 = V_2 -> V_96 ;
T_1 * V_94 = & V_118 [ V_119 ] ;
int V_49 ;
T_1 V_120 = V_118 [ V_121 ] ;
T_1 V_122 = V_118 [ V_123 ] ;
bool V_92 , V_93 ;
V_93 = V_122 & 0x40 ;
for ( V_49 = 0 ; V_49 < V_124 ; V_49 ++ ) {
V_92 = V_120 & ( 1U << ( 3 + V_49 ) ) ;
F_38 ( V_2 , V_49 , V_92 , V_93 ,
V_94 ) ;
if ( V_92 )
V_94 += V_125 ;
}
F_45 ( V_96 , V_126 , V_120 & 0x01 ) ;
F_46 ( V_96 , true ) ;
F_47 ( V_96 ) ;
}
static T_5 F_48 ( int V_62 , void * V_127 )
{
struct V_1 * V_2 = V_127 ;
struct V_48 * V_7 = & V_2 -> V_6 -> V_7 ;
int error ;
T_1 V_128 [ V_129 ] ;
if ( V_2 -> V_63 ) {
F_49 ( & V_2 -> V_59 ) ;
goto V_78;
}
error = V_2 -> V_8 -> V_130 ( V_2 -> V_6 , V_128 ) ;
if ( error )
goto V_78;
if ( V_128 [ V_131 ] != V_132 )
F_3 ( V_7 , L_29 ,
V_128 [ V_131 ] ) ;
else
F_44 ( V_2 , V_128 ) ;
V_78:
return V_133 ;
}
static int F_50 ( struct V_1 * V_2 )
{
struct V_48 * V_7 = & V_2 -> V_6 -> V_7 ;
struct V_95 * V_96 ;
unsigned int V_134 = F_39 ( V_2 -> V_36 , V_2 -> V_37 ) ;
unsigned int V_135 = F_40 ( V_2 -> V_36 , V_2 -> V_37 ) ;
int error ;
V_96 = F_51 ( V_7 ) ;
if ( ! V_96 )
return - V_136 ;
V_96 -> V_137 = L_30 ;
V_96 -> V_138 . V_139 = V_140 ;
F_52 ( V_96 , V_2 ) ;
error = F_53 ( V_96 , V_124 ,
V_141 | V_142 ) ;
if ( error ) {
F_3 ( V_7 , L_31 , error ) ;
return error ;
}
F_54 ( V_143 , V_96 -> V_144 ) ;
F_54 ( V_145 , V_96 -> V_146 ) ;
F_54 ( V_147 , V_96 -> V_146 ) ;
F_54 ( V_126 , V_96 -> V_148 ) ;
F_55 ( V_96 , V_149 , 0 , V_2 -> V_33 , 0 , 0 ) ;
F_55 ( V_96 , V_150 , 0 , V_2 -> V_34 , 0 , 0 ) ;
F_56 ( V_96 , V_149 , V_2 -> V_39 ) ;
F_56 ( V_96 , V_150 , V_2 -> V_40 ) ;
F_55 ( V_96 , V_151 , 0 , V_109 , 0 , 0 ) ;
F_55 ( V_96 , V_115 , 0 , V_152 , 0 , 0 ) ;
F_55 ( V_96 , V_111 , 0 , V_2 -> V_33 , 0 , 0 ) ;
F_55 ( V_96 , V_112 , 0 , V_2 -> V_34 , 0 , 0 ) ;
F_56 ( V_96 , V_111 , V_2 -> V_39 ) ;
F_56 ( V_96 , V_112 , V_2 -> V_40 ) ;
F_55 ( V_96 , V_114 , 0 ,
V_109 , 0 , 0 ) ;
F_55 ( V_96 , V_116 , 0 ,
V_152 * V_134 , 0 , 0 ) ;
F_55 ( V_96 , V_117 , 0 ,
V_152 * V_135 , 0 , 0 ) ;
F_55 ( V_96 , V_113 , 0 , 1 , 0 , 0 ) ;
V_2 -> V_96 = V_96 ;
return 0 ;
}
static void F_57 ( void * V_153 )
{
struct V_1 * V_2 = V_153 ;
F_6 ( V_2 -> V_5 ) ;
}
static void F_58 ( void * V_153 )
{
struct V_1 * V_2 = V_153 ;
F_59 ( & V_2 -> V_6 -> V_7 . V_154 , V_155 ) ;
}
static int F_60 ( struct V_11 * V_6 ,
const struct V_156 * V_127 )
{
const struct V_157 * V_158 ;
struct V_48 * V_7 = & V_6 -> V_7 ;
struct V_1 * V_2 ;
unsigned long V_159 ;
int error ;
if ( F_61 ( V_160 ) &&
F_62 ( V_6 -> V_161 , V_162 ) ) {
V_158 = & V_163 ;
} else if ( F_61 ( V_164 ) &&
F_62 ( V_6 -> V_161 ,
V_165 |
V_166 |
V_167 ) ) {
V_158 = & V_168 ;
} else {
F_3 ( V_7 , L_32 ) ;
return - V_60 ;
}
V_2 = F_63 ( & V_6 -> V_7 , sizeof( struct V_1 ) ,
V_169 ) ;
if ( ! V_2 )
return - V_136 ;
F_64 ( V_6 , V_2 ) ;
V_2 -> V_8 = V_158 ;
V_2 -> V_6 = V_6 ;
F_65 ( & V_2 -> V_59 ) ;
F_66 ( & V_2 -> V_75 ) ;
V_2 -> V_5 = F_67 ( & V_6 -> V_7 , L_33 ) ;
if ( F_68 ( V_2 -> V_5 ) ) {
error = F_69 ( V_2 -> V_5 ) ;
if ( error != - V_170 )
F_3 ( & V_6 -> V_7 ,
L_34 ,
error ) ;
return error ;
}
error = F_2 ( V_2 -> V_5 ) ;
if ( error ) {
F_3 ( & V_6 -> V_7 ,
L_35 , error ) ;
return error ;
}
error = F_70 ( & V_6 -> V_7 ,
F_57 , V_2 ) ;
if ( error ) {
F_6 ( V_2 -> V_5 ) ;
F_3 ( & V_6 -> V_7 ,
L_36 ,
error ) ;
return error ;
}
error = F_9 ( V_2 ) ;
if ( error )
return error ;
error = F_10 ( V_2 ) ;
if ( error )
return error ;
error = F_12 ( V_2 ) ;
if ( error )
return error ;
F_14 ( & V_6 -> V_7 ,
L_37
L_38
L_39
L_40
L_41
L_42
L_43
L_44 ,
V_2 -> V_17 ,
V_2 -> V_19 ,
V_2 -> V_23 ,
V_2 -> V_24 ,
V_2 -> V_33 , V_2 -> V_34 ,
V_2 -> V_36 , V_2 -> V_37 ,
V_2 -> V_39 , V_2 -> V_40 ) ;
error = F_50 ( V_2 ) ;
if ( error )
return error ;
V_159 = V_6 -> V_7 . V_171 ? 0 : V_172 ;
error = F_71 ( & V_6 -> V_7 , V_6 -> V_62 ,
NULL , F_48 ,
V_159 | V_173 ,
V_6 -> V_137 , V_2 ) ;
if ( error ) {
F_3 ( & V_6 -> V_7 , L_45 , V_6 -> V_62 ) ;
return error ;
}
error = F_72 ( & V_6 -> V_7 . V_154 , V_155 ) ;
if ( error ) {
F_3 ( & V_6 -> V_7 , L_46 ,
error ) ;
return error ;
}
error = F_70 ( & V_6 -> V_7 ,
F_58 , V_2 ) ;
if ( error ) {
F_58 ( V_2 ) ;
F_3 ( & V_6 -> V_7 ,
L_47 ,
error ) ;
return error ;
}
error = F_73 ( V_2 -> V_96 ) ;
if ( error ) {
F_3 ( & V_6 -> V_7 , L_48 ,
error ) ;
return error ;
}
if ( ! V_6 -> V_7 . V_171 )
F_74 ( & V_6 -> V_7 , true ) ;
return 0 ;
}
static int T_6 F_75 ( struct V_48 * V_7 )
{
struct V_11 * V_6 = F_21 ( V_7 ) ;
struct V_1 * V_2 = F_22 ( V_6 ) ;
int V_174 ;
V_174 = F_30 ( & V_2 -> V_75 ) ;
if ( V_174 )
return V_174 ;
F_18 ( V_6 -> V_62 ) ;
if ( F_76 ( V_7 ) ) {
V_174 = F_7 ( V_2 ) ;
V_2 -> V_175 = ( F_77 ( V_6 -> V_62 ) == 0 ) ;
} else {
V_174 = F_5 ( V_2 ) ;
}
F_31 ( & V_2 -> V_75 ) ;
return V_174 ;
}
static int T_6 F_78 ( struct V_48 * V_7 )
{
struct V_11 * V_6 = F_21 ( V_7 ) ;
struct V_1 * V_2 = F_22 ( V_6 ) ;
int error ;
if ( F_76 ( V_7 ) && V_2 -> V_175 ) {
F_79 ( V_6 -> V_62 ) ;
V_2 -> V_175 = false ;
}
error = F_1 ( V_2 ) ;
if ( error ) {
F_3 ( V_7 , L_49 , error ) ;
goto V_176;
}
error = F_9 ( V_2 ) ;
if ( error )
F_3 ( V_7 , L_50 , error ) ;
V_176:
F_19 ( V_2 -> V_6 -> V_62 ) ;
return error ;
}
