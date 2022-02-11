static void F_1 ( struct V_1 * V_2 )
{
F_2 ( V_2 , V_3 ,
( V_4 ) ~ V_5 | V_6 |
V_7 ) ;
}
static void F_3 ( struct V_1 * V_2 , V_4 V_8 )
{
F_2 ( V_2 , V_9 , V_8 ) ;
F_2 ( V_2 , V_10 , 0 ) ;
F_2 ( V_2 , V_3 ,
V_5 | V_7 ) ;
}
static int F_4 ( struct V_11 * V_12 )
{
F_1 ( V_13 ) ;
return 0 ;
}
static int F_5 ( struct V_11 * V_12 )
{
F_1 ( V_13 ) ;
F_3 ( V_13 , V_14 ) ;
return 0 ;
}
static int F_6 ( unsigned long V_8 , struct V_11 * V_12 )
{
F_3 ( V_13 , V_8 ) ;
return 0 ;
}
static T_1 F_7 ( int V_15 , void * V_16 )
{
V_4 V_17 = F_8 ( V_13 , V_3 ) ;
if ( ! ( V_17 & ( V_18 | V_7 | V_6 ) ) )
return V_19 ;
F_1 ( V_13 ) ;
if ( F_9 ( & V_20 ) ||
F_10 ( & V_20 ) )
return V_21 ;
F_2 ( V_13 , V_10 , 0 ) ;
if ( F_11 ( & V_20 ) )
F_2 ( V_13 , V_3 ,
V_5 | V_7 ) ;
V_20 . V_22 ( & V_20 ) ;
return V_21 ;
}
static int T_2 F_12 ( void )
{
struct V_1 * V_2 ;
int V_23 ;
V_4 V_17 ;
V_2 = F_13 ( V_24 , V_25 ) ;
if ( ! V_2 ) {
F_14 (KERN_ERR DRV_NAME L_1 ) ;
return - V_26 ;
}
V_13 = V_2 ;
if ( F_15 ( V_2 , V_27 , & V_28 ) ) {
F_14 (KERN_ERR DRV_NAME L_2 ,
timer_irq) ;
goto V_29;
}
V_23 = F_16 ( V_28 , & V_30 ) ;
if ( V_23 ) {
F_14 (KERN_ERR DRV_NAME L_3 ) ;
goto V_31;
}
V_17 = V_32 | ( 3 << 8 ) ;
F_2 ( V_13 , V_3 , V_17 ) ;
F_14 (KERN_INFO DRV_NAME
L_4 ,
timer_irq) ;
F_17 ( & V_20 , V_33 ,
0xF , 0xFFFE ) ;
return 0 ;
V_31:
F_18 ( V_13 , V_27 , & V_28 ) ;
V_29:
F_19 ( V_13 ) ;
F_14 (KERN_ERR DRV_NAME L_5 ) ;
return - V_34 ;
}
