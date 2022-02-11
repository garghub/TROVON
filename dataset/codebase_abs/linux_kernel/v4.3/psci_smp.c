static int F_1 ( unsigned int V_1 , struct V_2 * V_3 )
{
if ( V_4 . V_5 )
return V_4 . V_5 ( F_2 ( V_1 ) ,
F_3 ( & V_6 ) ) ;
return - V_7 ;
}
int F_4 ( unsigned int V_1 )
{
if ( ! V_4 . V_8 )
return - V_9 ;
if ( F_5 ( V_1 ) )
return - V_10 ;
return 0 ;
}
void T_1 F_6 ( unsigned int V_1 )
{
T_2 V_11 = V_12 <<
V_13 ;
if ( V_4 . V_8 )
V_4 . V_8 ( V_11 ) ;
F_7 ( L_1 , V_1 ) ;
}
int T_1 F_8 ( unsigned int V_1 )
{
int V_14 , V_15 ;
if ( ! V_4 . V_16 )
return 1 ;
for ( V_15 = 0 ; V_15 < 10 ; V_15 ++ ) {
V_14 = V_4 . V_16 ( F_2 ( V_1 ) , 0 ) ;
if ( V_14 == V_17 ) {
F_9 ( L_2 , V_1 ) ;
return 1 ;
}
F_10 ( 10 ) ;
F_9 ( L_3 ) ;
}
F_11 ( L_4 ,
V_1 , V_14 ) ;
return 0 ;
}
bool T_3 F_12 ( void )
{
return ( V_4 . V_5 != NULL ) ;
}
