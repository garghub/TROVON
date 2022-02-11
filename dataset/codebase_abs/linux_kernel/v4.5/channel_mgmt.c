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
static void F_15 ( T_3 V_38 )
{
struct V_39 V_40 ;
memset ( & V_40 , 0 , sizeof( struct V_39 ) ) ;
V_40 . V_41 = V_38 ;
V_40 . V_42 . V_43 = V_44 ;
F_16 ( & V_40 , sizeof( struct V_39 ) ) ;
}
void F_17 ( struct V_26 * V_28 , T_3 V_38 )
{
unsigned long V_45 ;
struct V_26 * V_46 ;
F_15 ( V_38 ) ;
F_18 ( ! V_28 -> V_47 ) ;
if ( V_28 -> V_48 != F_19 () ) {
F_20 () ;
F_21 ( V_28 -> V_48 ,
F_13 , V_28 , true ) ;
} else {
F_13 ( V_28 ) ;
F_20 () ;
}
if ( V_28 -> V_46 == NULL ) {
F_22 ( & V_49 . V_50 ) ;
F_14 ( & V_28 -> V_51 ) ;
F_23 ( & V_49 . V_50 ) ;
V_46 = V_28 ;
} else {
V_46 = V_28 -> V_46 ;
F_24 ( & V_46 -> V_32 , V_45 ) ;
F_14 ( & V_28 -> V_33 ) ;
V_46 -> V_52 -- ;
F_25 ( & V_46 -> V_32 , V_45 ) ;
}
F_26 ( V_28 -> V_48 ,
& V_46 -> V_53 ) ;
F_8 ( V_28 ) ;
}
void F_27 ( void )
{
struct V_26 * V_28 , * V_54 ;
F_28 (channel, tmp, &vmbus_connection.chn_list,
listentry) {
V_28 -> V_47 = true ;
F_29 ( V_28 -> V_55 ) ;
}
}
static void F_30 ( struct V_26 * V_56 )
{
struct V_26 * V_28 ;
bool V_57 = true ;
unsigned long V_45 ;
F_22 ( & V_49 . V_50 ) ;
F_31 (channel, &vmbus_connection.chn_list, listentry) {
if ( ! F_32 ( V_28 -> V_58 . V_59 . V_60 ,
V_56 -> V_58 . V_59 . V_60 ) &&
! F_32 ( V_28 -> V_58 . V_59 . V_61 ,
V_56 -> V_58 . V_59 . V_61 ) ) {
V_57 = false ;
break;
}
}
if ( V_57 )
F_12 ( & V_56 -> V_51 ,
& V_49 . V_62 ) ;
F_23 ( & V_49 . V_50 ) ;
if ( ! V_57 ) {
if ( V_56 -> V_58 . V_59 . V_63 != 0 ) {
V_56 -> V_46 = V_28 ;
F_24 ( & V_28 -> V_32 , V_45 ) ;
F_12 ( & V_56 -> V_33 , & V_28 -> V_33 ) ;
V_28 -> V_52 ++ ;
F_25 ( & V_28 -> V_32 , V_45 ) ;
} else
goto V_64;
}
F_33 ( V_56 , & V_56 -> V_58 . V_59 . V_60 ) ;
if ( V_56 -> V_48 != F_19 () ) {
F_20 () ;
F_21 ( V_56 -> V_48 ,
F_10 ,
V_56 , true ) ;
} else {
F_10 ( V_56 ) ;
F_20 () ;
}
V_56 -> V_65 = V_66 ;
if ( ! V_57 ) {
if ( V_28 -> V_67 != NULL )
V_28 -> V_67 ( V_56 ) ;
return;
}
V_56 -> V_55 = F_34 (
& V_56 -> V_58 . V_59 . V_60 ,
& V_56 -> V_58 . V_59 . V_61 ,
V_56 ) ;
if ( ! V_56 -> V_55 )
goto V_68;
if ( F_35 ( V_56 -> V_55 ) != 0 ) {
F_36 ( L_1 ,
V_56 -> V_58 . V_41 ) ;
F_9 ( V_56 -> V_55 ) ;
goto V_68;
}
return;
V_68:
F_15 ( V_56 -> V_58 . V_41 ) ;
F_22 ( & V_49 . V_50 ) ;
F_14 ( & V_56 -> V_51 ) ;
F_23 ( & V_49 . V_50 ) ;
if ( V_56 -> V_48 != F_19 () ) {
F_20 () ;
F_21 ( V_56 -> V_48 ,
F_13 , V_56 , true ) ;
} else {
F_13 ( V_56 ) ;
F_20 () ;
}
V_64:
F_8 ( V_56 ) ;
}
static void F_33 ( struct V_26 * V_28 , const T_4 * V_69 )
{
T_3 V_70 ;
int V_16 ;
bool V_71 = false ;
struct V_26 * V_72 = V_28 -> V_46 ;
int V_73 ;
struct V_74 V_75 ;
struct V_74 * V_76 ;
for ( V_16 = V_77 ; V_16 < V_78 ; V_16 ++ ) {
if ( ! F_32 ( * V_69 , V_79 [ V_16 ] . V_80 ) ) {
V_71 = true ;
break;
}
}
if ( ( V_81 == V_82 ) ||
( V_81 == V_83 ) || ( ! V_71 ) ) {
V_28 -> V_84 = 0 ;
V_28 -> V_48 = 0 ;
V_28 -> V_85 = V_37 . V_86 [ 0 ] ;
return;
}
if ( ! V_72 ) {
while ( true ) {
V_73 = V_87 ++ ;
if ( V_73 == V_88 )
V_73 = V_87 = 0 ;
if ( F_37 ( F_38 ( V_73 ) ) )
continue;
break;
}
V_28 -> V_84 = V_73 ;
V_72 = V_28 ;
}
V_76 = & V_37 . V_89 [ V_72 -> V_84 ] ;
if ( F_39 ( V_76 ) ==
F_39 ( F_38 ( V_72 -> V_84 ) ) ) {
F_40 ( V_76 ) ;
}
F_41 ( & V_75 , V_76 ,
F_38 ( V_72 -> V_84 ) ) ;
V_70 = - 1 ;
while ( true ) {
V_70 = F_42 ( V_70 , & V_75 ) ;
if ( V_70 >= V_90 ) {
V_70 = - 1 ;
F_43 ( & V_75 ,
F_38 ( V_72 -> V_84 ) ) ;
continue;
}
if ( ! F_44 ( V_70 ,
& V_72 -> V_53 ) ) {
F_45 ( V_70 ,
& V_72 -> V_53 ) ;
F_45 ( V_70 , V_76 ) ;
break;
}
}
V_28 -> V_48 = V_70 ;
V_28 -> V_85 = V_37 . V_86 [ V_70 ] ;
}
static void F_46 ( struct V_91 * V_92 )
{
F_47 ( & V_49 . V_93 ) ;
}
void F_48 ( void )
{
struct V_91 V_92 ;
if ( V_81 < V_94 )
return;
F_49 ( & V_49 . V_93 ) ;
memset ( & V_92 , 0 , sizeof( struct V_91 ) ) ;
V_92 . V_43 = V_95 ;
F_16 ( & V_92 , sizeof( struct V_91 ) ) ;
F_50 ( & V_49 . V_93 ) ;
}
static void F_51 ( struct V_91 * V_92 )
{
struct V_96 * V_59 ;
struct V_26 * V_56 ;
V_59 = (struct V_96 * ) V_92 ;
V_56 = F_2 () ;
if ( ! V_56 ) {
F_36 ( L_2 ) ;
return;
}
V_56 -> V_97 = true ;
V_56 -> V_98 = (struct V_99 * )
( F_52 ( ( unsigned long )
& V_56 -> V_100 ,
V_101 ) ) ;
V_56 -> V_98 -> V_102 . V_103 = 0 ;
V_56 -> V_98 -> V_102 . V_104 . V_30 = V_105 ;
V_56 -> V_98 -> V_106 = 0 ;
V_56 -> V_98 -> V_107 = 0 ;
if ( V_81 != V_82 ) {
V_56 -> V_108 =
( V_59 -> V_108 != 0 ) ;
V_56 -> V_98 -> V_102 . V_104 . V_30 =
V_59 -> V_109 ;
}
memcpy ( & V_56 -> V_58 , V_59 ,
sizeof( struct V_96 ) ) ;
V_56 -> V_110 = ( T_1 ) V_59 -> V_111 / 32 ;
V_56 -> V_112 = ( T_1 ) V_59 -> V_111 % 32 ;
F_30 ( V_56 ) ;
}
static void F_53 ( struct V_91 * V_92 )
{
struct V_113 * V_47 ;
struct V_26 * V_28 ;
unsigned long V_45 ;
struct V_114 * V_115 ;
V_47 = (struct V_113 * ) V_92 ;
V_28 = F_54 ( V_47 -> V_41 ) ;
if ( V_28 == NULL ) {
return;
}
F_24 ( & V_28 -> V_32 , V_45 ) ;
V_28 -> V_47 = true ;
F_25 ( & V_28 -> V_32 , V_45 ) ;
if ( V_28 -> V_55 ) {
V_115 = F_55 ( & V_28 -> V_55 -> V_114 ) ;
if ( V_115 ) {
F_29 ( V_28 -> V_55 ) ;
F_56 ( V_115 ) ;
}
} else {
F_17 ( V_28 ,
V_28 -> V_58 . V_41 ) ;
}
}
static void F_57 (
struct V_91 * V_92 )
{
}
static void F_58 ( struct V_91 * V_92 )
{
struct V_116 * V_117 ;
struct V_118 * V_119 ;
struct V_91 * V_120 ;
struct V_121 * V_122 ;
unsigned long V_45 ;
V_117 = (struct V_116 * ) V_92 ;
F_24 ( & V_49 . V_123 , V_45 ) ;
F_31 (msginfo, &vmbus_connection.chn_msg_list,
msglistentry) {
V_120 =
(struct V_91 * ) V_119 -> V_40 ;
if ( V_120 -> V_43 == V_124 ) {
V_122 =
(struct V_121 * ) V_119 -> V_40 ;
if ( V_122 -> V_41 == V_117 -> V_41 &&
V_122 -> V_125 == V_117 -> V_125 ) {
memcpy ( & V_119 -> V_126 . V_127 ,
V_117 ,
sizeof(
struct V_116 ) ) ;
F_47 ( & V_119 -> V_128 ) ;
break;
}
}
}
F_25 ( & V_49 . V_123 , V_45 ) ;
}
static void F_59 ( struct V_91 * V_92 )
{
struct V_129 * V_130 ;
struct V_118 * V_119 ;
struct V_91 * V_120 ;
struct V_131 * V_132 ;
unsigned long V_45 ;
V_130 = (struct V_129 * ) V_92 ;
F_24 ( & V_49 . V_123 , V_45 ) ;
F_31 (msginfo, &vmbus_connection.chn_msg_list,
msglistentry) {
V_120 =
(struct V_91 * ) V_119 -> V_40 ;
if ( V_120 -> V_43 == V_133 ) {
V_132 =
(struct V_131 * ) V_120 ;
if ( ( V_130 -> V_41 ==
V_132 -> V_41 ) &&
( V_130 -> V_134 == V_132 -> V_134 ) ) {
memcpy ( & V_119 -> V_126 . V_135 ,
V_130 ,
sizeof(
struct V_129 ) ) ;
F_47 ( & V_119 -> V_128 ) ;
break;
}
}
}
F_25 ( & V_49 . V_123 , V_45 ) ;
}
static void F_60 (
struct V_91 * V_92 )
{
struct V_136 * V_137 ;
struct V_118 * V_119 ;
struct V_91 * V_120 ;
struct V_138 * V_139 ;
unsigned long V_45 ;
V_137 = (struct V_136 * ) V_92 ;
F_24 ( & V_49 . V_123 , V_45 ) ;
F_31 (msginfo, &vmbus_connection.chn_msg_list,
msglistentry) {
V_120 =
(struct V_91 * ) V_119 -> V_40 ;
if ( V_120 -> V_43 == V_140 ) {
V_139 =
(struct V_138 * ) V_120 ;
if ( V_137 -> V_134 == V_139 -> V_134 ) {
memcpy ( & V_119 -> V_126 . V_137 ,
V_137 ,
sizeof(
struct V_136 ) ) ;
F_47 ( & V_119 -> V_128 ) ;
break;
}
}
}
F_25 ( & V_49 . V_123 , V_45 ) ;
}
static void F_61 (
struct V_91 * V_92 )
{
struct V_118 * V_119 ;
struct V_91 * V_120 ;
struct V_141 * V_142 ;
unsigned long V_45 ;
V_142 = (struct V_141 * ) V_92 ;
F_24 ( & V_49 . V_123 , V_45 ) ;
F_31 (msginfo, &vmbus_connection.chn_msg_list,
msglistentry) {
V_120 =
(struct V_91 * ) V_119 -> V_40 ;
if ( V_120 -> V_43 ==
V_143 ) {
memcpy ( & V_119 -> V_126 . V_142 ,
V_142 ,
sizeof( struct V_141 ) ) ;
F_47 ( & V_119 -> V_128 ) ;
}
}
F_25 ( & V_49 . V_123 , V_45 ) ;
}
void F_62 ( void * V_144 )
{
struct V_145 * V_40 = V_144 ;
struct V_91 * V_92 ;
int V_146 ;
V_92 = (struct V_91 * ) V_40 -> V_104 . V_147 ;
V_146 = V_40 -> V_42 . V_148 ;
if ( V_92 -> V_43 >= V_149 ) {
F_36 ( L_3 ,
V_92 -> V_43 , V_146 ) ;
F_63 ( L_4 , V_150 ,
( unsigned char * ) V_40 -> V_104 . V_147 , V_146 ) ;
return;
}
if ( V_151 [ V_92 -> V_43 ] . V_152 )
V_151 [ V_92 -> V_43 ] . V_152 ( V_92 ) ;
else
F_36 ( L_5 , V_92 -> V_43 ) ;
}
int F_64 ( void )
{
struct V_91 * V_40 ;
struct V_118 * V_119 ;
int V_153 ;
V_119 = F_65 ( sizeof( * V_119 ) +
sizeof( struct V_91 ) ,
V_154 ) ;
if ( ! V_119 )
return - V_155 ;
V_40 = (struct V_91 * ) V_119 -> V_40 ;
V_40 -> V_43 = V_156 ;
V_153 = F_16 ( V_40 ,
sizeof( struct V_91 ) ) ;
if ( V_153 != 0 ) {
F_36 ( L_6 , V_153 ) ;
goto V_157;
}
V_157:
F_9 ( V_119 ) ;
return V_153 ;
}
struct V_26 * F_66 ( struct V_26 * V_72 )
{
struct V_158 * V_159 , * V_54 ;
int V_70 ;
struct V_26 * V_160 ;
struct V_26 * V_161 = V_72 ;
int V_162 ;
int V_16 = 1 ;
if ( F_67 ( & V_72 -> V_33 ) )
return V_161 ;
V_162 = V_72 -> V_163 ++ ;
if ( V_162 > ( V_72 -> V_52 ) ) {
V_72 -> V_163 = 0 ;
return V_161 ;
}
V_70 = V_37 . V_86 [ F_19 () ] ;
F_20 () ;
F_68 (cur, tmp, &primary->sc_list) {
V_160 = F_69 ( V_159 , struct V_26 , V_33 ) ;
if ( V_160 -> V_65 != V_164 )
continue;
if ( V_160 -> V_85 == V_70 )
return V_160 ;
if ( V_16 == V_162 )
return V_160 ;
V_16 ++ ;
}
return V_161 ;
}
static void F_70 ( struct V_26 * V_46 )
{
struct V_158 * V_159 , * V_54 ;
struct V_26 * V_160 ;
if ( V_46 -> V_67 == NULL )
return;
F_68 (cur, tmp, &primary_channel->sc_list) {
V_160 = F_69 ( V_159 , struct V_26 , V_33 ) ;
V_46 -> V_67 ( V_160 ) ;
}
}
void F_71 ( struct V_26 * V_46 ,
void (* F_72)( struct V_26 * V_165 ) )
{
V_46 -> V_67 = F_72 ;
}
bool F_73 ( struct V_26 * V_72 )
{
bool V_153 ;
V_153 = ! F_67 ( & V_72 -> V_33 ) ;
if ( V_153 ) {
F_70 ( V_72 ) ;
}
return V_153 ;
}
