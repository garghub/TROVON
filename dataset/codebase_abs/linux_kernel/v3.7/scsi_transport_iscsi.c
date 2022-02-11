static void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
F_3 ( V_4 ) ;
}
static T_1
F_4 ( struct V_1 * V_2 , struct V_5 * V_6 ,
char * V_7 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
return sprintf ( V_7 , L_1 , ( unsigned long long ) F_5 ( V_4 -> V_8 ) ) ;
}
static void F_6 ( struct V_1 * V_2 )
{
struct V_9 * V_10 = F_7 ( V_2 ) ;
F_3 ( V_10 ) ;
}
static T_1
F_8 ( struct V_1 * V_2 , struct V_5 * V_6 , char * V_7 )
{
struct V_9 * V_10 = F_7 ( V_2 ) ;
return sprintf ( V_7 , L_1 , ( unsigned long long ) V_10 -> V_11 ) ;
}
static int F_9 ( struct V_1 * V_2 , void * V_12 )
{
struct V_9 * V_10 = F_7 ( V_2 ) ;
T_2 * V_13 = ( T_2 * ) V_12 ;
return * V_13 == V_10 -> V_11 ;
}
struct V_9 *
F_10 ( int V_14 )
{
struct V_1 * V_2 ;
struct V_9 * V_10 ;
T_2 V_11 ;
int V_15 ;
for ( V_11 = 1 ; V_11 < V_16 ; V_11 ++ ) {
V_2 = F_11 ( & V_17 , NULL , & V_11 ,
F_9 ) ;
if ( ! V_2 )
break;
}
if ( V_11 == V_16 ) {
F_12 ( V_18 L_2 ,
V_16 - 1 ) ;
return NULL ;
}
V_10 = F_13 ( sizeof( * V_10 ) + V_14 , V_19 ) ;
if ( ! V_10 )
return NULL ;
V_10 -> V_11 = V_11 ;
V_10 -> V_2 . V_20 = & V_17 ;
F_14 ( & V_10 -> V_2 , L_3 , ( unsigned long long ) V_11 ) ;
V_15 = F_15 ( & V_10 -> V_2 ) ;
if ( V_15 )
goto V_21;
V_15 = F_16 ( & V_10 -> V_2 . V_22 , & V_23 ) ;
if ( V_15 )
goto V_24;
if ( V_14 )
V_10 -> V_25 = & V_10 [ 1 ] ;
return V_10 ;
V_24:
F_17 ( & V_10 -> V_2 ) ;
return NULL ;
V_21:
F_3 ( V_10 ) ;
return NULL ;
}
void F_18 ( struct V_9 * V_10 )
{
F_19 ( & V_10 -> V_2 . V_22 , & V_23 ) ;
F_17 ( & V_10 -> V_2 ) ;
}
struct V_9 * F_20 ( T_3 V_26 )
{
struct V_9 * V_10 ;
struct V_1 * V_2 ;
V_2 = F_11 ( & V_17 , NULL , & V_26 ,
F_9 ) ;
if ( ! V_2 )
return NULL ;
V_10 = F_7 ( V_2 ) ;
F_21 ( V_2 ) ;
return V_10 ;
}
static void F_22 ( struct V_1 * V_2 )
{
struct V_27 * V_28 = F_23 ( V_2 ) ;
struct V_1 * V_29 = V_28 -> V_2 . V_29 ;
F_3 ( V_28 ) ;
F_21 ( V_29 ) ;
}
static T_4 F_24 ( struct V_30 * V_22 ,
struct V_31 * V_6 , int V_32 )
{
struct V_1 * V_2 = F_25 ( V_22 , struct V_1 , V_22 ) ;
struct V_27 * V_28 = F_23 ( V_2 ) ;
struct V_8 * V_33 = V_28 -> V_34 ;
int V_35 ;
if ( V_6 == & V_36 . V_6 )
V_35 = V_37 ;
else if ( V_6 == & V_38 . V_6 )
V_35 = V_39 ;
else if ( V_6 == & V_40 . V_6 )
V_35 = V_41 ;
else if ( V_6 == & V_42 . V_6 )
V_35 = V_43 ;
else if ( V_6 == & V_44 . V_6 )
V_35 = V_45 ;
else if ( V_6 == & V_46 . V_6 )
V_35 = V_47 ;
else if ( V_28 -> V_48 == V_49 ) {
if ( V_6 == & V_50 . V_6 )
V_35 = V_51 ;
else if ( V_6 == & V_52 . V_6 )
V_35 = V_53 ;
else if ( V_6 == & V_54 . V_6 )
V_35 = V_55 ;
else if ( V_6 == & V_56 . V_6 )
V_35 = V_57 ;
else
return 0 ;
} else if ( V_28 -> V_48 == V_58 ) {
if ( V_6 == & V_59 . V_6 )
V_35 = V_60 ;
else if ( V_6 == & V_61 . V_6 )
V_35 = V_62 ;
else if ( V_6 == & V_63 . V_6 )
V_35 = V_64 ;
else if ( V_6 == & V_65 . V_6 )
V_35 = V_66 ;
else if ( V_6 == & V_67 . V_6 )
V_35 = V_68 ;
else
return 0 ;
} else {
F_26 ( 1 , L_4 ) ;
return 0 ;
}
return V_33 -> V_69 ( V_70 , V_35 ) ;
}
struct V_27 *
F_27 ( struct V_71 * V_72 , struct V_8 * V_34 ,
T_5 V_48 , T_5 V_73 , int V_14 )
{
struct V_27 * V_28 ;
int V_15 ;
V_28 = F_13 ( sizeof( * V_28 ) + V_14 , V_19 ) ;
if ( ! V_28 )
return NULL ;
V_28 -> V_34 = V_34 ;
V_28 -> V_48 = V_48 ;
V_28 -> V_73 = V_73 ;
V_28 -> V_2 . V_74 = F_22 ;
V_28 -> V_2 . V_20 = & V_75 ;
V_28 -> V_2 . V_29 = F_28 ( & V_72 -> V_76 ) ;
if ( V_48 == V_49 )
F_14 ( & V_28 -> V_2 , L_5 , V_72 -> V_77 ,
V_73 ) ;
else
F_14 ( & V_28 -> V_2 , L_6 , V_72 -> V_77 ,
V_73 ) ;
V_15 = F_15 ( & V_28 -> V_2 ) ;
if ( V_15 )
goto V_78;
V_15 = F_16 ( & V_28 -> V_2 . V_22 , & V_79 ) ;
if ( V_15 )
goto V_80;
if ( V_14 )
V_28 -> V_25 = & V_28 [ 1 ] ;
return V_28 ;
V_80:
F_17 ( & V_28 -> V_2 ) ;
return NULL ;
V_78:
F_21 ( V_28 -> V_2 . V_29 ) ;
F_3 ( V_28 ) ;
return NULL ;
}
void F_29 ( struct V_27 * V_28 )
{
F_19 ( & V_28 -> V_2 . V_22 , & V_79 ) ;
F_17 ( & V_28 -> V_2 ) ;
}
static int F_30 ( struct V_81 * V_82 )
{
struct V_71 * V_72 = F_31 ( V_82 ) ;
struct V_83 * V_84 = V_82 -> V_85 ;
struct V_86 * V_87 = V_82 -> V_87 ;
struct V_3 * V_32 = F_32 ( V_72 -> V_88 ) ;
int V_89 = sizeof( T_5 ) ;
int V_90 ;
if ( V_82 -> V_91 < sizeof( T_5 ) ) {
V_90 = - V_92 ;
goto V_93;
}
switch ( V_84 -> V_94 ) {
case V_95 :
V_89 += sizeof( struct V_96 ) ;
if ( ( V_72 -> V_97 -> V_98 == 0L ) ||
( V_84 -> V_99 . V_100 . V_98 !=
V_72 -> V_97 -> V_98 ) ) {
V_90 = - V_101 ;
goto V_93;
}
break;
default:
V_90 = - V_102 ;
goto V_93;
}
if ( V_82 -> V_91 < V_89 ) {
V_90 = - V_92 ;
goto V_93;
}
V_90 = V_32 -> V_8 -> V_103 ( V_82 ) ;
if ( ! V_90 )
return 0 ;
V_93:
F_33 ( V_82 -> V_104 < sizeof( T_5 ) ) ;
V_87 -> V_105 = 0 ;
V_87 -> V_106 = V_90 ;
V_82 -> V_104 = sizeof( T_5 ) ;
F_34 ( V_82 , V_90 , 0 ) ;
return 0 ;
}
static int
F_35 ( struct V_71 * V_72 , struct V_107 * V_108 )
{
struct V_1 * V_2 = & V_72 -> V_76 ;
struct V_3 * V_32 = F_32 ( V_72 -> V_88 ) ;
struct V_109 * V_110 ;
char V_111 [ 20 ] ;
int V_90 ;
if ( ! V_32 -> V_8 -> V_103 )
return - V_112 ;
snprintf ( V_111 , sizeof( V_111 ) , L_7 , V_72 -> V_77 ) ;
V_110 = F_36 ( V_72 , V_113 ) ;
if ( ! V_110 )
return - V_114 ;
V_90 = F_37 ( V_2 , V_110 , V_111 , F_30 , 0 ) ;
if ( V_90 ) {
F_38 ( V_18 , V_72 , L_8
L_9 ) ;
F_39 ( V_110 ) ;
return V_90 ;
}
V_108 -> V_115 = V_110 ;
return 0 ;
}
static int F_40 ( struct V_116 * V_117 , struct V_1 * V_2 ,
struct V_1 * V_118 )
{
struct V_71 * V_72 = F_41 ( V_2 ) ;
struct V_107 * V_108 = V_72 -> V_119 ;
memset ( V_108 , 0 , sizeof( * V_108 ) ) ;
F_42 ( & V_108 -> V_120 , 0 ) ;
F_43 ( & V_108 -> V_121 ) ;
F_35 ( V_72 , V_108 ) ;
return 0 ;
}
static int F_44 ( struct V_116 * V_117 ,
struct V_1 * V_2 , struct V_1 * V_118 )
{
struct V_71 * V_72 = F_41 ( V_2 ) ;
struct V_107 * V_108 = V_72 -> V_119 ;
if ( V_108 -> V_115 ) {
F_45 ( V_108 -> V_115 ) ;
F_39 ( V_108 -> V_115 ) ;
}
return 0 ;
}
static T_5 F_46 ( struct V_122 * V_123 )
{
struct V_124 * V_125 = F_47 ( V_123 -> V_2 . V_29 ) ;
return V_125 -> V_126 ;
}
static struct V_124 * F_48 ( T_5 V_126 )
{
unsigned long V_127 ;
struct V_124 * V_125 ;
F_49 ( & V_128 , V_127 ) ;
F_50 (sess, &sesslist, sess_list) {
if ( V_125 -> V_126 == V_126 ) {
F_51 ( & V_128 , V_127 ) ;
return V_125 ;
}
}
F_51 ( & V_128 , V_127 ) ;
return NULL ;
}
static struct V_122 * F_52 ( T_5 V_126 , T_5 V_129 )
{
unsigned long V_127 ;
struct V_122 * V_123 ;
F_49 ( & V_130 , V_127 ) ;
F_50 (conn, &connlist, conn_list) {
if ( ( V_123 -> V_129 == V_129 ) && ( F_46 ( V_123 ) == V_126 ) ) {
F_51 ( & V_130 , V_127 ) ;
return V_123 ;
}
}
F_51 ( & V_130 , V_127 ) ;
return NULL ;
}
static const char * F_53 ( int V_131 )
{
int V_32 ;
char * V_132 = NULL ;
for ( V_32 = 0 ; V_32 < F_54 ( V_133 ) ; V_32 ++ ) {
if ( V_133 [ V_32 ] . V_134 == V_131 ) {
V_132 = V_133 [ V_32 ] . V_132 ;
break;
}
}
return V_132 ;
}
int F_55 ( struct V_124 * V_135 )
{
unsigned long V_127 ;
int V_15 ;
F_49 ( & V_135 -> V_136 , V_127 ) ;
switch ( V_135 -> V_131 ) {
case V_137 :
V_15 = 0 ;
break;
case V_138 :
V_15 = V_139 << 16 ;
break;
case V_140 :
V_15 = V_141 << 16 ;
break;
default:
V_15 = V_142 << 16 ;
break;
}
F_51 ( & V_135 -> V_136 , V_127 ) ;
return V_15 ;
}
int F_56 ( struct V_124 * V_135 )
{
unsigned long V_127 ;
int V_90 = 0 ;
F_49 ( & V_135 -> V_136 , V_127 ) ;
if ( V_135 -> V_131 == V_137 )
V_90 = 1 ;
F_51 ( & V_135 -> V_136 , V_127 ) ;
return V_90 ;
}
static void F_57 ( struct V_1 * V_2 )
{
struct V_124 * V_135 = F_47 ( V_2 ) ;
struct V_71 * V_72 ;
V_72 = F_58 ( V_135 ) ;
F_59 ( V_72 ) ;
F_60 ( V_135 , L_10 ) ;
F_3 ( V_135 ) ;
}
int F_61 ( const struct V_1 * V_2 )
{
return V_2 -> V_74 == F_57 ;
}
static int F_62 ( struct V_1 * V_2 , void * V_12 )
{
void (* F_63) ( struct V_124 * ) = V_12 ;
if ( ! F_61 ( V_2 ) )
return 0 ;
F_63 ( F_47 ( V_2 ) ) ;
return 0 ;
}
void F_64 ( struct V_71 * V_72 ,
void (* F_63)( struct V_124 * ) )
{
F_65 ( & V_72 -> V_76 , F_63 ,
F_62 ) ;
}
int F_66 ( struct V_71 * V_72 , unsigned long time )
{
struct V_107 * V_108 = V_72 -> V_119 ;
return ! F_67 ( & V_108 -> V_120 ) ;
}
static int F_68 ( struct V_1 * V_2 , void * V_12 )
{
struct V_143 * V_144 = V_12 ;
struct V_124 * V_135 ;
struct V_71 * V_72 ;
struct V_107 * V_108 ;
unsigned long V_127 ;
unsigned int V_11 ;
if ( ! F_61 ( V_2 ) )
return 0 ;
V_135 = F_47 ( V_2 ) ;
F_60 ( V_135 , L_11 ) ;
V_72 = F_58 ( V_135 ) ;
V_108 = V_72 -> V_119 ;
F_69 ( & V_108 -> V_121 ) ;
F_49 ( & V_135 -> V_136 , V_127 ) ;
if ( V_135 -> V_131 != V_137 ) {
F_51 ( & V_135 -> V_136 , V_127 ) ;
goto V_145;
}
V_11 = V_135 -> V_146 ;
F_51 ( & V_135 -> V_136 , V_127 ) ;
if ( V_11 != V_147 ) {
if ( ( V_144 -> V_148 == V_149 ||
V_144 -> V_148 == 0 ) &&
( V_144 -> V_11 == V_149 ||
V_144 -> V_11 == V_11 ) )
F_70 ( & V_135 -> V_2 , 0 , V_11 ,
V_144 -> V_150 , 1 ) ;
}
V_145:
F_71 ( & V_108 -> V_121 ) ;
F_60 ( V_135 , L_12 ) ;
return 0 ;
}
static int F_72 ( struct V_71 * V_72 , T_6 V_148 ,
T_6 V_11 , T_6 V_150 )
{
struct V_143 V_144 ;
V_144 . V_148 = V_148 ;
V_144 . V_11 = V_11 ;
V_144 . V_150 = V_150 ;
return F_65 ( & V_72 -> V_76 , & V_144 ,
F_68 ) ;
}
static void F_73 ( struct V_151 * V_152 )
{
struct V_124 * V_135 =
F_25 ( V_152 , struct V_124 , V_153 ) ;
struct V_71 * V_72 = F_58 ( V_135 ) ;
struct V_107 * V_108 = V_72 -> V_119 ;
struct V_143 V_144 ;
V_144 . V_148 = 0 ;
V_144 . V_11 = V_149 ;
V_144 . V_150 = V_149 ;
F_68 ( & V_135 -> V_2 , & V_144 ) ;
F_74 ( & V_108 -> V_120 ) ;
}
int F_75 ( struct V_154 * V_155 )
{
struct V_124 * V_135 =
F_76 ( F_77 ( V_155 -> V_1 ) ) ;
unsigned long V_127 ;
int V_90 = 0 ;
F_49 ( & V_135 -> V_136 , V_127 ) ;
while ( V_135 -> V_131 != V_137 ) {
if ( V_135 -> V_131 == V_140 ) {
V_90 = V_156 ;
break;
}
F_51 ( & V_135 -> V_136 , V_127 ) ;
F_78 ( 1000 ) ;
F_49 ( & V_135 -> V_136 , V_127 ) ;
}
F_51 ( & V_135 -> V_136 , V_127 ) ;
return V_90 ;
}
static void F_79 ( struct V_151 * V_152 )
{
struct V_124 * V_135 =
F_25 ( V_152 , struct V_124 ,
V_157 . V_152 ) ;
unsigned long V_127 ;
F_80 ( V_158 , V_135 ,
L_13 ,
V_135 -> V_159 ) ;
F_49 ( & V_135 -> V_136 , V_127 ) ;
switch ( V_135 -> V_131 ) {
case V_138 :
V_135 -> V_131 = V_140 ;
break;
case V_137 :
case V_140 :
F_51 ( & V_135 -> V_136 , V_127 ) ;
return;
}
F_51 ( & V_135 -> V_136 , V_127 ) ;
if ( V_135 -> V_34 -> F_79 )
V_135 -> V_34 -> F_79 ( V_135 ) ;
F_60 ( V_135 , L_14 ) ;
F_81 ( & V_135 -> V_2 , V_160 ) ;
F_60 ( V_135 , L_15 ) ;
}
static void F_82 ( struct V_151 * V_152 )
{
struct V_124 * V_135 =
F_25 ( V_152 , struct V_124 ,
V_161 ) ;
struct V_71 * V_72 = F_58 ( V_135 ) ;
struct V_107 * V_108 = V_72 -> V_119 ;
unsigned long V_127 ;
F_60 ( V_135 , L_16 ) ;
F_83 ( & V_135 -> V_157 ) ;
F_49 ( & V_135 -> V_136 , V_127 ) ;
V_135 -> V_131 = V_137 ;
F_51 ( & V_135 -> V_136 , V_127 ) ;
F_81 ( & V_135 -> V_2 , V_162 ) ;
if ( V_72 -> V_97 -> V_163 ) {
if ( F_84 ( V_72 , & V_135 -> V_153 ) )
F_85 ( & V_108 -> V_120 ) ;
}
F_60 ( V_135 , L_17 ) ;
}
void F_86 ( struct V_124 * V_135 )
{
F_87 ( V_164 , & V_135 -> V_161 ) ;
F_88 ( V_164 ) ;
}
static void F_89 ( struct V_151 * V_152 )
{
struct V_124 * V_135 =
F_25 ( V_152 , struct V_124 ,
V_165 ) ;
unsigned long V_127 ;
F_60 ( V_135 , L_18 ) ;
F_49 ( & V_135 -> V_136 , V_127 ) ;
V_135 -> V_131 = V_138 ;
F_51 ( & V_135 -> V_136 , V_127 ) ;
F_90 ( & V_135 -> V_2 ) ;
F_60 ( V_135 , L_19 ) ;
if ( V_135 -> V_159 >= 0 )
F_91 ( V_164 ,
& V_135 -> V_157 ,
V_135 -> V_159 * V_166 ) ;
}
void F_92 ( struct V_124 * V_135 )
{
F_87 ( V_164 , & V_135 -> V_165 ) ;
}
static void F_93 ( struct V_151 * V_152 )
{
struct V_124 * V_135 =
F_25 ( V_152 , struct V_124 ,
V_167 ) ;
struct V_71 * V_72 = F_58 ( V_135 ) ;
struct V_107 * V_108 = V_72 -> V_119 ;
unsigned long V_127 ;
unsigned int V_146 ;
F_60 ( V_135 , L_20 ) ;
F_69 ( & V_108 -> V_121 ) ;
F_49 ( & V_135 -> V_136 , V_127 ) ;
if ( V_135 -> V_146 == V_147 ) {
F_51 ( & V_135 -> V_136 , V_127 ) ;
F_71 ( & V_108 -> V_121 ) ;
return;
}
V_146 = V_135 -> V_146 ;
V_135 -> V_146 = V_147 ;
F_51 ( & V_135 -> V_136 , V_127 ) ;
F_71 ( & V_108 -> V_121 ) ;
if ( V_135 -> V_168 )
F_94 ( & V_169 , V_146 ) ;
F_95 ( & V_135 -> V_2 ) ;
F_96 ( V_135 , V_170 ) ;
F_60 ( V_135 , L_21 ) ;
}
struct V_124 *
F_97 ( struct V_71 * V_72 , struct V_8 * V_34 ,
int V_14 )
{
struct V_124 * V_135 ;
V_135 = F_13 ( sizeof( * V_135 ) + V_14 ,
V_19 ) ;
if ( ! V_135 )
return NULL ;
V_135 -> V_34 = V_34 ;
V_135 -> V_171 = - 1 ;
V_135 -> V_159 = 120 ;
V_135 -> V_131 = V_140 ;
F_98 ( & V_135 -> V_157 , F_79 ) ;
F_99 ( & V_135 -> V_172 ) ;
F_100 ( & V_135 -> V_161 , F_82 ) ;
F_100 ( & V_135 -> V_165 , F_89 ) ;
F_100 ( & V_135 -> V_167 , F_93 ) ;
F_100 ( & V_135 -> V_153 , F_73 ) ;
F_101 ( & V_135 -> V_136 ) ;
F_102 ( V_72 ) ;
V_135 -> V_2 . V_29 = & V_72 -> V_76 ;
V_135 -> V_2 . V_74 = F_57 ;
F_103 ( & V_135 -> V_2 ) ;
if ( V_14 )
V_135 -> V_25 = & V_135 [ 1 ] ;
F_60 ( V_135 , L_22 ) ;
return V_135 ;
}
int F_104 ( struct V_124 * V_135 , unsigned int V_146 )
{
struct V_71 * V_72 = F_58 ( V_135 ) ;
struct V_107 * V_108 ;
unsigned long V_127 ;
int V_11 = 0 ;
int V_15 ;
V_108 = V_72 -> V_119 ;
V_135 -> V_126 = F_105 ( 1 , & V_173 ) ;
if ( V_146 == V_147 ) {
V_11 = F_106 ( & V_169 , 0 , 0 , V_19 ) ;
if ( V_11 < 0 ) {
F_80 ( V_18 , V_135 ,
L_23 ) ;
return V_11 ;
}
V_135 -> V_146 = ( unsigned int ) V_11 ;
V_135 -> V_168 = true ;
} else
V_135 -> V_146 = V_146 ;
F_14 ( & V_135 -> V_2 , L_24 , V_135 -> V_126 ) ;
V_15 = F_107 ( & V_135 -> V_2 ) ;
if ( V_15 ) {
F_80 ( V_18 , V_135 ,
L_25 ) ;
goto V_174;
}
F_108 ( & V_135 -> V_2 ) ;
F_49 ( & V_128 , V_127 ) ;
F_109 ( & V_135 -> V_172 , & V_175 ) ;
F_51 ( & V_128 , V_127 ) ;
F_96 ( V_135 , V_176 ) ;
F_60 ( V_135 , L_26 ) ;
return 0 ;
V_174:
if ( V_135 -> V_168 )
F_94 ( & V_169 , V_135 -> V_146 ) ;
return V_15 ;
}
struct V_124 *
F_110 ( struct V_71 * V_72 , struct V_8 * V_34 ,
int V_14 , unsigned int V_146 )
{
struct V_124 * V_135 ;
V_135 = F_97 ( V_72 , V_34 , V_14 ) ;
if ( ! V_135 )
return NULL ;
if ( F_104 ( V_135 , V_146 ) ) {
F_111 ( V_135 ) ;
return NULL ;
}
return V_135 ;
}
static void F_112 ( struct V_1 * V_2 )
{
struct V_122 * V_123 = F_113 ( V_2 ) ;
struct V_1 * V_29 = V_123 -> V_2 . V_29 ;
F_114 ( V_123 , L_27 ) ;
F_3 ( V_123 ) ;
F_21 ( V_29 ) ;
}
static int F_115 ( const struct V_1 * V_2 )
{
return V_2 -> V_74 == F_112 ;
}
static int F_116 ( struct V_1 * V_2 , void * V_12 )
{
if ( ! F_115 ( V_2 ) )
return 0 ;
return F_117 ( F_113 ( V_2 ) ) ;
}
void F_118 ( struct V_124 * V_135 )
{
struct V_71 * V_72 = F_58 ( V_135 ) ;
unsigned long V_127 ;
int V_15 ;
F_60 ( V_135 , L_28 ) ;
F_49 ( & V_128 , V_127 ) ;
F_119 ( & V_135 -> V_172 ) ;
F_51 ( & V_128 , V_127 ) ;
F_88 ( V_164 ) ;
if ( ! F_83 ( & V_135 -> V_157 ) )
F_88 ( V_164 ) ;
F_49 ( & V_135 -> V_136 , V_127 ) ;
V_135 -> V_131 = V_140 ;
F_51 ( & V_135 -> V_136 , V_127 ) ;
F_81 ( & V_135 -> V_2 , V_160 ) ;
F_120 ( V_72 ) ;
F_93 ( & V_135 -> V_167 ) ;
V_15 = F_65 ( & V_135 -> V_2 , NULL ,
F_116 ) ;
if ( V_15 )
F_80 ( V_18 , V_135 ,
L_29
L_30 , V_15 ) ;
F_121 ( & V_135 -> V_2 ) ;
F_60 ( V_135 , L_31 ) ;
F_122 ( & V_135 -> V_2 ) ;
}
void F_111 ( struct V_124 * V_135 )
{
F_60 ( V_135 , L_32 ) ;
F_96 ( V_135 , V_177 ) ;
F_21 ( & V_135 -> V_2 ) ;
}
int F_123 ( struct V_124 * V_135 )
{
F_118 ( V_135 ) ;
F_60 ( V_135 , L_33 ) ;
F_111 ( V_135 ) ;
return 0 ;
}
struct V_122 *
F_124 ( struct V_124 * V_135 , int V_14 , T_5 V_129 )
{
struct V_8 * V_34 = V_135 -> V_34 ;
struct V_122 * V_123 ;
unsigned long V_127 ;
int V_15 ;
V_123 = F_13 ( sizeof( * V_123 ) + V_14 , V_19 ) ;
if ( ! V_123 )
return NULL ;
if ( V_14 )
V_123 -> V_25 = & V_123 [ 1 ] ;
F_43 ( & V_123 -> V_178 ) ;
F_99 ( & V_123 -> V_179 ) ;
V_123 -> V_34 = V_34 ;
V_123 -> V_129 = V_129 ;
if ( ! F_28 ( & V_135 -> V_2 ) )
goto V_180;
F_14 ( & V_123 -> V_2 , L_34 , V_135 -> V_126 , V_129 ) ;
V_123 -> V_2 . V_29 = & V_135 -> V_2 ;
V_123 -> V_2 . V_74 = F_112 ;
V_15 = F_15 ( & V_123 -> V_2 ) ;
if ( V_15 ) {
F_80 ( V_18 , V_135 , L_35
L_36 ) ;
goto V_181;
}
F_108 ( & V_123 -> V_2 ) ;
F_49 ( & V_130 , V_127 ) ;
F_109 ( & V_123 -> V_179 , & V_182 ) ;
F_51 ( & V_130 , V_127 ) ;
F_114 ( V_123 , L_37 ) ;
return V_123 ;
V_181:
F_21 ( & V_135 -> V_2 ) ;
V_180:
F_3 ( V_123 ) ;
return NULL ;
}
int F_117 ( struct V_122 * V_123 )
{
unsigned long V_127 ;
F_49 ( & V_130 , V_127 ) ;
F_119 ( & V_123 -> V_179 ) ;
F_51 ( & V_130 , V_127 ) ;
F_121 ( & V_123 -> V_2 ) ;
F_114 ( V_123 , L_38 ) ;
F_17 ( & V_123 -> V_2 ) ;
return 0 ;
}
static struct V_3 *
F_125 ( struct V_8 * V_183 )
{
struct V_3 * V_4 ;
unsigned long V_127 ;
F_49 ( & V_184 , V_127 ) ;
F_50 (priv, &iscsi_transports, list) {
if ( V_183 == V_4 -> V_8 ) {
F_51 ( & V_184 , V_127 ) ;
return V_4 ;
}
}
F_51 ( & V_184 , V_127 ) ;
return NULL ;
}
static int
F_126 ( struct V_185 * V_186 , T_5 V_187 , T_7 V_188 )
{
return F_127 ( V_189 , V_186 , 0 , V_187 , V_188 ) ;
}
int F_128 ( struct V_122 * V_123 , struct V_190 * V_191 ,
char * V_12 , T_5 V_192 )
{
struct V_193 * V_194 ;
struct V_185 * V_186 ;
struct V_195 * V_196 ;
char * V_197 ;
struct V_3 * V_4 ;
int V_198 = F_129 ( sizeof( * V_196 ) + sizeof( struct V_190 ) +
V_192 ) ;
V_4 = F_125 ( V_123 -> V_34 ) ;
if ( ! V_4 )
return - V_199 ;
V_186 = F_130 ( V_198 , V_200 ) ;
if ( ! V_186 ) {
F_131 ( V_123 , V_201 ) ;
F_132 ( V_18 , V_123 , L_39
L_40 ) ;
return - V_114 ;
}
V_194 = F_133 ( V_186 , 0 , 0 , 0 , ( V_198 - sizeof( * V_194 ) ) , 0 ) ;
V_196 = F_134 ( V_194 ) ;
memset ( V_196 , 0 , sizeof( * V_196 ) ) ;
V_196 -> V_202 = F_5 ( V_123 -> V_34 ) ;
V_196 -> type = V_203 ;
V_196 -> V_204 . V_205 . V_129 = V_123 -> V_129 ;
V_196 -> V_204 . V_205 . V_126 = F_46 ( V_123 ) ;
V_197 = ( char * ) V_196 + sizeof( * V_196 ) ;
memcpy ( V_197 , V_191 , sizeof( struct V_190 ) ) ;
memcpy ( V_197 + sizeof( struct V_190 ) , V_12 , V_192 ) ;
return F_126 ( V_186 , V_206 , V_200 ) ;
}
int F_135 ( struct V_71 * V_72 ,
struct V_8 * V_34 , T_5 type ,
char * V_12 , T_8 V_192 )
{
struct V_193 * V_194 ;
struct V_185 * V_186 ;
struct V_195 * V_196 ;
int V_198 = F_129 ( sizeof( * V_196 ) + V_192 ) ;
V_186 = F_130 ( V_198 , V_200 ) ;
if ( ! V_186 ) {
F_12 ( V_18 L_41 ) ;
return - V_114 ;
}
V_194 = F_133 ( V_186 , 0 , 0 , 0 , ( V_198 - sizeof( * V_194 ) ) , 0 ) ;
V_196 = F_134 ( V_194 ) ;
memset ( V_196 , 0 , sizeof( * V_196 ) ) ;
V_196 -> type = type ;
V_196 -> V_202 = F_5 ( V_34 ) ;
switch ( type ) {
case V_207 :
V_196 -> V_204 . V_208 . V_77 = V_72 -> V_77 ;
break;
case V_209 :
V_196 -> V_204 . V_210 . V_77 = V_72 -> V_77 ;
break;
}
memcpy ( ( char * ) V_196 + sizeof( * V_196 ) , V_12 , V_192 ) ;
return F_126 ( V_186 , V_211 , V_200 ) ;
}
void F_131 ( struct V_122 * V_123 , enum V_212 error )
{
struct V_193 * V_194 ;
struct V_185 * V_186 ;
struct V_195 * V_196 ;
struct V_3 * V_4 ;
int V_198 = F_129 ( sizeof( * V_196 ) ) ;
V_4 = F_125 ( V_123 -> V_34 ) ;
if ( ! V_4 )
return;
V_186 = F_130 ( V_198 , V_200 ) ;
if ( ! V_186 ) {
F_132 ( V_18 , V_123 , L_42
L_43 , error ) ;
return;
}
V_194 = F_133 ( V_186 , 0 , 0 , 0 , ( V_198 - sizeof( * V_194 ) ) , 0 ) ;
V_196 = F_134 ( V_194 ) ;
V_196 -> V_202 = F_5 ( V_123 -> V_34 ) ;
V_196 -> type = V_213 ;
V_196 -> V_204 . V_214 . error = error ;
V_196 -> V_204 . V_214 . V_129 = V_123 -> V_129 ;
V_196 -> V_204 . V_214 . V_126 = F_46 ( V_123 ) ;
F_126 ( V_186 , V_206 , V_200 ) ;
F_132 ( V_158 , V_123 , L_44 ,
error ) ;
}
void F_136 ( struct V_122 * V_123 ,
enum V_215 V_131 )
{
struct V_193 * V_194 ;
struct V_185 * V_186 ;
struct V_195 * V_196 ;
struct V_3 * V_4 ;
int V_198 = F_129 ( sizeof( * V_196 ) ) ;
V_4 = F_125 ( V_123 -> V_34 ) ;
if ( ! V_4 )
return;
V_186 = F_130 ( V_198 , V_200 ) ;
if ( ! V_186 ) {
F_132 ( V_18 , V_123 , L_42
L_45 , V_131 ) ;
return;
}
V_194 = F_133 ( V_186 , 0 , 0 , 0 , ( V_198 - sizeof( * V_194 ) ) , 0 ) ;
V_196 = F_134 ( V_194 ) ;
V_196 -> V_202 = F_5 ( V_123 -> V_34 ) ;
V_196 -> type = V_216 ;
V_196 -> V_204 . V_217 . V_131 = V_131 ;
V_196 -> V_204 . V_217 . V_129 = V_123 -> V_129 ;
V_196 -> V_204 . V_217 . V_126 = F_46 ( V_123 ) ;
F_126 ( V_186 , V_206 , V_200 ) ;
F_132 ( V_158 , V_123 , L_46 ,
V_131 ) ;
}
void F_137 ( T_5 V_77 , struct V_8 * V_34 ,
enum V_218 V_219 , T_5 V_192 ,
T_9 * V_12 )
{
struct V_193 * V_194 ;
struct V_185 * V_186 ;
struct V_195 * V_196 ;
int V_198 = F_129 ( sizeof( * V_196 ) + V_192 ) ;
V_186 = F_130 ( V_198 , V_220 ) ;
if ( ! V_186 ) {
F_12 ( V_18 L_47 ,
V_77 , V_219 ) ;
return;
}
V_194 = F_133 ( V_186 , 0 , 0 , 0 , ( V_198 - sizeof( * V_194 ) ) , 0 ) ;
V_196 = F_134 ( V_194 ) ;
V_196 -> V_202 = F_5 ( V_34 ) ;
V_196 -> type = V_221 ;
V_196 -> V_204 . V_222 . V_77 = V_77 ;
V_196 -> V_204 . V_222 . V_219 = V_219 ;
V_196 -> V_204 . V_222 . V_192 = V_192 ;
if ( V_192 )
memcpy ( ( char * ) V_196 + sizeof( * V_196 ) , V_12 , V_192 ) ;
F_126 ( V_186 , V_206 , V_220 ) ;
}
void F_138 ( T_5 V_77 , struct V_8 * V_34 ,
T_5 V_223 , T_5 V_224 , T_5 V_192 ,
T_9 * V_12 )
{
struct V_193 * V_194 ;
struct V_185 * V_186 ;
struct V_195 * V_196 ;
int V_198 = F_129 ( sizeof( * V_196 ) + V_192 ) ;
V_186 = F_130 ( V_198 , V_220 ) ;
if ( ! V_186 ) {
F_12 ( V_18 L_48 ) ;
return;
}
V_194 = F_133 ( V_186 , 0 , 0 , 0 , ( V_198 - sizeof( * V_194 ) ) , 0 ) ;
V_196 = F_134 ( V_194 ) ;
V_196 -> V_202 = F_5 ( V_34 ) ;
V_196 -> type = V_225 ;
V_196 -> V_204 . V_226 . V_77 = V_77 ;
V_196 -> V_204 . V_226 . V_223 = V_223 ;
V_196 -> V_204 . V_226 . V_224 = V_224 ;
V_196 -> V_204 . V_226 . V_192 = V_192 ;
memcpy ( ( char * ) V_196 + sizeof( * V_196 ) , V_12 , V_192 ) ;
F_126 ( V_186 , V_206 , V_220 ) ;
}
static int
F_139 ( T_5 V_187 , int V_227 , int type , int V_228 , int V_229 ,
void * V_230 , int V_231 )
{
struct V_185 * V_186 ;
struct V_193 * V_194 ;
int V_198 = F_129 ( V_231 ) ;
int V_127 = V_229 ? V_232 : 0 ;
int V_33 = V_228 ? V_233 : type ;
V_186 = F_130 ( V_198 , V_200 ) ;
if ( ! V_186 ) {
F_12 ( V_18 L_49 ) ;
return - V_114 ;
}
V_194 = F_133 ( V_186 , 0 , 0 , V_33 , ( V_198 - sizeof( * V_194 ) ) , 0 ) ;
V_194 -> V_234 = V_127 ;
memcpy ( F_134 ( V_194 ) , V_230 , V_231 ) ;
return F_126 ( V_186 , V_187 , V_200 ) ;
}
static int
F_140 ( struct V_8 * V_34 , struct V_193 * V_194 )
{
struct V_195 * V_196 = F_134 ( V_194 ) ;
struct V_235 * V_236 ;
struct V_185 * V_237 ;
struct V_122 * V_123 ;
struct V_193 * V_238 ;
struct V_195 * V_239 ;
struct V_3 * V_4 ;
int V_198 = F_129 ( sizeof( * V_196 ) +
sizeof( struct V_235 ) +
sizeof( struct V_240 ) *
V_241 ) ;
int V_15 = 0 ;
V_4 = F_125 ( V_34 ) ;
if ( ! V_4 )
return - V_199 ;
V_123 = F_52 ( V_196 -> V_242 . V_243 . V_126 , V_196 -> V_242 . V_243 . V_129 ) ;
if ( ! V_123 )
return - V_244 ;
do {
int V_245 ;
V_237 = F_130 ( V_198 , V_200 ) ;
if ( ! V_237 ) {
F_132 ( V_18 , V_123 , L_50
L_51 ) ;
return - V_114 ;
}
V_238 = F_133 ( V_237 , 0 , 0 , 0 ,
( V_198 - sizeof( * V_238 ) ) , 0 ) ;
V_239 = F_134 ( V_238 ) ;
memset ( V_239 , 0 , sizeof( * V_239 ) ) ;
V_239 -> V_202 = F_5 ( V_123 -> V_34 ) ;
V_239 -> type = V_194 -> V_246 ;
V_239 -> V_242 . V_243 . V_129 =
V_196 -> V_242 . V_243 . V_129 ;
V_239 -> V_242 . V_243 . V_126 =
V_196 -> V_242 . V_243 . V_126 ;
V_236 = (struct V_235 * )
( ( char * ) V_239 + sizeof( * V_239 ) ) ;
memset ( V_236 , 0 , sizeof( * V_236 ) ) ;
V_34 -> V_243 ( V_123 , V_236 ) ;
V_245 = F_129 ( sizeof( struct V_195 ) +
sizeof( struct V_235 ) +
sizeof( struct V_240 ) *
V_236 -> V_247 ) ;
V_245 -= sizeof( * V_238 ) ;
V_245 = F_141 ( V_245 ) ;
F_142 ( V_237 , F_143 ( V_245 ) ) ;
V_238 -> V_248 = V_245 ;
V_15 = F_126 ( V_237 , V_206 ,
V_200 ) ;
} while ( V_15 < 0 && V_15 != - V_249 );
return V_15 ;
}
int F_96 ( struct V_124 * V_135 ,
enum V_250 V_251 )
{
struct V_3 * V_4 ;
struct V_71 * V_72 ;
struct V_195 * V_196 ;
struct V_185 * V_186 ;
struct V_193 * V_194 ;
int V_252 , V_198 = F_129 ( sizeof( * V_196 ) ) ;
V_4 = F_125 ( V_135 -> V_34 ) ;
if ( ! V_4 )
return - V_199 ;
V_72 = F_58 ( V_135 ) ;
V_186 = F_130 ( V_198 , V_19 ) ;
if ( ! V_186 ) {
F_80 ( V_18 , V_135 ,
L_52
L_53 , V_251 ) ;
return - V_114 ;
}
V_194 = F_133 ( V_186 , 0 , 0 , 0 , ( V_198 - sizeof( * V_194 ) ) , 0 ) ;
V_196 = F_134 ( V_194 ) ;
V_196 -> V_202 = F_5 ( V_135 -> V_34 ) ;
V_196 -> type = V_251 ;
switch ( V_251 ) {
case V_177 :
V_196 -> V_204 . V_253 . V_77 = V_72 -> V_77 ;
V_196 -> V_204 . V_253 . V_126 = V_135 -> V_126 ;
break;
case V_176 :
V_196 -> V_204 . V_254 . V_77 = V_72 -> V_77 ;
V_196 -> V_204 . V_254 . V_126 = V_135 -> V_126 ;
break;
case V_170 :
V_196 -> V_204 . V_255 . V_77 = V_72 -> V_77 ;
V_196 -> V_204 . V_255 . V_126 = V_135 -> V_126 ;
break;
default:
F_80 ( V_18 , V_135 , L_54
L_55 , V_251 ) ;
F_144 ( V_186 ) ;
return - V_199 ;
}
V_252 = F_126 ( V_186 , V_206 , V_19 ) ;
if ( V_252 == - V_101 )
F_80 ( V_18 , V_135 ,
L_52
L_56 ,
V_251 ) ;
F_60 ( V_135 , L_57 ,
V_251 , V_252 ) ;
return V_252 ;
}
static int
F_145 ( struct V_3 * V_4 , struct V_9 * V_10 ,
struct V_195 * V_196 , T_10 V_224 ,
T_5 V_256 , T_8 V_257 ,
T_8 V_258 )
{
struct V_8 * V_34 = V_4 -> V_8 ;
struct V_124 * V_135 ;
struct V_71 * V_72 ;
V_135 = V_34 -> V_259 ( V_10 , V_257 , V_258 ,
V_256 ) ;
if ( ! V_135 )
return - V_114 ;
V_135 -> V_171 = V_224 ;
V_72 = F_58 ( V_135 ) ;
V_196 -> V_204 . V_254 . V_77 = V_72 -> V_77 ;
V_196 -> V_204 . V_254 . V_126 = V_135 -> V_126 ;
F_60 ( V_135 ,
L_58 ) ;
return 0 ;
}
static int
F_146 ( struct V_8 * V_34 , struct V_195 * V_196 )
{
struct V_122 * V_123 ;
struct V_124 * V_135 ;
V_135 = F_48 ( V_196 -> V_242 . V_260 . V_126 ) ;
if ( ! V_135 ) {
F_12 ( V_18 L_59 ,
V_196 -> V_242 . V_260 . V_126 ) ;
return - V_199 ;
}
V_123 = V_34 -> V_261 ( V_135 , V_196 -> V_242 . V_260 . V_129 ) ;
if ( ! V_123 ) {
F_80 ( V_18 , V_135 ,
L_60 ) ;
return - V_114 ;
}
V_196 -> V_204 . V_262 . V_126 = V_135 -> V_126 ;
V_196 -> V_204 . V_262 . V_129 = V_123 -> V_129 ;
F_114 ( V_123 , L_61 ) ;
return 0 ;
}
static int
F_147 ( struct V_8 * V_34 , struct V_195 * V_196 )
{
struct V_122 * V_123 ;
V_123 = F_52 ( V_196 -> V_242 . V_263 . V_126 , V_196 -> V_242 . V_263 . V_129 ) ;
if ( ! V_123 )
return - V_199 ;
F_114 ( V_123 , L_62 ) ;
if ( V_34 -> V_264 )
V_34 -> V_264 ( V_123 ) ;
return 0 ;
}
static int
F_148 ( struct V_8 * V_34 , struct V_195 * V_196 )
{
char * V_12 = ( char * ) V_196 + sizeof( * V_196 ) ;
struct V_122 * V_123 ;
struct V_124 * V_135 ;
int V_15 = 0 , V_134 = 0 ;
V_135 = F_48 ( V_196 -> V_242 . V_265 . V_126 ) ;
V_123 = F_52 ( V_196 -> V_242 . V_265 . V_126 , V_196 -> V_242 . V_265 . V_129 ) ;
if ( ! V_123 || ! V_135 )
return - V_199 ;
switch ( V_196 -> V_242 . V_265 . V_35 ) {
case V_266 :
sscanf ( V_12 , L_63 , & V_134 ) ;
V_135 -> V_159 = V_134 ;
break;
default:
V_15 = V_34 -> V_265 ( V_123 , V_196 -> V_242 . V_265 . V_35 ,
V_12 , V_196 -> V_242 . V_265 . V_198 ) ;
}
return V_15 ;
}
static int F_149 ( struct V_8 * V_34 ,
struct V_195 * V_196 , int V_267 )
{
struct V_9 * V_10 ;
struct V_268 * V_269 ;
struct V_71 * V_72 = NULL ;
int V_270 , V_15 = 0 ;
if ( ! V_34 -> V_271 )
return - V_199 ;
if ( V_267 == V_272 ) {
V_72 = F_150 ( V_196 -> V_242 . V_273 . V_77 ) ;
if ( ! V_72 ) {
F_12 ( V_18 L_64
L_65 ,
V_196 -> V_242 . V_273 . V_77 ) ;
return - V_274 ;
}
V_270 = V_196 -> V_242 . V_273 . V_270 ;
} else
V_270 = V_196 -> V_242 . V_271 . V_270 ;
V_269 = (struct V_268 * ) ( ( char * ) V_196 + sizeof( * V_196 ) ) ;
V_10 = V_34 -> V_271 ( V_72 , V_269 , V_270 ) ;
if ( F_151 ( V_10 ) ) {
V_15 = F_152 ( V_10 ) ;
goto V_275;
}
V_196 -> V_204 . V_276 . V_26 = V_10 -> V_11 ;
V_275:
if ( V_72 )
F_59 ( V_72 ) ;
return V_15 ;
}
static int F_153 ( struct V_8 * V_34 ,
T_3 V_277 )
{
struct V_122 * V_123 ;
struct V_9 * V_10 ;
if ( ! V_34 -> V_278 )
return - V_199 ;
V_10 = F_20 ( V_277 ) ;
if ( ! V_10 )
return - V_199 ;
V_123 = V_10 -> V_123 ;
if ( V_123 ) {
F_69 ( & V_123 -> V_178 ) ;
V_123 -> V_10 = NULL ;
F_71 ( & V_123 -> V_178 ) ;
}
V_34 -> V_278 ( V_10 ) ;
return 0 ;
}
static int
F_154 ( struct V_8 * V_34 ,
struct V_195 * V_196 , int V_267 )
{
struct V_9 * V_10 ;
int V_252 = 0 ;
switch ( V_267 ) {
case V_272 :
case V_279 :
V_252 = F_149 ( V_34 , V_196 , V_267 ) ;
break;
case V_280 :
if ( ! V_34 -> V_281 )
return - V_199 ;
V_10 = F_20 ( V_196 -> V_242 . V_281 . V_277 ) ;
if ( ! V_10 )
return - V_199 ;
V_196 -> V_204 . V_282 = V_34 -> V_281 ( V_10 ,
V_196 -> V_242 . V_281 . V_283 ) ;
break;
case V_284 :
V_252 = F_153 ( V_34 ,
V_196 -> V_242 . V_278 . V_277 ) ;
break;
}
return V_252 ;
}
static int
F_155 ( struct V_8 * V_34 ,
struct V_195 * V_196 )
{
struct V_71 * V_72 ;
struct V_268 * V_269 ;
int V_15 ;
if ( ! V_34 -> V_285 )
return - V_199 ;
V_72 = F_150 ( V_196 -> V_242 . V_285 . V_77 ) ;
if ( ! V_72 ) {
F_12 ( V_18 L_66 ,
V_196 -> V_242 . V_285 . V_77 ) ;
return - V_274 ;
}
V_269 = (struct V_268 * ) ( ( char * ) V_196 + sizeof( * V_196 ) ) ;
V_15 = V_34 -> V_285 ( V_72 , V_196 -> V_242 . V_285 . type ,
V_196 -> V_242 . V_285 . V_286 , V_269 ) ;
F_59 ( V_72 ) ;
return V_15 ;
}
static int
F_156 ( struct V_8 * V_34 ,
struct V_195 * V_196 )
{
char * V_12 = ( char * ) V_196 + sizeof( * V_196 ) ;
struct V_71 * V_72 ;
int V_15 ;
if ( ! V_34 -> V_287 )
return - V_288 ;
V_72 = F_150 ( V_196 -> V_242 . V_287 . V_77 ) ;
if ( ! V_72 ) {
F_12 ( V_18 L_67 ,
V_196 -> V_242 . V_287 . V_77 ) ;
return - V_274 ;
}
V_15 = V_34 -> V_287 ( V_72 , V_196 -> V_242 . V_287 . V_35 ,
V_12 , V_196 -> V_242 . V_287 . V_198 ) ;
F_59 ( V_72 ) ;
return V_15 ;
}
static int
F_157 ( struct V_8 * V_34 , struct V_195 * V_196 )
{
struct V_71 * V_72 ;
struct V_289 * V_290 ;
int V_15 ;
if ( ! V_34 -> V_291 )
return - V_288 ;
V_72 = F_150 ( V_196 -> V_242 . V_291 . V_77 ) ;
if ( ! V_72 ) {
F_12 ( V_18 L_68 ,
V_196 -> V_242 . V_291 . V_77 ) ;
return - V_274 ;
}
V_290 = (struct V_289 * ) ( ( char * ) V_196 + sizeof( * V_196 ) ) ;
V_15 = V_34 -> V_291 ( V_72 , V_290 ) ;
F_59 ( V_72 ) ;
return V_15 ;
}
static int
F_158 ( struct V_8 * V_34 ,
struct V_195 * V_196 , T_5 V_198 )
{
char * V_12 = ( char * ) V_196 + sizeof( * V_196 ) ;
struct V_71 * V_72 ;
int V_15 ;
if ( ! V_34 -> V_292 )
return - V_288 ;
V_72 = F_150 ( V_196 -> V_242 . V_293 . V_77 ) ;
if ( ! V_72 ) {
F_12 ( V_18 L_69 ,
V_196 -> V_242 . V_293 . V_77 ) ;
return - V_274 ;
}
V_15 = V_34 -> V_292 ( V_72 , V_12 , V_198 ) ;
F_59 ( V_72 ) ;
return V_15 ;
}
static int
F_159 ( struct V_8 * V_34 , struct V_195 * V_196 )
{
struct V_71 * V_72 ;
struct V_268 * V_269 ;
int V_15 ;
if ( ! V_34 -> V_294 )
return - V_288 ;
V_72 = F_150 ( V_196 -> V_242 . V_295 . V_77 ) ;
if ( ! V_72 ) {
F_12 ( V_18 L_70 ,
V_196 -> V_242 . V_295 . V_77 ) ;
return - V_274 ;
}
V_269 = (struct V_268 * ) ( ( char * ) V_196 + sizeof( * V_196 ) ) ;
V_15 = V_34 -> V_294 ( V_72 , V_196 -> V_242 . V_295 . V_73 ,
V_196 -> V_242 . V_295 . V_48 ,
V_196 -> V_242 . V_295 . V_296 ,
V_196 -> V_242 . V_295 . V_224 ,
V_269 ) ;
F_59 ( V_72 ) ;
return V_15 ;
}
static int
F_160 ( struct V_8 * V_34 , struct V_193 * V_194 )
{
struct V_195 * V_196 = F_134 ( V_194 ) ;
struct V_71 * V_72 = NULL ;
struct V_297 * V_298 ;
struct V_3 * V_4 ;
struct V_185 * V_299 ;
struct V_193 * V_300 ;
struct V_195 * V_301 ;
T_5 V_302 ;
int V_198 , V_15 = 0 ;
char * V_7 ;
if ( ! V_34 -> V_303 )
return - V_199 ;
V_4 = F_125 ( V_34 ) ;
if ( ! V_4 )
return - V_199 ;
V_302 = ( V_196 -> V_242 . V_303 . V_304 * sizeof( * V_298 ) ) ;
V_198 = F_129 ( sizeof( * V_196 ) + V_302 ) ;
V_72 = F_150 ( V_196 -> V_242 . V_303 . V_77 ) ;
if ( ! V_72 ) {
F_12 ( V_18 L_71 ,
V_305 , V_196 -> V_242 . V_303 . V_77 ) ;
return - V_274 ;
}
do {
int V_245 ;
V_299 = F_130 ( V_198 , V_19 ) ;
if ( ! V_299 ) {
F_12 ( V_18 L_72 ) ;
V_15 = - V_114 ;
goto V_306;
}
V_300 = F_133 ( V_299 , 0 , 0 , 0 ,
( V_198 - sizeof( * V_300 ) ) , 0 ) ;
V_301 = F_134 ( V_300 ) ;
memset ( V_301 , 0 , sizeof( * V_301 ) ) ;
V_301 -> V_202 = F_5 ( V_34 ) ;
V_301 -> type = V_194 -> V_246 ;
V_301 -> V_242 . V_303 . V_77 = V_196 -> V_242 . V_303 . V_77 ;
V_301 -> V_242 . V_303 . V_307 = V_196 -> V_242 . V_303 . V_307 ;
V_301 -> V_242 . V_303 . V_304 = V_196 -> V_242 . V_303 . V_304 ;
V_7 = ( char * ) ( ( char * ) V_301 + sizeof( * V_301 ) ) ;
memset ( V_7 , 0 , V_302 ) ;
V_15 = V_34 -> V_303 ( V_72 , V_196 -> V_242 . V_303 . V_307 ,
& V_301 -> V_242 . V_303 . V_304 , V_7 ) ;
V_245 = F_129 ( sizeof( * V_196 ) + V_302 ) ;
F_142 ( V_299 , F_143 ( V_245 ) ) ;
V_300 -> V_248 = V_245 ;
V_15 = F_126 ( V_299 , V_206 ,
V_19 ) ;
} while ( V_15 < 0 && V_15 != - V_249 );
V_306:
F_59 ( V_72 ) ;
return V_15 ;
}
static int F_161 ( struct V_8 * V_34 ,
struct V_195 * V_196 )
{
struct V_71 * V_72 ;
int V_15 = 0 ;
if ( ! V_34 -> V_308 )
return - V_288 ;
V_72 = F_150 ( V_196 -> V_242 . V_308 . V_77 ) ;
if ( ! V_72 ) {
F_12 ( V_18 L_73 ,
V_305 , V_196 -> V_242 . V_308 . V_77 ) ;
return - V_274 ;
}
V_15 = V_34 -> V_308 ( V_72 , V_196 -> V_242 . V_308 . V_307 ) ;
F_59 ( V_72 ) ;
return V_15 ;
}
static int
F_162 ( struct V_185 * V_186 , struct V_193 * V_194 , T_5 * V_187 )
{
int V_15 = 0 ;
struct V_195 * V_196 = F_134 ( V_194 ) ;
struct V_8 * V_34 = NULL ;
struct V_3 * V_4 ;
struct V_124 * V_135 ;
struct V_122 * V_123 ;
struct V_9 * V_10 = NULL ;
if ( V_194 -> V_246 == V_309 )
* V_187 = V_211 ;
else
* V_187 = V_206 ;
V_4 = F_125 ( F_163 ( V_196 -> V_202 ) ) ;
if ( ! V_4 )
return - V_199 ;
V_34 = V_4 -> V_8 ;
if ( ! F_164 ( V_34 -> V_310 ) )
return - V_199 ;
switch ( V_194 -> V_246 ) {
case V_311 :
V_15 = F_145 ( V_4 , V_10 , V_196 ,
F_165 ( V_186 ) . V_312 ,
V_196 -> V_242 . V_313 . V_256 ,
V_196 -> V_242 . V_313 . V_257 ,
V_196 -> V_242 . V_313 . V_258 ) ;
break;
case V_314 :
V_10 = F_20 ( V_196 -> V_242 . V_315 . V_277 ) ;
if ( ! V_10 ) {
V_15 = - V_199 ;
break;
}
V_15 = F_145 ( V_4 , V_10 , V_196 ,
F_165 ( V_186 ) . V_312 ,
V_196 -> V_242 . V_315 . V_256 ,
V_196 -> V_242 . V_315 . V_257 ,
V_196 -> V_242 . V_315 . V_258 ) ;
break;
case V_316 :
V_135 = F_48 ( V_196 -> V_242 . V_253 . V_126 ) ;
if ( V_135 )
V_34 -> V_317 ( V_135 ) ;
else
V_15 = - V_199 ;
break;
case V_318 :
V_135 = F_48 ( V_196 -> V_242 . V_253 . V_126 ) ;
if ( V_135 )
F_84 ( F_58 ( V_135 ) ,
& V_135 -> V_167 ) ;
else
V_15 = - V_199 ;
break;
case V_319 :
V_15 = F_146 ( V_34 , V_196 ) ;
break;
case V_320 :
V_15 = F_147 ( V_34 , V_196 ) ;
break;
case V_321 :
V_135 = F_48 ( V_196 -> V_242 . V_322 . V_126 ) ;
V_123 = F_52 ( V_196 -> V_242 . V_322 . V_126 , V_196 -> V_242 . V_322 . V_129 ) ;
if ( V_123 && V_123 -> V_10 )
F_153 ( V_34 , V_123 -> V_10 -> V_11 ) ;
if ( ! V_135 || ! V_123 ) {
V_15 = - V_199 ;
break;
}
V_196 -> V_204 . V_282 = V_34 -> V_323 ( V_135 , V_123 ,
V_196 -> V_242 . V_322 . V_324 ,
V_196 -> V_242 . V_322 . V_325 ) ;
if ( V_196 -> V_204 . V_282 || ! V_34 -> V_271 )
break;
V_10 = F_20 ( V_196 -> V_242 . V_322 . V_324 ) ;
if ( V_10 ) {
V_10 -> V_123 = V_123 ;
F_69 ( & V_123 -> V_178 ) ;
V_123 -> V_10 = V_10 ;
F_71 ( & V_123 -> V_178 ) ;
} else
F_132 ( V_18 , V_123 ,
L_74
L_75 ) ;
break;
case V_326 :
V_15 = F_148 ( V_34 , V_196 ) ;
break;
case V_327 :
V_123 = F_52 ( V_196 -> V_242 . V_328 . V_126 , V_196 -> V_242 . V_328 . V_129 ) ;
if ( V_123 )
V_196 -> V_204 . V_282 = V_34 -> V_328 ( V_123 ) ;
else
V_15 = - V_199 ;
break;
case V_329 :
V_123 = F_52 ( V_196 -> V_242 . V_330 . V_126 , V_196 -> V_242 . V_330 . V_129 ) ;
if ( V_123 )
V_34 -> V_330 ( V_123 , V_196 -> V_242 . V_330 . V_331 ) ;
else
V_15 = - V_199 ;
break;
case V_332 :
V_123 = F_52 ( V_196 -> V_242 . V_333 . V_126 , V_196 -> V_242 . V_333 . V_129 ) ;
if ( V_123 )
V_196 -> V_204 . V_282 = V_34 -> V_333 ( V_123 ,
(struct V_190 * ) ( ( char * ) V_196 + sizeof( * V_196 ) ) ,
( char * ) V_196 + sizeof( * V_196 ) + V_196 -> V_242 . V_333 . V_334 ,
V_196 -> V_242 . V_333 . V_192 ) ;
else
V_15 = - V_199 ;
break;
case V_335 :
V_15 = F_140 ( V_34 , V_194 ) ;
break;
case V_279 :
case V_280 :
case V_284 :
case V_272 :
V_15 = F_154 ( V_34 , V_196 , V_194 -> V_246 ) ;
break;
case V_336 :
V_15 = F_155 ( V_34 , V_196 ) ;
break;
case V_337 :
V_15 = F_156 ( V_34 , V_196 ) ;
break;
case V_309 :
V_15 = F_157 ( V_34 , V_196 ) ;
break;
case V_338 :
V_15 = F_158 ( V_34 , V_196 ,
F_166 ( V_194 , sizeof( * V_196 ) ) ) ;
break;
case V_339 :
V_15 = F_159 ( V_34 , V_196 ) ;
break;
case V_340 :
V_15 = F_160 ( V_34 , V_194 ) ;
break;
case V_341 :
V_15 = F_161 ( V_34 , V_196 ) ;
break;
default:
V_15 = - V_288 ;
break;
}
F_167 ( V_34 -> V_310 ) ;
return V_15 ;
}
static void
F_168 ( struct V_185 * V_186 )
{
F_69 ( & V_342 ) ;
while ( V_186 -> V_198 >= F_129 ( 0 ) ) {
int V_15 ;
T_5 V_343 ;
struct V_193 * V_194 ;
struct V_195 * V_196 ;
T_5 V_187 ;
V_194 = F_169 ( V_186 ) ;
if ( V_194 -> V_248 < sizeof( * V_194 ) ||
V_186 -> V_198 < V_194 -> V_248 ) {
break;
}
V_196 = F_134 ( V_194 ) ;
V_343 = F_143 ( V_194 -> V_248 ) ;
if ( V_343 > V_186 -> V_198 )
V_343 = V_186 -> V_198 ;
V_15 = F_162 ( V_186 , V_194 , & V_187 ) ;
if ( V_15 ) {
V_196 -> type = V_344 ;
V_196 -> V_345 = V_15 ;
}
do {
if ( V_196 -> type == V_335 && ! V_15 )
break;
if ( V_196 -> type == V_340 && ! V_15 )
break;
V_15 = F_139 ( V_187 , V_194 -> V_346 ,
V_194 -> V_246 , 0 , 0 , V_196 , sizeof( * V_196 ) ) ;
} while ( V_15 < 0 && V_15 != - V_249 && V_15 != - V_101 );
F_170 ( V_186 , V_343 ) ;
}
F_71 ( & V_342 ) ;
}
static T_4 F_171 ( struct V_30 * V_22 ,
struct V_31 * V_6 , int V_32 )
{
struct V_1 * V_118 = F_25 ( V_22 , struct V_1 , V_22 ) ;
struct V_122 * V_123 = F_172 ( V_118 ) ;
struct V_8 * V_33 = V_123 -> V_34 ;
int V_35 ;
if ( V_6 == & V_347 . V_6 )
V_35 = V_348 ;
else if ( V_6 == & V_349 . V_6 )
V_35 = V_350 ;
else if ( V_6 == & V_351 . V_6 )
V_35 = V_352 ;
else if ( V_6 == & V_353 . V_6 )
V_35 = V_354 ;
else if ( V_6 == & V_355 . V_6 )
V_35 = V_356 ;
else if ( V_6 == & V_357 . V_6 )
V_35 = V_358 ;
else if ( V_6 == & V_359 . V_6 )
V_35 = V_360 ;
else if ( V_6 == & V_361 . V_6 )
V_35 = V_362 ;
else if ( V_6 == & V_363 . V_6 )
V_35 = V_364 ;
else if ( V_6 == & V_365 . V_6 )
V_35 = V_366 ;
else if ( V_6 == & V_367 . V_6 )
V_35 = V_368 ;
else if ( V_6 == & V_369 . V_6 )
V_35 = V_370 ;
else if ( V_6 == & V_371 . V_6 )
V_35 = V_372 ;
else {
F_26 ( 1 , L_76 ) ;
return 0 ;
}
return V_33 -> V_69 ( V_373 , V_35 ) ;
}
static T_1
F_173 ( struct V_1 * V_2 , struct V_5 * V_6 ,
char * V_7 )
{
struct V_124 * V_135 = F_47 ( V_2 -> V_29 ) ;
return sprintf ( V_7 , L_77 , F_53 ( V_135 -> V_131 ) ) ;
}
static T_1
F_174 ( struct V_1 * V_2 , struct V_5 * V_6 ,
char * V_7 )
{
struct V_124 * V_135 = F_47 ( V_2 -> V_29 ) ;
return sprintf ( V_7 , L_78 , V_135 -> V_171 ) ;
}
static T_4 F_175 ( struct V_30 * V_22 ,
struct V_31 * V_6 , int V_32 )
{
struct V_1 * V_118 = F_25 ( V_22 , struct V_1 , V_22 ) ;
struct V_124 * V_135 = F_176 ( V_118 ) ;
struct V_8 * V_33 = V_135 -> V_34 ;
int V_35 ;
if ( V_6 == & V_374 . V_6 )
V_35 = V_375 ;
else if ( V_6 == & V_376 . V_6 )
V_35 = V_377 ;
else if ( V_6 == & V_378 . V_6 )
V_35 = V_379 ;
else if ( V_6 == & V_380 . V_6 )
V_35 = V_381 ;
else if ( V_6 == & V_382 . V_6 )
V_35 = V_383 ;
else if ( V_6 == & V_384 . V_6 )
V_35 = V_385 ;
else if ( V_6 == & V_386 . V_6 )
V_35 = V_387 ;
else if ( V_6 == & V_388 . V_6 )
V_35 = V_389 ;
else if ( V_6 == & V_390 . V_6 )
V_35 = V_391 ;
else if ( V_6 == & V_392 . V_6 )
V_35 = V_393 ;
else if ( V_6 == & V_394 . V_6 )
V_35 = V_395 ;
else if ( V_6 == & V_396 . V_6 )
V_35 = V_397 ;
else if ( V_6 == & V_398 . V_6 )
V_35 = V_399 ;
else if ( V_6 == & V_400 . V_6 )
V_35 = V_401 ;
else if ( V_6 == & V_402 . V_6 )
V_35 = V_403 ;
else if ( V_6 == & V_404 . V_6 )
V_35 = V_405 ;
else if ( V_6 == & V_406 . V_6 )
V_35 = V_407 ;
else if ( V_6 == & V_408 . V_6 )
V_35 = V_409 ;
else if ( V_6 == & V_410 . V_6 )
V_35 = V_411 ;
else if ( V_6 == & V_412 . V_6 )
V_35 = V_413 ;
else if ( V_6 == & V_414 . V_6 )
V_35 = V_415 ;
else if ( V_6 == & V_416 . V_6 )
V_35 = V_417 ;
else if ( V_6 == & V_418 . V_6 )
V_35 = V_419 ;
else if ( V_6 == & V_420 . V_6 )
return V_421 | V_422 ;
else if ( V_6 == & V_423 . V_6 )
return V_421 ;
else if ( V_6 == & V_424 . V_6 )
return V_421 ;
else {
F_26 ( 1 , L_79 ) ;
return 0 ;
}
return V_33 -> V_69 ( V_373 , V_35 ) ;
}
static T_4 F_177 ( struct V_30 * V_22 ,
struct V_31 * V_6 , int V_32 )
{
struct V_1 * V_118 = F_25 ( V_22 , struct V_1 , V_22 ) ;
struct V_71 * V_72 = F_178 ( V_118 ) ;
struct V_3 * V_4 = F_32 ( V_72 -> V_88 ) ;
int V_35 ;
if ( V_6 == & V_425 . V_6 )
V_35 = V_426 ;
else if ( V_6 == & V_427 . V_6 )
V_35 = V_428 ;
else if ( V_6 == & V_429 . V_6 )
V_35 = V_430 ;
else if ( V_6 == & V_431 . V_6 )
V_35 = V_432 ;
else if ( V_6 == & V_433 . V_6 )
V_35 = V_434 ;
else if ( V_6 == & V_435 . V_6 )
V_35 = V_436 ;
else {
F_26 ( 1 , L_80 ) ;
return 0 ;
}
return V_4 -> V_8 -> V_69 ( V_437 , V_35 ) ;
}
char * F_179 ( struct V_71 * V_72 )
{
int V_32 ;
char * V_438 = L_81 ;
struct V_107 * V_108 = V_72 -> V_119 ;
T_5 V_439 = V_108 -> V_439 ;
for ( V_32 = 0 ; V_32 < F_54 ( V_440 ) ; V_32 ++ ) {
if ( V_440 [ V_32 ] . V_134 & V_439 ) {
V_438 = V_440 [ V_32 ] . V_132 ;
break;
}
}
return V_438 ;
}
char * F_180 ( struct V_71 * V_72 )
{
int V_32 ;
char * V_131 = L_81 ;
struct V_107 * V_108 = V_72 -> V_119 ;
T_5 V_441 = V_108 -> V_441 ;
for ( V_32 = 0 ; V_32 < F_54 ( V_442 ) ; V_32 ++ ) {
if ( V_442 [ V_32 ] . V_134 & V_441 ) {
V_131 = V_442 [ V_32 ] . V_132 ;
break;
}
}
return V_131 ;
}
static int F_181 ( struct V_443 * V_444 ,
struct V_1 * V_2 )
{
struct V_124 * V_135 ;
struct V_71 * V_72 ;
struct V_3 * V_4 ;
if ( ! F_61 ( V_2 ) )
return 0 ;
V_135 = F_47 ( V_2 ) ;
V_72 = F_58 ( V_135 ) ;
if ( ! V_72 -> V_88 )
return 0 ;
V_4 = F_32 ( V_72 -> V_88 ) ;
if ( V_4 -> V_445 . V_446 . V_20 != & V_447 . V_20 )
return 0 ;
return & V_4 -> V_445 . V_446 == V_444 ;
}
static int F_182 ( struct V_443 * V_444 ,
struct V_1 * V_2 )
{
struct V_124 * V_135 ;
struct V_122 * V_123 ;
struct V_71 * V_72 ;
struct V_3 * V_4 ;
if ( ! F_115 ( V_2 ) )
return 0 ;
V_123 = F_113 ( V_2 ) ;
V_135 = F_47 ( V_123 -> V_2 . V_29 ) ;
V_72 = F_58 ( V_135 ) ;
if ( ! V_72 -> V_88 )
return 0 ;
V_4 = F_32 ( V_72 -> V_88 ) ;
if ( V_4 -> V_448 . V_446 . V_20 != & V_449 . V_20 )
return 0 ;
return & V_4 -> V_448 . V_446 == V_444 ;
}
static int F_183 ( struct V_443 * V_444 ,
struct V_1 * V_2 )
{
struct V_71 * V_72 ;
struct V_3 * V_4 ;
if ( ! F_184 ( V_2 ) )
return 0 ;
V_72 = F_41 ( V_2 ) ;
if ( ! V_72 -> V_88 ||
V_72 -> V_88 -> V_450 . V_446 . V_20 != & V_451 . V_20 )
return 0 ;
V_4 = F_32 ( V_72 -> V_88 ) ;
return & V_4 -> V_33 . V_450 . V_446 == V_444 ;
}
struct V_452 *
F_185 ( struct V_8 * V_183 )
{
struct V_3 * V_4 ;
unsigned long V_127 ;
int V_15 ;
F_33 ( ! V_183 ) ;
V_4 = F_125 ( V_183 ) ;
if ( V_4 )
return NULL ;
V_4 = F_13 ( sizeof( * V_4 ) , V_19 ) ;
if ( ! V_4 )
return NULL ;
F_99 ( & V_4 -> V_453 ) ;
V_4 -> V_8 = V_183 ;
V_4 -> V_33 . V_454 = F_72 ;
V_4 -> V_33 . V_455 = 1 ;
V_4 -> V_2 . V_20 = & V_456 ;
F_14 ( & V_4 -> V_2 , L_82 , V_183 -> V_132 ) ;
V_15 = F_15 ( & V_4 -> V_2 ) ;
if ( V_15 )
goto V_457;
V_15 = F_16 ( & V_4 -> V_2 . V_22 , & V_458 ) ;
if ( V_15 )
goto V_24;
V_4 -> V_33 . V_450 . V_446 . V_20 = & V_451 . V_20 ;
V_4 -> V_33 . V_450 . V_446 . V_459 = F_183 ;
V_4 -> V_33 . V_450 . V_446 . V_460 = & V_461 ;
V_4 -> V_33 . V_462 = sizeof( struct V_107 ) ;
F_186 ( & V_4 -> V_33 . V_450 ) ;
V_4 -> V_448 . V_446 . V_20 = & V_449 . V_20 ;
V_4 -> V_448 . V_446 . V_459 = F_182 ;
V_4 -> V_448 . V_446 . V_460 = & V_463 ;
F_186 ( & V_4 -> V_448 ) ;
V_4 -> V_445 . V_446 . V_20 = & V_447 . V_20 ;
V_4 -> V_445 . V_446 . V_459 = F_181 ;
V_4 -> V_445 . V_446 . V_460 = & V_464 ;
F_186 ( & V_4 -> V_445 ) ;
F_49 ( & V_184 , V_127 ) ;
F_109 ( & V_4 -> V_453 , & V_465 ) ;
F_51 ( & V_184 , V_127 ) ;
F_12 ( V_466 L_83 , V_183 -> V_132 ) ;
return & V_4 -> V_33 ;
V_24:
F_17 ( & V_4 -> V_2 ) ;
return NULL ;
V_457:
F_3 ( V_4 ) ;
return NULL ;
}
int F_187 ( struct V_8 * V_183 )
{
struct V_3 * V_4 ;
unsigned long V_127 ;
F_33 ( ! V_183 ) ;
F_69 ( & V_342 ) ;
V_4 = F_125 ( V_183 ) ;
F_33 ( ! V_4 ) ;
F_49 ( & V_184 , V_127 ) ;
F_119 ( & V_4 -> V_453 ) ;
F_51 ( & V_184 , V_127 ) ;
F_188 ( & V_4 -> V_448 ) ;
F_188 ( & V_4 -> V_445 ) ;
F_188 ( & V_4 -> V_33 . V_450 ) ;
F_19 ( & V_4 -> V_2 . V_22 , & V_458 ) ;
F_17 ( & V_4 -> V_2 ) ;
F_71 ( & V_342 ) ;
return 0 ;
}
static T_11 int F_189 ( void )
{
int V_15 ;
struct V_467 V_468 = {
. V_469 = 1 ,
. V_470 = F_168 ,
} ;
F_12 ( V_158 L_84 ,
V_471 ) ;
F_42 ( & V_173 , 0 ) ;
V_15 = F_190 ( & V_456 ) ;
if ( V_15 )
return V_15 ;
V_15 = F_190 ( & V_17 ) ;
if ( V_15 )
goto V_472;
V_15 = F_190 ( & V_75 ) ;
if ( V_15 )
goto V_473;
V_15 = F_191 ( & V_451 ) ;
if ( V_15 )
goto V_474;
V_15 = F_191 ( & V_449 ) ;
if ( V_15 )
goto V_475;
V_15 = F_191 ( & V_447 ) ;
if ( V_15 )
goto V_476;
V_189 = F_192 ( & V_477 , V_478 , & V_468 ) ;
if ( ! V_189 ) {
V_15 = - V_479 ;
goto V_480;
}
V_164 = F_193 ( L_85 ) ;
if ( ! V_164 )
goto V_481;
return 0 ;
V_481:
F_194 ( V_189 ) ;
V_480:
F_195 ( & V_447 ) ;
V_476:
F_195 ( & V_449 ) ;
V_475:
F_195 ( & V_451 ) ;
V_474:
F_196 ( & V_75 ) ;
V_473:
F_196 ( & V_17 ) ;
V_472:
F_196 ( & V_456 ) ;
return V_15 ;
}
static void T_12 F_197 ( void )
{
F_198 ( V_164 ) ;
F_194 ( V_189 ) ;
F_195 ( & V_449 ) ;
F_195 ( & V_447 ) ;
F_195 ( & V_451 ) ;
F_196 ( & V_17 ) ;
F_196 ( & V_75 ) ;
F_196 ( & V_456 ) ;
}
