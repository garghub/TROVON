static void
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
F_2 ( V_1 , V_2 , & V_16 , V_3 , V_7 ) ;
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
F_4 ( V_1 , V_2 , & V_16 , V_3 ,
V_8 , 10 , V_11 , V_12 , V_14 ) ;
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
F_4 ( V_1 , V_2 , & V_16 , V_3 , V_8 ,
V_7 == 'o' ? 8 : ( V_7 == 'u' ? 10 : 16 ) ,
V_11 , V_12 , V_14 ) ;
break;
case 'f' :
if ( V_15 == V_32 )
V_9 = va_arg ( args , T_4 ) ;
else
V_9 = va_arg ( args , double ) ;
F_5 ( V_1 , V_2 , & V_16 , V_3 ,
V_9 , V_11 , V_12 , V_14 ) ;
break;
case 'E' :
V_14 |= V_34 ;
case 'e' :
if ( V_15 == V_32 )
V_9 = va_arg ( args , T_4 ) ;
else
V_9 = va_arg ( args , double ) ;
break;
case 'G' :
V_14 |= V_34 ;
case 'g' :
if ( V_15 == V_32 )
V_9 = va_arg ( args , T_4 ) ;
else
V_9 = va_arg ( args , double ) ;
break;
case 'c' :
F_2 ( V_1 , V_2 , & V_16 , V_3 ,
va_arg ( args , int ) ) ;
break;
case 's' :
V_10 = va_arg ( args , char * ) ;
if ( V_12 < 0 ) {
if ( V_2 )
V_12 = V_36 ;
else
V_12 = * V_3 ;
}
F_6 ( V_1 , V_2 , & V_16 , V_3 , V_10 ,
V_14 , V_11 , V_12 ) ;
break;
case 'p' :
V_8 = ( long ) va_arg ( args , void * ) ;
F_4 ( V_1 , V_2 , & V_16 , V_3 ,
V_8 , 16 , V_11 , V_12 , V_14 | V_23 ) ;
break;
case 'n' :
if ( V_15 == V_29 ) {
short int * V_37 ;
V_37 = va_arg (args, short int *) ;
* V_37 = V_16 ;
} else if ( V_15 == V_31 ) {
long int * V_37 ;
V_37 = va_arg (args, long int *) ;
* V_37 = ( long int ) V_16 ;
} else if ( V_15 == V_30 ) {
T_3 * V_37 ;
V_37 = va_arg ( args , T_3 * ) ;
* V_37 = ( T_3 ) V_16 ;
} else {
int * V_37 ;
V_37 = va_arg ( args , int * ) ;
* V_37 = V_16 ;
}
break;
case '%' :
F_2 ( V_1 , V_2 , & V_16 , V_3 , V_7 ) ;
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
* V_5 = ( V_16 > * V_3 - 1 ) ;
if ( * V_5 )
V_16 = * V_3 - 1 ;
F_2 ( V_1 , V_2 , & V_16 , V_3 , '\0' ) ;
* V_4 = V_16 - 1 ;
return;
}
static void
F_6 ( char * * V_1 ,
char * * V_2 ,
T_1 * V_16 ,
T_1 * V_3 , const char * V_8 , int V_14 , int V_11 , int V_12 )
{
int V_38 , V_39 ;
int V_40 = 0 ;
if ( V_8 == 0 )
V_8 = L_1 ;
for ( V_39 = 0 ; V_8 [ V_39 ] ; ++ V_39 ) ;
V_38 = V_11 - V_39 ;
if ( V_38 < 0 )
V_38 = 0 ;
if ( V_14 & V_20 )
V_38 = - V_38 ;
while ( ( V_38 > 0 ) && ( V_40 < V_12 ) ) {
F_2 ( V_1 , V_2 , V_16 , V_3 , ' ' ) ;
-- V_38 ;
++ V_40 ;
}
while ( * V_8 && ( V_40 < V_12 ) ) {
F_2 ( V_1 , V_2 , V_16 , V_3 , * V_8 ++ ) ;
++ V_40 ;
}
while ( ( V_38 < 0 ) && ( V_40 < V_12 ) ) {
F_2 ( V_1 , V_2 , V_16 , V_3 , ' ' ) ;
++ V_38 ;
++ V_40 ;
}
}
static void
F_4 ( char * * V_1 ,
char * * V_2 ,
T_1 * V_16 ,
T_1 * V_3 , T_3 V_8 , int V_41 , int V_11 , int V_12 , int V_14 )
{
int V_42 = 0 ;
const char * V_43 = L_2 ;
unsigned T_3 V_44 ;
char V_45 [ F_7 ( V_8 ) + 3 ] ;
int V_46 = 0 ;
int V_47 = 0 ;
int V_48 = 0 ;
int V_49 = 0 ;
if ( V_12 < 0 )
V_12 = 0 ;
V_44 = V_8 ;
if ( ! ( V_14 & V_35 ) ) {
if ( V_8 < 0 ) {
V_42 = '-' ;
V_44 = - V_8 ;
} else if ( V_14 & V_21 )
V_42 = '+' ;
else if ( V_14 & V_22 )
V_42 = ' ' ;
}
if ( V_14 & V_23 ) {
if ( V_41 == 8 )
V_43 = L_3 ;
if ( V_41 == 16 )
V_43 = L_4 ;
}
if ( V_14 & V_34 )
V_49 = 1 ;
do {
V_45 [ V_46 ++ ] = ( V_49 ? L_5 : L_6 )
[ V_44 % ( unsigned ) V_41 ] ;
V_44 = ( V_44 / ( unsigned ) V_41 ) ;
} while ( V_44 && ( V_46 < ( int ) sizeof( V_45 ) ) );
if ( V_46 == sizeof( V_45 ) )
V_46 -- ;
V_45 [ V_46 ] = 0 ;
V_48 = V_12 - V_46 ;
V_47 =
V_11 - F_8 ( V_12 , V_46 ) - ( V_42 ? 1 : 0 ) - strlen ( V_43 ) ;
if ( V_48 < 0 )
V_48 = 0 ;
if ( V_47 < 0 )
V_47 = 0 ;
if ( V_14 & V_24 ) {
V_48 = F_8 ( V_48 , V_47 ) ;
V_47 = 0 ;
}
if ( V_14 & V_20 )
V_47 = - V_47 ;
while ( V_47 > 0 ) {
F_2 ( V_1 , V_2 , V_16 , V_3 , ' ' ) ;
-- V_47 ;
}
if ( V_42 )
F_2 ( V_1 , V_2 , V_16 , V_3 , V_42 ) ;
while ( * V_43 ) {
F_2 ( V_1 , V_2 , V_16 , V_3 , * V_43 ) ;
V_43 ++ ;
}
if ( V_48 > 0 ) {
while ( V_48 > 0 ) {
F_2 ( V_1 , V_2 , V_16 , V_3 , '0' ) ;
-- V_48 ;
}
}
while ( V_46 > 0 )
F_2 ( V_1 , V_2 , V_16 , V_3 , V_45 [ -- V_46 ] ) ;
while ( V_47 < 0 ) {
F_2 ( V_1 , V_2 , V_16 , V_3 , ' ' ) ;
++ V_47 ;
}
return;
}
static T_4 F_9 ( T_4 V_8 )
{
T_4 V_50 = V_8 ;
if ( V_8 < 0 )
V_50 = - V_8 ;
return V_50 ;
}
static T_4 F_10 ( int V_51 )
{
T_4 V_50 = 1 ;
while ( V_51 ) {
V_50 *= 10 ;
V_51 -- ;
}
return V_50 ;
}
static long F_11 ( T_4 V_8 )
{
long V_52 ;
V_52 = ( long ) V_8 ;
V_8 = V_8 - V_52 ;
if ( V_8 >= 0.5 )
V_52 ++ ;
return V_52 ;
}
static void
F_5 ( char * * V_1 ,
char * * V_2 ,
T_1 * V_16 ,
T_1 * V_3 , T_4 V_9 , int V_11 , int V_12 , int V_14 )
{
int V_42 = 0 ;
T_4 V_53 ;
char V_54 [ 20 ] ;
char V_55 [ 20 ] ;
int V_56 = 0 ;
int V_57 = 0 ;
int V_38 = 0 ;
int V_48 = 0 ;
int V_49 = 0 ;
long V_52 ;
long V_58 ;
long V_59 ;
if ( V_12 < 0 )
V_12 = 6 ;
V_53 = F_9 ( V_9 ) ;
if ( V_9 < 0 )
V_42 = '-' ;
else if ( V_14 & V_21 )
V_42 = '+' ;
else if ( V_14 & V_22 )
V_42 = ' ' ;
V_52 = ( long ) V_53 ;
if ( V_12 > 9 )
V_12 = 9 ;
V_59 = F_11 ( F_10 ( V_12 ) ) ;
V_58 = F_11 ( F_10 ( V_12 ) * ( V_53 - V_52 ) ) ;
if ( V_58 >= V_59 ) {
V_52 ++ ;
V_58 -= V_59 ;
}
do {
V_54 [ V_56 ++ ] =
( V_49 ? L_5 : L_6 ) [ V_52 % 10 ] ;
V_52 = ( V_52 / 10 ) ;
} while ( V_52 && ( V_56 < ( int ) sizeof( V_54 ) ) );
if ( V_56 == sizeof V_54 )
V_56 -- ;
V_54 [ V_56 ] = 0 ;
do {
V_55 [ V_57 ++ ] =
( V_49 ? L_5 : L_6 ) [ V_58 % 10 ] ;
V_58 = ( V_58 / 10 ) ;
} while ( V_57 < V_12 );
if ( V_57 == sizeof V_55 )
V_57 -- ;
V_55 [ V_57 ] = 0 ;
V_38 = V_11 - V_56 - V_12 - 1 - ( ( V_42 ) ? 1 : 0 ) ;
V_48 = V_12 - V_57 ;
if ( V_48 < 0 )
V_48 = 0 ;
if ( V_38 < 0 )
V_38 = 0 ;
if ( V_14 & V_20 )
V_38 = - V_38 ;
if ( ( V_14 & V_24 ) && ( V_38 > 0 ) ) {
if ( V_42 ) {
F_2 ( V_1 , V_2 , V_16 , V_3 , V_42 ) ;
-- V_38 ;
V_42 = 0 ;
}
while ( V_38 > 0 ) {
F_2 ( V_1 , V_2 , V_16 , V_3 , '0' ) ;
-- V_38 ;
}
}
while ( V_38 > 0 ) {
F_2 ( V_1 , V_2 , V_16 , V_3 , ' ' ) ;
-- V_38 ;
}
if ( V_42 )
F_2 ( V_1 , V_2 , V_16 , V_3 , V_42 ) ;
while ( V_56 > 0 )
F_2 ( V_1 , V_2 , V_16 , V_3 , V_54 [ -- V_56 ] ) ;
if ( V_12 > 0 || ( V_14 & V_23 ) ) {
F_2 ( V_1 , V_2 , V_16 , V_3 , '.' ) ;
while ( V_57 > 0 )
F_2 ( V_1 , V_2 , V_16 , V_3 , V_55 [ -- V_57 ] ) ;
}
while ( V_48 > 0 ) {
F_2 ( V_1 , V_2 , V_16 , V_3 , '0' ) ;
-- V_48 ;
}
while ( V_38 < 0 ) {
F_2 ( V_1 , V_2 , V_16 , V_3 , ' ' ) ;
++ V_38 ;
}
}
static void
F_2 ( char * * V_1 ,
char * * V_2 , T_1 * V_16 , T_1 * V_3 , int V_60 )
{
assert ( * V_1 != NULL || V_2 != NULL ) ;
if ( V_2 ) {
while ( * V_16 >= * V_3 ) {
if ( * V_2 == NULL ) {
if ( * V_3 == 0 )
* V_3 = 1024 ;
* V_2 = F_12 ( * V_3 ) ;
if ( * V_16 > 0 ) {
assert ( * V_1 != NULL ) ;
memcpy ( * V_2 , * V_1 , * V_16 ) ;
}
* V_1 = NULL ;
} else {
* V_3 += 1024 ;
* V_2 = F_13 ( * V_2 , * V_3 ) ;
}
}
assert ( * V_1 != NULL || * V_2 != NULL ) ;
}
if ( * V_16 < * V_3 ) {
if ( * V_1 )
( * V_1 ) [ ( * V_16 ) ++ ] = ( char ) V_60 ;
else
( * V_2 ) [ ( * V_16 ) ++ ] = ( char ) V_60 ;
}
return;
}
int F_14 ( T_5 * V_61 , const char * V_6 , ... )
{
T_2 args ;
int V_62 ;
va_start ( args , V_6 ) ;
V_62 = F_15 ( V_61 , V_6 , args ) ;
va_end ( args ) ;
return ( V_62 ) ;
}
int F_15 ( T_5 * V_61 , const char * V_6 , T_2 args )
{
int V_62 ;
T_1 V_4 ;
char V_63 [ 1024 * 2 ] ;
char * V_64 = V_63 ;
T_1 V_65 = sizeof( V_63 ) ;
char * V_66 = NULL ;
int V_67 ;
V_66 = NULL ;
F_16 ( L_7 ) ;
F_1 ( & V_64 , & V_66 , & V_65 , & V_4 , & V_67 , V_6 , args ) ;
if ( V_66 ) {
V_62 = F_17 ( V_61 , V_66 , ( int ) V_4 ) ;
F_18 ( V_66 ) ;
} else {
V_62 = F_17 ( V_61 , V_63 , ( int ) V_4 ) ;
}
F_19 () ;
return ( V_62 ) ;
}
int F_20 ( char * V_68 , T_1 V_69 , const char * V_6 , ... )
{
T_2 args ;
int V_62 ;
va_start ( args , V_6 ) ;
V_62 = F_21 ( V_68 , V_69 , V_6 , args ) ;
va_end ( args ) ;
return ( V_62 ) ;
}
int F_21 ( char * V_68 , T_1 V_69 , const char * V_6 , T_2 args )
{
T_1 V_4 ;
int V_5 ;
F_1 ( & V_68 , NULL , & V_69 , & V_4 , & V_5 , V_6 , args ) ;
if ( V_5 )
return - 1 ;
else
return ( V_4 <= V_36 ) ? ( int ) V_4 : - 1 ;
}
