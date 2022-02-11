static int F_1 ( struct V_1 * V_2 ,
const void * V_3 , T_1 V_4 )
{
int V_5 ;
V_5 = F_2 ( V_2 , V_3 , V_4 ) ;
if ( V_5 == V_4 )
return 0 ;
if ( V_5 >= 0 )
V_5 = - V_6 ;
F_3 ( & V_2 -> V_7 , L_1 ,
V_8 , ( int ) V_4 , V_3 , V_5 ) ;
return V_5 ;
}
static int F_4 ( struct V_1 * V_2 , void * V_3 , T_1 V_4 )
{
int V_5 ;
V_5 = F_5 ( V_2 , V_3 , V_4 ) ;
if ( V_5 == V_4 )
return 0 ;
if ( V_5 >= 0 )
V_5 = - V_6 ;
F_3 ( & V_2 -> V_7 , L_2 , V_8 , V_5 ) ;
return V_5 ;
}
static int F_6 ( struct V_1 * V_2 ,
const T_2 * V_9 , T_1 V_10 ,
T_2 * V_11 , T_1 V_12 )
{
struct V_13 V_14 [ 2 ] ;
int V_5 ;
T_2 V_15 ;
switch ( V_9 [ 0 ] ) {
case V_16 :
V_15 = V_17 ;
break;
case V_18 :
V_15 = V_19 ;
break;
default:
F_3 ( & V_2 -> V_7 , L_3 ,
V_8 , ( int ) V_10 , V_9 ) ;
return - V_20 ;
}
V_14 [ 0 ] . V_21 = V_2 -> V_21 ;
V_14 [ 0 ] . V_22 = V_2 -> V_22 & V_23 ;
V_14 [ 0 ] . V_24 = V_10 ;
V_14 [ 0 ] . V_25 = ( T_2 * ) V_9 ;
V_14 [ 1 ] . V_21 = V_2 -> V_21 ;
V_14 [ 1 ] . V_22 = V_2 -> V_22 & V_23 ;
V_14 [ 1 ] . V_22 |= V_26 ;
V_14 [ 1 ] . V_24 = V_12 ;
V_14 [ 1 ] . V_25 = V_11 ;
V_5 = F_7 ( V_2 -> V_27 , V_14 , F_8 ( V_14 ) ) ;
if ( V_5 < 0 )
return V_5 ;
if ( V_5 != F_8 ( V_14 ) || V_11 [ V_28 ] != V_15 )
return - V_6 ;
return 0 ;
}
static int F_9 ( struct V_29 * V_30 )
{
struct V_1 * V_2 = V_30 -> V_2 ;
int V_5 , error ;
static const T_2 V_31 [] = { 0x54 , 0xC0 , 0xE1 , 0x5A } ;
static const T_2 V_32 [] = { 0x54 , 0x29 , 0x00 , 0x01 } ;
static const T_2 V_33 [] = { V_34 , 0x66 , 0x66 , 0x66 } ;
F_10 ( V_2 -> V_35 ) ;
V_30 -> V_36 = V_37 ;
F_11 ( & V_30 -> V_38 ) ;
F_1 ( V_2 , V_31 , sizeof( V_31 ) ) ;
F_1 ( V_2 , V_32 , sizeof( V_32 ) ) ;
F_12 ( V_2 -> V_35 ) ;
V_5 = F_13 ( & V_30 -> V_38 ,
F_14 ( V_39 ) ) ;
V_30 -> V_36 = V_40 ;
if ( V_5 <= 0 ) {
error = V_5 < 0 ? V_5 : - V_41 ;
F_3 ( & V_2 -> V_7 ,
L_4 ,
error ) ;
return error ;
}
if ( memcmp ( V_33 , V_30 -> V_42 , sizeof( V_33 ) ) ) {
F_3 ( & V_2 -> V_7 ,
L_5 ,
( int ) sizeof( V_30 -> V_42 ) , V_30 -> V_42 ) ;
return - V_20 ;
}
return 0 ;
}
static int F_15 ( struct V_1 * V_2 )
{
const T_2 V_43 [] = { 0x77 , 0x77 , 0x77 , 0x77 } ;
int error ;
error = F_1 ( V_2 , V_43 ,
sizeof( V_43 ) ) ;
if ( error ) {
F_3 ( & V_2 -> V_7 , L_6 , error ) ;
return error ;
}
F_16 ( 30 ) ;
return 0 ;
}
static T_3 F_17 ( T_2 * V_25 )
{
return F_18 ( V_25 ) >> 4 ;
}
static int F_19 ( struct V_29 * V_30 )
{
struct V_1 * V_2 = V_30 -> V_2 ;
int error , V_44 ;
const T_2 V_9 [] = { V_16 , V_45 , 0x00 , 0x01 } ;
T_2 V_11 [ V_46 ] ;
for ( V_44 = 0 ; V_44 < V_47 ; V_44 ++ ) {
error = F_6 ( V_2 , V_9 , sizeof( V_9 ) ,
V_11 , sizeof( V_11 ) ) ;
if ( ! error ) {
V_30 -> V_48 = F_17 ( V_11 ) ;
if ( V_30 -> V_48 != 0xffff )
return 0 ;
}
F_20 ( & V_2 -> V_7 , L_7 ,
error , ( int ) sizeof( V_11 ) , V_11 ) ;
}
F_3 ( & V_2 -> V_7 ,
L_8 ) ;
return - V_20 ;
}
static int F_21 ( struct V_29 * V_30 )
{
struct V_1 * V_2 = V_30 -> V_2 ;
int error , V_44 ;
const T_2 V_9 [] = { V_16 , V_49 , 0x00 , 0x01 } ;
T_2 V_11 [ V_46 ] ;
for ( V_44 = 0 ; V_44 < V_47 ; V_44 ++ ) {
error = F_6 ( V_2 , V_9 , sizeof( V_9 ) ,
V_11 , sizeof( V_11 ) ) ;
if ( ! error ) {
V_30 -> V_50 = F_17 ( V_11 ) ;
if ( V_30 -> V_50 != 0x0000 &&
V_30 -> V_50 != 0xffff )
return 0 ;
}
F_20 ( & V_2 -> V_7 , L_9 ,
error , ( int ) sizeof( V_11 ) , V_11 ) ;
}
F_3 ( & V_2 -> V_7 ,
L_10 ) ;
return - V_20 ;
}
static int F_22 ( struct V_29 * V_30 )
{
struct V_1 * V_2 = V_30 -> V_2 ;
int error , V_44 ;
T_3 V_51 ;
const T_2 V_9 [] = { V_16 , V_52 , 0x00 , 0x01 } ;
T_2 V_11 [ V_46 ] ;
for ( V_44 = 0 ; V_44 < V_47 ; V_44 ++ ) {
error = F_6 ( V_2 , V_9 , sizeof( V_9 ) ,
V_11 , sizeof( V_11 ) ) ;
if ( ! error ) {
V_51 = F_17 ( V_11 ) ;
V_30 -> V_53 = V_51 >> 8 ;
V_30 -> V_54 = V_51 & 0xff ;
return 0 ;
}
F_20 ( & V_2 -> V_7 ,
L_11 ,
error , ( int ) sizeof( V_11 ) , V_11 ) ;
}
F_3 ( & V_2 -> V_7 , L_12 ) ;
return - V_20 ;
}
static int F_23 ( struct V_29 * V_30 )
{
struct V_1 * V_2 = V_30 -> V_2 ;
const T_2 V_9 [] = { V_16 , V_55 , 0x00 , 0x01 } ;
T_2 V_11 [ V_46 ] ;
T_3 V_51 ;
int error ;
error = F_6 ( V_2 , V_9 , sizeof( V_9 ) ,
V_11 , sizeof( V_11 ) ) ;
if ( error ) {
F_3 ( & V_2 -> V_7 ,
L_13 ,
error , ( int ) sizeof( V_11 ) , V_11 ) ;
return error ;
}
V_51 = F_17 ( V_11 ) ;
V_30 -> V_56 = V_51 >> 8 ;
V_30 -> V_57 = V_51 & 0xff ;
return 0 ;
}
static int F_24 ( struct V_29 * V_30 )
{
struct V_1 * V_2 = V_30 -> V_2 ;
int error ;
T_2 V_11 [ 17 ] ;
T_3 V_58 , V_59 , V_60 , V_61 , V_62 ;
const T_2 V_63 [] = {
V_18 , 0x00 , 0x00 , 0x00 , 0x00 , 0x00
} ;
const T_2 V_64 [] = {
V_16 , V_65 , 0x00 , 0x01
} ;
const T_2 V_66 [] = {
V_16 , V_67 , 0x00 , 0x01
} ;
const T_2 V_68 [] = {
V_16 , V_69 , 0x00 , 0x01
} ;
error = F_6 ( V_2 ,
V_63 ,
sizeof( V_63 ) ,
V_11 , sizeof( V_11 ) ) ;
if ( error ) {
F_3 ( & V_2 -> V_7 , L_14 ,
error ) ;
return error ;
}
V_60 = V_11 [ 2 ] + V_11 [ 6 ] + V_11 [ 10 ] ;
V_61 = V_11 [ 3 ] + V_11 [ 7 ] + V_11 [ 11 ] ;
error = F_6 ( V_2 ,
V_64 , sizeof( V_64 ) ,
V_11 , sizeof( V_11 ) ) ;
if ( error ) {
F_3 ( & V_2 -> V_7 , L_15 ,
error ) ;
return error ;
}
V_62 = V_11 [ 3 ] ;
error = F_6 ( V_2 ,
V_66 ,
sizeof( V_66 ) ,
V_11 , sizeof( V_11 ) ) ;
if ( error ) {
F_3 ( & V_2 -> V_7 , L_16 ,
error ) ;
return error ;
}
V_58 = F_25 ( & V_11 [ 2 ] ) ;
error = F_6 ( V_2 ,
V_68 ,
sizeof( V_68 ) ,
V_11 , sizeof( V_11 ) ) ;
if ( error ) {
F_3 ( & V_2 -> V_7 , L_17 ,
error ) ;
return error ;
}
V_59 = F_25 ( & V_11 [ 2 ] ) ;
F_20 ( & V_2 -> V_7 , L_18 , V_58 , V_59 ) ;
if ( V_60 == 0 || V_61 == 0 || V_62 == 0 ) {
F_26 ( & V_2 -> V_7 ,
L_19 ,
V_60 , V_61 , V_62 ) ;
} else {
V_30 -> V_70 = F_27 ( V_60 , V_62 ) ;
V_30 -> V_71 = F_28 ( V_30 -> V_70 , V_58 ) ;
V_30 -> V_72 = F_27 ( V_61 , V_62 ) ;
V_30 -> V_73 = F_28 ( V_30 -> V_72 , V_59 ) ;
}
return 0 ;
}
static int F_29 ( struct V_1 * V_2 )
{
const T_2 V_74 [] = { 0x4D , 0x61 , 0x69 , 0x6E } ;
int error ;
error = F_1 ( V_2 , V_74 , sizeof( V_74 ) ) ;
if ( error ) {
F_3 ( & V_2 -> V_7 , L_20 , error ) ;
return error ;
}
F_20 ( & V_2 -> V_7 , L_21 , V_2 -> V_21 ) ;
return 0 ;
}
static int F_30 ( struct V_29 * V_30 )
{
struct V_1 * V_2 = V_30 -> V_2 ;
int error , V_44 ;
const T_2 V_75 [] = { 0x55 , 0x55 , 0x55 , 0x55 } ;
const T_2 V_76 [] = { 0x55 , 0x55 , 0x80 , 0x80 } ;
T_2 V_25 [ V_46 ] ;
for ( V_44 = 0 ; V_44 < V_47 ; V_44 ++ ) {
error = F_15 ( V_2 ) ;
if ( error ) {
if ( V_44 < V_47 - 1 )
continue;
}
error = F_29 ( V_2 ) ;
if ( error ) {
if ( V_44 < V_47 - 1 )
continue;
}
F_16 ( V_77 ) ;
error = F_4 ( V_2 , V_25 , sizeof( V_25 ) ) ;
if ( error ) {
F_3 ( & V_2 -> V_7 ,
L_22 , error ) ;
} else if ( ! memcmp ( V_25 , V_75 , sizeof( V_75 ) ) ) {
V_30 -> V_78 = V_79 ;
break;
} else if ( ! memcmp ( V_25 , V_76 , sizeof( V_76 ) ) ) {
error = - V_6 ;
break;
} else {
error = - V_20 ;
F_3 ( & V_2 -> V_7 ,
L_23 ,
( int ) sizeof( V_25 ) , V_25 ) ;
}
}
if ( ! error )
error = F_19 ( V_30 ) ;
if ( ! error )
error = F_21 ( V_30 ) ;
if ( error ) {
V_30 -> V_78 = V_80 ;
} else {
F_22 ( V_30 ) ;
F_23 ( V_30 ) ;
F_24 ( V_30 ) ;
}
return 0 ;
}
static int F_31 ( struct V_1 * V_2 ,
const void * V_81 )
{
const T_2 V_82 [] = { 0xaa , 0xaa } ;
T_2 V_25 [ 2 ] ;
int V_83 ;
int error ;
for ( V_83 = 0 ; V_83 < V_84 ; V_83 ++ ) {
error = F_1 ( V_2 , V_81 , V_85 ) ;
if ( error ) {
F_3 ( & V_2 -> V_7 ,
L_24 , error ) ;
continue;
}
error = F_4 ( V_2 , V_25 , 2 ) ;
if ( error ) {
F_3 ( & V_2 -> V_7 ,
L_25 , error ) ;
return error ;
}
if ( ! memcmp ( V_25 , V_82 , sizeof( V_82 ) ) )
return 0 ;
error = - V_6 ;
F_3 ( & V_2 -> V_7 ,
L_26 ,
V_25 [ 0 ] , V_25 [ 1 ] ) ;
}
return error ;
}
static int F_32 ( struct V_1 * V_2 ,
const struct V_86 * V_87 ,
bool V_88 )
{
const T_2 V_89 [] = { 0x45 , 0x49 , 0x41 , 0x50 } ;
const T_2 V_90 [] = { 0x54 , 0x00 , 0x12 , 0x34 } ;
const T_2 V_91 [] = { 0x55 , 0xaa , 0x33 , 0xcc } ;
const T_2 V_92 [] = { 0x54 , 0x2c , 0x01 , 0x01 } ;
T_2 V_25 [ V_46 ] ;
T_3 V_93 ;
int V_81 , V_94 ;
int error ;
if ( V_88 ) {
F_20 ( & V_2 -> V_7 , L_27 ) ;
error = F_1 ( V_2 , V_90 , sizeof( V_90 ) ) ;
} else {
F_20 ( & V_2 -> V_7 , L_28 ) ;
error = F_1 ( V_2 , V_92 , sizeof( V_92 ) ) ;
if ( error )
F_3 ( & V_2 -> V_7 , L_29 , error ) ;
F_16 ( 60 ) ;
F_15 ( V_2 ) ;
F_16 ( 20 ) ;
error = F_1 ( V_2 , V_89 , sizeof( V_89 ) ) ;
}
if ( error ) {
F_3 ( & V_2 -> V_7 , L_30 , error ) ;
return error ;
}
F_16 ( 20 ) ;
error = F_4 ( V_2 , V_25 , 4 ) ;
if ( error ) {
F_3 ( & V_2 -> V_7 ,
L_31 ,
error ) ;
return error ;
}
if ( memcmp ( V_25 , V_91 , sizeof( V_91 ) ) ) {
F_3 ( & V_2 -> V_7 ,
L_32 ,
( int ) sizeof( V_25 ) , V_25 , ( int ) sizeof( V_91 ) , V_91 ) ;
return - V_6 ;
}
F_33 ( & V_2 -> V_7 , L_33 ) ;
V_93 = V_2 -> V_21 ;
error = F_1 ( V_2 , & V_93 , 1 ) ;
if ( error ) {
F_3 ( & V_2 -> V_7 , L_34 ,
error ) ;
return error ;
}
error = F_1 ( V_2 , V_87 -> V_3 , V_85 ) ;
if ( error ) {
F_3 ( & V_2 -> V_7 , L_35 ,
error ) ;
return error ;
}
error = F_4 ( V_2 , V_25 , 2 ) ;
if ( error ) {
F_3 ( & V_2 -> V_7 ,
L_36 ,
error ) ;
return error ;
}
V_94 = V_87 -> V_4 / V_85 ;
F_20 ( & V_2 -> V_7 , L_37 , V_94 ) ;
for ( V_81 = 0 ; V_81 < V_94 ; V_81 ++ ) {
error = F_31 ( V_2 ,
V_87 -> V_3 + V_81 * V_85 ) ;
if ( error ) {
F_3 ( & V_2 -> V_7 ,
L_38 ,
V_81 , error ) ;
return error ;
}
}
F_16 ( 300 ) ;
F_33 ( & V_2 -> V_7 , L_39 ) ;
return 0 ;
}
static int F_34 ( struct V_29 * V_30 )
{
struct V_1 * V_2 = V_30 -> V_2 ;
const struct V_86 * V_87 ;
char * V_95 ;
int error ;
V_95 = F_35 ( V_96 , L_40 , V_30 -> V_48 ) ;
if ( ! V_95 )
return - V_97 ;
F_33 ( & V_2 -> V_7 , L_41 , V_95 ) ;
error = F_36 ( & V_87 , V_95 , & V_2 -> V_7 ) ;
F_37 ( V_95 ) ;
if ( error ) {
F_3 ( & V_2 -> V_7 , L_42 ,
error ) ;
return error ;
}
if ( V_87 -> V_4 % V_85 ) {
F_3 ( & V_2 -> V_7 , L_43 ,
V_87 -> V_4 ) ;
error = - V_20 ;
goto V_98;
}
F_10 ( V_2 -> V_35 ) ;
error = F_32 ( V_2 , V_87 ,
V_30 -> V_78 == V_80 ) ;
if ( error ) {
F_3 ( & V_2 -> V_7 , L_44 , error ) ;
V_30 -> V_78 = V_80 ;
goto V_99;
}
error = F_30 ( V_30 ) ;
if ( error ) {
F_3 ( & V_2 -> V_7 ,
L_45 ,
error ) ;
V_30 -> V_78 = V_80 ;
goto V_99;
}
V_30 -> V_78 = V_79 ;
V_99:
V_30 -> V_36 = V_40 ;
F_12 ( V_2 -> V_35 ) ;
F_16 ( 100 ) ;
if ( ! error )
F_9 ( V_30 ) ;
V_98:
F_38 ( V_87 ) ;
return error ;
}
static void F_39 ( struct V_29 * V_30 , T_2 * V_25 )
{
struct V_100 * V_101 = V_30 -> V_101 ;
unsigned int V_102 ;
T_3 V_103 ;
int V_104 ;
V_102 = V_25 [ V_105 + 1 ] & 0x0f ;
V_103 = ( ( V_25 [ V_105 + 1 ] & 0x30 ) << 4 ) |
V_25 [ V_105 ] ;
F_20 ( & V_30 -> V_2 -> V_7 ,
L_46 , V_102 , V_103 ) ;
for ( V_104 = 0 ; V_104 < V_106 && V_102 ; V_104 ++ ) {
if ( V_103 & 1 ) {
unsigned int V_107 , V_108 , V_109 , V_110 ;
T_2 * V_111 ;
V_111 = & V_25 [ V_112 + V_104 * 3 ] ;
V_107 = ( ( ( T_3 ) V_111 [ 0 ] & 0xf0 ) << 4 ) | V_111 [ 1 ] ;
V_108 = ( ( ( T_3 ) V_111 [ 0 ] & 0x0f ) << 8 ) | V_111 [ 2 ] ;
V_109 = V_25 [ V_113 + V_104 ] ;
V_110 = V_25 [ V_114 + V_104 ] ;
F_20 ( & V_30 -> V_2 -> V_7 , L_47 ,
V_104 , V_107 , V_108 , V_109 , V_110 ) ;
F_40 ( V_101 , V_104 ) ;
F_41 ( V_101 , V_115 , true ) ;
F_42 ( V_101 , V_116 , V_117 , V_107 ) ;
F_42 ( V_101 , V_116 , V_118 , V_108 ) ;
F_42 ( V_101 , V_116 , V_119 , V_109 ) ;
F_42 ( V_101 , V_116 , V_120 , V_110 ) ;
V_102 -- ;
}
V_103 >>= 1 ;
}
F_43 ( V_101 ) ;
F_44 ( V_101 ) ;
}
static T_2 F_45 ( T_2 * V_25 )
{
T_2 V_121 = 0 ;
T_2 V_104 ;
for ( V_104 = 0 ; V_104 < V_122 ; V_104 ++ )
V_121 += V_25 [ V_104 ] ;
return V_121 ;
}
static void F_46 ( struct V_29 * V_30 , T_2 * V_25 )
{
T_2 V_121 = F_45 ( V_25 ) ;
if ( F_47 ( V_25 [ V_122 ] != V_121 ) )
F_26 ( & V_30 -> V_2 -> V_7 ,
L_48 ,
V_8 , V_25 [ V_123 ] ,
V_121 , V_25 [ V_122 ] ) ;
else if ( F_47 ( V_25 [ V_123 ] != V_124 ) )
F_26 ( & V_30 -> V_2 -> V_7 ,
L_49 ,
V_8 , V_25 [ V_123 ] ) ;
else
F_39 ( V_30 , V_25 ) ;
}
static T_4 F_48 ( int V_35 , void * V_125 )
{
const T_2 V_126 [] = { 0x64 , 0x64 , 0x64 , 0x64 } ;
struct V_29 * V_30 = V_125 ;
struct V_1 * V_2 = V_30 -> V_2 ;
int V_127 , V_128 ;
int V_104 ;
int V_24 ;
V_24 = F_5 ( V_2 , V_30 -> V_25 , sizeof( V_30 -> V_25 ) ) ;
if ( V_24 < 0 ) {
F_3 ( & V_2 -> V_7 , L_50 ,
V_8 , V_24 ) ;
goto V_98;
}
F_20 ( & V_2 -> V_7 , L_51 ,
V_8 , V_46 , V_30 -> V_25 ) ;
switch ( V_30 -> V_36 ) {
case V_37 :
if ( V_30 -> V_25 [ V_28 ] == V_34 ) {
memcpy ( V_30 -> V_42 , V_30 -> V_25 , sizeof( V_30 -> V_42 ) ) ;
F_49 ( & V_30 -> V_38 ) ;
V_30 -> V_36 = V_40 ;
}
break;
case V_129 :
if ( V_30 -> V_25 [ V_28 ] != V_130 )
break;
V_30 -> V_36 = V_40 ;
case V_40 :
switch ( V_30 -> V_25 [ V_28 ] ) {
case V_131 :
case V_17 :
case V_34 :
break;
case V_132 :
if ( memcmp ( V_30 -> V_25 , V_126 , sizeof( V_126 ) ) ) {
F_3 ( & V_2 -> V_7 ,
L_52 ,
V_46 , V_30 -> V_25 ) ;
} else {
V_30 -> V_36 = V_129 ;
F_50 ( 30 ) ;
}
break;
case V_133 :
F_46 ( V_30 , & V_30 -> V_25 [ V_46 ] ) ;
break;
case V_130 :
V_127 = V_30 -> V_25 [ V_134 ] ;
if ( V_127 > 3 ) {
F_3 ( & V_2 -> V_7 ,
L_53 ,
V_46 , V_30 -> V_25 ) ;
break;
}
V_128 = V_30 -> V_25 [ V_135 ] / V_127 ;
if ( V_128 != V_136 ) {
F_3 ( & V_2 -> V_7 ,
L_54 ,
V_46 , V_30 -> V_25 ) ;
break;
}
for ( V_104 = 0 ; V_104 < V_127 ; V_104 ++ ) {
T_2 * V_25 = V_30 -> V_25 + V_46 +
V_104 * V_136 ;
F_46 ( V_30 , V_25 ) ;
}
break;
default:
F_3 ( & V_2 -> V_7 , L_55 ,
V_46 , V_30 -> V_25 ) ;
break;
}
break;
}
V_98:
return V_137 ;
}
static T_5 F_51 ( struct V_138 * V_7 ,
struct V_139 * V_140 ,
const char * V_25 , T_1 V_141 )
{
struct V_1 * V_2 = F_52 ( V_7 ) ;
struct V_29 * V_30 = F_53 ( V_2 ) ;
int error ;
error = F_54 ( & V_30 -> V_142 ) ;
if ( error )
return error ;
error = F_9 ( V_30 ) ;
F_55 ( & V_30 -> V_142 ) ;
return error ? : V_141 ;
}
static T_5 F_56 ( struct V_138 * V_7 ,
struct V_139 * V_140 ,
const char * V_25 , T_1 V_141 )
{
struct V_1 * V_2 = F_52 ( V_7 ) ;
struct V_29 * V_30 = F_53 ( V_2 ) ;
int error ;
error = F_54 ( & V_30 -> V_142 ) ;
if ( error )
return error ;
error = F_34 ( V_30 ) ;
F_20 ( V_7 , L_56 , error ) ;
F_55 ( & V_30 -> V_142 ) ;
return error ? : V_141 ;
}
static T_5 F_57 ( struct V_138 * V_7 ,
struct V_139 * V_140 , char * V_25 )
{
struct V_1 * V_2 = F_52 ( V_7 ) ;
struct V_29 * V_30 = F_53 ( V_2 ) ;
return sprintf ( V_25 , L_57 ,
V_30 -> V_78 == V_79 ?
L_58 : L_59 ) ;
}
static T_5 F_58 ( struct V_138 * V_7 ,
struct V_139 * V_143 ,
char * V_25 )
{
struct V_1 * V_2 = F_52 ( V_7 ) ;
struct V_29 * V_30 = F_53 ( V_2 ) ;
struct V_144 * V_140 =
F_59 ( V_143 , struct V_144 , V_143 ) ;
T_2 * V_145 = ( T_2 * ) ( ( char * ) V_30 + V_140 -> V_146 ) ;
unsigned int V_147 ;
unsigned int V_148 ;
if ( V_140 -> V_149 == 1 ) {
V_148 = * V_145 ;
V_147 = 2 ;
} else {
V_148 = * ( T_3 * ) V_145 ;
V_147 = 4 ;
}
return sprintf ( V_25 , L_60 , V_147 , V_148 ) ;
}
static void F_60 ( void * V_150 )
{
struct V_29 * V_30 = V_150 ;
F_61 ( & V_30 -> V_2 -> V_7 . V_151 , & V_152 ) ;
}
static int F_62 ( struct V_29 * V_30 )
{
int error ;
if ( F_63 ( V_30 -> V_153 ) )
return 0 ;
F_64 ( V_30 -> V_153 , 1 ) ;
error = F_65 ( V_30 -> V_154 ) ;
if ( error ) {
F_3 ( & V_30 -> V_2 -> V_7 ,
L_61 ,
error ) ;
goto V_155;
}
error = F_65 ( V_30 -> V_156 ) ;
if ( error ) {
F_3 ( & V_30 -> V_2 -> V_7 ,
L_62 ,
error ) ;
F_66 ( V_30 -> V_154 ) ;
goto V_155;
}
F_50 ( V_157 ) ;
V_155:
F_64 ( V_30 -> V_153 , 0 ) ;
if ( error )
return error ;
F_16 ( V_158 ) ;
return 0 ;
}
static void F_67 ( void * V_150 )
{
struct V_29 * V_30 = V_150 ;
if ( ! F_63 ( V_30 -> V_153 ) ) {
F_64 ( V_30 -> V_153 , 1 ) ;
F_66 ( V_30 -> V_156 ) ;
F_66 ( V_30 -> V_154 ) ;
}
}
static int F_68 ( struct V_1 * V_2 ,
const struct V_159 * V_160 )
{
union V_161 V_162 ;
struct V_29 * V_30 ;
unsigned long V_163 ;
int error ;
if ( ! F_69 ( V_2 -> V_27 , V_164 ) ) {
F_3 ( & V_2 -> V_7 ,
L_63 , V_165 ) ;
return - V_166 ;
}
V_30 = F_70 ( & V_2 -> V_7 , sizeof( struct V_29 ) , V_96 ) ;
if ( ! V_30 )
return - V_97 ;
F_71 ( & V_30 -> V_142 ) ;
F_72 ( & V_30 -> V_38 ) ;
V_30 -> V_2 = V_2 ;
F_73 ( V_2 , V_30 ) ;
V_30 -> V_154 = F_74 ( & V_2 -> V_7 , L_64 ) ;
if ( F_75 ( V_30 -> V_154 ) ) {
error = F_76 ( V_30 -> V_154 ) ;
if ( error != - V_167 )
F_3 ( & V_2 -> V_7 ,
L_65 ,
error ) ;
return error ;
}
V_30 -> V_156 = F_74 ( & V_2 -> V_7 , L_66 ) ;
if ( F_75 ( V_30 -> V_156 ) ) {
error = F_76 ( V_30 -> V_156 ) ;
if ( error != - V_167 )
F_3 ( & V_2 -> V_7 ,
L_67 ,
error ) ;
return error ;
}
V_30 -> V_153 = F_77 ( & V_2 -> V_7 , L_68 , V_168 ) ;
if ( F_75 ( V_30 -> V_153 ) ) {
error = F_76 ( V_30 -> V_153 ) ;
if ( error == - V_167 )
return error ;
if ( error != - V_169 && error != - V_170 ) {
F_3 ( & V_2 -> V_7 ,
L_69 ,
error ) ;
return error ;
}
V_30 -> V_171 = true ;
}
error = F_62 ( V_30 ) ;
if ( error )
return error ;
error = F_78 ( & V_2 -> V_7 , F_67 , V_30 ) ;
if ( error ) {
F_3 ( & V_2 -> V_7 ,
L_70 , error ) ;
F_67 ( V_30 ) ;
return error ;
}
if ( F_79 ( V_2 -> V_27 , V_2 -> V_21 , 0 ,
V_172 , 0 , V_173 , & V_162 ) < 0 ) {
F_3 ( & V_2 -> V_7 , L_71 ) ;
return - V_166 ;
}
error = F_30 ( V_30 ) ;
if ( error ) {
F_3 ( & V_2 -> V_7 , L_72 , error ) ;
return error ;
}
V_30 -> V_101 = F_80 ( & V_2 -> V_7 ) ;
if ( ! V_30 -> V_101 ) {
F_3 ( & V_2 -> V_7 , L_73 ) ;
return - V_97 ;
}
V_30 -> V_101 -> V_174 = L_74 ;
V_30 -> V_101 -> V_160 . V_175 = V_176 ;
F_81 ( V_177 , V_30 -> V_101 -> V_178 ) ;
F_81 ( V_116 , V_30 -> V_101 -> V_179 ) ;
F_81 ( V_180 , V_30 -> V_101 -> V_179 ) ;
F_82 ( V_30 -> V_101 , V_181 , 0 , V_30 -> V_70 , 0 , 0 ) ;
F_82 ( V_30 -> V_101 , V_182 , 0 , V_30 -> V_72 , 0 , 0 ) ;
F_82 ( V_30 -> V_101 , V_183 , 0 , 255 , 0 , 0 ) ;
F_83 ( V_30 -> V_101 , V_181 , V_30 -> V_71 ) ;
F_83 ( V_30 -> V_101 , V_182 , V_30 -> V_73 ) ;
error = F_84 ( V_30 -> V_101 , V_106 ,
V_184 | V_185 ) ;
if ( error ) {
F_3 ( & V_2 -> V_7 ,
L_75 , error ) ;
return error ;
}
F_82 ( V_30 -> V_101 , V_117 , 0 , V_30 -> V_70 , 0 , 0 ) ;
F_82 ( V_30 -> V_101 , V_118 , 0 , V_30 -> V_72 , 0 , 0 ) ;
F_82 ( V_30 -> V_101 , V_120 , 0 , 255 , 0 , 0 ) ;
F_82 ( V_30 -> V_101 , V_119 , 0 , 255 , 0 , 0 ) ;
F_83 ( V_30 -> V_101 , V_117 , V_30 -> V_71 ) ;
F_83 ( V_30 -> V_101 , V_118 , V_30 -> V_73 ) ;
F_85 ( V_30 -> V_101 , V_30 ) ;
error = F_86 ( V_30 -> V_101 ) ;
if ( error ) {
F_3 ( & V_2 -> V_7 ,
L_76 , error ) ;
return error ;
}
V_163 = V_2 -> V_7 . V_186 ? 0 : V_187 ;
error = F_87 ( & V_2 -> V_7 , V_2 -> V_35 ,
NULL , F_48 ,
V_163 | V_188 ,
V_2 -> V_174 , V_30 ) ;
if ( error ) {
F_3 ( & V_2 -> V_7 , L_77 ) ;
return error ;
}
if ( ! V_2 -> V_7 . V_186 )
F_88 ( & V_2 -> V_7 , true ) ;
error = F_89 ( & V_2 -> V_7 . V_151 , & V_152 ) ;
if ( error ) {
F_3 ( & V_2 -> V_7 , L_78 ,
error ) ;
return error ;
}
error = F_78 ( & V_2 -> V_7 ,
F_60 , V_30 ) ;
if ( error ) {
F_60 ( V_30 ) ;
F_3 ( & V_2 -> V_7 ,
L_79 ,
error ) ;
return error ;
}
return 0 ;
}
static int T_6 F_90 ( struct V_138 * V_7 )
{
struct V_1 * V_2 = F_52 ( V_7 ) ;
struct V_29 * V_30 = F_53 ( V_2 ) ;
const T_2 V_189 [] = { 0x54 , 0x50 , 0x00 , 0x01 } ;
int V_44 ;
int error ;
if ( V_30 -> V_78 != V_79 )
return - V_190 ;
F_10 ( V_2 -> V_35 ) ;
if ( F_91 ( V_7 ) ) {
V_30 -> V_191 = ( F_92 ( V_2 -> V_35 ) == 0 ) ;
} else if ( V_30 -> V_171 ) {
for ( V_44 = 0 ; V_44 < V_47 ; V_44 ++ ) {
error = F_1 ( V_2 , V_189 ,
sizeof( V_189 ) ) ;
if ( ! error )
break;
F_3 ( & V_2 -> V_7 ,
L_80 , error ) ;
}
} else {
F_67 ( V_30 ) ;
}
return 0 ;
}
static int T_6 F_93 ( struct V_138 * V_7 )
{
struct V_1 * V_2 = F_52 ( V_7 ) ;
struct V_29 * V_30 = F_53 ( V_2 ) ;
const T_2 V_192 [] = { 0x54 , 0x58 , 0x00 , 0x01 } ;
int V_44 ;
int error ;
if ( F_91 ( V_7 ) ) {
if ( V_30 -> V_191 )
F_94 ( V_2 -> V_35 ) ;
F_15 ( V_2 ) ;
} else if ( V_30 -> V_171 ) {
for ( V_44 = 0 ; V_44 < V_47 ; V_44 ++ ) {
error = F_1 ( V_2 , V_192 ,
sizeof( V_192 ) ) ;
if ( ! error )
break;
F_3 ( & V_2 -> V_7 ,
L_81 , error ) ;
}
} else {
F_62 ( V_30 ) ;
F_30 ( V_30 ) ;
}
V_30 -> V_36 = V_40 ;
F_12 ( V_2 -> V_35 ) ;
return 0 ;
}
