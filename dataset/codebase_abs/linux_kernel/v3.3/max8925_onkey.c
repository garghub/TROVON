static T_1 F_1 ( int V_1 , void * V_2 )
{
struct V_3 * V_4 = V_2 ;
int V_5 , V_6 ;
V_5 = F_2 ( V_4 -> V_7 , V_8 ) ;
if ( V_5 & V_9 )
V_6 = 1 ;
else
V_6 = 0 ;
F_3 ( V_4 -> V_10 , V_11 , V_6 ) ;
F_4 ( V_4 -> V_10 ) ;
F_5 ( V_4 -> V_12 , L_1 , V_6 ) ;
F_6 ( V_4 -> V_7 , V_13 ,
V_14 , V_14 ) ;
return V_15 ;
}
static int T_2 F_7 ( struct V_16 * V_17 )
{
struct V_18 * V_19 = F_8 ( V_17 -> V_12 . V_20 ) ;
struct V_3 * V_4 ;
int V_1 [ 2 ] , error ;
V_1 [ 0 ] = F_9 ( V_17 , 0 ) ;
if ( V_1 [ 0 ] < 0 ) {
F_10 ( & V_17 -> V_12 , L_2 ) ;
return - V_21 ;
}
V_1 [ 1 ] = F_9 ( V_17 , 1 ) ;
if ( V_1 [ 1 ] < 0 ) {
F_10 ( & V_17 -> V_12 , L_2 ) ;
return - V_21 ;
}
V_4 = F_11 ( sizeof( struct V_3 ) , V_22 ) ;
if ( ! V_4 )
return - V_23 ;
V_4 -> V_7 = V_19 -> V_7 ;
V_4 -> V_12 = & V_17 -> V_12 ;
V_1 [ 0 ] += V_19 -> V_24 ;
V_1 [ 1 ] += V_19 -> V_24 ;
error = F_12 ( V_1 [ 0 ] , NULL , F_1 ,
V_25 , L_3 , V_4 ) ;
if ( error < 0 ) {
F_10 ( V_19 -> V_12 , L_4 ,
V_1 [ 0 ] , error ) ;
goto V_26;
}
error = F_12 ( V_1 [ 1 ] , NULL , F_1 ,
V_25 , L_5 , V_4 ) ;
if ( error < 0 ) {
F_10 ( V_19 -> V_12 , L_4 ,
V_1 [ 1 ] , error ) ;
goto V_27;
}
V_4 -> V_10 = F_13 () ;
if ( ! V_4 -> V_10 ) {
F_10 ( V_19 -> V_12 , L_6 ) ;
error = - V_23 ;
goto V_28;
}
V_4 -> V_10 -> V_29 = L_7 ;
V_4 -> V_10 -> V_30 = L_8 ;
V_4 -> V_10 -> V_31 . V_32 = V_33 ;
V_4 -> V_10 -> V_12 . V_20 = & V_17 -> V_12 ;
V_4 -> V_1 [ 0 ] = V_1 [ 0 ] ;
V_4 -> V_1 [ 1 ] = V_1 [ 1 ] ;
V_4 -> V_10 -> V_34 [ 0 ] = F_14 ( V_35 ) ;
V_4 -> V_10 -> V_36 [ F_15 ( V_11 ) ] = F_14 ( V_11 ) ;
error = F_16 ( V_4 -> V_10 ) ;
if ( error ) {
F_10 ( V_19 -> V_12 , L_9 , error ) ;
goto V_37;
}
F_17 ( V_17 , V_4 ) ;
return 0 ;
V_37:
F_18 ( V_4 -> V_10 ) ;
V_28:
F_19 ( V_4 -> V_1 [ 1 ] , V_4 ) ;
V_27:
F_19 ( V_4 -> V_1 [ 0 ] , V_4 ) ;
V_26:
F_20 ( V_4 ) ;
return error ;
}
static int T_3 F_21 ( struct V_16 * V_17 )
{
struct V_3 * V_4 = F_22 ( V_17 ) ;
F_19 ( V_4 -> V_1 [ 0 ] , V_4 ) ;
F_19 ( V_4 -> V_1 [ 1 ] , V_4 ) ;
F_23 ( V_4 -> V_10 ) ;
F_20 ( V_4 ) ;
F_17 ( V_17 , NULL ) ;
return 0 ;
}
