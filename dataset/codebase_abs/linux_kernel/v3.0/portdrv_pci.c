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
static int T_3 F_11 ( struct V_4 * V_5 ,
const struct V_15 * V_16 )
{
int V_17 ;
if ( ! F_12 ( V_5 ) ||
( ( V_5 -> V_13 != V_14 ) &&
( V_5 -> V_13 != V_18 ) &&
( V_5 -> V_13 != V_19 ) ) )
return - V_20 ;
if ( ! V_5 -> V_21 && V_5 -> V_22 ) {
F_13 ( & V_5 -> V_5 , L_4
L_5 , V_5 -> V_23 , V_5 -> V_11 ) ;
}
V_17 = F_14 ( V_5 ) ;
if ( V_17 )
return V_17 ;
F_15 ( V_5 ) ;
return 0 ;
}
static void F_16 ( struct V_4 * V_5 )
{
F_17 ( V_5 ) ;
F_18 ( V_5 ) ;
}
static int F_19 ( struct V_11 * V_11 , void * V_24 )
{
struct V_25 * V_25 ;
struct V_26 * V_27 ;
struct V_28 * V_29 ;
T_4 V_17 ;
V_29 = (struct V_28 * ) V_24 ;
if ( V_11 -> V_30 == & V_31 && V_11 -> V_27 ) {
V_27 = F_20 ( V_11 -> V_27 ) ;
if ( ! V_27 ||
! V_27 -> V_32 ||
! V_27 -> V_32 -> V_33 )
return 0 ;
V_25 = F_21 ( V_11 ) ;
V_17 = V_27 -> V_32 -> V_33 (
V_25 -> V_34 ,
V_29 -> V_35 ) ;
V_29 -> V_36 =
F_22 ( V_29 -> V_36 , V_17 ) ;
}
return 0 ;
}
static T_4 F_23 ( struct V_4 * V_5 ,
enum V_37 error )
{
struct V_28 V_24 = { error , V_38 } ;
int V_39 ;
V_39 = F_24 ( & V_5 -> V_5 , & V_24 , F_19 ) ;
return V_24 . V_36 ;
}
static int F_25 ( struct V_11 * V_11 , void * V_24 )
{
struct V_25 * V_25 ;
struct V_26 * V_27 ;
T_4 V_17 , * V_36 ;
V_36 = ( T_4 * ) V_24 ;
if ( V_11 -> V_30 == & V_31 && V_11 -> V_27 ) {
V_27 = F_20 ( V_11 -> V_27 ) ;
if ( V_27 &&
V_27 -> V_32 &&
V_27 -> V_32 -> V_40 ) {
V_25 = F_21 ( V_11 ) ;
V_17 = V_27 -> V_32 -> V_40 (
V_25 -> V_34 ) ;
* V_36 = F_22 ( * V_36 , V_17 ) ;
}
}
return 0 ;
}
static T_4 F_26 ( struct V_4 * V_5 )
{
T_4 V_17 = V_41 ;
int V_10 ;
V_10 = F_24 ( & V_5 -> V_5 , & V_17 , F_25 ) ;
return V_17 ;
}
static int F_27 ( struct V_11 * V_11 , void * V_24 )
{
struct V_25 * V_25 ;
struct V_26 * V_27 ;
T_4 V_17 , * V_36 ;
V_36 = ( T_4 * ) V_24 ;
if ( V_11 -> V_30 == & V_31 && V_11 -> V_27 ) {
V_27 = F_20 ( V_11 -> V_27 ) ;
if ( V_27 &&
V_27 -> V_32 &&
V_27 -> V_32 -> V_42 ) {
V_25 = F_21 ( V_11 ) ;
V_17 = V_27 -> V_32 -> V_42 (
V_25 -> V_34 ) ;
* V_36 = F_22 ( * V_36 , V_17 ) ;
}
}
return 0 ;
}
static T_4 F_28 ( struct V_4 * V_5 )
{
T_4 V_17 = V_41 ;
int V_10 ;
if ( V_5 -> V_43 == V_44 ) {
V_5 -> V_45 = true ;
F_29 ( V_5 ) ;
F_6 ( V_5 ) ;
F_30 ( V_5 ) ;
}
V_10 = F_24 ( & V_5 -> V_5 , & V_17 , F_27 ) ;
return V_17 ;
}
static int F_31 ( struct V_11 * V_11 , void * V_24 )
{
struct V_25 * V_25 ;
struct V_26 * V_27 ;
if ( V_11 -> V_30 == & V_31 && V_11 -> V_27 ) {
V_27 = F_20 ( V_11 -> V_27 ) ;
if ( V_27 &&
V_27 -> V_32 &&
V_27 -> V_32 -> V_46 ) {
V_25 = F_21 ( V_11 ) ;
V_27 -> V_32 -> V_46 ( V_25 -> V_34 ) ;
}
}
return 0 ;
}
static void F_32 ( struct V_4 * V_5 )
{
int V_10 ;
V_10 = F_24 ( & V_5 -> V_5 , NULL , F_31 ) ;
}
static int T_1 F_33 ( const struct V_47 * V_48 )
{
F_34 ( L_6 ,
V_48 -> V_49 ) ;
F_35 () ;
return 0 ;
}
static int T_1 F_36 ( void )
{
int V_10 ;
if ( V_2 )
return F_37 ( & V_50 ) ;
F_38 ( V_51 ) ;
V_10 = F_39 () ;
if ( V_10 ) {
F_40 ( V_52 L_7 , V_10 ) ;
goto V_53;
}
V_10 = F_37 ( & V_50 ) ;
if ( V_10 )
F_41 () ;
V_53:
return V_10 ;
}
