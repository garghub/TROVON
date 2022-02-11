static int F_1 ( struct V_1 * V_2 ,
bool V_3 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
struct V_7 * V_8 = V_5 -> V_8 ;
F_2 ( & V_8 -> V_9 , L_1 , V_10 , V_3 ) ;
return F_3 ( V_5 -> V_8 , V_3 ) ;
}
int F_4 ( struct V_7 * V_8 )
{
int V_11 ;
struct V_4 * V_5 = V_8 -> V_12 ;
V_5 -> V_2 = F_5 ( L_2 , V_8 -> V_13 ) ;
if ( V_5 -> V_2 == NULL ) {
V_11 = - V_14 ;
goto V_15;
}
V_11 = F_6 ( V_5 -> V_16 -> V_17 ,
& V_18 ,
V_19 ,
L_3 ,
V_5 -> V_2 ) ;
if ( V_11 )
goto V_20;
V_5 -> V_2 -> V_9 . V_21 = & V_5 -> V_16 -> V_9 ;
V_5 -> V_2 -> V_22 = V_23 ;
V_5 -> V_2 -> V_6 = V_5 ;
V_5 -> V_2 -> V_24 = & F_1 ;
V_11 = F_7 ( V_5 -> V_2 ) ;
V_8 -> V_2 = V_5 -> V_2 ;
if ( V_11 )
goto V_25;
return 0 ;
V_25:
F_8 ( V_5 -> V_16 -> V_17 , V_5 -> V_2 ) ;
V_20:
F_9 ( V_5 -> V_2 ) ;
V_15:
return V_11 ;
}
void F_10 ( struct V_7 * V_8 )
{
struct V_4 * V_3 = V_8 -> V_12 ;
F_11 ( V_3 -> V_2 ) ;
F_8 ( V_3 -> V_16 -> V_17 , V_3 -> V_2 ) ;
F_9 ( V_3 -> V_2 ) ;
}
