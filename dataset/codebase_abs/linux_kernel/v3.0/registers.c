int F_1 ( int V_1 , unsigned long * V_2 )
{
if ( F_2 ( V_3 , V_1 , 0 , V_2 ) < 0 )
return - V_4 ;
return 0 ;
}
int F_3 ( int V_1 , unsigned long * V_2 )
{
if ( F_2 ( V_5 , V_1 , 0 , V_2 ) < 0 )
return - V_4 ;
return 0 ;
}
unsigned long F_4 ( int V_6 , T_1 * V_7 )
{
switch ( V_6 ) {
case V_8 :
return V_7 [ 0 ] -> V_9 ;
case V_10 :
return V_7 [ 0 ] -> V_11 ;
case V_12 :
return V_7 [ 0 ] -> V_13 ;
default:
F_5 ( V_14 L_1 ,
V_6 ) ;
return 0 ;
}
}
int F_6 ( int V_1 , unsigned long * V_15 )
{
return F_1 ( V_1 , V_15 ) ;
}
int F_7 ( int V_1 , unsigned long * V_15 )
{
return F_3 ( V_1 , V_15 ) ;
}
