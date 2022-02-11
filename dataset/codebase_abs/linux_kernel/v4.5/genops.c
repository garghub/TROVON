static struct V_1 * F_1 ( void )
{
struct V_1 * V_2 ;
V_2 = F_2 ( V_3 , V_4 | V_5 ) ;
if ( V_2 != NULL )
V_2 -> V_6 = V_7 ;
return V_2 ;
}
static void F_3 ( struct V_1 * V_2 )
{
F_4 ( V_2 != NULL ) ;
F_5 ( V_2 -> V_6 == V_7 , L_1 ,
V_2 , V_2 -> V_6 , V_7 ) ;
if ( V_2 -> V_8 != NULL ) {
F_6 ( L_2 ,
V_2 , V_2 -> V_8 , V_2 -> V_9 ) ;
F_7 () ;
}
F_8 ( & V_2 -> V_10 ) ;
F_9 ( V_3 , V_2 ) ;
}
static struct V_11 * F_10 ( const char * V_12 )
{
struct V_13 * V_14 ;
struct V_11 * type ;
F_11 ( & V_15 ) ;
F_12 (tmp, &obd_types) {
type = F_13 ( V_14 , struct V_11 , V_16 ) ;
if ( strcmp ( type -> V_17 , V_12 ) == 0 ) {
F_14 ( & V_15 ) ;
return type ;
}
}
F_14 ( & V_15 ) ;
return NULL ;
}
static struct V_11 * F_15 ( const char * V_12 )
{
struct V_11 * type = F_10 ( V_12 ) ;
if ( ! type ) {
const char * V_18 = V_12 ;
if ( strcmp ( V_18 , L_3 ) == 0 )
V_18 = L_4 ;
if ( strcmp ( V_18 , V_19 ) == 0 )
V_18 = V_20 ;
if ( ! strncmp ( V_18 , V_21 , strlen ( V_21 ) ) )
V_18 = V_22 ;
if ( ! F_16 ( L_5 , V_18 ) ) {
F_17 ( V_23 , L_6 , V_18 ) ;
type = F_10 ( V_12 ) ;
} else {
F_18 ( 0x158 , L_7 ,
V_18 ) ;
}
}
if ( type ) {
F_11 ( & type -> V_24 ) ;
type -> V_25 ++ ;
F_19 ( type -> V_26 -> V_27 ) ;
F_14 ( & type -> V_24 ) ;
}
return type ;
}
void F_20 ( struct V_11 * type )
{
F_4 ( type ) ;
F_11 ( & type -> V_24 ) ;
type -> V_25 -- ;
F_21 ( type -> V_26 -> V_27 ) ;
F_14 ( & type -> V_24 ) ;
}
int F_22 ( struct V_28 * V_29 , struct V_30 * V_30 ,
const char * V_12 ,
struct V_31 * V_32 )
{
struct V_11 * type ;
int V_33 ;
F_4 ( F_23 ( V_12 , V_34 ) < V_34 ) ;
if ( F_10 ( V_12 ) ) {
F_17 ( V_35 , L_8 , V_12 ) ;
return - V_36 ;
}
V_33 = - V_37 ;
type = F_24 ( sizeof( * type ) , V_4 ) ;
if ( ! type )
return V_33 ;
type -> V_26 = F_24 ( sizeof( * type -> V_26 ) , V_4 ) ;
type -> V_38 = F_24 ( sizeof( * type -> V_38 ) , V_4 ) ;
type -> V_17 = F_24 ( strlen ( V_12 ) + 1 , V_4 ) ;
if ( ! type -> V_26 ||
! type -> V_38 ||
! type -> V_17 )
goto V_39;
* ( type -> V_26 ) = * V_29 ;
if ( V_30 )
* ( type -> V_38 ) = * V_30 ;
strcpy ( type -> V_17 , V_12 ) ;
F_25 ( & type -> V_24 ) ;
type -> V_40 = F_26 ( type -> V_17 ,
V_41 ,
NULL , type ) ;
if ( F_27 ( type -> V_40 ) ) {
V_33 = type -> V_40 ? F_28 ( type -> V_40 )
: - V_37 ;
type -> V_40 = NULL ;
goto V_39;
}
type -> V_42 = F_29 ( type -> V_17 , V_43 ) ;
if ( ! type -> V_42 ) {
V_33 = - V_37 ;
goto V_39;
}
if ( V_32 != NULL ) {
type -> V_44 = V_32 ;
V_33 = F_30 ( V_32 ) ;
if ( V_33 != 0 )
goto V_39;
}
F_11 ( & V_15 ) ;
F_31 ( & type -> V_16 , & V_45 ) ;
F_14 ( & V_15 ) ;
return 0 ;
V_39:
if ( type -> V_42 )
F_32 ( type -> V_42 ) ;
F_33 ( type -> V_17 ) ;
F_33 ( type -> V_38 ) ;
F_33 ( type -> V_26 ) ;
F_33 ( type ) ;
return V_33 ;
}
int F_34 ( const char * V_12 )
{
struct V_11 * type = F_10 ( V_12 ) ;
if ( ! type ) {
F_6 ( L_9 ) ;
return - V_46 ;
}
if ( type -> V_25 ) {
F_6 ( L_10 , V_12 , type -> V_25 ) ;
F_33 ( type -> V_26 ) ;
F_33 ( type -> V_38 ) ;
return - V_47 ;
}
if ( type -> V_42 )
F_32 ( type -> V_42 ) ;
if ( ! F_27 ( type -> V_40 ) )
F_35 ( & type -> V_40 ) ;
if ( type -> V_44 )
F_36 ( type -> V_44 ) ;
F_11 ( & V_15 ) ;
F_37 ( & type -> V_16 ) ;
F_14 ( & V_15 ) ;
F_33 ( type -> V_17 ) ;
F_33 ( type -> V_26 ) ;
F_33 ( type -> V_38 ) ;
F_33 ( type ) ;
return 0 ;
}
struct V_1 * F_38 ( const char * V_48 , const char * V_12 )
{
struct V_1 * V_49 = NULL ;
struct V_1 * V_50 ;
struct V_11 * type = NULL ;
int V_51 ;
int V_52 = 0 ;
if ( strlen ( V_12 ) >= V_53 ) {
F_6 ( L_11 , V_53 ) ;
return F_39 ( - V_46 ) ;
}
type = F_15 ( V_48 ) ;
if ( ! type ) {
F_6 ( L_12 , V_48 ) ;
return F_39 ( - V_54 ) ;
}
V_50 = F_1 () ;
if ( ! V_50 ) {
V_49 = F_39 ( - V_37 ) ;
goto V_55;
}
F_4 ( V_50 -> V_6 == V_7 ) ;
F_40 ( & V_56 ) ;
for ( V_51 = 0 ; V_51 < F_41 () ; V_51 ++ ) {
struct V_1 * V_2 = F_42 ( V_51 ) ;
if ( V_2 && ( strcmp ( V_12 , V_2 -> V_57 ) == 0 ) ) {
F_6 ( L_13 ,
V_12 , V_51 ) ;
if ( V_49 ) {
F_5 ( V_49 -> V_6 == V_7 ,
L_14 , V_49 ,
V_49 -> V_6 , V_7 ) ;
F_5 ( V_49 -> V_58 == V_52 ,
L_15 , V_49 ,
V_49 -> V_58 , V_52 ) ;
V_59 [ V_49 -> V_58 ] = NULL ;
V_49 -> V_57 [ 0 ] = '\0' ;
}
V_49 = F_39 ( - V_36 ) ;
break;
}
if ( ! V_49 && ! V_2 ) {
V_49 = V_50 ;
V_49 -> V_58 = V_51 ;
V_52 = V_51 ;
V_49 -> V_11 = type ;
strncpy ( V_49 -> V_57 , V_12 ,
sizeof( V_49 -> V_57 ) - 1 ) ;
V_59 [ V_51 ] = V_49 ;
}
}
F_43 ( & V_56 ) ;
if ( ! V_49 && V_51 >= F_41 () ) {
F_6 ( L_16 ,
F_41 () ) ;
V_49 = F_39 ( - V_60 ) ;
goto V_61;
}
if ( F_44 ( V_49 ) )
goto V_61;
F_17 ( V_35 , L_17 ,
V_49 -> V_57 , V_49 ) ;
return V_49 ;
V_61:
F_3 ( V_50 ) ;
V_55:
F_20 ( type ) ;
return V_49 ;
}
void F_45 ( struct V_1 * V_2 )
{
struct V_11 * V_11 = V_2 -> V_11 ;
F_5 ( V_2 -> V_6 == V_7 , L_14 ,
V_2 , V_2 -> V_6 , V_7 ) ;
F_5 ( V_2 == V_59 [ V_2 -> V_58 ] , L_18 ,
V_2 , V_2 -> V_58 , V_59 [ V_2 -> V_58 ] ) ;
F_4 ( V_11 != NULL ) ;
F_17 ( V_23 , L_19 ,
V_2 -> V_57 , V_2 -> V_58 , V_2 -> V_11 -> V_17 ) ;
F_40 ( & V_56 ) ;
V_59 [ V_2 -> V_58 ] = NULL ;
F_43 ( & V_56 ) ;
F_3 ( V_2 ) ;
F_20 ( V_11 ) ;
}
int F_46 ( const char * V_12 )
{
int V_51 ;
if ( ! V_12 )
return - 1 ;
F_47 ( & V_56 ) ;
for ( V_51 = 0 ; V_51 < F_41 () ; V_51 ++ ) {
struct V_1 * V_2 = F_42 ( V_51 ) ;
if ( V_2 && strcmp ( V_12 , V_2 -> V_57 ) == 0 ) {
F_4 ( V_2 -> V_6 == V_7 ) ;
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
struct V_1 * F_49 ( const char * V_12 )
{
int V_63 = F_46 ( V_12 ) ;
if ( V_63 < 0 || V_63 > F_41 () )
return NULL ;
return F_42 ( V_63 ) ;
}
int F_50 ( struct V_64 * V_65 )
{
int V_51 ;
F_47 ( & V_56 ) ;
for ( V_51 = 0 ; V_51 < F_41 () ; V_51 ++ ) {
struct V_1 * V_2 = F_42 ( V_51 ) ;
if ( V_2 && F_51 ( V_65 , & V_2 -> V_64 ) ) {
F_4 ( V_2 -> V_6 == V_7 ) ;
F_48 ( & V_56 ) ;
return V_51 ;
}
}
F_48 ( & V_56 ) ;
return - 1 ;
}
struct V_1 * F_42 ( int V_66 )
{
struct V_1 * V_2 = NULL ;
if ( V_66 < F_41 () ) {
V_2 = V_59 [ V_66 ] ;
if ( ! V_2 )
return NULL ;
F_5 ( V_2 -> V_6 == V_7 ,
L_14 ,
V_2 , V_2 -> V_6 , V_7 ) ;
F_5 ( V_2 -> V_58 == V_66 ,
L_20 ,
V_2 , V_2 -> V_58 , V_66 ) ;
}
return V_2 ;
}
struct V_1 * F_52 ( struct V_64 * V_67 ,
const char * V_17 ,
struct V_64 * V_68 )
{
int V_51 ;
F_47 ( & V_56 ) ;
for ( V_51 = 0 ; V_51 < F_41 () ; V_51 ++ ) {
struct V_1 * V_2 = F_42 ( V_51 ) ;
if ( ! V_2 )
continue;
if ( ( strncmp ( V_2 -> V_11 -> V_17 , V_17 ,
strlen ( V_17 ) ) == 0 ) ) {
if ( F_51 ( V_67 ,
& V_2 -> V_69 . V_70 . V_71 ) &&
( ( V_68 ) ? F_51 ( V_68 ,
& V_2 -> V_64 ) : 1 ) ) {
F_48 ( & V_56 ) ;
return V_2 ;
}
}
}
F_48 ( & V_56 ) ;
return NULL ;
}
struct V_1 * F_53 ( struct V_64 * V_68 , int * V_72 )
{
int V_51 ;
if ( ! V_72 )
V_51 = 0 ;
else if ( * V_72 >= 0 && * V_72 < F_41 () )
V_51 = * V_72 ;
else
return NULL ;
F_47 ( & V_56 ) ;
for (; V_51 < F_41 () ; V_51 ++ ) {
struct V_1 * V_2 = F_42 ( V_51 ) ;
if ( ! V_2 )
continue;
if ( F_51 ( V_68 , & V_2 -> V_64 ) ) {
if ( V_72 )
* V_72 = V_51 + 1 ;
F_48 ( & V_56 ) ;
return V_2 ;
}
}
F_48 ( & V_56 ) ;
return NULL ;
}
int F_54 ( const char * V_73 , int V_74 )
{
struct V_1 * V_2 ;
const char * type ;
int V_51 , V_33 = 0 , V_75 ;
F_4 ( V_74 > 0 ) ;
F_47 ( & V_56 ) ;
for ( V_51 = 0 ; V_51 < F_41 () ; V_51 ++ ) {
V_2 = F_42 ( V_51 ) ;
if ( ! V_2 || V_2 -> V_76 == 0 || V_2 -> V_77 )
continue;
type = V_2 -> V_11 -> V_17 ;
if ( strcmp ( type , V_78 ) != 0 &&
strcmp ( type , V_79 ) != 0 &&
strcmp ( type , V_22 ) != 0 &&
strcmp ( type , V_80 ) != 0 )
continue;
if ( strncmp ( V_2 -> V_57 , V_73 , V_74 ) )
continue;
F_55 ( V_2 , V_81 , V_2 ) ;
F_48 ( & V_56 ) ;
V_75 = F_56 ( NULL , V_2 -> V_82 ,
sizeof( V_83 ) ,
V_83 , 0 , NULL , NULL ) ;
V_33 = V_33 ? V_33 : V_75 ;
F_57 ( V_2 , V_81 , V_2 ) ;
F_47 ( & V_56 ) ;
}
F_48 ( & V_56 ) ;
return V_33 ;
}
void F_58 ( void )
{
F_59 ( V_3 ) ;
V_3 = NULL ;
F_59 ( V_84 ) ;
V_84 = NULL ;
F_59 ( V_85 ) ;
V_85 = NULL ;
}
int F_60 ( void )
{
F_4 ( ! V_3 ) ;
V_3 = F_61 ( L_21 ,
sizeof( struct V_1 ) ,
0 , 0 , NULL ) ;
if ( ! V_3 )
goto V_61;
F_4 ( ! V_84 ) ;
V_84 = F_61 ( L_22 , sizeof( struct V_86 ) ,
0 , 0 , NULL ) ;
if ( ! V_84 )
goto V_61;
F_4 ( ! V_85 ) ;
V_85 = F_61 ( L_23 ,
sizeof( struct V_87 ) ,
0 , 0 , NULL ) ;
if ( ! V_85 )
goto V_61;
return 0 ;
V_61:
F_58 () ;
return - V_37 ;
}
struct V_88 * F_62 ( struct V_89 * V_90 )
{
struct V_88 * V_91 ;
if ( ! V_90 ) {
F_17 ( V_92 , L_24 ) ;
return NULL ;
}
if ( V_90 -> V_93 == - 1 ) {
F_17 ( V_92 , L_25 ) ;
return NULL ;
}
F_17 ( V_23 , L_26 , V_90 -> V_93 ) ;
V_91 = F_63 ( V_90 -> V_93 ) ;
return V_91 ;
}
struct V_1 * F_64 ( struct V_88 * exp )
{
if ( exp )
return exp -> V_94 ;
return NULL ;
}
struct V_87 * F_65 ( struct V_88 * exp )
{
struct V_1 * V_2 = exp -> V_94 ;
if ( ! V_2 )
return NULL ;
return V_2 -> V_69 . V_70 . V_95 ;
}
static void F_66 ( struct V_88 * exp )
{
struct V_1 * V_2 = exp -> V_94 ;
F_67 ( & exp -> V_96 ) ;
F_4 ( V_2 != NULL ) ;
F_17 ( V_35 , L_27 , exp ,
exp -> V_97 . V_65 , V_2 -> V_57 ) ;
if ( exp -> V_98 )
F_68 ( exp -> V_98 ) ;
F_4 ( F_69 ( & exp -> V_99 ) ) ;
F_4 ( F_69 ( & exp -> V_100 ) ) ;
F_4 ( F_69 ( & exp -> V_101 ) ) ;
F_4 ( F_69 ( & exp -> V_102 ) ) ;
F_70 ( exp ) ;
F_57 ( V_2 , L_28 , exp ) ;
F_71 ( exp , sizeof( * exp ) , & exp -> V_103 ) ;
}
static void F_72 ( void * V_91 )
{
F_73 ( V_91 ) ;
}
struct V_88 * F_73 ( struct V_88 * exp )
{
F_74 ( & exp -> V_96 ) ;
F_17 ( V_23 , L_29 , exp ,
F_75 ( & exp -> V_96 ) ) ;
return exp ;
}
void F_76 ( struct V_88 * exp )
{
F_4 ( exp != NULL ) ;
F_77 ( & exp -> V_96 , 0 , V_104 ) ;
F_17 ( V_23 , L_30 , exp ,
F_75 ( & exp -> V_96 ) - 1 ) ;
if ( F_78 ( & exp -> V_96 ) ) {
F_4 ( ! F_69 ( & exp -> V_105 ) ) ;
F_17 ( V_35 , L_31 ,
exp , exp -> V_97 . V_65 ) ;
F_79 ( exp ) ;
F_80 ( exp ) ;
}
}
struct V_88 * F_81 ( struct V_1 * V_2 ,
struct V_64 * V_106 )
{
struct V_88 * V_91 ;
struct V_107 * V_108 = NULL ;
int V_33 = 0 ;
V_91 = F_24 ( sizeof( * V_91 ) , V_4 ) ;
if ( ! V_91 )
return F_39 ( - V_37 ) ;
V_91 -> V_109 = 0 ;
V_91 -> V_110 = NULL ;
V_91 -> V_111 = NULL ;
F_82 ( & V_91 -> V_96 , 2 ) ;
F_82 ( & V_91 -> V_112 , 0 ) ;
F_82 ( & V_91 -> V_113 , 0 ) ;
F_82 ( & V_91 -> V_114 , 0 ) ;
#if V_115
F_83 ( & V_91 -> V_116 ) ;
F_25 ( & V_91 -> V_117 ) ;
#endif
F_82 ( & V_91 -> V_118 , 0 ) ;
V_91 -> V_94 = V_2 ;
F_83 ( & V_91 -> V_99 ) ;
F_25 ( & V_91 -> V_119 ) ;
F_83 ( & V_91 -> V_100 ) ;
F_83 ( & V_91 -> V_101 ) ;
F_83 ( & V_91 -> V_103 . V_120 ) ;
F_83 ( & V_91 -> V_102 ) ;
F_84 ( & V_91 -> V_103 , & V_121 ) ;
F_25 ( & V_91 -> V_122 ) ;
F_25 ( & V_91 -> V_123 ) ;
F_85 ( & V_91 -> V_124 ) ;
F_25 ( & V_91 -> V_125 ) ;
F_83 ( & V_91 -> V_126 ) ;
V_91 -> V_127 = V_128 ;
V_91 -> V_129 . V_130 = V_131 ;
V_91 -> V_97 = * V_106 ;
F_86 ( V_91 ) ;
F_11 ( & V_2 -> V_56 ) ;
if ( V_2 -> V_77 ) {
V_33 = - V_54 ;
goto V_132;
}
V_108 = F_87 ( V_2 -> V_133 ) ;
if ( ! V_108 ) {
V_33 = - V_54 ;
goto V_132;
}
F_14 ( & V_2 -> V_56 ) ;
if ( ! F_51 ( V_106 , & V_2 -> V_64 ) ) {
V_33 = F_88 ( V_108 , V_106 , & V_91 -> V_124 ) ;
if ( V_33 != 0 ) {
F_89 ( L_32 ,
V_2 -> V_57 , V_106 -> V_65 , V_33 ) ;
V_33 = - V_134 ;
goto V_135;
}
}
F_11 ( & V_2 -> V_56 ) ;
if ( V_2 -> V_77 ) {
F_90 ( V_108 , V_106 , & V_91 -> V_124 ) ;
V_33 = - V_54 ;
goto V_132;
}
F_55 ( V_2 , L_28 , V_91 ) ;
F_31 ( & V_91 -> V_105 , & V_91 -> V_94 -> V_136 ) ;
V_91 -> V_94 -> V_137 ++ ;
F_14 ( & V_2 -> V_56 ) ;
F_91 ( V_108 ) ;
return V_91 ;
V_132:
F_14 ( & V_2 -> V_56 ) ;
V_135:
if ( V_108 )
F_91 ( V_108 ) ;
F_92 ( & V_91 -> V_103 ) ;
F_4 ( F_93 ( & V_91 -> V_124 ) ) ;
F_70 ( V_91 ) ;
F_33 ( V_91 ) ;
return F_39 ( V_33 ) ;
}
void F_94 ( struct V_88 * exp )
{
F_92 ( & exp -> V_103 ) ;
F_11 ( & exp -> V_94 -> V_56 ) ;
if ( ! F_93 ( & exp -> V_124 ) )
F_90 ( exp -> V_94 -> V_133 ,
& exp -> V_97 ,
& exp -> V_124 ) ;
F_95 ( & exp -> V_105 , & exp -> V_94 -> V_138 ) ;
exp -> V_94 -> V_137 -- ;
F_14 ( & exp -> V_94 -> V_56 ) ;
F_76 ( exp ) ;
}
static void F_96 ( struct V_87 * V_139 )
{
F_17 ( V_35 , L_33 , V_139 ,
V_139 -> V_140 -> V_57 ) ;
F_67 ( & V_139 -> V_141 ) ;
F_68 ( V_139 -> V_142 ) ;
while ( ! F_69 ( & V_139 -> V_143 ) ) {
struct V_144 * V_145 ;
V_145 = F_13 ( V_139 -> V_143 . V_72 ,
struct V_144 , V_146 ) ;
F_97 ( & V_145 -> V_146 ) ;
F_68 ( V_145 -> V_147 ) ;
F_33 ( V_145 ) ;
}
F_4 ( ! V_139 -> V_148 ) ;
F_57 ( V_139 -> V_140 , L_34 , V_139 ) ;
F_71 ( V_139 , sizeof( * V_139 ) , & V_139 -> V_149 ) ;
}
static void F_98 ( void * V_150 )
{
F_99 ( V_150 ) ;
}
struct V_87 * F_99 ( struct V_87 * V_150 )
{
F_74 ( & V_150 -> V_141 ) ;
F_17 ( V_23 , L_35 , V_150 ,
F_75 ( & V_150 -> V_141 ) ,
V_150 -> V_140 -> V_57 ) ;
return V_150 ;
}
void F_100 ( struct V_87 * V_139 )
{
F_4 ( F_69 ( & V_139 -> V_151 ) ) ;
F_77 ( & V_139 -> V_141 , 0 , V_104 ) ;
F_17 ( V_23 , L_35 , V_139 ,
F_75 ( & V_139 -> V_141 ) - 1 ,
V_139 -> V_140 -> V_57 ) ;
if ( F_78 ( & V_139 -> V_141 ) ) {
F_17 ( V_23 , L_36 , V_139 ) ;
F_101 ( V_139 ) ;
}
F_102 ( & V_139 -> V_141 , 0 , V_104 ) ;
}
static void F_103 ( struct V_152 * V_153 )
{
int V_51 ;
F_104 ( & V_153 -> V_154 , 0 , 0 ) ;
for ( V_51 = 0 ; V_51 < V_155 ; V_51 ++ ) {
F_104 ( & V_153 -> V_156 [ V_51 ] , V_157 ,
V_158 ) ;
}
}
struct V_87 * F_105 ( struct V_1 * V_2 )
{
struct V_87 * V_139 ;
V_139 = F_24 ( sizeof( * V_139 ) , V_4 ) ;
if ( ! V_139 )
return NULL ;
F_83 ( & V_139 -> V_159 ) ;
F_83 ( & V_139 -> V_151 ) ;
F_83 ( & V_139 -> V_160 ) ;
F_83 ( & V_139 -> V_161 ) ;
F_83 ( & V_139 -> V_162 ) ;
F_83 ( & V_139 -> V_163 ) ;
V_139 -> V_164 = & V_139 -> V_163 ;
F_25 ( & V_139 -> V_165 ) ;
V_139 -> V_166 = 0 ;
V_139 -> V_167 = V_168 ;
V_139 -> V_140 = F_55 ( V_2 , L_34 , V_139 ) ;
F_106 ( & V_139 -> V_169 ) ;
F_107 ( & V_139 -> V_170 ) ;
F_82 ( & V_139 -> V_141 , 2 ) ;
F_82 ( & V_139 -> V_171 , 0 ) ;
F_82 ( & V_139 -> V_172 , 0 ) ;
F_82 ( & V_139 -> V_173 , 0 ) ;
F_82 ( & V_139 -> V_174 , 0 ) ;
F_83 ( & V_139 -> V_143 ) ;
F_83 ( & V_139 -> V_149 . V_120 ) ;
F_84 ( & V_139 -> V_149 , & V_175 ) ;
F_103 ( & V_139 -> V_152 ) ;
V_139 -> V_176 = V_177 ;
return V_139 ;
}
void F_108 ( struct V_87 * V_150 )
{
F_4 ( V_150 != NULL ) ;
F_4 ( V_150 != V_178 ) ;
F_92 ( & V_150 -> V_149 ) ;
F_11 ( & V_150 -> V_165 ) ;
V_150 -> V_179 ++ ;
F_14 ( & V_150 -> V_165 ) ;
F_100 ( V_150 ) ;
}
void F_109 ( struct V_88 * exp , struct V_180 * V_181 )
{
F_11 ( & exp -> V_117 ) ;
F_4 ( V_181 -> V_182 >= 0 ) ;
if ( V_181 -> V_183 != NULL &&
V_181 -> V_183 != exp ) {
F_89 ( L_37 ,
exp , V_181 , V_181 -> V_183 ) ;
}
if ( ( V_181 -> V_182 ++ ) == 0 ) {
F_31 ( & V_181 -> V_184 , & exp -> V_116 ) ;
V_181 -> V_183 = exp ;
}
F_17 ( V_23 , L_38 ,
V_181 , exp , V_181 -> V_182 ) ;
F_14 ( & exp -> V_117 ) ;
}
void F_110 ( struct V_88 * exp , struct V_180 * V_181 )
{
F_11 ( & exp -> V_117 ) ;
F_4 ( V_181 -> V_182 > 0 ) ;
if ( V_181 -> V_183 != exp ) {
F_89 ( L_39 ,
V_181 , V_181 -> V_183 , exp ) ;
}
if ( -- V_181 -> V_182 == 0 ) {
F_97 ( & V_181 -> V_184 ) ;
V_181 -> V_183 = NULL ;
}
F_17 ( V_23 , L_38 ,
V_181 , exp , V_181 -> V_182 ) ;
F_14 ( & exp -> V_117 ) ;
}
int F_111 ( struct V_89 * V_90 , struct V_1 * V_2 ,
struct V_64 * V_106 )
{
struct V_88 * V_91 ;
F_4 ( V_90 != NULL ) ;
F_4 ( V_2 != NULL ) ;
F_4 ( V_106 != NULL ) ;
V_91 = F_81 ( V_2 , V_106 ) ;
if ( F_44 ( V_91 ) )
return F_28 ( V_91 ) ;
V_90 -> V_93 = V_91 -> V_103 . V_185 ;
F_76 ( V_91 ) ;
F_17 ( V_35 , L_40 ,
V_106 -> V_65 , V_90 -> V_93 ) ;
return 0 ;
}
int F_112 ( struct V_88 * V_91 )
{
int V_186 ;
if ( ! V_91 ) {
F_113 ( L_41 , V_91 ) ;
return - V_46 ;
}
F_11 ( & V_91 -> V_122 ) ;
V_186 = V_91 -> V_187 ;
V_91 -> V_187 = 1 ;
F_14 ( & V_91 -> V_122 ) ;
if ( V_186 )
goto V_188;
F_17 ( V_35 , L_42 ,
V_91 -> V_103 . V_185 ) ;
F_94 ( V_91 ) ;
V_188:
F_76 ( V_91 ) ;
return 0 ;
}
void F_114 ( struct V_88 * exp )
{
int V_33 , V_189 ;
F_11 ( & exp -> V_122 ) ;
V_189 = exp -> V_190 ;
exp -> V_190 = 1 ;
F_14 ( & exp -> V_122 ) ;
if ( V_189 ) {
F_17 ( V_191 , L_43 ,
exp , exp -> V_97 . V_65 ) ;
return;
}
F_17 ( V_191 , L_44 ,
exp , exp -> V_97 . V_65 ) ;
if ( V_192 )
F_115 () ;
F_73 ( exp ) ;
F_73 ( exp ) ;
V_33 = F_116 ( exp ) ;
if ( V_33 )
F_6 ( L_45 , exp , V_33 ) ;
else
F_17 ( V_191 , L_46 ,
exp , exp -> V_97 . V_65 ) ;
F_76 ( exp ) ;
}
static void F_117 ( void )
{
struct V_87 * V_150 ;
struct V_88 * V_91 ;
do {
F_11 ( & V_193 ) ;
V_150 = NULL ;
if ( ! F_69 ( & V_194 ) ) {
V_150 = F_13 ( V_194 . V_72 ,
struct V_87 ,
V_151 ) ;
F_97 ( & V_150 -> V_151 ) ;
}
V_91 = NULL ;
if ( ! F_69 ( & V_195 ) ) {
V_91 = F_13 ( V_195 . V_72 ,
struct V_88 ,
V_105 ) ;
F_97 ( & V_91 -> V_105 ) ;
}
F_14 ( & V_193 ) ;
if ( V_150 != NULL ) {
F_96 ( V_150 ) ;
F_11 ( & V_193 ) ;
V_196 -- ;
F_14 ( & V_193 ) ;
}
if ( V_91 != NULL ) {
F_66 ( V_91 ) ;
F_11 ( & V_193 ) ;
V_196 -- ;
F_14 ( & V_193 ) ;
}
F_118 () ;
} while ( V_150 != NULL || V_91 != NULL );
}
static int F_119 ( void * V_197 )
{
int V_33 ;
F_11 ( & V_193 ) ;
V_33 = ( V_196 == 0 ) &&
! F_120 ( V_198 , & V_199 ) ;
F_14 ( & V_193 ) ;
return V_33 ;
}
static void F_80 ( struct V_88 * exp )
{
F_11 ( & exp -> V_94 -> V_56 ) ;
F_4 ( ! F_69 ( & exp -> V_105 ) ) ;
F_97 ( & exp -> V_105 ) ;
F_14 ( & exp -> V_94 -> V_56 ) ;
F_11 ( & V_193 ) ;
V_196 ++ ;
F_31 ( & exp -> V_105 , & V_195 ) ;
F_14 ( & V_193 ) ;
F_121 () ;
}
static void F_101 ( struct V_87 * V_139 )
{
F_4 ( ! V_139 -> V_148 ) ;
F_11 ( & V_193 ) ;
F_4 ( F_69 ( & V_139 -> V_151 ) ) ;
V_196 ++ ;
F_31 ( & V_139 -> V_151 , & V_194 ) ;
F_14 ( & V_193 ) ;
F_121 () ;
}
static void F_121 ( void )
{
F_122 ( & V_200 ) ;
}
static int F_123 ( void )
{
int V_33 ;
F_4 ( ! F_120 ( V_198 , & V_199 ) ) ;
F_11 ( & V_193 ) ;
V_33 = ( V_196 == 0 ) ;
F_14 ( & V_193 ) ;
return V_33 ;
}
void F_124 ( void )
{
struct V_201 V_202 = { 0 } ;
if ( V_203 == F_125 () )
return;
F_126 ( V_200 , F_123 () , & V_202 ) ;
}
static int F_127 ( void * V_204 )
{
F_128 () ;
F_129 ( & V_205 ) ;
V_203 = F_125 () ;
while ( ! F_120 ( V_198 , & V_199 ) ) {
struct V_201 V_202 = { 0 } ;
F_126 ( V_200 ,
! F_119 ( NULL ) , & V_202 ) ;
F_117 () ;
F_130 ( & V_200 ) ;
}
F_129 ( & V_206 ) ;
return 0 ;
}
int F_131 ( void )
{
struct V_207 * V_208 ;
F_83 ( & V_194 ) ;
F_83 ( & V_195 ) ;
F_25 ( & V_193 ) ;
F_132 ( & V_205 ) ;
F_132 ( & V_206 ) ;
F_107 ( & V_200 ) ;
V_203 = 0 ;
V_208 = F_133 ( F_127 , NULL , L_47 ) ;
if ( F_44 ( V_208 ) )
return F_28 ( V_208 ) ;
F_134 ( & V_205 ) ;
return 0 ;
}
void F_135 ( void )
{
F_136 ( V_198 , & V_199 ) ;
F_121 () ;
F_134 ( & V_206 ) ;
}
