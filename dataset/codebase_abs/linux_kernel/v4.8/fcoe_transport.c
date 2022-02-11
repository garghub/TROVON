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
case V_32 :
V_2 -> V_30 = V_10 ;
break;
case V_33 :
V_2 -> V_30 = V_11 ;
break;
default:
V_2 -> V_30 = V_34 ;
break;
}
return 0 ;
}
return - 1 ;
}
void F_4 ( struct V_1 * V_2 ,
struct V_35 * V_36 ,
struct V_3 * V_4 )
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
F_5 (cpu) {
V_42 = F_6 ( V_2 -> V_42 , V_37 ) ;
V_38 += V_42 -> V_47 ;
V_39 += V_42 -> V_48 ;
V_40 += V_42 -> V_49 ;
}
V_44 -> V_50 = F_7 ( V_38 ) ;
V_44 -> V_51 = F_7 ( V_39 ) ;
V_44 -> V_52 = F_7 ( V_40 ) ;
V_44 -> V_53 =
F_7 ( F_8 ( V_4 , & V_46 ) -> V_54 ) ;
}
void F_9 ( struct V_1 * V_2 ,
struct V_35 * V_36 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
F_4 ( V_2 , V_36 , V_4 ) ;
}
void F_10 ( struct V_55 * V_56 )
{
struct V_57 * V_58 = F_11 ( V_56 ) ;
struct V_3 * V_4 = F_2 ( V_58 -> V_59 ) ;
struct V_35 * V_36 ;
V_36 = (struct V_35 * ) ( & V_56 -> V_44 ) ;
F_4 ( V_58 -> V_59 , V_36 , V_4 ) ;
}
void F_12 ( T_2 V_60 , char * V_61 , int V_62 )
{
T_3 V_63 [ 8 ] ;
F_13 ( V_60 , V_63 ) ;
snprintf ( V_61 , V_62 , L_1 ,
V_63 [ 0 ] , V_63 [ 1 ] , V_63 [ 2 ] , V_63 [ 3 ] ,
V_63 [ 4 ] , V_63 [ 5 ] , V_63 [ 6 ] , V_63 [ 7 ] ) ;
}
int F_14 ( struct V_64 * V_65 )
{
struct V_66 * V_67 = F_15 ( V_65 ) ;
struct V_1 * V_68 = F_16 ( V_67 ) ;
struct V_1 * V_69 ;
int V_70 = 0 ;
char V_61 [ 32 ] ;
F_17 ( & V_68 -> V_71 ) ;
F_12 ( V_65 -> V_72 , V_61 , sizeof( V_61 ) ) ;
if ( ! memcmp ( & V_68 -> V_63 , & V_65 -> V_72 , sizeof( T_2 ) ) ) {
F_18 ( L_2
L_3 , V_61 ) ;
V_70 = - V_73 ;
goto V_74;
}
F_19 (vn_port, &n_port->vports, list) {
if ( ! memcmp ( & V_69 -> V_63 , & V_65 -> V_72 , sizeof( T_2 ) ) ) {
F_18 ( L_4
L_5 , V_61 ) ;
V_70 = - V_73 ;
break;
}
}
V_74:
F_20 ( & V_68 -> V_71 ) ;
return V_70 ;
}
int F_21 ( struct V_3 * V_4 , T_2 * V_60 , int type )
{
const struct V_75 * V_76 = V_4 -> V_77 ;
if ( V_76 -> V_78 )
return V_76 -> V_78 ( V_4 , V_60 , type ) ;
return - V_73 ;
}
T_1 F_22 ( struct V_79 * V_80 )
{
struct V_81 * V_82 = F_23 ( V_80 ) ;
struct V_83 * V_84 ;
unsigned char * V_85 ;
unsigned long V_86 , V_62 , V_87 ;
T_1 V_88 ;
unsigned V_89 ;
V_88 = F_24 ( ~ 0 , V_82 -> V_85 , F_25 ( V_82 ) ) ;
for ( V_89 = 0 ; V_89 < F_26 ( V_82 ) -> V_90 ; V_89 ++ ) {
V_84 = & F_26 ( V_82 ) -> V_91 [ V_89 ] ;
V_86 = V_84 -> V_92 ;
V_62 = F_27 ( V_84 ) ;
while ( V_62 > 0 ) {
V_87 = F_28 ( V_62 , V_93 - ( V_86 & ~ V_94 ) ) ;
V_85 = F_29 (
F_30 ( V_84 ) + ( V_86 >> V_95 ) ) ;
V_88 = F_24 ( V_88 , V_85 + ( V_86 & ~ V_94 ) , V_87 ) ;
F_31 ( V_85 ) ;
V_86 += V_87 ;
V_62 -= V_87 ;
}
}
return V_88 ;
}
int F_32 ( struct V_81 * V_82 )
{
struct V_81 * V_96 ;
int V_70 ;
V_96 = F_33 ( V_82 , V_97 ) ;
if ( ! V_96 )
return - V_98 ;
V_70 = F_34 ( V_96 ) ;
if ( V_70 != 0 )
return V_70 ;
F_35 ( V_82 ) ;
return 0 ;
}
void F_36 ( struct V_1 * V_2 )
{
struct V_99 * V_100 = F_37 ( V_2 ) ;
struct V_81 * V_82 ;
F_38 ( & V_100 -> V_101 . V_102 ) ;
while ( ( V_82 = F_39 ( & V_100 -> V_101 ) ) != NULL ) {
F_40 ( & V_100 -> V_101 . V_102 ) ;
F_35 ( V_82 ) ;
F_38 ( & V_100 -> V_101 . V_102 ) ;
}
F_40 ( & V_100 -> V_101 . V_102 ) ;
}
void F_41 ( struct V_1 * V_2 , struct V_81 * V_82 )
{
struct V_99 * V_100 = F_37 ( V_2 ) ;
int V_70 ;
F_38 ( & V_100 -> V_101 . V_102 ) ;
if ( V_82 )
F_42 ( & V_100 -> V_101 , V_82 ) ;
if ( V_100 -> V_103 )
goto V_74;
V_100 -> V_103 = 1 ;
while ( V_100 -> V_101 . V_104 ) {
V_100 -> V_101 . V_104 ++ ;
V_82 = F_39 ( & V_100 -> V_101 ) ;
F_40 ( & V_100 -> V_101 . V_102 ) ;
V_70 = F_32 ( V_82 ) ;
F_38 ( & V_100 -> V_101 . V_102 ) ;
if ( V_70 ) {
F_43 ( & V_100 -> V_101 , V_82 ) ;
V_100 -> V_101 . V_104 -- ;
break;
}
V_100 -> V_101 . V_104 -- ;
}
if ( V_100 -> V_101 . V_104 < V_100 -> V_105 )
V_2 -> V_106 = 0 ;
if ( V_100 -> V_101 . V_104 && ! F_44 ( & V_100 -> V_107 ) )
F_45 ( & V_100 -> V_107 , V_108 + 2 ) ;
V_100 -> V_103 = 0 ;
V_74:
if ( V_100 -> V_101 . V_104 > V_100 -> V_109 )
V_2 -> V_106 = 1 ;
F_40 ( & V_100 -> V_101 . V_102 ) ;
}
void F_46 ( T_4 V_2 )
{
F_41 ( (struct V_1 * ) V_2 , NULL ) ;
}
int F_47 ( struct V_81 * V_82 , int V_110 ,
struct V_111 * V_112 )
{
struct V_113 * V_113 ;
V_113 = V_112 -> V_114 ;
if ( ! V_113 ) {
V_113 = F_48 ( V_97 ) ;
if ( ! V_113 )
return - V_98 ;
V_112 -> V_114 = V_113 ;
V_112 -> V_115 = 0 ;
}
F_49 ( V_113 ) ;
F_50 ( V_82 , F_26 ( V_82 ) -> V_90 , V_113 ,
V_112 -> V_115 , V_110 ) ;
V_82 -> V_62 += V_110 ;
V_82 -> V_116 += V_110 ;
V_82 -> V_117 += V_110 ;
V_112 -> V_115 += sizeof( struct V_118 ) ;
if ( V_112 -> V_115 >= V_93 ) {
V_112 -> V_114 = NULL ;
V_112 -> V_115 = 0 ;
F_51 ( V_113 ) ;
}
return 0 ;
}
static struct V_119 * F_52 ( struct V_3 * V_4 )
{
struct V_119 * V_120 = NULL ;
F_19 (ft, &fcoe_transports, list)
if ( V_120 -> V_121 && V_120 -> V_121 ( V_4 ) )
return V_120 ;
return NULL ;
}
int F_53 ( struct V_119 * V_120 )
{
int V_70 = 0 ;
F_17 ( & V_122 ) ;
if ( V_120 -> V_123 ) {
F_18 ( L_6 ,
V_120 -> V_124 ) ;
V_70 = - V_125 ;
goto V_126;
}
if ( strcmp ( V_120 -> V_124 , V_127 ) )
F_54 ( & V_120 -> V_128 , & V_129 ) ;
else
F_55 ( & V_120 -> V_128 , & V_129 ) ;
V_120 -> V_123 = true ;
F_18 ( L_7 , V_120 -> V_124 ) ;
V_126:
F_20 ( & V_122 ) ;
return V_70 ;
}
int F_56 ( struct V_119 * V_120 )
{
int V_70 = 0 ;
struct V_130 * V_131 = NULL , * V_132 ;
F_17 ( & V_122 ) ;
if ( ! V_120 -> V_123 ) {
F_18 ( L_8 ,
V_120 -> V_124 ) ;
V_70 = - V_133 ;
goto V_126;
}
F_17 ( & V_134 ) ;
F_57 (nm, tmp, &fcoe_netdevs, list) {
if ( V_131 -> V_120 == V_120 ) {
F_18 ( L_9
L_10 ,
V_120 -> V_124 , V_131 -> V_4 -> V_124 ) ;
F_58 ( & V_131 -> V_128 ) ;
F_59 ( V_131 ) ;
}
}
F_20 ( & V_134 ) ;
F_58 ( & V_120 -> V_128 ) ;
V_120 -> V_123 = false ;
F_18 ( L_11 , V_120 -> V_124 ) ;
V_126:
F_20 ( & V_122 ) ;
return V_70 ;
}
static int F_60 ( char * V_135 , const struct V_136 * V_137 )
{
int V_89 , V_138 ;
struct V_119 * V_120 = NULL ;
V_89 = V_138 = sprintf ( V_135 , L_12 ) ;
F_17 ( & V_122 ) ;
F_19 (ft, &fcoe_transports, list) {
if ( V_89 >= V_93 - V_139 )
break;
V_89 += snprintf ( & V_135 [ V_89 ] , V_139 , L_13 , V_120 -> V_124 ) ;
}
F_20 ( & V_122 ) ;
if ( V_89 == V_138 )
V_89 += snprintf ( & V_135 [ V_89 ] , V_139 , L_14 ) ;
return V_89 ;
}
static int T_5 F_61 ( void )
{
F_62 ( & V_140 ) ;
return 0 ;
}
static int F_63 ( void )
{
struct V_119 * V_120 ;
F_64 ( & V_140 ) ;
F_17 ( & V_122 ) ;
F_19 (ft, &fcoe_transports, list)
F_65 ( V_141 L_15 ,
V_120 -> V_124 ) ;
F_20 ( & V_122 ) ;
return 0 ;
}
static int F_66 ( struct V_3 * V_4 ,
struct V_119 * V_120 )
{
struct V_130 * V_131 ;
V_131 = F_67 ( sizeof( * V_131 ) , V_142 ) ;
if ( ! V_131 ) {
F_65 ( V_141 L_16 ) ;
return - V_98 ;
}
V_131 -> V_4 = V_4 ;
V_131 -> V_120 = V_120 ;
F_17 ( & V_134 ) ;
F_54 ( & V_131 -> V_128 , & V_143 ) ;
F_20 ( & V_134 ) ;
return 0 ;
}
static void F_68 ( struct V_3 * V_4 )
{
struct V_130 * V_131 = NULL , * V_132 ;
F_17 ( & V_134 ) ;
F_57 (nm, tmp, &fcoe_netdevs, list) {
if ( V_131 -> V_4 == V_4 ) {
F_58 ( & V_131 -> V_128 ) ;
F_59 ( V_131 ) ;
F_20 ( & V_134 ) ;
return;
}
}
F_20 ( & V_134 ) ;
}
static struct V_119 * F_69 ( struct V_3 * V_4 )
{
struct V_119 * V_120 = NULL ;
struct V_130 * V_131 ;
F_17 ( & V_134 ) ;
F_19 (nm, &fcoe_netdevs, list) {
if ( V_4 == V_131 -> V_4 ) {
V_120 = V_131 -> V_120 ;
F_20 ( & V_134 ) ;
return V_120 ;
}
}
F_20 ( & V_134 ) ;
return NULL ;
}
static struct V_3 * F_70 ( const char * V_135 )
{
char * V_144 ;
char V_145 [ V_139 + 2 ] ;
if ( V_135 ) {
F_71 ( V_145 , V_135 , V_139 ) ;
V_144 = V_145 + strlen ( V_145 ) ;
while ( -- V_144 >= V_145 && * V_144 == '\n' )
* V_144 = '\0' ;
return F_72 ( & V_146 , V_145 ) ;
}
return NULL ;
}
static int F_73 ( struct V_147 * V_148 ,
T_4 V_149 , void * V_150 )
{
struct V_3 * V_4 = F_74 ( V_150 ) ;
switch ( V_149 ) {
case V_151 :
F_18 ( L_17 ,
V_4 -> V_124 ) ;
F_68 ( V_4 ) ;
break;
}
return V_152 ;
}
T_6 F_75 ( struct V_153 * V_154 ,
const char * V_61 , T_7 V_155 )
{
struct V_3 * V_4 = NULL ;
struct V_119 * V_120 = NULL ;
int V_70 = 0 ;
int V_156 ;
F_17 ( & V_122 ) ;
V_4 = F_70 ( V_61 ) ;
if ( ! V_4 ) {
F_18 ( L_18 , V_61 ) ;
V_70 = - V_133 ;
goto V_157;
}
V_120 = F_69 ( V_4 ) ;
if ( V_120 ) {
F_18 ( L_19
L_20 ,
V_120 -> V_124 , V_4 -> V_124 ) ;
V_70 = - V_125 ;
goto V_158;
}
V_120 = F_52 ( V_4 ) ;
if ( ! V_120 ) {
F_18 ( L_21 ,
V_4 -> V_124 ) ;
V_70 = - V_133 ;
goto V_158;
}
V_156 = V_120 -> V_159 ? V_120 -> V_159 ( V_4 ) : - V_133 ;
if ( V_156 ) {
F_68 ( V_4 ) ;
V_70 = - V_98 ;
goto V_158;
}
V_156 = F_66 ( V_4 , V_120 ) ;
if ( V_156 ) {
F_18 ( L_22
L_23 ,
V_120 -> V_124 , V_4 -> V_124 ) ;
V_70 = - V_133 ;
goto V_158;
}
F_18 ( L_24 ,
V_120 -> V_124 , V_4 -> V_124 ) ;
V_158:
F_76 ( V_4 ) ;
V_157:
F_20 ( & V_122 ) ;
if ( V_70 )
return V_70 ;
return V_155 ;
}
T_6 F_77 ( struct V_153 * V_154 ,
const char * V_61 , T_7 V_155 )
{
int V_70 = - V_133 ;
struct V_3 * V_4 = NULL ;
struct V_119 * V_120 = NULL ;
F_17 ( & V_122 ) ;
V_4 = F_70 ( V_61 ) ;
if ( ! V_4 ) {
F_18 ( L_25 , V_61 ) ;
goto V_157;
}
V_120 = F_69 ( V_4 ) ;
if ( ! V_120 ) {
F_18 ( L_21 ,
V_4 -> V_124 ) ;
goto V_158;
}
V_70 = V_120 -> V_160 ( V_4 ) ;
if ( V_70 )
goto V_158;
F_68 ( V_4 ) ;
F_18 ( L_26 ,
V_120 -> V_124 , ( V_70 ) ? L_27 : L_28 ,
V_4 -> V_124 ) ;
V_70 = V_155 ;
V_158:
F_76 ( V_4 ) ;
V_157:
F_20 ( & V_122 ) ;
return V_70 ;
}
static int F_78 ( const char * V_135 , struct V_136 * V_137 )
{
int V_70 = - V_133 ;
struct V_3 * V_4 = NULL ;
struct V_119 * V_120 = NULL ;
enum V_161 V_162 = (enum V_161 ) ( long ) V_137 -> V_163 ;
F_17 ( & V_122 ) ;
V_4 = F_70 ( V_135 ) ;
if ( ! V_4 ) {
F_18 ( L_18 , V_135 ) ;
goto V_157;
}
V_120 = F_69 ( V_4 ) ;
if ( V_120 ) {
F_18 ( L_19
L_20 ,
V_120 -> V_124 , V_4 -> V_124 ) ;
V_70 = - V_125 ;
goto V_158;
}
V_120 = F_52 ( V_4 ) ;
if ( ! V_120 ) {
F_18 ( L_21 ,
V_4 -> V_124 ) ;
goto V_158;
}
V_70 = F_66 ( V_4 , V_120 ) ;
if ( V_70 ) {
F_18 ( L_22
L_23 ,
V_120 -> V_124 , V_4 -> V_124 ) ;
goto V_158;
}
V_70 = V_120 -> V_164 ? V_120 -> V_164 ( V_4 , V_162 ) : - V_133 ;
if ( V_70 )
F_68 ( V_4 ) ;
F_18 ( L_29 ,
V_120 -> V_124 , ( V_70 ) ? L_27 : L_28 ,
V_4 -> V_124 ) ;
V_158:
F_76 ( V_4 ) ;
V_157:
F_20 ( & V_122 ) ;
return V_70 ;
}
static int F_79 ( const char * V_135 , struct V_136 * V_137 )
{
int V_70 = - V_133 ;
struct V_3 * V_4 = NULL ;
struct V_119 * V_120 = NULL ;
F_17 ( & V_122 ) ;
V_4 = F_70 ( V_135 ) ;
if ( ! V_4 ) {
F_18 ( L_25 , V_135 ) ;
goto V_157;
}
V_120 = F_69 ( V_4 ) ;
if ( ! V_120 ) {
F_18 ( L_21 ,
V_4 -> V_124 ) ;
goto V_158;
}
V_70 = V_120 -> V_160 ? V_120 -> V_160 ( V_4 ) : - V_133 ;
F_68 ( V_4 ) ;
F_18 ( L_26 ,
V_120 -> V_124 , ( V_70 ) ? L_27 : L_28 ,
V_4 -> V_124 ) ;
V_158:
F_76 ( V_4 ) ;
V_157:
F_20 ( & V_122 ) ;
return V_70 ;
}
static int F_80 ( const char * V_135 , struct V_136 * V_137 )
{
int V_70 = - V_133 ;
struct V_3 * V_4 = NULL ;
struct V_119 * V_120 = NULL ;
F_17 ( & V_122 ) ;
V_4 = F_70 ( V_135 ) ;
if ( ! V_4 )
goto V_157;
V_120 = F_69 ( V_4 ) ;
if ( ! V_120 )
goto V_158;
V_70 = V_120 -> V_165 ? V_120 -> V_165 ( V_4 ) : - V_133 ;
V_158:
F_76 ( V_4 ) ;
V_157:
F_20 ( & V_122 ) ;
return V_70 ;
}
static int F_81 ( const char * V_135 , struct V_136 * V_137 )
{
int V_70 = - V_133 ;
struct V_3 * V_4 = NULL ;
struct V_119 * V_120 = NULL ;
F_17 ( & V_122 ) ;
V_4 = F_70 ( V_135 ) ;
if ( ! V_4 )
goto V_157;
V_120 = F_69 ( V_4 ) ;
if ( ! V_120 )
goto V_158;
V_70 = V_120 -> V_166 ? V_120 -> V_166 ( V_4 ) : - V_133 ;
V_158:
F_76 ( V_4 ) ;
V_157:
F_20 ( & V_122 ) ;
return V_70 ;
}
static int T_5 F_82 ( void )
{
int V_70 = 0 ;
V_70 = F_61 () ;
if ( V_70 )
return V_70 ;
V_70 = F_83 () ;
if ( V_70 )
F_63 () ;
return V_70 ;
}
static void T_8 F_84 ( void )
{
F_85 () ;
F_63 () ;
}
