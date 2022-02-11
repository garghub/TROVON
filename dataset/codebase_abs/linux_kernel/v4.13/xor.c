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
static void T_1
F_2 ( struct V_14 * V_15 , void * V_16 , void * V_17 )
{
int V_18 ;
unsigned long V_19 , V_20 ;
int V_21 , V_22 , V_23 ;
V_15 -> V_24 = V_25 ;
V_25 = V_15 ;
F_3 () ;
V_23 = 0 ;
for ( V_21 = 0 ; V_21 < 5 ; V_21 ++ ) {
V_20 = V_26 ;
V_22 = 0 ;
while ( ( V_19 = V_26 ) == V_20 )
F_4 () ;
while ( F_5 ( V_26 , V_19 + 1 ) ) {
F_6 () ;
V_15 -> V_10 ( V_27 , V_16 , V_17 ) ;
F_6 () ;
V_22 ++ ;
F_6 () ;
}
if ( V_22 > V_23 )
V_23 = V_22 ;
}
F_7 () ;
V_18 = V_23 * ( V_28 * V_27 / 1024 ) ;
V_15 -> V_18 = V_18 ;
F_8 ( V_29 L_1 , V_15 -> V_30 ,
V_18 / 1000 , V_18 % 1000 ) ;
}
static int T_1
F_9 ( void )
{
void * V_16 , * V_17 ;
struct V_14 * V_31 , * V_32 ;
V_32 = F_10 ( NULL ) ;
if ( V_32 ) {
F_8 ( V_29 L_2
L_3 ,
V_32 -> V_30 ) ;
goto V_33;
}
V_16 = ( void * ) F_11 ( V_34 | V_35 , 2 ) ;
if ( ! V_16 ) {
F_8 ( V_36 L_4 ) ;
return - V_37 ;
}
V_17 = V_16 + 2 * V_38 + V_27 ;
#define F_12 ( T_2 ) do_xor_speed((templ), b1, b2)
F_8 ( V_29 L_5 ) ;
V_39 ;
V_32 = V_25 ;
for ( V_31 = V_32 ; V_31 ; V_31 = V_31 -> V_24 )
if ( V_31 -> V_18 > V_32 -> V_18 )
V_32 = V_31 ;
F_8 ( V_29 L_6 ,
V_32 -> V_30 , V_32 -> V_18 / 1000 , V_32 -> V_18 % 1000 ) ;
#undef F_12
F_13 ( ( unsigned long ) V_16 , 2 ) ;
V_33:
V_9 = V_32 ;
return 0 ;
}
static T_3 void F_14 ( void ) { }
