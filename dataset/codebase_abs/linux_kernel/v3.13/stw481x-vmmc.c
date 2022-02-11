static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_3 = F_2 ( & V_2 -> V_4 ) ;
struct V_5 V_6 = { } ;
int V_7 ;
V_7 = F_3 ( V_3 -> V_8 , V_9 ,
V_10 , 0 ) ;
if ( V_7 ) {
F_4 ( & V_2 -> V_4 , L_1 ) ;
return V_7 ;
}
V_6 . V_4 = & V_2 -> V_4 ;
V_6 . V_11 = V_3 ;
V_6 . V_12 = V_3 -> V_8 ;
V_6 . V_13 = V_2 -> V_4 . V_13 ;
V_6 . V_14 = F_5 ( & V_2 -> V_4 ,
V_2 -> V_4 . V_13 ) ;
V_3 -> V_15 = F_6 ( & V_15 , & V_6 ) ;
if ( F_7 ( V_3 -> V_15 ) ) {
F_4 ( & V_2 -> V_4 ,
L_2 ) ;
return F_8 ( V_3 -> V_15 ) ;
}
F_9 ( & V_2 -> V_4 , L_3 ) ;
return 0 ;
}
static int F_10 ( struct V_1 * V_2 )
{
struct V_3 * V_3 = F_2 ( & V_2 -> V_4 ) ;
F_11 ( V_3 -> V_15 ) ;
return 0 ;
}
