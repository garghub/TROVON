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
bool V_30 = V_2 -> V_22 != V_10 &&
V_2 -> V_22 != V_9 ;
if ( V_2 -> V_22 != V_31 )
F_3 ( V_2 , V_31 ) ;
V_2 -> V_32 = false ;
if ( V_30 )
V_2 -> V_5 -> V_33 ( V_2 , V_3 ) ;
F_1 ( V_2 , V_3 ) ;
F_14 ( V_2 , V_34 ) ;
if ( V_30 && V_2 -> V_5 -> V_35 )
V_2 -> V_5 -> V_35 ( V_2 , V_2 -> V_22 ) ;
}
F_12 ( & V_2 -> V_15 ) ;
F_15 ( & V_2 -> V_36 ) ;
}
static void F_16 ( struct V_37 * V_38 )
{
struct V_1 * V_2 = F_17 ( V_38 , struct V_1 ,
V_39 ) ;
F_13 ( V_2 , false ) ;
}
int F_18 ( struct V_1 * V_2 )
{
int V_14 = 0 ;
F_6 ( & V_2 -> V_15 ) ;
if ( V_2 -> V_22 != V_9 ) {
F_3 ( V_2 , V_31 ) ;
F_19 ( & V_2 -> V_39 ) ;
} else {
F_7 ( & V_2 -> V_17 , L_6 , V_18 , __LINE__ ) ;
V_14 = - V_19 ;
}
F_12 ( & V_2 -> V_15 ) ;
return V_14 ;
}
int F_20 ( struct V_1 * V_2 )
{
struct V_40 V_41 = { . V_42 = V_43 } ;
int V_14 = 0 ;
F_6 ( & V_2 -> V_15 ) ;
if ( V_2 -> V_22 != V_29 ) {
V_14 = - V_19 ;
F_7 ( & V_2 -> V_17 , L_7 ,
V_18 , __LINE__ , V_44 [ V_2 -> V_22 ] ) ;
goto V_45;
}
if ( ! V_2 -> V_46 ) {
V_14 = - V_47 ;
F_7 ( & V_2 -> V_17 , L_8 ,
V_18 , __LINE__ , V_14 ) ;
goto V_45;
}
V_14 = F_21 ( V_2 -> V_46 , & V_41 , sizeof( V_41 ) , V_48 ) ;
if ( V_14 < 0 ) {
F_7 ( & V_2 -> V_17 , L_9 ,
V_18 , __LINE__ , V_14 ) ;
goto V_45;
}
V_2 -> V_32 = false ;
F_3 ( V_2 , V_49 ) ;
V_14 = 0 ;
V_45:
F_12 ( & V_2 -> V_15 ) ;
return V_14 ;
}
static int F_22 ( struct V_1 * V_2 )
{
int V_14 ;
if ( F_23 ( 1 , & V_50 ) == 1 ) {
V_14 = F_24 () ;
if ( V_14 )
goto V_51;
}
F_25 ( & V_2 -> V_15 ) ;
F_26 ( & V_2 -> V_39 , F_16 ) ;
F_26 ( & V_2 -> V_36 , V_52 ) ;
V_2 -> V_53 = true ;
F_27 ( V_2 ) ;
V_2 -> V_54 = F_28 ( V_55 , V_2 -> V_17 . V_56 ,
F_29 ( 0 , V_2 -> V_27 ) , V_2 , V_2 -> V_57 ,
L_10 , V_2 -> V_27 ) ;
if ( F_30 ( V_2 -> V_54 ) ) {
V_14 = F_31 ( V_2 -> V_54 ) ;
F_7 ( & V_2 -> V_17 , L_11 ,
V_14 ) ;
goto V_51;
}
V_2 -> V_58 = F_32 ( V_2 -> V_54 -> V_59 . V_60 ,
L_12 ) ;
if ( ! V_2 -> V_58 ) {
V_14 = - V_61 ;
F_7 ( & V_2 -> V_17 , L_13 , V_14 ) ;
goto V_62;
}
F_33 ( V_2 ) ;
return 0 ;
V_62:
F_34 ( V_55 , F_29 ( 0 , V_2 -> V_27 ) ) ;
V_51:
if ( F_35 ( & V_50 ) )
F_36 () ;
return V_14 ;
}
static void F_37 ( struct V_1 * V_2 )
{
F_38 ( V_2 ) ;
F_39 ( V_2 -> V_58 ) ;
F_34 ( V_55 , F_29 ( 0 , V_2 -> V_27 ) ) ;
F_15 ( & V_2 -> V_39 ) ;
F_13 ( V_2 , false ) ;
if ( F_35 ( & V_50 ) )
F_36 () ;
F_40 ( V_2 -> V_63 ) ;
F_40 ( V_2 -> V_64 ) ;
F_40 ( V_2 -> V_65 ) ;
F_40 ( V_2 -> V_16 ) ;
}
static int F_41 ( struct V_66 * V_17 )
{
struct V_1 * V_2 = F_42 ( V_17 ) ;
F_6 ( & V_2 -> V_15 ) ;
switch ( V_2 -> V_22 ) {
case V_29 :
case V_28 :
case V_49 :
F_12 ( & V_2 -> V_15 ) ;
F_13 ( V_2 , false ) ;
break;
default:
F_12 ( & V_2 -> V_15 ) ;
break;
}
return 0 ;
}
static int T_1 F_43 ( void )
{
int V_67 ;
F_44 () ;
V_55 = F_45 ( V_68 , V_69 ) ;
if ( F_30 ( V_55 ) ) {
V_67 = F_31 ( V_55 ) ;
F_46 ( L_14 , V_67 ) ;
goto V_70;
}
F_47 ( & V_71 ) ;
V_67 = F_48 ( & V_72 ) ;
if ( V_67 ) {
F_46 ( L_15 , V_67 ) ;
goto V_73;
}
return 0 ;
V_73:
V_73 ( & V_71 ) ;
F_49 ( V_55 ) ;
V_70:
F_50 () ;
return V_67 ;
}
static void T_2 F_51 ( void )
{
F_52 ( & V_72 ) ;
V_73 ( & V_71 ) ;
F_49 ( V_55 ) ;
F_50 () ;
}
