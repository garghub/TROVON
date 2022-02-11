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
if ( V_1 ( V_2 , V_7 -> V_10 [ 8 ] , 0 ) )
return V_3 ;
while ( 1 ) {
V_4 = V_3 ;
V_3 = V_7 -> V_11 ;
if ( ! V_3 )
break;
if ( V_3 <= V_4 || V_3 > V_5 - sizeof( * V_7 ) )
return V_3 ;
V_7 = (struct V_6 * ) V_3 ;
if ( V_1 ( V_2 , V_7 -> V_10 [ 8 ] , 1 ) )
return V_3 ;
}
V_3 = ( unsigned long ) ( V_7 + 1 ) ;
if ( V_3 <= V_4 || V_3 > V_5 - sizeof( * V_9 ) )
return V_3 ;
V_9 = (struct V_8 * ) V_3 ;
if ( ! F_2 ( V_9 ) ) {
if ( V_1 ( V_2 , V_9 -> V_12 . V_13 , 1 ) )
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
V_18 . V_19 + V_16 - V_20 ,
V_18 . V_19 + V_16 ) ;
#endif
V_3 = F_1 ( V_1 , V_2 , V_3 ,
V_18 . V_21 + V_16 - V_22 ,
V_18 . V_21 + V_16 ) ;
V_15 = V_15 ? : V_23 ;
F_1 ( V_1 , V_2 , V_3 ,
( unsigned long ) F_5 ( V_15 ) ,
( unsigned long ) F_5 ( V_15 ) + V_24 ) ;
}
static int F_6 ( void * V_2 , unsigned long V_25 , int V_26 )
{
if ( V_26 )
F_7 ( L_1 , V_25 , ( void * ) V_25 ) ;
else
F_7 ( L_2 , V_25 , ( void * ) V_25 ) ;
return 0 ;
}
void F_8 ( struct V_14 * V_15 , unsigned long * V_27 )
{
unsigned long V_3 = ( unsigned long ) V_27 ;
if ( ! V_3 )
V_3 = V_15 ? V_15 -> V_28 . V_29 : F_9 () ;
F_7 ( L_3 ) ;
F_3 ( F_6 , NULL , V_15 , V_3 ) ;
if ( ! V_15 )
V_15 = V_23 ;
F_10 ( V_15 ) ;
}
static void F_11 ( struct V_8 * V_9 )
{
F_7 ( L_4 ) ;
F_7 ( L_5 , V_9 -> args [ 0 ] , ( void * ) V_9 -> args [ 0 ] ) ;
}
void F_12 ( struct V_8 * V_9 )
{
struct V_30 * V_12 = & V_30 ( V_9 -> V_12 ) ;
char * V_31 ;
V_31 = F_2 ( V_9 ) ? L_6 : L_7 ;
F_7 ( L_8 , V_31 , ( void * ) V_9 -> V_12 . V_32 , ( void * ) V_9 -> V_12 . V_13 ) ;
if ( ! F_2 ( V_9 ) )
F_13 ( L_9 , ( void * ) V_9 -> V_12 . V_13 ) ;
F_13 ( L_10 ) ;
F_7 ( L_11
L_12 , V_12 -> V_33 , V_12 -> V_34 , V_12 -> V_35 , V_12 -> V_36 ,
V_12 -> V_37 , V_12 -> V_38 , V_12 -> V_39 , V_12 -> V_40 , V_12 -> V_41 , V_12 -> V_42 , V_12 -> V_43 ) ;
F_13 ( L_13 , V_12 -> V_44 , V_12 -> V_45 ) ;
F_7 ( L_14 , V_31 ,
V_9 -> V_10 [ 0 ] , V_9 -> V_10 [ 1 ] , V_9 -> V_10 [ 2 ] , V_9 -> V_10 [ 3 ] ) ;
F_7 ( L_15 ,
V_9 -> V_10 [ 4 ] , V_9 -> V_10 [ 5 ] , V_9 -> V_10 [ 6 ] , V_9 -> V_10 [ 7 ] ) ;
F_7 ( L_15 ,
V_9 -> V_10 [ 8 ] , V_9 -> V_10 [ 9 ] , V_9 -> V_10 [ 10 ] , V_9 -> V_10 [ 11 ] ) ;
F_7 ( L_15 ,
V_9 -> V_10 [ 12 ] , V_9 -> V_10 [ 13 ] , V_9 -> V_10 [ 14 ] , V_9 -> V_10 [ 15 ] ) ;
F_14 ( V_9 ) ;
}
void F_15 ( struct V_8 * V_9 )
{
F_16 ( V_46 ) ;
F_12 ( V_9 ) ;
if ( ! F_2 ( V_9 ) )
F_8 ( NULL , ( unsigned long * ) V_9 -> V_10 [ 15 ] ) ;
F_11 ( V_9 ) ;
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
F_7 ( L_16 , V_47 , V_9 -> V_50 & 0xffff ,
V_9 -> V_50 >> 17 , ++ V_48 ) ;
#ifdef F_24
F_13 ( L_17 ) ;
#endif
#ifdef F_25
F_13 ( L_18 ) ;
#endif
if ( F_26 () )
F_13 ( L_19 ) ;
F_13 ( L_10 ) ;
F_27 ( V_51 , V_47 , V_9 , 0 , V_9 -> V_50 & 0xffff , V_52 ) ;
F_28 () ;
F_15 ( V_9 ) ;
F_23 ( 0 ) ;
F_29 ( V_53 , V_54 ) ;
F_30 ( & V_49 ) ;
if ( F_31 () )
F_32 ( L_20 ) ;
if ( V_55 )
F_32 ( L_21 ) ;
F_33 () ;
F_34 ( V_52 ) ;
}
