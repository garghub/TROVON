static T_1 F_1 ( int V_1 , void * V_2 )
{
struct V_3 * V_4 = V_2 ;
int V_5 ;
V_5 = F_2 ( V_4 -> V_5 , & V_4 -> V_6 ) ;
if ( V_5 == - V_7 )
return V_8 ;
V_4 -> V_9 = V_5 ;
F_3 ( & V_4 -> V_10 ) ;
return V_11 ;
}
int F_4 ( int V_12 , int * V_13 )
{
struct V_3 * V_2 ;
int V_14 , V_15 ;
V_2 = F_5 ( sizeof( * V_2 ) , V_16 ) ;
if ( V_2 == NULL ) {
F_6 ( V_17 L_1 ) ;
return - V_18 ;
}
* V_2 = ( (struct V_3 ) { . V_5 = V_12 ,
. V_6 = - 1 ,
. V_9 = - 1 } ) ;
F_7 ( & V_2 -> V_10 ) ;
V_14 = F_8 ( V_19 , V_12 , V_20 , F_1 ,
V_21 , L_2 , V_2 ) ;
if ( V_14 ) {
F_6 ( V_17 L_3
L_4 , V_14 ) ;
V_15 = V_14 ;
goto V_22;
}
F_9 ( & V_2 -> V_10 ) ;
F_10 ( V_19 , V_2 ) ;
V_15 = V_2 -> V_9 ;
* V_13 = V_2 -> V_6 ;
V_22:
F_11 ( V_2 ) ;
return V_15 ;
}
