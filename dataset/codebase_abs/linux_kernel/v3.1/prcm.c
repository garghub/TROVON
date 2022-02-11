T_1 F_1 ( void )
{
if ( F_2 () || F_3 () )
return F_4 ( V_1 , V_2 ) & 0x7f ;
if ( F_5 () )
return F_4 ( V_1 , V_3 ) & 0x7f ;
return 0 ;
}
static void F_6 ( char V_4 , const char * V_5 )
{
T_2 V_6 = 0 ;
if ( F_2 () ) {
F_7 () ;
V_6 = V_1 ;
} else if ( F_3 () ) {
V_6 = V_7 ;
F_8 ( ( V_5 ? ( V_8 ) * V_5 : 0 ) ) ;
} else if ( F_5 () ) {
F_9 () ;
} else {
F_10 ( 1 ) ;
}
F_11 ( V_9 , V_6 ,
V_10 ) ;
F_4 ( V_6 , V_10 ) ;
}
int F_12 ( void T_3 * V_11 , T_1 V_12 , V_8 V_13 ,
const char * V_14 )
{
int V_15 = 0 ;
int V_16 = 0 ;
if ( V_13 )
V_16 = 0 ;
else
V_16 = V_12 ;
F_13 ( ( ( F_14 ( V_11 ) & V_12 ) == V_16 ) ,
V_17 , V_15 ) ;
if ( V_15 < V_17 )
F_15 ( L_1
L_2 , V_14 , V_15 ) ;
else
F_16 ( L_3
L_4 , V_14 , V_17 ) ;
return ( V_15 < V_17 ) ? 1 : 0 ;
}
void T_4 F_17 ( struct V_18 * V_19 )
{
if ( V_19 -> V_20 ) {
V_21 = F_18 ( V_19 -> V_20 , V_22 ) ;
F_10 ( ! V_21 ) ;
}
if ( V_19 -> V_23 ) {
V_24 = F_18 ( V_19 -> V_23 , V_22 ) ;
F_10 ( ! V_24 ) ;
}
if ( V_19 -> V_25 ) {
V_26 = F_18 ( V_19 -> V_25 , V_22 ) ;
F_10 ( ! V_26 ) ;
}
}
