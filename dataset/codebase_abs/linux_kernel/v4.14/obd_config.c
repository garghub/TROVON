int F_1 ( char * V_1 , char * V_2 , char * * V_3 )
{
char * V_4 ;
if ( ! V_1 )
return 1 ;
V_4 = strstr ( V_1 , V_2 ) ;
if ( ! V_4 )
return 1 ;
if ( V_3 )
* V_3 = V_4 + strlen ( V_2 ) ;
return 0 ;
}
static int F_2 ( char * V_1 , const char * V_2 , char * * V_3 )
{
if ( ! V_1 )
return 1 ;
if ( memcmp ( V_1 , V_2 , strlen ( V_2 ) ) != 0 )
return 1 ;
if ( V_3 )
* V_3 = V_1 + strlen ( V_2 ) ;
return 0 ;
}
static int F_3 ( char * V_1 , void * V_5 , int V_6 )
{
T_1 * V_7 = V_5 ;
* V_7 = F_4 ( V_1 ) ;
if ( * V_7 != V_8 )
return 0 ;
if ( ! V_6 )
F_5 ( 0x159 , L_1 , V_1 ) ;
return - V_9 ;
}
static int F_6 ( char * V_1 , void * V_5 )
{
T_2 * V_10 = V_5 ;
* V_10 = F_7 ( V_1 ) ;
F_8 ( V_11 , L_2 , F_9 ( * V_10 ) ) ;
return 0 ;
}
static int F_10 ( char * V_1 , int V_12 , void * V_5 , char * * V_13 ,
int V_6 )
{
char * V_14 ;
char V_15 ;
int V_16 = 0 ;
if ( ! V_1 )
return 1 ;
while ( * V_1 == ',' || * V_1 == ':' )
V_1 ++ ;
if ( * V_1 == ' ' || * V_1 == '/' || * V_1 == '\0' )
return 1 ;
V_14 = strpbrk ( V_1 , L_3 ) ;
if ( ! V_14 )
V_14 = V_1 + strlen ( V_1 ) ;
V_15 = * V_14 ;
* V_14 = '\0' ;
switch ( V_12 ) {
default:
F_11 () ;
case V_17 :
V_16 = F_3 ( V_1 , V_5 , V_6 ) ;
break;
case V_18 :
V_16 = F_6 ( V_1 , V_5 ) ;
break;
}
* V_14 = V_15 ;
if ( V_16 != 0 )
return V_16 ;
if ( V_13 )
* V_13 = V_14 ;
return 0 ;
}
int F_12 ( char * V_1 , T_1 * V_7 , char * * V_13 )
{
return F_10 ( V_1 , V_17 , ( void * ) V_7 , V_13 , 0 ) ;
}
int F_13 ( char * V_1 , T_1 * V_7 , char * * V_13 )
{
return F_10 ( V_1 , V_17 , ( void * ) V_7 , V_13 , 1 ) ;
}
char * F_14 ( struct V_19 * V_20 , T_3 V_21 )
{
char * V_22 ;
if ( ! V_20 -> V_23 [ V_21 ] )
return NULL ;
V_22 = F_15 ( V_20 , V_21 ) ;
if ( ! V_22 )
return NULL ;
if ( V_22 [ V_20 -> V_23 [ V_21 ] - 1 ] != '\0' ) {
T_4 V_24 = F_16 ( V_20 -> V_23 [ V_21 ] , 8 ) - 1 ;
char V_25 ;
if ( V_24 > V_20 -> V_23 [ V_21 ] )
V_24 = V_20 -> V_23 [ V_21 ] ;
V_25 = V_22 [ V_24 ] ;
V_22 [ V_24 ] = '\0' ;
if ( V_25 != '\0' ) {
F_17 ( L_4 ,
V_21 , V_22 , V_25 ) ;
}
}
return V_22 ;
}
static int F_18 ( struct V_19 * V_20 )
{
struct V_26 * V_27 = NULL ;
char * V_28 , * V_29 , * V_30 ;
int V_16 , V_31 ;
if ( ! F_19 ( V_20 , 1 ) ) {
F_20 ( L_5 ) ;
return - V_9 ;
}
V_28 = F_14 ( V_20 , 1 ) ;
if ( ! F_19 ( V_20 , 0 ) ) {
F_20 ( L_6 ) ;
return - V_9 ;
}
V_29 = F_14 ( V_20 , 0 ) ;
if ( ! F_19 ( V_20 , 2 ) ) {
F_20 ( L_7 ) ;
return - V_9 ;
}
V_30 = F_14 ( V_20 , 2 ) ;
F_8 ( V_32 , L_8 ,
F_21 ( V_28 ) , F_21 ( V_29 ) , F_21 ( V_30 ) ) ;
V_27 = F_22 ( V_28 , V_29 ) ;
if ( F_23 ( V_27 ) ) {
V_16 = F_24 ( V_27 ) ;
V_27 = NULL ;
F_20 ( L_9 ,
V_29 , V_28 , V_16 ) ;
goto V_33;
}
F_25 ( V_27 , L_10 ,
V_29 , V_28 ) ;
F_25 ( V_27 -> V_34 == V_35 ,
L_11 ,
V_27 , V_27 -> V_34 , V_35 ) ;
F_25 ( strncmp ( V_27 -> V_36 , V_29 , strlen ( V_29 ) ) == 0 ,
L_12 , V_27 , V_27 -> V_36 , V_29 ) ;
F_26 ( & V_27 -> V_37 ) ;
V_27 -> V_38 = 0 ;
V_27 -> V_39 = 0 ;
F_27 ( & V_27 -> V_40 ) ;
F_27 ( & V_27 -> V_41 ) ;
F_27 ( & V_27 -> V_42 ) ;
F_28 ( & V_27 -> V_43 ) ;
F_28 ( & V_27 -> V_44 ) ;
F_29 ( & V_27 -> V_45 ) ;
F_28 ( & V_27 -> V_46 ) ;
V_27 -> V_47 = F_30 ( - 1000 ) ;
F_31 ( & V_27 -> V_48 ) ;
F_32 ( & V_27 -> V_49 ) ;
F_33 ( & V_27 -> V_50 ) ;
V_27 -> V_51 = 0 ;
V_31 = strlen ( V_30 ) ;
if ( V_31 >= sizeof( V_27 -> V_52 ) ) {
F_20 ( L_13 ,
( int ) sizeof( V_27 -> V_52 ) ) ;
V_16 = - V_9 ;
goto V_33;
}
memcpy ( V_27 -> V_52 . V_30 , V_30 , V_31 ) ;
F_34 ( & V_27 -> V_44 ) ;
F_35 ( & V_27 -> V_53 , 1 ) ;
F_36 ( & V_27 -> V_44 ) ;
F_37 ( & V_27 -> V_54 ) ;
F_38 ( & V_27 -> V_54 , L_14 , V_27 ) ;
V_27 -> V_55 = 1 ;
F_8 ( V_32 , L_15 ,
V_27 -> V_56 , V_28 , F_39 ( & V_27 -> V_53 ) ) ;
return 0 ;
V_33:
if ( V_27 )
F_40 ( V_27 ) ;
return V_16 ;
}
static int F_41 ( struct V_26 * V_27 , struct V_19 * V_20 )
{
int V_57 = 0 ;
struct V_58 * exp ;
F_42 ( V_27 ) ;
F_25 ( V_27 == F_43 ( V_27 -> V_56 ) ,
L_16 ,
V_27 , V_27 -> V_56 , F_43 ( V_27 -> V_56 ) ) ;
F_25 ( V_27 -> V_34 == V_35 ,
L_17 ,
V_27 , V_27 -> V_34 , V_35 ) ;
if ( ! V_27 -> V_55 ) {
F_20 ( L_18 , V_27 -> V_56 ) ;
return - V_59 ;
}
if ( V_27 -> V_60 ) {
F_20 ( L_19 ,
V_27 -> V_56 , V_27 -> V_61 -> V_62 ) ;
return - V_63 ;
}
F_34 ( & V_27 -> V_44 ) ;
if ( V_27 -> V_64 ) {
F_36 ( & V_27 -> V_44 ) ;
F_20 ( L_20 ,
V_27 -> V_56 , V_27 -> V_61 -> V_62 ) ;
return - V_63 ;
}
V_27 -> V_64 = 1 ;
V_27 -> V_65 = NULL ;
F_36 ( & V_27 -> V_44 ) ;
V_27 -> V_65 = F_44 ( L_21 ,
V_66 ,
V_67 ,
V_68 , 0 ,
V_69 ,
V_70 ,
& V_71 , V_72 ) ;
if ( ! V_27 -> V_65 ) {
V_57 = - V_73 ;
goto V_74;
}
exp = F_45 ( V_27 , & V_27 -> V_52 ) ;
if ( F_23 ( exp ) ) {
V_57 = F_24 ( exp ) ;
goto V_74;
}
V_27 -> V_75 = exp ;
F_46 ( exp ) ;
V_57 = F_47 ( V_27 , V_20 ) ;
if ( V_57 )
goto V_76;
V_27 -> V_60 = 1 ;
F_34 ( & V_27 -> V_44 ) ;
F_48 ( V_27 , L_22 , V_27 ) ;
F_36 ( & V_27 -> V_44 ) ;
F_8 ( V_32 , L_23 ,
V_27 -> V_36 , V_27 -> V_52 . V_30 ) ;
return 0 ;
V_76:
if ( V_27 -> V_75 ) {
F_49 ( V_27 -> V_75 ) ;
V_27 -> V_75 = NULL ;
}
V_74:
if ( V_27 -> V_65 ) {
F_50 ( V_27 -> V_65 ) ;
V_27 -> V_65 = NULL ;
}
V_27 -> V_64 = 0 ;
F_20 ( L_24 , V_27 -> V_36 , V_57 ) ;
return V_57 ;
}
static int F_51 ( struct V_26 * V_27 , struct V_19 * V_20 )
{
if ( V_27 -> V_60 ) {
F_20 ( L_25 , V_27 -> V_56 ) ;
return - V_77 ;
}
F_34 ( & V_27 -> V_44 ) ;
if ( ! V_27 -> V_55 ) {
F_36 ( & V_27 -> V_44 ) ;
F_20 ( L_26 , V_27 -> V_56 ) ;
return - V_59 ;
}
V_27 -> V_55 = 0 ;
F_36 ( & V_27 -> V_44 ) ;
F_8 ( V_32 , L_27 ,
V_27 -> V_36 , V_27 -> V_52 . V_30 ) ;
F_52 ( V_27 , L_14 , V_27 ) ;
return 0 ;
}
static int F_53 ( struct V_26 * V_27 , struct V_19 * V_20 )
{
int V_57 = 0 ;
char * V_78 ;
F_54 ( V_79 ) ;
if ( ! V_27 -> V_60 ) {
F_20 ( L_28 , V_27 -> V_56 ) ;
return - V_59 ;
}
F_34 ( & V_27 -> V_44 ) ;
if ( V_27 -> V_80 ) {
F_36 ( & V_27 -> V_44 ) ;
F_20 ( L_29 , V_27 -> V_56 ) ;
return - V_59 ;
}
V_27 -> V_80 = 1 ;
F_36 ( & V_27 -> V_44 ) ;
while ( V_27 -> V_51 > 0 )
F_55 () ;
F_56 () ;
if ( V_20 -> V_81 >= 2 && F_19 ( V_20 , 1 ) > 0 ) {
for ( V_78 = F_14 ( V_20 , 1 ) ; * V_78 != 0 ; V_78 ++ )
switch ( * V_78 ) {
case 'F' :
V_27 -> V_82 = 1 ;
break;
case 'A' :
F_57 ( L_30 ,
V_27 -> V_36 ) ;
V_27 -> V_83 = 1 ;
V_27 -> V_84 = 1 ;
V_27 -> V_85 = 1 ;
if ( F_58 ( V_27 , V_86 ) ) {
F_59 ( V_87 ,
V_27 -> V_75 ,
0 , NULL , NULL ) ;
}
break;
default:
F_20 ( L_31 , * V_78 ) ;
}
}
F_42 ( V_27 -> V_75 ) ;
V_57 = F_60 ( V_27 ) ;
if ( V_57 )
F_20 ( L_32 ,
V_27 -> V_36 , V_57 ) ;
if ( V_27 -> V_65 ) {
F_50 ( V_27 -> V_65 ) ;
V_27 -> V_65 = NULL ;
}
F_52 ( V_27 , L_22 , V_27 ) ;
V_27 -> V_60 = 0 ;
return 0 ;
}
struct V_26 * F_48 ( struct V_26 * V_27 ,
const char * V_88 , const void * V_89 )
{
F_61 ( & V_27 -> V_54 , V_88 , V_89 ) ;
F_62 ( & V_27 -> V_53 ) ;
F_8 ( V_11 , L_33 , V_27 -> V_36 , V_27 ,
F_39 ( & V_27 -> V_53 ) ) ;
return V_27 ;
}
void F_52 ( struct V_26 * V_27 , const char * V_88 , const void * V_89 )
{
int V_57 ;
int V_90 ;
F_34 ( & V_27 -> V_44 ) ;
F_63 ( & V_27 -> V_53 ) ;
V_90 = F_39 ( & V_27 -> V_53 ) ;
F_36 ( & V_27 -> V_44 ) ;
F_64 ( & V_27 -> V_54 , V_88 , V_89 ) ;
F_8 ( V_11 , L_34 , V_27 -> V_36 , V_27 , V_90 ) ;
if ( ( V_90 == 1 ) && V_27 -> V_80 ) {
F_34 ( & V_27 -> V_75 -> V_91 ) ;
V_27 -> V_75 -> V_92 |= F_65 ( V_27 ) ;
F_36 ( & V_27 -> V_75 -> V_91 ) ;
F_49 ( V_27 -> V_75 ) ;
return;
}
if ( V_90 == 0 ) {
F_8 ( V_93 , L_35 ,
V_27 -> V_36 , V_27 -> V_52 . V_30 ) ;
F_42 ( ! V_27 -> V_55 ) ;
if ( V_27 -> V_80 ) {
V_57 = F_66 ( V_27 ) ;
if ( V_57 )
F_20 ( L_36 ,
V_27 -> V_36 , V_57 ) ;
}
F_40 ( V_27 ) ;
}
}
static int F_67 ( struct V_26 * V_27 , struct V_19 * V_20 )
{
struct V_94 * V_95 ;
struct V_52 V_30 ;
int V_16 ;
if ( F_19 ( V_20 , 1 ) < 1 ||
F_19 ( V_20 , 1 ) > sizeof( struct V_52 ) ) {
F_20 ( L_37 ) ;
return - V_9 ;
}
if ( strcmp ( V_27 -> V_61 -> V_62 , V_96 ) &&
strcmp ( V_27 -> V_61 -> V_62 , V_97 ) &&
strcmp ( V_27 -> V_61 -> V_62 , V_98 ) &&
strcmp ( V_27 -> V_61 -> V_62 , V_99 ) &&
strcmp ( V_27 -> V_61 -> V_62 , V_100 ) ) {
F_20 ( L_38 ) ;
return - V_9 ;
}
V_95 = V_27 -> V_101 . V_102 . V_103 ;
if ( ! V_95 ) {
F_20 ( L_39 ) ;
return - V_9 ;
}
F_68 ( & V_30 , F_14 ( V_20 , 1 ) ) ;
V_16 = F_69 ( V_95 , & V_30 , V_20 -> V_104 ) ;
return V_16 ;
}
static int F_70 ( struct V_26 * V_27 , struct V_19 * V_20 )
{
struct V_94 * V_95 ;
struct V_52 V_30 ;
int V_16 ;
if ( F_19 ( V_20 , 1 ) < 1 ||
F_19 ( V_20 , 1 ) > sizeof( struct V_52 ) ) {
F_20 ( L_37 ) ;
return - V_9 ;
}
if ( strcmp ( V_27 -> V_61 -> V_62 , V_96 ) &&
strcmp ( V_27 -> V_61 -> V_62 , V_97 ) ) {
F_20 ( L_40 ) ;
return - V_9 ;
}
V_95 = V_27 -> V_101 . V_102 . V_103 ;
if ( ! V_95 ) {
F_20 ( L_41 ) ;
return - V_9 ;
}
F_68 ( & V_30 , F_14 ( V_20 , 1 ) ) ;
V_16 = F_71 ( V_95 , & V_30 ) ;
return V_16 ;
}
struct V_105 * F_72 ( const char * V_106 )
{
struct V_105 * V_107 ;
F_34 ( & V_108 ) ;
F_73 (lprof, &lustre_profile_list, lp_list) {
if ( ! strcmp ( V_107 -> V_109 , V_106 ) ) {
V_107 -> V_110 ++ ;
F_36 ( & V_108 ) ;
return V_107 ;
}
}
F_36 ( & V_108 ) ;
return NULL ;
}
static int F_74 ( int V_111 , char * V_106 , int V_112 , char * V_113 ,
int V_114 , char * V_115 )
{
struct V_105 * V_107 ;
int V_57 = 0 ;
F_8 ( V_93 , L_42 , V_106 ) ;
V_107 = F_75 ( sizeof( * V_107 ) , V_116 ) ;
if ( ! V_107 )
return - V_73 ;
F_27 ( & V_107 -> V_117 ) ;
F_42 ( V_111 == ( strlen ( V_106 ) + 1 ) ) ;
V_107 -> V_109 = F_76 ( V_106 , V_111 , V_116 ) ;
if ( ! V_107 -> V_109 ) {
V_57 = - V_73 ;
goto V_118;
}
F_42 ( V_112 == ( strlen ( V_113 ) + 1 ) ) ;
V_107 -> V_119 = F_76 ( V_113 , V_112 , V_116 ) ;
if ( ! V_107 -> V_119 ) {
V_57 = - V_73 ;
goto V_120;
}
if ( V_114 > 0 ) {
F_42 ( V_114 == ( strlen ( V_115 ) + 1 ) ) ;
V_107 -> V_121 = F_76 ( V_115 , V_114 , V_116 ) ;
if ( ! V_107 -> V_121 ) {
V_57 = - V_73 ;
goto V_122;
}
}
F_34 ( & V_108 ) ;
V_107 -> V_110 = 1 ;
V_107 -> V_123 = false ;
F_77 ( & V_107 -> V_117 , & V_124 ) ;
F_36 ( & V_108 ) ;
return V_57 ;
V_122:
F_78 ( V_107 -> V_119 ) ;
V_120:
F_78 ( V_107 -> V_109 ) ;
V_118:
F_78 ( V_107 ) ;
return V_57 ;
}
void F_79 ( const char * V_106 )
{
struct V_105 * V_107 ;
F_8 ( V_93 , L_43 , V_106 ) ;
V_107 = F_72 ( V_106 ) ;
if ( V_107 ) {
F_34 ( & V_108 ) ;
V_107 -> V_110 -- ;
F_80 ( & V_107 -> V_117 ) ;
V_107 -> V_123 = true ;
F_36 ( & V_108 ) ;
F_81 ( V_107 ) ;
}
}
void F_81 ( struct V_105 * V_107 )
{
F_34 ( & V_108 ) ;
if ( -- V_107 -> V_110 > 0 ) {
F_42 ( V_107 -> V_110 > 0 ) ;
F_36 ( & V_108 ) ;
return;
}
F_36 ( & V_108 ) ;
F_42 ( ! V_107 -> V_110 ) ;
F_42 ( V_107 -> V_123 ) ;
F_78 ( V_107 -> V_109 ) ;
F_78 ( V_107 -> V_119 ) ;
F_78 ( V_107 -> V_121 ) ;
F_78 ( V_107 ) ;
}
void F_82 ( void )
{
struct V_105 * V_107 , * V_125 ;
F_34 ( & V_108 ) ;
F_83 (lprof, n, &lustre_profile_list, lp_list) {
F_80 ( & V_107 -> V_117 ) ;
V_107 -> V_123 = true ;
F_36 ( & V_108 ) ;
F_81 ( V_107 ) ;
F_34 ( & V_108 ) ;
}
F_36 ( & V_108 ) ;
}
static int F_84 ( char * V_4 , int V_126 , struct V_19 * V_20 )
{
if ( F_2 ( V_4 , V_127 , NULL ) == 0 )
V_128 = V_126 ;
else if ( F_2 ( V_4 , V_129 , NULL ) == 0 )
V_130 = V_126 ;
else if ( F_2 ( V_4 , V_131 , NULL ) == 0 )
V_132 = V_126 ;
else if ( F_2 ( V_4 , V_133 , NULL ) == 0 )
V_134 = V_126 ;
else if ( F_2 ( V_4 , V_135 , NULL ) == 0 )
V_136 = V_126 ;
else if ( F_2 ( V_4 , V_137 , NULL ) == 0 )
F_85 ( V_138 , F_14 ( V_20 , 2 ) ,
V_139 + 1 ) ;
else
return - V_9 ;
F_8 ( V_32 , L_44 , V_4 , V_126 ) ;
return 0 ;
}
void F_86 ( int (* F_87)( struct V_19 * V_20 ) )
{
V_140 = F_87 ;
}
static int F_88 ( struct V_19 * V_20 )
{
char * V_141 = F_14 ( V_20 , 1 ) ;
char * V_142 = F_14 ( V_20 , 2 ) ;
char * V_143 [] = {
[ 0 ] = L_45 ,
[ 1 ] = L_46 ,
[ 2 ] = V_141 ,
[ 3 ] = NULL
} ;
T_5 V_144 ;
T_5 V_145 ;
int V_16 ;
if ( strcmp ( V_142 , V_146 ) != 0 ) {
F_20 ( L_47 , V_142 ) ;
return - V_9 ;
}
V_144 = F_89 () ;
V_16 = F_90 ( V_143 [ 0 ] , V_143 , NULL , V_147 ) ;
V_145 = F_89 () ;
if ( V_16 < 0 ) {
F_20 (
L_48 ,
V_143 [ 0 ] , V_143 [ 1 ] , V_143 [ 2 ] , V_16 ,
( long ) F_91 ( V_145 , V_144 ) ) ;
} else {
F_8 ( V_148 , L_49 ,
V_143 [ 0 ] , V_143 [ 1 ] , V_143 [ 2 ] ,
( long ) F_91 ( V_145 , V_144 ) ) ;
V_16 = 0 ;
}
return V_16 ;
}
int F_92 ( struct V_19 * V_20 )
{
struct V_26 * V_27 ;
int V_57 ;
F_42 ( V_20 && ! F_23 ( V_20 ) ) ;
F_8 ( V_32 , L_50 , V_20 -> V_149 ) ;
switch ( V_20 -> V_149 ) {
case V_150 : {
V_57 = F_18 ( V_20 ) ;
goto V_33;
}
case V_151 : {
F_8 ( V_32 , L_51 ,
F_14 ( V_20 , 1 ) , V_20 -> V_152 ,
F_93 ( V_20 -> V_152 ) ) ;
V_57 = F_94 ( F_14 ( V_20 , 1 ) , V_20 -> V_152 ) ;
goto V_33;
}
case V_153 : {
F_8 ( V_32 , L_52 ,
( V_20 -> V_81 < 2 || F_19 ( V_20 , 1 ) == 0 )
? L_53 : F_14 ( V_20 , 1 ) ) ;
V_57 = F_95 ( F_14 ( V_20 , 1 ) ) ;
goto V_33;
}
case V_154 : {
F_8 ( V_32 , L_54 ,
F_14 ( V_20 , 1 ) ,
F_14 ( V_20 , 2 ) ,
F_14 ( V_20 , 3 ) ) ;
V_57 = F_74 ( F_19 ( V_20 , 1 ) ,
F_14 ( V_20 , 1 ) ,
F_19 ( V_20 , 2 ) ,
F_14 ( V_20 , 2 ) ,
F_19 ( V_20 , 3 ) ,
F_14 ( V_20 , 3 ) ) ;
goto V_33;
}
case V_155 : {
F_8 ( V_32 , L_55 ,
F_14 ( V_20 , 1 ) ) ;
F_79 ( F_14 ( V_20 , 1 ) ) ;
V_57 = 0 ;
goto V_33;
}
case V_156 : {
F_8 ( V_32 , L_56 ,
V_157 , V_20 -> V_104 ) ;
V_157 = F_96 ( V_20 -> V_104 , 1U ) ;
V_158 = 1 ;
V_57 = 0 ;
goto V_33;
}
case V_159 : {
V_57 = 0 ;
goto V_33;
}
case V_160 : {
F_5 ( 0x15a , L_57 ) ;
V_57 = 0 ;
goto V_33;
}
case V_161 : {
struct V_162 * V_163 ;
V_163 = F_15 ( V_20 , 1 ) ;
F_8 ( V_32 , L_58 , V_163 -> V_164 ,
V_163 -> V_165 , V_163 -> V_166 , V_163 -> V_167 ) ;
V_57 = 0 ;
goto V_33;
}
case V_168 : {
char * V_15 ;
if ( ( F_2 ( F_14 ( V_20 , 1 ) ,
V_169 , NULL ) == 0 ) &&
V_140 ) {
V_57 = (* V_140)( V_20 ) ;
goto V_33;
} else if ( ( F_2 ( F_14 ( V_20 , 1 ) ,
V_170 , & V_15 ) == 0 ) ) {
V_57 = F_84 ( V_15 , V_20 -> V_104 , V_20 ) ;
if ( V_57 != 0 )
F_17 ( L_59 , V_15 ) ;
V_57 = 0 ;
goto V_33;
} else if ( ( F_2 ( F_14 ( V_20 , 1 ) ,
V_171 , & V_15 ) == 0 ) &&
V_172 ) {
V_57 = (* V_172)( V_20 ) ;
goto V_33;
}
break;
}
case V_173 : {
V_57 = F_88 ( V_20 ) ;
goto V_33;
}
}
V_27 = F_97 ( F_14 ( V_20 , 0 ) ) ;
if ( ! V_27 ) {
if ( ! F_19 ( V_20 , 0 ) )
F_20 ( L_60 ) ;
else
F_20 ( L_61 ,
F_14 ( V_20 , 0 ) ) ;
V_57 = - V_9 ;
goto V_33;
}
switch ( V_20 -> V_149 ) {
case V_174 : {
V_57 = F_41 ( V_27 , V_20 ) ;
goto V_33;
}
case V_175 : {
V_57 = F_51 ( V_27 , V_20 ) ;
V_57 = 0 ;
goto V_33;
}
case V_176 : {
V_57 = F_53 ( V_27 , V_20 ) ;
V_57 = 0 ;
goto V_33;
}
case V_177 : {
V_57 = F_67 ( V_27 , V_20 ) ;
V_57 = 0 ;
goto V_33;
}
case V_178 : {
V_57 = F_70 ( V_27 , V_20 ) ;
V_57 = 0 ;
goto V_33;
}
case V_179 : {
V_57 = F_98 ( V_27 , F_14 ( V_20 , 2 ) ) ;
V_57 = 0 ;
goto V_33;
}
case V_180 : {
V_57 = F_99 ( V_27 , F_14 ( V_20 , 2 ) ,
F_14 ( V_20 , 3 ) ) ;
V_57 = 0 ;
goto V_33;
}
case V_181 : {
V_57 = F_100 ( V_27 , F_14 ( V_20 , 2 ) ,
F_14 ( V_20 , 3 ) ) ;
V_57 = 0 ;
goto V_33;
}
case V_182 : {
V_57 = F_101 ( V_27 , F_14 ( V_20 , 2 ) ) ;
V_57 = 0 ;
goto V_33;
}
default: {
V_57 = F_102 ( V_27 , sizeof( * V_20 ) , V_20 ) ;
goto V_33;
}
}
V_33:
if ( ( V_57 < 0 ) && ! ( V_20 -> V_149 & V_183 ) ) {
F_17 ( L_62 , V_57 ,
V_20 -> V_149 ) ;
V_57 = 0 ;
}
return V_57 ;
}
int F_103 ( char * V_184 , struct V_185 * V_186 ,
struct V_19 * V_20 , void * V_187 )
{
struct V_185 * V_188 ;
struct V_189 V_190 ;
struct V_191 V_192 ;
char * V_2 , * V_193 ;
int V_194 , V_195 , V_196 ;
int V_197 = 0 , V_198 = 0 ;
int V_16 = 0 ;
int V_199 = 0 ;
if ( V_20 -> V_149 != V_168 ) {
F_20 ( L_63 , V_20 -> V_149 ) ;
return - V_9 ;
}
V_190 . V_200 = & V_192 ;
V_192 . V_201 = V_187 ;
for ( V_194 = 1 ; V_194 < V_20 -> V_81 ; V_194 ++ ) {
V_2 = F_15 ( V_20 , V_194 ) ;
if ( F_2 ( V_2 , V_184 , & V_2 ) ) {
return - V_202 ;
}
V_193 = strchr ( V_2 , '=' ) ;
if ( ! V_193 || ( * ( V_193 + 1 ) == 0 ) ) {
F_20 ( L_64 , V_2 ) ;
continue;
}
V_195 = V_193 - V_2 ;
V_193 ++ ;
V_196 = strlen ( V_193 ) ;
V_197 = 0 ;
V_198 = 0 ;
while ( V_186 [ V_198 ] . V_29 ) {
V_188 = & V_186 [ V_198 ] ;
if ( ! F_2 ( V_2 , V_188 -> V_29 , NULL ) &&
V_195 == strlen ( V_188 -> V_29 ) ) {
V_197 ++ ;
V_16 = - V_203 ;
if ( V_188 -> V_204 && V_188 -> V_204 -> V_205 ) {
T_6 V_206 ;
V_206 = F_104 () ;
F_105 ( V_207 ) ;
V_16 = V_188 -> V_204 -> V_205 ( & V_190 ,
( const char V_208 * ) V_193 ,
V_196 , NULL ) ;
F_105 ( V_206 ) ;
}
break;
}
V_198 ++ ;
}
if ( ! V_197 ) {
F_20 ( L_65 ,
( int ) strlen ( V_184 ) - 1 , V_184 ,
( char * ) F_14 ( V_20 , 0 ) , V_2 ) ;
V_199 ++ ;
} else if ( V_16 < 0 ) {
F_20 ( L_66 ,
V_184 , V_188 -> V_29 , V_16 ) ;
V_16 = 0 ;
} else {
F_8 ( V_93 , L_67 ,
F_14 ( V_20 , 0 ) ,
( int ) strlen ( V_184 ) - 1 , V_184 ,
( int ) ( V_193 - V_2 - 1 ) , V_2 , V_193 ) ;
}
}
if ( V_16 > 0 )
V_16 = 0 ;
if ( ! V_16 && V_199 )
V_16 = V_199 ;
return V_16 ;
}
int F_106 ( const struct V_209 * V_210 ,
struct V_211 * V_212 ,
struct V_213 * V_214 , void * V_187 )
{
struct V_215 * V_216 = V_187 ;
int V_217 = V_214 -> V_218 ;
char * V_219 = ( char * ) ( V_214 + 1 ) ;
int V_16 = 0 ;
switch ( V_214 -> V_220 ) {
case V_221 : {
struct V_19 * V_20 , * V_222 ;
struct V_223 V_224 ;
char * V_225 = NULL ;
int V_226 = 0 ;
T_4 V_227 ;
int V_228 = 0 ;
V_20 = (struct V_19 * ) V_219 ;
if ( V_20 -> V_229 == F_107 ( V_230 ) ) {
F_108 ( V_20 ) ;
V_228 = 1 ;
}
V_16 = F_109 ( V_219 , V_217 ) ;
if ( V_16 )
goto V_33;
if ( V_20 -> V_149 == V_161 ) {
struct V_162 * V_163 = F_15 ( V_20 , 1 ) ;
F_110 ( V_163 , V_228 ,
F_19 ( V_20 , 1 ) ) ;
F_8 ( V_93 , L_68 ,
V_216 -> V_231 , V_163 -> V_165 ) ;
if ( V_163 -> V_165 & V_232 ) {
V_216 -> V_231 = V_233 ;
if ( V_163 -> V_165 & V_234 ) {
V_216 -> V_231 |= V_235 ;
F_8 ( V_93 , L_69 ,
V_163 -> V_164 ) ;
} else if ( ( V_163 -> V_165 & V_236 ) ||
( V_216 -> V_237 &&
F_111 ( V_216 -> V_237 ,
V_163 -> V_166 ) ) ) {
V_216 -> V_231 |= V_238 ;
F_8 ( V_93 , L_70 ,
V_163 -> V_164 ) ;
}
} else if ( V_163 -> V_165 & V_239 ) {
V_216 -> V_231 = 0 ;
}
}
if ( ! ( V_216 -> V_231 & V_240 ) &&
! ( V_216 -> V_231 & V_233 ) &&
( V_20 -> V_149 != V_161 ) ) {
F_17 ( L_71 ,
V_216 -> V_241 ,
V_216 -> V_242 . V_30 , V_216 -> V_231 ) ;
V_216 -> V_231 |= V_235 ;
}
if ( V_216 -> V_231 & V_235 ) {
F_8 ( V_93 , L_72 ,
V_216 -> V_231 ) ;
V_16 = 0 ;
break;
}
{
char * V_28 = F_14 ( V_20 , 1 ) ;
char * V_21 = F_14 ( V_20 , 2 ) ;
if ( ( V_20 -> V_149 == V_150 && V_28 &&
strcmp ( V_28 , L_73 ) == 0 ) ) {
F_17 ( L_74 ) ;
V_28 [ 2 ] = 't' ;
}
if ( ( V_20 -> V_149 == V_174 && V_21 &&
strcmp ( V_21 , L_75 ) == 0 ) ) {
F_8 ( V_11 , L_76 ) ;
V_21 [ 0 ] = '0' ;
V_21 [ 1 ] = 0 ;
}
}
if ( V_216 -> V_231 & V_238 ) {
F_8 ( V_93 , L_77 ,
V_20 -> V_149 ) ;
if ( V_20 -> V_149 == V_243 )
V_20 -> V_149 = V_244 ;
}
F_112 ( & V_224 , V_20 ) ;
if ( V_216 && V_216 -> V_241 &&
F_19 ( V_20 , 0 ) > 0 ) {
V_226 = F_19 ( V_20 , 0 ) +
sizeof( V_216 -> V_241 ) * 2 + 4 ;
V_225 = F_113 ( V_116 , L_78 ,
F_14 ( V_20 , 0 ) ,
V_216 -> V_241 ) ;
if ( ! V_225 ) {
V_16 = - V_73 ;
goto V_33;
}
F_114 ( & V_224 , 0 , V_225 ) ;
F_8 ( V_93 , L_79 ,
V_20 -> V_149 , V_225 ) ;
}
if ( V_216 && V_216 -> V_241 &&
V_20 -> V_149 == V_150 ) {
F_114 ( & V_224 , 2 ,
V_216 -> V_242 . V_30 ) ;
}
if ( V_216 && ! V_216 -> V_241 &&
V_20 -> V_149 == V_245 ) {
F_115 ( & V_224 , 2 , V_224 . V_246 [ 1 ] ,
V_224 . V_247 [ 1 ] ) ;
F_115 ( & V_224 , 1 , V_224 . V_246 [ 0 ] ,
V_224 . V_247 [ 0 ] ) ;
F_114 ( & V_224 , 0 ,
V_216 -> V_248 ) ;
}
V_227 = F_116 ( V_224 . V_81 , V_224 . V_247 ) ;
V_222 = F_75 ( V_227 , V_116 ) ;
if ( ! V_222 ) {
V_16 = - V_73 ;
goto V_33;
}
F_117 ( V_222 , V_20 -> V_149 , & V_224 ) ;
V_222 -> V_104 = V_20 -> V_104 ;
V_222 -> V_249 = V_20 -> V_249 ;
if ( V_20 -> V_250 != 0 &&
( V_20 -> V_152 >> 32 ) == 0 ) {
T_2 V_251 = ( T_2 ) ( V_20 -> V_152 & 0xffffffff ) ;
V_222 -> V_152 =
F_118 ( F_119 ( V_20 -> V_250 , 0 ) , V_251 ) ;
F_17 ( L_80 ,
V_20 -> V_250 , V_251 ,
F_93 ( V_222 -> V_152 ) ) ;
} else {
V_222 -> V_152 = V_20 -> V_152 ;
}
V_222 -> V_250 = 0 ;
V_16 = F_92 ( V_222 ) ;
F_78 ( V_222 ) ;
F_78 ( V_225 ) ;
break;
}
default:
F_20 ( L_81 ,
V_214 -> V_220 ) ;
break;
}
V_33:
if ( V_16 ) {
F_20 ( L_82 ,
V_212 -> V_252 -> V_253 -> V_36 , V_16 ) ;
F_120 ( NULL , V_212 , V_214 , V_187 ) ;
}
return V_16 ;
}
int F_121 ( const struct V_209 * V_210 , struct V_254 * V_255 ,
char * V_29 , struct V_215 * V_256 )
{
struct V_257 V_258 = { 0 , 0 } ;
struct V_211 * V_259 ;
T_7 V_260 ;
int V_16 ;
F_8 ( V_11 , L_83 , V_29 ) ;
V_16 = F_122 ( V_210 , V_255 , & V_259 , NULL , V_29 , V_261 ) ;
if ( V_16 )
return V_16 ;
V_16 = F_123 ( V_210 , V_259 , V_262 , NULL ) ;
if ( V_16 )
goto V_263;
if ( V_256 ) {
V_258 . V_264 = V_256 -> V_265 ;
V_260 = V_256 -> V_266 ;
F_42 ( V_260 ) ;
} else {
V_260 = F_106 ;
}
V_258 . V_267 = 0 ;
V_16 = F_124 ( V_210 , V_259 , V_260 , V_256 , & V_258 ) ;
F_8 ( V_93 , L_84 , V_29 ,
V_258 . V_264 + 1 , V_258 . V_267 , V_16 ) ;
if ( V_256 )
V_256 -> V_265 = V_258 . V_267 ;
V_263:
F_125 ( V_210 , V_259 ) ;
return V_16 ;
}
static int F_126 ( struct V_213 * V_214 , char * V_1 ,
int V_268 )
{
struct V_19 * V_20 = (struct V_19 * ) ( V_214 + 1 ) ;
char * V_4 = V_1 ;
char * V_145 = V_1 + V_268 ;
int V_16 = 0 ;
F_42 ( V_214 -> V_220 == V_221 ) ;
V_16 = F_109 ( V_20 , V_214 -> V_218 ) ;
if ( V_16 < 0 )
return V_16 ;
V_4 += snprintf ( V_4 , V_145 - V_4 , L_85 , V_20 -> V_149 ) ;
if ( V_20 -> V_249 )
V_4 += snprintf ( V_4 , V_145 - V_4 , L_86 ,
V_20 -> V_249 ) ;
if ( V_20 -> V_104 )
V_4 += snprintf ( V_4 , V_145 - V_4 , L_87 , V_20 -> V_104 ) ;
if ( V_20 -> V_152 ) {
char V_269 [ V_270 ] ;
F_127 ( V_20 -> V_152 , V_269 , sizeof( V_269 ) ) ;
V_4 += snprintf ( V_4 , V_145 - V_4 , L_88 ,
V_269 , V_20 -> V_152 ) ;
}
if ( V_20 -> V_149 == V_161 ) {
struct V_162 * V_163 = F_15 ( V_20 , 1 ) ;
V_4 += snprintf ( V_4 , V_145 - V_4 , L_89 ,
V_163 -> V_164 , V_163 -> V_165 ,
V_163 -> V_166 , V_163 -> V_167 ) ;
} else {
int V_194 ;
for ( V_194 = 0 ; V_194 < V_20 -> V_81 ; V_194 ++ ) {
V_4 += snprintf ( V_4 , V_145 - V_4 , L_90 , V_194 ,
F_14 ( V_20 , V_194 ) ) ;
}
}
V_4 += snprintf ( V_4 , V_145 - V_4 , L_91 ) ;
V_16 = V_4 - V_1 ;
return V_16 ;
}
int F_120 ( const struct V_209 * V_210 ,
struct V_211 * V_212 ,
struct V_213 * V_214 , void * V_187 )
{
char * V_271 ;
int V_16 = 0 ;
V_271 = F_75 ( 256 , V_116 ) ;
if ( ! V_271 )
return - V_73 ;
if ( V_214 -> V_220 == V_221 ) {
F_126 ( V_214 , V_271 , 256 ) ;
F_128 ( V_272 , L_92 , V_271 ) ;
} else {
F_128 ( V_272 , L_93 , V_214 -> V_220 ) ;
V_16 = - V_9 ;
}
F_78 ( V_271 ) ;
return V_16 ;
}
int F_129 ( struct V_26 * V_27 )
{
char V_273 [ 3 ] = L_94 ;
struct V_19 * V_20 ;
struct V_223 V_224 ;
int V_16 ;
if ( ! V_27 ) {
F_20 ( L_95 ) ;
return - V_274 ;
}
if ( V_27 -> V_82 )
strcat ( V_273 , L_96 ) ;
if ( V_27 -> V_83 )
strcat ( V_273 , L_97 ) ;
F_8 ( V_93 , L_98 ,
V_27 -> V_36 , V_273 ) ;
F_130 ( & V_224 , V_27 -> V_36 ) ;
F_114 ( & V_224 , 1 , V_273 ) ;
V_20 = F_75 ( F_116 ( V_224 . V_81 , V_224 . V_247 ) ,
V_116 ) ;
if ( ! V_20 )
return - V_73 ;
F_117 ( V_20 , V_176 , & V_224 ) ;
V_16 = F_92 ( V_20 ) ;
if ( V_16 ) {
F_20 ( L_99 , V_16 , V_27 -> V_36 ) ;
goto V_33;
}
V_20 -> V_149 = V_175 ;
V_16 = F_92 ( V_20 ) ;
if ( V_16 )
F_20 ( L_100 , V_16 , V_27 -> V_36 ) ;
V_33:
F_78 ( V_20 ) ;
return V_16 ;
}
static unsigned int
F_131 ( struct V_275 * V_276 , const void * V_2 , unsigned int V_277 )
{
return F_132 ( ( (struct V_52 * ) V_2 ) -> V_30 ,
sizeof( ( (struct V_52 * ) V_2 ) -> V_30 ) , V_277 ) ;
}
static void *
F_133 ( struct V_278 * V_279 )
{
struct V_58 * exp ;
exp = F_134 ( V_279 , struct V_58 , V_280 ) ;
return & exp -> V_281 ;
}
static int
F_135 ( const void * V_2 , struct V_278 * V_279 )
{
struct V_58 * exp ;
F_42 ( V_2 ) ;
exp = F_134 ( V_279 , struct V_58 , V_280 ) ;
return F_136 ( V_2 , & exp -> V_281 ) &&
! exp -> V_282 ;
}
static void *
F_137 ( struct V_278 * V_279 )
{
return F_134 ( V_279 , struct V_58 , V_280 ) ;
}
static void
F_138 ( struct V_275 * V_276 , struct V_278 * V_279 )
{
struct V_58 * exp ;
exp = F_134 ( V_279 , struct V_58 , V_280 ) ;
F_139 ( exp ) ;
}
static void
F_140 ( struct V_275 * V_276 , struct V_278 * V_279 )
{
struct V_58 * exp ;
exp = F_134 ( V_279 , struct V_58 , V_280 ) ;
F_46 ( exp ) ;
}
