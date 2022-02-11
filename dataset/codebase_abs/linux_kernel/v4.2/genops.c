static struct V_1 * F_1 ( void )
{
struct V_1 * V_2 ;
F_2 ( V_2 , V_3 , V_4 ) ;
if ( V_2 != NULL ) {
V_2 -> V_5 = V_6 ;
}
return V_2 ;
}
static void F_3 ( struct V_1 * V_2 )
{
F_4 ( V_2 != NULL ) ;
F_5 ( V_2 -> V_5 == V_6 , L_1 ,
V_2 , V_2 -> V_5 , V_6 ) ;
if ( V_2 -> V_7 != NULL ) {
F_6 ( L_2 ,
V_2 , V_2 -> V_7 , V_2 -> V_8 ) ;
F_7 () ;
}
F_8 ( & V_2 -> V_9 ) ;
F_9 ( V_2 , V_3 ) ;
}
struct V_10 * F_10 ( const char * V_11 )
{
struct V_12 * V_13 ;
struct V_10 * type ;
F_11 ( & V_14 ) ;
F_12 (tmp, &obd_types) {
type = F_13 ( V_13 , struct V_10 , V_15 ) ;
if ( strcmp ( type -> V_16 , V_11 ) == 0 ) {
F_14 ( & V_14 ) ;
return type ;
}
}
F_14 ( & V_14 ) ;
return NULL ;
}
struct V_10 * F_15 ( const char * V_11 )
{
struct V_10 * type = F_10 ( V_11 ) ;
if ( ! type ) {
const char * V_17 = V_11 ;
if ( strcmp ( V_17 , L_3 ) == 0 )
V_17 = L_4 ;
if ( strcmp ( V_17 , V_18 ) == 0 )
V_17 = V_19 ;
if ( ! strncmp ( V_17 , V_20 , strlen ( V_20 ) ) )
V_17 = V_21 ;
if ( ! F_16 ( L_5 , V_17 ) ) {
F_17 ( V_22 , L_6 , V_17 ) ;
type = F_10 ( V_11 ) ;
} else {
F_18 ( 0x158 , L_7 ,
V_17 ) ;
}
}
if ( type ) {
F_11 ( & type -> V_23 ) ;
type -> V_24 ++ ;
F_19 ( type -> V_25 -> V_26 ) ;
F_14 ( & type -> V_23 ) ;
}
return type ;
}
void F_20 ( struct V_10 * type )
{
F_4 ( type ) ;
F_11 ( & type -> V_23 ) ;
type -> V_24 -- ;
F_21 ( type -> V_25 -> V_26 ) ;
F_14 ( & type -> V_23 ) ;
}
int F_22 ( struct V_27 * V_28 , struct V_29 * V_29 ,
const char * V_11 ,
struct V_30 * V_31 )
{
struct V_10 * type ;
int V_32 = 0 ;
F_4 ( F_23 ( V_11 , V_33 ) < V_33 ) ;
if ( F_10 ( V_11 ) ) {
F_17 ( V_34 , L_8 , V_11 ) ;
return - V_35 ;
}
V_32 = - V_36 ;
type = F_24 ( sizeof( * type ) , V_4 ) ;
if ( type == NULL )
return V_32 ;
type -> V_25 = F_24 ( sizeof( * type -> V_25 ) , V_4 ) ;
type -> V_37 = F_24 ( sizeof( * type -> V_37 ) , V_4 ) ;
type -> V_16 = F_24 ( strlen ( V_11 ) + 1 , V_4 ) ;
if ( type -> V_25 == NULL ||
type -> V_37 == NULL ||
type -> V_16 == NULL )
goto V_38;
* ( type -> V_25 ) = * V_28 ;
if ( V_29 )
* ( type -> V_37 ) = * V_29 ;
strcpy ( type -> V_16 , V_11 ) ;
F_25 ( & type -> V_23 ) ;
type -> V_39 = F_26 ( type -> V_16 ,
V_40 ,
NULL , type ) ;
if ( F_27 ( type -> V_39 ) ) {
V_32 = type -> V_39 ? F_28 ( type -> V_39 )
: - V_36 ;
type -> V_39 = NULL ;
goto V_38;
}
type -> V_41 = F_29 ( type -> V_16 , V_42 ) ;
if ( ! type -> V_41 ) {
V_32 = - V_36 ;
goto V_38;
}
if ( V_31 != NULL ) {
type -> V_43 = V_31 ;
V_32 = F_30 ( V_31 ) ;
if ( V_32 != 0 )
goto V_38;
}
F_11 ( & V_14 ) ;
F_31 ( & type -> V_15 , & V_44 ) ;
F_14 ( & V_14 ) ;
return 0 ;
V_38:
if ( type -> V_41 )
F_32 ( type -> V_41 ) ;
F_33 ( type -> V_16 ) ;
F_33 ( type -> V_37 ) ;
F_33 ( type -> V_25 ) ;
F_33 ( type ) ;
return V_32 ;
}
int F_34 ( const char * V_11 )
{
struct V_10 * type = F_10 ( V_11 ) ;
if ( ! type ) {
F_6 ( L_9 ) ;
return - V_45 ;
}
if ( type -> V_24 ) {
F_6 ( L_10 , V_11 , type -> V_24 ) ;
F_33 ( type -> V_25 ) ;
F_33 ( type -> V_37 ) ;
return - V_46 ;
}
if ( type -> V_41 )
F_32 ( type -> V_41 ) ;
if ( ! F_27 ( type -> V_39 ) )
F_35 ( & type -> V_39 ) ;
if ( type -> V_43 )
F_36 ( type -> V_43 ) ;
F_11 ( & V_14 ) ;
F_37 ( & type -> V_15 ) ;
F_14 ( & V_14 ) ;
F_33 ( type -> V_16 ) ;
F_33 ( type -> V_25 ) ;
F_33 ( type -> V_37 ) ;
F_33 ( type ) ;
return 0 ;
}
struct V_1 * F_38 ( const char * V_47 , const char * V_11 )
{
struct V_1 * V_48 = NULL ;
struct V_1 * V_49 ;
struct V_10 * type = NULL ;
int V_50 ;
int V_51 = 0 ;
if ( strlen ( V_11 ) >= V_52 ) {
F_6 ( L_11 , V_52 ) ;
return F_39 ( - V_45 ) ;
}
type = F_15 ( V_47 ) ;
if ( type == NULL ) {
F_6 ( L_12 , V_47 ) ;
return F_39 ( - V_53 ) ;
}
V_49 = F_1 () ;
if ( V_49 == NULL ) {
V_48 = F_39 ( - V_36 ) ;
goto V_54;
}
F_4 ( V_49 -> V_5 == V_6 ) ;
F_40 ( & V_55 ) ;
for ( V_50 = 0 ; V_50 < F_41 () ; V_50 ++ ) {
struct V_1 * V_2 = F_42 ( V_50 ) ;
if ( V_2 && ( strcmp ( V_11 , V_2 -> V_56 ) == 0 ) ) {
F_6 ( L_13 ,
V_11 , V_50 ) ;
if ( V_48 ) {
F_5 ( V_48 -> V_5 == V_6 ,
L_14 , V_48 ,
V_48 -> V_5 , V_6 ) ;
F_5 ( V_48 -> V_57 == V_51 ,
L_15 , V_48 ,
V_48 -> V_57 , V_51 ) ;
V_58 [ V_48 -> V_57 ] = NULL ;
V_48 -> V_56 [ 0 ] = '\0' ;
}
V_48 = F_39 ( - V_35 ) ;
break;
}
if ( ! V_48 && ! V_2 ) {
V_48 = V_49 ;
V_48 -> V_57 = V_50 ;
V_51 = V_50 ;
V_48 -> V_10 = type ;
strncpy ( V_48 -> V_56 , V_11 ,
sizeof( V_48 -> V_56 ) - 1 ) ;
V_58 [ V_50 ] = V_48 ;
}
}
F_43 ( & V_55 ) ;
if ( V_48 == NULL && V_50 >= F_41 () ) {
F_6 ( L_16 ,
F_41 () ) ;
V_48 = F_39 ( - V_59 ) ;
goto V_60;
}
if ( F_44 ( V_48 ) )
goto V_60;
F_17 ( V_34 , L_17 ,
V_48 -> V_56 , V_48 ) ;
return V_48 ;
V_60:
F_3 ( V_49 ) ;
V_54:
F_20 ( type ) ;
return V_48 ;
}
void F_45 ( struct V_1 * V_2 )
{
struct V_10 * V_10 = V_2 -> V_10 ;
F_5 ( V_2 -> V_5 == V_6 , L_14 ,
V_2 , V_2 -> V_5 , V_6 ) ;
F_5 ( V_2 == V_58 [ V_2 -> V_57 ] , L_18 ,
V_2 , V_2 -> V_57 , V_58 [ V_2 -> V_57 ] ) ;
F_4 ( V_10 != NULL ) ;
F_17 ( V_22 , L_19 ,
V_2 -> V_56 , V_2 -> V_57 , V_2 -> V_10 -> V_16 ) ;
F_40 ( & V_55 ) ;
V_58 [ V_2 -> V_57 ] = NULL ;
F_43 ( & V_55 ) ;
F_3 ( V_2 ) ;
F_20 ( V_10 ) ;
}
int F_46 ( const char * V_11 )
{
int V_50 ;
if ( ! V_11 )
return - 1 ;
F_47 ( & V_55 ) ;
for ( V_50 = 0 ; V_50 < F_41 () ; V_50 ++ ) {
struct V_1 * V_2 = F_42 ( V_50 ) ;
if ( V_2 && strcmp ( V_11 , V_2 -> V_56 ) == 0 ) {
F_4 ( V_2 -> V_5 == V_6 ) ;
if ( V_2 -> V_61 ) {
F_48 ( & V_55 ) ;
return V_50 ;
}
break;
}
}
F_48 ( & V_55 ) ;
return - 1 ;
}
struct V_1 * F_49 ( const char * V_11 )
{
int V_62 = F_46 ( V_11 ) ;
if ( V_62 < 0 || V_62 > F_41 () )
return NULL ;
return F_42 ( V_62 ) ;
}
int F_50 ( struct V_63 * V_64 )
{
int V_50 ;
F_47 ( & V_55 ) ;
for ( V_50 = 0 ; V_50 < F_41 () ; V_50 ++ ) {
struct V_1 * V_2 = F_42 ( V_50 ) ;
if ( V_2 && F_51 ( V_64 , & V_2 -> V_63 ) ) {
F_4 ( V_2 -> V_5 == V_6 ) ;
F_48 ( & V_55 ) ;
return V_50 ;
}
}
F_48 ( & V_55 ) ;
return - 1 ;
}
struct V_1 * F_52 ( struct V_63 * V_64 )
{
int V_62 = F_50 ( V_64 ) ;
if ( V_62 < 0 )
return NULL ;
return F_42 ( V_62 ) ;
}
struct V_1 * F_42 ( int V_65 )
{
struct V_1 * V_2 = NULL ;
if ( V_65 < F_41 () ) {
V_2 = V_58 [ V_65 ] ;
if ( V_2 == NULL )
return NULL ;
F_5 ( V_2 -> V_5 == V_6 ,
L_14 ,
V_2 , V_2 -> V_5 , V_6 ) ;
F_5 ( V_2 -> V_57 == V_65 ,
L_20 ,
V_2 , V_2 -> V_57 , V_65 ) ;
}
return V_2 ;
}
int F_53 ( void )
{
int V_66 , V_67 = F_41 () , V_68 = 0 ;
F_47 ( & V_55 ) ;
for ( V_66 = 0 ; V_66 <= V_67 ; V_66 ++ ) {
struct V_1 * V_2 = F_42 ( V_66 ) ;
if ( V_2 != NULL )
V_68 ++ ;
}
F_48 ( & V_55 ) ;
return V_68 ;
}
void F_54 ( void )
{
char * V_69 ;
int V_50 ;
F_47 ( & V_55 ) ;
for ( V_50 = 0 ; V_50 < F_41 () ; V_50 ++ ) {
struct V_1 * V_2 = F_42 ( V_50 ) ;
if ( V_2 == NULL )
continue;
if ( V_2 -> V_70 )
V_69 = L_21 ;
else if ( V_2 -> V_71 )
V_69 = L_22 ;
else if ( V_2 -> V_61 )
V_69 = L_23 ;
else
V_69 = L_24 ;
F_55 ( V_72 , L_25 ,
V_50 , V_69 , V_2 -> V_10 -> V_16 ,
V_2 -> V_56 , V_2 -> V_63 . V_64 ,
F_56 ( & V_2 -> V_73 ) ) ;
}
F_48 ( & V_55 ) ;
return;
}
struct V_1 * F_57 ( struct V_63 * V_74 ,
const char * V_16 ,
struct V_63 * V_75 )
{
int V_50 ;
F_47 ( & V_55 ) ;
for ( V_50 = 0 ; V_50 < F_41 () ; V_50 ++ ) {
struct V_1 * V_2 = F_42 ( V_50 ) ;
if ( V_2 == NULL )
continue;
if ( ( strncmp ( V_2 -> V_10 -> V_16 , V_16 ,
strlen ( V_16 ) ) == 0 ) ) {
if ( F_51 ( V_74 ,
& V_2 -> V_76 . V_77 . V_78 ) &&
( ( V_75 ) ? F_51 ( V_75 ,
& V_2 -> V_63 ) : 1 ) ) {
F_48 ( & V_55 ) ;
return V_2 ;
}
}
}
F_48 ( & V_55 ) ;
return NULL ;
}
struct V_1 * F_58 ( struct V_63 * V_75 , int * V_79 )
{
int V_50 ;
if ( V_79 == NULL )
V_50 = 0 ;
else if ( * V_79 >= 0 && * V_79 < F_41 () )
V_50 = * V_79 ;
else
return NULL ;
F_47 ( & V_55 ) ;
for (; V_50 < F_41 () ; V_50 ++ ) {
struct V_1 * V_2 = F_42 ( V_50 ) ;
if ( V_2 == NULL )
continue;
if ( F_51 ( V_75 , & V_2 -> V_63 ) ) {
if ( V_79 != NULL )
* V_79 = V_50 + 1 ;
F_48 ( & V_55 ) ;
return V_2 ;
}
}
F_48 ( & V_55 ) ;
return NULL ;
}
int F_59 ( const char * V_80 , int V_81 )
{
struct V_1 * V_2 ;
const char * type ;
int V_50 , V_32 = 0 , V_82 ;
F_4 ( V_81 > 0 ) ;
F_47 ( & V_55 ) ;
for ( V_50 = 0 ; V_50 < F_41 () ; V_50 ++ ) {
V_2 = F_42 ( V_50 ) ;
if ( V_2 == NULL || V_2 -> V_71 == 0 || V_2 -> V_70 )
continue;
type = V_2 -> V_10 -> V_16 ;
if ( strcmp ( type , V_83 ) != 0 &&
strcmp ( type , V_84 ) != 0 &&
strcmp ( type , V_21 ) != 0 &&
strcmp ( type , V_85 ) != 0 )
continue;
if ( strncmp ( V_2 -> V_56 , V_80 , V_81 ) )
continue;
F_60 ( V_2 , V_86 , V_2 ) ;
F_48 ( & V_55 ) ;
V_82 = F_61 ( NULL , V_2 -> V_87 ,
sizeof( V_88 ) ,
V_88 , 0 , NULL , NULL ) ;
V_32 = V_32 ? V_32 : V_82 ;
F_62 ( V_2 , V_86 , V_2 ) ;
F_47 ( & V_55 ) ;
}
F_48 ( & V_55 ) ;
return V_32 ;
}
void F_63 ( void )
{
if ( V_3 ) {
F_64 ( V_3 ) ;
V_3 = NULL ;
}
if ( V_89 ) {
F_64 ( V_89 ) ;
V_89 = NULL ;
}
if ( V_90 ) {
F_64 ( V_90 ) ;
V_90 = NULL ;
}
if ( V_91 ) {
F_64 ( V_91 ) ;
V_91 = NULL ;
}
}
int F_65 ( void )
{
F_4 ( V_3 == NULL ) ;
V_3 = F_66 ( L_26 ,
sizeof( struct V_1 ) ,
0 , 0 , NULL ) ;
if ( ! V_3 )
goto V_60;
F_4 ( V_89 == NULL ) ;
V_89 = F_66 ( L_27 , sizeof( struct V_92 ) ,
0 , 0 , NULL ) ;
if ( ! V_89 )
goto V_60;
F_4 ( V_90 == NULL ) ;
V_90 = F_66 ( L_28 ,
sizeof( struct V_93 ) ,
0 , 0 , NULL ) ;
if ( ! V_90 )
goto V_60;
F_4 ( V_91 == NULL ) ;
V_91 = F_66 ( L_29 ,
sizeof( struct V_94 ) , 0 , 0 , NULL ) ;
if ( ! V_91 )
goto V_60;
return 0 ;
V_60:
F_63 () ;
return - V_36 ;
}
struct V_95 * F_67 ( struct V_96 * V_97 )
{
struct V_95 * V_98 ;
if ( ! V_97 ) {
F_17 ( V_99 , L_30 ) ;
return NULL ;
}
if ( V_97 -> V_100 == - 1 ) {
F_17 ( V_99 , L_31 ) ;
return NULL ;
}
F_17 ( V_22 , L_32 , V_97 -> V_100 ) ;
V_98 = F_68 ( V_97 -> V_100 ) ;
return V_98 ;
}
struct V_1 * F_69 ( struct V_95 * exp )
{
if ( exp )
return exp -> V_101 ;
return NULL ;
}
struct V_1 * F_70 ( struct V_96 * V_97 )
{
struct V_95 * V_98 ;
V_98 = F_67 ( V_97 ) ;
if ( V_98 ) {
struct V_1 * V_2 = V_98 -> V_101 ;
F_71 ( V_98 ) ;
return V_2 ;
}
return NULL ;
}
struct V_93 * F_72 ( struct V_95 * exp )
{
struct V_1 * V_2 = exp -> V_101 ;
if ( V_2 == NULL )
return NULL ;
return V_2 -> V_76 . V_77 . V_102 ;
}
struct V_93 * F_73 ( struct V_96 * V_97 )
{
struct V_1 * V_2 = F_70 ( V_97 ) ;
if ( V_2 == NULL )
return NULL ;
return V_2 -> V_76 . V_77 . V_102 ;
}
static void F_74 ( struct V_95 * exp )
{
struct V_1 * V_2 = exp -> V_101 ;
F_75 ( & exp -> V_103 ) ;
F_4 ( V_2 != NULL ) ;
F_17 ( V_34 , L_33 , exp ,
exp -> V_104 . V_64 , V_2 -> V_56 ) ;
if ( exp -> V_105 )
F_76 ( exp -> V_105 ) ;
F_4 ( F_77 ( & exp -> V_106 ) ) ;
F_4 ( F_77 ( & exp -> V_107 ) ) ;
F_4 ( F_77 ( & exp -> V_108 ) ) ;
F_4 ( F_77 ( & exp -> V_109 ) ) ;
F_78 ( exp ) ;
F_62 ( V_2 , L_34 , exp ) ;
F_79 ( exp , sizeof( * exp ) , & exp -> V_110 ) ;
}
static void F_80 ( void * V_98 )
{
F_81 ( V_98 ) ;
}
struct V_95 * F_81 ( struct V_95 * exp )
{
F_82 ( & exp -> V_103 ) ;
F_17 ( V_22 , L_35 , exp ,
F_56 ( & exp -> V_103 ) ) ;
return exp ;
}
void F_71 ( struct V_95 * exp )
{
F_4 ( exp != NULL ) ;
F_83 ( & exp -> V_103 , 0 , V_111 ) ;
F_17 ( V_22 , L_36 , exp ,
F_56 ( & exp -> V_103 ) - 1 ) ;
if ( F_84 ( & exp -> V_103 ) ) {
F_4 ( ! F_77 ( & exp -> V_112 ) ) ;
F_17 ( V_34 , L_37 ,
exp , exp -> V_104 . V_64 ) ;
F_85 ( exp ) ;
F_86 ( exp ) ;
}
}
struct V_95 * F_87 ( struct V_1 * V_2 ,
struct V_63 * V_113 )
{
struct V_95 * V_98 ;
struct V_114 * V_115 = NULL ;
int V_32 = 0 ;
V_98 = F_24 ( sizeof( * V_98 ) , V_4 ) ;
if ( ! V_98 )
return F_39 ( - V_36 ) ;
V_98 -> V_116 = 0 ;
V_98 -> V_117 = NULL ;
V_98 -> V_118 = NULL ;
F_88 ( & V_98 -> V_103 , 2 ) ;
F_88 ( & V_98 -> V_119 , 0 ) ;
F_88 ( & V_98 -> V_120 , 0 ) ;
F_88 ( & V_98 -> V_121 , 0 ) ;
#if V_122
F_89 ( & V_98 -> V_123 ) ;
F_25 ( & V_98 -> V_124 ) ;
#endif
F_88 ( & V_98 -> V_125 , 0 ) ;
V_98 -> V_101 = V_2 ;
F_89 ( & V_98 -> V_106 ) ;
F_25 ( & V_98 -> V_126 ) ;
F_89 ( & V_98 -> V_107 ) ;
F_89 ( & V_98 -> V_108 ) ;
F_89 ( & V_98 -> V_110 . V_127 ) ;
F_89 ( & V_98 -> V_109 ) ;
F_90 ( & V_98 -> V_110 , & V_128 ) ;
V_98 -> V_129 = F_91 () ;
F_25 ( & V_98 -> V_130 ) ;
F_25 ( & V_98 -> V_131 ) ;
F_92 ( & V_98 -> V_132 ) ;
F_92 ( & V_98 -> V_133 ) ;
F_25 ( & V_98 -> V_134 ) ;
F_89 ( & V_98 -> V_135 ) ;
V_98 -> V_136 = V_137 ;
V_98 -> V_138 . V_139 = V_140 ;
V_98 -> V_104 = * V_113 ;
F_93 ( V_98 ) ;
F_11 ( & V_2 -> V_55 ) ;
if ( V_2 -> V_70 ) {
V_32 = - V_53 ;
goto V_141;
}
V_115 = F_94 ( V_2 -> V_142 ) ;
if ( V_115 == NULL ) {
V_32 = - V_53 ;
goto V_141;
}
F_14 ( & V_2 -> V_55 ) ;
if ( ! F_51 ( V_113 , & V_2 -> V_63 ) ) {
V_32 = F_95 ( V_115 , V_113 , & V_98 -> V_132 ) ;
if ( V_32 != 0 ) {
F_96 ( L_38 ,
V_2 -> V_56 , V_113 -> V_64 , V_32 ) ;
V_32 = - V_143 ;
goto V_144;
}
}
F_11 ( & V_2 -> V_55 ) ;
if ( V_2 -> V_70 ) {
F_97 ( V_115 , V_113 , & V_98 -> V_132 ) ;
V_32 = - V_53 ;
goto V_141;
}
F_60 ( V_2 , L_34 , V_98 ) ;
F_31 ( & V_98 -> V_112 , & V_98 -> V_101 -> V_145 ) ;
F_98 ( & V_98 -> V_146 ,
& V_98 -> V_101 -> V_147 ) ;
V_98 -> V_101 -> V_148 ++ ;
F_14 ( & V_2 -> V_55 ) ;
F_99 ( V_115 ) ;
return V_98 ;
V_141:
F_14 ( & V_2 -> V_55 ) ;
V_144:
if ( V_115 )
F_99 ( V_115 ) ;
F_100 ( & V_98 -> V_110 ) ;
F_4 ( F_101 ( & V_98 -> V_132 ) ) ;
F_78 ( V_98 ) ;
F_33 ( V_98 ) ;
return F_39 ( V_32 ) ;
}
void F_102 ( struct V_95 * exp )
{
F_100 ( & exp -> V_110 ) ;
F_11 ( & exp -> V_101 -> V_55 ) ;
if ( ! F_101 ( & exp -> V_132 ) )
F_97 ( exp -> V_101 -> V_142 ,
& exp -> V_104 ,
& exp -> V_132 ) ;
F_103 ( & exp -> V_112 , & exp -> V_101 -> V_149 ) ;
F_104 ( & exp -> V_146 ) ;
exp -> V_101 -> V_148 -- ;
F_14 ( & exp -> V_101 -> V_55 ) ;
F_71 ( exp ) ;
}
static void F_105 ( struct V_93 * V_150 )
{
F_17 ( V_34 , L_39 , V_150 ,
V_150 -> V_151 -> V_56 ) ;
F_75 ( & V_150 -> V_152 ) ;
F_76 ( V_150 -> V_153 ) ;
while ( ! F_77 ( & V_150 -> V_154 ) ) {
struct V_155 * V_156 ;
V_156 = F_13 ( V_150 -> V_154 . V_79 ,
struct V_155 , V_157 ) ;
F_104 ( & V_156 -> V_157 ) ;
F_76 ( V_156 -> V_158 ) ;
F_33 ( V_156 ) ;
}
F_4 ( V_150 -> V_159 == NULL ) ;
F_62 ( V_150 -> V_151 , L_40 , V_150 ) ;
F_79 ( V_150 , sizeof( * V_150 ) , & V_150 -> V_160 ) ;
}
static void F_106 ( void * V_161 )
{
F_107 ( V_161 ) ;
}
struct V_93 * F_107 ( struct V_93 * V_161 )
{
F_82 ( & V_161 -> V_152 ) ;
F_17 ( V_22 , L_41 , V_161 ,
F_56 ( & V_161 -> V_152 ) ,
V_161 -> V_151 -> V_56 ) ;
return V_161 ;
}
void F_108 ( struct V_93 * V_150 )
{
F_4 ( F_77 ( & V_150 -> V_162 ) ) ;
F_83 ( & V_150 -> V_152 , 0 , V_111 ) ;
F_17 ( V_22 , L_41 , V_150 ,
F_56 ( & V_150 -> V_152 ) - 1 ,
V_150 -> V_151 -> V_56 ) ;
if ( F_84 ( & V_150 -> V_152 ) ) {
F_17 ( V_22 , L_42 , V_150 ) ;
F_109 ( V_150 ) ;
}
F_110 ( & V_150 -> V_152 , 0 , V_111 ) ;
}
static void F_111 ( struct V_163 * V_164 ) {
int V_50 ;
F_112 ( & V_164 -> V_165 , 0 , 0 ) ;
for ( V_50 = 0 ; V_50 < V_166 ; V_50 ++ ) {
F_112 ( & V_164 -> V_167 [ V_50 ] , V_168 ,
V_169 ) ;
}
}
struct V_93 * F_113 ( struct V_1 * V_2 )
{
struct V_93 * V_150 ;
V_150 = F_24 ( sizeof( * V_150 ) , V_4 ) ;
if ( V_150 == NULL )
return NULL ;
F_89 ( & V_150 -> V_170 ) ;
F_89 ( & V_150 -> V_162 ) ;
F_89 ( & V_150 -> V_171 ) ;
F_89 ( & V_150 -> V_172 ) ;
F_89 ( & V_150 -> V_173 ) ;
F_89 ( & V_150 -> V_174 ) ;
V_150 -> V_175 = & V_150 -> V_174 ;
F_25 ( & V_150 -> V_176 ) ;
V_150 -> V_177 = 0 ;
V_150 -> V_178 = V_179 ;
V_150 -> V_151 = F_60 ( V_2 , L_40 , V_150 ) ;
F_114 ( & V_150 -> V_180 ) ;
F_115 ( & V_150 -> V_181 ) ;
F_88 ( & V_150 -> V_152 , 2 ) ;
F_88 ( & V_150 -> V_182 , 0 ) ;
F_88 ( & V_150 -> V_183 , 0 ) ;
F_88 ( & V_150 -> V_184 , 0 ) ;
F_88 ( & V_150 -> V_185 , 0 ) ;
F_89 ( & V_150 -> V_154 ) ;
F_89 ( & V_150 -> V_160 . V_127 ) ;
F_90 ( & V_150 -> V_160 , & V_186 ) ;
F_111 ( & V_150 -> V_163 ) ;
V_150 -> V_187 = V_188 ;
return V_150 ;
}
void F_116 ( struct V_93 * V_161 )
{
F_4 ( V_161 != NULL ) ;
F_4 ( V_161 != V_189 ) ;
F_100 ( & V_161 -> V_160 ) ;
F_11 ( & V_161 -> V_176 ) ;
V_161 -> V_190 ++ ;
F_14 ( & V_161 -> V_176 ) ;
F_108 ( V_161 ) ;
}
void F_117 ( struct V_95 * exp , struct V_191 * V_192 )
{
F_11 ( & exp -> V_124 ) ;
F_4 ( V_192 -> V_193 >= 0 ) ;
if ( V_192 -> V_194 != NULL &&
V_192 -> V_194 != exp ) {
F_96 ( L_43 ,
exp , V_192 , V_192 -> V_194 ) ;
}
if ( ( V_192 -> V_193 ++ ) == 0 ) {
F_31 ( & V_192 -> V_195 , & exp -> V_123 ) ;
V_192 -> V_194 = exp ;
}
F_17 ( V_22 , L_44 ,
V_192 , exp , V_192 -> V_193 ) ;
F_14 ( & exp -> V_124 ) ;
}
void F_118 ( struct V_95 * exp , struct V_191 * V_192 )
{
F_11 ( & exp -> V_124 ) ;
F_4 ( V_192 -> V_193 > 0 ) ;
if ( V_192 -> V_194 != exp ) {
F_96 ( L_45 ,
V_192 , V_192 -> V_194 , exp ) ;
}
if ( -- V_192 -> V_193 == 0 ) {
F_104 ( & V_192 -> V_195 ) ;
V_192 -> V_194 = NULL ;
}
F_17 ( V_22 , L_44 ,
V_192 , exp , V_192 -> V_193 ) ;
F_14 ( & exp -> V_124 ) ;
}
int F_119 ( struct V_96 * V_97 , struct V_1 * V_2 ,
struct V_63 * V_113 )
{
struct V_95 * V_98 ;
F_4 ( V_97 != NULL ) ;
F_4 ( V_2 != NULL ) ;
F_4 ( V_113 != NULL ) ;
V_98 = F_87 ( V_2 , V_113 ) ;
if ( F_44 ( V_98 ) )
return F_28 ( V_98 ) ;
V_97 -> V_100 = V_98 -> V_110 . V_196 ;
F_71 ( V_98 ) ;
F_17 ( V_34 , L_46 ,
V_113 -> V_64 , V_97 -> V_100 ) ;
return 0 ;
}
static void F_120 ( struct V_95 * exp )
{
struct V_1 * V_2 = exp -> V_101 ;
F_11 ( & V_2 -> V_197 ) ;
if ( exp -> V_198 )
V_2 -> V_199 -- ;
if ( V_2 -> V_200 ) {
if ( exp -> V_201 ) {
F_11 ( & exp -> V_130 ) ;
exp -> V_201 = 0 ;
F_14 ( & exp -> V_130 ) ;
F_121 ( & V_2 -> V_202 ) ;
F_122 ( & V_2 -> V_202 ) ;
}
if ( exp -> V_203 &&
( F_123 ( exp ) & V_204 ) == 0 )
exp -> V_101 -> V_205 ++ ;
}
F_14 ( & V_2 -> V_197 ) ;
F_11 ( & exp -> V_130 ) ;
if ( exp -> V_206 ) {
exp -> V_206 = 0 ;
F_4 ( F_56 ( & V_2 -> V_207 ) ) ;
F_122 ( & V_2 -> V_207 ) ;
}
if ( exp -> V_208 ) {
exp -> V_208 = 0 ;
F_4 ( F_56 ( & V_2 -> V_209 ) ) ;
F_122 ( & V_2 -> V_209 ) ;
}
F_14 ( & exp -> V_130 ) ;
}
int F_124 ( struct V_95 * V_98 )
{
int V_210 ;
if ( V_98 == NULL ) {
F_125 ( L_47 , V_98 ) ;
return - V_45 ;
}
F_11 ( & V_98 -> V_130 ) ;
V_210 = V_98 -> V_211 ;
V_98 -> V_211 = 1 ;
F_14 ( & V_98 -> V_130 ) ;
if ( V_210 ) {
F_4 ( F_101 ( & V_98 -> V_133 ) ) ;
goto V_212;
}
F_17 ( V_34 , L_48 ,
V_98 -> V_110 . V_196 ) ;
if ( ! F_101 ( & V_98 -> V_133 ) )
F_97 ( V_98 -> V_101 -> V_213 ,
& V_98 -> V_105 -> V_214 . V_215 ,
& V_98 -> V_133 ) ;
F_120 ( V_98 ) ;
F_102 ( V_98 ) ;
V_212:
F_71 ( V_98 ) ;
return 0 ;
}
int F_126 ( struct V_95 * exp )
{
if ( exp ) {
int V_216 ;
F_11 ( & exp -> V_130 ) ;
V_216 = exp -> V_116 > 0 ;
F_14 ( & exp -> V_130 ) ;
return V_216 ;
}
return 0 ;
}
static void F_127 ( struct V_12 * V_217 ,
enum V_218 V_219 )
{
int V_32 ;
struct V_95 * exp ;
while ( ! F_77 ( V_217 ) ) {
exp = F_13 ( V_217 -> V_79 , struct V_95 ,
V_112 ) ;
F_81 ( exp ) ;
F_11 ( & exp -> V_130 ) ;
exp -> V_220 = V_219 ;
F_14 ( & exp -> V_130 ) ;
if ( F_51 ( & exp -> V_104 ,
& exp -> V_101 -> V_63 ) ) {
F_17 ( V_221 ,
L_49 ,
exp ) ;
F_104 ( & exp -> V_112 ) ;
F_71 ( exp ) ;
continue;
}
F_81 ( exp ) ;
F_17 ( V_221 , L_50 V_222 L_51 ,
exp -> V_101 -> V_56 , F_128 ( exp ) ,
exp , exp -> V_129 ) ;
V_32 = F_129 ( exp ) ;
F_17 ( V_221 , L_52 ,
F_128 ( exp ) , exp , V_32 ) ;
F_71 ( exp ) ;
}
}
void F_130 ( struct V_1 * V_2 )
{
struct V_12 V_223 ;
F_89 ( & V_223 ) ;
F_11 ( & V_2 -> V_55 ) ;
F_131 ( & V_2 -> V_145 , & V_223 ) ;
F_131 ( & V_2 -> V_224 , & V_223 ) ;
F_14 ( & V_2 -> V_55 ) ;
if ( ! F_77 ( & V_223 ) ) {
F_17 ( V_221 , L_53 ,
V_2 -> V_57 , V_2 ) ;
F_127 ( & V_223 ,
F_132 ( V_2 ) ) ;
} else
F_17 ( V_221 , L_54 ,
V_2 -> V_57 , V_2 ) ;
}
void F_133 ( struct V_1 * V_2 ,
int (* F_134)( struct V_95 * ) )
{
struct V_12 V_223 ;
struct V_95 * exp , * V_225 ;
int V_226 = 0 ;
F_89 ( & V_223 ) ;
F_11 ( & V_2 -> V_55 ) ;
F_135 (exp, n, &obd->obd_exports,
exp_obd_chain) {
if ( F_51 ( & exp -> V_104 ,
& exp -> V_101 -> V_63 ) )
continue;
if ( exp -> V_227 . V_228 == - 1 )
continue;
F_11 ( & exp -> V_130 ) ;
if ( exp -> V_203 || F_134 ( exp ) ) {
F_14 ( & exp -> V_130 ) ;
continue;
}
exp -> V_203 = 1 ;
F_14 ( & exp -> V_130 ) ;
F_103 ( & exp -> V_112 , & V_223 ) ;
V_226 ++ ;
F_17 ( V_221 , L_55 ,
V_2 -> V_56 , exp -> V_104 . V_64 ,
exp -> V_105 == NULL ? L_56 :
F_136 ( exp -> V_105 -> V_214 . V_215 ) ) ;
F_137 ( exp , L_57 , 0 ) ;
}
F_14 ( & V_2 -> V_55 ) ;
if ( V_226 )
F_96 ( L_58 ,
V_2 -> V_56 , V_226 ) ;
F_127 ( & V_223 , F_132 ( V_2 ) |
V_229 ) ;
}
void F_138 ( struct V_95 * exp )
{
int V_32 , V_230 ;
F_11 ( & exp -> V_130 ) ;
V_230 = exp -> V_203 ;
exp -> V_203 = 1 ;
F_14 ( & exp -> V_130 ) ;
if ( V_230 ) {
F_17 ( V_221 , L_59 ,
exp , exp -> V_104 . V_64 ) ;
return;
}
F_17 ( V_221 , L_60 ,
exp , exp -> V_104 . V_64 ) ;
if ( V_231 )
F_139 () ;
F_81 ( exp ) ;
F_81 ( exp ) ;
V_32 = F_129 ( exp ) ;
if ( V_32 )
F_6 ( L_61 , exp , V_32 ) ;
else
F_17 ( V_221 , L_62 ,
exp , exp -> V_104 . V_64 ) ;
F_71 ( exp ) ;
}
char * F_128 ( struct V_95 * exp )
{
if ( exp -> V_105 != NULL )
return F_136 ( exp -> V_105 -> V_214 . V_215 ) ;
return L_63 ;
}
int F_140 ( struct V_1 * V_2 , const char * V_215 )
{
struct V_114 * V_232 ;
struct V_95 * V_233 = NULL ;
int V_234 = 0 ;
T_1 V_235 = F_141 ( ( char * ) V_215 ) ;
F_11 ( & V_2 -> V_55 ) ;
if ( V_2 -> V_70 ) {
F_14 ( & V_2 -> V_55 ) ;
return V_234 ;
}
V_232 = V_2 -> V_213 ;
F_94 ( V_232 ) ;
F_14 ( & V_2 -> V_55 ) ;
do {
V_233 = F_142 ( V_232 , & V_235 ) ;
if ( V_233 == NULL )
break;
F_5 ( V_233 -> V_105 -> V_214 . V_215 == V_235 ,
L_64 ,
F_128 ( V_233 ) ,
F_136 ( V_235 ) , V_215 ) ;
F_5 ( V_233 != V_2 -> V_87 ,
L_65 ) ;
V_234 ++ ;
F_96 ( L_66 ,
V_2 -> V_56 ,
F_143 ( & V_233 -> V_104 ) ,
F_128 ( V_233 ) ) ;
F_138 ( V_233 ) ;
F_71 ( V_233 ) ;
} while ( 1 );
F_99 ( V_232 ) ;
if ( ! V_234 )
F_17 ( V_221 ,
L_67 ,
V_2 -> V_56 , V_215 ) ;
return V_234 ;
}
int F_144 ( struct V_1 * V_2 , const char * V_64 )
{
struct V_114 * V_236 ;
struct V_95 * V_233 = NULL ;
struct V_63 V_237 ;
int V_234 = 0 ;
F_11 ( & V_2 -> V_55 ) ;
if ( V_2 -> V_70 ) {
F_14 ( & V_2 -> V_55 ) ;
return V_234 ;
}
V_236 = V_2 -> V_142 ;
F_94 ( V_236 ) ;
F_14 ( & V_2 -> V_55 ) ;
F_145 ( & V_237 , V_64 ) ;
if ( F_51 ( & V_237 , & V_2 -> V_63 ) ) {
F_6 ( L_68 , V_2 -> V_56 ) ;
F_99 ( V_236 ) ;
return V_234 ;
}
V_233 = F_142 ( V_236 , & V_237 ) ;
if ( V_233 == NULL ) {
F_6 ( L_69 ,
V_2 -> V_56 , V_64 ) ;
} else {
F_125 ( L_70 ,
V_2 -> V_56 , V_233 -> V_104 . V_64 ) ;
F_138 ( V_233 ) ;
F_71 ( V_233 ) ;
V_234 ++ ;
}
F_99 ( V_236 ) ;
return V_234 ;
}
static void F_137 ( struct V_95 * exp , const char * V_69 ,
int V_238 )
{
struct V_239 * V_240 ;
struct V_239 * V_241 = NULL ;
int V_242 = 0 ;
F_11 ( & exp -> V_130 ) ;
F_146 (rs, &exp->exp_outstanding_replies,
rs_exp_list) {
if ( V_242 == 0 )
V_241 = V_240 ;
V_242 ++ ;
}
F_14 ( & exp -> V_130 ) ;
F_17 ( V_221 , L_71 ,
exp -> V_101 -> V_56 , V_69 , exp , exp -> V_104 . V_64 ,
F_128 ( exp ) , F_56 ( & exp -> V_103 ) ,
F_56 ( & exp -> V_119 ) ,
F_56 ( & exp -> V_120 ) ,
F_56 ( & exp -> V_121 ) ,
exp -> V_211 , exp -> V_198 , exp -> V_203 ,
V_242 , V_241 , V_242 > 3 ? L_72 : L_73 ,
exp -> V_243 ) ;
#if V_122
if ( V_238 && V_244 != NULL )
V_244 ( exp ) ;
#endif
}
void F_147 ( struct V_1 * V_2 , int V_238 )
{
struct V_95 * exp ;
F_11 ( & V_2 -> V_55 ) ;
F_146 (exp, &obd->obd_exports, exp_obd_chain)
F_137 ( exp , L_74 , V_238 ) ;
F_146 (exp, &obd->obd_unlinked_exports, exp_obd_chain)
F_137 ( exp , L_75 , V_238 ) ;
F_146 (exp, &obd->obd_delayed_exports, exp_obd_chain)
F_137 ( exp , L_76 , V_238 ) ;
F_14 ( & V_2 -> V_55 ) ;
F_11 ( & V_245 ) ;
F_146 (exp, &obd_zombie_exports, exp_obd_chain)
F_137 ( exp , L_77 , V_238 ) ;
F_14 ( & V_245 ) ;
}
void F_148 ( struct V_1 * V_2 )
{
int V_246 = 2 ;
F_4 ( F_77 ( & V_2 -> V_145 ) ) ;
F_11 ( & V_2 -> V_55 ) ;
while ( ! F_77 ( & V_2 -> V_149 ) ) {
F_14 ( & V_2 -> V_55 ) ;
F_149 ( V_247 ) ;
F_150 ( F_151 ( V_246 ) ) ;
if ( V_246 > 5 && F_152 ( V_246 ) ) {
F_96 ( L_78 ,
V_2 -> V_56 , V_246 ,
F_56 ( & V_2 -> V_73 ) ) ;
F_147 ( V_2 , 1 ) ;
}
V_246 *= 2 ;
F_11 ( & V_2 -> V_55 ) ;
}
F_14 ( & V_2 -> V_55 ) ;
}
void F_153 ( void )
{
struct V_93 * V_161 ;
struct V_95 * V_98 ;
do {
F_11 ( & V_245 ) ;
V_161 = NULL ;
if ( ! F_77 ( & V_248 ) ) {
V_161 = F_13 ( V_248 . V_79 ,
struct V_93 ,
V_162 ) ;
F_104 ( & V_161 -> V_162 ) ;
}
V_98 = NULL ;
if ( ! F_77 ( & V_249 ) ) {
V_98 = F_13 ( V_249 . V_79 ,
struct V_95 ,
V_112 ) ;
F_104 ( & V_98 -> V_112 ) ;
}
F_14 ( & V_245 ) ;
if ( V_161 != NULL ) {
F_105 ( V_161 ) ;
F_11 ( & V_245 ) ;
V_250 -- ;
F_14 ( & V_245 ) ;
}
if ( V_98 != NULL ) {
F_74 ( V_98 ) ;
F_11 ( & V_245 ) ;
V_250 -- ;
F_14 ( & V_245 ) ;
}
F_154 () ;
} while ( V_161 != NULL || V_98 != NULL );
}
static int F_155 ( void * V_251 )
{
int V_32 ;
F_11 ( & V_245 ) ;
V_32 = ( V_250 == 0 ) &&
! F_156 ( V_252 , & V_253 ) ;
F_14 ( & V_245 ) ;
return V_32 ;
}
static void F_86 ( struct V_95 * exp ) {
F_11 ( & exp -> V_101 -> V_55 ) ;
F_4 ( ! F_77 ( & exp -> V_112 ) ) ;
F_104 ( & exp -> V_112 ) ;
F_14 ( & exp -> V_101 -> V_55 ) ;
F_11 ( & V_245 ) ;
V_250 ++ ;
F_31 ( & exp -> V_112 , & V_249 ) ;
F_14 ( & V_245 ) ;
F_157 () ;
}
static void F_109 ( struct V_93 * V_150 ) {
F_4 ( V_150 -> V_159 == NULL ) ;
F_4 ( V_150 -> V_254 == NULL ) ;
F_11 ( & V_245 ) ;
F_4 ( F_77 ( & V_150 -> V_162 ) ) ;
V_250 ++ ;
F_31 ( & V_150 -> V_162 , & V_248 ) ;
F_14 ( & V_245 ) ;
F_157 () ;
}
static void F_157 ( void )
{
F_158 ( & V_255 ) ;
}
static int F_159 ( void )
{
int V_32 ;
F_4 ( ! F_156 ( V_252 , & V_253 ) ) ;
F_11 ( & V_245 ) ;
V_32 = ( V_250 == 0 ) ;
F_14 ( & V_245 ) ;
return V_32 ;
}
void F_160 ( void )
{
struct V_256 V_257 = { 0 } ;
if ( V_258 == F_161 () )
return;
F_162 ( V_255 , F_159 () , & V_257 ) ;
}
static int F_163 ( void * V_259 )
{
F_164 () ;
F_165 ( & V_260 ) ;
V_258 = F_161 () ;
while ( ! F_156 ( V_252 , & V_253 ) ) {
struct V_256 V_257 = { 0 } ;
F_162 ( V_255 ,
! F_155 ( NULL ) , & V_257 ) ;
F_153 () ;
F_166 ( & V_255 ) ;
}
F_165 ( & V_261 ) ;
return 0 ;
}
int F_167 ( void )
{
struct V_262 * V_263 ;
F_89 ( & V_248 ) ;
F_89 ( & V_249 ) ;
F_25 ( & V_245 ) ;
F_168 ( & V_260 ) ;
F_168 ( & V_261 ) ;
F_115 ( & V_255 ) ;
V_258 = 0 ;
V_263 = F_169 ( F_163 , NULL , L_79 ) ;
if ( F_44 ( V_263 ) )
return F_28 ( V_263 ) ;
F_170 ( & V_260 ) ;
return 0 ;
}
void F_171 ( void )
{
F_172 ( V_252 , & V_253 ) ;
F_157 () ;
F_170 ( & V_261 ) ;
}
int F_173 ( int V_264 )
{
return sizeof( struct V_265 ) + V_264 ;
}
struct V_265 * F_174 ( void * V_266 )
{
struct V_265 * V_267 = ( (struct V_265 * ) V_266 ) - 1 ;
F_4 ( V_267 -> V_268 == V_269 ) ;
return V_267 ;
}
int F_175 ( void * V_266 )
{
struct V_265 * V_270 = ( (struct V_265 * ) V_266 ) - 1 ;
if ( V_270 -> V_268 == V_269 )
return 1 ;
else
return 0 ;
}
void * F_176 ( int V_264 , int V_271 , int type )
{
struct V_265 * V_267 ;
int V_272 = F_173 ( V_264 ) ;
V_267 = F_24 ( V_272 , V_4 ) ;
if ( V_267 == NULL )
return F_39 ( - V_36 ) ;
V_267 -> V_268 = V_269 ;
V_267 -> V_273 = V_271 ;
V_267 -> V_274 = type ;
V_267 -> V_275 = V_272 ;
return ( void * ) ( V_267 + 1 ) ;
}
inline void F_177 ( void * V_266 , int V_264 )
{
struct V_265 * V_267 = F_174 ( V_266 ) ;
F_33 ( V_267 ) ;
}
