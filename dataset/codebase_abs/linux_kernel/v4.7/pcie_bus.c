static
void F_1 ( struct V_1 * V_2 )
{
T_1 V_3 = F_2 ( V_2 , V_4 ) ;
F_3 ( V_2 -> V_5 , V_6 ) ;
switch ( V_3 ) {
case V_7 :
V_2 -> V_8 = L_1 ;
V_2 -> V_9 = V_10 ;
break;
default:
F_4 ( V_2 , L_2 , V_3 ) ;
V_2 -> V_8 = L_3 ;
V_2 -> V_9 = V_11 ;
}
F_5 ( V_2 , L_4 , V_2 -> V_8 ) ;
}
void F_6 ( struct V_1 * V_2 )
{
F_7 ( V_2 -> V_12 -> V_13 ) ;
}
void F_8 ( struct V_1 * V_2 )
{
F_9 ( V_2 -> V_12 -> V_13 ) ;
}
static int F_10 ( struct V_1 * V_2 )
{
struct V_14 * V_12 = V_2 -> V_12 ;
int V_15 ;
int V_16 = V_12 -> V_17 ;
bool V_18 = V_19 ;
F_11 ( V_2 , L_5 , V_20 ) ;
V_12 -> V_17 = 0 ;
F_12 ( V_12 ) ;
F_11 ( V_2 , L_6 , V_19 ? L_7 : L_8 ) ;
if ( V_19 && F_13 ( V_12 ) ) {
F_4 ( V_2 , L_9 ) ;
V_18 = false ;
}
if ( ! V_18 && V_16 ) {
F_4 ( V_2 , L_10 ) ;
V_15 = - V_21 ;
goto V_22;
}
V_15 = F_14 ( V_2 , V_12 -> V_13 , V_18 ) ;
if ( V_15 )
goto V_22;
F_15 ( & V_2 -> V_23 ) ;
V_15 = F_16 ( V_2 , false ) ;
F_17 ( & V_2 -> V_23 ) ;
if ( V_15 )
goto V_24;
return 0 ;
V_24:
F_18 ( V_2 , V_12 -> V_13 ) ;
F_19 ( V_12 ) ;
V_22:
F_20 ( V_12 ) ;
return V_15 ;
}
static int F_21 ( struct V_1 * V_2 )
{
struct V_14 * V_12 = V_2 -> V_12 ;
F_11 ( V_2 , L_5 , V_20 ) ;
F_20 ( V_12 ) ;
F_18 ( V_2 , V_12 -> V_13 ) ;
F_19 ( V_12 ) ;
return 0 ;
}
static int F_22 ( void * V_25 , void * V_26 , T_2 V_27 )
{
struct V_1 * V_2 = V_25 ;
if ( ! V_2 )
return - V_28 ;
return F_23 ( V_2 , V_26 , V_27 ) ;
}
static int F_24 ( void * V_25 )
{
struct V_1 * V_2 = V_25 ;
if ( ! V_2 )
return - V_28 ;
F_25 ( V_2 ) ;
return 0 ;
}
static int F_26 ( struct V_14 * V_12 , const struct V_29 * V_30 )
{
struct V_1 * V_2 ;
struct V_31 * V_32 = & V_12 -> V_32 ;
int V_15 ;
const struct V_33 V_34 = {
. V_35 = F_22 ,
. V_36 = F_24 ,
} ;
F_27 ( & V_12 -> V_32 , V_37
L_11 ,
( int ) V_12 -> V_38 , ( int ) V_12 -> V_31 , ( int ) V_12 -> V_39 ) ;
if ( F_28 ( V_12 , 0 ) != V_40 ) {
F_29 ( & V_12 -> V_32 , L_12 V_37 L_13
L_14 ,
( V_41 ) F_28 ( V_12 , 0 ) , V_40 ) ;
return - V_21 ;
}
V_2 = F_30 ( V_32 ) ;
if ( F_31 ( V_2 ) ) {
V_15 = ( int ) F_32 ( V_2 ) ;
F_29 ( V_32 , L_15 , V_15 ) ;
return V_15 ;
}
V_2 -> V_12 = V_12 ;
F_33 ( V_12 , V_2 ) ;
V_2 -> V_42 =
F_34 ( & V_12 -> V_32 , & V_2 -> V_43 , & V_34 , V_2 ) ;
if ( ! V_2 -> V_42 ) {
V_15 = - V_21 ;
F_4 ( V_2 , L_16 ) ;
goto V_44;
}
V_15 = F_35 ( V_12 ) ;
if ( V_15 ) {
F_4 ( V_2 ,
L_17 ) ;
V_12 -> V_17 = 1 ;
V_15 = F_35 ( V_12 ) ;
}
if ( V_15 ) {
F_4 ( V_2 ,
L_18 ) ;
goto V_45;
}
V_15 = F_36 ( V_12 , 0 , V_37 ) ;
if ( V_15 ) {
F_4 ( V_2 , L_19 ) ;
goto V_46;
}
V_2 -> V_47 = F_37 ( V_12 , 0 ) ;
if ( ! V_2 -> V_47 ) {
F_4 ( V_2 , L_20 ) ;
V_15 = - V_21 ;
goto V_48;
}
F_5 ( V_2 , L_21 , & V_12 -> V_49 [ 0 ] , V_2 -> V_47 ) ;
F_1 ( V_2 ) ;
F_38 ( V_2 ) ;
V_15 = F_10 ( V_2 ) ;
if ( V_15 ) {
F_4 ( V_2 , L_22 ) ;
goto V_50;
}
V_15 = F_39 ( V_2 ) ;
if ( V_15 ) {
F_4 ( V_2 , L_23 , V_15 ) ;
goto V_51;
}
F_40 ( V_2 ) ;
return 0 ;
V_51:
F_21 ( V_2 ) ;
V_50:
F_41 ( V_12 , V_2 -> V_47 ) ;
V_48:
F_42 ( V_12 , 0 ) ;
V_46:
F_43 ( V_12 ) ;
V_45:
if ( V_2 -> V_43 . V_52 )
V_2 -> V_43 . V_52 ( V_2 -> V_42 ) ;
V_44:
F_44 ( V_2 ) ;
return V_15 ;
}
static void F_45 ( struct V_14 * V_12 )
{
struct V_1 * V_2 = F_46 ( V_12 ) ;
void T_3 * V_47 = V_2 -> V_47 ;
F_11 ( V_2 , L_5 , V_20 ) ;
F_47 ( V_2 ) ;
F_48 ( V_2 ) ;
F_21 ( V_2 ) ;
F_41 ( V_12 , V_47 ) ;
F_42 ( V_12 , 0 ) ;
F_43 ( V_12 ) ;
if ( V_2 -> V_43 . V_52 )
V_2 -> V_43 . V_52 ( V_2 -> V_42 ) ;
F_49 ( V_2 ) ;
F_44 ( V_2 ) ;
}
static int F_50 ( struct V_31 * V_32 , bool V_53 )
{
int V_15 = 0 ;
struct V_14 * V_12 = F_51 ( V_32 ) ;
struct V_1 * V_2 = F_46 ( V_12 ) ;
F_52 ( V_2 , L_24 , V_20 ,
V_53 ? L_25 : L_26 ) ;
V_15 = F_53 ( V_2 , V_53 ) ;
if ( V_15 )
goto V_54;
V_15 = F_54 ( V_2 , V_53 ) ;
if ( V_15 )
goto V_54;
F_20 ( V_12 ) ;
V_54:
return V_15 ;
}
static int F_55 ( struct V_31 * V_32 , bool V_53 )
{
int V_15 = 0 ;
struct V_14 * V_12 = F_51 ( V_32 ) ;
struct V_1 * V_2 = F_46 ( V_12 ) ;
F_52 ( V_2 , L_24 , V_20 ,
V_53 ? L_25 : L_26 ) ;
F_12 ( V_12 ) ;
V_15 = F_56 ( V_2 , V_53 ) ;
if ( V_15 )
F_20 ( V_12 ) ;
return V_15 ;
}
static int F_57 ( struct V_31 * V_32 )
{
return F_50 ( V_32 , false ) ;
}
static int F_58 ( struct V_31 * V_32 )
{
return F_55 ( V_32 , false ) ;
}
static int T_4 F_59 ( void )
{
int V_15 ;
V_15 = F_60 () ;
if ( V_15 )
return V_15 ;
V_15 = F_61 ( & V_55 ) ;
if ( V_15 )
F_62 () ;
return V_15 ;
}
static void T_5 F_63 ( void )
{
F_64 ( & V_55 ) ;
F_62 () ;
}
