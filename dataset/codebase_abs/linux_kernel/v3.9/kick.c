void F_1 ( struct V_1 * V_2 )
{
unsigned long V_3 ;
F_2 ( & V_4 , V_3 ) ;
F_3 ( & V_2 -> V_5 , & V_6 ) ;
F_4 ( & V_4 , V_3 ) ;
}
void F_5 ( struct V_1 * V_2 )
{
unsigned long V_3 ;
F_2 ( & V_4 , V_3 ) ;
F_6 ( & V_2 -> V_5 ) ;
F_4 ( & V_4 , V_3 ) ;
}
T_1
F_7 ( T_1 V_7 , int V_8 , int V_9 , int V_10 , T_2 V_11 )
{
struct V_1 * V_2 ;
struct V_12 * V_13 ;
int V_14 = 0 ;
T_1 V_15 ;
F_8 ( V_7 , ~ V_16 ) ;
if ( V_7 . V_17 . V_18 & V_19 )
F_9 ( V_7 ) ;
F_10 () ;
F_11 ( & V_4 ) ;
F_12 (lh, &kick_handlers_list) {
V_2 = F_13 ( V_13 , struct V_1 , V_5 ) ;
V_15 = V_2 -> V_20 ( V_7 , V_8 , V_9 , V_10 , V_11 , & V_14 ) ;
if ( V_14 )
break;
}
F_14 ( & V_4 ) ;
F_15 ( ! V_14 ) ;
return F_16 ( V_15 ) ;
}
