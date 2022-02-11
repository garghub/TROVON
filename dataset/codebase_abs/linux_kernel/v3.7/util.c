char * F_1 ( const char * V_1 )
{
int V_2 = strlen ( V_1 ) + 1 ;
char * V_3 = xmalloc ( V_2 ) ;
memcpy ( V_3 , V_1 , V_2 ) ;
return V_3 ;
}
char * F_2 ( const char * V_4 , const char * V_5 )
{
int V_6 = strlen ( V_4 ) ;
int V_7 = strlen ( V_5 ) ;
int V_2 ;
int V_8 = 1 ;
char * V_9 ;
V_2 = V_6 + V_7 + 2 ;
if ( ( V_6 > 0 ) && ( V_4 [ V_6 - 1 ] == '/' ) ) {
V_8 = 0 ;
V_2 -- ;
}
V_9 = xmalloc ( V_2 ) ;
memcpy ( V_9 , V_4 , V_6 ) ;
if ( V_8 ) {
V_9 [ V_6 ] = '/' ;
V_6 ++ ;
}
memcpy ( V_9 + V_6 , V_5 , V_7 + 1 ) ;
return V_9 ;
}
int F_3 ( const void * V_10 , int V_2 )
{
const char * V_1 = V_10 ;
const char * V_11 ;
if ( V_2 == 0 )
return 0 ;
if ( V_1 [ V_2 - 1 ] != '\0' )
return 0 ;
V_11 = V_1 ;
while ( * V_1 && isprint ( * V_1 ) )
V_1 ++ ;
if ( * V_1 != '\0' || ( V_1 + 1 - V_11 ) < V_2 )
return 0 ;
return 1 ;
}
static char F_4 ( const char * V_1 , int * V_12 )
{
char V_13 [ 4 ] ;
char * V_14 ;
long V_15 ;
V_13 [ 3 ] = '\0' ;
strncpy ( V_13 , V_1 + * V_12 , 3 ) ;
V_15 = strtol ( V_13 , & V_14 , 8 ) ;
assert ( V_14 > V_13 ) ;
( * V_12 ) += V_14 - V_13 ;
return V_15 ;
}
static char F_5 ( const char * V_1 , int * V_12 )
{
char V_13 [ 3 ] ;
char * V_14 ;
long V_15 ;
V_13 [ 2 ] = '\0' ;
strncpy ( V_13 , V_1 + * V_12 , 2 ) ;
V_15 = strtol ( V_13 , & V_14 , 16 ) ;
if ( ! ( V_14 > V_13 ) )
F_6 ( L_1 ) ;
( * V_12 ) += V_14 - V_13 ;
return V_15 ;
}
char F_7 ( const char * V_1 , int * V_12 )
{
char V_16 = V_1 [ * V_12 ] ;
int V_17 = * V_12 + 1 ;
char V_15 ;
assert ( V_16 ) ;
switch ( V_16 ) {
case 'a' :
V_15 = '\a' ;
break;
case 'b' :
V_15 = '\b' ;
break;
case 't' :
V_15 = '\t' ;
break;
case 'n' :
V_15 = '\n' ;
break;
case 'v' :
V_15 = '\v' ;
break;
case 'f' :
V_15 = '\f' ;
break;
case 'r' :
V_15 = '\r' ;
break;
case '0' :
case '1' :
case '2' :
case '3' :
case '4' :
case '5' :
case '6' :
case '7' :
V_17 -- ;
V_15 = F_4 ( V_1 , & V_17 ) ;
break;
case 'x' :
V_15 = F_5 ( V_1 , & V_17 ) ;
break;
default:
V_15 = V_16 ;
}
( * V_12 ) = V_17 ;
return V_15 ;
}
int F_8 ( const char * V_18 , char * * V_19 )
{
int V_20 = 0 ;
char * V_21 = NULL ;
T_1 V_22 = 1024 , V_23 = 0 ;
int V_24 = 0 ;
* V_19 = NULL ;
if ( strcmp ( V_18 , L_2 ) != 0 ) {
V_20 = F_9 ( V_18 , V_25 ) ;
if ( V_20 < 0 )
return V_26 ;
}
V_21 = malloc ( V_22 ) ;
do {
if ( V_23 == V_22 ) {
V_22 *= 2 ;
V_21 = realloc ( V_21 , V_22 ) ;
if ( ! V_21 ) {
V_24 = V_27 ;
break;
}
}
V_24 = F_10 ( V_20 , & V_21 [ V_23 ] , V_22 - V_23 ) ;
if ( V_24 < 0 ) {
V_24 = V_26 ;
break;
}
V_23 += V_24 ;
} while ( V_24 != 0 );
F_11 ( V_20 ) ;
if ( V_24 )
free ( V_21 ) ;
else
* V_19 = V_21 ;
return V_24 ;
}
char * F_12 ( const char * V_18 )
{
char * V_28 ;
int V_24 = F_8 ( V_18 , & V_28 ) ;
if ( V_24 ) {
fprintf ( V_29 , L_3 , V_18 ,
strerror ( V_24 ) ) ;
return NULL ;
}
return V_28 ;
}
int F_13 ( const char * V_18 , const void * V_30 )
{
int V_20 = 1 ;
int V_31 ;
int V_23 ;
int V_24 = 0 ;
const char * V_32 = V_30 ;
if ( strcmp ( V_18 , L_2 ) != 0 ) {
V_20 = F_9 ( V_18 , V_33 | V_34 | V_35 , 0666 ) ;
if ( V_20 < 0 )
return V_26 ;
}
V_31 = F_14 ( V_30 ) ;
V_23 = 0 ;
while ( V_23 < V_31 ) {
V_24 = F_15 ( V_20 , V_32 + V_23 , V_31 - V_23 ) ;
if ( V_24 < 0 ) {
V_24 = - V_26 ;
break;
}
V_23 += V_24 ;
}
if ( V_20 != 1 )
F_11 ( V_20 ) ;
return V_24 < 0 ? - V_24 : 0 ;
}
int F_16 ( const char * V_18 , const void * V_30 )
{
int V_24 = F_13 ( V_18 , V_30 ) ;
if ( V_24 ) {
fprintf ( V_29 , L_4 , V_18 ,
strerror ( V_24 ) ) ;
}
return V_24 ? - 1 : 0 ;
}
int F_17 ( const char * V_36 , int * type , int * V_37 )
{
int V_38 = 0 ;
if ( ! * V_36 )
return - 1 ;
* V_37 = - 1 ;
if ( strchr ( L_5 , * V_36 ) ) {
V_38 = * V_36 ++ ;
if ( V_38 == * V_36 ) {
switch ( * V_36 ++ ) {
case 'h' :
V_38 = 'b' ;
break;
}
}
}
if ( ( * V_36 == '\0' ) || ! strchr ( L_6 , * V_36 ) )
return - 1 ;
if ( * V_36 != 's' )
* V_37 = V_38 == 'b' ? 1 :
V_38 == 'h' ? 2 :
V_38 == 'l' ? 4 : - 1 ;
* type = * V_36 ++ ;
if ( * V_36 )
return - 1 ;
return 0 ;
}
