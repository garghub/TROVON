T_1 F_1 ( T_1 V_1 )
{
return ( T_1 ) F_2 ( V_1 , V_2 ) ;
}
int F_3 ( T_1 V_3 )
{
F_4 ( ( volatile void V_4 * ) V_3 ) ;
return 0 ;
}
int F_5 ( struct V_5 * V_6 , int V_7 ,
T_1 V_8 , T_1 V_9 )
{
if ( ! V_7 ) {
V_6 -> V_10 . V_11 = F_1 ( V_8 ) ;
if ( ! V_6 -> V_10 . V_11 )
return - V_12 ;
} else
V_6 -> V_10 . V_11 = 0 ;
V_6 -> V_13 . V_11 = V_9 ;
return 0 ;
}
int F_6 ( struct V_5 * V_6 )
{
if ( V_6 -> V_10 . V_11 ) {
int V_14 = F_3 ( V_6 -> V_10 . V_11 ) ;
if ( V_14 )
return V_14 ;
}
V_6 -> V_13 . V_11 = V_6 -> V_10 . V_11 = 0 ;
return 0 ;
}
