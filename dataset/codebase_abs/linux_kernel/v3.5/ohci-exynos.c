static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
int V_5 ;
F_3 ( V_4 , L_1 , V_4 ) ;
V_5 = F_4 ( V_4 ) ;
if ( V_5 < 0 )
return V_5 ;
V_5 = F_5 ( V_4 ) ;
if ( V_5 < 0 ) {
F_6 ( V_2 -> V_6 . V_7 , L_2 ,
V_2 -> V_6 . V_8 ) ;
F_7 ( V_2 ) ;
return V_5 ;
}
return 0 ;
}
static int T_1 F_8 ( struct V_9 * V_10 )
{
struct V_11 * V_12 ;
struct V_13 * V_14 ;
struct V_1 * V_2 ;
struct V_3 * V_4 ;
struct V_15 * V_16 ;
int V_17 ;
int V_18 ;
V_12 = V_10 -> V_19 . V_20 ;
if ( ! V_12 ) {
F_6 ( & V_10 -> V_19 , L_3 ) ;
return - V_21 ;
}
V_14 = F_9 ( sizeof( struct V_13 ) , V_22 ) ;
if ( ! V_14 )
return - V_23 ;
V_14 -> V_19 = & V_10 -> V_19 ;
V_2 = F_10 ( & V_24 , & V_10 -> V_19 ,
F_11 ( & V_10 -> V_19 ) ) ;
if ( ! V_2 ) {
F_6 ( & V_10 -> V_19 , L_4 ) ;
V_18 = - V_23 ;
goto V_25;
}
V_14 -> V_2 = V_2 ;
V_14 -> V_26 = F_12 ( & V_10 -> V_19 , L_5 ) ;
if ( F_13 ( V_14 -> V_26 ) ) {
F_6 ( & V_10 -> V_19 , L_6 ) ;
V_18 = F_14 ( V_14 -> V_26 ) ;
goto V_27;
}
V_18 = F_15 ( V_14 -> V_26 ) ;
if ( V_18 )
goto V_28;
V_16 = F_16 ( V_10 , V_29 , 0 ) ;
if ( ! V_16 ) {
F_6 ( & V_10 -> V_19 , L_7 ) ;
V_18 = - V_30 ;
goto V_31;
}
V_2 -> V_32 = V_16 -> V_33 ;
V_2 -> V_34 = F_17 ( V_16 ) ;
V_2 -> V_35 = F_18 ( V_16 -> V_33 , F_17 ( V_16 ) ) ;
if ( ! V_2 -> V_35 ) {
F_6 ( & V_10 -> V_19 , L_8 ) ;
V_18 = - V_23 ;
goto V_31;
}
V_17 = F_19 ( V_10 , 0 ) ;
if ( ! V_17 ) {
F_6 ( & V_10 -> V_19 , L_9 ) ;
V_18 = - V_36 ;
goto V_37;
}
if ( V_12 -> V_38 )
V_12 -> V_38 ( V_10 , V_39 ) ;
V_4 = F_2 ( V_2 ) ;
F_20 ( V_4 ) ;
V_18 = F_21 ( V_2 , V_17 , V_40 ) ;
if ( V_18 ) {
F_6 ( & V_10 -> V_19 , L_10 ) ;
goto V_37;
}
F_22 ( V_10 , V_14 ) ;
return 0 ;
V_37:
F_23 ( V_2 -> V_35 ) ;
V_31:
F_24 ( V_14 -> V_26 ) ;
V_28:
F_25 ( V_14 -> V_26 ) ;
V_27:
F_26 ( V_2 ) ;
V_25:
F_27 ( V_14 ) ;
return V_18 ;
}
static int T_2 F_28 ( struct V_9 * V_10 )
{
struct V_11 * V_12 = V_10 -> V_19 . V_20 ;
struct V_13 * V_14 = F_29 ( V_10 ) ;
struct V_1 * V_2 = V_14 -> V_2 ;
F_30 ( V_2 ) ;
if ( V_12 && V_12 -> V_41 )
V_12 -> V_41 ( V_10 , V_39 ) ;
F_23 ( V_2 -> V_35 ) ;
F_24 ( V_14 -> V_26 ) ;
F_25 ( V_14 -> V_26 ) ;
F_26 ( V_2 ) ;
F_27 ( V_14 ) ;
return 0 ;
}
static void F_31 ( struct V_9 * V_10 )
{
struct V_13 * V_14 = F_29 ( V_10 ) ;
struct V_1 * V_2 = V_14 -> V_2 ;
if ( V_2 -> V_42 -> V_43 )
V_2 -> V_42 -> V_43 ( V_2 ) ;
}
static int F_32 ( struct V_44 * V_19 )
{
struct V_13 * V_14 = F_33 ( V_19 ) ;
struct V_1 * V_2 = V_14 -> V_2 ;
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_9 * V_10 = F_34 ( V_19 ) ;
struct V_11 * V_12 = V_10 -> V_19 . V_20 ;
unsigned long V_45 ;
int V_46 = 0 ;
F_35 ( & V_4 -> V_47 , V_45 ) ;
if ( V_4 -> V_48 != V_49 &&
V_4 -> V_48 != V_50 ) {
V_46 = - V_21 ;
goto V_37;
}
F_36 ( V_51 , & V_2 -> V_45 ) ;
if ( V_12 && V_12 -> V_41 )
V_12 -> V_41 ( V_10 , V_39 ) ;
V_37:
F_37 ( & V_4 -> V_47 , V_45 ) ;
return V_46 ;
}
static int F_38 ( struct V_44 * V_19 )
{
struct V_13 * V_14 = F_33 ( V_19 ) ;
struct V_1 * V_2 = V_14 -> V_2 ;
struct V_9 * V_10 = F_34 ( V_19 ) ;
struct V_11 * V_12 = V_10 -> V_19 . V_20 ;
if ( V_12 && V_12 -> V_38 )
V_12 -> V_38 ( V_10 , V_39 ) ;
F_39 ( V_51 , & V_2 -> V_45 ) ;
F_40 ( V_2 ) ;
return 0 ;
}
