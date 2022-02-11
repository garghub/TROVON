static unsigned int F_1 ( T_1 * V_1 )
{
int V_2 , V_3 ;
do {
V_2 = fgetc ( V_1 ) ;
if ( V_2 == V_4 )
F_2 ( L_1 , V_5 ) ;
if ( V_2 == '#' ) {
do {
V_2 = fgetc ( V_1 ) ;
if ( V_2 == V_4 )
F_2 ( L_1 , V_5 ) ;
} while ( V_2 != '\n' );
}
} while ( isspace ( V_2 ) );
V_3 = 0 ;
while ( isdigit ( V_2 ) ) {
V_3 = 10 * V_3 + V_2 - '0' ;
if ( V_6 )
break;
V_2 = fgetc ( V_1 ) ;
if ( V_2 == V_4 )
F_2 ( L_1 , V_5 ) ;
}
return V_3 ;
}
static unsigned int F_3 ( T_1 * V_1 , unsigned int V_7 )
{
unsigned int V_3 = F_1 ( V_1 ) ;
return ( 255 * V_3 + V_7 / 2 ) / V_7 ;
}
static void F_4 ( void )
{
T_1 * V_1 ;
unsigned int V_8 , V_9 ;
int V_10 ;
unsigned int V_7 ;
V_1 = fopen ( V_5 , L_2 ) ;
if ( ! V_1 )
F_2 ( L_3 , V_5 , strerror ( V_11 ) ) ;
V_10 = fgetc ( V_1 ) ;
if ( V_10 != 'P' )
F_2 ( L_4 , V_5 ) ;
V_10 = fgetc ( V_1 ) ;
switch ( V_10 ) {
case '1' :
case '2' :
case '3' :
break;
case '4' :
case '5' :
case '6' :
F_2 ( L_5
L_6 , V_5 ) ;
default:
F_2 ( L_4 , V_5 ) ;
}
V_12 = F_1 ( V_1 ) ;
V_13 = F_1 ( V_1 ) ;
V_14 = (struct V_15 * * ) malloc ( V_13 * sizeof( struct V_15 * ) ) ;
if ( ! V_14 )
F_2 ( L_7 , strerror ( V_11 ) ) ;
for ( V_8 = 0 ; V_8 < V_13 ; V_8 ++ ) {
V_14 [ V_8 ] = malloc ( V_12 * sizeof( struct V_15 ) ) ;
if ( ! V_14 [ V_8 ] )
F_2 ( L_7 , strerror ( V_11 ) ) ;
}
switch ( V_10 ) {
case '1' :
V_6 = 1 ;
for ( V_8 = 0 ; V_8 < V_13 ; V_8 ++ )
for ( V_9 = 0 ; V_9 < V_12 ; V_9 ++ )
V_14 [ V_8 ] [ V_9 ] . V_16 = V_14 [ V_8 ] [ V_9 ] . V_17 =
V_14 [ V_8 ] [ V_9 ] . V_18 = 255 * ( 1 - F_1 ( V_1 ) ) ;
break;
case '2' :
V_7 = F_1 ( V_1 ) ;
for ( V_8 = 0 ; V_8 < V_13 ; V_8 ++ )
for ( V_9 = 0 ; V_9 < V_12 ; V_9 ++ )
V_14 [ V_8 ] [ V_9 ] . V_16 = V_14 [ V_8 ] [ V_9 ] . V_17 =
V_14 [ V_8 ] [ V_9 ] . V_18 = F_3 ( V_1 , V_7 ) ;
break;
case '3' :
V_7 = F_1 ( V_1 ) ;
for ( V_8 = 0 ; V_8 < V_13 ; V_8 ++ )
for ( V_9 = 0 ; V_9 < V_12 ; V_9 ++ ) {
V_14 [ V_8 ] [ V_9 ] . V_16 = F_3 ( V_1 , V_7 ) ;
V_14 [ V_8 ] [ V_9 ] . V_17 = F_3 ( V_1 , V_7 ) ;
V_14 [ V_8 ] [ V_9 ] . V_18 = F_3 ( V_1 , V_7 ) ;
}
break;
}
fclose ( V_1 ) ;
}
static inline int F_5 ( struct V_15 V_2 )
{
return V_2 . V_16 == 0 && V_2 . V_17 == 0 && V_2 . V_18 == 0 ;
}
static inline int F_6 ( struct V_15 V_2 )
{
return V_2 . V_16 == 255 && V_2 . V_17 == 255 && V_2 . V_18 == 255 ;
}
static inline int F_7 ( struct V_15 V_2 )
{
return V_2 . V_16 == V_2 . V_17 && V_2 . V_16 == V_2 . V_18 ;
}
static inline int F_8 ( struct V_15 V_19 , struct V_15 V_20 )
{
return V_19 . V_16 == V_20 . V_16 && V_19 . V_17 == V_20 . V_17 && V_19 . V_18 == V_20 . V_18 ;
}
static void F_9 ( void )
{
if ( V_21 ) {
V_22 = fopen ( V_21 , L_8 ) ;
if ( ! V_22 )
F_2 ( L_9 , V_21 , strerror ( V_11 ) ) ;
} else {
V_22 = stdout ;
}
fputs ( L_10 , V_22 ) ;
fputs ( L_11 , V_22 ) ;
fputs ( L_12 , V_22 ) ;
fprintf ( V_22 , L_13 , V_5 ) ;
fputs ( L_12 , V_22 ) ;
fprintf ( V_22 , L_14 , V_23 ) ;
fputs ( L_15 , V_22 ) ;
fputs ( L_16 , V_22 ) ;
fprintf ( V_22 , L_17 ,
V_23 ) ;
}
static void F_10 ( void )
{
fputs ( L_18 , V_22 ) ;
fprintf ( V_22 , L_19 , V_23 ) ;
fprintf ( V_22 , L_20 , V_24 [ V_25 ] ) ;
fprintf ( V_22 , L_21 , V_12 ) ;
fprintf ( V_22 , L_22 , V_13 ) ;
if ( V_25 == V_26 ) {
fprintf ( V_22 , L_23 , V_27 ) ;
fprintf ( V_22 , L_24 , V_23 ) ;
}
fprintf ( V_22 , L_25 , V_23 ) ;
fputs ( L_26 , V_22 ) ;
if ( V_21 )
fclose ( V_22 ) ;
}
static void F_11 ( unsigned char V_28 )
{
if ( V_29 % 12 )
fprintf ( V_22 , L_27 , V_28 ) ;
else if ( V_29 )
fprintf ( V_22 , L_28 , V_28 ) ;
else
fprintf ( V_22 , L_29 , V_28 ) ;
V_29 ++ ;
}
static void F_12 ( void )
{
unsigned int V_8 , V_9 ;
unsigned char V_3 , V_30 ;
for ( V_8 = 0 ; V_8 < V_13 ; V_8 ++ )
for ( V_9 = 0 ; V_9 < V_12 ; V_9 ++ )
if ( ! F_5 ( V_14 [ V_8 ] [ V_9 ] ) && ! F_6 ( V_14 [ V_8 ] [ V_9 ] ) )
F_2 ( L_30 ) ;
F_9 () ;
for ( V_8 = 0 ; V_8 < V_13 ; V_8 ++ ) {
for ( V_9 = 0 ; V_9 < V_12 ; ) {
for ( V_3 = 0 , V_30 = 0x80 ; V_30 && V_9 < V_12 ; V_9 ++ , V_30 >>= 1 )
if ( V_14 [ V_8 ] [ V_9 ] . V_16 )
V_3 |= V_30 ;
F_11 ( V_3 ) ;
}
}
F_10 () ;
}
static void F_13 ( void )
{
unsigned int V_8 , V_9 , V_31 ;
unsigned char V_3 ;
for ( V_8 = 0 ; V_8 < V_13 ; V_8 ++ )
for ( V_9 = 0 ; V_9 < V_12 ; V_9 ++ ) {
for ( V_31 = 0 ; V_31 < 16 ; V_31 ++ )
if ( F_8 ( V_14 [ V_8 ] [ V_9 ] , V_32 [ V_31 ] ) )
break;
if ( V_31 == 16 )
F_2 ( L_31
L_32
L_33 ) ;
}
F_9 () ;
for ( V_8 = 0 ; V_8 < V_13 ; V_8 ++ )
for ( V_9 = 0 ; V_9 < V_12 ; V_9 ++ ) {
for ( V_31 = 0 ; V_31 < 16 ; V_31 ++ )
if ( F_8 ( V_14 [ V_8 ] [ V_9 ] , V_32 [ V_31 ] ) )
break;
V_3 = V_31 << 4 ;
if ( ++ V_9 < V_12 ) {
for ( V_31 = 0 ; V_31 < 16 ; V_31 ++ )
if ( F_8 ( V_14 [ V_8 ] [ V_9 ] , V_32 [ V_31 ] ) )
break;
V_3 |= V_31 ;
}
F_11 ( V_3 ) ;
}
F_10 () ;
}
static void F_14 ( void )
{
unsigned int V_8 , V_9 , V_31 ;
for ( V_8 = 0 ; V_8 < V_13 ; V_8 ++ )
for ( V_9 = 0 ; V_9 < V_12 ; V_9 ++ ) {
for ( V_31 = 0 ; V_31 < V_27 ; V_31 ++ )
if ( F_8 ( V_14 [ V_8 ] [ V_9 ] , V_33 [ V_31 ] ) )
break;
if ( V_31 == V_27 ) {
if ( V_27 == V_34 )
F_2 ( L_34
L_35 ,
V_34 ) ;
V_33 [ V_27 ++ ] = V_14 [ V_8 ] [ V_9 ] ;
}
}
F_9 () ;
for ( V_8 = 0 ; V_8 < V_13 ; V_8 ++ )
for ( V_9 = 0 ; V_9 < V_12 ; V_9 ++ ) {
for ( V_31 = 0 ; V_31 < V_27 ; V_31 ++ )
if ( F_8 ( V_14 [ V_8 ] [ V_9 ] , V_33 [ V_31 ] ) )
break;
F_11 ( V_31 + 32 ) ;
}
fputs ( L_18 , V_22 ) ;
fprintf ( V_22 , L_36 ,
V_23 ) ;
V_29 = 0 ;
for ( V_8 = 0 ; V_8 < V_27 ; V_8 ++ ) {
F_11 ( V_33 [ V_8 ] . V_16 ) ;
F_11 ( V_33 [ V_8 ] . V_17 ) ;
F_11 ( V_33 [ V_8 ] . V_18 ) ;
}
F_10 () ;
}
static void F_15 ( void )
{
unsigned int V_8 , V_9 ;
for ( V_8 = 0 ; V_8 < V_13 ; V_8 ++ )
for ( V_9 = 0 ; V_9 < V_12 ; V_9 ++ )
if ( ! F_7 ( V_14 [ V_8 ] [ V_9 ] ) )
F_2 ( L_37 ) ;
F_9 () ;
for ( V_8 = 0 ; V_8 < V_13 ; V_8 ++ )
for ( V_9 = 0 ; V_9 < V_12 ; V_9 ++ )
F_11 ( V_14 [ V_8 ] [ V_9 ] . V_16 ) ;
F_10 () ;
}
static void F_2 ( const char * V_35 , ... )
{
T_2 V_36 ;
va_start ( V_36 , V_35 ) ;
vfprintf ( V_37 , V_35 , V_36 ) ;
va_end ( V_36 ) ;
exit ( 1 ) ;
}
static void F_16 ( void )
{
F_2 ( L_38
L_39
L_38
L_40
L_41
L_42
L_43
L_44
L_45
L_46
L_47
L_48
L_38 , V_38 ) ;
}
int main ( int V_39 , char * V_40 [] )
{
int V_41 ;
V_38 = V_40 [ 0 ] ;
V_42 = 0 ;
while ( 1 ) {
V_41 = F_17 ( V_39 , V_40 , L_49 ) ;
if ( V_41 == - 1 )
break;
switch ( V_41 ) {
case 'h' :
F_16 () ;
break;
case 'n' :
V_23 = V_43 ;
break;
case 'o' :
V_21 = V_43 ;
break;
case 't' :
if ( ! strcmp ( V_43 , L_50 ) )
V_25 = V_44 ;
else if ( ! strcmp ( V_43 , L_51 ) )
V_25 = V_45 ;
else if ( ! strcmp ( V_43 , L_52 ) )
V_25 = V_26 ;
else if ( ! strcmp ( V_43 , L_53 ) )
V_25 = V_46 ;
else
F_16 () ;
break;
default:
F_16 () ;
break;
}
}
if ( V_47 != V_39 - 1 )
F_16 () ;
V_5 = V_40 [ V_47 ] ;
F_4 () ;
switch ( V_25 ) {
case V_44 :
F_12 () ;
break;
case V_45 :
F_13 () ;
break;
case V_26 :
F_14 () ;
break;
case V_46 :
F_15 () ;
break;
}
exit ( 0 ) ;
}
