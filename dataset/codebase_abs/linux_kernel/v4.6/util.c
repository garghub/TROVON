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
bool F_3 ( const void * V_10 , int V_2 )
{
const char * V_1 = V_10 ;
const char * V_11 , * V_12 ;
if ( V_2 == 0 )
return 0 ;
if ( V_1 [ V_2 - 1 ] != '\0' )
return 0 ;
V_12 = V_1 + V_2 ;
while ( V_1 < V_12 ) {
V_11 = V_1 ;
while ( V_1 < V_12 && * V_1 && isprint ( ( unsigned char ) * V_1 ) )
V_1 ++ ;
if ( * V_1 != '\0' || V_1 == V_11 )
return 0 ;
V_1 ++ ;
}
return 1 ;
}
static char F_4 ( const char * V_1 , int * V_13 )
{
char V_14 [ 4 ] ;
char * V_15 ;
long V_16 ;
V_14 [ 3 ] = '\0' ;
strncpy ( V_14 , V_1 + * V_13 , 3 ) ;
V_16 = strtol ( V_14 , & V_15 , 8 ) ;
assert ( V_15 > V_14 ) ;
( * V_13 ) += V_15 - V_14 ;
return V_16 ;
}
static char F_5 ( const char * V_1 , int * V_13 )
{
char V_14 [ 3 ] ;
char * V_15 ;
long V_16 ;
V_14 [ 2 ] = '\0' ;
strncpy ( V_14 , V_1 + * V_13 , 2 ) ;
V_16 = strtol ( V_14 , & V_15 , 16 ) ;
if ( ! ( V_15 > V_14 ) )
F_6 ( L_1 ) ;
( * V_13 ) += V_15 - V_14 ;
return V_16 ;
}
char F_7 ( const char * V_1 , int * V_13 )
{
char V_17 = V_1 [ * V_13 ] ;
int V_18 = * V_13 + 1 ;
char V_16 ;
switch ( V_17 ) {
case 'a' :
V_16 = '\a' ;
break;
case 'b' :
V_16 = '\b' ;
break;
case 't' :
V_16 = '\t' ;
break;
case 'n' :
V_16 = '\n' ;
break;
case 'v' :
V_16 = '\v' ;
break;
case 'f' :
V_16 = '\f' ;
break;
case 'r' :
V_16 = '\r' ;
break;
case '0' :
case '1' :
case '2' :
case '3' :
case '4' :
case '5' :
case '6' :
case '7' :
V_18 -- ;
V_16 = F_4 ( V_1 , & V_18 ) ;
break;
case 'x' :
V_16 = F_5 ( V_1 , & V_18 ) ;
break;
default:
V_16 = V_17 ;
}
( * V_13 ) = V_18 ;
return V_16 ;
}
int F_8 ( const char * V_19 , char * * V_20 , T_1 * V_2 )
{
int V_21 = 0 ;
char * V_22 = NULL ;
T_1 V_23 = 1024 , V_24 = 0 ;
int V_25 = 0 ;
* V_20 = NULL ;
if ( strcmp ( V_19 , L_2 ) != 0 ) {
V_21 = F_9 ( V_19 , V_26 ) ;
if ( V_21 < 0 )
return V_27 ;
}
V_22 = xmalloc ( V_23 ) ;
do {
if ( V_24 == V_23 ) {
V_23 *= 2 ;
V_22 = F_10 ( V_22 , V_23 ) ;
}
V_25 = F_11 ( V_21 , & V_22 [ V_24 ] , V_23 - V_24 ) ;
if ( V_25 < 0 ) {
V_25 = V_27 ;
break;
}
V_24 += V_25 ;
} while ( V_25 != 0 );
F_12 ( V_21 ) ;
if ( V_25 )
free ( V_22 ) ;
else
* V_20 = V_22 ;
* V_2 = V_23 ;
return V_25 ;
}
int F_13 ( const char * V_19 , char * * V_20 )
{
T_1 V_2 ;
return F_8 ( V_19 , V_20 , & V_2 ) ;
}
char * F_14 ( const char * V_19 , T_1 * V_2 )
{
char * V_28 ;
int V_25 = F_8 ( V_19 , & V_28 , V_2 ) ;
if ( V_25 ) {
fprintf ( V_29 , L_3 , V_19 ,
strerror ( V_25 ) ) ;
return NULL ;
}
return V_28 ;
}
char * F_15 ( const char * V_19 )
{
T_1 V_2 ;
return F_14 ( V_19 , & V_2 ) ;
}
int F_16 ( const char * V_19 , const void * V_30 )
{
int V_21 = 1 ;
int V_31 ;
int V_24 ;
int V_25 = 0 ;
const char * V_32 = V_30 ;
if ( strcmp ( V_19 , L_2 ) != 0 ) {
V_21 = F_9 ( V_19 , V_33 | V_34 | V_35 , 0666 ) ;
if ( V_21 < 0 )
return V_27 ;
}
V_31 = F_17 ( V_30 ) ;
V_24 = 0 ;
while ( V_24 < V_31 ) {
V_25 = F_18 ( V_21 , V_32 + V_24 , V_31 - V_24 ) ;
if ( V_25 < 0 ) {
V_25 = - V_27 ;
break;
}
V_24 += V_25 ;
}
if ( V_21 != 1 )
F_12 ( V_21 ) ;
return V_25 < 0 ? - V_25 : 0 ;
}
int F_19 ( const char * V_19 , const void * V_30 )
{
int V_25 = F_16 ( V_19 , V_30 ) ;
if ( V_25 ) {
fprintf ( V_29 , L_4 , V_19 ,
strerror ( V_25 ) ) ;
}
return V_25 ? - 1 : 0 ;
}
int F_20 ( const char * V_36 , int * type , int * V_37 )
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
void F_21 ( const char * V_10 , int V_2 )
{
int V_13 ;
const char * V_1 ;
if ( V_2 == 0 )
return;
if ( F_3 ( V_10 , V_2 ) ) {
printf ( L_7 ) ;
V_1 = V_10 ;
do {
printf ( L_8 , V_1 ) ;
V_1 += strlen ( V_1 ) + 1 ;
if ( V_1 < V_10 + V_2 )
printf ( L_9 ) ;
} while ( V_1 < V_10 + V_2 );
} else if ( ( V_2 % 4 ) == 0 ) {
const T_2 * V_39 = ( const T_2 * ) V_10 ;
printf ( L_10 ) ;
for ( V_13 = 0 , V_2 /= 4 ; V_13 < V_2 ; V_13 ++ )
printf ( L_11 , F_22 ( V_39 [ V_13 ] ) ,
V_13 < ( V_2 - 1 ) ? L_12 : L_13 ) ;
printf ( L_14 ) ;
} else {
const unsigned char * V_40 = ( const unsigned char * ) V_10 ;
printf ( L_15 ) ;
for ( V_13 = 0 ; V_13 < V_2 ; V_13 ++ )
printf ( L_16 , * V_40 ++ , V_13 < V_2 - 1 ? L_12 : L_13 ) ;
printf ( L_17 ) ;
}
}
void F_23 ( void )
{
printf ( L_18 , V_41 ) ;
exit ( 0 ) ;
}
void F_24 ( const char * V_42 , const char * V_43 ,
const char * V_44 , struct V_45 const V_46 [] ,
const char * const V_47 [] )
{
T_3 * V_48 = V_42 ? V_29 : stdout ;
const char V_49 [] = L_19 ;
T_4 V_50 = strlen ( V_49 ) + 1 ;
T_4 V_13 ;
int V_51 ;
fprintf ( V_48 ,
L_20
L_21
L_22 , V_43 , V_44 ) ;
V_51 = 0 ;
for ( V_13 = 0 ; V_46 [ V_13 ] . V_5 ; ++ V_13 ) {
int V_52 = strlen ( V_46 [ V_13 ] . V_5 ) + 1 ;
if ( V_46 [ V_13 ] . V_53 == V_54 )
V_52 += V_50 ;
if ( V_51 < V_52 )
V_51 = V_52 ;
}
for ( V_13 = 0 ; V_46 [ V_13 ] . V_5 ; ++ V_13 ) {
assert ( V_47 [ V_13 ] != NULL ) ;
if ( V_46 [ V_13 ] . V_16 > '~' )
fprintf ( V_48 , L_23 ) ;
else
fprintf ( V_48 , L_24 , V_46 [ V_13 ] . V_16 ) ;
if ( V_46 [ V_13 ] . V_53 == V_55 )
fprintf ( V_48 , L_25 , V_51 , V_46 [ V_13 ] . V_5 ) ;
else
fprintf ( V_48 , L_26 , V_46 [ V_13 ] . V_5 , V_49 ,
( int ) ( V_51 - strlen ( V_46 [ V_13 ] . V_5 ) - V_50 ) , L_13 ) ;
fprintf ( V_48 , L_27 , V_47 [ V_13 ] ) ;
}
if ( V_42 ) {
fprintf ( V_48 , L_28 , V_42 ) ;
exit ( V_56 ) ;
} else
exit ( V_57 ) ;
}
