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
V_52 = F_57 ( V_22 ) ;
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
const char * V_83 , const void * V_84 )
{
F_58 ( & V_22 -> V_49 , V_83 , V_84 ) ;
F_59 ( & V_22 -> V_48 ) ;
F_8 ( V_11 , L_32 , V_22 -> V_31 , V_22 ,
F_36 ( & V_22 -> V_48 ) ) ;
return V_22 ;
}
void F_49 ( struct V_21 * V_22 , const char * V_83 , const void * V_84 )
{
int V_52 ;
int V_85 ;
F_31 ( & V_22 -> V_39 ) ;
F_60 ( & V_22 -> V_48 ) ;
V_85 = F_36 ( & V_22 -> V_48 ) ;
F_33 ( & V_22 -> V_39 ) ;
F_61 ( & V_22 -> V_49 , V_83 , V_84 ) ;
F_8 ( V_11 , L_33 , V_22 -> V_31 , V_22 , V_85 ) ;
if ( ( V_85 == 1 ) && V_22 -> V_75 ) {
F_31 ( & V_22 -> V_70 -> V_86 ) ;
V_22 -> V_70 -> V_87 |= F_62 ( V_22 ) ;
F_33 ( & V_22 -> V_70 -> V_86 ) ;
F_46 ( V_22 -> V_70 ) ;
return;
}
if ( V_85 == 0 ) {
F_8 ( V_88 , L_34 ,
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
struct V_89 * V_90 ;
struct V_47 V_25 ;
int V_16 ;
if ( F_15 ( V_20 , 1 ) < 1 ||
F_15 ( V_20 , 1 ) > sizeof( struct V_47 ) ) {
F_16 ( L_36 ) ;
return - V_9 ;
}
if ( strcmp ( V_22 -> V_56 -> V_57 , V_91 ) &&
strcmp ( V_22 -> V_56 -> V_57 , V_92 ) &&
strcmp ( V_22 -> V_56 -> V_57 , V_93 ) &&
strcmp ( V_22 -> V_56 -> V_57 , V_94 ) &&
strcmp ( V_22 -> V_56 -> V_57 , V_95 ) ) {
F_16 ( L_37 ) ;
return - V_9 ;
}
V_90 = V_22 -> V_96 . V_97 . V_98 ;
if ( ! V_90 ) {
F_16 ( L_38 ) ;
return - V_9 ;
}
F_65 ( & V_25 , F_17 ( V_20 , 1 ) ) ;
V_16 = F_66 ( V_90 , & V_25 , V_20 -> V_99 ) ;
return V_16 ;
}
static int F_67 ( struct V_21 * V_22 , struct V_19 * V_20 )
{
struct V_89 * V_90 ;
struct V_47 V_25 ;
int V_16 ;
if ( F_15 ( V_20 , 1 ) < 1 ||
F_15 ( V_20 , 1 ) > sizeof( struct V_47 ) ) {
F_16 ( L_36 ) ;
return - V_9 ;
}
if ( strcmp ( V_22 -> V_56 -> V_57 , V_91 ) &&
strcmp ( V_22 -> V_56 -> V_57 , V_92 ) ) {
F_16 ( L_39 ) ;
return - V_9 ;
}
V_90 = V_22 -> V_96 . V_97 . V_98 ;
if ( ! V_90 ) {
F_16 ( L_40 ) ;
return - V_9 ;
}
F_65 ( & V_25 , F_17 ( V_20 , 1 ) ) ;
V_16 = F_68 ( V_90 , & V_25 ) ;
return V_16 ;
}
struct V_100 * F_69 ( const char * V_101 )
{
struct V_100 * V_102 ;
F_31 ( & V_103 ) ;
F_70 (lprof, &lustre_profile_list, lp_list) {
if ( ! strcmp ( V_102 -> V_104 , V_101 ) ) {
V_102 -> V_105 ++ ;
F_33 ( & V_103 ) ;
return V_102 ;
}
}
F_33 ( & V_103 ) ;
return NULL ;
}
static int F_71 ( int V_106 , char * V_101 , int V_107 , char * V_108 ,
int V_109 , char * V_110 )
{
struct V_100 * V_102 ;
int V_52 = 0 ;
F_8 ( V_88 , L_41 , V_101 ) ;
V_102 = F_72 ( sizeof( * V_102 ) , V_111 ) ;
if ( ! V_102 )
return - V_68 ;
F_24 ( & V_102 -> V_112 ) ;
F_39 ( V_106 == ( strlen ( V_101 ) + 1 ) ) ;
V_102 -> V_104 = F_73 ( V_101 , V_106 , V_111 ) ;
if ( ! V_102 -> V_104 ) {
V_52 = - V_68 ;
goto V_113;
}
F_39 ( V_107 == ( strlen ( V_108 ) + 1 ) ) ;
V_102 -> V_114 = F_73 ( V_108 , V_107 , V_111 ) ;
if ( ! V_102 -> V_114 ) {
V_52 = - V_68 ;
goto V_115;
}
if ( V_109 > 0 ) {
F_39 ( V_109 == ( strlen ( V_110 ) + 1 ) ) ;
V_102 -> V_116 = F_73 ( V_110 , V_109 , V_111 ) ;
if ( ! V_102 -> V_116 ) {
V_52 = - V_68 ;
goto V_117;
}
}
F_31 ( & V_103 ) ;
V_102 -> V_105 = 1 ;
V_102 -> V_118 = false ;
F_74 ( & V_102 -> V_112 , & V_119 ) ;
F_33 ( & V_103 ) ;
return V_52 ;
V_117:
F_75 ( V_102 -> V_114 ) ;
V_115:
F_75 ( V_102 -> V_104 ) ;
V_113:
F_75 ( V_102 ) ;
return V_52 ;
}
void F_76 ( const char * V_101 )
{
struct V_100 * V_102 ;
F_8 ( V_88 , L_42 , V_101 ) ;
V_102 = F_69 ( V_101 ) ;
if ( V_102 ) {
F_31 ( & V_103 ) ;
V_102 -> V_105 -- ;
F_77 ( & V_102 -> V_112 ) ;
V_102 -> V_118 = true ;
F_33 ( & V_103 ) ;
F_78 ( V_102 ) ;
}
}
void F_78 ( struct V_100 * V_102 )
{
F_31 ( & V_103 ) ;
if ( -- V_102 -> V_105 > 0 ) {
F_39 ( V_102 -> V_105 > 0 ) ;
F_33 ( & V_103 ) ;
return;
}
F_33 ( & V_103 ) ;
F_39 ( ! V_102 -> V_105 ) ;
F_39 ( V_102 -> V_118 ) ;
F_75 ( V_102 -> V_104 ) ;
F_75 ( V_102 -> V_114 ) ;
F_75 ( V_102 -> V_116 ) ;
F_75 ( V_102 ) ;
}
void F_79 ( void )
{
struct V_100 * V_102 , * V_120 ;
F_31 ( & V_103 ) ;
F_80 (lprof, n, &lustre_profile_list, lp_list) {
F_77 ( & V_102 -> V_112 ) ;
V_102 -> V_118 = true ;
F_33 ( & V_103 ) ;
F_78 ( V_102 ) ;
F_31 ( & V_103 ) ;
}
F_33 ( & V_103 ) ;
}
static int F_81 ( char * V_4 , int V_121 , struct V_19 * V_20 )
{
if ( F_2 ( V_4 , V_122 , NULL ) == 0 )
V_123 = V_121 ;
else if ( F_2 ( V_4 , V_124 , NULL ) == 0 )
V_125 = V_121 ;
else if ( F_2 ( V_4 , V_126 , NULL ) == 0 )
V_127 = V_121 ;
else if ( F_2 ( V_4 , V_128 , NULL ) == 0 )
V_129 = V_121 ;
else if ( F_2 ( V_4 , V_130 , NULL ) == 0 )
V_131 = V_121 ;
else if ( F_2 ( V_4 , V_132 , NULL ) == 0 )
F_82 ( V_133 , F_17 ( V_20 , 2 ) ,
V_134 + 1 ) ;
else
return - V_9 ;
F_8 ( V_27 , L_43 , V_4 , V_121 ) ;
return 0 ;
}
void F_83 ( int (* F_84)( struct V_19 * V_20 ) )
{
V_135 = F_84 ;
}
static int F_85 ( struct V_19 * V_20 )
{
char * V_136 = F_17 ( V_20 , 1 ) ;
char * V_137 = F_17 ( V_20 , 2 ) ;
char * V_138 [] = {
[ 0 ] = L_44 ,
[ 1 ] = L_45 ,
[ 2 ] = V_136 ,
[ 3 ] = NULL
} ;
T_3 V_139 ;
T_3 V_140 ;
int V_16 ;
if ( strcmp ( V_137 , V_141 ) != 0 ) {
F_16 ( L_46 , V_137 ) ;
return - V_9 ;
}
V_139 = F_86 () ;
V_16 = F_87 ( V_138 [ 0 ] , V_138 , NULL , V_142 ) ;
V_140 = F_86 () ;
if ( V_16 < 0 ) {
F_16 (
L_47 ,
V_138 [ 0 ] , V_138 [ 1 ] , V_138 [ 2 ] , V_16 ,
( long ) F_88 ( V_140 , V_139 ) ) ;
} else {
F_8 ( V_143 , L_48 ,
V_138 [ 0 ] , V_138 [ 1 ] , V_138 [ 2 ] ,
( long ) F_88 ( V_140 , V_139 ) ) ;
V_16 = 0 ;
}
return V_16 ;
}
int F_89 ( struct V_19 * V_20 )
{
struct V_21 * V_22 ;
int V_52 ;
F_39 ( V_20 && ! F_20 ( V_20 ) ) ;
F_8 ( V_27 , L_49 , V_20 -> V_144 ) ;
switch ( V_20 -> V_144 ) {
case V_145 : {
V_52 = F_14 ( V_20 ) ;
goto V_28;
}
case V_146 : {
F_8 ( V_27 , L_50 ,
F_17 ( V_20 , 1 ) , V_20 -> V_147 ,
F_90 ( V_20 -> V_147 ) ) ;
V_52 = F_91 ( F_17 ( V_20 , 1 ) , V_20 -> V_147 ) ;
goto V_28;
}
case V_148 : {
F_8 ( V_27 , L_51 ,
( V_20 -> V_76 < 2 || F_15 ( V_20 , 1 ) == 0 )
? L_52 : F_17 ( V_20 , 1 ) ) ;
V_52 = F_92 ( F_17 ( V_20 , 1 ) ) ;
goto V_28;
}
case V_149 : {
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
case V_150 : {
F_8 ( V_27 , L_54 ,
F_17 ( V_20 , 1 ) ) ;
F_76 ( F_17 ( V_20 , 1 ) ) ;
V_52 = 0 ;
goto V_28;
}
case V_151 : {
F_8 ( V_27 , L_55 ,
V_152 , V_20 -> V_99 ) ;
V_152 = F_93 ( V_20 -> V_99 , 1U ) ;
V_153 = 1 ;
V_52 = 0 ;
goto V_28;
}
case V_154 : {
V_52 = 0 ;
goto V_28;
}
case V_155 : {
F_5 ( 0x15a , L_56 ) ;
V_52 = 0 ;
goto V_28;
}
case V_156 : {
struct V_157 * V_158 ;
V_158 = F_94 ( V_20 , 1 ) ;
F_8 ( V_27 , L_57 , V_158 -> V_159 ,
V_158 -> V_160 , V_158 -> V_161 , V_158 -> V_162 ) ;
V_52 = 0 ;
goto V_28;
}
case V_163 : {
char * V_15 ;
if ( ( F_2 ( F_17 ( V_20 , 1 ) ,
V_164 , NULL ) == 0 ) &&
V_135 ) {
V_52 = (* V_135)( V_20 ) ;
goto V_28;
} else if ( ( F_2 ( F_17 ( V_20 , 1 ) ,
V_165 , & V_15 ) == 0 ) ) {
V_52 = F_81 ( V_15 , V_20 -> V_99 , V_20 ) ;
if ( V_52 != 0 )
F_95 ( L_58 , V_15 ) ;
V_52 = 0 ;
goto V_28;
} else if ( ( F_2 ( F_17 ( V_20 , 1 ) ,
V_166 , & V_15 ) == 0 ) &&
V_167 ) {
V_52 = (* V_167)( V_20 ) ;
goto V_28;
}
break;
}
case V_168 : {
V_52 = F_85 ( V_20 ) ;
goto V_28;
}
}
V_22 = F_96 ( F_17 ( V_20 , 0 ) ) ;
if ( ! V_22 ) {
if ( ! F_15 ( V_20 , 0 ) )
F_16 ( L_59 ) ;
else
F_16 ( L_60 ,
F_17 ( V_20 , 0 ) ) ;
V_52 = - V_9 ;
goto V_28;
}
switch ( V_20 -> V_144 ) {
case V_169 : {
V_52 = F_38 ( V_22 , V_20 ) ;
goto V_28;
}
case V_170 : {
V_52 = F_48 ( V_22 , V_20 ) ;
V_52 = 0 ;
goto V_28;
}
case V_171 : {
V_52 = F_50 ( V_22 , V_20 ) ;
V_52 = 0 ;
goto V_28;
}
case V_172 : {
V_52 = F_64 ( V_22 , V_20 ) ;
V_52 = 0 ;
goto V_28;
}
case V_173 : {
V_52 = F_67 ( V_22 , V_20 ) ;
V_52 = 0 ;
goto V_28;
}
case V_174 : {
V_52 = F_97 ( V_22 , F_17 ( V_20 , 2 ) ) ;
V_52 = 0 ;
goto V_28;
}
case V_175 : {
V_52 = F_98 ( V_22 , F_17 ( V_20 , 2 ) ,
F_17 ( V_20 , 3 ) ) ;
V_52 = 0 ;
goto V_28;
}
case V_176 : {
V_52 = F_99 ( V_22 , F_17 ( V_20 , 2 ) ,
F_17 ( V_20 , 3 ) ) ;
V_52 = 0 ;
goto V_28;
}
case V_177 : {
V_52 = F_100 ( V_22 , F_17 ( V_20 , 2 ) ) ;
V_52 = 0 ;
goto V_28;
}
default: {
V_52 = F_101 ( V_22 , sizeof( * V_20 ) , V_20 ) ;
goto V_28;
}
}
V_28:
if ( ( V_52 < 0 ) && ! ( V_20 -> V_144 & V_178 ) ) {
F_95 ( L_61 , V_52 ,
V_20 -> V_144 ) ;
V_52 = 0 ;
}
return V_52 ;
}
int F_102 ( char * V_179 , struct V_180 * V_181 ,
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
F_16 ( L_62 , V_20 -> V_144 ) ;
return - V_9 ;
}
V_185 . V_195 = & V_187 ;
V_187 . V_196 = V_182 ;
for ( V_189 = 1 ; V_189 < V_20 -> V_76 ; V_189 ++ ) {
V_2 = F_94 ( V_20 , V_189 ) ;
if ( F_2 ( V_2 , V_179 , & V_2 ) ) {
return - V_197 ;
}
V_188 = strchr ( V_2 , '=' ) ;
if ( ! V_188 || ( * ( V_188 + 1 ) == 0 ) ) {
F_16 ( L_63 , V_2 ) ;
continue;
}
V_190 = V_188 - V_2 ;
V_188 ++ ;
V_191 = strlen ( V_188 ) ;
V_192 = 0 ;
V_193 = 0 ;
while ( V_181 [ V_193 ] . V_24 ) {
V_183 = & V_181 [ V_193 ] ;
if ( ! F_2 ( V_2 , V_183 -> V_24 , NULL ) &&
V_190 == strlen ( V_183 -> V_24 ) ) {
V_192 ++ ;
V_16 = - V_198 ;
if ( V_183 -> V_199 && V_183 -> V_199 -> V_200 ) {
T_4 V_201 ;
V_201 = F_103 () ;
F_104 ( V_202 ) ;
V_16 = V_183 -> V_199 -> V_200 ( & V_185 ,
( const char V_203 * ) V_188 ,
V_191 , NULL ) ;
F_104 ( V_201 ) ;
}
break;
}
V_193 ++ ;
}
if ( ! V_192 ) {
F_16 ( L_64 ,
( int ) strlen ( V_179 ) - 1 , V_179 ,
( char * ) F_17 ( V_20 , 0 ) , V_2 ) ;
V_194 ++ ;
} else if ( V_16 < 0 ) {
F_16 ( L_65 ,
V_179 , V_183 -> V_24 , V_16 ) ;
V_16 = 0 ;
} else {
F_8 ( V_88 , L_66 ,
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
int F_105 ( const struct V_204 * V_205 ,
struct V_206 * V_207 ,
struct V_208 * V_209 , void * V_182 )
{
struct V_210 * V_211 = V_182 ;
int V_212 = V_209 -> V_213 ;
char * V_214 = ( char * ) ( V_209 + 1 ) ;
int V_16 = 0 ;
switch ( V_209 -> V_215 ) {
case V_216 : {
struct V_19 * V_20 , * V_217 ;
struct V_218 V_219 ;
char * V_220 = NULL ;
int V_221 = 0 ;
int V_222 = 0 , V_223 = 0 ;
V_20 = (struct V_19 * ) V_214 ;
if ( V_20 -> V_224 == F_106 ( V_225 ) ) {
F_107 ( V_20 ) ;
V_223 = 1 ;
}
V_16 = F_108 ( V_214 , V_212 ) ;
if ( V_16 )
goto V_28;
if ( V_20 -> V_144 == V_156 ) {
struct V_157 * V_158 = F_94 ( V_20 , 1 ) ;
F_109 ( V_158 , V_223 ,
F_15 ( V_20 , 1 ) ) ;
F_8 ( V_88 , L_67 ,
V_211 -> V_226 , V_158 -> V_160 ) ;
if ( V_158 -> V_160 & V_227 ) {
V_211 -> V_226 = V_228 ;
if ( V_158 -> V_160 & V_229 ) {
V_211 -> V_226 |= V_230 ;
F_8 ( V_88 , L_68 ,
V_158 -> V_159 ) ;
} else if ( ( V_158 -> V_160 & V_231 ) ||
( V_211 -> V_232 &&
F_110 ( V_211 -> V_232 ,
V_158 -> V_161 ) ) ) {
V_211 -> V_226 |= V_233 ;
F_8 ( V_88 , L_69 ,
V_158 -> V_159 ) ;
}
} else if ( V_158 -> V_160 & V_234 ) {
V_211 -> V_226 = 0 ;
}
}
if ( ! ( V_211 -> V_226 & V_235 ) &&
! ( V_211 -> V_226 & V_228 ) &&
( V_20 -> V_144 != V_156 ) ) {
F_95 ( L_70 ,
V_211 -> V_236 ,
V_211 -> V_237 . V_25 , V_211 -> V_226 ) ;
V_211 -> V_226 |= V_230 ;
}
if ( V_211 -> V_226 & V_230 ) {
F_8 ( V_88 , L_71 ,
V_211 -> V_226 ) ;
V_16 = 0 ;
break;
}
{
char * V_23 = F_17 ( V_20 , 1 ) ;
char * V_238 = F_17 ( V_20 , 2 ) ;
if ( ( V_20 -> V_144 == V_145 && V_23 &&
strcmp ( V_23 , L_72 ) == 0 ) ) {
F_95 ( L_73 ) ;
V_23 [ 2 ] = 't' ;
}
if ( ( V_20 -> V_144 == V_169 && V_238 &&
strcmp ( V_238 , L_74 ) == 0 ) ) {
F_8 ( V_11 , L_75 ) ;
V_238 [ 0 ] = '0' ;
V_238 [ 1 ] = 0 ;
}
}
if ( V_211 -> V_226 & V_233 ) {
F_8 ( V_88 , L_76 ,
V_20 -> V_144 ) ;
if ( V_20 -> V_144 == V_239 )
V_20 -> V_144 = V_240 ;
}
F_111 ( & V_219 , V_20 ) ;
if ( V_211 && V_211 -> V_236 &&
F_15 ( V_20 , 0 ) > 0 ) {
V_222 = 1 ;
V_221 = F_15 ( V_20 , 0 ) +
sizeof( V_211 -> V_236 ) * 2 + 4 ;
V_220 = F_112 ( V_111 , L_77 ,
F_17 ( V_20 , 0 ) ,
V_211 -> V_236 ) ;
if ( ! V_220 ) {
V_16 = - V_68 ;
goto V_28;
}
F_113 ( & V_219 , 0 , V_220 ) ;
F_8 ( V_88 , L_78 ,
V_20 -> V_144 , V_220 ) ;
}
if ( V_211 && V_211 -> V_236 &&
V_20 -> V_144 == V_145 ) {
F_113 ( & V_219 , 2 ,
V_211 -> V_237 . V_25 ) ;
}
if ( V_211 && ! V_211 -> V_236 &&
V_20 -> V_144 == V_241 ) {
F_114 ( & V_219 , 2 , V_219 . V_242 [ 1 ] ,
V_219 . V_243 [ 1 ] ) ;
F_114 ( & V_219 , 1 , V_219 . V_242 [ 0 ] ,
V_219 . V_243 [ 0 ] ) ;
F_113 ( & V_219 , 0 ,
V_211 -> V_244 ) ;
}
V_217 = F_115 ( V_20 -> V_144 , & V_219 ) ;
V_217 -> V_99 = V_20 -> V_99 ;
V_217 -> V_245 = V_20 -> V_245 ;
if ( V_20 -> V_246 != 0 &&
( V_20 -> V_147 >> 32 ) == 0 ) {
T_2 V_247 = ( T_2 ) ( V_20 -> V_147 & 0xffffffff ) ;
V_217 -> V_147 =
F_116 ( F_117 ( V_20 -> V_246 , 0 ) , V_247 ) ;
F_95 ( L_79 ,
V_20 -> V_246 , V_247 ,
F_90 ( V_217 -> V_147 ) ) ;
} else {
V_217 -> V_147 = V_20 -> V_147 ;
}
V_217 -> V_246 = 0 ;
V_16 = F_89 ( V_217 ) ;
F_118 ( V_217 ) ;
if ( V_222 )
F_75 ( V_220 ) ;
break;
}
default:
F_16 ( L_80 ,
V_209 -> V_215 ) ;
break;
}
V_28:
if ( V_16 ) {
F_16 ( L_81 ,
V_207 -> V_248 -> V_249 -> V_31 , V_16 ) ;
F_119 ( NULL , V_207 , V_209 , V_182 ) ;
}
return V_16 ;
}
int F_120 ( const struct V_204 * V_205 , struct V_250 * V_251 ,
char * V_24 , struct V_210 * V_252 )
{
struct V_253 V_254 = { 0 , 0 } ;
struct V_206 * V_255 ;
T_5 V_256 ;
int V_16 ;
F_8 ( V_11 , L_82 , V_24 ) ;
V_16 = F_121 ( V_205 , V_251 , & V_255 , NULL , V_24 , V_257 ) ;
if ( V_16 )
return V_16 ;
V_16 = F_122 ( V_205 , V_255 , V_258 , NULL ) ;
if ( V_16 )
goto V_259;
if ( V_252 ) {
V_254 . V_260 = V_252 -> V_261 ;
V_256 = V_252 -> V_262 ;
F_39 ( V_256 ) ;
} else {
V_256 = F_105 ;
}
V_254 . V_263 = 0 ;
V_16 = F_123 ( V_205 , V_255 , V_256 , V_252 , & V_254 ) ;
F_8 ( V_88 , L_83 , V_24 ,
V_254 . V_260 + 1 , V_254 . V_263 , V_16 ) ;
if ( V_252 )
V_252 -> V_261 = V_254 . V_263 ;
V_259:
F_124 ( V_205 , V_255 ) ;
return V_16 ;
}
static int F_125 ( struct V_208 * V_209 , char * V_1 ,
int V_264 )
{
struct V_19 * V_20 = (struct V_19 * ) ( V_209 + 1 ) ;
char * V_4 = V_1 ;
char * V_140 = V_1 + V_264 ;
int V_16 = 0 ;
F_39 ( V_209 -> V_215 == V_216 ) ;
V_16 = F_108 ( V_20 , V_209 -> V_213 ) ;
if ( V_16 < 0 )
return V_16 ;
V_4 += snprintf ( V_4 , V_140 - V_4 , L_84 , V_20 -> V_144 ) ;
if ( V_20 -> V_245 )
V_4 += snprintf ( V_4 , V_140 - V_4 , L_85 ,
V_20 -> V_245 ) ;
if ( V_20 -> V_99 )
V_4 += snprintf ( V_4 , V_140 - V_4 , L_86 , V_20 -> V_99 ) ;
if ( V_20 -> V_147 ) {
char V_265 [ V_266 ] ;
F_126 ( V_20 -> V_147 , V_265 , sizeof( V_265 ) ) ;
V_4 += snprintf ( V_4 , V_140 - V_4 , L_87 ,
V_265 , V_20 -> V_147 ) ;
}
if ( V_20 -> V_144 == V_156 ) {
struct V_157 * V_158 = F_94 ( V_20 , 1 ) ;
V_4 += snprintf ( V_4 , V_140 - V_4 , L_88 ,
V_158 -> V_159 , V_158 -> V_160 ,
V_158 -> V_161 , V_158 -> V_162 ) ;
} else {
int V_189 ;
for ( V_189 = 0 ; V_189 < V_20 -> V_76 ; V_189 ++ ) {
V_4 += snprintf ( V_4 , V_140 - V_4 , L_89 , V_189 ,
F_17 ( V_20 , V_189 ) ) ;
}
}
V_4 += snprintf ( V_4 , V_140 - V_4 , L_90 ) ;
V_16 = V_4 - V_1 ;
return V_16 ;
}
int F_119 ( const struct V_204 * V_205 ,
struct V_206 * V_207 ,
struct V_208 * V_209 , void * V_182 )
{
char * V_267 ;
int V_16 = 0 ;
V_267 = F_72 ( 256 , V_111 ) ;
if ( ! V_267 )
return - V_68 ;
if ( V_209 -> V_215 == V_216 ) {
F_125 ( V_209 , V_267 , 256 ) ;
F_127 ( V_268 , L_91 , V_267 ) ;
} else {
F_127 ( V_268 , L_92 , V_209 -> V_215 ) ;
V_16 = - V_9 ;
}
F_75 ( V_267 ) ;
return V_16 ;
}
int F_128 ( struct V_21 * V_22 )
{
char V_269 [ 3 ] = L_93 ;
struct V_19 * V_20 ;
struct V_218 V_219 ;
int V_16 ;
if ( ! V_22 ) {
F_16 ( L_94 ) ;
return - V_270 ;
}
if ( V_22 -> V_77 )
strcat ( V_269 , L_95 ) ;
if ( V_22 -> V_78 )
strcat ( V_269 , L_96 ) ;
F_8 ( V_88 , L_97 ,
V_22 -> V_31 , V_269 ) ;
F_129 ( & V_219 , V_22 -> V_31 ) ;
F_113 ( & V_219 , 1 , V_269 ) ;
V_20 = F_115 ( V_171 , & V_219 ) ;
if ( F_20 ( V_20 ) )
return F_21 ( V_20 ) ;
V_16 = F_89 ( V_20 ) ;
if ( V_16 ) {
F_16 ( L_98 , V_16 , V_22 -> V_31 ) ;
goto V_28;
}
V_20 -> V_144 = V_170 ;
V_16 = F_89 ( V_20 ) ;
if ( V_16 )
F_16 ( L_99 , V_16 , V_22 -> V_31 ) ;
V_28:
F_118 ( V_20 ) ;
return V_16 ;
}
static unsigned int
F_130 ( struct V_271 * V_272 , const void * V_2 , unsigned int V_273 )
{
return F_131 ( ( (struct V_47 * ) V_2 ) -> V_25 ,
sizeof( ( (struct V_47 * ) V_2 ) -> V_25 ) , V_273 ) ;
}
static void *
F_132 ( struct V_274 * V_275 )
{
struct V_53 * exp ;
exp = F_133 ( V_275 , struct V_53 , V_276 ) ;
return & exp -> V_277 ;
}
static int
F_134 ( const void * V_2 , struct V_274 * V_275 )
{
struct V_53 * exp ;
F_39 ( V_2 ) ;
exp = F_133 ( V_275 , struct V_53 , V_276 ) ;
return F_135 ( V_2 , & exp -> V_277 ) &&
! exp -> V_278 ;
}
static void *
F_136 ( struct V_274 * V_275 )
{
return F_133 ( V_275 , struct V_53 , V_276 ) ;
}
static void
F_137 ( struct V_271 * V_272 , struct V_274 * V_275 )
{
struct V_53 * exp ;
exp = F_133 ( V_275 , struct V_53 , V_276 ) ;
F_138 ( exp ) ;
}
static void
F_139 ( struct V_271 * V_272 , struct V_274 * V_275 )
{
struct V_53 * exp ;
exp = F_133 ( V_275 , struct V_53 , V_276 ) ;
F_43 ( exp ) ;
}
