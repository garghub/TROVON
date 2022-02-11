void F_1 ( T_1 V_1 , void * V_2 )
{
if ( V_1 != V_3 )
{
return;
}
if ( NULL == V_2 )
{
return;
}
switch ( * ( ( V_4 * ) V_2 ) )
{
case V_5 :
{
T_2 * V_6 = ( T_2 * ) V_2 ;
F_2 ( V_6 -> V_7 ) ;
V_6 -> V_7 = NULL ;
F_2 ( V_6 -> V_8 ) ;
V_6 -> V_8 = NULL ;
F_2 ( V_6 -> V_9 ) ;
V_6 -> V_9 = NULL ;
break;
}
case V_10 :
{
T_3 * V_6 = ( T_3 * ) V_2 ;
F_2 ( V_6 -> V_11 ) ;
V_6 -> V_11 = NULL ;
break;
}
case V_12 :
{
T_4 * V_6 = ( T_4 * ) V_2 ;
F_2 ( V_6 -> V_13 . V_14 ) ;
V_6 -> V_13 . V_14 = NULL ;
break;
}
case V_15 :
{
T_5 * V_6 = ( T_5 * ) V_2 ;
F_2 ( V_6 -> signal ) ;
V_6 -> signal = NULL ;
F_2 ( V_6 -> V_16 ) ;
V_6 -> V_16 = NULL ;
break;
}
case V_17 :
{
T_6 * V_6 = ( T_6 * ) V_2 ;
F_2 ( V_6 -> V_16 ) ;
V_6 -> V_16 = NULL ;
break;
}
default:
break;
}
}
