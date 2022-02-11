static void F_1 ( struct V_1 * V_2 )
{
int V_3 ;
V_3 = F_2 ( V_2 -> V_4 , V_5 ) ;
if ( V_3 < 0 ) {
F_3 ( V_2 -> V_4 -> V_6 ,
L_1 , V_3 ) ;
} else {
bool V_7 = ! ( V_3 & V_8 ) ;
F_4 ( V_2 -> V_9 , V_10 , V_7 ) ;
F_5 ( V_2 -> V_9 ) ;
if ( V_7 )
F_6 ( & V_2 -> V_11 ,
F_7 ( 50 ) ) ;
}
}
static void F_8 ( struct V_12 * V_11 )
{
struct V_1 * V_2 = F_9 ( V_11 , struct V_1 ,
V_11 . V_11 ) ;
F_1 ( V_2 ) ;
}
static T_1 F_10 ( int V_13 , void * V_14 )
{
struct V_1 * V_2 = V_14 ;
F_1 ( V_2 ) ;
return V_15 ;
}
static int F_11 ( struct V_16 * V_17 )
{
struct V_4 * V_4 = F_12 ( V_17 -> V_6 . V_18 ) ;
struct V_1 * V_2 ;
struct V_19 * V_19 ;
int error ;
if ( ! V_4 ) {
F_3 ( & V_17 -> V_6 , L_2 ) ;
return - V_20 ;
}
V_2 = F_13 ( sizeof( * V_2 ) , V_21 ) ;
V_19 = F_14 () ;
if ( ! V_2 || ! V_19 ) {
F_3 ( & V_17 -> V_6 , L_3 ) ;
error = - V_22 ;
goto V_23;
}
V_2 -> V_9 = V_19 ;
V_2 -> V_4 = V_4 ;
F_15 ( & V_2 -> V_11 , F_8 ) ;
V_19 -> V_24 = L_4 ;
V_19 -> V_25 = L_5 ;
V_19 -> V_6 . V_18 = & V_17 -> V_6 ;
V_19 -> V_26 [ 0 ] = F_16 ( V_27 ) ;
F_17 ( V_10 , V_19 -> V_28 ) ;
error = F_18 ( V_2 -> V_4 , V_29 , L_6 ,
F_10 , V_2 ) ;
if ( error < 0 ) {
F_3 ( V_2 -> V_4 -> V_6 ,
L_7 , error ) ;
goto V_23;
}
error = F_19 ( V_2 -> V_9 ) ;
if ( error ) {
F_3 ( & V_17 -> V_6 , L_8 ,
error ) ;
goto V_30;
}
F_20 ( V_17 , V_2 ) ;
return 0 ;
V_30:
F_21 ( V_2 -> V_4 , V_29 , V_2 ) ;
F_22 ( & V_2 -> V_11 ) ;
V_23:
F_23 ( V_19 ) ;
F_24 ( V_2 ) ;
return error ;
}
static int F_25 ( struct V_16 * V_17 )
{
struct V_1 * V_2 = F_26 ( V_17 ) ;
F_21 ( V_2 -> V_4 , V_29 , V_2 ) ;
F_22 ( & V_2 -> V_11 ) ;
F_27 ( V_2 -> V_9 ) ;
F_24 ( V_2 ) ;
return 0 ;
}
