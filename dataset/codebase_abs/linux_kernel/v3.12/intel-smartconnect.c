static int F_1 ( struct V_1 * V_2 )
{
struct V_3 V_4 ;
struct V_5 V_6 = { V_7 , NULL } ;
union V_8 * V_9 ;
union V_8 V_10 ;
T_1 V_11 ;
V_11 = F_2 ( V_2 -> V_12 , L_1 , NULL , & V_6 ) ;
if ( ! F_3 ( V_11 ) )
return - V_13 ;
V_9 = V_6 . V_14 ;
if ( V_9 -> type != V_15 ) {
F_4 ( V_9 ) ;
return - V_13 ;
}
if ( V_9 -> integer . V_16 & 0x1 ) {
V_10 . type = V_15 ;
V_10 . integer . V_16 = 0 ;
V_4 . V_17 = 1 ;
V_4 . V_14 = & V_10 ;
F_5 ( & V_2 -> V_18 , L_2 ) ;
V_11 = F_2 ( V_2 -> V_12 , L_3 , & V_4 ,
NULL ) ;
}
F_4 ( V_9 ) ;
return 0 ;
}
