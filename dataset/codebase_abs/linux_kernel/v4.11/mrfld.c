static unsigned long T_1 F_1 ( void )
{
unsigned long V_1 ;
T_2 V_2 , V_3 , V_4 , V_5 , V_6 ;
F_2 ( V_7 , V_2 , V_3 ) ;
F_3 ( L_1 , V_3 , V_2 ) ;
V_4 = ( V_2 >> 8 ) & 0xFF ;
F_3 ( L_2 , V_4 ) ;
if ( ! V_4 ) {
F_4 ( L_3 ) ;
V_4 = 4 ;
}
F_2 ( V_8 , V_2 , V_3 ) ;
F_3 ( L_4 ,
V_3 , V_2 ) ;
V_6 = V_2 & 0x7 ;
F_3 ( L_5 , V_6 ) ;
if ( V_6 == 0 )
V_5 = V_9 ;
else if ( V_6 == 1 )
V_5 = V_9 ;
else if ( V_6 == 2 )
V_5 = V_10 ;
else if ( V_6 == 3 )
V_5 = V_11 ;
else if ( V_6 == 4 )
V_5 = V_12 ;
else if ( V_6 == 5 )
V_5 = V_13 ;
else if ( V_6 == 6 )
V_5 = V_14 ;
else if ( V_6 == 7 )
V_5 = V_15 ;
else {
F_5 () ;
F_4 ( L_6 ) ;
V_5 = V_9 ;
}
V_1 = V_4 * V_5 ;
F_3 ( L_7 , V_1 ) ;
V_16 = ( V_5 * 1000 ) / V_17 ;
F_3 ( L_8 ,
V_16 ) ;
F_6 ( V_18 ) ;
F_6 ( V_19 ) ;
return V_1 ;
}
static void T_1 F_7 ( void )
{
V_20 . V_21 = F_1 ;
V_20 . V_22 . V_23 = 1 ;
}
void * F_8 ( void )
{
return & V_24 ;
}
