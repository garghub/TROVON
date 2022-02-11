static struct V_1 *
F_1 ( int V_2 , struct V_3 * V_4 , T_1 V_5 )
{
struct V_1 * V_6 ;
int V_7 ;
T_2 V_8 ;
V_6 = F_2 ( sizeof( * V_6 ) , V_9 ) ;
if ( ! V_6 )
return NULL ;
F_3 ( & V_6 -> V_10 ) ;
F_4 ( & V_6 -> V_11 ) ;
F_4 ( & V_6 -> V_12 ) ;
F_5 ( & V_6 -> V_13 ) ;
V_6 -> V_5 = V_5 ;
V_6 -> V_4 = F_6 ( V_4 ) ;
V_6 -> V_14 = V_2 ;
V_7 = F_7 ( V_2 , & V_15 . V_16 ,
V_6 , & V_8 ) ;
if ( V_7 ) {
F_8 ( V_4 ) ;
F_9 ( V_6 ) ;
return NULL ;
}
V_6 -> V_17 = V_8 ;
return V_6 ;
}
static void F_10 ( struct V_1 * V_6 )
{
F_11 ( V_6 -> V_17 ) ;
F_8 ( V_6 -> V_4 ) ;
F_9 ( V_6 ) ;
}
static void F_12 ( struct V_10 * V_10 )
{
struct V_1 * V_18 =
F_13 ( V_10 , struct V_1 , V_10 ) ;
F_10 ( V_18 ) ;
}
static void F_14 ( struct V_1 * V_6 )
{
F_15 ( & V_6 -> V_11 ) ;
if ( V_15 . V_19 == V_6 )
V_15 . V_19 = NULL ;
V_6 -> V_20 = true ;
}
static struct V_1 * F_16 ( void )
{
struct V_1 * V_6 = NULL ;
F_17 ( & V_15 . V_21 ) ;
if ( V_15 . V_19 ) {
V_6 = V_15 . V_19 ;
F_18 ( & V_6 -> V_10 ) ;
}
F_19 ( & V_15 . V_21 ) ;
return V_6 ;
}
static void F_20 ( struct V_1 * V_6 )
{
F_21 ( & V_6 -> V_10 , F_12 ) ;
}
static struct V_22 * F_22 ( void )
{
struct V_1 * V_18 ;
struct V_22 * V_23 ;
V_18 = F_16 () ;
if ( ! V_18 )
return NULL ;
V_23 = F_2 ( sizeof( struct V_22 ) , V_9 ) ;
if ( ! V_23 ) {
F_20 ( V_18 ) ;
return NULL ;
}
F_3 ( & V_23 -> V_10 ) ;
F_23 ( & V_23 -> V_24 ) ;
F_4 ( & V_23 -> V_11 ) ;
V_23 -> V_3 = V_18 ;
V_23 -> V_25 = V_26 ;
return V_23 ;
}
static void F_24 ( struct V_22 * V_27 )
{
F_20 ( V_27 -> V_3 ) ;
F_9 ( V_27 ) ;
}
static void F_25 ( struct V_10 * V_10 )
{
struct V_22 * V_27 =
F_13 ( V_10 , struct V_22 , V_10 ) ;
F_24 ( V_27 ) ;
}
static struct V_22 * F_26 ( struct V_22 * V_27 )
{
F_18 ( & V_27 -> V_10 ) ;
return V_27 ;
}
static void F_27 ( struct V_22 * V_27 )
{
F_21 ( & V_27 -> V_10 , F_25 ) ;
}
static int F_28 ( struct V_22 * V_27 ,
T_3 V_28 ,
T_4 * V_29 )
{
struct V_30 * V_31 ;
struct V_32 * V_33 ;
struct V_1 * V_3 ;
unsigned long V_34 ;
V_31 = & V_27 -> V_35 ;
V_31 -> V_36 = F_29 ( V_28 ) ;
V_31 -> V_37 = F_30 ( V_28 ) ;
V_31 -> V_38 = V_27 -> V_38 ;
V_33 = (struct V_32 * ) V_29 ;
if ( V_33 -> V_39 > V_40 ) {
F_31 ( V_27 -> V_3 -> V_4 , true ,
L_1 ,
V_33 -> V_39 ) ;
return - V_41 ;
}
V_31 -> V_42 = V_33 -> V_39 ;
memcpy ( V_27 -> V_38 , V_33 -> V_38 , V_31 -> V_42 ) ;
V_27 -> V_43 . V_44 = V_45 ;
V_27 -> V_43 . V_46 = V_47 ;
V_27 -> V_43 . V_38 [ 0 ] = 0 ;
V_3 = V_27 -> V_3 ;
F_32 ( & V_3 -> V_13 , V_34 ) ;
V_3 -> V_48 ++ ;
V_27 -> V_49 = V_3 -> V_48 ;
F_33 ( & V_3 -> V_13 , V_34 ) ;
return 0 ;
}
static void F_34 ( struct V_22 * V_31 ,
T_4 * V_29 )
{
struct V_32 * V_33 ;
V_33 = (struct V_32 * ) V_29 ;
V_33 -> V_50 = V_31 -> V_25 ;
if ( V_31 -> V_25 != V_51 )
return;
V_33 -> V_39 = V_31 -> V_52 ;
memcpy ( V_33 -> V_38 , V_31 -> V_38 , V_31 -> V_52 ) ;
}
static void F_35 ( struct V_1 * V_18 )
{
struct V_22 * V_27 ;
unsigned long V_34 ;
F_32 ( & V_18 -> V_13 , V_34 ) ;
while ( ! F_36 ( & V_18 -> V_12 ) ) {
V_27 = F_37 ( & V_18 -> V_12 ,
struct V_22 ,
V_11 ) ;
F_15 ( & V_27 -> V_11 ) ;
F_33 ( & V_18 -> V_13 , V_34 ) ;
F_38 ( & V_27 -> V_24 ) ;
F_27 ( V_27 ) ;
F_32 ( & V_18 -> V_13 , V_34 ) ;
}
F_33 ( & V_18 -> V_13 , V_34 ) ;
}
static void F_39 ( struct V_1 * V_18 ,
struct V_22 * V_31 )
{
struct V_22 * V_27 , * V_53 ;
bool V_54 = false ;
unsigned long V_34 ;
F_32 ( & V_18 -> V_13 , V_34 ) ;
F_40 (tx_msg, temp, &ipmi->tx_msg_list, head) {
if ( V_31 == V_27 ) {
V_54 = true ;
F_15 ( & V_27 -> V_11 ) ;
break;
}
}
F_33 ( & V_18 -> V_13 , V_34 ) ;
if ( V_54 )
F_27 ( V_27 ) ;
}
static void F_41 ( struct V_55 * V_31 , void * V_56 )
{
struct V_1 * V_6 = V_56 ;
bool V_54 = false ;
struct V_22 * V_27 , * V_53 ;
struct V_3 * V_4 = V_6 -> V_4 ;
unsigned long V_34 ;
if ( V_31 -> V_8 != V_6 -> V_17 ) {
F_42 ( V_4 ,
L_2 ,
V_31 -> V_8 , V_6 -> V_17 ) ;
goto V_57;
}
F_32 ( & V_6 -> V_13 , V_34 ) ;
F_40 (tx_msg, temp, &ipmi_device->tx_msg_list, head) {
if ( V_31 -> V_58 == V_27 -> V_49 ) {
V_54 = true ;
F_15 ( & V_27 -> V_11 ) ;
break;
}
}
F_33 ( & V_6 -> V_13 , V_34 ) ;
if ( ! V_54 ) {
F_42 ( V_4 ,
L_3 ,
V_31 -> V_58 ) ;
goto V_57;
}
if ( V_31 -> V_31 . V_42 > V_40 ) {
F_31 ( V_4 , true ,
L_4 ,
V_31 -> V_31 . V_42 ) ;
goto V_59;
}
V_31 -> V_60 = V_61 ;
if ( V_31 -> V_60 == V_61 &&
V_31 -> V_31 . V_42 == 1 ) {
if ( V_31 -> V_31 . V_38 [ 0 ] == V_62 ) {
F_43 ( V_4 , L_5 ) ;
V_27 -> V_25 = V_63 ;
}
goto V_59;
}
V_27 -> V_52 = V_31 -> V_31 . V_42 ;
memcpy ( V_27 -> V_38 , V_31 -> V_31 . V_38 , V_27 -> V_52 ) ;
V_27 -> V_25 = V_51 ;
V_59:
F_38 ( & V_27 -> V_24 ) ;
F_27 ( V_27 ) ;
V_57:
F_44 ( V_31 ) ;
}
static void F_45 ( int V_2 , struct V_3 * V_4 )
{
struct V_1 * V_6 , * V_53 ;
int V_7 ;
struct V_64 V_65 ;
T_1 V_5 ;
V_7 = F_46 ( V_2 , & V_65 ) ;
if ( V_7 )
return;
if ( V_65 . V_66 != V_67 )
goto V_68;
V_5 = V_65 . V_69 . V_70 . T_1 ;
if ( ! V_5 )
goto V_68;
V_6 = F_1 ( V_2 , V_65 . V_4 , V_5 ) ;
if ( ! V_6 ) {
F_42 ( V_65 . V_4 , L_6 ) ;
goto V_68;
}
F_17 ( & V_15 . V_21 ) ;
F_47 (temp, &driver_data.ipmi_devices, head) {
if ( V_53 -> V_5 == V_5 )
goto V_71;
}
if ( ! V_15 . V_19 )
V_15 . V_19 = V_6 ;
F_48 ( & V_6 -> V_11 , & V_15 . V_72 ) ;
F_19 ( & V_15 . V_21 ) ;
F_8 ( V_65 . V_4 ) ;
return;
V_71:
F_19 ( & V_15 . V_21 ) ;
F_10 ( V_6 ) ;
V_68:
F_8 ( V_65 . V_4 ) ;
return;
}
static void F_49 ( int V_2 )
{
struct V_1 * V_6 , * V_53 ;
bool V_73 = false ;
F_17 ( & V_15 . V_21 ) ;
F_40 (ipmi_device, temp,
&driver_data.ipmi_devices, head) {
if ( V_6 -> V_14 != V_2 ) {
V_73 = true ;
F_14 ( V_6 ) ;
break;
}
}
if ( ! V_15 . V_19 )
V_15 . V_19 = F_50 (
& V_15 . V_72 ,
struct V_1 , V_11 ) ;
F_19 ( & V_15 . V_21 ) ;
if ( V_73 ) {
F_35 ( V_6 ) ;
F_20 ( V_6 ) ;
}
}
static T_5
F_51 ( T_6 V_74 , T_3 V_28 ,
T_6 V_75 , T_4 * V_29 ,
void * V_76 , void * V_77 )
{
struct V_22 * V_27 ;
struct V_1 * V_6 ;
int V_7 ;
T_5 V_50 ;
unsigned long V_34 ;
if ( ( V_74 & V_78 ) == V_79 )
return V_80 ;
V_27 = F_22 () ;
if ( ! V_27 )
return V_81 ;
V_6 = V_27 -> V_3 ;
if ( F_28 ( V_27 , V_28 , V_29 ) != 0 ) {
F_24 ( V_27 ) ;
return V_80 ;
}
F_26 ( V_27 ) ;
F_17 ( & V_15 . V_21 ) ;
if ( V_6 -> V_20 ) {
F_19 ( & V_15 . V_21 ) ;
F_24 ( V_27 ) ;
return V_81 ;
}
F_32 ( & V_6 -> V_13 , V_34 ) ;
F_48 ( & V_27 -> V_11 , & V_6 -> V_12 ) ;
F_33 ( & V_6 -> V_13 , V_34 ) ;
F_19 ( & V_15 . V_21 ) ;
V_7 = F_52 ( V_6 -> V_17 ,
& V_27 -> V_43 ,
V_27 -> V_49 ,
& V_27 -> V_35 ,
NULL , 0 , 0 , V_82 ) ;
if ( V_7 ) {
V_50 = V_83 ;
goto V_57;
}
F_53 ( & V_27 -> V_24 ) ;
F_34 ( V_27 , V_29 ) ;
V_50 = V_84 ;
V_57:
F_39 ( V_6 , V_27 ) ;
F_27 ( V_27 ) ;
return V_50 ;
}
static int T_7 F_54 ( void )
{
int V_85 ;
T_5 V_50 ;
if ( V_86 )
return 0 ;
V_50 = F_55 ( V_87 ,
V_88 ,
& F_51 ,
NULL , NULL ) ;
if ( F_56 ( V_50 ) ) {
F_57 ( L_7 ) ;
return - V_41 ;
}
V_85 = F_58 ( & V_15 . V_89 ) ;
if ( V_85 )
F_59 ( L_8 ) ;
return V_85 ;
}
static void T_8 F_60 ( void )
{
struct V_1 * V_6 ;
if ( V_86 )
return;
F_61 ( & V_15 . V_89 ) ;
F_17 ( & V_15 . V_21 ) ;
while ( ! F_36 ( & V_15 . V_72 ) ) {
V_6 = F_37 ( & V_15 . V_72 ,
struct V_1 ,
V_11 ) ;
F_14 ( V_6 ) ;
F_19 ( & V_15 . V_21 ) ;
F_35 ( V_6 ) ;
F_20 ( V_6 ) ;
F_17 ( & V_15 . V_21 ) ;
}
F_19 ( & V_15 . V_21 ) ;
F_62 ( V_87 ,
V_88 ,
& F_51 ) ;
}
