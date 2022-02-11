static inline int F_1 ( int V_1 ) { return 0 ; }
static inline void F_2 ( void ) { }
static T_1 F_3 ( struct V_2 * V_3 , char * V_4 )
{
int V_5 ;
T_2 V_6 ;
V_5 = F_4 ( V_3 -> V_7 , & V_6 ) ;
if ( V_5 )
goto exit;
V_5 = sprintf ( V_4 , L_1 , V_6 ) ;
exit:
return V_5 ;
}
static T_1 F_5 ( struct V_2 * V_2 , const char * V_4 ,
T_3 V_8 )
{
struct V_9 * V_3 = V_2 -> V_7 ;
unsigned long V_10 ;
T_2 V_11 ;
int V_5 = 0 ;
V_10 = F_6 ( V_4 , NULL , 10 ) ;
V_11 = ( T_2 ) ( V_10 & 0xff ) ;
F_7 ( L_2 , V_11 ) ;
if ( ! F_8 ( V_3 -> V_12 -> V_13 ) ) {
V_5 = - V_14 ;
goto exit;
}
switch ( V_11 ) {
case 0 :
if ( V_3 -> V_12 -> V_15 )
V_5 = V_3 -> V_12 -> V_15 ( V_3 ) ;
break;
case 1 :
if ( V_3 -> V_12 -> V_16 )
V_5 = V_3 -> V_12 -> V_16 ( V_3 ) ;
break;
default:
F_9 ( L_3 ) ;
V_5 = - V_17 ;
}
F_10 ( V_3 -> V_12 -> V_13 ) ;
exit:
if ( V_5 )
return V_5 ;
return V_8 ;
}
static T_1 F_11 ( struct V_2 * V_3 , char * V_4 )
{
int V_5 ;
T_2 V_6 ;
V_5 = F_12 ( V_3 -> V_7 , & V_6 ) ;
if ( V_5 )
goto exit;
V_5 = sprintf ( V_4 , L_1 , V_6 ) ;
exit:
return V_5 ;
}
static T_1 F_13 ( struct V_2 * V_3 , const char * V_4 ,
T_3 V_8 )
{
struct V_18 * V_12 = V_3 -> V_7 -> V_12 ;
unsigned long V_19 ;
T_2 V_20 ;
int V_5 = 0 ;
V_19 = F_6 ( V_4 , NULL , 10 ) ;
V_20 = ( T_2 ) ( V_19 & 0xff ) ;
F_7 ( L_4 , V_20 ) ;
if ( ! F_8 ( V_12 -> V_13 ) ) {
V_5 = - V_14 ;
goto exit;
}
if ( V_12 -> V_21 )
V_5 = V_12 -> V_21 ( V_3 -> V_7 , V_20 ) ;
F_10 ( V_12 -> V_13 ) ;
exit:
if ( V_5 )
return V_5 ;
return V_8 ;
}
static T_1 F_14 ( struct V_2 * V_3 , char * V_4 )
{
int V_5 ;
T_2 V_6 ;
V_5 = F_15 ( V_3 -> V_7 , & V_6 ) ;
if ( V_5 )
goto exit;
V_5 = sprintf ( V_4 , L_1 , V_6 ) ;
exit:
return V_5 ;
}
static T_1 F_16 ( struct V_2 * V_3 , char * V_4 )
{
int V_5 ;
T_2 V_6 ;
V_5 = F_17 ( V_3 -> V_7 , & V_6 ) ;
if ( V_5 )
goto exit;
V_5 = sprintf ( V_4 , L_1 , V_6 ) ;
exit:
return V_5 ;
}
static T_1 F_18 ( struct V_2 * V_2 , const char * V_4 ,
T_3 V_8 )
{
struct V_9 * V_3 = V_2 -> V_7 ;
unsigned long V_22 ;
T_4 V_23 ;
int V_5 = 0 ;
V_22 = F_6 ( V_4 , NULL , 10 ) ;
V_23 = ( T_4 ) ( V_22 & 0xffffffff ) ;
F_7 ( L_5 , V_23 ) ;
if ( ! F_8 ( V_3 -> V_12 -> V_13 ) ) {
V_5 = - V_14 ;
goto exit;
}
if ( V_3 -> V_12 -> V_24 )
V_5 = V_3 -> V_12 -> V_24 ( V_3 , V_23 ) ;
F_10 ( V_3 -> V_12 -> V_13 ) ;
exit:
if ( V_5 )
return V_5 ;
return V_8 ;
}
static bool F_19 ( struct V_2 * V_2 )
{
struct V_9 * V_3 = V_2 -> V_7 ;
if ( ( ! V_3 ) || ( ! V_3 -> V_12 ) )
return false ;
if ( ( V_3 -> V_12 -> V_16 ) ||
( V_3 -> V_12 -> V_15 ) ||
( V_3 -> V_12 -> F_4 ) )
return true ;
return false ;
}
static bool F_20 ( struct V_2 * V_2 )
{
struct V_9 * V_3 = V_2 -> V_7 ;
if ( ( ! V_3 ) || ( ! V_3 -> V_12 ) )
return false ;
if ( ( V_3 -> V_12 -> V_21 ) ||
( V_3 -> V_12 -> F_12 ) )
return true ;
return false ;
}
static bool F_21 ( struct V_2 * V_2 )
{
struct V_9 * V_3 = V_2 -> V_7 ;
if ( ( ! V_3 ) || ( ! V_3 -> V_12 ) )
return false ;
if ( V_3 -> V_12 -> F_15 )
return true ;
return false ;
}
static bool F_22 ( struct V_2 * V_2 )
{
struct V_9 * V_3 = V_2 -> V_7 ;
if ( ( ! V_3 ) || ( ! V_3 -> V_12 ) )
return false ;
if ( V_3 -> V_12 -> F_17 )
return true ;
return false ;
}
static bool F_23 ( struct V_2 * V_2 )
{
struct V_9 * V_3 = V_2 -> V_7 ;
if ( ( ! V_3 ) || ( ! V_3 -> V_12 ) )
return false ;
if ( V_3 -> V_12 -> V_24 )
return true ;
return false ;
}
static int F_24 ( struct V_2 * V_3 )
{
int V_5 = 0 ;
F_25 ( V_3 ) ;
if ( F_19 ( V_3 ) ) {
V_5 = F_26 ( & V_3 -> V_25 ,
& V_26 . V_27 ) ;
if ( V_5 )
goto V_28;
}
if ( F_20 ( V_3 ) ) {
V_5 = F_26 ( & V_3 -> V_25 ,
& V_29 . V_27 ) ;
if ( V_5 )
goto V_30;
}
if ( F_21 ( V_3 ) ) {
V_5 = F_26 ( & V_3 -> V_25 ,
& V_31 . V_27 ) ;
if ( V_5 )
goto V_32;
}
if ( F_22 ( V_3 ) ) {
V_5 = F_26 ( & V_3 -> V_25 ,
& V_33 . V_27 ) ;
if ( V_5 )
goto V_34;
}
if ( F_23 ( V_3 ) ) {
V_5 = F_26 ( & V_3 -> V_25 ,
& V_35 . V_27 ) ;
if ( V_5 )
goto V_36;
}
goto exit;
V_36:
if ( F_22 ( V_3 ) )
F_27 ( & V_3 -> V_25 ,
& V_33 . V_27 ) ;
V_34:
if ( F_21 ( V_3 ) )
F_27 ( & V_3 -> V_25 , & V_31 . V_27 ) ;
V_32:
if ( F_20 ( V_3 ) )
F_27 ( & V_3 -> V_25 ,
& V_29 . V_27 ) ;
V_30:
if ( F_19 ( V_3 ) )
F_27 ( & V_3 -> V_25 , & V_26 . V_27 ) ;
V_28:
F_28 ( V_3 ) ;
exit:
return V_5 ;
}
static void F_29 ( struct V_2 * V_3 )
{
if ( F_19 ( V_3 ) )
F_27 ( & V_3 -> V_25 , & V_26 . V_27 ) ;
if ( F_20 ( V_3 ) )
F_27 ( & V_3 -> V_25 ,
& V_29 . V_27 ) ;
if ( F_21 ( V_3 ) )
F_27 ( & V_3 -> V_25 , & V_31 . V_27 ) ;
if ( F_22 ( V_3 ) )
F_27 ( & V_3 -> V_25 ,
& V_33 . V_27 ) ;
if ( F_23 ( V_3 ) )
F_27 ( & V_3 -> V_25 , & V_35 . V_27 ) ;
F_28 ( V_3 ) ;
}
static struct V_9 * F_30 ( const char * V_37 )
{
struct V_9 * V_3 ;
struct V_38 * V_39 ;
F_31 (tmp, &pci_hotplug_slot_list) {
V_3 = F_32 ( V_39 , struct V_9 , V_40 ) ;
if ( strcmp ( F_33 ( V_3 ) , V_37 ) == 0 )
return V_3 ;
}
return NULL ;
}
int F_34 ( struct V_9 * V_3 , struct V_41 * V_42 ,
int V_43 , const char * V_37 ,
struct V_44 * V_13 , const char * V_45 )
{
int V_46 ;
struct V_2 * V_2 ;
if ( V_3 == NULL )
return - V_14 ;
if ( ( V_3 -> V_47 == NULL ) || ( V_3 -> V_12 == NULL ) )
return - V_17 ;
if ( V_3 -> V_48 == NULL ) {
F_7 ( L_6
L_7 ) ;
return - V_17 ;
}
V_3 -> V_12 -> V_13 = V_13 ;
V_3 -> V_12 -> V_45 = V_45 ;
F_35 ( & V_49 ) ;
V_2 = F_36 ( V_42 , V_43 , V_37 , V_3 ) ;
if ( F_37 ( V_2 ) ) {
V_46 = F_38 ( V_2 ) ;
goto V_50;
}
V_3 -> V_2 = V_2 ;
V_2 -> V_7 = V_3 ;
F_39 ( & V_3 -> V_40 , & V_51 ) ;
V_46 = F_24 ( V_2 ) ;
F_40 ( & V_2 -> V_25 , V_52 ) ;
F_7 ( L_8 , V_37 ) ;
V_50:
F_41 ( & V_49 ) ;
return V_46 ;
}
int F_42 ( struct V_9 * V_7 )
{
struct V_9 * V_53 ;
struct V_2 * V_3 ;
if ( ! V_7 )
return - V_14 ;
F_35 ( & V_49 ) ;
V_53 = F_30 ( F_33 ( V_7 ) ) ;
if ( V_53 != V_7 ) {
F_41 ( & V_49 ) ;
return - V_14 ;
}
F_43 ( & V_7 -> V_40 ) ;
V_3 = V_7 -> V_2 ;
F_29 ( V_3 ) ;
F_7 ( L_9 , F_33 ( V_7 ) ) ;
V_7 -> V_48 ( V_7 ) ;
V_3 -> V_7 = NULL ;
F_44 ( V_3 ) ;
F_41 ( & V_49 ) ;
return 0 ;
}
int T_5 F_45 ( struct V_9 * V_7 ,
struct V_54 * V_47 )
{
struct V_2 * V_3 ;
if ( ! V_7 || ! V_47 )
return - V_14 ;
V_3 = V_7 -> V_2 ;
memcpy ( V_7 -> V_47 , V_47 , sizeof( struct V_54 ) ) ;
return 0 ;
}
static int T_6 F_46 ( void )
{
int V_46 ;
V_46 = F_1 ( V_1 ) ;
if ( V_46 ) {
F_9 ( L_10 , V_46 ) ;
goto V_55;
}
V_47 ( V_56 L_11 V_57 L_12 ) ;
V_55:
return V_46 ;
}
static void T_7 F_47 ( void )
{
F_2 () ;
}
