static int F_1 ( struct V_1 * V_2 )
{
const struct V_3 * V_4 = & V_5 ;
struct V_6 * V_7 ;
struct V_8 * V_9 = NULL ;
struct V_10 * V_11 ;
struct V_12 * V_13 ;
struct V_14 * V_15 ;
int V_16 , V_17 ;
V_17 = F_2 ( V_2 , 0 ) ;
if ( V_17 < 0 ) {
V_16 = V_17 ;
goto V_18;
}
V_16 = F_3 ( & V_2 -> V_19 , F_4 ( 32 ) ) ;
if ( V_16 )
goto V_18;
V_11 = F_5 ( & V_2 -> V_19 , NULL ) ;
if ( F_6 ( V_11 ) ) {
F_7 ( & V_2 -> V_19 , L_1 ) ;
V_16 = F_8 ( V_11 ) ;
goto V_18;
}
V_9 = F_9 ( V_4 , & V_2 -> V_19 , F_10 ( & V_2 -> V_19 ) ) ;
if ( ! V_9 ) {
V_16 = - V_20 ;
goto V_18;
}
V_15 = F_11 ( V_2 , V_21 , 0 ) ;
if ( ! V_15 ) {
V_16 = - V_22 ;
goto V_23;
}
V_9 -> V_24 = V_2 -> V_14 [ 0 ] . V_25 ;
V_9 -> V_26 = F_12 ( V_15 ) ;
V_9 -> V_27 = F_13 ( & V_2 -> V_19 , V_15 ) ;
if ( F_6 ( V_9 -> V_27 ) ) {
V_16 = F_8 ( V_9 -> V_27 ) ;
goto V_23;
}
V_13 = F_14 ( V_9 ) ;
V_13 -> V_10 = V_11 ;
F_15 ( V_13 -> V_10 ) ;
V_7 = F_16 ( V_9 ) ;
V_16 = F_17 ( V_9 , F_2 ( V_2 , 0 ) , 0 ) ;
if ( V_16 == 0 ) {
F_18 ( V_9 -> V_28 . V_29 ) ;
return V_16 ;
}
F_19 ( V_13 -> V_10 ) ;
V_23:
F_20 ( V_9 ) ;
V_18:
F_7 ( & V_2 -> V_19 , L_2 , V_16 ) ;
return V_16 ;
}
static int F_21 ( struct V_1 * V_2 )
{
struct V_8 * V_9 = F_22 ( V_2 ) ;
struct V_12 * V_13 = F_14 ( V_9 ) ;
F_23 ( V_9 ) ;
if ( V_13 -> V_10 )
F_19 ( V_13 -> V_10 ) ;
F_20 ( V_9 ) ;
return 0 ;
}
static int F_24 ( struct V_1 * V_2 ,
T_1 V_30 )
{
struct V_8 * V_9 = F_22 ( V_2 ) ;
struct V_6 * V_7 = F_16 ( V_9 ) ;
struct V_12 * V_13 = F_14 ( V_9 ) ;
bool V_31 = F_25 ( & V_2 -> V_19 ) ;
int V_32 ;
if ( F_26 ( V_33 , V_7 -> V_34 ) )
F_27 ( 5 ) ;
V_7 -> V_34 = V_33 ;
V_32 = F_28 ( V_9 , V_31 ) ;
if ( V_32 )
return V_32 ;
F_19 ( V_13 -> V_10 ) ;
return V_32 ;
}
static int F_29 ( struct V_1 * V_19 )
{
struct V_8 * V_9 = F_22 ( V_19 ) ;
struct V_6 * V_7 = F_16 ( V_9 ) ;
struct V_12 * V_13 = F_14 ( V_9 ) ;
if ( F_26 ( V_33 , V_7 -> V_34 ) )
F_27 ( 5 ) ;
V_7 -> V_34 = V_33 ;
F_15 ( V_13 -> V_10 ) ;
F_30 ( V_9 , false ) ;
return 0 ;
}
static int T_2 F_31 ( void )
{
if ( F_32 () )
return - V_22 ;
F_33 ( L_3 V_35 L_4 , V_36 ) ;
F_34 ( & V_5 , & V_37 ) ;
return F_35 ( & V_38 ) ;
}
static void T_3 F_36 ( void )
{
F_37 ( & V_38 ) ;
}
