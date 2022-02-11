int F_1 ( struct V_1 * V_2 )
{
void T_1 * V_3 ;
if ( ! V_2 ) {
F_2 ( L_1 , V_4 ) ;
return - V_5 ;
}
V_3 = F_3 ( V_2 ) ;
if ( ! V_3 ) {
F_2 ( L_2 ,
V_2 -> V_6 , V_4 ) ;
return - V_5 ;
}
F_4 ( 0xAAAA , V_3 + V_7 ) ;
while ( F_5 ( V_3 + V_8 ) & 0x10 )
F_6 () ;
F_4 ( 0x5555 , V_3 + V_7 ) ;
while ( F_5 ( V_3 + V_8 ) & 0x10 )
F_6 () ;
return 0 ;
}
