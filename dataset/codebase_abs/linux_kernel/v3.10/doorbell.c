int F_1 ( struct V_1 * V_2 , unsigned long V_3 ,
struct V_4 * V_5 )
{
struct V_6 * V_7 ;
struct V_8 * V_9 ;
int V_10 = 0 ;
F_2 ( & V_2 -> V_11 ) ;
F_3 (page, &context->db_page_list, list)
if ( V_7 -> V_12 == ( V_3 & V_13 ) )
goto V_14;
V_7 = F_4 ( sizeof *V_7 , V_15 ) ;
if ( ! V_7 ) {
V_10 = - V_16 ;
goto V_17;
}
V_7 -> V_12 = ( V_3 & V_13 ) ;
V_7 -> V_18 = 0 ;
V_7 -> V_19 = F_5 ( & V_2 -> V_20 , V_3 & V_13 ,
V_21 , 0 , 0 ) ;
if ( F_6 ( V_7 -> V_19 ) ) {
V_10 = F_7 ( V_7 -> V_19 ) ;
F_8 ( V_7 ) ;
goto V_17;
}
F_9 ( & V_7 -> V_22 , & V_2 -> V_23 ) ;
V_14:
V_9 = F_10 ( V_7 -> V_19 -> V_24 . V_25 , struct V_8 , V_22 ) ;
V_5 -> V_26 = F_11 ( V_9 -> V_27 ) + ( V_3 & ~ V_13 ) ;
V_5 -> V_28 . V_29 = V_7 ;
++ V_7 -> V_18 ;
V_17:
F_12 ( & V_2 -> V_11 ) ;
return V_10 ;
}
void F_13 ( struct V_1 * V_2 , struct V_4 * V_5 )
{
F_2 ( & V_2 -> V_11 ) ;
if ( ! -- V_5 -> V_28 . V_29 -> V_18 ) {
F_14 ( & V_5 -> V_28 . V_29 -> V_22 ) ;
F_15 ( V_5 -> V_28 . V_29 -> V_19 ) ;
F_8 ( V_5 -> V_28 . V_29 ) ;
}
F_12 ( & V_2 -> V_11 ) ;
}
