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
V_12 = ( ( V_3 [ V_10 ] . V_16 >> 8 ) & 0x3f ) ;
F_2 ( ( V_12 * 250 ) , V_17 ) ;
V_2 = F_3 ( V_18 ) ;
V_2 &= ~ ( ( 0x3ff << 16 ) | ( 0x3f << 8 ) | ( 0x7 << 0 ) ) ;
V_2 |= V_3 [ V_10 ] . V_16 ;
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
static bool F_7 ( unsigned int V_11 , unsigned int V_10 )
{
unsigned int V_20 = V_3 [ V_11 ] . V_16 >> 8 ;
unsigned int V_21 = V_3 [ V_10 ] . V_16 >> 8 ;
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
V_2 |= V_3 [ V_10 ] . V_16 & 0x7 ;
F_2 ( V_2 , V_18 ) ;
} else {
F_1 ( V_10 ) ;
F_5 ( V_10 , V_11 ) ;
}
} else if ( V_11 < V_10 ) {
if ( ! F_7 ( V_11 , V_10 ) ) {
V_2 = F_3 ( V_18 ) ;
V_2 &= ~ ( 0x7 << 0 ) ;
V_2 |= V_3 [ V_10 ] . V_16 & 0x7 ;
F_2 ( V_2 , V_18 ) ;
F_1 ( V_10 ) ;
} else {
F_5 ( V_10 , V_11 ) ;
F_1 ( V_10 ) ;
}
}
}
int F_9 ( struct V_22 * V_23 )
{
unsigned long V_24 ;
V_25 = F_10 ( NULL , L_1 ) ;
if ( F_11 ( V_25 ) )
return F_12 ( V_25 ) ;
V_13 = F_10 ( NULL , L_2 ) ;
if ( F_11 ( V_13 ) )
goto V_26;
V_14 = F_10 ( NULL , L_3 ) ;
if ( F_11 ( V_14 ) )
goto V_27;
V_24 = F_13 ( V_14 ) / 1000 ;
V_19 = F_10 ( NULL , L_4 ) ;
if ( F_11 ( V_19 ) )
goto V_28;
V_23 -> V_29 = V_24 ;
V_23 -> V_30 = V_31 ;
V_23 -> V_25 = V_25 ;
V_23 -> V_32 = V_33 ;
V_23 -> V_34 = V_35 ;
V_23 -> V_36 = F_8 ;
V_23 -> V_37 = F_7 ;
return 0 ;
V_28:
F_14 ( V_14 ) ;
V_27:
F_14 ( V_13 ) ;
V_26:
F_14 ( V_25 ) ;
F_15 ( L_5 , V_38 ) ;
return - V_39 ;
}
