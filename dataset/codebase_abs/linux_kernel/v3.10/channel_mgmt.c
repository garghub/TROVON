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
unsigned long V_25 ;
struct V_26 V_27 ;
F_14 ( V_17 -> V_28 ) ;
memset ( & V_27 , 0 , sizeof( struct V_26 ) ) ;
V_27 . V_29 = V_17 -> V_30 . V_29 ;
V_27 . V_31 . V_32 = V_33 ;
F_15 ( & V_27 , sizeof( struct V_26 ) ) ;
F_16 ( & V_23 . V_34 , V_25 ) ;
F_17 ( & V_17 -> V_35 ) ;
F_18 ( & V_23 . V_34 , V_25 ) ;
F_10 ( V_17 ) ;
}
void F_19 ( void )
{
struct V_16 * V_17 ;
F_20 (channel, &vmbus_connection.chn_list, listentry) {
F_14 ( V_17 -> V_28 ) ;
F_6 ( V_17 -> V_28 ) ;
F_10 ( V_17 ) ;
}
}
static void F_21 ( struct V_21 * V_22 )
{
struct V_16 * V_36 = F_8 ( V_22 ,
struct V_16 ,
V_22 ) ;
struct V_16 * V_17 ;
bool V_37 = true ;
int V_38 ;
unsigned long V_25 ;
F_11 ( & V_36 -> V_22 , F_13 ) ;
F_16 ( & V_23 . V_34 , V_25 ) ;
F_20 (channel, &vmbus_connection.chn_list, listentry) {
if ( ! F_22 ( V_17 -> V_30 . V_39 . V_40 ,
V_36 -> V_30 . V_39 . V_40 ) &&
! F_22 ( V_17 -> V_30 . V_39 . V_41 ,
V_36 -> V_30 . V_39 . V_41 ) ) {
V_37 = false ;
break;
}
}
if ( V_37 )
F_23 ( & V_36 -> V_35 ,
& V_23 . V_42 ) ;
F_18 ( & V_23 . V_34 , V_25 ) ;
if ( ! V_37 ) {
F_10 ( V_36 ) ;
return;
}
V_36 -> V_28 = F_24 (
& V_36 -> V_30 . V_39 . V_40 ,
& V_36 -> V_30 . V_39 . V_41 ,
V_36 ) ;
V_38 = F_25 ( V_36 -> V_28 ) ;
if ( V_38 != 0 ) {
F_26 ( L_2 ,
V_36 -> V_30 . V_29 ) ;
F_16 ( & V_23 . V_34 , V_25 ) ;
F_17 ( & V_36 -> V_35 ) ;
F_18 ( & V_23 . V_34 , V_25 ) ;
F_6 ( V_36 -> V_28 ) ;
F_10 ( V_36 ) ;
} else {
V_36 -> V_43 = V_44 ;
}
}
static T_2 F_27 ( T_3 * V_45 )
{
T_2 V_46 ;
int V_10 ;
bool V_47 = false ;
T_2 V_48 = F_28 () ;
for ( V_10 = V_49 ; V_10 < V_50 ; V_10 ++ ) {
if ( ! memcmp ( V_45 -> V_51 , V_52 [ V_10 ] . V_53 ,
sizeof( T_3 ) ) ) {
V_47 = true ;
break;
}
}
if ( ( V_54 == V_55 ) ||
( V_54 == V_56 ) || ( ! V_47 ) ) {
return 0 ;
}
V_46 = ( ++ V_57 % V_48 ) ;
return V_58 . V_59 [ V_46 ] ;
}
static void F_29 ( struct V_60 * V_61 )
{
struct V_62 * V_39 ;
struct V_16 * V_36 ;
V_39 = (struct V_62 * ) V_61 ;
V_36 = F_2 () ;
if ( ! V_36 ) {
F_26 ( L_3 ) ;
return;
}
V_36 -> V_63 = true ;
V_36 -> V_64 = (struct V_65 * )
( F_30 ( ( unsigned long )
& V_36 -> V_66 ,
V_67 ) ) ;
V_36 -> V_64 -> V_68 . V_69 = 0 ;
V_36 -> V_64 -> V_68 . V_70 . V_71 = V_72 ;
V_36 -> V_64 -> V_73 = 0 ;
V_36 -> V_64 -> V_74 = 0 ;
if ( V_54 != V_55 ) {
V_36 -> V_75 =
( V_39 -> V_75 != 0 ) ;
V_36 -> V_64 -> V_68 . V_70 . V_71 =
V_39 -> V_76 ;
}
V_36 -> V_77 = F_27 ( & V_39 -> V_39 . V_40 ) ;
memcpy ( & V_36 -> V_30 , V_39 ,
sizeof( struct V_62 ) ) ;
V_36 -> V_78 = ( T_1 ) V_39 -> V_79 / 32 ;
V_36 -> V_80 = ( T_1 ) V_39 -> V_79 % 32 ;
F_11 ( & V_36 -> V_22 , F_21 ) ;
F_12 ( V_36 -> V_20 , & V_36 -> V_22 ) ;
}
static void F_31 ( struct V_60 * V_61 )
{
struct V_81 * V_82 ;
struct V_16 * V_17 ;
V_82 = (struct V_81 * ) V_61 ;
V_17 = F_32 ( V_82 -> V_29 ) ;
if ( V_17 == NULL )
return;
F_12 ( V_17 -> V_20 , & V_17 -> V_22 ) ;
}
static void F_33 (
struct V_60 * V_61 )
{
}
static void F_34 ( struct V_60 * V_61 )
{
struct V_83 * V_84 ;
struct V_85 * V_86 ;
struct V_60 * V_87 ;
struct V_88 * V_89 ;
unsigned long V_25 ;
V_84 = (struct V_83 * ) V_61 ;
F_16 ( & V_23 . V_90 , V_25 ) ;
F_20 (msginfo, &vmbus_connection.chn_msg_list,
msglistentry) {
V_87 =
(struct V_60 * ) V_86 -> V_27 ;
if ( V_87 -> V_32 == V_91 ) {
V_89 =
(struct V_88 * ) V_86 -> V_27 ;
if ( V_89 -> V_29 == V_84 -> V_29 &&
V_89 -> V_92 == V_84 -> V_92 ) {
memcpy ( & V_86 -> V_93 . V_94 ,
V_84 ,
sizeof(
struct V_83 ) ) ;
F_35 ( & V_86 -> V_95 ) ;
break;
}
}
}
F_18 ( & V_23 . V_90 , V_25 ) ;
}
static void F_36 ( struct V_60 * V_61 )
{
struct V_96 * V_97 ;
struct V_85 * V_86 ;
struct V_60 * V_87 ;
struct V_98 * V_99 ;
unsigned long V_25 ;
V_97 = (struct V_96 * ) V_61 ;
F_16 ( & V_23 . V_90 , V_25 ) ;
F_20 (msginfo, &vmbus_connection.chn_msg_list,
msglistentry) {
V_87 =
(struct V_60 * ) V_86 -> V_27 ;
if ( V_87 -> V_32 == V_100 ) {
V_99 =
(struct V_98 * ) V_87 ;
if ( ( V_97 -> V_29 ==
V_99 -> V_29 ) &&
( V_97 -> V_101 == V_99 -> V_101 ) ) {
memcpy ( & V_86 -> V_93 . V_102 ,
V_97 ,
sizeof(
struct V_96 ) ) ;
F_35 ( & V_86 -> V_95 ) ;
break;
}
}
}
F_18 ( & V_23 . V_90 , V_25 ) ;
}
static void F_37 (
struct V_60 * V_61 )
{
struct V_103 * V_104 ;
struct V_85 * V_86 ;
struct V_60 * V_87 ;
struct V_105 * V_106 ;
unsigned long V_25 ;
V_104 = (struct V_103 * ) V_61 ;
F_16 ( & V_23 . V_90 , V_25 ) ;
F_20 (msginfo, &vmbus_connection.chn_msg_list,
msglistentry) {
V_87 =
(struct V_60 * ) V_86 -> V_27 ;
if ( V_87 -> V_32 == V_107 ) {
V_106 =
(struct V_105 * ) V_87 ;
if ( V_104 -> V_101 == V_106 -> V_101 ) {
memcpy ( & V_86 -> V_93 . V_104 ,
V_104 ,
sizeof(
struct V_103 ) ) ;
F_35 ( & V_86 -> V_95 ) ;
break;
}
}
}
F_18 ( & V_23 . V_90 , V_25 ) ;
}
static void F_38 (
struct V_60 * V_61 )
{
struct V_85 * V_86 ;
struct V_60 * V_87 ;
struct V_108 * V_109 ;
unsigned long V_25 ;
V_109 = (struct V_108 * ) V_61 ;
F_16 ( & V_23 . V_90 , V_25 ) ;
F_20 (msginfo, &vmbus_connection.chn_msg_list,
msglistentry) {
V_87 =
(struct V_60 * ) V_86 -> V_27 ;
if ( V_87 -> V_32 ==
V_110 ) {
memcpy ( & V_86 -> V_93 . V_109 ,
V_109 ,
sizeof( struct V_108 ) ) ;
F_35 ( & V_86 -> V_95 ) ;
}
}
F_18 ( & V_23 . V_90 , V_25 ) ;
}
void F_39 ( void * V_111 )
{
struct V_112 * V_27 = V_111 ;
struct V_60 * V_61 ;
int V_113 ;
V_61 = (struct V_60 * ) V_27 -> V_70 . V_114 ;
V_113 = V_27 -> V_31 . V_115 ;
if ( V_61 -> V_32 >= V_116 ) {
F_26 ( L_4 ,
V_61 -> V_32 , V_113 ) ;
F_40 ( L_5 , V_117 ,
( unsigned char * ) V_27 -> V_70 . V_114 , V_113 ) ;
return;
}
if ( V_118 [ V_61 -> V_32 ] . V_119 )
V_118 [ V_61 -> V_32 ] . V_119 ( V_61 ) ;
else
F_26 ( L_6 , V_61 -> V_32 ) ;
}
int F_41 ( void )
{
struct V_60 * V_27 ;
struct V_85 * V_86 ;
int V_38 , V_120 ;
V_86 = F_42 ( sizeof( * V_86 ) +
sizeof( struct V_60 ) ,
V_121 ) ;
if ( ! V_86 )
return - V_122 ;
F_43 ( & V_86 -> V_95 ) ;
V_27 = (struct V_60 * ) V_86 -> V_27 ;
V_27 -> V_32 = V_123 ;
V_38 = F_15 ( V_27 ,
sizeof( struct V_60 ) ) ;
if ( V_38 != 0 ) {
F_26 ( L_7 , V_38 ) ;
goto V_124;
}
V_120 = F_44 ( & V_86 -> V_95 , 5 * V_125 ) ;
if ( V_120 == 0 ) {
V_38 = - V_126 ;
goto V_124;
}
V_124:
F_6 ( V_86 ) ;
return V_38 ;
}
