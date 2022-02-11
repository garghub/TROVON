static void F_1 ( void )
{
T_1 V_1 = F_2 ( V_2 ) ;
V_1 &= ~ ( V_3 | V_4 ) ;
V_1 |= ( V_5 | V_6 | V_7 | V_8 ) ;
F_3 ( V_2 , V_1 ) ;
}
static void F_4 ( void )
{
T_1 V_1 = F_2 ( V_2 ) ;
V_1 |= V_3 ;
V_1 &= ~ ( V_5 | V_6 | V_7 | V_8 ) ;
F_3 ( V_2 , V_1 ) ;
}
static int F_5 ( struct V_9 * V_10 )
{
F_4 () ;
F_3 ( V_2 , V_11 ) ;
F_3 ( V_12 , V_13 ) ;
if ( V_14 > 4 )
F_3 ( V_15 , V_16 ) ;
return 0 ;
}
static int F_6 ( struct V_9 * V_10 ,
struct V_17 * V_18 ,
int V_19 )
{
int V_20 ;
V_14 = V_19 ;
for ( V_20 = 0 ; V_20 < V_19 ; ++ V_20 )
V_21 [ V_20 ] = 0x80000000UL - V_10 [ V_20 ] . V_22 ;
V_11 = V_23 | F_7 ( V_10 [ 0 ] . V_24 )
| F_8 ( V_10 [ 1 ] . V_24 ) ;
if ( V_18 -> V_25 )
V_11 &= ~ ( V_26 ) ;
if ( V_18 -> V_27 )
V_11 &= ~ ( V_28 ) ;
V_13 = F_9 ( V_10 [ 2 ] . V_24 )
| F_10 ( V_10 [ 3 ] . V_24 ) ;
if ( V_19 > 4 )
V_13 |= F_11 ( V_10 [ 4 ] . V_24 )
| F_12 ( V_10 [ 5 ] . V_24 ) ;
V_16 = 0 ;
return 0 ;
}
static int F_13 ( struct V_9 * V_10 )
{
int V_20 ;
F_14 ( F_15 () | V_29 ) ;
for ( V_20 = 0 ; V_20 < V_14 ; ++ V_20 ) {
if ( V_10 [ V_20 ] . V_30 )
F_16 ( V_20 , V_21 [ V_20 ] ) ;
else
F_16 ( V_20 , 0 ) ;
}
F_1 () ;
V_31 = 1 ;
return 0 ;
}
static void F_17 ( void )
{
F_4 () ;
V_31 = 0 ;
F_18 () ;
}
static void F_19 ( struct V_32 * V_33 ,
struct V_9 * V_10 )
{
unsigned long V_34 ;
int V_35 ;
int V_36 ;
int V_20 ;
F_14 ( F_15 () | V_29 ) ;
V_34 = F_2 ( V_37 ) ;
V_35 = F_20 ( V_34 ) ;
for ( V_20 = 0 ; V_20 < V_14 ; ++ V_20 ) {
V_36 = F_21 ( V_20 ) ;
if ( V_36 < 0 ) {
if ( V_31 && V_10 [ V_20 ] . V_30 ) {
F_22 ( V_34 , V_33 , V_20 , V_35 ) ;
F_16 ( V_20 , V_21 [ V_20 ] ) ;
} else {
F_16 ( V_20 , 0 ) ;
}
}
}
F_1 () ;
}
