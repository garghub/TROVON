int F_1 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
V_4 -> V_5 = F_2 ( & V_2 -> V_6 . V_7 ) ;
if ( V_4 -> V_5 == - 1 )
return - V_8 ;
V_4 -> V_9 = ( F_3 ( V_2 -> V_10 , 2 ) >> V_11 ) + V_4 -> V_5 ;
return 0 ;
}
void F_4 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
F_5 ( & V_2 -> V_6 . V_7 , V_4 -> V_5 ) ;
}
int F_6 ( struct V_1 * V_2 )
{
int V_12 ;
V_12 = F_7 ( & V_2 -> V_6 . V_7 ,
V_2 -> V_13 . V_14 ,
V_2 -> V_13 . V_14 - 1 ,
V_2 -> V_13 . V_15 + 1 ) ;
if ( V_12 )
return V_12 ;
V_12 = F_8 ( V_2 ) ;
if ( V_12 )
F_9 ( & V_2 -> V_6 . V_7 ) ;
return V_12 ;
}
void F_10 ( struct V_1 * V_2 )
{
F_11 ( V_2 ) ;
F_9 ( & V_2 -> V_6 . V_7 ) ;
}
