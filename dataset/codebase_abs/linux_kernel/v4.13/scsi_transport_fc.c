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
if ( * V_110 && ( * V_110 != '\n' ) )
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
if ( V_135 -> V_136 & ( V_138 | V_139 | V_140 ) ) {
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
static int F_104 ( const struct V_8 * V_9 )
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
enum V_189
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
F_108 ( & V_14 -> V_9 , V_176 , V_194 , V_195 ,
V_198 ) ;
return;
}
}
F_54 ( V_19 -> V_137 , V_136 ) ;
}
static int
F_109 ( struct V_18 * V_19 , T_8 V_176 , T_8 V_194 , T_3 V_195 )
{
T_8 V_199 , V_200 ;
T_8 V_201 , V_202 ;
if ( ( ( V_176 != V_203 ) && ( V_176 > V_19 -> V_204 ) ) ||
( ( V_194 != V_203 ) && ( V_194 >= V_19 -> V_205 ) ) ||
( ( V_195 != V_203 ) && ( V_195 > V_19 -> V_206 ) ) )
return - V_111 ;
if ( V_176 == V_203 ) {
V_199 = 0 ;
V_200 = V_19 -> V_204 + 1 ;
} else {
V_199 = V_176 ;
V_200 = V_176 + 1 ;
}
if ( V_194 == V_203 ) {
V_201 = 0 ;
V_202 = V_19 -> V_205 ;
} else {
V_201 = V_194 ;
V_202 = V_194 + 1 ;
}
for ( ; V_199 < V_200 ; V_199 ++ )
for ( ; V_201 < V_202 ; V_201 ++ )
F_107 ( V_19 , V_199 , V_201 , V_195 ) ;
return 0 ;
}
struct V_207 *
F_110 ( struct V_208 * V_209 )
{
int V_123 ;
struct V_113 * V_3 = F_111 ( sizeof( struct V_113 ) ,
V_81 ) ;
if ( F_112 ( ! V_3 ) )
return NULL ;
V_3 -> V_183 . V_185 . V_181 . V_210 = & V_3 -> V_211 [ 0 ] ;
V_3 -> V_183 . V_185 . V_181 . V_182 = & V_105 . V_182 ;
V_3 -> V_183 . V_185 . V_181 . V_175 = F_94 ;
V_3 -> V_183 . V_212 = sizeof( struct V_213 ) ;
F_113 ( & V_3 -> V_183 . V_185 ) ;
V_3 -> V_183 . V_180 . V_181 . V_210 = & V_3 -> V_180 [ 0 ] ;
V_3 -> V_183 . V_180 . V_181 . V_182 = & V_100 . V_182 ;
V_3 -> V_183 . V_180 . V_181 . V_175 = F_92 ;
V_3 -> V_183 . V_214 = sizeof( struct V_20 ) ;
if ( V_209 -> V_158 )
V_3 -> V_183 . V_180 . V_215 = & V_216 ;
F_113 ( & V_3 -> V_183 . V_180 ) ;
V_3 -> V_187 . V_181 . V_210 = & V_3 -> V_217 [ 0 ] ;
V_3 -> V_187 . V_181 . V_182 = & V_103 . V_182 ;
V_3 -> V_187 . V_181 . V_175 = F_101 ;
F_113 ( & V_3 -> V_187 ) ;
V_3 -> V_188 . V_181 . V_210 = & V_3 -> V_218 [ 0 ] ;
V_3 -> V_188 . V_181 . V_182 = & V_101 . V_182 ;
V_3 -> V_188 . V_181 . V_175 = F_105 ;
F_113 ( & V_3 -> V_188 ) ;
V_3 -> V_121 = V_209 ;
V_3 -> V_183 . V_219 = 1 ;
V_3 -> V_183 . V_220 = F_109 ;
V_123 = 0 ;
F_114 ( V_15 ) ;
F_114 ( V_16 ) ;
F_114 ( V_17 ) ;
F_115 ( V_123 > V_221 ) ;
V_3 -> V_211 [ V_123 ] = NULL ;
V_123 = 0 ;
F_116 ( V_15 ) ;
F_116 ( V_16 ) ;
F_116 ( V_22 ) ;
F_116 ( V_23 ) ;
F_116 ( V_25 ) ;
F_116 ( V_26 ) ;
F_116 ( V_28 ) ;
if ( V_209 -> V_222 ) {
F_117 ( V_29 ) ;
F_117 ( V_55 ) ;
}
F_116 ( V_30 ) ;
F_116 ( V_31 ) ;
F_116 ( V_32 ) ;
F_116 ( V_33 ) ;
F_116 ( V_34 ) ;
F_116 ( V_35 ) ;
F_116 ( V_36 ) ;
F_116 ( V_37 ) ;
F_116 ( V_17 ) ;
F_116 ( V_38 ) ;
F_116 ( V_40 ) ;
F_116 ( V_42 ) ;
F_116 ( V_43 ) ;
F_116 ( V_44 ) ;
F_116 ( V_45 ) ;
F_118 ( V_46 ) ;
F_119 ( V_60 ) ;
F_119 ( V_47 ) ;
if ( V_209 -> V_154 )
F_119 ( V_223 ) ;
if ( V_209 -> V_222 )
F_119 ( V_222 ) ;
if ( V_209 -> V_224 )
F_119 ( V_224 ) ;
F_115 ( V_123 > V_225 ) ;
V_3 -> V_180 [ V_123 ] = NULL ;
V_123 = 0 ;
F_120 ( V_28 ) ;
F_120 ( V_23 ) ;
F_121 ( V_60 ) ;
F_122 ( V_15 ) ;
F_122 ( V_16 ) ;
F_122 ( V_17 ) ;
F_122 ( V_132 ) ;
F_122 ( V_40 ) ;
F_122 ( V_196 ) ;
F_123 ( V_119 ) ;
F_115 ( V_123 > V_226 ) ;
V_3 -> V_217 [ V_123 ] = NULL ;
V_123 = 0 ;
F_124 ( V_143 ) ;
F_124 ( V_227 ) ;
F_124 ( V_15 ) ;
F_124 ( V_16 ) ;
F_124 ( V_132 ) ;
F_124 ( V_169 ) ;
F_125 ( V_45 ) ;
F_126 ( V_224 ) ;
F_126 ( V_146 ) ;
F_115 ( V_123 > V_228 ) ;
V_3 -> V_218 [ V_123 ] = NULL ;
return & V_3 -> V_183 ;
}
void F_127 ( struct V_207 * V_183 )
{
struct V_113 * V_3 = F_43 ( V_183 ) ;
F_128 ( & V_3 -> V_183 . V_185 ) ;
F_128 ( & V_3 -> V_183 . V_180 ) ;
F_128 ( & V_3 -> V_187 ) ;
F_128 ( & V_3 -> V_188 ) ;
F_99 ( V_3 ) ;
}
static int
F_55 ( struct V_18 * V_19 , struct V_229 * V_230 )
{
if ( F_112 ( ! F_129 ( V_19 ) ) ) {
F_29 ( V_231
L_22
L_23 , V_19 -> V_232 -> V_76 ) ;
F_130 () ;
return - V_111 ;
}
return F_131 ( F_129 ( V_19 ) , V_230 ) ;
}
static void
F_132 ( struct V_18 * V_19 )
{
if ( ! F_129 ( V_19 ) ) {
F_29 ( V_231
L_24
L_23 , V_19 -> V_232 -> V_76 ) ;
F_130 () ;
return;
}
F_133 ( F_129 ( V_19 ) ) ;
}
static int
F_134 ( struct V_18 * V_19 , struct V_233 * V_230 ,
unsigned long V_234 )
{
if ( F_112 ( ! F_135 ( V_19 ) ) ) {
F_29 ( V_231
L_22
L_23 , V_19 -> V_232 -> V_76 ) ;
F_130 () ;
return - V_111 ;
}
return F_136 ( F_135 ( V_19 ) , V_230 , V_234 ) ;
}
static void
F_137 ( struct V_18 * V_19 )
{
if ( ! F_135 ( V_19 ) ) {
F_29 ( V_231
L_24
L_23 , V_19 -> V_232 -> V_76 ) ;
F_130 () ;
return;
}
F_133 ( F_135 ( V_19 ) ) ;
}
void
F_138 ( struct V_18 * V_19 )
{
struct V_134 * V_135 = NULL , * V_235 = NULL ;
struct V_13 * V_14 = NULL , * V_236 = NULL ;
struct V_237 * V_58 ;
struct V_20 * V_21 = F_10 ( V_19 ) ;
unsigned long V_136 ;
F_53 ( V_19 -> V_137 , V_136 ) ;
F_139 (vport, next_vport, &fc_host->vports, peers) {
V_135 -> V_136 |= V_140 ;
F_55 ( V_19 , & V_135 -> V_141 ) ;
}
F_139 (rport, next_rport,
&fc_host->rports, peers) {
F_77 ( & V_14 -> V_151 ) ;
V_14 -> V_40 = V_116 ;
F_55 ( V_19 , & V_14 -> V_152 ) ;
}
F_139 (rport, next_rport,
&fc_host->rport_bindings, peers) {
F_77 ( & V_14 -> V_151 ) ;
V_14 -> V_40 = V_116 ;
F_55 ( V_19 , & V_14 -> V_152 ) ;
}
F_54 ( V_19 -> V_137 , V_136 ) ;
F_140 ( V_19 ) ;
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
static void F_141 ( struct V_13 * V_14 )
{
struct V_18 * V_19 = F_42 ( V_14 ) ;
struct V_113 * V_3 = F_43 ( V_19 -> V_114 ) ;
if ( V_3 -> V_121 -> V_238 )
V_3 -> V_121 -> V_238 ( V_14 ) ;
F_142 ( & V_14 -> V_9 , V_239 ) ;
}
static void
F_143 ( struct V_229 * V_230 )
{
struct V_13 * V_14 =
F_144 ( V_230 , struct V_13 , V_240 ) ;
F_141 ( V_14 ) ;
F_145 ( & V_14 -> V_9 ) ;
}
static void
F_146 ( struct V_229 * V_230 )
{
struct V_13 * V_14 =
F_144 ( V_230 , struct V_13 , V_152 ) ;
struct V_8 * V_9 = & V_14 -> V_9 ;
struct V_18 * V_19 = F_42 ( V_14 ) ;
struct V_113 * V_3 = F_43 ( V_19 -> V_114 ) ;
unsigned long V_136 ;
int V_241 = 0 ;
F_141 ( V_14 ) ;
if ( V_14 -> V_136 & V_242 )
F_140 ( V_19 ) ;
F_53 ( V_19 -> V_137 , V_136 ) ;
if ( V_14 -> V_136 & V_243 ) {
F_54 ( V_19 -> V_137 , V_136 ) ;
if ( ! F_147 ( & V_14 -> V_244 ) )
F_137 ( V_19 ) ;
if ( ! F_147 ( & V_14 -> V_245 ) )
F_137 ( V_19 ) ;
F_148 ( & V_14 -> V_246 ) ;
F_53 ( V_19 -> V_137 , V_136 ) ;
V_14 -> V_136 &= ~ V_243 ;
}
F_54 ( V_19 -> V_137 , V_136 ) ;
if ( V_14 -> V_196 != - 1 )
F_143 ( & V_14 -> V_240 ) ;
F_53 ( V_19 -> V_137 , V_136 ) ;
if ( ! ( V_14 -> V_136 & V_247 ) &&
( V_3 -> V_121 -> V_248 ) ) {
V_14 -> V_136 |= V_247 ;
V_241 = 1 ;
}
F_54 ( V_19 -> V_137 , V_136 ) ;
if ( V_241 )
V_3 -> V_121 -> V_248 ( V_14 ) ;
F_16 ( V_14 -> V_64 ) ;
F_149 ( V_9 ) ;
F_150 ( V_9 ) ;
F_151 ( V_9 ) ;
F_152 ( V_19 ) ;
F_98 ( V_9 ) ;
}
static struct V_13 *
F_153 ( struct V_18 * V_19 , int V_176 ,
struct V_249 * V_250 )
{
struct V_20 * V_21 = F_10 ( V_19 ) ;
struct V_113 * V_251 = F_43 ( V_19 -> V_114 ) ;
struct V_13 * V_14 ;
struct V_8 * V_9 ;
unsigned long V_136 ;
int error ;
T_7 V_252 ;
V_252 = ( sizeof( struct V_13 ) + V_251 -> V_121 -> V_253 ) ;
V_14 = F_111 ( V_252 , V_81 ) ;
if ( F_112 ( ! V_14 ) ) {
F_29 ( V_231 L_25 , V_94 ) ;
return NULL ;
}
V_14 -> V_28 = - 1 ;
V_14 -> V_23 = V_24 ;
V_14 -> V_60 = V_21 -> V_60 ;
memcpy ( & V_14 -> V_15 , & V_250 -> V_15 , sizeof( V_14 -> V_15 ) ) ;
memcpy ( & V_14 -> V_16 , & V_250 -> V_16 , sizeof( V_14 -> V_16 ) ) ;
V_14 -> V_17 = V_250 -> V_17 ;
V_14 -> V_132 = V_250 -> V_132 ;
V_14 -> V_40 = V_197 ;
if ( V_251 -> V_121 -> V_253 )
V_14 -> V_254 = & V_14 [ 1 ] ;
V_14 -> V_176 = V_176 ;
V_14 -> V_119 = - 1 ;
F_154 ( & V_14 -> V_245 , V_255 ) ;
F_154 ( & V_14 -> V_244 , V_256 ) ;
F_155 ( & V_14 -> V_246 , V_257 ) ;
F_155 ( & V_14 -> V_240 , F_143 ) ;
F_155 ( & V_14 -> V_152 , F_146 ) ;
F_53 ( V_19 -> V_137 , V_136 ) ;
V_14 -> V_258 = V_21 -> V_52 ++ ;
if ( ( V_14 -> V_132 & V_259 ) ||
( V_14 -> V_132 & V_260 ) )
V_14 -> V_196 = V_21 -> V_53 ++ ;
else
V_14 -> V_196 = - 1 ;
F_156 ( & V_14 -> V_151 , & V_21 -> V_49 ) ;
F_157 ( V_19 ) ;
F_54 ( V_19 -> V_137 , V_136 ) ;
V_9 = & V_14 -> V_9 ;
F_158 ( V_9 ) ;
V_9 -> V_184 = F_159 ( & V_19 -> V_172 ) ;
V_9 -> V_186 = F_96 ;
F_160 ( V_9 , L_26 ,
V_19 -> V_57 , V_176 , V_14 -> V_258 ) ;
F_161 ( V_9 ) ;
error = F_162 ( V_9 ) ;
if ( error ) {
F_29 ( V_231 L_27 ) ;
goto V_261;
}
F_163 ( V_9 ) ;
F_164 ( V_9 ) ;
F_165 ( V_19 , V_14 ) ;
if ( V_14 -> V_132 & V_259 ) {
V_14 -> V_136 |= V_242 ;
F_166 ( V_19 , & V_14 -> V_246 ) ;
}
return V_14 ;
V_261:
F_151 ( V_9 ) ;
F_53 ( V_19 -> V_137 , V_136 ) ;
F_77 ( & V_14 -> V_151 ) ;
F_152 ( V_19 ) ;
F_54 ( V_19 -> V_137 , V_136 ) ;
F_98 ( V_9 -> V_184 ) ;
F_99 ( V_14 ) ;
return NULL ;
}
struct V_13 *
F_167 ( struct V_18 * V_19 , int V_176 ,
struct V_249 * V_250 )
{
struct V_113 * V_251 = F_43 ( V_19 -> V_114 ) ;
struct V_20 * V_21 = F_10 ( V_19 ) ;
struct V_13 * V_14 ;
unsigned long V_136 ;
int V_175 = 0 ;
F_132 ( V_19 ) ;
F_53 ( V_19 -> V_137 , V_136 ) ;
F_81 (rport, &fc_host->rports, peers) {
if ( ( V_14 -> V_40 == V_115 ) &&
( V_14 -> V_176 == V_176 ) ) {
switch ( V_21 -> V_47 ) {
case V_48 :
case V_262 :
if ( V_14 -> V_16 == V_250 -> V_16 )
V_175 = 1 ;
break;
case V_263 :
if ( V_14 -> V_15 == V_250 -> V_15 )
V_175 = 1 ;
break;
case V_264 :
if ( V_14 -> V_17 == V_250 -> V_17 )
V_175 = 1 ;
break;
}
if ( V_175 ) {
memcpy ( & V_14 -> V_15 , & V_250 -> V_15 ,
sizeof( V_14 -> V_15 ) ) ;
memcpy ( & V_14 -> V_16 , & V_250 -> V_16 ,
sizeof( V_14 -> V_16 ) ) ;
V_14 -> V_17 = V_250 -> V_17 ;
V_14 -> V_40 = V_197 ;
V_14 -> V_132 = V_250 -> V_132 ;
F_54 ( V_19 -> V_137 , V_136 ) ;
if ( V_251 -> V_121 -> V_253 )
memset ( V_14 -> V_254 , 0 ,
V_251 -> V_121 -> V_253 ) ;
if ( ( V_14 -> V_196 != - 1 ) &&
( ! ( V_250 -> V_132 & V_259 ) ) )
return V_14 ;
if ( ! F_147 ( & V_14 -> V_244 ) )
F_137 ( V_19 ) ;
if ( ! F_147 ( & V_14 -> V_245 ) )
F_137 ( V_19 ) ;
F_53 ( V_19 -> V_137 , V_136 ) ;
V_14 -> V_136 &= ~ ( V_265 |
V_243 |
V_247 ) ;
F_54 ( V_19 -> V_137 , V_136 ) ;
if ( V_14 -> V_196 != - 1 ) {
F_142 ( & V_14 -> V_9 ,
V_266 ) ;
F_53 ( V_19 -> V_137 ,
V_136 ) ;
V_14 -> V_136 |= V_242 ;
F_166 ( V_19 ,
& V_14 -> V_246 ) ;
F_54 ( V_19 -> V_137 ,
V_136 ) ;
}
F_168 ( V_14 ) ;
return V_14 ;
}
}
}
if ( V_21 -> V_47 != V_262 ) {
F_81 (rport, &fc_host->rport_bindings,
peers) {
if ( V_14 -> V_176 != V_176 )
continue;
switch ( V_21 -> V_47 ) {
case V_48 :
if ( V_14 -> V_16 == V_250 -> V_16 )
V_175 = 1 ;
break;
case V_263 :
if ( V_14 -> V_15 == V_250 -> V_15 )
V_175 = 1 ;
break;
case V_264 :
if ( V_14 -> V_17 == V_250 -> V_17 )
V_175 = 1 ;
break;
case V_262 :
break;
}
if ( V_175 ) {
F_169 ( & V_14 -> V_151 , & V_21 -> V_49 ) ;
break;
}
}
if ( V_175 ) {
memcpy ( & V_14 -> V_15 , & V_250 -> V_15 ,
sizeof( V_14 -> V_15 ) ) ;
memcpy ( & V_14 -> V_16 , & V_250 -> V_16 ,
sizeof( V_14 -> V_16 ) ) ;
V_14 -> V_17 = V_250 -> V_17 ;
V_14 -> V_132 = V_250 -> V_132 ;
V_14 -> V_40 = V_197 ;
V_14 -> V_136 &= ~ V_265 ;
if ( V_251 -> V_121 -> V_253 )
memset ( V_14 -> V_254 , 0 ,
V_251 -> V_121 -> V_253 ) ;
F_54 ( V_19 -> V_137 , V_136 ) ;
if ( V_250 -> V_132 & V_259 ) {
F_142 ( & V_14 -> V_9 , V_266 ) ;
F_53 ( V_19 -> V_137 , V_136 ) ;
V_14 -> V_136 |= V_242 ;
F_166 ( V_19 , & V_14 -> V_246 ) ;
F_54 ( V_19 -> V_137 , V_136 ) ;
}
return V_14 ;
}
}
F_54 ( V_19 -> V_137 , V_136 ) ;
V_14 = F_153 ( V_19 , V_176 , V_250 ) ;
return V_14 ;
}
void
F_170 ( struct V_13 * V_14 )
{
struct V_18 * V_19 = F_42 ( V_14 ) ;
unsigned long V_267 = V_14 -> V_60 ;
unsigned long V_136 ;
F_53 ( V_19 -> V_137 , V_136 ) ;
if ( V_14 -> V_40 != V_197 ) {
F_54 ( V_19 -> V_137 , V_136 ) ;
return;
}
V_14 -> V_40 = V_115 ;
V_14 -> V_136 |= V_243 ;
F_54 ( V_19 -> V_137 , V_136 ) ;
F_171 ( & V_14 -> V_9 ) ;
if ( ( V_14 -> V_119 != - 1 ) &&
( V_14 -> V_119 < V_267 ) )
F_134 ( V_19 , & V_14 -> V_244 ,
V_14 -> V_119 * V_268 ) ;
F_134 ( V_19 , & V_14 -> V_245 , V_267 * V_268 ) ;
}
void
F_172 ( struct V_13 * V_14 , T_2 V_132 )
{
struct V_18 * V_19 = F_42 ( V_14 ) ;
struct V_20 * V_21 = F_10 ( V_19 ) ;
unsigned long V_136 ;
int V_269 = 0 ;
F_53 ( V_19 -> V_137 , V_136 ) ;
if ( V_132 & V_259 ) {
if ( V_14 -> V_196 == - 1 ) {
V_14 -> V_196 = V_21 -> V_53 ++ ;
V_269 = 1 ;
} else if ( ! ( V_14 -> V_132 & V_259 ) )
V_269 = 1 ;
}
V_14 -> V_132 = V_132 ;
F_54 ( V_19 -> V_137 , V_136 ) ;
if ( V_269 ) {
if ( ! F_147 ( & V_14 -> V_244 ) )
F_137 ( V_19 ) ;
if ( ! F_147 ( & V_14 -> V_245 ) )
F_137 ( V_19 ) ;
F_53 ( V_19 -> V_137 , V_136 ) ;
V_14 -> V_136 &= ~ ( V_265 |
V_243 |
V_247 ) ;
F_54 ( V_19 -> V_137 , V_136 ) ;
F_132 ( V_19 ) ;
F_142 ( & V_14 -> V_9 , V_266 ) ;
F_53 ( V_19 -> V_137 , V_136 ) ;
V_14 -> V_136 |= V_242 ;
F_166 ( V_19 , & V_14 -> V_246 ) ;
F_54 ( V_19 -> V_137 , V_136 ) ;
}
}
static void
V_255 ( struct V_229 * V_230 )
{
struct V_13 * V_14 =
F_144 ( V_230 , struct V_13 , V_245 . V_230 ) ;
struct V_18 * V_19 = F_42 ( V_14 ) ;
struct V_113 * V_3 = F_43 ( V_19 -> V_114 ) ;
struct V_20 * V_21 = F_10 ( V_19 ) ;
unsigned long V_136 ;
int V_241 = 0 ;
F_53 ( V_19 -> V_137 , V_136 ) ;
V_14 -> V_136 &= ~ V_243 ;
if ( ( V_14 -> V_40 == V_197 ) &&
( V_14 -> V_196 != - 1 ) &&
! ( V_14 -> V_132 & V_259 ) ) {
F_173 ( V_231 , & V_14 -> V_9 ,
L_28
L_29 ) ;
F_54 ( V_19 -> V_137 , V_136 ) ;
F_142 ( & V_14 -> V_9 , V_239 ) ;
F_55 ( V_19 , & V_14 -> V_240 ) ;
return;
}
if ( V_14 -> V_40 != V_115 ) {
F_54 ( V_19 -> V_137 , V_136 ) ;
F_173 ( V_231 , & V_14 -> V_9 ,
L_30
L_31 ,
( V_14 -> V_196 != - 1 ) ? L_32 : L_33 ) ;
return;
}
if ( ( V_21 -> V_47 == V_262 ) ||
( V_14 -> V_196 == - 1 ) ) {
F_77 ( & V_14 -> V_151 ) ;
V_14 -> V_40 = V_116 ;
F_173 ( V_231 , & V_14 -> V_9 ,
L_34
L_35 ,
( V_14 -> V_196 != - 1 ) ? L_32 : L_33 ) ;
F_55 ( V_19 , & V_14 -> V_152 ) ;
F_54 ( V_19 -> V_137 , V_136 ) ;
return;
}
F_173 ( V_231 , & V_14 -> V_9 ,
L_36
L_37 ) ;
F_169 ( & V_14 -> V_151 , & V_21 -> V_50 ) ;
V_14 -> V_28 = - 1 ;
V_14 -> V_23 = V_24 ;
V_14 -> V_132 = V_133 ;
V_14 -> V_40 = V_117 ;
V_14 -> V_136 &= ~ V_265 ;
F_54 ( V_19 -> V_137 , V_136 ) ;
F_141 ( V_14 ) ;
F_53 ( V_19 -> V_137 , V_136 ) ;
if ( V_14 -> V_40 == V_117 ) {
switch ( V_21 -> V_47 ) {
case V_48 :
V_14 -> V_15 = - 1 ;
V_14 -> V_17 = - 1 ;
break;
case V_263 :
V_14 -> V_16 = - 1 ;
V_14 -> V_17 = - 1 ;
break;
case V_264 :
V_14 -> V_15 = - 1 ;
V_14 -> V_16 = - 1 ;
break;
case V_262 :
break;
}
V_14 -> V_136 |= V_247 ;
F_55 ( V_19 , & V_14 -> V_240 ) ;
V_241 = 1 ;
}
F_54 ( V_19 -> V_137 , V_136 ) ;
if ( V_241 && V_3 -> V_121 -> V_248 )
V_3 -> V_121 -> V_248 ( V_14 ) ;
}
static void
V_256 ( struct V_229 * V_230 )
{
struct V_13 * V_14 =
F_144 ( V_230 , struct V_13 , V_244 . V_230 ) ;
if ( V_14 -> V_40 != V_115 )
return;
V_14 -> V_136 |= V_265 ;
F_141 ( V_14 ) ;
}
static void
V_257 ( struct V_229 * V_230 )
{
struct V_13 * V_14 =
F_144 ( V_230 , struct V_13 , V_246 ) ;
struct V_18 * V_19 = F_42 ( V_14 ) ;
struct V_113 * V_3 = F_43 ( V_19 -> V_114 ) ;
unsigned long V_136 ;
if ( ( V_14 -> V_40 == V_197 ) &&
( V_14 -> V_132 & V_259 ) &&
! ( V_3 -> V_121 -> V_270 ) ) {
F_108 ( & V_14 -> V_9 , V_14 -> V_176 ,
V_14 -> V_196 , V_203 ,
V_271 ) ;
}
F_53 ( V_19 -> V_137 , V_136 ) ;
V_14 -> V_136 &= ~ V_242 ;
F_54 ( V_19 -> V_137 , V_136 ) ;
}
int F_174 ( struct V_190 * V_272 )
{
struct V_18 * V_19 = V_272 -> V_8 -> V_273 ;
struct V_13 * V_14 = F_4 ( V_11 ( V_272 -> V_8 ) ) ;
unsigned long V_136 ;
F_53 ( V_19 -> V_137 , V_136 ) ;
while ( V_14 -> V_40 == V_115 &&
! ( V_14 -> V_136 & V_265 ) ) {
F_54 ( V_19 -> V_137 , V_136 ) ;
F_175 ( 1000 ) ;
F_53 ( V_19 -> V_137 , V_136 ) ;
}
F_54 ( V_19 -> V_137 , V_136 ) ;
if ( V_14 -> V_136 & V_265 )
return V_274 ;
return 0 ;
}
static int
F_89 ( struct V_18 * V_19 , int V_176 , struct V_8 * V_275 ,
struct V_165 * V_250 , struct V_134 * * V_276 )
{
struct V_20 * V_21 = F_10 ( V_19 ) ;
struct V_113 * V_251 = F_43 ( V_19 -> V_114 ) ;
struct V_134 * V_135 ;
struct V_8 * V_9 ;
unsigned long V_136 ;
T_7 V_252 ;
int error ;
* V_276 = NULL ;
if ( ! V_251 -> V_121 -> V_222 )
return - V_79 ;
V_252 = ( sizeof( struct V_134 ) + V_251 -> V_121 -> V_277 ) ;
V_135 = F_111 ( V_252 , V_81 ) ;
if ( F_112 ( ! V_135 ) ) {
F_29 ( V_231 L_25 , V_94 ) ;
return - V_59 ;
}
V_135 -> V_143 = V_278 ;
V_135 -> V_227 = V_278 ;
V_135 -> V_15 = V_250 -> V_15 ;
V_135 -> V_16 = V_250 -> V_16 ;
V_135 -> V_132 = V_250 -> V_132 ;
V_135 -> V_169 = V_250 -> V_169 ;
if ( V_251 -> V_121 -> V_277 )
V_135 -> V_254 = & V_135 [ 1 ] ;
V_135 -> V_19 = V_19 ;
V_135 -> V_176 = V_176 ;
V_135 -> V_136 = V_139 ;
F_155 ( & V_135 -> V_141 , V_279 ) ;
F_53 ( V_19 -> V_137 , V_136 ) ;
if ( V_21 -> V_55 >= V_21 -> V_29 ) {
F_54 ( V_19 -> V_137 , V_136 ) ;
F_99 ( V_135 ) ;
return - V_280 ;
}
V_21 -> V_55 ++ ;
V_135 -> V_258 = V_21 -> V_54 ++ ;
F_156 ( & V_135 -> V_151 , & V_21 -> V_51 ) ;
F_157 ( V_19 ) ;
F_54 ( V_19 -> V_137 , V_136 ) ;
V_9 = & V_135 -> V_9 ;
F_158 ( V_9 ) ;
V_9 -> V_184 = F_159 ( V_275 ) ;
V_9 -> V_186 = F_102 ;
F_160 ( V_9 , L_38 ,
V_19 -> V_57 , V_176 , V_135 -> V_258 ) ;
F_161 ( V_9 ) ;
error = F_162 ( V_9 ) ;
if ( error ) {
F_29 ( V_231 L_39 ) ;
goto V_281;
}
F_163 ( V_9 ) ;
F_164 ( V_9 ) ;
error = V_251 -> V_121 -> V_222 ( V_135 , V_250 -> V_171 ) ;
if ( error ) {
F_29 ( V_231 L_40 ) ;
goto V_282;
}
if ( V_275 != & V_19 -> V_172 ) {
error = F_176 ( & V_19 -> V_172 . V_283 ,
& V_9 -> V_283 , F_177 ( V_9 ) ) ;
if ( error )
F_29 ( V_231
L_41
L_42 ,
V_94 , F_177 ( V_9 ) , error ) ;
}
F_53 ( V_19 -> V_137 , V_136 ) ;
V_135 -> V_136 &= ~ V_139 ;
F_54 ( V_19 -> V_137 , V_136 ) ;
F_173 ( V_284 , V_275 ,
L_43 , F_177 ( V_9 ) ,
V_19 -> V_57 , V_176 ) ;
* V_276 = V_135 ;
return 0 ;
V_282:
F_149 ( V_9 ) ;
F_150 ( V_9 ) ;
V_281:
F_151 ( V_9 ) ;
F_53 ( V_19 -> V_137 , V_136 ) ;
F_77 ( & V_135 -> V_151 ) ;
F_152 ( V_19 ) ;
V_21 -> V_55 -- ;
F_54 ( V_19 -> V_137 , V_136 ) ;
F_98 ( V_9 -> V_184 ) ;
F_99 ( V_135 ) ;
return error ;
}
struct V_134 *
F_178 ( struct V_18 * V_19 , int V_176 ,
struct V_165 * V_250 )
{
int V_142 ;
struct V_134 * V_135 ;
V_142 = F_89 ( V_19 , V_176 , & V_19 -> V_172 ,
V_250 , & V_135 ) ;
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
if ( V_3 -> V_121 -> V_224 )
V_142 = V_3 -> V_121 -> V_224 ( V_135 ) ;
else
V_142 = - V_79 ;
F_53 ( V_19 -> V_137 , V_136 ) ;
V_135 -> V_136 &= ~ V_140 ;
if ( ! V_142 ) {
V_135 -> V_136 |= V_285 ;
F_77 ( & V_135 -> V_151 ) ;
V_21 -> V_55 -- ;
F_152 ( V_19 ) ;
}
F_54 ( V_19 -> V_137 , V_136 ) ;
if ( V_142 )
return V_142 ;
if ( V_9 -> V_184 != & V_19 -> V_172 )
F_179 ( & V_19 -> V_172 . V_283 , F_177 ( V_9 ) ) ;
F_149 ( V_9 ) ;
F_150 ( V_9 ) ;
F_151 ( V_9 ) ;
F_98 ( V_9 ) ;
return 0 ;
}
static void
V_279 ( struct V_229 * V_230 )
{
struct V_134 * V_135 =
F_144 ( V_230 , struct V_134 , V_141 ) ;
int V_142 ;
V_142 = F_91 ( V_135 ) ;
if ( V_142 )
F_173 ( V_231 , V_135 -> V_9 . V_184 ,
L_44
L_45 , V_94 ,
F_177 ( & V_135 -> V_9 ) , V_135 -> V_19 -> V_57 ,
V_135 -> V_176 , V_142 ) ;
}
static enum V_189
F_180 ( struct V_286 * V_287 )
{
struct V_288 * V_289 = ( void * ) V_287 -> V_290 ;
struct V_18 * V_19 = F_181 ( V_289 ) ;
struct V_13 * V_14 = F_182 ( V_289 ) ;
struct V_113 * V_3 = F_43 ( V_19 -> V_114 ) ;
int V_77 = 0 , V_291 = 0 ;
if ( V_14 && V_14 -> V_40 == V_115 )
return V_192 ;
V_291 = F_183 ( V_289 ) ;
if ( V_291 && V_3 -> V_121 -> V_292 ) {
V_77 = V_3 -> V_121 -> V_292 ( V_289 ) ;
if ( V_77 == - V_293 ) {
F_184 ( V_289 ) ;
return V_192 ;
} else if ( V_77 )
F_29 ( V_231 L_46
L_47 , V_77 ) ;
}
if ( ! V_291 )
return V_193 ;
else
return V_294 ;
}
static int F_185 ( struct V_18 * V_19 , struct V_288 * V_289 )
{
struct V_113 * V_3 = F_43 ( V_19 -> V_114 ) ;
struct V_295 * V_296 = V_289 -> V_286 ;
struct V_297 * V_298 = V_289 -> V_299 ;
int V_300 = sizeof( V_301 ) ;
int V_153 ;
if ( V_289 -> V_302 < V_300 ) {
V_153 = - V_303 ;
goto V_304;
}
switch ( V_296 -> V_305 ) {
case V_306 :
V_300 += sizeof( struct V_307 ) ;
break;
case V_308 :
V_300 += sizeof( struct V_309 ) ;
break;
case V_310 :
V_300 += sizeof( struct V_311 ) ;
if ( ( ! V_289 -> V_312 . V_313 ) ||
( ! V_289 -> V_314 . V_313 ) ) {
V_153 = - V_111 ;
goto V_304;
}
break;
case V_315 :
V_300 += sizeof( struct V_316 ) ;
if ( ( ! V_289 -> V_312 . V_313 ) ||
( ! V_289 -> V_314 . V_313 ) ) {
V_153 = - V_111 ;
goto V_304;
}
break;
case V_317 :
V_300 += sizeof( struct V_318 ) ;
if ( ( V_19 -> V_232 -> V_89 == 0L ) ||
( V_296 -> V_319 . V_320 . V_89 !=
V_19 -> V_232 -> V_89 ) ) {
V_153 = - V_321 ;
goto V_304;
}
break;
default:
V_153 = - V_322 ;
goto V_304;
}
V_153 = V_3 -> V_121 -> V_296 ( V_289 ) ;
if ( ! V_153 )
return 0 ;
V_304:
F_115 ( V_289 -> V_323 < sizeof( V_301 ) ) ;
V_298 -> V_324 = 0 ;
V_298 -> V_325 = V_153 ;
V_289 -> V_323 = sizeof( V_301 ) ;
F_186 ( V_289 , V_298 -> V_325 ,
V_298 -> V_324 ) ;
return 0 ;
}
static void
F_168 ( struct V_13 * V_14 )
{
struct V_326 * V_327 = V_14 -> V_64 ;
unsigned long V_136 ;
if ( ! V_327 )
return;
F_53 ( V_327 -> V_328 , V_136 ) ;
F_187 ( V_327 ) ;
F_54 ( V_327 -> V_328 , V_136 ) ;
}
static int F_188 ( struct V_18 * V_19 , struct V_288 * V_289 )
{
struct V_113 * V_3 = F_43 ( V_19 -> V_114 ) ;
struct V_295 * V_296 = V_289 -> V_286 ;
struct V_297 * V_298 = V_289 -> V_299 ;
int V_300 = sizeof( V_301 ) ;
int V_153 ;
if ( V_289 -> V_302 < V_300 ) {
V_153 = - V_303 ;
goto V_329;
}
switch ( V_296 -> V_305 ) {
case V_330 :
V_300 += sizeof( struct V_331 ) ;
goto V_332;
case V_333 :
V_300 += sizeof( struct V_334 ) ;
V_332:
if ( ( ! V_289 -> V_312 . V_313 ) ||
( ! V_289 -> V_314 . V_313 ) ) {
V_153 = - V_111 ;
goto V_329;
}
break;
default:
V_153 = - V_322 ;
goto V_329;
}
V_153 = V_3 -> V_121 -> V_296 ( V_289 ) ;
if ( ! V_153 )
return 0 ;
V_329:
F_115 ( V_289 -> V_323 < sizeof( V_301 ) ) ;
V_298 -> V_324 = 0 ;
V_298 -> V_325 = V_153 ;
V_289 -> V_323 = sizeof( V_301 ) ;
F_186 ( V_289 , V_298 -> V_325 ,
V_298 -> V_324 ) ;
return 0 ;
}
static int F_189 ( struct V_288 * V_289 )
{
struct V_18 * V_19 = F_181 ( V_289 ) ;
if ( F_100 ( V_289 -> V_9 ) )
return F_188 ( V_19 , V_289 ) ;
else
return F_185 ( V_19 , V_289 ) ;
}
static int
F_14 ( struct V_18 * V_19 , struct V_20 * V_21 )
{
struct V_8 * V_9 = & V_19 -> V_172 ;
struct V_113 * V_3 = F_43 ( V_19 -> V_114 ) ;
struct V_326 * V_327 ;
char V_335 [ 20 ] ;
V_21 -> V_64 = NULL ;
if ( ! V_3 -> V_121 -> V_296 )
return - V_336 ;
snprintf ( V_335 , sizeof( V_335 ) ,
L_48 , V_19 -> V_57 ) ;
V_327 = F_190 ( V_9 , V_335 , F_189 , V_3 -> V_121 -> V_337 ) ;
if ( F_191 ( V_327 ) ) {
F_192 ( V_9 ,
L_49 ,
V_19 -> V_57 ) ;
return F_193 ( V_327 ) ;
}
F_194 ( V_19 , V_327 ) ;
F_195 ( V_327 , F_180 ) ;
F_196 ( V_327 , V_338 ) ;
V_21 -> V_64 = V_327 ;
return 0 ;
}
static int F_197 ( struct V_326 * V_327 , struct V_286 * V_287 )
{
struct V_13 * V_14 = F_97 ( V_327 -> V_339 ) ;
if ( V_14 -> V_40 == V_115 &&
! ( V_14 -> V_136 & V_265 ) )
return V_340 ;
if ( V_14 -> V_40 != V_197 )
return V_341 ;
return V_342 ;
}
static int
F_165 ( struct V_18 * V_19 , struct V_13 * V_14 )
{
struct V_8 * V_9 = & V_14 -> V_9 ;
struct V_113 * V_3 = F_43 ( V_19 -> V_114 ) ;
struct V_326 * V_327 ;
V_14 -> V_64 = NULL ;
if ( ! V_3 -> V_121 -> V_296 )
return - V_336 ;
V_327 = F_190 ( V_9 , NULL , F_189 , V_3 -> V_121 -> V_337 ) ;
if ( F_191 ( V_327 ) ) {
F_192 ( V_9 , L_50 ) ;
return F_193 ( V_327 ) ;
}
F_194 ( V_19 , V_327 ) ;
F_198 ( V_327 , F_197 ) ;
F_195 ( V_327 , F_180 ) ;
F_196 ( V_327 , V_343 ) ;
V_14 -> V_64 = V_327 ;
return 0 ;
}
static void
F_16 ( struct V_326 * V_327 )
{
if ( V_327 ) {
F_199 ( V_327 ) ;
F_200 ( V_327 ) ;
}
}
