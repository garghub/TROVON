static T_1 F_1 ( struct V_1 * V_2 , char * V_3 )
{
int V_4 ;
T_2 V_5 ;
V_4 = F_2 ( V_2 -> V_6 , & V_5 ) ;
if ( V_4 )
goto exit;
V_4 = sprintf ( V_3 , L_1 , V_5 ) ;
exit:
return V_4 ;
}
static T_1 F_3 ( struct V_1 * V_1 , const char * V_3 ,
T_3 V_7 )
{
struct V_8 * V_2 = V_1 -> V_6 ;
unsigned long V_9 ;
T_2 V_10 ;
int V_4 = 0 ;
V_9 = F_4 ( V_3 , NULL , 10 ) ;
V_10 = ( T_2 ) ( V_9 & 0xff ) ;
F_5 ( L_2 , V_10 ) ;
if ( ! F_6 ( V_2 -> V_11 -> V_12 ) ) {
V_4 = - V_13 ;
goto exit;
}
switch ( V_10 ) {
case 0 :
if ( V_2 -> V_11 -> V_14 )
V_4 = V_2 -> V_11 -> V_14 ( V_2 ) ;
break;
case 1 :
if ( V_2 -> V_11 -> V_15 )
V_4 = V_2 -> V_11 -> V_15 ( V_2 ) ;
break;
default:
F_7 ( L_3 ) ;
V_4 = - V_16 ;
}
F_8 ( V_2 -> V_11 -> V_12 ) ;
exit:
if ( V_4 )
return V_4 ;
return V_7 ;
}
static T_1 F_9 ( struct V_1 * V_2 , char * V_3 )
{
int V_4 ;
T_2 V_5 ;
V_4 = F_10 ( V_2 -> V_6 , & V_5 ) ;
if ( V_4 )
goto exit;
V_4 = sprintf ( V_3 , L_1 , V_5 ) ;
exit:
return V_4 ;
}
static T_1 F_11 ( struct V_1 * V_2 , const char * V_3 ,
T_3 V_7 )
{
struct V_17 * V_11 = V_2 -> V_6 -> V_11 ;
unsigned long V_18 ;
T_2 V_19 ;
int V_4 = 0 ;
V_18 = F_4 ( V_3 , NULL , 10 ) ;
V_19 = ( T_2 ) ( V_18 & 0xff ) ;
F_5 ( L_4 , V_19 ) ;
if ( ! F_6 ( V_11 -> V_12 ) ) {
V_4 = - V_13 ;
goto exit;
}
if ( V_11 -> V_20 )
V_4 = V_11 -> V_20 ( V_2 -> V_6 , V_19 ) ;
F_8 ( V_11 -> V_12 ) ;
exit:
if ( V_4 )
return V_4 ;
return V_7 ;
}
static T_1 F_12 ( struct V_1 * V_2 , char * V_3 )
{
int V_4 ;
T_2 V_5 ;
V_4 = F_13 ( V_2 -> V_6 , & V_5 ) ;
if ( V_4 )
goto exit;
V_4 = sprintf ( V_3 , L_1 , V_5 ) ;
exit:
return V_4 ;
}
static T_1 F_14 ( struct V_1 * V_2 , char * V_3 )
{
int V_4 ;
T_2 V_5 ;
V_4 = F_15 ( V_2 -> V_6 , & V_5 ) ;
if ( V_4 )
goto exit;
V_4 = sprintf ( V_3 , L_1 , V_5 ) ;
exit:
return V_4 ;
}
static T_1 F_16 ( struct V_1 * V_1 , const char * V_3 ,
T_3 V_7 )
{
struct V_8 * V_2 = V_1 -> V_6 ;
unsigned long V_21 ;
T_4 V_22 ;
int V_4 = 0 ;
V_21 = F_4 ( V_3 , NULL , 10 ) ;
V_22 = ( T_4 ) ( V_21 & 0xffffffff ) ;
F_5 ( L_5 , V_22 ) ;
if ( ! F_6 ( V_2 -> V_11 -> V_12 ) ) {
V_4 = - V_13 ;
goto exit;
}
if ( V_2 -> V_11 -> V_23 )
V_4 = V_2 -> V_11 -> V_23 ( V_2 , V_22 ) ;
F_8 ( V_2 -> V_11 -> V_12 ) ;
exit:
if ( V_4 )
return V_4 ;
return V_7 ;
}
static bool F_17 ( struct V_1 * V_1 )
{
struct V_8 * V_2 = V_1 -> V_6 ;
if ( ( ! V_2 ) || ( ! V_2 -> V_11 ) )
return false ;
if ( ( V_2 -> V_11 -> V_15 ) ||
( V_2 -> V_11 -> V_14 ) ||
( V_2 -> V_11 -> F_2 ) )
return true ;
return false ;
}
static bool F_18 ( struct V_1 * V_1 )
{
struct V_8 * V_2 = V_1 -> V_6 ;
if ( ( ! V_2 ) || ( ! V_2 -> V_11 ) )
return false ;
if ( ( V_2 -> V_11 -> V_20 ) ||
( V_2 -> V_11 -> F_10 ) )
return true ;
return false ;
}
static bool F_19 ( struct V_1 * V_1 )
{
struct V_8 * V_2 = V_1 -> V_6 ;
if ( ( ! V_2 ) || ( ! V_2 -> V_11 ) )
return false ;
if ( V_2 -> V_11 -> F_13 )
return true ;
return false ;
}
static bool F_20 ( struct V_1 * V_1 )
{
struct V_8 * V_2 = V_1 -> V_6 ;
if ( ( ! V_2 ) || ( ! V_2 -> V_11 ) )
return false ;
if ( V_2 -> V_11 -> F_15 )
return true ;
return false ;
}
static bool F_21 ( struct V_1 * V_1 )
{
struct V_8 * V_2 = V_1 -> V_6 ;
if ( ( ! V_2 ) || ( ! V_2 -> V_11 ) )
return false ;
if ( V_2 -> V_11 -> V_23 )
return true ;
return false ;
}
static int F_22 ( struct V_1 * V_2 )
{
int V_4 = 0 ;
F_23 ( V_2 ) ;
if ( F_17 ( V_2 ) ) {
V_4 = F_24 ( & V_2 -> V_24 ,
& V_25 . V_26 ) ;
if ( V_4 )
goto V_27;
}
if ( F_18 ( V_2 ) ) {
V_4 = F_24 ( & V_2 -> V_24 ,
& V_28 . V_26 ) ;
if ( V_4 )
goto V_29;
}
if ( F_19 ( V_2 ) ) {
V_4 = F_24 ( & V_2 -> V_24 ,
& V_30 . V_26 ) ;
if ( V_4 )
goto V_31;
}
if ( F_20 ( V_2 ) ) {
V_4 = F_24 ( & V_2 -> V_24 ,
& V_32 . V_26 ) ;
if ( V_4 )
goto V_33;
}
if ( F_21 ( V_2 ) ) {
V_4 = F_24 ( & V_2 -> V_24 ,
& V_34 . V_26 ) ;
if ( V_4 )
goto V_35;
}
goto exit;
V_35:
if ( F_20 ( V_2 ) )
F_25 ( & V_2 -> V_24 ,
& V_32 . V_26 ) ;
V_33:
if ( F_19 ( V_2 ) )
F_25 ( & V_2 -> V_24 , & V_30 . V_26 ) ;
V_31:
if ( F_18 ( V_2 ) )
F_25 ( & V_2 -> V_24 ,
& V_28 . V_26 ) ;
V_29:
if ( F_17 ( V_2 ) )
F_25 ( & V_2 -> V_24 , & V_25 . V_26 ) ;
V_27:
F_26 ( V_2 ) ;
exit:
return V_4 ;
}
static void F_27 ( struct V_1 * V_2 )
{
if ( F_17 ( V_2 ) )
F_25 ( & V_2 -> V_24 , & V_25 . V_26 ) ;
if ( F_18 ( V_2 ) )
F_25 ( & V_2 -> V_24 ,
& V_28 . V_26 ) ;
if ( F_19 ( V_2 ) )
F_25 ( & V_2 -> V_24 , & V_30 . V_26 ) ;
if ( F_20 ( V_2 ) )
F_25 ( & V_2 -> V_24 ,
& V_32 . V_26 ) ;
if ( F_21 ( V_2 ) )
F_25 ( & V_2 -> V_24 , & V_34 . V_26 ) ;
F_26 ( V_2 ) ;
}
static struct V_8 * F_28 ( const char * V_36 )
{
struct V_8 * V_2 ;
struct V_37 * V_38 ;
F_29 (tmp, &pci_hotplug_slot_list) {
V_2 = F_30 ( V_38 , struct V_8 , V_39 ) ;
if ( strcmp ( F_31 ( V_2 ) , V_36 ) == 0 )
return V_2 ;
}
return NULL ;
}
int F_32 ( struct V_8 * V_2 , struct V_40 * V_41 ,
int V_42 , const char * V_36 ,
struct V_43 * V_12 , const char * V_44 )
{
int V_45 ;
struct V_1 * V_1 ;
if ( V_2 == NULL )
return - V_13 ;
if ( ( V_2 -> V_46 == NULL ) || ( V_2 -> V_11 == NULL ) )
return - V_16 ;
if ( V_2 -> V_47 == NULL ) {
F_5 ( L_6
L_7 ) ;
return - V_16 ;
}
V_2 -> V_11 -> V_12 = V_12 ;
V_2 -> V_11 -> V_44 = V_44 ;
F_33 ( & V_48 ) ;
V_1 = F_34 ( V_41 , V_42 , V_36 , V_2 ) ;
if ( F_35 ( V_1 ) ) {
V_45 = F_36 ( V_1 ) ;
goto V_49;
}
V_2 -> V_1 = V_1 ;
V_1 -> V_6 = V_2 ;
F_37 ( & V_2 -> V_39 , & V_50 ) ;
V_45 = F_22 ( V_1 ) ;
F_38 ( & V_1 -> V_24 , V_51 ) ;
F_5 ( L_8 , V_36 ) ;
V_49:
F_39 ( & V_48 ) ;
return V_45 ;
}
int F_40 ( struct V_8 * V_6 )
{
struct V_8 * V_52 ;
struct V_1 * V_2 ;
if ( ! V_6 )
return - V_13 ;
F_33 ( & V_48 ) ;
V_52 = F_28 ( F_31 ( V_6 ) ) ;
if ( V_52 != V_6 ) {
F_39 ( & V_48 ) ;
return - V_13 ;
}
F_41 ( & V_6 -> V_39 ) ;
V_2 = V_6 -> V_1 ;
F_27 ( V_2 ) ;
F_5 ( L_9 , F_31 ( V_6 ) ) ;
V_6 -> V_47 ( V_6 ) ;
V_2 -> V_6 = NULL ;
F_42 ( V_2 ) ;
F_39 ( & V_48 ) ;
return 0 ;
}
int F_43 ( struct V_8 * V_6 ,
struct V_53 * V_46 )
{
if ( ! V_6 || ! V_46 )
return - V_13 ;
memcpy ( V_6 -> V_46 , V_46 , sizeof( struct V_53 ) ) ;
return 0 ;
}
static int T_5 F_44 ( void )
{
int V_45 ;
V_45 = F_45 ( V_54 ) ;
if ( V_45 ) {
F_7 ( L_10 , V_45 ) ;
goto V_55;
}
V_46 ( V_56 L_11 V_57 L_12 ) ;
V_55:
return V_45 ;
}
static void T_6 F_46 ( void )
{
F_47 () ;
}
