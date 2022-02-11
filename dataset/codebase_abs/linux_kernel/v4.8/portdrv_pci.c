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
if ( ! V_5 -> V_20 ) {
F_17 ( & V_5 -> V_5 , 100 ) ;
F_18 ( & V_5 -> V_5 ) ;
F_19 ( & V_5 -> V_5 ) ;
F_20 ( & V_5 -> V_5 ) ;
F_21 ( & V_5 -> V_5 ) ;
}
return 0 ;
}
static void F_22 ( struct V_4 * V_5 )
{
if ( ! V_5 -> V_20 ) {
F_23 ( & V_5 -> V_5 ) ;
F_24 ( & V_5 -> V_5 ) ;
F_25 ( & V_5 -> V_5 ) ;
}
F_26 ( V_5 ) ;
}
static int F_27 ( struct V_9 * V_9 , void * V_21 )
{
struct V_22 * V_22 ;
struct V_23 * V_24 ;
struct V_25 * V_26 ;
T_2 V_16 ;
V_26 = (struct V_25 * ) V_21 ;
if ( V_9 -> V_27 == & V_28 && V_9 -> V_24 ) {
V_24 = F_28 ( V_9 -> V_24 ) ;
if ( ! V_24 ||
! V_24 -> V_29 ||
! V_24 -> V_29 -> V_30 )
return 0 ;
V_22 = F_29 ( V_9 ) ;
V_16 = V_24 -> V_29 -> V_30 (
V_22 -> V_31 ,
V_26 -> V_32 ) ;
V_26 -> V_33 =
F_30 ( V_26 -> V_33 , V_16 ) ;
}
return 0 ;
}
static T_2 F_31 ( struct V_4 * V_5 ,
enum V_34 error )
{
struct V_25 V_21 = { error , V_35 } ;
F_32 ( & V_5 -> V_5 , & V_21 , F_27 ) ;
return V_21 . V_33 ;
}
static int F_33 ( struct V_9 * V_9 , void * V_21 )
{
struct V_22 * V_22 ;
struct V_23 * V_24 ;
T_2 V_16 , * V_33 ;
V_33 = ( T_2 * ) V_21 ;
if ( V_9 -> V_27 == & V_28 && V_9 -> V_24 ) {
V_24 = F_28 ( V_9 -> V_24 ) ;
if ( V_24 &&
V_24 -> V_29 &&
V_24 -> V_29 -> V_36 ) {
V_22 = F_29 ( V_9 ) ;
V_16 = V_24 -> V_29 -> V_36 (
V_22 -> V_31 ) ;
* V_33 = F_30 ( * V_33 , V_16 ) ;
}
}
return 0 ;
}
static T_2 F_34 ( struct V_4 * V_5 )
{
T_2 V_16 = V_37 ;
F_32 ( & V_5 -> V_5 , & V_16 , F_33 ) ;
return V_16 ;
}
static int F_35 ( struct V_9 * V_9 , void * V_21 )
{
struct V_22 * V_22 ;
struct V_23 * V_24 ;
T_2 V_16 , * V_33 ;
V_33 = ( T_2 * ) V_21 ;
if ( V_9 -> V_27 == & V_28 && V_9 -> V_24 ) {
V_24 = F_28 ( V_9 -> V_24 ) ;
if ( V_24 &&
V_24 -> V_29 &&
V_24 -> V_29 -> V_38 ) {
V_22 = F_29 ( V_9 ) ;
V_16 = V_24 -> V_29 -> V_38 (
V_22 -> V_31 ) ;
* V_33 = F_30 ( * V_33 , V_16 ) ;
}
}
return 0 ;
}
static T_2 F_36 ( struct V_4 * V_5 )
{
T_2 V_16 = V_37 ;
if ( V_5 -> V_39 == V_40 ) {
V_5 -> V_41 = true ;
F_37 ( V_5 ) ;
F_4 ( V_5 ) ;
F_38 ( V_5 ) ;
}
F_32 ( & V_5 -> V_5 , & V_16 , F_35 ) ;
return V_16 ;
}
static int F_39 ( struct V_9 * V_9 , void * V_21 )
{
struct V_22 * V_22 ;
struct V_23 * V_24 ;
if ( V_9 -> V_27 == & V_28 && V_9 -> V_24 ) {
V_24 = F_28 ( V_9 -> V_24 ) ;
if ( V_24 &&
V_24 -> V_29 &&
V_24 -> V_29 -> V_42 ) {
V_22 = F_29 ( V_9 ) ;
V_24 -> V_29 -> V_42 ( V_22 -> V_31 ) ;
}
}
return 0 ;
}
static void F_40 ( struct V_4 * V_5 )
{
F_32 ( & V_5 -> V_5 , NULL , F_39 ) ;
}
static int T_1 F_41 ( const struct V_43 * V_44 )
{
F_42 ( L_4 ,
V_44 -> V_45 ) ;
F_43 () ;
return 0 ;
}
static int T_1 F_44 ( void )
{
int V_8 ;
if ( V_2 )
return F_45 ( & V_46 ) ;
F_46 ( V_47 ) ;
V_8 = F_47 () ;
if ( V_8 ) {
F_48 ( V_48 L_5 , V_8 ) ;
goto V_49;
}
V_8 = F_45 ( & V_46 ) ;
if ( V_8 )
F_49 () ;
V_49:
return V_8 ;
}
