static int F_1 ( struct V_1 * V_2 , const struct V_3 * V_4 )
{
struct V_5 * V_5 ;
struct V_6 * V_7 ;
int error ;
V_5 = F_2 ( sizeof( struct V_5 ) , V_8 ) ;
V_7 = F_3 () ;
if ( ! V_5 || ! V_7 ) {
F_4 ( V_9 L_1 ) ;
error = - V_10 ;
goto V_11;
}
error = F_5 ( V_2 ) ;
if ( error )
goto V_11;
V_5 -> V_12 = F_6 ( V_2 , 0 ) ;
V_5 -> V_13 = F_7 ( V_2 , 0 ) ;
V_5 -> V_14 = V_2 ;
V_5 -> V_6 = V_7 ;
F_8 ( V_7 , L_2 ) ;
F_9 ( V_7 , L_3 , F_10 ( V_2 ) ) ;
V_7 -> V_14 . V_15 = & V_2 -> V_14 ;
V_7 -> V_12 = V_5 -> V_12 ;
if ( ! F_11 ( V_5 -> V_12 , V_5 -> V_13 , L_4 ) ) {
F_4 ( V_9 L_5 ,
V_5 -> V_12 , V_5 -> V_12 + V_5 -> V_13 - 1 ) ;
error = - V_16 ;
goto V_17;
}
F_12 ( V_2 , V_5 ) ;
F_13 ( V_7 ) ;
return 0 ;
V_17:
F_14 ( V_2 ) ;
V_11:
F_15 ( V_7 ) ;
F_16 ( V_5 ) ;
return error ;
}
static void F_17 ( struct V_1 * V_2 )
{
struct V_5 * V_5 = F_18 ( V_2 ) ;
F_19 ( V_5 -> V_6 ) ;
F_20 ( V_5 -> V_12 , V_5 -> V_13 ) ;
F_16 ( V_5 ) ;
F_14 ( V_2 ) ;
}
