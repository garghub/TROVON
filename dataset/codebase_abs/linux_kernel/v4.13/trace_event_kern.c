int F_1 ( struct V_1 * V_2 )
{
char V_3 [] = L_1 ;
T_1 V_4 = F_2 () ;
struct V_5 V_6 ;
T_2 * V_7 , V_8 = 1 ;
if ( V_2 -> V_9 < 10000 )
return 0 ;
F_3 ( & V_6 . V_10 , sizeof( V_6 . V_10 ) ) ;
V_6 . V_11 = F_4 ( V_2 , & V_12 , V_13 ) ;
V_6 . V_14 = F_4 ( V_2 , & V_12 , V_15 ) ;
if ( ( int ) V_6 . V_11 < 0 && ( int ) V_6 . V_14 < 0 ) {
F_5 ( V_3 , sizeof( V_3 ) , V_4 , V_2 -> V_9 ,
F_6 ( & V_2 -> V_16 ) ) ;
return 0 ;
}
V_7 = F_7 ( & V_17 , & V_6 ) ;
if ( V_7 )
( * V_7 ) ++ ;
else
F_8 ( & V_17 , & V_6 , & V_8 , V_18 ) ;
return 0 ;
}
