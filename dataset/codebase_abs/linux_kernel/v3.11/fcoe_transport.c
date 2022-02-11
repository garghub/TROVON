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
struct V_17 * V_18 ;
V_18 = (struct V_17 * ) ( & V_38 -> V_26 ) ;
F_5 ( V_40 -> V_41 , V_18 , V_4 ) ;
}
void F_13 ( T_2 V_42 , char * V_43 , int V_44 )
{
T_3 V_45 [ 8 ] ;
F_14 ( V_42 , V_45 ) ;
snprintf ( V_43 , V_44 , L_1 ,
V_45 [ 0 ] , V_45 [ 1 ] , V_45 [ 2 ] , V_45 [ 3 ] ,
V_45 [ 4 ] , V_45 [ 5 ] , V_45 [ 6 ] , V_45 [ 7 ] ) ;
}
int F_15 ( struct V_46 * V_47 )
{
struct V_48 * V_49 = F_16 ( V_47 ) ;
struct V_1 * V_50 = F_17 ( V_49 ) ;
struct V_1 * V_51 ;
int V_52 = 0 ;
char V_43 [ 32 ] ;
F_18 ( & V_50 -> V_53 ) ;
F_13 ( V_47 -> V_54 , V_43 , sizeof( V_43 ) ) ;
if ( ! memcmp ( & V_50 -> V_45 , & V_47 -> V_54 , sizeof( T_2 ) ) ) {
F_19 ( L_2
L_3 , V_43 ) ;
V_52 = - V_55 ;
goto V_56;
}
F_20 (vn_port, &n_port->vports, list) {
if ( ! memcmp ( & V_51 -> V_45 , & V_47 -> V_54 , sizeof( T_2 ) ) ) {
F_19 ( L_4
L_5 , V_43 ) ;
V_52 = - V_55 ;
break;
}
}
V_56:
F_21 ( & V_50 -> V_53 ) ;
return V_52 ;
}
int F_22 ( struct V_3 * V_4 , T_2 * V_42 , int type )
{
const struct V_57 * V_58 = V_4 -> V_59 ;
if ( V_58 -> V_60 )
return V_58 -> V_60 ( V_4 , V_42 , type ) ;
return - V_55 ;
}
T_1 F_23 ( struct V_61 * V_62 )
{
struct V_63 * V_64 = F_24 ( V_62 ) ;
struct V_65 * V_66 ;
unsigned char * V_67 ;
unsigned long V_68 , V_44 , V_69 ;
T_1 V_70 ;
unsigned V_71 ;
V_70 = F_25 ( ~ 0 , V_64 -> V_67 , F_26 ( V_64 ) ) ;
for ( V_71 = 0 ; V_71 < F_27 ( V_64 ) -> V_72 ; V_71 ++ ) {
V_66 = & F_27 ( V_64 ) -> V_73 [ V_71 ] ;
V_68 = V_66 -> V_74 ;
V_44 = F_28 ( V_66 ) ;
while ( V_44 > 0 ) {
V_69 = F_29 ( V_44 , V_75 - ( V_68 & ~ V_76 ) ) ;
V_67 = F_30 (
F_31 ( V_66 ) + ( V_68 >> V_77 ) ) ;
V_70 = F_25 ( V_70 , V_67 + ( V_68 & ~ V_76 ) , V_69 ) ;
F_32 ( V_67 ) ;
V_68 += V_69 ;
V_44 -= V_69 ;
}
}
return V_70 ;
}
int F_33 ( struct V_63 * V_64 )
{
struct V_63 * V_78 ;
int V_52 ;
V_78 = F_34 ( V_64 , V_79 ) ;
if ( ! V_78 )
return - V_80 ;
V_52 = F_35 ( V_78 ) ;
if ( V_52 != 0 )
return V_52 ;
F_36 ( V_64 ) ;
return 0 ;
}
void F_37 ( struct V_1 * V_2 )
{
struct V_81 * V_82 = F_38 ( V_2 ) ;
struct V_63 * V_64 ;
F_39 ( & V_82 -> V_83 . V_84 ) ;
while ( ( V_64 = F_40 ( & V_82 -> V_83 ) ) != NULL ) {
F_41 ( & V_82 -> V_83 . V_84 ) ;
F_36 ( V_64 ) ;
F_39 ( & V_82 -> V_83 . V_84 ) ;
}
F_41 ( & V_82 -> V_83 . V_84 ) ;
}
void F_42 ( struct V_1 * V_2 , struct V_63 * V_64 )
{
struct V_81 * V_82 = F_38 ( V_2 ) ;
int V_52 ;
F_39 ( & V_82 -> V_83 . V_84 ) ;
if ( V_64 )
F_43 ( & V_82 -> V_83 , V_64 ) ;
if ( V_82 -> V_85 )
goto V_56;
V_82 -> V_85 = 1 ;
while ( V_82 -> V_83 . V_86 ) {
V_82 -> V_83 . V_86 ++ ;
V_64 = F_40 ( & V_82 -> V_83 ) ;
F_41 ( & V_82 -> V_83 . V_84 ) ;
V_52 = F_33 ( V_64 ) ;
F_39 ( & V_82 -> V_83 . V_84 ) ;
if ( V_52 ) {
F_44 ( & V_82 -> V_83 , V_64 ) ;
V_82 -> V_83 . V_86 -- ;
break;
}
V_82 -> V_83 . V_86 -- ;
}
if ( V_82 -> V_83 . V_86 < V_82 -> V_87 )
V_2 -> V_88 = 0 ;
if ( V_82 -> V_83 . V_86 && ! F_45 ( & V_82 -> V_89 ) )
F_46 ( & V_82 -> V_89 , V_90 + 2 ) ;
V_82 -> V_85 = 0 ;
V_56:
if ( V_82 -> V_83 . V_86 > V_82 -> V_91 )
V_2 -> V_88 = 1 ;
F_41 ( & V_82 -> V_83 . V_84 ) ;
}
void F_47 ( T_4 V_2 )
{
F_42 ( (struct V_1 * ) V_2 , NULL ) ;
}
int F_48 ( struct V_63 * V_64 , int V_92 ,
struct V_93 * V_94 )
{
struct V_95 * V_95 ;
V_95 = V_94 -> V_96 ;
if ( ! V_95 ) {
V_95 = F_49 ( V_79 ) ;
if ( ! V_95 )
return - V_80 ;
V_94 -> V_96 = V_95 ;
V_94 -> V_97 = 0 ;
}
F_50 ( V_95 ) ;
F_51 ( V_64 , F_27 ( V_64 ) -> V_72 , V_95 ,
V_94 -> V_97 , V_92 ) ;
V_64 -> V_44 += V_92 ;
V_64 -> V_98 += V_92 ;
V_64 -> V_99 += V_92 ;
V_94 -> V_97 += sizeof( struct V_100 ) ;
if ( V_94 -> V_97 >= V_75 ) {
V_94 -> V_96 = NULL ;
V_94 -> V_97 = 0 ;
F_52 ( V_95 ) ;
}
return 0 ;
}
static struct V_101 * F_53 ( struct V_3 * V_4 )
{
struct V_101 * V_102 = NULL ;
F_20 (ft, &fcoe_transports, list)
if ( V_102 -> V_103 && V_102 -> V_103 ( V_4 ) )
return V_102 ;
return NULL ;
}
int F_54 ( struct V_101 * V_102 )
{
int V_52 = 0 ;
F_18 ( & V_104 ) ;
if ( V_102 -> V_105 ) {
F_19 ( L_6 ,
V_102 -> V_106 ) ;
V_52 = - V_107 ;
goto V_108;
}
if ( strcmp ( V_102 -> V_106 , V_109 ) )
F_55 ( & V_102 -> V_110 , & V_111 ) ;
else
F_56 ( & V_102 -> V_110 , & V_111 ) ;
V_102 -> V_105 = true ;
F_19 ( L_7 , V_102 -> V_106 ) ;
V_108:
F_21 ( & V_104 ) ;
return V_52 ;
}
int F_57 ( struct V_101 * V_102 )
{
int V_52 = 0 ;
struct V_112 * V_113 = NULL , * V_114 ;
F_18 ( & V_104 ) ;
if ( ! V_102 -> V_105 ) {
F_19 ( L_8 ,
V_102 -> V_106 ) ;
V_52 = - V_115 ;
goto V_108;
}
F_18 ( & V_116 ) ;
F_58 (nm, tmp, &fcoe_netdevs, list) {
if ( V_113 -> V_102 == V_102 ) {
F_19 ( L_9
L_10 ,
V_102 -> V_106 , V_113 -> V_4 -> V_106 ) ;
F_59 ( & V_113 -> V_110 ) ;
F_60 ( V_113 ) ;
}
}
F_21 ( & V_116 ) ;
F_59 ( & V_102 -> V_110 ) ;
V_102 -> V_105 = false ;
F_19 ( L_11 , V_102 -> V_106 ) ;
V_108:
F_21 ( & V_104 ) ;
return V_52 ;
}
static int F_61 ( char * V_117 , const struct V_118 * V_119 )
{
int V_71 , V_120 ;
struct V_101 * V_102 = NULL ;
V_71 = V_120 = sprintf ( V_117 , L_12 ) ;
F_18 ( & V_104 ) ;
F_20 (ft, &fcoe_transports, list) {
if ( V_71 >= V_75 - V_121 )
break;
V_71 += snprintf ( & V_117 [ V_71 ] , V_121 , L_13 , V_102 -> V_106 ) ;
}
F_21 ( & V_104 ) ;
if ( V_71 == V_120 )
V_71 += snprintf ( & V_117 [ V_71 ] , V_121 , L_14 ) ;
return V_71 ;
}
static int T_5 F_62 ( void )
{
F_63 ( & V_122 ) ;
return 0 ;
}
static int F_64 ( void )
{
struct V_101 * V_102 ;
F_65 ( & V_122 ) ;
F_18 ( & V_104 ) ;
F_20 (ft, &fcoe_transports, list)
F_66 ( V_123 L_15 ,
V_102 -> V_106 ) ;
F_21 ( & V_104 ) ;
return 0 ;
}
static int F_67 ( struct V_3 * V_4 ,
struct V_101 * V_102 )
{
struct V_112 * V_113 ;
V_113 = F_68 ( sizeof( * V_113 ) , V_124 ) ;
if ( ! V_113 ) {
F_66 ( V_123 L_16 ) ;
return - V_80 ;
}
V_113 -> V_4 = V_4 ;
V_113 -> V_102 = V_102 ;
F_18 ( & V_116 ) ;
F_55 ( & V_113 -> V_110 , & V_125 ) ;
F_21 ( & V_116 ) ;
return 0 ;
}
static void F_69 ( struct V_3 * V_4 )
{
struct V_112 * V_113 = NULL , * V_114 ;
F_18 ( & V_116 ) ;
F_58 (nm, tmp, &fcoe_netdevs, list) {
if ( V_113 -> V_4 == V_4 ) {
F_59 ( & V_113 -> V_110 ) ;
F_60 ( V_113 ) ;
F_21 ( & V_116 ) ;
return;
}
}
F_21 ( & V_116 ) ;
}
static struct V_101 * F_70 ( struct V_3 * V_4 )
{
struct V_101 * V_102 = NULL ;
struct V_112 * V_113 ;
F_18 ( & V_116 ) ;
F_20 (nm, &fcoe_netdevs, list) {
if ( V_4 == V_113 -> V_4 ) {
V_102 = V_113 -> V_102 ;
F_21 ( & V_116 ) ;
return V_102 ;
}
}
F_21 ( & V_116 ) ;
return NULL ;
}
static struct V_3 * F_71 ( const char * V_117 )
{
char * V_126 ;
char V_127 [ V_121 + 2 ] ;
if ( V_117 ) {
F_72 ( V_127 , V_117 , V_121 ) ;
V_126 = V_127 + strlen ( V_127 ) ;
while ( -- V_126 >= V_127 && * V_126 == '\n' )
* V_126 = '\0' ;
return F_73 ( & V_128 , V_127 ) ;
}
return NULL ;
}
static int F_74 ( struct V_129 * V_130 ,
T_4 V_131 , void * V_132 )
{
struct V_3 * V_4 = F_75 ( V_132 ) ;
switch ( V_131 ) {
case V_133 :
F_19 ( L_17 ,
V_4 -> V_106 ) ;
F_69 ( V_4 ) ;
break;
}
return V_134 ;
}
T_6 F_76 ( struct V_135 * V_136 ,
const char * V_43 , T_7 V_137 )
{
struct V_3 * V_4 = NULL ;
struct V_101 * V_102 = NULL ;
int V_52 = 0 ;
int V_138 ;
F_18 ( & V_104 ) ;
V_4 = F_71 ( V_43 ) ;
if ( ! V_4 ) {
F_19 ( L_18 , V_43 ) ;
V_52 = - V_115 ;
goto V_139;
}
V_102 = F_70 ( V_4 ) ;
if ( V_102 ) {
F_19 ( L_19
L_20 ,
V_102 -> V_106 , V_4 -> V_106 ) ;
V_52 = - V_107 ;
goto V_140;
}
V_102 = F_53 ( V_4 ) ;
if ( ! V_102 ) {
F_19 ( L_21 ,
V_4 -> V_106 ) ;
V_52 = - V_115 ;
goto V_140;
}
V_138 = V_102 -> V_141 ? V_102 -> V_141 ( V_4 ) : - V_115 ;
if ( V_138 ) {
F_69 ( V_4 ) ;
V_52 = - V_80 ;
goto V_140;
}
V_138 = F_67 ( V_4 , V_102 ) ;
if ( V_138 ) {
F_19 ( L_22
L_23 ,
V_102 -> V_106 , V_4 -> V_106 ) ;
V_52 = - V_115 ;
goto V_140;
}
F_19 ( L_24 ,
V_102 -> V_106 , V_4 -> V_106 ) ;
V_140:
F_77 ( V_4 ) ;
V_139:
F_21 ( & V_104 ) ;
if ( V_52 )
return V_52 ;
return V_137 ;
}
T_6 F_78 ( struct V_135 * V_136 ,
const char * V_43 , T_7 V_137 )
{
int V_52 = - V_115 ;
struct V_3 * V_4 = NULL ;
struct V_101 * V_102 = NULL ;
F_18 ( & V_104 ) ;
V_4 = F_71 ( V_43 ) ;
if ( ! V_4 ) {
F_19 ( L_25 , V_43 ) ;
goto V_139;
}
V_102 = F_70 ( V_4 ) ;
if ( ! V_102 ) {
F_19 ( L_21 ,
V_4 -> V_106 ) ;
goto V_140;
}
V_52 = V_102 -> V_142 ( V_4 ) ;
if ( V_52 )
goto V_140;
F_69 ( V_4 ) ;
F_19 ( L_26 ,
V_102 -> V_106 , ( V_52 ) ? L_27 : L_28 ,
V_4 -> V_106 ) ;
V_52 = V_137 ;
V_140:
F_77 ( V_4 ) ;
V_139:
F_21 ( & V_104 ) ;
return V_52 ;
}
static int F_79 ( const char * V_117 , struct V_118 * V_119 )
{
int V_52 = - V_115 ;
struct V_3 * V_4 = NULL ;
struct V_101 * V_102 = NULL ;
enum V_143 V_144 = (enum V_143 ) ( long ) V_119 -> V_145 ;
F_18 ( & V_104 ) ;
V_4 = F_71 ( V_117 ) ;
if ( ! V_4 ) {
F_19 ( L_18 , V_117 ) ;
goto V_139;
}
V_102 = F_70 ( V_4 ) ;
if ( V_102 ) {
F_19 ( L_19
L_20 ,
V_102 -> V_106 , V_4 -> V_106 ) ;
V_52 = - V_107 ;
goto V_140;
}
V_102 = F_53 ( V_4 ) ;
if ( ! V_102 ) {
F_19 ( L_21 ,
V_4 -> V_106 ) ;
goto V_140;
}
V_52 = F_67 ( V_4 , V_102 ) ;
if ( V_52 ) {
F_19 ( L_22
L_23 ,
V_102 -> V_106 , V_4 -> V_106 ) ;
goto V_140;
}
V_52 = V_102 -> V_146 ? V_102 -> V_146 ( V_4 , V_144 ) : - V_115 ;
if ( V_52 )
F_69 ( V_4 ) ;
F_19 ( L_29 ,
V_102 -> V_106 , ( V_52 ) ? L_27 : L_28 ,
V_4 -> V_106 ) ;
V_140:
F_77 ( V_4 ) ;
V_139:
F_21 ( & V_104 ) ;
return V_52 ;
}
static int F_80 ( const char * V_117 , struct V_118 * V_119 )
{
int V_52 = - V_115 ;
struct V_3 * V_4 = NULL ;
struct V_101 * V_102 = NULL ;
F_18 ( & V_104 ) ;
V_4 = F_71 ( V_117 ) ;
if ( ! V_4 ) {
F_19 ( L_25 , V_117 ) ;
goto V_139;
}
V_102 = F_70 ( V_4 ) ;
if ( ! V_102 ) {
F_19 ( L_21 ,
V_4 -> V_106 ) ;
goto V_140;
}
V_52 = V_102 -> V_142 ? V_102 -> V_142 ( V_4 ) : - V_115 ;
F_69 ( V_4 ) ;
F_19 ( L_26 ,
V_102 -> V_106 , ( V_52 ) ? L_27 : L_28 ,
V_4 -> V_106 ) ;
V_140:
F_77 ( V_4 ) ;
V_139:
F_21 ( & V_104 ) ;
return V_52 ;
}
static int F_81 ( const char * V_117 , struct V_118 * V_119 )
{
int V_52 = - V_115 ;
struct V_3 * V_4 = NULL ;
struct V_101 * V_102 = NULL ;
F_18 ( & V_104 ) ;
V_4 = F_71 ( V_117 ) ;
if ( ! V_4 )
goto V_139;
V_102 = F_70 ( V_4 ) ;
if ( ! V_102 )
goto V_140;
V_52 = V_102 -> V_147 ? V_102 -> V_147 ( V_4 ) : - V_115 ;
V_140:
F_77 ( V_4 ) ;
V_139:
F_21 ( & V_104 ) ;
return V_52 ;
}
static int F_82 ( const char * V_117 , struct V_118 * V_119 )
{
int V_52 = - V_115 ;
struct V_3 * V_4 = NULL ;
struct V_101 * V_102 = NULL ;
F_18 ( & V_104 ) ;
V_4 = F_71 ( V_117 ) ;
if ( ! V_4 )
goto V_139;
V_102 = F_70 ( V_4 ) ;
if ( ! V_102 )
goto V_140;
V_52 = V_102 -> V_148 ? V_102 -> V_148 ( V_4 ) : - V_115 ;
V_140:
F_77 ( V_4 ) ;
V_139:
F_21 ( & V_104 ) ;
return V_52 ;
}
static int T_5 F_83 ( void )
{
int V_52 = 0 ;
V_52 = F_62 () ;
if ( V_52 )
return V_52 ;
V_52 = F_84 () ;
if ( V_52 )
F_64 () ;
return V_52 ;
}
static void T_8 F_85 ( void )
{
F_86 () ;
F_64 () ;
}
