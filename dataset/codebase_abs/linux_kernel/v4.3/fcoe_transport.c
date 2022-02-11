int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_5 V_6 ;
if ( ! F_3 ( V_4 , & V_6 ) ) {
V_2 -> V_7 &= ~ ( V_8 |
V_9 |
V_10 |
V_11 ) ;
if ( V_6 . V_12 & ( V_13 |
V_14 |
V_15 ) )
V_2 -> V_7 |= V_8 ;
if ( V_6 . V_12 & ( V_16 |
V_17 |
V_18 |
V_19 ) )
V_2 -> V_7 |= V_9 ;
if ( V_6 . V_12 & ( V_20 |
V_21 ) )
V_2 -> V_7 |= V_10 ;
if ( V_6 . V_12 & ( V_22 |
V_23 |
V_24 |
V_25 ) )
V_2 -> V_7 |= V_11 ;
switch ( F_4 ( & V_6 ) ) {
case V_26 :
V_2 -> V_27 = V_8 ;
break;
case V_28 :
V_2 -> V_27 = V_9 ;
break;
case 20000 :
V_2 -> V_27 = V_10 ;
break;
case 40000 :
V_2 -> V_27 = V_11 ;
break;
default:
V_2 -> V_27 = V_29 ;
break;
}
return 0 ;
}
return - 1 ;
}
void F_5 ( struct V_1 * V_2 ,
struct V_30 * V_31 ,
struct V_3 * V_4 )
{
unsigned int V_32 ;
T_1 V_33 , V_34 , V_35 ;
struct V_36 * V_37 ;
struct V_38 * V_39 ;
struct V_40 V_41 ;
V_33 = 0 ;
V_34 = 0 ;
V_35 = 0 ;
V_39 = (struct V_38 * ) V_31 ;
memset ( V_39 , 0 , sizeof( * V_39 ) ) ;
F_6 (cpu) {
V_37 = F_7 ( V_2 -> V_37 , V_32 ) ;
V_33 += V_37 -> V_42 ;
V_34 += V_37 -> V_43 ;
V_35 += V_37 -> V_44 ;
}
V_39 -> V_45 = F_8 ( V_33 ) ;
V_39 -> V_46 = F_8 ( V_34 ) ;
V_39 -> V_47 = F_8 ( V_35 ) ;
V_39 -> V_48 =
F_8 ( F_9 ( V_4 , & V_41 ) -> V_49 ) ;
}
void F_10 ( struct V_1 * V_2 ,
struct V_30 * V_31 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
F_5 ( V_2 , V_31 , V_4 ) ;
}
void F_11 ( struct V_50 * V_51 )
{
struct V_52 * V_53 = F_12 ( V_51 ) ;
struct V_3 * V_4 = F_2 ( V_53 -> V_54 ) ;
struct V_30 * V_31 ;
V_31 = (struct V_30 * ) ( & V_51 -> V_39 ) ;
F_5 ( V_53 -> V_54 , V_31 , V_4 ) ;
}
void F_13 ( T_2 V_55 , char * V_56 , int V_57 )
{
T_3 V_58 [ 8 ] ;
F_14 ( V_55 , V_58 ) ;
snprintf ( V_56 , V_57 , L_1 ,
V_58 [ 0 ] , V_58 [ 1 ] , V_58 [ 2 ] , V_58 [ 3 ] ,
V_58 [ 4 ] , V_58 [ 5 ] , V_58 [ 6 ] , V_58 [ 7 ] ) ;
}
int F_15 ( struct V_59 * V_60 )
{
struct V_61 * V_62 = F_16 ( V_60 ) ;
struct V_1 * V_63 = F_17 ( V_62 ) ;
struct V_1 * V_64 ;
int V_65 = 0 ;
char V_56 [ 32 ] ;
F_18 ( & V_63 -> V_66 ) ;
F_13 ( V_60 -> V_67 , V_56 , sizeof( V_56 ) ) ;
if ( ! memcmp ( & V_63 -> V_58 , & V_60 -> V_67 , sizeof( T_2 ) ) ) {
F_19 ( L_2
L_3 , V_56 ) ;
V_65 = - V_68 ;
goto V_69;
}
F_20 (vn_port, &n_port->vports, list) {
if ( ! memcmp ( & V_64 -> V_58 , & V_60 -> V_67 , sizeof( T_2 ) ) ) {
F_19 ( L_4
L_5 , V_56 ) ;
V_65 = - V_68 ;
break;
}
}
V_69:
F_21 ( & V_63 -> V_66 ) ;
return V_65 ;
}
int F_22 ( struct V_3 * V_4 , T_2 * V_55 , int type )
{
const struct V_70 * V_71 = V_4 -> V_72 ;
if ( V_71 -> V_73 )
return V_71 -> V_73 ( V_4 , V_55 , type ) ;
return - V_68 ;
}
T_1 F_23 ( struct V_74 * V_75 )
{
struct V_76 * V_77 = F_24 ( V_75 ) ;
struct V_78 * V_79 ;
unsigned char * V_80 ;
unsigned long V_81 , V_57 , V_82 ;
T_1 V_83 ;
unsigned V_84 ;
V_83 = F_25 ( ~ 0 , V_77 -> V_80 , F_26 ( V_77 ) ) ;
for ( V_84 = 0 ; V_84 < F_27 ( V_77 ) -> V_85 ; V_84 ++ ) {
V_79 = & F_27 ( V_77 ) -> V_86 [ V_84 ] ;
V_81 = V_79 -> V_87 ;
V_57 = F_28 ( V_79 ) ;
while ( V_57 > 0 ) {
V_82 = F_29 ( V_57 , V_88 - ( V_81 & ~ V_89 ) ) ;
V_80 = F_30 (
F_31 ( V_79 ) + ( V_81 >> V_90 ) ) ;
V_83 = F_25 ( V_83 , V_80 + ( V_81 & ~ V_89 ) , V_82 ) ;
F_32 ( V_80 ) ;
V_81 += V_82 ;
V_57 -= V_82 ;
}
}
return V_83 ;
}
int F_33 ( struct V_76 * V_77 )
{
struct V_76 * V_91 ;
int V_65 ;
V_91 = F_34 ( V_77 , V_92 ) ;
if ( ! V_91 )
return - V_93 ;
V_65 = F_35 ( V_91 ) ;
if ( V_65 != 0 )
return V_65 ;
F_36 ( V_77 ) ;
return 0 ;
}
void F_37 ( struct V_1 * V_2 )
{
struct V_94 * V_95 = F_38 ( V_2 ) ;
struct V_76 * V_77 ;
F_39 ( & V_95 -> V_96 . V_97 ) ;
while ( ( V_77 = F_40 ( & V_95 -> V_96 ) ) != NULL ) {
F_41 ( & V_95 -> V_96 . V_97 ) ;
F_36 ( V_77 ) ;
F_39 ( & V_95 -> V_96 . V_97 ) ;
}
F_41 ( & V_95 -> V_96 . V_97 ) ;
}
void F_42 ( struct V_1 * V_2 , struct V_76 * V_77 )
{
struct V_94 * V_95 = F_38 ( V_2 ) ;
int V_65 ;
F_39 ( & V_95 -> V_96 . V_97 ) ;
if ( V_77 )
F_43 ( & V_95 -> V_96 , V_77 ) ;
if ( V_95 -> V_98 )
goto V_69;
V_95 -> V_98 = 1 ;
while ( V_95 -> V_96 . V_99 ) {
V_95 -> V_96 . V_99 ++ ;
V_77 = F_40 ( & V_95 -> V_96 ) ;
F_41 ( & V_95 -> V_96 . V_97 ) ;
V_65 = F_33 ( V_77 ) ;
F_39 ( & V_95 -> V_96 . V_97 ) ;
if ( V_65 ) {
F_44 ( & V_95 -> V_96 , V_77 ) ;
V_95 -> V_96 . V_99 -- ;
break;
}
V_95 -> V_96 . V_99 -- ;
}
if ( V_95 -> V_96 . V_99 < V_95 -> V_100 )
V_2 -> V_101 = 0 ;
if ( V_95 -> V_96 . V_99 && ! F_45 ( & V_95 -> V_102 ) )
F_46 ( & V_95 -> V_102 , V_103 + 2 ) ;
V_95 -> V_98 = 0 ;
V_69:
if ( V_95 -> V_96 . V_99 > V_95 -> V_104 )
V_2 -> V_101 = 1 ;
F_41 ( & V_95 -> V_96 . V_97 ) ;
}
void F_47 ( T_4 V_2 )
{
F_42 ( (struct V_1 * ) V_2 , NULL ) ;
}
int F_48 ( struct V_76 * V_77 , int V_105 ,
struct V_106 * V_107 )
{
struct V_108 * V_108 ;
V_108 = V_107 -> V_109 ;
if ( ! V_108 ) {
V_108 = F_49 ( V_92 ) ;
if ( ! V_108 )
return - V_93 ;
V_107 -> V_109 = V_108 ;
V_107 -> V_110 = 0 ;
}
F_50 ( V_108 ) ;
F_51 ( V_77 , F_27 ( V_77 ) -> V_85 , V_108 ,
V_107 -> V_110 , V_105 ) ;
V_77 -> V_57 += V_105 ;
V_77 -> V_111 += V_105 ;
V_77 -> V_112 += V_105 ;
V_107 -> V_110 += sizeof( struct V_113 ) ;
if ( V_107 -> V_110 >= V_88 ) {
V_107 -> V_109 = NULL ;
V_107 -> V_110 = 0 ;
F_52 ( V_108 ) ;
}
return 0 ;
}
static struct V_114 * F_53 ( struct V_3 * V_4 )
{
struct V_114 * V_115 = NULL ;
F_20 (ft, &fcoe_transports, list)
if ( V_115 -> V_116 && V_115 -> V_116 ( V_4 ) )
return V_115 ;
return NULL ;
}
int F_54 ( struct V_114 * V_115 )
{
int V_65 = 0 ;
F_18 ( & V_117 ) ;
if ( V_115 -> V_118 ) {
F_19 ( L_6 ,
V_115 -> V_119 ) ;
V_65 = - V_120 ;
goto V_121;
}
if ( strcmp ( V_115 -> V_119 , V_122 ) )
F_55 ( & V_115 -> V_123 , & V_124 ) ;
else
F_56 ( & V_115 -> V_123 , & V_124 ) ;
V_115 -> V_118 = true ;
F_19 ( L_7 , V_115 -> V_119 ) ;
V_121:
F_21 ( & V_117 ) ;
return V_65 ;
}
int F_57 ( struct V_114 * V_115 )
{
int V_65 = 0 ;
struct V_125 * V_126 = NULL , * V_127 ;
F_18 ( & V_117 ) ;
if ( ! V_115 -> V_118 ) {
F_19 ( L_8 ,
V_115 -> V_119 ) ;
V_65 = - V_128 ;
goto V_121;
}
F_18 ( & V_129 ) ;
F_58 (nm, tmp, &fcoe_netdevs, list) {
if ( V_126 -> V_115 == V_115 ) {
F_19 ( L_9
L_10 ,
V_115 -> V_119 , V_126 -> V_4 -> V_119 ) ;
F_59 ( & V_126 -> V_123 ) ;
F_60 ( V_126 ) ;
}
}
F_21 ( & V_129 ) ;
F_59 ( & V_115 -> V_123 ) ;
V_115 -> V_118 = false ;
F_19 ( L_11 , V_115 -> V_119 ) ;
V_121:
F_21 ( & V_117 ) ;
return V_65 ;
}
static int F_61 ( char * V_130 , const struct V_131 * V_132 )
{
int V_84 , V_133 ;
struct V_114 * V_115 = NULL ;
V_84 = V_133 = sprintf ( V_130 , L_12 ) ;
F_18 ( & V_117 ) ;
F_20 (ft, &fcoe_transports, list) {
if ( V_84 >= V_88 - V_134 )
break;
V_84 += snprintf ( & V_130 [ V_84 ] , V_134 , L_13 , V_115 -> V_119 ) ;
}
F_21 ( & V_117 ) ;
if ( V_84 == V_133 )
V_84 += snprintf ( & V_130 [ V_84 ] , V_134 , L_14 ) ;
return V_84 ;
}
static int T_5 F_62 ( void )
{
F_63 ( & V_135 ) ;
return 0 ;
}
static int F_64 ( void )
{
struct V_114 * V_115 ;
F_65 ( & V_135 ) ;
F_18 ( & V_117 ) ;
F_20 (ft, &fcoe_transports, list)
F_66 ( V_136 L_15 ,
V_115 -> V_119 ) ;
F_21 ( & V_117 ) ;
return 0 ;
}
static int F_67 ( struct V_3 * V_4 ,
struct V_114 * V_115 )
{
struct V_125 * V_126 ;
V_126 = F_68 ( sizeof( * V_126 ) , V_137 ) ;
if ( ! V_126 ) {
F_66 ( V_136 L_16 ) ;
return - V_93 ;
}
V_126 -> V_4 = V_4 ;
V_126 -> V_115 = V_115 ;
F_18 ( & V_129 ) ;
F_55 ( & V_126 -> V_123 , & V_138 ) ;
F_21 ( & V_129 ) ;
return 0 ;
}
static void F_69 ( struct V_3 * V_4 )
{
struct V_125 * V_126 = NULL , * V_127 ;
F_18 ( & V_129 ) ;
F_58 (nm, tmp, &fcoe_netdevs, list) {
if ( V_126 -> V_4 == V_4 ) {
F_59 ( & V_126 -> V_123 ) ;
F_60 ( V_126 ) ;
F_21 ( & V_129 ) ;
return;
}
}
F_21 ( & V_129 ) ;
}
static struct V_114 * F_70 ( struct V_3 * V_4 )
{
struct V_114 * V_115 = NULL ;
struct V_125 * V_126 ;
F_18 ( & V_129 ) ;
F_20 (nm, &fcoe_netdevs, list) {
if ( V_4 == V_126 -> V_4 ) {
V_115 = V_126 -> V_115 ;
F_21 ( & V_129 ) ;
return V_115 ;
}
}
F_21 ( & V_129 ) ;
return NULL ;
}
static struct V_3 * F_71 ( const char * V_130 )
{
char * V_139 ;
char V_140 [ V_134 + 2 ] ;
if ( V_130 ) {
F_72 ( V_140 , V_130 , V_134 ) ;
V_139 = V_140 + strlen ( V_140 ) ;
while ( -- V_139 >= V_140 && * V_139 == '\n' )
* V_139 = '\0' ;
return F_73 ( & V_141 , V_140 ) ;
}
return NULL ;
}
static int F_74 ( struct V_142 * V_143 ,
T_4 V_144 , void * V_145 )
{
struct V_3 * V_4 = F_75 ( V_145 ) ;
switch ( V_144 ) {
case V_146 :
F_19 ( L_17 ,
V_4 -> V_119 ) ;
F_69 ( V_4 ) ;
break;
}
return V_147 ;
}
T_6 F_76 ( struct V_148 * V_149 ,
const char * V_56 , T_7 V_150 )
{
struct V_3 * V_4 = NULL ;
struct V_114 * V_115 = NULL ;
int V_65 = 0 ;
int V_151 ;
F_18 ( & V_117 ) ;
V_4 = F_71 ( V_56 ) ;
if ( ! V_4 ) {
F_19 ( L_18 , V_56 ) ;
V_65 = - V_128 ;
goto V_152;
}
V_115 = F_70 ( V_4 ) ;
if ( V_115 ) {
F_19 ( L_19
L_20 ,
V_115 -> V_119 , V_4 -> V_119 ) ;
V_65 = - V_120 ;
goto V_153;
}
V_115 = F_53 ( V_4 ) ;
if ( ! V_115 ) {
F_19 ( L_21 ,
V_4 -> V_119 ) ;
V_65 = - V_128 ;
goto V_153;
}
V_151 = V_115 -> V_154 ? V_115 -> V_154 ( V_4 ) : - V_128 ;
if ( V_151 ) {
F_69 ( V_4 ) ;
V_65 = - V_93 ;
goto V_153;
}
V_151 = F_67 ( V_4 , V_115 ) ;
if ( V_151 ) {
F_19 ( L_22
L_23 ,
V_115 -> V_119 , V_4 -> V_119 ) ;
V_65 = - V_128 ;
goto V_153;
}
F_19 ( L_24 ,
V_115 -> V_119 , V_4 -> V_119 ) ;
V_153:
F_77 ( V_4 ) ;
V_152:
F_21 ( & V_117 ) ;
if ( V_65 )
return V_65 ;
return V_150 ;
}
T_6 F_78 ( struct V_148 * V_149 ,
const char * V_56 , T_7 V_150 )
{
int V_65 = - V_128 ;
struct V_3 * V_4 = NULL ;
struct V_114 * V_115 = NULL ;
F_18 ( & V_117 ) ;
V_4 = F_71 ( V_56 ) ;
if ( ! V_4 ) {
F_19 ( L_25 , V_56 ) ;
goto V_152;
}
V_115 = F_70 ( V_4 ) ;
if ( ! V_115 ) {
F_19 ( L_21 ,
V_4 -> V_119 ) ;
goto V_153;
}
V_65 = V_115 -> V_155 ( V_4 ) ;
if ( V_65 )
goto V_153;
F_69 ( V_4 ) ;
F_19 ( L_26 ,
V_115 -> V_119 , ( V_65 ) ? L_27 : L_28 ,
V_4 -> V_119 ) ;
V_65 = V_150 ;
V_153:
F_77 ( V_4 ) ;
V_152:
F_21 ( & V_117 ) ;
return V_65 ;
}
static int F_79 ( const char * V_130 , struct V_131 * V_132 )
{
int V_65 = - V_128 ;
struct V_3 * V_4 = NULL ;
struct V_114 * V_115 = NULL ;
enum V_156 V_157 = (enum V_156 ) ( long ) V_132 -> V_158 ;
F_18 ( & V_117 ) ;
V_4 = F_71 ( V_130 ) ;
if ( ! V_4 ) {
F_19 ( L_18 , V_130 ) ;
goto V_152;
}
V_115 = F_70 ( V_4 ) ;
if ( V_115 ) {
F_19 ( L_19
L_20 ,
V_115 -> V_119 , V_4 -> V_119 ) ;
V_65 = - V_120 ;
goto V_153;
}
V_115 = F_53 ( V_4 ) ;
if ( ! V_115 ) {
F_19 ( L_21 ,
V_4 -> V_119 ) ;
goto V_153;
}
V_65 = F_67 ( V_4 , V_115 ) ;
if ( V_65 ) {
F_19 ( L_22
L_23 ,
V_115 -> V_119 , V_4 -> V_119 ) ;
goto V_153;
}
V_65 = V_115 -> V_159 ? V_115 -> V_159 ( V_4 , V_157 ) : - V_128 ;
if ( V_65 )
F_69 ( V_4 ) ;
F_19 ( L_29 ,
V_115 -> V_119 , ( V_65 ) ? L_27 : L_28 ,
V_4 -> V_119 ) ;
V_153:
F_77 ( V_4 ) ;
V_152:
F_21 ( & V_117 ) ;
return V_65 ;
}
static int F_80 ( const char * V_130 , struct V_131 * V_132 )
{
int V_65 = - V_128 ;
struct V_3 * V_4 = NULL ;
struct V_114 * V_115 = NULL ;
F_18 ( & V_117 ) ;
V_4 = F_71 ( V_130 ) ;
if ( ! V_4 ) {
F_19 ( L_25 , V_130 ) ;
goto V_152;
}
V_115 = F_70 ( V_4 ) ;
if ( ! V_115 ) {
F_19 ( L_21 ,
V_4 -> V_119 ) ;
goto V_153;
}
V_65 = V_115 -> V_155 ? V_115 -> V_155 ( V_4 ) : - V_128 ;
F_69 ( V_4 ) ;
F_19 ( L_26 ,
V_115 -> V_119 , ( V_65 ) ? L_27 : L_28 ,
V_4 -> V_119 ) ;
V_153:
F_77 ( V_4 ) ;
V_152:
F_21 ( & V_117 ) ;
return V_65 ;
}
static int F_81 ( const char * V_130 , struct V_131 * V_132 )
{
int V_65 = - V_128 ;
struct V_3 * V_4 = NULL ;
struct V_114 * V_115 = NULL ;
F_18 ( & V_117 ) ;
V_4 = F_71 ( V_130 ) ;
if ( ! V_4 )
goto V_152;
V_115 = F_70 ( V_4 ) ;
if ( ! V_115 )
goto V_153;
V_65 = V_115 -> V_160 ? V_115 -> V_160 ( V_4 ) : - V_128 ;
V_153:
F_77 ( V_4 ) ;
V_152:
F_21 ( & V_117 ) ;
return V_65 ;
}
static int F_82 ( const char * V_130 , struct V_131 * V_132 )
{
int V_65 = - V_128 ;
struct V_3 * V_4 = NULL ;
struct V_114 * V_115 = NULL ;
F_18 ( & V_117 ) ;
V_4 = F_71 ( V_130 ) ;
if ( ! V_4 )
goto V_152;
V_115 = F_70 ( V_4 ) ;
if ( ! V_115 )
goto V_153;
V_65 = V_115 -> V_161 ? V_115 -> V_161 ( V_4 ) : - V_128 ;
V_153:
F_77 ( V_4 ) ;
V_152:
F_21 ( & V_117 ) ;
return V_65 ;
}
static int T_5 F_83 ( void )
{
int V_65 = 0 ;
V_65 = F_62 () ;
if ( V_65 )
return V_65 ;
V_65 = F_84 () ;
if ( V_65 )
F_64 () ;
return V_65 ;
}
static void T_8 F_85 ( void )
{
F_86 () ;
F_64 () ;
}
