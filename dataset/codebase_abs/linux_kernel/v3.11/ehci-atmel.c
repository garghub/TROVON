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
static int F_8 ( struct V_4 * V_5 )
{
struct V_7 * V_8 ;
const struct V_9 * V_10 = & V_11 ;
struct V_12 * V_13 ;
struct V_14 * V_15 ;
int V_16 ;
int V_17 ;
if ( F_9 () )
return - V_18 ;
F_10 ( L_3 ) ;
V_16 = F_11 ( V_5 , 0 ) ;
if ( V_16 <= 0 ) {
F_12 ( & V_5 -> V_6 ,
L_4 ,
F_13 ( & V_5 -> V_6 ) ) ;
V_17 = - V_18 ;
goto V_19;
}
if ( ! V_5 -> V_6 . V_20 )
V_5 -> V_6 . V_20 = & V_5 -> V_6 . V_21 ;
if ( ! V_5 -> V_6 . V_21 )
V_5 -> V_6 . V_21 = F_14 ( 32 ) ;
V_8 = F_15 ( V_10 , & V_5 -> V_6 , F_13 ( & V_5 -> V_6 ) ) ;
if ( ! V_8 ) {
V_17 = - V_22 ;
goto V_19;
}
V_13 = F_16 ( V_5 , V_23 , 0 ) ;
if ( ! V_13 ) {
F_12 ( & V_5 -> V_6 ,
L_5 ,
F_13 ( & V_5 -> V_6 ) ) ;
V_17 = - V_18 ;
goto V_24;
}
V_8 -> V_25 = V_13 -> V_26 ;
V_8 -> V_27 = F_17 ( V_13 ) ;
V_8 -> V_28 = F_18 ( & V_5 -> V_6 , V_13 ) ;
if ( F_19 ( V_8 -> V_28 ) ) {
V_17 = F_20 ( V_8 -> V_28 ) ;
goto V_24;
}
V_1 = F_21 ( & V_5 -> V_6 , L_6 ) ;
if ( F_19 ( V_1 ) ) {
F_12 ( & V_5 -> V_6 , L_7 ) ;
V_17 = - V_29 ;
goto V_24;
}
V_2 = F_21 ( & V_5 -> V_6 , L_8 ) ;
if ( F_19 ( V_2 ) ) {
F_12 ( & V_5 -> V_6 , L_9 ) ;
V_17 = - V_29 ;
goto V_24;
}
V_15 = F_22 ( V_8 ) ;
V_15 -> V_30 = V_8 -> V_28 ;
F_5 ( V_5 ) ;
V_17 = F_23 ( V_8 , V_16 , V_31 ) ;
if ( V_17 )
goto V_32;
return V_17 ;
V_32:
F_7 ( V_5 ) ;
V_24:
F_24 ( V_8 ) ;
V_19:
F_12 ( & V_5 -> V_6 , L_10 ,
F_13 ( & V_5 -> V_6 ) , V_17 ) ;
return V_17 ;
}
static int F_25 ( struct V_4 * V_5 )
{
struct V_7 * V_8 = F_26 ( V_5 ) ;
F_27 ( V_8 ) ;
F_24 ( V_8 ) ;
F_7 ( V_5 ) ;
V_2 = V_1 = NULL ;
return 0 ;
}
static int T_1 F_28 ( void )
{
if ( F_9 () )
return - V_18 ;
F_29 ( L_11 V_33 L_12 , V_34 ) ;
F_30 ( & V_11 , NULL ) ;
return F_31 ( & V_35 ) ;
}
static void T_2 F_32 ( void )
{
F_33 ( & V_35 ) ;
}
