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
F_4 ( rand ) ;
rand *= 0xc345c6b72fd16123UL ;
}
V_7 = rand % V_5 ;
V_6 = ( rand / V_5 )
& ( V_11 - 1 ) ;
}
void T_1 F_5 ( void )
{
T_2 * V_12 ;
T_3 V_13 ;
V_13 = V_14 ;
V_12 = & V_15 [ F_6 ( V_10 ) ] ;
F_7 ( & V_16 , V_12 , ( V_17 * ) V_18 ) ;
F_2 () ;
F_8 () ;
}
void F_8 ( void )
{
unsigned int V_1 , V_2 ;
unsigned long V_4 ;
V_17 V_19 , * V_20 ;
T_4 V_21 , * V_22 ;
T_5 V_23 , * V_24 ;
int V_25 ;
void * V_26 ;
T_3 V_13 ;
if ( F_9 ( F_10 ( V_27 ) ) )
return;
V_1 = F_11 () ;
V_4 = F_1 ( V_1 ) ;
V_2 = V_1 / V_5 ;
V_26 = F_12 ( V_28 [ V_2 ] ) ;
if ( F_9 ( V_26 ) )
goto V_29;
F_13 ( & V_30 ) ;
V_26 = F_12 ( V_28 [ V_2 ] ) ;
if ( V_26 )
goto V_31;
V_13 = V_14 ;
V_20 = & V_18 [ F_14 ( V_4 ) ] ;
V_19 = * V_20 ;
if ( ! F_15 ( V_19 ) ) {
V_22 = ( T_4 * ) F_16 ( V_32 ) ;
V_19 = F_17 ( F_18 ( V_22 ) | ( V_33 & V_13 ) ) ;
F_19 ( & V_16 , F_18 ( V_22 ) >> V_8 ) ;
for ( V_25 = 0 ; V_25 < V_34 ; V_25 ++ )
F_20 ( & V_20 [ V_25 ] , V_19 ) ;
}
V_22 = F_21 ( & V_19 , V_4 ) ;
V_21 = * V_22 ;
if ( ! F_22 ( V_21 ) ) {
V_24 = ( T_5 * ) F_16 ( V_32 ) ;
V_21 = F_23 ( F_18 ( V_24 ) | ( V_33 & V_13 ) ) ;
F_24 ( & V_16 , F_18 ( V_24 ) >> V_8 ) ;
for ( V_25 = 0 ; V_25 < V_35 ; V_25 ++ )
F_25 ( & V_22 [ V_25 ] , V_21 ) ;
}
V_24 = F_26 ( & V_21 , V_4 ) ;
V_26 = ( void * ) F_16 ( V_36 ) ;
V_23 = F_27 ( F_18 ( V_26 ) | ( V_37 & V_13 ) ) ;
for ( V_25 = 0 ; V_25 < V_38 ; V_25 ++ )
F_28 ( & V_24 [ V_25 * V_39 ] , V_23 ) ;
F_12 ( V_28 [ V_2 ] ) = V_26 ;
V_31:
F_29 ( & V_30 ) ;
V_29:
F_30 ( V_27 , V_4 ) ;
F_30 ( V_40 , ( unsigned long ) V_26
+ ( V_4 & ~ V_41 ) ) ;
}
