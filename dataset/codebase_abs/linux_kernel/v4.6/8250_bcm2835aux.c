static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
struct V_5 * V_6 ;
int V_7 ;
V_4 = F_2 ( & V_2 -> V_8 , sizeof( * V_4 ) , V_9 ) ;
if ( ! V_4 )
return - V_10 ;
F_3 ( & V_4 -> V_11 . V_12 . V_13 ) ;
V_4 -> V_11 . V_14 = V_15 ;
V_4 -> V_11 . V_12 . V_8 = & V_2 -> V_8 ;
V_4 -> V_11 . V_12 . V_16 = 2 ;
V_4 -> V_11 . V_12 . type = V_17 ;
V_4 -> V_11 . V_12 . V_18 = V_19 ;
V_4 -> V_11 . V_12 . V_20 = 8 ;
V_4 -> V_11 . V_12 . V_21 = V_22 |
V_23 |
V_24 |
V_25 ;
V_4 -> V_26 = F_4 ( & V_2 -> V_8 , NULL ) ;
V_7 = F_5 ( V_4 -> V_26 ) ;
if ( V_7 ) {
F_6 ( & V_2 -> V_8 , L_1 , V_7 ) ;
return V_7 ;
}
V_7 = F_7 ( V_2 , 0 ) ;
if ( V_7 < 0 ) {
F_6 ( & V_2 -> V_8 , L_2 , V_7 ) ;
return V_7 ;
}
V_4 -> V_11 . V_12 . V_27 = V_7 ;
V_6 = F_8 ( V_2 , V_28 , 0 ) ;
if ( ! V_6 ) {
F_6 ( & V_2 -> V_8 , L_3 ) ;
return - V_29 ;
}
V_4 -> V_11 . V_12 . V_30 = F_9 ( & V_2 -> V_8 , V_6 ) ;
V_7 = F_5 ( V_4 -> V_11 . V_12 . V_30 ) ;
if ( V_7 )
return V_7 ;
V_7 = F_10 ( V_2 -> V_8 . V_31 , L_4 ) ;
if ( V_7 >= 0 )
V_4 -> V_11 . V_12 . line = V_7 ;
V_7 = F_11 ( V_4 -> V_26 ) ;
if ( V_7 ) {
F_6 ( & V_2 -> V_8 , L_5 ,
V_7 ) ;
return V_7 ;
}
V_4 -> V_11 . V_12 . V_32 = F_12 ( V_4 -> V_26 ) * 2 ;
V_7 = F_13 ( & V_4 -> V_11 ) ;
if ( V_7 < 0 ) {
F_6 ( & V_2 -> V_8 , L_6 ,
V_7 ) ;
goto V_33;
}
V_4 -> line = V_7 ;
F_14 ( V_2 , V_4 ) ;
return 0 ;
V_33:
F_15 ( V_4 -> V_26 ) ;
return V_7 ;
}
static int F_16 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_17 ( V_2 ) ;
F_18 ( V_4 -> V_11 . V_12 . line ) ;
F_15 ( V_4 -> V_26 ) ;
return 0 ;
}
