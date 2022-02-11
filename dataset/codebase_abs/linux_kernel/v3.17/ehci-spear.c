static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
bool V_5 = F_3 ( V_2 ) ;
return F_4 ( V_4 , V_5 ) ;
}
static int F_5 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
F_6 ( V_4 , false ) ;
return 0 ;
}
static int F_7 ( struct V_6 * V_7 )
{
struct V_3 * V_4 ;
struct V_8 * V_9 ;
struct V_10 * V_11 ;
struct V_12 * V_13 ;
const struct V_14 * V_15 = & V_16 ;
int V_17 , V_18 ;
if ( F_8 () )
return - V_19 ;
V_17 = F_9 ( V_7 , 0 ) ;
if ( V_17 < 0 ) {
V_18 = V_17 ;
goto V_20;
}
V_18 = F_10 ( & V_7 -> V_2 , F_11 ( 32 ) ) ;
if ( V_18 )
goto V_20;
V_13 = F_12 ( & V_7 -> V_2 , NULL ) ;
if ( F_13 ( V_13 ) ) {
F_14 ( & V_7 -> V_2 , L_1 ) ;
V_18 = F_15 ( V_13 ) ;
goto V_20;
}
V_4 = F_16 ( V_15 , & V_7 -> V_2 , F_17 ( & V_7 -> V_2 ) ) ;
if ( ! V_4 ) {
V_18 = - V_21 ;
goto V_20;
}
V_11 = F_18 ( V_7 , V_22 , 0 ) ;
if ( ! V_11 ) {
V_18 = - V_19 ;
goto V_23;
}
V_4 -> V_24 = V_11 -> V_25 ;
V_4 -> V_26 = F_19 ( V_11 ) ;
V_4 -> V_27 = F_20 ( & V_7 -> V_2 , V_11 ) ;
if ( F_13 ( V_4 -> V_27 ) ) {
V_18 = F_15 ( V_4 -> V_27 ) ;
goto V_23;
}
V_9 = F_21 ( V_4 ) ;
V_9 -> V_12 = V_13 ;
F_22 ( V_4 ) -> V_28 = V_4 -> V_27 ;
F_23 ( V_9 -> V_12 ) ;
V_18 = F_24 ( V_4 , V_17 , V_29 ) ;
if ( V_18 )
goto V_30;
F_25 ( V_4 -> V_31 . V_32 ) ;
return V_18 ;
V_30:
F_26 ( V_9 -> V_12 ) ;
V_23:
F_27 ( V_4 ) ;
V_20:
F_14 ( & V_7 -> V_2 , L_2 , V_18 ) ;
return V_18 ;
}
static int F_28 ( struct V_6 * V_7 )
{
struct V_3 * V_4 = F_29 ( V_7 ) ;
struct V_8 * V_9 = F_21 ( V_4 ) ;
F_30 ( V_4 ) ;
if ( V_9 -> V_12 )
F_26 ( V_9 -> V_12 ) ;
F_27 ( V_4 ) ;
return 0 ;
}
static int T_1 F_31 ( void )
{
if ( F_8 () )
return - V_19 ;
F_32 ( L_3 V_33 L_4 , V_34 ) ;
F_33 ( & V_16 , & V_35 ) ;
return F_34 ( & V_36 ) ;
}
static void T_2 F_35 ( void )
{
F_36 ( & V_36 ) ;
}
