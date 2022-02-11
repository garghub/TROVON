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
static int F_10 ( struct V_4 * V_5 ,
const struct V_12 * V_13 )
{
int V_14 ;
if ( ! F_11 ( V_5 ) ||
( ( F_9 ( V_5 ) != V_11 ) &&
( F_9 ( V_5 ) != V_15 ) &&
( F_9 ( V_5 ) != V_16 ) ) )
return - V_17 ;
V_14 = F_12 ( V_5 ) ;
if ( V_14 )
return V_14 ;
F_13 ( V_5 ) ;
V_5 -> V_18 = false ;
return 0 ;
}
static void F_14 ( struct V_4 * V_5 )
{
F_15 ( V_5 ) ;
}
static int F_16 ( struct V_9 * V_9 , void * V_19 )
{
struct V_20 * V_20 ;
struct V_21 * V_22 ;
struct V_23 * V_24 ;
T_2 V_14 ;
V_24 = (struct V_23 * ) V_19 ;
if ( V_9 -> V_25 == & V_26 && V_9 -> V_22 ) {
V_22 = F_17 ( V_9 -> V_22 ) ;
if ( ! V_22 ||
! V_22 -> V_27 ||
! V_22 -> V_27 -> V_28 )
return 0 ;
V_20 = F_18 ( V_9 ) ;
V_14 = V_22 -> V_27 -> V_28 (
V_20 -> V_29 ,
V_24 -> V_30 ) ;
V_24 -> V_31 =
F_19 ( V_24 -> V_31 , V_14 ) ;
}
return 0 ;
}
static T_2 F_20 ( struct V_4 * V_5 ,
enum V_32 error )
{
struct V_23 V_19 = { error , V_33 } ;
F_21 ( & V_5 -> V_5 , & V_19 , F_16 ) ;
return V_19 . V_31 ;
}
static int F_22 ( struct V_9 * V_9 , void * V_19 )
{
struct V_20 * V_20 ;
struct V_21 * V_22 ;
T_2 V_14 , * V_31 ;
V_31 = ( T_2 * ) V_19 ;
if ( V_9 -> V_25 == & V_26 && V_9 -> V_22 ) {
V_22 = F_17 ( V_9 -> V_22 ) ;
if ( V_22 &&
V_22 -> V_27 &&
V_22 -> V_27 -> V_34 ) {
V_20 = F_18 ( V_9 ) ;
V_14 = V_22 -> V_27 -> V_34 (
V_20 -> V_29 ) ;
* V_31 = F_19 ( * V_31 , V_14 ) ;
}
}
return 0 ;
}
static T_2 F_23 ( struct V_4 * V_5 )
{
T_2 V_14 = V_35 ;
F_21 ( & V_5 -> V_5 , & V_14 , F_22 ) ;
return V_14 ;
}
static int F_24 ( struct V_9 * V_9 , void * V_19 )
{
struct V_20 * V_20 ;
struct V_21 * V_22 ;
T_2 V_14 , * V_31 ;
V_31 = ( T_2 * ) V_19 ;
if ( V_9 -> V_25 == & V_26 && V_9 -> V_22 ) {
V_22 = F_17 ( V_9 -> V_22 ) ;
if ( V_22 &&
V_22 -> V_27 &&
V_22 -> V_27 -> V_36 ) {
V_20 = F_18 ( V_9 ) ;
V_14 = V_22 -> V_27 -> V_36 (
V_20 -> V_29 ) ;
* V_31 = F_19 ( * V_31 , V_14 ) ;
}
}
return 0 ;
}
static T_2 F_25 ( struct V_4 * V_5 )
{
T_2 V_14 = V_35 ;
if ( V_5 -> V_37 == V_38 ) {
V_5 -> V_39 = true ;
F_26 ( V_5 ) ;
F_4 ( V_5 ) ;
F_27 ( V_5 ) ;
}
F_21 ( & V_5 -> V_5 , & V_14 , F_24 ) ;
return V_14 ;
}
static int F_28 ( struct V_9 * V_9 , void * V_19 )
{
struct V_20 * V_20 ;
struct V_21 * V_22 ;
if ( V_9 -> V_25 == & V_26 && V_9 -> V_22 ) {
V_22 = F_17 ( V_9 -> V_22 ) ;
if ( V_22 &&
V_22 -> V_27 &&
V_22 -> V_27 -> V_40 ) {
V_20 = F_18 ( V_9 ) ;
V_22 -> V_27 -> V_40 ( V_20 -> V_29 ) ;
}
}
return 0 ;
}
static void F_29 ( struct V_4 * V_5 )
{
F_21 ( & V_5 -> V_5 , NULL , F_28 ) ;
}
static int T_1 F_30 ( const struct V_41 * V_42 )
{
F_31 ( L_4 ,
V_42 -> V_43 ) ;
F_32 () ;
return 0 ;
}
static int T_1 F_33 ( void )
{
int V_8 ;
if ( V_2 )
return F_34 ( & V_44 ) ;
F_35 ( V_45 ) ;
V_8 = F_36 () ;
if ( V_8 ) {
F_37 ( V_46 L_5 , V_8 ) ;
goto V_47;
}
V_8 = F_34 ( & V_44 ) ;
if ( V_8 )
F_38 () ;
V_47:
return V_8 ;
}
