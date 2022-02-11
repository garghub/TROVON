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
fprintf ( V_18 , L_6 ) ;
fprintf ( V_18 , L_86 ) ;
fprintf ( V_18 , L_87 ) ;
fprintf ( V_18 , L_88 ) ;
fprintf ( V_18 , L_89 ) ;
fprintf ( V_18 , L_90 ) ;
fprintf ( V_18 , L_91 ) ;
fprintf ( V_18 , L_92 ) ;
fprintf ( V_18 , L_93 ) ;
#ifdef F_18
fprintf ( V_18 , L_6 ) ;
fprintf ( V_18 , L_94 ) ;
fprintf ( V_18 , L_95 ) ;
fprintf ( V_18 , L_96 ) ;
fprintf ( V_18 , L_6 ) ;
#endif
}
static void
F_19 ( void )
{
T_6 * V_18 ;
V_18 = stdout ;
fprintf ( V_18 , L_97 , F_20 () ) ;
fprintf ( V_18 , L_6 ) ;
fprintf ( V_18 , L_98 ) ;
fprintf ( V_18 , L_6 ) ;
fprintf ( V_18 , L_99 ) ;
fprintf ( V_18 , L_100 ) ;
fprintf ( V_18 , L_101 ) ;
fprintf ( V_18 , L_102 ) ;
fprintf ( V_18 , L_103 ) ;
fprintf ( V_18 , L_104 ) ;
fprintf ( V_18 , L_105 ) ;
fprintf ( V_18 , L_106 ) ;
fprintf ( V_18 , L_107 ) ;
fprintf ( V_18 , L_108 ) ;
fprintf ( V_18 , L_109 ) ;
fprintf ( V_18 , L_6 ) ;
fprintf ( V_18 , L_110 ) ;
fprintf ( V_18 , L_111 ) ;
fprintf ( V_18 , L_112 ) ;
fprintf ( V_18 , L_6 ) ;
}
static void
F_21 ( const char * V_21 , const char * V_22 ,
T_3 V_18 )
{
if ( ( V_23 == NULL ) ||
( strcmp ( V_23 , V_21 ) != 0 ) ) {
fprintf ( ( T_6 * ) V_18 , L_113 , V_21 , V_22 ) ;
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
fprintf ( ( T_6 * ) V_18 , L_113 ,
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
F_35 ( L_114 , V_38 , V_20 ) ;
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
F_35 ( L_115 ) ;
}
else {
V_46 = F_36 ( V_21 ) ;
if ( ! V_46 ) {
F_35 ( L_116 , V_21 ) ;
}
}
if ( ! V_46 ) {
F_35 ( L_117 ) ;
F_29 ( V_7 ) ;
}
if ( V_42 == NULL || ! V_46 ) {
F_11 ( V_41 ) ;
return FALSE ;
}
if ( * ( V_42 + 1 ) != '=' ) {
F_35 ( L_118 , V_21 , V_42 + 1 ) ;
}
else {
V_42 ++ ;
* V_42 = '\0' ;
}
V_42 ++ ;
V_43 = V_42 ;
V_42 = strchr ( V_43 , ',' ) ;
if ( V_42 == NULL ) {
F_35 ( L_114 , V_38 , V_20 ) ;
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
switch ( sscanf ( V_43 , L_119 , & V_39 , & V_50 , & V_40 ) ) {
case 1 :
V_50 = '\0' ;
break;
case 3 :
if ( V_50 != ':' && V_50 != '-' ) {
F_35 ( L_120 , V_43 ) ;
F_11 ( V_41 ) ;
return FALSE ;
}
if ( V_50 == ':' ) {
if ( ( V_40 == 0 ) || ( ( T_14 ) V_39 + V_40 - 1 ) > V_55 ) {
F_35 ( L_120 , V_43 ) ;
F_11 ( V_41 ) ;
return FALSE ;
}
}
else if ( V_40 < V_39 ) {
F_35 ( L_120 , V_43 ) ;
F_11 ( V_41 ) ;
return FALSE ;
}
break;
default:
F_35 ( L_121 , V_43 ) ;
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
F_35 ( L_122 , V_21 ) ;
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
F_35 ( L_123 ) ;
}
else {
V_49 . V_33 = 0 ;
V_49 . V_32 = V_44 ;
V_49 . V_34 = NULL ;
F_32 ( V_21 , F_27 , & V_49 ) ;
if ( V_49 . V_33 != 0 ) {
V_45 = V_49 . V_34 ;
if ( V_49 . V_33 > 1 ) {
F_35 ( L_124 , V_44 , V_49 . V_33 ) ;
}
}
else {
if ( F_39 ( V_44 ) == - 1 ) {
F_35 ( L_125 , V_44 ) ;
} else {
F_35 ( L_126 ,
V_44 , V_21 ) ;
}
}
}
if ( ! V_45 ) {
F_35 ( L_122 , V_21 ) ;
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
if ( strcmp ( V_66 , L_127 ) == 0 ) {
V_67 = F_34 ( L_128 ) ;
} else {
V_67 = F_45 ( L_129 , V_66 ) ;
}
return V_67 ;
}
static void
F_46 ( void ) {
T_7 * V_68 , * V_69 ;
if ( F_47 () ) {
V_68 = F_48 () ;
V_69 = F_49 () ;
fprintf ( V_7 , L_130 ,
V_68 , V_69 ) ;
F_11 ( V_68 ) ;
F_11 ( V_69 ) ;
if ( F_50 () ) {
fprintf ( V_7 , L_131 ) ;
}
fprintf ( V_7 , L_6 ) ;
}
}
static void
F_51 ( T_16 * V_70 )
{
F_52 ( V_70 ) ;
F_53 ( V_70 , L_132 ) ;
#ifdef F_54
F_53 ( V_70 , L_133 ) ;
#ifdef F_55
F_53 ( V_70 , F_55 ) ;
#else
F_53 ( V_70 , L_134 ) ;
#endif
#else
F_53 ( V_70 , L_135 ) ;
#endif
}
static void
F_56 ( T_16 * V_70 )
{
#ifdef F_14
F_53 ( V_70 , L_132 ) ;
F_57 ( V_70 ) ;
#endif
#if F_58 ( F_54 ) && ! F_58 ( V_71 )
F_59 ( V_70 , L_136 , F_60 () ) ;
#endif
F_61 ( V_70 ) ;
}
int
main ( int V_72 , char * V_73 [] )
{
T_16 * V_74 ;
T_16 * V_75 ;
char * V_76 ;
int V_77 ;
F_62 (cast-qual)
static const struct V_78 V_79 [] = {
{ ( char * ) L_137 , V_80 , NULL , 'h' } ,
{ ( char * ) L_138 , V_80 , NULL , 'v' } ,
V_81
{ 0 , 0 , 0 , 0 }
} ;
F_63 (cast-qual)
T_10 V_82 = FALSE ;
#ifdef V_71
T_17 V_83 ;
#endif
char * V_84 , * V_85 ;
char * V_86 , * V_87 ;
int V_88 , V_89 ;
int V_90 , V_91 ;
int V_92 , V_93 ;
int V_94 , V_95 ;
int V_96 ;
volatile int V_97 = 0 ;
#ifdef F_14
T_10 V_98 = FALSE ;
T_10 V_99 = FALSE ;
int V_100 ;
T_18 * V_101 ;
T_7 * V_102 ;
#else
T_10 V_103 = FALSE ;
#endif
T_10 V_104 = FALSE ;
#ifdef F_64
volatile int V_105 = V_106 ;
#else
volatile int V_105 = V_107 ;
#endif
volatile T_10 V_108 = FALSE ;
volatile int V_109 = V_110 ;
T_7 * volatile V_111 = NULL ;
T_7 * V_112 = NULL ;
T_7 * V_113 = NULL ;
#ifdef F_65
struct V_114 V_115 ;
#endif
T_19 * V_116 = NULL ;
T_19 * V_117 = NULL ;
T_7 * V_118 ;
T_20 * V_119 ;
char V_120 ;
int V_121 ;
T_7 * V_122 = NULL ;
T_5 * V_123 = NULL ;
T_5 * V_124 = NULL ;
T_5 * V_125 = NULL ;
#define F_66 "+2" OPTSTRING_CAPTURE_COMMON "C:d:e:E:F:gG:hH:" "K:lnN:o:O:PqQr:R:S:t:T:u:vVw:W:xX:Y:z:"
static const char V_126 [] = F_66 ;
F_67 ( L_139 , V_72 ) ;
setlocale ( V_127 , L_140 ) ;
F_68 ( V_128 , V_129 ) ;
#ifdef V_71
F_69 ( V_72 , V_73 ) ;
F_70 () ;
#if ! F_71 ( 2 , 31 , 0 )
F_72 ( NULL ) ;
#endif
#endif
F_73 () ;
F_74 () ;
F_46 () ;
V_76 = F_75 ( V_73 [ 0 ] , ( void * )main ) ;
if ( V_76 != NULL ) {
fprintf ( V_7 , L_141 ,
V_76 ) ;
}
F_76 () ;
#ifdef V_71
F_77 () ;
if ( ! F_78 () && F_79 () >= 6 ) {
fprintf ( V_7 , L_142
L_143 ) ;
}
#endif
V_74 = F_80 ( F_51 ,
V_130 ) ;
V_75 = F_81 ( F_56 ) ;
F_82 ( L_97
L_6
L_144
L_6
L_144 ,
F_20 () , V_74 -> V_70 , V_75 -> V_70 ) ;
F_83 ( V_74 , TRUE ) ;
F_83 ( V_75 , TRUE ) ;
V_131 = 0 ;
while ( ( V_77 = F_84 ( V_72 , V_73 , V_126 , V_79 , NULL ) ) != - 1 ) {
switch ( V_77 ) {
case 'C' :
if ( F_85 ( V_132 , FALSE ) ) {
F_86 ( V_132 ) ;
} else {
F_35 ( L_145 , V_132 ) ;
return 1 ;
}
break;
case 'P' :
V_133 = TRUE ;
V_134 = TRUE ;
break;
case 'O' :
V_122 = F_34 ( V_132 ) ;
case 'V' :
V_135 = TRUE ;
V_133 = TRUE ;
break;
case 'x' :
V_136 = TRUE ;
V_133 = TRUE ;
break;
case 'X' :
F_87 ( V_132 ) ;
break;
default:
break;
}
}
if ( V_134 == - 1 )
V_134 = ( V_135 || V_136 ) ? FALSE : TRUE ;
V_121 =
V_137 |
V_138 |
V_139 |
V_140 |
V_141 |
V_142 |
V_143 | V_144 ;
F_88 ( NULL ,
( T_15 ) V_121 ,
F_42 , NULL ) ;
F_88 ( V_145 ,
( T_15 ) V_121 ,
F_42 , NULL ) ;
#ifdef F_14
F_88 ( V_146 ,
( T_15 ) V_121 ,
F_42 , NULL ) ;
F_88 ( V_147 ,
( T_15 ) V_121 ,
F_42 , NULL ) ;
#endif
F_89 ( V_128 , V_148 , V_149 ,
V_150 ) ;
#ifdef F_14
F_90 ( & V_151 ) ;
F_91 ( & V_152 , & V_153 ) ;
#endif
F_92 ( V_154 ) ;
F_93 ( V_155 ) ;
F_94 ( V_156 ) ;
F_95 () ;
#ifdef F_96
F_97 () ;
F_98 () ;
F_99 () ;
F_100 () ;
#endif
F_101 ( V_157 , V_158 , NULL , NULL ) ;
#ifdef F_96
F_102 () ;
#endif
F_103 () ;
F_104 ( V_159 ) ;
F_105 ( V_160 ) ;
F_106 ( V_161 , NULL ) ;
F_107 ( V_162 , NULL ) ;
F_108 ( V_163 , NULL ) ;
if ( V_72 >= 2 && strcmp ( V_73 [ 1 ] , L_146 ) == 0 ) {
F_109 () ;
if ( V_72 == 2 )
F_110 () ;
else {
if ( strcmp ( V_73 [ 2 ] , L_147 ) == 0 )
F_111 () ;
else if ( strcmp ( V_73 [ 2 ] , L_148 ) == 0 ) {
F_112 ( & V_88 , & V_89 , & V_84 ,
& V_90 , & V_91 , & V_85 ) ;
F_113 ( NULL ) ;
}
else if ( strcmp ( V_73 [ 2 ] , L_149 ) == 0 )
F_114 () ;
else if ( strcmp ( V_73 [ 2 ] , L_150 ) == 0 )
F_113 ( NULL ) ;
else if ( strcmp ( V_73 [ 2 ] , L_151 ) == 0 )
F_115 () ;
else if ( strcmp ( V_73 [ 2 ] , L_152 ) == 0 ) {
return F_116 () ;
} else if ( strcmp ( V_73 [ 2 ] , L_153 ) == 0 )
F_110 () ;
else if ( strcmp ( V_73 [ 2 ] , L_154 ) == 0 )
F_117 () ;
else if ( strcmp ( V_73 [ 2 ] , L_155 ) == 0 )
F_118 () ;
else if ( strcmp ( V_73 [ 2 ] , L_156 ) == 0 ) {
#ifdef F_96
F_119 () ;
#endif
#ifdef F_120
F_121 () ;
#endif
}
else if ( strcmp ( V_73 [ 2 ] , L_157 ) == 0 )
F_122 () ;
else if ( strcmp ( V_73 [ 2 ] , L_158 ) == 0 )
F_123 () ;
else if ( strcmp ( V_73 [ 2 ] , L_159 ) == 0 )
F_19 () ;
else if ( strcmp ( V_73 [ 2 ] , L_160 ) == 0 )
F_19 () ;
else {
F_35 ( L_161 , V_73 [ 2 ] ) ;
return 1 ;
}
}
return 0 ;
}
F_67 ( L_162 ) ;
V_119 = F_112 ( & V_88 , & V_89 , & V_84 ,
& V_90 , & V_91 , & V_85 ) ;
if ( V_84 != NULL ) {
if ( V_88 != 0 ) {
F_35 ( L_163 ,
V_85 , F_124 ( V_88 ) ) ;
}
if ( V_89 != 0 ) {
F_35 ( L_164 ,
V_85 , F_124 ( V_89 ) ) ;
}
}
if ( V_85 != NULL ) {
if ( V_90 != 0 ) {
F_35 ( L_165 , V_85 ,
F_124 ( V_90 ) ) ;
}
if ( V_91 != 0 ) {
F_35 ( L_166 ,
V_85 , F_124 ( V_91 ) ) ;
}
F_11 ( V_85 ) ;
V_85 = NULL ;
}
F_125 ( & V_86 , & V_92 , & V_93 ,
& V_87 , & V_94 , & V_95 ) ;
F_126 ( & V_86 , & V_92 , & V_93 ,
& V_87 , & V_94 , & V_95 ) ;
if ( V_86 != NULL ) {
if ( V_92 != 0 ) {
F_35 ( L_167 ,
V_86 , F_124 ( V_92 ) ) ;
}
if ( V_93 != 0 ) {
F_35 ( L_168 ,
V_86 , F_124 ( V_93 ) ) ;
}
F_11 ( V_86 ) ;
}
if ( V_87 != NULL ) {
if ( V_94 != 0 ) {
F_35 (
L_169 , V_87 ,
F_124 ( V_94 ) ) ;
}
if ( V_95 != 0 ) {
F_35 (
L_170 , V_87 ,
F_124 ( V_95 ) ) ;
}
F_11 ( V_87 ) ;
}
F_127 ( & V_153 ) ;
V_164 = V_165 ;
V_166 = F_128 () ;
#ifdef F_129
V_167 = 1 ;
V_168 = 1 ;
#else
V_168 = 0 ;
#endif
V_131 = 1 ;
while ( ( V_77 = F_84 ( V_72 , V_73 , V_126 , V_79 , NULL ) ) != - 1 ) {
switch ( V_77 ) {
case '2' :
V_169 = TRUE ;
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
case V_170 :
#ifdef F_16
case 'B' :
#endif
#ifdef F_14
V_100 = F_130 ( & V_151 , V_77 , V_132 , & V_99 ) ;
if ( V_100 != 0 ) {
return V_100 ;
}
#else
if ( V_77 == 'w' ) {
V_171 = V_132 ;
} else {
V_103 = TRUE ;
V_82 = TRUE ;
}
#endif
break;
case 'C' :
break;
case 'd' :
if ( ! F_33 ( V_132 ) )
return 1 ;
break;
#if F_58 ( V_172 ) || F_58 ( V_173 )
case 'K' :
F_131 ( V_132 ) ;
break;
#endif
case 'D' :
#ifdef F_14
V_101 = F_132 ( & V_96 , & V_102 , NULL ) ;
if ( V_101 == NULL ) {
if ( V_96 == 0 )
F_35 ( L_171 ) ;
else {
F_35 ( L_144 , V_102 ) ;
F_11 ( V_102 ) ;
}
return 2 ;
}
F_133 ( V_101 ) ;
F_134 ( V_101 ) ;
return 0 ;
#else
V_103 = TRUE ;
V_82 = TRUE ;
#endif
break;
case 'e' :
F_135 ( V_166 , V_132 ) ;
break;
case 'E' :
if ( ! F_136 ( V_166 , V_132 ) ) {
F_35 ( L_172 , V_132 ) ;
F_137 ( V_7 ) ;
return 1 ;
}
break;
case 'F' :
V_105 = F_138 ( V_132 ) ;
if ( V_105 < 0 ) {
F_35 ( L_173 , V_132 ) ;
F_3 () ;
return 1 ;
}
break;
case 'W' :
if ( strchr ( V_132 , 'n' ) ) {
V_108 = TRUE ;
} else {
F_35 ( L_174 , V_132 ) ;
F_139 ( L_175 ) ;
return 1 ;
}
break;
case 'H' :
if ( ! F_140 ( V_132 ) )
{
F_35 ( L_176 , V_132 ) ;
return 1 ;
}
V_108 = TRUE ;
break;
case 'h' :
printf ( L_97
L_177
L_178 ,
F_20 () ) ;
F_13 ( stdout ) ;
return 0 ;
break;
case 'l' :
V_174 = TRUE ;
break;
case 'L' :
#ifdef F_14
V_98 = TRUE ;
#else
V_103 = TRUE ;
V_82 = TRUE ;
#endif
break;
case 'n' :
F_141 () ;
break;
case 'N' :
V_120 = F_142 ( V_132 , & V_175 ) ;
if ( V_120 != '\0' ) {
F_35 ( L_179 ,
V_120 ) ;
F_139 ( L_180
L_181
L_182
L_183
L_184
L_185
L_186 ) ;
return 1 ;
}
break;
case 'o' :
switch ( F_143 ( V_132 ) ) {
case V_176 :
break;
case V_177 :
F_35 ( L_187 , V_132 ) ;
return 1 ;
break;
case V_178 :
case V_179 :
F_35 ( L_188 , V_132 ) ;
return 1 ;
break;
}
break;
case 'q' :
V_104 = TRUE ;
break;
case 'Q' :
V_104 = TRUE ;
V_180 = TRUE ;
break;
case 'r' :
V_111 = F_34 ( V_132 ) ;
break;
case 'R' :
V_112 = V_132 ;
break;
case 'P' :
break;
case 'S' :
V_181 = V_132 ;
break;
case 't' :
if ( strcmp ( V_132 , L_189 ) == 0 )
F_92 ( V_154 ) ;
else if ( strcmp ( V_132 , L_190 ) == 0 )
F_92 ( V_182 ) ;
else if ( strcmp ( V_132 , L_191 ) == 0 )
F_92 ( V_183 ) ;
else if ( strcmp ( V_132 , L_192 ) == 0 )
F_92 ( V_184 ) ;
else if ( strcmp ( V_132 , L_193 ) == 0 )
F_92 ( V_185 ) ;
else if ( strcmp ( V_132 , L_194 ) == 0 )
F_92 ( V_186 ) ;
else if ( strcmp ( V_132 , L_195 ) == 0 )
F_92 ( V_187 ) ;
else if ( strcmp ( V_132 , L_196 ) == 0 )
F_92 ( V_188 ) ;
else if ( strcmp ( V_132 , L_197 ) == 0 )
F_92 ( V_189 ) ;
else if ( strcmp ( V_132 , L_198 ) == 0 )
F_92 ( V_190 ) ;
else {
F_35 ( L_199 , V_132 ) ;
F_139 ( L_200
L_201
L_202
L_203
L_204
L_205
L_206
L_207
L_208
L_209 ) ;
return 1 ;
}
break;
case 'T' :
V_133 = TRUE ;
if ( strcmp ( V_132 , L_210 ) == 0 ) {
V_191 = V_192 ;
V_164 = V_165 ;
} else if ( strcmp ( V_132 , L_211 ) == 0 ) {
V_191 = V_192 ;
V_164 = V_193 ;
} else if ( strcmp ( V_132 , L_212 ) == 0 ) {
V_191 = V_194 ;
V_135 = TRUE ;
V_134 = FALSE ;
} else if ( strcmp ( V_132 , L_213 ) == 0 ) {
V_191 = V_194 ;
V_135 = FALSE ;
V_134 = TRUE ;
} else if ( strcmp ( V_132 , L_153 ) == 0 ) {
V_191 = V_195 ;
V_135 = TRUE ;
V_134 = FALSE ;
} else {
F_35 ( L_214 , V_132 ) ;
F_139 ( L_215
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
L_228
L_229
L_230 ) ;
return 1 ;
}
break;
case 'u' :
if ( strcmp ( V_132 , L_231 ) == 0 )
F_94 ( V_156 ) ;
else if ( strcmp ( V_132 , L_232 ) == 0 )
F_94 ( V_196 ) ;
else {
F_35 ( L_233 , V_132 ) ;
F_139 ( L_234
L_235 ) ;
return 1 ;
}
break;
case 'v' :
V_74 = F_80 ( F_51 ,
V_130 ) ;
V_75 = F_81 ( F_56 ) ;
F_144 ( L_236 , V_74 , V_75 ) ;
F_83 ( V_74 , TRUE ) ;
F_83 ( V_75 , TRUE ) ;
F_145 () ;
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
V_113 = V_132 ;
break;
case 'z' :
if ( strcmp ( L_137 , V_132 ) == 0 ) {
fprintf ( V_7 , L_237 ) ;
F_146 () ;
return 0 ;
}
if ( ! F_147 ( V_132 ) ) {
F_35 ( L_238 , V_132 ) ;
F_146 () ;
return 1 ;
}
break;
case V_197 :
V_123 = F_148 ( V_123 , V_132 ) ;
break;
case V_198 :
V_124 = F_148 ( V_124 , V_132 ) ;
break;
case V_199 :
V_125 = F_148 ( V_125 , V_132 ) ;
break;
default:
case '?' :
switch( V_200 ) {
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
if ( V_195 != V_191 && 0 != F_149 ( V_166 ) ) {
F_35 ( L_239
L_240 ) ;
return 1 ;
} else if ( V_195 == V_191 && 0 == F_149 ( V_166 ) ) {
F_35 ( L_241
L_242 ) ;
return 1 ;
}
if ( V_168 < V_72 ) {
if ( V_111 != NULL ) {
if ( V_113 != NULL ) {
F_35 ( L_243
L_244 ) ;
return 1 ;
}
V_113 = F_150 ( V_72 , V_73 , V_168 ) ;
} else {
#ifdef F_14
T_21 V_9 ;
if ( V_151 . V_201 . V_202 ) {
F_35 ( L_245
L_246 ) ;
return 1 ;
}
for ( V_9 = 0 ; V_9 < V_151 . V_203 -> V_204 ; V_9 ++ ) {
T_22 V_205 ;
V_205 = F_151 ( V_151 . V_203 , T_22 , V_9 ) ;
if ( V_205 . V_202 == NULL ) {
V_205 . V_202 = F_150 ( V_72 , V_73 , V_168 ) ;
V_151 . V_203 = F_152 ( V_151 . V_203 , V_9 ) ;
F_153 ( V_151 . V_203 , V_9 , V_205 ) ;
} else {
F_35 ( L_247
L_246 ) ;
return 1 ;
}
}
V_151 . V_201 . V_202 = F_150 ( V_72 , V_73 , V_168 ) ;
#else
V_103 = TRUE ;
#endif
}
}
#ifdef F_14
if ( ! V_151 . V_206 ) {
if ( ! V_104 )
V_133 = TRUE ;
} else {
if ( strcmp ( V_151 . V_207 , L_127 ) == 0 && V_133 ) {
F_35 ( L_248
L_249 ) ;
return 1 ;
}
}
#else
if ( ! V_104 )
V_133 = TRUE ;
#endif
#ifndef F_14
if ( V_103 )
F_35 ( L_250 ) ;
#endif
if ( V_82 ) {
F_13 ( V_7 ) ;
return 1 ;
}
if ( V_136 ) {
if ( V_191 != V_192 ) {
F_35 ( L_251 ) ;
return 1 ;
}
}
if ( V_122 != NULL ) {
char * V_208 ;
if ( ! V_135 ) {
F_35 ( L_252 ) ;
return 1 ;
}
V_209 = F_154 ( V_210 , V_211 ) ;
for ( V_208 = strtok ( V_122 , L_253 ) ; V_208 ; V_208 = strtok ( NULL , L_253 ) ) {
F_155 ( V_209 , ( T_3 ) V_208 , ( T_3 ) V_208 ) ;
}
}
if ( V_112 != NULL && ! V_169 ) {
F_35 ( L_254 ) ;
return 1 ;
}
#ifdef F_14
if ( V_98 ) {
if ( V_111 ) {
F_35 ( L_255 ) ;
return 1 ;
}
if ( V_151 . V_212 ) {
F_35 ( L_256 ) ;
return 1 ;
}
} else {
if ( V_111 ) {
if ( V_151 . V_201 . V_202 ) {
F_35 ( L_257
L_258 ) ;
return 1 ;
}
if ( V_151 . V_212 ) {
F_35 ( L_259
L_260 ) ;
return 1 ;
}
if ( V_151 . V_213 ) {
F_35 ( L_261
L_260 ) ;
return 1 ;
}
if ( V_151 . V_214 ) {
F_35 ( L_262
L_260 ) ;
return 1 ;
}
if ( V_151 . V_215 ) {
F_35 ( L_263
L_260 ) ;
return 1 ;
}
if ( V_151 . V_216 ) {
F_35 ( L_264
L_265
L_266 ) ;
return 1 ;
}
if ( V_151 . V_217 ) {
F_35 ( L_267
L_260 ) ;
return 1 ;
}
} else {
if ( V_169 ) {
F_35 ( L_268 ) ;
return 1 ;
}
if ( V_151 . V_206 ) {
if ( V_105 != V_107 &&
V_105 != V_106 ) {
F_35 ( L_269 ) ;
return 1 ;
}
if ( V_151 . V_216 &&
V_105 != V_106 ) {
F_35 ( L_270 ) ;
return 1 ;
}
if ( V_151 . V_212 ) {
if ( strcmp ( V_151 . V_207 , L_127 ) == 0 ) {
F_35 ( L_259
L_271 ) ;
return 1 ;
}
if ( V_151 . V_218 ) {
F_35 ( L_259
L_272 ) ;
return 1 ;
}
if ( ! V_151 . V_219 &&
! V_151 . V_213 ) {
F_35 ( L_259
L_273 ) ;
return 1 ;
}
}
if ( V_112 != NULL ) {
F_35 ( L_274 ) ;
return 1 ;
}
if ( V_113 != NULL ) {
F_35 ( L_275 ) ;
return 1 ;
}
V_151 . V_220 = ( V_105 == V_106 ) ? TRUE : FALSE ;
} else {
if ( V_151 . V_219 ) {
F_35 ( L_276
L_277 ) ;
return 1 ;
}
if ( V_151 . V_212 ) {
F_35 ( L_259
L_278 ) ;
return 1 ;
}
if ( V_151 . V_216 ) {
F_35 ( L_264
L_278 ) ;
return 1 ;
}
}
}
}
#endif
#ifdef V_71
F_156 ( F_157 ( 1 , 1 ) , & V_83 ) ;
#endif
F_158 () ;
F_159 () ;
{
T_5 * V_221 = NULL ;
T_5 * V_222 = F_160 ( V_166 ) ;
if ( V_222 != NULL ) {
F_35 ( L_279 ) ;
for ( V_221 = V_222 ; V_221 != NULL ; V_221 = F_161 ( V_221 ) ) {
F_139 ( L_280 , ( T_7 * ) V_221 -> V_5 ) ;
}
F_10 ( V_222 ) ;
return 1 ;
}
}
#ifdef F_14
if ( V_151 . V_206 &&
V_151 . V_218 ) {
if ( F_162 () ) {
F_35 ( L_281 ) ;
return 1 ;
}
if ( V_133 ) {
F_35 ( L_282 ) ;
return 1 ;
}
}
#endif
if ( F_163 ( L_283 ) > 0 ) {
const T_7 * V_16 = F_164 ( L_283 ) ;
V_109 = F_165 ( V_16 ) ;
if ( V_109 == V_110 ) {
F_35 ( L_284 , V_16 ? V_16 : L_140 ) ;
F_12 () ;
return 1 ;
}
}
if ( V_86 == NULL && V_87 == NULL ) {
F_166 () ;
F_167 () ;
}
if( V_123 ) {
T_5 * V_223 ;
for ( V_223 = V_123 ; V_223 != NULL ; V_223 = F_161 ( V_223 ) )
{
F_168 ( ( char * ) V_223 -> V_5 ) ;
}
}
if( V_124 ) {
T_5 * V_224 ;
for ( V_224 = V_124 ; V_224 != NULL ; V_224 = F_161 ( V_224 ) )
{
F_169 ( ( char * ) V_224 -> V_5 , TRUE ) ;
}
}
if( V_125 ) {
T_5 * V_225 ;
for ( V_225 = V_125 ; V_225 != NULL ; V_225 = F_161 ( V_225 ) )
{
F_169 ( ( char * ) V_225 -> V_5 , FALSE ) ;
}
}
F_170 ( & V_153 . V_226 , V_119 -> V_227 , TRUE ) ;
#ifdef F_14
F_171 ( & V_151 , V_228 ) ;
F_172 ( & V_151 ) ;
#endif
if ( V_112 != NULL ) {
F_67 ( L_285 , V_112 ) ;
if ( ! F_173 ( V_112 , & V_116 , & V_118 ) ) {
F_35 ( L_144 , V_118 ) ;
F_11 ( V_118 ) ;
F_145 () ;
#ifdef F_65
{
T_23 * V_229 ;
V_229 = F_174 ( V_230 , V_228 ) ;
if ( V_229 != NULL ) {
if ( F_175 ( V_229 , & V_115 , V_112 , 0 , 0 ) != - 1 ) {
F_139 (
L_286
L_287 ) ;
}
F_176 ( V_229 ) ;
}
}
#endif
return 2 ;
}
}
V_153 . V_116 = V_116 ;
if ( V_113 != NULL ) {
F_67 ( L_288 , V_113 ) ;
if ( ! F_173 ( V_113 , & V_117 , & V_118 ) ) {
F_35 ( L_144 , V_118 ) ;
F_11 ( V_118 ) ;
F_145 () ;
#ifdef F_65
{
T_23 * V_229 ;
V_229 = F_174 ( V_230 , V_228 ) ;
if ( V_229 != NULL ) {
if ( F_175 ( V_229 , & V_115 , V_113 , 0 , 0 ) != - 1 ) {
F_139 (
L_289
L_287 ) ;
}
F_176 ( V_229 ) ;
}
}
#endif
return 2 ;
}
}
V_153 . V_117 = V_117 ;
if ( V_133 ) {
if ( V_191 == V_192 ) {
switch ( V_164 ) {
case V_165 :
V_231 = F_177 ( stdout ) ;
break;
case V_193 :
V_231 = F_178 ( stdout ) ;
break;
default:
F_38 () ;
}
}
}
V_232 = V_133 || V_116 || V_117 || F_162 () ;
F_67 ( L_290 , V_232 ? L_291 : L_292 ) ;
if ( V_111 ) {
F_67 ( L_293 , V_111 ) ;
if ( F_179 ( & V_153 , V_111 , V_109 , FALSE , & V_96 ) != V_233 ) {
F_145 () ;
return 2 ;
}
F_67 ( L_294 ) ;
F_180 {
#ifdef F_14
V_96 = F_181 ( & V_153 , V_151 . V_207 , V_105 , V_108 ,
V_151 . V_234 ? V_151 . V_235 : 0 ,
V_151 . V_219 ? V_151 . V_236 : 0 ) ;
#else
V_96 = F_181 ( & V_153 , V_171 , V_105 , V_108 , 0 , 0 ) ;
#endif
}
F_182 (OutOfMemoryError) {
fprintf ( V_7 ,
L_295
L_6
L_296
L_6
L_297
L_298 ) ;
V_96 = V_237 ;
}
V_238 ;
if ( V_96 != 0 ) {
V_97 = 2 ;
}
} else {
F_67 ( L_299 ) ;
#ifdef F_14
V_97 = F_183 ( & V_151 ,
( ( V_119 -> V_239 ) && ( * V_119 -> V_239 != '\0' ) ) ? F_184 ( V_119 -> V_239 ) : NULL ) ;
if ( V_97 != 0 )
return V_97 ;
if ( V_98 ) {
T_21 V_9 ;
for ( V_9 = 0 ; V_9 < V_151 . V_203 -> V_204 ; V_9 ++ ) {
T_22 V_205 ;
T_24 * V_240 ;
char * V_241 = NULL ;
V_205 = F_151 ( V_151 . V_203 , T_22 , V_9 ) ;
#ifdef F_17
if ( V_205 . V_242 == V_243 ) {
V_241 = F_45 ( L_300 , V_205 . V_244 , V_205 . V_245 ) ;
}
#endif
V_240 = F_185 ( V_205 . V_16 , V_205 . V_246 , V_241 , & V_102 , NULL ) ;
F_11 ( V_241 ) ;
if ( V_240 == NULL ) {
F_35 ( L_144 , V_102 ) ;
F_11 ( V_102 ) ;
return 2 ;
}
if ( V_240 -> V_247 == NULL ) {
F_35 ( L_301 , V_205 . V_16 ) ;
return 2 ;
}
F_186 ( V_240 , V_205 . V_16 , V_205 . V_246 ) ;
F_187 ( V_240 ) ;
}
return 0 ;
}
if ( ! F_188 ( fileno ( V_7 ) ) )
V_248 = FALSE ;
else if ( V_133 && F_188 ( fileno ( stdout ) ) )
V_248 = FALSE ;
else if ( V_104 )
V_248 = FALSE ;
else
V_248 = TRUE ;
if ( V_133 ) {
if ( ! F_189 ( & V_153 ) ) {
F_190 ( V_249 ) ;
return 2 ;
}
}
F_67 ( L_302 ) ;
F_191 () ;
V_97 = V_152 . V_250 ;
if ( V_133 ) {
if ( ! F_192 () ) {
V_96 = V_249 ;
F_190 ( V_96 ) ;
}
}
#else
F_35 ( L_250 ) ;
return 2 ;
#endif
}
F_11 ( V_111 ) ;
if ( V_153 . V_251 != NULL ) {
F_193 ( V_153 . V_251 ) ;
V_153 . V_251 = NULL ;
}
F_194 ( TRUE ) ;
F_195 () ;
F_196 ( V_153 . V_252 ) ;
F_145 () ;
F_197 ( V_166 ) ;
V_166 = NULL ;
return V_97 ;
}
static T_1
F_198 ( T_3 V_5 )
{
T_25 V_24 ;
T_26 V_253 = 0 ;
T_10 V_254 ;
T_26 V_255 ;
T_27 * V_256 = V_5 ;
T_1 V_257 = 0 ;
F_199 ( V_256 -> V_258 ) ;
while( V_257 < 5 ) {
V_24 = ( T_25 ) F_200 ( V_256 -> V_259 ) ;
V_254 = F_201 ( V_24 , NULL , 0 , NULL , & V_253 , NULL ) ;
F_202 ( ( T_25 ) * ( V_256 -> V_260 ) ,
& V_255 ) ;
if ( ! V_254 || V_253 > 0 || V_255 != V_261 ) {
if ( ! V_256 -> V_262 ( V_256 -> V_259 , V_256 -> V_29 ) ) {
F_203 ( NULL , V_142 , L_303 , V_257 ) ;
F_204 ( V_256 -> V_258 ) ;
return FALSE ;
}
}
else {
break;
}
V_257 ++ ;
}
F_204 ( V_256 -> V_258 ) ;
return TRUE ;
}
void
F_205 ( T_1 V_259 , T_3 V_29 , T_28 * V_260 , T_29 V_262 )
{
V_263 . V_259 = V_259 ;
V_263 . V_260 = V_260 ;
V_263 . V_29 = V_29 ;
V_263 . V_262 = V_262 ;
#ifdef V_71
#if F_71 ( 2 , 31 , 0 )
V_263 . V_258 = F_206 ( sizeof( V_264 ) ) ;
F_207 ( V_263 . V_258 ) ;
#else
V_263 . V_258 = F_208 () ;
#endif
V_263 . V_265 = F_209 ( 200 , F_198 , & V_263 ) ;
#endif
}
static const T_30 *
F_210 ( void * V_5 , T_11 V_266 )
{
T_31 * V_267 = ( T_31 * ) V_5 ;
if ( V_268 && V_268 -> V_269 == V_266 )
return & V_268 -> V_270 ;
if ( V_271 && V_271 -> V_269 == V_266 )
return & V_271 -> V_270 ;
if ( V_272 && V_272 -> V_269 == V_266 )
return & V_272 -> V_270 ;
if ( V_267 -> V_251 ) {
T_32 * V_273 = F_211 ( V_267 -> V_251 , V_266 ) ;
return ( V_273 ) ? & V_273 -> V_270 : NULL ;
}
return NULL ;
}
static T_33 *
F_212 ( T_31 * V_267 )
{
T_33 * V_252 = F_213 () ;
V_252 -> V_5 = V_267 ;
V_252 -> V_274 = F_210 ;
V_252 -> V_275 = V_276 ;
V_252 -> V_277 = NULL ;
return V_252 ;
}
static T_10
F_191 ( void )
{
T_10 V_278 ;
T_21 V_9 ;
T_16 * V_70 ;
#ifdef F_214
T_34 V_279 ;
#endif
#ifndef V_71
struct V_280 V_281 , V_282 ;
#endif
F_196 ( V_153 . V_252 ) ;
V_153 . V_252 = F_212 ( & V_153 ) ;
#ifdef V_71
F_215 ( V_283 , TRUE ) ;
#else
memset ( & V_281 , 0 , sizeof( V_281 ) ) ;
V_281 . V_284 = V_283 ;
V_281 . V_285 = V_286 ;
F_216 ( & V_281 . V_287 ) ;
V_280 ( V_288 , & V_281 , NULL ) ;
V_280 ( V_289 , & V_281 , NULL ) ;
V_280 ( V_290 , NULL , & V_282 ) ;
if ( V_282 . V_284 == V_291 )
V_280 ( V_290 , & V_281 , NULL ) ;
#ifdef F_217
V_281 . V_284 = V_292 ;
V_281 . V_285 = V_286 ;
F_216 ( & V_281 . V_287 ) ;
V_280 ( F_217 , & V_281 , NULL ) ;
#endif
#endif
V_152 . V_293 = V_294 ;
for ( V_9 = 0 ; V_9 < V_151 . V_203 -> V_204 ; V_9 ++ ) {
T_22 V_205 ;
V_205 = F_151 ( V_151 . V_203 , T_22 , V_9 ) ;
V_205 . V_295 = F_218 ( V_205 . V_16 ) ;
V_151 . V_203 = F_152 ( V_151 . V_203 , V_9 ) ;
F_153 ( V_151 . V_203 , V_9 , V_205 ) ;
}
V_70 = F_219 ( & V_151 , V_296 ) ;
if ( V_180 == FALSE )
fprintf ( V_7 , L_304 , V_70 -> V_70 ) ;
fflush ( V_7 ) ;
F_83 ( V_70 , TRUE ) ;
V_278 = F_220 ( & V_151 , & V_152 , NULL ) ;
if ( ! V_278 )
return FALSE ;
#ifdef F_214
F_221 ( & V_279 ) ;
F_222 ( V_263 . V_259 , & V_279 ) ;
#endif
V_297 = TRUE ;
F_180
{
while ( V_297 )
{
#ifdef F_214
V_278 = F_223 ( V_263 . V_259 + 1 , & V_279 , NULL , NULL , NULL ) ;
if ( V_278 == - 1 )
{
fprintf ( V_7 , L_305 , L_306 , F_124 ( V_249 ) ) ;
return TRUE ;
} else if ( V_278 == 1 ) {
#endif
if ( ! V_263 . V_262 ( V_263 . V_259 , V_263 . V_29 ) ) {
F_203 ( NULL , V_142 , L_307 ) ;
return FALSE ;
}
#ifdef F_214
}
#endif
}
}
F_182 (OutOfMemoryError) {
fprintf ( V_7 ,
L_295
L_6
L_296
L_6
L_297
L_298 ) ;
exit ( 1 ) ;
}
V_238 ;
return TRUE ;
}
void
F_224 ( T_35 * T_36 V_6 , char * V_298 , char * V_299 )
{
F_35 ( L_144 , V_298 ) ;
F_139 ( L_144 , V_299 ) ;
}
void
F_225 ( T_35 * T_36 , T_21 V_9 , char * V_300 )
{
T_37 * V_301 = T_36 -> V_301 ;
T_19 * V_116 = NULL ;
T_22 V_205 ;
F_26 ( V_9 < V_301 -> V_203 -> V_204 ) ;
V_205 = F_151 ( V_301 -> V_203 , T_22 , V_9 ) ;
if ( F_173 ( V_205 . V_202 , & V_116 , NULL ) && V_116 != NULL ) {
F_35 (
L_308
L_6
L_309
L_310
L_6
L_311
L_312
L_6
L_313 ,
V_205 . V_202 , V_205 . V_295 , V_300 ) ;
F_226 ( V_116 ) ;
} else {
F_35 (
L_308
L_6
L_314
L_313 ,
V_205 . V_202 , V_205 . V_295 , V_300 ) ;
}
}
T_10
F_227 ( T_35 * T_36 , T_7 * V_302 )
{
T_37 * V_301 = T_36 -> V_301 ;
T_31 * V_267 = ( T_31 * ) T_36 -> V_267 ;
T_10 V_303 ;
int V_96 ;
if ( T_36 -> V_293 == V_294 ) {
F_203 ( V_146 , V_140 , L_315 ) ;
}
F_203 ( V_146 , V_140 , L_316 , V_302 ) ;
F_26 ( T_36 -> V_293 == V_294 || T_36 -> V_293 == V_304 ) ;
if ( V_301 -> V_207 != NULL ) {
if ( V_267 -> V_293 != V_305 ) {
if ( V_267 -> V_306 != NULL ) {
F_228 ( V_267 -> V_306 ) ;
V_267 -> V_306 = NULL ;
}
V_267 -> V_293 = V_305 ;
}
F_11 ( V_301 -> V_207 ) ;
V_303 = FALSE ;
F_196 ( V_267 -> V_252 ) ;
V_267 -> V_252 = F_212 ( V_267 ) ;
} else {
V_303 = TRUE ;
}
V_301 -> V_207 = F_34 ( V_302 ) ;
if ( V_232 ) {
( ( T_31 * ) T_36 -> V_267 ) -> V_307 = V_110 ;
switch( F_179 ( ( T_31 * ) T_36 -> V_267 , V_301 -> V_207 , V_110 , V_303 , & V_96 ) ) {
case V_233 :
break;
case V_308 :
F_11 ( V_301 -> V_207 ) ;
V_301 -> V_207 = NULL ;
return FALSE ;
}
}
T_36 -> V_293 = V_304 ;
return TRUE ;
}
void
F_229 ( T_35 * T_36 , int V_309 )
{
T_10 V_278 ;
int V_96 ;
T_7 * V_310 ;
T_38 V_311 ;
T_31 * V_267 = ( T_31 * ) T_36 -> V_267 ;
T_10 V_312 ;
T_21 V_313 ;
#ifdef F_217
V_314 = TRUE ;
#endif
V_312 = F_230 () ;
V_313 = F_231 () ;
if ( V_232 ) {
T_10 V_315 ;
T_39 * V_316 ;
if ( V_267 -> V_116 || V_267 -> V_117 || V_135 || V_312 ||
( V_313 & V_317 ) || F_232 ( & V_267 -> V_226 ) )
V_315 = TRUE ;
else
V_315 = FALSE ;
V_316 = F_233 ( V_267 -> V_252 , V_315 , V_133 && V_135 ) ;
while ( V_309 -- && V_267 -> V_306 ) {
F_234 ( V_267 -> V_306 ) ;
V_278 = F_235 ( V_267 -> V_306 , & V_96 , & V_310 , & V_311 ) ;
if ( V_278 == FALSE ) {
F_236 ( T_36 ) ;
F_228 ( V_267 -> V_306 ) ;
V_267 -> V_306 = NULL ;
} else {
V_278 = F_237 ( V_267 , V_316 , V_311 , F_238 ( V_267 -> V_306 ) ,
F_239 ( V_267 -> V_306 ) ,
V_313 ) ;
}
if ( V_278 != FALSE ) {
V_318 ++ ;
}
}
F_240 ( V_316 ) ;
} else {
V_318 += V_309 ;
}
if ( V_248 ) {
if ( V_318 != 0 ) {
fprintf ( V_7 , L_317 , V_318 ) ;
fflush ( V_7 ) ;
}
}
#ifdef F_217
V_314 = FALSE ;
if ( V_319 )
F_241 () ;
#endif
}
static void
F_241 ( void )
{
if ( ( V_248 == FALSE ) && ( V_180 == FALSE ) ) {
fprintf ( V_7 , L_318 , V_318 ,
F_242 ( V_318 , L_140 , L_231 ) ) ;
}
#ifdef F_217
V_319 = FALSE ;
#endif
}
static void
V_292 ( int T_40 V_6 )
{
int V_320 = V_249 ;
if ( V_314 )
V_319 = TRUE ;
else
F_241 () ;
V_249 = V_320 ;
}
void
F_243 ( T_35 * T_36 V_6 , T_11 V_321 )
{
if ( V_248 ) {
fprintf ( V_7 , L_6 ) ;
}
if ( V_321 != 0 ) {
fprintf ( V_7 , L_319 , V_321 , F_242 ( V_321 , L_140 , L_231 ) ) ;
}
}
void
F_244 ( T_35 * T_36 , T_7 * V_322 )
{
T_31 * V_267 = ( T_31 * ) T_36 -> V_267 ;
if ( V_322 != NULL )
fprintf ( V_7 , L_320 , V_322 ) ;
F_241 () ;
if ( V_267 != NULL && V_267 -> V_306 != NULL ) {
F_228 ( V_267 -> V_306 ) ;
if ( V_267 -> V_303 ) {
F_245 ( V_267 -> V_323 ) ;
}
}
#ifdef F_246
F_247 ( V_324 ) ;
#else
V_297 = FALSE ;
#endif
}
static BOOL T_41
V_283 ( T_26 T_42 V_6 )
{
F_236 ( & V_152 ) ;
return TRUE ;
}
static void
V_283 ( int T_40 V_6 )
{
F_236 ( & V_152 ) ;
}
static T_10
F_248 ( T_31 * V_267 , T_39 * V_316 ,
T_38 V_325 , struct V_326 * V_327 ,
const T_43 * V_328 )
{
T_32 V_329 ;
T_11 V_330 ;
T_10 V_331 ;
V_330 = V_267 -> V_332 + 1 ;
V_331 = TRUE ;
F_249 ( & V_329 , V_330 , V_327 , V_325 , V_333 ) ;
if ( V_316 ) {
if ( V_175 . V_334 || V_175 . V_335 ||
V_175 . V_336 || V_175 . V_337 )
F_250 () ;
if ( V_267 -> V_116 )
F_251 ( V_316 , V_267 -> V_116 ) ;
if ( V_267 -> V_117 )
F_251 ( V_316 , V_267 -> V_117 ) ;
F_252 ( & V_329 , & V_267 -> V_338 ,
& V_268 , V_271 ) ;
if ( V_268 == & V_329 ) {
V_339 = V_329 ;
V_268 = & V_339 ;
}
F_253 ( V_316 , V_267 -> V_340 , V_327 , F_254 ( & V_329 , V_328 ) , & V_329 , NULL ) ;
if ( V_267 -> V_116 )
V_331 = F_255 ( V_267 -> V_116 , V_316 ) ;
}
if ( V_331 ) {
F_256 ( & V_329 , & V_333 ) ;
V_272 = V_271 = F_257 ( V_267 -> V_251 , & V_329 ) ;
if ( V_316 && V_267 -> V_117 ) {
if ( F_255 ( V_267 -> V_117 , V_316 ) ) {
F_9 ( V_316 -> V_341 . V_342 , V_343 , V_267 -> V_251 ) ;
}
}
V_267 -> V_332 ++ ;
} else {
F_258 ( & V_329 ) ;
}
if ( V_316 )
F_259 ( V_316 ) ;
return V_331 ;
}
static T_10
F_260 ( T_31 * V_267 , T_39 * V_316 , T_32 * V_344 ,
struct V_326 * V_345 , T_44 * V_346 ,
T_21 V_313 )
{
T_45 * V_226 ;
T_10 V_331 ;
V_331 = TRUE ;
if ( V_316 ) {
if ( V_175 . V_334 || V_175 . V_335 ||
V_175 . V_336 || V_175 . V_337 )
F_250 () ;
if ( V_267 -> V_117 )
F_251 ( V_316 , V_267 -> V_117 ) ;
F_261 ( V_316 , & V_267 -> V_226 ) ;
if ( ( V_313 & V_347 ) || ( V_133 && V_134 ) || F_262 ( V_166 ) )
V_226 = & V_267 -> V_226 ;
else
V_226 = NULL ;
F_252 ( V_344 , & V_267 -> V_338 ,
& V_268 , V_271 ) ;
if ( V_268 == V_344 ) {
V_339 = * V_344 ;
V_268 = & V_339 ;
}
F_263 ( V_316 , V_267 -> V_340 , V_345 , F_264 ( V_344 , V_346 ) , V_344 , V_226 ) ;
if ( V_267 -> V_117 )
V_331 = F_255 ( V_267 -> V_117 , V_316 ) ;
}
if ( V_331 ) {
F_256 ( V_344 , & V_333 ) ;
if ( V_133 ) {
F_265 ( V_267 , V_316 ) ;
if ( V_174 )
fflush ( stdout ) ;
if ( ferror ( stdout ) ) {
F_190 ( V_249 ) ;
exit ( 2 ) ;
}
}
V_271 = V_344 ;
}
V_272 = V_344 ;
if ( V_316 ) {
F_259 ( V_316 ) ;
}
return V_331 || V_344 -> V_348 . V_349 ;
}
static int
F_181 ( T_31 * V_267 , char * V_207 , int V_105 ,
T_10 V_108 , int V_350 , T_38 V_351 )
{
T_1 V_352 ;
int V_353 ;
T_46 * V_354 ;
T_11 V_330 ;
int V_96 ;
T_7 * V_310 = NULL ;
T_38 V_311 ;
char * V_67 = NULL ;
T_10 V_312 ;
T_21 V_313 ;
T_47 * V_355 = NULL ;
T_48 * V_356 = NULL ;
T_49 * V_357 = NULL ;
struct V_326 V_345 ;
T_44 V_346 ;
T_39 * V_316 = NULL ;
F_266 ( & V_345 ) ;
V_356 = F_267 ( V_267 -> V_306 ) ;
#ifdef F_64
if ( V_356 -> V_358 -> V_204 > 1 ) {
V_352 = V_359 ;
} else {
V_352 = F_268 ( V_267 -> V_306 ) ;
}
#else
V_352 = F_268 ( V_267 -> V_306 ) ;
#endif
if ( V_207 != NULL ) {
V_67 = F_44 ( V_207 ) ;
V_353 = F_269 ( V_267 -> V_306 ) ;
if ( V_353 == 0 ) {
V_353 = V_360 ;
}
F_67 ( L_321 , V_353 ) ;
V_355 = F_270 ( V_267 -> V_306 ) ;
V_357 = F_271 ( V_267 -> V_306 ) ;
if ( V_355 -> V_361 == NULL ) {
V_355 -> V_361 = F_45 ( L_322 , F_20 () ) ;
}
if ( V_352 != V_359 &&
V_105 == V_107 ) {
F_67 ( L_323 , V_207 ) ;
if ( strcmp ( V_207 , L_127 ) == 0 ) {
V_354 = F_272 ( V_105 , V_352 ,
V_353 , FALSE , & V_96 ) ;
} else {
V_354 = F_273 ( V_207 , V_105 , V_352 ,
V_353 , FALSE , & V_96 ) ;
}
}
else {
F_67 ( L_324 , V_105 , V_207 ) ;
if ( strcmp ( V_207 , L_127 ) == 0 ) {
V_354 = F_274 ( V_105 , V_352 ,
V_353 , FALSE , V_355 , V_356 , V_357 , & V_96 ) ;
} else {
V_354 = F_275 ( V_207 , V_105 , V_352 ,
V_353 , FALSE , V_355 , V_356 , V_357 , & V_96 ) ;
}
}
F_11 ( V_356 ) ;
V_356 = NULL ;
if ( V_354 == NULL ) {
switch ( V_96 ) {
case V_362 :
F_35 ( L_325 ) ;
break;
case V_363 :
case V_364 :
F_35 ( L_326
L_327 , F_6 ( V_105 ) ) ;
break;
case V_365 :
F_35 ( L_328
L_329 , V_67 ) ;
break;
case V_366 :
F_35 ( L_330 ,
V_67 ) ;
break;
default:
F_35 ( L_331 , V_67 ,
F_276 ( V_96 ) ) ;
break;
}
goto V_367;
}
} else {
if ( V_133 ) {
if ( ! F_189 ( V_267 ) ) {
V_96 = V_249 ;
F_190 ( V_96 ) ;
goto V_367;
}
}
F_11 ( V_356 ) ;
V_356 = NULL ;
V_354 = NULL ;
}
V_312 = F_230 () ;
V_313 = F_231 () ;
if ( V_169 ) {
T_32 * V_344 ;
F_67 ( L_332 , V_232 ? L_291 : L_292 ) ;
V_267 -> V_251 = F_277 () ;
if ( V_232 ) {
T_10 V_315 = FALSE ;
if ( V_267 -> V_116 || V_267 -> V_117 )
V_315 = TRUE ;
F_67 ( L_333 , V_315 ? L_291 : L_292 ) ;
V_316 = F_233 ( V_267 -> V_252 , V_315 , FALSE ) ;
}
F_67 ( L_334 ) ;
while ( F_235 ( V_267 -> V_306 , & V_96 , & V_310 , & V_311 ) ) {
if ( F_248 ( V_267 , V_316 , V_311 , F_238 ( V_267 -> V_306 ) ,
F_239 ( V_267 -> V_306 ) ) ) {
if ( ( -- V_350 == 0 ) || ( V_351 != 0 && V_311 >= V_351 ) ) {
F_67 ( L_335 V_368 L_336 V_368 L_337 ,
V_350 , V_311 , V_351 ) ;
V_96 = 0 ;
break;
}
}
}
if ( V_316 ) {
F_240 ( V_316 ) ;
V_316 = NULL ;
}
F_278 ( V_267 -> V_306 ) ;
F_279 () ;
V_271 = NULL ;
V_272 = NULL ;
F_280 ( & V_346 , 1500 ) ;
F_67 ( L_338 ) ;
if ( V_232 ) {
T_10 V_315 ;
if ( V_267 -> V_117 || V_135 || V_312 ||
( V_313 & V_317 ) || F_232 ( & V_267 -> V_226 ) )
V_315 = TRUE ;
else
V_315 = FALSE ;
F_67 ( L_333 , V_315 ? L_291 : L_292 ) ;
V_316 = F_233 ( V_267 -> V_252 , V_315 , V_133 && V_135 ) ;
}
for ( V_330 = 1 ; V_96 == 0 && V_330 <= V_267 -> V_332 ; V_330 ++ ) {
V_344 = F_211 ( V_267 -> V_251 , V_330 ) ;
if ( F_281 ( V_267 -> V_306 , V_344 -> V_369 , & V_345 , & V_346 , & V_96 ,
& V_310 ) ) {
F_67 ( L_339 , V_330 ) ;
if ( F_260 ( V_267 , V_316 , V_344 , & V_345 , & V_346 ,
V_313 ) ) {
if ( V_354 != NULL ) {
F_67 ( L_340 , V_330 ) ;
if ( ! F_282 ( V_354 , & V_345 , F_283 ( & V_346 ) , & V_96 , & V_310 ) ) {
F_67 ( L_341 , V_96 ) ;
switch ( V_96 ) {
case V_363 :
fprintf ( V_7 ,
L_342 ,
V_330 , V_267 -> V_323 ,
F_6 ( V_105 ) ) ;
break;
case V_370 :
fprintf ( V_7 ,
L_343 ,
V_330 , V_267 -> V_323 ,
F_6 ( V_105 ) ) ;
break;
case V_371 :
fprintf ( V_7 ,
L_344 ,
V_330 , V_267 -> V_323 ,
F_6 ( V_105 ) ) ;
break;
case V_372 :
fprintf ( V_7 ,
L_345 ,
V_330 , V_267 -> V_323 ,
F_6 ( V_105 ) ,
V_310 != NULL ? V_310 : L_346 ) ;
F_11 ( V_310 ) ;
break;
default:
F_284 ( V_207 , V_96 , FALSE ) ;
break;
}
F_285 ( V_354 , & V_96 ) ;
F_286 ( V_355 ) ;
F_287 ( V_357 ) ;
exit ( 2 ) ;
}
}
}
}
}
if ( V_316 ) {
F_240 ( V_316 ) ;
V_316 = NULL ;
}
F_288 ( & V_346 ) ;
F_67 ( L_347 ) ;
}
else {
V_330 = 0 ;
F_67 ( L_348 , V_232 ? L_291 : L_292 ) ;
if ( V_232 ) {
T_10 V_315 ;
if ( V_267 -> V_116 || V_267 -> V_117 || V_135 || V_312 ||
( V_313 & V_317 ) || F_232 ( & V_267 -> V_226 ) )
V_315 = TRUE ;
else
V_315 = FALSE ;
F_67 ( L_333 , V_315 ? L_291 : L_292 ) ;
V_316 = F_233 ( V_267 -> V_252 , V_315 , V_133 && V_135 ) ;
}
while ( F_235 ( V_267 -> V_306 , & V_96 , & V_310 , & V_311 ) ) {
V_330 ++ ;
F_67 ( L_349 , V_330 ) ;
if ( F_237 ( V_267 , V_316 , V_311 , F_238 ( V_267 -> V_306 ) ,
F_239 ( V_267 -> V_306 ) ,
V_313 ) ) {
if ( V_354 != NULL ) {
F_67 ( L_340 , V_330 ) ;
if ( ! F_282 ( V_354 , F_238 ( V_267 -> V_306 ) , F_239 ( V_267 -> V_306 ) , & V_96 , & V_310 ) ) {
F_67 ( L_341 , V_96 ) ;
switch ( V_96 ) {
case V_363 :
fprintf ( V_7 ,
L_342 ,
V_330 , V_267 -> V_323 ,
F_6 ( V_105 ) ) ;
break;
case V_370 :
fprintf ( V_7 ,
L_343 ,
V_330 , V_267 -> V_323 ,
F_6 ( V_105 ) ) ;
break;
case V_371 :
fprintf ( V_7 ,
L_344 ,
V_330 , V_267 -> V_323 ,
F_6 ( V_105 ) ) ;
break;
case V_372 :
fprintf ( V_7 ,
L_345 ,
V_330 , V_267 -> V_323 ,
F_6 ( V_105 ) ,
V_310 != NULL ? V_310 : L_346 ) ;
F_11 ( V_310 ) ;
break;
default:
F_284 ( V_207 , V_96 , FALSE ) ;
break;
}
F_285 ( V_354 , & V_96 ) ;
F_286 ( V_355 ) ;
F_287 ( V_357 ) ;
exit ( 2 ) ;
}
}
}
if ( ( -- V_350 == 0 ) || ( V_351 != 0 && V_311 >= V_351 ) ) {
F_67 ( L_335 V_368 L_336 V_368 L_337 ,
V_350 , V_311 , V_351 ) ;
V_96 = 0 ;
break;
}
}
if ( V_316 ) {
F_240 ( V_316 ) ;
V_316 = NULL ;
}
}
F_289 ( & V_345 ) ;
if ( V_96 != 0 ) {
F_67 ( L_350 , V_96 ) ;
#ifndef V_71
if ( V_133 ) {
T_50 V_373 , V_374 ;
if ( F_290 ( 1 , & V_373 ) == 0 && F_290 ( 2 , & V_374 ) == 0 ) {
if ( V_373 . V_375 == V_374 . V_375 &&
V_373 . V_376 == V_374 . V_376 ) {
fflush ( stdout ) ;
fprintf ( V_7 , L_6 ) ;
}
}
}
#endif
switch ( V_96 ) {
case V_377 :
F_35 ( L_351 ,
V_267 -> V_323 ,
V_310 != NULL ? V_310 : L_346 ) ;
F_11 ( V_310 ) ;
break;
case V_378 :
F_35 ( L_352 ,
V_267 -> V_323 ) ;
break;
case V_379 :
F_35 ( L_353 ,
V_267 -> V_323 ,
V_310 != NULL ? V_310 : L_346 ) ;
F_11 ( V_310 ) ;
break;
case V_380 :
F_35 ( L_354
L_355 , V_267 -> V_323 ,
V_310 != NULL ? V_310 : L_346 ) ;
F_11 ( V_310 ) ;
break;
default:
F_35 ( L_356 ,
V_267 -> V_323 , F_276 ( V_96 ) ) ;
break;
}
if ( V_207 != NULL ) {
if ( ! F_285 ( V_354 , & V_96 ) )
F_284 ( V_207 , V_96 , TRUE ) ;
}
} else {
if ( V_207 != NULL ) {
if ( V_354 && V_108 ) {
if ( ! F_291 ( V_354 , F_292 () ) ) {
F_35 ( L_357 ,
F_6 ( V_105 ) ) ;
}
}
if ( ! F_285 ( V_354 , & V_96 ) )
F_284 ( V_207 , V_96 , TRUE ) ;
} else {
if ( V_133 ) {
if ( ! F_192 () ) {
V_96 = V_249 ;
F_190 ( V_96 ) ;
}
}
}
}
V_367:
F_228 ( V_267 -> V_306 ) ;
V_267 -> V_306 = NULL ;
F_11 ( V_67 ) ;
F_286 ( V_355 ) ;
F_287 ( V_357 ) ;
return V_96 ;
}
static T_10
F_237 ( T_31 * V_267 , T_39 * V_316 , T_38 V_325 , struct V_326 * V_327 ,
const T_43 * V_328 , T_21 V_313 )
{
T_32 V_344 ;
T_45 * V_226 ;
T_10 V_331 ;
V_267 -> V_332 ++ ;
V_331 = TRUE ;
F_249 ( & V_344 , V_267 -> V_332 , V_327 , V_325 , V_333 ) ;
if ( V_316 ) {
if ( V_133 && ( V_175 . V_334 || V_175 . V_335 ||
V_175 . V_336 || V_175 . V_337 ) )
F_250 () ;
if ( V_267 -> V_117 )
F_251 ( V_316 , V_267 -> V_117 ) ;
F_261 ( V_316 , & V_267 -> V_226 ) ;
if ( ( V_313 & V_347 ) || ( V_133 && V_134 ) || F_262 ( V_166 ) )
V_226 = & V_267 -> V_226 ;
else
V_226 = NULL ;
F_252 ( & V_344 , & V_267 -> V_338 ,
& V_268 , V_271 ) ;
if ( V_268 == & V_344 ) {
V_339 = V_344 ;
V_268 = & V_339 ;
}
F_263 ( V_316 , V_267 -> V_340 , V_327 , F_254 ( & V_344 , V_328 ) , & V_344 , V_226 ) ;
if ( V_267 -> V_117 )
V_331 = F_255 ( V_267 -> V_117 , V_316 ) ;
}
if ( V_331 ) {
F_256 ( & V_344 , & V_333 ) ;
if ( V_133 ) {
F_265 ( V_267 , V_316 ) ;
if ( V_174 )
fflush ( stdout ) ;
if ( ferror ( stdout ) ) {
F_190 ( V_249 ) ;
exit ( 2 ) ;
}
}
V_381 = V_344 ;
V_271 = & V_381 ;
}
V_382 = V_344 ;
V_272 = & V_382 ;
if ( V_316 ) {
F_259 ( V_316 ) ;
F_258 ( & V_344 ) ;
}
return V_331 ;
}
static T_10
F_189 ( T_31 * V_267 )
{
switch ( V_191 ) {
case V_192 :
return F_293 ( V_231 , V_267 -> V_323 , F_20 () ) ;
case V_194 :
if ( V_135 )
F_294 ( stdout , V_267 -> V_323 ) ;
else
F_295 ( & V_267 -> V_226 , stdout ) ;
return ! ferror ( stdout ) ;
case V_195 :
F_296 ( V_166 , stdout ) ;
return ! ferror ( stdout ) ;
default:
F_38 () ;
return FALSE ;
}
}
static char *
F_297 ( T_51 V_204 )
{
static char * V_383 = NULL ;
static T_51 V_384 = 256 ;
T_51 V_385 ;
for ( V_385 = V_384 ; V_204 > V_385 ;
V_385 *= 2 )
;
if ( V_383 == NULL ) {
V_384 = V_385 ;
V_383 = ( char * ) F_206 ( V_384 + 1 ) ;
} else {
if ( V_385 > V_384 ) {
V_384 = V_385 ;
V_383 = ( char * ) F_298 ( V_383 , V_384 + 1 ) ;
}
}
return V_383 ;
}
static inline void
F_299 ( char * V_386 , const char * V_70 , T_51 V_387 )
{
memcpy ( V_386 , V_70 , V_387 ) ;
V_386 [ V_387 ] = '\0' ;
}
static inline void
F_300 ( char * V_386 , const char * V_70 , T_51 V_387 , T_51 V_388 )
{
T_51 V_9 ;
for ( V_9 = V_387 ; V_9 < V_388 ; V_9 ++ )
* V_386 ++ = ' ' ;
F_299 ( V_386 , V_70 , V_387 ) ;
}
static inline void
F_301 ( char * V_386 , const char * V_70 , T_51 V_387 , T_51 V_388 )
{
T_51 V_9 ;
memcpy ( V_386 , V_70 , V_387 ) ;
for ( V_9 = V_387 ; V_9 < V_388 ; V_9 ++ )
V_386 [ V_9 ] = ' ' ;
V_386 [ V_388 ] = '\0' ;
}
static T_10
F_302 ( T_31 * V_267 )
{
char * V_383 ;
int V_9 ;
T_51 V_389 ;
T_51 V_390 ;
T_51 V_391 ;
T_52 * V_392 ;
V_383 = F_297 ( 256 ) ;
V_389 = 0 ;
* V_383 = '\0' ;
for ( V_9 = 0 ; V_9 < V_267 -> V_226 . V_227 ; V_9 ++ ) {
V_392 = & V_267 -> V_226 . V_393 [ V_9 ] ;
if ( ! F_303 ( V_9 ) )
continue;
switch ( V_392 -> V_394 ) {
case V_395 :
V_390 = V_391 = strlen ( V_392 -> V_396 ) ;
if ( V_390 < 3 )
V_390 = 3 ;
V_383 = F_297 ( V_389 + V_390 ) ;
F_300 ( V_383 + V_389 , V_392 -> V_396 , V_391 , V_390 ) ;
break;
case V_397 :
case V_398 :
case V_399 :
case V_400 :
case V_401 :
case V_402 :
case V_403 :
case V_404 :
V_390 = V_391 = strlen ( V_392 -> V_396 ) ;
if ( V_390 < 10 )
V_390 = 10 ;
V_383 = F_297 ( V_389 + V_390 ) ;
F_300 ( V_383 + V_389 , V_392 -> V_396 , V_391 , V_390 ) ;
break;
case V_405 :
case V_406 :
case V_407 :
case V_408 :
case V_409 :
case V_410 :
case V_411 :
case V_412 :
case V_413 :
V_390 = V_391 = strlen ( V_392 -> V_396 ) ;
if ( V_390 < 12 )
V_390 = 12 ;
V_383 = F_297 ( V_389 + V_390 ) ;
F_300 ( V_383 + V_389 , V_392 -> V_396 , V_391 , V_390 ) ;
break;
case V_414 :
case V_415 :
case V_416 :
case V_417 :
case V_418 :
case V_419 :
case V_420 :
case V_421 :
case V_422 :
V_390 = V_391 = strlen ( V_392 -> V_396 ) ;
if ( V_390 < 12 )
V_390 = 12 ;
V_383 = F_297 ( V_389 + V_390 ) ;
F_301 ( V_383 + V_389 , V_392 -> V_396 , V_391 , V_390 ) ;
break;
default:
V_390 = strlen ( V_392 -> V_396 ) ;
V_383 = F_297 ( V_389 + V_390 ) ;
F_299 ( V_383 + V_389 , V_392 -> V_396 , V_390 ) ;
break;
}
V_389 += V_390 ;
if ( V_9 != V_267 -> V_226 . V_227 - 1 ) {
V_383 = F_297 ( V_389 + 4 ) ;
switch ( V_392 -> V_394 ) {
case V_405 :
case V_406 :
case V_407 :
switch ( V_267 -> V_226 . V_393 [ V_9 + 1 ] . V_394 ) {
case V_414 :
case V_415 :
case V_416 :
F_299 ( V_383 + V_389 , L_358 , 4 ) ;
V_389 += 4 ;
break;
default:
F_299 ( V_383 + V_389 , L_359 , 1 ) ;
V_389 += 1 ;
break;
}
break;
case V_408 :
case V_409 :
case V_410 :
switch ( V_267 -> V_226 . V_393 [ V_9 + 1 ] . V_394 ) {
case V_417 :
case V_418 :
case V_419 :
F_299 ( V_383 + V_389 , L_358 , 4 ) ;
V_389 += 4 ;
break;
default:
F_299 ( V_383 + V_389 , L_359 , 1 ) ;
V_389 += 1 ;
break;
}
break;
case V_411 :
case V_412 :
case V_413 :
switch ( V_267 -> V_226 . V_393 [ V_9 + 1 ] . V_394 ) {
case V_420 :
case V_421 :
case V_422 :
F_299 ( V_383 + V_389 , L_358 , 4 ) ;
V_389 += 4 ;
break;
default:
F_299 ( V_383 + V_389 , L_359 , 1 ) ;
V_389 += 1 ;
break;
}
break;
case V_414 :
case V_415 :
case V_416 :
switch ( V_267 -> V_226 . V_393 [ V_9 + 1 ] . V_394 ) {
case V_405 :
case V_406 :
case V_407 :
F_299 ( V_383 + V_389 , L_360 , 4 ) ;
V_389 += 4 ;
break;
default:
F_299 ( V_383 + V_389 , L_359 , 1 ) ;
V_389 += 1 ;
break;
}
break;
case V_417 :
case V_418 :
case V_419 :
switch ( V_267 -> V_226 . V_393 [ V_9 + 1 ] . V_394 ) {
case V_408 :
case V_409 :
case V_410 :
F_299 ( V_383 + V_389 , L_360 , 4 ) ;
V_389 += 4 ;
break;
default:
F_299 ( V_383 + V_389 , L_359 , 1 ) ;
V_389 += 1 ;
break;
}
break;
case V_420 :
case V_421 :
case V_422 :
switch ( V_267 -> V_226 . V_393 [ V_9 + 1 ] . V_394 ) {
case V_411 :
case V_412 :
case V_413 :
F_299 ( V_383 + V_389 , L_360 , 4 ) ;
V_389 += 4 ;
break;
default:
F_299 ( V_383 + V_389 , L_359 , 1 ) ;
V_389 += 1 ;
break;
}
break;
default:
F_299 ( V_383 + V_389 , L_359 , 1 ) ;
V_389 += 1 ;
break;
}
}
}
return F_304 ( V_231 , 0 , V_383 ) ;
}
static T_10
F_265 ( T_31 * V_267 , T_39 * V_316 )
{
T_53 V_423 ;
if ( V_134 || F_262 ( V_166 ) ) {
F_305 ( V_316 , FALSE , TRUE ) ;
if ( V_134 ) {
switch ( V_191 ) {
case V_192 :
if ( ! F_302 ( V_267 ) )
return FALSE ;
break;
case V_194 :
F_306 ( V_316 , stdout ) ;
return ! ferror ( stdout ) ;
case V_195 :
F_38 () ;
break;
}
}
}
if ( V_135 ) {
switch ( V_191 ) {
case V_192 :
V_423 . V_136 = V_136 ;
V_423 . V_424 = V_135 ? V_425 : V_426 ;
if ( ! F_307 ( & V_423 , V_316 , V_209 , V_231 ) )
return FALSE ;
if ( ! V_136 ) {
if ( ! F_304 ( V_231 , 0 , V_181 ) )
return FALSE ;
}
break;
case V_194 :
F_308 ( V_316 , stdout ) ;
printf ( L_6 ) ;
return ! ferror ( stdout ) ;
case V_195 :
F_309 ( V_166 , V_316 , & V_267 -> V_226 , stdout ) ;
printf ( L_6 ) ;
return ! ferror ( stdout ) ;
}
}
if ( V_136 ) {
if ( V_134 || V_135 ) {
if ( ! F_304 ( V_231 , 0 , L_140 ) )
return FALSE ;
}
if ( ! F_310 ( V_231 , V_316 ) )
return FALSE ;
if ( ! F_304 ( V_231 , 0 , V_181 ) )
return FALSE ;
}
return TRUE ;
}
static T_10
F_192 ( void )
{
switch ( V_191 ) {
case V_192 :
return F_311 ( V_231 ) ;
case V_194 :
if ( V_135 )
F_312 ( stdout ) ;
else
F_313 ( stdout ) ;
return ! ferror ( stdout ) ;
case V_195 :
F_314 ( V_166 , stdout ) ;
return ! ferror ( stdout ) ;
default:
F_38 () ;
return FALSE ;
}
}
T_54
F_179 ( T_31 * V_267 , const char * V_66 , unsigned int type , T_10 V_303 , int * V_96 )
{
T_55 * V_306 ;
T_7 * V_310 ;
char V_118 [ 2048 + 1 ] ;
V_306 = F_315 ( V_66 , type , V_96 , & V_310 , V_169 ) ;
if ( V_306 == NULL )
goto V_427;
F_196 ( V_267 -> V_252 ) ;
V_267 -> V_252 = F_212 ( V_267 ) ;
V_267 -> V_306 = V_306 ;
V_267 -> V_428 = 0 ;
V_267 -> V_323 = F_34 ( V_66 ) ;
V_267 -> V_303 = V_303 ;
V_267 -> V_429 = FALSE ;
V_267 -> V_340 = F_316 ( V_267 -> V_306 ) ;
V_267 -> V_307 = type ;
V_267 -> V_332 = 0 ;
V_267 -> V_430 = FALSE ;
V_267 -> V_431 = 0 ;
V_267 -> V_432 = F_269 ( V_267 -> V_306 ) ;
if ( V_267 -> V_432 == 0 ) {
V_267 -> V_433 = FALSE ;
V_267 -> V_432 = V_360 ;
} else
V_267 -> V_433 = TRUE ;
F_317 ( & V_267 -> V_338 ) ;
V_268 = NULL ;
V_271 = NULL ;
V_272 = NULL ;
V_267 -> V_293 = V_434 ;
F_318 ( V_267 -> V_306 , V_435 ) ;
F_319 ( V_267 -> V_306 , ( V_436 ) V_437 ) ;
return V_233 ;
V_427:
F_320 ( V_118 , sizeof V_118 ,
F_321 ( * V_96 , V_310 , FALSE , V_267 -> V_340 ) , V_66 ) ;
F_35 ( L_144 , V_118 ) ;
return V_308 ;
}
static void
F_284 ( const char * V_66 , int V_96 , T_10 V_438 )
{
char * V_67 ;
V_67 = F_44 ( V_66 ) ;
switch ( V_96 ) {
case V_439 :
F_35 ( L_361
L_362 ,
V_67 ) ;
break;
#ifdef F_322
case F_322 :
F_35 ( L_363
L_364 ,
V_67 ) ;
break;
#endif
case V_440 :
F_35 ( L_365 ,
V_67 ) ;
break;
case V_366 :
F_35 ( L_366 ,
V_67 ) ;
break;
default:
if ( V_438 ) {
F_35 ( L_367 , V_67 ,
F_276 ( V_96 ) ) ;
} else {
F_35 ( L_368 ,
V_67 , F_276 ( V_96 ) ) ;
}
break;
}
F_11 ( V_67 ) ;
}
static void
F_190 ( int V_96 )
{
switch ( V_96 ) {
case V_439 :
F_35 ( L_369
L_362 ) ;
break;
#ifdef F_322
case F_322 :
F_35 ( L_370
L_364 ) ;
break;
#endif
default:
F_35 ( L_371 ,
F_124 ( V_96 ) ) ;
break;
}
}
static const char *
F_321 ( int V_96 , T_7 * V_310 , T_10 V_441 ,
int V_442 )
{
const char * V_443 ;
static char V_444 [ 1024 + 1 ] ;
if ( V_96 < 0 ) {
switch ( V_96 ) {
case V_445 :
V_443 = L_372 ;
break;
case V_446 :
V_443 = L_373 ;
break;
case V_447 :
V_443 = L_374 ;
break;
case V_377 :
F_320 ( V_444 , sizeof( V_444 ) ,
L_375
L_355 ,
V_310 != NULL ? V_310 : L_346 ) ;
F_11 ( V_310 ) ;
V_443 = V_444 ;
break;
case V_448 :
F_320 ( V_444 , sizeof( V_444 ) ,
L_376
L_377 , F_6 ( V_442 ) ) ;
V_443 = V_444 ;
break;
case V_362 :
V_443 = L_378 ;
break;
case V_363 :
F_320 ( V_444 , sizeof( V_444 ) ,
L_379 ,
F_6 ( V_442 ) ) ;
V_443 = V_444 ;
break;
case V_364 :
if ( V_441 ) {
F_320 ( V_444 , sizeof( V_444 ) ,
L_379 ,
F_6 ( V_442 ) ) ;
V_443 = V_444 ;
} else
V_443 = L_380 ;
break;
case V_379 :
F_320 ( V_444 , sizeof( V_444 ) ,
L_381
L_355 ,
V_310 != NULL ? V_310 : L_346 ) ;
F_11 ( V_310 ) ;
V_443 = V_444 ;
break;
case V_365 :
if ( V_441 )
V_443 = L_382 ;
else
V_443 = L_383 ;
break;
case V_378 :
V_443 = L_384
L_385 ;
break;
case V_366 :
V_443 = L_386 ;
break;
case V_449 :
V_443 = L_387 ;
break;
case V_380 :
F_320 ( V_444 , sizeof( V_444 ) ,
L_388
L_355 ,
V_310 != NULL ? V_310 : L_346 ) ;
F_11 ( V_310 ) ;
V_443 = V_444 ;
break;
default:
F_320 ( V_444 , sizeof( V_444 ) ,
L_389 ,
V_441 ? L_390 : L_391 ,
F_276 ( V_96 ) ) ;
V_443 = V_444 ;
break;
}
} else
V_443 = F_323 ( V_96 , V_441 ) ;
return V_443 ;
}
static void
V_148 ( const char * V_323 , int V_96 , T_10 V_441 )
{
fprintf ( V_7 , L_392 ) ;
fprintf ( V_7 , F_323 ( V_96 , V_441 ) , V_323 ) ;
fprintf ( V_7 , L_6 ) ;
}
static void
V_128 ( const char * V_450 , T_56 V_451 )
{
fprintf ( V_7 , L_392 ) ;
vfprintf ( V_7 , V_450 , V_451 ) ;
fprintf ( V_7 , L_6 ) ;
}
static void
V_149 ( const char * V_323 , int V_96 )
{
F_35 ( L_393 ,
V_323 , F_124 ( V_96 ) ) ;
}
static void
V_150 ( const char * V_323 , int V_96 )
{
F_35 ( L_394 ,
V_323 , F_124 ( V_96 ) ) ;
}
static void
V_129 ( const char * V_450 , T_56 V_451 )
{
vfprintf ( V_7 , V_450 , V_451 ) ;
fprintf ( V_7 , L_6 ) ;
}
