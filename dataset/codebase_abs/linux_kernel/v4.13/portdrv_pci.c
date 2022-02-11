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
static int F_10 ( struct V_9 * V_5 )
{
return F_8 ( V_5 ) -> V_12 ? 0 : - V_13 ;
}
static int F_11 ( struct V_9 * V_5 )
{
return 0 ;
}
static int F_12 ( struct V_9 * V_5 )
{
return F_8 ( V_5 ) -> V_12 ? 0 : - V_13 ;
}
static int F_13 ( struct V_4 * V_5 ,
const struct V_14 * V_15 )
{
int V_16 ;
if ( ! F_14 ( V_5 ) ||
( ( F_9 ( V_5 ) != V_11 ) &&
( F_9 ( V_5 ) != V_17 ) &&
( F_9 ( V_5 ) != V_18 ) ) )
return - V_19 ;
V_16 = F_15 ( V_5 ) ;
if ( V_16 )
return V_16 ;
F_16 ( V_5 ) ;
if ( F_17 ( V_5 ) ) {
F_18 ( & V_5 -> V_5 , 100 ) ;
F_19 ( & V_5 -> V_5 ) ;
F_20 ( & V_5 -> V_5 ) ;
F_21 ( & V_5 -> V_5 ) ;
F_22 ( & V_5 -> V_5 ) ;
}
return 0 ;
}
static void F_23 ( struct V_4 * V_5 )
{
if ( F_17 ( V_5 ) ) {
F_24 ( & V_5 -> V_5 ) ;
F_25 ( & V_5 -> V_5 ) ;
F_26 ( & V_5 -> V_5 ) ;
}
F_27 ( V_5 ) ;
}
static int F_28 ( struct V_9 * V_9 , void * V_20 )
{
struct V_21 * V_21 ;
struct V_22 * V_23 ;
struct V_24 * V_25 ;
T_2 V_16 ;
V_25 = (struct V_24 * ) V_20 ;
if ( V_9 -> V_26 == & V_27 && V_9 -> V_23 ) {
V_23 = F_29 ( V_9 -> V_23 ) ;
if ( ! V_23 ||
! V_23 -> V_28 ||
! V_23 -> V_28 -> V_29 )
return 0 ;
V_21 = F_30 ( V_9 ) ;
V_16 = V_23 -> V_28 -> V_29 (
V_21 -> V_30 ,
V_25 -> V_31 ) ;
V_25 -> V_32 =
F_31 ( V_25 -> V_32 , V_16 ) ;
}
return 0 ;
}
static T_2 F_32 ( struct V_4 * V_5 ,
enum V_33 error )
{
struct V_24 V_20 = { error , V_34 } ;
F_33 ( & V_5 -> V_5 , & V_20 , F_28 ) ;
return V_20 . V_32 ;
}
static int F_34 ( struct V_9 * V_9 , void * V_20 )
{
struct V_21 * V_21 ;
struct V_22 * V_23 ;
T_2 V_16 , * V_32 ;
V_32 = ( T_2 * ) V_20 ;
if ( V_9 -> V_26 == & V_27 && V_9 -> V_23 ) {
V_23 = F_29 ( V_9 -> V_23 ) ;
if ( V_23 &&
V_23 -> V_28 &&
V_23 -> V_28 -> V_35 ) {
V_21 = F_30 ( V_9 ) ;
V_16 = V_23 -> V_28 -> V_35 (
V_21 -> V_30 ) ;
* V_32 = F_31 ( * V_32 , V_16 ) ;
}
}
return 0 ;
}
static T_2 F_35 ( struct V_4 * V_5 )
{
T_2 V_16 = V_36 ;
F_33 ( & V_5 -> V_5 , & V_16 , F_34 ) ;
return V_16 ;
}
static int F_36 ( struct V_9 * V_9 , void * V_20 )
{
struct V_21 * V_21 ;
struct V_22 * V_23 ;
T_2 V_16 , * V_32 ;
V_32 = ( T_2 * ) V_20 ;
if ( V_9 -> V_26 == & V_27 && V_9 -> V_23 ) {
V_23 = F_29 ( V_9 -> V_23 ) ;
if ( V_23 &&
V_23 -> V_28 &&
V_23 -> V_28 -> V_37 ) {
V_21 = F_30 ( V_9 ) ;
V_16 = V_23 -> V_28 -> V_37 (
V_21 -> V_30 ) ;
* V_32 = F_31 ( * V_32 , V_16 ) ;
}
}
return 0 ;
}
static T_2 F_37 ( struct V_4 * V_5 )
{
T_2 V_16 = V_36 ;
if ( V_5 -> V_38 == V_39 ) {
V_5 -> V_40 = true ;
F_38 ( V_5 ) ;
F_4 ( V_5 ) ;
F_39 ( V_5 ) ;
}
F_33 ( & V_5 -> V_5 , & V_16 , F_36 ) ;
return V_16 ;
}
static int F_40 ( struct V_9 * V_9 , void * V_20 )
{
struct V_21 * V_21 ;
struct V_22 * V_23 ;
if ( V_9 -> V_26 == & V_27 && V_9 -> V_23 ) {
V_23 = F_29 ( V_9 -> V_23 ) ;
if ( V_23 &&
V_23 -> V_28 &&
V_23 -> V_28 -> V_41 ) {
V_21 = F_30 ( V_9 ) ;
V_23 -> V_28 -> V_41 ( V_21 -> V_30 ) ;
}
}
return 0 ;
}
static void F_41 ( struct V_4 * V_5 )
{
F_33 ( & V_5 -> V_5 , NULL , F_40 ) ;
}
static int T_1 F_42 ( const struct V_42 * V_43 )
{
F_43 ( L_4 ,
V_43 -> V_44 ) ;
F_44 () ;
return 0 ;
}
static int T_1 F_45 ( void )
{
int V_8 ;
if ( V_2 )
return F_46 ( & V_45 ) ;
F_47 ( V_46 ) ;
V_8 = F_48 () ;
if ( V_8 ) {
F_49 ( V_47 L_5 , V_8 ) ;
goto V_48;
}
V_8 = F_46 ( & V_45 ) ;
if ( V_8 )
F_50 () ;
V_48:
return V_8 ;
}
