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
F_8 () ;
V_13 = F_9 ( V_11 , & V_2 , & V_3 ) ;
F_10 () ;
if ( V_13 ) {
F_11 ( L_2 , V_13 ) ;
V_13 = F_12 ( V_11 , & V_2 , & V_3 ) ;
if ( V_13 )
return F_6 ( - V_14 ) ;
} else
F_5 ( L_3 ) ;
V_5 = F_3 ( V_2 , V_3 , V_11 ) ;
if ( ! F_4 ( V_5 ) && V_15 . V_16 )
F_13 ( V_11 , V_2 , V_3 ) ;
free ( V_2 ) ;
} else
V_5 = F_14 ( V_11 ) ;
if ( F_4 ( V_5 ) ) {
F_5 ( L_4 , V_11 ) ;
return V_5 ;
}
return V_5 ;
}
void F_15 ( void )
{
struct V_1 * V_5 , * V_17 ;
F_16 (obj, tmp) {
F_17 ( V_5 ) ;
F_18 ( V_5 ) ;
}
}
static void
F_19 ( struct V_18 * T_2 V_19 ,
void * V_20 )
{
struct V_21 * V_22 = V_20 ;
F_20 ( & V_22 -> V_23 , 1 ) ;
F_21 ( & V_22 -> V_24 ) ;
F_21 ( & V_22 -> V_25 ) ;
F_21 ( & V_22 -> V_26 ) ;
F_21 ( & V_22 -> V_27 ) ;
free ( V_22 ) ;
}
static int
F_22 ( const char * V_28 , struct V_29 * V_23 )
{
V_23 -> V_30 = true ;
V_23 -> V_31 = F_23 ( V_28 ) ;
if ( ! V_23 -> V_31 )
return - V_32 ;
return 0 ;
}
static int
F_24 ( const char * V_28 , struct V_29 * V_23 )
{
V_23 -> V_30 = false ;
V_23 -> V_31 = F_23 ( V_28 ) ;
if ( ! V_23 -> V_31 )
return - V_32 ;
return 0 ;
}
static int
F_25 ( const char * V_28 , bool * V_33 , bool V_34 )
{
int V_13 ;
bool V_35 ;
if ( ! V_33 )
return - V_10 ;
V_13 = F_26 ( V_28 , & V_35 ) ;
if ( V_13 )
return V_13 ;
* V_33 = V_34 ? ! V_35 : V_35 ;
return 0 ;
}
static int
F_27 ( const char * V_28 ,
struct V_29 * V_23 V_19 )
{
return F_25 ( V_28 , & V_36 . V_37 , true ) ;
}
static int
F_28 ( const char * V_28 ,
struct V_29 * V_23 V_19 )
{
return F_25 ( V_28 , & V_36 . V_38 , false ) ;
}
static int
F_29 ( const char * V_39 , const char * V_28 ,
struct V_29 * V_23 )
{
unsigned int V_40 ;
F_5 ( L_5 , V_39 , V_28 ) ;
for ( V_40 = 0 ; V_40 < F_30 ( V_41 ) ; V_40 ++ )
if ( strcmp ( V_39 , V_41 [ V_40 ] . V_39 ) == 0 )
return V_41 [ V_40 ] . F_31 ( V_28 , V_23 ) ;
F_5 ( L_6 ,
V_39 , V_28 ) ;
F_5 ( L_7 ) ;
for ( V_40 = 0 ; V_40 < F_30 ( V_41 ) ; V_40 ++ )
F_5 ( L_8 , V_41 [ V_40 ] . V_42 ,
V_41 [ V_40 ] . V_43 ) ;
F_5 ( L_9 ) ;
return - V_44 ;
}
static const char *
F_32 ( const char * V_45 , struct V_29 * V_23 )
{
char * V_46 = F_23 ( V_45 ) ;
char * V_47 , * line ;
const char * V_48 = NULL ;
int V_13 = 0 ;
if ( ! V_46 ) {
F_5 ( L_10 ) ;
return F_6 ( - V_32 ) ;
}
line = V_46 ;
while ( ( V_47 = strchr ( line , ';' ) ) ) {
char * V_49 ;
* V_47 = '\0' ;
V_49 = strchr ( line , '=' ) ;
if ( ! V_49 ) {
F_11 ( L_11 ,
line ) ;
F_11 ( L_12 ) ;
goto V_50;
}
* V_49 = '\0' ;
V_13 = F_29 ( line , V_49 + 1 , V_23 ) ;
if ( V_13 )
break;
V_50:
line = V_47 + 1 ;
}
if ( ! V_13 )
V_48 = V_45 + ( line - V_46 ) ;
free ( V_46 ) ;
return V_13 ? F_6 ( V_13 ) : V_48 ;
}
static int
F_33 ( const char * V_45 , const char * * V_51 ,
bool * V_52 , struct V_29 * V_23 )
{
int V_13 ;
const char * V_48 = F_32 ( V_45 , V_23 ) ;
if ( F_4 ( V_48 ) )
return F_34 ( V_48 ) ;
* V_51 = V_48 ;
if ( ! strchr ( V_48 , '=' ) ) {
const char * V_53 = strchr ( V_48 , ':' ) ;
if ( ! V_53 ) {
F_5 ( L_13 ,
V_45 ) ;
return - V_54 ;
}
* V_52 = true ;
return 0 ;
}
* V_52 = false ;
V_13 = F_35 ( V_48 , V_23 ) ;
if ( V_13 < 0 ) {
F_5 ( L_14 ,
V_45 ) ;
return - V_54 ;
}
return 0 ;
}
static int
F_36 ( struct V_18 * T_2 )
{
struct V_29 * V_23 = NULL ;
struct V_21 * V_22 = NULL ;
const char * V_45 , * V_48 ;
bool V_52 = false ;
int V_13 ;
V_36 . V_37 = false ;
V_36 . V_38 = false ;
V_45 = F_37 ( T_2 , false ) ;
if ( F_4 ( V_45 ) ) {
F_5 ( L_15 ) ;
return F_34 ( V_45 ) ;
}
V_22 = calloc ( sizeof( * V_22 ) , 1 ) ;
if ( ! V_22 ) {
F_5 ( L_16 ) ;
return - V_32 ;
}
V_23 = & V_22 -> V_23 ;
F_5 ( L_17 , V_45 ) ;
V_13 = F_33 ( V_45 , & V_48 , & V_52 , V_23 ) ;
if ( V_13 )
goto V_55;
if ( V_52 ) {
char * V_53 = strchr ( V_48 , ':' ) ;
V_22 -> V_52 = true ;
V_22 -> V_26 = F_38 ( V_48 , V_53 - V_48 ) ;
V_22 -> V_27 = F_23 ( V_53 + 1 ) ;
goto V_56;
}
if ( V_23 -> V_57 && strcmp ( V_23 -> V_57 , V_58 ) ) {
F_5 ( L_18 ,
V_45 , V_58 ) ;
V_13 = - V_59 ;
goto V_55;
} else if ( ! V_23 -> V_57 )
V_23 -> V_57 = F_23 ( V_58 ) ;
if ( ! V_23 -> V_57 ) {
F_5 ( L_19 ) ;
V_13 = - V_32 ;
goto V_55;
}
if ( ! V_23 -> V_60 ) {
F_5 ( L_20 ,
V_45 ) ;
V_13 = - V_61 ;
goto V_55;
}
F_5 ( L_21 , V_45 ) ;
V_56:
V_13 = F_39 ( T_2 , V_22 , F_19 ) ;
if ( V_13 ) {
F_5 ( L_22 , V_45 ) ;
goto V_55;
}
return 0 ;
V_55:
if ( V_23 )
F_40 ( V_23 ) ;
free ( V_22 ) ;
return V_13 ;
}
static int F_41 ( void )
{
static int V_13 = 0 ;
static bool V_62 = false ;
if ( V_62 )
return V_13 ;
V_62 = true ;
V_13 = F_42 ( false ) ;
if ( V_13 < 0 )
F_5 ( L_23 ) ;
V_36 . V_63 = V_64 ;
return V_13 ;
}
static int
F_43 ( struct V_18 * T_2 , int V_65 ,
struct V_66 * V_67 , int V_68 ,
struct V_69 * V_70 )
{
struct V_21 * V_22 = F_44 ( T_2 ) ;
struct V_71 * V_72 ;
struct V_29 * V_23 ;
struct V_66 * V_73 ;
T_1 V_74 = 0 ;
int V_40 , V_13 ;
if ( F_4 ( V_22 ) || ! V_22 || V_22 -> V_52 )
goto V_55;
V_23 = & V_22 -> V_23 ;
if ( V_65 < 0 || V_65 >= V_22 -> V_75 )
goto V_55;
for ( V_40 = 0 ; V_40 < V_23 -> V_76 ; V_40 ++ ) {
if ( V_22 -> V_25 [ V_40 ] == V_65 )
break;
}
if ( V_40 >= V_23 -> V_76 ) {
F_5 ( L_24 , V_65 ) ;
return - V_77 ;
}
V_72 = & V_23 -> V_78 [ V_40 ] ;
V_73 = V_22 -> V_24 ;
V_13 = F_45 ( V_72 -> args , V_72 -> V_79 ,
V_73 , & V_74 ,
V_80 - V_68 ) ;
if ( V_13 ) {
const char * V_81 ;
V_81 = F_37 ( T_2 , false ) ;
if ( ! V_81 )
V_81 = L_25 ;
F_5 ( L_26 ,
V_81 ) ;
return V_13 ;
}
memcpy ( & V_73 [ V_74 ] , V_67 ,
sizeof( struct V_66 ) * V_68 ) ;
V_70 -> V_82 = V_73 ;
V_70 -> V_83 = V_74 + V_68 ;
V_70 -> V_84 = NULL ;
return 0 ;
V_55:
F_5 ( L_27 ) ;
return - V_77 ;
}
static int F_46 ( const void * V_85 , const void * V_86 )
{
int V_40 , V_87 ;
const struct V_71 * V_88 =
* ( const struct V_71 * * ) V_85 ;
const struct V_71 * V_89 =
* ( const struct V_71 * * ) V_86 ;
V_87 = V_89 -> V_79 - V_88 -> V_79 ;
if ( V_87 )
return V_87 ;
for ( V_40 = 0 ; V_40 < V_88 -> V_79 ; V_40 ++ ) {
struct V_90 * V_91 , * V_92 ;
struct V_93 * V_94 , * V_95 ;
V_91 = & V_88 -> args [ V_40 ] ;
V_92 = & V_89 -> args [ V_40 ] ;
V_87 = strcmp ( V_91 -> V_28 , V_92 -> V_28 ) ;
if ( V_87 )
return V_87 ;
V_94 = V_91 -> V_96 ;
V_95 = V_92 -> V_96 ;
while ( V_94 && V_95 ) {
V_87 = V_95 -> V_97 - V_94 -> V_97 ;
if ( V_87 )
return V_87 ;
V_94 = V_94 -> V_98 ;
V_95 = V_95 -> V_98 ;
}
if ( V_94 || V_95 )
return V_95 ? 1 : - 1 ;
}
return 0 ;
}
static int F_47 ( struct V_29 * V_23 , int * V_99 ,
int * V_75 )
{
int V_40 , type = 0 ;
struct V_71 * * V_100 ;
T_1 V_101 = sizeof( * V_100 ) * V_23 -> V_76 ;
V_100 = malloc ( V_101 ) ;
if ( ! V_100 ) {
F_5 ( L_28 ) ;
return - V_32 ;
}
F_5 ( L_29 , V_23 -> V_76 ) ;
for ( V_40 = 0 ; V_40 < V_23 -> V_76 ; V_40 ++ )
V_100 [ V_40 ] = & V_23 -> V_78 [ V_40 ] ;
qsort ( V_100 , V_23 -> V_76 , sizeof( * V_100 ) ,
F_46 ) ;
for ( V_40 = 0 ; V_40 < V_23 -> V_76 ; V_40 ++ ) {
int V_65 ;
V_65 = V_100 [ V_40 ] - V_23 -> V_78 ;
if ( V_40 == 0 ) {
V_99 [ V_65 ] = type ;
F_5 ( L_30 , V_65 , type ) ;
continue;
}
if ( F_46 ( V_100 + V_40 , V_100 + V_40 - 1 ) == 0 )
V_99 [ V_65 ] = type ;
else
V_99 [ V_65 ] = ++ type ;
F_5 ( L_30 , V_65 , V_99 [ V_65 ] ) ;
}
free ( V_100 ) ;
* V_75 = type + 1 ;
return 0 ;
}
static int F_48 ( struct V_18 * T_2 )
{
struct V_21 * V_22 = F_44 ( T_2 ) ;
struct V_29 * V_23 ;
bool V_102 = false ;
int V_13 , V_40 ;
if ( F_4 ( V_22 ) || ! V_22 ) {
F_5 ( L_31 ) ;
return - V_103 ;
}
if ( V_22 -> V_52 ) {
V_22 -> V_102 = false ;
return 0 ;
}
V_23 = & V_22 -> V_23 ;
for ( V_40 = 0 ; V_40 < V_23 -> V_76 ; V_40 ++ ) {
struct V_71 * V_72 = & V_23 -> V_78 [ V_40 ] ;
if ( V_72 -> V_79 > 0 ) {
V_102 = true ;
break;
}
}
if ( ! V_102 ) {
V_22 -> V_102 = false ;
return 0 ;
}
V_22 -> V_102 = true ;
V_22 -> V_24 = malloc ( sizeof( struct V_66 ) * V_80 ) ;
if ( ! V_22 -> V_24 ) {
F_5 ( L_32 ) ;
return - V_32 ;
}
V_22 -> V_25 = malloc ( sizeof( int ) * V_23 -> V_76 ) ;
if ( ! V_22 -> V_25 ) {
F_5 ( L_33 ) ;
return - V_32 ;
}
memset ( V_22 -> V_25 , - 1 ,
sizeof( int ) * V_23 -> V_76 ) ;
V_13 = F_47 ( V_23 , V_22 -> V_25 , & V_22 -> V_75 ) ;
if ( V_13 )
return V_13 ;
V_13 = F_49 ( T_2 , V_22 -> V_75 ,
F_43 ) ;
return V_13 ;
}
int F_50 ( struct V_1 * V_5 )
{
int V_13 = 0 ;
struct V_18 * T_2 ;
struct V_21 * V_22 ;
struct V_29 * V_23 ;
V_13 = F_41 () ;
if ( V_13 ) {
F_5 ( L_34 ) ;
return V_13 ;
}
F_51 (prog, obj) {
V_13 = F_36 ( T_2 ) ;
if ( V_13 )
goto V_104;
V_22 = F_44 ( T_2 ) ;
if ( F_4 ( V_22 ) || ! V_22 ) {
V_13 = F_34 ( V_22 ) ;
goto V_104;
}
if ( V_22 -> V_52 ) {
F_52 ( T_2 ) ;
continue;
}
F_53 ( T_2 ) ;
V_23 = & V_22 -> V_23 ;
V_13 = F_54 ( V_23 , 1 ) ;
if ( V_13 < 0 ) {
F_5 ( L_35 ) ;
goto V_104;
}
V_13 = F_55 ( V_23 , 1 ) ;
if ( V_13 < 0 ) {
F_5 ( L_36 ) ;
goto V_104;
}
V_13 = F_48 ( T_2 ) ;
if ( V_13 )
goto V_104;
}
V_104:
return V_13 < 0 ? V_13 : 0 ;
}
int F_17 ( struct V_1 * V_5 )
{
int V_13 , V_87 = 0 ;
struct V_18 * T_2 ;
F_51 (prog, obj) {
struct V_21 * V_22 = F_44 ( T_2 ) ;
int V_40 ;
if ( F_4 ( V_22 ) || ! V_22 || V_22 -> V_52 )
continue;
for ( V_40 = 0 ; V_40 < V_22 -> V_23 . V_76 ; V_40 ++ ) {
struct V_71 * V_72 = & V_22 -> V_23 . V_78 [ V_40 ] ;
char V_105 [ V_106 ] ;
struct V_107 * V_108 ;
snprintf ( V_105 , V_106 ,
L_37 , V_72 -> V_57 , V_72 -> V_60 ) ;
V_105 [ V_106 - 1 ] = '\0' ;
V_108 = F_56 ( V_105 , NULL ) ;
if ( ! V_108 ) {
F_5 ( L_38 ) ;
V_87 = - V_32 ;
continue;
}
V_13 = F_57 ( V_108 ) ;
F_58 ( V_108 ) ;
if ( V_13 ) {
F_5 ( L_39 , V_105 ) ;
V_87 = V_13 ;
continue;
}
}
}
return V_87 ;
}
int F_59 ( struct V_1 * V_5 )
{
int V_13 ;
V_13 = F_60 ( V_5 ) ;
if ( V_13 ) {
F_5 ( L_40 ) ;
return V_13 ;
}
return 0 ;
}
int F_61 ( struct V_1 * V_5 ,
T_3 F_31 ,
void * V_109 )
{
struct V_18 * T_2 ;
int V_13 ;
F_51 (prog, obj) {
struct V_21 * V_22 = F_44 ( T_2 ) ;
struct V_71 * V_72 ;
struct V_29 * V_23 ;
int V_40 , V_110 ;
if ( F_4 ( V_22 ) || ! V_22 ) {
F_5 ( L_41 ) ;
return - V_103 ;
}
if ( V_22 -> V_52 ) {
V_110 = F_62 ( T_2 ) ;
V_13 = (* F_31)( V_22 -> V_26 , V_22 -> V_27 , V_110 , V_109 ) ;
if ( V_13 ) {
F_5 ( L_42 ) ;
return V_13 ;
}
continue;
}
V_23 = & V_22 -> V_23 ;
for ( V_40 = 0 ; V_40 < V_23 -> V_76 ; V_40 ++ ) {
V_72 = & V_23 -> V_78 [ V_40 ] ;
if ( V_22 -> V_102 ) {
int type = V_22 -> V_25 [ V_40 ] ;
V_110 = F_63 ( T_2 , type ) ;
} else {
V_110 = F_62 ( T_2 ) ;
}
if ( V_110 < 0 ) {
F_5 ( L_43 ) ;
return V_110 ;
}
V_13 = (* F_31)( V_72 -> V_57 , V_72 -> V_60 , V_110 , V_109 ) ;
if ( V_13 ) {
F_5 ( L_44 ) ;
return V_13 ;
}
}
}
return 0 ;
}
static void
F_64 ( struct V_111 * V_112 )
{
if ( ! F_65 ( & V_112 -> V_113 ) )
F_66 ( & V_112 -> V_113 ) ;
if ( V_112 -> V_114 == V_115 )
F_67 ( & V_112 -> V_116 . V_117 ) ;
free ( V_112 ) ;
}
static void
F_68 ( struct V_118 * V_22 )
{
struct V_111 * V_119 , * V_65 ;
F_69 (pos, n, &priv->ops_list, list) {
F_70 ( & V_119 -> V_113 ) ;
F_64 ( V_119 ) ;
}
}
static void
F_71 ( struct V_120 * T_4 V_19 ,
void * V_20 )
{
struct V_118 * V_22 = V_20 ;
F_68 ( V_22 ) ;
free ( V_22 ) ;
}
static int
F_72 ( struct V_111 * V_112 , struct V_121 * V_122 )
{
V_112 -> V_114 = V_123 ;
if ( ! V_122 )
return 0 ;
if ( V_122 -> V_117 . V_124 ) {
T_1 V_125 = V_122 -> V_117 . V_124 *
sizeof( V_112 -> V_116 . V_117 . V_126 [ 0 ] ) ;
V_112 -> V_116 . V_117 . V_126 = F_73 ( V_122 -> V_117 . V_126 , V_125 ) ;
if ( ! V_112 -> V_116 . V_117 . V_126 ) {
F_5 ( L_45 ) ;
return - V_32 ;
}
V_112 -> V_114 = V_115 ;
V_112 -> V_116 . V_117 . V_124 = V_122 -> V_117 . V_124 ;
}
return 0 ;
}
static struct V_111 *
F_74 ( struct V_121 * V_122 )
{
struct V_111 * V_112 ;
int V_13 ;
V_112 = F_75 ( sizeof( * V_112 ) ) ;
if ( ! V_112 ) {
F_5 ( L_46 ) ;
return F_6 ( - V_32 ) ;
}
F_76 ( & V_112 -> V_113 ) ;
V_13 = F_72 ( V_112 , V_122 ) ;
if ( V_13 ) {
free ( V_112 ) ;
return F_6 ( V_13 ) ;
}
return V_112 ;
}
static struct V_111 *
F_77 ( struct V_111 * V_112 )
{
struct V_111 * V_127 ;
V_127 = F_73 ( V_112 , sizeof( * V_112 ) ) ;
if ( ! V_127 ) {
F_5 ( L_46 ) ;
return NULL ;
}
F_76 ( & V_127 -> V_113 ) ;
if ( V_112 -> V_114 == V_115 ) {
T_1 V_125 = V_112 -> V_116 . V_117 . V_124 *
sizeof( V_112 -> V_116 . V_117 . V_126 [ 0 ] ) ;
V_127 -> V_116 . V_117 . V_126 = F_73 ( V_112 -> V_116 . V_117 . V_126 , V_125 ) ;
if ( ! V_127 -> V_116 . V_117 . V_126 ) {
F_5 ( L_47 ) ;
free ( V_127 ) ;
return NULL ;
}
}
return V_127 ;
}
static struct V_118 *
F_78 ( struct V_118 * V_22 )
{
struct V_118 * V_128 ;
struct V_111 * V_119 , * V_127 ;
V_128 = F_75 ( sizeof( * V_128 ) ) ;
if ( ! V_128 ) {
F_5 ( L_48 ) ;
return NULL ;
}
F_76 ( & V_128 -> V_129 ) ;
F_79 (pos, &priv->ops_list, list) {
V_127 = F_77 ( V_119 ) ;
if ( ! V_127 ) {
F_68 ( V_128 ) ;
return NULL ;
}
F_80 ( & V_127 -> V_113 , & V_128 -> V_129 ) ;
}
return V_128 ;
}
static int
F_81 ( struct V_120 * T_4 , struct V_111 * V_112 )
{
const char * V_130 = F_82 ( T_4 ) ;
struct V_118 * V_22 = F_83 ( T_4 ) ;
if ( F_4 ( V_22 ) ) {
F_5 ( L_49 , V_130 ) ;
return F_34 ( V_22 ) ;
}
if ( ! V_22 ) {
V_22 = F_75 ( sizeof( * V_22 ) ) ;
if ( ! V_22 ) {
F_5 ( L_48 ) ;
return - V_32 ;
}
F_76 ( & V_22 -> V_129 ) ;
if ( F_84 ( T_4 , V_22 , F_71 ) ) {
free ( V_22 ) ;
return - V_103 ;
}
}
F_80 ( & V_112 -> V_113 , & V_22 -> V_129 ) ;
return 0 ;
}
static struct V_111 *
F_85 ( struct V_120 * T_4 , struct V_121 * V_122 )
{
struct V_111 * V_112 ;
int V_13 ;
V_112 = F_74 ( V_122 ) ;
if ( F_4 ( V_112 ) )
return V_112 ;
V_13 = F_81 ( T_4 , V_112 ) ;
if ( V_13 ) {
F_64 ( V_112 ) ;
return F_6 ( V_13 ) ;
}
return V_112 ;
}
static int
F_86 ( struct V_120 * T_4 ,
struct V_121 * V_122 )
{
struct V_111 * V_112 ;
const char * V_130 = F_82 ( T_4 ) ;
const struct V_131 * V_132 = F_87 ( T_4 ) ;
if ( F_4 ( V_132 ) ) {
F_5 ( L_50 ,
V_130 ) ;
return - V_103 ;
}
if ( V_132 -> type != V_133 ) {
F_5 ( L_51 ,
V_130 ) ;
return - V_134 ;
}
if ( V_132 -> V_135 < sizeof( unsigned int ) ) {
F_5 ( L_52 , V_130 ) ;
return - V_136 ;
}
switch ( V_132 -> V_137 ) {
case 1 :
case 2 :
case 4 :
case 8 :
break;
default:
F_5 ( L_53 , V_130 ) ;
return - V_138 ;
}
V_112 = F_85 ( T_4 , V_122 ) ;
if ( F_4 ( V_112 ) )
return F_34 ( V_112 ) ;
V_112 -> V_139 = V_140 ;
V_112 -> V_141 . V_28 = V_122 -> V_142 . V_143 ;
return 0 ;
}
static int
F_88 ( struct V_120 * T_4 ,
struct V_121 * V_122 ,
struct V_144 * T_5 V_19 )
{
if ( ! V_122 -> V_145 ) {
F_5 ( L_54 ) ;
return - V_146 ;
}
if ( V_122 -> V_147 != V_148 ) {
F_5 ( L_55 ) ;
return - V_149 ;
}
return F_86 ( T_4 , V_122 ) ;
}
static int
F_89 ( struct V_120 * T_4 ,
struct V_121 * V_122 ,
struct V_144 * T_5 )
{
struct V_150 * V_151 ;
const struct V_131 * V_132 ;
struct V_111 * V_112 ;
const char * V_130 = F_82 ( T_4 ) ;
V_151 = F_90 ( T_5 , V_122 -> V_142 . V_152 ) ;
if ( ! V_151 ) {
F_5 ( L_56 ,
V_130 , V_122 -> V_142 . V_152 ) ;
return - V_153 ;
}
V_132 = F_87 ( T_4 ) ;
if ( F_4 ( V_132 ) ) {
F_5 ( L_50 ,
V_130 ) ;
return F_34 ( V_132 ) ;
}
if ( V_132 -> type != V_154 ) {
F_5 ( L_57 ,
V_130 ) ;
return - V_134 ;
}
V_112 = F_85 ( T_4 , V_122 ) ;
if ( F_4 ( V_112 ) )
return F_34 ( V_112 ) ;
V_112 -> V_139 = V_155 ;
V_112 -> V_141 . V_151 = V_151 ;
return 0 ;
}
static int
F_91 ( struct V_120 * T_4 ,
struct V_121 * V_122 ,
struct V_144 * T_5 )
{
if ( ! V_122 -> V_145 ) {
F_5 ( L_54 ) ;
return - V_146 ;
}
if ( V_122 -> V_147 != V_156 ) {
F_5 ( L_58 ) ;
return - V_149 ;
}
return F_89 ( T_4 , V_122 , T_5 ) ;
}
static int
F_92 ( struct V_121 * V_122 ,
struct V_120 * T_4 ,
const char * V_130 )
{
struct V_157 * V_117 = & V_122 -> V_117 ;
const struct V_131 * V_132 ;
unsigned int V_40 ;
if ( ! V_117 -> V_124 )
return 0 ;
if ( ! V_117 -> V_126 ) {
F_5 ( L_59 ,
V_130 , ( int ) V_117 -> V_124 ) ;
return - V_103 ;
}
V_132 = F_87 ( T_4 ) ;
if ( F_4 ( V_132 ) ) {
F_5 ( L_60 ,
V_130 ) ;
return - V_103 ;
}
for ( V_40 = 0 ; V_40 < V_117 -> V_124 ; V_40 ++ ) {
unsigned int V_158 = V_117 -> V_126 [ V_40 ] . V_158 ;
T_1 V_159 = V_117 -> V_126 [ V_40 ] . V_159 ;
unsigned int V_160 = V_158 + V_159 - 1 ;
if ( V_160 >= V_132 -> V_161 ) {
F_5 ( L_61 , V_160 ) ;
return - V_162 ;
}
}
return 0 ;
}
static int
F_93 ( struct V_1 * V_5 ,
struct V_121 * V_122 ,
struct V_144 * T_5 ,
int * V_163 )
{
char * V_130 = F_23 ( V_122 -> V_164 + sizeof( L_62 ) - 1 ) ;
struct V_120 * T_4 ;
int V_13 = - V_165 ;
char * V_166 ;
T_1 V_40 ;
if ( ! V_130 )
return - V_32 ;
V_166 = strchr ( V_130 , '.' ) ;
if ( ! V_166 ) {
F_5 ( L_63 , V_130 ) ;
goto V_104;
}
* V_166 ++ = '\0' ;
if ( * V_166 == '\0' ) {
F_5 ( L_64 , V_122 -> V_164 ) ;
goto V_104;
}
T_4 = F_94 ( V_5 , V_130 ) ;
if ( ! T_4 ) {
F_5 ( L_65 , V_130 ) ;
V_13 = - V_167 ;
goto V_104;
}
* V_163 += strlen ( V_166 ) ;
V_13 = F_92 ( V_122 , T_4 , V_130 ) ;
if ( V_13 )
goto V_104;
* V_163 -= strlen ( V_166 ) ;
for ( V_40 = 0 ; V_40 < F_30 ( V_168 ) ; V_40 ++ ) {
struct V_169 * F_31 =
& V_168 [ V_40 ] ;
if ( strcmp ( V_166 , F_31 -> V_170 ) == 0 ) {
V_13 = F_31 -> V_171 ( T_4 , V_122 , T_5 ) ;
goto V_104;
}
}
F_5 ( L_66 , V_166 ) ;
V_13 = - V_172 ;
V_104:
free ( V_130 ) ;
if ( ! V_13 )
V_163 += strlen ( V_166 ) ;
return V_13 ;
}
int F_95 ( struct V_1 * V_5 ,
struct V_121 * V_122 ,
struct V_144 * T_5 ,
int * V_173 )
{
int V_163 = 0 ;
int V_13 ;
if ( ! V_5 || ! V_122 || ! V_122 -> V_164 )
return - V_10 ;
if ( ! F_96 ( V_122 -> V_164 , L_62 ) ) {
V_163 = sizeof( L_62 ) - 1 ;
V_13 = F_93 ( V_5 , V_122 , T_5 , & V_163 ) ;
goto V_104;
}
V_13 = - V_165 ;
V_104:
if ( V_173 )
* V_173 = V_163 ;
return V_13 ;
}
static int
F_97 ( T_6 F_31 ,
void * V_109 , const char * V_4 ,
int V_174 , const struct V_131 * V_175 ,
struct V_111 * V_112 )
{
unsigned int V_40 ;
int V_13 ;
for ( V_40 = 0 ; V_40 < V_175 -> V_161 ; V_40 ++ ) {
V_13 = F_31 ( V_4 , V_174 , V_175 , V_112 , & V_40 , V_109 ) ;
if ( V_13 ) {
F_5 ( L_67 ,
V_4 , V_40 ) ;
return V_13 ;
}
}
return 0 ;
}
static int
F_98 ( T_6 F_31 , void * V_109 ,
const char * V_4 , int V_174 ,
const struct V_131 * V_175 ,
struct V_111 * V_112 )
{
unsigned int V_40 , V_176 ;
int V_13 ;
for ( V_40 = 0 ; V_40 < V_112 -> V_116 . V_117 . V_124 ; V_40 ++ ) {
unsigned int V_158 = V_112 -> V_116 . V_117 . V_126 [ V_40 ] . V_158 ;
T_1 V_159 = V_112 -> V_116 . V_117 . V_126 [ V_40 ] . V_159 ;
for ( V_176 = 0 ; V_176 < V_159 ; V_176 ++ ) {
unsigned int V_160 = V_158 + V_176 ;
V_13 = F_31 ( V_4 , V_174 , V_175 , V_112 , & V_160 , V_109 ) ;
if ( V_13 ) {
F_5 ( L_67 ,
V_4 , V_160 ) ;
return V_13 ;
}
}
}
return 0 ;
}
static int
F_99 ( struct V_120 * T_4 ,
T_6 F_31 ,
void * V_109 )
{
int V_13 , V_174 ;
struct V_111 * V_112 ;
const struct V_131 * V_132 ;
const char * V_4 = F_82 ( T_4 ) ;
struct V_118 * V_22 = F_83 ( T_4 ) ;
if ( F_4 ( V_22 ) ) {
F_5 ( L_68 , V_4 ) ;
return - V_103 ;
}
if ( ! V_22 || F_65 ( & V_22 -> V_129 ) ) {
F_5 ( L_69 , V_4 ) ;
return 0 ;
}
V_132 = F_87 ( T_4 ) ;
if ( F_4 ( V_132 ) ) {
F_5 ( L_70 , V_4 ) ;
return - V_103 ;
}
V_174 = F_100 ( T_4 ) ;
if ( V_174 < 0 ) {
F_5 ( L_71 , V_4 ) ;
return V_174 ;
}
F_79 (op, &priv->ops_list, list) {
switch ( V_132 -> type ) {
case V_133 :
case V_154 :
switch ( V_112 -> V_114 ) {
case V_123 :
V_13 = F_97 ( F_31 , V_109 , V_4 ,
V_174 , V_132 , V_112 ) ;
break;
case V_115 :
V_13 = F_98 ( F_31 , V_109 , V_4 ,
V_174 , V_132 ,
V_112 ) ;
break;
default:
F_5 ( L_72 ,
V_4 ) ;
return - V_103 ;
}
if ( V_13 )
return V_13 ;
break;
default:
F_5 ( L_73 , V_4 ) ;
return - V_134 ;
}
}
return 0 ;
}
static int
F_101 ( int V_174 , void * V_177 ,
T_1 V_178 , T_7 V_142 )
{
int V_13 = 0 ;
switch ( V_178 ) {
case 1 : {
T_8 V_179 = ( T_8 ) ( V_142 ) ;
V_13 = F_102 ( V_174 , V_177 , & V_179 , V_180 ) ;
break;
}
case 2 : {
T_9 V_179 = ( T_9 ) ( V_142 ) ;
V_13 = F_102 ( V_174 , V_177 , & V_179 , V_180 ) ;
break;
}
case 4 : {
T_10 V_179 = ( T_10 ) ( V_142 ) ;
V_13 = F_102 ( V_174 , V_177 , & V_179 , V_180 ) ;
break;
}
case 8 : {
V_13 = F_102 ( V_174 , V_177 , & V_142 , V_180 ) ;
break;
}
default:
F_5 ( L_74 ) ;
return - V_138 ;
}
if ( V_13 && V_181 )
V_13 = - V_181 ;
return V_13 ;
}
static int
F_103 ( const char * V_4 , int V_174 , void * V_177 ,
struct V_150 * V_151 )
{
struct V_182 * V_183 = V_151 -> V_110 ;
struct V_184 * V_185 ;
unsigned int V_39 , V_186 ;
bool V_187 = false ;
int * V_188 ;
int V_13 ;
if ( ! V_183 ) {
F_5 ( L_75 , V_4 ) ;
return - V_103 ;
}
if ( V_183 -> V_189 / V_183 -> V_190 != 1 ) {
F_5 ( L_76 ,
V_4 ) ;
return - V_191 ;
}
V_185 = & V_151 -> V_185 ;
if ( V_185 -> V_192 ) {
F_5 ( L_77 , V_4 ) ;
return - V_193 ;
}
if ( F_104 ( V_151 ) )
V_187 = true ;
if ( V_185 -> type == V_194 )
V_187 = true ;
if ( V_185 -> type == V_195 )
V_187 = true ;
if ( ! V_187 ) {
F_5 ( L_78 , V_4 ) ;
return - V_196 ;
}
V_186 = V_183 -> V_197 / ( V_183 -> V_189 / V_183 -> V_190 ) ;
V_39 = * ( ( unsigned int * ) V_177 ) ;
if ( V_39 >= V_186 ) {
F_5 ( L_79 ,
V_39 , V_4 ) ;
return - V_198 ;
}
V_188 = F_105 ( V_183 , V_39 , 0 ) ;
V_13 = F_102 ( V_174 , V_177 , V_188 , V_180 ) ;
if ( V_13 && V_181 )
V_13 = - V_181 ;
return V_13 ;
}
static int
F_106 ( const char * V_4 , int V_174 ,
const struct V_131 * V_175 ,
struct V_111 * V_112 ,
void * V_177 , void * V_109 V_19 )
{
int V_13 ;
switch ( V_112 -> V_139 ) {
case V_140 :
V_13 = F_101 ( V_174 , V_177 ,
V_175 -> V_137 ,
V_112 -> V_141 . V_28 ) ;
break;
case V_155 :
V_13 = F_103 ( V_4 , V_174 , V_177 ,
V_112 -> V_141 . V_151 ) ;
break;
default:
F_5 ( L_80 , V_4 ) ;
V_13 = - V_103 ;
}
return V_13 ;
}
static int
F_107 ( struct V_120 * T_4 )
{
return F_99 ( T_4 ,
F_106 ,
NULL ) ;
}
static int
F_108 ( struct V_1 * V_5 )
{
struct V_120 * T_4 ;
int V_13 ;
F_109 (map, obj) {
V_13 = F_107 ( T_4 ) ;
if ( V_13 )
return V_13 ;
}
return 0 ;
}
int F_110 ( void )
{
struct V_1 * V_5 , * V_17 ;
int V_13 ;
F_16 (obj, tmp) {
V_13 = F_108 ( V_5 ) ;
if ( V_13 )
return V_13 ;
}
return 0 ;
}
int F_111 ( struct V_144 * T_5 V_19 )
{
struct V_118 * V_199 = NULL ;
struct V_1 * V_5 , * V_17 ;
struct V_150 * V_151 = NULL ;
struct V_120 * T_4 ;
int V_13 ;
bool V_200 = false ;
F_112 (map, obj, tmp) {
struct V_118 * V_22 = F_83 ( T_4 ) ;
if ( F_4 ( V_22 ) )
return - V_103 ;
if ( ! V_200 && ! V_22 )
V_200 = ! V_22 ;
if ( ! V_199 && V_22 )
V_199 = V_22 ;
}
if ( ! V_200 )
return 0 ;
if ( ! V_199 ) {
V_13 = F_113 ( T_5 , L_81 ,
NULL ) ;
if ( V_13 ) {
F_5 ( L_82 ) ;
return - V_13 ;
}
V_151 = F_114 ( T_5 ) ;
}
F_112 (map, obj, tmp) {
struct V_118 * V_22 = F_83 ( T_4 ) ;
if ( F_4 ( V_22 ) )
return - V_103 ;
if ( V_22 )
continue;
if ( V_199 ) {
V_22 = F_78 ( V_199 ) ;
if ( ! V_22 )
return - V_32 ;
V_13 = F_84 ( T_4 , V_22 , F_71 ) ;
if ( V_13 ) {
F_71 ( T_4 , V_22 ) ;
return V_13 ;
}
} else if ( V_151 ) {
struct V_111 * V_112 ;
V_112 = F_85 ( T_4 , NULL ) ;
if ( F_4 ( V_112 ) )
return F_34 ( V_112 ) ;
V_112 -> V_139 = V_155 ;
V_112 -> V_141 . V_151 = V_151 ;
}
}
return 0 ;
}
static int
F_115 ( int V_13 , char * V_73 , T_1 V_201 )
{
char V_202 [ V_203 ] ;
const char * V_204 ;
if ( ! V_73 || ! V_201 )
return - 1 ;
V_13 = V_13 > 0 ? V_13 : - V_13 ;
if ( V_13 >= V_205 )
return F_116 ( V_13 , V_73 , V_201 ) ;
if ( V_13 >= V_206 && V_13 < V_207 ) {
V_204 = V_208 [ F_117 ( V_13 ) ] ;
snprintf ( V_73 , V_201 , L_83 , V_204 ) ;
V_73 [ V_201 - 1 ] = '\0' ;
return 0 ;
}
if ( V_13 >= V_207 )
snprintf ( V_73 , V_201 , L_84 , V_13 ) ;
else
snprintf ( V_73 , V_201 , L_83 ,
F_118 ( V_13 , V_202 , sizeof( V_202 ) ) ) ;
V_73 [ V_201 - 1 ] = '\0' ;
return - 1 ;
}
int F_119 ( const char * V_11 , bool V_12 ,
int V_13 , char * V_73 , T_1 V_201 )
{
T_1 V_65 ;
int V_87 ;
V_65 = snprintf ( V_73 , V_201 , L_85 ,
V_11 , V_12 ? L_86 : L_87 ) ;
if ( V_65 >= V_201 ) {
V_73 [ V_201 - 1 ] = '\0' ;
return 0 ;
}
V_73 += V_65 ;
V_201 -= V_65 ;
V_87 = F_115 ( V_13 , V_73 , V_201 ) ;
V_73 [ V_201 - 1 ] = '\0' ;
return V_87 ;
}
int F_120 ( struct V_1 * V_5 V_19 ,
int V_13 , char * V_73 , T_1 V_201 )
{
F_121 ( V_13 , V_73 , V_201 ) ;
case V_44 : {
F_122 ( V_73 , V_201 , L_88 , V_209 ) ;
break;
}
F_123 ( V_210 , L_89 ) ;
F_123 ( V_211 , L_90 ) ;
F_123 ( V_212 , L_91 ) ;
F_123 ( V_213 , L_92 ) ;
F_124 ( V_73 , V_201 ) ;
return 0 ;
}
int F_125 ( struct V_1 * V_5 ,
int V_13 , char * V_73 , T_1 V_201 )
{
F_121 ( V_13 , V_73 , V_201 ) ;
case V_214 : {
unsigned int V_215 = F_126 ( V_5 ) ;
unsigned int V_216 ;
if ( F_127 ( & V_216 , NULL , 0 ) ) {
F_122 ( V_73 , V_201 , L_93 ) ;
break;
}
if ( V_215 != V_216 ) {
F_122 ( V_73 , V_201 ,
L_94 V_217 L_95 V_217 L_96 ,
F_128 ( V_215 ) ,
F_128 ( V_216 ) ) ;
break;
}
F_122 ( V_73 , V_201 , L_97 ) ;
break;
}
F_124 ( V_73 , V_201 ) ;
return 0 ;
}
int F_129 ( struct V_1 * V_5 V_19 ,
struct V_121 * V_122 V_19 ,
struct V_144 * T_5 V_19 ,
int * V_173 V_19 , int V_13 ,
char * V_73 , T_1 V_201 )
{
F_121 ( V_13 , V_73 , V_201 ) ;
F_123 ( V_134 ,
L_98 ) ;
F_124 ( V_73 , V_201 ) ;
return 0 ;
}
int F_130 ( int V_13 , char * V_73 , T_1 V_201 )
{
F_121 ( V_13 , V_73 , V_201 ) ;
F_123 ( V_191 ,
L_99 ) ;
F_123 ( V_193 ,
L_100 , V_209 ) ;
F_123 ( V_196 ,
L_101 ) ;
F_124 ( V_73 , V_201 ) ;
return 0 ;
}
int F_131 ( struct V_144 * T_5 V_19 ,
int V_13 , char * V_73 , T_1 V_201 )
{
F_121 ( V_13 , V_73 , V_201 ) ;
F_124 ( V_73 , V_201 ) ;
return 0 ;
}
