static void F_1 ( void )
{
}
static unsigned long T_1 F_2 ( void )
{
unsigned long V_1 ;
T_2 V_2 , V_3 , V_4 , V_5 ;
F_3 ( V_6 , V_2 , V_3 ) ;
F_4 ( L_1 , V_2 , V_3 ) ;
V_4 = ( V_3 >> 8 ) & 0x1f ;
F_4 ( L_2 , V_4 ) ;
if ( ! V_4 ) {
F_5 ( L_3 ) ;
F_5 ( L_4 ) ;
V_4 = 16 ;
}
F_3 ( V_7 , V_2 , V_3 ) ;
if ( ( V_2 & 0x7 ) == 0x7 )
V_5 = V_8 ;
else
V_5 = V_9 ;
V_1 = V_4 * V_5 ;
F_4 ( L_5 , V_1 ) ;
V_10 = V_5 * 1000 / V_11 ;
F_6 ( & V_12 , V_13 ) ;
if ( V_1 )
return V_1 ;
return 0 ;
}
static void T_1 F_7 ( void )
{
V_14 . V_15 = F_2 ;
V_16 = F_1 ;
}
void * F_8 ( void )
{
return & V_17 ;
}
void * F_9 ( void )
{
return & V_17 ;
}
