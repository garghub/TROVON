char * F_1 ( const char * V_1 )
{
int V_2 = strlen ( V_1 ) + 1 ;
char * V_3 = xmalloc ( V_2 ) ;
memcpy ( V_3 , V_1 , V_2 ) ;
return V_3 ;
}
int F_2 ( char * * V_4 , const char * V_5 , ... )
{
int V_6 , V_7 = 128 ;
char * V_8 ;
T_1 V_9 ;
V_8 = NULL ;
while ( 1 ) {
V_8 = F_3 ( V_8 , V_7 ) ;
va_start ( V_9 , V_5 ) ;
V_6 = vsnprintf ( V_8 , V_7 , V_5 , V_9 ) ;
va_end ( V_9 ) ;
if ( V_6 > - 1 && V_6 < V_7 )
break;
if ( V_6 > - 1 )
V_7 = V_6 + 1 ;
else
V_7 *= 2 ;
}
* V_4 = V_8 ;
return strlen ( V_8 ) ;
}
char * F_4 ( const char * V_10 , const char * V_11 )
{
int V_12 = strlen ( V_10 ) ;
int V_13 = strlen ( V_11 ) ;
int V_2 ;
int V_14 = 1 ;
char * V_15 ;
V_2 = V_12 + V_13 + 2 ;
if ( ( V_12 > 0 ) && ( V_10 [ V_12 - 1 ] == '/' ) ) {
V_14 = 0 ;
V_2 -- ;
}
V_15 = xmalloc ( V_2 ) ;
memcpy ( V_15 , V_10 , V_12 ) ;
if ( V_14 ) {
V_15 [ V_12 ] = '/' ;
V_12 ++ ;
}
memcpy ( V_15 + V_12 , V_11 , V_13 + 1 ) ;
return V_15 ;
}
bool F_5 ( const void * V_16 , int V_2 )
{
const char * V_1 = V_16 ;
const char * V_17 , * V_18 ;
if ( V_2 == 0 )
return 0 ;
if ( V_1 [ V_2 - 1 ] != '\0' )
return 0 ;
V_18 = V_1 + V_2 ;
while ( V_1 < V_18 ) {
V_17 = V_1 ;
while ( V_1 < V_18 && * V_1 && isprint ( ( unsigned char ) * V_1 ) )
V_1 ++ ;
if ( * V_1 != '\0' || V_1 == V_17 )
return 0 ;
V_1 ++ ;
}
return 1 ;
}
static char F_6 ( const char * V_1 , int * V_19 )
{
char V_20 [ 4 ] ;
char * V_21 ;
long V_22 ;
V_20 [ 3 ] = '\0' ;
strncpy ( V_20 , V_1 + * V_19 , 3 ) ;
V_22 = strtol ( V_20 , & V_21 , 8 ) ;
assert ( V_21 > V_20 ) ;
( * V_19 ) += V_21 - V_20 ;
return V_22 ;
}
static char F_7 ( const char * V_1 , int * V_19 )
{
char V_20 [ 3 ] ;
char * V_21 ;
long V_22 ;
V_20 [ 2 ] = '\0' ;
strncpy ( V_20 , V_1 + * V_19 , 2 ) ;
V_22 = strtol ( V_20 , & V_21 , 16 ) ;
if ( ! ( V_21 > V_20 ) )
F_8 ( L_1 ) ;
( * V_19 ) += V_21 - V_20 ;
return V_22 ;
}
char F_9 ( const char * V_1 , int * V_19 )
{
char V_23 = V_1 [ * V_19 ] ;
int V_24 = * V_19 + 1 ;
char V_22 ;
switch ( V_23 ) {
case 'a' :
V_22 = '\a' ;
break;
case 'b' :
V_22 = '\b' ;
break;
case 't' :
V_22 = '\t' ;
break;
case 'n' :
V_22 = '\n' ;
break;
case 'v' :
V_22 = '\v' ;
break;
case 'f' :
V_22 = '\f' ;
break;
case 'r' :
V_22 = '\r' ;
break;
case '0' :
case '1' :
case '2' :
case '3' :
case '4' :
case '5' :
case '6' :
case '7' :
V_24 -- ;
V_22 = F_6 ( V_1 , & V_24 ) ;
break;
case 'x' :
V_22 = F_7 ( V_1 , & V_24 ) ;
break;
default:
V_22 = V_23 ;
}
( * V_19 ) = V_24 ;
return V_22 ;
}
int F_10 ( const char * V_25 , char * * V_26 , T_2 * V_2 )
{
int V_27 = 0 ;
char * V_28 = NULL ;
T_2 V_29 = 1024 , V_30 = 0 ;
int V_31 = 0 ;
* V_26 = NULL ;
if ( strcmp ( V_25 , L_2 ) != 0 ) {
V_27 = F_11 ( V_25 , V_32 ) ;
if ( V_27 < 0 )
return V_33 ;
}
V_28 = xmalloc ( V_29 ) ;
do {
if ( V_30 == V_29 ) {
V_29 *= 2 ;
V_28 = F_3 ( V_28 , V_29 ) ;
}
V_31 = F_12 ( V_27 , & V_28 [ V_30 ] , V_29 - V_30 ) ;
if ( V_31 < 0 ) {
V_31 = V_33 ;
break;
}
V_30 += V_31 ;
} while ( V_31 != 0 );
F_13 ( V_27 ) ;
if ( V_31 )
free ( V_28 ) ;
else
* V_26 = V_28 ;
* V_2 = V_29 ;
return V_31 ;
}
int F_14 ( const char * V_25 , char * * V_26 )
{
T_2 V_2 ;
return F_10 ( V_25 , V_26 , & V_2 ) ;
}
char * F_15 ( const char * V_25 , T_2 * V_2 )
{
char * V_34 ;
int V_31 = F_10 ( V_25 , & V_34 , V_2 ) ;
if ( V_31 ) {
fprintf ( V_35 , L_3 , V_25 ,
strerror ( V_31 ) ) ;
return NULL ;
}
return V_34 ;
}
char * F_16 ( const char * V_25 )
{
T_2 V_2 ;
return F_15 ( V_25 , & V_2 ) ;
}
int F_17 ( const char * V_25 , const void * V_36 )
{
int V_27 = 1 ;
int V_37 ;
int V_30 ;
int V_31 = 0 ;
const char * V_38 = V_36 ;
if ( strcmp ( V_25 , L_2 ) != 0 ) {
V_27 = F_11 ( V_25 , V_39 | V_40 | V_41 , 0666 ) ;
if ( V_27 < 0 )
return V_33 ;
}
V_37 = F_18 ( V_36 ) ;
V_30 = 0 ;
while ( V_30 < V_37 ) {
V_31 = F_19 ( V_27 , V_38 + V_30 , V_37 - V_30 ) ;
if ( V_31 < 0 ) {
V_31 = - V_33 ;
break;
}
V_30 += V_31 ;
}
if ( V_27 != 1 )
F_13 ( V_27 ) ;
return V_31 < 0 ? - V_31 : 0 ;
}
int F_20 ( const char * V_25 , const void * V_36 )
{
int V_31 = F_17 ( V_25 , V_36 ) ;
if ( V_31 ) {
fprintf ( V_35 , L_4 , V_25 ,
strerror ( V_31 ) ) ;
}
return V_31 ? - 1 : 0 ;
}
int F_21 ( const char * V_5 , int * type , int * V_7 )
{
int V_42 = 0 ;
if ( ! * V_5 )
return - 1 ;
* V_7 = - 1 ;
if ( strchr ( L_5 , * V_5 ) ) {
V_42 = * V_5 ++ ;
if ( V_42 == * V_5 ) {
switch ( * V_5 ++ ) {
case 'h' :
V_42 = 'b' ;
break;
}
}
}
if ( ( * V_5 == '\0' ) || ! strchr ( L_6 , * V_5 ) )
return - 1 ;
if ( * V_5 != 's' )
* V_7 = V_42 == 'b' ? 1 :
V_42 == 'h' ? 2 :
V_42 == 'l' ? 4 : - 1 ;
* type = * V_5 ++ ;
if ( * V_5 )
return - 1 ;
return 0 ;
}
void F_22 ( const char * V_16 , int V_2 )
{
int V_19 ;
const char * V_1 ;
if ( V_2 == 0 )
return;
if ( F_5 ( V_16 , V_2 ) ) {
printf ( L_7 ) ;
V_1 = V_16 ;
do {
printf ( L_8 , V_1 ) ;
V_1 += strlen ( V_1 ) + 1 ;
if ( V_1 < V_16 + V_2 )
printf ( L_9 ) ;
} while ( V_1 < V_16 + V_2 );
} else if ( ( V_2 % 4 ) == 0 ) {
const T_3 * V_43 = ( const T_3 * ) V_16 ;
printf ( L_10 ) ;
for ( V_19 = 0 , V_2 /= 4 ; V_19 < V_2 ; V_19 ++ )
printf ( L_11 , F_23 ( V_43 [ V_19 ] ) ,
V_19 < ( V_2 - 1 ) ? L_12 : L_13 ) ;
printf ( L_14 ) ;
} else {
const unsigned char * V_8 = ( const unsigned char * ) V_16 ;
printf ( L_15 ) ;
for ( V_19 = 0 ; V_19 < V_2 ; V_19 ++ )
printf ( L_16 , * V_8 ++ , V_19 < V_2 - 1 ? L_12 : L_13 ) ;
printf ( L_17 ) ;
}
}
void NORETURN F_24 ( void )
{
printf ( L_18 , V_44 ) ;
exit ( 0 ) ;
}
void NORETURN F_25 ( const char * V_45 , const char * V_46 ,
const char * V_47 ,
struct V_48 const V_49 [] ,
const char * const V_50 [] )
{
T_4 * V_51 = V_45 ? V_35 : stdout ;
const char V_52 [] = L_19 ;
T_5 V_53 = strlen ( V_52 ) + 1 ;
T_5 V_19 ;
int V_54 ;
fprintf ( V_51 ,
L_20
L_21
L_22 , V_46 , V_47 ) ;
V_54 = 0 ;
for ( V_19 = 0 ; V_49 [ V_19 ] . V_11 ; ++ V_19 ) {
int V_55 = strlen ( V_49 [ V_19 ] . V_11 ) + 1 ;
if ( V_49 [ V_19 ] . V_56 == V_57 )
V_55 += V_53 ;
if ( V_54 < V_55 )
V_54 = V_55 ;
}
for ( V_19 = 0 ; V_49 [ V_19 ] . V_11 ; ++ V_19 ) {
assert ( V_50 [ V_19 ] != NULL ) ;
if ( V_49 [ V_19 ] . V_22 > '~' )
fprintf ( V_51 , L_23 ) ;
else
fprintf ( V_51 , L_24 , V_49 [ V_19 ] . V_22 ) ;
if ( V_49 [ V_19 ] . V_56 == V_58 )
fprintf ( V_51 , L_25 , V_54 , V_49 [ V_19 ] . V_11 ) ;
else
fprintf ( V_51 , L_26 , V_49 [ V_19 ] . V_11 , V_52 ,
( int ) ( V_54 - strlen ( V_49 [ V_19 ] . V_11 ) - V_53 ) , L_13 ) ;
fprintf ( V_51 , L_27 , V_50 [ V_19 ] ) ;
}
if ( V_45 ) {
fprintf ( V_51 , L_28 , V_45 ) ;
exit ( V_59 ) ;
} else
exit ( V_60 ) ;
}
