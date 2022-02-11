static void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = & V_2 -> V_4 ;
int V_5 ;
int V_6 ;
if ( ! V_4 -> V_7 )
return;
V_6 = F_2 ( V_4 -> V_7 , L_1 , 0 ) ;
if ( ! F_3 ( V_6 ) )
return;
V_5 = F_4 ( V_4 , V_6 , V_8 ,
L_2 ) ;
if ( V_5 )
F_5 ( V_4 , L_3 , V_6 ) ;
}
static int F_6 ( struct V_1 * V_2 )
{
struct V_9 * V_10 ;
struct V_11 * V_12 ;
struct V_13 * V_14 ;
struct V_15 * V_16 ;
struct V_17 * V_18 ;
int V_19 ;
int V_5 ;
V_5 = F_7 ( & V_2 -> V_4 , F_8 ( 32 ) ) ;
if ( V_5 )
return V_5 ;
F_1 ( V_2 ) ;
V_12 = F_9 ( & V_20 ,
& V_2 -> V_4 , F_10 ( & V_2 -> V_4 ) ) ;
if ( ! V_12 ) {
F_5 ( & V_2 -> V_4 , L_4 ) ;
return - V_21 ;
}
V_10 = F_11 ( V_12 ) ;
if ( F_12 ( V_2 -> V_4 . V_7 ,
L_5 ) )
goto V_22;
V_18 = F_13 ( & V_2 -> V_4 , V_23 ) ;
if ( F_14 ( V_18 ) ) {
F_15 ( V_12 ) ;
F_16 ( & V_2 -> V_4 , L_6 ) ;
return - V_24 ;
} else {
V_10 -> V_18 = V_18 ;
V_10 -> V_25 = V_18 -> V_25 ;
}
V_22:
V_10 -> V_26 = F_17 ( & V_2 -> V_4 , L_7 ) ;
if ( F_14 ( V_10 -> V_26 ) ) {
F_5 ( & V_2 -> V_4 , L_8 ) ;
V_5 = F_18 ( V_10 -> V_26 ) ;
goto V_27;
}
V_5 = F_19 ( V_10 -> V_26 ) ;
if ( V_5 )
goto V_27;
V_16 = F_20 ( V_2 , V_28 , 0 ) ;
if ( ! V_16 ) {
F_5 ( & V_2 -> V_4 , L_9 ) ;
V_5 = - V_29 ;
goto V_30;
}
V_12 -> V_31 = V_16 -> V_32 ;
V_12 -> V_33 = F_21 ( V_16 ) ;
V_12 -> V_34 = F_22 ( & V_2 -> V_4 , V_16 -> V_32 , V_12 -> V_33 ) ;
if ( ! V_12 -> V_34 ) {
F_5 ( & V_2 -> V_4 , L_10 ) ;
V_5 = - V_21 ;
goto V_30;
}
V_19 = F_23 ( V_2 , 0 ) ;
if ( ! V_19 ) {
F_5 ( & V_2 -> V_4 , L_11 ) ;
V_5 = - V_35 ;
goto V_30;
}
if ( V_10 -> V_25 )
V_10 -> V_25 -> V_36 ( V_10 -> V_25 , & V_12 -> V_37 ) ;
if ( V_10 -> V_18 )
F_24 ( V_10 -> V_18 ) ;
V_14 = F_25 ( V_12 ) ;
V_14 -> V_38 = V_12 -> V_34 ;
F_26 ( V_39 , F_27 ( V_12 -> V_34 ) ) ;
V_5 = F_28 ( V_12 , V_19 , V_40 ) ;
if ( V_5 ) {
F_5 ( & V_2 -> V_4 , L_12 ) ;
goto V_41;
}
F_29 ( V_2 , V_12 ) ;
return 0 ;
V_41:
if ( V_10 -> V_18 )
F_30 ( V_10 -> V_18 ) ;
V_30:
F_31 ( V_10 -> V_26 ) ;
V_27:
F_15 ( V_12 ) ;
return V_5 ;
}
static int F_32 ( struct V_1 * V_2 )
{
struct V_11 * V_12 = F_33 ( V_2 ) ;
struct V_9 * V_10 = F_11 ( V_12 ) ;
F_34 ( V_12 ) ;
if ( V_10 -> V_25 )
V_10 -> V_25 -> V_36 ( V_10 -> V_25 , & V_12 -> V_37 ) ;
if ( V_10 -> V_18 )
F_30 ( V_10 -> V_18 ) ;
F_31 ( V_10 -> V_26 ) ;
F_15 ( V_12 ) ;
return 0 ;
}
static int F_35 ( struct V_3 * V_4 )
{
struct V_11 * V_12 = F_36 ( V_4 ) ;
struct V_9 * V_10 = F_11 ( V_12 ) ;
bool V_42 = F_37 ( V_4 ) ;
int V_43 ;
V_43 = F_38 ( V_12 , V_42 ) ;
if ( V_10 -> V_25 )
V_10 -> V_25 -> V_36 ( V_10 -> V_25 , & V_12 -> V_37 ) ;
if ( V_10 -> V_18 )
F_30 ( V_10 -> V_18 ) ;
F_31 ( V_10 -> V_26 ) ;
return V_43 ;
}
static int F_39 ( struct V_3 * V_4 )
{
struct V_11 * V_12 = F_36 ( V_4 ) ;
struct V_9 * V_10 = F_11 ( V_12 ) ;
F_19 ( V_10 -> V_26 ) ;
if ( V_10 -> V_25 )
V_10 -> V_25 -> V_36 ( V_10 -> V_25 , & V_12 -> V_37 ) ;
if ( V_10 -> V_18 )
F_24 ( V_10 -> V_18 ) ;
F_26 ( V_39 , F_27 ( V_12 -> V_34 ) ) ;
F_40 ( V_12 , false ) ;
return 0 ;
}
static int T_1 F_41 ( void )
{
if ( F_42 () )
return - V_35 ;
F_43 ( L_13 V_44 L_14 , V_45 ) ;
F_44 ( & V_20 , & V_46 ) ;
return F_45 ( & V_47 ) ;
}
static void T_2 F_46 ( void )
{
F_47 ( & V_47 ) ;
}
