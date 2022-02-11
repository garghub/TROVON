static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
if ( V_5 . V_6 == NULL )
return - V_7 ;
F_2 ( L_1 , V_2 -> V_2 . V_8 -> V_9 ) ;
V_4 = F_3 ( V_2 -> V_2 . V_8 ) ;
if ( ! V_4 )
return - V_7 ;
V_4 -> V_10 = & V_2 -> V_2 ;
if ( V_5 . V_6 ( V_4 ) ) {
F_4 ( V_4 ) ;
return - V_7 ;
}
F_5 ( V_4 , V_2 -> V_2 . V_8 , 0 ) ;
F_6 ( V_4 ) ;
F_7 ( V_4 ) ;
if ( V_2 -> V_2 . V_8 -> V_11 )
F_8 ( F_9 ( V_2 -> V_2 . V_8 ) ) ;
F_10 ( V_4 ) ;
if ( V_4 -> V_12 == NULL )
return - V_13 ;
F_11 ( V_4 -> V_12 ) ;
F_12 ( V_4 -> V_12 ) ;
F_13 ( V_4 -> V_12 ) ;
F_14 ( V_4 -> V_12 ) ;
return 0 ;
}
