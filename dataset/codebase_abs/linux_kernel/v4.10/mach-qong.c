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
struct V_14 * V_14 = F_11 ( V_11 ) ;
if ( V_12 == V_15 )
return;
if ( V_13 & V_16 )
F_12 ( V_12 , V_14 -> V_17 + ( 1 << 24 ) ) ;
else
F_12 ( V_12 , V_14 -> V_17 + ( 1 << 23 ) ) ;
}
static int F_13 ( struct V_10 * V_11 )
{
return F_14 ( F_7 ( V_18 ) ) ;
}
static void F_15 ( struct V_10 * V_11 , int V_19 )
{
if ( V_19 >= 0 )
F_16 ( F_7 ( V_20 ) , 0 ) ;
else
F_16 ( F_7 ( V_20 ) , 1 ) ;
}
static void T_1 F_17 ( void )
{
F_18 ( 0x00004f00 , F_19 ( F_20 ( 3 ) ) ) ;
F_18 ( 0x20013b31 , F_19 ( F_21 ( 3 ) ) ) ;
F_18 ( 0x00020800 , F_19 ( F_22 ( 3 ) ) ) ;
F_23 ( V_21 , true ) ;
F_24 ( F_25 ( V_20 , V_22 ) ) ;
if ( ! F_26 ( F_7 ( V_20 ) , L_2 ) )
F_27 ( F_7 ( V_20 ) , 0 ) ;
F_24 ( F_25 ( V_18 , V_22 ) ) ;
if ( ! F_26 ( F_7 ( V_18 ) , L_3 ) )
F_28 ( F_7 ( V_18 ) ) ;
F_24 ( F_25 ( V_23 , V_22 ) ) ;
if ( ! F_26 ( F_7 ( V_23 ) , L_4 ) )
F_28 ( F_7 ( V_23 ) ) ;
F_8 ( & V_24 ) ;
}
static void T_1 F_29 ( void )
{
void T_2 * V_25 ;
T_3 V_26 ;
V_25 = F_30 ( V_27 , V_28 ) ;
if ( ! V_25 ) {
F_31 ( V_29 L_5 ,
V_30 ) ;
return;
}
V_26 = F_32 ( V_25 + V_31 ) ;
F_33 ( V_25 ) ;
F_31 ( V_32 L_6 ,
( V_26 & 0xF000 ) >> 12 ,
( V_26 & 0x0F00 ) >> 8 , V_26 & 0x00FF ) ;
if ( V_26 < F_34 ( 0 , 8 , 7 ) ) {
F_31 ( V_29 L_7
L_8 ) ;
return;
}
F_17 () ;
F_5 () ;
}
static void T_1 F_35 ( void )
{
F_36 () ;
F_1 () ;
F_9 () ;
F_37 () ;
}
static void T_1 F_38 ( void )
{
F_39 ( 26000000 ) ;
}
