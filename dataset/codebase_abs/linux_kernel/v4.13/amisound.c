void T_1 F_1 ( void )
{
static struct V_1 V_2 = { . V_3 = L_1 } ;
V_4 = F_2 ( sizeof( V_5 ) , & V_2 ) ;
if ( ! V_4 ) {
F_3 ( L_2 ) ;
return;
}
memcpy ( V_4 , V_5 , sizeof( V_5 ) ) ;
V_6 = ( V_7 + V_8 / 2 ) / V_8 ;
#ifndef F_4
F_5 () ;
#endif
}
void F_6 ( unsigned int V_9 , unsigned int V_10 )
{
unsigned long V_11 ;
if ( ! V_4 )
return;
F_7 ( V_11 ) ;
F_8 ( & V_12 ) ;
if ( V_9 > 20 && V_9 < 32767 ) {
unsigned long V_13 = ( V_6 / V_9 ) ;
if ( V_13 < V_14 )
V_13 = V_14 ;
if ( V_13 > V_15 )
V_13 = V_15 ;
V_16 . V_17 [ 2 ] . V_18 = V_4 ;
V_16 . V_17 [ 2 ] . V_19 = sizeof( V_5 ) / 2 ;
V_16 . V_17 [ 2 ] . V_20 = ( unsigned short ) V_13 ;
V_16 . V_17 [ 2 ] . V_21 = 32 ;
if ( V_10 ) {
V_12 . V_22 = V_23 + V_10 ;
F_9 ( & V_12 ) ;
}
V_16 . V_24 = V_25 | V_26 ;
} else
F_10 ( 0 ) ;
F_11 ( V_11 ) ;
}
static void F_10 ( unsigned long V_27 )
{
V_16 . V_24 = V_26 ;
V_16 . V_17 [ 2 ] . V_20 = V_28 ;
}
