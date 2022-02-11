static int T_1 F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
int V_5 = 0 , V_6 = 0 ;
if ( F_2 ( V_2 -> V_7 -> V_8 ) ) {
V_2 -> V_9 = V_10 ;
V_2 -> V_11 |= V_12 ;
}
F_3 (e, &hidg_func_list, node) {
V_6 = F_4 ( V_2 , V_4 -> V_5 , V_5 ++ ) ;
if ( V_6 )
break;
}
return V_6 ;
}
static int T_1 F_5 ( struct V_13 * V_7 )
{
struct V_14 * V_8 = V_7 -> V_8 ;
struct V_15 * V_16 ;
int V_6 , V_17 , V_18 = 0 ;
F_6 (tmp, &hidg_func_list)
V_18 ++ ;
if ( ! V_18 )
return - V_19 ;
V_6 = F_7 ( V_7 -> V_8 , V_18 ) ;
if ( V_6 < 0 )
return V_6 ;
V_17 = F_8 ( V_8 ) ;
if ( V_17 >= 0 )
V_20 . V_21 = F_9 ( 0x0300 | V_17 ) ;
else
V_20 . V_21 = F_9 ( 0x0300 | 0x0099 ) ;
snprintf ( V_22 , sizeof V_22 , L_1 ,
F_10 () -> V_23 , F_10 () -> V_24 ,
V_8 -> V_25 ) ;
V_6 = F_11 ( V_7 ) ;
if ( V_6 < 0 )
return V_6 ;
V_26 [ V_27 ] . V_28 = V_6 ;
V_20 . V_29 = V_6 ;
V_6 = F_11 ( V_7 ) ;
if ( V_6 < 0 )
return V_6 ;
V_26 [ V_30 ] . V_28 = V_6 ;
V_20 . V_31 = V_6 ;
V_6 = F_12 ( V_7 , & V_32 , F_1 ) ;
if ( V_6 < 0 )
return V_6 ;
F_13 ( & V_8 -> V_33 , V_34 L_2 V_35 L_3 ) ;
return 0 ;
}
static int T_2 F_14 ( struct V_13 * V_7 )
{
F_15 () ;
return 0 ;
}
static int T_1 F_16 ( struct V_36 * V_37 )
{
struct V_38 * V_5 = V_37 -> V_33 . V_39 ;
struct V_3 * V_40 ;
if ( ! V_5 ) {
F_17 ( & V_37 -> V_33 , L_4 ) ;
return - V_19 ;
}
V_40 = F_18 ( sizeof( * V_40 ) , V_41 ) ;
if ( ! V_40 )
return - V_42 ;
V_40 -> V_5 = V_5 ;
F_19 ( & V_40 -> V_43 , & V_44 ) ;
return 0 ;
}
static int T_3 F_20 ( struct V_36 * V_37 )
{
struct V_3 * V_4 , * V_45 ;
F_21 (e, n, &hidg_func_list, node) {
F_22 ( & V_4 -> V_43 ) ;
F_23 ( V_4 ) ;
}
return 0 ;
}
static int T_1 F_24 ( void )
{
int V_6 ;
V_6 = F_25 ( & V_46 ,
F_16 ) ;
if ( V_6 < 0 )
return V_6 ;
V_6 = F_26 ( & V_47 , F_5 ) ;
if ( V_6 < 0 )
F_27 ( & V_46 ) ;
return V_6 ;
}
static void T_2 F_28 ( void )
{
F_27 ( & V_46 ) ;
F_29 ( & V_47 ) ;
}
