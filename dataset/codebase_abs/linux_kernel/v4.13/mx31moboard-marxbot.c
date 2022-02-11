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
static void F_14 ( void )
{
if ( ! F_4 ( V_14 , L_6 ) ) {
F_5 ( V_14 ) ;
F_13 ( V_14 , true ) ;
}
if ( ! F_4 ( V_15 , L_7 ) ) {
F_5 ( V_15 ) ;
F_13 ( V_15 , true ) ;
}
if ( ! F_4 ( V_16 , L_8 ) ) {
F_5 ( V_16 ) ;
F_13 ( V_16 , true ) ;
}
if ( ! F_4 ( V_17 , L_9 ) ) {
F_5 ( V_17 ) ;
F_13 ( V_17 , true ) ;
}
}
static int F_15 ( struct V_18 * V_19 )
{
F_16 ( V_20 , true ) ;
F_17 ( V_21 , V_22 ) ;
F_17 ( V_23 , V_22 ) ;
F_17 ( V_24 , V_22 ) ;
F_17 ( V_25 , V_22 ) ;
F_17 ( V_26 , V_22 ) ;
F_17 ( V_27 , V_22 ) ;
F_17 ( V_28 , V_22 ) ;
F_17 ( V_29 , V_22 ) ;
F_18 ( 10 ) ;
return F_19 ( V_19 -> V_30 , V_31 |
V_32 ) ;
}
static int F_20 ( struct V_33 * V_34 )
{
int V_6 = F_4 ( V_35 , L_10 ) ;
if ( V_6 )
return V_6 ;
F_12 ( V_35 , 0 ) ;
V_6 = F_4 ( V_36 , L_11 ) ;
if ( V_6 ) {
F_8 ( V_35 ) ;
return V_6 ;
}
F_12 ( V_36 , 1 ) ;
return 0 ;
}
static int F_21 ( struct V_37 * V_34 , bool V_38 )
{
if ( V_38 )
F_22 ( V_36 , 0 ) ;
else
F_22 ( V_36 , 1 ) ;
return 0 ;
}
static int T_2 F_23 ( void )
{
struct V_33 * V_39 ;
struct V_18 * V_19 ;
V_39 = F_24 ( sizeof( * V_39 ) , V_40 ) ;
if ( ! V_39 )
return - V_41 ;
V_39 -> V_34 = F_24 ( sizeof( struct V_37 ) , V_40 ) ;
if ( ! V_39 -> V_34 ) {
F_25 ( V_39 ) ;
return - V_41 ;
}
V_39 -> V_42 = L_12 ;
V_39 -> V_43 = F_20 ;
V_39 -> V_34 -> V_44 = F_21 ;
V_45 . V_34 = V_39 ;
V_19 = F_26 ( 1 , & V_45 ) ;
return F_27 ( V_19 ) ;
}
void T_2 F_28 ( void )
{
F_29 ( V_46 L_13 ) ;
F_30 ( V_47 , F_31 ( V_47 ) ,
L_14 ) ;
F_14 () ;
F_11 () ;
F_32 ( 1 , & V_48 ) ;
F_33 ( V_49 ,
F_31 ( V_49 ) ) ;
F_4 ( F_34 ( V_50 ) , L_15 ) ;
F_5 ( F_34 ( V_50 ) ) ;
F_13 ( F_34 ( V_50 ) , false ) ;
F_35 ( & V_51 ) ;
F_23 () ;
}
