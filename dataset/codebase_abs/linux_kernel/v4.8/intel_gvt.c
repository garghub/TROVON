static bool F_1 ( struct V_1 * V_2 )
{
if ( F_2 ( V_2 ) )
return true ;
return false ;
}
int F_3 ( struct V_1 * V_2 )
{
int V_3 ;
if ( ! V_4 . V_5 ) {
F_4 ( L_1 ) ;
return 0 ;
}
if ( ! F_1 ( V_2 ) ) {
F_4 ( L_2 ) ;
goto V_6;
}
V_3 = F_5 () ;
if ( V_3 ) {
F_4 ( L_3 ) ;
goto V_6;
}
V_3 = F_6 ( V_2 ) ;
if ( V_3 ) {
F_4 ( L_4 ) ;
goto V_6;
}
return 0 ;
V_6:
V_4 . V_5 = 0 ;
return 0 ;
}
void F_7 ( struct V_1 * V_2 )
{
if ( ! F_8 ( V_2 ) )
return;
F_9 ( V_2 ) ;
}
