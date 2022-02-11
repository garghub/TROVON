static int F_1 ( struct V_1 * V_2 )
{
return 0 ;
}
static int F_2 ( struct V_3 * V_4 ,
struct V_5 * V_6 ,
struct V_5 * V_7 )
{
return 1 ;
}
static int F_3 ( struct V_3 * V_4 , T_1 V_8 )
{
return 0 ;
}
static int F_4 ( struct V_3 * V_4 )
{
return 0 ;
}
static int F_5 ( struct V_9 * V_10 )
{
struct V_11 * V_11 = F_6 ( V_10 ) ;
if ( V_11 -> V_10 . V_12 != 1 )
return - V_13 ;
if ( F_7 ( V_14 , V_11 , & V_15 ) ) {
F_8 (KERN_ERR PFX L_1 ) ;
return - V_16 ;
}
if ( V_11 -> V_10 . V_17 -> V_18 ( V_11 -> V_10 . V_17 ,
F_9 () ,
& V_19 , V_11 ) ) {
F_8 (KERN_ERR PFX L_2 ) ;
F_10 ( F_9 () , V_11 ) ;
return - V_16 ;
}
return 0 ;
}
static void F_11 ( struct V_9 * V_10 )
{
struct V_11 * V_11 = F_6 ( V_10 ) ;
if ( ! V_11 -> V_10 . V_17 ) {
F_8 (KERN_ERR PFX L_3 ) ;
return;
}
V_11 -> V_10 . V_17 -> V_20 ( V_11 -> V_10 . V_17 , V_11 ) ;
}
static int T_2 F_12 ( void )
{
V_11 = F_13 ( sizeof( struct V_11 ) , V_21 ) ;
if ( ! V_11 )
return - V_22 ;
F_14 ( V_11 -> V_10 . V_23 , L_4 , sizeof( V_11 -> V_10 . V_23 ) ) ;
V_11 -> V_10 . V_24 = V_25 ;
V_11 -> V_10 . V_26 = F_5 ;
V_11 -> V_10 . exit = F_11 ;
if ( F_15 ( & V_11 -> V_10 ) ) {
F_16 ( V_11 ) ;
return - V_27 ;
}
return 0 ;
}
static void T_3 F_17 ( void )
{
F_18 ( & V_11 -> V_10 ) ;
F_16 ( V_11 ) ;
}
