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
static int F_22 ( struct V_14 * V_12 , const struct V_25 * V_26 )
{
struct V_1 * V_2 ;
struct V_27 * V_28 = & V_12 -> V_28 ;
int V_15 ;
F_23 ( & V_12 -> V_28 , V_29
L_11 ,
( int ) V_12 -> V_30 , ( int ) V_12 -> V_27 , ( int ) V_12 -> V_31 ) ;
if ( F_24 ( V_12 , 0 ) != V_32 ) {
F_25 ( & V_12 -> V_28 , L_12 V_29 L_13
L_14 ,
( V_33 ) F_24 ( V_12 , 0 ) , V_32 ) ;
return - V_21 ;
}
V_2 = F_26 ( V_28 ) ;
if ( F_27 ( V_2 ) ) {
V_15 = ( int ) F_28 ( V_2 ) ;
F_25 ( V_28 , L_15 , V_15 ) ;
return V_15 ;
}
V_2 -> V_12 = V_12 ;
F_29 ( V_12 , V_2 ) ;
V_2 -> V_34 =
F_30 ( & V_12 -> V_28 , & V_2 -> V_35 ) ;
if ( ! V_2 -> V_34 ) {
V_15 = - V_21 ;
F_4 ( V_2 , L_16 ) ;
goto V_36;
}
V_15 = F_31 ( V_12 ) ;
if ( V_15 ) {
F_4 ( V_2 ,
L_17 ) ;
V_12 -> V_17 = 1 ;
V_15 = F_31 ( V_12 ) ;
}
if ( V_15 ) {
F_4 ( V_2 ,
L_18 ) ;
goto V_37;
}
V_15 = F_32 ( V_12 , 0 , V_29 ) ;
if ( V_15 ) {
F_4 ( V_2 , L_19 ) ;
goto V_38;
}
V_2 -> V_39 = F_33 ( V_12 , 0 ) ;
if ( ! V_2 -> V_39 ) {
F_4 ( V_2 , L_20 ) ;
V_15 = - V_21 ;
goto V_40;
}
F_5 ( V_2 , L_21 , & V_12 -> V_41 [ 0 ] , V_2 -> V_39 ) ;
F_1 ( V_2 ) ;
F_34 ( V_2 ) ;
V_15 = F_10 ( V_2 ) ;
if ( V_15 ) {
F_4 ( V_2 , L_22 ) ;
goto V_42;
}
V_15 = F_35 ( V_2 ) ;
if ( V_15 ) {
F_4 ( V_2 , L_23 , V_15 ) ;
goto V_43;
}
F_36 ( V_2 ) ;
return 0 ;
V_43:
F_21 ( V_2 ) ;
V_42:
F_37 ( V_12 , V_2 -> V_39 ) ;
V_40:
F_38 ( V_12 , 0 ) ;
V_38:
F_39 ( V_12 ) ;
V_37:
if ( V_2 -> V_35 . V_44 )
V_2 -> V_35 . V_44 ( V_2 -> V_34 ) ;
V_36:
F_40 ( V_2 ) ;
return V_15 ;
}
static void F_41 ( struct V_14 * V_12 )
{
struct V_1 * V_2 = F_42 ( V_12 ) ;
void T_2 * V_39 = V_2 -> V_39 ;
F_11 ( V_2 , L_5 , V_20 ) ;
F_43 ( V_2 ) ;
F_44 ( V_2 ) ;
F_21 ( V_2 ) ;
F_37 ( V_12 , V_39 ) ;
F_38 ( V_12 , 0 ) ;
F_39 ( V_12 ) ;
if ( V_2 -> V_35 . V_44 )
V_2 -> V_35 . V_44 ( V_2 -> V_34 ) ;
F_40 ( V_2 ) ;
}
static int F_45 ( struct V_27 * V_28 , bool V_45 )
{
int V_15 = 0 ;
struct V_14 * V_12 = F_46 ( V_28 ) ;
struct V_1 * V_2 = F_42 ( V_12 ) ;
F_47 ( V_2 , L_24 , V_20 ,
V_45 ? L_25 : L_26 ) ;
V_15 = F_48 ( V_2 , V_45 ) ;
if ( V_15 )
goto V_46;
V_15 = F_49 ( V_2 , V_45 ) ;
if ( V_15 )
goto V_46;
F_20 ( V_12 ) ;
V_46:
return V_15 ;
}
static int F_50 ( struct V_27 * V_28 , bool V_45 )
{
int V_15 = 0 ;
struct V_14 * V_12 = F_46 ( V_28 ) ;
struct V_1 * V_2 = F_42 ( V_12 ) ;
F_47 ( V_2 , L_24 , V_20 ,
V_45 ? L_25 : L_26 ) ;
F_12 ( V_12 ) ;
V_15 = F_51 ( V_2 , V_45 ) ;
if ( V_15 )
F_20 ( V_12 ) ;
return V_15 ;
}
static int F_52 ( struct V_27 * V_28 )
{
return F_45 ( V_28 , false ) ;
}
static int F_53 ( struct V_27 * V_28 )
{
return F_50 ( V_28 , false ) ;
}
static int T_3 F_54 ( void )
{
int V_15 ;
V_15 = F_55 () ;
if ( V_15 )
return V_15 ;
V_15 = F_56 ( & V_47 ) ;
if ( V_15 )
F_57 () ;
return V_15 ;
}
static void T_4 F_58 ( void )
{
F_59 ( & V_47 ) ;
F_57 () ;
}
