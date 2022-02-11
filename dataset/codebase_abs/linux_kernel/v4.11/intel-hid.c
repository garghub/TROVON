static int F_1 ( struct V_1 * V_1 , int V_2 )
{
union V_3 V_4 = { V_5 } ;
struct V_6 args = { 1 , & V_4 } ;
T_1 V_7 ;
V_4 . integer . V_8 = V_2 ;
V_7 = F_2 ( F_3 ( V_1 ) , L_1 , & args , NULL ) ;
if ( F_4 ( V_7 ) ) {
F_5 ( V_1 , L_2 ,
V_2 ? L_3 : L_4 ) ;
return - V_9 ;
}
return 0 ;
}
static void F_6 ( struct V_1 * V_1 , bool V_2 )
{
struct V_10 * V_11 = F_7 ( V_1 ) ;
T_2 V_12 = F_3 ( V_1 ) ;
unsigned long long V_13 ;
T_1 V_7 ;
if ( ! V_11 -> V_14 )
return;
V_7 = F_8 ( V_12 , L_5 , NULL , & V_13 ) ;
if ( F_4 ( V_7 ) ) {
F_5 ( V_1 , L_6 ) ;
return;
}
V_7 = F_9 ( V_12 , L_7 ,
V_2 ? V_13 : 1 ) ;
if ( F_4 ( V_7 ) )
F_5 ( V_1 , L_8 ) ;
}
static int F_10 ( struct V_1 * V_1 )
{
F_1 ( V_1 , 0 ) ;
F_6 ( V_1 , false ) ;
return 0 ;
}
static int F_11 ( struct V_1 * V_1 )
{
F_1 ( V_1 , 1 ) ;
F_6 ( V_1 , true ) ;
return 0 ;
}
static int F_12 ( struct V_15 * V_1 )
{
struct V_10 * V_11 = F_7 ( & V_1 -> V_16 ) ;
int V_17 ;
V_11 -> V_18 = F_13 () ;
if ( ! V_11 -> V_18 )
return - V_19 ;
V_17 = F_14 ( V_11 -> V_18 , V_20 , NULL ) ;
if ( V_17 )
goto V_21;
V_11 -> V_18 -> V_16 . V_22 = & V_1 -> V_16 ;
V_11 -> V_18 -> V_23 = L_9 ;
V_11 -> V_18 -> V_24 . V_25 = V_26 ;
F_15 ( V_27 , V_11 -> V_18 -> V_28 ) ;
V_17 = F_16 ( V_11 -> V_18 ) ;
if ( V_17 )
goto V_21;
return 0 ;
V_21:
F_17 ( V_11 -> V_18 ) ;
return V_17 ;
}
static int F_18 ( struct V_15 * V_1 )
{
struct V_10 * V_11 = F_7 ( & V_1 -> V_16 ) ;
int V_17 ;
V_11 -> V_14 = F_19 ( & V_1 -> V_16 ) ;
if ( ! V_11 -> V_14 )
return - V_19 ;
V_17 = F_14 ( V_11 -> V_14 , V_29 , NULL ) ;
if ( V_17 )
return V_17 ;
V_11 -> V_14 -> V_16 . V_22 = & V_1 -> V_16 ;
V_11 -> V_14 -> V_23 = L_10 ;
V_11 -> V_14 -> V_24 . V_25 = V_26 ;
return F_16 ( V_11 -> V_14 ) ;
}
static void F_20 ( struct V_15 * V_1 )
{
struct V_10 * V_11 = F_7 ( & V_1 -> V_16 ) ;
F_21 ( V_11 -> V_18 ) ;
}
static void F_22 ( T_2 V_12 , T_3 V_30 , void * V_31 )
{
struct V_15 * V_1 = V_31 ;
struct V_10 * V_11 = F_7 ( & V_1 -> V_16 ) ;
unsigned long long V_32 ;
T_1 V_7 ;
if ( V_30 != 0xc0 ) {
if ( ! V_11 -> V_14 ||
! F_23 ( V_11 -> V_14 , V_30 , 1 , true ) )
F_24 ( & V_1 -> V_16 , L_11 , V_30 ) ;
return;
}
V_7 = F_8 ( V_12 , L_12 , NULL , & V_32 ) ;
if ( F_4 ( V_7 ) ) {
F_5 ( & V_1 -> V_16 , L_13 ) ;
return;
}
if ( ! F_23 ( V_11 -> V_18 , V_32 , 1 , true ) )
F_24 ( & V_1 -> V_16 , L_14 ,
V_32 ) ;
}
static int F_25 ( struct V_15 * V_1 )
{
T_2 V_12 = F_3 ( & V_1 -> V_16 ) ;
unsigned long long V_33 , V_34 ;
struct V_10 * V_11 ;
T_1 V_7 ;
int V_35 ;
V_7 = F_8 ( V_12 , L_15 , NULL , & V_34 ) ;
if ( F_4 ( V_7 ) ) {
F_5 ( & V_1 -> V_16 , L_16 ) ;
return - V_36 ;
}
if ( V_34 != 0 ) {
F_24 ( & V_1 -> V_16 , L_17 ) ;
return - V_36 ;
}
V_11 = F_26 ( & V_1 -> V_16 , sizeof( * V_11 ) , V_37 ) ;
if ( ! V_11 )
return - V_19 ;
F_27 ( & V_1 -> V_16 , V_11 ) ;
V_35 = F_12 ( V_1 ) ;
if ( V_35 ) {
F_28 ( L_18 ) ;
return V_35 ;
}
V_7 = F_8 ( V_12 , L_19 , NULL , & V_33 ) ;
if ( F_29 ( V_7 ) && ( V_33 & 0x20000 ) ) {
F_24 ( & V_1 -> V_16 , L_20 ) ;
V_35 = F_18 ( V_1 ) ;
if ( V_35 )
F_28 ( L_21 ) ;
}
V_7 = F_30 ( V_12 ,
V_38 ,
F_22 ,
V_1 ) ;
if ( F_4 ( V_7 ) ) {
V_35 = - V_39 ;
goto V_40;
}
V_35 = F_1 ( & V_1 -> V_16 , 1 ) ;
if ( V_35 )
goto V_41;
if ( V_11 -> V_14 ) {
F_6 ( & V_1 -> V_16 , true ) ;
V_7 = F_2 ( V_12 , L_22 , NULL , NULL ) ;
if ( F_4 ( V_7 ) )
F_5 ( & V_1 -> V_16 ,
L_23 ) ;
}
return 0 ;
V_41:
F_31 ( V_12 , V_38 , F_22 ) ;
V_40:
F_20 ( V_1 ) ;
return V_35 ;
}
static int F_32 ( struct V_15 * V_1 )
{
T_2 V_12 = F_3 ( & V_1 -> V_16 ) ;
F_31 ( V_12 , V_38 , F_22 ) ;
F_20 ( V_1 ) ;
F_1 ( & V_1 -> V_16 , 0 ) ;
F_6 ( & V_1 -> V_16 , false ) ;
return 0 ;
}
static T_1 T_4
F_33 ( T_2 V_12 , T_3 V_42 , void * V_31 , void * * V_43 )
{
const struct V_44 * V_45 = V_31 ;
struct V_46 * V_16 ;
if ( F_34 ( V_12 , & V_16 ) != 0 )
return V_47 ;
if ( F_35 ( V_16 , V_45 ) == 0 )
if ( F_36 ( V_16 , NULL ) )
F_24 ( & V_16 -> V_16 ,
L_24 ) ;
return V_47 ;
}
static int T_4 F_37 ( void )
{
F_38 ( V_48 , V_49 ,
V_50 , F_33 , NULL ,
( void * ) V_51 , NULL ) ;
return F_39 ( & V_52 ) ;
}
static void T_5 F_40 ( void )
{
F_41 ( & V_52 ) ;
}
