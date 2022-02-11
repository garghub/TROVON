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
V_2 -> V_25 = F_12 ( & V_13 -> V_19 , V_15 ) ;
if ( F_13 ( V_2 -> V_25 ) ) {
V_18 = F_14 ( V_2 -> V_25 ) ;
goto V_23;
}
V_2 -> V_26 = V_15 -> V_27 ;
V_2 -> V_28 = F_15 ( V_15 ) ;
if ( V_13 -> V_19 . V_29 )
V_17 = F_16 ( & V_13 -> V_19 , L_4 , 0 ) ;
else
V_17 = F_17 ( & V_13 -> V_19 , V_30 ) ;
if ( F_13 ( V_17 ) ) {
F_9 ( & V_13 -> V_19 , L_5 ) ;
V_18 = - V_31 ;
goto V_23;
}
V_18 = F_18 ( V_17 -> V_32 , & V_2 -> V_33 ) ;
if ( V_18 < 0 ) {
F_9 ( & V_13 -> V_19 , L_6 ) ;
goto V_23;
}
V_2 -> V_16 = V_17 ;
F_19 ( & V_13 -> V_19 , 1 ) ;
F_20 ( & V_13 -> V_19 ) ;
F_21 ( & V_13 -> V_19 ) ;
return 0 ;
V_23:
F_22 ( V_2 ) ;
return V_18 ;
}
static int F_23 ( struct V_12 * V_13 )
{
struct V_1 * V_2 = F_24 ( V_13 ) ;
F_19 ( & V_13 -> V_19 , 0 ) ;
F_25 ( & V_13 -> V_19 ) ;
F_26 ( & V_13 -> V_19 ) ;
F_18 ( V_2 -> V_16 -> V_32 , NULL ) ;
F_22 ( V_2 ) ;
return 0 ;
}
static int F_27 ( struct V_34 * V_19 )
{
struct V_1 * V_2 = F_28 ( V_19 ) ;
bool V_35 = F_29 ( V_19 ) ;
F_6 ( V_19 , L_7 ) ;
return F_30 ( V_2 , V_35 ) ;
}
static int F_31 ( struct V_34 * V_19 )
{
struct V_1 * V_2 = F_28 ( V_19 ) ;
F_6 ( V_19 , L_8 ) ;
F_32 ( V_2 , false ) ;
return 0 ;
}
static int T_1 F_33 ( void )
{
if ( F_34 () )
return - V_36 ;
F_35 ( L_9 V_37 L_10 , V_38 ) ;
F_36 ( & V_20 , & V_39 ) ;
return F_37 ( & V_40 ) ;
}
static void T_2 F_38 ( void )
{
F_39 ( & V_40 ) ;
}
