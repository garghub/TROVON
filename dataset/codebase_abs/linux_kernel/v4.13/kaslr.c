static inline unsigned long F_1 ( struct V_1 * V_2 )
{
return ( V_2 -> V_3 << V_4 ) ;
}
static inline bool F_2 ( void )
{
return F_3 () && ! F_4 ( V_5 ) ;
}
void T_1 F_5 ( void )
{
T_2 V_6 ;
unsigned long V_7 = V_8 ;
unsigned long rand , V_9 ;
struct V_10 V_11 ;
unsigned long V_12 ;
F_6 ( V_8 >= V_13 ) ;
F_6 ( F_4 ( V_14 ) &&
V_13 >= V_15 ) ;
F_6 ( ( F_4 ( V_14 ) ||
F_4 ( V_16 ) ) &&
V_13 >= V_17 ) ;
F_6 ( V_13 > V_17 ) ;
if ( ! F_2 () )
return;
F_7 ( V_18 [ 0 ] . V_19 != & V_20 ) ;
V_9 = F_8 ( V_21 << V_22 , 1UL << V_4 ) +
V_23 ;
if ( V_9 < V_18 [ 0 ] . V_3 )
V_18 [ 0 ] . V_3 = V_9 ;
V_12 = V_13 - V_8 ;
for ( V_6 = 0 ; V_6 < F_9 ( V_18 ) ; V_6 ++ )
V_12 -= F_1 ( & V_18 [ V_6 ] ) ;
F_10 ( & V_11 , F_11 ( L_1 ) ) ;
for ( V_6 = 0 ; V_6 < F_9 ( V_18 ) ; V_6 ++ ) {
unsigned long V_24 ;
V_24 = V_12 / ( F_9 ( V_18 ) - V_6 ) ;
F_12 ( & V_11 , & rand , sizeof( rand ) ) ;
if ( F_4 ( V_25 ) )
V_24 = ( rand % ( V_24 + 1 ) ) & V_26 ;
else
V_24 = ( rand % ( V_24 + 1 ) ) & V_27 ;
V_7 += V_24 ;
* V_18 [ V_6 ] . V_19 = V_7 ;
V_7 += F_1 ( & V_18 [ V_6 ] ) ;
if ( F_4 ( V_25 ) )
V_7 = F_13 ( V_7 + 1 , V_28 ) ;
else
V_7 = F_13 ( V_7 + 1 , V_29 ) ;
V_12 -= V_24 ;
}
}
static void T_3 F_14 ( void )
{
unsigned long V_30 , V_31 ;
T_4 * V_32 ;
T_5 * V_33 , * V_34 ;
int V_6 ;
V_34 = F_15 () ;
V_30 = 0 ;
V_32 = F_16 ( ( unsigned long ) F_17 ( V_30 ) ) ;
V_33 = ( T_5 * ) F_18 ( * V_32 ) ;
for ( V_6 = F_19 ( V_30 ) ; V_6 < V_35 ; V_6 ++ , V_30 = V_31 ) {
T_5 * V_36 , * V_37 ;
unsigned long V_7 = ( unsigned long ) F_17 ( V_30 ) ;
V_37 = V_34 + F_19 ( V_30 ) ;
V_36 = V_33 + F_19 ( V_7 ) ;
V_31 = ( V_30 & V_27 ) + V_29 ;
* V_37 = * V_36 ;
}
F_20 ( & V_38 ,
F_21 ( V_39 | F_22 ( V_34 ) ) ) ;
}
static void T_3 F_23 ( void )
{
unsigned long V_30 , V_31 ;
T_4 * V_32 ;
T_6 * V_40 , * V_41 ;
int V_6 ;
V_41 = F_15 () ;
V_30 = 0 ;
V_32 = F_16 ( ( unsigned long ) F_17 ( V_30 ) ) ;
V_40 = ( T_6 * ) F_18 ( * V_32 ) ;
for ( V_6 = F_24 ( V_30 ) ; V_6 < V_42 ; V_6 ++ , V_30 = V_31 ) {
T_6 * V_43 , * V_44 ;
unsigned long V_7 = ( unsigned long ) F_17 ( V_30 ) ;
V_44 = V_41 + F_24 ( V_30 ) ;
V_43 = V_40 + F_24 ( V_7 ) ;
V_31 = ( V_30 & V_26 ) + V_28 ;
* V_44 = * V_43 ;
}
F_20 ( & V_38 ,
F_21 ( V_39 | F_22 ( V_41 ) ) ) ;
}
void T_3 F_25 ( void )
{
if ( ! F_2 () ) {
F_26 () ;
return;
}
if ( F_4 ( V_25 ) )
F_23 () ;
else
F_14 () ;
}
