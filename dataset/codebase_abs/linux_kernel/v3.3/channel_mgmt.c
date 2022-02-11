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
int V_44 ;
int V_45 = 0 ;
V_31 = (struct V_41 * ) V_40 ;
for ( V_44 = 0 ; V_44 < V_46 ; V_44 ++ ) {
if ( ! F_19 ( V_31 -> V_31 . V_32 ,
V_47 [ V_44 ] ) ) {
V_45 = 1 ;
break;
}
}
if ( ! V_45 )
return;
V_42 = & V_31 -> V_31 . V_32 ;
V_43 = & V_31 -> V_31 . V_33 ;
V_25 = F_2 () ;
if ( ! V_25 ) {
F_24 ( L_3 ) ;
return;
}
memcpy ( & V_25 -> V_30 , V_31 ,
sizeof( struct V_41 ) ) ;
V_25 -> V_48 = ( T_1 ) V_31 -> V_49 / 32 ;
V_25 -> V_50 = ( T_1 ) V_31 -> V_49 % 32 ;
F_11 ( & V_25 -> V_21 , F_17 ) ;
F_12 ( V_25 -> V_19 , & V_25 -> V_21 ) ;
}
static void F_27 ( struct V_39 * V_40 )
{
struct V_51 * V_52 ;
struct V_15 * V_16 ;
V_52 = (struct V_51 * ) V_40 ;
V_16 = F_28 ( V_52 -> V_36 ) ;
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
struct V_53 * V_54 ;
struct V_55 * V_56 ;
struct V_39 * V_57 ;
struct V_58 * V_59 ;
unsigned long V_28 ;
V_54 = (struct V_53 * ) V_40 ;
F_18 ( & V_22 . V_60 , V_28 ) ;
F_16 (msginfo, &vmbus_connection.chn_msg_list,
msglistentry) {
V_57 =
(struct V_39 * ) V_56 -> V_61 ;
if ( V_57 -> V_62 == V_63 ) {
V_59 =
(struct V_58 * ) V_56 -> V_61 ;
if ( V_59 -> V_36 == V_54 -> V_36 &&
V_59 -> V_64 == V_54 -> V_64 ) {
memcpy ( & V_56 -> V_65 . V_66 ,
V_54 ,
sizeof(
struct V_53 ) ) ;
F_31 ( & V_56 -> V_67 ) ;
break;
}
}
}
F_21 ( & V_22 . V_60 , V_28 ) ;
}
static void F_32 ( struct V_39 * V_40 )
{
struct V_68 * V_69 ;
struct V_55 * V_56 ;
struct V_39 * V_57 ;
struct V_70 * V_71 ;
unsigned long V_28 ;
V_69 = (struct V_68 * ) V_40 ;
F_18 ( & V_22 . V_60 , V_28 ) ;
F_16 (msginfo, &vmbus_connection.chn_msg_list,
msglistentry) {
V_57 =
(struct V_39 * ) V_56 -> V_61 ;
if ( V_57 -> V_62 == V_72 ) {
V_71 =
(struct V_70 * ) V_57 ;
if ( ( V_69 -> V_36 ==
V_71 -> V_36 ) &&
( V_69 -> V_73 == V_71 -> V_73 ) ) {
memcpy ( & V_56 -> V_65 . V_74 ,
V_69 ,
sizeof(
struct V_68 ) ) ;
F_31 ( & V_56 -> V_67 ) ;
break;
}
}
}
F_21 ( & V_22 . V_60 , V_28 ) ;
}
static void F_33 (
struct V_39 * V_40 )
{
struct V_75 * V_76 ;
struct V_55 * V_56 ;
struct V_39 * V_57 ;
struct V_77 * V_78 ;
unsigned long V_28 ;
V_76 = (struct V_75 * ) V_40 ;
F_18 ( & V_22 . V_60 , V_28 ) ;
F_16 (msginfo, &vmbus_connection.chn_msg_list,
msglistentry) {
V_57 =
(struct V_39 * ) V_56 -> V_61 ;
if ( V_57 -> V_62 == V_79 ) {
V_78 =
(struct V_77 * ) V_57 ;
if ( V_76 -> V_73 == V_78 -> V_73 ) {
memcpy ( & V_56 -> V_65 . V_76 ,
V_76 ,
sizeof(
struct V_75 ) ) ;
F_31 ( & V_56 -> V_67 ) ;
break;
}
}
}
F_21 ( & V_22 . V_60 , V_28 ) ;
}
static void F_34 (
struct V_39 * V_40 )
{
struct V_55 * V_56 ;
struct V_39 * V_57 ;
struct V_80 * V_81 ;
struct V_82 * V_83 ;
unsigned long V_28 ;
V_83 = (struct V_82 * ) V_40 ;
F_18 ( & V_22 . V_60 , V_28 ) ;
F_16 (msginfo, &vmbus_connection.chn_msg_list,
msglistentry) {
V_57 =
(struct V_39 * ) V_56 -> V_61 ;
if ( V_57 -> V_62 ==
V_84 ) {
V_81 =
(struct V_80 * ) V_57 ;
memcpy ( & V_56 -> V_65 . V_83 ,
V_83 ,
sizeof( struct V_82 ) ) ;
F_31 ( & V_56 -> V_67 ) ;
}
}
F_21 ( & V_22 . V_60 , V_28 ) ;
}
void F_35 ( void * V_85 )
{
struct V_86 * V_61 = V_85 ;
struct V_39 * V_40 ;
int V_87 ;
V_40 = (struct V_39 * ) V_61 -> V_88 . V_89 ;
V_87 = V_61 -> V_90 . V_91 ;
if ( V_40 -> V_62 >= V_92 ) {
F_24 ( L_4 ,
V_40 -> V_62 , V_87 ) ;
F_36 ( L_5 , V_93 ,
( unsigned char * ) V_61 -> V_88 . V_89 , V_87 ) ;
return;
}
if ( V_94 [ V_40 -> V_62 ] . V_95 )
V_94 [ V_40 -> V_62 ] . V_95 ( V_40 ) ;
else
F_24 ( L_6 , V_40 -> V_62 ) ;
}
int F_37 ( void )
{
struct V_39 * V_61 ;
struct V_55 * V_56 ;
int V_27 , V_96 ;
V_56 = F_38 ( sizeof( * V_56 ) +
sizeof( struct V_39 ) ,
V_97 ) ;
if ( ! V_56 )
return - V_98 ;
F_39 ( & V_56 -> V_67 ) ;
V_61 = (struct V_39 * ) V_56 -> V_61 ;
V_61 -> V_62 = V_99 ;
V_27 = F_40 ( V_61 ,
sizeof( struct V_39 ) ) ;
if ( V_27 != 0 ) {
F_24 ( L_7 , V_27 ) ;
goto V_100;
}
V_96 = F_41 ( & V_56 -> V_67 , 5 * V_101 ) ;
if ( V_96 == 0 ) {
V_27 = - V_102 ;
goto V_100;
}
V_100:
F_6 ( V_56 ) ;
return V_27 ;
}
