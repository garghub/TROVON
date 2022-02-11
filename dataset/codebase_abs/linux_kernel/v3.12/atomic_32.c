int * F_1 ( volatile void * V_1 )
{
unsigned long V_2 = F_2 ( ( unsigned long ) V_1 >> 1 ,
( unsigned long ) V_3 ,
2 , ( V_4 + 2 ) - 1 ) ;
return ( int * ) V_2 ;
}
static int F_3 ( int * V_5 )
{
return V_5 >= & V_3 [ 0 ] && V_5 < & V_3 [ V_6 ] ;
}
void F_4 ( int * V_7 )
{
F_5 ( ! F_3 ( V_7 ) ) ;
F_5 ( * V_7 != 1 ) ;
* V_7 = 0 ;
}
static inline int * F_6 ( volatile void * V_1 )
{
* ( volatile int * ) V_1 ;
return F_1 ( V_1 ) ;
}
int F_7 ( int * V_1 , int V_8 )
{
return F_8 ( V_1 , F_6 ( V_1 ) , V_8 ) . V_9 ;
}
int F_9 ( int * V_1 , int V_10 )
{
return F_10 ( V_1 , F_6 ( V_1 ) , V_10 ) . V_9 ;
}
int F_11 ( int * V_1 , int V_11 , int V_12 )
{
return F_12 ( V_1 , F_6 ( V_1 ) , V_12 , V_11 ) . V_9 ;
}
int F_13 ( int * V_1 , int V_13 , int V_8 )
{
return F_14 ( V_1 , F_6 ( V_1 ) , V_13 , V_8 ) . V_9 ;
}
unsigned long F_15 ( volatile unsigned long * V_5 , unsigned long V_14 )
{
return F_16 ( ( int * ) V_5 , F_6 ( V_5 ) , V_14 ) . V_9 ;
}
unsigned long F_17 ( volatile unsigned long * V_5 , unsigned long V_14 )
{
return F_18 ( ( int * ) V_5 , F_6 ( V_5 ) , V_14 ) . V_9 ;
}
unsigned long F_19 ( volatile unsigned long * V_5 , unsigned long V_14 )
{
return F_20 ( ( int * ) V_5 , F_6 ( V_5 ) , V_14 ) . V_9 ;
}
long long F_21 ( long long * V_1 , long long V_8 )
{
return F_22 ( V_1 , F_6 ( V_1 ) , V_8 ) ;
}
long long F_23 ( long long * V_1 , long long V_10 )
{
return F_24 ( V_1 , F_6 ( V_1 ) , V_10 ) ;
}
long long F_25 ( long long * V_1 , long long V_11 , long long V_12 )
{
return F_26 ( V_1 , F_6 ( V_1 ) , V_12 , V_11 ) ;
}
long long F_27 ( long long * V_1 , long long V_13 , long long V_8 )
{
return F_28 ( V_1 , F_6 ( V_1 ) , V_13 , V_8 ) ;
}
struct V_15 F_29 ( int T_1 * V_16 )
{
if ( F_30 ( ! F_31 ( V_17 , V_16 , sizeof( int ) ) ) )
F_32 ( L_1 , V_16 ) ;
return (struct V_15 ) { . V_18 = - V_19 } ;
}
void T_2 F_33 ( void )
{
F_34 ( V_6 & ( V_6 - 1 ) ) ;
F_5 ( V_6 < V_20 ) ;
F_5 ( ( unsigned long ) V_3 % V_21 != 0 ) ;
F_34 ( V_6 * sizeof( int ) > V_21 ) ;
F_34 ( ( V_21 >> 3 ) > V_6 ) ;
}
