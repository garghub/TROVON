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
int V_11 ;
V_10 -> V_12 = V_8 -> V_13 ;
V_11 = F_10 ( V_8 ) ;
if ( V_11 )
return V_11 ;
F_11 ( V_10 , 0 ) ;
return V_11 ;
}
static int T_1 F_12 ( struct V_4 * V_5 )
{
struct V_7 * V_8 ;
const struct V_14 * V_15 = & V_16 ;
struct V_17 * V_18 ;
int V_19 ;
int V_11 ;
if ( F_13 () )
return - V_20 ;
F_14 ( L_3 ) ;
V_19 = F_15 ( V_5 , 0 ) ;
if ( V_19 <= 0 ) {
F_16 ( & V_5 -> V_6 ,
L_4 ,
F_17 ( & V_5 -> V_6 ) ) ;
V_11 = - V_20 ;
goto V_21;
}
if ( ! V_5 -> V_6 . V_22 )
V_5 -> V_6 . V_22 = & V_23 ;
V_8 = F_18 ( V_15 , & V_5 -> V_6 , F_17 ( & V_5 -> V_6 ) ) ;
if ( ! V_8 ) {
V_11 = - V_24 ;
goto V_21;
}
V_18 = F_19 ( V_5 , V_25 , 0 ) ;
if ( ! V_18 ) {
F_16 ( & V_5 -> V_6 ,
L_5 ,
F_17 ( & V_5 -> V_6 ) ) ;
V_11 = - V_20 ;
goto V_26;
}
V_8 -> V_27 = V_18 -> V_28 ;
V_8 -> V_29 = F_20 ( V_18 ) ;
V_8 -> V_13 = F_21 ( & V_5 -> V_6 , V_18 ) ;
if ( V_8 -> V_13 == NULL ) {
F_6 ( & V_5 -> V_6 , L_6 ) ;
V_11 = - V_30 ;
goto V_26;
}
V_1 = F_22 ( & V_5 -> V_6 , L_7 ) ;
if ( F_23 ( V_1 ) ) {
F_16 ( & V_5 -> V_6 , L_8 ) ;
V_11 = - V_31 ;
goto V_26;
}
V_2 = F_22 ( & V_5 -> V_6 , L_9 ) ;
if ( F_23 ( V_2 ) ) {
F_16 ( & V_5 -> V_6 , L_10 ) ;
V_11 = - V_31 ;
goto V_26;
}
F_5 ( V_5 ) ;
V_11 = F_24 ( V_8 , V_19 , V_32 ) ;
if ( V_11 )
goto V_33;
return V_11 ;
V_33:
F_7 ( V_5 ) ;
V_26:
F_25 ( V_8 ) ;
V_21:
F_16 ( & V_5 -> V_6 , L_11 ,
F_17 ( & V_5 -> V_6 ) , V_11 ) ;
return V_11 ;
}
static int T_2 F_26 ( struct V_4 * V_5 )
{
struct V_7 * V_8 = F_27 ( V_5 ) ;
F_28 ( V_8 ) ;
F_29 ( V_8 ) ;
F_25 ( V_8 ) ;
F_7 ( V_5 ) ;
V_2 = V_1 = NULL ;
return 0 ;
}
