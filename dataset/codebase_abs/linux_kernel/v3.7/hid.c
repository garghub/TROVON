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
int V_6 , V_17 = 0 ;
F_6 (tmp, &hidg_func_list)
V_17 ++ ;
if ( ! V_17 )
return - V_18 ;
V_6 = F_7 ( V_7 -> V_8 , V_17 ) ;
if ( V_6 < 0 )
return V_6 ;
V_6 = F_8 ( V_7 , V_19 ) ;
if ( V_6 < 0 )
return V_6 ;
V_20 . V_21 = V_19 [ V_22 ] . V_23 ;
V_20 . V_24 = V_19 [ V_25 ] . V_23 ;
V_6 = F_9 ( V_7 , & V_26 , F_1 ) ;
if ( V_6 < 0 )
return V_6 ;
F_10 ( V_7 , & V_27 ) ;
F_11 ( & V_8 -> V_28 , V_29 L_1 V_30 L_2 ) ;
return 0 ;
}
static int T_2 F_12 ( struct V_13 * V_7 )
{
F_13 () ;
return 0 ;
}
static int T_1 F_14 ( struct V_31 * V_32 )
{
struct V_33 * V_5 = V_32 -> V_28 . V_34 ;
struct V_3 * V_35 ;
if ( ! V_5 ) {
F_15 ( & V_32 -> V_28 , L_3 ) ;
return - V_18 ;
}
V_35 = F_16 ( sizeof( * V_35 ) , V_36 ) ;
if ( ! V_35 )
return - V_37 ;
V_35 -> V_5 = V_5 ;
F_17 ( & V_35 -> V_38 , & V_39 ) ;
return 0 ;
}
static int T_3 F_18 ( struct V_31 * V_32 )
{
struct V_3 * V_4 , * V_40 ;
F_19 (e, n, &hidg_func_list, node) {
F_20 ( & V_4 -> V_38 ) ;
F_21 ( V_4 ) ;
}
return 0 ;
}
static int T_1 F_22 ( void )
{
int V_6 ;
V_6 = F_23 ( & V_41 ,
F_14 ) ;
if ( V_6 < 0 )
return V_6 ;
V_6 = F_24 ( & V_42 ) ;
if ( V_6 < 0 )
F_25 ( & V_41 ) ;
return V_6 ;
}
static void T_2 F_26 ( void )
{
F_25 ( & V_41 ) ;
F_27 ( & V_42 ) ;
}
