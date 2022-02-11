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
struct V_45 * V_46 ;
if ( V_27 -> V_47 ) {
V_46 = F_20 ( & V_27 -> V_47 -> V_45 ) ;
if ( V_46 ) {
F_21 ( V_27 -> V_47 ) ;
F_22 ( V_46 ) ;
}
}
memset ( & V_44 , 0 , sizeof( struct V_43 ) ) ;
V_44 . V_48 = V_27 -> V_49 . V_48 ;
V_44 . V_50 . V_51 = V_52 ;
F_23 ( & V_44 , sizeof( struct V_43 ) ) ;
if ( V_27 -> V_53 != F_24 () ) {
F_25 () ;
F_26 ( V_27 -> V_53 ,
F_17 , V_27 , true ) ;
} else {
F_17 ( V_27 ) ;
F_25 () ;
}
if ( V_27 -> V_42 == NULL ) {
F_27 ( & V_36 . V_54 , V_41 ) ;
F_18 ( & V_27 -> V_55 ) ;
F_28 ( & V_36 . V_54 , V_41 ) ;
} else {
V_42 = V_27 -> V_42 ;
F_27 ( & V_42 -> V_30 , V_41 ) ;
F_18 ( & V_27 -> V_31 ) ;
F_28 ( & V_42 -> V_30 , V_41 ) ;
}
F_11 ( V_27 ) ;
}
void F_29 ( void )
{
struct V_26 * V_27 ;
F_30 (channel, &vmbus_connection.chn_list, listentry) {
F_21 ( V_27 -> V_47 ) ;
F_7 ( V_27 -> V_47 ) ;
F_11 ( V_27 ) ;
}
}
static void F_31 ( struct V_34 * V_35 )
{
struct V_26 * V_56 = F_9 ( V_35 ,
struct V_26 ,
V_35 ) ;
struct V_26 * V_27 ;
bool V_57 = true ;
bool V_58 = false ;
int V_59 ;
unsigned long V_41 ;
F_12 ( & V_56 -> V_35 , F_19 ) ;
F_27 ( & V_36 . V_54 , V_41 ) ;
F_30 (channel, &vmbus_connection.chn_list, listentry) {
if ( ! F_32 ( V_27 -> V_49 . V_60 . V_61 ,
V_56 -> V_49 . V_60 . V_61 ) &&
! F_32 ( V_27 -> V_49 . V_60 . V_62 ,
V_56 -> V_49 . V_60 . V_62 ) ) {
V_57 = false ;
break;
}
}
if ( V_57 ) {
F_16 ( & V_56 -> V_55 ,
& V_36 . V_63 ) ;
V_58 = true ;
}
F_28 ( & V_36 . V_54 , V_41 ) ;
if ( V_58 ) {
if ( V_56 -> V_53 != F_24 () ) {
F_25 () ;
F_26 ( V_56 -> V_53 ,
F_14 ,
V_56 , true ) ;
} else {
F_14 ( V_56 ) ;
F_25 () ;
}
}
if ( ! V_57 ) {
if ( V_56 -> V_49 . V_60 . V_64 != 0 ) {
V_56 -> V_42 = V_27 ;
F_27 ( & V_27 -> V_30 , V_41 ) ;
F_16 ( & V_56 -> V_31 , & V_27 -> V_31 ) ;
F_28 ( & V_27 -> V_30 , V_41 ) ;
if ( V_56 -> V_53 != F_24 () ) {
F_25 () ;
F_26 ( V_56 -> V_53 ,
F_14 ,
V_56 , true ) ;
} else {
F_14 ( V_56 ) ;
F_25 () ;
}
V_56 -> V_65 = V_66 ;
if ( V_27 -> V_67 != NULL )
V_27 -> V_67 ( V_56 ) ;
return;
}
F_11 ( V_56 ) ;
return;
}
V_56 -> V_65 = V_66 ;
V_56 -> V_47 = F_33 (
& V_56 -> V_49 . V_60 . V_61 ,
& V_56 -> V_49 . V_60 . V_62 ,
V_56 ) ;
V_59 = F_34 ( V_56 -> V_47 ) ;
if ( V_59 != 0 ) {
F_35 ( L_2 ,
V_56 -> V_49 . V_48 ) ;
F_27 ( & V_36 . V_54 , V_41 ) ;
F_18 ( & V_56 -> V_55 ) ;
F_28 ( & V_36 . V_54 , V_41 ) ;
F_7 ( V_56 -> V_47 ) ;
F_11 ( V_56 ) ;
}
}
static void F_36 ( struct V_26 * V_27 , const T_2 * V_68 )
{
T_3 V_69 ;
int V_16 ;
bool V_70 = false ;
T_3 V_71 = F_37 () ;
for ( V_16 = V_72 ; V_16 < V_73 ; V_16 ++ ) {
if ( ! memcmp ( V_68 -> V_74 , V_75 [ V_16 ] . V_76 ,
sizeof( T_2 ) ) ) {
V_70 = true ;
break;
}
}
if ( ( V_77 == V_78 ) ||
( V_77 == V_79 ) || ( ! V_70 ) ) {
V_27 -> V_53 = 0 ;
V_27 -> V_80 = 0 ;
return;
}
V_69 = ( ++ V_81 % V_71 ) ;
V_27 -> V_53 = V_69 ;
V_27 -> V_80 = V_40 . V_82 [ V_69 ] ;
}
static void F_38 ( struct V_83 * V_84 )
{
struct V_85 * V_60 ;
struct V_26 * V_56 ;
V_60 = (struct V_85 * ) V_84 ;
V_56 = F_2 () ;
if ( ! V_56 ) {
F_35 ( L_3 ) ;
return;
}
V_56 -> V_86 = true ;
V_56 -> V_87 = (struct V_88 * )
( F_39 ( ( unsigned long )
& V_56 -> V_89 ,
V_90 ) ) ;
V_56 -> V_87 -> V_91 . V_92 = 0 ;
V_56 -> V_87 -> V_91 . V_93 . V_94 = V_95 ;
V_56 -> V_87 -> V_96 = 0 ;
V_56 -> V_87 -> V_97 = 0 ;
if ( V_77 != V_78 ) {
V_56 -> V_98 =
( V_60 -> V_98 != 0 ) ;
V_56 -> V_87 -> V_91 . V_93 . V_94 =
V_60 -> V_99 ;
}
F_36 ( V_56 , & V_60 -> V_60 . V_61 ) ;
memcpy ( & V_56 -> V_49 , V_60 ,
sizeof( struct V_85 ) ) ;
V_56 -> V_100 = ( T_1 ) V_60 -> V_101 / 32 ;
V_56 -> V_102 = ( T_1 ) V_60 -> V_101 % 32 ;
F_12 ( & V_56 -> V_35 , F_31 ) ;
F_13 ( V_56 -> V_33 , & V_56 -> V_35 ) ;
}
static void F_40 ( struct V_83 * V_84 )
{
struct V_103 * V_104 ;
struct V_26 * V_27 ;
V_104 = (struct V_103 * ) V_84 ;
V_27 = F_41 ( V_104 -> V_48 ) ;
if ( V_27 == NULL )
return;
V_27 -> V_104 = true ;
F_13 ( V_27 -> V_33 , & V_27 -> V_35 ) ;
}
static void F_42 (
struct V_83 * V_84 )
{
}
static void F_43 ( struct V_83 * V_84 )
{
struct V_105 * V_106 ;
struct V_107 * V_108 ;
struct V_83 * V_109 ;
struct V_110 * V_111 ;
unsigned long V_41 ;
V_106 = (struct V_105 * ) V_84 ;
F_27 ( & V_36 . V_112 , V_41 ) ;
F_30 (msginfo, &vmbus_connection.chn_msg_list,
msglistentry) {
V_109 =
(struct V_83 * ) V_108 -> V_44 ;
if ( V_109 -> V_51 == V_113 ) {
V_111 =
(struct V_110 * ) V_108 -> V_44 ;
if ( V_111 -> V_48 == V_106 -> V_48 &&
V_111 -> V_114 == V_106 -> V_114 ) {
memcpy ( & V_108 -> V_115 . V_116 ,
V_106 ,
sizeof(
struct V_105 ) ) ;
F_44 ( & V_108 -> V_117 ) ;
break;
}
}
}
F_28 ( & V_36 . V_112 , V_41 ) ;
}
static void F_45 ( struct V_83 * V_84 )
{
struct V_118 * V_119 ;
struct V_107 * V_108 ;
struct V_83 * V_109 ;
struct V_120 * V_121 ;
unsigned long V_41 ;
V_119 = (struct V_118 * ) V_84 ;
F_27 ( & V_36 . V_112 , V_41 ) ;
F_30 (msginfo, &vmbus_connection.chn_msg_list,
msglistentry) {
V_109 =
(struct V_83 * ) V_108 -> V_44 ;
if ( V_109 -> V_51 == V_122 ) {
V_121 =
(struct V_120 * ) V_109 ;
if ( ( V_119 -> V_48 ==
V_121 -> V_48 ) &&
( V_119 -> V_123 == V_121 -> V_123 ) ) {
memcpy ( & V_108 -> V_115 . V_124 ,
V_119 ,
sizeof(
struct V_118 ) ) ;
F_44 ( & V_108 -> V_117 ) ;
break;
}
}
}
F_28 ( & V_36 . V_112 , V_41 ) ;
}
static void F_46 (
struct V_83 * V_84 )
{
struct V_125 * V_126 ;
struct V_107 * V_108 ;
struct V_83 * V_109 ;
struct V_127 * V_128 ;
unsigned long V_41 ;
V_126 = (struct V_125 * ) V_84 ;
F_27 ( & V_36 . V_112 , V_41 ) ;
F_30 (msginfo, &vmbus_connection.chn_msg_list,
msglistentry) {
V_109 =
(struct V_83 * ) V_108 -> V_44 ;
if ( V_109 -> V_51 == V_129 ) {
V_128 =
(struct V_127 * ) V_109 ;
if ( V_126 -> V_123 == V_128 -> V_123 ) {
memcpy ( & V_108 -> V_115 . V_126 ,
V_126 ,
sizeof(
struct V_125 ) ) ;
F_44 ( & V_108 -> V_117 ) ;
break;
}
}
}
F_28 ( & V_36 . V_112 , V_41 ) ;
}
static void F_47 (
struct V_83 * V_84 )
{
struct V_107 * V_108 ;
struct V_83 * V_109 ;
struct V_130 * V_131 ;
unsigned long V_41 ;
V_131 = (struct V_130 * ) V_84 ;
F_27 ( & V_36 . V_112 , V_41 ) ;
F_30 (msginfo, &vmbus_connection.chn_msg_list,
msglistentry) {
V_109 =
(struct V_83 * ) V_108 -> V_44 ;
if ( V_109 -> V_51 ==
V_132 ) {
memcpy ( & V_108 -> V_115 . V_131 ,
V_131 ,
sizeof( struct V_130 ) ) ;
F_44 ( & V_108 -> V_117 ) ;
}
}
F_28 ( & V_36 . V_112 , V_41 ) ;
}
void F_48 ( void * V_133 )
{
struct V_134 * V_44 = V_133 ;
struct V_83 * V_84 ;
int V_135 ;
V_84 = (struct V_83 * ) V_44 -> V_93 . V_136 ;
V_135 = V_44 -> V_50 . V_137 ;
if ( V_84 -> V_51 >= V_138 ) {
F_35 ( L_4 ,
V_84 -> V_51 , V_135 ) ;
F_49 ( L_5 , V_139 ,
( unsigned char * ) V_44 -> V_93 . V_136 , V_135 ) ;
return;
}
if ( V_140 [ V_84 -> V_51 ] . V_141 )
V_140 [ V_84 -> V_51 ] . V_141 ( V_84 ) ;
else
F_35 ( L_6 , V_84 -> V_51 ) ;
}
int F_50 ( void )
{
struct V_83 * V_44 ;
struct V_107 * V_108 ;
int V_59 , V_142 ;
V_108 = F_51 ( sizeof( * V_108 ) +
sizeof( struct V_83 ) ,
V_143 ) ;
if ( ! V_108 )
return - V_144 ;
F_52 ( & V_108 -> V_117 ) ;
V_44 = (struct V_83 * ) V_108 -> V_44 ;
V_44 -> V_51 = V_145 ;
V_59 = F_23 ( V_44 ,
sizeof( struct V_83 ) ) ;
if ( V_59 != 0 ) {
F_35 ( L_7 , V_59 ) ;
goto V_146;
}
V_142 = F_53 ( & V_108 -> V_117 , 5 * V_147 ) ;
if ( V_142 == 0 ) {
V_59 = - V_148 ;
goto V_146;
}
V_146:
F_7 ( V_108 ) ;
return V_59 ;
}
struct V_26 * F_54 ( struct V_26 * V_149 )
{
struct V_150 * V_151 , * V_152 ;
int V_69 = V_40 . V_82 [ F_15 () ] ;
struct V_26 * V_153 ;
struct V_26 * V_154 = V_149 ;
int V_155 , V_156 ;
if ( F_55 ( & V_149 -> V_31 ) )
return V_154 ;
F_56 (cur, tmp, &primary->sc_list) {
V_153 = F_57 ( V_151 , struct V_26 , V_31 ) ;
if ( V_153 -> V_65 != V_157 )
continue;
if ( V_153 -> V_80 == V_69 )
return V_153 ;
V_155 = ( ( V_154 -> V_80 > V_69 ) ?
( V_154 -> V_80 - V_69 ) :
( V_69 - V_154 -> V_80 ) ) ;
V_156 = ( ( V_153 -> V_80 > V_69 ) ?
( V_153 -> V_80 - V_69 ) :
( V_69 - V_153 -> V_80 ) ) ;
if ( V_155 < V_156 )
continue;
V_154 = V_153 ;
}
return V_154 ;
}
static void F_58 ( struct V_26 * V_42 )
{
struct V_150 * V_151 , * V_152 ;
struct V_26 * V_153 ;
if ( V_42 -> V_67 == NULL )
return;
F_56 (cur, tmp, &primary_channel->sc_list) {
V_153 = F_57 ( V_151 , struct V_26 , V_31 ) ;
V_42 -> V_67 ( V_153 ) ;
}
}
void F_59 ( struct V_26 * V_42 ,
void (* F_60)( struct V_26 * V_158 ) )
{
V_42 -> V_67 = F_60 ;
}
bool F_61 ( struct V_26 * V_149 )
{
bool V_59 ;
V_59 = ! F_55 ( & V_149 -> V_31 ) ;
if ( V_59 ) {
F_58 ( V_149 ) ;
}
return V_59 ;
}
