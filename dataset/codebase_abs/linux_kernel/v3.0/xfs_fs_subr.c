void
F_1 (
T_1 * V_1 ,
T_2 V_2 ,
T_2 V_3 ,
int V_4 )
{
V_3 &= ~ ( V_5 - 1 ) ;
F_2 ( F_3 ( V_1 ) -> V_6 , V_2 , V_3 - 1 ) ;
}
int
F_4 (
T_1 * V_1 ,
T_2 V_2 ,
T_2 V_3 ,
int V_4 )
{
struct V_7 * V_8 = F_3 ( V_1 ) -> V_6 ;
int V_9 = 0 ;
F_5 ( V_1 , V_2 , V_3 ) ;
F_6 ( V_1 , V_10 ) ;
V_9 = F_7 ( V_8 , V_2 ,
V_3 == - 1 ? V_11 : V_3 ) ;
if ( ! V_9 )
F_2 ( V_8 , V_2 , V_3 ) ;
return - V_9 ;
}
int
F_8 (
T_1 * V_1 ,
T_2 V_2 ,
T_2 V_3 ,
T_3 V_12 ,
int V_4 )
{
struct V_7 * V_8 = F_3 ( V_1 ) -> V_6 ;
int V_9 = 0 ;
int V_13 ;
F_6 ( V_1 , V_10 ) ;
V_9 = - F_9 ( V_8 , V_2 ,
V_3 == - 1 ? V_11 : V_3 ) ;
if ( V_12 & V_14 )
return V_9 ;
V_13 = F_10 ( V_1 , V_2 , V_3 ) ;
if ( ! V_9 )
V_9 = V_13 ;
return V_9 ;
}
int
F_10 (
T_1 * V_1 ,
T_2 V_2 ,
T_2 V_3 )
{
struct V_7 * V_8 = F_3 ( V_1 ) -> V_6 ;
if ( F_11 ( V_8 , V_15 ) ) {
return - F_12 ( V_8 , V_2 ,
V_3 == - 1 ? V_1 -> V_16 - 1 : V_3 ) ;
}
return 0 ;
}
