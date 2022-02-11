T_1 * F_1 ( void )
{
T_1 * V_1 = NULL ;
V_1 = F_2 ( sizeof( * V_1 ) ) ;
if ( V_1 == NULL )
goto V_2;
V_1 -> V_3 = F_3 () ;
V_1 -> V_4 = F_4 () ;
if ( V_1 -> V_3 == NULL || V_1 -> V_4 == NULL )
goto V_2;
return V_1 ;
V_2:
F_5 ( V_1 ) ;
F_6 ( V_5 , V_6 ) ;
return NULL ;
}
void F_5 ( T_1 * V_7 )
{
if ( V_7 == NULL )
return;
F_7 ( V_7 -> V_3 ) ;
F_8 ( V_7 -> V_4 ) ;
F_9 ( V_7 -> V_8 ) ;
if ( V_7 -> V_9 )
F_10 ( V_7 -> V_10 ) ;
F_10 ( V_7 ) ;
}
