int * F_1 ( volatile void * V_1 )
{
#if F_2 ()
unsigned long V_2 =
( unsigned long ) V_1 & ( ( V_3 - 1 ) & -sizeof( long long ) ) ;
unsigned long V_4 = F_3 ( 0 , V_2 ) ;
unsigned long V_5 = V_4 >> ( ( sizeof( V_4 ) * 8 ) - V_6 ) ;
unsigned long V_7 = V_4 & ( V_8 - 1 ) ;
return & V_9 [ V_5 ] -> V_10 [ V_7 ] ;
#else
unsigned long V_11 = F_4 ( ( unsigned long ) V_1 >> 1 ,
( unsigned long ) V_12 ,
2 , ( V_13 + 2 ) - 1 ) ;
return ( int * ) V_11 ;
#endif
}
static int F_5 ( int * V_14 )
{
#if F_2 ()
int V_2 ;
for ( V_2 = 0 ; V_2 < V_15 ; ++ V_2 ) {
if ( V_14 >= & V_9 [ V_2 ] -> V_10 [ 0 ] &&
V_14 < & V_9 [ V_2 ] -> V_10 [ V_8 ] ) {
return 1 ;
}
}
return 0 ;
#else
return V_14 >= & V_12 [ 0 ] && V_14 < & V_12 [ V_16 ] ;
#endif
}
void F_6 ( int * V_17 )
{
F_7 ( ! F_5 ( V_17 ) ) ;
F_7 ( * V_17 != 1 ) ;
* V_17 = 0 ;
}
static inline int * F_8 ( volatile void * V_1 )
{
* ( volatile int * ) V_1 ;
return F_1 ( V_1 ) ;
}
int F_9 ( T_1 * V_1 , int V_4 )
{
return F_10 ( & V_1 -> V_18 , F_8 ( V_1 ) , V_4 ) . V_19 ;
}
int F_11 ( T_1 * V_1 , int V_2 )
{
return F_12 ( & V_1 -> V_18 , F_8 ( V_1 ) , V_2 ) . V_19 ;
}
int F_13 ( T_1 * V_1 , int V_20 , int V_21 )
{
return F_14 ( & V_1 -> V_18 , F_8 ( V_1 ) , V_21 , V_20 )
. V_19 ;
}
int F_15 ( T_1 * V_1 , int V_22 , int V_4 )
{
return F_16 ( & V_1 -> V_18 , F_8 ( V_1 ) , V_22 , V_4 ) . V_19 ;
}
unsigned long F_17 ( volatile unsigned long * V_14 , unsigned long V_23 )
{
return F_18 ( ( int * ) V_14 , F_8 ( V_14 ) , V_23 ) . V_19 ;
}
unsigned long F_19 ( volatile unsigned long * V_14 , unsigned long V_23 )
{
return F_20 ( ( int * ) V_14 , F_8 ( V_14 ) , V_23 ) . V_19 ;
}
unsigned long F_21 ( volatile unsigned long * V_14 , unsigned long V_23 )
{
return F_22 ( ( int * ) V_14 , F_8 ( V_14 ) , V_23 ) . V_19 ;
}
T_2 F_23 ( T_3 * V_1 , T_2 V_4 )
{
return F_24 ( & V_1 -> V_18 , F_8 ( V_1 ) , V_4 ) ;
}
T_2 F_25 ( T_3 * V_1 , T_2 V_2 )
{
return F_26 ( & V_1 -> V_18 , F_8 ( V_1 ) , V_2 ) ;
}
T_2 F_27 ( T_3 * V_1 , T_2 V_20 , T_2 V_21 )
{
return F_28 ( & V_1 -> V_18 , F_8 ( V_1 ) ,
V_21 , V_20 ) ;
}
T_2 F_29 ( T_3 * V_1 , T_2 V_22 , T_2 V_4 )
{
return F_30 ( & V_1 -> V_18 , F_8 ( V_1 ) , V_22 , V_4 ) ;
}
struct V_24 F_31 ( int T_4 * V_25 )
{
if ( F_32 ( ! F_33 ( V_26 , V_25 , sizeof( int ) ) ) )
F_34 ( L_1 , V_25 ) ;
return (struct V_24 ) { . V_27 = - V_28 } ;
}
static int T_5 F_35 ( char * V_29 )
{
F_36 ( L_2 ) ;
return 1 ;
}
void T_5 F_37 ( void )
{
#if F_2 ()
unsigned int V_2 ;
int V_30 ;
V_30 = F_38 ( V_31 ) ;
for ( V_2 = 0 ; V_2 < V_15 ; ++ V_2 ) {
V_30 = F_39 ( V_30 , V_31 ) ;
if ( V_30 >= V_32 )
V_30 = F_38 ( V_31 ) ;
V_9 [ V_2 ] = & F_40 ( V_33 , V_30 ) ;
}
#else
F_41 ( V_16 & ( V_16 - 1 ) ) ;
F_7 ( V_16 < V_32 ) ;
F_7 ( ( unsigned long ) V_12 % V_3 != 0 ) ;
F_41 ( V_16 * sizeof( int ) > V_3 ) ;
F_41 ( ( V_3 >> 3 ) > V_16 ) ;
#endif
}
