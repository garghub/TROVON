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
V_21 -> V_17 = - 1 ;
V_21 -> V_31 = V_32 ;
V_21 -> V_33 = V_34 ;
memset ( V_21 -> V_35 , 0 ,
sizeof( V_21 -> V_35 ) ) ;
V_21 -> V_36 = V_27 ;
V_21 -> V_37 = - 1 ;
memset ( V_21 -> V_38 , 0 , sizeof( V_21 -> V_38 ) ) ;
memset ( V_21 -> V_39 , 0 , sizeof( V_21 -> V_39 ) ) ;
V_21 -> V_40 = V_41 ;
F_11 ( & V_21 -> V_42 ) ;
F_11 ( & V_21 -> V_43 ) ;
F_11 ( & V_21 -> V_44 ) ;
V_21 -> V_45 = 0 ;
V_21 -> V_46 = 0 ;
V_21 -> V_47 = 0 ;
V_21 -> V_48 = 0 ;
snprintf ( V_21 -> V_49 , sizeof( V_21 -> V_49 ) ,
L_3 , V_19 -> V_50 ) ;
V_21 -> V_51 = F_12 ( V_21 -> V_49 , 0 , 0 ) ;
if ( ! V_21 -> V_51 )
return - V_52 ;
V_21 -> V_53 = V_54 ;
snprintf ( V_21 -> V_55 ,
sizeof( V_21 -> V_55 ) ,
L_4 , V_19 -> V_50 ) ;
V_21 -> V_56 =
F_12 ( V_21 -> V_55 , 0 , 0 ) ;
if ( ! V_21 -> V_56 ) {
F_13 ( V_21 -> V_51 ) ;
V_21 -> V_51 = NULL ;
return - V_52 ;
}
F_14 ( V_19 , V_21 ) ;
return 0 ;
}
static int F_15 ( struct V_6 * V_7 , struct V_8 * V_9 ,
struct V_8 * V_10 )
{
struct V_18 * V_19 = F_9 ( V_9 ) ;
struct V_20 * V_21 = F_10 ( V_19 ) ;
F_16 ( V_21 -> V_57 ) ;
return 0 ;
}
T_2
F_17 ( void )
{
return F_18 ( 1 , & V_58 ) ;
}
void
F_19 ( struct V_18 * V_19 , T_2 V_59 ,
enum V_60 V_61 , T_2 V_62 )
{
struct V_63 * V_64 ;
struct V_65 * V_66 ;
struct V_67 * V_68 ;
const char * V_69 ;
T_2 V_4 , V_70 ;
int V_71 ;
if ( ! V_72 ) {
V_71 = - V_73 ;
goto V_74;
}
V_4 = F_20 ( sizeof( * V_68 ) ) ;
V_70 = F_21 ( V_4 ) ;
V_64 = F_22 ( V_70 , V_75 ) ;
if ( ! V_64 ) {
V_71 = - V_76 ;
goto V_74;
}
V_66 = F_23 ( V_64 , 0 , 0 , V_77 ,
V_70 - sizeof( * V_66 ) , 0 ) ;
if ( ! V_66 ) {
V_71 = - V_76 ;
goto V_78;
}
V_68 = F_24 ( V_66 ) ;
F_25 ( & V_68 -> V_79 , V_80 ,
V_81 , V_4 ) ;
V_68 -> V_82 = F_26 () ;
V_68 -> V_83 = 0 ;
V_68 -> V_50 = V_19 -> V_50 ;
V_68 -> V_84 = sizeof( T_2 ) ;
V_68 -> V_85 = V_59 ;
V_68 -> V_61 = V_61 ;
V_68 -> V_62 = V_62 ;
F_27 ( V_72 , V_64 , 0 , V_86 ,
V_75 ) ;
return;
V_78:
F_28 ( V_64 ) ;
V_74:
V_69 = F_29 ( V_61 ) ;
F_30 ( V_87
L_5 ,
V_88 , V_19 -> V_50 ,
( V_69 ) ? V_69 : L_6 , V_62 , V_71 ) ;
return;
}
void
F_31 ( struct V_18 * V_19 , T_2 V_59 ,
T_2 V_89 , char * V_90 , T_3 V_83 )
{
struct V_63 * V_64 ;
struct V_65 * V_66 ;
struct V_67 * V_68 ;
T_2 V_4 , V_70 ;
int V_71 ;
if ( ! V_72 ) {
V_71 = - V_73 ;
goto V_91;
}
V_4 = F_20 ( sizeof( * V_68 ) + V_89 ) ;
V_70 = F_21 ( V_4 ) ;
V_64 = F_22 ( V_70 , V_75 ) ;
if ( ! V_64 ) {
V_71 = - V_76 ;
goto V_91;
}
V_66 = F_23 ( V_64 , 0 , 0 , V_77 ,
V_70 - sizeof( * V_66 ) , 0 ) ;
if ( ! V_66 ) {
V_71 = - V_76 ;
goto V_92;
}
V_68 = F_24 ( V_66 ) ;
F_25 ( & V_68 -> V_79 , V_80 ,
V_81 , V_4 ) ;
V_68 -> V_82 = F_26 () ;
V_68 -> V_83 = V_83 ;
V_68 -> V_50 = V_19 -> V_50 ;
V_68 -> V_84 = V_89 ;
V_68 -> V_85 = V_59 ;
V_68 -> V_61 = V_93 ;
memcpy ( & V_68 -> V_62 , V_90 , V_89 ) ;
F_27 ( V_72 , V_64 , 0 , V_86 ,
V_75 ) ;
return;
V_92:
F_28 ( V_64 ) ;
V_91:
F_30 ( V_87
L_7 ,
V_88 , V_19 -> V_50 , V_71 ) ;
return;
}
static T_4 int F_32 ( void )
{
int error ;
F_33 ( & V_58 , 0 ) ;
error = F_34 ( & V_94 ) ;
if ( error )
return error ;
error = F_34 ( & V_95 ) ;
if ( error )
goto V_96;
error = F_34 ( & V_97 ) ;
if ( error )
goto V_98;
error = F_34 ( & V_99 ) ;
if ( error )
goto V_100;
return 0 ;
V_100:
F_35 ( & V_97 ) ;
V_98:
F_35 ( & V_95 ) ;
V_96:
F_35 ( & V_94 ) ;
return error ;
}
static void T_5 F_36 ( void )
{
F_35 ( & V_99 ) ;
F_35 ( & V_97 ) ;
F_35 ( & V_94 ) ;
F_35 ( & V_95 ) ;
}
static T_6
F_37 ( struct V_8 * V_9 ,
struct V_101 * V_102 , char * V_1 )
{
struct V_13 * V_14 = F_38 ( V_9 ) ;
if ( V_14 -> V_23 == V_24 )
return snprintf ( V_1 , 20 , L_8 ) ;
return F_39 ( V_14 -> V_23 , V_1 ) ;
}
static int F_40 ( const char * V_1 , unsigned long * V_103 )
{
char * V_104 ;
* V_103 = F_41 ( V_1 , & V_104 , 0 ) ;
if ( ( * V_104 && ( * V_104 != '\n' ) ) || ( * V_103 < 0 ) )
return - V_105 ;
if ( * V_103 > V_106 )
return - V_105 ;
return 0 ;
}
static int F_42 ( struct V_13 * V_14 ,
unsigned long V_103 )
{
struct V_18 * V_19 = F_43 ( V_14 ) ;
struct V_107 * V_3 = F_44 ( V_19 -> V_108 ) ;
if ( ( V_14 -> V_33 == V_109 ) ||
( V_14 -> V_33 == V_110 ) ||
( V_14 -> V_33 == V_111 ) )
return - V_112 ;
if ( V_103 > V_106 )
return - V_105 ;
if ( V_14 -> V_113 == - 1 &&
V_103 > V_114 )
return - V_105 ;
V_3 -> V_115 -> V_116 ( V_14 , V_103 ) ;
return 0 ;
}
static T_6
F_45 ( struct V_8 * V_9 , struct V_101 * V_102 ,
const char * V_1 , T_7 V_117 )
{
struct V_13 * V_14 = F_38 ( V_9 ) ;
unsigned long V_103 ;
int V_118 ;
V_118 = F_40 ( V_1 , & V_103 ) ;
if ( V_118 )
return V_118 ;
V_118 = F_42 ( V_14 , V_103 ) ;
if ( V_118 )
return V_118 ;
return V_117 ;
}
static T_6
F_46 ( struct V_8 * V_9 , struct V_101 * V_102 ,
char * V_1 )
{
struct V_13 * V_14 = F_38 ( V_9 ) ;
if ( ( V_14 -> V_17 != - 1 ) &&
( V_14 -> V_17 & V_119 ) ==
V_119 ) {
switch ( V_14 -> V_17 & V_120 ) {
case V_121 :
return snprintf ( V_1 , 30 , L_9 ) ;
case V_122 :
return snprintf ( V_1 , 30 , L_10 ) ;
case V_123 :
return snprintf ( V_1 , 30 , L_11 ) ;
case V_124 :
return snprintf ( V_1 , 30 , L_12 ) ;
case V_125 :
return snprintf ( V_1 , 30 , L_13 ) ;
default:
return snprintf ( V_1 , 30 , L_14 ) ;
}
} else {
if ( V_14 -> V_126 == V_127 )
return snprintf ( V_1 , 20 , L_15 ) ;
return F_47 ( V_14 -> V_126 , V_1 ) ;
}
}
static T_6
F_48 ( struct V_8 * V_9 ,
struct V_101 * V_102 , char * V_1 )
{
struct V_13 * V_14 = F_38 ( V_9 ) ;
if ( V_14 -> V_113 == - 1 )
return snprintf ( V_1 , 5 , L_16 ) ;
return snprintf ( V_1 , 20 , L_17 , V_14 -> V_113 ) ;
}
static T_6
F_49 ( struct V_8 * V_9 ,
struct V_101 * V_102 , const char * V_1 ,
T_7 V_117 )
{
int V_103 ;
char * V_104 ;
struct V_13 * V_14 = F_38 ( V_9 ) ;
if ( ( V_14 -> V_33 == V_109 ) ||
( V_14 -> V_33 == V_110 ) ||
( V_14 -> V_33 == V_111 ) )
return - V_112 ;
if ( strncmp ( V_1 , L_18 , 3 ) == 0 )
V_14 -> V_113 = - 1 ;
else {
V_103 = F_41 ( V_1 , & V_104 , 0 ) ;
if ( ( * V_104 && ( * V_104 != '\n' ) ) || ( V_103 < 0 ) )
return - V_105 ;
if ( ( V_103 >= V_14 -> V_53 ) ||
( V_103 > V_114 ) )
return - V_105 ;
V_14 -> V_113 = V_103 ;
}
return V_117 ;
}
static T_6
F_50 ( struct V_8 * V_9 , struct V_101 * V_102 ,
char * V_1 )
{
struct V_128 * V_129 = F_51 ( V_9 ) ;
if ( V_129 -> V_126 == V_127 )
return snprintf ( V_1 , 20 , L_15 ) ;
return F_47 ( V_129 -> V_126 , V_1 ) ;
}
static T_6
F_52 ( struct V_8 * V_9 , struct V_101 * V_102 ,
const char * V_1 , T_7 V_117 )
{
struct V_128 * V_129 = F_51 ( V_9 ) ;
struct V_18 * V_19 = F_53 ( V_129 ) ;
unsigned long V_130 ;
F_54 ( V_19 -> V_131 , V_130 ) ;
if ( V_129 -> V_130 & ( V_132 | V_133 ) ) {
F_55 ( V_19 -> V_131 , V_130 ) ;
return - V_112 ;
}
V_129 -> V_130 |= V_134 ;
F_55 ( V_19 -> V_131 , V_130 ) ;
F_56 ( V_19 , & V_129 -> V_135 ) ;
return V_117 ;
}
static T_6
F_57 ( struct V_8 * V_9 , struct V_101 * V_102 ,
const char * V_1 ,
T_7 V_117 )
{
struct V_128 * V_129 = F_51 ( V_9 ) ;
struct V_18 * V_19 = F_53 ( V_129 ) ;
struct V_107 * V_3 = F_44 ( V_19 -> V_108 ) ;
int V_136 ;
if ( V_129 -> V_130 & ( V_132 | V_133 ) )
return - V_112 ;
if ( * V_1 == '0' ) {
if ( V_129 -> V_137 != V_138 )
return - V_139 ;
} else if ( * V_1 == '1' ) {
if ( V_129 -> V_137 == V_138 )
return - V_139 ;
} else
return - V_105 ;
V_136 = V_3 -> V_115 -> V_140 ( V_129 , ( ( * V_1 == '0' ) ? false : true ) ) ;
return V_136 ? V_136 : V_117 ;
}
static T_6
F_58 ( struct V_8 * V_9 ,
struct V_101 * V_102 , char * V_1 )
{
struct V_18 * V_19 = F_59 ( V_9 ) ;
if ( F_60 ( V_19 ) == V_24 )
return snprintf ( V_1 , 20 , L_8 ) ;
return F_39 ( F_60 ( V_19 ) , V_1 ) ;
}
static T_6
F_61 ( struct V_8 * V_9 ,
struct V_101 * V_102 , char * V_1 )
{
struct V_18 * V_19 = F_59 ( V_9 ) ;
return ( T_6 ) F_1 ( V_1 , F_62 ( V_19 ) ) ;
}
static T_6
F_63 ( struct V_8 * V_9 ,
struct V_101 * V_102 , char * V_1 )
{
struct V_18 * V_19 = F_59 ( V_9 ) ;
if ( F_64 ( V_19 ) == V_27 )
return snprintf ( V_1 , 20 , L_15 ) ;
return F_65 ( F_64 ( V_19 ) , V_1 ) ;
}
static T_6
F_66 ( struct V_8 * V_9 ,
struct V_101 * V_102 , char * V_1 )
{
struct V_18 * V_19 = F_59 ( V_9 ) ;
struct V_107 * V_3 = F_44 ( V_19 -> V_108 ) ;
if ( V_3 -> V_115 -> V_141 )
V_3 -> V_115 -> V_141 ( V_19 ) ;
return ( T_6 ) F_1 ( V_1 , F_67 ( V_19 ) ) ;
}
static T_6
F_68 ( struct V_8 * V_9 ,
struct V_101 * V_102 , char * V_1 )
{
struct V_18 * V_19 = F_59 ( V_9 ) ;
struct V_107 * V_3 = F_44 ( V_19 -> V_108 ) ;
if ( V_3 -> V_115 -> V_142 )
V_3 -> V_115 -> V_142 ( V_19 ) ;
if ( F_69 ( V_19 ) == V_27 )
return snprintf ( V_1 , 20 , L_15 ) ;
return F_65 ( F_69 ( V_19 ) , V_1 ) ;
}
static T_6
F_70 ( struct V_8 * V_9 ,
struct V_101 * V_102 , char * V_1 )
{
struct V_18 * V_19 = F_59 ( V_9 ) ;
const char * V_69 ;
V_69 = F_71 ( F_72 ( V_19 ) ) ;
if ( ! V_69 )
return - V_105 ;
return snprintf ( V_1 , V_143 , L_19 , V_69 ) ;
}
static T_6
F_73 ( struct V_8 * V_9 ,
struct V_101 * V_102 , const char * V_1 , T_7 V_117 )
{
struct V_18 * V_19 = F_59 ( V_9 ) ;
struct V_13 * V_14 ;
enum V_144 V_103 ;
unsigned long V_130 ;
if ( F_74 ( V_1 , & V_103 ) )
return - V_105 ;
if ( V_103 != F_72 ( V_19 ) ) {
F_54 ( V_19 -> V_131 , V_130 ) ;
while ( ! F_75 ( & F_76 ( V_19 ) ) ) {
F_77 ( V_14 ,
& F_76 ( V_19 ) , V_145 ) ;
F_78 ( & V_14 -> V_145 ) ;
V_14 -> V_33 = V_110 ;
F_56 ( V_19 , & V_14 -> V_146 ) ;
}
F_55 ( V_19 -> V_131 , V_130 ) ;
}
F_72 ( V_19 ) = V_103 ;
return V_117 ;
}
static T_6
F_79 ( struct V_8 * V_9 ,
struct V_101 * V_102 , const char * V_1 , T_7 V_117 )
{
struct V_18 * V_19 = F_59 ( V_9 ) ;
struct V_107 * V_3 = F_44 ( V_19 -> V_108 ) ;
int V_147 ;
if ( V_3 -> V_115 -> V_148 ) {
V_147 = V_3 -> V_115 -> V_148 ( V_19 ) ;
return V_147 ? V_147 : V_117 ;
}
return - V_73 ;
}
static T_6
F_80 ( struct V_8 * V_9 ,
struct V_101 * V_102 ,
const char * V_1 , T_7 V_117 )
{
struct V_18 * V_19 = F_59 ( V_9 ) ;
struct V_20 * V_21 = F_10 ( V_19 ) ;
struct V_13 * V_14 ;
unsigned long V_103 , V_130 ;
int V_118 ;
V_118 = F_40 ( V_1 , & V_103 ) ;
if ( V_118 )
return V_118 ;
F_81 ( V_19 ) = V_103 ;
F_54 ( V_19 -> V_131 , V_130 ) ;
F_82 (rport, &fc_host->rports, peers)
F_42 ( V_14 , V_103 ) ;
F_55 ( V_19 -> V_131 , V_130 ) ;
return V_117 ;
}
static T_6
F_83 ( const struct V_8 * V_9 , char * V_1 , unsigned long V_149 )
{
struct V_18 * V_19 = F_59 ( V_9 ) ;
struct V_107 * V_3 = F_44 ( V_19 -> V_108 ) ;
struct V_150 * V_151 ;
T_6 V_147 = - V_73 ;
if ( V_149 > sizeof( struct V_150 ) ||
V_149 % sizeof( T_3 ) != 0 )
F_84 ( 1 ) ;
if ( V_3 -> V_115 -> V_152 ) {
V_151 = ( V_3 -> V_115 -> V_152 ) ( V_19 ) ;
if ( V_151 )
V_147 = snprintf ( V_1 , 20 , L_20 ,
( unsigned long long ) * ( T_3 * ) ( ( ( T_1 * ) V_151 ) + V_149 ) ) ;
}
return V_147 ;
}
static T_6
F_85 ( struct V_8 * V_9 , struct V_101 * V_102 ,
const char * V_1 , T_7 V_117 )
{
struct V_18 * V_19 = F_59 ( V_9 ) ;
struct V_107 * V_3 = F_44 ( V_19 -> V_108 ) ;
if ( V_3 -> V_115 -> V_153 ) {
V_3 -> V_115 -> V_153 ( V_19 ) ;
return V_117 ;
}
return - V_73 ;
}
static int
F_86 ( const char * V_154 , T_3 * V_155 )
{
unsigned int V_3 , V_156 ;
T_1 V_157 [ 8 ] ;
memset ( V_157 , 0 , sizeof( V_157 ) ) ;
for ( V_3 = 0 , V_156 = 0 ; V_3 < 16 ; V_3 ++ ) {
int V_158 ;
V_158 = F_87 ( * V_154 ++ ) ;
if ( V_158 >= 0 )
V_156 = ( V_156 << 4 ) | V_158 ;
else
return - V_105 ;
if ( V_3 % 2 ) {
V_157 [ V_3 / 2 ] = V_156 & 0xff ;
V_156 = 0 ;
}
}
* V_155 = F_88 ( V_157 ) ;
return 0 ;
}
static T_6
F_89 ( struct V_8 * V_9 , struct V_101 * V_102 ,
const char * V_1 , T_7 V_117 )
{
struct V_18 * V_19 = F_59 ( V_9 ) ;
struct V_159 V_160 ;
struct V_128 * V_129 ;
unsigned int V_161 = V_117 ;
int V_136 ;
memset ( & V_160 , 0 , sizeof( V_160 ) ) ;
if ( V_1 [ V_161 - 1 ] == '\n' )
V_161 -- ;
if ( ( V_161 != ( 16 + 1 + 16 ) ) || ( V_1 [ 16 ] != ':' ) )
return - V_105 ;
V_136 = F_86 ( & V_1 [ 0 ] , & V_160 . V_16 ) ;
if ( V_136 )
return V_136 ;
V_136 = F_86 ( & V_1 [ 17 ] , & V_160 . V_15 ) ;
if ( V_136 )
return V_136 ;
V_160 . V_126 = V_162 ;
V_160 . V_163 = V_164 ;
V_160 . V_165 = false ;
V_136 = F_90 ( V_19 , 0 , & V_19 -> V_166 , & V_160 , & V_129 ) ;
return V_136 ? V_136 : V_117 ;
}
static T_6
F_91 ( struct V_8 * V_9 , struct V_101 * V_102 ,
const char * V_1 , T_7 V_117 )
{
struct V_18 * V_19 = F_59 ( V_9 ) ;
struct V_20 * V_21 = F_10 ( V_19 ) ;
struct V_128 * V_129 ;
T_3 V_167 , V_168 ;
unsigned long V_130 ;
unsigned int V_161 = V_117 ;
int V_136 , V_169 ;
if ( V_1 [ V_161 - 1 ] == '\n' )
V_161 -- ;
if ( ( V_161 != ( 16 + 1 + 16 ) ) || ( V_1 [ 16 ] != ':' ) )
return - V_105 ;
V_136 = F_86 ( & V_1 [ 0 ] , & V_167 ) ;
if ( V_136 )
return V_136 ;
V_136 = F_86 ( & V_1 [ 17 ] , & V_168 ) ;
if ( V_136 )
return V_136 ;
F_54 ( V_19 -> V_131 , V_130 ) ;
V_169 = 0 ;
F_82 (vport, &fc_host->vports, peers) {
if ( ( V_129 -> V_170 == 0 ) &&
( V_129 -> V_16 == V_167 ) && ( V_129 -> V_15 == V_168 ) ) {
if ( V_129 -> V_130 & ( V_132 | V_133 ) )
break;
V_129 -> V_130 |= V_134 ;
V_169 = 1 ;
break;
}
}
F_55 ( V_19 -> V_131 , V_130 ) ;
if ( ! V_169 )
return - V_171 ;
V_136 = F_92 ( V_129 ) ;
return V_136 ? V_136 : V_117 ;
}
static int F_93 ( struct V_172 * V_173 ,
struct V_8 * V_9 )
{
struct V_18 * V_19 ;
struct V_107 * V_3 ;
if ( ! F_94 ( V_9 ) )
return 0 ;
V_19 = F_9 ( V_9 ) ;
if ( ! V_19 -> V_108 || V_19 -> V_108 -> V_174 . V_175 . V_176
!= & V_94 . V_176 )
return 0 ;
V_3 = F_44 ( V_19 -> V_108 ) ;
return & V_3 -> V_177 . V_174 . V_175 == V_173 ;
}
static int F_95 ( struct V_172 * V_173 ,
struct V_8 * V_9 )
{
struct V_18 * V_19 ;
struct V_107 * V_3 ;
if ( ! F_96 ( V_9 ) )
return 0 ;
V_19 = F_9 ( V_9 -> V_178 ) ;
if ( ! V_19 -> V_108 || V_19 -> V_108 -> V_174 . V_175 . V_176
!= & V_94 . V_176 )
return 0 ;
V_3 = F_44 ( V_19 -> V_108 ) ;
return & V_3 -> V_177 . V_179 . V_175 == V_173 ;
}
static void F_97 ( struct V_8 * V_9 )
{
struct V_13 * V_14 = F_98 ( V_9 ) ;
F_99 ( V_9 -> V_178 ) ;
F_100 ( V_14 ) ;
}
int F_101 ( const struct V_8 * V_9 )
{
return V_9 -> V_180 == F_97 ;
}
static int F_102 ( struct V_172 * V_173 ,
struct V_8 * V_9 )
{
struct V_18 * V_19 ;
struct V_107 * V_3 ;
if ( ! F_101 ( V_9 ) )
return 0 ;
V_19 = F_9 ( V_9 -> V_178 ) ;
if ( ! V_19 -> V_108 || V_19 -> V_108 -> V_174 . V_175 . V_176
!= & V_94 . V_176 )
return 0 ;
V_3 = F_44 ( V_19 -> V_108 ) ;
return & V_3 -> V_181 . V_175 == V_173 ;
}
static void F_103 ( struct V_8 * V_9 )
{
struct V_128 * V_129 = F_104 ( V_9 ) ;
F_99 ( V_9 -> V_178 ) ;
F_100 ( V_129 ) ;
}
int F_105 ( const struct V_8 * V_9 )
{
return V_9 -> V_180 == F_103 ;
}
static int F_106 ( struct V_172 * V_173 ,
struct V_8 * V_9 )
{
struct V_128 * V_129 ;
struct V_18 * V_19 ;
struct V_107 * V_3 ;
if ( ! F_105 ( V_9 ) )
return 0 ;
V_129 = F_104 ( V_9 ) ;
V_19 = F_53 ( V_129 ) ;
if ( ! V_19 -> V_108 || V_19 -> V_108 -> V_174 . V_175 . V_176
!= & V_94 . V_176 )
return 0 ;
V_3 = F_44 ( V_19 -> V_108 ) ;
return & V_3 -> V_182 . V_175 == V_173 ;
}
static enum V_183
F_107 ( struct V_184 * V_185 )
{
struct V_13 * V_14 = F_4 ( V_11 ( V_185 -> V_8 ) ) ;
if ( V_14 -> V_33 == V_109 )
return V_186 ;
return V_187 ;
}
static void
F_108 ( struct V_18 * V_19 , T_8 V_170 , T_8 V_188 , T_8 V_189 )
{
struct V_13 * V_14 ;
unsigned long V_130 ;
F_54 ( V_19 -> V_131 , V_130 ) ;
F_82 (rport, &fc_host_rports(shost), peers) {
if ( V_14 -> V_190 == - 1 )
continue;
if ( V_14 -> V_33 != V_191 )
continue;
if ( ( V_170 == V_14 -> V_170 ) &&
( V_188 == V_14 -> V_190 ) ) {
F_55 ( V_19 -> V_131 , V_130 ) ;
F_109 ( & V_14 -> V_9 , V_170 , V_188 , V_189 , 1 ) ;
return;
}
}
F_55 ( V_19 -> V_131 , V_130 ) ;
}
static int
F_110 ( struct V_18 * V_19 , T_8 V_170 , T_8 V_188 , T_8 V_189 )
{
T_8 V_192 , V_193 ;
T_8 V_194 , V_195 ;
if ( ( ( V_170 != V_196 ) && ( V_170 > V_19 -> V_197 ) ) ||
( ( V_188 != V_196 ) && ( V_188 >= V_19 -> V_198 ) ) ||
( ( V_189 != V_196 ) && ( V_189 > V_19 -> V_199 ) ) )
return - V_105 ;
if ( V_170 == V_196 ) {
V_192 = 0 ;
V_193 = V_19 -> V_197 + 1 ;
} else {
V_192 = V_170 ;
V_193 = V_170 + 1 ;
}
if ( V_188 == V_196 ) {
V_194 = 0 ;
V_195 = V_19 -> V_198 ;
} else {
V_194 = V_188 ;
V_195 = V_188 + 1 ;
}
for ( ; V_192 < V_193 ; V_192 ++ )
for ( ; V_194 < V_195 ; V_194 ++ )
F_108 ( V_19 , V_192 , V_194 , V_189 ) ;
return 0 ;
}
static int F_111 ( struct V_18 * V_19 , T_3 V_200 , T_3 V_201 ,
int V_202 )
{
struct V_107 * V_3 = F_44 ( V_19 -> V_108 ) ;
return V_3 -> V_115 -> V_203 ( V_19 , V_200 , V_201 , V_202 ) ;
}
static int F_112 ( struct V_18 * V_19 , T_3 V_200 , int V_202 )
{
struct V_107 * V_3 = F_44 ( V_19 -> V_108 ) ;
return V_3 -> V_115 -> V_204 ( V_19 , V_200 , V_202 ) ;
}
struct V_205 *
F_113 ( struct V_206 * V_207 )
{
int V_117 ;
struct V_107 * V_3 = F_114 ( sizeof( struct V_107 ) ,
V_75 ) ;
if ( F_115 ( ! V_3 ) )
return NULL ;
V_3 -> V_177 . V_179 . V_175 . V_208 = & V_3 -> V_209 [ 0 ] ;
V_3 -> V_177 . V_179 . V_175 . V_176 = & V_99 . V_176 ;
V_3 -> V_177 . V_179 . V_175 . V_169 = F_95 ;
V_3 -> V_177 . V_210 = sizeof( struct V_211 ) ;
F_116 ( & V_3 -> V_177 . V_179 ) ;
V_3 -> V_177 . V_174 . V_175 . V_208 = & V_3 -> V_174 [ 0 ] ;
V_3 -> V_177 . V_174 . V_175 . V_176 = & V_94 . V_176 ;
V_3 -> V_177 . V_174 . V_175 . V_169 = F_93 ;
V_3 -> V_177 . V_212 = sizeof( struct V_20 ) ;
if ( V_207 -> V_152 )
V_3 -> V_177 . V_174 . V_213 = & V_214 ;
F_116 ( & V_3 -> V_177 . V_174 ) ;
V_3 -> V_181 . V_175 . V_208 = & V_3 -> V_215 [ 0 ] ;
V_3 -> V_181 . V_175 . V_176 = & V_97 . V_176 ;
V_3 -> V_181 . V_175 . V_169 = F_102 ;
F_116 ( & V_3 -> V_181 ) ;
V_3 -> V_182 . V_175 . V_208 = & V_3 -> V_216 [ 0 ] ;
V_3 -> V_182 . V_175 . V_176 = & V_95 . V_176 ;
V_3 -> V_182 . V_175 . V_169 = F_106 ;
F_116 ( & V_3 -> V_182 ) ;
V_3 -> V_115 = V_207 ;
V_3 -> V_177 . V_217 = 1 ;
V_3 -> V_177 . V_218 = F_107 ;
V_3 -> V_177 . V_219 = F_110 ;
V_3 -> V_177 . V_203 = F_111 ;
V_3 -> V_177 . V_204 = F_112 ;
V_117 = 0 ;
F_117 ( V_15 ) ;
F_117 ( V_16 ) ;
F_117 ( V_17 ) ;
F_118 ( V_117 > V_220 ) ;
V_3 -> V_209 [ V_117 ] = NULL ;
V_117 = 0 ;
F_119 ( V_15 ) ;
F_119 ( V_16 ) ;
F_119 ( V_22 ) ;
F_119 ( V_23 ) ;
F_119 ( V_25 ) ;
F_119 ( V_26 ) ;
F_119 ( V_28 ) ;
if ( V_207 -> V_221 ) {
F_120 ( V_29 ) ;
F_120 ( V_48 ) ;
}
F_119 ( V_30 ) ;
F_119 ( V_17 ) ;
F_119 ( V_31 ) ;
F_119 ( V_33 ) ;
F_119 ( V_35 ) ;
F_119 ( V_36 ) ;
F_119 ( V_37 ) ;
F_119 ( V_38 ) ;
F_121 ( V_39 ) ;
F_122 ( V_53 ) ;
F_122 ( V_40 ) ;
if ( V_207 -> V_148 )
F_122 ( V_222 ) ;
if ( V_207 -> V_221 )
F_122 ( V_221 ) ;
if ( V_207 -> V_223 )
F_122 ( V_223 ) ;
F_118 ( V_117 > V_224 ) ;
V_3 -> V_174 [ V_117 ] = NULL ;
V_117 = 0 ;
F_123 ( V_28 ) ;
F_123 ( V_23 ) ;
F_124 ( V_53 ) ;
F_125 ( V_15 ) ;
F_125 ( V_16 ) ;
F_125 ( V_17 ) ;
F_125 ( V_126 ) ;
F_125 ( V_33 ) ;
F_125 ( V_190 ) ;
F_126 ( V_113 ) ;
F_118 ( V_117 > V_225 ) ;
V_3 -> V_215 [ V_117 ] = NULL ;
V_117 = 0 ;
F_127 ( V_137 ) ;
F_127 ( V_226 ) ;
F_127 ( V_15 ) ;
F_127 ( V_16 ) ;
F_127 ( V_126 ) ;
F_127 ( V_163 ) ;
F_128 ( V_38 ) ;
F_129 ( V_223 ) ;
F_129 ( V_140 ) ;
F_118 ( V_117 > V_227 ) ;
V_3 -> V_216 [ V_117 ] = NULL ;
return & V_3 -> V_177 ;
}
void F_130 ( struct V_205 * V_177 )
{
struct V_107 * V_3 = F_44 ( V_177 ) ;
F_131 ( & V_3 -> V_177 . V_179 ) ;
F_131 ( & V_3 -> V_177 . V_174 ) ;
F_131 ( & V_3 -> V_181 ) ;
F_131 ( & V_3 -> V_182 ) ;
F_100 ( V_3 ) ;
}
static int
F_56 ( struct V_18 * V_19 , struct V_228 * V_229 )
{
if ( F_115 ( ! F_132 ( V_19 ) ) ) {
F_30 ( V_230
L_21
L_22 , V_19 -> V_231 -> V_69 ) ;
F_133 () ;
return - V_105 ;
}
return F_134 ( F_132 ( V_19 ) , V_229 ) ;
}
static void
F_135 ( struct V_18 * V_19 )
{
if ( ! F_132 ( V_19 ) ) {
F_30 ( V_230
L_23
L_22 , V_19 -> V_231 -> V_69 ) ;
F_133 () ;
return;
}
F_136 ( F_132 ( V_19 ) ) ;
}
static int
F_137 ( struct V_18 * V_19 , struct V_232 * V_229 ,
unsigned long V_233 )
{
if ( F_115 ( ! F_138 ( V_19 ) ) ) {
F_30 ( V_230
L_21
L_22 , V_19 -> V_231 -> V_69 ) ;
F_133 () ;
return - V_105 ;
}
return F_139 ( F_138 ( V_19 ) , V_229 , V_233 ) ;
}
static void
F_140 ( struct V_18 * V_19 )
{
if ( ! F_138 ( V_19 ) ) {
F_30 ( V_230
L_23
L_22 , V_19 -> V_231 -> V_69 ) ;
F_133 () ;
return;
}
F_136 ( F_138 ( V_19 ) ) ;
}
void
F_141 ( struct V_18 * V_19 )
{
struct V_128 * V_129 = NULL , * V_234 = NULL ;
struct V_13 * V_14 = NULL , * V_235 = NULL ;
struct V_236 * V_51 ;
struct V_20 * V_21 = F_10 ( V_19 ) ;
unsigned long V_130 ;
F_54 ( V_19 -> V_131 , V_130 ) ;
F_142 (vport, next_vport, &fc_host->vports, peers)
F_56 ( V_19 , & V_129 -> V_135 ) ;
F_142 (rport, next_rport,
&fc_host->rports, peers) {
F_78 ( & V_14 -> V_145 ) ;
V_14 -> V_33 = V_110 ;
F_56 ( V_19 , & V_14 -> V_146 ) ;
}
F_142 (rport, next_rport,
&fc_host->rport_bindings, peers) {
F_78 ( & V_14 -> V_145 ) ;
V_14 -> V_33 = V_110 ;
F_56 ( V_19 , & V_14 -> V_146 ) ;
}
F_55 ( V_19 -> V_131 , V_130 ) ;
F_143 ( V_19 ) ;
if ( V_21 -> V_51 ) {
V_51 = V_21 -> V_51 ;
V_21 -> V_51 = NULL ;
F_13 ( V_51 ) ;
}
if ( V_21 -> V_56 ) {
V_51 = V_21 -> V_56 ;
V_21 -> V_56 = NULL ;
F_13 ( V_51 ) ;
}
}
static void F_144 ( struct V_13 * V_14 )
{
struct V_18 * V_19 = F_43 ( V_14 ) ;
struct V_107 * V_3 = F_44 ( V_19 -> V_108 ) ;
if ( V_3 -> V_115 -> V_237 )
V_3 -> V_115 -> V_237 ( V_14 ) ;
F_145 ( & V_14 -> V_9 ) ;
}
static void
F_146 ( struct V_228 * V_229 )
{
struct V_13 * V_14 =
F_147 ( V_229 , struct V_13 , V_238 ) ;
F_144 ( V_14 ) ;
F_148 ( & V_14 -> V_9 ) ;
}
static void
F_149 ( struct V_228 * V_229 )
{
struct V_13 * V_14 =
F_147 ( V_229 , struct V_13 , V_146 ) ;
struct V_8 * V_9 = & V_14 -> V_9 ;
struct V_18 * V_19 = F_43 ( V_14 ) ;
struct V_107 * V_3 = F_44 ( V_19 -> V_108 ) ;
unsigned long V_130 ;
int V_239 = 0 ;
F_144 ( V_14 ) ;
if ( V_14 -> V_130 & V_240 )
F_143 ( V_19 ) ;
F_54 ( V_19 -> V_131 , V_130 ) ;
if ( V_14 -> V_130 & V_241 ) {
F_55 ( V_19 -> V_131 , V_130 ) ;
if ( ! F_150 ( & V_14 -> V_242 ) )
F_140 ( V_19 ) ;
if ( ! F_150 ( & V_14 -> V_243 ) )
F_140 ( V_19 ) ;
F_54 ( V_19 -> V_131 , V_130 ) ;
V_14 -> V_130 &= ~ V_241 ;
}
F_55 ( V_19 -> V_131 , V_130 ) ;
if ( V_14 -> V_190 != - 1 )
F_146 ( & V_14 -> V_238 ) ;
F_54 ( V_19 -> V_131 , V_130 ) ;
if ( ! ( V_14 -> V_130 & V_244 ) &&
( V_3 -> V_115 -> V_245 ) ) {
V_14 -> V_130 |= V_244 ;
V_239 = 1 ;
}
F_55 ( V_19 -> V_131 , V_130 ) ;
if ( V_239 )
V_3 -> V_115 -> V_245 ( V_14 ) ;
F_16 ( V_14 -> V_57 ) ;
F_151 ( V_9 ) ;
F_152 ( V_9 ) ;
F_153 ( V_9 ) ;
F_99 ( & V_19 -> V_166 ) ;
F_99 ( V_9 ) ;
}
static struct V_13 *
F_154 ( struct V_18 * V_19 , int V_170 ,
struct V_246 * V_247 )
{
struct V_20 * V_21 = F_10 ( V_19 ) ;
struct V_107 * V_248 = F_44 ( V_19 -> V_108 ) ;
struct V_13 * V_14 ;
struct V_8 * V_9 ;
unsigned long V_130 ;
int error ;
T_7 V_249 ;
V_249 = ( sizeof( struct V_13 ) + V_248 -> V_115 -> V_250 ) ;
V_14 = F_114 ( V_249 , V_75 ) ;
if ( F_115 ( ! V_14 ) ) {
F_30 ( V_230 L_24 , V_88 ) ;
return NULL ;
}
V_14 -> V_28 = - 1 ;
V_14 -> V_23 = V_24 ;
V_14 -> V_53 = V_21 -> V_53 ;
memcpy ( & V_14 -> V_15 , & V_247 -> V_15 , sizeof( V_14 -> V_15 ) ) ;
memcpy ( & V_14 -> V_16 , & V_247 -> V_16 , sizeof( V_14 -> V_16 ) ) ;
V_14 -> V_17 = V_247 -> V_17 ;
V_14 -> V_126 = V_247 -> V_126 ;
V_14 -> V_33 = V_191 ;
if ( V_248 -> V_115 -> V_250 )
V_14 -> V_251 = & V_14 [ 1 ] ;
V_14 -> V_170 = V_170 ;
V_14 -> V_113 = - 1 ;
F_155 ( & V_14 -> V_243 , V_252 ) ;
F_155 ( & V_14 -> V_242 , V_253 ) ;
F_156 ( & V_14 -> V_254 , V_255 ) ;
F_156 ( & V_14 -> V_238 , F_146 ) ;
F_156 ( & V_14 -> V_146 , F_149 ) ;
F_54 ( V_19 -> V_131 , V_130 ) ;
V_14 -> V_256 = V_21 -> V_45 ++ ;
if ( V_14 -> V_126 & V_257 )
V_14 -> V_190 = V_21 -> V_46 ++ ;
else
V_14 -> V_190 = - 1 ;
F_157 ( & V_14 -> V_145 , & V_21 -> V_42 ) ;
F_158 ( & V_19 -> V_166 ) ;
F_55 ( V_19 -> V_131 , V_130 ) ;
V_9 = & V_14 -> V_9 ;
F_159 ( V_9 ) ;
V_9 -> V_178 = F_158 ( & V_19 -> V_166 ) ;
V_9 -> V_180 = F_97 ;
F_160 ( V_9 , L_25 ,
V_19 -> V_50 , V_170 , V_14 -> V_256 ) ;
F_161 ( V_9 ) ;
error = F_162 ( V_9 ) ;
if ( error ) {
F_30 ( V_230 L_26 ) ;
goto V_258;
}
F_163 ( V_9 ) ;
F_164 ( V_9 ) ;
F_165 ( V_19 , V_14 ) ;
if ( V_14 -> V_126 & V_257 ) {
V_14 -> V_130 |= V_240 ;
F_166 ( V_19 , & V_14 -> V_254 ) ;
}
return V_14 ;
V_258:
F_153 ( V_9 ) ;
F_54 ( V_19 -> V_131 , V_130 ) ;
F_78 ( & V_14 -> V_145 ) ;
F_99 ( & V_19 -> V_166 ) ;
F_55 ( V_19 -> V_131 , V_130 ) ;
F_99 ( V_9 -> V_178 ) ;
F_100 ( V_14 ) ;
return NULL ;
}
struct V_13 *
F_167 ( struct V_18 * V_19 , int V_170 ,
struct V_246 * V_247 )
{
struct V_107 * V_248 = F_44 ( V_19 -> V_108 ) ;
struct V_20 * V_21 = F_10 ( V_19 ) ;
struct V_13 * V_14 ;
unsigned long V_130 ;
int V_169 = 0 ;
F_135 ( V_19 ) ;
F_54 ( V_19 -> V_131 , V_130 ) ;
F_82 (rport, &fc_host->rports, peers) {
if ( ( V_14 -> V_33 == V_109 ) &&
( V_14 -> V_170 == V_170 ) ) {
switch ( V_21 -> V_40 ) {
case V_41 :
case V_259 :
if ( V_14 -> V_16 == V_247 -> V_16 )
V_169 = 1 ;
break;
case V_260 :
if ( V_14 -> V_15 == V_247 -> V_15 )
V_169 = 1 ;
break;
case V_261 :
if ( V_14 -> V_17 == V_247 -> V_17 )
V_169 = 1 ;
break;
}
if ( V_169 ) {
memcpy ( & V_14 -> V_15 , & V_247 -> V_15 ,
sizeof( V_14 -> V_15 ) ) ;
memcpy ( & V_14 -> V_16 , & V_247 -> V_16 ,
sizeof( V_14 -> V_16 ) ) ;
V_14 -> V_17 = V_247 -> V_17 ;
V_14 -> V_33 = V_191 ;
V_14 -> V_126 = V_247 -> V_126 ;
F_55 ( V_19 -> V_131 , V_130 ) ;
if ( V_248 -> V_115 -> V_250 )
memset ( V_14 -> V_251 , 0 ,
V_248 -> V_115 -> V_250 ) ;
if ( ( V_14 -> V_190 != - 1 ) &&
( ! ( V_247 -> V_126 & V_257 ) ) )
return V_14 ;
if ( ! F_150 ( & V_14 -> V_242 ) )
F_140 ( V_19 ) ;
if ( ! F_150 ( & V_14 -> V_243 ) )
F_140 ( V_19 ) ;
F_54 ( V_19 -> V_131 , V_130 ) ;
V_14 -> V_130 &= ~ ( V_262 |
V_241 |
V_244 ) ;
if ( V_14 -> V_190 != - 1 ) {
V_14 -> V_130 |= V_240 ;
F_166 ( V_19 ,
& V_14 -> V_254 ) ;
F_55 ( V_19 -> V_131 ,
V_130 ) ;
F_145 ( & V_14 -> V_9 ) ;
} else
F_55 ( V_19 -> V_131 ,
V_130 ) ;
F_168 ( V_14 ) ;
return V_14 ;
}
}
}
if ( V_21 -> V_40 != V_259 ) {
F_82 (rport, &fc_host->rport_bindings,
peers) {
if ( V_14 -> V_170 != V_170 )
continue;
switch ( V_21 -> V_40 ) {
case V_41 :
if ( V_14 -> V_16 == V_247 -> V_16 )
V_169 = 1 ;
break;
case V_260 :
if ( V_14 -> V_15 == V_247 -> V_15 )
V_169 = 1 ;
break;
case V_261 :
if ( V_14 -> V_17 == V_247 -> V_17 )
V_169 = 1 ;
break;
case V_259 :
break;
}
if ( V_169 ) {
F_169 ( & V_14 -> V_145 , & V_21 -> V_42 ) ;
break;
}
}
if ( V_169 ) {
memcpy ( & V_14 -> V_15 , & V_247 -> V_15 ,
sizeof( V_14 -> V_15 ) ) ;
memcpy ( & V_14 -> V_16 , & V_247 -> V_16 ,
sizeof( V_14 -> V_16 ) ) ;
V_14 -> V_17 = V_247 -> V_17 ;
V_14 -> V_126 = V_247 -> V_126 ;
V_14 -> V_33 = V_191 ;
V_14 -> V_130 &= ~ V_262 ;
if ( V_248 -> V_115 -> V_250 )
memset ( V_14 -> V_251 , 0 ,
V_248 -> V_115 -> V_250 ) ;
if ( V_14 -> V_126 & V_257 ) {
V_14 -> V_130 |= V_240 ;
F_166 ( V_19 , & V_14 -> V_254 ) ;
F_55 ( V_19 -> V_131 , V_130 ) ;
F_145 ( & V_14 -> V_9 ) ;
} else
F_55 ( V_19 -> V_131 , V_130 ) ;
return V_14 ;
}
}
F_55 ( V_19 -> V_131 , V_130 ) ;
V_14 = F_154 ( V_19 , V_170 , V_247 ) ;
return V_14 ;
}
void
F_170 ( struct V_13 * V_14 )
{
struct V_18 * V_19 = F_43 ( V_14 ) ;
unsigned long V_263 = V_14 -> V_53 ;
unsigned long V_130 ;
F_54 ( V_19 -> V_131 , V_130 ) ;
if ( V_14 -> V_33 != V_191 ) {
F_55 ( V_19 -> V_131 , V_130 ) ;
return;
}
V_14 -> V_33 = V_109 ;
V_14 -> V_130 |= V_241 ;
F_55 ( V_19 -> V_131 , V_130 ) ;
if ( V_14 -> V_126 & V_162 &&
V_19 -> V_264 & V_265 )
F_171 ( V_19 , ( unsigned long ) V_14 ) ;
F_172 ( & V_14 -> V_9 ) ;
if ( ( V_14 -> V_113 != - 1 ) &&
( V_14 -> V_113 < V_263 ) )
F_137 ( V_19 , & V_14 -> V_242 ,
V_14 -> V_113 * V_266 ) ;
F_137 ( V_19 , & V_14 -> V_243 , V_263 * V_266 ) ;
}
void
F_173 ( struct V_13 * V_14 , T_2 V_126 )
{
struct V_18 * V_19 = F_43 ( V_14 ) ;
struct V_20 * V_21 = F_10 ( V_19 ) ;
unsigned long V_130 ;
int V_267 = 0 ;
int V_147 ;
F_54 ( V_19 -> V_131 , V_130 ) ;
if ( V_126 & V_257 ) {
if ( V_14 -> V_190 == - 1 ) {
V_14 -> V_190 = V_21 -> V_46 ++ ;
V_267 = 1 ;
} else if ( ! ( V_14 -> V_126 & V_257 ) )
V_267 = 1 ;
} else if ( V_19 -> V_264 & V_265 ) {
V_147 = F_174 ( V_19 , ( unsigned long ) V_14 ,
( char * ) & V_14 -> V_15 ) ;
if ( V_147 )
F_30 ( V_230 L_27 ,
V_147 ) ;
}
V_14 -> V_126 = V_126 ;
F_55 ( V_19 -> V_131 , V_130 ) ;
if ( V_267 ) {
if ( ! F_150 ( & V_14 -> V_242 ) )
F_140 ( V_19 ) ;
if ( ! F_150 ( & V_14 -> V_243 ) )
F_140 ( V_19 ) ;
F_54 ( V_19 -> V_131 , V_130 ) ;
V_14 -> V_130 &= ~ ( V_262 |
V_241 |
V_244 ) ;
F_55 ( V_19 -> V_131 , V_130 ) ;
F_135 ( V_19 ) ;
F_54 ( V_19 -> V_131 , V_130 ) ;
V_14 -> V_130 |= V_240 ;
F_166 ( V_19 , & V_14 -> V_254 ) ;
F_55 ( V_19 -> V_131 , V_130 ) ;
F_145 ( & V_14 -> V_9 ) ;
}
}
static void
V_252 ( struct V_228 * V_229 )
{
struct V_13 * V_14 =
F_147 ( V_229 , struct V_13 , V_243 . V_229 ) ;
struct V_18 * V_19 = F_43 ( V_14 ) ;
struct V_107 * V_3 = F_44 ( V_19 -> V_108 ) ;
struct V_20 * V_21 = F_10 ( V_19 ) ;
unsigned long V_130 ;
int V_239 = 0 ;
F_54 ( V_19 -> V_131 , V_130 ) ;
V_14 -> V_130 &= ~ V_241 ;
if ( ( V_14 -> V_33 == V_191 ) &&
( V_14 -> V_190 != - 1 ) &&
! ( V_14 -> V_126 & V_257 ) ) {
F_175 ( V_230 , & V_14 -> V_9 ,
L_28
L_29 ) ;
F_55 ( V_19 -> V_131 , V_130 ) ;
F_145 ( & V_14 -> V_9 ) ;
F_56 ( V_19 , & V_14 -> V_238 ) ;
return;
}
if ( V_14 -> V_33 != V_109 ) {
F_55 ( V_19 -> V_131 , V_130 ) ;
F_175 ( V_230 , & V_14 -> V_9 ,
L_30
L_31 ,
( V_14 -> V_190 != - 1 ) ? L_32 : L_33 ) ;
return;
}
if ( ( V_21 -> V_40 == V_259 ) ||
( V_14 -> V_190 == - 1 ) ) {
F_78 ( & V_14 -> V_145 ) ;
V_14 -> V_33 = V_110 ;
F_175 ( V_230 , & V_14 -> V_9 ,
L_34
L_35 ,
( V_14 -> V_190 != - 1 ) ? L_32 : L_33 ) ;
F_56 ( V_19 , & V_14 -> V_146 ) ;
F_55 ( V_19 -> V_131 , V_130 ) ;
return;
}
F_175 ( V_230 , & V_14 -> V_9 ,
L_36
L_37 ) ;
F_169 ( & V_14 -> V_145 , & V_21 -> V_43 ) ;
V_14 -> V_28 = - 1 ;
V_14 -> V_23 = V_24 ;
V_14 -> V_126 = V_127 ;
V_14 -> V_33 = V_111 ;
V_14 -> V_130 &= ~ V_262 ;
F_55 ( V_19 -> V_131 , V_130 ) ;
F_144 ( V_14 ) ;
F_54 ( V_19 -> V_131 , V_130 ) ;
if ( V_14 -> V_33 == V_111 ) {
switch ( V_21 -> V_40 ) {
case V_41 :
V_14 -> V_15 = - 1 ;
V_14 -> V_17 = - 1 ;
break;
case V_260 :
V_14 -> V_16 = - 1 ;
V_14 -> V_17 = - 1 ;
break;
case V_261 :
V_14 -> V_15 = - 1 ;
V_14 -> V_16 = - 1 ;
break;
case V_259 :
break;
}
V_14 -> V_130 |= V_244 ;
F_56 ( V_19 , & V_14 -> V_238 ) ;
V_239 = 1 ;
}
F_55 ( V_19 -> V_131 , V_130 ) ;
if ( V_239 && V_3 -> V_115 -> V_245 )
V_3 -> V_115 -> V_245 ( V_14 ) ;
}
static void
V_253 ( struct V_228 * V_229 )
{
struct V_13 * V_14 =
F_147 ( V_229 , struct V_13 , V_242 . V_229 ) ;
if ( V_14 -> V_33 != V_109 )
return;
V_14 -> V_130 |= V_262 ;
F_144 ( V_14 ) ;
}
static void
V_255 ( struct V_228 * V_229 )
{
struct V_13 * V_14 =
F_147 ( V_229 , struct V_13 , V_254 ) ;
struct V_18 * V_19 = F_43 ( V_14 ) ;
struct V_107 * V_3 = F_44 ( V_19 -> V_108 ) ;
unsigned long V_130 ;
if ( ( V_14 -> V_33 == V_191 ) &&
( V_14 -> V_126 & V_257 ) &&
! ( V_3 -> V_115 -> V_268 ) ) {
F_109 ( & V_14 -> V_9 , V_14 -> V_170 ,
V_14 -> V_190 , V_196 , 1 ) ;
}
F_54 ( V_19 -> V_131 , V_130 ) ;
V_14 -> V_130 &= ~ V_240 ;
F_55 ( V_19 -> V_131 , V_130 ) ;
}
int F_176 ( struct V_184 * V_269 )
{
struct V_18 * V_19 = V_269 -> V_8 -> V_270 ;
struct V_13 * V_14 = F_4 ( V_11 ( V_269 -> V_8 ) ) ;
unsigned long V_130 ;
F_54 ( V_19 -> V_131 , V_130 ) ;
while ( V_14 -> V_33 == V_109 &&
! ( V_14 -> V_130 & V_262 ) ) {
F_55 ( V_19 -> V_131 , V_130 ) ;
F_177 ( 1000 ) ;
F_54 ( V_19 -> V_131 , V_130 ) ;
}
F_55 ( V_19 -> V_131 , V_130 ) ;
if ( V_14 -> V_130 & V_262 )
return V_271 ;
return 0 ;
}
static int
F_90 ( struct V_18 * V_19 , int V_170 , struct V_8 * V_272 ,
struct V_159 * V_247 , struct V_128 * * V_273 )
{
struct V_20 * V_21 = F_10 ( V_19 ) ;
struct V_107 * V_248 = F_44 ( V_19 -> V_108 ) ;
struct V_128 * V_129 ;
struct V_8 * V_9 ;
unsigned long V_130 ;
T_7 V_249 ;
int error ;
* V_273 = NULL ;
if ( ! V_248 -> V_115 -> V_221 )
return - V_73 ;
V_249 = ( sizeof( struct V_128 ) + V_248 -> V_115 -> V_274 ) ;
V_129 = F_114 ( V_249 , V_75 ) ;
if ( F_115 ( ! V_129 ) ) {
F_30 ( V_230 L_24 , V_88 ) ;
return - V_52 ;
}
V_129 -> V_137 = V_275 ;
V_129 -> V_226 = V_275 ;
V_129 -> V_15 = V_247 -> V_15 ;
V_129 -> V_16 = V_247 -> V_16 ;
V_129 -> V_126 = V_247 -> V_126 ;
V_129 -> V_163 = V_247 -> V_163 ;
if ( V_248 -> V_115 -> V_274 )
V_129 -> V_251 = & V_129 [ 1 ] ;
V_129 -> V_19 = V_19 ;
V_129 -> V_170 = V_170 ;
V_129 -> V_130 = V_133 ;
F_156 ( & V_129 -> V_135 , V_276 ) ;
F_54 ( V_19 -> V_131 , V_130 ) ;
if ( V_21 -> V_48 >= V_21 -> V_29 ) {
F_55 ( V_19 -> V_131 , V_130 ) ;
F_100 ( V_129 ) ;
return - V_277 ;
}
V_21 -> V_48 ++ ;
V_129 -> V_256 = V_21 -> V_47 ++ ;
F_157 ( & V_129 -> V_145 , & V_21 -> V_44 ) ;
F_158 ( & V_19 -> V_166 ) ;
F_55 ( V_19 -> V_131 , V_130 ) ;
V_9 = & V_129 -> V_9 ;
F_159 ( V_9 ) ;
V_9 -> V_178 = F_158 ( V_272 ) ;
V_9 -> V_180 = F_103 ;
F_160 ( V_9 , L_38 ,
V_19 -> V_50 , V_170 , V_129 -> V_256 ) ;
F_161 ( V_9 ) ;
error = F_162 ( V_9 ) ;
if ( error ) {
F_30 ( V_230 L_39 ) ;
goto V_278;
}
F_163 ( V_9 ) ;
F_164 ( V_9 ) ;
error = V_248 -> V_115 -> V_221 ( V_129 , V_247 -> V_165 ) ;
if ( error ) {
F_30 ( V_230 L_40 ) ;
goto V_279;
}
if ( V_272 != & V_19 -> V_166 ) {
error = F_178 ( & V_19 -> V_166 . V_280 ,
& V_9 -> V_280 , F_179 ( V_9 ) ) ;
if ( error )
F_30 ( V_230
L_41
L_42 ,
V_88 , F_179 ( V_9 ) , error ) ;
}
F_54 ( V_19 -> V_131 , V_130 ) ;
V_129 -> V_130 &= ~ V_133 ;
F_55 ( V_19 -> V_131 , V_130 ) ;
F_175 ( V_281 , V_272 ,
L_43 , F_179 ( V_9 ) ,
V_19 -> V_50 , V_170 ) ;
* V_273 = V_129 ;
return 0 ;
V_279:
F_151 ( V_9 ) ;
F_152 ( V_9 ) ;
V_278:
F_153 ( V_9 ) ;
F_54 ( V_19 -> V_131 , V_130 ) ;
F_78 ( & V_129 -> V_145 ) ;
F_99 ( & V_19 -> V_166 ) ;
V_21 -> V_48 -- ;
F_55 ( V_19 -> V_131 , V_130 ) ;
F_99 ( V_9 -> V_178 ) ;
F_100 ( V_129 ) ;
return error ;
}
struct V_128 *
F_180 ( struct V_18 * V_19 , int V_170 ,
struct V_159 * V_247 )
{
int V_136 ;
struct V_128 * V_129 ;
V_136 = F_90 ( V_19 , V_170 , & V_19 -> V_166 ,
V_247 , & V_129 ) ;
return V_136 ? NULL : V_129 ;
}
int
F_92 ( struct V_128 * V_129 )
{
struct V_18 * V_19 = F_53 ( V_129 ) ;
struct V_20 * V_21 = F_10 ( V_19 ) ;
struct V_107 * V_3 = F_44 ( V_19 -> V_108 ) ;
struct V_8 * V_9 = & V_129 -> V_9 ;
unsigned long V_130 ;
int V_136 ;
if ( V_3 -> V_115 -> V_223 )
V_136 = V_3 -> V_115 -> V_223 ( V_129 ) ;
else
V_136 = - V_73 ;
F_54 ( V_19 -> V_131 , V_130 ) ;
V_129 -> V_130 &= ~ V_134 ;
if ( ! V_136 ) {
V_129 -> V_130 |= V_282 ;
F_78 ( & V_129 -> V_145 ) ;
V_21 -> V_48 -- ;
F_99 ( & V_19 -> V_166 ) ;
}
F_55 ( V_19 -> V_131 , V_130 ) ;
if ( V_136 )
return V_136 ;
if ( V_9 -> V_178 != & V_19 -> V_166 )
F_181 ( & V_19 -> V_166 . V_280 , F_179 ( V_9 ) ) ;
F_151 ( V_9 ) ;
F_152 ( V_9 ) ;
F_153 ( V_9 ) ;
F_99 ( V_9 ) ;
return 0 ;
}
static void
V_276 ( struct V_228 * V_229 )
{
struct V_128 * V_129 =
F_147 ( V_229 , struct V_128 , V_135 ) ;
int V_136 ;
V_136 = F_92 ( V_129 ) ;
if ( V_136 )
F_175 ( V_230 , V_129 -> V_9 . V_178 ,
L_44
L_45 , V_88 ,
F_179 ( & V_129 -> V_9 ) , V_129 -> V_19 -> V_50 ,
V_129 -> V_170 , V_136 ) ;
}
static void
F_182 ( struct V_283 * V_284 )
{
unsigned long V_130 ;
F_54 ( & V_284 -> V_285 , V_130 ) ;
if ( V_284 -> V_286 ) {
F_55 ( & V_284 -> V_285 , V_130 ) ;
return;
}
F_55 ( & V_284 -> V_285 , V_130 ) ;
F_99 ( V_284 -> V_9 ) ;
F_100 ( V_284 -> V_287 . V_288 ) ;
F_100 ( V_284 -> V_289 . V_288 ) ;
F_100 ( V_284 ) ;
}
static void
F_183 ( struct V_283 * V_284 )
{
struct V_290 * V_291 = V_284 -> V_291 ;
struct V_290 * V_292 = V_291 -> V_293 ;
int V_71 ;
V_71 = V_284 -> V_291 -> V_294 = V_284 -> V_295 -> V_202 ;
if ( V_71 < 0 )
V_284 -> V_291 -> V_296 = sizeof( V_297 ) ;
else
V_284 -> V_291 -> V_296 = V_284 -> V_298 ;
V_291 -> V_299 = 0 ;
if ( V_292 ) {
F_84 ( V_284 -> V_295 -> V_300 > V_292 -> V_299 ) ;
V_292 -> V_299 -= F_184 ( V_284 -> V_295 -> V_300 ,
V_292 -> V_299 ) ;
}
F_185 ( V_291 ) ;
}
static void F_186 ( struct V_290 * V_301 )
{
struct V_283 * V_284 = V_301 -> V_302 ;
unsigned long V_130 ;
F_54 ( & V_284 -> V_285 , V_130 ) ;
V_284 -> V_303 |= V_304 ;
V_284 -> V_286 -- ;
F_55 ( & V_284 -> V_285 , V_130 ) ;
F_187 ( V_301 , V_301 -> V_294 ) ;
F_182 ( V_284 ) ;
}
static enum V_183
F_188 ( struct V_290 * V_291 )
{
struct V_283 * V_284 = ( void * ) V_291 -> V_302 ;
struct V_18 * V_19 = V_284 -> V_19 ;
struct V_107 * V_3 = F_44 ( V_19 -> V_108 ) ;
unsigned long V_130 ;
int V_71 = 0 , V_305 = 0 ;
if ( V_284 -> V_14 && V_284 -> V_14 -> V_33 == V_109 )
return V_186 ;
F_54 ( & V_284 -> V_285 , V_130 ) ;
if ( V_284 -> V_303 & V_304 )
V_305 = 1 ;
else
V_284 -> V_286 ++ ;
F_55 ( & V_284 -> V_285 , V_130 ) ;
if ( ! V_305 && V_3 -> V_115 -> V_306 ) {
V_71 = V_3 -> V_115 -> V_306 ( V_284 ) ;
if ( V_71 == - V_307 ) {
V_284 -> V_286 -- ;
return V_186 ;
} else if ( V_71 )
F_30 ( V_230 L_46
L_47 , V_71 ) ;
}
if ( V_305 )
return V_187 ;
else
return V_308 ;
}
static int
F_189 ( struct V_309 * V_1 , struct V_290 * V_291 )
{
T_7 V_310 = ( sizeof( struct V_311 ) * V_291 -> V_312 ) ;
F_118 ( ! V_291 -> V_312 ) ;
V_1 -> V_288 = F_114 ( V_310 , V_75 ) ;
if ( ! V_1 -> V_288 )
return - V_52 ;
F_190 ( V_1 -> V_288 , V_291 -> V_312 ) ;
V_1 -> V_313 = F_191 ( V_291 -> V_314 , V_291 , V_1 -> V_288 ) ;
V_1 -> V_315 = F_192 ( V_291 ) ;
return 0 ;
}
static int
F_193 ( struct V_18 * V_19 , struct V_13 * V_14 ,
struct V_290 * V_291 )
{
struct V_107 * V_3 = F_44 ( V_19 -> V_108 ) ;
struct V_290 * V_292 = V_291 -> V_293 ;
struct V_283 * V_284 ;
int V_147 ;
F_118 ( V_291 -> V_302 ) ;
V_284 = F_114 ( sizeof( struct V_283 ) + V_3 -> V_115 -> V_316 ,
V_75 ) ;
if ( ! V_284 )
return - V_52 ;
V_291 -> V_302 = V_284 ;
V_284 -> V_19 = V_19 ;
V_284 -> V_14 = V_14 ;
V_284 -> V_291 = V_291 ;
if ( V_3 -> V_115 -> V_316 )
V_284 -> V_251 = ( void * ) & V_284 [ 1 ] ;
F_194 ( & V_284 -> V_285 ) ;
V_284 -> V_290 = (struct V_317 * ) V_291 -> V_318 ;
V_284 -> V_319 = V_291 -> V_320 ;
V_284 -> V_295 = V_291 -> V_321 ;
V_284 -> V_298 = V_322 ;
if ( V_291 -> V_323 ) {
V_147 = F_189 ( & V_284 -> V_287 , V_291 ) ;
if ( V_147 )
goto V_324;
}
if ( V_292 && V_292 -> V_323 ) {
V_147 = F_189 ( & V_284 -> V_289 , V_292 ) ;
if ( V_147 )
goto V_325;
}
V_284 -> V_326 = F_183 ;
if ( V_14 )
V_284 -> V_9 = & V_14 -> V_9 ;
else
V_284 -> V_9 = & V_19 -> V_166 ;
F_158 ( V_284 -> V_9 ) ;
V_284 -> V_286 = 1 ;
return 0 ;
V_325:
F_100 ( V_284 -> V_287 . V_288 ) ;
V_324:
F_100 ( V_284 ) ;
return - V_52 ;
}
static enum V_327
F_195 ( struct V_328 * V_314 , struct V_18 * V_19 ,
struct V_283 * V_284 )
{
struct V_107 * V_3 = F_44 ( V_19 -> V_108 ) ;
int V_329 = sizeof( V_297 ) ;
int V_147 ;
switch ( V_284 -> V_290 -> V_330 ) {
case V_331 :
V_329 += sizeof( struct V_332 ) ;
break;
case V_333 :
V_329 += sizeof( struct V_334 ) ;
break;
case V_335 :
V_329 += sizeof( struct V_336 ) ;
if ( ( ! V_284 -> V_287 . V_315 ) ||
( ! V_284 -> V_289 . V_315 ) ) {
V_147 = - V_105 ;
goto V_337;
}
break;
case V_338 :
V_329 += sizeof( struct V_339 ) ;
if ( ( ! V_284 -> V_287 . V_315 ) ||
( ! V_284 -> V_289 . V_315 ) ) {
V_147 = - V_105 ;
goto V_337;
}
break;
case V_340 :
V_329 += sizeof( struct V_341 ) ;
if ( ( V_19 -> V_231 -> V_83 == 0L ) ||
( V_284 -> V_290 -> V_342 . V_343 . V_83 !=
V_19 -> V_231 -> V_83 ) ) {
V_147 = - V_344 ;
goto V_337;
}
break;
default:
V_147 = - V_345 ;
goto V_337;
}
if ( V_284 -> V_319 < V_329 ) {
V_147 = - V_346 ;
goto V_337;
}
V_147 = V_3 -> V_115 -> V_347 ( V_284 ) ;
if ( ! V_147 )
return V_348 ;
V_337:
F_118 ( V_284 -> V_298 < sizeof( V_297 ) ) ;
V_284 -> V_295 -> V_300 = 0 ;
V_284 -> V_295 -> V_202 = V_147 ;
V_284 -> V_298 = sizeof( V_297 ) ;
F_183 ( V_284 ) ;
return V_348 ;
}
static void
F_168 ( struct V_13 * V_14 )
{
if ( ! V_14 -> V_57 )
return;
F_158 ( & V_14 -> V_9 ) ;
F_196 ( V_14 -> V_57 ) ;
F_99 ( & V_14 -> V_9 ) ;
}
static enum V_327
F_197 ( struct V_328 * V_314 , struct V_18 * V_19 ,
struct V_13 * V_14 , struct V_283 * V_284 )
{
struct V_107 * V_3 = F_44 ( V_19 -> V_108 ) ;
int V_329 = sizeof( V_297 ) ;
int V_147 ;
switch ( V_284 -> V_290 -> V_330 ) {
case V_349 :
V_329 += sizeof( struct V_350 ) ;
goto V_351;
case V_352 :
V_329 += sizeof( struct V_353 ) ;
V_351:
if ( ( ! V_284 -> V_287 . V_315 ) ||
( ! V_284 -> V_289 . V_315 ) ) {
V_147 = - V_105 ;
goto V_354;
}
break;
default:
V_147 = - V_345 ;
goto V_354;
}
if ( V_284 -> V_319 < V_329 ) {
V_147 = - V_346 ;
goto V_354;
}
V_147 = V_3 -> V_115 -> V_347 ( V_284 ) ;
if ( ! V_147 )
return V_348 ;
V_354:
F_118 ( V_284 -> V_298 < sizeof( V_297 ) ) ;
V_284 -> V_295 -> V_300 = 0 ;
V_284 -> V_295 -> V_202 = V_147 ;
V_284 -> V_298 = sizeof( V_297 ) ;
F_183 ( V_284 ) ;
return V_348 ;
}
static void
F_198 ( struct V_328 * V_314 , struct V_18 * V_19 ,
struct V_13 * V_14 , struct V_8 * V_9 )
{
struct V_290 * V_291 ;
struct V_283 * V_284 ;
enum V_327 V_147 ;
if ( ! F_158 ( V_9 ) )
return;
while ( 1 ) {
if ( V_14 && ( V_14 -> V_33 == V_109 ) &&
! ( V_14 -> V_130 & V_262 ) )
break;
V_291 = F_199 ( V_314 ) ;
if ( ! V_291 )
break;
if ( V_14 && ( V_14 -> V_33 != V_191 ) ) {
V_291 -> V_294 = - V_355 ;
F_200 ( V_314 -> V_356 ) ;
F_187 ( V_291 , - V_355 ) ;
F_201 ( V_314 -> V_356 ) ;
continue;
}
F_200 ( V_314 -> V_356 ) ;
V_147 = F_193 ( V_19 , V_14 , V_291 ) ;
if ( V_147 ) {
V_291 -> V_294 = V_147 ;
F_187 ( V_291 , V_147 ) ;
F_201 ( V_314 -> V_356 ) ;
continue;
}
V_284 = V_291 -> V_302 ;
if ( V_284 -> V_319 < sizeof( V_297 ) ) {
F_118 ( V_284 -> V_298 < sizeof( V_297 ) ) ;
V_284 -> V_295 -> V_300 = 0 ;
V_284 -> V_295 -> V_202 = - V_346 ;
V_284 -> V_298 = sizeof( V_297 ) ;
F_183 ( V_284 ) ;
F_201 ( V_314 -> V_356 ) ;
continue;
}
if ( V_14 )
V_147 = F_197 ( V_314 , V_19 , V_14 , V_284 ) ;
else
V_147 = F_195 ( V_314 , V_19 , V_284 ) ;
if ( V_147 == V_357 )
break;
if ( V_147 == V_348 )
F_201 ( V_314 -> V_356 ) ;
}
F_200 ( V_314 -> V_356 ) ;
F_99 ( V_9 ) ;
F_201 ( V_314 -> V_356 ) ;
}
static void
F_202 ( struct V_328 * V_314 )
{
struct V_18 * V_19 = V_314 -> V_358 ;
F_198 ( V_314 , V_19 , NULL , & V_19 -> V_166 ) ;
}
static void
F_203 ( struct V_328 * V_314 )
{
struct V_13 * V_14 = V_314 -> V_358 ;
struct V_18 * V_19 = F_43 ( V_14 ) ;
F_198 ( V_314 , V_19 , V_14 , & V_14 -> V_9 ) ;
}
static int
F_14 ( struct V_18 * V_19 , struct V_20 * V_21 )
{
struct V_8 * V_9 = & V_19 -> V_166 ;
struct V_107 * V_3 = F_44 ( V_19 -> V_108 ) ;
struct V_328 * V_314 ;
int V_71 ;
char V_359 [ 20 ] ;
V_21 -> V_57 = NULL ;
if ( ! V_3 -> V_115 -> V_347 )
return - V_360 ;
snprintf ( V_359 , sizeof( V_359 ) ,
L_48 , V_19 -> V_50 ) ;
V_314 = F_204 ( V_19 , F_202 ) ;
if ( ! V_314 ) {
F_30 ( V_230 L_49
L_50 ,
V_19 -> V_50 ) ;
return - V_52 ;
}
V_314 -> V_358 = V_19 ;
F_205 ( V_361 , V_314 ) ;
F_206 ( V_314 , F_186 ) ;
F_207 ( V_314 , F_188 ) ;
F_208 ( V_314 , V_362 ) ;
V_71 = F_209 ( V_314 , V_9 , V_359 , NULL ) ;
if ( V_71 ) {
F_30 ( V_230 L_49
L_51 ,
V_19 -> V_50 ) ;
F_210 ( V_314 ) ;
return V_71 ;
}
V_21 -> V_57 = V_314 ;
return 0 ;
}
static int
F_165 ( struct V_18 * V_19 , struct V_13 * V_14 )
{
struct V_8 * V_9 = & V_14 -> V_9 ;
struct V_107 * V_3 = F_44 ( V_19 -> V_108 ) ;
struct V_328 * V_314 ;
int V_71 ;
V_14 -> V_57 = NULL ;
if ( ! V_3 -> V_115 -> V_347 )
return - V_360 ;
V_314 = F_204 ( V_19 , F_203 ) ;
if ( ! V_314 ) {
F_30 ( V_230 L_52
L_50 ,
V_9 -> V_280 . V_69 ) ;
return - V_52 ;
}
V_314 -> V_358 = V_14 ;
F_205 ( V_361 , V_314 ) ;
F_206 ( V_314 , F_186 ) ;
F_207 ( V_314 , F_188 ) ;
F_208 ( V_314 , V_363 ) ;
V_71 = F_209 ( V_314 , V_9 , NULL , NULL ) ;
if ( V_71 ) {
F_30 ( V_230 L_52
L_51 ,
V_9 -> V_280 . V_69 ) ;
F_210 ( V_314 ) ;
return V_71 ;
}
V_14 -> V_57 = V_314 ;
return 0 ;
}
static void
F_16 ( struct V_328 * V_314 )
{
struct V_290 * V_291 ;
int V_364 ;
if ( V_314 ) {
F_201 ( V_314 -> V_356 ) ;
F_211 ( V_314 ) ;
while ( 1 ) {
V_291 = F_199 ( V_314 ) ;
V_364 = V_314 -> V_301 . V_117 [ 0 ] + V_314 -> V_301 . V_117 [ 1 ] +
V_314 -> V_301 . V_365 [ 0 ] + V_314 -> V_301 . V_365 [ 1 ] ;
F_200 ( V_314 -> V_356 ) ;
if ( V_364 == 0 )
break;
if ( V_291 ) {
V_291 -> V_294 = - V_355 ;
F_187 ( V_291 , - V_355 ) ;
}
F_177 ( 200 ) ;
F_201 ( V_314 -> V_356 ) ;
}
F_212 ( V_314 ) ;
F_210 ( V_314 ) ;
}
}
