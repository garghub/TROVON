int F_1 ( struct V_1 * V_2 , unsigned long type ,
unsigned long V_3 , unsigned long V_4 )
{
T_1 V_5 = 4 ;
unsigned long V_6 ;
unsigned long V_7 = ( unsigned long ) V_2 -> V_8 . V_9 ;
unsigned long V_10 = V_2 -> V_8 . V_5 ;
switch ( type ) {
case V_11 :
return 0 ;
case V_12 :
V_6 = V_4 ;
V_5 = 8 ;
break;
case V_13 :
V_6 = ( V_14 ) V_4 ;
break;
case V_15 :
V_6 = ( V_16 ) V_4 ;
break;
case V_17 :
V_6 = ( V_14 ) ( V_4 - V_3 ) ;
break;
default:
return - V_18 ;
}
if ( V_3 < V_7 || V_3 >= V_7 + V_10 )
return - V_18 ;
return F_2 ( ( void * ) V_3 , & V_6 , V_5 ) ;
}
