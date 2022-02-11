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
type -> V_41 = F_27 ( type -> V_16 , V_42 ,
V_31 , type ) ;
if ( F_28 ( type -> V_41 ) ) {
V_34 = F_29 ( type -> V_41 ) ;
type -> V_41 = NULL ;
GOTO ( V_40 , V_34 ) ;
}
if ( V_33 != NULL ) {
type -> V_43 = V_33 ;
V_34 = F_30 ( V_33 ) ;
if ( V_34 != 0 )
GOTO ( V_40 , V_34 ) ;
}
F_11 ( & V_14 ) ;
F_31 ( & type -> V_15 , & V_44 ) ;
F_14 ( & V_14 ) ;
return 0 ;
V_40:
if ( type -> V_16 != NULL )
F_32 ( type -> V_16 , strlen ( V_11 ) + 1 ) ;
if ( type -> V_39 != NULL )
F_33 ( type -> V_39 ) ;
if ( type -> V_25 != NULL )
F_33 ( type -> V_25 ) ;
F_32 ( type , sizeof( * type ) ) ;
return V_34 ;
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
F_33 ( type -> V_39 ) ;
return - V_46 ;
}
if ( type -> V_41 ) {
F_35 ( & type -> V_41 ) ;
}
if ( type -> V_43 )
F_36 ( type -> V_43 ) ;
F_11 ( & V_14 ) ;
F_37 ( & type -> V_15 ) ;
F_14 ( & V_14 ) ;
F_32 ( type -> V_16 , strlen ( V_11 ) + 1 ) ;
if ( type -> V_25 != NULL )
F_33 ( type -> V_25 ) ;
if ( type -> V_39 != NULL )
F_33 ( type -> V_39 ) ;
F_32 ( type , sizeof( * type ) ) ;
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
if ( V_49 == NULL )
GOTO ( V_54 , V_48 = F_39 ( - V_38 ) ) ;
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
V_48 = F_39 ( - V_37 ) ;
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
GOTO ( V_59 , V_48 = F_39 ( - V_60 ) ) ;
}
if ( F_28 ( V_48 ) )
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
void F_44 ( struct V_1 * V_2 )
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
int F_45 ( const char * V_11 )
{
int V_50 ;
if ( ! V_11 )
return - 1 ;
F_46 ( & V_55 ) ;
for ( V_50 = 0 ; V_50 < F_41 () ; V_50 ++ ) {
struct V_1 * V_2 = F_42 ( V_50 ) ;
if ( V_2 && strcmp ( V_11 , V_2 -> V_56 ) == 0 ) {
F_4 ( V_2 -> V_5 == V_6 ) ;
if ( V_2 -> V_61 ) {
F_47 ( & V_55 ) ;
return V_50 ;
}
break;
}
}
F_47 ( & V_55 ) ;
return - 1 ;
}
struct V_1 * F_48 ( const char * V_11 )
{
int V_62 = F_45 ( V_11 ) ;
if ( V_62 < 0 || V_62 > F_41 () )
return NULL ;
return F_42 ( V_62 ) ;
}
int F_49 ( struct V_63 * V_64 )
{
int V_50 ;
F_46 ( & V_55 ) ;
for ( V_50 = 0 ; V_50 < F_41 () ; V_50 ++ ) {
struct V_1 * V_2 = F_42 ( V_50 ) ;
if ( V_2 && F_50 ( V_64 , & V_2 -> V_63 ) ) {
F_4 ( V_2 -> V_5 == V_6 ) ;
F_47 ( & V_55 ) ;
return V_50 ;
}
}
F_47 ( & V_55 ) ;
return - 1 ;
}
struct V_1 * F_51 ( struct V_63 * V_64 )
{
int V_62 = F_49 ( V_64 ) ;
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
int F_52 ( void )
{
int V_66 , V_67 = F_41 () , V_68 = 0 ;
F_46 ( & V_55 ) ;
for ( V_66 = 0 ; V_66 <= V_67 ; V_66 ++ ) {
struct V_1 * V_2 = F_42 ( V_66 ) ;
if ( V_2 != NULL )
V_68 ++ ;
}
F_47 ( & V_55 ) ;
return V_68 ;
}
void F_53 ( void )
{
char * V_69 ;
int V_50 ;
F_46 ( & V_55 ) ;
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
F_54 ( V_72 , L_25 ,
V_50 , V_69 , V_2 -> V_10 -> V_16 ,
V_2 -> V_56 , V_2 -> V_63 . V_64 ,
F_55 ( & V_2 -> V_73 ) ) ;
}
F_47 ( & V_55 ) ;
return;
}
struct V_1 * F_56 ( struct V_63 * V_74 ,
const char * V_16 ,
struct V_63 * V_75 )
{
int V_50 ;
F_46 ( & V_55 ) ;
for ( V_50 = 0 ; V_50 < F_41 () ; V_50 ++ ) {
struct V_1 * V_2 = F_42 ( V_50 ) ;
if ( V_2 == NULL )
continue;
if ( ( strncmp ( V_2 -> V_10 -> V_16 , V_16 ,
strlen ( V_16 ) ) == 0 ) ) {
if ( F_50 ( V_74 ,
& V_2 -> V_76 . V_77 . V_78 ) &&
( ( V_75 ) ? F_50 ( V_75 ,
& V_2 -> V_63 ) : 1 ) ) {
F_47 ( & V_55 ) ;
return V_2 ;
}
}
}
F_47 ( & V_55 ) ;
return NULL ;
}
struct V_1 * F_57 ( struct V_63 * V_75 , int * V_79 )
{
int V_50 ;
if ( V_79 == NULL )
V_50 = 0 ;
else if ( * V_79 >= 0 && * V_79 < F_41 () )
V_50 = * V_79 ;
else
return NULL ;
F_46 ( & V_55 ) ;
for (; V_50 < F_41 () ; V_50 ++ ) {
struct V_1 * V_2 = F_42 ( V_50 ) ;
if ( V_2 == NULL )
continue;
if ( F_50 ( V_75 , & V_2 -> V_63 ) ) {
if ( V_79 != NULL )
* V_79 = V_50 + 1 ;
F_47 ( & V_55 ) ;
return V_2 ;
}
}
F_47 ( & V_55 ) ;
return NULL ;
}
int F_58 ( const char * V_80 , int V_81 )
{
struct V_1 * V_2 ;
const char * type ;
int V_50 , V_34 = 0 , V_82 ;
F_4 ( V_81 > 0 ) ;
F_46 ( & V_55 ) ;
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
F_59 ( V_2 , V_86 , V_2 ) ;
F_47 ( & V_55 ) ;
V_82 = F_60 ( NULL , V_2 -> V_87 ,
sizeof( V_88 ) ,
V_88 , 0 , NULL , NULL ) ;
V_34 = V_34 ? V_34 : V_82 ;
F_61 ( V_2 , V_86 , V_2 ) ;
F_46 ( & V_55 ) ;
}
F_47 ( & V_55 ) ;
return V_34 ;
}
void F_62 ( void )
{
if ( V_3 ) {
F_63 ( V_3 ) ;
V_3 = NULL ;
}
if ( V_89 ) {
F_63 ( V_89 ) ;
V_89 = NULL ;
}
if ( V_90 ) {
F_63 ( V_90 ) ;
V_90 = NULL ;
}
if ( V_91 ) {
F_63 ( V_91 ) ;
V_91 = NULL ;
}
}
int F_64 ( void )
{
F_4 ( V_3 == NULL ) ;
V_3 = F_65 ( L_26 ,
sizeof( struct V_1 ) ,
0 , 0 , NULL ) ;
if ( ! V_3 )
GOTO ( V_59 , - V_38 ) ;
F_4 ( V_89 == NULL ) ;
V_89 = F_65 ( L_27 , sizeof( struct V_92 ) ,
0 , 0 , NULL ) ;
if ( ! V_89 )
GOTO ( V_59 , - V_38 ) ;
F_4 ( V_90 == NULL ) ;
V_90 = F_65 ( L_28 ,
sizeof( struct V_93 ) ,
0 , 0 , NULL ) ;
if ( ! V_90 )
GOTO ( V_59 , - V_38 ) ;
F_4 ( V_91 == NULL ) ;
V_91 = F_65 ( L_29 ,
sizeof( struct V_94 ) , 0 , 0 , NULL ) ;
if ( ! V_91 )
GOTO ( V_59 , - V_38 ) ;
return 0 ;
V_59:
F_62 () ;
return - V_38 ;
}
struct V_95 * F_66 ( struct V_96 * V_97 )
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
V_98 = F_67 ( V_97 -> V_100 ) ;
return V_98 ;
}
struct V_1 * F_68 ( struct V_95 * exp )
{
if ( exp )
return exp -> V_102 ;
return NULL ;
}
struct V_1 * F_69 ( struct V_96 * V_97 )
{
struct V_95 * V_98 ;
V_98 = F_66 ( V_97 ) ;
if ( V_98 ) {
struct V_1 * V_2 = V_98 -> V_102 ;
F_70 ( V_98 ) ;
return V_2 ;
}
return NULL ;
}
struct V_93 * F_71 ( struct V_95 * exp )
{
struct V_1 * V_2 = exp -> V_102 ;
if ( V_2 == NULL )
return NULL ;
return V_2 -> V_76 . V_77 . V_103 ;
}
struct V_93 * F_72 ( struct V_96 * V_97 )
{
struct V_1 * V_2 = F_69 ( V_97 ) ;
if ( V_2 == NULL )
return NULL ;
return V_2 -> V_76 . V_77 . V_103 ;
}
static void F_73 ( struct V_95 * exp )
{
struct V_1 * V_2 = exp -> V_102 ;
F_74 ( & exp -> V_104 ) ;
F_4 ( V_2 != NULL ) ;
F_17 ( V_36 , L_34 , exp ,
exp -> V_105 . V_64 , V_2 -> V_56 ) ;
if ( exp -> V_106 )
F_75 ( exp -> V_106 ) ;
F_4 ( F_76 ( & exp -> V_107 ) ) ;
F_4 ( F_76 ( & exp -> V_108 ) ) ;
F_4 ( F_76 ( & exp -> V_109 ) ) ;
F_4 ( F_76 ( & exp -> V_110 ) ) ;
F_77 ( exp ) ;
F_61 ( V_2 , L_35 , exp ) ;
F_78 ( exp , sizeof( * exp ) , & exp -> V_111 ) ;
}
static void F_79 ( void * V_98 )
{
F_80 ( V_98 ) ;
}
struct V_95 * F_80 ( struct V_95 * exp )
{
F_81 ( & exp -> V_104 ) ;
F_17 ( V_22 , L_36 , exp ,
F_55 ( & exp -> V_104 ) ) ;
return exp ;
}
void F_70 ( struct V_95 * exp )
{
F_4 ( exp != NULL ) ;
F_82 ( & exp -> V_104 , 0 , V_112 ) ;
F_17 ( V_22 , L_37 , exp ,
F_55 ( & exp -> V_104 ) - 1 ) ;
if ( F_83 ( & exp -> V_104 ) ) {
F_4 ( ! F_76 ( & exp -> V_113 ) ) ;
F_17 ( V_36 , L_38 ,
exp , exp -> V_105 . V_64 ) ;
F_84 ( exp ) ;
F_85 ( exp ) ;
}
}
struct V_95 * F_86 ( struct V_1 * V_2 ,
struct V_63 * V_114 )
{
struct V_95 * V_98 ;
struct V_115 * V_116 = NULL ;
int V_34 = 0 ;
F_25 ( V_98 ) ;
if ( ! V_98 )
return F_39 ( - V_38 ) ;
V_98 -> V_117 = 0 ;
V_98 -> V_118 = NULL ;
V_98 -> V_119 = NULL ;
F_87 ( & V_98 -> V_104 , 2 ) ;
F_87 ( & V_98 -> V_120 , 0 ) ;
F_87 ( & V_98 -> V_121 , 0 ) ;
F_87 ( & V_98 -> V_122 , 0 ) ;
#if V_123
F_88 ( & V_98 -> V_124 ) ;
F_26 ( & V_98 -> V_125 ) ;
#endif
F_87 ( & V_98 -> V_126 , 0 ) ;
V_98 -> V_102 = V_2 ;
F_88 ( & V_98 -> V_107 ) ;
F_26 ( & V_98 -> V_127 ) ;
F_88 ( & V_98 -> V_108 ) ;
F_88 ( & V_98 -> V_109 ) ;
F_88 ( & V_98 -> V_111 . V_128 ) ;
F_88 ( & V_98 -> V_110 ) ;
F_89 ( & V_98 -> V_111 , & V_129 ) ;
V_98 -> V_130 = F_90 () ;
F_26 ( & V_98 -> V_131 ) ;
F_26 ( & V_98 -> V_132 ) ;
F_91 ( & V_98 -> V_133 ) ;
F_91 ( & V_98 -> V_134 ) ;
F_26 ( & V_98 -> V_135 ) ;
F_88 ( & V_98 -> V_136 ) ;
V_98 -> V_137 = V_138 ;
V_98 -> V_139 . V_140 = V_141 ;
V_98 -> V_105 = * V_114 ;
F_92 ( V_98 ) ;
F_11 ( & V_2 -> V_55 ) ;
if ( V_2 -> V_70 )
GOTO ( V_142 , V_34 = - V_53 ) ;
V_116 = F_93 ( V_2 -> V_143 ) ;
if ( V_116 == NULL )
GOTO ( V_142 , V_34 = - V_53 ) ;
F_14 ( & V_2 -> V_55 ) ;
if ( ! F_50 ( V_114 , & V_2 -> V_63 ) ) {
V_34 = F_94 ( V_116 , V_114 , & V_98 -> V_133 ) ;
if ( V_34 != 0 ) {
F_95 ( L_39 ,
V_2 -> V_56 , V_114 -> V_64 , V_34 ) ;
GOTO ( V_144 , V_34 = - V_145 ) ;
}
}
F_11 ( & V_2 -> V_55 ) ;
if ( V_2 -> V_70 ) {
F_96 ( V_116 , V_114 , & V_98 -> V_133 ) ;
GOTO ( V_142 , V_34 = - V_53 ) ;
}
F_59 ( V_2 , L_35 , V_98 ) ;
F_31 ( & V_98 -> V_113 , & V_98 -> V_102 -> V_146 ) ;
F_97 ( & V_98 -> V_147 ,
& V_98 -> V_102 -> V_148 ) ;
V_98 -> V_102 -> V_149 ++ ;
F_14 ( & V_2 -> V_55 ) ;
F_98 ( V_116 ) ;
return V_98 ;
V_142:
F_14 ( & V_2 -> V_55 ) ;
V_144:
if ( V_116 )
F_98 ( V_116 ) ;
F_99 ( & V_98 -> V_111 ) ;
F_4 ( F_100 ( & V_98 -> V_133 ) ) ;
F_77 ( V_98 ) ;
F_33 ( V_98 ) ;
return F_39 ( V_34 ) ;
}
void F_101 ( struct V_95 * exp )
{
F_99 ( & exp -> V_111 ) ;
F_11 ( & exp -> V_102 -> V_55 ) ;
if ( ! F_100 ( & exp -> V_133 ) )
F_96 ( exp -> V_102 -> V_143 ,
& exp -> V_105 ,
& exp -> V_133 ) ;
F_102 ( & exp -> V_113 , & exp -> V_102 -> V_150 ) ;
F_103 ( & exp -> V_147 ) ;
exp -> V_102 -> V_149 -- ;
F_14 ( & exp -> V_102 -> V_55 ) ;
F_70 ( exp ) ;
}
void F_104 ( struct V_93 * V_151 )
{
F_17 ( V_36 , L_40 , V_151 ,
V_151 -> V_152 -> V_56 ) ;
F_74 ( & V_151 -> V_153 ) ;
F_75 ( V_151 -> V_154 ) ;
while ( ! F_76 ( & V_151 -> V_155 ) ) {
struct V_156 * V_157 ;
V_157 = F_13 ( V_151 -> V_155 . V_79 ,
struct V_156 , V_158 ) ;
F_103 ( & V_157 -> V_158 ) ;
F_75 ( V_157 -> V_159 ) ;
F_32 ( V_157 , sizeof( * V_157 ) ) ;
}
F_4 ( V_151 -> V_160 == NULL ) ;
F_61 ( V_151 -> V_152 , L_41 , V_151 ) ;
F_78 ( V_151 , sizeof( * V_151 ) , & V_151 -> V_161 ) ;
}
static void F_105 ( void * V_162 )
{
F_106 ( V_162 ) ;
}
struct V_93 * F_106 ( struct V_93 * V_162 )
{
F_81 ( & V_162 -> V_153 ) ;
F_17 ( V_22 , L_42 , V_162 ,
F_55 ( & V_162 -> V_153 ) ,
V_162 -> V_152 -> V_56 ) ;
return V_162 ;
}
void F_107 ( struct V_93 * V_151 )
{
F_4 ( F_76 ( & V_151 -> V_163 ) ) ;
F_82 ( & V_151 -> V_153 , 0 , V_112 ) ;
F_17 ( V_22 , L_42 , V_151 ,
F_55 ( & V_151 -> V_153 ) - 1 ,
V_151 -> V_152 -> V_56 ) ;
if ( F_83 ( & V_151 -> V_153 ) ) {
F_17 ( V_22 , L_43 , V_151 ) ;
F_108 ( V_151 ) ;
}
F_109 ( & V_151 -> V_153 , 0 , V_112 ) ;
}
static void F_110 ( struct V_164 * V_165 ) {
int V_50 ;
F_111 ( & V_165 -> V_166 , 0 , 0 ) ;
for ( V_50 = 0 ; V_50 < V_167 ; V_50 ++ ) {
F_111 ( & V_165 -> V_168 [ V_50 ] , V_169 ,
V_170 ) ;
}
}
struct V_93 * F_112 ( struct V_1 * V_2 )
{
struct V_93 * V_151 ;
F_24 ( V_151 , sizeof( * V_151 ) ) ;
if ( V_151 == NULL )
return NULL ;
F_88 ( & V_151 -> V_171 ) ;
F_88 ( & V_151 -> V_163 ) ;
F_88 ( & V_151 -> V_172 ) ;
F_88 ( & V_151 -> V_173 ) ;
F_88 ( & V_151 -> V_174 ) ;
F_88 ( & V_151 -> V_175 ) ;
V_151 -> V_176 = & V_151 -> V_175 ;
F_26 ( & V_151 -> V_177 ) ;
V_151 -> V_178 = 0 ;
V_151 -> V_179 = V_180 ;
V_151 -> V_152 = F_59 ( V_2 , L_41 , V_151 ) ;
F_113 ( & V_151 -> V_181 ) ;
F_114 ( & V_151 -> V_182 ) ;
F_87 ( & V_151 -> V_153 , 2 ) ;
F_87 ( & V_151 -> V_183 , 0 ) ;
F_87 ( & V_151 -> V_184 , 0 ) ;
F_87 ( & V_151 -> V_185 , 0 ) ;
F_87 ( & V_151 -> V_186 , 0 ) ;
F_88 ( & V_151 -> V_155 ) ;
F_88 ( & V_151 -> V_161 . V_128 ) ;
F_89 ( & V_151 -> V_161 , & V_187 ) ;
F_110 ( & V_151 -> V_164 ) ;
V_151 -> V_188 = V_189 ;
return V_151 ;
}
void F_115 ( struct V_93 * V_162 )
{
F_4 ( V_162 != NULL ) ;
F_4 ( V_162 != V_190 ) ;
F_99 ( & V_162 -> V_161 ) ;
F_11 ( & V_162 -> V_177 ) ;
V_162 -> V_191 ++ ;
F_14 ( & V_162 -> V_177 ) ;
F_107 ( V_162 ) ;
}
void F_116 ( struct V_95 * exp , struct V_192 * V_193 )
{
F_11 ( & exp -> V_125 ) ;
F_4 ( V_193 -> V_194 >= 0 ) ;
if ( V_193 -> V_195 != NULL &&
V_193 -> V_195 != exp ) {
F_95 ( L_44 ,
exp , V_193 , V_193 -> V_195 ) ;
}
if ( ( V_193 -> V_194 ++ ) == 0 ) {
F_31 ( & V_193 -> V_196 , & exp -> V_124 ) ;
V_193 -> V_195 = exp ;
}
F_17 ( V_22 , L_45 ,
V_193 , exp , V_193 -> V_194 ) ;
F_14 ( & exp -> V_125 ) ;
}
void F_117 ( struct V_95 * exp , struct V_192 * V_193 )
{
F_11 ( & exp -> V_125 ) ;
F_4 ( V_193 -> V_194 > 0 ) ;
if ( V_193 -> V_195 != exp ) {
F_95 ( L_46
L_47 ,
V_193 , V_193 -> V_195 , exp ) ;
}
if ( -- V_193 -> V_194 == 0 ) {
F_103 ( & V_193 -> V_196 ) ;
V_193 -> V_195 = NULL ;
}
F_17 ( V_22 , L_45 ,
V_193 , exp , V_193 -> V_194 ) ;
F_14 ( & exp -> V_125 ) ;
}
int F_118 ( struct V_96 * V_97 , struct V_1 * V_2 ,
struct V_63 * V_114 )
{
struct V_95 * V_98 ;
F_4 ( V_97 != NULL ) ;
F_4 ( V_2 != NULL ) ;
F_4 ( V_114 != NULL ) ;
V_98 = F_86 ( V_2 , V_114 ) ;
if ( F_28 ( V_98 ) )
return F_29 ( V_98 ) ;
V_97 -> V_100 = V_98 -> V_111 . V_197 ;
F_70 ( V_98 ) ;
F_17 ( V_36 , L_48 V_101 L_33 ,
V_114 -> V_64 , V_97 -> V_100 ) ;
return 0 ;
}
void F_119 ( struct V_95 * exp )
{
struct V_1 * V_2 = exp -> V_102 ;
F_11 ( & V_2 -> V_198 ) ;
if ( exp -> V_199 )
V_2 -> V_200 -- ;
if ( V_2 -> V_201 ) {
if ( exp -> V_202 ) {
F_11 ( & exp -> V_131 ) ;
exp -> V_202 = 0 ;
F_14 ( & exp -> V_131 ) ;
F_120 ( & V_2 -> V_203 ) ;
F_121 ( & V_2 -> V_203 ) ;
}
if ( exp -> V_204 &&
( F_122 ( exp ) & V_205 ) == 0 )
exp -> V_102 -> V_206 ++ ;
}
F_14 ( & V_2 -> V_198 ) ;
if ( exp -> V_207 ) {
F_11 ( & exp -> V_131 ) ;
exp -> V_207 = 0 ;
F_14 ( & exp -> V_131 ) ;
F_4 ( F_55 ( & V_2 -> V_208 ) ) ;
F_121 ( & V_2 -> V_208 ) ;
}
if ( exp -> V_209 ) {
F_11 ( & exp -> V_131 ) ;
exp -> V_209 = 0 ;
F_14 ( & exp -> V_131 ) ;
F_4 ( F_55 ( & V_2 -> V_210 ) ) ;
F_121 ( & V_2 -> V_210 ) ;
}
}
int F_123 ( struct V_95 * V_98 )
{
int V_211 ;
if ( V_98 == NULL ) {
F_124 ( L_49 , V_98 ) ;
return - V_45 ;
}
F_11 ( & V_98 -> V_131 ) ;
V_211 = V_98 -> V_212 ;
V_98 -> V_212 = 1 ;
F_14 ( & V_98 -> V_131 ) ;
if ( V_211 ) {
F_4 ( F_100 ( & V_98 -> V_134 ) ) ;
GOTO ( V_213 , V_211 ) ;
}
F_17 ( V_36 , L_50 V_101 L_33 ,
V_98 -> V_111 . V_197 ) ;
if ( ! F_100 ( & V_98 -> V_134 ) )
F_96 ( V_98 -> V_102 -> V_214 ,
& V_98 -> V_106 -> V_215 . V_216 ,
& V_98 -> V_134 ) ;
F_119 ( V_98 ) ;
F_101 ( V_98 ) ;
V_213:
F_70 ( V_98 ) ;
return 0 ;
}
int F_125 ( struct V_95 * exp )
{
if ( exp ) {
int V_217 ;
F_11 ( & exp -> V_131 ) ;
V_217 = ( exp -> V_117 > 0 ) ;
F_14 ( & exp -> V_131 ) ;
return V_217 ;
}
return 0 ;
}
static void F_126 ( struct V_12 * V_218 ,
enum V_219 V_220 )
{
int V_34 ;
struct V_95 * exp ;
while ( ! F_76 ( V_218 ) ) {
exp = F_13 ( V_218 -> V_79 , struct V_95 ,
V_113 ) ;
F_80 ( exp ) ;
F_11 ( & exp -> V_131 ) ;
exp -> V_221 = V_220 ;
F_14 ( & exp -> V_131 ) ;
if ( F_50 ( & exp -> V_105 ,
& exp -> V_102 -> V_63 ) ) {
F_17 ( V_222 ,
L_51 ,
exp ) ;
F_103 ( & exp -> V_113 ) ;
F_70 ( exp ) ;
continue;
}
F_80 ( exp ) ;
F_17 ( V_222 , L_52
L_53 V_223 L_33 ,
exp -> V_102 -> V_56 , F_127 ( exp ) ,
exp , exp -> V_130 ) ;
V_34 = F_128 ( exp ) ;
F_17 ( V_222 , L_54 ,
F_127 ( exp ) , exp , V_34 ) ;
F_70 ( exp ) ;
}
}
void F_129 ( struct V_1 * V_2 )
{
struct V_12 V_224 ;
F_88 ( & V_224 ) ;
F_11 ( & V_2 -> V_55 ) ;
F_130 ( & V_2 -> V_146 , & V_224 ) ;
F_130 ( & V_2 -> V_225 , & V_224 ) ;
F_14 ( & V_2 -> V_55 ) ;
if ( ! F_76 ( & V_224 ) ) {
F_17 ( V_222 , L_55
L_56 , V_2 -> V_57 , V_2 ) ;
F_126 ( & V_224 ,
F_131 ( V_2 ) ) ;
} else
F_17 ( V_222 , L_57 ,
V_2 -> V_57 , V_2 ) ;
}
void F_132 ( struct V_1 * V_2 ,
int (* F_133)( struct V_95 * ) )
{
struct V_12 V_224 ;
struct V_95 * exp , * V_226 ;
int V_227 = 0 ;
F_88 ( & V_224 ) ;
F_11 ( & V_2 -> V_55 ) ;
F_134 (exp, n, &obd->obd_exports,
exp_obd_chain) {
if ( F_50 ( & exp -> V_105 ,
& exp -> V_102 -> V_63 ) )
continue;
if ( exp -> V_228 . V_229 == - 1 )
continue;
F_11 ( & exp -> V_131 ) ;
if ( exp -> V_204 || F_133 ( exp ) ) {
F_14 ( & exp -> V_131 ) ;
continue;
}
exp -> V_204 = 1 ;
F_14 ( & exp -> V_131 ) ;
F_102 ( & exp -> V_113 , & V_224 ) ;
V_227 ++ ;
F_17 ( V_222 , L_58 ,
V_2 -> V_56 , exp -> V_105 . V_64 ,
exp -> V_106 == NULL ? L_59 :
F_135 ( exp -> V_106 -> V_215 . V_216 ) ) ;
F_136 ( exp , L_60 , 0 ) ;
}
F_14 ( & V_2 -> V_55 ) ;
if ( V_227 )
F_95 ( L_61 ,
V_2 -> V_56 , V_227 ) ;
F_126 ( & V_224 , F_131 ( V_2 ) |
V_230 ) ;
}
void F_137 ( struct V_95 * exp )
{
int V_34 , V_231 ;
F_11 ( & exp -> V_131 ) ;
V_231 = exp -> V_204 ;
exp -> V_204 = 1 ;
F_14 ( & exp -> V_131 ) ;
if ( V_231 ) {
F_17 ( V_222 , L_62 ,
exp , exp -> V_105 . V_64 ) ;
return;
}
F_17 ( V_222 , L_63 ,
exp , exp -> V_105 . V_64 ) ;
if ( V_232 )
F_138 () ;
F_80 ( exp ) ;
F_80 ( exp ) ;
V_34 = F_128 ( exp ) ;
if ( V_34 )
F_6 ( L_64 , exp , V_34 ) ;
else
F_17 ( V_222 , L_65 ,
exp , exp -> V_105 . V_64 ) ;
F_70 ( exp ) ;
}
char * F_127 ( struct V_95 * exp )
{
if ( exp -> V_106 != NULL )
return F_135 ( exp -> V_106 -> V_215 . V_216 ) ;
return L_66 ;
}
int F_139 ( struct V_1 * V_2 , const char * V_216 )
{
struct V_115 * V_233 ;
struct V_95 * V_234 = NULL ;
int V_235 = 0 ;
T_1 V_236 = F_140 ( ( char * ) V_216 ) ;
F_11 ( & V_2 -> V_55 ) ;
if ( V_2 -> V_70 ) {
F_14 ( & V_2 -> V_55 ) ;
return V_235 ;
}
V_233 = V_2 -> V_214 ;
F_93 ( V_233 ) ;
F_14 ( & V_2 -> V_55 ) ;
do {
V_234 = F_141 ( V_233 , & V_236 ) ;
if ( V_234 == NULL )
break;
F_5 ( V_234 -> V_106 -> V_215 . V_216 == V_236 ,
L_67 ,
F_127 ( V_234 ) ,
F_135 ( V_236 ) , V_216 ) ;
F_5 ( V_234 != V_2 -> V_87 ,
L_68 ) ;
V_235 ++ ;
F_95 ( L_69
L_70 , V_2 -> V_56 ,
F_142 ( & V_234 -> V_105 ) ,
F_127 ( V_234 ) ) ;
F_137 ( V_234 ) ;
F_70 ( V_234 ) ;
} while ( 1 );
F_98 ( V_233 ) ;
if ( ! V_235 )
F_17 ( V_222 , L_71 ,
V_2 -> V_56 , V_216 ) ;
return V_235 ;
}
int F_143 ( struct V_1 * V_2 , const char * V_64 )
{
struct V_115 * V_237 ;
struct V_95 * V_234 = NULL ;
struct V_63 V_238 ;
int V_235 = 0 ;
F_11 ( & V_2 -> V_55 ) ;
if ( V_2 -> V_70 ) {
F_14 ( & V_2 -> V_55 ) ;
return V_235 ;
}
V_237 = V_2 -> V_143 ;
F_93 ( V_237 ) ;
F_14 ( & V_2 -> V_55 ) ;
F_144 ( & V_238 , V_64 ) ;
if ( F_50 ( & V_238 , & V_2 -> V_63 ) ) {
F_6 ( L_72 , V_2 -> V_56 ) ;
F_98 ( V_237 ) ;
return V_235 ;
}
V_234 = F_141 ( V_237 , & V_238 ) ;
if ( V_234 == NULL ) {
F_6 ( L_73 ,
V_2 -> V_56 , V_64 ) ;
} else {
F_124 ( L_74 ,
V_2 -> V_56 , V_234 -> V_105 . V_64 ) ;
F_137 ( V_234 ) ;
F_70 ( V_234 ) ;
V_235 ++ ;
}
F_98 ( V_237 ) ;
return V_235 ;
}
static void F_136 ( struct V_95 * exp , const char * V_69 ,
int V_239 )
{
struct V_240 * V_241 ;
struct V_240 * V_242 = NULL ;
int V_243 = 0 ;
F_11 ( & exp -> V_131 ) ;
F_145 (rs, &exp->exp_outstanding_replies,
rs_exp_list) {
if ( V_243 == 0 )
V_242 = V_241 ;
V_243 ++ ;
}
F_14 ( & exp -> V_131 ) ;
F_17 ( V_222 , L_75 V_244 L_33 ,
exp -> V_102 -> V_56 , V_69 , exp , exp -> V_105 . V_64 ,
F_127 ( exp ) , F_55 ( & exp -> V_104 ) ,
F_55 ( & exp -> V_120 ) ,
F_55 ( & exp -> V_121 ) ,
F_55 ( & exp -> V_122 ) ,
exp -> V_212 , exp -> V_199 , exp -> V_204 ,
V_243 , V_242 , V_243 > 3 ? L_76 : L_77 ,
exp -> V_245 ) ;
#if V_123
if ( V_239 && V_246 != NULL )
V_246 ( exp ) ;
#endif
}
void F_146 ( struct V_1 * V_2 , int V_239 )
{
struct V_95 * exp ;
F_11 ( & V_2 -> V_55 ) ;
F_145 (exp, &obd->obd_exports, exp_obd_chain)
F_136 ( exp , L_78 , V_239 ) ;
F_145 (exp, &obd->obd_unlinked_exports, exp_obd_chain)
F_136 ( exp , L_79 , V_239 ) ;
F_145 (exp, &obd->obd_delayed_exports, exp_obd_chain)
F_136 ( exp , L_80 , V_239 ) ;
F_14 ( & V_2 -> V_55 ) ;
F_11 ( & V_247 ) ;
F_145 (exp, &obd_zombie_exports, exp_obd_chain)
F_136 ( exp , L_81 , V_239 ) ;
F_14 ( & V_247 ) ;
}
void F_147 ( struct V_1 * V_2 )
{
int V_248 = 2 ;
F_4 ( F_76 ( & V_2 -> V_146 ) ) ;
F_11 ( & V_2 -> V_55 ) ;
while ( ! F_76 ( & V_2 -> V_150 ) ) {
F_14 ( & V_2 -> V_55 ) ;
F_148 ( V_249 ) ;
F_149 ( F_150 ( V_248 ) ) ;
if ( V_248 > 5 && F_151 ( V_248 ) ) {
F_95 ( L_82
L_83
L_84 ,
V_2 -> V_56 , V_248 ,
F_55 ( & V_2 -> V_73 ) ) ;
F_146 ( V_2 , 1 ) ;
}
V_248 *= 2 ;
F_11 ( & V_2 -> V_55 ) ;
}
F_14 ( & V_2 -> V_55 ) ;
}
void F_152 ( void )
{
struct V_93 * V_162 ;
struct V_95 * V_98 ;
do {
F_11 ( & V_247 ) ;
V_162 = NULL ;
if ( ! F_76 ( & V_250 ) ) {
V_162 = F_13 ( V_250 . V_79 ,
struct V_93 ,
V_163 ) ;
F_103 ( & V_162 -> V_163 ) ;
}
V_98 = NULL ;
if ( ! F_76 ( & V_251 ) ) {
V_98 = F_13 ( V_251 . V_79 ,
struct V_95 ,
V_113 ) ;
F_103 ( & V_98 -> V_113 ) ;
}
F_14 ( & V_247 ) ;
if ( V_162 != NULL ) {
F_104 ( V_162 ) ;
F_11 ( & V_247 ) ;
V_252 -- ;
F_14 ( & V_247 ) ;
}
if ( V_98 != NULL ) {
F_73 ( V_98 ) ;
F_11 ( & V_247 ) ;
V_252 -- ;
F_14 ( & V_247 ) ;
}
F_153 () ;
} while ( V_162 != NULL || V_98 != NULL );
}
static int F_154 ( void * V_253 )
{
int V_34 ;
F_11 ( & V_247 ) ;
V_34 = ( V_252 == 0 ) &&
! F_155 ( V_254 , & V_255 ) ;
F_14 ( & V_247 ) ;
return V_34 ;
}
static void F_85 ( struct V_95 * exp ) {
F_11 ( & exp -> V_102 -> V_55 ) ;
F_4 ( ! F_76 ( & exp -> V_113 ) ) ;
F_103 ( & exp -> V_113 ) ;
F_14 ( & exp -> V_102 -> V_55 ) ;
F_11 ( & V_247 ) ;
V_252 ++ ;
F_31 ( & exp -> V_113 , & V_251 ) ;
F_14 ( & V_247 ) ;
F_156 () ;
}
static void F_108 ( struct V_93 * V_151 ) {
F_4 ( V_151 -> V_160 == NULL ) ;
F_4 ( V_151 -> V_256 == NULL ) ;
F_11 ( & V_247 ) ;
F_4 ( F_76 ( & V_151 -> V_163 ) ) ;
V_252 ++ ;
F_31 ( & V_151 -> V_163 , & V_250 ) ;
F_14 ( & V_247 ) ;
F_156 () ;
}
static void F_156 ( void )
{
F_157 ( & V_257 ) ;
}
static int F_158 ( void )
{
int V_34 ;
F_4 ( ! F_155 ( V_254 , & V_255 ) ) ;
F_11 ( & V_247 ) ;
V_34 = ( V_252 == 0 ) ;
F_14 ( & V_247 ) ;
return V_34 ;
}
void F_159 ( void )
{
struct V_258 V_259 = { 0 } ;
if ( V_260 == F_160 () )
return;
F_161 ( V_257 , F_158 () , & V_259 ) ;
}
static int F_162 ( void * V_261 )
{
F_163 () ;
F_164 ( & V_262 ) ;
V_260 = F_160 () ;
while ( ! F_155 ( V_254 , & V_255 ) ) {
struct V_258 V_259 = { 0 } ;
F_161 ( V_257 ,
! F_154 ( NULL ) , & V_259 ) ;
F_152 () ;
F_165 ( & V_257 ) ;
}
F_164 ( & V_263 ) ;
return 0 ;
}
int F_166 ( void )
{
struct V_264 * V_265 ;
F_88 ( & V_250 ) ;
F_88 ( & V_251 ) ;
F_26 ( & V_247 ) ;
F_167 ( & V_262 ) ;
F_167 ( & V_263 ) ;
F_114 ( & V_257 ) ;
V_260 = 0 ;
V_265 = F_168 ( F_162 , NULL , L_85 ) ;
if ( F_28 ( V_265 ) )
return F_29 ( V_265 ) ;
F_169 ( & V_262 ) ;
return 0 ;
}
void F_170 ( void )
{
F_171 ( V_254 , & V_255 ) ;
F_156 () ;
F_169 ( & V_263 ) ;
}
int F_172 ( int V_266 )
{
return sizeof( struct V_267 ) + V_266 ;
}
struct V_267 * F_173 ( void * V_268 )
{
struct V_267 * V_269 = ( (struct V_267 * ) V_268 ) - 1 ;
F_4 ( V_269 -> V_270 == V_271 ) ;
return V_269 ;
}
int F_174 ( void * V_268 )
{
struct V_267 * V_272 = ( (struct V_267 * ) V_268 ) - 1 ;
if ( V_272 -> V_270 == V_271 )
return 1 ;
else
return 0 ;
}
void * F_175 ( int V_266 , int V_273 , int type )
{
struct V_267 * V_269 ;
int V_274 = F_172 ( V_266 ) ;
F_24 ( V_269 , V_274 ) ;
if ( V_269 == NULL )
return F_39 ( - V_38 ) ;
V_269 -> V_270 = V_271 ;
V_269 -> V_275 = V_273 ;
V_269 -> V_276 = type ;
V_269 -> V_277 = V_274 ;
return ( void * ) ( V_269 + 1 ) ;
}
inline void F_176 ( void * V_268 , int V_266 )
{
struct V_267 * V_269 = F_173 ( V_268 ) ;
F_32 ( V_269 , F_172 ( V_266 ) ) ;
}
