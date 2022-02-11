int F_1 ( struct V_1 * V_2 ,
const struct V_3 * V_4 )
{
int V_5 ;
struct V_6 * V_7 = F_2 ( V_2 ) ;
V_7 -> V_8 = F_3 ( L_1 , V_2 -> V_9 ) ;
if ( V_7 -> V_8 == NULL ) {
V_5 = - V_10 ;
F_4 ( & V_2 -> V_11 , L_2 ) ;
goto V_12;
}
V_5 = F_5 ( V_7 -> V_13 ( V_2 ) ,
V_14 ,
NULL ,
V_15 ,
V_7 -> V_8 -> V_9 ,
V_7 -> V_8 ) ;
if ( V_5 )
goto V_16;
F_6 ( V_7 -> V_8 , V_2 ) ;
V_7 -> V_8 -> V_17 = V_4 ;
V_7 -> V_8 -> V_11 . V_18 = V_7 -> V_11 ;
V_5 = F_7 ( V_7 -> V_8 ) ;
if ( V_5 < 0 ) {
F_4 ( & V_2 -> V_11 , L_3 ) ;
goto V_19;
}
V_2 -> V_8 = F_8 ( V_7 -> V_8 ) ;
return 0 ;
V_19:
F_9 ( V_7 -> V_13 ( V_2 ) , V_7 -> V_8 ) ;
V_16:
F_10 ( V_7 -> V_8 ) ;
V_12:
return V_5 ;
}
void F_11 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
F_12 ( V_7 -> V_8 ) ;
F_9 ( V_7 -> V_13 ( V_2 ) , V_7 -> V_8 ) ;
F_10 ( V_7 -> V_8 ) ;
}
