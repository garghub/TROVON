static bool F_1 ( struct V_1 * V_2 )
{
if ( F_2 ( V_2 ) )
return true ;
if ( F_3 ( V_2 ) )
return true ;
if ( F_4 ( V_2 ) )
return true ;
return false ;
}
void F_5 ( struct V_1 * V_2 )
{
if ( ! V_3 . V_4 )
return;
if ( F_6 ( V_2 ) ) {
F_7 ( L_1 ) ;
goto V_5;
}
if ( ! F_1 ( V_2 ) ) {
F_7 ( L_2 ) ;
goto V_5;
}
return;
V_5:
V_3 . V_4 = 0 ;
}
int F_8 ( struct V_1 * V_2 )
{
int V_6 ;
if ( ! V_3 . V_4 ) {
F_9 ( L_3 ) ;
return 0 ;
}
if ( ! V_3 . V_7 ) {
F_10 ( L_4 ) ;
return - V_8 ;
}
if ( V_3 . V_9 ) {
F_10 ( L_5 ) ;
return - V_8 ;
}
V_6 = F_11 () ;
if ( V_6 ) {
F_9 ( L_6 ) ;
goto V_5;
}
V_6 = F_12 ( V_2 ) ;
if ( V_6 ) {
F_9 ( L_7 ) ;
goto V_5;
}
return 0 ;
V_5:
V_3 . V_4 = 0 ;
return 0 ;
}
void F_13 ( struct V_1 * V_2 )
{
if ( ! F_14 ( V_2 ) )
return;
F_15 ( V_2 ) ;
}
