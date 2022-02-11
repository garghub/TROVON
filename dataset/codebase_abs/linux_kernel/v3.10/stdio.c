T_1 F_1 ( const char * V_1 , T_1 V_2 )
{
const char * V_3 ;
for ( V_3 = V_1 ; V_2 -- && * V_3 != '\0' ; ++ V_3 )
;
return V_3 - V_1 ;
}
static int F_2 ( const char * * V_1 )
{
int V_4 , V_5 ;
for ( V_4 = 0 ; '0' <= ( V_5 = * * V_1 ) && V_5 <= '9' ; ++ * V_1 )
V_4 = V_4 * 10 + V_5 - '0' ;
return V_4 ;
}
static char * F_3 ( char * V_6 , unsigned long long V_7 , int V_8 , int V_9 , int V_10 , int type )
{
char V_5 , V_11 , V_12 [ 66 ] ;
const char * V_13 = L_1 ;
int V_4 ;
if ( type & V_14 )
V_13 = L_2 ;
if ( type & V_15 )
type &= ~ V_16 ;
if ( V_8 < 2 || V_8 > 36 )
return 0 ;
V_5 = ( type & V_16 ) ? '0' : ' ' ;
V_11 = 0 ;
if ( type & V_17 ) {
if ( ( signed long long ) V_7 < 0 ) {
V_11 = '-' ;
V_7 = - ( signed long long ) V_7 ;
V_9 -- ;
} else if ( type & V_18 ) {
V_11 = '+' ;
V_9 -- ;
} else if ( type & V_19 ) {
V_11 = ' ' ;
V_9 -- ;
}
}
if ( type & V_20 ) {
if ( V_8 == 16 )
V_9 -= 2 ;
else if ( V_8 == 8 )
V_9 -- ;
}
V_4 = 0 ;
if ( V_7 == 0 )
V_12 [ V_4 ++ ] = '0' ;
else while ( V_7 != 0 ) {
V_12 [ V_4 ++ ] = V_13 [ F_4 ( V_7 , V_8 ) ] ;
}
if ( V_4 > V_10 )
V_10 = V_4 ;
V_9 -= V_10 ;
if ( ! ( type & ( V_16 + V_15 ) ) )
while( V_9 -- > 0 )
* V_6 ++ = ' ' ;
if ( V_11 )
* V_6 ++ = V_11 ;
if ( type & V_20 ) {
if ( V_8 == 8 )
* V_6 ++ = '0' ;
else if ( V_8 == 16 ) {
* V_6 ++ = '0' ;
* V_6 ++ = V_13 [ 33 ] ;
}
}
if ( ! ( type & V_15 ) )
while ( V_9 -- > 0 )
* V_6 ++ = V_5 ;
while ( V_4 < V_10 -- )
* V_6 ++ = '0' ;
while ( V_4 -- > 0 )
* V_6 ++ = V_12 [ V_4 ] ;
while ( V_9 -- > 0 )
* V_6 ++ = ' ' ;
return V_6 ;
}
int vsprintf ( char * V_21 , const char * V_22 , T_2 args )
{
int V_23 ;
unsigned long long V_7 ;
int V_4 , V_8 ;
char * V_6 ;
const char * V_1 ;
int V_24 ;
int V_25 ;
int V_10 ;
int V_26 ;
for ( V_6 = V_21 ; * V_22 ; ++ V_22 ) {
if ( * V_22 != '%' ) {
* V_6 ++ = * V_22 ;
continue;
}
V_24 = 0 ;
V_27:
++ V_22 ;
switch ( * V_22 ) {
case '-' : V_24 |= V_15 ; goto V_27;
case '+' : V_24 |= V_18 ; goto V_27;
case ' ' : V_24 |= V_19 ; goto V_27;
case '#' : V_24 |= V_20 ; goto V_27;
case '0' : V_24 |= V_16 ; goto V_27;
}
V_25 = - 1 ;
if ( '0' <= * V_22 && * V_22 <= '9' )
V_25 = F_2 ( & V_22 ) ;
else if ( * V_22 == '*' ) {
++ V_22 ;
V_25 = va_arg ( args , int ) ;
if ( V_25 < 0 ) {
V_25 = - V_25 ;
V_24 |= V_15 ;
}
}
V_10 = - 1 ;
if ( * V_22 == '.' ) {
++ V_22 ;
if ( '0' <= * V_22 && * V_22 <= '9' )
V_10 = F_2 ( & V_22 ) ;
else if ( * V_22 == '*' ) {
++ V_22 ;
V_10 = va_arg ( args , int ) ;
}
if ( V_10 < 0 )
V_10 = 0 ;
}
V_26 = - 1 ;
if ( * V_22 == 'l' && * ( V_22 + 1 ) == 'l' ) {
V_26 = 'q' ;
V_22 += 2 ;
} else if ( * V_22 == 'h' || * V_22 == 'l' || * V_22 == 'L'
|| * V_22 == 'Z' ) {
V_26 = * V_22 ;
++ V_22 ;
}
V_8 = 10 ;
switch ( * V_22 ) {
case 'c' :
if ( ! ( V_24 & V_15 ) )
while ( -- V_25 > 0 )
* V_6 ++ = ' ' ;
* V_6 ++ = ( unsigned char ) va_arg ( args , int ) ;
while ( -- V_25 > 0 )
* V_6 ++ = ' ' ;
continue;
case 's' :
V_1 = va_arg ( args , char * ) ;
if ( ! V_1 )
V_1 = L_3 ;
V_23 = F_1 ( V_1 , V_10 ) ;
if ( ! ( V_24 & V_15 ) )
while ( V_23 < V_25 -- )
* V_6 ++ = ' ' ;
for ( V_4 = 0 ; V_4 < V_23 ; ++ V_4 )
* V_6 ++ = * V_1 ++ ;
while ( V_23 < V_25 -- )
* V_6 ++ = ' ' ;
continue;
case 'p' :
if ( V_25 == - 1 ) {
V_25 = 2 * sizeof( void * ) ;
V_24 |= V_16 ;
}
V_6 = F_3 ( V_6 ,
( unsigned long ) va_arg ( args , void * ) , 16 ,
V_25 , V_10 , V_24 ) ;
continue;
case 'n' :
if ( V_26 == 'l' ) {
long * V_28 = va_arg ( args , long * ) ;
* V_28 = ( V_6 - V_21 ) ;
} else if ( V_26 == 'Z' ) {
T_1 * V_28 = va_arg ( args , T_1 * ) ;
* V_28 = ( V_6 - V_21 ) ;
} else {
int * V_28 = va_arg ( args , int * ) ;
* V_28 = ( V_6 - V_21 ) ;
}
continue;
case '%' :
* V_6 ++ = '%' ;
continue;
case 'o' :
V_8 = 8 ;
break;
case 'X' :
V_24 |= V_14 ;
case 'x' :
V_8 = 16 ;
break;
case 'd' :
case 'i' :
V_24 |= V_17 ;
case 'u' :
break;
default:
* V_6 ++ = '%' ;
if ( * V_22 )
* V_6 ++ = * V_22 ;
else
-- V_22 ;
continue;
}
if ( V_26 == 'l' ) {
V_7 = va_arg (args, unsigned long) ;
if ( V_24 & V_17 )
V_7 = ( signed long ) V_7 ;
} else if ( V_26 == 'q' ) {
V_7 = va_arg (args, unsigned long long) ;
if ( V_24 & V_17 )
V_7 = ( signed long long ) V_7 ;
} else if ( V_26 == 'Z' ) {
V_7 = va_arg ( args , T_1 ) ;
} else if ( V_26 == 'h' ) {
V_7 = ( unsigned short ) va_arg ( args , int ) ;
if ( V_24 & V_17 )
V_7 = ( signed short ) V_7 ;
} else {
V_7 = va_arg (args, unsigned int) ;
if ( V_24 & V_17 )
V_7 = ( signed int ) V_7 ;
}
V_6 = F_3 ( V_6 , V_7 , V_8 , V_25 , V_10 , V_24 ) ;
}
* V_6 = '\0' ;
return V_6 - V_21 ;
}
int sprintf ( char * V_21 , const char * V_22 , ... )
{
T_2 args ;
int V_4 ;
va_start ( args , V_22 ) ;
V_4 = vsprintf ( V_21 , V_22 , args ) ;
va_end ( args ) ;
return V_4 ;
}
int
printf ( const char * V_22 , ... )
{
T_2 args ;
int V_29 ;
va_start ( args , V_22 ) ;
V_29 = vsprintf ( V_30 , V_22 , args ) ;
va_end ( args ) ;
if ( V_31 . V_32 )
V_31 . V_32 ( V_30 , V_29 ) ;
return V_29 ;
}
