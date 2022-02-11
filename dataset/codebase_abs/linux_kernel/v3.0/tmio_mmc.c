static int F_1 ( struct V_1 * V_2 , T_1 V_3 )
{
const struct V_4 * V_5 = F_2 ( V_2 ) ;
struct V_6 * V_7 = F_3 ( V_2 ) ;
int V_8 ;
V_8 = F_4 ( & V_2 -> V_2 ) ;
if ( ! V_8 && V_5 -> V_9 )
V_5 -> V_9 ( V_2 ) ;
return V_8 ;
}
static int F_5 ( struct V_1 * V_2 )
{
const struct V_4 * V_5 = F_2 ( V_2 ) ;
struct V_6 * V_7 = F_3 ( V_2 ) ;
int V_8 = 0 ;
if ( V_5 -> V_10 )
V_8 = V_5 -> V_10 ( V_2 ) ;
if ( ! V_8 )
V_8 = F_6 ( & V_2 -> V_2 ) ;
return V_8 ;
}
static int T_2 F_7 ( struct V_1 * V_11 )
{
const struct V_4 * V_5 = F_2 ( V_11 ) ;
struct V_12 * V_13 ;
struct V_14 * V_15 ;
int V_8 = - V_16 , V_17 ;
if ( V_11 -> V_18 != 2 )
goto V_19;
V_13 = V_11 -> V_2 . V_20 ;
if ( ! V_13 || ! V_13 -> V_21 )
goto V_19;
V_17 = F_8 ( V_11 , 0 ) ;
if ( V_17 < 0 ) {
V_8 = V_17 ;
goto V_19;
}
if ( V_5 -> V_22 ) {
V_8 = V_5 -> V_22 ( V_11 ) ;
if ( V_8 )
goto V_19;
}
V_8 = F_9 ( & V_15 , V_11 , V_13 ) ;
if ( V_8 )
goto V_23;
V_8 = F_10 ( V_17 , V_24 , V_25 |
V_26 , F_11 ( & V_11 -> V_2 ) , V_15 ) ;
if ( V_8 )
goto V_27;
F_12 ( L_1 , F_13 ( V_15 -> V_7 ) ,
( unsigned long ) V_15 -> V_28 , V_17 ) ;
return 0 ;
V_27:
F_14 ( V_15 ) ;
V_23:
if ( V_5 -> V_9 )
V_5 -> V_9 ( V_11 ) ;
V_19:
return V_8 ;
}
static int T_3 F_15 ( struct V_1 * V_11 )
{
const struct V_4 * V_5 = F_2 ( V_11 ) ;
struct V_6 * V_7 = F_3 ( V_11 ) ;
F_16 ( V_11 , NULL ) ;
if ( V_7 ) {
struct V_14 * V_15 = F_17 ( V_7 ) ;
F_18 ( F_8 ( V_11 , 0 ) , V_15 ) ;
F_14 ( V_15 ) ;
if ( V_5 -> V_9 )
V_5 -> V_9 ( V_11 ) ;
}
return 0 ;
}
static int T_4 F_19 ( void )
{
return F_20 ( & V_29 ) ;
}
static void T_5 F_21 ( void )
{
F_22 ( & V_29 ) ;
}
