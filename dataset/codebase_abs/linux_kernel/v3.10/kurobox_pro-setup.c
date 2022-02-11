static int T_1 F_1 ( const struct V_1 * V_2 , T_2 V_3 ,
T_2 V_4 )
{
int V_5 ;
V_5 = F_2 ( V_2 , V_3 , V_4 ) ;
if ( V_5 != - 1 )
return V_5 ;
return - 1 ;
}
static int T_1 F_3 ( void )
{
if ( F_4 () ) {
F_5 () ;
F_6 ( & V_6 ) ;
}
return 0 ;
}
static int F_7 ( unsigned char * V_7 , int V_8 )
{
int V_9 ;
int V_10 ;
for ( V_9 = 0 ; V_9 < V_8 ; V_9 ++ ) {
V_10 = 10 ;
while ( ! ( F_8 ( F_9 ( V_11 ) ) & V_12 ) ) {
if ( -- V_10 == 0 )
break;
F_10 ( 1000 ) ;
}
if ( V_10 == 0 )
break;
V_7 [ V_9 ] = F_8 ( F_9 ( V_13 ) ) ;
}
return V_9 ;
}
static int F_11 ( const unsigned char * V_7 , int V_8 )
{
int V_9 = 0 ;
while ( V_8 -- ) {
while ( ! ( F_8 ( F_9 ( V_11 ) ) & V_14 ) )
F_12 () ;
F_13 ( V_7 [ V_9 ++ ] , F_9 ( V_15 ) ) ;
}
return 0 ;
}
static int F_14 ( const unsigned char * V_16 , int V_8 )
{
int V_9 ;
unsigned char V_17 = 0 ;
unsigned char V_18 [ 40 ] ;
unsigned char V_19 [ 40 ] ;
unsigned char V_20 [ 3 ] ;
int V_21 = 2 ;
for ( V_9 = 0 ; V_9 < V_8 ; V_9 ++ )
V_17 -= V_16 [ V_9 ] ;
do {
F_11 ( V_16 , V_8 ) ;
F_11 ( & V_17 , 1 ) ;
if ( F_7 ( V_18 , sizeof( V_18 ) ) <= 3 ) {
F_15 ( V_22 L_1 , V_23 ) ;
memset ( & V_19 , 0xff , sizeof( V_19 ) ) ;
F_11 ( V_19 , sizeof( V_19 ) ) ;
F_16 ( 100 ) ;
F_7 ( V_18 , sizeof( V_18 ) ) ;
} else {
V_20 [ 0 ] = 0x01 ;
V_20 [ 1 ] = V_16 [ 1 ] ;
V_20 [ 2 ] = 0x00 ;
if ( ( V_18 [ 0 ] + V_18 [ 1 ] + V_18 [ 2 ] +
V_18 [ 3 ] ) & 0xFF ) {
F_15 ( V_22 L_2
L_3
L_4 , V_23 , V_18 [ 0 ] ,
V_18 [ 1 ] , V_18 [ 2 ] , V_18 [ 3 ] ) ;
} else {
if ( V_20 [ 0 ] == V_18 [ 0 ] &&
V_20 [ 1 ] == V_18 [ 1 ] &&
V_20 [ 2 ] == V_18 [ 2 ] ) {
F_16 ( 10 ) ;
return 0 ;
}
}
F_15 ( V_22 L_5
L_6 , V_23 ) ;
}
} while ( V_21 -- );
F_16 ( 10 ) ;
return - 1 ;
}
static void F_17 ( void )
{
const unsigned char V_24 [] = { 0x01 , 0x35 , 0x00 } ;
const unsigned char V_25 [] = { 0x00 , 0x0c } ;
const unsigned char V_26 [] = { 0x00 , 0x06 } ;
const unsigned V_27 = ( ( V_28 + ( 8 * 38400 ) ) / ( 16 * 38400 ) ) ;
F_18 ( L_7 , V_23 ) ;
F_13 ( 0x83 , F_9 ( V_29 ) ) ;
F_13 ( V_27 & 0xff , F_9 ( V_30 ) ) ;
F_13 ( ( V_27 >> 8 ) & 0xff , F_9 ( V_31 ) ) ;
F_13 ( 0x1b , F_9 ( V_29 ) ) ;
F_13 ( 0x00 , F_9 ( V_32 ) ) ;
F_13 ( 0x07 , F_9 ( V_33 ) ) ;
F_13 ( 0x00 , F_9 ( V_34 ) ) ;
F_14 ( V_24 , sizeof( V_24 ) ) ;
F_14 ( V_25 , sizeof( V_25 ) ) ;
F_14 ( V_26 , sizeof( V_26 ) ) ;
}
static void T_1 F_19 ( void )
{
F_20 () ;
F_21 ( V_35 ) ;
F_22 () ;
F_23 () ;
F_24 ( & V_36 ) ;
F_25 () ;
F_26 ( & V_37 ) ;
F_27 () ;
F_28 () ;
F_29 () ;
F_30 ( L_8 , V_38 ,
V_39 ) ;
F_31 ( & V_40 ) ;
if ( F_4 () ) {
F_30 ( L_9 , V_41 ,
V_42 ) ;
F_31 ( & V_43 ) ;
}
F_32 ( 0 , & V_44 , 1 ) ;
V_45 = F_17 ;
}
