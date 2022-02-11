static bool F_1 ( const T_1 * V_1 )
{
int V_2 ;
for ( V_2 = 0 ; V_2 < F_2 ( V_3 ) ; V_2 ++ )
if ( ! F_3 ( * V_1 , V_3 [ V_2 ] . V_1 ) )
return true ;
return false ;
}
static T_2 F_4 ( const struct V_4 * V_5 )
{
const T_1 * V_1 = & V_5 -> V_6 . V_7 . V_8 ;
T_2 V_2 ;
if ( F_5 ( V_5 ) || F_1 ( V_1 ) )
return V_9 ;
for ( V_2 = V_10 ; V_2 < V_9 ; V_2 ++ ) {
if ( ! F_3 ( * V_1 , V_11 [ V_2 ] . V_1 ) )
return V_2 ;
}
F_6 ( L_1 , V_1 ) ;
return V_2 ;
}
bool F_7 ( struct V_12 * V_13 ,
struct V_14 * V_15 , T_3 * V_16 ,
int V_17 , int V_18 )
{
int V_19 , V_20 ;
int V_21 , V_22 ;
int V_23 , V_24 ;
int V_25 , V_26 ;
int V_2 ;
bool V_27 = false ;
V_13 -> V_28 = 0x10 ;
V_23 = ( V_17 >> 16 ) ;
V_24 = ( V_17 & 0xFFFF ) ;
V_25 = ( V_18 >> 16 ) ;
V_26 = ( V_18 & 0xFFFF ) ;
V_15 = (struct V_14 * ) & V_16 [
sizeof( struct V_29 ) +
sizeof( struct V_12 ) ] ;
V_19 = V_15 -> V_30 ;
V_20 = 0 ;
V_21 = V_15 -> V_31 ;
V_22 = 0 ;
for ( V_2 = 0 ; V_2 < V_15 -> V_30 ; V_2 ++ ) {
if ( ( V_15 -> V_32 [ V_2 ] . V_33 == V_23 ) &&
( V_15 -> V_32 [ V_2 ] . V_34 == V_24 ) ) {
V_19 = V_15 -> V_32 [ V_2 ] . V_33 ;
V_20 = V_15 -> V_32 [ V_2 ] . V_34 ;
V_27 = true ;
}
}
if ( ! V_27 )
goto V_35;
V_27 = false ;
for ( V_2 = V_15 -> V_30 ;
( V_2 < V_15 -> V_30 + V_15 -> V_31 ) ; V_2 ++ ) {
if ( ( V_15 -> V_32 [ V_2 ] . V_33 == V_25 ) &&
( V_15 -> V_32 [ V_2 ] . V_34 == V_26 ) ) {
V_21 = V_15 -> V_32 [ V_2 ] . V_33 ;
V_22 = V_15 -> V_32 [ V_2 ] . V_34 ;
V_27 = true ;
}
}
V_35:
if ( ! V_27 ) {
V_15 -> V_30 = 0 ;
V_15 -> V_31 = 0 ;
} else {
V_15 -> V_30 = 1 ;
V_15 -> V_31 = 1 ;
}
V_15 -> V_32 [ 0 ] . V_33 = V_19 ;
V_15 -> V_32 [ 0 ] . V_34 = V_20 ;
V_15 -> V_32 [ 1 ] . V_33 = V_21 ;
V_15 -> V_32 [ 1 ] . V_34 = V_22 ;
return V_27 ;
}
static struct V_4 * F_8 ( void )
{
struct V_4 * V_5 ;
V_5 = F_9 ( sizeof( * V_5 ) , V_36 ) ;
if ( ! V_5 )
return NULL ;
V_5 -> V_37 = true ;
F_10 ( & V_5 -> V_38 ) ;
F_10 ( & V_5 -> V_39 ) ;
F_11 ( & V_5 -> V_40 ) ;
F_11 ( & V_5 -> V_41 ) ;
return V_5 ;
}
static void F_12 ( struct V_4 * V_5 )
{
F_13 ( V_5 ) ;
}
static void F_14 ( void * V_42 )
{
struct V_4 * V_5 = V_42 ;
int V_43 = F_15 () ;
F_16 ( & V_5 -> V_41 , & V_44 . V_41 [ V_43 ] ) ;
}
static void F_17 ( void * V_42 )
{
struct V_4 * V_5 = V_42 ;
F_18 ( & V_5 -> V_41 ) ;
}
static void F_19 ( T_4 V_45 )
{
struct V_46 V_47 ;
memset ( & V_47 , 0 , sizeof( struct V_46 ) ) ;
V_47 . V_48 = V_45 ;
V_47 . V_49 . V_50 = V_51 ;
F_20 ( & V_47 , sizeof( struct V_46 ) ) ;
}
void F_21 ( struct V_4 * V_5 )
{
struct V_52 * V_53 ;
V_53 = V_44 . V_54 [ V_5 -> V_55 ] ;
F_22 ( V_53 ) ;
}
void F_23 ( struct V_4 * V_5 )
{
struct V_52 * V_53 ;
V_53 = V_44 . V_54 [ V_5 -> V_55 ] ;
F_24 ( V_53 ) ;
F_25 ( V_53 ) ;
}
void F_26 ( struct V_4 * V_5 , T_4 V_45 )
{
unsigned long V_56 ;
struct V_4 * V_57 ;
F_27 ( ! V_5 -> V_58 ) ;
F_27 ( ! F_28 ( & V_59 . V_60 ) ) ;
F_21 ( V_5 ) ;
if ( V_5 -> V_55 != F_29 () ) {
F_30 () ;
F_31 ( V_5 -> V_55 ,
F_17 , V_5 , true ) ;
} else {
F_17 ( V_5 ) ;
F_30 () ;
}
F_23 ( V_5 ) ;
if ( V_5 -> V_57 == NULL ) {
F_18 ( & V_5 -> V_61 ) ;
V_57 = V_5 ;
} else {
V_57 = V_5 -> V_57 ;
F_32 ( & V_57 -> V_39 , V_56 ) ;
F_18 ( & V_5 -> V_40 ) ;
V_57 -> V_62 -- ;
F_33 ( & V_57 -> V_39 , V_56 ) ;
}
if ( V_5 -> V_63 == V_64 )
F_34 ( V_5 -> V_55 ,
& V_57 -> V_65 ) ;
F_19 ( V_45 ) ;
F_12 ( V_5 ) ;
}
void F_35 ( void )
{
struct V_4 * V_5 , * V_66 ;
F_36 ( & V_59 . V_60 ) ;
F_37 (channel, tmp, &vmbus_connection.chn_list,
listentry) {
V_5 -> V_58 = true ;
F_38 ( V_5 -> V_67 ) ;
}
F_39 ( & V_59 . V_60 ) ;
}
static void F_40 ( struct V_4 * V_68 )
{
struct V_4 * V_5 ;
bool V_69 = true ;
unsigned long V_56 ;
T_2 V_70 ;
int V_71 ;
F_36 ( & V_59 . V_60 ) ;
F_41 (channel, &vmbus_connection.chn_list, listentry) {
if ( ! F_3 ( V_5 -> V_6 . V_7 . V_8 ,
V_68 -> V_6 . V_7 . V_8 ) &&
! F_3 ( V_5 -> V_6 . V_7 . V_72 ,
V_68 -> V_6 . V_7 . V_72 ) ) {
V_69 = false ;
break;
}
}
if ( V_69 )
F_16 ( & V_68 -> V_61 ,
& V_59 . V_73 ) ;
F_39 ( & V_59 . V_60 ) ;
if ( ! V_69 ) {
if ( V_68 -> V_6 . V_7 . V_74 != 0 ) {
V_68 -> V_57 = V_5 ;
F_32 ( & V_5 -> V_39 , V_56 ) ;
F_16 ( & V_68 -> V_40 , & V_5 -> V_40 ) ;
V_5 -> V_62 ++ ;
F_33 ( & V_5 -> V_39 , V_56 ) ;
} else
goto V_75;
}
V_70 = F_4 ( V_68 ) ;
F_42 ( V_68 , V_70 ) ;
F_21 ( V_68 ) ;
if ( V_68 -> V_55 != F_29 () ) {
F_30 () ;
F_31 ( V_68 -> V_55 ,
F_14 ,
V_68 , true ) ;
} else {
F_14 ( V_68 ) ;
F_30 () ;
}
F_23 ( V_68 ) ;
V_68 -> V_76 = V_77 ;
if ( ! V_69 ) {
if ( V_5 -> V_78 != NULL )
V_5 -> V_78 ( V_68 ) ;
return;
}
V_68 -> V_67 = F_43 (
& V_68 -> V_6 . V_7 . V_8 ,
& V_68 -> V_6 . V_7 . V_72 ,
V_68 ) ;
if ( ! V_68 -> V_67 )
goto V_79;
V_68 -> V_67 -> V_80 = V_70 ;
F_36 ( & V_59 . V_60 ) ;
V_71 = F_44 ( V_68 -> V_67 ) ;
F_39 ( & V_59 . V_60 ) ;
if ( V_71 != 0 ) {
F_45 ( L_2 ,
V_68 -> V_6 . V_48 ) ;
F_13 ( V_68 -> V_67 ) ;
goto V_79;
}
return;
V_79:
F_36 ( & V_59 . V_60 ) ;
F_18 ( & V_68 -> V_61 ) ;
F_39 ( & V_59 . V_60 ) ;
F_21 ( V_68 ) ;
if ( V_68 -> V_55 != F_29 () ) {
F_30 () ;
F_31 ( V_68 -> V_55 ,
F_17 , V_68 , true ) ;
} else {
F_17 ( V_68 ) ;
F_30 () ;
}
F_23 ( V_68 ) ;
F_19 ( V_68 -> V_6 . V_48 ) ;
V_75:
F_12 ( V_68 ) ;
}
static void F_42 ( struct V_4 * V_5 , T_2 V_70 )
{
T_4 V_81 ;
bool V_82 = V_11 [ V_70 ] . V_83 ;
struct V_4 * V_84 = V_5 -> V_57 ;
int V_85 ;
struct V_86 V_87 ;
struct V_86 * V_88 ;
if ( ( V_89 == V_90 ) ||
( V_89 == V_91 ) || ( ! V_82 ) ) {
V_5 -> V_92 = 0 ;
V_5 -> V_55 = 0 ;
V_5 -> V_93 = V_44 . V_94 [ 0 ] ;
return;
}
if ( ( V_5 -> V_63 == V_95 ) || ( ! V_84 ) ) {
while ( true ) {
V_85 = V_96 ++ ;
if ( V_85 == V_97 ) {
V_85 = V_96 = 0 ;
continue;
}
if ( F_46 ( F_47 ( V_85 ) ) )
continue;
break;
}
V_5 -> V_92 = V_85 ;
V_84 = V_5 ;
}
V_88 = & V_44 . V_98 [ V_84 -> V_92 ] ;
if ( F_48 ( V_88 ) ==
F_48 ( F_47 ( V_84 -> V_92 ) ) ) {
F_49 ( V_88 ) ;
}
F_50 ( & V_87 , V_88 ,
F_47 ( V_84 -> V_92 ) ) ;
V_81 = - 1 ;
if ( V_84 -> V_63 == V_64 ) {
if ( F_51 ( & V_84 -> V_65 ,
F_47 ( V_84 -> V_92 ) ) )
F_49 ( & V_84 -> V_65 ) ;
}
while ( true ) {
V_81 = F_52 ( V_81 , & V_87 ) ;
if ( V_81 >= V_99 ) {
V_81 = - 1 ;
F_53 ( & V_87 ,
F_47 ( V_84 -> V_92 ) ) ;
continue;
}
if ( V_84 -> V_63 == V_64 ) {
if ( ! F_54 ( V_81 ,
& V_84 -> V_65 ) ) {
F_55 ( V_81 ,
& V_84 -> V_65 ) ;
F_55 ( V_81 , V_88 ) ;
break;
}
} else {
F_55 ( V_81 , V_88 ) ;
break;
}
}
V_5 -> V_55 = V_81 ;
V_5 -> V_93 = V_44 . V_94 [ V_81 ] ;
}
static void F_56 ( void )
{
int V_43 ;
void * V_100 ;
struct V_101 * V_47 ;
struct V_102 * V_103 ;
T_4 V_104 ;
while ( 1 ) {
if ( F_57 ( & V_59 . V_105 ) )
break;
F_58 (cpu) {
V_100 = V_44 . V_106 [ V_43 ] ;
V_47 = (struct V_101 * ) V_100 +
V_107 ;
V_104 = F_59 ( V_47 -> V_49 . V_104 ) ;
if ( V_104 == V_108 )
continue;
V_103 = (struct V_102 * )
V_47 -> V_109 . V_110 ;
if ( V_103 -> V_50 == V_111 )
F_60 ( & V_59 . V_105 ) ;
F_61 ( V_47 , V_104 ) ;
}
F_62 ( 10 ) ;
}
F_58 (cpu) {
V_100 = V_44 . V_106 [ V_43 ] ;
V_47 = (struct V_101 * ) V_100 + V_107 ;
V_47 -> V_49 . V_104 = V_108 ;
}
}
static void F_63 ( struct V_102 * V_103 )
{
F_60 ( & V_59 . V_105 ) ;
}
void F_64 ( bool V_112 )
{
struct V_102 V_103 ;
if ( V_89 < V_113 )
return;
F_65 ( & V_59 . V_105 ) ;
memset ( & V_103 , 0 , sizeof( struct V_102 ) ) ;
V_103 . V_50 = V_114 ;
F_20 ( & V_103 , sizeof( struct V_102 ) ) ;
if ( ! V_112 )
F_66 ( & V_59 . V_105 ) ;
else
F_56 () ;
}
static void F_67 ( struct V_102 * V_103 )
{
struct V_115 * V_7 ;
struct V_4 * V_68 ;
V_7 = (struct V_115 * ) V_103 ;
V_68 = F_8 () ;
if ( ! V_68 ) {
F_45 ( L_3 ) ;
return;
}
V_68 -> V_116 = true ;
V_68 -> V_117 = (struct V_118 * )
( F_68 ( ( unsigned long )
& V_68 -> V_119 ,
V_120 ) ) ;
V_68 -> V_117 -> V_121 . V_122 = 0 ;
V_68 -> V_117 -> V_121 . V_109 . V_123 = V_124 ;
V_68 -> V_117 -> V_125 = 0 ;
V_68 -> V_117 -> V_126 = 0 ;
if ( V_89 != V_90 ) {
V_68 -> V_127 =
( V_7 -> V_127 != 0 ) ;
V_68 -> V_117 -> V_121 . V_109 . V_123 =
V_7 -> V_128 ;
}
memcpy ( & V_68 -> V_6 , V_7 ,
sizeof( struct V_115 ) ) ;
V_68 -> V_129 = ( T_3 ) V_7 -> V_130 / 32 ;
V_68 -> V_131 = ( T_3 ) V_7 -> V_130 % 32 ;
F_40 ( V_68 ) ;
}
static void F_69 ( struct V_102 * V_103 )
{
struct V_132 * V_58 ;
struct V_4 * V_5 ;
unsigned long V_56 ;
struct V_133 * V_134 ;
V_58 = (struct V_132 * ) V_103 ;
F_36 ( & V_59 . V_60 ) ;
V_5 = F_70 ( V_58 -> V_48 ) ;
if ( V_5 == NULL ) {
goto V_135;
}
F_32 ( & V_5 -> V_39 , V_56 ) ;
V_5 -> V_58 = true ;
F_33 ( & V_5 -> V_39 , V_56 ) ;
if ( V_5 -> V_67 ) {
if ( V_5 -> V_136 ) {
V_5 -> V_136 ( V_5 ) ;
goto V_135;
}
V_134 = F_71 ( & V_5 -> V_67 -> V_133 ) ;
if ( V_134 ) {
F_38 ( V_5 -> V_67 ) ;
F_72 ( V_134 ) ;
}
} else {
F_26 ( V_5 ,
V_5 -> V_6 . V_48 ) ;
}
V_135:
F_39 ( & V_59 . V_60 ) ;
}
void F_73 ( struct V_4 * V_5 )
{
F_36 ( & V_59 . V_60 ) ;
F_27 ( ! F_5 ( V_5 ) ) ;
V_5 -> V_58 = true ;
F_38 ( V_5 -> V_67 ) ;
F_39 ( & V_59 . V_60 ) ;
}
static void F_74 (
struct V_102 * V_103 )
{
}
static void F_75 ( struct V_102 * V_103 )
{
struct V_137 * V_138 ;
struct V_139 * V_140 ;
struct V_102 * V_141 ;
struct V_142 * V_143 ;
unsigned long V_56 ;
V_138 = (struct V_137 * ) V_103 ;
F_32 ( & V_59 . V_144 , V_56 ) ;
F_41 (msginfo, &vmbus_connection.chn_msg_list,
msglistentry) {
V_141 =
(struct V_102 * ) V_140 -> V_47 ;
if ( V_141 -> V_50 == V_145 ) {
V_143 =
(struct V_142 * ) V_140 -> V_47 ;
if ( V_143 -> V_48 == V_138 -> V_48 &&
V_143 -> V_146 == V_138 -> V_146 ) {
memcpy ( & V_140 -> V_147 . V_148 ,
V_138 ,
sizeof(
struct V_137 ) ) ;
F_60 ( & V_140 -> V_149 ) ;
break;
}
}
}
F_33 ( & V_59 . V_144 , V_56 ) ;
}
static void F_76 ( struct V_102 * V_103 )
{
struct V_150 * V_151 ;
struct V_139 * V_140 ;
struct V_102 * V_141 ;
struct V_152 * V_153 ;
unsigned long V_56 ;
V_151 = (struct V_150 * ) V_103 ;
F_32 ( & V_59 . V_144 , V_56 ) ;
F_41 (msginfo, &vmbus_connection.chn_msg_list,
msglistentry) {
V_141 =
(struct V_102 * ) V_140 -> V_47 ;
if ( V_141 -> V_50 == V_154 ) {
V_153 =
(struct V_152 * ) V_141 ;
if ( ( V_151 -> V_48 ==
V_153 -> V_48 ) &&
( V_151 -> V_155 == V_153 -> V_155 ) ) {
memcpy ( & V_140 -> V_147 . V_156 ,
V_151 ,
sizeof(
struct V_150 ) ) ;
F_60 ( & V_140 -> V_149 ) ;
break;
}
}
}
F_33 ( & V_59 . V_144 , V_56 ) ;
}
static void F_77 (
struct V_102 * V_103 )
{
struct V_157 * V_158 ;
struct V_139 * V_140 ;
struct V_102 * V_141 ;
struct V_159 * V_160 ;
unsigned long V_56 ;
V_158 = (struct V_157 * ) V_103 ;
F_32 ( & V_59 . V_144 , V_56 ) ;
F_41 (msginfo, &vmbus_connection.chn_msg_list,
msglistentry) {
V_141 =
(struct V_102 * ) V_140 -> V_47 ;
if ( V_141 -> V_50 == V_161 ) {
V_160 =
(struct V_159 * ) V_141 ;
if ( V_158 -> V_155 == V_160 -> V_155 ) {
memcpy ( & V_140 -> V_147 . V_158 ,
V_158 ,
sizeof(
struct V_157 ) ) ;
F_60 ( & V_140 -> V_149 ) ;
break;
}
}
}
F_33 ( & V_59 . V_144 , V_56 ) ;
}
static void F_78 (
struct V_102 * V_103 )
{
struct V_139 * V_140 ;
struct V_102 * V_141 ;
struct V_162 * V_163 ;
unsigned long V_56 ;
V_163 = (struct V_162 * ) V_103 ;
F_32 ( & V_59 . V_144 , V_56 ) ;
F_41 (msginfo, &vmbus_connection.chn_msg_list,
msglistentry) {
V_141 =
(struct V_102 * ) V_140 -> V_47 ;
if ( V_141 -> V_50 ==
V_164 ) {
memcpy ( & V_140 -> V_147 . V_163 ,
V_163 ,
sizeof( struct V_162 ) ) ;
F_60 ( & V_140 -> V_149 ) ;
}
}
F_33 ( & V_59 . V_144 , V_56 ) ;
}
void F_79 ( void * V_165 )
{
struct V_101 * V_47 = V_165 ;
struct V_102 * V_103 ;
int V_166 ;
V_103 = (struct V_102 * ) V_47 -> V_109 . V_110 ;
V_166 = V_47 -> V_49 . V_167 ;
if ( V_103 -> V_50 >= V_168 ) {
F_45 ( L_4 ,
V_103 -> V_50 , V_166 ) ;
F_80 ( L_5 , V_169 ,
( unsigned char * ) V_47 -> V_109 . V_110 , V_166 ) ;
return;
}
if ( V_170 [ V_103 -> V_50 ] . V_171 )
V_170 [ V_103 -> V_50 ] . V_171 ( V_103 ) ;
else
F_45 ( L_6 , V_103 -> V_50 ) ;
}
int F_81 ( void )
{
struct V_102 * V_47 ;
struct V_139 * V_140 ;
int V_71 ;
V_140 = F_82 ( sizeof( * V_140 ) +
sizeof( struct V_102 ) ,
V_172 ) ;
if ( ! V_140 )
return - V_173 ;
V_47 = (struct V_102 * ) V_140 -> V_47 ;
V_47 -> V_50 = V_174 ;
V_71 = F_20 ( V_47 ,
sizeof( struct V_102 ) ) ;
if ( V_71 != 0 ) {
F_45 ( L_7 , V_71 ) ;
goto V_175;
}
V_175:
F_13 ( V_140 ) ;
return V_71 ;
}
struct V_4 * F_83 ( struct V_4 * V_84 )
{
struct V_176 * V_177 , * V_66 ;
int V_81 ;
struct V_4 * V_178 ;
struct V_4 * V_179 = V_84 ;
int V_180 ;
int V_2 = 1 ;
if ( F_84 ( & V_84 -> V_40 ) )
return V_179 ;
V_180 = V_84 -> V_181 ++ ;
if ( V_180 > ( V_84 -> V_62 ) ) {
V_84 -> V_181 = 0 ;
return V_179 ;
}
V_81 = V_44 . V_94 [ F_29 () ] ;
F_30 () ;
F_85 (cur, tmp, &primary->sc_list) {
V_178 = F_86 ( V_177 , struct V_4 , V_40 ) ;
if ( V_178 -> V_76 != V_182 )
continue;
if ( V_178 -> V_93 == V_81 )
return V_178 ;
if ( V_2 == V_180 )
return V_178 ;
V_2 ++ ;
}
return V_179 ;
}
static void F_87 ( struct V_4 * V_57 )
{
struct V_176 * V_177 , * V_66 ;
struct V_4 * V_178 ;
if ( V_57 -> V_78 == NULL )
return;
F_85 (cur, tmp, &primary_channel->sc_list) {
V_178 = F_86 ( V_177 , struct V_4 , V_40 ) ;
V_57 -> V_78 ( V_178 ) ;
}
}
void F_88 ( struct V_4 * V_57 ,
void (* F_89)( struct V_4 * V_183 ) )
{
V_57 -> V_78 = F_89 ;
}
bool F_90 ( struct V_4 * V_84 )
{
bool V_71 ;
V_71 = ! F_84 ( & V_84 -> V_40 ) ;
if ( V_71 ) {
F_87 ( V_84 ) ;
}
return V_71 ;
}
void F_91 ( struct V_4 * V_5 ,
void (* F_92)( struct V_4 * ) )
{
V_5 -> V_136 = F_92 ;
}
