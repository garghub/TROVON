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
F_36 (channel, tmp, &vmbus_connection.chn_list,
listentry) {
V_5 -> V_58 = true ;
F_37 ( V_5 -> V_67 ) ;
}
}
static void F_38 ( struct V_4 * V_68 )
{
struct V_4 * V_5 ;
bool V_69 = true ;
unsigned long V_56 ;
T_2 V_70 ;
int V_71 ;
F_39 ( & V_59 . V_60 ) ;
F_40 (channel, &vmbus_connection.chn_list, listentry) {
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
F_41 ( & V_59 . V_60 ) ;
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
if ( V_70 == V_76 )
F_42 ( V_68 , V_77 ) ;
F_43 ( V_68 , V_70 ) ;
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
V_68 -> V_78 = V_79 ;
if ( ! V_69 ) {
if ( V_5 -> V_80 != NULL )
V_5 -> V_80 ( V_68 ) ;
return;
}
V_68 -> V_67 = F_44 (
& V_68 -> V_6 . V_7 . V_8 ,
& V_68 -> V_6 . V_7 . V_72 ,
V_68 ) ;
if ( ! V_68 -> V_67 )
goto V_81;
V_68 -> V_67 -> V_82 = V_70 ;
F_39 ( & V_59 . V_60 ) ;
V_71 = F_45 ( V_68 -> V_67 ) ;
F_41 ( & V_59 . V_60 ) ;
if ( V_71 != 0 ) {
F_46 ( L_2 ,
V_68 -> V_6 . V_48 ) ;
F_13 ( V_68 -> V_67 ) ;
goto V_81;
}
return;
V_81:
F_39 ( & V_59 . V_60 ) ;
F_18 ( & V_68 -> V_61 ) ;
F_41 ( & V_59 . V_60 ) ;
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
static void F_43 ( struct V_4 * V_5 , T_2 V_70 )
{
T_4 V_83 ;
bool V_84 = V_11 [ V_70 ] . V_85 ;
struct V_4 * V_86 = V_5 -> V_57 ;
int V_87 ;
struct V_88 V_89 ;
struct V_88 * V_90 ;
if ( ( V_91 == V_92 ) ||
( V_91 == V_93 ) || ( ! V_84 ) ) {
V_5 -> V_94 = 0 ;
V_5 -> V_55 = 0 ;
V_5 -> V_95 = V_44 . V_96 [ 0 ] ;
return;
}
if ( ( V_5 -> V_63 == V_97 ) || ( ! V_86 ) ) {
while ( true ) {
V_87 = V_98 ++ ;
if ( V_87 == V_99 ) {
V_87 = V_98 = 0 ;
continue;
}
if ( F_47 ( F_48 ( V_87 ) ) )
continue;
break;
}
V_5 -> V_94 = V_87 ;
V_86 = V_5 ;
}
V_90 = & V_44 . V_100 [ V_86 -> V_94 ] ;
if ( F_49 ( V_90 ) ==
F_49 ( F_48 ( V_86 -> V_94 ) ) ) {
F_50 ( V_90 ) ;
}
F_51 ( & V_89 , V_90 ,
F_48 ( V_86 -> V_94 ) ) ;
V_83 = - 1 ;
if ( V_86 -> V_63 == V_64 ) {
if ( F_52 ( & V_86 -> V_65 ,
F_48 ( V_86 -> V_94 ) ) )
F_50 ( & V_86 -> V_65 ) ;
}
while ( true ) {
V_83 = F_53 ( V_83 , & V_89 ) ;
if ( V_83 >= V_101 ) {
V_83 = - 1 ;
F_54 ( & V_89 ,
F_48 ( V_86 -> V_94 ) ) ;
continue;
}
if ( V_86 -> V_63 == V_64 ) {
if ( ! F_55 ( V_83 ,
& V_86 -> V_65 ) ) {
F_56 ( V_83 ,
& V_86 -> V_65 ) ;
F_56 ( V_83 , V_90 ) ;
break;
}
} else {
F_56 ( V_83 , V_90 ) ;
break;
}
}
V_5 -> V_55 = V_83 ;
V_5 -> V_95 = V_44 . V_96 [ V_83 ] ;
}
static void F_57 ( void )
{
int V_43 ;
void * V_102 ;
struct V_103 * V_47 ;
struct V_104 * V_105 ;
T_4 V_106 ;
while ( 1 ) {
if ( F_58 ( & V_59 . V_107 ) )
break;
F_59 (cpu) {
V_102 = V_44 . V_108 [ V_43 ] ;
V_47 = (struct V_103 * ) V_102 +
V_109 ;
V_106 = F_60 ( V_47 -> V_49 . V_106 ) ;
if ( V_106 == V_110 )
continue;
V_105 = (struct V_104 * )
V_47 -> V_111 . V_112 ;
if ( V_105 -> V_50 == V_113 )
F_61 ( & V_59 . V_107 ) ;
F_62 ( V_47 , V_106 ) ;
}
F_63 ( 10 ) ;
}
F_59 (cpu) {
V_102 = V_44 . V_108 [ V_43 ] ;
V_47 = (struct V_103 * ) V_102 + V_109 ;
V_47 -> V_49 . V_106 = V_110 ;
}
}
static void F_64 ( struct V_104 * V_105 )
{
F_61 ( & V_59 . V_107 ) ;
}
void F_65 ( bool V_114 )
{
struct V_104 V_105 ;
if ( V_91 < V_115 )
return;
F_66 ( & V_59 . V_107 ) ;
memset ( & V_105 , 0 , sizeof( struct V_104 ) ) ;
V_105 . V_50 = V_116 ;
F_20 ( & V_105 , sizeof( struct V_104 ) ) ;
if ( ! V_114 )
F_67 ( & V_59 . V_107 ) ;
else
F_57 () ;
}
static void F_68 ( struct V_104 * V_105 )
{
struct V_117 * V_7 ;
struct V_4 * V_68 ;
V_7 = (struct V_117 * ) V_105 ;
V_68 = F_8 () ;
if ( ! V_68 ) {
F_46 ( L_3 ) ;
return;
}
V_68 -> V_118 = true ;
V_68 -> V_119 = (struct V_120 * )
( F_69 ( ( unsigned long )
& V_68 -> V_121 ,
V_122 ) ) ;
V_68 -> V_119 -> V_123 . V_124 = 0 ;
V_68 -> V_119 -> V_123 . V_111 . V_125 = V_126 ;
V_68 -> V_119 -> V_127 = 0 ;
V_68 -> V_119 -> V_128 = 0 ;
if ( V_91 != V_92 ) {
V_68 -> V_129 =
( V_7 -> V_129 != 0 ) ;
V_68 -> V_119 -> V_123 . V_111 . V_125 =
V_7 -> V_130 ;
}
memcpy ( & V_68 -> V_6 , V_7 ,
sizeof( struct V_117 ) ) ;
V_68 -> V_131 = ( T_3 ) V_7 -> V_132 / 32 ;
V_68 -> V_133 = ( T_3 ) V_7 -> V_132 % 32 ;
F_38 ( V_68 ) ;
}
static void F_70 ( struct V_104 * V_105 )
{
struct V_134 * V_58 ;
struct V_4 * V_5 ;
unsigned long V_56 ;
struct V_135 * V_136 ;
V_58 = (struct V_134 * ) V_105 ;
F_39 ( & V_59 . V_60 ) ;
V_5 = F_71 ( V_58 -> V_48 ) ;
if ( V_5 == NULL ) {
goto V_137;
}
F_32 ( & V_5 -> V_39 , V_56 ) ;
V_5 -> V_58 = true ;
F_33 ( & V_5 -> V_39 , V_56 ) ;
if ( V_5 -> V_67 ) {
if ( V_5 -> V_138 ) {
V_5 -> V_138 ( V_5 ) ;
goto V_137;
}
V_136 = F_72 ( & V_5 -> V_67 -> V_135 ) ;
if ( V_136 ) {
F_37 ( V_5 -> V_67 ) ;
F_73 ( V_136 ) ;
}
} else {
F_26 ( V_5 ,
V_5 -> V_6 . V_48 ) ;
}
V_137:
F_41 ( & V_59 . V_60 ) ;
}
void F_74 ( struct V_4 * V_5 )
{
F_39 ( & V_59 . V_60 ) ;
F_27 ( ! F_5 ( V_5 ) ) ;
V_5 -> V_58 = true ;
F_37 ( V_5 -> V_67 ) ;
F_41 ( & V_59 . V_60 ) ;
}
static void F_75 (
struct V_104 * V_105 )
{
}
static void F_76 ( struct V_104 * V_105 )
{
struct V_139 * V_140 ;
struct V_141 * V_142 ;
struct V_104 * V_143 ;
struct V_144 * V_145 ;
unsigned long V_56 ;
V_140 = (struct V_139 * ) V_105 ;
F_32 ( & V_59 . V_146 , V_56 ) ;
F_40 (msginfo, &vmbus_connection.chn_msg_list,
msglistentry) {
V_143 =
(struct V_104 * ) V_142 -> V_47 ;
if ( V_143 -> V_50 == V_147 ) {
V_145 =
(struct V_144 * ) V_142 -> V_47 ;
if ( V_145 -> V_48 == V_140 -> V_48 &&
V_145 -> V_148 == V_140 -> V_148 ) {
memcpy ( & V_142 -> V_149 . V_150 ,
V_140 ,
sizeof(
struct V_139 ) ) ;
F_61 ( & V_142 -> V_151 ) ;
break;
}
}
}
F_33 ( & V_59 . V_146 , V_56 ) ;
}
static void F_77 ( struct V_104 * V_105 )
{
struct V_152 * V_153 ;
struct V_141 * V_142 ;
struct V_104 * V_143 ;
struct V_154 * V_155 ;
unsigned long V_56 ;
V_153 = (struct V_152 * ) V_105 ;
F_32 ( & V_59 . V_146 , V_56 ) ;
F_40 (msginfo, &vmbus_connection.chn_msg_list,
msglistentry) {
V_143 =
(struct V_104 * ) V_142 -> V_47 ;
if ( V_143 -> V_50 == V_156 ) {
V_155 =
(struct V_154 * ) V_143 ;
if ( ( V_153 -> V_48 ==
V_155 -> V_48 ) &&
( V_153 -> V_157 == V_155 -> V_157 ) ) {
memcpy ( & V_142 -> V_149 . V_158 ,
V_153 ,
sizeof(
struct V_152 ) ) ;
F_61 ( & V_142 -> V_151 ) ;
break;
}
}
}
F_33 ( & V_59 . V_146 , V_56 ) ;
}
static void F_78 (
struct V_104 * V_105 )
{
struct V_159 * V_160 ;
struct V_141 * V_142 ;
struct V_104 * V_143 ;
struct V_161 * V_162 ;
unsigned long V_56 ;
V_160 = (struct V_159 * ) V_105 ;
F_32 ( & V_59 . V_146 , V_56 ) ;
F_40 (msginfo, &vmbus_connection.chn_msg_list,
msglistentry) {
V_143 =
(struct V_104 * ) V_142 -> V_47 ;
if ( V_143 -> V_50 == V_163 ) {
V_162 =
(struct V_161 * ) V_143 ;
if ( V_160 -> V_157 == V_162 -> V_157 ) {
memcpy ( & V_142 -> V_149 . V_160 ,
V_160 ,
sizeof(
struct V_159 ) ) ;
F_61 ( & V_142 -> V_151 ) ;
break;
}
}
}
F_33 ( & V_59 . V_146 , V_56 ) ;
}
static void F_79 (
struct V_104 * V_105 )
{
struct V_141 * V_142 ;
struct V_104 * V_143 ;
struct V_164 * V_165 ;
unsigned long V_56 ;
V_165 = (struct V_164 * ) V_105 ;
F_32 ( & V_59 . V_146 , V_56 ) ;
F_40 (msginfo, &vmbus_connection.chn_msg_list,
msglistentry) {
V_143 =
(struct V_104 * ) V_142 -> V_47 ;
if ( V_143 -> V_50 ==
V_166 ) {
memcpy ( & V_142 -> V_149 . V_165 ,
V_165 ,
sizeof( struct V_164 ) ) ;
F_61 ( & V_142 -> V_151 ) ;
}
}
F_33 ( & V_59 . V_146 , V_56 ) ;
}
void F_80 ( void * V_167 )
{
struct V_103 * V_47 = V_167 ;
struct V_104 * V_105 ;
int V_168 ;
V_105 = (struct V_104 * ) V_47 -> V_111 . V_112 ;
V_168 = V_47 -> V_49 . V_169 ;
if ( V_105 -> V_50 >= V_170 ) {
F_46 ( L_4 ,
V_105 -> V_50 , V_168 ) ;
F_81 ( L_5 , V_171 ,
( unsigned char * ) V_47 -> V_111 . V_112 , V_168 ) ;
return;
}
if ( V_172 [ V_105 -> V_50 ] . V_173 )
V_172 [ V_105 -> V_50 ] . V_173 ( V_105 ) ;
else
F_46 ( L_6 , V_105 -> V_50 ) ;
}
int F_82 ( void )
{
struct V_104 * V_47 ;
struct V_141 * V_142 ;
int V_71 ;
V_142 = F_83 ( sizeof( * V_142 ) +
sizeof( struct V_104 ) ,
V_174 ) ;
if ( ! V_142 )
return - V_175 ;
V_47 = (struct V_104 * ) V_142 -> V_47 ;
V_47 -> V_50 = V_176 ;
V_71 = F_20 ( V_47 ,
sizeof( struct V_104 ) ) ;
if ( V_71 != 0 ) {
F_46 ( L_7 , V_71 ) ;
goto V_177;
}
V_177:
F_13 ( V_142 ) ;
return V_71 ;
}
struct V_4 * F_84 ( struct V_4 * V_86 )
{
struct V_178 * V_179 , * V_66 ;
int V_83 ;
struct V_4 * V_180 ;
struct V_4 * V_181 = V_86 ;
int V_182 ;
int V_2 = 1 ;
if ( F_85 ( & V_86 -> V_40 ) )
return V_181 ;
V_182 = V_86 -> V_183 ++ ;
if ( V_182 > ( V_86 -> V_62 ) ) {
V_86 -> V_183 = 0 ;
return V_181 ;
}
V_83 = V_44 . V_96 [ F_29 () ] ;
F_30 () ;
F_86 (cur, tmp, &primary->sc_list) {
V_180 = F_87 ( V_179 , struct V_4 , V_40 ) ;
if ( V_180 -> V_78 != V_184 )
continue;
if ( V_180 -> V_95 == V_83 )
return V_180 ;
if ( V_2 == V_182 )
return V_180 ;
V_2 ++ ;
}
return V_181 ;
}
static void F_88 ( struct V_4 * V_57 )
{
struct V_178 * V_179 , * V_66 ;
struct V_4 * V_180 ;
if ( V_57 -> V_80 == NULL )
return;
F_86 (cur, tmp, &primary_channel->sc_list) {
V_180 = F_87 ( V_179 , struct V_4 , V_40 ) ;
V_57 -> V_80 ( V_180 ) ;
}
}
void F_89 ( struct V_4 * V_57 ,
void (* F_90)( struct V_4 * V_185 ) )
{
V_57 -> V_80 = F_90 ;
}
bool F_91 ( struct V_4 * V_86 )
{
bool V_71 ;
V_71 = ! F_85 ( & V_86 -> V_40 ) ;
if ( V_71 ) {
F_88 ( V_86 ) ;
}
return V_71 ;
}
void F_92 ( struct V_4 * V_5 ,
void (* F_93)( struct V_4 * ) )
{
V_5 -> V_138 = F_93 ;
}
