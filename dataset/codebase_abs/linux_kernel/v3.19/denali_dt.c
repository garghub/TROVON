static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 , * V_5 ;
struct V_6 * V_7 ;
struct V_8 * V_9 ;
int V_10 ;
const struct V_11 * V_12 ;
V_12 = F_2 ( V_13 , & V_2 -> V_14 ) ;
if ( V_12 ) {
V_2 -> V_15 = V_12 -> V_16 ;
} else {
F_3 ( L_1 ) ;
return - V_17 ;
}
V_7 = F_4 ( & V_2 -> V_14 , sizeof( * V_7 ) , V_18 ) ;
if ( ! V_7 )
return - V_17 ;
V_9 = & V_7 -> V_9 ;
V_9 -> V_19 = V_20 ;
V_9 -> V_14 = & V_2 -> V_14 ;
V_9 -> V_21 = F_5 ( V_2 , 0 ) ;
if ( V_9 -> V_21 < 0 ) {
F_6 ( & V_2 -> V_14 , L_2 ) ;
return V_9 -> V_21 ;
}
V_4 = F_7 ( V_2 , V_22 , L_3 ) ;
V_9 -> V_23 = F_8 ( & V_2 -> V_14 , V_4 ) ;
if ( F_9 ( V_9 -> V_23 ) )
return F_10 ( V_9 -> V_23 ) ;
V_5 = F_7 ( V_2 , V_22 , L_4 ) ;
V_9 -> V_24 = F_8 ( & V_2 -> V_14 , V_5 ) ;
if ( F_9 ( V_9 -> V_24 ) )
return F_10 ( V_9 -> V_24 ) ;
if ( ! F_11 ( V_2 -> V_14 . V_25 ,
L_5 , ( V_26 * ) & V_27 ) ) {
V_9 -> V_14 -> V_28 = & V_27 ;
} else {
V_9 -> V_14 -> V_28 = NULL ;
}
V_7 -> V_29 = F_12 ( & V_2 -> V_14 , NULL ) ;
if ( F_9 ( V_7 -> V_29 ) ) {
F_6 ( & V_2 -> V_14 , L_6 ) ;
return F_10 ( V_7 -> V_29 ) ;
}
F_13 ( V_7 -> V_29 ) ;
V_10 = F_14 ( V_9 ) ;
if ( V_10 )
goto V_30;
F_15 ( V_2 , V_7 ) ;
return 0 ;
V_30:
F_16 ( V_7 -> V_29 ) ;
return V_10 ;
}
static int F_17 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = F_18 ( V_2 ) ;
F_19 ( & V_7 -> V_9 ) ;
F_20 ( V_7 -> V_29 ) ;
return 0 ;
}
