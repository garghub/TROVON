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
V_2 = fgetc ( V_1 ) ;
if ( V_2 == V_4 )
F_2 ( L_1 , V_5 ) ;
}
return V_3 ;
}
static unsigned int F_3 ( T_1 * V_1 , unsigned int V_6 )
{
unsigned int V_3 = F_1 ( V_1 ) ;
return ( 255 * V_3 + V_6 / 2 ) / V_6 ;
}
static void F_4 ( void )
{
T_1 * V_1 ;
unsigned int V_7 , V_8 ;
int V_9 ;
unsigned int V_6 ;
V_1 = fopen ( V_5 , L_2 ) ;
if ( ! V_1 )
F_2 ( L_3 , V_5 , strerror ( V_10 ) ) ;
V_9 = fgetc ( V_1 ) ;
if ( V_9 != 'P' )
F_2 ( L_4 , V_5 ) ;
V_9 = fgetc ( V_1 ) ;
switch ( V_9 ) {
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
V_11 = F_1 ( V_1 ) ;
V_12 = F_1 ( V_1 ) ;
V_13 = (struct V_14 * * ) malloc ( V_12 * sizeof( struct V_14 * ) ) ;
if ( ! V_13 )
F_2 ( L_7 , strerror ( V_10 ) ) ;
for ( V_7 = 0 ; V_7 < V_12 ; V_7 ++ ) {
V_13 [ V_7 ] = malloc ( V_11 * sizeof( struct V_14 ) ) ;
if ( ! V_13 [ V_7 ] )
F_2 ( L_7 , strerror ( V_10 ) ) ;
}
switch ( V_9 ) {
case '1' :
for ( V_7 = 0 ; V_7 < V_12 ; V_7 ++ )
for ( V_8 = 0 ; V_8 < V_11 ; V_8 ++ )
V_13 [ V_7 ] [ V_8 ] . V_15 = V_13 [ V_7 ] [ V_8 ] . V_16 =
V_13 [ V_7 ] [ V_8 ] . V_17 = 255 * ( 1 - F_1 ( V_1 ) ) ;
break;
case '2' :
V_6 = F_1 ( V_1 ) ;
for ( V_7 = 0 ; V_7 < V_12 ; V_7 ++ )
for ( V_8 = 0 ; V_8 < V_11 ; V_8 ++ )
V_13 [ V_7 ] [ V_8 ] . V_15 = V_13 [ V_7 ] [ V_8 ] . V_16 =
V_13 [ V_7 ] [ V_8 ] . V_17 = F_3 ( V_1 , V_6 ) ;
break;
case '3' :
V_6 = F_1 ( V_1 ) ;
for ( V_7 = 0 ; V_7 < V_12 ; V_7 ++ )
for ( V_8 = 0 ; V_8 < V_11 ; V_8 ++ ) {
V_13 [ V_7 ] [ V_8 ] . V_15 = F_3 ( V_1 , V_6 ) ;
V_13 [ V_7 ] [ V_8 ] . V_16 = F_3 ( V_1 , V_6 ) ;
V_13 [ V_7 ] [ V_8 ] . V_17 = F_3 ( V_1 , V_6 ) ;
}
break;
}
fclose ( V_1 ) ;
}
static inline int F_5 ( struct V_14 V_2 )
{
return V_2 . V_15 == 0 && V_2 . V_16 == 0 && V_2 . V_17 == 0 ;
}
static inline int F_6 ( struct V_14 V_2 )
{
return V_2 . V_15 == 255 && V_2 . V_16 == 255 && V_2 . V_17 == 255 ;
}
static inline int F_7 ( struct V_14 V_2 )
{
return V_2 . V_15 == V_2 . V_16 && V_2 . V_15 == V_2 . V_17 ;
}
static inline int F_8 ( struct V_14 V_18 , struct V_14 V_19 )
{
return V_18 . V_15 == V_19 . V_15 && V_18 . V_16 == V_19 . V_16 && V_18 . V_17 == V_19 . V_17 ;
}
static void F_9 ( void )
{
if ( V_20 ) {
V_21 = fopen ( V_20 , L_8 ) ;
if ( ! V_21 )
F_2 ( L_9 , V_20 , strerror ( V_10 ) ) ;
} else {
V_21 = stdout ;
}
fputs ( L_10 , V_21 ) ;
fputs ( L_11 , V_21 ) ;
fputs ( L_12 , V_21 ) ;
fprintf ( V_21 , L_13 , V_5 ) ;
fputs ( L_12 , V_21 ) ;
fprintf ( V_21 , L_14 , V_22 ) ;
fputs ( L_15 , V_21 ) ;
fputs ( L_16 , V_21 ) ;
fprintf ( V_21 , L_17 ,
V_22 ) ;
}
static void F_10 ( void )
{
fputs ( L_18 , V_21 ) ;
fprintf ( V_21 , L_19 , V_22 ) ;
fprintf ( V_21 , L_20 , V_23 [ V_24 ] ) ;
fprintf ( V_21 , L_21 , V_11 ) ;
fprintf ( V_21 , L_22 , V_12 ) ;
if ( V_24 == V_25 ) {
fprintf ( V_21 , L_23 , V_26 ) ;
fprintf ( V_21 , L_24 , V_22 ) ;
}
fprintf ( V_21 , L_25 , V_22 ) ;
fputs ( L_26 , V_21 ) ;
if ( V_20 )
fclose ( V_21 ) ;
}
static void F_11 ( unsigned char V_27 )
{
if ( V_28 % 12 )
fprintf ( V_21 , L_27 , V_27 ) ;
else if ( V_28 )
fprintf ( V_21 , L_28 , V_27 ) ;
else
fprintf ( V_21 , L_29 , V_27 ) ;
V_28 ++ ;
}
static void F_12 ( void )
{
unsigned int V_7 , V_8 ;
unsigned char V_3 , V_29 ;
for ( V_7 = 0 ; V_7 < V_12 ; V_7 ++ )
for ( V_8 = 0 ; V_8 < V_11 ; V_8 ++ )
if ( ! F_5 ( V_13 [ V_7 ] [ V_8 ] ) && ! F_6 ( V_13 [ V_7 ] [ V_8 ] ) )
F_2 ( L_30 ) ;
F_9 () ;
for ( V_7 = 0 ; V_7 < V_12 ; V_7 ++ ) {
for ( V_8 = 0 ; V_8 < V_11 ; ) {
for ( V_3 = 0 , V_29 = 0x80 ; V_29 && V_8 < V_11 ; V_8 ++ , V_29 >>= 1 )
if ( V_13 [ V_7 ] [ V_8 ] . V_15 )
V_3 |= V_29 ;
F_11 ( V_3 ) ;
}
}
F_10 () ;
}
static void F_13 ( void )
{
unsigned int V_7 , V_8 , V_30 ;
unsigned char V_3 ;
for ( V_7 = 0 ; V_7 < V_12 ; V_7 ++ )
for ( V_8 = 0 ; V_8 < V_11 ; V_8 ++ ) {
for ( V_30 = 0 ; V_30 < 16 ; V_30 ++ )
if ( F_8 ( V_13 [ V_7 ] [ V_8 ] , V_31 [ V_30 ] ) )
break;
if ( V_30 == 16 )
F_2 ( L_31
L_32
L_33 ) ;
}
F_9 () ;
for ( V_7 = 0 ; V_7 < V_12 ; V_7 ++ )
for ( V_8 = 0 ; V_8 < V_11 ; V_8 ++ ) {
for ( V_30 = 0 ; V_30 < 16 ; V_30 ++ )
if ( F_8 ( V_13 [ V_7 ] [ V_8 ] , V_31 [ V_30 ] ) )
break;
V_3 = V_30 << 4 ;
if ( ++ V_8 < V_11 ) {
for ( V_30 = 0 ; V_30 < 16 ; V_30 ++ )
if ( F_8 ( V_13 [ V_7 ] [ V_8 ] , V_31 [ V_30 ] ) )
break;
V_3 |= V_30 ;
}
F_11 ( V_3 ) ;
}
F_10 () ;
}
static void F_14 ( void )
{
unsigned int V_7 , V_8 , V_30 ;
for ( V_7 = 0 ; V_7 < V_12 ; V_7 ++ )
for ( V_8 = 0 ; V_8 < V_11 ; V_8 ++ ) {
for ( V_30 = 0 ; V_30 < V_26 ; V_30 ++ )
if ( F_8 ( V_13 [ V_7 ] [ V_8 ] , V_32 [ V_30 ] ) )
break;
if ( V_30 == V_26 ) {
if ( V_26 == V_33 )
F_2 ( L_34
L_35 ,
V_33 ) ;
V_32 [ V_26 ++ ] = V_13 [ V_7 ] [ V_8 ] ;
}
}
F_9 () ;
for ( V_7 = 0 ; V_7 < V_12 ; V_7 ++ )
for ( V_8 = 0 ; V_8 < V_11 ; V_8 ++ ) {
for ( V_30 = 0 ; V_30 < V_26 ; V_30 ++ )
if ( F_8 ( V_13 [ V_7 ] [ V_8 ] , V_32 [ V_30 ] ) )
break;
F_11 ( V_30 + 32 ) ;
}
fputs ( L_18 , V_21 ) ;
fprintf ( V_21 , L_36 ,
V_22 ) ;
V_28 = 0 ;
for ( V_7 = 0 ; V_7 < V_26 ; V_7 ++ ) {
F_11 ( V_32 [ V_7 ] . V_15 ) ;
F_11 ( V_32 [ V_7 ] . V_16 ) ;
F_11 ( V_32 [ V_7 ] . V_17 ) ;
}
F_10 () ;
}
static void F_15 ( void )
{
unsigned int V_7 , V_8 ;
for ( V_7 = 0 ; V_7 < V_12 ; V_7 ++ )
for ( V_8 = 0 ; V_8 < V_11 ; V_8 ++ )
if ( ! F_7 ( V_13 [ V_7 ] [ V_8 ] ) )
F_2 ( L_37 ) ;
F_9 () ;
for ( V_7 = 0 ; V_7 < V_12 ; V_7 ++ )
for ( V_8 = 0 ; V_8 < V_11 ; V_8 ++ )
F_11 ( V_13 [ V_7 ] [ V_8 ] . V_15 ) ;
F_10 () ;
}
static void F_2 ( const char * V_34 , ... )
{
T_2 V_35 ;
va_start ( V_35 , V_34 ) ;
vfprintf ( V_36 , V_34 , V_35 ) ;
va_end ( V_35 ) ;
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
L_38 , V_37 ) ;
}
int main ( int V_38 , char * V_39 [] )
{
int V_40 ;
V_37 = V_39 [ 0 ] ;
V_41 = 0 ;
while ( 1 ) {
V_40 = F_17 ( V_38 , V_39 , L_49 ) ;
if ( V_40 == - 1 )
break;
switch ( V_40 ) {
case 'h' :
F_16 () ;
break;
case 'n' :
V_22 = V_42 ;
break;
case 'o' :
V_20 = V_42 ;
break;
case 't' :
if ( ! strcmp ( V_42 , L_50 ) )
V_24 = V_43 ;
else if ( ! strcmp ( V_42 , L_51 ) )
V_24 = V_44 ;
else if ( ! strcmp ( V_42 , L_52 ) )
V_24 = V_25 ;
else if ( ! strcmp ( V_42 , L_53 ) )
V_24 = V_45 ;
else
F_16 () ;
break;
default:
F_16 () ;
break;
}
}
if ( V_46 != V_38 - 1 )
F_16 () ;
V_5 = V_39 [ V_46 ] ;
F_4 () ;
switch ( V_24 ) {
case V_43 :
F_12 () ;
break;
case V_44 :
F_13 () ;
break;
case V_25 :
F_14 () ;
break;
case V_45 :
F_15 () ;
break;
}
exit ( 0 ) ;
}
