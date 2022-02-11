static int F_1 ( struct V_1 * V_2 ,
char * V_3 , unsigned int V_4 ,
char * V_5 , unsigned int V_6 )
{
struct V_7 V_8 [] = {
{
. V_9 = V_2 -> V_10 -> V_9 ,
. V_11 = 0 ,
. V_12 = V_3 ,
. V_13 = V_4 ,
} , {
. V_9 = V_2 -> V_10 -> V_9 ,
. V_11 = V_14 ,
. V_12 = V_5 ,
. V_13 = V_6 ,
} ,
} ;
int V_15 = V_16 ;
int V_17 ;
int error ;
do {
V_17 = F_2 ( V_2 -> V_10 -> V_18 , V_8 , F_3 ( V_8 ) ) ;
if ( V_17 == F_3 ( V_8 ) )
return 0 ;
error = V_17 < 0 ? V_17 : - V_19 ;
F_4 ( & V_2 -> V_10 -> V_20 ,
L_1 ,
V_21 , error , V_17 ) ;
} while ( -- V_15 );
return error ;
}
static void F_5 ( const T_1 * V_12 , struct V_22 * V_23 )
{
V_23 -> V_24 = F_6 ( V_12 + 0 ) ;
V_23 -> V_25 = F_6 ( V_12 + 2 ) ;
V_23 -> V_26 = F_6 ( V_12 + 4 ) ;
V_23 -> V_27 = F_6 ( V_12 + 6 ) ;
}
static int F_7 ( struct V_1 * V_2 )
{
T_1 V_28 [] = { V_29 , V_30 } ;
T_1 V_12 [ sizeof( V_2 -> V_31 ) ] ;
int error ;
error = F_1 ( V_2 , V_28 , sizeof( V_28 ) , V_12 , sizeof( V_12 ) ) ;
if ( error ) {
memset ( & V_2 -> V_31 , 0xff , sizeof( V_2 -> V_31 ) ) ;
return error ;
}
F_5 ( V_12 , & V_2 -> V_31 ) ;
return 0 ;
}
static int F_8 ( struct V_1 * V_2 )
{
union V_32 V_33 ;
int error ;
T_1 V_28 [ 2 ] ;
T_1 V_12 [ 14 ] ;
if ( F_9 ( V_2 -> V_10 -> V_18 , V_2 -> V_10 -> V_9 ,
0 , V_34 , 0 , V_35 , & V_33 ) < 0 ) {
F_4 ( & V_2 -> V_10 -> V_20 , L_2 ) ;
return - V_36 ;
}
V_28 [ 0 ] = V_29 ;
V_28 [ 1 ] = V_37 ;
error = F_1 ( V_2 , V_28 , sizeof( V_28 ) ,
V_2 -> V_38 , sizeof( V_2 -> V_38 ) ) ;
if ( error )
F_10 ( & V_2 -> V_10 -> V_20 ,
L_3 , error ) ;
else
F_11 ( & V_2 -> V_10 -> V_20 , L_4 ,
( int ) sizeof( V_2 -> V_38 ) , V_2 -> V_38 ) ;
V_28 [ 0 ] = V_29 ;
V_28 [ 1 ] = V_39 ;
error = F_1 ( V_2 , V_28 , sizeof( V_28 ) , V_12 , 2 ) ;
if ( error ) {
F_10 ( & V_2 -> V_10 -> V_20 ,
L_5 , error ) ;
} else {
V_2 -> V_40 = F_6 ( & V_12 [ 0 ] ) ;
F_11 ( & V_2 -> V_10 -> V_20 , L_6 , V_2 -> V_40 ) ;
}
snprintf ( V_2 -> V_41 , sizeof( V_2 -> V_41 ) ,
L_7 , V_2 -> V_40 ) ;
F_11 ( & V_2 -> V_10 -> V_20 , L_8 , V_2 -> V_41 ) ;
V_28 [ 0 ] = V_29 ;
V_28 [ 1 ] = V_42 ;
error = F_1 ( V_2 , V_28 , sizeof( V_28 ) ,
V_2 -> V_43 , sizeof( V_2 -> V_43 ) ) ;
if ( error )
F_10 ( & V_2 -> V_10 -> V_20 ,
L_9 , error ) ;
else
F_11 ( & V_2 -> V_10 -> V_20 , L_10 ,
( int ) sizeof( V_2 -> V_43 ) , V_2 -> V_43 ) ;
error = F_7 ( V_2 ) ;
if ( error )
F_10 ( & V_2 -> V_10 -> V_20 ,
L_11 , error ) ;
else
F_11 ( & V_2 -> V_10 -> V_20 , L_12 ,
V_2 -> V_31 . V_24 , V_2 -> V_31 . V_25 ,
V_2 -> V_31 . V_26 , V_2 -> V_31 . V_27 ) ;
V_28 [ 0 ] = V_29 ;
V_28 [ 1 ] = V_44 ;
error = F_1 ( V_2 , V_28 , sizeof( V_28 ) , V_12 , 14 ) ;
if ( error ) {
F_10 ( & V_2 -> V_10 -> V_20 ,
L_13 ,
error ) ;
} else {
V_2 -> V_45 = F_6 ( & V_12 [ 0 ] ) ;
V_2 -> V_46 = F_6 ( & V_12 [ 2 ] ) ;
F_11 ( & V_2 -> V_10 -> V_20 , L_14 ,
V_2 -> V_45 , V_2 -> V_46 ) ;
V_2 -> V_47 = V_12 [ 4 ] ;
V_2 -> V_48 = V_12 [ 5 ] ;
V_2 -> V_49 = V_12 [ 6 ] ;
F_11 ( & V_2 -> V_10 -> V_20 ,
L_15 ,
V_2 -> V_47 , V_2 -> V_48 , V_2 -> V_49 ) ;
V_2 -> V_50 = V_12 [ 12 ] ;
V_2 -> V_51 = V_12 [ 13 ] ;
F_11 ( & V_2 -> V_10 -> V_20 , L_16 ,
V_2 -> V_50 , V_2 -> V_51 ) ;
if ( V_2 -> V_49 > 0 )
V_2 -> V_52 = V_2 -> V_49 ;
}
V_28 [ 0 ] = V_53 ;
V_28 [ 1 ] = V_54 ;
error = F_1 ( V_2 , V_28 , sizeof( V_28 ) , V_12 , 7 ) ;
if ( error ) {
F_10 ( & V_2 -> V_10 -> V_20 ,
L_17 , error ) ;
V_2 -> V_55 = 0xff ;
} else {
V_2 -> V_55 = F_6 ( & V_12 [ 4 ] ) ;
V_2 -> V_56 = V_12 [ 6 ] ;
F_11 ( & V_2 -> V_10 -> V_20 , L_18 ,
V_2 -> V_55 , V_2 -> V_56 ) ;
if ( V_2 -> V_55 == 2 || V_2 -> V_55 > 3 )
F_10 ( & V_2 -> V_10 -> V_20 ,
L_19 , V_2 -> V_55 ) ;
}
return 0 ;
}
static int F_12 ( struct V_1 * V_2 )
{
if ( V_2 -> V_57 ) {
F_13 ( V_2 -> V_57 , 1 ) ;
F_14 ( 200 * 1000 , 300 * 1000 ) ;
}
return 0 ;
}
static void F_15 ( struct V_1 * V_2 )
{
if ( V_2 -> V_57 )
F_13 ( V_2 -> V_57 , 0 ) ;
}
static void F_16 ( struct V_1 * V_2 )
{
int V_58 ;
for ( V_58 = 0 ; V_58 < V_59 ; V_58 ++ ) {
F_17 ( V_2 -> V_60 , V_58 ) ;
F_18 ( V_2 -> V_60 , V_61 , 0 ) ;
}
for ( V_58 = 0 ; V_58 < V_2 -> V_52 ; V_58 ++ )
F_19 ( V_2 -> V_60 , V_2 -> V_62 [ V_58 ] , 0 ) ;
F_20 ( V_2 -> V_60 ) ;
}
static int F_21 ( struct V_1 * V_2 )
{
int error ;
error = F_12 ( V_2 ) ;
if ( error )
return error ;
F_22 ( V_2 -> V_10 -> V_63 ) ;
return 0 ;
}
static void F_23 ( struct V_1 * V_2 )
{
F_24 ( V_2 -> V_10 -> V_63 ) ;
F_15 ( V_2 ) ;
F_16 ( V_2 ) ;
}
static void F_25 ( struct V_1 * V_2 , T_1 * V_64 )
{
T_1 V_65 ;
bool V_66 ;
switch ( V_2 -> V_55 ) {
case 0 :
case 1 :
V_65 = V_64 [ 0 ] & 0x0F ;
V_66 = V_64 [ 0 ] & 0x80 ;
break;
case 3 :
default:
V_65 = V_64 [ 0 ] & 0x0F ;
V_66 = V_64 [ 1 ] & 0x01 ;
break;
}
if ( V_65 >= 1 && V_65 <= V_2 -> V_52 ) {
unsigned short V_67 = V_2 -> V_62 [ V_65 - 1 ] ;
F_11 ( & V_2 -> V_10 -> V_20 ,
L_20 ,
V_65 , V_67 , V_66 ) ;
F_26 ( V_2 -> V_60 , V_68 , V_69 , V_67 ) ;
F_19 ( V_2 -> V_60 , V_67 , V_66 ) ;
} else {
F_4 ( & V_2 -> V_10 -> V_20 , L_21 , V_65 ) ;
}
}
static void F_27 ( struct V_1 * V_2 , T_1 * V_64 )
{
int V_70 ;
bool V_71 ;
bool V_72 ;
bool V_73 ;
T_2 V_74 , V_75 ;
T_1 V_76 = 0 ;
T_1 V_77 ;
T_1 V_78 ;
T_1 V_79 ;
T_1 V_80 ;
switch ( V_2 -> V_55 ) {
case 0 :
case 1 :
V_73 = V_64 [ 0 ] & F_28 ( 7 ) ;
V_71 = V_64 [ 0 ] & F_28 ( 5 ) ;
V_72 = V_64 [ 0 ] & F_28 ( 4 ) ;
V_70 = ( V_64 [ 0 ] & 0x0F ) - 1 ;
V_74 = ( ( V_64 [ 1 ] & 0x0F ) << 8 ) | V_64 [ 2 ] ;
V_75 = ( ( ( V_64 [ 1 ] >> 4 ) & 0x0F ) << 8 ) |
V_64 [ 3 ] ;
V_77 = V_64 [ 4 ] ;
V_78 = V_64 [ 5 ] ;
if ( V_2 -> V_55 == 0 ) {
V_79 = V_64 [ 5 ] ;
V_80 = V_64 [ 5 ] ;
} else {
V_79 = V_64 [ 6 ] ;
V_80 = V_64 [ 7 ] ;
}
break;
case 3 :
default:
V_70 = ( V_64 [ 0 ] & 0x0F ) - 1 ;
V_71 = V_64 [ 1 ] & F_28 ( 2 ) ;
V_72 = V_64 [ 1 ] & F_28 ( 1 ) ;
V_73 = V_64 [ 1 ] & F_28 ( 0 ) ;
V_74 = ( ( V_64 [ 2 ] & 0x0F ) << 8 ) | V_64 [ 3 ] ;
V_75 = ( ( ( V_64 [ 2 ] >> 4 ) & 0x0F ) << 8 ) |
V_64 [ 4 ] ;
V_78 = V_64 [ 6 ] ;
V_76 = ( V_64 [ 7 ] & 0xF0 ) >> 4 ;
V_77 = ( ( V_64 [ 7 ] & 0x0F ) << 8 ) |
V_64 [ 8 ] ;
V_79 = V_64 [ 9 ] ;
V_80 = V_64 [ 10 ] ;
break;
}
F_11 ( & V_2 -> V_10 -> V_20 ,
L_22 ,
V_70 , V_73 , V_74 , V_75 , V_77 ) ;
if ( F_29 ( V_70 < 0 || V_70 >= V_59 ) ) {
F_4 ( & V_2 -> V_10 -> V_20 , L_23 , V_70 ) ;
} else if ( V_73 ) {
F_17 ( V_2 -> V_60 , V_70 ) ;
F_18 ( V_2 -> V_60 , V_61 , true ) ;
F_30 ( V_2 -> V_60 , V_81 , V_74 ) ;
F_30 ( V_2 -> V_60 , V_82 , V_75 ) ;
F_30 ( V_2 -> V_60 , V_83 , V_77 ) ;
F_30 ( V_2 -> V_60 , V_84 , V_79 ) ;
F_30 ( V_2 -> V_60 , V_85 , V_80 ) ;
} else {
F_17 ( V_2 -> V_60 , V_70 ) ;
F_18 ( V_2 -> V_60 , V_61 , 0 ) ;
}
F_31 ( V_2 -> V_60 ) ;
}
static int F_32 ( struct V_1 * V_2 , T_1 * V_64 )
{
T_1 type ;
switch ( V_2 -> V_55 ) {
case 0 :
case 1 :
type = ( V_64 [ 0 ] & 0x40 ) >> 6 ;
break;
case 3 :
type = ( V_64 [ 0 ] & 0xF0 ) >> 4 ;
break;
default:
return - V_86 ;
}
F_11 ( & V_2 -> V_10 -> V_20 , L_24 , type ) ;
switch ( type ) {
case V_87 :
F_25 ( V_2 , V_64 ) ;
break;
case V_88 :
F_27 ( V_2 , V_64 ) ;
break;
default:
F_4 ( & V_2 -> V_10 -> V_20 , L_25 , type ) ;
break;
}
return 0 ;
}
static T_3 F_33 ( int V_63 , void * V_89 )
{
struct V_1 * V_2 = V_89 ;
struct V_90 * V_10 = V_2 -> V_10 ;
unsigned int V_58 ;
int error ;
T_1 V_28 [ 2 ] ;
T_1 V_78 ;
bool V_91 ;
V_28 [ 0 ] = V_53 ;
V_28 [ 1 ] = V_92 ;
error = F_1 ( V_2 , V_28 , sizeof( V_28 ) , V_2 -> V_12 , 1 ) ;
if ( error ) {
F_4 ( & V_10 -> V_20 ,
L_26 , error ) ;
goto V_93;
}
V_78 = V_2 -> V_12 [ 0 ] & 0x7F ;
V_91 = V_2 -> V_12 [ 0 ] & F_28 ( 7 ) ;
F_11 ( & V_10 -> V_20 , L_27 , V_78 , V_91 ) ;
if ( ! V_78 ) {
F_4 ( & V_10 -> V_20 , L_28 ) ;
goto V_93;
}
V_28 [ 0 ] = V_53 ;
V_28 [ 1 ] = V_94 ;
error = F_1 ( V_2 , V_28 , sizeof( V_28 ) , V_2 -> V_12 , V_78 ) ;
if ( error ) {
F_4 ( & V_10 -> V_20 ,
L_29 , error ) ;
goto V_93;
}
if ( V_91 ) {
F_11 ( & V_10 -> V_20 , L_30 , V_2 -> V_12 [ 0 ] ) ;
} else {
for ( V_58 = 0 ; V_58 < V_78 ; V_58 += V_2 -> V_56 ) {
error = F_32 ( V_2 , & V_2 -> V_12 [ V_58 ] ) ;
if ( error )
break;
}
F_20 ( V_2 -> V_60 ) ;
}
V_93:
return V_95 ;
}
static int F_34 ( struct V_96 * V_20 )
{
struct V_1 * V_2 = F_35 ( V_20 ) ;
return F_21 ( V_2 ) ;
}
static void F_36 ( struct V_96 * V_20 )
{
struct V_1 * V_2 = F_35 ( V_20 ) ;
F_23 ( V_2 ) ;
}
static int F_37 ( struct V_1 * V_2 )
{
T_1 V_28 [] = { V_97 , V_98 } ;
T_1 V_99 ;
struct V_7 V_8 [] = {
{
. V_9 = V_2 -> V_10 -> V_9 ,
. V_11 = 0 ,
. V_12 = V_28 ,
. V_13 = sizeof( V_28 ) ,
} , {
. V_9 = V_2 -> V_10 -> V_9 ,
. V_11 = V_14 ,
. V_12 = & V_99 ,
. V_13 = sizeof( V_99 ) ,
} ,
} ;
int V_100 ;
int error ;
int V_15 = 1000 ;
do {
V_100 = F_2 ( V_2 -> V_10 -> V_18 , V_8 , F_3 ( V_8 ) ) ;
if ( V_100 != F_3 ( V_8 ) ) {
error = V_100 < 0 ? V_100 : - V_19 ;
F_4 ( & V_2 -> V_10 -> V_20 ,
L_31 ,
error ) ;
return error ;
}
switch ( V_99 ) {
case V_101 :
F_11 ( & V_2 -> V_10 -> V_20 , L_32 , V_21 ) ;
return 0 ;
case V_102 :
F_4 ( & V_2 -> V_10 -> V_20 , L_33 ) ;
return - V_19 ;
case V_103 :
F_11 ( & V_2 -> V_10 -> V_20 , L_34 , V_21 ) ;
error = - V_104 ;
break;
default:
F_4 ( & V_2 -> V_10 -> V_20 ,
L_35 ,
V_99 ) ;
error = - V_86 ;
break;
}
F_14 ( 1000 , 2000 ) ;
} while ( -- V_15 );
return error ;
}
static int F_38 ( struct V_1 * V_2 , T_1 V_105 )
{
T_1 V_106 [] = { V_97 , V_107 , V_105 } ;
T_1 V_108 [] = { V_97 , V_107 } ;
T_1 V_99 ;
struct V_7 V_8 [] = {
{
. V_9 = V_2 -> V_10 -> V_9 ,
. V_11 = 0 ,
. V_12 = V_108 ,
. V_13 = sizeof( V_108 ) ,
} , {
. V_9 = V_2 -> V_10 -> V_9 ,
. V_11 = V_14 ,
. V_12 = & V_99 ,
. V_13 = sizeof( V_99 ) ,
} ,
} ;
int V_15 = 10 ;
int V_100 ;
int error ;
do {
V_100 = F_39 ( V_2 -> V_10 ,
V_106 , sizeof( V_106 ) ) ;
if ( V_100 != sizeof( V_106 ) ) {
error = V_100 < 0 ? V_100 : - V_19 ;
F_4 ( & V_2 -> V_10 -> V_20 ,
L_36 ,
V_105 , error , V_100 ) ;
return error ;
}
F_11 ( & V_2 -> V_10 -> V_20 ,
L_37 , V_105 ) ;
F_40 ( 1000 ) ;
V_100 = F_2 ( V_2 -> V_10 -> V_18 , V_8 , F_3 ( V_8 ) ) ;
if ( V_100 != F_3 ( V_8 ) ) {
error = V_100 < 0 ? V_100 : - V_19 ;
F_4 ( & V_2 -> V_10 -> V_20 ,
L_38 , error ) ;
return error ;
}
F_11 ( & V_2 -> V_10 -> V_20 ,
L_39 , V_99 , V_105 ) ;
if ( V_99 == V_105 )
return 0 ;
} while ( -- V_15 );
return - V_19 ;
}
static int F_41 ( struct V_1 * V_2 )
{
return F_38 ( V_2 , V_109 ) ;
}
static int F_42 ( struct V_1 * V_2 )
{
return F_38 ( V_2 , V_110 ) ;
}
static int F_43 ( struct V_1 * V_2 , T_2 * V_111 )
{
T_1 V_28 [] = { V_97 , V_112 } ;
T_1 V_99 [ sizeof( T_2 ) ] ;
struct V_7 V_8 [] = {
{
. V_9 = V_2 -> V_10 -> V_9 ,
. V_11 = 0 ,
. V_12 = V_28 ,
. V_13 = sizeof( V_28 ) ,
} , {
. V_9 = V_2 -> V_10 -> V_9 ,
. V_11 = V_14 ,
. V_12 = V_99 ,
. V_13 = sizeof( V_99 ) ,
} ,
} ;
int V_100 ;
int error ;
V_100 = F_2 ( V_2 -> V_10 -> V_18 , V_8 , F_3 ( V_8 ) ) ;
if ( V_100 != F_3 ( V_8 ) ) {
error = V_100 < 0 ? V_100 : - V_19 ;
F_4 ( & V_2 -> V_10 -> V_20 ,
L_40 ,
error ) ;
return error ;
}
* V_111 = F_6 ( V_99 ) ;
F_11 ( & V_2 -> V_10 -> V_20 ,
L_41 , * V_111 ) ;
return 0 ;
}
static int F_44 ( struct V_1 * V_2 , int V_113 ,
const T_1 * V_114 , int V_115 , T_2 V_111 )
{
T_1 V_28 [ 6 ] ;
T_1 * V_116 ;
T_2 V_117 ;
int V_100 ;
int error ;
F_11 ( & V_2 -> V_10 -> V_20 , L_42 ,
V_113 , V_115 ) ;
if ( V_115 > V_118 || V_115 % V_119 ) {
F_4 ( & V_2 -> V_10 -> V_20 ,
L_43 , V_115 ) ;
return - V_86 ;
}
V_116 = F_45 ( 2 + V_119 , V_120 ) ;
if ( ! V_116 )
return - V_121 ;
V_28 [ 0 ] = V_97 ;
V_28 [ 1 ] = V_122 ;
F_46 ( V_113 , & V_28 [ 2 ] ) ;
V_100 = F_39 ( V_2 -> V_10 , V_28 , 6 ) ;
if ( V_100 != 6 ) {
error = V_100 < 0 ? V_100 : - V_19 ;
F_4 ( & V_2 -> V_10 -> V_20 ,
L_44 , error ) ;
goto V_93;
}
V_28 [ 0 ] = V_97 ;
V_28 [ 1 ] = V_123 ;
F_46 ( V_115 , & V_28 [ 2 ] ) ;
V_100 = F_39 ( V_2 -> V_10 , V_28 , 6 ) ;
if ( V_100 != 6 ) {
error = V_100 < 0 ? V_100 : - V_19 ;
F_4 ( & V_2 -> V_10 -> V_20 ,
L_45 , error ) ;
goto V_93;
}
for ( V_117 = 0 ;
V_117 < V_115 ;
V_117 += V_119 ) {
F_11 ( & V_2 -> V_10 -> V_20 ,
L_46 ,
V_117 , V_119 ) ;
F_47 ( V_111 + V_117 , V_116 ) ;
memcpy ( & V_116 [ 2 ] , & V_114 [ V_117 ] , V_119 ) ;
V_100 = F_39 ( V_2 -> V_10 ,
V_116 , 2 + V_119 ) ;
if ( V_100 != 2 + V_119 ) {
error = V_100 < 0 ? V_100 : - V_19 ;
F_4 ( & V_2 -> V_10 -> V_20 ,
L_47 ,
V_117 , V_119 , error ) ;
goto V_93;
}
}
V_28 [ 0 ] = V_97 ;
V_28 [ 1 ] = V_124 ;
V_28 [ 2 ] = V_125 ;
V_100 = F_39 ( V_2 -> V_10 , V_28 , 3 ) ;
if ( V_100 != 3 ) {
error = V_100 < 0 ? V_100 : - V_19 ;
F_4 ( & V_2 -> V_10 -> V_20 ,
L_48 , error ) ;
goto V_93;
}
error = F_37 ( V_2 ) ;
V_93:
F_48 ( V_116 ) ;
return error ? error : 0 ;
}
static int F_49 ( struct V_1 * V_2 , int V_113 ,
const T_1 * V_114 , int V_115 , int V_111 )
{
T_1 V_28 [ 8 ] ;
T_1 * V_5 ;
int V_117 ;
struct V_7 V_8 [] = {
{
. V_9 = V_2 -> V_10 -> V_9 ,
. V_11 = 0 ,
. V_12 = V_28 ,
. V_13 = 2 ,
} , {
. V_9 = V_2 -> V_10 -> V_9 ,
. V_11 = V_14 ,
. V_13 = V_119 ,
} ,
} ;
int V_100 ;
int error ;
F_11 ( & V_2 -> V_10 -> V_20 , L_49 ,
V_113 , V_115 ) ;
V_28 [ 0 ] = V_97 ;
V_28 [ 1 ] = V_122 ;
F_46 ( V_113 , & V_28 [ 2 ] ) ;
V_100 = F_39 ( V_2 -> V_10 , V_28 , 6 ) ;
if ( V_100 != 6 ) {
error = V_100 < 0 ? V_100 : - V_19 ;
F_4 ( & V_2 -> V_10 -> V_20 ,
L_50 , error ) ;
return error ;
}
V_28 [ 0 ] = V_97 ;
V_28 [ 1 ] = V_123 ;
F_46 ( V_115 , & V_28 [ 2 ] ) ;
V_100 = F_39 ( V_2 -> V_10 , V_28 , 6 ) ;
if ( V_100 != 6 ) {
error = V_100 < 0 ? V_100 : - V_19 ;
F_4 ( & V_2 -> V_10 -> V_20 ,
L_51 , error ) ;
return error ;
}
V_28 [ 0 ] = V_97 ;
V_28 [ 1 ] = V_124 ;
V_28 [ 2 ] = V_126 ;
V_100 = F_39 ( V_2 -> V_10 , V_28 , 3 ) ;
if ( V_100 != 3 ) {
error = V_100 < 0 ? V_100 : - V_19 ;
F_4 ( & V_2 -> V_10 -> V_20 ,
L_52 , error ) ;
return error ;
}
error = F_37 ( V_2 ) ;
if ( error )
return error ;
V_8 [ 1 ] . V_12 = V_5 = F_45 ( V_119 , V_120 ) ;
if ( ! V_5 )
return - V_121 ;
for ( V_117 = 0 ;
V_117 < V_115 ;
V_117 += V_119 ) {
F_11 ( & V_2 -> V_10 -> V_20 ,
L_53 ,
V_117 , V_119 ) ;
F_47 ( V_111 + V_117 , V_28 ) ;
V_100 = F_2 ( V_2 -> V_10 -> V_18 , V_8 , F_3 ( V_8 ) ) ;
if ( V_100 != F_3 ( V_8 ) ) {
error = V_100 < 0 ? V_100 : - V_19 ;
F_4 ( & V_2 -> V_10 -> V_20 ,
L_47 ,
V_117 , V_119 , error ) ;
break;
}
if ( memcmp ( & V_114 [ V_117 ] , V_5 , V_119 ) ) {
F_4 ( & V_2 -> V_10 -> V_20 ,
L_54 ,
V_117 , V_119 ) ;
#if V_127
F_50 ( V_128 ,
V_129 L_55 ,
V_130 , 16 , 1 ,
V_114 + V_113 , V_119 ,
false ) ;
F_50 ( V_128 ,
V_129 L_56 ,
V_130 , 16 , 1 ,
V_5 , V_118 , false ) ;
#endif
error = - V_86 ;
break;
}
}
F_48 ( V_5 ) ;
return error ? error : 0 ;
}
static int F_51 ( struct V_1 * V_2 ,
const T_1 * V_131 , T_4 V_132 , T_4 V_133 )
{
struct V_90 * V_10 = V_2 -> V_10 ;
int V_113 ;
T_2 V_111 ;
int error , V_134 ;
F_11 ( & V_10 -> V_20 , L_57 ) ;
error = F_41 ( V_2 ) ;
if ( error ) {
F_4 ( & V_10 -> V_20 ,
L_58 ,
error ) ;
return error ;
}
error = F_43 ( V_2 , & V_111 ) ;
if ( error )
goto V_135;
F_11 ( & V_10 -> V_20 ,
L_59 ,
V_118 , V_119 ) ;
for ( V_113 = V_133 ;
V_113 < V_133 + V_132 ;
V_113 += V_118 ) {
error = F_44 ( V_2 , V_113 , V_131 + V_113 ,
V_118 , V_111 ) ;
if ( error )
break;
error = F_49 ( V_2 , V_113 , V_131 + V_113 ,
V_118 , V_111 ) ;
if ( error )
break;
}
V_135:
F_11 ( & V_10 -> V_20 , L_60 ) ;
V_134 = F_42 ( V_2 ) ;
if ( V_134 ) {
F_4 ( & V_10 -> V_20 ,
L_61 , V_134 ) ;
if ( ! error )
error = V_134 ;
}
F_15 ( V_2 ) ;
F_12 ( V_2 ) ;
F_8 ( V_2 ) ;
F_52 ( V_2 -> V_60 , V_81 , 0 , V_2 -> V_45 , 0 , 0 ) ;
F_52 ( V_2 -> V_60 , V_82 , 0 , V_2 -> V_46 , 0 , 0 ) ;
F_52 ( V_2 -> V_60 , V_136 , 0 , V_2 -> V_45 , 0 , 0 ) ;
F_52 ( V_2 -> V_60 , V_137 , 0 , V_2 -> V_46 , 0 , 0 ) ;
F_53 ( V_2 -> V_60 , V_81 , V_2 -> V_50 ) ;
F_53 ( V_2 -> V_60 , V_82 , V_2 -> V_51 ) ;
F_53 ( V_2 -> V_60 , V_136 , V_2 -> V_50 ) ;
F_53 ( V_2 -> V_60 , V_137 , V_2 -> V_51 ) ;
return error ? error : 0 ;
}
static int F_54 ( struct V_1 * V_2 , const struct V_138 * V_139 ,
T_4 * V_140 , T_4 * V_132 ,
const struct V_141 * * V_142 )
{
const struct V_141 * V_143 ;
struct V_22 V_31 ;
T_2 V_144 ;
if ( V_139 -> V_78 < V_145 ) {
F_4 ( & V_2 -> V_10 -> V_20 ,
L_62 ,
V_145 , V_139 -> V_78 ) ;
return - V_86 ;
}
V_143 = ( const void * ) & V_139 -> V_114 [ V_139 -> V_78 - V_145 ] ;
#if V_127
F_50 ( V_146 , V_129 L_63 ,
V_130 , 16 , 1 , * V_143 , V_144 , false ) ;
#endif
V_144 = F_6 ( & V_143 -> V_144 ) ;
if ( V_144 != V_145 ) {
F_4 ( & V_2 -> V_10 -> V_20 ,
L_64 ,
V_144 , V_145 ) ;
return - V_86 ;
}
if ( memcmp ( V_143 -> V_147 , V_148 ,
sizeof( V_143 -> V_147 ) ) ) {
F_4 ( & V_2 -> V_10 -> V_20 ,
L_65 ,
( int ) sizeof( V_143 -> V_147 ) , V_143 -> V_147 ,
( int ) sizeof( V_143 -> V_147 ) , V_148 ) ;
return - V_86 ;
}
* V_140 = F_55 ( & V_143 -> V_149 ) ;
* V_132 = F_55 ( & V_143 -> V_150 ) ;
F_11 ( & V_2 -> V_10 -> V_20 ,
L_66 ,
* V_140 , * V_132 ) ;
if ( * V_132 % V_118 ) {
F_4 ( & V_2 -> V_10 -> V_20 ,
L_67 ,
* V_132 , V_118 ) ;
return - V_86 ;
}
if ( V_139 -> V_78 != * V_140 + * V_132 ) {
F_4 ( & V_2 -> V_10 -> V_20 ,
L_68 ,
* V_140 + * V_132 , V_139 -> V_78 ) ;
return - V_86 ;
}
F_5 ( ( const T_1 * ) & V_143 -> V_151 , & V_31 ) ;
F_11 ( & V_2 -> V_10 -> V_20 ,
L_69 ,
V_31 . V_24 , V_31 . V_25 ,
V_31 . V_26 , V_31 . V_27 ) ;
F_11 ( & V_2 -> V_10 -> V_20 , L_70 ,
V_2 -> V_31 . V_24 , V_2 -> V_31 . V_25 ,
V_2 -> V_31 . V_26 , V_2 -> V_31 . V_27 ) ;
if ( V_31 . V_24 != 0xEEEE && V_31 . V_24 != 0xFFFF &&
V_31 . V_25 == 0xEEEE &&
V_31 . V_26 == 0xEEEE &&
V_31 . V_27 == 0xEEEE ) {
F_11 ( & V_2 -> V_10 -> V_20 , L_71 ) ;
} else if ( V_31 . V_24 == 0xEEEE &&
V_31 . V_25 != 0xEEEE && V_31 . V_25 != 0xFFFF &&
V_31 . V_26 != 0xEEEE && V_31 . V_26 != 0xFFFF &&
V_31 . V_27 != 0xEEEE && V_31 . V_27 != 0xFFFF ) {
F_11 ( & V_2 -> V_10 -> V_20 , L_72 ) ;
} else {
F_4 ( & V_2 -> V_10 -> V_20 , L_73 ) ;
return - V_86 ;
}
return 0 ;
}
static int F_56 ( struct V_1 * V_2 , const struct V_138 * V_139 )
{
const struct V_141 * V_143 ;
T_4 V_152 ;
T_4 V_132 ;
int V_153 = 3 ;
int error ;
error = F_54 ( V_2 , V_139 ,
& V_152 , & V_132 , & V_143 ) ;
if ( error )
return error ;
if ( V_2 -> V_60 -> V_154 ) {
F_24 ( V_2 -> V_10 -> V_63 ) ;
} else {
error = F_12 ( V_2 ) ;
if ( error )
return error ;
}
do {
error = F_51 ( V_2 , V_139 -> V_114 , V_132 , V_152 ) ;
if ( ! error )
break;
} while ( -- V_153 );
if ( error )
F_4 ( & V_2 -> V_10 -> V_20 ,
L_74 , error ) ;
if ( V_2 -> V_60 -> V_154 )
F_22 ( V_2 -> V_10 -> V_63 ) ;
else
F_15 ( V_2 ) ;
return error ? error : 0 ;
}
static T_5 F_57 ( struct V_155 * V_20 ,
struct V_156 * V_157 ,
const char * V_12 , T_6 V_158 )
{
struct V_90 * V_10 = F_58 ( V_20 ) ;
struct V_1 * V_2 = F_59 ( V_10 ) ;
const struct V_138 * V_139 ;
int error ;
error = F_60 ( & V_139 , V_2 -> V_41 , V_20 ) ;
if ( error ) {
F_4 ( & V_2 -> V_10 -> V_20 ,
L_75 ,
V_2 -> V_41 , error ) ;
return error ;
}
F_61 ( & V_2 -> V_60 -> V_159 ) ;
error = F_56 ( V_2 , V_139 ) ;
F_62 ( & V_2 -> V_60 -> V_159 ) ;
F_63 ( V_139 ) ;
if ( error ) {
F_4 ( & V_2 -> V_10 -> V_20 ,
L_76 , error ) ;
return error ;
}
return V_158 ;
}
static T_5 F_64 ( struct V_155 * V_20 ,
struct V_156 * V_157 ,
char * V_12 )
{
struct V_90 * V_10 = F_58 ( V_20 ) ;
struct V_1 * V_2 = F_59 ( V_10 ) ;
T_6 V_158 ;
F_61 ( & V_2 -> V_60 -> V_159 ) ;
V_158 = snprintf ( V_12 , V_160 , L_77 ,
V_2 -> V_31 . V_24 , V_2 -> V_31 . V_25 ,
V_2 -> V_31 . V_26 , V_2 -> V_31 . V_27 ) ;
F_62 ( & V_2 -> V_60 -> V_159 ) ;
return V_158 ;
}
static T_5 F_65 ( struct V_155 * V_20 ,
struct V_156 * V_157 ,
char * V_12 )
{
struct V_90 * V_10 = F_58 ( V_20 ) ;
struct V_1 * V_2 = F_59 ( V_10 ) ;
T_6 V_158 ;
F_61 ( & V_2 -> V_60 -> V_159 ) ;
V_158 = snprintf ( V_12 , V_160 , L_78 ,
( int ) sizeof( V_2 -> V_38 ) , V_2 -> V_38 ) ;
F_62 ( & V_2 -> V_60 -> V_159 ) ;
return V_158 ;
}
static T_5 F_66 ( struct V_155 * V_20 ,
struct V_156 * V_157 ,
char * V_12 )
{
struct V_90 * V_10 = F_58 ( V_20 ) ;
struct V_1 * V_2 = F_59 ( V_10 ) ;
T_6 V_158 ;
F_61 ( & V_2 -> V_60 -> V_159 ) ;
V_158 = snprintf ( V_12 , V_160 , L_79 , V_2 -> V_40 ) ;
F_62 ( & V_2 -> V_60 -> V_159 ) ;
return V_158 ;
}
static T_5 F_67 ( struct V_155 * V_20 ,
struct V_156 * V_157 ,
char * V_12 )
{
struct V_90 * V_10 = F_58 ( V_20 ) ;
struct V_1 * V_2 = F_59 ( V_10 ) ;
T_6 V_158 ;
F_61 ( & V_2 -> V_60 -> V_159 ) ;
V_158 = snprintf ( V_12 , V_160 , L_78 ,
( int ) sizeof( V_2 -> V_43 ) , V_2 -> V_43 ) ;
F_62 ( & V_2 -> V_60 -> V_159 ) ;
return V_158 ;
}
static void F_68 ( void * V_161 )
{
struct V_1 * V_2 = V_161 ;
F_69 ( & V_2 -> V_10 -> V_20 . V_162 , & V_163 ) ;
}
static int F_70 ( struct V_90 * V_10 , const struct V_164 * V_70 )
{
struct V_1 * V_2 ;
struct V_96 * V_60 ;
int error ;
if ( ! F_71 ( V_10 -> V_18 , V_165 ) ) {
F_4 ( & V_10 -> V_20 , L_80 ) ;
return - V_36 ;
}
V_2 = F_72 ( & V_10 -> V_20 , sizeof( * V_2 ) , V_120 ) ;
if ( ! V_2 )
return - V_121 ;
V_60 = F_73 ( & V_10 -> V_20 ) ;
if ( ! V_60 )
return - V_121 ;
V_2 -> V_10 = V_10 ;
V_2 -> V_60 = V_60 ;
snprintf ( V_2 -> V_166 , sizeof( V_2 -> V_166 ) ,
L_81 , F_74 ( & V_10 -> V_20 ) ) ;
V_2 -> V_57 = F_75 ( & V_10 -> V_20 ,
L_82 , V_167 ) ;
if ( F_76 ( V_2 -> V_57 ) ) {
error = F_77 ( V_2 -> V_57 ) ;
if ( error != V_168 )
F_4 ( & V_10 -> V_20 ,
L_83 , error ) ;
return error ;
}
error = F_12 ( V_2 ) ;
if ( error )
return error ;
error = F_8 ( V_2 ) ;
F_15 ( V_2 ) ;
if ( error )
return error ;
V_60 -> V_169 = L_84 ;
V_60 -> V_166 = V_2 -> V_166 ;
V_60 -> V_70 . V_170 = V_171 ;
V_60 -> V_70 . V_172 = 0x13c5 ;
V_60 -> V_70 . V_173 = V_2 -> V_40 ;
V_60 -> V_174 = F_34 ;
V_60 -> V_175 = F_36 ;
F_78 ( V_60 , V_2 ) ;
V_60 -> V_67 = V_2 -> V_62 ;
V_60 -> V_176 = sizeof( * V_2 -> V_62 ) ;
V_60 -> V_177 = V_2 -> V_52 ;
F_52 ( V_60 , V_81 , 0 , V_2 -> V_45 , 0 , 0 ) ;
F_52 ( V_60 , V_82 , 0 , V_2 -> V_46 , 0 , 0 ) ;
F_52 ( V_60 , V_83 ,
V_178 , V_179 , 0 , 0 ) ;
F_52 ( V_60 , V_84 ,
V_180 , V_181 , 0 , 0 ) ;
F_52 ( V_60 , V_85 ,
V_182 , V_183 , 0 , 0 ) ;
F_53 ( V_2 -> V_60 , V_81 , V_2 -> V_50 ) ;
F_53 ( V_2 -> V_60 , V_82 , V_2 -> V_51 ) ;
error = F_79 ( V_60 , V_59 , V_184 ) ;
if ( error )
return error ;
F_80 ( V_10 , V_2 ) ;
error = F_81 ( & V_10 -> V_20 , V_10 -> V_63 ,
NULL , F_33 ,
V_185 , V_129 , V_2 ) ;
if ( error ) {
F_4 ( & V_10 -> V_20 ,
L_85 ,
V_10 -> V_63 , error ) ;
return error ;
}
F_24 ( V_10 -> V_63 ) ;
error = F_82 ( V_60 ) ;
if ( error ) {
F_4 ( & V_10 -> V_20 ,
L_86 , error ) ;
return error ;
}
error = F_83 ( & V_10 -> V_20 . V_162 , & V_163 ) ;
if ( error ) {
F_4 ( & V_10 -> V_20 ,
L_87 , error ) ;
return error ;
}
error = F_84 ( & V_10 -> V_20 , F_68 , V_2 ) ;
if ( error ) {
F_68 ( V_2 ) ;
F_4 ( & V_10 -> V_20 ,
L_88 , error ) ;
return error ;
}
return 0 ;
}
static int T_7 F_85 ( struct V_155 * V_20 )
{
struct V_90 * V_10 = F_58 ( V_20 ) ;
struct V_1 * V_2 = F_59 ( V_10 ) ;
struct V_96 * V_60 = V_2 -> V_60 ;
F_61 ( & V_60 -> V_159 ) ;
if ( F_86 ( V_20 ) )
V_2 -> V_186 = F_87 ( V_10 -> V_63 ) == 0 ;
else if ( V_60 -> V_154 )
F_23 ( V_2 ) ;
F_62 ( & V_60 -> V_159 ) ;
return 0 ;
}
static int T_7 F_88 ( struct V_155 * V_20 )
{
struct V_90 * V_10 = F_58 ( V_20 ) ;
struct V_1 * V_2 = F_59 ( V_10 ) ;
struct V_96 * V_60 = V_2 -> V_60 ;
F_61 ( & V_60 -> V_159 ) ;
if ( V_2 -> V_186 )
F_89 ( V_10 -> V_63 ) ;
else if ( V_60 -> V_154 )
F_21 ( V_2 ) ;
F_62 ( & V_60 -> V_159 ) ;
return 0 ;
}
