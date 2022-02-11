int F_1 ( T_1 * V_1 , T_1 * V_2 )
{
int V_3 = - 1 ;
if ( ! V_1 || ! V_2 || V_1 -> type != V_2 -> type ) return - 1 ;
switch( V_1 -> type )
{
case V_4 :
case V_5 :
V_3 = F_2 ( V_1 -> V_6 . V_7 , V_2 -> V_6 . V_7 ) ;
break;
case V_8 :
V_3 = F_3 ( V_1 -> V_6 . V_9 , V_2 -> V_6 . V_9 ) ;
break;
case V_10 :
case V_11 :
case V_12 :
V_3 = F_4 ( V_1 -> V_6 . V_13 , V_2 -> V_6 . V_13 ) ;
break;
case V_14 :
V_3 = F_5 ( V_1 -> V_6 . V_15 , V_2 -> V_6 . V_15 ) ;
break;
case V_16 :
V_3 = F_6 ( V_1 -> V_6 . V_17 , V_2 -> V_6 . V_17 ) ;
break;
case V_18 :
V_3 = F_7 ( V_1 -> V_6 . V_19 , V_2 -> V_6 . V_19 ) ;
break;
}
return V_3 ;
}
int F_3 ( T_2 * V_1 , T_2 * V_2 )
{
int V_3 = - 1 ;
if ( ! V_1 || ! V_2 ) return - 1 ;
if ( ( V_3 = F_7 ( V_1 -> V_20 , V_2 -> V_20 ) ) != 0 )
return V_3 ;
V_3 = F_2 ( V_1 -> V_21 , V_2 -> V_21 ) ;
return V_3 ;
}
void F_8 ( T_1 * V_1 , int type , void * V_21 )
{
switch( type )
{
case V_4 :
case V_5 :
V_1 -> V_6 . V_7 = V_21 ;
break;
case V_8 :
V_1 -> V_6 . V_9 = V_21 ;
break;
case V_10 :
case V_11 :
case V_12 :
V_1 -> V_6 . V_13 = V_21 ;
break;
case V_14 :
V_1 -> V_6 . V_15 = V_21 ;
break;
case V_16 :
V_1 -> V_6 . V_17 = V_21 ;
break;
case V_18 :
V_1 -> V_6 . V_19 = V_21 ;
break;
}
V_1 -> type = type ;
}
void * F_9 ( T_1 * V_1 , int * V_22 )
{
if ( V_22 )
* V_22 = V_1 -> type ;
switch( V_1 -> type )
{
case V_4 :
case V_5 :
return V_1 -> V_6 . V_7 ;
case V_8 :
return V_1 -> V_6 . V_9 ;
case V_10 :
case V_11 :
case V_12 :
return V_1 -> V_6 . V_13 ;
case V_14 :
return V_1 -> V_6 . V_15 ;
case V_16 :
return V_1 -> V_6 . V_17 ;
case V_18 :
return V_1 -> V_6 . V_19 ;
default:
return NULL ;
}
}
int F_10 ( T_1 * V_23 ,
T_3 * V_24 , T_4 * V_21 )
{
T_2 * V_25 ;
V_25 = F_11 () ;
if ( ! V_25 )
return 0 ;
V_25 -> V_20 = V_24 ;
V_25 -> V_21 = V_21 ;
F_8 ( V_23 , V_8 , V_25 ) ;
return 1 ;
}
int F_12 ( T_1 * V_23 ,
T_3 * * V_26 , T_4 * * V_27 )
{
if ( V_23 -> type != V_8 )
return 0 ;
if ( V_26 )
* V_26 = V_23 -> V_6 . V_9 -> V_20 ;
if ( V_27 )
* V_27 = V_23 -> V_6 . V_9 -> V_21 ;
return 1 ;
}
