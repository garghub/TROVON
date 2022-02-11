static int
F_1 ( char * V_1 , T_1 * V_2 )
{
int V_3 , V_4 = 0 ;
for ( V_3 = 0 ; V_3 < V_5 ; V_3 ++ , V_2 ++ )
V_4 += sprintf ( V_1 + V_4 , L_1 , * V_2 ) ;
V_4 += sprintf ( V_1 + V_4 , L_2 ) ;
return V_4 ;
}
static int F_2 ( struct V_6 * V_7 , struct V_8 * V_9 ,
struct V_8 * V_10 )
{
struct V_11 * V_12 = F_3 ( V_9 ) ;
struct V_13 * V_14 = F_4 ( V_12 ) ;
if ( V_14 ) {
F_5 ( V_12 ) = V_14 -> V_15 ;
F_6 ( V_12 ) = V_14 -> V_16 ;
F_7 ( V_12 ) = V_14 -> V_17 ;
} else {
F_5 ( V_12 ) = - 1 ;
F_6 ( V_12 ) = - 1 ;
F_7 ( V_12 ) = - 1 ;
}
return 0 ;
}
static int F_8 ( struct V_6 * V_7 , struct V_8 * V_9 ,
struct V_8 * V_10 )
{
struct V_18 * V_19 = F_9 ( V_9 ) ;
struct V_20 * V_21 = F_10 ( V_19 ) ;
V_21 -> V_15 = - 1 ;
V_21 -> V_16 = - 1 ;
V_21 -> V_22 = - 1 ;
V_21 -> V_23 = V_24 ;
memset ( V_21 -> V_25 , 0 ,
sizeof( V_21 -> V_25 ) ) ;
V_21 -> V_26 = V_27 ;
V_21 -> V_28 = - 1 ;
V_21 -> V_29 = 0 ;
memset ( V_21 -> V_30 , 0 ,
sizeof( V_21 -> V_30 ) ) ;
memset ( V_21 -> V_31 , 0 ,
sizeof( V_21 -> V_31 ) ) ;
memset ( V_21 -> V_32 , 0 ,
sizeof( V_21 -> V_32 ) ) ;
memset ( V_21 -> V_33 , 0 ,
sizeof( V_21 -> V_33 ) ) ;
memset ( V_21 -> V_34 , 0 ,
sizeof( V_21 -> V_34 ) ) ;
memset ( V_21 -> V_35 , 0 ,
sizeof( V_21 -> V_35 ) ) ;
memset ( V_21 -> V_36 , 0 ,
sizeof( V_21 -> V_36 ) ) ;
memset ( V_21 -> V_37 , 0 ,
sizeof( V_21 -> V_37 ) ) ;
V_21 -> V_17 = - 1 ;
V_21 -> V_38 = V_39 ;
V_21 -> V_40 = V_41 ;
memset ( V_21 -> V_42 , 0 ,
sizeof( V_21 -> V_42 ) ) ;
V_21 -> V_43 = V_27 ;
V_21 -> V_44 = - 1 ;
memset ( V_21 -> V_45 , 0 , sizeof( V_21 -> V_45 ) ) ;
memset ( V_21 -> V_46 , 0 , sizeof( V_21 -> V_46 ) ) ;
V_21 -> V_47 = V_48 ;
F_11 ( & V_21 -> V_49 ) ;
F_11 ( & V_21 -> V_50 ) ;
F_11 ( & V_21 -> V_51 ) ;
V_21 -> V_52 = 0 ;
V_21 -> V_53 = 0 ;
V_21 -> V_54 = 0 ;
V_21 -> V_55 = 0 ;
snprintf ( V_21 -> V_56 , sizeof( V_21 -> V_56 ) ,
L_3 , V_19 -> V_57 ) ;
V_21 -> V_58 = F_12 ( L_4 , 0 , 0 , V_21 -> V_56 ) ;
if ( ! V_21 -> V_58 )
return - V_59 ;
V_21 -> V_60 = V_61 ;
snprintf ( V_21 -> V_62 ,
sizeof( V_21 -> V_62 ) ,
L_5 , V_19 -> V_57 ) ;
V_21 -> V_63 = F_12 ( L_4 , 0 , 0 ,
V_21 -> V_62 ) ;
if ( ! V_21 -> V_63 ) {
F_13 ( V_21 -> V_58 ) ;
V_21 -> V_58 = NULL ;
return - V_59 ;
}
F_14 ( V_19 , V_21 ) ;
return 0 ;
}
static int F_15 ( struct V_6 * V_7 , struct V_8 * V_9 ,
struct V_8 * V_10 )
{
struct V_18 * V_19 = F_9 ( V_9 ) ;
struct V_20 * V_21 = F_10 ( V_19 ) ;
F_16 ( V_21 -> V_64 ) ;
return 0 ;
}
T_2
F_17 ( void )
{
return F_18 ( 1 , & V_65 ) ;
}
void
F_19 ( struct V_18 * V_19 , T_2 V_66 ,
enum V_67 V_68 , T_2 V_69 )
{
struct V_70 * V_71 ;
struct V_72 * V_73 ;
struct V_74 * V_75 ;
const char * V_76 ;
T_2 V_4 ;
int V_77 ;
if ( ! V_78 ) {
V_77 = - V_79 ;
goto V_80;
}
V_4 = F_20 ( sizeof( * V_75 ) ) ;
V_71 = F_21 ( V_4 , V_81 ) ;
if ( ! V_71 ) {
V_77 = - V_82 ;
goto V_80;
}
V_73 = F_22 ( V_71 , 0 , 0 , V_83 , V_4 , 0 ) ;
if ( ! V_73 ) {
V_77 = - V_82 ;
goto V_84;
}
V_75 = F_23 ( V_73 ) ;
F_24 ( & V_75 -> V_85 , V_86 ,
V_87 , V_4 ) ;
V_75 -> V_88 = F_25 () ;
V_75 -> V_89 = 0 ;
V_75 -> V_57 = V_19 -> V_57 ;
V_75 -> V_90 = sizeof( T_2 ) ;
V_75 -> V_91 = V_66 ;
V_75 -> V_68 = V_68 ;
V_75 -> V_69 = V_69 ;
F_26 ( V_78 , V_71 , 0 , V_92 ,
V_81 ) ;
return;
V_84:
F_27 ( V_71 ) ;
V_80:
V_76 = F_28 ( V_68 ) ;
F_29 ( V_93
L_6 ,
V_94 , V_19 -> V_57 ,
( V_76 ) ? V_76 : L_7 , V_69 , V_77 ) ;
return;
}
void
F_30 ( struct V_18 * V_19 , T_2 V_66 ,
T_2 V_95 , char * V_96 , T_3 V_89 )
{
struct V_70 * V_71 ;
struct V_72 * V_73 ;
struct V_74 * V_75 ;
T_2 V_4 ;
int V_77 ;
if ( ! V_78 ) {
V_77 = - V_79 ;
goto V_97;
}
V_4 = F_20 ( sizeof( * V_75 ) + V_95 ) ;
V_71 = F_21 ( V_4 , V_81 ) ;
if ( ! V_71 ) {
V_77 = - V_82 ;
goto V_97;
}
V_73 = F_22 ( V_71 , 0 , 0 , V_83 , V_4 , 0 ) ;
if ( ! V_73 ) {
V_77 = - V_82 ;
goto V_98;
}
V_75 = F_23 ( V_73 ) ;
F_24 ( & V_75 -> V_85 , V_86 ,
V_87 , V_4 ) ;
V_75 -> V_88 = F_25 () ;
V_75 -> V_89 = V_89 ;
V_75 -> V_57 = V_19 -> V_57 ;
V_75 -> V_90 = V_95 ;
V_75 -> V_91 = V_66 ;
V_75 -> V_68 = V_99 ;
memcpy ( & V_75 -> V_69 , V_96 , V_95 ) ;
F_26 ( V_78 , V_71 , 0 , V_92 ,
V_81 ) ;
return;
V_98:
F_27 ( V_71 ) ;
V_97:
F_29 ( V_93
L_8 ,
V_94 , V_19 -> V_57 , V_77 ) ;
return;
}
static T_4 int F_31 ( void )
{
int error ;
F_32 ( & V_65 , 0 ) ;
error = F_33 ( & V_100 ) ;
if ( error )
return error ;
error = F_33 ( & V_101 ) ;
if ( error )
goto V_102;
error = F_33 ( & V_103 ) ;
if ( error )
goto V_104;
error = F_33 ( & V_105 ) ;
if ( error )
goto V_106;
return 0 ;
V_106:
F_34 ( & V_103 ) ;
V_104:
F_34 ( & V_101 ) ;
V_102:
F_34 ( & V_100 ) ;
return error ;
}
static void T_5 F_35 ( void )
{
F_34 ( & V_105 ) ;
F_34 ( & V_103 ) ;
F_34 ( & V_100 ) ;
F_34 ( & V_101 ) ;
}
static T_6
F_36 ( struct V_8 * V_9 ,
struct V_107 * V_108 , char * V_1 )
{
struct V_13 * V_14 = F_37 ( V_9 ) ;
if ( V_14 -> V_23 == V_24 )
return snprintf ( V_1 , 20 , L_9 ) ;
return F_38 ( V_14 -> V_23 , V_1 ) ;
}
static int F_39 ( const char * V_1 , unsigned long * V_109 )
{
char * V_110 ;
* V_109 = F_40 ( V_1 , & V_110 , 0 ) ;
if ( ( * V_110 && ( * V_110 != '\n' ) ) || ( * V_109 < 0 ) )
return - V_111 ;
if ( * V_109 > V_112 )
return - V_111 ;
return 0 ;
}
static int F_41 ( struct V_13 * V_14 ,
unsigned long V_109 )
{
struct V_18 * V_19 = F_42 ( V_14 ) ;
struct V_113 * V_3 = F_43 ( V_19 -> V_114 ) ;
if ( ( V_14 -> V_40 == V_115 ) ||
( V_14 -> V_40 == V_116 ) ||
( V_14 -> V_40 == V_117 ) )
return - V_118 ;
if ( V_109 > V_112 )
return - V_111 ;
if ( V_14 -> V_119 == - 1 &&
V_109 > V_120 )
return - V_111 ;
V_3 -> V_121 -> V_122 ( V_14 , V_109 ) ;
return 0 ;
}
static T_6
F_44 ( struct V_8 * V_9 , struct V_107 * V_108 ,
const char * V_1 , T_7 V_123 )
{
struct V_13 * V_14 = F_37 ( V_9 ) ;
unsigned long V_109 ;
int V_124 ;
V_124 = F_39 ( V_1 , & V_109 ) ;
if ( V_124 )
return V_124 ;
V_124 = F_41 ( V_14 , V_109 ) ;
if ( V_124 )
return V_124 ;
return V_123 ;
}
static T_6
F_45 ( struct V_8 * V_9 , struct V_107 * V_108 ,
char * V_1 )
{
struct V_13 * V_14 = F_37 ( V_9 ) ;
if ( ( V_14 -> V_17 != - 1 ) &&
( V_14 -> V_17 & V_125 ) ==
V_125 ) {
switch ( V_14 -> V_17 & V_126 ) {
case V_127 :
return snprintf ( V_1 , 30 , L_10 ) ;
case V_128 :
return snprintf ( V_1 , 30 , L_11 ) ;
case V_129 :
return snprintf ( V_1 , 30 , L_12 ) ;
case V_130 :
return snprintf ( V_1 , 30 , L_13 ) ;
case V_131 :
return snprintf ( V_1 , 30 , L_14 ) ;
default:
return snprintf ( V_1 , 30 , L_15 ) ;
}
} else {
if ( V_14 -> V_132 == V_133 )
return snprintf ( V_1 , 20 , L_16 ) ;
return F_46 ( V_14 -> V_132 , V_1 ) ;
}
}
static T_6
F_47 ( struct V_8 * V_9 ,
struct V_107 * V_108 , char * V_1 )
{
struct V_13 * V_14 = F_37 ( V_9 ) ;
if ( V_14 -> V_119 == - 1 )
return snprintf ( V_1 , 5 , L_17 ) ;
return snprintf ( V_1 , 20 , L_18 , V_14 -> V_119 ) ;
}
static T_6
F_48 ( struct V_8 * V_9 ,
struct V_107 * V_108 , const char * V_1 ,
T_7 V_123 )
{
int V_109 ;
char * V_110 ;
struct V_13 * V_14 = F_37 ( V_9 ) ;
if ( ( V_14 -> V_40 == V_115 ) ||
( V_14 -> V_40 == V_116 ) ||
( V_14 -> V_40 == V_117 ) )
return - V_118 ;
if ( strncmp ( V_1 , L_19 , 3 ) == 0 )
V_14 -> V_119 = - 1 ;
else {
V_109 = F_40 ( V_1 , & V_110 , 0 ) ;
if ( ( * V_110 && ( * V_110 != '\n' ) ) || ( V_109 < 0 ) )
return - V_111 ;
if ( ( V_109 >= V_14 -> V_60 ) ||
( V_109 > V_120 ) )
return - V_111 ;
V_14 -> V_119 = V_109 ;
}
return V_123 ;
}
static T_6
F_49 ( struct V_8 * V_9 , struct V_107 * V_108 ,
char * V_1 )
{
struct V_134 * V_135 = F_50 ( V_9 ) ;
if ( V_135 -> V_132 == V_133 )
return snprintf ( V_1 , 20 , L_16 ) ;
return F_46 ( V_135 -> V_132 , V_1 ) ;
}
static T_6
F_51 ( struct V_8 * V_9 , struct V_107 * V_108 ,
const char * V_1 , T_7 V_123 )
{
struct V_134 * V_135 = F_50 ( V_9 ) ;
struct V_18 * V_19 = F_52 ( V_135 ) ;
unsigned long V_136 ;
F_53 ( V_19 -> V_137 , V_136 ) ;
if ( V_135 -> V_136 & ( V_138 | V_139 ) ) {
F_54 ( V_19 -> V_137 , V_136 ) ;
return - V_118 ;
}
V_135 -> V_136 |= V_140 ;
F_54 ( V_19 -> V_137 , V_136 ) ;
F_55 ( V_19 , & V_135 -> V_141 ) ;
return V_123 ;
}
static T_6
F_56 ( struct V_8 * V_9 , struct V_107 * V_108 ,
const char * V_1 ,
T_7 V_123 )
{
struct V_134 * V_135 = F_50 ( V_9 ) ;
struct V_18 * V_19 = F_52 ( V_135 ) ;
struct V_113 * V_3 = F_43 ( V_19 -> V_114 ) ;
int V_142 ;
if ( V_135 -> V_136 & ( V_138 | V_139 ) )
return - V_118 ;
if ( * V_1 == '0' ) {
if ( V_135 -> V_143 != V_144 )
return - V_145 ;
} else if ( * V_1 == '1' ) {
if ( V_135 -> V_143 == V_144 )
return - V_145 ;
} else
return - V_111 ;
V_142 = V_3 -> V_121 -> V_146 ( V_135 , ( ( * V_1 == '0' ) ? false : true ) ) ;
return V_142 ? V_142 : V_123 ;
}
static T_6
F_57 ( struct V_8 * V_9 ,
struct V_107 * V_108 , char * V_1 )
{
struct V_18 * V_19 = F_58 ( V_9 ) ;
if ( F_59 ( V_19 ) == V_24 )
return snprintf ( V_1 , 20 , L_9 ) ;
return F_38 ( F_59 ( V_19 ) , V_1 ) ;
}
static T_6
F_60 ( struct V_8 * V_9 ,
struct V_107 * V_108 , char * V_1 )
{
struct V_18 * V_19 = F_58 ( V_9 ) ;
return ( T_6 ) F_1 ( V_1 , F_61 ( V_19 ) ) ;
}
static T_6
F_62 ( struct V_8 * V_9 ,
struct V_107 * V_108 , char * V_1 )
{
struct V_18 * V_19 = F_58 ( V_9 ) ;
if ( F_63 ( V_19 ) == V_27 )
return snprintf ( V_1 , 20 , L_16 ) ;
return F_64 ( F_63 ( V_19 ) , V_1 ) ;
}
static T_6
F_65 ( struct V_8 * V_9 ,
struct V_107 * V_108 , char * V_1 )
{
struct V_18 * V_19 = F_58 ( V_9 ) ;
struct V_113 * V_3 = F_43 ( V_19 -> V_114 ) ;
if ( V_3 -> V_121 -> V_147 )
V_3 -> V_121 -> V_147 ( V_19 ) ;
return ( T_6 ) F_1 ( V_1 , F_66 ( V_19 ) ) ;
}
static T_6
F_67 ( struct V_8 * V_9 ,
struct V_107 * V_108 , char * V_1 )
{
struct V_18 * V_19 = F_58 ( V_9 ) ;
struct V_113 * V_3 = F_43 ( V_19 -> V_114 ) ;
if ( V_3 -> V_121 -> V_148 )
V_3 -> V_121 -> V_148 ( V_19 ) ;
if ( F_68 ( V_19 ) == V_27 )
return snprintf ( V_1 , 20 , L_16 ) ;
return F_64 ( F_68 ( V_19 ) , V_1 ) ;
}
static T_6
F_69 ( struct V_8 * V_9 ,
struct V_107 * V_108 , char * V_1 )
{
struct V_18 * V_19 = F_58 ( V_9 ) ;
const char * V_76 ;
V_76 = F_70 ( F_71 ( V_19 ) ) ;
if ( ! V_76 )
return - V_111 ;
return snprintf ( V_1 , V_149 , L_20 , V_76 ) ;
}
static T_6
F_72 ( struct V_8 * V_9 ,
struct V_107 * V_108 , const char * V_1 , T_7 V_123 )
{
struct V_18 * V_19 = F_58 ( V_9 ) ;
struct V_13 * V_14 ;
enum V_150 V_109 ;
unsigned long V_136 ;
if ( F_73 ( V_1 , & V_109 ) )
return - V_111 ;
if ( V_109 != F_71 ( V_19 ) ) {
F_53 ( V_19 -> V_137 , V_136 ) ;
while ( ! F_74 ( & F_75 ( V_19 ) ) ) {
F_76 ( V_14 ,
& F_75 ( V_19 ) , V_151 ) ;
F_77 ( & V_14 -> V_151 ) ;
V_14 -> V_40 = V_116 ;
F_55 ( V_19 , & V_14 -> V_152 ) ;
}
F_54 ( V_19 -> V_137 , V_136 ) ;
}
F_71 ( V_19 ) = V_109 ;
return V_123 ;
}
static T_6
F_78 ( struct V_8 * V_9 ,
struct V_107 * V_108 , const char * V_1 , T_7 V_123 )
{
struct V_18 * V_19 = F_58 ( V_9 ) ;
struct V_113 * V_3 = F_43 ( V_19 -> V_114 ) ;
int V_153 ;
if ( V_3 -> V_121 -> V_154 ) {
V_153 = V_3 -> V_121 -> V_154 ( V_19 ) ;
return V_153 ? V_153 : V_123 ;
}
return - V_79 ;
}
static T_6
F_79 ( struct V_8 * V_9 ,
struct V_107 * V_108 ,
const char * V_1 , T_7 V_123 )
{
struct V_18 * V_19 = F_58 ( V_9 ) ;
struct V_20 * V_21 = F_10 ( V_19 ) ;
struct V_13 * V_14 ;
unsigned long V_109 , V_136 ;
int V_124 ;
V_124 = F_39 ( V_1 , & V_109 ) ;
if ( V_124 )
return V_124 ;
F_80 ( V_19 ) = V_109 ;
F_53 ( V_19 -> V_137 , V_136 ) ;
F_81 (rport, &fc_host->rports, peers)
F_41 ( V_14 , V_109 ) ;
F_54 ( V_19 -> V_137 , V_136 ) ;
return V_123 ;
}
static T_6
F_82 ( const struct V_8 * V_9 , char * V_1 , unsigned long V_155 )
{
struct V_18 * V_19 = F_58 ( V_9 ) ;
struct V_113 * V_3 = F_43 ( V_19 -> V_114 ) ;
struct V_156 * V_157 ;
T_6 V_153 = - V_79 ;
if ( V_155 > sizeof( struct V_156 ) ||
V_155 % sizeof( T_3 ) != 0 )
F_83 ( 1 ) ;
if ( V_3 -> V_121 -> V_158 ) {
V_157 = ( V_3 -> V_121 -> V_158 ) ( V_19 ) ;
if ( V_157 )
V_153 = snprintf ( V_1 , 20 , L_21 ,
( unsigned long long ) * ( T_3 * ) ( ( ( T_1 * ) V_157 ) + V_155 ) ) ;
}
return V_153 ;
}
static T_6
F_84 ( struct V_8 * V_9 , struct V_107 * V_108 ,
const char * V_1 , T_7 V_123 )
{
struct V_18 * V_19 = F_58 ( V_9 ) ;
struct V_113 * V_3 = F_43 ( V_19 -> V_114 ) ;
if ( V_3 -> V_121 -> V_159 ) {
V_3 -> V_121 -> V_159 ( V_19 ) ;
return V_123 ;
}
return - V_79 ;
}
static int
F_85 ( const char * V_160 , T_3 * V_161 )
{
unsigned int V_3 , V_162 ;
T_1 V_163 [ 8 ] ;
memset ( V_163 , 0 , sizeof( V_163 ) ) ;
for ( V_3 = 0 , V_162 = 0 ; V_3 < 16 ; V_3 ++ ) {
int V_164 ;
V_164 = F_86 ( * V_160 ++ ) ;
if ( V_164 >= 0 )
V_162 = ( V_162 << 4 ) | V_164 ;
else
return - V_111 ;
if ( V_3 % 2 ) {
V_163 [ V_3 / 2 ] = V_162 & 0xff ;
V_162 = 0 ;
}
}
* V_161 = F_87 ( V_163 ) ;
return 0 ;
}
static T_6
F_88 ( struct V_8 * V_9 , struct V_107 * V_108 ,
const char * V_1 , T_7 V_123 )
{
struct V_18 * V_19 = F_58 ( V_9 ) ;
struct V_165 V_166 ;
struct V_134 * V_135 ;
unsigned int V_167 = V_123 ;
int V_142 ;
memset ( & V_166 , 0 , sizeof( V_166 ) ) ;
if ( V_1 [ V_167 - 1 ] == '\n' )
V_167 -- ;
if ( ( V_167 != ( 16 + 1 + 16 ) ) || ( V_1 [ 16 ] != ':' ) )
return - V_111 ;
V_142 = F_85 ( & V_1 [ 0 ] , & V_166 . V_16 ) ;
if ( V_142 )
return V_142 ;
V_142 = F_85 ( & V_1 [ 17 ] , & V_166 . V_15 ) ;
if ( V_142 )
return V_142 ;
V_166 . V_132 = V_168 ;
V_166 . V_169 = V_170 ;
V_166 . V_171 = false ;
V_142 = F_89 ( V_19 , 0 , & V_19 -> V_172 , & V_166 , & V_135 ) ;
return V_142 ? V_142 : V_123 ;
}
static T_6
F_90 ( struct V_8 * V_9 , struct V_107 * V_108 ,
const char * V_1 , T_7 V_123 )
{
struct V_18 * V_19 = F_58 ( V_9 ) ;
struct V_20 * V_21 = F_10 ( V_19 ) ;
struct V_134 * V_135 ;
T_3 V_173 , V_174 ;
unsigned long V_136 ;
unsigned int V_167 = V_123 ;
int V_142 , V_175 ;
if ( V_1 [ V_167 - 1 ] == '\n' )
V_167 -- ;
if ( ( V_167 != ( 16 + 1 + 16 ) ) || ( V_1 [ 16 ] != ':' ) )
return - V_111 ;
V_142 = F_85 ( & V_1 [ 0 ] , & V_173 ) ;
if ( V_142 )
return V_142 ;
V_142 = F_85 ( & V_1 [ 17 ] , & V_174 ) ;
if ( V_142 )
return V_142 ;
F_53 ( V_19 -> V_137 , V_136 ) ;
V_175 = 0 ;
F_81 (vport, &fc_host->vports, peers) {
if ( ( V_135 -> V_176 == 0 ) &&
( V_135 -> V_16 == V_173 ) && ( V_135 -> V_15 == V_174 ) ) {
if ( V_135 -> V_136 & ( V_138 | V_139 ) )
break;
V_135 -> V_136 |= V_140 ;
V_175 = 1 ;
break;
}
}
F_54 ( V_19 -> V_137 , V_136 ) ;
if ( ! V_175 )
return - V_177 ;
V_142 = F_91 ( V_135 ) ;
return V_142 ? V_142 : V_123 ;
}
static int F_92 ( struct V_178 * V_179 ,
struct V_8 * V_9 )
{
struct V_18 * V_19 ;
struct V_113 * V_3 ;
if ( ! F_93 ( V_9 ) )
return 0 ;
V_19 = F_9 ( V_9 ) ;
if ( ! V_19 -> V_114 || V_19 -> V_114 -> V_180 . V_181 . V_182
!= & V_100 . V_182 )
return 0 ;
V_3 = F_43 ( V_19 -> V_114 ) ;
return & V_3 -> V_183 . V_180 . V_181 == V_179 ;
}
static int F_94 ( struct V_178 * V_179 ,
struct V_8 * V_9 )
{
struct V_18 * V_19 ;
struct V_113 * V_3 ;
if ( ! F_95 ( V_9 ) )
return 0 ;
V_19 = F_9 ( V_9 -> V_184 ) ;
if ( ! V_19 -> V_114 || V_19 -> V_114 -> V_180 . V_181 . V_182
!= & V_100 . V_182 )
return 0 ;
V_3 = F_43 ( V_19 -> V_114 ) ;
return & V_3 -> V_183 . V_185 . V_181 == V_179 ;
}
static void F_96 ( struct V_8 * V_9 )
{
struct V_13 * V_14 = F_97 ( V_9 ) ;
F_98 ( V_9 -> V_184 ) ;
F_99 ( V_14 ) ;
}
int F_100 ( const struct V_8 * V_9 )
{
return V_9 -> V_186 == F_96 ;
}
static int F_101 ( struct V_178 * V_179 ,
struct V_8 * V_9 )
{
struct V_18 * V_19 ;
struct V_113 * V_3 ;
if ( ! F_100 ( V_9 ) )
return 0 ;
V_19 = F_9 ( V_9 -> V_184 ) ;
if ( ! V_19 -> V_114 || V_19 -> V_114 -> V_180 . V_181 . V_182
!= & V_100 . V_182 )
return 0 ;
V_3 = F_43 ( V_19 -> V_114 ) ;
return & V_3 -> V_187 . V_181 == V_179 ;
}
static void F_102 ( struct V_8 * V_9 )
{
struct V_134 * V_135 = F_103 ( V_9 ) ;
F_98 ( V_9 -> V_184 ) ;
F_99 ( V_135 ) ;
}
int F_104 ( const struct V_8 * V_9 )
{
return V_9 -> V_186 == F_102 ;
}
static int F_105 ( struct V_178 * V_179 ,
struct V_8 * V_9 )
{
struct V_134 * V_135 ;
struct V_18 * V_19 ;
struct V_113 * V_3 ;
if ( ! F_104 ( V_9 ) )
return 0 ;
V_135 = F_103 ( V_9 ) ;
V_19 = F_52 ( V_135 ) ;
if ( ! V_19 -> V_114 || V_19 -> V_114 -> V_180 . V_181 . V_182
!= & V_100 . V_182 )
return 0 ;
V_3 = F_43 ( V_19 -> V_114 ) ;
return & V_3 -> V_188 . V_181 == V_179 ;
}
static enum V_189
F_106 ( struct V_190 * V_191 )
{
struct V_13 * V_14 = F_4 ( V_11 ( V_191 -> V_8 ) ) ;
if ( V_14 -> V_40 == V_115 )
return V_192 ;
return V_193 ;
}
static void
F_107 ( struct V_18 * V_19 , T_8 V_176 , T_8 V_194 , T_3 V_195 )
{
struct V_13 * V_14 ;
unsigned long V_136 ;
F_53 ( V_19 -> V_137 , V_136 ) ;
F_81 (rport, &fc_host_rports(shost), peers) {
if ( V_14 -> V_196 == - 1 )
continue;
if ( V_14 -> V_40 != V_197 )
continue;
if ( ( V_176 == V_14 -> V_176 ) &&
( V_194 == V_14 -> V_196 ) ) {
F_54 ( V_19 -> V_137 , V_136 ) ;
F_108 ( & V_14 -> V_9 , V_176 , V_194 , V_195 , 1 ) ;
return;
}
}
F_54 ( V_19 -> V_137 , V_136 ) ;
}
static int
F_109 ( struct V_18 * V_19 , T_8 V_176 , T_8 V_194 , T_3 V_195 )
{
T_8 V_198 , V_199 ;
T_8 V_200 , V_201 ;
if ( ( ( V_176 != V_202 ) && ( V_176 > V_19 -> V_203 ) ) ||
( ( V_194 != V_202 ) && ( V_194 >= V_19 -> V_204 ) ) ||
( ( V_195 != V_202 ) && ( V_195 > V_19 -> V_205 ) ) )
return - V_111 ;
if ( V_176 == V_202 ) {
V_198 = 0 ;
V_199 = V_19 -> V_203 + 1 ;
} else {
V_198 = V_176 ;
V_199 = V_176 + 1 ;
}
if ( V_194 == V_202 ) {
V_200 = 0 ;
V_201 = V_19 -> V_204 ;
} else {
V_200 = V_194 ;
V_201 = V_194 + 1 ;
}
for ( ; V_198 < V_199 ; V_198 ++ )
for ( ; V_200 < V_201 ; V_200 ++ )
F_107 ( V_19 , V_198 , V_200 , V_195 ) ;
return 0 ;
}
static int F_110 ( struct V_18 * V_19 , T_3 V_206 , T_3 V_207 ,
int V_208 )
{
struct V_113 * V_3 = F_43 ( V_19 -> V_114 ) ;
return V_3 -> V_121 -> V_209 ( V_19 , V_206 , V_207 , V_208 ) ;
}
static int F_111 ( struct V_18 * V_19 , T_3 V_206 , int V_208 )
{
struct V_113 * V_3 = F_43 ( V_19 -> V_114 ) ;
return V_3 -> V_121 -> V_210 ( V_19 , V_206 , V_208 ) ;
}
struct V_211 *
F_112 ( struct V_212 * V_213 )
{
int V_123 ;
struct V_113 * V_3 = F_113 ( sizeof( struct V_113 ) ,
V_81 ) ;
if ( F_114 ( ! V_3 ) )
return NULL ;
V_3 -> V_183 . V_185 . V_181 . V_214 = & V_3 -> V_215 [ 0 ] ;
V_3 -> V_183 . V_185 . V_181 . V_182 = & V_105 . V_182 ;
V_3 -> V_183 . V_185 . V_181 . V_175 = F_94 ;
V_3 -> V_183 . V_216 = sizeof( struct V_217 ) ;
F_115 ( & V_3 -> V_183 . V_185 ) ;
V_3 -> V_183 . V_180 . V_181 . V_214 = & V_3 -> V_180 [ 0 ] ;
V_3 -> V_183 . V_180 . V_181 . V_182 = & V_100 . V_182 ;
V_3 -> V_183 . V_180 . V_181 . V_175 = F_92 ;
V_3 -> V_183 . V_218 = sizeof( struct V_20 ) ;
if ( V_213 -> V_158 )
V_3 -> V_183 . V_180 . V_219 = & V_220 ;
F_115 ( & V_3 -> V_183 . V_180 ) ;
V_3 -> V_187 . V_181 . V_214 = & V_3 -> V_221 [ 0 ] ;
V_3 -> V_187 . V_181 . V_182 = & V_103 . V_182 ;
V_3 -> V_187 . V_181 . V_175 = F_101 ;
F_115 ( & V_3 -> V_187 ) ;
V_3 -> V_188 . V_181 . V_214 = & V_3 -> V_222 [ 0 ] ;
V_3 -> V_188 . V_181 . V_182 = & V_101 . V_182 ;
V_3 -> V_188 . V_181 . V_175 = F_105 ;
F_115 ( & V_3 -> V_188 ) ;
V_3 -> V_121 = V_213 ;
V_3 -> V_183 . V_223 = 1 ;
V_3 -> V_183 . V_224 = F_106 ;
V_3 -> V_183 . V_225 = F_109 ;
V_3 -> V_183 . V_209 = F_110 ;
V_3 -> V_183 . V_210 = F_111 ;
V_123 = 0 ;
F_116 ( V_15 ) ;
F_116 ( V_16 ) ;
F_116 ( V_17 ) ;
F_117 ( V_123 > V_226 ) ;
V_3 -> V_215 [ V_123 ] = NULL ;
V_123 = 0 ;
F_118 ( V_15 ) ;
F_118 ( V_16 ) ;
F_118 ( V_22 ) ;
F_118 ( V_23 ) ;
F_118 ( V_25 ) ;
F_118 ( V_26 ) ;
F_118 ( V_28 ) ;
if ( V_213 -> V_227 ) {
F_119 ( V_29 ) ;
F_119 ( V_55 ) ;
}
F_118 ( V_30 ) ;
F_118 ( V_31 ) ;
F_118 ( V_32 ) ;
F_118 ( V_33 ) ;
F_118 ( V_34 ) ;
F_118 ( V_35 ) ;
F_118 ( V_36 ) ;
F_118 ( V_37 ) ;
F_118 ( V_17 ) ;
F_118 ( V_38 ) ;
F_118 ( V_40 ) ;
F_118 ( V_42 ) ;
F_118 ( V_43 ) ;
F_118 ( V_44 ) ;
F_118 ( V_45 ) ;
F_120 ( V_46 ) ;
F_121 ( V_60 ) ;
F_121 ( V_47 ) ;
if ( V_213 -> V_154 )
F_121 ( V_228 ) ;
if ( V_213 -> V_227 )
F_121 ( V_227 ) ;
if ( V_213 -> V_229 )
F_121 ( V_229 ) ;
F_117 ( V_123 > V_230 ) ;
V_3 -> V_180 [ V_123 ] = NULL ;
V_123 = 0 ;
F_122 ( V_28 ) ;
F_122 ( V_23 ) ;
F_123 ( V_60 ) ;
F_124 ( V_15 ) ;
F_124 ( V_16 ) ;
F_124 ( V_17 ) ;
F_124 ( V_132 ) ;
F_124 ( V_40 ) ;
F_124 ( V_196 ) ;
F_125 ( V_119 ) ;
F_117 ( V_123 > V_231 ) ;
V_3 -> V_221 [ V_123 ] = NULL ;
V_123 = 0 ;
F_126 ( V_143 ) ;
F_126 ( V_232 ) ;
F_126 ( V_15 ) ;
F_126 ( V_16 ) ;
F_126 ( V_132 ) ;
F_126 ( V_169 ) ;
F_127 ( V_45 ) ;
F_128 ( V_229 ) ;
F_128 ( V_146 ) ;
F_117 ( V_123 > V_233 ) ;
V_3 -> V_222 [ V_123 ] = NULL ;
return & V_3 -> V_183 ;
}
void F_129 ( struct V_211 * V_183 )
{
struct V_113 * V_3 = F_43 ( V_183 ) ;
F_130 ( & V_3 -> V_183 . V_185 ) ;
F_130 ( & V_3 -> V_183 . V_180 ) ;
F_130 ( & V_3 -> V_187 ) ;
F_130 ( & V_3 -> V_188 ) ;
F_99 ( V_3 ) ;
}
static int
F_55 ( struct V_18 * V_19 , struct V_234 * V_235 )
{
if ( F_114 ( ! F_131 ( V_19 ) ) ) {
F_29 ( V_236
L_22
L_23 , V_19 -> V_237 -> V_76 ) ;
F_132 () ;
return - V_111 ;
}
return F_133 ( F_131 ( V_19 ) , V_235 ) ;
}
static void
F_134 ( struct V_18 * V_19 )
{
if ( ! F_131 ( V_19 ) ) {
F_29 ( V_236
L_24
L_23 , V_19 -> V_237 -> V_76 ) ;
F_132 () ;
return;
}
F_135 ( F_131 ( V_19 ) ) ;
}
static int
F_136 ( struct V_18 * V_19 , struct V_238 * V_235 ,
unsigned long V_239 )
{
if ( F_114 ( ! F_137 ( V_19 ) ) ) {
F_29 ( V_236
L_22
L_23 , V_19 -> V_237 -> V_76 ) ;
F_132 () ;
return - V_111 ;
}
return F_138 ( F_137 ( V_19 ) , V_235 , V_239 ) ;
}
static void
F_139 ( struct V_18 * V_19 )
{
if ( ! F_137 ( V_19 ) ) {
F_29 ( V_236
L_24
L_23 , V_19 -> V_237 -> V_76 ) ;
F_132 () ;
return;
}
F_135 ( F_137 ( V_19 ) ) ;
}
void
F_140 ( struct V_18 * V_19 )
{
struct V_134 * V_135 = NULL , * V_240 = NULL ;
struct V_13 * V_14 = NULL , * V_241 = NULL ;
struct V_242 * V_58 ;
struct V_20 * V_21 = F_10 ( V_19 ) ;
unsigned long V_136 ;
F_53 ( V_19 -> V_137 , V_136 ) ;
F_141 (vport, next_vport, &fc_host->vports, peers)
F_55 ( V_19 , & V_135 -> V_141 ) ;
F_141 (rport, next_rport,
&fc_host->rports, peers) {
F_77 ( & V_14 -> V_151 ) ;
V_14 -> V_40 = V_116 ;
F_55 ( V_19 , & V_14 -> V_152 ) ;
}
F_141 (rport, next_rport,
&fc_host->rport_bindings, peers) {
F_77 ( & V_14 -> V_151 ) ;
V_14 -> V_40 = V_116 ;
F_55 ( V_19 , & V_14 -> V_152 ) ;
}
F_54 ( V_19 -> V_137 , V_136 ) ;
F_142 ( V_19 ) ;
if ( V_21 -> V_58 ) {
V_58 = V_21 -> V_58 ;
V_21 -> V_58 = NULL ;
F_13 ( V_58 ) ;
}
if ( V_21 -> V_63 ) {
V_58 = V_21 -> V_63 ;
V_21 -> V_63 = NULL ;
F_13 ( V_58 ) ;
}
}
static void F_143 ( struct V_13 * V_14 )
{
struct V_18 * V_19 = F_42 ( V_14 ) ;
struct V_113 * V_3 = F_43 ( V_19 -> V_114 ) ;
if ( V_3 -> V_121 -> V_243 )
V_3 -> V_121 -> V_243 ( V_14 ) ;
F_144 ( & V_14 -> V_9 , V_244 ) ;
}
static void
F_145 ( struct V_234 * V_235 )
{
struct V_13 * V_14 =
F_146 ( V_235 , struct V_13 , V_245 ) ;
F_143 ( V_14 ) ;
F_147 ( & V_14 -> V_9 ) ;
}
static void
F_148 ( struct V_234 * V_235 )
{
struct V_13 * V_14 =
F_146 ( V_235 , struct V_13 , V_152 ) ;
struct V_8 * V_9 = & V_14 -> V_9 ;
struct V_18 * V_19 = F_42 ( V_14 ) ;
struct V_113 * V_3 = F_43 ( V_19 -> V_114 ) ;
unsigned long V_136 ;
int V_246 = 0 ;
F_143 ( V_14 ) ;
if ( V_14 -> V_136 & V_247 )
F_142 ( V_19 ) ;
F_53 ( V_19 -> V_137 , V_136 ) ;
if ( V_14 -> V_136 & V_248 ) {
F_54 ( V_19 -> V_137 , V_136 ) ;
if ( ! F_149 ( & V_14 -> V_249 ) )
F_139 ( V_19 ) ;
if ( ! F_149 ( & V_14 -> V_250 ) )
F_139 ( V_19 ) ;
F_150 ( & V_14 -> V_251 ) ;
F_53 ( V_19 -> V_137 , V_136 ) ;
V_14 -> V_136 &= ~ V_248 ;
}
F_54 ( V_19 -> V_137 , V_136 ) ;
if ( V_14 -> V_196 != - 1 )
F_145 ( & V_14 -> V_245 ) ;
F_53 ( V_19 -> V_137 , V_136 ) ;
if ( ! ( V_14 -> V_136 & V_252 ) &&
( V_3 -> V_121 -> V_253 ) ) {
V_14 -> V_136 |= V_252 ;
V_246 = 1 ;
}
F_54 ( V_19 -> V_137 , V_136 ) ;
if ( V_246 )
V_3 -> V_121 -> V_253 ( V_14 ) ;
F_16 ( V_14 -> V_64 ) ;
F_151 ( V_9 ) ;
F_152 ( V_9 ) ;
F_153 ( V_9 ) ;
F_98 ( & V_19 -> V_172 ) ;
F_98 ( V_9 ) ;
}
static struct V_13 *
F_154 ( struct V_18 * V_19 , int V_176 ,
struct V_254 * V_255 )
{
struct V_20 * V_21 = F_10 ( V_19 ) ;
struct V_113 * V_256 = F_43 ( V_19 -> V_114 ) ;
struct V_13 * V_14 ;
struct V_8 * V_9 ;
unsigned long V_136 ;
int error ;
T_7 V_257 ;
V_257 = ( sizeof( struct V_13 ) + V_256 -> V_121 -> V_258 ) ;
V_14 = F_113 ( V_257 , V_81 ) ;
if ( F_114 ( ! V_14 ) ) {
F_29 ( V_236 L_25 , V_94 ) ;
return NULL ;
}
V_14 -> V_28 = - 1 ;
V_14 -> V_23 = V_24 ;
V_14 -> V_60 = V_21 -> V_60 ;
memcpy ( & V_14 -> V_15 , & V_255 -> V_15 , sizeof( V_14 -> V_15 ) ) ;
memcpy ( & V_14 -> V_16 , & V_255 -> V_16 , sizeof( V_14 -> V_16 ) ) ;
V_14 -> V_17 = V_255 -> V_17 ;
V_14 -> V_132 = V_255 -> V_132 ;
V_14 -> V_40 = V_197 ;
if ( V_256 -> V_121 -> V_258 )
V_14 -> V_259 = & V_14 [ 1 ] ;
V_14 -> V_176 = V_176 ;
V_14 -> V_119 = - 1 ;
F_155 ( & V_14 -> V_250 , V_260 ) ;
F_155 ( & V_14 -> V_249 , V_261 ) ;
F_156 ( & V_14 -> V_251 , V_262 ) ;
F_156 ( & V_14 -> V_245 , F_145 ) ;
F_156 ( & V_14 -> V_152 , F_148 ) ;
F_53 ( V_19 -> V_137 , V_136 ) ;
V_14 -> V_263 = V_21 -> V_52 ++ ;
if ( V_14 -> V_132 & V_264 )
V_14 -> V_196 = V_21 -> V_53 ++ ;
else
V_14 -> V_196 = - 1 ;
F_157 ( & V_14 -> V_151 , & V_21 -> V_49 ) ;
F_158 ( & V_19 -> V_172 ) ;
F_54 ( V_19 -> V_137 , V_136 ) ;
V_9 = & V_14 -> V_9 ;
F_159 ( V_9 ) ;
V_9 -> V_184 = F_158 ( & V_19 -> V_172 ) ;
V_9 -> V_186 = F_96 ;
F_160 ( V_9 , L_26 ,
V_19 -> V_57 , V_176 , V_14 -> V_263 ) ;
F_161 ( V_9 ) ;
error = F_162 ( V_9 ) ;
if ( error ) {
F_29 ( V_236 L_27 ) ;
goto V_265;
}
F_163 ( V_9 ) ;
F_164 ( V_9 ) ;
F_165 ( V_19 , V_14 ) ;
if ( V_14 -> V_132 & V_264 ) {
V_14 -> V_136 |= V_247 ;
F_166 ( V_19 , & V_14 -> V_251 ) ;
}
return V_14 ;
V_265:
F_153 ( V_9 ) ;
F_53 ( V_19 -> V_137 , V_136 ) ;
F_77 ( & V_14 -> V_151 ) ;
F_98 ( & V_19 -> V_172 ) ;
F_54 ( V_19 -> V_137 , V_136 ) ;
F_98 ( V_9 -> V_184 ) ;
F_99 ( V_14 ) ;
return NULL ;
}
struct V_13 *
F_167 ( struct V_18 * V_19 , int V_176 ,
struct V_254 * V_255 )
{
struct V_113 * V_256 = F_43 ( V_19 -> V_114 ) ;
struct V_20 * V_21 = F_10 ( V_19 ) ;
struct V_13 * V_14 ;
unsigned long V_136 ;
int V_175 = 0 ;
F_134 ( V_19 ) ;
F_53 ( V_19 -> V_137 , V_136 ) ;
F_81 (rport, &fc_host->rports, peers) {
if ( ( V_14 -> V_40 == V_115 ) &&
( V_14 -> V_176 == V_176 ) ) {
switch ( V_21 -> V_47 ) {
case V_48 :
case V_266 :
if ( V_14 -> V_16 == V_255 -> V_16 )
V_175 = 1 ;
break;
case V_267 :
if ( V_14 -> V_15 == V_255 -> V_15 )
V_175 = 1 ;
break;
case V_268 :
if ( V_14 -> V_17 == V_255 -> V_17 )
V_175 = 1 ;
break;
}
if ( V_175 ) {
memcpy ( & V_14 -> V_15 , & V_255 -> V_15 ,
sizeof( V_14 -> V_15 ) ) ;
memcpy ( & V_14 -> V_16 , & V_255 -> V_16 ,
sizeof( V_14 -> V_16 ) ) ;
V_14 -> V_17 = V_255 -> V_17 ;
V_14 -> V_40 = V_197 ;
V_14 -> V_132 = V_255 -> V_132 ;
F_54 ( V_19 -> V_137 , V_136 ) ;
if ( V_256 -> V_121 -> V_258 )
memset ( V_14 -> V_259 , 0 ,
V_256 -> V_121 -> V_258 ) ;
if ( ( V_14 -> V_196 != - 1 ) &&
( ! ( V_255 -> V_132 & V_264 ) ) )
return V_14 ;
if ( ! F_149 ( & V_14 -> V_249 ) )
F_139 ( V_19 ) ;
if ( ! F_149 ( & V_14 -> V_250 ) )
F_139 ( V_19 ) ;
F_53 ( V_19 -> V_137 , V_136 ) ;
V_14 -> V_136 &= ~ ( V_269 |
V_248 |
V_252 ) ;
F_54 ( V_19 -> V_137 , V_136 ) ;
if ( V_14 -> V_196 != - 1 ) {
F_144 ( & V_14 -> V_9 ,
V_270 ) ;
F_53 ( V_19 -> V_137 ,
V_136 ) ;
V_14 -> V_136 |= V_247 ;
F_166 ( V_19 ,
& V_14 -> V_251 ) ;
F_54 ( V_19 -> V_137 ,
V_136 ) ;
}
F_168 ( V_14 ) ;
return V_14 ;
}
}
}
if ( V_21 -> V_47 != V_266 ) {
F_81 (rport, &fc_host->rport_bindings,
peers) {
if ( V_14 -> V_176 != V_176 )
continue;
switch ( V_21 -> V_47 ) {
case V_48 :
if ( V_14 -> V_16 == V_255 -> V_16 )
V_175 = 1 ;
break;
case V_267 :
if ( V_14 -> V_15 == V_255 -> V_15 )
V_175 = 1 ;
break;
case V_268 :
if ( V_14 -> V_17 == V_255 -> V_17 )
V_175 = 1 ;
break;
case V_266 :
break;
}
if ( V_175 ) {
F_169 ( & V_14 -> V_151 , & V_21 -> V_49 ) ;
break;
}
}
if ( V_175 ) {
memcpy ( & V_14 -> V_15 , & V_255 -> V_15 ,
sizeof( V_14 -> V_15 ) ) ;
memcpy ( & V_14 -> V_16 , & V_255 -> V_16 ,
sizeof( V_14 -> V_16 ) ) ;
V_14 -> V_17 = V_255 -> V_17 ;
V_14 -> V_132 = V_255 -> V_132 ;
V_14 -> V_40 = V_197 ;
V_14 -> V_136 &= ~ V_269 ;
if ( V_256 -> V_121 -> V_258 )
memset ( V_14 -> V_259 , 0 ,
V_256 -> V_121 -> V_258 ) ;
F_54 ( V_19 -> V_137 , V_136 ) ;
if ( V_255 -> V_132 & V_264 ) {
F_144 ( & V_14 -> V_9 , V_270 ) ;
F_53 ( V_19 -> V_137 , V_136 ) ;
V_14 -> V_136 |= V_247 ;
F_166 ( V_19 , & V_14 -> V_251 ) ;
F_54 ( V_19 -> V_137 , V_136 ) ;
}
return V_14 ;
}
}
F_54 ( V_19 -> V_137 , V_136 ) ;
V_14 = F_154 ( V_19 , V_176 , V_255 ) ;
return V_14 ;
}
void
F_170 ( struct V_13 * V_14 )
{
struct V_18 * V_19 = F_42 ( V_14 ) ;
unsigned long V_271 = V_14 -> V_60 ;
unsigned long V_136 ;
F_53 ( V_19 -> V_137 , V_136 ) ;
if ( V_14 -> V_40 != V_197 ) {
F_54 ( V_19 -> V_137 , V_136 ) ;
return;
}
V_14 -> V_40 = V_115 ;
V_14 -> V_136 |= V_248 ;
F_54 ( V_19 -> V_137 , V_136 ) ;
F_171 ( & V_14 -> V_9 ) ;
if ( ( V_14 -> V_119 != - 1 ) &&
( V_14 -> V_119 < V_271 ) )
F_136 ( V_19 , & V_14 -> V_249 ,
V_14 -> V_119 * V_272 ) ;
F_136 ( V_19 , & V_14 -> V_250 , V_271 * V_272 ) ;
}
void
F_172 ( struct V_13 * V_14 , T_2 V_132 )
{
struct V_18 * V_19 = F_42 ( V_14 ) ;
struct V_20 * V_21 = F_10 ( V_19 ) ;
unsigned long V_136 ;
int V_273 = 0 ;
F_53 ( V_19 -> V_137 , V_136 ) ;
if ( V_132 & V_264 ) {
if ( V_14 -> V_196 == - 1 ) {
V_14 -> V_196 = V_21 -> V_53 ++ ;
V_273 = 1 ;
} else if ( ! ( V_14 -> V_132 & V_264 ) )
V_273 = 1 ;
}
V_14 -> V_132 = V_132 ;
F_54 ( V_19 -> V_137 , V_136 ) ;
if ( V_273 ) {
if ( ! F_149 ( & V_14 -> V_249 ) )
F_139 ( V_19 ) ;
if ( ! F_149 ( & V_14 -> V_250 ) )
F_139 ( V_19 ) ;
F_53 ( V_19 -> V_137 , V_136 ) ;
V_14 -> V_136 &= ~ ( V_269 |
V_248 |
V_252 ) ;
F_54 ( V_19 -> V_137 , V_136 ) ;
F_134 ( V_19 ) ;
F_144 ( & V_14 -> V_9 , V_270 ) ;
F_53 ( V_19 -> V_137 , V_136 ) ;
V_14 -> V_136 |= V_247 ;
F_166 ( V_19 , & V_14 -> V_251 ) ;
F_54 ( V_19 -> V_137 , V_136 ) ;
}
}
static void
V_260 ( struct V_234 * V_235 )
{
struct V_13 * V_14 =
F_146 ( V_235 , struct V_13 , V_250 . V_235 ) ;
struct V_18 * V_19 = F_42 ( V_14 ) ;
struct V_113 * V_3 = F_43 ( V_19 -> V_114 ) ;
struct V_20 * V_21 = F_10 ( V_19 ) ;
unsigned long V_136 ;
int V_246 = 0 ;
F_53 ( V_19 -> V_137 , V_136 ) ;
V_14 -> V_136 &= ~ V_248 ;
if ( ( V_14 -> V_40 == V_197 ) &&
( V_14 -> V_196 != - 1 ) &&
! ( V_14 -> V_132 & V_264 ) ) {
F_173 ( V_236 , & V_14 -> V_9 ,
L_28
L_29 ) ;
F_54 ( V_19 -> V_137 , V_136 ) ;
F_144 ( & V_14 -> V_9 , V_244 ) ;
F_55 ( V_19 , & V_14 -> V_245 ) ;
return;
}
if ( V_14 -> V_40 != V_115 ) {
F_54 ( V_19 -> V_137 , V_136 ) ;
F_173 ( V_236 , & V_14 -> V_9 ,
L_30
L_31 ,
( V_14 -> V_196 != - 1 ) ? L_32 : L_33 ) ;
return;
}
if ( ( V_21 -> V_47 == V_266 ) ||
( V_14 -> V_196 == - 1 ) ) {
F_77 ( & V_14 -> V_151 ) ;
V_14 -> V_40 = V_116 ;
F_173 ( V_236 , & V_14 -> V_9 ,
L_34
L_35 ,
( V_14 -> V_196 != - 1 ) ? L_32 : L_33 ) ;
F_55 ( V_19 , & V_14 -> V_152 ) ;
F_54 ( V_19 -> V_137 , V_136 ) ;
return;
}
F_173 ( V_236 , & V_14 -> V_9 ,
L_36
L_37 ) ;
F_169 ( & V_14 -> V_151 , & V_21 -> V_50 ) ;
V_14 -> V_28 = - 1 ;
V_14 -> V_23 = V_24 ;
V_14 -> V_132 = V_133 ;
V_14 -> V_40 = V_117 ;
V_14 -> V_136 &= ~ V_269 ;
F_54 ( V_19 -> V_137 , V_136 ) ;
F_143 ( V_14 ) ;
F_53 ( V_19 -> V_137 , V_136 ) ;
if ( V_14 -> V_40 == V_117 ) {
switch ( V_21 -> V_47 ) {
case V_48 :
V_14 -> V_15 = - 1 ;
V_14 -> V_17 = - 1 ;
break;
case V_267 :
V_14 -> V_16 = - 1 ;
V_14 -> V_17 = - 1 ;
break;
case V_268 :
V_14 -> V_15 = - 1 ;
V_14 -> V_16 = - 1 ;
break;
case V_266 :
break;
}
V_14 -> V_136 |= V_252 ;
F_55 ( V_19 , & V_14 -> V_245 ) ;
V_246 = 1 ;
}
F_54 ( V_19 -> V_137 , V_136 ) ;
if ( V_246 && V_3 -> V_121 -> V_253 )
V_3 -> V_121 -> V_253 ( V_14 ) ;
}
static void
V_261 ( struct V_234 * V_235 )
{
struct V_13 * V_14 =
F_146 ( V_235 , struct V_13 , V_249 . V_235 ) ;
if ( V_14 -> V_40 != V_115 )
return;
V_14 -> V_136 |= V_269 ;
F_143 ( V_14 ) ;
}
static void
V_262 ( struct V_234 * V_235 )
{
struct V_13 * V_14 =
F_146 ( V_235 , struct V_13 , V_251 ) ;
struct V_18 * V_19 = F_42 ( V_14 ) ;
struct V_113 * V_3 = F_43 ( V_19 -> V_114 ) ;
unsigned long V_136 ;
if ( ( V_14 -> V_40 == V_197 ) &&
( V_14 -> V_132 & V_264 ) &&
! ( V_3 -> V_121 -> V_274 ) ) {
F_108 ( & V_14 -> V_9 , V_14 -> V_176 ,
V_14 -> V_196 , V_202 , 1 ) ;
}
F_53 ( V_19 -> V_137 , V_136 ) ;
V_14 -> V_136 &= ~ V_247 ;
F_54 ( V_19 -> V_137 , V_136 ) ;
}
int F_174 ( struct V_190 * V_275 )
{
struct V_18 * V_19 = V_275 -> V_8 -> V_276 ;
struct V_13 * V_14 = F_4 ( V_11 ( V_275 -> V_8 ) ) ;
unsigned long V_136 ;
F_53 ( V_19 -> V_137 , V_136 ) ;
while ( V_14 -> V_40 == V_115 &&
! ( V_14 -> V_136 & V_269 ) ) {
F_54 ( V_19 -> V_137 , V_136 ) ;
F_175 ( 1000 ) ;
F_53 ( V_19 -> V_137 , V_136 ) ;
}
F_54 ( V_19 -> V_137 , V_136 ) ;
if ( V_14 -> V_136 & V_269 )
return V_277 ;
return 0 ;
}
static int
F_89 ( struct V_18 * V_19 , int V_176 , struct V_8 * V_278 ,
struct V_165 * V_255 , struct V_134 * * V_279 )
{
struct V_20 * V_21 = F_10 ( V_19 ) ;
struct V_113 * V_256 = F_43 ( V_19 -> V_114 ) ;
struct V_134 * V_135 ;
struct V_8 * V_9 ;
unsigned long V_136 ;
T_7 V_257 ;
int error ;
* V_279 = NULL ;
if ( ! V_256 -> V_121 -> V_227 )
return - V_79 ;
V_257 = ( sizeof( struct V_134 ) + V_256 -> V_121 -> V_280 ) ;
V_135 = F_113 ( V_257 , V_81 ) ;
if ( F_114 ( ! V_135 ) ) {
F_29 ( V_236 L_25 , V_94 ) ;
return - V_59 ;
}
V_135 -> V_143 = V_281 ;
V_135 -> V_232 = V_281 ;
V_135 -> V_15 = V_255 -> V_15 ;
V_135 -> V_16 = V_255 -> V_16 ;
V_135 -> V_132 = V_255 -> V_132 ;
V_135 -> V_169 = V_255 -> V_169 ;
if ( V_256 -> V_121 -> V_280 )
V_135 -> V_259 = & V_135 [ 1 ] ;
V_135 -> V_19 = V_19 ;
V_135 -> V_176 = V_176 ;
V_135 -> V_136 = V_139 ;
F_156 ( & V_135 -> V_141 , V_282 ) ;
F_53 ( V_19 -> V_137 , V_136 ) ;
if ( V_21 -> V_55 >= V_21 -> V_29 ) {
F_54 ( V_19 -> V_137 , V_136 ) ;
F_99 ( V_135 ) ;
return - V_283 ;
}
V_21 -> V_55 ++ ;
V_135 -> V_263 = V_21 -> V_54 ++ ;
F_157 ( & V_135 -> V_151 , & V_21 -> V_51 ) ;
F_158 ( & V_19 -> V_172 ) ;
F_54 ( V_19 -> V_137 , V_136 ) ;
V_9 = & V_135 -> V_9 ;
F_159 ( V_9 ) ;
V_9 -> V_184 = F_158 ( V_278 ) ;
V_9 -> V_186 = F_102 ;
F_160 ( V_9 , L_38 ,
V_19 -> V_57 , V_176 , V_135 -> V_263 ) ;
F_161 ( V_9 ) ;
error = F_162 ( V_9 ) ;
if ( error ) {
F_29 ( V_236 L_39 ) ;
goto V_284;
}
F_163 ( V_9 ) ;
F_164 ( V_9 ) ;
error = V_256 -> V_121 -> V_227 ( V_135 , V_255 -> V_171 ) ;
if ( error ) {
F_29 ( V_236 L_40 ) ;
goto V_285;
}
if ( V_278 != & V_19 -> V_172 ) {
error = F_176 ( & V_19 -> V_172 . V_286 ,
& V_9 -> V_286 , F_177 ( V_9 ) ) ;
if ( error )
F_29 ( V_236
L_41
L_42 ,
V_94 , F_177 ( V_9 ) , error ) ;
}
F_53 ( V_19 -> V_137 , V_136 ) ;
V_135 -> V_136 &= ~ V_139 ;
F_54 ( V_19 -> V_137 , V_136 ) ;
F_173 ( V_287 , V_278 ,
L_43 , F_177 ( V_9 ) ,
V_19 -> V_57 , V_176 ) ;
* V_279 = V_135 ;
return 0 ;
V_285:
F_151 ( V_9 ) ;
F_152 ( V_9 ) ;
V_284:
F_153 ( V_9 ) ;
F_53 ( V_19 -> V_137 , V_136 ) ;
F_77 ( & V_135 -> V_151 ) ;
F_98 ( & V_19 -> V_172 ) ;
V_21 -> V_55 -- ;
F_54 ( V_19 -> V_137 , V_136 ) ;
F_98 ( V_9 -> V_184 ) ;
F_99 ( V_135 ) ;
return error ;
}
struct V_134 *
F_178 ( struct V_18 * V_19 , int V_176 ,
struct V_165 * V_255 )
{
int V_142 ;
struct V_134 * V_135 ;
V_142 = F_89 ( V_19 , V_176 , & V_19 -> V_172 ,
V_255 , & V_135 ) ;
return V_142 ? NULL : V_135 ;
}
int
F_91 ( struct V_134 * V_135 )
{
struct V_18 * V_19 = F_52 ( V_135 ) ;
struct V_20 * V_21 = F_10 ( V_19 ) ;
struct V_113 * V_3 = F_43 ( V_19 -> V_114 ) ;
struct V_8 * V_9 = & V_135 -> V_9 ;
unsigned long V_136 ;
int V_142 ;
if ( V_3 -> V_121 -> V_229 )
V_142 = V_3 -> V_121 -> V_229 ( V_135 ) ;
else
V_142 = - V_79 ;
F_53 ( V_19 -> V_137 , V_136 ) ;
V_135 -> V_136 &= ~ V_140 ;
if ( ! V_142 ) {
V_135 -> V_136 |= V_288 ;
F_77 ( & V_135 -> V_151 ) ;
V_21 -> V_55 -- ;
F_98 ( & V_19 -> V_172 ) ;
}
F_54 ( V_19 -> V_137 , V_136 ) ;
if ( V_142 )
return V_142 ;
if ( V_9 -> V_184 != & V_19 -> V_172 )
F_179 ( & V_19 -> V_172 . V_286 , F_177 ( V_9 ) ) ;
F_151 ( V_9 ) ;
F_152 ( V_9 ) ;
F_153 ( V_9 ) ;
F_98 ( V_9 ) ;
return 0 ;
}
static void
V_282 ( struct V_234 * V_235 )
{
struct V_134 * V_135 =
F_146 ( V_235 , struct V_134 , V_141 ) ;
int V_142 ;
V_142 = F_91 ( V_135 ) ;
if ( V_142 )
F_173 ( V_236 , V_135 -> V_9 . V_184 ,
L_44
L_45 , V_94 ,
F_177 ( & V_135 -> V_9 ) , V_135 -> V_19 -> V_57 ,
V_135 -> V_176 , V_142 ) ;
}
static void
F_180 ( struct V_289 * V_290 )
{
unsigned long V_136 ;
F_53 ( & V_290 -> V_291 , V_136 ) ;
if ( V_290 -> V_292 ) {
F_54 ( & V_290 -> V_291 , V_136 ) ;
return;
}
F_54 ( & V_290 -> V_291 , V_136 ) ;
F_98 ( V_290 -> V_9 ) ;
F_99 ( V_290 -> V_293 . V_294 ) ;
F_99 ( V_290 -> V_295 . V_294 ) ;
F_99 ( V_290 ) ;
}
static void
F_181 ( struct V_289 * V_290 )
{
struct V_296 * V_297 = V_290 -> V_297 ;
struct V_296 * V_298 = V_297 -> V_299 ;
int V_77 ;
V_77 = V_290 -> V_297 -> V_300 = V_290 -> V_301 -> V_208 ;
if ( V_77 < 0 )
V_290 -> V_297 -> V_302 = sizeof( V_303 ) ;
else
V_290 -> V_297 -> V_302 = V_290 -> V_304 ;
V_297 -> V_305 = 0 ;
if ( V_298 ) {
F_83 ( V_290 -> V_301 -> V_306 > V_298 -> V_305 ) ;
V_298 -> V_305 -= F_182 ( V_290 -> V_301 -> V_306 ,
V_298 -> V_305 ) ;
}
F_183 ( V_297 ) ;
}
static void F_184 ( struct V_296 * V_307 )
{
struct V_289 * V_290 = V_307 -> V_308 ;
unsigned long V_136 ;
F_53 ( & V_290 -> V_291 , V_136 ) ;
V_290 -> V_309 |= V_310 ;
V_290 -> V_292 -- ;
F_54 ( & V_290 -> V_291 , V_136 ) ;
F_185 ( V_307 , V_307 -> V_300 ) ;
F_180 ( V_290 ) ;
}
static enum V_189
F_186 ( struct V_296 * V_297 )
{
struct V_289 * V_290 = ( void * ) V_297 -> V_308 ;
struct V_18 * V_19 = V_290 -> V_19 ;
struct V_113 * V_3 = F_43 ( V_19 -> V_114 ) ;
unsigned long V_136 ;
int V_77 = 0 , V_311 = 0 ;
if ( V_290 -> V_14 && V_290 -> V_14 -> V_40 == V_115 )
return V_192 ;
F_53 ( & V_290 -> V_291 , V_136 ) ;
if ( V_290 -> V_309 & V_310 )
V_311 = 1 ;
else
V_290 -> V_292 ++ ;
F_54 ( & V_290 -> V_291 , V_136 ) ;
if ( ! V_311 && V_3 -> V_121 -> V_312 ) {
V_77 = V_3 -> V_121 -> V_312 ( V_290 ) ;
if ( V_77 == - V_313 ) {
V_290 -> V_292 -- ;
return V_192 ;
} else if ( V_77 )
F_29 ( V_236 L_46
L_47 , V_77 ) ;
}
if ( V_311 )
return V_193 ;
else
return V_314 ;
}
static int
F_187 ( struct V_315 * V_1 , struct V_296 * V_297 )
{
T_7 V_316 = ( sizeof( struct V_317 ) * V_297 -> V_318 ) ;
F_117 ( ! V_297 -> V_318 ) ;
V_1 -> V_294 = F_113 ( V_316 , V_81 ) ;
if ( ! V_1 -> V_294 )
return - V_59 ;
F_188 ( V_1 -> V_294 , V_297 -> V_318 ) ;
V_1 -> V_319 = F_189 ( V_297 -> V_320 , V_297 , V_1 -> V_294 ) ;
V_1 -> V_321 = F_190 ( V_297 ) ;
return 0 ;
}
static int
F_191 ( struct V_18 * V_19 , struct V_13 * V_14 ,
struct V_296 * V_297 )
{
struct V_113 * V_3 = F_43 ( V_19 -> V_114 ) ;
struct V_296 * V_298 = V_297 -> V_299 ;
struct V_289 * V_290 ;
int V_153 ;
F_117 ( V_297 -> V_308 ) ;
V_290 = F_113 ( sizeof( struct V_289 ) + V_3 -> V_121 -> V_322 ,
V_81 ) ;
if ( ! V_290 )
return - V_59 ;
V_297 -> V_308 = V_290 ;
V_290 -> V_19 = V_19 ;
V_290 -> V_14 = V_14 ;
V_290 -> V_297 = V_297 ;
if ( V_3 -> V_121 -> V_322 )
V_290 -> V_259 = ( void * ) & V_290 [ 1 ] ;
F_192 ( & V_290 -> V_291 ) ;
V_290 -> V_296 = (struct V_323 * ) V_297 -> V_324 ;
V_290 -> V_325 = V_297 -> V_326 ;
V_290 -> V_301 = V_297 -> V_327 ;
V_290 -> V_304 = V_328 ;
if ( V_297 -> V_329 ) {
V_153 = F_187 ( & V_290 -> V_293 , V_297 ) ;
if ( V_153 )
goto V_330;
}
if ( V_298 && V_298 -> V_329 ) {
V_153 = F_187 ( & V_290 -> V_295 , V_298 ) ;
if ( V_153 )
goto V_331;
}
V_290 -> V_332 = F_181 ;
if ( V_14 )
V_290 -> V_9 = & V_14 -> V_9 ;
else
V_290 -> V_9 = & V_19 -> V_172 ;
F_158 ( V_290 -> V_9 ) ;
V_290 -> V_292 = 1 ;
return 0 ;
V_331:
F_99 ( V_290 -> V_293 . V_294 ) ;
V_330:
F_99 ( V_290 ) ;
return - V_59 ;
}
static enum V_333
F_193 ( struct V_334 * V_320 , struct V_18 * V_19 ,
struct V_289 * V_290 )
{
struct V_113 * V_3 = F_43 ( V_19 -> V_114 ) ;
int V_335 = sizeof( V_303 ) ;
int V_153 ;
switch ( V_290 -> V_296 -> V_336 ) {
case V_337 :
V_335 += sizeof( struct V_338 ) ;
break;
case V_339 :
V_335 += sizeof( struct V_340 ) ;
break;
case V_341 :
V_335 += sizeof( struct V_342 ) ;
if ( ( ! V_290 -> V_293 . V_321 ) ||
( ! V_290 -> V_295 . V_321 ) ) {
V_153 = - V_111 ;
goto V_343;
}
break;
case V_344 :
V_335 += sizeof( struct V_345 ) ;
if ( ( ! V_290 -> V_293 . V_321 ) ||
( ! V_290 -> V_295 . V_321 ) ) {
V_153 = - V_111 ;
goto V_343;
}
break;
case V_346 :
V_335 += sizeof( struct V_347 ) ;
if ( ( V_19 -> V_237 -> V_89 == 0L ) ||
( V_290 -> V_296 -> V_348 . V_349 . V_89 !=
V_19 -> V_237 -> V_89 ) ) {
V_153 = - V_350 ;
goto V_343;
}
break;
default:
V_153 = - V_351 ;
goto V_343;
}
if ( V_290 -> V_325 < V_335 ) {
V_153 = - V_352 ;
goto V_343;
}
V_153 = V_3 -> V_121 -> V_353 ( V_290 ) ;
if ( ! V_153 )
return V_354 ;
V_343:
F_117 ( V_290 -> V_304 < sizeof( V_303 ) ) ;
V_290 -> V_301 -> V_306 = 0 ;
V_290 -> V_301 -> V_208 = V_153 ;
V_290 -> V_304 = sizeof( V_303 ) ;
F_181 ( V_290 ) ;
return V_354 ;
}
static void
F_168 ( struct V_13 * V_14 )
{
if ( ! V_14 -> V_64 )
return;
F_158 ( & V_14 -> V_9 ) ;
F_194 ( V_14 -> V_64 ) ;
F_98 ( & V_14 -> V_9 ) ;
}
static enum V_333
F_195 ( struct V_334 * V_320 , struct V_18 * V_19 ,
struct V_13 * V_14 , struct V_289 * V_290 )
{
struct V_113 * V_3 = F_43 ( V_19 -> V_114 ) ;
int V_335 = sizeof( V_303 ) ;
int V_153 ;
switch ( V_290 -> V_296 -> V_336 ) {
case V_355 :
V_335 += sizeof( struct V_356 ) ;
goto V_357;
case V_358 :
V_335 += sizeof( struct V_359 ) ;
V_357:
if ( ( ! V_290 -> V_293 . V_321 ) ||
( ! V_290 -> V_295 . V_321 ) ) {
V_153 = - V_111 ;
goto V_360;
}
break;
default:
V_153 = - V_351 ;
goto V_360;
}
if ( V_290 -> V_325 < V_335 ) {
V_153 = - V_352 ;
goto V_360;
}
V_153 = V_3 -> V_121 -> V_353 ( V_290 ) ;
if ( ! V_153 )
return V_354 ;
V_360:
F_117 ( V_290 -> V_304 < sizeof( V_303 ) ) ;
V_290 -> V_301 -> V_306 = 0 ;
V_290 -> V_301 -> V_208 = V_153 ;
V_290 -> V_304 = sizeof( V_303 ) ;
F_181 ( V_290 ) ;
return V_354 ;
}
static void
F_196 ( struct V_334 * V_320 , struct V_18 * V_19 ,
struct V_13 * V_14 , struct V_8 * V_9 )
{
struct V_296 * V_297 ;
struct V_289 * V_290 ;
enum V_333 V_153 ;
if ( ! F_158 ( V_9 ) )
return;
while ( 1 ) {
if ( V_14 && ( V_14 -> V_40 == V_115 ) &&
! ( V_14 -> V_136 & V_269 ) )
break;
V_297 = F_197 ( V_320 ) ;
if ( ! V_297 )
break;
if ( V_14 && ( V_14 -> V_40 != V_197 ) ) {
V_297 -> V_300 = - V_361 ;
F_198 ( V_320 -> V_362 ) ;
F_185 ( V_297 , - V_361 ) ;
F_199 ( V_320 -> V_362 ) ;
continue;
}
F_198 ( V_320 -> V_362 ) ;
V_153 = F_191 ( V_19 , V_14 , V_297 ) ;
if ( V_153 ) {
V_297 -> V_300 = V_153 ;
F_185 ( V_297 , V_153 ) ;
F_199 ( V_320 -> V_362 ) ;
continue;
}
V_290 = V_297 -> V_308 ;
if ( V_290 -> V_325 < sizeof( V_303 ) ) {
F_117 ( V_290 -> V_304 < sizeof( V_303 ) ) ;
V_290 -> V_301 -> V_306 = 0 ;
V_290 -> V_301 -> V_208 = - V_352 ;
V_290 -> V_304 = sizeof( V_303 ) ;
F_181 ( V_290 ) ;
F_199 ( V_320 -> V_362 ) ;
continue;
}
if ( V_14 )
V_153 = F_195 ( V_320 , V_19 , V_14 , V_290 ) ;
else
V_153 = F_193 ( V_320 , V_19 , V_290 ) ;
if ( V_153 == V_363 )
break;
if ( V_153 == V_354 )
F_199 ( V_320 -> V_362 ) ;
}
F_198 ( V_320 -> V_362 ) ;
F_98 ( V_9 ) ;
F_199 ( V_320 -> V_362 ) ;
}
static void
F_200 ( struct V_334 * V_320 )
{
struct V_18 * V_19 = V_320 -> V_364 ;
F_196 ( V_320 , V_19 , NULL , & V_19 -> V_172 ) ;
}
static void
F_201 ( struct V_334 * V_320 )
{
struct V_13 * V_14 = V_320 -> V_364 ;
struct V_18 * V_19 = F_42 ( V_14 ) ;
F_196 ( V_320 , V_19 , V_14 , & V_14 -> V_9 ) ;
}
static int
F_14 ( struct V_18 * V_19 , struct V_20 * V_21 )
{
struct V_8 * V_9 = & V_19 -> V_172 ;
struct V_113 * V_3 = F_43 ( V_19 -> V_114 ) ;
struct V_334 * V_320 ;
int V_77 ;
char V_365 [ 20 ] ;
V_21 -> V_64 = NULL ;
if ( ! V_3 -> V_121 -> V_353 )
return - V_366 ;
snprintf ( V_365 , sizeof( V_365 ) ,
L_48 , V_19 -> V_57 ) ;
V_320 = F_202 ( V_19 , F_200 ) ;
if ( ! V_320 ) {
F_29 ( V_236 L_49
L_50 ,
V_19 -> V_57 ) ;
return - V_59 ;
}
V_320 -> V_364 = V_19 ;
F_203 ( V_367 , V_320 ) ;
F_204 ( V_320 , F_184 ) ;
F_205 ( V_320 , F_186 ) ;
F_206 ( V_320 , V_368 ) ;
V_77 = F_207 ( V_320 , V_9 , V_365 , NULL ) ;
if ( V_77 ) {
F_29 ( V_236 L_49
L_51 ,
V_19 -> V_57 ) ;
F_208 ( V_320 ) ;
return V_77 ;
}
V_21 -> V_64 = V_320 ;
return 0 ;
}
static int
F_165 ( struct V_18 * V_19 , struct V_13 * V_14 )
{
struct V_8 * V_9 = & V_14 -> V_9 ;
struct V_113 * V_3 = F_43 ( V_19 -> V_114 ) ;
struct V_334 * V_320 ;
int V_77 ;
V_14 -> V_64 = NULL ;
if ( ! V_3 -> V_121 -> V_353 )
return - V_366 ;
V_320 = F_202 ( V_19 , F_201 ) ;
if ( ! V_320 ) {
F_29 ( V_236 L_52
L_50 ,
V_9 -> V_286 . V_76 ) ;
return - V_59 ;
}
V_320 -> V_364 = V_14 ;
F_203 ( V_367 , V_320 ) ;
F_204 ( V_320 , F_184 ) ;
F_205 ( V_320 , F_186 ) ;
F_206 ( V_320 , V_369 ) ;
V_77 = F_207 ( V_320 , V_9 , NULL , NULL ) ;
if ( V_77 ) {
F_29 ( V_236 L_52
L_51 ,
V_9 -> V_286 . V_76 ) ;
F_208 ( V_320 ) ;
return V_77 ;
}
V_14 -> V_64 = V_320 ;
return 0 ;
}
static void
F_16 ( struct V_334 * V_320 )
{
if ( V_320 ) {
F_209 ( V_320 ) ;
F_208 ( V_320 ) ;
}
}
