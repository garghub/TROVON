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
static void T_1
F_11 ( struct V_3 * V_4 )
{
union V_15 V_16 ;
union V_17 V_18 ;
unsigned int V_19 , V_20 = 1 ;
struct V_21 V_22 , V_23 ;
T_2 V_24 , V_25 , V_26 ;
unsigned int V_27 = 0 ;
V_18 . V_28 = 0 ;
V_18 . V_29 . V_30 = V_31 ;
V_18 . V_29 . V_32 = 1 ;
F_12 ( V_18 . V_28 , & V_4 -> V_33 -> V_34 . V_28 ) ;
F_12 ( 0 , & V_4 -> V_33 -> V_16 . V_28 ) ;
F_13 () ;
V_16 . V_28 = 0 ;
V_16 . V_29 . V_27 = V_35 ;
V_16 . V_29 . V_36 = V_37 ;
V_16 . V_29 . V_38 = 0 ;
F_12 ( V_16 . V_28 , & V_4 -> V_33 -> V_16 . V_28 ) ;
F_13 () ;
do {
V_16 . V_28 = F_14 ( & V_4 -> V_33 -> V_16 . V_28 ) ;
V_19 = V_16 . V_29 . V_16 ;
if ( ! V_20 && V_19 ) {
V_27 ++ ;
if ( V_27 == V_39 ) {
F_15 ( & V_23 ) ;
break;
} else if ( V_27 == V_40 )
F_15 ( & V_22 ) ;
}
V_20 = V_19 ;
} while ( 1 );
V_25 = V_23 . V_41 * V_42 + V_23 . V_43 ;
V_24 = V_22 . V_41 * V_42 + V_22 . V_43 ;
V_26 = ( V_25 - V_24 ) /
( V_44 * 2 * ( V_35 + 1 ) ) ;
if ( V_26 > V_45 ||
V_26 < V_46 ) {
F_5 ( V_47
L_5
L_6 ,
F_7 ( V_4 -> V_13 ) ,
V_48 / V_49 ) ;
V_26 = V_48 ;
} else {
T_3 V_50 = V_26 ;
F_16 ( V_50 , V_49 ) ;
F_5 ( V_51
L_7 ,
F_7 ( V_4 -> V_13 ) , ( unsigned long long ) V_50 ) ;
}
V_4 -> V_52 = V_26 ;
}
static unsigned int T_1
F_17 ( struct V_3 * V_4 )
{
struct V_53 * V_54 = NULL ;
int V_55 = 0 ;
do {
V_54 = F_18 ( V_56 ,
V_57 , V_54 ) ;
if ( V_54 &&
V_4 -> V_13 -> V_58 -> V_59 == V_54 -> V_58 -> V_59 &&
3 == F_19 ( V_54 -> V_60 ) )
V_55 = 1 ;
} while ( V_54 && ! V_55 );
if ( NULL != V_54 ) {
F_20 ( V_54 ) ;
return V_61 ;
}
V_54 = NULL ;
do {
V_54 = F_18 ( V_62 ,
V_63 , V_54 ) ;
if ( V_54 &&
V_4 -> V_13 -> V_58 -> V_59 == V_54 -> V_58 -> V_59 &&
3 == F_19 ( V_54 -> V_60 ) )
V_55 = 1 ;
} while ( V_54 && ! V_55 );
if ( NULL != V_54 ) {
F_20 ( V_54 ) ;
return V_64 ;
}
return V_65 ;
}
static void
F_21 ( struct V_66 * V_67 )
{
F_22 ( L_8 ) ;
}
static int T_1
F_23 ( struct V_53 * V_54 , const struct V_68 * V_69 )
{
struct V_3 * V_4 ;
struct V_1 * V_2 ;
T_4 V_70 ;
int V_71 ;
if ( ( V_71 = F_24 ( V_54 ) ) ) {
F_5 ( V_10
L_9 ,
V_11 , F_7 ( V_54 ) ) ;
goto V_9;
}
F_25 ( V_54 ) ;
V_4 = F_26 ( sizeof( struct V_3 ) , V_72 ) ;
if ( ! V_4 ) {
F_5 ( V_10
L_10 ,
V_11 , F_7 ( V_54 ) ) ;
V_71 = - V_73 ;
goto V_74;
}
V_4 -> V_13 = V_54 ;
V_4 -> V_75 = V_69 ;
V_4 -> V_76 = F_27 ( V_4 -> V_13 , 0 ) ;
if ( ! V_4 -> V_76 ) {
F_5 ( V_10
L_11
L_4 ,
V_11 , F_7 ( V_4 -> V_13 ) ) ;
V_71 = - V_73 ;
goto V_77;
}
if ( ! F_28 ( V_4 -> V_76 , sizeof( struct V_78 ) ,
L_12 ) ) {
F_5 ( V_10
L_13
L_4 ,
V_11 , F_7 ( V_4 -> V_13 ) ) ;
V_71 = - V_73 ;
goto V_77;
}
V_4 -> V_33 = F_29 ( V_4 -> V_76 ,
sizeof( struct V_78 ) ) ;
if ( ! V_4 -> V_33 ) {
F_5 ( V_10
L_14
L_4 ,
V_11 , F_7 ( V_4 -> V_13 ) ) ;
V_71 = - V_73 ;
goto V_79;
}
V_4 -> V_80 = F_17 ( V_4 ) ;
F_5 ( V_47 L_15 , F_7 ( V_54 ) ,
V_4 -> V_80 == V_61 ? L_16 :
V_4 -> V_80 == V_65 ? L_17 :
V_4 -> V_80 == V_64 ? L_18 : L_19 ) ;
F_30 ( V_4 -> V_13 , V_81 , & V_70 ) ;
F_31 ( V_4 -> V_13 , V_81 ,
V_70 | V_82 | V_83 ) ;
F_11 ( V_4 ) ;
F_12 ( ~ 0 , & V_4 -> V_33 -> V_84 . V_28 ) ;
F_12 ( ~ 0 , & V_4 -> V_33 -> V_85 ) ;
F_12 ( ~ 0 , & V_4 -> V_33 -> V_86 . V_28 ) ;
F_12 ( ~ 0 , & V_4 -> V_33 -> V_87 ) ;
V_4 -> V_88 = NULL ;
F_32 ( V_4 -> V_13 , V_4 ) ;
F_2 ( & V_5 ) ;
F_33 ( & V_4 -> V_89 , & V_90 ) ;
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
if ( V_4 -> V_80 != V_65 ) {
F_5 ( V_47 L_21 ) ;
F_34 ( & V_91 ) ;
}
return 0 ;
V_79:
F_35 ( V_4 -> V_76 , sizeof( struct V_78 ) ) ;
V_77:
F_36 ( V_4 ) ;
V_74:
F_37 ( V_54 ) ;
V_9:
return V_71 ;
}
static void T_5
F_38 ( struct V_53 * V_54 )
{
struct V_1 * V_2 ;
struct V_3 * V_4 ;
V_4 = F_39 ( V_54 ) ;
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
F_40 ( V_4 -> V_33 ) ;
if ( ! V_4 -> V_76 ) {
F_5 ( V_10
L_23
L_24 ,
V_11 , F_7 ( V_4 -> V_13 ) ) ;
}
F_35 ( V_4 -> V_76 , sizeof( struct V_78 ) ) ;
F_37 ( V_54 ) ;
F_2 ( & V_5 ) ;
F_10 ( & V_4 -> V_89 ) ;
F_8 ( & V_5 ) ;
F_36 ( V_4 ) ;
}
static int T_6
F_41 ( void )
{
return F_42 ( & V_92 ) ;
}
static void T_7
F_43 ( void )
{
F_44 ( & V_91 ) ;
F_45 ( & V_92 ) ;
}
