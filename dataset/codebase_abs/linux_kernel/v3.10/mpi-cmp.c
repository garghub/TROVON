int F_1 ( T_1 V_1 , unsigned long V_2 )
{
T_2 V_3 = V_2 ;
F_2 ( V_1 ) ;
if ( ! V_1 -> V_4 && ! V_3 )
return 0 ;
if ( V_1 -> V_5 )
return - 1 ;
if ( V_1 -> V_4 > 1 )
return 1 ;
if ( V_1 -> V_6 [ 0 ] == V_3 )
return 0 ;
else if ( V_1 -> V_6 [ 0 ] > V_3 )
return 1 ;
else
return - 1 ;
}
int F_3 ( T_1 V_1 , T_1 V_2 )
{
T_3 V_7 , V_8 ;
int V_9 ;
F_2 ( V_1 ) ;
F_2 ( V_2 ) ;
V_7 = V_1 -> V_4 ;
V_8 = V_2 -> V_4 ;
if ( ! V_1 -> V_5 && V_2 -> V_5 )
return 1 ;
if ( V_1 -> V_5 && ! V_2 -> V_5 )
return - 1 ;
if ( V_7 != V_8 && ! V_1 -> V_5 && ! V_2 -> V_5 )
return V_7 - V_8 ;
if ( V_7 != V_8 && V_1 -> V_5 && V_2 -> V_5 )
return V_8 + V_7 ;
if ( ! V_7 )
return 0 ;
V_9 = F_4 ( V_1 -> V_6 , V_2 -> V_6 , V_7 ) ;
if ( ! V_9 )
return 0 ;
if ( ( V_9 < 0 ? 1 : 0 ) == ( V_1 -> V_5 ? 1 : 0 ) )
return 1 ;
return - 1 ;
}
