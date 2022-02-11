int T_1 F_1 ( struct V_1 * V_1 )
{
struct V_2 * V_3 ;
V_3 = F_2 ( V_4 , sizeof( V_4 ) , V_5 ) ;
if ( V_3 == NULL )
goto V_6;
V_3 [ 0 ] . V_7 = & V_1 -> V_8 . V_9 ;
V_1 -> V_8 . V_10 = F_3 ( V_1 , V_11 , V_3 ) ;
if ( V_1 -> V_8 . V_10 == NULL )
goto V_12;
return 0 ;
V_12:
F_4 ( V_3 ) ;
V_6:
return - V_13 ;
}
void F_5 ( struct V_1 * V_1 )
{
struct V_2 * V_3 ;
V_3 = V_1 -> V_8 . V_10 -> V_14 ;
F_6 ( V_1 -> V_8 . V_10 ) ;
F_4 ( V_3 ) ;
}
