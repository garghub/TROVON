static void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
if ( V_4 -> V_5 )
F_3 ( V_4 -> V_5 ) ;
}
int F_4 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
int V_6 ;
V_6 = F_5 ( V_2 , V_2 -> V_7 . V_8 ) ;
if ( V_6 < 0 ) {
F_6 ( V_2 -> V_2 , L_1 ) ;
return V_6 ;
}
V_2 -> V_7 . V_9 = 2048 ;
V_2 -> V_7 . V_10 = 2048 ;
V_2 -> V_7 . V_11 = & V_12 ;
V_2 -> V_7 . V_13 = 24 ;
V_2 -> V_14 = true ;
F_7 ( V_2 ) ;
V_4 -> V_5 = F_8 ( V_2 , 32 ,
V_2 -> V_7 . V_8 ,
V_2 -> V_7 . V_15 ) ;
if ( F_9 ( V_4 -> V_5 ) )
V_4 -> V_5 = NULL ;
F_10 ( V_2 ) ;
return 0 ;
}
