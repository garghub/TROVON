void F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 )
{
unsigned int V_7 ;
T_1 V_8 , V_9 , V_10 ;
struct V_11 * V_12 ;
struct V_13 * V_14 ;
struct V_15 V_16 ;
V_8 = 0 ;
V_9 = 0 ;
V_10 = 0 ;
V_14 = (struct V_13 * ) V_4 ;
memset ( V_14 , 0 , sizeof( * V_14 ) ) ;
F_2 (cpu) {
V_12 = F_3 ( V_2 -> V_17 , V_7 ) ;
V_8 += V_12 -> V_18 ;
V_9 += V_12 -> V_19 ;
V_10 += V_12 -> V_20 ;
}
V_14 -> V_21 = F_4 ( V_8 ) ;
V_14 -> V_22 = F_4 ( V_9 ) ;
V_14 -> V_23 = F_4 ( V_10 ) ;
V_14 -> V_24 =
F_4 ( F_5 ( V_6 , & V_16 ) -> V_25 ) ;
}
void F_6 ( T_2 V_26 , char * V_27 , int V_28 )
{
T_3 V_29 [ 8 ] ;
F_7 ( V_26 , V_29 ) ;
snprintf ( V_27 , V_28 , L_1 ,
V_29 [ 0 ] , V_29 [ 1 ] , V_29 [ 2 ] , V_29 [ 3 ] ,
V_29 [ 4 ] , V_29 [ 5 ] , V_29 [ 6 ] , V_29 [ 7 ] ) ;
}
int F_8 ( struct V_30 * V_31 )
{
struct V_32 * V_33 = F_9 ( V_31 ) ;
struct V_1 * V_34 = F_10 ( V_33 ) ;
struct V_1 * V_35 ;
int V_36 = 0 ;
char V_27 [ 32 ] ;
F_11 ( & V_34 -> V_37 ) ;
F_6 ( V_31 -> V_38 , V_27 , sizeof( V_27 ) ) ;
if ( ! memcmp ( & V_34 -> V_29 , & V_31 -> V_38 , sizeof( T_2 ) ) ) {
F_12 ( L_2
L_3 , V_27 ) ;
V_36 = - V_39 ;
goto V_40;
}
F_13 (vn_port, &n_port->vports, list) {
if ( ! memcmp ( & V_35 -> V_29 , & V_31 -> V_38 , sizeof( T_2 ) ) ) {
F_12 ( L_4
L_5 , V_27 ) ;
V_36 = - V_39 ;
break;
}
}
V_40:
F_14 ( & V_34 -> V_37 ) ;
return V_36 ;
}
int F_15 ( struct V_5 * V_6 , T_2 * V_26 , int type )
{
const struct V_41 * V_42 = V_6 -> V_43 ;
if ( V_42 -> V_44 )
return V_42 -> V_44 ( V_6 , V_26 , type ) ;
return - V_39 ;
}
T_1 F_16 ( struct V_45 * V_46 )
{
struct V_47 * V_48 = F_17 ( V_46 ) ;
struct V_49 * V_50 ;
unsigned char * V_51 ;
unsigned long V_52 , V_28 , V_53 ;
T_1 V_54 ;
unsigned V_55 ;
V_54 = F_18 ( ~ 0 , V_48 -> V_51 , F_19 ( V_48 ) ) ;
for ( V_55 = 0 ; V_55 < F_20 ( V_48 ) -> V_56 ; V_55 ++ ) {
V_50 = & F_20 ( V_48 ) -> V_57 [ V_55 ] ;
V_52 = V_50 -> V_58 ;
V_28 = F_21 ( V_50 ) ;
while ( V_28 > 0 ) {
V_53 = F_22 ( V_28 , V_59 - ( V_52 & ~ V_60 ) ) ;
V_51 = F_23 (
F_24 ( V_50 ) + ( V_52 >> V_61 ) ,
V_62 ) ;
V_54 = F_18 ( V_54 , V_51 + ( V_52 & ~ V_60 ) , V_53 ) ;
F_25 ( V_51 , V_62 ) ;
V_52 += V_53 ;
V_28 -= V_53 ;
}
}
return V_54 ;
}
int F_26 ( struct V_47 * V_48 )
{
struct V_47 * V_63 ;
int V_36 ;
V_63 = F_27 ( V_48 , V_64 ) ;
if ( ! V_63 )
return - V_65 ;
V_36 = F_28 ( V_63 ) ;
if ( V_36 != 0 )
return V_36 ;
F_29 ( V_48 ) ;
return 0 ;
}
void F_30 ( struct V_1 * V_2 )
{
struct V_66 * V_67 = F_31 ( V_2 ) ;
struct V_47 * V_48 ;
F_32 ( & V_67 -> V_68 . V_69 ) ;
while ( ( V_48 = F_33 ( & V_67 -> V_68 ) ) != NULL ) {
F_34 ( & V_67 -> V_68 . V_69 ) ;
F_29 ( V_48 ) ;
F_32 ( & V_67 -> V_68 . V_69 ) ;
}
F_34 ( & V_67 -> V_68 . V_69 ) ;
}
void F_35 ( struct V_1 * V_2 , struct V_47 * V_48 )
{
struct V_66 * V_67 = F_31 ( V_2 ) ;
int V_36 ;
F_32 ( & V_67 -> V_68 . V_69 ) ;
if ( V_48 )
F_36 ( & V_67 -> V_68 , V_48 ) ;
if ( V_67 -> V_70 )
goto V_40;
V_67 -> V_70 = 1 ;
while ( V_67 -> V_68 . V_71 ) {
V_67 -> V_68 . V_71 ++ ;
V_48 = F_33 ( & V_67 -> V_68 ) ;
F_34 ( & V_67 -> V_68 . V_69 ) ;
V_36 = F_26 ( V_48 ) ;
F_32 ( & V_67 -> V_68 . V_69 ) ;
if ( V_36 ) {
F_37 ( & V_67 -> V_68 , V_48 ) ;
V_67 -> V_68 . V_71 -- ;
break;
}
V_67 -> V_68 . V_71 -- ;
}
if ( V_67 -> V_68 . V_71 < V_67 -> V_72 )
V_2 -> V_73 = 0 ;
if ( V_67 -> V_68 . V_71 && ! F_38 ( & V_67 -> V_74 ) )
F_39 ( & V_67 -> V_74 , V_75 + 2 ) ;
V_67 -> V_70 = 0 ;
V_40:
if ( V_67 -> V_68 . V_71 > V_67 -> V_76 )
V_2 -> V_73 = 1 ;
F_34 ( & V_67 -> V_68 . V_69 ) ;
}
void F_40 ( T_4 V_2 )
{
F_35 ( (struct V_1 * ) V_2 , NULL ) ;
}
int F_41 ( struct V_47 * V_48 , int V_77 ,
struct V_78 * V_79 )
{
struct V_80 * V_80 ;
V_80 = V_79 -> V_81 ;
if ( ! V_80 ) {
V_80 = F_42 ( V_64 ) ;
if ( ! V_80 )
return - V_65 ;
V_79 -> V_81 = V_80 ;
V_79 -> V_82 = 0 ;
}
F_43 ( V_80 ) ;
F_44 ( V_48 , F_20 ( V_48 ) -> V_56 , V_80 ,
V_79 -> V_82 , V_77 ) ;
V_48 -> V_28 += V_77 ;
V_48 -> V_83 += V_77 ;
V_48 -> V_84 += V_77 ;
V_79 -> V_82 += sizeof( struct V_85 ) ;
if ( V_79 -> V_82 >= V_59 ) {
V_79 -> V_81 = NULL ;
V_79 -> V_82 = 0 ;
F_45 ( V_80 ) ;
}
return 0 ;
}
static struct V_86 * F_46 ( struct V_5 * V_6 )
{
struct V_86 * V_87 = NULL ;
F_13 (ft, &fcoe_transports, list)
if ( V_87 -> V_88 && V_87 -> V_88 ( V_6 ) )
return V_87 ;
return NULL ;
}
int F_47 ( struct V_86 * V_87 )
{
int V_36 = 0 ;
F_11 ( & V_89 ) ;
if ( V_87 -> V_90 ) {
F_12 ( L_6 ,
V_87 -> V_91 ) ;
V_36 = - V_92 ;
goto V_93;
}
if ( strcmp ( V_87 -> V_91 , V_94 ) )
F_48 ( & V_87 -> V_95 , & V_96 ) ;
else
F_49 ( & V_87 -> V_95 , & V_96 ) ;
V_87 -> V_90 = true ;
F_12 ( L_7 , V_87 -> V_91 ) ;
V_93:
F_14 ( & V_89 ) ;
return V_36 ;
}
int F_50 ( struct V_86 * V_87 )
{
int V_36 = 0 ;
struct V_97 * V_98 = NULL , * V_99 ;
F_11 ( & V_89 ) ;
if ( ! V_87 -> V_90 ) {
F_12 ( L_8 ,
V_87 -> V_91 ) ;
V_36 = - V_100 ;
goto V_93;
}
F_11 ( & V_101 ) ;
F_51 (nm, tmp, &fcoe_netdevs, list) {
if ( V_98 -> V_87 == V_87 ) {
F_12 ( L_9
L_10 ,
V_87 -> V_91 , V_98 -> V_6 -> V_91 ) ;
F_52 ( & V_98 -> V_95 ) ;
F_53 ( V_98 ) ;
}
}
F_14 ( & V_101 ) ;
F_52 ( & V_87 -> V_95 ) ;
V_87 -> V_90 = false ;
F_12 ( L_11 , V_87 -> V_91 ) ;
V_93:
F_14 ( & V_89 ) ;
return V_36 ;
}
static int F_54 ( char * V_102 , const struct V_103 * V_104 )
{
int V_55 , V_105 ;
struct V_86 * V_87 = NULL ;
V_55 = V_105 = sprintf ( V_102 , L_12 ) ;
F_11 ( & V_89 ) ;
F_13 (ft, &fcoe_transports, list) {
if ( V_55 >= V_59 - V_106 )
break;
V_55 += snprintf ( & V_102 [ V_55 ] , V_106 , L_13 , V_87 -> V_91 ) ;
}
F_14 ( & V_89 ) ;
if ( V_55 == V_105 )
V_55 += snprintf ( & V_102 [ V_55 ] , V_106 , L_14 ) ;
return V_55 ;
}
static int T_5 F_55 ( void )
{
F_56 ( & V_107 ) ;
return 0 ;
}
static int T_6 F_57 ( void )
{
struct V_86 * V_87 ;
F_58 ( & V_107 ) ;
F_11 ( & V_89 ) ;
F_13 (ft, &fcoe_transports, list)
F_59 ( V_108 L_15 ,
V_87 -> V_91 ) ;
F_14 ( & V_89 ) ;
return 0 ;
}
static int F_60 ( struct V_5 * V_6 ,
struct V_86 * V_87 )
{
struct V_97 * V_98 ;
V_98 = F_61 ( sizeof( * V_98 ) , V_109 ) ;
if ( ! V_98 ) {
F_59 ( V_108 L_16 ) ;
return - V_65 ;
}
V_98 -> V_6 = V_6 ;
V_98 -> V_87 = V_87 ;
F_11 ( & V_101 ) ;
F_48 ( & V_98 -> V_95 , & V_110 ) ;
F_14 ( & V_101 ) ;
return 0 ;
}
static void F_62 ( struct V_5 * V_6 )
{
struct V_97 * V_98 = NULL , * V_99 ;
F_11 ( & V_101 ) ;
F_51 (nm, tmp, &fcoe_netdevs, list) {
if ( V_98 -> V_6 == V_6 ) {
F_52 ( & V_98 -> V_95 ) ;
F_53 ( V_98 ) ;
F_14 ( & V_101 ) ;
return;
}
}
F_14 ( & V_101 ) ;
}
static struct V_86 * F_63 ( struct V_5 * V_6 )
{
struct V_86 * V_87 = NULL ;
struct V_97 * V_98 ;
F_11 ( & V_101 ) ;
F_13 (nm, &fcoe_netdevs, list) {
if ( V_6 == V_98 -> V_6 ) {
V_87 = V_98 -> V_87 ;
F_14 ( & V_101 ) ;
return V_87 ;
}
}
F_14 ( & V_101 ) ;
return NULL ;
}
static struct V_5 * F_64 ( const char * V_102 )
{
char * V_111 ;
char V_112 [ V_106 + 2 ] ;
if ( V_102 ) {
F_65 ( V_112 , V_102 , V_106 ) ;
V_111 = V_112 + strlen ( V_112 ) ;
while ( -- V_111 >= V_112 && * V_111 == '\n' )
* V_111 = '\0' ;
return F_66 ( & V_113 , V_112 ) ;
}
return NULL ;
}
static int F_67 ( struct V_114 * V_115 ,
T_4 V_116 , void * V_117 )
{
struct V_5 * V_6 = V_117 ;
switch ( V_116 ) {
case V_118 :
F_59 ( V_108 L_17 ,
V_6 -> V_91 ) ;
F_62 ( V_6 ) ;
break;
}
return V_119 ;
}
static int F_68 ( const char * V_102 , struct V_103 * V_104 )
{
int V_36 = - V_100 ;
struct V_5 * V_6 = NULL ;
struct V_86 * V_87 = NULL ;
enum V_120 V_121 = (enum V_120 ) ( long ) V_104 -> V_122 ;
F_11 ( & V_89 ) ;
V_6 = F_64 ( V_102 ) ;
if ( ! V_6 ) {
F_12 ( L_18 , V_102 ) ;
goto V_123;
}
V_87 = F_63 ( V_6 ) ;
if ( V_87 ) {
F_12 ( L_19
L_20 ,
V_87 -> V_91 , V_6 -> V_91 ) ;
V_36 = - V_92 ;
goto V_124;
}
V_87 = F_46 ( V_6 ) ;
if ( ! V_87 ) {
F_12 ( L_21 ,
V_6 -> V_91 ) ;
goto V_124;
}
V_36 = F_60 ( V_6 , V_87 ) ;
if ( V_36 ) {
F_12 ( L_22
L_23 ,
V_87 -> V_91 , V_6 -> V_91 ) ;
goto V_124;
}
V_36 = V_87 -> V_125 ? V_87 -> V_125 ( V_6 , V_121 ) : - V_100 ;
if ( V_36 )
F_62 ( V_6 ) ;
F_12 ( L_24 ,
V_87 -> V_91 , ( V_36 ) ? L_25 : L_26 ,
V_6 -> V_91 ) ;
V_124:
F_69 ( V_6 ) ;
V_123:
F_14 ( & V_89 ) ;
return V_36 ;
}
static int F_70 ( const char * V_102 , struct V_103 * V_104 )
{
int V_36 = - V_100 ;
struct V_5 * V_6 = NULL ;
struct V_86 * V_87 = NULL ;
F_11 ( & V_89 ) ;
V_6 = F_64 ( V_102 ) ;
if ( ! V_6 ) {
F_12 ( L_27 , V_102 ) ;
goto V_123;
}
V_87 = F_63 ( V_6 ) ;
if ( ! V_87 ) {
F_12 ( L_21 ,
V_6 -> V_91 ) ;
goto V_124;
}
V_36 = V_87 -> V_126 ? V_87 -> V_126 ( V_6 ) : - V_100 ;
F_62 ( V_6 ) ;
F_12 ( L_28 ,
V_87 -> V_91 , ( V_36 ) ? L_25 : L_26 ,
V_6 -> V_91 ) ;
V_124:
F_69 ( V_6 ) ;
V_123:
F_14 ( & V_89 ) ;
return V_36 ;
}
static int F_71 ( const char * V_102 , struct V_103 * V_104 )
{
int V_36 = - V_100 ;
struct V_5 * V_6 = NULL ;
struct V_86 * V_87 = NULL ;
F_11 ( & V_89 ) ;
V_6 = F_64 ( V_102 ) ;
if ( ! V_6 )
goto V_123;
V_87 = F_63 ( V_6 ) ;
if ( ! V_87 )
goto V_124;
V_36 = V_87 -> V_127 ? V_87 -> V_127 ( V_6 ) : - V_100 ;
V_124:
F_69 ( V_6 ) ;
V_123:
F_14 ( & V_89 ) ;
if ( V_36 == - V_128 )
return F_72 () ;
else
return V_36 ;
}
static int F_73 ( const char * V_102 , struct V_103 * V_104 )
{
int V_36 = - V_100 ;
struct V_5 * V_6 = NULL ;
struct V_86 * V_87 = NULL ;
F_11 ( & V_89 ) ;
V_6 = F_64 ( V_102 ) ;
if ( ! V_6 )
goto V_123;
V_87 = F_63 ( V_6 ) ;
if ( ! V_87 )
goto V_124;
V_36 = V_87 -> V_129 ? V_87 -> V_129 ( V_6 ) : - V_100 ;
V_124:
F_69 ( V_6 ) ;
V_123:
F_14 ( & V_89 ) ;
return V_36 ;
}
static int T_5 F_74 ( void )
{
F_55 () ;
return 0 ;
}
static void T_6 F_75 ( void )
{
F_57 () ;
}
