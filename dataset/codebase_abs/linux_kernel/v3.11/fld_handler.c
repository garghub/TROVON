static int T_1 F_1 ( void )
{
V_1 = F_2 ( V_2 ,
V_3 ,
NULL , NULL ) ;
if ( F_3 ( V_1 ) )
return F_4 ( V_1 ) ;
F_5 ( & V_4 ) ;
F_6 ( & V_4 ) ;
return 0 ;
}
static void T_2 F_7 ( void )
{
F_8 ( & V_4 ) ;
if ( V_1 != NULL && ! F_3 ( V_1 ) ) {
F_9 ( & V_1 ) ;
V_1 = NULL ;
}
}
int F_10 ( const struct V_5 * V_6 ,
struct V_7 * V_8 ,
struct V_9 * V_10 ,
struct V_11 * V_12 )
{
int V_13 ;
V_13 = F_11 ( V_6 , V_8 , V_10 , V_12 ) ;
RETURN ( V_13 ) ;
}
int F_12 ( const struct V_5 * V_6 , struct V_7 * V_8 ,
struct V_9 * V_10 , struct V_11 * V_12 )
{
int V_13 ;
F_13 ( & V_8 -> V_14 ) ;
V_13 = F_14 ( V_6 , V_8 , V_10 , V_12 ) ;
F_15 ( & V_8 -> V_14 ) ;
RETURN ( V_13 ) ;
}
int F_16 ( const struct V_5 * V_6 , struct V_7 * V_8 ,
T_3 V_15 , struct V_9 * V_10 )
{
struct V_9 * V_16 ;
struct V_17 * V_18 ;
int V_13 ;
V_19 ;
V_18 = F_17 ( & V_6 -> V_20 , & V_4 ) ;
F_18 ( V_18 != NULL ) ;
V_16 = & V_18 -> V_21 ;
V_13 = F_19 ( V_8 -> V_22 , V_15 , V_16 ) ;
if ( V_13 == 0 ) {
if ( F_20 ( F_21 ( V_16 ) != F_21 ( V_10 ) &&
! F_22 ( V_10 ) ) ) {
F_23 ( L_1 V_23 L_2
L_3 , V_8 -> V_24 ,
F_24 ( V_16 ) , V_10 -> V_25 , - V_26 ) ;
RETURN ( - V_26 ) ;
}
* V_10 = * V_16 ;
RETURN ( 0 ) ;
}
if ( V_8 -> V_27 ) {
F_23 ( L_4 V_28 L_5 ,
V_8 -> V_24 , V_15 , - V_26 ) ;
RETURN ( - V_26 ) ;
} else {
F_18 ( V_8 -> V_29 ) ;
V_10 -> V_30 = V_15 ;
V_13 = F_25 ( V_8 -> V_29 ,
V_10 , V_31 ) ;
if ( V_13 == 0 )
F_26 ( V_8 -> V_22 , V_10 ) ;
}
RETURN ( V_13 ) ;
}
static int F_27 ( struct V_7 * V_8 ,
const struct V_5 * V_6 ,
T_4 V_32 , struct V_9 * V_10 ,
struct V_17 * V_18 )
{
int V_13 ;
V_19 ;
switch ( V_32 ) {
case V_31 :
V_13 = F_16 ( V_6 , V_8 , V_10 -> V_30 , V_10 ) ;
break;
default:
V_13 = - V_33 ;
break;
}
F_28 ( V_34 , L_6
V_23 L_7 , V_8 -> V_24 , V_13 , V_32 , F_24 ( V_10 ) ) ;
RETURN ( V_13 ) ;
}
static int F_29 ( struct V_35 * V_36 ,
struct V_17 * V_18 )
{
struct V_37 * exp = V_36 -> V_38 ;
struct V_39 * V_40 = exp -> V_41 -> V_42 -> V_43 ;
struct V_9 * V_44 ;
struct V_9 * V_45 ;
int V_13 ;
T_4 * V_32 ;
V_19 ;
V_13 = F_30 ( V_18 -> V_46 ) ;
if ( V_13 )
RETURN ( F_31 ( V_13 ) ) ;
V_32 = F_32 ( V_18 -> V_46 , & V_47 ) ;
if ( V_32 != NULL ) {
V_44 = F_32 ( V_18 -> V_46 , & V_48 ) ;
if ( V_44 == NULL )
RETURN ( F_31 ( - V_49 ) ) ;
V_45 = F_33 ( V_18 -> V_46 , & V_48 ) ;
if ( V_45 == NULL )
RETURN ( F_31 ( - V_49 ) ) ;
* V_45 = * V_44 ;
if ( ! ( F_34 ( exp ) & V_50 ) &&
! ( F_34 ( exp ) & V_51 ) &&
! ( F_34 ( exp ) & V_52 ) &&
! exp -> V_53 )
F_35 ( V_45 ) ;
V_13 = F_27 ( F_36 ( V_40 ) -> V_54 ,
V_36 -> V_55 -> V_56 ,
* V_32 , V_45 , V_18 ) ;
} else {
V_13 = F_31 ( - V_49 ) ;
}
RETURN ( V_13 ) ;
}
static void F_37 ( struct V_35 * V_36 ,
struct V_17 * V_18 )
{
V_18 -> V_46 = & V_36 -> V_57 ;
F_38 ( V_18 -> V_46 , V_36 , V_58 ) ;
F_39 ( V_18 -> V_46 , & V_59 ) ;
}
static void F_40 ( struct V_17 * V_18 )
{
F_41 ( V_18 -> V_46 ) ;
}
static int F_42 ( struct V_35 * V_36 )
{
struct V_17 * V_18 ;
const struct V_5 * V_6 ;
int V_13 ;
V_6 = V_36 -> V_55 -> V_56 ;
F_18 ( V_6 != NULL ) ;
V_18 = F_17 ( & V_6 -> V_20 , & V_4 ) ;
F_18 ( V_18 != NULL ) ;
F_37 ( V_36 , V_18 ) ;
V_13 = F_29 ( V_36 , V_18 ) ;
F_40 ( V_18 ) ;
return V_13 ;
}
int F_43 ( struct V_60 * V_18 )
{
return F_42 ( V_18 -> V_61 -> V_62 ) ;
}
int F_44 ( const struct V_5 * V_6 ,
struct V_39 * V_40 , const struct V_63 * V_64 )
{
int V_65 ;
struct V_66 * V_67 ;
struct V_9 * V_10 ;
struct V_17 * V_18 ;
V_19 ;
V_18 = F_17 ( & V_6 -> V_20 , & V_4 ) ;
V_10 = & V_18 -> V_21 ;
V_65 = 1 ;
V_67 = F_36 ( V_40 ) ;
if ( V_67 -> V_68 != NULL ) {
int V_13 ;
V_13 = F_19 ( V_67 -> V_68 -> V_69 ,
F_45 ( V_64 ) , V_10 ) ;
if ( V_13 == 0 )
V_65 = ( V_10 -> V_70 == V_67 -> V_71 ) ;
}
return V_65 ;
}
static int F_46 ( struct V_7 * V_8 )
{
int V_13 = 0 ;
V_19 ;
V_8 -> V_72 = F_2 ( V_8 -> V_24 ,
V_1 ,
V_73 , V_8 ) ;
if ( F_3 ( V_8 -> V_72 ) ) {
V_13 = F_4 ( V_8 -> V_72 ) ;
RETURN ( V_13 ) ;
}
V_13 = F_47 ( V_8 -> V_72 , L_8 , 0444 ,
& V_74 , V_8 ) ;
if ( V_13 ) {
F_9 ( & V_8 -> V_72 ) ;
V_8 -> V_72 = NULL ;
}
RETURN ( V_13 ) ;
}
static void F_48 ( struct V_7 * V_8 )
{
V_19 ;
if ( V_8 -> V_72 != NULL ) {
if ( ! F_3 ( V_8 -> V_72 ) )
F_9 ( & V_8 -> V_72 ) ;
V_8 -> V_72 = NULL ;
}
EXIT ;
}
static int F_46 ( struct V_7 * V_8 )
{
return 0 ;
}
static void F_48 ( struct V_7 * V_8 )
{
return;
}
int F_49 ( const struct V_5 * V_6 , struct V_7 * V_8 ,
struct V_75 * V_76 , const char * V_77 , int V_78 ,
int type )
{
int V_79 , V_80 ;
int V_13 ;
V_19 ;
snprintf ( V_8 -> V_24 , sizeof( V_8 -> V_24 ) ,
L_9 , V_77 ) ;
V_79 = V_81 /
sizeof( struct V_82 ) ;
V_80 = V_79 *
V_83 / 100 ;
F_50 ( & V_8 -> V_14 ) ;
V_8 -> V_22 = F_51 ( V_8 -> V_24 ,
V_79 , V_80 ) ;
if ( F_3 ( V_8 -> V_22 ) ) {
V_13 = F_4 ( V_8 -> V_22 ) ;
V_8 -> V_22 = NULL ;
GOTO ( V_45 , V_13 ) ;
}
if ( ! V_78 && type == V_84 ) {
V_13 = F_52 ( V_6 , V_8 , V_76 ) ;
if ( V_13 )
GOTO ( V_45 , V_13 ) ;
} else {
V_8 -> V_27 = NULL ;
}
V_13 = F_46 ( V_8 ) ;
if ( V_13 )
GOTO ( V_45 , V_13 ) ;
V_8 -> V_29 = NULL ;
GOTO ( V_45 , V_13 ) ;
V_45:
if ( V_13 )
F_53 ( V_6 , V_8 ) ;
return V_13 ;
}
void F_53 ( const struct V_5 * V_6 , struct V_7 * V_8 )
{
V_19 ;
F_48 ( V_8 ) ;
F_54 ( V_6 , V_8 ) ;
if ( V_8 -> V_22 != NULL ) {
if ( ! F_3 ( V_8 -> V_22 ) )
F_55 ( V_8 -> V_22 ) ;
V_8 -> V_22 = NULL ;
}
EXIT ;
}
