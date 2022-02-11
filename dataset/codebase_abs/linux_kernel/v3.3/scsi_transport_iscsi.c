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
static int F_61 ( const struct V_1 * V_2 )
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
F_81 ( & V_135 -> V_2 ) ;
F_60 ( V_135 , L_15 ) ;
}
static void F_82 ( struct V_151 * V_152 )
{
struct V_124 * V_135 =
F_25 ( V_152 , struct V_124 ,
V_160 ) ;
struct V_71 * V_72 = F_58 ( V_135 ) ;
struct V_107 * V_108 = V_72 -> V_119 ;
unsigned long V_127 ;
F_60 ( V_135 , L_16 ) ;
F_83 ( & V_135 -> V_157 ) ;
F_49 ( & V_135 -> V_136 , V_127 ) ;
V_135 -> V_131 = V_137 ;
F_51 ( & V_135 -> V_136 , V_127 ) ;
F_81 ( & V_135 -> V_2 ) ;
if ( V_72 -> V_97 -> V_161 ) {
if ( F_84 ( V_72 , & V_135 -> V_153 ) )
F_85 ( & V_108 -> V_120 ) ;
}
F_60 ( V_135 , L_17 ) ;
}
void F_86 ( struct V_124 * V_135 )
{
F_87 ( V_162 , & V_135 -> V_160 ) ;
F_88 ( V_162 ) ;
}
static void F_89 ( struct V_151 * V_152 )
{
struct V_124 * V_135 =
F_25 ( V_152 , struct V_124 ,
V_163 ) ;
unsigned long V_127 ;
F_60 ( V_135 , L_18 ) ;
F_49 ( & V_135 -> V_136 , V_127 ) ;
V_135 -> V_131 = V_138 ;
F_51 ( & V_135 -> V_136 , V_127 ) ;
F_90 ( & V_135 -> V_2 ) ;
F_60 ( V_135 , L_19 ) ;
if ( V_135 -> V_159 >= 0 )
F_91 ( V_162 ,
& V_135 -> V_157 ,
V_135 -> V_159 * V_164 ) ;
}
void F_92 ( struct V_124 * V_135 )
{
F_87 ( V_162 , & V_135 -> V_163 ) ;
}
static void F_93 ( struct V_151 * V_152 )
{
struct V_124 * V_135 =
F_25 ( V_152 , struct V_124 ,
V_165 ) ;
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
if ( V_135 -> V_166 )
F_94 ( & V_167 , V_146 ) ;
F_95 ( & V_135 -> V_2 ) ;
F_96 ( V_135 , V_168 ) ;
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
V_135 -> V_169 = - 1 ;
V_135 -> V_159 = 120 ;
V_135 -> V_131 = V_140 ;
F_98 ( & V_135 -> V_157 , F_79 ) ;
F_99 ( & V_135 -> V_170 ) ;
F_100 ( & V_135 -> V_160 , F_82 ) ;
F_100 ( & V_135 -> V_163 , F_89 ) ;
F_100 ( & V_135 -> V_165 , F_93 ) ;
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
V_135 -> V_126 = F_105 ( 1 , & V_171 ) ;
if ( V_146 == V_147 ) {
V_11 = F_106 ( & V_167 , 0 , 0 , V_19 ) ;
if ( V_11 < 0 ) {
F_80 ( V_18 , V_135 ,
L_23 ) ;
return V_11 ;
}
V_135 -> V_146 = ( unsigned int ) V_11 ;
V_135 -> V_166 = true ;
} else
V_135 -> V_146 = V_146 ;
F_14 ( & V_135 -> V_2 , L_24 , V_135 -> V_126 ) ;
V_15 = F_107 ( & V_135 -> V_2 ) ;
if ( V_15 ) {
F_80 ( V_18 , V_135 ,
L_25 ) ;
goto V_172;
}
F_108 ( & V_135 -> V_2 ) ;
F_49 ( & V_128 , V_127 ) ;
F_109 ( & V_135 -> V_170 , & V_173 ) ;
F_51 ( & V_128 , V_127 ) ;
F_96 ( V_135 , V_174 ) ;
F_60 ( V_135 , L_26 ) ;
return 0 ;
V_172:
if ( V_135 -> V_166 )
F_94 ( & V_167 , V_135 -> V_146 ) ;
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
F_119 ( & V_135 -> V_170 ) ;
F_51 ( & V_128 , V_127 ) ;
F_88 ( V_162 ) ;
if ( ! F_83 ( & V_135 -> V_157 ) )
F_88 ( V_162 ) ;
F_49 ( & V_135 -> V_136 , V_127 ) ;
V_135 -> V_131 = V_140 ;
F_51 ( & V_135 -> V_136 , V_127 ) ;
F_81 ( & V_135 -> V_2 ) ;
F_120 ( V_72 ) ;
F_93 ( & V_135 -> V_165 ) ;
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
F_96 ( V_135 , V_175 ) ;
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
F_43 ( & V_123 -> V_176 ) ;
F_99 ( & V_123 -> V_177 ) ;
V_123 -> V_34 = V_34 ;
V_123 -> V_129 = V_129 ;
if ( ! F_28 ( & V_135 -> V_2 ) )
goto V_178;
F_14 ( & V_123 -> V_2 , L_34 , V_135 -> V_126 , V_129 ) ;
V_123 -> V_2 . V_29 = & V_135 -> V_2 ;
V_123 -> V_2 . V_74 = F_112 ;
V_15 = F_15 ( & V_123 -> V_2 ) ;
if ( V_15 ) {
F_80 ( V_18 , V_135 , L_35
L_36 ) ;
goto V_179;
}
F_108 ( & V_123 -> V_2 ) ;
F_49 ( & V_130 , V_127 ) ;
F_109 ( & V_123 -> V_177 , & V_180 ) ;
F_51 ( & V_130 , V_127 ) ;
F_114 ( V_123 , L_37 ) ;
return V_123 ;
V_179:
F_21 ( & V_135 -> V_2 ) ;
V_178:
F_3 ( V_123 ) ;
return NULL ;
}
int F_117 ( struct V_122 * V_123 )
{
unsigned long V_127 ;
F_49 ( & V_130 , V_127 ) ;
F_119 ( & V_123 -> V_177 ) ;
F_51 ( & V_130 , V_127 ) ;
F_121 ( & V_123 -> V_2 ) ;
F_114 ( V_123 , L_38 ) ;
F_17 ( & V_123 -> V_2 ) ;
return 0 ;
}
static struct V_3 *
F_125 ( struct V_8 * V_181 )
{
struct V_3 * V_4 ;
unsigned long V_127 ;
F_49 ( & V_182 , V_127 ) ;
F_50 (priv, &iscsi_transports, list) {
if ( V_181 == V_4 -> V_8 ) {
F_51 ( & V_182 , V_127 ) ;
return V_4 ;
}
}
F_51 ( & V_182 , V_127 ) ;
return NULL ;
}
static int
F_126 ( struct V_183 * V_184 , T_5 V_185 , T_7 V_186 )
{
return F_127 ( V_187 , V_184 , 0 , V_185 , V_186 ) ;
}
int F_128 ( struct V_122 * V_123 , struct V_188 * V_189 ,
char * V_12 , T_5 V_190 )
{
struct V_191 * V_192 ;
struct V_183 * V_184 ;
struct V_193 * V_194 ;
char * V_195 ;
struct V_3 * V_4 ;
int V_196 = F_129 ( sizeof( * V_194 ) + sizeof( struct V_188 ) +
V_190 ) ;
V_4 = F_125 ( V_123 -> V_34 ) ;
if ( ! V_4 )
return - V_197 ;
V_184 = F_130 ( V_196 , V_198 ) ;
if ( ! V_184 ) {
F_131 ( V_123 , V_199 ) ;
F_132 ( V_18 , V_123 , L_39
L_40 ) ;
return - V_114 ;
}
V_192 = F_133 ( V_184 , 0 , 0 , 0 , ( V_196 - sizeof( * V_192 ) ) , 0 ) ;
V_194 = F_134 ( V_192 ) ;
memset ( V_194 , 0 , sizeof( * V_194 ) ) ;
V_194 -> V_200 = F_5 ( V_123 -> V_34 ) ;
V_194 -> type = V_201 ;
V_194 -> V_202 . V_203 . V_129 = V_123 -> V_129 ;
V_194 -> V_202 . V_203 . V_126 = F_46 ( V_123 ) ;
V_195 = ( char * ) V_194 + sizeof( * V_194 ) ;
memcpy ( V_195 , V_189 , sizeof( struct V_188 ) ) ;
memcpy ( V_195 + sizeof( struct V_188 ) , V_12 , V_190 ) ;
return F_126 ( V_184 , V_204 , V_198 ) ;
}
int F_135 ( struct V_71 * V_72 ,
struct V_8 * V_34 , T_5 type ,
char * V_12 , T_8 V_190 )
{
struct V_191 * V_192 ;
struct V_183 * V_184 ;
struct V_193 * V_194 ;
int V_196 = F_129 ( sizeof( * V_194 ) + V_190 ) ;
V_184 = F_130 ( V_196 , V_198 ) ;
if ( ! V_184 ) {
F_12 ( V_18 L_41 ) ;
return - V_114 ;
}
V_192 = F_133 ( V_184 , 0 , 0 , 0 , ( V_196 - sizeof( * V_192 ) ) , 0 ) ;
V_194 = F_134 ( V_192 ) ;
memset ( V_194 , 0 , sizeof( * V_194 ) ) ;
V_194 -> type = type ;
V_194 -> V_200 = F_5 ( V_34 ) ;
switch ( type ) {
case V_205 :
V_194 -> V_202 . V_206 . V_77 = V_72 -> V_77 ;
break;
case V_207 :
V_194 -> V_202 . V_208 . V_77 = V_72 -> V_77 ;
break;
}
memcpy ( ( char * ) V_194 + sizeof( * V_194 ) , V_12 , V_190 ) ;
return F_126 ( V_184 , V_209 , V_198 ) ;
}
void F_131 ( struct V_122 * V_123 , enum V_210 error )
{
struct V_191 * V_192 ;
struct V_183 * V_184 ;
struct V_193 * V_194 ;
struct V_3 * V_4 ;
int V_196 = F_129 ( sizeof( * V_194 ) ) ;
V_4 = F_125 ( V_123 -> V_34 ) ;
if ( ! V_4 )
return;
V_184 = F_130 ( V_196 , V_198 ) ;
if ( ! V_184 ) {
F_132 ( V_18 , V_123 , L_42
L_43 , error ) ;
return;
}
V_192 = F_133 ( V_184 , 0 , 0 , 0 , ( V_196 - sizeof( * V_192 ) ) , 0 ) ;
V_194 = F_134 ( V_192 ) ;
V_194 -> V_200 = F_5 ( V_123 -> V_34 ) ;
V_194 -> type = V_211 ;
V_194 -> V_202 . V_212 . error = error ;
V_194 -> V_202 . V_212 . V_129 = V_123 -> V_129 ;
V_194 -> V_202 . V_212 . V_126 = F_46 ( V_123 ) ;
F_126 ( V_184 , V_204 , V_198 ) ;
F_132 ( V_158 , V_123 , L_44 ,
error ) ;
}
void F_136 ( struct V_122 * V_123 ,
enum V_213 V_131 )
{
struct V_191 * V_192 ;
struct V_183 * V_184 ;
struct V_193 * V_194 ;
struct V_3 * V_4 ;
int V_196 = F_129 ( sizeof( * V_194 ) ) ;
V_4 = F_125 ( V_123 -> V_34 ) ;
if ( ! V_4 )
return;
V_184 = F_130 ( V_196 , V_198 ) ;
if ( ! V_184 ) {
F_132 ( V_18 , V_123 , L_42
L_45 , V_131 ) ;
return;
}
V_192 = F_133 ( V_184 , 0 , 0 , 0 , ( V_196 - sizeof( * V_192 ) ) , 0 ) ;
V_194 = F_134 ( V_192 ) ;
V_194 -> V_200 = F_5 ( V_123 -> V_34 ) ;
V_194 -> type = V_214 ;
V_194 -> V_202 . V_215 . V_131 = V_131 ;
V_194 -> V_202 . V_215 . V_129 = V_123 -> V_129 ;
V_194 -> V_202 . V_215 . V_126 = F_46 ( V_123 ) ;
F_126 ( V_184 , V_204 , V_198 ) ;
F_132 ( V_158 , V_123 , L_46 ,
V_131 ) ;
}
static int
F_137 ( T_5 V_185 , int V_216 , int type , int V_217 , int V_218 ,
void * V_219 , int V_220 )
{
struct V_183 * V_184 ;
struct V_191 * V_192 ;
int V_196 = F_129 ( V_220 ) ;
int V_127 = V_218 ? V_221 : 0 ;
int V_33 = V_217 ? V_222 : type ;
V_184 = F_130 ( V_196 , V_198 ) ;
if ( ! V_184 ) {
F_12 ( V_18 L_47 ) ;
return - V_114 ;
}
V_192 = F_133 ( V_184 , 0 , 0 , V_33 , ( V_196 - sizeof( * V_192 ) ) , 0 ) ;
V_192 -> V_223 = V_127 ;
memcpy ( F_134 ( V_192 ) , V_219 , V_220 ) ;
return F_126 ( V_184 , V_185 , V_198 ) ;
}
static int
F_138 ( struct V_8 * V_34 , struct V_191 * V_192 )
{
struct V_193 * V_194 = F_134 ( V_192 ) ;
struct V_224 * V_225 ;
struct V_183 * V_226 ;
struct V_122 * V_123 ;
struct V_191 * V_227 ;
struct V_193 * V_228 ;
struct V_3 * V_4 ;
int V_196 = F_129 ( sizeof( * V_194 ) +
sizeof( struct V_224 ) +
sizeof( struct V_229 ) *
V_230 ) ;
int V_15 = 0 ;
V_4 = F_125 ( V_34 ) ;
if ( ! V_4 )
return - V_197 ;
V_123 = F_52 ( V_194 -> V_231 . V_232 . V_126 , V_194 -> V_231 . V_232 . V_129 ) ;
if ( ! V_123 )
return - V_233 ;
do {
int V_234 ;
V_226 = F_130 ( V_196 , V_198 ) ;
if ( ! V_226 ) {
F_132 ( V_18 , V_123 , L_48
L_49 ) ;
return - V_114 ;
}
V_227 = F_133 ( V_226 , 0 , 0 , 0 ,
( V_196 - sizeof( * V_227 ) ) , 0 ) ;
V_228 = F_134 ( V_227 ) ;
memset ( V_228 , 0 , sizeof( * V_228 ) ) ;
V_228 -> V_200 = F_5 ( V_123 -> V_34 ) ;
V_228 -> type = V_192 -> V_235 ;
V_228 -> V_231 . V_232 . V_129 =
V_194 -> V_231 . V_232 . V_129 ;
V_228 -> V_231 . V_232 . V_126 =
V_194 -> V_231 . V_232 . V_126 ;
V_225 = (struct V_224 * )
( ( char * ) V_228 + sizeof( * V_228 ) ) ;
memset ( V_225 , 0 , sizeof( * V_225 ) ) ;
V_34 -> V_232 ( V_123 , V_225 ) ;
V_234 = F_129 ( sizeof( struct V_193 ) +
sizeof( struct V_224 ) +
sizeof( struct V_229 ) *
V_225 -> V_236 ) ;
V_234 -= sizeof( * V_227 ) ;
V_234 = F_139 ( V_234 ) ;
F_140 ( V_226 , F_141 ( V_234 ) ) ;
V_227 -> V_237 = V_234 ;
V_15 = F_126 ( V_226 , V_204 ,
V_198 ) ;
} while ( V_15 < 0 && V_15 != - V_238 );
return V_15 ;
}
int F_96 ( struct V_124 * V_135 ,
enum V_239 V_240 )
{
struct V_3 * V_4 ;
struct V_71 * V_72 ;
struct V_193 * V_194 ;
struct V_183 * V_184 ;
struct V_191 * V_192 ;
int V_241 , V_196 = F_129 ( sizeof( * V_194 ) ) ;
V_4 = F_125 ( V_135 -> V_34 ) ;
if ( ! V_4 )
return - V_197 ;
V_72 = F_58 ( V_135 ) ;
V_184 = F_130 ( V_196 , V_19 ) ;
if ( ! V_184 ) {
F_80 ( V_18 , V_135 ,
L_50
L_51 , V_240 ) ;
return - V_114 ;
}
V_192 = F_133 ( V_184 , 0 , 0 , 0 , ( V_196 - sizeof( * V_192 ) ) , 0 ) ;
V_194 = F_134 ( V_192 ) ;
V_194 -> V_200 = F_5 ( V_135 -> V_34 ) ;
V_194 -> type = V_240 ;
switch ( V_240 ) {
case V_175 :
V_194 -> V_202 . V_242 . V_77 = V_72 -> V_77 ;
V_194 -> V_202 . V_242 . V_126 = V_135 -> V_126 ;
break;
case V_174 :
V_194 -> V_202 . V_243 . V_77 = V_72 -> V_77 ;
V_194 -> V_202 . V_243 . V_126 = V_135 -> V_126 ;
break;
case V_168 :
V_194 -> V_202 . V_244 . V_77 = V_72 -> V_77 ;
V_194 -> V_202 . V_244 . V_126 = V_135 -> V_126 ;
break;
default:
F_80 ( V_18 , V_135 , L_52
L_53 , V_240 ) ;
F_142 ( V_184 ) ;
return - V_197 ;
}
V_241 = F_126 ( V_184 , V_204 , V_19 ) ;
if ( V_241 == - V_101 )
F_80 ( V_18 , V_135 ,
L_50
L_54 ,
V_240 ) ;
F_60 ( V_135 , L_55 ,
V_240 , V_241 ) ;
return V_241 ;
}
static int
F_143 ( struct V_3 * V_4 , struct V_9 * V_10 ,
struct V_193 * V_194 , T_9 V_245 ,
T_5 V_246 , T_8 V_247 ,
T_8 V_248 )
{
struct V_8 * V_34 = V_4 -> V_8 ;
struct V_124 * V_135 ;
struct V_71 * V_72 ;
V_135 = V_34 -> V_249 ( V_10 , V_247 , V_248 ,
V_246 ) ;
if ( ! V_135 )
return - V_114 ;
V_135 -> V_169 = V_245 ;
V_72 = F_58 ( V_135 ) ;
V_194 -> V_202 . V_243 . V_77 = V_72 -> V_77 ;
V_194 -> V_202 . V_243 . V_126 = V_135 -> V_126 ;
F_60 ( V_135 ,
L_56 ) ;
return 0 ;
}
static int
F_144 ( struct V_8 * V_34 , struct V_193 * V_194 )
{
struct V_122 * V_123 ;
struct V_124 * V_135 ;
V_135 = F_48 ( V_194 -> V_231 . V_250 . V_126 ) ;
if ( ! V_135 ) {
F_12 ( V_18 L_57 ,
V_194 -> V_231 . V_250 . V_126 ) ;
return - V_197 ;
}
V_123 = V_34 -> V_251 ( V_135 , V_194 -> V_231 . V_250 . V_129 ) ;
if ( ! V_123 ) {
F_80 ( V_18 , V_135 ,
L_58 ) ;
return - V_114 ;
}
V_194 -> V_202 . V_252 . V_126 = V_135 -> V_126 ;
V_194 -> V_202 . V_252 . V_129 = V_123 -> V_129 ;
F_114 ( V_123 , L_59 ) ;
return 0 ;
}
static int
F_145 ( struct V_8 * V_34 , struct V_193 * V_194 )
{
struct V_122 * V_123 ;
V_123 = F_52 ( V_194 -> V_231 . V_253 . V_126 , V_194 -> V_231 . V_253 . V_129 ) ;
if ( ! V_123 )
return - V_197 ;
F_114 ( V_123 , L_60 ) ;
if ( V_34 -> V_254 )
V_34 -> V_254 ( V_123 ) ;
return 0 ;
}
static int
F_146 ( struct V_8 * V_34 , struct V_193 * V_194 )
{
char * V_12 = ( char * ) V_194 + sizeof( * V_194 ) ;
struct V_122 * V_123 ;
struct V_124 * V_135 ;
int V_15 = 0 , V_134 = 0 ;
V_135 = F_48 ( V_194 -> V_231 . V_255 . V_126 ) ;
V_123 = F_52 ( V_194 -> V_231 . V_255 . V_126 , V_194 -> V_231 . V_255 . V_129 ) ;
if ( ! V_123 || ! V_135 )
return - V_197 ;
switch ( V_194 -> V_231 . V_255 . V_35 ) {
case V_256 :
sscanf ( V_12 , L_61 , & V_134 ) ;
V_135 -> V_159 = V_134 ;
break;
default:
V_15 = V_34 -> V_255 ( V_123 , V_194 -> V_231 . V_255 . V_35 ,
V_12 , V_194 -> V_231 . V_255 . V_196 ) ;
}
return V_15 ;
}
static int F_147 ( struct V_8 * V_34 ,
struct V_193 * V_194 , int V_257 )
{
struct V_9 * V_10 ;
struct V_258 * V_259 ;
struct V_71 * V_72 = NULL ;
int V_260 , V_15 = 0 ;
if ( ! V_34 -> V_261 )
return - V_197 ;
if ( V_257 == V_262 ) {
V_72 = F_148 ( V_194 -> V_231 . V_263 . V_77 ) ;
if ( ! V_72 ) {
F_12 ( V_18 L_62
L_63 ,
V_194 -> V_231 . V_263 . V_77 ) ;
return - V_264 ;
}
V_260 = V_194 -> V_231 . V_263 . V_260 ;
} else
V_260 = V_194 -> V_231 . V_261 . V_260 ;
V_259 = (struct V_258 * ) ( ( char * ) V_194 + sizeof( * V_194 ) ) ;
V_10 = V_34 -> V_261 ( V_72 , V_259 , V_260 ) ;
if ( F_149 ( V_10 ) ) {
V_15 = F_150 ( V_10 ) ;
goto V_265;
}
V_194 -> V_202 . V_266 . V_26 = V_10 -> V_11 ;
V_265:
if ( V_72 )
F_59 ( V_72 ) ;
return V_15 ;
}
static int F_151 ( struct V_8 * V_34 ,
T_3 V_267 )
{
struct V_122 * V_123 ;
struct V_9 * V_10 ;
if ( ! V_34 -> V_268 )
return - V_197 ;
V_10 = F_20 ( V_267 ) ;
if ( ! V_10 )
return - V_197 ;
V_123 = V_10 -> V_123 ;
if ( V_123 ) {
F_69 ( & V_123 -> V_176 ) ;
V_123 -> V_10 = NULL ;
F_71 ( & V_123 -> V_176 ) ;
}
V_34 -> V_268 ( V_10 ) ;
return 0 ;
}
static int
F_152 ( struct V_8 * V_34 ,
struct V_193 * V_194 , int V_257 )
{
struct V_9 * V_10 ;
int V_241 = 0 ;
switch ( V_257 ) {
case V_262 :
case V_269 :
V_241 = F_147 ( V_34 , V_194 , V_257 ) ;
break;
case V_270 :
if ( ! V_34 -> V_271 )
return - V_197 ;
V_10 = F_20 ( V_194 -> V_231 . V_271 . V_267 ) ;
if ( ! V_10 )
return - V_197 ;
V_194 -> V_202 . V_272 = V_34 -> V_271 ( V_10 ,
V_194 -> V_231 . V_271 . V_273 ) ;
break;
case V_274 :
V_241 = F_151 ( V_34 ,
V_194 -> V_231 . V_268 . V_267 ) ;
break;
}
return V_241 ;
}
static int
F_153 ( struct V_8 * V_34 ,
struct V_193 * V_194 )
{
struct V_71 * V_72 ;
struct V_258 * V_259 ;
int V_15 ;
if ( ! V_34 -> V_275 )
return - V_197 ;
V_72 = F_148 ( V_194 -> V_231 . V_275 . V_77 ) ;
if ( ! V_72 ) {
F_12 ( V_18 L_64 ,
V_194 -> V_231 . V_275 . V_77 ) ;
return - V_264 ;
}
V_259 = (struct V_258 * ) ( ( char * ) V_194 + sizeof( * V_194 ) ) ;
V_15 = V_34 -> V_275 ( V_72 , V_194 -> V_231 . V_275 . type ,
V_194 -> V_231 . V_275 . V_276 , V_259 ) ;
F_59 ( V_72 ) ;
return V_15 ;
}
static int
F_154 ( struct V_8 * V_34 ,
struct V_193 * V_194 )
{
char * V_12 = ( char * ) V_194 + sizeof( * V_194 ) ;
struct V_71 * V_72 ;
int V_15 ;
if ( ! V_34 -> V_277 )
return - V_278 ;
V_72 = F_148 ( V_194 -> V_231 . V_277 . V_77 ) ;
if ( ! V_72 ) {
F_12 ( V_18 L_65 ,
V_194 -> V_231 . V_277 . V_77 ) ;
return - V_264 ;
}
V_15 = V_34 -> V_277 ( V_72 , V_194 -> V_231 . V_277 . V_35 ,
V_12 , V_194 -> V_231 . V_277 . V_196 ) ;
F_59 ( V_72 ) ;
return V_15 ;
}
static int
F_155 ( struct V_8 * V_34 , struct V_193 * V_194 )
{
struct V_71 * V_72 ;
struct V_279 * V_280 ;
int V_15 ;
if ( ! V_34 -> V_281 )
return - V_278 ;
V_72 = F_148 ( V_194 -> V_231 . V_281 . V_77 ) ;
if ( ! V_72 ) {
F_12 ( V_18 L_66 ,
V_194 -> V_231 . V_281 . V_77 ) ;
return - V_264 ;
}
V_280 = (struct V_279 * ) ( ( char * ) V_194 + sizeof( * V_194 ) ) ;
V_15 = V_34 -> V_281 ( V_72 , V_280 ) ;
F_59 ( V_72 ) ;
return V_15 ;
}
static int
F_156 ( struct V_8 * V_34 ,
struct V_193 * V_194 , T_5 V_196 )
{
char * V_12 = ( char * ) V_194 + sizeof( * V_194 ) ;
struct V_71 * V_72 ;
int V_15 ;
if ( ! V_34 -> V_282 )
return - V_278 ;
V_72 = F_148 ( V_194 -> V_231 . V_283 . V_77 ) ;
if ( ! V_72 ) {
F_12 ( V_18 L_67 ,
V_194 -> V_231 . V_283 . V_77 ) ;
return - V_264 ;
}
V_15 = V_34 -> V_282 ( V_72 , V_12 , V_196 ) ;
F_59 ( V_72 ) ;
return V_15 ;
}
static int
F_157 ( struct V_183 * V_184 , struct V_191 * V_192 , T_5 * V_185 )
{
int V_15 = 0 ;
struct V_193 * V_194 = F_134 ( V_192 ) ;
struct V_8 * V_34 = NULL ;
struct V_3 * V_4 ;
struct V_124 * V_135 ;
struct V_122 * V_123 ;
struct V_9 * V_10 = NULL ;
if ( V_192 -> V_235 == V_284 )
* V_185 = V_209 ;
else
* V_185 = V_204 ;
V_4 = F_125 ( F_158 ( V_194 -> V_200 ) ) ;
if ( ! V_4 )
return - V_197 ;
V_34 = V_4 -> V_8 ;
if ( ! F_159 ( V_34 -> V_285 ) )
return - V_197 ;
switch ( V_192 -> V_235 ) {
case V_286 :
V_15 = F_143 ( V_4 , V_10 , V_194 ,
F_160 ( V_184 ) -> V_245 ,
V_194 -> V_231 . V_287 . V_246 ,
V_194 -> V_231 . V_287 . V_247 ,
V_194 -> V_231 . V_287 . V_248 ) ;
break;
case V_288 :
V_10 = F_20 ( V_194 -> V_231 . V_289 . V_267 ) ;
if ( ! V_10 ) {
V_15 = - V_197 ;
break;
}
V_15 = F_143 ( V_4 , V_10 , V_194 ,
F_160 ( V_184 ) -> V_245 ,
V_194 -> V_231 . V_289 . V_246 ,
V_194 -> V_231 . V_289 . V_247 ,
V_194 -> V_231 . V_289 . V_248 ) ;
break;
case V_290 :
V_135 = F_48 ( V_194 -> V_231 . V_242 . V_126 ) ;
if ( V_135 )
V_34 -> V_291 ( V_135 ) ;
else
V_15 = - V_197 ;
break;
case V_292 :
V_135 = F_48 ( V_194 -> V_231 . V_242 . V_126 ) ;
if ( V_135 )
F_84 ( F_58 ( V_135 ) ,
& V_135 -> V_165 ) ;
else
V_15 = - V_197 ;
break;
case V_293 :
V_15 = F_144 ( V_34 , V_194 ) ;
break;
case V_294 :
V_15 = F_145 ( V_34 , V_194 ) ;
break;
case V_295 :
V_135 = F_48 ( V_194 -> V_231 . V_296 . V_126 ) ;
V_123 = F_52 ( V_194 -> V_231 . V_296 . V_126 , V_194 -> V_231 . V_296 . V_129 ) ;
if ( V_123 && V_123 -> V_10 )
F_151 ( V_34 , V_123 -> V_10 -> V_11 ) ;
if ( ! V_135 || ! V_123 ) {
V_15 = - V_197 ;
break;
}
V_194 -> V_202 . V_272 = V_34 -> V_297 ( V_135 , V_123 ,
V_194 -> V_231 . V_296 . V_298 ,
V_194 -> V_231 . V_296 . V_299 ) ;
if ( V_194 -> V_202 . V_272 || ! V_34 -> V_261 )
break;
V_10 = F_20 ( V_194 -> V_231 . V_296 . V_298 ) ;
if ( V_10 ) {
V_10 -> V_123 = V_123 ;
F_69 ( & V_123 -> V_176 ) ;
V_123 -> V_10 = V_10 ;
F_71 ( & V_123 -> V_176 ) ;
} else
F_132 ( V_18 , V_123 ,
L_68
L_69 ) ;
break;
case V_300 :
V_15 = F_146 ( V_34 , V_194 ) ;
break;
case V_301 :
V_123 = F_52 ( V_194 -> V_231 . V_302 . V_126 , V_194 -> V_231 . V_302 . V_129 ) ;
if ( V_123 )
V_194 -> V_202 . V_272 = V_34 -> V_302 ( V_123 ) ;
else
V_15 = - V_197 ;
break;
case V_303 :
V_123 = F_52 ( V_194 -> V_231 . V_304 . V_126 , V_194 -> V_231 . V_304 . V_129 ) ;
if ( V_123 )
V_34 -> V_304 ( V_123 , V_194 -> V_231 . V_304 . V_305 ) ;
else
V_15 = - V_197 ;
break;
case V_306 :
V_123 = F_52 ( V_194 -> V_231 . V_307 . V_126 , V_194 -> V_231 . V_307 . V_129 ) ;
if ( V_123 )
V_194 -> V_202 . V_272 = V_34 -> V_307 ( V_123 ,
(struct V_188 * ) ( ( char * ) V_194 + sizeof( * V_194 ) ) ,
( char * ) V_194 + sizeof( * V_194 ) + V_194 -> V_231 . V_307 . V_308 ,
V_194 -> V_231 . V_307 . V_190 ) ;
else
V_15 = - V_197 ;
break;
case V_309 :
V_15 = F_138 ( V_34 , V_192 ) ;
break;
case V_269 :
case V_270 :
case V_274 :
case V_262 :
V_15 = F_152 ( V_34 , V_194 , V_192 -> V_235 ) ;
break;
case V_310 :
V_15 = F_153 ( V_34 , V_194 ) ;
break;
case V_311 :
V_15 = F_154 ( V_34 , V_194 ) ;
break;
case V_284 :
V_15 = F_155 ( V_34 , V_194 ) ;
break;
case V_312 :
V_15 = F_156 ( V_34 , V_194 ,
F_161 ( V_192 , sizeof( * V_194 ) ) ) ;
break;
default:
V_15 = - V_278 ;
break;
}
F_162 ( V_34 -> V_285 ) ;
return V_15 ;
}
static void
F_163 ( struct V_183 * V_184 )
{
F_69 ( & V_313 ) ;
while ( V_184 -> V_196 >= F_129 ( 0 ) ) {
int V_15 ;
T_5 V_314 ;
struct V_191 * V_192 ;
struct V_193 * V_194 ;
T_5 V_185 ;
V_192 = F_164 ( V_184 ) ;
if ( V_192 -> V_237 < sizeof( * V_192 ) ||
V_184 -> V_196 < V_192 -> V_237 ) {
break;
}
V_194 = F_134 ( V_192 ) ;
V_314 = F_141 ( V_192 -> V_237 ) ;
if ( V_314 > V_184 -> V_196 )
V_314 = V_184 -> V_196 ;
V_15 = F_157 ( V_184 , V_192 , & V_185 ) ;
if ( V_15 ) {
V_194 -> type = V_315 ;
V_194 -> V_316 = V_15 ;
}
do {
if ( V_194 -> type == V_309 && ! V_15 )
break;
V_15 = F_137 ( V_185 , V_192 -> V_317 ,
V_192 -> V_235 , 0 , 0 , V_194 , sizeof( * V_194 ) ) ;
} while ( V_15 < 0 && V_15 != - V_238 );
F_165 ( V_184 , V_314 ) ;
}
F_71 ( & V_313 ) ;
}
static T_4 F_166 ( struct V_30 * V_22 ,
struct V_31 * V_6 , int V_32 )
{
struct V_1 * V_118 = F_25 ( V_22 , struct V_1 , V_22 ) ;
struct V_122 * V_123 = F_167 ( V_118 ) ;
struct V_8 * V_33 = V_123 -> V_34 ;
int V_35 ;
if ( V_6 == & V_318 . V_6 )
V_35 = V_319 ;
else if ( V_6 == & V_320 . V_6 )
V_35 = V_321 ;
else if ( V_6 == & V_322 . V_6 )
V_35 = V_323 ;
else if ( V_6 == & V_324 . V_6 )
V_35 = V_325 ;
else if ( V_6 == & V_326 . V_6 )
V_35 = V_327 ;
else if ( V_6 == & V_328 . V_6 )
V_35 = V_329 ;
else if ( V_6 == & V_330 . V_6 )
V_35 = V_331 ;
else if ( V_6 == & V_332 . V_6 )
V_35 = V_333 ;
else if ( V_6 == & V_334 . V_6 )
V_35 = V_335 ;
else if ( V_6 == & V_336 . V_6 )
V_35 = V_337 ;
else if ( V_6 == & V_338 . V_6 )
V_35 = V_339 ;
else if ( V_6 == & V_340 . V_6 )
V_35 = V_341 ;
else if ( V_6 == & V_342 . V_6 )
V_35 = V_343 ;
else {
F_26 ( 1 , L_70 ) ;
return 0 ;
}
return V_33 -> V_69 ( V_344 , V_35 ) ;
}
static T_1
F_168 ( struct V_1 * V_2 , struct V_5 * V_6 ,
char * V_7 )
{
struct V_124 * V_135 = F_47 ( V_2 -> V_29 ) ;
return sprintf ( V_7 , L_71 , F_53 ( V_135 -> V_131 ) ) ;
}
static T_1
F_169 ( struct V_1 * V_2 , struct V_5 * V_6 ,
char * V_7 )
{
struct V_124 * V_135 = F_47 ( V_2 -> V_29 ) ;
return sprintf ( V_7 , L_72 , V_135 -> V_169 ) ;
}
static T_4 F_170 ( struct V_30 * V_22 ,
struct V_31 * V_6 , int V_32 )
{
struct V_1 * V_118 = F_25 ( V_22 , struct V_1 , V_22 ) ;
struct V_124 * V_135 = F_171 ( V_118 ) ;
struct V_8 * V_33 = V_135 -> V_34 ;
int V_35 ;
if ( V_6 == & V_345 . V_6 )
V_35 = V_346 ;
else if ( V_6 == & V_347 . V_6 )
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
else if ( V_6 == & V_373 . V_6 )
V_35 = V_374 ;
else if ( V_6 == & V_375 . V_6 )
V_35 = V_376 ;
else if ( V_6 == & V_377 . V_6 )
V_35 = V_378 ;
else if ( V_6 == & V_379 . V_6 )
V_35 = V_380 ;
else if ( V_6 == & V_381 . V_6 )
V_35 = V_382 ;
else if ( V_6 == & V_383 . V_6 )
V_35 = V_384 ;
else if ( V_6 == & V_385 . V_6 )
V_35 = V_386 ;
else if ( V_6 == & V_387 . V_6 )
return V_388 | V_389 ;
else if ( V_6 == & V_390 . V_6 )
return V_388 ;
else if ( V_6 == & V_391 . V_6 )
return V_388 ;
else {
F_26 ( 1 , L_73 ) ;
return 0 ;
}
return V_33 -> V_69 ( V_344 , V_35 ) ;
}
static T_4 F_172 ( struct V_30 * V_22 ,
struct V_31 * V_6 , int V_32 )
{
struct V_1 * V_118 = F_25 ( V_22 , struct V_1 , V_22 ) ;
struct V_71 * V_72 = F_173 ( V_118 ) ;
struct V_3 * V_4 = F_32 ( V_72 -> V_88 ) ;
int V_35 ;
if ( V_6 == & V_392 . V_6 )
V_35 = V_393 ;
else if ( V_6 == & V_394 . V_6 )
V_35 = V_395 ;
else if ( V_6 == & V_396 . V_6 )
V_35 = V_397 ;
else if ( V_6 == & V_398 . V_6 )
V_35 = V_399 ;
else {
F_26 ( 1 , L_74 ) ;
return 0 ;
}
return V_4 -> V_8 -> V_69 ( V_400 , V_35 ) ;
}
static int F_174 ( struct V_401 * V_402 ,
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
if ( V_4 -> V_403 . V_404 . V_20 != & V_405 . V_20 )
return 0 ;
return & V_4 -> V_403 . V_404 == V_402 ;
}
static int F_175 ( struct V_401 * V_402 ,
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
if ( V_4 -> V_406 . V_404 . V_20 != & V_407 . V_20 )
return 0 ;
return & V_4 -> V_406 . V_404 == V_402 ;
}
static int F_176 ( struct V_401 * V_402 ,
struct V_1 * V_2 )
{
struct V_71 * V_72 ;
struct V_3 * V_4 ;
if ( ! F_177 ( V_2 ) )
return 0 ;
V_72 = F_41 ( V_2 ) ;
if ( ! V_72 -> V_88 ||
V_72 -> V_88 -> V_408 . V_404 . V_20 != & V_409 . V_20 )
return 0 ;
V_4 = F_32 ( V_72 -> V_88 ) ;
return & V_4 -> V_33 . V_408 . V_404 == V_402 ;
}
struct V_410 *
F_178 ( struct V_8 * V_181 )
{
struct V_3 * V_4 ;
unsigned long V_127 ;
int V_15 ;
F_33 ( ! V_181 ) ;
V_4 = F_125 ( V_181 ) ;
if ( V_4 )
return NULL ;
V_4 = F_13 ( sizeof( * V_4 ) , V_19 ) ;
if ( ! V_4 )
return NULL ;
F_99 ( & V_4 -> V_411 ) ;
V_4 -> V_8 = V_181 ;
V_4 -> V_33 . V_412 = F_72 ;
V_4 -> V_33 . V_413 = 1 ;
V_4 -> V_2 . V_20 = & V_414 ;
F_14 ( & V_4 -> V_2 , L_75 , V_181 -> V_132 ) ;
V_15 = F_15 ( & V_4 -> V_2 ) ;
if ( V_15 )
goto V_415;
V_15 = F_16 ( & V_4 -> V_2 . V_22 , & V_416 ) ;
if ( V_15 )
goto V_24;
V_4 -> V_33 . V_408 . V_404 . V_20 = & V_409 . V_20 ;
V_4 -> V_33 . V_408 . V_404 . V_417 = F_176 ;
V_4 -> V_33 . V_408 . V_404 . V_418 = & V_419 ;
V_4 -> V_33 . V_420 = sizeof( struct V_107 ) ;
F_179 ( & V_4 -> V_33 . V_408 ) ;
V_4 -> V_406 . V_404 . V_20 = & V_407 . V_20 ;
V_4 -> V_406 . V_404 . V_417 = F_175 ;
V_4 -> V_406 . V_404 . V_418 = & V_421 ;
F_179 ( & V_4 -> V_406 ) ;
V_4 -> V_403 . V_404 . V_20 = & V_405 . V_20 ;
V_4 -> V_403 . V_404 . V_417 = F_174 ;
V_4 -> V_403 . V_404 . V_418 = & V_422 ;
F_179 ( & V_4 -> V_403 ) ;
F_49 ( & V_182 , V_127 ) ;
F_109 ( & V_4 -> V_411 , & V_423 ) ;
F_51 ( & V_182 , V_127 ) ;
F_12 ( V_424 L_76 , V_181 -> V_132 ) ;
return & V_4 -> V_33 ;
V_24:
F_17 ( & V_4 -> V_2 ) ;
return NULL ;
V_415:
F_3 ( V_4 ) ;
return NULL ;
}
int F_180 ( struct V_8 * V_181 )
{
struct V_3 * V_4 ;
unsigned long V_127 ;
F_33 ( ! V_181 ) ;
F_69 ( & V_313 ) ;
V_4 = F_125 ( V_181 ) ;
F_33 ( ! V_4 ) ;
F_49 ( & V_182 , V_127 ) ;
F_119 ( & V_4 -> V_411 ) ;
F_51 ( & V_182 , V_127 ) ;
F_181 ( & V_4 -> V_406 ) ;
F_181 ( & V_4 -> V_403 ) ;
F_181 ( & V_4 -> V_33 . V_408 ) ;
F_19 ( & V_4 -> V_2 . V_22 , & V_416 ) ;
F_17 ( & V_4 -> V_2 ) ;
F_71 ( & V_313 ) ;
return 0 ;
}
static T_10 int F_182 ( void )
{
int V_15 ;
F_12 ( V_158 L_77 ,
V_425 ) ;
F_42 ( & V_171 , 0 ) ;
V_15 = F_183 ( & V_414 ) ;
if ( V_15 )
return V_15 ;
V_15 = F_183 ( & V_17 ) ;
if ( V_15 )
goto V_426;
V_15 = F_183 ( & V_75 ) ;
if ( V_15 )
goto V_427;
V_15 = F_184 ( & V_409 ) ;
if ( V_15 )
goto V_428;
V_15 = F_184 ( & V_407 ) ;
if ( V_15 )
goto V_429;
V_15 = F_184 ( & V_405 ) ;
if ( V_15 )
goto V_430;
V_187 = F_185 ( & V_431 , V_432 , 1 , F_163 ,
NULL , V_433 ) ;
if ( ! V_187 ) {
V_15 = - V_434 ;
goto V_435;
}
V_162 = F_186 ( L_78 ) ;
if ( ! V_162 )
goto V_436;
return 0 ;
V_436:
F_187 ( V_187 ) ;
V_435:
F_188 ( & V_405 ) ;
V_430:
F_188 ( & V_407 ) ;
V_429:
F_188 ( & V_409 ) ;
V_428:
F_189 ( & V_75 ) ;
V_427:
F_189 ( & V_17 ) ;
V_426:
F_189 ( & V_414 ) ;
return V_15 ;
}
static void T_11 F_190 ( void )
{
F_191 ( V_162 ) ;
F_187 ( V_187 ) ;
F_188 ( & V_407 ) ;
F_188 ( & V_405 ) ;
F_188 ( & V_409 ) ;
F_189 ( & V_17 ) ;
F_189 ( & V_75 ) ;
F_189 ( & V_414 ) ;
}
