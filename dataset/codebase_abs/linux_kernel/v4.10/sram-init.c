static void T_1 F_1 ( void )
{
unsigned long V_1 = V_2 ;
unsigned long V_3 = V_4 ;
unsigned long V_5 ;
if ( F_2 () )
V_5 = 0x32000 ;
else if ( F_3 () )
V_5 = 0x30000 ;
else if ( F_4 () || F_5 () ||
F_6 () || F_7 () )
V_5 = 0x4000 ;
else {
F_8 ( L_1 ) ;
V_5 = 0x4000 ;
}
F_9 ( V_3 , V_5 ,
V_1 , 1 ) ;
}
void F_10 ( T_2 V_6 , T_2 V_7 )
{
F_11 ( ! V_8 ) ;
if ( F_2 () )
V_7 |= 0x2000 ;
V_8 ( V_6 , V_7 ) ;
}
int T_1 F_12 ( void )
{
F_1 () ;
V_8 =
F_13 ( V_9 ,
V_10 ) ;
return 0 ;
}
