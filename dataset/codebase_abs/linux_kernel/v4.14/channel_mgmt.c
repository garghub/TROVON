static void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
unsigned long V_5 ;
F_2 ( & V_6 . V_7 , V_5 ) ;
V_2 -> V_8 = true ;
F_3 (msginfo, &vmbus_connection.chn_msg_list,
msglistentry) {
if ( V_4 -> V_9 == V_2 ) {
F_4 ( & V_4 -> V_10 ) ;
break;
}
}
F_5 ( & V_6 . V_7 , V_5 ) ;
}
static bool F_6 ( const T_1 * V_11 )
{
int V_12 ;
for ( V_12 = 0 ; V_12 < F_7 ( V_13 ) ; V_12 ++ )
if ( ! F_8 ( * V_11 , V_13 [ V_12 ] . V_11 ) )
return true ;
return false ;
}
static T_2 F_9 ( const struct V_1 * V_2 )
{
const T_1 * V_11 = & V_2 -> V_14 . V_15 . V_16 ;
T_2 V_12 ;
if ( F_10 ( V_2 ) || F_6 ( V_11 ) )
return V_17 ;
for ( V_12 = V_18 ; V_12 < V_17 ; V_12 ++ ) {
if ( ! F_8 ( * V_11 , V_19 [ V_12 ] . V_11 ) )
return V_12 ;
}
F_11 ( L_1 , V_11 ) ;
return V_12 ;
}
bool F_12 ( struct V_20 * V_21 ,
T_3 * V_22 , const int * V_23 , int V_24 ,
const int * V_25 , int V_26 ,
int * V_27 , int * V_28 )
{
int V_29 , V_30 ;
int V_31 , V_32 ;
int V_33 , V_34 ;
int V_35 , V_36 ;
int V_12 , V_37 ;
bool V_38 = false ;
struct V_39 * V_40 ;
V_21 -> V_41 = 0x10 ;
V_40 = (struct V_39 * ) & V_22 [
sizeof( struct V_42 ) +
sizeof( struct V_20 ) ] ;
V_29 = V_40 -> V_43 ;
V_30 = 0 ;
V_31 = V_40 -> V_44 ;
V_32 = 0 ;
for ( V_12 = 0 ; V_12 < V_24 ; V_12 ++ ) {
V_33 = ( V_23 [ V_12 ] >> 16 ) ;
V_34 = ( V_23 [ V_12 ] & 0xFFFF ) ;
for ( V_37 = 0 ; V_37 < V_40 -> V_43 ; V_37 ++ ) {
if ( ( V_40 -> V_45 [ V_37 ] . V_46 == V_33 ) &&
( V_40 -> V_45 [ V_37 ] . V_47 == V_34 ) ) {
V_29 = V_40 -> V_45 [ V_37 ] . V_46 ;
V_30 = V_40 -> V_45 [ V_37 ] . V_47 ;
V_38 = true ;
break;
}
}
if ( V_38 )
break;
}
if ( ! V_38 )
goto V_48;
V_38 = false ;
for ( V_12 = 0 ; V_12 < V_26 ; V_12 ++ ) {
V_35 = ( V_25 [ V_12 ] >> 16 ) ;
V_36 = ( V_25 [ V_12 ] & 0xFFFF ) ;
for ( V_37 = V_40 -> V_43 ;
( V_37 < V_40 -> V_43 + V_40 -> V_44 ) ;
V_37 ++ ) {
if ( ( V_40 -> V_45 [ V_37 ] . V_46 == V_35 ) &&
( V_40 -> V_45 [ V_37 ] . V_47 == V_36 ) ) {
V_31 = V_40 -> V_45 [ V_37 ] . V_46 ;
V_32 = V_40 -> V_45 [ V_37 ] . V_47 ;
V_38 = true ;
break;
}
}
if ( V_38 )
break;
}
V_48:
if ( ! V_38 ) {
V_40 -> V_43 = 0 ;
V_40 -> V_44 = 0 ;
} else {
V_40 -> V_43 = 1 ;
V_40 -> V_44 = 1 ;
}
if ( V_27 )
* V_27 = ( V_29 << 16 ) | V_30 ;
if ( V_28 )
* V_28 = ( V_31 << 16 ) | V_32 ;
V_40 -> V_45 [ 0 ] . V_46 = V_29 ;
V_40 -> V_45 [ 0 ] . V_47 = V_30 ;
V_40 -> V_45 [ 1 ] . V_46 = V_31 ;
V_40 -> V_45 [ 1 ] . V_47 = V_32 ;
return V_38 ;
}
static struct V_1 * F_13 ( void )
{
struct V_1 * V_2 ;
V_2 = F_14 ( sizeof( * V_2 ) , V_49 ) ;
if ( ! V_2 )
return NULL ;
F_15 ( & V_2 -> V_50 ) ;
F_16 ( & V_2 -> V_51 ) ;
F_16 ( & V_2 -> V_52 ) ;
F_17 ( & V_2 -> V_53 ,
V_54 , ( unsigned long ) V_2 ) ;
return V_2 ;
}
static void F_18 ( struct V_1 * V_2 )
{
F_19 ( & V_2 -> V_53 ) ;
F_20 ( V_2 , V_55 ) ;
}
static void F_21 ( void * V_56 )
{
struct V_1 * V_2 = V_56 ;
struct V_57 * V_58
= F_22 ( V_59 . V_60 ) ;
F_23 ( & V_2 -> V_52 , & V_58 -> V_61 ) ;
}
static void F_24 ( void * V_56 )
{
struct V_1 * V_2 = V_56 ;
F_25 ( & V_2 -> V_52 ) ;
}
static void F_26 ( T_4 V_62 )
{
struct V_63 V_64 ;
memset ( & V_64 , 0 , sizeof( struct V_63 ) ) ;
V_64 . V_65 = V_62 ;
V_64 . V_66 . V_67 = V_68 ;
F_27 ( & V_64 , sizeof( struct V_63 ) ,
true ) ;
}
void F_28 ( T_4 V_62 )
{
unsigned long V_5 ;
struct V_1 * V_69 , * V_2 ;
F_29 ( ! F_30 ( & V_6 . V_70 ) ) ;
V_2 = F_31 ( V_62 ) ;
if ( ! V_2 )
return;
F_29 ( ! V_2 -> V_8 ) ;
if ( V_2 -> V_71 != F_32 () ) {
F_33 () ;
F_34 ( V_2 -> V_71 ,
F_24 , V_2 , true ) ;
} else {
F_24 ( V_2 ) ;
F_33 () ;
}
if ( V_2 -> V_69 == NULL ) {
F_35 ( & V_2 -> V_72 ) ;
V_69 = V_2 ;
} else {
V_69 = V_2 -> V_69 ;
F_2 ( & V_69 -> V_50 , V_5 ) ;
F_35 ( & V_2 -> V_51 ) ;
V_69 -> V_73 -- ;
F_5 ( & V_69 -> V_50 , V_5 ) ;
}
if ( V_2 -> V_74 == V_75 )
F_36 ( V_2 -> V_71 ,
& V_69 -> V_76 ) ;
F_26 ( V_62 ) ;
F_18 ( V_2 ) ;
}
void F_37 ( void )
{
struct V_1 * V_2 , * V_77 ;
F_38 (channel, tmp, &vmbus_connection.chn_list,
listentry) {
V_2 -> V_8 = true ;
F_39 ( V_2 -> V_78 ) ;
}
}
static void F_40 ( struct V_1 * V_79 )
{
struct V_1 * V_2 ;
bool V_80 = true ;
unsigned long V_5 ;
T_2 V_81 ;
int V_82 ;
F_41 ( & V_6 . V_70 ) ;
F_42 ( & V_6 . V_83 ) ;
F_3 (channel, &vmbus_connection.chn_list, listentry) {
if ( ! F_8 ( V_2 -> V_14 . V_15 . V_16 ,
V_79 -> V_14 . V_15 . V_16 ) &&
! F_8 ( V_2 -> V_14 . V_15 . V_84 ,
V_79 -> V_14 . V_15 . V_84 ) ) {
V_80 = false ;
break;
}
}
if ( V_80 )
F_43 ( & V_79 -> V_72 ,
& V_6 . V_85 ) ;
F_44 ( & V_6 . V_70 ) ;
if ( ! V_80 ) {
if ( V_79 -> V_14 . V_15 . V_86 != 0 ) {
V_79 -> V_69 = V_2 ;
F_2 ( & V_2 -> V_50 , V_5 ) ;
F_43 ( & V_79 -> V_51 , & V_2 -> V_51 ) ;
V_2 -> V_73 ++ ;
F_5 ( & V_2 -> V_50 , V_5 ) ;
} else {
goto V_87;
}
}
V_81 = F_9 ( V_79 ) ;
F_45 ( V_79 , V_81 ) ;
if ( V_79 -> V_71 != F_32 () ) {
F_33 () ;
F_34 ( V_79 -> V_71 ,
F_21 ,
V_79 , true ) ;
} else {
F_21 ( V_79 ) ;
F_33 () ;
}
V_79 -> V_88 = V_89 ;
if ( ! V_80 ) {
if ( V_2 -> V_90 != NULL )
V_2 -> V_90 ( V_79 ) ;
V_79 -> V_91 = true ;
return;
}
V_79 -> V_78 = F_46 (
& V_79 -> V_14 . V_15 . V_16 ,
& V_79 -> V_14 . V_15 . V_84 ,
V_79 ) ;
if ( ! V_79 -> V_78 )
goto V_92;
V_79 -> V_78 -> V_93 = V_81 ;
V_82 = F_47 ( V_79 -> V_78 ) ;
if ( V_82 != 0 ) {
F_48 ( L_2 ,
V_79 -> V_14 . V_65 ) ;
F_49 ( V_79 -> V_78 ) ;
goto V_92;
}
V_79 -> V_91 = true ;
return;
V_92:
F_41 ( & V_6 . V_70 ) ;
F_35 ( & V_79 -> V_72 ) ;
F_44 ( & V_6 . V_70 ) ;
if ( V_79 -> V_71 != F_32 () ) {
F_33 () ;
F_34 ( V_79 -> V_71 ,
F_24 , V_79 , true ) ;
} else {
F_24 ( V_79 ) ;
F_33 () ;
}
F_26 ( V_79 -> V_14 . V_65 ) ;
V_87:
F_18 ( V_79 ) ;
}
static void F_45 ( struct V_1 * V_2 , T_2 V_81 )
{
T_4 V_94 ;
bool V_95 = V_19 [ V_81 ] . V_96 ;
struct V_1 * V_97 = V_2 -> V_69 ;
int V_98 ;
struct V_99 V_100 ;
struct V_99 * V_101 ;
if ( ( V_102 == V_103 ) ||
( V_102 == V_104 ) || ( ! V_95 ) ) {
V_2 -> V_105 = 0 ;
V_2 -> V_71 = 0 ;
V_2 -> V_106 = F_50 ( 0 ) ;
return;
}
if ( ( V_2 -> V_74 == V_107 ) || ( ! V_97 ) ) {
while ( true ) {
V_98 = V_108 ++ ;
if ( V_98 == V_109 ) {
V_98 = V_108 = 0 ;
continue;
}
if ( F_51 ( F_52 ( V_98 ) ) )
continue;
break;
}
V_2 -> V_105 = V_98 ;
V_97 = V_2 ;
}
V_101 = & V_59 . V_110 [ V_97 -> V_105 ] ;
if ( F_53 ( V_101 ) ==
F_53 ( F_52 ( V_97 -> V_105 ) ) ) {
F_54 ( V_101 ) ;
}
F_55 ( & V_100 , V_101 ,
F_52 ( V_97 -> V_105 ) ) ;
V_94 = - 1 ;
if ( V_97 -> V_74 == V_75 ) {
if ( F_56 ( & V_97 -> V_76 ,
F_52 ( V_97 -> V_105 ) ) )
F_54 ( & V_97 -> V_76 ) ;
}
while ( true ) {
V_94 = F_57 ( V_94 , & V_100 ) ;
if ( V_94 >= V_111 ) {
V_94 = - 1 ;
F_58 ( & V_100 ,
F_52 ( V_97 -> V_105 ) ) ;
continue;
}
if ( V_97 -> V_74 == V_75 ) {
if ( ! F_59 ( V_94 ,
& V_97 -> V_76 ) ) {
F_60 ( V_94 ,
& V_97 -> V_76 ) ;
F_60 ( V_94 , V_101 ) ;
break;
}
} else {
F_60 ( V_94 , V_101 ) ;
break;
}
}
V_2 -> V_71 = V_94 ;
V_2 -> V_106 = F_50 ( V_94 ) ;
}
static void F_61 ( void )
{
int V_112 ;
void * V_113 ;
struct V_114 * V_64 ;
struct V_115 * V_116 ;
T_4 V_117 ;
while ( 1 ) {
if ( F_62 ( & V_6 . V_118 ) )
break;
F_63 (cpu) {
struct V_57 * V_58
= F_64 ( V_59 . V_60 , V_112 ) ;
V_113 = V_58 -> V_119 ;
V_64 = (struct V_114 * ) V_113
+ V_120 ;
V_117 = F_65 ( V_64 -> V_66 . V_117 ) ;
if ( V_117 == V_121 )
continue;
V_116 = (struct V_115 * )
V_64 -> V_122 . V_123 ;
if ( V_116 -> V_67 == V_124 )
F_4 ( & V_6 . V_118 ) ;
F_66 ( V_64 , V_117 ) ;
}
F_67 ( 10 ) ;
}
F_63 (cpu) {
struct V_57 * V_58
= F_64 ( V_59 . V_60 , V_112 ) ;
V_113 = V_58 -> V_119 ;
V_64 = (struct V_114 * ) V_113 + V_120 ;
V_64 -> V_66 . V_117 = V_121 ;
}
}
static void F_68 ( struct V_115 * V_116 )
{
F_4 ( & V_6 . V_118 ) ;
}
void F_69 ( bool V_125 )
{
struct V_115 V_116 ;
if ( V_102 < V_126 )
return;
F_70 ( & V_6 . V_118 ) ;
memset ( & V_116 , 0 , sizeof( struct V_115 ) ) ;
V_116 . V_67 = V_127 ;
F_27 ( & V_116 , sizeof( struct V_115 ) ,
! V_125 ) ;
if ( ! V_125 )
F_71 ( & V_6 . V_118 ) ;
else
F_61 () ;
}
static void F_72 ( struct V_115 * V_116 )
{
struct V_128 * V_15 ;
struct V_1 * V_79 ;
V_15 = (struct V_128 * ) V_116 ;
V_79 = F_13 () ;
if ( ! V_79 ) {
F_26 ( V_15 -> V_65 ) ;
F_42 ( & V_6 . V_83 ) ;
F_48 ( L_3 ) ;
return;
}
V_79 -> V_129 = V_130 ;
if ( V_102 != V_103 ) {
V_79 -> V_131 =
( V_15 -> V_131 != 0 ) ;
V_79 -> V_129 = V_15 -> V_132 ;
}
memcpy ( & V_79 -> V_14 , V_15 ,
sizeof( struct V_128 ) ) ;
V_79 -> V_133 = ( T_3 ) V_15 -> V_134 / 32 ;
V_79 -> V_135 = ( T_3 ) V_15 -> V_134 % 32 ;
F_40 ( V_79 ) ;
}
static void F_73 ( struct V_115 * V_116 )
{
struct V_136 * V_8 ;
struct V_1 * V_2 ;
struct V_137 * V_138 ;
V_8 = (struct V_136 * ) V_116 ;
while ( F_74 ( & V_6 . V_83 ) != 0 ) {
F_75 ( 1 ) ;
}
F_41 ( & V_6 . V_70 ) ;
V_2 = F_31 ( V_8 -> V_65 ) ;
F_44 ( & V_6 . V_70 ) ;
if ( V_2 == NULL ) {
return;
}
while ( F_65 ( V_2 -> V_91 ) == false ) {
F_75 ( 1 ) ;
}
if ( V_2 -> V_78 ) {
if ( V_2 -> V_139 ) {
V_2 -> V_139 ( V_2 ) ;
F_1 ( V_2 ) ;
return;
}
V_138 = F_76 ( & V_2 -> V_78 -> V_137 ) ;
if ( V_138 ) {
F_1 ( V_2 ) ;
F_39 ( V_2 -> V_78 ) ;
F_77 ( V_138 ) ;
}
}
if ( V_2 -> V_69 != NULL ) {
F_41 ( & V_6 . V_70 ) ;
F_1 ( V_2 ) ;
if ( V_2 -> V_88 == V_89 ) {
F_28 ( V_8 -> V_65 ) ;
}
F_44 ( & V_6 . V_70 ) ;
}
}
void F_78 ( struct V_1 * V_2 )
{
F_29 ( ! F_10 ( V_2 ) ) ;
while ( ! F_65 ( V_2 -> V_91 ) || ! F_65 ( V_2 -> V_8 ) )
F_75 ( 1 ) ;
F_39 ( V_2 -> V_78 ) ;
}
static void F_79 (
struct V_115 * V_116 )
{
}
static void F_80 ( struct V_115 * V_116 )
{
struct V_140 * V_141 ;
struct V_3 * V_4 ;
struct V_115 * V_142 ;
struct V_143 * V_144 ;
unsigned long V_5 ;
V_141 = (struct V_140 * ) V_116 ;
F_2 ( & V_6 . V_7 , V_5 ) ;
F_3 (msginfo, &vmbus_connection.chn_msg_list,
msglistentry) {
V_142 =
(struct V_115 * ) V_4 -> V_64 ;
if ( V_142 -> V_67 == V_145 ) {
V_144 =
(struct V_143 * ) V_4 -> V_64 ;
if ( V_144 -> V_65 == V_141 -> V_65 &&
V_144 -> V_146 == V_141 -> V_146 ) {
memcpy ( & V_4 -> V_147 . V_148 ,
V_141 ,
sizeof(
struct V_140 ) ) ;
F_4 ( & V_4 -> V_10 ) ;
break;
}
}
}
F_5 ( & V_6 . V_7 , V_5 ) ;
}
static void F_81 ( struct V_115 * V_116 )
{
struct V_149 * V_150 ;
struct V_3 * V_4 ;
struct V_115 * V_142 ;
struct V_151 * V_152 ;
unsigned long V_5 ;
V_150 = (struct V_149 * ) V_116 ;
F_2 ( & V_6 . V_7 , V_5 ) ;
F_3 (msginfo, &vmbus_connection.chn_msg_list,
msglistentry) {
V_142 =
(struct V_115 * ) V_4 -> V_64 ;
if ( V_142 -> V_67 == V_153 ) {
V_152 =
(struct V_151 * ) V_142 ;
if ( ( V_150 -> V_65 ==
V_152 -> V_65 ) &&
( V_150 -> V_154 == V_152 -> V_154 ) ) {
memcpy ( & V_4 -> V_147 . V_155 ,
V_150 ,
sizeof(
struct V_149 ) ) ;
F_4 ( & V_4 -> V_10 ) ;
break;
}
}
}
F_5 ( & V_6 . V_7 , V_5 ) ;
}
static void F_82 (
struct V_115 * V_116 )
{
struct V_156 * V_157 ;
struct V_3 * V_4 ;
struct V_115 * V_142 ;
struct V_158 * V_159 ;
unsigned long V_5 ;
V_157 = (struct V_156 * ) V_116 ;
F_2 ( & V_6 . V_7 , V_5 ) ;
F_3 (msginfo, &vmbus_connection.chn_msg_list,
msglistentry) {
V_142 =
(struct V_115 * ) V_4 -> V_64 ;
if ( V_142 -> V_67 == V_160 ) {
V_159 =
(struct V_158 * ) V_142 ;
if ( V_157 -> V_154 == V_159 -> V_154 ) {
memcpy ( & V_4 -> V_147 . V_157 ,
V_157 ,
sizeof(
struct V_156 ) ) ;
F_4 ( & V_4 -> V_10 ) ;
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
struct V_115 * V_142 ;
struct V_161 * V_162 ;
unsigned long V_5 ;
V_162 = (struct V_161 * ) V_116 ;
F_2 ( & V_6 . V_7 , V_5 ) ;
F_3 (msginfo, &vmbus_connection.chn_msg_list,
msglistentry) {
V_142 =
(struct V_115 * ) V_4 -> V_64 ;
if ( V_142 -> V_67 ==
V_163 ) {
memcpy ( & V_4 -> V_147 . V_162 ,
V_162 ,
sizeof( struct V_161 ) ) ;
F_4 ( & V_4 -> V_10 ) ;
}
}
F_5 ( & V_6 . V_7 , V_5 ) ;
}
void F_84 ( void * V_164 )
{
struct V_114 * V_64 = V_164 ;
struct V_115 * V_116 ;
int V_165 ;
V_116 = (struct V_115 * ) V_64 -> V_122 . V_123 ;
V_165 = V_64 -> V_66 . V_166 ;
if ( V_116 -> V_67 >= V_167 ) {
F_48 ( L_4 ,
V_116 -> V_67 , V_165 ) ;
F_85 ( L_5 , V_168 ,
( unsigned char * ) V_64 -> V_122 . V_123 , V_165 ) ;
return;
}
if ( V_169 [ V_116 -> V_67 ] . V_170 )
V_169 [ V_116 -> V_67 ] . V_170 ( V_116 ) ;
else
F_48 ( L_6 , V_116 -> V_67 ) ;
}
int F_86 ( void )
{
struct V_115 * V_64 ;
struct V_3 * V_4 ;
int V_82 ;
V_4 = F_87 ( sizeof( * V_4 ) +
sizeof( struct V_115 ) ,
V_171 ) ;
if ( ! V_4 )
return - V_172 ;
V_64 = (struct V_115 * ) V_4 -> V_64 ;
V_64 -> V_67 = V_173 ;
V_82 = F_27 ( V_64 , sizeof( struct V_115 ) ,
true ) ;
if ( V_82 != 0 ) {
F_48 ( L_7 , V_82 ) ;
goto V_174;
}
V_174:
F_49 ( V_4 ) ;
return V_82 ;
}
struct V_1 * F_88 ( struct V_1 * V_97 )
{
struct V_175 * V_176 , * V_77 ;
int V_94 ;
struct V_1 * V_177 ;
struct V_1 * V_178 = V_97 ;
int V_179 ;
int V_12 = 1 ;
if ( F_89 ( & V_97 -> V_51 ) )
return V_178 ;
V_179 = V_97 -> V_180 ++ ;
if ( V_179 > ( V_97 -> V_73 ) ) {
V_97 -> V_180 = 0 ;
return V_178 ;
}
V_94 = F_50 ( F_90 () ) ;
F_91 (cur, tmp, &primary->sc_list) {
V_177 = F_92 ( V_176 , struct V_1 , V_51 ) ;
if ( V_177 -> V_88 != V_181 )
continue;
if ( V_177 -> V_106 == V_94 )
return V_177 ;
if ( V_12 == V_179 )
return V_177 ;
V_12 ++ ;
}
return V_178 ;
}
static void F_93 ( struct V_1 * V_69 )
{
struct V_175 * V_176 , * V_77 ;
struct V_1 * V_177 ;
if ( V_69 -> V_90 == NULL )
return;
F_91 (cur, tmp, &primary_channel->sc_list) {
V_177 = F_92 ( V_176 , struct V_1 , V_51 ) ;
V_69 -> V_90 ( V_177 ) ;
}
}
void F_94 ( struct V_1 * V_69 ,
void (* F_95)( struct V_1 * V_182 ) )
{
V_69 -> V_90 = F_95 ;
}
bool F_96 ( struct V_1 * V_97 )
{
bool V_82 ;
V_82 = ! F_89 ( & V_97 -> V_51 ) ;
if ( V_82 ) {
F_93 ( V_97 ) ;
}
return V_82 ;
}
void F_97 ( struct V_1 * V_2 ,
void (* F_98)( struct V_1 * ) )
{
V_2 -> V_139 = F_98 ;
}
