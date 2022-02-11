char * F_1 ( int V_1 )
{
if ( V_1 == V_2 )
return L_1 ;
else if ( V_1 == V_3 )
return L_2 ;
else if ( V_1 == V_4 )
return L_3 ;
else if ( V_1 == V_5 )
return L_4 ;
else if ( V_1 == V_6 )
return L_5 ;
return L_6 ;
}
static int F_2 ( void )
{
V_7 = F_3 ( L_7 ) ;
if ( V_7 == NULL )
return - V_8 ;
else
return 0 ;
}
static void F_4 ( void )
{
if ( V_7 ) {
F_5 ( V_7 ) ;
F_6 ( V_7 ) ;
V_7 = NULL ;
}
}
static int T_1 F_7 ( void )
{
int V_9 = 0 ;
F_8 ( V_10 , V_11 , V_12 L_8 ) ;
F_9 () ;
V_9 = F_10 () ;
if ( V_9 )
goto error;
F_11 () ;
V_9 = F_2 () ;
if ( V_9 ) {
F_8 ( V_13 , V_11 , L_9 ) ;
goto error;
}
return 0 ;
error:
return V_9 ;
}
static void T_2 F_12 ( void )
{
F_13 ( 0 , L_8 ) ;
F_4 () ;
F_14 () ;
F_15 () ;
}
