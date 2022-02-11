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
L_2 ,
error ) ;
V_2 -> V_8 -> V_9 ( V_2 -> V_6 , true ) ;
break;
}
return 0 ;
}
F_4 ( 30 ) ;
} while ( -- V_3 > 0 );
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
F_3 ( & V_6 -> V_7 , L_3 , error ) ;
return error ;
}
V_2 -> V_13 |= V_14 ;
error = V_2 -> V_8 -> V_15 ( V_6 , V_2 -> V_13 ) ;
if ( error ) {
F_3 ( & V_6 -> V_7 ,
L_4 , error ) ;
return error ;
}
error = V_2 -> V_8 -> V_10 ( V_6 , false ) ;
if ( error ) {
F_3 ( & V_6 -> V_7 ,
L_5 , error ) ;
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
V_3 -- ;
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
return 0 ;
}
static unsigned int F_11 ( T_1 V_25 )
{
return ( ( int ) ( char ) V_25 * 10 + 790 ) * 10 / 254 ;
}
static int F_12 ( struct V_1 * V_2 )
{
unsigned int V_26 , V_27 ;
T_1 V_28 , V_29 ;
int error ;
error = V_2 -> V_8 -> V_30 ( V_2 -> V_6 , & V_2 -> V_31 , & V_2 -> V_32 ) ;
if ( error )
return error ;
error = V_2 -> V_8 -> V_33 ( V_2 -> V_6 , & V_26 , & V_27 ) ;
if ( error )
return error ;
V_2 -> V_34 = V_2 -> V_31 / V_26 ;
V_2 -> V_35 = V_2 -> V_32 / V_27 ;
error = V_2 -> V_8 -> V_36 ( V_2 -> V_6 , & V_28 , & V_29 ) ;
if ( error )
return error ;
V_2 -> V_37 = F_11 ( V_28 ) ;
V_2 -> V_38 = F_11 ( V_29 ) ;
return 0 ;
}
static int F_13 ( struct V_1 * V_2 ,
const T_1 * V_39 , T_2 V_40 , int V_41 )
{
int V_42 = V_4 ;
int error ;
do {
error = V_2 -> V_8 -> V_43 ( V_2 -> V_6 ,
V_39 , V_40 , V_41 ) ;
if ( ! error )
return 0 ;
F_14 ( & V_2 -> V_6 -> V_7 ,
L_6 , V_41 , error ) ;
} while ( -- V_42 > 0 );
return error ;
}
static int F_15 ( struct V_1 * V_2 ,
const struct V_44 * V_45 )
{
struct V_11 * V_6 = V_2 -> V_6 ;
struct V_46 * V_7 = & V_6 -> V_7 ;
int V_47 , V_48 ;
int error ;
T_2 V_49 ;
T_2 V_50 ;
T_2 V_51 = 0 , V_21 = 0 ;
error = V_2 -> V_8 -> V_52 ( V_6 ) ;
if ( error )
return error ;
V_49 = F_16 ( & V_45 -> V_2 [ V_53 * 2 ] ) ;
V_50 = ( V_49 * 2 ) / V_54 ;
for ( V_47 = V_50 ; V_47 < V_55 ; V_47 ++ ) {
T_2 V_40 = 0 ;
const T_1 * V_39 = & V_45 -> V_2 [ V_47 * V_54 ] ;
for ( V_48 = 0 ; V_48 < V_54 ; V_48 += 2 )
V_40 += ( ( V_39 [ V_48 + 1 ] << 8 ) | V_39 [ V_48 ] ) ;
error = F_13 ( V_2 , V_39 , V_40 , V_47 ) ;
if ( error ) {
F_3 ( V_7 , L_7 , V_47 , error ) ;
return error ;
}
V_51 += V_40 ;
}
F_4 ( 600 ) ;
error = V_2 -> V_8 -> V_56 ( V_6 , & V_2 -> V_57 ) ;
if ( error )
return error ;
error = V_2 -> V_8 -> V_20 ( V_6 , true , & V_21 ) ;
if ( error )
return error ;
if ( V_51 != V_21 ) {
F_3 ( V_7 , L_8 ,
V_51 , V_21 ) ;
return - V_58 ;
}
return 0 ;
}
static int F_17 ( struct V_1 * V_2 ,
const struct V_44 * V_45 )
{
struct V_11 * V_6 = V_2 -> V_6 ;
int V_59 ;
F_14 ( & V_6 -> V_7 , L_9 ) ;
F_18 ( V_6 -> V_60 ) ;
V_2 -> V_61 = true ;
V_59 = F_15 ( V_2 , V_45 ) ;
if ( V_59 ) {
F_3 ( & V_6 -> V_7 , L_10 , V_59 ) ;
V_2 -> V_8 -> V_62 ( V_6 ) ;
} else {
F_9 ( V_2 ) ;
F_10 ( V_2 ) ;
}
V_2 -> V_61 = false ;
F_19 ( V_6 -> V_60 ) ;
return V_59 ;
}
static T_3 F_20 ( struct V_46 * V_7 ,
struct V_63 * V_64 ,
char * V_65 )
{
struct V_11 * V_6 = F_21 ( V_7 ) ;
struct V_1 * V_2 = F_22 ( V_6 ) ;
return sprintf ( V_65 , L_11 , V_2 -> V_21 ) ;
}
static T_3 F_23 ( struct V_46 * V_7 ,
struct V_63 * V_64 ,
char * V_65 )
{
struct V_11 * V_6 = F_21 ( V_7 ) ;
struct V_1 * V_2 = F_22 ( V_6 ) ;
return sprintf ( V_65 , L_12 , V_2 -> V_17 ) ;
}
static T_3 F_24 ( struct V_46 * V_7 ,
struct V_63 * V_64 ,
char * V_65 )
{
struct V_11 * V_6 = F_21 ( V_7 ) ;
struct V_1 * V_2 = F_22 ( V_6 ) ;
return sprintf ( V_65 , L_12 , V_2 -> V_19 ) ;
}
static T_3 F_25 ( struct V_46 * V_7 ,
struct V_63 * V_64 ,
char * V_65 )
{
struct V_11 * V_6 = F_21 ( V_7 ) ;
struct V_1 * V_2 = F_22 ( V_6 ) ;
return sprintf ( V_65 , L_12 , V_2 -> V_23 ) ;
}
static T_3 F_26 ( struct V_46 * V_7 ,
struct V_63 * V_64 ,
char * V_65 )
{
struct V_11 * V_6 = F_21 ( V_7 ) ;
struct V_1 * V_2 = F_22 ( V_6 ) ;
return sprintf ( V_65 , L_12 , V_2 -> V_24 ) ;
}
static T_3 F_27 ( struct V_46 * V_7 ,
struct V_63 * V_64 ,
const char * V_65 , T_4 V_66 )
{
struct V_11 * V_6 = F_21 ( V_7 ) ;
struct V_1 * V_2 = F_22 ( V_6 ) ;
const struct V_44 * V_45 ;
int error ;
error = F_28 ( & V_45 , V_67 , V_7 ) ;
if ( error ) {
F_3 ( V_7 , L_13 ,
V_67 , error ) ;
return error ;
}
if ( V_45 -> V_68 != V_69 ) {
F_3 ( V_7 , L_14 ,
V_45 -> V_68 , V_69 ) ;
error = - V_70 ;
goto V_71;
}
error = F_29 ( & V_2 -> V_72 ) ;
if ( error )
goto V_71;
error = F_17 ( V_2 , V_45 ) ;
F_30 ( & V_2 -> V_72 ) ;
V_71:
F_31 ( V_45 ) ;
return error ? : V_66 ;
}
static T_3 F_32 ( struct V_46 * V_7 ,
struct V_63 * V_64 ,
const char * V_65 , T_4 V_66 )
{
struct V_11 * V_6 = F_21 ( V_7 ) ;
struct V_1 * V_2 = F_22 ( V_6 ) ;
int V_73 = 20 ;
int V_59 ;
int error ;
T_1 V_25 [ 3 ] ;
V_59 = F_29 ( & V_2 -> V_72 ) ;
if ( V_59 )
return V_59 ;
F_18 ( V_6 -> V_60 ) ;
V_2 -> V_13 |= V_74 ;
V_59 = V_2 -> V_8 -> V_15 ( V_6 , V_2 -> V_13 ) ;
if ( V_59 ) {
F_3 ( V_7 , L_15 ,
V_59 ) ;
goto V_75;
}
V_59 = V_2 -> V_8 -> V_76 ( V_6 ) ;
if ( V_59 ) {
F_3 ( V_7 , L_16 ,
V_59 ) ;
goto V_77;
}
V_25 [ 0 ] = 0xff ;
do {
F_4 ( 250 ) ;
V_59 = V_2 -> V_8 -> V_78 ( V_6 , V_25 ) ;
if ( V_59 )
F_3 ( V_7 , L_17 ,
V_59 ) ;
else if ( V_25 [ 0 ] == 0 )
break;
} while ( -- V_73 );
if ( V_73 == 0 ) {
F_3 ( V_7 , L_18 ) ;
V_59 = - V_79 ;
}
V_77:
V_2 -> V_13 &= ~ V_74 ;
error = V_2 -> V_8 -> V_15 ( V_2 -> V_6 , V_2 -> V_13 ) ;
if ( error ) {
F_3 ( V_7 , L_19 ,
error ) ;
if ( ! V_59 )
V_59 = error ;
}
V_75:
F_19 ( V_6 -> V_60 ) ;
F_30 ( & V_2 -> V_72 ) ;
return V_59 ? : V_66 ;
}
static T_3 F_33 ( struct V_46 * V_7 ,
struct V_63 * V_64 ,
char * V_65 )
{
struct V_11 * V_6 = F_21 ( V_7 ) ;
struct V_1 * V_2 = F_22 ( V_6 ) ;
int error ;
enum V_80 V_13 ;
error = F_29 ( & V_2 -> V_72 ) ;
if ( error )
return error ;
error = V_2 -> V_8 -> V_81 ( V_2 -> V_6 , & V_13 ) ;
F_30 ( & V_2 -> V_72 ) ;
if ( error )
return error ;
return sprintf ( V_65 , L_20 , ( int ) V_13 ) ;
}
static T_3 F_34 ( struct V_46 * V_7 , struct V_63 * V_64 ,
const char * V_65 , T_4 V_66 )
{
struct V_11 * V_6 = F_21 ( V_7 ) ;
struct V_1 * V_2 = F_22 ( V_6 ) ;
int error ;
int V_59 ;
V_59 = F_29 ( & V_2 -> V_72 ) ;
if ( V_59 )
return V_59 ;
F_18 ( V_6 -> V_60 ) ;
V_2 -> V_82 = false ;
V_2 -> V_13 |= V_74 ;
V_59 = V_2 -> V_8 -> V_15 ( V_2 -> V_6 , V_2 -> V_13 ) ;
if ( V_59 ) {
F_3 ( V_7 , L_21 ,
V_59 ) ;
goto V_75;
}
F_4 ( 250 ) ;
V_59 = V_2 -> V_8 -> V_83 ( V_2 -> V_6 , true ,
& V_2 -> V_84 ) ;
if ( V_59 ) {
F_3 ( V_7 , L_22 ,
V_59 ) ;
goto V_77;
}
V_59 = V_2 -> V_8 -> V_83 ( V_2 -> V_6 , false ,
& V_2 -> V_85 ) ;
if ( V_59 ) {
F_3 ( V_7 , L_23 ,
V_59 ) ;
goto V_77;
}
V_2 -> V_82 = true ;
V_77:
V_2 -> V_13 &= ~ V_74 ;
error = V_2 -> V_8 -> V_15 ( V_2 -> V_6 , V_2 -> V_13 ) ;
if ( error ) {
F_3 ( V_7 , L_24 ,
error ) ;
if ( ! V_59 )
V_59 = error ;
}
V_75:
F_19 ( V_6 -> V_60 ) ;
F_30 ( & V_2 -> V_72 ) ;
return V_59 ? : V_66 ;
}
static T_3 F_35 ( struct V_46 * V_7 ,
struct V_63 * V_64 , char * V_65 )
{
struct V_11 * V_6 = F_21 ( V_7 ) ;
struct V_1 * V_2 = F_22 ( V_6 ) ;
int V_59 ;
V_59 = F_29 ( & V_2 -> V_72 ) ;
if ( V_59 )
return V_59 ;
if ( ! V_2 -> V_82 ) {
V_59 = - V_86 ;
goto V_75;
}
V_59 = snprintf ( V_65 , V_87 , L_25 , V_2 -> V_85 ) ;
V_75:
F_30 ( & V_2 -> V_72 ) ;
return V_59 ;
}
static T_3 F_36 ( struct V_46 * V_7 ,
struct V_63 * V_64 , char * V_65 )
{
struct V_11 * V_6 = F_21 ( V_7 ) ;
struct V_1 * V_2 = F_22 ( V_6 ) ;
int V_59 ;
V_59 = F_29 ( & V_2 -> V_72 ) ;
if ( V_59 )
return V_59 ;
if ( ! V_2 -> V_82 ) {
V_59 = - V_86 ;
goto V_75;
}
V_59 = snprintf ( V_65 , V_87 , L_25 , V_2 -> V_84 ) ;
V_75:
F_30 ( & V_2 -> V_72 ) ;
return V_59 ;
}
static void F_37 ( struct V_1 * V_2 ,
int V_88 , bool V_89 ,
T_1 * V_90 )
{
struct V_91 * V_92 = V_2 -> V_92 ;
unsigned int V_93 , V_94 ;
unsigned int V_95 , V_96 , V_97 ;
unsigned int V_98 , V_99 , V_100 , V_101 , V_102 ;
if ( V_89 ) {
V_93 = ( ( V_90 [ 0 ] & 0xf0 ) << 4 ) |
V_90 [ 1 ] ;
V_94 = ( ( V_90 [ 0 ] & 0x0f ) << 8 ) |
V_90 [ 2 ] ;
V_96 = ( V_90 [ 3 ] & 0x0f ) ;
V_97 = ( V_90 [ 3 ] >> 4 ) ;
V_95 = V_90 [ 4 ] ;
if ( V_93 > V_2 -> V_31 || V_94 > V_2 -> V_32 ) {
F_14 ( V_92 -> V_7 . V_103 ,
L_26 ,
V_88 , V_93 , V_94 ,
V_2 -> V_31 , V_2 -> V_32 ) ;
return;
}
V_98 = V_96 * ( V_2 -> V_34 - V_104 ) ;
V_99 = V_97 * ( V_2 -> V_35 - V_104 ) ;
V_100 = F_38 ( V_98 , V_99 ) ;
V_101 = F_39 ( V_98 , V_99 ) ;
V_102 = V_95 + V_105 ;
if ( V_102 > V_106 )
V_102 = V_106 ;
F_40 ( V_92 , V_88 ) ;
F_41 ( V_92 , V_107 , true ) ;
F_42 ( V_92 , V_108 , V_93 ) ;
F_42 ( V_92 , V_109 , V_2 -> V_32 - V_94 ) ;
F_42 ( V_92 , V_110 , V_102 ) ;
F_42 ( V_92 , V_111 , V_96 ) ;
F_42 ( V_92 , V_112 , V_100 ) ;
F_42 ( V_92 , V_113 , V_101 ) ;
} else {
F_40 ( V_92 , V_88 ) ;
F_41 ( V_92 , V_107 , false ) ;
}
}
static void F_43 ( struct V_1 * V_2 , T_1 * V_114 )
{
struct V_91 * V_92 = V_2 -> V_92 ;
T_1 * V_90 = & V_114 [ V_115 ] ;
int V_47 ;
T_1 V_116 = V_114 [ V_117 ] ;
bool V_89 ;
for ( V_47 = 0 ; V_47 < V_118 ; V_47 ++ ) {
V_89 = V_116 & ( 1U << ( 3 + V_47 ) ) ;
F_37 ( V_2 , V_47 , V_89 , V_90 ) ;
if ( V_89 )
V_90 += V_119 ;
}
F_44 ( V_92 , V_120 , V_116 & 0x01 ) ;
F_45 ( V_92 , true ) ;
F_46 ( V_92 ) ;
}
static T_5 F_47 ( int V_60 , void * V_121 )
{
struct V_1 * V_2 = V_121 ;
struct V_46 * V_7 = & V_2 -> V_6 -> V_7 ;
int error ;
T_1 V_122 [ V_123 ] ;
if ( V_2 -> V_61 ) {
F_48 ( & V_2 -> V_57 ) ;
goto V_75;
}
error = V_2 -> V_8 -> V_124 ( V_2 -> V_6 , V_122 ) ;
if ( error )
goto V_75;
if ( V_122 [ V_125 ] != V_126 )
F_3 ( V_7 , L_27 ,
V_122 [ V_125 ] ) ;
else
F_43 ( V_2 , V_122 ) ;
V_75:
return V_127 ;
}
static int F_49 ( struct V_1 * V_2 )
{
struct V_46 * V_7 = & V_2 -> V_6 -> V_7 ;
struct V_91 * V_92 ;
unsigned int V_128 = F_38 ( V_2 -> V_34 , V_2 -> V_35 ) ;
unsigned int V_129 = F_39 ( V_2 -> V_34 , V_2 -> V_35 ) ;
int error ;
V_92 = F_50 ( V_7 ) ;
if ( ! V_92 )
return - V_130 ;
V_92 -> V_131 = L_28 ;
V_92 -> V_132 . V_133 = V_134 ;
F_51 ( V_92 , V_2 ) ;
error = F_52 ( V_92 , V_118 ,
V_135 | V_136 ) ;
if ( error ) {
F_3 ( V_7 , L_29 , error ) ;
return error ;
}
F_53 ( V_137 , V_92 -> V_138 ) ;
F_53 ( V_139 , V_92 -> V_140 ) ;
F_53 ( V_141 , V_92 -> V_140 ) ;
F_53 ( V_120 , V_92 -> V_142 ) ;
F_54 ( V_92 , V_143 , 0 , V_2 -> V_31 , 0 , 0 ) ;
F_54 ( V_92 , V_144 , 0 , V_2 -> V_32 , 0 , 0 ) ;
F_55 ( V_92 , V_143 , V_2 -> V_37 ) ;
F_55 ( V_92 , V_144 , V_2 -> V_38 ) ;
F_54 ( V_92 , V_145 , 0 , V_106 , 0 , 0 ) ;
F_54 ( V_92 , V_111 , 0 , V_146 , 0 , 0 ) ;
F_54 ( V_92 , V_108 , 0 , V_2 -> V_31 , 0 , 0 ) ;
F_54 ( V_92 , V_109 , 0 , V_2 -> V_32 , 0 , 0 ) ;
F_55 ( V_92 , V_108 , V_2 -> V_37 ) ;
F_55 ( V_92 , V_109 , V_2 -> V_38 ) ;
F_54 ( V_92 , V_110 , 0 ,
V_106 , 0 , 0 ) ;
F_54 ( V_92 , V_112 , 0 ,
V_146 * V_128 , 0 , 0 ) ;
F_54 ( V_92 , V_113 , 0 ,
V_146 * V_129 , 0 , 0 ) ;
V_2 -> V_92 = V_92 ;
return 0 ;
}
static void F_56 ( void * V_147 )
{
struct V_1 * V_2 = V_147 ;
F_6 ( V_2 -> V_5 ) ;
}
static void F_57 ( void * V_147 )
{
struct V_1 * V_2 = V_147 ;
F_58 ( & V_2 -> V_6 -> V_7 . V_148 , V_149 ) ;
}
static int F_59 ( struct V_11 * V_6 ,
const struct V_150 * V_121 )
{
const struct V_151 * V_152 ;
struct V_46 * V_7 = & V_6 -> V_7 ;
struct V_1 * V_2 ;
unsigned long V_153 ;
int error ;
if ( F_60 ( V_154 ) &&
F_61 ( V_6 -> V_155 , V_156 ) ) {
V_152 = & V_157 ;
} else if ( F_60 ( V_158 ) &&
F_61 ( V_6 -> V_155 ,
V_159 |
V_160 |
V_161 ) ) {
V_152 = & V_162 ;
} else {
F_3 ( V_7 , L_30 ) ;
return - V_58 ;
}
V_2 = F_62 ( & V_6 -> V_7 , sizeof( struct V_1 ) ,
V_163 ) ;
if ( ! V_2 )
return - V_130 ;
F_63 ( V_6 , V_2 ) ;
V_2 -> V_8 = V_152 ;
V_2 -> V_6 = V_6 ;
F_64 ( & V_2 -> V_57 ) ;
F_65 ( & V_2 -> V_72 ) ;
V_2 -> V_5 = F_66 ( & V_6 -> V_7 , L_31 ) ;
if ( F_67 ( V_2 -> V_5 ) ) {
error = F_68 ( V_2 -> V_5 ) ;
if ( error != - V_164 )
F_3 ( & V_6 -> V_7 ,
L_32 ,
error ) ;
return error ;
}
error = F_2 ( V_2 -> V_5 ) ;
if ( error ) {
F_3 ( & V_6 -> V_7 ,
L_1 , error ) ;
return error ;
}
error = F_69 ( & V_6 -> V_7 ,
F_56 , V_2 ) ;
if ( error ) {
F_6 ( V_2 -> V_5 ) ;
F_3 ( & V_6 -> V_7 ,
L_33 ,
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
L_34
L_35
L_36
L_37
L_38
L_39
L_40
L_41 ,
V_2 -> V_17 ,
V_2 -> V_19 ,
V_2 -> V_23 ,
V_2 -> V_24 ,
V_2 -> V_31 , V_2 -> V_32 ,
V_2 -> V_34 , V_2 -> V_35 ,
V_2 -> V_37 , V_2 -> V_38 ) ;
error = F_49 ( V_2 ) ;
if ( error )
return error ;
V_153 = V_6 -> V_7 . V_165 ? 0 : V_166 ;
error = F_70 ( & V_6 -> V_7 , V_6 -> V_60 ,
NULL , F_47 ,
V_153 | V_167 ,
V_6 -> V_131 , V_2 ) ;
if ( error ) {
F_3 ( & V_6 -> V_7 , L_42 , V_6 -> V_60 ) ;
return error ;
}
error = F_71 ( & V_6 -> V_7 . V_148 , V_149 ) ;
if ( error ) {
F_3 ( & V_6 -> V_7 , L_43 ,
error ) ;
return error ;
}
error = F_69 ( & V_6 -> V_7 ,
F_57 , V_2 ) ;
if ( error ) {
F_57 ( V_2 ) ;
F_3 ( & V_6 -> V_7 ,
L_44 ,
error ) ;
return error ;
}
error = F_72 ( V_2 -> V_92 ) ;
if ( error ) {
F_3 ( & V_6 -> V_7 , L_45 ,
error ) ;
return error ;
}
if ( ! V_6 -> V_7 . V_165 )
F_73 ( & V_6 -> V_7 , true ) ;
return 0 ;
}
static int T_6 F_74 ( struct V_46 * V_7 )
{
struct V_11 * V_6 = F_21 ( V_7 ) ;
struct V_1 * V_2 = F_22 ( V_6 ) ;
int V_168 ;
V_168 = F_29 ( & V_2 -> V_72 ) ;
if ( V_168 )
return V_168 ;
F_18 ( V_6 -> V_60 ) ;
if ( F_75 ( V_7 ) ) {
V_168 = F_7 ( V_2 ) ;
V_2 -> V_169 = ( F_76 ( V_6 -> V_60 ) == 0 ) ;
} else {
V_168 = F_5 ( V_2 ) ;
}
F_30 ( & V_2 -> V_72 ) ;
return V_168 ;
}
static int T_6 F_77 ( struct V_46 * V_7 )
{
struct V_11 * V_6 = F_21 ( V_7 ) ;
struct V_1 * V_2 = F_22 ( V_6 ) ;
int error ;
if ( F_75 ( V_7 ) && V_2 -> V_169 ) {
F_78 ( V_6 -> V_60 ) ;
V_2 -> V_169 = false ;
}
error = F_1 ( V_2 ) ;
if ( error )
F_3 ( V_7 , L_46 , error ) ;
error = F_9 ( V_2 ) ;
if ( error )
F_3 ( V_7 , L_47 , error ) ;
F_19 ( V_2 -> V_6 -> V_60 ) ;
return 0 ;
}
