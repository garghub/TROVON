static inline T_1 F_1 ( int V_1 )
{
unsigned long V_2 ;
T_1 V_3 ;
F_2 ( & V_4 , V_2 ) ;
V_3 = F_3 ( V_5 , V_6 , V_1 ) ;
F_4 ( & V_4 , V_2 ) ;
return V_7 + ( V_3 << V_8 ) ;
}
static void F_5 ( T_1 V_9 , int V_1 )
{
unsigned long V_2 ;
T_1 V_3 = ( V_9 - V_7 ) >> V_8 ;
if ( V_9 < V_7 || ( V_3 + ( 1 << V_1 ) ) >= V_6 ) {
F_6 ( V_10 L_1 , V_11 ) ;
F_7 () ;
}
F_2 ( & V_4 , V_2 ) ;
F_8 ( V_5 , V_3 , V_1 ) ;
F_4 ( & V_4 , V_2 ) ;
}
void * F_9 ( struct V_12 * V_13 , T_2 V_14 , T_3 * V_15 ,
T_4 V_16 , unsigned long V_17 )
{
T_1 V_18 ;
int V_1 ;
if ( ! V_19 || ! V_14 )
return NULL ;
V_1 = F_10 ( ( ( V_14 - 1 ) >> V_8 ) + 1 ) ;
V_18 = F_1 ( V_1 ) ;
if ( V_15 )
* V_15 = V_18 ;
if ( ! V_18 )
return NULL ;
return F_11 ( V_18 ) ;
}
void F_12 ( struct V_12 * V_13 , T_2 V_14 , void * V_20 ,
T_3 V_21 , unsigned long V_17 )
{
int V_1 ;
if ( ! V_19 || ! V_14 )
return;
V_1 = F_10 ( ( ( V_14 - 1 ) >> V_8 ) + 1 ) ;
F_5 ( F_13 ( V_20 ) , V_1 ) ;
}
void T_5 F_14 ( T_6 V_22 , T_1 V_14 )
{
T_6 V_23 ;
if ( ! V_14 )
return;
F_6 ( V_24
L_2 ,
V_22 , V_14 ) ;
V_7 = V_22 ;
V_19 = V_14 ;
V_6 = V_19 >> V_8 ;
if ( V_19 & ( V_25 - 1 ) )
++ V_6 ;
V_23 = F_15 ( F_16 ( V_6 ) * sizeof( long ) ,
sizeof( long ) ) ;
V_5 = F_11 ( V_23 ) ;
memset ( V_5 , 0 , V_6 * V_25 ) ;
}
