T_1 int F_1 ( unsigned long V_1 , unsigned long V_2 ,
unsigned long V_3 , unsigned long V_4 ,
int V_5 , unsigned long V_6 )
{
if ( V_6 & ~ V_7 )
return - V_8 ;
return F_2 ( V_1 , V_2 , V_3 , V_4 , V_5 , V_6 >> V_9 ) ;
}
T_1 long F_3 ( unsigned long V_1 , unsigned long V_2 ,
unsigned long V_3 , unsigned long V_4 ,
unsigned long V_5 , unsigned long V_10 )
{
if ( V_10 & ( ( 1 << ( V_9 - 12 ) ) - 1 ) )
return - V_8 ;
V_10 >>= V_9 - 12 ;
return F_2 ( V_1 , V_2 , V_3 , V_4 , V_5 , V_10 ) ;
}
T_1 int F_4 ( unsigned long V_1 , unsigned long V_2 , int V_11 )
{
struct V_12 * V_13 ;
if ( ( V_11 <= 0 ) || ( V_11 > ( V_14 | V_15 ) ) )
return - V_8 ;
if ( V_1 + V_2 < V_1 )
return - V_16 ;
F_5 ( & V_17 -> V_18 -> V_19 ) ;
V_13 = F_6 ( V_17 -> V_18 , V_1 ) ;
if ( V_13 == NULL || V_1 < V_13 -> V_20 || V_1 + V_2 > V_13 -> V_21 ) {
F_7 ( & V_17 -> V_18 -> V_19 ) ;
return - V_16 ;
}
switch ( V_11 & V_14 ) {
case V_22 :
F_8 ( ( void * ) V_1 , V_2 ) ;
break;
case V_23 :
F_9 ( ( void * ) V_1 , V_2 ) ;
break;
case V_14 :
F_10 ( ( void * ) V_1 , V_2 ) ;
break;
}
if ( V_11 & V_15 )
F_11 ( V_1 , V_1 + V_2 ) ;
F_7 ( & V_17 -> V_18 -> V_19 ) ;
return 0 ;
}
