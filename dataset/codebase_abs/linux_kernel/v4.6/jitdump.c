static int
F_1 ( char * V_1 ,
const char * V_2 ,
T_1 V_3 ,
const void * V_4 ,
int V_5 ,
void * V_6 ,
int V_7 )
{
int V_8 , V_9 ;
if ( V_10 > 0 )
fprintf ( V_11 , L_1 , V_1 ) ;
V_9 = F_2 ( V_1 , V_12 | V_13 | V_14 , 0644 ) ;
if ( V_9 == - 1 ) {
F_3 ( L_2 , V_1 , strerror ( V_15 ) ) ;
return - 1 ;
}
V_8 = F_4 ( V_9 , V_3 , V_2 , ( const void * ) V_4 , V_5 , V_6 , V_7 ) ;
F_5 ( V_9 ) ;
if ( V_8 )
F_6 ( V_1 ) ;
return V_8 ;
}
static void
F_7 ( struct V_16 * V_17 )
{
if ( ! ( V_17 && V_17 -> V_18 ) )
return;
F_8 ( V_17 -> V_18 ) ;
fclose ( V_17 -> V_18 ) ;
V_17 -> V_18 = NULL ;
}
static int
F_9 ( struct V_19 * V_20 )
{
struct V_21 * V_22 ;
F_10 (session->evlist, evsel) {
if ( V_22 -> V_23 . V_24 == 0 || V_22 -> V_23 . V_25 != V_26 )
return - 1 ;
}
return 0 ;
}
static int
F_11 ( struct V_16 * V_17 , const char * V_27 )
{
struct V_28 V_29 ;
struct V_30 * V_31 ;
T_2 V_32 , V_33 = 0 ;
void * V_34 , * V_35 = NULL ;
int V_8 , V_36 = - 1 ;
V_17 -> V_18 = fopen ( V_27 , L_3 ) ;
if ( ! V_17 -> V_18 )
return - 1 ;
V_33 = F_12 ( sizeof( V_29 ) , sizeof( * V_31 ) ) ;
V_35 = malloc ( V_33 ) ;
if ( ! V_35 )
goto error;
F_13 ( V_17 -> V_18 ) ;
V_8 = fread ( V_35 , sizeof( V_29 ) , 1 , V_17 -> V_18 ) ;
if ( V_8 != 1 )
goto error;
memcpy ( & V_29 , V_35 , sizeof( V_29 ) ) ;
if ( V_29 . V_37 != V_38 ) {
if ( V_29 . V_37 != V_39 )
goto error;
V_17 -> V_40 = true ;
}
if ( V_17 -> V_40 ) {
V_29 . V_41 = F_14 ( V_29 . V_41 ) ;
V_29 . V_42 = F_14 ( V_29 . V_42 ) ;
V_29 . V_43 = F_14 ( V_29 . V_43 ) ;
V_29 . V_44 = F_14 ( V_29 . V_44 ) ;
V_29 . V_45 = F_15 ( V_29 . V_45 ) ;
V_29 . V_46 = F_15 ( V_29 . V_46 ) ;
}
if ( V_10 > 2 )
F_16 ( L_4 ,
V_29 . V_41 ,
V_29 . V_42 ,
( unsigned long long ) V_29 . V_45 ,
V_29 . V_43 ,
V_29 . V_44 ) ;
if ( V_29 . V_46 & V_47 ) {
F_17 ( L_5 ,
( unsigned long long ) V_29 . V_46 & V_47 ) ;
goto error;
}
if ( F_9 ( V_17 -> V_20 ) ) {
F_17 ( L_6 ) ;
goto error;
}
V_32 = V_29 . V_42 - sizeof( V_29 ) ;
if ( V_32 > V_33 ) {
V_34 = realloc ( V_35 , V_32 ) ;
if ( ! V_34 )
goto error;
V_33 = V_32 ;
V_35 = V_34 ;
V_8 = fread ( V_35 , V_32 - V_33 , 1 , V_17 -> V_18 ) ;
if ( V_8 != 1 )
goto error;
}
strcpy ( V_17 -> V_48 , V_27 ) ;
F_18 ( V_17 -> V_48 ) ;
return 0 ;
error:
F_8 ( V_17 -> V_18 ) ;
fclose ( V_17 -> V_18 ) ;
return V_36 ;
}
static union V_49 *
F_19 ( struct V_16 * V_17 )
{
struct V_30 * V_31 ;
union V_49 * V_50 ;
void * V_51 ;
T_3 V_32 , V_52 ;
int V_53 , V_8 ;
if ( ! ( V_17 && V_17 -> V_18 ) )
return NULL ;
if ( V_17 -> V_35 == NULL ) {
T_3 V_54 = F_20 () ;
if ( V_54 < sizeof( * V_31 ) )
V_54 = sizeof( * V_31 ) ;
V_17 -> V_35 = malloc ( V_54 ) ;
if ( V_17 -> V_35 == NULL )
return NULL ;
V_17 -> V_55 = V_54 ;
}
V_31 = V_17 -> V_35 ;
V_8 = fread ( V_31 , sizeof( * V_31 ) , 1 , V_17 -> V_18 ) ;
if ( V_8 != 1 )
return NULL ;
if ( V_17 -> V_40 ) {
V_31 -> V_53 = F_14 ( V_31 -> V_53 ) ;
V_31 -> V_42 = F_14 ( V_31 -> V_42 ) ;
V_31 -> V_45 = F_15 ( V_31 -> V_45 ) ;
}
V_53 = V_31 -> V_53 ;
V_52 = V_31 -> V_42 ;
V_32 = ( T_3 ) V_52 ;
if ( V_32 < sizeof( * V_31 ) )
return NULL ;
if ( V_53 >= V_56 ) {
F_3 ( L_7 , V_53 ) ;
return NULL ;
}
if ( V_32 > V_17 -> V_55 ) {
void * V_34 ;
V_34 = realloc ( V_17 -> V_35 , V_32 ) ;
if ( ! V_34 )
return NULL ;
V_17 -> V_35 = V_34 ;
V_17 -> V_55 = V_32 ;
}
V_51 = ( ( void * ) V_17 -> V_35 ) + sizeof( * V_31 ) ;
V_8 = fread ( V_51 , V_32 - sizeof( * V_31 ) , 1 , V_17 -> V_18 ) ;
if ( V_8 != 1 )
return NULL ;
V_50 = (union V_49 * ) V_17 -> V_35 ;
switch( V_53 ) {
case V_57 :
if ( V_17 -> V_40 ) {
T_1 V_34 ;
V_50 -> V_58 . V_3 = F_15 ( V_50 -> V_58 . V_3 ) ;
V_50 -> V_58 . V_59 = F_15 ( V_50 -> V_58 . V_59 ) ;
for ( V_34 = 0 ; V_34 < V_50 -> V_58 . V_59 ; V_34 ++ ) {
V_50 -> V_58 . V_60 [ V_34 ] . V_51 = F_15 ( V_50 -> V_58 . V_60 [ V_34 ] . V_51 ) ;
V_50 -> V_58 . V_60 [ V_34 ] . V_61 = F_14 ( V_50 -> V_58 . V_60 [ V_34 ] . V_61 ) ;
V_50 -> V_58 . V_60 [ V_34 ] . V_62 = F_14 ( V_50 -> V_58 . V_60 [ V_34 ] . V_62 ) ;
}
}
break;
case V_63 :
break;
case V_64 :
if ( V_17 -> V_40 ) {
V_50 -> V_65 . V_43 = F_14 ( V_50 -> V_65 . V_43 ) ;
V_50 -> V_65 . V_66 = F_14 ( V_50 -> V_65 . V_66 ) ;
V_50 -> V_65 . V_67 = F_15 ( V_50 -> V_65 . V_67 ) ;
V_50 -> V_65 . V_3 = F_15 ( V_50 -> V_65 . V_3 ) ;
V_50 -> V_65 . V_68 = F_15 ( V_50 -> V_65 . V_68 ) ;
V_50 -> V_65 . V_69 = F_15 ( V_50 -> V_65 . V_69 ) ;
}
V_17 -> V_70 ++ ;
break;
case V_71 :
if ( V_17 -> V_40 ) {
V_50 -> V_72 . V_43 = F_14 ( V_50 -> V_72 . V_43 ) ;
V_50 -> V_72 . V_66 = F_14 ( V_50 -> V_72 . V_66 ) ;
V_50 -> V_72 . V_67 = F_15 ( V_50 -> V_72 . V_67 ) ;
V_50 -> V_72 . V_73 = F_15 ( V_50 -> V_72 . V_73 ) ;
V_50 -> V_72 . V_74 = F_15 ( V_50 -> V_72 . V_74 ) ;
V_50 -> V_72 . V_68 = F_15 ( V_50 -> V_72 . V_68 ) ;
V_50 -> V_72 . V_69 = F_15 ( V_50 -> V_72 . V_69 ) ;
}
break;
case V_56 :
default:
return NULL ;
}
return V_50 ;
}
static int
F_21 ( struct V_16 * V_17 , union V_75 * V_76 )
{
T_2 V_52 ;
V_52 = F_22 ( V_17 -> V_77 , V_76 , V_76 -> V_29 . V_52 ) ;
if ( V_52 < 0 )
return - 1 ;
V_17 -> V_78 += V_52 ;
return 0 ;
}
static int F_23 ( struct V_16 * V_17 , union V_49 * V_50 )
{
struct V_79 V_80 ;
union V_75 * V_76 ;
struct V_81 * V_82 = V_17 -> V_20 -> V_82 ;
T_1 V_4 , V_51 ;
T_4 V_83 ;
char * V_1 ;
struct V_84 V_85 ;
T_3 V_52 ;
T_5 V_86 ;
const char * V_2 ;
T_6 V_87 ;
int V_8 , V_5 ;
T_7 V_43 , V_66 ;
struct {
T_8 V_43 , V_66 ;
T_9 time ;
} * V_53 ;
V_43 = V_50 -> V_65 . V_43 ;
V_66 = V_50 -> V_65 . V_66 ;
V_5 = V_50 -> V_65 . V_68 ;
V_51 = V_50 -> V_65 . V_3 ;
V_2 = ( void * ) ( ( unsigned long ) V_50 + sizeof( V_50 -> V_65 ) ) ;
V_4 = ( unsigned long ) V_50 + V_50 -> V_65 . V_88 . V_42 - V_5 ;
V_87 = V_50 -> V_65 . V_69 ;
V_86 = V_17 -> V_89 -> V_90 ;
V_76 = calloc ( 1 , sizeof( * V_76 ) + V_86 ) ;
if ( ! V_76 )
return - 1 ;
V_1 = V_76 -> V_91 . V_1 ;
V_52 = snprintf ( V_1 , V_92 , L_8 ,
V_17 -> V_48 ,
V_43 ,
V_87 ) ;
V_52 ++ ;
V_52 = F_24 ( V_52 , sizeof( T_9 ) ) ;
V_83 = ( T_4 ) V_4 ;
V_8 = F_1 ( V_1 , V_2 , V_51 , ( const void * ) V_83 , V_5 , V_17 -> V_93 , V_17 -> V_7 ) ;
if ( V_17 -> V_93 && V_17 -> V_7 ) {
free ( V_17 -> V_93 ) ;
V_17 -> V_93 = NULL ;
V_17 -> V_7 = 0 ;
}
if ( V_8 ) {
free ( V_76 ) ;
return - 1 ;
}
if ( V_84 ( V_1 , & V_85 ) )
memset ( & V_85 , 0 , sizeof( V_84 ) ) ;
V_76 -> V_91 . V_29 . type = V_94 ;
V_76 -> V_91 . V_29 . V_95 = V_96 ;
V_76 -> V_91 . V_29 . V_52 = ( sizeof( V_76 -> V_91 ) -
( sizeof( V_76 -> V_91 . V_1 ) - V_52 ) + V_86 ) ;
V_76 -> V_91 . V_97 = V_98 ;
V_76 -> V_91 . V_99 = V_51 ;
V_76 -> V_91 . V_100 = V_5 ;
V_76 -> V_91 . V_43 = V_43 ;
V_76 -> V_91 . V_66 = V_66 ;
V_76 -> V_91 . V_101 = V_85 . V_102 ;
V_76 -> V_91 . V_103 = F_25 ( V_85 . V_104 ) ;
V_76 -> V_91 . V_105 = F_26 ( V_85 . V_104 ) ;
V_76 -> V_91 . V_106 = V_85 . V_107 ;
V_76 -> V_91 . V_46 = V_108 ;
V_76 -> V_91 . V_109 = 1 ;
V_53 = ( void * ) ( ( unsigned long ) V_76 + V_76 -> V_110 . V_29 . V_52 - V_86 ) ;
if ( V_17 -> V_111 & V_112 ) {
V_53 -> V_43 = V_43 ;
V_53 -> V_66 = V_66 ;
}
if ( V_17 -> V_111 & V_113 )
V_53 -> time = V_50 -> V_65 . V_88 . V_45 ;
memset ( & V_80 , 0 , sizeof( V_80 ) ) ;
V_80 . V_114 = V_96 ;
V_80 . V_43 = V_43 ;
V_80 . V_66 = V_66 ;
V_80 . time = V_53 -> time ;
V_80 . V_115 = V_51 ;
V_8 = F_27 ( V_82 , V_76 , & V_80 , V_17 -> V_89 ) ;
if ( V_8 )
return V_8 ;
V_8 = F_21 ( V_17 , V_76 ) ;
if ( ! V_8 )
F_28 ( V_82 , V_76 , & V_80 , NULL , V_17 -> V_89 ) ;
return V_8 ;
}
static int F_29 ( struct V_16 * V_17 , union V_49 * V_50 )
{
struct V_79 V_80 ;
union V_75 * V_76 ;
struct V_81 * V_82 = V_17 -> V_20 -> V_82 ;
char * V_1 ;
T_3 V_52 ;
struct V_84 V_85 ;
T_5 V_86 ;
int V_8 ;
T_7 V_43 , V_66 ;
struct {
T_8 V_43 , V_66 ;
T_9 time ;
} * V_53 ;
V_43 = V_50 -> V_72 . V_43 ;
V_66 = V_50 -> V_72 . V_66 ;
V_86 = V_17 -> V_89 -> V_90 ;
V_76 = calloc ( 1 , sizeof( * V_76 ) + 16 ) ;
if ( ! V_76 )
return - 1 ;
V_1 = V_76 -> V_91 . V_1 ;
V_52 = snprintf ( V_1 , V_92 , L_9 V_116 ,
V_17 -> V_48 ,
V_43 ,
V_50 -> V_72 . V_69 ) ;
V_52 ++ ;
if ( V_84 ( V_1 , & V_85 ) )
memset ( & V_85 , 0 , sizeof( V_84 ) ) ;
V_52 = F_24 ( V_52 , sizeof( T_9 ) ) ;
V_76 -> V_91 . V_29 . type = V_94 ;
V_76 -> V_91 . V_29 . V_95 = V_96 ;
V_76 -> V_91 . V_29 . V_52 = ( sizeof( V_76 -> V_91 ) -
( sizeof( V_76 -> V_91 . V_1 ) - V_52 ) + V_86 ) ;
V_76 -> V_91 . V_97 = V_98 ;
V_76 -> V_91 . V_99 = V_50 -> V_72 . V_74 ;
V_76 -> V_91 . V_100 = V_50 -> V_72 . V_68 ;
V_76 -> V_91 . V_43 = V_43 ;
V_76 -> V_91 . V_66 = V_66 ;
V_76 -> V_91 . V_101 = V_85 . V_102 ;
V_76 -> V_91 . V_103 = F_25 ( V_85 . V_104 ) ;
V_76 -> V_91 . V_105 = F_26 ( V_85 . V_104 ) ;
V_76 -> V_91 . V_106 = V_85 . V_107 ;
V_76 -> V_91 . V_46 = V_108 ;
V_76 -> V_91 . V_109 = 1 ;
V_53 = ( void * ) ( ( unsigned long ) V_76 + V_76 -> V_110 . V_29 . V_52 - V_86 ) ;
if ( V_17 -> V_111 & V_112 ) {
V_53 -> V_43 = V_43 ;
V_53 -> V_66 = V_66 ;
}
if ( V_17 -> V_111 & V_113 )
V_53 -> time = V_50 -> V_65 . V_88 . V_45 ;
memset ( & V_80 , 0 , sizeof( V_80 ) ) ;
V_80 . V_114 = V_96 ;
V_80 . V_43 = V_43 ;
V_80 . V_66 = V_66 ;
V_80 . time = V_53 -> time ;
V_80 . V_115 = V_50 -> V_72 . V_74 ;
V_8 = F_27 ( V_82 , V_76 , & V_80 , V_17 -> V_89 ) ;
if ( V_8 )
return V_8 ;
V_8 = F_21 ( V_17 , V_76 ) ;
if ( ! V_8 )
F_28 ( V_82 , V_76 , & V_80 , NULL , V_17 -> V_89 ) ;
return V_8 ;
}
static int F_30 ( struct V_16 * V_17 , union V_49 * V_50 )
{
void * V_117 ;
T_3 V_54 ;
if ( ! ( V_17 && V_50 ) )
return - 1 ;
V_54 = V_50 -> V_31 . V_42 - sizeof( V_50 -> V_58 ) ;
V_117 = malloc ( V_54 ) ;
if ( ! V_117 )
return - 1 ;
memcpy ( V_117 , & V_50 -> V_58 . V_60 , V_54 ) ;
V_17 -> V_93 = V_117 ;
V_17 -> V_7 = V_50 -> V_58 . V_59 ;
return 0 ;
}
static int
F_31 ( struct V_16 * V_17 )
{
union V_49 * V_50 ;
int V_8 ;
while ( ( V_50 = F_19 ( V_17 ) ) ) {
switch( V_50 -> V_31 . V_53 ) {
case V_64 :
V_8 = F_23 ( V_17 , V_50 ) ;
break;
case V_71 :
V_8 = F_29 ( V_17 , V_50 ) ;
break;
case V_57 :
V_8 = F_30 ( V_17 , V_50 ) ;
break;
default:
V_8 = 0 ;
continue;
}
}
return V_8 ;
}
static int
F_32 ( struct V_16 * V_17 , char * V_118 )
{
int V_8 ;
if ( V_10 > 0 )
fprintf ( V_11 , L_10 , V_118 ) ;
V_8 = F_11 ( V_17 , V_118 ) ;
if ( V_8 )
return - 1 ;
V_8 = F_31 ( V_17 ) ;
F_7 ( V_17 ) ;
if ( V_10 > 0 )
fprintf ( V_11 , L_11 , V_118 , V_8 ) ;
return 0 ;
}
static int
F_33 ( char * V_119 , T_7 V_43 )
{
char * V_88 ;
char * V_120 = NULL ;
T_7 V_121 ;
if ( V_10 > 2 )
fprintf ( V_11 , L_12 , V_119 ) ;
V_88 = strrchr ( V_119 , '/' ) ;
if ( ! V_88 )
return - 1 ;
if ( strncmp ( V_88 , L_13 , 5 ) )
return - 1 ;
V_88 += 5 ;
if ( ! isdigit ( * V_88 ) )
return - 1 ;
V_121 = ( int ) strtol ( V_88 , & V_120 , 10 ) ;
if ( ! V_120 )
return - 1 ;
if ( V_43 && V_121 != V_43 )
return - 1 ;
if ( strcmp ( V_120 , L_14 ) )
return - 1 ;
if ( V_10 > 0 )
fprintf ( V_11 , L_15 , V_119 ) ;
return 0 ;
}
int
F_34 ( struct V_19 * V_20 ,
struct V_122 * V_77 ,
struct V_89 * V_89 ,
char * V_1 ,
T_7 V_43 ,
T_9 * V_123 )
{
struct V_21 * V_124 ;
struct V_16 V_17 ;
int V_8 ;
if ( F_33 ( V_1 , V_43 ) )
return 0 ;
memset ( & V_17 , 0 , sizeof( V_17 ) ) ;
V_17 . V_20 = V_20 ;
V_17 . V_77 = V_77 ;
V_17 . V_89 = V_89 ;
V_124 = F_35 ( V_20 -> V_125 ) ;
V_17 . V_111 = V_124 -> V_23 . V_111 ;
* V_123 = 0 ;
V_8 = F_32 ( & V_17 , V_1 ) ;
if ( ! V_8 ) {
* V_123 = V_17 . V_78 ;
V_8 = 1 ;
}
return V_8 ;
}
