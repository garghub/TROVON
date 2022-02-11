static int F_1 ( const char * V_1 , struct V_2 * V_3 )
{
unsigned long V_4 ;
int V_5 ;
V_5 = F_2 ( V_1 , 0 , & V_4 ) ;
if ( V_5 )
return V_5 ;
if ( V_4 > 4 )
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
int V_13 ;
V_13 = F_6 ( & V_14 , NULL ) ;
if ( V_13 )
F_7 ( V_15 L_7 ) ;
return V_13 ;
}
static void F_8 ( void )
{
F_9 ( & V_14 ) ;
}
struct V_16 * F_10 ( void )
{
return & V_14 ;
}
static int T_1 F_11 ( void )
{
int V_13 = 0 ;
F_12 ( V_17 , V_18 , V_19 L_8 ) ;
V_13 = F_5 () ;
if ( V_13 )
return V_13 ;
F_13 () ;
V_13 = F_14 () ;
if ( V_13 )
goto V_20;
F_15 () ;
V_13 = F_16 () ;
if ( V_13 ) {
F_12 ( V_15 , V_18 , L_9 ) ;
goto V_21;
}
return 0 ;
V_21:
F_17 () ;
F_18 () ;
V_20:
F_8 () ;
return V_13 ;
}
static void T_2 F_19 ( void )
{
F_20 ( 0 , L_8 ) ;
F_21 () ;
F_18 () ;
F_17 () ;
F_8 () ;
}
