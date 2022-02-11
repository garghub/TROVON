static
void F_1 ( struct V_1 * V_2 )
{
T_1 V_3 = F_2 ( V_2 , V_4 ) ;
T_2 V_5 = ( F_2 ( V_2 , V_6 ) &
V_7 ) ;
F_3 ( V_2 -> V_8 , V_9 ) ;
F_3 ( V_2 -> V_10 , V_11 ) ;
V_2 -> V_12 = V_13 ;
V_2 -> V_5 = V_5 ;
switch ( V_3 ) {
case V_14 :
switch ( V_5 ) {
case V_15 :
V_2 -> V_16 = L_1 ;
V_2 -> V_17 = V_18 ;
if ( F_4 ( V_2 ,
V_19 ) )
V_2 -> V_12 = V_19 ;
break;
case V_20 :
V_2 -> V_16 = L_2 ;
V_2 -> V_17 = V_21 ;
break;
default:
V_2 -> V_16 = L_3 ;
V_2 -> V_17 = V_22 ;
break;
}
break;
default:
F_5 ( V_2 , L_4 ,
V_3 , V_5 ) ;
V_2 -> V_16 = L_3 ;
V_2 -> V_17 = V_22 ;
}
F_6 ( V_2 , L_5 , V_2 -> V_16 ) ;
F_7 ( V_2 , V_2 -> V_12 , false ) ;
}
void F_8 ( struct V_1 * V_2 )
{
F_9 ( V_2 -> V_23 -> V_24 ) ;
}
void F_10 ( struct V_1 * V_2 )
{
F_11 ( V_2 -> V_23 -> V_24 ) ;
}
static int F_12 ( struct V_1 * V_2 )
{
struct V_25 * V_23 = V_2 -> V_23 ;
int V_26 ;
int V_27 = V_23 -> V_28 ;
bool V_29 = V_30 ;
bool V_31 = F_13 ( V_32 ,
V_2 -> V_10 ) ;
F_14 ( V_2 , L_6 , V_31 ) ;
V_23 -> V_28 = 0 ;
F_15 ( V_23 ) ;
F_14 ( V_2 , L_7 , V_30 ? L_8 : L_9 ) ;
if ( V_30 && F_16 ( V_23 ) ) {
F_5 ( V_2 , L_10 ) ;
V_29 = false ;
}
if ( ! V_29 && V_27 ) {
F_5 ( V_2 , L_11 ) ;
V_26 = - V_33 ;
goto V_34;
}
V_26 = F_17 ( V_2 , V_23 -> V_24 , V_29 ) ;
if ( V_26 )
goto V_34;
F_18 ( & V_2 -> V_35 ) ;
V_26 = F_19 ( V_2 , V_31 ) ;
F_20 ( & V_2 -> V_35 ) ;
if ( V_26 )
goto V_36;
return 0 ;
V_36:
F_21 ( V_2 , V_23 -> V_24 ) ;
F_22 ( V_23 ) ;
V_34:
F_23 ( V_23 ) ;
return V_26 ;
}
static int F_24 ( struct V_1 * V_2 )
{
struct V_25 * V_23 = V_2 -> V_23 ;
F_14 ( V_2 , L_12 ) ;
F_23 ( V_23 ) ;
F_21 ( V_2 , V_23 -> V_24 ) ;
F_22 ( V_23 ) ;
return 0 ;
}
static int F_25 ( void * V_37 , void * V_38 , T_3 V_39 )
{
struct V_1 * V_2 = V_37 ;
if ( ! V_2 )
return - V_40 ;
return F_26 ( V_2 , V_38 , V_39 ) ;
}
static int F_27 ( void * V_37 )
{
struct V_1 * V_2 = V_37 ;
if ( ! V_2 )
return - V_40 ;
F_28 ( V_2 ) ;
return 0 ;
}
static int F_29 ( struct V_25 * V_23 , const struct V_41 * V_42 )
{
struct V_1 * V_2 ;
struct V_43 * V_44 = & V_23 -> V_44 ;
int V_26 ;
const struct V_45 V_46 = {
. V_47 = F_25 ,
. V_48 = F_27 ,
} ;
F_30 ( & V_23 -> V_44 , V_49
L_13 ,
( int ) V_23 -> V_50 , ( int ) V_23 -> V_43 , ( int ) V_23 -> V_51 ) ;
if ( F_31 ( V_23 , 0 ) != V_52 ) {
F_32 ( & V_23 -> V_44 , L_14 V_49 L_15
L_16 ,
( V_53 ) F_31 ( V_23 , 0 ) , V_52 ) ;
return - V_33 ;
}
V_2 = F_33 ( V_44 ) ;
if ( F_34 ( V_2 ) ) {
V_26 = ( int ) F_35 ( V_2 ) ;
F_32 ( V_44 , L_17 , V_26 ) ;
return V_26 ;
}
V_2 -> V_23 = V_23 ;
F_36 ( V_23 , V_2 ) ;
V_2 -> V_54 =
F_37 ( & V_23 -> V_44 , & V_2 -> V_55 , & V_46 , V_2 ) ;
if ( ! V_2 -> V_54 ) {
V_26 = - V_33 ;
F_5 ( V_2 , L_18 ) ;
goto V_56;
}
V_26 = F_38 ( V_23 ) ;
if ( V_26 ) {
F_5 ( V_2 ,
L_19 ) ;
V_23 -> V_28 = 1 ;
V_26 = F_38 ( V_23 ) ;
}
if ( V_26 ) {
F_5 ( V_2 ,
L_20 ) ;
goto V_57;
}
V_26 = F_39 ( V_23 , 0 , V_49 ) ;
if ( V_26 ) {
F_5 ( V_2 , L_21 ) ;
goto V_58;
}
V_2 -> V_59 = F_40 ( V_23 , 0 ) ;
if ( ! V_2 -> V_59 ) {
F_5 ( V_2 , L_22 ) ;
V_26 = - V_33 ;
goto V_60;
}
F_6 ( V_2 , L_23 , & V_23 -> V_61 [ 0 ] , V_2 -> V_59 ) ;
F_1 ( V_2 ) ;
F_41 ( V_2 ) ;
V_26 = F_12 ( V_2 ) ;
if ( V_26 ) {
F_5 ( V_2 , L_24 ) ;
goto V_62;
}
V_26 = F_42 ( V_2 ) ;
if ( V_26 ) {
F_5 ( V_2 , L_25 , V_26 ) ;
goto V_63;
}
#ifdef F_43
#ifdef F_44
V_2 -> V_64 . V_65 = V_66 ;
V_26 = F_45 ( & V_2 -> V_64 ) ;
if ( V_26 )
F_5 ( V_2 , L_26 , V_26 ) ;
#endif
#endif
F_46 ( V_2 ) ;
return 0 ;
V_63:
F_24 ( V_2 ) ;
V_62:
F_47 ( V_23 , V_2 -> V_59 ) ;
V_60:
F_48 ( V_23 , 0 ) ;
V_58:
F_49 ( V_23 ) ;
V_57:
if ( V_2 -> V_55 . V_67 )
V_2 -> V_55 . V_67 ( V_2 -> V_54 ) ;
V_56:
F_50 ( V_2 ) ;
return V_26 ;
}
static void F_51 ( struct V_25 * V_23 )
{
struct V_1 * V_2 = F_52 ( V_23 ) ;
void T_4 * V_59 = V_2 -> V_59 ;
F_14 ( V_2 , L_27 ) ;
#ifdef F_43
#ifdef F_44
F_53 ( & V_2 -> V_64 ) ;
#endif
#endif
F_54 ( V_2 ) ;
F_55 () ;
F_56 ( V_2 ) ;
F_57 () ;
F_58 ( V_2 ) ;
F_24 ( V_2 ) ;
F_47 ( V_23 , V_59 ) ;
F_48 ( V_23 , 0 ) ;
F_49 ( V_23 ) ;
if ( V_2 -> V_55 . V_67 )
V_2 -> V_55 . V_67 ( V_2 -> V_54 ) ;
F_50 ( V_2 ) ;
}
static int F_59 ( struct V_43 * V_44 , bool V_68 )
{
int V_26 = 0 ;
struct V_25 * V_23 = F_60 ( V_44 ) ;
struct V_1 * V_2 = F_52 ( V_23 ) ;
F_61 ( V_2 , L_28 , V_68 ? L_29 : L_30 ) ;
V_26 = F_62 ( V_2 , V_68 ) ;
if ( V_26 )
goto V_69;
V_26 = F_63 ( V_2 , V_68 ) ;
if ( V_26 )
goto V_69;
F_23 ( V_23 ) ;
V_69:
return V_26 ;
}
static int F_64 ( struct V_43 * V_44 , bool V_68 )
{
int V_26 = 0 ;
struct V_25 * V_23 = F_60 ( V_44 ) ;
struct V_1 * V_2 = F_52 ( V_23 ) ;
F_61 ( V_2 , L_31 , V_68 ? L_29 : L_30 ) ;
F_15 ( V_23 ) ;
V_26 = F_65 ( V_2 , V_68 ) ;
if ( V_26 )
F_23 ( V_23 ) ;
return V_26 ;
}
static int V_66 ( struct V_70 * V_71 ,
unsigned long V_72 , void * V_73 )
{
struct V_1 * V_2 = F_66 (
V_71 , struct V_1 , V_64 ) ;
int V_26 = 0 ;
enum V_74 V_75 ;
F_61 ( V_2 , L_32 , V_72 ) ;
switch ( V_72 ) {
case V_76 :
case V_77 :
case V_78 :
V_26 = F_62 ( V_2 , false ) ;
if ( V_26 )
break;
V_75 = V_79 ;
if ( V_2 -> V_55 . V_80 )
V_26 = V_2 -> V_55 . V_80 ( V_2 -> V_54 ,
V_75 ) ;
break;
case V_81 :
case V_82 :
case V_83 :
V_75 = V_84 ;
if ( V_2 -> V_55 . V_80 )
V_26 = V_2 -> V_55 . V_80 ( V_2 -> V_54 ,
V_75 ) ;
break;
default:
F_61 ( V_2 , L_33 , V_72 ) ;
break;
}
F_61 ( V_2 , L_34 , V_72 , V_26 ) ;
return V_26 ;
}
static int F_67 ( struct V_43 * V_44 )
{
return F_59 ( V_44 , false ) ;
}
static int F_68 ( struct V_43 * V_44 )
{
return F_64 ( V_44 , false ) ;
}
static int T_5 F_69 ( void )
{
int V_26 ;
V_26 = F_70 () ;
if ( V_26 )
return V_26 ;
V_26 = F_71 ( & V_85 ) ;
if ( V_26 )
F_72 () ;
return V_26 ;
}
static void T_6 F_73 ( void )
{
F_74 ( & V_85 ) ;
F_72 () ;
}
