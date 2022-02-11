static void T_1 F_1 ( void )
{
F_2 () ;
F_3 ( V_1 , F_4 ( V_1 ) ) ;
}
static void F_5 ( struct V_2 * V_3 ,
int V_4 , unsigned int V_5 )
{
struct V_6 * V_7 = V_3 -> V_8 ;
if ( V_5 & V_9 ) {
void T_2 * V_10 = V_7 -> V_11 ;
unsigned char V_12 ;
V_10 += ( 1 << V_13 ) ;
V_12 = F_6 ( V_10 ) & ~ 0x07 ;
V_12 |= ( V_5 & V_14 ) << 2 ;
V_12 |= ( V_5 & V_15 ) ;
V_12 |= ( V_5 & V_16 ) >> 2 ;
F_7 ( V_12 , V_10 ) ;
}
if ( V_4 != V_17 )
F_7 ( V_4 , V_7 -> V_18 ) ;
}
static int F_8 ( struct V_2 * V_3 )
{
struct V_6 * V_7 = V_3 -> V_8 ;
void T_2 * V_10 = V_7 -> V_11 ;
V_10 += ( 1 << V_19 ) ;
return ! ! ( F_6 ( V_10 ) & 0x20 ) ;
}
static void T_1 F_9 ( void )
{
if ( F_10 () ) {
F_11 ( 2 , V_20 , V_21 ) ;
} else {
T_3 V_22 ;
if ( F_12 () )
V_22 = V_23 ;
else
V_22 = V_20 ;
V_24 [ 0 ] . V_22 = V_22 ;
V_24 [ 0 ] . V_25 = V_22 + V_21 - 1 ;
F_13 ( & V_26 ) ;
}
}
static unsigned char F_14 ( unsigned long V_10 )
{
F_7 ( V_10 , V_27 ) ;
return F_6 ( V_28 ) ;
}
static void F_15 ( unsigned char V_29 , unsigned long V_10 )
{
F_7 ( V_10 , V_27 ) ;
F_7 ( V_29 , V_28 ) ;
}
static void T_1 F_16 ( void )
{
F_17 () ;
F_9 () ;
F_13 ( & V_30 ) ;
F_13 ( & V_31 ) ;
F_18 ( & V_32 , 1 ) ;
}
