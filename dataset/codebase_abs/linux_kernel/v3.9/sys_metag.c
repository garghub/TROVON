int F_1 ( unsigned long V_1 , unsigned long V_2 ,
unsigned long V_3 )
{
if ( ( V_3 & V_4 ) && ( V_1 < V_5 ) )
return - V_6 ;
return 0 ;
}
T_1 long F_2 ( unsigned long V_1 , unsigned long V_2 ,
unsigned long V_7 , unsigned long V_3 ,
unsigned long V_8 , unsigned long V_9 )
{
if ( V_9 & ( ( 1 << ( V_10 - 12 ) ) - 1 ) )
return - V_6 ;
V_9 >>= V_10 - 12 ;
return F_3 ( V_1 , V_2 , V_7 , V_3 , V_8 , V_9 ) ;
}
T_1 int F_4 ( char T_2 * V_1 , int V_11 )
{
char V_12 ;
int V_13 = 0 ;
unsigned int V_3 ;
if ( ! ( ( V_14 unsigned int ) V_1 >= V_15 ) )
return - V_16 ;
F_5 ( V_3 ) ;
F_6 ( ( V_14 void * ) V_1 , sizeof( V_11 ) ) ;
V_13 = F_7 ( V_12 , V_1 ) ;
if ( V_13 )
goto V_17;
V_12 |= V_11 ;
V_13 = F_8 ( V_12 , V_1 ) ;
F_6 ( ( V_14 void * ) V_1 , sizeof( V_11 ) ) ;
V_17:
F_9 ( V_3 ) ;
return V_13 ;
}
T_1 void F_10 ( unsigned int V_3 )
{
unsigned int V_18 ;
V_3 &= V_19 ;
V_18 = F_11 ( V_20 ) ;
V_18 &= ~ V_19 ;
V_18 |= V_3 ;
F_12 ( V_20 , V_18 ) ;
}
T_1 int F_13 ( void T_2 * V_21 )
{
V_22 -> V_23 . V_24 = V_21 ;
F_14 ( V_21 ) ;
return 0 ;
}
T_1 void * F_15 ( void )
{
return ( V_14 void * ) V_22 -> V_23 . V_24 ;
}
T_1 long F_16 ( const char T_2 * V_25 , unsigned long V_26 ,
unsigned long V_27 )
{
return F_17 ( V_25 , F_18 ( V_27 , V_26 ) ) ;
}
T_1 long F_19 ( unsigned int V_8 , unsigned long V_26 ,
unsigned long V_27 )
{
return F_20 ( V_8 , F_18 ( V_27 , V_26 ) ) ;
}
T_1 long F_21 ( int V_8 , unsigned long V_28 ,
unsigned long V_29 ,
unsigned long V_30 ,
unsigned long V_31 , int V_32 )
{
return F_22 ( V_8 , F_18 ( V_29 , V_28 ) ,
F_18 ( V_31 , V_30 ) , V_32 ) ;
}
T_1 long F_23 ( int V_8 , unsigned long V_26 , unsigned long V_27 ,
T_3 V_33 )
{
return F_24 ( V_8 , F_18 ( V_27 , V_26 ) , V_33 ) ;
}
T_1 T_4 F_25 ( unsigned long V_8 , char T_2 * V_34 ,
T_3 V_33 , unsigned long V_26 ,
unsigned long V_27 )
{
return F_26 ( V_8 , V_34 , V_33 , F_18 ( V_27 , V_26 ) ) ;
}
T_1 T_4 F_27 ( unsigned long V_8 , char T_2 * V_34 ,
T_3 V_33 , unsigned long V_26 ,
unsigned long V_27 )
{
return F_28 ( V_8 , V_34 , V_33 , F_18 ( V_27 , V_26 ) ) ;
}
T_1 long F_29 ( int V_8 , unsigned long V_28 ,
unsigned long V_29 ,
unsigned long V_30 ,
unsigned long V_31 ,
unsigned int V_3 )
{
return F_30 ( V_8 , F_18 ( V_29 , V_28 ) ,
F_18 ( V_31 , V_30 ) , V_3 ) ;
}
