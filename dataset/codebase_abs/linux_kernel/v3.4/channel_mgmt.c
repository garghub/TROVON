void F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 , T_1 * V_5 )
{
if ( V_2 -> V_6 == V_7 ) {
V_2 -> V_8 = 0x10 ;
V_4 = (struct V_3 * ) & V_5 [
sizeof( struct V_9 ) +
sizeof( struct V_1 ) ] ;
if ( V_4 -> V_10 == 2 &&
V_4 -> V_11 [ 1 ] . V_12 == 3 ) {
V_4 -> V_11 [ 0 ] . V_12 = 3 ;
V_4 -> V_11 [ 0 ] . V_13 = 0 ;
V_4 -> V_11 [ 1 ] . V_12 = 3 ;
V_4 -> V_11 [ 1 ] . V_13 = 0 ;
} else {
V_4 -> V_11 [ 0 ] . V_12 = 1 ;
V_4 -> V_11 [ 0 ] . V_13 = 0 ;
V_4 -> V_11 [ 1 ] . V_12 = 1 ;
V_4 -> V_11 [ 1 ] . V_13 = 0 ;
}
V_4 -> V_10 = 1 ;
V_4 -> V_14 = 1 ;
}
}
static struct V_15 * F_2 ( void )
{
struct V_15 * V_16 ;
V_16 = F_3 ( sizeof( * V_16 ) , V_17 ) ;
if ( ! V_16 )
return NULL ;
F_4 ( & V_16 -> V_18 ) ;
V_16 -> V_19 = F_5 ( L_1 ) ;
if ( ! V_16 -> V_19 ) {
F_6 ( V_16 ) ;
return NULL ;
}
return V_16 ;
}
static void F_7 ( struct V_20 * V_21 )
{
struct V_15 * V_16 = F_8 ( V_21 ,
struct V_15 ,
V_21 ) ;
F_9 ( V_16 -> V_19 ) ;
F_6 ( V_16 ) ;
}
static void F_10 ( struct V_15 * V_16 )
{
F_11 ( & V_16 -> V_21 , F_7 ) ;
F_12 ( V_22 . V_23 , & V_16 -> V_21 ) ;
}
static void F_13 ( struct V_20 * V_21 )
{
struct V_15 * V_16 = F_8 ( V_21 ,
struct V_15 ,
V_21 ) ;
F_14 ( V_16 -> V_24 ) ;
}
void F_15 ( void )
{
struct V_15 * V_16 ;
F_16 (channel, &vmbus_connection.chn_list, listentry) {
F_14 ( V_16 -> V_24 ) ;
F_6 ( V_16 -> V_24 ) ;
F_10 ( V_16 ) ;
}
}
static void F_17 ( struct V_20 * V_21 )
{
struct V_15 * V_25 = F_8 ( V_21 ,
struct V_15 ,
V_21 ) ;
struct V_15 * V_16 ;
bool V_26 = true ;
int V_27 ;
unsigned long V_28 ;
F_11 ( & V_25 -> V_21 , F_13 ) ;
F_18 ( & V_22 . V_29 , V_28 ) ;
F_16 (channel, &vmbus_connection.chn_list, listentry) {
if ( ! F_19 ( V_16 -> V_30 . V_31 . V_32 ,
V_25 -> V_30 . V_31 . V_32 ) &&
! F_19 ( V_16 -> V_30 . V_31 . V_33 ,
V_25 -> V_30 . V_31 . V_33 ) ) {
V_26 = false ;
break;
}
}
if ( V_26 )
F_20 ( & V_25 -> V_34 ,
& V_22 . V_35 ) ;
F_21 ( & V_22 . V_29 , V_28 ) ;
if ( ! V_26 ) {
F_10 ( V_25 ) ;
return;
}
V_25 -> V_24 = F_22 (
& V_25 -> V_30 . V_31 . V_32 ,
& V_25 -> V_30 . V_31 . V_33 ,
V_25 ) ;
V_27 = F_23 ( V_25 -> V_24 ) ;
if ( V_27 != 0 ) {
F_24 ( L_2 ,
V_25 -> V_30 . V_36 ) ;
F_18 ( & V_22 . V_29 , V_28 ) ;
F_25 ( & V_25 -> V_34 ) ;
F_21 ( & V_22 . V_29 , V_28 ) ;
F_6 ( V_25 -> V_24 ) ;
F_10 ( V_25 ) ;
} else {
V_25 -> V_37 = V_38 ;
}
}
static void F_26 ( struct V_39 * V_40 )
{
struct V_41 * V_31 ;
struct V_15 * V_25 ;
T_2 * V_42 ;
T_2 * V_43 ;
V_31 = (struct V_41 * ) V_40 ;
V_42 = & V_31 -> V_31 . V_32 ;
V_43 = & V_31 -> V_31 . V_33 ;
V_25 = F_2 () ;
if ( ! V_25 ) {
F_24 ( L_3 ) ;
return;
}
memcpy ( & V_25 -> V_30 , V_31 ,
sizeof( struct V_41 ) ) ;
V_25 -> V_44 = ( T_1 ) V_31 -> V_45 / 32 ;
V_25 -> V_46 = ( T_1 ) V_31 -> V_45 % 32 ;
F_11 ( & V_25 -> V_21 , F_17 ) ;
F_12 ( V_25 -> V_19 , & V_25 -> V_21 ) ;
}
static void F_27 ( struct V_39 * V_40 )
{
struct V_47 * V_48 ;
struct V_15 * V_16 ;
V_48 = (struct V_47 * ) V_40 ;
V_16 = F_28 ( V_48 -> V_36 ) ;
if ( V_16 == NULL )
return;
F_12 ( V_16 -> V_19 , & V_16 -> V_21 ) ;
}
static void F_29 (
struct V_39 * V_40 )
{
}
static void F_30 ( struct V_39 * V_40 )
{
struct V_49 * V_50 ;
struct V_51 * V_52 ;
struct V_39 * V_53 ;
struct V_54 * V_55 ;
unsigned long V_28 ;
V_50 = (struct V_49 * ) V_40 ;
F_18 ( & V_22 . V_56 , V_28 ) ;
F_16 (msginfo, &vmbus_connection.chn_msg_list,
msglistentry) {
V_53 =
(struct V_39 * ) V_52 -> V_57 ;
if ( V_53 -> V_58 == V_59 ) {
V_55 =
(struct V_54 * ) V_52 -> V_57 ;
if ( V_55 -> V_36 == V_50 -> V_36 &&
V_55 -> V_60 == V_50 -> V_60 ) {
memcpy ( & V_52 -> V_61 . V_62 ,
V_50 ,
sizeof(
struct V_49 ) ) ;
F_31 ( & V_52 -> V_63 ) ;
break;
}
}
}
F_21 ( & V_22 . V_56 , V_28 ) ;
}
static void F_32 ( struct V_39 * V_40 )
{
struct V_64 * V_65 ;
struct V_51 * V_52 ;
struct V_39 * V_53 ;
struct V_66 * V_67 ;
unsigned long V_28 ;
V_65 = (struct V_64 * ) V_40 ;
F_18 ( & V_22 . V_56 , V_28 ) ;
F_16 (msginfo, &vmbus_connection.chn_msg_list,
msglistentry) {
V_53 =
(struct V_39 * ) V_52 -> V_57 ;
if ( V_53 -> V_58 == V_68 ) {
V_67 =
(struct V_66 * ) V_53 ;
if ( ( V_65 -> V_36 ==
V_67 -> V_36 ) &&
( V_65 -> V_69 == V_67 -> V_69 ) ) {
memcpy ( & V_52 -> V_61 . V_70 ,
V_65 ,
sizeof(
struct V_64 ) ) ;
F_31 ( & V_52 -> V_63 ) ;
break;
}
}
}
F_21 ( & V_22 . V_56 , V_28 ) ;
}
static void F_33 (
struct V_39 * V_40 )
{
struct V_71 * V_72 ;
struct V_51 * V_52 ;
struct V_39 * V_53 ;
struct V_73 * V_74 ;
unsigned long V_28 ;
V_72 = (struct V_71 * ) V_40 ;
F_18 ( & V_22 . V_56 , V_28 ) ;
F_16 (msginfo, &vmbus_connection.chn_msg_list,
msglistentry) {
V_53 =
(struct V_39 * ) V_52 -> V_57 ;
if ( V_53 -> V_58 == V_75 ) {
V_74 =
(struct V_73 * ) V_53 ;
if ( V_72 -> V_69 == V_74 -> V_69 ) {
memcpy ( & V_52 -> V_61 . V_72 ,
V_72 ,
sizeof(
struct V_71 ) ) ;
F_31 ( & V_52 -> V_63 ) ;
break;
}
}
}
F_21 ( & V_22 . V_56 , V_28 ) ;
}
static void F_34 (
struct V_39 * V_40 )
{
struct V_51 * V_52 ;
struct V_39 * V_53 ;
struct V_76 * V_77 ;
struct V_78 * V_79 ;
unsigned long V_28 ;
V_79 = (struct V_78 * ) V_40 ;
F_18 ( & V_22 . V_56 , V_28 ) ;
F_16 (msginfo, &vmbus_connection.chn_msg_list,
msglistentry) {
V_53 =
(struct V_39 * ) V_52 -> V_57 ;
if ( V_53 -> V_58 ==
V_80 ) {
V_77 =
(struct V_76 * ) V_53 ;
memcpy ( & V_52 -> V_61 . V_79 ,
V_79 ,
sizeof( struct V_78 ) ) ;
F_31 ( & V_52 -> V_63 ) ;
}
}
F_21 ( & V_22 . V_56 , V_28 ) ;
}
void F_35 ( void * V_81 )
{
struct V_82 * V_57 = V_81 ;
struct V_39 * V_40 ;
int V_83 ;
V_40 = (struct V_39 * ) V_57 -> V_84 . V_85 ;
V_83 = V_57 -> V_86 . V_87 ;
if ( V_40 -> V_58 >= V_88 ) {
F_24 ( L_4 ,
V_40 -> V_58 , V_83 ) ;
F_36 ( L_5 , V_89 ,
( unsigned char * ) V_57 -> V_84 . V_85 , V_83 ) ;
return;
}
if ( V_90 [ V_40 -> V_58 ] . V_91 )
V_90 [ V_40 -> V_58 ] . V_91 ( V_40 ) ;
else
F_24 ( L_6 , V_40 -> V_58 ) ;
}
int F_37 ( void )
{
struct V_39 * V_57 ;
struct V_51 * V_52 ;
int V_27 , V_92 ;
V_52 = F_38 ( sizeof( * V_52 ) +
sizeof( struct V_39 ) ,
V_93 ) ;
if ( ! V_52 )
return - V_94 ;
F_39 ( & V_52 -> V_63 ) ;
V_57 = (struct V_39 * ) V_52 -> V_57 ;
V_57 -> V_58 = V_95 ;
V_27 = F_40 ( V_57 ,
sizeof( struct V_39 ) ) ;
if ( V_27 != 0 ) {
F_24 ( L_7 , V_27 ) ;
goto V_96;
}
V_92 = F_41 ( & V_52 -> V_63 , 5 * V_97 ) ;
if ( V_92 == 0 ) {
V_27 = - V_98 ;
goto V_96;
}
V_96:
F_6 ( V_52 ) ;
return V_27 ;
}
