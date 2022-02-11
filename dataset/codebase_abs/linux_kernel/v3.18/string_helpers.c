int F_1 ( T_1 V_1 , const enum V_2 V_3 ,
char * V_4 , int V_5 )
{
static const char * const V_6 [] = {
L_1 , L_2 , L_3 , L_4 , L_5 , L_6 , L_7 , L_8 , L_9 , NULL
} ;
static const char * const V_7 [] = {
L_1 , L_10 , L_11 , L_12 , L_13 , L_14 , L_15 , L_16 , L_17 ,
NULL
} ;
static const char * const * const V_8 [] = {
[ V_9 ] = V_6 ,
[ V_10 ] = V_7 ,
} ;
static const unsigned int V_11 [] = {
[ V_9 ] = 1000 ,
[ V_10 ] = 1024 ,
} ;
int V_12 , V_13 ;
T_1 V_14 = 0 , V_15 ;
char V_16 [ 8 ] ;
V_16 [ 0 ] = '\0' ;
V_12 = 0 ;
if ( V_1 >= V_11 [ V_3 ] ) {
while ( V_1 >= V_11 [ V_3 ] && V_8 [ V_3 ] [ V_12 ] ) {
V_14 = F_2 ( V_1 , V_11 [ V_3 ] ) ;
V_12 ++ ;
}
V_15 = V_1 ;
for ( V_13 = 0 ; V_15 * 10 < 1000 ; V_13 ++ )
V_15 *= 10 ;
if ( V_13 ) {
V_14 *= 1000 ;
F_2 ( V_14 , V_11 [ V_3 ] ) ;
snprintf ( V_16 , sizeof( V_16 ) , L_18 ,
( unsigned long long ) V_14 ) ;
V_16 [ V_13 + 1 ] = '\0' ;
}
}
snprintf ( V_4 , V_5 , L_19 , ( unsigned long long ) V_1 ,
V_16 , V_8 [ V_3 ] [ V_12 ] ) ;
return 0 ;
}
static bool F_3 ( char * * V_17 , char * * V_18 )
{
char * V_19 = * V_18 , * V_20 = * V_17 ;
switch ( * V_20 ) {
case 'n' :
* V_19 = '\n' ;
break;
case 'r' :
* V_19 = '\r' ;
break;
case 't' :
* V_19 = '\t' ;
break;
case 'v' :
* V_19 = '\v' ;
break;
case 'f' :
* V_19 = '\f' ;
break;
default:
return false ;
}
* V_18 += 1 ;
* V_17 += 1 ;
return true ;
}
static bool F_4 ( char * * V_17 , char * * V_18 )
{
char * V_19 = * V_18 , * V_20 = * V_17 ;
T_2 V_21 ;
if ( F_5 ( * V_20 ) == 0 )
return false ;
V_21 = ( * V_20 ++ ) & 7 ;
while ( V_21 < 32 && F_5 ( * V_20 ) && ( V_20 - * V_17 < 3 ) ) {
V_21 <<= 3 ;
V_21 += ( * V_20 ++ ) & 7 ;
}
* V_19 = V_21 ;
* V_18 += 1 ;
* V_17 = V_20 ;
return true ;
}
static bool F_6 ( char * * V_17 , char * * V_18 )
{
char * V_19 = * V_18 , * V_20 = * V_17 ;
int V_22 ;
T_2 V_21 ;
if ( * V_20 ++ != 'x' )
return false ;
V_21 = V_22 = F_7 ( * V_20 ++ ) ;
if ( V_22 < 0 )
return false ;
V_22 = F_7 ( * V_20 ) ;
if ( V_22 >= 0 ) {
V_20 ++ ;
V_21 = ( V_21 << 4 ) | V_22 ;
}
* V_19 = V_21 ;
* V_18 += 1 ;
* V_17 = V_20 ;
return true ;
}
static bool F_8 ( char * * V_17 , char * * V_18 )
{
char * V_19 = * V_18 , * V_20 = * V_17 ;
switch ( * V_20 ) {
case '\"' :
* V_19 = '\"' ;
break;
case '\\' :
* V_19 = '\\' ;
break;
case 'a' :
* V_19 = '\a' ;
break;
case 'e' :
* V_19 = '\e' ;
break;
default:
return false ;
}
* V_18 += 1 ;
* V_17 += 1 ;
return true ;
}
int F_9 ( char * V_17 , char * V_18 , T_3 V_1 , unsigned int V_23 )
{
char * V_24 = V_18 ;
while ( * V_17 && -- V_1 ) {
if ( V_17 [ 0 ] == '\\' && V_17 [ 1 ] != '\0' && V_1 > 1 ) {
V_17 ++ ;
V_1 -- ;
if ( V_23 & V_25 &&
F_3 ( & V_17 , & V_24 ) )
continue;
if ( V_23 & V_26 &&
F_4 ( & V_17 , & V_24 ) )
continue;
if ( V_23 & V_27 &&
F_6 ( & V_17 , & V_24 ) )
continue;
if ( V_23 & V_28 &&
F_8 ( & V_17 , & V_24 ) )
continue;
* V_24 ++ = '\\' ;
}
* V_24 ++ = * V_17 ++ ;
}
* V_24 = '\0' ;
return V_24 - V_18 ;
}
static int F_10 ( unsigned char V_29 , char * * V_18 , T_3 * V_30 )
{
char * V_24 = * V_18 ;
if ( * V_30 < 1 )
return - V_31 ;
* V_24 ++ = V_29 ;
* V_18 = V_24 ;
* V_30 -= 1 ;
return 1 ;
}
static int F_11 ( unsigned char V_29 , char * * V_18 , T_3 * V_30 )
{
char * V_24 = * V_18 ;
unsigned char V_32 ;
if ( * V_30 < 2 )
return - V_31 ;
switch ( V_29 ) {
case '\n' :
V_32 = 'n' ;
break;
case '\r' :
V_32 = 'r' ;
break;
case '\t' :
V_32 = 't' ;
break;
case '\v' :
V_32 = 'v' ;
break;
case '\f' :
V_32 = 'f' ;
break;
default:
return 0 ;
}
* V_24 ++ = '\\' ;
* V_24 ++ = V_32 ;
* V_18 = V_24 ;
* V_30 -= 2 ;
return 1 ;
}
static int F_12 ( unsigned char V_29 , char * * V_18 , T_3 * V_30 )
{
char * V_24 = * V_18 ;
unsigned char V_32 ;
if ( * V_30 < 2 )
return - V_31 ;
switch ( V_29 ) {
case '\\' :
V_32 = '\\' ;
break;
case '\a' :
V_32 = 'a' ;
break;
case '\e' :
V_32 = 'e' ;
break;
default:
return 0 ;
}
* V_24 ++ = '\\' ;
* V_24 ++ = V_32 ;
* V_18 = V_24 ;
* V_30 -= 2 ;
return 1 ;
}
static int F_13 ( unsigned char V_29 , char * * V_18 , T_3 * V_30 )
{
char * V_24 = * V_18 ;
if ( * V_30 < 2 )
return - V_31 ;
if ( V_29 )
return 0 ;
* V_24 ++ = '\\' ;
* V_24 ++ = '0' ;
* V_18 = V_24 ;
* V_30 -= 2 ;
return 1 ;
}
static int F_14 ( unsigned char V_29 , char * * V_18 , T_3 * V_30 )
{
char * V_24 = * V_18 ;
if ( * V_30 < 4 )
return - V_31 ;
* V_24 ++ = '\\' ;
* V_24 ++ = ( ( V_29 >> 6 ) & 0x07 ) + '0' ;
* V_24 ++ = ( ( V_29 >> 3 ) & 0x07 ) + '0' ;
* V_24 ++ = ( ( V_29 >> 0 ) & 0x07 ) + '0' ;
* V_18 = V_24 ;
* V_30 -= 4 ;
return 1 ;
}
static int F_15 ( unsigned char V_29 , char * * V_18 , T_3 * V_30 )
{
char * V_24 = * V_18 ;
if ( * V_30 < 4 )
return - V_31 ;
* V_24 ++ = '\\' ;
* V_24 ++ = 'x' ;
* V_24 ++ = F_16 ( V_29 ) ;
* V_24 ++ = F_17 ( V_29 ) ;
* V_18 = V_24 ;
* V_30 -= 4 ;
return 1 ;
}
int F_18 ( const char * V_17 , T_3 V_33 , char * * V_18 , T_3 V_30 ,
unsigned int V_23 , const char * V_34 )
{
char * V_24 = * V_18 , * V_19 = V_24 ;
bool V_35 = V_34 && * V_34 ;
int V_36 = 0 ;
while ( V_33 -- ) {
unsigned char V_29 = * V_17 ++ ;
if ( ( V_23 & V_37 && isprint ( V_29 ) ) ||
( V_35 && ! strchr ( V_34 , V_29 ) ) ) {
} else {
if ( V_23 & V_38 ) {
V_36 = F_11 ( V_29 , & V_19 , & V_30 ) ;
if ( V_36 < 0 )
break;
if ( V_36 > 0 )
continue;
}
if ( V_23 & V_39 ) {
V_36 = F_12 ( V_29 , & V_19 , & V_30 ) ;
if ( V_36 < 0 )
break;
if ( V_36 > 0 )
continue;
}
if ( V_23 & V_40 ) {
V_36 = F_13 ( V_29 , & V_19 , & V_30 ) ;
if ( V_36 < 0 )
break;
if ( V_36 > 0 )
continue;
}
if ( V_23 & V_41 ) {
V_36 = F_14 ( V_29 , & V_19 , & V_30 ) ;
if ( V_36 < 0 )
break;
continue;
}
if ( V_23 & V_42 ) {
V_36 = F_15 ( V_29 , & V_19 , & V_30 ) ;
if ( V_36 < 0 )
break;
continue;
}
}
V_36 = F_10 ( V_29 , & V_19 , & V_30 ) ;
if ( V_36 < 0 )
break;
}
* V_18 = V_19 ;
if ( V_36 < 0 )
return V_36 ;
return V_19 - V_24 ;
}
