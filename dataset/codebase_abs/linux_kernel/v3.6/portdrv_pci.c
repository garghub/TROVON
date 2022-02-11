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
int V_6 ;
T_2 V_7 ;
V_6 = F_3 ( V_5 ) + V_8 ;
F_4 ( V_5 , V_6 , & V_7 ) ;
V_7 |= V_9 ;
F_5 ( V_5 , V_6 , V_7 ) ;
}
static int F_6 ( struct V_4 * V_5 )
{
int V_10 ;
V_10 = F_7 ( V_5 ) ;
if ( V_10 )
return V_10 ;
F_8 ( V_5 ) ;
return 0 ;
}
static int F_9 ( struct V_11 * V_5 )
{
struct V_4 * V_12 = F_10 ( V_5 ) ;
if( V_12 -> V_13 == V_14 )
F_2 ( V_12 ) ;
return 0 ;
}
static int F_11 ( struct V_4 * V_12 , void * V_15 )
{
struct V_16 * V_17 = V_15 ;
V_17 -> V_18 = F_12 (unsigned int, pdev->d3cold_delay,
info->d3cold_delay) ;
if ( V_12 -> V_19 )
V_17 -> V_19 = true ;
return 0 ;
}
static int F_13 ( struct V_11 * V_5 )
{
struct V_4 * V_12 = F_10 ( V_5 ) ;
struct V_16 V_16 = {
. V_19 = false ,
. V_18 = V_20 ,
} ;
F_14 ( V_12 -> V_21 , F_11 , & V_16 ) ;
V_12 -> V_19 = V_16 . V_19 ;
V_12 -> V_18 = V_16 . V_18 ;
return 0 ;
}
static int F_15 ( struct V_11 * V_5 )
{
return 0 ;
}
static int F_16 ( struct V_11 * V_5 )
{
F_17 ( V_5 , 10 ) ;
return - V_22 ;
}
static int T_3 F_18 ( struct V_4 * V_5 ,
const struct V_23 * V_24 )
{
int V_25 ;
if ( ! F_19 ( V_5 ) ||
( ( V_5 -> V_13 != V_14 ) &&
( V_5 -> V_13 != V_26 ) &&
( V_5 -> V_13 != V_27 ) ) )
return - V_28 ;
if ( ! V_5 -> V_29 && V_5 -> V_30 ) {
F_20 ( & V_5 -> V_5 , L_4
L_5 , V_5 -> V_31 , V_5 -> V_11 ) ;
}
V_25 = F_21 ( V_5 ) ;
if ( V_25 )
return V_25 ;
F_22 ( V_5 ) ;
V_5 -> V_32 = false ;
if ( ! F_23 ( V_33 , V_5 ) )
F_24 ( & V_5 -> V_5 ) ;
return 0 ;
}
static void F_25 ( struct V_4 * V_5 )
{
if ( ! F_23 ( V_33 , V_5 ) )
F_26 ( & V_5 -> V_5 ) ;
F_27 ( V_5 ) ;
F_28 ( V_5 ) ;
}
static int F_29 ( struct V_11 * V_11 , void * V_15 )
{
struct V_34 * V_34 ;
struct V_35 * V_36 ;
struct V_37 * V_38 ;
T_4 V_25 ;
V_38 = (struct V_37 * ) V_15 ;
if ( V_11 -> V_39 == & V_40 && V_11 -> V_36 ) {
V_36 = F_30 ( V_11 -> V_36 ) ;
if ( ! V_36 ||
! V_36 -> V_41 ||
! V_36 -> V_41 -> V_42 )
return 0 ;
V_34 = F_31 ( V_11 ) ;
V_25 = V_36 -> V_41 -> V_42 (
V_34 -> V_43 ,
V_38 -> V_44 ) ;
V_38 -> V_45 =
F_32 ( V_38 -> V_45 , V_25 ) ;
}
return 0 ;
}
static T_4 F_33 ( struct V_4 * V_5 ,
enum V_46 error )
{
struct V_37 V_15 = { error , V_47 } ;
int V_48 ;
V_48 = F_34 ( & V_5 -> V_5 , & V_15 , F_29 ) ;
return V_15 . V_45 ;
}
static int F_35 ( struct V_11 * V_11 , void * V_15 )
{
struct V_34 * V_34 ;
struct V_35 * V_36 ;
T_4 V_25 , * V_45 ;
V_45 = ( T_4 * ) V_15 ;
if ( V_11 -> V_39 == & V_40 && V_11 -> V_36 ) {
V_36 = F_30 ( V_11 -> V_36 ) ;
if ( V_36 &&
V_36 -> V_41 &&
V_36 -> V_41 -> V_49 ) {
V_34 = F_31 ( V_11 ) ;
V_25 = V_36 -> V_41 -> V_49 (
V_34 -> V_43 ) ;
* V_45 = F_32 ( * V_45 , V_25 ) ;
}
}
return 0 ;
}
static T_4 F_36 ( struct V_4 * V_5 )
{
T_4 V_25 = V_50 ;
int V_10 ;
V_10 = F_34 ( & V_5 -> V_5 , & V_25 , F_35 ) ;
return V_25 ;
}
static int F_37 ( struct V_11 * V_11 , void * V_15 )
{
struct V_34 * V_34 ;
struct V_35 * V_36 ;
T_4 V_25 , * V_45 ;
V_45 = ( T_4 * ) V_15 ;
if ( V_11 -> V_39 == & V_40 && V_11 -> V_36 ) {
V_36 = F_30 ( V_11 -> V_36 ) ;
if ( V_36 &&
V_36 -> V_41 &&
V_36 -> V_41 -> V_51 ) {
V_34 = F_31 ( V_11 ) ;
V_25 = V_36 -> V_41 -> V_51 (
V_34 -> V_43 ) ;
* V_45 = F_32 ( * V_45 , V_25 ) ;
}
}
return 0 ;
}
static T_4 F_38 ( struct V_4 * V_5 )
{
T_4 V_25 = V_50 ;
int V_10 ;
if ( V_5 -> V_52 == V_53 ) {
V_5 -> V_54 = true ;
F_39 ( V_5 ) ;
F_6 ( V_5 ) ;
F_40 ( V_5 ) ;
}
V_10 = F_34 ( & V_5 -> V_5 , & V_25 , F_37 ) ;
return V_25 ;
}
static int F_41 ( struct V_11 * V_11 , void * V_15 )
{
struct V_34 * V_34 ;
struct V_35 * V_36 ;
if ( V_11 -> V_39 == & V_40 && V_11 -> V_36 ) {
V_36 = F_30 ( V_11 -> V_36 ) ;
if ( V_36 &&
V_36 -> V_41 &&
V_36 -> V_41 -> V_55 ) {
V_34 = F_31 ( V_11 ) ;
V_36 -> V_41 -> V_55 ( V_34 -> V_43 ) ;
}
}
return 0 ;
}
static void F_42 ( struct V_4 * V_5 )
{
int V_10 ;
V_10 = F_34 ( & V_5 -> V_5 , NULL , F_41 ) ;
}
static int T_1 F_43 ( const struct V_56 * V_57 )
{
F_44 ( L_6 ,
V_57 -> V_58 ) ;
F_45 () ;
return 0 ;
}
static int T_1 F_46 ( void )
{
int V_10 ;
if ( V_2 )
return F_47 ( & V_59 ) ;
F_48 ( V_60 ) ;
V_10 = F_49 () ;
if ( V_10 ) {
F_50 ( V_61 L_7 , V_10 ) ;
goto V_62;
}
V_10 = F_47 ( & V_59 ) ;
if ( V_10 )
F_51 () ;
V_62:
return V_10 ;
}
