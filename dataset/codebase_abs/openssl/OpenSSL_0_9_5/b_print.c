int F_1 ( T_1 * V_1 , ... )
{
T_2 args ;
char * V_2 ;
int V_3 ;
T_3 V_4 ;
T_4 char V_5 [ 1024 * 2 ] ;
va_start ( args , V_1 ) ;
V_2 = va_arg ( args , char * ) ;
V_5 [ 0 ] = '\0' ;
F_2 ( V_5 , sizeof( V_5 ) , & V_4 , V_2 , args ) ;
V_3 = F_3 ( V_1 , V_5 , ( int ) V_4 ) ;
va_end ( args ) ;
return ( V_3 ) ;
}
static void
F_2 (
char * V_6 ,
T_3 V_7 ,
T_3 * V_4 ,
const char * V_2 ,
T_2 args )
{
char V_8 ;
T_5 V_9 ;
T_6 V_10 ;
char * V_11 ;
int V_12 ;
int V_13 ;
int V_14 ;
int V_15 ;
int V_16 ;
T_3 V_17 ;
V_14 = V_18 ;
V_15 = V_17 = V_16 = V_12 = 0 ;
V_13 = - 1 ;
V_8 = * V_2 ++ ;
while ( V_14 != V_19 ) {
if ( ( V_8 == '\0' ) || ( V_17 >= V_7 ) )
V_14 = V_19 ;
switch ( V_14 ) {
case V_18 :
if ( V_8 == '%' )
V_14 = V_20 ;
else
F_4 ( V_6 , & V_17 , V_7 , V_8 ) ;
V_8 = * V_2 ++ ;
break;
case V_20 :
switch ( V_8 ) {
case '-' :
V_15 |= V_21 ;
V_8 = * V_2 ++ ;
break;
case '+' :
V_15 |= V_22 ;
V_8 = * V_2 ++ ;
break;
case ' ' :
V_15 |= V_23 ;
V_8 = * V_2 ++ ;
break;
case '#' :
V_15 |= V_24 ;
V_8 = * V_2 ++ ;
break;
case '0' :
V_15 |= V_25 ;
V_8 = * V_2 ++ ;
break;
default:
V_14 = V_26 ;
break;
}
break;
case V_26 :
if ( isdigit ( ( unsigned char ) V_8 ) ) {
V_12 = 10 * V_12 + F_5 ( V_8 ) ;
V_8 = * V_2 ++ ;
} else if ( V_8 == '*' ) {
V_12 = va_arg ( args , int ) ;
V_8 = * V_2 ++ ;
V_14 = V_27 ;
} else
V_14 = V_27 ;
break;
case V_27 :
if ( V_8 == '.' ) {
V_14 = V_28 ;
V_8 = * V_2 ++ ;
} else
V_14 = V_29 ;
break;
case V_28 :
if ( isdigit ( ( unsigned char ) V_8 ) ) {
if ( V_13 < 0 )
V_13 = 0 ;
V_13 = 10 * V_13 + F_5 ( V_8 ) ;
V_8 = * V_2 ++ ;
} else if ( V_8 == '*' ) {
V_13 = va_arg ( args , int ) ;
V_8 = * V_2 ++ ;
V_14 = V_29 ;
} else
V_14 = V_29 ;
break;
case V_29 :
switch ( V_8 ) {
case 'h' :
V_16 = V_30 ;
V_8 = * V_2 ++ ;
break;
case 'l' :
if ( * V_2 == 'l' ) {
V_16 = V_31 ;
V_2 ++ ;
} else
V_16 = V_32 ;
V_8 = * V_2 ++ ;
break;
case 'q' :
V_16 = V_31 ;
V_8 = * V_2 ++ ;
break;
case 'L' :
V_16 = V_33 ;
V_8 = * V_2 ++ ;
break;
default:
break;
}
V_14 = V_34 ;
break;
case V_34 :
switch ( V_8 ) {
case 'd' :
case 'i' :
switch ( V_16 ) {
case V_30 :
V_9 = ( short int ) va_arg ( args , int ) ;
break;
case V_32 :
V_9 = va_arg (args, long int) ;
break;
case V_31 :
V_9 = va_arg ( args , T_5 ) ;
break;
default:
V_9 = va_arg ( args , int ) ;
break;
}
F_6 ( V_6 , & V_17 , V_7 , V_9 , 10 , V_12 , V_13 , V_15 ) ;
break;
case 'X' :
V_15 |= V_35 ;
case 'x' :
case 'o' :
case 'u' :
V_15 |= V_36 ;
switch ( V_16 ) {
case V_30 :
V_9 = ( unsigned short int ) va_arg (args, unsigned int) ;
break;
case V_32 :
V_9 = ( T_5 ) va_arg (args,
unsigned long int) ;
break;
case V_31 :
V_9 = va_arg (args, unsigned LLONG) ;
break;
default:
V_9 = ( T_5 ) va_arg (args,
unsigned int) ;
break;
}
F_6 ( V_6 , & V_17 , V_7 , V_9 ,
V_8 == 'o' ? 8 : ( V_8 == 'u' ? 10 : 16 ) ,
V_12 , V_13 , V_15 ) ;
break;
case 'f' :
if ( V_16 == V_33 )
V_10 = va_arg ( args , T_6 ) ;
else
V_10 = va_arg ( args , double ) ;
F_7 ( V_6 , & V_17 , V_7 , V_10 , V_12 , V_13 , V_15 ) ;
break;
case 'E' :
V_15 |= V_35 ;
case 'e' :
if ( V_16 == V_33 )
V_10 = va_arg ( args , T_6 ) ;
else
V_10 = va_arg ( args , double ) ;
break;
case 'G' :
V_15 |= V_35 ;
case 'g' :
if ( V_16 == V_33 )
V_10 = va_arg ( args , T_6 ) ;
else
V_10 = va_arg ( args , double ) ;
break;
case 'c' :
F_4 ( V_6 , & V_17 , V_7 ,
va_arg ( args , int ) ) ;
break;
case 's' :
V_11 = va_arg ( args , char * ) ;
if ( V_13 < 0 )
V_13 = V_7 ;
F_8 ( V_6 , & V_17 , V_7 , V_11 ,
V_15 , V_12 , V_13 ) ;
break;
case 'p' :
V_9 = ( long ) va_arg ( args , void * ) ;
F_6 ( V_6 , & V_17 , V_7 ,
V_9 , 16 , V_12 , V_13 , V_15 ) ;
break;
case 'n' :
if ( V_16 == V_30 ) {
short int * V_37 ;
V_37 = va_arg (args, short int *) ;
* V_37 = V_17 ;
} else if ( V_16 == V_32 ) {
long int * V_37 ;
V_37 = va_arg (args, long int *) ;
* V_37 = ( long int ) V_17 ;
} else if ( V_16 == V_31 ) {
T_5 * V_37 ;
V_37 = va_arg ( args , T_5 * ) ;
* V_37 = ( T_5 ) V_17 ;
} else {
int * V_37 ;
V_37 = va_arg ( args , int * ) ;
* V_37 = V_17 ;
}
break;
case '%' :
F_4 ( V_6 , & V_17 , V_7 , V_8 ) ;
break;
case 'w' :
V_8 = * V_2 ++ ;
break;
default:
break;
}
V_8 = * V_2 ++ ;
V_14 = V_18 ;
V_15 = V_16 = V_12 = 0 ;
V_13 = - 1 ;
break;
case V_19 :
break;
default:
break;
}
}
if ( V_17 >= V_7 - 1 )
V_17 = V_7 - 1 ;
V_6 [ V_17 ] = '\0' ;
* V_4 = V_17 ;
return;
}
static void
F_8 (
char * V_6 ,
T_3 * V_17 ,
T_3 V_7 ,
char * V_9 ,
int V_15 ,
int V_12 ,
int V_13 )
{
int V_38 , V_39 ;
int V_40 = 0 ;
if ( V_9 == 0 )
V_9 = L_1 ;
for ( V_39 = 0 ; V_9 [ V_39 ] ; ++ V_39 )
;
V_38 = V_12 - V_39 ;
if ( V_38 < 0 )
V_38 = 0 ;
if ( V_15 & V_21 )
V_38 = - V_38 ;
while ( ( V_38 > 0 ) && ( V_40 < V_13 ) ) {
F_4 ( V_6 , V_17 , V_7 , ' ' ) ;
-- V_38 ;
++ V_40 ;
}
while ( * V_9 && ( V_40 < V_13 ) ) {
F_4 ( V_6 , V_17 , V_7 , * V_9 ++ ) ;
++ V_40 ;
}
while ( ( V_38 < 0 ) && ( V_40 < V_13 ) ) {
F_4 ( V_6 , V_17 , V_7 , ' ' ) ;
++ V_38 ;
++ V_40 ;
}
}
static void
F_6 (
char * V_6 ,
T_3 * V_17 ,
T_3 V_7 ,
T_5 V_9 ,
int V_41 ,
int V_12 ,
int V_13 ,
int V_15 )
{
int V_42 = 0 ;
unsigned T_5 V_43 ;
char V_44 [ 20 ] ;
int V_45 = 0 ;
int V_46 = 0 ;
int V_47 = 0 ;
int V_48 = 0 ;
if ( V_13 < 0 )
V_13 = 0 ;
V_43 = V_9 ;
if ( ! ( V_15 & V_36 ) ) {
if ( V_9 < 0 ) {
V_42 = '-' ;
V_43 = - V_9 ;
} else if ( V_15 & V_22 )
V_42 = '+' ;
else if ( V_15 & V_23 )
V_42 = ' ' ;
}
if ( V_15 & V_35 )
V_48 = 1 ;
do {
V_44 [ V_45 ++ ] =
( V_48 ? L_2 : L_3 )
[ V_43 % ( unsigned ) V_41 ] ;
V_43 = ( V_43 / ( unsigned ) V_41 ) ;
} while ( V_43 && ( V_45 < 20 ) );
if ( V_45 == 20 )
V_45 -- ;
V_44 [ V_45 ] = 0 ;
V_47 = V_13 - V_45 ;
V_46 = V_12 - F_9 ( V_13 , V_45 ) - ( V_42 ? 1 : 0 ) ;
if ( V_47 < 0 )
V_47 = 0 ;
if ( V_46 < 0 )
V_46 = 0 ;
if ( V_15 & V_25 ) {
V_47 = F_9 ( V_47 , V_46 ) ;
V_46 = 0 ;
}
if ( V_15 & V_21 )
V_46 = - V_46 ;
while ( V_46 > 0 ) {
F_4 ( V_6 , V_17 , V_7 , ' ' ) ;
-- V_46 ;
}
if ( V_42 )
F_4 ( V_6 , V_17 , V_7 , V_42 ) ;
if ( V_47 > 0 ) {
while ( V_47 > 0 ) {
F_4 ( V_6 , V_17 , V_7 , '0' ) ;
-- V_47 ;
}
}
while ( V_45 > 0 )
F_4 ( V_6 , V_17 , V_7 , V_44 [ -- V_45 ] ) ;
while ( V_46 < 0 ) {
F_4 ( V_6 , V_17 , V_7 , ' ' ) ;
++ V_46 ;
}
return;
}
static T_6
F_10 ( T_6 V_9 )
{
T_6 V_49 = V_9 ;
if ( V_9 < 0 )
V_49 = - V_9 ;
return V_49 ;
}
static T_6
F_11 ( int exp )
{
T_6 V_49 = 1 ;
while ( exp ) {
V_49 *= 10 ;
exp -- ;
}
return V_49 ;
}
static long
F_12 ( T_6 V_9 )
{
long V_50 ;
V_50 = ( long ) V_9 ;
V_9 = V_9 - V_50 ;
if ( V_9 >= 0.5 )
V_50 ++ ;
return V_50 ;
}
static void
F_7 (
char * V_6 ,
T_3 * V_17 ,
T_3 V_7 ,
T_6 V_10 ,
int V_12 ,
int V_13 ,
int V_15 )
{
int V_42 = 0 ;
T_6 V_51 ;
char V_52 [ 20 ] ;
char V_53 [ 20 ] ;
int V_54 = 0 ;
int V_55 = 0 ;
int V_38 = 0 ;
int V_47 = 0 ;
int V_48 = 0 ;
long V_50 ;
long V_56 ;
if ( V_13 < 0 )
V_13 = 6 ;
V_51 = F_10 ( V_10 ) ;
if ( V_10 < 0 )
V_42 = '-' ;
else if ( V_15 & V_22 )
V_42 = '+' ;
else if ( V_15 & V_23 )
V_42 = ' ' ;
V_50 = ( long ) V_51 ;
if ( V_13 > 9 )
V_13 = 9 ;
V_56 = F_12 ( ( F_11 ( V_13 ) ) * ( V_51 - V_50 ) ) ;
if ( V_56 >= F_11 ( V_13 ) ) {
V_50 ++ ;
V_56 -= ( long ) F_11 ( V_13 ) ;
}
do {
V_52 [ V_54 ++ ] =
( V_48 ? L_2
: L_3 ) [ V_50 % 10 ] ;
V_50 = ( V_50 / 10 ) ;
} while ( V_50 && ( V_54 < 20 ) );
if ( V_54 == 20 )
V_54 -- ;
V_52 [ V_54 ] = 0 ;
do {
V_53 [ V_55 ++ ] =
( V_48 ? L_2
: L_3 ) [ V_56 % 10 ] ;
V_56 = ( V_56 / 10 ) ;
} while ( V_56 && ( V_55 < 20 ) );
if ( V_55 == 20 )
V_55 -- ;
V_53 [ V_55 ] = 0 ;
V_38 = V_12 - V_54 - V_13 - 1 - ( ( V_42 ) ? 1 : 0 ) ;
V_47 = V_13 - V_55 ;
if ( V_47 < 0 )
V_47 = 0 ;
if ( V_38 < 0 )
V_38 = 0 ;
if ( V_15 & V_21 )
V_38 = - V_38 ;
if ( ( V_15 & V_25 ) && ( V_38 > 0 ) ) {
if ( V_42 ) {
F_4 ( V_6 , V_17 , V_7 , V_42 ) ;
-- V_38 ;
V_42 = 0 ;
}
while ( V_38 > 0 ) {
F_4 ( V_6 , V_17 , V_7 , '0' ) ;
-- V_38 ;
}
}
while ( V_38 > 0 ) {
F_4 ( V_6 , V_17 , V_7 , ' ' ) ;
-- V_38 ;
}
if ( V_42 )
F_4 ( V_6 , V_17 , V_7 , V_42 ) ;
while ( V_54 > 0 )
F_4 ( V_6 , V_17 , V_7 , V_52 [ -- V_54 ] ) ;
if ( V_13 > 0 ) {
F_4 ( V_6 , V_17 , V_7 , '.' ) ;
while ( V_55 > 0 )
F_4 ( V_6 , V_17 , V_7 , V_53 [ -- V_55 ] ) ;
}
while ( V_47 > 0 ) {
F_4 ( V_6 , V_17 , V_7 , '0' ) ;
-- V_47 ;
}
while ( V_38 < 0 ) {
F_4 ( V_6 , V_17 , V_7 , ' ' ) ;
++ V_38 ;
}
}
static void
F_4 (
char * V_6 ,
T_3 * V_17 ,
T_3 V_7 ,
int V_57 )
{
if ( * V_17 < V_7 )
V_6 [ ( * V_17 ) ++ ] = ( char ) V_57 ;
return;
}
