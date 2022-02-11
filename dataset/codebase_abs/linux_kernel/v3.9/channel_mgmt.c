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
static T_2 F_26 ( T_3 * V_40 )
{
T_2 V_41 ;
int V_10 ;
bool V_42 = false ;
T_2 V_43 = F_27 () ;
for ( V_10 = V_44 ; V_10 < V_45 ; V_10 ++ ) {
if ( ! memcmp ( V_40 -> V_46 , V_47 [ V_10 ] . V_48 ,
sizeof( T_3 ) ) ) {
V_42 = true ;
break;
}
}
if ( ( V_49 == V_50 ) ||
( V_49 == V_51 ) || ( ! V_42 ) ) {
return 0 ;
}
V_41 = ( ++ V_52 % V_43 ) ;
return V_41 ;
}
static void F_28 ( struct V_53 * V_54 )
{
struct V_55 * V_32 ;
struct V_16 * V_26 ;
V_32 = (struct V_55 * ) V_54 ;
V_26 = F_2 () ;
if ( ! V_26 ) {
F_24 ( L_3 ) ;
return;
}
V_26 -> V_56 = true ;
V_26 -> V_57 = (struct V_58 * )
( F_29 ( ( unsigned long )
& V_26 -> V_59 ,
V_60 ) ) ;
V_26 -> V_57 -> V_61 . V_62 = 0 ;
V_26 -> V_57 -> V_61 . V_63 . V_64 = V_65 ;
V_26 -> V_57 -> V_66 = 0 ;
V_26 -> V_57 -> V_67 = 0 ;
if ( V_49 != V_50 ) {
V_26 -> V_68 =
( V_32 -> V_68 != 0 ) ;
V_26 -> V_57 -> V_61 . V_63 . V_64 =
V_32 -> V_69 ;
}
V_26 -> V_70 = F_26 ( & V_32 -> V_32 . V_33 ) ;
memcpy ( & V_26 -> V_31 , V_32 ,
sizeof( struct V_55 ) ) ;
V_26 -> V_71 = ( T_1 ) V_32 -> V_72 / 32 ;
V_26 -> V_73 = ( T_1 ) V_32 -> V_72 % 32 ;
F_11 ( & V_26 -> V_22 , F_17 ) ;
F_12 ( V_26 -> V_20 , & V_26 -> V_22 ) ;
}
static void F_30 ( struct V_53 * V_54 )
{
struct V_74 * V_75 ;
struct V_16 * V_17 ;
V_75 = (struct V_74 * ) V_54 ;
V_17 = F_31 ( V_75 -> V_37 ) ;
if ( V_17 == NULL )
return;
F_12 ( V_17 -> V_20 , & V_17 -> V_22 ) ;
}
static void F_32 (
struct V_53 * V_54 )
{
}
static void F_33 ( struct V_53 * V_54 )
{
struct V_76 * V_77 ;
struct V_78 * V_79 ;
struct V_53 * V_80 ;
struct V_81 * V_82 ;
unsigned long V_29 ;
V_77 = (struct V_76 * ) V_54 ;
F_18 ( & V_23 . V_83 , V_29 ) ;
F_16 (msginfo, &vmbus_connection.chn_msg_list,
msglistentry) {
V_80 =
(struct V_53 * ) V_79 -> V_84 ;
if ( V_80 -> V_85 == V_86 ) {
V_82 =
(struct V_81 * ) V_79 -> V_84 ;
if ( V_82 -> V_37 == V_77 -> V_37 &&
V_82 -> V_87 == V_77 -> V_87 ) {
memcpy ( & V_79 -> V_88 . V_89 ,
V_77 ,
sizeof(
struct V_76 ) ) ;
F_34 ( & V_79 -> V_90 ) ;
break;
}
}
}
F_21 ( & V_23 . V_83 , V_29 ) ;
}
static void F_35 ( struct V_53 * V_54 )
{
struct V_91 * V_92 ;
struct V_78 * V_79 ;
struct V_53 * V_80 ;
struct V_93 * V_94 ;
unsigned long V_29 ;
V_92 = (struct V_91 * ) V_54 ;
F_18 ( & V_23 . V_83 , V_29 ) ;
F_16 (msginfo, &vmbus_connection.chn_msg_list,
msglistentry) {
V_80 =
(struct V_53 * ) V_79 -> V_84 ;
if ( V_80 -> V_85 == V_95 ) {
V_94 =
(struct V_93 * ) V_80 ;
if ( ( V_92 -> V_37 ==
V_94 -> V_37 ) &&
( V_92 -> V_96 == V_94 -> V_96 ) ) {
memcpy ( & V_79 -> V_88 . V_97 ,
V_92 ,
sizeof(
struct V_91 ) ) ;
F_34 ( & V_79 -> V_90 ) ;
break;
}
}
}
F_21 ( & V_23 . V_83 , V_29 ) ;
}
static void F_36 (
struct V_53 * V_54 )
{
struct V_98 * V_99 ;
struct V_78 * V_79 ;
struct V_53 * V_80 ;
struct V_100 * V_101 ;
unsigned long V_29 ;
V_99 = (struct V_98 * ) V_54 ;
F_18 ( & V_23 . V_83 , V_29 ) ;
F_16 (msginfo, &vmbus_connection.chn_msg_list,
msglistentry) {
V_80 =
(struct V_53 * ) V_79 -> V_84 ;
if ( V_80 -> V_85 == V_102 ) {
V_101 =
(struct V_100 * ) V_80 ;
if ( V_99 -> V_96 == V_101 -> V_96 ) {
memcpy ( & V_79 -> V_88 . V_99 ,
V_99 ,
sizeof(
struct V_98 ) ) ;
F_34 ( & V_79 -> V_90 ) ;
break;
}
}
}
F_21 ( & V_23 . V_83 , V_29 ) ;
}
static void F_37 (
struct V_53 * V_54 )
{
struct V_78 * V_79 ;
struct V_53 * V_80 ;
struct V_103 * V_104 ;
unsigned long V_29 ;
V_104 = (struct V_103 * ) V_54 ;
F_18 ( & V_23 . V_83 , V_29 ) ;
F_16 (msginfo, &vmbus_connection.chn_msg_list,
msglistentry) {
V_80 =
(struct V_53 * ) V_79 -> V_84 ;
if ( V_80 -> V_85 ==
V_105 ) {
memcpy ( & V_79 -> V_88 . V_104 ,
V_104 ,
sizeof( struct V_103 ) ) ;
F_34 ( & V_79 -> V_90 ) ;
}
}
F_21 ( & V_23 . V_83 , V_29 ) ;
}
void F_38 ( void * V_106 )
{
struct V_107 * V_84 = V_106 ;
struct V_53 * V_54 ;
int V_108 ;
V_54 = (struct V_53 * ) V_84 -> V_63 . V_109 ;
V_108 = V_84 -> V_110 . V_111 ;
if ( V_54 -> V_85 >= V_112 ) {
F_24 ( L_4 ,
V_54 -> V_85 , V_108 ) ;
F_39 ( L_5 , V_113 ,
( unsigned char * ) V_84 -> V_63 . V_109 , V_108 ) ;
return;
}
if ( V_114 [ V_54 -> V_85 ] . V_115 )
V_114 [ V_54 -> V_85 ] . V_115 ( V_54 ) ;
else
F_24 ( L_6 , V_54 -> V_85 ) ;
}
int F_40 ( void )
{
struct V_53 * V_84 ;
struct V_78 * V_79 ;
int V_28 , V_116 ;
V_79 = F_41 ( sizeof( * V_79 ) +
sizeof( struct V_53 ) ,
V_117 ) ;
if ( ! V_79 )
return - V_118 ;
F_42 ( & V_79 -> V_90 ) ;
V_84 = (struct V_53 * ) V_79 -> V_84 ;
V_84 -> V_85 = V_119 ;
V_28 = F_43 ( V_84 ,
sizeof( struct V_53 ) ) ;
if ( V_28 != 0 ) {
F_24 ( L_7 , V_28 ) ;
goto V_120;
}
V_116 = F_44 ( & V_79 -> V_90 , 5 * V_121 ) ;
if ( V_116 == 0 ) {
V_28 = - V_122 ;
goto V_120;
}
V_120:
F_6 ( V_79 ) ;
return V_28 ;
}
