static inline int * F_1 ( volatile void * V_1 )
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
static inline int * F_31 ( int T_4 * V_1 )
{
F_32 ( V_1 ) ;
return F_1 ( ( int V_24 * ) V_1 ) ;
}
struct V_25 F_33 ( T_5 T_4 * V_1 , int V_2 )
{
return F_10 ( ( int V_24 * ) V_1 , F_31 ( V_1 ) , V_2 ) ;
}
struct V_25 F_34 ( T_5 T_4 * V_1 , int V_4 )
{
return F_12 ( ( int V_24 * ) V_1 , F_31 ( V_1 ) , V_4 ) ;
}
struct V_25 F_35 ( T_5 T_4 * V_1 , int V_4 )
{
return F_18 ( ( int V_24 * ) V_1 , F_31 ( V_1 ) , V_4 ) ;
}
struct V_25 F_36 ( T_5 T_4 * V_1 , int V_4 )
{
return F_20 ( ( int V_24 * ) V_1 , F_31 ( V_1 ) , V_4 ) ;
}
struct V_25 F_37 ( T_5 T_4 * V_1 , int V_4 )
{
return F_22 ( ( int V_24 * ) V_1 , F_31 ( V_1 ) , V_4 ) ;
}
struct V_25 F_38 ( T_5 T_4 * V_1 , int V_22 , int V_4 )
{
return F_16 ( ( int V_24 * ) V_1 , F_31 ( V_1 ) , V_22 , V_4 ) ;
}
struct V_25 F_39 ( int T_4 * V_26 )
{
if ( F_40 ( ! F_41 ( V_27 , V_26 , sizeof( int ) ) ) )
F_42 ( L_1 , V_26 ) ;
return (struct V_25 ) { . V_28 = - V_29 } ;
}
static int T_6 F_43 ( char * V_30 )
{
F_44 ( L_2 ) ;
return 1 ;
}
void T_6 F_45 ( void )
{
#if F_2 ()
unsigned int V_2 ;
int V_31 ;
V_31 = F_46 ( V_32 ) ;
for ( V_2 = 0 ; V_2 < V_15 ; ++ V_2 ) {
V_31 = F_47 ( V_31 , V_32 ) ;
if ( V_31 >= V_33 )
V_31 = F_46 ( V_32 ) ;
V_9 [ V_2 ] = & F_48 ( V_34 , V_31 ) ;
}
#else
F_49 ( V_16 & ( V_16 - 1 ) ) ;
F_7 ( V_16 < V_33 ) ;
F_7 ( ( unsigned long ) V_12 % V_3 != 0 ) ;
F_49 ( V_16 * sizeof( int ) > V_3 ) ;
F_49 ( ( V_3 >> 3 ) > V_16 ) ;
#endif
F_49 ( sizeof( T_1 ) != sizeof( int ) ) ;
}
