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
unsigned long V_18 ;
V_15 = & V_11 -> V_19 ;
V_15 -> V_20 = F_7 ( V_12 ) ;
V_15 -> V_21 = F_8 ( V_12 ) ;
V_15 -> V_22 = V_11 -> V_23 ;
V_17 = (struct V_16 * ) V_13 ;
V_15 -> V_24 = V_17 -> V_25 ;
memcpy ( V_11 -> V_23 , V_17 -> V_22 , V_15 -> V_24 ) ;
V_11 -> V_26 . V_27 = V_28 ;
V_11 -> V_26 . V_29 = V_30 ;
V_11 -> V_26 . V_22 [ 0 ] = 0 ;
V_10 = V_11 -> V_10 ;
F_9 ( & V_10 -> V_31 , V_18 ) ;
V_10 -> V_32 ++ ;
V_11 -> V_33 = V_10 -> V_32 ;
F_10 ( & V_10 -> V_31 , V_18 ) ;
}
static void F_11 ( struct V_1 * V_15 ,
T_2 * V_13 , int V_34 )
{
struct V_16 * V_17 ;
V_17 = (struct V_16 * ) V_13 ;
if ( ! V_34 && ! V_15 -> V_35 ) {
V_17 -> V_36 = V_37 ;
return;
}
if ( ! V_15 -> V_35 || ! V_15 -> V_38 ) {
V_17 -> V_36 = V_39 ;
return;
}
V_17 -> V_36 = V_40 ;
V_17 -> V_25 = V_15 -> V_38 ;
memcpy ( V_17 -> V_22 , V_15 -> V_41 , V_15 -> V_38 ) ;
}
static void F_12 ( struct V_2 * V_3 )
{
struct V_1 * V_11 , * V_42 ;
int V_43 = V_44 / 10 ;
struct V_5 * V_5 = V_3 -> V_5 ;
F_13 (tx_msg, temp, &ipmi->tx_msg_list, head) {
F_14 ( & V_11 -> V_8 ) ;
}
while ( V_43 -- ) {
if ( F_15 ( & V_3 -> V_45 ) )
break;
F_16 ( 1 ) ;
}
if ( ! F_15 ( & V_3 -> V_45 ) )
F_3 ( & V_5 -> V_7 , L_2 ) ;
}
static void F_17 ( struct V_46 * V_15 , void * V_47 )
{
struct V_2 * V_48 = V_47 ;
int V_49 = 0 ;
struct V_1 * V_11 ;
struct V_5 * V_5 = V_48 -> V_5 ;
unsigned long V_18 ;
if ( V_15 -> V_50 != V_48 -> V_51 ) {
F_3 ( & V_5 -> V_7 , L_3
L_4 ,
V_15 -> V_50 , V_48 -> V_51 ) ;
F_18 ( V_15 ) ;
return;
}
F_9 ( & V_48 -> V_31 , V_18 ) ;
F_19 (tx_msg, &ipmi_device->tx_msg_list, head) {
if ( V_15 -> V_52 == V_11 -> V_33 ) {
V_49 = 1 ;
break;
}
}
F_10 ( & V_48 -> V_31 , V_18 ) ;
if ( ! V_49 ) {
F_3 ( & V_5 -> V_7 , L_5
L_6 , V_15 -> V_52 ) ;
F_18 ( V_15 ) ;
return;
}
if ( V_15 -> V_15 . V_24 ) {
memcpy ( V_11 -> V_41 , V_15 -> V_53 , V_15 -> V_15 . V_24 ) ;
V_11 -> V_38 = V_15 -> V_15 . V_24 ;
V_11 -> V_35 = 1 ;
}
F_14 ( & V_11 -> V_8 ) ;
F_18 ( V_15 ) ;
}
static void F_20 ( int V_54 , struct V_10 * V_7 )
{
struct V_2 * V_48 , * V_42 ;
struct V_5 * V_5 ;
T_3 V_50 ;
int V_55 ;
struct V_56 V_57 ;
T_4 V_58 ;
V_55 = F_21 ( V_54 , & V_57 ) ;
if ( V_55 )
return;
if ( V_57 . V_59 != V_60 ) {
F_22 ( V_57 . V_7 ) ;
return;
}
V_58 = V_57 . V_61 . V_62 . T_4 ;
F_23 ( & V_63 . V_64 ) ;
F_19 (temp, &driver_data.ipmi_devices, head) {
if ( V_42 -> V_58 == V_58 )
goto V_65;
}
V_48 = F_2 ( sizeof( * V_48 ) , V_6 ) ;
if ( ! V_48 )
goto V_65;
V_5 = F_24 ( V_57 . V_7 ) ;
V_48 -> V_58 = V_58 ;
V_48 -> V_5 = V_5 ;
V_55 = F_25 ( V_54 , & V_63 . V_66 ,
V_48 , & V_50 ) ;
if ( V_55 ) {
F_3 ( & V_5 -> V_7 , L_7 ) ;
F_26 ( V_48 ) ;
goto V_65;
}
F_27 ( V_48 ) ;
V_48 -> V_51 = V_50 ;
V_48 -> V_67 = V_54 ;
F_28 ( & V_63 . V_64 ) ;
memcpy ( & V_48 -> V_57 , & V_57 , sizeof( struct V_56 ) ) ;
return;
V_65:
F_28 ( & V_63 . V_64 ) ;
F_22 ( V_57 . V_7 ) ;
return;
}
static void F_29 ( int V_54 )
{
struct V_2 * V_48 , * V_42 ;
F_23 ( & V_63 . V_64 ) ;
F_13 (ipmi_device, temp,
&driver_data.ipmi_devices, head) {
if ( V_48 -> V_67 != V_54 )
continue;
F_30 ( V_48 ) ;
F_22 ( V_48 -> V_57 . V_7 ) ;
F_26 ( V_48 ) ;
break;
}
F_28 ( & V_63 . V_64 ) ;
}
static T_5
F_31 ( T_6 V_68 , T_1 V_12 ,
T_6 V_69 , T_2 * V_13 ,
void * V_70 , void * V_71 )
{
struct V_1 * V_11 ;
struct V_2 * V_48 = V_70 ;
int V_55 , V_34 ;
T_5 V_36 ;
unsigned long V_18 ;
if ( ( V_68 & V_72 ) == V_73 )
return V_74 ;
if ( ! V_48 -> V_51 )
return V_75 ;
V_11 = F_1 ( V_48 ) ;
if ( ! V_11 )
return V_76 ;
F_6 ( V_11 , V_12 , V_13 ) ;
F_9 ( & V_48 -> V_31 , V_18 ) ;
F_32 ( & V_11 -> V_9 , & V_48 -> V_45 ) ;
F_10 ( & V_48 -> V_31 , V_18 ) ;
V_55 = F_33 ( V_48 -> V_51 ,
& V_11 -> V_26 ,
V_11 -> V_33 ,
& V_11 -> V_19 ,
NULL , 0 , 0 , 0 ) ;
if ( V_55 ) {
V_36 = V_77 ;
goto V_78;
}
V_34 = F_34 ( & V_11 -> V_8 ,
V_79 ) ;
F_11 ( V_11 , V_13 , V_34 ) ;
V_36 = V_80 ;
V_78:
F_9 ( & V_48 -> V_31 , V_18 ) ;
F_35 ( & V_11 -> V_9 ) ;
F_10 ( & V_48 -> V_31 , V_18 ) ;
F_26 ( V_11 ) ;
return V_36 ;
}
static void F_36 ( struct V_2 * V_3 )
{
if ( ! F_37 ( V_81 , & V_3 -> V_18 ) )
return;
F_38 ( V_3 -> V_58 ,
V_82 , & F_31 ) ;
F_39 ( V_81 , & V_3 -> V_18 ) ;
}
static int F_40 ( struct V_2 * V_3 )
{
T_5 V_36 ;
if ( F_37 ( V_81 , & V_3 -> V_18 ) )
return 0 ;
V_36 = F_41 ( V_3 -> V_58 ,
V_82 ,
& F_31 ,
NULL , V_3 ) ;
if ( F_42 ( V_36 ) ) {
struct V_5 * V_5 = V_3 -> V_5 ;
F_3 ( & V_5 -> V_7 , L_8
L_9 ) ;
return - V_83 ;
}
F_43 ( V_81 , & V_3 -> V_18 ) ;
return 0 ;
}
static void F_27 ( struct V_2 * V_48 )
{
F_5 ( & V_48 -> V_9 ) ;
F_44 ( & V_48 -> V_31 ) ;
F_5 ( & V_48 -> V_45 ) ;
F_40 ( V_48 ) ;
F_32 ( & V_48 -> V_9 , & V_63 . V_84 ) ;
}
static void F_30 ( struct V_2 * V_48 )
{
if ( V_48 -> V_51 ) {
F_45 ( V_48 -> V_51 ) ;
V_48 -> V_51 = NULL ;
}
if ( ! F_15 ( & V_48 -> V_45 ) )
F_12 ( V_48 ) ;
F_35 ( & V_48 -> V_9 ) ;
F_36 ( V_48 ) ;
}
static int T_7 F_46 ( void )
{
int V_85 = 0 ;
if ( V_86 )
return V_85 ;
F_47 ( & V_63 . V_64 ) ;
V_85 = F_48 ( & V_63 . V_87 ) ;
return V_85 ;
}
static void T_8 F_49 ( void )
{
struct V_2 * V_48 , * V_42 ;
if ( V_86 )
return;
F_50 ( & V_63 . V_87 ) ;
F_23 ( & V_63 . V_64 ) ;
F_13 (ipmi_device, temp,
&driver_data.ipmi_devices, head) {
F_30 ( V_48 ) ;
F_22 ( V_48 -> V_57 . V_7 ) ;
F_26 ( V_48 ) ;
}
F_28 ( & V_63 . V_64 ) ;
}
