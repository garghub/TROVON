static int F_1 ( struct V_1 * V_1 , int V_2 )
{
union V_3 V_4 = { V_5 } ;
struct V_6 args = { 1 , & V_4 } ;
T_1 V_7 ;
V_4 . integer . V_8 = V_2 ;
V_7 = F_2 ( F_3 ( V_1 ) , L_1 , & args , NULL ) ;
if ( ! F_4 ( V_7 ) ) {
F_5 ( V_1 , L_2 ,
V_2 ? L_3 : L_4 ) ;
return - V_9 ;
}
return 0 ;
}
static int F_6 ( struct V_1 * V_1 )
{
F_1 ( V_1 , 0 ) ;
return 0 ;
}
static int F_7 ( struct V_1 * V_1 )
{
F_1 ( V_1 , 1 ) ;
return 0 ;
}
static int F_8 ( struct V_10 * V_1 )
{
struct V_11 * V_12 = F_9 ( & V_1 -> V_13 ) ;
int V_14 ;
V_12 -> V_15 = F_10 () ;
if ( ! V_12 -> V_15 )
return - V_16 ;
V_14 = F_11 ( V_12 -> V_15 , V_17 , NULL ) ;
if ( V_14 )
goto V_18;
V_12 -> V_15 -> V_13 . V_19 = & V_1 -> V_13 ;
V_12 -> V_15 -> V_20 = L_5 ;
V_12 -> V_15 -> V_21 . V_22 = V_23 ;
F_12 ( V_24 , V_12 -> V_15 -> V_25 ) ;
V_14 = F_13 ( V_12 -> V_15 ) ;
if ( V_14 )
goto V_18;
return 0 ;
V_18:
F_14 ( V_12 -> V_15 ) ;
return V_14 ;
}
static void F_15 ( struct V_10 * V_1 )
{
struct V_11 * V_12 = F_9 ( & V_1 -> V_13 ) ;
F_16 ( V_12 -> V_15 ) ;
}
static void F_17 ( T_2 V_26 , T_3 V_27 , void * V_28 )
{
struct V_10 * V_1 = V_28 ;
struct V_11 * V_12 = F_9 ( & V_1 -> V_13 ) ;
unsigned long long V_29 ;
T_1 V_7 ;
if ( V_27 != 0xc0 ) {
F_5 ( & V_1 -> V_13 , L_6 ,
V_27 ) ;
return;
}
V_7 = F_18 ( V_26 , L_7 , NULL , & V_29 ) ;
if ( ! F_4 ( V_7 ) ) {
F_5 ( & V_1 -> V_13 , L_8 ) ;
return;
}
if ( ! F_19 ( V_12 -> V_15 , V_29 , 1 , true ) )
F_20 ( & V_1 -> V_13 , L_9 ,
V_29 ) ;
}
static int F_21 ( struct V_10 * V_1 )
{
T_2 V_26 = F_3 ( & V_1 -> V_13 ) ;
struct V_11 * V_12 ;
unsigned long long V_30 ;
T_1 V_7 ;
int V_31 ;
V_7 = F_18 ( V_26 , L_10 , NULL , & V_30 ) ;
if ( ! F_4 ( V_7 ) ) {
F_5 ( & V_1 -> V_13 , L_11 ) ;
return - V_32 ;
}
if ( V_30 != 0 ) {
F_20 ( & V_1 -> V_13 , L_12 ) ;
return - V_32 ;
}
V_12 = F_22 ( & V_1 -> V_13 , sizeof( * V_12 ) , V_33 ) ;
if ( ! V_12 )
return - V_16 ;
F_23 ( & V_1 -> V_13 , V_12 ) ;
V_31 = F_8 ( V_1 ) ;
if ( V_31 ) {
F_24 ( L_13 ) ;
return V_31 ;
}
V_7 = F_25 ( V_26 ,
V_34 ,
F_17 ,
V_1 ) ;
if ( F_26 ( V_7 ) ) {
V_31 = - V_35 ;
goto V_36;
}
V_31 = F_1 ( & V_1 -> V_13 , 1 ) ;
if ( V_31 )
goto V_37;
return 0 ;
V_37:
F_27 ( V_26 , V_34 , F_17 ) ;
V_36:
F_15 ( V_1 ) ;
return V_31 ;
}
static int F_28 ( struct V_10 * V_1 )
{
T_2 V_26 = F_3 ( & V_1 -> V_13 ) ;
F_27 ( V_26 , V_34 , F_17 ) ;
F_15 ( V_1 ) ;
F_1 ( & V_1 -> V_13 , 0 ) ;
F_27 ( V_26 , V_34 , F_17 ) ;
return 0 ;
}
static T_1 T_4
F_29 ( T_2 V_26 , T_3 V_38 , void * V_28 , void * * V_39 )
{
const struct V_40 * V_41 = V_28 ;
struct V_42 * V_13 ;
if ( F_30 ( V_26 , & V_13 ) != 0 )
return V_43 ;
if ( F_31 ( V_13 , V_41 ) == 0 )
if ( F_32 ( V_13 ) )
F_20 ( & V_13 -> V_13 ,
L_14 ) ;
return V_43 ;
}
static int T_4 F_33 ( void )
{
F_34 ( V_44 , V_45 ,
V_46 , F_29 , NULL ,
( void * ) V_47 , NULL ) ;
return F_35 ( & V_48 ) ;
}
static void T_5 F_36 ( void )
{
F_37 ( & V_48 ) ;
}
