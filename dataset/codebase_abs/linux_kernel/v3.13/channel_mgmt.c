bool F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 , T_1 * V_5 ,
int V_6 , int V_7 )
{
int V_8 , V_9 ;
int V_10 , V_11 ;
int V_12 , V_13 ;
int V_14 , V_15 ;
int V_16 ;
bool V_17 = false ;
V_2 -> V_18 = 0x10 ;
V_12 = ( V_6 >> 16 ) ;
V_13 = ( V_6 & 0xFFFF ) ;
V_14 = ( V_7 >> 16 ) ;
V_15 = ( V_7 & 0xFFFF ) ;
V_4 = (struct V_3 * ) & V_5 [
sizeof( struct V_19 ) +
sizeof( struct V_1 ) ] ;
V_8 = V_4 -> V_20 ;
V_9 = 0 ;
V_10 = V_4 -> V_21 ;
V_11 = 0 ;
for ( V_16 = 0 ; V_16 < V_4 -> V_20 ; V_16 ++ ) {
if ( ( V_4 -> V_22 [ V_16 ] . V_23 == V_12 ) &&
( V_4 -> V_22 [ V_16 ] . V_24 == V_13 ) ) {
V_8 = V_4 -> V_22 [ V_16 ] . V_23 ;
V_9 = V_4 -> V_22 [ V_16 ] . V_24 ;
V_17 = true ;
}
}
if ( ! V_17 )
goto V_25;
V_17 = false ;
for ( V_16 = V_4 -> V_20 ;
( V_16 < V_4 -> V_20 + V_4 -> V_21 ) ; V_16 ++ ) {
if ( ( V_4 -> V_22 [ V_16 ] . V_23 == V_14 ) &&
( V_4 -> V_22 [ V_16 ] . V_24 == V_15 ) ) {
V_10 = V_4 -> V_22 [ V_16 ] . V_23 ;
V_11 = V_4 -> V_22 [ V_16 ] . V_24 ;
V_17 = true ;
}
}
V_25:
if ( ! V_17 ) {
V_4 -> V_20 = 0 ;
V_4 -> V_21 = 0 ;
} else {
V_4 -> V_20 = 1 ;
V_4 -> V_21 = 1 ;
}
V_4 -> V_22 [ 0 ] . V_23 = V_8 ;
V_4 -> V_22 [ 0 ] . V_24 = V_9 ;
V_4 -> V_22 [ 1 ] . V_23 = V_10 ;
V_4 -> V_22 [ 1 ] . V_24 = V_11 ;
return V_17 ;
}
static struct V_26 * F_2 ( void )
{
struct V_26 * V_27 ;
V_27 = F_3 ( sizeof( * V_27 ) , V_28 ) ;
if ( ! V_27 )
return NULL ;
F_4 ( & V_27 -> V_29 ) ;
F_4 ( & V_27 -> V_30 ) ;
F_5 ( & V_27 -> V_31 ) ;
V_27 -> V_32 = F_6 ( L_1 ) ;
if ( ! V_27 -> V_32 ) {
F_7 ( V_27 ) ;
return NULL ;
}
return V_27 ;
}
static void F_8 ( struct V_33 * V_34 )
{
struct V_26 * V_27 = F_9 ( V_34 ,
struct V_26 ,
V_34 ) ;
F_10 ( V_27 -> V_32 ) ;
F_7 ( V_27 ) ;
}
static void F_11 ( struct V_26 * V_27 )
{
F_12 ( & V_27 -> V_34 , F_8 ) ;
F_13 ( V_35 . V_36 , & V_27 -> V_34 ) ;
}
static void F_14 ( struct V_33 * V_34 )
{
struct V_26 * V_27 = F_9 ( V_34 ,
struct V_26 ,
V_34 ) ;
unsigned long V_37 ;
struct V_26 * V_38 ;
struct V_39 V_40 ;
if ( V_27 -> V_41 )
F_15 ( V_27 -> V_41 ) ;
memset ( & V_40 , 0 , sizeof( struct V_39 ) ) ;
V_40 . V_42 = V_27 -> V_43 . V_42 ;
V_40 . V_44 . V_45 = V_46 ;
F_16 ( & V_40 , sizeof( struct V_39 ) ) ;
if ( V_27 -> V_38 == NULL ) {
F_17 ( & V_35 . V_47 , V_37 ) ;
F_18 ( & V_27 -> V_48 ) ;
F_19 ( & V_35 . V_47 , V_37 ) ;
} else {
V_38 = V_27 -> V_38 ;
F_17 ( & V_38 -> V_30 , V_37 ) ;
F_18 ( & V_27 -> V_31 ) ;
F_19 ( & V_38 -> V_30 , V_37 ) ;
}
F_11 ( V_27 ) ;
}
void F_20 ( void )
{
struct V_26 * V_27 ;
F_21 (channel, &vmbus_connection.chn_list, listentry) {
F_15 ( V_27 -> V_41 ) ;
F_7 ( V_27 -> V_41 ) ;
F_11 ( V_27 ) ;
}
}
static void F_22 ( struct V_33 * V_34 )
{
struct V_26 * V_49 = F_9 ( V_34 ,
struct V_26 ,
V_34 ) ;
struct V_26 * V_27 ;
bool V_50 = true ;
int V_51 ;
unsigned long V_37 ;
F_12 ( & V_49 -> V_34 , F_14 ) ;
F_17 ( & V_35 . V_47 , V_37 ) ;
F_21 (channel, &vmbus_connection.chn_list, listentry) {
if ( ! F_23 ( V_27 -> V_43 . V_52 . V_53 ,
V_49 -> V_43 . V_52 . V_53 ) &&
! F_23 ( V_27 -> V_43 . V_52 . V_54 ,
V_49 -> V_43 . V_52 . V_54 ) ) {
V_50 = false ;
break;
}
}
if ( V_50 )
F_24 ( & V_49 -> V_48 ,
& V_35 . V_55 ) ;
F_19 ( & V_35 . V_47 , V_37 ) ;
if ( ! V_50 ) {
if ( V_49 -> V_43 . V_52 . V_56 != 0 ) {
V_49 -> V_38 = V_27 ;
F_17 ( & V_27 -> V_30 , V_37 ) ;
F_24 ( & V_49 -> V_31 , & V_27 -> V_31 ) ;
F_19 ( & V_27 -> V_30 , V_37 ) ;
V_49 -> V_57 = V_58 ;
if ( V_27 -> V_59 != NULL )
V_27 -> V_59 ( V_49 ) ;
return;
}
F_11 ( V_49 ) ;
return;
}
V_49 -> V_57 = V_58 ;
V_49 -> V_41 = F_25 (
& V_49 -> V_43 . V_52 . V_53 ,
& V_49 -> V_43 . V_52 . V_54 ,
V_49 ) ;
V_51 = F_26 ( V_49 -> V_41 ) ;
if ( V_51 != 0 ) {
F_27 ( L_2 ,
V_49 -> V_43 . V_42 ) ;
F_17 ( & V_35 . V_47 , V_37 ) ;
F_18 ( & V_49 -> V_48 ) ;
F_19 ( & V_35 . V_47 , V_37 ) ;
F_7 ( V_49 -> V_41 ) ;
F_11 ( V_49 ) ;
}
}
static T_2 F_28 ( T_3 * V_60 )
{
T_2 V_61 ;
int V_16 ;
bool V_62 = false ;
T_2 V_63 = F_29 () ;
for ( V_16 = V_64 ; V_16 < V_65 ; V_16 ++ ) {
if ( ! memcmp ( V_60 -> V_66 , V_67 [ V_16 ] . V_68 ,
sizeof( T_3 ) ) ) {
V_62 = true ;
break;
}
}
if ( ( V_69 == V_70 ) ||
( V_69 == V_71 ) || ( ! V_62 ) ) {
return 0 ;
}
V_61 = ( ++ V_72 % V_63 ) ;
return V_73 . V_74 [ V_61 ] ;
}
static void F_30 ( struct V_75 * V_76 )
{
struct V_77 * V_52 ;
struct V_26 * V_49 ;
V_52 = (struct V_77 * ) V_76 ;
V_49 = F_2 () ;
if ( ! V_49 ) {
F_27 ( L_3 ) ;
return;
}
V_49 -> V_78 = true ;
V_49 -> V_79 = (struct V_80 * )
( F_31 ( ( unsigned long )
& V_49 -> V_81 ,
V_82 ) ) ;
V_49 -> V_79 -> V_83 . V_84 = 0 ;
V_49 -> V_79 -> V_83 . V_85 . V_86 = V_87 ;
V_49 -> V_79 -> V_88 = 0 ;
V_49 -> V_79 -> V_89 = 0 ;
if ( V_69 != V_70 ) {
V_49 -> V_90 =
( V_52 -> V_90 != 0 ) ;
V_49 -> V_79 -> V_83 . V_85 . V_86 =
V_52 -> V_91 ;
}
V_49 -> V_92 = F_28 ( & V_52 -> V_52 . V_53 ) ;
memcpy ( & V_49 -> V_43 , V_52 ,
sizeof( struct V_77 ) ) ;
V_49 -> V_93 = ( T_1 ) V_52 -> V_94 / 32 ;
V_49 -> V_95 = ( T_1 ) V_52 -> V_94 % 32 ;
F_12 ( & V_49 -> V_34 , F_22 ) ;
F_13 ( V_49 -> V_32 , & V_49 -> V_34 ) ;
}
static void F_32 ( struct V_75 * V_76 )
{
struct V_96 * V_97 ;
struct V_26 * V_27 ;
V_97 = (struct V_96 * ) V_76 ;
V_27 = F_33 ( V_97 -> V_42 ) ;
if ( V_27 == NULL )
return;
F_13 ( V_27 -> V_32 , & V_27 -> V_34 ) ;
}
static void F_34 (
struct V_75 * V_76 )
{
}
static void F_35 ( struct V_75 * V_76 )
{
struct V_98 * V_99 ;
struct V_100 * V_101 ;
struct V_75 * V_102 ;
struct V_103 * V_104 ;
unsigned long V_37 ;
V_99 = (struct V_98 * ) V_76 ;
F_17 ( & V_35 . V_105 , V_37 ) ;
F_21 (msginfo, &vmbus_connection.chn_msg_list,
msglistentry) {
V_102 =
(struct V_75 * ) V_101 -> V_40 ;
if ( V_102 -> V_45 == V_106 ) {
V_104 =
(struct V_103 * ) V_101 -> V_40 ;
if ( V_104 -> V_42 == V_99 -> V_42 &&
V_104 -> V_107 == V_99 -> V_107 ) {
memcpy ( & V_101 -> V_108 . V_109 ,
V_99 ,
sizeof(
struct V_98 ) ) ;
F_36 ( & V_101 -> V_110 ) ;
break;
}
}
}
F_19 ( & V_35 . V_105 , V_37 ) ;
}
static void F_37 ( struct V_75 * V_76 )
{
struct V_111 * V_112 ;
struct V_100 * V_101 ;
struct V_75 * V_102 ;
struct V_113 * V_114 ;
unsigned long V_37 ;
V_112 = (struct V_111 * ) V_76 ;
F_17 ( & V_35 . V_105 , V_37 ) ;
F_21 (msginfo, &vmbus_connection.chn_msg_list,
msglistentry) {
V_102 =
(struct V_75 * ) V_101 -> V_40 ;
if ( V_102 -> V_45 == V_115 ) {
V_114 =
(struct V_113 * ) V_102 ;
if ( ( V_112 -> V_42 ==
V_114 -> V_42 ) &&
( V_112 -> V_116 == V_114 -> V_116 ) ) {
memcpy ( & V_101 -> V_108 . V_117 ,
V_112 ,
sizeof(
struct V_111 ) ) ;
F_36 ( & V_101 -> V_110 ) ;
break;
}
}
}
F_19 ( & V_35 . V_105 , V_37 ) ;
}
static void F_38 (
struct V_75 * V_76 )
{
struct V_118 * V_119 ;
struct V_100 * V_101 ;
struct V_75 * V_102 ;
struct V_120 * V_121 ;
unsigned long V_37 ;
V_119 = (struct V_118 * ) V_76 ;
F_17 ( & V_35 . V_105 , V_37 ) ;
F_21 (msginfo, &vmbus_connection.chn_msg_list,
msglistentry) {
V_102 =
(struct V_75 * ) V_101 -> V_40 ;
if ( V_102 -> V_45 == V_122 ) {
V_121 =
(struct V_120 * ) V_102 ;
if ( V_119 -> V_116 == V_121 -> V_116 ) {
memcpy ( & V_101 -> V_108 . V_119 ,
V_119 ,
sizeof(
struct V_118 ) ) ;
F_36 ( & V_101 -> V_110 ) ;
break;
}
}
}
F_19 ( & V_35 . V_105 , V_37 ) ;
}
static void F_39 (
struct V_75 * V_76 )
{
struct V_100 * V_101 ;
struct V_75 * V_102 ;
struct V_123 * V_124 ;
unsigned long V_37 ;
V_124 = (struct V_123 * ) V_76 ;
F_17 ( & V_35 . V_105 , V_37 ) ;
F_21 (msginfo, &vmbus_connection.chn_msg_list,
msglistentry) {
V_102 =
(struct V_75 * ) V_101 -> V_40 ;
if ( V_102 -> V_45 ==
V_125 ) {
memcpy ( & V_101 -> V_108 . V_124 ,
V_124 ,
sizeof( struct V_123 ) ) ;
F_36 ( & V_101 -> V_110 ) ;
}
}
F_19 ( & V_35 . V_105 , V_37 ) ;
}
void F_40 ( void * V_126 )
{
struct V_127 * V_40 = V_126 ;
struct V_75 * V_76 ;
int V_128 ;
V_76 = (struct V_75 * ) V_40 -> V_85 . V_129 ;
V_128 = V_40 -> V_44 . V_130 ;
if ( V_76 -> V_45 >= V_131 ) {
F_27 ( L_4 ,
V_76 -> V_45 , V_128 ) ;
F_41 ( L_5 , V_132 ,
( unsigned char * ) V_40 -> V_85 . V_129 , V_128 ) ;
return;
}
if ( V_133 [ V_76 -> V_45 ] . V_134 )
V_133 [ V_76 -> V_45 ] . V_134 ( V_76 ) ;
else
F_27 ( L_6 , V_76 -> V_45 ) ;
}
int F_42 ( void )
{
struct V_75 * V_40 ;
struct V_100 * V_101 ;
int V_51 , V_135 ;
V_101 = F_43 ( sizeof( * V_101 ) +
sizeof( struct V_75 ) ,
V_136 ) ;
if ( ! V_101 )
return - V_137 ;
F_44 ( & V_101 -> V_110 ) ;
V_40 = (struct V_75 * ) V_101 -> V_40 ;
V_40 -> V_45 = V_138 ;
V_51 = F_16 ( V_40 ,
sizeof( struct V_75 ) ) ;
if ( V_51 != 0 ) {
F_27 ( L_7 , V_51 ) ;
goto V_139;
}
V_135 = F_45 ( & V_101 -> V_110 , 5 * V_140 ) ;
if ( V_135 == 0 ) {
V_51 = - V_141 ;
goto V_139;
}
V_139:
F_7 ( V_101 ) ;
return V_51 ;
}
struct V_26 * F_46 ( struct V_26 * V_142 )
{
struct V_143 * V_144 , * V_145 ;
int V_61 = V_73 . V_74 [ F_47 () ] ;
struct V_26 * V_146 ;
struct V_26 * V_147 = V_142 ;
int V_148 , V_149 ;
if ( F_48 ( & V_142 -> V_31 ) )
return V_147 ;
F_49 (cur, tmp, &primary->sc_list) {
V_146 = F_50 ( V_144 , struct V_26 , V_31 ) ;
if ( V_146 -> V_57 != V_150 )
continue;
if ( V_146 -> V_92 == V_61 )
return V_146 ;
V_148 = ( ( V_147 -> V_92 > V_61 ) ?
( V_147 -> V_92 - V_61 ) :
( V_61 - V_147 -> V_92 ) ) ;
V_149 = ( ( V_146 -> V_92 > V_61 ) ?
( V_146 -> V_92 - V_61 ) :
( V_61 - V_146 -> V_92 ) ) ;
if ( V_148 < V_149 )
continue;
V_147 = V_146 ;
}
return V_147 ;
}
static void F_51 ( struct V_26 * V_38 )
{
struct V_143 * V_144 , * V_145 ;
struct V_26 * V_146 ;
if ( V_38 -> V_59 == NULL )
return;
F_49 (cur, tmp, &primary_channel->sc_list) {
V_146 = F_50 ( V_144 , struct V_26 , V_31 ) ;
V_38 -> V_59 ( V_146 ) ;
}
}
void F_52 ( struct V_26 * V_38 ,
void (* F_53)( struct V_26 * V_151 ) )
{
V_38 -> V_59 = F_53 ;
}
bool F_54 ( struct V_26 * V_142 )
{
bool V_51 ;
V_51 = ! F_48 ( & V_142 -> V_31 ) ;
if ( V_51 ) {
F_51 ( V_142 ) ;
}
return V_51 ;
}
