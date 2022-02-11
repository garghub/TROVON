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
F_4 ( F_23 ( V_11 , V_35 ) < V_35 ) ;
if ( F_10 ( V_11 ) ) {
F_17 ( V_36 , L_8 , V_11 ) ;
return - V_37 ;
}
V_34 = - V_38 ;
F_24 ( type , sizeof( * type ) ) ;
if ( type == NULL )
return V_34 ;
F_25 ( type -> V_25 ) ;
F_25 ( type -> V_39 ) ;
F_24 ( type -> V_16 , strlen ( V_11 ) + 1 ) ;
if ( type -> V_25 == NULL ||
type -> V_39 == NULL ||
type -> V_16 == NULL )
GOTO ( V_40 , V_34 ) ;
* ( type -> V_25 ) = * V_28 ;
if ( V_29 )
* ( type -> V_39 ) = * V_29 ;
strcpy ( type -> V_16 , V_11 ) ;
F_26 ( & type -> V_23 ) ;
#ifdef F_27
type -> V_41 = F_28 ( type -> V_16 , V_42 ,
V_31 , type ) ;
if ( F_29 ( type -> V_41 ) ) {
V_34 = F_30 ( type -> V_41 ) ;
type -> V_41 = NULL ;
GOTO ( V_40 , V_34 ) ;
}
#endif
if ( V_33 != NULL ) {
type -> V_43 = V_33 ;
V_34 = F_31 ( V_33 ) ;
if ( V_34 != 0 )
GOTO ( V_40 , V_34 ) ;
}
F_11 ( & V_14 ) ;
F_32 ( & type -> V_15 , & V_44 ) ;
F_14 ( & V_14 ) ;
return 0 ;
V_40:
if ( type -> V_16 != NULL )
F_33 ( type -> V_16 , strlen ( V_11 ) + 1 ) ;
if ( type -> V_39 != NULL )
F_34 ( type -> V_39 ) ;
if ( type -> V_25 != NULL )
F_34 ( type -> V_25 ) ;
F_33 ( type , sizeof( * type ) ) ;
return V_34 ;
}
int F_35 ( const char * V_11 )
{
struct V_10 * type = F_10 ( V_11 ) ;
if ( ! type ) {
F_6 ( L_9 ) ;
return - V_45 ;
}
if ( type -> V_24 ) {
F_6 ( L_10 , V_11 , type -> V_24 ) ;
F_34 ( type -> V_25 ) ;
F_34 ( type -> V_39 ) ;
return - V_46 ;
}
if ( type -> V_41 ) {
F_36 ( & type -> V_41 ) ;
}
if ( type -> V_43 )
F_37 ( type -> V_43 ) ;
F_11 ( & V_14 ) ;
F_38 ( & type -> V_15 ) ;
F_14 ( & V_14 ) ;
F_33 ( type -> V_16 , strlen ( V_11 ) + 1 ) ;
if ( type -> V_25 != NULL )
F_34 ( type -> V_25 ) ;
if ( type -> V_39 != NULL )
F_34 ( type -> V_39 ) ;
F_33 ( type , sizeof( * type ) ) ;
return 0 ;
}
struct V_1 * F_39 ( const char * V_47 , const char * V_11 )
{
struct V_1 * V_48 = NULL ;
struct V_1 * V_49 ;
struct V_10 * type = NULL ;
int V_50 ;
int V_51 = 0 ;
if ( strlen ( V_11 ) >= V_52 ) {
F_6 ( L_11 , V_52 ) ;
return F_40 ( - V_45 ) ;
}
type = F_15 ( V_47 ) ;
if ( type == NULL ) {
F_6 ( L_12 , V_47 ) ;
return F_40 ( - V_53 ) ;
}
V_49 = F_1 () ;
if ( V_49 == NULL )
GOTO ( V_54 , V_48 = F_40 ( - V_38 ) ) ;
F_4 ( V_49 -> V_5 == V_6 ) ;
F_41 ( & V_55 ) ;
for ( V_50 = 0 ; V_50 < F_42 () ; V_50 ++ ) {
struct V_1 * V_2 = F_43 ( V_50 ) ;
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
V_48 = F_40 ( - V_37 ) ;
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
F_44 ( & V_55 ) ;
if ( V_48 == NULL && V_50 >= F_42 () ) {
F_6 ( L_16 ,
F_42 () ) ;
GOTO ( V_59 , V_48 = F_40 ( - V_60 ) ) ;
}
if ( F_29 ( V_48 ) )
GOTO ( V_59 , V_48 ) ;
F_17 ( V_36 , L_17 ,
V_48 -> V_56 , V_48 ) ;
return V_48 ;
V_59:
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
F_41 ( & V_55 ) ;
V_58 [ V_2 -> V_57 ] = NULL ;
F_44 ( & V_55 ) ;
F_3 ( V_2 ) ;
F_20 ( V_10 ) ;
}
int F_46 ( const char * V_11 )
{
int V_50 ;
if ( ! V_11 )
return - 1 ;
F_47 ( & V_55 ) ;
for ( V_50 = 0 ; V_50 < F_42 () ; V_50 ++ ) {
struct V_1 * V_2 = F_43 ( V_50 ) ;
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
if ( V_62 < 0 || V_62 > F_42 () )
return NULL ;
return F_43 ( V_62 ) ;
}
int F_50 ( struct V_63 * V_64 )
{
int V_50 ;
F_47 ( & V_55 ) ;
for ( V_50 = 0 ; V_50 < F_42 () ; V_50 ++ ) {
struct V_1 * V_2 = F_43 ( V_50 ) ;
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
return F_43 ( V_62 ) ;
}
struct V_1 * F_43 ( int V_65 )
{
struct V_1 * V_2 = NULL ;
if ( V_65 < F_42 () ) {
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
int V_66 , V_67 = F_42 () , V_68 = 0 ;
F_47 ( & V_55 ) ;
for ( V_66 = 0 ; V_66 <= V_67 ; V_66 ++ ) {
struct V_1 * V_2 = F_43 ( V_66 ) ;
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
for ( V_50 = 0 ; V_50 < F_42 () ; V_50 ++ ) {
struct V_1 * V_2 = F_43 ( V_50 ) ;
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
for ( V_50 = 0 ; V_50 < F_42 () ; V_50 ++ ) {
struct V_1 * V_2 = F_43 ( V_50 ) ;
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
else if ( * V_79 >= 0 && * V_79 < F_42 () )
V_50 = * V_79 ;
else
return NULL ;
F_47 ( & V_55 ) ;
for (; V_50 < F_42 () ; V_50 ++ ) {
struct V_1 * V_2 = F_43 ( V_50 ) ;
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
int V_50 , V_34 = 0 , V_82 ;
F_4 ( V_81 > 0 ) ;
F_47 ( & V_55 ) ;
for ( V_50 = 0 ; V_50 < F_42 () ; V_50 ++ ) {
V_2 = F_43 ( V_50 ) ;
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
V_34 = V_34 ? V_34 : V_82 ;
F_62 ( V_2 , V_86 , V_2 ) ;
F_47 ( & V_55 ) ;
}
F_48 ( & V_55 ) ;
return V_34 ;
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
GOTO ( V_59 , - V_38 ) ;
F_4 ( V_89 == NULL ) ;
V_89 = F_66 ( L_27 , sizeof( struct V_92 ) ,
0 , 0 , NULL ) ;
if ( ! V_89 )
GOTO ( V_59 , - V_38 ) ;
F_4 ( V_90 == NULL ) ;
V_90 = F_66 ( L_28 ,
sizeof( struct V_93 ) ,
0 , 0 , NULL ) ;
if ( ! V_90 )
GOTO ( V_59 , - V_38 ) ;
F_4 ( V_91 == NULL ) ;
V_91 = F_66 ( L_29 ,
sizeof( struct V_94 ) , 0 , 0 , NULL ) ;
if ( ! V_91 )
GOTO ( V_59 , - V_38 ) ;
return 0 ;
V_59:
F_63 () ;
return - V_38 ;
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
F_17 ( V_22 , L_32 V_101 L_33 , V_97 -> V_100 ) ;
V_98 = F_68 ( V_97 -> V_100 ) ;
return V_98 ;
}
struct V_1 * F_69 ( struct V_95 * exp )
{
if ( exp )
return exp -> V_102 ;
return NULL ;
}
struct V_1 * F_70 ( struct V_96 * V_97 )
{
struct V_95 * V_98 ;
V_98 = F_67 ( V_97 ) ;
if ( V_98 ) {
struct V_1 * V_2 = V_98 -> V_102 ;
F_71 ( V_98 ) ;
return V_2 ;
}
return NULL ;
}
struct V_93 * F_72 ( struct V_95 * exp )
{
struct V_1 * V_2 = exp -> V_102 ;
if ( V_2 == NULL )
return NULL ;
return V_2 -> V_76 . V_77 . V_103 ;
}
struct V_93 * F_73 ( struct V_96 * V_97 )
{
struct V_1 * V_2 = F_70 ( V_97 ) ;
if ( V_2 == NULL )
return NULL ;
return V_2 -> V_76 . V_77 . V_103 ;
}
static void F_74 ( struct V_95 * exp )
{
struct V_1 * V_2 = exp -> V_102 ;
F_75 ( & exp -> V_104 ) ;
F_4 ( V_2 != NULL ) ;
F_17 ( V_36 , L_34 , exp ,
exp -> V_105 . V_64 , V_2 -> V_56 ) ;
if ( exp -> V_106 )
F_76 ( exp -> V_106 ) ;
F_4 ( F_77 ( & exp -> V_107 ) ) ;
F_4 ( F_77 ( & exp -> V_108 ) ) ;
F_4 ( F_77 ( & exp -> V_109 ) ) ;
F_4 ( F_77 ( & exp -> V_110 ) ) ;
F_78 ( exp ) ;
F_62 ( V_2 , L_35 , exp ) ;
F_79 ( exp , sizeof( * exp ) , & exp -> V_111 ) ;
}
static void F_80 ( void * V_98 )
{
F_81 ( V_98 ) ;
}
struct V_95 * F_81 ( struct V_95 * exp )
{
F_82 ( & exp -> V_104 ) ;
F_17 ( V_22 , L_36 , exp ,
F_56 ( & exp -> V_104 ) ) ;
return exp ;
}
void F_71 ( struct V_95 * exp )
{
F_4 ( exp != NULL ) ;
F_83 ( & exp -> V_104 , 0 , V_112 ) ;
F_17 ( V_22 , L_37 , exp ,
F_56 ( & exp -> V_104 ) - 1 ) ;
if ( F_84 ( & exp -> V_104 ) ) {
F_4 ( ! F_77 ( & exp -> V_113 ) ) ;
F_17 ( V_36 , L_38 ,
exp , exp -> V_105 . V_64 ) ;
F_85 ( exp ) ;
F_86 ( exp ) ;
}
}
struct V_95 * F_87 ( struct V_1 * V_2 ,
struct V_63 * V_114 )
{
struct V_95 * V_98 ;
T_1 * V_115 = NULL ;
int V_34 = 0 ;
F_25 ( V_98 ) ;
if ( ! V_98 )
return F_40 ( - V_38 ) ;
V_98 -> V_116 = 0 ;
V_98 -> V_117 = NULL ;
V_98 -> V_118 = NULL ;
F_88 ( & V_98 -> V_104 , 2 ) ;
F_88 ( & V_98 -> V_119 , 0 ) ;
F_88 ( & V_98 -> V_120 , 0 ) ;
F_88 ( & V_98 -> V_121 , 0 ) ;
#if V_122
F_89 ( & V_98 -> V_123 ) ;
F_26 ( & V_98 -> V_124 ) ;
#endif
F_88 ( & V_98 -> V_125 , 0 ) ;
V_98 -> V_102 = V_2 ;
F_89 ( & V_98 -> V_107 ) ;
F_26 ( & V_98 -> V_126 ) ;
F_89 ( & V_98 -> V_108 ) ;
F_89 ( & V_98 -> V_109 ) ;
F_89 ( & V_98 -> V_111 . V_127 ) ;
F_89 ( & V_98 -> V_110 ) ;
F_90 ( & V_98 -> V_111 , & V_128 ) ;
V_98 -> V_129 = F_91 () ;
F_26 ( & V_98 -> V_130 ) ;
F_26 ( & V_98 -> V_131 ) ;
F_92 ( & V_98 -> V_132 ) ;
F_92 ( & V_98 -> V_133 ) ;
F_26 ( & V_98 -> V_134 ) ;
F_89 ( & V_98 -> V_135 ) ;
V_98 -> V_136 = V_137 ;
V_98 -> V_138 . V_139 = V_140 ;
V_98 -> V_105 = * V_114 ;
F_93 ( V_98 ) ;
F_11 ( & V_2 -> V_55 ) ;
if ( V_2 -> V_70 )
GOTO ( V_141 , V_34 = - V_53 ) ;
V_115 = F_94 ( V_2 -> V_142 ) ;
if ( V_115 == NULL )
GOTO ( V_141 , V_34 = - V_53 ) ;
F_14 ( & V_2 -> V_55 ) ;
if ( ! F_51 ( V_114 , & V_2 -> V_63 ) ) {
V_34 = F_95 ( V_115 , V_114 , & V_98 -> V_132 ) ;
if ( V_34 != 0 ) {
F_96 ( L_39 ,
V_2 -> V_56 , V_114 -> V_64 , V_34 ) ;
GOTO ( V_143 , V_34 = - V_144 ) ;
}
}
F_11 ( & V_2 -> V_55 ) ;
if ( V_2 -> V_70 ) {
F_97 ( V_115 , V_114 , & V_98 -> V_132 ) ;
GOTO ( V_141 , V_34 = - V_53 ) ;
}
F_60 ( V_2 , L_35 , V_98 ) ;
F_32 ( & V_98 -> V_113 , & V_98 -> V_102 -> V_145 ) ;
F_98 ( & V_98 -> V_146 ,
& V_98 -> V_102 -> V_147 ) ;
V_98 -> V_102 -> V_148 ++ ;
F_14 ( & V_2 -> V_55 ) ;
F_99 ( V_115 ) ;
return V_98 ;
V_141:
F_14 ( & V_2 -> V_55 ) ;
V_143:
if ( V_115 )
F_99 ( V_115 ) ;
F_100 ( & V_98 -> V_111 ) ;
F_4 ( F_101 ( & V_98 -> V_132 ) ) ;
F_78 ( V_98 ) ;
F_34 ( V_98 ) ;
return F_40 ( V_34 ) ;
}
void F_102 ( struct V_95 * exp )
{
F_100 ( & exp -> V_111 ) ;
F_11 ( & exp -> V_102 -> V_55 ) ;
if ( ! F_101 ( & exp -> V_132 ) )
F_97 ( exp -> V_102 -> V_142 ,
& exp -> V_105 ,
& exp -> V_132 ) ;
F_103 ( & exp -> V_113 , & exp -> V_102 -> V_149 ) ;
F_104 ( & exp -> V_146 ) ;
exp -> V_102 -> V_148 -- ;
F_14 ( & exp -> V_102 -> V_55 ) ;
F_71 ( exp ) ;
}
void F_105 ( struct V_93 * V_150 )
{
F_17 ( V_36 , L_40 , V_150 ,
V_150 -> V_151 -> V_56 ) ;
F_75 ( & V_150 -> V_152 ) ;
F_76 ( V_150 -> V_153 ) ;
while ( ! F_77 ( & V_150 -> V_154 ) ) {
struct V_155 * V_156 ;
V_156 = F_13 ( V_150 -> V_154 . V_79 ,
struct V_155 , V_157 ) ;
F_104 ( & V_156 -> V_157 ) ;
F_76 ( V_156 -> V_158 ) ;
F_33 ( V_156 , sizeof( * V_156 ) ) ;
}
F_4 ( V_150 -> V_159 == NULL ) ;
F_62 ( V_150 -> V_151 , L_41 , V_150 ) ;
F_79 ( V_150 , sizeof( * V_150 ) , & V_150 -> V_160 ) ;
}
static void F_106 ( void * V_161 )
{
F_107 ( V_161 ) ;
}
struct V_93 * F_107 ( struct V_93 * V_161 )
{
F_82 ( & V_161 -> V_152 ) ;
F_17 ( V_22 , L_42 , V_161 ,
F_56 ( & V_161 -> V_152 ) ,
V_161 -> V_151 -> V_56 ) ;
return V_161 ;
}
void F_108 ( struct V_93 * V_150 )
{
F_4 ( F_77 ( & V_150 -> V_162 ) ) ;
F_83 ( & V_150 -> V_152 , 0 , V_112 ) ;
F_17 ( V_22 , L_42 , V_150 ,
F_56 ( & V_150 -> V_152 ) - 1 ,
V_150 -> V_151 -> V_56 ) ;
if ( F_84 ( & V_150 -> V_152 ) ) {
F_17 ( V_22 , L_43 , V_150 ) ;
F_109 ( V_150 ) ;
}
F_110 ( & V_150 -> V_152 , 0 , V_112 ) ;
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
F_24 ( V_150 , sizeof( * V_150 ) ) ;
if ( V_150 == NULL )
return NULL ;
F_89 ( & V_150 -> V_170 ) ;
F_89 ( & V_150 -> V_162 ) ;
F_89 ( & V_150 -> V_171 ) ;
F_89 ( & V_150 -> V_172 ) ;
F_89 ( & V_150 -> V_173 ) ;
F_26 ( & V_150 -> V_174 ) ;
V_150 -> V_175 = 0 ;
V_150 -> V_176 = V_177 ;
V_150 -> V_151 = F_60 ( V_2 , L_41 , V_150 ) ;
F_114 ( & V_150 -> V_178 ) ;
F_115 ( & V_150 -> V_179 ) ;
F_88 ( & V_150 -> V_152 , 2 ) ;
F_88 ( & V_150 -> V_180 , 0 ) ;
F_88 ( & V_150 -> V_181 , 0 ) ;
F_88 ( & V_150 -> V_182 , 0 ) ;
F_88 ( & V_150 -> V_183 , 0 ) ;
F_89 ( & V_150 -> V_154 ) ;
F_89 ( & V_150 -> V_160 . V_127 ) ;
F_90 ( & V_150 -> V_160 , & V_184 ) ;
F_111 ( & V_150 -> V_163 ) ;
V_150 -> V_185 = V_186 ;
return V_150 ;
}
void F_116 ( struct V_93 * V_161 )
{
F_4 ( V_161 != NULL ) ;
F_4 ( V_161 != V_187 ) ;
F_100 ( & V_161 -> V_160 ) ;
F_11 ( & V_161 -> V_174 ) ;
V_161 -> V_188 ++ ;
F_14 ( & V_161 -> V_174 ) ;
F_108 ( V_161 ) ;
}
void F_117 ( struct V_95 * exp , struct V_189 * V_190 )
{
F_11 ( & exp -> V_124 ) ;
F_4 ( V_190 -> V_191 >= 0 ) ;
if ( V_190 -> V_192 != NULL &&
V_190 -> V_192 != exp ) {
F_96 ( L_44 ,
exp , V_190 , V_190 -> V_192 ) ;
}
if ( ( V_190 -> V_191 ++ ) == 0 ) {
F_32 ( & V_190 -> V_193 , & exp -> V_123 ) ;
V_190 -> V_192 = exp ;
}
F_17 ( V_22 , L_45 ,
V_190 , exp , V_190 -> V_191 ) ;
F_14 ( & exp -> V_124 ) ;
}
void F_118 ( struct V_95 * exp , struct V_189 * V_190 )
{
F_11 ( & exp -> V_124 ) ;
F_4 ( V_190 -> V_191 > 0 ) ;
if ( V_190 -> V_192 != exp ) {
F_96 ( L_46
L_47 ,
V_190 , V_190 -> V_192 , exp ) ;
}
if ( -- V_190 -> V_191 == 0 ) {
F_104 ( & V_190 -> V_193 ) ;
V_190 -> V_192 = NULL ;
}
F_17 ( V_22 , L_45 ,
V_190 , exp , V_190 -> V_191 ) ;
F_14 ( & exp -> V_124 ) ;
}
int F_119 ( struct V_96 * V_97 , struct V_1 * V_2 ,
struct V_63 * V_114 )
{
struct V_95 * V_98 ;
F_4 ( V_97 != NULL ) ;
F_4 ( V_2 != NULL ) ;
F_4 ( V_114 != NULL ) ;
V_98 = F_87 ( V_2 , V_114 ) ;
if ( F_29 ( V_98 ) )
return F_30 ( V_98 ) ;
V_97 -> V_100 = V_98 -> V_111 . V_194 ;
F_71 ( V_98 ) ;
F_17 ( V_36 , L_48 V_101 L_33 ,
V_114 -> V_64 , V_97 -> V_100 ) ;
return 0 ;
}
void F_120 ( struct V_95 * exp )
{
struct V_1 * V_2 = exp -> V_102 ;
F_11 ( & V_2 -> V_195 ) ;
if ( exp -> V_196 )
V_2 -> V_197 -- ;
if ( V_2 -> V_198 ) {
if ( exp -> V_199 ) {
F_11 ( & exp -> V_130 ) ;
exp -> V_199 = 0 ;
F_14 ( & exp -> V_130 ) ;
F_121 ( & V_2 -> V_200 ) ;
F_122 ( & V_2 -> V_200 ) ;
}
if ( exp -> V_201 &&
( F_123 ( exp ) & V_202 ) == 0 )
exp -> V_102 -> V_203 ++ ;
}
F_14 ( & V_2 -> V_195 ) ;
if ( exp -> V_204 ) {
F_11 ( & exp -> V_130 ) ;
exp -> V_204 = 0 ;
F_14 ( & exp -> V_130 ) ;
F_4 ( F_56 ( & V_2 -> V_205 ) ) ;
F_122 ( & V_2 -> V_205 ) ;
}
if ( exp -> V_206 ) {
F_11 ( & exp -> V_130 ) ;
exp -> V_206 = 0 ;
F_14 ( & exp -> V_130 ) ;
F_4 ( F_56 ( & V_2 -> V_207 ) ) ;
F_122 ( & V_2 -> V_207 ) ;
}
}
int F_124 ( struct V_95 * V_98 )
{
int V_208 ;
if ( V_98 == NULL ) {
F_125 ( L_49 , V_98 ) ;
return - V_45 ;
}
F_11 ( & V_98 -> V_130 ) ;
V_208 = V_98 -> V_209 ;
V_98 -> V_209 = 1 ;
F_14 ( & V_98 -> V_130 ) ;
if ( V_208 ) {
F_4 ( F_101 ( & V_98 -> V_133 ) ) ;
GOTO ( V_210 , V_208 ) ;
}
F_17 ( V_36 , L_50 V_101 L_33 ,
V_98 -> V_111 . V_194 ) ;
if ( ! F_101 ( & V_98 -> V_133 ) )
F_97 ( V_98 -> V_102 -> V_211 ,
& V_98 -> V_106 -> V_212 . V_213 ,
& V_98 -> V_133 ) ;
F_120 ( V_98 ) ;
F_102 ( V_98 ) ;
V_210:
F_71 ( V_98 ) ;
return 0 ;
}
int F_126 ( struct V_95 * exp )
{
if ( exp ) {
int V_214 ;
F_11 ( & exp -> V_130 ) ;
V_214 = ( exp -> V_116 > 0 ) ;
F_14 ( & exp -> V_130 ) ;
return V_214 ;
}
return 0 ;
}
static void F_127 ( struct V_12 * V_215 ,
enum V_216 V_217 )
{
int V_34 ;
struct V_95 * exp ;
while ( ! F_77 ( V_215 ) ) {
exp = F_13 ( V_215 -> V_79 , struct V_95 ,
V_113 ) ;
F_81 ( exp ) ;
F_11 ( & exp -> V_130 ) ;
exp -> V_218 = V_217 ;
F_14 ( & exp -> V_130 ) ;
if ( F_51 ( & exp -> V_105 ,
& exp -> V_102 -> V_63 ) ) {
F_17 ( V_219 ,
L_51 ,
exp ) ;
F_104 ( & exp -> V_113 ) ;
F_71 ( exp ) ;
continue;
}
F_81 ( exp ) ;
F_17 ( V_219 , L_52
L_53 V_220 L_33 ,
exp -> V_102 -> V_56 , F_128 ( exp ) ,
exp , exp -> V_129 ) ;
V_34 = F_129 ( exp ) ;
F_17 ( V_219 , L_54 ,
F_128 ( exp ) , exp , V_34 ) ;
F_71 ( exp ) ;
}
}
void F_130 ( struct V_1 * V_2 )
{
struct V_12 V_221 ;
F_89 ( & V_221 ) ;
F_11 ( & V_2 -> V_55 ) ;
F_131 ( & V_2 -> V_145 , & V_221 ) ;
F_131 ( & V_2 -> V_222 , & V_221 ) ;
F_14 ( & V_2 -> V_55 ) ;
if ( ! F_77 ( & V_221 ) ) {
F_17 ( V_219 , L_55
L_56 , V_2 -> V_57 , V_2 ) ;
F_127 ( & V_221 ,
F_132 ( V_2 ) ) ;
} else
F_17 ( V_219 , L_57 ,
V_2 -> V_57 , V_2 ) ;
}
void F_133 ( struct V_1 * V_2 ,
int (* F_134)( struct V_95 * ) )
{
struct V_12 V_221 ;
struct V_95 * exp , * V_223 ;
int V_224 = 0 ;
F_89 ( & V_221 ) ;
F_11 ( & V_2 -> V_55 ) ;
F_135 (exp, n, &obd->obd_exports,
exp_obd_chain) {
if ( F_51 ( & exp -> V_105 ,
& exp -> V_102 -> V_63 ) )
continue;
if ( exp -> V_225 . V_226 == - 1 )
continue;
F_11 ( & exp -> V_130 ) ;
if ( exp -> V_201 || F_134 ( exp ) ) {
F_14 ( & exp -> V_130 ) ;
continue;
}
exp -> V_201 = 1 ;
F_14 ( & exp -> V_130 ) ;
F_103 ( & exp -> V_113 , & V_221 ) ;
V_224 ++ ;
F_17 ( V_219 , L_58 ,
V_2 -> V_56 , exp -> V_105 . V_64 ,
exp -> V_106 == NULL ? L_59 :
F_136 ( exp -> V_106 -> V_212 . V_213 ) ) ;
F_137 ( exp , L_60 , 0 ) ;
}
F_14 ( & V_2 -> V_55 ) ;
if ( V_224 )
F_96 ( L_61 ,
V_2 -> V_56 , V_224 ) ;
F_127 ( & V_221 , F_132 ( V_2 ) |
V_227 ) ;
}
void F_138 ( struct V_95 * exp )
{
int V_34 , V_228 ;
F_11 ( & exp -> V_130 ) ;
V_228 = exp -> V_201 ;
exp -> V_201 = 1 ;
F_14 ( & exp -> V_130 ) ;
if ( V_228 ) {
F_17 ( V_219 , L_62 ,
exp , exp -> V_105 . V_64 ) ;
return;
}
F_17 ( V_219 , L_63 ,
exp , exp -> V_105 . V_64 ) ;
if ( V_229 )
F_139 () ;
F_81 ( exp ) ;
F_81 ( exp ) ;
V_34 = F_129 ( exp ) ;
if ( V_34 )
F_6 ( L_64 , exp , V_34 ) ;
else
F_17 ( V_219 , L_65 ,
exp , exp -> V_105 . V_64 ) ;
F_71 ( exp ) ;
}
char * F_128 ( struct V_95 * exp )
{
if ( exp -> V_106 != NULL )
return F_136 ( exp -> V_106 -> V_212 . V_213 ) ;
return L_66 ;
}
int F_140 ( struct V_1 * V_2 , const char * V_213 )
{
T_1 * V_230 ;
struct V_95 * V_231 = NULL ;
int V_232 = 0 ;
T_2 V_233 = F_141 ( ( char * ) V_213 ) ;
F_11 ( & V_2 -> V_55 ) ;
if ( V_2 -> V_70 ) {
F_14 ( & V_2 -> V_55 ) ;
return V_232 ;
}
V_230 = V_2 -> V_211 ;
F_94 ( V_230 ) ;
F_14 ( & V_2 -> V_55 ) ;
do {
V_231 = F_142 ( V_230 , & V_233 ) ;
if ( V_231 == NULL )
break;
F_5 ( V_231 -> V_106 -> V_212 . V_213 == V_233 ,
L_67 ,
F_128 ( V_231 ) ,
F_136 ( V_233 ) , V_213 ) ;
F_5 ( V_231 != V_2 -> V_87 ,
L_68 ) ;
V_232 ++ ;
F_96 ( L_69
L_70 , V_2 -> V_56 ,
F_143 ( & V_231 -> V_105 ) ,
F_128 ( V_231 ) ) ;
F_138 ( V_231 ) ;
F_71 ( V_231 ) ;
} while ( 1 );
F_99 ( V_230 ) ;
if ( ! V_232 )
F_17 ( V_219 , L_71 ,
V_2 -> V_56 , V_213 ) ;
return V_232 ;
}
int F_144 ( struct V_1 * V_2 , const char * V_64 )
{
T_1 * V_234 ;
struct V_95 * V_231 = NULL ;
struct V_63 V_235 ;
int V_232 = 0 ;
F_11 ( & V_2 -> V_55 ) ;
if ( V_2 -> V_70 ) {
F_14 ( & V_2 -> V_55 ) ;
return V_232 ;
}
V_234 = V_2 -> V_142 ;
F_94 ( V_234 ) ;
F_14 ( & V_2 -> V_55 ) ;
F_145 ( & V_235 , V_64 ) ;
if ( F_51 ( & V_235 , & V_2 -> V_63 ) ) {
F_6 ( L_72 , V_2 -> V_56 ) ;
F_99 ( V_234 ) ;
return V_232 ;
}
V_231 = F_142 ( V_234 , & V_235 ) ;
if ( V_231 == NULL ) {
F_6 ( L_73 ,
V_2 -> V_56 , V_64 ) ;
} else {
F_125 ( L_74 ,
V_2 -> V_56 , V_231 -> V_105 . V_64 ) ;
F_138 ( V_231 ) ;
F_71 ( V_231 ) ;
V_232 ++ ;
}
F_99 ( V_234 ) ;
return V_232 ;
}
static void F_137 ( struct V_95 * exp , const char * V_69 ,
int V_236 )
{
struct V_237 * V_238 ;
struct V_237 * V_239 = NULL ;
int V_240 = 0 ;
F_11 ( & exp -> V_130 ) ;
F_146 (rs, &exp->exp_outstanding_replies,
rs_exp_list) {
if ( V_240 == 0 )
V_239 = V_238 ;
V_240 ++ ;
}
F_14 ( & exp -> V_130 ) ;
F_17 ( V_219 , L_75 V_241 L_33 ,
exp -> V_102 -> V_56 , V_69 , exp , exp -> V_105 . V_64 ,
F_128 ( exp ) , F_56 ( & exp -> V_104 ) ,
F_56 ( & exp -> V_119 ) ,
F_56 ( & exp -> V_120 ) ,
F_56 ( & exp -> V_121 ) ,
exp -> V_209 , exp -> V_196 , exp -> V_201 ,
V_240 , V_239 , V_240 > 3 ? L_76 : L_77 ,
exp -> V_242 ) ;
#if V_122
if ( V_236 && V_243 != NULL )
V_243 ( exp ) ;
#endif
}
void F_147 ( struct V_1 * V_2 , int V_236 )
{
struct V_95 * exp ;
F_11 ( & V_2 -> V_55 ) ;
F_146 (exp, &obd->obd_exports, exp_obd_chain)
F_137 ( exp , L_78 , V_236 ) ;
F_146 (exp, &obd->obd_unlinked_exports, exp_obd_chain)
F_137 ( exp , L_79 , V_236 ) ;
F_146 (exp, &obd->obd_delayed_exports, exp_obd_chain)
F_137 ( exp , L_80 , V_236 ) ;
F_14 ( & V_2 -> V_55 ) ;
F_11 ( & V_244 ) ;
F_146 (exp, &obd_zombie_exports, exp_obd_chain)
F_137 ( exp , L_81 , V_236 ) ;
F_14 ( & V_244 ) ;
}
void F_148 ( struct V_1 * V_2 )
{
int V_245 = 2 ;
F_4 ( F_77 ( & V_2 -> V_145 ) ) ;
F_11 ( & V_2 -> V_55 ) ;
while ( ! F_77 ( & V_2 -> V_149 ) ) {
F_14 ( & V_2 -> V_55 ) ;
F_149 ( V_246 ,
F_150 ( V_245 ) ) ;
if ( V_245 > 5 && F_151 ( V_245 ) ) {
F_96 ( L_82
L_83
L_84 ,
V_2 -> V_56 , V_245 ,
F_56 ( & V_2 -> V_73 ) ) ;
F_147 ( V_2 , 1 ) ;
}
V_245 *= 2 ;
F_11 ( & V_2 -> V_55 ) ;
}
F_14 ( & V_2 -> V_55 ) ;
}
void F_152 ( void )
{
struct V_93 * V_161 ;
struct V_95 * V_98 ;
do {
F_11 ( & V_244 ) ;
V_161 = NULL ;
if ( ! F_77 ( & V_247 ) ) {
V_161 = F_13 ( V_247 . V_79 ,
struct V_93 ,
V_162 ) ;
F_104 ( & V_161 -> V_162 ) ;
}
V_98 = NULL ;
if ( ! F_77 ( & V_248 ) ) {
V_98 = F_13 ( V_248 . V_79 ,
struct V_95 ,
V_113 ) ;
F_104 ( & V_98 -> V_113 ) ;
}
F_14 ( & V_244 ) ;
if ( V_161 != NULL ) {
F_105 ( V_161 ) ;
F_11 ( & V_244 ) ;
V_249 -- ;
F_14 ( & V_244 ) ;
}
if ( V_98 != NULL ) {
F_74 ( V_98 ) ;
F_11 ( & V_244 ) ;
V_249 -- ;
F_14 ( & V_244 ) ;
}
F_153 () ;
} while ( V_161 != NULL || V_98 != NULL );
}
static int F_154 ( void * V_250 )
{
int V_34 ;
F_11 ( & V_244 ) ;
V_34 = ( V_249 == 0 ) &&
! F_155 ( V_251 , & V_252 ) ;
F_14 ( & V_244 ) ;
return V_34 ;
}
static void F_86 ( struct V_95 * exp ) {
F_11 ( & exp -> V_102 -> V_55 ) ;
F_4 ( ! F_77 ( & exp -> V_113 ) ) ;
F_104 ( & exp -> V_113 ) ;
F_14 ( & exp -> V_102 -> V_55 ) ;
F_11 ( & V_244 ) ;
V_249 ++ ;
F_32 ( & exp -> V_113 , & V_248 ) ;
F_14 ( & V_244 ) ;
F_156 () ;
}
static void F_109 ( struct V_93 * V_150 ) {
F_4 ( V_150 -> V_159 == NULL ) ;
F_4 ( V_150 -> V_253 == NULL ) ;
F_11 ( & V_244 ) ;
F_4 ( F_77 ( & V_150 -> V_162 ) ) ;
V_249 ++ ;
F_32 ( & V_150 -> V_162 , & V_247 ) ;
F_14 ( & V_244 ) ;
F_156 () ;
}
static void F_156 ( void )
{
F_157 ( & V_254 ) ;
}
static int F_158 ( void )
{
int V_34 ;
F_4 ( ! F_155 ( V_251 , & V_252 ) ) ;
F_11 ( & V_244 ) ;
V_34 = ( V_249 == 0 ) ;
F_14 ( & V_244 ) ;
return V_34 ;
}
void F_159 ( void )
{
struct V_255 V_256 = { 0 } ;
if ( V_257 == F_160 () )
return;
F_161 ( V_254 , F_158 () , & V_256 ) ;
}
static int F_162 ( void * V_258 )
{
F_163 () ;
F_164 ( & V_259 ) ;
V_257 = F_160 () ;
while ( ! F_155 ( V_251 , & V_252 ) ) {
struct V_255 V_256 = { 0 } ;
F_161 ( V_254 ,
! F_154 ( NULL ) , & V_256 ) ;
F_152 () ;
F_165 ( & V_254 ) ;
}
F_164 ( & V_260 ) ;
return 0 ;
}
int F_166 ( void )
{
struct V_261 * V_262 ;
F_89 ( & V_247 ) ;
F_89 ( & V_248 ) ;
F_26 ( & V_244 ) ;
F_167 ( & V_259 ) ;
F_167 ( & V_260 ) ;
F_115 ( & V_254 ) ;
V_257 = 0 ;
V_262 = F_168 ( F_162 , NULL , L_85 ) ;
if ( F_29 ( V_262 ) )
return F_30 ( V_262 ) ;
F_169 ( & V_259 ) ;
return 0 ;
}
void F_170 ( void )
{
F_171 ( V_251 , & V_252 ) ;
F_156 () ;
F_169 ( & V_260 ) ;
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
return F_40 ( - V_38 ) ;
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
