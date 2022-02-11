static void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
unsigned long V_5 ;
F_2 ( & V_6 . V_7 , V_5 ) ;
F_3 (msginfo, &vmbus_connection.chn_msg_list,
msglistentry) {
if ( V_4 -> V_8 == V_2 ) {
F_4 ( & V_4 -> V_9 ) ;
break;
}
}
F_5 ( & V_6 . V_7 , V_5 ) ;
}
static bool F_6 ( const T_1 * V_10 )
{
int V_11 ;
for ( V_11 = 0 ; V_11 < F_7 ( V_12 ) ; V_11 ++ )
if ( ! F_8 ( * V_10 , V_12 [ V_11 ] . V_10 ) )
return true ;
return false ;
}
static T_2 F_9 ( const struct V_1 * V_2 )
{
const T_1 * V_10 = & V_2 -> V_13 . V_14 . V_15 ;
T_2 V_11 ;
if ( F_10 ( V_2 ) || F_6 ( V_10 ) )
return V_16 ;
for ( V_11 = V_17 ; V_11 < V_16 ; V_11 ++ ) {
if ( ! F_8 ( * V_10 , V_18 [ V_11 ] . V_10 ) )
return V_11 ;
}
F_11 ( L_1 , V_10 ) ;
return V_11 ;
}
bool F_12 ( struct V_19 * V_20 ,
T_3 * V_21 , const int * V_22 , int V_23 ,
const int * V_24 , int V_25 ,
int * V_26 , int * V_27 )
{
int V_28 , V_29 ;
int V_30 , V_31 ;
int V_32 , V_33 ;
int V_34 , V_35 ;
int V_11 , V_36 ;
bool V_37 = false ;
struct V_38 * V_39 ;
V_20 -> V_40 = 0x10 ;
V_39 = (struct V_38 * ) & V_21 [
sizeof( struct V_41 ) +
sizeof( struct V_19 ) ] ;
V_28 = V_39 -> V_42 ;
V_29 = 0 ;
V_30 = V_39 -> V_43 ;
V_31 = 0 ;
for ( V_11 = 0 ; V_11 < V_23 ; V_11 ++ ) {
V_32 = ( V_22 [ V_11 ] >> 16 ) ;
V_33 = ( V_22 [ V_11 ] & 0xFFFF ) ;
for ( V_36 = 0 ; V_36 < V_39 -> V_42 ; V_36 ++ ) {
if ( ( V_39 -> V_44 [ V_36 ] . V_45 == V_32 ) &&
( V_39 -> V_44 [ V_36 ] . V_46 == V_33 ) ) {
V_28 = V_39 -> V_44 [ V_36 ] . V_45 ;
V_29 = V_39 -> V_44 [ V_36 ] . V_46 ;
V_37 = true ;
break;
}
}
if ( V_37 )
break;
}
if ( ! V_37 )
goto V_47;
V_37 = false ;
for ( V_11 = 0 ; V_11 < V_25 ; V_11 ++ ) {
V_34 = ( V_24 [ V_11 ] >> 16 ) ;
V_35 = ( V_24 [ V_11 ] & 0xFFFF ) ;
for ( V_36 = V_39 -> V_42 ;
( V_36 < V_39 -> V_42 + V_39 -> V_43 ) ;
V_36 ++ ) {
if ( ( V_39 -> V_44 [ V_36 ] . V_45 == V_34 ) &&
( V_39 -> V_44 [ V_36 ] . V_46 == V_35 ) ) {
V_30 = V_39 -> V_44 [ V_36 ] . V_45 ;
V_31 = V_39 -> V_44 [ V_36 ] . V_46 ;
V_37 = true ;
break;
}
}
if ( V_37 )
break;
}
V_47:
if ( ! V_37 ) {
V_39 -> V_42 = 0 ;
V_39 -> V_43 = 0 ;
} else {
V_39 -> V_42 = 1 ;
V_39 -> V_43 = 1 ;
}
if ( V_26 )
* V_26 = ( V_28 << 16 ) | V_29 ;
if ( V_27 )
* V_27 = ( V_30 << 16 ) | V_31 ;
V_39 -> V_44 [ 0 ] . V_45 = V_28 ;
V_39 -> V_44 [ 0 ] . V_46 = V_29 ;
V_39 -> V_44 [ 1 ] . V_45 = V_30 ;
V_39 -> V_44 [ 1 ] . V_46 = V_31 ;
return V_37 ;
}
static struct V_1 * F_13 ( void )
{
struct V_1 * V_2 ;
V_2 = F_14 ( sizeof( * V_2 ) , V_48 ) ;
if ( ! V_2 )
return NULL ;
F_15 ( & V_2 -> V_49 ) ;
F_16 ( & V_2 -> V_50 ) ;
F_16 ( & V_2 -> V_51 ) ;
F_17 ( & V_2 -> V_52 ,
V_53 , ( unsigned long ) V_2 ) ;
return V_2 ;
}
static void F_18 ( struct V_1 * V_2 )
{
F_19 ( & V_2 -> V_52 ) ;
F_20 ( V_2 , V_54 ) ;
}
static void F_21 ( void * V_55 )
{
struct V_1 * V_2 = V_55 ;
struct V_56 * V_57
= F_22 ( V_58 . V_59 ) ;
F_23 ( & V_2 -> V_51 , & V_57 -> V_60 ) ;
}
static void F_24 ( void * V_55 )
{
struct V_1 * V_2 = V_55 ;
F_25 ( & V_2 -> V_51 ) ;
}
static void F_26 ( T_4 V_61 )
{
struct V_62 V_63 ;
memset ( & V_63 , 0 , sizeof( struct V_62 ) ) ;
V_63 . V_64 = V_61 ;
V_63 . V_65 . V_66 = V_67 ;
F_27 ( & V_63 , sizeof( struct V_62 ) ,
true ) ;
}
void F_28 ( struct V_1 * V_2 , T_4 V_61 )
{
unsigned long V_5 ;
struct V_1 * V_68 ;
F_29 ( ! V_2 -> V_69 ) ;
F_29 ( ! F_30 ( & V_6 . V_70 ) ) ;
if ( V_2 -> V_71 != F_31 () ) {
F_32 () ;
F_33 ( V_2 -> V_71 ,
F_24 , V_2 , true ) ;
} else {
F_24 ( V_2 ) ;
F_32 () ;
}
if ( V_2 -> V_68 == NULL ) {
F_34 ( & V_2 -> V_72 ) ;
V_68 = V_2 ;
} else {
V_68 = V_2 -> V_68 ;
F_2 ( & V_68 -> V_49 , V_5 ) ;
F_34 ( & V_2 -> V_50 ) ;
V_68 -> V_73 -- ;
F_5 ( & V_68 -> V_49 , V_5 ) ;
}
if ( V_2 -> V_74 == V_75 )
F_35 ( V_2 -> V_71 ,
& V_68 -> V_76 ) ;
F_26 ( V_61 ) ;
F_18 ( V_2 ) ;
}
void F_36 ( void )
{
struct V_1 * V_2 , * V_77 ;
F_37 (channel, tmp, &vmbus_connection.chn_list,
listentry) {
V_2 -> V_69 = true ;
F_38 ( V_2 -> V_78 ) ;
}
}
static void F_39 ( struct V_1 * V_79 )
{
struct V_1 * V_2 ;
bool V_80 = true ;
unsigned long V_5 ;
T_2 V_81 ;
int V_82 ;
F_40 ( & V_6 . V_70 ) ;
F_3 (channel, &vmbus_connection.chn_list, listentry) {
if ( ! F_8 ( V_2 -> V_13 . V_14 . V_15 ,
V_79 -> V_13 . V_14 . V_15 ) &&
! F_8 ( V_2 -> V_13 . V_14 . V_83 ,
V_79 -> V_13 . V_14 . V_83 ) ) {
V_80 = false ;
break;
}
}
if ( V_80 )
F_41 ( & V_79 -> V_72 ,
& V_6 . V_84 ) ;
F_42 ( & V_6 . V_70 ) ;
if ( ! V_80 ) {
if ( V_79 -> V_13 . V_14 . V_85 != 0 ) {
V_79 -> V_68 = V_2 ;
F_2 ( & V_2 -> V_49 , V_5 ) ;
F_41 ( & V_79 -> V_50 , & V_2 -> V_50 ) ;
V_2 -> V_73 ++ ;
F_5 ( & V_2 -> V_49 , V_5 ) ;
} else {
F_43 ( & V_6 . V_86 ) ;
goto V_87;
}
}
V_81 = F_9 ( V_79 ) ;
F_44 ( V_79 , V_81 ) ;
if ( V_79 -> V_71 != F_31 () ) {
F_32 () ;
F_33 ( V_79 -> V_71 ,
F_21 ,
V_79 , true ) ;
} else {
F_21 ( V_79 ) ;
F_32 () ;
}
V_79 -> V_88 = V_89 ;
if ( ! V_80 ) {
if ( V_2 -> V_90 != NULL )
V_2 -> V_90 ( V_79 ) ;
F_43 ( & V_6 . V_86 ) ;
return;
}
V_79 -> V_78 = F_45 (
& V_79 -> V_13 . V_14 . V_15 ,
& V_79 -> V_13 . V_14 . V_83 ,
V_79 ) ;
if ( ! V_79 -> V_78 )
goto V_91;
V_79 -> V_78 -> V_92 = V_81 ;
V_82 = F_46 ( V_79 -> V_78 ) ;
if ( V_82 != 0 ) {
F_47 ( L_2 ,
V_79 -> V_13 . V_64 ) ;
F_48 ( V_79 -> V_78 ) ;
goto V_91;
}
F_43 ( & V_6 . V_86 ) ;
return;
V_91:
F_40 ( & V_6 . V_70 ) ;
F_34 ( & V_79 -> V_72 ) ;
F_42 ( & V_6 . V_70 ) ;
if ( V_79 -> V_71 != F_31 () ) {
F_32 () ;
F_33 ( V_79 -> V_71 ,
F_24 , V_79 , true ) ;
} else {
F_24 ( V_79 ) ;
F_32 () ;
}
F_26 ( V_79 -> V_13 . V_64 ) ;
V_87:
F_18 ( V_79 ) ;
}
static void F_44 ( struct V_1 * V_2 , T_2 V_81 )
{
T_4 V_93 ;
bool V_94 = V_18 [ V_81 ] . V_95 ;
struct V_1 * V_96 = V_2 -> V_68 ;
int V_97 ;
struct V_98 V_99 ;
struct V_98 * V_100 ;
if ( ( V_101 == V_102 ) ||
( V_101 == V_103 ) || ( ! V_94 ) ) {
V_2 -> V_104 = 0 ;
V_2 -> V_71 = 0 ;
V_2 -> V_105 = V_58 . V_106 [ 0 ] ;
return;
}
if ( ( V_2 -> V_74 == V_107 ) || ( ! V_96 ) ) {
while ( true ) {
V_97 = V_108 ++ ;
if ( V_97 == V_109 ) {
V_97 = V_108 = 0 ;
continue;
}
if ( F_49 ( F_50 ( V_97 ) ) )
continue;
break;
}
V_2 -> V_104 = V_97 ;
V_96 = V_2 ;
}
V_100 = & V_58 . V_110 [ V_96 -> V_104 ] ;
if ( F_51 ( V_100 ) ==
F_51 ( F_50 ( V_96 -> V_104 ) ) ) {
F_52 ( V_100 ) ;
}
F_53 ( & V_99 , V_100 ,
F_50 ( V_96 -> V_104 ) ) ;
V_93 = - 1 ;
if ( V_96 -> V_74 == V_75 ) {
if ( F_54 ( & V_96 -> V_76 ,
F_50 ( V_96 -> V_104 ) ) )
F_52 ( & V_96 -> V_76 ) ;
}
while ( true ) {
V_93 = F_55 ( V_93 , & V_99 ) ;
if ( V_93 >= V_111 ) {
V_93 = - 1 ;
F_56 ( & V_99 ,
F_50 ( V_96 -> V_104 ) ) ;
continue;
}
if ( V_96 -> V_74 == V_75 ) {
if ( ! F_57 ( V_93 ,
& V_96 -> V_76 ) ) {
F_58 ( V_93 ,
& V_96 -> V_76 ) ;
F_58 ( V_93 , V_100 ) ;
break;
}
} else {
F_58 ( V_93 , V_100 ) ;
break;
}
}
V_2 -> V_71 = V_93 ;
V_2 -> V_105 = V_58 . V_106 [ V_93 ] ;
}
static void F_59 ( void )
{
int V_112 ;
void * V_113 ;
struct V_114 * V_63 ;
struct V_115 * V_116 ;
T_4 V_117 ;
while ( 1 ) {
if ( F_60 ( & V_6 . V_118 ) )
break;
F_61 (cpu) {
struct V_56 * V_57
= F_62 ( V_58 . V_59 , V_112 ) ;
V_113 = V_57 -> V_119 ;
V_63 = (struct V_114 * ) V_113
+ V_120 ;
V_117 = F_63 ( V_63 -> V_65 . V_117 ) ;
if ( V_117 == V_121 )
continue;
V_116 = (struct V_115 * )
V_63 -> V_122 . V_123 ;
if ( V_116 -> V_66 == V_124 )
F_4 ( & V_6 . V_118 ) ;
F_64 ( V_63 , V_117 ) ;
}
F_65 ( 10 ) ;
}
F_61 (cpu) {
struct V_56 * V_57
= F_62 ( V_58 . V_59 , V_112 ) ;
V_113 = V_57 -> V_119 ;
V_63 = (struct V_114 * ) V_113 + V_120 ;
V_63 -> V_65 . V_117 = V_121 ;
}
}
static void F_66 ( struct V_115 * V_116 )
{
F_4 ( & V_6 . V_118 ) ;
}
void F_67 ( bool V_125 )
{
struct V_115 V_116 ;
if ( V_101 < V_126 )
return;
F_68 ( & V_6 . V_118 ) ;
memset ( & V_116 , 0 , sizeof( struct V_115 ) ) ;
V_116 . V_66 = V_127 ;
F_27 ( & V_116 , sizeof( struct V_115 ) ,
! V_125 ) ;
if ( ! V_125 )
F_69 ( & V_6 . V_118 ) ;
else
F_59 () ;
}
static void F_70 ( struct V_115 * V_116 )
{
struct V_128 * V_14 ;
struct V_1 * V_79 ;
V_14 = (struct V_128 * ) V_116 ;
V_79 = F_13 () ;
if ( ! V_79 ) {
F_26 ( V_14 -> V_64 ) ;
F_43 ( & V_6 . V_86 ) ;
F_47 ( L_3 ) ;
return;
}
V_79 -> V_129 = (struct V_130 * )
( F_71 ( ( unsigned long )
& V_79 -> V_131 ,
V_132 ) ) ;
V_79 -> V_129 -> V_133 . V_134 = 0 ;
V_79 -> V_129 -> V_133 . V_122 . V_135 = V_136 ;
V_79 -> V_129 -> V_137 = 0 ;
V_79 -> V_129 -> V_138 = 0 ;
if ( V_101 != V_102 ) {
V_79 -> V_139 =
( V_14 -> V_139 != 0 ) ;
V_79 -> V_129 -> V_133 . V_122 . V_135 =
V_14 -> V_140 ;
}
memcpy ( & V_79 -> V_13 , V_14 ,
sizeof( struct V_128 ) ) ;
V_79 -> V_141 = ( T_3 ) V_14 -> V_142 / 32 ;
V_79 -> V_143 = ( T_3 ) V_14 -> V_142 % 32 ;
F_39 ( V_79 ) ;
}
static void F_72 ( struct V_115 * V_116 )
{
struct V_144 * V_69 ;
struct V_1 * V_2 ;
unsigned long V_5 ;
struct V_145 * V_146 ;
V_69 = (struct V_144 * ) V_116 ;
while ( F_73 ( & V_6 . V_86 ) != 0 ) {
F_74 ( 1 ) ;
}
F_40 ( & V_6 . V_70 ) ;
V_2 = F_75 ( V_69 -> V_64 ) ;
F_42 ( & V_6 . V_70 ) ;
if ( V_2 == NULL ) {
return;
}
F_2 ( & V_2 -> V_49 , V_5 ) ;
V_2 -> V_69 = true ;
F_5 ( & V_2 -> V_49 , V_5 ) ;
F_1 ( V_2 ) ;
if ( V_2 -> V_78 ) {
if ( V_2 -> V_147 ) {
V_2 -> V_147 ( V_2 ) ;
return;
}
V_146 = F_76 ( & V_2 -> V_78 -> V_145 ) ;
if ( V_146 ) {
F_38 ( V_2 -> V_78 ) ;
F_77 ( V_146 ) ;
}
}
if ( V_2 -> V_68 != NULL ) {
if ( V_2 -> V_88 == V_89 ) {
F_40 ( & V_6 . V_70 ) ;
F_28 ( V_2 ,
V_2 -> V_13 . V_64 ) ;
F_42 ( & V_6 . V_70 ) ;
}
}
}
void F_78 ( struct V_1 * V_2 )
{
F_40 ( & V_6 . V_70 ) ;
F_29 ( ! F_10 ( V_2 ) ) ;
V_2 -> V_69 = true ;
F_38 ( V_2 -> V_78 ) ;
F_42 ( & V_6 . V_70 ) ;
}
static void F_79 (
struct V_115 * V_116 )
{
}
static void F_80 ( struct V_115 * V_116 )
{
struct V_148 * V_149 ;
struct V_3 * V_4 ;
struct V_115 * V_150 ;
struct V_151 * V_152 ;
unsigned long V_5 ;
V_149 = (struct V_148 * ) V_116 ;
F_2 ( & V_6 . V_7 , V_5 ) ;
F_3 (msginfo, &vmbus_connection.chn_msg_list,
msglistentry) {
V_150 =
(struct V_115 * ) V_4 -> V_63 ;
if ( V_150 -> V_66 == V_153 ) {
V_152 =
(struct V_151 * ) V_4 -> V_63 ;
if ( V_152 -> V_64 == V_149 -> V_64 &&
V_152 -> V_154 == V_149 -> V_154 ) {
memcpy ( & V_4 -> V_155 . V_156 ,
V_149 ,
sizeof(
struct V_148 ) ) ;
F_4 ( & V_4 -> V_9 ) ;
break;
}
}
}
F_5 ( & V_6 . V_7 , V_5 ) ;
}
static void F_81 ( struct V_115 * V_116 )
{
struct V_157 * V_158 ;
struct V_3 * V_4 ;
struct V_115 * V_150 ;
struct V_159 * V_160 ;
unsigned long V_5 ;
V_158 = (struct V_157 * ) V_116 ;
F_2 ( & V_6 . V_7 , V_5 ) ;
F_3 (msginfo, &vmbus_connection.chn_msg_list,
msglistentry) {
V_150 =
(struct V_115 * ) V_4 -> V_63 ;
if ( V_150 -> V_66 == V_161 ) {
V_160 =
(struct V_159 * ) V_150 ;
if ( ( V_158 -> V_64 ==
V_160 -> V_64 ) &&
( V_158 -> V_162 == V_160 -> V_162 ) ) {
memcpy ( & V_4 -> V_155 . V_163 ,
V_158 ,
sizeof(
struct V_157 ) ) ;
F_4 ( & V_4 -> V_9 ) ;
break;
}
}
}
F_5 ( & V_6 . V_7 , V_5 ) ;
}
static void F_82 (
struct V_115 * V_116 )
{
struct V_164 * V_165 ;
struct V_3 * V_4 ;
struct V_115 * V_150 ;
struct V_166 * V_167 ;
unsigned long V_5 ;
V_165 = (struct V_164 * ) V_116 ;
F_2 ( & V_6 . V_7 , V_5 ) ;
F_3 (msginfo, &vmbus_connection.chn_msg_list,
msglistentry) {
V_150 =
(struct V_115 * ) V_4 -> V_63 ;
if ( V_150 -> V_66 == V_168 ) {
V_167 =
(struct V_166 * ) V_150 ;
if ( V_165 -> V_162 == V_167 -> V_162 ) {
memcpy ( & V_4 -> V_155 . V_165 ,
V_165 ,
sizeof(
struct V_164 ) ) ;
F_4 ( & V_4 -> V_9 ) ;
break;
}
}
}
F_5 ( & V_6 . V_7 , V_5 ) ;
}
static void F_83 (
struct V_115 * V_116 )
{
struct V_3 * V_4 ;
struct V_115 * V_150 ;
struct V_169 * V_170 ;
unsigned long V_5 ;
V_170 = (struct V_169 * ) V_116 ;
F_2 ( & V_6 . V_7 , V_5 ) ;
F_3 (msginfo, &vmbus_connection.chn_msg_list,
msglistentry) {
V_150 =
(struct V_115 * ) V_4 -> V_63 ;
if ( V_150 -> V_66 ==
V_171 ) {
memcpy ( & V_4 -> V_155 . V_170 ,
V_170 ,
sizeof( struct V_169 ) ) ;
F_4 ( & V_4 -> V_9 ) ;
}
}
F_5 ( & V_6 . V_7 , V_5 ) ;
}
void F_84 ( void * V_172 )
{
struct V_114 * V_63 = V_172 ;
struct V_115 * V_116 ;
int V_173 ;
V_116 = (struct V_115 * ) V_63 -> V_122 . V_123 ;
V_173 = V_63 -> V_65 . V_174 ;
if ( V_116 -> V_66 >= V_175 ) {
F_47 ( L_4 ,
V_116 -> V_66 , V_173 ) ;
F_85 ( L_5 , V_176 ,
( unsigned char * ) V_63 -> V_122 . V_123 , V_173 ) ;
return;
}
if ( V_177 [ V_116 -> V_66 ] . V_178 )
V_177 [ V_116 -> V_66 ] . V_178 ( V_116 ) ;
else
F_47 ( L_6 , V_116 -> V_66 ) ;
}
int F_86 ( void )
{
struct V_115 * V_63 ;
struct V_3 * V_4 ;
int V_82 ;
V_4 = F_87 ( sizeof( * V_4 ) +
sizeof( struct V_115 ) ,
V_179 ) ;
if ( ! V_4 )
return - V_180 ;
V_63 = (struct V_115 * ) V_4 -> V_63 ;
V_63 -> V_66 = V_181 ;
V_82 = F_27 ( V_63 , sizeof( struct V_115 ) ,
true ) ;
if ( V_82 != 0 ) {
F_47 ( L_7 , V_82 ) ;
goto V_182;
}
V_182:
F_48 ( V_4 ) ;
return V_82 ;
}
struct V_1 * F_88 ( struct V_1 * V_96 )
{
struct V_183 * V_184 , * V_77 ;
int V_93 ;
struct V_1 * V_185 ;
struct V_1 * V_186 = V_96 ;
int V_187 ;
int V_11 = 1 ;
if ( F_89 ( & V_96 -> V_50 ) )
return V_186 ;
V_187 = V_96 -> V_188 ++ ;
if ( V_187 > ( V_96 -> V_73 ) ) {
V_96 -> V_188 = 0 ;
return V_186 ;
}
V_93 = V_58 . V_106 [ F_31 () ] ;
F_32 () ;
F_90 (cur, tmp, &primary->sc_list) {
V_185 = F_91 ( V_184 , struct V_1 , V_50 ) ;
if ( V_185 -> V_88 != V_189 )
continue;
if ( V_185 -> V_105 == V_93 )
return V_185 ;
if ( V_11 == V_187 )
return V_185 ;
V_11 ++ ;
}
return V_186 ;
}
static void F_92 ( struct V_1 * V_68 )
{
struct V_183 * V_184 , * V_77 ;
struct V_1 * V_185 ;
if ( V_68 -> V_90 == NULL )
return;
F_90 (cur, tmp, &primary_channel->sc_list) {
V_185 = F_91 ( V_184 , struct V_1 , V_50 ) ;
V_68 -> V_90 ( V_185 ) ;
}
}
void F_93 ( struct V_1 * V_68 ,
void (* F_94)( struct V_1 * V_190 ) )
{
V_68 -> V_90 = F_94 ;
}
bool F_95 ( struct V_1 * V_96 )
{
bool V_82 ;
V_82 = ! F_89 ( & V_96 -> V_50 ) ;
if ( V_82 ) {
F_92 ( V_96 ) ;
}
return V_82 ;
}
void F_96 ( struct V_1 * V_2 ,
void (* F_97)( struct V_1 * ) )
{
V_2 -> V_147 = F_97 ;
}
