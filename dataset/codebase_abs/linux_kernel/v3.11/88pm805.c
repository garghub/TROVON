static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_3 ;
unsigned long V_5 = V_6 ;
int V_7 , V_8 , V_9 = - V_10 ;
if ( ! V_4 || ! V_2 -> V_11 ) {
F_2 ( V_2 -> V_12 , L_1 ) ;
return - V_10 ;
}
V_8 =
V_13 | V_14 |
V_15 ;
V_7 = V_13 ;
V_9 = F_3 ( V_4 , V_16 , V_8 , V_7 ) ;
F_4 ( 1 ) ;
if ( V_9 < 0 )
goto V_17;
V_9 =
F_5 ( V_2 -> V_3 , V_2 -> V_11 , V_5 , - 1 ,
V_2 -> V_18 , & V_2 -> V_19 ) ;
V_17:
return V_9 ;
}
static void F_6 ( struct V_1 * V_2 )
{
F_7 ( V_2 -> V_11 , V_2 -> V_19 ) ;
}
static int F_8 ( struct V_1 * V_2 )
{
int V_9 = 0 ;
struct V_3 * V_4 = V_2 -> V_3 ;
if ( ! V_4 ) {
F_2 ( V_2 -> V_12 , L_2 ) ;
return - V_10 ;
}
V_2 -> V_18 = & V_20 ;
V_9 = F_1 ( V_2 ) ;
if ( V_9 < 0 ) {
F_2 ( V_2 -> V_12 , L_3 ) ;
goto V_21;
}
V_9 = F_9 ( V_2 -> V_12 , 0 , & V_22 [ 0 ] ,
F_10 ( V_22 ) , & V_23 [ 0 ] , 0 ,
NULL ) ;
if ( V_9 < 0 ) {
F_2 ( V_2 -> V_12 , L_4 ) ;
goto V_24;
} else
F_11 ( V_2 -> V_12 , L_5 , V_25 ) ;
return 0 ;
V_24:
F_6 ( V_2 ) ;
V_21:
return V_9 ;
}
static int F_12 ( struct V_26 * V_27 ,
const struct V_28 * V_29 )
{
int V_9 = 0 ;
struct V_1 * V_2 ;
struct V_30 * V_31 = V_27 -> V_12 . V_32 ;
V_9 = F_13 ( V_27 ) ;
if ( V_9 ) {
F_2 ( & V_27 -> V_12 , L_6 ) ;
goto V_33;
}
V_2 = F_14 ( V_27 ) ;
V_9 = F_8 ( V_2 ) ;
if ( V_9 ) {
F_2 ( V_2 -> V_12 , L_7 ) ;
goto V_34;
}
if ( V_31 -> V_35 )
V_31 -> V_35 ( V_2 , V_31 ) ;
V_34:
F_15 () ;
V_33:
return V_9 ;
}
static int F_16 ( struct V_26 * V_27 )
{
struct V_1 * V_2 = F_14 ( V_27 ) ;
F_17 ( V_2 -> V_12 ) ;
F_6 ( V_2 ) ;
F_15 () ;
return 0 ;
}
static int T_1 F_18 ( void )
{
return F_19 ( & V_36 ) ;
}
static void T_2 F_20 ( void )
{
F_21 ( & V_36 ) ;
}
