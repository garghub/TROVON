static void T_1 F_1 ( int V_1 )
{
T_2 * V_2 ;
void * V_3 ;
if ( ! ( V_4 & V_5 ) )
return;
for ( V_3 = V_6 . V_7 ; V_3 < V_6 . V_8 ; V_3 += V_6 . V_9 ) {
V_2 = V_3 ;
if ( V_2 -> type == V_10 ||
V_2 -> type == V_11 )
F_2 ( V_2 , V_1 ) ;
}
}
void T_1 F_3 ( void )
{
unsigned long V_12 ;
int V_13 ;
int V_14 ;
F_1 ( 1 ) ;
F_4 ( V_15 ) ;
V_14 = F_5 ( ( V_16 << V_17 ) , V_18 ) ;
V_19 = F_6 ( V_14 * sizeof( V_20 ) , V_21 ) ;
for ( V_13 = 0 ; V_13 < V_14 ; V_13 ++ ) {
V_19 [ V_13 ] = * F_7 ( V_13 * V_18 ) ;
V_12 = ( unsigned long ) F_8 ( V_13 * V_18 ) ;
F_9 ( F_7 ( V_13 * V_18 ) , * F_7 ( V_12 ) ) ;
}
F_10 () ;
}
void T_1 F_11 ( void )
{
int V_13 ;
int V_14 = F_5 ( ( V_16 << V_17 ) , V_18 ) ;
for ( V_13 = 0 ; V_13 < V_14 ; V_13 ++ )
F_9 ( F_7 ( V_13 * V_18 ) , V_19 [ V_13 ] ) ;
F_12 ( V_19 ) ;
F_10 () ;
F_13 ( V_15 ) ;
F_1 ( 0 ) ;
}
void T_3 * T_1 F_14 ( unsigned long V_22 , unsigned long V_23 ,
T_4 type , T_5 V_24 )
{
unsigned long V_25 ;
if ( type == V_26 )
return F_15 ( V_22 , V_23 ) ;
V_25 = F_16 ( V_22 , V_22 + V_23 ) ;
if ( ( V_25 << V_17 ) < V_22 + V_23 ) {
unsigned long V_27 = V_25 << V_17 ;
F_14 ( V_27 , V_23 - ( V_27 - V_22 ) , type , V_24 ) ;
}
if ( ! ( V_24 & V_28 ) )
F_17 ( ( T_5 ) ( unsigned long ) F_8 ( V_22 ) , V_23 ) ;
return ( void T_3 * ) F_8 ( V_22 ) ;
}
