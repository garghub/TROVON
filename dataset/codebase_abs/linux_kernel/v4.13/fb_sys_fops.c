T_1 F_1 ( struct V_1 * V_2 , char T_2 * V_3 , T_3 V_4 ,
T_4 * V_5 )
{
unsigned long V_6 = * V_5 ;
void * V_7 ;
int V_8 = 0 ;
unsigned long V_9 ;
if ( V_2 -> V_10 != V_11 )
return - V_12 ;
V_9 = V_2 -> V_13 ;
if ( V_9 == 0 )
V_9 = V_2 -> V_14 . V_15 ;
if ( V_6 >= V_9 )
return 0 ;
if ( V_4 >= V_9 )
V_4 = V_9 ;
if ( V_4 + V_6 > V_9 )
V_4 = V_9 - V_6 ;
V_7 = ( void V_16 * ) ( V_2 -> V_17 + V_6 ) ;
if ( V_2 -> V_18 -> V_19 )
V_2 -> V_18 -> V_19 ( V_2 ) ;
if ( F_2 ( V_3 , V_7 , V_4 ) )
V_8 = - V_20 ;
if ( ! V_8 )
* V_5 += V_4 ;
return ( V_8 ) ? V_8 : V_4 ;
}
T_1 F_3 ( struct V_1 * V_2 , const char T_2 * V_3 ,
T_3 V_4 , T_4 * V_5 )
{
unsigned long V_6 = * V_5 ;
void * V_21 ;
int V_8 = 0 ;
unsigned long V_9 ;
if ( V_2 -> V_10 != V_11 )
return - V_12 ;
V_9 = V_2 -> V_13 ;
if ( V_9 == 0 )
V_9 = V_2 -> V_14 . V_15 ;
if ( V_6 > V_9 )
return - V_22 ;
if ( V_4 > V_9 ) {
V_8 = - V_22 ;
V_4 = V_9 ;
}
if ( V_4 + V_6 > V_9 ) {
if ( ! V_8 )
V_8 = - V_23 ;
V_4 = V_9 - V_6 ;
}
V_21 = ( void V_16 * ) ( V_2 -> V_17 + V_6 ) ;
if ( V_2 -> V_18 -> V_19 )
V_2 -> V_18 -> V_19 ( V_2 ) ;
if ( F_4 ( V_21 , V_3 , V_4 ) )
V_8 = - V_20 ;
if ( ! V_8 )
* V_5 += V_4 ;
return ( V_8 ) ? V_8 : V_4 ;
}
