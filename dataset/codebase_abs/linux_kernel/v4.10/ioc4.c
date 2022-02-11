int
F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
F_2 ( & V_5 ) ;
F_3 ( & V_2 -> V_6 , & V_7 ) ;
if ( ! V_2 -> V_8 )
goto V_9;
F_4 (idd, &ioc4_devices, idd_list) {
if ( V_2 -> V_8 ( V_4 ) ) {
F_5 ( V_10
L_1
L_2 ,
V_11 , F_6 ( V_2 -> V_12 ) ,
F_7 ( V_4 -> V_13 ) ) ;
}
}
V_9:
F_8 ( & V_5 ) ;
return 0 ;
}
void
F_9 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
F_2 ( & V_5 ) ;
F_10 ( & V_2 -> V_6 ) ;
if ( ! V_2 -> V_14 )
goto V_9;
F_4 (idd, &ioc4_devices, idd_list) {
if ( V_2 -> V_14 ( V_4 ) ) {
F_5 ( V_10
L_3
L_4 ,
V_11 , F_6 ( V_2 -> V_12 ) ,
F_7 ( V_4 -> V_13 ) ) ;
}
}
V_9:
F_8 ( & V_5 ) ;
}
static void
F_11 ( struct V_3 * V_4 )
{
union V_15 V_16 ;
union V_17 V_18 ;
unsigned int V_19 , V_20 ;
T_1 V_21 , V_22 , V_23 ;
unsigned int V_24 ;
V_18 . V_25 = 0 ;
V_18 . V_26 . V_27 = V_28 ;
V_18 . V_26 . V_29 = 1 ;
F_12 ( V_18 . V_25 , & V_4 -> V_30 -> V_31 . V_25 ) ;
F_12 ( 0 , & V_4 -> V_30 -> V_16 . V_25 ) ;
F_13 () ;
V_16 . V_25 = 0 ;
V_16 . V_26 . V_24 = V_32 ;
V_16 . V_26 . V_33 = V_34 ;
V_16 . V_26 . V_35 = 0 ;
F_12 ( V_16 . V_25 , & V_4 -> V_30 -> V_16 . V_25 ) ;
F_13 () ;
V_21 = F_14 () ;
V_19 = 1 ;
for ( V_24 = 0 ; V_24 <= V_36 ; V_24 ++ ) {
do {
V_20 = V_19 ;
V_16 . V_25 = F_15 ( & V_4 -> V_30 -> V_16 . V_25 ) ;
V_19 = V_16 . V_26 . V_16 ;
} while ( V_20 || ! V_19 );
if ( V_24 == V_37 )
V_21 = F_14 () ;
}
V_22 = F_14 () ;
V_23 = ( V_22 - V_21 ) /
( V_38 * 2 * ( V_32 + 1 ) ) ;
if ( V_23 > V_39 ||
V_23 < V_40 ) {
F_5 ( V_41
L_5
L_6 ,
F_7 ( V_4 -> V_13 ) ,
V_42 / V_43 ) ;
V_23 = V_42 ;
} else {
T_2 V_44 = V_23 ;
F_16 ( V_44 , V_43 ) ;
F_5 ( V_45
L_7 ,
F_7 ( V_4 -> V_13 ) , ( unsigned long long ) V_44 ) ;
}
V_4 -> V_46 = V_23 ;
}
static unsigned int
F_17 ( struct V_3 * V_4 )
{
struct V_47 * V_48 = NULL ;
int V_49 = 0 ;
do {
V_48 = F_18 ( V_50 ,
V_51 , V_48 ) ;
if ( V_48 &&
V_4 -> V_13 -> V_52 -> V_53 == V_48 -> V_52 -> V_53 &&
3 == F_19 ( V_48 -> V_54 ) )
V_49 = 1 ;
} while ( V_48 && ! V_49 );
if ( NULL != V_48 ) {
F_20 ( V_48 ) ;
return V_55 ;
}
V_48 = NULL ;
do {
V_48 = F_18 ( V_56 ,
V_57 , V_48 ) ;
if ( V_48 &&
V_4 -> V_13 -> V_52 -> V_53 == V_48 -> V_52 -> V_53 &&
3 == F_19 ( V_48 -> V_54 ) )
V_49 = 1 ;
} while ( V_48 && ! V_49 );
if ( NULL != V_48 ) {
F_20 ( V_48 ) ;
return V_58 ;
}
return V_59 ;
}
static void
F_21 ( struct V_60 * V_61 )
{
F_22 ( L_8 ) ;
}
static int
F_23 ( struct V_47 * V_48 , const struct V_62 * V_63 )
{
struct V_3 * V_4 ;
struct V_1 * V_2 ;
T_3 V_64 ;
int V_65 ;
if ( ( V_65 = F_24 ( V_48 ) ) ) {
F_5 ( V_10
L_9 ,
V_11 , F_7 ( V_48 ) ) ;
goto V_9;
}
F_25 ( V_48 ) ;
V_4 = F_26 ( sizeof( struct V_3 ) , V_66 ) ;
if ( ! V_4 ) {
F_5 ( V_10
L_10 ,
V_11 , F_7 ( V_48 ) ) ;
V_65 = - V_67 ;
goto V_68;
}
V_4 -> V_13 = V_48 ;
V_4 -> V_69 = V_63 ;
V_4 -> V_70 = F_27 ( V_4 -> V_13 , 0 ) ;
if ( ! V_4 -> V_70 ) {
F_5 ( V_10
L_11
L_4 ,
V_11 , F_7 ( V_4 -> V_13 ) ) ;
V_65 = - V_67 ;
goto V_71;
}
if ( ! F_28 ( V_4 -> V_70 , sizeof( struct V_72 ) ,
L_12 ) ) {
F_5 ( V_10
L_13
L_4 ,
V_11 , F_7 ( V_4 -> V_13 ) ) ;
V_65 = - V_67 ;
goto V_71;
}
V_4 -> V_30 = F_29 ( V_4 -> V_70 ,
sizeof( struct V_72 ) ) ;
if ( ! V_4 -> V_30 ) {
F_5 ( V_10
L_14
L_4 ,
V_11 , F_7 ( V_4 -> V_13 ) ) ;
V_65 = - V_67 ;
goto V_73;
}
V_4 -> V_74 = F_17 ( V_4 ) ;
F_5 ( V_41 L_15 , F_7 ( V_48 ) ,
V_4 -> V_74 == V_55 ? L_16 :
V_4 -> V_74 == V_59 ? L_17 :
V_4 -> V_74 == V_58 ? L_18 : L_19 ) ;
F_30 ( V_4 -> V_13 , V_75 , & V_64 ) ;
F_31 ( V_4 -> V_13 , V_75 ,
V_64 | V_76 | V_77 ) ;
F_11 ( V_4 ) ;
F_12 ( ~ 0 , & V_4 -> V_30 -> V_78 . V_25 ) ;
F_12 ( ~ 0 , & V_4 -> V_30 -> V_79 ) ;
F_12 ( ~ 0 , & V_4 -> V_30 -> V_80 . V_25 ) ;
F_12 ( ~ 0 , & V_4 -> V_30 -> V_81 ) ;
V_4 -> V_82 = NULL ;
F_32 ( V_4 -> V_13 , V_4 ) ;
F_2 ( & V_5 ) ;
F_33 ( & V_4 -> V_83 , & V_84 ) ;
F_4 (is, &ioc4_submodules, is_list) {
if ( V_2 -> V_8 && V_2 -> V_8 ( V_4 ) ) {
F_5 ( V_10
L_20
L_4 ,
V_11 , F_6 ( V_2 -> V_12 ) ,
F_7 ( V_4 -> V_13 ) ) ;
}
}
F_8 ( & V_5 ) ;
if ( V_4 -> V_74 != V_59 ) {
F_5 ( V_41 L_21 ) ;
F_34 ( & V_85 ) ;
}
return 0 ;
V_73:
F_35 ( V_4 -> V_70 , sizeof( struct V_72 ) ) ;
V_71:
F_36 ( V_4 ) ;
V_68:
F_37 ( V_48 ) ;
V_9:
return V_65 ;
}
static void
F_38 ( struct V_47 * V_48 )
{
struct V_1 * V_2 ;
struct V_3 * V_4 ;
V_4 = F_39 ( V_48 ) ;
F_2 ( & V_5 ) ;
F_4 (is, &ioc4_submodules, is_list) {
if ( V_2 -> V_14 && V_2 -> V_14 ( V_4 ) ) {
F_5 ( V_10
L_22
L_4 ,
V_11 , F_6 ( V_2 -> V_12 ) ,
F_7 ( V_4 -> V_13 ) ) ;
}
}
F_8 ( & V_5 ) ;
F_40 ( V_4 -> V_30 ) ;
if ( ! V_4 -> V_70 ) {
F_5 ( V_10
L_23
L_24 ,
V_11 , F_7 ( V_4 -> V_13 ) ) ;
}
F_35 ( V_4 -> V_70 , sizeof( struct V_72 ) ) ;
F_37 ( V_48 ) ;
F_2 ( & V_5 ) ;
F_10 ( & V_4 -> V_83 ) ;
F_8 ( & V_5 ) ;
F_36 ( V_4 ) ;
}
static int T_4
F_41 ( void )
{
return F_42 ( & V_86 ) ;
}
static void T_5
F_43 ( void )
{
F_44 ( & V_85 ) ;
F_45 ( & V_86 ) ;
}
