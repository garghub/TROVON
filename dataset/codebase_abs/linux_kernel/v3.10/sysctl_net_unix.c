int T_1 F_1 ( struct V_1 * V_1 )
{
struct V_2 * V_3 ;
V_3 = F_2 ( V_4 , sizeof( V_4 ) , V_5 ) ;
if ( V_3 == NULL )
goto V_6;
if ( V_1 -> V_7 != & V_8 )
V_3 [ 0 ] . V_9 = NULL ;
V_3 [ 0 ] . V_10 = & V_1 -> V_11 . V_12 ;
V_1 -> V_11 . V_13 = F_3 ( V_1 , L_1 , V_3 ) ;
if ( V_1 -> V_11 . V_13 == NULL )
goto V_14;
return 0 ;
V_14:
F_4 ( V_3 ) ;
V_6:
return - V_15 ;
}
void F_5 ( struct V_1 * V_1 )
{
struct V_2 * V_3 ;
V_3 = V_1 -> V_11 . V_13 -> V_16 ;
F_6 ( V_1 -> V_11 . V_13 ) ;
F_4 ( V_3 ) ;
}
