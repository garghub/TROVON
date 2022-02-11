void F_1 ( struct V_1 * V_2 )
{
F_2 ( & V_2 -> V_3 , V_2 -> V_4 , false , false ) ;
V_2 -> V_4 = NULL ;
}
static void F_3 ( struct V_5 * V_2 )
{
struct V_1 * V_6 = F_4 ( V_2 ) ;
F_5 ( V_2 ) ;
if ( V_6 -> V_7 && V_2 -> V_8 ) {
F_6 ( V_2 -> V_8 ) ;
V_2 -> V_8 = NULL ;
}
F_7 ( V_2 ) ;
if ( V_6 -> V_4 )
F_1 ( V_6 ) ;
V_6 -> V_4 = NULL ;
F_8 ( V_6 ) ;
}
int F_9 ( struct V_1 * V_2 )
{
struct V_9 * * V_4 ;
if ( V_2 -> V_4 || V_2 -> V_7 )
return 0 ;
V_4 = F_10 ( & V_2 -> V_3 ) ;
if ( F_11 ( V_4 ) ) {
return F_12 ( V_4 ) ;
}
V_2 -> V_4 = V_4 ;
return 0 ;
}
static int F_13 ( struct V_10 * V_11 , struct V_12 * V_13 )
{
struct V_1 * V_2 = V_11 -> V_14 ;
struct V_15 * V_16 = V_2 -> V_3 . V_16 ;
T_1 V_17 ;
T_2 V_18 ;
int V_19 ;
V_18 = ( ( unsigned long ) V_13 -> V_20 - V_11 -> V_21 ) >>
V_22 ;
V_17 = F_14 ( V_2 -> V_3 . V_23 , V_24 ) ;
if ( V_18 > V_17 )
return V_25 ;
F_15 ( & V_16 -> V_26 ) ;
V_19 = F_16 ( V_11 , ( unsigned long ) V_13 -> V_20 ,
V_2 -> V_4 [ V_18 ] ) ;
F_17 ( & V_16 -> V_26 ) ;
switch ( V_19 ) {
case 0 :
return V_27 ;
case - V_28 :
return V_29 ;
case - V_30 :
return V_31 ;
case - V_32 :
case - V_33 :
return V_25 ;
default:
F_18 ( 1 ) ;
return V_25 ;
}
}
static struct V_5 * F_19 ( struct V_15 * V_16 ,
struct V_34 * V_35 ,
unsigned int * V_36 ,
unsigned long V_23 )
{
struct V_1 * V_2 ;
struct V_5 * V_37 ;
int V_38 ;
V_23 = F_20 ( V_23 , V_24 ) ;
V_2 = F_21 ( sizeof( * V_2 ) , V_39 ) ;
if ( ! V_2 )
return F_22 ( - V_28 ) ;
V_37 = & V_2 -> V_3 ;
V_38 = F_23 ( V_16 , V_37 , V_23 ) ;
if ( V_38 )
goto V_40;
V_38 = F_24 ( V_35 , V_37 , V_36 ) ;
if ( V_38 )
goto V_41;
F_25 ( V_37 ) ;
return V_37 ;
V_41:
F_7 ( V_37 ) ;
V_40:
F_8 ( V_2 ) ;
return F_22 ( V_38 ) ;
}
static int F_26 ( struct V_34 * V_35 , struct V_15 * V_16 ,
struct V_42 * args )
{
struct V_5 * V_37 ;
T_3 V_23 ;
T_3 V_43 = args -> V_44 * F_14 ( args -> V_45 , 8 ) ;
V_23 = args -> V_46 * V_43 ;
if ( V_23 == 0 )
return - V_33 ;
V_37 = F_19 ( V_16 , V_35 , & args -> V_36 , V_23 ) ;
if ( F_11 ( V_37 ) ) {
F_27 ( L_1 ) ;
return F_12 ( V_37 ) ;
}
args -> V_23 = V_37 -> V_23 ;
args -> V_43 = V_43 ;
F_27 ( L_2 , V_23 ) ;
return 0 ;
}
int F_28 ( struct V_34 * V_35 , struct V_15 * V_16 ,
T_4 V_36 , T_3 * V_47 )
{
int V_19 = 0 ;
struct V_5 * V_2 ;
F_15 ( & V_16 -> V_26 ) ;
V_2 = F_29 ( V_16 , V_35 , V_36 ) ;
if ( ! V_2 ) {
V_19 = - V_48 ;
goto V_49;
}
if ( ! F_30 ( & V_2 -> V_50 ) ) {
V_19 = F_31 ( V_2 ) ;
if ( V_19 )
goto V_51;
}
F_32 ( ! V_2 -> V_52 ) ;
V_2 -> V_52 -> V_53 = V_2 ;
V_19 = F_9 ( F_4 ( V_2 ) ) ;
if ( V_19 )
goto V_54;
* V_47 = F_33 ( & V_2 -> V_50 ) ;
goto V_51;
V_54:
F_5 ( V_2 ) ;
V_51:
F_34 ( V_2 ) ;
V_49:
F_17 ( & V_16 -> V_26 ) ;
return V_19 ;
}
int F_35 ( struct V_35 * V_52 , struct V_10 * V_11 )
{
struct V_34 * V_55 = V_52 -> V_53 ;
struct V_15 * V_16 = V_55 -> V_56 -> V_16 ;
struct V_57 * V_58 ;
struct V_5 * V_2 ;
struct V_1 * V_6 ;
int V_19 = 0 ;
F_15 ( & V_16 -> V_26 ) ;
V_58 = F_36 ( V_16 -> V_59 ,
V_11 -> V_60 ,
F_37 ( V_11 ) ) ;
if ( ! V_58 ) {
V_19 = - V_33 ;
goto V_61;
} else if ( ! F_38 ( V_58 , V_52 ) ) {
V_19 = - V_62 ;
goto V_61;
}
V_2 = F_39 ( V_58 , struct V_5 , V_50 ) ;
V_6 = F_4 ( V_2 ) ;
if ( V_2 -> V_8 && V_6 -> V_7 ) {
V_19 = F_40 ( V_2 -> V_8 , V_11 , 0 ) ;
goto V_61;
}
if ( ! V_2 -> V_16 -> V_63 -> V_64 ) {
V_19 = - V_33 ;
goto V_61;
}
V_11 -> V_65 |= V_66 | V_67 | V_68 | V_69 ;
V_11 -> V_70 = V_2 -> V_16 -> V_63 -> V_64 ;
V_11 -> V_14 = V_6 ;
V_11 -> V_71 =
F_41 ( F_42 ( V_11 -> V_65 ) ) ;
F_17 ( & V_16 -> V_26 ) ;
F_43 ( V_11 ) ;
return V_19 ;
V_61:
F_17 ( & V_16 -> V_26 ) ;
return V_19 ;
}
static int T_5 F_44 ( void )
{
int V_19 ;
V_72 = F_45 ( & V_73 , NULL ) ;
if ( ! V_72 ) {
V_19 = - V_28 ;
goto V_40;
}
F_46 ( V_72 , L_3 ) ;
V_19 = F_47 ( V_72 , 0 ) ;
if ( V_19 )
goto V_74;
return 0 ;
V_74:
F_48 ( V_72 ) ;
V_40:
return V_19 ;
}
static void T_6 F_49 ( void )
{
F_50 ( V_72 ) ;
F_48 ( V_72 ) ;
}
