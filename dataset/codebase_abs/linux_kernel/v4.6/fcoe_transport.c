int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_5 V_6 ;
if ( ! F_3 ( V_4 , & V_6 ) ) {
V_2 -> V_7 &= ~ ( V_8 |
V_9 |
V_10 |
V_11 ) ;
if ( V_6 . V_12 . V_13 [ 0 ] & (
V_14 |
V_15 |
V_16 ) )
V_2 -> V_7 |= V_8 ;
if ( V_6 . V_12 . V_13 [ 0 ] & (
V_17 |
V_18 |
V_19 |
V_20 ) )
V_2 -> V_7 |= V_9 ;
if ( V_6 . V_12 . V_13 [ 0 ] & (
V_21 |
V_22 ) )
V_2 -> V_7 |= V_10 ;
if ( V_6 . V_12 . V_13 [ 0 ] & (
V_23 |
V_24 |
V_25 |
V_26 ) )
V_2 -> V_7 |= V_11 ;
switch ( V_6 . V_27 . V_28 ) {
case V_29 :
V_2 -> V_30 = V_8 ;
break;
case V_31 :
V_2 -> V_30 = V_9 ;
break;
case 20000 :
V_2 -> V_30 = V_10 ;
break;
case 40000 :
V_2 -> V_30 = V_11 ;
break;
default:
V_2 -> V_30 = V_32 ;
break;
}
return 0 ;
}
return - 1 ;
}
void F_4 ( struct V_1 * V_2 ,
struct V_33 * V_34 ,
struct V_3 * V_4 )
{
unsigned int V_35 ;
T_1 V_36 , V_37 , V_38 ;
struct V_39 * V_40 ;
struct V_41 * V_42 ;
struct V_43 V_44 ;
V_36 = 0 ;
V_37 = 0 ;
V_38 = 0 ;
V_42 = (struct V_41 * ) V_34 ;
memset ( V_42 , 0 , sizeof( * V_42 ) ) ;
F_5 (cpu) {
V_40 = F_6 ( V_2 -> V_40 , V_35 ) ;
V_36 += V_40 -> V_45 ;
V_37 += V_40 -> V_46 ;
V_38 += V_40 -> V_47 ;
}
V_42 -> V_48 = F_7 ( V_36 ) ;
V_42 -> V_49 = F_7 ( V_37 ) ;
V_42 -> V_50 = F_7 ( V_38 ) ;
V_42 -> V_51 =
F_7 ( F_8 ( V_4 , & V_44 ) -> V_52 ) ;
}
void F_9 ( struct V_1 * V_2 ,
struct V_33 * V_34 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
F_4 ( V_2 , V_34 , V_4 ) ;
}
void F_10 ( struct V_53 * V_54 )
{
struct V_55 * V_56 = F_11 ( V_54 ) ;
struct V_3 * V_4 = F_2 ( V_56 -> V_57 ) ;
struct V_33 * V_34 ;
V_34 = (struct V_33 * ) ( & V_54 -> V_42 ) ;
F_4 ( V_56 -> V_57 , V_34 , V_4 ) ;
}
void F_12 ( T_2 V_58 , char * V_59 , int V_60 )
{
T_3 V_61 [ 8 ] ;
F_13 ( V_58 , V_61 ) ;
snprintf ( V_59 , V_60 , L_1 ,
V_61 [ 0 ] , V_61 [ 1 ] , V_61 [ 2 ] , V_61 [ 3 ] ,
V_61 [ 4 ] , V_61 [ 5 ] , V_61 [ 6 ] , V_61 [ 7 ] ) ;
}
int F_14 ( struct V_62 * V_63 )
{
struct V_64 * V_65 = F_15 ( V_63 ) ;
struct V_1 * V_66 = F_16 ( V_65 ) ;
struct V_1 * V_67 ;
int V_68 = 0 ;
char V_59 [ 32 ] ;
F_17 ( & V_66 -> V_69 ) ;
F_12 ( V_63 -> V_70 , V_59 , sizeof( V_59 ) ) ;
if ( ! memcmp ( & V_66 -> V_61 , & V_63 -> V_70 , sizeof( T_2 ) ) ) {
F_18 ( L_2
L_3 , V_59 ) ;
V_68 = - V_71 ;
goto V_72;
}
F_19 (vn_port, &n_port->vports, list) {
if ( ! memcmp ( & V_67 -> V_61 , & V_63 -> V_70 , sizeof( T_2 ) ) ) {
F_18 ( L_4
L_5 , V_59 ) ;
V_68 = - V_71 ;
break;
}
}
V_72:
F_20 ( & V_66 -> V_69 ) ;
return V_68 ;
}
int F_21 ( struct V_3 * V_4 , T_2 * V_58 , int type )
{
const struct V_73 * V_74 = V_4 -> V_75 ;
if ( V_74 -> V_76 )
return V_74 -> V_76 ( V_4 , V_58 , type ) ;
return - V_71 ;
}
T_1 F_22 ( struct V_77 * V_78 )
{
struct V_79 * V_80 = F_23 ( V_78 ) ;
struct V_81 * V_82 ;
unsigned char * V_83 ;
unsigned long V_84 , V_60 , V_85 ;
T_1 V_86 ;
unsigned V_87 ;
V_86 = F_24 ( ~ 0 , V_80 -> V_83 , F_25 ( V_80 ) ) ;
for ( V_87 = 0 ; V_87 < F_26 ( V_80 ) -> V_88 ; V_87 ++ ) {
V_82 = & F_26 ( V_80 ) -> V_89 [ V_87 ] ;
V_84 = V_82 -> V_90 ;
V_60 = F_27 ( V_82 ) ;
while ( V_60 > 0 ) {
V_85 = F_28 ( V_60 , V_91 - ( V_84 & ~ V_92 ) ) ;
V_83 = F_29 (
F_30 ( V_82 ) + ( V_84 >> V_93 ) ) ;
V_86 = F_24 ( V_86 , V_83 + ( V_84 & ~ V_92 ) , V_85 ) ;
F_31 ( V_83 ) ;
V_84 += V_85 ;
V_60 -= V_85 ;
}
}
return V_86 ;
}
int F_32 ( struct V_79 * V_80 )
{
struct V_79 * V_94 ;
int V_68 ;
V_94 = F_33 ( V_80 , V_95 ) ;
if ( ! V_94 )
return - V_96 ;
V_68 = F_34 ( V_94 ) ;
if ( V_68 != 0 )
return V_68 ;
F_35 ( V_80 ) ;
return 0 ;
}
void F_36 ( struct V_1 * V_2 )
{
struct V_97 * V_98 = F_37 ( V_2 ) ;
struct V_79 * V_80 ;
F_38 ( & V_98 -> V_99 . V_100 ) ;
while ( ( V_80 = F_39 ( & V_98 -> V_99 ) ) != NULL ) {
F_40 ( & V_98 -> V_99 . V_100 ) ;
F_35 ( V_80 ) ;
F_38 ( & V_98 -> V_99 . V_100 ) ;
}
F_40 ( & V_98 -> V_99 . V_100 ) ;
}
void F_41 ( struct V_1 * V_2 , struct V_79 * V_80 )
{
struct V_97 * V_98 = F_37 ( V_2 ) ;
int V_68 ;
F_38 ( & V_98 -> V_99 . V_100 ) ;
if ( V_80 )
F_42 ( & V_98 -> V_99 , V_80 ) ;
if ( V_98 -> V_101 )
goto V_72;
V_98 -> V_101 = 1 ;
while ( V_98 -> V_99 . V_102 ) {
V_98 -> V_99 . V_102 ++ ;
V_80 = F_39 ( & V_98 -> V_99 ) ;
F_40 ( & V_98 -> V_99 . V_100 ) ;
V_68 = F_32 ( V_80 ) ;
F_38 ( & V_98 -> V_99 . V_100 ) ;
if ( V_68 ) {
F_43 ( & V_98 -> V_99 , V_80 ) ;
V_98 -> V_99 . V_102 -- ;
break;
}
V_98 -> V_99 . V_102 -- ;
}
if ( V_98 -> V_99 . V_102 < V_98 -> V_103 )
V_2 -> V_104 = 0 ;
if ( V_98 -> V_99 . V_102 && ! F_44 ( & V_98 -> V_105 ) )
F_45 ( & V_98 -> V_105 , V_106 + 2 ) ;
V_98 -> V_101 = 0 ;
V_72:
if ( V_98 -> V_99 . V_102 > V_98 -> V_107 )
V_2 -> V_104 = 1 ;
F_40 ( & V_98 -> V_99 . V_100 ) ;
}
void F_46 ( T_4 V_2 )
{
F_41 ( (struct V_1 * ) V_2 , NULL ) ;
}
int F_47 ( struct V_79 * V_80 , int V_108 ,
struct V_109 * V_110 )
{
struct V_111 * V_111 ;
V_111 = V_110 -> V_112 ;
if ( ! V_111 ) {
V_111 = F_48 ( V_95 ) ;
if ( ! V_111 )
return - V_96 ;
V_110 -> V_112 = V_111 ;
V_110 -> V_113 = 0 ;
}
F_49 ( V_111 ) ;
F_50 ( V_80 , F_26 ( V_80 ) -> V_88 , V_111 ,
V_110 -> V_113 , V_108 ) ;
V_80 -> V_60 += V_108 ;
V_80 -> V_114 += V_108 ;
V_80 -> V_115 += V_108 ;
V_110 -> V_113 += sizeof( struct V_116 ) ;
if ( V_110 -> V_113 >= V_91 ) {
V_110 -> V_112 = NULL ;
V_110 -> V_113 = 0 ;
F_51 ( V_111 ) ;
}
return 0 ;
}
static struct V_117 * F_52 ( struct V_3 * V_4 )
{
struct V_117 * V_118 = NULL ;
F_19 (ft, &fcoe_transports, list)
if ( V_118 -> V_119 && V_118 -> V_119 ( V_4 ) )
return V_118 ;
return NULL ;
}
int F_53 ( struct V_117 * V_118 )
{
int V_68 = 0 ;
F_17 ( & V_120 ) ;
if ( V_118 -> V_121 ) {
F_18 ( L_6 ,
V_118 -> V_122 ) ;
V_68 = - V_123 ;
goto V_124;
}
if ( strcmp ( V_118 -> V_122 , V_125 ) )
F_54 ( & V_118 -> V_126 , & V_127 ) ;
else
F_55 ( & V_118 -> V_126 , & V_127 ) ;
V_118 -> V_121 = true ;
F_18 ( L_7 , V_118 -> V_122 ) ;
V_124:
F_20 ( & V_120 ) ;
return V_68 ;
}
int F_56 ( struct V_117 * V_118 )
{
int V_68 = 0 ;
struct V_128 * V_129 = NULL , * V_130 ;
F_17 ( & V_120 ) ;
if ( ! V_118 -> V_121 ) {
F_18 ( L_8 ,
V_118 -> V_122 ) ;
V_68 = - V_131 ;
goto V_124;
}
F_17 ( & V_132 ) ;
F_57 (nm, tmp, &fcoe_netdevs, list) {
if ( V_129 -> V_118 == V_118 ) {
F_18 ( L_9
L_10 ,
V_118 -> V_122 , V_129 -> V_4 -> V_122 ) ;
F_58 ( & V_129 -> V_126 ) ;
F_59 ( V_129 ) ;
}
}
F_20 ( & V_132 ) ;
F_58 ( & V_118 -> V_126 ) ;
V_118 -> V_121 = false ;
F_18 ( L_11 , V_118 -> V_122 ) ;
V_124:
F_20 ( & V_120 ) ;
return V_68 ;
}
static int F_60 ( char * V_133 , const struct V_134 * V_135 )
{
int V_87 , V_136 ;
struct V_117 * V_118 = NULL ;
V_87 = V_136 = sprintf ( V_133 , L_12 ) ;
F_17 ( & V_120 ) ;
F_19 (ft, &fcoe_transports, list) {
if ( V_87 >= V_91 - V_137 )
break;
V_87 += snprintf ( & V_133 [ V_87 ] , V_137 , L_13 , V_118 -> V_122 ) ;
}
F_20 ( & V_120 ) ;
if ( V_87 == V_136 )
V_87 += snprintf ( & V_133 [ V_87 ] , V_137 , L_14 ) ;
return V_87 ;
}
static int T_5 F_61 ( void )
{
F_62 ( & V_138 ) ;
return 0 ;
}
static int F_63 ( void )
{
struct V_117 * V_118 ;
F_64 ( & V_138 ) ;
F_17 ( & V_120 ) ;
F_19 (ft, &fcoe_transports, list)
F_65 ( V_139 L_15 ,
V_118 -> V_122 ) ;
F_20 ( & V_120 ) ;
return 0 ;
}
static int F_66 ( struct V_3 * V_4 ,
struct V_117 * V_118 )
{
struct V_128 * V_129 ;
V_129 = F_67 ( sizeof( * V_129 ) , V_140 ) ;
if ( ! V_129 ) {
F_65 ( V_139 L_16 ) ;
return - V_96 ;
}
V_129 -> V_4 = V_4 ;
V_129 -> V_118 = V_118 ;
F_17 ( & V_132 ) ;
F_54 ( & V_129 -> V_126 , & V_141 ) ;
F_20 ( & V_132 ) ;
return 0 ;
}
static void F_68 ( struct V_3 * V_4 )
{
struct V_128 * V_129 = NULL , * V_130 ;
F_17 ( & V_132 ) ;
F_57 (nm, tmp, &fcoe_netdevs, list) {
if ( V_129 -> V_4 == V_4 ) {
F_58 ( & V_129 -> V_126 ) ;
F_59 ( V_129 ) ;
F_20 ( & V_132 ) ;
return;
}
}
F_20 ( & V_132 ) ;
}
static struct V_117 * F_69 ( struct V_3 * V_4 )
{
struct V_117 * V_118 = NULL ;
struct V_128 * V_129 ;
F_17 ( & V_132 ) ;
F_19 (nm, &fcoe_netdevs, list) {
if ( V_4 == V_129 -> V_4 ) {
V_118 = V_129 -> V_118 ;
F_20 ( & V_132 ) ;
return V_118 ;
}
}
F_20 ( & V_132 ) ;
return NULL ;
}
static struct V_3 * F_70 ( const char * V_133 )
{
char * V_142 ;
char V_143 [ V_137 + 2 ] ;
if ( V_133 ) {
F_71 ( V_143 , V_133 , V_137 ) ;
V_142 = V_143 + strlen ( V_143 ) ;
while ( -- V_142 >= V_143 && * V_142 == '\n' )
* V_142 = '\0' ;
return F_72 ( & V_144 , V_143 ) ;
}
return NULL ;
}
static int F_73 ( struct V_145 * V_146 ,
T_4 V_147 , void * V_148 )
{
struct V_3 * V_4 = F_74 ( V_148 ) ;
switch ( V_147 ) {
case V_149 :
F_18 ( L_17 ,
V_4 -> V_122 ) ;
F_68 ( V_4 ) ;
break;
}
return V_150 ;
}
T_6 F_75 ( struct V_151 * V_152 ,
const char * V_59 , T_7 V_153 )
{
struct V_3 * V_4 = NULL ;
struct V_117 * V_118 = NULL ;
int V_68 = 0 ;
int V_154 ;
F_17 ( & V_120 ) ;
V_4 = F_70 ( V_59 ) ;
if ( ! V_4 ) {
F_18 ( L_18 , V_59 ) ;
V_68 = - V_131 ;
goto V_155;
}
V_118 = F_69 ( V_4 ) ;
if ( V_118 ) {
F_18 ( L_19
L_20 ,
V_118 -> V_122 , V_4 -> V_122 ) ;
V_68 = - V_123 ;
goto V_156;
}
V_118 = F_52 ( V_4 ) ;
if ( ! V_118 ) {
F_18 ( L_21 ,
V_4 -> V_122 ) ;
V_68 = - V_131 ;
goto V_156;
}
V_154 = V_118 -> V_157 ? V_118 -> V_157 ( V_4 ) : - V_131 ;
if ( V_154 ) {
F_68 ( V_4 ) ;
V_68 = - V_96 ;
goto V_156;
}
V_154 = F_66 ( V_4 , V_118 ) ;
if ( V_154 ) {
F_18 ( L_22
L_23 ,
V_118 -> V_122 , V_4 -> V_122 ) ;
V_68 = - V_131 ;
goto V_156;
}
F_18 ( L_24 ,
V_118 -> V_122 , V_4 -> V_122 ) ;
V_156:
F_76 ( V_4 ) ;
V_155:
F_20 ( & V_120 ) ;
if ( V_68 )
return V_68 ;
return V_153 ;
}
T_6 F_77 ( struct V_151 * V_152 ,
const char * V_59 , T_7 V_153 )
{
int V_68 = - V_131 ;
struct V_3 * V_4 = NULL ;
struct V_117 * V_118 = NULL ;
F_17 ( & V_120 ) ;
V_4 = F_70 ( V_59 ) ;
if ( ! V_4 ) {
F_18 ( L_25 , V_59 ) ;
goto V_155;
}
V_118 = F_69 ( V_4 ) ;
if ( ! V_118 ) {
F_18 ( L_21 ,
V_4 -> V_122 ) ;
goto V_156;
}
V_68 = V_118 -> V_158 ( V_4 ) ;
if ( V_68 )
goto V_156;
F_68 ( V_4 ) ;
F_18 ( L_26 ,
V_118 -> V_122 , ( V_68 ) ? L_27 : L_28 ,
V_4 -> V_122 ) ;
V_68 = V_153 ;
V_156:
F_76 ( V_4 ) ;
V_155:
F_20 ( & V_120 ) ;
return V_68 ;
}
static int F_78 ( const char * V_133 , struct V_134 * V_135 )
{
int V_68 = - V_131 ;
struct V_3 * V_4 = NULL ;
struct V_117 * V_118 = NULL ;
enum V_159 V_160 = (enum V_159 ) ( long ) V_135 -> V_161 ;
F_17 ( & V_120 ) ;
V_4 = F_70 ( V_133 ) ;
if ( ! V_4 ) {
F_18 ( L_18 , V_133 ) ;
goto V_155;
}
V_118 = F_69 ( V_4 ) ;
if ( V_118 ) {
F_18 ( L_19
L_20 ,
V_118 -> V_122 , V_4 -> V_122 ) ;
V_68 = - V_123 ;
goto V_156;
}
V_118 = F_52 ( V_4 ) ;
if ( ! V_118 ) {
F_18 ( L_21 ,
V_4 -> V_122 ) ;
goto V_156;
}
V_68 = F_66 ( V_4 , V_118 ) ;
if ( V_68 ) {
F_18 ( L_22
L_23 ,
V_118 -> V_122 , V_4 -> V_122 ) ;
goto V_156;
}
V_68 = V_118 -> V_162 ? V_118 -> V_162 ( V_4 , V_160 ) : - V_131 ;
if ( V_68 )
F_68 ( V_4 ) ;
F_18 ( L_29 ,
V_118 -> V_122 , ( V_68 ) ? L_27 : L_28 ,
V_4 -> V_122 ) ;
V_156:
F_76 ( V_4 ) ;
V_155:
F_20 ( & V_120 ) ;
return V_68 ;
}
static int F_79 ( const char * V_133 , struct V_134 * V_135 )
{
int V_68 = - V_131 ;
struct V_3 * V_4 = NULL ;
struct V_117 * V_118 = NULL ;
F_17 ( & V_120 ) ;
V_4 = F_70 ( V_133 ) ;
if ( ! V_4 ) {
F_18 ( L_25 , V_133 ) ;
goto V_155;
}
V_118 = F_69 ( V_4 ) ;
if ( ! V_118 ) {
F_18 ( L_21 ,
V_4 -> V_122 ) ;
goto V_156;
}
V_68 = V_118 -> V_158 ? V_118 -> V_158 ( V_4 ) : - V_131 ;
F_68 ( V_4 ) ;
F_18 ( L_26 ,
V_118 -> V_122 , ( V_68 ) ? L_27 : L_28 ,
V_4 -> V_122 ) ;
V_156:
F_76 ( V_4 ) ;
V_155:
F_20 ( & V_120 ) ;
return V_68 ;
}
static int F_80 ( const char * V_133 , struct V_134 * V_135 )
{
int V_68 = - V_131 ;
struct V_3 * V_4 = NULL ;
struct V_117 * V_118 = NULL ;
F_17 ( & V_120 ) ;
V_4 = F_70 ( V_133 ) ;
if ( ! V_4 )
goto V_155;
V_118 = F_69 ( V_4 ) ;
if ( ! V_118 )
goto V_156;
V_68 = V_118 -> V_163 ? V_118 -> V_163 ( V_4 ) : - V_131 ;
V_156:
F_76 ( V_4 ) ;
V_155:
F_20 ( & V_120 ) ;
return V_68 ;
}
static int F_81 ( const char * V_133 , struct V_134 * V_135 )
{
int V_68 = - V_131 ;
struct V_3 * V_4 = NULL ;
struct V_117 * V_118 = NULL ;
F_17 ( & V_120 ) ;
V_4 = F_70 ( V_133 ) ;
if ( ! V_4 )
goto V_155;
V_118 = F_69 ( V_4 ) ;
if ( ! V_118 )
goto V_156;
V_68 = V_118 -> V_164 ? V_118 -> V_164 ( V_4 ) : - V_131 ;
V_156:
F_76 ( V_4 ) ;
V_155:
F_20 ( & V_120 ) ;
return V_68 ;
}
static int T_5 F_82 ( void )
{
int V_68 = 0 ;
V_68 = F_61 () ;
if ( V_68 )
return V_68 ;
V_68 = F_83 () ;
if ( V_68 )
F_63 () ;
return V_68 ;
}
static void T_8 F_84 ( void )
{
F_85 () ;
F_63 () ;
}
