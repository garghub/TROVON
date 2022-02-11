static int F_1 ( const char * * V_1 )
{
int V_2 = 0 ;
while ( isdigit ( * * V_1 ) )
V_2 = V_2 * 10 + * ( ( * V_1 ) ++ ) - '0' ;
return V_2 ;
}
static char * F_2 ( char * V_3 , long V_4 , int V_5 , int V_6 , int V_7 ,
int type )
{
static const char V_8 [ 16 ] = L_1 ;
char V_9 [ 66 ] ;
char V_10 , V_11 , V_12 ;
int V_2 ;
V_12 = ( type & V_13 ) ;
if ( type & V_14 )
type &= ~ V_15 ;
if ( V_5 < 2 || V_5 > 36 )
return NULL ;
V_10 = ( type & V_15 ) ? '0' : ' ' ;
V_11 = 0 ;
if ( type & V_16 ) {
if ( V_4 < 0 ) {
V_11 = '-' ;
V_4 = - V_4 ;
V_6 -- ;
} else if ( type & V_17 ) {
V_11 = '+' ;
V_6 -- ;
} else if ( type & V_18 ) {
V_11 = ' ' ;
V_6 -- ;
}
}
if ( type & V_19 ) {
if ( V_5 == 16 )
V_6 -= 2 ;
else if ( V_5 == 8 )
V_6 -- ;
}
V_2 = 0 ;
if ( V_4 == 0 )
V_9 [ V_2 ++ ] = '0' ;
else
while ( V_4 != 0 )
V_9 [ V_2 ++ ] = ( V_8 [ F_3 ( V_4 , V_5 ) ] | V_12 ) ;
if ( V_2 > V_7 )
V_7 = V_2 ;
V_6 -= V_7 ;
if ( ! ( type & ( V_15 + V_14 ) ) )
while ( V_6 -- > 0 )
* V_3 ++ = ' ' ;
if ( V_11 )
* V_3 ++ = V_11 ;
if ( type & V_19 ) {
if ( V_5 == 8 )
* V_3 ++ = '0' ;
else if ( V_5 == 16 ) {
* V_3 ++ = '0' ;
* V_3 ++ = ( 'X' | V_12 ) ;
}
}
if ( ! ( type & V_14 ) )
while ( V_6 -- > 0 )
* V_3 ++ = V_10 ;
while ( V_2 < V_7 -- )
* V_3 ++ = '0' ;
while ( V_2 -- > 0 )
* V_3 ++ = V_9 [ V_2 ] ;
while ( V_6 -- > 0 )
* V_3 ++ = ' ' ;
return V_3 ;
}
int vsprintf ( char * V_20 , const char * V_21 , T_1 args )
{
int V_22 ;
unsigned long V_4 ;
int V_2 , V_5 ;
char * V_3 ;
const char * V_1 ;
int V_23 ;
int V_24 ;
int V_7 ;
int V_25 ;
for ( V_3 = V_20 ; * V_21 ; ++ V_21 ) {
if ( * V_21 != '%' ) {
* V_3 ++ = * V_21 ;
continue;
}
V_23 = 0 ;
V_26:
++ V_21 ;
switch ( * V_21 ) {
case '-' :
V_23 |= V_14 ;
goto V_26;
case '+' :
V_23 |= V_17 ;
goto V_26;
case ' ' :
V_23 |= V_18 ;
goto V_26;
case '#' :
V_23 |= V_19 ;
goto V_26;
case '0' :
V_23 |= V_15 ;
goto V_26;
}
V_24 = - 1 ;
if ( isdigit ( * V_21 ) )
V_24 = F_1 ( & V_21 ) ;
else if ( * V_21 == '*' ) {
++ V_21 ;
V_24 = va_arg ( args , int ) ;
if ( V_24 < 0 ) {
V_24 = - V_24 ;
V_23 |= V_14 ;
}
}
V_7 = - 1 ;
if ( * V_21 == '.' ) {
++ V_21 ;
if ( isdigit ( * V_21 ) )
V_7 = F_1 ( & V_21 ) ;
else if ( * V_21 == '*' ) {
++ V_21 ;
V_7 = va_arg ( args , int ) ;
}
if ( V_7 < 0 )
V_7 = 0 ;
}
V_25 = - 1 ;
if ( * V_21 == 'h' || * V_21 == 'l' || * V_21 == 'L' ) {
V_25 = * V_21 ;
++ V_21 ;
}
V_5 = 10 ;
switch ( * V_21 ) {
case 'c' :
if ( ! ( V_23 & V_14 ) )
while ( -- V_24 > 0 )
* V_3 ++ = ' ' ;
* V_3 ++ = ( unsigned char ) va_arg ( args , int ) ;
while ( -- V_24 > 0 )
* V_3 ++ = ' ' ;
continue;
case 's' :
V_1 = va_arg ( args , char * ) ;
V_22 = F_4 ( V_1 , V_7 ) ;
if ( ! ( V_23 & V_14 ) )
while ( V_22 < V_24 -- )
* V_3 ++ = ' ' ;
for ( V_2 = 0 ; V_2 < V_22 ; ++ V_2 )
* V_3 ++ = * V_1 ++ ;
while ( V_22 < V_24 -- )
* V_3 ++ = ' ' ;
continue;
case 'p' :
if ( V_24 == - 1 ) {
V_24 = 2 * sizeof( void * ) ;
V_23 |= V_15 ;
}
V_3 = F_2 ( V_3 ,
( unsigned long ) va_arg ( args , void * ) , 16 ,
V_24 , V_7 , V_23 ) ;
continue;
case 'n' :
if ( V_25 == 'l' ) {
long * V_27 = va_arg ( args , long * ) ;
* V_27 = ( V_3 - V_20 ) ;
} else {
int * V_27 = va_arg ( args , int * ) ;
* V_27 = ( V_3 - V_20 ) ;
}
continue;
case '%' :
* V_3 ++ = '%' ;
continue;
case 'o' :
V_5 = 8 ;
break;
case 'x' :
V_23 |= V_13 ;
case 'X' :
V_5 = 16 ;
break;
case 'd' :
case 'i' :
V_23 |= V_16 ;
case 'u' :
break;
default:
* V_3 ++ = '%' ;
if ( * V_21 )
* V_3 ++ = * V_21 ;
else
-- V_21 ;
continue;
}
if ( V_25 == 'l' )
V_4 = va_arg (args, unsigned long) ;
else if ( V_25 == 'h' ) {
V_4 = ( unsigned short ) va_arg ( args , int ) ;
if ( V_23 & V_16 )
V_4 = ( short ) V_4 ;
} else if ( V_23 & V_16 )
V_4 = va_arg ( args , int ) ;
else
V_4 = va_arg (args, unsigned int) ;
V_3 = F_2 ( V_3 , V_4 , V_5 , V_24 , V_7 , V_23 ) ;
}
* V_3 = '\0' ;
return V_3 - V_20 ;
}
int sprintf ( char * V_20 , const char * V_21 , ... )
{
T_1 args ;
int V_2 ;
va_start ( args , V_21 ) ;
V_2 = vsprintf ( V_20 , V_21 , args ) ;
va_end ( args ) ;
return V_2 ;
}
int printf ( const char * V_21 , ... )
{
char V_28 [ 1024 ] ;
T_1 args ;
int V_29 ;
va_start ( args , V_21 ) ;
V_29 = vsprintf ( V_28 , V_21 , args ) ;
va_end ( args ) ;
puts ( V_28 ) ;
return V_29 ;
}
