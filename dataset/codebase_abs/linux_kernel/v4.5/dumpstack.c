static unsigned long
F_1 ( unsigned long V_1 , unsigned long V_2 , unsigned long V_3 )
{
struct V_4 * V_5 ;
struct V_6 * V_7 ;
unsigned long V_8 ;
while ( 1 ) {
if ( V_1 < V_2 || V_1 > V_3 - sizeof( * V_5 ) )
return V_1 ;
V_5 = (struct V_4 * ) V_1 ;
V_8 = V_5 -> V_9 [ 8 ] ;
F_2 ( L_1 , V_8 , ( void * ) V_8 ) ;
while ( 1 ) {
V_2 = V_1 ;
V_1 = V_5 -> V_10 ;
if ( ! V_1 )
break;
if ( V_1 <= V_2 || V_1 > V_3 - sizeof( * V_5 ) )
return V_1 ;
V_5 = (struct V_4 * ) V_1 ;
V_8 = V_5 -> V_9 [ 8 ] ;
F_2 ( L_2 , V_8 , ( void * ) V_8 ) ;
}
V_1 = ( unsigned long ) ( V_5 + 1 ) ;
if ( V_1 <= V_2 || V_1 > V_3 - sizeof( * V_7 ) )
return V_1 ;
V_7 = (struct V_6 * ) V_1 ;
V_8 = V_7 -> V_11 . V_8 ;
F_2 ( L_2 , V_8 , ( void * ) V_8 ) ;
V_2 = V_1 ;
V_1 = V_7 -> V_9 [ 15 ] ;
}
}
static void F_3 ( struct V_12 * V_13 , unsigned long * V_14 )
{
const unsigned long V_15 =
V_16 + sizeof( struct V_6 ) ;
register unsigned long T_1 V_17 ( L_3 ) ;
unsigned long V_1 ;
V_1 = ( unsigned long ) V_14 ;
if ( ! V_1 )
V_1 = V_13 ? V_13 -> V_18 . V_19 : T_1 ;
F_2 ( L_4 ) ;
#ifdef F_4
V_1 = F_1 ( V_1 ,
V_20 . V_21 + V_15 - 4096 ,
V_20 . V_21 + V_15 ) ;
#endif
V_1 = F_1 ( V_1 ,
V_20 . V_22 + V_15 - V_23 ,
V_20 . V_22 + V_15 ) ;
if ( V_13 )
F_1 ( V_1 , ( unsigned long ) F_5 ( V_13 ) ,
( unsigned long ) F_5 ( V_13 ) + V_24 ) ;
else
F_1 ( V_1 , V_20 . V_25 ,
V_20 . V_25 + V_24 ) ;
if ( ! V_13 )
V_13 = V_26 ;
F_6 ( V_13 ) ;
}
void F_7 ( struct V_12 * V_13 , unsigned long * V_1 )
{
register unsigned long * T_1 V_17 ( L_3 ) ;
unsigned long * V_14 ;
int V_27 ;
if ( ! V_1 )
V_14 = V_13 ? ( unsigned long * ) V_13 -> V_18 . V_19 : T_1 ;
else
V_14 = V_1 ;
for ( V_27 = 0 ; V_27 < 20 ; V_27 ++ ) {
if ( ( ( V_28 ) V_14 & ( V_24 - 1 ) ) == 0 )
break;
if ( ( V_27 * sizeof( long ) % 32 ) == 0 )
F_2 ( L_5 , V_27 == 0 ? L_6 : L_7 ) ;
F_2 ( L_8 , * V_14 ++ ) ;
}
F_2 ( L_7 ) ;
F_3 ( V_13 , V_1 ) ;
}
static void F_8 ( struct V_6 * V_7 )
{
F_2 ( L_9 ) ;
F_2 ( L_2 , V_7 -> args [ 0 ] , ( void * ) V_7 -> args [ 0 ] ) ;
}
static inline int F_9 ( struct V_6 * V_7 , unsigned long V_29 )
{
return ( V_7 -> V_11 . V_30 & V_29 ) / ( ( ~ V_29 + 1 ) & V_29 ) ;
}
void F_10 ( struct V_6 * V_7 )
{
char * V_31 ;
V_31 = F_11 ( V_7 ) ? L_10 : L_11 ;
F_2 ( L_12 , V_31 , ( void * ) V_7 -> V_11 . V_30 , ( void * ) V_7 -> V_11 . V_8 ) ;
if ( ! F_11 ( V_7 ) )
F_2 ( L_13 , ( void * ) V_7 -> V_11 . V_8 ) ;
F_2 ( L_7 ) ;
F_2 ( L_14
L_15 , F_9 ( V_7 , V_32 ) ,
F_9 ( V_7 , V_33 ) , F_9 ( V_7 , V_34 ) ,
F_9 ( V_7 , V_35 ) , F_9 ( V_7 , V_36 ) ,
F_9 ( V_7 , V_37 ) , F_9 ( V_7 , V_38 ) ,
F_9 ( V_7 , V_39 ) , F_9 ( V_7 , V_40 ) ,
F_9 ( V_7 , V_41 ) , F_9 ( V_7 , V_42 ) ) ;
F_2 ( L_16 , F_9 ( V_7 , V_43 | V_44 ) ) ;
F_2 ( L_17 , V_31 ,
V_7 -> V_9 [ 0 ] , V_7 -> V_9 [ 1 ] , V_7 -> V_9 [ 2 ] , V_7 -> V_9 [ 3 ] ) ;
F_2 ( L_18 ,
V_7 -> V_9 [ 4 ] , V_7 -> V_9 [ 5 ] , V_7 -> V_9 [ 6 ] , V_7 -> V_9 [ 7 ] ) ;
F_2 ( L_18 ,
V_7 -> V_9 [ 8 ] , V_7 -> V_9 [ 9 ] , V_7 -> V_9 [ 10 ] , V_7 -> V_9 [ 11 ] ) ;
F_2 ( L_18 ,
V_7 -> V_9 [ 12 ] , V_7 -> V_9 [ 13 ] , V_7 -> V_9 [ 14 ] , V_7 -> V_9 [ 15 ] ) ;
F_12 ( V_7 ) ;
}
void F_13 ( struct V_6 * V_7 )
{
F_14 ( V_45 ) ;
F_10 ( V_7 ) ;
if ( ! F_11 ( V_7 ) )
F_3 ( NULL , ( unsigned long * ) V_7 -> V_9 [ 15 ] ) ;
F_8 ( V_7 ) ;
}
void F_15 ( struct V_6 * V_7 , const char * V_46 )
{
static int V_47 ;
F_16 () ;
F_17 () ;
F_18 () ;
F_19 () ;
F_20 ( & V_48 ) ;
F_21 ( 1 ) ;
F_2 ( L_19 , V_46 , V_7 -> V_49 & 0xffff ,
V_7 -> V_49 >> 17 , ++ V_47 ) ;
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
F_25 ( V_50 , V_46 , V_7 , 0 , V_7 -> V_49 & 0xffff , V_51 ) ;
F_26 () ;
F_13 ( V_7 ) ;
F_21 ( 0 ) ;
F_27 ( V_52 , V_53 ) ;
F_28 ( & V_48 ) ;
if ( F_29 () )
F_30 ( L_23 ) ;
if ( V_54 )
F_30 ( L_24 ) ;
F_31 () ;
F_32 ( V_51 ) ;
}
