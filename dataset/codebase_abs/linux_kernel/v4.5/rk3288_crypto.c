static int F_1 ( struct V_1 * V_2 )
{
int V_3 ;
V_3 = F_2 ( V_2 -> V_4 ) ;
if ( V_3 ) {
F_3 ( V_2 -> V_2 , L_1 ,
V_5 , __LINE__ ) ;
goto V_6;
}
V_3 = F_2 ( V_2 -> V_7 ) ;
if ( V_3 ) {
F_3 ( V_2 -> V_2 , L_2 ,
V_5 , __LINE__ ) ;
goto V_8;
}
V_3 = F_2 ( V_2 -> V_9 ) ;
if ( V_3 ) {
F_3 ( V_2 -> V_2 , L_3 ,
V_5 , __LINE__ ) ;
goto V_10;
}
V_3 = F_2 ( V_2 -> V_11 ) ;
if ( V_3 ) {
F_3 ( V_2 -> V_2 , L_4 ,
V_5 , __LINE__ ) ;
goto V_12;
}
return V_3 ;
V_12:
F_4 ( V_2 -> V_9 ) ;
V_10:
F_4 ( V_2 -> V_7 ) ;
V_8:
F_4 ( V_2 -> V_4 ) ;
V_6:
return V_3 ;
}
static void F_5 ( struct V_1 * V_2 )
{
F_4 ( V_2 -> V_11 ) ;
F_4 ( V_2 -> V_9 ) ;
F_4 ( V_2 -> V_7 ) ;
F_4 ( V_2 -> V_4 ) ;
}
static int F_6 ( struct V_13 * V_14 ,
struct V_13 * V_15 ,
int V_16 )
{
int V_17 , V_18 , V_19 ;
V_17 = F_7 ( ( V_20 ) V_14 -> V_21 , 4 ) &&
F_7 ( ( V_20 ) V_14 -> V_22 , V_16 ) ;
if ( ! V_15 )
return V_17 ;
V_18 = F_7 ( ( V_20 ) V_15 -> V_21 , 4 ) &&
F_7 ( ( V_20 ) V_15 -> V_22 , V_16 ) ;
V_19 = V_17 && V_18 ;
return ( V_19 && ( V_14 -> V_22 == V_15 -> V_22 ) ) ;
}
static int F_8 ( struct V_1 * V_2 ,
struct V_13 * V_14 ,
struct V_13 * V_15 )
{
unsigned int V_23 ;
V_2 -> V_24 = V_2 -> V_24 ?
F_6 ( V_14 , V_15 , V_2 -> V_25 ) :
V_2 -> V_24 ;
if ( V_2 -> V_24 ) {
V_23 = F_9 ( V_2 -> V_26 , V_14 -> V_22 ) ;
V_2 -> V_26 -= V_23 ;
if ( ! F_10 ( V_2 -> V_2 , V_14 , 1 , V_27 ) ) {
F_3 ( V_2 -> V_2 , L_5 ,
V_5 , __LINE__ ) ;
return - V_28 ;
}
V_2 -> V_29 = F_11 ( V_14 ) ;
if ( V_15 ) {
if ( ! F_10 ( V_2 -> V_2 , V_15 , 1 , V_30 ) ) {
F_3 ( V_2 -> V_2 ,
L_6 ,
V_5 , __LINE__ ) ;
F_12 ( V_2 -> V_2 , V_14 , 1 ,
V_27 ) ;
return - V_28 ;
}
V_2 -> V_31 = F_11 ( V_15 ) ;
}
} else {
V_23 = ( V_2 -> V_26 > V_32 ) ?
V_32 : V_2 -> V_26 ;
if ( ! F_13 ( V_2 -> V_33 , V_2 -> V_34 ,
V_2 -> V_35 , V_23 ,
V_2 -> V_36 - V_2 -> V_26 ) ) {
F_3 ( V_2 -> V_2 , L_7 ,
V_5 , __LINE__ ) ;
return - V_28 ;
}
V_2 -> V_26 -= V_23 ;
F_14 ( & V_2 -> V_37 , V_2 -> V_35 , V_23 ) ;
if ( ! F_10 ( V_2 -> V_2 , & V_2 -> V_37 , 1 , V_27 ) ) {
F_3 ( V_2 -> V_2 , L_8 ,
V_5 , __LINE__ ) ;
return - V_38 ;
}
V_2 -> V_29 = F_11 ( & V_2 -> V_37 ) ;
if ( V_15 ) {
if ( ! F_10 ( V_2 -> V_2 , & V_2 -> V_37 , 1 ,
V_30 ) ) {
F_3 ( V_2 -> V_2 ,
L_8 ,
V_5 , __LINE__ ) ;
F_12 ( V_2 -> V_2 , & V_2 -> V_37 , 1 ,
V_27 ) ;
return - V_38 ;
}
V_2 -> V_31 = F_11 ( & V_2 -> V_37 ) ;
}
}
V_2 -> V_23 = V_23 ;
return 0 ;
}
static void F_15 ( struct V_1 * V_2 )
{
struct V_13 * V_39 , * V_40 ;
V_39 = V_2 -> V_24 ? V_2 -> V_14 : & V_2 -> V_37 ;
F_12 ( V_2 -> V_2 , V_39 , 1 , V_27 ) ;
if ( V_2 -> V_15 ) {
V_40 = V_2 -> V_24 ? V_2 -> V_15 : & V_2 -> V_37 ;
F_12 ( V_2 -> V_2 , V_40 , 1 , V_30 ) ;
}
}
static T_1 F_16 ( int V_41 , void * V_42 )
{
struct V_1 * V_2 = F_17 ( V_42 ) ;
T_2 V_43 ;
int V_3 = 0 ;
F_18 ( & V_2 -> V_44 ) ;
V_43 = F_19 ( V_2 , V_45 ) ;
F_20 ( V_2 , V_45 , V_43 ) ;
if ( V_43 & 0x0a ) {
F_21 ( V_2 -> V_2 , L_9 ) ;
V_3 = - V_46 ;
} else if ( V_43 & 0x05 ) {
V_3 = V_2 -> V_47 ( V_2 ) ;
}
if ( V_3 )
V_2 -> V_48 ( V_2 , V_3 ) ;
F_22 ( & V_2 -> V_44 ) ;
return V_49 ;
}
static void F_23 ( unsigned long V_50 )
{
struct V_1 * V_2 = (struct V_1 * ) V_50 ;
struct V_51 * V_52 , * V_53 ;
unsigned long V_54 ;
int V_3 = 0 ;
F_24 ( & V_2 -> V_44 , V_54 ) ;
V_53 = F_25 ( & V_2 -> V_55 ) ;
V_52 = F_26 ( & V_2 -> V_55 ) ;
F_27 ( & V_2 -> V_44 , V_54 ) ;
if ( ! V_52 ) {
F_3 ( V_2 -> V_2 , L_10 ) ;
return;
}
if ( V_53 ) {
V_53 -> V_48 ( V_53 , - V_56 ) ;
V_53 = NULL ;
}
if ( F_28 ( V_52 -> V_57 ) == V_58 )
V_2 -> V_59 = F_29 ( V_52 ) ;
V_3 = V_2 -> V_60 ( V_2 ) ;
if ( V_3 )
V_2 -> V_48 ( V_2 , V_3 ) ;
}
static int F_30 ( struct V_1 * V_61 )
{
unsigned int V_62 , V_63 ;
int V_3 = 0 ;
for ( V_62 = 0 ; V_62 < F_31 ( V_64 ) ; V_62 ++ ) {
V_64 [ V_62 ] -> V_2 = V_61 ;
V_3 = F_32 ( & V_64 [ V_62 ] -> V_65 ) ;
if ( V_3 )
goto V_66;
}
return 0 ;
V_66:
for ( V_63 = 0 ; V_63 < V_62 ; V_63 ++ )
F_33 ( & V_64 [ V_63 ] -> V_65 ) ;
return V_3 ;
}
static void F_34 ( void )
{
unsigned int V_62 ;
for ( V_62 = 0 ; V_62 < F_31 ( V_64 ) ; V_62 ++ )
F_33 ( & V_64 [ V_62 ] -> V_65 ) ;
}
static void F_35 ( void * V_50 )
{
struct V_1 * V_61 = V_50 ;
F_36 ( V_61 -> V_67 ) ;
}
static int F_37 ( struct V_68 * V_69 )
{
struct V_70 * V_71 ;
struct V_72 * V_2 = & V_69 -> V_2 ;
struct V_1 * V_61 ;
int V_3 = 0 ;
V_61 = F_38 ( & V_69 -> V_2 ,
sizeof( * V_61 ) , V_73 ) ;
if ( ! V_61 ) {
V_3 = - V_38 ;
goto V_74;
}
V_61 -> V_67 = F_39 ( V_2 , L_11 ) ;
if ( F_40 ( V_61 -> V_67 ) ) {
V_3 = F_41 ( V_61 -> V_67 ) ;
goto V_74;
}
F_36 ( V_61 -> V_67 ) ;
F_42 ( 10 , 20 ) ;
F_43 ( V_61 -> V_67 ) ;
V_3 = F_44 ( V_2 , F_35 , V_61 ) ;
if ( V_3 ) {
F_36 ( V_61 -> V_67 ) ;
goto V_74;
}
F_45 ( & V_61 -> V_44 ) ;
V_71 = F_46 ( V_69 , V_75 , 0 ) ;
V_61 -> V_76 = F_47 ( & V_69 -> V_2 , V_71 ) ;
if ( F_40 ( V_61 -> V_76 ) ) {
V_3 = F_41 ( V_61 -> V_76 ) ;
goto V_74;
}
V_61 -> V_7 = F_48 ( & V_69 -> V_2 , L_12 ) ;
if ( F_40 ( V_61 -> V_7 ) ) {
V_3 = F_41 ( V_61 -> V_7 ) ;
goto V_74;
}
V_61 -> V_9 = F_48 ( & V_69 -> V_2 , L_13 ) ;
if ( F_40 ( V_61 -> V_9 ) ) {
V_3 = F_41 ( V_61 -> V_9 ) ;
goto V_74;
}
V_61 -> V_4 = F_48 ( & V_69 -> V_2 , L_14 ) ;
if ( F_40 ( V_61 -> V_4 ) ) {
V_3 = F_41 ( V_61 -> V_4 ) ;
goto V_74;
}
V_61 -> V_11 = F_48 ( & V_69 -> V_2 , L_15 ) ;
if ( F_40 ( V_61 -> V_11 ) ) {
V_3 = F_41 ( V_61 -> V_11 ) ;
goto V_74;
}
V_61 -> V_41 = F_49 ( V_69 , 0 ) ;
if ( V_61 -> V_41 < 0 ) {
F_21 ( V_61 -> V_2 ,
L_16 ) ;
V_3 = V_61 -> V_41 ;
goto V_74;
}
V_3 = F_50 ( & V_69 -> V_2 , V_61 -> V_41 ,
F_16 , V_77 ,
L_17 , V_69 ) ;
if ( V_3 ) {
F_3 ( V_61 -> V_2 , L_18 ) ;
goto V_74;
}
V_61 -> V_2 = & V_69 -> V_2 ;
F_51 ( V_69 , V_61 ) ;
F_52 ( & V_61 -> V_78 ,
F_23 , ( unsigned long ) V_61 ) ;
F_53 ( & V_61 -> V_55 , 50 ) ;
V_61 -> V_79 = F_1 ;
V_61 -> V_80 = F_5 ;
V_61 -> V_81 = F_8 ;
V_61 -> V_82 = F_15 ;
V_3 = F_30 ( V_61 ) ;
if ( V_3 ) {
F_3 ( V_2 , L_19 ) ;
goto V_83;
}
F_54 ( V_2 , L_20 ) ;
return 0 ;
V_83:
F_55 ( & V_61 -> V_78 ) ;
V_74:
return V_3 ;
}
static int F_56 ( struct V_68 * V_69 )
{
struct V_1 * V_84 = F_17 ( V_69 ) ;
F_34 () ;
F_55 ( & V_84 -> V_78 ) ;
return 0 ;
}
