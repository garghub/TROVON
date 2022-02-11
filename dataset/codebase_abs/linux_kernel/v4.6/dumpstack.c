static unsigned long
F_1 ( T_1 V_1 , void * V_2 , unsigned long V_3 ,
unsigned long V_4 , unsigned long V_5 )
{
struct V_6 * V_7 ;
struct V_8 * V_9 ;
while ( 1 ) {
if ( V_3 < V_4 || V_3 > V_5 - sizeof( * V_7 ) )
return V_3 ;
V_7 = (struct V_6 * ) V_3 ;
while ( 1 ) {
if ( V_1 ( V_2 , V_7 -> V_10 [ 8 ] ) )
return V_3 ;
V_4 = V_3 ;
V_3 = V_7 -> V_11 ;
if ( ! V_3 )
break;
if ( V_3 <= V_4 || V_3 > V_5 - sizeof( * V_7 ) )
return V_3 ;
V_7 = (struct V_6 * ) V_3 ;
}
V_3 = ( unsigned long ) ( V_7 + 1 ) ;
if ( V_3 <= V_4 || V_3 > V_5 - sizeof( * V_9 ) )
return V_3 ;
V_9 = (struct V_8 * ) V_3 ;
if ( ! F_2 ( V_9 ) ) {
if ( V_1 ( V_2 , V_9 -> V_12 . V_13 ) )
return V_3 ;
}
V_4 = V_3 ;
V_3 = V_9 -> V_10 [ 15 ] ;
}
}
void F_3 ( T_1 V_1 , void * V_2 , struct V_14 * V_15 ,
unsigned long V_3 )
{
unsigned long V_16 ;
V_16 = V_17 + sizeof( struct V_8 ) ;
#ifdef F_4
V_3 = F_1 ( V_1 , V_2 , V_3 ,
V_18 . V_19 + V_16 - 4096 ,
V_18 . V_19 + V_16 ) ;
#endif
V_3 = F_1 ( V_1 , V_2 , V_3 ,
V_18 . V_20 + V_16 - V_21 ,
V_18 . V_20 + V_16 ) ;
if ( V_15 )
F_1 ( V_1 , V_2 , V_3 ,
( unsigned long ) F_5 ( V_15 ) ,
( unsigned long ) F_5 ( V_15 ) + V_22 ) ;
else
F_1 ( V_1 , V_2 , V_3 ,
V_18 . V_23 ,
V_18 . V_23 + V_22 ) ;
}
static int F_6 ( void * V_2 , unsigned long V_24 )
{
F_7 ( L_1 , V_24 , ( void * ) V_24 ) ;
return 0 ;
}
static void F_8 ( struct V_14 * V_15 , unsigned long V_3 )
{
if ( ! V_3 )
V_3 = V_15 ? V_15 -> V_25 . V_26 : F_9 () ;
F_7 ( L_2 ) ;
F_3 ( F_6 , NULL , V_15 , V_3 ) ;
if ( ! V_15 )
V_15 = V_27 ;
F_10 ( V_15 ) ;
}
void F_11 ( struct V_14 * V_15 , unsigned long * V_3 )
{
unsigned long * V_28 ;
int V_29 ;
V_28 = V_3 ;
if ( ! V_28 ) {
if ( ! V_15 )
V_28 = ( unsigned long * ) F_9 () ;
else
V_28 = ( unsigned long * ) V_15 -> V_25 . V_26 ;
}
for ( V_29 = 0 ; V_29 < 20 ; V_29 ++ ) {
if ( ( ( V_30 ) V_28 & ( V_22 - 1 ) ) == 0 )
break;
if ( ( V_29 * sizeof( long ) % 32 ) == 0 )
F_7 ( L_3 , V_29 == 0 ? L_4 : L_5 ) ;
F_7 ( L_6 , * V_28 ++ ) ;
}
F_7 ( L_5 ) ;
F_8 ( V_15 , ( unsigned long ) V_3 ) ;
}
static void F_12 ( struct V_8 * V_9 )
{
F_7 ( L_7 ) ;
F_7 ( L_8 , V_9 -> args [ 0 ] , ( void * ) V_9 -> args [ 0 ] ) ;
}
void F_13 ( struct V_8 * V_9 )
{
struct V_31 * V_12 = & V_31 ( V_9 -> V_12 ) ;
char * V_32 ;
V_32 = F_2 ( V_9 ) ? L_9 : L_10 ;
F_7 ( L_11 , V_32 , ( void * ) V_9 -> V_12 . V_33 , ( void * ) V_9 -> V_12 . V_13 ) ;
if ( ! F_2 ( V_9 ) )
F_7 ( L_12 , ( void * ) V_9 -> V_12 . V_13 ) ;
F_7 ( L_5 ) ;
F_7 ( L_13
L_14 , V_12 -> V_34 , V_12 -> V_35 , V_12 -> V_29 , V_12 -> V_36 ,
V_12 -> V_37 , V_12 -> V_38 , V_12 -> V_39 , V_12 -> V_40 , V_12 -> V_41 , V_12 -> V_42 , V_12 -> V_43 ) ;
F_7 ( L_15 , V_12 -> V_44 , V_12 -> V_45 ) ;
F_7 ( L_16 , V_32 ,
V_9 -> V_10 [ 0 ] , V_9 -> V_10 [ 1 ] , V_9 -> V_10 [ 2 ] , V_9 -> V_10 [ 3 ] ) ;
F_7 ( L_17 ,
V_9 -> V_10 [ 4 ] , V_9 -> V_10 [ 5 ] , V_9 -> V_10 [ 6 ] , V_9 -> V_10 [ 7 ] ) ;
F_7 ( L_17 ,
V_9 -> V_10 [ 8 ] , V_9 -> V_10 [ 9 ] , V_9 -> V_10 [ 10 ] , V_9 -> V_10 [ 11 ] ) ;
F_7 ( L_17 ,
V_9 -> V_10 [ 12 ] , V_9 -> V_10 [ 13 ] , V_9 -> V_10 [ 14 ] , V_9 -> V_10 [ 15 ] ) ;
F_14 ( V_9 ) ;
}
void F_15 ( struct V_8 * V_9 )
{
F_16 ( V_46 ) ;
F_13 ( V_9 ) ;
if ( ! F_2 ( V_9 ) )
F_8 ( NULL , V_9 -> V_10 [ 15 ] ) ;
F_12 ( V_9 ) ;
}
void F_17 ( struct V_8 * V_9 , const char * V_47 )
{
static int V_48 ;
F_18 () ;
F_19 () ;
F_20 () ;
F_21 () ;
F_22 ( & V_49 ) ;
F_23 ( 1 ) ;
F_7 ( L_18 , V_47 , V_9 -> V_50 & 0xffff ,
V_9 -> V_50 >> 17 , ++ V_48 ) ;
#ifdef F_24
F_7 ( L_19 ) ;
#endif
#ifdef F_25
F_7 ( L_20 ) ;
#endif
if ( F_26 () )
F_7 ( L_21 ) ;
F_7 ( L_5 ) ;
F_27 ( V_51 , V_47 , V_9 , 0 , V_9 -> V_50 & 0xffff , V_52 ) ;
F_28 () ;
F_15 ( V_9 ) ;
F_23 ( 0 ) ;
F_29 ( V_53 , V_54 ) ;
F_30 ( & V_49 ) ;
if ( F_31 () )
F_32 ( L_22 ) ;
if ( V_55 )
F_32 ( L_23 ) ;
F_33 () ;
F_34 ( V_52 ) ;
}
