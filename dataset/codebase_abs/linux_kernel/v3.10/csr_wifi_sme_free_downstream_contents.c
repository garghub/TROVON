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
break;
}
case V_8 :
{
T_3 * V_6 = ( T_3 * ) V_2 ;
F_2 ( V_6 -> V_9 ) ;
V_6 -> V_9 = NULL ;
break;
}
case V_10 :
{
T_4 * V_6 = ( T_4 * ) V_2 ;
F_2 ( V_6 -> V_11 . V_12 ) ;
V_6 -> V_11 . V_12 = NULL ;
break;
}
case V_13 :
{
T_5 * V_6 = ( T_5 * ) V_2 ;
F_2 ( V_6 -> V_14 ) ;
V_6 -> V_14 = NULL ;
break;
}
case V_15 :
{
T_6 * V_6 = ( T_6 * ) V_2 ;
F_2 ( V_6 -> V_14 ) ;
V_6 -> V_14 = NULL ;
break;
}
case V_16 :
{
T_7 * V_6 = ( T_7 * ) V_2 ;
F_2 ( V_6 -> V_14 ) ;
V_6 -> V_14 = NULL ;
break;
}
case V_17 :
{
T_8 * V_6 = ( T_8 * ) V_2 ;
F_2 ( V_6 -> V_7 ) ;
V_6 -> V_7 = NULL ;
break;
}
case V_18 :
{
T_9 * V_6 = ( T_9 * ) V_2 ;
F_2 ( V_6 -> V_19 ) ;
V_6 -> V_19 = NULL ;
break;
}
case V_20 :
{
T_10 * V_6 = ( T_10 * ) V_2 ;
F_2 ( V_6 -> V_21 ) ;
V_6 -> V_21 = NULL ;
break;
}
case V_22 :
{
T_11 * V_6 = ( T_11 * ) V_2 ;
F_2 ( V_6 -> V_23 . V_24 ) ;
V_6 -> V_23 . V_24 = NULL ;
break;
}
case V_25 :
{
T_12 * V_6 = ( T_12 * ) V_2 ;
F_2 ( V_6 -> V_26 ) ;
V_6 -> V_26 = NULL ;
F_2 ( V_6 -> V_27 ) ;
V_6 -> V_27 = NULL ;
F_2 ( V_6 -> V_28 ) ;
V_6 -> V_28 = NULL ;
break;
}
case V_29 :
{
T_13 * V_6 = ( T_13 * ) V_2 ;
F_2 ( V_6 -> V_30 ) ;
V_6 -> V_30 = NULL ;
F_2 ( V_6 -> V_31 ) ;
V_6 -> V_31 = NULL ;
break;
}
case V_32 :
{
T_14 * V_6 = ( T_14 * ) V_2 ;
{
T_1 V_33 ;
for ( V_33 = 0 ; V_33 < V_6 -> V_34 ; V_33 ++ )
{
F_2 ( V_6 -> V_35 [ V_33 ] . V_36 ) ;
V_6 -> V_35 [ V_33 ] . V_36 = NULL ;
}
}
F_2 ( V_6 -> V_35 ) ;
V_6 -> V_35 = NULL ;
break;
}
case V_37 :
{
T_15 * V_6 = ( T_15 * ) V_2 ;
{
T_1 V_33 ;
for ( V_33 = 0 ; V_33 < V_6 -> V_34 ; V_33 ++ )
{
F_2 ( V_6 -> V_35 [ V_33 ] . V_36 ) ;
V_6 -> V_35 [ V_33 ] . V_36 = NULL ;
}
}
F_2 ( V_6 -> V_35 ) ;
V_6 -> V_35 = NULL ;
break;
}
case V_38 :
{
T_16 * V_6 = ( T_16 * ) V_2 ;
F_2 ( V_6 -> V_39 . V_39 ) ;
V_6 -> V_39 . V_39 = NULL ;
break;
}
case V_40 :
{
T_17 * V_6 = ( T_17 * ) V_2 ;
F_2 ( V_6 -> V_41 . V_42 ) ;
V_6 -> V_41 . V_42 = NULL ;
break;
}
case V_43 :
{
T_18 * V_6 = ( T_18 * ) V_2 ;
F_2 ( V_6 -> V_36 ) ;
V_6 -> V_36 = NULL ;
break;
}
default:
break;
}
}
