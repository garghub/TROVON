static T_1 F_1 ( struct V_1 * V_2 )
{
return F_2 ( V_3 ) ;
}
int T_2 F_3 ( void )
{
unsigned int V_4 ;
T_3 V_5 , V_6 ;
int V_7 = V_8 / 8 ;
F_4 () ;
while ( ! F_4 () )
;
V_5 = F_1 ( & V_9 ) ;
while ( V_7 -- )
while ( ! F_4 () )
;
V_6 = F_1 ( & V_9 ) ;
V_4 = ( V_6 - V_5 ) * 8 ;
if ( ! V_4 )
return - V_10 ;
F_5 ( V_11 L_1 , V_4 ) ;
V_9 . V_12 = 200 + V_4 / 10000000 ;
F_6 ( & V_9 , V_4 ) ;
return 0 ;
}
