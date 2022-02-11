static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
if ( ! ( F_3 ( V_4 , V_5 ) & 0x80 ) ) {
V_4 -> V_6 = 1 ;
V_4 -> V_7 = 1 ;
}
V_4 -> V_8 = F_4 ( V_2 ) ;
V_4 -> V_9 = V_10 ;
V_4 -> V_11 = V_12 ;
V_4 -> V_13 = NULL ;
V_4 -> V_14 = NULL ;
V_4 -> V_15 = NULL ;
V_11 ( V_4 ) ;
return 0 ;
}
static int F_5 ( struct V_16 * V_17 )
{
struct V_18 * V_19 = V_17 -> V_20 . V_21 ;
struct V_1 * V_2 ;
struct V_3 * V_4 = NULL ;
struct V_22 V_23 ;
int V_24 ;
int V_25 ;
if ( F_6 () )
return - V_26 ;
F_7 ( & V_17 -> V_20 , L_1 ) ;
V_25 = F_8 ( V_19 , 0 , & V_23 ) ;
if ( V_25 )
return V_25 ;
V_17 -> V_20 . V_27 = & V_17 -> V_20 . V_28 ;
V_2 = F_9 ( & V_29 , & V_17 -> V_20 ,
L_2 ) ;
if ( ! V_2 )
return - V_30 ;
V_2 -> V_31 = V_23 . V_32 ;
V_2 -> V_33 = F_10 ( & V_23 ) ;
if ( ! F_11 ( V_2 -> V_31 , V_2 -> V_33 , V_34 ) ) {
F_12 ( V_35 L_3 , __FILE__ ) ;
V_25 = - V_36 ;
goto V_37;
}
V_24 = F_13 ( V_19 , 0 ) ;
if ( V_24 == V_38 ) {
F_12 ( V_35 L_4 , __FILE__ ) ;
V_25 = - V_36 ;
goto V_39;
}
V_2 -> V_40 = F_14 ( V_2 -> V_31 , V_2 -> V_33 ) ;
if ( ! V_2 -> V_40 ) {
F_12 ( V_35 L_5 , __FILE__ ) ;
V_25 = - V_30 ;
goto V_41;
}
V_4 = F_2 ( V_2 ) ;
V_4 -> V_40 = V_2 -> V_40 ;
V_25 = F_15 ( V_2 , V_24 , 0 ) ;
if ( V_25 )
goto V_42;
return 0 ;
V_42:
F_16 ( V_2 -> V_40 ) ;
V_41:
F_17 ( V_24 ) ;
V_39:
F_18 ( V_2 -> V_31 , V_2 -> V_33 ) ;
V_37:
F_19 ( V_2 ) ;
return V_25 ;
}
static int F_20 ( struct V_16 * V_17 )
{
struct V_1 * V_2 = F_21 ( V_17 ) ;
F_7 ( & V_17 -> V_20 , L_6 ) ;
F_22 ( V_2 ) ;
F_16 ( V_2 -> V_40 ) ;
F_17 ( V_2 -> V_24 ) ;
F_18 ( V_2 -> V_31 , V_2 -> V_33 ) ;
F_19 ( V_2 ) ;
return 0 ;
}
static void F_23 ( struct V_16 * V_17 )
{
struct V_1 * V_2 = F_21 ( V_17 ) ;
F_24 ( F_2 ( V_2 ) ) ;
}
