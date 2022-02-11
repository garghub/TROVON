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
free ( V_20 ) ;
}
static int
F_17 ( const char * V_24 , struct V_25 * V_21 )
{
V_21 -> V_26 = true ;
V_21 -> V_27 = F_18 ( V_24 ) ;
if ( ! V_21 -> V_27 )
return - V_28 ;
return 0 ;
}
static int
F_19 ( const char * V_24 , struct V_25 * V_21 )
{
V_21 -> V_26 = false ;
V_21 -> V_27 = F_18 ( V_24 ) ;
if ( ! V_21 -> V_27 )
return - V_28 ;
return 0 ;
}
static int
F_20 ( const char * V_24 , bool * V_29 , bool V_30 )
{
int V_13 ;
bool V_31 ;
if ( ! V_29 )
return - V_10 ;
V_13 = F_21 ( V_24 , & V_31 ) ;
if ( V_13 )
return V_13 ;
* V_29 = V_30 ? ! V_31 : V_31 ;
return 0 ;
}
static int
F_22 ( const char * V_24 ,
struct V_25 * V_21 V_17 )
{
return F_20 ( V_24 , & V_32 . V_33 , true ) ;
}
static int
F_23 ( const char * V_24 ,
struct V_25 * V_21 V_17 )
{
return F_20 ( V_24 , & V_32 . V_34 , false ) ;
}
static int
F_24 ( const char * V_35 , const char * V_24 ,
struct V_25 * V_21 )
{
unsigned int V_36 ;
F_5 ( L_3 , V_35 , V_24 ) ;
for ( V_36 = 0 ; V_36 < F_25 ( V_37 ) ; V_36 ++ )
if ( strcmp ( V_35 , V_37 [ V_36 ] . V_35 ) == 0 )
return V_37 [ V_36 ] . F_26 ( V_24 , V_21 ) ;
F_5 ( L_4 ,
V_35 , V_24 ) ;
F_5 ( L_5 ) ;
for ( V_36 = 0 ; V_36 < F_25 ( V_37 ) ; V_36 ++ )
F_5 ( L_6 , V_37 [ V_36 ] . V_38 ,
V_37 [ V_36 ] . V_39 ) ;
F_5 ( L_7 ) ;
return - V_40 ;
}
static const char *
F_27 ( const char * V_41 , struct V_25 * V_21 )
{
char * V_42 = F_18 ( V_41 ) ;
char * V_43 , * line ;
const char * V_44 = NULL ;
int V_13 = 0 ;
if ( ! V_42 ) {
F_5 ( L_8 ) ;
return F_6 ( - V_28 ) ;
}
line = V_42 ;
while ( ( V_43 = strchr ( line , ';' ) ) ) {
char * V_45 ;
* V_43 = '\0' ;
V_45 = strchr ( line , '=' ) ;
if ( ! V_45 ) {
F_28 ( L_9 ,
line ) ;
F_28 ( L_10 ) ;
goto V_46;
}
* V_45 = '\0' ;
V_13 = F_24 ( line , V_45 + 1 , V_21 ) ;
if ( V_13 )
break;
V_46:
line = V_43 + 1 ;
}
if ( ! V_13 )
V_44 = V_41 + ( line - V_42 ) ;
free ( V_42 ) ;
return V_13 ? F_6 ( V_13 ) : V_44 ;
}
static int
F_29 ( const char * V_41 , struct V_25 * V_21 )
{
int V_13 ;
const char * V_44 = F_27 ( V_41 , V_21 ) ;
if ( F_4 ( V_44 ) )
return F_30 ( V_44 ) ;
V_13 = F_31 ( V_44 , V_21 ) ;
if ( V_13 < 0 ) {
F_5 ( L_11 ,
V_41 ) ;
return - V_47 ;
}
return 0 ;
}
static int
F_32 ( struct V_16 * T_2 )
{
struct V_25 * V_21 = NULL ;
struct V_19 * V_20 = NULL ;
const char * V_41 ;
int V_13 ;
V_32 . V_33 = false ;
V_32 . V_34 = false ;
V_41 = F_33 ( T_2 , false ) ;
if ( F_4 ( V_41 ) ) {
F_5 ( L_12 ) ;
return F_30 ( V_41 ) ;
}
V_20 = calloc ( sizeof( * V_20 ) , 1 ) ;
if ( ! V_20 ) {
F_5 ( L_13 ) ;
return - V_28 ;
}
V_21 = & V_20 -> V_21 ;
F_5 ( L_14 , V_41 ) ;
V_13 = F_29 ( V_41 , V_21 ) ;
if ( V_13 )
goto V_48;
if ( V_21 -> V_49 && strcmp ( V_21 -> V_49 , V_50 ) ) {
F_5 ( L_15 ,
V_41 , V_50 ) ;
V_13 = - V_51 ;
goto V_48;
} else if ( ! V_21 -> V_49 )
V_21 -> V_49 = F_18 ( V_50 ) ;
if ( ! V_21 -> V_49 ) {
F_5 ( L_16 ) ;
V_13 = - V_28 ;
goto V_48;
}
if ( ! V_21 -> V_52 ) {
F_5 ( L_17 ,
V_41 ) ;
V_13 = - V_53 ;
goto V_48;
}
F_5 ( L_18 , V_41 ) ;
V_13 = F_34 ( T_2 , V_20 , F_14 ) ;
if ( V_13 ) {
F_5 ( L_19 , V_41 ) ;
goto V_48;
}
return 0 ;
V_48:
if ( V_21 )
F_35 ( V_21 ) ;
free ( V_20 ) ;
return V_13 ;
}
static int F_36 ( void )
{
static int V_13 = 0 ;
static bool V_54 = false ;
if ( V_54 )
return V_13 ;
V_54 = true ;
V_13 = F_37 ( false ) ;
if ( V_13 < 0 )
F_5 ( L_20 ) ;
V_32 . V_55 = V_56 ;
return V_13 ;
}
static int
F_38 ( struct V_16 * T_2 , int V_57 ,
struct V_58 * V_59 , int V_60 ,
struct V_61 * V_62 )
{
struct V_63 * V_64 ;
struct V_25 * V_21 ;
struct V_19 * V_20 ;
struct V_58 * V_65 ;
T_1 V_66 = 0 ;
int V_36 , V_13 ;
V_13 = F_39 ( T_2 , ( void * * ) & V_20 ) ;
if ( V_13 || ! V_20 )
goto V_48;
V_21 = & V_20 -> V_21 ;
if ( V_57 < 0 || V_57 >= V_20 -> V_67 )
goto V_48;
for ( V_36 = 0 ; V_36 < V_21 -> V_68 ; V_36 ++ ) {
if ( V_20 -> V_23 [ V_36 ] == V_57 )
break;
}
if ( V_36 >= V_21 -> V_68 ) {
F_5 ( L_21 , V_57 ) ;
return - V_69 ;
}
V_64 = & V_21 -> V_70 [ V_36 ] ;
V_65 = V_20 -> V_22 ;
V_13 = F_40 ( V_64 -> args , V_64 -> V_71 ,
V_65 , & V_66 ,
V_72 - V_60 ) ;
if ( V_13 ) {
const char * V_73 ;
V_73 = F_33 ( T_2 , false ) ;
if ( ! V_73 )
V_73 = L_22 ;
F_5 ( L_23 ,
V_73 ) ;
return V_13 ;
}
memcpy ( & V_65 [ V_66 ] , V_59 ,
sizeof( struct V_58 ) * V_60 ) ;
V_62 -> V_74 = V_65 ;
V_62 -> V_75 = V_66 + V_60 ;
V_62 -> V_76 = NULL ;
return 0 ;
V_48:
F_5 ( L_24 ) ;
return - V_69 ;
}
static int F_41 ( const void * V_77 , const void * V_78 )
{
int V_36 , V_79 ;
const struct V_63 * V_80 =
* ( const struct V_63 * * ) V_77 ;
const struct V_63 * V_81 =
* ( const struct V_63 * * ) V_78 ;
V_79 = V_81 -> V_71 - V_80 -> V_71 ;
if ( V_79 )
return V_79 ;
for ( V_36 = 0 ; V_36 < V_80 -> V_71 ; V_36 ++ ) {
struct V_82 * V_83 , * V_84 ;
struct V_85 * V_86 , * V_87 ;
V_83 = & V_80 -> args [ V_36 ] ;
V_84 = & V_81 -> args [ V_36 ] ;
V_79 = strcmp ( V_83 -> V_24 , V_84 -> V_24 ) ;
if ( V_79 )
return V_79 ;
V_86 = V_83 -> V_88 ;
V_87 = V_84 -> V_88 ;
while ( V_86 && V_87 ) {
V_79 = V_87 -> V_89 - V_86 -> V_89 ;
if ( V_79 )
return V_79 ;
V_86 = V_86 -> V_90 ;
V_87 = V_87 -> V_90 ;
}
if ( V_86 || V_87 )
return V_87 ? 1 : - 1 ;
}
return 0 ;
}
static int F_42 ( struct V_25 * V_21 , int * V_91 ,
int * V_67 )
{
int V_36 , type = 0 ;
struct V_63 * * V_92 ;
T_1 V_93 = sizeof( * V_92 ) * V_21 -> V_68 ;
V_92 = malloc ( V_93 ) ;
if ( ! V_92 ) {
F_5 ( L_25 ) ;
return - V_28 ;
}
F_5 ( L_26 , V_21 -> V_68 ) ;
for ( V_36 = 0 ; V_36 < V_21 -> V_68 ; V_36 ++ )
V_92 [ V_36 ] = & V_21 -> V_70 [ V_36 ] ;
qsort ( V_92 , V_21 -> V_68 , sizeof( * V_92 ) ,
F_41 ) ;
for ( V_36 = 0 ; V_36 < V_21 -> V_68 ; V_36 ++ ) {
int V_57 ;
V_57 = V_92 [ V_36 ] - V_21 -> V_70 ;
if ( V_36 == 0 ) {
V_91 [ V_57 ] = type ;
F_5 ( L_27 , V_57 , type ) ;
continue;
}
if ( F_41 ( V_92 + V_36 , V_92 + V_36 - 1 ) == 0 )
V_91 [ V_57 ] = type ;
else
V_91 [ V_57 ] = ++ type ;
F_5 ( L_27 , V_57 , V_91 [ V_57 ] ) ;
}
free ( V_92 ) ;
* V_67 = type + 1 ;
return 0 ;
}
static int F_43 ( struct V_16 * T_2 )
{
struct V_25 * V_21 ;
struct V_19 * V_20 ;
bool V_94 = false ;
int V_13 , V_36 ;
V_13 = F_39 ( T_2 , ( void * * ) & V_20 ) ;
if ( V_13 || ! V_20 ) {
F_5 ( L_28 ) ;
return - V_95 ;
}
V_21 = & V_20 -> V_21 ;
for ( V_36 = 0 ; V_36 < V_21 -> V_68 ; V_36 ++ ) {
struct V_63 * V_64 = & V_21 -> V_70 [ V_36 ] ;
if ( V_64 -> V_71 > 0 ) {
V_94 = true ;
break;
}
}
if ( ! V_94 ) {
V_20 -> V_94 = false ;
return 0 ;
}
V_20 -> V_94 = true ;
V_20 -> V_22 = malloc ( sizeof( struct V_58 ) * V_72 ) ;
if ( ! V_20 -> V_22 ) {
F_5 ( L_29 ) ;
return - V_28 ;
}
V_20 -> V_23 = malloc ( sizeof( int ) * V_21 -> V_68 ) ;
if ( ! V_20 -> V_23 ) {
F_5 ( L_30 ) ;
return - V_28 ;
}
memset ( V_20 -> V_23 , - 1 ,
sizeof( int ) * V_21 -> V_68 ) ;
V_13 = F_42 ( V_21 , V_20 -> V_23 , & V_20 -> V_67 ) ;
if ( V_13 )
return V_13 ;
V_13 = F_44 ( T_2 , V_20 -> V_67 ,
F_38 ) ;
return V_13 ;
}
int F_45 ( struct V_1 * V_5 )
{
int V_13 = 0 ;
struct V_16 * T_2 ;
struct V_19 * V_20 ;
struct V_25 * V_21 ;
V_13 = F_36 () ;
if ( V_13 ) {
F_5 ( L_31 ) ;
return V_13 ;
}
F_46 (prog, obj) {
V_13 = F_32 ( T_2 ) ;
if ( V_13 )
goto V_96;
V_13 = F_39 ( T_2 , ( void * * ) & V_20 ) ;
if ( V_13 || ! V_20 )
goto V_96;
V_21 = & V_20 -> V_21 ;
V_13 = F_47 ( V_21 , 1 ) ;
if ( V_13 < 0 ) {
F_5 ( L_32 ) ;
goto V_96;
}
V_13 = F_48 ( V_21 , 1 ) ;
if ( V_13 < 0 ) {
F_5 ( L_33 ) ;
goto V_96;
}
V_13 = F_43 ( T_2 ) ;
if ( V_13 )
goto V_96;
}
V_96:
return V_13 < 0 ? V_13 : 0 ;
}
int F_12 ( struct V_1 * V_5 )
{
int V_13 , V_79 = 0 ;
struct V_16 * T_2 ;
struct V_19 * V_20 ;
F_46 (prog, obj) {
int V_36 ;
V_13 = F_39 ( T_2 , ( void * * ) & V_20 ) ;
if ( V_13 || ! V_20 )
continue;
for ( V_36 = 0 ; V_36 < V_20 -> V_21 . V_68 ; V_36 ++ ) {
struct V_63 * V_64 = & V_20 -> V_21 . V_70 [ V_36 ] ;
char V_97 [ V_98 ] ;
struct V_99 * V_100 ;
snprintf ( V_97 , V_98 ,
L_34 , V_64 -> V_49 , V_64 -> V_52 ) ;
V_97 [ V_98 - 1 ] = '\0' ;
V_100 = F_49 ( V_97 , NULL ) ;
if ( ! V_100 ) {
F_5 ( L_35 ) ;
V_79 = - V_28 ;
continue;
}
V_13 = F_50 ( V_100 ) ;
F_51 ( V_100 ) ;
if ( V_13 ) {
F_5 ( L_36 , V_97 ) ;
V_79 = V_13 ;
continue;
}
}
}
return V_79 ;
}
int F_52 ( struct V_1 * V_5 )
{
int V_13 ;
V_13 = F_53 ( V_5 ) ;
if ( V_13 ) {
F_5 ( L_37 ) ;
return V_13 ;
}
return 0 ;
}
int F_54 ( struct V_1 * V_5 ,
T_3 F_26 ,
void * V_101 )
{
struct V_16 * T_2 ;
int V_13 ;
F_46 (prog, obj) {
struct V_63 * V_64 ;
struct V_25 * V_21 ;
struct V_19 * V_20 ;
int V_36 , V_102 ;
V_13 = F_39 ( T_2 ,
( void * * ) & V_20 ) ;
if ( V_13 || ! V_20 ) {
F_5 ( L_38 ) ;
return - V_95 ;
}
V_21 = & V_20 -> V_21 ;
for ( V_36 = 0 ; V_36 < V_21 -> V_68 ; V_36 ++ ) {
V_64 = & V_21 -> V_70 [ V_36 ] ;
if ( V_20 -> V_94 ) {
int type = V_20 -> V_23 [ V_36 ] ;
V_102 = F_55 ( T_2 , type ) ;
} else {
V_102 = F_56 ( T_2 ) ;
}
if ( V_102 < 0 ) {
F_5 ( L_39 ) ;
return V_102 ;
}
V_13 = (* F_26)( V_64 , V_102 , V_101 ) ;
if ( V_13 ) {
F_5 ( L_40 ) ;
return V_13 ;
}
}
}
return 0 ;
}
static void
F_57 ( struct V_103 * V_104 )
{
if ( ! F_58 ( & V_104 -> V_105 ) )
F_59 ( & V_104 -> V_105 ) ;
if ( V_104 -> V_106 == V_107 )
F_60 ( & V_104 -> V_108 . V_109 ) ;
free ( V_104 ) ;
}
static void
F_61 ( struct V_110 * V_20 )
{
struct V_103 * V_111 , * V_57 ;
F_62 (pos, n, &priv->ops_list, list) {
F_63 ( & V_111 -> V_105 ) ;
F_57 ( V_111 ) ;
}
}
static void
F_64 ( struct V_112 * T_4 V_17 ,
void * V_18 )
{
struct V_110 * V_20 = V_18 ;
F_61 ( V_20 ) ;
free ( V_20 ) ;
}
static int
F_65 ( struct V_103 * V_104 , struct V_113 * V_114 )
{
V_104 -> V_106 = V_115 ;
if ( ! V_114 )
return 0 ;
if ( V_114 -> V_109 . V_116 ) {
T_1 V_117 = V_114 -> V_109 . V_116 *
sizeof( V_104 -> V_108 . V_109 . V_118 [ 0 ] ) ;
V_104 -> V_108 . V_109 . V_118 = F_66 ( V_114 -> V_109 . V_118 , V_117 ) ;
if ( ! V_104 -> V_108 . V_109 . V_118 ) {
F_5 ( L_41 ) ;
return - V_28 ;
}
V_104 -> V_106 = V_107 ;
V_104 -> V_108 . V_109 . V_116 = V_114 -> V_109 . V_116 ;
}
return 0 ;
}
static struct V_103 *
F_67 ( struct V_113 * V_114 )
{
struct V_103 * V_104 ;
int V_13 ;
V_104 = F_68 ( sizeof( * V_104 ) ) ;
if ( ! V_104 ) {
F_5 ( L_42 ) ;
return F_6 ( - V_28 ) ;
}
F_69 ( & V_104 -> V_105 ) ;
V_13 = F_65 ( V_104 , V_114 ) ;
if ( V_13 ) {
free ( V_104 ) ;
return F_6 ( V_13 ) ;
}
return V_104 ;
}
static struct V_103 *
F_70 ( struct V_103 * V_104 )
{
struct V_103 * V_119 ;
V_119 = F_66 ( V_104 , sizeof( * V_104 ) ) ;
if ( ! V_119 ) {
F_5 ( L_42 ) ;
return NULL ;
}
F_69 ( & V_119 -> V_105 ) ;
if ( V_104 -> V_106 == V_107 ) {
T_1 V_117 = V_104 -> V_108 . V_109 . V_116 *
sizeof( V_104 -> V_108 . V_109 . V_118 [ 0 ] ) ;
V_119 -> V_108 . V_109 . V_118 = F_66 ( V_104 -> V_108 . V_109 . V_118 , V_117 ) ;
if ( ! V_119 -> V_108 . V_109 . V_118 ) {
F_5 ( L_43 ) ;
free ( V_119 ) ;
return NULL ;
}
}
return V_119 ;
}
static struct V_110 *
F_71 ( struct V_110 * V_20 )
{
struct V_110 * V_120 ;
struct V_103 * V_111 , * V_119 ;
V_120 = F_68 ( sizeof( * V_120 ) ) ;
if ( ! V_120 ) {
F_5 ( L_44 ) ;
return NULL ;
}
F_69 ( & V_120 -> V_121 ) ;
F_72 (pos, &priv->ops_list, list) {
V_119 = F_70 ( V_111 ) ;
if ( ! V_119 ) {
F_61 ( V_120 ) ;
return NULL ;
}
F_73 ( & V_119 -> V_105 , & V_120 -> V_121 ) ;
}
return V_120 ;
}
static int
F_74 ( struct V_112 * T_4 , struct V_103 * V_104 )
{
struct V_110 * V_20 ;
const char * V_122 ;
int V_13 ;
V_122 = F_75 ( T_4 ) ;
V_13 = F_76 ( T_4 , ( void * * ) & V_20 ) ;
if ( V_13 ) {
F_5 ( L_45 , V_122 ) ;
return V_13 ;
}
if ( ! V_20 ) {
V_20 = F_68 ( sizeof( * V_20 ) ) ;
if ( ! V_20 ) {
F_5 ( L_44 ) ;
return - V_28 ;
}
F_69 ( & V_20 -> V_121 ) ;
if ( F_77 ( T_4 , V_20 , F_64 ) ) {
free ( V_20 ) ;
return - V_95 ;
}
}
F_73 ( & V_104 -> V_105 , & V_20 -> V_121 ) ;
return 0 ;
}
static struct V_103 *
F_78 ( struct V_112 * T_4 , struct V_113 * V_114 )
{
struct V_103 * V_104 ;
int V_13 ;
V_104 = F_67 ( V_114 ) ;
if ( F_4 ( V_104 ) )
return V_104 ;
V_13 = F_74 ( T_4 , V_104 ) ;
if ( V_13 ) {
F_57 ( V_104 ) ;
return F_6 ( V_13 ) ;
}
return V_104 ;
}
static int
F_79 ( struct V_112 * T_4 ,
struct V_113 * V_114 )
{
struct V_123 V_124 ;
struct V_103 * V_104 ;
const char * V_122 ;
int V_13 ;
V_122 = F_75 ( T_4 ) ;
V_13 = F_80 ( T_4 , & V_124 ) ;
if ( V_13 ) {
F_5 ( L_46 ,
V_122 ) ;
return - V_95 ;
}
if ( V_124 . type != V_125 ) {
F_5 ( L_47 ,
V_122 ) ;
return - V_126 ;
}
if ( V_124 . V_127 < sizeof( unsigned int ) ) {
F_5 ( L_48 , V_122 ) ;
return - V_128 ;
}
switch ( V_124 . V_129 ) {
case 1 :
case 2 :
case 4 :
case 8 :
break;
default:
F_5 ( L_49 , V_122 ) ;
return - V_130 ;
}
V_104 = F_78 ( T_4 , V_114 ) ;
if ( F_4 ( V_104 ) )
return F_30 ( V_104 ) ;
V_104 -> V_131 = V_132 ;
V_104 -> V_133 . V_24 = V_114 -> V_134 . V_135 ;
return 0 ;
}
static int
F_81 ( struct V_112 * T_4 ,
struct V_113 * V_114 ,
struct V_136 * T_5 V_17 )
{
if ( ! V_114 -> V_137 ) {
F_5 ( L_50 ) ;
return - V_138 ;
}
if ( V_114 -> V_139 != V_140 ) {
F_5 ( L_51 ) ;
return - V_141 ;
}
return F_79 ( T_4 , V_114 ) ;
}
static int
F_82 ( struct V_112 * T_4 ,
struct V_113 * V_114 ,
struct V_136 * T_5 )
{
struct V_142 * V_143 ;
struct V_123 V_124 ;
struct V_103 * V_104 ;
const char * V_122 ;
int V_13 ;
V_122 = F_75 ( T_4 ) ;
V_143 = F_83 ( T_5 , V_114 -> V_134 . V_144 ) ;
if ( ! V_143 ) {
F_5 ( L_52 ,
V_122 , V_114 -> V_134 . V_144 ) ;
return - V_145 ;
}
V_13 = F_80 ( T_4 , & V_124 ) ;
if ( V_13 ) {
F_5 ( L_46 ,
V_122 ) ;
return V_13 ;
}
if ( V_124 . type != V_146 ) {
F_5 ( L_53 ,
V_122 ) ;
return - V_126 ;
}
V_104 = F_78 ( T_4 , V_114 ) ;
if ( F_4 ( V_104 ) )
return F_30 ( V_104 ) ;
V_104 -> V_131 = V_147 ;
V_104 -> V_133 . V_143 = V_143 ;
return 0 ;
}
static int
F_84 ( struct V_112 * T_4 ,
struct V_113 * V_114 ,
struct V_136 * T_5 )
{
if ( ! V_114 -> V_137 ) {
F_5 ( L_50 ) ;
return - V_138 ;
}
if ( V_114 -> V_139 != V_148 ) {
F_5 ( L_54 ) ;
return - V_141 ;
}
return F_82 ( T_4 , V_114 , T_5 ) ;
}
static int
F_85 ( struct V_113 * V_114 ,
struct V_112 * T_4 ,
const char * V_122 )
{
struct V_149 * V_109 = & V_114 -> V_109 ;
struct V_123 V_124 ;
unsigned int V_36 ;
int V_13 ;
if ( ! V_109 -> V_116 )
return 0 ;
if ( ! V_109 -> V_118 ) {
F_5 ( L_55 ,
V_122 , ( int ) V_109 -> V_116 ) ;
return - V_95 ;
}
V_13 = F_80 ( T_4 , & V_124 ) ;
if ( V_13 ) {
F_5 ( L_56 ,
V_122 ) ;
return - V_95 ;
}
for ( V_36 = 0 ; V_36 < V_109 -> V_116 ; V_36 ++ ) {
unsigned int V_150 = V_109 -> V_118 [ V_36 ] . V_150 ;
T_1 V_151 = V_109 -> V_118 [ V_36 ] . V_151 ;
unsigned int V_152 = V_150 + V_151 - 1 ;
if ( V_152 >= V_124 . V_153 ) {
F_5 ( L_57 , V_152 ) ;
return - V_154 ;
}
}
return 0 ;
}
static int
F_86 ( struct V_1 * V_5 ,
struct V_113 * V_114 ,
struct V_136 * T_5 ,
int * V_155 )
{
char * V_122 = F_18 ( V_114 -> V_156 + sizeof( L_58 ) - 1 ) ;
struct V_112 * T_4 ;
int V_13 = - V_157 ;
char * V_158 ;
T_1 V_36 ;
if ( ! V_122 )
return - V_28 ;
V_158 = strchr ( V_122 , '.' ) ;
if ( ! V_158 ) {
F_5 ( L_59 , V_122 ) ;
goto V_96;
}
* V_158 ++ = '\0' ;
if ( * V_158 == '\0' ) {
F_5 ( L_60 , V_114 -> V_156 ) ;
goto V_96;
}
T_4 = F_87 ( V_5 , V_122 ) ;
if ( ! T_4 ) {
F_5 ( L_61 , V_122 ) ;
V_13 = - V_159 ;
goto V_96;
}
* V_155 += strlen ( V_158 ) ;
V_13 = F_85 ( V_114 , T_4 , V_122 ) ;
if ( V_13 )
goto V_96;
* V_155 -= strlen ( V_158 ) ;
for ( V_36 = 0 ; V_36 < F_25 ( V_160 ) ; V_36 ++ ) {
struct V_161 * F_26 =
& V_160 [ V_36 ] ;
if ( strcmp ( V_158 , F_26 -> V_162 ) == 0 ) {
V_13 = F_26 -> V_163 ( T_4 , V_114 , T_5 ) ;
goto V_96;
}
}
F_5 ( L_62 , V_158 ) ;
V_13 = - V_164 ;
V_96:
free ( V_122 ) ;
if ( ! V_13 )
V_155 += strlen ( V_158 ) ;
return V_13 ;
}
int F_88 ( struct V_1 * V_5 ,
struct V_113 * V_114 ,
struct V_136 * T_5 ,
int * V_165 )
{
int V_155 = 0 ;
int V_13 ;
if ( ! V_5 || ! V_114 || ! V_114 -> V_156 )
return - V_10 ;
if ( ! F_89 ( V_114 -> V_156 , L_58 ) ) {
V_155 = sizeof( L_58 ) - 1 ;
V_13 = F_86 ( V_5 , V_114 , T_5 , & V_155 ) ;
goto V_96;
}
V_13 = - V_157 ;
V_96:
if ( V_165 )
* V_165 = V_155 ;
return V_13 ;
}
static int
F_90 ( T_6 F_26 ,
void * V_101 , const char * V_4 ,
int V_166 , struct V_123 * V_167 ,
struct V_103 * V_104 )
{
unsigned int V_36 ;
int V_13 ;
for ( V_36 = 0 ; V_36 < V_167 -> V_153 ; V_36 ++ ) {
V_13 = F_26 ( V_4 , V_166 , V_167 , V_104 , & V_36 , V_101 ) ;
if ( V_13 ) {
F_5 ( L_63 ,
V_4 , V_36 ) ;
return V_13 ;
}
}
return 0 ;
}
static int
F_91 ( T_6 F_26 , void * V_101 ,
const char * V_4 , int V_166 ,
struct V_123 * V_167 ,
struct V_103 * V_104 )
{
unsigned int V_36 , V_168 ;
int V_13 ;
for ( V_36 = 0 ; V_36 < V_104 -> V_108 . V_109 . V_116 ; V_36 ++ ) {
unsigned int V_150 = V_104 -> V_108 . V_109 . V_118 [ V_36 ] . V_150 ;
T_1 V_151 = V_104 -> V_108 . V_109 . V_118 [ V_36 ] . V_151 ;
for ( V_168 = 0 ; V_168 < V_151 ; V_168 ++ ) {
unsigned int V_152 = V_150 + V_168 ;
V_13 = F_26 ( V_4 , V_166 , V_167 , V_104 , & V_152 , V_101 ) ;
if ( V_13 ) {
F_5 ( L_63 ,
V_4 , V_152 ) ;
return V_13 ;
}
}
}
return 0 ;
}
static int
F_92 ( struct V_112 * T_4 ,
T_6 F_26 ,
void * V_101 )
{
int V_13 , V_166 ;
const char * V_4 ;
struct V_103 * V_104 ;
struct V_123 V_124 ;
struct V_110 * V_20 ;
V_4 = F_75 ( T_4 ) ;
V_13 = F_76 ( T_4 , ( void * * ) & V_20 ) ;
if ( V_13 ) {
F_5 ( L_64 , V_4 ) ;
return - V_95 ;
}
if ( ! V_20 || F_58 ( & V_20 -> V_121 ) ) {
F_5 ( L_65 , V_4 ) ;
return 0 ;
}
V_13 = F_80 ( T_4 , & V_124 ) ;
if ( V_13 ) {
F_5 ( L_66 , V_4 ) ;
return - V_95 ;
}
V_166 = F_93 ( T_4 ) ;
if ( V_166 < 0 ) {
F_5 ( L_67 , V_4 ) ;
return V_166 ;
}
F_72 (op, &priv->ops_list, list) {
switch ( V_124 . type ) {
case V_125 :
case V_146 :
switch ( V_104 -> V_106 ) {
case V_115 :
V_13 = F_90 ( F_26 , V_101 , V_4 ,
V_166 , & V_124 , V_104 ) ;
break;
case V_107 :
V_13 = F_91 ( F_26 , V_101 , V_4 ,
V_166 , & V_124 ,
V_104 ) ;
break;
default:
F_5 ( L_68 ,
V_4 ) ;
return - V_95 ;
}
if ( V_13 )
return V_13 ;
break;
default:
F_5 ( L_69 , V_4 ) ;
return - V_126 ;
}
}
return 0 ;
}
static int
F_94 ( int V_166 , void * V_169 ,
T_1 V_170 , T_7 V_134 )
{
int V_13 = 0 ;
switch ( V_170 ) {
case 1 : {
T_8 V_171 = ( T_8 ) ( V_134 ) ;
V_13 = F_95 ( V_166 , V_169 , & V_171 , V_172 ) ;
break;
}
case 2 : {
T_9 V_171 = ( T_9 ) ( V_134 ) ;
V_13 = F_95 ( V_166 , V_169 , & V_171 , V_172 ) ;
break;
}
case 4 : {
T_10 V_171 = ( T_10 ) ( V_134 ) ;
V_13 = F_95 ( V_166 , V_169 , & V_171 , V_172 ) ;
break;
}
case 8 : {
V_13 = F_95 ( V_166 , V_169 , & V_134 , V_172 ) ;
break;
}
default:
F_5 ( L_70 ) ;
return - V_130 ;
}
if ( V_13 && V_173 )
V_13 = - V_173 ;
return V_13 ;
}
static int
F_96 ( const char * V_4 , int V_166 , void * V_169 ,
struct V_142 * V_143 )
{
struct V_174 * V_175 = V_143 -> V_102 ;
struct V_176 * V_177 ;
unsigned int V_35 , V_178 ;
bool V_179 = false ;
int * V_180 ;
int V_13 ;
if ( ! V_175 ) {
F_5 ( L_71 , V_4 ) ;
return - V_95 ;
}
if ( V_175 -> V_181 / V_175 -> V_182 != 1 ) {
F_5 ( L_72 ,
V_4 ) ;
return - V_183 ;
}
V_177 = & V_143 -> V_177 ;
if ( V_177 -> V_184 ) {
F_5 ( L_73 , V_4 ) ;
return - V_185 ;
}
if ( F_97 ( V_143 ) )
V_179 = true ;
if ( V_177 -> type == V_186 )
V_179 = true ;
if ( V_177 -> type == V_187 )
V_179 = true ;
if ( ! V_179 ) {
F_5 ( L_74 , V_4 ) ;
return - V_188 ;
}
V_178 = V_175 -> V_189 / ( V_175 -> V_181 / V_175 -> V_182 ) ;
V_35 = * ( ( unsigned int * ) V_169 ) ;
if ( V_35 >= V_178 ) {
F_5 ( L_75 ,
V_35 , V_4 ) ;
return - V_190 ;
}
V_180 = F_98 ( V_175 , V_35 , 0 ) ;
V_13 = F_95 ( V_166 , V_169 , V_180 , V_172 ) ;
if ( V_13 && V_173 )
V_13 = - V_173 ;
return V_13 ;
}
static int
F_99 ( const char * V_4 , int V_166 ,
struct V_123 * V_167 V_17 ,
struct V_103 * V_104 ,
void * V_169 , void * V_101 V_17 )
{
int V_13 ;
switch ( V_104 -> V_131 ) {
case V_132 :
V_13 = F_94 ( V_166 , V_169 ,
V_167 -> V_129 ,
V_104 -> V_133 . V_24 ) ;
break;
case V_147 :
V_13 = F_96 ( V_4 , V_166 , V_169 ,
V_104 -> V_133 . V_143 ) ;
break;
default:
F_5 ( L_76 , V_4 ) ;
V_13 = - V_95 ;
}
return V_13 ;
}
static int
F_100 ( struct V_112 * T_4 )
{
return F_92 ( T_4 ,
F_99 ,
NULL ) ;
}
static int
F_101 ( struct V_1 * V_5 )
{
struct V_112 * T_4 ;
int V_13 ;
F_102 (map, obj) {
V_13 = F_100 ( T_4 ) ;
if ( V_13 )
return V_13 ;
}
return 0 ;
}
int F_103 ( void )
{
struct V_1 * V_5 , * V_15 ;
int V_13 ;
F_11 (obj, tmp) {
V_13 = F_101 ( V_5 ) ;
if ( V_13 )
return V_13 ;
}
return 0 ;
}
int F_104 ( struct V_136 * T_5 V_17 )
{
struct V_110 * V_191 = NULL ;
struct V_1 * V_5 , * V_15 ;
struct V_142 * V_143 = NULL ;
struct V_112 * T_4 ;
int V_13 ;
bool V_192 = false ;
F_105 (map, obj, tmp) {
struct V_110 * V_20 ;
V_13 = F_76 ( T_4 , ( void * * ) & V_20 ) ;
if ( V_13 )
return - V_95 ;
if ( ! V_192 && ! V_20 )
V_192 = ! V_20 ;
if ( ! V_191 && V_20 )
V_191 = V_20 ;
}
if ( ! V_192 )
return 0 ;
if ( ! V_191 ) {
V_13 = F_106 ( T_5 , L_77 ,
NULL ) ;
if ( V_13 ) {
F_5 ( L_78 ) ;
return - V_13 ;
}
V_143 = F_107 ( T_5 ) ;
}
F_105 (map, obj, tmp) {
struct V_110 * V_20 ;
V_13 = F_76 ( T_4 , ( void * * ) & V_20 ) ;
if ( V_13 )
return - V_95 ;
if ( V_20 )
continue;
if ( V_191 ) {
V_20 = F_71 ( V_191 ) ;
if ( ! V_20 )
return - V_28 ;
V_13 = F_77 ( T_4 , V_20 , F_64 ) ;
if ( V_13 ) {
F_64 ( T_4 , V_20 ) ;
return V_13 ;
}
} else if ( V_143 ) {
struct V_103 * V_104 ;
V_104 = F_78 ( T_4 , NULL ) ;
if ( F_4 ( V_104 ) )
return F_30 ( V_104 ) ;
V_104 -> V_131 = V_147 ;
V_104 -> V_133 . V_143 = V_143 ;
}
}
return 0 ;
}
static int
F_108 ( int V_13 , char * V_65 , T_1 V_193 )
{
char V_194 [ V_195 ] ;
const char * V_196 ;
if ( ! V_65 || ! V_193 )
return - 1 ;
V_13 = V_13 > 0 ? V_13 : - V_13 ;
if ( V_13 >= V_197 )
return F_109 ( V_13 , V_65 , V_193 ) ;
if ( V_13 >= V_198 && V_13 < V_199 ) {
V_196 = V_200 [ F_110 ( V_13 ) ] ;
snprintf ( V_65 , V_193 , L_79 , V_196 ) ;
V_65 [ V_193 - 1 ] = '\0' ;
return 0 ;
}
if ( V_13 >= V_199 )
snprintf ( V_65 , V_193 , L_80 , V_13 ) ;
else
snprintf ( V_65 , V_193 , L_79 ,
F_111 ( V_13 , V_194 , sizeof( V_194 ) ) ) ;
V_65 [ V_193 - 1 ] = '\0' ;
return - 1 ;
}
int F_112 ( const char * V_11 , bool V_12 ,
int V_13 , char * V_65 , T_1 V_193 )
{
T_1 V_57 ;
int V_79 ;
V_57 = snprintf ( V_65 , V_193 , L_81 ,
V_11 , V_12 ? L_82 : L_83 ) ;
if ( V_57 >= V_193 ) {
V_65 [ V_193 - 1 ] = '\0' ;
return 0 ;
}
V_65 += V_57 ;
V_193 -= V_57 ;
V_79 = F_108 ( V_13 , V_65 , V_193 ) ;
V_65 [ V_193 - 1 ] = '\0' ;
return V_79 ;
}
int F_113 ( struct V_1 * V_5 V_17 ,
int V_13 , char * V_65 , T_1 V_193 )
{
F_114 ( V_13 , V_65 , V_193 ) ;
case V_40 : {
F_115 ( V_65 , V_193 , L_84 , V_201 ) ;
break;
}
F_116 ( V_202 , L_85 ) ;
F_116 ( V_203 , L_86 ) ;
F_116 ( V_204 , L_87 ) ;
F_116 ( V_205 , L_88 ) ;
F_117 ( V_65 , V_193 ) ;
return 0 ;
}
int F_118 ( struct V_1 * V_5 ,
int V_13 , char * V_65 , T_1 V_193 )
{
F_114 ( V_13 , V_65 , V_193 ) ;
case V_206 : {
unsigned int V_207 = F_119 ( V_5 ) ;
unsigned int V_208 ;
if ( F_120 ( & V_208 , NULL , 0 ) ) {
F_115 ( V_65 , V_193 , L_89 ) ;
break;
}
if ( V_207 != V_208 ) {
F_115 ( V_65 , V_193 ,
L_90 V_209 L_91 V_209 L_92 ,
F_121 ( V_207 ) ,
F_121 ( V_208 ) ) ;
break;
}
F_115 ( V_65 , V_193 , L_93 ) ;
break;
}
F_117 ( V_65 , V_193 ) ;
return 0 ;
}
int F_122 ( struct V_1 * V_5 V_17 ,
struct V_113 * V_114 V_17 ,
struct V_136 * T_5 V_17 ,
int * V_165 V_17 , int V_13 ,
char * V_65 , T_1 V_193 )
{
F_114 ( V_13 , V_65 , V_193 ) ;
F_116 ( V_126 ,
L_94 ) ;
F_117 ( V_65 , V_193 ) ;
return 0 ;
}
int F_123 ( int V_13 , char * V_65 , T_1 V_193 )
{
F_114 ( V_13 , V_65 , V_193 ) ;
F_116 ( V_183 ,
L_95 ) ;
F_116 ( V_185 ,
L_96 , V_201 ) ;
F_116 ( V_188 ,
L_97 ) ;
F_117 ( V_65 , V_193 ) ;
return 0 ;
}
int F_124 ( struct V_136 * T_5 V_17 ,
int V_13 , char * V_65 , T_1 V_193 )
{
F_114 ( V_13 , V_65 , V_193 ) ;
F_117 ( V_65 , V_193 ) ;
return 0 ;
}
