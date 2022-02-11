static inline unsigned long F_1 ( unsigned int V_1 )
{
unsigned long V_2 , V_3 ;
unsigned long V_4 ;
V_2 = ( V_1 / V_5 ) ^ V_6 ;
V_3 = ( V_1 + V_7 ) % V_5 ;
V_4 = ( V_2 << V_8 ) + ( V_3 * V_9 ) ;
V_4 = ( V_4 & 0xffffUL ) | ( ( V_4 & ~ 0xffffUL ) << 16 ) ;
V_4 += V_10 ;
return V_4 ;
}
static void F_2 ( void )
{
unsigned long rand ;
if ( ! F_3 ( & rand ) ) {
rand = F_4 () ;
rand *= 0xc345c6b72fd16123UL ;
}
V_7 = rand % V_5 ;
V_6 = ( rand / V_5 )
& ( V_11 - 1 ) ;
}
void T_1 F_5 ( void )
{
T_2 * V_12 ;
T_3 * V_13 ;
V_12 = & V_14 [ F_6 ( V_10 ) ] ;
V_13 = F_7 ( & V_15 , V_12 , V_10 ) ;
F_8 ( & V_15 , V_13 , V_16 ) ;
F_2 () ;
F_9 ( 0 ) ;
}
void F_9 ( int V_1 )
{
unsigned int V_2 ;
unsigned long V_4 ;
T_4 V_17 , * V_18 ;
T_5 V_19 , * V_20 ;
T_6 V_21 , * V_22 ;
int V_23 , V_24 ;
void * V_25 ;
T_7 V_26 ;
if ( F_10 ( F_11 ( V_27 , V_1 ) ) )
return;
V_4 = F_1 ( V_1 ) ;
V_2 = V_1 / V_5 ;
V_25 = F_12 ( V_28 [ V_2 ] ) ;
if ( F_10 ( V_25 ) )
goto V_29;
F_13 ( & V_30 ) ;
V_25 = F_12 ( V_28 [ V_2 ] ) ;
if ( V_25 )
goto V_31;
V_24 = F_14 ( V_1 ) ;
V_26 = V_32 ;
V_18 = & V_16 [ F_15 ( V_4 ) ] ;
V_17 = * V_18 ;
if ( ! F_16 ( V_17 ) ) {
struct V_2 * V_2 = F_17 ( V_24 , V_33 , 0 ) ;
V_20 = ( T_5 * ) F_18 ( V_2 ) ;
V_17 = F_19 ( F_20 ( V_20 ) | ( V_34 & V_26 ) ) ;
F_21 ( & V_15 , F_20 ( V_20 ) >> V_8 ) ;
for ( V_23 = 0 ; V_23 < V_35 ; V_23 ++ )
F_22 ( & V_18 [ V_23 ] , V_17 ) ;
}
V_20 = F_23 ( & V_17 , V_4 ) ;
V_19 = * V_20 ;
if ( ! F_24 ( V_19 ) ) {
struct V_2 * V_2 = F_17 ( V_24 , V_33 , 0 ) ;
V_22 = ( T_6 * ) F_18 ( V_2 ) ;
V_19 = F_25 ( F_20 ( V_22 ) | ( V_34 & V_26 ) ) ;
F_26 ( & V_15 , F_20 ( V_22 ) >> V_8 ) ;
for ( V_23 = 0 ; V_23 < V_36 ; V_23 ++ )
F_27 ( & V_20 [ V_23 ] , V_19 ) ;
}
V_22 = F_28 ( & V_19 , V_4 ) ;
V_25 = F_18 ( F_17 ( V_24 , V_37 , 0 ) ) ;
V_21 = F_29 ( F_20 ( V_25 ) | ( ( V_38 | V_39 ) & V_26 ) ) ;
for ( V_23 = 0 ; V_23 < V_40 ; V_23 ++ )
F_30 ( & V_22 [ V_23 * V_41 ] , V_21 ) ;
F_12 ( V_28 [ V_2 ] ) = V_25 ;
V_31:
F_31 ( & V_30 ) ;
V_29:
F_11 ( V_27 , V_1 ) = V_4 ;
F_11 ( V_42 , V_1 ) = ( unsigned long ) V_25
+ ( V_4 & ~ V_43 ) ;
}
