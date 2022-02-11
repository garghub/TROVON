static int F_1 ( struct V_1 * V_2 )
{
int V_3 ;
F_2 ( L_1 , V_4 ) ;
if ( V_2 -> V_5 -> V_6 -> V_7 . V_8 != 1 ) {
F_3 ( & V_2 -> V_5 -> V_5 , L_2 ,
V_2 -> V_5 -> V_6 -> V_7 . V_8 ) ;
return - V_9 ;
}
F_2 ( L_3 , V_4 ) ;
V_3 = F_4 ( V_2 -> V_5 ) ;
return V_3 ;
}
static void F_5 ( struct V_10 * V_11 )
{
struct V_12 * V_13 = V_11 -> V_13 ;
V_13 -> V_14
&= ~ ( V_15
| V_16
| V_17
| V_18
| V_19
| V_20
| V_21
| V_22 ) ;
V_13 -> V_23
&= ~ V_24 ;
V_13 -> V_25
&= ~ ( V_26
| V_27
| V_28
| V_29
| V_30 ) ;
V_13 -> V_31
&= ~ ( V_32
| V_33
| V_34 ) ;
V_13 -> V_31
|= V_35 ;
F_6 ( V_11 , 115200 , 115200 ) ;
}
static int T_1 F_7 ( void )
{
int V_36 ;
V_36 = F_8 ( & V_37 ) ;
if ( V_36 )
return V_36 ;
V_36 = F_9 ( & V_38 ) ;
if ( V_36 ) {
F_10 ( & V_37 ) ;
return V_36 ;
}
F_11 (KERN_INFO KBUILD_MODNAME L_4 DRIVER_VERSION L_5
DRIVER_DESC L_6 ) ;
return 0 ;
}
static void T_2 F_12 ( void )
{
F_13 ( & V_38 ) ;
F_10 ( & V_37 ) ;
}
