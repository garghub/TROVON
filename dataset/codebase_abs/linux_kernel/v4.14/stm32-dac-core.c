static struct V_1 * F_1 ( struct V_2 * V_3 )
{
return F_2 ( V_3 , struct V_1 , V_4 ) ;
}
static int F_3 ( struct V_5 * V_6 )
{
struct V_7 * V_8 = & V_6 -> V_8 ;
const struct V_9 * V_10 ;
struct V_1 * V_11 ;
struct V_12 * V_12 ;
struct V_13 * V_14 ;
void T_1 * V_15 ;
int V_16 ;
if ( ! V_8 -> V_17 )
return - V_18 ;
V_11 = F_4 ( V_8 , sizeof( * V_11 ) , V_19 ) ;
if ( ! V_11 )
return - V_20 ;
V_10 = ( const struct V_9 * )
F_5 ( V_8 -> V_21 -> V_22 , V_8 ) -> V_23 ;
V_14 = F_6 ( V_6 , V_24 , 0 ) ;
V_15 = F_7 ( V_8 , V_14 ) ;
if ( F_8 ( V_15 ) )
return F_9 ( V_15 ) ;
V_12 = F_10 ( V_8 , V_15 , & V_25 ) ;
if ( F_8 ( V_12 ) )
return F_9 ( V_12 ) ;
V_11 -> V_4 . V_12 = V_12 ;
V_11 -> V_26 = F_11 ( V_8 , L_1 ) ;
if ( F_8 ( V_11 -> V_26 ) ) {
V_16 = F_9 ( V_11 -> V_26 ) ;
F_12 ( V_8 , L_2 , V_16 ) ;
return V_16 ;
}
V_16 = F_13 ( V_11 -> V_26 ) ;
if ( V_16 < 0 ) {
F_12 ( V_8 , L_3 ) ;
return V_16 ;
}
V_16 = F_14 ( V_11 -> V_26 ) ;
if ( V_16 < 0 ) {
F_12 ( V_8 , L_4 , V_16 ) ;
goto V_27;
}
V_11 -> V_4 . V_28 = V_16 / 1000 ;
F_15 ( V_8 , L_5 , V_11 -> V_4 . V_28 ) ;
V_11 -> V_29 = F_16 ( V_8 , L_6 ) ;
if ( F_8 ( V_11 -> V_29 ) ) {
V_16 = F_9 ( V_11 -> V_29 ) ;
F_12 ( V_8 , L_7 ) ;
goto V_27;
}
V_16 = F_17 ( V_11 -> V_29 ) ;
if ( V_16 < 0 ) {
F_12 ( V_8 , L_8 ) ;
goto V_27;
}
V_11 -> V_30 = F_18 ( V_8 , NULL ) ;
if ( ! F_8 ( V_11 -> V_30 ) ) {
F_19 ( V_11 -> V_30 ) ;
F_20 ( 2 ) ;
F_21 ( V_11 -> V_30 ) ;
}
if ( V_10 && V_10 -> V_31 ) {
V_11 -> V_4 . V_32 = ( F_22 ( V_11 -> V_29 ) > 80000000UL ) ;
V_16 = F_23 ( V_12 , V_33 ,
V_34 ,
V_11 -> V_4 . V_32 ?
V_34 : 0 ) ;
if ( V_16 )
goto V_35;
}
F_24 ( V_6 , & V_11 -> V_4 ) ;
V_16 = F_25 ( V_6 -> V_8 . V_17 , NULL , NULL , V_8 ) ;
if ( V_16 < 0 ) {
F_12 ( V_8 , L_9 ) ;
goto V_35;
}
return 0 ;
V_35:
F_26 ( V_11 -> V_29 ) ;
V_27:
F_27 ( V_11 -> V_26 ) ;
return V_16 ;
}
static int F_28 ( struct V_5 * V_6 )
{
struct V_2 * V_4 = F_29 ( V_6 ) ;
struct V_1 * V_11 = F_1 ( V_4 ) ;
F_30 ( & V_6 -> V_8 ) ;
F_26 ( V_11 -> V_29 ) ;
F_27 ( V_11 -> V_26 ) ;
return 0 ;
}
