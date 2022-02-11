static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
int V_5 ;
V_5 = F_3 ( V_4 ) ;
if ( V_5 )
return V_5 ;
V_5 = F_4 ( V_2 ) ;
if ( V_5 )
return V_5 ;
V_4 -> V_6 = 0x20 ;
F_5 ( V_4 , 1 ) ;
return F_6 ( V_4 ) ;
}
static int T_1 F_7 ( struct V_7 * V_8 )
{
struct V_9 * V_10 = V_8 -> V_11 . V_12 ;
struct V_1 * V_2 ;
struct V_3 * V_4 = NULL ;
struct V_13 V_14 ;
T_2 V_15 ;
int V_16 ;
int V_17 ;
if ( F_8 () )
return - V_18 ;
F_9 ( & V_8 -> V_11 , L_1 ) ;
V_17 = F_10 ( V_10 , 0 , & V_14 ) ;
if ( V_17 )
return V_17 ;
V_8 -> V_11 . V_19 = & V_8 -> V_11 . V_20 ;
V_2 = F_11 ( & V_21 , & V_8 -> V_11 ,
L_2 ) ;
if ( ! V_2 )
return - V_22 ;
V_2 -> V_23 = V_14 . V_24 ;
V_2 -> V_25 = V_14 . V_26 - V_14 . V_24 + 1 ;
if ( ! F_12 ( V_2 -> V_23 , V_2 -> V_25 , V_27 ) ) {
F_13 ( V_28 L_3 , __FILE__ ) ;
V_17 = - V_29 ;
goto V_30;
}
V_16 = F_14 ( V_10 , 0 ) ;
if ( V_16 == V_31 ) {
F_13 ( V_28 L_4 , __FILE__ ) ;
V_17 = - V_29 ;
goto V_32;
}
V_2 -> V_33 = F_15 ( V_2 -> V_23 , V_2 -> V_25 ) ;
if ( ! V_2 -> V_33 ) {
F_13 ( V_28 L_5 , __FILE__ ) ;
V_17 = - V_22 ;
goto V_34;
}
V_4 = F_2 ( V_2 ) ;
V_4 -> V_35 = V_2 -> V_33 ;
V_15 = F_16 ( V_4 , & V_4 -> V_35 -> V_15 ) ;
if ( F_17 ( V_4 , V_15 ) != V_36 ) {
V_4 -> V_37 = 1 ;
V_4 -> V_38 = 1 ;
V_4 -> V_39 = 1 ;
}
V_4 -> V_33 = V_2 -> V_33 +
F_18 ( V_4 , F_16 ( V_4 , & V_4 -> V_35 -> V_15 ) ) ;
V_4 -> V_40 = F_16 ( V_4 , & V_4 -> V_35 -> V_40 ) ;
V_17 = F_19 ( V_2 , V_16 , 0 ) ;
if ( V_17 )
goto V_41;
return 0 ;
V_41:
F_20 ( V_2 -> V_33 ) ;
V_34:
F_21 ( V_16 ) ;
V_32:
F_22 ( V_2 -> V_23 , V_2 -> V_25 ) ;
V_30:
F_23 ( V_2 ) ;
return V_17 ;
}
static int F_24 ( struct V_7 * V_8 )
{
struct V_1 * V_2 = F_25 ( & V_8 -> V_11 ) ;
F_26 ( & V_8 -> V_11 , NULL ) ;
F_9 ( & V_8 -> V_11 , L_6 ) ;
F_27 ( V_2 ) ;
F_20 ( V_2 -> V_33 ) ;
F_21 ( V_2 -> V_16 ) ;
F_22 ( V_2 -> V_23 , V_2 -> V_25 ) ;
F_23 ( V_2 ) ;
return 0 ;
}
static void F_28 ( struct V_7 * V_8 )
{
struct V_1 * V_2 = F_25 ( & V_8 -> V_11 ) ;
if ( V_2 -> V_42 -> V_43 )
V_2 -> V_42 -> V_43 ( V_2 ) ;
}
