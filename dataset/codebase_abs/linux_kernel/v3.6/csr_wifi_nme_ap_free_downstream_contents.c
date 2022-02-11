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
F_2 ( V_6 -> V_7 . V_8 ) ;
V_6 -> V_7 . V_8 = NULL ;
break;
}
case V_9 :
{
T_3 * V_6 = ( T_3 * ) V_2 ;
switch ( V_6 -> V_10 . V_11 )
{
case V_12 :
switch ( V_6 -> V_10 . V_13 . V_14 . V_15 )
{
case V_16 :
F_2 ( V_6 -> V_10 . V_13 . V_14 . V_17 . V_18 . V_18 ) ;
V_6 -> V_10 . V_13 . V_14 . V_17 . V_18 . V_18 = NULL ;
break;
default:
break;
}
break;
default:
break;
}
{
T_1 V_19 ;
for ( V_19 = 0 ; V_19 < V_6 -> V_20 . V_21 . V_22 ; V_19 ++ )
{
F_2 ( V_6 -> V_20 . V_21 . V_23 [ V_19 ] . V_24 ) ;
V_6 -> V_20 . V_21 . V_23 [ V_19 ] . V_24 = NULL ;
}
}
F_2 ( V_6 -> V_20 . V_21 . V_23 ) ;
V_6 -> V_20 . V_21 . V_23 = NULL ;
break;
}
default:
break;
}
}
