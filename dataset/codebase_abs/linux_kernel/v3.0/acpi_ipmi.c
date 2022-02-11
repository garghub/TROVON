static struct V_1 * F_1 ( struct V_2 * V_3 )
{
struct V_1 * V_4 ;
struct V_5 * V_5 = V_3 -> V_5 ;
V_4 = F_2 ( sizeof( struct V_1 ) , V_6 ) ;
if ( ! V_4 ) {
F_3 ( & V_5 -> V_7 , L_1 ) ;
return NULL ;
}
F_4 ( & V_4 -> V_8 ) ;
F_5 ( & V_4 -> V_9 ) ;
V_4 -> V_10 = V_3 ;
return V_4 ;
}
static void F_6 ( struct V_1 * V_11 ,
T_1 V_12 ,
T_2 * V_13 )
{
struct V_14 * V_15 ;
struct V_16 * V_17 ;
struct V_2 * V_10 ;
V_15 = & V_11 -> V_18 ;
V_15 -> V_19 = F_7 ( V_12 ) ;
V_15 -> V_20 = F_8 ( V_12 ) ;
V_15 -> V_21 = V_11 -> V_22 ;
V_17 = (struct V_16 * ) V_13 ;
V_15 -> V_23 = V_17 -> V_24 ;
memcpy ( V_11 -> V_22 , V_17 -> V_21 , V_15 -> V_23 ) ;
V_11 -> V_25 . V_26 = V_27 ;
V_11 -> V_25 . V_28 = V_29 ;
V_11 -> V_25 . V_21 [ 0 ] = 0 ;
V_10 = V_11 -> V_10 ;
F_9 ( & V_10 -> V_30 ) ;
V_10 -> V_31 ++ ;
V_11 -> V_32 = V_10 -> V_31 ;
F_10 ( & V_10 -> V_30 ) ;
}
static void F_11 ( struct V_1 * V_15 ,
T_2 * V_13 , int V_33 )
{
struct V_16 * V_17 ;
V_17 = (struct V_16 * ) V_13 ;
if ( ! V_33 && ! V_15 -> V_34 ) {
V_17 -> V_35 = V_36 ;
return;
}
if ( ! V_15 -> V_34 || ! V_15 -> V_37 ) {
V_17 -> V_35 = V_38 ;
return;
}
V_17 -> V_35 = V_39 ;
V_17 -> V_24 = V_15 -> V_37 ;
memcpy ( V_17 -> V_21 , V_15 -> V_40 , V_15 -> V_37 ) ;
}
static void F_12 ( struct V_2 * V_3 )
{
struct V_1 * V_11 , * V_41 ;
int V_42 = V_43 / 10 ;
struct V_5 * V_5 = V_3 -> V_5 ;
F_13 (tx_msg, temp, &ipmi->tx_msg_list, head) {
F_14 ( & V_11 -> V_8 ) ;
}
while ( V_42 -- ) {
if ( F_15 ( & V_3 -> V_44 ) )
break;
F_16 ( 1 ) ;
}
if ( ! F_15 ( & V_3 -> V_44 ) )
F_3 ( & V_5 -> V_7 , L_2 ) ;
}
static void F_17 ( struct V_45 * V_15 , void * V_46 )
{
struct V_2 * V_47 = V_46 ;
int V_48 = 0 ;
struct V_1 * V_11 ;
struct V_5 * V_5 = V_47 -> V_5 ;
if ( V_15 -> V_49 != V_47 -> V_50 ) {
F_3 ( & V_5 -> V_7 , L_3
L_4 ,
V_15 -> V_49 , V_47 -> V_50 ) ;
F_18 ( V_15 ) ;
return;
}
F_9 ( & V_47 -> V_30 ) ;
F_19 (tx_msg, &ipmi_device->tx_msg_list, head) {
if ( V_15 -> V_51 == V_11 -> V_32 ) {
V_48 = 1 ;
break;
}
}
F_10 ( & V_47 -> V_30 ) ;
if ( ! V_48 ) {
F_3 ( & V_5 -> V_7 , L_5
L_6 , V_15 -> V_51 ) ;
F_18 ( V_15 ) ;
return;
}
if ( V_15 -> V_15 . V_23 ) {
memcpy ( V_11 -> V_40 , V_15 -> V_52 , V_15 -> V_15 . V_23 ) ;
V_11 -> V_37 = V_15 -> V_15 . V_23 ;
V_11 -> V_34 = 1 ;
}
F_14 ( & V_11 -> V_8 ) ;
F_18 ( V_15 ) ;
}
static void F_20 ( int V_53 , struct V_10 * V_7 )
{
struct V_2 * V_47 , * V_41 ;
struct V_5 * V_5 ;
T_3 V_49 ;
int V_54 ;
struct V_55 V_56 ;
T_4 V_57 ;
V_54 = F_21 ( V_53 , & V_56 ) ;
if ( V_54 )
return;
if ( V_56 . V_58 != V_59 ) {
F_22 ( V_56 . V_7 ) ;
return;
}
V_57 = V_56 . V_60 . V_61 . T_4 ;
F_9 ( & V_62 . V_63 ) ;
F_19 (temp, &driver_data.ipmi_devices, head) {
if ( V_41 -> V_57 == V_57 )
goto V_64;
}
V_47 = F_2 ( sizeof( * V_47 ) , V_6 ) ;
if ( ! V_47 )
goto V_64;
V_5 = F_23 ( V_56 . V_7 ) ;
V_47 -> V_57 = V_57 ;
V_47 -> V_5 = V_5 ;
V_54 = F_24 ( V_53 , & V_62 . V_65 ,
V_47 , & V_49 ) ;
if ( V_54 ) {
F_3 ( & V_5 -> V_7 , L_7 ) ;
F_25 ( V_47 ) ;
goto V_64;
}
F_26 ( V_47 ) ;
V_47 -> V_50 = V_49 ;
V_47 -> V_66 = V_53 ;
F_10 ( & V_62 . V_63 ) ;
memcpy ( & V_47 -> V_56 , & V_56 , sizeof( struct V_55 ) ) ;
return;
V_64:
F_10 ( & V_62 . V_63 ) ;
F_22 ( V_56 . V_7 ) ;
return;
}
static void F_27 ( int V_53 )
{
struct V_2 * V_47 , * V_41 ;
F_9 ( & V_62 . V_63 ) ;
F_13 (ipmi_device, temp,
&driver_data.ipmi_devices, head) {
if ( V_47 -> V_66 != V_53 )
continue;
F_28 ( V_47 ) ;
F_22 ( V_47 -> V_56 . V_7 ) ;
F_25 ( V_47 ) ;
break;
}
F_10 ( & V_62 . V_63 ) ;
}
static T_5
F_29 ( T_6 V_67 , T_1 V_12 ,
T_6 V_68 , T_2 * V_13 ,
void * V_69 , void * V_70 )
{
struct V_1 * V_11 ;
struct V_2 * V_47 = V_69 ;
int V_54 , V_33 ;
T_5 V_35 ;
if ( ( V_67 & V_71 ) == V_72 )
return V_73 ;
if ( ! V_47 -> V_50 )
return V_74 ;
V_11 = F_1 ( V_47 ) ;
if ( ! V_11 )
return V_75 ;
F_6 ( V_11 , V_12 , V_13 ) ;
F_9 ( & V_47 -> V_30 ) ;
F_30 ( & V_11 -> V_9 , & V_47 -> V_44 ) ;
F_10 ( & V_47 -> V_30 ) ;
V_54 = F_31 ( V_47 -> V_50 ,
& V_11 -> V_25 ,
V_11 -> V_32 ,
& V_11 -> V_18 ,
NULL , 0 , 0 , 0 ) ;
if ( V_54 ) {
V_35 = V_76 ;
goto V_77;
}
V_33 = F_32 ( & V_11 -> V_8 ,
V_78 ) ;
F_11 ( V_11 , V_13 , V_33 ) ;
V_35 = V_79 ;
V_77:
F_9 ( & V_47 -> V_30 ) ;
F_33 ( & V_11 -> V_9 ) ;
F_10 ( & V_47 -> V_30 ) ;
F_25 ( V_11 ) ;
return V_35 ;
}
static void F_34 ( struct V_2 * V_3 )
{
if ( ! F_35 ( V_80 , & V_3 -> V_81 ) )
return;
F_36 ( V_3 -> V_57 ,
V_82 , & F_29 ) ;
F_37 ( V_80 , & V_3 -> V_81 ) ;
}
static int F_38 ( struct V_2 * V_3 )
{
T_5 V_35 ;
if ( F_35 ( V_80 , & V_3 -> V_81 ) )
return 0 ;
V_35 = F_39 ( V_3 -> V_57 ,
V_82 ,
& F_29 ,
NULL , V_3 ) ;
if ( F_40 ( V_35 ) ) {
struct V_5 * V_5 = V_3 -> V_5 ;
F_3 ( & V_5 -> V_7 , L_8
L_9 ) ;
return - V_83 ;
}
F_41 ( V_80 , & V_3 -> V_81 ) ;
return 0 ;
}
static void F_26 ( struct V_2 * V_47 )
{
F_5 ( & V_47 -> V_9 ) ;
F_42 ( & V_47 -> V_30 ) ;
F_5 ( & V_47 -> V_44 ) ;
F_38 ( V_47 ) ;
F_30 ( & V_47 -> V_9 , & V_62 . V_84 ) ;
}
static void F_28 ( struct V_2 * V_47 )
{
if ( V_47 -> V_50 ) {
F_43 ( V_47 -> V_50 ) ;
V_47 -> V_50 = NULL ;
}
if ( ! F_15 ( & V_47 -> V_44 ) )
F_12 ( V_47 ) ;
F_33 ( & V_47 -> V_9 ) ;
F_34 ( V_47 ) ;
}
static int T_7 F_44 ( void )
{
int V_85 = 0 ;
if ( V_86 )
return V_85 ;
F_42 ( & V_62 . V_63 ) ;
V_85 = F_45 ( & V_62 . V_87 ) ;
return V_85 ;
}
static void T_8 F_46 ( void )
{
struct V_2 * V_47 , * V_41 ;
if ( V_86 )
return;
F_47 ( & V_62 . V_87 ) ;
F_9 ( & V_62 . V_63 ) ;
F_13 (ipmi_device, temp,
&driver_data.ipmi_devices, head) {
F_28 ( V_47 ) ;
F_22 ( V_47 -> V_56 . V_7 ) ;
F_25 ( V_47 ) ;
}
F_10 ( & V_62 . V_63 ) ;
}
