static void F_1 ( struct V_1 * V_2 , bool V_3 )
{
int V_4 ;
#define F_2 (45)
if ( V_3 && V_2 -> V_5 -> V_6 )
V_2 -> V_5 -> V_6 ( V_2 ) ;
else
V_2 -> V_5 -> V_7 ( V_2 ) ;
for ( V_4 = 0 ; V_4 < F_2 ; V_4 ++ ) {
if ( V_2 -> V_5 -> V_8 ( V_2 ) ) {
F_3 ( V_2 , V_9 ) ;
return;
}
F_4 ( 1000 ) ;
}
F_3 ( V_2 , V_10 ) ;
}
int F_5 ( struct V_1 * V_2 )
{
const struct V_11 * V_12 ;
struct V_11 * V_13 ;
int V_14 ;
F_6 ( & V_2 -> V_15 ) ;
if ( ! V_2 -> V_16 ) {
F_7 ( & V_2 -> V_17 , L_1 ,
V_18 , __LINE__ ) ;
V_14 = - V_19 ;
goto V_20;
}
V_21:
if ( V_2 -> V_22 != V_9 ) {
F_7 ( & V_2 -> V_17 , L_2 ,
V_18 , __LINE__ ) ;
V_14 = - V_19 ;
goto V_20;
}
if ( ! V_2 -> V_5 -> V_8 ( V_2 ) ) {
F_1 ( V_2 , false ) ;
goto V_21;
}
V_13 = F_8 () ;
if ( ! V_13 ) {
F_7 ( & V_2 -> V_17 , L_3 ,
V_18 , __LINE__ ) ;
V_14 = - V_23 ;
goto V_20;
}
V_13 -> V_24 = V_25 ;
V_12 = F_9 ( V_13 ) ;
V_14 = V_2 -> V_5 -> V_26 ( V_2 , V_2 -> V_27 ) ;
F_10 ( V_12 ) ;
F_11 ( V_13 ) ;
if ( V_14 )
goto V_20;
if ( ! strcmp ( V_2 -> V_16 , L_4 ) )
F_3 ( V_2 , V_28 ) ;
else
F_3 ( V_2 , V_29 ) ;
V_20:
F_12 ( & V_2 -> V_15 ) ;
if ( V_14 )
F_7 ( & V_2 -> V_17 , L_5 , V_14 ) ;
return V_14 ;
}
void F_13 ( struct V_1 * V_2 , bool V_3 )
{
F_6 ( & V_2 -> V_15 ) ;
if ( V_2 -> V_22 != V_9 || V_3 ) {
T_1 V_22 = V_2 -> V_22 == V_30 ?
V_2 -> V_31 : V_2 -> V_22 ;
bool V_32 = V_22 != V_10 &&
V_22 != V_9 ;
if ( V_2 -> V_22 != V_30 )
F_3 ( V_2 , V_30 ) ;
V_2 -> V_33 = false ;
if ( V_32 )
V_2 -> V_5 -> V_34 ( V_2 , V_3 ) ;
F_1 ( V_2 , V_3 ) ;
F_14 ( V_2 , V_35 ) ;
if ( V_32 && V_2 -> V_5 -> V_36 )
V_2 -> V_5 -> V_36 ( V_2 , V_2 -> V_22 ) ;
}
F_12 ( & V_2 -> V_15 ) ;
F_15 ( & V_2 -> V_37 ) ;
}
static void F_16 ( struct V_38 * V_39 )
{
struct V_1 * V_2 = F_17 ( V_39 , struct V_1 ,
V_40 ) ;
F_13 ( V_2 , false ) ;
}
int F_18 ( struct V_1 * V_2 )
{
int V_14 = 0 ;
F_6 ( & V_2 -> V_15 ) ;
if ( V_2 -> V_22 != V_9 ) {
if ( V_2 -> V_22 != V_30 ) {
V_2 -> V_31 = V_2 -> V_22 ;
F_3 ( V_2 , V_30 ) ;
F_19 ( & V_2 -> V_40 ) ;
}
} else {
F_7 ( & V_2 -> V_17 , L_6 , V_18 , __LINE__ ) ;
V_14 = - V_19 ;
}
F_12 ( & V_2 -> V_15 ) ;
return V_14 ;
}
int F_20 ( struct V_1 * V_2 )
{
struct V_41 V_42 = { . V_43 = V_44 } ;
int V_14 = 0 ;
F_6 ( & V_2 -> V_15 ) ;
if ( V_2 -> V_22 != V_29 ) {
V_14 = - V_19 ;
F_7 ( & V_2 -> V_17 , L_7 ,
V_18 , __LINE__ , V_45 [ V_2 -> V_22 ] ) ;
goto V_46;
}
if ( ! V_2 -> V_47 ) {
V_14 = - V_48 ;
F_7 ( & V_2 -> V_17 , L_8 ,
V_18 , __LINE__ , V_14 ) ;
goto V_46;
}
V_14 = F_21 ( V_2 -> V_47 , & V_42 , sizeof( V_42 ) , V_49 ) ;
if ( V_14 < 0 ) {
F_7 ( & V_2 -> V_17 , L_9 ,
V_18 , __LINE__ , V_14 ) ;
goto V_46;
}
V_2 -> V_33 = false ;
F_3 ( V_2 , V_50 ) ;
V_14 = 0 ;
V_46:
F_12 ( & V_2 -> V_15 ) ;
return V_14 ;
}
static int F_22 ( struct V_1 * V_2 )
{
int V_14 ;
if ( F_23 ( 1 , & V_51 ) == 1 ) {
V_14 = F_24 () ;
if ( V_14 )
goto V_52;
}
F_25 ( & V_2 -> V_15 ) ;
F_26 ( & V_2 -> V_40 , F_16 ) ;
F_26 ( & V_2 -> V_37 , V_53 ) ;
V_2 -> V_54 = true ;
F_27 ( V_2 ) ;
V_2 -> V_55 = F_28 ( V_56 , V_2 -> V_17 . V_57 ,
F_29 ( 0 , V_2 -> V_27 ) , V_2 , V_2 -> V_58 ,
L_10 , V_2 -> V_27 ) ;
if ( F_30 ( V_2 -> V_55 ) ) {
V_14 = F_31 ( V_2 -> V_55 ) ;
F_7 ( & V_2 -> V_17 , L_11 ,
V_14 ) ;
goto V_52;
}
V_2 -> V_59 = F_32 ( V_2 -> V_55 -> V_60 . V_61 ,
L_12 ) ;
if ( ! V_2 -> V_59 ) {
V_14 = - V_62 ;
F_7 ( & V_2 -> V_17 , L_13 , V_14 ) ;
goto V_63;
}
F_33 ( V_2 ) ;
return 0 ;
V_63:
F_34 ( V_56 , F_29 ( 0 , V_2 -> V_27 ) ) ;
V_52:
if ( F_35 ( & V_51 ) )
F_36 () ;
return V_14 ;
}
static void F_37 ( struct V_1 * V_2 )
{
F_38 ( V_2 ) ;
F_39 ( V_2 -> V_59 ) ;
F_34 ( V_56 , F_29 ( 0 , V_2 -> V_27 ) ) ;
F_15 ( & V_2 -> V_40 ) ;
F_13 ( V_2 , false ) ;
if ( F_35 ( & V_51 ) )
F_36 () ;
F_40 ( V_2 -> V_64 ) ;
F_40 ( V_2 -> V_65 ) ;
F_40 ( V_2 -> V_66 ) ;
F_40 ( V_2 -> V_16 ) ;
}
static int F_41 ( struct V_67 * V_17 )
{
struct V_1 * V_2 = F_42 ( V_17 ) ;
F_6 ( & V_2 -> V_15 ) ;
switch ( V_2 -> V_22 ) {
case V_29 :
case V_28 :
case V_50 :
F_12 ( & V_2 -> V_15 ) ;
F_13 ( V_2 , false ) ;
break;
default:
F_12 ( & V_2 -> V_15 ) ;
break;
}
return 0 ;
}
static int T_2 F_43 ( void )
{
int V_68 ;
F_44 () ;
V_56 = F_45 ( V_69 , V_70 ) ;
if ( F_30 ( V_56 ) ) {
V_68 = F_31 ( V_56 ) ;
F_46 ( L_14 , V_68 ) ;
goto V_71;
}
F_47 ( & V_72 ) ;
V_68 = F_48 ( & V_73 ) ;
if ( V_68 ) {
F_46 ( L_15 , V_68 ) ;
goto V_74;
}
return 0 ;
V_74:
V_74 ( & V_72 ) ;
F_49 ( V_56 ) ;
V_71:
F_50 () ;
return V_68 ;
}
static void T_3 F_51 ( void )
{
F_52 ( & V_73 ) ;
V_74 ( & V_72 ) ;
F_49 ( V_56 ) ;
F_50 () ;
}
