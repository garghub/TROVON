static inline void T_1 F_1 ( void )
{
F_2 ( V_1 , F_3 ( V_1 ) ,
L_1 ) ;
F_4 ( & V_2 ) ;
}
static int T_1 F_5 ( void )
{
int V_3 ;
V_4 [ 1 ] . V_5 =
F_6 ( F_7 ( V_6 ) ) ;
V_4 [ 1 ] . V_7 =
F_6 ( F_7 ( V_6 ) ) ;
V_3 = F_8 ( & V_8 ) ;
return V_3 ;
}
static void F_9 ( void )
{
( void ) F_8 ( & V_9 ) ;
}
static void F_10 ( struct V_10 * V_11 , int V_12 , unsigned int V_13 )
{
struct V_14 * V_14 = V_11 -> V_15 ;
if ( V_12 == V_16 )
return;
if ( V_13 & V_17 )
F_11 ( V_12 , V_14 -> V_18 + ( 1 << 24 ) ) ;
else
F_11 ( V_12 , V_14 -> V_18 + ( 1 << 23 ) ) ;
}
static int F_12 ( struct V_10 * V_11 )
{
return F_13 ( F_7 ( V_19 ) ) ;
}
static void F_14 ( struct V_10 * V_11 , int V_20 )
{
if ( V_20 >= 0 )
F_15 ( F_7 ( V_21 ) , 0 ) ;
else
F_15 ( F_7 ( V_21 ) , 1 ) ;
}
static void T_1 F_16 ( void )
{
F_17 ( 0x00004f00 , F_18 ( F_19 ( 3 ) ) ) ;
F_17 ( 0x20013b31 , F_18 ( F_20 ( 3 ) ) ) ;
F_17 ( 0x00020800 , F_18 ( F_21 ( 3 ) ) ) ;
F_22 ( V_22 , true ) ;
F_23 ( F_24 ( V_21 , V_23 ) ) ;
if ( ! F_25 ( F_7 ( V_21 ) , L_2 ) )
F_26 ( F_7 ( V_21 ) , 0 ) ;
F_23 ( F_24 ( V_19 , V_23 ) ) ;
if ( ! F_25 ( F_7 ( V_19 ) , L_3 ) )
F_27 ( F_7 ( V_19 ) ) ;
F_23 ( F_24 ( V_24 , V_23 ) ) ;
if ( ! F_25 ( F_7 ( V_24 ) , L_4 ) )
F_27 ( F_7 ( V_24 ) ) ;
F_8 ( & V_25 ) ;
}
static void T_1 F_28 ( void )
{
void T_2 * V_26 ;
T_3 V_27 ;
V_26 = F_29 ( V_28 , V_29 ) ;
if ( ! V_26 ) {
F_30 ( V_30 L_5 ,
V_31 ) ;
return;
}
V_27 = F_31 ( V_26 + V_32 ) ;
F_32 ( V_26 ) ;
F_30 ( V_33 L_6 ,
( V_27 & 0xF000 ) >> 12 ,
( V_27 & 0x0F00 ) >> 8 , V_27 & 0x00FF ) ;
if ( V_27 < F_33 ( 0 , 8 , 7 ) ) {
F_30 ( V_30 L_7
L_8 ) ;
return;
}
F_16 () ;
F_5 () ;
}
static void T_1 F_34 ( void )
{
F_35 () ;
F_1 () ;
F_9 () ;
F_28 () ;
F_36 () ;
}
static void T_1 F_37 ( void )
{
F_38 ( 26000000 ) ;
}
