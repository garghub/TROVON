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
V_42 = V_28 ;
} else {
V_42 = V_28 -> V_42 ;
F_20 ( & V_42 -> V_32 , V_41 ) ;
F_14 ( & V_28 -> V_33 ) ;
V_42 -> V_51 -- ;
F_21 ( & V_42 -> V_32 , V_41 ) ;
}
F_22 ( V_28 -> V_47 ,
& V_42 -> V_52 ) ;
F_8 ( V_28 ) ;
}
void F_23 ( void )
{
struct V_26 * V_28 , * V_53 ;
F_24 (channel, tmp, &vmbus_connection.chn_list,
listentry) {
V_28 -> V_54 = true ;
F_25 ( V_28 -> V_55 ) ;
}
}
static void F_26 ( struct V_26 * V_56 )
{
struct V_26 * V_28 ;
bool V_57 = true ;
unsigned long V_41 ;
F_20 ( & V_48 . V_49 , V_41 ) ;
F_27 (channel, &vmbus_connection.chn_list, listentry) {
if ( ! F_28 ( V_28 -> V_58 . V_59 . V_60 ,
V_56 -> V_58 . V_59 . V_60 ) &&
! F_28 ( V_28 -> V_58 . V_59 . V_61 ,
V_56 -> V_58 . V_59 . V_61 ) ) {
V_57 = false ;
break;
}
}
if ( V_57 )
F_12 ( & V_56 -> V_50 ,
& V_48 . V_62 ) ;
F_21 ( & V_48 . V_49 , V_41 ) ;
if ( ! V_57 ) {
if ( V_56 -> V_58 . V_59 . V_63 != 0 ) {
V_56 -> V_42 = V_28 ;
F_20 ( & V_28 -> V_32 , V_41 ) ;
F_12 ( & V_56 -> V_33 , & V_28 -> V_33 ) ;
V_28 -> V_51 ++ ;
F_21 ( & V_28 -> V_32 , V_41 ) ;
} else
goto V_64;
}
F_29 ( V_56 , & V_56 -> V_58 . V_59 . V_60 ) ;
if ( V_56 -> V_47 != F_17 () ) {
F_18 () ;
F_19 ( V_56 -> V_47 ,
F_10 ,
V_56 , true ) ;
} else {
F_10 ( V_56 ) ;
F_18 () ;
}
V_56 -> V_65 = V_66 ;
if ( ! V_57 ) {
if ( V_28 -> V_67 != NULL )
V_28 -> V_67 ( V_56 ) ;
return;
}
V_56 -> V_55 = F_30 (
& V_56 -> V_58 . V_59 . V_60 ,
& V_56 -> V_58 . V_59 . V_61 ,
V_56 ) ;
if ( ! V_56 -> V_55 )
goto V_68;
if ( F_31 ( V_56 -> V_55 ) != 0 ) {
F_32 ( L_1 ,
V_56 -> V_58 . V_43 ) ;
F_9 ( V_56 -> V_55 ) ;
goto V_68;
}
return;
V_68:
F_20 ( & V_48 . V_49 , V_41 ) ;
F_14 ( & V_56 -> V_50 ) ;
F_21 ( & V_48 . V_49 , V_41 ) ;
if ( V_56 -> V_47 != F_17 () ) {
F_18 () ;
F_19 ( V_56 -> V_47 ,
F_13 , V_56 , true ) ;
} else {
F_13 ( V_56 ) ;
F_18 () ;
}
V_64:
F_8 ( V_56 ) ;
}
static void F_29 ( struct V_26 * V_28 , const T_4 * V_69 )
{
T_3 V_70 ;
int V_16 ;
bool V_71 = false ;
struct V_26 * V_72 = V_28 -> V_42 ;
int V_73 ;
struct V_74 V_75 ;
struct V_74 * V_76 ;
for ( V_16 = V_77 ; V_16 < V_78 ; V_16 ++ ) {
if ( ! memcmp ( V_69 -> V_79 , V_80 [ V_16 ] . V_81 ,
sizeof( T_4 ) ) ) {
V_71 = true ;
break;
}
}
if ( ( V_82 == V_83 ) ||
( V_82 == V_84 ) || ( ! V_71 ) ) {
V_28 -> V_85 = 0 ;
V_28 -> V_47 = 0 ;
V_28 -> V_86 = V_37 . V_87 [ 0 ] ;
return;
}
if ( ! V_72 ) {
while ( true ) {
V_73 = V_88 ++ ;
if ( V_73 == V_89 )
V_73 = V_88 = 0 ;
if ( F_33 ( F_34 ( V_73 ) ) )
continue;
break;
}
V_28 -> V_85 = V_73 ;
V_72 = V_28 ;
}
V_76 = & V_37 . V_90 [ V_72 -> V_85 ] ;
if ( F_35 ( V_76 ) ==
F_35 ( F_34 ( V_72 -> V_85 ) ) ) {
F_36 ( V_76 ) ;
}
F_37 ( & V_75 , V_76 ,
F_34 ( V_72 -> V_85 ) ) ;
V_70 = - 1 ;
while ( true ) {
V_70 = F_38 ( V_70 , & V_75 ) ;
if ( V_70 >= V_91 ) {
V_70 = - 1 ;
F_39 ( & V_75 ,
F_34 ( V_72 -> V_85 ) ) ;
continue;
}
if ( ! F_40 ( V_70 ,
& V_72 -> V_52 ) ) {
F_41 ( V_70 ,
& V_72 -> V_52 ) ;
F_41 ( V_70 , V_76 ) ;
break;
}
}
V_28 -> V_47 = V_70 ;
V_28 -> V_86 = V_37 . V_87 [ V_70 ] ;
}
static void F_42 ( struct V_92 * V_93 )
{
F_43 ( & V_48 . V_94 ) ;
}
void F_44 ( void )
{
struct V_92 V_93 ;
if ( V_82 < V_95 )
return;
F_45 ( & V_48 . V_94 ) ;
memset ( & V_93 , 0 , sizeof( struct V_92 ) ) ;
V_93 . V_45 = V_96 ;
F_16 ( & V_93 , sizeof( struct V_92 ) ) ;
F_46 ( & V_48 . V_94 ) ;
}
static void F_47 ( struct V_92 * V_93 )
{
struct V_97 * V_59 ;
struct V_26 * V_56 ;
V_59 = (struct V_97 * ) V_93 ;
V_56 = F_2 () ;
if ( ! V_56 ) {
F_32 ( L_2 ) ;
return;
}
V_56 -> V_98 = true ;
V_56 -> V_99 = (struct V_100 * )
( F_48 ( ( unsigned long )
& V_56 -> V_101 ,
V_102 ) ) ;
V_56 -> V_99 -> V_103 . V_104 = 0 ;
V_56 -> V_99 -> V_103 . V_105 . V_30 = V_106 ;
V_56 -> V_99 -> V_107 = 0 ;
V_56 -> V_99 -> V_108 = 0 ;
if ( V_82 != V_83 ) {
V_56 -> V_109 =
( V_59 -> V_109 != 0 ) ;
V_56 -> V_99 -> V_103 . V_105 . V_30 =
V_59 -> V_110 ;
}
memcpy ( & V_56 -> V_58 , V_59 ,
sizeof( struct V_97 ) ) ;
V_56 -> V_111 = ( T_1 ) V_59 -> V_112 / 32 ;
V_56 -> V_113 = ( T_1 ) V_59 -> V_112 % 32 ;
F_26 ( V_56 ) ;
}
static void F_49 ( struct V_92 * V_93 )
{
struct V_114 * V_54 ;
struct V_26 * V_28 ;
unsigned long V_41 ;
struct V_115 * V_116 ;
V_54 = (struct V_114 * ) V_93 ;
V_28 = F_50 ( V_54 -> V_43 ) ;
if ( V_28 == NULL ) {
F_15 ( NULL , V_54 -> V_43 ) ;
return;
}
F_20 ( & V_28 -> V_32 , V_41 ) ;
V_28 -> V_54 = true ;
F_21 ( & V_28 -> V_32 , V_41 ) ;
if ( V_28 -> V_55 ) {
V_116 = F_51 ( & V_28 -> V_55 -> V_115 ) ;
if ( V_116 ) {
F_25 ( V_28 -> V_55 ) ;
F_52 ( V_116 ) ;
}
} else {
F_15 ( V_28 ,
V_28 -> V_58 . V_43 ) ;
}
}
static void F_53 (
struct V_92 * V_93 )
{
}
static void F_54 ( struct V_92 * V_93 )
{
struct V_117 * V_118 ;
struct V_119 * V_120 ;
struct V_92 * V_121 ;
struct V_122 * V_123 ;
unsigned long V_41 ;
V_118 = (struct V_117 * ) V_93 ;
F_20 ( & V_48 . V_124 , V_41 ) ;
F_27 (msginfo, &vmbus_connection.chn_msg_list,
msglistentry) {
V_121 =
(struct V_92 * ) V_120 -> V_40 ;
if ( V_121 -> V_45 == V_125 ) {
V_123 =
(struct V_122 * ) V_120 -> V_40 ;
if ( V_123 -> V_43 == V_118 -> V_43 &&
V_123 -> V_126 == V_118 -> V_126 ) {
memcpy ( & V_120 -> V_127 . V_128 ,
V_118 ,
sizeof(
struct V_117 ) ) ;
F_43 ( & V_120 -> V_129 ) ;
break;
}
}
}
F_21 ( & V_48 . V_124 , V_41 ) ;
}
static void F_55 ( struct V_92 * V_93 )
{
struct V_130 * V_131 ;
struct V_119 * V_120 ;
struct V_92 * V_121 ;
struct V_132 * V_133 ;
unsigned long V_41 ;
V_131 = (struct V_130 * ) V_93 ;
F_20 ( & V_48 . V_124 , V_41 ) ;
F_27 (msginfo, &vmbus_connection.chn_msg_list,
msglistentry) {
V_121 =
(struct V_92 * ) V_120 -> V_40 ;
if ( V_121 -> V_45 == V_134 ) {
V_133 =
(struct V_132 * ) V_121 ;
if ( ( V_131 -> V_43 ==
V_133 -> V_43 ) &&
( V_131 -> V_135 == V_133 -> V_135 ) ) {
memcpy ( & V_120 -> V_127 . V_136 ,
V_131 ,
sizeof(
struct V_130 ) ) ;
F_43 ( & V_120 -> V_129 ) ;
break;
}
}
}
F_21 ( & V_48 . V_124 , V_41 ) ;
}
static void F_56 (
struct V_92 * V_93 )
{
struct V_137 * V_138 ;
struct V_119 * V_120 ;
struct V_92 * V_121 ;
struct V_139 * V_140 ;
unsigned long V_41 ;
V_138 = (struct V_137 * ) V_93 ;
F_20 ( & V_48 . V_124 , V_41 ) ;
F_27 (msginfo, &vmbus_connection.chn_msg_list,
msglistentry) {
V_121 =
(struct V_92 * ) V_120 -> V_40 ;
if ( V_121 -> V_45 == V_141 ) {
V_140 =
(struct V_139 * ) V_121 ;
if ( V_138 -> V_135 == V_140 -> V_135 ) {
memcpy ( & V_120 -> V_127 . V_138 ,
V_138 ,
sizeof(
struct V_137 ) ) ;
F_43 ( & V_120 -> V_129 ) ;
break;
}
}
}
F_21 ( & V_48 . V_124 , V_41 ) ;
}
static void F_57 (
struct V_92 * V_93 )
{
struct V_119 * V_120 ;
struct V_92 * V_121 ;
struct V_142 * V_143 ;
unsigned long V_41 ;
V_143 = (struct V_142 * ) V_93 ;
F_20 ( & V_48 . V_124 , V_41 ) ;
F_27 (msginfo, &vmbus_connection.chn_msg_list,
msglistentry) {
V_121 =
(struct V_92 * ) V_120 -> V_40 ;
if ( V_121 -> V_45 ==
V_144 ) {
memcpy ( & V_120 -> V_127 . V_143 ,
V_143 ,
sizeof( struct V_142 ) ) ;
F_43 ( & V_120 -> V_129 ) ;
}
}
F_21 ( & V_48 . V_124 , V_41 ) ;
}
void F_58 ( void * V_145 )
{
struct V_146 * V_40 = V_145 ;
struct V_92 * V_93 ;
int V_147 ;
V_93 = (struct V_92 * ) V_40 -> V_105 . V_148 ;
V_147 = V_40 -> V_44 . V_149 ;
if ( V_93 -> V_45 >= V_150 ) {
F_32 ( L_3 ,
V_93 -> V_45 , V_147 ) ;
F_59 ( L_4 , V_151 ,
( unsigned char * ) V_40 -> V_105 . V_148 , V_147 ) ;
return;
}
if ( V_152 [ V_93 -> V_45 ] . V_153 )
V_152 [ V_93 -> V_45 ] . V_153 ( V_93 ) ;
else
F_32 ( L_5 , V_93 -> V_45 ) ;
}
int F_60 ( void )
{
struct V_92 * V_40 ;
struct V_119 * V_120 ;
int V_154 ;
V_120 = F_61 ( sizeof( * V_120 ) +
sizeof( struct V_92 ) ,
V_155 ) ;
if ( ! V_120 )
return - V_156 ;
V_40 = (struct V_92 * ) V_120 -> V_40 ;
V_40 -> V_45 = V_157 ;
V_154 = F_16 ( V_40 ,
sizeof( struct V_92 ) ) ;
if ( V_154 != 0 ) {
F_32 ( L_6 , V_154 ) ;
goto V_158;
}
V_158:
F_9 ( V_120 ) ;
return V_154 ;
}
struct V_26 * F_62 ( struct V_26 * V_72 )
{
struct V_159 * V_160 , * V_53 ;
int V_70 ;
struct V_26 * V_161 ;
struct V_26 * V_162 = V_72 ;
int V_163 ;
int V_16 = 1 ;
if ( F_63 ( & V_72 -> V_33 ) )
return V_162 ;
V_163 = V_72 -> V_164 ++ ;
if ( V_163 > ( V_72 -> V_51 ) ) {
V_72 -> V_164 = 0 ;
return V_162 ;
}
V_70 = V_37 . V_87 [ F_17 () ] ;
F_18 () ;
F_64 (cur, tmp, &primary->sc_list) {
V_161 = F_65 ( V_160 , struct V_26 , V_33 ) ;
if ( V_161 -> V_65 != V_165 )
continue;
if ( V_161 -> V_86 == V_70 )
return V_161 ;
if ( V_16 == V_163 )
return V_161 ;
V_16 ++ ;
}
return V_162 ;
}
static void F_66 ( struct V_26 * V_42 )
{
struct V_159 * V_160 , * V_53 ;
struct V_26 * V_161 ;
if ( V_42 -> V_67 == NULL )
return;
F_64 (cur, tmp, &primary_channel->sc_list) {
V_161 = F_65 ( V_160 , struct V_26 , V_33 ) ;
V_42 -> V_67 ( V_161 ) ;
}
}
void F_67 ( struct V_26 * V_42 ,
void (* F_68)( struct V_26 * V_166 ) )
{
V_42 -> V_67 = F_68 ;
}
bool F_69 ( struct V_26 * V_72 )
{
bool V_154 ;
V_154 = ! F_63 ( & V_72 -> V_33 ) ;
if ( V_154 ) {
F_66 ( V_72 ) ;
}
return V_154 ;
}
