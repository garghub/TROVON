void F_1 ( struct V_1 * V_2 )
{
F_2 ( & V_2 -> V_3 ) ;
}
int F_3 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = V_2 -> V_5 ;
int V_6 ;
if ( V_2 -> V_7 ) {
V_6 = F_4 ( & V_2 -> V_7 -> V_8 ,
& V_5 -> V_9 . V_10 . V_8 , L_1 ) ;
if ( V_6 < 0 )
return V_6 ;
V_6 = F_4 ( & V_5 -> V_9 . V_10 . V_8 ,
& V_2 -> V_7 -> V_8 , V_2 -> V_11 ) ;
if ( V_6 < 0 ) {
F_5 ( & V_2 -> V_7 -> V_8 , L_1 ) ;
return V_6 ;
}
}
V_2 -> V_12 = F_6 ( V_2 ) ;
F_7 ( & V_5 -> V_9 . V_13 ) ;
F_8 ( & V_2 -> V_3 , & V_5 -> V_14 ) ;
F_9 ( & V_5 -> V_9 . V_13 ) ;
return 0 ;
}
void F_10 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = V_2 -> V_5 ;
F_11 ( V_2 ) ;
F_7 ( & V_5 -> V_9 . V_13 ) ;
F_12 ( & V_2 -> V_3 ) ;
F_9 ( & V_5 -> V_9 . V_13 ) ;
F_13 ( V_2 -> V_12 ) ;
if ( V_2 -> V_7 ) {
F_5 ( & V_5 -> V_9 . V_10 . V_8 , V_2 -> V_11 ) ;
F_5 ( & V_2 -> V_7 -> V_8 , L_1 ) ;
}
}
void F_14 ( struct V_4 * V_5 )
{
F_2 ( & V_5 -> V_14 ) ;
}
