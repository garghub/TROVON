static struct V_1 * F_1 ( struct V_2 * V_3 )
{
return F_2 ( V_3 , struct V_1 , V_4 ) ;
}
static int F_3 ( struct V_5 * V_6 )
{
struct V_7 * V_8 = & V_6 -> V_8 ;
struct V_1 * V_9 ;
struct V_10 * V_10 ;
struct V_11 * V_12 ;
void T_1 * V_13 ;
int V_14 ;
if ( ! V_8 -> V_15 )
return - V_16 ;
V_9 = F_4 ( V_8 , sizeof( * V_9 ) , V_17 ) ;
if ( ! V_9 )
return - V_18 ;
V_12 = F_5 ( V_6 , V_19 , 0 ) ;
V_13 = F_6 ( V_8 , V_12 ) ;
if ( F_7 ( V_13 ) )
return F_8 ( V_13 ) ;
V_10 = F_9 ( V_8 , V_13 , & V_20 ) ;
if ( F_7 ( V_10 ) )
return F_8 ( V_10 ) ;
V_9 -> V_4 . V_10 = V_10 ;
V_9 -> V_21 = F_10 ( V_8 , L_1 ) ;
if ( F_7 ( V_9 -> V_21 ) ) {
V_14 = F_8 ( V_9 -> V_21 ) ;
F_11 ( V_8 , L_2 , V_14 ) ;
return V_14 ;
}
V_14 = F_12 ( V_9 -> V_21 ) ;
if ( V_14 < 0 ) {
F_11 ( V_8 , L_3 ) ;
return V_14 ;
}
V_14 = F_13 ( V_9 -> V_21 ) ;
if ( V_14 < 0 ) {
F_11 ( V_8 , L_4 , V_14 ) ;
goto V_22;
}
V_9 -> V_4 . V_23 = V_14 / 1000 ;
F_14 ( V_8 , L_5 , V_9 -> V_4 . V_23 ) ;
V_9 -> V_24 = F_15 ( V_8 , L_6 ) ;
if ( F_7 ( V_9 -> V_24 ) ) {
V_14 = F_8 ( V_9 -> V_24 ) ;
F_11 ( V_8 , L_7 ) ;
goto V_22;
}
V_14 = F_16 ( V_9 -> V_24 ) ;
if ( V_14 < 0 ) {
F_11 ( V_8 , L_8 ) ;
goto V_22;
}
V_9 -> V_25 = F_17 ( V_8 , NULL ) ;
if ( ! F_7 ( V_9 -> V_25 ) ) {
F_18 ( V_9 -> V_25 ) ;
F_19 ( 2 ) ;
F_20 ( V_9 -> V_25 ) ;
}
V_9 -> V_4 . V_26 = ( F_21 ( V_9 -> V_24 ) > 80000000UL ) ;
V_14 = F_22 ( V_10 , V_27 , V_28 ,
V_9 -> V_4 . V_26 ? V_28 : 0 ) ;
if ( V_14 )
goto V_29;
F_23 ( V_6 , & V_9 -> V_4 ) ;
V_14 = F_24 ( V_6 -> V_8 . V_15 , NULL , NULL , V_8 ) ;
if ( V_14 < 0 ) {
F_11 ( V_8 , L_9 ) ;
goto V_29;
}
return 0 ;
V_29:
F_25 ( V_9 -> V_24 ) ;
V_22:
F_26 ( V_9 -> V_21 ) ;
return V_14 ;
}
static int F_27 ( struct V_5 * V_6 )
{
struct V_2 * V_4 = F_28 ( V_6 ) ;
struct V_1 * V_9 = F_1 ( V_4 ) ;
F_29 ( & V_6 -> V_8 ) ;
F_25 ( V_9 -> V_24 ) ;
F_26 ( V_9 -> V_21 ) ;
return 0 ;
}
