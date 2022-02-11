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
V_21 -> V_58 = F_12 ( V_21 -> V_56 , 0 , 0 ) ;
if ( ! V_21 -> V_58 )
return - V_59 ;
V_21 -> V_60 = V_61 ;
snprintf ( V_21 -> V_62 ,
sizeof( V_21 -> V_62 ) ,
L_4 , V_19 -> V_57 ) ;
V_21 -> V_63 =
F_12 ( V_21 -> V_62 , 0 , 0 ) ;
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
T_2 V_4 , V_77 ;
int V_78 ;
if ( ! V_79 ) {
V_78 = - V_80 ;
goto V_81;
}
V_4 = F_20 ( sizeof( * V_75 ) ) ;
V_77 = F_21 ( V_4 ) ;
V_71 = F_22 ( V_77 , V_82 ) ;
if ( ! V_71 ) {
V_78 = - V_83 ;
goto V_81;
}
V_73 = F_23 ( V_71 , 0 , 0 , V_84 ,
V_77 - sizeof( * V_73 ) , 0 ) ;
if ( ! V_73 ) {
V_78 = - V_83 ;
goto V_85;
}
V_75 = F_24 ( V_73 ) ;
F_25 ( & V_75 -> V_86 , V_87 ,
V_88 , V_4 ) ;
V_75 -> V_89 = F_26 () ;
V_75 -> V_90 = 0 ;
V_75 -> V_57 = V_19 -> V_57 ;
V_75 -> V_91 = sizeof( T_2 ) ;
V_75 -> V_92 = V_66 ;
V_75 -> V_68 = V_68 ;
V_75 -> V_69 = V_69 ;
F_27 ( V_79 , V_71 , 0 , V_93 ,
V_82 ) ;
return;
V_85:
F_28 ( V_71 ) ;
V_81:
V_76 = F_29 ( V_68 ) ;
F_30 ( V_94
L_5 ,
V_95 , V_19 -> V_57 ,
( V_76 ) ? V_76 : L_6 , V_69 , V_78 ) ;
return;
}
void
F_31 ( struct V_18 * V_19 , T_2 V_66 ,
T_2 V_96 , char * V_97 , T_3 V_90 )
{
struct V_70 * V_71 ;
struct V_72 * V_73 ;
struct V_74 * V_75 ;
T_2 V_4 , V_77 ;
int V_78 ;
if ( ! V_79 ) {
V_78 = - V_80 ;
goto V_98;
}
V_4 = F_20 ( sizeof( * V_75 ) + V_96 ) ;
V_77 = F_21 ( V_4 ) ;
V_71 = F_22 ( V_77 , V_82 ) ;
if ( ! V_71 ) {
V_78 = - V_83 ;
goto V_98;
}
V_73 = F_23 ( V_71 , 0 , 0 , V_84 ,
V_77 - sizeof( * V_73 ) , 0 ) ;
if ( ! V_73 ) {
V_78 = - V_83 ;
goto V_99;
}
V_75 = F_24 ( V_73 ) ;
F_25 ( & V_75 -> V_86 , V_87 ,
V_88 , V_4 ) ;
V_75 -> V_89 = F_26 () ;
V_75 -> V_90 = V_90 ;
V_75 -> V_57 = V_19 -> V_57 ;
V_75 -> V_91 = V_96 ;
V_75 -> V_92 = V_66 ;
V_75 -> V_68 = V_100 ;
memcpy ( & V_75 -> V_69 , V_97 , V_96 ) ;
F_27 ( V_79 , V_71 , 0 , V_93 ,
V_82 ) ;
return;
V_99:
F_28 ( V_71 ) ;
V_98:
F_30 ( V_94
L_7 ,
V_95 , V_19 -> V_57 , V_78 ) ;
return;
}
static T_4 int F_32 ( void )
{
int error ;
F_33 ( & V_65 , 0 ) ;
error = F_34 ( & V_101 ) ;
if ( error )
return error ;
error = F_34 ( & V_102 ) ;
if ( error )
goto V_103;
error = F_34 ( & V_104 ) ;
if ( error )
goto V_105;
error = F_34 ( & V_106 ) ;
if ( error )
goto V_107;
return 0 ;
V_107:
F_35 ( & V_104 ) ;
V_105:
F_35 ( & V_102 ) ;
V_103:
F_35 ( & V_101 ) ;
return error ;
}
static void T_5 F_36 ( void )
{
F_35 ( & V_106 ) ;
F_35 ( & V_104 ) ;
F_35 ( & V_101 ) ;
F_35 ( & V_102 ) ;
}
static T_6
F_37 ( struct V_8 * V_9 ,
struct V_108 * V_109 , char * V_1 )
{
struct V_13 * V_14 = F_38 ( V_9 ) ;
if ( V_14 -> V_23 == V_24 )
return snprintf ( V_1 , 20 , L_8 ) ;
return F_39 ( V_14 -> V_23 , V_1 ) ;
}
static int F_40 ( const char * V_1 , unsigned long * V_110 )
{
char * V_111 ;
* V_110 = F_41 ( V_1 , & V_111 , 0 ) ;
if ( ( * V_111 && ( * V_111 != '\n' ) ) || ( * V_110 < 0 ) )
return - V_112 ;
if ( * V_110 > V_113 )
return - V_112 ;
return 0 ;
}
static int F_42 ( struct V_13 * V_14 ,
unsigned long V_110 )
{
struct V_18 * V_19 = F_43 ( V_14 ) ;
struct V_114 * V_3 = F_44 ( V_19 -> V_115 ) ;
if ( ( V_14 -> V_40 == V_116 ) ||
( V_14 -> V_40 == V_117 ) ||
( V_14 -> V_40 == V_118 ) )
return - V_119 ;
if ( V_110 > V_113 )
return - V_112 ;
if ( V_14 -> V_120 == - 1 &&
V_110 > V_121 )
return - V_112 ;
V_3 -> V_122 -> V_123 ( V_14 , V_110 ) ;
return 0 ;
}
static T_6
F_45 ( struct V_8 * V_9 , struct V_108 * V_109 ,
const char * V_1 , T_7 V_124 )
{
struct V_13 * V_14 = F_38 ( V_9 ) ;
unsigned long V_110 ;
int V_125 ;
V_125 = F_40 ( V_1 , & V_110 ) ;
if ( V_125 )
return V_125 ;
V_125 = F_42 ( V_14 , V_110 ) ;
if ( V_125 )
return V_125 ;
return V_124 ;
}
static T_6
F_46 ( struct V_8 * V_9 , struct V_108 * V_109 ,
char * V_1 )
{
struct V_13 * V_14 = F_38 ( V_9 ) ;
if ( ( V_14 -> V_17 != - 1 ) &&
( V_14 -> V_17 & V_126 ) ==
V_126 ) {
switch ( V_14 -> V_17 & V_127 ) {
case V_128 :
return snprintf ( V_1 , 30 , L_9 ) ;
case V_129 :
return snprintf ( V_1 , 30 , L_10 ) ;
case V_130 :
return snprintf ( V_1 , 30 , L_11 ) ;
case V_131 :
return snprintf ( V_1 , 30 , L_12 ) ;
case V_132 :
return snprintf ( V_1 , 30 , L_13 ) ;
default:
return snprintf ( V_1 , 30 , L_14 ) ;
}
} else {
if ( V_14 -> V_133 == V_134 )
return snprintf ( V_1 , 20 , L_15 ) ;
return F_47 ( V_14 -> V_133 , V_1 ) ;
}
}
static T_6
F_48 ( struct V_8 * V_9 ,
struct V_108 * V_109 , char * V_1 )
{
struct V_13 * V_14 = F_38 ( V_9 ) ;
if ( V_14 -> V_120 == - 1 )
return snprintf ( V_1 , 5 , L_16 ) ;
return snprintf ( V_1 , 20 , L_17 , V_14 -> V_120 ) ;
}
static T_6
F_49 ( struct V_8 * V_9 ,
struct V_108 * V_109 , const char * V_1 ,
T_7 V_124 )
{
int V_110 ;
char * V_111 ;
struct V_13 * V_14 = F_38 ( V_9 ) ;
if ( ( V_14 -> V_40 == V_116 ) ||
( V_14 -> V_40 == V_117 ) ||
( V_14 -> V_40 == V_118 ) )
return - V_119 ;
if ( strncmp ( V_1 , L_18 , 3 ) == 0 )
V_14 -> V_120 = - 1 ;
else {
V_110 = F_41 ( V_1 , & V_111 , 0 ) ;
if ( ( * V_111 && ( * V_111 != '\n' ) ) || ( V_110 < 0 ) )
return - V_112 ;
if ( ( V_110 >= V_14 -> V_60 ) ||
( V_110 > V_121 ) )
return - V_112 ;
V_14 -> V_120 = V_110 ;
}
return V_124 ;
}
static T_6
F_50 ( struct V_8 * V_9 , struct V_108 * V_109 ,
char * V_1 )
{
struct V_135 * V_136 = F_51 ( V_9 ) ;
if ( V_136 -> V_133 == V_134 )
return snprintf ( V_1 , 20 , L_15 ) ;
return F_47 ( V_136 -> V_133 , V_1 ) ;
}
static T_6
F_52 ( struct V_8 * V_9 , struct V_108 * V_109 ,
const char * V_1 , T_7 V_124 )
{
struct V_135 * V_136 = F_51 ( V_9 ) ;
struct V_18 * V_19 = F_53 ( V_136 ) ;
unsigned long V_137 ;
F_54 ( V_19 -> V_138 , V_137 ) ;
if ( V_136 -> V_137 & ( V_139 | V_140 ) ) {
F_55 ( V_19 -> V_138 , V_137 ) ;
return - V_119 ;
}
V_136 -> V_137 |= V_141 ;
F_55 ( V_19 -> V_138 , V_137 ) ;
F_56 ( V_19 , & V_136 -> V_142 ) ;
return V_124 ;
}
static T_6
F_57 ( struct V_8 * V_9 , struct V_108 * V_109 ,
const char * V_1 ,
T_7 V_124 )
{
struct V_135 * V_136 = F_51 ( V_9 ) ;
struct V_18 * V_19 = F_53 ( V_136 ) ;
struct V_114 * V_3 = F_44 ( V_19 -> V_115 ) ;
int V_143 ;
if ( V_136 -> V_137 & ( V_139 | V_140 ) )
return - V_119 ;
if ( * V_1 == '0' ) {
if ( V_136 -> V_144 != V_145 )
return - V_146 ;
} else if ( * V_1 == '1' ) {
if ( V_136 -> V_144 == V_145 )
return - V_146 ;
} else
return - V_112 ;
V_143 = V_3 -> V_122 -> V_147 ( V_136 , ( ( * V_1 == '0' ) ? false : true ) ) ;
return V_143 ? V_143 : V_124 ;
}
static T_6
F_58 ( struct V_8 * V_9 ,
struct V_108 * V_109 , char * V_1 )
{
struct V_18 * V_19 = F_59 ( V_9 ) ;
if ( F_60 ( V_19 ) == V_24 )
return snprintf ( V_1 , 20 , L_8 ) ;
return F_39 ( F_60 ( V_19 ) , V_1 ) ;
}
static T_6
F_61 ( struct V_8 * V_9 ,
struct V_108 * V_109 , char * V_1 )
{
struct V_18 * V_19 = F_59 ( V_9 ) ;
return ( T_6 ) F_1 ( V_1 , F_62 ( V_19 ) ) ;
}
static T_6
F_63 ( struct V_8 * V_9 ,
struct V_108 * V_109 , char * V_1 )
{
struct V_18 * V_19 = F_59 ( V_9 ) ;
if ( F_64 ( V_19 ) == V_27 )
return snprintf ( V_1 , 20 , L_15 ) ;
return F_65 ( F_64 ( V_19 ) , V_1 ) ;
}
static T_6
F_66 ( struct V_8 * V_9 ,
struct V_108 * V_109 , char * V_1 )
{
struct V_18 * V_19 = F_59 ( V_9 ) ;
struct V_114 * V_3 = F_44 ( V_19 -> V_115 ) ;
if ( V_3 -> V_122 -> V_148 )
V_3 -> V_122 -> V_148 ( V_19 ) ;
return ( T_6 ) F_1 ( V_1 , F_67 ( V_19 ) ) ;
}
static T_6
F_68 ( struct V_8 * V_9 ,
struct V_108 * V_109 , char * V_1 )
{
struct V_18 * V_19 = F_59 ( V_9 ) ;
struct V_114 * V_3 = F_44 ( V_19 -> V_115 ) ;
if ( V_3 -> V_122 -> V_149 )
V_3 -> V_122 -> V_149 ( V_19 ) ;
if ( F_69 ( V_19 ) == V_27 )
return snprintf ( V_1 , 20 , L_15 ) ;
return F_65 ( F_69 ( V_19 ) , V_1 ) ;
}
static T_6
F_70 ( struct V_8 * V_9 ,
struct V_108 * V_109 , char * V_1 )
{
struct V_18 * V_19 = F_59 ( V_9 ) ;
const char * V_76 ;
V_76 = F_71 ( F_72 ( V_19 ) ) ;
if ( ! V_76 )
return - V_112 ;
return snprintf ( V_1 , V_150 , L_19 , V_76 ) ;
}
static T_6
F_73 ( struct V_8 * V_9 ,
struct V_108 * V_109 , const char * V_1 , T_7 V_124 )
{
struct V_18 * V_19 = F_59 ( V_9 ) ;
struct V_13 * V_14 ;
enum V_151 V_110 ;
unsigned long V_137 ;
if ( F_74 ( V_1 , & V_110 ) )
return - V_112 ;
if ( V_110 != F_72 ( V_19 ) ) {
F_54 ( V_19 -> V_138 , V_137 ) ;
while ( ! F_75 ( & F_76 ( V_19 ) ) ) {
F_77 ( V_14 ,
& F_76 ( V_19 ) , V_152 ) ;
F_78 ( & V_14 -> V_152 ) ;
V_14 -> V_40 = V_117 ;
F_56 ( V_19 , & V_14 -> V_153 ) ;
}
F_55 ( V_19 -> V_138 , V_137 ) ;
}
F_72 ( V_19 ) = V_110 ;
return V_124 ;
}
static T_6
F_79 ( struct V_8 * V_9 ,
struct V_108 * V_109 , const char * V_1 , T_7 V_124 )
{
struct V_18 * V_19 = F_59 ( V_9 ) ;
struct V_114 * V_3 = F_44 ( V_19 -> V_115 ) ;
int V_154 ;
if ( V_3 -> V_122 -> V_155 ) {
V_154 = V_3 -> V_122 -> V_155 ( V_19 ) ;
return V_154 ? V_154 : V_124 ;
}
return - V_80 ;
}
static T_6
F_80 ( struct V_8 * V_9 ,
struct V_108 * V_109 ,
const char * V_1 , T_7 V_124 )
{
struct V_18 * V_19 = F_59 ( V_9 ) ;
struct V_20 * V_21 = F_10 ( V_19 ) ;
struct V_13 * V_14 ;
unsigned long V_110 , V_137 ;
int V_125 ;
V_125 = F_40 ( V_1 , & V_110 ) ;
if ( V_125 )
return V_125 ;
F_81 ( V_19 ) = V_110 ;
F_54 ( V_19 -> V_138 , V_137 ) ;
F_82 (rport, &fc_host->rports, peers)
F_42 ( V_14 , V_110 ) ;
F_55 ( V_19 -> V_138 , V_137 ) ;
return V_124 ;
}
static T_6
F_83 ( const struct V_8 * V_9 , char * V_1 , unsigned long V_156 )
{
struct V_18 * V_19 = F_59 ( V_9 ) ;
struct V_114 * V_3 = F_44 ( V_19 -> V_115 ) ;
struct V_157 * V_158 ;
T_6 V_154 = - V_80 ;
if ( V_156 > sizeof( struct V_157 ) ||
V_156 % sizeof( T_3 ) != 0 )
F_84 ( 1 ) ;
if ( V_3 -> V_122 -> V_159 ) {
V_158 = ( V_3 -> V_122 -> V_159 ) ( V_19 ) ;
if ( V_158 )
V_154 = snprintf ( V_1 , 20 , L_20 ,
( unsigned long long ) * ( T_3 * ) ( ( ( T_1 * ) V_158 ) + V_156 ) ) ;
}
return V_154 ;
}
static T_6
F_85 ( struct V_8 * V_9 , struct V_108 * V_109 ,
const char * V_1 , T_7 V_124 )
{
struct V_18 * V_19 = F_59 ( V_9 ) ;
struct V_114 * V_3 = F_44 ( V_19 -> V_115 ) ;
if ( V_3 -> V_122 -> V_160 ) {
V_3 -> V_122 -> V_160 ( V_19 ) ;
return V_124 ;
}
return - V_80 ;
}
static int
F_86 ( const char * V_161 , T_3 * V_162 )
{
unsigned int V_3 , V_163 ;
T_1 V_164 [ 8 ] ;
memset ( V_164 , 0 , sizeof( V_164 ) ) ;
for ( V_3 = 0 , V_163 = 0 ; V_3 < 16 ; V_3 ++ ) {
int V_165 ;
V_165 = F_87 ( * V_161 ++ ) ;
if ( V_165 >= 0 )
V_163 = ( V_163 << 4 ) | V_165 ;
else
return - V_112 ;
if ( V_3 % 2 ) {
V_164 [ V_3 / 2 ] = V_163 & 0xff ;
V_163 = 0 ;
}
}
* V_162 = F_88 ( V_164 ) ;
return 0 ;
}
static T_6
F_89 ( struct V_8 * V_9 , struct V_108 * V_109 ,
const char * V_1 , T_7 V_124 )
{
struct V_18 * V_19 = F_59 ( V_9 ) ;
struct V_166 V_167 ;
struct V_135 * V_136 ;
unsigned int V_168 = V_124 ;
int V_143 ;
memset ( & V_167 , 0 , sizeof( V_167 ) ) ;
if ( V_1 [ V_168 - 1 ] == '\n' )
V_168 -- ;
if ( ( V_168 != ( 16 + 1 + 16 ) ) || ( V_1 [ 16 ] != ':' ) )
return - V_112 ;
V_143 = F_86 ( & V_1 [ 0 ] , & V_167 . V_16 ) ;
if ( V_143 )
return V_143 ;
V_143 = F_86 ( & V_1 [ 17 ] , & V_167 . V_15 ) ;
if ( V_143 )
return V_143 ;
V_167 . V_133 = V_169 ;
V_167 . V_170 = V_171 ;
V_167 . V_172 = false ;
V_143 = F_90 ( V_19 , 0 , & V_19 -> V_173 , & V_167 , & V_136 ) ;
return V_143 ? V_143 : V_124 ;
}
static T_6
F_91 ( struct V_8 * V_9 , struct V_108 * V_109 ,
const char * V_1 , T_7 V_124 )
{
struct V_18 * V_19 = F_59 ( V_9 ) ;
struct V_20 * V_21 = F_10 ( V_19 ) ;
struct V_135 * V_136 ;
T_3 V_174 , V_175 ;
unsigned long V_137 ;
unsigned int V_168 = V_124 ;
int V_143 , V_176 ;
if ( V_1 [ V_168 - 1 ] == '\n' )
V_168 -- ;
if ( ( V_168 != ( 16 + 1 + 16 ) ) || ( V_1 [ 16 ] != ':' ) )
return - V_112 ;
V_143 = F_86 ( & V_1 [ 0 ] , & V_174 ) ;
if ( V_143 )
return V_143 ;
V_143 = F_86 ( & V_1 [ 17 ] , & V_175 ) ;
if ( V_143 )
return V_143 ;
F_54 ( V_19 -> V_138 , V_137 ) ;
V_176 = 0 ;
F_82 (vport, &fc_host->vports, peers) {
if ( ( V_136 -> V_177 == 0 ) &&
( V_136 -> V_16 == V_174 ) && ( V_136 -> V_15 == V_175 ) ) {
if ( V_136 -> V_137 & ( V_139 | V_140 ) )
break;
V_136 -> V_137 |= V_141 ;
V_176 = 1 ;
break;
}
}
F_55 ( V_19 -> V_138 , V_137 ) ;
if ( ! V_176 )
return - V_178 ;
V_143 = F_92 ( V_136 ) ;
return V_143 ? V_143 : V_124 ;
}
static int F_93 ( struct V_179 * V_180 ,
struct V_8 * V_9 )
{
struct V_18 * V_19 ;
struct V_114 * V_3 ;
if ( ! F_94 ( V_9 ) )
return 0 ;
V_19 = F_9 ( V_9 ) ;
if ( ! V_19 -> V_115 || V_19 -> V_115 -> V_181 . V_182 . V_183
!= & V_101 . V_183 )
return 0 ;
V_3 = F_44 ( V_19 -> V_115 ) ;
return & V_3 -> V_184 . V_181 . V_182 == V_180 ;
}
static int F_95 ( struct V_179 * V_180 ,
struct V_8 * V_9 )
{
struct V_18 * V_19 ;
struct V_114 * V_3 ;
if ( ! F_96 ( V_9 ) )
return 0 ;
V_19 = F_9 ( V_9 -> V_185 ) ;
if ( ! V_19 -> V_115 || V_19 -> V_115 -> V_181 . V_182 . V_183
!= & V_101 . V_183 )
return 0 ;
V_3 = F_44 ( V_19 -> V_115 ) ;
return & V_3 -> V_184 . V_186 . V_182 == V_180 ;
}
static void F_97 ( struct V_8 * V_9 )
{
struct V_13 * V_14 = F_98 ( V_9 ) ;
F_99 ( V_9 -> V_185 ) ;
F_100 ( V_14 ) ;
}
int F_101 ( const struct V_8 * V_9 )
{
return V_9 -> V_187 == F_97 ;
}
static int F_102 ( struct V_179 * V_180 ,
struct V_8 * V_9 )
{
struct V_18 * V_19 ;
struct V_114 * V_3 ;
if ( ! F_101 ( V_9 ) )
return 0 ;
V_19 = F_9 ( V_9 -> V_185 ) ;
if ( ! V_19 -> V_115 || V_19 -> V_115 -> V_181 . V_182 . V_183
!= & V_101 . V_183 )
return 0 ;
V_3 = F_44 ( V_19 -> V_115 ) ;
return & V_3 -> V_188 . V_182 == V_180 ;
}
static void F_103 ( struct V_8 * V_9 )
{
struct V_135 * V_136 = F_104 ( V_9 ) ;
F_99 ( V_9 -> V_185 ) ;
F_100 ( V_136 ) ;
}
int F_105 ( const struct V_8 * V_9 )
{
return V_9 -> V_187 == F_103 ;
}
static int F_106 ( struct V_179 * V_180 ,
struct V_8 * V_9 )
{
struct V_135 * V_136 ;
struct V_18 * V_19 ;
struct V_114 * V_3 ;
if ( ! F_105 ( V_9 ) )
return 0 ;
V_136 = F_104 ( V_9 ) ;
V_19 = F_53 ( V_136 ) ;
if ( ! V_19 -> V_115 || V_19 -> V_115 -> V_181 . V_182 . V_183
!= & V_101 . V_183 )
return 0 ;
V_3 = F_44 ( V_19 -> V_115 ) ;
return & V_3 -> V_189 . V_182 == V_180 ;
}
static enum V_190
F_107 ( struct V_191 * V_192 )
{
struct V_13 * V_14 = F_4 ( V_11 ( V_192 -> V_8 ) ) ;
if ( V_14 -> V_40 == V_116 )
return V_193 ;
return V_194 ;
}
static void
F_108 ( struct V_18 * V_19 , T_8 V_177 , T_8 V_195 , T_8 V_196 )
{
struct V_13 * V_14 ;
unsigned long V_137 ;
F_54 ( V_19 -> V_138 , V_137 ) ;
F_82 (rport, &fc_host_rports(shost), peers) {
if ( V_14 -> V_197 == - 1 )
continue;
if ( V_14 -> V_40 != V_198 )
continue;
if ( ( V_177 == V_14 -> V_177 ) &&
( V_195 == V_14 -> V_197 ) ) {
F_55 ( V_19 -> V_138 , V_137 ) ;
F_109 ( & V_14 -> V_9 , V_177 , V_195 , V_196 , 1 ) ;
return;
}
}
F_55 ( V_19 -> V_138 , V_137 ) ;
}
static int
F_110 ( struct V_18 * V_19 , T_8 V_177 , T_8 V_195 , T_8 V_196 )
{
T_8 V_199 , V_200 ;
T_8 V_201 , V_202 ;
if ( ( ( V_177 != V_203 ) && ( V_177 > V_19 -> V_204 ) ) ||
( ( V_195 != V_203 ) && ( V_195 >= V_19 -> V_205 ) ) ||
( ( V_196 != V_203 ) && ( V_196 > V_19 -> V_206 ) ) )
return - V_112 ;
if ( V_177 == V_203 ) {
V_199 = 0 ;
V_200 = V_19 -> V_204 + 1 ;
} else {
V_199 = V_177 ;
V_200 = V_177 + 1 ;
}
if ( V_195 == V_203 ) {
V_201 = 0 ;
V_202 = V_19 -> V_205 ;
} else {
V_201 = V_195 ;
V_202 = V_195 + 1 ;
}
for ( ; V_199 < V_200 ; V_199 ++ )
for ( ; V_201 < V_202 ; V_201 ++ )
F_108 ( V_19 , V_199 , V_201 , V_196 ) ;
return 0 ;
}
static int F_111 ( struct V_18 * V_19 , T_3 V_207 , T_3 V_208 ,
int V_209 )
{
struct V_114 * V_3 = F_44 ( V_19 -> V_115 ) ;
return V_3 -> V_122 -> V_210 ( V_19 , V_207 , V_208 , V_209 ) ;
}
static int F_112 ( struct V_18 * V_19 , T_3 V_207 , int V_209 )
{
struct V_114 * V_3 = F_44 ( V_19 -> V_115 ) ;
return V_3 -> V_122 -> V_211 ( V_19 , V_207 , V_209 ) ;
}
struct V_212 *
F_113 ( struct V_213 * V_214 )
{
int V_124 ;
struct V_114 * V_3 = F_114 ( sizeof( struct V_114 ) ,
V_82 ) ;
if ( F_115 ( ! V_3 ) )
return NULL ;
V_3 -> V_184 . V_186 . V_182 . V_215 = & V_3 -> V_216 [ 0 ] ;
V_3 -> V_184 . V_186 . V_182 . V_183 = & V_106 . V_183 ;
V_3 -> V_184 . V_186 . V_182 . V_176 = F_95 ;
V_3 -> V_184 . V_217 = sizeof( struct V_218 ) ;
F_116 ( & V_3 -> V_184 . V_186 ) ;
V_3 -> V_184 . V_181 . V_182 . V_215 = & V_3 -> V_181 [ 0 ] ;
V_3 -> V_184 . V_181 . V_182 . V_183 = & V_101 . V_183 ;
V_3 -> V_184 . V_181 . V_182 . V_176 = F_93 ;
V_3 -> V_184 . V_219 = sizeof( struct V_20 ) ;
if ( V_214 -> V_159 )
V_3 -> V_184 . V_181 . V_220 = & V_221 ;
F_116 ( & V_3 -> V_184 . V_181 ) ;
V_3 -> V_188 . V_182 . V_215 = & V_3 -> V_222 [ 0 ] ;
V_3 -> V_188 . V_182 . V_183 = & V_104 . V_183 ;
V_3 -> V_188 . V_182 . V_176 = F_102 ;
F_116 ( & V_3 -> V_188 ) ;
V_3 -> V_189 . V_182 . V_215 = & V_3 -> V_223 [ 0 ] ;
V_3 -> V_189 . V_182 . V_183 = & V_102 . V_183 ;
V_3 -> V_189 . V_182 . V_176 = F_106 ;
F_116 ( & V_3 -> V_189 ) ;
V_3 -> V_122 = V_214 ;
V_3 -> V_184 . V_224 = 1 ;
V_3 -> V_184 . V_225 = F_107 ;
V_3 -> V_184 . V_226 = F_110 ;
V_3 -> V_184 . V_210 = F_111 ;
V_3 -> V_184 . V_211 = F_112 ;
V_124 = 0 ;
F_117 ( V_15 ) ;
F_117 ( V_16 ) ;
F_117 ( V_17 ) ;
F_118 ( V_124 > V_227 ) ;
V_3 -> V_216 [ V_124 ] = NULL ;
V_124 = 0 ;
F_119 ( V_15 ) ;
F_119 ( V_16 ) ;
F_119 ( V_22 ) ;
F_119 ( V_23 ) ;
F_119 ( V_25 ) ;
F_119 ( V_26 ) ;
F_119 ( V_28 ) ;
if ( V_214 -> V_228 ) {
F_120 ( V_29 ) ;
F_120 ( V_55 ) ;
}
F_119 ( V_30 ) ;
F_119 ( V_31 ) ;
F_119 ( V_32 ) ;
F_119 ( V_33 ) ;
F_119 ( V_34 ) ;
F_119 ( V_35 ) ;
F_119 ( V_36 ) ;
F_119 ( V_37 ) ;
F_119 ( V_17 ) ;
F_119 ( V_38 ) ;
F_119 ( V_40 ) ;
F_119 ( V_42 ) ;
F_119 ( V_43 ) ;
F_119 ( V_44 ) ;
F_119 ( V_45 ) ;
F_121 ( V_46 ) ;
F_122 ( V_60 ) ;
F_122 ( V_47 ) ;
if ( V_214 -> V_155 )
F_122 ( V_229 ) ;
if ( V_214 -> V_228 )
F_122 ( V_228 ) ;
if ( V_214 -> V_230 )
F_122 ( V_230 ) ;
F_118 ( V_124 > V_231 ) ;
V_3 -> V_181 [ V_124 ] = NULL ;
V_124 = 0 ;
F_123 ( V_28 ) ;
F_123 ( V_23 ) ;
F_124 ( V_60 ) ;
F_125 ( V_15 ) ;
F_125 ( V_16 ) ;
F_125 ( V_17 ) ;
F_125 ( V_133 ) ;
F_125 ( V_40 ) ;
F_125 ( V_197 ) ;
F_126 ( V_120 ) ;
F_118 ( V_124 > V_232 ) ;
V_3 -> V_222 [ V_124 ] = NULL ;
V_124 = 0 ;
F_127 ( V_144 ) ;
F_127 ( V_233 ) ;
F_127 ( V_15 ) ;
F_127 ( V_16 ) ;
F_127 ( V_133 ) ;
F_127 ( V_170 ) ;
F_128 ( V_45 ) ;
F_129 ( V_230 ) ;
F_129 ( V_147 ) ;
F_118 ( V_124 > V_234 ) ;
V_3 -> V_223 [ V_124 ] = NULL ;
return & V_3 -> V_184 ;
}
void F_130 ( struct V_212 * V_184 )
{
struct V_114 * V_3 = F_44 ( V_184 ) ;
F_131 ( & V_3 -> V_184 . V_186 ) ;
F_131 ( & V_3 -> V_184 . V_181 ) ;
F_131 ( & V_3 -> V_188 ) ;
F_131 ( & V_3 -> V_189 ) ;
F_100 ( V_3 ) ;
}
static int
F_56 ( struct V_18 * V_19 , struct V_235 * V_236 )
{
if ( F_115 ( ! F_132 ( V_19 ) ) ) {
F_30 ( V_237
L_21
L_22 , V_19 -> V_238 -> V_76 ) ;
F_133 () ;
return - V_112 ;
}
return F_134 ( F_132 ( V_19 ) , V_236 ) ;
}
static void
F_135 ( struct V_18 * V_19 )
{
if ( ! F_132 ( V_19 ) ) {
F_30 ( V_237
L_23
L_22 , V_19 -> V_238 -> V_76 ) ;
F_133 () ;
return;
}
F_136 ( F_132 ( V_19 ) ) ;
}
static int
F_137 ( struct V_18 * V_19 , struct V_239 * V_236 ,
unsigned long V_240 )
{
if ( F_115 ( ! F_138 ( V_19 ) ) ) {
F_30 ( V_237
L_21
L_22 , V_19 -> V_238 -> V_76 ) ;
F_133 () ;
return - V_112 ;
}
return F_139 ( F_138 ( V_19 ) , V_236 , V_240 ) ;
}
static void
F_140 ( struct V_18 * V_19 )
{
if ( ! F_138 ( V_19 ) ) {
F_30 ( V_237
L_23
L_22 , V_19 -> V_238 -> V_76 ) ;
F_133 () ;
return;
}
F_136 ( F_138 ( V_19 ) ) ;
}
void
F_141 ( struct V_18 * V_19 )
{
struct V_135 * V_136 = NULL , * V_241 = NULL ;
struct V_13 * V_14 = NULL , * V_242 = NULL ;
struct V_243 * V_58 ;
struct V_20 * V_21 = F_10 ( V_19 ) ;
unsigned long V_137 ;
F_54 ( V_19 -> V_138 , V_137 ) ;
F_142 (vport, next_vport, &fc_host->vports, peers)
F_56 ( V_19 , & V_136 -> V_142 ) ;
F_142 (rport, next_rport,
&fc_host->rports, peers) {
F_78 ( & V_14 -> V_152 ) ;
V_14 -> V_40 = V_117 ;
F_56 ( V_19 , & V_14 -> V_153 ) ;
}
F_142 (rport, next_rport,
&fc_host->rport_bindings, peers) {
F_78 ( & V_14 -> V_152 ) ;
V_14 -> V_40 = V_117 ;
F_56 ( V_19 , & V_14 -> V_153 ) ;
}
F_55 ( V_19 -> V_138 , V_137 ) ;
F_143 ( V_19 ) ;
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
static void F_144 ( struct V_13 * V_14 )
{
struct V_18 * V_19 = F_43 ( V_14 ) ;
struct V_114 * V_3 = F_44 ( V_19 -> V_115 ) ;
if ( V_3 -> V_122 -> V_244 )
V_3 -> V_122 -> V_244 ( V_14 ) ;
F_145 ( & V_14 -> V_9 ) ;
}
static void
F_146 ( struct V_235 * V_236 )
{
struct V_13 * V_14 =
F_147 ( V_236 , struct V_13 , V_245 ) ;
F_144 ( V_14 ) ;
F_148 ( & V_14 -> V_9 ) ;
}
static void
F_149 ( struct V_235 * V_236 )
{
struct V_13 * V_14 =
F_147 ( V_236 , struct V_13 , V_153 ) ;
struct V_8 * V_9 = & V_14 -> V_9 ;
struct V_18 * V_19 = F_43 ( V_14 ) ;
struct V_114 * V_3 = F_44 ( V_19 -> V_115 ) ;
unsigned long V_137 ;
int V_246 = 0 ;
F_144 ( V_14 ) ;
if ( V_14 -> V_137 & V_247 )
F_143 ( V_19 ) ;
F_54 ( V_19 -> V_138 , V_137 ) ;
if ( V_14 -> V_137 & V_248 ) {
F_55 ( V_19 -> V_138 , V_137 ) ;
if ( ! F_150 ( & V_14 -> V_249 ) )
F_140 ( V_19 ) ;
if ( ! F_150 ( & V_14 -> V_250 ) )
F_140 ( V_19 ) ;
F_54 ( V_19 -> V_138 , V_137 ) ;
V_14 -> V_137 &= ~ V_248 ;
}
F_55 ( V_19 -> V_138 , V_137 ) ;
if ( V_14 -> V_197 != - 1 )
F_146 ( & V_14 -> V_245 ) ;
F_54 ( V_19 -> V_138 , V_137 ) ;
if ( ! ( V_14 -> V_137 & V_251 ) &&
( V_3 -> V_122 -> V_252 ) ) {
V_14 -> V_137 |= V_251 ;
V_246 = 1 ;
}
F_55 ( V_19 -> V_138 , V_137 ) ;
if ( V_246 )
V_3 -> V_122 -> V_252 ( V_14 ) ;
F_16 ( V_14 -> V_64 ) ;
F_151 ( V_9 ) ;
F_152 ( V_9 ) ;
F_153 ( V_9 ) ;
F_99 ( & V_19 -> V_173 ) ;
F_99 ( V_9 ) ;
}
static struct V_13 *
F_154 ( struct V_18 * V_19 , int V_177 ,
struct V_253 * V_254 )
{
struct V_20 * V_21 = F_10 ( V_19 ) ;
struct V_114 * V_255 = F_44 ( V_19 -> V_115 ) ;
struct V_13 * V_14 ;
struct V_8 * V_9 ;
unsigned long V_137 ;
int error ;
T_7 V_256 ;
V_256 = ( sizeof( struct V_13 ) + V_255 -> V_122 -> V_257 ) ;
V_14 = F_114 ( V_256 , V_82 ) ;
if ( F_115 ( ! V_14 ) ) {
F_30 ( V_237 L_24 , V_95 ) ;
return NULL ;
}
V_14 -> V_28 = - 1 ;
V_14 -> V_23 = V_24 ;
V_14 -> V_60 = V_21 -> V_60 ;
memcpy ( & V_14 -> V_15 , & V_254 -> V_15 , sizeof( V_14 -> V_15 ) ) ;
memcpy ( & V_14 -> V_16 , & V_254 -> V_16 , sizeof( V_14 -> V_16 ) ) ;
V_14 -> V_17 = V_254 -> V_17 ;
V_14 -> V_133 = V_254 -> V_133 ;
V_14 -> V_40 = V_198 ;
if ( V_255 -> V_122 -> V_257 )
V_14 -> V_258 = & V_14 [ 1 ] ;
V_14 -> V_177 = V_177 ;
V_14 -> V_120 = - 1 ;
F_155 ( & V_14 -> V_250 , V_259 ) ;
F_155 ( & V_14 -> V_249 , V_260 ) ;
F_156 ( & V_14 -> V_261 , V_262 ) ;
F_156 ( & V_14 -> V_245 , F_146 ) ;
F_156 ( & V_14 -> V_153 , F_149 ) ;
F_54 ( V_19 -> V_138 , V_137 ) ;
V_14 -> V_263 = V_21 -> V_52 ++ ;
if ( V_14 -> V_133 & V_264 )
V_14 -> V_197 = V_21 -> V_53 ++ ;
else
V_14 -> V_197 = - 1 ;
F_157 ( & V_14 -> V_152 , & V_21 -> V_49 ) ;
F_158 ( & V_19 -> V_173 ) ;
F_55 ( V_19 -> V_138 , V_137 ) ;
V_9 = & V_14 -> V_9 ;
F_159 ( V_9 ) ;
V_9 -> V_185 = F_158 ( & V_19 -> V_173 ) ;
V_9 -> V_187 = F_97 ;
F_160 ( V_9 , L_25 ,
V_19 -> V_57 , V_177 , V_14 -> V_263 ) ;
F_161 ( V_9 ) ;
error = F_162 ( V_9 ) ;
if ( error ) {
F_30 ( V_237 L_26 ) ;
goto V_265;
}
F_163 ( V_9 ) ;
F_164 ( V_9 ) ;
F_165 ( V_19 , V_14 ) ;
if ( V_14 -> V_133 & V_264 ) {
V_14 -> V_137 |= V_247 ;
F_166 ( V_19 , & V_14 -> V_261 ) ;
}
return V_14 ;
V_265:
F_153 ( V_9 ) ;
F_54 ( V_19 -> V_138 , V_137 ) ;
F_78 ( & V_14 -> V_152 ) ;
F_99 ( & V_19 -> V_173 ) ;
F_55 ( V_19 -> V_138 , V_137 ) ;
F_99 ( V_9 -> V_185 ) ;
F_100 ( V_14 ) ;
return NULL ;
}
struct V_13 *
F_167 ( struct V_18 * V_19 , int V_177 ,
struct V_253 * V_254 )
{
struct V_114 * V_255 = F_44 ( V_19 -> V_115 ) ;
struct V_20 * V_21 = F_10 ( V_19 ) ;
struct V_13 * V_14 ;
unsigned long V_137 ;
int V_176 = 0 ;
F_135 ( V_19 ) ;
F_54 ( V_19 -> V_138 , V_137 ) ;
F_82 (rport, &fc_host->rports, peers) {
if ( ( V_14 -> V_40 == V_116 ) &&
( V_14 -> V_177 == V_177 ) ) {
switch ( V_21 -> V_47 ) {
case V_48 :
case V_266 :
if ( V_14 -> V_16 == V_254 -> V_16 )
V_176 = 1 ;
break;
case V_267 :
if ( V_14 -> V_15 == V_254 -> V_15 )
V_176 = 1 ;
break;
case V_268 :
if ( V_14 -> V_17 == V_254 -> V_17 )
V_176 = 1 ;
break;
}
if ( V_176 ) {
memcpy ( & V_14 -> V_15 , & V_254 -> V_15 ,
sizeof( V_14 -> V_15 ) ) ;
memcpy ( & V_14 -> V_16 , & V_254 -> V_16 ,
sizeof( V_14 -> V_16 ) ) ;
V_14 -> V_17 = V_254 -> V_17 ;
V_14 -> V_40 = V_198 ;
V_14 -> V_133 = V_254 -> V_133 ;
F_55 ( V_19 -> V_138 , V_137 ) ;
if ( V_255 -> V_122 -> V_257 )
memset ( V_14 -> V_258 , 0 ,
V_255 -> V_122 -> V_257 ) ;
if ( ( V_14 -> V_197 != - 1 ) &&
( ! ( V_254 -> V_133 & V_264 ) ) )
return V_14 ;
if ( ! F_150 ( & V_14 -> V_249 ) )
F_140 ( V_19 ) ;
if ( ! F_150 ( & V_14 -> V_250 ) )
F_140 ( V_19 ) ;
F_54 ( V_19 -> V_138 , V_137 ) ;
V_14 -> V_137 &= ~ ( V_269 |
V_248 |
V_251 ) ;
F_55 ( V_19 -> V_138 , V_137 ) ;
if ( V_14 -> V_197 != - 1 ) {
F_145 ( & V_14 -> V_9 ) ;
F_54 ( V_19 -> V_138 ,
V_137 ) ;
V_14 -> V_137 |= V_247 ;
F_166 ( V_19 ,
& V_14 -> V_261 ) ;
F_55 ( V_19 -> V_138 ,
V_137 ) ;
}
F_168 ( V_14 ) ;
return V_14 ;
}
}
}
if ( V_21 -> V_47 != V_266 ) {
F_82 (rport, &fc_host->rport_bindings,
peers) {
if ( V_14 -> V_177 != V_177 )
continue;
switch ( V_21 -> V_47 ) {
case V_48 :
if ( V_14 -> V_16 == V_254 -> V_16 )
V_176 = 1 ;
break;
case V_267 :
if ( V_14 -> V_15 == V_254 -> V_15 )
V_176 = 1 ;
break;
case V_268 :
if ( V_14 -> V_17 == V_254 -> V_17 )
V_176 = 1 ;
break;
case V_266 :
break;
}
if ( V_176 ) {
F_169 ( & V_14 -> V_152 , & V_21 -> V_49 ) ;
break;
}
}
if ( V_176 ) {
memcpy ( & V_14 -> V_15 , & V_254 -> V_15 ,
sizeof( V_14 -> V_15 ) ) ;
memcpy ( & V_14 -> V_16 , & V_254 -> V_16 ,
sizeof( V_14 -> V_16 ) ) ;
V_14 -> V_17 = V_254 -> V_17 ;
V_14 -> V_133 = V_254 -> V_133 ;
V_14 -> V_40 = V_198 ;
V_14 -> V_137 &= ~ V_269 ;
if ( V_255 -> V_122 -> V_257 )
memset ( V_14 -> V_258 , 0 ,
V_255 -> V_122 -> V_257 ) ;
F_55 ( V_19 -> V_138 , V_137 ) ;
if ( V_254 -> V_133 & V_264 ) {
F_145 ( & V_14 -> V_9 ) ;
F_54 ( V_19 -> V_138 , V_137 ) ;
V_14 -> V_137 |= V_247 ;
F_166 ( V_19 , & V_14 -> V_261 ) ;
F_55 ( V_19 -> V_138 , V_137 ) ;
}
return V_14 ;
}
}
F_55 ( V_19 -> V_138 , V_137 ) ;
V_14 = F_154 ( V_19 , V_177 , V_254 ) ;
return V_14 ;
}
void
F_170 ( struct V_13 * V_14 )
{
struct V_18 * V_19 = F_43 ( V_14 ) ;
unsigned long V_270 = V_14 -> V_60 ;
unsigned long V_137 ;
F_54 ( V_19 -> V_138 , V_137 ) ;
if ( V_14 -> V_40 != V_198 ) {
F_55 ( V_19 -> V_138 , V_137 ) ;
return;
}
V_14 -> V_40 = V_116 ;
V_14 -> V_137 |= V_248 ;
F_55 ( V_19 -> V_138 , V_137 ) ;
if ( V_14 -> V_133 & V_169 &&
V_19 -> V_271 & V_272 )
F_171 ( V_19 , ( unsigned long ) V_14 ) ;
F_172 ( & V_14 -> V_9 ) ;
if ( ( V_14 -> V_120 != - 1 ) &&
( V_14 -> V_120 < V_270 ) )
F_137 ( V_19 , & V_14 -> V_249 ,
V_14 -> V_120 * V_273 ) ;
F_137 ( V_19 , & V_14 -> V_250 , V_270 * V_273 ) ;
}
void
F_173 ( struct V_13 * V_14 , T_2 V_133 )
{
struct V_18 * V_19 = F_43 ( V_14 ) ;
struct V_20 * V_21 = F_10 ( V_19 ) ;
unsigned long V_137 ;
int V_274 = 0 ;
int V_154 ;
F_54 ( V_19 -> V_138 , V_137 ) ;
if ( V_133 & V_264 ) {
if ( V_14 -> V_197 == - 1 ) {
V_14 -> V_197 = V_21 -> V_53 ++ ;
V_274 = 1 ;
} else if ( ! ( V_14 -> V_133 & V_264 ) )
V_274 = 1 ;
} else if ( V_19 -> V_271 & V_272 ) {
V_154 = F_174 ( V_19 , ( unsigned long ) V_14 ,
( char * ) & V_14 -> V_15 ) ;
if ( V_154 )
F_30 ( V_237 L_27 ,
V_154 ) ;
}
V_14 -> V_133 = V_133 ;
F_55 ( V_19 -> V_138 , V_137 ) ;
if ( V_274 ) {
if ( ! F_150 ( & V_14 -> V_249 ) )
F_140 ( V_19 ) ;
if ( ! F_150 ( & V_14 -> V_250 ) )
F_140 ( V_19 ) ;
F_54 ( V_19 -> V_138 , V_137 ) ;
V_14 -> V_137 &= ~ ( V_269 |
V_248 |
V_251 ) ;
F_55 ( V_19 -> V_138 , V_137 ) ;
F_135 ( V_19 ) ;
F_145 ( & V_14 -> V_9 ) ;
F_54 ( V_19 -> V_138 , V_137 ) ;
V_14 -> V_137 |= V_247 ;
F_166 ( V_19 , & V_14 -> V_261 ) ;
F_55 ( V_19 -> V_138 , V_137 ) ;
}
}
static void
V_259 ( struct V_235 * V_236 )
{
struct V_13 * V_14 =
F_147 ( V_236 , struct V_13 , V_250 . V_236 ) ;
struct V_18 * V_19 = F_43 ( V_14 ) ;
struct V_114 * V_3 = F_44 ( V_19 -> V_115 ) ;
struct V_20 * V_21 = F_10 ( V_19 ) ;
unsigned long V_137 ;
int V_246 = 0 ;
F_54 ( V_19 -> V_138 , V_137 ) ;
V_14 -> V_137 &= ~ V_248 ;
if ( ( V_14 -> V_40 == V_198 ) &&
( V_14 -> V_197 != - 1 ) &&
! ( V_14 -> V_133 & V_264 ) ) {
F_175 ( V_237 , & V_14 -> V_9 ,
L_28
L_29 ) ;
F_55 ( V_19 -> V_138 , V_137 ) ;
F_145 ( & V_14 -> V_9 ) ;
F_56 ( V_19 , & V_14 -> V_245 ) ;
return;
}
if ( V_14 -> V_40 != V_116 ) {
F_55 ( V_19 -> V_138 , V_137 ) ;
F_175 ( V_237 , & V_14 -> V_9 ,
L_30
L_31 ,
( V_14 -> V_197 != - 1 ) ? L_32 : L_33 ) ;
return;
}
if ( ( V_21 -> V_47 == V_266 ) ||
( V_14 -> V_197 == - 1 ) ) {
F_78 ( & V_14 -> V_152 ) ;
V_14 -> V_40 = V_117 ;
F_175 ( V_237 , & V_14 -> V_9 ,
L_34
L_35 ,
( V_14 -> V_197 != - 1 ) ? L_32 : L_33 ) ;
F_56 ( V_19 , & V_14 -> V_153 ) ;
F_55 ( V_19 -> V_138 , V_137 ) ;
return;
}
F_175 ( V_237 , & V_14 -> V_9 ,
L_36
L_37 ) ;
F_169 ( & V_14 -> V_152 , & V_21 -> V_50 ) ;
V_14 -> V_28 = - 1 ;
V_14 -> V_23 = V_24 ;
V_14 -> V_133 = V_134 ;
V_14 -> V_40 = V_118 ;
V_14 -> V_137 &= ~ V_269 ;
F_55 ( V_19 -> V_138 , V_137 ) ;
F_144 ( V_14 ) ;
F_54 ( V_19 -> V_138 , V_137 ) ;
if ( V_14 -> V_40 == V_118 ) {
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
V_14 -> V_137 |= V_251 ;
F_56 ( V_19 , & V_14 -> V_245 ) ;
V_246 = 1 ;
}
F_55 ( V_19 -> V_138 , V_137 ) ;
if ( V_246 && V_3 -> V_122 -> V_252 )
V_3 -> V_122 -> V_252 ( V_14 ) ;
}
static void
V_260 ( struct V_235 * V_236 )
{
struct V_13 * V_14 =
F_147 ( V_236 , struct V_13 , V_249 . V_236 ) ;
if ( V_14 -> V_40 != V_116 )
return;
V_14 -> V_137 |= V_269 ;
F_144 ( V_14 ) ;
}
static void
V_262 ( struct V_235 * V_236 )
{
struct V_13 * V_14 =
F_147 ( V_236 , struct V_13 , V_261 ) ;
struct V_18 * V_19 = F_43 ( V_14 ) ;
struct V_114 * V_3 = F_44 ( V_19 -> V_115 ) ;
unsigned long V_137 ;
if ( ( V_14 -> V_40 == V_198 ) &&
( V_14 -> V_133 & V_264 ) &&
! ( V_3 -> V_122 -> V_275 ) ) {
F_109 ( & V_14 -> V_9 , V_14 -> V_177 ,
V_14 -> V_197 , V_203 , 1 ) ;
}
F_54 ( V_19 -> V_138 , V_137 ) ;
V_14 -> V_137 &= ~ V_247 ;
F_55 ( V_19 -> V_138 , V_137 ) ;
}
int F_176 ( struct V_191 * V_276 )
{
struct V_18 * V_19 = V_276 -> V_8 -> V_277 ;
struct V_13 * V_14 = F_4 ( V_11 ( V_276 -> V_8 ) ) ;
unsigned long V_137 ;
F_54 ( V_19 -> V_138 , V_137 ) ;
while ( V_14 -> V_40 == V_116 &&
! ( V_14 -> V_137 & V_269 ) ) {
F_55 ( V_19 -> V_138 , V_137 ) ;
F_177 ( 1000 ) ;
F_54 ( V_19 -> V_138 , V_137 ) ;
}
F_55 ( V_19 -> V_138 , V_137 ) ;
if ( V_14 -> V_137 & V_269 )
return V_278 ;
return 0 ;
}
static int
F_90 ( struct V_18 * V_19 , int V_177 , struct V_8 * V_279 ,
struct V_166 * V_254 , struct V_135 * * V_280 )
{
struct V_20 * V_21 = F_10 ( V_19 ) ;
struct V_114 * V_255 = F_44 ( V_19 -> V_115 ) ;
struct V_135 * V_136 ;
struct V_8 * V_9 ;
unsigned long V_137 ;
T_7 V_256 ;
int error ;
* V_280 = NULL ;
if ( ! V_255 -> V_122 -> V_228 )
return - V_80 ;
V_256 = ( sizeof( struct V_135 ) + V_255 -> V_122 -> V_281 ) ;
V_136 = F_114 ( V_256 , V_82 ) ;
if ( F_115 ( ! V_136 ) ) {
F_30 ( V_237 L_24 , V_95 ) ;
return - V_59 ;
}
V_136 -> V_144 = V_282 ;
V_136 -> V_233 = V_282 ;
V_136 -> V_15 = V_254 -> V_15 ;
V_136 -> V_16 = V_254 -> V_16 ;
V_136 -> V_133 = V_254 -> V_133 ;
V_136 -> V_170 = V_254 -> V_170 ;
if ( V_255 -> V_122 -> V_281 )
V_136 -> V_258 = & V_136 [ 1 ] ;
V_136 -> V_19 = V_19 ;
V_136 -> V_177 = V_177 ;
V_136 -> V_137 = V_140 ;
F_156 ( & V_136 -> V_142 , V_283 ) ;
F_54 ( V_19 -> V_138 , V_137 ) ;
if ( V_21 -> V_55 >= V_21 -> V_29 ) {
F_55 ( V_19 -> V_138 , V_137 ) ;
F_100 ( V_136 ) ;
return - V_284 ;
}
V_21 -> V_55 ++ ;
V_136 -> V_263 = V_21 -> V_54 ++ ;
F_157 ( & V_136 -> V_152 , & V_21 -> V_51 ) ;
F_158 ( & V_19 -> V_173 ) ;
F_55 ( V_19 -> V_138 , V_137 ) ;
V_9 = & V_136 -> V_9 ;
F_159 ( V_9 ) ;
V_9 -> V_185 = F_158 ( V_279 ) ;
V_9 -> V_187 = F_103 ;
F_160 ( V_9 , L_38 ,
V_19 -> V_57 , V_177 , V_136 -> V_263 ) ;
F_161 ( V_9 ) ;
error = F_162 ( V_9 ) ;
if ( error ) {
F_30 ( V_237 L_39 ) ;
goto V_285;
}
F_163 ( V_9 ) ;
F_164 ( V_9 ) ;
error = V_255 -> V_122 -> V_228 ( V_136 , V_254 -> V_172 ) ;
if ( error ) {
F_30 ( V_237 L_40 ) ;
goto V_286;
}
if ( V_279 != & V_19 -> V_173 ) {
error = F_178 ( & V_19 -> V_173 . V_287 ,
& V_9 -> V_287 , F_179 ( V_9 ) ) ;
if ( error )
F_30 ( V_237
L_41
L_42 ,
V_95 , F_179 ( V_9 ) , error ) ;
}
F_54 ( V_19 -> V_138 , V_137 ) ;
V_136 -> V_137 &= ~ V_140 ;
F_55 ( V_19 -> V_138 , V_137 ) ;
F_175 ( V_288 , V_279 ,
L_43 , F_179 ( V_9 ) ,
V_19 -> V_57 , V_177 ) ;
* V_280 = V_136 ;
return 0 ;
V_286:
F_151 ( V_9 ) ;
F_152 ( V_9 ) ;
V_285:
F_153 ( V_9 ) ;
F_54 ( V_19 -> V_138 , V_137 ) ;
F_78 ( & V_136 -> V_152 ) ;
F_99 ( & V_19 -> V_173 ) ;
V_21 -> V_55 -- ;
F_55 ( V_19 -> V_138 , V_137 ) ;
F_99 ( V_9 -> V_185 ) ;
F_100 ( V_136 ) ;
return error ;
}
struct V_135 *
F_180 ( struct V_18 * V_19 , int V_177 ,
struct V_166 * V_254 )
{
int V_143 ;
struct V_135 * V_136 ;
V_143 = F_90 ( V_19 , V_177 , & V_19 -> V_173 ,
V_254 , & V_136 ) ;
return V_143 ? NULL : V_136 ;
}
int
F_92 ( struct V_135 * V_136 )
{
struct V_18 * V_19 = F_53 ( V_136 ) ;
struct V_20 * V_21 = F_10 ( V_19 ) ;
struct V_114 * V_3 = F_44 ( V_19 -> V_115 ) ;
struct V_8 * V_9 = & V_136 -> V_9 ;
unsigned long V_137 ;
int V_143 ;
if ( V_3 -> V_122 -> V_230 )
V_143 = V_3 -> V_122 -> V_230 ( V_136 ) ;
else
V_143 = - V_80 ;
F_54 ( V_19 -> V_138 , V_137 ) ;
V_136 -> V_137 &= ~ V_141 ;
if ( ! V_143 ) {
V_136 -> V_137 |= V_289 ;
F_78 ( & V_136 -> V_152 ) ;
V_21 -> V_55 -- ;
F_99 ( & V_19 -> V_173 ) ;
}
F_55 ( V_19 -> V_138 , V_137 ) ;
if ( V_143 )
return V_143 ;
if ( V_9 -> V_185 != & V_19 -> V_173 )
F_181 ( & V_19 -> V_173 . V_287 , F_179 ( V_9 ) ) ;
F_151 ( V_9 ) ;
F_152 ( V_9 ) ;
F_153 ( V_9 ) ;
F_99 ( V_9 ) ;
return 0 ;
}
static void
V_283 ( struct V_235 * V_236 )
{
struct V_135 * V_136 =
F_147 ( V_236 , struct V_135 , V_142 ) ;
int V_143 ;
V_143 = F_92 ( V_136 ) ;
if ( V_143 )
F_175 ( V_237 , V_136 -> V_9 . V_185 ,
L_44
L_45 , V_95 ,
F_179 ( & V_136 -> V_9 ) , V_136 -> V_19 -> V_57 ,
V_136 -> V_177 , V_143 ) ;
}
static void
F_182 ( struct V_290 * V_291 )
{
unsigned long V_137 ;
F_54 ( & V_291 -> V_292 , V_137 ) ;
if ( V_291 -> V_293 ) {
F_55 ( & V_291 -> V_292 , V_137 ) ;
return;
}
F_55 ( & V_291 -> V_292 , V_137 ) ;
F_99 ( V_291 -> V_9 ) ;
F_100 ( V_291 -> V_294 . V_295 ) ;
F_100 ( V_291 -> V_296 . V_295 ) ;
F_100 ( V_291 ) ;
}
static void
F_183 ( struct V_290 * V_291 )
{
struct V_297 * V_298 = V_291 -> V_298 ;
struct V_297 * V_299 = V_298 -> V_300 ;
int V_78 ;
V_78 = V_291 -> V_298 -> V_301 = V_291 -> V_302 -> V_209 ;
if ( V_78 < 0 )
V_291 -> V_298 -> V_303 = sizeof( V_304 ) ;
else
V_291 -> V_298 -> V_303 = V_291 -> V_305 ;
V_298 -> V_306 = 0 ;
if ( V_299 ) {
F_84 ( V_291 -> V_302 -> V_307 > V_299 -> V_306 ) ;
V_299 -> V_306 -= F_184 ( V_291 -> V_302 -> V_307 ,
V_299 -> V_306 ) ;
}
F_185 ( V_298 ) ;
}
static void F_186 ( struct V_297 * V_308 )
{
struct V_290 * V_291 = V_308 -> V_309 ;
unsigned long V_137 ;
F_54 ( & V_291 -> V_292 , V_137 ) ;
V_291 -> V_310 |= V_311 ;
V_291 -> V_293 -- ;
F_55 ( & V_291 -> V_292 , V_137 ) ;
F_187 ( V_308 , V_308 -> V_301 ) ;
F_182 ( V_291 ) ;
}
static enum V_190
F_188 ( struct V_297 * V_298 )
{
struct V_290 * V_291 = ( void * ) V_298 -> V_309 ;
struct V_18 * V_19 = V_291 -> V_19 ;
struct V_114 * V_3 = F_44 ( V_19 -> V_115 ) ;
unsigned long V_137 ;
int V_78 = 0 , V_312 = 0 ;
if ( V_291 -> V_14 && V_291 -> V_14 -> V_40 == V_116 )
return V_193 ;
F_54 ( & V_291 -> V_292 , V_137 ) ;
if ( V_291 -> V_310 & V_311 )
V_312 = 1 ;
else
V_291 -> V_293 ++ ;
F_55 ( & V_291 -> V_292 , V_137 ) ;
if ( ! V_312 && V_3 -> V_122 -> V_313 ) {
V_78 = V_3 -> V_122 -> V_313 ( V_291 ) ;
if ( V_78 == - V_314 ) {
V_291 -> V_293 -- ;
return V_193 ;
} else if ( V_78 )
F_30 ( V_237 L_46
L_47 , V_78 ) ;
}
if ( V_312 )
return V_194 ;
else
return V_315 ;
}
static int
F_189 ( struct V_316 * V_1 , struct V_297 * V_298 )
{
T_7 V_317 = ( sizeof( struct V_318 ) * V_298 -> V_319 ) ;
F_118 ( ! V_298 -> V_319 ) ;
V_1 -> V_295 = F_114 ( V_317 , V_82 ) ;
if ( ! V_1 -> V_295 )
return - V_59 ;
F_190 ( V_1 -> V_295 , V_298 -> V_319 ) ;
V_1 -> V_320 = F_191 ( V_298 -> V_321 , V_298 , V_1 -> V_295 ) ;
V_1 -> V_322 = F_192 ( V_298 ) ;
return 0 ;
}
static int
F_193 ( struct V_18 * V_19 , struct V_13 * V_14 ,
struct V_297 * V_298 )
{
struct V_114 * V_3 = F_44 ( V_19 -> V_115 ) ;
struct V_297 * V_299 = V_298 -> V_300 ;
struct V_290 * V_291 ;
int V_154 ;
F_118 ( V_298 -> V_309 ) ;
V_291 = F_114 ( sizeof( struct V_290 ) + V_3 -> V_122 -> V_323 ,
V_82 ) ;
if ( ! V_291 )
return - V_59 ;
V_298 -> V_309 = V_291 ;
V_291 -> V_19 = V_19 ;
V_291 -> V_14 = V_14 ;
V_291 -> V_298 = V_298 ;
if ( V_3 -> V_122 -> V_323 )
V_291 -> V_258 = ( void * ) & V_291 [ 1 ] ;
F_194 ( & V_291 -> V_292 ) ;
V_291 -> V_297 = (struct V_324 * ) V_298 -> V_325 ;
V_291 -> V_326 = V_298 -> V_327 ;
V_291 -> V_302 = V_298 -> V_328 ;
V_291 -> V_305 = V_329 ;
if ( V_298 -> V_330 ) {
V_154 = F_189 ( & V_291 -> V_294 , V_298 ) ;
if ( V_154 )
goto V_331;
}
if ( V_299 && V_299 -> V_330 ) {
V_154 = F_189 ( & V_291 -> V_296 , V_299 ) ;
if ( V_154 )
goto V_332;
}
V_291 -> V_333 = F_183 ;
if ( V_14 )
V_291 -> V_9 = & V_14 -> V_9 ;
else
V_291 -> V_9 = & V_19 -> V_173 ;
F_158 ( V_291 -> V_9 ) ;
V_291 -> V_293 = 1 ;
return 0 ;
V_332:
F_100 ( V_291 -> V_294 . V_295 ) ;
V_331:
F_100 ( V_291 ) ;
return - V_59 ;
}
static enum V_334
F_195 ( struct V_335 * V_321 , struct V_18 * V_19 ,
struct V_290 * V_291 )
{
struct V_114 * V_3 = F_44 ( V_19 -> V_115 ) ;
int V_336 = sizeof( V_304 ) ;
int V_154 ;
switch ( V_291 -> V_297 -> V_337 ) {
case V_338 :
V_336 += sizeof( struct V_339 ) ;
break;
case V_340 :
V_336 += sizeof( struct V_341 ) ;
break;
case V_342 :
V_336 += sizeof( struct V_343 ) ;
if ( ( ! V_291 -> V_294 . V_322 ) ||
( ! V_291 -> V_296 . V_322 ) ) {
V_154 = - V_112 ;
goto V_344;
}
break;
case V_345 :
V_336 += sizeof( struct V_346 ) ;
if ( ( ! V_291 -> V_294 . V_322 ) ||
( ! V_291 -> V_296 . V_322 ) ) {
V_154 = - V_112 ;
goto V_344;
}
break;
case V_347 :
V_336 += sizeof( struct V_348 ) ;
if ( ( V_19 -> V_238 -> V_90 == 0L ) ||
( V_291 -> V_297 -> V_349 . V_350 . V_90 !=
V_19 -> V_238 -> V_90 ) ) {
V_154 = - V_351 ;
goto V_344;
}
break;
default:
V_154 = - V_352 ;
goto V_344;
}
if ( V_291 -> V_326 < V_336 ) {
V_154 = - V_353 ;
goto V_344;
}
V_154 = V_3 -> V_122 -> V_354 ( V_291 ) ;
if ( ! V_154 )
return V_355 ;
V_344:
F_118 ( V_291 -> V_305 < sizeof( V_304 ) ) ;
V_291 -> V_302 -> V_307 = 0 ;
V_291 -> V_302 -> V_209 = V_154 ;
V_291 -> V_305 = sizeof( V_304 ) ;
F_183 ( V_291 ) ;
return V_355 ;
}
static void
F_168 ( struct V_13 * V_14 )
{
if ( ! V_14 -> V_64 )
return;
F_158 ( & V_14 -> V_9 ) ;
F_196 ( V_14 -> V_64 ) ;
F_99 ( & V_14 -> V_9 ) ;
}
static enum V_334
F_197 ( struct V_335 * V_321 , struct V_18 * V_19 ,
struct V_13 * V_14 , struct V_290 * V_291 )
{
struct V_114 * V_3 = F_44 ( V_19 -> V_115 ) ;
int V_336 = sizeof( V_304 ) ;
int V_154 ;
switch ( V_291 -> V_297 -> V_337 ) {
case V_356 :
V_336 += sizeof( struct V_357 ) ;
goto V_358;
case V_359 :
V_336 += sizeof( struct V_360 ) ;
V_358:
if ( ( ! V_291 -> V_294 . V_322 ) ||
( ! V_291 -> V_296 . V_322 ) ) {
V_154 = - V_112 ;
goto V_361;
}
break;
default:
V_154 = - V_352 ;
goto V_361;
}
if ( V_291 -> V_326 < V_336 ) {
V_154 = - V_353 ;
goto V_361;
}
V_154 = V_3 -> V_122 -> V_354 ( V_291 ) ;
if ( ! V_154 )
return V_355 ;
V_361:
F_118 ( V_291 -> V_305 < sizeof( V_304 ) ) ;
V_291 -> V_302 -> V_307 = 0 ;
V_291 -> V_302 -> V_209 = V_154 ;
V_291 -> V_305 = sizeof( V_304 ) ;
F_183 ( V_291 ) ;
return V_355 ;
}
static void
F_198 ( struct V_335 * V_321 , struct V_18 * V_19 ,
struct V_13 * V_14 , struct V_8 * V_9 )
{
struct V_297 * V_298 ;
struct V_290 * V_291 ;
enum V_334 V_154 ;
if ( ! F_158 ( V_9 ) )
return;
while ( 1 ) {
if ( V_14 && ( V_14 -> V_40 == V_116 ) &&
! ( V_14 -> V_137 & V_269 ) )
break;
V_298 = F_199 ( V_321 ) ;
if ( ! V_298 )
break;
if ( V_14 && ( V_14 -> V_40 != V_198 ) ) {
V_298 -> V_301 = - V_362 ;
F_200 ( V_321 -> V_363 ) ;
F_187 ( V_298 , - V_362 ) ;
F_201 ( V_321 -> V_363 ) ;
continue;
}
F_200 ( V_321 -> V_363 ) ;
V_154 = F_193 ( V_19 , V_14 , V_298 ) ;
if ( V_154 ) {
V_298 -> V_301 = V_154 ;
F_187 ( V_298 , V_154 ) ;
F_201 ( V_321 -> V_363 ) ;
continue;
}
V_291 = V_298 -> V_309 ;
if ( V_291 -> V_326 < sizeof( V_304 ) ) {
F_118 ( V_291 -> V_305 < sizeof( V_304 ) ) ;
V_291 -> V_302 -> V_307 = 0 ;
V_291 -> V_302 -> V_209 = - V_353 ;
V_291 -> V_305 = sizeof( V_304 ) ;
F_183 ( V_291 ) ;
F_201 ( V_321 -> V_363 ) ;
continue;
}
if ( V_14 )
V_154 = F_197 ( V_321 , V_19 , V_14 , V_291 ) ;
else
V_154 = F_195 ( V_321 , V_19 , V_291 ) ;
if ( V_154 == V_364 )
break;
if ( V_154 == V_355 )
F_201 ( V_321 -> V_363 ) ;
}
F_200 ( V_321 -> V_363 ) ;
F_99 ( V_9 ) ;
F_201 ( V_321 -> V_363 ) ;
}
static void
F_202 ( struct V_335 * V_321 )
{
struct V_18 * V_19 = V_321 -> V_365 ;
F_198 ( V_321 , V_19 , NULL , & V_19 -> V_173 ) ;
}
static void
F_203 ( struct V_335 * V_321 )
{
struct V_13 * V_14 = V_321 -> V_365 ;
struct V_18 * V_19 = F_43 ( V_14 ) ;
F_198 ( V_321 , V_19 , V_14 , & V_14 -> V_9 ) ;
}
static int
F_14 ( struct V_18 * V_19 , struct V_20 * V_21 )
{
struct V_8 * V_9 = & V_19 -> V_173 ;
struct V_114 * V_3 = F_44 ( V_19 -> V_115 ) ;
struct V_335 * V_321 ;
int V_78 ;
char V_366 [ 20 ] ;
V_21 -> V_64 = NULL ;
if ( ! V_3 -> V_122 -> V_354 )
return - V_367 ;
snprintf ( V_366 , sizeof( V_366 ) ,
L_48 , V_19 -> V_57 ) ;
V_321 = F_204 ( V_19 , F_202 ) ;
if ( ! V_321 ) {
F_30 ( V_237 L_49
L_50 ,
V_19 -> V_57 ) ;
return - V_59 ;
}
V_321 -> V_365 = V_19 ;
F_205 ( V_368 , V_321 ) ;
F_206 ( V_321 , F_186 ) ;
F_207 ( V_321 , F_188 ) ;
F_208 ( V_321 , V_369 ) ;
V_78 = F_209 ( V_321 , V_9 , V_366 , NULL ) ;
if ( V_78 ) {
F_30 ( V_237 L_49
L_51 ,
V_19 -> V_57 ) ;
F_210 ( V_321 ) ;
return V_78 ;
}
V_21 -> V_64 = V_321 ;
return 0 ;
}
static int
F_165 ( struct V_18 * V_19 , struct V_13 * V_14 )
{
struct V_8 * V_9 = & V_14 -> V_9 ;
struct V_114 * V_3 = F_44 ( V_19 -> V_115 ) ;
struct V_335 * V_321 ;
int V_78 ;
V_14 -> V_64 = NULL ;
if ( ! V_3 -> V_122 -> V_354 )
return - V_367 ;
V_321 = F_204 ( V_19 , F_203 ) ;
if ( ! V_321 ) {
F_30 ( V_237 L_52
L_50 ,
V_9 -> V_287 . V_76 ) ;
return - V_59 ;
}
V_321 -> V_365 = V_14 ;
F_205 ( V_368 , V_321 ) ;
F_206 ( V_321 , F_186 ) ;
F_207 ( V_321 , F_188 ) ;
F_208 ( V_321 , V_370 ) ;
V_78 = F_209 ( V_321 , V_9 , NULL , NULL ) ;
if ( V_78 ) {
F_30 ( V_237 L_52
L_51 ,
V_9 -> V_287 . V_76 ) ;
F_210 ( V_321 ) ;
return V_78 ;
}
V_14 -> V_64 = V_321 ;
return 0 ;
}
static void
F_16 ( struct V_335 * V_321 )
{
struct V_297 * V_298 ;
int V_371 ;
if ( V_321 ) {
F_201 ( V_321 -> V_363 ) ;
F_211 ( V_321 ) ;
while ( 1 ) {
V_298 = F_199 ( V_321 ) ;
V_371 = V_321 -> V_308 . V_124 [ 0 ] + V_321 -> V_308 . V_124 [ 1 ] +
V_321 -> V_308 . V_372 [ 0 ] + V_321 -> V_308 . V_372 [ 1 ] ;
F_200 ( V_321 -> V_363 ) ;
if ( V_371 == 0 )
break;
if ( V_298 ) {
V_298 -> V_301 = - V_362 ;
F_187 ( V_298 , - V_362 ) ;
}
F_177 ( 200 ) ;
F_201 ( V_321 -> V_363 ) ;
}
F_212 ( V_321 ) ;
F_210 ( V_321 ) ;
}
}
