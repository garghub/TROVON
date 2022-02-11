static
void F_1 ( struct V_1 * V_2 )
{
T_1 V_3 = F_2 ( V_2 , V_4 ) ;
F_3 ( V_2 -> V_5 , V_6 ) ;
F_3 ( V_2 -> V_7 , V_8 ) ;
switch ( V_3 ) {
case V_9 :
V_2 -> V_10 = L_1 ;
V_2 -> V_11 = V_12 ;
break;
default:
F_4 ( V_2 , L_2 , V_3 ) ;
V_2 -> V_10 = L_3 ;
V_2 -> V_11 = V_13 ;
}
F_5 ( V_2 , L_4 , V_2 -> V_10 ) ;
F_6 ( V_2 , V_14 , false ) ;
}
void F_7 ( struct V_1 * V_2 )
{
F_8 ( V_2 -> V_15 -> V_16 ) ;
}
void F_9 ( struct V_1 * V_2 )
{
F_10 ( V_2 -> V_15 -> V_16 ) ;
}
static int F_11 ( struct V_1 * V_2 )
{
struct V_17 * V_15 = V_2 -> V_15 ;
int V_18 ;
int V_19 = V_15 -> V_20 ;
bool V_21 = V_22 ;
F_12 ( V_2 , L_5 , V_23 ) ;
V_15 -> V_20 = 0 ;
F_13 ( V_15 ) ;
F_12 ( V_2 , L_6 , V_22 ? L_7 : L_8 ) ;
if ( V_22 && F_14 ( V_15 ) ) {
F_4 ( V_2 , L_9 ) ;
V_21 = false ;
}
if ( ! V_21 && V_19 ) {
F_4 ( V_2 , L_10 ) ;
V_18 = - V_24 ;
goto V_25;
}
V_18 = F_15 ( V_2 , V_15 -> V_16 , V_21 ) ;
if ( V_18 )
goto V_25;
F_16 ( & V_2 -> V_26 ) ;
V_18 = F_17 ( V_2 , false ) ;
F_18 ( & V_2 -> V_26 ) ;
if ( V_18 )
goto V_27;
return 0 ;
V_27:
F_19 ( V_2 , V_15 -> V_16 ) ;
F_20 ( V_15 ) ;
V_25:
F_21 ( V_15 ) ;
return V_18 ;
}
static int F_22 ( struct V_1 * V_2 )
{
struct V_17 * V_15 = V_2 -> V_15 ;
F_12 ( V_2 , L_5 , V_23 ) ;
F_21 ( V_15 ) ;
F_19 ( V_2 , V_15 -> V_16 ) ;
F_20 ( V_15 ) ;
return 0 ;
}
static int F_23 ( void * V_28 , void * V_29 , T_2 V_30 )
{
struct V_1 * V_2 = V_28 ;
if ( ! V_2 )
return - V_31 ;
return F_24 ( V_2 , V_29 , V_30 ) ;
}
static int F_25 ( void * V_28 )
{
struct V_1 * V_2 = V_28 ;
if ( ! V_2 )
return - V_31 ;
F_26 ( V_2 ) ;
return 0 ;
}
static int F_27 ( struct V_17 * V_15 , const struct V_32 * V_33 )
{
struct V_1 * V_2 ;
struct V_34 * V_35 = & V_15 -> V_35 ;
int V_18 ;
const struct V_36 V_37 = {
. V_38 = F_23 ,
. V_39 = F_25 ,
} ;
F_28 ( & V_15 -> V_35 , V_40
L_11 ,
( int ) V_15 -> V_41 , ( int ) V_15 -> V_34 , ( int ) V_15 -> V_42 ) ;
if ( F_29 ( V_15 , 0 ) != V_43 ) {
F_30 ( & V_15 -> V_35 , L_12 V_40 L_13
L_14 ,
( V_44 ) F_29 ( V_15 , 0 ) , V_43 ) ;
return - V_24 ;
}
V_2 = F_31 ( V_35 ) ;
if ( F_32 ( V_2 ) ) {
V_18 = ( int ) F_33 ( V_2 ) ;
F_30 ( V_35 , L_15 , V_18 ) ;
return V_18 ;
}
V_2 -> V_15 = V_15 ;
F_34 ( V_15 , V_2 ) ;
V_2 -> V_45 =
F_35 ( & V_15 -> V_35 , & V_2 -> V_46 , & V_37 , V_2 ) ;
if ( ! V_2 -> V_45 ) {
V_18 = - V_24 ;
F_4 ( V_2 , L_16 ) ;
goto V_47;
}
V_18 = F_36 ( V_15 ) ;
if ( V_18 ) {
F_4 ( V_2 ,
L_17 ) ;
V_15 -> V_20 = 1 ;
V_18 = F_36 ( V_15 ) ;
}
if ( V_18 ) {
F_4 ( V_2 ,
L_18 ) ;
goto V_48;
}
V_18 = F_37 ( V_15 , 0 , V_40 ) ;
if ( V_18 ) {
F_4 ( V_2 , L_19 ) ;
goto V_49;
}
V_2 -> V_50 = F_38 ( V_15 , 0 ) ;
if ( ! V_2 -> V_50 ) {
F_4 ( V_2 , L_20 ) ;
V_18 = - V_24 ;
goto V_51;
}
F_5 ( V_2 , L_21 , & V_15 -> V_52 [ 0 ] , V_2 -> V_50 ) ;
F_1 ( V_2 ) ;
F_39 ( V_2 ) ;
V_18 = F_11 ( V_2 ) ;
if ( V_18 ) {
F_4 ( V_2 , L_22 ) ;
goto V_53;
}
V_18 = F_40 ( V_2 ) ;
if ( V_18 ) {
F_4 ( V_2 , L_23 , V_18 ) ;
goto V_54;
}
#ifdef F_41
#ifdef F_42
V_2 -> V_55 . V_56 = V_57 ;
V_18 = F_43 ( & V_2 -> V_55 ) ;
if ( V_18 )
F_4 ( V_2 , L_24 , V_18 ) ;
#endif
#endif
F_44 ( V_2 ) ;
return 0 ;
V_54:
F_22 ( V_2 ) ;
V_53:
F_45 ( V_15 , V_2 -> V_50 ) ;
V_51:
F_46 ( V_15 , 0 ) ;
V_49:
F_47 ( V_15 ) ;
V_48:
if ( V_2 -> V_46 . V_58 )
V_2 -> V_46 . V_58 ( V_2 -> V_45 ) ;
V_47:
F_48 ( V_2 ) ;
return V_18 ;
}
static void F_49 ( struct V_17 * V_15 )
{
struct V_1 * V_2 = F_50 ( V_15 ) ;
void T_3 * V_50 = V_2 -> V_50 ;
F_12 ( V_2 , L_5 , V_23 ) ;
#ifdef F_41
#ifdef F_42
F_51 ( & V_2 -> V_55 ) ;
#endif
#endif
F_52 ( V_2 ) ;
F_53 () ;
F_54 ( V_2 ) ;
F_55 () ;
F_56 ( V_2 ) ;
F_22 ( V_2 ) ;
F_45 ( V_15 , V_50 ) ;
F_46 ( V_15 , 0 ) ;
F_47 ( V_15 ) ;
if ( V_2 -> V_46 . V_58 )
V_2 -> V_46 . V_58 ( V_2 -> V_45 ) ;
F_48 ( V_2 ) ;
}
static int F_57 ( struct V_34 * V_35 , bool V_59 )
{
int V_18 = 0 ;
struct V_17 * V_15 = F_58 ( V_35 ) ;
struct V_1 * V_2 = F_50 ( V_15 ) ;
F_59 ( V_2 , L_25 , V_23 ,
V_59 ? L_26 : L_27 ) ;
V_18 = F_60 ( V_2 , V_59 ) ;
if ( V_18 )
goto V_60;
V_18 = F_61 ( V_2 , V_59 ) ;
if ( V_18 )
goto V_60;
F_21 ( V_15 ) ;
V_60:
return V_18 ;
}
static int F_62 ( struct V_34 * V_35 , bool V_59 )
{
int V_18 = 0 ;
struct V_17 * V_15 = F_58 ( V_35 ) ;
struct V_1 * V_2 = F_50 ( V_15 ) ;
F_59 ( V_2 , L_25 , V_23 ,
V_59 ? L_26 : L_27 ) ;
F_13 ( V_15 ) ;
V_18 = F_63 ( V_2 , V_59 ) ;
if ( V_18 )
F_21 ( V_15 ) ;
return V_18 ;
}
static int V_57 ( struct V_61 * V_62 ,
unsigned long V_63 , void * V_64 )
{
struct V_1 * V_2 = F_64 (
V_62 , struct V_1 , V_55 ) ;
int V_18 = 0 ;
enum V_65 V_66 ;
F_59 ( V_2 , L_28 , V_23 , V_63 ) ;
switch ( V_63 ) {
case V_67 :
case V_68 :
case V_69 :
V_18 = F_60 ( V_2 , false ) ;
if ( V_18 )
break;
V_66 = V_70 ;
if ( V_2 -> V_46 . V_71 )
V_18 = V_2 -> V_46 . V_71 ( V_2 -> V_45 ,
V_66 ) ;
break;
case V_72 :
case V_73 :
case V_74 :
V_66 = V_75 ;
if ( V_2 -> V_46 . V_71 )
V_18 = V_2 -> V_46 . V_71 ( V_2 -> V_45 ,
V_66 ) ;
break;
default:
F_59 ( V_2 , L_29 , V_63 ) ;
break;
}
F_59 ( V_2 , L_30 , V_63 , V_18 ) ;
return V_18 ;
}
static int F_65 ( struct V_34 * V_35 )
{
return F_57 ( V_35 , false ) ;
}
static int F_66 ( struct V_34 * V_35 )
{
return F_62 ( V_35 , false ) ;
}
static int T_4 F_67 ( void )
{
int V_18 ;
V_18 = F_68 () ;
if ( V_18 )
return V_18 ;
V_18 = F_69 ( & V_76 ) ;
if ( V_18 )
F_70 () ;
return V_18 ;
}
static void T_5 F_71 ( void )
{
F_72 ( & V_76 ) ;
F_70 () ;
}
