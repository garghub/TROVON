static void F_1 ( unsigned int V_1 )
{
unsigned int V_2 ;
V_2 = V_3 [ V_1 ] . V_4 ;
F_2 ( V_2 , V_5 ) ;
do {
V_2 = F_3 ( V_6 ) ;
} while ( V_2 & 0x1111111 );
V_2 = F_3 ( V_7 ) ;
V_2 &= ~ ( ( 0x7 << 4 ) | 0x7 ) ;
V_2 |= ( ( V_8 [ V_1 ] [ 0 ] << 4 ) |
( V_8 [ V_1 ] [ 1 ] << 0 ) ) ;
F_2 ( V_2 , V_7 ) ;
do {
V_2 = F_3 ( V_9 ) ;
} while ( V_2 & 0x11 );
}
static void F_4 ( unsigned int V_10 )
{
unsigned int V_2 ;
F_5 ( V_11 , V_12 ) ;
do {
V_2 = ( F_3 ( V_13 )
>> V_14 ) ;
V_2 &= 0x7 ;
} while ( V_2 != 0x2 );
F_2 ( V_15 , V_16 ) ;
V_2 = F_3 ( V_17 ) ;
V_2 &= ~ ( ( 0x3ff << 16 ) | ( 0x3f << 8 ) | ( 0x7 << 0 ) ) ;
V_2 |= V_18 [ V_10 ] ;
F_2 ( V_2 , V_17 ) ;
do {
V_2 = F_3 ( V_17 ) ;
} while ( ! ( V_2 & ( 0x1 << V_19 ) ) );
F_5 ( V_11 , V_20 ) ;
do {
V_2 = F_3 ( V_13 ) ;
V_2 &= V_21 ;
} while ( V_2 != ( 0x1 << V_14 ) );
}
bool F_6 ( unsigned int V_22 , unsigned int V_23 )
{
unsigned int V_24 = ( V_18 [ V_22 ] >> 8 ) ;
unsigned int V_25 = ( V_18 [ V_23 ] >> 8 ) ;
return ( V_24 == V_25 ) ? 0 : 1 ;
}
static void F_7 ( unsigned int V_22 ,
unsigned int V_23 )
{
unsigned int V_2 ;
if ( V_22 > V_23 ) {
if ( ! F_6 ( V_22 , V_23 ) ) {
F_1 ( V_23 ) ;
V_2 = F_3 ( V_17 ) ;
V_2 &= ~ ( 0x7 << 0 ) ;
V_2 |= ( V_18 [ V_23 ] & 0x7 ) ;
F_2 ( V_2 , V_17 ) ;
} else {
F_1 ( V_23 ) ;
F_4 ( V_23 ) ;
}
} else if ( V_22 < V_23 ) {
if ( ! F_6 ( V_22 , V_23 ) ) {
V_2 = F_3 ( V_17 ) ;
V_2 &= ~ ( 0x7 << 0 ) ;
V_2 |= ( V_18 [ V_23 ] & 0x7 ) ;
F_2 ( V_2 , V_17 ) ;
F_1 ( V_23 ) ;
} else {
F_4 ( V_23 ) ;
F_1 ( V_23 ) ;
}
}
}
int F_8 ( struct V_26 * V_27 )
{
int V_28 ;
unsigned int V_2 ;
unsigned long V_29 ;
V_30 = F_9 ( NULL , L_1 ) ;
if ( F_10 ( V_30 ) )
return F_11 ( V_30 ) ;
V_11 = F_9 ( NULL , L_2 ) ;
if ( F_10 ( V_11 ) )
goto V_31;
V_12 = F_9 ( NULL , L_3 ) ;
if ( F_10 ( V_12 ) )
goto V_32;
V_29 = F_12 ( V_12 ) / 1000 ;
V_20 = F_9 ( NULL , L_4 ) ;
if ( F_10 ( V_20 ) )
goto V_33;
V_2 = F_3 ( V_5 ) ;
for ( V_28 = V_34 ; V_28 < V_35 ; V_28 ++ ) {
V_2 &= ~ ( V_36 |
V_37 |
V_38 |
V_39 |
V_40 |
V_41 |
V_42 ) ;
V_2 |= ( ( V_43 [ V_28 ] [ 0 ] << V_44 ) |
( V_43 [ V_28 ] [ 1 ] << V_45 ) |
( V_43 [ V_28 ] [ 2 ] << V_46 ) |
( V_43 [ V_28 ] [ 3 ] << V_47 ) |
( V_43 [ V_28 ] [ 4 ] << V_48 ) |
( V_43 [ V_28 ] [ 5 ] << V_49 ) |
( V_43 [ V_28 ] [ 6 ] << V_50 ) ) ;
V_3 [ V_28 ] . V_4 = V_2 ;
}
V_27 -> V_51 = V_29 ;
V_27 -> V_52 = V_53 ;
V_27 -> V_54 = V_53 ;
V_27 -> V_55 = V_55 ;
V_27 -> V_56 = V_56 ;
V_27 -> V_30 = V_30 ;
V_27 -> V_57 = V_58 ;
V_27 -> V_59 = V_60 ;
V_27 -> V_61 = F_7 ;
V_27 -> V_62 = F_6 ;
return 0 ;
V_33:
if ( ! F_10 ( V_12 ) )
F_13 ( V_12 ) ;
V_32:
if ( ! F_10 ( V_11 ) )
F_13 ( V_11 ) ;
V_31:
if ( ! F_10 ( V_30 ) )
F_13 ( V_30 ) ;
F_14 ( L_5 , V_63 ) ;
return - V_64 ;
}
