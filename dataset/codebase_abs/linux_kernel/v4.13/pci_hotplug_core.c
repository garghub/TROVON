static T_1 F_1 ( struct V_1 * V_1 , char * V_2 )
{
int V_3 ;
T_2 V_4 ;
V_3 = F_2 ( V_1 -> V_5 , & V_4 ) ;
if ( V_3 )
return V_3 ;
return sprintf ( V_2 , L_1 , V_4 ) ;
}
static T_1 F_3 ( struct V_1 * V_1 , const char * V_2 ,
T_3 V_6 )
{
struct V_7 * V_8 = V_1 -> V_5 ;
unsigned long V_9 ;
T_2 V_10 ;
int V_3 = 0 ;
V_9 = F_4 ( V_2 , NULL , 10 ) ;
V_10 = ( T_2 ) ( V_9 & 0xff ) ;
F_5 ( L_2 , V_10 ) ;
if ( ! F_6 ( V_8 -> V_11 -> V_12 ) ) {
V_3 = - V_13 ;
goto exit;
}
switch ( V_10 ) {
case 0 :
if ( V_8 -> V_11 -> V_14 )
V_3 = V_8 -> V_11 -> V_14 ( V_8 ) ;
break;
case 1 :
if ( V_8 -> V_11 -> V_15 )
V_3 = V_8 -> V_11 -> V_15 ( V_8 ) ;
break;
default:
F_7 ( L_3 ) ;
V_3 = - V_16 ;
}
F_8 ( V_8 -> V_11 -> V_12 ) ;
exit:
if ( V_3 )
return V_3 ;
return V_6 ;
}
static T_1 F_9 ( struct V_1 * V_1 , char * V_2 )
{
int V_3 ;
T_2 V_4 ;
V_3 = F_10 ( V_1 -> V_5 , & V_4 ) ;
if ( V_3 )
return V_3 ;
return sprintf ( V_2 , L_1 , V_4 ) ;
}
static T_1 F_11 ( struct V_1 * V_1 , const char * V_2 ,
T_3 V_6 )
{
struct V_17 * V_11 = V_1 -> V_5 -> V_11 ;
unsigned long V_18 ;
T_2 V_19 ;
int V_3 = 0 ;
V_18 = F_4 ( V_2 , NULL , 10 ) ;
V_19 = ( T_2 ) ( V_18 & 0xff ) ;
F_5 ( L_4 , V_19 ) ;
if ( ! F_6 ( V_11 -> V_12 ) ) {
V_3 = - V_13 ;
goto exit;
}
if ( V_11 -> V_20 )
V_3 = V_11 -> V_20 ( V_1 -> V_5 , V_19 ) ;
F_8 ( V_11 -> V_12 ) ;
exit:
if ( V_3 )
return V_3 ;
return V_6 ;
}
static T_1 F_12 ( struct V_1 * V_1 , char * V_2 )
{
int V_3 ;
T_2 V_4 ;
V_3 = F_13 ( V_1 -> V_5 , & V_4 ) ;
if ( V_3 )
return V_3 ;
return sprintf ( V_2 , L_1 , V_4 ) ;
}
static T_1 F_14 ( struct V_1 * V_1 , char * V_2 )
{
int V_3 ;
T_2 V_4 ;
V_3 = F_15 ( V_1 -> V_5 , & V_4 ) ;
if ( V_3 )
return V_3 ;
return sprintf ( V_2 , L_1 , V_4 ) ;
}
static T_1 F_16 ( struct V_1 * V_1 , const char * V_2 ,
T_3 V_6 )
{
struct V_7 * V_8 = V_1 -> V_5 ;
unsigned long V_21 ;
T_4 V_22 ;
int V_3 = 0 ;
V_21 = F_4 ( V_2 , NULL , 10 ) ;
V_22 = ( T_4 ) ( V_21 & 0xffffffff ) ;
F_5 ( L_5 , V_22 ) ;
if ( ! F_6 ( V_8 -> V_11 -> V_12 ) ) {
V_3 = - V_13 ;
goto exit;
}
if ( V_8 -> V_11 -> V_23 )
V_3 = V_8 -> V_11 -> V_23 ( V_8 , V_22 ) ;
F_8 ( V_8 -> V_11 -> V_12 ) ;
exit:
if ( V_3 )
return V_3 ;
return V_6 ;
}
static bool F_17 ( struct V_1 * V_1 )
{
struct V_7 * V_8 = V_1 -> V_5 ;
if ( ( ! V_8 ) || ( ! V_8 -> V_11 ) )
return false ;
if ( ( V_8 -> V_11 -> V_15 ) ||
( V_8 -> V_11 -> V_14 ) ||
( V_8 -> V_11 -> F_2 ) )
return true ;
return false ;
}
static bool F_18 ( struct V_1 * V_1 )
{
struct V_7 * V_8 = V_1 -> V_5 ;
if ( ( ! V_8 ) || ( ! V_8 -> V_11 ) )
return false ;
if ( ( V_8 -> V_11 -> V_20 ) ||
( V_8 -> V_11 -> F_10 ) )
return true ;
return false ;
}
static bool F_19 ( struct V_1 * V_1 )
{
struct V_7 * V_8 = V_1 -> V_5 ;
if ( ( ! V_8 ) || ( ! V_8 -> V_11 ) )
return false ;
if ( V_8 -> V_11 -> F_13 )
return true ;
return false ;
}
static bool F_20 ( struct V_1 * V_1 )
{
struct V_7 * V_8 = V_1 -> V_5 ;
if ( ( ! V_8 ) || ( ! V_8 -> V_11 ) )
return false ;
if ( V_8 -> V_11 -> F_15 )
return true ;
return false ;
}
static bool F_21 ( struct V_1 * V_1 )
{
struct V_7 * V_8 = V_1 -> V_5 ;
if ( ( ! V_8 ) || ( ! V_8 -> V_11 ) )
return false ;
if ( V_8 -> V_11 -> V_23 )
return true ;
return false ;
}
static int F_22 ( struct V_1 * V_1 )
{
int V_3 = 0 ;
F_23 ( V_1 ) ;
if ( F_17 ( V_1 ) ) {
V_3 = F_24 ( & V_1 -> V_24 ,
& V_25 . V_26 ) ;
if ( V_3 )
goto V_27;
}
if ( F_18 ( V_1 ) ) {
V_3 = F_24 ( & V_1 -> V_24 ,
& V_28 . V_26 ) ;
if ( V_3 )
goto V_29;
}
if ( F_19 ( V_1 ) ) {
V_3 = F_24 ( & V_1 -> V_24 ,
& V_30 . V_26 ) ;
if ( V_3 )
goto V_31;
}
if ( F_20 ( V_1 ) ) {
V_3 = F_24 ( & V_1 -> V_24 ,
& V_32 . V_26 ) ;
if ( V_3 )
goto V_33;
}
if ( F_21 ( V_1 ) ) {
V_3 = F_24 ( & V_1 -> V_24 ,
& V_34 . V_26 ) ;
if ( V_3 )
goto V_35;
}
goto exit;
V_35:
if ( F_20 ( V_1 ) )
F_25 ( & V_1 -> V_24 ,
& V_32 . V_26 ) ;
V_33:
if ( F_19 ( V_1 ) )
F_25 ( & V_1 -> V_24 , & V_30 . V_26 ) ;
V_31:
if ( F_18 ( V_1 ) )
F_25 ( & V_1 -> V_24 ,
& V_28 . V_26 ) ;
V_29:
if ( F_17 ( V_1 ) )
F_25 ( & V_1 -> V_24 , & V_25 . V_26 ) ;
V_27:
F_26 ( V_1 ) ;
exit:
return V_3 ;
}
static void F_27 ( struct V_1 * V_1 )
{
if ( F_17 ( V_1 ) )
F_25 ( & V_1 -> V_24 , & V_25 . V_26 ) ;
if ( F_18 ( V_1 ) )
F_25 ( & V_1 -> V_24 ,
& V_28 . V_26 ) ;
if ( F_19 ( V_1 ) )
F_25 ( & V_1 -> V_24 , & V_30 . V_26 ) ;
if ( F_20 ( V_1 ) )
F_25 ( & V_1 -> V_24 ,
& V_32 . V_26 ) ;
if ( F_21 ( V_1 ) )
F_25 ( & V_1 -> V_24 , & V_34 . V_26 ) ;
F_26 ( V_1 ) ;
}
static struct V_7 * F_28 ( const char * V_36 )
{
struct V_7 * V_8 ;
F_29 (slot, &pci_hotplug_slot_list, slot_list) {
if ( strcmp ( F_30 ( V_8 ) , V_36 ) == 0 )
return V_8 ;
}
return NULL ;
}
int F_31 ( struct V_7 * V_8 , struct V_37 * V_38 ,
int V_39 , const char * V_36 ,
struct V_40 * V_12 , const char * V_41 )
{
int V_42 ;
struct V_1 * V_1 ;
if ( V_8 == NULL )
return - V_13 ;
if ( ( V_8 -> V_43 == NULL ) || ( V_8 -> V_11 == NULL ) )
return - V_16 ;
if ( V_8 -> V_44 == NULL ) {
F_5 ( L_6 ) ;
return - V_16 ;
}
V_8 -> V_11 -> V_12 = V_12 ;
V_8 -> V_11 -> V_41 = V_41 ;
F_32 ( & V_45 ) ;
V_1 = F_33 ( V_38 , V_39 , V_36 , V_8 ) ;
if ( F_34 ( V_1 ) ) {
V_42 = F_35 ( V_1 ) ;
goto V_46;
}
V_8 -> V_1 = V_1 ;
V_1 -> V_5 = V_8 ;
F_36 ( & V_8 -> V_47 , & V_48 ) ;
V_42 = F_22 ( V_1 ) ;
F_37 ( & V_1 -> V_24 , V_49 ) ;
F_5 ( L_7 , V_36 ) ;
V_46:
F_38 ( & V_45 ) ;
return V_42 ;
}
int F_39 ( struct V_7 * V_8 )
{
struct V_7 * V_50 ;
struct V_1 * V_1 ;
if ( ! V_8 )
return - V_13 ;
F_32 ( & V_45 ) ;
V_50 = F_28 ( F_30 ( V_8 ) ) ;
if ( V_50 != V_8 ) {
F_38 ( & V_45 ) ;
return - V_13 ;
}
F_40 ( & V_8 -> V_47 ) ;
V_1 = V_8 -> V_1 ;
F_27 ( V_1 ) ;
F_5 ( L_8 , F_30 ( V_8 ) ) ;
V_8 -> V_44 ( V_8 ) ;
V_1 -> V_5 = NULL ;
F_41 ( V_1 ) ;
F_38 ( & V_45 ) ;
return 0 ;
}
int F_42 ( struct V_7 * V_8 ,
struct V_51 * V_43 )
{
if ( ! V_8 || ! V_43 )
return - V_13 ;
memcpy ( V_8 -> V_43 , V_43 , sizeof( struct V_51 ) ) ;
return 0 ;
}
static int T_5 F_43 ( void )
{
int V_42 ;
V_42 = F_44 ( V_52 ) ;
if ( V_42 ) {
F_7 ( L_9 , V_42 ) ;
return V_42 ;
}
return V_42 ;
}
