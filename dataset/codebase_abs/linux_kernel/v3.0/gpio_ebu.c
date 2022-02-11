static void F_1 ( void )
{
unsigned long V_1 ;
F_2 ( & V_2 , V_1 ) ;
F_3 ( V_3 , V_4 ) ;
* ( ( V_5 * ) V_6 ) = V_7 ;
F_3 ( V_3 | V_8 , V_4 ) ;
F_4 ( & V_2 , V_1 ) ;
}
static void F_5 ( struct V_9 * V_10 , unsigned V_11 , int V_12 )
{
if ( V_12 )
V_7 |= ( 1 << V_11 ) ;
else
V_7 &= ~ ( 1 << V_11 ) ;
F_1 () ;
}
static int F_6 ( struct V_9 * V_10 , unsigned V_11 ,
int V_12 )
{
F_5 ( V_10 , V_11 , V_12 ) ;
return 0 ;
}
static int F_7 ( struct V_13 * V_14 )
{
int V_15 = 0 ;
struct V_16 * V_17 = F_8 ( V_14 , V_18 , 0 ) ;
if ( ! V_17 ) {
F_9 ( & V_14 -> V_19 , L_1 ) ;
return - V_20 ;
}
V_17 = F_10 ( & V_14 -> V_19 , V_17 -> V_21 ,
F_11 ( V_17 ) , F_12 ( & V_14 -> V_19 ) ) ;
if ( ! V_17 ) {
F_9 ( & V_14 -> V_19 , L_2 ) ;
return - V_22 ;
}
V_6 = F_13 ( & V_14 -> V_19 , V_17 -> V_21 ,
F_11 ( V_17 ) ) ;
if ( ! V_6 ) {
F_9 ( & V_14 -> V_19 , L_3 ) ;
return - V_23 ;
}
V_7 = ( unsigned int ) V_14 -> V_19 . V_24 ;
F_3 ( V_14 -> V_16 -> V_21 | 0x1 , V_25 ) ;
F_3 ( V_3 | V_8 , V_4 ) ;
V_15 = F_14 ( & V_26 ) ;
if ( ! V_15 )
F_1 () ;
return V_15 ;
}
static int T_1 F_15 ( void )
{
int V_15 = F_16 ( & V_27 ) ;
if ( V_15 )
F_17 ( L_4 ) ;
return V_15 ;
}
