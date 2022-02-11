static int T_1 F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 , * V_5 ;
int V_6 = 0 ;
if ( F_2 ( V_2 -> V_7 -> V_8 ) ) {
V_2 -> V_9 = V_10 ;
V_2 -> V_11 |= V_12 ;
}
F_3 (e, &hidg_func_list, node) {
V_4 -> V_13 = F_4 ( V_4 -> V_14 ) ;
if ( F_5 ( V_4 -> V_13 ) )
goto V_15;
V_6 = F_6 ( V_2 , V_4 -> V_13 ) ;
if ( V_6 < 0 ) {
F_7 ( V_4 -> V_13 ) ;
goto V_15;
}
}
return 0 ;
V_15:
F_3 (n, &hidg_func_list, node) {
if ( V_5 == V_4 )
break;
F_8 ( V_2 , V_5 -> V_13 ) ;
F_7 ( V_5 -> V_13 ) ;
}
return V_6 ;
}
static int T_1 F_9 ( struct V_16 * V_7 )
{
struct V_17 * V_8 = V_7 -> V_8 ;
struct V_18 * V_19 ;
struct V_3 * V_5 , * V_20 ;
struct V_21 * V_22 ;
int V_6 , V_23 = 0 ;
F_10 (tmp, &hidg_func_list)
V_23 ++ ;
if ( ! V_23 )
return - V_24 ;
F_3 (n, &hidg_func_list, node) {
V_5 -> V_14 = F_11 ( L_1 ) ;
if ( F_5 ( V_5 -> V_14 ) ) {
V_6 = F_12 ( V_5 -> V_14 ) ;
goto V_15;
}
V_22 = F_13 ( V_5 -> V_14 , struct V_21 , V_25 ) ;
V_22 -> V_26 = V_5 -> V_27 -> V_26 ;
V_22 -> V_28 = V_5 -> V_27 -> V_28 ;
V_22 -> V_29 = V_5 -> V_27 -> V_29 ;
V_22 -> V_30 = V_5 -> V_27 -> V_30 ;
V_22 -> V_31 = V_5 -> V_27 -> V_31 ;
}
V_6 = F_14 ( V_7 , V_32 ) ;
if ( V_6 < 0 )
goto V_15;
V_33 . V_34 = V_32 [ V_35 ] . V_36 ;
V_33 . V_37 = V_32 [ V_38 ] . V_36 ;
V_6 = F_15 ( V_7 , & V_39 , F_1 ) ;
if ( V_6 < 0 )
goto V_15;
F_16 ( V_7 , & V_40 ) ;
F_17 ( & V_8 -> V_41 , V_42 L_2 V_43 L_3 ) ;
return 0 ;
V_15:
F_3 (m, &hidg_func_list, node) {
if ( V_20 == V_5 )
break;
F_18 ( V_20 -> V_14 ) ;
}
return V_6 ;
}
static int T_2 F_19 ( struct V_16 * V_7 )
{
struct V_3 * V_5 ;
F_3 (n, &hidg_func_list, node) {
F_7 ( V_5 -> V_13 ) ;
F_18 ( V_5 -> V_14 ) ;
}
return 0 ;
}
static int T_1 F_20 ( struct V_44 * V_45 )
{
struct V_46 * V_27 = F_21 ( & V_45 -> V_41 ) ;
struct V_3 * V_47 ;
if ( ! V_27 ) {
F_22 ( & V_45 -> V_41 , L_4 ) ;
return - V_24 ;
}
V_47 = F_23 ( sizeof( * V_47 ) , V_48 ) ;
if ( ! V_47 )
return - V_49 ;
V_47 -> V_27 = V_27 ;
F_24 ( & V_47 -> V_50 , & V_51 ) ;
return 0 ;
}
static int F_25 ( struct V_44 * V_45 )
{
struct V_3 * V_4 , * V_5 ;
F_26 (e, n, &hidg_func_list, node) {
F_27 ( & V_4 -> V_50 ) ;
F_28 ( V_4 ) ;
}
return 0 ;
}
static int T_1 F_29 ( void )
{
int V_6 ;
V_6 = F_30 ( & V_52 ,
F_20 ) ;
if ( V_6 < 0 )
return V_6 ;
V_6 = F_31 ( & V_53 ) ;
if ( V_6 < 0 )
F_32 ( & V_52 ) ;
return V_6 ;
}
static void T_2 F_33 ( void )
{
F_34 ( & V_53 ) ;
F_32 ( & V_52 ) ;
}
