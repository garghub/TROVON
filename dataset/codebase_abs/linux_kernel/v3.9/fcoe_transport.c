int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_5 V_6 ;
if ( ! F_3 ( V_4 , & V_6 ) ) {
V_2 -> V_7 &=
~ ( V_8 | V_9 ) ;
if ( V_6 . V_10 & ( V_11 |
V_12 ) )
V_2 -> V_7 |= V_8 ;
if ( V_6 . V_10 & V_13 )
V_2 -> V_7 |=
V_9 ;
switch ( F_4 ( & V_6 ) ) {
case V_14 :
V_2 -> V_15 = V_8 ;
break;
case V_16 :
V_2 -> V_15 = V_9 ;
break;
}
return 0 ;
}
return - 1 ;
}
void F_5 ( struct V_1 * V_2 ,
struct V_17 * V_18 ,
struct V_3 * V_4 )
{
unsigned int V_19 ;
T_1 V_20 , V_21 , V_22 ;
struct V_23 * V_24 ;
struct V_25 * V_26 ;
struct V_27 V_28 ;
V_20 = 0 ;
V_21 = 0 ;
V_22 = 0 ;
V_26 = (struct V_25 * ) V_18 ;
memset ( V_26 , 0 , sizeof( * V_26 ) ) ;
F_6 (cpu) {
V_24 = F_7 ( V_2 -> V_24 , V_19 ) ;
V_20 += V_24 -> V_29 ;
V_21 += V_24 -> V_30 ;
V_22 += V_24 -> V_31 ;
}
V_26 -> V_32 = F_8 ( V_20 ) ;
V_26 -> V_33 = F_8 ( V_21 ) ;
V_26 -> V_34 = F_8 ( V_22 ) ;
V_26 -> V_35 =
F_8 ( F_9 ( V_4 , & V_28 ) -> V_36 ) ;
}
void F_10 ( struct V_1 * V_2 ,
struct V_17 * V_18 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
F_5 ( V_2 , V_18 , V_4 ) ;
}
void F_11 ( struct V_37 * V_38 )
{
struct V_39 * V_40 = F_12 ( V_38 ) ;
struct V_3 * V_4 = F_2 ( V_40 -> V_41 ) ;
struct V_25 * V_42 ;
struct V_17 V_18 ;
F_5 ( V_40 -> V_41 , & V_18 , V_4 ) ;
V_42 = (struct V_25 * ) ( & V_18 ) ;
V_38 -> V_26 . V_32 =
F_13 ( V_42 -> V_32 ) ;
V_38 -> V_26 . V_33 =
F_13 ( V_42 -> V_33 ) ;
V_38 -> V_26 . V_34 =
F_13 ( V_42 -> V_34 ) ;
V_38 -> V_26 . V_43 =
F_13 ( V_42 -> V_43 ) ;
V_38 -> V_26 . V_44 =
F_13 ( V_42 -> V_44 ) ;
V_38 -> V_26 . V_35 =
F_13 ( V_42 -> V_35 ) ;
}
void F_14 ( T_2 V_45 , char * V_46 , int V_47 )
{
T_3 V_48 [ 8 ] ;
F_15 ( V_45 , V_48 ) ;
snprintf ( V_46 , V_47 , L_1 ,
V_48 [ 0 ] , V_48 [ 1 ] , V_48 [ 2 ] , V_48 [ 3 ] ,
V_48 [ 4 ] , V_48 [ 5 ] , V_48 [ 6 ] , V_48 [ 7 ] ) ;
}
int F_16 ( struct V_49 * V_50 )
{
struct V_51 * V_52 = F_17 ( V_50 ) ;
struct V_1 * V_53 = F_18 ( V_52 ) ;
struct V_1 * V_54 ;
int V_55 = 0 ;
char V_46 [ 32 ] ;
F_19 ( & V_53 -> V_56 ) ;
F_14 ( V_50 -> V_57 , V_46 , sizeof( V_46 ) ) ;
if ( ! memcmp ( & V_53 -> V_48 , & V_50 -> V_57 , sizeof( T_2 ) ) ) {
F_20 ( L_2
L_3 , V_46 ) ;
V_55 = - V_58 ;
goto V_59;
}
F_21 (vn_port, &n_port->vports, list) {
if ( ! memcmp ( & V_54 -> V_48 , & V_50 -> V_57 , sizeof( T_2 ) ) ) {
F_20 ( L_4
L_5 , V_46 ) ;
V_55 = - V_58 ;
break;
}
}
V_59:
F_22 ( & V_53 -> V_56 ) ;
return V_55 ;
}
int F_23 ( struct V_3 * V_4 , T_2 * V_45 , int type )
{
const struct V_60 * V_61 = V_4 -> V_62 ;
if ( V_61 -> V_63 )
return V_61 -> V_63 ( V_4 , V_45 , type ) ;
return - V_58 ;
}
T_1 F_24 ( struct V_64 * V_65 )
{
struct V_66 * V_67 = F_25 ( V_65 ) ;
struct V_68 * V_69 ;
unsigned char * V_70 ;
unsigned long V_71 , V_47 , V_72 ;
T_1 V_73 ;
unsigned V_74 ;
V_73 = F_26 ( ~ 0 , V_67 -> V_70 , F_27 ( V_67 ) ) ;
for ( V_74 = 0 ; V_74 < F_28 ( V_67 ) -> V_75 ; V_74 ++ ) {
V_69 = & F_28 ( V_67 ) -> V_76 [ V_74 ] ;
V_71 = V_69 -> V_77 ;
V_47 = F_29 ( V_69 ) ;
while ( V_47 > 0 ) {
V_72 = F_30 ( V_47 , V_78 - ( V_71 & ~ V_79 ) ) ;
V_70 = F_31 (
F_32 ( V_69 ) + ( V_71 >> V_80 ) ) ;
V_73 = F_26 ( V_73 , V_70 + ( V_71 & ~ V_79 ) , V_72 ) ;
F_33 ( V_70 ) ;
V_71 += V_72 ;
V_47 -= V_72 ;
}
}
return V_73 ;
}
int F_34 ( struct V_66 * V_67 )
{
struct V_66 * V_81 ;
int V_55 ;
V_81 = F_35 ( V_67 , V_82 ) ;
if ( ! V_81 )
return - V_83 ;
V_55 = F_36 ( V_81 ) ;
if ( V_55 != 0 )
return V_55 ;
F_37 ( V_67 ) ;
return 0 ;
}
void F_38 ( struct V_1 * V_2 )
{
struct V_84 * V_85 = F_39 ( V_2 ) ;
struct V_66 * V_67 ;
F_40 ( & V_85 -> V_86 . V_87 ) ;
while ( ( V_67 = F_41 ( & V_85 -> V_86 ) ) != NULL ) {
F_42 ( & V_85 -> V_86 . V_87 ) ;
F_37 ( V_67 ) ;
F_40 ( & V_85 -> V_86 . V_87 ) ;
}
F_42 ( & V_85 -> V_86 . V_87 ) ;
}
void F_43 ( struct V_1 * V_2 , struct V_66 * V_67 )
{
struct V_84 * V_85 = F_39 ( V_2 ) ;
int V_55 ;
F_40 ( & V_85 -> V_86 . V_87 ) ;
if ( V_67 )
F_44 ( & V_85 -> V_86 , V_67 ) ;
if ( V_85 -> V_88 )
goto V_59;
V_85 -> V_88 = 1 ;
while ( V_85 -> V_86 . V_89 ) {
V_85 -> V_86 . V_89 ++ ;
V_67 = F_41 ( & V_85 -> V_86 ) ;
F_42 ( & V_85 -> V_86 . V_87 ) ;
V_55 = F_34 ( V_67 ) ;
F_40 ( & V_85 -> V_86 . V_87 ) ;
if ( V_55 ) {
F_45 ( & V_85 -> V_86 , V_67 ) ;
V_85 -> V_86 . V_89 -- ;
break;
}
V_85 -> V_86 . V_89 -- ;
}
if ( V_85 -> V_86 . V_89 < V_85 -> V_90 )
V_2 -> V_91 = 0 ;
if ( V_85 -> V_86 . V_89 && ! F_46 ( & V_85 -> V_92 ) )
F_47 ( & V_85 -> V_92 , V_93 + 2 ) ;
V_85 -> V_88 = 0 ;
V_59:
if ( V_85 -> V_86 . V_89 > V_85 -> V_94 )
V_2 -> V_91 = 1 ;
F_42 ( & V_85 -> V_86 . V_87 ) ;
}
void F_48 ( T_4 V_2 )
{
F_43 ( (struct V_1 * ) V_2 , NULL ) ;
}
int F_49 ( struct V_66 * V_67 , int V_95 ,
struct V_96 * V_97 )
{
struct V_98 * V_98 ;
V_98 = V_97 -> V_99 ;
if ( ! V_98 ) {
V_98 = F_50 ( V_82 ) ;
if ( ! V_98 )
return - V_83 ;
V_97 -> V_99 = V_98 ;
V_97 -> V_100 = 0 ;
}
F_51 ( V_98 ) ;
F_52 ( V_67 , F_28 ( V_67 ) -> V_75 , V_98 ,
V_97 -> V_100 , V_95 ) ;
V_67 -> V_47 += V_95 ;
V_67 -> V_101 += V_95 ;
V_67 -> V_102 += V_95 ;
V_97 -> V_100 += sizeof( struct V_103 ) ;
if ( V_97 -> V_100 >= V_78 ) {
V_97 -> V_99 = NULL ;
V_97 -> V_100 = 0 ;
F_53 ( V_98 ) ;
}
return 0 ;
}
static struct V_104 * F_54 ( struct V_3 * V_4 )
{
struct V_104 * V_105 = NULL ;
F_21 (ft, &fcoe_transports, list)
if ( V_105 -> V_106 && V_105 -> V_106 ( V_4 ) )
return V_105 ;
return NULL ;
}
int F_55 ( struct V_104 * V_105 )
{
int V_55 = 0 ;
F_19 ( & V_107 ) ;
if ( V_105 -> V_108 ) {
F_20 ( L_6 ,
V_105 -> V_109 ) ;
V_55 = - V_110 ;
goto V_111;
}
if ( strcmp ( V_105 -> V_109 , V_112 ) )
F_56 ( & V_105 -> V_113 , & V_114 ) ;
else
F_57 ( & V_105 -> V_113 , & V_114 ) ;
V_105 -> V_108 = true ;
F_20 ( L_7 , V_105 -> V_109 ) ;
V_111:
F_22 ( & V_107 ) ;
return V_55 ;
}
int F_58 ( struct V_104 * V_105 )
{
int V_55 = 0 ;
struct V_115 * V_116 = NULL , * V_117 ;
F_19 ( & V_107 ) ;
if ( ! V_105 -> V_108 ) {
F_20 ( L_8 ,
V_105 -> V_109 ) ;
V_55 = - V_118 ;
goto V_111;
}
F_19 ( & V_119 ) ;
F_59 (nm, tmp, &fcoe_netdevs, list) {
if ( V_116 -> V_105 == V_105 ) {
F_20 ( L_9
L_10 ,
V_105 -> V_109 , V_116 -> V_4 -> V_109 ) ;
F_60 ( & V_116 -> V_113 ) ;
F_61 ( V_116 ) ;
}
}
F_22 ( & V_119 ) ;
F_60 ( & V_105 -> V_113 ) ;
V_105 -> V_108 = false ;
F_20 ( L_11 , V_105 -> V_109 ) ;
V_111:
F_22 ( & V_107 ) ;
return V_55 ;
}
static int F_62 ( char * V_120 , const struct V_121 * V_122 )
{
int V_74 , V_123 ;
struct V_104 * V_105 = NULL ;
V_74 = V_123 = sprintf ( V_120 , L_12 ) ;
F_19 ( & V_107 ) ;
F_21 (ft, &fcoe_transports, list) {
if ( V_74 >= V_78 - V_124 )
break;
V_74 += snprintf ( & V_120 [ V_74 ] , V_124 , L_13 , V_105 -> V_109 ) ;
}
F_22 ( & V_107 ) ;
if ( V_74 == V_123 )
V_74 += snprintf ( & V_120 [ V_74 ] , V_124 , L_14 ) ;
return V_74 ;
}
static int T_5 F_63 ( void )
{
F_64 ( & V_125 ) ;
return 0 ;
}
static int F_65 ( void )
{
struct V_104 * V_105 ;
F_66 ( & V_125 ) ;
F_19 ( & V_107 ) ;
F_21 (ft, &fcoe_transports, list)
F_67 ( V_126 L_15 ,
V_105 -> V_109 ) ;
F_22 ( & V_107 ) ;
return 0 ;
}
static int F_68 ( struct V_3 * V_4 ,
struct V_104 * V_105 )
{
struct V_115 * V_116 ;
V_116 = F_69 ( sizeof( * V_116 ) , V_127 ) ;
if ( ! V_116 ) {
F_67 ( V_126 L_16 ) ;
return - V_83 ;
}
V_116 -> V_4 = V_4 ;
V_116 -> V_105 = V_105 ;
F_19 ( & V_119 ) ;
F_56 ( & V_116 -> V_113 , & V_128 ) ;
F_22 ( & V_119 ) ;
return 0 ;
}
static void F_70 ( struct V_3 * V_4 )
{
struct V_115 * V_116 = NULL , * V_117 ;
F_19 ( & V_119 ) ;
F_59 (nm, tmp, &fcoe_netdevs, list) {
if ( V_116 -> V_4 == V_4 ) {
F_60 ( & V_116 -> V_113 ) ;
F_61 ( V_116 ) ;
F_22 ( & V_119 ) ;
return;
}
}
F_22 ( & V_119 ) ;
}
static struct V_104 * F_71 ( struct V_3 * V_4 )
{
struct V_104 * V_105 = NULL ;
struct V_115 * V_116 ;
F_19 ( & V_119 ) ;
F_21 (nm, &fcoe_netdevs, list) {
if ( V_4 == V_116 -> V_4 ) {
V_105 = V_116 -> V_105 ;
F_22 ( & V_119 ) ;
return V_105 ;
}
}
F_22 ( & V_119 ) ;
return NULL ;
}
static struct V_3 * F_72 ( const char * V_120 )
{
char * V_129 ;
char V_130 [ V_124 + 2 ] ;
if ( V_120 ) {
F_73 ( V_130 , V_120 , V_124 ) ;
V_129 = V_130 + strlen ( V_130 ) ;
while ( -- V_129 >= V_130 && * V_129 == '\n' )
* V_129 = '\0' ;
return F_74 ( & V_131 , V_130 ) ;
}
return NULL ;
}
static int F_75 ( struct V_132 * V_133 ,
T_4 V_134 , void * V_135 )
{
struct V_3 * V_4 = V_135 ;
switch ( V_134 ) {
case V_136 :
F_20 ( L_17 ,
V_4 -> V_109 ) ;
F_70 ( V_4 ) ;
break;
}
return V_137 ;
}
T_6 F_76 ( struct V_138 * V_139 ,
const char * V_46 , T_7 V_140 )
{
struct V_3 * V_4 = NULL ;
struct V_104 * V_105 = NULL ;
struct V_37 * V_38 = NULL ;
int V_55 = 0 ;
int V_141 ;
F_19 ( & V_107 ) ;
V_4 = F_72 ( V_46 ) ;
if ( ! V_4 ) {
F_20 ( L_18 , V_46 ) ;
V_55 = - V_118 ;
goto V_142;
}
V_105 = F_71 ( V_4 ) ;
if ( V_105 ) {
F_20 ( L_19
L_20 ,
V_105 -> V_109 , V_4 -> V_109 ) ;
V_55 = - V_110 ;
goto V_143;
}
V_105 = F_54 ( V_4 ) ;
if ( ! V_105 ) {
F_20 ( L_21 ,
V_4 -> V_109 ) ;
V_55 = - V_118 ;
goto V_143;
}
V_141 = V_105 -> V_144 ? V_105 -> V_144 ( V_4 ) : - V_118 ;
if ( V_141 ) {
F_70 ( V_4 ) ;
V_55 = - V_83 ;
goto V_143;
}
V_141 = F_68 ( V_4 , V_105 ) ;
if ( V_141 ) {
F_20 ( L_22
L_23 ,
V_105 -> V_109 , V_4 -> V_109 ) ;
V_55 = - V_118 ;
goto V_143;
}
F_20 ( L_24 ,
V_105 -> V_109 , ( V_38 ) ? L_25 : L_26 ,
V_4 -> V_109 ) ;
V_143:
F_77 ( V_4 ) ;
V_142:
F_22 ( & V_107 ) ;
if ( V_55 )
return V_55 ;
return V_140 ;
}
T_6 F_78 ( struct V_138 * V_139 ,
const char * V_46 , T_7 V_140 )
{
int V_55 = - V_118 ;
struct V_3 * V_4 = NULL ;
struct V_104 * V_105 = NULL ;
F_19 ( & V_107 ) ;
V_4 = F_72 ( V_46 ) ;
if ( ! V_4 ) {
F_20 ( L_27 , V_46 ) ;
goto V_142;
}
V_105 = F_71 ( V_4 ) ;
if ( ! V_105 ) {
F_20 ( L_21 ,
V_4 -> V_109 ) ;
goto V_143;
}
V_55 = V_105 -> V_145 ( V_4 ) ;
if ( V_55 )
goto V_143;
F_70 ( V_4 ) ;
F_20 ( L_28 ,
V_105 -> V_109 , ( V_55 ) ? L_26 : L_25 ,
V_4 -> V_109 ) ;
V_55 = V_140 ;
V_143:
F_77 ( V_4 ) ;
V_142:
F_22 ( & V_107 ) ;
return V_55 ;
}
static int F_79 ( const char * V_120 , struct V_121 * V_122 )
{
int V_55 = - V_118 ;
struct V_3 * V_4 = NULL ;
struct V_104 * V_105 = NULL ;
enum V_146 V_147 = (enum V_146 ) ( long ) V_122 -> V_148 ;
F_19 ( & V_107 ) ;
V_4 = F_72 ( V_120 ) ;
if ( ! V_4 ) {
F_20 ( L_18 , V_120 ) ;
goto V_142;
}
V_105 = F_71 ( V_4 ) ;
if ( V_105 ) {
F_20 ( L_19
L_20 ,
V_105 -> V_109 , V_4 -> V_109 ) ;
V_55 = - V_110 ;
goto V_143;
}
V_105 = F_54 ( V_4 ) ;
if ( ! V_105 ) {
F_20 ( L_21 ,
V_4 -> V_109 ) ;
goto V_143;
}
V_55 = F_68 ( V_4 , V_105 ) ;
if ( V_55 ) {
F_20 ( L_22
L_23 ,
V_105 -> V_109 , V_4 -> V_109 ) ;
goto V_143;
}
V_55 = V_105 -> V_149 ? V_105 -> V_149 ( V_4 , V_147 ) : - V_118 ;
if ( V_55 )
F_70 ( V_4 ) ;
F_20 ( L_24 ,
V_105 -> V_109 , ( V_55 ) ? L_26 : L_25 ,
V_4 -> V_109 ) ;
V_143:
F_77 ( V_4 ) ;
V_142:
F_22 ( & V_107 ) ;
return V_55 ;
}
static int F_80 ( const char * V_120 , struct V_121 * V_122 )
{
int V_55 = - V_118 ;
struct V_3 * V_4 = NULL ;
struct V_104 * V_105 = NULL ;
F_19 ( & V_107 ) ;
V_4 = F_72 ( V_120 ) ;
if ( ! V_4 ) {
F_20 ( L_27 , V_120 ) ;
goto V_142;
}
V_105 = F_71 ( V_4 ) ;
if ( ! V_105 ) {
F_20 ( L_21 ,
V_4 -> V_109 ) ;
goto V_143;
}
V_55 = V_105 -> V_145 ? V_105 -> V_145 ( V_4 ) : - V_118 ;
F_70 ( V_4 ) ;
F_20 ( L_28 ,
V_105 -> V_109 , ( V_55 ) ? L_26 : L_25 ,
V_4 -> V_109 ) ;
V_143:
F_77 ( V_4 ) ;
V_142:
F_22 ( & V_107 ) ;
return V_55 ;
}
static int F_81 ( const char * V_120 , struct V_121 * V_122 )
{
int V_55 = - V_118 ;
struct V_3 * V_4 = NULL ;
struct V_104 * V_105 = NULL ;
F_19 ( & V_107 ) ;
V_4 = F_72 ( V_120 ) ;
if ( ! V_4 )
goto V_142;
V_105 = F_71 ( V_4 ) ;
if ( ! V_105 )
goto V_143;
V_55 = V_105 -> V_150 ? V_105 -> V_150 ( V_4 ) : - V_118 ;
V_143:
F_77 ( V_4 ) ;
V_142:
F_22 ( & V_107 ) ;
return V_55 ;
}
static int F_82 ( const char * V_120 , struct V_121 * V_122 )
{
int V_55 = - V_118 ;
struct V_3 * V_4 = NULL ;
struct V_104 * V_105 = NULL ;
F_19 ( & V_107 ) ;
V_4 = F_72 ( V_120 ) ;
if ( ! V_4 )
goto V_142;
V_105 = F_71 ( V_4 ) ;
if ( ! V_105 )
goto V_143;
V_55 = V_105 -> V_151 ? V_105 -> V_151 ( V_4 ) : - V_118 ;
V_143:
F_77 ( V_4 ) ;
V_142:
F_22 ( & V_107 ) ;
return V_55 ;
}
static int T_5 F_83 ( void )
{
int V_55 = 0 ;
V_55 = F_63 () ;
if ( V_55 )
return V_55 ;
V_55 = F_84 () ;
if ( V_55 )
F_65 () ;
return V_55 ;
}
static void T_8 F_85 ( void )
{
F_86 () ;
F_65 () ;
}
