static void T_1 T_2 * F_1 ( int V_1 )
{
return ( void T_2 * ) ( ( V_1 < 8 ) ? F_2 ( V_1 ) : F_3 ( V_1 ) ) ;
}
static int T_1 F_4 ( int V_1 )
{
if ( V_1 < 8 )
return 1 ;
return 0 ;
}
static void T_1 F_5 ( int V_1 , T_3 V_2 , T_3 V_3 ,
T_4 V_4 , T_4 V_5 , int V_6 )
{
void T_2 * V_7 = F_1 ( V_1 ) ;
T_3 V_8 ;
V_2 &= 0xffff0000 ;
V_8 = ( ( V_3 - 1 ) & 0xffff0000 ) | ( V_5 << 8 ) | ( V_4 << 4 ) | 1 ;
F_6 ( V_2 , V_7 + V_9 ) ;
F_6 ( V_8 , V_7 + V_10 ) ;
if ( F_4 ( V_1 ) ) {
if ( V_6 < 0 )
V_6 = V_2 ;
F_6 ( V_6 & 0xffff0000 , V_7 + V_11 ) ;
F_6 ( 0 , V_7 + V_12 ) ;
}
}
void T_1 F_7 ( void )
{
void T_2 * V_7 ;
int V_13 ;
int V_14 ;
for ( V_13 = 0 ; V_13 < 14 ; V_13 ++ ) {
V_7 = F_1 ( V_13 ) ;
F_6 ( 0 , V_7 + V_9 ) ;
F_6 ( 0 , V_7 + V_10 ) ;
if ( F_4 ( V_13 ) ) {
F_6 ( 0 , V_7 + V_11 ) ;
F_6 ( 0 , V_7 + V_12 ) ;
}
}
V_15 . V_16 = V_17 ;
if ( F_8 () == 0 )
V_7 = ( void T_2 * ) V_18 ;
else
V_7 = ( void T_2 * ) V_19 ;
for ( V_13 = 0 , V_14 = 0 ; V_13 < 4 ; V_13 ++ ) {
T_3 V_2 = F_9 ( V_7 + F_10 ( V_13 ) ) ;
T_3 V_3 = F_9 ( V_7 + F_11 ( V_13 ) ) ;
if ( V_3 & 1 ) {
struct V_20 * V_21 ;
V_21 = & V_15 . V_14 [ V_14 ++ ] ;
V_21 -> V_22 = V_13 ;
V_21 -> V_23 = 0xf & ~ ( 1 << V_13 ) ;
V_21 -> V_2 = V_2 & 0xffff0000 ;
V_21 -> V_3 = ( V_3 | 0x0000ffff ) + 1 ;
}
}
V_15 . V_24 = V_14 ;
}
void T_1 F_12 ( int V_25 , T_3 V_2 , T_3 V_3 ,
int V_26 , int V_27 )
{
F_5 ( V_25 , V_2 , V_3 , F_13 ( V_26 ) ,
F_14 ( V_27 ) , - 1 ) ;
}
void T_1 F_15 ( int V_25 , T_3 V_2 , T_3 V_3 ,
int V_26 , int V_27 )
{
F_5 ( V_25 , V_2 , V_3 , F_13 ( V_26 ) ,
F_16 ( V_27 ) , - 1 ) ;
}
