static void F_1 ( const char * V_1 )
{
F_2 () ;
F_3 ( L_1 ) ;
abort () ;
}
static void F_4 ( T_1 * V_2 , const char * V_3 , T_1 * V_4 )
{
F_5 ( V_2 , V_3 , V_4 ) ;
F_6 ( V_4 ) ;
}
static void F_7 ( enum V_5 V_6 ,
const char * V_7 ,
const char * V_8 ,
const char * V_9 ,
const char * V_10 )
{
const char * V_1 = L_2 ;
T_1 * V_11 , * V_12 , * V_13 ;
unsigned long long V_14 ;
unsigned V_15 = 0 ;
if ( V_6 == V_16 )
V_1 = L_3 ;
V_12 = F_8 ( 4 ) ;
if ( ! V_12 )
F_3 ( L_4 ) ;
V_14 = F_9 ( V_9 ) ;
F_10 ( V_12 , V_15 ++ , F_11 ( V_7 ) ) ;
F_10 ( V_12 , V_15 ++ , F_11 ( V_8 ) ) ;
F_10 ( V_12 , V_15 ++ , F_12 ( V_14 ) ) ;
F_10 ( V_12 , V_15 ++ , F_11 ( V_10 ) ) ;
V_11 = F_13 ( V_17 , V_1 ) ;
if ( V_11 && F_14 ( V_11 ) ) {
V_13 = F_15 ( V_11 , V_12 ) ;
if ( V_13 == NULL )
F_1 ( V_1 ) ;
F_6 ( V_13 ) ;
}
F_6 ( V_12 ) ;
}
static void F_16 ( enum V_5 V_6 ,
struct V_18 * V_19 ,
const char * V_7 ,
const char * V_8 )
{
F_7 ( V_6 , V_7 , V_8 , V_19 -> V_14 ,
V_19 -> V_20 ) ;
if ( V_19 -> V_21 )
F_16 ( V_6 , V_19 -> V_21 , V_7 , V_8 ) ;
}
static void F_17 ( enum V_5 V_6 ,
const char * V_7 ,
const char * V_8 ,
const char * V_22 )
{
const char * V_1 = L_5 ;
T_1 * V_11 , * V_12 , * V_13 ;
unsigned V_15 = 0 ;
if ( V_6 == V_16 )
V_1 = L_6 ;
if ( V_6 == V_23 )
V_12 = F_8 ( 3 ) ;
else
V_12 = F_8 ( 2 ) ;
if ( ! V_12 )
F_3 ( L_4 ) ;
F_10 ( V_12 , V_15 ++ , F_11 ( V_7 ) ) ;
F_10 ( V_12 , V_15 ++ , F_11 ( V_8 ) ) ;
if ( V_6 == V_23 )
F_10 ( V_12 , V_15 ++ , F_11 ( V_22 ) ) ;
V_11 = F_13 ( V_17 , V_1 ) ;
if ( V_11 && F_14 ( V_11 ) ) {
V_13 = F_15 ( V_11 , V_12 ) ;
if ( V_13 == NULL )
F_1 ( V_1 ) ;
F_6 ( V_13 ) ;
}
F_6 ( V_12 ) ;
}
static void F_18 ( struct V_24 * V_25 ,
const char * V_7 ,
struct V_26 * args )
{
switch ( args -> type ) {
case V_27 :
break;
case V_28 :
F_7 ( V_23 , V_7 , V_29 , L_7 ,
args -> V_30 . V_30 ) ;
V_31 = 0 ;
break;
case V_32 :
free ( V_29 ) ;
V_29 = F_19 ( args -> V_19 . V_33 ) ;
break;
case V_23 :
F_18 ( V_25 , V_7 , args -> V_34 . V_19 ) ;
F_17 ( V_23 , V_7 , V_29 ,
args -> V_34 . V_22 ) ;
F_16 ( V_23 , args -> V_34 . V_34 , V_7 ,
V_29 ) ;
break;
case V_16 :
F_18 ( V_25 , V_7 , args -> V_35 . V_19 ) ;
F_17 ( V_16 , V_7 , V_29 , NULL ) ;
F_16 ( V_16 , args -> V_35 . V_36 , V_7 ,
V_29 ) ;
break;
case V_37 :
F_18 ( V_25 , V_7 , args -> V_38 . V_19 ) ;
F_18 ( V_25 , V_7 , args -> V_38 . V_39 ) ;
break;
case V_40 :
break;
case V_41 :
F_18 ( V_25 , V_7 , args -> V_42 . V_43 ) ;
break;
case V_44 :
if ( strcmp ( args -> V_45 . V_45 , L_8 ) == 0 )
V_31 = 1 ;
F_18 ( V_25 , V_7 , args -> V_45 . V_46 ) ;
F_18 ( V_25 , V_7 , args -> V_45 . V_47 ) ;
break;
default:
case V_48 :
case V_49 :
case V_50 :
case V_51 :
return;
}
if ( args -> V_21 )
F_18 ( V_25 , V_7 , args -> V_21 ) ;
}
static inline struct V_24 * F_20 ( struct V_52 * V_53 )
{
static char V_7 [ 256 ] ;
struct V_24 * V_25 ;
int type = V_53 -> V_54 . V_55 ;
if ( V_56 [ type ] )
return V_56 [ type ] ;
V_56 [ type ] = V_25 = V_53 -> V_57 ;
if ( ! V_25 )
return NULL ;
sprintf ( V_7 , L_9 , V_25 -> system , V_25 -> V_33 ) ;
F_18 ( V_25 , V_7 , V_25 -> V_58 . args ) ;
return V_25 ;
}
static T_1 * F_21 ( struct V_24 * V_25 ,
struct V_59 * V_19 , void * V_60 )
{
bool V_61 = V_19 -> V_34 & V_62 ;
T_1 * V_63 , * V_64 = NULL ;
unsigned long long V_4 ;
unsigned int V_65 , V_66 , V_67 ;
if ( V_61 ) {
V_64 = F_22 ( V_19 -> V_68 ) ;
V_65 = V_19 -> V_39 / V_19 -> V_68 ;
V_66 = V_19 -> V_68 ;
} else {
V_65 = V_19 -> V_39 ;
V_66 = 1 ;
}
for ( V_67 = 0 ; V_67 < V_66 ; V_67 ++ ) {
V_4 = F_23 ( V_25 , V_60 + V_19 -> V_69 + V_67 * V_65 ,
V_65 ) ;
if ( V_19 -> V_34 & V_70 ) {
if ( ( long long ) V_4 >= V_71 &&
( long long ) V_4 <= V_72 )
V_63 = F_12 ( V_4 ) ;
else
V_63 = F_24 ( V_4 ) ;
} else {
if ( V_4 <= V_72 )
V_63 = F_12 ( V_4 ) ;
else
V_63 = F_25 ( V_4 ) ;
}
if ( V_61 )
F_26 ( V_64 , V_67 , V_63 ) ;
}
if ( V_61 )
V_63 = V_64 ;
return V_63 ;
}
static T_1 * F_27 ( struct V_73 * V_74 ,
struct V_52 * V_53 ,
struct V_75 * V_76 )
{
T_1 * V_77 ;
V_77 = F_22 ( 0 ) ;
if ( ! V_77 )
F_3 ( L_10 ) ;
if ( ! V_78 . V_79 || ! V_74 -> V_80 )
goto exit;
if ( F_28 ( V_76 -> V_81 , V_53 , V_76 -> V_82 ,
V_74 , NULL , NULL ,
V_83 ) != 0 ) {
F_29 ( L_11 ) ;
goto exit;
}
F_30 ( & V_84 ) ;
while ( 1 ) {
T_1 * V_85 ;
struct V_86 * V_87 ;
V_87 = F_31 ( & V_84 ) ;
if ( ! V_87 )
break;
V_85 = F_32 () ;
if ( ! V_85 )
F_3 ( L_12 ) ;
F_4 ( V_85 , L_13 ,
F_25 ( V_87 -> V_88 ) ) ;
if ( V_87 -> V_89 ) {
T_1 * V_90 = F_32 () ;
if ( ! V_90 )
F_3 ( L_12 ) ;
F_4 ( V_90 , L_14 ,
F_25 ( V_87 -> V_89 -> V_91 ) ) ;
F_4 ( V_90 , L_15 ,
F_25 ( V_87 -> V_89 -> V_92 ) ) ;
F_4 ( V_90 , L_16 ,
F_12 ( V_87 -> V_89 -> V_93 ) ) ;
F_4 ( V_90 , L_17 ,
F_33 ( V_87 -> V_89 -> V_33 ,
V_87 -> V_89 -> V_94 ) ) ;
F_4 ( V_85 , L_18 , V_90 ) ;
}
if ( V_87 -> V_95 ) {
struct V_95 * V_95 = V_87 -> V_95 ;
const char * V_96 = L_19 ;
if ( V_95 && V_95 -> V_97 && ( V_95 -> V_97 -> V_33 || V_95 -> V_97 -> V_98 ) ) {
if ( V_78 . V_99 && V_95 -> V_97 -> V_98 )
V_96 = V_95 -> V_97 -> V_98 ;
else if ( V_95 -> V_97 -> V_33 )
V_96 = V_95 -> V_97 -> V_33 ;
}
F_4 ( V_85 , L_20 ,
F_11 ( V_96 ) ) ;
}
F_34 ( & V_84 ) ;
F_35 ( V_77 , V_85 ) ;
F_6 ( V_85 ) ;
}
exit:
return V_77 ;
}
static void F_36 ( struct V_73 * V_74 ,
struct V_52 * V_53 ,
struct V_82 * V_82 ,
struct V_75 * V_76 )
{
T_1 * V_11 , * V_13 , * V_100 , * V_12 , * V_63 , * V_80 ;
T_1 * V_2 = NULL ;
static char V_1 [ 256 ] ;
struct V_59 * V_19 ;
unsigned long V_101 , V_102 ;
struct V_24 * V_25 ;
unsigned V_15 = 0 ;
int V_103 ;
int V_104 = V_74 -> V_104 ;
void * V_60 = V_74 -> V_105 ;
unsigned long long V_106 = V_74 -> time ;
const char * V_107 = F_37 ( V_82 ) ;
V_12 = F_8 ( V_108 ) ;
if ( ! V_12 )
F_3 ( L_4 ) ;
V_25 = F_20 ( V_53 ) ;
if ( ! V_25 )
F_38 ( L_21 , ( int ) V_53 -> V_54 . V_55 ) ;
V_103 = F_39 ( V_25 , L_22 , V_60 ) ;
sprintf ( V_1 , L_9 , V_25 -> system , V_25 -> V_33 ) ;
V_11 = F_13 ( V_17 , V_1 ) ;
if ( V_11 && ! F_14 ( V_11 ) )
V_11 = NULL ;
if ( ! V_11 ) {
V_2 = F_32 () ;
if ( ! V_2 )
F_3 ( L_23 ) ;
}
V_101 = V_106 / V_109 ;
V_102 = V_106 - V_101 * V_109 ;
V_110 -> V_111 = V_60 ;
V_110 -> V_112 = V_53 -> V_57 -> V_112 ;
V_100 = F_40 ( V_110 , NULL ) ;
F_10 ( V_12 , V_15 ++ , F_11 ( V_1 ) ) ;
F_10 ( V_12 , V_15 ++ , V_100 ) ;
V_80 = F_27 ( V_74 , V_53 , V_76 ) ;
if ( V_11 ) {
F_10 ( V_12 , V_15 ++ , F_12 ( V_104 ) ) ;
F_10 ( V_12 , V_15 ++ , F_12 ( V_101 ) ) ;
F_10 ( V_12 , V_15 ++ , F_12 ( V_102 ) ) ;
F_10 ( V_12 , V_15 ++ , F_12 ( V_103 ) ) ;
F_10 ( V_12 , V_15 ++ , F_11 ( V_107 ) ) ;
F_10 ( V_12 , V_15 ++ , V_80 ) ;
} else {
F_4 ( V_2 , L_24 , F_12 ( V_104 ) ) ;
F_4 ( V_2 , L_25 , F_12 ( V_101 ) ) ;
F_4 ( V_2 , L_26 , F_12 ( V_102 ) ) ;
F_4 ( V_2 , L_22 , F_12 ( V_103 ) ) ;
F_4 ( V_2 , L_27 , F_11 ( V_107 ) ) ;
F_4 ( V_2 , L_28 , V_80 ) ;
}
for ( V_19 = V_25 -> V_113 . V_114 ; V_19 ; V_19 = V_19 -> V_21 ) {
if ( V_19 -> V_34 & V_115 ) {
int V_69 ;
if ( V_19 -> V_34 & V_116 ) {
V_69 = * ( int * ) ( V_60 + V_19 -> V_69 ) ;
V_69 &= 0xffff ;
} else
V_69 = V_19 -> V_69 ;
V_63 = F_11 ( ( char * ) V_60 + V_69 ) ;
} else {
V_63 = F_21 ( V_25 , V_19 , V_60 ) ;
}
if ( V_11 )
F_10 ( V_12 , V_15 ++ , V_63 ) ;
else
F_4 ( V_2 , V_19 -> V_33 , V_63 ) ;
}
if ( ! V_11 )
F_10 ( V_12 , V_15 ++ , V_2 ) ;
if ( F_41 ( & V_12 , V_15 ) == - 1 )
F_3 ( L_29 ) ;
if ( V_11 ) {
V_13 = F_15 ( V_11 , V_12 ) ;
if ( V_13 == NULL )
F_1 ( V_1 ) ;
F_6 ( V_13 ) ;
} else {
V_11 = F_13 ( V_17 , L_30 ) ;
if ( V_11 && F_14 ( V_11 ) ) {
V_13 = F_15 ( V_11 , V_12 ) ;
if ( V_13 == NULL )
F_1 ( L_30 ) ;
F_6 ( V_13 ) ;
}
F_6 ( V_2 ) ;
}
F_6 ( V_12 ) ;
}
static void F_42 ( struct V_73 * V_74 ,
struct V_52 * V_53 ,
struct V_82 * V_82 ,
struct V_75 * V_76 )
{
T_1 * V_11 , * V_13 , * V_12 , * V_2 , * V_80 , * V_117 ;
static char V_1 [ 64 ] ;
unsigned V_15 = 0 ;
V_12 = F_8 ( V_108 ) ;
if ( ! V_12 )
F_3 ( L_4 ) ;
V_2 = F_32 () ;
if ( ! V_2 )
F_3 ( L_12 ) ;
V_117 = F_32 () ;
if ( ! V_117 )
F_3 ( L_12 ) ;
snprintf ( V_1 , sizeof( V_1 ) , L_31 , L_32 ) ;
V_11 = F_13 ( V_17 , V_1 ) ;
if ( ! V_11 || ! F_14 ( V_11 ) )
goto exit;
F_4 ( V_2 , L_33 , F_11 ( F_43 ( V_53 ) ) ) ;
F_4 ( V_2 , L_34 , F_33 (
( const char * ) & V_53 -> V_54 , sizeof( V_53 -> V_54 ) ) ) ;
F_4 ( V_117 , L_35 ,
F_12 ( V_74 -> V_103 ) ) ;
F_4 ( V_117 , L_36 ,
F_12 ( V_74 -> V_118 ) ) ;
F_4 ( V_117 , L_37 ,
F_12 ( V_74 -> V_104 ) ) ;
F_4 ( V_117 , L_13 ,
F_25 ( V_74 -> V_88 ) ) ;
F_4 ( V_117 , L_38 ,
F_25 ( V_74 -> time ) ) ;
F_4 ( V_117 , L_39 ,
F_25 ( V_74 -> V_119 ) ) ;
F_4 ( V_2 , L_40 , V_117 ) ;
F_4 ( V_2 , L_41 , F_33 (
( const char * ) V_74 -> V_105 , V_74 -> V_120 ) ) ;
F_4 ( V_2 , L_42 ,
F_11 ( F_37 ( V_82 ) ) ) ;
if ( V_76 -> V_95 ) {
F_4 ( V_2 , L_20 ,
F_11 ( V_76 -> V_95 -> V_97 -> V_33 ) ) ;
}
if ( V_76 -> V_89 ) {
F_4 ( V_2 , L_43 ,
F_11 ( V_76 -> V_89 -> V_33 ) ) ;
}
V_80 = F_27 ( V_74 , V_53 , V_76 ) ;
F_4 ( V_2 , L_44 , V_80 ) ;
F_10 ( V_12 , V_15 ++ , V_2 ) ;
if ( F_41 ( & V_12 , V_15 ) == - 1 )
F_3 ( L_29 ) ;
V_13 = F_15 ( V_11 , V_12 ) ;
if ( V_13 == NULL )
F_1 ( V_1 ) ;
F_6 ( V_13 ) ;
exit:
F_6 ( V_2 ) ;
F_6 ( V_12 ) ;
}
static void F_44 ( union V_121 * V_25 V_122 ,
struct V_73 * V_74 ,
struct V_52 * V_53 ,
struct V_82 * V_82 ,
struct V_75 * V_76 )
{
switch ( V_53 -> V_54 . type ) {
case V_123 :
F_36 ( V_74 , V_53 , V_82 , V_76 ) ;
break;
default:
F_42 ( V_74 , V_53 , V_82 , V_76 ) ;
}
}
static int F_45 ( void )
{
T_1 * V_11 , * V_13 ;
int V_124 = 0 ;
V_125 = F_46 ( L_45 ) ;
if ( V_125 == NULL )
return - 1 ;
F_47 ( V_125 ) ;
V_17 = F_48 ( V_125 ) ;
if ( V_17 == NULL ) {
V_124 = - 1 ;
goto error;
}
F_47 ( V_17 ) ;
V_11 = F_13 ( V_17 , L_46 ) ;
if ( V_11 == NULL || ! F_14 ( V_11 ) )
goto V_126;
V_13 = F_15 ( V_11 , NULL ) ;
if ( V_13 == NULL )
F_1 ( L_46 ) ;
F_6 ( V_13 ) ;
return V_124 ;
error:
F_49 ( V_17 ) ;
F_49 ( V_125 ) ;
V_126:
return V_124 ;
}
static int F_50 ( const char * V_127 , int V_128 , const char * * V_129 )
{
const char * * V_130 ;
char V_131 [ V_132 ] ;
int V_67 , V_124 = 0 ;
T_2 * V_133 ;
V_130 = malloc ( ( V_128 + 1 ) * sizeof( const char * ) ) ;
V_130 [ 0 ] = V_127 ;
for ( V_67 = 1 ; V_67 < V_128 + 1 ; V_67 ++ )
V_130 [ V_67 ] = V_129 [ V_67 - 1 ] ;
F_51 () ;
F_52 () ;
F_53 ( V_128 + 1 , ( char * * ) V_130 ) ;
V_133 = fopen ( V_127 , L_47 ) ;
if ( ! V_133 ) {
sprintf ( V_131 , L_48 , V_127 ) ;
perror ( V_131 ) ;
V_124 = - 1 ;
goto error;
}
V_124 = F_54 ( V_133 , V_127 ) ;
if ( V_124 ) {
fprintf ( V_134 , L_49 , V_127 ) ;
goto error;
}
V_124 = F_45 () ;
if ( V_124 ) {
fprintf ( V_134 , L_50 , V_127 ) ;
goto error;
}
free ( V_130 ) ;
return V_124 ;
error:
F_55 () ;
free ( V_130 ) ;
return V_124 ;
}
static int F_56 ( void )
{
T_1 * V_11 , * V_13 ;
int V_124 = 0 ;
V_11 = F_13 ( V_17 , L_51 ) ;
if ( V_11 == NULL || ! F_14 ( V_11 ) )
goto V_126;
V_13 = F_15 ( V_11 , NULL ) ;
if ( V_13 == NULL )
F_1 ( L_51 ) ;
F_6 ( V_13 ) ;
V_126:
F_49 ( V_17 ) ;
F_49 ( V_125 ) ;
F_55 () ;
return V_124 ;
}
static int F_57 ( struct V_112 * V_112 , const char * V_135 )
{
struct V_24 * V_25 = NULL ;
struct V_59 * V_136 ;
char V_137 [ V_132 ] ;
int V_138 , V_139 ;
T_2 * V_140 ;
sprintf ( V_137 , L_52 , V_135 ) ;
V_140 = fopen ( V_137 , L_53 ) ;
if ( V_140 == NULL ) {
fprintf ( V_134 , L_54 , V_137 ) ;
return - 1 ;
}
fprintf ( V_140 , L_55
L_56 ) ;
fprintf ( V_140 , L_57
L_58 ) ;
fprintf ( V_140 , L_59
L_60 ) ;
fprintf ( V_140 , L_61
L_62 ) ;
fprintf ( V_140 , L_63
L_64 ) ;
fprintf ( V_140 , L_65
L_66 ) ;
fprintf ( V_140 , L_67
L_68 ) ;
fprintf ( V_140 , L_69 ) ;
fprintf ( V_140 , L_70 ) ;
fprintf ( V_140 , L_71 ) ;
fprintf ( V_140 , L_72 ) ;
fprintf ( V_140 , L_73 ) ;
fprintf ( V_140 , L_74 ) ;
fprintf ( V_140 , L_75 ) ;
fprintf ( V_140 , L_76 ) ;
fprintf ( V_140 , L_77 ) ;
fprintf ( V_140 , L_78 ) ;
while ( ( V_25 = F_58 ( V_112 , V_25 ) ) ) {
fprintf ( V_140 , L_79 , V_25 -> system , V_25 -> V_33 ) ;
fprintf ( V_140 , L_80 ) ;
fprintf ( V_140 , L_81 ) ;
fprintf ( V_140 , L_82 ) ;
fprintf ( V_140 , L_83 ) ;
fprintf ( V_140 , L_84 ) ;
fprintf ( V_140 , L_85 ) ;
fprintf ( V_140 , L_86 ) ;
fprintf ( V_140 , L_87 ) ;
V_138 = 0 ;
V_139 = 0 ;
for ( V_136 = V_25 -> V_113 . V_114 ; V_136 ; V_136 = V_136 -> V_21 ) {
if ( V_138 ++ )
fprintf ( V_140 , L_88 ) ;
if ( ++ V_139 % 5 == 0 )
fprintf ( V_140 , L_89 ) ;
fprintf ( V_140 , L_31 , V_136 -> V_33 ) ;
}
fprintf ( V_140 , L_90 ) ;
fprintf ( V_140 , L_91
L_92
L_93 ) ;
fprintf ( V_140 , L_94 ) ;
V_138 = 0 ;
V_139 = 0 ;
for ( V_136 = V_25 -> V_113 . V_114 ; V_136 ; V_136 = V_136 -> V_21 ) {
if ( V_138 ++ )
fprintf ( V_140 , L_88 ) ;
if ( V_139 && V_139 % 3 == 0 ) {
fprintf ( V_140 , L_95 ) ;
}
V_139 ++ ;
fprintf ( V_140 , L_96 , V_136 -> V_33 ) ;
if ( V_136 -> V_34 & V_115 ||
V_136 -> V_34 & V_141 ||
V_136 -> V_34 & V_62 ||
V_136 -> V_34 & V_142 )
fprintf ( V_140 , L_97 ) ;
else if ( V_136 -> V_34 & V_70 )
fprintf ( V_140 , L_98 ) ;
else
fprintf ( V_140 , L_99 ) ;
}
fprintf ( V_140 , L_100 ) ;
V_138 = 0 ;
V_139 = 0 ;
for ( V_136 = V_25 -> V_113 . V_114 ; V_136 ; V_136 = V_136 -> V_21 ) {
if ( V_138 ++ )
fprintf ( V_140 , L_88 ) ;
if ( ++ V_139 % 5 == 0 )
fprintf ( V_140 , L_101 ) ;
if ( V_136 -> V_34 & V_141 ) {
if ( ( V_139 - 1 ) % 5 != 0 ) {
fprintf ( V_140 , L_101 ) ;
V_139 = 4 ;
}
fprintf ( V_140 , L_102 ) ;
fprintf ( V_140 , L_103 , V_25 -> system ,
V_25 -> V_33 ) ;
fprintf ( V_140 , L_104 , V_136 -> V_33 ,
V_136 -> V_33 ) ;
} else if ( V_136 -> V_34 & V_142 ) {
if ( ( V_139 - 1 ) % 5 != 0 ) {
fprintf ( V_140 , L_101 ) ;
V_139 = 4 ;
}
fprintf ( V_140 , L_105 ) ;
fprintf ( V_140 , L_103 , V_25 -> system ,
V_25 -> V_33 ) ;
fprintf ( V_140 , L_104 , V_136 -> V_33 ,
V_136 -> V_33 ) ;
} else
fprintf ( V_140 , L_31 , V_136 -> V_33 ) ;
}
fprintf ( V_140 , L_106 ) ;
fprintf ( V_140 , L_107 ) ;
fprintf ( V_140 , L_108 ) ;
fprintf ( V_140 , L_109 ) ;
fprintf ( V_140 , L_110 ) ;
fprintf ( V_140 , L_111 ) ;
fprintf ( V_140 , L_112 ) ;
}
fprintf ( V_140 , L_113
L_114 ) ;
fprintf ( V_140 , L_115
L_116 ) ;
fprintf ( V_140 , L_117
L_118
L_119
L_120 ) ;
fclose ( V_140 ) ;
fprintf ( V_134 , L_121 , V_137 ) ;
return 0 ;
}
