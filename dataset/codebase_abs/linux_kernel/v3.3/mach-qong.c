static inline void T_1 F_1 ( void )
{
F_2 ( V_1 , F_3 ( V_1 ) ,
L_1 ) ;
F_4 ( & V_2 ) ;
}
static int T_1 F_5 ( void )
{
int V_3 ;
V_3 = F_6 ( & V_4 ) ;
return V_3 ;
}
static void F_7 ( void )
{
( void ) F_6 ( & V_5 ) ;
}
static void F_8 ( struct V_6 * V_7 , int V_8 , unsigned int V_9 )
{
struct V_10 * V_10 = V_7 -> V_11 ;
if ( V_8 == V_12 )
return;
if ( V_9 & V_13 )
F_9 ( V_8 , V_10 -> V_14 + ( 1 << 24 ) ) ;
else
F_9 ( V_8 , V_10 -> V_14 + ( 1 << 23 ) ) ;
}
static int F_10 ( struct V_6 * V_7 )
{
return F_11 ( F_12 ( V_15 ) ) ;
}
static void F_13 ( struct V_6 * V_7 , int V_16 )
{
if ( V_16 >= 0 )
F_14 ( F_12 ( V_17 ) , 0 ) ;
else
F_14 ( F_12 ( V_17 ) , 1 ) ;
}
static void T_1 F_15 ( void )
{
F_16 ( 0x00004f00 , F_17 ( F_18 ( 3 ) ) ) ;
F_16 ( 0x20013b31 , F_17 ( F_19 ( 3 ) ) ) ;
F_16 ( 0x00020800 , F_17 ( F_20 ( 3 ) ) ) ;
F_21 ( V_18 , true ) ;
F_22 ( F_23 ( V_17 , V_19 ) ) ;
if ( ! F_24 ( F_12 ( V_17 ) , L_2 ) )
F_25 ( F_12 ( V_17 ) , 0 ) ;
F_22 ( F_23 ( V_15 , V_19 ) ) ;
if ( ! F_24 ( F_12 ( V_15 ) , L_3 ) )
F_26 ( F_12 ( V_15 ) ) ;
F_22 ( F_23 ( V_20 , V_19 ) ) ;
if ( ! F_24 ( F_12 ( V_20 ) , L_4 ) )
F_26 ( F_12 ( V_20 ) ) ;
F_6 ( & V_21 ) ;
}
static void T_1 F_27 ( void )
{
void T_2 * V_22 ;
T_3 V_23 ;
V_22 = F_28 ( V_24 , V_25 ) ;
if ( ! V_22 ) {
F_29 ( V_26 L_5 ,
V_27 ) ;
return;
}
V_23 = F_30 ( V_22 + V_28 ) ;
F_31 ( V_22 ) ;
F_29 ( V_29 L_6 ,
( V_23 & 0xF000 ) >> 12 ,
( V_23 & 0x0F00 ) >> 8 , V_23 & 0x00FF ) ;
if ( V_23 < F_32 ( 0 , 8 , 7 ) ) {
F_29 ( V_26 L_7
L_8 ) ;
return;
}
F_15 () ;
F_5 () ;
}
static void T_1 F_33 ( void )
{
F_34 () ;
F_1 () ;
F_7 () ;
F_27 () ;
F_35 ( NULL ) ;
}
static void T_1 F_36 ( void )
{
F_37 ( 26000000 ) ;
}
