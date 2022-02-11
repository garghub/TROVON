static void F_1 ( void * V_1 )
{
struct V_2 * V_3 = V_1 ;
V_3 -> V_4 = F_2 ( V_3 -> V_5 ) ;
V_3 -> V_6 = V_7 ;
}
int F_3 ( void )
{
struct V_2 V_3 ;
int V_5 , V_6 ;
V_5 = F_4 ( L_1 , V_8 ) ;
if ( V_5 < 0 ) {
V_6 = - V_7 ;
F_5 ( V_9 L_2
L_3 , V_7 ) ;
return V_6 ;
}
V_3 . V_5 = V_5 ;
F_6 ( F_1 , & V_3 ) ;
if ( V_3 . V_4 < 0 ) {
V_6 = - V_3 . V_6 ;
F_5 ( V_9 L_4
L_5 , - V_3 . V_6 ) ;
goto V_10;
}
if ( F_7 ( V_5 ) < 0 ) {
V_6 = - V_7 ;
F_5 ( V_9 L_6
L_5 , V_7 ) ;
goto V_10;
}
return V_5 ;
V_10:
F_8 ( V_5 ) ;
return V_6 ;
}
