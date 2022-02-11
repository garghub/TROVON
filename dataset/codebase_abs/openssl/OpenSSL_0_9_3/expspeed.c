static double F_1 ( int V_1 )
{
double V_2 ;
#ifdef F_2
static struct V_3 V_4 , V_5 ;
if ( V_1 == V_6 )
{
F_3 ( & V_4 ) ;
return ( 0 ) ;
}
else
{
F_3 ( & V_5 ) ;
V_2 = ( ( double ) ( V_5 . V_7 - V_4 . V_7 ) ) / V_8 ;
return ( ( V_2 < 1e-3 ) ? 1e-3 : V_2 ) ;
}
#else
static struct V_9 V_4 , V_5 ;
long V_10 ;
if ( V_1 == V_6 )
{
F_4 ( & V_4 ) ;
return ( 0 ) ;
}
else
{
F_4 ( & V_5 ) ;
V_10 = ( long ) V_5 . V_11 - ( long ) V_4 . V_11 ;
V_2 = ( ( double ) ( V_5 . time - V_4 . time ) ) + ( ( double ) V_10 ) / 1000.0 ;
return ( ( V_2 < 0.001 ) ? 0.001 : V_2 ) ;
}
#endif
}
int main ( int V_12 , char * * V_13 )
{
T_1 * V_14 ;
T_2 * V_15 , * V_16 , * V_17 , * V_18 ;
V_14 = F_5 () ;
V_15 = F_6 () ;
V_16 = F_6 () ;
V_17 = F_6 () ;
V_18 = F_6 () ;
F_7 ( V_18 , V_15 , V_16 , V_17 , V_14 ) ;
}
void F_7 ( T_2 * V_18 , T_2 * V_15 , T_2 * V_16 , T_2 * V_17 , T_1 * V_14 )
{
int V_10 , V_19 ;
double V_20 ;
long V_21 ;
T_3 V_22 ;
memset ( & V_22 , 0 , sizeof( V_22 ) ) ;
V_21 = V_23 ;
for ( V_10 = 0 ; V_10 < V_24 ; V_10 ++ )
{
F_8 ( V_15 , V_25 [ V_10 ] , 1 , 0 ) ;
F_8 ( V_16 , V_25 [ V_10 ] , 1 , 0 ) ;
F_8 ( V_17 , V_25 [ V_10 ] , 1 , 1 ) ;
F_9 ( V_15 , V_15 , V_17 , V_14 ) ;
F_9 ( V_16 , V_16 , V_17 , V_14 ) ;
F_10 ( & V_22 , V_17 , V_14 ) ;
F_1 ( V_6 ) ;
for ( V_19 = 0 ; V_19 < V_21 ; V_19 ++ )
F_11 ( V_18 , V_15 , V_16 , V_17 , V_14 , & V_22 ) ;
V_20 = F_1 ( V_26 ) ;
printf ( L_1 , V_25 [ V_10 ] , V_25 [ V_10 ] , V_25 [ V_10 ] , V_20 * 1000.0 / V_21 , V_20 * V_27 [ V_10 ] / V_21 ) ;
V_21 /= 7 ;
if ( V_21 <= 0 ) V_21 = 1 ;
}
}
