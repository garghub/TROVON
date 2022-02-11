static void T_1 F_1 ( void )
{
F_2 () ;
F_3 ( V_1 , F_4 ( V_1 ) ) ;
}
static void F_5 ( struct V_2 * V_3 ,
int V_4 , unsigned int V_5 )
{
struct V_6 * V_7 = F_6 ( V_3 ) ;
if ( V_5 & V_8 ) {
void T_2 * V_9 = V_7 -> V_10 ;
unsigned char V_11 ;
V_9 += ( 1 << V_12 ) ;
V_11 = F_7 ( V_9 ) & ~ 0x07 ;
V_11 |= ( V_5 & V_13 ) << 2 ;
V_11 |= ( V_5 & V_14 ) ;
V_11 |= ( V_5 & V_15 ) >> 2 ;
F_8 ( V_11 , V_9 ) ;
}
if ( V_4 != V_16 )
F_8 ( V_4 , V_7 -> V_17 ) ;
}
static int F_9 ( struct V_2 * V_3 )
{
struct V_6 * V_7 = F_6 ( V_3 ) ;
void T_2 * V_9 = V_7 -> V_10 ;
V_9 += ( 1 << V_18 ) ;
return ! ! ( F_7 ( V_9 ) & 0x20 ) ;
}
static void T_1 F_10 ( void )
{
if ( F_11 () ) {
F_12 ( 2 , V_19 , V_20 ) ;
} else {
T_3 V_21 ;
if ( F_13 () )
V_21 = V_22 ;
else
V_21 = V_19 ;
V_23 [ 0 ] . V_21 = V_21 ;
V_23 [ 0 ] . V_24 = V_21 + V_20 - 1 ;
F_14 ( & V_25 ) ;
}
}
static unsigned char F_15 ( unsigned long V_9 )
{
F_8 ( V_9 , V_26 ) ;
return F_7 ( V_27 ) ;
}
static void F_16 ( unsigned char V_28 , unsigned long V_9 )
{
F_8 ( V_9 , V_26 ) ;
F_8 ( V_28 , V_27 ) ;
}
static void T_1 F_17 ( void )
{
F_18 () ;
F_10 () ;
F_14 ( & V_29 ) ;
F_14 ( & V_30 ) ;
F_19 ( & V_31 , 1 ) ;
}
