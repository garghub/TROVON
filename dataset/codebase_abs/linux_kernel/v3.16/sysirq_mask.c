void T_1 F_1 ( T_2 V_1 )
{
void T_3 * V_2 ;
V_2 = F_2 ( V_1 , 64 ) ;
if ( ! V_2 )
return;
F_3 ( V_3 , V_2 + V_4 ) ;
( void ) F_4 ( V_2 + V_5 ) ;
F_5 ( V_2 ) ;
}
void T_1 F_6 ( T_2 V_6 )
{
void T_3 * V_2 ;
void T_3 * V_7 ;
T_2 V_8 ;
V_2 = F_2 ( V_6 , 16 ) ;
if ( ! V_2 )
return;
V_7 = V_2 + V_9 ;
V_8 = F_4 ( V_7 ) ;
if ( V_8 & ( V_10 | V_11 ) ) {
F_7 ( L_1 ) ;
V_8 &= ~ ( V_10 | V_11 ) ;
F_3 ( V_8 , V_7 ) ;
( void ) F_4 ( V_7 ) ;
}
F_5 ( V_2 ) ;
}
