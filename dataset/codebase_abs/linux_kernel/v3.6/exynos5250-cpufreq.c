static void F_1 ( unsigned int V_1 )
{
unsigned int V_2 ;
V_2 = V_3 [ V_1 ] . V_4 ;
F_2 ( V_2 , V_5 ) ;
while ( F_3 ( V_6 ) & 0x11111111 )
F_4 () ;
V_2 = V_3 [ V_1 ] . V_7 ;
F_2 ( V_2 , V_8 ) ;
while ( F_3 ( V_9 ) & 0x11 )
F_4 () ;
}
static void F_5 ( unsigned int V_10 ,
unsigned int V_11 )
{
unsigned int V_2 , V_12 ;
F_6 ( V_13 , V_14 ) ;
do {
F_4 () ;
V_2 = ( F_3 ( V_15 ) >> 16 ) ;
V_2 &= 0x7 ;
} while ( V_2 != 0x2 );
V_12 = ( ( V_16 [ V_10 ] >> 8 ) & 0x3f ) ;
F_2 ( ( V_12 * 250 ) , V_17 ) ;
V_2 = F_3 ( V_18 ) ;
V_2 &= ~ ( ( 0x3ff << 16 ) | ( 0x3f << 8 ) | ( 0x7 << 0 ) ) ;
V_2 |= V_16 [ V_10 ] ;
F_2 ( V_2 , V_18 ) ;
do {
F_4 () ;
V_2 = F_3 ( V_18 ) ;
} while ( ! ( V_2 & ( 0x1 << 29 ) ) );
F_6 ( V_13 , V_19 ) ;
do {
F_4 () ;
V_2 = F_3 ( V_15 ) ;
V_2 &= ( 0x7 << 16 ) ;
} while ( V_2 != ( 0x1 << 16 ) );
}
bool F_7 ( unsigned int V_11 , unsigned int V_10 )
{
unsigned int V_20 = ( V_16 [ V_11 ] >> 8 ) ;
unsigned int V_21 = ( V_16 [ V_10 ] >> 8 ) ;
return ( V_20 == V_21 ) ? 0 : 1 ;
}
static void F_8 ( unsigned int V_11 ,
unsigned int V_10 )
{
unsigned int V_2 ;
if ( V_11 > V_10 ) {
if ( ! F_7 ( V_11 , V_10 ) ) {
F_1 ( V_10 ) ;
V_2 = F_3 ( V_18 ) ;
V_2 &= ~ ( 0x7 << 0 ) ;
V_2 |= ( V_16 [ V_10 ] & 0x7 ) ;
F_2 ( V_2 , V_18 ) ;
} else {
F_1 ( V_10 ) ;
F_5 ( V_10 , V_11 ) ;
}
} else if ( V_11 < V_10 ) {
if ( ! F_7 ( V_11 , V_10 ) ) {
V_2 = F_3 ( V_18 ) ;
V_2 &= ~ ( 0x7 << 0 ) ;
V_2 |= ( V_16 [ V_10 ] & 0x7 ) ;
F_2 ( V_2 , V_18 ) ;
F_1 ( V_10 ) ;
} else {
F_5 ( V_10 , V_11 ) ;
F_1 ( V_10 ) ;
}
}
}
static void T_1 F_9 ( void )
{
unsigned int V_22 ;
V_23 = V_24 ;
for ( V_22 = 0 ; V_22 < V_25 ; V_22 ++ )
V_26 [ V_22 ] = V_27 [ V_22 ] ;
}
int F_10 ( struct V_28 * V_29 )
{
int V_22 ;
unsigned int V_2 ;
unsigned long V_30 ;
F_9 () ;
V_31 = F_11 ( NULL , L_1 ) ;
if ( F_12 ( V_31 ) )
return F_13 ( V_31 ) ;
V_13 = F_11 ( NULL , L_2 ) ;
if ( F_12 ( V_13 ) )
goto V_32;
V_14 = F_11 ( NULL , L_3 ) ;
if ( F_12 ( V_14 ) )
goto V_33;
V_30 = F_14 ( V_14 ) / 1000 ;
V_19 = F_11 ( NULL , L_4 ) ;
if ( F_12 ( V_19 ) )
goto V_34;
for ( V_22 = V_24 ; V_22 < V_25 ; V_22 ++ ) {
V_3 [ V_22 ] . V_35 = V_22 ;
V_2 = F_3 ( V_5 ) ;
V_2 &= ~ ( ( 0x7 << 0 ) | ( 0x7 << 4 ) | ( 0x7 << 8 ) |
( 0x7 << 12 ) | ( 0x7 << 16 ) | ( 0x7 << 20 ) |
( 0x7 << 24 ) | ( 0x7 << 28 ) ) ;
V_2 |= ( ( V_36 [ V_22 ] [ 0 ] << 0 ) |
( V_36 [ V_22 ] [ 1 ] << 4 ) |
( V_36 [ V_22 ] [ 2 ] << 8 ) |
( V_36 [ V_22 ] [ 3 ] << 12 ) |
( V_36 [ V_22 ] [ 4 ] << 16 ) |
( V_36 [ V_22 ] [ 5 ] << 20 ) |
( V_36 [ V_22 ] [ 6 ] << 24 ) |
( V_36 [ V_22 ] [ 7 ] << 28 ) ) ;
V_3 [ V_22 ] . V_4 = V_2 ;
V_2 = F_3 ( V_8 ) ;
V_2 &= ~ ( ( 0x7 << 0 ) | ( 0x7 << 4 ) ) ;
V_2 |= ( ( V_37 [ V_22 ] [ 0 ] << 0 ) |
( V_37 [ V_22 ] [ 1 ] << 4 ) ) ;
V_3 [ V_22 ] . V_7 = V_2 ;
}
V_29 -> V_38 = V_30 ;
V_29 -> V_39 = V_40 ;
V_29 -> V_41 = V_42 ;
V_29 -> V_23 = V_23 ;
V_29 -> V_43 = V_43 ;
V_29 -> V_31 = V_31 ;
V_29 -> V_44 = V_26 ;
V_29 -> V_45 = V_46 ;
V_29 -> V_47 = F_8 ;
V_29 -> V_48 = F_7 ;
return 0 ;
V_34:
F_15 ( V_14 ) ;
V_33:
F_15 ( V_13 ) ;
V_32:
F_15 ( V_31 ) ;
F_16 ( L_5 , V_49 ) ;
return - V_50 ;
}
