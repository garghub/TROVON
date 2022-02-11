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
static const unsigned int V_13 [] = { 500 , 50 , 5 } ;
int V_14 = 0 , V_15 ;
T_2 V_16 = 0 , V_17 ;
char V_18 [ 8 ] ;
const char * V_19 ;
V_18 [ 0 ] = '\0' ;
if ( V_2 == 0 )
V_1 = 0 ;
if ( V_1 == 0 )
goto V_20;
while ( V_2 >> 32 ) {
F_2 ( V_2 , V_12 [ V_4 ] ) ;
V_14 ++ ;
}
while ( V_1 >> 32 ) {
F_2 ( V_1 , V_12 [ V_4 ] ) ;
V_14 ++ ;
}
V_1 *= V_2 ;
while ( V_1 >= V_12 [ V_4 ] ) {
V_16 = F_2 ( V_1 , V_12 [ V_4 ] ) ;
V_14 ++ ;
}
V_17 = V_1 ;
for ( V_15 = 0 ; V_17 * 10 < 1000 ; V_15 ++ )
V_17 *= 10 ;
if ( V_4 == V_11 ) {
V_16 *= 1000 ;
V_16 >>= 10 ;
}
V_16 += V_13 [ V_15 ] ;
if ( V_16 >= 1000 ) {
V_16 -= 1000 ;
V_1 += 1 ;
}
if ( V_15 ) {
snprintf ( V_18 , sizeof( V_18 ) , L_18 , V_16 ) ;
V_18 [ V_15 + 1 ] = '\0' ;
}
V_20:
if ( V_14 >= F_3 ( V_8 ) )
V_19 = L_19 ;
else
V_19 = V_9 [ V_4 ] [ V_14 ] ;
snprintf ( V_5 , V_6 , L_20 , ( T_2 ) V_1 ,
V_18 , V_19 ) ;
}
static bool F_4 ( char * * V_21 , char * * V_22 )
{
char * V_23 = * V_22 , * V_24 = * V_21 ;
switch ( * V_24 ) {
case 'n' :
* V_23 = '\n' ;
break;
case 'r' :
* V_23 = '\r' ;
break;
case 't' :
* V_23 = '\t' ;
break;
case 'v' :
* V_23 = '\v' ;
break;
case 'f' :
* V_23 = '\f' ;
break;
default:
return false ;
}
* V_22 += 1 ;
* V_21 += 1 ;
return true ;
}
static bool F_5 ( char * * V_21 , char * * V_22 )
{
char * V_23 = * V_22 , * V_24 = * V_21 ;
T_3 V_25 ;
if ( F_6 ( * V_24 ) == 0 )
return false ;
V_25 = ( * V_24 ++ ) & 7 ;
while ( V_25 < 32 && F_6 ( * V_24 ) && ( V_24 - * V_21 < 3 ) ) {
V_25 <<= 3 ;
V_25 += ( * V_24 ++ ) & 7 ;
}
* V_23 = V_25 ;
* V_22 += 1 ;
* V_21 = V_24 ;
return true ;
}
static bool F_7 ( char * * V_21 , char * * V_22 )
{
char * V_23 = * V_22 , * V_24 = * V_21 ;
int V_26 ;
T_3 V_25 ;
if ( * V_24 ++ != 'x' )
return false ;
V_25 = V_26 = F_8 ( * V_24 ++ ) ;
if ( V_26 < 0 )
return false ;
V_26 = F_8 ( * V_24 ) ;
if ( V_26 >= 0 ) {
V_24 ++ ;
V_25 = ( V_25 << 4 ) | V_26 ;
}
* V_23 = V_25 ;
* V_22 += 1 ;
* V_21 = V_24 ;
return true ;
}
static bool F_9 ( char * * V_21 , char * * V_22 )
{
char * V_23 = * V_22 , * V_24 = * V_21 ;
switch ( * V_24 ) {
case '\"' :
* V_23 = '\"' ;
break;
case '\\' :
* V_23 = '\\' ;
break;
case 'a' :
* V_23 = '\a' ;
break;
case 'e' :
* V_23 = '\e' ;
break;
default:
return false ;
}
* V_22 += 1 ;
* V_21 += 1 ;
return true ;
}
int F_10 ( char * V_21 , char * V_22 , T_4 V_1 , unsigned int V_27 )
{
char * V_20 = V_22 ;
while ( * V_21 && -- V_1 ) {
if ( V_21 [ 0 ] == '\\' && V_21 [ 1 ] != '\0' && V_1 > 1 ) {
V_21 ++ ;
V_1 -- ;
if ( V_27 & V_28 &&
F_4 ( & V_21 , & V_20 ) )
continue;
if ( V_27 & V_29 &&
F_5 ( & V_21 , & V_20 ) )
continue;
if ( V_27 & V_30 &&
F_7 ( & V_21 , & V_20 ) )
continue;
if ( V_27 & V_31 &&
F_9 ( & V_21 , & V_20 ) )
continue;
* V_20 ++ = '\\' ;
}
* V_20 ++ = * V_21 ++ ;
}
* V_20 = '\0' ;
return V_20 - V_22 ;
}
static bool F_11 ( unsigned char V_32 , char * * V_22 , char * V_33 )
{
char * V_20 = * V_22 ;
if ( V_20 < V_33 )
* V_20 = V_32 ;
* V_22 = V_20 + 1 ;
return true ;
}
static bool F_12 ( unsigned char V_32 , char * * V_22 , char * V_33 )
{
char * V_20 = * V_22 ;
unsigned char V_34 ;
switch ( V_32 ) {
case '\n' :
V_34 = 'n' ;
break;
case '\r' :
V_34 = 'r' ;
break;
case '\t' :
V_34 = 't' ;
break;
case '\v' :
V_34 = 'v' ;
break;
case '\f' :
V_34 = 'f' ;
break;
default:
return false ;
}
if ( V_20 < V_33 )
* V_20 = '\\' ;
++ V_20 ;
if ( V_20 < V_33 )
* V_20 = V_34 ;
++ V_20 ;
* V_22 = V_20 ;
return true ;
}
static bool F_13 ( unsigned char V_32 , char * * V_22 , char * V_33 )
{
char * V_20 = * V_22 ;
unsigned char V_34 ;
switch ( V_32 ) {
case '\\' :
V_34 = '\\' ;
break;
case '\a' :
V_34 = 'a' ;
break;
case '\e' :
V_34 = 'e' ;
break;
default:
return false ;
}
if ( V_20 < V_33 )
* V_20 = '\\' ;
++ V_20 ;
if ( V_20 < V_33 )
* V_20 = V_34 ;
++ V_20 ;
* V_22 = V_20 ;
return true ;
}
static bool F_14 ( unsigned char V_32 , char * * V_22 , char * V_33 )
{
char * V_20 = * V_22 ;
if ( V_32 )
return false ;
if ( V_20 < V_33 )
* V_20 = '\\' ;
++ V_20 ;
if ( V_20 < V_33 )
* V_20 = '0' ;
++ V_20 ;
* V_22 = V_20 ;
return true ;
}
static bool F_15 ( unsigned char V_32 , char * * V_22 , char * V_33 )
{
char * V_20 = * V_22 ;
if ( V_20 < V_33 )
* V_20 = '\\' ;
++ V_20 ;
if ( V_20 < V_33 )
* V_20 = ( ( V_32 >> 6 ) & 0x07 ) + '0' ;
++ V_20 ;
if ( V_20 < V_33 )
* V_20 = ( ( V_32 >> 3 ) & 0x07 ) + '0' ;
++ V_20 ;
if ( V_20 < V_33 )
* V_20 = ( ( V_32 >> 0 ) & 0x07 ) + '0' ;
++ V_20 ;
* V_22 = V_20 ;
return true ;
}
static bool F_16 ( unsigned char V_32 , char * * V_22 , char * V_33 )
{
char * V_20 = * V_22 ;
if ( V_20 < V_33 )
* V_20 = '\\' ;
++ V_20 ;
if ( V_20 < V_33 )
* V_20 = 'x' ;
++ V_20 ;
if ( V_20 < V_33 )
* V_20 = F_17 ( V_32 ) ;
++ V_20 ;
if ( V_20 < V_33 )
* V_20 = F_18 ( V_32 ) ;
++ V_20 ;
* V_22 = V_20 ;
return true ;
}
int F_19 ( const char * V_21 , T_4 V_35 , char * V_22 , T_4 V_36 ,
unsigned int V_27 , const char * V_37 )
{
char * V_23 = V_22 ;
char * V_33 = V_23 + V_36 ;
bool V_38 = V_37 && * V_37 ;
while ( V_35 -- ) {
unsigned char V_32 = * V_21 ++ ;
if ( ( V_27 & V_39 && isprint ( V_32 ) ) ||
( V_38 && ! strchr ( V_37 , V_32 ) ) ) {
} else {
if ( V_27 & V_40 && F_12 ( V_32 , & V_23 , V_33 ) )
continue;
if ( V_27 & V_41 && F_13 ( V_32 , & V_23 , V_33 ) )
continue;
if ( V_27 & V_42 && F_14 ( V_32 , & V_23 , V_33 ) )
continue;
if ( V_27 & V_43 && F_15 ( V_32 , & V_23 , V_33 ) )
continue;
if ( V_27 & V_44 && F_16 ( V_32 , & V_23 , V_33 ) )
continue;
}
F_11 ( V_32 , & V_23 , V_33 ) ;
}
return V_23 - V_22 ;
}
char * F_20 ( const char * V_21 , T_5 V_45 )
{
T_4 V_46 , V_47 ;
char * V_22 ;
const int V_27 = V_44 ;
const char V_48 [] = L_21 ;
if ( ! V_21 )
return NULL ;
V_46 = strlen ( V_21 ) ;
V_47 = F_19 ( V_21 , V_46 , NULL , 0 , V_27 , V_48 ) ;
V_22 = F_21 ( V_47 + 1 , V_45 ) ;
if ( ! V_22 )
return NULL ;
F_22 ( F_19 ( V_21 , V_46 , V_22 , V_47 , V_27 , V_48 ) != V_47 ) ;
V_22 [ V_47 ] = '\0' ;
return V_22 ;
}
char * F_23 ( struct V_49 * V_50 , T_5 V_45 )
{
char * V_51 , * V_52 ;
int V_14 , V_53 ;
V_51 = F_21 ( V_54 , V_55 ) ;
if ( ! V_51 )
return NULL ;
V_53 = F_24 ( V_50 , V_51 , V_54 - 1 ) ;
V_51 [ V_53 ] = '\0' ;
while ( -- V_53 >= 0 && V_51 [ V_53 ] == '\0' )
;
for ( V_14 = 0 ; V_14 <= V_53 ; V_14 ++ )
if ( V_51 [ V_14 ] == '\0' )
V_51 [ V_14 ] = ' ' ;
V_52 = F_20 ( V_51 , V_45 ) ;
F_25 ( V_51 ) ;
return V_52 ;
}
char * F_26 ( struct V_56 * V_56 , T_5 V_45 )
{
char * V_57 , * V_58 ;
if ( ! V_56 )
return F_27 ( L_22 , V_45 ) ;
V_57 = F_21 ( V_59 + 11 , V_55 ) ;
if ( ! V_57 )
return F_27 ( L_23 , V_45 ) ;
V_58 = F_28 ( V_56 , V_57 , V_59 + 11 ) ;
if ( F_29 ( V_58 ) )
V_58 = F_27 ( L_24 , V_45 ) ;
else
V_58 = F_20 ( V_58 , V_45 ) ;
F_25 ( V_57 ) ;
return V_58 ;
}
