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
static int F_14 ( struct V_19 * V_20 )
{
struct V_21 * V_22 = NULL ;
char * V_23 , * V_24 , * V_25 ;
int V_16 , V_26 ;
if ( ! F_15 ( V_20 , 1 ) ) {
F_16 ( L_4 ) ;
return - V_9 ;
}
V_23 = F_17 ( V_20 , 1 ) ;
if ( ! F_15 ( V_20 , 0 ) ) {
F_16 ( L_5 ) ;
return - V_9 ;
}
V_24 = F_17 ( V_20 , 0 ) ;
if ( ! F_15 ( V_20 , 2 ) ) {
F_16 ( L_6 ) ;
return - V_9 ;
}
V_25 = F_17 ( V_20 , 2 ) ;
F_8 ( V_27 , L_7 ,
F_18 ( V_23 ) , F_18 ( V_24 ) , F_18 ( V_25 ) ) ;
V_22 = F_19 ( V_23 , V_24 ) ;
if ( F_20 ( V_22 ) ) {
V_16 = F_21 ( V_22 ) ;
V_22 = NULL ;
F_16 ( L_8 ,
V_24 , V_23 , V_16 ) ;
goto V_28;
}
F_22 ( V_22 , L_9 ,
V_24 , V_23 ) ;
F_22 ( V_22 -> V_29 == V_30 ,
L_10 ,
V_22 , V_22 -> V_29 , V_30 ) ;
F_22 ( strncmp ( V_22 -> V_31 , V_24 , strlen ( V_24 ) ) == 0 ,
L_11 , V_22 , V_22 -> V_31 , V_24 ) ;
F_23 ( & V_22 -> V_32 ) ;
V_22 -> V_33 = 0 ;
V_22 -> V_34 = 0 ;
F_24 ( & V_22 -> V_35 ) ;
F_24 ( & V_22 -> V_36 ) ;
F_24 ( & V_22 -> V_37 ) ;
F_25 ( & V_22 -> V_38 ) ;
F_25 ( & V_22 -> V_39 ) ;
F_26 ( & V_22 -> V_40 ) ;
F_25 ( & V_22 -> V_41 ) ;
V_22 -> V_42 = F_27 ( - 1000 ) ;
F_28 ( & V_22 -> V_43 ) ;
F_29 ( & V_22 -> V_44 ) ;
F_30 ( & V_22 -> V_45 , V_46 ) ;
V_22 -> V_47 = 0 ;
V_26 = strlen ( V_25 ) ;
if ( V_26 >= sizeof( V_22 -> V_48 ) ) {
F_16 ( L_12 ,
( int ) sizeof( V_22 -> V_48 ) ) ;
V_16 = - V_9 ;
goto V_28;
}
memcpy ( V_22 -> V_48 . V_25 , V_25 , V_26 ) ;
if ( F_31 ( V_22 , V_49 ) ) {
V_16 = F_31 ( V_22 , V_49 ) ( V_22 , sizeof( * V_20 ) , V_20 ) ;
if ( V_16 ) {
V_16 = - V_9 ;
goto V_28;
}
}
F_32 ( & V_22 -> V_39 ) ;
F_33 ( & V_22 -> V_50 , 1 ) ;
F_34 ( & V_22 -> V_39 ) ;
F_35 ( & V_22 -> V_51 ) ;
F_36 ( & V_22 -> V_51 , L_13 , V_22 ) ;
V_22 -> V_52 = 1 ;
F_8 ( V_27 , L_14 ,
V_22 -> V_53 , V_23 , F_37 ( & V_22 -> V_50 ) ) ;
return 0 ;
V_28:
if ( V_22 )
F_38 ( V_22 ) ;
return V_16 ;
}
static int F_39 ( struct V_21 * V_22 , struct V_19 * V_20 )
{
int V_54 = 0 ;
struct V_55 * exp ;
F_40 ( V_22 ) ;
F_22 ( V_22 == F_41 ( V_22 -> V_53 ) ,
L_15 ,
V_22 , V_22 -> V_53 , F_41 ( V_22 -> V_53 ) ) ;
F_22 ( V_22 -> V_29 == V_30 ,
L_16 ,
V_22 , V_22 -> V_29 , V_30 ) ;
if ( ! V_22 -> V_52 ) {
F_16 ( L_17 , V_22 -> V_53 ) ;
return - V_56 ;
}
if ( V_22 -> V_57 ) {
F_16 ( L_18 ,
V_22 -> V_53 , V_22 -> V_58 -> V_59 ) ;
return - V_60 ;
}
F_32 ( & V_22 -> V_39 ) ;
if ( V_22 -> V_61 ) {
F_34 ( & V_22 -> V_39 ) ;
F_16 ( L_19 ,
V_22 -> V_53 , V_22 -> V_58 -> V_59 ) ;
return - V_60 ;
}
V_22 -> V_61 = 1 ;
V_22 -> V_62 = NULL ;
F_34 ( & V_22 -> V_39 ) ;
V_22 -> V_62 = F_42 ( L_20 ,
V_63 ,
V_64 ,
V_65 , 0 ,
V_66 ,
V_67 ,
& V_68 , V_69 ) ;
if ( ! V_22 -> V_62 ) {
V_54 = - V_70 ;
goto V_71;
}
exp = F_43 ( V_22 , & V_22 -> V_48 ) ;
if ( F_20 ( exp ) ) {
V_54 = F_21 ( exp ) ;
goto V_71;
}
V_22 -> V_72 = exp ;
F_44 ( exp ) ;
V_54 = F_45 ( V_22 , V_20 ) ;
if ( V_54 )
goto V_73;
V_22 -> V_57 = 1 ;
F_32 ( & V_22 -> V_39 ) ;
F_46 ( V_22 , L_21 , V_22 ) ;
F_34 ( & V_22 -> V_39 ) ;
F_8 ( V_27 , L_22 ,
V_22 -> V_31 , V_22 -> V_48 . V_25 ) ;
return 0 ;
V_73:
if ( V_22 -> V_72 ) {
F_47 ( V_22 -> V_72 ) ;
V_22 -> V_72 = NULL ;
}
V_71:
if ( V_22 -> V_62 ) {
F_48 ( V_22 -> V_62 ) ;
V_22 -> V_62 = NULL ;
}
V_22 -> V_61 = 0 ;
F_16 ( L_23 , V_22 -> V_31 , V_54 ) ;
return V_54 ;
}
static int F_49 ( struct V_21 * V_22 , struct V_19 * V_20 )
{
if ( V_22 -> V_57 ) {
F_16 ( L_24 , V_22 -> V_53 ) ;
return - V_74 ;
}
F_32 ( & V_22 -> V_39 ) ;
if ( ! V_22 -> V_52 ) {
F_34 ( & V_22 -> V_39 ) ;
F_16 ( L_25 , V_22 -> V_53 ) ;
return - V_56 ;
}
V_22 -> V_52 = 0 ;
F_34 ( & V_22 -> V_39 ) ;
F_8 ( V_27 , L_26 ,
V_22 -> V_31 , V_22 -> V_48 . V_25 ) ;
F_50 ( V_22 , L_13 , V_22 ) ;
return 0 ;
}
static int F_51 ( struct V_21 * V_22 , struct V_19 * V_20 )
{
int V_54 = 0 ;
char * V_75 ;
F_52 ( V_76 ) ;
if ( ! V_22 -> V_57 ) {
F_16 ( L_27 , V_22 -> V_53 ) ;
return - V_56 ;
}
F_32 ( & V_22 -> V_39 ) ;
if ( V_22 -> V_77 ) {
F_34 ( & V_22 -> V_39 ) ;
F_16 ( L_28 , V_22 -> V_53 ) ;
return - V_56 ;
}
V_22 -> V_77 = 1 ;
while ( V_22 -> V_47 > 0 ) {
F_34 ( & V_22 -> V_39 ) ;
F_53 () ;
F_32 ( & V_22 -> V_39 ) ;
}
F_34 ( & V_22 -> V_39 ) ;
if ( V_20 -> V_78 >= 2 && F_15 ( V_20 , 1 ) > 0 ) {
for ( V_75 = F_17 ( V_20 , 1 ) ; * V_75 != 0 ; V_75 ++ )
switch ( * V_75 ) {
case 'F' :
V_22 -> V_79 = 1 ;
break;
case 'A' :
F_54 ( L_29 ,
V_22 -> V_31 ) ;
V_22 -> V_80 = 1 ;
V_22 -> V_81 = 1 ;
V_22 -> V_82 = 1 ;
if ( F_31 ( V_22 , V_83 ) ) {
F_55 ( V_84 ,
V_22 -> V_72 ,
0 , NULL , NULL ) ;
}
break;
default:
F_16 ( L_30 , * V_75 ) ;
}
}
F_40 ( V_22 -> V_72 ) ;
V_54 = F_56 ( V_22 , V_85 ) ;
if ( V_54 )
F_16 ( L_31 ,
V_22 -> V_31 , V_54 ) ;
if ( V_22 -> V_62 ) {
F_48 ( V_22 -> V_62 ) ;
V_22 -> V_62 = NULL ;
}
F_50 ( V_22 , L_21 , V_22 ) ;
V_22 -> V_57 = 0 ;
return 0 ;
}
struct V_21 * F_46 ( struct V_21 * V_22 ,
const char * V_86 , const void * V_87 )
{
F_57 ( & V_22 -> V_51 , V_86 , V_87 ) ;
F_58 ( & V_22 -> V_50 ) ;
F_8 ( V_11 , L_32 , V_22 -> V_31 , V_22 ,
F_37 ( & V_22 -> V_50 ) ) ;
return V_22 ;
}
void F_50 ( struct V_21 * V_22 , const char * V_86 , const void * V_87 )
{
int V_54 ;
int V_88 ;
F_32 ( & V_22 -> V_39 ) ;
F_59 ( & V_22 -> V_50 ) ;
V_88 = F_37 ( & V_22 -> V_50 ) ;
F_34 ( & V_22 -> V_39 ) ;
F_60 ( & V_22 -> V_51 , V_86 , V_87 ) ;
F_8 ( V_11 , L_33 , V_22 -> V_31 , V_22 , V_88 ) ;
if ( ( V_88 == 1 ) && V_22 -> V_77 ) {
F_32 ( & V_22 -> V_72 -> V_89 ) ;
V_22 -> V_72 -> V_90 |= F_61 ( V_22 ) ;
F_34 ( & V_22 -> V_72 -> V_89 ) ;
F_47 ( V_22 -> V_72 ) ;
return;
}
if ( V_88 == 0 ) {
F_8 ( V_91 , L_34 ,
V_22 -> V_31 , V_22 -> V_48 . V_25 ) ;
F_40 ( ! V_22 -> V_52 ) ;
if ( V_22 -> V_77 ) {
V_54 = F_62 ( V_22 ) ;
if ( V_54 )
F_16 ( L_35 ,
V_22 -> V_31 , V_54 ) ;
}
if ( F_31 ( V_22 , V_92 ) ) {
V_54 = F_31 ( V_22 , V_92 ) ( V_22 ) ;
if ( V_54 )
F_16 ( L_36 , V_54 ) ;
}
F_38 ( V_22 ) ;
}
}
static int F_63 ( struct V_21 * V_22 , struct V_19 * V_20 )
{
struct V_93 * V_94 ;
struct V_48 V_25 ;
int V_16 ;
if ( F_15 ( V_20 , 1 ) < 1 ||
F_15 ( V_20 , 1 ) > sizeof( struct V_48 ) ) {
F_16 ( L_37 ) ;
return - V_9 ;
}
if ( strcmp ( V_22 -> V_58 -> V_59 , V_95 ) &&
strcmp ( V_22 -> V_58 -> V_59 , V_96 ) &&
strcmp ( V_22 -> V_58 -> V_59 , V_97 ) &&
strcmp ( V_22 -> V_58 -> V_59 , V_98 ) &&
strcmp ( V_22 -> V_58 -> V_59 , V_99 ) ) {
F_16 ( L_38 ) ;
return - V_9 ;
}
V_94 = V_22 -> V_100 . V_101 . V_102 ;
if ( ! V_94 ) {
F_16 ( L_39 ) ;
return - V_9 ;
}
F_64 ( & V_25 , F_17 ( V_20 , 1 ) ) ;
V_16 = F_65 ( V_94 , & V_25 , V_20 -> V_103 ) ;
return V_16 ;
}
static int F_66 ( struct V_21 * V_22 , struct V_19 * V_20 )
{
struct V_93 * V_94 ;
struct V_48 V_25 ;
int V_16 ;
if ( F_15 ( V_20 , 1 ) < 1 ||
F_15 ( V_20 , 1 ) > sizeof( struct V_48 ) ) {
F_16 ( L_37 ) ;
return - V_9 ;
}
if ( strcmp ( V_22 -> V_58 -> V_59 , V_95 ) &&
strcmp ( V_22 -> V_58 -> V_59 , V_96 ) ) {
F_16 ( L_40 ) ;
return - V_9 ;
}
V_94 = V_22 -> V_100 . V_101 . V_102 ;
if ( ! V_94 ) {
F_16 ( L_41 ) ;
return - V_9 ;
}
F_64 ( & V_25 , F_17 ( V_20 , 1 ) ) ;
V_16 = F_67 ( V_94 , & V_25 ) ;
return V_16 ;
}
struct V_104 * F_68 ( const char * V_105 )
{
struct V_104 * V_106 ;
F_69 (lprof, &lustre_profile_list, lp_list) {
if ( ! strcmp ( V_106 -> V_107 , V_105 ) ) {
return V_106 ;
}
}
return NULL ;
}
static int F_70 ( int V_108 , char * V_105 , int V_109 , char * V_110 ,
int V_111 , char * V_112 )
{
struct V_104 * V_106 ;
int V_54 = 0 ;
F_8 ( V_91 , L_42 , V_105 ) ;
V_106 = F_71 ( sizeof( * V_106 ) , V_113 ) ;
if ( ! V_106 )
return - V_70 ;
F_24 ( & V_106 -> V_114 ) ;
F_40 ( V_108 == ( strlen ( V_105 ) + 1 ) ) ;
V_106 -> V_107 = F_72 ( V_105 , V_108 , V_113 ) ;
if ( ! V_106 -> V_107 ) {
V_54 = - V_70 ;
goto V_115;
}
F_40 ( V_109 == ( strlen ( V_110 ) + 1 ) ) ;
V_106 -> V_116 = F_72 ( V_110 , V_109 , V_113 ) ;
if ( ! V_106 -> V_116 ) {
V_54 = - V_70 ;
goto V_117;
}
if ( V_111 > 0 ) {
F_40 ( V_111 == ( strlen ( V_112 ) + 1 ) ) ;
V_106 -> V_118 = F_72 ( V_112 , V_111 , V_113 ) ;
if ( ! V_106 -> V_118 ) {
V_54 = - V_70 ;
goto V_119;
}
}
F_73 ( & V_106 -> V_114 , & V_120 ) ;
return V_54 ;
V_119:
F_74 ( V_106 -> V_116 ) ;
V_117:
F_74 ( V_106 -> V_107 ) ;
V_115:
F_74 ( V_106 ) ;
return V_54 ;
}
void F_75 ( const char * V_105 )
{
struct V_104 * V_106 ;
F_8 ( V_91 , L_43 , V_105 ) ;
V_106 = F_68 ( V_105 ) ;
if ( V_106 ) {
F_76 ( & V_106 -> V_114 ) ;
F_74 ( V_106 -> V_107 ) ;
F_74 ( V_106 -> V_116 ) ;
F_74 ( V_106 -> V_118 ) ;
F_74 ( V_106 ) ;
}
}
void F_77 ( void )
{
struct V_104 * V_106 , * V_121 ;
F_78 (lprof, n, &lustre_profile_list, lp_list) {
F_76 ( & V_106 -> V_114 ) ;
F_74 ( V_106 -> V_107 ) ;
F_74 ( V_106 -> V_116 ) ;
F_74 ( V_106 -> V_118 ) ;
F_74 ( V_106 ) ;
}
}
static int F_79 ( char * V_4 , int V_122 , struct V_19 * V_20 )
{
if ( F_2 ( V_4 , V_123 , NULL ) == 0 )
V_124 = V_122 ;
else if ( F_2 ( V_4 , V_125 , NULL ) == 0 )
V_126 = V_122 ;
else if ( F_2 ( V_4 , V_127 , NULL ) == 0 )
V_128 = V_122 ;
else if ( F_2 ( V_4 , V_129 , NULL ) == 0 )
V_130 = V_122 ;
else if ( F_2 ( V_4 , V_131 , NULL ) == 0 )
V_132 = V_122 ;
else if ( F_2 ( V_4 , V_133 , NULL ) == 0 )
F_80 ( V_134 , F_17 ( V_20 , 2 ) ,
V_135 + 1 ) ;
else
return - V_9 ;
F_8 ( V_27 , L_44 , V_4 , V_122 ) ;
return 0 ;
}
void F_81 ( int (* F_82)( struct V_19 * V_20 ) )
{
V_136 = F_82 ;
}
static int F_83 ( struct V_19 * V_20 )
{
char * V_137 = F_17 ( V_20 , 1 ) ;
char * V_138 = F_17 ( V_20 , 2 ) ;
char * V_139 [] = {
[ 0 ] = L_45 ,
[ 1 ] = L_46 ,
[ 2 ] = V_137 ,
[ 3 ] = NULL
} ;
T_3 V_140 ;
T_3 V_141 ;
int V_16 ;
if ( strcmp ( V_138 , V_142 ) != 0 ) {
F_16 ( L_47 , V_138 ) ;
return - V_9 ;
}
V_140 = F_84 () ;
V_16 = F_85 ( V_139 [ 0 ] , V_139 , NULL , 1 ) ;
V_141 = F_84 () ;
if ( V_16 < 0 ) {
F_16 (
L_48 ,
V_139 [ 0 ] , V_139 [ 1 ] , V_139 [ 2 ] , V_16 ,
( long ) F_86 ( V_141 , V_140 ) ) ;
} else {
F_8 ( V_143 , L_49 ,
V_139 [ 0 ] , V_139 [ 1 ] , V_139 [ 2 ] ,
( long ) F_86 ( V_141 , V_140 ) ) ;
V_16 = 0 ;
}
return V_16 ;
}
int F_87 ( struct V_19 * V_20 )
{
struct V_21 * V_22 ;
int V_54 ;
F_40 ( V_20 && ! F_20 ( V_20 ) ) ;
F_8 ( V_27 , L_50 , V_20 -> V_144 ) ;
switch ( V_20 -> V_144 ) {
case V_145 : {
V_54 = F_14 ( V_20 ) ;
goto V_28;
}
case V_146 : {
F_8 ( V_27 , L_51 ,
F_17 ( V_20 , 1 ) , V_20 -> V_147 ,
F_88 ( V_20 -> V_147 ) ) ;
V_54 = F_89 ( F_17 ( V_20 , 1 ) , V_20 -> V_147 ) ;
goto V_28;
}
case V_148 : {
F_8 ( V_27 , L_52 ,
( V_20 -> V_78 < 2 || F_15 ( V_20 , 1 ) == 0 )
? L_53 : F_17 ( V_20 , 1 ) ) ;
V_54 = F_90 ( F_17 ( V_20 , 1 ) ) ;
goto V_28;
}
case V_149 : {
F_8 ( V_27 , L_54 ,
F_17 ( V_20 , 1 ) ,
F_17 ( V_20 , 2 ) ,
F_17 ( V_20 , 3 ) ) ;
V_54 = F_70 ( F_15 ( V_20 , 1 ) ,
F_17 ( V_20 , 1 ) ,
F_15 ( V_20 , 2 ) ,
F_17 ( V_20 , 2 ) ,
F_15 ( V_20 , 3 ) ,
F_17 ( V_20 , 3 ) ) ;
goto V_28;
}
case V_150 : {
F_8 ( V_27 , L_55 ,
F_17 ( V_20 , 1 ) ) ;
F_75 ( F_17 ( V_20 , 1 ) ) ;
V_54 = 0 ;
goto V_28;
}
case V_151 : {
F_8 ( V_27 , L_56 ,
V_152 , V_20 -> V_103 ) ;
V_152 = F_91 ( V_20 -> V_103 , 1U ) ;
V_153 = 1 ;
V_54 = 0 ;
goto V_28;
}
case V_154 : {
V_54 = 0 ;
goto V_28;
}
case V_155 : {
F_5 ( 0x15a , L_57 ) ;
V_54 = 0 ;
goto V_28;
}
case V_156 : {
struct V_157 * V_158 ;
V_158 = F_92 ( V_20 , 1 ) ;
F_8 ( V_27 , L_58 , V_158 -> V_159 ,
V_158 -> V_160 , V_158 -> V_161 , V_158 -> V_162 ) ;
V_54 = 0 ;
goto V_28;
}
case V_163 : {
char * V_15 ;
if ( ( F_2 ( F_17 ( V_20 , 1 ) ,
V_164 , NULL ) == 0 ) &&
V_136 ) {
V_54 = (* V_136)( V_20 ) ;
goto V_28;
} else if ( ( F_2 ( F_17 ( V_20 , 1 ) ,
V_165 , & V_15 ) == 0 ) ) {
V_54 = F_79 ( V_15 , V_20 -> V_103 , V_20 ) ;
if ( V_54 != 0 )
F_93 ( L_59 , V_15 ) ;
V_54 = 0 ;
goto V_28;
} else if ( ( F_2 ( F_17 ( V_20 , 1 ) ,
V_166 , & V_15 ) == 0 ) &&
V_167 ) {
V_54 = (* V_167)( V_20 ) ;
goto V_28;
}
break;
}
case V_168 : {
V_54 = F_83 ( V_20 ) ;
goto V_28;
}
}
V_22 = F_94 ( F_17 ( V_20 , 0 ) ) ;
if ( ! V_22 ) {
if ( ! F_15 ( V_20 , 0 ) )
F_16 ( L_60 ) ;
else
F_16 ( L_61 ,
F_17 ( V_20 , 0 ) ) ;
V_54 = - V_9 ;
goto V_28;
}
switch ( V_20 -> V_144 ) {
case V_169 : {
V_54 = F_39 ( V_22 , V_20 ) ;
goto V_28;
}
case V_170 : {
V_54 = F_49 ( V_22 , V_20 ) ;
V_54 = 0 ;
goto V_28;
}
case V_171 : {
V_54 = F_51 ( V_22 , V_20 ) ;
V_54 = 0 ;
goto V_28;
}
case V_172 : {
V_54 = F_63 ( V_22 , V_20 ) ;
V_54 = 0 ;
goto V_28;
}
case V_173 : {
V_54 = F_66 ( V_22 , V_20 ) ;
V_54 = 0 ;
goto V_28;
}
case V_174 : {
V_54 = F_95 ( V_22 , F_17 ( V_20 , 2 ) ) ;
V_54 = 0 ;
goto V_28;
}
case V_175 : {
V_54 = F_96 ( V_22 , F_17 ( V_20 , 2 ) ,
F_17 ( V_20 , 3 ) ) ;
V_54 = 0 ;
goto V_28;
}
case V_176 : {
V_54 = F_97 ( V_22 , F_17 ( V_20 , 2 ) ,
F_17 ( V_20 , 3 ) ) ;
V_54 = 0 ;
goto V_28;
}
case V_177 : {
V_54 = F_98 ( V_22 , F_17 ( V_20 , 2 ) ) ;
V_54 = 0 ;
goto V_28;
}
default: {
V_54 = F_99 ( V_22 , sizeof( * V_20 ) , V_20 ) ;
goto V_28;
}
}
V_28:
if ( ( V_54 < 0 ) && ! ( V_20 -> V_144 & V_178 ) ) {
F_93 ( L_62 , V_54 ,
V_20 -> V_144 ) ;
V_54 = 0 ;
}
return V_54 ;
}
int F_100 ( char * V_179 , struct V_180 * V_181 ,
struct V_19 * V_20 , void * V_182 )
{
struct V_180 * V_183 ;
struct V_184 V_185 ;
struct V_186 V_187 ;
char * V_2 , * V_188 ;
int V_189 , V_190 , V_191 ;
int V_192 = 0 , V_193 = 0 ;
int V_16 = 0 ;
int V_194 = 0 ;
if ( V_20 -> V_144 != V_163 ) {
F_16 ( L_63 , V_20 -> V_144 ) ;
return - V_9 ;
}
V_185 . V_195 = & V_187 ;
V_187 . V_196 = V_182 ;
for ( V_189 = 1 ; V_189 < V_20 -> V_78 ; V_189 ++ ) {
V_2 = F_92 ( V_20 , V_189 ) ;
F_2 ( V_2 , V_179 , & V_2 ) ;
V_188 = strchr ( V_2 , '=' ) ;
if ( ! V_188 || ( * ( V_188 + 1 ) == 0 ) ) {
F_16 ( L_64 , V_2 ) ;
continue;
}
V_190 = V_188 - V_2 ;
V_188 ++ ;
V_191 = strlen ( V_188 ) ;
V_192 = 0 ;
V_193 = 0 ;
while ( V_181 [ V_193 ] . V_24 ) {
V_183 = & V_181 [ V_193 ] ;
if ( ! F_2 ( V_2 , V_183 -> V_24 , NULL )
&& V_190 == strlen ( V_183 -> V_24 ) ) {
V_192 ++ ;
V_16 = - V_197 ;
if ( V_183 -> V_198 && V_183 -> V_198 -> V_199 ) {
T_4 V_200 ;
V_200 = F_101 () ;
F_102 ( V_201 ) ;
V_16 = ( V_183 -> V_198 -> V_199 ) ( & V_185 , V_188 ,
V_191 , NULL ) ;
F_102 ( V_200 ) ;
}
break;
}
V_193 ++ ;
}
if ( ! V_192 ) {
if ( F_103 ( V_2 , V_190 , '.' ) )
return - V_202 ;
F_16 ( L_65 ,
( char * ) F_17 ( V_20 , 0 ) , V_2 ) ;
V_194 ++ ;
} else if ( V_16 < 0 ) {
F_16 ( L_66 ,
V_183 -> V_24 , V_16 ) ;
V_16 = 0 ;
} else {
F_8 ( V_91 , L_67 ,
F_17 ( V_20 , 0 ) ,
( int ) strlen ( V_179 ) - 1 , V_179 ,
( int ) ( V_188 - V_2 - 1 ) , V_2 , V_188 ) ;
}
}
if ( V_16 > 0 )
V_16 = 0 ;
if ( ! V_16 && V_194 )
V_16 = V_194 ;
return V_16 ;
}
int F_104 ( const struct V_203 * V_204 ,
struct V_205 * V_206 ,
struct V_207 * V_208 , void * V_182 )
{
struct V_209 * V_210 = V_182 ;
int V_211 = V_208 -> V_212 ;
char * V_213 = ( char * ) ( V_208 + 1 ) ;
int V_16 = 0 ;
switch ( V_208 -> V_214 ) {
case V_215 : {
struct V_19 * V_20 , * V_216 ;
struct V_217 V_218 ;
char * V_219 = NULL ;
int V_220 = 0 ;
int V_221 = 0 , V_222 = 0 ;
V_20 = (struct V_19 * ) V_213 ;
if ( V_20 -> V_223 == F_105 ( V_224 ) ) {
F_106 ( V_20 ) ;
V_222 = 1 ;
}
V_16 = F_107 ( V_213 , V_211 ) ;
if ( V_16 )
goto V_28;
if ( V_20 -> V_144 == V_156 ) {
struct V_157 * V_158 = F_92 ( V_20 , 1 ) ;
F_108 ( V_158 , V_222 ,
F_15 ( V_20 , 1 ) ) ;
F_8 ( V_91 , L_68 ,
V_210 -> V_225 , V_158 -> V_160 ) ;
if ( V_158 -> V_160 & V_226 ) {
V_210 -> V_225 = V_227 ;
if ( V_158 -> V_160 & V_228 ) {
V_210 -> V_225 |= V_229 ;
F_8 ( V_91 , L_69 ,
V_158 -> V_159 ) ;
} else if ( ( V_158 -> V_160 & V_230 ) ||
( V_210 -> V_231 &&
F_109 ( V_210 -> V_231 ,
V_158 -> V_161 ) ) ) {
V_210 -> V_225 |= V_232 ;
F_8 ( V_91 , L_70 ,
V_158 -> V_159 ) ;
}
} else if ( V_158 -> V_160 & V_233 ) {
V_210 -> V_225 = 0 ;
}
}
if ( ! ( V_210 -> V_225 & V_234 ) &&
! ( V_210 -> V_225 & V_227 ) &&
( V_20 -> V_144 != V_156 ) ) {
F_93 ( L_71 ,
V_210 -> V_235 ,
V_210 -> V_236 . V_25 , V_210 -> V_225 ) ;
V_210 -> V_225 |= V_229 ;
}
if ( V_210 -> V_225 & V_229 ) {
F_8 ( V_91 , L_72 ,
V_210 -> V_225 ) ;
V_16 = 0 ;
break;
}
{
char * V_23 = F_17 ( V_20 , 1 ) ;
char * V_237 = F_17 ( V_20 , 2 ) ;
if ( ( V_20 -> V_144 == V_145 && V_23 &&
strcmp ( V_23 , L_73 ) == 0 ) ) {
F_93 ( L_74 ) ;
V_23 [ 2 ] = 't' ;
}
if ( ( V_20 -> V_144 == V_169 && V_237 &&
strcmp ( V_237 , L_75 ) == 0 ) ) {
F_8 ( V_11 , L_76 ) ;
V_237 [ 0 ] = '0' ;
V_237 [ 1 ] = 0 ;
}
}
if ( V_210 -> V_225 & V_232 ) {
F_8 ( V_91 , L_77 ,
V_20 -> V_144 ) ;
if ( V_20 -> V_144 == V_238 )
V_20 -> V_144 = V_239 ;
}
F_110 ( & V_218 , V_20 ) ;
if ( V_210 && V_210 -> V_235 &&
F_15 ( V_20 , 0 ) > 0 ) {
V_221 = 1 ;
V_220 = F_15 ( V_20 , 0 ) +
sizeof( V_210 -> V_235 ) * 2 + 4 ;
V_219 = F_111 ( V_113 , L_78 ,
F_17 ( V_20 , 0 ) ,
V_210 -> V_235 ) ;
if ( ! V_219 ) {
V_16 = - V_70 ;
goto V_28;
}
F_112 ( & V_218 , 0 , V_219 ) ;
F_8 ( V_91 , L_79 ,
V_20 -> V_144 , V_219 ) ;
}
if ( V_210 && V_210 -> V_235 &&
V_20 -> V_144 == V_145 ) {
F_112 ( & V_218 , 2 ,
V_210 -> V_236 . V_25 ) ;
}
if ( V_210 && ! V_210 -> V_235 &&
V_20 -> V_144 == V_240 ) {
F_113 ( & V_218 , 2 , V_218 . V_241 [ 1 ] ,
V_218 . V_242 [ 1 ] ) ;
F_113 ( & V_218 , 1 , V_218 . V_241 [ 0 ] ,
V_218 . V_242 [ 0 ] ) ;
F_112 ( & V_218 , 0 ,
V_210 -> V_243 ) ;
}
V_216 = F_114 ( V_20 -> V_144 , & V_218 ) ;
V_216 -> V_103 = V_20 -> V_103 ;
V_216 -> V_244 = V_20 -> V_244 ;
if ( V_20 -> V_245 != 0 &&
( V_20 -> V_147 >> 32 ) == 0 ) {
T_2 V_246 = ( T_2 ) ( V_20 -> V_147 & 0xffffffff ) ;
V_216 -> V_147 =
F_115 ( F_116 ( V_20 -> V_245 , 0 ) , V_246 ) ;
F_93 ( L_80 ,
V_20 -> V_245 , V_246 ,
F_88 ( V_216 -> V_147 ) ) ;
} else {
V_216 -> V_147 = V_20 -> V_147 ;
}
V_216 -> V_245 = 0 ;
V_16 = F_87 ( V_216 ) ;
F_117 ( V_216 ) ;
if ( V_221 )
F_74 ( V_219 ) ;
break;
}
default:
F_16 ( L_81 ,
V_208 -> V_214 ) ;
break;
}
V_28:
if ( V_16 ) {
F_16 ( L_82 ,
V_206 -> V_247 -> V_248 -> V_31 , V_16 ) ;
F_118 ( NULL , V_206 , V_208 , V_182 ) ;
}
return V_16 ;
}
int F_119 ( const struct V_203 * V_204 , struct V_249 * V_250 ,
char * V_24 , struct V_209 * V_251 )
{
struct V_252 V_253 = { 0 , 0 } ;
struct V_205 * V_254 ;
T_5 V_255 ;
int V_16 ;
F_8 ( V_11 , L_83 , V_24 ) ;
V_16 = F_120 ( V_204 , V_250 , & V_254 , NULL , V_24 , V_256 ) ;
if ( V_16 )
return V_16 ;
V_16 = F_121 ( V_204 , V_254 , V_257 , NULL ) ;
if ( V_16 )
goto V_258;
if ( V_251 ) {
V_253 . V_259 = V_251 -> V_260 ;
V_255 = V_251 -> V_261 ;
F_40 ( V_255 ) ;
} else {
V_255 = F_104 ;
}
V_253 . V_262 = 0 ;
V_16 = F_122 ( V_204 , V_254 , V_255 , V_251 , & V_253 ) ;
F_8 ( V_91 , L_84 , V_24 ,
V_253 . V_259 + 1 , V_253 . V_262 , V_16 ) ;
if ( V_251 )
V_251 -> V_260 = V_253 . V_262 ;
V_258:
F_123 ( V_204 , V_254 ) ;
return V_16 ;
}
static int F_124 ( struct V_207 * V_208 , char * V_1 ,
int V_263 )
{
struct V_19 * V_20 = (struct V_19 * ) ( V_208 + 1 ) ;
char * V_4 = V_1 ;
char * V_141 = V_1 + V_263 ;
int V_16 = 0 ;
F_40 ( V_208 -> V_214 == V_215 ) ;
V_16 = F_107 ( V_20 , V_208 -> V_212 ) ;
if ( V_16 < 0 )
return V_16 ;
V_4 += snprintf ( V_4 , V_141 - V_4 , L_85 , V_20 -> V_144 ) ;
if ( V_20 -> V_244 )
V_4 += snprintf ( V_4 , V_141 - V_4 , L_86 ,
V_20 -> V_244 ) ;
if ( V_20 -> V_103 )
V_4 += snprintf ( V_4 , V_141 - V_4 , L_87 , V_20 -> V_103 ) ;
if ( V_20 -> V_147 ) {
char V_264 [ V_265 ] ;
F_125 ( V_20 -> V_147 , V_264 , sizeof( V_264 ) ) ;
V_4 += snprintf ( V_4 , V_141 - V_4 , L_88 ,
V_264 , V_20 -> V_147 ) ;
}
if ( V_20 -> V_144 == V_156 ) {
struct V_157 * V_158 = F_92 ( V_20 , 1 ) ;
V_4 += snprintf ( V_4 , V_141 - V_4 , L_89 ,
V_158 -> V_159 , V_158 -> V_160 ,
V_158 -> V_161 , V_158 -> V_162 ) ;
} else {
int V_189 ;
for ( V_189 = 0 ; V_189 < V_20 -> V_78 ; V_189 ++ ) {
V_4 += snprintf ( V_4 , V_141 - V_4 , L_90 , V_189 ,
F_17 ( V_20 , V_189 ) ) ;
}
}
V_16 = V_4 - V_1 ;
return V_16 ;
}
int F_118 ( const struct V_203 * V_204 ,
struct V_205 * V_206 ,
struct V_207 * V_208 , void * V_182 )
{
char * V_266 ;
int V_16 = 0 ;
V_266 = F_71 ( 256 , V_113 ) ;
if ( ! V_266 )
return - V_70 ;
if ( V_208 -> V_214 == V_215 ) {
F_124 ( V_208 , V_266 , 256 ) ;
F_126 ( V_267 , L_91 , V_266 ) ;
} else {
F_126 ( V_267 , L_92 , V_208 -> V_214 ) ;
V_16 = - V_9 ;
}
F_74 ( V_266 ) ;
return V_16 ;
}
int F_127 ( struct V_21 * V_22 )
{
char V_268 [ 3 ] = L_93 ;
struct V_19 * V_20 ;
struct V_217 V_218 ;
int V_16 ;
if ( ! V_22 ) {
F_16 ( L_94 ) ;
return - V_269 ;
}
if ( V_22 -> V_79 )
strcat ( V_268 , L_95 ) ;
if ( V_22 -> V_80 )
strcat ( V_268 , L_96 ) ;
F_8 ( V_91 , L_97 ,
V_22 -> V_31 , V_268 ) ;
F_128 ( & V_218 , V_22 -> V_31 ) ;
F_112 ( & V_218 , 1 , V_268 ) ;
V_20 = F_114 ( V_171 , & V_218 ) ;
if ( ! V_20 )
return - V_70 ;
V_16 = F_87 ( V_20 ) ;
if ( V_16 ) {
F_16 ( L_98 , V_16 , V_22 -> V_31 ) ;
goto V_28;
}
V_20 -> V_144 = V_170 ;
V_16 = F_87 ( V_20 ) ;
if ( V_16 )
F_16 ( L_99 , V_16 , V_22 -> V_31 ) ;
V_28:
F_117 ( V_20 ) ;
return V_16 ;
}
static unsigned
F_129 ( struct V_270 * V_271 , const void * V_2 , unsigned V_272 )
{
return F_130 ( ( (struct V_48 * ) V_2 ) -> V_25 ,
sizeof( ( (struct V_48 * ) V_2 ) -> V_25 ) , V_272 ) ;
}
static void *
F_131 ( struct V_273 * V_274 )
{
struct V_55 * exp ;
exp = F_132 ( V_274 , struct V_55 , V_275 ) ;
return & exp -> V_276 ;
}
static int
F_133 ( const void * V_2 , struct V_273 * V_274 )
{
struct V_55 * exp ;
F_40 ( V_2 ) ;
exp = F_132 ( V_274 , struct V_55 , V_275 ) ;
return F_134 ( V_2 , & exp -> V_276 ) &&
! exp -> V_277 ;
}
static void *
F_135 ( struct V_273 * V_274 )
{
return F_132 ( V_274 , struct V_55 , V_275 ) ;
}
static void
F_136 ( struct V_270 * V_271 , struct V_273 * V_274 )
{
struct V_55 * exp ;
exp = F_132 ( V_274 , struct V_55 , V_275 ) ;
F_137 ( exp ) ;
}
static void
F_138 ( struct V_270 * V_271 , struct V_273 * V_274 )
{
struct V_55 * exp ;
exp = F_132 ( V_274 , struct V_55 , V_275 ) ;
F_44 ( exp ) ;
}
