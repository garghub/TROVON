int F_1 ( void )
{
if ( V_1 == V_2 )
return 0 ;
return F_2 ( & V_3 ) ;
}
void F_3 ( void )
{
V_4 ++ ;
}
struct V_5 * F_4 ( void )
{
int V_6 = 0 ;
if ( F_2 ( & V_7 ) )
goto V_8;
V_6 = F_5 ( & V_9 , NULL ) ;
if ( V_6 ) {
F_6 ( V_10 L_1 ) ;
return NULL ;
}
V_8:
F_7 ( & V_7 ) ;
return & V_9 ;
}
void F_8 ( void )
{
if ( F_9 ( & V_7 ) )
F_10 ( & V_9 ) ;
}
