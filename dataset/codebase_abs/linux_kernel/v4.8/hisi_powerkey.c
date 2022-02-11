static T_1 F_1 ( int V_1 , void * V_2 )
{
struct V_3 * V_4 = V_2 ;
F_2 ( V_4 -> V_5 . V_6 , V_7 ) ;
F_3 ( V_4 , V_8 , 1 ) ;
F_4 ( V_4 ) ;
return V_9 ;
}
static T_1 F_5 ( int V_1 , void * V_2 )
{
struct V_3 * V_4 = V_2 ;
F_2 ( V_4 -> V_5 . V_6 , V_7 ) ;
F_3 ( V_4 , V_8 , 0 ) ;
F_4 ( V_4 ) ;
return V_9 ;
}
static T_1 F_6 ( int V_1 , void * V_2 )
{
struct V_3 * V_4 = V_2 ;
int V_10 = F_7 ( V_11 , V_4 -> V_12 ) ;
F_2 ( V_4 -> V_5 . V_6 , V_7 ) ;
F_3 ( V_4 , V_11 , ! V_10 ) ;
F_4 ( V_4 ) ;
return V_9 ;
}
static int F_8 ( struct V_13 * V_14 )
{
struct V_15 * V_5 = & V_14 -> V_5 ;
struct V_3 * V_4 ;
int V_1 , V_16 , error ;
V_4 = F_9 ( & V_14 -> V_5 ) ;
if ( ! V_4 ) {
F_10 ( & V_14 -> V_5 , L_1 ) ;
return - V_17 ;
}
V_4 -> V_18 = L_2 ;
V_4 -> V_19 = L_3 ;
F_11 ( V_4 , V_20 , V_8 ) ;
F_11 ( V_4 , V_20 , V_11 ) ;
for ( V_16 = 0 ; V_16 < F_12 ( V_21 ) ; V_16 ++ ) {
V_1 = F_13 ( V_14 , V_21 [ V_16 ] . V_19 ) ;
if ( V_1 < 0 ) {
error = V_1 ;
F_10 ( V_5 , L_4 ,
V_21 [ V_16 ] . V_19 , error ) ;
return error ;
}
error = F_14 ( V_5 , V_1 ,
V_21 [ V_16 ] . V_22 ,
V_23 ,
V_21 [ V_16 ] . V_19 ,
V_4 ) ;
if ( error < 0 ) {
F_10 ( V_5 , L_5 ,
V_21 [ V_16 ] . V_19 , error ) ;
return error ;
}
}
error = F_15 ( V_4 ) ;
if ( error ) {
F_10 ( & V_14 -> V_5 , L_6 ,
error ) ;
return error ;
}
F_16 ( & V_14 -> V_5 , 1 ) ;
return 0 ;
}
static int F_17 ( struct V_13 * V_14 )
{
F_16 ( & V_14 -> V_5 , 0 ) ;
return 0 ;
}
