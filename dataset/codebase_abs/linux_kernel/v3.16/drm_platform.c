static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_5 * V_6 ;
int V_7 ;
F_2 ( L_1 ) ;
V_6 = F_3 ( V_4 , & V_2 -> V_6 ) ;
if ( ! V_6 )
return - V_8 ;
V_6 -> V_9 = V_2 ;
V_7 = F_4 ( V_6 , 0 ) ;
if ( V_7 )
goto V_10;
F_5 ( L_2 ,
V_4 -> V_11 , V_4 -> V_12 , V_4 -> V_13 , V_4 -> V_14 ,
V_4 -> V_15 , V_6 -> V_16 -> V_17 ) ;
return 0 ;
V_10:
F_6 ( V_6 ) ;
return V_7 ;
}
static int F_7 ( struct V_5 * V_6 , struct V_18 * V_19 )
{
int V_20 , V_7 , V_21 ;
V_19 -> V_22 = 13 + strlen ( V_6 -> V_9 -> V_11 ) ;
V_19 -> V_23 = V_19 -> V_22 ;
V_19 -> V_24 = F_8 ( V_19 -> V_22 + 1 , V_25 ) ;
if ( V_19 -> V_24 == NULL )
return - V_8 ;
V_21 = V_6 -> V_9 -> V_21 ;
if ( V_21 == - 1 )
V_21 = 0 ;
V_20 = snprintf ( V_19 -> V_24 , V_19 -> V_22 ,
L_3 , V_6 -> V_9 -> V_11 , V_21 ) ;
if ( V_20 > V_19 -> V_22 ) {
F_9 ( L_4 ) ;
V_7 = - V_26 ;
goto V_27;
}
return 0 ;
V_27:
return V_7 ;
}
int F_10 ( struct V_3 * V_4 , struct V_1 * V_1 )
{
F_2 ( L_1 ) ;
V_4 -> V_28 = & V_29 ;
return F_1 ( V_1 , V_4 ) ;
}
