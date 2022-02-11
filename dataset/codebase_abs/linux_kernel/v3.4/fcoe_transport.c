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
F_24 ( V_50 ) + ( V_52 >> V_61 ) ) ;
V_54 = F_18 ( V_54 , V_51 + ( V_52 & ~ V_60 ) , V_53 ) ;
F_25 ( V_51 ) ;
V_52 += V_53 ;
V_28 -= V_53 ;
}
}
return V_54 ;
}
int F_26 ( struct V_47 * V_48 )
{
struct V_47 * V_62 ;
int V_36 ;
V_62 = F_27 ( V_48 , V_63 ) ;
if ( ! V_62 )
return - V_64 ;
V_36 = F_28 ( V_62 ) ;
if ( V_36 != 0 )
return V_36 ;
F_29 ( V_48 ) ;
return 0 ;
}
void F_30 ( struct V_1 * V_2 )
{
struct V_65 * V_66 = F_31 ( V_2 ) ;
struct V_47 * V_48 ;
F_32 ( & V_66 -> V_67 . V_68 ) ;
while ( ( V_48 = F_33 ( & V_66 -> V_67 ) ) != NULL ) {
F_34 ( & V_66 -> V_67 . V_68 ) ;
F_29 ( V_48 ) ;
F_32 ( & V_66 -> V_67 . V_68 ) ;
}
F_34 ( & V_66 -> V_67 . V_68 ) ;
}
void F_35 ( struct V_1 * V_2 , struct V_47 * V_48 )
{
struct V_65 * V_66 = F_31 ( V_2 ) ;
int V_36 ;
F_32 ( & V_66 -> V_67 . V_68 ) ;
if ( V_48 )
F_36 ( & V_66 -> V_67 , V_48 ) ;
if ( V_66 -> V_69 )
goto V_40;
V_66 -> V_69 = 1 ;
while ( V_66 -> V_67 . V_70 ) {
V_66 -> V_67 . V_70 ++ ;
V_48 = F_33 ( & V_66 -> V_67 ) ;
F_34 ( & V_66 -> V_67 . V_68 ) ;
V_36 = F_26 ( V_48 ) ;
F_32 ( & V_66 -> V_67 . V_68 ) ;
if ( V_36 ) {
F_37 ( & V_66 -> V_67 , V_48 ) ;
V_66 -> V_67 . V_70 -- ;
break;
}
V_66 -> V_67 . V_70 -- ;
}
if ( V_66 -> V_67 . V_70 < V_66 -> V_71 )
V_2 -> V_72 = 0 ;
if ( V_66 -> V_67 . V_70 && ! F_38 ( & V_66 -> V_73 ) )
F_39 ( & V_66 -> V_73 , V_74 + 2 ) ;
V_66 -> V_69 = 0 ;
V_40:
if ( V_66 -> V_67 . V_70 > V_66 -> V_75 )
V_2 -> V_72 = 1 ;
F_34 ( & V_66 -> V_67 . V_68 ) ;
}
void F_40 ( T_4 V_2 )
{
F_35 ( (struct V_1 * ) V_2 , NULL ) ;
}
int F_41 ( struct V_47 * V_48 , int V_76 ,
struct V_77 * V_78 )
{
struct V_79 * V_79 ;
V_79 = V_78 -> V_80 ;
if ( ! V_79 ) {
V_79 = F_42 ( V_63 ) ;
if ( ! V_79 )
return - V_64 ;
V_78 -> V_80 = V_79 ;
V_78 -> V_81 = 0 ;
}
F_43 ( V_79 ) ;
F_44 ( V_48 , F_20 ( V_48 ) -> V_56 , V_79 ,
V_78 -> V_81 , V_76 ) ;
V_48 -> V_28 += V_76 ;
V_48 -> V_82 += V_76 ;
V_48 -> V_83 += V_76 ;
V_78 -> V_81 += sizeof( struct V_84 ) ;
if ( V_78 -> V_81 >= V_59 ) {
V_78 -> V_80 = NULL ;
V_78 -> V_81 = 0 ;
F_45 ( V_79 ) ;
}
return 0 ;
}
static struct V_85 * F_46 ( struct V_5 * V_6 )
{
struct V_85 * V_86 = NULL ;
F_13 (ft, &fcoe_transports, list)
if ( V_86 -> V_87 && V_86 -> V_87 ( V_6 ) )
return V_86 ;
return NULL ;
}
int F_47 ( struct V_85 * V_86 )
{
int V_36 = 0 ;
F_11 ( & V_88 ) ;
if ( V_86 -> V_89 ) {
F_12 ( L_6 ,
V_86 -> V_90 ) ;
V_36 = - V_91 ;
goto V_92;
}
if ( strcmp ( V_86 -> V_90 , V_93 ) )
F_48 ( & V_86 -> V_94 , & V_95 ) ;
else
F_49 ( & V_86 -> V_94 , & V_95 ) ;
V_86 -> V_89 = true ;
F_12 ( L_7 , V_86 -> V_90 ) ;
V_92:
F_14 ( & V_88 ) ;
return V_36 ;
}
int F_50 ( struct V_85 * V_86 )
{
int V_36 = 0 ;
struct V_96 * V_97 = NULL , * V_98 ;
F_11 ( & V_88 ) ;
if ( ! V_86 -> V_89 ) {
F_12 ( L_8 ,
V_86 -> V_90 ) ;
V_36 = - V_99 ;
goto V_92;
}
F_11 ( & V_100 ) ;
F_51 (nm, tmp, &fcoe_netdevs, list) {
if ( V_97 -> V_86 == V_86 ) {
F_12 ( L_9
L_10 ,
V_86 -> V_90 , V_97 -> V_6 -> V_90 ) ;
F_52 ( & V_97 -> V_94 ) ;
F_53 ( V_97 ) ;
}
}
F_14 ( & V_100 ) ;
F_52 ( & V_86 -> V_94 ) ;
V_86 -> V_89 = false ;
F_12 ( L_11 , V_86 -> V_90 ) ;
V_92:
F_14 ( & V_88 ) ;
return V_36 ;
}
static int F_54 ( char * V_101 , const struct V_102 * V_103 )
{
int V_55 , V_104 ;
struct V_85 * V_86 = NULL ;
V_55 = V_104 = sprintf ( V_101 , L_12 ) ;
F_11 ( & V_88 ) ;
F_13 (ft, &fcoe_transports, list) {
if ( V_55 >= V_59 - V_105 )
break;
V_55 += snprintf ( & V_101 [ V_55 ] , V_105 , L_13 , V_86 -> V_90 ) ;
}
F_14 ( & V_88 ) ;
if ( V_55 == V_104 )
V_55 += snprintf ( & V_101 [ V_55 ] , V_105 , L_14 ) ;
return V_55 ;
}
static int T_5 F_55 ( void )
{
F_56 ( & V_106 ) ;
return 0 ;
}
static int T_6 F_57 ( void )
{
struct V_85 * V_86 ;
F_58 ( & V_106 ) ;
F_11 ( & V_88 ) ;
F_13 (ft, &fcoe_transports, list)
F_59 ( V_107 L_15 ,
V_86 -> V_90 ) ;
F_14 ( & V_88 ) ;
return 0 ;
}
static int F_60 ( struct V_5 * V_6 ,
struct V_85 * V_86 )
{
struct V_96 * V_97 ;
V_97 = F_61 ( sizeof( * V_97 ) , V_108 ) ;
if ( ! V_97 ) {
F_59 ( V_107 L_16 ) ;
return - V_64 ;
}
V_97 -> V_6 = V_6 ;
V_97 -> V_86 = V_86 ;
F_11 ( & V_100 ) ;
F_48 ( & V_97 -> V_94 , & V_109 ) ;
F_14 ( & V_100 ) ;
return 0 ;
}
static void F_62 ( struct V_5 * V_6 )
{
struct V_96 * V_97 = NULL , * V_98 ;
F_11 ( & V_100 ) ;
F_51 (nm, tmp, &fcoe_netdevs, list) {
if ( V_97 -> V_6 == V_6 ) {
F_52 ( & V_97 -> V_94 ) ;
F_53 ( V_97 ) ;
F_14 ( & V_100 ) ;
return;
}
}
F_14 ( & V_100 ) ;
}
static struct V_85 * F_63 ( struct V_5 * V_6 )
{
struct V_85 * V_86 = NULL ;
struct V_96 * V_97 ;
F_11 ( & V_100 ) ;
F_13 (nm, &fcoe_netdevs, list) {
if ( V_6 == V_97 -> V_6 ) {
V_86 = V_97 -> V_86 ;
F_14 ( & V_100 ) ;
return V_86 ;
}
}
F_14 ( & V_100 ) ;
return NULL ;
}
static struct V_5 * F_64 ( const char * V_101 )
{
char * V_110 ;
char V_111 [ V_105 + 2 ] ;
if ( V_101 ) {
F_65 ( V_111 , V_101 , V_105 ) ;
V_110 = V_111 + strlen ( V_111 ) ;
while ( -- V_110 >= V_111 && * V_110 == '\n' )
* V_110 = '\0' ;
return F_66 ( & V_112 , V_111 ) ;
}
return NULL ;
}
static int F_67 ( struct V_113 * V_114 ,
T_4 V_115 , void * V_116 )
{
struct V_5 * V_6 = V_116 ;
switch ( V_115 ) {
case V_117 :
F_12 ( L_17 ,
V_6 -> V_90 ) ;
F_62 ( V_6 ) ;
break;
}
return V_118 ;
}
static int F_68 ( const char * V_101 , struct V_102 * V_103 )
{
int V_36 = - V_99 ;
struct V_5 * V_6 = NULL ;
struct V_85 * V_86 = NULL ;
enum V_119 V_120 = (enum V_119 ) ( long ) V_103 -> V_121 ;
F_11 ( & V_88 ) ;
V_6 = F_64 ( V_101 ) ;
if ( ! V_6 ) {
F_12 ( L_18 , V_101 ) ;
goto V_122;
}
V_86 = F_63 ( V_6 ) ;
if ( V_86 ) {
F_12 ( L_19
L_20 ,
V_86 -> V_90 , V_6 -> V_90 ) ;
V_36 = - V_91 ;
goto V_123;
}
V_86 = F_46 ( V_6 ) ;
if ( ! V_86 ) {
F_12 ( L_21 ,
V_6 -> V_90 ) ;
goto V_123;
}
V_36 = F_60 ( V_6 , V_86 ) ;
if ( V_36 ) {
F_12 ( L_22
L_23 ,
V_86 -> V_90 , V_6 -> V_90 ) ;
goto V_123;
}
V_36 = V_86 -> V_124 ? V_86 -> V_124 ( V_6 , V_120 ) : - V_99 ;
if ( V_36 )
F_62 ( V_6 ) ;
F_12 ( L_24 ,
V_86 -> V_90 , ( V_36 ) ? L_25 : L_26 ,
V_6 -> V_90 ) ;
V_123:
F_69 ( V_6 ) ;
V_122:
F_14 ( & V_88 ) ;
return V_36 ;
}
static int F_70 ( const char * V_101 , struct V_102 * V_103 )
{
int V_36 = - V_99 ;
struct V_5 * V_6 = NULL ;
struct V_85 * V_86 = NULL ;
F_11 ( & V_88 ) ;
V_6 = F_64 ( V_101 ) ;
if ( ! V_6 ) {
F_12 ( L_27 , V_101 ) ;
goto V_122;
}
V_86 = F_63 ( V_6 ) ;
if ( ! V_86 ) {
F_12 ( L_21 ,
V_6 -> V_90 ) ;
goto V_123;
}
V_36 = V_86 -> V_125 ? V_86 -> V_125 ( V_6 ) : - V_99 ;
F_62 ( V_6 ) ;
F_12 ( L_28 ,
V_86 -> V_90 , ( V_36 ) ? L_25 : L_26 ,
V_6 -> V_90 ) ;
V_123:
F_69 ( V_6 ) ;
V_122:
F_14 ( & V_88 ) ;
return V_36 ;
}
static int F_71 ( const char * V_101 , struct V_102 * V_103 )
{
int V_36 = - V_99 ;
struct V_5 * V_6 = NULL ;
struct V_85 * V_86 = NULL ;
F_11 ( & V_88 ) ;
V_6 = F_64 ( V_101 ) ;
if ( ! V_6 )
goto V_122;
V_86 = F_63 ( V_6 ) ;
if ( ! V_86 )
goto V_123;
V_36 = V_86 -> V_126 ? V_86 -> V_126 ( V_6 ) : - V_99 ;
V_123:
F_69 ( V_6 ) ;
V_122:
F_14 ( & V_88 ) ;
if ( V_36 == - V_127 )
return F_72 () ;
else
return V_36 ;
}
static int F_73 ( const char * V_101 , struct V_102 * V_103 )
{
int V_36 = - V_99 ;
struct V_5 * V_6 = NULL ;
struct V_85 * V_86 = NULL ;
F_11 ( & V_88 ) ;
V_6 = F_64 ( V_101 ) ;
if ( ! V_6 )
goto V_122;
V_86 = F_63 ( V_6 ) ;
if ( ! V_86 )
goto V_123;
V_36 = V_86 -> V_128 ? V_86 -> V_128 ( V_6 ) : - V_99 ;
V_123:
F_69 ( V_6 ) ;
V_122:
F_14 ( & V_88 ) ;
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
