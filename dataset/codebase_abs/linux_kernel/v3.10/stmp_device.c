static int F_1 ( void T_1 * V_1 , T_2 V_2 )
{
int V_3 = 0x400 ;
F_2 ( V_2 , V_1 + V_4 ) ;
F_3 ( 1 ) ;
while ( ( F_4 ( V_1 ) & V_2 ) && -- V_3 )
;
return ! V_3 ;
}
int F_5 ( void T_1 * V_5 )
{
int V_6 ;
int V_3 = 0x400 ;
V_6 = F_1 ( V_5 , V_7 ) ;
if ( F_6 ( V_6 ) )
goto error;
F_2 ( V_8 , V_5 + V_4 ) ;
F_2 ( V_7 , V_5 + V_9 ) ;
F_3 ( 1 ) ;
while ( ( ! ( F_4 ( V_5 ) & V_8 ) ) && -- V_3 )
;
if ( F_6 ( ! V_3 ) )
goto error;
V_6 = F_1 ( V_5 , V_7 ) ;
if ( F_6 ( V_6 ) )
goto error;
V_6 = F_1 ( V_5 , V_8 ) ;
if ( F_6 ( V_6 ) )
goto error;
return 0 ;
error:
F_7 ( L_1 , V_10 , V_5 ) ;
return - V_11 ;
}
