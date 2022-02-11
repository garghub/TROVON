static inline struct V_1 * F_1 ( struct V_2 * V_3 )
{
return F_2 ( F_3 ( V_3 ) ) ;
}
int F_4 ( struct V_2 * V_3 , int V_4 , T_1 V_5 )
{
struct V_1 * V_1 = F_1 ( V_3 ) ;
return F_5 ( V_1 -> V_6 , V_4 , V_5 ) ;
}
int F_6 ( struct V_2 * V_3 , int V_4 , int V_7 , T_1 * V_5 )
{
struct V_1 * V_1 = F_1 ( V_3 ) ;
return F_7 ( V_1 -> V_6 , V_4 , V_5 , V_7 ) ;
}
int F_8 ( struct V_2 * V_3 , int V_4 , T_1 * V_5 )
{
struct V_1 * V_1 = F_1 ( V_3 ) ;
unsigned int V_8 ;
int V_9 ;
V_9 = F_9 ( V_1 -> V_6 , V_4 , & V_8 ) ;
if ( ! V_9 )
* V_5 = V_8 ;
return V_9 ;
}
int F_10 ( struct V_2 * V_3 , int V_4 , int V_7 , T_1 * V_5 )
{
struct V_1 * V_1 = F_1 ( V_3 ) ;
return F_11 ( V_1 -> V_6 , V_4 , V_5 , V_7 ) ;
}
int F_12 ( struct V_2 * V_3 , int V_4 , T_1 V_10 )
{
struct V_1 * V_1 = F_1 ( V_3 ) ;
return F_13 ( V_1 -> V_6 , V_4 , V_10 , V_10 ) ;
}
int F_14 ( struct V_2 * V_3 , int V_4 , T_1 V_10 )
{
struct V_1 * V_1 = F_1 ( V_3 ) ;
return F_13 ( V_1 -> V_6 , V_4 , V_10 , 0 ) ;
}
int F_15 ( struct V_2 * V_3 , int V_4 , T_1 V_5 , T_1 V_11 )
{
struct V_1 * V_1 = F_1 ( V_3 ) ;
return F_13 ( V_1 -> V_6 , V_4 , V_11 , V_5 ) ;
}
int F_16 ( struct V_2 * V_3 , int V_12 )
{
struct V_1 * V_1 = F_1 ( V_3 ) ;
return F_17 ( V_1 -> V_13 , V_12 ) ;
}
int F_18 ( struct V_2 * V_3 )
{
struct V_1 * V_1 = F_19 ( V_3 ) ;
return V_1 -> V_14 ;
}
static int F_20 ( struct V_2 * V_3 , void * V_15 )
{
F_21 ( F_22 ( V_3 ) ) ;
return 0 ;
}
static int F_23 ( struct V_1 * V_1 )
{
return F_24 ( V_1 -> V_3 , NULL , F_20 ) ;
}
static void F_25 ( struct V_16 * V_17 )
{
struct V_1 * V_1 = F_26 ( V_17 ) ;
F_27 ( & V_1 -> V_18 ) ;
}
static void F_28 ( struct V_16 * V_16 )
{
struct V_1 * V_1 = F_26 ( V_16 ) ;
unsigned int V_19 = V_16 -> V_20 ;
const struct V_21 * V_17 = & V_22 [ V_19 ] ;
V_1 -> V_23 [ V_17 -> V_23 ] &= ~ V_17 -> V_24 ;
V_1 -> V_25 |= ( 1 << V_19 ) ;
}
static void F_29 ( struct V_16 * V_16 )
{
struct V_1 * V_1 = F_26 ( V_16 ) ;
unsigned int V_19 = V_16 -> V_20 ;
const struct V_21 * V_17 = & V_22 [ V_19 ] ;
V_1 -> V_23 [ V_17 -> V_23 ] |= V_17 -> V_24 ;
V_1 -> V_25 &= ~ ( 1 << V_19 ) ;
}
static void F_30 ( struct V_16 * V_17 )
{
struct V_1 * V_1 = F_26 ( V_17 ) ;
int V_26 ;
for ( V_26 = 0 ; V_26 < F_31 ( V_1 -> V_23 ) ; V_26 ++ ) {
int V_9 ;
V_9 = F_4 ( V_1 -> V_3 ,
V_27 + V_26 ,
V_1 -> V_23 [ V_26 ] ) ;
F_32 ( V_9 ) ;
}
F_33 ( & V_1 -> V_18 ) ;
}
static int F_34 ( struct V_16 * V_16 , unsigned int V_28 )
{
struct V_1 * V_1 = F_26 ( V_16 ) ;
return F_35 ( V_1 -> V_12 , V_28 ) ;
}
static int F_36 ( struct V_13 * V_29 , unsigned int V_30 ,
T_2 V_31 )
{
struct V_1 * V_1 = V_29 -> V_32 ;
F_37 ( V_30 , V_1 ) ;
F_38 ( V_30 , & V_33 , V_34 ) ;
F_39 ( V_30 , 1 ) ;
#ifdef F_40
F_41 ( V_30 , V_35 ) ;
#else
F_42 ( V_30 ) ;
#endif
return 0 ;
}
static T_3 F_43 ( int V_12 , void * V_17 )
{
struct V_1 * V_1 = V_17 ;
T_4 V_36 ;
int V_9 = 0 ;
V_9 = F_10 ( V_1 -> V_3 , V_37 ,
sizeof( V_36 ) , ( T_1 * ) & V_36 ) ;
if ( V_9 < 0 ) {
F_44 ( V_1 -> V_3 , L_1 ) ;
return V_38 ;
}
V_36 = F_45 ( V_36 ) ;
while ( V_36 ) {
int V_26 = F_46 ( V_36 ) ;
if ( V_1 -> V_25 & ( 1 << V_26 ) )
F_47 (
F_48 ( V_1 -> V_13 , V_26 ) ) ;
V_36 &= ~ ( 1 << V_26 ) ;
}
return V_39 ;
}
static int F_49 ( struct V_1 * V_1 , int V_12 ,
int V_40 )
{
int V_26 , V_9 ;
T_5 V_41 [ 4 ] ;
int V_42 ;
int V_43 = F_31 ( V_22 ) ;
V_1 -> V_12 = V_12 ;
F_50 ( & V_1 -> V_18 ) ;
for ( V_26 = 0 ; V_26 < 5 ; V_26 ++ ) {
V_1 -> V_23 [ V_26 ] = 0xff ;
F_4 ( V_1 -> V_3 , V_27 + V_26 , 0xff ) ;
}
F_10 ( V_1 -> V_3 , V_37 , sizeof( V_41 ) , V_41 ) ;
if ( V_40 > 0 ) {
V_42 = F_51 ( V_40 , 0 , V_43 , - 1 ) ;
if ( V_42 < 0 ) {
F_44 ( V_1 -> V_3 ,
L_2 , V_42 ) ;
return V_42 ;
}
} else {
V_42 = 0 ;
}
V_1 -> V_13 = F_52 ( V_1 -> V_3 -> V_44 ,
V_43 , V_42 , & V_45 ,
V_1 ) ;
if ( ! V_1 -> V_13 ) {
F_44 ( V_1 -> V_3 , L_3 ) ;
return - V_46 ;
}
V_9 = F_53 ( V_12 , NULL , F_43 , V_47 ,
L_4 , V_1 ) ;
if ( ! V_9 )
F_54 ( V_1 -> V_3 , 1 ) ;
return V_9 ;
}
static int F_55 ( struct V_1 * V_1 ,
struct V_48 * V_49 )
{
struct V_50 * V_51 ;
struct V_52 * V_53 ;
int V_26 , V_9 = 0 ;
for ( V_26 = 0 ; V_26 < V_49 -> V_54 ; V_26 ++ ) {
V_51 = & V_49 -> V_55 [ V_26 ] ;
V_53 = F_56 ( V_51 -> V_56 , V_51 -> V_57 ) ;
if ( ! V_53 ) {
V_9 = - V_46 ;
goto V_58;
}
V_53 -> V_3 . V_59 = V_1 -> V_3 ;
V_53 -> V_3 . V_60 = V_51 -> V_60 ;
V_53 -> V_3 . V_44 = V_51 -> V_44 ;
V_9 = F_57 ( V_53 ) ;
if ( V_9 ) {
F_58 ( V_53 ) ;
goto V_58;
}
}
return 0 ;
V_58:
F_23 ( V_1 ) ;
return V_9 ;
}
static struct V_48 * F_59 ( struct V_61 * V_62 )
{
struct V_63 * V_64 = V_62 -> V_3 . V_44 ;
struct V_48 * V_49 ;
V_49 = F_60 ( & V_62 -> V_3 , sizeof( * V_49 ) , V_65 ) ;
if ( ! V_49 ) {
F_44 ( & V_62 -> V_3 , L_5 ) ;
return NULL ;
}
V_49 -> V_54 = 0 ;
V_49 -> V_55 = NULL ;
V_49 -> V_66 = - 1 ;
V_49 -> V_40 = - 1 ;
V_49 -> V_67 = F_61 ( V_64 , L_6 ) ;
return V_49 ;
}
static struct V_48 * F_59 ( struct V_61 * V_62 )
{
return NULL ;
}
static bool F_62 ( struct V_2 * V_3 , unsigned int V_4 )
{
if ( ( V_4 >= V_27 ) && ( V_4 <= V_68 ) )
return false ;
return true ;
}
static void F_63 ( void )
{
if ( F_14 ( V_69 , V_70 , V_71 ) )
return;
F_12 ( V_69 , V_70 , V_72 ) ;
}
static void F_64 ( struct V_61 * V_62 , int V_14 )
{
const char * V_56 ;
switch ( V_14 ) {
case V_73 :
V_56 = L_7 ;
break;
case V_74 :
V_56 = L_8 ;
break;
case V_75 :
V_56 = L_9 ;
break;
case V_76 :
V_56 = L_10 ;
break;
default:
V_56 = L_11 ;
break;
}
F_65 ( & V_62 -> V_3 , L_12 , V_56 , V_14 ) ;
}
static int F_66 ( struct V_61 * V_62 ,
const struct V_77 * V_57 )
{
struct V_48 * V_49 = F_67 ( & V_62 -> V_3 ) ;
struct V_1 * V_1 ;
int V_9 ;
int V_14 ;
if ( ! V_49 && V_62 -> V_3 . V_44 )
V_49 = F_59 ( V_62 ) ;
if ( ! V_49 ) {
F_44 ( & V_62 -> V_3 , L_13 ) ;
return - V_78 ;
}
V_14 = F_68 ( V_62 , V_79 ) ;
if ( V_14 < 0 ) {
F_44 ( & V_62 -> V_3 , L_14 , V_14 ) ;
return - V_80 ;
}
V_1 = F_60 ( & V_62 -> V_3 , sizeof( * V_1 ) , V_65 ) ;
if ( ! V_1 )
return - V_46 ;
V_1 -> V_14 = V_14 ;
F_64 ( V_62 , V_1 -> V_14 ) ;
V_1 -> V_62 = V_62 ;
V_1 -> V_3 = & V_62 -> V_3 ;
F_69 ( V_62 , V_1 ) ;
V_1 -> V_6 = F_70 ( V_62 ,
& V_81 ) ;
if ( F_71 ( V_1 -> V_6 ) ) {
V_9 = F_72 ( V_1 -> V_6 ) ;
F_44 ( & V_62 -> V_3 , L_15 , V_9 ) ;
return V_9 ;
}
if ( V_62 -> V_12 ) {
V_9 = F_49 ( V_1 , V_62 -> V_12 ,
V_49 -> V_40 ) ;
if ( V_9 ) {
F_44 ( & V_62 -> V_3 , L_16 , V_9 ) ;
return V_9 ;
}
}
V_9 = F_73 ( V_1 -> V_3 , - 1 ,
V_82 , F_31 ( V_82 ) ,
NULL , 0 , V_1 -> V_13 ) ;
if ( V_9 < 0 ) {
F_44 ( & V_62 -> V_3 , L_17 , V_9 ) ;
goto V_83;
}
V_9 = F_55 ( V_1 , V_49 ) ;
if ( V_9 ) {
F_44 ( & V_62 -> V_3 , L_18 , V_9 ) ;
goto V_84;
}
if ( V_49 -> V_67 && ! V_85 ) {
V_69 = & V_62 -> V_3 ;
V_85 = F_63 ;
}
return 0 ;
V_84:
F_74 ( V_1 -> V_3 ) ;
V_83:
if ( V_62 -> V_12 )
F_75 ( V_62 -> V_12 , V_1 ) ;
return V_9 ;
}
static int F_76 ( struct V_61 * V_62 )
{
struct V_1 * V_1 = F_2 ( V_62 ) ;
F_23 ( V_1 ) ;
F_74 ( V_1 -> V_3 ) ;
if ( V_62 -> V_12 )
F_75 ( V_62 -> V_12 , V_1 ) ;
return 0 ;
}
static int T_6 F_77 ( void )
{
return F_78 ( & V_86 ) ;
}
static void T_7 F_79 ( void )
{
F_80 ( & V_86 ) ;
}
