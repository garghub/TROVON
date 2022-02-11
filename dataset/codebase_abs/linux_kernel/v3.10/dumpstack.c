static unsigned long
F_1 ( unsigned long V_1 , unsigned long V_2 , unsigned long V_3 )
{
struct V_4 * V_5 ;
struct V_6 * V_7 ;
while ( 1 ) {
V_1 = V_1 & V_8 ;
if ( V_1 < V_2 || V_1 > V_3 - sizeof( * V_5 ) )
return V_1 ;
V_5 = (struct V_4 * ) V_1 ;
F_2 ( L_1 , V_5 -> V_9 [ 8 ] & V_8 ) ;
F_3 ( L_2 , V_5 -> V_9 [ 8 ] & V_8 ) ;
while ( 1 ) {
V_2 = V_1 ;
V_1 = V_5 -> V_10 & V_8 ;
if ( ! V_1 )
break;
if ( V_1 <= V_2 || V_1 > V_3 - sizeof( * V_5 ) )
return V_1 ;
V_5 = (struct V_4 * ) V_1 ;
F_2 ( L_3 , V_5 -> V_9 [ 8 ] & V_8 ) ;
F_3 ( L_4 , V_5 -> V_9 [ 8 ] & V_8 ) ;
}
V_1 = ( unsigned long ) ( V_5 + 1 ) ;
if ( V_1 <= V_2 || V_1 > V_3 - sizeof( * V_7 ) )
return V_1 ;
V_7 = (struct V_6 * ) V_1 ;
F_2 ( L_3 , V_7 -> V_11 . V_12 & V_8 ) ;
F_3 ( L_4 , V_7 -> V_11 . V_12 & V_8 ) ;
V_2 = V_1 ;
V_1 = V_7 -> V_9 [ 15 ] ;
}
}
static void F_4 ( struct V_13 * V_14 , unsigned long * V_15 )
{
const unsigned long V_16 =
V_17 + sizeof( struct V_6 ) ;
register unsigned long T_1 V_18 ( L_5 ) ;
unsigned long V_1 ;
V_1 = ( unsigned long ) V_15 ;
if ( ! V_1 )
V_1 = V_14 ? V_14 -> V_19 . V_20 : T_1 ;
F_2 ( L_6 ) ;
#ifdef F_5
V_1 = F_1 ( V_1 ,
V_21 . V_22 + V_16 - 4096 ,
V_21 . V_22 + V_16 ) ;
#endif
V_1 = F_1 ( V_1 ,
V_21 . V_23 + V_16 - V_24 ,
V_21 . V_23 + V_16 ) ;
if ( V_14 )
F_1 ( V_1 , ( unsigned long ) F_6 ( V_14 ) ,
( unsigned long ) F_6 ( V_14 ) + V_25 ) ;
else
F_1 ( V_1 , V_21 . V_26 ,
V_21 . V_26 + V_25 ) ;
if ( ! V_14 )
V_14 = V_27 ;
F_7 ( V_14 ) ;
}
void F_8 ( struct V_13 * V_14 , unsigned long * V_1 )
{
register unsigned long * T_1 V_18 ( L_5 ) ;
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
F_2 ( L_7 , V_28 == 0 ? L_8 : L_9 ) ;
F_2 ( LONG , * V_15 ++ ) ;
}
F_2 ( L_9 ) ;
F_4 ( V_14 , V_1 ) ;
}
static void F_9 ( struct V_6 * V_7 )
{
#ifdef F_10
F_2 ( L_10 ) ;
F_2 ( L_3 , V_7 -> args [ 0 ] & V_8 ) ;
F_3 ( L_4 , V_7 -> args [ 0 ] & V_8 ) ;
#endif
}
static inline int F_11 ( struct V_6 * V_7 , unsigned long V_31 )
{
return ( V_7 -> V_11 . V_32 & V_31 ) / ( ( ~ V_31 + 1 ) & V_31 ) ;
}
void F_12 ( struct V_6 * V_7 )
{
char * V_33 ;
V_33 = F_13 ( V_7 ) ? L_11 : L_12 ;
F_2 ( L_13 ,
V_33 , ( void * ) V_7 -> V_11 . V_32 ,
( void * ) V_7 -> V_11 . V_12 ) ;
F_3 ( L_14 , V_7 -> V_11 . V_12 & V_8 ) ;
F_2 ( L_15
L_16 , F_11 ( V_7 , V_34 ) ,
F_11 ( V_7 , V_35 ) , F_11 ( V_7 , V_36 ) ,
F_11 ( V_7 , V_37 ) , F_11 ( V_7 , V_38 ) ,
F_11 ( V_7 , V_39 ) , F_11 ( V_7 , V_40 ) ,
F_11 ( V_7 , V_41 ) , F_11 ( V_7 , V_42 ) ,
F_11 ( V_7 , V_43 ) , F_11 ( V_7 , V_44 ) ) ;
#ifdef F_10
F_2 ( L_17 , F_11 ( V_7 , V_45 | V_46 ) ) ;
#endif
F_2 ( L_18 V_47 , V_33 ,
V_7 -> V_9 [ 0 ] , V_7 -> V_9 [ 1 ] , V_7 -> V_9 [ 2 ] , V_7 -> V_9 [ 3 ] ) ;
F_2 ( L_19 V_47 ,
V_7 -> V_9 [ 4 ] , V_7 -> V_9 [ 5 ] , V_7 -> V_9 [ 6 ] , V_7 -> V_9 [ 7 ] ) ;
F_2 ( L_19 V_47 ,
V_7 -> V_9 [ 8 ] , V_7 -> V_9 [ 9 ] , V_7 -> V_9 [ 10 ] , V_7 -> V_9 [ 11 ] ) ;
F_2 ( L_19 V_47 ,
V_7 -> V_9 [ 12 ] , V_7 -> V_9 [ 13 ] , V_7 -> V_9 [ 14 ] , V_7 -> V_9 [ 15 ] ) ;
F_14 ( V_7 ) ;
}
void F_15 ( struct V_6 * V_7 )
{
F_16 ( V_48 ) ;
F_12 ( V_7 ) ;
if ( ! F_13 ( V_7 ) )
F_4 ( NULL , ( unsigned long * ) V_7 -> V_9 [ 15 ] ) ;
F_9 ( V_7 ) ;
}
void F_17 ( struct V_6 * V_7 , const char * V_49 )
{
static int V_50 ;
F_18 () ;
F_19 () ;
F_20 () ;
F_21 () ;
F_22 ( & V_51 ) ;
F_23 ( 1 ) ;
F_2 ( L_20 , V_49 , V_7 -> V_52 & 0xffff , ++ V_50 ) ;
#ifdef F_24
F_2 ( L_21 ) ;
#endif
#ifdef F_25
F_2 ( L_22 ) ;
#endif
#ifdef F_26
F_2 ( L_23 ) ;
#endif
F_2 ( L_9 ) ;
F_27 ( V_53 , V_49 , V_7 , 0 , V_7 -> V_52 & 0xffff , V_54 ) ;
F_28 () ;
F_15 ( V_7 ) ;
F_23 ( 0 ) ;
F_29 ( V_55 , V_56 ) ;
F_30 ( & V_51 ) ;
if ( F_31 () )
F_32 ( L_24 ) ;
if ( V_57 )
F_32 ( L_25 ) ;
F_33 () ;
F_34 ( V_54 ) ;
}
