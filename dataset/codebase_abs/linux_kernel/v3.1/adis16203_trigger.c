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
V_11 -> V_2 = F_6 ( L_2 , V_5 -> V_12 ) ;
if ( V_11 -> V_2 == NULL ) {
V_9 = - V_13 ;
goto V_14;
}
V_9 = F_7 ( V_11 -> V_15 -> V_16 ,
& V_17 ,
V_18 ,
L_3 ,
V_11 -> V_2 ) ;
if ( V_9 )
goto V_19;
V_11 -> V_2 -> V_7 . V_20 = & V_11 -> V_15 -> V_7 ;
V_11 -> V_2 -> V_21 = V_22 ;
V_11 -> V_2 -> V_6 = V_5 ;
V_11 -> V_2 -> V_23 = & F_1 ;
V_9 = F_8 ( V_11 -> V_2 ) ;
V_5 -> V_2 = V_11 -> V_2 ;
if ( V_9 )
goto V_24;
return 0 ;
V_24:
F_9 ( V_11 -> V_15 -> V_16 , V_11 -> V_2 ) ;
V_19:
F_10 ( V_11 -> V_2 ) ;
V_14:
return V_9 ;
}
void F_11 ( struct V_4 * V_5 )
{
struct V_10 * V_11 = F_5 ( V_5 ) ;
F_12 ( V_11 -> V_2 ) ;
F_9 ( V_11 -> V_15 -> V_16 , V_11 -> V_2 ) ;
F_10 ( V_11 -> V_2 ) ;
}
