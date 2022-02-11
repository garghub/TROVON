static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_3 = F_2 ( & V_2 -> V_4 ) ;
struct V_5 V_6 = { } ;
struct V_7 * V_8 ;
int V_9 ;
V_9 = F_3 ( V_3 -> V_10 , V_11 ,
V_12 , 0 ) ;
if ( V_9 ) {
F_4 ( & V_2 -> V_4 , L_1 ) ;
return V_9 ;
}
V_6 . V_4 = & V_2 -> V_4 ;
V_6 . V_13 = V_3 ;
V_6 . V_14 = V_3 -> V_10 ;
V_6 . V_15 = V_2 -> V_4 . V_15 ;
V_6 . V_16 = F_5 ( & V_2 -> V_4 ,
V_2 -> V_4 . V_15 ,
& V_17 ) ;
V_8 = F_6 ( & V_2 -> V_4 , & V_17 , & V_6 ) ;
if ( F_7 ( V_8 ) ) {
F_4 ( & V_2 -> V_4 ,
L_2 ) ;
return F_8 ( V_8 ) ;
}
F_9 ( & V_2 -> V_4 , L_3 ) ;
return 0 ;
}
