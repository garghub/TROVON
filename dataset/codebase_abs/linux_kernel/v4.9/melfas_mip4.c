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
error = F_1 ( V_2 , V_28 , sizeof( V_28 ) ,
V_2 -> V_35 , sizeof( V_2 -> V_35 ) ) ;
if ( error )
F_9 ( & V_2 -> V_10 -> V_20 ,
L_4 , error ) ;
else
F_10 ( & V_2 -> V_10 -> V_20 , L_5 ,
( int ) sizeof( V_2 -> V_35 ) , V_2 -> V_35 ) ;
error = F_7 ( V_2 ) ;
if ( error )
F_9 ( & V_2 -> V_10 -> V_20 ,
L_6 , error ) ;
else
F_10 ( & V_2 -> V_10 -> V_20 , L_7 ,
V_2 -> V_31 . V_24 , V_2 -> V_31 . V_25 ,
V_2 -> V_31 . V_26 , V_2 -> V_31 . V_27 ) ;
V_28 [ 0 ] = V_29 ;
V_28 [ 1 ] = V_36 ;
error = F_1 ( V_2 , V_28 , sizeof( V_28 ) , V_12 , 14 ) ;
if ( error ) {
F_9 ( & V_2 -> V_10 -> V_20 ,
L_8 ,
error ) ;
} else {
V_2 -> V_37 = F_6 ( & V_12 [ 0 ] ) ;
V_2 -> V_38 = F_6 ( & V_12 [ 2 ] ) ;
F_10 ( & V_2 -> V_10 -> V_20 , L_9 ,
V_2 -> V_37 , V_2 -> V_38 ) ;
V_2 -> V_39 = V_12 [ 4 ] ;
V_2 -> V_40 = V_12 [ 5 ] ;
V_2 -> V_41 = V_12 [ 6 ] ;
F_10 ( & V_2 -> V_10 -> V_20 ,
L_10 ,
V_2 -> V_39 , V_2 -> V_40 , V_2 -> V_41 ) ;
V_2 -> V_42 = V_12 [ 12 ] ;
V_2 -> V_43 = V_12 [ 13 ] ;
F_10 ( & V_2 -> V_10 -> V_20 , L_11 ,
V_2 -> V_42 , V_2 -> V_43 ) ;
if ( V_2 -> V_41 > 0 )
V_2 -> V_44 = V_2 -> V_41 ;
}
V_28 [ 0 ] = V_45 ;
V_28 [ 1 ] = V_46 ;
error = F_1 ( V_2 , V_28 , sizeof( V_28 ) , V_12 , 7 ) ;
if ( error ) {
F_9 ( & V_2 -> V_10 -> V_20 ,
L_12 , error ) ;
V_2 -> V_47 = 0xff ;
} else {
V_2 -> V_47 = F_6 ( & V_12 [ 4 ] ) ;
V_2 -> V_48 = V_12 [ 6 ] ;
F_10 ( & V_2 -> V_10 -> V_20 , L_13 ,
V_2 -> V_47 , V_2 -> V_48 ) ;
if ( V_2 -> V_47 == 2 || V_2 -> V_47 > 3 )
F_9 ( & V_2 -> V_10 -> V_20 ,
L_14 , V_2 -> V_47 ) ;
}
return 0 ;
}
static int F_11 ( struct V_1 * V_2 )
{
if ( V_2 -> V_49 ) {
F_12 ( V_2 -> V_49 , 1 ) ;
F_13 ( 200 * 1000 , 300 * 1000 ) ;
}
return 0 ;
}
static void F_14 ( struct V_1 * V_2 )
{
if ( V_2 -> V_49 )
F_12 ( V_2 -> V_49 , 0 ) ;
}
static void F_15 ( struct V_1 * V_2 )
{
int V_50 ;
for ( V_50 = 0 ; V_50 < V_51 ; V_50 ++ ) {
F_16 ( V_2 -> V_52 , V_50 ) ;
F_17 ( V_2 -> V_52 , V_53 , 0 ) ;
}
for ( V_50 = 0 ; V_50 < V_2 -> V_44 ; V_50 ++ )
F_18 ( V_2 -> V_52 , V_2 -> V_54 [ V_50 ] , 0 ) ;
F_19 ( V_2 -> V_52 ) ;
}
static int F_20 ( struct V_1 * V_2 )
{
int error ;
error = F_11 ( V_2 ) ;
if ( error )
return error ;
F_21 ( V_2 -> V_10 -> V_55 ) ;
return 0 ;
}
static void F_22 ( struct V_1 * V_2 )
{
F_23 ( V_2 -> V_10 -> V_55 ) ;
F_14 ( V_2 ) ;
F_15 ( V_2 ) ;
}
static void F_24 ( struct V_1 * V_2 , T_1 * V_56 )
{
T_1 V_57 ;
bool V_58 ;
switch ( V_2 -> V_47 ) {
case 0 :
case 1 :
V_57 = V_56 [ 0 ] & 0x0F ;
V_58 = V_56 [ 0 ] & 0x80 ;
break;
case 3 :
default:
V_57 = V_56 [ 0 ] & 0x0F ;
V_58 = V_56 [ 1 ] & 0x01 ;
break;
}
if ( V_57 >= 1 && V_57 <= V_2 -> V_44 ) {
unsigned short V_59 = V_2 -> V_54 [ V_57 - 1 ] ;
F_10 ( & V_2 -> V_10 -> V_20 ,
L_15 ,
V_57 , V_59 , V_58 ) ;
F_25 ( V_2 -> V_52 , V_60 , V_61 , V_59 ) ;
F_18 ( V_2 -> V_52 , V_59 , V_58 ) ;
} else {
F_4 ( & V_2 -> V_10 -> V_20 , L_16 , V_57 ) ;
}
}
static void F_26 ( struct V_1 * V_2 , T_1 * V_56 )
{
int V_62 ;
bool V_63 ;
bool V_64 ;
bool V_65 ;
T_2 V_66 , V_67 ;
T_1 V_68 = 0 ;
T_1 V_69 ;
T_1 V_70 ;
T_1 V_71 ;
T_1 V_72 ;
switch ( V_2 -> V_47 ) {
case 0 :
case 1 :
V_65 = V_56 [ 0 ] & F_27 ( 7 ) ;
V_63 = V_56 [ 0 ] & F_27 ( 5 ) ;
V_64 = V_56 [ 0 ] & F_27 ( 4 ) ;
V_62 = ( V_56 [ 0 ] & 0x0F ) - 1 ;
V_66 = ( ( V_56 [ 1 ] & 0x0F ) << 8 ) | V_56 [ 2 ] ;
V_67 = ( ( ( V_56 [ 1 ] >> 4 ) & 0x0F ) << 8 ) |
V_56 [ 3 ] ;
V_69 = V_56 [ 4 ] ;
V_70 = V_56 [ 5 ] ;
if ( V_2 -> V_47 == 0 ) {
V_71 = V_56 [ 5 ] ;
V_72 = V_56 [ 5 ] ;
} else {
V_71 = V_56 [ 6 ] ;
V_72 = V_56 [ 7 ] ;
}
break;
case 3 :
default:
V_62 = ( V_56 [ 0 ] & 0x0F ) - 1 ;
V_63 = V_56 [ 1 ] & F_27 ( 2 ) ;
V_64 = V_56 [ 1 ] & F_27 ( 1 ) ;
V_65 = V_56 [ 1 ] & F_27 ( 0 ) ;
V_66 = ( ( V_56 [ 2 ] & 0x0F ) << 8 ) | V_56 [ 3 ] ;
V_67 = ( ( ( V_56 [ 2 ] >> 4 ) & 0x0F ) << 8 ) |
V_56 [ 4 ] ;
V_70 = V_56 [ 6 ] ;
V_68 = ( V_56 [ 7 ] & 0xF0 ) >> 4 ;
V_69 = ( ( V_56 [ 7 ] & 0x0F ) << 8 ) |
V_56 [ 8 ] ;
V_71 = V_56 [ 9 ] ;
V_72 = V_56 [ 10 ] ;
break;
}
F_10 ( & V_2 -> V_10 -> V_20 ,
L_17 ,
V_62 , V_65 , V_66 , V_67 , V_69 ) ;
if ( F_28 ( V_62 < 0 || V_62 >= V_51 ) ) {
F_4 ( & V_2 -> V_10 -> V_20 , L_18 , V_62 ) ;
} else if ( V_65 ) {
F_16 ( V_2 -> V_52 , V_62 ) ;
F_17 ( V_2 -> V_52 , V_53 , true ) ;
F_29 ( V_2 -> V_52 , V_73 , V_66 ) ;
F_29 ( V_2 -> V_52 , V_74 , V_67 ) ;
F_29 ( V_2 -> V_52 , V_75 , V_69 ) ;
F_29 ( V_2 -> V_52 , V_76 , V_71 ) ;
F_29 ( V_2 -> V_52 , V_77 , V_72 ) ;
} else {
F_16 ( V_2 -> V_52 , V_62 ) ;
F_17 ( V_2 -> V_52 , V_53 , 0 ) ;
}
F_30 ( V_2 -> V_52 ) ;
}
static int F_31 ( struct V_1 * V_2 , T_1 * V_56 )
{
T_1 type ;
switch ( V_2 -> V_47 ) {
case 0 :
case 1 :
type = ( V_56 [ 0 ] & 0x40 ) >> 6 ;
break;
case 3 :
type = ( V_56 [ 0 ] & 0xF0 ) >> 4 ;
break;
default:
return - V_78 ;
}
F_10 ( & V_2 -> V_10 -> V_20 , L_19 , type ) ;
switch ( type ) {
case V_79 :
F_24 ( V_2 , V_56 ) ;
break;
case V_80 :
F_26 ( V_2 , V_56 ) ;
break;
default:
F_4 ( & V_2 -> V_10 -> V_20 , L_20 , type ) ;
break;
}
return 0 ;
}
static T_3 F_32 ( int V_55 , void * V_81 )
{
struct V_1 * V_2 = V_81 ;
struct V_82 * V_10 = V_2 -> V_10 ;
unsigned int V_50 ;
int error ;
T_1 V_28 [ 2 ] ;
T_1 V_70 ;
bool V_83 ;
V_28 [ 0 ] = V_45 ;
V_28 [ 1 ] = V_84 ;
error = F_1 ( V_2 , V_28 , sizeof( V_28 ) , V_2 -> V_12 , 1 ) ;
if ( error ) {
F_4 ( & V_10 -> V_20 ,
L_21 , error ) ;
goto V_85;
}
V_70 = V_2 -> V_12 [ 0 ] & 0x7F ;
V_83 = V_2 -> V_12 [ 0 ] & F_27 ( 7 ) ;
F_10 ( & V_10 -> V_20 , L_22 , V_70 , V_83 ) ;
if ( ! V_70 ) {
F_4 ( & V_10 -> V_20 , L_23 ) ;
goto V_85;
}
V_28 [ 0 ] = V_45 ;
V_28 [ 1 ] = V_86 ;
error = F_1 ( V_2 , V_28 , sizeof( V_28 ) , V_2 -> V_12 , V_70 ) ;
if ( error ) {
F_4 ( & V_10 -> V_20 ,
L_24 , error ) ;
goto V_85;
}
if ( V_83 ) {
F_10 ( & V_10 -> V_20 , L_25 , V_2 -> V_12 [ 0 ] ) ;
} else {
for ( V_50 = 0 ; V_50 < V_70 ; V_50 += V_2 -> V_48 ) {
error = F_31 ( V_2 , & V_2 -> V_12 [ V_50 ] ) ;
if ( error )
break;
}
F_19 ( V_2 -> V_52 ) ;
}
V_85:
return V_87 ;
}
static int F_33 ( struct V_88 * V_20 )
{
struct V_1 * V_2 = F_34 ( V_20 ) ;
return F_20 ( V_2 ) ;
}
static void F_35 ( struct V_88 * V_20 )
{
struct V_1 * V_2 = F_34 ( V_20 ) ;
F_22 ( V_2 ) ;
}
static int F_36 ( struct V_1 * V_2 )
{
T_1 V_28 [] = { V_89 , V_90 } ;
T_1 V_91 ;
struct V_7 V_8 [] = {
{
. V_9 = V_2 -> V_10 -> V_9 ,
. V_11 = 0 ,
. V_12 = V_28 ,
. V_13 = sizeof( V_28 ) ,
} , {
. V_9 = V_2 -> V_10 -> V_9 ,
. V_11 = V_14 ,
. V_12 = & V_91 ,
. V_13 = sizeof( V_91 ) ,
} ,
} ;
int V_92 ;
int error ;
int V_15 = 1000 ;
do {
V_92 = F_2 ( V_2 -> V_10 -> V_18 , V_8 , F_3 ( V_8 ) ) ;
if ( V_92 != F_3 ( V_8 ) ) {
error = V_92 < 0 ? V_92 : - V_19 ;
F_4 ( & V_2 -> V_10 -> V_20 ,
L_26 ,
error ) ;
return error ;
}
switch ( V_91 ) {
case V_93 :
F_10 ( & V_2 -> V_10 -> V_20 , L_27 , V_21 ) ;
return 0 ;
case V_94 :
F_4 ( & V_2 -> V_10 -> V_20 , L_28 ) ;
return - V_19 ;
case V_95 :
F_10 ( & V_2 -> V_10 -> V_20 , L_29 , V_21 ) ;
error = - V_96 ;
break;
default:
F_4 ( & V_2 -> V_10 -> V_20 ,
L_30 ,
V_91 ) ;
error = - V_78 ;
break;
}
F_13 ( 1000 , 2000 ) ;
} while ( -- V_15 );
return error ;
}
static int F_37 ( struct V_1 * V_2 , T_1 V_97 )
{
T_1 V_98 [] = { V_89 , V_99 , V_97 } ;
T_1 V_100 [] = { V_89 , V_99 } ;
T_1 V_91 ;
struct V_7 V_8 [] = {
{
. V_9 = V_2 -> V_10 -> V_9 ,
. V_11 = 0 ,
. V_12 = V_100 ,
. V_13 = sizeof( V_100 ) ,
} , {
. V_9 = V_2 -> V_10 -> V_9 ,
. V_11 = V_14 ,
. V_12 = & V_91 ,
. V_13 = sizeof( V_91 ) ,
} ,
} ;
int V_15 = 10 ;
int V_92 ;
int error ;
do {
V_92 = F_38 ( V_2 -> V_10 ,
V_98 , sizeof( V_98 ) ) ;
if ( V_92 != sizeof( V_98 ) ) {
error = V_92 < 0 ? V_92 : - V_19 ;
F_4 ( & V_2 -> V_10 -> V_20 ,
L_31 ,
V_97 , error , V_92 ) ;
return error ;
}
F_10 ( & V_2 -> V_10 -> V_20 ,
L_32 , V_97 ) ;
F_39 ( 1000 ) ;
V_92 = F_2 ( V_2 -> V_10 -> V_18 , V_8 , F_3 ( V_8 ) ) ;
if ( V_92 != F_3 ( V_8 ) ) {
error = V_92 < 0 ? V_92 : - V_19 ;
F_4 ( & V_2 -> V_10 -> V_20 ,
L_33 , error ) ;
return error ;
}
F_10 ( & V_2 -> V_10 -> V_20 ,
L_34 , V_91 , V_97 ) ;
if ( V_91 == V_97 )
return 0 ;
} while ( -- V_15 );
return - V_19 ;
}
static int F_40 ( struct V_1 * V_2 )
{
return F_37 ( V_2 , V_101 ) ;
}
static int F_41 ( struct V_1 * V_2 )
{
return F_37 ( V_2 , V_102 ) ;
}
static int F_42 ( struct V_1 * V_2 , T_2 * V_103 )
{
T_1 V_28 [] = { V_89 , V_104 } ;
T_1 V_91 [ sizeof( T_2 ) ] ;
struct V_7 V_8 [] = {
{
. V_9 = V_2 -> V_10 -> V_9 ,
. V_11 = 0 ,
. V_12 = V_28 ,
. V_13 = sizeof( V_28 ) ,
} , {
. V_9 = V_2 -> V_10 -> V_9 ,
. V_11 = V_14 ,
. V_12 = V_91 ,
. V_13 = sizeof( V_91 ) ,
} ,
} ;
int V_92 ;
int error ;
V_92 = F_2 ( V_2 -> V_10 -> V_18 , V_8 , F_3 ( V_8 ) ) ;
if ( V_92 != F_3 ( V_8 ) ) {
error = V_92 < 0 ? V_92 : - V_19 ;
F_4 ( & V_2 -> V_10 -> V_20 ,
L_35 ,
error ) ;
return error ;
}
* V_103 = F_6 ( V_91 ) ;
F_10 ( & V_2 -> V_10 -> V_20 ,
L_36 , * V_103 ) ;
return 0 ;
}
static int F_43 ( struct V_1 * V_2 , int V_105 ,
const T_1 * V_106 , int V_107 , T_2 V_103 )
{
T_1 V_28 [ 6 ] ;
T_1 * V_108 ;
T_2 V_109 ;
int V_92 ;
int error ;
F_10 ( & V_2 -> V_10 -> V_20 , L_37 ,
V_105 , V_107 ) ;
if ( V_107 > V_110 || V_107 % V_111 ) {
F_4 ( & V_2 -> V_10 -> V_20 ,
L_38 , V_107 ) ;
return - V_78 ;
}
V_108 = F_44 ( 2 + V_111 , V_112 ) ;
if ( ! V_108 )
return - V_113 ;
V_28 [ 0 ] = V_89 ;
V_28 [ 1 ] = V_114 ;
F_45 ( V_105 , & V_28 [ 2 ] ) ;
V_92 = F_38 ( V_2 -> V_10 , V_28 , 6 ) ;
if ( V_92 != 6 ) {
error = V_92 < 0 ? V_92 : - V_19 ;
F_4 ( & V_2 -> V_10 -> V_20 ,
L_39 , error ) ;
goto V_85;
}
V_28 [ 0 ] = V_89 ;
V_28 [ 1 ] = V_115 ;
F_45 ( V_107 , & V_28 [ 2 ] ) ;
V_92 = F_38 ( V_2 -> V_10 , V_28 , 6 ) ;
if ( V_92 != 6 ) {
error = V_92 < 0 ? V_92 : - V_19 ;
F_4 ( & V_2 -> V_10 -> V_20 ,
L_40 , error ) ;
goto V_85;
}
for ( V_109 = 0 ;
V_109 < V_107 ;
V_109 += V_111 ) {
F_10 ( & V_2 -> V_10 -> V_20 ,
L_41 ,
V_109 , V_111 ) ;
F_46 ( V_103 + V_109 , V_108 ) ;
memcpy ( & V_108 [ 2 ] , & V_106 [ V_109 ] , V_111 ) ;
V_92 = F_38 ( V_2 -> V_10 ,
V_108 , 2 + V_111 ) ;
if ( V_92 != 2 + V_111 ) {
error = V_92 < 0 ? V_92 : - V_19 ;
F_4 ( & V_2 -> V_10 -> V_20 ,
L_42 ,
V_109 , V_111 , error ) ;
goto V_85;
}
}
V_28 [ 0 ] = V_89 ;
V_28 [ 1 ] = V_116 ;
V_28 [ 2 ] = V_117 ;
V_92 = F_38 ( V_2 -> V_10 , V_28 , 3 ) ;
if ( V_92 != 3 ) {
error = V_92 < 0 ? V_92 : - V_19 ;
F_4 ( & V_2 -> V_10 -> V_20 ,
L_43 , error ) ;
goto V_85;
}
error = F_36 ( V_2 ) ;
V_85:
F_47 ( V_108 ) ;
return error ? error : 0 ;
}
static int F_48 ( struct V_1 * V_2 , int V_105 ,
const T_1 * V_106 , int V_107 , int V_103 )
{
T_1 V_28 [ 8 ] ;
T_1 * V_5 ;
int V_109 ;
struct V_7 V_8 [] = {
{
. V_9 = V_2 -> V_10 -> V_9 ,
. V_11 = 0 ,
. V_12 = V_28 ,
. V_13 = 2 ,
} , {
. V_9 = V_2 -> V_10 -> V_9 ,
. V_11 = V_14 ,
. V_13 = V_111 ,
} ,
} ;
int V_92 ;
int error ;
F_10 ( & V_2 -> V_10 -> V_20 , L_44 ,
V_105 , V_107 ) ;
V_28 [ 0 ] = V_89 ;
V_28 [ 1 ] = V_114 ;
F_45 ( V_105 , & V_28 [ 2 ] ) ;
V_92 = F_38 ( V_2 -> V_10 , V_28 , 6 ) ;
if ( V_92 != 6 ) {
error = V_92 < 0 ? V_92 : - V_19 ;
F_4 ( & V_2 -> V_10 -> V_20 ,
L_45 , error ) ;
return error ;
}
V_28 [ 0 ] = V_89 ;
V_28 [ 1 ] = V_115 ;
F_45 ( V_107 , & V_28 [ 2 ] ) ;
V_92 = F_38 ( V_2 -> V_10 , V_28 , 6 ) ;
if ( V_92 != 6 ) {
error = V_92 < 0 ? V_92 : - V_19 ;
F_4 ( & V_2 -> V_10 -> V_20 ,
L_46 , error ) ;
return error ;
}
V_28 [ 0 ] = V_89 ;
V_28 [ 1 ] = V_116 ;
V_28 [ 2 ] = V_118 ;
V_92 = F_38 ( V_2 -> V_10 , V_28 , 3 ) ;
if ( V_92 != 3 ) {
error = V_92 < 0 ? V_92 : - V_19 ;
F_4 ( & V_2 -> V_10 -> V_20 ,
L_47 , error ) ;
return error ;
}
error = F_36 ( V_2 ) ;
if ( error )
return error ;
V_8 [ 1 ] . V_12 = V_5 = F_44 ( V_111 , V_112 ) ;
if ( ! V_5 )
return - V_113 ;
for ( V_109 = 0 ;
V_109 < V_107 ;
V_109 += V_111 ) {
F_10 ( & V_2 -> V_10 -> V_20 ,
L_48 ,
V_109 , V_111 ) ;
F_46 ( V_103 + V_109 , V_28 ) ;
V_92 = F_2 ( V_2 -> V_10 -> V_18 , V_8 , F_3 ( V_8 ) ) ;
if ( V_92 != F_3 ( V_8 ) ) {
error = V_92 < 0 ? V_92 : - V_19 ;
F_4 ( & V_2 -> V_10 -> V_20 ,
L_42 ,
V_109 , V_111 , error ) ;
break;
}
if ( memcmp ( & V_106 [ V_109 ] , V_5 , V_111 ) ) {
F_4 ( & V_2 -> V_10 -> V_20 ,
L_49 ,
V_109 , V_111 ) ;
#if V_119
F_49 ( V_120 ,
V_121 L_50 ,
V_122 , 16 , 1 ,
V_106 + V_105 , V_111 ,
false ) ;
F_49 ( V_120 ,
V_121 L_51 ,
V_122 , 16 , 1 ,
V_5 , V_110 , false ) ;
#endif
error = - V_78 ;
break;
}
}
F_47 ( V_5 ) ;
return error ? error : 0 ;
}
static int F_50 ( struct V_1 * V_2 ,
const T_1 * V_123 , T_4 V_124 , T_4 V_125 )
{
struct V_82 * V_10 = V_2 -> V_10 ;
int V_105 ;
T_2 V_103 ;
int error , V_126 ;
F_10 ( & V_10 -> V_20 , L_52 ) ;
error = F_40 ( V_2 ) ;
if ( error ) {
F_4 ( & V_10 -> V_20 ,
L_53 ,
error ) ;
return error ;
}
error = F_42 ( V_2 , & V_103 ) ;
if ( error )
goto V_127;
F_10 ( & V_10 -> V_20 ,
L_54 ,
V_110 , V_111 ) ;
for ( V_105 = V_125 ;
V_105 < V_125 + V_124 ;
V_105 += V_110 ) {
error = F_43 ( V_2 , V_105 , V_123 + V_105 ,
V_110 , V_103 ) ;
if ( error )
break;
error = F_48 ( V_2 , V_105 , V_123 + V_105 ,
V_110 , V_103 ) ;
if ( error )
break;
}
V_127:
F_10 ( & V_10 -> V_20 , L_55 ) ;
V_126 = F_41 ( V_2 ) ;
if ( V_126 ) {
F_4 ( & V_10 -> V_20 ,
L_56 , V_126 ) ;
if ( ! error )
error = V_126 ;
}
F_14 ( V_2 ) ;
F_11 ( V_2 ) ;
F_8 ( V_2 ) ;
F_51 ( V_2 -> V_52 , V_73 , 0 , V_2 -> V_37 , 0 , 0 ) ;
F_51 ( V_2 -> V_52 , V_74 , 0 , V_2 -> V_38 , 0 , 0 ) ;
F_51 ( V_2 -> V_52 , V_128 , 0 , V_2 -> V_37 , 0 , 0 ) ;
F_51 ( V_2 -> V_52 , V_129 , 0 , V_2 -> V_38 , 0 , 0 ) ;
F_52 ( V_2 -> V_52 , V_73 , V_2 -> V_42 ) ;
F_52 ( V_2 -> V_52 , V_74 , V_2 -> V_43 ) ;
F_52 ( V_2 -> V_52 , V_128 , V_2 -> V_42 ) ;
F_52 ( V_2 -> V_52 , V_129 , V_2 -> V_43 ) ;
return error ? error : 0 ;
}
static int F_53 ( struct V_1 * V_2 , const struct V_130 * V_131 ,
T_4 * V_132 , T_4 * V_124 ,
const struct V_133 * * V_134 )
{
const struct V_133 * V_135 ;
struct V_22 V_31 ;
T_2 V_136 ;
if ( V_131 -> V_70 < V_137 ) {
F_4 ( & V_2 -> V_10 -> V_20 ,
L_57 ,
V_137 , V_131 -> V_70 ) ;
return - V_78 ;
}
V_135 = ( const void * ) & V_131 -> V_106 [ V_131 -> V_70 - V_137 ] ;
#if V_119
F_49 ( V_138 , V_121 L_58 ,
V_122 , 16 , 1 , * V_135 , V_136 , false ) ;
#endif
V_136 = F_6 ( & V_135 -> V_136 ) ;
if ( V_136 != V_137 ) {
F_4 ( & V_2 -> V_10 -> V_20 ,
L_59 ,
V_136 , V_137 ) ;
return - V_78 ;
}
if ( memcmp ( V_135 -> V_139 , V_140 ,
sizeof( V_135 -> V_139 ) ) ) {
F_4 ( & V_2 -> V_10 -> V_20 ,
L_60 ,
( int ) sizeof( V_135 -> V_139 ) , V_135 -> V_139 ,
( int ) sizeof( V_135 -> V_139 ) , V_140 ) ;
return - V_78 ;
}
* V_132 = F_54 ( & V_135 -> V_141 ) ;
* V_124 = F_54 ( & V_135 -> V_142 ) ;
F_10 ( & V_2 -> V_10 -> V_20 ,
L_61 ,
* V_132 , * V_124 ) ;
if ( * V_124 % V_110 ) {
F_4 ( & V_2 -> V_10 -> V_20 ,
L_62 ,
* V_124 , V_110 ) ;
return - V_78 ;
}
if ( V_131 -> V_70 != * V_132 + * V_124 ) {
F_4 ( & V_2 -> V_10 -> V_20 ,
L_63 ,
* V_132 + * V_124 , V_131 -> V_70 ) ;
return - V_78 ;
}
F_5 ( ( const T_1 * ) & V_135 -> V_143 , & V_31 ) ;
F_10 ( & V_2 -> V_10 -> V_20 ,
L_64 ,
V_31 . V_24 , V_31 . V_25 ,
V_31 . V_26 , V_31 . V_27 ) ;
F_10 ( & V_2 -> V_10 -> V_20 , L_65 ,
V_2 -> V_31 . V_24 , V_2 -> V_31 . V_25 ,
V_2 -> V_31 . V_26 , V_2 -> V_31 . V_27 ) ;
if ( V_31 . V_24 != 0xEEEE && V_31 . V_24 != 0xFFFF &&
V_31 . V_25 == 0xEEEE &&
V_31 . V_26 == 0xEEEE &&
V_31 . V_27 == 0xEEEE ) {
F_10 ( & V_2 -> V_10 -> V_20 , L_66 ) ;
} else if ( V_31 . V_24 == 0xEEEE &&
V_31 . V_25 != 0xEEEE && V_31 . V_25 != 0xFFFF &&
V_31 . V_26 != 0xEEEE && V_31 . V_26 != 0xFFFF &&
V_31 . V_27 != 0xEEEE && V_31 . V_27 != 0xFFFF ) {
F_10 ( & V_2 -> V_10 -> V_20 , L_67 ) ;
} else {
F_4 ( & V_2 -> V_10 -> V_20 , L_68 ) ;
return - V_78 ;
}
return 0 ;
}
static int F_55 ( struct V_1 * V_2 , const struct V_130 * V_131 )
{
const struct V_133 * V_135 ;
T_4 V_144 ;
T_4 V_124 ;
int V_145 = 3 ;
int error ;
error = F_53 ( V_2 , V_131 ,
& V_144 , & V_124 , & V_135 ) ;
if ( error )
return error ;
if ( V_2 -> V_52 -> V_146 ) {
F_23 ( V_2 -> V_10 -> V_55 ) ;
} else {
error = F_11 ( V_2 ) ;
if ( error )
return error ;
}
do {
error = F_50 ( V_2 , V_131 -> V_106 , V_124 , V_144 ) ;
if ( ! error )
break;
} while ( -- V_145 );
if ( error )
F_4 ( & V_2 -> V_10 -> V_20 ,
L_69 , error ) ;
if ( V_2 -> V_52 -> V_146 )
F_21 ( V_2 -> V_10 -> V_55 ) ;
else
F_14 ( V_2 ) ;
return error ? error : 0 ;
}
static T_5 F_56 ( struct V_147 * V_20 ,
struct V_148 * V_149 ,
const char * V_12 , T_6 V_150 )
{
struct V_82 * V_10 = F_57 ( V_20 ) ;
struct V_1 * V_2 = F_58 ( V_10 ) ;
const struct V_130 * V_131 ;
int error ;
error = F_59 ( & V_131 , V_151 , V_20 ) ;
if ( error ) {
F_4 ( & V_2 -> V_10 -> V_20 ,
L_70 ,
V_151 , error ) ;
return error ;
}
F_60 ( & V_2 -> V_52 -> V_152 ) ;
error = F_55 ( V_2 , V_131 ) ;
F_61 ( & V_2 -> V_52 -> V_152 ) ;
F_62 ( V_131 ) ;
if ( error ) {
F_4 ( & V_2 -> V_10 -> V_20 ,
L_71 , error ) ;
return error ;
}
return V_150 ;
}
static T_5 F_63 ( struct V_147 * V_20 ,
struct V_148 * V_149 ,
char * V_12 )
{
struct V_82 * V_10 = F_57 ( V_20 ) ;
struct V_1 * V_2 = F_58 ( V_10 ) ;
T_6 V_150 ;
F_60 ( & V_2 -> V_52 -> V_152 ) ;
V_150 = snprintf ( V_12 , V_153 , L_72 ,
V_2 -> V_31 . V_24 , V_2 -> V_31 . V_25 ,
V_2 -> V_31 . V_26 , V_2 -> V_31 . V_27 ) ;
F_61 ( & V_2 -> V_52 -> V_152 ) ;
return V_150 ;
}
static T_5 F_64 ( struct V_147 * V_20 ,
struct V_148 * V_149 ,
char * V_12 )
{
struct V_82 * V_10 = F_57 ( V_20 ) ;
struct V_1 * V_2 = F_58 ( V_10 ) ;
T_6 V_150 ;
F_60 ( & V_2 -> V_52 -> V_152 ) ;
V_150 = snprintf ( V_12 , V_153 , L_73 ,
( int ) sizeof( V_2 -> V_33 ) , V_2 -> V_33 ) ;
F_61 ( & V_2 -> V_52 -> V_152 ) ;
return V_150 ;
}
static T_5 F_65 ( struct V_147 * V_20 ,
struct V_148 * V_149 ,
char * V_12 )
{
struct V_82 * V_10 = F_57 ( V_20 ) ;
struct V_1 * V_2 = F_58 ( V_10 ) ;
T_6 V_150 ;
F_60 ( & V_2 -> V_52 -> V_152 ) ;
V_150 = snprintf ( V_12 , V_153 , L_73 ,
( int ) sizeof( V_2 -> V_35 ) , V_2 -> V_35 ) ;
F_61 ( & V_2 -> V_52 -> V_152 ) ;
return V_150 ;
}
static void F_66 ( void * V_154 )
{
struct V_1 * V_2 = V_154 ;
F_67 ( & V_2 -> V_10 -> V_20 . V_155 , & V_156 ) ;
}
static int F_68 ( struct V_82 * V_10 , const struct V_157 * V_62 )
{
struct V_1 * V_2 ;
struct V_88 * V_52 ;
int error ;
if ( ! F_69 ( V_10 -> V_18 , V_158 ) ) {
F_4 ( & V_10 -> V_20 , L_74 ) ;
return - V_159 ;
}
V_2 = F_70 ( & V_10 -> V_20 , sizeof( * V_2 ) , V_112 ) ;
if ( ! V_2 )
return - V_113 ;
V_52 = F_71 ( & V_10 -> V_20 ) ;
if ( ! V_52 )
return - V_113 ;
V_2 -> V_10 = V_10 ;
V_2 -> V_52 = V_52 ;
snprintf ( V_2 -> V_160 , sizeof( V_2 -> V_160 ) ,
L_75 , F_72 ( & V_10 -> V_20 ) ) ;
V_2 -> V_49 = F_73 ( & V_10 -> V_20 ,
L_76 , V_161 ) ;
if ( F_74 ( V_2 -> V_49 ) ) {
error = F_75 ( V_2 -> V_49 ) ;
if ( error != V_162 )
F_4 ( & V_10 -> V_20 ,
L_77 , error ) ;
return error ;
}
error = F_11 ( V_2 ) ;
if ( error )
return error ;
error = F_8 ( V_2 ) ;
F_14 ( V_2 ) ;
if ( error )
return error ;
V_52 -> V_163 = L_78 ;
V_52 -> V_160 = V_2 -> V_160 ;
V_52 -> V_62 . V_164 = V_165 ;
V_52 -> V_62 . V_166 = 0x13c5 ;
V_52 -> V_167 = F_33 ;
V_52 -> V_168 = F_35 ;
F_76 ( V_52 , V_2 ) ;
V_52 -> V_59 = V_2 -> V_54 ;
V_52 -> V_169 = sizeof( * V_2 -> V_54 ) ;
V_52 -> V_170 = V_2 -> V_44 ;
F_51 ( V_52 , V_73 , 0 , V_2 -> V_37 , 0 , 0 ) ;
F_51 ( V_52 , V_74 , 0 , V_2 -> V_38 , 0 , 0 ) ;
F_51 ( V_52 , V_75 ,
V_171 , V_172 , 0 , 0 ) ;
F_51 ( V_52 , V_76 ,
V_173 , V_174 , 0 , 0 ) ;
F_51 ( V_52 , V_77 ,
V_175 , V_176 , 0 , 0 ) ;
F_52 ( V_2 -> V_52 , V_73 , V_2 -> V_42 ) ;
F_52 ( V_2 -> V_52 , V_74 , V_2 -> V_43 ) ;
error = F_77 ( V_52 , V_51 , V_177 ) ;
if ( error )
return error ;
F_78 ( V_10 , V_2 ) ;
error = F_79 ( & V_10 -> V_20 , V_10 -> V_55 ,
NULL , F_32 ,
V_178 , V_121 , V_2 ) ;
if ( error ) {
F_4 ( & V_10 -> V_20 ,
L_79 ,
V_10 -> V_55 , error ) ;
return error ;
}
F_23 ( V_10 -> V_55 ) ;
error = F_80 ( V_52 ) ;
if ( error ) {
F_4 ( & V_10 -> V_20 ,
L_80 , error ) ;
return error ;
}
error = F_81 ( & V_10 -> V_20 . V_155 , & V_156 ) ;
if ( error ) {
F_4 ( & V_10 -> V_20 ,
L_81 , error ) ;
return error ;
}
error = F_82 ( & V_10 -> V_20 , F_66 , V_2 ) ;
if ( error ) {
F_66 ( V_2 ) ;
F_4 ( & V_10 -> V_20 ,
L_82 , error ) ;
return error ;
}
return 0 ;
}
static int T_7 F_83 ( struct V_147 * V_20 )
{
struct V_82 * V_10 = F_57 ( V_20 ) ;
struct V_1 * V_2 = F_58 ( V_10 ) ;
struct V_88 * V_52 = V_2 -> V_52 ;
F_60 ( & V_52 -> V_152 ) ;
if ( F_84 ( V_20 ) )
V_2 -> V_179 = F_85 ( V_10 -> V_55 ) == 0 ;
else if ( V_52 -> V_146 )
F_22 ( V_2 ) ;
F_61 ( & V_52 -> V_152 ) ;
return 0 ;
}
static int T_7 F_86 ( struct V_147 * V_20 )
{
struct V_82 * V_10 = F_57 ( V_20 ) ;
struct V_1 * V_2 = F_58 ( V_10 ) ;
struct V_88 * V_52 = V_2 -> V_52 ;
F_60 ( & V_52 -> V_152 ) ;
if ( V_2 -> V_179 )
F_87 ( V_10 -> V_55 ) ;
else if ( V_52 -> V_146 )
F_20 ( V_2 ) ;
F_61 ( & V_52 -> V_152 ) ;
return 0 ;
}
