static int F_1 ( struct V_1 * V_2 )
{
struct V_3 V_4 ;
int V_5 ;
if ( ! V_2 -> V_6 )
return 0 ;
memset ( & V_4 , 0 , sizeof( V_4 ) ) ;
V_4 . V_7 = V_2 -> V_6 -> V_7 ;
V_4 . V_8 = F_2 ( V_2 -> V_6 -> V_8 ) ;
V_4 . V_9 = F_2 ( V_2 -> V_6 -> V_9 ) ;
V_4 . V_10 = F_2 (
V_2 -> V_6 -> V_10 ) ;
V_4 . V_11 = V_4 . V_9 ;
V_4 . V_12 = F_2 ( V_2 -> V_6 -> V_12 ) ;
V_4 . V_13 = F_2 ( V_2 -> V_6 -> V_13 ) ;
V_4 . V_14 = F_2 ( V_2 -> V_6 -> V_14 ) ;
V_4 . V_15 = F_2 ( V_2 -> V_6 -> V_15 ) ;
V_4 . V_16 = F_2 (
V_2 -> V_6 -> V_16 ) ;
V_4 . V_17 = V_4 . V_11 ;
if ( F_3 () ) {
V_4 . V_18 = F_2 (
V_2 -> V_6 -> V_18 ) ;
V_4 . V_19 = F_2 (
V_2 -> V_6 -> V_19 ) ;
}
V_4 . V_20 = F_2 ( V_2 -> V_6 -> V_20 ) ;
V_4 . V_21 = F_2 ( V_2 -> V_6 -> V_21 ) ;
V_4 . V_22 = F_2 ( V_2 -> V_6 -> V_22 ) ;
if ( V_2 -> V_23 == V_24 )
F_4 ( V_2 -> V_25 , V_26 , 1 ) ;
else
F_4 ( V_2 -> V_25 , V_26 , 0 ) ;
F_4 ( V_2 -> V_25 ,
V_27 , V_28 ) ;
V_5 = F_5 ( V_2 -> V_25 , & V_4 ) ;
if ( V_5 )
return V_5 ;
return 0 ;
}
int T_1 F_6 ( struct V_1 * V_2 )
{
int V_5 = 0 ;
struct V_29 * V_30 = & V_31 . V_30 ;
V_31 . V_30 . V_32 = V_2 ;
V_5 = F_7 ( V_2 -> V_25 , V_33 ,
& V_2 -> V_34 ) ;
if ( V_5 < 0 ) {
F_8 ( V_30 , L_1 ) ;
return V_5 ;
}
V_5 = F_1 ( V_2 ) ;
if ( V_5 < 0 ) {
F_8 ( V_30 , L_2 , V_5 ) ;
return V_5 ;
}
if ( V_2 -> V_35 ) {
F_4 ( V_2 -> V_25 , V_36 , 1 ) ;
}
V_5 = F_9 ( & V_31 ) ;
if ( V_5 < 0 ) {
F_8 ( V_30 , L_3 ) ;
goto V_37;
}
return 0 ;
V_37:
F_10 ( V_2 -> V_25 ) ;
return V_5 ;
}
