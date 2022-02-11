static void F_1 ( struct V_1 * V_2 )
{
if ( V_2 -> V_3 )
return;
F_2 ( V_2 -> V_4 ) ;
F_2 ( V_2 -> V_5 ) ;
V_2 -> V_3 = true ;
}
static void F_3 ( struct V_1 * V_2 )
{
if ( ! V_2 -> V_3 )
return;
F_4 ( V_2 -> V_5 ) ;
F_4 ( V_2 -> V_4 ) ;
V_2 -> V_3 = false ;
}
static void F_5 ( struct V_6 * V_7 )
{
struct V_8 * V_9 = F_6 ( V_7 ) ;
struct V_1 * V_2 = F_7 ( V_9 ) ;
F_8 ( & V_7 -> V_10 , L_1 ) ;
F_1 ( V_2 ) ;
}
static void F_9 ( struct V_6 * V_7 )
{
struct V_8 * V_9 = F_6 ( V_7 ) ;
struct V_1 * V_2 = F_7 ( V_9 ) ;
F_8 ( & V_7 -> V_10 , L_2 ) ;
F_3 ( V_2 ) ;
}
static int F_10 ( struct V_6 * V_7 )
{
struct V_8 * V_9 ;
const struct V_11 * V_12 = & V_13 ;
struct V_14 * V_15 ;
struct V_16 * V_17 ;
struct V_1 * V_2 ;
int V_18 ;
int V_19 ;
if ( F_11 () )
return - V_20 ;
F_12 ( L_3 ) ;
V_18 = F_13 ( V_7 , 0 ) ;
if ( V_18 <= 0 ) {
F_14 ( & V_7 -> V_10 ,
L_4 ,
F_15 ( & V_7 -> V_10 ) ) ;
V_19 = - V_20 ;
goto V_21;
}
V_19 = F_16 ( & V_7 -> V_10 , F_17 ( 32 ) ) ;
if ( V_19 )
goto V_21;
V_9 = F_18 ( V_12 , & V_7 -> V_10 , F_15 ( & V_7 -> V_10 ) ) ;
if ( ! V_9 ) {
V_19 = - V_22 ;
goto V_21;
}
V_2 = F_7 ( V_9 ) ;
V_15 = F_19 ( V_7 , V_23 , 0 ) ;
V_9 -> V_24 = F_20 ( & V_7 -> V_10 , V_15 ) ;
if ( F_21 ( V_9 -> V_24 ) ) {
V_19 = F_22 ( V_9 -> V_24 ) ;
goto V_25;
}
V_9 -> V_26 = V_15 -> V_27 ;
V_9 -> V_28 = F_23 ( V_15 ) ;
V_2 -> V_5 = F_24 ( & V_7 -> V_10 , L_5 ) ;
if ( F_21 ( V_2 -> V_5 ) ) {
F_14 ( & V_7 -> V_10 , L_6 ) ;
V_19 = - V_29 ;
goto V_25;
}
V_2 -> V_4 = F_24 ( & V_7 -> V_10 , L_7 ) ;
if ( F_21 ( V_2 -> V_4 ) ) {
F_14 ( & V_7 -> V_10 , L_8 ) ;
V_19 = F_22 ( V_2 -> V_4 ) ;
goto V_25;
}
V_17 = F_25 ( V_9 ) ;
V_17 -> V_30 = V_9 -> V_24 ;
F_5 ( V_7 ) ;
V_19 = F_26 ( V_9 , V_18 , V_31 ) ;
if ( V_19 )
goto V_32;
F_27 ( V_9 -> V_33 . V_34 ) ;
return V_19 ;
V_32:
F_9 ( V_7 ) ;
V_25:
F_28 ( V_9 ) ;
V_21:
F_14 ( & V_7 -> V_10 , L_9 ,
F_15 ( & V_7 -> V_10 ) , V_19 ) ;
return V_19 ;
}
static int F_29 ( struct V_6 * V_7 )
{
struct V_8 * V_9 = F_6 ( V_7 ) ;
F_30 ( V_9 ) ;
F_28 ( V_9 ) ;
F_9 ( V_7 ) ;
return 0 ;
}
static int F_31 ( struct V_35 * V_10 )
{
struct V_8 * V_9 = F_32 ( V_10 ) ;
struct V_1 * V_2 = F_7 ( V_9 ) ;
int V_36 ;
V_36 = F_33 ( V_9 , false ) ;
if ( V_36 )
return V_36 ;
F_3 ( V_2 ) ;
return 0 ;
}
static int F_34 ( struct V_35 * V_10 )
{
struct V_8 * V_9 = F_32 ( V_10 ) ;
struct V_1 * V_2 = F_7 ( V_9 ) ;
F_1 ( V_2 ) ;
return F_35 ( V_9 , false ) ;
}
static int T_1 F_36 ( void )
{
if ( F_11 () )
return - V_20 ;
F_37 ( L_10 V_37 L_11 , V_38 ) ;
F_38 ( & V_13 , & V_39 ) ;
return F_39 ( & V_40 ) ;
}
static void T_2 F_40 ( void )
{
F_41 ( & V_40 ) ;
}
