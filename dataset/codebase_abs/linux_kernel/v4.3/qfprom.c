static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
return F_3 ( V_4 ) ;
}
static int F_4 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = & V_2 -> V_6 ;
struct V_7 * V_8 ;
struct V_3 * V_4 ;
struct V_9 * V_9 ;
void T_1 * V_10 ;
V_8 = F_5 ( V_2 , V_11 , 0 ) ;
V_10 = F_6 ( V_6 , V_8 ) ;
if ( F_7 ( V_10 ) )
return F_8 ( V_10 ) ;
V_12 . V_13 = F_9 ( V_8 ) - 1 ;
V_9 = F_10 ( V_6 , V_10 , & V_12 ) ;
if ( F_7 ( V_9 ) ) {
F_11 ( V_6 , L_1 ) ;
return F_8 ( V_9 ) ;
}
V_14 . V_6 = V_6 ;
V_4 = F_12 ( & V_14 ) ;
if ( F_7 ( V_4 ) )
return F_8 ( V_4 ) ;
F_13 ( V_2 , V_4 ) ;
return 0 ;
}
