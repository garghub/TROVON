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
static void F_4 ( enum V_11 V_12 ,
struct V_13 * V_14 )
{
F_1 ( V_15 ) ;
if ( V_12 == V_16 )
F_3 ( V_15 , V_17 ) ;
V_18 = V_12 ;
}
static int F_5 ( unsigned long V_8 , struct V_13 * V_14 )
{
F_3 ( V_15 , V_8 ) ;
return 0 ;
}
static T_1 F_6 ( int V_19 , void * V_20 )
{
V_4 V_21 = F_7 ( V_15 , V_3 ) ;
if ( ! ( V_21 & ( V_22 | V_7 | V_6 ) ) )
return V_23 ;
F_1 ( V_15 ) ;
if ( V_18 == V_24 )
return V_25 ;
F_2 ( V_15 , V_10 , 0 ) ;
if ( V_18 == V_16 )
F_2 ( V_15 , V_3 ,
V_5 | V_7 ) ;
V_26 . V_27 ( & V_26 ) ;
return V_25 ;
}
static int T_2 F_8 ( void )
{
struct V_1 * V_2 ;
int V_28 ;
V_4 V_21 ;
V_2 = F_9 ( V_29 , V_30 ) ;
if ( ! V_2 ) {
F_10 (KERN_ERR DRV_NAME L_1 ) ;
return - V_31 ;
}
V_15 = V_2 ;
if ( F_11 ( V_2 , V_32 , & V_33 ) ) {
F_10 (KERN_ERR DRV_NAME L_2 ,
timer_irq) ;
goto V_34;
}
V_28 = F_12 ( V_33 , & V_35 ) ;
if ( V_28 ) {
F_10 (KERN_ERR DRV_NAME L_3 ) ;
goto V_36;
}
V_21 = V_37 | ( 3 << 8 ) ;
F_2 ( V_15 , V_3 , V_21 ) ;
V_26 . V_38 = F_13 ( V_39 , V_40 ,
V_26 . V_41 ) ;
V_26 . V_42 = F_14 ( 0xF ,
& V_26 ) ;
V_26 . V_43 = F_14 ( 0xFFFE ,
& V_26 ) ;
F_10 (KERN_INFO DRV_NAME
L_4 ,
timer_irq) ;
F_15 ( & V_26 ) ;
return 0 ;
V_36:
F_16 ( V_15 , V_32 , & V_33 ) ;
V_34:
F_17 ( V_15 ) ;
F_10 (KERN_ERR DRV_NAME L_5 ) ;
return - V_44 ;
}
