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
static void F_9 ( T_3 V_20 ,
struct V_21 * V_7 )
{
if ( V_20 == V_22 || V_20 == V_23 ) {
V_24 [ 1 ] . V_20 = V_20 - V_25 ;
V_7 -> V_26 = V_24 ;
V_7 -> V_27 = F_4 ( V_24 ) ;
} else {
F_10 ( L_1 , V_20 >> 20 ) ;
}
}
static void T_1 F_11 ( void )
{
if ( F_12 () ) {
F_13 ( 2 , V_28 , V_29 ) ;
} else {
T_4 V_30 ;
if ( F_14 () )
V_30 = V_31 ;
else
V_30 = V_28 ;
V_32 [ 0 ] . V_30 = V_30 ;
V_32 [ 0 ] . V_33 = V_30 + V_29 - 1 ;
F_15 ( & V_34 ) ;
}
}
static unsigned char F_16 ( unsigned long V_10 )
{
F_7 ( V_10 , V_35 ) ;
return F_6 ( V_36 ) ;
}
static void F_17 ( unsigned char V_37 , unsigned long V_10 )
{
F_7 ( V_10 , V_35 ) ;
F_7 ( V_37 , V_36 ) ;
}
static void T_1 F_18 ( void )
{
F_19 () ;
F_11 () ;
F_15 ( & V_38 ) ;
F_15 ( & V_39 ) ;
F_20 ( & V_40 , 1 ) ;
}
