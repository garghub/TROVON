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
V_12 = F_3 ( V_2 -> V_12 , V_7 ) ;
V_8 += V_12 -> V_17 ;
V_9 += V_12 -> V_18 ;
V_10 += V_12 -> V_19 ;
}
V_14 -> V_20 = F_4 ( V_8 ) ;
V_14 -> V_21 = F_4 ( V_9 ) ;
V_14 -> V_22 = F_4 ( V_10 ) ;
V_14 -> V_23 =
F_4 ( F_5 ( V_6 , & V_16 ) -> V_24 ) ;
}
void F_6 ( T_2 V_25 , char * V_26 , int V_27 )
{
T_3 V_28 [ 8 ] ;
F_7 ( V_25 , V_28 ) ;
snprintf ( V_26 , V_27 , L_1 ,
V_28 [ 0 ] , V_28 [ 1 ] , V_28 [ 2 ] , V_28 [ 3 ] ,
V_28 [ 4 ] , V_28 [ 5 ] , V_28 [ 6 ] , V_28 [ 7 ] ) ;
}
int F_8 ( struct V_29 * V_30 )
{
struct V_31 * V_32 = F_9 ( V_30 ) ;
struct V_1 * V_33 = F_10 ( V_32 ) ;
struct V_1 * V_34 ;
int V_35 = 0 ;
char V_26 [ 32 ] ;
F_11 ( & V_33 -> V_36 ) ;
F_6 ( V_30 -> V_37 , V_26 , sizeof( V_26 ) ) ;
if ( ! memcmp ( & V_33 -> V_28 , & V_30 -> V_37 , sizeof( T_2 ) ) ) {
F_12 ( L_2
L_3 , V_26 ) ;
V_35 = - V_38 ;
goto V_39;
}
F_13 (vn_port, &n_port->vports, list) {
if ( ! memcmp ( & V_34 -> V_28 , & V_30 -> V_37 , sizeof( T_2 ) ) ) {
F_12 ( L_4
L_5 , V_26 ) ;
V_35 = - V_38 ;
break;
}
}
V_39:
F_14 ( & V_33 -> V_36 ) ;
return V_35 ;
}
int F_15 ( struct V_5 * V_6 , T_2 * V_25 , int type )
{
const struct V_40 * V_41 = V_6 -> V_42 ;
if ( V_41 -> V_43 )
return V_41 -> V_43 ( V_6 , V_25 , type ) ;
return - V_38 ;
}
T_1 F_16 ( struct V_44 * V_45 )
{
struct V_46 * V_47 = F_17 ( V_45 ) ;
struct V_48 * V_49 ;
unsigned char * V_50 ;
unsigned long V_51 , V_27 , V_52 ;
T_1 V_53 ;
unsigned V_54 ;
V_53 = F_18 ( ~ 0 , V_47 -> V_50 , F_19 ( V_47 ) ) ;
for ( V_54 = 0 ; V_54 < F_20 ( V_47 ) -> V_55 ; V_54 ++ ) {
V_49 = & F_20 ( V_47 ) -> V_56 [ V_54 ] ;
V_51 = V_49 -> V_57 ;
V_27 = F_21 ( V_49 ) ;
while ( V_27 > 0 ) {
V_52 = F_22 ( V_27 , V_58 - ( V_51 & ~ V_59 ) ) ;
V_50 = F_23 (
F_24 ( V_49 ) + ( V_51 >> V_60 ) ) ;
V_53 = F_18 ( V_53 , V_50 + ( V_51 & ~ V_59 ) , V_52 ) ;
F_25 ( V_50 ) ;
V_51 += V_52 ;
V_27 -= V_52 ;
}
}
return V_53 ;
}
int F_26 ( struct V_46 * V_47 )
{
struct V_46 * V_61 ;
int V_35 ;
V_61 = F_27 ( V_47 , V_62 ) ;
if ( ! V_61 )
return - V_63 ;
V_35 = F_28 ( V_61 ) ;
if ( V_35 != 0 )
return V_35 ;
F_29 ( V_47 ) ;
return 0 ;
}
void F_30 ( struct V_1 * V_2 )
{
struct V_64 * V_65 = F_31 ( V_2 ) ;
struct V_46 * V_47 ;
F_32 ( & V_65 -> V_66 . V_67 ) ;
while ( ( V_47 = F_33 ( & V_65 -> V_66 ) ) != NULL ) {
F_34 ( & V_65 -> V_66 . V_67 ) ;
F_29 ( V_47 ) ;
F_32 ( & V_65 -> V_66 . V_67 ) ;
}
F_34 ( & V_65 -> V_66 . V_67 ) ;
}
void F_35 ( struct V_1 * V_2 , struct V_46 * V_47 )
{
struct V_64 * V_65 = F_31 ( V_2 ) ;
int V_35 ;
F_32 ( & V_65 -> V_66 . V_67 ) ;
if ( V_47 )
F_36 ( & V_65 -> V_66 , V_47 ) ;
if ( V_65 -> V_68 )
goto V_39;
V_65 -> V_68 = 1 ;
while ( V_65 -> V_66 . V_69 ) {
V_65 -> V_66 . V_69 ++ ;
V_47 = F_33 ( & V_65 -> V_66 ) ;
F_34 ( & V_65 -> V_66 . V_67 ) ;
V_35 = F_26 ( V_47 ) ;
F_32 ( & V_65 -> V_66 . V_67 ) ;
if ( V_35 ) {
F_37 ( & V_65 -> V_66 , V_47 ) ;
V_65 -> V_66 . V_69 -- ;
break;
}
V_65 -> V_66 . V_69 -- ;
}
if ( V_65 -> V_66 . V_69 < V_65 -> V_70 )
V_2 -> V_71 = 0 ;
if ( V_65 -> V_66 . V_69 && ! F_38 ( & V_65 -> V_72 ) )
F_39 ( & V_65 -> V_72 , V_73 + 2 ) ;
V_65 -> V_68 = 0 ;
V_39:
if ( V_65 -> V_66 . V_69 > V_65 -> V_74 )
V_2 -> V_71 = 1 ;
F_34 ( & V_65 -> V_66 . V_67 ) ;
}
void F_40 ( T_4 V_2 )
{
F_35 ( (struct V_1 * ) V_2 , NULL ) ;
}
int F_41 ( struct V_46 * V_47 , int V_75 ,
struct V_76 * V_77 )
{
struct V_78 * V_78 ;
V_78 = V_77 -> V_79 ;
if ( ! V_78 ) {
V_78 = F_42 ( V_62 ) ;
if ( ! V_78 )
return - V_63 ;
V_77 -> V_79 = V_78 ;
V_77 -> V_80 = 0 ;
}
F_43 ( V_78 ) ;
F_44 ( V_47 , F_20 ( V_47 ) -> V_55 , V_78 ,
V_77 -> V_80 , V_75 ) ;
V_47 -> V_27 += V_75 ;
V_47 -> V_81 += V_75 ;
V_47 -> V_82 += V_75 ;
V_77 -> V_80 += sizeof( struct V_83 ) ;
if ( V_77 -> V_80 >= V_58 ) {
V_77 -> V_79 = NULL ;
V_77 -> V_80 = 0 ;
F_45 ( V_78 ) ;
}
return 0 ;
}
static struct V_84 * F_46 ( struct V_5 * V_6 )
{
struct V_84 * V_85 = NULL ;
F_13 (ft, &fcoe_transports, list)
if ( V_85 -> V_86 && V_85 -> V_86 ( V_6 ) )
return V_85 ;
return NULL ;
}
int F_47 ( struct V_84 * V_85 )
{
int V_35 = 0 ;
F_11 ( & V_87 ) ;
if ( V_85 -> V_88 ) {
F_12 ( L_6 ,
V_85 -> V_89 ) ;
V_35 = - V_90 ;
goto V_91;
}
if ( strcmp ( V_85 -> V_89 , V_92 ) )
F_48 ( & V_85 -> V_93 , & V_94 ) ;
else
F_49 ( & V_85 -> V_93 , & V_94 ) ;
V_85 -> V_88 = true ;
F_12 ( L_7 , V_85 -> V_89 ) ;
V_91:
F_14 ( & V_87 ) ;
return V_35 ;
}
int F_50 ( struct V_84 * V_85 )
{
int V_35 = 0 ;
struct V_95 * V_96 = NULL , * V_97 ;
F_11 ( & V_87 ) ;
if ( ! V_85 -> V_88 ) {
F_12 ( L_8 ,
V_85 -> V_89 ) ;
V_35 = - V_98 ;
goto V_91;
}
F_11 ( & V_99 ) ;
F_51 (nm, tmp, &fcoe_netdevs, list) {
if ( V_96 -> V_85 == V_85 ) {
F_12 ( L_9
L_10 ,
V_85 -> V_89 , V_96 -> V_6 -> V_89 ) ;
F_52 ( & V_96 -> V_93 ) ;
F_53 ( V_96 ) ;
}
}
F_14 ( & V_99 ) ;
F_52 ( & V_85 -> V_93 ) ;
V_85 -> V_88 = false ;
F_12 ( L_11 , V_85 -> V_89 ) ;
V_91:
F_14 ( & V_87 ) ;
return V_35 ;
}
static int F_54 ( char * V_100 , const struct V_101 * V_102 )
{
int V_54 , V_103 ;
struct V_84 * V_85 = NULL ;
V_54 = V_103 = sprintf ( V_100 , L_12 ) ;
F_11 ( & V_87 ) ;
F_13 (ft, &fcoe_transports, list) {
if ( V_54 >= V_58 - V_104 )
break;
V_54 += snprintf ( & V_100 [ V_54 ] , V_104 , L_13 , V_85 -> V_89 ) ;
}
F_14 ( & V_87 ) ;
if ( V_54 == V_103 )
V_54 += snprintf ( & V_100 [ V_54 ] , V_104 , L_14 ) ;
return V_54 ;
}
static int T_5 F_55 ( void )
{
F_56 ( & V_105 ) ;
return 0 ;
}
static int F_57 ( void )
{
struct V_84 * V_85 ;
F_58 ( & V_105 ) ;
F_11 ( & V_87 ) ;
F_13 (ft, &fcoe_transports, list)
F_59 ( V_106 L_15 ,
V_85 -> V_89 ) ;
F_14 ( & V_87 ) ;
return 0 ;
}
static int F_60 ( struct V_5 * V_6 ,
struct V_84 * V_85 )
{
struct V_95 * V_96 ;
V_96 = F_61 ( sizeof( * V_96 ) , V_107 ) ;
if ( ! V_96 ) {
F_59 ( V_106 L_16 ) ;
return - V_63 ;
}
V_96 -> V_6 = V_6 ;
V_96 -> V_85 = V_85 ;
F_11 ( & V_99 ) ;
F_48 ( & V_96 -> V_93 , & V_108 ) ;
F_14 ( & V_99 ) ;
return 0 ;
}
static void F_62 ( struct V_5 * V_6 )
{
struct V_95 * V_96 = NULL , * V_97 ;
F_11 ( & V_99 ) ;
F_51 (nm, tmp, &fcoe_netdevs, list) {
if ( V_96 -> V_6 == V_6 ) {
F_52 ( & V_96 -> V_93 ) ;
F_53 ( V_96 ) ;
F_14 ( & V_99 ) ;
return;
}
}
F_14 ( & V_99 ) ;
}
static struct V_84 * F_63 ( struct V_5 * V_6 )
{
struct V_84 * V_85 = NULL ;
struct V_95 * V_96 ;
F_11 ( & V_99 ) ;
F_13 (nm, &fcoe_netdevs, list) {
if ( V_6 == V_96 -> V_6 ) {
V_85 = V_96 -> V_85 ;
F_14 ( & V_99 ) ;
return V_85 ;
}
}
F_14 ( & V_99 ) ;
return NULL ;
}
static struct V_5 * F_64 ( const char * V_100 )
{
char * V_109 ;
char V_110 [ V_104 + 2 ] ;
if ( V_100 ) {
F_65 ( V_110 , V_100 , V_104 ) ;
V_109 = V_110 + strlen ( V_110 ) ;
while ( -- V_109 >= V_110 && * V_109 == '\n' )
* V_109 = '\0' ;
return F_66 ( & V_111 , V_110 ) ;
}
return NULL ;
}
static int F_67 ( struct V_112 * V_113 ,
T_4 V_114 , void * V_115 )
{
struct V_5 * V_6 = V_115 ;
switch ( V_114 ) {
case V_116 :
F_12 ( L_17 ,
V_6 -> V_89 ) ;
F_62 ( V_6 ) ;
break;
}
return V_117 ;
}
static int F_68 ( const char * V_100 , struct V_101 * V_102 )
{
int V_35 = - V_98 ;
struct V_5 * V_6 = NULL ;
struct V_84 * V_85 = NULL ;
enum V_118 V_119 = (enum V_118 ) ( long ) V_102 -> V_120 ;
F_11 ( & V_87 ) ;
V_6 = F_64 ( V_100 ) ;
if ( ! V_6 ) {
F_12 ( L_18 , V_100 ) ;
goto V_121;
}
V_85 = F_63 ( V_6 ) ;
if ( V_85 ) {
F_12 ( L_19
L_20 ,
V_85 -> V_89 , V_6 -> V_89 ) ;
V_35 = - V_90 ;
goto V_122;
}
V_85 = F_46 ( V_6 ) ;
if ( ! V_85 ) {
F_12 ( L_21 ,
V_6 -> V_89 ) ;
goto V_122;
}
V_35 = F_60 ( V_6 , V_85 ) ;
if ( V_35 ) {
F_12 ( L_22
L_23 ,
V_85 -> V_89 , V_6 -> V_89 ) ;
goto V_122;
}
V_35 = V_85 -> V_123 ? V_85 -> V_123 ( V_6 , V_119 ) : - V_98 ;
if ( V_35 )
F_62 ( V_6 ) ;
F_12 ( L_24 ,
V_85 -> V_89 , ( V_35 ) ? L_25 : L_26 ,
V_6 -> V_89 ) ;
V_122:
F_69 ( V_6 ) ;
V_121:
F_14 ( & V_87 ) ;
return V_35 ;
}
static int F_70 ( const char * V_100 , struct V_101 * V_102 )
{
int V_35 = - V_98 ;
struct V_5 * V_6 = NULL ;
struct V_84 * V_85 = NULL ;
F_11 ( & V_87 ) ;
V_6 = F_64 ( V_100 ) ;
if ( ! V_6 ) {
F_12 ( L_27 , V_100 ) ;
goto V_121;
}
V_85 = F_63 ( V_6 ) ;
if ( ! V_85 ) {
F_12 ( L_21 ,
V_6 -> V_89 ) ;
goto V_122;
}
V_35 = V_85 -> V_124 ? V_85 -> V_124 ( V_6 ) : - V_98 ;
F_62 ( V_6 ) ;
F_12 ( L_28 ,
V_85 -> V_89 , ( V_35 ) ? L_25 : L_26 ,
V_6 -> V_89 ) ;
V_122:
F_69 ( V_6 ) ;
V_121:
F_14 ( & V_87 ) ;
return V_35 ;
}
static int F_71 ( const char * V_100 , struct V_101 * V_102 )
{
int V_35 = - V_98 ;
struct V_5 * V_6 = NULL ;
struct V_84 * V_85 = NULL ;
F_11 ( & V_87 ) ;
V_6 = F_64 ( V_100 ) ;
if ( ! V_6 )
goto V_121;
V_85 = F_63 ( V_6 ) ;
if ( ! V_85 )
goto V_122;
V_35 = V_85 -> V_125 ? V_85 -> V_125 ( V_6 ) : - V_98 ;
V_122:
F_69 ( V_6 ) ;
V_121:
F_14 ( & V_87 ) ;
if ( V_35 == - V_126 )
return F_72 () ;
else
return V_35 ;
}
static int F_73 ( const char * V_100 , struct V_101 * V_102 )
{
int V_35 = - V_98 ;
struct V_5 * V_6 = NULL ;
struct V_84 * V_85 = NULL ;
F_11 ( & V_87 ) ;
V_6 = F_64 ( V_100 ) ;
if ( ! V_6 )
goto V_121;
V_85 = F_63 ( V_6 ) ;
if ( ! V_85 )
goto V_122;
V_35 = V_85 -> V_127 ? V_85 -> V_127 ( V_6 ) : - V_98 ;
V_122:
F_69 ( V_6 ) ;
V_121:
F_14 ( & V_87 ) ;
return V_35 ;
}
static int T_5 F_74 ( void )
{
int V_35 = 0 ;
V_35 = F_55 () ;
if ( V_35 )
return V_35 ;
V_35 = F_75 () ;
if ( V_35 )
F_57 () ;
return V_35 ;
}
static void T_6 F_76 ( void )
{
F_77 () ;
F_57 () ;
}
