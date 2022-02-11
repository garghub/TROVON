int F_1 ( struct V_1 * V_2 )
{
int V_3 = 0 ;
if ( ! ( V_2 -> V_4 . V_5 & V_6 ) )
return 0 ;
if ( V_2 -> V_4 . V_7 == NULL ) {
F_2 ( L_1 ) ;
return - V_8 ;
}
F_3 ( V_2 -> V_9 . V_10 , V_2 -> V_11 -> V_10 , sizeof( V_2 -> V_9 . V_10 ) ) ;
V_2 -> V_9 . V_12 = V_2 -> V_4 . V_7 ;
V_2 -> V_9 . V_13 = NULL ;
V_2 -> V_9 . V_14 . V_15 = & V_2 -> V_16 -> V_14 ;
F_4 ( & V_2 -> V_9 , V_2 ) ;
if ( ( V_3 = F_5 ( & V_2 -> V_9 ) ) < 0 )
F_2 ( L_2 ) ;
V_2 -> V_17 |= V_18 ;
return V_3 ;
}
int F_6 ( struct V_1 * V_2 )
{
if ( V_2 -> V_17 & V_18 )
F_7 ( & V_2 -> V_9 ) ;
V_2 -> V_17 &= ~ V_18 ;
return 0 ;
}
