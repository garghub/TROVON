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
F_5 ( & V_27 -> V_32 ) ;
V_27 -> V_33 = F_6 ( L_1 ) ;
if ( ! V_27 -> V_33 ) {
F_7 ( V_27 ) ;
return NULL ;
}
return V_27 ;
}
static void F_8 ( struct V_34 * V_35 )
{
struct V_26 * V_27 = F_9 ( V_35 ,
struct V_26 ,
V_35 ) ;
F_10 ( V_27 -> V_33 ) ;
F_7 ( V_27 ) ;
}
static void F_11 ( struct V_26 * V_27 )
{
F_12 ( & V_27 -> V_35 , F_8 ) ;
F_13 ( V_36 . V_37 , & V_27 -> V_35 ) ;
}
static void F_14 ( void * V_38 )
{
struct V_26 * V_27 = V_38 ;
int V_39 = F_15 () ;
F_16 ( & V_27 -> V_32 , & V_40 . V_32 [ V_39 ] ) ;
}
static void F_17 ( void * V_38 )
{
struct V_26 * V_27 = V_38 ;
F_18 ( & V_27 -> V_32 ) ;
}
static void F_19 ( struct V_34 * V_35 )
{
struct V_26 * V_27 = F_9 ( V_35 ,
struct V_26 ,
V_35 ) ;
unsigned long V_41 ;
struct V_26 * V_42 ;
struct V_43 V_44 ;
if ( V_27 -> V_45 )
F_20 ( V_27 -> V_45 ) ;
memset ( & V_44 , 0 , sizeof( struct V_43 ) ) ;
V_44 . V_46 = V_27 -> V_47 . V_46 ;
V_44 . V_48 . V_49 = V_50 ;
F_21 ( & V_44 , sizeof( struct V_43 ) ) ;
if ( V_27 -> V_51 != F_15 () )
F_22 ( V_27 -> V_51 ,
F_17 , V_27 , true ) ;
else
F_17 ( V_27 ) ;
if ( V_27 -> V_42 == NULL ) {
F_23 ( & V_36 . V_52 , V_41 ) ;
F_18 ( & V_27 -> V_53 ) ;
F_24 ( & V_36 . V_52 , V_41 ) ;
} else {
V_42 = V_27 -> V_42 ;
F_23 ( & V_42 -> V_30 , V_41 ) ;
F_18 ( & V_27 -> V_31 ) ;
F_24 ( & V_42 -> V_30 , V_41 ) ;
}
F_11 ( V_27 ) ;
}
void F_25 ( void )
{
struct V_26 * V_27 ;
F_26 (channel, &vmbus_connection.chn_list, listentry) {
F_20 ( V_27 -> V_45 ) ;
F_7 ( V_27 -> V_45 ) ;
F_11 ( V_27 ) ;
}
}
static void F_27 ( struct V_34 * V_35 )
{
struct V_26 * V_54 = F_9 ( V_35 ,
struct V_26 ,
V_35 ) ;
struct V_26 * V_27 ;
bool V_55 = true ;
bool V_56 = false ;
int V_57 ;
unsigned long V_41 ;
F_12 ( & V_54 -> V_35 , F_19 ) ;
F_23 ( & V_36 . V_52 , V_41 ) ;
F_26 (channel, &vmbus_connection.chn_list, listentry) {
if ( ! F_28 ( V_27 -> V_47 . V_58 . V_59 ,
V_54 -> V_47 . V_58 . V_59 ) &&
! F_28 ( V_27 -> V_47 . V_58 . V_60 ,
V_54 -> V_47 . V_58 . V_60 ) ) {
V_55 = false ;
break;
}
}
if ( V_55 ) {
F_16 ( & V_54 -> V_53 ,
& V_36 . V_61 ) ;
V_56 = true ;
}
F_24 ( & V_36 . V_52 , V_41 ) ;
if ( V_56 ) {
if ( V_54 -> V_51 != F_15 () )
F_22 ( V_54 -> V_51 ,
F_14 ,
V_54 , true ) ;
else
F_14 ( V_54 ) ;
}
if ( ! V_55 ) {
if ( V_54 -> V_47 . V_58 . V_62 != 0 ) {
V_54 -> V_42 = V_27 ;
F_23 ( & V_27 -> V_30 , V_41 ) ;
F_16 ( & V_54 -> V_31 , & V_27 -> V_31 ) ;
F_24 ( & V_27 -> V_30 , V_41 ) ;
if ( V_54 -> V_51 != F_15 () )
F_22 ( V_54 -> V_51 ,
F_14 ,
V_54 , true ) ;
else
F_14 ( V_54 ) ;
V_54 -> V_63 = V_64 ;
if ( V_27 -> V_65 != NULL )
V_27 -> V_65 ( V_54 ) ;
return;
}
F_11 ( V_54 ) ;
return;
}
V_54 -> V_63 = V_64 ;
V_54 -> V_45 = F_29 (
& V_54 -> V_47 . V_58 . V_59 ,
& V_54 -> V_47 . V_58 . V_60 ,
V_54 ) ;
V_57 = F_30 ( V_54 -> V_45 ) ;
if ( V_57 != 0 ) {
F_31 ( L_2 ,
V_54 -> V_47 . V_46 ) ;
F_23 ( & V_36 . V_52 , V_41 ) ;
F_18 ( & V_54 -> V_53 ) ;
F_24 ( & V_36 . V_52 , V_41 ) ;
F_7 ( V_54 -> V_45 ) ;
F_11 ( V_54 ) ;
}
}
static void F_32 ( struct V_26 * V_27 , const T_2 * V_66 )
{
T_3 V_67 ;
int V_16 ;
bool V_68 = false ;
T_3 V_69 = F_33 () ;
for ( V_16 = V_70 ; V_16 < V_71 ; V_16 ++ ) {
if ( ! memcmp ( V_66 -> V_72 , V_73 [ V_16 ] . V_74 ,
sizeof( T_2 ) ) ) {
V_68 = true ;
break;
}
}
if ( ( V_75 == V_76 ) ||
( V_75 == V_77 ) || ( ! V_68 ) ) {
V_27 -> V_51 = 0 ;
V_27 -> V_78 = 0 ;
return;
}
V_67 = ( ++ V_79 % V_69 ) ;
V_27 -> V_51 = V_67 ;
V_27 -> V_78 = V_40 . V_80 [ V_67 ] ;
}
static void F_34 ( struct V_81 * V_82 )
{
struct V_83 * V_58 ;
struct V_26 * V_54 ;
V_58 = (struct V_83 * ) V_82 ;
V_54 = F_2 () ;
if ( ! V_54 ) {
F_31 ( L_3 ) ;
return;
}
V_54 -> V_84 = true ;
V_54 -> V_85 = (struct V_86 * )
( F_35 ( ( unsigned long )
& V_54 -> V_87 ,
V_88 ) ) ;
V_54 -> V_85 -> V_89 . V_90 = 0 ;
V_54 -> V_85 -> V_89 . V_91 . V_92 = V_93 ;
V_54 -> V_85 -> V_94 = 0 ;
V_54 -> V_85 -> V_95 = 0 ;
if ( V_75 != V_76 ) {
V_54 -> V_96 =
( V_58 -> V_96 != 0 ) ;
V_54 -> V_85 -> V_89 . V_91 . V_92 =
V_58 -> V_97 ;
}
F_32 ( V_54 , & V_58 -> V_58 . V_59 ) ;
memcpy ( & V_54 -> V_47 , V_58 ,
sizeof( struct V_83 ) ) ;
V_54 -> V_98 = ( T_1 ) V_58 -> V_99 / 32 ;
V_54 -> V_100 = ( T_1 ) V_58 -> V_99 % 32 ;
F_12 ( & V_54 -> V_35 , F_27 ) ;
F_13 ( V_54 -> V_33 , & V_54 -> V_35 ) ;
}
static void F_36 ( struct V_81 * V_82 )
{
struct V_101 * V_102 ;
struct V_26 * V_27 ;
V_102 = (struct V_101 * ) V_82 ;
V_27 = F_37 ( V_102 -> V_46 ) ;
if ( V_27 == NULL )
return;
F_13 ( V_27 -> V_33 , & V_27 -> V_35 ) ;
}
static void F_38 (
struct V_81 * V_82 )
{
}
static void F_39 ( struct V_81 * V_82 )
{
struct V_103 * V_104 ;
struct V_105 * V_106 ;
struct V_81 * V_107 ;
struct V_108 * V_109 ;
unsigned long V_41 ;
V_104 = (struct V_103 * ) V_82 ;
F_23 ( & V_36 . V_110 , V_41 ) ;
F_26 (msginfo, &vmbus_connection.chn_msg_list,
msglistentry) {
V_107 =
(struct V_81 * ) V_106 -> V_44 ;
if ( V_107 -> V_49 == V_111 ) {
V_109 =
(struct V_108 * ) V_106 -> V_44 ;
if ( V_109 -> V_46 == V_104 -> V_46 &&
V_109 -> V_112 == V_104 -> V_112 ) {
memcpy ( & V_106 -> V_113 . V_114 ,
V_104 ,
sizeof(
struct V_103 ) ) ;
F_40 ( & V_106 -> V_115 ) ;
break;
}
}
}
F_24 ( & V_36 . V_110 , V_41 ) ;
}
static void F_41 ( struct V_81 * V_82 )
{
struct V_116 * V_117 ;
struct V_105 * V_106 ;
struct V_81 * V_107 ;
struct V_118 * V_119 ;
unsigned long V_41 ;
V_117 = (struct V_116 * ) V_82 ;
F_23 ( & V_36 . V_110 , V_41 ) ;
F_26 (msginfo, &vmbus_connection.chn_msg_list,
msglistentry) {
V_107 =
(struct V_81 * ) V_106 -> V_44 ;
if ( V_107 -> V_49 == V_120 ) {
V_119 =
(struct V_118 * ) V_107 ;
if ( ( V_117 -> V_46 ==
V_119 -> V_46 ) &&
( V_117 -> V_121 == V_119 -> V_121 ) ) {
memcpy ( & V_106 -> V_113 . V_122 ,
V_117 ,
sizeof(
struct V_116 ) ) ;
F_40 ( & V_106 -> V_115 ) ;
break;
}
}
}
F_24 ( & V_36 . V_110 , V_41 ) ;
}
static void F_42 (
struct V_81 * V_82 )
{
struct V_123 * V_124 ;
struct V_105 * V_106 ;
struct V_81 * V_107 ;
struct V_125 * V_126 ;
unsigned long V_41 ;
V_124 = (struct V_123 * ) V_82 ;
F_23 ( & V_36 . V_110 , V_41 ) ;
F_26 (msginfo, &vmbus_connection.chn_msg_list,
msglistentry) {
V_107 =
(struct V_81 * ) V_106 -> V_44 ;
if ( V_107 -> V_49 == V_127 ) {
V_126 =
(struct V_125 * ) V_107 ;
if ( V_124 -> V_121 == V_126 -> V_121 ) {
memcpy ( & V_106 -> V_113 . V_124 ,
V_124 ,
sizeof(
struct V_123 ) ) ;
F_40 ( & V_106 -> V_115 ) ;
break;
}
}
}
F_24 ( & V_36 . V_110 , V_41 ) ;
}
static void F_43 (
struct V_81 * V_82 )
{
struct V_105 * V_106 ;
struct V_81 * V_107 ;
struct V_128 * V_129 ;
unsigned long V_41 ;
V_129 = (struct V_128 * ) V_82 ;
F_23 ( & V_36 . V_110 , V_41 ) ;
F_26 (msginfo, &vmbus_connection.chn_msg_list,
msglistentry) {
V_107 =
(struct V_81 * ) V_106 -> V_44 ;
if ( V_107 -> V_49 ==
V_130 ) {
memcpy ( & V_106 -> V_113 . V_129 ,
V_129 ,
sizeof( struct V_128 ) ) ;
F_40 ( & V_106 -> V_115 ) ;
}
}
F_24 ( & V_36 . V_110 , V_41 ) ;
}
void F_44 ( void * V_131 )
{
struct V_132 * V_44 = V_131 ;
struct V_81 * V_82 ;
int V_133 ;
V_82 = (struct V_81 * ) V_44 -> V_91 . V_134 ;
V_133 = V_44 -> V_48 . V_135 ;
if ( V_82 -> V_49 >= V_136 ) {
F_31 ( L_4 ,
V_82 -> V_49 , V_133 ) ;
F_45 ( L_5 , V_137 ,
( unsigned char * ) V_44 -> V_91 . V_134 , V_133 ) ;
return;
}
if ( V_138 [ V_82 -> V_49 ] . V_139 )
V_138 [ V_82 -> V_49 ] . V_139 ( V_82 ) ;
else
F_31 ( L_6 , V_82 -> V_49 ) ;
}
int F_46 ( void )
{
struct V_81 * V_44 ;
struct V_105 * V_106 ;
int V_57 , V_140 ;
V_106 = F_47 ( sizeof( * V_106 ) +
sizeof( struct V_81 ) ,
V_141 ) ;
if ( ! V_106 )
return - V_142 ;
F_48 ( & V_106 -> V_115 ) ;
V_44 = (struct V_81 * ) V_106 -> V_44 ;
V_44 -> V_49 = V_143 ;
V_57 = F_21 ( V_44 ,
sizeof( struct V_81 ) ) ;
if ( V_57 != 0 ) {
F_31 ( L_7 , V_57 ) ;
goto V_144;
}
V_140 = F_49 ( & V_106 -> V_115 , 5 * V_145 ) ;
if ( V_140 == 0 ) {
V_57 = - V_146 ;
goto V_144;
}
V_144:
F_7 ( V_106 ) ;
return V_57 ;
}
struct V_26 * F_50 ( struct V_26 * V_147 )
{
struct V_148 * V_149 , * V_150 ;
int V_67 = V_40 . V_80 [ F_15 () ] ;
struct V_26 * V_151 ;
struct V_26 * V_152 = V_147 ;
int V_153 , V_154 ;
if ( F_51 ( & V_147 -> V_31 ) )
return V_152 ;
F_52 (cur, tmp, &primary->sc_list) {
V_151 = F_53 ( V_149 , struct V_26 , V_31 ) ;
if ( V_151 -> V_63 != V_155 )
continue;
if ( V_151 -> V_78 == V_67 )
return V_151 ;
V_153 = ( ( V_152 -> V_78 > V_67 ) ?
( V_152 -> V_78 - V_67 ) :
( V_67 - V_152 -> V_78 ) ) ;
V_154 = ( ( V_151 -> V_78 > V_67 ) ?
( V_151 -> V_78 - V_67 ) :
( V_67 - V_151 -> V_78 ) ) ;
if ( V_153 < V_154 )
continue;
V_152 = V_151 ;
}
return V_152 ;
}
static void F_54 ( struct V_26 * V_42 )
{
struct V_148 * V_149 , * V_150 ;
struct V_26 * V_151 ;
if ( V_42 -> V_65 == NULL )
return;
F_52 (cur, tmp, &primary_channel->sc_list) {
V_151 = F_53 ( V_149 , struct V_26 , V_31 ) ;
V_42 -> V_65 ( V_151 ) ;
}
}
void F_55 ( struct V_26 * V_42 ,
void (* F_56)( struct V_26 * V_156 ) )
{
V_42 -> V_65 = F_56 ;
}
bool F_57 ( struct V_26 * V_147 )
{
bool V_57 ;
V_57 = ! F_51 ( & V_147 -> V_31 ) ;
if ( V_57 ) {
F_54 ( V_147 ) ;
}
return V_57 ;
}
