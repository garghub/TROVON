static void F_1 ( struct V_1 * V_2 )
{
F_2 ( V_2 -> V_3 ) ;
F_3 ( V_2 -> V_4 , 0 ) ;
V_2 -> V_5 = F_4 () ;
V_2 -> V_6 = F_5 () ;
F_6 ( V_2 -> V_7 ) ;
F_7 ( V_2 -> V_8 ) ;
F_8 () ;
}
static void F_9 ( struct V_1 * V_2 )
{
F_6 ( V_2 -> V_5 ) ;
F_7 ( V_2 -> V_6 ) ;
F_8 () ;
F_3 ( V_2 -> V_4 , 1 ) ;
F_10 ( V_2 -> V_3 ) ;
}
static T_1 F_11 ( struct V_9 * V_10 , unsigned long V_11 )
{
struct V_1 * V_2 = (struct V_1 * ) V_10 -> V_12 ;
T_2 V_13 ;
T_1 V_14 ;
F_1 ( V_2 ) ;
V_13 = F_12 ( V_10 -> V_15 + V_11 ) ;
F_9 ( V_2 ) ;
V_14 . V_16 [ 0 ] = V_13 ;
return V_14 ;
}
static void F_13 ( struct V_9 * V_10 , void * V_17 , unsigned long V_18 , T_3 V_19 )
{
struct V_1 * V_2 = (struct V_1 * ) V_10 -> V_12 ;
F_1 ( V_2 ) ;
memcpy ( V_17 , V_10 -> V_15 + V_18 , V_19 ) ;
F_9 ( V_2 ) ;
}
static void F_14 ( struct V_9 * V_10 , T_1 V_20 , unsigned long V_11 )
{
struct V_1 * V_2 = (struct V_1 * ) V_10 -> V_12 ;
T_2 V_21 ;
V_21 = V_20 . V_16 [ 0 ] ;
F_1 ( V_2 ) ;
F_15 ( V_21 , V_10 -> V_15 + V_11 ) ;
F_8 () ;
F_9 ( V_2 ) ;
}
static void F_16 ( struct V_9 * V_10 , unsigned long V_17 , const void * V_18 , T_3 V_19 )
{
struct V_1 * V_2 = (struct V_1 * ) V_10 -> V_12 ;
F_1 ( V_2 ) ;
memcpy ( V_10 -> V_15 + V_17 , V_18 , V_19 ) ;
F_8 () ;
F_9 ( V_2 ) ;
}
static int T_4 F_17 ( struct V_22 * V_23 )
{
int V_24 ;
struct V_25 * V_26 = V_23 -> V_27 . V_28 ;
struct V_29 * V_30 = F_18 ( V_23 , V_31 , 0 ) ;
struct V_29 * V_32 = F_18 ( V_23 , V_31 , 1 ) ;
struct V_1 * V_2 ;
V_2 = F_19 ( sizeof( * V_2 ) , V_33 ) ;
if ( ! V_2 )
return - V_34 ;
V_2 -> V_10 . V_35 = V_36 ;
V_2 -> V_10 . V_37 = F_11 ;
V_2 -> V_10 . V_38 = F_13 ;
V_2 -> V_10 . V_39 = F_14 ;
V_2 -> V_10 . V_40 = F_16 ;
V_2 -> V_10 . V_41 = V_26 -> V_42 ;
V_2 -> V_10 . V_43 = V_30 -> V_44 - V_30 -> V_45 + 1 ;
V_2 -> V_10 . V_15 = ( void V_46 * ) V_30 -> V_45 ;
V_2 -> V_10 . V_47 = V_30 -> V_45 ;
V_2 -> V_10 . V_12 = ( unsigned long ) V_2 ;
V_2 -> V_4 = F_20 ( V_23 , 0 ) ;
V_2 -> V_7 = V_32 -> V_45 ;
V_2 -> V_8 = V_32 -> V_44 ;
if ( F_21 ( V_2 -> V_4 , V_36 ) ) {
F_22 (KERN_ERR DRIVER_NAME L_1 , state->enet_flash_pin) ;
F_23 ( V_2 ) ;
return - V_48 ;
}
F_24 ( V_2 -> V_4 , 1 ) ;
F_22 (KERN_NOTICE DRIVER_NAME L_2 , state->map.bankwidth * 8 ) ;
V_2 -> V_49 = F_25 ( V_30 -> V_35 , & V_2 -> V_10 ) ;
if ( ! V_2 -> V_49 ) {
F_26 ( V_2 -> V_4 ) ;
F_23 ( V_2 ) ;
return - V_50 ;
}
V_24 = F_27 ( V_2 -> V_49 , V_51 , & V_26 -> V_52 , 0 ) ;
if ( V_24 > 0 ) {
F_22 (KERN_NOTICE DRIVER_NAME L_3 ) ;
F_28 ( V_2 -> V_49 , V_26 -> V_52 , V_24 ) ;
V_2 -> V_52 = V_26 -> V_52 ;
} else if ( V_26 -> V_53 ) {
F_22 (KERN_NOTICE DRIVER_NAME L_4 ) ;
F_28 ( V_2 -> V_49 , V_26 -> V_52 , V_26 -> V_53 ) ;
} else {
F_22 (KERN_NOTICE DRIVER_NAME L_5 ) ;
F_28 ( V_2 -> V_49 , NULL , 0 ) ;
}
F_29 ( V_23 , V_2 ) ;
return 0 ;
}
static int T_5 F_30 ( struct V_22 * V_23 )
{
struct V_1 * V_2 = F_31 ( V_23 ) ;
F_26 ( V_2 -> V_4 ) ;
F_32 ( V_2 -> V_49 ) ;
F_23 ( V_2 -> V_52 ) ;
F_33 ( V_2 -> V_49 ) ;
F_23 ( V_2 ) ;
return 0 ;
}
static int T_6 F_34 ( void )
{
return F_35 ( & V_54 ) ;
}
static void T_7 F_36 ( void )
{
F_37 ( & V_54 ) ;
}
