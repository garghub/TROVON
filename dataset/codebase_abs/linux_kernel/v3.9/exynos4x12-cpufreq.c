static void F_1 ( unsigned int V_1 )
{
unsigned int V_2 ;
unsigned int V_3 ;
V_2 = V_4 [ V_1 ] . V_5 ;
F_2 ( V_2 , V_6 ) ;
while ( F_3 ( V_7 ) & 0x11111111 )
F_4 () ;
V_2 = V_4 [ V_1 ] . V_8 ;
F_2 ( V_2 , V_9 ) ;
if ( F_5 () )
V_3 = 0x11 ;
else
V_3 = 0x111 ;
while ( F_3 ( V_10 ) & V_3 )
F_4 () ;
}
static void F_6 ( unsigned int V_11 )
{
unsigned int V_2 , V_12 ;
F_7 ( V_13 , V_14 ) ;
do {
F_4 () ;
V_2 = ( F_3 ( V_15 )
>> V_16 ) ;
V_2 &= 0x7 ;
} while ( V_2 != 0x2 );
V_12 = ( ( V_4 [ V_11 ] . V_17 >> 8 ) & 0x3f ) ;
F_2 ( ( V_12 * 250 ) , V_18 ) ;
V_2 = F_3 ( V_19 ) ;
V_2 &= ~ ( ( 0x3ff << 16 ) | ( 0x3f << 8 ) | ( 0x7 << 0 ) ) ;
V_2 |= V_4 [ V_11 ] . V_17 ;
F_2 ( V_2 , V_19 ) ;
do {
F_4 () ;
V_2 = F_3 ( V_19 ) ;
} while ( ! ( V_2 & ( 0x1 << V_20 ) ) );
F_7 ( V_13 , V_21 ) ;
do {
F_4 () ;
V_2 = F_3 ( V_15 ) ;
V_2 &= V_22 ;
} while ( V_2 != ( 0x1 << V_16 ) );
}
static bool F_8 ( unsigned int V_23 , unsigned int V_24 )
{
unsigned int V_25 = V_4 [ V_23 ] . V_17 >> 8 ;
unsigned int V_26 = V_4 [ V_24 ] . V_17 >> 8 ;
return ( V_25 == V_26 ) ? 0 : 1 ;
}
static void F_9 ( unsigned int V_23 ,
unsigned int V_24 )
{
unsigned int V_2 ;
if ( V_23 > V_24 ) {
if ( ! F_8 ( V_23 , V_24 ) ) {
F_1 ( V_24 ) ;
V_2 = F_3 ( V_19 ) ;
V_2 &= ~ ( 0x7 << 0 ) ;
V_2 |= V_4 [ V_24 ] . V_17 & 0x7 ;
F_2 ( V_2 , V_19 ) ;
} else {
F_1 ( V_24 ) ;
F_6 ( V_24 ) ;
}
} else if ( V_23 < V_24 ) {
if ( ! F_8 ( V_23 , V_24 ) ) {
V_2 = F_3 ( V_19 ) ;
V_2 &= ~ ( 0x7 << 0 ) ;
V_2 |= V_4 [ V_24 ] . V_17 & 0x7 ;
F_2 ( V_2 , V_19 ) ;
F_1 ( V_24 ) ;
} else {
F_6 ( V_24 ) ;
F_1 ( V_24 ) ;
}
}
}
int F_10 ( struct V_27 * V_28 )
{
unsigned long V_29 ;
V_30 = F_11 ( NULL , L_1 ) ;
if ( F_12 ( V_30 ) )
return F_13 ( V_30 ) ;
V_13 = F_11 ( NULL , L_2 ) ;
if ( F_12 ( V_13 ) )
goto V_31;
V_14 = F_11 ( NULL , L_3 ) ;
if ( F_12 ( V_14 ) )
goto V_32;
V_29 = F_14 ( V_14 ) / 1000 ;
V_21 = F_11 ( NULL , L_4 ) ;
if ( F_12 ( V_21 ) )
goto V_33;
if ( F_5 () )
V_4 = V_34 ;
else
V_4 = V_35 ;
V_28 -> V_36 = V_29 ;
V_28 -> V_37 = V_38 ;
V_28 -> V_30 = V_30 ;
V_28 -> V_39 = V_40 ;
V_28 -> V_41 = V_42 ;
V_28 -> V_43 = F_9 ;
V_28 -> V_44 = F_8 ;
return 0 ;
V_33:
F_15 ( V_14 ) ;
V_32:
F_15 ( V_13 ) ;
V_31:
F_15 ( V_30 ) ;
F_16 ( L_5 , V_45 ) ;
return - V_46 ;
}
