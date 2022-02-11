int F_1 ( struct V_1 * V_2 , unsigned long V_3 ,
struct V_4 * V_5 )
{
struct V_6 * V_7 ;
int V_8 = 0 ;
F_2 ( & V_2 -> V_9 ) ;
F_3 (page, &context->db_page_list, list)
if ( V_7 -> V_10 == ( V_3 & V_11 ) )
goto V_12;
V_7 = F_4 ( sizeof *V_7 , V_13 ) ;
if ( ! V_7 ) {
V_8 = - V_14 ;
goto V_15;
}
V_7 -> V_10 = ( V_3 & V_11 ) ;
V_7 -> V_16 = 0 ;
V_7 -> V_17 = F_5 ( & V_2 -> V_18 , V_3 & V_11 ,
V_19 , 0 , 0 ) ;
if ( F_6 ( V_7 -> V_17 ) ) {
V_8 = F_7 ( V_7 -> V_17 ) ;
F_8 ( V_7 ) ;
goto V_15;
}
F_9 ( & V_7 -> V_20 , & V_2 -> V_21 ) ;
V_12:
V_5 -> V_22 = F_10 ( V_7 -> V_17 -> V_23 . V_24 ) + ( V_3 & ~ V_11 ) ;
V_5 -> V_25 . V_26 = V_7 ;
++ V_7 -> V_16 ;
V_15:
F_11 ( & V_2 -> V_9 ) ;
return V_8 ;
}
void F_12 ( struct V_1 * V_2 , struct V_4 * V_5 )
{
F_2 ( & V_2 -> V_9 ) ;
if ( ! -- V_5 -> V_25 . V_26 -> V_16 ) {
F_13 ( & V_5 -> V_25 . V_26 -> V_20 ) ;
F_14 ( V_5 -> V_25 . V_26 -> V_17 ) ;
F_8 ( V_5 -> V_25 . V_26 ) ;
}
F_11 ( & V_2 -> V_9 ) ;
}
