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
F_30 ( & V_22 -> V_45 ) ;
V_22 -> V_46 = 0 ;
V_26 = strlen ( V_25 ) ;
if ( V_26 >= sizeof( V_22 -> V_47 ) ) {
F_16 ( L_12 ,
( int ) sizeof( V_22 -> V_47 ) ) ;
V_16 = - V_9 ;
goto V_28;
}
memcpy ( V_22 -> V_47 . V_25 , V_25 , V_26 ) ;
F_31 ( & V_22 -> V_39 ) ;
F_32 ( & V_22 -> V_48 , 1 ) ;
F_33 ( & V_22 -> V_39 ) ;
F_34 ( & V_22 -> V_49 ) ;
F_35 ( & V_22 -> V_49 , L_13 , V_22 ) ;
V_22 -> V_50 = 1 ;
F_8 ( V_27 , L_14 ,
V_22 -> V_51 , V_23 , F_36 ( & V_22 -> V_48 ) ) ;
return 0 ;
V_28:
if ( V_22 )
F_37 ( V_22 ) ;
return V_16 ;
}
static int F_38 ( struct V_21 * V_22 , struct V_19 * V_20 )
{
int V_52 = 0 ;
struct V_53 * exp ;
F_39 ( V_22 ) ;
F_22 ( V_22 == F_40 ( V_22 -> V_51 ) ,
L_15 ,
V_22 , V_22 -> V_51 , F_40 ( V_22 -> V_51 ) ) ;
F_22 ( V_22 -> V_29 == V_30 ,
L_16 ,
V_22 , V_22 -> V_29 , V_30 ) ;
if ( ! V_22 -> V_50 ) {
F_16 ( L_17 , V_22 -> V_51 ) ;
return - V_54 ;
}
if ( V_22 -> V_55 ) {
F_16 ( L_18 ,
V_22 -> V_51 , V_22 -> V_56 -> V_57 ) ;
return - V_58 ;
}
F_31 ( & V_22 -> V_39 ) ;
if ( V_22 -> V_59 ) {
F_33 ( & V_22 -> V_39 ) ;
F_16 ( L_19 ,
V_22 -> V_51 , V_22 -> V_56 -> V_57 ) ;
return - V_58 ;
}
V_22 -> V_59 = 1 ;
V_22 -> V_60 = NULL ;
F_33 ( & V_22 -> V_39 ) ;
V_22 -> V_60 = F_41 ( L_20 ,
V_61 ,
V_62 ,
V_63 , 0 ,
V_64 ,
V_65 ,
& V_66 , V_67 ) ;
if ( ! V_22 -> V_60 ) {
V_52 = - V_68 ;
goto V_69;
}
exp = F_42 ( V_22 , & V_22 -> V_47 ) ;
if ( F_20 ( exp ) ) {
V_52 = F_21 ( exp ) ;
goto V_69;
}
V_22 -> V_70 = exp ;
F_43 ( exp ) ;
V_52 = F_44 ( V_22 , V_20 ) ;
if ( V_52 )
goto V_71;
V_22 -> V_55 = 1 ;
F_31 ( & V_22 -> V_39 ) ;
F_45 ( V_22 , L_21 , V_22 ) ;
F_33 ( & V_22 -> V_39 ) ;
F_8 ( V_27 , L_22 ,
V_22 -> V_31 , V_22 -> V_47 . V_25 ) ;
return 0 ;
V_71:
if ( V_22 -> V_70 ) {
F_46 ( V_22 -> V_70 ) ;
V_22 -> V_70 = NULL ;
}
V_69:
if ( V_22 -> V_60 ) {
F_47 ( V_22 -> V_60 ) ;
V_22 -> V_60 = NULL ;
}
V_22 -> V_59 = 0 ;
F_16 ( L_23 , V_22 -> V_31 , V_52 ) ;
return V_52 ;
}
static int F_48 ( struct V_21 * V_22 , struct V_19 * V_20 )
{
if ( V_22 -> V_55 ) {
F_16 ( L_24 , V_22 -> V_51 ) ;
return - V_72 ;
}
F_31 ( & V_22 -> V_39 ) ;
if ( ! V_22 -> V_50 ) {
F_33 ( & V_22 -> V_39 ) ;
F_16 ( L_25 , V_22 -> V_51 ) ;
return - V_54 ;
}
V_22 -> V_50 = 0 ;
F_33 ( & V_22 -> V_39 ) ;
F_8 ( V_27 , L_26 ,
V_22 -> V_31 , V_22 -> V_47 . V_25 ) ;
F_49 ( V_22 , L_13 , V_22 ) ;
return 0 ;
}
static int F_50 ( struct V_21 * V_22 , struct V_19 * V_20 )
{
int V_52 = 0 ;
char * V_73 ;
F_51 ( V_74 ) ;
if ( ! V_22 -> V_55 ) {
F_16 ( L_27 , V_22 -> V_51 ) ;
return - V_54 ;
}
F_31 ( & V_22 -> V_39 ) ;
if ( V_22 -> V_75 ) {
F_33 ( & V_22 -> V_39 ) ;
F_16 ( L_28 , V_22 -> V_51 ) ;
return - V_54 ;
}
V_22 -> V_75 = 1 ;
F_33 ( & V_22 -> V_39 ) ;
while ( V_22 -> V_46 > 0 )
F_52 () ;
F_53 () ;
if ( V_20 -> V_76 >= 2 && F_15 ( V_20 , 1 ) > 0 ) {
for ( V_73 = F_17 ( V_20 , 1 ) ; * V_73 != 0 ; V_73 ++ )
switch ( * V_73 ) {
case 'F' :
V_22 -> V_77 = 1 ;
break;
case 'A' :
F_54 ( L_29 ,
V_22 -> V_31 ) ;
V_22 -> V_78 = 1 ;
V_22 -> V_79 = 1 ;
V_22 -> V_80 = 1 ;
if ( F_55 ( V_22 , V_81 ) ) {
F_56 ( V_82 ,
V_22 -> V_70 ,
0 , NULL , NULL ) ;
}
break;
default:
F_16 ( L_30 , * V_73 ) ;
}
}
F_39 ( V_22 -> V_70 ) ;
V_52 = F_57 ( V_22 , V_83 ) ;
if ( V_52 )
F_16 ( L_31 ,
V_22 -> V_31 , V_52 ) ;
if ( V_22 -> V_60 ) {
F_47 ( V_22 -> V_60 ) ;
V_22 -> V_60 = NULL ;
}
F_49 ( V_22 , L_21 , V_22 ) ;
V_22 -> V_55 = 0 ;
return 0 ;
}
struct V_21 * F_45 ( struct V_21 * V_22 ,
const char * V_84 , const void * V_85 )
{
F_58 ( & V_22 -> V_49 , V_84 , V_85 ) ;
F_59 ( & V_22 -> V_48 ) ;
F_8 ( V_11 , L_32 , V_22 -> V_31 , V_22 ,
F_36 ( & V_22 -> V_48 ) ) ;
return V_22 ;
}
void F_49 ( struct V_21 * V_22 , const char * V_84 , const void * V_85 )
{
int V_52 ;
int V_86 ;
F_31 ( & V_22 -> V_39 ) ;
F_60 ( & V_22 -> V_48 ) ;
V_86 = F_36 ( & V_22 -> V_48 ) ;
F_33 ( & V_22 -> V_39 ) ;
F_61 ( & V_22 -> V_49 , V_84 , V_85 ) ;
F_8 ( V_11 , L_33 , V_22 -> V_31 , V_22 , V_86 ) ;
if ( ( V_86 == 1 ) && V_22 -> V_75 ) {
F_31 ( & V_22 -> V_70 -> V_87 ) ;
V_22 -> V_70 -> V_88 |= F_62 ( V_22 ) ;
F_33 ( & V_22 -> V_70 -> V_87 ) ;
F_46 ( V_22 -> V_70 ) ;
return;
}
if ( V_86 == 0 ) {
F_8 ( V_89 , L_34 ,
V_22 -> V_31 , V_22 -> V_47 . V_25 ) ;
F_39 ( ! V_22 -> V_50 ) ;
if ( V_22 -> V_75 ) {
V_52 = F_63 ( V_22 ) ;
if ( V_52 )
F_16 ( L_35 ,
V_22 -> V_31 , V_52 ) ;
}
F_37 ( V_22 ) ;
}
}
static int F_64 ( struct V_21 * V_22 , struct V_19 * V_20 )
{
struct V_90 * V_91 ;
struct V_47 V_25 ;
int V_16 ;
if ( F_15 ( V_20 , 1 ) < 1 ||
F_15 ( V_20 , 1 ) > sizeof( struct V_47 ) ) {
F_16 ( L_36 ) ;
return - V_9 ;
}
if ( strcmp ( V_22 -> V_56 -> V_57 , V_92 ) &&
strcmp ( V_22 -> V_56 -> V_57 , V_93 ) &&
strcmp ( V_22 -> V_56 -> V_57 , V_94 ) &&
strcmp ( V_22 -> V_56 -> V_57 , V_95 ) &&
strcmp ( V_22 -> V_56 -> V_57 , V_96 ) ) {
F_16 ( L_37 ) ;
return - V_9 ;
}
V_91 = V_22 -> V_97 . V_98 . V_99 ;
if ( ! V_91 ) {
F_16 ( L_38 ) ;
return - V_9 ;
}
F_65 ( & V_25 , F_17 ( V_20 , 1 ) ) ;
V_16 = F_66 ( V_91 , & V_25 , V_20 -> V_100 ) ;
return V_16 ;
}
static int F_67 ( struct V_21 * V_22 , struct V_19 * V_20 )
{
struct V_90 * V_91 ;
struct V_47 V_25 ;
int V_16 ;
if ( F_15 ( V_20 , 1 ) < 1 ||
F_15 ( V_20 , 1 ) > sizeof( struct V_47 ) ) {
F_16 ( L_36 ) ;
return - V_9 ;
}
if ( strcmp ( V_22 -> V_56 -> V_57 , V_92 ) &&
strcmp ( V_22 -> V_56 -> V_57 , V_93 ) ) {
F_16 ( L_39 ) ;
return - V_9 ;
}
V_91 = V_22 -> V_97 . V_98 . V_99 ;
if ( ! V_91 ) {
F_16 ( L_40 ) ;
return - V_9 ;
}
F_65 ( & V_25 , F_17 ( V_20 , 1 ) ) ;
V_16 = F_68 ( V_91 , & V_25 ) ;
return V_16 ;
}
struct V_101 * F_69 ( const char * V_102 )
{
struct V_101 * V_103 ;
F_70 (lprof, &lustre_profile_list, lp_list) {
if ( ! strcmp ( V_103 -> V_104 , V_102 ) ) {
return V_103 ;
}
}
return NULL ;
}
static int F_71 ( int V_105 , char * V_102 , int V_106 , char * V_107 ,
int V_108 , char * V_109 )
{
struct V_101 * V_103 ;
int V_52 = 0 ;
F_8 ( V_89 , L_41 , V_102 ) ;
V_103 = F_72 ( sizeof( * V_103 ) , V_110 ) ;
if ( ! V_103 )
return - V_68 ;
F_24 ( & V_103 -> V_111 ) ;
F_39 ( V_105 == ( strlen ( V_102 ) + 1 ) ) ;
V_103 -> V_104 = F_73 ( V_102 , V_105 , V_110 ) ;
if ( ! V_103 -> V_104 ) {
V_52 = - V_68 ;
goto V_112;
}
F_39 ( V_106 == ( strlen ( V_107 ) + 1 ) ) ;
V_103 -> V_113 = F_73 ( V_107 , V_106 , V_110 ) ;
if ( ! V_103 -> V_113 ) {
V_52 = - V_68 ;
goto V_114;
}
if ( V_108 > 0 ) {
F_39 ( V_108 == ( strlen ( V_109 ) + 1 ) ) ;
V_103 -> V_115 = F_73 ( V_109 , V_108 , V_110 ) ;
if ( ! V_103 -> V_115 ) {
V_52 = - V_68 ;
goto V_116;
}
}
F_74 ( & V_103 -> V_111 , & V_117 ) ;
return V_52 ;
V_116:
F_75 ( V_103 -> V_113 ) ;
V_114:
F_75 ( V_103 -> V_104 ) ;
V_112:
F_75 ( V_103 ) ;
return V_52 ;
}
void F_76 ( const char * V_102 )
{
struct V_101 * V_103 ;
F_8 ( V_89 , L_42 , V_102 ) ;
V_103 = F_69 ( V_102 ) ;
if ( V_103 ) {
F_77 ( & V_103 -> V_111 ) ;
F_75 ( V_103 -> V_104 ) ;
F_75 ( V_103 -> V_113 ) ;
F_75 ( V_103 -> V_115 ) ;
F_75 ( V_103 ) ;
}
}
void F_78 ( void )
{
struct V_101 * V_103 , * V_118 ;
F_79 (lprof, n, &lustre_profile_list, lp_list) {
F_77 ( & V_103 -> V_111 ) ;
F_75 ( V_103 -> V_104 ) ;
F_75 ( V_103 -> V_113 ) ;
F_75 ( V_103 -> V_115 ) ;
F_75 ( V_103 ) ;
}
}
static int F_80 ( char * V_4 , int V_119 , struct V_19 * V_20 )
{
if ( F_2 ( V_4 , V_120 , NULL ) == 0 )
V_121 = V_119 ;
else if ( F_2 ( V_4 , V_122 , NULL ) == 0 )
V_123 = V_119 ;
else if ( F_2 ( V_4 , V_124 , NULL ) == 0 )
V_125 = V_119 ;
else if ( F_2 ( V_4 , V_126 , NULL ) == 0 )
V_127 = V_119 ;
else if ( F_2 ( V_4 , V_128 , NULL ) == 0 )
V_129 = V_119 ;
else if ( F_2 ( V_4 , V_130 , NULL ) == 0 )
F_81 ( V_131 , F_17 ( V_20 , 2 ) ,
V_132 + 1 ) ;
else
return - V_9 ;
F_8 ( V_27 , L_43 , V_4 , V_119 ) ;
return 0 ;
}
void F_82 ( int (* F_83)( struct V_19 * V_20 ) )
{
V_133 = F_83 ;
}
static int F_84 ( struct V_19 * V_20 )
{
char * V_134 = F_17 ( V_20 , 1 ) ;
char * V_135 = F_17 ( V_20 , 2 ) ;
char * V_136 [] = {
[ 0 ] = L_44 ,
[ 1 ] = L_45 ,
[ 2 ] = V_134 ,
[ 3 ] = NULL
} ;
T_3 V_137 ;
T_3 V_138 ;
int V_16 ;
if ( strcmp ( V_135 , V_139 ) != 0 ) {
F_16 ( L_46 , V_135 ) ;
return - V_9 ;
}
V_137 = F_85 () ;
V_16 = F_86 ( V_136 [ 0 ] , V_136 , NULL , V_140 ) ;
V_138 = F_85 () ;
if ( V_16 < 0 ) {
F_16 (
L_47 ,
V_136 [ 0 ] , V_136 [ 1 ] , V_136 [ 2 ] , V_16 ,
( long ) F_87 ( V_138 , V_137 ) ) ;
} else {
F_8 ( V_141 , L_48 ,
V_136 [ 0 ] , V_136 [ 1 ] , V_136 [ 2 ] ,
( long ) F_87 ( V_138 , V_137 ) ) ;
V_16 = 0 ;
}
return V_16 ;
}
int F_88 ( struct V_19 * V_20 )
{
struct V_21 * V_22 ;
int V_52 ;
F_39 ( V_20 && ! F_20 ( V_20 ) ) ;
F_8 ( V_27 , L_49 , V_20 -> V_142 ) ;
switch ( V_20 -> V_142 ) {
case V_143 : {
V_52 = F_14 ( V_20 ) ;
goto V_28;
}
case V_144 : {
F_8 ( V_27 , L_50 ,
F_17 ( V_20 , 1 ) , V_20 -> V_145 ,
F_89 ( V_20 -> V_145 ) ) ;
V_52 = F_90 ( F_17 ( V_20 , 1 ) , V_20 -> V_145 ) ;
goto V_28;
}
case V_146 : {
F_8 ( V_27 , L_51 ,
( V_20 -> V_76 < 2 || F_15 ( V_20 , 1 ) == 0 )
? L_52 : F_17 ( V_20 , 1 ) ) ;
V_52 = F_91 ( F_17 ( V_20 , 1 ) ) ;
goto V_28;
}
case V_147 : {
F_8 ( V_27 , L_53 ,
F_17 ( V_20 , 1 ) ,
F_17 ( V_20 , 2 ) ,
F_17 ( V_20 , 3 ) ) ;
V_52 = F_71 ( F_15 ( V_20 , 1 ) ,
F_17 ( V_20 , 1 ) ,
F_15 ( V_20 , 2 ) ,
F_17 ( V_20 , 2 ) ,
F_15 ( V_20 , 3 ) ,
F_17 ( V_20 , 3 ) ) ;
goto V_28;
}
case V_148 : {
F_8 ( V_27 , L_54 ,
F_17 ( V_20 , 1 ) ) ;
F_76 ( F_17 ( V_20 , 1 ) ) ;
V_52 = 0 ;
goto V_28;
}
case V_149 : {
F_8 ( V_27 , L_55 ,
V_150 , V_20 -> V_100 ) ;
V_150 = F_92 ( V_20 -> V_100 , 1U ) ;
V_151 = 1 ;
V_52 = 0 ;
goto V_28;
}
case V_152 : {
V_52 = 0 ;
goto V_28;
}
case V_153 : {
F_5 ( 0x15a , L_56 ) ;
V_52 = 0 ;
goto V_28;
}
case V_154 : {
struct V_155 * V_156 ;
V_156 = F_93 ( V_20 , 1 ) ;
F_8 ( V_27 , L_57 , V_156 -> V_157 ,
V_156 -> V_158 , V_156 -> V_159 , V_156 -> V_160 ) ;
V_52 = 0 ;
goto V_28;
}
case V_161 : {
char * V_15 ;
if ( ( F_2 ( F_17 ( V_20 , 1 ) ,
V_162 , NULL ) == 0 ) &&
V_133 ) {
V_52 = (* V_133)( V_20 ) ;
goto V_28;
} else if ( ( F_2 ( F_17 ( V_20 , 1 ) ,
V_163 , & V_15 ) == 0 ) ) {
V_52 = F_80 ( V_15 , V_20 -> V_100 , V_20 ) ;
if ( V_52 != 0 )
F_94 ( L_58 , V_15 ) ;
V_52 = 0 ;
goto V_28;
} else if ( ( F_2 ( F_17 ( V_20 , 1 ) ,
V_164 , & V_15 ) == 0 ) &&
V_165 ) {
V_52 = (* V_165)( V_20 ) ;
goto V_28;
}
break;
}
case V_166 : {
V_52 = F_84 ( V_20 ) ;
goto V_28;
}
}
V_22 = F_95 ( F_17 ( V_20 , 0 ) ) ;
if ( ! V_22 ) {
if ( ! F_15 ( V_20 , 0 ) )
F_16 ( L_59 ) ;
else
F_16 ( L_60 ,
F_17 ( V_20 , 0 ) ) ;
V_52 = - V_9 ;
goto V_28;
}
switch ( V_20 -> V_142 ) {
case V_167 : {
V_52 = F_38 ( V_22 , V_20 ) ;
goto V_28;
}
case V_168 : {
V_52 = F_48 ( V_22 , V_20 ) ;
V_52 = 0 ;
goto V_28;
}
case V_169 : {
V_52 = F_50 ( V_22 , V_20 ) ;
V_52 = 0 ;
goto V_28;
}
case V_170 : {
V_52 = F_64 ( V_22 , V_20 ) ;
V_52 = 0 ;
goto V_28;
}
case V_171 : {
V_52 = F_67 ( V_22 , V_20 ) ;
V_52 = 0 ;
goto V_28;
}
case V_172 : {
V_52 = F_96 ( V_22 , F_17 ( V_20 , 2 ) ) ;
V_52 = 0 ;
goto V_28;
}
case V_173 : {
V_52 = F_97 ( V_22 , F_17 ( V_20 , 2 ) ,
F_17 ( V_20 , 3 ) ) ;
V_52 = 0 ;
goto V_28;
}
case V_174 : {
V_52 = F_98 ( V_22 , F_17 ( V_20 , 2 ) ,
F_17 ( V_20 , 3 ) ) ;
V_52 = 0 ;
goto V_28;
}
case V_175 : {
V_52 = F_99 ( V_22 , F_17 ( V_20 , 2 ) ) ;
V_52 = 0 ;
goto V_28;
}
default: {
V_52 = F_100 ( V_22 , sizeof( * V_20 ) , V_20 ) ;
goto V_28;
}
}
V_28:
if ( ( V_52 < 0 ) && ! ( V_20 -> V_142 & V_176 ) ) {
F_94 ( L_61 , V_52 ,
V_20 -> V_142 ) ;
V_52 = 0 ;
}
return V_52 ;
}
int F_101 ( char * V_177 , struct V_178 * V_179 ,
struct V_19 * V_20 , void * V_180 )
{
struct V_178 * V_181 ;
struct V_182 V_183 ;
struct V_184 V_185 ;
char * V_2 , * V_186 ;
int V_187 , V_188 , V_189 ;
int V_190 = 0 , V_191 = 0 ;
int V_16 = 0 ;
int V_192 = 0 ;
if ( V_20 -> V_142 != V_161 ) {
F_16 ( L_62 , V_20 -> V_142 ) ;
return - V_9 ;
}
V_183 . V_193 = & V_185 ;
V_185 . V_194 = V_180 ;
for ( V_187 = 1 ; V_187 < V_20 -> V_76 ; V_187 ++ ) {
V_2 = F_93 ( V_20 , V_187 ) ;
if ( F_2 ( V_2 , V_177 , & V_2 ) ) {
return - V_195 ;
}
V_186 = strchr ( V_2 , '=' ) ;
if ( ! V_186 || ( * ( V_186 + 1 ) == 0 ) ) {
F_16 ( L_63 , V_2 ) ;
continue;
}
V_188 = V_186 - V_2 ;
V_186 ++ ;
V_189 = strlen ( V_186 ) ;
V_190 = 0 ;
V_191 = 0 ;
while ( V_179 [ V_191 ] . V_24 ) {
V_181 = & V_179 [ V_191 ] ;
if ( ! F_2 ( V_2 , V_181 -> V_24 , NULL ) &&
V_188 == strlen ( V_181 -> V_24 ) ) {
V_190 ++ ;
V_16 = - V_196 ;
if ( V_181 -> V_197 && V_181 -> V_197 -> V_198 ) {
T_4 V_199 ;
V_199 = F_102 () ;
F_103 ( V_200 ) ;
V_16 = V_181 -> V_197 -> V_198 ( & V_183 , V_186 ,
V_189 , NULL ) ;
F_103 ( V_199 ) ;
}
break;
}
V_191 ++ ;
}
if ( ! V_190 ) {
F_16 ( L_64 ,
( int ) strlen ( V_177 ) - 1 , V_177 ,
( char * ) F_17 ( V_20 , 0 ) , V_2 ) ;
V_192 ++ ;
} else if ( V_16 < 0 ) {
F_16 ( L_65 ,
V_177 , V_181 -> V_24 , V_16 ) ;
V_16 = 0 ;
} else {
F_8 ( V_89 , L_66 ,
F_17 ( V_20 , 0 ) ,
( int ) strlen ( V_177 ) - 1 , V_177 ,
( int ) ( V_186 - V_2 - 1 ) , V_2 , V_186 ) ;
}
}
if ( V_16 > 0 )
V_16 = 0 ;
if ( ! V_16 && V_192 )
V_16 = V_192 ;
return V_16 ;
}
int F_104 ( const struct V_201 * V_202 ,
struct V_203 * V_204 ,
struct V_205 * V_206 , void * V_180 )
{
struct V_207 * V_208 = V_180 ;
int V_209 = V_206 -> V_210 ;
char * V_211 = ( char * ) ( V_206 + 1 ) ;
int V_16 = 0 ;
switch ( V_206 -> V_212 ) {
case V_213 : {
struct V_19 * V_20 , * V_214 ;
struct V_215 V_216 ;
char * V_217 = NULL ;
int V_218 = 0 ;
int V_219 = 0 , V_220 = 0 ;
V_20 = (struct V_19 * ) V_211 ;
if ( V_20 -> V_221 == F_105 ( V_222 ) ) {
F_106 ( V_20 ) ;
V_220 = 1 ;
}
V_16 = F_107 ( V_211 , V_209 ) ;
if ( V_16 )
goto V_28;
if ( V_20 -> V_142 == V_154 ) {
struct V_155 * V_156 = F_93 ( V_20 , 1 ) ;
F_108 ( V_156 , V_220 ,
F_15 ( V_20 , 1 ) ) ;
F_8 ( V_89 , L_67 ,
V_208 -> V_223 , V_156 -> V_158 ) ;
if ( V_156 -> V_158 & V_224 ) {
V_208 -> V_223 = V_225 ;
if ( V_156 -> V_158 & V_226 ) {
V_208 -> V_223 |= V_227 ;
F_8 ( V_89 , L_68 ,
V_156 -> V_157 ) ;
} else if ( ( V_156 -> V_158 & V_228 ) ||
( V_208 -> V_229 &&
F_109 ( V_208 -> V_229 ,
V_156 -> V_159 ) ) ) {
V_208 -> V_223 |= V_230 ;
F_8 ( V_89 , L_69 ,
V_156 -> V_157 ) ;
}
} else if ( V_156 -> V_158 & V_231 ) {
V_208 -> V_223 = 0 ;
}
}
if ( ! ( V_208 -> V_223 & V_232 ) &&
! ( V_208 -> V_223 & V_225 ) &&
( V_20 -> V_142 != V_154 ) ) {
F_94 ( L_70 ,
V_208 -> V_233 ,
V_208 -> V_234 . V_25 , V_208 -> V_223 ) ;
V_208 -> V_223 |= V_227 ;
}
if ( V_208 -> V_223 & V_227 ) {
F_8 ( V_89 , L_71 ,
V_208 -> V_223 ) ;
V_16 = 0 ;
break;
}
{
char * V_23 = F_17 ( V_20 , 1 ) ;
char * V_235 = F_17 ( V_20 , 2 ) ;
if ( ( V_20 -> V_142 == V_143 && V_23 &&
strcmp ( V_23 , L_72 ) == 0 ) ) {
F_94 ( L_73 ) ;
V_23 [ 2 ] = 't' ;
}
if ( ( V_20 -> V_142 == V_167 && V_235 &&
strcmp ( V_235 , L_74 ) == 0 ) ) {
F_8 ( V_11 , L_75 ) ;
V_235 [ 0 ] = '0' ;
V_235 [ 1 ] = 0 ;
}
}
if ( V_208 -> V_223 & V_230 ) {
F_8 ( V_89 , L_76 ,
V_20 -> V_142 ) ;
if ( V_20 -> V_142 == V_236 )
V_20 -> V_142 = V_237 ;
}
F_110 ( & V_216 , V_20 ) ;
if ( V_208 && V_208 -> V_233 &&
F_15 ( V_20 , 0 ) > 0 ) {
V_219 = 1 ;
V_218 = F_15 ( V_20 , 0 ) +
sizeof( V_208 -> V_233 ) * 2 + 4 ;
V_217 = F_111 ( V_110 , L_77 ,
F_17 ( V_20 , 0 ) ,
V_208 -> V_233 ) ;
if ( ! V_217 ) {
V_16 = - V_68 ;
goto V_28;
}
F_112 ( & V_216 , 0 , V_217 ) ;
F_8 ( V_89 , L_78 ,
V_20 -> V_142 , V_217 ) ;
}
if ( V_208 && V_208 -> V_233 &&
V_20 -> V_142 == V_143 ) {
F_112 ( & V_216 , 2 ,
V_208 -> V_234 . V_25 ) ;
}
if ( V_208 && ! V_208 -> V_233 &&
V_20 -> V_142 == V_238 ) {
F_113 ( & V_216 , 2 , V_216 . V_239 [ 1 ] ,
V_216 . V_240 [ 1 ] ) ;
F_113 ( & V_216 , 1 , V_216 . V_239 [ 0 ] ,
V_216 . V_240 [ 0 ] ) ;
F_112 ( & V_216 , 0 ,
V_208 -> V_241 ) ;
}
V_214 = F_114 ( V_20 -> V_142 , & V_216 ) ;
V_214 -> V_100 = V_20 -> V_100 ;
V_214 -> V_242 = V_20 -> V_242 ;
if ( V_20 -> V_243 != 0 &&
( V_20 -> V_145 >> 32 ) == 0 ) {
T_2 V_244 = ( T_2 ) ( V_20 -> V_145 & 0xffffffff ) ;
V_214 -> V_145 =
F_115 ( F_116 ( V_20 -> V_243 , 0 ) , V_244 ) ;
F_94 ( L_79 ,
V_20 -> V_243 , V_244 ,
F_89 ( V_214 -> V_145 ) ) ;
} else {
V_214 -> V_145 = V_20 -> V_145 ;
}
V_214 -> V_243 = 0 ;
V_16 = F_88 ( V_214 ) ;
F_117 ( V_214 ) ;
if ( V_219 )
F_75 ( V_217 ) ;
break;
}
default:
F_16 ( L_80 ,
V_206 -> V_212 ) ;
break;
}
V_28:
if ( V_16 ) {
F_16 ( L_81 ,
V_204 -> V_245 -> V_246 -> V_31 , V_16 ) ;
F_118 ( NULL , V_204 , V_206 , V_180 ) ;
}
return V_16 ;
}
int F_119 ( const struct V_201 * V_202 , struct V_247 * V_248 ,
char * V_24 , struct V_207 * V_249 )
{
struct V_250 V_251 = { 0 , 0 } ;
struct V_203 * V_252 ;
T_5 V_253 ;
int V_16 ;
F_8 ( V_11 , L_82 , V_24 ) ;
V_16 = F_120 ( V_202 , V_248 , & V_252 , NULL , V_24 , V_254 ) ;
if ( V_16 )
return V_16 ;
V_16 = F_121 ( V_202 , V_252 , V_255 , NULL ) ;
if ( V_16 )
goto V_256;
if ( V_249 ) {
V_251 . V_257 = V_249 -> V_258 ;
V_253 = V_249 -> V_259 ;
F_39 ( V_253 ) ;
} else {
V_253 = F_104 ;
}
V_251 . V_260 = 0 ;
V_16 = F_122 ( V_202 , V_252 , V_253 , V_249 , & V_251 ) ;
F_8 ( V_89 , L_83 , V_24 ,
V_251 . V_257 + 1 , V_251 . V_260 , V_16 ) ;
if ( V_249 )
V_249 -> V_258 = V_251 . V_260 ;
V_256:
F_123 ( V_202 , V_252 ) ;
return V_16 ;
}
static int F_124 ( struct V_205 * V_206 , char * V_1 ,
int V_261 )
{
struct V_19 * V_20 = (struct V_19 * ) ( V_206 + 1 ) ;
char * V_4 = V_1 ;
char * V_138 = V_1 + V_261 ;
int V_16 = 0 ;
F_39 ( V_206 -> V_212 == V_213 ) ;
V_16 = F_107 ( V_20 , V_206 -> V_210 ) ;
if ( V_16 < 0 )
return V_16 ;
V_4 += snprintf ( V_4 , V_138 - V_4 , L_84 , V_20 -> V_142 ) ;
if ( V_20 -> V_242 )
V_4 += snprintf ( V_4 , V_138 - V_4 , L_85 ,
V_20 -> V_242 ) ;
if ( V_20 -> V_100 )
V_4 += snprintf ( V_4 , V_138 - V_4 , L_86 , V_20 -> V_100 ) ;
if ( V_20 -> V_145 ) {
char V_262 [ V_263 ] ;
F_125 ( V_20 -> V_145 , V_262 , sizeof( V_262 ) ) ;
V_4 += snprintf ( V_4 , V_138 - V_4 , L_87 ,
V_262 , V_20 -> V_145 ) ;
}
if ( V_20 -> V_142 == V_154 ) {
struct V_155 * V_156 = F_93 ( V_20 , 1 ) ;
V_4 += snprintf ( V_4 , V_138 - V_4 , L_88 ,
V_156 -> V_157 , V_156 -> V_158 ,
V_156 -> V_159 , V_156 -> V_160 ) ;
} else {
int V_187 ;
for ( V_187 = 0 ; V_187 < V_20 -> V_76 ; V_187 ++ ) {
V_4 += snprintf ( V_4 , V_138 - V_4 , L_89 , V_187 ,
F_17 ( V_20 , V_187 ) ) ;
}
}
V_4 += snprintf ( V_4 , V_138 - V_4 , L_90 ) ;
V_16 = V_4 - V_1 ;
return V_16 ;
}
int F_118 ( const struct V_201 * V_202 ,
struct V_203 * V_204 ,
struct V_205 * V_206 , void * V_180 )
{
char * V_264 ;
int V_16 = 0 ;
V_264 = F_72 ( 256 , V_110 ) ;
if ( ! V_264 )
return - V_68 ;
if ( V_206 -> V_212 == V_213 ) {
F_124 ( V_206 , V_264 , 256 ) ;
F_126 ( V_265 , L_91 , V_264 ) ;
} else {
F_126 ( V_265 , L_92 , V_206 -> V_212 ) ;
V_16 = - V_9 ;
}
F_75 ( V_264 ) ;
return V_16 ;
}
int F_127 ( struct V_21 * V_22 )
{
char V_266 [ 3 ] = L_93 ;
struct V_19 * V_20 ;
struct V_215 V_216 ;
int V_16 ;
if ( ! V_22 ) {
F_16 ( L_94 ) ;
return - V_267 ;
}
if ( V_22 -> V_77 )
strcat ( V_266 , L_95 ) ;
if ( V_22 -> V_78 )
strcat ( V_266 , L_96 ) ;
F_8 ( V_89 , L_97 ,
V_22 -> V_31 , V_266 ) ;
F_128 ( & V_216 , V_22 -> V_31 ) ;
F_112 ( & V_216 , 1 , V_266 ) ;
V_20 = F_114 ( V_169 , & V_216 ) ;
if ( ! V_20 )
return - V_68 ;
V_16 = F_88 ( V_20 ) ;
if ( V_16 ) {
F_16 ( L_98 , V_16 , V_22 -> V_31 ) ;
goto V_28;
}
V_20 -> V_142 = V_168 ;
V_16 = F_88 ( V_20 ) ;
if ( V_16 )
F_16 ( L_99 , V_16 , V_22 -> V_31 ) ;
V_28:
F_117 ( V_20 ) ;
return V_16 ;
}
static unsigned
F_129 ( struct V_268 * V_269 , const void * V_2 , unsigned V_270 )
{
return F_130 ( ( (struct V_47 * ) V_2 ) -> V_25 ,
sizeof( ( (struct V_47 * ) V_2 ) -> V_25 ) , V_270 ) ;
}
static void *
F_131 ( struct V_271 * V_272 )
{
struct V_53 * exp ;
exp = F_132 ( V_272 , struct V_53 , V_273 ) ;
return & exp -> V_274 ;
}
static int
F_133 ( const void * V_2 , struct V_271 * V_272 )
{
struct V_53 * exp ;
F_39 ( V_2 ) ;
exp = F_132 ( V_272 , struct V_53 , V_273 ) ;
return F_134 ( V_2 , & exp -> V_274 ) &&
! exp -> V_275 ;
}
static void *
F_135 ( struct V_271 * V_272 )
{
return F_132 ( V_272 , struct V_53 , V_273 ) ;
}
static void
F_136 ( struct V_268 * V_269 , struct V_271 * V_272 )
{
struct V_53 * exp ;
exp = F_132 ( V_272 , struct V_53 , V_273 ) ;
F_137 ( exp ) ;
}
static void
F_138 ( struct V_268 * V_269 , struct V_271 * V_272 )
{
struct V_53 * exp ;
exp = F_132 ( V_272 , struct V_53 , V_273 ) ;
F_43 ( exp ) ;
}
