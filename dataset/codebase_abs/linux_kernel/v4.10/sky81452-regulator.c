static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = & V_2 -> V_4 ;
const struct V_5 * V_6 = F_2 ( V_4 ) ;
struct V_7 V_8 = { } ;
struct V_9 * V_10 ;
V_8 . V_4 = V_4 -> V_11 ;
V_8 . V_6 = V_6 ;
V_8 . V_12 = V_4 -> V_12 ;
V_8 . V_13 = F_3 ( V_4 -> V_11 ) ;
V_10 = F_4 ( V_4 , & V_14 , & V_8 ) ;
if ( F_5 ( V_10 ) ) {
F_6 ( V_4 , L_1 , F_7 ( V_10 ) ) ;
return F_7 ( V_10 ) ;
}
F_8 ( V_2 , V_10 ) ;
return 0 ;
}
