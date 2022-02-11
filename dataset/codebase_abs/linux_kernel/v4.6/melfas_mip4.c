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
error = F_7 ( V_2 ) ;
if ( error )
F_9 ( & V_2 -> V_10 -> V_20 ,
L_4 , error ) ;
else
F_10 ( & V_2 -> V_10 -> V_20 , L_5 ,
V_2 -> V_31 . V_24 , V_2 -> V_31 . V_25 ,
V_2 -> V_31 . V_26 , V_2 -> V_31 . V_27 ) ;
V_28 [ 0 ] = V_29 ;
V_28 [ 1 ] = V_34 ;
error = F_1 ( V_2 , V_28 , sizeof( V_28 ) , V_12 , 14 ) ;
if ( error ) {
F_9 ( & V_2 -> V_10 -> V_20 ,
L_6 ,
error ) ;
} else {
V_2 -> V_35 = F_6 ( & V_12 [ 0 ] ) ;
V_2 -> V_36 = F_6 ( & V_12 [ 2 ] ) ;
F_10 ( & V_2 -> V_10 -> V_20 , L_7 ,
V_2 -> V_35 , V_2 -> V_36 ) ;
V_2 -> V_37 = V_12 [ 4 ] ;
V_2 -> V_38 = V_12 [ 5 ] ;
V_2 -> V_39 = V_12 [ 6 ] ;
F_10 ( & V_2 -> V_10 -> V_20 ,
L_8 ,
V_2 -> V_37 , V_2 -> V_38 , V_2 -> V_39 ) ;
V_2 -> V_40 = V_12 [ 12 ] ;
V_2 -> V_41 = V_12 [ 13 ] ;
F_10 ( & V_2 -> V_10 -> V_20 , L_9 ,
V_2 -> V_40 , V_2 -> V_41 ) ;
if ( V_2 -> V_39 > 0 )
V_2 -> V_42 = V_2 -> V_39 ;
}
V_28 [ 0 ] = V_43 ;
V_28 [ 1 ] = V_44 ;
error = F_1 ( V_2 , V_28 , sizeof( V_28 ) , V_12 , 7 ) ;
if ( error ) {
F_9 ( & V_2 -> V_10 -> V_20 ,
L_10 , error ) ;
V_2 -> V_45 = 0xff ;
} else {
V_2 -> V_45 = F_6 ( & V_12 [ 4 ] ) ;
V_2 -> V_46 = V_12 [ 6 ] ;
F_10 ( & V_2 -> V_10 -> V_20 , L_11 ,
V_2 -> V_45 , V_2 -> V_46 ) ;
if ( V_2 -> V_45 == 2 || V_2 -> V_45 > 3 )
F_9 ( & V_2 -> V_10 -> V_20 ,
L_12 , V_2 -> V_45 ) ;
}
return 0 ;
}
static int F_11 ( struct V_1 * V_2 )
{
if ( V_2 -> V_47 ) {
F_12 ( V_2 -> V_47 , 1 ) ;
F_13 ( 200 * 1000 , 300 * 1000 ) ;
}
return 0 ;
}
static void F_14 ( struct V_1 * V_2 )
{
if ( V_2 -> V_47 )
F_12 ( V_2 -> V_47 , 0 ) ;
}
static void F_15 ( struct V_1 * V_2 )
{
int V_48 ;
for ( V_48 = 0 ; V_48 < V_49 ; V_48 ++ ) {
F_16 ( V_2 -> V_50 , V_48 ) ;
F_17 ( V_2 -> V_50 , V_51 , 0 ) ;
}
for ( V_48 = 0 ; V_48 < V_2 -> V_42 ; V_48 ++ )
F_18 ( V_2 -> V_50 , V_2 -> V_52 [ V_48 ] , 0 ) ;
F_19 ( V_2 -> V_50 ) ;
}
static int F_20 ( struct V_1 * V_2 )
{
int error ;
error = F_11 ( V_2 ) ;
if ( error )
return error ;
F_21 ( V_2 -> V_10 -> V_53 ) ;
return 0 ;
}
static void F_22 ( struct V_1 * V_2 )
{
F_23 ( V_2 -> V_10 -> V_53 ) ;
F_14 ( V_2 ) ;
F_15 ( V_2 ) ;
}
static void F_24 ( struct V_1 * V_2 , T_1 * V_54 )
{
T_1 V_55 ;
bool V_56 ;
switch ( V_2 -> V_45 ) {
case 0 :
case 1 :
V_55 = V_54 [ 0 ] & 0x0F ;
V_56 = V_54 [ 0 ] & 0x80 ;
break;
case 3 :
default:
V_55 = V_54 [ 0 ] & 0x0F ;
V_56 = V_54 [ 1 ] & 0x01 ;
break;
}
if ( V_55 >= 1 && V_55 <= V_2 -> V_42 ) {
unsigned short V_57 = V_2 -> V_52 [ V_55 - 1 ] ;
F_10 ( & V_2 -> V_10 -> V_20 ,
L_13 ,
V_55 , V_57 , V_56 ) ;
F_25 ( V_2 -> V_50 , V_58 , V_59 , V_57 ) ;
F_18 ( V_2 -> V_50 , V_57 , V_56 ) ;
} else {
F_4 ( & V_2 -> V_10 -> V_20 , L_14 , V_55 ) ;
}
}
static void F_26 ( struct V_1 * V_2 , T_1 * V_54 )
{
int V_60 ;
bool V_61 ;
bool V_62 ;
bool V_63 ;
T_2 V_64 , V_65 ;
T_1 V_66 = 0 ;
T_1 V_67 ;
T_1 V_68 ;
T_1 V_69 ;
T_1 V_70 ;
switch ( V_2 -> V_45 ) {
case 0 :
case 1 :
V_63 = V_54 [ 0 ] & F_27 ( 7 ) ;
V_61 = V_54 [ 0 ] & F_27 ( 5 ) ;
V_62 = V_54 [ 0 ] & F_27 ( 4 ) ;
V_60 = ( V_54 [ 0 ] & 0x0F ) - 1 ;
V_64 = ( ( V_54 [ 1 ] & 0x0F ) << 8 ) | V_54 [ 2 ] ;
V_65 = ( ( ( V_54 [ 1 ] >> 4 ) & 0x0F ) << 8 ) |
V_54 [ 3 ] ;
V_67 = V_54 [ 4 ] ;
V_68 = V_54 [ 5 ] ;
if ( V_2 -> V_45 == 0 ) {
V_69 = V_54 [ 5 ] ;
V_70 = V_54 [ 5 ] ;
} else {
V_69 = V_54 [ 6 ] ;
V_70 = V_54 [ 7 ] ;
}
break;
case 3 :
default:
V_60 = ( V_54 [ 0 ] & 0x0F ) - 1 ;
V_61 = V_54 [ 1 ] & F_27 ( 2 ) ;
V_62 = V_54 [ 1 ] & F_27 ( 1 ) ;
V_63 = V_54 [ 1 ] & F_27 ( 0 ) ;
V_64 = ( ( V_54 [ 2 ] & 0x0F ) << 8 ) | V_54 [ 3 ] ;
V_65 = ( ( ( V_54 [ 2 ] >> 4 ) & 0x0F ) << 8 ) |
V_54 [ 4 ] ;
V_68 = V_54 [ 6 ] ;
V_66 = ( V_54 [ 7 ] & 0xF0 ) >> 4 ;
V_67 = ( ( V_54 [ 7 ] & 0x0F ) << 8 ) |
V_54 [ 8 ] ;
V_69 = V_54 [ 9 ] ;
V_70 = V_54 [ 10 ] ;
break;
}
F_10 ( & V_2 -> V_10 -> V_20 ,
L_15 ,
V_60 , V_63 , V_64 , V_65 , V_67 ) ;
if ( F_28 ( V_60 < 0 || V_60 >= V_49 ) ) {
F_4 ( & V_2 -> V_10 -> V_20 , L_16 , V_60 ) ;
} else if ( V_63 ) {
F_16 ( V_2 -> V_50 , V_60 ) ;
F_17 ( V_2 -> V_50 , V_51 , true ) ;
F_29 ( V_2 -> V_50 , V_71 , V_64 ) ;
F_29 ( V_2 -> V_50 , V_72 , V_65 ) ;
F_29 ( V_2 -> V_50 , V_73 , V_67 ) ;
F_29 ( V_2 -> V_50 , V_74 , V_69 ) ;
F_29 ( V_2 -> V_50 , V_75 , V_70 ) ;
} else {
F_16 ( V_2 -> V_50 , V_60 ) ;
F_17 ( V_2 -> V_50 , V_51 , 0 ) ;
}
F_30 ( V_2 -> V_50 ) ;
}
static int F_31 ( struct V_1 * V_2 , T_1 * V_54 )
{
T_1 type ;
switch ( V_2 -> V_45 ) {
case 0 :
case 1 :
type = ( V_54 [ 0 ] & 0x40 ) >> 6 ;
break;
case 3 :
type = ( V_54 [ 0 ] & 0xF0 ) >> 4 ;
break;
default:
return - V_76 ;
}
F_10 ( & V_2 -> V_10 -> V_20 , L_17 , type ) ;
switch ( type ) {
case V_77 :
F_24 ( V_2 , V_54 ) ;
break;
case V_78 :
F_26 ( V_2 , V_54 ) ;
break;
default:
F_4 ( & V_2 -> V_10 -> V_20 , L_18 , type ) ;
break;
}
return 0 ;
}
static T_3 F_32 ( int V_53 , void * V_79 )
{
struct V_1 * V_2 = V_79 ;
struct V_80 * V_10 = V_2 -> V_10 ;
unsigned int V_48 ;
int error ;
T_1 V_28 [ 2 ] ;
T_1 V_68 ;
bool V_81 ;
V_28 [ 0 ] = V_43 ;
V_28 [ 1 ] = V_82 ;
error = F_1 ( V_2 , V_28 , sizeof( V_28 ) , V_2 -> V_12 , 1 ) ;
if ( error ) {
F_4 ( & V_10 -> V_20 ,
L_19 , error ) ;
goto V_83;
}
V_68 = V_2 -> V_12 [ 0 ] & 0x7F ;
V_81 = V_2 -> V_12 [ 0 ] & F_27 ( 7 ) ;
F_10 ( & V_10 -> V_20 , L_20 , V_68 , V_81 ) ;
if ( ! V_68 ) {
F_4 ( & V_10 -> V_20 , L_21 ) ;
goto V_83;
}
V_28 [ 0 ] = V_43 ;
V_28 [ 1 ] = V_84 ;
error = F_1 ( V_2 , V_28 , sizeof( V_28 ) , V_2 -> V_12 , V_68 ) ;
if ( error ) {
F_4 ( & V_10 -> V_20 ,
L_22 , error ) ;
goto V_83;
}
if ( V_81 ) {
F_10 ( & V_10 -> V_20 , L_23 , V_2 -> V_12 [ 0 ] ) ;
} else {
for ( V_48 = 0 ; V_48 < V_68 ; V_48 += V_2 -> V_46 ) {
error = F_31 ( V_2 , & V_2 -> V_12 [ V_48 ] ) ;
if ( error )
break;
}
F_19 ( V_2 -> V_50 ) ;
}
V_83:
return V_85 ;
}
static int F_33 ( struct V_86 * V_20 )
{
struct V_1 * V_2 = F_34 ( V_20 ) ;
return F_20 ( V_2 ) ;
}
static void F_35 ( struct V_86 * V_20 )
{
struct V_1 * V_2 = F_34 ( V_20 ) ;
F_22 ( V_2 ) ;
}
static int F_36 ( struct V_1 * V_2 )
{
T_1 V_28 [] = { V_87 , V_88 } ;
T_1 V_89 ;
struct V_7 V_8 [] = {
{
. V_9 = V_2 -> V_10 -> V_9 ,
. V_11 = 0 ,
. V_12 = V_28 ,
. V_13 = sizeof( V_28 ) ,
} , {
. V_9 = V_2 -> V_10 -> V_9 ,
. V_11 = V_14 ,
. V_12 = & V_89 ,
. V_13 = sizeof( V_89 ) ,
} ,
} ;
int V_90 ;
int error ;
int V_15 = 1000 ;
do {
V_90 = F_2 ( V_2 -> V_10 -> V_18 , V_8 , F_3 ( V_8 ) ) ;
if ( V_90 != F_3 ( V_8 ) ) {
error = V_90 < 0 ? V_90 : - V_19 ;
F_4 ( & V_2 -> V_10 -> V_20 ,
L_24 ,
error ) ;
return error ;
}
switch ( V_89 ) {
case V_91 :
F_10 ( & V_2 -> V_10 -> V_20 , L_25 , V_21 ) ;
return 0 ;
case V_92 :
F_4 ( & V_2 -> V_10 -> V_20 , L_26 ) ;
return - V_19 ;
case V_93 :
F_10 ( & V_2 -> V_10 -> V_20 , L_27 , V_21 ) ;
error = - V_94 ;
break;
default:
F_4 ( & V_2 -> V_10 -> V_20 ,
L_28 ,
V_89 ) ;
error = - V_76 ;
break;
}
F_13 ( 1000 , 2000 ) ;
} while ( -- V_15 );
return error ;
}
static int F_37 ( struct V_1 * V_2 , T_1 V_95 )
{
T_1 V_96 [] = { V_87 , V_97 , V_95 } ;
T_1 V_98 [] = { V_87 , V_97 } ;
T_1 V_89 ;
struct V_7 V_8 [] = {
{
. V_9 = V_2 -> V_10 -> V_9 ,
. V_11 = 0 ,
. V_12 = V_98 ,
. V_13 = sizeof( V_98 ) ,
} , {
. V_9 = V_2 -> V_10 -> V_9 ,
. V_11 = V_14 ,
. V_12 = & V_89 ,
. V_13 = sizeof( V_89 ) ,
} ,
} ;
int V_15 = 10 ;
int V_90 ;
int error ;
do {
V_90 = F_38 ( V_2 -> V_10 ,
V_96 , sizeof( V_96 ) ) ;
if ( V_90 != sizeof( V_96 ) ) {
error = V_90 < 0 ? V_90 : - V_19 ;
F_4 ( & V_2 -> V_10 -> V_20 ,
L_29 ,
V_95 , error , V_90 ) ;
return error ;
}
F_10 ( & V_2 -> V_10 -> V_20 ,
L_30 , V_95 ) ;
F_39 ( 1000 ) ;
V_90 = F_2 ( V_2 -> V_10 -> V_18 , V_8 , F_3 ( V_8 ) ) ;
if ( V_90 != F_3 ( V_8 ) ) {
error = V_90 < 0 ? V_90 : - V_19 ;
F_4 ( & V_2 -> V_10 -> V_20 ,
L_31 , error ) ;
return error ;
}
F_10 ( & V_2 -> V_10 -> V_20 ,
L_32 , V_89 , V_95 ) ;
if ( V_89 == V_95 )
return 0 ;
} while ( -- V_15 );
return - V_19 ;
}
static int F_40 ( struct V_1 * V_2 )
{
return F_37 ( V_2 , V_99 ) ;
}
static int F_41 ( struct V_1 * V_2 )
{
return F_37 ( V_2 , V_100 ) ;
}
static int F_42 ( struct V_1 * V_2 , T_2 * V_101 )
{
T_1 V_28 [] = { V_87 , V_102 } ;
T_1 V_89 [ sizeof( T_2 ) ] ;
struct V_7 V_8 [] = {
{
. V_9 = V_2 -> V_10 -> V_9 ,
. V_11 = 0 ,
. V_12 = V_28 ,
. V_13 = sizeof( V_28 ) ,
} , {
. V_9 = V_2 -> V_10 -> V_9 ,
. V_11 = V_14 ,
. V_12 = V_89 ,
. V_13 = sizeof( V_89 ) ,
} ,
} ;
int V_90 ;
int error ;
V_90 = F_2 ( V_2 -> V_10 -> V_18 , V_8 , F_3 ( V_8 ) ) ;
if ( V_90 != F_3 ( V_8 ) ) {
error = V_90 < 0 ? V_90 : - V_19 ;
F_4 ( & V_2 -> V_10 -> V_20 ,
L_33 ,
error ) ;
return error ;
}
* V_101 = F_6 ( V_89 ) ;
F_10 ( & V_2 -> V_10 -> V_20 ,
L_34 , * V_101 ) ;
return 0 ;
}
static int F_43 ( struct V_1 * V_2 , int V_103 ,
const T_1 * V_104 , int V_105 , T_2 V_101 )
{
T_1 V_28 [ 6 ] ;
T_1 * V_106 ;
T_2 V_107 ;
int V_90 ;
int error ;
F_10 ( & V_2 -> V_10 -> V_20 , L_35 ,
V_103 , V_105 ) ;
if ( V_105 > V_108 || V_105 % V_109 ) {
F_4 ( & V_2 -> V_10 -> V_20 ,
L_36 , V_105 ) ;
return - V_76 ;
}
V_106 = F_44 ( 2 + V_109 , V_110 ) ;
if ( ! V_106 )
return - V_111 ;
V_28 [ 0 ] = V_87 ;
V_28 [ 1 ] = V_112 ;
F_45 ( V_103 , & V_28 [ 2 ] ) ;
V_90 = F_38 ( V_2 -> V_10 , V_28 , 6 ) ;
if ( V_90 != 6 ) {
error = V_90 < 0 ? V_90 : - V_19 ;
F_4 ( & V_2 -> V_10 -> V_20 ,
L_37 , error ) ;
goto V_83;
}
V_28 [ 0 ] = V_87 ;
V_28 [ 1 ] = V_113 ;
F_45 ( V_105 , & V_28 [ 2 ] ) ;
V_90 = F_38 ( V_2 -> V_10 , V_28 , 6 ) ;
if ( V_90 != 6 ) {
error = V_90 < 0 ? V_90 : - V_19 ;
F_4 ( & V_2 -> V_10 -> V_20 ,
L_38 , error ) ;
goto V_83;
}
for ( V_107 = 0 ;
V_107 < V_105 ;
V_107 += V_109 ) {
F_10 ( & V_2 -> V_10 -> V_20 ,
L_39 ,
V_107 , V_109 ) ;
F_46 ( V_101 + V_107 , V_106 ) ;
memcpy ( & V_106 [ 2 ] , & V_104 [ V_107 ] , V_109 ) ;
V_90 = F_38 ( V_2 -> V_10 ,
V_106 , 2 + V_109 ) ;
if ( V_90 != 2 + V_109 ) {
error = V_90 < 0 ? V_90 : - V_19 ;
F_4 ( & V_2 -> V_10 -> V_20 ,
L_40 ,
V_107 , V_109 , error ) ;
goto V_83;
}
}
V_28 [ 0 ] = V_87 ;
V_28 [ 1 ] = V_114 ;
V_28 [ 2 ] = V_115 ;
V_90 = F_38 ( V_2 -> V_10 , V_28 , 3 ) ;
if ( V_90 != 3 ) {
error = V_90 < 0 ? V_90 : - V_19 ;
F_4 ( & V_2 -> V_10 -> V_20 ,
L_41 , error ) ;
goto V_83;
}
error = F_36 ( V_2 ) ;
V_83:
F_47 ( V_106 ) ;
return error ? error : 0 ;
}
static int F_48 ( struct V_1 * V_2 , int V_103 ,
const T_1 * V_104 , int V_105 , int V_101 )
{
T_1 V_28 [ 8 ] ;
T_1 * V_5 ;
int V_107 ;
struct V_7 V_8 [] = {
{
. V_9 = V_2 -> V_10 -> V_9 ,
. V_11 = 0 ,
. V_12 = V_28 ,
. V_13 = 2 ,
} , {
. V_9 = V_2 -> V_10 -> V_9 ,
. V_11 = V_14 ,
. V_13 = V_109 ,
} ,
} ;
int V_90 ;
int error ;
F_10 ( & V_2 -> V_10 -> V_20 , L_42 ,
V_103 , V_105 ) ;
V_28 [ 0 ] = V_87 ;
V_28 [ 1 ] = V_112 ;
F_45 ( V_103 , & V_28 [ 2 ] ) ;
V_90 = F_38 ( V_2 -> V_10 , V_28 , 6 ) ;
if ( V_90 != 6 ) {
error = V_90 < 0 ? V_90 : - V_19 ;
F_4 ( & V_2 -> V_10 -> V_20 ,
L_43 , error ) ;
return error ;
}
V_28 [ 0 ] = V_87 ;
V_28 [ 1 ] = V_113 ;
F_45 ( V_105 , & V_28 [ 2 ] ) ;
V_90 = F_38 ( V_2 -> V_10 , V_28 , 6 ) ;
if ( V_90 != 6 ) {
error = V_90 < 0 ? V_90 : - V_19 ;
F_4 ( & V_2 -> V_10 -> V_20 ,
L_44 , error ) ;
return error ;
}
V_28 [ 0 ] = V_87 ;
V_28 [ 1 ] = V_114 ;
V_28 [ 2 ] = V_116 ;
V_90 = F_38 ( V_2 -> V_10 , V_28 , 3 ) ;
if ( V_90 != 3 ) {
error = V_90 < 0 ? V_90 : - V_19 ;
F_4 ( & V_2 -> V_10 -> V_20 ,
L_45 , error ) ;
return error ;
}
error = F_36 ( V_2 ) ;
if ( error )
return error ;
V_8 [ 1 ] . V_12 = V_5 = F_44 ( V_109 , V_110 ) ;
if ( ! V_5 )
return - V_111 ;
for ( V_107 = 0 ;
V_107 < V_105 ;
V_107 += V_109 ) {
F_10 ( & V_2 -> V_10 -> V_20 ,
L_46 ,
V_107 , V_109 ) ;
F_46 ( V_101 + V_107 , V_28 ) ;
V_90 = F_2 ( V_2 -> V_10 -> V_18 , V_8 , F_3 ( V_8 ) ) ;
if ( V_90 != F_3 ( V_8 ) ) {
error = V_90 < 0 ? V_90 : - V_19 ;
F_4 ( & V_2 -> V_10 -> V_20 ,
L_40 ,
V_107 , V_109 , error ) ;
break;
}
if ( memcmp ( & V_104 [ V_107 ] , V_5 , V_109 ) ) {
F_4 ( & V_2 -> V_10 -> V_20 ,
L_47 ,
V_107 , V_109 ) ;
#if V_117
F_49 ( V_118 ,
V_119 L_48 ,
V_120 , 16 , 1 ,
V_104 + V_103 , V_109 ,
false ) ;
F_49 ( V_118 ,
V_119 L_49 ,
V_120 , 16 , 1 ,
V_5 , V_108 , false ) ;
#endif
error = - V_76 ;
break;
}
}
F_47 ( V_5 ) ;
return error ? error : 0 ;
}
static int F_50 ( struct V_1 * V_2 ,
const T_1 * V_121 , T_4 V_122 , T_4 V_123 )
{
struct V_80 * V_10 = V_2 -> V_10 ;
int V_103 ;
T_2 V_101 ;
int error , V_124 ;
F_10 ( & V_10 -> V_20 , L_50 ) ;
error = F_40 ( V_2 ) ;
if ( error ) {
F_4 ( & V_10 -> V_20 ,
L_51 ,
error ) ;
return error ;
}
error = F_42 ( V_2 , & V_101 ) ;
if ( error )
goto V_125;
F_10 ( & V_10 -> V_20 ,
L_52 ,
V_108 , V_109 ) ;
for ( V_103 = V_123 ;
V_103 < V_123 + V_122 ;
V_103 += V_108 ) {
error = F_43 ( V_2 , V_103 , V_121 + V_103 ,
V_108 , V_101 ) ;
if ( error )
break;
error = F_48 ( V_2 , V_103 , V_121 + V_103 ,
V_108 , V_101 ) ;
if ( error )
break;
}
V_125:
F_10 ( & V_10 -> V_20 , L_53 ) ;
V_124 = F_41 ( V_2 ) ;
if ( V_124 ) {
F_4 ( & V_10 -> V_20 ,
L_54 , V_124 ) ;
if ( ! error )
error = V_124 ;
}
F_14 ( V_2 ) ;
F_11 ( V_2 ) ;
F_8 ( V_2 ) ;
F_51 ( V_2 -> V_50 , V_71 , 0 , V_2 -> V_35 , 0 , 0 ) ;
F_51 ( V_2 -> V_50 , V_72 , 0 , V_2 -> V_36 , 0 , 0 ) ;
F_51 ( V_2 -> V_50 , V_126 , 0 , V_2 -> V_35 , 0 , 0 ) ;
F_51 ( V_2 -> V_50 , V_127 , 0 , V_2 -> V_36 , 0 , 0 ) ;
F_52 ( V_2 -> V_50 , V_71 , V_2 -> V_40 ) ;
F_52 ( V_2 -> V_50 , V_72 , V_2 -> V_41 ) ;
F_52 ( V_2 -> V_50 , V_126 , V_2 -> V_40 ) ;
F_52 ( V_2 -> V_50 , V_127 , V_2 -> V_41 ) ;
return error ? error : 0 ;
}
static int F_53 ( struct V_1 * V_2 , const struct V_128 * V_129 ,
T_4 * V_130 , T_4 * V_122 ,
const struct V_131 * * V_132 )
{
const struct V_131 * V_133 ;
struct V_22 V_31 ;
T_2 V_134 ;
if ( V_129 -> V_68 < V_135 ) {
F_4 ( & V_2 -> V_10 -> V_20 ,
L_55 ,
V_135 , V_129 -> V_68 ) ;
return - V_76 ;
}
V_133 = ( const void * ) & V_129 -> V_104 [ V_129 -> V_68 - V_135 ] ;
#if V_117
F_49 ( V_136 , V_119 L_56 ,
V_120 , 16 , 1 , * V_133 , V_134 , false ) ;
#endif
V_134 = F_6 ( & V_133 -> V_134 ) ;
if ( V_134 != V_135 ) {
F_4 ( & V_2 -> V_10 -> V_20 ,
L_57 ,
V_134 , V_135 ) ;
return - V_76 ;
}
if ( memcmp ( V_133 -> V_137 , V_138 ,
sizeof( V_133 -> V_137 ) ) ) {
F_4 ( & V_2 -> V_10 -> V_20 ,
L_58 ,
( int ) sizeof( V_133 -> V_137 ) , V_133 -> V_137 ,
( int ) sizeof( V_133 -> V_137 ) , V_138 ) ;
return - V_76 ;
}
* V_130 = F_54 ( & V_133 -> V_139 ) ;
* V_122 = F_54 ( & V_133 -> V_140 ) ;
F_10 ( & V_2 -> V_10 -> V_20 ,
L_59 ,
* V_130 , * V_122 ) ;
if ( * V_122 % V_108 ) {
F_4 ( & V_2 -> V_10 -> V_20 ,
L_60 ,
* V_122 , V_108 ) ;
return - V_76 ;
}
if ( V_129 -> V_68 != * V_130 + * V_122 ) {
F_4 ( & V_2 -> V_10 -> V_20 ,
L_61 ,
* V_130 + * V_122 , V_129 -> V_68 ) ;
return - V_76 ;
}
F_5 ( ( const T_1 * ) & V_133 -> V_141 , & V_31 ) ;
F_10 ( & V_2 -> V_10 -> V_20 ,
L_62 ,
V_31 . V_24 , V_31 . V_25 ,
V_31 . V_26 , V_31 . V_27 ) ;
F_10 ( & V_2 -> V_10 -> V_20 , L_63 ,
V_2 -> V_31 . V_24 , V_2 -> V_31 . V_25 ,
V_2 -> V_31 . V_26 , V_2 -> V_31 . V_27 ) ;
if ( V_31 . V_24 != 0xEEEE && V_31 . V_24 != 0xFFFF &&
V_31 . V_25 == 0xEEEE &&
V_31 . V_26 == 0xEEEE &&
V_31 . V_27 == 0xEEEE ) {
F_10 ( & V_2 -> V_10 -> V_20 , L_64 ) ;
} else if ( V_31 . V_24 == 0xEEEE &&
V_31 . V_25 != 0xEEEE && V_31 . V_25 != 0xFFFF &&
V_31 . V_26 != 0xEEEE && V_31 . V_26 != 0xFFFF &&
V_31 . V_27 != 0xEEEE && V_31 . V_27 != 0xFFFF ) {
F_10 ( & V_2 -> V_10 -> V_20 , L_65 ) ;
} else {
F_4 ( & V_2 -> V_10 -> V_20 , L_66 ) ;
return - V_76 ;
}
return 0 ;
}
static int F_55 ( struct V_1 * V_2 , const struct V_128 * V_129 )
{
const struct V_131 * V_133 ;
T_4 V_142 ;
T_4 V_122 ;
int V_143 = 3 ;
int error ;
error = F_53 ( V_2 , V_129 ,
& V_142 , & V_122 , & V_133 ) ;
if ( error )
return error ;
if ( V_2 -> V_50 -> V_144 ) {
F_23 ( V_2 -> V_10 -> V_53 ) ;
} else {
error = F_11 ( V_2 ) ;
if ( error )
return error ;
}
do {
error = F_50 ( V_2 , V_129 -> V_104 , V_122 , V_142 ) ;
if ( ! error )
break;
} while ( -- V_143 );
if ( error )
F_4 ( & V_2 -> V_10 -> V_20 ,
L_67 , error ) ;
if ( V_2 -> V_50 -> V_144 )
F_21 ( V_2 -> V_10 -> V_53 ) ;
else
F_14 ( V_2 ) ;
return error ? error : 0 ;
}
static T_5 F_56 ( struct V_145 * V_20 ,
struct V_146 * V_147 ,
const char * V_12 , T_6 V_148 )
{
struct V_80 * V_10 = F_57 ( V_20 ) ;
struct V_1 * V_2 = F_58 ( V_10 ) ;
const struct V_128 * V_129 ;
int error ;
error = F_59 ( & V_129 , V_149 , V_20 ) ;
if ( error ) {
F_4 ( & V_2 -> V_10 -> V_20 ,
L_68 ,
V_149 , error ) ;
return error ;
}
F_60 ( & V_2 -> V_50 -> V_150 ) ;
error = F_55 ( V_2 , V_129 ) ;
F_61 ( & V_2 -> V_50 -> V_150 ) ;
F_62 ( V_129 ) ;
if ( error ) {
F_4 ( & V_2 -> V_10 -> V_20 ,
L_69 , error ) ;
return error ;
}
return V_148 ;
}
static T_5 F_63 ( struct V_145 * V_20 ,
struct V_146 * V_147 ,
char * V_12 )
{
struct V_80 * V_10 = F_57 ( V_20 ) ;
struct V_1 * V_2 = F_58 ( V_10 ) ;
T_6 V_148 ;
F_60 ( & V_2 -> V_50 -> V_150 ) ;
V_148 = snprintf ( V_12 , V_151 , L_70 ,
V_2 -> V_31 . V_24 , V_2 -> V_31 . V_25 ,
V_2 -> V_31 . V_26 , V_2 -> V_31 . V_27 ) ;
F_61 ( & V_2 -> V_50 -> V_150 ) ;
return V_148 ;
}
static T_5 F_64 ( struct V_145 * V_20 ,
struct V_146 * V_147 ,
char * V_12 )
{
struct V_80 * V_10 = F_57 ( V_20 ) ;
struct V_1 * V_2 = F_58 ( V_10 ) ;
T_6 V_148 ;
F_60 ( & V_2 -> V_50 -> V_150 ) ;
V_148 = snprintf ( V_12 , V_151 , L_71 ,
( int ) sizeof( V_2 -> V_33 ) , V_2 -> V_33 ) ;
F_61 ( & V_2 -> V_50 -> V_150 ) ;
return V_148 ;
}
static void F_65 ( void * V_152 )
{
struct V_1 * V_2 = V_152 ;
F_66 ( & V_2 -> V_10 -> V_20 . V_153 , & V_154 ) ;
}
static int F_67 ( struct V_80 * V_10 , const struct V_155 * V_60 )
{
struct V_1 * V_2 ;
struct V_86 * V_50 ;
int error ;
if ( ! F_68 ( V_10 -> V_18 , V_156 ) ) {
F_4 ( & V_10 -> V_20 , L_72 ) ;
return - V_157 ;
}
V_2 = F_69 ( & V_10 -> V_20 , sizeof( * V_2 ) , V_110 ) ;
if ( ! V_2 )
return - V_111 ;
V_50 = F_70 ( & V_10 -> V_20 ) ;
if ( ! V_50 )
return - V_111 ;
V_2 -> V_10 = V_10 ;
V_2 -> V_50 = V_50 ;
snprintf ( V_2 -> V_158 , sizeof( V_2 -> V_158 ) ,
L_73 , F_71 ( & V_10 -> V_20 ) ) ;
V_2 -> V_47 = F_72 ( & V_10 -> V_20 ,
L_74 , V_159 ) ;
if ( F_73 ( V_2 -> V_47 ) ) {
error = F_74 ( V_2 -> V_47 ) ;
if ( error != V_160 )
F_4 ( & V_10 -> V_20 ,
L_75 , error ) ;
return error ;
}
error = F_11 ( V_2 ) ;
if ( error )
return error ;
error = F_8 ( V_2 ) ;
F_14 ( V_2 ) ;
if ( error )
return error ;
V_50 -> V_161 = L_76 ;
V_50 -> V_158 = V_2 -> V_158 ;
V_50 -> V_60 . V_162 = V_163 ;
V_50 -> V_60 . V_164 = 0x13c5 ;
V_50 -> V_165 = F_33 ;
V_50 -> V_166 = F_35 ;
F_75 ( V_50 , V_2 ) ;
V_50 -> V_57 = V_2 -> V_52 ;
V_50 -> V_167 = sizeof( * V_2 -> V_52 ) ;
V_50 -> V_168 = V_2 -> V_42 ;
F_51 ( V_50 , V_71 , 0 , V_2 -> V_35 , 0 , 0 ) ;
F_51 ( V_50 , V_72 , 0 , V_2 -> V_36 , 0 , 0 ) ;
F_51 ( V_50 , V_73 ,
V_169 , V_170 , 0 , 0 ) ;
F_51 ( V_50 , V_74 ,
V_171 , V_172 , 0 , 0 ) ;
F_51 ( V_50 , V_75 ,
V_173 , V_174 , 0 , 0 ) ;
F_52 ( V_2 -> V_50 , V_71 , V_2 -> V_40 ) ;
F_52 ( V_2 -> V_50 , V_72 , V_2 -> V_41 ) ;
error = F_76 ( V_50 , V_49 , V_175 ) ;
if ( error )
return error ;
F_77 ( V_10 , V_2 ) ;
error = F_78 ( & V_10 -> V_20 , V_10 -> V_53 ,
NULL , F_32 ,
V_176 , V_119 , V_2 ) ;
if ( error ) {
F_4 ( & V_10 -> V_20 ,
L_77 ,
V_10 -> V_53 , error ) ;
return error ;
}
F_23 ( V_10 -> V_53 ) ;
error = F_79 ( V_50 ) ;
if ( error ) {
F_4 ( & V_10 -> V_20 ,
L_78 , error ) ;
return error ;
}
error = F_80 ( & V_10 -> V_20 . V_153 , & V_154 ) ;
if ( error ) {
F_4 ( & V_10 -> V_20 ,
L_79 , error ) ;
return error ;
}
error = F_81 ( & V_10 -> V_20 , F_65 , V_2 ) ;
if ( error ) {
F_65 ( V_2 ) ;
F_4 ( & V_10 -> V_20 ,
L_80 , error ) ;
return error ;
}
return 0 ;
}
static int T_7 F_82 ( struct V_145 * V_20 )
{
struct V_80 * V_10 = F_57 ( V_20 ) ;
struct V_1 * V_2 = F_58 ( V_10 ) ;
struct V_86 * V_50 = V_2 -> V_50 ;
F_60 ( & V_50 -> V_150 ) ;
if ( F_83 ( V_20 ) )
V_2 -> V_177 = F_84 ( V_10 -> V_53 ) == 0 ;
else if ( V_50 -> V_144 )
F_22 ( V_2 ) ;
F_61 ( & V_50 -> V_150 ) ;
return 0 ;
}
static int T_7 F_85 ( struct V_145 * V_20 )
{
struct V_80 * V_10 = F_57 ( V_20 ) ;
struct V_1 * V_2 = F_58 ( V_10 ) ;
struct V_86 * V_50 = V_2 -> V_50 ;
F_60 ( & V_50 -> V_150 ) ;
if ( V_2 -> V_177 )
F_86 ( V_10 -> V_53 ) ;
else if ( V_50 -> V_144 )
F_20 ( V_2 ) ;
F_61 ( & V_50 -> V_150 ) ;
return 0 ;
}
