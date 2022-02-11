static void F_1 ( void )
{
F_2 ( V_1 ) ;
F_2 ( V_2 ) ;
V_3 = 1 ;
}
static void F_3 ( void )
{
F_4 ( V_2 ) ;
F_4 ( V_1 ) ;
V_3 = 0 ;
}
static void F_5 ( struct V_4 * V_5 )
{
F_6 ( & V_5 -> V_6 , L_1 ) ;
F_1 () ;
}
static void F_7 ( struct V_4 * V_5 )
{
F_6 ( & V_5 -> V_6 , L_2 ) ;
F_3 () ;
}
static int F_8 ( struct V_7 * V_8 )
{
struct V_9 * V_10 = F_9 ( V_8 ) ;
int V_11 = 0 ;
V_10 -> V_12 = V_8 -> V_13 ;
V_10 -> V_13 = V_8 -> V_13 +
F_10 ( V_10 , F_11 ( V_10 , & V_10 -> V_12 -> V_14 ) ) ;
F_12 ( V_10 , L_3 ) ;
F_13 ( V_10 , L_3 ) ;
V_10 -> V_15 = F_11 ( V_10 , & V_10 -> V_12 -> V_15 ) ;
V_11 = F_14 ( V_10 ) ;
if ( V_11 )
return V_11 ;
V_11 = F_15 ( V_8 ) ;
if ( V_11 )
return V_11 ;
V_10 -> V_16 = 0x20 ;
F_16 ( V_10 ) ;
F_17 ( V_10 , 0 ) ;
return V_11 ;
}
static int T_1 F_18 ( struct V_4 * V_5 )
{
struct V_7 * V_8 ;
const struct V_17 * V_18 = & V_19 ;
struct V_20 * V_21 ;
int V_22 ;
int V_11 ;
if ( F_19 () )
return - V_23 ;
F_20 ( L_4 ) ;
V_22 = F_21 ( V_5 , 0 ) ;
if ( V_22 <= 0 ) {
F_22 ( & V_5 -> V_6 ,
L_5 ,
F_23 ( & V_5 -> V_6 ) ) ;
V_11 = - V_23 ;
goto V_24;
}
V_8 = F_24 ( V_18 , & V_5 -> V_6 , F_23 ( & V_5 -> V_6 ) ) ;
if ( ! V_8 ) {
V_11 = - V_25 ;
goto V_24;
}
V_21 = F_25 ( V_5 , V_26 , 0 ) ;
if ( ! V_21 ) {
F_22 ( & V_5 -> V_6 ,
L_6 ,
F_23 ( & V_5 -> V_6 ) ) ;
V_11 = - V_23 ;
goto V_27;
}
V_8 -> V_28 = V_21 -> V_29 ;
V_8 -> V_30 = F_26 ( V_21 ) ;
if ( ! F_27 ( V_8 -> V_28 , V_8 -> V_30 ,
V_18 -> V_31 ) ) {
F_6 ( & V_5 -> V_6 , L_7 ) ;
V_11 = - V_32 ;
goto V_27;
}
V_8 -> V_13 = F_28 ( V_8 -> V_28 , V_8 -> V_30 ) ;
if ( V_8 -> V_13 == NULL ) {
F_6 ( & V_5 -> V_6 , L_8 ) ;
V_11 = - V_33 ;
goto V_34;
}
V_1 = F_29 ( & V_5 -> V_6 , L_9 ) ;
if ( F_30 ( V_1 ) ) {
F_22 ( & V_5 -> V_6 , L_10 ) ;
V_11 = - V_35 ;
goto V_36;
}
V_2 = F_29 ( & V_5 -> V_6 , L_11 ) ;
if ( F_30 ( V_2 ) ) {
F_22 ( & V_5 -> V_6 , L_12 ) ;
V_11 = - V_35 ;
goto V_37;
}
F_5 ( V_5 ) ;
V_11 = F_31 ( V_8 , V_22 , V_38 ) ;
if ( V_11 )
goto V_39;
return V_11 ;
V_39:
F_7 ( V_5 ) ;
F_32 ( V_2 ) ;
V_37:
F_32 ( V_1 ) ;
V_36:
F_33 ( V_8 -> V_13 ) ;
V_34:
F_34 ( V_8 -> V_28 , V_8 -> V_30 ) ;
V_27:
F_35 ( V_8 ) ;
V_24:
F_22 ( & V_5 -> V_6 , L_13 ,
F_23 ( & V_5 -> V_6 ) , V_11 ) ;
return V_11 ;
}
static int T_2 F_36 ( struct V_4 * V_5 )
{
struct V_7 * V_8 = F_37 ( V_5 ) ;
F_38 ( V_8 ) ;
F_39 ( V_8 ) ;
F_33 ( V_8 -> V_13 ) ;
F_34 ( V_8 -> V_28 , V_8 -> V_30 ) ;
F_35 ( V_8 ) ;
F_7 ( V_5 ) ;
F_32 ( V_2 ) ;
F_32 ( V_1 ) ;
V_2 = V_1 = NULL ;
return 0 ;
}
