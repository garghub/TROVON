static int
F_1 ( char * * V_1 ,
char * * V_2 ,
T_1 * V_3 ,
T_1 * V_4 , int * V_5 , const char * V_6 , T_2 args )
{
char V_7 ;
T_3 V_8 ;
T_4 V_9 ;
char * V_10 ;
int V_11 ;
int V_12 ;
int V_13 ;
int V_14 ;
int V_15 ;
T_1 V_16 ;
V_13 = V_17 ;
V_14 = V_16 = V_15 = V_11 = 0 ;
V_12 = - 1 ;
V_7 = * V_6 ++ ;
while ( V_13 != V_18 ) {
if ( V_7 == '\0' || ( V_2 == NULL && V_16 >= * V_3 ) )
V_13 = V_18 ;
switch ( V_13 ) {
case V_17 :
if ( V_7 == '%' )
V_13 = V_19 ;
else
if( ! F_2 ( V_1 , V_2 , & V_16 , V_3 , V_7 ) )
return 0 ;
V_7 = * V_6 ++ ;
break;
case V_19 :
switch ( V_7 ) {
case '-' :
V_14 |= V_20 ;
V_7 = * V_6 ++ ;
break;
case '+' :
V_14 |= V_21 ;
V_7 = * V_6 ++ ;
break;
case ' ' :
V_14 |= V_22 ;
V_7 = * V_6 ++ ;
break;
case '#' :
V_14 |= V_23 ;
V_7 = * V_6 ++ ;
break;
case '0' :
V_14 |= V_24 ;
V_7 = * V_6 ++ ;
break;
default:
V_13 = V_25 ;
break;
}
break;
case V_25 :
if ( isdigit ( ( unsigned char ) V_7 ) ) {
V_11 = 10 * V_11 + F_3 ( V_7 ) ;
V_7 = * V_6 ++ ;
} else if ( V_7 == '*' ) {
V_11 = va_arg ( args , int ) ;
V_7 = * V_6 ++ ;
V_13 = V_26 ;
} else
V_13 = V_26 ;
break;
case V_26 :
if ( V_7 == '.' ) {
V_13 = V_27 ;
V_7 = * V_6 ++ ;
} else
V_13 = V_28 ;
break;
case V_27 :
if ( isdigit ( ( unsigned char ) V_7 ) ) {
if ( V_12 < 0 )
V_12 = 0 ;
V_12 = 10 * V_12 + F_3 ( V_7 ) ;
V_7 = * V_6 ++ ;
} else if ( V_7 == '*' ) {
V_12 = va_arg ( args , int ) ;
V_7 = * V_6 ++ ;
V_13 = V_28 ;
} else
V_13 = V_28 ;
break;
case V_28 :
switch ( V_7 ) {
case 'h' :
V_15 = V_29 ;
V_7 = * V_6 ++ ;
break;
case 'l' :
if ( * V_6 == 'l' ) {
V_15 = V_30 ;
V_6 ++ ;
} else
V_15 = V_31 ;
V_7 = * V_6 ++ ;
break;
case 'q' :
V_15 = V_30 ;
V_7 = * V_6 ++ ;
break;
case 'L' :
V_15 = V_32 ;
V_7 = * V_6 ++ ;
break;
default:
break;
}
V_13 = V_33 ;
break;
case V_33 :
switch ( V_7 ) {
case 'd' :
case 'i' :
switch ( V_15 ) {
case V_29 :
V_8 = ( short int ) va_arg ( args , int ) ;
break;
case V_31 :
V_8 = va_arg (args, long int) ;
break;
case V_30 :
V_8 = va_arg ( args , T_3 ) ;
break;
default:
V_8 = va_arg ( args , int ) ;
break;
}
if ( ! F_4 ( V_1 , V_2 , & V_16 , V_3 , V_8 , 10 , V_11 ,
V_12 , V_14 ) )
return 0 ;
break;
case 'X' :
V_14 |= V_34 ;
case 'x' :
case 'o' :
case 'u' :
V_14 |= V_35 ;
switch ( V_15 ) {
case V_29 :
V_8 = ( unsigned short int ) va_arg (args, unsigned int) ;
break;
case V_31 :
V_8 = ( T_3 ) va_arg (args, unsigned long int) ;
break;
case V_30 :
V_8 = va_arg (args, unsigned LLONG) ;
break;
default:
V_8 = ( T_3 ) va_arg (args, unsigned int) ;
break;
}
if ( ! F_4 ( V_1 , V_2 , & V_16 , V_3 , V_8 ,
V_7 == 'o' ? 8 : ( V_7 == 'u' ? 10 : 16 ) ,
V_11 , V_12 , V_14 ) )
return 0 ;
break;
case 'f' :
if ( V_15 == V_32 )
V_9 = va_arg ( args , T_4 ) ;
else
V_9 = va_arg ( args , double ) ;
if ( ! F_5 ( V_1 , V_2 , & V_16 , V_3 , V_9 , V_11 , V_12 ,
V_14 , V_36 ) )
return 0 ;
break;
case 'E' :
V_14 |= V_34 ;
case 'e' :
if ( V_15 == V_32 )
V_9 = va_arg ( args , T_4 ) ;
else
V_9 = va_arg ( args , double ) ;
if ( ! F_5 ( V_1 , V_2 , & V_16 , V_3 , V_9 , V_11 , V_12 ,
V_14 , V_37 ) )
return 0 ;
break;
case 'G' :
V_14 |= V_34 ;
case 'g' :
if ( V_15 == V_32 )
V_9 = va_arg ( args , T_4 ) ;
else
V_9 = va_arg ( args , double ) ;
if ( ! F_5 ( V_1 , V_2 , & V_16 , V_3 , V_9 , V_11 , V_12 ,
V_14 , V_38 ) )
return 0 ;
break;
case 'c' :
if( ! F_2 ( V_1 , V_2 , & V_16 , V_3 ,
va_arg ( args , int ) ) )
return 0 ;
break;
case 's' :
V_10 = va_arg ( args , char * ) ;
if ( V_12 < 0 ) {
if ( V_2 )
V_12 = V_39 ;
else
V_12 = * V_3 ;
}
if ( ! F_6 ( V_1 , V_2 , & V_16 , V_3 , V_10 ,
V_14 , V_11 , V_12 ) )
return 0 ;
break;
case 'p' :
V_8 = ( T_1 ) va_arg ( args , void * ) ;
if ( ! F_4 ( V_1 , V_2 , & V_16 , V_3 ,
V_8 , 16 , V_11 , V_12 , V_14 | V_23 ) )
return 0 ;
break;
case 'n' :
if ( V_15 == V_29 ) {
short int * V_40 ;
V_40 = va_arg (args, short int *) ;
* V_40 = V_16 ;
} else if ( V_15 == V_31 ) {
long int * V_40 ;
V_40 = va_arg (args, long int *) ;
* V_40 = ( long int ) V_16 ;
} else if ( V_15 == V_30 ) {
T_3 * V_40 ;
V_40 = va_arg ( args , T_3 * ) ;
* V_40 = ( T_3 ) V_16 ;
} else {
int * V_40 ;
V_40 = va_arg ( args , int * ) ;
* V_40 = V_16 ;
}
break;
case '%' :
if( ! F_2 ( V_1 , V_2 , & V_16 , V_3 , V_7 ) )
return 0 ;
break;
case 'w' :
V_7 = * V_6 ++ ;
break;
default:
break;
}
V_7 = * V_6 ++ ;
V_13 = V_17 ;
V_14 = V_15 = V_11 = 0 ;
V_12 = - 1 ;
break;
case V_18 :
break;
default:
break;
}
}
if ( V_2 == NULL ) {
* V_5 = ( V_16 > * V_3 - 1 ) ;
if ( * V_5 )
V_16 = * V_3 - 1 ;
}
if( ! F_2 ( V_1 , V_2 , & V_16 , V_3 , '\0' ) )
return 0 ;
* V_4 = V_16 - 1 ;
return 1 ;
}
static int
F_6 ( char * * V_1 ,
char * * V_2 ,
T_1 * V_16 ,
T_1 * V_3 , const char * V_8 , int V_14 , int V_11 , int V_12 )
{
int V_41 ;
T_1 V_42 ;
int V_43 = 0 ;
if ( V_8 == 0 )
V_8 = L_1 ;
V_42 = F_7 ( V_8 , V_12 < 0 ? V_44 : ( T_1 ) V_12 ) ;
V_41 = V_11 - V_42 ;
if ( V_11 < 0 || V_41 < 0 )
V_41 = 0 ;
if ( V_12 >= 0 ) {
if ( V_12 < V_39 - V_41 )
V_12 += V_41 ;
else
V_12 = V_39 ;
}
if ( V_14 & V_20 )
V_41 = - V_41 ;
while ( ( V_41 > 0 ) && ( V_12 < 0 || V_43 < V_12 ) ) {
if( ! F_2 ( V_1 , V_2 , V_16 , V_3 , ' ' ) )
return 0 ;
-- V_41 ;
++ V_43 ;
}
while ( V_42 > 0 && ( V_12 < 0 || V_43 < V_12 ) ) {
if( ! F_2 ( V_1 , V_2 , V_16 , V_3 , * V_8 ++ ) )
return 0 ;
-- V_42 ;
++ V_43 ;
}
while ( ( V_41 < 0 ) && ( V_12 < 0 || V_43 < V_12 ) ) {
if( ! F_2 ( V_1 , V_2 , V_16 , V_3 , ' ' ) )
return 0 ;
++ V_41 ;
++ V_43 ;
}
return 1 ;
}
static int
F_4 ( char * * V_1 ,
char * * V_2 ,
T_1 * V_16 ,
T_1 * V_3 , T_3 V_8 , int V_45 , int V_11 , int V_12 , int V_14 )
{
int V_46 = 0 ;
const char * V_47 = L_2 ;
unsigned T_3 V_48 ;
char V_49 [ F_8 ( V_8 ) + 3 ] ;
int V_50 = 0 ;
int V_51 = 0 ;
int V_52 = 0 ;
int V_53 = 0 ;
if ( V_12 < 0 )
V_12 = 0 ;
V_48 = V_8 ;
if ( ! ( V_14 & V_35 ) ) {
if ( V_8 < 0 ) {
V_46 = '-' ;
V_48 = - ( unsigned T_3 ) V_8 ;
} else if ( V_14 & V_21 )
V_46 = '+' ;
else if ( V_14 & V_22 )
V_46 = ' ' ;
}
if ( V_14 & V_23 ) {
if ( V_45 == 8 )
V_47 = L_3 ;
if ( V_45 == 16 )
V_47 = L_4 ;
}
if ( V_14 & V_34 )
V_53 = 1 ;
do {
V_49 [ V_50 ++ ] = ( V_53 ? L_5 : L_6 )
[ V_48 % ( unsigned ) V_45 ] ;
V_48 = ( V_48 / ( unsigned ) V_45 ) ;
} while ( V_48 && ( V_50 < ( int ) sizeof( V_49 ) ) );
if ( V_50 == sizeof( V_49 ) )
V_50 -- ;
V_49 [ V_50 ] = 0 ;
V_52 = V_12 - V_50 ;
V_51 =
V_11 - F_9 ( V_12 , V_50 ) - ( V_46 ? 1 : 0 ) - strlen ( V_47 ) ;
if ( V_52 < 0 )
V_52 = 0 ;
if ( V_51 < 0 )
V_51 = 0 ;
if ( V_14 & V_24 ) {
V_52 = F_9 ( V_52 , V_51 ) ;
V_51 = 0 ;
}
if ( V_14 & V_20 )
V_51 = - V_51 ;
while ( V_51 > 0 ) {
if( ! F_2 ( V_1 , V_2 , V_16 , V_3 , ' ' ) )
return 0 ;
-- V_51 ;
}
if ( V_46 )
if( ! F_2 ( V_1 , V_2 , V_16 , V_3 , V_46 ) )
return 0 ;
while ( * V_47 ) {
if( ! F_2 ( V_1 , V_2 , V_16 , V_3 , * V_47 ) )
return 0 ;
V_47 ++ ;
}
if ( V_52 > 0 ) {
while ( V_52 > 0 ) {
if( ! F_2 ( V_1 , V_2 , V_16 , V_3 , '0' ) )
return 0 ;
-- V_52 ;
}
}
while ( V_50 > 0 ) {
if ( ! F_2 ( V_1 , V_2 , V_16 , V_3 , V_49 [ -- V_50 ] ) )
return 0 ;
}
while ( V_51 < 0 ) {
if ( ! F_2 ( V_1 , V_2 , V_16 , V_3 , ' ' ) )
return 0 ;
++ V_51 ;
}
return 1 ;
}
static T_4 F_10 ( T_4 V_8 )
{
T_4 V_54 = V_8 ;
if ( V_8 < 0 )
V_54 = - V_8 ;
return V_54 ;
}
static T_4 F_11 ( int V_55 )
{
T_4 V_54 = 1 ;
while ( V_55 ) {
V_54 *= 10 ;
V_55 -- ;
}
return V_54 ;
}
static long F_12 ( T_4 V_8 )
{
long V_56 ;
V_56 = ( long ) V_8 ;
V_8 = V_8 - V_56 ;
if ( V_8 >= 0.5 )
V_56 ++ ;
return V_56 ;
}
static int
F_5 ( char * * V_1 ,
char * * V_2 ,
T_1 * V_16 ,
T_1 * V_3 , T_4 V_9 , int V_11 , int V_12 , int V_14 , int V_57 )
{
int V_46 = 0 ;
T_4 V_58 ;
T_4 V_59 ;
char V_60 [ 20 ] ;
char V_61 [ 20 ] ;
char V_62 [ 20 ] ;
int V_63 = 0 ;
int V_64 = 0 ;
int V_65 = 0 ;
int V_41 = 0 ;
int V_52 = 0 ;
long exp = 0 ;
unsigned long V_56 ;
unsigned long V_66 ;
unsigned long V_67 ;
int V_68 ;
if ( V_12 < 0 )
V_12 = 6 ;
if ( V_9 < 0 )
V_46 = '-' ;
else if ( V_14 & V_21 )
V_46 = '+' ;
else if ( V_14 & V_22 )
V_46 = ' ' ;
if ( V_57 == V_38 ) {
if ( V_9 == 0.0 ) {
V_68 = V_36 ;
} else if ( V_9 < 0.0001 ) {
V_68 = V_37 ;
} else if ( ( V_12 == 0 && V_9 >= 10 )
|| ( V_12 > 0 && V_9 >= F_11 ( V_12 ) ) ) {
V_68 = V_37 ;
} else {
V_68 = V_36 ;
}
} else {
V_68 = V_57 ;
}
if ( V_57 != V_36 ) {
V_59 = V_9 ;
if ( V_9 != 0.0 ) {
while ( V_59 < 1 ) {
V_59 *= 10 ;
exp -- ;
}
while ( V_59 > 10 ) {
V_59 /= 10 ;
exp ++ ;
}
}
if ( V_57 == V_38 ) {
if ( V_12 == 0 )
V_12 = 1 ;
if ( V_68 == V_36 ) {
V_12 -= ( exp + 1 ) ;
if ( V_12 < 0 ) {
return 0 ;
}
} else {
V_12 -- ;
}
}
if ( V_68 == V_37 )
V_9 = V_59 ;
}
V_58 = F_10 ( V_9 ) ;
if ( V_58 > V_69 ) {
return 0 ;
}
V_56 = ( unsigned long ) V_58 ;
if ( V_12 > 9 )
V_12 = 9 ;
V_67 = F_12 ( F_11 ( V_12 ) ) ;
V_66 = F_12 ( F_11 ( V_12 ) * ( V_58 - V_56 ) ) ;
if ( V_66 >= V_67 ) {
V_56 ++ ;
V_66 -= V_67 ;
}
do {
V_60 [ V_63 ++ ] = L_7 [ V_56 % 10 ] ;
V_56 = ( V_56 / 10 ) ;
} while ( V_56 && ( V_63 < ( int ) sizeof( V_60 ) ) );
if ( V_63 == sizeof V_60 )
V_63 -- ;
V_60 [ V_63 ] = 0 ;
while ( V_64 < V_12 ) {
if ( V_57 == V_38 && V_64 == 0 && ( V_66 % 10 ) == 0 ) {
V_12 -- ;
V_66 = V_66 / 10 ;
if ( V_64 < V_12 )
continue;
break;
}
V_61 [ V_64 ++ ] = L_7 [ V_66 % 10 ] ;
V_66 = ( V_66 / 10 ) ;
}
if ( V_64 == sizeof V_61 )
V_64 -- ;
V_61 [ V_64 ] = 0 ;
if ( V_68 == V_37 ) {
int V_70 ;
if ( exp < 0 )
V_70 = - exp ;
else
V_70 = exp ;
do {
V_62 [ V_65 ++ ] = L_7 [ V_70 % 10 ] ;
V_70 = ( V_70 / 10 ) ;
} while ( V_70 > 0 && V_65 < ( int ) sizeof( V_62 ) );
if ( V_70 > 0 )
return 0 ;
if ( V_65 == 1 )
V_62 [ V_65 ++ ] = '0' ;
}
V_41 = V_11 - V_63 - V_12 - ( V_12 > 0 ? 1 : 0 ) - ( ( V_46 ) ? 1 : 0 ) ;
if ( V_68 == V_37 )
V_41 -= 2 + V_65 ;
V_52 = V_12 - V_64 ;
if ( V_52 < 0 )
V_52 = 0 ;
if ( V_41 < 0 )
V_41 = 0 ;
if ( V_14 & V_20 )
V_41 = - V_41 ;
if ( ( V_14 & V_24 ) && ( V_41 > 0 ) ) {
if ( V_46 ) {
if ( ! F_2 ( V_1 , V_2 , V_16 , V_3 , V_46 ) )
return 0 ;
-- V_41 ;
V_46 = 0 ;
}
while ( V_41 > 0 ) {
if ( ! F_2 ( V_1 , V_2 , V_16 , V_3 , '0' ) )
return 0 ;
-- V_41 ;
}
}
while ( V_41 > 0 ) {
if ( ! F_2 ( V_1 , V_2 , V_16 , V_3 , ' ' ) )
return 0 ;
-- V_41 ;
}
if ( V_46 && ! F_2 ( V_1 , V_2 , V_16 , V_3 , V_46 ) )
return 0 ;
while ( V_63 > 0 ) {
if ( ! F_2 ( V_1 , V_2 , V_16 , V_3 , V_60 [ -- V_63 ] ) )
return 0 ;
}
if ( V_12 > 0 || ( V_14 & V_23 ) ) {
if ( ! F_2 ( V_1 , V_2 , V_16 , V_3 , '.' ) )
return 0 ;
while ( V_64 > 0 ) {
if( ! F_2 ( V_1 , V_2 , V_16 , V_3 ,
V_61 [ -- V_64 ] ) )
return 0 ;
}
}
while ( V_52 > 0 ) {
if ( ! F_2 ( V_1 , V_2 , V_16 , V_3 , '0' ) )
return 0 ;
-- V_52 ;
}
if ( V_68 == V_37 ) {
char V_71 ;
if ( ( V_14 & V_34 ) == 0 )
V_71 = 'e' ;
else
V_71 = 'E' ;
if ( ! F_2 ( V_1 , V_2 , V_16 , V_3 , V_71 ) )
return 0 ;
if ( exp < 0 ) {
if ( ! F_2 ( V_1 , V_2 , V_16 , V_3 , '-' ) )
return 0 ;
} else {
if ( ! F_2 ( V_1 , V_2 , V_16 , V_3 , '+' ) )
return 0 ;
}
while ( V_65 > 0 ) {
if ( ! F_2 ( V_1 , V_2 , V_16 , V_3 ,
V_62 [ -- V_65 ] ) )
return 0 ;
}
}
while ( V_41 < 0 ) {
if ( ! F_2 ( V_1 , V_2 , V_16 , V_3 , ' ' ) )
return 0 ;
++ V_41 ;
}
return 1 ;
}
static int
F_2 ( char * * V_1 ,
char * * V_2 , T_1 * V_16 , T_1 * V_3 , int V_72 )
{
F_13 ( * V_1 != NULL || V_2 != NULL ) ;
F_13 ( * V_16 <= * V_3 ) ;
if ( V_2 && * V_16 == * V_3 ) {
if ( * V_3 > V_39 - V_73 )
return 0 ;
* V_3 += V_73 ;
if ( * V_2 == NULL ) {
* V_2 = F_14 ( * V_3 ) ;
if ( * V_2 == NULL )
return 0 ;
if ( * V_16 > 0 ) {
F_13 ( * V_1 != NULL ) ;
memcpy ( * V_2 , * V_1 , * V_16 ) ;
}
* V_1 = NULL ;
} else {
char * V_74 ;
V_74 = F_15 ( * V_2 , * V_3 ) ;
if ( V_74 == NULL )
return 0 ;
* V_2 = V_74 ;
}
}
if ( * V_16 < * V_3 ) {
if ( * V_1 )
( * V_1 ) [ ( * V_16 ) ++ ] = ( char ) V_72 ;
else
( * V_2 ) [ ( * V_16 ) ++ ] = ( char ) V_72 ;
}
return 1 ;
}
int F_16 ( T_5 * V_75 , const char * V_6 , ... )
{
T_2 args ;
int V_76 ;
va_start ( args , V_6 ) ;
V_76 = F_17 ( V_75 , V_6 , args ) ;
va_end ( args ) ;
return ( V_76 ) ;
}
int F_17 ( T_5 * V_75 , const char * V_6 , T_2 args )
{
int V_76 ;
T_1 V_4 ;
char V_77 [ 1024 * 2 ] ;
char * V_78 = V_77 ;
T_1 V_79 = sizeof( V_77 ) ;
char * V_80 = NULL ;
int V_81 ;
V_80 = NULL ;
if ( ! F_1 ( & V_78 , & V_80 , & V_79 , & V_4 , & V_81 , V_6 ,
args ) ) {
F_18 ( V_80 ) ;
return - 1 ;
}
if ( V_80 ) {
V_76 = F_19 ( V_75 , V_80 , ( int ) V_4 ) ;
F_18 ( V_80 ) ;
} else {
V_76 = F_19 ( V_75 , V_77 , ( int ) V_4 ) ;
}
return ( V_76 ) ;
}
int F_20 ( char * V_82 , T_1 V_83 , const char * V_6 , ... )
{
T_2 args ;
int V_76 ;
va_start ( args , V_6 ) ;
V_76 = F_21 ( V_82 , V_83 , V_6 , args ) ;
va_end ( args ) ;
return ( V_76 ) ;
}
int F_21 ( char * V_82 , T_1 V_83 , const char * V_6 , T_2 args )
{
T_1 V_4 ;
int V_5 ;
if( ! F_1 ( & V_82 , NULL , & V_83 , & V_4 , & V_5 , V_6 , args ) )
return - 1 ;
if ( V_5 )
return - 1 ;
else
return ( V_4 <= V_39 ) ? ( int ) V_4 : - 1 ;
}
