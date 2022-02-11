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
V_8 -> V_17 = F_6 ( V_6 ) ;
if ( ! F_7 ( V_8 -> V_15 , V_8 -> V_17 ,
V_2 -> V_18 ) ) {
F_8 ( & V_4 -> V_4 , L_4 ) ;
V_9 = - V_19 ;
goto V_20;
}
V_8 -> V_21 = F_9 ( V_8 -> V_15 , V_8 -> V_17 ) ;
if ( V_8 -> V_21 == NULL ) {
F_8 ( & V_4 -> V_4 , L_5 ) ;
V_9 = - V_22 ;
goto V_23;
}
V_9 = F_10 ( V_8 , V_10 , V_24 | V_25 ) ;
if ( V_9 != 0 )
goto V_26;
return V_9 ;
V_26:
F_11 ( V_8 -> V_21 ) ;
V_23:
F_12 ( V_8 -> V_15 , V_8 -> V_17 ) ;
V_20:
F_13 ( V_8 ) ;
V_14:
F_3 ( & V_4 -> V_4 , L_6 , V_9 ) ;
return V_9 ;
}
static int F_14 ( struct V_7 * V_8 )
{
struct V_27 * V_28 = F_15 ( V_8 ) ;
F_16 ( V_28 ) ;
return F_17 ( V_28 ) ;
}
static int T_1 F_18 ( struct V_7 * V_8 )
{
struct V_27 * V_28 ;
int V_29 ;
V_28 = F_15 ( V_8 ) ;
V_29 = F_19 ( V_28 ) ;
if ( V_29 < 0 ) {
F_3 ( V_8 -> V_30 . V_31 , L_7 ,
V_8 -> V_30 . V_32 ) ;
F_20 ( V_8 ) ;
return V_29 ;
}
return 0 ;
}
static int F_21 ( struct V_3 * V_4 )
{
int V_29 ;
F_22 ( L_8 ) ;
if ( F_23 () )
return - V_11 ;
V_29 = F_1 ( & V_33 , V_4 ) ;
return V_29 ;
}
static int F_24 ( struct V_3 * V_4 )
{
struct V_7 * V_8 = F_25 ( V_4 ) ;
F_26 ( V_8 ) ;
F_11 ( V_8 -> V_21 ) ;
F_12 ( V_8 -> V_15 , V_8 -> V_17 ) ;
F_13 ( V_8 ) ;
return 0 ;
}
