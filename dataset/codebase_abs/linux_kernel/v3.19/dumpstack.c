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
for ( V_28 = 0 ; V_28 < V_29 ; V_28 ++ ) {
if ( ( ( V_30 ) V_15 & ( V_25 - 1 ) ) == 0 )
break;
if ( ( V_28 * sizeof( long ) % 32 ) == 0 )
F_2 ( L_5 , V_28 == 0 ? L_6 : L_7 ) ;
F_2 ( LONG , * V_15 ++ ) ;
}
F_2 ( L_7 ) ;
F_3 ( V_14 , V_1 ) ;
}
static void F_8 ( struct V_6 * V_7 )
{
#ifdef F_9
F_2 ( L_8 ) ;
F_2 ( L_2 , V_7 -> args [ 0 ] , ( void * ) V_7 -> args [ 0 ] ) ;
#endif
}
static inline int F_10 ( struct V_6 * V_7 , unsigned long V_31 )
{
return ( V_7 -> V_12 . V_32 & V_31 ) / ( ( ~ V_31 + 1 ) & V_31 ) ;
}
void F_11 ( struct V_6 * V_7 )
{
char * V_33 ;
V_33 = F_12 ( V_7 ) ? L_9 : L_10 ;
F_2 ( L_11 , V_33 , ( void * ) V_7 -> V_12 . V_32 , ( void * ) V_7 -> V_12 . V_8 ) ;
if ( ! F_12 ( V_7 ) )
F_2 ( L_12 , ( void * ) V_7 -> V_12 . V_8 ) ;
F_2 ( L_7 ) ;
F_2 ( L_13
L_14 , F_10 ( V_7 , V_34 ) ,
F_10 ( V_7 , V_35 ) , F_10 ( V_7 , V_36 ) ,
F_10 ( V_7 , V_37 ) , F_10 ( V_7 , V_38 ) ,
F_10 ( V_7 , V_39 ) , F_10 ( V_7 , V_40 ) ,
F_10 ( V_7 , V_41 ) , F_10 ( V_7 , V_42 ) ,
F_10 ( V_7 , V_43 ) , F_10 ( V_7 , V_44 ) ) ;
#ifdef F_9
F_2 ( L_15 , F_10 ( V_7 , V_45 | V_46 ) ) ;
#endif
F_2 ( L_16 V_47 , V_33 ,
V_7 -> V_10 [ 0 ] , V_7 -> V_10 [ 1 ] , V_7 -> V_10 [ 2 ] , V_7 -> V_10 [ 3 ] ) ;
F_2 ( L_17 V_47 ,
V_7 -> V_10 [ 4 ] , V_7 -> V_10 [ 5 ] , V_7 -> V_10 [ 6 ] , V_7 -> V_10 [ 7 ] ) ;
F_2 ( L_17 V_47 ,
V_7 -> V_10 [ 8 ] , V_7 -> V_10 [ 9 ] , V_7 -> V_10 [ 10 ] , V_7 -> V_10 [ 11 ] ) ;
F_2 ( L_17 V_47 ,
V_7 -> V_10 [ 12 ] , V_7 -> V_10 [ 13 ] , V_7 -> V_10 [ 14 ] , V_7 -> V_10 [ 15 ] ) ;
F_13 ( V_7 ) ;
}
void F_14 ( struct V_6 * V_7 )
{
F_15 ( V_48 ) ;
F_11 ( V_7 ) ;
if ( ! F_12 ( V_7 ) )
F_3 ( NULL , ( unsigned long * ) V_7 -> V_10 [ 15 ] ) ;
F_8 ( V_7 ) ;
}
void F_16 ( struct V_6 * V_7 , const char * V_49 )
{
static int V_50 ;
F_17 () ;
F_18 () ;
F_19 () ;
F_20 () ;
F_21 ( & V_51 ) ;
F_22 ( 1 ) ;
F_2 ( L_18 , V_49 , V_7 -> V_52 & 0xffff ,
V_7 -> V_52 >> 17 , ++ V_50 ) ;
#ifdef F_23
F_2 ( L_19 ) ;
#endif
#ifdef F_24
F_2 ( L_20 ) ;
#endif
#ifdef F_25
F_2 ( L_21 ) ;
#endif
F_2 ( L_7 ) ;
F_26 ( V_53 , V_49 , V_7 , 0 , V_7 -> V_52 & 0xffff , V_54 ) ;
F_27 () ;
F_14 ( V_7 ) ;
F_22 ( 0 ) ;
F_28 ( V_55 , V_56 ) ;
F_29 ( & V_51 ) ;
if ( F_30 () )
F_31 ( L_22 ) ;
if ( V_57 )
F_31 ( L_23 ) ;
F_32 () ;
F_33 ( V_54 ) ;
}
