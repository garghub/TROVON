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
static T_1 * F_7 ( const char * V_1 )
{
T_1 * V_5 ;
V_5 = F_8 ( V_6 , V_1 ) ;
if ( V_5 && ! F_9 ( V_5 ) )
return NULL ;
return V_5 ;
}
static void F_10 ( T_1 * V_5 , T_1 * args , const char * V_7 )
{
T_1 * V_8 ;
V_8 = F_11 ( V_5 , args ) ;
if ( V_8 == NULL )
F_1 ( V_7 ) ;
F_6 ( V_8 ) ;
}
static void F_12 ( const char * V_1 , T_1 * args )
{
T_1 * V_5 ;
V_5 = F_7 ( V_1 ) ;
if ( V_5 )
F_10 ( V_5 , args , V_1 ) ;
}
static void F_13 ( enum V_9 V_10 ,
const char * V_11 ,
const char * V_12 ,
const char * V_13 ,
const char * V_14 )
{
const char * V_1 = L_2 ;
T_1 * V_15 ;
unsigned long long V_16 ;
unsigned V_17 = 0 ;
if ( V_10 == V_18 )
V_1 = L_3 ;
V_15 = F_14 ( 4 ) ;
if ( ! V_15 )
F_3 ( L_4 ) ;
V_16 = F_15 ( V_13 ) ;
F_16 ( V_15 , V_17 ++ , F_17 ( V_11 ) ) ;
F_16 ( V_15 , V_17 ++ , F_17 ( V_12 ) ) ;
F_16 ( V_15 , V_17 ++ , F_18 ( V_16 ) ) ;
F_16 ( V_15 , V_17 ++ , F_17 ( V_14 ) ) ;
F_12 ( V_1 , V_15 ) ;
F_6 ( V_15 ) ;
}
static void F_19 ( enum V_9 V_10 ,
struct V_19 * V_20 ,
const char * V_11 ,
const char * V_12 )
{
F_13 ( V_10 , V_11 , V_12 , V_20 -> V_16 ,
V_20 -> V_21 ) ;
if ( V_20 -> V_22 )
F_19 ( V_10 , V_20 -> V_22 , V_11 , V_12 ) ;
}
static void F_20 ( enum V_9 V_10 ,
const char * V_11 ,
const char * V_12 ,
const char * V_23 )
{
const char * V_1 = L_5 ;
T_1 * V_15 ;
unsigned V_17 = 0 ;
if ( V_10 == V_18 )
V_1 = L_6 ;
if ( V_10 == V_24 )
V_15 = F_14 ( 3 ) ;
else
V_15 = F_14 ( 2 ) ;
if ( ! V_15 )
F_3 ( L_4 ) ;
F_16 ( V_15 , V_17 ++ , F_17 ( V_11 ) ) ;
F_16 ( V_15 , V_17 ++ , F_17 ( V_12 ) ) ;
if ( V_10 == V_24 )
F_16 ( V_15 , V_17 ++ , F_17 ( V_23 ) ) ;
F_12 ( V_1 , V_15 ) ;
F_6 ( V_15 ) ;
}
static void F_21 ( struct V_25 * V_26 ,
const char * V_11 ,
struct V_27 * args )
{
switch ( args -> type ) {
case V_28 :
break;
case V_29 :
F_13 ( V_24 , V_11 , V_30 , L_7 ,
args -> V_31 . V_31 ) ;
V_32 = 0 ;
break;
case V_33 :
free ( V_30 ) ;
V_30 = F_22 ( args -> V_20 . V_34 ) ;
break;
case V_24 :
F_21 ( V_26 , V_11 , args -> V_35 . V_20 ) ;
F_20 ( V_24 , V_11 , V_30 ,
args -> V_35 . V_23 ) ;
F_19 ( V_24 , args -> V_35 . V_35 , V_11 ,
V_30 ) ;
break;
case V_18 :
F_21 ( V_26 , V_11 , args -> V_36 . V_20 ) ;
F_20 ( V_18 , V_11 , V_30 , NULL ) ;
F_19 ( V_18 , args -> V_36 . V_37 , V_11 ,
V_30 ) ;
break;
case V_38 :
F_21 ( V_26 , V_11 , args -> V_39 . V_20 ) ;
F_21 ( V_26 , V_11 , args -> V_39 . V_40 ) ;
break;
case V_41 :
break;
case V_42 :
F_21 ( V_26 , V_11 , args -> V_43 . V_44 ) ;
break;
case V_45 :
if ( strcmp ( args -> V_46 . V_46 , L_8 ) == 0 )
V_32 = 1 ;
F_21 ( V_26 , V_11 , args -> V_46 . V_47 ) ;
F_21 ( V_26 , V_11 , args -> V_46 . V_48 ) ;
break;
default:
case V_49 :
case V_50 :
case V_51 :
case V_52 :
return;
}
if ( args -> V_22 )
F_21 ( V_26 , V_11 , args -> V_22 ) ;
}
static inline struct V_25 * F_23 ( struct V_53 * V_54 )
{
static char V_11 [ 256 ] ;
struct V_25 * V_26 ;
int type = V_54 -> V_55 . V_56 ;
if ( V_57 [ type ] )
return V_57 [ type ] ;
V_57 [ type ] = V_26 = V_54 -> V_58 ;
if ( ! V_26 )
return NULL ;
sprintf ( V_11 , L_9 , V_26 -> system , V_26 -> V_34 ) ;
F_21 ( V_26 , V_11 , V_26 -> V_59 . args ) ;
return V_26 ;
}
static T_1 * F_24 ( struct V_25 * V_26 ,
struct V_60 * V_20 , void * V_61 )
{
bool V_62 = V_20 -> V_35 & V_63 ;
T_1 * V_64 , * V_65 = NULL ;
unsigned long long V_4 ;
unsigned int V_66 , V_67 , V_68 ;
if ( V_62 ) {
V_65 = F_25 ( V_20 -> V_69 ) ;
V_66 = V_20 -> V_40 / V_20 -> V_69 ;
V_67 = V_20 -> V_69 ;
} else {
V_66 = V_20 -> V_40 ;
V_67 = 1 ;
}
for ( V_68 = 0 ; V_68 < V_67 ; V_68 ++ ) {
V_4 = F_26 ( V_26 , V_61 + V_20 -> V_70 + V_68 * V_66 ,
V_66 ) ;
if ( V_20 -> V_35 & V_71 ) {
if ( ( long long ) V_4 >= V_72 &&
( long long ) V_4 <= V_73 )
V_64 = F_18 ( V_4 ) ;
else
V_64 = F_27 ( V_4 ) ;
} else {
if ( V_4 <= V_73 )
V_64 = F_18 ( V_4 ) ;
else
V_64 = F_28 ( V_4 ) ;
}
if ( V_62 )
F_29 ( V_65 , V_68 , V_64 ) ;
}
if ( V_62 )
V_64 = V_65 ;
return V_64 ;
}
static T_1 * F_30 ( struct V_74 * V_75 ,
struct V_53 * V_54 ,
struct V_76 * V_77 )
{
T_1 * V_78 ;
V_78 = F_25 ( 0 ) ;
if ( ! V_78 )
F_3 ( L_10 ) ;
if ( ! V_79 . V_80 || ! V_75 -> V_81 )
goto exit;
if ( F_31 ( V_77 -> V_82 , V_54 , V_77 -> V_83 ,
V_75 , NULL , NULL ,
V_84 ) != 0 ) {
F_32 ( L_11 ) ;
goto exit;
}
F_33 ( & V_85 ) ;
while ( 1 ) {
T_1 * V_86 ;
struct V_87 * V_88 ;
V_88 = F_34 ( & V_85 ) ;
if ( ! V_88 )
break;
V_86 = F_35 () ;
if ( ! V_86 )
F_3 ( L_12 ) ;
F_4 ( V_86 , L_13 ,
F_28 ( V_88 -> V_89 ) ) ;
if ( V_88 -> V_90 ) {
T_1 * V_91 = F_35 () ;
if ( ! V_91 )
F_3 ( L_12 ) ;
F_4 ( V_91 , L_14 ,
F_28 ( V_88 -> V_90 -> V_92 ) ) ;
F_4 ( V_91 , L_15 ,
F_28 ( V_88 -> V_90 -> V_93 ) ) ;
F_4 ( V_91 , L_16 ,
F_18 ( V_88 -> V_90 -> V_94 ) ) ;
F_4 ( V_91 , L_17 ,
F_36 ( V_88 -> V_90 -> V_34 ,
V_88 -> V_90 -> V_95 ) ) ;
F_4 ( V_86 , L_18 , V_91 ) ;
}
if ( V_88 -> V_96 ) {
struct V_96 * V_96 = V_88 -> V_96 ;
const char * V_97 = L_19 ;
if ( V_96 && V_96 -> V_98 && ( V_96 -> V_98 -> V_34 || V_96 -> V_98 -> V_99 ) ) {
if ( V_79 . V_100 && V_96 -> V_98 -> V_99 )
V_97 = V_96 -> V_98 -> V_99 ;
else if ( V_96 -> V_98 -> V_34 )
V_97 = V_96 -> V_98 -> V_34 ;
}
F_4 ( V_86 , L_20 ,
F_17 ( V_97 ) ) ;
}
F_37 ( & V_85 ) ;
F_38 ( V_78 , V_86 ) ;
F_6 ( V_86 ) ;
}
exit:
return V_78 ;
}
static void F_39 ( struct V_74 * V_75 ,
struct V_53 * V_54 ,
struct V_83 * V_83 ,
struct V_76 * V_77 )
{
T_1 * V_5 , * V_101 , * V_15 , * V_64 , * V_81 ;
T_1 * V_2 = NULL ;
static char V_1 [ 256 ] ;
struct V_60 * V_20 ;
unsigned long V_102 , V_103 ;
struct V_25 * V_26 ;
unsigned V_17 = 0 ;
int V_104 ;
int V_105 = V_75 -> V_105 ;
void * V_61 = V_75 -> V_106 ;
unsigned long long V_107 = V_75 -> time ;
const char * V_108 = F_40 ( V_83 ) ;
V_15 = F_14 ( V_109 ) ;
if ( ! V_15 )
F_3 ( L_4 ) ;
V_26 = F_23 ( V_54 ) ;
if ( ! V_26 )
F_41 ( L_21 , ( int ) V_54 -> V_55 . V_56 ) ;
V_104 = F_42 ( V_26 , L_22 , V_61 ) ;
sprintf ( V_1 , L_9 , V_26 -> system , V_26 -> V_34 ) ;
V_5 = F_7 ( V_1 ) ;
if ( ! V_5 ) {
V_2 = F_35 () ;
if ( ! V_2 )
F_3 ( L_23 ) ;
}
V_102 = V_107 / V_110 ;
V_103 = V_107 - V_102 * V_110 ;
V_111 -> V_112 = V_61 ;
V_111 -> V_113 = V_54 -> V_58 -> V_113 ;
V_101 = F_43 ( V_111 , NULL ) ;
F_16 ( V_15 , V_17 ++ , F_17 ( V_1 ) ) ;
F_16 ( V_15 , V_17 ++ , V_101 ) ;
V_81 = F_30 ( V_75 , V_54 , V_77 ) ;
if ( V_5 ) {
F_16 ( V_15 , V_17 ++ , F_18 ( V_105 ) ) ;
F_16 ( V_15 , V_17 ++ , F_18 ( V_102 ) ) ;
F_16 ( V_15 , V_17 ++ , F_18 ( V_103 ) ) ;
F_16 ( V_15 , V_17 ++ , F_18 ( V_104 ) ) ;
F_16 ( V_15 , V_17 ++ , F_17 ( V_108 ) ) ;
F_16 ( V_15 , V_17 ++ , V_81 ) ;
} else {
F_4 ( V_2 , L_24 , F_18 ( V_105 ) ) ;
F_4 ( V_2 , L_25 , F_18 ( V_102 ) ) ;
F_4 ( V_2 , L_26 , F_18 ( V_103 ) ) ;
F_4 ( V_2 , L_22 , F_18 ( V_104 ) ) ;
F_4 ( V_2 , L_27 , F_17 ( V_108 ) ) ;
F_4 ( V_2 , L_28 , V_81 ) ;
}
for ( V_20 = V_26 -> V_114 . V_115 ; V_20 ; V_20 = V_20 -> V_22 ) {
if ( V_20 -> V_35 & V_116 ) {
int V_70 ;
if ( V_20 -> V_35 & V_117 ) {
V_70 = * ( int * ) ( V_61 + V_20 -> V_70 ) ;
V_70 &= 0xffff ;
} else
V_70 = V_20 -> V_70 ;
V_64 = F_17 ( ( char * ) V_61 + V_70 ) ;
} else {
V_64 = F_24 ( V_26 , V_20 , V_61 ) ;
}
if ( V_5 )
F_16 ( V_15 , V_17 ++ , V_64 ) ;
else
F_4 ( V_2 , V_20 -> V_34 , V_64 ) ;
}
if ( ! V_5 )
F_16 ( V_15 , V_17 ++ , V_2 ) ;
if ( F_44 ( & V_15 , V_17 ) == - 1 )
F_3 ( L_29 ) ;
if ( V_5 ) {
F_10 ( V_5 , V_15 , V_1 ) ;
} else {
F_12 ( L_30 , V_15 ) ;
F_6 ( V_2 ) ;
}
F_6 ( V_15 ) ;
}
static void F_45 ( struct V_74 * V_75 ,
struct V_53 * V_54 ,
struct V_83 * V_83 ,
struct V_76 * V_77 )
{
T_1 * V_5 , * V_15 , * V_2 , * V_81 , * V_118 ;
static char V_1 [ 64 ] ;
unsigned V_17 = 0 ;
V_15 = F_14 ( V_109 ) ;
if ( ! V_15 )
F_3 ( L_4 ) ;
V_2 = F_35 () ;
if ( ! V_2 )
F_3 ( L_12 ) ;
V_118 = F_35 () ;
if ( ! V_118 )
F_3 ( L_12 ) ;
snprintf ( V_1 , sizeof( V_1 ) , L_31 , L_32 ) ;
V_5 = F_7 ( V_1 ) ;
if ( ! V_5 )
goto exit;
F_4 ( V_2 , L_33 , F_17 ( F_46 ( V_54 ) ) ) ;
F_4 ( V_2 , L_34 , F_36 (
( const char * ) & V_54 -> V_55 , sizeof( V_54 -> V_55 ) ) ) ;
F_4 ( V_118 , L_35 ,
F_18 ( V_75 -> V_104 ) ) ;
F_4 ( V_118 , L_36 ,
F_18 ( V_75 -> V_119 ) ) ;
F_4 ( V_118 , L_37 ,
F_18 ( V_75 -> V_105 ) ) ;
F_4 ( V_118 , L_13 ,
F_28 ( V_75 -> V_89 ) ) ;
F_4 ( V_118 , L_38 ,
F_28 ( V_75 -> time ) ) ;
F_4 ( V_118 , L_39 ,
F_28 ( V_75 -> V_120 ) ) ;
F_4 ( V_2 , L_40 , V_118 ) ;
F_4 ( V_2 , L_41 , F_36 (
( const char * ) V_75 -> V_106 , V_75 -> V_121 ) ) ;
F_4 ( V_2 , L_42 ,
F_17 ( F_40 ( V_83 ) ) ) ;
if ( V_77 -> V_96 ) {
F_4 ( V_2 , L_20 ,
F_17 ( V_77 -> V_96 -> V_98 -> V_34 ) ) ;
}
if ( V_77 -> V_90 ) {
F_4 ( V_2 , L_43 ,
F_17 ( V_77 -> V_90 -> V_34 ) ) ;
}
V_81 = F_30 ( V_75 , V_54 , V_77 ) ;
F_4 ( V_2 , L_44 , V_81 ) ;
F_16 ( V_15 , V_17 ++ , V_2 ) ;
if ( F_44 ( & V_15 , V_17 ) == - 1 )
F_3 ( L_29 ) ;
F_10 ( V_5 , V_15 , V_1 ) ;
exit:
F_6 ( V_2 ) ;
F_6 ( V_15 ) ;
}
static void F_47 ( union V_122 * V_26 V_123 ,
struct V_74 * V_75 ,
struct V_53 * V_54 ,
struct V_83 * V_83 ,
struct V_76 * V_77 )
{
switch ( V_54 -> V_55 . type ) {
case V_124 :
F_39 ( V_75 , V_54 , V_83 , V_77 ) ;
break;
default:
F_45 ( V_75 , V_54 , V_83 , V_77 ) ;
}
}
static int F_48 ( void )
{
V_125 = F_49 ( L_45 ) ;
if ( V_125 == NULL )
return - 1 ;
F_50 ( V_125 ) ;
V_6 = F_51 ( V_125 ) ;
if ( V_6 == NULL )
goto error;
F_50 ( V_6 ) ;
F_12 ( L_46 , NULL ) ;
return 0 ;
error:
F_52 ( V_6 ) ;
F_52 ( V_125 ) ;
return - 1 ;
}
static int F_53 ( const char * V_126 , int V_127 , const char * * V_128 )
{
const char * * V_129 ;
char V_130 [ V_131 ] ;
int V_68 , V_132 = 0 ;
T_2 * V_133 ;
V_129 = malloc ( ( V_127 + 1 ) * sizeof( const char * ) ) ;
V_129 [ 0 ] = V_126 ;
for ( V_68 = 1 ; V_68 < V_127 + 1 ; V_68 ++ )
V_129 [ V_68 ] = V_128 [ V_68 - 1 ] ;
F_54 () ;
F_55 () ;
F_56 ( V_127 + 1 , ( char * * ) V_129 ) ;
V_133 = fopen ( V_126 , L_47 ) ;
if ( ! V_133 ) {
sprintf ( V_130 , L_48 , V_126 ) ;
perror ( V_130 ) ;
V_132 = - 1 ;
goto error;
}
V_132 = F_57 ( V_133 , V_126 ) ;
if ( V_132 ) {
fprintf ( V_134 , L_49 , V_126 ) ;
goto error;
}
V_132 = F_48 () ;
if ( V_132 ) {
fprintf ( V_134 , L_50 , V_126 ) ;
goto error;
}
free ( V_129 ) ;
return V_132 ;
error:
F_58 () ;
free ( V_129 ) ;
return V_132 ;
}
static int F_59 ( void )
{
return 0 ;
}
static int F_60 ( void )
{
F_12 ( L_51 , NULL ) ;
F_52 ( V_6 ) ;
F_52 ( V_125 ) ;
F_58 () ;
return 0 ;
}
static int F_61 ( struct V_113 * V_113 , const char * V_135 )
{
struct V_25 * V_26 = NULL ;
struct V_60 * V_136 ;
char V_137 [ V_131 ] ;
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
while ( ( V_26 = F_62 ( V_113 , V_26 ) ) ) {
fprintf ( V_140 , L_79 , V_26 -> system , V_26 -> V_34 ) ;
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
for ( V_136 = V_26 -> V_114 . V_115 ; V_136 ; V_136 = V_136 -> V_22 ) {
if ( V_138 ++ )
fprintf ( V_140 , L_88 ) ;
if ( ++ V_139 % 5 == 0 )
fprintf ( V_140 , L_89 ) ;
fprintf ( V_140 , L_31 , V_136 -> V_34 ) ;
}
fprintf ( V_140 , L_90 ) ;
fprintf ( V_140 , L_91
L_92
L_93 ) ;
fprintf ( V_140 , L_94 ) ;
V_138 = 0 ;
V_139 = 0 ;
for ( V_136 = V_26 -> V_114 . V_115 ; V_136 ; V_136 = V_136 -> V_22 ) {
if ( V_138 ++ )
fprintf ( V_140 , L_88 ) ;
if ( V_139 && V_139 % 3 == 0 ) {
fprintf ( V_140 , L_95 ) ;
}
V_139 ++ ;
fprintf ( V_140 , L_96 , V_136 -> V_34 ) ;
if ( V_136 -> V_35 & V_116 ||
V_136 -> V_35 & V_141 ||
V_136 -> V_35 & V_63 ||
V_136 -> V_35 & V_142 )
fprintf ( V_140 , L_97 ) ;
else if ( V_136 -> V_35 & V_71 )
fprintf ( V_140 , L_98 ) ;
else
fprintf ( V_140 , L_99 ) ;
}
fprintf ( V_140 , L_100 ) ;
V_138 = 0 ;
V_139 = 0 ;
for ( V_136 = V_26 -> V_114 . V_115 ; V_136 ; V_136 = V_136 -> V_22 ) {
if ( V_138 ++ )
fprintf ( V_140 , L_88 ) ;
if ( ++ V_139 % 5 == 0 )
fprintf ( V_140 , L_101 ) ;
if ( V_136 -> V_35 & V_141 ) {
if ( ( V_139 - 1 ) % 5 != 0 ) {
fprintf ( V_140 , L_101 ) ;
V_139 = 4 ;
}
fprintf ( V_140 , L_102 ) ;
fprintf ( V_140 , L_103 , V_26 -> system ,
V_26 -> V_34 ) ;
fprintf ( V_140 , L_104 , V_136 -> V_34 ,
V_136 -> V_34 ) ;
} else if ( V_136 -> V_35 & V_142 ) {
if ( ( V_139 - 1 ) % 5 != 0 ) {
fprintf ( V_140 , L_101 ) ;
V_139 = 4 ;
}
fprintf ( V_140 , L_105 ) ;
fprintf ( V_140 , L_103 , V_26 -> system ,
V_26 -> V_34 ) ;
fprintf ( V_140 , L_104 , V_136 -> V_34 ,
V_136 -> V_34 ) ;
} else
fprintf ( V_140 , L_31 , V_136 -> V_34 ) ;
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
