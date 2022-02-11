static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
int V_5 ;
V_4 -> V_6 = V_7 ;
V_2 -> V_8 = 1 ;
V_5 = F_3 ( V_2 ) ;
if ( V_5 )
return V_5 ;
F_4 ( V_9 , V_10 ) ;
F_4 ( 0 , V_11 ) ;
F_4 ( 0x8 , V_12 ) ;
F_4 ( 0x13 , V_13 ) ;
F_4 ( F_5 ( V_14 ) & ~ V_15 , V_14 ) ;
return 0 ;
}
static int F_6 ( struct V_16 * V_17 )
{
struct V_1 * V_2 ;
struct V_18 * V_19 ;
struct V_20 * V_21 ;
int V_22 ;
F_7 ( & V_17 -> V_23 , L_1 ) ;
V_2 = F_8 ( & V_24 , & V_17 -> V_23 , F_9 ( & V_17 -> V_23 ) ) ;
if ( ! V_2 ) {
F_10 ( & V_17 -> V_23 , L_2 ) ;
return - V_25 ;
}
V_22 = F_11 ( V_17 , 0 ) ;
if ( V_22 < 0 ) {
F_10 ( & V_17 -> V_23 , L_3 ) ;
goto V_26;
}
V_2 -> V_27 = V_22 ;
V_19 = F_12 ( V_17 , V_28 , 0 ) ;
if ( ! V_19 ) {
F_10 ( & V_17 -> V_23 , L_4 ) ;
V_22 = - V_29 ;
goto V_26;
}
V_2 -> V_30 = V_19 -> V_31 ;
V_2 -> V_32 = F_13 ( V_19 ) ;
V_2 -> V_33 = F_14 ( & V_17 -> V_23 , V_2 -> V_30 , V_2 -> V_32 ) ;
if ( ! V_2 -> V_33 ) {
F_10 ( & V_17 -> V_23 , L_5 ) ;
V_22 = - V_25 ;
goto V_26;
}
if ( V_17 -> V_23 . V_34 )
V_21 = F_15 ( & V_17 -> V_23 , L_6 , 0 ) ;
else
V_21 = F_16 ( & V_17 -> V_23 , V_35 ) ;
if ( F_17 ( V_21 ) ) {
if ( F_18 ( V_21 ) == - V_36 ) {
F_10 ( & V_17 -> V_23 , L_7 ) ;
V_22 = - V_36 ;
goto V_26;
}
V_21 = NULL ;
}
V_2 -> V_20 = V_21 ;
F_19 ( & V_17 -> V_23 , 1 ) ;
if ( V_21 && V_21 -> V_37 ) {
V_22 = F_20 ( V_21 -> V_37 , & V_2 -> V_38 ) ;
if ( V_22 < 0 ) {
F_10 ( & V_17 -> V_23 , L_8 ) ;
goto V_26;
}
F_21 ( & V_17 -> V_23 ) ;
F_22 ( & V_17 -> V_23 ) ;
} else {
V_22 = F_23 ( V_2 , V_2 -> V_27 , V_39 ) ;
if ( V_22 )
goto V_26;
}
return 0 ;
V_26:
F_24 ( V_2 ) ;
return V_22 ;
}
static int F_25 ( struct V_16 * V_17 )
{
struct V_1 * V_2 = F_26 ( V_17 ) ;
F_19 ( & V_17 -> V_23 , 0 ) ;
F_27 ( & V_17 -> V_23 ) ;
F_28 ( & V_17 -> V_23 ) ;
if ( V_2 -> V_20 && V_2 -> V_20 -> V_37 )
F_20 ( V_2 -> V_20 -> V_37 , NULL ) ;
else
F_29 ( V_2 ) ;
F_24 ( V_2 ) ;
return 0 ;
}
static int F_30 ( struct V_40 * V_23 )
{
struct V_1 * V_2 = F_31 ( V_23 ) ;
bool V_41 = F_32 ( V_23 ) ;
F_7 ( V_23 , L_9 ) ;
return F_33 ( V_2 , V_41 ) ;
}
static int F_34 ( struct V_40 * V_23 )
{
struct V_1 * V_2 = F_31 ( V_23 ) ;
F_7 ( V_23 , L_10 ) ;
F_35 ( V_2 , false ) ;
return 0 ;
}
static int T_1 F_36 ( void )
{
if ( F_37 () )
return - V_29 ;
F_38 ( L_11 V_42 L_12 , V_43 ) ;
F_39 ( & V_24 , & V_44 ) ;
return F_40 ( & V_45 ) ;
}
static void T_2 F_41 ( void )
{
F_42 ( & V_45 ) ;
}
