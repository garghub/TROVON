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
void F_28 ( struct V_1 * V_2 , T_4 V_62 )
{
unsigned long V_5 ;
struct V_1 * V_69 ;
F_29 ( ! V_2 -> V_70 ) ;
F_29 ( ! F_30 ( & V_6 . V_71 ) ) ;
if ( V_2 -> V_72 != F_31 () ) {
F_32 () ;
F_33 ( V_2 -> V_72 ,
F_24 , V_2 , true ) ;
} else {
F_24 ( V_2 ) ;
F_32 () ;
}
if ( V_2 -> V_69 == NULL ) {
F_34 ( & V_2 -> V_73 ) ;
V_69 = V_2 ;
} else {
V_69 = V_2 -> V_69 ;
F_2 ( & V_69 -> V_50 , V_5 ) ;
F_34 ( & V_2 -> V_51 ) ;
V_69 -> V_74 -- ;
F_5 ( & V_69 -> V_50 , V_5 ) ;
}
if ( V_2 -> V_75 == V_76 )
F_35 ( V_2 -> V_72 ,
& V_69 -> V_77 ) ;
F_26 ( V_62 ) ;
F_18 ( V_2 ) ;
}
void F_36 ( void )
{
struct V_1 * V_2 , * V_78 ;
F_37 ( & V_6 . V_71 ) ;
F_38 (channel, tmp, &vmbus_connection.chn_list,
listentry) {
V_2 -> V_70 = true ;
F_39 ( V_2 -> V_79 ) ;
}
F_40 ( & V_6 . V_71 ) ;
}
static void F_41 ( struct V_1 * V_80 )
{
struct V_1 * V_2 ;
bool V_81 = true ;
unsigned long V_5 ;
T_2 V_82 ;
int V_83 ;
F_37 ( & V_6 . V_71 ) ;
F_3 (channel, &vmbus_connection.chn_list, listentry) {
if ( ! F_8 ( V_2 -> V_13 . V_14 . V_15 ,
V_80 -> V_13 . V_14 . V_15 ) &&
! F_8 ( V_2 -> V_13 . V_14 . V_84 ,
V_80 -> V_13 . V_14 . V_84 ) ) {
V_81 = false ;
break;
}
}
if ( V_81 )
F_42 ( & V_80 -> V_73 ,
& V_6 . V_85 ) ;
F_40 ( & V_6 . V_71 ) ;
if ( ! V_81 ) {
if ( V_80 -> V_13 . V_14 . V_86 != 0 ) {
V_80 -> V_69 = V_2 ;
F_2 ( & V_2 -> V_50 , V_5 ) ;
F_42 ( & V_80 -> V_51 , & V_2 -> V_51 ) ;
V_2 -> V_74 ++ ;
F_5 ( & V_2 -> V_50 , V_5 ) ;
} else
goto V_87;
}
V_82 = F_9 ( V_80 ) ;
F_43 ( V_80 , V_82 ) ;
if ( V_80 -> V_72 != F_31 () ) {
F_32 () ;
F_33 ( V_80 -> V_72 ,
F_21 ,
V_80 , true ) ;
} else {
F_21 ( V_80 ) ;
F_32 () ;
}
V_80 -> V_88 = V_89 ;
if ( ! V_81 ) {
if ( V_2 -> V_90 != NULL )
V_2 -> V_90 ( V_80 ) ;
return;
}
V_80 -> V_79 = F_44 (
& V_80 -> V_13 . V_14 . V_15 ,
& V_80 -> V_13 . V_14 . V_84 ,
V_80 ) ;
if ( ! V_80 -> V_79 )
goto V_91;
V_80 -> V_79 -> V_92 = V_82 ;
F_37 ( & V_6 . V_71 ) ;
V_83 = F_45 ( V_80 -> V_79 ) ;
F_40 ( & V_6 . V_71 ) ;
if ( V_83 != 0 ) {
F_46 ( L_2 ,
V_80 -> V_13 . V_65 ) ;
F_47 ( V_80 -> V_79 ) ;
goto V_91;
}
return;
V_91:
F_37 ( & V_6 . V_71 ) ;
F_34 ( & V_80 -> V_73 ) ;
F_40 ( & V_6 . V_71 ) ;
if ( V_80 -> V_72 != F_31 () ) {
F_32 () ;
F_33 ( V_80 -> V_72 ,
F_24 , V_80 , true ) ;
} else {
F_24 ( V_80 ) ;
F_32 () ;
}
F_26 ( V_80 -> V_13 . V_65 ) ;
V_87:
F_18 ( V_80 ) ;
}
static void F_43 ( struct V_1 * V_2 , T_2 V_82 )
{
T_4 V_93 ;
bool V_94 = V_18 [ V_82 ] . V_95 ;
struct V_1 * V_96 = V_2 -> V_69 ;
int V_97 ;
struct V_98 V_99 ;
struct V_98 * V_100 ;
if ( ( V_101 == V_102 ) ||
( V_101 == V_103 ) || ( ! V_94 ) ) {
V_2 -> V_104 = 0 ;
V_2 -> V_72 = 0 ;
V_2 -> V_105 = V_59 . V_106 [ 0 ] ;
return;
}
if ( ( V_2 -> V_75 == V_107 ) || ( ! V_96 ) ) {
while ( true ) {
V_97 = V_108 ++ ;
if ( V_97 == V_109 ) {
V_97 = V_108 = 0 ;
continue;
}
if ( F_48 ( F_49 ( V_97 ) ) )
continue;
break;
}
V_2 -> V_104 = V_97 ;
V_96 = V_2 ;
}
V_100 = & V_59 . V_110 [ V_96 -> V_104 ] ;
if ( F_50 ( V_100 ) ==
F_50 ( F_49 ( V_96 -> V_104 ) ) ) {
F_51 ( V_100 ) ;
}
F_52 ( & V_99 , V_100 ,
F_49 ( V_96 -> V_104 ) ) ;
V_93 = - 1 ;
if ( V_96 -> V_75 == V_76 ) {
if ( F_53 ( & V_96 -> V_77 ,
F_49 ( V_96 -> V_104 ) ) )
F_51 ( & V_96 -> V_77 ) ;
}
while ( true ) {
V_93 = F_54 ( V_93 , & V_99 ) ;
if ( V_93 >= V_111 ) {
V_93 = - 1 ;
F_55 ( & V_99 ,
F_49 ( V_96 -> V_104 ) ) ;
continue;
}
if ( V_96 -> V_75 == V_76 ) {
if ( ! F_56 ( V_93 ,
& V_96 -> V_77 ) ) {
F_57 ( V_93 ,
& V_96 -> V_77 ) ;
F_57 ( V_93 , V_100 ) ;
break;
}
} else {
F_57 ( V_93 , V_100 ) ;
break;
}
}
V_2 -> V_72 = V_93 ;
V_2 -> V_105 = V_59 . V_106 [ V_93 ] ;
}
static void F_58 ( void )
{
int V_112 ;
void * V_113 ;
struct V_114 * V_64 ;
struct V_115 * V_116 ;
T_4 V_117 ;
while ( 1 ) {
if ( F_59 ( & V_6 . V_118 ) )
break;
F_60 (cpu) {
struct V_57 * V_58
= F_61 ( V_59 . V_60 , V_112 ) ;
V_113 = V_58 -> V_119 ;
V_64 = (struct V_114 * ) V_113
+ V_120 ;
V_117 = F_62 ( V_64 -> V_66 . V_117 ) ;
if ( V_117 == V_121 )
continue;
V_116 = (struct V_115 * )
V_64 -> V_122 . V_123 ;
if ( V_116 -> V_67 == V_124 )
F_4 ( & V_6 . V_118 ) ;
F_63 ( V_64 , V_117 ) ;
}
F_64 ( 10 ) ;
}
F_60 (cpu) {
struct V_57 * V_58
= F_61 ( V_59 . V_60 , V_112 ) ;
V_113 = V_58 -> V_119 ;
V_64 = (struct V_114 * ) V_113 + V_120 ;
V_64 -> V_66 . V_117 = V_121 ;
}
}
static void F_65 ( struct V_115 * V_116 )
{
F_4 ( & V_6 . V_118 ) ;
}
void F_66 ( bool V_125 )
{
struct V_115 V_116 ;
if ( V_101 < V_126 )
return;
F_67 ( & V_6 . V_118 ) ;
memset ( & V_116 , 0 , sizeof( struct V_115 ) ) ;
V_116 . V_67 = V_127 ;
F_27 ( & V_116 , sizeof( struct V_115 ) ,
! V_125 ) ;
if ( ! V_125 )
F_68 ( & V_6 . V_118 ) ;
else
F_58 () ;
}
static void F_69 ( struct V_115 * V_116 )
{
struct V_128 * V_14 ;
struct V_1 * V_80 ;
V_14 = (struct V_128 * ) V_116 ;
V_80 = F_13 () ;
if ( ! V_80 ) {
F_26 ( V_14 -> V_65 ) ;
F_46 ( L_3 ) ;
return;
}
V_80 -> V_129 = (struct V_130 * )
( F_70 ( ( unsigned long )
& V_80 -> V_131 ,
V_132 ) ) ;
V_80 -> V_129 -> V_133 . V_134 = 0 ;
V_80 -> V_129 -> V_133 . V_122 . V_135 = V_136 ;
V_80 -> V_129 -> V_137 = 0 ;
V_80 -> V_129 -> V_138 = 0 ;
if ( V_101 != V_102 ) {
V_80 -> V_139 =
( V_14 -> V_139 != 0 ) ;
V_80 -> V_129 -> V_133 . V_122 . V_135 =
V_14 -> V_140 ;
}
memcpy ( & V_80 -> V_13 , V_14 ,
sizeof( struct V_128 ) ) ;
V_80 -> V_141 = ( T_3 ) V_14 -> V_142 / 32 ;
V_80 -> V_143 = ( T_3 ) V_14 -> V_142 % 32 ;
F_41 ( V_80 ) ;
}
static void F_71 ( struct V_115 * V_116 )
{
struct V_144 * V_70 ;
struct V_1 * V_2 ;
unsigned long V_5 ;
struct V_145 * V_146 ;
V_70 = (struct V_144 * ) V_116 ;
F_37 ( & V_6 . V_71 ) ;
V_2 = F_72 ( V_70 -> V_65 ) ;
if ( V_2 == NULL ) {
goto V_147;
}
F_2 ( & V_2 -> V_50 , V_5 ) ;
V_2 -> V_70 = true ;
F_5 ( & V_2 -> V_50 , V_5 ) ;
F_1 ( V_2 ) ;
if ( V_2 -> V_79 ) {
if ( V_2 -> V_148 ) {
V_2 -> V_148 ( V_2 ) ;
goto V_147;
}
V_146 = F_73 ( & V_2 -> V_79 -> V_145 ) ;
if ( V_146 ) {
F_39 ( V_2 -> V_79 ) ;
F_74 ( V_146 ) ;
}
} else {
F_28 ( V_2 ,
V_2 -> V_13 . V_65 ) ;
}
V_147:
F_40 ( & V_6 . V_71 ) ;
}
void F_75 ( struct V_1 * V_2 )
{
F_37 ( & V_6 . V_71 ) ;
F_29 ( ! F_10 ( V_2 ) ) ;
V_2 -> V_70 = true ;
F_39 ( V_2 -> V_79 ) ;
F_40 ( & V_6 . V_71 ) ;
}
static void F_76 (
struct V_115 * V_116 )
{
}
static void F_77 ( struct V_115 * V_116 )
{
struct V_149 * V_150 ;
struct V_3 * V_4 ;
struct V_115 * V_151 ;
struct V_152 * V_153 ;
unsigned long V_5 ;
V_150 = (struct V_149 * ) V_116 ;
F_2 ( & V_6 . V_7 , V_5 ) ;
F_3 (msginfo, &vmbus_connection.chn_msg_list,
msglistentry) {
V_151 =
(struct V_115 * ) V_4 -> V_64 ;
if ( V_151 -> V_67 == V_154 ) {
V_153 =
(struct V_152 * ) V_4 -> V_64 ;
if ( V_153 -> V_65 == V_150 -> V_65 &&
V_153 -> V_155 == V_150 -> V_155 ) {
memcpy ( & V_4 -> V_156 . V_157 ,
V_150 ,
sizeof(
struct V_149 ) ) ;
F_4 ( & V_4 -> V_9 ) ;
break;
}
}
}
F_5 ( & V_6 . V_7 , V_5 ) ;
}
static void F_78 ( struct V_115 * V_116 )
{
struct V_158 * V_159 ;
struct V_3 * V_4 ;
struct V_115 * V_151 ;
struct V_160 * V_161 ;
unsigned long V_5 ;
V_159 = (struct V_158 * ) V_116 ;
F_2 ( & V_6 . V_7 , V_5 ) ;
F_3 (msginfo, &vmbus_connection.chn_msg_list,
msglistentry) {
V_151 =
(struct V_115 * ) V_4 -> V_64 ;
if ( V_151 -> V_67 == V_162 ) {
V_161 =
(struct V_160 * ) V_151 ;
if ( ( V_159 -> V_65 ==
V_161 -> V_65 ) &&
( V_159 -> V_163 == V_161 -> V_163 ) ) {
memcpy ( & V_4 -> V_156 . V_164 ,
V_159 ,
sizeof(
struct V_158 ) ) ;
F_4 ( & V_4 -> V_9 ) ;
break;
}
}
}
F_5 ( & V_6 . V_7 , V_5 ) ;
}
static void F_79 (
struct V_115 * V_116 )
{
struct V_165 * V_166 ;
struct V_3 * V_4 ;
struct V_115 * V_151 ;
struct V_167 * V_168 ;
unsigned long V_5 ;
V_166 = (struct V_165 * ) V_116 ;
F_2 ( & V_6 . V_7 , V_5 ) ;
F_3 (msginfo, &vmbus_connection.chn_msg_list,
msglistentry) {
V_151 =
(struct V_115 * ) V_4 -> V_64 ;
if ( V_151 -> V_67 == V_169 ) {
V_168 =
(struct V_167 * ) V_151 ;
if ( V_166 -> V_163 == V_168 -> V_163 ) {
memcpy ( & V_4 -> V_156 . V_166 ,
V_166 ,
sizeof(
struct V_165 ) ) ;
F_4 ( & V_4 -> V_9 ) ;
break;
}
}
}
F_5 ( & V_6 . V_7 , V_5 ) ;
}
static void F_80 (
struct V_115 * V_116 )
{
struct V_3 * V_4 ;
struct V_115 * V_151 ;
struct V_170 * V_171 ;
unsigned long V_5 ;
V_171 = (struct V_170 * ) V_116 ;
F_2 ( & V_6 . V_7 , V_5 ) ;
F_3 (msginfo, &vmbus_connection.chn_msg_list,
msglistentry) {
V_151 =
(struct V_115 * ) V_4 -> V_64 ;
if ( V_151 -> V_67 ==
V_172 ) {
memcpy ( & V_4 -> V_156 . V_171 ,
V_171 ,
sizeof( struct V_170 ) ) ;
F_4 ( & V_4 -> V_9 ) ;
}
}
F_5 ( & V_6 . V_7 , V_5 ) ;
}
void F_81 ( void * V_173 )
{
struct V_114 * V_64 = V_173 ;
struct V_115 * V_116 ;
int V_174 ;
V_116 = (struct V_115 * ) V_64 -> V_122 . V_123 ;
V_174 = V_64 -> V_66 . V_175 ;
if ( V_116 -> V_67 >= V_176 ) {
F_46 ( L_4 ,
V_116 -> V_67 , V_174 ) ;
F_82 ( L_5 , V_177 ,
( unsigned char * ) V_64 -> V_122 . V_123 , V_174 ) ;
return;
}
if ( V_178 [ V_116 -> V_67 ] . V_179 )
V_178 [ V_116 -> V_67 ] . V_179 ( V_116 ) ;
else
F_46 ( L_6 , V_116 -> V_67 ) ;
}
int F_83 ( void )
{
struct V_115 * V_64 ;
struct V_3 * V_4 ;
int V_83 ;
V_4 = F_84 ( sizeof( * V_4 ) +
sizeof( struct V_115 ) ,
V_180 ) ;
if ( ! V_4 )
return - V_181 ;
V_64 = (struct V_115 * ) V_4 -> V_64 ;
V_64 -> V_67 = V_182 ;
V_83 = F_27 ( V_64 , sizeof( struct V_115 ) ,
true ) ;
if ( V_83 != 0 ) {
F_46 ( L_7 , V_83 ) ;
goto V_183;
}
V_183:
F_47 ( V_4 ) ;
return V_83 ;
}
struct V_1 * F_85 ( struct V_1 * V_96 )
{
struct V_184 * V_185 , * V_78 ;
int V_93 ;
struct V_1 * V_186 ;
struct V_1 * V_187 = V_96 ;
int V_188 ;
int V_11 = 1 ;
if ( F_86 ( & V_96 -> V_51 ) )
return V_187 ;
V_188 = V_96 -> V_189 ++ ;
if ( V_188 > ( V_96 -> V_74 ) ) {
V_96 -> V_189 = 0 ;
return V_187 ;
}
V_93 = V_59 . V_106 [ F_31 () ] ;
F_32 () ;
F_87 (cur, tmp, &primary->sc_list) {
V_186 = F_88 ( V_185 , struct V_1 , V_51 ) ;
if ( V_186 -> V_88 != V_190 )
continue;
if ( V_186 -> V_105 == V_93 )
return V_186 ;
if ( V_11 == V_188 )
return V_186 ;
V_11 ++ ;
}
return V_187 ;
}
static void F_89 ( struct V_1 * V_69 )
{
struct V_184 * V_185 , * V_78 ;
struct V_1 * V_186 ;
if ( V_69 -> V_90 == NULL )
return;
F_87 (cur, tmp, &primary_channel->sc_list) {
V_186 = F_88 ( V_185 , struct V_1 , V_51 ) ;
V_69 -> V_90 ( V_186 ) ;
}
}
void F_90 ( struct V_1 * V_69 ,
void (* F_91)( struct V_1 * V_191 ) )
{
V_69 -> V_90 = F_91 ;
}
bool F_92 ( struct V_1 * V_96 )
{
bool V_83 ;
V_83 = ! F_86 ( & V_96 -> V_51 ) ;
if ( V_83 ) {
F_89 ( V_96 ) ;
}
return V_83 ;
}
void F_93 ( struct V_1 * V_2 ,
void (* F_94)( struct V_1 * ) )
{
V_2 -> V_148 = F_94 ;
}
