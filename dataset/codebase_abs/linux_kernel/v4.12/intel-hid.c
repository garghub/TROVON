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
F_1 ( V_1 , false ) ;
F_6 ( V_1 , false ) ;
return 0 ;
}
static int F_10 ( struct V_1 * V_1 )
{
F_1 ( V_1 , true ) ;
F_6 ( V_1 , true ) ;
return 0 ;
}
static int F_11 ( struct V_10 * V_1 )
{
struct V_5 * V_6 = F_7 ( & V_1 -> V_11 ) ;
int V_12 ;
V_6 -> V_13 = F_12 ( & V_1 -> V_11 ) ;
if ( ! V_6 -> V_13 )
return - V_14 ;
V_12 = F_13 ( V_6 -> V_13 , V_15 , NULL ) ;
if ( V_12 )
return V_12 ;
V_6 -> V_13 -> V_16 = L_9 ;
V_6 -> V_13 -> V_17 . V_18 = V_19 ;
return F_14 ( V_6 -> V_13 ) ;
}
static int F_15 ( struct V_10 * V_1 )
{
struct V_5 * V_6 = F_7 ( & V_1 -> V_11 ) ;
int V_12 ;
V_6 -> V_9 = F_12 ( & V_1 -> V_11 ) ;
if ( ! V_6 -> V_9 )
return - V_14 ;
V_12 = F_13 ( V_6 -> V_9 , V_20 , NULL ) ;
if ( V_12 )
return V_12 ;
V_6 -> V_9 -> V_16 = L_10 ;
V_6 -> V_9 -> V_17 . V_18 = V_19 ;
return F_14 ( V_6 -> V_9 ) ;
}
static void F_16 ( T_2 V_7 , T_3 V_21 , void * V_22 )
{
struct V_10 * V_1 = V_22 ;
struct V_5 * V_6 = F_7 ( & V_1 -> V_11 ) ;
unsigned long long V_23 ;
T_1 V_3 ;
if ( V_21 != 0xc0 ) {
if ( ! V_6 -> V_9 ||
! F_17 ( V_6 -> V_9 , V_21 , 1 , true ) )
F_18 ( & V_1 -> V_11 , L_11 , V_21 ) ;
return;
}
V_3 = F_8 ( V_7 , L_12 , NULL , & V_23 ) ;
if ( F_4 ( V_3 ) ) {
F_5 ( & V_1 -> V_11 , L_13 ) ;
return;
}
if ( ! F_17 ( V_6 -> V_13 , V_23 , 1 , true ) )
F_18 ( & V_1 -> V_11 , L_14 ,
V_23 ) ;
}
static int F_19 ( struct V_10 * V_1 )
{
T_2 V_7 = F_3 ( & V_1 -> V_11 ) ;
unsigned long long V_24 , V_25 ;
struct V_5 * V_6 ;
T_1 V_3 ;
int V_26 ;
V_3 = F_8 ( V_7 , L_15 , NULL , & V_25 ) ;
if ( F_4 ( V_3 ) ) {
F_5 ( & V_1 -> V_11 , L_16 ) ;
return - V_27 ;
}
if ( V_25 != 0 ) {
F_18 ( & V_1 -> V_11 , L_17 ) ;
return - V_27 ;
}
V_6 = F_20 ( & V_1 -> V_11 , sizeof( * V_6 ) , V_28 ) ;
if ( ! V_6 )
return - V_14 ;
F_21 ( & V_1 -> V_11 , V_6 ) ;
V_26 = F_11 ( V_1 ) ;
if ( V_26 ) {
F_22 ( L_18 ) ;
return V_26 ;
}
V_3 = F_8 ( V_7 , L_19 , NULL , & V_24 ) ;
if ( F_23 ( V_3 ) && ( V_24 & 0x20000 ) ) {
F_18 ( & V_1 -> V_11 , L_20 ) ;
V_26 = F_15 ( V_1 ) ;
if ( V_26 )
F_22 ( L_21 ) ;
}
V_3 = F_24 ( V_7 ,
V_29 ,
F_16 ,
V_1 ) ;
if ( F_4 ( V_3 ) )
return - V_30 ;
V_26 = F_1 ( & V_1 -> V_11 , true ) ;
if ( V_26 )
goto V_31;
if ( V_6 -> V_9 ) {
F_6 ( & V_1 -> V_11 , true ) ;
V_3 = F_25 ( V_7 , L_22 , NULL , NULL ) ;
if ( F_4 ( V_3 ) )
F_5 ( & V_1 -> V_11 ,
L_23 ) ;
}
return 0 ;
V_31:
F_26 ( V_7 , V_29 , F_16 ) ;
return V_26 ;
}
static int F_27 ( struct V_10 * V_1 )
{
T_2 V_7 = F_3 ( & V_1 -> V_11 ) ;
F_26 ( V_7 , V_29 , F_16 ) ;
F_1 ( & V_1 -> V_11 , false ) ;
F_6 ( & V_1 -> V_11 , false ) ;
return 0 ;
}
static T_1 T_4
F_28 ( T_2 V_7 , T_3 V_32 , void * V_22 , void * * V_33 )
{
const struct V_34 * V_35 = V_22 ;
struct V_36 * V_11 ;
if ( F_29 ( V_7 , & V_11 ) != 0 )
return V_37 ;
if ( F_30 ( V_11 , V_35 ) == 0 )
if ( F_31 ( V_11 , NULL ) )
F_18 ( & V_11 -> V_11 ,
L_24 ) ;
return V_37 ;
}
static int T_4 F_32 ( void )
{
F_33 ( V_38 , V_39 ,
V_40 , F_28 , NULL ,
( void * ) V_41 , NULL ) ;
return F_34 ( & V_42 ) ;
}
static void T_5 F_35 ( void )
{
F_36 ( & V_42 ) ;
}
