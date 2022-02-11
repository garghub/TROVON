static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
int V_5 ;
V_4 -> V_6 = V_2 -> V_7 ;
V_5 = F_3 ( V_2 ) ;
if ( V_5 )
return V_5 ;
F_4 ( V_4 , 0 ) ;
return 0 ;
}
static int F_5 ( struct V_8 * V_9 )
{
struct V_1 * V_2 ;
struct V_10 * V_11 ;
int V_12 ;
int V_5 ;
F_6 ( L_1 ) ;
if ( F_7 () )
return - V_13 ;
V_11 = F_8 ( V_9 , V_14 , 0 ) ;
if ( ! V_11 ) {
F_9 ( & V_9 -> V_15 ,
L_2 ,
F_10 ( & V_9 -> V_15 ) ) ;
return - V_13 ;
}
V_12 = V_11 -> V_16 ;
V_11 = F_8 ( V_9 , V_17 , 0 ) ;
if ( ! V_11 ) {
F_9 ( & V_9 -> V_15 ,
L_3 ,
F_10 ( & V_9 -> V_15 ) ) ;
return - V_13 ;
}
V_2 = F_11 ( & V_18 , & V_9 -> V_15 ,
F_10 ( & V_9 -> V_15 ) ) ;
if ( ! V_2 )
return - V_19 ;
V_2 -> V_20 = V_11 -> V_16 ;
V_2 -> V_21 = F_12 ( V_11 ) ;
if ( ! F_13 ( V_2 -> V_20 , V_2 -> V_21 , V_22 ) ) {
F_14 ( & V_9 -> V_15 , L_4 ) ;
V_5 = - V_23 ;
goto V_24;
}
V_2 -> V_7 = F_15 ( V_2 -> V_20 , V_2 -> V_21 ) ;
if ( V_2 -> V_7 == NULL ) {
F_14 ( & V_9 -> V_15 , L_5 ) ;
V_5 = - V_25 ;
goto V_26;
}
V_5 = F_16 ( V_2 , V_12 , V_27 | V_28 ) ;
if ( V_5 )
goto V_29;
return V_5 ;
V_29:
F_17 ( V_2 -> V_7 ) ;
V_26:
F_18 ( V_2 -> V_20 , V_2 -> V_21 ) ;
V_24:
F_19 ( V_2 ) ;
return V_5 ;
}
static int F_20 ( struct V_8 * V_9 )
{
struct V_1 * V_2 = F_21 ( V_9 ) ;
F_22 ( V_2 ) ;
F_17 ( V_2 -> V_7 ) ;
F_18 ( V_2 -> V_20 , V_2 -> V_21 ) ;
F_19 ( V_2 ) ;
return 0 ;
}
