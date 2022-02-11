static int F_1 ( struct V_1 * V_2 )
{
const struct V_3 * V_4 ;
struct V_5 * V_6 ;
int V_7 ;
V_6 = F_2 ( & V_2 -> V_8 , sizeof( * V_6 ) , V_9 ) ;
if ( ! V_6 )
return - V_10 ;
V_4 = F_3 ( & V_2 -> V_8 ) ;
if ( ! V_4 ) {
F_4 ( & V_2 -> V_8 , L_1 ) ;
return - V_11 ;
}
V_6 -> V_12 = F_5 ( & V_2 -> V_8 , L_2 , 0 ) ;
if ( F_6 ( V_6 -> V_12 ) ) {
V_7 = F_7 ( V_6 -> V_12 ) ;
F_4 ( & V_2 -> V_8 , L_3 , V_7 ) ;
return V_7 ;
}
V_6 -> V_13 = F_8 ( & V_2 -> V_8 , NULL ) ;
if ( F_6 ( V_6 -> V_13 ) ) {
V_7 = F_7 ( V_6 -> V_13 ) ;
F_4 ( & V_2 -> V_8 , L_4 , V_7 ) ;
return V_7 ;
}
V_7 = F_9 ( V_6 -> V_13 ) ;
if ( V_7 < 0 ) {
F_4 ( & V_2 -> V_8 , L_5 , V_7 ) ;
return V_7 ;
}
F_10 ( V_6 -> V_12 , 0 ) ;
V_6 -> V_14 . V_15 = L_6 ;
V_6 -> V_14 . V_16 = V_4 -> V_16 ;
V_6 -> V_14 . V_17 = V_6 -> V_12 ;
V_6 -> V_14 . V_18 = V_19 ;
V_6 -> V_8 = F_11 ( & V_2 -> V_8 , V_2 -> V_20 ,
V_2 -> V_21 , & V_6 -> V_14 ) ;
if ( F_6 ( V_6 -> V_8 ) ) {
V_7 = F_7 ( V_6 -> V_8 ) ;
F_4 ( & V_2 -> V_8 , L_7 , V_7 ) ;
goto V_22;
}
F_12 ( V_2 , V_6 ) ;
return 0 ;
V_22:
F_10 ( V_6 -> V_12 , 1 ) ;
F_13 ( V_6 -> V_13 ) ;
return V_7 ;
}
static int F_14 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_15 ( V_2 ) ;
F_10 ( V_6 -> V_12 , 1 ) ;
F_13 ( V_6 -> V_13 ) ;
return 0 ;
}
