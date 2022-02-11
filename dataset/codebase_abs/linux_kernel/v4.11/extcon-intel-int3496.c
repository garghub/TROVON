static void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 =
F_2 ( V_2 , struct V_3 , V_2 . V_2 ) ;
int V_5 = F_3 ( V_4 -> V_6 ) ;
F_4 ( V_4 -> V_7 , L_1 , V_5 ? L_2 : L_3 ) ;
if ( ! F_5 ( V_4 -> V_8 ) )
F_6 ( V_4 -> V_8 , V_5 ) ;
if ( ! F_5 ( V_4 -> V_9 ) )
F_6 ( V_4 -> V_9 , ! V_5 ) ;
F_7 ( V_4 -> V_10 , V_11 , ! V_5 ) ;
}
static T_1 F_8 ( int V_12 , void * V_13 )
{
struct V_3 * V_4 = V_13 ;
F_9 ( V_14 , & V_4 -> V_2 , V_15 ) ;
return V_16 ;
}
static int F_10 ( struct V_17 * V_18 )
{
struct V_19 * V_7 = & V_18 -> V_7 ;
struct V_3 * V_4 ;
int V_20 ;
V_20 = F_11 ( F_12 ( V_7 ) ,
V_21 ) ;
if ( V_20 ) {
F_13 ( V_7 , L_4 ) ;
return V_20 ;
}
V_4 = F_14 ( V_7 , sizeof( * V_4 ) , V_22 ) ;
if ( ! V_4 )
return - V_23 ;
V_4 -> V_7 = V_7 ;
F_15 ( & V_4 -> V_2 , F_1 ) ;
V_4 -> V_6 = F_16 ( V_7 , L_5 , V_24 ) ;
if ( F_5 ( V_4 -> V_6 ) ) {
V_20 = F_17 ( V_4 -> V_6 ) ;
F_13 ( V_7 , L_6 , V_20 ) ;
return V_20 ;
} else if ( F_18 ( V_4 -> V_6 ) != V_25 ) {
F_19 ( V_7 , V_26 L_7 ) ;
F_20 ( V_4 -> V_6 ) ;
}
V_4 -> V_27 = F_21 ( V_4 -> V_6 ) ;
if ( V_4 -> V_27 < 0 ) {
F_13 ( V_7 , L_8 , V_4 -> V_27 ) ;
return V_4 -> V_27 ;
}
V_4 -> V_9 = F_16 ( V_7 , L_9 , V_28 ) ;
if ( F_5 ( V_4 -> V_9 ) )
F_22 ( V_7 , L_10 ) ;
V_4 -> V_8 = F_16 ( V_7 , L_11 , V_28 ) ;
if ( F_5 ( V_4 -> V_8 ) )
F_22 ( V_7 , L_12 ) ;
V_4 -> V_10 = F_23 ( V_7 , V_29 ) ;
if ( F_5 ( V_4 -> V_10 ) )
return - V_23 ;
V_20 = F_24 ( V_7 , V_4 -> V_10 ) ;
if ( V_20 < 0 ) {
F_13 ( V_7 , L_13 , V_20 ) ;
return V_20 ;
}
V_20 = F_25 ( V_7 , V_4 -> V_27 ,
NULL , F_8 ,
V_30 | V_31 |
V_32 |
V_33 ,
F_26 ( V_7 ) , V_4 ) ;
if ( V_20 < 0 ) {
F_13 ( V_7 , L_14 , V_20 ) ;
return V_20 ;
}
F_27 ( V_14 , & V_4 -> V_2 , 0 ) ;
F_28 ( V_18 , V_4 ) ;
return 0 ;
}
static int F_29 ( struct V_17 * V_18 )
{
struct V_3 * V_4 = F_30 ( V_18 ) ;
F_31 ( & V_18 -> V_7 , V_4 -> V_27 , V_4 ) ;
F_32 ( & V_4 -> V_2 ) ;
F_33 ( F_12 ( & V_18 -> V_7 ) ) ;
return 0 ;
}
