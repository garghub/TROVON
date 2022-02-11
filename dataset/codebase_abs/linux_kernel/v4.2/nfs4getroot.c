int F_1 ( struct V_1 * V_2 , struct V_3 * V_4 , bool V_5 )
{
struct V_6 V_7 ;
int V_8 = - V_9 ;
F_2 ( L_1 ) ;
V_7 . V_10 = F_3 () ;
if ( V_7 . V_10 == NULL )
goto V_11;
V_8 = F_4 ( V_2 , V_4 , & V_7 , V_5 ) ;
if ( V_8 < 0 ) {
F_2 ( L_2 , - V_8 ) ;
goto V_11;
}
if ( ! ( V_7 . V_10 -> V_12 & V_13 )
|| ! F_5 ( V_7 . V_10 -> V_14 ) ) {
F_6 ( V_15 L_3
L_4 ) ;
V_8 = - V_16 ;
goto V_11;
}
memcpy ( & V_2 -> V_17 , & V_7 . V_10 -> V_17 , sizeof( V_2 -> V_17 ) ) ;
V_11:
F_7 ( V_7 . V_10 ) ;
F_2 ( L_5 , V_8 ) ;
return V_8 ;
}
