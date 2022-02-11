static inline unsigned long F_1 ( unsigned int V_1 )
{
return ( ( V_1 & V_2 ) <<
( ( V_3 -> V_4 & V_5 ) >= 5 ? 24 : 22 ) ) ;
}
static inline unsigned long F_2 ( unsigned int V_1 )
{
return ( ( V_1 & V_6 ) + 0x0100 ) <<
( ( V_3 -> V_4 & V_5 ) >= 5 ? 16 : 14 ) ;
}
static inline unsigned int F_3 ( int V_7 )
{
unsigned int V_8 = V_7 > 1 ? V_3 -> V_9 : V_3 -> V_10 ;
return V_7 % 2 ? V_8 & 0xffff : V_8 >> 16 ;
}
static void T_1 F_4 ( void )
{
int V_11 , V_12 , V_13 , V_14 = 0 ;
struct V_15 V_7 [ 4 ] ;
struct V_15 V_16 [ 2 ] = { { V_17 , 0 } , { V_18 , 0 } } ;
F_5 ( V_19 L_1 ) ;
for ( V_11 = 0 ; V_11 < F_6 ( V_7 ) ; V_11 ++ ) {
unsigned int V_20 = F_3 ( V_11 ) ;
if ( ! ( V_20 & V_21 ) )
continue;
V_7 [ V_14 ] . V_22 = F_2 ( V_20 ) ;
V_7 [ V_14 ] . V_23 = F_1 ( V_20 ) ;
F_5 ( V_19 L_2 ,
V_11 , V_7 [ V_14 ] . V_22 / 1024 / 1024 , V_7 [ V_14 ] . V_23 ) ;
V_14 ++ ;
}
do {
unsigned long V_23 , V_22 ;
V_13 = 0 ;
for ( V_11 = 1 ; V_11 < V_14 ; V_11 ++ )
if ( V_7 [ V_11 - 1 ] . V_23 > V_7 [ V_11 ] . V_23 ) {
V_23 = V_7 [ V_11 ] . V_23 ;
V_22 = V_7 [ V_11 ] . V_22 ;
V_7 [ V_11 ] . V_23 = V_7 [ V_11 - 1 ] . V_23 ;
V_7 [ V_11 ] . V_22 = V_7 [ V_11 - 1 ] . V_22 ;
V_7 [ V_11 - 1 ] . V_23 = V_23 ;
V_7 [ V_11 - 1 ] . V_22 = V_22 ;
V_13 = 1 ;
}
} while ( V_13 );
for ( V_11 = 0 ; V_11 < V_14 ; V_11 ++ ) {
V_13 = 0 ;
for ( V_12 = 0 ; V_12 < F_6 ( V_16 ) && ! V_13 ; V_12 ++ )
if ( V_16 [ V_12 ] . V_23 + V_16 [ V_12 ] . V_22 == V_7 [ V_11 ] . V_23 ) {
V_16 [ V_12 ] . V_22 += V_7 [ V_11 ] . V_22 ;
V_13 = 1 ;
}
if ( ! V_13 )
F_5 ( V_24 L_3
L_4 ,
V_7 [ V_11 ] . V_23 ) ;
}
for ( V_11 = 0 ; V_11 < F_6 ( V_16 ) ; V_11 ++ )
if ( V_16 [ V_11 ] . V_22 )
F_7 ( V_16 [ V_11 ] . V_23 , V_16 [ V_11 ] . V_22 ,
V_25 ) ;
}
void T_1 F_8 ( void )
{
T_2 V_20 ;
V_3 = (struct V_26 * )
F_9 ( V_27 , sizeof( struct V_26 ) ) ;
F_5 ( V_19 L_5 ,
( int ) V_3 -> V_4 & V_5 ) ;
V_20 = V_3 -> V_28 ;
V_20 &= ~ V_29 ;
V_3 -> V_28 = V_20 ;
V_3 -> V_30 = V_3 -> V_31 = 0 ;
#ifndef F_10
V_20 = V_3 -> V_28 ;
V_20 |= ( V_32 | V_33 |
V_34 ) ;
#endif
V_3 -> V_28 = V_20 ;
V_20 = V_3 -> V_35 ;
V_20 &= ~ 0xf ;
V_20 |= 0xd ;
V_3 -> V_35 = V_20 ;
V_3 -> V_36 = 0x101 ;
V_20 = V_37 ;
V_20 |= V_38 ;
if ( F_11 () ) {
if ( F_12 ( V_39 -> V_40 ) < 2 ) {
V_20 |= V_41 ;
V_20 |= V_42 ;
V_20 |= V_43 ;
V_20 |= V_44 ;
} else {
V_20 |= V_41 ;
V_20 |= V_42 ;
V_20 |= V_45 ;
V_20 |= V_46 ;
V_20 |= V_47 ;
}
} else {
V_20 |= V_48 ;
V_20 |= V_46 ;
}
V_3 -> V_49 = V_20 ;
F_4 () ;
}
void T_1 F_13 ( void ) {}
void T_1 F_14 ( void )
{
#ifdef F_10
T_2 V_9 ;
unsigned long V_50 ;
T_3 V_51 ;
F_15 ( & V_51 , V_50 ) ;
V_9 = V_3 -> V_9 ;
V_3 -> V_9 = ( V_9 & 0xffff0000 ) | 0x2060 ;
F_16 () ;
* ( unsigned long * ) F_17 ( 0x60000000 ) = 0 ;
F_16 () ;
V_3 -> V_52 = ( V_3 -> V_52 & ~ 0xf ) | 4 ;
F_16 () ;
V_3 -> V_9 = V_9 ;
F_16 () ;
F_18 ( & V_51 , V_50 ) ;
#endif
}
