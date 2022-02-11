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
if ( ! V_13 -> V_18 . V_19 )
V_13 -> V_18 . V_19 = & V_20 ;
if ( V_13 -> V_14 [ 1 ] . V_21 != V_22 ) {
F_7 ( L_1 ) ;
return - V_23 ;
}
V_2 = F_8 ( & V_24 , & V_13 -> V_18 , L_2 ) ;
if ( ! V_2 )
return - V_23 ;
V_15 = F_9 ( V_13 , V_25 , 0 ) ;
V_2 -> V_26 = V_15 -> V_27 ;
V_2 -> V_28 = F_10 ( V_15 ) ;
V_2 -> V_29 = F_11 ( & V_13 -> V_18 , V_15 ) ;
if ( ! V_2 -> V_29 ) {
F_7 ( L_3 ) ;
V_16 = - V_23 ;
goto V_30;
}
V_6 = F_2 ( V_2 ) ;
V_6 -> V_31 = V_2 -> V_29 ;
V_16 = F_12 ( V_2 , V_13 -> V_14 [ 1 ] . V_27 ,
V_32 ) ;
if ( V_16 == 0 ) {
F_13 ( V_13 , V_2 ) ;
return V_16 ;
}
V_30:
F_14 ( V_2 ) ;
return V_16 ;
}
static int F_15 ( struct V_12 * V_13 )
{
struct V_1 * V_2 = F_16 ( V_13 ) ;
F_17 ( V_2 ) ;
F_14 ( V_2 ) ;
F_13 ( V_13 , NULL ) ;
return 0 ;
}
