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
V_42 -> V_51 -- ;
F_21 ( & V_42 -> V_32 , V_41 ) ;
}
F_8 ( V_28 ) ;
}
void F_22 ( void )
{
struct V_26 * V_28 , * V_52 ;
F_23 (channel, tmp, &vmbus_connection.chn_list,
listentry) {
V_28 -> V_53 = true ;
F_24 ( V_28 -> V_54 ) ;
}
}
static void F_25 ( struct V_26 * V_55 )
{
struct V_26 * V_28 ;
bool V_56 = true ;
unsigned long V_41 ;
F_20 ( & V_48 . V_49 , V_41 ) ;
F_26 (channel, &vmbus_connection.chn_list, listentry) {
if ( ! F_27 ( V_28 -> V_57 . V_58 . V_59 ,
V_55 -> V_57 . V_58 . V_59 ) &&
! F_27 ( V_28 -> V_57 . V_58 . V_60 ,
V_55 -> V_57 . V_58 . V_60 ) ) {
V_56 = false ;
break;
}
}
if ( V_56 )
F_12 ( & V_55 -> V_50 ,
& V_48 . V_61 ) ;
F_21 ( & V_48 . V_49 , V_41 ) ;
if ( ! V_56 ) {
if ( V_55 -> V_57 . V_58 . V_62 != 0 ) {
V_55 -> V_42 = V_28 ;
F_20 ( & V_28 -> V_32 , V_41 ) ;
F_12 ( & V_55 -> V_33 , & V_28 -> V_33 ) ;
V_28 -> V_51 ++ ;
F_21 ( & V_28 -> V_32 , V_41 ) ;
} else
goto V_63;
}
F_28 ( V_55 , & V_55 -> V_57 . V_58 . V_59 ) ;
if ( V_55 -> V_47 != F_17 () ) {
F_18 () ;
F_19 ( V_55 -> V_47 ,
F_10 ,
V_55 , true ) ;
} else {
F_10 ( V_55 ) ;
F_18 () ;
}
V_55 -> V_64 = V_65 ;
if ( ! V_56 ) {
if ( V_28 -> V_66 != NULL )
V_28 -> V_66 ( V_55 ) ;
return;
}
V_55 -> V_54 = F_29 (
& V_55 -> V_57 . V_58 . V_59 ,
& V_55 -> V_57 . V_58 . V_60 ,
V_55 ) ;
if ( ! V_55 -> V_54 )
goto V_67;
if ( F_30 ( V_55 -> V_54 ) != 0 ) {
F_31 ( L_1 ,
V_55 -> V_57 . V_43 ) ;
F_9 ( V_55 -> V_54 ) ;
goto V_67;
}
return;
V_67:
F_20 ( & V_48 . V_49 , V_41 ) ;
F_14 ( & V_55 -> V_50 ) ;
F_21 ( & V_48 . V_49 , V_41 ) ;
if ( V_55 -> V_47 != F_17 () ) {
F_18 () ;
F_19 ( V_55 -> V_47 ,
F_13 , V_55 , true ) ;
} else {
F_13 ( V_55 ) ;
F_18 () ;
}
V_63:
F_8 ( V_55 ) ;
}
static void F_28 ( struct V_26 * V_28 , const T_4 * V_68 )
{
T_3 V_69 ;
int V_16 ;
bool V_70 = false ;
struct V_26 * V_71 = V_28 -> V_42 ;
int V_72 ;
struct V_73 V_74 ;
for ( V_16 = V_75 ; V_16 < V_76 ; V_16 ++ ) {
if ( ! memcmp ( V_68 -> V_77 , V_78 [ V_16 ] . V_79 ,
sizeof( T_4 ) ) ) {
V_70 = true ;
break;
}
}
if ( ( V_80 == V_81 ) ||
( V_80 == V_82 ) || ( ! V_70 ) ) {
V_28 -> V_83 = 0 ;
F_32 ( 0 , & V_28 -> V_84 ) ;
V_28 -> V_47 = 0 ;
V_28 -> V_85 = V_37 . V_86 [ 0 ] ;
return;
}
if ( ! V_71 ) {
while ( true ) {
V_72 = V_87 ++ ;
if ( V_72 == V_88 )
V_72 = V_87 = 0 ;
if ( F_33 ( F_34 ( V_72 ) ) )
continue;
break;
}
V_28 -> V_83 = V_72 ;
V_71 = V_28 ;
}
if ( F_35 ( & V_71 -> V_84 ) ==
F_35 ( F_34 ( V_71 -> V_83 ) ) ) {
F_36 ( & V_71 -> V_84 ) ;
}
F_37 ( & V_74 , & V_71 -> V_84 ,
F_34 ( V_71 -> V_83 ) ) ;
V_69 = F_38 ( - 1 , & V_74 ) ;
F_32 ( V_69 , & V_71 -> V_84 ) ;
V_28 -> V_47 = V_69 ;
V_28 -> V_85 = V_37 . V_86 [ V_69 ] ;
}
static void F_39 ( struct V_89 * V_90 )
{
F_40 ( & V_48 . V_91 ) ;
}
void F_41 ( void )
{
struct V_89 V_90 ;
F_42 ( & V_48 . V_91 ) ;
memset ( & V_90 , 0 , sizeof( struct V_89 ) ) ;
V_90 . V_45 = V_92 ;
F_16 ( & V_90 , sizeof( struct V_89 ) ) ;
F_43 ( & V_48 . V_91 ) ;
}
static void F_44 ( struct V_89 * V_90 )
{
struct V_93 * V_58 ;
struct V_26 * V_55 ;
V_58 = (struct V_93 * ) V_90 ;
V_55 = F_2 () ;
if ( ! V_55 ) {
F_31 ( L_2 ) ;
return;
}
V_55 -> V_94 = true ;
V_55 -> V_95 = (struct V_96 * )
( F_45 ( ( unsigned long )
& V_55 -> V_97 ,
V_98 ) ) ;
V_55 -> V_95 -> V_99 . V_100 = 0 ;
V_55 -> V_95 -> V_99 . V_101 . V_30 = V_102 ;
V_55 -> V_95 -> V_103 = 0 ;
V_55 -> V_95 -> V_104 = 0 ;
if ( V_80 != V_81 ) {
V_55 -> V_105 =
( V_58 -> V_105 != 0 ) ;
V_55 -> V_95 -> V_99 . V_101 . V_30 =
V_58 -> V_106 ;
}
memcpy ( & V_55 -> V_57 , V_58 ,
sizeof( struct V_93 ) ) ;
V_55 -> V_107 = ( T_1 ) V_58 -> V_108 / 32 ;
V_55 -> V_109 = ( T_1 ) V_58 -> V_108 % 32 ;
F_25 ( V_55 ) ;
}
static void F_46 ( struct V_89 * V_90 )
{
struct V_110 * V_53 ;
struct V_26 * V_28 ;
unsigned long V_41 ;
struct V_111 * V_112 ;
V_53 = (struct V_110 * ) V_90 ;
V_28 = F_47 ( V_53 -> V_43 ) ;
if ( V_28 == NULL ) {
F_15 ( NULL , V_53 -> V_43 ) ;
return;
}
F_20 ( & V_28 -> V_32 , V_41 ) ;
V_28 -> V_53 = true ;
F_21 ( & V_28 -> V_32 , V_41 ) ;
if ( V_28 -> V_54 ) {
V_112 = F_48 ( & V_28 -> V_54 -> V_111 ) ;
if ( V_112 ) {
F_24 ( V_28 -> V_54 ) ;
F_49 ( V_112 ) ;
}
} else {
F_15 ( V_28 ,
V_28 -> V_57 . V_43 ) ;
}
}
static void F_50 (
struct V_89 * V_90 )
{
}
static void F_51 ( struct V_89 * V_90 )
{
struct V_113 * V_114 ;
struct V_115 * V_116 ;
struct V_89 * V_117 ;
struct V_118 * V_119 ;
unsigned long V_41 ;
V_114 = (struct V_113 * ) V_90 ;
F_20 ( & V_48 . V_120 , V_41 ) ;
F_26 (msginfo, &vmbus_connection.chn_msg_list,
msglistentry) {
V_117 =
(struct V_89 * ) V_116 -> V_40 ;
if ( V_117 -> V_45 == V_121 ) {
V_119 =
(struct V_118 * ) V_116 -> V_40 ;
if ( V_119 -> V_43 == V_114 -> V_43 &&
V_119 -> V_122 == V_114 -> V_122 ) {
memcpy ( & V_116 -> V_123 . V_124 ,
V_114 ,
sizeof(
struct V_113 ) ) ;
F_40 ( & V_116 -> V_125 ) ;
break;
}
}
}
F_21 ( & V_48 . V_120 , V_41 ) ;
}
static void F_52 ( struct V_89 * V_90 )
{
struct V_126 * V_127 ;
struct V_115 * V_116 ;
struct V_89 * V_117 ;
struct V_128 * V_129 ;
unsigned long V_41 ;
V_127 = (struct V_126 * ) V_90 ;
F_20 ( & V_48 . V_120 , V_41 ) ;
F_26 (msginfo, &vmbus_connection.chn_msg_list,
msglistentry) {
V_117 =
(struct V_89 * ) V_116 -> V_40 ;
if ( V_117 -> V_45 == V_130 ) {
V_129 =
(struct V_128 * ) V_117 ;
if ( ( V_127 -> V_43 ==
V_129 -> V_43 ) &&
( V_127 -> V_131 == V_129 -> V_131 ) ) {
memcpy ( & V_116 -> V_123 . V_132 ,
V_127 ,
sizeof(
struct V_126 ) ) ;
F_40 ( & V_116 -> V_125 ) ;
break;
}
}
}
F_21 ( & V_48 . V_120 , V_41 ) ;
}
static void F_53 (
struct V_89 * V_90 )
{
struct V_133 * V_134 ;
struct V_115 * V_116 ;
struct V_89 * V_117 ;
struct V_135 * V_136 ;
unsigned long V_41 ;
V_134 = (struct V_133 * ) V_90 ;
F_20 ( & V_48 . V_120 , V_41 ) ;
F_26 (msginfo, &vmbus_connection.chn_msg_list,
msglistentry) {
V_117 =
(struct V_89 * ) V_116 -> V_40 ;
if ( V_117 -> V_45 == V_137 ) {
V_136 =
(struct V_135 * ) V_117 ;
if ( V_134 -> V_131 == V_136 -> V_131 ) {
memcpy ( & V_116 -> V_123 . V_134 ,
V_134 ,
sizeof(
struct V_133 ) ) ;
F_40 ( & V_116 -> V_125 ) ;
break;
}
}
}
F_21 ( & V_48 . V_120 , V_41 ) ;
}
static void F_54 (
struct V_89 * V_90 )
{
struct V_115 * V_116 ;
struct V_89 * V_117 ;
struct V_138 * V_139 ;
unsigned long V_41 ;
V_139 = (struct V_138 * ) V_90 ;
F_20 ( & V_48 . V_120 , V_41 ) ;
F_26 (msginfo, &vmbus_connection.chn_msg_list,
msglistentry) {
V_117 =
(struct V_89 * ) V_116 -> V_40 ;
if ( V_117 -> V_45 ==
V_140 ) {
memcpy ( & V_116 -> V_123 . V_139 ,
V_139 ,
sizeof( struct V_138 ) ) ;
F_40 ( & V_116 -> V_125 ) ;
}
}
F_21 ( & V_48 . V_120 , V_41 ) ;
}
void F_55 ( void * V_141 )
{
struct V_142 * V_40 = V_141 ;
struct V_89 * V_90 ;
int V_143 ;
V_90 = (struct V_89 * ) V_40 -> V_101 . V_144 ;
V_143 = V_40 -> V_44 . V_145 ;
if ( V_90 -> V_45 >= V_146 ) {
F_31 ( L_3 ,
V_90 -> V_45 , V_143 ) ;
F_56 ( L_4 , V_147 ,
( unsigned char * ) V_40 -> V_101 . V_144 , V_143 ) ;
return;
}
if ( V_148 [ V_90 -> V_45 ] . V_149 )
V_148 [ V_90 -> V_45 ] . V_149 ( V_90 ) ;
else
F_31 ( L_5 , V_90 -> V_45 ) ;
}
int F_57 ( void )
{
struct V_89 * V_40 ;
struct V_115 * V_116 ;
int V_150 ;
V_116 = F_58 ( sizeof( * V_116 ) +
sizeof( struct V_89 ) ,
V_151 ) ;
if ( ! V_116 )
return - V_152 ;
V_40 = (struct V_89 * ) V_116 -> V_40 ;
V_40 -> V_45 = V_153 ;
V_150 = F_16 ( V_40 ,
sizeof( struct V_89 ) ) ;
if ( V_150 != 0 ) {
F_31 ( L_6 , V_150 ) ;
goto V_154;
}
V_154:
F_9 ( V_116 ) ;
return V_150 ;
}
struct V_26 * F_59 ( struct V_26 * V_71 )
{
struct V_155 * V_156 , * V_52 ;
int V_69 ;
struct V_26 * V_157 ;
struct V_26 * V_158 = V_71 ;
int V_159 ;
int V_16 = 1 ;
if ( F_60 ( & V_71 -> V_33 ) )
return V_158 ;
V_159 = V_71 -> V_160 ++ ;
if ( V_159 > ( V_71 -> V_51 ) ) {
V_71 -> V_160 = 0 ;
return V_158 ;
}
V_69 = V_37 . V_86 [ F_17 () ] ;
F_18 () ;
F_61 (cur, tmp, &primary->sc_list) {
V_157 = F_62 ( V_156 , struct V_26 , V_33 ) ;
if ( V_157 -> V_64 != V_161 )
continue;
if ( V_157 -> V_85 == V_69 )
return V_157 ;
if ( V_16 == V_159 )
return V_157 ;
V_16 ++ ;
}
return V_158 ;
}
static void F_63 ( struct V_26 * V_42 )
{
struct V_155 * V_156 , * V_52 ;
struct V_26 * V_157 ;
if ( V_42 -> V_66 == NULL )
return;
F_61 (cur, tmp, &primary_channel->sc_list) {
V_157 = F_62 ( V_156 , struct V_26 , V_33 ) ;
V_42 -> V_66 ( V_157 ) ;
}
}
void F_64 ( struct V_26 * V_42 ,
void (* F_65)( struct V_26 * V_162 ) )
{
V_42 -> V_66 = F_65 ;
}
bool F_66 ( struct V_26 * V_71 )
{
bool V_150 ;
V_150 = ! F_60 ( & V_71 -> V_33 ) ;
if ( V_150 ) {
F_63 ( V_71 ) ;
}
return V_150 ;
}
