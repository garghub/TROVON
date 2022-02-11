static int F_1 ( struct V_1 * V_2 )
{
return ! F_2 ( V_3 ) ;
}
static int F_3 ( struct V_1 * V_2 , T_1 V_4 ,
void * V_5 )
{
int V_6 ;
V_6 = F_4 ( V_7 , L_1 ) ;
if ( V_6 )
return V_6 ;
F_5 ( V_7 ) ;
V_6 = F_4 ( V_3 , L_2 ) ;
if ( V_6 )
goto V_8;
F_5 ( V_3 ) ;
V_6 = F_6 ( F_7 ( V_7 ) , V_4 ,
V_9 | V_10 ,
L_3 , V_5 ) ;
if ( V_6 )
goto V_11;
return 0 ;
V_11:
F_8 ( V_3 ) ;
V_8:
F_8 ( V_7 ) ;
return V_6 ;
}
static void F_9 ( struct V_1 * V_2 , void * V_5 )
{
F_10 ( F_7 ( V_7 ) , V_5 ) ;
F_8 ( V_3 ) ;
F_8 ( V_7 ) ;
}
static void F_11 ( void )
{
if ( ! F_4 ( V_12 , L_4 ) ) {
F_12 ( V_12 , 0 ) ;
F_13 ( V_12 , false ) ;
}
if ( ! F_4 ( V_13 , L_5 ) ) {
F_12 ( V_13 , 0 ) ;
F_13 ( V_13 , false ) ;
}
}
static int F_14 ( struct V_1 * V_2 , int V_14 )
{
F_15 ( V_15 , ! V_14 ) ;
return 0 ;
}
static int F_16 ( struct V_1 * V_2 )
{
F_15 ( V_16 , 0 ) ;
F_17 ( 100 ) ;
F_15 ( V_16 , 1 ) ;
return 0 ;
}
static int T_2 F_18 ( void )
{
int V_6 = F_4 ( V_17 , L_6 ) ;
if ( V_6 )
return V_6 ;
F_12 ( V_17 , 0 ) ;
V_6 = F_4 ( V_16 , L_7 ) ;
if ( V_6 )
return V_6 ;
F_12 ( V_16 , 1 ) ;
V_6 = F_4 ( V_15 , L_8 ) ;
if ( V_6 )
return V_6 ;
F_12 ( V_15 , 0 ) ;
V_6 = F_4 ( V_18 , L_9 ) ;
if ( V_6 )
return V_6 ;
F_12 ( V_18 , 1 ) ;
V_6 = F_4 ( V_19 , L_10 ) ;
if ( V_6 )
return V_6 ;
F_12 ( V_19 , 0 ) ;
return 0 ;
}
static void F_19 ( void )
{
if ( ! F_4 ( V_20 , L_11 ) ) {
F_5 ( V_20 ) ;
F_13 ( V_20 , true ) ;
}
if ( ! F_4 ( V_21 , L_12 ) ) {
F_5 ( V_21 ) ;
F_13 ( V_21 , true ) ;
}
if ( ! F_4 ( V_22 , L_13 ) ) {
F_5 ( V_22 ) ;
F_13 ( V_22 , true ) ;
}
if ( ! F_4 ( V_23 , L_14 ) ) {
F_5 ( V_23 ) ;
F_13 ( V_23 , true ) ;
}
}
static int F_20 ( struct V_24 * V_25 )
{
F_21 ( V_26 , true ) ;
F_22 ( V_27 , V_28 ) ;
F_22 ( V_29 , V_28 ) ;
F_22 ( V_30 , V_28 ) ;
F_22 ( V_31 , V_28 ) ;
F_22 ( V_32 , V_28 ) ;
F_22 ( V_33 , V_28 ) ;
F_22 ( V_34 , V_28 ) ;
F_22 ( V_35 , V_28 ) ;
F_23 ( 10 ) ;
return F_24 ( V_25 -> V_36 , V_37 |
V_38 ) ;
}
static int F_25 ( struct V_39 * V_40 )
{
int V_6 = F_4 ( V_41 , L_15 ) ;
if ( V_6 )
return V_6 ;
F_12 ( V_41 , 0 ) ;
V_6 = F_4 ( V_42 , L_16 ) ;
if ( V_6 ) {
F_8 ( V_41 ) ;
return V_6 ;
}
F_12 ( V_42 , 1 ) ;
return 0 ;
}
static int F_26 ( struct V_39 * V_40 , bool V_14 )
{
if ( V_14 )
F_15 ( V_42 , 0 ) ;
else
F_15 ( V_42 , 1 ) ;
return 0 ;
}
static int T_2 F_27 ( void )
{
struct V_39 * V_40 ;
struct V_24 * V_25 ;
V_40 = F_28 ( sizeof( * V_40 ) , V_43 ) ;
if ( ! V_40 )
return - V_44 ;
V_40 -> V_45 = L_17 ;
V_40 -> V_46 = F_25 ;
V_40 -> V_47 = F_26 ;
V_48 . V_40 = V_40 ;
V_25 = F_29 ( 1 , & V_48 ) ;
if ( F_30 ( V_25 ) )
return F_31 ( V_25 ) ;
return 0 ;
}
void T_2 F_32 ( void )
{
F_33 ( V_49 L_18 ) ;
F_34 ( V_50 , F_35 ( V_50 ) ,
L_19 ) ;
F_19 () ;
F_11 () ;
F_36 ( 1 , & V_51 ) ;
F_37 ( V_52 ,
F_35 ( V_52 ) ) ;
F_18 () ;
F_38 ( V_53 , F_35 ( V_53 ) ) ;
F_4 ( F_39 ( V_54 ) , L_20 ) ;
F_5 ( F_39 ( V_54 ) ) ;
F_13 ( F_39 ( V_54 ) , false ) ;
F_40 ( & V_55 ) ;
F_27 () ;
}
