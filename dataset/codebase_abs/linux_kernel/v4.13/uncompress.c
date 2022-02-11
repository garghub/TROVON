int F_1 ( void * V_1 , int V_2 , void * V_3 , int V_4 )
{
int V_5 ;
V_6 . V_7 = V_3 ;
V_6 . V_8 = V_4 ;
V_6 . V_9 = V_1 ;
V_6 . V_10 = V_2 ;
V_5 = F_2 ( & V_6 ) ;
if ( V_5 != V_11 ) {
F_3 ( L_1 , V_5 ) ;
F_4 ( & V_6 ) ;
F_5 ( & V_6 ) ;
}
V_5 = F_6 ( & V_6 , V_12 ) ;
if ( V_5 != V_13 )
goto V_5;
return V_6 . V_14 ;
V_5:
F_3 ( L_2 , V_5 ) ;
F_3 ( L_3 , V_3 , V_4 , V_1 , V_2 ) ;
return - V_15 ;
}
int F_7 ( void )
{
if ( ! V_16 ++ ) {
V_6 . V_17 = F_8 ( F_9 () ) ;
if ( ! V_6 . V_17 ) {
V_16 = 0 ;
return - V_18 ;
}
V_6 . V_7 = NULL ;
V_6 . V_8 = 0 ;
F_5 ( & V_6 ) ;
}
return 0 ;
}
void F_10 ( void )
{
if ( ! -- V_16 ) {
F_4 ( & V_6 ) ;
F_11 ( V_6 . V_17 ) ;
}
}
