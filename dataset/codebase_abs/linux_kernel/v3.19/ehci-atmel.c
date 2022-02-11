static void F_1 ( void )
{
if ( F_2 ( V_1 ) ) {
F_3 ( V_2 , 48000000 ) ;
F_4 ( V_2 ) ;
}
F_4 ( V_3 ) ;
F_4 ( V_4 ) ;
V_5 = 1 ;
}
static void F_5 ( void )
{
F_6 ( V_4 ) ;
F_6 ( V_3 ) ;
if ( F_2 ( V_1 ) )
F_6 ( V_2 ) ;
V_5 = 0 ;
}
static void F_7 ( struct V_6 * V_7 )
{
F_8 ( & V_7 -> V_8 , L_1 ) ;
F_1 () ;
}
static void F_9 ( struct V_6 * V_7 )
{
F_8 ( & V_7 -> V_8 , L_2 ) ;
F_5 () ;
}
static int F_10 ( struct V_6 * V_7 )
{
struct V_9 * V_10 ;
const struct V_11 * V_12 = & V_13 ;
struct V_14 * V_15 ;
struct V_16 * V_17 ;
int V_18 ;
int V_19 ;
if ( F_11 () )
return - V_20 ;
F_12 ( L_3 ) ;
V_18 = F_13 ( V_7 , 0 ) ;
if ( V_18 <= 0 ) {
F_14 ( & V_7 -> V_8 ,
L_4 ,
F_15 ( & V_7 -> V_8 ) ) ;
V_19 = - V_20 ;
goto V_21;
}
V_19 = F_16 ( & V_7 -> V_8 , F_17 ( 32 ) ) ;
if ( V_19 )
goto V_21;
V_10 = F_18 ( V_12 , & V_7 -> V_8 , F_15 ( & V_7 -> V_8 ) ) ;
if ( ! V_10 ) {
V_19 = - V_22 ;
goto V_21;
}
V_15 = F_19 ( V_7 , V_23 , 0 ) ;
V_10 -> V_24 = F_20 ( & V_7 -> V_8 , V_15 ) ;
if ( F_21 ( V_10 -> V_24 ) ) {
V_19 = F_22 ( V_10 -> V_24 ) ;
goto V_25;
}
V_10 -> V_26 = V_15 -> V_27 ;
V_10 -> V_28 = F_23 ( V_15 ) ;
V_3 = F_24 ( & V_7 -> V_8 , L_5 ) ;
if ( F_21 ( V_3 ) ) {
F_14 ( & V_7 -> V_8 , L_6 ) ;
V_19 = - V_29 ;
goto V_25;
}
V_4 = F_24 ( & V_7 -> V_8 , L_7 ) ;
if ( F_21 ( V_4 ) ) {
F_14 ( & V_7 -> V_8 , L_8 ) ;
V_19 = - V_29 ;
goto V_25;
}
if ( F_2 ( V_1 ) ) {
V_2 = F_24 ( & V_7 -> V_8 , L_9 ) ;
if ( F_21 ( V_2 ) ) {
F_14 ( & V_7 -> V_8 , L_10 ) ;
V_19 = F_22 ( V_2 ) ;
goto V_25;
}
}
V_17 = F_25 ( V_10 ) ;
V_17 -> V_30 = V_10 -> V_24 ;
F_7 ( V_7 ) ;
V_19 = F_26 ( V_10 , V_18 , V_31 ) ;
if ( V_19 )
goto V_32;
F_27 ( V_10 -> V_33 . V_34 ) ;
return V_19 ;
V_32:
F_9 ( V_7 ) ;
V_25:
F_28 ( V_10 ) ;
V_21:
F_14 ( & V_7 -> V_8 , L_11 ,
F_15 ( & V_7 -> V_8 ) , V_19 ) ;
return V_19 ;
}
static int F_29 ( struct V_6 * V_7 )
{
struct V_9 * V_10 = F_30 ( V_7 ) ;
F_31 ( V_10 ) ;
F_28 ( V_10 ) ;
F_9 ( V_7 ) ;
V_4 = V_3 = NULL ;
return 0 ;
}
static int T_1 F_32 ( void )
{
if ( F_11 () )
return - V_20 ;
F_33 ( L_12 V_35 L_13 , V_36 ) ;
F_34 ( & V_13 , NULL ) ;
return F_35 ( & V_37 ) ;
}
static void T_2 F_36 ( void )
{
F_37 ( & V_37 ) ;
}
