static inline T_1 F_1 ( T_1 V_1 )
{
int V_2 ;
for ( V_2 = 0 ; V_2 < F_2 ( V_3 ) ; V_2 ++ ) {
if ( V_3 [ V_2 ] . V_1 == V_1 )
return V_3 [ V_2 ] . V_4 ;
}
return V_5 ;
}
int F_3 ( struct V_6 * V_7 )
{
struct V_8 * V_9 = F_4 ( V_7 ) ;
struct V_10 V_11 ;
if ( ! F_5 ( V_9 , & V_11 ) ) {
V_7 -> V_12 &= ~ ( V_13 |
V_14 |
V_15 |
V_16 ) ;
if ( V_11 . V_17 . V_18 [ 0 ] & (
V_19 |
V_20 |
V_21 ) )
V_7 -> V_12 |= V_13 ;
if ( V_11 . V_17 . V_18 [ 0 ] & (
V_22 |
V_23 |
V_24 |
V_25 ) )
V_7 -> V_12 |= V_14 ;
if ( V_11 . V_17 . V_18 [ 0 ] & (
V_26 |
V_27 ) )
V_7 -> V_12 |= V_15 ;
if ( V_11 . V_17 . V_18 [ 0 ] & (
V_28 |
V_29 |
V_30 |
V_31 ) )
V_7 -> V_12 |= V_16 ;
V_7 -> V_32 = F_1 ( V_11 . V_33 . V_34 ) ;
return 0 ;
}
return - 1 ;
}
void F_6 ( struct V_6 * V_7 ,
struct V_35 * V_36 ,
struct V_8 * V_9 )
{
unsigned int V_37 ;
T_1 V_38 , V_39 , V_40 ;
struct V_41 * V_42 ;
struct V_43 * V_44 ;
struct V_45 V_46 ;
V_38 = 0 ;
V_39 = 0 ;
V_40 = 0 ;
V_44 = (struct V_43 * ) V_36 ;
memset ( V_44 , 0 , sizeof( * V_44 ) ) ;
F_7 (cpu) {
V_42 = F_8 ( V_7 -> V_42 , V_37 ) ;
V_38 += V_42 -> V_47 ;
V_39 += V_42 -> V_48 ;
V_40 += V_42 -> V_49 ;
}
V_44 -> V_50 = F_9 ( V_38 ) ;
V_44 -> V_51 = F_9 ( V_39 ) ;
V_44 -> V_52 = F_9 ( V_40 ) ;
V_44 -> V_53 =
F_9 ( F_10 ( V_9 , & V_46 ) -> V_54 ) ;
}
void F_11 ( struct V_6 * V_7 ,
struct V_35 * V_36 )
{
struct V_8 * V_9 = F_4 ( V_7 ) ;
F_6 ( V_7 , V_36 , V_9 ) ;
}
void F_12 ( struct V_55 * V_56 )
{
struct V_57 * V_58 = F_13 ( V_56 ) ;
struct V_8 * V_9 = F_4 ( V_58 -> V_59 ) ;
struct V_35 * V_36 ;
V_36 = (struct V_35 * ) ( & V_56 -> V_44 ) ;
F_6 ( V_58 -> V_59 , V_36 , V_9 ) ;
}
void F_14 ( T_2 V_60 , char * V_61 , int V_62 )
{
T_3 V_63 [ 8 ] ;
F_15 ( V_60 , V_63 ) ;
snprintf ( V_61 , V_62 , L_1 ,
V_63 [ 0 ] , V_63 [ 1 ] , V_63 [ 2 ] , V_63 [ 3 ] ,
V_63 [ 4 ] , V_63 [ 5 ] , V_63 [ 6 ] , V_63 [ 7 ] ) ;
}
int F_16 ( struct V_64 * V_65 )
{
struct V_66 * V_67 = F_17 ( V_65 ) ;
struct V_6 * V_68 = F_18 ( V_67 ) ;
struct V_6 * V_69 ;
int V_70 = 0 ;
char V_61 [ 32 ] ;
F_19 ( & V_68 -> V_71 ) ;
F_14 ( V_65 -> V_72 , V_61 , sizeof( V_61 ) ) ;
if ( ! memcmp ( & V_68 -> V_63 , & V_65 -> V_72 , sizeof( T_2 ) ) ) {
F_20 ( L_2
L_3 , V_61 ) ;
V_70 = - V_73 ;
goto V_74;
}
F_21 (vn_port, &n_port->vports, list) {
if ( ! memcmp ( & V_69 -> V_63 , & V_65 -> V_72 , sizeof( T_2 ) ) ) {
F_20 ( L_4
L_5 , V_61 ) ;
V_70 = - V_73 ;
break;
}
}
V_74:
F_22 ( & V_68 -> V_71 ) ;
return V_70 ;
}
int F_23 ( struct V_8 * V_9 , T_2 * V_60 , int type )
{
const struct V_75 * V_76 = V_9 -> V_77 ;
if ( V_76 -> V_78 )
return V_76 -> V_78 ( V_9 , V_60 , type ) ;
return - V_73 ;
}
T_1 F_24 ( struct V_79 * V_80 )
{
struct V_81 * V_82 = F_25 ( V_80 ) ;
struct V_83 * V_84 ;
unsigned char * V_85 ;
unsigned long V_86 , V_62 , V_87 ;
T_1 V_88 ;
unsigned V_2 ;
V_88 = F_26 ( ~ 0 , V_82 -> V_85 , F_27 ( V_82 ) ) ;
for ( V_2 = 0 ; V_2 < F_28 ( V_82 ) -> V_89 ; V_2 ++ ) {
V_84 = & F_28 ( V_82 ) -> V_90 [ V_2 ] ;
V_86 = V_84 -> V_91 ;
V_62 = F_29 ( V_84 ) ;
while ( V_62 > 0 ) {
V_87 = F_30 ( V_62 , V_92 - ( V_86 & ~ V_93 ) ) ;
V_85 = F_31 (
F_32 ( V_84 ) + ( V_86 >> V_94 ) ) ;
V_88 = F_26 ( V_88 , V_85 + ( V_86 & ~ V_93 ) , V_87 ) ;
F_33 ( V_85 ) ;
V_86 += V_87 ;
V_62 -= V_87 ;
}
}
return V_88 ;
}
int F_34 ( struct V_81 * V_82 )
{
struct V_81 * V_95 ;
int V_70 ;
V_95 = F_35 ( V_82 , V_96 ) ;
if ( ! V_95 )
return - V_97 ;
V_70 = F_36 ( V_95 ) ;
if ( V_70 != 0 )
return V_70 ;
F_37 ( V_82 ) ;
return 0 ;
}
void F_38 ( struct V_6 * V_7 )
{
struct V_98 * V_99 = F_39 ( V_7 ) ;
struct V_81 * V_82 ;
F_40 ( & V_99 -> V_100 . V_101 ) ;
while ( ( V_82 = F_41 ( & V_99 -> V_100 ) ) != NULL ) {
F_42 ( & V_99 -> V_100 . V_101 ) ;
F_37 ( V_82 ) ;
F_40 ( & V_99 -> V_100 . V_101 ) ;
}
F_42 ( & V_99 -> V_100 . V_101 ) ;
}
void F_43 ( struct V_6 * V_7 , struct V_81 * V_82 )
{
struct V_98 * V_99 = F_39 ( V_7 ) ;
int V_70 ;
F_40 ( & V_99 -> V_100 . V_101 ) ;
if ( V_82 )
F_44 ( & V_99 -> V_100 , V_82 ) ;
if ( V_99 -> V_102 )
goto V_74;
V_99 -> V_102 = 1 ;
while ( V_99 -> V_100 . V_103 ) {
V_99 -> V_100 . V_103 ++ ;
V_82 = F_41 ( & V_99 -> V_100 ) ;
F_42 ( & V_99 -> V_100 . V_101 ) ;
V_70 = F_34 ( V_82 ) ;
F_40 ( & V_99 -> V_100 . V_101 ) ;
if ( V_70 ) {
F_45 ( & V_99 -> V_100 , V_82 ) ;
V_99 -> V_100 . V_103 -- ;
break;
}
V_99 -> V_100 . V_103 -- ;
}
if ( V_99 -> V_100 . V_103 < V_99 -> V_104 )
V_7 -> V_105 = 0 ;
if ( V_99 -> V_100 . V_103 && ! F_46 ( & V_99 -> V_106 ) )
F_47 ( & V_99 -> V_106 , V_107 + 2 ) ;
V_99 -> V_102 = 0 ;
V_74:
if ( V_99 -> V_100 . V_103 > V_99 -> V_108 )
V_7 -> V_105 = 1 ;
F_42 ( & V_99 -> V_100 . V_101 ) ;
}
void F_48 ( T_4 V_7 )
{
F_43 ( (struct V_6 * ) V_7 , NULL ) ;
}
int F_49 ( struct V_81 * V_82 , int V_109 ,
struct V_110 * V_111 )
{
struct V_112 * V_112 ;
V_112 = V_111 -> V_113 ;
if ( ! V_112 ) {
V_112 = F_50 ( V_96 ) ;
if ( ! V_112 )
return - V_97 ;
V_111 -> V_113 = V_112 ;
V_111 -> V_114 = 0 ;
}
F_51 ( V_112 ) ;
F_52 ( V_82 , F_28 ( V_82 ) -> V_89 , V_112 ,
V_111 -> V_114 , V_109 ) ;
V_82 -> V_62 += V_109 ;
V_82 -> V_115 += V_109 ;
V_82 -> V_116 += V_109 ;
V_111 -> V_114 += sizeof( struct V_117 ) ;
if ( V_111 -> V_114 >= V_92 ) {
V_111 -> V_113 = NULL ;
V_111 -> V_114 = 0 ;
F_53 ( V_112 ) ;
}
return 0 ;
}
static struct V_118 * F_54 ( struct V_8 * V_9 )
{
struct V_118 * V_119 = NULL ;
F_21 (ft, &fcoe_transports, list)
if ( V_119 -> V_120 && V_119 -> V_120 ( V_9 ) )
return V_119 ;
return NULL ;
}
int F_55 ( struct V_118 * V_119 )
{
int V_70 = 0 ;
F_19 ( & V_121 ) ;
if ( V_119 -> V_122 ) {
F_20 ( L_6 ,
V_119 -> V_123 ) ;
V_70 = - V_124 ;
goto V_125;
}
if ( strcmp ( V_119 -> V_123 , V_126 ) )
F_56 ( & V_119 -> V_127 , & V_128 ) ;
else
F_57 ( & V_119 -> V_127 , & V_128 ) ;
V_119 -> V_122 = true ;
F_20 ( L_7 , V_119 -> V_123 ) ;
V_125:
F_22 ( & V_121 ) ;
return V_70 ;
}
int F_58 ( struct V_118 * V_119 )
{
int V_70 = 0 ;
struct V_129 * V_130 = NULL , * V_131 ;
F_19 ( & V_121 ) ;
if ( ! V_119 -> V_122 ) {
F_20 ( L_8 ,
V_119 -> V_123 ) ;
V_70 = - V_132 ;
goto V_125;
}
F_19 ( & V_133 ) ;
F_59 (nm, tmp, &fcoe_netdevs, list) {
if ( V_130 -> V_119 == V_119 ) {
F_20 ( L_9
L_10 ,
V_119 -> V_123 , V_130 -> V_9 -> V_123 ) ;
F_60 ( & V_130 -> V_127 ) ;
F_61 ( V_130 ) ;
}
}
F_22 ( & V_133 ) ;
F_60 ( & V_119 -> V_127 ) ;
V_119 -> V_122 = false ;
F_20 ( L_11 , V_119 -> V_123 ) ;
V_125:
F_22 ( & V_121 ) ;
return V_70 ;
}
static int F_62 ( char * V_134 , const struct V_135 * V_136 )
{
int V_2 , V_137 ;
struct V_118 * V_119 = NULL ;
V_2 = V_137 = sprintf ( V_134 , L_12 ) ;
F_19 ( & V_121 ) ;
F_21 (ft, &fcoe_transports, list) {
if ( V_2 >= V_92 - V_138 )
break;
V_2 += snprintf ( & V_134 [ V_2 ] , V_138 , L_13 , V_119 -> V_123 ) ;
}
F_22 ( & V_121 ) ;
if ( V_2 == V_137 )
V_2 += snprintf ( & V_134 [ V_2 ] , V_138 , L_14 ) ;
return V_2 ;
}
static int T_5 F_63 ( void )
{
F_64 ( & V_139 ) ;
return 0 ;
}
static int F_65 ( void )
{
struct V_118 * V_119 ;
F_66 ( & V_139 ) ;
F_19 ( & V_121 ) ;
F_21 (ft, &fcoe_transports, list)
F_67 ( V_140 L_15 ,
V_119 -> V_123 ) ;
F_22 ( & V_121 ) ;
return 0 ;
}
static int F_68 ( struct V_8 * V_9 ,
struct V_118 * V_119 )
{
struct V_129 * V_130 ;
V_130 = F_69 ( sizeof( * V_130 ) , V_141 ) ;
if ( ! V_130 ) {
F_67 ( V_140 L_16 ) ;
return - V_97 ;
}
V_130 -> V_9 = V_9 ;
V_130 -> V_119 = V_119 ;
F_19 ( & V_133 ) ;
F_56 ( & V_130 -> V_127 , & V_142 ) ;
F_22 ( & V_133 ) ;
return 0 ;
}
static void F_70 ( struct V_8 * V_9 )
{
struct V_129 * V_130 = NULL , * V_131 ;
F_19 ( & V_133 ) ;
F_59 (nm, tmp, &fcoe_netdevs, list) {
if ( V_130 -> V_9 == V_9 ) {
F_60 ( & V_130 -> V_127 ) ;
F_61 ( V_130 ) ;
F_22 ( & V_133 ) ;
return;
}
}
F_22 ( & V_133 ) ;
}
static struct V_118 * F_71 ( struct V_8 * V_9 )
{
struct V_118 * V_119 = NULL ;
struct V_129 * V_130 ;
F_19 ( & V_133 ) ;
F_21 (nm, &fcoe_netdevs, list) {
if ( V_9 == V_130 -> V_9 ) {
V_119 = V_130 -> V_119 ;
F_22 ( & V_133 ) ;
return V_119 ;
}
}
F_22 ( & V_133 ) ;
return NULL ;
}
static struct V_8 * F_72 ( const char * V_134 )
{
char * V_143 ;
char V_144 [ V_138 + 2 ] ;
if ( V_134 ) {
F_73 ( V_144 , V_134 , V_138 ) ;
V_143 = V_144 + strlen ( V_144 ) ;
while ( -- V_143 >= V_144 && * V_143 == '\n' )
* V_143 = '\0' ;
return F_74 ( & V_145 , V_144 ) ;
}
return NULL ;
}
static int F_75 ( struct V_146 * V_147 ,
T_4 V_148 , void * V_149 )
{
struct V_8 * V_9 = F_76 ( V_149 ) ;
switch ( V_148 ) {
case V_150 :
F_20 ( L_17 ,
V_9 -> V_123 ) ;
F_70 ( V_9 ) ;
break;
}
return V_151 ;
}
T_6 F_77 ( struct V_152 * V_153 ,
const char * V_61 , T_7 V_154 )
{
struct V_8 * V_9 = NULL ;
struct V_118 * V_119 = NULL ;
int V_70 = 0 ;
int V_155 ;
F_19 ( & V_121 ) ;
V_9 = F_72 ( V_61 ) ;
if ( ! V_9 ) {
F_20 ( L_18 , V_61 ) ;
V_70 = - V_132 ;
goto V_156;
}
V_119 = F_71 ( V_9 ) ;
if ( V_119 ) {
F_20 ( L_19
L_20 ,
V_119 -> V_123 , V_9 -> V_123 ) ;
V_70 = - V_124 ;
goto V_157;
}
V_119 = F_54 ( V_9 ) ;
if ( ! V_119 ) {
F_20 ( L_21 ,
V_9 -> V_123 ) ;
V_70 = - V_132 ;
goto V_157;
}
V_155 = V_119 -> V_158 ? V_119 -> V_158 ( V_9 ) : - V_132 ;
if ( V_155 ) {
F_70 ( V_9 ) ;
V_70 = - V_97 ;
goto V_157;
}
V_155 = F_68 ( V_9 , V_119 ) ;
if ( V_155 ) {
F_20 ( L_22
L_23 ,
V_119 -> V_123 , V_9 -> V_123 ) ;
V_70 = - V_132 ;
goto V_157;
}
F_20 ( L_24 ,
V_119 -> V_123 , V_9 -> V_123 ) ;
V_157:
F_78 ( V_9 ) ;
V_156:
F_22 ( & V_121 ) ;
if ( V_70 )
return V_70 ;
return V_154 ;
}
T_6 F_79 ( struct V_152 * V_153 ,
const char * V_61 , T_7 V_154 )
{
int V_70 = - V_132 ;
struct V_8 * V_9 = NULL ;
struct V_118 * V_119 = NULL ;
F_19 ( & V_121 ) ;
V_9 = F_72 ( V_61 ) ;
if ( ! V_9 ) {
F_20 ( L_25 , V_61 ) ;
goto V_156;
}
V_119 = F_71 ( V_9 ) ;
if ( ! V_119 ) {
F_20 ( L_21 ,
V_9 -> V_123 ) ;
goto V_157;
}
V_70 = V_119 -> V_159 ( V_9 ) ;
if ( V_70 )
goto V_157;
F_70 ( V_9 ) ;
F_20 ( L_26 ,
V_119 -> V_123 , ( V_70 ) ? L_27 : L_28 ,
V_9 -> V_123 ) ;
V_70 = V_154 ;
V_157:
F_78 ( V_9 ) ;
V_156:
F_22 ( & V_121 ) ;
return V_70 ;
}
static int F_80 ( const char * V_134 , struct V_135 * V_136 )
{
int V_70 = - V_132 ;
struct V_8 * V_9 = NULL ;
struct V_118 * V_119 = NULL ;
enum V_160 V_161 = (enum V_160 ) ( long ) V_136 -> V_162 ;
F_19 ( & V_121 ) ;
V_9 = F_72 ( V_134 ) ;
if ( ! V_9 ) {
F_20 ( L_18 , V_134 ) ;
goto V_156;
}
V_119 = F_71 ( V_9 ) ;
if ( V_119 ) {
F_20 ( L_19
L_20 ,
V_119 -> V_123 , V_9 -> V_123 ) ;
V_70 = - V_124 ;
goto V_157;
}
V_119 = F_54 ( V_9 ) ;
if ( ! V_119 ) {
F_20 ( L_21 ,
V_9 -> V_123 ) ;
goto V_157;
}
V_70 = F_68 ( V_9 , V_119 ) ;
if ( V_70 ) {
F_20 ( L_22
L_23 ,
V_119 -> V_123 , V_9 -> V_123 ) ;
goto V_157;
}
V_70 = V_119 -> V_163 ? V_119 -> V_163 ( V_9 , V_161 ) : - V_132 ;
if ( V_70 )
F_70 ( V_9 ) ;
F_20 ( L_29 ,
V_119 -> V_123 , ( V_70 ) ? L_27 : L_28 ,
V_9 -> V_123 ) ;
V_157:
F_78 ( V_9 ) ;
V_156:
F_22 ( & V_121 ) ;
return V_70 ;
}
static int F_81 ( const char * V_134 , struct V_135 * V_136 )
{
int V_70 = - V_132 ;
struct V_8 * V_9 = NULL ;
struct V_118 * V_119 = NULL ;
F_19 ( & V_121 ) ;
V_9 = F_72 ( V_134 ) ;
if ( ! V_9 ) {
F_20 ( L_25 , V_134 ) ;
goto V_156;
}
V_119 = F_71 ( V_9 ) ;
if ( ! V_119 ) {
F_20 ( L_21 ,
V_9 -> V_123 ) ;
goto V_157;
}
V_70 = V_119 -> V_159 ? V_119 -> V_159 ( V_9 ) : - V_132 ;
F_70 ( V_9 ) ;
F_20 ( L_26 ,
V_119 -> V_123 , ( V_70 ) ? L_27 : L_28 ,
V_9 -> V_123 ) ;
V_157:
F_78 ( V_9 ) ;
V_156:
F_22 ( & V_121 ) ;
return V_70 ;
}
static int F_82 ( const char * V_134 , struct V_135 * V_136 )
{
int V_70 = - V_132 ;
struct V_8 * V_9 = NULL ;
struct V_118 * V_119 = NULL ;
F_19 ( & V_121 ) ;
V_9 = F_72 ( V_134 ) ;
if ( ! V_9 )
goto V_156;
V_119 = F_71 ( V_9 ) ;
if ( ! V_119 )
goto V_157;
V_70 = V_119 -> V_164 ? V_119 -> V_164 ( V_9 ) : - V_132 ;
V_157:
F_78 ( V_9 ) ;
V_156:
F_22 ( & V_121 ) ;
return V_70 ;
}
static int F_83 ( const char * V_134 , struct V_135 * V_136 )
{
int V_70 = - V_132 ;
struct V_8 * V_9 = NULL ;
struct V_118 * V_119 = NULL ;
F_19 ( & V_121 ) ;
V_9 = F_72 ( V_134 ) ;
if ( ! V_9 )
goto V_156;
V_119 = F_71 ( V_9 ) ;
if ( ! V_119 )
goto V_157;
V_70 = V_119 -> V_165 ? V_119 -> V_165 ( V_9 ) : - V_132 ;
V_157:
F_78 ( V_9 ) ;
V_156:
F_22 ( & V_121 ) ;
return V_70 ;
}
static int T_5 F_84 ( void )
{
int V_70 = 0 ;
V_70 = F_63 () ;
if ( V_70 )
return V_70 ;
V_70 = F_85 () ;
if ( V_70 )
F_65 () ;
return V_70 ;
}
static void T_8 F_86 ( void )
{
F_87 () ;
F_65 () ;
}
