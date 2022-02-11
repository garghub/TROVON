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
int V_41 ;
void * V_95 ;
struct V_96 * V_45 ;
struct V_97 * V_98 ;
T_5 V_99 ;
while ( 1 ) {
if ( F_51 ( & V_53 . V_100 ) )
break;
F_52 (cpu) {
V_95 = V_42 . V_101 [ V_41 ] ;
V_45 = (struct V_96 * ) V_95 +
V_102 ;
V_99 = F_53 ( V_45 -> V_47 . V_99 ) ;
if ( V_99 == V_103 )
continue;
V_98 = (struct V_97 * )
V_45 -> V_104 . V_105 ;
if ( V_98 -> V_48 == V_106 )
F_54 ( & V_53 . V_100 ) ;
F_55 ( V_45 , V_99 ) ;
}
F_56 ( 10 ) ;
}
F_52 (cpu) {
V_95 = V_42 . V_101 [ V_41 ] ;
V_45 = (struct V_96 * ) V_95 + V_102 ;
V_45 -> V_47 . V_99 = V_103 ;
}
}
static void F_57 ( struct V_97 * V_98 )
{
F_54 ( & V_53 . V_100 ) ;
}
void F_58 ( bool V_107 )
{
struct V_97 V_98 ;
if ( V_85 < V_108 )
return;
F_59 ( & V_53 . V_100 ) ;
memset ( & V_98 , 0 , sizeof( struct V_97 ) ) ;
V_98 . V_48 = V_109 ;
F_19 ( & V_98 , sizeof( struct V_97 ) ) ;
if ( ! V_107 )
F_60 ( & V_53 . V_100 ) ;
else
F_50 () ;
}
static void F_61 ( struct V_97 * V_98 )
{
struct V_110 * V_66 ;
struct V_30 * V_61 ;
V_66 = (struct V_110 * ) V_98 ;
V_61 = F_5 () ;
if ( ! V_61 ) {
F_39 ( L_3 ) ;
return;
}
V_61 -> V_111 = true ;
V_61 -> V_112 = (struct V_113 * )
( F_62 ( ( unsigned long )
& V_61 -> V_114 ,
V_115 ) ) ;
V_61 -> V_112 -> V_116 . V_117 = 0 ;
V_61 -> V_112 -> V_116 . V_104 . V_34 = V_118 ;
V_61 -> V_112 -> V_119 = 0 ;
V_61 -> V_112 -> V_120 = 0 ;
if ( V_85 != V_86 ) {
V_61 -> V_121 =
( V_66 -> V_121 != 0 ) ;
V_61 -> V_112 -> V_116 . V_104 . V_34 =
V_66 -> V_122 ;
}
memcpy ( & V_61 -> V_65 , V_66 ,
sizeof( struct V_110 ) ) ;
V_61 -> V_123 = ( T_3 ) V_66 -> V_124 / 32 ;
V_61 -> V_125 = ( T_3 ) V_66 -> V_124 % 32 ;
F_32 ( V_61 ) ;
}
static void F_63 ( struct V_97 * V_98 )
{
struct V_126 * V_52 ;
struct V_30 * V_32 ;
unsigned long V_50 ;
struct V_127 * V_128 ;
V_52 = (struct V_126 * ) V_98 ;
F_33 ( & V_53 . V_54 ) ;
V_32 = F_64 ( V_52 -> V_46 ) ;
if ( V_32 == NULL ) {
goto V_129;
}
F_26 ( & V_32 -> V_37 , V_50 ) ;
V_32 -> V_52 = true ;
F_27 ( & V_32 -> V_37 , V_50 ) ;
if ( V_32 -> V_60 ) {
if ( V_32 -> V_130 ) {
V_32 -> V_130 ( V_32 ) ;
goto V_129;
}
V_128 = F_65 ( & V_32 -> V_60 -> V_127 ) ;
if ( V_128 ) {
F_31 ( V_32 -> V_60 ) ;
F_66 ( V_128 ) ;
}
} else {
F_20 ( V_32 ,
V_32 -> V_65 . V_46 ) ;
}
V_129:
F_35 ( & V_53 . V_54 ) ;
}
void F_67 ( struct V_30 * V_32 )
{
F_33 ( & V_53 . V_54 ) ;
F_21 ( ! F_68 ( V_32 ) ) ;
V_32 -> V_52 = true ;
F_31 ( V_32 -> V_60 ) ;
F_35 ( & V_53 . V_54 ) ;
}
static void F_69 (
struct V_97 * V_98 )
{
}
static void F_70 ( struct V_97 * V_98 )
{
struct V_131 * V_132 ;
struct V_133 * V_134 ;
struct V_97 * V_135 ;
struct V_136 * V_137 ;
unsigned long V_50 ;
V_132 = (struct V_131 * ) V_98 ;
F_26 ( & V_53 . V_138 , V_50 ) ;
F_34 (msginfo, &vmbus_connection.chn_msg_list,
msglistentry) {
V_135 =
(struct V_97 * ) V_134 -> V_45 ;
if ( V_135 -> V_48 == V_139 ) {
V_137 =
(struct V_136 * ) V_134 -> V_45 ;
if ( V_137 -> V_46 == V_132 -> V_46 &&
V_137 -> V_140 == V_132 -> V_140 ) {
memcpy ( & V_134 -> V_141 . V_142 ,
V_132 ,
sizeof(
struct V_131 ) ) ;
F_54 ( & V_134 -> V_143 ) ;
break;
}
}
}
F_27 ( & V_53 . V_138 , V_50 ) ;
}
static void F_71 ( struct V_97 * V_98 )
{
struct V_144 * V_145 ;
struct V_133 * V_134 ;
struct V_97 * V_135 ;
struct V_146 * V_147 ;
unsigned long V_50 ;
V_145 = (struct V_144 * ) V_98 ;
F_26 ( & V_53 . V_138 , V_50 ) ;
F_34 (msginfo, &vmbus_connection.chn_msg_list,
msglistentry) {
V_135 =
(struct V_97 * ) V_134 -> V_45 ;
if ( V_135 -> V_48 == V_148 ) {
V_147 =
(struct V_146 * ) V_135 ;
if ( ( V_145 -> V_46 ==
V_147 -> V_46 ) &&
( V_145 -> V_149 == V_147 -> V_149 ) ) {
memcpy ( & V_134 -> V_141 . V_150 ,
V_145 ,
sizeof(
struct V_144 ) ) ;
F_54 ( & V_134 -> V_143 ) ;
break;
}
}
}
F_27 ( & V_53 . V_138 , V_50 ) ;
}
static void F_72 (
struct V_97 * V_98 )
{
struct V_151 * V_152 ;
struct V_133 * V_134 ;
struct V_97 * V_135 ;
struct V_153 * V_154 ;
unsigned long V_50 ;
V_152 = (struct V_151 * ) V_98 ;
F_26 ( & V_53 . V_138 , V_50 ) ;
F_34 (msginfo, &vmbus_connection.chn_msg_list,
msglistentry) {
V_135 =
(struct V_97 * ) V_134 -> V_45 ;
if ( V_135 -> V_48 == V_155 ) {
V_154 =
(struct V_153 * ) V_135 ;
if ( V_152 -> V_149 == V_154 -> V_149 ) {
memcpy ( & V_134 -> V_141 . V_152 ,
V_152 ,
sizeof(
struct V_151 ) ) ;
F_54 ( & V_134 -> V_143 ) ;
break;
}
}
}
F_27 ( & V_53 . V_138 , V_50 ) ;
}
static void F_73 (
struct V_97 * V_98 )
{
struct V_133 * V_134 ;
struct V_97 * V_135 ;
struct V_156 * V_157 ;
unsigned long V_50 ;
V_157 = (struct V_156 * ) V_98 ;
F_26 ( & V_53 . V_138 , V_50 ) ;
F_34 (msginfo, &vmbus_connection.chn_msg_list,
msglistentry) {
V_135 =
(struct V_97 * ) V_134 -> V_45 ;
if ( V_135 -> V_48 ==
V_158 ) {
memcpy ( & V_134 -> V_141 . V_157 ,
V_157 ,
sizeof( struct V_156 ) ) ;
F_54 ( & V_134 -> V_143 ) ;
}
}
F_27 ( & V_53 . V_138 , V_50 ) ;
}
void F_74 ( void * V_159 )
{
struct V_96 * V_45 = V_159 ;
struct V_97 * V_98 ;
int V_160 ;
V_98 = (struct V_97 * ) V_45 -> V_104 . V_105 ;
V_160 = V_45 -> V_47 . V_161 ;
if ( V_98 -> V_48 >= V_162 ) {
F_39 ( L_4 ,
V_98 -> V_48 , V_160 ) ;
F_75 ( L_5 , V_163 ,
( unsigned char * ) V_45 -> V_104 . V_105 , V_160 ) ;
return;
}
if ( V_164 [ V_98 -> V_48 ] . V_165 )
V_164 [ V_98 -> V_48 ] . V_165 ( V_98 ) ;
else
F_39 ( L_6 , V_98 -> V_48 ) ;
}
int F_76 ( void )
{
struct V_97 * V_45 ;
struct V_133 * V_134 ;
int V_64 ;
V_134 = F_77 ( sizeof( * V_134 ) +
sizeof( struct V_97 ) ,
V_166 ) ;
if ( ! V_134 )
return - V_167 ;
V_45 = (struct V_97 * ) V_134 -> V_45 ;
V_45 -> V_48 = V_168 ;
V_64 = F_19 ( V_45 ,
sizeof( struct V_97 ) ) ;
if ( V_64 != 0 ) {
F_39 ( L_7 , V_64 ) ;
goto V_169;
}
V_169:
F_12 ( V_134 ) ;
return V_64 ;
}
struct V_30 * F_78 ( struct V_30 * V_80 )
{
struct V_170 * V_171 , * V_59 ;
int V_77 ;
struct V_30 * V_172 ;
struct V_30 * V_173 = V_80 ;
int V_174 ;
int V_2 = 1 ;
if ( F_79 ( & V_80 -> V_38 ) )
return V_173 ;
V_174 = V_80 -> V_175 ++ ;
if ( V_174 > ( V_80 -> V_57 ) ) {
V_80 -> V_175 = 0 ;
return V_173 ;
}
V_77 = V_42 . V_90 [ F_23 () ] ;
F_24 () ;
F_80 (cur, tmp, &primary->sc_list) {
V_172 = F_81 ( V_171 , struct V_30 , V_38 ) ;
if ( V_172 -> V_72 != V_176 )
continue;
if ( V_172 -> V_89 == V_77 )
return V_172 ;
if ( V_2 == V_174 )
return V_172 ;
V_2 ++ ;
}
return V_173 ;
}
static void F_82 ( struct V_30 * V_51 )
{
struct V_170 * V_171 , * V_59 ;
struct V_30 * V_172 ;
if ( V_51 -> V_74 == NULL )
return;
F_80 (cur, tmp, &primary_channel->sc_list) {
V_172 = F_81 ( V_171 , struct V_30 , V_38 ) ;
V_51 -> V_74 ( V_172 ) ;
}
}
void F_83 ( struct V_30 * V_51 ,
void (* F_84)( struct V_30 * V_177 ) )
{
V_51 -> V_74 = F_84 ;
}
bool F_85 ( struct V_30 * V_80 )
{
bool V_64 ;
V_64 = ! F_79 ( & V_80 -> V_38 ) ;
if ( V_64 ) {
F_82 ( V_80 ) ;
}
return V_64 ;
}
void F_86 ( struct V_30 * V_32 ,
void (* F_87)( struct V_30 * ) )
{
V_32 -> V_130 = F_87 ;
}
