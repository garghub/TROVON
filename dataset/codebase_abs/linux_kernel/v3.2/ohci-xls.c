static int F_1 ( const struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_5 * V_6 ;
struct V_7 * V_8 ;
int V_9 , V_10 ;
V_10 = F_2 ( V_4 , 0 ) ;
if ( V_10 < 0 ) {
F_3 ( & V_4 -> V_4 , L_1 ) ;
return - V_11 ;
}
V_6 = F_4 ( V_4 , V_12 , 0 ) ;
if ( ! V_6 ) {
F_3 ( & V_4 -> V_4 , L_2 ) ;
return - V_11 ;
}
V_8 = F_5 ( V_2 , & V_4 -> V_4 , L_3 ) ;
if ( ! V_8 ) {
V_9 = - V_13 ;
goto V_14;
}
V_8 -> V_15 = V_6 -> V_16 ;
V_8 -> V_17 = V_6 -> V_18 - V_6 -> V_16 + 1 ;
if ( ! F_6 ( V_8 -> V_15 , V_8 -> V_17 ,
V_2 -> V_19 ) ) {
F_7 ( & V_4 -> V_4 , L_4 ) ;
V_9 = - V_20 ;
goto V_21;
}
V_8 -> V_22 = F_8 ( V_8 -> V_15 , V_8 -> V_17 ) ;
if ( V_8 -> V_22 == NULL ) {
F_7 ( & V_4 -> V_4 , L_5 ) ;
V_9 = - V_23 ;
goto V_24;
}
V_9 = F_9 ( V_8 , V_10 , V_25 | V_26 ) ;
if ( V_9 != 0 )
goto V_27;
return V_9 ;
V_27:
F_10 ( V_8 -> V_22 ) ;
V_24:
F_11 ( V_8 -> V_15 , V_8 -> V_17 ) ;
V_21:
F_12 ( V_8 ) ;
V_14:
F_3 ( & V_4 -> V_4 , L_6 , V_9 ) ;
return V_9 ;
}
static int F_13 ( struct V_7 * V_8 )
{
struct V_28 * V_29 = F_14 ( V_8 ) ;
F_15 ( V_29 ) ;
return F_16 ( V_29 ) ;
}
static int T_1 F_17 ( struct V_7 * V_8 )
{
struct V_28 * V_29 ;
int V_30 ;
V_29 = F_14 ( V_8 ) ;
V_30 = F_18 ( V_29 ) ;
if ( V_30 < 0 ) {
F_19 ( L_7 , V_8 -> V_31 . V_32 ) ;
F_20 ( V_8 ) ;
return V_30 ;
}
return 0 ;
}
static int F_21 ( struct V_3 * V_4 )
{
int V_30 ;
F_22 ( L_8 ) ;
if ( F_23 () )
return - V_11 ;
V_30 = F_1 ( & V_33 , V_4 ) ;
return V_30 ;
}
static int F_24 ( struct V_3 * V_4 )
{
struct V_7 * V_8 = F_25 ( V_4 ) ;
F_26 ( V_8 ) ;
F_10 ( V_8 -> V_22 ) ;
F_11 ( V_8 -> V_15 , V_8 -> V_17 ) ;
F_12 ( V_8 ) ;
return 0 ;
}
