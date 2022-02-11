static int F_1 ( struct V_1 * V_2 ,
bool V_3 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
F_2 ( & V_5 -> V_7 , L_1 , V_8 , V_3 ) ;
return F_3 ( V_5 , V_3 ) ;
}
int F_4 ( struct V_4 * V_5 )
{
int V_9 ;
struct V_10 * V_11 = F_5 ( V_5 ) ;
V_11 -> V_2 = F_6 ( L_2 ,
F_7 ( V_11 -> V_12 ) -> V_13 ,
V_5 -> V_14 ) ;
if ( V_11 -> V_2 == NULL ) {
V_9 = - V_15 ;
goto V_16;
}
V_9 = F_8 ( V_11 -> V_12 -> V_17 ,
& V_18 ,
V_19 ,
L_3 ,
V_11 -> V_2 ) ;
if ( V_9 )
goto V_20;
V_11 -> V_2 -> V_7 . V_21 = & V_11 -> V_12 -> V_7 ;
V_11 -> V_2 -> V_22 = V_23 ;
V_11 -> V_2 -> V_6 = V_5 ;
V_11 -> V_2 -> V_24 = & F_1 ;
V_9 = F_9 ( V_11 -> V_2 ) ;
V_5 -> V_2 = V_11 -> V_2 ;
if ( V_9 )
goto V_25;
return 0 ;
V_25:
F_10 ( V_11 -> V_12 -> V_17 , V_11 -> V_2 ) ;
V_20:
F_11 ( V_11 -> V_2 ) ;
V_16:
return V_9 ;
}
void F_12 ( struct V_4 * V_5 )
{
struct V_10 * V_11 = F_5 ( V_5 ) ;
F_13 ( V_11 -> V_2 ) ;
F_10 ( V_11 -> V_12 -> V_17 , V_11 -> V_2 ) ;
F_11 ( V_11 -> V_2 ) ;
}
