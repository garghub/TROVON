static T_1 F_1 ( int V_1 , void * V_2 )
{
struct V_3 * V_3 = V_2 ;
struct V_4 * V_5 = V_3 -> V_5 ;
unsigned char V_6 ;
V_6 = F_2 ( V_3 -> V_7 ) ;
F_3 ( V_5 , V_6 & 0x7f , V_6 & 0x80 ? 0 : 1 ) ;
F_4 ( V_5 ) ;
return V_8 ;
}
static int F_5 ( struct V_9 * V_10 )
{
struct V_4 * V_5 ;
struct V_3 * V_3 ;
struct V_11 * V_12 ;
int V_1 , V_13 , error ;
V_12 = F_6 ( V_10 , V_14 , 0 ) ;
if ( ! V_12 ) {
F_7 ( & V_10 -> V_15 , L_1 ) ;
return - V_16 ;
}
V_1 = F_8 ( V_10 , 0 ) ;
if ( V_1 < 0 ) {
F_7 ( & V_10 -> V_15 , L_2 ) ;
return - V_16 ;
}
V_3 = F_9 ( & V_10 -> V_15 , sizeof( * V_3 ) ,
V_17 ) ;
if ( ! V_3 )
return - V_18 ;
V_5 = F_10 ( & V_10 -> V_15 ) ;
if ( ! V_5 ) {
F_7 ( & V_10 -> V_15 , L_3 ) ;
return - V_18 ;
}
V_3 -> V_5 = V_5 ;
V_3 -> V_7 = F_11 ( & V_10 -> V_15 , V_12 ) ;
if ( F_12 ( V_3 -> V_7 ) )
return F_13 ( V_3 -> V_7 ) ;
V_5 -> V_19 = V_10 -> V_19 ;
V_5 -> V_20 = L_4 ;
V_5 -> V_21 . V_22 = V_23 ;
V_5 -> V_21 . V_24 = 0x0001 ;
V_5 -> V_21 . V_25 = 0x0001 ;
V_5 -> V_21 . V_26 = 0x0100 ;
V_5 -> V_27 = V_3 -> V_28 ;
V_5 -> V_29 = sizeof( V_3 -> V_28 [ 0 ] ) ;
V_5 -> V_30 = F_14 ( V_3 -> V_28 ) ;
F_15 ( V_31 , V_5 -> V_32 ) ;
for ( V_13 = 0 ; V_13 < F_14 ( V_3 -> V_28 ) ; V_13 ++ ) {
V_3 -> V_28 [ V_13 ] = V_13 ;
F_15 ( V_3 -> V_28 [ V_13 ] , V_5 -> V_33 ) ;
}
F_16 ( V_34 , V_5 -> V_33 ) ;
error = F_17 ( & V_10 -> V_15 , V_1 , & F_1 ,
V_35 ,
V_10 -> V_19 , V_3 ) ;
if ( error ) {
F_7 ( & V_10 -> V_15 , L_5 , V_1 ) ;
return error ;
}
error = F_18 ( V_5 ) ;
if ( error ) {
F_7 ( & V_10 -> V_15 , L_6 ) ;
return error ;
}
return 0 ;
}
