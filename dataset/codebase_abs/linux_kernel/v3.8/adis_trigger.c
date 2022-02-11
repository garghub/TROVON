static int F_1 ( struct V_1 * V_2 ,
bool V_3 )
{
struct V_4 * V_4 = V_2 -> V_5 ;
return F_2 ( V_4 , V_3 ) ;
}
int F_3 ( struct V_4 * V_4 , struct V_6 * V_7 )
{
int V_8 ;
V_4 -> V_2 = F_4 ( L_1 , V_7 -> V_9 ,
V_7 -> V_10 ) ;
if ( V_4 -> V_2 == NULL )
return - V_11 ;
V_8 = F_5 ( V_4 -> V_12 -> V_13 ,
& V_14 ,
V_15 ,
V_7 -> V_9 ,
V_4 -> V_2 ) ;
if ( V_8 )
goto V_16;
V_4 -> V_2 -> V_17 . V_18 = & V_4 -> V_12 -> V_17 ;
V_4 -> V_2 -> V_19 = & V_20 ;
V_4 -> V_2 -> V_5 = V_4 ;
V_8 = F_6 ( V_4 -> V_2 ) ;
V_7 -> V_2 = V_4 -> V_2 ;
if ( V_8 )
goto V_21;
return 0 ;
V_21:
F_7 ( V_4 -> V_12 -> V_13 , V_4 -> V_2 ) ;
V_16:
F_8 ( V_4 -> V_2 ) ;
return V_8 ;
}
void F_9 ( struct V_4 * V_4 )
{
F_10 ( V_4 -> V_2 ) ;
F_7 ( V_4 -> V_12 -> V_13 , V_4 -> V_2 ) ;
F_8 ( V_4 -> V_2 ) ;
}
