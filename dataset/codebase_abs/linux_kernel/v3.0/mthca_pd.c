int F_1 ( struct V_1 * V_2 , int V_3 , struct V_4 * V_5 )
{
int V_6 = 0 ;
V_5 -> V_3 = V_3 ;
F_2 ( & V_5 -> V_7 , 0 ) ;
V_5 -> V_8 = F_3 ( & V_2 -> V_9 . V_10 ) ;
if ( V_5 -> V_8 == - 1 )
return - V_11 ;
if ( V_3 ) {
V_6 = F_4 ( V_2 , V_5 -> V_8 ,
V_12 |
V_13 ,
& V_5 -> V_14 ) ;
if ( V_6 )
F_5 ( & V_2 -> V_9 . V_10 , V_5 -> V_8 ) ;
}
return V_6 ;
}
void F_6 ( struct V_1 * V_2 , struct V_4 * V_5 )
{
if ( V_5 -> V_3 )
F_7 ( V_2 , & V_5 -> V_14 ) ;
F_5 ( & V_2 -> V_9 . V_10 , V_5 -> V_8 ) ;
}
int F_8 ( struct V_1 * V_2 )
{
return F_9 ( & V_2 -> V_9 . V_10 ,
V_2 -> V_15 . V_16 ,
( 1 << 24 ) - 1 ,
V_2 -> V_15 . V_17 ) ;
}
void F_10 ( struct V_1 * V_2 )
{
F_11 ( & V_2 -> V_9 . V_10 ) ;
}
