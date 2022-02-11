static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
int V_5 ;
V_4 -> V_6 = V_7 ;
V_2 -> V_8 = 1 ;
V_5 = F_3 ( V_2 ) ;
if ( V_5 )
return V_5 ;
F_4 ( 0 , V_9 ) ;
F_4 ( 0 , V_10 ) ;
F_4 ( 0x13 , V_11 ) ;
return 0 ;
}
static int F_5 ( struct V_12 * V_13 )
{
struct V_1 * V_2 ;
struct V_14 * V_15 ;
struct V_16 * V_17 ;
int V_18 ;
F_6 ( & V_13 -> V_19 , L_1 ) ;
V_2 = F_7 ( & V_20 , & V_13 -> V_19 , F_8 ( & V_13 -> V_19 ) ) ;
if ( ! V_2 ) {
F_9 ( & V_13 -> V_19 , L_2 ) ;
return - V_21 ;
}
V_2 -> V_22 = F_10 ( V_13 , 0 ) ;
if ( V_2 -> V_22 < 0 ) {
F_9 ( & V_13 -> V_19 , L_3 ) ;
V_18 = V_2 -> V_22 ;
goto V_23;
}
V_15 = F_11 ( V_13 , V_24 , 0 ) ;
if ( ! V_15 ) {
F_9 ( & V_13 -> V_19 , L_4 ) ;
V_18 = - V_25 ;
goto V_23;
}
V_2 -> V_26 = V_15 -> V_27 ;
V_2 -> V_28 = F_12 ( V_15 ) ;
V_2 -> V_29 = F_13 ( & V_13 -> V_19 , V_2 -> V_26 , V_2 -> V_28 ) ;
if ( ! V_2 -> V_29 ) {
F_9 ( & V_13 -> V_19 , L_5 ) ;
V_18 = - V_21 ;
goto V_23;
}
if ( V_13 -> V_19 . V_30 )
V_17 = F_14 ( & V_13 -> V_19 , L_6 , 0 ) ;
else
V_17 = F_15 ( & V_13 -> V_19 , V_31 ) ;
if ( F_16 ( V_17 ) ) {
F_9 ( & V_13 -> V_19 , L_7 ) ;
V_18 = - V_32 ;
goto V_23;
}
V_18 = F_17 ( V_17 -> V_33 , & V_2 -> V_34 ) ;
if ( V_18 < 0 ) {
F_9 ( & V_13 -> V_19 , L_8 ) ;
goto V_23;
}
V_2 -> V_16 = V_17 ;
F_18 ( & V_13 -> V_19 , 1 ) ;
F_19 ( & V_13 -> V_19 ) ;
F_20 ( & V_13 -> V_19 ) ;
return 0 ;
V_23:
F_21 ( V_2 ) ;
return V_18 ;
}
static int F_22 ( struct V_12 * V_13 )
{
struct V_1 * V_2 = F_23 ( V_13 ) ;
F_18 ( & V_13 -> V_19 , 0 ) ;
F_24 ( & V_13 -> V_19 ) ;
F_25 ( & V_13 -> V_19 ) ;
F_17 ( V_2 -> V_16 -> V_33 , NULL ) ;
F_21 ( V_2 ) ;
return 0 ;
}
static int F_26 ( struct V_35 * V_19 )
{
struct V_1 * V_2 = F_27 ( V_19 ) ;
bool V_36 = F_28 ( V_19 ) ;
F_6 ( V_19 , L_9 ) ;
return F_29 ( V_2 , V_36 ) ;
}
static int F_30 ( struct V_35 * V_19 )
{
struct V_1 * V_2 = F_27 ( V_19 ) ;
F_6 ( V_19 , L_10 ) ;
F_31 ( V_2 , false ) ;
return 0 ;
}
static int T_1 F_32 ( void )
{
if ( F_33 () )
return - V_25 ;
F_34 ( L_11 V_37 L_12 , V_38 ) ;
F_35 ( & V_20 , & V_39 ) ;
return F_36 ( & V_40 ) ;
}
static void T_2 F_37 ( void )
{
F_38 ( & V_40 ) ;
}
