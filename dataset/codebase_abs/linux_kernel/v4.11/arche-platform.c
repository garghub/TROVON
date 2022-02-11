static int F_1 ( struct V_1 * V_2 , void * V_3 )
{
F_2 ( V_2 ) ;
return 0 ;
}
static int F_3 ( struct V_1 * V_2 , void * V_3 )
{
F_4 ( V_2 ) ;
return 0 ;
}
static void F_5 ( struct V_4 * V_5 ,
enum V_6 V_7 )
{
V_5 -> V_7 = V_7 ;
}
int F_6 ( enum V_6 V_7 ,
struct V_8 * V_9 )
{
struct V_4 * V_5 ;
struct V_10 * V_11 ;
struct V_12 * V_13 ;
int V_14 = - V_15 ;
unsigned long V_16 ;
V_13 = F_7 ( NULL , NULL , L_1 ) ;
if ( ! V_13 ) {
F_8 ( L_2 ) ;
return - V_17 ;
}
V_11 = F_9 ( V_13 ) ;
if ( ! V_11 ) {
F_8 ( L_3 ) ;
F_10 ( V_13 ) ;
return - V_17 ;
}
V_5 = F_11 ( V_11 ) ;
F_12 ( & V_5 -> V_18 ) ;
F_13 ( & V_5 -> V_19 , V_16 ) ;
if ( V_5 -> V_7 == V_7 ) {
V_14 = 0 ;
goto exit;
}
switch ( V_7 ) {
case V_20 :
if ( V_5 -> V_7 != V_21 ) {
V_14 = - V_22 ;
goto exit;
}
if ( V_5 -> V_23 != V_24 ) {
F_14 ( V_5 -> V_2 ,
L_4 ) ;
goto exit;
}
F_15 ( V_5 -> V_2 , NULL ,
F_1 ) ;
V_5 -> V_23 = V_25 ;
break;
case V_21 :
if ( V_5 -> V_7 != V_20 ) {
V_14 = - V_22 ;
goto exit;
}
F_15 ( V_5 -> V_2 , NULL ,
F_3 ) ;
V_5 -> V_23 = V_24 ;
break;
case V_26 :
case V_27 :
case V_28 :
F_14 ( V_5 -> V_2 , L_5 ) ;
goto exit;
default:
V_14 = - V_22 ;
F_14 ( V_5 -> V_2 ,
L_6 ) ;
goto exit;
}
V_5 -> V_9 = V_9 ;
F_5 ( V_5 , V_7 ) ;
if ( V_7 == V_21 )
F_16 ( & V_5 -> V_29 ) ;
V_14 = 0 ;
exit:
F_17 ( & V_5 -> V_19 , V_16 ) ;
F_18 ( & V_5 -> V_18 ) ;
F_19 ( & V_11 -> V_2 ) ;
F_10 ( V_13 ) ;
return V_14 ;
}
static void F_20 (
struct V_4 * V_5 ,
enum V_30 V_7 )
{
V_5 -> V_23 = V_7 ;
}
static inline void F_21 ( unsigned int V_31 , bool V_32 )
{
F_22 ( V_31 , V_32 ) ;
}
static int F_23 ( struct V_1 * V_2 , void * V_3 )
{
int V_14 ;
V_14 = F_24 ( V_2 ) ;
if ( V_14 )
F_25 ( V_2 , L_7 ) ;
return 0 ;
}
static int F_26 ( struct V_1 * V_2 , void * V_3 )
{
F_27 ( V_2 ) ;
if ( F_28 ( false ) )
F_25 ( V_2 , L_8 ) ;
return 0 ;
}
static void F_29 ( struct V_4 * V_5 )
{
F_30 ( V_5 -> V_33 ) ;
F_31 ( V_5 -> V_34 ) ;
}
static T_1 F_32 ( int V_35 , void * V_36 )
{
struct V_4 * V_5 = V_36 ;
unsigned long V_16 ;
F_13 ( & V_5 -> V_19 , V_16 ) ;
if ( V_5 -> V_23 != V_37 ) {
F_17 ( & V_5 -> V_19 , V_16 ) ;
return V_38 ;
}
F_20 ( V_5 ,
V_39 ) ;
F_17 ( & V_5 -> V_19 , V_16 ) ;
F_15 ( V_5 -> V_2 , NULL , F_26 ) ;
F_15 ( V_5 -> V_2 , NULL , F_23 ) ;
if ( F_28 ( true ) )
F_25 ( V_5 -> V_2 , L_8 ) ;
F_13 ( & V_5 -> V_19 , V_16 ) ;
F_20 ( V_5 , V_24 ) ;
F_17 ( & V_5 -> V_19 , V_16 ) ;
return V_38 ;
}
static T_1 F_33 ( int V_35 , void * V_36 )
{
struct V_4 * V_5 = V_36 ;
unsigned long V_16 ;
F_13 ( & V_5 -> V_19 , V_16 ) ;
if ( V_5 -> V_23 == V_25 ) {
F_34 ( V_5 -> V_9 ) ;
goto exit;
}
if ( F_35 ( V_5 -> V_33 ) ) {
if ( V_5 -> V_23 == V_40 ) {
if ( F_36 ( V_41 ,
V_5 -> V_42 +
F_37 ( V_43 ) ) ) {
F_20 ( V_5 ,
V_24 ) ;
} else {
if ( V_5 -> V_23 !=
V_39 ) {
F_20 ( V_5 ,
V_37 ) ;
F_17 (
& V_5 -> V_19 ,
V_16 ) ;
return V_44 ;
}
}
}
} else {
if ( V_5 -> V_23 == V_24 ) {
V_5 -> V_42 = V_41 ;
F_20 ( V_5 ,
V_40 ) ;
}
}
exit:
F_17 ( & V_5 -> V_19 , V_16 ) ;
return V_38 ;
}
static int
F_38 ( struct V_4 * V_5 )
{
int V_14 ;
if ( V_5 -> V_7 == V_21 )
return 0 ;
F_39 ( V_5 -> V_2 , L_9 ) ;
F_21 ( V_5 -> V_45 ,
V_5 -> V_46 ) ;
F_22 ( V_5 -> V_47 , 0 ) ;
F_40 ( 100 , 200 ) ;
V_14 = F_41 ( V_5 -> V_48 ) ;
if ( V_14 ) {
F_14 ( V_5 -> V_2 , L_10 ,
V_14 ) ;
return V_14 ;
}
F_21 ( V_5 -> V_45 ,
! V_5 -> V_46 ) ;
F_5 ( V_5 , V_21 ) ;
return 0 ;
}
static int
F_42 ( struct V_4 * V_5 )
{
int V_14 ;
if ( V_5 -> V_7 == V_28 )
return 0 ;
F_39 ( V_5 -> V_2 , L_11 ) ;
F_21 ( V_5 -> V_45 ,
V_5 -> V_46 ) ;
F_22 ( V_5 -> V_47 , 1 ) ;
F_40 ( 100 , 200 ) ;
V_14 = F_41 ( V_5 -> V_48 ) ;
if ( V_14 ) {
F_14 ( V_5 -> V_2 , L_10 ,
V_14 ) ;
return V_14 ;
}
F_21 ( V_5 -> V_45 ,
! V_5 -> V_46 ) ;
F_5 ( V_5 , V_28 ) ;
return 0 ;
}
static void
F_43 ( struct V_4 * V_5 )
{
unsigned long V_16 ;
if ( V_5 -> V_7 == V_26 )
return;
if ( V_5 -> V_7 != V_28 ) {
F_44 ( V_5 -> V_34 ) ;
F_13 ( & V_5 -> V_19 , V_16 ) ;
F_20 ( V_5 ,
V_24 ) ;
F_17 ( & V_5 -> V_19 , V_16 ) ;
}
F_45 ( V_5 -> V_48 ) ;
F_21 ( V_5 -> V_45 ,
V_5 -> V_46 ) ;
F_5 ( V_5 , V_26 ) ;
}
static T_2 F_46 ( struct V_1 * V_2 ,
struct V_49 * V_50 , const char * V_51 , T_3 V_52 )
{
struct V_10 * V_11 = F_47 ( V_2 ) ;
struct V_4 * V_5 = F_11 ( V_11 ) ;
int V_14 = 0 ;
V_53:
F_12 ( & V_5 -> V_18 ) ;
if ( V_5 -> V_7 == V_20 ) {
F_18 ( & V_5 -> V_18 ) ;
V_14 = F_48 (
V_5 -> V_29 ,
V_5 -> V_7 != V_20 ) ;
if ( V_14 )
return V_14 ;
goto V_53;
}
if ( F_49 ( V_51 , L_12 ) ) {
if ( V_5 -> V_7 == V_26 )
goto exit;
F_15 ( V_5 -> V_2 , NULL , F_26 ) ;
F_43 ( V_5 ) ;
} else if ( F_49 ( V_51 , L_13 ) ) {
if ( V_5 -> V_7 == V_21 )
goto exit;
F_15 ( V_5 -> V_2 , NULL , F_26 ) ;
F_43 ( V_5 ) ;
F_29 ( V_5 ) ;
V_14 = F_38 ( V_5 ) ;
if ( V_14 )
goto exit;
} else if ( F_49 ( V_51 , L_14 ) ) {
if ( V_5 -> V_7 == V_27 )
goto exit;
F_25 ( V_5 -> V_2 , L_15 ) ;
} else if ( F_49 ( V_51 , L_16 ) ) {
if ( V_5 -> V_7 == V_28 )
goto exit;
F_43 ( V_5 ) ;
V_14 = F_42 ( V_5 ) ;
if ( V_14 )
goto exit;
} else {
F_14 ( V_5 -> V_2 , L_17 ) ;
V_14 = - V_22 ;
}
exit:
F_18 ( & V_5 -> V_18 ) ;
return V_14 ? V_14 : V_52 ;
}
static T_2 F_50 ( struct V_1 * V_2 ,
struct V_49 * V_50 , char * V_51 )
{
struct V_4 * V_5 = F_51 ( V_2 ) ;
switch ( V_5 -> V_7 ) {
case V_26 :
return sprintf ( V_51 , L_18 ) ;
case V_21 :
return sprintf ( V_51 , L_19 ) ;
case V_27 :
return sprintf ( V_51 , L_20 ) ;
case V_28 :
return sprintf ( V_51 , L_21 ) ;
case V_20 :
return sprintf ( V_51 , L_22 ) ;
default:
return sprintf ( V_51 , L_17 ) ;
}
}
static int F_52 ( struct V_54 * V_55 ,
unsigned long V_56 , void * V_57 )
{
struct V_4 * V_5 =
F_53 ( V_55 , struct V_4 ,
V_58 ) ;
int V_14 = V_59 ;
F_12 ( & V_5 -> V_18 ) ;
switch ( V_56 ) {
case V_60 :
if ( V_5 -> V_7 != V_21 ) {
V_14 = V_61 ;
break;
}
F_15 ( V_5 -> V_2 , NULL , F_26 ) ;
F_43 ( V_5 ) ;
break;
case V_62 :
if ( V_5 -> V_7 != V_26 )
break;
F_29 ( V_5 ) ;
F_38 ( V_5 ) ;
break;
default:
break;
}
F_18 ( & V_5 -> V_18 ) ;
return V_14 ;
}
static int F_54 ( struct V_10 * V_11 )
{
struct V_4 * V_5 ;
struct V_1 * V_2 = & V_11 -> V_2 ;
struct V_12 * V_13 = V_2 -> V_63 ;
int V_14 ;
V_5 = F_55 ( & V_11 -> V_2 , sizeof( * V_5 ) ,
V_64 ) ;
if ( ! V_5 )
return - V_65 ;
V_5 -> V_46 = F_56 ( V_13 ,
L_23 ) ;
V_5 -> V_45 = F_57 ( V_13 ,
L_24 ,
0 ) ;
if ( V_5 -> V_45 < 0 ) {
F_14 ( V_2 , L_25 ) ;
return V_5 -> V_45 ;
}
V_14 = F_58 ( V_2 , V_5 -> V_45 , L_26 ) ;
if ( V_14 ) {
F_14 ( V_2 , L_27 , V_14 ) ;
return V_14 ;
}
V_14 = F_59 ( V_5 -> V_45 ,
V_5 -> V_46 ) ;
if ( V_14 ) {
F_14 ( V_2 , L_28 , V_14 ) ;
return V_14 ;
}
F_5 ( V_5 , V_26 ) ;
V_5 -> V_47 = F_57 ( V_13 ,
L_29 , 0 ) ;
if ( V_5 -> V_47 < 0 ) {
F_14 ( V_2 , L_30 ) ;
return V_5 -> V_47 ;
}
V_14 = F_58 ( V_2 , V_5 -> V_47 , L_31 ) ;
if ( V_14 ) {
F_14 ( V_2 , L_32 , V_14 ) ;
return V_14 ;
}
V_14 = F_59 ( V_5 -> V_47 , 0 ) ;
if ( V_14 ) {
F_14 ( V_2 , L_28 , V_14 ) ;
return V_14 ;
}
V_5 -> V_66 = F_57 ( V_13 ,
L_33 , 0 ) ;
if ( V_5 -> V_66 < 0 ) {
F_14 ( V_2 , L_34 ) ;
return V_5 -> V_66 ;
}
V_14 = F_58 ( V_2 , V_5 -> V_66 ,
L_35 ) ;
if ( V_14 ) {
F_14 ( V_2 , L_36 , V_14 ) ;
return V_14 ;
}
V_14 = F_30 ( V_5 -> V_66 ) ;
if ( V_14 ) {
F_14 ( V_2 , L_37 , V_14 ) ;
return V_14 ;
}
V_5 -> V_48 = F_60 ( V_2 , L_38 ) ;
if ( F_61 ( V_5 -> V_48 ) ) {
V_14 = F_62 ( V_5 -> V_48 ) ;
F_14 ( V_2 , L_39 , V_14 ) ;
return V_14 ;
}
F_63 ( V_11 , V_5 ) ;
V_5 -> V_67 = F_64 ( V_13 ) ;
F_65 ( V_2 , L_40 , V_5 -> V_67 ) ;
V_5 -> V_33 = F_57 ( V_13 ,
L_41 ,
0 ) ;
if ( V_5 -> V_33 < 0 ) {
F_14 ( V_2 , L_42 ) ;
return V_5 -> V_33 ;
}
V_14 = F_58 ( V_2 , V_5 -> V_33 ,
L_43 ) ;
if ( V_14 ) {
F_14 ( V_2 , L_44 ,
V_5 -> V_33 ) ;
return V_14 ;
}
F_20 ( V_5 , V_24 ) ;
V_5 -> V_2 = & V_11 -> V_2 ;
F_66 ( & V_5 -> V_19 ) ;
F_67 ( & V_5 -> V_18 ) ;
F_68 ( & V_5 -> V_29 ) ;
V_5 -> V_34 =
F_69 ( V_5 -> V_33 ) ;
V_14 = F_70 ( V_2 , V_5 -> V_34 ,
F_33 ,
F_32 ,
V_68 |
V_69 | V_70 ,
F_71 ( V_2 ) , V_5 ) ;
if ( V_14 ) {
F_14 ( V_2 , L_45 , V_14 ) ;
return V_14 ;
}
F_44 ( V_5 -> V_34 ) ;
V_14 = F_72 ( V_2 , & V_71 ) ;
if ( V_14 ) {
F_14 ( V_2 , L_46 ) ;
return V_14 ;
}
V_14 = F_73 ( V_13 , NULL , NULL , V_2 ) ;
if ( V_14 ) {
F_14 ( V_2 , L_47 , V_14 ) ;
goto V_72;
}
V_5 -> V_58 . V_73 = F_52 ;
V_14 = F_74 ( & V_5 -> V_58 ) ;
if ( V_14 ) {
F_14 ( V_2 , L_48 , V_14 ) ;
goto V_72;
}
V_74 = F_6 ;
if ( ! F_56 ( V_11 -> V_2 . V_63 , L_49 ) ) {
F_12 ( & V_5 -> V_18 ) ;
V_14 = F_38 ( V_5 ) ;
if ( V_14 ) {
F_14 ( V_2 , L_50 , V_14 ) ;
goto V_75;
}
F_29 ( V_5 ) ;
F_18 ( & V_5 -> V_18 ) ;
}
F_39 ( V_2 , L_51 ) ;
return 0 ;
V_75:
F_18 ( & V_5 -> V_18 ) ;
V_72:
F_75 ( & V_11 -> V_2 , & V_71 ) ;
return V_14 ;
}
static int F_76 ( struct V_1 * V_2 , void * V_57 )
{
struct V_10 * V_11 = F_47 ( V_2 ) ;
F_77 ( V_11 ) ;
return 0 ;
}
static int F_78 ( struct V_10 * V_11 )
{
struct V_4 * V_5 = F_11 ( V_11 ) ;
F_79 ( & V_5 -> V_58 ) ;
F_75 ( & V_11 -> V_2 , & V_71 ) ;
F_15 ( & V_11 -> V_2 , NULL , F_76 ) ;
F_43 ( V_5 ) ;
F_63 ( V_11 , NULL ) ;
if ( F_28 ( false ) )
F_25 ( V_5 -> V_2 , L_8 ) ;
return 0 ;
}
static int F_80 ( struct V_1 * V_2 )
{
return 0 ;
}
static int F_81 ( struct V_1 * V_2 )
{
return 0 ;
}
static void F_82 ( struct V_10 * V_11 )
{
struct V_4 * V_5 = F_11 ( V_11 ) ;
F_43 ( V_5 ) ;
F_28 ( false ) ;
}
static int T_4 F_83 ( void )
{
int V_76 ;
V_76 = F_84 ( & V_77 ) ;
if ( V_76 )
return V_76 ;
V_76 = F_85 () ;
if ( V_76 )
F_86 ( & V_77 ) ;
return V_76 ;
}
static void T_5 F_87 ( void )
{
F_88 () ;
F_86 ( & V_77 ) ;
}
