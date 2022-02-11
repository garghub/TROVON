void F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 , T_1 * V_5 ,
int V_6 , int V_7 )
{
int V_8 ;
int V_9 ;
int V_10 ;
V_2 -> V_11 = 0x10 ;
V_4 = (struct V_3 * ) & V_5 [
sizeof( struct V_12 ) +
sizeof( struct V_1 ) ] ;
V_8 = V_4 -> V_8 ;
V_9 = V_4 -> V_9 ;
for ( V_10 = 0 ; V_10 < V_4 -> V_8 ; V_10 ++ ) {
if ( V_4 -> V_13 [ V_10 ] . V_14 <= V_6 )
V_8 = V_4 -> V_13 [ V_10 ] . V_14 ;
}
for ( V_10 = V_4 -> V_8 ;
( V_10 < V_4 -> V_8 + V_4 -> V_9 ) ; V_10 ++ ) {
if ( V_4 -> V_13 [ V_10 ] . V_14 <= V_7 )
V_9 = V_4 -> V_13 [ V_10 ] . V_14 ;
}
V_4 -> V_8 = 1 ;
V_4 -> V_9 = 1 ;
V_4 -> V_13 [ 0 ] . V_14 = V_8 ;
V_4 -> V_13 [ 0 ] . V_15 = 0 ;
V_4 -> V_13 [ 1 ] . V_14 = V_9 ;
V_4 -> V_13 [ 1 ] . V_15 = 0 ;
}
static struct V_16 * F_2 ( void )
{
struct V_16 * V_17 ;
V_17 = F_3 ( sizeof( * V_17 ) , V_18 ) ;
if ( ! V_17 )
return NULL ;
F_4 ( & V_17 -> V_19 ) ;
V_17 -> V_20 = F_5 ( L_1 ) ;
if ( ! V_17 -> V_20 ) {
F_6 ( V_17 ) ;
return NULL ;
}
return V_17 ;
}
static void F_7 ( struct V_21 * V_22 )
{
struct V_16 * V_17 = F_8 ( V_22 ,
struct V_16 ,
V_22 ) ;
F_9 ( V_17 -> V_20 ) ;
F_6 ( V_17 ) ;
}
static void F_10 ( struct V_16 * V_17 )
{
F_11 ( & V_17 -> V_22 , F_7 ) ;
F_12 ( V_23 . V_24 , & V_17 -> V_22 ) ;
}
static void F_13 ( struct V_21 * V_22 )
{
struct V_16 * V_17 = F_8 ( V_22 ,
struct V_16 ,
V_22 ) ;
F_14 ( V_17 -> V_25 ) ;
}
void F_15 ( void )
{
struct V_16 * V_17 ;
F_16 (channel, &vmbus_connection.chn_list, listentry) {
F_14 ( V_17 -> V_25 ) ;
F_6 ( V_17 -> V_25 ) ;
F_10 ( V_17 ) ;
}
}
static void F_17 ( struct V_21 * V_22 )
{
struct V_16 * V_26 = F_8 ( V_22 ,
struct V_16 ,
V_22 ) ;
struct V_16 * V_17 ;
bool V_27 = true ;
int V_28 ;
unsigned long V_29 ;
F_11 ( & V_26 -> V_22 , F_13 ) ;
F_18 ( & V_23 . V_30 , V_29 ) ;
F_16 (channel, &vmbus_connection.chn_list, listentry) {
if ( ! F_19 ( V_17 -> V_31 . V_32 . V_33 ,
V_26 -> V_31 . V_32 . V_33 ) &&
! F_19 ( V_17 -> V_31 . V_32 . V_34 ,
V_26 -> V_31 . V_32 . V_34 ) ) {
V_27 = false ;
break;
}
}
if ( V_27 )
F_20 ( & V_26 -> V_35 ,
& V_23 . V_36 ) ;
F_21 ( & V_23 . V_30 , V_29 ) ;
if ( ! V_27 ) {
F_10 ( V_26 ) ;
return;
}
V_26 -> V_25 = F_22 (
& V_26 -> V_31 . V_32 . V_33 ,
& V_26 -> V_31 . V_32 . V_34 ,
V_26 ) ;
V_28 = F_23 ( V_26 -> V_25 ) ;
if ( V_28 != 0 ) {
F_24 ( L_2 ,
V_26 -> V_31 . V_37 ) ;
F_18 ( & V_23 . V_30 , V_29 ) ;
F_25 ( & V_26 -> V_35 ) ;
F_21 ( & V_23 . V_30 , V_29 ) ;
F_6 ( V_26 -> V_25 ) ;
F_10 ( V_26 ) ;
} else {
V_26 -> V_38 = V_39 ;
}
}
static void F_26 ( struct V_40 * V_41 )
{
struct V_42 * V_32 ;
struct V_16 * V_26 ;
T_2 * V_43 ;
T_2 * V_44 ;
V_32 = (struct V_42 * ) V_41 ;
V_43 = & V_32 -> V_32 . V_33 ;
V_44 = & V_32 -> V_32 . V_34 ;
V_26 = F_2 () ;
if ( ! V_26 ) {
F_24 ( L_3 ) ;
return;
}
memcpy ( & V_26 -> V_31 , V_32 ,
sizeof( struct V_42 ) ) ;
V_26 -> V_45 = ( T_1 ) V_32 -> V_46 / 32 ;
V_26 -> V_47 = ( T_1 ) V_32 -> V_46 % 32 ;
F_11 ( & V_26 -> V_22 , F_17 ) ;
F_12 ( V_26 -> V_20 , & V_26 -> V_22 ) ;
}
static void F_27 ( struct V_40 * V_41 )
{
struct V_48 * V_49 ;
struct V_16 * V_17 ;
V_49 = (struct V_48 * ) V_41 ;
V_17 = F_28 ( V_49 -> V_37 ) ;
if ( V_17 == NULL )
return;
F_12 ( V_17 -> V_20 , & V_17 -> V_22 ) ;
}
static void F_29 (
struct V_40 * V_41 )
{
}
static void F_30 ( struct V_40 * V_41 )
{
struct V_50 * V_51 ;
struct V_52 * V_53 ;
struct V_40 * V_54 ;
struct V_55 * V_56 ;
unsigned long V_29 ;
V_51 = (struct V_50 * ) V_41 ;
F_18 ( & V_23 . V_57 , V_29 ) ;
F_16 (msginfo, &vmbus_connection.chn_msg_list,
msglistentry) {
V_54 =
(struct V_40 * ) V_53 -> V_58 ;
if ( V_54 -> V_59 == V_60 ) {
V_56 =
(struct V_55 * ) V_53 -> V_58 ;
if ( V_56 -> V_37 == V_51 -> V_37 &&
V_56 -> V_61 == V_51 -> V_61 ) {
memcpy ( & V_53 -> V_62 . V_63 ,
V_51 ,
sizeof(
struct V_50 ) ) ;
F_31 ( & V_53 -> V_64 ) ;
break;
}
}
}
F_21 ( & V_23 . V_57 , V_29 ) ;
}
static void F_32 ( struct V_40 * V_41 )
{
struct V_65 * V_66 ;
struct V_52 * V_53 ;
struct V_40 * V_54 ;
struct V_67 * V_68 ;
unsigned long V_29 ;
V_66 = (struct V_65 * ) V_41 ;
F_18 ( & V_23 . V_57 , V_29 ) ;
F_16 (msginfo, &vmbus_connection.chn_msg_list,
msglistentry) {
V_54 =
(struct V_40 * ) V_53 -> V_58 ;
if ( V_54 -> V_59 == V_69 ) {
V_68 =
(struct V_67 * ) V_54 ;
if ( ( V_66 -> V_37 ==
V_68 -> V_37 ) &&
( V_66 -> V_70 == V_68 -> V_70 ) ) {
memcpy ( & V_53 -> V_62 . V_71 ,
V_66 ,
sizeof(
struct V_65 ) ) ;
F_31 ( & V_53 -> V_64 ) ;
break;
}
}
}
F_21 ( & V_23 . V_57 , V_29 ) ;
}
static void F_33 (
struct V_40 * V_41 )
{
struct V_72 * V_73 ;
struct V_52 * V_53 ;
struct V_40 * V_54 ;
struct V_74 * V_75 ;
unsigned long V_29 ;
V_73 = (struct V_72 * ) V_41 ;
F_18 ( & V_23 . V_57 , V_29 ) ;
F_16 (msginfo, &vmbus_connection.chn_msg_list,
msglistentry) {
V_54 =
(struct V_40 * ) V_53 -> V_58 ;
if ( V_54 -> V_59 == V_76 ) {
V_75 =
(struct V_74 * ) V_54 ;
if ( V_73 -> V_70 == V_75 -> V_70 ) {
memcpy ( & V_53 -> V_62 . V_73 ,
V_73 ,
sizeof(
struct V_72 ) ) ;
F_31 ( & V_53 -> V_64 ) ;
break;
}
}
}
F_21 ( & V_23 . V_57 , V_29 ) ;
}
static void F_34 (
struct V_40 * V_41 )
{
struct V_52 * V_53 ;
struct V_40 * V_54 ;
struct V_77 * V_78 ;
struct V_79 * V_80 ;
unsigned long V_29 ;
V_80 = (struct V_79 * ) V_41 ;
F_18 ( & V_23 . V_57 , V_29 ) ;
F_16 (msginfo, &vmbus_connection.chn_msg_list,
msglistentry) {
V_54 =
(struct V_40 * ) V_53 -> V_58 ;
if ( V_54 -> V_59 ==
V_81 ) {
V_78 =
(struct V_77 * ) V_54 ;
memcpy ( & V_53 -> V_62 . V_80 ,
V_80 ,
sizeof( struct V_79 ) ) ;
F_31 ( & V_53 -> V_64 ) ;
}
}
F_21 ( & V_23 . V_57 , V_29 ) ;
}
void F_35 ( void * V_82 )
{
struct V_83 * V_58 = V_82 ;
struct V_40 * V_41 ;
int V_84 ;
V_41 = (struct V_40 * ) V_58 -> V_85 . V_86 ;
V_84 = V_58 -> V_87 . V_88 ;
if ( V_41 -> V_59 >= V_89 ) {
F_24 ( L_4 ,
V_41 -> V_59 , V_84 ) ;
F_36 ( L_5 , V_90 ,
( unsigned char * ) V_58 -> V_85 . V_86 , V_84 ) ;
return;
}
if ( V_91 [ V_41 -> V_59 ] . V_92 )
V_91 [ V_41 -> V_59 ] . V_92 ( V_41 ) ;
else
F_24 ( L_6 , V_41 -> V_59 ) ;
}
int F_37 ( void )
{
struct V_40 * V_58 ;
struct V_52 * V_53 ;
int V_28 , V_93 ;
V_53 = F_38 ( sizeof( * V_53 ) +
sizeof( struct V_40 ) ,
V_94 ) ;
if ( ! V_53 )
return - V_95 ;
F_39 ( & V_53 -> V_64 ) ;
V_58 = (struct V_40 * ) V_53 -> V_58 ;
V_58 -> V_59 = V_96 ;
V_28 = F_40 ( V_58 ,
sizeof( struct V_40 ) ) ;
if ( V_28 != 0 ) {
F_24 ( L_7 , V_28 ) ;
goto V_97;
}
V_93 = F_41 ( & V_53 -> V_64 , 5 * V_98 ) ;
if ( V_93 == 0 ) {
V_28 = - V_99 ;
goto V_97;
}
V_97:
F_6 ( V_53 ) ;
return V_28 ;
}
