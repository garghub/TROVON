struct V_1 *
F_1 ( void * V_2 , T_1 V_3 , const char * V_4 )
{
struct V_1 * V_5 ;
if ( ! V_6 ) {
F_2 ( V_7 ,
V_8 ,
V_9 ) ;
V_6 = true ;
}
V_5 = F_3 ( V_2 , V_3 , V_4 ) ;
if ( F_4 ( V_5 ) ) {
F_5 ( L_1 ) ;
return F_6 ( - V_10 ) ;
}
return V_5 ;
}
struct V_1 * F_7 ( const char * V_11 , bool V_12 )
{
struct V_1 * V_5 ;
if ( ! V_6 ) {
F_2 ( V_7 ,
V_8 ,
V_9 ) ;
V_6 = true ;
}
if ( V_12 ) {
int V_13 ;
void * V_2 ;
T_1 V_3 ;
V_13 = F_8 ( V_11 , & V_2 , & V_3 ) ;
if ( V_13 )
return F_6 ( - V_14 ) ;
V_5 = F_3 ( V_2 , V_3 , V_11 ) ;
free ( V_2 ) ;
} else
V_5 = F_9 ( V_11 ) ;
if ( F_4 ( V_5 ) ) {
F_5 ( L_2 , V_11 ) ;
return V_5 ;
}
return V_5 ;
}
void F_10 ( void )
{
struct V_1 * V_5 , * V_15 ;
F_11 (obj, tmp) {
F_12 ( V_5 ) ;
F_13 ( V_5 ) ;
}
}
static void
F_14 ( struct V_16 * T_2 V_17 ,
void * V_18 )
{
struct V_19 * V_20 = V_18 ;
F_15 ( & V_20 -> V_21 , 1 ) ;
F_16 ( & V_20 -> V_22 ) ;
F_16 ( & V_20 -> V_23 ) ;
F_16 ( & V_20 -> V_24 ) ;
F_16 ( & V_20 -> V_25 ) ;
free ( V_20 ) ;
}
static int
F_17 ( const char * V_26 , struct V_27 * V_21 )
{
V_21 -> V_28 = true ;
V_21 -> V_29 = F_18 ( V_26 ) ;
if ( ! V_21 -> V_29 )
return - V_30 ;
return 0 ;
}
static int
F_19 ( const char * V_26 , struct V_27 * V_21 )
{
V_21 -> V_28 = false ;
V_21 -> V_29 = F_18 ( V_26 ) ;
if ( ! V_21 -> V_29 )
return - V_30 ;
return 0 ;
}
static int
F_20 ( const char * V_26 , bool * V_31 , bool V_32 )
{
int V_13 ;
bool V_33 ;
if ( ! V_31 )
return - V_10 ;
V_13 = F_21 ( V_26 , & V_33 ) ;
if ( V_13 )
return V_13 ;
* V_31 = V_32 ? ! V_33 : V_33 ;
return 0 ;
}
static int
F_22 ( const char * V_26 ,
struct V_27 * V_21 V_17 )
{
return F_20 ( V_26 , & V_34 . V_35 , true ) ;
}
static int
F_23 ( const char * V_26 ,
struct V_27 * V_21 V_17 )
{
return F_20 ( V_26 , & V_34 . V_36 , false ) ;
}
static int
F_24 ( const char * V_37 , const char * V_26 ,
struct V_27 * V_21 )
{
unsigned int V_38 ;
F_5 ( L_3 , V_37 , V_26 ) ;
for ( V_38 = 0 ; V_38 < F_25 ( V_39 ) ; V_38 ++ )
if ( strcmp ( V_37 , V_39 [ V_38 ] . V_37 ) == 0 )
return V_39 [ V_38 ] . F_26 ( V_26 , V_21 ) ;
F_5 ( L_4 ,
V_37 , V_26 ) ;
F_5 ( L_5 ) ;
for ( V_38 = 0 ; V_38 < F_25 ( V_39 ) ; V_38 ++ )
F_5 ( L_6 , V_39 [ V_38 ] . V_40 ,
V_39 [ V_38 ] . V_41 ) ;
F_5 ( L_7 ) ;
return - V_42 ;
}
static const char *
F_27 ( const char * V_43 , struct V_27 * V_21 )
{
char * V_44 = F_18 ( V_43 ) ;
char * V_45 , * line ;
const char * V_46 = NULL ;
int V_13 = 0 ;
if ( ! V_44 ) {
F_5 ( L_8 ) ;
return F_6 ( - V_30 ) ;
}
line = V_44 ;
while ( ( V_45 = strchr ( line , ';' ) ) ) {
char * V_47 ;
* V_45 = '\0' ;
V_47 = strchr ( line , '=' ) ;
if ( ! V_47 ) {
F_28 ( L_9 ,
line ) ;
F_28 ( L_10 ) ;
goto V_48;
}
* V_47 = '\0' ;
V_13 = F_24 ( line , V_47 + 1 , V_21 ) ;
if ( V_13 )
break;
V_48:
line = V_45 + 1 ;
}
if ( ! V_13 )
V_46 = V_43 + ( line - V_44 ) ;
free ( V_44 ) ;
return V_13 ? F_6 ( V_13 ) : V_46 ;
}
static int
F_29 ( const char * V_43 , const char * * V_49 ,
bool * V_50 , struct V_27 * V_21 )
{
int V_13 ;
const char * V_46 = F_27 ( V_43 , V_21 ) ;
if ( F_4 ( V_46 ) )
return F_30 ( V_46 ) ;
* V_49 = V_46 ;
if ( ! strchr ( V_46 , '=' ) ) {
const char * V_51 = strchr ( V_46 , ':' ) ;
if ( ! V_51 ) {
F_5 ( L_11 ,
V_43 ) ;
return - V_52 ;
}
* V_50 = true ;
return 0 ;
}
* V_50 = false ;
V_13 = F_31 ( V_46 , V_21 ) ;
if ( V_13 < 0 ) {
F_5 ( L_12 ,
V_43 ) ;
return - V_52 ;
}
return 0 ;
}
static int
F_32 ( struct V_16 * T_2 )
{
struct V_27 * V_21 = NULL ;
struct V_19 * V_20 = NULL ;
const char * V_43 , * V_46 ;
bool V_50 = false ;
int V_13 ;
V_34 . V_35 = false ;
V_34 . V_36 = false ;
V_43 = F_33 ( T_2 , false ) ;
if ( F_4 ( V_43 ) ) {
F_5 ( L_13 ) ;
return F_30 ( V_43 ) ;
}
V_20 = calloc ( sizeof( * V_20 ) , 1 ) ;
if ( ! V_20 ) {
F_5 ( L_14 ) ;
return - V_30 ;
}
V_21 = & V_20 -> V_21 ;
F_5 ( L_15 , V_43 ) ;
V_13 = F_29 ( V_43 , & V_46 , & V_50 , V_21 ) ;
if ( V_13 )
goto V_53;
if ( V_50 ) {
char * V_51 = strchr ( V_46 , ':' ) ;
V_20 -> V_50 = true ;
V_20 -> V_24 = F_34 ( V_46 , V_51 - V_46 ) ;
V_20 -> V_25 = F_18 ( V_51 + 1 ) ;
goto V_54;
}
if ( V_21 -> V_55 && strcmp ( V_21 -> V_55 , V_56 ) ) {
F_5 ( L_16 ,
V_43 , V_56 ) ;
V_13 = - V_57 ;
goto V_53;
} else if ( ! V_21 -> V_55 )
V_21 -> V_55 = F_18 ( V_56 ) ;
if ( ! V_21 -> V_55 ) {
F_5 ( L_17 ) ;
V_13 = - V_30 ;
goto V_53;
}
if ( ! V_21 -> V_58 ) {
F_5 ( L_18 ,
V_43 ) ;
V_13 = - V_59 ;
goto V_53;
}
F_5 ( L_19 , V_43 ) ;
V_54:
V_13 = F_35 ( T_2 , V_20 , F_14 ) ;
if ( V_13 ) {
F_5 ( L_20 , V_43 ) ;
goto V_53;
}
return 0 ;
V_53:
if ( V_21 )
F_36 ( V_21 ) ;
free ( V_20 ) ;
return V_13 ;
}
static int F_37 ( void )
{
static int V_13 = 0 ;
static bool V_60 = false ;
if ( V_60 )
return V_13 ;
V_60 = true ;
V_13 = F_38 ( false ) ;
if ( V_13 < 0 )
F_5 ( L_21 ) ;
V_34 . V_61 = V_62 ;
return V_13 ;
}
static int
F_39 ( struct V_16 * T_2 , int V_63 ,
struct V_64 * V_65 , int V_66 ,
struct V_67 * V_68 )
{
struct V_19 * V_20 = F_40 ( T_2 ) ;
struct V_69 * V_70 ;
struct V_27 * V_21 ;
struct V_64 * V_71 ;
T_1 V_72 = 0 ;
int V_38 , V_13 ;
if ( F_4 ( V_20 ) || ! V_20 || V_20 -> V_50 )
goto V_53;
V_21 = & V_20 -> V_21 ;
if ( V_63 < 0 || V_63 >= V_20 -> V_73 )
goto V_53;
for ( V_38 = 0 ; V_38 < V_21 -> V_74 ; V_38 ++ ) {
if ( V_20 -> V_23 [ V_38 ] == V_63 )
break;
}
if ( V_38 >= V_21 -> V_74 ) {
F_5 ( L_22 , V_63 ) ;
return - V_75 ;
}
V_70 = & V_21 -> V_76 [ V_38 ] ;
V_71 = V_20 -> V_22 ;
V_13 = F_41 ( V_70 -> args , V_70 -> V_77 ,
V_71 , & V_72 ,
V_78 - V_66 ) ;
if ( V_13 ) {
const char * V_79 ;
V_79 = F_33 ( T_2 , false ) ;
if ( ! V_79 )
V_79 = L_23 ;
F_5 ( L_24 ,
V_79 ) ;
return V_13 ;
}
memcpy ( & V_71 [ V_72 ] , V_65 ,
sizeof( struct V_64 ) * V_66 ) ;
V_68 -> V_80 = V_71 ;
V_68 -> V_81 = V_72 + V_66 ;
V_68 -> V_82 = NULL ;
return 0 ;
V_53:
F_5 ( L_25 ) ;
return - V_75 ;
}
static int F_42 ( const void * V_83 , const void * V_84 )
{
int V_38 , V_85 ;
const struct V_69 * V_86 =
* ( const struct V_69 * * ) V_83 ;
const struct V_69 * V_87 =
* ( const struct V_69 * * ) V_84 ;
V_85 = V_87 -> V_77 - V_86 -> V_77 ;
if ( V_85 )
return V_85 ;
for ( V_38 = 0 ; V_38 < V_86 -> V_77 ; V_38 ++ ) {
struct V_88 * V_89 , * V_90 ;
struct V_91 * V_92 , * V_93 ;
V_89 = & V_86 -> args [ V_38 ] ;
V_90 = & V_87 -> args [ V_38 ] ;
V_85 = strcmp ( V_89 -> V_26 , V_90 -> V_26 ) ;
if ( V_85 )
return V_85 ;
V_92 = V_89 -> V_94 ;
V_93 = V_90 -> V_94 ;
while ( V_92 && V_93 ) {
V_85 = V_93 -> V_95 - V_92 -> V_95 ;
if ( V_85 )
return V_85 ;
V_92 = V_92 -> V_96 ;
V_93 = V_93 -> V_96 ;
}
if ( V_92 || V_93 )
return V_93 ? 1 : - 1 ;
}
return 0 ;
}
static int F_43 ( struct V_27 * V_21 , int * V_97 ,
int * V_73 )
{
int V_38 , type = 0 ;
struct V_69 * * V_98 ;
T_1 V_99 = sizeof( * V_98 ) * V_21 -> V_74 ;
V_98 = malloc ( V_99 ) ;
if ( ! V_98 ) {
F_5 ( L_26 ) ;
return - V_30 ;
}
F_5 ( L_27 , V_21 -> V_74 ) ;
for ( V_38 = 0 ; V_38 < V_21 -> V_74 ; V_38 ++ )
V_98 [ V_38 ] = & V_21 -> V_76 [ V_38 ] ;
qsort ( V_98 , V_21 -> V_74 , sizeof( * V_98 ) ,
F_42 ) ;
for ( V_38 = 0 ; V_38 < V_21 -> V_74 ; V_38 ++ ) {
int V_63 ;
V_63 = V_98 [ V_38 ] - V_21 -> V_76 ;
if ( V_38 == 0 ) {
V_97 [ V_63 ] = type ;
F_5 ( L_28 , V_63 , type ) ;
continue;
}
if ( F_42 ( V_98 + V_38 , V_98 + V_38 - 1 ) == 0 )
V_97 [ V_63 ] = type ;
else
V_97 [ V_63 ] = ++ type ;
F_5 ( L_28 , V_63 , V_97 [ V_63 ] ) ;
}
free ( V_98 ) ;
* V_73 = type + 1 ;
return 0 ;
}
static int F_44 ( struct V_16 * T_2 )
{
struct V_19 * V_20 = F_40 ( T_2 ) ;
struct V_27 * V_21 ;
bool V_100 = false ;
int V_13 , V_38 ;
if ( F_4 ( V_20 ) || ! V_20 ) {
F_5 ( L_29 ) ;
return - V_101 ;
}
if ( V_20 -> V_50 ) {
V_20 -> V_100 = false ;
return 0 ;
}
V_21 = & V_20 -> V_21 ;
for ( V_38 = 0 ; V_38 < V_21 -> V_74 ; V_38 ++ ) {
struct V_69 * V_70 = & V_21 -> V_76 [ V_38 ] ;
if ( V_70 -> V_77 > 0 ) {
V_100 = true ;
break;
}
}
if ( ! V_100 ) {
V_20 -> V_100 = false ;
return 0 ;
}
V_20 -> V_100 = true ;
V_20 -> V_22 = malloc ( sizeof( struct V_64 ) * V_78 ) ;
if ( ! V_20 -> V_22 ) {
F_5 ( L_30 ) ;
return - V_30 ;
}
V_20 -> V_23 = malloc ( sizeof( int ) * V_21 -> V_74 ) ;
if ( ! V_20 -> V_23 ) {
F_5 ( L_31 ) ;
return - V_30 ;
}
memset ( V_20 -> V_23 , - 1 ,
sizeof( int ) * V_21 -> V_74 ) ;
V_13 = F_43 ( V_21 , V_20 -> V_23 , & V_20 -> V_73 ) ;
if ( V_13 )
return V_13 ;
V_13 = F_45 ( T_2 , V_20 -> V_73 ,
F_39 ) ;
return V_13 ;
}
int F_46 ( struct V_1 * V_5 )
{
int V_13 = 0 ;
struct V_16 * T_2 ;
struct V_19 * V_20 ;
struct V_27 * V_21 ;
V_13 = F_37 () ;
if ( V_13 ) {
F_5 ( L_32 ) ;
return V_13 ;
}
F_47 (prog, obj) {
V_13 = F_32 ( T_2 ) ;
if ( V_13 )
goto V_102;
V_20 = F_40 ( T_2 ) ;
if ( F_4 ( V_20 ) || ! V_20 ) {
V_13 = F_30 ( V_20 ) ;
goto V_102;
}
if ( V_20 -> V_50 ) {
F_48 ( T_2 ) ;
continue;
}
F_49 ( T_2 ) ;
V_21 = & V_20 -> V_21 ;
V_13 = F_50 ( V_21 , 1 ) ;
if ( V_13 < 0 ) {
F_5 ( L_33 ) ;
goto V_102;
}
V_13 = F_51 ( V_21 , 1 ) ;
if ( V_13 < 0 ) {
F_5 ( L_34 ) ;
goto V_102;
}
V_13 = F_44 ( T_2 ) ;
if ( V_13 )
goto V_102;
}
V_102:
return V_13 < 0 ? V_13 : 0 ;
}
int F_12 ( struct V_1 * V_5 )
{
int V_13 , V_85 = 0 ;
struct V_16 * T_2 ;
F_47 (prog, obj) {
struct V_19 * V_20 = F_40 ( T_2 ) ;
int V_38 ;
if ( F_4 ( V_20 ) || ! V_20 || V_20 -> V_50 )
continue;
for ( V_38 = 0 ; V_38 < V_20 -> V_21 . V_74 ; V_38 ++ ) {
struct V_69 * V_70 = & V_20 -> V_21 . V_76 [ V_38 ] ;
char V_103 [ V_104 ] ;
struct V_105 * V_106 ;
snprintf ( V_103 , V_104 ,
L_35 , V_70 -> V_55 , V_70 -> V_58 ) ;
V_103 [ V_104 - 1 ] = '\0' ;
V_106 = F_52 ( V_103 , NULL ) ;
if ( ! V_106 ) {
F_5 ( L_36 ) ;
V_85 = - V_30 ;
continue;
}
V_13 = F_53 ( V_106 ) ;
F_54 ( V_106 ) ;
if ( V_13 ) {
F_5 ( L_37 , V_103 ) ;
V_85 = V_13 ;
continue;
}
}
}
return V_85 ;
}
int F_55 ( struct V_1 * V_5 )
{
int V_13 ;
V_13 = F_56 ( V_5 ) ;
if ( V_13 ) {
F_5 ( L_38 ) ;
return V_13 ;
}
return 0 ;
}
int F_57 ( struct V_1 * V_5 ,
T_3 F_26 ,
void * V_107 )
{
struct V_16 * T_2 ;
int V_13 ;
F_47 (prog, obj) {
struct V_19 * V_20 = F_40 ( T_2 ) ;
struct V_69 * V_70 ;
struct V_27 * V_21 ;
int V_38 , V_108 ;
if ( F_4 ( V_20 ) || ! V_20 ) {
F_5 ( L_39 ) ;
return - V_101 ;
}
if ( V_20 -> V_50 ) {
V_108 = F_58 ( T_2 ) ;
V_13 = (* F_26)( V_20 -> V_24 , V_20 -> V_25 , V_108 , V_107 ) ;
if ( V_13 ) {
F_5 ( L_40 ) ;
return V_13 ;
}
continue;
}
V_21 = & V_20 -> V_21 ;
for ( V_38 = 0 ; V_38 < V_21 -> V_74 ; V_38 ++ ) {
V_70 = & V_21 -> V_76 [ V_38 ] ;
if ( V_20 -> V_100 ) {
int type = V_20 -> V_23 [ V_38 ] ;
V_108 = F_59 ( T_2 , type ) ;
} else {
V_108 = F_58 ( T_2 ) ;
}
if ( V_108 < 0 ) {
F_5 ( L_41 ) ;
return V_108 ;
}
V_13 = (* F_26)( V_70 -> V_55 , V_70 -> V_58 , V_108 , V_107 ) ;
if ( V_13 ) {
F_5 ( L_42 ) ;
return V_13 ;
}
}
}
return 0 ;
}
static void
F_60 ( struct V_109 * V_110 )
{
if ( ! F_61 ( & V_110 -> V_111 ) )
F_62 ( & V_110 -> V_111 ) ;
if ( V_110 -> V_112 == V_113 )
F_63 ( & V_110 -> V_114 . V_115 ) ;
free ( V_110 ) ;
}
static void
F_64 ( struct V_116 * V_20 )
{
struct V_109 * V_117 , * V_63 ;
F_65 (pos, n, &priv->ops_list, list) {
F_66 ( & V_117 -> V_111 ) ;
F_60 ( V_117 ) ;
}
}
static void
F_67 ( struct V_118 * T_4 V_17 ,
void * V_18 )
{
struct V_116 * V_20 = V_18 ;
F_64 ( V_20 ) ;
free ( V_20 ) ;
}
static int
F_68 ( struct V_109 * V_110 , struct V_119 * V_120 )
{
V_110 -> V_112 = V_121 ;
if ( ! V_120 )
return 0 ;
if ( V_120 -> V_115 . V_122 ) {
T_1 V_123 = V_120 -> V_115 . V_122 *
sizeof( V_110 -> V_114 . V_115 . V_124 [ 0 ] ) ;
V_110 -> V_114 . V_115 . V_124 = F_69 ( V_120 -> V_115 . V_124 , V_123 ) ;
if ( ! V_110 -> V_114 . V_115 . V_124 ) {
F_5 ( L_43 ) ;
return - V_30 ;
}
V_110 -> V_112 = V_113 ;
V_110 -> V_114 . V_115 . V_122 = V_120 -> V_115 . V_122 ;
}
return 0 ;
}
static struct V_109 *
F_70 ( struct V_119 * V_120 )
{
struct V_109 * V_110 ;
int V_13 ;
V_110 = F_71 ( sizeof( * V_110 ) ) ;
if ( ! V_110 ) {
F_5 ( L_44 ) ;
return F_6 ( - V_30 ) ;
}
F_72 ( & V_110 -> V_111 ) ;
V_13 = F_68 ( V_110 , V_120 ) ;
if ( V_13 ) {
free ( V_110 ) ;
return F_6 ( V_13 ) ;
}
return V_110 ;
}
static struct V_109 *
F_73 ( struct V_109 * V_110 )
{
struct V_109 * V_125 ;
V_125 = F_69 ( V_110 , sizeof( * V_110 ) ) ;
if ( ! V_125 ) {
F_5 ( L_44 ) ;
return NULL ;
}
F_72 ( & V_125 -> V_111 ) ;
if ( V_110 -> V_112 == V_113 ) {
T_1 V_123 = V_110 -> V_114 . V_115 . V_122 *
sizeof( V_110 -> V_114 . V_115 . V_124 [ 0 ] ) ;
V_125 -> V_114 . V_115 . V_124 = F_69 ( V_110 -> V_114 . V_115 . V_124 , V_123 ) ;
if ( ! V_125 -> V_114 . V_115 . V_124 ) {
F_5 ( L_45 ) ;
free ( V_125 ) ;
return NULL ;
}
}
return V_125 ;
}
static struct V_116 *
F_74 ( struct V_116 * V_20 )
{
struct V_116 * V_126 ;
struct V_109 * V_117 , * V_125 ;
V_126 = F_71 ( sizeof( * V_126 ) ) ;
if ( ! V_126 ) {
F_5 ( L_46 ) ;
return NULL ;
}
F_72 ( & V_126 -> V_127 ) ;
F_75 (pos, &priv->ops_list, list) {
V_125 = F_73 ( V_117 ) ;
if ( ! V_125 ) {
F_64 ( V_126 ) ;
return NULL ;
}
F_76 ( & V_125 -> V_111 , & V_126 -> V_127 ) ;
}
return V_126 ;
}
static int
F_77 ( struct V_118 * T_4 , struct V_109 * V_110 )
{
const char * V_128 = F_78 ( T_4 ) ;
struct V_116 * V_20 = F_79 ( T_4 ) ;
if ( F_4 ( V_20 ) ) {
F_5 ( L_47 , V_128 ) ;
return F_30 ( V_20 ) ;
}
if ( ! V_20 ) {
V_20 = F_71 ( sizeof( * V_20 ) ) ;
if ( ! V_20 ) {
F_5 ( L_46 ) ;
return - V_30 ;
}
F_72 ( & V_20 -> V_127 ) ;
if ( F_80 ( T_4 , V_20 , F_67 ) ) {
free ( V_20 ) ;
return - V_101 ;
}
}
F_76 ( & V_110 -> V_111 , & V_20 -> V_127 ) ;
return 0 ;
}
static struct V_109 *
F_81 ( struct V_118 * T_4 , struct V_119 * V_120 )
{
struct V_109 * V_110 ;
int V_13 ;
V_110 = F_70 ( V_120 ) ;
if ( F_4 ( V_110 ) )
return V_110 ;
V_13 = F_77 ( T_4 , V_110 ) ;
if ( V_13 ) {
F_60 ( V_110 ) ;
return F_6 ( V_13 ) ;
}
return V_110 ;
}
static int
F_82 ( struct V_118 * T_4 ,
struct V_119 * V_120 )
{
struct V_109 * V_110 ;
const char * V_128 = F_78 ( T_4 ) ;
const struct V_129 * V_130 = F_83 ( T_4 ) ;
if ( F_4 ( V_130 ) ) {
F_5 ( L_48 ,
V_128 ) ;
return - V_101 ;
}
if ( V_130 -> type != V_131 ) {
F_5 ( L_49 ,
V_128 ) ;
return - V_132 ;
}
if ( V_130 -> V_133 < sizeof( unsigned int ) ) {
F_5 ( L_50 , V_128 ) ;
return - V_134 ;
}
switch ( V_130 -> V_135 ) {
case 1 :
case 2 :
case 4 :
case 8 :
break;
default:
F_5 ( L_51 , V_128 ) ;
return - V_136 ;
}
V_110 = F_81 ( T_4 , V_120 ) ;
if ( F_4 ( V_110 ) )
return F_30 ( V_110 ) ;
V_110 -> V_137 = V_138 ;
V_110 -> V_139 . V_26 = V_120 -> V_140 . V_141 ;
return 0 ;
}
static int
F_84 ( struct V_118 * T_4 ,
struct V_119 * V_120 ,
struct V_142 * T_5 V_17 )
{
if ( ! V_120 -> V_143 ) {
F_5 ( L_52 ) ;
return - V_144 ;
}
if ( V_120 -> V_145 != V_146 ) {
F_5 ( L_53 ) ;
return - V_147 ;
}
return F_82 ( T_4 , V_120 ) ;
}
static int
F_85 ( struct V_118 * T_4 ,
struct V_119 * V_120 ,
struct V_142 * T_5 )
{
struct V_148 * V_149 ;
const struct V_129 * V_130 ;
struct V_109 * V_110 ;
const char * V_128 = F_78 ( T_4 ) ;
V_149 = F_86 ( T_5 , V_120 -> V_140 . V_150 ) ;
if ( ! V_149 ) {
F_5 ( L_54 ,
V_128 , V_120 -> V_140 . V_150 ) ;
return - V_151 ;
}
V_130 = F_83 ( T_4 ) ;
if ( F_4 ( V_130 ) ) {
F_5 ( L_48 ,
V_128 ) ;
return F_30 ( V_130 ) ;
}
if ( V_130 -> type != V_152 ) {
F_5 ( L_55 ,
V_128 ) ;
return - V_132 ;
}
V_110 = F_81 ( T_4 , V_120 ) ;
if ( F_4 ( V_110 ) )
return F_30 ( V_110 ) ;
V_110 -> V_137 = V_153 ;
V_110 -> V_139 . V_149 = V_149 ;
return 0 ;
}
static int
F_87 ( struct V_118 * T_4 ,
struct V_119 * V_120 ,
struct V_142 * T_5 )
{
if ( ! V_120 -> V_143 ) {
F_5 ( L_52 ) ;
return - V_144 ;
}
if ( V_120 -> V_145 != V_154 ) {
F_5 ( L_56 ) ;
return - V_147 ;
}
return F_85 ( T_4 , V_120 , T_5 ) ;
}
static int
F_88 ( struct V_119 * V_120 ,
struct V_118 * T_4 ,
const char * V_128 )
{
struct V_155 * V_115 = & V_120 -> V_115 ;
const struct V_129 * V_130 ;
unsigned int V_38 ;
if ( ! V_115 -> V_122 )
return 0 ;
if ( ! V_115 -> V_124 ) {
F_5 ( L_57 ,
V_128 , ( int ) V_115 -> V_122 ) ;
return - V_101 ;
}
V_130 = F_83 ( T_4 ) ;
if ( F_4 ( V_130 ) ) {
F_5 ( L_58 ,
V_128 ) ;
return - V_101 ;
}
for ( V_38 = 0 ; V_38 < V_115 -> V_122 ; V_38 ++ ) {
unsigned int V_156 = V_115 -> V_124 [ V_38 ] . V_156 ;
T_1 V_157 = V_115 -> V_124 [ V_38 ] . V_157 ;
unsigned int V_158 = V_156 + V_157 - 1 ;
if ( V_158 >= V_130 -> V_159 ) {
F_5 ( L_59 , V_158 ) ;
return - V_160 ;
}
}
return 0 ;
}
static int
F_89 ( struct V_1 * V_5 ,
struct V_119 * V_120 ,
struct V_142 * T_5 ,
int * V_161 )
{
char * V_128 = F_18 ( V_120 -> V_162 + sizeof( L_60 ) - 1 ) ;
struct V_118 * T_4 ;
int V_13 = - V_163 ;
char * V_164 ;
T_1 V_38 ;
if ( ! V_128 )
return - V_30 ;
V_164 = strchr ( V_128 , '.' ) ;
if ( ! V_164 ) {
F_5 ( L_61 , V_128 ) ;
goto V_102;
}
* V_164 ++ = '\0' ;
if ( * V_164 == '\0' ) {
F_5 ( L_62 , V_120 -> V_162 ) ;
goto V_102;
}
T_4 = F_90 ( V_5 , V_128 ) ;
if ( ! T_4 ) {
F_5 ( L_63 , V_128 ) ;
V_13 = - V_165 ;
goto V_102;
}
* V_161 += strlen ( V_164 ) ;
V_13 = F_88 ( V_120 , T_4 , V_128 ) ;
if ( V_13 )
goto V_102;
* V_161 -= strlen ( V_164 ) ;
for ( V_38 = 0 ; V_38 < F_25 ( V_166 ) ; V_38 ++ ) {
struct V_167 * F_26 =
& V_166 [ V_38 ] ;
if ( strcmp ( V_164 , F_26 -> V_168 ) == 0 ) {
V_13 = F_26 -> V_169 ( T_4 , V_120 , T_5 ) ;
goto V_102;
}
}
F_5 ( L_64 , V_164 ) ;
V_13 = - V_170 ;
V_102:
free ( V_128 ) ;
if ( ! V_13 )
V_161 += strlen ( V_164 ) ;
return V_13 ;
}
int F_91 ( struct V_1 * V_5 ,
struct V_119 * V_120 ,
struct V_142 * T_5 ,
int * V_171 )
{
int V_161 = 0 ;
int V_13 ;
if ( ! V_5 || ! V_120 || ! V_120 -> V_162 )
return - V_10 ;
if ( ! F_92 ( V_120 -> V_162 , L_60 ) ) {
V_161 = sizeof( L_60 ) - 1 ;
V_13 = F_89 ( V_5 , V_120 , T_5 , & V_161 ) ;
goto V_102;
}
V_13 = - V_163 ;
V_102:
if ( V_171 )
* V_171 = V_161 ;
return V_13 ;
}
static int
F_93 ( T_6 F_26 ,
void * V_107 , const char * V_4 ,
int V_172 , const struct V_129 * V_173 ,
struct V_109 * V_110 )
{
unsigned int V_38 ;
int V_13 ;
for ( V_38 = 0 ; V_38 < V_173 -> V_159 ; V_38 ++ ) {
V_13 = F_26 ( V_4 , V_172 , V_173 , V_110 , & V_38 , V_107 ) ;
if ( V_13 ) {
F_5 ( L_65 ,
V_4 , V_38 ) ;
return V_13 ;
}
}
return 0 ;
}
static int
F_94 ( T_6 F_26 , void * V_107 ,
const char * V_4 , int V_172 ,
const struct V_129 * V_173 ,
struct V_109 * V_110 )
{
unsigned int V_38 , V_174 ;
int V_13 ;
for ( V_38 = 0 ; V_38 < V_110 -> V_114 . V_115 . V_122 ; V_38 ++ ) {
unsigned int V_156 = V_110 -> V_114 . V_115 . V_124 [ V_38 ] . V_156 ;
T_1 V_157 = V_110 -> V_114 . V_115 . V_124 [ V_38 ] . V_157 ;
for ( V_174 = 0 ; V_174 < V_157 ; V_174 ++ ) {
unsigned int V_158 = V_156 + V_174 ;
V_13 = F_26 ( V_4 , V_172 , V_173 , V_110 , & V_158 , V_107 ) ;
if ( V_13 ) {
F_5 ( L_65 ,
V_4 , V_158 ) ;
return V_13 ;
}
}
}
return 0 ;
}
static int
F_95 ( struct V_118 * T_4 ,
T_6 F_26 ,
void * V_107 )
{
int V_13 , V_172 ;
struct V_109 * V_110 ;
const struct V_129 * V_130 ;
const char * V_4 = F_78 ( T_4 ) ;
struct V_116 * V_20 = F_79 ( T_4 ) ;
if ( F_4 ( V_20 ) ) {
F_5 ( L_66 , V_4 ) ;
return - V_101 ;
}
if ( ! V_20 || F_61 ( & V_20 -> V_127 ) ) {
F_5 ( L_67 , V_4 ) ;
return 0 ;
}
V_130 = F_83 ( T_4 ) ;
if ( F_4 ( V_130 ) ) {
F_5 ( L_68 , V_4 ) ;
return - V_101 ;
}
V_172 = F_96 ( T_4 ) ;
if ( V_172 < 0 ) {
F_5 ( L_69 , V_4 ) ;
return V_172 ;
}
F_75 (op, &priv->ops_list, list) {
switch ( V_130 -> type ) {
case V_131 :
case V_152 :
switch ( V_110 -> V_112 ) {
case V_121 :
V_13 = F_93 ( F_26 , V_107 , V_4 ,
V_172 , V_130 , V_110 ) ;
break;
case V_113 :
V_13 = F_94 ( F_26 , V_107 , V_4 ,
V_172 , V_130 ,
V_110 ) ;
break;
default:
F_5 ( L_70 ,
V_4 ) ;
return - V_101 ;
}
if ( V_13 )
return V_13 ;
break;
default:
F_5 ( L_71 , V_4 ) ;
return - V_132 ;
}
}
return 0 ;
}
static int
F_97 ( int V_172 , void * V_175 ,
T_1 V_176 , T_7 V_140 )
{
int V_13 = 0 ;
switch ( V_176 ) {
case 1 : {
T_8 V_177 = ( T_8 ) ( V_140 ) ;
V_13 = F_98 ( V_172 , V_175 , & V_177 , V_178 ) ;
break;
}
case 2 : {
T_9 V_177 = ( T_9 ) ( V_140 ) ;
V_13 = F_98 ( V_172 , V_175 , & V_177 , V_178 ) ;
break;
}
case 4 : {
T_10 V_177 = ( T_10 ) ( V_140 ) ;
V_13 = F_98 ( V_172 , V_175 , & V_177 , V_178 ) ;
break;
}
case 8 : {
V_13 = F_98 ( V_172 , V_175 , & V_140 , V_178 ) ;
break;
}
default:
F_5 ( L_72 ) ;
return - V_136 ;
}
if ( V_13 && V_179 )
V_13 = - V_179 ;
return V_13 ;
}
static int
F_99 ( const char * V_4 , int V_172 , void * V_175 ,
struct V_148 * V_149 )
{
struct V_180 * V_181 = V_149 -> V_108 ;
struct V_182 * V_183 ;
unsigned int V_37 , V_184 ;
bool V_185 = false ;
int * V_186 ;
int V_13 ;
if ( ! V_181 ) {
F_5 ( L_73 , V_4 ) ;
return - V_101 ;
}
if ( V_181 -> V_187 / V_181 -> V_188 != 1 ) {
F_5 ( L_74 ,
V_4 ) ;
return - V_189 ;
}
V_183 = & V_149 -> V_183 ;
if ( V_183 -> V_190 ) {
F_5 ( L_75 , V_4 ) ;
return - V_191 ;
}
if ( F_100 ( V_149 ) )
V_185 = true ;
if ( V_183 -> type == V_192 )
V_185 = true ;
if ( V_183 -> type == V_193 )
V_185 = true ;
if ( ! V_185 ) {
F_5 ( L_76 , V_4 ) ;
return - V_194 ;
}
V_184 = V_181 -> V_195 / ( V_181 -> V_187 / V_181 -> V_188 ) ;
V_37 = * ( ( unsigned int * ) V_175 ) ;
if ( V_37 >= V_184 ) {
F_5 ( L_77 ,
V_37 , V_4 ) ;
return - V_196 ;
}
V_186 = F_101 ( V_181 , V_37 , 0 ) ;
V_13 = F_98 ( V_172 , V_175 , V_186 , V_178 ) ;
if ( V_13 && V_179 )
V_13 = - V_179 ;
return V_13 ;
}
static int
F_102 ( const char * V_4 , int V_172 ,
const struct V_129 * V_173 ,
struct V_109 * V_110 ,
void * V_175 , void * V_107 V_17 )
{
int V_13 ;
switch ( V_110 -> V_137 ) {
case V_138 :
V_13 = F_97 ( V_172 , V_175 ,
V_173 -> V_135 ,
V_110 -> V_139 . V_26 ) ;
break;
case V_153 :
V_13 = F_99 ( V_4 , V_172 , V_175 ,
V_110 -> V_139 . V_149 ) ;
break;
default:
F_5 ( L_78 , V_4 ) ;
V_13 = - V_101 ;
}
return V_13 ;
}
static int
F_103 ( struct V_118 * T_4 )
{
return F_95 ( T_4 ,
F_102 ,
NULL ) ;
}
static int
F_104 ( struct V_1 * V_5 )
{
struct V_118 * T_4 ;
int V_13 ;
F_105 (map, obj) {
V_13 = F_103 ( T_4 ) ;
if ( V_13 )
return V_13 ;
}
return 0 ;
}
int F_106 ( void )
{
struct V_1 * V_5 , * V_15 ;
int V_13 ;
F_11 (obj, tmp) {
V_13 = F_104 ( V_5 ) ;
if ( V_13 )
return V_13 ;
}
return 0 ;
}
int F_107 ( struct V_142 * T_5 V_17 )
{
struct V_116 * V_197 = NULL ;
struct V_1 * V_5 , * V_15 ;
struct V_148 * V_149 = NULL ;
struct V_118 * T_4 ;
int V_13 ;
bool V_198 = false ;
F_108 (map, obj, tmp) {
struct V_116 * V_20 = F_79 ( T_4 ) ;
if ( F_4 ( V_20 ) )
return - V_101 ;
if ( ! V_198 && ! V_20 )
V_198 = ! V_20 ;
if ( ! V_197 && V_20 )
V_197 = V_20 ;
}
if ( ! V_198 )
return 0 ;
if ( ! V_197 ) {
V_13 = F_109 ( T_5 , L_79 ,
NULL ) ;
if ( V_13 ) {
F_5 ( L_80 ) ;
return - V_13 ;
}
V_149 = F_110 ( T_5 ) ;
}
F_108 (map, obj, tmp) {
struct V_116 * V_20 = F_79 ( T_4 ) ;
if ( F_4 ( V_20 ) )
return - V_101 ;
if ( V_20 )
continue;
if ( V_197 ) {
V_20 = F_74 ( V_197 ) ;
if ( ! V_20 )
return - V_30 ;
V_13 = F_80 ( T_4 , V_20 , F_67 ) ;
if ( V_13 ) {
F_67 ( T_4 , V_20 ) ;
return V_13 ;
}
} else if ( V_149 ) {
struct V_109 * V_110 ;
V_110 = F_81 ( T_4 , NULL ) ;
if ( F_4 ( V_110 ) )
return F_30 ( V_110 ) ;
V_110 -> V_137 = V_153 ;
V_110 -> V_139 . V_149 = V_149 ;
}
}
return 0 ;
}
static int
F_111 ( int V_13 , char * V_71 , T_1 V_199 )
{
char V_200 [ V_201 ] ;
const char * V_202 ;
if ( ! V_71 || ! V_199 )
return - 1 ;
V_13 = V_13 > 0 ? V_13 : - V_13 ;
if ( V_13 >= V_203 )
return F_112 ( V_13 , V_71 , V_199 ) ;
if ( V_13 >= V_204 && V_13 < V_205 ) {
V_202 = V_206 [ F_113 ( V_13 ) ] ;
snprintf ( V_71 , V_199 , L_81 , V_202 ) ;
V_71 [ V_199 - 1 ] = '\0' ;
return 0 ;
}
if ( V_13 >= V_205 )
snprintf ( V_71 , V_199 , L_82 , V_13 ) ;
else
snprintf ( V_71 , V_199 , L_81 ,
F_114 ( V_13 , V_200 , sizeof( V_200 ) ) ) ;
V_71 [ V_199 - 1 ] = '\0' ;
return - 1 ;
}
int F_115 ( const char * V_11 , bool V_12 ,
int V_13 , char * V_71 , T_1 V_199 )
{
T_1 V_63 ;
int V_85 ;
V_63 = snprintf ( V_71 , V_199 , L_83 ,
V_11 , V_12 ? L_84 : L_85 ) ;
if ( V_63 >= V_199 ) {
V_71 [ V_199 - 1 ] = '\0' ;
return 0 ;
}
V_71 += V_63 ;
V_199 -= V_63 ;
V_85 = F_111 ( V_13 , V_71 , V_199 ) ;
V_71 [ V_199 - 1 ] = '\0' ;
return V_85 ;
}
int F_116 ( struct V_1 * V_5 V_17 ,
int V_13 , char * V_71 , T_1 V_199 )
{
F_117 ( V_13 , V_71 , V_199 ) ;
case V_42 : {
F_118 ( V_71 , V_199 , L_86 , V_207 ) ;
break;
}
F_119 ( V_208 , L_87 ) ;
F_119 ( V_209 , L_88 ) ;
F_119 ( V_210 , L_89 ) ;
F_119 ( V_211 , L_90 ) ;
F_120 ( V_71 , V_199 ) ;
return 0 ;
}
int F_121 ( struct V_1 * V_5 ,
int V_13 , char * V_71 , T_1 V_199 )
{
F_117 ( V_13 , V_71 , V_199 ) ;
case V_212 : {
unsigned int V_213 = F_122 ( V_5 ) ;
unsigned int V_214 ;
if ( F_123 ( & V_214 , NULL , 0 ) ) {
F_118 ( V_71 , V_199 , L_91 ) ;
break;
}
if ( V_213 != V_214 ) {
F_118 ( V_71 , V_199 ,
L_92 V_215 L_93 V_215 L_94 ,
F_124 ( V_213 ) ,
F_124 ( V_214 ) ) ;
break;
}
F_118 ( V_71 , V_199 , L_95 ) ;
break;
}
F_120 ( V_71 , V_199 ) ;
return 0 ;
}
int F_125 ( struct V_1 * V_5 V_17 ,
struct V_119 * V_120 V_17 ,
struct V_142 * T_5 V_17 ,
int * V_171 V_17 , int V_13 ,
char * V_71 , T_1 V_199 )
{
F_117 ( V_13 , V_71 , V_199 ) ;
F_119 ( V_132 ,
L_96 ) ;
F_120 ( V_71 , V_199 ) ;
return 0 ;
}
int F_126 ( int V_13 , char * V_71 , T_1 V_199 )
{
F_117 ( V_13 , V_71 , V_199 ) ;
F_119 ( V_189 ,
L_97 ) ;
F_119 ( V_191 ,
L_98 , V_207 ) ;
F_119 ( V_194 ,
L_99 ) ;
F_120 ( V_71 , V_199 ) ;
return 0 ;
}
int F_127 ( struct V_142 * T_5 V_17 ,
int V_13 , char * V_71 , T_1 V_199 )
{
F_117 ( V_13 , V_71 , V_199 ) ;
F_120 ( V_71 , V_199 ) ;
return 0 ;
}
