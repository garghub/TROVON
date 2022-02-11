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
struct V_30 * V_31 , const char * V_11 ,
struct V_32 * V_33 )
{
struct V_10 * type ;
int V_34 = 0 ;
V_35 ;
F_4 ( F_23 ( V_11 , V_36 ) < V_36 ) ;
if ( F_10 ( V_11 ) ) {
F_17 ( V_37 , L_8 , V_11 ) ;
RETURN ( - V_38 ) ;
}
V_34 = - V_39 ;
F_24 ( type , sizeof( * type ) ) ;
if ( type == NULL )
RETURN ( V_34 ) ;
F_25 ( type -> V_25 ) ;
F_25 ( type -> V_40 ) ;
F_24 ( type -> V_16 , strlen ( V_11 ) + 1 ) ;
if ( type -> V_25 == NULL ||
type -> V_40 == NULL ||
type -> V_16 == NULL )
GOTO ( V_41 , V_34 ) ;
* ( type -> V_25 ) = * V_28 ;
if ( V_29 )
* ( type -> V_40 ) = * V_29 ;
strcpy ( type -> V_16 , V_11 ) ;
F_26 ( & type -> V_23 ) ;
#ifdef F_27
type -> V_42 = F_28 ( type -> V_16 , V_43 ,
V_31 , type ) ;
if ( F_29 ( type -> V_42 ) ) {
V_34 = F_30 ( type -> V_42 ) ;
type -> V_42 = NULL ;
GOTO ( V_41 , V_34 ) ;
}
#endif
if ( V_33 != NULL ) {
type -> V_44 = V_33 ;
V_34 = F_31 ( V_33 ) ;
if ( V_34 != 0 )
GOTO ( V_41 , V_34 ) ;
}
F_11 ( & V_14 ) ;
F_32 ( & type -> V_15 , & V_45 ) ;
F_14 ( & V_14 ) ;
RETURN ( 0 ) ;
V_41:
if ( type -> V_16 != NULL )
F_33 ( type -> V_16 , strlen ( V_11 ) + 1 ) ;
if ( type -> V_40 != NULL )
F_34 ( type -> V_40 ) ;
if ( type -> V_25 != NULL )
F_34 ( type -> V_25 ) ;
F_33 ( type , sizeof( * type ) ) ;
RETURN ( V_34 ) ;
}
int F_35 ( const char * V_11 )
{
struct V_10 * type = F_10 ( V_11 ) ;
V_35 ;
if ( ! type ) {
F_6 ( L_9 ) ;
RETURN ( - V_46 ) ;
}
if ( type -> V_24 ) {
F_6 ( L_10 , V_11 , type -> V_24 ) ;
F_34 ( type -> V_25 ) ;
F_34 ( type -> V_40 ) ;
RETURN ( - V_47 ) ;
}
if ( type -> V_42 ) {
F_36 ( & type -> V_42 ) ;
}
if ( type -> V_44 )
F_37 ( type -> V_44 ) ;
F_11 ( & V_14 ) ;
F_38 ( & type -> V_15 ) ;
F_14 ( & V_14 ) ;
F_33 ( type -> V_16 , strlen ( V_11 ) + 1 ) ;
if ( type -> V_25 != NULL )
F_34 ( type -> V_25 ) ;
if ( type -> V_40 != NULL )
F_34 ( type -> V_40 ) ;
F_33 ( type , sizeof( * type ) ) ;
RETURN ( 0 ) ;
}
struct V_1 * F_39 ( const char * V_48 , const char * V_11 )
{
struct V_1 * V_49 = NULL ;
struct V_1 * V_50 ;
struct V_10 * type = NULL ;
int V_51 ;
int V_52 = 0 ;
V_35 ;
if ( strlen ( V_11 ) >= V_53 ) {
F_6 ( L_11 , V_53 ) ;
RETURN ( F_40 ( - V_46 ) ) ;
}
type = F_15 ( V_48 ) ;
if ( type == NULL ) {
F_6 ( L_12 , V_48 ) ;
RETURN ( F_40 ( - V_54 ) ) ;
}
V_50 = F_1 () ;
if ( V_50 == NULL )
GOTO ( V_55 , V_49 = F_40 ( - V_39 ) ) ;
F_4 ( V_50 -> V_5 == V_6 ) ;
F_41 ( & V_56 ) ;
for ( V_51 = 0 ; V_51 < F_42 () ; V_51 ++ ) {
struct V_1 * V_2 = F_43 ( V_51 ) ;
if ( V_2 && ( strcmp ( V_11 , V_2 -> V_57 ) == 0 ) ) {
F_6 ( L_13 ,
V_11 , V_51 ) ;
if ( V_49 ) {
F_5 ( V_49 -> V_5 == V_6 ,
L_14 , V_49 ,
V_49 -> V_5 , V_6 ) ;
F_5 ( V_49 -> V_58 == V_52 ,
L_15 , V_49 ,
V_49 -> V_58 , V_52 ) ;
V_59 [ V_49 -> V_58 ] = NULL ;
V_49 -> V_57 [ 0 ] = '\0' ;
}
V_49 = F_40 ( - V_38 ) ;
break;
}
if ( ! V_49 && ! V_2 ) {
V_49 = V_50 ;
V_49 -> V_58 = V_51 ;
V_52 = V_51 ;
V_49 -> V_10 = type ;
strncpy ( V_49 -> V_57 , V_11 ,
sizeof( V_49 -> V_57 ) - 1 ) ;
V_59 [ V_51 ] = V_49 ;
}
}
F_44 ( & V_56 ) ;
if ( V_49 == NULL && V_51 >= F_42 () ) {
F_6 ( L_16 ,
F_42 () ) ;
GOTO ( V_60 , V_49 = F_40 ( - V_61 ) ) ;
}
if ( F_29 ( V_49 ) )
GOTO ( V_60 , V_49 ) ;
F_17 ( V_37 , L_17 ,
V_49 -> V_57 , V_49 ) ;
RETURN ( V_49 ) ;
V_60:
F_3 ( V_50 ) ;
V_55:
F_20 ( type ) ;
return V_49 ;
}
void F_45 ( struct V_1 * V_2 )
{
struct V_10 * V_10 = V_2 -> V_10 ;
F_5 ( V_2 -> V_5 == V_6 , L_14 ,
V_2 , V_2 -> V_5 , V_6 ) ;
F_5 ( V_2 == V_59 [ V_2 -> V_58 ] , L_18 ,
V_2 , V_2 -> V_58 , V_59 [ V_2 -> V_58 ] ) ;
F_4 ( V_10 != NULL ) ;
F_17 ( V_22 , L_19 ,
V_2 -> V_57 , V_2 -> V_58 , V_2 -> V_10 -> V_16 ) ;
F_41 ( & V_56 ) ;
V_59 [ V_2 -> V_58 ] = NULL ;
F_44 ( & V_56 ) ;
F_3 ( V_2 ) ;
F_20 ( V_10 ) ;
}
int F_46 ( const char * V_11 )
{
int V_51 ;
if ( ! V_11 )
return - 1 ;
F_47 ( & V_56 ) ;
for ( V_51 = 0 ; V_51 < F_42 () ; V_51 ++ ) {
struct V_1 * V_2 = F_43 ( V_51 ) ;
if ( V_2 && strcmp ( V_11 , V_2 -> V_57 ) == 0 ) {
F_4 ( V_2 -> V_5 == V_6 ) ;
if ( V_2 -> V_62 ) {
F_48 ( & V_56 ) ;
return V_51 ;
}
break;
}
}
F_48 ( & V_56 ) ;
return - 1 ;
}
struct V_1 * F_49 ( const char * V_11 )
{
int V_63 = F_46 ( V_11 ) ;
if ( V_63 < 0 || V_63 > F_42 () )
return NULL ;
return F_43 ( V_63 ) ;
}
int F_50 ( struct V_64 * V_65 )
{
int V_51 ;
F_47 ( & V_56 ) ;
for ( V_51 = 0 ; V_51 < F_42 () ; V_51 ++ ) {
struct V_1 * V_2 = F_43 ( V_51 ) ;
if ( V_2 && F_51 ( V_65 , & V_2 -> V_64 ) ) {
F_4 ( V_2 -> V_5 == V_6 ) ;
F_48 ( & V_56 ) ;
return V_51 ;
}
}
F_48 ( & V_56 ) ;
return - 1 ;
}
struct V_1 * F_52 ( struct V_64 * V_65 )
{
int V_63 = F_50 ( V_65 ) ;
if ( V_63 < 0 )
return NULL ;
return F_43 ( V_63 ) ;
}
struct V_1 * F_43 ( int V_66 )
{
struct V_1 * V_2 = NULL ;
if ( V_66 < F_42 () ) {
V_2 = V_59 [ V_66 ] ;
if ( V_2 == NULL )
return NULL ;
F_5 ( V_2 -> V_5 == V_6 ,
L_14 ,
V_2 , V_2 -> V_5 , V_6 ) ;
F_5 ( V_2 -> V_58 == V_66 ,
L_20 ,
V_2 , V_2 -> V_58 , V_66 ) ;
}
return V_2 ;
}
int F_53 ( void )
{
int V_67 , V_68 = F_42 () , V_69 = 0 ;
F_47 ( & V_56 ) ;
for ( V_67 = 0 ; V_67 <= V_68 ; V_67 ++ ) {
struct V_1 * V_2 = F_43 ( V_67 ) ;
if ( V_2 != NULL )
V_69 ++ ;
}
F_48 ( & V_56 ) ;
return V_69 ;
}
void F_54 ( void )
{
char * V_70 ;
int V_51 ;
F_47 ( & V_56 ) ;
for ( V_51 = 0 ; V_51 < F_42 () ; V_51 ++ ) {
struct V_1 * V_2 = F_43 ( V_51 ) ;
if ( V_2 == NULL )
continue;
if ( V_2 -> V_71 )
V_70 = L_21 ;
else if ( V_2 -> V_72 )
V_70 = L_22 ;
else if ( V_2 -> V_62 )
V_70 = L_23 ;
else
V_70 = L_24 ;
F_55 ( V_73 , L_25 ,
V_51 , V_70 , V_2 -> V_10 -> V_16 ,
V_2 -> V_57 , V_2 -> V_64 . V_65 ,
F_56 ( & V_2 -> V_74 ) ) ;
}
F_48 ( & V_56 ) ;
return;
}
struct V_1 * F_57 ( struct V_64 * V_75 ,
const char * V_16 ,
struct V_64 * V_76 )
{
int V_51 ;
F_47 ( & V_56 ) ;
for ( V_51 = 0 ; V_51 < F_42 () ; V_51 ++ ) {
struct V_1 * V_2 = F_43 ( V_51 ) ;
if ( V_2 == NULL )
continue;
if ( ( strncmp ( V_2 -> V_10 -> V_16 , V_16 ,
strlen ( V_16 ) ) == 0 ) ) {
if ( F_51 ( V_75 ,
& V_2 -> V_77 . V_78 . V_79 ) &&
( ( V_76 ) ? F_51 ( V_76 ,
& V_2 -> V_64 ) : 1 ) ) {
F_48 ( & V_56 ) ;
return V_2 ;
}
}
}
F_48 ( & V_56 ) ;
return NULL ;
}
struct V_1 * F_58 ( struct V_64 * V_76 , int * V_80 )
{
int V_51 ;
if ( V_80 == NULL )
V_51 = 0 ;
else if ( * V_80 >= 0 && * V_80 < F_42 () )
V_51 = * V_80 ;
else
return NULL ;
F_47 ( & V_56 ) ;
for (; V_51 < F_42 () ; V_51 ++ ) {
struct V_1 * V_2 = F_43 ( V_51 ) ;
if ( V_2 == NULL )
continue;
if ( F_51 ( V_76 , & V_2 -> V_64 ) ) {
if ( V_80 != NULL )
* V_80 = V_51 + 1 ;
F_48 ( & V_56 ) ;
return V_2 ;
}
}
F_48 ( & V_56 ) ;
return NULL ;
}
int F_59 ( const char * V_81 , int V_82 )
{
struct V_1 * V_2 ;
const char * type ;
int V_51 , V_34 = 0 , V_83 ;
F_4 ( V_82 > 0 ) ;
F_47 ( & V_56 ) ;
for ( V_51 = 0 ; V_51 < F_42 () ; V_51 ++ ) {
V_2 = F_43 ( V_51 ) ;
if ( V_2 == NULL || V_2 -> V_72 == 0 || V_2 -> V_71 )
continue;
type = V_2 -> V_10 -> V_16 ;
if ( strcmp ( type , V_84 ) != 0 &&
strcmp ( type , V_85 ) != 0 &&
strcmp ( type , V_21 ) != 0 &&
strcmp ( type , V_86 ) != 0 )
continue;
if ( strncmp ( V_2 -> V_57 , V_81 , V_82 ) )
continue;
F_60 ( V_2 , V_87 , V_2 ) ;
F_48 ( & V_56 ) ;
V_83 = F_61 ( NULL , V_2 -> V_88 ,
sizeof( V_89 ) ,
V_89 , 0 , NULL , NULL ) ;
V_34 = V_34 ? V_34 : V_83 ;
F_62 ( V_2 , V_87 , V_2 ) ;
F_47 ( & V_56 ) ;
}
F_48 ( & V_56 ) ;
return V_34 ;
}
void F_63 ( void )
{
V_35 ;
if ( V_3 ) {
F_64 ( V_3 ) ;
V_3 = NULL ;
}
if ( V_90 ) {
F_64 ( V_90 ) ;
V_90 = NULL ;
}
if ( V_91 ) {
F_64 ( V_91 ) ;
V_91 = NULL ;
}
if ( V_92 ) {
F_64 ( V_92 ) ;
V_92 = NULL ;
}
EXIT ;
}
int F_65 ( void )
{
V_35 ;
F_4 ( V_3 == NULL ) ;
V_3 = F_66 ( L_26 ,
sizeof( struct V_1 ) ,
0 , 0 , NULL ) ;
if ( ! V_3 )
GOTO ( V_60 , - V_39 ) ;
F_4 ( V_90 == NULL ) ;
V_90 = F_66 ( L_27 , sizeof( struct V_93 ) ,
0 , 0 , NULL ) ;
if ( ! V_90 )
GOTO ( V_60 , - V_39 ) ;
F_4 ( V_91 == NULL ) ;
V_91 = F_66 ( L_28 ,
sizeof( struct V_94 ) ,
0 , 0 , NULL ) ;
if ( ! V_91 )
GOTO ( V_60 , - V_39 ) ;
F_4 ( V_92 == NULL ) ;
V_92 = F_66 ( L_29 ,
sizeof( struct V_95 ) , 0 , 0 , NULL ) ;
if ( ! V_92 )
GOTO ( V_60 , - V_39 ) ;
RETURN ( 0 ) ;
V_60:
F_63 () ;
RETURN ( - V_39 ) ;
}
struct V_96 * F_67 ( struct V_97 * V_98 )
{
struct V_96 * V_99 ;
V_35 ;
if ( ! V_98 ) {
F_17 ( V_100 , L_30 ) ;
RETURN ( NULL ) ;
}
if ( V_98 -> V_101 == - 1 ) {
F_17 ( V_100 , L_31 ) ;
RETURN ( NULL ) ;
}
F_17 ( V_22 , L_32 V_102 L_33 , V_98 -> V_101 ) ;
V_99 = F_68 ( V_98 -> V_101 ) ;
RETURN ( V_99 ) ;
}
struct V_1 * F_69 ( struct V_96 * exp )
{
if ( exp )
return exp -> V_103 ;
return NULL ;
}
struct V_1 * F_70 ( struct V_97 * V_98 )
{
struct V_96 * V_99 ;
V_99 = F_67 ( V_98 ) ;
if ( V_99 ) {
struct V_1 * V_2 = V_99 -> V_103 ;
F_71 ( V_99 ) ;
return V_2 ;
}
return NULL ;
}
struct V_94 * F_72 ( struct V_96 * exp )
{
struct V_1 * V_2 = exp -> V_103 ;
if ( V_2 == NULL )
return NULL ;
return V_2 -> V_77 . V_78 . V_104 ;
}
struct V_94 * F_73 ( struct V_97 * V_98 )
{
struct V_1 * V_2 = F_70 ( V_98 ) ;
if ( V_2 == NULL )
return NULL ;
return V_2 -> V_77 . V_78 . V_104 ;
}
static void F_74 ( struct V_96 * exp )
{
struct V_1 * V_2 = exp -> V_103 ;
V_35 ;
F_75 ( & exp -> V_105 ) ;
F_4 ( V_2 != NULL ) ;
F_17 ( V_37 , L_34 , exp ,
exp -> V_106 . V_65 , V_2 -> V_57 ) ;
if ( exp -> V_107 )
F_76 ( exp -> V_107 ) ;
F_4 ( F_77 ( & exp -> V_108 ) ) ;
F_4 ( F_77 ( & exp -> V_109 ) ) ;
F_4 ( F_77 ( & exp -> V_110 ) ) ;
F_4 ( F_77 ( & exp -> V_111 ) ) ;
F_78 ( exp ) ;
F_62 ( V_2 , L_35 , exp ) ;
F_79 ( exp , sizeof( * exp ) , & exp -> V_112 ) ;
EXIT ;
}
static void F_80 ( void * V_99 )
{
F_81 ( V_99 ) ;
}
struct V_96 * F_81 ( struct V_96 * exp )
{
F_82 ( & exp -> V_105 ) ;
F_17 ( V_22 , L_36 , exp ,
F_56 ( & exp -> V_105 ) ) ;
return exp ;
}
void F_71 ( struct V_96 * exp )
{
F_4 ( exp != NULL ) ;
F_83 ( & exp -> V_105 , 0 , V_113 ) ;
F_17 ( V_22 , L_37 , exp ,
F_56 ( & exp -> V_105 ) - 1 ) ;
if ( F_84 ( & exp -> V_105 ) ) {
F_4 ( ! F_77 ( & exp -> V_114 ) ) ;
F_17 ( V_37 , L_38 ,
exp , exp -> V_106 . V_65 ) ;
F_85 ( exp ) ;
F_86 ( exp ) ;
}
}
struct V_96 * F_87 ( struct V_1 * V_2 ,
struct V_64 * V_115 )
{
struct V_96 * V_99 ;
T_1 * V_116 = NULL ;
int V_34 = 0 ;
V_35 ;
F_25 ( V_99 ) ;
if ( ! V_99 )
return F_40 ( - V_39 ) ;
V_99 -> V_117 = 0 ;
V_99 -> V_118 = NULL ;
V_99 -> V_119 = NULL ;
F_88 ( & V_99 -> V_105 , 2 ) ;
F_88 ( & V_99 -> V_120 , 0 ) ;
F_88 ( & V_99 -> V_121 , 0 ) ;
F_88 ( & V_99 -> V_122 , 0 ) ;
#if V_123
F_89 ( & V_99 -> V_124 ) ;
F_26 ( & V_99 -> V_125 ) ;
#endif
F_88 ( & V_99 -> V_126 , 0 ) ;
V_99 -> V_103 = V_2 ;
F_89 ( & V_99 -> V_108 ) ;
F_26 ( & V_99 -> V_127 ) ;
F_89 ( & V_99 -> V_109 ) ;
F_89 ( & V_99 -> V_110 ) ;
F_89 ( & V_99 -> V_112 . V_128 ) ;
F_89 ( & V_99 -> V_111 ) ;
F_90 ( & V_99 -> V_112 , & V_129 ) ;
V_99 -> V_130 = F_91 () ;
F_26 ( & V_99 -> V_131 ) ;
F_26 ( & V_99 -> V_132 ) ;
F_92 ( & V_99 -> V_133 ) ;
F_92 ( & V_99 -> V_134 ) ;
F_26 ( & V_99 -> V_135 ) ;
F_89 ( & V_99 -> V_136 ) ;
V_99 -> V_137 = V_138 ;
V_99 -> V_139 . V_140 = V_141 ;
V_99 -> V_106 = * V_115 ;
F_93 ( V_99 ) ;
F_11 ( & V_2 -> V_56 ) ;
if ( V_2 -> V_71 )
GOTO ( V_142 , V_34 = - V_54 ) ;
V_116 = F_94 ( V_2 -> V_143 ) ;
if ( V_116 == NULL )
GOTO ( V_142 , V_34 = - V_54 ) ;
F_14 ( & V_2 -> V_56 ) ;
if ( ! F_51 ( V_115 , & V_2 -> V_64 ) ) {
V_34 = F_95 ( V_116 , V_115 , & V_99 -> V_133 ) ;
if ( V_34 != 0 ) {
F_96 ( L_39 ,
V_2 -> V_57 , V_115 -> V_65 , V_34 ) ;
GOTO ( V_144 , V_34 = - V_145 ) ;
}
}
F_11 ( & V_2 -> V_56 ) ;
if ( V_2 -> V_71 ) {
F_97 ( V_116 , V_115 , & V_99 -> V_133 ) ;
GOTO ( V_142 , V_34 = - V_54 ) ;
}
F_60 ( V_2 , L_35 , V_99 ) ;
F_32 ( & V_99 -> V_114 , & V_99 -> V_103 -> V_146 ) ;
F_98 ( & V_99 -> V_147 ,
& V_99 -> V_103 -> V_148 ) ;
V_99 -> V_103 -> V_149 ++ ;
F_14 ( & V_2 -> V_56 ) ;
F_99 ( V_116 ) ;
RETURN ( V_99 ) ;
V_142:
F_14 ( & V_2 -> V_56 ) ;
V_144:
if ( V_116 )
F_99 ( V_116 ) ;
F_100 ( & V_99 -> V_112 ) ;
F_4 ( F_101 ( & V_99 -> V_133 ) ) ;
F_78 ( V_99 ) ;
F_34 ( V_99 ) ;
return F_40 ( V_34 ) ;
}
void F_102 ( struct V_96 * exp )
{
F_100 ( & exp -> V_112 ) ;
F_11 ( & exp -> V_103 -> V_56 ) ;
if ( ! F_101 ( & exp -> V_133 ) )
F_97 ( exp -> V_103 -> V_143 ,
& exp -> V_106 ,
& exp -> V_133 ) ;
F_103 ( & exp -> V_114 , & exp -> V_103 -> V_150 ) ;
F_104 ( & exp -> V_147 ) ;
exp -> V_103 -> V_149 -- ;
F_14 ( & exp -> V_103 -> V_56 ) ;
F_71 ( exp ) ;
}
void F_105 ( struct V_94 * V_151 )
{
V_35 ;
F_17 ( V_37 , L_40 , V_151 ,
V_151 -> V_152 -> V_57 ) ;
F_75 ( & V_151 -> V_153 ) ;
F_76 ( V_151 -> V_154 ) ;
while ( ! F_77 ( & V_151 -> V_155 ) ) {
struct V_156 * V_157 ;
V_157 = F_13 ( V_151 -> V_155 . V_80 ,
struct V_156 , V_158 ) ;
F_104 ( & V_157 -> V_158 ) ;
F_76 ( V_157 -> V_159 ) ;
F_33 ( V_157 , sizeof( * V_157 ) ) ;
}
F_4 ( V_151 -> V_160 == NULL ) ;
F_62 ( V_151 -> V_152 , L_41 , V_151 ) ;
F_79 ( V_151 , sizeof( * V_151 ) , & V_151 -> V_161 ) ;
EXIT ;
}
static void F_106 ( void * V_162 )
{
F_107 ( V_162 ) ;
}
struct V_94 * F_107 ( struct V_94 * V_162 )
{
F_82 ( & V_162 -> V_153 ) ;
F_17 ( V_22 , L_42 , V_162 ,
F_56 ( & V_162 -> V_153 ) ,
V_162 -> V_152 -> V_57 ) ;
return V_162 ;
}
void F_108 ( struct V_94 * V_151 )
{
V_35 ;
F_4 ( F_77 ( & V_151 -> V_163 ) ) ;
F_83 ( & V_151 -> V_153 , 0 , V_113 ) ;
F_17 ( V_22 , L_42 , V_151 ,
F_56 ( & V_151 -> V_153 ) - 1 ,
V_151 -> V_152 -> V_57 ) ;
if ( F_84 ( & V_151 -> V_153 ) ) {
F_17 ( V_22 , L_43 , V_151 ) ;
F_109 ( V_151 ) ;
}
F_110 ( & V_151 -> V_153 , 0 , V_113 ) ;
EXIT ;
}
static void F_111 ( struct V_164 * V_165 ) {
int V_51 ;
F_112 ( & V_165 -> V_166 , 0 , 0 ) ;
for ( V_51 = 0 ; V_51 < V_167 ; V_51 ++ ) {
F_112 ( & V_165 -> V_168 [ V_51 ] , V_169 ,
V_170 ) ;
}
}
struct V_94 * F_113 ( struct V_1 * V_2 )
{
struct V_94 * V_151 ;
F_24 ( V_151 , sizeof( * V_151 ) ) ;
if ( V_151 == NULL )
return NULL ;
F_89 ( & V_151 -> V_171 ) ;
F_89 ( & V_151 -> V_163 ) ;
F_89 ( & V_151 -> V_172 ) ;
F_89 ( & V_151 -> V_173 ) ;
F_89 ( & V_151 -> V_174 ) ;
F_26 ( & V_151 -> V_175 ) ;
V_151 -> V_176 = 0 ;
V_151 -> V_177 = V_178 ;
V_151 -> V_152 = F_60 ( V_2 , L_41 , V_151 ) ;
F_114 ( & V_151 -> V_179 ) ;
F_115 ( & V_151 -> V_180 ) ;
F_88 ( & V_151 -> V_153 , 2 ) ;
F_88 ( & V_151 -> V_181 , 0 ) ;
F_88 ( & V_151 -> V_182 , 0 ) ;
F_88 ( & V_151 -> V_183 , 0 ) ;
F_88 ( & V_151 -> V_184 , 0 ) ;
F_89 ( & V_151 -> V_155 ) ;
F_89 ( & V_151 -> V_161 . V_128 ) ;
F_90 ( & V_151 -> V_161 , & V_185 ) ;
F_111 ( & V_151 -> V_164 ) ;
V_151 -> V_186 = V_187 ;
return V_151 ;
}
void F_116 ( struct V_94 * V_162 )
{
F_4 ( V_162 != NULL ) ;
F_4 ( V_162 != V_188 ) ;
F_100 ( & V_162 -> V_161 ) ;
F_11 ( & V_162 -> V_175 ) ;
V_162 -> V_189 ++ ;
F_14 ( & V_162 -> V_175 ) ;
F_108 ( V_162 ) ;
}
void F_117 ( struct V_96 * exp , struct V_190 * V_191 )
{
F_11 ( & exp -> V_125 ) ;
F_4 ( V_191 -> V_192 >= 0 ) ;
if ( V_191 -> V_193 != NULL &&
V_191 -> V_193 != exp ) {
F_96 ( L_44 ,
exp , V_191 , V_191 -> V_193 ) ;
}
if ( ( V_191 -> V_192 ++ ) == 0 ) {
F_32 ( & V_191 -> V_194 , & exp -> V_124 ) ;
V_191 -> V_193 = exp ;
}
F_17 ( V_22 , L_45 ,
V_191 , exp , V_191 -> V_192 ) ;
F_14 ( & exp -> V_125 ) ;
}
void F_118 ( struct V_96 * exp , struct V_190 * V_191 )
{
F_11 ( & exp -> V_125 ) ;
F_4 ( V_191 -> V_192 > 0 ) ;
if ( V_191 -> V_193 != exp ) {
F_96 ( L_46
L_47 ,
V_191 , V_191 -> V_193 , exp ) ;
}
if ( -- V_191 -> V_192 == 0 ) {
F_104 ( & V_191 -> V_194 ) ;
V_191 -> V_193 = NULL ;
}
F_17 ( V_22 , L_45 ,
V_191 , exp , V_191 -> V_192 ) ;
F_14 ( & exp -> V_125 ) ;
}
int F_119 ( struct V_97 * V_98 , struct V_1 * V_2 ,
struct V_64 * V_115 )
{
struct V_96 * V_99 ;
F_4 ( V_98 != NULL ) ;
F_4 ( V_2 != NULL ) ;
F_4 ( V_115 != NULL ) ;
V_35 ;
V_99 = F_87 ( V_2 , V_115 ) ;
if ( F_29 ( V_99 ) )
RETURN ( F_30 ( V_99 ) ) ;
V_98 -> V_101 = V_99 -> V_112 . V_195 ;
F_71 ( V_99 ) ;
F_17 ( V_37 , L_48 V_102 L_33 ,
V_115 -> V_65 , V_98 -> V_101 ) ;
RETURN ( 0 ) ;
}
void F_120 ( struct V_96 * exp )
{
struct V_1 * V_2 = exp -> V_103 ;
F_11 ( & V_2 -> V_196 ) ;
if ( exp -> V_197 )
V_2 -> V_198 -- ;
if ( V_2 -> V_199 ) {
if ( exp -> V_200 ) {
F_11 ( & exp -> V_131 ) ;
exp -> V_200 = 0 ;
F_14 ( & exp -> V_131 ) ;
F_121 ( & V_2 -> V_201 ) ;
F_122 ( & V_2 -> V_201 ) ;
}
if ( exp -> V_202 &&
( F_123 ( exp ) & V_203 ) == 0 )
exp -> V_103 -> V_204 ++ ;
}
F_14 ( & V_2 -> V_196 ) ;
if ( exp -> V_205 ) {
F_11 ( & exp -> V_131 ) ;
exp -> V_205 = 0 ;
F_14 ( & exp -> V_131 ) ;
F_4 ( F_56 ( & V_2 -> V_206 ) ) ;
F_122 ( & V_2 -> V_206 ) ;
}
if ( exp -> V_207 ) {
F_11 ( & exp -> V_131 ) ;
exp -> V_207 = 0 ;
F_14 ( & exp -> V_131 ) ;
F_4 ( F_56 ( & V_2 -> V_208 ) ) ;
F_122 ( & V_2 -> V_208 ) ;
}
}
int F_124 ( struct V_96 * V_99 )
{
int V_209 ;
V_35 ;
if ( V_99 == NULL ) {
F_125 ( L_49 , V_99 ) ;
RETURN ( - V_46 ) ;
}
F_11 ( & V_99 -> V_131 ) ;
V_209 = V_99 -> V_210 ;
V_99 -> V_210 = 1 ;
F_14 ( & V_99 -> V_131 ) ;
if ( V_209 ) {
F_4 ( F_101 ( & V_99 -> V_134 ) ) ;
GOTO ( V_211 , V_209 ) ;
}
F_17 ( V_37 , L_50 V_102 L_33 ,
V_99 -> V_112 . V_195 ) ;
if ( ! F_101 ( & V_99 -> V_134 ) )
F_97 ( V_99 -> V_103 -> V_212 ,
& V_99 -> V_107 -> V_213 . V_214 ,
& V_99 -> V_134 ) ;
F_120 ( V_99 ) ;
F_102 ( V_99 ) ;
V_211:
F_71 ( V_99 ) ;
RETURN ( 0 ) ;
}
int F_126 ( struct V_96 * exp )
{
if ( exp ) {
int V_215 ;
F_11 ( & exp -> V_131 ) ;
V_215 = ( exp -> V_117 > 0 ) ;
F_14 ( & exp -> V_131 ) ;
return V_215 ;
}
return 0 ;
}
static void F_127 ( struct V_12 * V_216 ,
enum V_217 V_218 )
{
int V_34 ;
struct V_96 * exp ;
V_35 ;
while ( ! F_77 ( V_216 ) ) {
exp = F_13 ( V_216 -> V_80 , struct V_96 ,
V_114 ) ;
F_81 ( exp ) ;
F_11 ( & exp -> V_131 ) ;
exp -> V_219 = V_218 ;
F_14 ( & exp -> V_131 ) ;
if ( F_51 ( & exp -> V_106 ,
& exp -> V_103 -> V_64 ) ) {
F_17 ( V_220 ,
L_51 ,
exp ) ;
F_104 ( & exp -> V_114 ) ;
F_71 ( exp ) ;
continue;
}
F_81 ( exp ) ;
F_17 ( V_220 , L_52
L_53 V_221 L_33 ,
exp -> V_103 -> V_57 , F_128 ( exp ) ,
exp , exp -> V_130 ) ;
V_34 = F_129 ( exp ) ;
F_17 ( V_220 , L_54 ,
F_128 ( exp ) , exp , V_34 ) ;
F_71 ( exp ) ;
}
EXIT ;
}
void F_130 ( struct V_1 * V_2 )
{
struct V_12 V_222 ;
V_35 ;
F_89 ( & V_222 ) ;
F_11 ( & V_2 -> V_56 ) ;
F_131 ( & V_2 -> V_146 , & V_222 ) ;
F_131 ( & V_2 -> V_223 , & V_222 ) ;
F_14 ( & V_2 -> V_56 ) ;
if ( ! F_77 ( & V_222 ) ) {
F_17 ( V_220 , L_55
L_56 , V_2 -> V_58 , V_2 ) ;
F_127 ( & V_222 ,
F_132 ( V_2 ) ) ;
} else
F_17 ( V_220 , L_57 ,
V_2 -> V_58 , V_2 ) ;
EXIT ;
}
void F_133 ( struct V_1 * V_2 ,
int (* F_134)( struct V_96 * ) )
{
struct V_12 V_222 ;
struct V_96 * exp , * V_224 ;
int V_225 = 0 ;
V_35 ;
F_89 ( & V_222 ) ;
F_11 ( & V_2 -> V_56 ) ;
F_135 (exp, n, &obd->obd_exports,
exp_obd_chain) {
if ( F_51 ( & exp -> V_106 ,
& exp -> V_103 -> V_64 ) )
continue;
if ( exp -> V_226 . V_227 == - 1 )
continue;
F_11 ( & exp -> V_131 ) ;
if ( exp -> V_202 || F_134 ( exp ) ) {
F_14 ( & exp -> V_131 ) ;
continue;
}
exp -> V_202 = 1 ;
F_14 ( & exp -> V_131 ) ;
F_103 ( & exp -> V_114 , & V_222 ) ;
V_225 ++ ;
F_17 ( V_220 , L_58 ,
V_2 -> V_57 , exp -> V_106 . V_65 ,
exp -> V_107 == NULL ? L_59 :
F_136 ( exp -> V_107 -> V_213 . V_214 ) ) ;
F_137 ( exp , L_60 , 0 ) ;
}
F_14 ( & V_2 -> V_56 ) ;
if ( V_225 )
F_96 ( L_61 ,
V_2 -> V_57 , V_225 ) ;
F_127 ( & V_222 , F_132 ( V_2 ) |
V_228 ) ;
EXIT ;
}
void F_138 ( struct V_96 * exp )
{
int V_34 , V_229 ;
F_11 ( & exp -> V_131 ) ;
V_229 = exp -> V_202 ;
exp -> V_202 = 1 ;
F_14 ( & exp -> V_131 ) ;
if ( V_229 ) {
F_17 ( V_220 , L_62 ,
exp , exp -> V_106 . V_65 ) ;
return;
}
F_17 ( V_220 , L_63 ,
exp , exp -> V_106 . V_65 ) ;
if ( V_230 )
F_139 () ;
F_81 ( exp ) ;
F_81 ( exp ) ;
V_34 = F_129 ( exp ) ;
if ( V_34 )
F_6 ( L_64 , exp , V_34 ) ;
else
F_17 ( V_220 , L_65 ,
exp , exp -> V_106 . V_65 ) ;
F_71 ( exp ) ;
}
char * F_128 ( struct V_96 * exp )
{
if ( exp -> V_107 != NULL )
return F_136 ( exp -> V_107 -> V_213 . V_214 ) ;
return L_66 ;
}
int F_140 ( struct V_1 * V_2 , const char * V_214 )
{
T_1 * V_231 ;
struct V_96 * V_232 = NULL ;
int V_233 = 0 ;
T_2 V_234 = F_141 ( ( char * ) V_214 ) ;
F_11 ( & V_2 -> V_56 ) ;
if ( V_2 -> V_71 ) {
F_14 ( & V_2 -> V_56 ) ;
return V_233 ;
}
V_231 = V_2 -> V_212 ;
F_94 ( V_231 ) ;
F_14 ( & V_2 -> V_56 ) ;
do {
V_232 = F_142 ( V_231 , & V_234 ) ;
if ( V_232 == NULL )
break;
F_5 ( V_232 -> V_107 -> V_213 . V_214 == V_234 ,
L_67 ,
F_128 ( V_232 ) ,
F_136 ( V_234 ) , V_214 ) ;
F_5 ( V_232 != V_2 -> V_88 ,
L_68 ) ;
V_233 ++ ;
F_96 ( L_69
L_70 , V_2 -> V_57 ,
F_143 ( & V_232 -> V_106 ) ,
F_128 ( V_232 ) ) ;
F_138 ( V_232 ) ;
F_71 ( V_232 ) ;
} while ( 1 );
F_99 ( V_231 ) ;
if ( ! V_233 )
F_17 ( V_220 , L_71 ,
V_2 -> V_57 , V_214 ) ;
return V_233 ;
}
int F_144 ( struct V_1 * V_2 , const char * V_65 )
{
T_1 * V_235 ;
struct V_96 * V_232 = NULL ;
struct V_64 V_236 ;
int V_233 = 0 ;
F_11 ( & V_2 -> V_56 ) ;
if ( V_2 -> V_71 ) {
F_14 ( & V_2 -> V_56 ) ;
return V_233 ;
}
V_235 = V_2 -> V_143 ;
F_94 ( V_235 ) ;
F_14 ( & V_2 -> V_56 ) ;
F_145 ( & V_236 , V_65 ) ;
if ( F_51 ( & V_236 , & V_2 -> V_64 ) ) {
F_6 ( L_72 , V_2 -> V_57 ) ;
F_99 ( V_235 ) ;
return V_233 ;
}
V_232 = F_142 ( V_235 , & V_236 ) ;
if ( V_232 == NULL ) {
F_6 ( L_73 ,
V_2 -> V_57 , V_65 ) ;
} else {
F_125 ( L_74 ,
V_2 -> V_57 , V_232 -> V_106 . V_65 ) ;
F_138 ( V_232 ) ;
F_71 ( V_232 ) ;
V_233 ++ ;
}
F_99 ( V_235 ) ;
return V_233 ;
}
static void F_137 ( struct V_96 * exp , const char * V_70 ,
int V_237 )
{
struct V_238 * V_239 ;
struct V_238 * V_240 = NULL ;
int V_241 = 0 ;
F_11 ( & exp -> V_131 ) ;
F_146 (rs, &exp->exp_outstanding_replies,
rs_exp_list) {
if ( V_241 == 0 )
V_240 = V_239 ;
V_241 ++ ;
}
F_14 ( & exp -> V_131 ) ;
F_17 ( V_220 , L_75 V_242 L_33 ,
exp -> V_103 -> V_57 , V_70 , exp , exp -> V_106 . V_65 ,
F_128 ( exp ) , F_56 ( & exp -> V_105 ) ,
F_56 ( & exp -> V_120 ) ,
F_56 ( & exp -> V_121 ) ,
F_56 ( & exp -> V_122 ) ,
exp -> V_210 , exp -> V_197 , exp -> V_202 ,
V_241 , V_240 , V_241 > 3 ? L_76 : L_77 ,
exp -> V_243 ) ;
#if V_123
if ( V_237 && V_244 != NULL )
V_244 ( exp ) ;
#endif
}
void F_147 ( struct V_1 * V_2 , int V_237 )
{
struct V_96 * exp ;
F_11 ( & V_2 -> V_56 ) ;
F_146 (exp, &obd->obd_exports, exp_obd_chain)
F_137 ( exp , L_78 , V_237 ) ;
F_146 (exp, &obd->obd_unlinked_exports, exp_obd_chain)
F_137 ( exp , L_79 , V_237 ) ;
F_146 (exp, &obd->obd_delayed_exports, exp_obd_chain)
F_137 ( exp , L_80 , V_237 ) ;
F_14 ( & V_2 -> V_56 ) ;
F_11 ( & V_245 ) ;
F_146 (exp, &obd_zombie_exports, exp_obd_chain)
F_137 ( exp , L_81 , V_237 ) ;
F_14 ( & V_245 ) ;
}
void F_148 ( struct V_1 * V_2 )
{
int V_246 = 2 ;
F_4 ( F_77 ( & V_2 -> V_146 ) ) ;
F_11 ( & V_2 -> V_56 ) ;
while ( ! F_77 ( & V_2 -> V_150 ) ) {
F_14 ( & V_2 -> V_56 ) ;
F_149 ( V_247 ,
F_150 ( V_246 ) ) ;
if ( V_246 > 5 && F_151 ( V_246 ) ) {
F_96 ( L_82
L_83
L_84 ,
V_2 -> V_57 , V_246 ,
F_56 ( & V_2 -> V_74 ) ) ;
F_147 ( V_2 , 1 ) ;
}
V_246 *= 2 ;
F_11 ( & V_2 -> V_56 ) ;
}
F_14 ( & V_2 -> V_56 ) ;
}
void F_152 ( void )
{
struct V_94 * V_162 ;
struct V_96 * V_99 ;
V_35 ;
do {
F_11 ( & V_245 ) ;
V_162 = NULL ;
if ( ! F_77 ( & V_248 ) ) {
V_162 = F_13 ( V_248 . V_80 ,
struct V_94 ,
V_163 ) ;
F_104 ( & V_162 -> V_163 ) ;
}
V_99 = NULL ;
if ( ! F_77 ( & V_249 ) ) {
V_99 = F_13 ( V_249 . V_80 ,
struct V_96 ,
V_114 ) ;
F_104 ( & V_99 -> V_114 ) ;
}
F_14 ( & V_245 ) ;
if ( V_162 != NULL ) {
F_105 ( V_162 ) ;
F_11 ( & V_245 ) ;
V_250 -- ;
F_14 ( & V_245 ) ;
}
if ( V_99 != NULL ) {
F_74 ( V_99 ) ;
F_11 ( & V_245 ) ;
V_250 -- ;
F_14 ( & V_245 ) ;
}
F_153 () ;
} while ( V_162 != NULL || V_99 != NULL );
EXIT ;
}
static int F_154 ( void * V_251 )
{
int V_34 ;
F_11 ( & V_245 ) ;
V_34 = ( V_250 == 0 ) &&
! F_155 ( V_252 , & V_253 ) ;
F_14 ( & V_245 ) ;
RETURN ( V_34 ) ;
}
static void F_86 ( struct V_96 * exp ) {
F_11 ( & exp -> V_103 -> V_56 ) ;
F_4 ( ! F_77 ( & exp -> V_114 ) ) ;
F_104 ( & exp -> V_114 ) ;
F_14 ( & exp -> V_103 -> V_56 ) ;
F_11 ( & V_245 ) ;
V_250 ++ ;
F_32 ( & exp -> V_114 , & V_249 ) ;
F_14 ( & V_245 ) ;
F_156 () ;
}
static void F_109 ( struct V_94 * V_151 ) {
F_4 ( V_151 -> V_160 == NULL ) ;
F_4 ( V_151 -> V_254 == NULL ) ;
F_11 ( & V_245 ) ;
F_4 ( F_77 ( & V_151 -> V_163 ) ) ;
V_250 ++ ;
F_32 ( & V_151 -> V_163 , & V_248 ) ;
F_14 ( & V_245 ) ;
F_156 () ;
}
static void F_156 ( void )
{
F_157 ( & V_255 ) ;
}
static int F_158 ( void )
{
int V_34 ;
F_4 ( ! F_155 ( V_252 , & V_253 ) ) ;
F_11 ( & V_245 ) ;
V_34 = ( V_250 == 0 ) ;
F_14 ( & V_245 ) ;
return V_34 ;
}
void F_159 ( void )
{
struct V_256 V_257 = { 0 } ;
if ( V_258 == F_160 () )
return;
F_161 ( V_255 , F_158 () , & V_257 ) ;
}
static int F_162 ( void * V_259 )
{
F_163 () ;
F_164 ( & V_260 ) ;
V_258 = F_160 () ;
while ( ! F_155 ( V_252 , & V_253 ) ) {
struct V_256 V_257 = { 0 } ;
F_161 ( V_255 ,
! F_154 ( NULL ) , & V_257 ) ;
F_152 () ;
F_165 ( & V_255 ) ;
}
F_164 ( & V_261 ) ;
RETURN ( 0 ) ;
}
int F_166 ( void )
{
T_3 * V_262 ;
F_89 ( & V_248 ) ;
F_89 ( & V_249 ) ;
F_26 ( & V_245 ) ;
F_167 ( & V_260 ) ;
F_167 ( & V_261 ) ;
F_115 ( & V_255 ) ;
V_258 = 0 ;
V_262 = F_168 ( F_162 , NULL , L_85 ) ;
if ( F_29 ( V_262 ) )
RETURN ( F_30 ( V_262 ) ) ;
F_169 ( & V_260 ) ;
RETURN ( 0 ) ;
}
void F_170 ( void )
{
F_171 ( V_252 , & V_253 ) ;
F_156 () ;
F_169 ( & V_261 ) ;
}
int F_172 ( int V_263 )
{
return sizeof( struct V_264 ) + V_263 ;
}
struct V_264 * F_173 ( void * V_265 )
{
struct V_264 * V_266 = ( (struct V_264 * ) V_265 ) - 1 ;
F_4 ( V_266 -> V_267 == V_268 ) ;
return V_266 ;
}
int F_174 ( void * V_265 )
{
struct V_264 * V_269 = ( (struct V_264 * ) V_265 ) - 1 ;
if ( V_269 -> V_267 == V_268 )
return 1 ;
else
return 0 ;
}
void * F_175 ( int V_263 , int V_270 , int type )
{
struct V_264 * V_266 ;
int V_271 = F_172 ( V_263 ) ;
F_24 ( V_266 , V_271 ) ;
if ( V_266 == NULL )
return F_40 ( - V_39 ) ;
V_266 -> V_267 = V_268 ;
V_266 -> V_272 = V_270 ;
V_266 -> V_273 = type ;
V_266 -> V_274 = V_271 ;
return ( void * ) ( V_266 + 1 ) ;
}
inline void F_176 ( void * V_265 , int V_263 )
{
struct V_264 * V_266 = F_173 ( V_265 ) ;
F_33 ( V_266 , F_172 ( V_263 ) ) ;
}
