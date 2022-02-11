static inline struct V_1 * F_1 ( struct V_2 * V_3 )
{
return F_2 ( V_3 , struct V_1 , V_3 ) ;
}
static void F_3 ( struct V_1 * V_4 )
{
F_4 ( & V_5 ) ;
F_5 ( & V_4 -> V_6 , & V_7 ) ;
F_6 ( & V_5 ) ;
}
static void F_7 ( struct V_1 * V_4 )
{
F_4 ( & V_5 ) ;
F_8 ( & V_4 -> V_6 ) ;
F_6 ( & V_5 ) ;
}
static struct V_1 * F_9 ( struct V_8 * V_9 )
{
struct V_1 * V_4 ;
F_4 ( & V_5 ) ;
F_10 (cam, &mmpcam_devices, devlist) {
if ( V_4 -> V_9 == V_9 ) {
F_6 ( & V_5 ) ;
return V_4 ;
}
}
F_6 ( & V_5 ) ;
return NULL ;
}
static void F_11 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
struct V_10 * V_11 ;
F_12 ( 0x3f , V_4 -> V_12 + V_13 ) ;
F_12 ( 0x3805b , V_4 -> V_12 + V_14 ) ;
F_13 ( 1 ) ;
F_14 ( V_3 , V_15 , 0x60000002 ) ;
V_11 = V_4 -> V_9 -> V_16 . V_17 ;
F_15 ( V_11 -> V_18 , 1 ) ;
F_13 ( 5 ) ;
F_16 ( V_3 , V_19 , 0x10000000 ) ;
F_15 ( V_11 -> V_20 , 0 ) ;
F_13 ( 5 ) ;
F_15 ( V_11 -> V_20 , 1 ) ;
F_13 ( 5 ) ;
}
static void F_17 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
struct V_10 * V_11 ;
F_12 ( 0 , V_4 -> V_12 + V_13 ) ;
F_12 ( 0 , V_4 -> V_12 + V_14 ) ;
V_11 = V_4 -> V_9 -> V_16 . V_17 ;
F_15 ( V_11 -> V_18 , 0 ) ;
F_15 ( V_11 -> V_20 , 0 ) ;
}
static T_1 F_18 ( int V_21 , void * V_22 )
{
struct V_2 * V_3 = V_22 ;
unsigned int V_23 , V_24 ;
F_19 ( & V_3 -> V_25 ) ;
V_23 = F_20 ( V_3 , V_26 ) ;
V_24 = F_21 ( V_3 , V_23 ) ;
F_22 ( & V_3 -> V_25 ) ;
return F_23 ( V_24 ) ;
}
static int F_24 ( struct V_8 * V_9 )
{
struct V_1 * V_4 ;
struct V_2 * V_3 ;
struct V_27 * V_28 ;
struct V_10 * V_11 ;
int V_29 ;
V_4 = F_25 ( sizeof( * V_4 ) , V_30 ) ;
if ( V_4 == NULL )
return - V_31 ;
V_4 -> V_9 = V_9 ;
F_26 ( & V_4 -> V_6 ) ;
V_3 = & V_4 -> V_3 ;
V_3 -> V_32 = V_33 ;
V_3 -> V_34 = F_11 ;
V_3 -> V_35 = F_17 ;
V_3 -> V_16 = & V_9 -> V_16 ;
V_3 -> V_36 = 0 ;
V_3 -> V_37 = V_38 ;
V_3 -> V_39 = V_40 ;
F_27 ( & V_3 -> V_25 ) ;
V_28 = F_28 ( V_9 , V_41 , 0 ) ;
if ( V_28 == NULL ) {
F_29 ( & V_9 -> V_16 , L_1 ) ;
V_29 = - V_42 ;
goto V_43;
}
V_3 -> V_44 = F_30 ( V_28 -> V_45 , F_31 ( V_28 ) ) ;
if ( V_3 -> V_44 == NULL ) {
F_29 ( & V_9 -> V_16 , L_2 ) ;
V_29 = - V_42 ;
goto V_43;
}
V_28 = F_28 ( V_9 , V_41 , 1 ) ;
if ( V_28 == NULL ) {
F_29 ( & V_9 -> V_16 , L_3 ) ;
V_29 = - V_42 ;
goto V_46;
}
V_4 -> V_12 = F_30 ( V_28 -> V_45 , F_31 ( V_28 ) ) ;
if ( V_4 -> V_12 == NULL ) {
F_29 ( & V_9 -> V_16 , L_4 ) ;
V_29 = - V_42 ;
goto V_46;
}
V_11 = V_9 -> V_16 . V_17 ;
V_3 -> V_47 = F_32 ( V_11 -> V_48 ) ;
if ( V_3 -> V_47 == NULL ) {
V_29 = - V_42 ;
F_29 ( & V_9 -> V_16 , L_5 ) ;
goto V_49;
}
V_29 = F_33 ( V_11 -> V_18 , L_6 ) ;
if ( V_29 ) {
F_29 ( & V_9 -> V_16 , L_7 ,
V_11 -> V_18 ) ;
goto V_49;
}
F_34 ( V_11 -> V_18 , 0 ) ;
V_29 = F_33 ( V_11 -> V_20 , L_8 ) ;
if ( V_29 ) {
F_29 ( & V_9 -> V_16 , L_9 ,
V_11 -> V_20 ) ;
goto V_50;
}
F_34 ( V_11 -> V_20 , 0 ) ;
F_11 ( V_3 ) ;
V_29 = F_35 ( V_3 ) ;
if ( V_29 )
goto V_51;
V_28 = F_28 ( V_9 , V_52 , 0 ) ;
if ( V_28 == NULL ) {
V_29 = - V_42 ;
goto V_53;
}
V_4 -> V_21 = V_28 -> V_45 ;
V_29 = F_36 ( V_4 -> V_21 , F_18 , V_54 ,
L_10 , V_3 ) ;
if ( V_29 == 0 ) {
F_3 ( V_4 ) ;
return 0 ;
}
V_53:
F_37 ( V_3 ) ;
V_51:
F_17 ( V_3 ) ;
F_38 ( V_11 -> V_20 ) ;
V_50:
F_38 ( V_11 -> V_18 ) ;
V_49:
F_39 ( V_4 -> V_12 ) ;
V_46:
F_39 ( V_3 -> V_44 ) ;
V_43:
F_40 ( V_4 ) ;
return V_29 ;
}
static int F_41 ( struct V_1 * V_4 )
{
struct V_2 * V_3 = & V_4 -> V_3 ;
struct V_10 * V_11 ;
F_7 ( V_4 ) ;
F_42 ( V_4 -> V_21 , V_3 ) ;
F_37 ( V_3 ) ;
F_17 ( V_3 ) ;
V_11 = V_4 -> V_9 -> V_16 . V_17 ;
F_38 ( V_11 -> V_20 ) ;
F_38 ( V_11 -> V_18 ) ;
F_39 ( V_4 -> V_12 ) ;
F_39 ( V_3 -> V_44 ) ;
F_40 ( V_4 ) ;
return 0 ;
}
static int F_43 ( struct V_8 * V_9 )
{
struct V_1 * V_4 = F_9 ( V_9 ) ;
if ( V_4 == NULL )
return - V_42 ;
return F_41 ( V_4 ) ;
}
static int T_2 F_44 ( void )
{
F_45 ( & V_5 ) ;
return F_46 ( & V_55 ) ;
}
static void T_3 F_47 ( void )
{
F_48 ( & V_55 ) ;
if ( ! F_49 ( & V_7 ) )
F_50 ( V_56 L_11 ) ;
}
