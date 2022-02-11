static int T_1 F_1 ( char * V_1 )
{
if ( ! strncmp ( V_1 , L_1 , 6 ) ) {
V_2 = true ;
} else if ( ! strncmp ( V_1 , L_2 , 6 ) ) {
V_2 = false ;
V_3 = false ;
} else if ( ! strncmp ( V_1 , L_3 , 4 ) ) {
V_2 = false ;
V_3 = true ;
}
return 1 ;
}
void F_2 ( struct V_4 * V_5 )
{
F_3 ( V_5 , V_6 , V_7 ) ;
}
static int F_4 ( struct V_4 * V_5 )
{
int V_8 ;
V_8 = F_5 ( V_5 ) ;
if ( V_8 )
return V_8 ;
F_6 ( V_5 ) ;
return 0 ;
}
static int F_7 ( struct V_9 * V_5 )
{
struct V_4 * V_10 = F_8 ( V_5 ) ;
if ( F_9 ( V_10 ) == V_11 )
F_2 ( V_10 ) ;
return 0 ;
}
static int F_10 ( struct V_4 * V_10 , void * V_12 )
{
struct V_13 * V_14 = V_12 ;
V_14 -> V_15 = F_11 (unsigned int, pdev->d3cold_delay,
info->d3cold_delay) ;
if ( V_10 -> V_16 )
V_14 -> V_16 = true ;
return 0 ;
}
static int F_12 ( struct V_9 * V_5 )
{
struct V_4 * V_10 = F_8 ( V_5 ) ;
struct V_13 V_13 = {
. V_16 = false ,
. V_15 = V_17 ,
} ;
F_13 ( V_10 -> V_18 , F_10 , & V_13 ) ;
V_10 -> V_16 = V_13 . V_16 ;
V_10 -> V_15 = V_13 . V_15 ;
return 0 ;
}
static int F_14 ( struct V_9 * V_5 )
{
return 0 ;
}
static int F_15 ( struct V_9 * V_5 )
{
F_16 ( V_5 , 10 ) ;
return - V_19 ;
}
static int T_2 F_17 ( struct V_4 * V_5 ,
const struct V_20 * V_21 )
{
int V_22 ;
if ( ! F_18 ( V_5 ) ||
( ( F_9 ( V_5 ) != V_11 ) &&
( F_9 ( V_5 ) != V_23 ) &&
( F_9 ( V_5 ) != V_24 ) ) )
return - V_25 ;
if ( ! V_5 -> V_26 && V_5 -> V_27 ) {
F_19 ( & V_5 -> V_5 , L_4
L_5 , V_5 -> V_28 , V_5 -> V_9 ) ;
}
V_22 = F_20 ( V_5 ) ;
if ( V_22 )
return V_22 ;
F_21 ( V_5 ) ;
V_5 -> V_29 = false ;
if ( ! F_22 ( V_30 , V_5 ) )
F_23 ( & V_5 -> V_5 ) ;
return 0 ;
}
static void F_24 ( struct V_4 * V_5 )
{
if ( ! F_22 ( V_30 , V_5 ) )
F_25 ( & V_5 -> V_5 ) ;
F_26 ( V_5 ) ;
F_27 ( V_5 ) ;
}
static int F_28 ( struct V_9 * V_9 , void * V_12 )
{
struct V_31 * V_31 ;
struct V_32 * V_33 ;
struct V_34 * V_35 ;
T_3 V_22 ;
V_35 = (struct V_34 * ) V_12 ;
if ( V_9 -> V_36 == & V_37 && V_9 -> V_33 ) {
V_33 = F_29 ( V_9 -> V_33 ) ;
if ( ! V_33 ||
! V_33 -> V_38 ||
! V_33 -> V_38 -> V_39 )
return 0 ;
V_31 = F_30 ( V_9 ) ;
V_22 = V_33 -> V_38 -> V_39 (
V_31 -> V_40 ,
V_35 -> V_41 ) ;
V_35 -> V_42 =
F_31 ( V_35 -> V_42 , V_22 ) ;
}
return 0 ;
}
static T_3 F_32 ( struct V_4 * V_5 ,
enum V_43 error )
{
struct V_34 V_12 = { error , V_44 } ;
int V_45 ;
V_45 = F_33 ( & V_5 -> V_5 , & V_12 , F_28 ) ;
return V_12 . V_42 ;
}
static int F_34 ( struct V_9 * V_9 , void * V_12 )
{
struct V_31 * V_31 ;
struct V_32 * V_33 ;
T_3 V_22 , * V_42 ;
V_42 = ( T_3 * ) V_12 ;
if ( V_9 -> V_36 == & V_37 && V_9 -> V_33 ) {
V_33 = F_29 ( V_9 -> V_33 ) ;
if ( V_33 &&
V_33 -> V_38 &&
V_33 -> V_38 -> V_46 ) {
V_31 = F_30 ( V_9 ) ;
V_22 = V_33 -> V_38 -> V_46 (
V_31 -> V_40 ) ;
* V_42 = F_31 ( * V_42 , V_22 ) ;
}
}
return 0 ;
}
static T_3 F_35 ( struct V_4 * V_5 )
{
T_3 V_22 = V_47 ;
int V_8 ;
V_8 = F_33 ( & V_5 -> V_5 , & V_22 , F_34 ) ;
return V_22 ;
}
static int F_36 ( struct V_9 * V_9 , void * V_12 )
{
struct V_31 * V_31 ;
struct V_32 * V_33 ;
T_3 V_22 , * V_42 ;
V_42 = ( T_3 * ) V_12 ;
if ( V_9 -> V_36 == & V_37 && V_9 -> V_33 ) {
V_33 = F_29 ( V_9 -> V_33 ) ;
if ( V_33 &&
V_33 -> V_38 &&
V_33 -> V_38 -> V_48 ) {
V_31 = F_30 ( V_9 ) ;
V_22 = V_33 -> V_38 -> V_48 (
V_31 -> V_40 ) ;
* V_42 = F_31 ( * V_42 , V_22 ) ;
}
}
return 0 ;
}
static T_3 F_37 ( struct V_4 * V_5 )
{
T_3 V_22 = V_47 ;
int V_8 ;
if ( V_5 -> V_49 == V_50 ) {
V_5 -> V_51 = true ;
F_38 ( V_5 ) ;
F_4 ( V_5 ) ;
F_39 ( V_5 ) ;
}
V_8 = F_33 ( & V_5 -> V_5 , & V_22 , F_36 ) ;
return V_22 ;
}
static int F_40 ( struct V_9 * V_9 , void * V_12 )
{
struct V_31 * V_31 ;
struct V_32 * V_33 ;
if ( V_9 -> V_36 == & V_37 && V_9 -> V_33 ) {
V_33 = F_29 ( V_9 -> V_33 ) ;
if ( V_33 &&
V_33 -> V_38 &&
V_33 -> V_38 -> V_52 ) {
V_31 = F_30 ( V_9 ) ;
V_33 -> V_38 -> V_52 ( V_31 -> V_40 ) ;
}
}
return 0 ;
}
static void F_41 ( struct V_4 * V_5 )
{
int V_8 ;
V_8 = F_33 ( & V_5 -> V_5 , NULL , F_40 ) ;
}
static int T_1 F_42 ( const struct V_53 * V_54 )
{
F_43 ( L_6 ,
V_54 -> V_55 ) ;
F_44 () ;
return 0 ;
}
static int T_1 F_45 ( void )
{
int V_8 ;
if ( V_2 )
return F_46 ( & V_56 ) ;
F_47 ( V_57 ) ;
V_8 = F_48 () ;
if ( V_8 ) {
F_49 ( V_58 L_7 , V_8 ) ;
goto V_59;
}
V_8 = F_46 ( & V_56 ) ;
if ( V_8 )
F_50 () ;
V_59:
return V_8 ;
}
