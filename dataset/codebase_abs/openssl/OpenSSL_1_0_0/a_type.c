int F_1 ( T_1 * V_1 )
{
if ( ( V_1 -> V_2 . V_3 != NULL ) || ( V_1 -> type == V_4 ) )
return ( V_1 -> type ) ;
else
return ( 0 ) ;
}
void F_2 ( T_1 * V_1 , int type , void * V_2 )
{
if ( V_1 -> V_2 . V_3 != NULL )
{
T_1 * * V_5 = & V_1 ;
F_3 ( ( V_6 * * ) V_5 , NULL ) ;
}
V_1 -> type = type ;
if ( type == V_7 )
V_1 -> V_2 . boolean = V_2 ? 0xff : 0 ;
else
V_1 -> V_2 . V_3 = V_2 ;
}
int F_4 ( T_1 * V_1 , int type , const void * V_2 )
{
if ( ! V_2 || ( type == V_7 ) )
{
void * V_8 = ( void * ) V_2 ;
F_2 ( V_1 , type , V_8 ) ;
}
else if ( type == V_9 )
{
T_2 * V_10 ;
V_10 = F_5 ( V_2 ) ;
if ( ! V_10 )
return 0 ;
F_2 ( V_1 , type , V_10 ) ;
}
else
{
T_3 * V_11 ;
V_11 = F_6 ( V_2 ) ;
if ( ! V_11 )
return 0 ;
F_2 ( V_1 , type , V_11 ) ;
}
return 1 ;
}
int F_7 ( T_1 * V_1 , T_1 * V_12 )
{
int V_13 = - 1 ;
if ( ! V_1 || ! V_12 || V_1 -> type != V_12 -> type ) return - 1 ;
switch ( V_1 -> type )
{
case V_9 :
V_13 = F_8 ( V_1 -> V_2 . V_14 , V_12 -> V_2 . V_14 ) ;
break;
case V_4 :
V_13 = 0 ;
break;
case V_15 :
case V_16 :
case V_17 :
case V_18 :
case V_19 :
case V_20 :
case V_21 :
case V_22 :
case V_23 :
case V_24 :
case V_25 :
case V_26 :
case V_27 :
case V_28 :
case V_29 :
case V_30 :
case V_31 :
case V_32 :
case V_33 :
case V_34 :
case V_35 :
case V_36 :
default:
V_13 = F_9 ( ( T_3 * ) V_1 -> V_2 . V_3 ,
( T_3 * ) V_12 -> V_2 . V_3 ) ;
break;
}
return V_13 ;
}
