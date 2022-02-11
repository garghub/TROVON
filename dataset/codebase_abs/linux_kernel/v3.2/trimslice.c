static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
struct V_8 * V_9 = V_6 -> V_9 ;
struct V_8 * V_10 = V_6 -> V_10 ;
struct V_11 * V_12 = V_6 -> V_12 ;
struct V_13 * V_14 = V_12 -> V_14 ;
struct V_15 * V_16 = F_2 ( V_14 ) ;
int V_17 , V_18 ;
int V_19 ;
V_17 = F_3 ( V_4 ) ;
V_18 = 128 * V_17 ;
V_19 = F_4 ( & V_16 -> V_20 , V_17 , V_18 ) ;
if ( V_19 < 0 ) {
F_5 ( V_14 -> V_21 , L_1 ) ;
return V_19 ;
}
V_19 = F_6 ( V_9 ,
V_22 |
V_23 |
V_24 ) ;
if ( V_19 < 0 ) {
F_5 ( V_14 -> V_21 , L_2 ) ;
return V_19 ;
}
V_19 = F_6 ( V_10 ,
V_22 |
V_23 |
V_24 ) ;
if ( V_19 < 0 ) {
F_5 ( V_14 -> V_21 , L_3 ) ;
return V_19 ;
}
V_19 = F_7 ( V_9 , 0 , V_18 ,
V_25 ) ;
if ( V_19 < 0 ) {
F_5 ( V_14 -> V_21 , L_4 ) ;
return V_19 ;
}
return 0 ;
}
static int F_8 ( struct V_5 * V_6 )
{
struct V_11 * V_12 = V_6 -> V_12 ;
struct V_26 * V_27 = & V_12 -> V_27 ;
F_9 ( V_27 , L_5 ) ;
F_9 ( V_27 , L_6 ) ;
F_9 ( V_27 , L_7 ) ;
return 0 ;
}
static T_1 int F_10 ( struct V_28 * V_29 )
{
struct V_13 * V_14 = & V_30 ;
struct V_15 * V_16 ;
int V_31 ;
V_16 = F_11 ( sizeof( struct V_15 ) , V_32 ) ;
if ( ! V_16 ) {
F_5 ( & V_29 -> V_21 , L_8 ) ;
return - V_33 ;
}
V_31 = F_12 ( & V_16 -> V_20 , & V_29 -> V_21 ) ;
if ( V_31 )
goto V_34;
V_14 -> V_21 = & V_29 -> V_21 ;
F_13 ( V_29 , V_14 ) ;
F_14 ( V_14 , V_16 ) ;
V_31 = F_15 ( V_14 ) ;
if ( V_31 ) {
F_5 ( & V_29 -> V_21 , L_9 ,
V_31 ) ;
goto V_35;
}
return 0 ;
V_35:
F_16 ( & V_16 -> V_20 ) ;
V_34:
F_17 ( V_16 ) ;
return V_31 ;
}
static int T_2 F_18 ( struct V_28 * V_29 )
{
struct V_13 * V_14 = F_19 ( V_29 ) ;
struct V_15 * V_16 = F_2 ( V_14 ) ;
F_20 ( V_14 ) ;
F_16 ( & V_16 -> V_20 ) ;
F_17 ( V_16 ) ;
return 0 ;
}
static int T_3 F_21 ( void )
{
return F_22 ( & V_36 ) ;
}
static void T_4 F_23 ( void )
{
F_24 ( & V_36 ) ;
}
