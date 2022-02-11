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
static int F_4 ( struct V_10 * V_11 )
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
V_4 = F_8 ( & V_11 -> V_13 , sizeof( struct V_3 ) ,
V_17 ) ;
if ( ! V_4 )
return - V_18 ;
V_16 = F_9 ( & V_11 -> V_13 ) ;
if ( ! V_16 )
return - V_18 ;
V_4 -> V_6 = V_16 ;
V_4 -> V_12 = V_12 ;
V_4 -> V_5 = V_5 ;
V_4 -> V_8 = V_8 ;
V_16 -> V_19 = L_5 ;
V_16 -> V_13 . V_14 = & V_11 -> V_13 ;
F_10 ( V_16 , V_20 , V_7 ) ;
error = F_11 ( & V_11 -> V_13 , V_4 -> V_5 ,
F_1 , 0 ,
L_6 , V_4 ) ;
if ( error < 0 ) {
F_7 ( V_12 -> V_13 , L_7 ,
V_4 -> V_5 , error ) ;
return error ;
}
error = F_11 ( & V_11 -> V_13 , V_4 -> V_8 ,
F_1 , 0 ,
L_8 , V_4 ) ;
if ( error < 0 ) {
F_7 ( V_12 -> V_13 , L_9 ,
V_4 -> V_8 , error ) ;
return error ;
}
error = F_12 ( V_4 -> V_6 ) ;
if ( error ) {
F_7 ( V_12 -> V_13 , L_10 , error ) ;
return error ;
}
return 0 ;
}
