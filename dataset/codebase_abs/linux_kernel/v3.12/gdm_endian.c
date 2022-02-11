void F_1 ( struct V_1 * V_2 , T_1 V_3 )
{
T_1 V_4 [ 2 ] = { 0x12 , 0x34 } ;
T_1 V_5 [ 2 ] = { 0 , } ;
T_2 V_6 = 0x1234 ;
if ( V_3 == V_7 )
V_2 -> V_8 = V_7 ;
else
V_2 -> V_8 = V_9 ;
memcpy ( V_5 , & V_6 , 2 ) ;
if ( V_4 [ 0 ] != V_5 [ 0 ] )
V_2 -> V_10 = V_9 ;
else
V_2 -> V_10 = V_7 ;
}
T_2 F_2 ( struct V_1 * V_2 , T_2 V_11 )
{
if ( V_2 -> V_8 == V_2 -> V_10 )
return V_11 ;
return F_3 ( V_11 ) ;
}
T_2 F_4 ( struct V_1 * V_2 , T_2 V_11 )
{
if ( V_2 -> V_8 == V_2 -> V_10 )
return V_11 ;
return F_3 ( V_11 ) ;
}
T_3 F_5 ( struct V_1 * V_2 , T_3 V_11 )
{
if ( V_2 -> V_8 == V_2 -> V_10 )
return V_11 ;
return F_6 ( V_11 ) ;
}
T_3 F_7 ( struct V_1 * V_2 , T_3 V_11 )
{
if ( V_2 -> V_8 == V_2 -> V_10 )
return V_11 ;
return F_6 ( V_11 ) ;
}
