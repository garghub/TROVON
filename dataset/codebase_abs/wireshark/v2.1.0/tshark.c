static T_1
F_1 ( T_2 V_1 , T_2 V_2 )
{
return strcmp ( ( ( const struct V_3 * ) V_1 ) -> V_4 ,
( ( const struct V_3 * ) V_2 ) -> V_4 ) ;
}
static void
F_2 ( T_3 V_5 , T_3 T_4 V_6 )
{
fprintf ( V_7 , L_1 ,
( (struct V_3 * ) V_5 ) -> V_4 ,
( (struct V_3 * ) V_5 ) -> V_8 ) ;
}
static void
F_3 ( void ) {
int V_9 ;
struct V_3 * V_10 ;
T_5 * V_11 = NULL ;
V_10 = F_4 ( struct V_3 , V_12 ) ;
fprintf ( V_7 , L_2 ) ;
for ( V_9 = 0 ; V_9 < V_12 ; V_9 ++ ) {
if ( F_5 ( V_9 ) ) {
V_10 [ V_9 ] . V_4 = F_6 ( V_9 ) ;
V_10 [ V_9 ] . V_8 = F_7 ( V_9 ) ;
V_11 = F_8 ( V_11 , & V_10 [ V_9 ] , F_1 ) ;
}
}
F_9 ( V_11 , F_2 , NULL ) ;
F_10 ( V_11 ) ;
F_11 ( V_10 ) ;
}
static void
F_12 ( void ) {
int V_9 ;
struct V_3 * V_10 ;
T_5 * V_11 = NULL ;
const char * V_13 = L_3 ;
const char * V_14 = L_4 ;
V_10 = F_4 ( struct V_3 , V_12 ) ;
fprintf ( V_7 , L_5 ) ;
for ( V_9 = 0 ; V_15 [ V_9 ] . V_16 != NULL ; V_9 ++ ) {
V_10 [ V_9 ] . V_4 = V_15 [ V_9 ] . V_16 ;
V_10 [ V_9 ] . V_8 = ( V_15 [ V_9 ] . type == V_17 ) ? V_13 : V_14 ;
V_11 = F_8 ( V_11 , & V_10 [ V_9 ] , F_1 ) ;
}
F_9 ( V_11 , F_2 , NULL ) ;
F_10 ( V_11 ) ;
F_11 ( V_10 ) ;
}
static void
F_13 ( T_6 * V_18 )
{
fprintf ( V_18 , L_6 ) ;
fprintf ( V_18 , L_7 ) ;
fprintf ( V_18 , L_6 ) ;
#ifdef F_14
fprintf ( V_18 , L_8 ) ;
fprintf ( V_18 , L_9 ) ;
fprintf ( V_18 , L_10 ) ;
fprintf ( V_18 , L_11 ) ;
fprintf ( V_18 , L_12 ) ;
#ifdef F_15
fprintf ( V_18 , L_13 ) ;
#endif
#ifdef F_16
fprintf ( V_18 , L_14 , V_19 ) ;
#endif
fprintf ( V_18 , L_15 ) ;
fprintf ( V_18 , L_16 ) ;
fprintf ( V_18 , L_17 ) ;
fprintf ( V_18 , L_6 ) ;
fprintf ( V_18 , L_18 ) ;
fprintf ( V_18 , L_19 ) ;
fprintf ( V_18 , L_20 ) ;
fprintf ( V_18 , L_21 ) ;
fprintf ( V_18 , L_22 ) ;
fprintf ( V_18 , L_23 ) ;
fprintf ( V_18 , L_24 ) ;
fprintf ( V_18 , L_25 ) ;
fprintf ( V_18 , L_26 ) ;
#endif
#ifdef F_17
fprintf ( V_18 , L_27 ) ;
fprintf ( V_18 , L_28 ) ;
#endif
fprintf ( V_18 , L_29 ) ;
fprintf ( V_18 , L_30 ) ;
fprintf ( V_18 , L_6 ) ;
fprintf ( V_18 , L_31 ) ;
fprintf ( V_18 , L_32 ) ;
fprintf ( V_18 , L_33 ) ;
fprintf ( V_18 , L_34 ) ;
fprintf ( V_18 , L_35 ) ;
fprintf ( V_18 , L_36 ) ;
fprintf ( V_18 , L_37 ) ;
fprintf ( V_18 , L_38 , V_20 ) ;
fprintf ( V_18 , L_39 ) ;
fprintf ( V_18 , L_40 ) ;
fprintf ( V_18 , L_41 ) ;
fprintf ( V_18 , L_42 ) ;
fprintf ( V_18 , L_43 ) ;
fprintf ( V_18 , L_44 ) ;
fprintf ( V_18 , L_45 ) ;
fprintf ( V_18 , L_46 ) ;
fprintf ( V_18 , L_47 ) ;
fprintf ( V_18 , L_48 ) ;
fprintf ( V_18 , L_49 ) ;
fprintf ( V_18 , L_50 ) ;
fprintf ( V_18 , L_51 ) ;
fprintf ( V_18 , L_52 ) ;
fprintf ( V_18 , L_53 ) ;
fprintf ( V_18 , L_54 ) ;
fprintf ( V_18 , L_55 ) ;
fprintf ( V_18 , L_56 ) ;
fprintf ( V_18 , L_57 ) ;
fprintf ( V_18 , L_58 ) ;
fprintf ( V_18 , L_59 ) ;
fprintf ( V_18 , L_60 ) ;
fprintf ( V_18 , L_61 ) ;
fprintf ( V_18 , L_62 ) ;
fprintf ( V_18 , L_63 ) ;
fprintf ( V_18 , L_64 ) ;
fprintf ( V_18 , L_65 ) ;
fprintf ( V_18 , L_66 ) ;
fprintf ( V_18 , L_67 ) ;
fprintf ( V_18 , L_68 ) ;
fprintf ( V_18 , L_69 ) ;
fprintf ( V_18 , L_70 ) ;
fprintf ( V_18 , L_71 ) ;
fprintf ( V_18 , L_72 ) ;
fprintf ( V_18 , L_73 ) ;
fprintf ( V_18 , L_74 ) ;
fprintf ( V_18 , L_75 ) ;
fprintf ( V_18 , L_76 ) ;
fprintf ( V_18 , L_77 ) ;
fprintf ( V_18 , L_78 ) ;
fprintf ( V_18 , L_79 ) ;
fprintf ( V_18 , L_80 ) ;
fprintf ( V_18 , L_81 ) ;
fprintf ( V_18 , L_82 ) ;
fprintf ( V_18 , L_83 ) ;
fprintf ( V_18 , L_84 ) ;
fprintf ( V_18 , L_85 ) ;
fprintf ( V_18 , L_86 ) ;
fprintf ( V_18 , L_87 ) ;
fprintf ( V_18 , L_6 ) ;
fprintf ( V_18 , L_88 ) ;
fprintf ( V_18 , L_89 ) ;
fprintf ( V_18 , L_90 ) ;
fprintf ( V_18 , L_91 ) ;
fprintf ( V_18 , L_92 ) ;
fprintf ( V_18 , L_93 ) ;
fprintf ( V_18 , L_94 ) ;
fprintf ( V_18 , L_95 ) ;
#ifdef F_18
fprintf ( V_18 , L_6 ) ;
fprintf ( V_18 , L_96 ) ;
fprintf ( V_18 , L_97 ) ;
fprintf ( V_18 , L_98 ) ;
fprintf ( V_18 , L_6 ) ;
#endif
}
static void
F_19 ( void )
{
T_6 * V_18 ;
V_18 = stdout ;
fprintf ( V_18 , L_99 , F_20 () ) ;
fprintf ( V_18 , L_6 ) ;
fprintf ( V_18 , L_100 ) ;
fprintf ( V_18 , L_6 ) ;
fprintf ( V_18 , L_101 ) ;
fprintf ( V_18 , L_102 ) ;
fprintf ( V_18 , L_103 ) ;
fprintf ( V_18 , L_104 ) ;
fprintf ( V_18 , L_105 ) ;
fprintf ( V_18 , L_106 ) ;
fprintf ( V_18 , L_107 ) ;
fprintf ( V_18 , L_108 ) ;
fprintf ( V_18 , L_109 ) ;
fprintf ( V_18 , L_110 ) ;
fprintf ( V_18 , L_111 ) ;
fprintf ( V_18 , L_6 ) ;
fprintf ( V_18 , L_112 ) ;
fprintf ( V_18 , L_113 ) ;
fprintf ( V_18 , L_114 ) ;
fprintf ( V_18 , L_6 ) ;
}
static void
F_21 ( const char * V_21 , const char * V_22 ,
T_3 V_18 )
{
if ( ( V_23 == NULL ) ||
( strcmp ( V_23 , V_21 ) != 0 ) ) {
fprintf ( ( T_6 * ) V_18 , L_115 , V_21 , V_22 ) ;
V_23 = V_21 ;
}
}
static void
F_22 ( const T_7 * T_8 V_6 , T_3 V_24 , T_3 V_18 )
{
int V_25 ;
const T_7 * V_26 ;
const T_7 * V_27 ;
V_25 = F_23 ( ( V_28 ) V_24 ) ;
if ( V_25 != - 1 ) {
V_26 = F_24 ( V_25 ) ;
V_27 = F_25 ( V_25 ) ;
F_26 ( V_26 != NULL ) ;
F_26 ( V_27 != NULL ) ;
if ( ( V_23 == NULL ) ||
( strcmp ( V_23 , V_26 ) != 0 ) ) {
fprintf ( ( T_6 * ) V_18 , L_115 ,
V_26 ,
V_27 ) ;
V_23 = V_26 ;
}
}
}
static void
F_27 ( const T_7 * T_8 V_6 , T_3 V_24 , T_3 V_29 )
{
int V_25 ;
const T_7 * V_30 ;
T_9 V_31 ;
F_26 ( V_24 ) ;
V_31 = ( T_9 ) V_29 ;
V_25 = F_23 ( ( V_28 ) V_24 ) ;
if ( V_25 != - 1 ) {
V_30 = F_24 ( V_25 ) ;
F_26 ( V_30 != NULL ) ;
if ( strcmp ( V_30 , V_31 -> V_32 ) == 0 ) {
if ( V_31 -> V_33 == 0 ) {
V_31 -> V_34 = ( V_28 ) V_24 ;
}
V_31 -> V_33 ++ ;
}
}
}
static T_1
F_28 ( T_2 V_35 , T_2 V_36 )
{
return strcmp ( ( const char * ) V_35 , ( const char * ) V_36 ) ;
}
static void
F_29 ( T_6 * V_18 )
{
V_23 = NULL ;
F_30 ( F_21 , ( T_3 ) V_18 , ( V_37 ) F_28 ) ;
}
static void
F_31 ( T_6 * V_18 , T_7 * V_21 )
{
V_23 = NULL ;
F_32 ( V_21 ,
F_22 ,
( T_3 ) V_18 ) ;
}
static T_10
F_33 ( const T_7 * V_38 )
{
T_7 * V_21 ;
T_11 V_39 , V_40 ;
T_7 * V_41 ;
T_7 * V_42 ;
T_7 * V_43 ;
T_7 * V_44 ;
V_28 V_45 ;
T_12 V_46 ;
T_13 V_47 ;
struct V_48 V_49 ;
T_14 V_9 ;
char V_50 ;
F_26 ( V_38 ) ;
V_41 = F_34 ( V_38 ) ;
F_26 ( V_41 ) ;
V_21 = V_41 ;
V_42 = strchr ( V_21 , '=' ) ;
if ( V_42 == NULL ) {
F_35 ( L_116 , V_38 , V_20 ) ;
}
else {
* V_42 = '\0' ;
}
while ( V_21 [ 0 ] == ' ' )
V_21 ++ ;
while ( V_21 [ strlen ( V_21 ) - 1 ] == ' ' )
V_21 [ strlen ( V_21 ) - 1 ] = '\0' ;
V_46 = NULL ;
if ( ! ( * ( V_21 ) ) ) {
F_35 ( L_117 ) ;
}
else {
V_46 = F_36 ( V_21 ) ;
if ( ! V_46 ) {
F_35 ( L_118 , V_21 ) ;
}
}
if ( ! V_46 ) {
F_35 ( L_119 ) ;
F_29 ( V_7 ) ;
}
if ( V_42 == NULL || ! V_46 ) {
F_11 ( V_41 ) ;
return FALSE ;
}
if ( * ( V_42 + 1 ) != '=' ) {
F_35 ( L_120 , V_21 , V_42 + 1 ) ;
}
else {
V_42 ++ ;
* V_42 = '\0' ;
}
V_42 ++ ;
V_43 = V_42 ;
V_42 = strchr ( V_43 , ',' ) ;
if ( V_42 == NULL ) {
F_35 ( L_116 , V_38 , V_20 ) ;
}
else {
* V_42 = '\0' ;
}
V_47 = F_37 ( V_21 ) ;
switch ( V_47 ) {
case V_51 :
case V_52 :
case V_53 :
case V_54 :
switch ( sscanf ( V_43 , L_121 , & V_39 , & V_50 , & V_40 ) ) {
case 1 :
V_50 = '\0' ;
break;
case 3 :
if ( V_50 != ':' && V_50 != '-' ) {
F_35 ( L_122 , V_43 ) ;
F_11 ( V_41 ) ;
return FALSE ;
}
if ( V_50 == ':' ) {
if ( ( V_40 == 0 ) || ( ( T_14 ) V_39 + V_40 - 1 ) > V_55 ) {
F_35 ( L_122 , V_43 ) ;
F_11 ( V_41 ) ;
return FALSE ;
}
}
else if ( V_40 < V_39 ) {
F_35 ( L_122 , V_43 ) ;
F_11 ( V_41 ) ;
return FALSE ;
}
break;
default:
F_35 ( L_123 , V_43 ) ;
F_11 ( V_41 ) ;
return FALSE ;
}
break;
case V_56 :
case V_57 :
case V_58 :
case V_59 :
break;
default:
F_38 () ;
}
if ( V_42 == NULL ) {
F_35 ( L_124 , V_21 ) ;
F_31 ( V_7 , V_21 ) ;
F_11 ( V_41 ) ;
return FALSE ;
}
V_42 ++ ;
V_44 = V_42 ;
while ( V_44 [ 0 ] == ' ' )
V_44 ++ ;
while ( V_44 [ strlen ( V_44 ) - 1 ] == ' ' )
V_44 [ strlen ( V_44 ) - 1 ] = '\0' ;
V_45 = NULL ;
if ( ! ( * V_44 ) ) {
F_35 ( L_125 ) ;
}
else {
V_49 . V_33 = 0 ;
V_49 . V_32 = V_44 ;
V_49 . V_34 = NULL ;
F_32 ( V_21 , F_27 , & V_49 ) ;
if ( V_49 . V_33 != 0 ) {
V_45 = V_49 . V_34 ;
if ( V_49 . V_33 > 1 ) {
F_35 ( L_126 , V_44 , V_49 . V_33 ) ;
}
}
else {
if ( F_39 ( V_44 ) == - 1 ) {
F_35 ( L_127 , V_44 ) ;
} else {
F_35 ( L_128 ,
V_44 , V_21 ) ;
}
}
}
if ( ! V_45 ) {
F_35 ( L_124 , V_21 ) ;
F_31 ( V_7 , V_21 ) ;
F_11 ( V_41 ) ;
return FALSE ;
}
switch ( V_47 ) {
case V_51 :
case V_52 :
case V_53 :
case V_54 :
if ( V_50 == '\0' ) {
F_40 ( V_21 , V_39 , V_45 ) ;
} else if ( V_50 == ':' ) {
for ( V_9 = V_39 ; V_9 < ( T_14 ) V_39 + V_40 ; V_9 ++ ) {
F_40 ( V_21 , ( T_11 ) V_9 , V_45 ) ;
}
} else {
for ( V_9 = V_39 ; V_9 <= V_40 ; V_9 ++ ) {
F_40 ( V_21 , ( T_11 ) V_9 , V_45 ) ;
}
}
break;
case V_56 :
case V_57 :
case V_58 :
case V_59 :
F_41 ( V_21 , V_43 , V_45 ) ;
break;
default:
F_38 () ;
}
F_11 ( V_41 ) ;
return TRUE ;
}
static void
F_42 ( const T_7 * V_60 , T_15 V_61 ,
const T_7 * V_62 , T_3 V_29 )
{
if ( ( V_61 & V_63 & V_64 . V_65 ) == 0 &&
V_64 . V_65 != 0 ) {
return;
}
F_43 ( V_60 , V_61 , V_62 , V_29 ) ;
}
static char *
F_44 ( const char * V_66 )
{
char * V_67 ;
if ( strcmp ( V_66 , L_129 ) == 0 ) {
V_67 = F_34 ( L_130 ) ;
} else {
V_67 = F_45 ( L_131 , V_66 ) ;
}
return V_67 ;
}
static void
F_46 ( void ) {
T_7 * V_68 , * V_69 ;
if ( F_47 () ) {
V_68 = F_48 () ;
V_69 = F_49 () ;
fprintf ( V_7 , L_132 ,
V_68 , V_69 ) ;
F_11 ( V_68 ) ;
F_11 ( V_69 ) ;
if ( F_50 () ) {
fprintf ( V_7 , L_133 ) ;
}
fprintf ( V_7 , L_6 ) ;
}
}
static void
F_51 ( T_16 * V_70 )
{
F_52 ( V_70 ) ;
}
static void
F_53 ( T_16 * V_70 )
{
#ifdef F_14
F_54 ( V_70 , L_134 ) ;
F_55 ( V_70 ) ;
#endif
F_56 ( V_70 ) ;
}
int
main ( int V_71 , char * V_72 [] )
{
T_16 * V_73 ;
T_16 * V_74 ;
char * V_75 ;
int V_76 ;
static const struct V_77 V_78 [] = {
{ L_135 , V_79 , NULL , 'h' } ,
{ L_136 , V_79 , NULL , 'v' } ,
V_80
{ 0 , 0 , 0 , 0 }
} ;
T_10 V_81 = FALSE ;
#ifdef F_57
T_17 V_82 ;
#endif
char * V_83 , * V_84 ;
char * V_85 , * V_86 ;
char * V_87 ;
int V_88 , V_89 ;
int V_90 , V_91 ;
int V_92 , V_93 ;
int V_94 , V_95 ;
int V_96 ;
int V_97 ;
volatile int V_98 = 0 ;
#ifdef F_14
T_10 V_99 = FALSE ;
T_10 V_100 = FALSE ;
int V_101 ;
T_18 * V_102 ;
T_7 * V_103 ;
#else
T_10 V_104 = FALSE ;
#endif
T_10 V_105 = FALSE ;
#ifdef F_58
volatile int V_106 = V_107 ;
#else
volatile int V_106 = V_108 ;
#endif
volatile T_10 V_109 = FALSE ;
volatile int V_110 = V_111 ;
T_7 * volatile V_112 = NULL ;
T_7 * V_113 = NULL ;
T_7 * V_114 = NULL ;
#ifdef F_59
struct V_115 V_116 ;
#endif
T_19 * V_117 = NULL ;
T_19 * V_118 = NULL ;
T_7 * V_119 ;
T_20 * V_120 ;
char V_121 ;
int V_122 ;
T_7 * V_123 = NULL ;
T_5 * V_124 = NULL ;
T_5 * V_125 = NULL ;
T_5 * V_126 = NULL ;
T_7 * volatile V_127 = NULL ;
T_21 V_128 ;
#define F_60 "+2" OPTSTRING_CAPTURE_COMMON "C:d:e:E:F:gG:hH:" "K:lnN:o:O:PqQr:R:S:t:T:u:U:vVw:W:xX:Y:z:"
static const char V_129 [] = F_60 ;
F_61 ( L_137 , V_71 ) ;
setlocale ( V_130 , L_138 ) ;
F_62 ( V_131 , V_132 ) ;
#ifdef F_57
F_63 ( V_71 , V_72 ) ;
F_64 () ;
#if ! F_65 ( 2 , 31 , 0 )
F_66 ( NULL ) ;
#endif
#endif
F_67 () ;
F_68 () ;
F_46 () ;
V_75 = F_69 ( V_72 [ 0 ] , main ) ;
if ( V_75 != NULL ) {
fprintf ( V_7 , L_139 ,
V_75 ) ;
}
F_70 () ;
#ifdef F_57
F_71 () ;
if ( ! F_72 () && F_73 () >= 6 ) {
fprintf ( V_7 , L_140
L_141 ) ;
}
#endif
V_73 = F_74 ( F_51 ,
V_133 ) ;
V_74 = F_75 ( F_53 ) ;
F_76 ( L_99
L_6
L_142
L_6
L_142 ,
F_20 () , V_73 -> V_70 , V_74 -> V_70 ) ;
F_77 ( V_73 , TRUE ) ;
F_77 ( V_74 , TRUE ) ;
V_134 = 0 ;
while ( ( V_76 = F_78 ( V_71 , V_72 , V_129 , V_78 , NULL ) ) != - 1 ) {
switch ( V_76 ) {
case 'C' :
if ( F_79 ( V_135 , FALSE ) ) {
F_80 ( V_135 ) ;
} else {
F_35 ( L_143 , V_135 ) ;
return 1 ;
}
break;
case 'P' :
V_136 = TRUE ;
V_137 = TRUE ;
break;
case 'O' :
V_123 = F_34 ( V_135 ) ;
case 'V' :
V_138 = TRUE ;
V_136 = TRUE ;
break;
case 'x' :
V_139 = TRUE ;
V_136 = TRUE ;
break;
case 'X' :
F_81 ( V_135 ) ;
break;
default:
break;
}
}
if ( V_137 == - 1 )
V_137 = ( V_138 || V_139 ) ? FALSE : TRUE ;
V_122 =
V_140 |
V_141 |
V_142 |
V_143 |
V_144 |
V_145 |
V_146 | V_147 ;
F_82 ( NULL ,
( T_15 ) V_122 ,
F_42 , NULL ) ;
F_82 ( V_148 ,
( T_15 ) V_122 ,
F_42 , NULL ) ;
#ifdef F_14
F_82 ( V_149 ,
( T_15 ) V_122 ,
F_42 , NULL ) ;
F_82 ( V_150 ,
( T_15 ) V_122 ,
F_42 , NULL ) ;
#endif
F_83 ( V_131 , V_151 , V_152 ,
V_153 ) ;
#ifdef F_14
F_84 ( & V_154 ) ;
F_85 ( & V_155 , & V_156 ) ;
#endif
F_86 ( V_157 ) ;
F_87 ( V_158 ) ;
F_88 ( V_159 ) ;
F_89 () ;
#ifdef F_90
F_91 () ;
F_92 () ;
F_93 () ;
F_94 () ;
#endif
if ( ! F_95 ( V_160 , V_161 , NULL ,
NULL ) )
return 2 ;
#ifdef F_90
F_96 () ;
#endif
F_97 () ;
F_98 ( V_162 ) ;
F_99 ( V_163 ) ;
F_100 ( V_164 , NULL ) ;
F_101 ( V_165 , NULL ) ;
F_102 ( V_166 , NULL ) ;
if ( V_71 >= 2 && strcmp ( V_72 [ 1 ] , L_144 ) == 0 ) {
F_103 () ;
if ( V_71 == 2 )
F_104 () ;
else {
if ( strcmp ( V_72 [ 2 ] , L_145 ) == 0 )
F_105 () ;
else if ( strcmp ( V_72 [ 2 ] , L_146 ) == 0 ) {
F_106 ( & V_88 , & V_89 , & V_83 ,
& V_90 , & V_91 , & V_84 ) ;
F_107 ( NULL ) ;
}
else if ( strcmp ( V_72 [ 2 ] , L_147 ) == 0 )
F_108 () ;
else if ( strcmp ( V_72 [ 2 ] , L_148 ) == 0 )
F_107 ( NULL ) ;
else if ( strcmp ( V_72 [ 2 ] , L_149 ) == 0 )
F_109 () ;
else if ( strcmp ( V_72 [ 2 ] , L_150 ) == 0 ) {
return F_110 () ;
} else if ( strcmp ( V_72 [ 2 ] , L_151 ) == 0 )
F_104 () ;
else if ( strcmp ( V_72 [ 2 ] , L_152 ) == 0 )
F_111 () ;
else if ( strcmp ( V_72 [ 2 ] , L_153 ) == 0 )
F_112 () ;
else if ( strcmp ( V_72 [ 2 ] , L_154 ) == 0 ) {
#ifdef F_90
F_113 () ;
#endif
#ifdef F_114
F_115 () ;
#endif
}
else if ( strcmp ( V_72 [ 2 ] , L_155 ) == 0 )
F_116 () ;
else if ( strcmp ( V_72 [ 2 ] , L_156 ) == 0 )
F_117 () ;
else if ( strcmp ( V_72 [ 2 ] , L_157 ) == 0 )
F_19 () ;
else if ( strcmp ( V_72 [ 2 ] , L_158 ) == 0 )
F_19 () ;
else {
F_35 ( L_159 , V_72 [ 2 ] ) ;
return 1 ;
}
}
return 0 ;
}
F_118 () ;
F_61 ( L_160 ) ;
V_120 = F_106 ( & V_88 , & V_89 , & V_83 ,
& V_90 , & V_91 , & V_84 ) ;
if ( V_83 != NULL ) {
if ( V_88 != 0 ) {
F_35 ( L_161 ,
V_84 , F_119 ( V_88 ) ) ;
}
if ( V_89 != 0 ) {
F_35 ( L_162 ,
V_84 , F_119 ( V_89 ) ) ;
}
}
if ( V_84 != NULL ) {
if ( V_90 != 0 ) {
F_35 ( L_163 , V_84 ,
F_119 ( V_90 ) ) ;
}
if ( V_91 != 0 ) {
F_35 ( L_164 ,
V_84 , F_119 ( V_91 ) ) ;
}
F_11 ( V_84 ) ;
V_84 = NULL ;
}
F_120 ( V_167 , & V_87 , & V_96 ) ;
if ( V_87 != NULL ) {
F_35 ( L_165 ,
V_87 , F_119 ( V_96 ) ) ;
F_11 ( V_87 ) ;
}
F_121 ( & V_85 , & V_92 , & V_93 ,
& V_86 , & V_94 , & V_95 ) ;
F_122 ( & V_85 , & V_92 , & V_93 ,
& V_86 , & V_94 , & V_95 ) ;
if ( V_85 != NULL ) {
if ( V_92 != 0 ) {
F_35 ( L_166 ,
V_85 , F_119 ( V_92 ) ) ;
}
if ( V_93 != 0 ) {
F_35 ( L_167 ,
V_85 , F_119 ( V_93 ) ) ;
}
F_11 ( V_85 ) ;
}
if ( V_86 != NULL ) {
if ( V_94 != 0 ) {
F_35 (
L_168 , V_86 ,
F_119 ( V_94 ) ) ;
}
if ( V_95 != 0 ) {
F_35 (
L_169 , V_86 ,
F_119 ( V_95 ) ) ;
}
F_11 ( V_86 ) ;
}
F_123 ( & V_156 ) ;
V_168 = V_169 ;
V_170 = F_124 () ;
#ifdef F_125
V_171 = 1 ;
V_172 = 1 ;
#else
V_172 = 0 ;
#endif
V_134 = 1 ;
while ( ( V_76 = F_78 ( V_71 , V_72 , V_129 , V_78 , NULL ) ) != - 1 ) {
switch ( V_76 ) {
case '2' :
V_173 = TRUE ;
break;
case 'a' :
case 'b' :
case 'c' :
case 'f' :
case 'g' :
case 'i' :
case 'p' :
#ifdef F_17
case 'A' :
#endif
#ifdef F_15
case 'I' :
#endif
case 's' :
case 'w' :
case 'y' :
case V_174 :
#ifdef F_16
case 'B' :
#endif
#ifdef F_14
V_101 = F_126 ( & V_154 , V_76 , V_135 , & V_100 ) ;
if ( V_101 != 0 ) {
return V_101 ;
}
#else
if ( V_76 == 'w' ) {
V_175 = V_135 ;
} else {
V_104 = TRUE ;
V_81 = TRUE ;
}
#endif
break;
case 'C' :
break;
case 'd' :
if ( ! F_33 ( V_135 ) )
return 1 ;
break;
#if F_127 ( V_176 ) || F_127 ( V_177 )
case 'K' :
F_128 ( V_135 ) ;
break;
#endif
case 'D' :
#ifdef F_14
V_102 = F_129 ( & V_97 , & V_103 , NULL ) ;
if ( V_102 == NULL ) {
if ( V_97 == 0 )
F_35 ( L_170 ) ;
else {
F_35 ( L_142 , V_103 ) ;
F_11 ( V_103 ) ;
}
return 2 ;
}
F_130 ( V_102 ) ;
F_131 ( V_102 ) ;
return 0 ;
#else
V_104 = TRUE ;
V_81 = TRUE ;
#endif
break;
case 'e' :
F_132 ( V_170 , V_135 ) ;
break;
case 'E' :
if ( ! F_133 ( V_170 , V_135 ) ) {
F_35 ( L_171 , V_135 ) ;
F_134 ( V_7 ) ;
return 1 ;
}
break;
case 'F' :
V_106 = F_135 ( V_135 ) ;
if ( V_106 < 0 ) {
F_35 ( L_172 , V_135 ) ;
F_3 () ;
return 1 ;
}
break;
case 'W' :
if ( strchr ( V_135 , 'n' ) ) {
V_109 = TRUE ;
} else {
F_35 ( L_173 , V_135 ) ;
F_136 ( L_174 ) ;
return 1 ;
}
break;
case 'H' :
if ( ! F_137 ( V_135 ) )
{
F_35 ( L_175 , V_135 ) ;
return 1 ;
}
V_109 = TRUE ;
break;
case 'h' :
printf ( L_99
L_176
L_177 ,
F_20 () ) ;
F_13 ( stdout ) ;
return 0 ;
break;
case 'l' :
V_178 = TRUE ;
break;
case 'L' :
#ifdef F_14
V_99 = TRUE ;
#else
V_104 = TRUE ;
V_81 = TRUE ;
#endif
break;
case 'n' :
F_138 () ;
break;
case 'N' :
V_121 = F_139 ( V_135 , & V_179 ) ;
if ( V_121 != '\0' ) {
F_35 ( L_178 ,
V_121 ) ;
F_136 ( L_179
L_180
L_181
L_182
L_183
L_184 ) ;
return 1 ;
}
break;
case 'o' :
switch ( F_140 ( V_135 ) ) {
case V_180 :
break;
case V_181 :
F_35 ( L_185 , V_135 ) ;
return 1 ;
break;
case V_182 :
case V_183 :
F_35 ( L_186 , V_135 ) ;
return 1 ;
break;
}
break;
case 'q' :
V_105 = TRUE ;
break;
case 'Q' :
V_105 = TRUE ;
V_184 = TRUE ;
break;
case 'r' :
V_112 = F_34 ( V_135 ) ;
break;
case 'R' :
V_113 = V_135 ;
break;
case 'P' :
break;
case 'S' :
V_185 = V_135 ;
break;
case 't' :
if ( strcmp ( V_135 , L_187 ) == 0 )
F_86 ( V_157 ) ;
else if ( strcmp ( V_135 , L_188 ) == 0 )
F_86 ( V_186 ) ;
else if ( strcmp ( V_135 , L_189 ) == 0 )
F_86 ( V_187 ) ;
else if ( strcmp ( V_135 , L_190 ) == 0 )
F_86 ( V_188 ) ;
else if ( strcmp ( V_135 , L_191 ) == 0 )
F_86 ( V_189 ) ;
else if ( strcmp ( V_135 , L_192 ) == 0 )
F_86 ( V_190 ) ;
else if ( strcmp ( V_135 , L_193 ) == 0 )
F_86 ( V_191 ) ;
else if ( strcmp ( V_135 , L_194 ) == 0 )
F_86 ( V_192 ) ;
else if ( strcmp ( V_135 , L_195 ) == 0 )
F_86 ( V_193 ) ;
else if ( strcmp ( V_135 , L_196 ) == 0 )
F_86 ( V_194 ) ;
else {
F_35 ( L_197 , V_135 ) ;
F_136 ( L_198
L_199
L_200
L_201
L_202
L_203
L_204
L_205
L_206
L_207 ) ;
return 1 ;
}
break;
case 'T' :
V_136 = TRUE ;
if ( strcmp ( V_135 , L_208 ) == 0 ) {
V_195 = V_196 ;
V_168 = V_169 ;
} else if ( strcmp ( V_135 , L_209 ) == 0 ) {
V_195 = V_196 ;
V_168 = V_197 ;
} else if ( strcmp ( V_135 , L_210 ) == 0 ) {
V_195 = V_198 ;
V_138 = TRUE ;
V_137 = FALSE ;
} else if ( strcmp ( V_135 , L_211 ) == 0 ) {
V_195 = V_198 ;
V_138 = FALSE ;
V_137 = TRUE ;
} else if ( strcmp ( V_135 , L_151 ) == 0 ) {
V_195 = V_199 ;
V_138 = TRUE ;
V_137 = FALSE ;
} else {
F_35 ( L_212 , V_135 ) ;
F_136 ( L_213
L_214
L_215
L_216
L_217
L_218
L_219
L_220
L_221
L_222
L_223
L_224
L_225
L_226
L_227
L_228 ) ;
return 1 ;
}
break;
case 'u' :
if ( strcmp ( V_135 , L_229 ) == 0 )
F_88 ( V_159 ) ;
else if ( strcmp ( V_135 , L_230 ) == 0 )
F_88 ( V_200 ) ;
else {
F_35 ( L_231 , V_135 ) ;
F_136 ( L_232
L_233 ) ;
return 1 ;
}
break;
case 'U' :
{
T_5 * V_201 = NULL ;
if ( ! * V_135 ) {
F_35 ( L_234 ) ;
for ( V_201 = F_141 () ; V_201 ; V_201 = F_142 ( V_201 ) ) {
F_35 ( L_235 , ( const char * ) ( V_201 -> V_5 ) ) ;
}
return 1 ;
}
V_127 = F_34 ( V_135 ) ;
break;
}
case 'v' :
V_73 = F_74 ( F_51 ,
V_133 ) ;
V_74 = F_75 ( F_53 ) ;
F_143 ( L_236 , V_73 , V_74 ) ;
F_77 ( V_73 , TRUE ) ;
F_77 ( V_74 , TRUE ) ;
F_144 () ;
return 0 ;
case 'O' :
break;
case 'V' :
break;
case 'x' :
break;
case 'X' :
break;
case 'Y' :
V_114 = V_135 ;
break;
case 'z' :
if ( strcmp ( L_135 , V_135 ) == 0 ) {
fprintf ( V_7 , L_237 ) ;
F_145 () ;
return 0 ;
}
if ( ! F_146 ( V_135 ) ) {
F_35 ( L_238 , V_135 ) ;
F_145 () ;
return 1 ;
}
break;
case V_202 :
V_124 = F_147 ( V_124 , V_135 ) ;
break;
case V_203 :
V_125 = F_147 ( V_125 , V_135 ) ;
break;
case V_204 :
V_126 = F_147 ( V_126 , V_135 ) ;
break;
default:
case '?' :
switch( V_205 ) {
case 'F' :
F_3 () ;
break;
default:
F_13 ( V_7 ) ;
}
return 1 ;
break;
}
}
if ( V_199 != V_195 && 0 != F_148 ( V_170 ) ) {
F_35 ( L_239
L_240 ) ;
return 1 ;
} else if ( V_199 == V_195 && 0 == F_148 ( V_170 ) ) {
F_35 ( L_241
L_242 ) ;
return 1 ;
}
if ( V_172 < V_71 ) {
if ( V_112 != NULL ) {
if ( V_114 != NULL ) {
F_35 ( L_243
L_244 ) ;
return 1 ;
}
V_114 = F_149 ( V_71 , V_72 , V_172 ) ;
} else {
#ifdef F_14
T_22 V_9 ;
if ( V_154 . V_206 . V_207 ) {
F_35 ( L_245
L_246 ) ;
return 1 ;
}
for ( V_9 = 0 ; V_9 < V_154 . V_208 -> V_209 ; V_9 ++ ) {
T_23 V_210 ;
V_210 = F_150 ( V_154 . V_208 , T_23 , V_9 ) ;
if ( V_210 . V_207 == NULL ) {
V_210 . V_207 = F_149 ( V_71 , V_72 , V_172 ) ;
V_154 . V_208 = F_151 ( V_154 . V_208 , V_9 ) ;
F_152 ( V_154 . V_208 , V_9 , V_210 ) ;
} else {
F_35 ( L_247
L_246 ) ;
return 1 ;
}
}
V_154 . V_206 . V_207 = F_149 ( V_71 , V_72 , V_172 ) ;
#else
V_104 = TRUE ;
#endif
}
}
#ifdef F_14
if ( ! V_154 . V_211 ) {
if ( ! V_105 )
V_136 = TRUE ;
} else {
if ( strcmp ( V_154 . V_212 , L_129 ) == 0 && V_136 ) {
F_35 ( L_248
L_249 ) ;
return 1 ;
}
}
#else
if ( ! V_105 )
V_136 = TRUE ;
#endif
#ifndef F_14
if ( V_104 )
F_35 ( L_250 ) ;
#endif
if ( V_81 ) {
F_13 ( V_7 ) ;
return 1 ;
}
if ( V_139 ) {
if ( V_195 != V_196 ) {
F_35 ( L_251 ) ;
return 1 ;
}
}
if ( V_123 != NULL ) {
char * V_213 ;
if ( ! V_138 ) {
F_35 ( L_252 ) ;
return 1 ;
}
V_214 = F_153 ( V_215 , V_216 ) ;
for ( V_213 = strtok ( V_123 , L_253 ) ; V_213 ; V_213 = strtok ( NULL , L_253 ) ) {
F_154 ( V_214 , ( T_3 ) V_213 , ( T_3 ) V_213 ) ;
}
}
if ( V_113 != NULL && ! V_173 ) {
F_35 ( L_254 ) ;
return 1 ;
}
#ifdef F_14
if ( V_99 ) {
if ( V_112 ) {
F_35 ( L_255 ) ;
return 1 ;
}
if ( V_154 . V_217 ) {
F_35 ( L_256 ) ;
return 1 ;
}
} else {
if ( V_112 ) {
if ( V_154 . V_206 . V_207 ) {
F_35 ( L_257
L_258 ) ;
return 1 ;
}
if ( V_154 . V_217 ) {
F_35 ( L_259
L_260 ) ;
return 1 ;
}
if ( V_154 . V_218 ) {
F_35 ( L_261
L_260 ) ;
return 1 ;
}
if ( V_154 . V_219 ) {
F_35 ( L_262
L_260 ) ;
return 1 ;
}
if ( V_154 . V_220 ) {
F_35 ( L_263
L_260 ) ;
return 1 ;
}
if ( V_154 . V_221 ) {
F_35 ( L_264
L_265
L_266 ) ;
return 1 ;
}
if ( V_154 . V_222 ) {
F_35 ( L_267
L_260 ) ;
return 1 ;
}
} else {
if ( V_173 ) {
F_35 ( L_268 ) ;
return 1 ;
}
if ( V_154 . V_211 ) {
if ( V_106 != V_108 &&
V_106 != V_107 ) {
F_35 ( L_269 ) ;
return 1 ;
}
if ( V_154 . V_221 &&
V_106 != V_107 ) {
F_35 ( L_270 ) ;
return 1 ;
}
if ( V_154 . V_217 ) {
if ( strcmp ( V_154 . V_212 , L_129 ) == 0 ) {
F_35 ( L_259
L_271 ) ;
return 1 ;
}
if ( V_154 . V_223 ) {
F_35 ( L_259
L_272 ) ;
return 1 ;
}
if ( ! V_154 . V_224 &&
! V_154 . V_218 ) {
F_35 ( L_259
L_273 ) ;
return 1 ;
}
}
if ( V_113 != NULL ) {
F_35 ( L_274 ) ;
return 1 ;
}
if ( V_114 != NULL ) {
F_35 ( L_275 ) ;
return 1 ;
}
V_154 . V_225 = ( V_106 == V_107 ) ? TRUE : FALSE ;
} else {
if ( V_154 . V_224 ) {
F_35 ( L_276
L_277 ) ;
return 1 ;
}
if ( V_154 . V_217 ) {
F_35 ( L_259
L_278 ) ;
return 1 ;
}
if ( V_154 . V_221 ) {
F_35 ( L_264
L_278 ) ;
return 1 ;
}
}
}
}
#endif
#ifdef F_57
F_155 ( F_156 ( 1 , 1 ) , & V_82 ) ;
#endif
F_157 () ;
F_158 () ;
{
T_5 * V_226 = NULL ;
T_5 * V_227 = F_159 ( V_170 ) ;
if ( V_227 != NULL ) {
F_35 ( L_279 ) ;
for ( V_226 = V_227 ; V_226 != NULL ; V_226 = F_142 ( V_226 ) ) {
F_136 ( L_280 , ( T_7 * ) V_226 -> V_5 ) ;
}
F_10 ( V_227 ) ;
return 1 ;
}
}
#ifdef F_14
if ( V_154 . V_211 &&
V_154 . V_223 ) {
if ( F_160 () ) {
F_35 ( L_281 ) ;
return 1 ;
}
if ( V_136 ) {
F_35 ( L_282 ) ;
return 1 ;
}
}
#endif
if ( F_161 ( L_283 ) > 0 ) {
const T_7 * V_16 = F_162 ( L_283 ) ;
V_110 = F_163 ( V_16 ) ;
if ( V_110 == V_111 ) {
F_35 ( L_284 , V_16 ? V_16 : L_138 ) ;
F_12 () ;
return 1 ;
}
}
if ( V_85 == NULL && V_86 == NULL ) {
F_164 () ;
F_165 () ;
}
if( V_124 ) {
T_5 * V_228 ;
for ( V_228 = V_124 ; V_228 != NULL ; V_228 = F_142 ( V_228 ) )
{
F_166 ( ( char * ) V_228 -> V_5 ) ;
}
}
if( V_125 ) {
T_5 * V_229 ;
for ( V_229 = V_125 ; V_229 != NULL ; V_229 = F_142 ( V_229 ) )
{
F_167 ( ( char * ) V_229 -> V_5 , TRUE ) ;
}
}
if( V_126 ) {
T_5 * V_230 ;
for ( V_230 = V_126 ; V_230 != NULL ; V_230 = F_142 ( V_230 ) )
{
F_167 ( ( char * ) V_230 -> V_5 , FALSE ) ;
}
}
F_168 ( & V_156 . V_231 , V_120 -> V_232 , TRUE ) ;
#ifdef F_14
F_169 ( & V_154 , V_233 ) ;
F_170 ( & V_154 ) ;
#endif
if ( V_113 != NULL ) {
F_61 ( L_285 , V_113 ) ;
if ( ! F_171 ( V_113 , & V_117 , & V_119 ) ) {
F_35 ( L_142 , V_119 ) ;
F_11 ( V_119 ) ;
F_144 () ;
#ifdef F_59
{
T_24 * V_234 ;
V_234 = F_172 ( V_235 , V_233 ) ;
if ( V_234 != NULL ) {
if ( F_173 ( V_234 , & V_116 , V_113 , 0 , 0 ) != - 1 ) {
F_136 (
L_286
L_287 ) ;
}
F_174 ( V_234 ) ;
}
}
#endif
return 2 ;
}
}
V_156 . V_117 = V_117 ;
if ( V_114 != NULL ) {
F_61 ( L_288 , V_114 ) ;
if ( ! F_171 ( V_114 , & V_118 , & V_119 ) ) {
F_35 ( L_142 , V_119 ) ;
F_11 ( V_119 ) ;
F_144 () ;
#ifdef F_59
{
T_24 * V_234 ;
V_234 = F_172 ( V_235 , V_233 ) ;
if ( V_234 != NULL ) {
if ( F_173 ( V_234 , & V_116 , V_114 , 0 , 0 ) != - 1 ) {
F_136 (
L_289
L_287 ) ;
}
F_174 ( V_234 ) ;
}
}
#endif
return 2 ;
}
}
V_156 . V_118 = V_118 ;
if ( V_136 ) {
if ( V_195 == V_196 ) {
switch ( V_168 ) {
case V_169 :
V_236 = F_175 ( stdout ) ;
break;
case V_197 :
V_236 = F_176 ( stdout ) ;
break;
default:
F_38 () ;
}
}
}
if ( V_127 ) {
const char * V_237 ;
const char * V_238 = V_127 ;
const char * V_239 = V_114 ;
char * V_240 ;
int V_241 ;
if ( ! V_112 ) {
F_35 ( L_290 ) ;
return 1 ;
}
#ifdef F_14
V_237 = V_154 . V_212 ;
V_154 . V_212 = NULL ;
#else
V_237 = V_175 ;
V_175 = NULL ;
#endif
if ( V_237 == NULL ) {
F_35 ( L_291 ) ;
return 1 ;
}
V_240 = F_177 ( V_238 , V_239 ,
& V_128 ) ;
if ( V_240 ) {
F_35 ( L_292 , V_240 ) ;
F_11 ( V_240 ) ;
return 2 ;
}
V_241 = F_178 ( V_237 , V_242 | V_243 | V_244 | V_245 , 0644 ) ;
if ( V_241 == - 1 ) {
F_35 ( L_293 , V_237 , F_179 ( V_246 , TRUE ) ) ;
return 2 ;
}
V_97 = F_180 ( & V_128 , V_241 ,
F_45 ( L_294 , V_112 ) ) ;
if ( V_97 != 0 ) {
F_35 ( L_295 , F_119 ( V_97 ) ) ;
return 2 ;
}
}
V_247 = V_136 || V_117 || V_118 || V_127 ||
F_160 () ;
F_61 ( L_296 , V_247 ? L_297 : L_298 ) ;
if ( V_112 ) {
F_61 ( L_299 , V_112 ) ;
if ( F_181 ( & V_156 , V_112 , V_110 , FALSE , & V_97 ) != V_248 ) {
F_144 () ;
return 2 ;
}
F_61 ( L_300 ) ;
F_182 {
#ifdef F_14
V_97 = F_183 ( & V_156 , V_154 . V_212 , V_106 , V_109 ,
V_154 . V_249 ? V_154 . V_250 : 0 ,
V_154 . V_224 ? V_154 . V_251 : 0 ) ;
#else
V_97 = F_183 ( & V_156 , V_175 , V_106 , V_109 , 0 , 0 ) ;
#endif
}
F_184 (OutOfMemoryError) {
fprintf ( V_7 ,
L_301
L_6
L_302
L_6
L_303
L_304 ) ;
V_97 = V_252 ;
}
V_253 ;
if ( V_97 != 0 ) {
V_98 = 2 ;
}
if ( V_127 ) {
V_97 = F_185 ( & V_128 ) ;
if ( V_97 ) {
F_35 ( L_142 , F_186 ( V_97 ) ) ;
V_98 = 2 ;
}
F_11 ( V_127 ) ;
}
} else {
F_61 ( L_305 ) ;
#ifdef F_14
V_98 = F_187 ( & V_154 ,
( ( V_120 -> V_254 ) && ( * V_120 -> V_254 != '\0' ) ) ? F_188 ( V_120 -> V_254 ) : NULL ) ;
if ( V_98 != 0 )
return V_98 ;
if ( V_99 ) {
T_22 V_9 ;
for ( V_9 = 0 ; V_9 < V_154 . V_208 -> V_209 ; V_9 ++ ) {
T_23 V_210 ;
T_25 * V_255 ;
char * V_256 = NULL ;
V_210 = F_150 ( V_154 . V_208 , T_23 , V_9 ) ;
#ifdef F_17
if ( V_210 . V_257 == V_258 ) {
V_256 = F_45 ( L_306 , V_210 . V_259 , V_210 . V_260 ) ;
}
#endif
V_255 = F_189 ( V_210 . V_16 , V_210 . V_261 , V_256 , & V_103 , NULL ) ;
F_11 ( V_256 ) ;
if ( V_255 == NULL ) {
F_35 ( L_142 , V_103 ) ;
F_11 ( V_103 ) ;
return 2 ;
}
if ( V_255 -> V_262 == NULL ) {
F_35 ( L_307 , V_210 . V_16 ) ;
return 2 ;
}
F_190 ( V_255 , V_210 . V_16 , V_210 . V_261 ) ;
F_191 ( V_255 ) ;
}
return 0 ;
}
if ( ! F_192 ( F_193 ( V_7 ) ) )
V_263 = FALSE ;
else if ( V_136 && F_192 ( F_193 ( stdout ) ) )
V_263 = FALSE ;
else if ( V_105 )
V_263 = FALSE ;
else
V_263 = TRUE ;
if ( V_136 ) {
if ( ! F_194 ( & V_156 ) ) {
F_195 ( V_246 ) ;
return 2 ;
}
}
F_61 ( L_308 ) ;
F_196 () ;
V_98 = V_155 . V_264 ;
if ( V_136 ) {
if ( ! F_197 () ) {
V_97 = V_246 ;
F_195 ( V_97 ) ;
}
}
#else
F_35 ( L_250 ) ;
return 2 ;
#endif
}
F_11 ( V_112 ) ;
if ( V_156 . V_265 != NULL ) {
F_198 ( V_156 . V_265 ) ;
V_156 . V_265 = NULL ;
}
F_199 ( TRUE ) ;
F_200 () ;
F_201 ( V_156 . V_266 ) ;
F_144 () ;
F_202 ( V_170 ) ;
V_170 = NULL ;
return V_98 ;
}
static T_1
F_203 ( T_3 V_5 )
{
T_26 V_24 ;
T_27 V_267 = 0 ;
T_10 V_268 ;
T_27 V_269 ;
T_28 * V_270 = V_5 ;
T_1 V_271 = 0 ;
F_204 ( V_270 -> V_272 ) ;
while( V_271 < 5 ) {
V_24 = ( T_26 ) F_205 ( V_270 -> V_273 ) ;
V_268 = F_206 ( V_24 , NULL , 0 , NULL , & V_267 , NULL ) ;
F_207 ( ( T_26 ) * ( V_270 -> V_274 ) ,
& V_269 ) ;
if ( ! V_268 || V_267 > 0 || V_269 != V_275 ) {
if ( ! V_270 -> V_276 ( V_270 -> V_273 , V_270 -> V_29 ) ) {
F_208 ( NULL , V_145 , L_309 , V_271 ) ;
F_209 ( V_270 -> V_272 ) ;
return FALSE ;
}
}
else {
break;
}
V_271 ++ ;
}
F_209 ( V_270 -> V_272 ) ;
return TRUE ;
}
void
F_210 ( T_1 V_273 , T_3 V_29 , T_29 * V_274 , T_30 V_276 )
{
V_277 . V_273 = V_273 ;
V_277 . V_274 = V_274 ;
V_277 . V_29 = V_29 ;
V_277 . V_276 = V_276 ;
#ifdef F_57
#if F_65 ( 2 , 31 , 0 )
V_277 . V_272 = F_211 ( sizeof( V_278 ) ) ;
F_212 ( V_277 . V_272 ) ;
#else
V_277 . V_272 = F_213 () ;
#endif
V_277 . V_279 = F_214 ( 200 , F_203 , & V_277 ) ;
#endif
}
static const T_31 *
F_215 ( void * V_5 , T_11 V_280 )
{
T_32 * V_281 = ( T_32 * ) V_5 ;
if ( V_282 && V_282 -> V_283 == V_280 )
return & V_282 -> V_284 ;
if ( V_285 && V_285 -> V_283 == V_280 )
return & V_285 -> V_284 ;
if ( V_286 && V_286 -> V_283 == V_280 )
return & V_286 -> V_284 ;
if ( V_281 -> V_265 ) {
T_33 * V_287 = F_216 ( V_281 -> V_265 , V_280 ) ;
return ( V_287 ) ? & V_287 -> V_284 : NULL ;
}
return NULL ;
}
static T_34 *
F_217 ( T_32 * V_281 )
{
T_34 * V_266 = F_218 () ;
V_266 -> V_5 = V_281 ;
V_266 -> V_288 = F_215 ;
V_266 -> V_289 = V_290 ;
V_266 -> V_291 = NULL ;
return V_266 ;
}
static T_10
F_196 ( void )
{
T_10 V_292 ;
T_22 V_9 ;
T_16 * V_70 ;
#ifdef F_219
T_35 V_293 ;
#endif
#ifndef F_57
struct V_294 V_295 , V_296 ;
#endif
F_201 ( V_156 . V_266 ) ;
V_156 . V_266 = F_217 ( & V_156 ) ;
#ifdef F_57
F_220 ( V_297 , TRUE ) ;
#else
memset ( & V_295 , 0 , sizeof( V_295 ) ) ;
V_295 . V_298 = V_297 ;
V_295 . V_299 = V_300 ;
F_221 ( & V_295 . V_301 ) ;
V_294 ( V_302 , & V_295 , NULL ) ;
V_294 ( V_303 , & V_295 , NULL ) ;
V_294 ( V_304 , NULL , & V_296 ) ;
if ( V_296 . V_298 == V_305 )
V_294 ( V_304 , & V_295 , NULL ) ;
#ifdef F_222
V_295 . V_298 = V_306 ;
V_295 . V_299 = V_300 ;
F_221 ( & V_295 . V_301 ) ;
V_294 ( F_222 , & V_295 , NULL ) ;
#endif
#endif
V_155 . V_307 = V_308 ;
for ( V_9 = 0 ; V_9 < V_154 . V_208 -> V_209 ; V_9 ++ ) {
T_23 V_210 ;
V_210 = F_150 ( V_154 . V_208 , T_23 , V_9 ) ;
V_210 . V_309 = F_223 ( V_210 . V_16 ) ;
V_154 . V_208 = F_151 ( V_154 . V_208 , V_9 ) ;
F_152 ( V_154 . V_208 , V_9 , V_210 ) ;
}
V_70 = F_224 ( & V_154 , V_310 ) ;
if ( V_184 == FALSE )
fprintf ( V_7 , L_310 , V_70 -> V_70 ) ;
fflush ( V_7 ) ;
F_77 ( V_70 , TRUE ) ;
V_292 = F_225 ( & V_154 , & V_155 , & V_311 , NULL ) ;
if ( ! V_292 )
return FALSE ;
#ifdef F_219
F_226 ( & V_293 ) ;
F_227 ( V_277 . V_273 , & V_293 ) ;
#endif
V_312 = TRUE ;
F_182
{
while ( V_312 )
{
#ifdef F_219
V_292 = F_228 ( V_277 . V_273 + 1 , & V_293 , NULL , NULL , NULL ) ;
if ( V_292 == - 1 )
{
fprintf ( V_7 , L_311 , L_312 , F_119 ( V_246 ) ) ;
return TRUE ;
} else if ( V_292 == 1 ) {
#endif
if ( ! V_277 . V_276 ( V_277 . V_273 , V_277 . V_29 ) ) {
F_208 ( NULL , V_145 , L_313 ) ;
return FALSE ;
}
#ifdef F_219
}
#endif
}
}
F_184 (OutOfMemoryError) {
fprintf ( V_7 ,
L_301
L_6
L_302
L_6
L_303
L_304 ) ;
exit ( 1 ) ;
}
V_253 ;
return TRUE ;
}
void
F_229 ( T_36 * T_37 V_6 , char * V_313 , char * V_314 )
{
F_35 ( L_142 , V_313 ) ;
F_136 ( L_142 , V_314 ) ;
}
void
F_230 ( T_36 * T_37 , T_22 V_9 , char * V_315 )
{
T_38 * V_316 = T_37 -> V_316 ;
T_19 * V_117 = NULL ;
T_23 V_210 ;
F_26 ( V_9 < V_316 -> V_208 -> V_209 ) ;
V_210 = F_150 ( V_316 -> V_208 , T_23 , V_9 ) ;
if ( F_171 ( V_210 . V_207 , & V_117 , NULL ) && V_117 != NULL ) {
F_35 (
L_314
L_6
L_315
L_316
L_6
L_317
L_318
L_6
L_319 ,
V_210 . V_207 , V_210 . V_309 , V_315 ) ;
F_231 ( V_117 ) ;
} else {
F_35 (
L_314
L_6
L_320
L_319 ,
V_210 . V_207 , V_210 . V_309 , V_315 ) ;
}
}
T_10
F_232 ( T_36 * T_37 , T_7 * V_317 )
{
T_38 * V_316 = T_37 -> V_316 ;
T_32 * V_281 = ( T_32 * ) T_37 -> V_281 ;
T_10 V_318 ;
int V_97 ;
if ( T_37 -> V_307 == V_308 ) {
F_208 ( V_149 , V_143 , L_321 ) ;
}
F_208 ( V_149 , V_143 , L_322 , V_317 ) ;
F_26 ( T_37 -> V_307 == V_308 || T_37 -> V_307 == V_319 ) ;
if ( V_316 -> V_212 != NULL ) {
if ( V_281 -> V_307 != V_320 ) {
if ( V_281 -> V_321 != NULL ) {
F_233 ( V_281 -> V_321 ) ;
V_281 -> V_321 = NULL ;
}
V_281 -> V_307 = V_320 ;
}
F_11 ( V_316 -> V_212 ) ;
V_318 = FALSE ;
F_201 ( V_281 -> V_266 ) ;
V_281 -> V_266 = F_217 ( V_281 ) ;
} else {
V_318 = TRUE ;
}
V_316 -> V_212 = F_34 ( V_317 ) ;
if ( V_247 ) {
( ( T_32 * ) T_37 -> V_281 ) -> V_322 = V_111 ;
switch( F_181 ( ( T_32 * ) T_37 -> V_281 , V_316 -> V_212 , V_111 , V_318 , & V_97 ) ) {
case V_248 :
break;
case V_323 :
F_11 ( V_316 -> V_212 ) ;
V_316 -> V_212 = NULL ;
return FALSE ;
}
}
T_37 -> V_307 = V_319 ;
return TRUE ;
}
void
F_234 ( T_36 * T_37 , int V_324 )
{
T_10 V_292 ;
int V_97 ;
T_7 * V_325 ;
T_39 V_326 ;
T_32 * V_281 = ( T_32 * ) T_37 -> V_281 ;
T_10 V_327 ;
T_22 V_328 ;
#ifdef F_222
V_329 = TRUE ;
#endif
V_327 = F_235 () ;
V_328 = F_236 () ;
if ( V_247 ) {
T_10 V_330 ;
T_40 * V_331 ;
if ( V_281 -> V_117 || V_281 -> V_118 || V_138 || V_327 ||
( V_328 & V_332 ) || F_237 ( & V_281 -> V_231 ) )
V_330 = TRUE ;
else
V_330 = FALSE ;
V_331 = F_238 ( V_281 -> V_266 , V_330 , V_136 && V_138 ) ;
while ( V_324 -- && V_281 -> V_321 ) {
F_239 ( V_281 -> V_321 ) ;
V_292 = F_240 ( V_281 -> V_321 , & V_97 , & V_325 , & V_326 ) ;
if ( V_292 == FALSE ) {
F_241 ( T_37 ) ;
F_233 ( V_281 -> V_321 ) ;
V_281 -> V_321 = NULL ;
} else {
V_292 = F_242 ( V_281 , V_331 , V_326 , F_243 ( V_281 -> V_321 ) ,
F_244 ( V_281 -> V_321 ) ,
V_328 ) ;
}
if ( V_292 != FALSE ) {
V_333 ++ ;
}
}
F_245 ( V_331 ) ;
} else {
V_333 += V_324 ;
}
if ( V_263 ) {
if ( V_333 != 0 ) {
fprintf ( V_7 , L_323 , V_333 ) ;
fflush ( V_7 ) ;
}
}
#ifdef F_222
V_329 = FALSE ;
if ( V_334 )
F_246 () ;
#endif
}
static void
F_246 ( void )
{
if ( ( V_263 == FALSE ) && ( V_184 == FALSE ) ) {
fprintf ( V_7 , L_324 , V_333 ,
F_247 ( V_333 , L_138 , L_229 ) ) ;
}
#ifdef F_222
V_334 = FALSE ;
#endif
}
static void
V_306 ( int T_41 V_6 )
{
int V_335 = V_246 ;
if ( V_329 )
V_334 = TRUE ;
else
F_246 () ;
V_246 = V_335 ;
}
void
F_248 ( T_36 * T_37 V_6 , T_11 V_336 )
{
if ( V_263 ) {
fprintf ( V_7 , L_6 ) ;
}
if ( V_336 != 0 ) {
fprintf ( V_7 , L_325 , V_336 , F_247 ( V_336 , L_138 , L_229 ) ) ;
}
}
void
F_249 ( T_36 * T_37 , T_7 * V_337 )
{
T_32 * V_281 = ( T_32 * ) T_37 -> V_281 ;
if ( V_337 != NULL )
fprintf ( V_7 , L_326 , V_337 ) ;
F_246 () ;
if ( V_281 != NULL && V_281 -> V_321 != NULL ) {
F_233 ( V_281 -> V_321 ) ;
if ( V_281 -> V_318 ) {
F_250 ( V_281 -> V_338 ) ;
}
}
#ifdef F_251
F_252 ( V_339 ) ;
#else
V_312 = FALSE ;
#endif
}
static BOOL T_42
V_297 ( T_27 T_43 V_6 )
{
F_241 ( & V_155 ) ;
return TRUE ;
}
static void
V_297 ( int T_41 V_6 )
{
F_241 ( & V_155 ) ;
}
static T_10
F_253 ( T_32 * V_281 , T_40 * V_331 ,
T_39 V_340 , struct V_341 * V_342 ,
const T_44 * V_343 )
{
T_33 V_344 ;
T_11 V_345 ;
T_10 V_346 ;
V_345 = V_281 -> V_347 + 1 ;
V_346 = TRUE ;
F_254 ( & V_344 , V_345 , V_342 , V_340 , V_348 ) ;
if ( V_331 ) {
if ( V_179 . V_349 || V_179 . V_350 ||
V_179 . V_351 )
F_255 () ;
if ( V_281 -> V_117 )
F_256 ( V_331 , V_281 -> V_117 ) ;
if ( V_281 -> V_118 )
F_256 ( V_331 , V_281 -> V_118 ) ;
F_257 ( & V_344 , & V_281 -> V_352 ,
& V_282 , V_285 ) ;
if ( V_282 == & V_344 ) {
V_353 = V_344 ;
V_282 = & V_353 ;
}
F_258 ( V_331 , V_281 -> V_354 , V_342 , F_259 ( & V_344 , V_343 ) , & V_344 , NULL ) ;
if ( V_281 -> V_117 )
V_346 = F_260 ( V_281 -> V_117 , V_331 ) ;
}
if ( V_346 ) {
F_261 ( & V_344 , & V_348 ) ;
V_286 = V_285 = F_262 ( V_281 -> V_265 , & V_344 ) ;
if ( V_331 && V_281 -> V_118 ) {
if ( F_260 ( V_281 -> V_118 , V_331 ) ) {
F_9 ( V_331 -> V_355 . V_356 , V_357 , V_281 -> V_265 ) ;
}
}
V_281 -> V_347 ++ ;
} else {
F_263 ( & V_344 ) ;
}
if ( V_331 )
F_264 ( V_331 ) ;
return V_346 ;
}
static T_10
F_265 ( T_32 * V_281 , T_40 * V_331 , T_33 * V_358 ,
struct V_341 * V_359 , T_45 * V_360 ,
T_22 V_328 )
{
T_46 * V_231 ;
T_10 V_346 ;
V_346 = TRUE ;
if ( V_331 ) {
if ( V_179 . V_349 || V_179 . V_350 ||
V_179 . V_351 )
F_255 () ;
if ( V_281 -> V_118 )
F_256 ( V_331 , V_281 -> V_118 ) ;
F_266 ( V_331 , & V_281 -> V_231 ) ;
if ( ( V_328 & V_361 ) || ( V_136 && V_137 ) || F_267 ( V_170 ) )
V_231 = & V_281 -> V_231 ;
else
V_231 = NULL ;
F_257 ( V_358 , & V_281 -> V_352 ,
& V_282 , V_285 ) ;
if ( V_282 == V_358 ) {
V_353 = * V_358 ;
V_282 = & V_353 ;
}
F_268 ( V_331 , V_281 -> V_354 , V_359 , F_269 ( V_358 , V_360 ) , V_358 , V_231 ) ;
if ( V_281 -> V_118 )
V_346 = F_260 ( V_281 -> V_118 , V_331 ) ;
}
if ( V_346 ) {
F_261 ( V_358 , & V_348 ) ;
if ( V_136 ) {
F_270 ( V_281 , V_331 ) ;
if ( V_178 )
fflush ( stdout ) ;
if ( ferror ( stdout ) ) {
F_195 ( V_246 ) ;
exit ( 2 ) ;
}
}
V_285 = V_358 ;
}
V_286 = V_358 ;
if ( V_331 ) {
F_264 ( V_331 ) ;
}
return V_346 || V_358 -> V_362 . V_363 ;
}
static int
F_183 ( T_32 * V_281 , char * V_212 , int V_106 ,
T_10 V_109 , int V_364 , T_39 V_365 )
{
T_1 V_366 ;
int V_367 ;
T_47 * V_368 ;
T_11 V_345 ;
int V_97 ;
T_7 * V_325 = NULL ;
T_39 V_326 ;
char * V_67 = NULL ;
T_10 V_327 ;
T_22 V_328 ;
T_48 * V_369 = NULL ;
T_49 * V_370 = NULL ;
T_48 * V_371 = NULL ;
struct V_341 V_359 ;
T_45 V_360 ;
T_40 * V_331 = NULL ;
char * V_372 ;
F_271 ( & V_359 ) ;
V_370 = F_272 ( V_281 -> V_321 ) ;
#ifdef F_58
if ( V_370 -> V_373 -> V_209 > 1 ) {
V_366 = V_374 ;
} else {
V_366 = F_273 ( V_281 -> V_321 ) ;
}
#else
V_366 = F_273 ( V_281 -> V_321 ) ;
#endif
if ( V_212 != NULL ) {
V_67 = F_44 ( V_212 ) ;
V_367 = F_274 ( V_281 -> V_321 ) ;
if ( V_367 == 0 ) {
V_367 = V_375 ;
}
F_61 ( L_327 , V_367 ) ;
V_369 = F_275 ( V_281 -> V_321 ) ;
V_371 = F_276 ( V_281 -> V_321 ) ;
F_277 ( F_150 ( V_369 , V_376 , 0 ) , V_377 , & V_372 ) ;
if ( V_372 == NULL ) {
F_278 ( F_150 ( V_369 , V_376 , 0 ) , V_377 , L_328 , F_20 () ) ;
}
if ( V_366 != V_374 &&
V_106 == V_108 ) {
F_61 ( L_329 , V_212 ) ;
if ( strcmp ( V_212 , L_129 ) == 0 ) {
V_368 = F_279 ( V_106 , V_366 ,
V_367 , FALSE , & V_97 ) ;
} else {
V_368 = F_280 ( V_212 , V_106 , V_366 ,
V_367 , FALSE , & V_97 ) ;
}
}
else {
F_61 ( L_330 , V_106 , V_212 ) ;
if ( strcmp ( V_212 , L_129 ) == 0 ) {
V_368 = F_281 ( V_106 , V_366 ,
V_367 , FALSE , V_369 , V_370 , V_371 , & V_97 ) ;
} else {
V_368 = F_282 ( V_212 , V_106 , V_366 ,
V_367 , FALSE , V_369 , V_370 , V_371 , & V_97 ) ;
}
}
F_11 ( V_370 ) ;
V_370 = NULL ;
if ( V_368 == NULL ) {
switch ( V_97 ) {
case V_378 :
F_35 ( L_331 ) ;
break;
case V_379 :
case V_380 :
F_35 ( L_332
L_333 , F_6 ( V_106 ) ) ;
break;
case V_381 :
F_35 ( L_334
L_335 , V_67 ) ;
break;
case V_382 :
F_35 ( L_336 ,
V_67 ) ;
break;
default:
F_35 ( L_337 , V_67 ,
F_186 ( V_97 ) ) ;
break;
}
goto V_383;
}
} else {
if ( V_136 ) {
if ( ! F_194 ( V_281 ) ) {
V_97 = V_246 ;
F_195 ( V_97 ) ;
goto V_383;
}
}
F_11 ( V_370 ) ;
V_370 = NULL ;
V_368 = NULL ;
}
V_327 = F_235 () ;
V_328 = F_236 () ;
if ( V_173 ) {
T_33 * V_358 ;
F_61 ( L_338 , V_247 ? L_297 : L_298 ) ;
V_281 -> V_265 = F_283 () ;
if ( V_247 ) {
T_10 V_330 = FALSE ;
if ( V_281 -> V_117 || V_281 -> V_118 )
V_330 = TRUE ;
F_61 ( L_339 , V_330 ? L_297 : L_298 ) ;
V_331 = F_238 ( V_281 -> V_266 , V_330 , FALSE ) ;
}
F_61 ( L_340 ) ;
while ( F_240 ( V_281 -> V_321 , & V_97 , & V_325 , & V_326 ) ) {
if ( F_253 ( V_281 , V_331 , V_326 , F_243 ( V_281 -> V_321 ) ,
F_244 ( V_281 -> V_321 ) ) ) {
if ( ( -- V_364 == 0 ) || ( V_365 != 0 && V_326 >= V_365 ) ) {
F_61 ( L_341 V_384 L_342 V_384 L_343 ,
V_364 , V_326 , V_365 ) ;
V_97 = 0 ;
break;
}
}
}
if ( V_331 ) {
F_245 ( V_331 ) ;
V_331 = NULL ;
}
F_284 ( V_281 -> V_321 ) ;
F_285 () ;
V_285 = NULL ;
V_286 = NULL ;
F_286 ( & V_360 , 1500 ) ;
F_61 ( L_344 ) ;
if ( V_247 ) {
T_10 V_330 ;
if ( V_281 -> V_118 || V_138 || V_327 ||
( V_328 & V_332 ) || F_237 ( & V_281 -> V_231 ) )
V_330 = TRUE ;
else
V_330 = FALSE ;
F_61 ( L_339 , V_330 ? L_297 : L_298 ) ;
V_331 = F_238 ( V_281 -> V_266 , V_330 , V_136 && V_138 ) ;
}
for ( V_345 = 1 ; V_97 == 0 && V_345 <= V_281 -> V_347 ; V_345 ++ ) {
V_358 = F_216 ( V_281 -> V_265 , V_345 ) ;
if ( F_287 ( V_281 -> V_321 , V_358 -> V_385 , & V_359 , & V_360 , & V_97 ,
& V_325 ) ) {
F_61 ( L_345 , V_345 ) ;
if ( F_265 ( V_281 , V_331 , V_358 , & V_359 , & V_360 ,
V_328 ) ) {
if ( V_368 != NULL ) {
F_61 ( L_346 , V_345 ) ;
if ( ! F_288 ( V_368 , & V_359 , F_289 ( & V_360 ) , & V_97 , & V_325 ) ) {
F_61 ( L_347 , V_97 ) ;
switch ( V_97 ) {
case V_379 :
fprintf ( V_7 ,
L_348 ,
V_345 , V_281 -> V_338 ,
F_6 ( V_106 ) ) ;
break;
case V_386 :
fprintf ( V_7 ,
L_349 ,
V_345 , V_281 -> V_338 ,
F_6 ( V_106 ) ) ;
break;
case V_387 :
fprintf ( V_7 ,
L_350 ,
V_345 , V_281 -> V_338 ,
F_6 ( V_106 ) ) ;
break;
case V_388 :
fprintf ( V_7 ,
L_351 ,
V_345 , V_281 -> V_338 ,
F_6 ( V_106 ) ,
V_325 != NULL ? V_325 : L_352 ) ;
F_11 ( V_325 ) ;
break;
default:
F_290 ( V_212 , V_97 , FALSE ) ;
break;
}
F_291 ( V_368 , & V_97 ) ;
F_292 ( V_369 ) ;
F_292 ( V_371 ) ;
exit ( 2 ) ;
}
}
}
}
}
if ( V_331 ) {
F_245 ( V_331 ) ;
V_331 = NULL ;
}
F_293 ( & V_360 ) ;
F_61 ( L_353 ) ;
}
else {
V_345 = 0 ;
F_61 ( L_354 , V_247 ? L_297 : L_298 ) ;
if ( V_247 ) {
T_10 V_330 ;
if ( V_281 -> V_117 || V_281 -> V_118 || V_138 || V_327 ||
( V_328 & V_332 ) || F_237 ( & V_281 -> V_231 ) )
V_330 = TRUE ;
else
V_330 = FALSE ;
F_61 ( L_339 , V_330 ? L_297 : L_298 ) ;
V_331 = F_238 ( V_281 -> V_266 , V_330 , V_136 && V_138 ) ;
}
while ( F_240 ( V_281 -> V_321 , & V_97 , & V_325 , & V_326 ) ) {
V_345 ++ ;
F_61 ( L_355 , V_345 ) ;
if ( F_242 ( V_281 , V_331 , V_326 , F_243 ( V_281 -> V_321 ) ,
F_244 ( V_281 -> V_321 ) ,
V_328 ) ) {
if ( V_368 != NULL ) {
F_61 ( L_346 , V_345 ) ;
if ( ! F_288 ( V_368 , F_243 ( V_281 -> V_321 ) , F_244 ( V_281 -> V_321 ) , & V_97 , & V_325 ) ) {
F_61 ( L_347 , V_97 ) ;
switch ( V_97 ) {
case V_379 :
fprintf ( V_7 ,
L_348 ,
V_345 , V_281 -> V_338 ,
F_6 ( V_106 ) ) ;
break;
case V_386 :
fprintf ( V_7 ,
L_349 ,
V_345 , V_281 -> V_338 ,
F_6 ( V_106 ) ) ;
break;
case V_387 :
fprintf ( V_7 ,
L_350 ,
V_345 , V_281 -> V_338 ,
F_6 ( V_106 ) ) ;
break;
case V_388 :
fprintf ( V_7 ,
L_351 ,
V_345 , V_281 -> V_338 ,
F_6 ( V_106 ) ,
V_325 != NULL ? V_325 : L_352 ) ;
F_11 ( V_325 ) ;
break;
default:
F_290 ( V_212 , V_97 , FALSE ) ;
break;
}
F_291 ( V_368 , & V_97 ) ;
F_292 ( V_369 ) ;
F_292 ( V_371 ) ;
exit ( 2 ) ;
}
}
}
if ( ( -- V_364 == 0 ) || ( V_365 != 0 && V_326 >= V_365 ) ) {
F_61 ( L_341 V_384 L_342 V_384 L_343 ,
V_364 , V_326 , V_365 ) ;
V_97 = 0 ;
break;
}
}
if ( V_331 ) {
F_245 ( V_331 ) ;
V_331 = NULL ;
}
}
F_294 ( & V_359 ) ;
if ( V_97 != 0 ) {
F_61 ( L_356 , V_97 ) ;
#ifndef F_57
if ( V_136 ) {
T_50 V_389 , V_390 ;
if ( F_295 ( 1 , & V_389 ) == 0 && F_295 ( 2 , & V_390 ) == 0 ) {
if ( V_389 . V_391 == V_390 . V_391 &&
V_389 . V_392 == V_390 . V_392 ) {
fflush ( stdout ) ;
fprintf ( V_7 , L_6 ) ;
}
}
}
#endif
switch ( V_97 ) {
case V_393 :
F_35 ( L_357 ,
V_281 -> V_338 ,
V_325 != NULL ? V_325 : L_352 ) ;
F_11 ( V_325 ) ;
break;
case V_394 :
F_35 ( L_358 ,
V_281 -> V_338 ) ;
break;
case V_395 :
F_35 ( L_359 ,
V_281 -> V_338 ,
V_325 != NULL ? V_325 : L_352 ) ;
F_11 ( V_325 ) ;
break;
case V_396 :
F_35 ( L_360
L_361 , V_281 -> V_338 ,
V_325 != NULL ? V_325 : L_352 ) ;
F_11 ( V_325 ) ;
break;
default:
F_35 ( L_362 ,
V_281 -> V_338 , F_186 ( V_97 ) ) ;
break;
}
if ( V_212 != NULL ) {
if ( ! F_291 ( V_368 , & V_97 ) )
F_290 ( V_212 , V_97 , TRUE ) ;
}
} else {
if ( V_212 != NULL ) {
if ( V_368 && V_109 ) {
if ( ! F_296 ( V_368 , F_297 () ) ) {
F_35 ( L_363 ,
F_6 ( V_106 ) ) ;
}
}
if ( ! F_291 ( V_368 , & V_97 ) )
F_290 ( V_212 , V_97 , TRUE ) ;
} else {
if ( V_136 ) {
if ( ! F_197 () ) {
V_97 = V_246 ;
F_195 ( V_97 ) ;
}
}
}
}
V_383:
F_233 ( V_281 -> V_321 ) ;
V_281 -> V_321 = NULL ;
F_11 ( V_67 ) ;
F_292 ( V_369 ) ;
F_292 ( V_371 ) ;
return V_97 ;
}
static T_10
F_242 ( T_32 * V_281 , T_40 * V_331 , T_39 V_340 , struct V_341 * V_342 ,
const T_44 * V_343 , T_22 V_328 )
{
T_33 V_358 ;
T_46 * V_231 ;
T_10 V_346 ;
V_281 -> V_347 ++ ;
V_346 = TRUE ;
F_254 ( & V_358 , V_281 -> V_347 , V_342 , V_340 , V_348 ) ;
if ( V_331 ) {
if ( V_136 && ( V_179 . V_349 || V_179 . V_350 ||
V_179 . V_351 ) )
F_255 () ;
if ( V_281 -> V_118 )
F_256 ( V_331 , V_281 -> V_118 ) ;
F_266 ( V_331 , & V_281 -> V_231 ) ;
if ( ( V_328 & V_361 ) || ( V_136 && V_137 ) || F_267 ( V_170 ) )
V_231 = & V_281 -> V_231 ;
else
V_231 = NULL ;
F_257 ( & V_358 , & V_281 -> V_352 ,
& V_282 , V_285 ) ;
if ( V_282 == & V_358 ) {
V_353 = V_358 ;
V_282 = & V_353 ;
}
F_268 ( V_331 , V_281 -> V_354 , V_342 , F_259 ( & V_358 , V_343 ) , & V_358 , V_231 ) ;
if ( V_281 -> V_118 )
V_346 = F_260 ( V_281 -> V_118 , V_331 ) ;
}
if ( V_346 ) {
F_261 ( & V_358 , & V_348 ) ;
if ( V_136 ) {
F_270 ( V_281 , V_331 ) ;
if ( V_178 )
fflush ( stdout ) ;
if ( ferror ( stdout ) ) {
F_195 ( V_246 ) ;
exit ( 2 ) ;
}
}
V_397 = V_358 ;
V_285 = & V_397 ;
}
V_398 = V_358 ;
V_286 = & V_398 ;
if ( V_331 ) {
F_264 ( V_331 ) ;
F_263 ( & V_358 ) ;
}
return V_346 ;
}
static T_10
F_194 ( T_32 * V_281 )
{
switch ( V_195 ) {
case V_196 :
return F_298 ( V_236 , V_281 -> V_338 , F_20 () ) ;
case V_198 :
if ( V_138 )
F_299 ( stdout , V_281 -> V_338 ) ;
else
F_300 ( & V_281 -> V_231 , stdout ) ;
return ! ferror ( stdout ) ;
case V_199 :
F_301 ( V_170 , stdout ) ;
return ! ferror ( stdout ) ;
default:
F_38 () ;
return FALSE ;
}
}
static char *
F_302 ( T_51 V_209 )
{
static char * V_399 = NULL ;
static T_51 V_400 = 256 ;
T_51 V_401 ;
for ( V_401 = V_400 ; V_209 > V_401 ;
V_401 *= 2 )
;
if ( V_399 == NULL ) {
V_400 = V_401 ;
V_399 = ( char * ) F_211 ( V_400 + 1 ) ;
} else {
if ( V_401 > V_400 ) {
V_400 = V_401 ;
V_399 = ( char * ) F_303 ( V_399 , V_400 + 1 ) ;
}
}
return V_399 ;
}
static inline void
F_304 ( char * V_402 , const char * V_70 , T_51 V_403 )
{
memcpy ( V_402 , V_70 , V_403 ) ;
V_402 [ V_403 ] = '\0' ;
}
static inline void
F_305 ( char * V_402 , const char * V_70 , T_51 V_403 , T_51 V_404 )
{
T_51 V_9 ;
for ( V_9 = V_403 ; V_9 < V_404 ; V_9 ++ )
* V_402 ++ = ' ' ;
F_304 ( V_402 , V_70 , V_403 ) ;
}
static inline void
F_306 ( char * V_402 , const char * V_70 , T_51 V_403 , T_51 V_404 )
{
T_51 V_9 ;
memcpy ( V_402 , V_70 , V_403 ) ;
for ( V_9 = V_403 ; V_9 < V_404 ; V_9 ++ )
V_402 [ V_9 ] = ' ' ;
V_402 [ V_404 ] = '\0' ;
}
static T_10
F_307 ( T_32 * V_281 )
{
char * V_399 ;
int V_9 ;
T_51 V_405 ;
T_51 V_406 ;
T_51 V_407 ;
T_52 * V_408 ;
V_399 = F_302 ( 256 ) ;
V_405 = 0 ;
* V_399 = '\0' ;
for ( V_9 = 0 ; V_9 < V_281 -> V_231 . V_232 ; V_9 ++ ) {
V_408 = & V_281 -> V_231 . V_409 [ V_9 ] ;
if ( ! F_308 ( V_9 ) )
continue;
switch ( V_408 -> V_410 ) {
case V_411 :
V_406 = V_407 = strlen ( V_408 -> V_412 ) ;
if ( V_406 < 3 )
V_406 = 3 ;
V_399 = F_302 ( V_405 + V_406 ) ;
F_305 ( V_399 + V_405 , V_408 -> V_412 , V_407 , V_406 ) ;
break;
case V_413 :
case V_414 :
case V_415 :
case V_416 :
case V_417 :
case V_418 :
case V_419 :
case V_420 :
V_406 = V_407 = strlen ( V_408 -> V_412 ) ;
if ( V_406 < 10 )
V_406 = 10 ;
V_399 = F_302 ( V_405 + V_406 ) ;
F_305 ( V_399 + V_405 , V_408 -> V_412 , V_407 , V_406 ) ;
break;
case V_421 :
case V_422 :
case V_423 :
case V_424 :
case V_425 :
case V_426 :
case V_427 :
case V_428 :
case V_429 :
V_406 = V_407 = strlen ( V_408 -> V_412 ) ;
if ( V_406 < 12 )
V_406 = 12 ;
V_399 = F_302 ( V_405 + V_406 ) ;
F_305 ( V_399 + V_405 , V_408 -> V_412 , V_407 , V_406 ) ;
break;
case V_430 :
case V_431 :
case V_432 :
case V_433 :
case V_434 :
case V_435 :
case V_436 :
case V_437 :
case V_438 :
V_406 = V_407 = strlen ( V_408 -> V_412 ) ;
if ( V_406 < 12 )
V_406 = 12 ;
V_399 = F_302 ( V_405 + V_406 ) ;
F_306 ( V_399 + V_405 , V_408 -> V_412 , V_407 , V_406 ) ;
break;
default:
V_406 = strlen ( V_408 -> V_412 ) ;
V_399 = F_302 ( V_405 + V_406 ) ;
F_304 ( V_399 + V_405 , V_408 -> V_412 , V_406 ) ;
break;
}
V_405 += V_406 ;
if ( V_9 != V_281 -> V_231 . V_232 - 1 ) {
V_399 = F_302 ( V_405 + 5 ) ;
switch ( V_408 -> V_410 ) {
case V_421 :
case V_422 :
case V_423 :
switch ( V_281 -> V_231 . V_409 [ V_9 + 1 ] . V_410 ) {
case V_430 :
case V_431 :
case V_432 :
F_304 ( V_399 + V_405 , L_364 V_439 L_364 , 5 ) ;
V_405 += 5 ;
break;
default:
F_304 ( V_399 + V_405 , L_364 , 1 ) ;
V_405 += 1 ;
break;
}
break;
case V_424 :
case V_425 :
case V_426 :
switch ( V_281 -> V_231 . V_409 [ V_9 + 1 ] . V_410 ) {
case V_433 :
case V_434 :
case V_435 :
F_304 ( V_399 + V_405 , L_364 V_439 L_364 , 5 ) ;
V_405 += 5 ;
break;
default:
F_304 ( V_399 + V_405 , L_364 , 1 ) ;
V_405 += 1 ;
break;
}
break;
case V_427 :
case V_428 :
case V_429 :
switch ( V_281 -> V_231 . V_409 [ V_9 + 1 ] . V_410 ) {
case V_436 :
case V_437 :
case V_438 :
F_304 ( V_399 + V_405 , L_364 V_439 L_364 , 5 ) ;
V_405 += 5 ;
break;
default:
F_304 ( V_399 + V_405 , L_364 , 1 ) ;
V_405 += 1 ;
break;
}
break;
case V_430 :
case V_431 :
case V_432 :
switch ( V_281 -> V_231 . V_409 [ V_9 + 1 ] . V_410 ) {
case V_421 :
case V_422 :
case V_423 :
F_304 ( V_399 + V_405 , L_364 V_440 L_364 , 5 ) ;
V_405 += 5 ;
break;
default:
F_304 ( V_399 + V_405 , L_364 , 1 ) ;
V_405 += 1 ;
break;
}
break;
case V_433 :
case V_434 :
case V_435 :
switch ( V_281 -> V_231 . V_409 [ V_9 + 1 ] . V_410 ) {
case V_424 :
case V_425 :
case V_426 :
F_304 ( V_399 + V_405 , L_364 V_440 L_364 , 5 ) ;
V_405 += 5 ;
break;
default:
F_304 ( V_399 + V_405 , L_364 , 1 ) ;
V_405 += 1 ;
break;
}
break;
case V_436 :
case V_437 :
case V_438 :
switch ( V_281 -> V_231 . V_409 [ V_9 + 1 ] . V_410 ) {
case V_427 :
case V_428 :
case V_429 :
F_304 ( V_399 + V_405 , L_364 V_440 L_364 , 5 ) ;
V_405 += 5 ;
break;
default:
F_304 ( V_399 + V_405 , L_364 , 1 ) ;
V_405 += 1 ;
break;
}
break;
default:
F_304 ( V_399 + V_405 , L_364 , 1 ) ;
V_405 += 1 ;
break;
}
}
}
return F_309 ( V_236 , 0 , V_399 ) ;
}
static T_10
F_270 ( T_32 * V_281 , T_40 * V_331 )
{
T_53 V_441 ;
if ( V_137 || F_267 ( V_170 ) ) {
F_310 ( V_331 , FALSE , TRUE ) ;
if ( V_137 ) {
switch ( V_195 ) {
case V_196 :
if ( ! F_307 ( V_281 ) )
return FALSE ;
break;
case V_198 :
F_311 ( V_331 , stdout ) ;
return ! ferror ( stdout ) ;
case V_199 :
F_38 () ;
break;
}
}
}
if ( V_138 ) {
switch ( V_195 ) {
case V_196 :
V_441 . V_139 = V_139 ;
V_441 . V_442 = V_138 ? V_443 : V_444 ;
if ( ! F_312 ( & V_441 , V_331 , V_214 , V_236 ) )
return FALSE ;
if ( ! V_139 ) {
if ( ! F_309 ( V_236 , 0 , V_185 ) )
return FALSE ;
}
break;
case V_198 :
F_313 ( V_331 , stdout ) ;
printf ( L_6 ) ;
return ! ferror ( stdout ) ;
case V_199 :
F_314 ( V_170 , V_331 , & V_281 -> V_231 , stdout ) ;
printf ( L_6 ) ;
return ! ferror ( stdout ) ;
}
}
if ( V_139 ) {
if ( V_137 || V_138 ) {
if ( ! F_309 ( V_236 , 0 , L_138 ) )
return FALSE ;
}
if ( ! F_315 ( V_236 , V_331 ) )
return FALSE ;
if ( ! F_309 ( V_236 , 0 , V_185 ) )
return FALSE ;
}
return TRUE ;
}
static T_10
F_197 ( void )
{
switch ( V_195 ) {
case V_196 :
return F_316 ( V_236 ) ;
case V_198 :
if ( V_138 )
F_317 ( stdout ) ;
else
F_318 ( stdout ) ;
return ! ferror ( stdout ) ;
case V_199 :
F_319 ( V_170 , stdout ) ;
return ! ferror ( stdout ) ;
default:
F_38 () ;
return FALSE ;
}
}
T_54
F_181 ( T_32 * V_281 , const char * V_66 , unsigned int type , T_10 V_318 , int * V_97 )
{
T_55 * V_321 ;
T_7 * V_325 ;
char V_119 [ 2048 + 1 ] ;
V_321 = F_320 ( V_66 , type , V_97 , & V_325 , V_173 ) ;
if ( V_321 == NULL )
goto V_445;
F_201 ( V_281 -> V_266 ) ;
V_281 -> V_266 = F_217 ( V_281 ) ;
V_281 -> V_321 = V_321 ;
V_281 -> V_446 = 0 ;
V_281 -> V_338 = F_34 ( V_66 ) ;
V_281 -> V_318 = V_318 ;
V_281 -> V_447 = FALSE ;
V_281 -> V_354 = F_321 ( V_281 -> V_321 ) ;
V_281 -> V_322 = type ;
V_281 -> V_347 = 0 ;
V_281 -> V_448 = FALSE ;
V_281 -> V_449 = 0 ;
V_281 -> V_450 = F_274 ( V_281 -> V_321 ) ;
if ( V_281 -> V_450 == 0 ) {
V_281 -> V_451 = FALSE ;
V_281 -> V_450 = V_375 ;
} else
V_281 -> V_451 = TRUE ;
F_322 ( & V_281 -> V_352 ) ;
V_282 = NULL ;
V_285 = NULL ;
V_286 = NULL ;
V_281 -> V_307 = V_452 ;
F_323 ( V_281 -> V_321 , V_453 ) ;
F_324 ( V_281 -> V_321 , ( V_454 ) V_455 ) ;
return V_248 ;
V_445:
F_325 ( V_119 , sizeof V_119 ,
F_326 ( * V_97 , V_325 , FALSE , V_281 -> V_354 ) , V_66 ) ;
F_35 ( L_142 , V_119 ) ;
return V_323 ;
}
static void
F_290 ( const char * V_66 , int V_97 , T_10 V_456 )
{
char * V_67 ;
V_67 = F_44 ( V_66 ) ;
switch ( V_97 ) {
case V_457 :
F_35 ( L_365
L_366 ,
V_67 ) ;
break;
#ifdef F_327
case F_327 :
F_35 ( L_367
L_368 ,
V_67 ) ;
break;
#endif
case V_458 :
F_35 ( L_369 ,
V_67 ) ;
break;
case V_382 :
F_35 ( L_370 ,
V_67 ) ;
break;
default:
if ( V_456 ) {
F_35 ( L_371 , V_67 ,
F_186 ( V_97 ) ) ;
} else {
F_35 ( L_372 ,
V_67 , F_186 ( V_97 ) ) ;
}
break;
}
F_11 ( V_67 ) ;
}
static void
F_195 ( int V_97 )
{
switch ( V_97 ) {
case V_457 :
F_35 ( L_373
L_366 ) ;
break;
#ifdef F_327
case F_327 :
F_35 ( L_374
L_368 ) ;
break;
#endif
default:
F_35 ( L_375 ,
F_119 ( V_97 ) ) ;
break;
}
}
static const char *
F_326 ( int V_97 , T_7 * V_325 , T_10 V_459 ,
int V_460 )
{
const char * V_461 ;
static char V_462 [ 1024 + 1 ] ;
if ( V_97 < 0 ) {
switch ( V_97 ) {
case V_463 :
V_461 = L_376 ;
break;
case V_464 :
V_461 = L_377 ;
break;
case V_465 :
V_461 = L_378 ;
break;
case V_393 :
F_325 ( V_462 , sizeof( V_462 ) ,
L_379
L_361 ,
V_325 != NULL ? V_325 : L_352 ) ;
F_11 ( V_325 ) ;
V_461 = V_462 ;
break;
case V_466 :
F_325 ( V_462 , sizeof( V_462 ) ,
L_380
L_381 , F_6 ( V_460 ) ) ;
V_461 = V_462 ;
break;
case V_378 :
V_461 = L_382 ;
break;
case V_379 :
F_325 ( V_462 , sizeof( V_462 ) ,
L_383 ,
F_6 ( V_460 ) ) ;
V_461 = V_462 ;
break;
case V_380 :
if ( V_459 ) {
F_325 ( V_462 , sizeof( V_462 ) ,
L_383 ,
F_6 ( V_460 ) ) ;
V_461 = V_462 ;
} else
V_461 = L_384 ;
break;
case V_395 :
F_325 ( V_462 , sizeof( V_462 ) ,
L_385
L_361 ,
V_325 != NULL ? V_325 : L_352 ) ;
F_11 ( V_325 ) ;
V_461 = V_462 ;
break;
case V_381 :
if ( V_459 )
V_461 = L_386 ;
else
V_461 = L_387 ;
break;
case V_394 :
V_461 = L_388
L_389 ;
break;
case V_382 :
V_461 = L_390 ;
break;
case V_467 :
V_461 = L_391 ;
break;
case V_396 :
F_325 ( V_462 , sizeof( V_462 ) ,
L_392
L_361 ,
V_325 != NULL ? V_325 : L_352 ) ;
F_11 ( V_325 ) ;
V_461 = V_462 ;
break;
default:
F_325 ( V_462 , sizeof( V_462 ) ,
L_393 ,
V_459 ? L_394 : L_395 ,
F_186 ( V_97 ) ) ;
V_461 = V_462 ;
break;
}
} else
V_461 = F_179 ( V_97 , V_459 ) ;
return V_461 ;
}
static void
V_151 ( const char * V_338 , int V_97 , T_10 V_459 )
{
fprintf ( V_7 , L_396 ) ;
fprintf ( V_7 , F_179 ( V_97 , V_459 ) , V_338 ) ;
fprintf ( V_7 , L_6 ) ;
}
static void
V_131 ( const char * V_468 , T_56 V_469 )
{
fprintf ( V_7 , L_396 ) ;
vfprintf ( V_7 , V_468 , V_469 ) ;
fprintf ( V_7 , L_6 ) ;
}
static void
V_152 ( const char * V_338 , int V_97 )
{
F_35 ( L_397 ,
V_338 , F_119 ( V_97 ) ) ;
}
static void
V_153 ( const char * V_338 , int V_97 )
{
F_35 ( L_398 ,
V_338 , F_119 ( V_97 ) ) ;
}
static void
V_132 ( const char * V_468 , T_56 V_469 )
{
vfprintf ( V_7 , V_468 , V_469 ) ;
fprintf ( V_7 , L_6 ) ;
}
