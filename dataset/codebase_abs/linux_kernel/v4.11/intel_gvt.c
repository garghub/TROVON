static bool F_1 ( struct V_1 * V_2 )
{
if ( F_2 ( V_2 ) )
return true ;
if ( F_3 ( V_2 ) )
return true ;
return false ;
}
int F_4 ( struct V_1 * V_2 )
{
int V_3 ;
if ( ! V_4 . V_5 ) {
F_5 ( L_1 ) ;
return 0 ;
}
if ( F_6 ( V_2 ) ) {
F_5 ( L_2 ) ;
goto V_6;
}
if ( ! F_1 ( V_2 ) ) {
F_5 ( L_3 ) ;
goto V_6;
}
if ( ! V_4 . V_7 ) {
F_7 ( L_4 ) ;
goto V_6;
}
V_3 = F_8 () ;
if ( V_3 ) {
F_5 ( L_5 ) ;
goto V_6;
}
V_3 = F_9 ( V_2 ) ;
if ( V_3 ) {
F_5 ( L_6 ) ;
goto V_6;
}
return 0 ;
V_6:
V_4 . V_5 = 0 ;
return 0 ;
}
void F_10 ( struct V_1 * V_2 )
{
if ( ! F_11 ( V_2 ) )
return;
F_12 ( V_2 ) ;
}
