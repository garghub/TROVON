static T_1 F_1 ( int V_1 , void * V_2 )
{
struct V_3 * V_4 = V_2 ;
F_2 ( V_4 , V_5 , 0 ) ;
F_3 ( V_4 ) ;
return V_6 ;
}
static T_1 F_4 ( int V_1 , void * V_2 )
{
struct V_3 * V_4 = V_2 ;
F_2 ( V_4 , V_5 , 1 ) ;
F_5 ( V_4 -> V_7 . V_8 , 0 ) ;
F_3 ( V_4 ) ;
return V_6 ;
}
static int T_2 F_6 ( struct V_9 * V_7 )
{
struct V_10 * V_11 = F_7 ( V_7 ) ;
if ( F_8 ( V_7 ) )
F_9 ( F_10 ( V_11 , L_1 ) ) ;
return 0 ;
}
static int T_2 F_11 ( struct V_9 * V_7 )
{
struct V_10 * V_11 = F_7 ( V_7 ) ;
if ( F_8 ( V_7 ) )
F_12 ( F_10 ( V_11 , L_1 ) ) ;
return 0 ;
}
static int F_13 ( struct V_10 * V_11 )
{
struct V_3 * V_12 ;
int V_13 , V_14 ;
int error ;
V_13 = F_10 ( V_11 , L_1 ) ;
if ( V_13 < 0 ) {
F_14 ( & V_11 -> V_7 , L_2 ,
V_13 ) ;
return V_13 ;
}
V_14 = F_10 ( V_11 , L_3 ) ;
if ( V_14 < 0 ) {
F_14 ( & V_11 -> V_7 , L_4 ,
V_14 ) ;
return V_14 ;
}
V_12 = F_15 ( & V_11 -> V_7 ) ;
if ( ! V_12 )
return - V_15 ;
V_12 -> V_16 = L_5 ;
V_12 -> V_17 = L_6 ;
V_12 -> V_7 . V_8 = & V_11 -> V_7 ;
F_16 ( V_12 , V_18 , V_5 ) ;
error = F_17 ( & V_11 -> V_7 , V_13 ,
F_4 , 0 ,
L_7 , V_12 ) ;
if ( error ) {
F_14 ( & V_11 -> V_7 , L_8 ,
V_13 , error ) ;
return error ;
}
error = F_17 ( & V_11 -> V_7 , V_14 ,
F_1 , 0 ,
L_7 , V_12 ) ;
if ( error ) {
F_14 ( & V_11 -> V_7 , L_9 ,
V_14 , error ) ;
return error ;
}
error = F_18 ( V_12 ) ;
if ( error ) {
F_14 ( & V_11 -> V_7 , L_10 , error ) ;
return error ;
}
F_19 ( V_11 , V_12 ) ;
F_20 ( & V_11 -> V_7 , 1 ) ;
return 0 ;
}
static int F_21 ( struct V_10 * V_11 )
{
F_20 ( & V_11 -> V_7 , 0 ) ;
return 0 ;
}
