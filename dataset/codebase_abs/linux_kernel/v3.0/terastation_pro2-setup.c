void T_1 F_1 ( void )
{
int V_1 ;
V_1 = V_2 ;
if ( F_2 ( V_1 , L_1 ) == 0 ) {
if ( F_3 ( V_1 ) == 0 ) {
F_4 ( F_5 ( V_1 ) , V_3 ) ;
} else {
F_6 ( V_4 L_2
L_3 , V_1 ) ;
F_7 ( V_1 ) ;
}
} else {
F_6 ( V_4 L_4
L_5 , V_1 ) ;
}
}
static int T_1 F_8 ( struct V_5 * V_6 , T_2 V_7 , T_2 V_1 )
{
int V_8 ;
V_8 = F_9 ( V_6 , V_7 , V_1 ) ;
if ( V_8 != - 1 )
return V_8 ;
if ( V_7 == V_9 )
return F_5 ( V_2 ) ;
return - 1 ;
}
static int T_1 F_10 ( void )
{
if ( F_11 () )
F_12 ( & V_10 ) ;
return 0 ;
}
static int F_13 ( unsigned char * V_11 , int V_12 )
{
int V_13 ;
int V_14 ;
for ( V_13 = 0 ; V_13 < V_12 ; V_13 ++ ) {
V_14 = 10 ;
while ( ! ( F_14 ( F_15 ( V_15 ) ) & V_16 ) ) {
if ( -- V_14 == 0 )
break;
F_16 ( 1000 ) ;
}
if ( V_14 == 0 )
break;
V_11 [ V_13 ] = F_14 ( F_15 ( V_17 ) ) ;
}
return V_13 ;
}
static int F_17 ( const unsigned char * V_11 , int V_12 )
{
int V_13 = 0 ;
while ( V_12 -- ) {
while ( ! ( F_14 ( F_15 ( V_15 ) ) & V_18 ) )
F_18 () ;
F_19 ( V_11 [ V_13 ++ ] , F_15 ( V_19 ) ) ;
}
return 0 ;
}
static int F_20 ( const unsigned char * V_20 , int V_12 )
{
int V_13 ;
unsigned char V_21 = 0 ;
unsigned char V_22 [ 40 ] ;
unsigned char V_23 [ 40 ] ;
unsigned char V_24 [ 3 ] ;
int V_25 = 2 ;
for ( V_13 = 0 ; V_13 < V_12 ; V_13 ++ )
V_21 -= V_20 [ V_13 ] ;
do {
F_17 ( V_20 , V_12 ) ;
F_17 ( & V_21 , 1 ) ;
if ( F_13 ( V_22 , sizeof( V_22 ) ) <= 3 ) {
F_6 ( V_4 L_6 , V_26 ) ;
memset ( & V_23 , 0xff , sizeof( V_23 ) ) ;
F_17 ( V_23 , sizeof( V_23 ) ) ;
F_21 ( 100 ) ;
F_13 ( V_22 , sizeof( V_22 ) ) ;
} else {
V_24 [ 0 ] = 0x01 ;
V_24 [ 1 ] = V_20 [ 1 ] ;
V_24 [ 2 ] = 0x00 ;
if ( ( V_22 [ 0 ] + V_22 [ 1 ] + V_22 [ 2 ] +
V_22 [ 3 ] ) & 0xFF ) {
F_6 ( V_4 L_7
L_8
L_9 , V_26 , V_22 [ 0 ] ,
V_22 [ 1 ] , V_22 [ 2 ] , V_22 [ 3 ] ) ;
} else {
if ( V_24 [ 0 ] == V_22 [ 0 ] &&
V_24 [ 1 ] == V_22 [ 1 ] &&
V_24 [ 2 ] == V_22 [ 2 ] ) {
F_21 ( 10 ) ;
return 0 ;
}
}
F_6 ( V_4 L_10
L_11 , V_26 ) ;
}
} while ( V_25 -- );
F_21 ( 10 ) ;
return - 1 ;
}
static void F_22 ( void )
{
const unsigned char V_27 [] = { 0x01 , 0x35 , 0x00 } ;
const unsigned char V_28 [] = { 0x00 , 0x0c } ;
const unsigned char V_29 [] = { 0x00 , 0x06 } ;
const unsigned V_30 = ( ( V_31 + ( 8 * 38400 ) ) / ( 16 * 38400 ) ) ;
F_23 ( L_12 , V_26 ) ;
F_19 ( 0x83 , F_15 ( V_32 ) ) ;
F_19 ( V_30 & 0xff , F_15 ( V_33 ) ) ;
F_19 ( ( V_30 >> 8 ) & 0xff , F_15 ( V_34 ) ) ;
F_19 ( 0x1b , F_15 ( V_32 ) ) ;
F_19 ( 0x00 , F_15 ( V_35 ) ) ;
F_19 ( 0x07 , F_15 ( V_36 ) ) ;
F_19 ( 0x00 , F_15 ( V_37 ) ) ;
F_20 ( V_27 , sizeof( V_27 ) ) ;
F_20 ( V_28 , sizeof( V_28 ) ) ;
F_20 ( V_29 , sizeof( V_29 ) ) ;
}
static void T_1 F_24 ( void )
{
F_25 () ;
F_26 ( V_38 ) ;
F_27 ( V_39 ,
V_40 ) ;
F_28 ( & V_41 ) ;
F_29 () ;
F_30 ( & V_42 ) ;
F_31 () ;
F_32 () ;
F_33 () ;
if ( F_2 ( V_43 , L_13 ) == 0 ) {
if ( F_3 ( V_43 ) == 0 )
V_44 . V_8 = F_5 ( V_43 ) ;
else
F_7 ( V_43 ) ;
}
if ( V_44 . V_8 == 0 )
F_34 ( L_14 ) ;
F_35 ( 0 , & V_44 , 1 ) ;
V_45 = F_22 ;
}
