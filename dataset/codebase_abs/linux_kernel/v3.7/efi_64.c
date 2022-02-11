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
F_1 ( 1 ) ;
F_4 ( V_13 ) ;
V_12 = ( unsigned long ) F_5 ( 0x0UL ) ;
V_14 = * F_6 ( 0x0UL ) ;
F_7 ( F_6 ( 0x0UL ) , * F_6 ( V_12 ) ) ;
F_8 () ;
}
void T_1 F_9 ( void )
{
F_7 ( F_6 ( 0x0UL ) , V_14 ) ;
F_8 () ;
F_10 ( V_13 ) ;
F_1 ( 0 ) ;
}
void T_3 * T_1 F_11 ( unsigned long V_15 , unsigned long V_16 ,
T_4 type , T_5 V_17 )
{
unsigned long V_18 ;
if ( type == V_19 )
return F_12 ( V_15 , V_16 ) ;
V_18 = F_13 ( V_15 , V_15 + V_16 ) ;
if ( ( V_18 << V_20 ) < V_15 + V_16 ) {
unsigned long V_21 = V_18 << V_20 ;
F_11 ( V_21 , V_16 - ( V_21 - V_15 ) , type , V_17 ) ;
}
if ( ! ( V_17 & V_22 ) )
F_14 ( ( T_5 ) ( unsigned long ) F_5 ( V_15 ) , V_16 ) ;
return ( void T_3 * ) F_5 ( V_15 ) ;
}
