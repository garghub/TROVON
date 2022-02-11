static T_1 F_1 ( const T_2 * V_1 )
{
T_1 V_2 ;
for ( V_2 = V_3 ; V_2 < V_4 ; V_2 ++ ) {
if ( ! F_2 ( * V_1 , V_5 [ V_2 ] . V_1 ) )
return V_2 ;
}
F_3 ( L_1 , V_1 ) ;
return V_2 ;
}
bool F_4 ( struct V_6 * V_7 ,
struct V_8 * V_9 , T_3 * V_10 ,
int V_11 , int V_12 )
{
int V_13 , V_14 ;
int V_15 , V_16 ;
int V_17 , V_18 ;
int V_19 , V_20 ;
int V_2 ;
bool V_21 = false ;
V_7 -> V_22 = 0x10 ;
V_17 = ( V_11 >> 16 ) ;
V_18 = ( V_11 & 0xFFFF ) ;
V_19 = ( V_12 >> 16 ) ;
V_20 = ( V_12 & 0xFFFF ) ;
V_9 = (struct V_8 * ) & V_10 [
sizeof( struct V_23 ) +
sizeof( struct V_6 ) ] ;
V_13 = V_9 -> V_24 ;
V_14 = 0 ;
V_15 = V_9 -> V_25 ;
V_16 = 0 ;
for ( V_2 = 0 ; V_2 < V_9 -> V_24 ; V_2 ++ ) {
if ( ( V_9 -> V_26 [ V_2 ] . V_27 == V_17 ) &&
( V_9 -> V_26 [ V_2 ] . V_28 == V_18 ) ) {
V_13 = V_9 -> V_26 [ V_2 ] . V_27 ;
V_14 = V_9 -> V_26 [ V_2 ] . V_28 ;
V_21 = true ;
}
}
if ( ! V_21 )
goto V_29;
V_21 = false ;
for ( V_2 = V_9 -> V_24 ;
( V_2 < V_9 -> V_24 + V_9 -> V_25 ) ; V_2 ++ ) {
if ( ( V_9 -> V_26 [ V_2 ] . V_27 == V_19 ) &&
( V_9 -> V_26 [ V_2 ] . V_28 == V_20 ) ) {
V_15 = V_9 -> V_26 [ V_2 ] . V_27 ;
V_16 = V_9 -> V_26 [ V_2 ] . V_28 ;
V_21 = true ;
}
}
V_29:
if ( ! V_21 ) {
V_9 -> V_24 = 0 ;
V_9 -> V_25 = 0 ;
} else {
V_9 -> V_24 = 1 ;
V_9 -> V_25 = 1 ;
}
V_9 -> V_26 [ 0 ] . V_27 = V_13 ;
V_9 -> V_26 [ 0 ] . V_28 = V_14 ;
V_9 -> V_26 [ 1 ] . V_27 = V_15 ;
V_9 -> V_26 [ 1 ] . V_28 = V_16 ;
return V_21 ;
}
static struct V_30 * F_5 ( void )
{
static T_4 V_31 = F_6 ( 0 ) ;
struct V_30 * V_32 ;
V_32 = F_7 ( sizeof( * V_32 ) , V_33 ) ;
if ( ! V_32 )
return NULL ;
V_32 -> V_34 = F_8 ( & V_31 ) ;
V_32 -> V_35 = true ;
F_9 ( & V_32 -> V_36 ) ;
F_9 ( & V_32 -> V_37 ) ;
F_10 ( & V_32 -> V_38 ) ;
F_10 ( & V_32 -> V_39 ) ;
return V_32 ;
}
static void F_11 ( struct V_30 * V_32 )
{
F_12 ( V_32 ) ;
}
static void F_13 ( void * V_40 )
{
struct V_30 * V_32 = V_40 ;
int V_41 = F_14 () ;
F_15 ( & V_32 -> V_39 , & V_42 . V_39 [ V_41 ] ) ;
}
static void F_16 ( void * V_40 )
{
struct V_30 * V_32 = V_40 ;
F_17 ( & V_32 -> V_39 ) ;
}
static void F_18 ( T_5 V_43 )
{
struct V_44 V_45 ;
memset ( & V_45 , 0 , sizeof( struct V_44 ) ) ;
V_45 . V_46 = V_43 ;
V_45 . V_47 . V_48 = V_49 ;
F_19 ( & V_45 , sizeof( struct V_44 ) ) ;
}
void F_20 ( struct V_30 * V_32 , T_5 V_43 )
{
unsigned long V_50 ;
struct V_30 * V_51 ;
F_18 ( V_43 ) ;
F_21 ( ! V_32 -> V_52 ) ;
F_21 ( ! F_22 ( & V_53 . V_54 ) ) ;
if ( V_32 -> V_55 != F_23 () ) {
F_24 () ;
F_25 ( V_32 -> V_55 ,
F_16 , V_32 , true ) ;
} else {
F_16 ( V_32 ) ;
F_24 () ;
}
if ( V_32 -> V_51 == NULL ) {
F_17 ( & V_32 -> V_56 ) ;
V_51 = V_32 ;
} else {
V_51 = V_32 -> V_51 ;
F_26 ( & V_51 -> V_37 , V_50 ) ;
F_17 ( & V_32 -> V_38 ) ;
V_51 -> V_57 -- ;
F_27 ( & V_51 -> V_37 , V_50 ) ;
}
F_28 ( V_32 -> V_55 ,
& V_51 -> V_58 ) ;
F_11 ( V_32 ) ;
}
void F_29 ( void )
{
struct V_30 * V_32 , * V_59 ;
F_30 (channel, tmp, &vmbus_connection.chn_list,
listentry) {
V_32 -> V_52 = true ;
F_31 ( V_32 -> V_60 ) ;
}
}
static void F_32 ( struct V_30 * V_61 )
{
struct V_30 * V_32 ;
bool V_62 = true ;
unsigned long V_50 ;
T_1 V_63 ;
int V_64 ;
F_33 ( & V_53 . V_54 ) ;
F_34 (channel, &vmbus_connection.chn_list, listentry) {
if ( ! F_2 ( V_32 -> V_65 . V_66 . V_67 ,
V_61 -> V_65 . V_66 . V_67 ) &&
! F_2 ( V_32 -> V_65 . V_66 . V_68 ,
V_61 -> V_65 . V_66 . V_68 ) ) {
V_62 = false ;
break;
}
}
if ( V_62 )
F_15 ( & V_61 -> V_56 ,
& V_53 . V_69 ) ;
F_35 ( & V_53 . V_54 ) ;
if ( ! V_62 ) {
if ( V_61 -> V_65 . V_66 . V_70 != 0 ) {
V_61 -> V_51 = V_32 ;
F_26 ( & V_32 -> V_37 , V_50 ) ;
F_15 ( & V_61 -> V_38 , & V_32 -> V_38 ) ;
V_32 -> V_57 ++ ;
F_27 ( & V_32 -> V_37 , V_50 ) ;
} else
goto V_71;
}
V_63 = F_1 ( & V_61 -> V_65 . V_66 . V_67 ) ;
F_36 ( V_61 , V_63 ) ;
if ( V_61 -> V_55 != F_23 () ) {
F_24 () ;
F_25 ( V_61 -> V_55 ,
F_13 ,
V_61 , true ) ;
} else {
F_13 ( V_61 ) ;
F_24 () ;
}
V_61 -> V_72 = V_73 ;
if ( ! V_62 ) {
if ( V_32 -> V_74 != NULL )
V_32 -> V_74 ( V_61 ) ;
return;
}
V_61 -> V_60 = F_37 (
& V_61 -> V_65 . V_66 . V_67 ,
& V_61 -> V_65 . V_66 . V_68 ,
V_61 ) ;
if ( ! V_61 -> V_60 )
goto V_75;
V_61 -> V_60 -> V_76 = V_63 ;
F_33 ( & V_53 . V_54 ) ;
V_64 = F_38 ( V_61 -> V_60 ) ;
F_35 ( & V_53 . V_54 ) ;
if ( V_64 != 0 ) {
F_39 ( L_2 ,
V_61 -> V_65 . V_46 ) ;
F_12 ( V_61 -> V_60 ) ;
goto V_75;
}
return;
V_75:
F_18 ( V_61 -> V_65 . V_46 ) ;
F_33 ( & V_53 . V_54 ) ;
F_17 ( & V_61 -> V_56 ) ;
F_35 ( & V_53 . V_54 ) ;
if ( V_61 -> V_55 != F_23 () ) {
F_24 () ;
F_25 ( V_61 -> V_55 ,
F_16 , V_61 , true ) ;
} else {
F_16 ( V_61 ) ;
F_24 () ;
}
V_71:
F_11 ( V_61 ) ;
}
static void F_36 ( struct V_30 * V_32 , T_1 V_63 )
{
T_5 V_77 ;
bool V_78 = V_5 [ V_63 ] . V_79 ;
struct V_30 * V_80 = V_32 -> V_51 ;
int V_81 ;
struct V_82 V_83 ;
struct V_82 * V_84 ;
if ( ( V_85 == V_86 ) ||
( V_85 == V_87 ) || ( ! V_78 ) ) {
V_32 -> V_88 = 0 ;
V_32 -> V_55 = 0 ;
V_32 -> V_89 = V_42 . V_90 [ 0 ] ;
return;
}
if ( ! V_80 ) {
while ( true ) {
V_81 = V_91 ++ ;
if ( V_81 == V_92 )
V_81 = V_91 = 0 ;
if ( F_40 ( F_41 ( V_81 ) ) )
continue;
break;
}
V_32 -> V_88 = V_81 ;
V_80 = V_32 ;
}
V_84 = & V_42 . V_93 [ V_80 -> V_88 ] ;
if ( F_42 ( V_84 ) ==
F_42 ( F_41 ( V_80 -> V_88 ) ) ) {
F_43 ( V_84 ) ;
}
F_44 ( & V_83 , V_84 ,
F_41 ( V_80 -> V_88 ) ) ;
V_77 = - 1 ;
if ( F_45 ( & V_80 -> V_58 ,
F_41 ( V_80 -> V_88 ) ) )
F_43 ( & V_80 -> V_58 ) ;
while ( true ) {
V_77 = F_46 ( V_77 , & V_83 ) ;
if ( V_77 >= V_94 ) {
V_77 = - 1 ;
F_47 ( & V_83 ,
F_41 ( V_80 -> V_88 ) ) ;
continue;
}
if ( ! F_48 ( V_77 ,
& V_80 -> V_58 ) ) {
F_49 ( V_77 ,
& V_80 -> V_58 ) ;
F_49 ( V_77 , V_84 ) ;
break;
}
}
V_32 -> V_55 = V_77 ;
V_32 -> V_89 = V_42 . V_90 [ V_77 ] ;
}
static void F_50 ( void )
{
int V_41 = F_14 () ;
void * V_95 = V_42 . V_96 [ V_41 ] ;
struct V_97 * V_45 = (struct V_97 * ) V_95 +
V_98 ;
struct V_99 * V_100 ;
bool V_101 = false ;
while ( 1 ) {
if ( F_51 ( V_45 -> V_47 . V_102 ) == V_103 ) {
F_52 ( 10 ) ;
continue;
}
V_100 = (struct V_99 * ) V_45 -> V_104 . V_105 ;
if ( V_100 -> V_48 == V_106 )
V_101 = true ;
F_53 ( V_45 ) ;
if ( V_101 )
break;
}
}
static void F_54 ( struct V_99 * V_100 )
{
F_55 ( & V_53 . V_107 ) ;
}
void F_56 ( bool V_108 )
{
struct V_99 V_100 ;
if ( V_85 < V_109 )
return;
F_57 ( & V_53 . V_107 ) ;
memset ( & V_100 , 0 , sizeof( struct V_99 ) ) ;
V_100 . V_48 = V_110 ;
F_19 ( & V_100 , sizeof( struct V_99 ) ) ;
if ( ! V_108 )
F_58 ( & V_53 . V_107 ) ;
else
F_50 () ;
}
static void F_59 ( struct V_99 * V_100 )
{
struct V_111 * V_66 ;
struct V_30 * V_61 ;
V_66 = (struct V_111 * ) V_100 ;
V_61 = F_5 () ;
if ( ! V_61 ) {
F_39 ( L_3 ) ;
return;
}
V_61 -> V_112 = true ;
V_61 -> V_113 = (struct V_114 * )
( F_60 ( ( unsigned long )
& V_61 -> V_115 ,
V_116 ) ) ;
V_61 -> V_113 -> V_117 . V_118 = 0 ;
V_61 -> V_113 -> V_117 . V_104 . V_34 = V_119 ;
V_61 -> V_113 -> V_120 = 0 ;
V_61 -> V_113 -> V_121 = 0 ;
if ( V_85 != V_86 ) {
V_61 -> V_122 =
( V_66 -> V_122 != 0 ) ;
V_61 -> V_113 -> V_117 . V_104 . V_34 =
V_66 -> V_123 ;
}
memcpy ( & V_61 -> V_65 , V_66 ,
sizeof( struct V_111 ) ) ;
V_61 -> V_124 = ( T_3 ) V_66 -> V_125 / 32 ;
V_61 -> V_126 = ( T_3 ) V_66 -> V_125 % 32 ;
F_32 ( V_61 ) ;
}
static void F_61 ( struct V_99 * V_100 )
{
struct V_127 * V_52 ;
struct V_30 * V_32 ;
unsigned long V_50 ;
struct V_128 * V_129 ;
V_52 = (struct V_127 * ) V_100 ;
F_33 ( & V_53 . V_54 ) ;
V_32 = F_62 ( V_52 -> V_46 ) ;
if ( V_32 == NULL ) {
goto V_130;
}
F_26 ( & V_32 -> V_37 , V_50 ) ;
V_32 -> V_52 = true ;
F_27 ( & V_32 -> V_37 , V_50 ) ;
if ( V_32 -> V_60 ) {
if ( V_32 -> V_131 ) {
V_32 -> V_131 ( V_32 ) ;
goto V_130;
}
V_129 = F_63 ( & V_32 -> V_60 -> V_128 ) ;
if ( V_129 ) {
F_31 ( V_32 -> V_60 ) ;
F_64 ( V_129 ) ;
}
} else {
F_20 ( V_32 ,
V_32 -> V_65 . V_46 ) ;
}
V_130:
F_35 ( & V_53 . V_54 ) ;
}
void F_65 ( struct V_30 * V_32 )
{
F_33 ( & V_53 . V_54 ) ;
F_21 ( ! F_66 ( V_32 ) ) ;
V_32 -> V_52 = true ;
F_31 ( V_32 -> V_60 ) ;
F_35 ( & V_53 . V_54 ) ;
}
static void F_67 (
struct V_99 * V_100 )
{
}
static void F_68 ( struct V_99 * V_100 )
{
struct V_132 * V_133 ;
struct V_134 * V_135 ;
struct V_99 * V_136 ;
struct V_137 * V_138 ;
unsigned long V_50 ;
V_133 = (struct V_132 * ) V_100 ;
F_26 ( & V_53 . V_139 , V_50 ) ;
F_34 (msginfo, &vmbus_connection.chn_msg_list,
msglistentry) {
V_136 =
(struct V_99 * ) V_135 -> V_45 ;
if ( V_136 -> V_48 == V_140 ) {
V_138 =
(struct V_137 * ) V_135 -> V_45 ;
if ( V_138 -> V_46 == V_133 -> V_46 &&
V_138 -> V_141 == V_133 -> V_141 ) {
memcpy ( & V_135 -> V_142 . V_143 ,
V_133 ,
sizeof(
struct V_132 ) ) ;
F_55 ( & V_135 -> V_144 ) ;
break;
}
}
}
F_27 ( & V_53 . V_139 , V_50 ) ;
}
static void F_69 ( struct V_99 * V_100 )
{
struct V_145 * V_146 ;
struct V_134 * V_135 ;
struct V_99 * V_136 ;
struct V_147 * V_148 ;
unsigned long V_50 ;
V_146 = (struct V_145 * ) V_100 ;
F_26 ( & V_53 . V_139 , V_50 ) ;
F_34 (msginfo, &vmbus_connection.chn_msg_list,
msglistentry) {
V_136 =
(struct V_99 * ) V_135 -> V_45 ;
if ( V_136 -> V_48 == V_149 ) {
V_148 =
(struct V_147 * ) V_136 ;
if ( ( V_146 -> V_46 ==
V_148 -> V_46 ) &&
( V_146 -> V_150 == V_148 -> V_150 ) ) {
memcpy ( & V_135 -> V_142 . V_151 ,
V_146 ,
sizeof(
struct V_145 ) ) ;
F_55 ( & V_135 -> V_144 ) ;
break;
}
}
}
F_27 ( & V_53 . V_139 , V_50 ) ;
}
static void F_70 (
struct V_99 * V_100 )
{
struct V_152 * V_153 ;
struct V_134 * V_135 ;
struct V_99 * V_136 ;
struct V_154 * V_155 ;
unsigned long V_50 ;
V_153 = (struct V_152 * ) V_100 ;
F_26 ( & V_53 . V_139 , V_50 ) ;
F_34 (msginfo, &vmbus_connection.chn_msg_list,
msglistentry) {
V_136 =
(struct V_99 * ) V_135 -> V_45 ;
if ( V_136 -> V_48 == V_156 ) {
V_155 =
(struct V_154 * ) V_136 ;
if ( V_153 -> V_150 == V_155 -> V_150 ) {
memcpy ( & V_135 -> V_142 . V_153 ,
V_153 ,
sizeof(
struct V_152 ) ) ;
F_55 ( & V_135 -> V_144 ) ;
break;
}
}
}
F_27 ( & V_53 . V_139 , V_50 ) ;
}
static void F_71 (
struct V_99 * V_100 )
{
struct V_134 * V_135 ;
struct V_99 * V_136 ;
struct V_157 * V_158 ;
unsigned long V_50 ;
V_158 = (struct V_157 * ) V_100 ;
F_26 ( & V_53 . V_139 , V_50 ) ;
F_34 (msginfo, &vmbus_connection.chn_msg_list,
msglistentry) {
V_136 =
(struct V_99 * ) V_135 -> V_45 ;
if ( V_136 -> V_48 ==
V_159 ) {
memcpy ( & V_135 -> V_142 . V_158 ,
V_158 ,
sizeof( struct V_157 ) ) ;
F_55 ( & V_135 -> V_144 ) ;
}
}
F_27 ( & V_53 . V_139 , V_50 ) ;
}
void F_72 ( void * V_160 )
{
struct V_97 * V_45 = V_160 ;
struct V_99 * V_100 ;
int V_161 ;
V_100 = (struct V_99 * ) V_45 -> V_104 . V_105 ;
V_161 = V_45 -> V_47 . V_162 ;
if ( V_100 -> V_48 >= V_163 ) {
F_39 ( L_4 ,
V_100 -> V_48 , V_161 ) ;
F_73 ( L_5 , V_164 ,
( unsigned char * ) V_45 -> V_104 . V_105 , V_161 ) ;
return;
}
if ( V_165 [ V_100 -> V_48 ] . V_166 )
V_165 [ V_100 -> V_48 ] . V_166 ( V_100 ) ;
else
F_39 ( L_6 , V_100 -> V_48 ) ;
}
int F_74 ( void )
{
struct V_99 * V_45 ;
struct V_134 * V_135 ;
int V_64 ;
V_135 = F_75 ( sizeof( * V_135 ) +
sizeof( struct V_99 ) ,
V_167 ) ;
if ( ! V_135 )
return - V_168 ;
V_45 = (struct V_99 * ) V_135 -> V_45 ;
V_45 -> V_48 = V_169 ;
V_64 = F_19 ( V_45 ,
sizeof( struct V_99 ) ) ;
if ( V_64 != 0 ) {
F_39 ( L_7 , V_64 ) ;
goto V_170;
}
V_170:
F_12 ( V_135 ) ;
return V_64 ;
}
struct V_30 * F_76 ( struct V_30 * V_80 )
{
struct V_171 * V_172 , * V_59 ;
int V_77 ;
struct V_30 * V_173 ;
struct V_30 * V_174 = V_80 ;
int V_175 ;
int V_2 = 1 ;
if ( F_77 ( & V_80 -> V_38 ) )
return V_174 ;
V_175 = V_80 -> V_176 ++ ;
if ( V_175 > ( V_80 -> V_57 ) ) {
V_80 -> V_176 = 0 ;
return V_174 ;
}
V_77 = V_42 . V_90 [ F_23 () ] ;
F_24 () ;
F_78 (cur, tmp, &primary->sc_list) {
V_173 = F_79 ( V_172 , struct V_30 , V_38 ) ;
if ( V_173 -> V_72 != V_177 )
continue;
if ( V_173 -> V_89 == V_77 )
return V_173 ;
if ( V_2 == V_175 )
return V_173 ;
V_2 ++ ;
}
return V_174 ;
}
static void F_80 ( struct V_30 * V_51 )
{
struct V_171 * V_172 , * V_59 ;
struct V_30 * V_173 ;
if ( V_51 -> V_74 == NULL )
return;
F_78 (cur, tmp, &primary_channel->sc_list) {
V_173 = F_79 ( V_172 , struct V_30 , V_38 ) ;
V_51 -> V_74 ( V_173 ) ;
}
}
void F_81 ( struct V_30 * V_51 ,
void (* F_82)( struct V_30 * V_178 ) )
{
V_51 -> V_74 = F_82 ;
}
bool F_83 ( struct V_30 * V_80 )
{
bool V_64 ;
V_64 = ! F_77 ( & V_80 -> V_38 ) ;
if ( V_64 ) {
F_80 ( V_80 ) ;
}
return V_64 ;
}
void F_84 ( struct V_30 * V_32 ,
void (* F_85)( struct V_30 * ) )
{
V_32 -> V_131 = F_85 ;
}
