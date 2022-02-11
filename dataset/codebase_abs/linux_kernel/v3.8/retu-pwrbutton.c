static T_1 F_1 ( int V_1 , void * V_2 )
{
struct V_3 * V_4 = V_2 ;
struct V_5 * V_6 = F_2 ( V_4 ) ;
bool V_7 ;
V_7 = ! ( F_3 ( V_6 , V_8 ) & V_9 ) ;
F_4 ( V_4 , V_10 , V_7 ) ;
F_5 ( V_4 ) ;
return V_11 ;
}
static int F_6 ( struct V_12 * V_13 )
{
struct V_5 * V_6 = F_7 ( V_13 -> V_14 . V_15 ) ;
struct V_3 * V_4 ;
int V_1 ;
int error ;
V_1 = F_8 ( V_13 , 0 ) ;
if ( V_1 < 0 )
return V_1 ;
V_4 = F_9 ( & V_13 -> V_14 ) ;
if ( ! V_4 )
return - V_16 ;
V_4 -> V_17 = L_1 ;
V_4 -> V_14 . V_15 = & V_13 -> V_14 ;
F_10 ( V_4 , V_18 , V_10 ) ;
F_11 ( V_4 , V_6 ) ;
error = F_12 ( & V_13 -> V_14 , V_1 ,
NULL , F_1 , 0 ,
L_1 , V_4 ) ;
if ( error )
return error ;
error = F_13 ( V_4 ) ;
if ( error )
return error ;
return 0 ;
}
static int F_14 ( struct V_12 * V_13 )
{
return 0 ;
}
