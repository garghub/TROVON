void F_1 ( struct V_1 * V_2 , T_1 V_3 , T_1 V_4 )
{
memset ( V_2 , 0 , sizeof( * V_2 ) ) ;
V_2 -> V_5 = V_6 ;
V_2 -> V_7 = V_3 ;
V_2 -> V_8 = V_4 ;
}
int F_2 ( const struct V_1 * V_2 )
{
if ( ! V_2 )
return - V_9 ;
if ( V_2 -> V_5 != V_6 )
return - V_10 ;
if ( V_2 -> V_11 [ 0 ] != 0 )
return - V_12 ;
return 0 ;
}
bool F_3 ( const struct V_1 * V_2 )
{
return V_2 -> V_8 != V_13 ;
}
void F_4 ( struct V_1 * V_2 )
{
F_1 ( V_2 , V_14 , V_13 ) ;
}
bool F_5 ( const struct V_1 * V_2 ,
const struct V_1 * V_15 )
{
return V_2 -> V_7 == V_15 -> V_7 &&
V_2 -> V_8 == V_15 -> V_8 ;
}
int F_6 ( const struct V_16 * V_2 ,
T_2 V_17 , struct V_1 * * V_18 )
{
if ( V_17 < sizeof( * * V_18 ) )
return - V_9 ;
* V_18 = (struct V_1 * ) V_2 ;
return F_2 ( * V_18 ) ;
}
