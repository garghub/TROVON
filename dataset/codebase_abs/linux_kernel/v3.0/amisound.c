void T_1 F_1 ( void )
{
static struct V_1 V_2 = { . V_3 = L_1 } ;
V_4 = F_2 ( sizeof( V_5 ) , & V_2 ) ;
if ( ! V_4 ) {
F_3 ( V_6 L_2 ) ;
return;
}
memcpy ( V_4 , V_5 , sizeof( V_5 ) ) ;
V_7 = ( V_8 + V_9 / 2 ) / V_9 ;
#ifndef F_4
F_5 () ;
#endif
}
void F_6 ( unsigned int V_10 , unsigned int V_11 )
{
unsigned long V_12 ;
if ( ! V_4 )
return;
F_7 ( V_12 ) ;
F_8 ( & V_13 ) ;
if ( V_10 > 20 && V_10 < 32767 ) {
unsigned long V_14 = ( V_7 / V_10 ) ;
if ( V_14 < V_15 )
V_14 = V_15 ;
if ( V_14 > V_16 )
V_14 = V_16 ;
V_17 . V_18 [ 2 ] . V_19 = V_4 ;
V_17 . V_18 [ 2 ] . V_20 = sizeof( V_5 ) / 2 ;
V_17 . V_18 [ 2 ] . V_21 = ( unsigned short ) V_14 ;
V_17 . V_18 [ 2 ] . V_22 = 32 ;
if ( V_11 ) {
V_13 . V_23 = V_24 + V_11 ;
F_9 ( & V_13 ) ;
}
V_17 . V_25 = V_26 | V_27 ;
} else
F_10 ( 0 ) ;
F_11 ( V_12 ) ;
}
static void F_10 ( unsigned long V_28 )
{
V_17 . V_25 = V_27 ;
V_17 . V_18 [ 2 ] . V_21 = V_29 ;
}
