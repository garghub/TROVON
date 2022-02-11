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
static int F_15 ( struct V_4 * V_10 , void * V_12 )
{
bool * V_19 = V_12 ;
if ( V_10 -> V_19 )
* V_19 = true ;
return 0 ;
}
static int F_16 ( struct V_9 * V_5 )
{
struct V_4 * V_10 = F_8 ( V_5 ) ;
bool V_19 = false ;
F_13 ( V_10 -> V_18 , F_15 , & V_19 ) ;
if ( ! V_19 )
F_17 ( V_5 , 10 ) ;
return - V_20 ;
}
static int F_18 ( struct V_4 * V_5 ,
const struct V_21 * V_22 )
{
int V_23 ;
if ( ! F_19 ( V_5 ) ||
( ( F_9 ( V_5 ) != V_11 ) &&
( F_9 ( V_5 ) != V_24 ) &&
( F_9 ( V_5 ) != V_25 ) ) )
return - V_26 ;
if ( ! V_5 -> V_27 && V_5 -> V_28 ) {
F_20 ( & V_5 -> V_5 , L_4
L_5 , V_5 -> V_29 , V_5 -> V_9 ) ;
}
V_23 = F_21 ( V_5 ) ;
if ( V_23 )
return V_23 ;
F_22 ( V_5 ) ;
V_5 -> V_30 = false ;
if ( ! F_23 ( V_31 , V_5 ) )
F_24 ( & V_5 -> V_5 ) ;
return 0 ;
}
static void F_25 ( struct V_4 * V_5 )
{
if ( ! F_23 ( V_31 , V_5 ) )
F_26 ( & V_5 -> V_5 ) ;
F_27 ( V_5 ) ;
F_28 ( V_5 ) ;
}
static int F_29 ( struct V_9 * V_9 , void * V_12 )
{
struct V_32 * V_32 ;
struct V_33 * V_34 ;
struct V_35 * V_36 ;
T_2 V_23 ;
V_36 = (struct V_35 * ) V_12 ;
if ( V_9 -> V_37 == & V_38 && V_9 -> V_34 ) {
V_34 = F_30 ( V_9 -> V_34 ) ;
if ( ! V_34 ||
! V_34 -> V_39 ||
! V_34 -> V_39 -> V_40 )
return 0 ;
V_32 = F_31 ( V_9 ) ;
V_23 = V_34 -> V_39 -> V_40 (
V_32 -> V_41 ,
V_36 -> V_42 ) ;
V_36 -> V_43 =
F_32 ( V_36 -> V_43 , V_23 ) ;
}
return 0 ;
}
static T_2 F_33 ( struct V_4 * V_5 ,
enum V_44 error )
{
struct V_35 V_12 = { error , V_45 } ;
int V_46 ;
V_46 = F_34 ( & V_5 -> V_5 , & V_12 , F_29 ) ;
return V_12 . V_43 ;
}
static int F_35 ( struct V_9 * V_9 , void * V_12 )
{
struct V_32 * V_32 ;
struct V_33 * V_34 ;
T_2 V_23 , * V_43 ;
V_43 = ( T_2 * ) V_12 ;
if ( V_9 -> V_37 == & V_38 && V_9 -> V_34 ) {
V_34 = F_30 ( V_9 -> V_34 ) ;
if ( V_34 &&
V_34 -> V_39 &&
V_34 -> V_39 -> V_47 ) {
V_32 = F_31 ( V_9 ) ;
V_23 = V_34 -> V_39 -> V_47 (
V_32 -> V_41 ) ;
* V_43 = F_32 ( * V_43 , V_23 ) ;
}
}
return 0 ;
}
static T_2 F_36 ( struct V_4 * V_5 )
{
T_2 V_23 = V_48 ;
int V_8 ;
V_8 = F_34 ( & V_5 -> V_5 , & V_23 , F_35 ) ;
return V_23 ;
}
static int F_37 ( struct V_9 * V_9 , void * V_12 )
{
struct V_32 * V_32 ;
struct V_33 * V_34 ;
T_2 V_23 , * V_43 ;
V_43 = ( T_2 * ) V_12 ;
if ( V_9 -> V_37 == & V_38 && V_9 -> V_34 ) {
V_34 = F_30 ( V_9 -> V_34 ) ;
if ( V_34 &&
V_34 -> V_39 &&
V_34 -> V_39 -> V_49 ) {
V_32 = F_31 ( V_9 ) ;
V_23 = V_34 -> V_39 -> V_49 (
V_32 -> V_41 ) ;
* V_43 = F_32 ( * V_43 , V_23 ) ;
}
}
return 0 ;
}
static T_2 F_38 ( struct V_4 * V_5 )
{
T_2 V_23 = V_48 ;
int V_8 ;
if ( V_5 -> V_50 == V_51 ) {
V_5 -> V_52 = true ;
F_39 ( V_5 ) ;
F_4 ( V_5 ) ;
F_40 ( V_5 ) ;
}
V_8 = F_34 ( & V_5 -> V_5 , & V_23 , F_37 ) ;
return V_23 ;
}
static int F_41 ( struct V_9 * V_9 , void * V_12 )
{
struct V_32 * V_32 ;
struct V_33 * V_34 ;
if ( V_9 -> V_37 == & V_38 && V_9 -> V_34 ) {
V_34 = F_30 ( V_9 -> V_34 ) ;
if ( V_34 &&
V_34 -> V_39 &&
V_34 -> V_39 -> V_53 ) {
V_32 = F_31 ( V_9 ) ;
V_34 -> V_39 -> V_53 ( V_32 -> V_41 ) ;
}
}
return 0 ;
}
static void F_42 ( struct V_4 * V_5 )
{
int V_8 ;
V_8 = F_34 ( & V_5 -> V_5 , NULL , F_41 ) ;
}
static int T_1 F_43 ( const struct V_54 * V_55 )
{
F_44 ( L_6 ,
V_55 -> V_56 ) ;
F_45 () ;
return 0 ;
}
static int T_1 F_46 ( void )
{
int V_8 ;
if ( V_2 )
return F_47 ( & V_57 ) ;
F_48 ( V_58 ) ;
V_8 = F_49 () ;
if ( V_8 ) {
F_50 ( V_59 L_7 , V_8 ) ;
goto V_60;
}
V_8 = F_47 ( & V_57 ) ;
if ( V_8 )
F_51 () ;
V_60:
return V_8 ;
}
