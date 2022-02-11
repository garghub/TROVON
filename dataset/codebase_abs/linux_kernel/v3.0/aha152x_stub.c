static int F_1 ( struct V_1 * V_2 )
{
T_1 * V_3 ;
F_2 ( & V_2 -> V_4 , L_1 ) ;
V_3 = F_3 ( sizeof( * V_3 ) , V_5 ) ;
if ( ! V_3 ) return - V_6 ;
V_3 -> V_7 = V_2 ;
V_2 -> V_8 = V_3 ;
V_2 -> V_9 |= V_10 | V_11 ;
V_2 -> V_12 = V_13 ;
return F_4 ( V_2 ) ;
}
static void F_5 ( struct V_1 * V_2 )
{
F_2 ( & V_2 -> V_4 , L_2 ) ;
F_6 ( V_2 ) ;
F_7 ( V_2 -> V_8 ) ;
}
static int F_8 ( struct V_1 * V_7 , void * V_14 )
{
V_7 -> V_15 = 10 ;
if ( ( V_7 -> V_16 [ 0 ] -> V_17 < 0x20 ) &&
( V_7 -> V_16 [ 1 ] -> V_17 >= 0x20 ) )
V_7 -> V_16 [ 0 ] -> V_18 = V_7 -> V_16 [ 1 ] -> V_18 ;
if ( V_7 -> V_16 [ 0 ] -> V_18 >= 0xffff )
return - V_19 ;
V_7 -> V_16 [ 1 ] -> V_18 = V_7 -> V_16 [ 1 ] -> V_17 = 0 ;
V_7 -> V_16 [ 0 ] -> V_17 = 0x20 ;
V_7 -> V_16 [ 0 ] -> V_20 &= ~ V_21 ;
V_7 -> V_16 [ 0 ] -> V_20 |= V_22 ;
return F_9 ( V_7 ) ;
}
static int F_4 ( struct V_1 * V_2 )
{
T_1 * V_3 = V_2 -> V_8 ;
struct V_23 V_24 ;
int V_25 ;
struct V_26 * V_27 ;
F_2 ( & V_2 -> V_4 , L_3 ) ;
V_25 = F_10 ( V_2 , F_8 , NULL ) ;
if ( V_25 )
goto V_28;
if ( ! V_2 -> V_29 )
goto V_28;
V_25 = F_11 ( V_2 ) ;
if ( V_25 )
goto V_28;
memset ( & V_24 , 0 , sizeof( V_24 ) ) ;
V_24 . V_30 = L_4 ;
V_24 . V_31 = V_2 -> V_16 [ 0 ] -> V_18 ;
V_24 . V_29 = V_2 -> V_29 ;
V_24 . V_32 = V_33 ;
V_24 . V_34 = V_34 ;
V_24 . V_35 = V_35 ;
V_24 . V_36 = V_36 ;
V_24 . V_37 = V_38 ;
if ( V_39 )
V_24 . V_39 = V_39 ;
V_27 = F_12 ( & V_24 ) ;
if ( V_27 == NULL ) {
F_13 ( V_40 L_5 ) ;
goto V_28;
}
V_3 -> V_27 = V_27 ;
return 0 ;
V_28:
F_6 ( V_2 ) ;
return - V_41 ;
}
static void F_6 ( struct V_1 * V_2 )
{
T_1 * V_3 = V_2 -> V_8 ;
F_14 ( V_3 -> V_27 ) ;
F_15 ( V_2 ) ;
}
static int F_16 ( struct V_1 * V_2 )
{
T_1 * V_3 = V_2 -> V_8 ;
F_17 ( V_3 -> V_27 ) ;
return 0 ;
}
static int T_2 F_18 ( void )
{
return F_19 ( & V_42 ) ;
}
static void T_3 F_20 ( void )
{
F_21 ( & V_42 ) ;
}
