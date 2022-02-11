static inline T_1 F_1 ( void T_2 * V_1 , T_1 V_2 )
{
return F_2 ( V_1 + V_2 ) ;
}
static inline void F_3 ( void T_2 * V_1 , T_1 V_2 , T_1 V_3 )
{
F_4 ( V_3 , V_1 + V_2 ) ;
}
static void F_5 ( struct V_4 * V_5 )
{
T_1 V_6 ;
V_6 = F_1 ( V_5 -> V_7 , V_8 ) ;
V_6 |= V_9 ;
F_3 ( V_5 -> V_7 , V_8 , V_6 ) ;
}
static void F_6 ( struct V_4 * V_5 )
{
T_1 V_6 ;
V_6 = F_1 ( V_5 -> V_7 , V_8 ) ;
V_6 &= ~ V_9 ;
F_3 ( V_5 -> V_7 , V_8 , V_6 ) ;
}
static T_3 F_7 ( int V_10 , void * V_11 )
{
struct V_4 * V_5 = V_11 ;
F_3 ( V_5 -> V_7 , V_12 , V_13 ) ;
F_3 ( V_5 -> V_7 , V_14 , V_15 ) ;
F_3 ( V_5 -> V_7 , V_8 , V_9 ) ;
F_3 ( V_5 -> V_7 , V_16 , F_8 ( 0 ) ) ;
return V_17 ;
}
static int F_9 ( struct V_18 * V_19 )
{
struct V_20 * V_21 = & V_19 -> V_21 ;
struct V_22 * V_23 = V_19 -> V_21 . V_24 ;
struct V_4 * V_5 ;
struct V_25 * V_26 ;
int error , V_10 ;
V_5 = F_10 ( V_21 , sizeof( * V_5 ) , V_27 ) ;
if ( ! V_5 )
return - V_28 ;
F_11 ( V_19 , V_5 ) ;
V_5 -> V_21 = V_21 ;
V_26 = F_12 ( V_19 , V_29 , 0 ) ;
V_5 -> V_7 = F_13 ( V_21 , V_26 ) ;
if ( F_14 ( V_5 -> V_7 ) )
return F_15 ( V_5 -> V_7 ) ;
F_16 ( V_5 -> V_21 ) ;
error = F_17 ( V_5 -> V_21 ) ;
if ( error < 0 ) {
F_18 ( V_5 -> V_21 , L_1 ,
error ) ;
goto V_30;
}
V_10 = F_19 ( V_19 , 0 ) ;
if ( V_10 < 0 ) {
F_18 ( & V_19 -> V_21 , L_2 ) ;
error = V_10 ;
goto V_30;
}
error = F_20 ( V_21 , V_10 , F_7 , V_31 ,
F_21 ( V_21 ) , V_5 ) ;
if ( error ) {
F_18 ( V_21 , L_3 ,
V_10 , error ) ;
goto V_30;
}
F_5 ( V_5 ) ;
error = F_22 ( V_23 , NULL , NULL , V_21 ) ;
if ( error ) {
F_18 ( & V_19 -> V_21 , L_4 ) ;
goto V_32;
}
return 0 ;
V_32:
F_6 ( V_5 ) ;
V_30:
F_23 ( V_5 -> V_21 ) ;
F_24 ( V_5 -> V_21 ) ;
return error ;
}
static int F_25 ( struct V_20 * V_21 , void * V_33 )
{
struct V_18 * V_19 = F_26 ( V_21 ) ;
F_27 ( V_19 ) ;
return 0 ;
}
static int F_28 ( struct V_18 * V_19 )
{
struct V_4 * V_5 = F_29 ( V_19 ) ;
F_6 ( V_5 ) ;
F_30 ( & V_19 -> V_21 , NULL , F_25 ) ;
F_23 ( V_5 -> V_21 ) ;
F_24 ( V_5 -> V_21 ) ;
F_11 ( V_19 , NULL ) ;
return 0 ;
}
