static T_1 F_1 ( int V_1 , void * V_2 )
{
struct V_3 * V_4 = V_2 ;
if ( V_1 == V_4 -> V_5 )
F_2 ( V_4 -> V_6 , V_7 , true ) ;
else if ( V_1 == V_4 -> V_8 )
F_2 ( V_4 -> V_6 , V_7 , false ) ;
F_3 ( V_4 -> V_6 ) ;
return V_9 ;
}
static int T_2 F_4 ( struct V_10 * V_11 )
{
struct V_12 * V_12 = F_5 ( V_11 -> V_13 . V_14 ) ;
struct V_3 * V_4 ;
struct V_15 * V_16 ;
int V_5 , V_8 ;
int error ;
V_5 = F_6 ( V_11 , L_1 ) ;
if ( V_5 < 0 ) {
F_7 ( & V_11 -> V_13 , L_2 , V_5 ) ;
return V_5 ;
}
V_8 = F_6 ( V_11 , L_3 ) ;
if ( V_8 < 0 ) {
F_7 ( & V_11 -> V_13 , L_4 , V_8 ) ;
return V_8 ;
}
V_4 = F_8 ( sizeof( struct V_3 ) , V_17 ) ;
V_16 = F_9 () ;
if ( ! V_4 || ! V_16 ) {
error = - V_18 ;
goto V_19;
}
V_4 -> V_6 = V_16 ;
V_4 -> V_12 = V_12 ;
V_4 -> V_5 = V_5 ;
V_4 -> V_8 = V_8 ;
V_16 -> V_20 = L_5 ;
V_16 -> V_13 . V_14 = & V_11 -> V_13 ;
F_10 ( V_16 , V_21 , V_7 ) ;
error = F_11 ( V_4 -> V_5 , F_1 ,
0 , L_6 , V_4 ) ;
if ( error < 0 ) {
F_7 ( V_12 -> V_13 , L_7 ,
V_4 -> V_5 , error ) ;
goto V_19;
}
error = F_11 ( V_4 -> V_8 , F_1 ,
0 , L_8 , V_4 ) ;
if ( error < 0 ) {
F_7 ( V_12 -> V_13 , L_9 ,
V_4 -> V_8 , error ) ;
goto V_22;
}
error = F_12 ( V_4 -> V_6 ) ;
if ( error ) {
F_7 ( V_12 -> V_13 , L_10 , error ) ;
goto V_23;
}
F_13 ( V_11 , V_4 ) ;
return 0 ;
V_23:
F_14 ( V_4 -> V_8 , V_4 ) ;
V_22:
F_14 ( V_4 -> V_5 , V_4 ) ;
V_19:
F_15 ( V_16 ) ;
F_16 ( V_4 ) ;
return error ;
}
static int T_3 F_17 ( struct V_10 * V_11 )
{
struct V_3 * V_4 = F_18 ( V_11 ) ;
F_14 ( V_4 -> V_5 , V_4 ) ;
F_14 ( V_4 -> V_8 , V_4 ) ;
F_19 ( V_4 -> V_6 ) ;
F_16 ( V_4 ) ;
F_13 ( V_11 , NULL ) ;
return 0 ;
}
