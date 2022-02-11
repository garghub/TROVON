int F_1 ( T_1 * V_1 )
{
return ( F_2 ( ( T_1 * * ) & V_2 , NULL , V_1 ) == NULL ) ?
0 : - V_3 ;
}
int F_3 ( T_1 * V_1 )
{
int V_4 ;
V_4 = ( F_2 ( ( T_1 * * ) & V_2 , V_1 , NULL ) == V_1 ) ?
0 : - V_5 ;
F_4 () ;
return V_4 ;
}
void F_5 ( struct V_6 * V_7 , T_2 type , T_2 V_8 , T_3 V_9 )
{
T_1 * V_10 ;
F_6 () ;
V_10 = F_7 ( V_2 ) ;
if ( ! V_10 )
goto V_11;
V_10 ( V_7 , type , V_8 , V_9 ) ;
V_11:
F_8 () ;
}
