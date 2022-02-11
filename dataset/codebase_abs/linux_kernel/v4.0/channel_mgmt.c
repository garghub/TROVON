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
goto V_68;
}
goto V_69;
}
V_56 -> V_65 = V_66 ;
V_56 -> V_47 = F_33 (
& V_56 -> V_49 . V_60 . V_61 ,
& V_56 -> V_49 . V_60 . V_62 ,
V_56 ) ;
if ( ! V_56 -> V_47 )
goto V_69;
V_59 = F_34 ( V_56 -> V_47 ) ;
if ( V_59 != 0 ) {
F_35 ( L_2 ,
V_56 -> V_49 . V_48 ) ;
F_27 ( & V_36 . V_54 , V_41 ) ;
F_18 ( & V_56 -> V_55 ) ;
F_28 ( & V_36 . V_54 , V_41 ) ;
F_7 ( V_56 -> V_47 ) ;
goto V_69;
}
V_68:
F_27 ( & V_56 -> V_30 , V_41 ) ;
F_12 ( & V_56 -> V_35 , F_19 ) ;
if ( V_56 -> V_70 )
F_13 ( V_56 -> V_33 , & V_56 -> V_35 ) ;
F_28 ( & V_56 -> V_30 , V_41 ) ;
return;
V_69:
F_11 ( V_56 ) ;
}
static void F_36 ( struct V_26 * V_27 , const T_2 * V_71 )
{
T_3 V_72 ;
int V_16 ;
bool V_73 = false ;
T_3 V_74 = F_37 () ;
for ( V_16 = V_75 ; V_16 < V_76 ; V_16 ++ ) {
if ( ! memcmp ( V_71 -> V_77 , V_78 [ V_16 ] . V_79 ,
sizeof( T_2 ) ) ) {
V_73 = true ;
break;
}
}
if ( ( V_80 == V_81 ) ||
( V_80 == V_82 ) || ( ! V_73 ) ) {
V_27 -> V_53 = 0 ;
V_27 -> V_83 = 0 ;
return;
}
V_72 = ( ++ V_84 % V_74 ) ;
V_27 -> V_53 = V_72 ;
V_27 -> V_83 = V_40 . V_85 [ V_72 ] ;
}
static void F_38 ( struct V_86 * V_87 )
{
struct V_88 * V_60 ;
struct V_26 * V_56 ;
V_60 = (struct V_88 * ) V_87 ;
V_56 = F_2 () ;
if ( ! V_56 ) {
F_35 ( L_3 ) ;
return;
}
V_56 -> V_89 = true ;
V_56 -> V_90 = (struct V_91 * )
( F_39 ( ( unsigned long )
& V_56 -> V_92 ,
V_93 ) ) ;
V_56 -> V_90 -> V_94 . V_95 = 0 ;
V_56 -> V_90 -> V_94 . V_96 . V_97 = V_98 ;
V_56 -> V_90 -> V_99 = 0 ;
V_56 -> V_90 -> V_100 = 0 ;
if ( V_80 != V_81 ) {
V_56 -> V_101 =
( V_60 -> V_101 != 0 ) ;
V_56 -> V_90 -> V_94 . V_96 . V_97 =
V_60 -> V_102 ;
}
F_36 ( V_56 , & V_60 -> V_60 . V_61 ) ;
memcpy ( & V_56 -> V_49 , V_60 ,
sizeof( struct V_88 ) ) ;
V_56 -> V_103 = ( T_1 ) V_60 -> V_104 / 32 ;
V_56 -> V_105 = ( T_1 ) V_60 -> V_104 % 32 ;
F_12 ( & V_56 -> V_35 , F_31 ) ;
F_13 ( V_56 -> V_33 , & V_56 -> V_35 ) ;
}
static void F_40 ( struct V_86 * V_87 )
{
struct V_106 * V_70 ;
struct V_26 * V_27 ;
unsigned long V_41 ;
V_70 = (struct V_106 * ) V_87 ;
V_27 = F_41 ( V_70 -> V_48 ) ;
if ( V_27 == NULL )
return;
F_27 ( & V_27 -> V_30 , V_41 ) ;
V_27 -> V_70 = true ;
if ( V_27 -> V_35 . V_107 == F_19 )
F_13 ( V_27 -> V_33 , & V_27 -> V_35 ) ;
F_28 ( & V_27 -> V_30 , V_41 ) ;
}
static void F_42 (
struct V_86 * V_87 )
{
}
static void F_43 ( struct V_86 * V_87 )
{
struct V_108 * V_109 ;
struct V_110 * V_111 ;
struct V_86 * V_112 ;
struct V_113 * V_114 ;
unsigned long V_41 ;
V_109 = (struct V_108 * ) V_87 ;
F_27 ( & V_36 . V_115 , V_41 ) ;
F_30 (msginfo, &vmbus_connection.chn_msg_list,
msglistentry) {
V_112 =
(struct V_86 * ) V_111 -> V_44 ;
if ( V_112 -> V_51 == V_116 ) {
V_114 =
(struct V_113 * ) V_111 -> V_44 ;
if ( V_114 -> V_48 == V_109 -> V_48 &&
V_114 -> V_117 == V_109 -> V_117 ) {
memcpy ( & V_111 -> V_118 . V_119 ,
V_109 ,
sizeof(
struct V_108 ) ) ;
F_44 ( & V_111 -> V_120 ) ;
break;
}
}
}
F_28 ( & V_36 . V_115 , V_41 ) ;
}
static void F_45 ( struct V_86 * V_87 )
{
struct V_121 * V_122 ;
struct V_110 * V_111 ;
struct V_86 * V_112 ;
struct V_123 * V_124 ;
unsigned long V_41 ;
V_122 = (struct V_121 * ) V_87 ;
F_27 ( & V_36 . V_115 , V_41 ) ;
F_30 (msginfo, &vmbus_connection.chn_msg_list,
msglistentry) {
V_112 =
(struct V_86 * ) V_111 -> V_44 ;
if ( V_112 -> V_51 == V_125 ) {
V_124 =
(struct V_123 * ) V_112 ;
if ( ( V_122 -> V_48 ==
V_124 -> V_48 ) &&
( V_122 -> V_126 == V_124 -> V_126 ) ) {
memcpy ( & V_111 -> V_118 . V_127 ,
V_122 ,
sizeof(
struct V_121 ) ) ;
F_44 ( & V_111 -> V_120 ) ;
break;
}
}
}
F_28 ( & V_36 . V_115 , V_41 ) ;
}
static void F_46 (
struct V_86 * V_87 )
{
struct V_128 * V_129 ;
struct V_110 * V_111 ;
struct V_86 * V_112 ;
struct V_130 * V_131 ;
unsigned long V_41 ;
V_129 = (struct V_128 * ) V_87 ;
F_27 ( & V_36 . V_115 , V_41 ) ;
F_30 (msginfo, &vmbus_connection.chn_msg_list,
msglistentry) {
V_112 =
(struct V_86 * ) V_111 -> V_44 ;
if ( V_112 -> V_51 == V_132 ) {
V_131 =
(struct V_130 * ) V_112 ;
if ( V_129 -> V_126 == V_131 -> V_126 ) {
memcpy ( & V_111 -> V_118 . V_129 ,
V_129 ,
sizeof(
struct V_128 ) ) ;
F_44 ( & V_111 -> V_120 ) ;
break;
}
}
}
F_28 ( & V_36 . V_115 , V_41 ) ;
}
static void F_47 (
struct V_86 * V_87 )
{
struct V_110 * V_111 ;
struct V_86 * V_112 ;
struct V_133 * V_134 ;
unsigned long V_41 ;
V_134 = (struct V_133 * ) V_87 ;
F_27 ( & V_36 . V_115 , V_41 ) ;
F_30 (msginfo, &vmbus_connection.chn_msg_list,
msglistentry) {
V_112 =
(struct V_86 * ) V_111 -> V_44 ;
if ( V_112 -> V_51 ==
V_135 ) {
memcpy ( & V_111 -> V_118 . V_134 ,
V_134 ,
sizeof( struct V_133 ) ) ;
F_44 ( & V_111 -> V_120 ) ;
}
}
F_28 ( & V_36 . V_115 , V_41 ) ;
}
void F_48 ( void * V_136 )
{
struct V_137 * V_44 = V_136 ;
struct V_86 * V_87 ;
int V_138 ;
V_87 = (struct V_86 * ) V_44 -> V_96 . V_139 ;
V_138 = V_44 -> V_50 . V_140 ;
if ( V_87 -> V_51 >= V_141 ) {
F_35 ( L_4 ,
V_87 -> V_51 , V_138 ) ;
F_49 ( L_5 , V_142 ,
( unsigned char * ) V_44 -> V_96 . V_139 , V_138 ) ;
return;
}
if ( V_143 [ V_87 -> V_51 ] . V_144 )
V_143 [ V_87 -> V_51 ] . V_144 ( V_87 ) ;
else
F_35 ( L_6 , V_87 -> V_51 ) ;
}
int F_50 ( void )
{
struct V_86 * V_44 ;
struct V_110 * V_111 ;
int V_59 , V_145 ;
V_111 = F_51 ( sizeof( * V_111 ) +
sizeof( struct V_86 ) ,
V_146 ) ;
if ( ! V_111 )
return - V_147 ;
F_52 ( & V_111 -> V_120 ) ;
V_44 = (struct V_86 * ) V_111 -> V_44 ;
V_44 -> V_51 = V_148 ;
V_59 = F_23 ( V_44 ,
sizeof( struct V_86 ) ) ;
if ( V_59 != 0 ) {
F_35 ( L_7 , V_59 ) ;
goto V_149;
}
V_145 = F_53 ( & V_111 -> V_120 , 5 * V_150 ) ;
if ( V_145 == 0 ) {
V_59 = - V_151 ;
goto V_149;
}
V_149:
F_7 ( V_111 ) ;
return V_59 ;
}
struct V_26 * F_54 ( struct V_26 * V_152 )
{
struct V_153 * V_154 , * V_155 ;
int V_72 ;
struct V_26 * V_156 ;
struct V_26 * V_157 = V_152 ;
int V_158 , V_159 ;
if ( F_55 ( & V_152 -> V_31 ) )
return V_157 ;
V_72 = V_40 . V_85 [ F_24 () ] ;
F_25 () ;
F_56 (cur, tmp, &primary->sc_list) {
V_156 = F_57 ( V_154 , struct V_26 , V_31 ) ;
if ( V_156 -> V_65 != V_160 )
continue;
if ( V_156 -> V_83 == V_72 )
return V_156 ;
V_158 = ( ( V_157 -> V_83 > V_72 ) ?
( V_157 -> V_83 - V_72 ) :
( V_72 - V_157 -> V_83 ) ) ;
V_159 = ( ( V_156 -> V_83 > V_72 ) ?
( V_156 -> V_83 - V_72 ) :
( V_72 - V_156 -> V_83 ) ) ;
if ( V_158 < V_159 )
continue;
V_157 = V_156 ;
}
return V_157 ;
}
static void F_58 ( struct V_26 * V_42 )
{
struct V_153 * V_154 , * V_155 ;
struct V_26 * V_156 ;
if ( V_42 -> V_67 == NULL )
return;
F_56 (cur, tmp, &primary_channel->sc_list) {
V_156 = F_57 ( V_154 , struct V_26 , V_31 ) ;
V_42 -> V_67 ( V_156 ) ;
}
}
void F_59 ( struct V_26 * V_42 ,
void (* F_60)( struct V_26 * V_161 ) )
{
V_42 -> V_67 = F_60 ;
}
bool F_61 ( struct V_26 * V_152 )
{
bool V_59 ;
V_59 = ! F_55 ( & V_152 -> V_31 ) ;
if ( V_59 ) {
F_58 ( V_152 ) ;
}
return V_59 ;
}
