void F_1 ( struct V_1 * V_2 )
{
F_2 ( & V_2 -> V_3 ) ;
F_2 ( & V_2 -> V_4 . V_5 ) ;
V_2 -> V_4 . V_6 = NULL ;
V_2 -> V_4 . V_7 = NULL ;
V_2 -> V_4 . V_8 = 0 ;
V_2 -> V_9 = NULL ;
}
void F_3 ( struct V_10 * V_11 , struct V_12 * V_13 ,
bool V_14 )
{
struct V_10 * V_15 = V_13 -> V_16 ;
struct V_17 * V_4 ;
V_4 = & F_4 ( V_15 ) -> V_18 . V_4 ;
F_5 ( V_11 ) -> V_19 = NULL ;
F_6 ( & V_4 -> V_5 ) ;
V_4 -> V_8 -- ;
F_7 ( V_13 ) -> V_20 = false ;
if ( V_13 -> V_11 )
goto V_21;
if ( ! V_14 || V_15 -> V_22 != V_23 ) {
F_8 ( & V_4 -> V_5 ) ;
F_9 ( V_13 ) ;
return;
}
V_13 -> V_24 . V_25 = V_26 + 60 * V_27 ;
if ( V_4 -> V_6 == NULL )
V_4 -> V_6 = V_13 ;
else
V_4 -> V_7 -> V_28 = V_13 ;
V_13 -> V_28 = NULL ;
V_4 -> V_7 = V_13 ;
V_4 -> V_8 ++ ;
V_21:
F_8 ( & V_4 -> V_5 ) ;
}
