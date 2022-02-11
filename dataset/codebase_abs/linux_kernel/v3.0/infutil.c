int F_1 ( void * V_1 , unsigned int V_2 ,
const void * V_3 , unsigned int V_4 )
{
const T_1 * V_5 = V_3 ;
struct V_6 * V_7 ;
int V_8 ;
V_8 = - V_9 ;
V_7 = F_2 ( sizeof( * V_7 ) , V_10 ) ;
if ( V_7 == NULL )
goto V_11;
V_7 -> V_12 = F_2 ( F_3 () , V_10 ) ;
if ( V_7 -> V_12 == NULL )
goto V_13;
V_7 -> V_14 = V_5 ;
V_7 -> V_15 = V_4 ;
V_7 -> V_16 = V_1 ;
V_7 -> V_17 = V_2 ;
V_8 = F_4 ( V_7 , - V_18 ) ;
if ( V_8 == V_19 ) {
V_8 = F_5 ( V_7 , V_20 ) ;
if ( V_8 == V_21 )
V_8 = V_2 - V_7 -> V_17 ;
else
V_8 = - V_22 ;
F_6 ( V_7 ) ;
} else
V_8 = - V_22 ;
F_7 ( V_7 -> V_12 ) ;
V_13:
F_7 ( V_7 ) ;
V_11:
return V_8 ;
}
