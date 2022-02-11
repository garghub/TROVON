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
static T_2 V_27 = F_3 ( 0 ) ;
struct V_26 * V_28 ;
V_28 = F_4 ( sizeof( * V_28 ) , V_29 ) ;
if ( ! V_28 )
return NULL ;
V_28 -> V_30 = F_5 ( & V_27 ) ;
F_6 ( & V_28 -> V_31 ) ;
F_6 ( & V_28 -> V_32 ) ;
F_7 ( & V_28 -> V_33 ) ;
F_7 ( & V_28 -> V_34 ) ;
return V_28 ;
}
static void F_8 ( struct V_26 * V_28 )
{
F_9 ( V_28 ) ;
}
static void F_10 ( void * V_35 )
{
struct V_26 * V_28 = V_35 ;
int V_36 = F_11 () ;
F_12 ( & V_28 -> V_34 , & V_37 . V_34 [ V_36 ] ) ;
}
static void F_13 ( void * V_35 )
{
struct V_26 * V_28 = V_35 ;
F_14 ( & V_28 -> V_34 ) ;
}
void F_15 ( struct V_26 * V_28 , T_3 V_38 )
{
struct V_39 V_40 ;
unsigned long V_41 ;
struct V_26 * V_42 ;
memset ( & V_40 , 0 , sizeof( struct V_39 ) ) ;
V_40 . V_43 = V_38 ;
V_40 . V_44 . V_45 = V_46 ;
F_16 ( & V_40 , sizeof( struct V_39 ) ) ;
if ( V_28 == NULL )
return;
if ( V_28 -> V_47 != F_17 () ) {
F_18 () ;
F_19 ( V_28 -> V_47 ,
F_13 , V_28 , true ) ;
} else {
F_13 ( V_28 ) ;
F_18 () ;
}
if ( V_28 -> V_42 == NULL ) {
F_20 ( & V_48 . V_49 , V_41 ) ;
F_14 ( & V_28 -> V_50 ) ;
F_21 ( & V_48 . V_49 , V_41 ) ;
} else {
V_42 = V_28 -> V_42 ;
F_20 ( & V_42 -> V_32 , V_41 ) ;
F_14 ( & V_28 -> V_33 ) ;
F_21 ( & V_42 -> V_32 , V_41 ) ;
}
F_8 ( V_28 ) ;
}
void F_22 ( void )
{
struct V_26 * V_28 ;
F_23 (channel, &vmbus_connection.chn_list, listentry) {
F_24 ( V_28 -> V_51 ) ;
F_8 ( V_28 ) ;
}
}
static void F_25 ( struct V_26 * V_52 )
{
struct V_26 * V_28 ;
bool V_53 = true ;
bool V_54 = false ;
unsigned long V_41 ;
F_20 ( & V_48 . V_49 , V_41 ) ;
F_23 (channel, &vmbus_connection.chn_list, listentry) {
if ( ! F_26 ( V_28 -> V_55 . V_56 . V_57 ,
V_52 -> V_55 . V_56 . V_57 ) &&
! F_26 ( V_28 -> V_55 . V_56 . V_58 ,
V_52 -> V_55 . V_56 . V_58 ) ) {
V_53 = false ;
break;
}
}
if ( V_53 ) {
F_12 ( & V_52 -> V_50 ,
& V_48 . V_59 ) ;
V_54 = true ;
}
F_21 ( & V_48 . V_49 , V_41 ) ;
if ( V_54 ) {
if ( V_52 -> V_47 != F_17 () ) {
F_18 () ;
F_19 ( V_52 -> V_47 ,
F_10 ,
V_52 , true ) ;
} else {
F_10 ( V_52 ) ;
F_18 () ;
}
}
if ( ! V_53 ) {
if ( V_52 -> V_55 . V_56 . V_60 != 0 ) {
V_52 -> V_42 = V_28 ;
F_20 ( & V_28 -> V_32 , V_41 ) ;
F_12 ( & V_52 -> V_33 , & V_28 -> V_33 ) ;
F_21 ( & V_28 -> V_32 , V_41 ) ;
if ( V_52 -> V_47 != F_17 () ) {
F_18 () ;
F_19 ( V_52 -> V_47 ,
F_10 ,
V_52 , true ) ;
} else {
F_10 ( V_52 ) ;
F_18 () ;
}
V_52 -> V_61 = V_62 ;
V_28 -> V_63 ++ ;
if ( V_28 -> V_64 != NULL )
V_28 -> V_64 ( V_52 ) ;
return;
}
goto V_65;
}
V_52 -> V_61 = V_62 ;
V_52 -> V_51 = F_27 (
& V_52 -> V_55 . V_56 . V_57 ,
& V_52 -> V_55 . V_56 . V_58 ,
V_52 ) ;
if ( ! V_52 -> V_51 )
goto V_66;
if ( F_28 ( V_52 -> V_51 ) != 0 ) {
F_29 ( L_1 ,
V_52 -> V_55 . V_43 ) ;
F_9 ( V_52 -> V_51 ) ;
goto V_66;
}
return;
V_66:
F_20 ( & V_48 . V_49 , V_41 ) ;
F_14 ( & V_52 -> V_50 ) ;
F_21 ( & V_48 . V_49 , V_41 ) ;
if ( V_52 -> V_47 != F_17 () ) {
F_18 () ;
F_19 ( V_52 -> V_47 ,
F_13 , V_52 , true ) ;
} else {
F_13 ( V_52 ) ;
F_18 () ;
}
V_65:
F_8 ( V_52 ) ;
}
static void F_30 ( struct V_26 * V_28 , const T_4 * V_67 )
{
T_3 V_68 ;
int V_16 ;
bool V_69 = false ;
T_3 V_70 = F_31 () ;
for ( V_16 = V_71 ; V_16 < V_72 ; V_16 ++ ) {
if ( ! memcmp ( V_67 -> V_73 , V_74 [ V_16 ] . V_75 ,
sizeof( T_4 ) ) ) {
V_69 = true ;
break;
}
}
if ( ( V_76 == V_77 ) ||
( V_76 == V_78 ) || ( ! V_69 ) ) {
V_28 -> V_47 = 0 ;
V_28 -> V_79 = 0 ;
return;
}
V_68 = ( ++ V_80 % V_70 ) ;
V_28 -> V_47 = V_68 ;
V_28 -> V_79 = V_37 . V_81 [ V_68 ] ;
}
static void F_32 ( struct V_82 * V_83 )
{
struct V_84 * V_56 ;
struct V_26 * V_52 ;
V_56 = (struct V_84 * ) V_83 ;
V_52 = F_2 () ;
if ( ! V_52 ) {
F_29 ( L_2 ) ;
return;
}
V_52 -> V_85 = true ;
V_52 -> V_86 = (struct V_87 * )
( F_33 ( ( unsigned long )
& V_52 -> V_88 ,
V_89 ) ) ;
V_52 -> V_86 -> V_90 . V_91 = 0 ;
V_52 -> V_86 -> V_90 . V_92 . V_30 = V_93 ;
V_52 -> V_86 -> V_94 = 0 ;
V_52 -> V_86 -> V_95 = 0 ;
if ( V_76 != V_77 ) {
V_52 -> V_96 =
( V_56 -> V_96 != 0 ) ;
V_52 -> V_86 -> V_90 . V_92 . V_30 =
V_56 -> V_97 ;
}
F_30 ( V_52 , & V_56 -> V_56 . V_57 ) ;
memcpy ( & V_52 -> V_55 , V_56 ,
sizeof( struct V_84 ) ) ;
V_52 -> V_98 = ( T_1 ) V_56 -> V_99 / 32 ;
V_52 -> V_100 = ( T_1 ) V_56 -> V_99 % 32 ;
F_25 ( V_52 ) ;
}
static void F_34 ( struct V_82 * V_83 )
{
struct V_101 * V_102 ;
struct V_26 * V_28 ;
unsigned long V_41 ;
struct V_103 * V_104 ;
V_102 = (struct V_101 * ) V_83 ;
V_28 = F_35 ( V_102 -> V_43 ) ;
if ( V_28 == NULL ) {
F_15 ( NULL , V_102 -> V_43 ) ;
return;
}
F_20 ( & V_28 -> V_32 , V_41 ) ;
V_28 -> V_102 = true ;
F_21 ( & V_28 -> V_32 , V_41 ) ;
if ( V_28 -> V_51 ) {
V_104 = F_36 ( & V_28 -> V_51 -> V_103 ) ;
if ( V_104 ) {
F_24 ( V_28 -> V_51 ) ;
F_37 ( V_104 ) ;
}
} else {
F_15 ( V_28 ,
V_28 -> V_55 . V_43 ) ;
}
}
static void F_38 (
struct V_82 * V_83 )
{
}
static void F_39 ( struct V_82 * V_83 )
{
struct V_105 * V_106 ;
struct V_107 * V_108 ;
struct V_82 * V_109 ;
struct V_110 * V_111 ;
unsigned long V_41 ;
V_106 = (struct V_105 * ) V_83 ;
F_20 ( & V_48 . V_112 , V_41 ) ;
F_23 (msginfo, &vmbus_connection.chn_msg_list,
msglistentry) {
V_109 =
(struct V_82 * ) V_108 -> V_40 ;
if ( V_109 -> V_45 == V_113 ) {
V_111 =
(struct V_110 * ) V_108 -> V_40 ;
if ( V_111 -> V_43 == V_106 -> V_43 &&
V_111 -> V_114 == V_106 -> V_114 ) {
memcpy ( & V_108 -> V_115 . V_116 ,
V_106 ,
sizeof(
struct V_105 ) ) ;
F_40 ( & V_108 -> V_117 ) ;
break;
}
}
}
F_21 ( & V_48 . V_112 , V_41 ) ;
}
static void F_41 ( struct V_82 * V_83 )
{
struct V_118 * V_119 ;
struct V_107 * V_108 ;
struct V_82 * V_109 ;
struct V_120 * V_121 ;
unsigned long V_41 ;
V_119 = (struct V_118 * ) V_83 ;
F_20 ( & V_48 . V_112 , V_41 ) ;
F_23 (msginfo, &vmbus_connection.chn_msg_list,
msglistentry) {
V_109 =
(struct V_82 * ) V_108 -> V_40 ;
if ( V_109 -> V_45 == V_122 ) {
V_121 =
(struct V_120 * ) V_109 ;
if ( ( V_119 -> V_43 ==
V_121 -> V_43 ) &&
( V_119 -> V_123 == V_121 -> V_123 ) ) {
memcpy ( & V_108 -> V_115 . V_124 ,
V_119 ,
sizeof(
struct V_118 ) ) ;
F_40 ( & V_108 -> V_117 ) ;
break;
}
}
}
F_21 ( & V_48 . V_112 , V_41 ) ;
}
static void F_42 (
struct V_82 * V_83 )
{
struct V_125 * V_126 ;
struct V_107 * V_108 ;
struct V_82 * V_109 ;
struct V_127 * V_128 ;
unsigned long V_41 ;
V_126 = (struct V_125 * ) V_83 ;
F_20 ( & V_48 . V_112 , V_41 ) ;
F_23 (msginfo, &vmbus_connection.chn_msg_list,
msglistentry) {
V_109 =
(struct V_82 * ) V_108 -> V_40 ;
if ( V_109 -> V_45 == V_129 ) {
V_128 =
(struct V_127 * ) V_109 ;
if ( V_126 -> V_123 == V_128 -> V_123 ) {
memcpy ( & V_108 -> V_115 . V_126 ,
V_126 ,
sizeof(
struct V_125 ) ) ;
F_40 ( & V_108 -> V_117 ) ;
break;
}
}
}
F_21 ( & V_48 . V_112 , V_41 ) ;
}
static void F_43 (
struct V_82 * V_83 )
{
struct V_107 * V_108 ;
struct V_82 * V_109 ;
struct V_130 * V_131 ;
unsigned long V_41 ;
V_131 = (struct V_130 * ) V_83 ;
F_20 ( & V_48 . V_112 , V_41 ) ;
F_23 (msginfo, &vmbus_connection.chn_msg_list,
msglistentry) {
V_109 =
(struct V_82 * ) V_108 -> V_40 ;
if ( V_109 -> V_45 ==
V_132 ) {
memcpy ( & V_108 -> V_115 . V_131 ,
V_131 ,
sizeof( struct V_130 ) ) ;
F_40 ( & V_108 -> V_117 ) ;
}
}
F_21 ( & V_48 . V_112 , V_41 ) ;
}
void F_44 ( void * V_133 )
{
struct V_134 * V_40 = V_133 ;
struct V_82 * V_83 ;
int V_135 ;
V_83 = (struct V_82 * ) V_40 -> V_92 . V_136 ;
V_135 = V_40 -> V_44 . V_137 ;
if ( V_83 -> V_45 >= V_138 ) {
F_29 ( L_3 ,
V_83 -> V_45 , V_135 ) ;
F_45 ( L_4 , V_139 ,
( unsigned char * ) V_40 -> V_92 . V_136 , V_135 ) ;
return;
}
if ( V_140 [ V_83 -> V_45 ] . V_141 )
V_140 [ V_83 -> V_45 ] . V_141 ( V_83 ) ;
else
F_29 ( L_5 , V_83 -> V_45 ) ;
}
int F_46 ( void )
{
struct V_82 * V_40 ;
struct V_107 * V_108 ;
int V_142 ;
V_108 = F_47 ( sizeof( * V_108 ) +
sizeof( struct V_82 ) ,
V_143 ) ;
if ( ! V_108 )
return - V_144 ;
V_40 = (struct V_82 * ) V_108 -> V_40 ;
V_40 -> V_45 = V_145 ;
V_142 = F_16 ( V_40 ,
sizeof( struct V_82 ) ) ;
if ( V_142 != 0 ) {
F_29 ( L_6 , V_142 ) ;
goto V_146;
}
V_146:
F_9 ( V_108 ) ;
return V_142 ;
}
struct V_26 * F_48 ( struct V_26 * V_147 )
{
struct V_148 * V_149 , * V_150 ;
int V_68 ;
struct V_26 * V_151 ;
struct V_26 * V_152 = V_147 ;
int V_153 ;
int V_16 = 1 ;
if ( F_49 ( & V_147 -> V_33 ) )
return V_152 ;
V_153 = V_147 -> V_154 ++ ;
if ( V_153 > ( V_147 -> V_63 ) ) {
V_147 -> V_154 = 0 ;
return V_152 ;
}
V_68 = V_37 . V_81 [ F_17 () ] ;
F_18 () ;
F_50 (cur, tmp, &primary->sc_list) {
V_151 = F_51 ( V_149 , struct V_26 , V_33 ) ;
if ( V_151 -> V_61 != V_155 )
continue;
if ( V_151 -> V_79 == V_68 )
return V_151 ;
if ( V_16 == V_153 )
return V_151 ;
V_16 ++ ;
}
return V_152 ;
}
static void F_52 ( struct V_26 * V_42 )
{
struct V_148 * V_149 , * V_150 ;
struct V_26 * V_151 ;
if ( V_42 -> V_64 == NULL )
return;
F_50 (cur, tmp, &primary_channel->sc_list) {
V_151 = F_51 ( V_149 , struct V_26 , V_33 ) ;
V_42 -> V_64 ( V_151 ) ;
}
}
void F_53 ( struct V_26 * V_42 ,
void (* F_54)( struct V_26 * V_156 ) )
{
V_42 -> V_64 = F_54 ;
}
bool F_55 ( struct V_26 * V_147 )
{
bool V_142 ;
V_142 = ! F_49 ( & V_147 -> V_33 ) ;
if ( V_142 ) {
F_52 ( V_147 ) ;
}
return V_142 ;
}
