static T_1 F_1 ( int V_1 , void * V_2 )
{
struct V_3 * V_4 = V_2 ;
T_2 V_5 ;
V_5 = F_2 ( V_4 -> V_6 +
V_7 ) ;
F_3 ( V_5 & ~ V_8 ,
V_4 -> V_6 + V_7 ) ;
F_4 ( V_4 -> V_9 , V_10 , V_11 , 1 ) ;
F_5 ( V_4 -> V_9 ) ;
return V_12 ;
}
static int F_6 ( struct V_13 * V_14 )
{
struct V_15 * V_16 = V_14 -> V_17 . V_18 ;
struct V_3 * V_4 ;
int V_1 ;
int error ;
V_4 = F_7 ( & V_14 -> V_17 , sizeof( struct V_3 ) ,
V_19 ) ;
if ( ! V_4 ) {
F_8 ( & V_14 -> V_17 , L_1 ) ;
return - V_20 ;
}
error = F_9 ( V_16 , L_2 , & V_4 -> V_6 ) ;
if ( error ) {
F_10 ( & V_14 -> V_17 ,
L_3 ) ;
return error ;
}
V_4 -> V_9 = F_11 ( & V_14 -> V_17 ) ;
if ( ! V_4 -> V_9 )
return - V_20 ;
V_4 -> V_9 -> V_21 = L_4 ;
V_4 -> V_9 -> V_22 = L_5 ;
V_4 -> V_9 -> V_23 [ 0 ] = F_12 ( V_10 ) ;
V_1 = F_13 ( V_14 , 0 ) ;
error = F_14 ( & V_14 -> V_17 , V_1 ,
F_1 , V_24 ,
L_6 , V_4 ) ;
if ( error ) {
F_10 ( & V_14 -> V_17 , L_7 ,
V_1 , error ) ;
return error ;
}
F_3 (
F_2 ( V_4 -> V_6 + V_25 ) |
V_8 ,
V_4 -> V_6 + V_25 ) ;
error = F_15 ( V_4 -> V_9 ) ;
if ( error ) {
F_10 ( & V_14 -> V_17 ,
L_8 ,
error ) ;
return error ;
}
F_16 ( V_14 , V_4 ) ;
F_17 ( & V_14 -> V_17 , 1 ) ;
return 0 ;
}
static int F_18 ( struct V_13 * V_14 )
{
F_17 ( & V_14 -> V_17 , 0 ) ;
return 0 ;
}
static int F_19 ( struct V_26 * V_17 )
{
struct V_13 * V_14 = F_20 ( V_17 ) ;
struct V_3 * V_4 = F_21 ( V_14 ) ;
F_3 (
F_2 (
V_4 -> V_6 + V_25 ) | V_8 ,
V_4 -> V_6 + V_25 ) ;
return 0 ;
}
