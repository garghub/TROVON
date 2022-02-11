static void F_1 ( struct V_1 * V_2 )
{
int V_3 ;
V_3 = F_2 ( V_2 -> V_4 , V_5 ) ;
if ( V_3 < 0 ) {
F_3 ( V_2 -> V_4 -> V_6 ,
L_1 , V_3 ) ;
} else {
V_3 &= V_7 ;
F_4 ( V_2 -> V_8 , V_9 , V_3 ) ;
F_5 ( V_2 -> V_8 ) ;
}
if ( V_3 )
F_6 ( & V_2 -> V_10 , F_7 ( 50 ) ) ;
}
static void F_8 ( struct V_11 * V_10 )
{
struct V_1 * V_2 = F_9 ( V_10 , struct V_1 ,
V_10 . V_10 ) ;
F_1 ( V_2 ) ;
}
static T_1 F_10 ( int V_12 , void * V_13 )
{
struct V_1 * V_2 = V_13 ;
F_1 ( V_2 ) ;
return V_14 ;
}
static int T_2 F_11 ( struct V_15 * V_16 )
{
struct V_4 * V_4 = F_12 ( V_16 -> V_6 . V_17 ) ;
struct V_1 * V_2 ;
struct V_18 * V_18 ;
int V_12 ;
int error ;
if ( ! V_4 ) {
F_3 ( & V_16 -> V_6 , L_2 ) ;
return - V_19 ;
}
V_12 = F_13 ( V_16 , L_3 ) ;
if ( V_12 < 0 ) {
F_3 ( & V_16 -> V_6 ,
L_4 , V_12 ) ;
return - V_19 ;
}
V_2 = F_14 ( sizeof( * V_2 ) , V_20 ) ;
V_18 = F_15 () ;
if ( ! V_2 || ! V_18 ) {
F_3 ( & V_16 -> V_6 , L_5 ) ;
error = - V_21 ;
goto V_22;
}
V_2 -> V_8 = V_18 ;
V_2 -> V_4 = V_4 ;
V_2 -> V_12 = V_12 ;
F_16 ( & V_2 -> V_10 , F_8 ) ;
V_18 -> V_23 = L_6 ;
V_18 -> V_24 = L_7 ;
V_18 -> V_6 . V_17 = & V_16 -> V_6 ;
V_18 -> V_25 [ 0 ] = F_17 ( V_26 ) ;
F_18 ( V_9 , V_18 -> V_27 ) ;
error = F_19 ( V_2 -> V_12 , NULL , F_10 ,
V_28 | V_29 ,
L_3 , V_2 ) ;
if ( error < 0 ) {
F_3 ( V_2 -> V_4 -> V_6 ,
L_8 ,
V_2 -> V_12 , error ) ;
goto V_22;
}
error = F_20 ( V_2 -> V_8 ) ;
if ( error ) {
F_3 ( & V_16 -> V_6 , L_9 ,
error ) ;
goto V_30;
}
F_21 ( V_16 , V_2 ) ;
return 0 ;
V_30:
F_22 ( V_2 -> V_12 , V_2 ) ;
F_23 ( & V_2 -> V_10 ) ;
V_22:
F_24 ( V_18 ) ;
F_25 ( V_2 ) ;
return error ;
}
static int T_3 F_26 ( struct V_15 * V_16 )
{
struct V_1 * V_2 = F_27 ( V_16 ) ;
F_22 ( V_2 -> V_12 , V_2 ) ;
F_23 ( & V_2 -> V_10 ) ;
F_28 ( V_2 -> V_8 ) ;
F_25 ( V_2 ) ;
return 0 ;
}
