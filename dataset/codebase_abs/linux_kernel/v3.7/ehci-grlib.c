static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
int V_5 ;
V_5 = F_3 ( V_2 ) ;
if ( V_5 )
return V_5 ;
F_4 ( V_4 , 1 ) ;
return V_5 ;
}
static int T_1 F_5 ( struct V_6 * V_7 )
{
struct V_8 * V_9 = V_7 -> V_10 . V_11 ;
struct V_1 * V_2 ;
struct V_3 * V_4 = NULL ;
struct V_12 V_13 ;
T_2 V_14 ;
int V_15 ;
int V_16 ;
if ( F_6 () )
return - V_17 ;
F_7 ( & V_7 -> V_10 , L_1 ) ;
V_16 = F_8 ( V_9 , 0 , & V_13 ) ;
if ( V_16 )
return V_16 ;
V_7 -> V_10 . V_18 = & V_7 -> V_10 . V_19 ;
V_2 = F_9 ( & V_20 , & V_7 -> V_10 ,
L_2 ) ;
if ( ! V_2 )
return - V_21 ;
V_2 -> V_22 = V_13 . V_23 ;
V_2 -> V_24 = F_10 ( & V_13 ) ;
V_15 = F_11 ( V_9 , 0 ) ;
if ( V_15 == V_25 ) {
F_12 ( V_26 L_3 , __FILE__ ) ;
V_16 = - V_27 ;
goto V_28;
}
V_2 -> V_29 = F_13 ( & V_7 -> V_10 , & V_13 ) ;
if ( ! V_2 -> V_29 ) {
F_14 ( L_4 , __FILE__ ) ;
V_16 = - V_21 ;
goto V_30;
}
V_4 = F_2 ( V_2 ) ;
V_4 -> V_31 = V_2 -> V_29 ;
V_14 = F_15 ( V_4 , & V_4 -> V_31 -> V_14 ) ;
if ( F_16 ( V_4 , V_14 ) != V_32 ) {
V_4 -> V_33 = 1 ;
V_4 -> V_34 = 1 ;
V_4 -> V_35 = 1 ;
}
V_16 = F_17 ( V_2 , V_15 , 0 ) ;
if ( V_16 )
goto V_30;
return 0 ;
V_30:
F_18 ( V_15 ) ;
V_28:
F_19 ( V_2 ) ;
return V_16 ;
}
static int F_20 ( struct V_6 * V_7 )
{
struct V_1 * V_2 = F_21 ( & V_7 -> V_10 ) ;
F_22 ( & V_7 -> V_10 , NULL ) ;
F_7 ( & V_7 -> V_10 , L_5 ) ;
F_23 ( V_2 ) ;
F_18 ( V_2 -> V_15 ) ;
F_19 ( V_2 ) ;
return 0 ;
}
static void F_24 ( struct V_6 * V_7 )
{
struct V_1 * V_2 = F_21 ( & V_7 -> V_10 ) ;
if ( V_2 -> V_36 -> V_37 )
V_2 -> V_36 -> V_37 ( V_2 ) ;
}
