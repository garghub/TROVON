void T_1 F_1 ( int V_1 )
{
#ifndef F_2
struct V_2 * V_3 = V_4 + V_1 ;
int V_5 , V_6 ;
V_5 = ( unsigned long ) F_3 ( V_3 -> V_7 ) >> F_4 () ;
V_6 = ( unsigned long ) F_3 ( V_3 -> V_7 + V_3 -> V_8 - 1 ) >> F_4 () ;
for (; V_5 <= V_6 ; V_5 ++ ) {
if ( V_9 [ V_5 ] )
F_5 ( L_1 , V_5 , V_1 ) ;
V_9 [ V_5 ] = V_10 + V_1 ;
}
#endif
V_10 [ V_1 ] . V_11 = V_12 + V_1 ;
F_6 ( V_1 ) ;
}
void T_1 F_7 ( void )
{
#define F_8 ( T_2 ) ((unsigned long) (x))
#define F_9 ( T_3 , T_4 ) UL(b), UL(t), (UL(t) - UL(b)) >> 10
#define F_10 ( T_3 , T_4 ) UL(b), UL(t), (UL(t) - UL(b)) >> 20
#define F_11 ( T_3 , T_4 ) b, t, DIV_ROUND_UP(((t) - (b)), 1024)
F_12 ( L_2
L_3
L_4
L_5
L_6
L_7 L_8 L_9
L_10 L_8 L_9
L_11 L_8 L_9
L_12 L_8 L_9 ,
F_9 ( V_13 , V_13 + 256 ) ,
F_10 ( V_14 , V_15 ) ,
F_10 ( V_16 , V_17 ) ,
F_10 ( V_18 , ( unsigned long ) V_19 ) ,
F_11 ( V_20 , V_21 ) ,
F_11 ( V_22 , V_23 ) ,
F_11 ( V_24 , V_25 ) ,
F_11 ( V_26 , V_27 ) ) ;
}
void T_1 F_13 ( void )
{
T_5 * V_28 ;
int V_29 = 0 ;
int V_30 = 0 ;
int V_31 = 0 ;
int V_5 ;
V_32 = V_33 = 0 ;
F_14 (pgdat) {
V_33 += V_28 -> V_34 ;
V_32 += F_15 ( V_28 ) ;
for ( V_5 = 0 ; V_5 < V_28 -> V_35 ; V_5 ++ ) {
struct V_36 * V_36 = V_28 -> V_37 + V_5 ;
char * V_7 = F_16 ( V_36 ) ;
if ( ! F_17 ( V_36 ) )
continue;
if ( V_7 >= V_38 &&
V_7 < V_23 )
V_29 ++ ;
else if ( V_7 >= V_20 &&
V_7 < V_21 )
V_31 ++ ;
else
V_30 ++ ;
}
}
#if ! F_18 ( V_39 ) && ! F_18 ( V_40 )
F_19 ( ( unsigned long ) V_41 ) ;
for ( V_5 = 0 ; V_5 < V_42 ; V_5 ++ ) {
if ( F_20 ( V_41 [ V_5 ] ) )
F_19 ( F_21 ( V_41 [ V_5 ] ) ) ;
}
if ( V_43 )
F_19 ( ( unsigned long ) V_43 ) ;
#endif
F_5 ( L_13 ,
F_22 () << ( V_44 - 10 ) ,
V_32 << ( V_44 - 10 ) ,
V_29 << ( V_44 - 10 ) ,
V_30 << ( V_44 - 10 ) ,
V_31 << ( V_44 - 10 ) ) ;
F_7 () ;
}
void F_23 ( unsigned long V_45 , unsigned long V_6 )
{
int V_46 = 0 ;
for (; V_45 < V_6 ; V_45 += V_47 ) {
F_24 ( F_25 ( V_45 ) ) ;
F_26 ( F_25 ( V_45 ) ) ;
F_27 ( V_45 ) ;
V_32 ++ ;
V_46 ++ ;
}
F_5 ( L_14 , V_46 ) ;
}
