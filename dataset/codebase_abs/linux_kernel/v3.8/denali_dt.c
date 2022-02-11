static void T_1 * F_1 ( struct V_1 * V_2 ,
const struct V_3 * V_4 )
{
void T_1 * V_5 ;
if ( ! F_2 ( V_2 , V_4 -> V_6 , F_3 ( V_4 ) ,
L_1 ) ) {
F_4 ( V_2 , L_2 , V_4 -> V_7 ) ;
return NULL ;
}
V_5 = F_5 ( V_2 , V_4 -> V_6 , F_3 ( V_4 ) ) ;
if ( ! V_4 )
F_4 ( V_2 , L_3 , V_4 -> V_7 ) ;
return V_5 ;
}
static int F_6 ( struct V_8 * V_9 )
{
struct V_3 * V_10 , * V_11 ;
struct V_12 * V_13 ;
struct V_14 * V_15 ;
int V_16 ;
const struct V_17 * V_18 ;
V_18 = F_7 ( V_19 , & V_9 -> V_2 ) ;
if ( V_18 ) {
V_9 -> V_20 = V_18 -> V_21 ;
} else {
F_8 ( L_4 ) ;
return - V_22 ;
}
V_13 = F_9 ( & V_9 -> V_2 , sizeof( * V_13 ) , V_23 ) ;
if ( ! V_13 )
return - V_22 ;
V_15 = & V_13 -> V_15 ;
V_10 = F_10 ( V_9 , V_24 , L_5 ) ;
V_11 = F_10 ( V_9 , V_24 , L_6 ) ;
if ( ! V_10 || ! V_11 ) {
F_4 ( & V_9 -> V_2 , L_7 ) ;
return - V_25 ;
}
V_15 -> V_26 = V_27 ;
V_15 -> V_2 = & V_9 -> V_2 ;
V_15 -> V_28 = F_11 ( V_9 , 0 ) ;
if ( V_15 -> V_28 < 0 ) {
F_4 ( & V_9 -> V_2 , L_8 ) ;
return - V_29 ;
}
V_15 -> V_30 = F_1 ( & V_9 -> V_2 , V_10 ) ;
if ( ! V_15 -> V_30 )
return - V_22 ;
V_15 -> V_31 = F_1 ( & V_9 -> V_2 , V_11 ) ;
if ( ! V_15 -> V_31 )
return - V_22 ;
if ( ! F_12 ( V_9 -> V_2 . V_32 ,
L_9 , ( V_33 * ) & V_34 ) ) {
V_15 -> V_2 -> V_35 = & V_34 ;
} else {
V_15 -> V_2 -> V_35 = NULL ;
}
V_13 -> V_36 = F_13 ( & V_9 -> V_2 , NULL ) ;
if ( F_14 ( V_13 -> V_36 ) ) {
F_4 ( & V_9 -> V_2 , L_10 ) ;
return F_15 ( V_13 -> V_36 ) ;
}
F_16 ( V_13 -> V_36 ) ;
V_16 = F_17 ( V_15 ) ;
if ( V_16 )
goto V_37;
F_18 ( V_9 , V_13 ) ;
return 0 ;
V_37:
F_19 ( V_13 -> V_36 ) ;
F_20 ( V_13 -> V_36 ) ;
return V_16 ;
}
static int F_21 ( struct V_8 * V_9 )
{
struct V_12 * V_13 = F_22 ( V_9 ) ;
F_23 ( & V_13 -> V_15 ) ;
F_24 ( V_13 -> V_36 ) ;
F_20 ( V_13 -> V_36 ) ;
return 0 ;
}
static int T_2 F_25 ( void )
{
return F_26 ( & V_38 ) ;
}
static void T_3 F_27 ( void )
{
F_28 ( & V_38 ) ;
}
