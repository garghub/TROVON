int F_1 ( struct V_1 * V_2 , unsigned long type ,
unsigned long V_3 , unsigned long V_4 )
{
int V_5 , V_6 , V_7 = 4 ;
bool V_8 ;
unsigned long V_9 ;
unsigned long V_10 = ( unsigned long ) V_2 -> V_11 ;
unsigned long V_12 = V_2 -> V_12 ;
switch ( type ) {
case V_13 :
return 0 ;
case V_14 :
V_9 = V_4 ;
V_7 = 8 ;
break;
case V_15 :
V_9 = ( V_16 ) V_4 ;
break;
case V_17 :
V_9 = ( V_18 ) V_4 ;
break;
case V_19 :
V_9 = ( V_16 ) ( V_4 - V_3 ) ;
break;
default:
return - V_20 ;
}
if ( V_3 < V_10 || V_3 >= V_10 + V_12 )
return - V_20 ;
V_8 = false ;
#ifdef F_2
if ( V_3 < V_10 + V_2 -> V_21 )
V_8 = true ;
#endif
V_6 = ( ( V_3 & V_22 ) == ( ( V_3 + V_7 ) & V_22 ) ) ? 1 : 2 ;
if ( V_8 )
F_3 ( V_3 & V_22 , V_6 ) ;
V_5 = F_4 ( ( void * ) V_3 , & V_9 , V_7 ) ;
if ( V_8 )
F_5 ( V_3 & V_22 , V_6 ) ;
return V_5 ;
}
