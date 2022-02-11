static unsigned long
F_1 ( unsigned long V_1 , unsigned long V_2 , unsigned long V_3 )
{
struct V_4 * V_5 ;
struct V_6 * V_7 ;
unsigned long V_8 ;
while ( 1 ) {
V_1 = V_1 & V_9 ;
if ( V_1 < V_2 || V_1 > V_3 - sizeof( * V_5 ) )
return V_1 ;
V_5 = (struct V_4 * ) V_1 ;
V_8 = V_5 -> V_10 [ 8 ] & V_9 ;
F_2 ( L_1 , V_8 , ( void * ) V_8 ) ;
while ( 1 ) {
V_2 = V_1 ;
V_1 = V_5 -> V_11 & V_9 ;
if ( ! V_1 )
break;
if ( V_1 <= V_2 || V_1 > V_3 - sizeof( * V_5 ) )
return V_1 ;
V_5 = (struct V_4 * ) V_1 ;
V_8 = V_5 -> V_10 [ 8 ] & V_9 ;
F_2 ( L_2 , V_8 , ( void * ) V_8 ) ;
}
V_1 = ( unsigned long ) ( V_5 + 1 ) ;
if ( V_1 <= V_2 || V_1 > V_3 - sizeof( * V_7 ) )
return V_1 ;
V_7 = (struct V_6 * ) V_1 ;
V_8 = V_7 -> V_12 . V_8 & V_9 ;
F_2 ( L_2 , V_8 , ( void * ) V_8 ) ;
V_2 = V_1 ;
V_1 = V_7 -> V_10 [ 15 ] ;
}
}
static void F_3 ( struct V_13 * V_14 , unsigned long * V_15 )
{
const unsigned long V_16 =
V_17 + sizeof( struct V_6 ) ;
register unsigned long T_1 V_18 ( L_3 ) ;
unsigned long V_1 ;
V_1 = ( unsigned long ) V_15 ;
if ( ! V_1 )
V_1 = V_14 ? V_14 -> V_19 . V_20 : T_1 ;
F_2 ( L_4 ) ;
#ifdef F_4
V_1 = F_1 ( V_1 ,
V_21 . V_22 + V_16 - 4096 ,
V_21 . V_22 + V_16 ) ;
#endif
V_1 = F_1 ( V_1 ,
V_21 . V_23 + V_16 - V_24 ,
V_21 . V_23 + V_16 ) ;
if ( V_14 )
F_1 ( V_1 , ( unsigned long ) F_5 ( V_14 ) ,
( unsigned long ) F_5 ( V_14 ) + V_25 ) ;
else
F_1 ( V_1 , V_21 . V_26 ,
V_21 . V_26 + V_25 ) ;
if ( ! V_14 )
V_14 = V_27 ;
F_6 ( V_14 ) ;
}
void F_7 ( struct V_13 * V_14 , unsigned long * V_1 )
{
register unsigned long * T_1 V_18 ( L_3 ) ;
unsigned long * V_15 ;
int V_28 ;
if ( ! V_1 )
V_15 = V_14 ? ( unsigned long * ) V_14 -> V_19 . V_20 : T_1 ;
else
V_15 = V_1 ;
for ( V_28 = 0 ; V_28 < 20 ; V_28 ++ ) {
if ( ( ( V_29 ) V_15 & ( V_25 - 1 ) ) == 0 )
break;
if ( ( V_28 * sizeof( long ) % 32 ) == 0 )
F_2 ( L_5 , V_28 == 0 ? L_6 : L_7 ) ;
F_2 ( L_8 , * V_15 ++ ) ;
}
F_2 ( L_7 ) ;
F_3 ( V_14 , V_1 ) ;
}
static void F_8 ( struct V_6 * V_7 )
{
F_2 ( L_9 ) ;
F_2 ( L_2 , V_7 -> args [ 0 ] , ( void * ) V_7 -> args [ 0 ] ) ;
}
static inline int F_9 ( struct V_6 * V_7 , unsigned long V_30 )
{
return ( V_7 -> V_12 . V_31 & V_30 ) / ( ( ~ V_30 + 1 ) & V_30 ) ;
}
void F_10 ( struct V_6 * V_7 )
{
char * V_32 ;
V_32 = F_11 ( V_7 ) ? L_10 : L_11 ;
F_2 ( L_12 , V_32 , ( void * ) V_7 -> V_12 . V_31 , ( void * ) V_7 -> V_12 . V_8 ) ;
if ( ! F_11 ( V_7 ) )
F_2 ( L_13 , ( void * ) V_7 -> V_12 . V_8 ) ;
F_2 ( L_7 ) ;
F_2 ( L_14
L_15 , F_9 ( V_7 , V_33 ) ,
F_9 ( V_7 , V_34 ) , F_9 ( V_7 , V_35 ) ,
F_9 ( V_7 , V_36 ) , F_9 ( V_7 , V_37 ) ,
F_9 ( V_7 , V_38 ) , F_9 ( V_7 , V_39 ) ,
F_9 ( V_7 , V_40 ) , F_9 ( V_7 , V_41 ) ,
F_9 ( V_7 , V_42 ) , F_9 ( V_7 , V_43 ) ) ;
F_2 ( L_16 , F_9 ( V_7 , V_44 | V_45 ) ) ;
F_2 ( L_17 , V_32 ,
V_7 -> V_10 [ 0 ] , V_7 -> V_10 [ 1 ] , V_7 -> V_10 [ 2 ] , V_7 -> V_10 [ 3 ] ) ;
F_2 ( L_18 ,
V_7 -> V_10 [ 4 ] , V_7 -> V_10 [ 5 ] , V_7 -> V_10 [ 6 ] , V_7 -> V_10 [ 7 ] ) ;
F_2 ( L_18 ,
V_7 -> V_10 [ 8 ] , V_7 -> V_10 [ 9 ] , V_7 -> V_10 [ 10 ] , V_7 -> V_10 [ 11 ] ) ;
F_2 ( L_18 ,
V_7 -> V_10 [ 12 ] , V_7 -> V_10 [ 13 ] , V_7 -> V_10 [ 14 ] , V_7 -> V_10 [ 15 ] ) ;
F_12 ( V_7 ) ;
}
void F_13 ( struct V_6 * V_7 )
{
F_14 ( V_46 ) ;
F_10 ( V_7 ) ;
if ( ! F_11 ( V_7 ) )
F_3 ( NULL , ( unsigned long * ) V_7 -> V_10 [ 15 ] ) ;
F_8 ( V_7 ) ;
}
void F_15 ( struct V_6 * V_7 , const char * V_47 )
{
static int V_48 ;
F_16 () ;
F_17 () ;
F_18 () ;
F_19 () ;
F_20 ( & V_49 ) ;
F_21 ( 1 ) ;
F_2 ( L_19 , V_47 , V_7 -> V_50 & 0xffff ,
V_7 -> V_50 >> 17 , ++ V_48 ) ;
#ifdef F_22
F_2 ( L_20 ) ;
#endif
#ifdef F_23
F_2 ( L_21 ) ;
#endif
#ifdef F_24
F_2 ( L_22 ) ;
#endif
F_2 ( L_7 ) ;
F_25 ( V_51 , V_47 , V_7 , 0 , V_7 -> V_50 & 0xffff , V_52 ) ;
F_26 () ;
F_13 ( V_7 ) ;
F_21 ( 0 ) ;
F_27 ( V_53 , V_54 ) ;
F_28 ( & V_49 ) ;
if ( F_29 () )
F_30 ( L_23 ) ;
if ( V_55 )
F_30 ( L_24 ) ;
F_31 () ;
F_32 ( V_52 ) ;
}
