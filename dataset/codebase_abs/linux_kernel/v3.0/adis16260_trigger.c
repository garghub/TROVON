static int F_1 ( struct V_1 * V_2 ,
bool V_3 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
struct V_7 * V_8 = V_5 -> V_8 ;
F_2 ( & V_8 -> V_9 , L_1 , V_10 , V_3 ) ;
return F_3 ( V_8 , V_3 ) ;
}
int F_4 ( struct V_7 * V_8 )
{
int V_11 ;
struct V_4 * V_5 = V_8 -> V_12 ;
V_5 -> V_2 = F_5 ( L_2 ,
F_6 ( V_5 -> V_13 ) -> V_14 ,
V_8 -> V_15 ) ;
if ( V_5 -> V_2 == NULL ) {
V_11 = - V_16 ;
goto V_17;
}
V_11 = F_7 ( V_5 -> V_13 -> V_18 ,
& V_19 ,
V_20 ,
L_3 ,
V_5 -> V_2 ) ;
if ( V_11 )
goto V_21;
V_5 -> V_2 -> V_9 . V_22 = & V_5 -> V_13 -> V_9 ;
V_5 -> V_2 -> V_23 = V_24 ;
V_5 -> V_2 -> V_6 = V_5 ;
V_5 -> V_2 -> V_25 = & F_1 ;
V_11 = F_8 ( V_5 -> V_2 ) ;
V_8 -> V_2 = V_5 -> V_2 ;
if ( V_11 )
goto V_26;
return 0 ;
V_26:
F_9 ( V_5 -> V_13 -> V_18 , V_5 -> V_2 ) ;
V_21:
F_10 ( V_5 -> V_2 ) ;
V_17:
return V_11 ;
}
void F_11 ( struct V_7 * V_8 )
{
struct V_4 * V_3 = V_8 -> V_12 ;
F_12 ( V_3 -> V_2 ) ;
F_9 ( V_3 -> V_13 -> V_18 , V_3 -> V_2 ) ;
F_10 ( V_3 -> V_2 ) ;
}
