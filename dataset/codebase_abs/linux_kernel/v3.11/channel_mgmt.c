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
F_4 ( & V_17 -> V_20 ) ;
F_5 ( & V_17 -> V_21 ) ;
V_17 -> V_22 = F_6 ( L_1 ) ;
if ( ! V_17 -> V_22 ) {
F_7 ( V_17 ) ;
return NULL ;
}
return V_17 ;
}
static void F_8 ( struct V_23 * V_24 )
{
struct V_16 * V_17 = F_9 ( V_24 ,
struct V_16 ,
V_24 ) ;
F_10 ( V_17 -> V_22 ) ;
F_7 ( V_17 ) ;
}
static void F_11 ( struct V_16 * V_17 )
{
F_12 ( & V_17 -> V_24 , F_8 ) ;
F_13 ( V_25 . V_26 , & V_17 -> V_24 ) ;
}
static void F_14 ( struct V_23 * V_24 )
{
struct V_16 * V_17 = F_9 ( V_24 ,
struct V_16 ,
V_24 ) ;
unsigned long V_27 ;
struct V_16 * V_28 ;
struct V_29 V_30 ;
F_15 ( V_17 -> V_31 ) ;
memset ( & V_30 , 0 , sizeof( struct V_29 ) ) ;
V_30 . V_32 = V_17 -> V_33 . V_32 ;
V_30 . V_34 . V_35 = V_36 ;
F_16 ( & V_30 , sizeof( struct V_29 ) ) ;
if ( V_17 -> V_28 == NULL ) {
F_17 ( & V_25 . V_37 , V_27 ) ;
F_18 ( & V_17 -> V_38 ) ;
F_19 ( & V_25 . V_37 , V_27 ) ;
} else {
V_28 = V_17 -> V_28 ;
F_17 ( & V_28 -> V_20 , V_27 ) ;
F_18 ( & V_17 -> V_38 ) ;
F_19 ( & V_28 -> V_20 , V_27 ) ;
}
F_11 ( V_17 ) ;
}
void F_20 ( void )
{
struct V_16 * V_17 ;
F_21 (channel, &vmbus_connection.chn_list, listentry) {
F_15 ( V_17 -> V_31 ) ;
F_7 ( V_17 -> V_31 ) ;
F_11 ( V_17 ) ;
}
}
static void F_22 ( struct V_23 * V_24 )
{
struct V_16 * V_39 = F_9 ( V_24 ,
struct V_16 ,
V_24 ) ;
struct V_16 * V_17 ;
bool V_40 = true ;
int V_41 ;
unsigned long V_27 ;
F_12 ( & V_39 -> V_24 , F_14 ) ;
F_17 ( & V_25 . V_37 , V_27 ) ;
F_21 (channel, &vmbus_connection.chn_list, listentry) {
if ( ! F_23 ( V_17 -> V_33 . V_42 . V_43 ,
V_39 -> V_33 . V_42 . V_43 ) &&
! F_23 ( V_17 -> V_33 . V_42 . V_44 ,
V_39 -> V_33 . V_42 . V_44 ) ) {
V_40 = false ;
break;
}
}
if ( V_40 )
F_24 ( & V_39 -> V_38 ,
& V_25 . V_45 ) ;
F_19 ( & V_25 . V_37 , V_27 ) ;
if ( ! V_40 ) {
if ( V_39 -> V_33 . V_42 . V_46 != 0 ) {
V_39 -> V_28 = V_17 ;
F_17 ( & V_17 -> V_20 , V_27 ) ;
F_24 ( & V_39 -> V_21 , & V_17 -> V_21 ) ;
F_19 ( & V_17 -> V_20 , V_27 ) ;
V_39 -> V_47 = V_48 ;
if ( V_17 -> V_49 != NULL )
V_17 -> V_49 ( V_39 ) ;
return;
}
F_11 ( V_39 ) ;
return;
}
V_39 -> V_31 = F_25 (
& V_39 -> V_33 . V_42 . V_43 ,
& V_39 -> V_33 . V_42 . V_44 ,
V_39 ) ;
V_41 = F_26 ( V_39 -> V_31 ) ;
if ( V_41 != 0 ) {
F_27 ( L_2 ,
V_39 -> V_33 . V_32 ) ;
F_17 ( & V_25 . V_37 , V_27 ) ;
F_18 ( & V_39 -> V_38 ) ;
F_19 ( & V_25 . V_37 , V_27 ) ;
F_7 ( V_39 -> V_31 ) ;
F_11 ( V_39 ) ;
} else {
V_39 -> V_47 = V_48 ;
}
}
static T_2 F_28 ( T_3 * V_50 )
{
T_2 V_51 ;
int V_10 ;
bool V_52 = false ;
T_2 V_53 = F_29 () ;
for ( V_10 = V_54 ; V_10 < V_55 ; V_10 ++ ) {
if ( ! memcmp ( V_50 -> V_56 , V_57 [ V_10 ] . V_58 ,
sizeof( T_3 ) ) ) {
V_52 = true ;
break;
}
}
if ( ( V_59 == V_60 ) ||
( V_59 == V_61 ) || ( ! V_52 ) ) {
return 0 ;
}
V_51 = ( ++ V_62 % V_53 ) ;
return V_63 . V_64 [ V_51 ] ;
}
static void F_30 ( struct V_65 * V_66 )
{
struct V_67 * V_42 ;
struct V_16 * V_39 ;
V_42 = (struct V_67 * ) V_66 ;
V_39 = F_2 () ;
if ( ! V_39 ) {
F_27 ( L_3 ) ;
return;
}
V_39 -> V_68 = true ;
V_39 -> V_69 = (struct V_70 * )
( F_31 ( ( unsigned long )
& V_39 -> V_71 ,
V_72 ) ) ;
V_39 -> V_69 -> V_73 . V_74 = 0 ;
V_39 -> V_69 -> V_73 . V_75 . V_76 = V_77 ;
V_39 -> V_69 -> V_78 = 0 ;
V_39 -> V_69 -> V_79 = 0 ;
if ( V_59 != V_60 ) {
V_39 -> V_80 =
( V_42 -> V_80 != 0 ) ;
V_39 -> V_69 -> V_73 . V_75 . V_76 =
V_42 -> V_81 ;
}
V_39 -> V_82 = F_28 ( & V_42 -> V_42 . V_43 ) ;
memcpy ( & V_39 -> V_33 , V_42 ,
sizeof( struct V_67 ) ) ;
V_39 -> V_83 = ( T_1 ) V_42 -> V_84 / 32 ;
V_39 -> V_85 = ( T_1 ) V_42 -> V_84 % 32 ;
F_12 ( & V_39 -> V_24 , F_22 ) ;
F_13 ( V_39 -> V_22 , & V_39 -> V_24 ) ;
}
static void F_32 ( struct V_65 * V_66 )
{
struct V_86 * V_87 ;
struct V_16 * V_17 ;
V_87 = (struct V_86 * ) V_66 ;
V_17 = F_33 ( V_87 -> V_32 ) ;
if ( V_17 == NULL )
return;
F_13 ( V_17 -> V_22 , & V_17 -> V_24 ) ;
}
static void F_34 (
struct V_65 * V_66 )
{
}
static void F_35 ( struct V_65 * V_66 )
{
struct V_88 * V_89 ;
struct V_90 * V_91 ;
struct V_65 * V_92 ;
struct V_93 * V_94 ;
unsigned long V_27 ;
V_89 = (struct V_88 * ) V_66 ;
F_17 ( & V_25 . V_95 , V_27 ) ;
F_21 (msginfo, &vmbus_connection.chn_msg_list,
msglistentry) {
V_92 =
(struct V_65 * ) V_91 -> V_30 ;
if ( V_92 -> V_35 == V_96 ) {
V_94 =
(struct V_93 * ) V_91 -> V_30 ;
if ( V_94 -> V_32 == V_89 -> V_32 &&
V_94 -> V_97 == V_89 -> V_97 ) {
memcpy ( & V_91 -> V_98 . V_99 ,
V_89 ,
sizeof(
struct V_88 ) ) ;
F_36 ( & V_91 -> V_100 ) ;
break;
}
}
}
F_19 ( & V_25 . V_95 , V_27 ) ;
}
static void F_37 ( struct V_65 * V_66 )
{
struct V_101 * V_102 ;
struct V_90 * V_91 ;
struct V_65 * V_92 ;
struct V_103 * V_104 ;
unsigned long V_27 ;
V_102 = (struct V_101 * ) V_66 ;
F_17 ( & V_25 . V_95 , V_27 ) ;
F_21 (msginfo, &vmbus_connection.chn_msg_list,
msglistentry) {
V_92 =
(struct V_65 * ) V_91 -> V_30 ;
if ( V_92 -> V_35 == V_105 ) {
V_104 =
(struct V_103 * ) V_92 ;
if ( ( V_102 -> V_32 ==
V_104 -> V_32 ) &&
( V_102 -> V_106 == V_104 -> V_106 ) ) {
memcpy ( & V_91 -> V_98 . V_107 ,
V_102 ,
sizeof(
struct V_101 ) ) ;
F_36 ( & V_91 -> V_100 ) ;
break;
}
}
}
F_19 ( & V_25 . V_95 , V_27 ) ;
}
static void F_38 (
struct V_65 * V_66 )
{
struct V_108 * V_109 ;
struct V_90 * V_91 ;
struct V_65 * V_92 ;
struct V_110 * V_111 ;
unsigned long V_27 ;
V_109 = (struct V_108 * ) V_66 ;
F_17 ( & V_25 . V_95 , V_27 ) ;
F_21 (msginfo, &vmbus_connection.chn_msg_list,
msglistentry) {
V_92 =
(struct V_65 * ) V_91 -> V_30 ;
if ( V_92 -> V_35 == V_112 ) {
V_111 =
(struct V_110 * ) V_92 ;
if ( V_109 -> V_106 == V_111 -> V_106 ) {
memcpy ( & V_91 -> V_98 . V_109 ,
V_109 ,
sizeof(
struct V_108 ) ) ;
F_36 ( & V_91 -> V_100 ) ;
break;
}
}
}
F_19 ( & V_25 . V_95 , V_27 ) ;
}
static void F_39 (
struct V_65 * V_66 )
{
struct V_90 * V_91 ;
struct V_65 * V_92 ;
struct V_113 * V_114 ;
unsigned long V_27 ;
V_114 = (struct V_113 * ) V_66 ;
F_17 ( & V_25 . V_95 , V_27 ) ;
F_21 (msginfo, &vmbus_connection.chn_msg_list,
msglistentry) {
V_92 =
(struct V_65 * ) V_91 -> V_30 ;
if ( V_92 -> V_35 ==
V_115 ) {
memcpy ( & V_91 -> V_98 . V_114 ,
V_114 ,
sizeof( struct V_113 ) ) ;
F_36 ( & V_91 -> V_100 ) ;
}
}
F_19 ( & V_25 . V_95 , V_27 ) ;
}
void F_40 ( void * V_116 )
{
struct V_117 * V_30 = V_116 ;
struct V_65 * V_66 ;
int V_118 ;
V_66 = (struct V_65 * ) V_30 -> V_75 . V_119 ;
V_118 = V_30 -> V_34 . V_120 ;
if ( V_66 -> V_35 >= V_121 ) {
F_27 ( L_4 ,
V_66 -> V_35 , V_118 ) ;
F_41 ( L_5 , V_122 ,
( unsigned char * ) V_30 -> V_75 . V_119 , V_118 ) ;
return;
}
if ( V_123 [ V_66 -> V_35 ] . V_124 )
V_123 [ V_66 -> V_35 ] . V_124 ( V_66 ) ;
else
F_27 ( L_6 , V_66 -> V_35 ) ;
}
int F_42 ( void )
{
struct V_65 * V_30 ;
struct V_90 * V_91 ;
int V_41 , V_125 ;
V_91 = F_43 ( sizeof( * V_91 ) +
sizeof( struct V_65 ) ,
V_126 ) ;
if ( ! V_91 )
return - V_127 ;
F_44 ( & V_91 -> V_100 ) ;
V_30 = (struct V_65 * ) V_91 -> V_30 ;
V_30 -> V_35 = V_128 ;
V_41 = F_16 ( V_30 ,
sizeof( struct V_65 ) ) ;
if ( V_41 != 0 ) {
F_27 ( L_7 , V_41 ) ;
goto V_129;
}
V_125 = F_45 ( & V_91 -> V_100 , 5 * V_130 ) ;
if ( V_125 == 0 ) {
V_41 = - V_131 ;
goto V_129;
}
V_129:
F_7 ( V_91 ) ;
return V_41 ;
}
struct V_16 * F_46 ( struct V_16 * V_132 )
{
struct V_133 * V_134 , * V_135 ;
int V_51 = V_63 . V_64 [ F_47 () ] ;
struct V_16 * V_136 ;
struct V_16 * V_137 = V_132 ;
int V_138 , V_139 ;
if ( F_48 ( & V_132 -> V_21 ) )
return V_137 ;
F_49 (cur, tmp, &primary->sc_list) {
V_136 = F_50 ( V_134 , struct V_16 , V_21 ) ;
if ( V_136 -> V_47 != V_140 )
continue;
if ( V_136 -> V_82 == V_51 )
return V_136 ;
V_138 = ( ( V_137 -> V_82 > V_51 ) ?
( V_137 -> V_82 - V_51 ) :
( V_51 - V_137 -> V_82 ) ) ;
V_139 = ( ( V_136 -> V_82 > V_51 ) ?
( V_136 -> V_82 - V_51 ) :
( V_51 - V_136 -> V_82 ) ) ;
if ( V_138 < V_139 )
continue;
V_137 = V_136 ;
}
return V_137 ;
}
static void F_51 ( struct V_16 * V_28 )
{
struct V_133 * V_134 , * V_135 ;
struct V_16 * V_136 ;
if ( V_28 -> V_49 == NULL )
return;
F_49 (cur, tmp, &primary_channel->sc_list) {
V_136 = F_50 ( V_134 , struct V_16 , V_21 ) ;
V_28 -> V_49 ( V_136 ) ;
}
}
void F_52 ( struct V_16 * V_28 ,
void (* F_53)( struct V_16 * V_141 ) )
{
V_28 -> V_49 = F_53 ;
}
bool F_54 ( struct V_16 * V_132 )
{
bool V_41 ;
V_41 = ! F_48 ( & V_132 -> V_21 ) ;
if ( V_41 ) {
F_51 ( V_132 ) ;
}
return V_41 ;
}
