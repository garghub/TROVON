static bool F_1 ( struct V_1 * V_2 )
{
if ( F_2 ( V_2 ) )
return true ;
if ( F_3 ( V_2 ) )
return true ;
if ( F_4 ( V_2 ) && F_5 ( V_2 ) == 0x591D )
return true ;
return false ;
}
int F_6 ( struct V_1 * V_2 )
{
int V_3 ;
if ( ! V_4 . V_5 ) {
F_7 ( L_1 ) ;
return 0 ;
}
if ( F_8 ( V_2 ) ) {
F_7 ( L_2 ) ;
goto V_6;
}
if ( ! F_1 ( V_2 ) ) {
F_7 ( L_3 ) ;
goto V_6;
}
if ( ! V_4 . V_7 ) {
F_9 ( L_4 ) ;
goto V_6;
}
V_3 = F_10 () ;
if ( V_3 ) {
F_7 ( L_5 ) ;
goto V_6;
}
V_3 = F_11 ( V_2 ) ;
if ( V_3 ) {
F_7 ( L_6 ) ;
goto V_6;
}
return 0 ;
V_6:
V_4 . V_5 = 0 ;
return 0 ;
}
void F_12 ( struct V_1 * V_2 )
{
if ( ! F_13 ( V_2 ) )
return;
F_14 ( V_2 ) ;
}
