void F_1 ( T_1 V_1 , T_1 V_2 , const enum V_3 V_4 ,
char * V_5 , int V_6 )
{
static const char * const V_7 [] = {
L_1 , L_2 , L_3 , L_4 , L_5 , L_6 , L_7 , L_8 , L_9
} ;
static const char * const V_8 [] = {
L_1 , L_10 , L_11 , L_12 , L_13 , L_14 , L_15 , L_16 , L_17
} ;
static const char * const * const V_9 [] = {
[ V_10 ] = V_7 ,
[ V_11 ] = V_8 ,
} ;
static const unsigned int V_12 [] = {
[ V_10 ] = 1000 ,
[ V_11 ] = 1024 ,
} ;
int V_13 , V_14 ;
T_2 V_15 = 0 , V_16 , exp ;
char V_17 [ 8 ] ;
const char * V_18 ;
V_17 [ 0 ] = '\0' ;
V_13 = 0 ;
if ( ! V_1 )
goto V_19;
while ( V_2 >= V_12 [ V_4 ] ) {
V_15 = F_2 ( V_2 , V_12 [ V_4 ] ) ;
V_13 ++ ;
}
exp = V_12 [ V_4 ] / ( T_2 ) V_2 ;
if ( V_1 >= exp ) {
V_15 = F_2 ( V_1 , V_12 [ V_4 ] ) ;
V_15 *= V_2 ;
V_13 ++ ;
} else {
V_15 *= V_1 ;
}
V_1 *= V_2 ;
V_1 += V_15 / V_12 [ V_4 ] ;
V_15 %= V_12 [ V_4 ] ;
while ( V_1 >= V_12 [ V_4 ] ) {
V_15 = F_2 ( V_1 , V_12 [ V_4 ] ) ;
V_13 ++ ;
}
V_16 = V_1 ;
for ( V_14 = 0 ; V_16 * 10 < 1000 ; V_14 ++ )
V_16 *= 10 ;
if ( V_14 ) {
V_15 *= 1000 ;
V_15 /= V_12 [ V_4 ] ;
snprintf ( V_17 , sizeof( V_17 ) , L_18 , V_15 ) ;
V_17 [ V_14 + 1 ] = '\0' ;
}
V_19:
if ( V_13 >= F_3 ( V_8 ) )
V_18 = L_19 ;
else
V_18 = V_9 [ V_4 ] [ V_13 ] ;
snprintf ( V_5 , V_6 , L_20 , ( T_2 ) V_1 ,
V_17 , V_18 ) ;
}
static bool F_4 ( char * * V_20 , char * * V_21 )
{
char * V_22 = * V_21 , * V_23 = * V_20 ;
switch ( * V_23 ) {
case 'n' :
* V_22 = '\n' ;
break;
case 'r' :
* V_22 = '\r' ;
break;
case 't' :
* V_22 = '\t' ;
break;
case 'v' :
* V_22 = '\v' ;
break;
case 'f' :
* V_22 = '\f' ;
break;
default:
return false ;
}
* V_21 += 1 ;
* V_20 += 1 ;
return true ;
}
static bool F_5 ( char * * V_20 , char * * V_21 )
{
char * V_22 = * V_21 , * V_23 = * V_20 ;
T_3 V_24 ;
if ( F_6 ( * V_23 ) == 0 )
return false ;
V_24 = ( * V_23 ++ ) & 7 ;
while ( V_24 < 32 && F_6 ( * V_23 ) && ( V_23 - * V_20 < 3 ) ) {
V_24 <<= 3 ;
V_24 += ( * V_23 ++ ) & 7 ;
}
* V_22 = V_24 ;
* V_21 += 1 ;
* V_20 = V_23 ;
return true ;
}
static bool F_7 ( char * * V_20 , char * * V_21 )
{
char * V_22 = * V_21 , * V_23 = * V_20 ;
int V_25 ;
T_3 V_24 ;
if ( * V_23 ++ != 'x' )
return false ;
V_24 = V_25 = F_8 ( * V_23 ++ ) ;
if ( V_25 < 0 )
return false ;
V_25 = F_8 ( * V_23 ) ;
if ( V_25 >= 0 ) {
V_23 ++ ;
V_24 = ( V_24 << 4 ) | V_25 ;
}
* V_22 = V_24 ;
* V_21 += 1 ;
* V_20 = V_23 ;
return true ;
}
static bool F_9 ( char * * V_20 , char * * V_21 )
{
char * V_22 = * V_21 , * V_23 = * V_20 ;
switch ( * V_23 ) {
case '\"' :
* V_22 = '\"' ;
break;
case '\\' :
* V_22 = '\\' ;
break;
case 'a' :
* V_22 = '\a' ;
break;
case 'e' :
* V_22 = '\e' ;
break;
default:
return false ;
}
* V_21 += 1 ;
* V_20 += 1 ;
return true ;
}
int F_10 ( char * V_20 , char * V_21 , T_4 V_1 , unsigned int V_26 )
{
char * V_19 = V_21 ;
while ( * V_20 && -- V_1 ) {
if ( V_20 [ 0 ] == '\\' && V_20 [ 1 ] != '\0' && V_1 > 1 ) {
V_20 ++ ;
V_1 -- ;
if ( V_26 & V_27 &&
F_4 ( & V_20 , & V_19 ) )
continue;
if ( V_26 & V_28 &&
F_5 ( & V_20 , & V_19 ) )
continue;
if ( V_26 & V_29 &&
F_7 ( & V_20 , & V_19 ) )
continue;
if ( V_26 & V_30 &&
F_9 ( & V_20 , & V_19 ) )
continue;
* V_19 ++ = '\\' ;
}
* V_19 ++ = * V_20 ++ ;
}
* V_19 = '\0' ;
return V_19 - V_21 ;
}
static bool F_11 ( unsigned char V_31 , char * * V_21 , char * V_32 )
{
char * V_19 = * V_21 ;
if ( V_19 < V_32 )
* V_19 = V_31 ;
* V_21 = V_19 + 1 ;
return true ;
}
static bool F_12 ( unsigned char V_31 , char * * V_21 , char * V_32 )
{
char * V_19 = * V_21 ;
unsigned char V_33 ;
switch ( V_31 ) {
case '\n' :
V_33 = 'n' ;
break;
case '\r' :
V_33 = 'r' ;
break;
case '\t' :
V_33 = 't' ;
break;
case '\v' :
V_33 = 'v' ;
break;
case '\f' :
V_33 = 'f' ;
break;
default:
return false ;
}
if ( V_19 < V_32 )
* V_19 = '\\' ;
++ V_19 ;
if ( V_19 < V_32 )
* V_19 = V_33 ;
++ V_19 ;
* V_21 = V_19 ;
return true ;
}
static bool F_13 ( unsigned char V_31 , char * * V_21 , char * V_32 )
{
char * V_19 = * V_21 ;
unsigned char V_33 ;
switch ( V_31 ) {
case '\\' :
V_33 = '\\' ;
break;
case '\a' :
V_33 = 'a' ;
break;
case '\e' :
V_33 = 'e' ;
break;
default:
return false ;
}
if ( V_19 < V_32 )
* V_19 = '\\' ;
++ V_19 ;
if ( V_19 < V_32 )
* V_19 = V_33 ;
++ V_19 ;
* V_21 = V_19 ;
return true ;
}
static bool F_14 ( unsigned char V_31 , char * * V_21 , char * V_32 )
{
char * V_19 = * V_21 ;
if ( V_31 )
return false ;
if ( V_19 < V_32 )
* V_19 = '\\' ;
++ V_19 ;
if ( V_19 < V_32 )
* V_19 = '0' ;
++ V_19 ;
* V_21 = V_19 ;
return true ;
}
static bool F_15 ( unsigned char V_31 , char * * V_21 , char * V_32 )
{
char * V_19 = * V_21 ;
if ( V_19 < V_32 )
* V_19 = '\\' ;
++ V_19 ;
if ( V_19 < V_32 )
* V_19 = ( ( V_31 >> 6 ) & 0x07 ) + '0' ;
++ V_19 ;
if ( V_19 < V_32 )
* V_19 = ( ( V_31 >> 3 ) & 0x07 ) + '0' ;
++ V_19 ;
if ( V_19 < V_32 )
* V_19 = ( ( V_31 >> 0 ) & 0x07 ) + '0' ;
++ V_19 ;
* V_21 = V_19 ;
return true ;
}
static bool F_16 ( unsigned char V_31 , char * * V_21 , char * V_32 )
{
char * V_19 = * V_21 ;
if ( V_19 < V_32 )
* V_19 = '\\' ;
++ V_19 ;
if ( V_19 < V_32 )
* V_19 = 'x' ;
++ V_19 ;
if ( V_19 < V_32 )
* V_19 = F_17 ( V_31 ) ;
++ V_19 ;
if ( V_19 < V_32 )
* V_19 = F_18 ( V_31 ) ;
++ V_19 ;
* V_21 = V_19 ;
return true ;
}
int F_19 ( const char * V_20 , T_4 V_34 , char * V_21 , T_4 V_35 ,
unsigned int V_26 , const char * V_36 )
{
char * V_22 = V_21 ;
char * V_32 = V_22 + V_35 ;
bool V_37 = V_36 && * V_36 ;
while ( V_34 -- ) {
unsigned char V_31 = * V_20 ++ ;
if ( ( V_26 & V_38 && isprint ( V_31 ) ) ||
( V_37 && ! strchr ( V_36 , V_31 ) ) ) {
} else {
if ( V_26 & V_39 && F_12 ( V_31 , & V_22 , V_32 ) )
continue;
if ( V_26 & V_40 && F_13 ( V_31 , & V_22 , V_32 ) )
continue;
if ( V_26 & V_41 && F_14 ( V_31 , & V_22 , V_32 ) )
continue;
if ( V_26 & V_42 && F_15 ( V_31 , & V_22 , V_32 ) )
continue;
if ( V_26 & V_43 && F_16 ( V_31 , & V_22 , V_32 ) )
continue;
}
F_11 ( V_31 , & V_22 , V_32 ) ;
}
return V_22 - V_21 ;
}
