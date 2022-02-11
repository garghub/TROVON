int F_1 ( struct V_1 * V_2 )
{
void * V_3 ;
const unsigned long * V_4 ;
V_4 = ( unsigned long * ) & V_5 ;
V_3 = F_2 ( V_2 -> V_6 ) ;
memcpy ( ( void * ) V_3 , ( const void * ) V_4 [ 0 ] ,
V_7 ) ;
F_3 ( ( unsigned long ) V_3 ,
( unsigned long ) V_3 + V_7 ) ;
V_8 = V_2 ;
return 0 ;
}
void F_4 ( struct V_1 * V_2 )
{
}
static void F_5 ( struct V_9 * V_10 , void * V_11 )
{
struct V_1 * V_2 = V_11 ;
T_1 V_12 ;
void * V_13 = F_6 () ;
unsigned long V_14 = ( unsigned long ) F_2 ( V_2 -> V_6 ) ;
int V_15 ;
T_2 V_16 , V_17 ;
T_3 * V_18 = ( T_3 * ) V_19 ;
F_7 ( ! V_2 ) ;
if ( V_2 -> type == V_20 ) {
F_8 () ;
V_21 -> V_22 . V_23 = ( V_24 ) V_10 -> V_25 - 16 ;
V_16 = F_9 ( V_18 -> V_16 ) ;
V_17 = F_9 ( F_10 ( V_26 ) ) ;
F_11 ( V_27 , V_16 , V_17 , 0 , V_16 , V_17 , 0 ) ;
} else {
F_11 ( V_27 , 0 , 0 , 0 , 0 , 0 , 0 ) ;
}
F_11 ( V_28 , 0 , 0 , 0 , 0 , 0 , 0 ) ;
F_12 () ;
F_13 ( V_29 , 1 << 16 ) ;
F_13 ( V_30 , 1 << 16 ) ;
F_14 ( 1 << 16 ) ;
F_15 ( 1 << 16 ) ;
F_16 ( 1 << 16 ) ;
for ( V_15 = 0 ; V_15 < 16 ; V_15 ++ )
F_17 () ;
F_13 ( V_31 , 0 ) ;
F_18 () ;
while ( F_19 () != V_32 )
F_17 () ;
F_20 () ;
V_12 = ( T_1 ) & V_14 ;
(* V_12)( V_2 -> V_33 , V_2 -> V_34 , V_35 ,
F_21 ( ( unsigned long ) V_13 ) ) ;
F_22 () ;
}
void F_23 ( struct V_1 * V_2 )
{
F_7 ( ! V_2 ) ;
F_24 ( F_5 , V_2 ) ;
for(; ; ) ;
}
void F_25 ( void )
{
#if F_26 ( V_36 ) || F_26 ( V_37 )
F_27 ( V_38 ) ;
F_28 ( V_38 , V_39 ) ;
#endif
#ifdef F_29
F_27 ( V_40 ) ;
F_28 ( V_40 , V_41 ) ;
F_30 ( V_42 ) ;
F_31 ( V_42 , V_43 ) ;
F_31 ( V_42 , V_44 ) ;
#endif
#ifdef F_32
F_33 ( V_45 ) ;
#elif F_26 ( V_46 )
F_33 ( V_47 ) ;
#endif
}
unsigned long F_34 ( void )
{
return F_9 ( ( unsigned long ) ( char * ) & V_48 ) ;
}
