static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_3 ;
unsigned long V_5 = V_6 | V_7 ;
int V_8 , V_9 , V_10 = - V_11 ;
if ( ! V_4 || ! V_2 -> V_12 ) {
F_2 ( V_2 -> V_13 , L_1 ) ;
return - V_11 ;
}
V_9 =
V_14 | V_15 |
V_16 ;
V_8 = V_14 ;
V_10 = F_3 ( V_4 , V_17 , V_9 , V_8 ) ;
F_4 ( 1 ) ;
if ( V_10 < 0 )
goto V_18;
V_10 =
F_5 ( V_2 -> V_3 , V_2 -> V_12 , V_5 , - 1 ,
V_2 -> V_19 , & V_2 -> V_20 ) ;
V_18:
return V_10 ;
}
static void F_6 ( struct V_1 * V_2 )
{
F_7 ( V_2 -> V_12 , V_2 -> V_20 ) ;
}
static int F_8 ( struct V_1 * V_2 )
{
int V_10 = 0 ;
unsigned int V_21 ;
struct V_3 * V_4 = V_2 -> V_3 ;
if ( ! V_4 ) {
F_2 ( V_2 -> V_13 , L_2 ) ;
return - V_11 ;
}
V_10 = F_9 ( V_4 , V_22 , & V_21 ) ;
if ( V_10 < 0 ) {
F_2 ( V_2 -> V_13 , L_3 , V_10 ) ;
goto V_23;
}
V_2 -> V_24 = V_21 ;
V_2 -> V_19 = & V_25 ;
V_10 = F_1 ( V_2 ) ;
if ( V_10 < 0 ) {
F_2 ( V_2 -> V_13 , L_4 ) ;
goto V_23;
}
V_10 = F_10 ( V_2 -> V_13 , 0 , & V_26 [ 0 ] ,
F_11 ( V_26 ) , & V_27 [ 0 ] , 0 ,
NULL ) ;
if ( V_10 < 0 ) {
F_2 ( V_2 -> V_13 , L_5 ) ;
goto V_28;
} else
F_12 ( V_2 -> V_13 , L_6 , V_29 ) ;
return 0 ;
V_28:
F_6 ( V_2 ) ;
V_23:
return V_10 ;
}
static int F_13 ( struct V_30 * V_31 ,
const struct V_32 * V_33 )
{
int V_10 = 0 ;
struct V_1 * V_2 ;
struct V_34 * V_35 = V_31 -> V_13 . V_36 ;
V_10 = F_14 ( V_31 , V_33 ) ;
if ( V_10 ) {
F_2 ( & V_31 -> V_13 , L_7 ) ;
goto V_37;
}
V_2 = F_15 ( V_31 ) ;
V_10 = F_8 ( V_2 ) ;
if ( V_10 ) {
F_2 ( V_2 -> V_13 , L_8 , V_29 , V_2 -> V_33 ) ;
goto V_38;
}
if ( V_35 -> V_39 )
V_35 -> V_39 ( V_2 , V_35 ) ;
V_38:
F_16 () ;
V_37:
return V_10 ;
}
static int F_17 ( struct V_30 * V_31 )
{
struct V_1 * V_2 = F_15 ( V_31 ) ;
F_18 ( V_2 -> V_13 ) ;
F_6 ( V_2 ) ;
F_16 () ;
return 0 ;
}
static int T_1 F_19 ( void )
{
return F_20 ( & V_40 ) ;
}
static void T_2 F_21 ( void )
{
F_22 ( & V_40 ) ;
}
