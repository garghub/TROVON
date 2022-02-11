static int F_1 ( struct V_1 * V_2 )
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
static int F_9 ( struct V_16 * V_7 )
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
if ( F_2 ( V_8 ) && ! V_10 [ 0 ] ) {
struct V_39 * V_40 ;
V_40 = F_15 ( V_8 ) ;
if ( ! V_40 )
goto V_15;
F_16 ( V_8 , V_40 ) ;
V_10 [ 0 ] = V_40 ;
V_10 [ 1 ] = NULL ;
}
V_6 = F_17 ( V_7 , & V_41 , F_1 ) ;
if ( V_6 < 0 )
goto V_42;
F_18 ( V_7 , & V_43 ) ;
F_19 ( & V_8 -> V_44 , V_45 L_2 V_46 L_3 ) ;
return 0 ;
V_42:
F_20 ( V_10 [ 0 ] ) ;
V_10 [ 0 ] = NULL ;
V_15:
F_3 (m, &hidg_func_list, node) {
if ( V_20 == V_5 )
break;
F_21 ( V_20 -> V_14 ) ;
}
return V_6 ;
}
static int F_22 ( struct V_16 * V_7 )
{
struct V_3 * V_5 ;
F_3 (n, &hidg_func_list, node) {
F_7 ( V_5 -> V_13 ) ;
F_21 ( V_5 -> V_14 ) ;
}
F_20 ( V_10 [ 0 ] ) ;
V_10 [ 0 ] = NULL ;
return 0 ;
}
static int F_23 ( struct V_47 * V_48 )
{
struct V_49 * V_27 = F_24 ( & V_48 -> V_44 ) ;
struct V_3 * V_50 ;
if ( ! V_27 ) {
F_25 ( & V_48 -> V_44 , L_4 ) ;
return - V_24 ;
}
V_50 = F_26 ( sizeof( * V_50 ) , V_51 ) ;
if ( ! V_50 )
return - V_52 ;
V_50 -> V_27 = V_27 ;
F_27 ( & V_50 -> V_53 , & V_54 ) ;
return 0 ;
}
static int F_28 ( struct V_47 * V_48 )
{
struct V_3 * V_4 , * V_5 ;
F_29 (e, n, &hidg_func_list, node) {
F_30 ( & V_4 -> V_53 ) ;
F_20 ( V_4 ) ;
}
return 0 ;
}
static int T_1 F_31 ( void )
{
int V_6 ;
V_6 = F_32 ( & V_55 ,
F_23 ) ;
if ( V_6 < 0 )
return V_6 ;
V_6 = F_33 ( & V_56 ) ;
if ( V_6 < 0 )
F_34 ( & V_55 ) ;
return V_6 ;
}
static void T_2 F_35 ( void )
{
F_36 ( & V_56 ) ;
F_34 ( & V_55 ) ;
}
