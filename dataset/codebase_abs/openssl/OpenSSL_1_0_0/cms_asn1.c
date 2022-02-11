static int F_1 ( int V_1 , T_1 * * V_2 , const T_2 * V_3 ,
void * V_4 )
{
T_3 * V_5 = V_4 ;
T_4 * V_6 = NULL ;
if ( V_2 )
V_6 = ( T_4 * ) * V_2 ;
else
return 1 ;
switch( V_1 )
{
case V_7 :
if ( F_2 ( & V_5 -> V_8 , V_6 ) <= 0 )
return 0 ;
case V_9 :
V_5 -> V_10 = F_3 ( V_6 , V_5 -> V_11 ) ;
if ( ! V_5 -> V_10 )
return 0 ;
break;
case V_12 :
case V_13 :
if ( F_4 ( V_6 , V_5 -> V_10 ) <= 0 )
return 0 ;
break;
}
return 1 ;
}
