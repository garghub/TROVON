static int F_1 ( const char * V_1 , struct V_2 * V_3 )
{
unsigned long V_4 ;
int V_5 ;
V_5 = F_2 ( V_1 , 0 , & V_4 ) ;
if ( V_5 )
return V_5 ;
if ( V_4 < 0 || V_4 > 4 )
return - V_6 ;
return F_3 ( V_1 , V_3 ) ;
}
char * F_4 ( int V_7 )
{
if ( V_7 == V_8 )
return L_1 ;
else if ( V_7 == V_9 )
return L_2 ;
else if ( V_7 == V_10 )
return L_3 ;
else if ( V_7 == V_11 )
return L_4 ;
else if ( V_7 == V_12 )
return L_5 ;
return L_6 ;
}
static int F_5 ( void )
{
V_13 = F_6 ( L_7 ) ;
if ( V_13 == NULL )
return - V_14 ;
else
return 0 ;
}
static void F_7 ( void )
{
if ( V_13 ) {
F_8 ( V_13 ) ;
F_9 ( V_13 ) ;
V_13 = NULL ;
}
}
static int T_1 F_10 ( void )
{
int V_15 = 0 ;
F_11 ( V_16 , V_17 , V_18 L_8 ) ;
F_12 () ;
V_15 = F_13 () ;
if ( V_15 )
goto error;
F_14 () ;
V_15 = F_5 () ;
if ( V_15 ) {
F_11 ( V_19 , V_17 , L_9 ) ;
goto error;
}
return 0 ;
error:
return V_15 ;
}
static void T_2 F_15 ( void )
{
F_16 ( 0 , L_8 ) ;
F_7 () ;
F_17 () ;
F_18 () ;
}
