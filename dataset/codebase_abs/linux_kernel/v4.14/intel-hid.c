static int F_1 ( struct V_1 * V_1 , bool V_2 )
{
T_1 V_3 ;
V_3 = F_2 ( F_3 ( V_1 ) , L_1 ,
V_2 ) ;
if ( F_4 ( V_3 ) ) {
F_5 ( V_1 , L_2 ,
V_2 ? L_3 : L_4 ) ;
return - V_4 ;
}
return 0 ;
}
static void F_6 ( struct V_1 * V_1 , bool V_2 )
{
struct V_5 * V_6 = F_7 ( V_1 ) ;
T_2 V_7 = F_3 ( V_1 ) ;
unsigned long long V_8 ;
T_1 V_3 ;
if ( ! V_6 -> V_9 )
return;
V_3 = F_8 ( V_7 , L_5 , NULL , & V_8 ) ;
if ( F_4 ( V_3 ) ) {
F_5 ( V_1 , L_6 ) ;
return;
}
V_3 = F_2 ( V_7 , L_7 ,
V_2 ? V_8 : 1 ) ;
if ( F_4 ( V_3 ) )
F_5 ( V_1 , L_8 ) ;
}
static int F_9 ( struct V_1 * V_1 )
{
struct V_5 * V_6 = F_7 ( V_1 ) ;
V_6 -> V_10 = true ;
return 0 ;
}
static int F_10 ( struct V_1 * V_1 )
{
if ( F_11 () ) {
F_1 ( V_1 , false ) ;
F_6 ( V_1 , false ) ;
}
return 0 ;
}
static int F_12 ( struct V_1 * V_1 )
{
struct V_5 * V_6 = F_7 ( V_1 ) ;
V_6 -> V_10 = false ;
if ( F_13 () ) {
F_1 ( V_1 , true ) ;
F_6 ( V_1 , true ) ;
}
return 0 ;
}
static int F_14 ( struct V_11 * V_1 )
{
struct V_5 * V_6 = F_7 ( & V_1 -> V_12 ) ;
int V_13 ;
V_6 -> V_14 = F_15 ( & V_1 -> V_12 ) ;
if ( ! V_6 -> V_14 )
return - V_15 ;
V_13 = F_16 ( V_6 -> V_14 , V_16 , NULL ) ;
if ( V_13 )
return V_13 ;
V_6 -> V_14 -> V_17 = L_9 ;
V_6 -> V_14 -> V_18 . V_19 = V_20 ;
return F_17 ( V_6 -> V_14 ) ;
}
static int F_18 ( struct V_11 * V_1 )
{
struct V_5 * V_6 = F_7 ( & V_1 -> V_12 ) ;
int V_13 ;
V_6 -> V_9 = F_15 ( & V_1 -> V_12 ) ;
if ( ! V_6 -> V_9 )
return - V_15 ;
V_13 = F_16 ( V_6 -> V_9 , V_21 , NULL ) ;
if ( V_13 )
return V_13 ;
V_6 -> V_9 -> V_17 = L_10 ;
V_6 -> V_9 -> V_18 . V_19 = V_20 ;
return F_17 ( V_6 -> V_9 ) ;
}
static void F_19 ( T_2 V_7 , T_3 V_22 , void * V_23 )
{
struct V_11 * V_1 = V_23 ;
struct V_5 * V_6 = F_7 ( & V_1 -> V_12 ) ;
unsigned long long V_24 ;
T_1 V_3 ;
if ( V_6 -> V_10 ) {
if ( V_22 == 0xce )
goto V_25;
if ( V_22 == 0xc0 || ! V_6 -> V_9 )
return;
if ( ! F_20 ( V_6 -> V_9 , V_22 ) ) {
F_21 ( & V_1 -> V_12 , L_11 , V_22 ) ;
return;
}
V_25:
F_22 ( & V_1 -> V_12 ) ;
return;
}
if ( V_22 != 0xc0 ) {
if ( ! V_6 -> V_9 ||
! F_23 ( V_6 -> V_9 , V_22 , 1 , true ) )
F_24 ( & V_1 -> V_12 , L_11 , V_22 ) ;
return;
}
V_3 = F_8 ( V_7 , L_12 , NULL , & V_24 ) ;
if ( F_4 ( V_3 ) ) {
F_5 ( & V_1 -> V_12 , L_13 ) ;
return;
}
if ( ! F_23 ( V_6 -> V_14 , V_24 , 1 , true ) )
F_24 ( & V_1 -> V_12 , L_14 ,
V_24 ) ;
}
static int F_25 ( struct V_11 * V_1 )
{
T_2 V_7 = F_3 ( & V_1 -> V_12 ) ;
unsigned long long V_26 , V_27 ;
struct V_5 * V_6 ;
T_1 V_3 ;
int V_28 ;
V_3 = F_8 ( V_7 , L_15 , NULL , & V_27 ) ;
if ( F_4 ( V_3 ) ) {
F_5 ( & V_1 -> V_12 , L_16 ) ;
return - V_29 ;
}
if ( V_27 != 0 ) {
F_21 ( & V_1 -> V_12 , L_17 ) ;
return - V_29 ;
}
V_6 = F_26 ( & V_1 -> V_12 , sizeof( * V_6 ) , V_30 ) ;
if ( ! V_6 )
return - V_15 ;
F_27 ( & V_1 -> V_12 , V_6 ) ;
V_28 = F_14 ( V_1 ) ;
if ( V_28 ) {
F_28 ( L_18 ) ;
return V_28 ;
}
V_3 = F_8 ( V_7 , L_19 , NULL , & V_26 ) ;
if ( F_29 ( V_3 ) && ( V_26 & 0x20000 ) ) {
F_21 ( & V_1 -> V_12 , L_20 ) ;
V_28 = F_18 ( V_1 ) ;
if ( V_28 )
F_28 ( L_21 ) ;
}
V_3 = F_30 ( V_7 ,
V_31 ,
F_19 ,
V_1 ) ;
if ( F_4 ( V_3 ) )
return - V_32 ;
V_28 = F_1 ( & V_1 -> V_12 , true ) ;
if ( V_28 )
goto V_33;
if ( V_6 -> V_9 ) {
F_6 ( & V_1 -> V_12 , true ) ;
V_3 = F_31 ( V_7 , L_22 , NULL , NULL ) ;
if ( F_4 ( V_3 ) )
F_5 ( & V_1 -> V_12 ,
L_23 ) ;
}
F_32 ( & V_1 -> V_12 , true ) ;
return 0 ;
V_33:
F_33 ( V_7 , V_31 , F_19 ) ;
return V_28 ;
}
static int F_34 ( struct V_11 * V_1 )
{
T_2 V_7 = F_3 ( & V_1 -> V_12 ) ;
F_33 ( V_7 , V_31 , F_19 ) ;
F_1 ( & V_1 -> V_12 , false ) ;
F_6 ( & V_1 -> V_12 , false ) ;
return 0 ;
}
static T_1 T_4
F_35 ( T_2 V_7 , T_3 V_34 , void * V_23 , void * * V_35 )
{
const struct V_36 * V_37 = V_23 ;
struct V_38 * V_12 ;
if ( F_36 ( V_7 , & V_12 ) != 0 )
return V_39 ;
if ( F_37 ( V_12 , V_37 ) == 0 )
if ( F_38 ( V_12 , NULL ) )
F_21 ( & V_12 -> V_12 ,
L_24 ) ;
return V_39 ;
}
static int T_4 F_39 ( void )
{
F_40 ( V_40 , V_41 ,
V_42 , F_35 , NULL ,
( void * ) V_43 , NULL ) ;
return F_41 ( & V_44 ) ;
}
static void T_5 F_42 ( void )
{
F_43 ( & V_44 ) ;
}
