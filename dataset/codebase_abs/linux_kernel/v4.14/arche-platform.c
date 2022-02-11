static inline int F_1 ( bool V_1 )
{
return 0 ;
}
static void F_2 ( struct V_2 * V_3 ,
enum V_4 V_5 )
{
V_3 -> V_5 = V_5 ;
}
static void F_3 (
struct V_2 * V_3 ,
enum V_6 V_5 )
{
V_3 -> V_7 = V_5 ;
}
static inline void F_4 ( unsigned int V_8 , bool V_9 )
{
F_5 ( V_8 , V_9 ) ;
}
static int F_6 ( struct V_10 * V_11 , void * V_12 )
{
int V_13 ;
V_13 = F_7 ( V_11 ) ;
if ( V_13 )
F_8 ( V_11 , L_1 ) ;
return 0 ;
}
static int F_9 ( struct V_10 * V_11 , void * V_12 )
{
F_10 ( V_11 ) ;
if ( F_1 ( false ) )
F_8 ( V_11 , L_2 ) ;
return 0 ;
}
static void F_11 ( struct V_2 * V_3 )
{
F_12 ( V_3 -> V_14 ) ;
F_13 ( V_3 -> V_15 ) ;
}
static T_1 F_14 ( int V_16 , void * V_17 )
{
struct V_2 * V_3 = V_17 ;
unsigned long V_18 ;
F_15 ( & V_3 -> V_19 , V_18 ) ;
if ( V_3 -> V_7 != V_20 ) {
F_16 ( & V_3 -> V_19 , V_18 ) ;
return V_21 ;
}
F_3 ( V_3 ,
V_22 ) ;
F_16 ( & V_3 -> V_19 , V_18 ) ;
F_17 ( V_3 -> V_11 , NULL , F_9 ) ;
F_17 ( V_3 -> V_11 , NULL , F_6 ) ;
if ( F_1 ( true ) )
F_8 ( V_3 -> V_11 , L_2 ) ;
F_15 ( & V_3 -> V_19 , V_18 ) ;
F_3 ( V_3 , V_23 ) ;
F_16 ( & V_3 -> V_19 , V_18 ) ;
return V_21 ;
}
static T_1 F_18 ( int V_16 , void * V_17 )
{
struct V_2 * V_3 = V_17 ;
unsigned long V_18 ;
F_15 ( & V_3 -> V_19 , V_18 ) ;
if ( F_19 ( V_3 -> V_14 ) ) {
if ( V_3 -> V_7 == V_24 ) {
if ( F_20 ( V_25 ,
V_3 -> V_26 +
F_21 ( V_27 ) ) ) {
F_3 ( V_3 ,
V_23 ) ;
} else {
if ( V_3 -> V_7 !=
V_22 ) {
F_3 ( V_3 ,
V_20 ) ;
F_16 (
& V_3 -> V_19 ,
V_18 ) ;
return V_28 ;
}
}
}
} else {
if ( V_3 -> V_7 == V_23 ) {
V_3 -> V_26 = V_25 ;
F_3 ( V_3 ,
V_24 ) ;
}
}
F_16 ( & V_3 -> V_19 , V_18 ) ;
return V_21 ;
}
static int
F_22 ( struct V_2 * V_3 )
{
int V_13 ;
if ( V_3 -> V_5 == V_29 )
return 0 ;
F_23 ( V_3 -> V_11 , L_3 ) ;
F_4 ( V_3 -> V_30 ,
V_3 -> V_31 ) ;
F_5 ( V_3 -> V_32 , 0 ) ;
F_24 ( 100 , 200 ) ;
V_13 = F_25 ( V_3 -> V_33 ) ;
if ( V_13 ) {
F_26 ( V_3 -> V_11 , L_4 ,
V_13 ) ;
return V_13 ;
}
F_4 ( V_3 -> V_30 ,
! V_3 -> V_31 ) ;
F_2 ( V_3 , V_29 ) ;
return 0 ;
}
static int
F_27 ( struct V_2 * V_3 )
{
int V_13 ;
if ( V_3 -> V_5 == V_34 )
return 0 ;
F_23 ( V_3 -> V_11 , L_5 ) ;
F_4 ( V_3 -> V_30 ,
V_3 -> V_31 ) ;
F_5 ( V_3 -> V_32 , 1 ) ;
F_24 ( 100 , 200 ) ;
V_13 = F_25 ( V_3 -> V_33 ) ;
if ( V_13 ) {
F_26 ( V_3 -> V_11 , L_4 ,
V_13 ) ;
return V_13 ;
}
F_4 ( V_3 -> V_30 ,
! V_3 -> V_31 ) ;
F_2 ( V_3 , V_34 ) ;
return 0 ;
}
static void
F_28 ( struct V_2 * V_3 )
{
unsigned long V_18 ;
if ( V_3 -> V_5 == V_35 )
return;
if ( V_3 -> V_5 != V_34 ) {
F_29 ( V_3 -> V_15 ) ;
F_15 ( & V_3 -> V_19 , V_18 ) ;
F_3 ( V_3 ,
V_23 ) ;
F_16 ( & V_3 -> V_19 , V_18 ) ;
}
F_30 ( V_3 -> V_33 ) ;
F_4 ( V_3 -> V_30 ,
V_3 -> V_31 ) ;
F_2 ( V_3 , V_35 ) ;
}
static T_2 F_31 ( struct V_10 * V_11 ,
struct V_36 * V_37 , const char * V_38 , T_3 V_39 )
{
struct V_40 * V_41 = F_32 ( V_11 ) ;
struct V_2 * V_3 = F_33 ( V_41 ) ;
int V_13 = 0 ;
F_34 ( & V_3 -> V_42 ) ;
if ( F_35 ( V_38 , L_6 ) ) {
if ( V_3 -> V_5 == V_35 )
goto exit;
F_17 ( V_3 -> V_11 , NULL , F_9 ) ;
F_28 ( V_3 ) ;
} else if ( F_35 ( V_38 , L_7 ) ) {
if ( V_3 -> V_5 == V_29 )
goto exit;
F_17 ( V_3 -> V_11 , NULL , F_9 ) ;
F_28 ( V_3 ) ;
F_11 ( V_3 ) ;
V_13 = F_22 ( V_3 ) ;
if ( V_13 )
goto exit;
} else if ( F_35 ( V_38 , L_8 ) ) {
if ( V_3 -> V_5 == V_43 )
goto exit;
F_8 ( V_3 -> V_11 , L_9 ) ;
} else if ( F_35 ( V_38 , L_10 ) ) {
if ( V_3 -> V_5 == V_34 )
goto exit;
F_28 ( V_3 ) ;
V_13 = F_27 ( V_3 ) ;
if ( V_13 )
goto exit;
} else {
F_26 ( V_3 -> V_11 , L_11 ) ;
V_13 = - V_44 ;
}
exit:
F_36 ( & V_3 -> V_42 ) ;
return V_13 ? V_13 : V_39 ;
}
static T_2 F_37 ( struct V_10 * V_11 ,
struct V_36 * V_37 , char * V_38 )
{
struct V_2 * V_3 = F_38 ( V_11 ) ;
switch ( V_3 -> V_5 ) {
case V_35 :
return sprintf ( V_38 , L_12 ) ;
case V_29 :
return sprintf ( V_38 , L_13 ) ;
case V_43 :
return sprintf ( V_38 , L_14 ) ;
case V_34 :
return sprintf ( V_38 , L_15 ) ;
default:
return sprintf ( V_38 , L_11 ) ;
}
}
static int F_39 ( struct V_45 * V_46 ,
unsigned long V_47 , void * V_1 )
{
struct V_2 * V_3 =
F_40 ( V_46 , struct V_2 ,
V_48 ) ;
int V_13 = V_49 ;
F_34 ( & V_3 -> V_42 ) ;
switch ( V_47 ) {
case V_50 :
if ( V_3 -> V_5 != V_29 ) {
V_13 = V_51 ;
break;
}
F_17 ( V_3 -> V_11 , NULL , F_9 ) ;
F_28 ( V_3 ) ;
break;
case V_52 :
if ( V_3 -> V_5 != V_35 )
break;
F_11 ( V_3 ) ;
F_22 ( V_3 ) ;
break;
default:
break;
}
F_36 ( & V_3 -> V_42 ) ;
return V_13 ;
}
static int F_41 ( struct V_40 * V_41 )
{
struct V_2 * V_3 ;
struct V_10 * V_11 = & V_41 -> V_11 ;
struct V_53 * V_54 = V_11 -> V_55 ;
int V_13 ;
V_3 = F_42 ( & V_41 -> V_11 , sizeof( * V_3 ) ,
V_56 ) ;
if ( ! V_3 )
return - V_57 ;
V_3 -> V_31 = F_43 ( V_54 ,
L_16 ) ;
V_3 -> V_30 = F_44 ( V_54 ,
L_17 ,
0 ) ;
if ( V_3 -> V_30 < 0 ) {
F_26 ( V_11 , L_18 ) ;
return V_3 -> V_30 ;
}
V_13 = F_45 ( V_11 , V_3 -> V_30 , L_19 ) ;
if ( V_13 ) {
F_26 ( V_11 , L_20 , V_13 ) ;
return V_13 ;
}
V_13 = F_46 ( V_3 -> V_30 ,
V_3 -> V_31 ) ;
if ( V_13 ) {
F_26 ( V_11 , L_21 , V_13 ) ;
return V_13 ;
}
F_2 ( V_3 , V_35 ) ;
V_3 -> V_32 = F_44 ( V_54 ,
L_22 , 0 ) ;
if ( V_3 -> V_32 < 0 ) {
F_26 ( V_11 , L_23 ) ;
return V_3 -> V_32 ;
}
V_13 = F_45 ( V_11 , V_3 -> V_32 , L_24 ) ;
if ( V_13 ) {
F_26 ( V_11 , L_25 , V_13 ) ;
return V_13 ;
}
V_13 = F_46 ( V_3 -> V_32 , 0 ) ;
if ( V_13 ) {
F_26 ( V_11 , L_21 , V_13 ) ;
return V_13 ;
}
V_3 -> V_58 = F_44 ( V_54 ,
L_26 , 0 ) ;
if ( V_3 -> V_58 < 0 ) {
F_26 ( V_11 , L_27 ) ;
return V_3 -> V_58 ;
}
V_13 = F_45 ( V_11 , V_3 -> V_58 ,
L_28 ) ;
if ( V_13 ) {
F_26 ( V_11 , L_29 , V_13 ) ;
return V_13 ;
}
V_13 = F_12 ( V_3 -> V_58 ) ;
if ( V_13 ) {
F_26 ( V_11 , L_30 , V_13 ) ;
return V_13 ;
}
V_3 -> V_33 = F_47 ( V_11 , L_31 ) ;
if ( F_48 ( V_3 -> V_33 ) ) {
V_13 = F_49 ( V_3 -> V_33 ) ;
F_26 ( V_11 , L_32 , V_13 ) ;
return V_13 ;
}
F_50 ( V_41 , V_3 ) ;
V_3 -> V_59 = F_51 ( V_54 ) ;
F_52 ( V_11 , L_33 , V_3 -> V_59 ) ;
V_3 -> V_14 = F_44 ( V_54 ,
L_34 ,
0 ) ;
if ( V_3 -> V_14 < 0 ) {
F_26 ( V_11 , L_35 ) ;
return V_3 -> V_14 ;
}
V_13 = F_45 ( V_11 , V_3 -> V_14 ,
L_36 ) ;
if ( V_13 ) {
F_26 ( V_11 , L_37 ,
V_3 -> V_14 ) ;
return V_13 ;
}
F_3 ( V_3 , V_23 ) ;
V_3 -> V_11 = & V_41 -> V_11 ;
F_53 ( & V_3 -> V_19 ) ;
F_54 ( & V_3 -> V_42 ) ;
V_3 -> V_15 =
F_55 ( V_3 -> V_14 ) ;
V_13 = F_56 ( V_11 , V_3 -> V_15 ,
F_18 ,
F_14 ,
V_60 |
V_61 | V_62 ,
F_57 ( V_11 ) , V_3 ) ;
if ( V_13 ) {
F_26 ( V_11 , L_38 , V_13 ) ;
return V_13 ;
}
F_29 ( V_3 -> V_15 ) ;
V_13 = F_58 ( V_11 , & V_63 ) ;
if ( V_13 ) {
F_26 ( V_11 , L_39 ) ;
return V_13 ;
}
V_13 = F_59 ( V_54 , NULL , NULL , V_11 ) ;
if ( V_13 ) {
F_26 ( V_11 , L_40 , V_13 ) ;
goto V_64;
}
V_3 -> V_48 . V_65 = F_39 ;
V_13 = F_60 ( & V_3 -> V_48 ) ;
if ( V_13 ) {
F_26 ( V_11 , L_41 , V_13 ) ;
goto V_64;
}
if ( ! F_43 ( V_41 -> V_11 . V_55 , L_42 ) ) {
F_34 ( & V_3 -> V_42 ) ;
V_13 = F_22 ( V_3 ) ;
if ( V_13 ) {
F_26 ( V_11 , L_43 , V_13 ) ;
goto V_66;
}
F_11 ( V_3 ) ;
F_36 ( & V_3 -> V_42 ) ;
}
F_23 ( V_11 , L_44 ) ;
return 0 ;
V_66:
F_36 ( & V_3 -> V_42 ) ;
V_64:
F_61 ( & V_41 -> V_11 , & V_63 ) ;
return V_13 ;
}
static int F_62 ( struct V_10 * V_11 , void * V_1 )
{
struct V_40 * V_41 = F_32 ( V_11 ) ;
F_63 ( V_41 ) ;
return 0 ;
}
static int F_64 ( struct V_40 * V_41 )
{
struct V_2 * V_3 = F_33 ( V_41 ) ;
F_65 ( & V_3 -> V_48 ) ;
F_61 ( & V_41 -> V_11 , & V_63 ) ;
F_17 ( & V_41 -> V_11 , NULL , F_62 ) ;
F_28 ( V_3 ) ;
if ( F_1 ( false ) )
F_8 ( V_3 -> V_11 , L_2 ) ;
return 0 ;
}
static T_4 int F_66 ( struct V_10 * V_11 )
{
return 0 ;
}
static T_4 int F_67 ( struct V_10 * V_11 )
{
return 0 ;
}
static void F_68 ( struct V_40 * V_41 )
{
struct V_2 * V_3 = F_33 ( V_41 ) ;
F_28 ( V_3 ) ;
F_1 ( false ) ;
}
static int T_5 F_69 ( void )
{
int V_67 ;
V_67 = F_70 ( & V_68 ) ;
if ( V_67 )
return V_67 ;
V_67 = F_71 () ;
if ( V_67 )
F_72 ( & V_68 ) ;
return V_67 ;
}
static void T_6 F_73 ( void )
{
F_74 () ;
F_72 ( & V_68 ) ;
}
