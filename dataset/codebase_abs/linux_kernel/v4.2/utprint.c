static T_1
F_1 ( const char * string , T_1 V_1 )
{
T_2 V_2 = 0 ;
while ( * string && V_1 ) {
V_2 ++ ;
string ++ ;
V_1 -- ;
}
return ( V_2 ) ;
}
static char * F_2 ( char * string , const char * V_3 , char V_4 )
{
if ( string < V_3 ) {
* string = V_4 ;
}
++ string ;
return ( string ) ;
}
static char * F_3 ( char * string , T_3 V_5 , T_4 V_6 , T_4 V_7 )
{
const char * V_8 ;
T_3 V_9 ;
char * V_10 ;
V_10 = string ;
V_8 = V_7 ? V_11 : V_12 ;
if ( V_5 == 0 ) {
* ( V_10 ++ ) = '0' ;
} else {
while ( V_5 ) {
( void ) F_4 ( V_5 , V_6 , & V_5 ,
& V_9 ) ;
* ( V_10 ++ ) = V_8 [ V_9 ] ;
}
}
return ( V_10 ) ;
}
const char * F_5 ( const char * string , T_3 * V_13 )
{
T_3 V_5 = 0 ;
while ( isdigit ( ( int ) * string ) ) {
V_5 *= 10 ;
V_5 += * ( string ++ ) - '0' ;
}
* V_13 = V_5 ;
return ( string ) ;
}
const char * F_6 ( char * string , T_3 V_5 )
{
char V_14 [ 20 ] ;
const char * V_15 ;
char * V_16 ;
V_15 = F_3 ( V_14 , V_5 , 10 , FALSE ) ;
V_16 = string ;
while ( V_15 != V_14 ) {
* ( V_16 ++ ) = * ( -- V_15 ) ;
}
* V_16 = 0 ;
return ( string ) ;
}
static char * F_7 ( char * string ,
char * V_3 ,
T_3 V_5 ,
T_4 V_6 , T_5 V_17 , T_5 V_18 , T_4 type )
{
char * V_10 ;
char V_19 ;
char V_20 ;
T_4 V_21 ;
T_4 V_7 ;
T_5 V_22 ;
char V_23 [ 66 ] ;
if ( V_6 < 2 || V_6 > 16 ) {
return ( NULL ) ;
}
if ( type & V_24 ) {
type &= ~ V_25 ;
}
V_21 = ( ( type & V_26 )
&& V_6 != 10 ) ? TRUE : FALSE ;
V_7 = ( type & V_27 ) ? TRUE : FALSE ;
V_20 = ( type & V_25 ) ? '0' : ' ' ;
V_19 = '\0' ;
if ( type & V_28 ) {
if ( ( V_29 ) V_5 < 0 ) {
V_19 = '-' ;
V_5 = - ( V_29 ) V_5 ;
V_17 -- ;
} else if ( type & V_30 ) {
V_19 = '+' ;
V_17 -- ;
} else if ( type & V_31 ) {
V_19 = ' ' ;
V_17 -- ;
}
}
if ( V_21 ) {
V_17 -- ;
if ( V_6 == 16 ) {
V_17 -- ;
}
}
V_10 = F_3 ( V_23 , V_5 , V_6 , V_7 ) ;
V_22 = F_8 ( V_10 , V_23 ) ;
if ( V_22 > V_18 ) {
V_18 = V_22 ;
}
V_17 -= V_18 ;
if ( ! ( type & ( V_25 | V_24 ) ) ) {
while ( -- V_17 >= 0 ) {
string = F_2 ( string , V_3 , ' ' ) ;
}
}
if ( V_19 ) {
string = F_2 ( string , V_3 , V_19 ) ;
}
if ( V_21 ) {
string = F_2 ( string , V_3 , '0' ) ;
if ( V_6 == 16 ) {
string = F_2 ( string , V_3 ,
V_7 ? 'X' : 'x' ) ;
}
}
if ( ! ( type & V_24 ) ) {
while ( -- V_17 >= 0 ) {
string = F_2 ( string , V_3 , V_20 ) ;
}
}
while ( V_22 <= -- V_18 ) {
string = F_2 ( string , V_3 , '0' ) ;
}
while ( -- V_22 >= 0 ) {
string = F_2 ( string , V_3 ,
V_23 [ V_22 ] ) ;
}
while ( -- V_17 >= 0 ) {
string = F_2 ( string , V_3 , ' ' ) ;
}
return ( string ) ;
}
int
F_9 ( char * string ,
T_1 V_32 , const char * V_33 , T_6 args )
{
T_4 V_6 ;
T_4 type ;
T_5 V_17 ;
T_5 V_18 ;
char V_34 ;
T_3 V_5 ;
char * V_10 ;
char * V_3 ;
char V_4 ;
const char * V_35 ;
const void * V_36 ;
T_5 V_2 ;
int V_22 ;
V_10 = string ;
V_3 = string + V_32 ;
for (; * V_33 ; ++ V_33 ) {
if ( * V_33 != '%' ) {
V_10 = F_2 ( V_10 , V_3 , * V_33 ) ;
continue;
}
type = 0 ;
V_6 = 10 ;
do {
++ V_33 ;
if ( * V_33 == '#' ) {
type |= V_26 ;
} else if ( * V_33 == '0' ) {
type |= V_25 ;
} else if ( * V_33 == '+' ) {
type |= V_30 ;
} else if ( * V_33 == ' ' ) {
type |= V_31 ;
} else if ( * V_33 == '-' ) {
type |= V_24 ;
} else {
break;
}
} while ( 1 );
V_17 = - 1 ;
if ( isdigit ( ( int ) * V_33 ) ) {
V_33 = F_5 ( V_33 , & V_5 ) ;
V_17 = ( T_5 ) V_5 ;
} else if ( * V_33 == '*' ) {
++ V_33 ;
V_17 = va_arg ( args , int ) ;
if ( V_17 < 0 ) {
V_17 = - V_17 ;
type |= V_24 ;
}
}
V_18 = - 1 ;
if ( * V_33 == '.' ) {
++ V_33 ;
if ( isdigit ( ( int ) * V_33 ) ) {
V_33 = F_5 ( V_33 , & V_5 ) ;
V_18 = ( T_5 ) V_5 ;
} else if ( * V_33 == '*' ) {
++ V_33 ;
V_18 = va_arg ( args , int ) ;
}
if ( V_18 < 0 ) {
V_18 = 0 ;
}
}
V_34 = - 1 ;
if ( * V_33 == 'h' || * V_33 == 'l' || * V_33 == 'L' ) {
V_34 = * V_33 ;
++ V_33 ;
if ( V_34 == 'l' && * V_33 == 'l' ) {
V_34 = 'L' ;
++ V_33 ;
}
}
switch ( * V_33 ) {
case '%' :
V_10 = F_2 ( V_10 , V_3 , '%' ) ;
continue;
case 'c' :
if ( ! ( type & V_24 ) ) {
while ( -- V_17 > 0 ) {
V_10 =
F_2 ( V_10 ,
V_3 ,
' ' ) ;
}
}
V_4 = ( char ) va_arg ( args , int ) ;
V_10 = F_2 ( V_10 , V_3 , V_4 ) ;
while ( -- V_17 > 0 ) {
V_10 =
F_2 ( V_10 , V_3 , ' ' ) ;
}
continue;
case 's' :
V_35 = va_arg ( args , char * ) ;
if ( ! V_35 ) {
V_35 = L_1 ;
}
V_2 = F_1 ( V_35 , V_18 ) ;
if ( ! ( type & V_24 ) ) {
while ( V_2 < V_17 -- ) {
V_10 =
F_2 ( V_10 ,
V_3 ,
' ' ) ;
}
}
for ( V_22 = 0 ; V_22 < V_2 ; ++ V_22 ) {
V_10 = F_2 ( V_10 , V_3 , * V_35 ) ;
++ V_35 ;
}
while ( V_2 < V_17 -- ) {
V_10 =
F_2 ( V_10 , V_3 , ' ' ) ;
}
continue;
case 'o' :
V_6 = 8 ;
break;
case 'X' :
type |= V_27 ;
case 'x' :
V_6 = 16 ;
break;
case 'd' :
case 'i' :
type |= V_28 ;
case 'u' :
break;
case 'p' :
if ( V_17 == - 1 ) {
V_17 = 2 * sizeof( void * ) ;
type |= V_25 ;
}
V_36 = va_arg ( args , void * ) ;
V_10 = F_7 ( V_10 , V_3 ,
F_10 ( V_36 ) , 16 ,
V_17 , V_18 , type ) ;
continue;
default:
V_10 = F_2 ( V_10 , V_3 , '%' ) ;
if ( * V_33 ) {
V_10 =
F_2 ( V_10 , V_3 ,
* V_33 ) ;
} else {
-- V_33 ;
}
continue;
}
if ( V_34 == 'L' ) {
V_5 = va_arg ( args , T_3 ) ;
if ( type & V_28 ) {
V_5 = ( V_29 ) V_5 ;
}
} else if ( V_34 == 'l' ) {
V_5 = va_arg (args, unsigned long) ;
if ( type & V_28 ) {
V_5 = ( T_5 ) V_5 ;
}
} else if ( V_34 == 'h' ) {
V_5 = ( V_37 ) va_arg ( args , int ) ;
if ( type & V_28 ) {
V_5 = ( V_38 ) V_5 ;
}
} else {
V_5 = va_arg (args, unsigned int) ;
if ( type & V_28 ) {
V_5 = ( signed int ) V_5 ;
}
}
V_10 = F_7 ( V_10 , V_3 , V_5 , V_6 ,
V_17 , V_18 , type ) ;
}
if ( V_32 > 0 ) {
if ( V_10 < V_3 ) {
* V_10 = '\0' ;
} else {
V_3 [ - 1 ] = '\0' ;
}
}
return ( F_8 ( V_10 , string ) ) ;
}
int F_11 ( char * string , T_1 V_32 , const char * V_33 , ... )
{
T_6 args ;
int V_2 ;
va_start ( args , V_33 ) ;
V_2 = F_9 ( string , V_32 , V_33 , args ) ;
va_end ( args ) ;
return ( V_2 ) ;
}
int F_12 ( T_7 V_39 , const char * V_33 , T_6 args )
{
T_8 V_40 ;
int V_2 ;
V_40 = F_13 ( V_41 ) ;
V_2 = F_9 ( V_42 ,
sizeof( V_42 ) , V_33 , args ) ;
( void ) F_14 ( V_39 , V_42 , V_2 , 1 ) ;
F_15 ( V_41 , V_40 ) ;
return ( V_2 ) ;
}
int F_16 ( T_7 V_39 , const char * V_33 , ... )
{
T_6 args ;
int V_2 ;
va_start ( args , V_33 ) ;
V_2 = F_12 ( V_39 , V_33 , args ) ;
va_end ( args ) ;
return ( V_2 ) ;
}
