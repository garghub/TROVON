static int F_1 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
int V_7 = 0 ;
if ( ! V_4 -> V_8 )
V_7 = - 1 ;
if ( V_6 -> V_9 && ! V_4 -> V_8 -> V_8 ) {
V_7 = F_3 ( V_6 , V_4 -> V_10 , V_4 -> V_11 ) ;
if ( ! V_7 )
V_7 = F_4 ( V_6 , V_4 -> V_11 ) ;
}
return V_7 ;
}
static int F_5 ( struct V_12 * V_13 )
{
struct V_1 * V_2 ;
struct V_5 * V_6 ;
struct V_14 * V_15 ;
int V_16 ;
if ( F_6 () )
return - V_17 ;
if ( V_13 -> V_14 [ 1 ] . V_18 != V_19 ) {
F_7 ( L_1 ) ;
return - V_20 ;
}
V_2 = F_8 ( & V_21 , & V_13 -> V_22 , L_2 ) ;
if ( ! V_2 )
return - V_20 ;
V_15 = F_9 ( V_13 , V_23 , 0 ) ;
V_2 -> V_24 = V_15 -> V_25 ;
V_2 -> V_26 = F_10 ( V_15 ) ;
if ( ! F_11 ( V_2 -> V_24 , V_2 -> V_26 , V_27 ) ) {
F_7 ( L_3 ) ;
V_16 = - V_28 ;
goto V_29;
}
V_2 -> V_30 = F_12 ( V_2 -> V_24 , V_2 -> V_26 ) ;
if ( ! V_2 -> V_30 ) {
F_7 ( L_4 ) ;
V_16 = - V_20 ;
goto V_31;
}
V_6 = F_2 ( V_2 ) ;
V_6 -> V_32 = V_2 -> V_30 ;
V_6 -> V_30 = V_2 -> V_30 +
F_13 ( V_6 , F_14 ( & V_6 -> V_32 -> V_33 ) ) ;
F_15 ( V_6 , L_5 ) ;
F_16 ( V_6 , L_5 ) ;
V_6 -> V_34 = F_14 ( & V_6 -> V_32 -> V_34 ) ;
F_17 ( V_6 , 1 ) ;
V_16 = F_18 ( V_2 , V_13 -> V_14 [ 1 ] . V_25 ,
V_35 | V_36 ) ;
if ( V_16 == 0 ) {
F_19 ( V_13 , V_2 ) ;
return V_16 ;
}
F_20 ( V_2 -> V_30 ) ;
V_31:
F_21 ( V_2 -> V_24 , V_2 -> V_26 ) ;
V_29:
F_22 ( V_2 ) ;
return V_16 ;
}
static int F_23 ( struct V_12 * V_13 )
{
struct V_1 * V_2 = F_24 ( V_13 ) ;
F_25 ( V_2 ) ;
F_20 ( V_2 -> V_30 ) ;
F_21 ( V_2 -> V_24 , V_2 -> V_26 ) ;
F_22 ( V_2 ) ;
F_19 ( V_13 , NULL ) ;
return 0 ;
}
