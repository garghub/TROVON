T_1 * F_1 ( void )
{
return ( & V_1 ) ;
}
int F_2 ( long V_2 , void * V_3 , T_2 * V_4 ,
T_3 * V_5 , T_4 * V_6 )
{
return F_3 ( V_7 , V_2 , V_3 ,
V_4 , V_5 , V_6 ) ;
}
int F_4 ( T_5 * V_8 , int V_9 , void * V_10 )
{
return ( F_5 ( & V_8 -> V_11 , V_9 , V_10 ) ) ;
}
void * F_6 ( T_5 * V_8 , int V_9 )
{
return ( F_7 ( & V_8 -> V_11 , V_9 ) ) ;
}
T_5 * F_8 ( T_5 * * V_12 , unsigned char * * V_13 , long V_14 )
{
unsigned char * V_15 ;
T_5 * V_16 ;
V_15 = * V_13 ;
V_16 = F_9 ( V_12 , V_13 , V_14 ) ;
if( ! V_16 ) return NULL ;
V_14 -= * V_13 - V_15 ;
if( ! V_14 ) return V_16 ;
if( ! F_10 ( & V_16 -> V_17 , V_13 , V_14 ) ) goto V_18;
return V_16 ;
V_18:
F_11 ( V_16 ) ;
return NULL ;
}
int F_12 ( T_5 * V_12 , unsigned char * * V_13 )
{
int V_14 ;
V_14 = F_13 ( V_12 , V_13 ) ;
if( V_12 ) V_14 += F_14 ( V_12 -> V_17 , V_13 ) ;
return V_14 ;
}
