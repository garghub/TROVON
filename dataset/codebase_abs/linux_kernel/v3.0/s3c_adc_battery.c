static void F_1 ( struct V_1 * V_2 )
{
F_2 ( & V_3 ,
F_3 ( V_4 ) ) ;
}
static int F_4 ( struct V_1 * V_2 ,
enum V_5 V_6 ,
union V_7 * V_8 )
{
struct V_9 * V_10 = F_5 ( V_2 , struct V_9 , V_2 ) ;
if ( ! V_10 ) {
F_6 ( V_2 -> V_11 , L_1 , V_12 ) ;
return - V_13 ;
}
if ( V_10 -> V_14 < 0 ||
F_7 ( V_15 - V_10 -> V_16 ) >
V_17 ) {
V_10 -> V_14 = F_8 ( V_10 -> V_18 ,
V_10 -> V_19 -> V_20 ) ;
V_10 -> V_14 *= V_10 -> V_19 -> V_21 ;
V_10 -> V_16 = V_15 ;
}
switch ( V_6 ) {
case V_22 :
V_8 -> V_23 = V_10 -> V_14 ;
return 0 ;
case V_24 :
V_8 -> V_23 = V_10 -> V_19 -> V_25 ;
return 0 ;
case V_26 :
V_8 -> V_23 = V_10 -> V_19 -> V_27 ;
return 0 ;
default:
return - V_13 ;
}
}
static int F_9 ( int V_28 , int V_29 , int V_30 )
{
return V_28 + V_29 * V_30 / 1000 ;
}
static int F_10 ( struct V_9 * V_10 )
{
return V_10 -> V_19 -> V_31 ?
! F_11 ( V_10 -> V_19 -> V_32 ) :
F_11 ( V_10 -> V_19 -> V_32 ) ;
}
static int F_12 ( struct V_1 * V_2 ,
enum V_5 V_6 ,
union V_7 * V_8 )
{
struct V_9 * V_10 = F_5 ( V_2 , struct V_9 , V_2 ) ;
int V_33 ;
int V_34 ;
const struct V_35 * V_36 = V_10 -> V_19 -> V_37 ;
unsigned int V_38 = V_10 -> V_19 -> V_39 ;
if ( ! V_10 ) {
F_6 ( V_2 -> V_11 , L_2 ) ;
return - V_13 ;
}
if ( V_10 -> V_14 < 0 || V_10 -> V_40 < 0 ||
F_7 ( V_15 - V_10 -> V_16 ) >
V_17 ) {
V_10 -> V_14 = F_8 ( V_10 -> V_18 ,
V_10 -> V_19 -> V_41 ) * V_10 -> V_19 -> V_42 ;
V_10 -> V_40 = F_8 ( V_10 -> V_18 ,
V_10 -> V_19 -> V_43 ) * V_10 -> V_19 -> V_44 ;
V_10 -> V_16 = V_15 ;
}
if ( V_10 -> V_45 &&
( ( V_10 -> V_19 -> V_32 < 0 ) ||
! F_10 ( V_10 ) ) ) {
V_36 = V_10 -> V_19 -> V_46 ;
V_38 = V_10 -> V_19 -> V_47 ;
}
V_33 = 100000 ;
V_34 = F_9 ( ( V_10 -> V_14 / 1000 ) ,
( V_10 -> V_40 / 1000 ) , V_10 -> V_19 -> V_48 ) ;
if ( V_34 < F_9 ( V_36 -> V_49 , V_36 -> V_50 ,
V_10 -> V_19 -> V_48 ) ) {
V_38 -- ;
while ( V_38 -- ) {
int V_51 ;
int V_52 ;
V_51 = F_9 ( V_36 [ 0 ] . V_49 , V_36 [ 0 ] . V_50 ,
V_10 -> V_19 -> V_48 ) ;
V_52 = F_9 ( V_36 [ 1 ] . V_49 , V_36 [ 1 ] . V_50 ,
V_10 -> V_19 -> V_48 ) ;
if ( V_34 < V_51 && V_34 >= V_52 ) {
V_33 = ( V_36 [ 1 ] . V_53 +
( V_36 [ 0 ] . V_53 - V_36 [ 1 ] . V_53 ) *
( V_34 - V_52 ) /
( V_51 - V_52 ) ) * 1000 ;
break;
}
V_33 = V_36 [ 1 ] . V_53 * 1000 ;
V_36 ++ ;
}
}
V_10 -> V_53 = V_33 ;
switch ( V_6 ) {
case V_54 :
if ( V_10 -> V_19 -> V_32 < 0 )
V_8 -> V_23 = V_10 -> V_53 == 100000 ?
V_55 : V_10 -> V_56 ;
else
V_8 -> V_23 = V_10 -> V_56 ;
return 0 ;
case V_57 :
V_8 -> V_23 = 100000 ;
return 0 ;
case V_58 :
V_8 -> V_23 = 0 ;
return 0 ;
case V_59 :
V_8 -> V_23 = V_10 -> V_53 ;
return 0 ;
case V_22 :
V_8 -> V_23 = V_10 -> V_14 ;
return 0 ;
case V_60 :
V_8 -> V_23 = V_10 -> V_40 ;
return 0 ;
default:
return - V_13 ;
}
}
static void F_13 ( struct V_61 * V_62 )
{
struct V_9 * V_10 = & V_63 ;
int V_64 ;
int V_65 ;
static int V_66 ;
V_65 = F_14 ( & V_10 -> V_2 ) ;
V_10 -> V_45 = V_65 ;
if ( V_65 != V_66 ) {
V_66 = V_65 ;
if ( V_65 ) {
if ( V_10 -> V_19 -> V_67 )
V_10 -> V_19 -> V_67 () ;
V_10 -> V_56 = V_68 ;
} else {
if ( V_10 -> V_19 -> V_69 )
V_10 -> V_19 -> V_69 () ;
V_10 -> V_56 = V_70 ;
}
} else {
if ( ( V_10 -> V_19 -> V_32 >= 0 ) && V_65 ) {
V_64 = F_10 ( & V_63 ) ;
if ( V_64 ) {
if ( V_10 -> V_19 -> V_69 )
V_10 -> V_19 -> V_69 () ;
V_10 -> V_56 = V_55 ;
} else {
if ( V_10 -> V_19 -> V_67 )
V_10 -> V_19 -> V_67 () ;
V_10 -> V_56 = V_68 ;
}
}
}
F_15 ( & V_10 -> V_2 ) ;
}
static T_1 F_16 ( int V_71 , void * V_72 )
{
F_2 ( & V_3 ,
F_3 ( V_4 ) ) ;
return V_73 ;
}
static int T_2 F_17 ( struct V_74 * V_75 )
{
struct V_76 * V_18 ;
struct V_77 * V_19 = V_75 -> V_11 . V_78 ;
int V_79 ;
V_18 = F_18 ( V_75 , NULL , NULL , 0 ) ;
if ( F_19 ( V_18 ) ) {
F_6 ( & V_75 -> V_11 , L_3 ) ;
return F_20 ( V_18 ) ;
}
F_21 ( V_75 , V_18 ) ;
V_63 . V_18 = V_18 ;
V_63 . V_19 = V_19 ;
V_63 . V_14 = - 1 ;
V_63 . V_40 = - 1 ;
V_63 . V_45 = 0 ;
V_63 . V_56 = V_70 ;
V_79 = F_22 ( & V_75 -> V_11 , & V_63 . V_2 ) ;
if ( V_79 )
goto V_80;
if ( V_19 -> V_21 ) {
V_81 . V_18 = V_18 ;
V_81 . V_19 = V_75 -> V_11 . V_78 ;
V_81 . V_14 = - 1 ;
V_79 = F_22 ( & V_75 -> V_11 , & V_81 . V_2 ) ;
if ( V_79 )
goto V_82;
}
F_23 ( & V_3 , F_13 ) ;
if ( V_19 -> V_32 >= 0 ) {
V_79 = F_24 ( V_19 -> V_32 , L_4 ) ;
if ( V_79 )
goto V_83;
V_79 = F_25 ( F_26 ( V_19 -> V_32 ) ,
F_16 ,
V_84 | V_85 ,
L_5 , NULL ) ;
if ( V_79 )
goto V_86;
}
if ( V_19 -> V_87 ) {
V_79 = V_19 -> V_87 () ;
if ( V_79 )
goto V_88;
}
F_27 ( & V_75 -> V_11 , L_6 ) ;
F_28 ( & V_75 -> V_11 , 1 ) ;
F_2 ( & V_3 ,
F_3 ( V_4 ) ) ;
return 0 ;
V_88:
if ( V_19 -> V_32 >= 0 )
F_29 ( F_26 ( V_19 -> V_32 ) , NULL ) ;
V_86:
if ( V_19 -> V_32 >= 0 )
F_30 ( V_19 -> V_32 ) ;
V_83:
if ( V_19 -> V_21 )
F_31 ( & V_81 . V_2 ) ;
V_82:
F_31 ( & V_63 . V_2 ) ;
V_80:
return V_79 ;
}
static int F_32 ( struct V_74 * V_75 )
{
struct V_76 * V_18 = F_33 ( V_75 ) ;
struct V_77 * V_19 = V_75 -> V_11 . V_78 ;
F_31 ( & V_63 . V_2 ) ;
if ( V_19 -> V_21 )
F_31 ( & V_81 . V_2 ) ;
F_34 ( V_18 ) ;
if ( V_19 -> V_32 >= 0 ) {
F_29 ( F_26 ( V_19 -> V_32 ) , NULL ) ;
F_30 ( V_19 -> V_32 ) ;
}
F_35 ( & V_3 ) ;
if ( V_19 -> exit )
V_19 -> exit () ;
return 0 ;
}
static int F_36 ( struct V_74 * V_75 ,
T_3 V_89 )
{
struct V_77 * V_19 = V_75 -> V_11 . V_78 ;
if ( V_19 -> V_32 >= 0 ) {
if ( F_37 ( & V_75 -> V_11 ) )
F_38 (
F_26 ( V_19 -> V_32 ) ) ;
else {
F_39 ( F_26 ( V_19 -> V_32 ) ) ;
V_63 . V_19 -> V_69 () ;
}
}
return 0 ;
}
static int F_40 ( struct V_74 * V_75 )
{
struct V_77 * V_19 = V_75 -> V_11 . V_78 ;
if ( V_19 -> V_32 >= 0 ) {
if ( F_37 ( & V_75 -> V_11 ) )
F_41 (
F_26 ( V_19 -> V_32 ) ) ;
else
F_42 ( F_26 ( V_19 -> V_32 ) ) ;
}
F_2 ( & V_3 ,
F_3 ( V_4 ) ) ;
return 0 ;
}
static int T_2 F_43 ( void )
{
return F_44 ( & V_90 ) ;
}
static void T_4 F_45 ( void )
{
F_46 ( & V_90 ) ;
}
