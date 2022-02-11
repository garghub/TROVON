static int F_1 ( T_1 V_1 ,
T_2 V_2 , T_2 V_3 ,
bool V_4 )
{
unsigned int V_5 = V_4 ? 8 : 16 ;
struct V_6 V_7 = {
. V_8 = V_9 ,
. V_10 = V_11 ,
. V_12 . V_13 = {
. V_2 = ( V_14 ) V_2 ,
. V_3 = ( V_14 ) V_3 ,
. V_1 = V_1 ,
. V_15 = V_4 ? V_16 : 0 ,
} ,
} ;
if ( F_2 ( ( V_2 & ( ~ 0 << V_5 ) ) || ( V_3 & ( ~ 0 << V_5 ) ) ,
L_1
L_2 , \
V_5 , V_2 , V_3 ) )
return - 1 ;
F_3 ( & V_7 ) ;
return 1 ;
}
int F_4 ( T_1 V_1 ,
T_2 V_17 , T_2 V_18 )
{
return F_1 ( V_1 , V_17 ,
V_18 , false ) ;
}
int F_5 ( T_1 V_1 ,
T_2 V_2 , T_2 V_3 )
{
return F_1 ( V_1 , V_2 ,
V_3 , true ) ;
}
