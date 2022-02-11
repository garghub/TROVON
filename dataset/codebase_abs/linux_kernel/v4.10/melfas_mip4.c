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
int error ;
T_1 V_28 [ 2 ] ;
T_1 V_12 [ 14 ] ;
V_28 [ 0 ] = V_29 ;
V_28 [ 1 ] = V_32 ;
error = F_1 ( V_2 , V_28 , sizeof( V_28 ) ,
V_2 -> V_33 , sizeof( V_2 -> V_33 ) ) ;
if ( error )
F_9 ( & V_2 -> V_10 -> V_20 ,
L_2 , error ) ;
else
F_10 ( & V_2 -> V_10 -> V_20 , L_3 ,
( int ) sizeof( V_2 -> V_33 ) , V_2 -> V_33 ) ;
V_28 [ 0 ] = V_29 ;
V_28 [ 1 ] = V_34 ;
error = F_1 ( V_2 , V_28 , sizeof( V_28 ) , V_12 , 2 ) ;
if ( error ) {
F_9 ( & V_2 -> V_10 -> V_20 ,
L_4 , error ) ;
} else {
V_2 -> V_35 = F_6 ( & V_12 [ 0 ] ) ;
F_10 ( & V_2 -> V_10 -> V_20 , L_5 , V_2 -> V_35 ) ;
}
snprintf ( V_2 -> V_36 , sizeof( V_2 -> V_36 ) ,
L_6 , V_2 -> V_35 ) ;
F_10 ( & V_2 -> V_10 -> V_20 , L_7 , V_2 -> V_36 ) ;
V_28 [ 0 ] = V_29 ;
V_28 [ 1 ] = V_37 ;
error = F_1 ( V_2 , V_28 , sizeof( V_28 ) ,
V_2 -> V_38 , sizeof( V_2 -> V_38 ) ) ;
if ( error )
F_9 ( & V_2 -> V_10 -> V_20 ,
L_8 , error ) ;
else
F_10 ( & V_2 -> V_10 -> V_20 , L_9 ,
( int ) sizeof( V_2 -> V_38 ) , V_2 -> V_38 ) ;
error = F_7 ( V_2 ) ;
if ( error )
F_9 ( & V_2 -> V_10 -> V_20 ,
L_10 , error ) ;
else
F_10 ( & V_2 -> V_10 -> V_20 , L_11 ,
V_2 -> V_31 . V_24 , V_2 -> V_31 . V_25 ,
V_2 -> V_31 . V_26 , V_2 -> V_31 . V_27 ) ;
V_28 [ 0 ] = V_29 ;
V_28 [ 1 ] = V_39 ;
error = F_1 ( V_2 , V_28 , sizeof( V_28 ) , V_12 , 14 ) ;
if ( error ) {
F_9 ( & V_2 -> V_10 -> V_20 ,
L_12 ,
error ) ;
} else {
V_2 -> V_40 = F_6 ( & V_12 [ 0 ] ) ;
V_2 -> V_41 = F_6 ( & V_12 [ 2 ] ) ;
F_10 ( & V_2 -> V_10 -> V_20 , L_13 ,
V_2 -> V_40 , V_2 -> V_41 ) ;
V_2 -> V_42 = V_12 [ 4 ] ;
V_2 -> V_43 = V_12 [ 5 ] ;
V_2 -> V_44 = V_12 [ 6 ] ;
F_10 ( & V_2 -> V_10 -> V_20 ,
L_14 ,
V_2 -> V_42 , V_2 -> V_43 , V_2 -> V_44 ) ;
V_2 -> V_45 = V_12 [ 12 ] ;
V_2 -> V_46 = V_12 [ 13 ] ;
F_10 ( & V_2 -> V_10 -> V_20 , L_15 ,
V_2 -> V_45 , V_2 -> V_46 ) ;
if ( V_2 -> V_44 > 0 )
V_2 -> V_47 = V_2 -> V_44 ;
}
V_28 [ 0 ] = V_48 ;
V_28 [ 1 ] = V_49 ;
error = F_1 ( V_2 , V_28 , sizeof( V_28 ) , V_12 , 7 ) ;
if ( error ) {
F_9 ( & V_2 -> V_10 -> V_20 ,
L_16 , error ) ;
V_2 -> V_50 = 0xff ;
} else {
V_2 -> V_50 = F_6 ( & V_12 [ 4 ] ) ;
V_2 -> V_51 = V_12 [ 6 ] ;
F_10 ( & V_2 -> V_10 -> V_20 , L_17 ,
V_2 -> V_50 , V_2 -> V_51 ) ;
if ( V_2 -> V_50 == 2 || V_2 -> V_50 > 3 )
F_9 ( & V_2 -> V_10 -> V_20 ,
L_18 , V_2 -> V_50 ) ;
}
return 0 ;
}
static int F_11 ( struct V_1 * V_2 )
{
if ( V_2 -> V_52 ) {
F_12 ( V_2 -> V_52 , 1 ) ;
F_13 ( 200 * 1000 , 300 * 1000 ) ;
}
return 0 ;
}
static void F_14 ( struct V_1 * V_2 )
{
if ( V_2 -> V_52 )
F_12 ( V_2 -> V_52 , 0 ) ;
}
static void F_15 ( struct V_1 * V_2 )
{
int V_53 ;
for ( V_53 = 0 ; V_53 < V_54 ; V_53 ++ ) {
F_16 ( V_2 -> V_55 , V_53 ) ;
F_17 ( V_2 -> V_55 , V_56 , 0 ) ;
}
for ( V_53 = 0 ; V_53 < V_2 -> V_47 ; V_53 ++ )
F_18 ( V_2 -> V_55 , V_2 -> V_57 [ V_53 ] , 0 ) ;
F_19 ( V_2 -> V_55 ) ;
}
static int F_20 ( struct V_1 * V_2 )
{
int error ;
error = F_11 ( V_2 ) ;
if ( error )
return error ;
F_21 ( V_2 -> V_10 -> V_58 ) ;
return 0 ;
}
static void F_22 ( struct V_1 * V_2 )
{
F_23 ( V_2 -> V_10 -> V_58 ) ;
F_14 ( V_2 ) ;
F_15 ( V_2 ) ;
}
static void F_24 ( struct V_1 * V_2 , T_1 * V_59 )
{
T_1 V_60 ;
bool V_61 ;
switch ( V_2 -> V_50 ) {
case 0 :
case 1 :
V_60 = V_59 [ 0 ] & 0x0F ;
V_61 = V_59 [ 0 ] & 0x80 ;
break;
case 3 :
default:
V_60 = V_59 [ 0 ] & 0x0F ;
V_61 = V_59 [ 1 ] & 0x01 ;
break;
}
if ( V_60 >= 1 && V_60 <= V_2 -> V_47 ) {
unsigned short V_62 = V_2 -> V_57 [ V_60 - 1 ] ;
F_10 ( & V_2 -> V_10 -> V_20 ,
L_19 ,
V_60 , V_62 , V_61 ) ;
F_25 ( V_2 -> V_55 , V_63 , V_64 , V_62 ) ;
F_18 ( V_2 -> V_55 , V_62 , V_61 ) ;
} else {
F_4 ( & V_2 -> V_10 -> V_20 , L_20 , V_60 ) ;
}
}
static void F_26 ( struct V_1 * V_2 , T_1 * V_59 )
{
int V_65 ;
bool V_66 ;
bool V_67 ;
bool V_68 ;
T_2 V_69 , V_70 ;
T_1 V_71 = 0 ;
T_1 V_72 ;
T_1 V_73 ;
T_1 V_74 ;
T_1 V_75 ;
switch ( V_2 -> V_50 ) {
case 0 :
case 1 :
V_68 = V_59 [ 0 ] & F_27 ( 7 ) ;
V_66 = V_59 [ 0 ] & F_27 ( 5 ) ;
V_67 = V_59 [ 0 ] & F_27 ( 4 ) ;
V_65 = ( V_59 [ 0 ] & 0x0F ) - 1 ;
V_69 = ( ( V_59 [ 1 ] & 0x0F ) << 8 ) | V_59 [ 2 ] ;
V_70 = ( ( ( V_59 [ 1 ] >> 4 ) & 0x0F ) << 8 ) |
V_59 [ 3 ] ;
V_72 = V_59 [ 4 ] ;
V_73 = V_59 [ 5 ] ;
if ( V_2 -> V_50 == 0 ) {
V_74 = V_59 [ 5 ] ;
V_75 = V_59 [ 5 ] ;
} else {
V_74 = V_59 [ 6 ] ;
V_75 = V_59 [ 7 ] ;
}
break;
case 3 :
default:
V_65 = ( V_59 [ 0 ] & 0x0F ) - 1 ;
V_66 = V_59 [ 1 ] & F_27 ( 2 ) ;
V_67 = V_59 [ 1 ] & F_27 ( 1 ) ;
V_68 = V_59 [ 1 ] & F_27 ( 0 ) ;
V_69 = ( ( V_59 [ 2 ] & 0x0F ) << 8 ) | V_59 [ 3 ] ;
V_70 = ( ( ( V_59 [ 2 ] >> 4 ) & 0x0F ) << 8 ) |
V_59 [ 4 ] ;
V_73 = V_59 [ 6 ] ;
V_71 = ( V_59 [ 7 ] & 0xF0 ) >> 4 ;
V_72 = ( ( V_59 [ 7 ] & 0x0F ) << 8 ) |
V_59 [ 8 ] ;
V_74 = V_59 [ 9 ] ;
V_75 = V_59 [ 10 ] ;
break;
}
F_10 ( & V_2 -> V_10 -> V_20 ,
L_21 ,
V_65 , V_68 , V_69 , V_70 , V_72 ) ;
if ( F_28 ( V_65 < 0 || V_65 >= V_54 ) ) {
F_4 ( & V_2 -> V_10 -> V_20 , L_22 , V_65 ) ;
} else if ( V_68 ) {
F_16 ( V_2 -> V_55 , V_65 ) ;
F_17 ( V_2 -> V_55 , V_56 , true ) ;
F_29 ( V_2 -> V_55 , V_76 , V_69 ) ;
F_29 ( V_2 -> V_55 , V_77 , V_70 ) ;
F_29 ( V_2 -> V_55 , V_78 , V_72 ) ;
F_29 ( V_2 -> V_55 , V_79 , V_74 ) ;
F_29 ( V_2 -> V_55 , V_80 , V_75 ) ;
} else {
F_16 ( V_2 -> V_55 , V_65 ) ;
F_17 ( V_2 -> V_55 , V_56 , 0 ) ;
}
F_30 ( V_2 -> V_55 ) ;
}
static int F_31 ( struct V_1 * V_2 , T_1 * V_59 )
{
T_1 type ;
switch ( V_2 -> V_50 ) {
case 0 :
case 1 :
type = ( V_59 [ 0 ] & 0x40 ) >> 6 ;
break;
case 3 :
type = ( V_59 [ 0 ] & 0xF0 ) >> 4 ;
break;
default:
return - V_81 ;
}
F_10 ( & V_2 -> V_10 -> V_20 , L_23 , type ) ;
switch ( type ) {
case V_82 :
F_24 ( V_2 , V_59 ) ;
break;
case V_83 :
F_26 ( V_2 , V_59 ) ;
break;
default:
F_4 ( & V_2 -> V_10 -> V_20 , L_24 , type ) ;
break;
}
return 0 ;
}
static T_3 F_32 ( int V_58 , void * V_84 )
{
struct V_1 * V_2 = V_84 ;
struct V_85 * V_10 = V_2 -> V_10 ;
unsigned int V_53 ;
int error ;
T_1 V_28 [ 2 ] ;
T_1 V_73 ;
bool V_86 ;
V_28 [ 0 ] = V_48 ;
V_28 [ 1 ] = V_87 ;
error = F_1 ( V_2 , V_28 , sizeof( V_28 ) , V_2 -> V_12 , 1 ) ;
if ( error ) {
F_4 ( & V_10 -> V_20 ,
L_25 , error ) ;
goto V_88;
}
V_73 = V_2 -> V_12 [ 0 ] & 0x7F ;
V_86 = V_2 -> V_12 [ 0 ] & F_27 ( 7 ) ;
F_10 ( & V_10 -> V_20 , L_26 , V_73 , V_86 ) ;
if ( ! V_73 ) {
F_4 ( & V_10 -> V_20 , L_27 ) ;
goto V_88;
}
V_28 [ 0 ] = V_48 ;
V_28 [ 1 ] = V_89 ;
error = F_1 ( V_2 , V_28 , sizeof( V_28 ) , V_2 -> V_12 , V_73 ) ;
if ( error ) {
F_4 ( & V_10 -> V_20 ,
L_28 , error ) ;
goto V_88;
}
if ( V_86 ) {
F_10 ( & V_10 -> V_20 , L_29 , V_2 -> V_12 [ 0 ] ) ;
} else {
for ( V_53 = 0 ; V_53 < V_73 ; V_53 += V_2 -> V_51 ) {
error = F_31 ( V_2 , & V_2 -> V_12 [ V_53 ] ) ;
if ( error )
break;
}
F_19 ( V_2 -> V_55 ) ;
}
V_88:
return V_90 ;
}
static int F_33 ( struct V_91 * V_20 )
{
struct V_1 * V_2 = F_34 ( V_20 ) ;
return F_20 ( V_2 ) ;
}
static void F_35 ( struct V_91 * V_20 )
{
struct V_1 * V_2 = F_34 ( V_20 ) ;
F_22 ( V_2 ) ;
}
static int F_36 ( struct V_1 * V_2 )
{
T_1 V_28 [] = { V_92 , V_93 } ;
T_1 V_94 ;
struct V_7 V_8 [] = {
{
. V_9 = V_2 -> V_10 -> V_9 ,
. V_11 = 0 ,
. V_12 = V_28 ,
. V_13 = sizeof( V_28 ) ,
} , {
. V_9 = V_2 -> V_10 -> V_9 ,
. V_11 = V_14 ,
. V_12 = & V_94 ,
. V_13 = sizeof( V_94 ) ,
} ,
} ;
int V_95 ;
int error ;
int V_15 = 1000 ;
do {
V_95 = F_2 ( V_2 -> V_10 -> V_18 , V_8 , F_3 ( V_8 ) ) ;
if ( V_95 != F_3 ( V_8 ) ) {
error = V_95 < 0 ? V_95 : - V_19 ;
F_4 ( & V_2 -> V_10 -> V_20 ,
L_30 ,
error ) ;
return error ;
}
switch ( V_94 ) {
case V_96 :
F_10 ( & V_2 -> V_10 -> V_20 , L_31 , V_21 ) ;
return 0 ;
case V_97 :
F_4 ( & V_2 -> V_10 -> V_20 , L_32 ) ;
return - V_19 ;
case V_98 :
F_10 ( & V_2 -> V_10 -> V_20 , L_33 , V_21 ) ;
error = - V_99 ;
break;
default:
F_4 ( & V_2 -> V_10 -> V_20 ,
L_34 ,
V_94 ) ;
error = - V_81 ;
break;
}
F_13 ( 1000 , 2000 ) ;
} while ( -- V_15 );
return error ;
}
static int F_37 ( struct V_1 * V_2 , T_1 V_100 )
{
T_1 V_101 [] = { V_92 , V_102 , V_100 } ;
T_1 V_103 [] = { V_92 , V_102 } ;
T_1 V_94 ;
struct V_7 V_8 [] = {
{
. V_9 = V_2 -> V_10 -> V_9 ,
. V_11 = 0 ,
. V_12 = V_103 ,
. V_13 = sizeof( V_103 ) ,
} , {
. V_9 = V_2 -> V_10 -> V_9 ,
. V_11 = V_14 ,
. V_12 = & V_94 ,
. V_13 = sizeof( V_94 ) ,
} ,
} ;
int V_15 = 10 ;
int V_95 ;
int error ;
do {
V_95 = F_38 ( V_2 -> V_10 ,
V_101 , sizeof( V_101 ) ) ;
if ( V_95 != sizeof( V_101 ) ) {
error = V_95 < 0 ? V_95 : - V_19 ;
F_4 ( & V_2 -> V_10 -> V_20 ,
L_35 ,
V_100 , error , V_95 ) ;
return error ;
}
F_10 ( & V_2 -> V_10 -> V_20 ,
L_36 , V_100 ) ;
F_39 ( 1000 ) ;
V_95 = F_2 ( V_2 -> V_10 -> V_18 , V_8 , F_3 ( V_8 ) ) ;
if ( V_95 != F_3 ( V_8 ) ) {
error = V_95 < 0 ? V_95 : - V_19 ;
F_4 ( & V_2 -> V_10 -> V_20 ,
L_37 , error ) ;
return error ;
}
F_10 ( & V_2 -> V_10 -> V_20 ,
L_38 , V_94 , V_100 ) ;
if ( V_94 == V_100 )
return 0 ;
} while ( -- V_15 );
return - V_19 ;
}
static int F_40 ( struct V_1 * V_2 )
{
return F_37 ( V_2 , V_104 ) ;
}
static int F_41 ( struct V_1 * V_2 )
{
return F_37 ( V_2 , V_105 ) ;
}
static int F_42 ( struct V_1 * V_2 , T_2 * V_106 )
{
T_1 V_28 [] = { V_92 , V_107 } ;
T_1 V_94 [ sizeof( T_2 ) ] ;
struct V_7 V_8 [] = {
{
. V_9 = V_2 -> V_10 -> V_9 ,
. V_11 = 0 ,
. V_12 = V_28 ,
. V_13 = sizeof( V_28 ) ,
} , {
. V_9 = V_2 -> V_10 -> V_9 ,
. V_11 = V_14 ,
. V_12 = V_94 ,
. V_13 = sizeof( V_94 ) ,
} ,
} ;
int V_95 ;
int error ;
V_95 = F_2 ( V_2 -> V_10 -> V_18 , V_8 , F_3 ( V_8 ) ) ;
if ( V_95 != F_3 ( V_8 ) ) {
error = V_95 < 0 ? V_95 : - V_19 ;
F_4 ( & V_2 -> V_10 -> V_20 ,
L_39 ,
error ) ;
return error ;
}
* V_106 = F_6 ( V_94 ) ;
F_10 ( & V_2 -> V_10 -> V_20 ,
L_40 , * V_106 ) ;
return 0 ;
}
static int F_43 ( struct V_1 * V_2 , int V_108 ,
const T_1 * V_109 , int V_110 , T_2 V_106 )
{
T_1 V_28 [ 6 ] ;
T_1 * V_111 ;
T_2 V_112 ;
int V_95 ;
int error ;
F_10 ( & V_2 -> V_10 -> V_20 , L_41 ,
V_108 , V_110 ) ;
if ( V_110 > V_113 || V_110 % V_114 ) {
F_4 ( & V_2 -> V_10 -> V_20 ,
L_42 , V_110 ) ;
return - V_81 ;
}
V_111 = F_44 ( 2 + V_114 , V_115 ) ;
if ( ! V_111 )
return - V_116 ;
V_28 [ 0 ] = V_92 ;
V_28 [ 1 ] = V_117 ;
F_45 ( V_108 , & V_28 [ 2 ] ) ;
V_95 = F_38 ( V_2 -> V_10 , V_28 , 6 ) ;
if ( V_95 != 6 ) {
error = V_95 < 0 ? V_95 : - V_19 ;
F_4 ( & V_2 -> V_10 -> V_20 ,
L_43 , error ) ;
goto V_88;
}
V_28 [ 0 ] = V_92 ;
V_28 [ 1 ] = V_118 ;
F_45 ( V_110 , & V_28 [ 2 ] ) ;
V_95 = F_38 ( V_2 -> V_10 , V_28 , 6 ) ;
if ( V_95 != 6 ) {
error = V_95 < 0 ? V_95 : - V_19 ;
F_4 ( & V_2 -> V_10 -> V_20 ,
L_44 , error ) ;
goto V_88;
}
for ( V_112 = 0 ;
V_112 < V_110 ;
V_112 += V_114 ) {
F_10 ( & V_2 -> V_10 -> V_20 ,
L_45 ,
V_112 , V_114 ) ;
F_46 ( V_106 + V_112 , V_111 ) ;
memcpy ( & V_111 [ 2 ] , & V_109 [ V_112 ] , V_114 ) ;
V_95 = F_38 ( V_2 -> V_10 ,
V_111 , 2 + V_114 ) ;
if ( V_95 != 2 + V_114 ) {
error = V_95 < 0 ? V_95 : - V_19 ;
F_4 ( & V_2 -> V_10 -> V_20 ,
L_46 ,
V_112 , V_114 , error ) ;
goto V_88;
}
}
V_28 [ 0 ] = V_92 ;
V_28 [ 1 ] = V_119 ;
V_28 [ 2 ] = V_120 ;
V_95 = F_38 ( V_2 -> V_10 , V_28 , 3 ) ;
if ( V_95 != 3 ) {
error = V_95 < 0 ? V_95 : - V_19 ;
F_4 ( & V_2 -> V_10 -> V_20 ,
L_47 , error ) ;
goto V_88;
}
error = F_36 ( V_2 ) ;
V_88:
F_47 ( V_111 ) ;
return error ? error : 0 ;
}
static int F_48 ( struct V_1 * V_2 , int V_108 ,
const T_1 * V_109 , int V_110 , int V_106 )
{
T_1 V_28 [ 8 ] ;
T_1 * V_5 ;
int V_112 ;
struct V_7 V_8 [] = {
{
. V_9 = V_2 -> V_10 -> V_9 ,
. V_11 = 0 ,
. V_12 = V_28 ,
. V_13 = 2 ,
} , {
. V_9 = V_2 -> V_10 -> V_9 ,
. V_11 = V_14 ,
. V_13 = V_114 ,
} ,
} ;
int V_95 ;
int error ;
F_10 ( & V_2 -> V_10 -> V_20 , L_48 ,
V_108 , V_110 ) ;
V_28 [ 0 ] = V_92 ;
V_28 [ 1 ] = V_117 ;
F_45 ( V_108 , & V_28 [ 2 ] ) ;
V_95 = F_38 ( V_2 -> V_10 , V_28 , 6 ) ;
if ( V_95 != 6 ) {
error = V_95 < 0 ? V_95 : - V_19 ;
F_4 ( & V_2 -> V_10 -> V_20 ,
L_49 , error ) ;
return error ;
}
V_28 [ 0 ] = V_92 ;
V_28 [ 1 ] = V_118 ;
F_45 ( V_110 , & V_28 [ 2 ] ) ;
V_95 = F_38 ( V_2 -> V_10 , V_28 , 6 ) ;
if ( V_95 != 6 ) {
error = V_95 < 0 ? V_95 : - V_19 ;
F_4 ( & V_2 -> V_10 -> V_20 ,
L_50 , error ) ;
return error ;
}
V_28 [ 0 ] = V_92 ;
V_28 [ 1 ] = V_119 ;
V_28 [ 2 ] = V_121 ;
V_95 = F_38 ( V_2 -> V_10 , V_28 , 3 ) ;
if ( V_95 != 3 ) {
error = V_95 < 0 ? V_95 : - V_19 ;
F_4 ( & V_2 -> V_10 -> V_20 ,
L_51 , error ) ;
return error ;
}
error = F_36 ( V_2 ) ;
if ( error )
return error ;
V_8 [ 1 ] . V_12 = V_5 = F_44 ( V_114 , V_115 ) ;
if ( ! V_5 )
return - V_116 ;
for ( V_112 = 0 ;
V_112 < V_110 ;
V_112 += V_114 ) {
F_10 ( & V_2 -> V_10 -> V_20 ,
L_52 ,
V_112 , V_114 ) ;
F_46 ( V_106 + V_112 , V_28 ) ;
V_95 = F_2 ( V_2 -> V_10 -> V_18 , V_8 , F_3 ( V_8 ) ) ;
if ( V_95 != F_3 ( V_8 ) ) {
error = V_95 < 0 ? V_95 : - V_19 ;
F_4 ( & V_2 -> V_10 -> V_20 ,
L_46 ,
V_112 , V_114 , error ) ;
break;
}
if ( memcmp ( & V_109 [ V_112 ] , V_5 , V_114 ) ) {
F_4 ( & V_2 -> V_10 -> V_20 ,
L_53 ,
V_112 , V_114 ) ;
#if V_122
F_49 ( V_123 ,
V_124 L_54 ,
V_125 , 16 , 1 ,
V_109 + V_108 , V_114 ,
false ) ;
F_49 ( V_123 ,
V_124 L_55 ,
V_125 , 16 , 1 ,
V_5 , V_113 , false ) ;
#endif
error = - V_81 ;
break;
}
}
F_47 ( V_5 ) ;
return error ? error : 0 ;
}
static int F_50 ( struct V_1 * V_2 ,
const T_1 * V_126 , T_4 V_127 , T_4 V_128 )
{
struct V_85 * V_10 = V_2 -> V_10 ;
int V_108 ;
T_2 V_106 ;
int error , V_129 ;
F_10 ( & V_10 -> V_20 , L_56 ) ;
error = F_40 ( V_2 ) ;
if ( error ) {
F_4 ( & V_10 -> V_20 ,
L_57 ,
error ) ;
return error ;
}
error = F_42 ( V_2 , & V_106 ) ;
if ( error )
goto V_130;
F_10 ( & V_10 -> V_20 ,
L_58 ,
V_113 , V_114 ) ;
for ( V_108 = V_128 ;
V_108 < V_128 + V_127 ;
V_108 += V_113 ) {
error = F_43 ( V_2 , V_108 , V_126 + V_108 ,
V_113 , V_106 ) ;
if ( error )
break;
error = F_48 ( V_2 , V_108 , V_126 + V_108 ,
V_113 , V_106 ) ;
if ( error )
break;
}
V_130:
F_10 ( & V_10 -> V_20 , L_59 ) ;
V_129 = F_41 ( V_2 ) ;
if ( V_129 ) {
F_4 ( & V_10 -> V_20 ,
L_60 , V_129 ) ;
if ( ! error )
error = V_129 ;
}
F_14 ( V_2 ) ;
F_11 ( V_2 ) ;
F_8 ( V_2 ) ;
F_51 ( V_2 -> V_55 , V_76 , 0 , V_2 -> V_40 , 0 , 0 ) ;
F_51 ( V_2 -> V_55 , V_77 , 0 , V_2 -> V_41 , 0 , 0 ) ;
F_51 ( V_2 -> V_55 , V_131 , 0 , V_2 -> V_40 , 0 , 0 ) ;
F_51 ( V_2 -> V_55 , V_132 , 0 , V_2 -> V_41 , 0 , 0 ) ;
F_52 ( V_2 -> V_55 , V_76 , V_2 -> V_45 ) ;
F_52 ( V_2 -> V_55 , V_77 , V_2 -> V_46 ) ;
F_52 ( V_2 -> V_55 , V_131 , V_2 -> V_45 ) ;
F_52 ( V_2 -> V_55 , V_132 , V_2 -> V_46 ) ;
return error ? error : 0 ;
}
static int F_53 ( struct V_1 * V_2 , const struct V_133 * V_134 ,
T_4 * V_135 , T_4 * V_127 ,
const struct V_136 * * V_137 )
{
const struct V_136 * V_138 ;
struct V_22 V_31 ;
T_2 V_139 ;
if ( V_134 -> V_73 < V_140 ) {
F_4 ( & V_2 -> V_10 -> V_20 ,
L_61 ,
V_140 , V_134 -> V_73 ) ;
return - V_81 ;
}
V_138 = ( const void * ) & V_134 -> V_109 [ V_134 -> V_73 - V_140 ] ;
#if V_122
F_49 ( V_141 , V_124 L_62 ,
V_125 , 16 , 1 , * V_138 , V_139 , false ) ;
#endif
V_139 = F_6 ( & V_138 -> V_139 ) ;
if ( V_139 != V_140 ) {
F_4 ( & V_2 -> V_10 -> V_20 ,
L_63 ,
V_139 , V_140 ) ;
return - V_81 ;
}
if ( memcmp ( V_138 -> V_142 , V_143 ,
sizeof( V_138 -> V_142 ) ) ) {
F_4 ( & V_2 -> V_10 -> V_20 ,
L_64 ,
( int ) sizeof( V_138 -> V_142 ) , V_138 -> V_142 ,
( int ) sizeof( V_138 -> V_142 ) , V_143 ) ;
return - V_81 ;
}
* V_135 = F_54 ( & V_138 -> V_144 ) ;
* V_127 = F_54 ( & V_138 -> V_145 ) ;
F_10 ( & V_2 -> V_10 -> V_20 ,
L_65 ,
* V_135 , * V_127 ) ;
if ( * V_127 % V_113 ) {
F_4 ( & V_2 -> V_10 -> V_20 ,
L_66 ,
* V_127 , V_113 ) ;
return - V_81 ;
}
if ( V_134 -> V_73 != * V_135 + * V_127 ) {
F_4 ( & V_2 -> V_10 -> V_20 ,
L_67 ,
* V_135 + * V_127 , V_134 -> V_73 ) ;
return - V_81 ;
}
F_5 ( ( const T_1 * ) & V_138 -> V_146 , & V_31 ) ;
F_10 ( & V_2 -> V_10 -> V_20 ,
L_68 ,
V_31 . V_24 , V_31 . V_25 ,
V_31 . V_26 , V_31 . V_27 ) ;
F_10 ( & V_2 -> V_10 -> V_20 , L_69 ,
V_2 -> V_31 . V_24 , V_2 -> V_31 . V_25 ,
V_2 -> V_31 . V_26 , V_2 -> V_31 . V_27 ) ;
if ( V_31 . V_24 != 0xEEEE && V_31 . V_24 != 0xFFFF &&
V_31 . V_25 == 0xEEEE &&
V_31 . V_26 == 0xEEEE &&
V_31 . V_27 == 0xEEEE ) {
F_10 ( & V_2 -> V_10 -> V_20 , L_70 ) ;
} else if ( V_31 . V_24 == 0xEEEE &&
V_31 . V_25 != 0xEEEE && V_31 . V_25 != 0xFFFF &&
V_31 . V_26 != 0xEEEE && V_31 . V_26 != 0xFFFF &&
V_31 . V_27 != 0xEEEE && V_31 . V_27 != 0xFFFF ) {
F_10 ( & V_2 -> V_10 -> V_20 , L_71 ) ;
} else {
F_4 ( & V_2 -> V_10 -> V_20 , L_72 ) ;
return - V_81 ;
}
return 0 ;
}
static int F_55 ( struct V_1 * V_2 , const struct V_133 * V_134 )
{
const struct V_136 * V_138 ;
T_4 V_147 ;
T_4 V_127 ;
int V_148 = 3 ;
int error ;
error = F_53 ( V_2 , V_134 ,
& V_147 , & V_127 , & V_138 ) ;
if ( error )
return error ;
if ( V_2 -> V_55 -> V_149 ) {
F_23 ( V_2 -> V_10 -> V_58 ) ;
} else {
error = F_11 ( V_2 ) ;
if ( error )
return error ;
}
do {
error = F_50 ( V_2 , V_134 -> V_109 , V_127 , V_147 ) ;
if ( ! error )
break;
} while ( -- V_148 );
if ( error )
F_4 ( & V_2 -> V_10 -> V_20 ,
L_73 , error ) ;
if ( V_2 -> V_55 -> V_149 )
F_21 ( V_2 -> V_10 -> V_58 ) ;
else
F_14 ( V_2 ) ;
return error ? error : 0 ;
}
static T_5 F_56 ( struct V_150 * V_20 ,
struct V_151 * V_152 ,
const char * V_12 , T_6 V_153 )
{
struct V_85 * V_10 = F_57 ( V_20 ) ;
struct V_1 * V_2 = F_58 ( V_10 ) ;
const struct V_133 * V_134 ;
int error ;
error = F_59 ( & V_134 , V_2 -> V_36 , V_20 ) ;
if ( error ) {
F_4 ( & V_2 -> V_10 -> V_20 ,
L_74 ,
V_2 -> V_36 , error ) ;
return error ;
}
F_60 ( & V_2 -> V_55 -> V_154 ) ;
error = F_55 ( V_2 , V_134 ) ;
F_61 ( & V_2 -> V_55 -> V_154 ) ;
F_62 ( V_134 ) ;
if ( error ) {
F_4 ( & V_2 -> V_10 -> V_20 ,
L_75 , error ) ;
return error ;
}
return V_153 ;
}
static T_5 F_63 ( struct V_150 * V_20 ,
struct V_151 * V_152 ,
char * V_12 )
{
struct V_85 * V_10 = F_57 ( V_20 ) ;
struct V_1 * V_2 = F_58 ( V_10 ) ;
T_6 V_153 ;
F_60 ( & V_2 -> V_55 -> V_154 ) ;
V_153 = snprintf ( V_12 , V_155 , L_76 ,
V_2 -> V_31 . V_24 , V_2 -> V_31 . V_25 ,
V_2 -> V_31 . V_26 , V_2 -> V_31 . V_27 ) ;
F_61 ( & V_2 -> V_55 -> V_154 ) ;
return V_153 ;
}
static T_5 F_64 ( struct V_150 * V_20 ,
struct V_151 * V_152 ,
char * V_12 )
{
struct V_85 * V_10 = F_57 ( V_20 ) ;
struct V_1 * V_2 = F_58 ( V_10 ) ;
T_6 V_153 ;
F_60 ( & V_2 -> V_55 -> V_154 ) ;
V_153 = snprintf ( V_12 , V_155 , L_77 ,
( int ) sizeof( V_2 -> V_33 ) , V_2 -> V_33 ) ;
F_61 ( & V_2 -> V_55 -> V_154 ) ;
return V_153 ;
}
static T_5 F_65 ( struct V_150 * V_20 ,
struct V_151 * V_152 ,
char * V_12 )
{
struct V_85 * V_10 = F_57 ( V_20 ) ;
struct V_1 * V_2 = F_58 ( V_10 ) ;
T_6 V_153 ;
F_60 ( & V_2 -> V_55 -> V_154 ) ;
V_153 = snprintf ( V_12 , V_155 , L_78 , V_2 -> V_35 ) ;
F_61 ( & V_2 -> V_55 -> V_154 ) ;
return V_153 ;
}
static T_5 F_66 ( struct V_150 * V_20 ,
struct V_151 * V_152 ,
char * V_12 )
{
struct V_85 * V_10 = F_57 ( V_20 ) ;
struct V_1 * V_2 = F_58 ( V_10 ) ;
T_6 V_153 ;
F_60 ( & V_2 -> V_55 -> V_154 ) ;
V_153 = snprintf ( V_12 , V_155 , L_77 ,
( int ) sizeof( V_2 -> V_38 ) , V_2 -> V_38 ) ;
F_61 ( & V_2 -> V_55 -> V_154 ) ;
return V_153 ;
}
static void F_67 ( void * V_156 )
{
struct V_1 * V_2 = V_156 ;
F_68 ( & V_2 -> V_10 -> V_20 . V_157 , & V_158 ) ;
}
static int F_69 ( struct V_85 * V_10 , const struct V_159 * V_65 )
{
struct V_1 * V_2 ;
struct V_91 * V_55 ;
int error ;
if ( ! F_70 ( V_10 -> V_18 , V_160 ) ) {
F_4 ( & V_10 -> V_20 , L_79 ) ;
return - V_161 ;
}
V_2 = F_71 ( & V_10 -> V_20 , sizeof( * V_2 ) , V_115 ) ;
if ( ! V_2 )
return - V_116 ;
V_55 = F_72 ( & V_10 -> V_20 ) ;
if ( ! V_55 )
return - V_116 ;
V_2 -> V_10 = V_10 ;
V_2 -> V_55 = V_55 ;
snprintf ( V_2 -> V_162 , sizeof( V_2 -> V_162 ) ,
L_80 , F_73 ( & V_10 -> V_20 ) ) ;
V_2 -> V_52 = F_74 ( & V_10 -> V_20 ,
L_81 , V_163 ) ;
if ( F_75 ( V_2 -> V_52 ) ) {
error = F_76 ( V_2 -> V_52 ) ;
if ( error != V_164 )
F_4 ( & V_10 -> V_20 ,
L_82 , error ) ;
return error ;
}
error = F_11 ( V_2 ) ;
if ( error )
return error ;
error = F_8 ( V_2 ) ;
F_14 ( V_2 ) ;
if ( error )
return error ;
V_55 -> V_165 = L_83 ;
V_55 -> V_162 = V_2 -> V_162 ;
V_55 -> V_65 . V_166 = V_167 ;
V_55 -> V_65 . V_168 = 0x13c5 ;
V_55 -> V_65 . V_169 = V_2 -> V_35 ;
V_55 -> V_170 = F_33 ;
V_55 -> V_171 = F_35 ;
F_77 ( V_55 , V_2 ) ;
V_55 -> V_62 = V_2 -> V_57 ;
V_55 -> V_172 = sizeof( * V_2 -> V_57 ) ;
V_55 -> V_173 = V_2 -> V_47 ;
F_51 ( V_55 , V_76 , 0 , V_2 -> V_40 , 0 , 0 ) ;
F_51 ( V_55 , V_77 , 0 , V_2 -> V_41 , 0 , 0 ) ;
F_51 ( V_55 , V_78 ,
V_174 , V_175 , 0 , 0 ) ;
F_51 ( V_55 , V_79 ,
V_176 , V_177 , 0 , 0 ) ;
F_51 ( V_55 , V_80 ,
V_178 , V_179 , 0 , 0 ) ;
F_52 ( V_2 -> V_55 , V_76 , V_2 -> V_45 ) ;
F_52 ( V_2 -> V_55 , V_77 , V_2 -> V_46 ) ;
error = F_78 ( V_55 , V_54 , V_180 ) ;
if ( error )
return error ;
F_79 ( V_10 , V_2 ) ;
error = F_80 ( & V_10 -> V_20 , V_10 -> V_58 ,
NULL , F_32 ,
V_181 , V_124 , V_2 ) ;
if ( error ) {
F_4 ( & V_10 -> V_20 ,
L_84 ,
V_10 -> V_58 , error ) ;
return error ;
}
F_23 ( V_10 -> V_58 ) ;
error = F_81 ( V_55 ) ;
if ( error ) {
F_4 ( & V_10 -> V_20 ,
L_85 , error ) ;
return error ;
}
error = F_82 ( & V_10 -> V_20 . V_157 , & V_158 ) ;
if ( error ) {
F_4 ( & V_10 -> V_20 ,
L_86 , error ) ;
return error ;
}
error = F_83 ( & V_10 -> V_20 , F_67 , V_2 ) ;
if ( error ) {
F_67 ( V_2 ) ;
F_4 ( & V_10 -> V_20 ,
L_87 , error ) ;
return error ;
}
return 0 ;
}
static int T_7 F_84 ( struct V_150 * V_20 )
{
struct V_85 * V_10 = F_57 ( V_20 ) ;
struct V_1 * V_2 = F_58 ( V_10 ) ;
struct V_91 * V_55 = V_2 -> V_55 ;
F_60 ( & V_55 -> V_154 ) ;
if ( F_85 ( V_20 ) )
V_2 -> V_182 = F_86 ( V_10 -> V_58 ) == 0 ;
else if ( V_55 -> V_149 )
F_22 ( V_2 ) ;
F_61 ( & V_55 -> V_154 ) ;
return 0 ;
}
static int T_7 F_87 ( struct V_150 * V_20 )
{
struct V_85 * V_10 = F_57 ( V_20 ) ;
struct V_1 * V_2 = F_58 ( V_10 ) ;
struct V_91 * V_55 = V_2 -> V_55 ;
F_60 ( & V_55 -> V_154 ) ;
if ( V_2 -> V_182 )
F_88 ( V_10 -> V_58 ) ;
else if ( V_55 -> V_149 )
F_20 ( V_2 ) ;
F_61 ( & V_55 -> V_154 ) ;
return 0 ;
}
