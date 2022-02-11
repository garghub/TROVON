static void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
V_4 = F_2 ( V_2 ) ;
F_3 ( & V_3 -> V_5 ) ;
if ( F_4 ( V_4 -> V_6 ) )
return;
F_5 ( V_4 ) ;
F_6 ( F_7 ( V_7 ) , & V_4 -> V_8 -> V_9 ) ;
F_8 ( V_2 -> V_10 , V_4 ) ;
F_9 ( V_4 -> V_11 ) ;
F_10 ( F_11 ( V_2 , 0 ) ,
F_12 ( V_2 , 0 ) ) ;
F_13 ( V_2 ) ;
F_14 ( V_4 ) ;
}
static int F_15 (
struct V_1 * V_2 ,
const struct V_12 * V_13
)
{
struct V_3 * V_4 ;
unsigned long V_14 ;
unsigned long V_15 ;
int V_16 = 0 ;
if ( V_3 ) {
F_16 ( & V_2 -> V_4 , L_1 ) ;
return - V_17 ;
}
V_4 = F_17 ( sizeof( struct V_3 ) , V_18 ) ;
if ( ! V_4 )
return - V_19 ;
if ( F_18 ( V_2 ) < 0 ) {
V_16 = - V_20 ;
goto V_21;
}
V_14 = F_11 ( V_2 , 0 ) ;
V_15 = F_12 ( V_2 , 0 ) ;
if ( ! F_19 ( V_14 , V_15 , V_22 ) ) {
F_16 ( & V_2 -> V_4 , L_2 ) ;
V_16 = - V_17 ;
goto V_23;
}
V_4 -> V_11 = F_20 ( V_14 , V_15 ) ;
if ( ! V_4 -> V_11 ) {
F_16 ( & V_2 -> V_4 , L_3 ) ;
V_16 = - V_24 ;
goto V_25;
}
if ( ! V_2 -> V_10 ) {
F_21 ( & V_2 -> V_4 , L_4 ) ;
V_16 = - V_20 ;
goto V_26;
}
F_22 ( & V_4 -> V_27 ) ;
V_4 -> V_28 = V_4 -> V_11 + V_29 ;
V_4 -> V_8 = V_4 -> V_11 + V_30 ;
V_4 -> V_31 = V_4 -> V_11 + V_32 ;
V_4 -> V_33 = ( V_34 V_35 * ) ( V_4 -> V_11 + V_36 ) ;
V_4 -> V_37 = ( V_34 V_35 * ) ( V_4 -> V_11 + V_38 ) ;
if ( F_23 ( V_2 -> V_10 , V_39 , V_40 , V_22 , V_4 ) != 0 ) {
F_16 ( & V_2 -> V_4 , L_5 , V_2 -> V_10 ) ;
V_16 = - V_17 ;
goto V_26;
}
F_24 ( V_2 , V_4 ) ;
V_4 -> V_41 = V_2 -> V_42 ;
F_25 ( V_2 ) ;
F_26 ( V_2 ) ;
if ( V_43 ) {
V_16 = F_27 ( V_4 ) ;
if ( V_16 != 0 )
goto V_44;
}
V_4 -> V_45 = V_14 ;
V_4 -> V_10 = V_2 -> V_10 ;
V_4 -> V_2 = V_2 ;
if ( F_28 ( V_4 ) ) {
V_16 = - V_20 ;
goto V_46;
}
return 0 ;
V_46:
if ( V_43 )
F_5 ( V_4 ) ;
V_44:
F_8 ( V_2 -> V_10 , V_4 ) ;
V_26:
F_9 ( V_4 -> V_11 ) ;
V_25:
F_10 ( V_14 , V_15 ) ;
V_23:
F_13 ( V_2 ) ;
V_21:
F_29 ( V_4 ) ;
return V_16 ;
}
