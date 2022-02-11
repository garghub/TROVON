void
F_1 ( unsigned int V_1 , unsigned int V_2 , void * V_3 , void * * V_4 )
{
unsigned long * V_5 , * V_6 , * V_7 , * V_8 ;
V_5 = ( unsigned long * ) V_4 [ 0 ] ;
if ( V_1 == 1 ) {
V_9 -> V_10 ( V_2 , V_3 , V_5 ) ;
return;
}
V_6 = ( unsigned long * ) V_4 [ 1 ] ;
if ( V_1 == 2 ) {
V_9 -> V_11 ( V_2 , V_3 , V_5 , V_6 ) ;
return;
}
V_7 = ( unsigned long * ) V_4 [ 2 ] ;
if ( V_1 == 3 ) {
V_9 -> V_12 ( V_2 , V_3 , V_5 , V_6 , V_7 ) ;
return;
}
V_8 = ( unsigned long * ) V_4 [ 3 ] ;
V_9 -> V_13 ( V_2 , V_3 , V_5 , V_6 , V_7 , V_8 ) ;
}
static void
F_2 ( struct V_14 * V_15 , void * V_16 , void * V_17 )
{
int V_18 ;
unsigned long V_19 ;
int V_20 , V_21 , V_22 ;
V_15 -> V_23 = V_24 ;
V_24 = V_15 ;
V_22 = 0 ;
for ( V_20 = 0 ; V_20 < 5 ; V_20 ++ ) {
V_19 = V_25 ;
V_21 = 0 ;
while ( V_25 == V_19 ) {
F_3 () ;
V_15 -> V_10 ( V_26 , V_16 , V_17 ) ;
F_3 () ;
V_21 ++ ;
F_3 () ;
}
if ( V_21 > V_22 )
V_22 = V_21 ;
}
V_18 = V_22 * ( V_27 * V_26 / 1024 ) ;
V_15 -> V_18 = V_18 ;
F_4 ( V_28 L_1 , V_15 -> V_29 ,
V_18 / 1000 , V_18 % 1000 ) ;
}
static int T_1
F_5 ( void )
{
void * V_16 , * V_17 ;
struct V_14 * V_30 , * V_31 ;
V_16 = ( void * ) F_6 ( V_32 | V_33 , 2 ) ;
if ( ! V_16 ) {
F_4 ( V_34 L_2 ) ;
return - V_35 ;
}
V_17 = V_16 + 2 * V_36 + V_26 ;
V_31 = NULL ;
#ifdef F_7
V_31 = F_7 ( V_31 ) ;
#endif
#define F_8 ( T_2 ) do_xor_speed((templ), b1, b2)
if ( V_31 ) {
F_4 ( V_28 L_3
L_4 ,
V_31 -> V_29 ) ;
F_8 ( V_31 ) ;
} else {
F_4 ( V_28 L_5 ) ;
V_37 ;
V_31 = V_24 ;
for ( V_30 = V_31 ; V_30 ; V_30 = V_30 -> V_23 )
if ( V_30 -> V_18 > V_31 -> V_18 )
V_31 = V_30 ;
}
F_4 ( V_28 L_6 ,
V_31 -> V_29 , V_31 -> V_18 / 1000 , V_31 -> V_18 % 1000 ) ;
#undef F_8
F_9 ( ( unsigned long ) V_16 , 2 ) ;
V_9 = V_31 ;
return 0 ;
}
static T_3 void F_10 ( void ) { }
