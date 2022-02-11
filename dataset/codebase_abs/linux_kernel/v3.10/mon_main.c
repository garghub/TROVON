void F_1 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
unsigned long V_5 ;
struct V_6 * V_7 ;
F_2 ( & V_2 -> V_8 , V_5 ) ;
if ( V_2 -> V_9 == 0 ) {
if ( V_2 == & V_10 ) {
F_3 (p, &mon_buses) {
struct V_1 * V_11 ;
V_11 = F_4 ( V_7 , struct V_1 , V_12 ) ;
V_11 -> V_13 -> V_14 = 1 ;
}
} else {
V_2 -> V_13 -> V_14 = 1 ;
}
}
V_2 -> V_9 ++ ;
F_5 ( & V_4 -> V_15 , & V_2 -> V_16 ) ;
F_6 ( & V_2 -> V_8 , V_5 ) ;
F_7 ( & V_2 -> V_17 ) ;
}
void F_8 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
unsigned long V_5 ;
F_2 ( & V_2 -> V_8 , V_5 ) ;
F_9 ( & V_4 -> V_15 ) ;
-- V_2 -> V_9 ;
if ( V_2 -> V_9 == 0 )
F_10 ( V_2 ) ;
F_6 ( & V_2 -> V_8 , V_5 ) ;
F_11 ( & V_2 -> V_17 , V_18 ) ;
}
static void F_12 ( struct V_1 * V_2 , struct V_19 * V_19 )
{
unsigned long V_5 ;
struct V_6 * V_20 ;
struct V_3 * V_4 ;
F_2 ( & V_2 -> V_8 , V_5 ) ;
V_2 -> V_21 ++ ;
F_3 (pos, &mbus->r_list) {
V_4 = F_4 ( V_20 , struct V_3 , V_15 ) ;
V_4 -> V_22 ( V_4 -> V_23 , V_19 ) ;
}
F_6 ( & V_2 -> V_8 , V_5 ) ;
}
static void F_13 ( struct V_24 * V_25 , struct V_19 * V_19 )
{
struct V_1 * V_2 ;
if ( ( V_2 = V_25 -> V_1 ) != NULL )
F_12 ( V_2 , V_19 ) ;
F_12 ( & V_10 , V_19 ) ;
}
static void F_14 ( struct V_1 * V_2 , struct V_19 * V_19 , int error )
{
unsigned long V_5 ;
struct V_6 * V_20 ;
struct V_3 * V_4 ;
F_2 ( & V_2 -> V_8 , V_5 ) ;
V_2 -> V_21 ++ ;
F_3 (pos, &mbus->r_list) {
V_4 = F_4 ( V_20 , struct V_3 , V_15 ) ;
V_4 -> V_26 ( V_4 -> V_23 , V_19 , error ) ;
}
F_6 ( & V_2 -> V_8 , V_5 ) ;
}
static void F_15 ( struct V_24 * V_25 , struct V_19 * V_19 , int error )
{
struct V_1 * V_2 ;
if ( ( V_2 = V_25 -> V_1 ) != NULL )
F_14 ( V_2 , V_19 , error ) ;
F_14 ( & V_10 , V_19 , error ) ;
}
static void F_16 ( struct V_1 * V_2 , struct V_19 * V_19 , int V_27 )
{
unsigned long V_5 ;
struct V_6 * V_20 ;
struct V_3 * V_4 ;
F_2 ( & V_2 -> V_8 , V_5 ) ;
V_2 -> V_21 ++ ;
F_3 (pos, &mbus->r_list) {
V_4 = F_4 ( V_20 , struct V_3 , V_15 ) ;
V_4 -> V_28 ( V_4 -> V_23 , V_19 , V_27 ) ;
}
F_6 ( & V_2 -> V_8 , V_5 ) ;
}
static void F_17 ( struct V_24 * V_25 , struct V_19 * V_19 , int V_27 )
{
struct V_1 * V_2 ;
if ( ( V_2 = V_25 -> V_1 ) != NULL )
F_16 ( V_2 , V_19 , V_27 ) ;
F_16 ( & V_10 , V_19 , V_27 ) ;
}
static void F_10 ( struct V_1 * V_2 )
{
struct V_24 * V_25 ;
struct V_6 * V_7 ;
if ( V_2 == & V_10 ) {
F_3 (p, &mon_buses) {
V_2 = F_4 ( V_7 , struct V_1 , V_12 ) ;
if ( V_2 -> V_9 == 0 && ( V_25 = V_2 -> V_13 ) != NULL )
V_25 -> V_14 = 0 ;
}
} else {
if ( V_10 . V_9 == 0 && ( V_25 = V_2 -> V_13 ) != NULL ) {
V_25 -> V_14 = 0 ;
F_18 () ;
}
}
}
static void F_19 ( struct V_24 * V_25 )
{
F_20 ( V_25 ) ;
F_21 ( & V_29 ) ;
if ( V_10 . V_9 != 0 )
V_25 -> V_14 = 1 ;
F_22 ( & V_29 ) ;
}
static void F_23 ( struct V_24 * V_25 )
{
struct V_1 * V_2 = V_25 -> V_1 ;
F_21 ( & V_29 ) ;
F_9 ( & V_2 -> V_12 ) ;
if ( V_2 -> V_30 )
F_24 ( V_2 ) ;
if ( V_2 -> V_31 )
F_25 ( V_2 ) ;
F_26 ( V_2 , V_25 ) ;
F_11 ( & V_2 -> V_17 , V_18 ) ;
F_22 ( & V_29 ) ;
}
static int F_27 ( struct V_32 * V_33 , unsigned long V_34 ,
void * V_35 )
{
switch ( V_34 ) {
case V_36 :
F_19 ( V_35 ) ;
break;
case V_37 :
F_23 ( V_35 ) ;
}
return V_38 ;
}
static void F_26 ( struct V_1 * V_2 , struct V_24 * V_25 )
{
if ( V_25 -> V_14 ) {
V_25 -> V_14 = 0 ;
F_18 () ;
}
V_25 -> V_1 = NULL ;
V_2 -> V_13 = NULL ;
F_18 () ;
}
static void V_18 ( struct V_39 * V_4 )
{
struct V_1 * V_2 = F_28 ( V_4 , struct V_1 , V_17 ) ;
F_29 ( V_2 ) ;
}
static void F_20 ( struct V_24 * V_25 )
{
struct V_1 * V_2 ;
if ( ( V_2 = F_30 ( sizeof( struct V_1 ) , V_40 ) ) == NULL )
goto V_41;
F_31 ( & V_2 -> V_17 ) ;
F_32 ( & V_2 -> V_8 ) ;
F_33 ( & V_2 -> V_16 ) ;
V_2 -> V_13 = V_25 ;
V_25 -> V_1 = V_2 ;
V_2 -> V_30 = F_34 ( V_2 , V_25 ) ;
V_2 -> V_31 = F_35 ( V_2 , V_25 ) ;
F_21 ( & V_29 ) ;
F_5 ( & V_2 -> V_12 , & V_42 ) ;
F_22 ( & V_29 ) ;
return;
V_41:
return;
}
static void F_36 ( void )
{
struct V_1 * V_2 = & V_10 ;
F_31 ( & V_2 -> V_17 ) ;
F_32 ( & V_2 -> V_8 ) ;
F_33 ( & V_2 -> V_16 ) ;
V_2 -> V_30 = F_34 ( V_2 , NULL ) ;
V_2 -> V_31 = F_35 ( V_2 , NULL ) ;
}
struct V_1 * F_37 ( unsigned int V_43 )
{
struct V_6 * V_7 ;
struct V_1 * V_2 ;
if ( V_43 == 0 ) {
return & V_10 ;
}
F_3 (p, &mon_buses) {
V_2 = F_4 ( V_7 , struct V_1 , V_12 ) ;
if ( V_2 -> V_13 -> V_44 == V_43 ) {
return V_2 ;
}
}
return NULL ;
}
static int T_1 F_38 ( void )
{
struct V_24 * V_25 ;
int V_45 ;
if ( ( V_45 = F_39 () ) != 0 )
goto V_46;
if ( ( V_45 = F_40 () ) != 0 )
goto V_47;
F_36 () ;
if ( F_41 ( & V_48 ) != 0 ) {
F_42 (KERN_NOTICE TAG L_1 ) ;
V_45 = - V_49 ;
goto V_50;
}
F_21 ( & V_51 ) ;
F_43 (ubus, &usb_bus_list, bus_list) {
F_20 ( V_25 ) ;
}
F_44 ( & V_52 ) ;
F_22 ( & V_51 ) ;
return 0 ;
V_50:
F_45 () ;
V_47:
F_46 () ;
V_46:
return V_45 ;
}
static void T_2 F_47 ( void )
{
struct V_1 * V_2 ;
struct V_6 * V_7 ;
F_48 ( & V_52 ) ;
F_49 () ;
F_21 ( & V_29 ) ;
while ( ! F_50 ( & V_42 ) ) {
V_7 = V_42 . V_53 ;
V_2 = F_4 ( V_7 , struct V_1 , V_12 ) ;
F_9 ( V_7 ) ;
if ( V_2 -> V_30 )
F_24 ( V_2 ) ;
if ( V_2 -> V_31 )
F_25 ( V_2 ) ;
if ( V_2 -> V_9 ) {
F_42 (KERN_ERR TAG
L_2 ,
mbus->nreaders, mbus->u_bus->busnum) ;
F_51 ( & V_2 -> V_17 . V_54 , 2 ) ;
}
F_26 ( V_2 , V_2 -> V_13 ) ;
F_11 ( & V_2 -> V_17 , V_18 ) ;
}
V_2 = & V_10 ;
if ( V_2 -> V_30 )
F_24 ( V_2 ) ;
if ( V_2 -> V_31 )
F_25 ( V_2 ) ;
F_22 ( & V_29 ) ;
F_46 () ;
F_45 () ;
}
