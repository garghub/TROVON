int F_1 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_5 V_6 ;
int V_7 = - V_8 ;
F_2 ( L_1 ) ;
V_6 . V_9 = F_3 () ;
if ( V_6 . V_9 == NULL )
goto V_10;
V_7 = F_4 ( V_2 , V_4 , & V_6 ) ;
if ( V_7 < 0 ) {
F_2 ( L_2 , - V_7 ) ;
goto V_10;
}
if ( ! ( V_6 . V_9 -> V_11 & V_12 )
|| ! F_5 ( V_6 . V_9 -> V_13 ) ) {
F_6 ( V_14 L_3
L_4 ) ;
V_7 = - V_15 ;
goto V_10;
}
if ( V_6 . V_9 -> V_11 & V_16 ) {
F_6 ( V_14 L_3
L_5 ) ;
V_7 = - V_17 ;
goto V_10;
}
memcpy ( & V_2 -> V_18 , & V_6 . V_9 -> V_18 , sizeof( V_2 -> V_18 ) ) ;
V_10:
F_7 ( V_6 . V_9 ) ;
F_2 ( L_6 , V_7 ) ;
return V_7 ;
}
