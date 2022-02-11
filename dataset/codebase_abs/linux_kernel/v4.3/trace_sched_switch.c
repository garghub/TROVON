static void
F_1 ( void * V_1 , struct V_2 * V_3 , struct V_2 * V_4 )
{
if ( F_2 ( ! V_5 ) )
return;
F_3 ( V_3 ) ;
F_3 ( V_4 ) ;
}
static void
F_4 ( void * V_1 , struct V_2 * V_6 )
{
if ( F_2 ( ! V_5 ) )
return;
F_3 ( V_7 ) ;
}
static int F_5 ( void )
{
int V_8 ;
V_8 = F_6 ( F_4 , NULL ) ;
if ( V_8 ) {
F_7 ( L_1
L_2 ) ;
return V_8 ;
}
V_8 = F_8 ( F_4 , NULL ) ;
if ( V_8 ) {
F_7 ( L_1
L_3 ) ;
goto V_9;
}
V_8 = F_9 ( F_1 , NULL ) ;
if ( V_8 ) {
F_7 ( L_4
L_5 ) ;
goto V_10;
}
return V_8 ;
V_10:
F_10 ( F_4 , NULL ) ;
V_9:
F_11 ( F_4 , NULL ) ;
return V_8 ;
}
static void F_12 ( void )
{
F_13 ( F_1 , NULL ) ;
F_10 ( F_4 , NULL ) ;
F_11 ( F_4 , NULL ) ;
}
static void F_14 ( void )
{
F_15 ( & V_11 ) ;
if ( ! ( V_5 ++ ) )
F_5 () ;
F_16 ( & V_11 ) ;
}
static void F_17 ( void )
{
F_15 ( & V_11 ) ;
if ( ! ( -- V_5 ) )
F_12 () ;
F_16 ( & V_11 ) ;
}
void F_18 ( void )
{
F_14 () ;
}
void F_19 ( void )
{
F_17 () ;
}
