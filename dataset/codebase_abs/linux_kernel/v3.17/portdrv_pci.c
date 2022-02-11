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
V_23 = F_20 ( V_5 ) ;
if ( V_23 )
return V_23 ;
F_21 ( V_5 ) ;
V_5 -> V_27 = false ;
return 0 ;
}
static void F_22 ( struct V_4 * V_5 )
{
F_23 ( V_5 ) ;
}
static int F_24 ( struct V_9 * V_9 , void * V_12 )
{
struct V_28 * V_28 ;
struct V_29 * V_30 ;
struct V_31 * V_32 ;
T_2 V_23 ;
V_32 = (struct V_31 * ) V_12 ;
if ( V_9 -> V_33 == & V_34 && V_9 -> V_30 ) {
V_30 = F_25 ( V_9 -> V_30 ) ;
if ( ! V_30 ||
! V_30 -> V_35 ||
! V_30 -> V_35 -> V_36 )
return 0 ;
V_28 = F_26 ( V_9 ) ;
V_23 = V_30 -> V_35 -> V_36 (
V_28 -> V_37 ,
V_32 -> V_38 ) ;
V_32 -> V_39 =
F_27 ( V_32 -> V_39 , V_23 ) ;
}
return 0 ;
}
static T_2 F_28 ( struct V_4 * V_5 ,
enum V_40 error )
{
struct V_31 V_12 = { error , V_41 } ;
F_29 ( & V_5 -> V_5 , & V_12 , F_24 ) ;
return V_12 . V_39 ;
}
static int F_30 ( struct V_9 * V_9 , void * V_12 )
{
struct V_28 * V_28 ;
struct V_29 * V_30 ;
T_2 V_23 , * V_39 ;
V_39 = ( T_2 * ) V_12 ;
if ( V_9 -> V_33 == & V_34 && V_9 -> V_30 ) {
V_30 = F_25 ( V_9 -> V_30 ) ;
if ( V_30 &&
V_30 -> V_35 &&
V_30 -> V_35 -> V_42 ) {
V_28 = F_26 ( V_9 ) ;
V_23 = V_30 -> V_35 -> V_42 (
V_28 -> V_37 ) ;
* V_39 = F_27 ( * V_39 , V_23 ) ;
}
}
return 0 ;
}
static T_2 F_31 ( struct V_4 * V_5 )
{
T_2 V_23 = V_43 ;
F_29 ( & V_5 -> V_5 , & V_23 , F_30 ) ;
return V_23 ;
}
static int F_32 ( struct V_9 * V_9 , void * V_12 )
{
struct V_28 * V_28 ;
struct V_29 * V_30 ;
T_2 V_23 , * V_39 ;
V_39 = ( T_2 * ) V_12 ;
if ( V_9 -> V_33 == & V_34 && V_9 -> V_30 ) {
V_30 = F_25 ( V_9 -> V_30 ) ;
if ( V_30 &&
V_30 -> V_35 &&
V_30 -> V_35 -> V_44 ) {
V_28 = F_26 ( V_9 ) ;
V_23 = V_30 -> V_35 -> V_44 (
V_28 -> V_37 ) ;
* V_39 = F_27 ( * V_39 , V_23 ) ;
}
}
return 0 ;
}
static T_2 F_33 ( struct V_4 * V_5 )
{
T_2 V_23 = V_43 ;
if ( V_5 -> V_45 == V_46 ) {
V_5 -> V_47 = true ;
F_34 ( V_5 ) ;
F_4 ( V_5 ) ;
F_35 ( V_5 ) ;
}
F_29 ( & V_5 -> V_5 , & V_23 , F_32 ) ;
return V_23 ;
}
static int F_36 ( struct V_9 * V_9 , void * V_12 )
{
struct V_28 * V_28 ;
struct V_29 * V_30 ;
if ( V_9 -> V_33 == & V_34 && V_9 -> V_30 ) {
V_30 = F_25 ( V_9 -> V_30 ) ;
if ( V_30 &&
V_30 -> V_35 &&
V_30 -> V_35 -> V_48 ) {
V_28 = F_26 ( V_9 ) ;
V_30 -> V_35 -> V_48 ( V_28 -> V_37 ) ;
}
}
return 0 ;
}
static void F_37 ( struct V_4 * V_5 )
{
F_29 ( & V_5 -> V_5 , NULL , F_36 ) ;
}
static int T_1 F_38 ( const struct V_49 * V_50 )
{
F_39 ( L_4 ,
V_50 -> V_51 ) ;
F_40 () ;
return 0 ;
}
static int T_1 F_41 ( void )
{
int V_8 ;
if ( V_2 )
return F_42 ( & V_52 ) ;
F_43 ( V_53 ) ;
V_8 = F_44 () ;
if ( V_8 ) {
F_45 ( V_54 L_5 , V_8 ) ;
goto V_55;
}
V_8 = F_42 ( & V_52 ) ;
if ( V_8 )
F_46 () ;
V_55:
return V_8 ;
}
