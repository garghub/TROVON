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
V_17 -> V_47 = V_29 . V_46 & V_48 ;
if ( V_10 > 2 )
F_16 ( L_4 ,
V_29 . V_41 ,
V_29 . V_42 ,
( unsigned long long ) V_29 . V_45 ,
V_29 . V_43 ,
V_29 . V_44 ,
V_17 -> V_47 ) ;
if ( V_29 . V_46 & V_49 ) {
F_17 ( L_5 ,
( unsigned long long ) V_29 . V_46 & V_49 ) ;
goto error;
}
if ( V_17 -> V_47 && ! V_17 -> V_20 -> V_50 . V_51 ) {
F_17 ( L_6 ) ;
goto error;
}
if ( ! V_17 -> V_47 && F_9 ( V_17 -> V_20 ) ) {
F_17 ( L_7 ) ;
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
strcpy ( V_17 -> V_52 , V_27 ) ;
F_18 ( V_17 -> V_52 ) ;
return 0 ;
error:
F_8 ( V_17 -> V_18 ) ;
fclose ( V_17 -> V_18 ) ;
return V_36 ;
}
static union V_53 *
F_19 ( struct V_16 * V_17 )
{
struct V_30 * V_31 ;
union V_53 * V_54 ;
void * V_55 ;
T_3 V_32 , V_56 ;
int V_57 , V_8 ;
if ( ! ( V_17 && V_17 -> V_18 ) )
return NULL ;
if ( V_17 -> V_35 == NULL ) {
T_3 V_58 = F_20 () ;
if ( V_58 < sizeof( * V_31 ) )
V_58 = sizeof( * V_31 ) ;
V_17 -> V_35 = malloc ( V_58 ) ;
if ( V_17 -> V_35 == NULL )
return NULL ;
V_17 -> V_59 = V_58 ;
}
V_31 = V_17 -> V_35 ;
V_8 = fread ( V_31 , sizeof( * V_31 ) , 1 , V_17 -> V_18 ) ;
if ( V_8 != 1 )
return NULL ;
if ( V_17 -> V_40 ) {
V_31 -> V_57 = F_14 ( V_31 -> V_57 ) ;
V_31 -> V_42 = F_14 ( V_31 -> V_42 ) ;
V_31 -> V_45 = F_15 ( V_31 -> V_45 ) ;
}
V_57 = V_31 -> V_57 ;
V_56 = V_31 -> V_42 ;
V_32 = ( T_3 ) V_56 ;
if ( V_32 < sizeof( * V_31 ) )
return NULL ;
if ( V_57 >= V_60 ) {
F_3 ( L_8 , V_57 ) ;
return NULL ;
}
if ( V_32 > V_17 -> V_59 ) {
void * V_34 ;
V_34 = realloc ( V_17 -> V_35 , V_32 ) ;
if ( ! V_34 )
return NULL ;
V_17 -> V_35 = V_34 ;
V_17 -> V_59 = V_32 ;
}
V_55 = ( ( void * ) V_17 -> V_35 ) + sizeof( * V_31 ) ;
V_8 = fread ( V_55 , V_32 - sizeof( * V_31 ) , 1 , V_17 -> V_18 ) ;
if ( V_8 != 1 )
return NULL ;
V_54 = (union V_53 * ) V_17 -> V_35 ;
switch( V_57 ) {
case V_61 :
if ( V_17 -> V_40 ) {
T_1 V_34 ;
V_54 -> V_62 . V_3 = F_15 ( V_54 -> V_62 . V_3 ) ;
V_54 -> V_62 . V_63 = F_15 ( V_54 -> V_62 . V_63 ) ;
for ( V_34 = 0 ; V_34 < V_54 -> V_62 . V_63 ; V_34 ++ ) {
V_54 -> V_62 . V_64 [ V_34 ] . V_55 = F_15 ( V_54 -> V_62 . V_64 [ V_34 ] . V_55 ) ;
V_54 -> V_62 . V_64 [ V_34 ] . V_65 = F_14 ( V_54 -> V_62 . V_64 [ V_34 ] . V_65 ) ;
V_54 -> V_62 . V_64 [ V_34 ] . V_66 = F_14 ( V_54 -> V_62 . V_64 [ V_34 ] . V_66 ) ;
}
}
break;
case V_67 :
break;
case V_68 :
if ( V_17 -> V_40 ) {
V_54 -> V_69 . V_43 = F_14 ( V_54 -> V_69 . V_43 ) ;
V_54 -> V_69 . V_70 = F_14 ( V_54 -> V_69 . V_70 ) ;
V_54 -> V_69 . V_71 = F_15 ( V_54 -> V_69 . V_71 ) ;
V_54 -> V_69 . V_3 = F_15 ( V_54 -> V_69 . V_3 ) ;
V_54 -> V_69 . V_72 = F_15 ( V_54 -> V_69 . V_72 ) ;
V_54 -> V_69 . V_73 = F_15 ( V_54 -> V_69 . V_73 ) ;
}
V_17 -> V_74 ++ ;
break;
case V_75 :
if ( V_17 -> V_40 ) {
V_54 -> V_76 . V_43 = F_14 ( V_54 -> V_76 . V_43 ) ;
V_54 -> V_76 . V_70 = F_14 ( V_54 -> V_76 . V_70 ) ;
V_54 -> V_76 . V_71 = F_15 ( V_54 -> V_76 . V_71 ) ;
V_54 -> V_76 . V_77 = F_15 ( V_54 -> V_76 . V_77 ) ;
V_54 -> V_76 . V_78 = F_15 ( V_54 -> V_76 . V_78 ) ;
V_54 -> V_76 . V_72 = F_15 ( V_54 -> V_76 . V_72 ) ;
V_54 -> V_76 . V_73 = F_15 ( V_54 -> V_76 . V_73 ) ;
}
break;
case V_60 :
default:
return NULL ;
}
return V_54 ;
}
static int
F_21 ( struct V_16 * V_17 , union V_79 * V_80 )
{
T_2 V_56 ;
V_56 = F_22 ( V_17 -> V_81 , V_80 , V_80 -> V_29 . V_56 ) ;
if ( V_56 < 0 )
return - 1 ;
V_17 -> V_82 += V_56 ;
return 0 ;
}
static T_1 F_23 ( struct V_16 * V_17 , T_1 V_45 )
{
struct V_83 V_84 ;
if ( ! V_17 -> V_47 )
return V_45 ;
V_84 . V_85 = V_17 -> V_20 -> V_50 . V_85 ;
V_84 . V_51 = V_17 -> V_20 -> V_50 . V_51 ;
V_84 . V_86 = V_17 -> V_20 -> V_50 . V_86 ;
if ( ! V_84 . V_51 )
return 0 ;
return F_24 ( V_45 , & V_84 ) ;
}
static int F_25 ( struct V_16 * V_17 , union V_53 * V_54 )
{
struct V_87 V_88 ;
union V_79 * V_80 ;
struct V_89 * V_90 = V_17 -> V_20 -> V_90 ;
T_1 V_4 , V_55 ;
T_4 V_91 ;
char * V_1 ;
struct V_92 V_93 ;
T_3 V_56 ;
T_5 V_94 ;
const char * V_2 ;
T_6 V_95 ;
int V_8 , V_5 ;
T_7 V_43 , V_70 ;
struct {
T_8 V_43 , V_70 ;
T_9 time ;
} * V_57 ;
V_43 = V_54 -> V_69 . V_43 ;
V_70 = V_54 -> V_69 . V_70 ;
V_5 = V_54 -> V_69 . V_72 ;
V_55 = V_54 -> V_69 . V_3 ;
V_2 = ( void * ) ( ( unsigned long ) V_54 + sizeof( V_54 -> V_69 ) ) ;
V_4 = ( unsigned long ) V_54 + V_54 -> V_69 . V_96 . V_42 - V_5 ;
V_95 = V_54 -> V_69 . V_73 ;
V_94 = V_17 -> V_97 -> V_98 ;
V_80 = calloc ( 1 , sizeof( * V_80 ) + V_94 ) ;
if ( ! V_80 )
return - 1 ;
V_1 = V_80 -> V_99 . V_1 ;
V_56 = snprintf ( V_1 , V_100 , L_9 ,
V_17 -> V_52 ,
V_43 ,
V_95 ) ;
V_56 ++ ;
V_56 = F_26 ( V_56 , sizeof( T_9 ) ) ;
V_91 = ( T_4 ) V_4 ;
V_8 = F_1 ( V_1 , V_2 , V_55 , ( const void * ) V_91 , V_5 , V_17 -> V_101 , V_17 -> V_7 ) ;
if ( V_17 -> V_101 && V_17 -> V_7 ) {
free ( V_17 -> V_101 ) ;
V_17 -> V_101 = NULL ;
V_17 -> V_7 = 0 ;
}
if ( V_8 ) {
free ( V_80 ) ;
return - 1 ;
}
if ( V_92 ( V_1 , & V_93 ) )
memset ( & V_93 , 0 , sizeof( V_93 ) ) ;
V_80 -> V_99 . V_29 . type = V_102 ;
V_80 -> V_99 . V_29 . V_103 = V_104 ;
V_80 -> V_99 . V_29 . V_56 = ( sizeof( V_80 -> V_99 ) -
( sizeof( V_80 -> V_99 . V_1 ) - V_56 ) + V_94 ) ;
V_80 -> V_99 . V_105 = V_106 ;
V_80 -> V_99 . V_107 = V_55 ;
V_80 -> V_99 . V_108 = V_5 ;
V_80 -> V_99 . V_43 = V_43 ;
V_80 -> V_99 . V_70 = V_70 ;
V_80 -> V_99 . V_109 = V_93 . V_110 ;
V_80 -> V_99 . V_111 = F_27 ( V_93 . V_112 ) ;
V_80 -> V_99 . V_113 = F_28 ( V_93 . V_112 ) ;
V_80 -> V_99 . V_114 = V_93 . V_115 ;
V_80 -> V_99 . V_46 = V_116 ;
V_80 -> V_99 . V_117 = 1 ;
V_57 = ( void * ) ( ( unsigned long ) V_80 + V_80 -> V_118 . V_29 . V_56 - V_94 ) ;
if ( V_17 -> V_119 & V_120 ) {
V_57 -> V_43 = V_43 ;
V_57 -> V_70 = V_70 ;
}
if ( V_17 -> V_119 & V_121 )
V_57 -> time = F_23 ( V_17 , V_54 -> V_69 . V_96 . V_45 ) ;
memset ( & V_88 , 0 , sizeof( V_88 ) ) ;
V_88 . V_122 = V_104 ;
V_88 . V_43 = V_43 ;
V_88 . V_70 = V_70 ;
V_88 . time = V_57 -> time ;
V_88 . V_123 = V_55 ;
V_8 = F_29 ( V_90 , V_80 , & V_88 , V_17 -> V_97 ) ;
if ( V_8 )
return V_8 ;
V_8 = F_21 ( V_17 , V_80 ) ;
if ( ! V_8 )
F_30 ( V_90 , V_80 , & V_88 , NULL , V_17 -> V_97 ) ;
return V_8 ;
}
static int F_31 ( struct V_16 * V_17 , union V_53 * V_54 )
{
struct V_87 V_88 ;
union V_79 * V_80 ;
struct V_89 * V_90 = V_17 -> V_20 -> V_90 ;
char * V_1 ;
T_3 V_56 ;
struct V_92 V_93 ;
T_5 V_94 ;
int V_8 ;
T_7 V_43 , V_70 ;
struct {
T_8 V_43 , V_70 ;
T_9 time ;
} * V_57 ;
V_43 = V_54 -> V_76 . V_43 ;
V_70 = V_54 -> V_76 . V_70 ;
V_94 = V_17 -> V_97 -> V_98 ;
V_80 = calloc ( 1 , sizeof( * V_80 ) + 16 ) ;
if ( ! V_80 )
return - 1 ;
V_1 = V_80 -> V_99 . V_1 ;
V_56 = snprintf ( V_1 , V_100 , L_10 V_124 ,
V_17 -> V_52 ,
V_43 ,
V_54 -> V_76 . V_73 ) ;
V_56 ++ ;
if ( V_92 ( V_1 , & V_93 ) )
memset ( & V_93 , 0 , sizeof( V_93 ) ) ;
V_56 = F_26 ( V_56 , sizeof( T_9 ) ) ;
V_80 -> V_99 . V_29 . type = V_102 ;
V_80 -> V_99 . V_29 . V_103 = V_104 ;
V_80 -> V_99 . V_29 . V_56 = ( sizeof( V_80 -> V_99 ) -
( sizeof( V_80 -> V_99 . V_1 ) - V_56 ) + V_94 ) ;
V_80 -> V_99 . V_105 = V_106 ;
V_80 -> V_99 . V_107 = V_54 -> V_76 . V_78 ;
V_80 -> V_99 . V_108 = V_54 -> V_76 . V_72 ;
V_80 -> V_99 . V_43 = V_43 ;
V_80 -> V_99 . V_70 = V_70 ;
V_80 -> V_99 . V_109 = V_93 . V_110 ;
V_80 -> V_99 . V_111 = F_27 ( V_93 . V_112 ) ;
V_80 -> V_99 . V_113 = F_28 ( V_93 . V_112 ) ;
V_80 -> V_99 . V_114 = V_93 . V_115 ;
V_80 -> V_99 . V_46 = V_116 ;
V_80 -> V_99 . V_117 = 1 ;
V_57 = ( void * ) ( ( unsigned long ) V_80 + V_80 -> V_118 . V_29 . V_56 - V_94 ) ;
if ( V_17 -> V_119 & V_120 ) {
V_57 -> V_43 = V_43 ;
V_57 -> V_70 = V_70 ;
}
if ( V_17 -> V_119 & V_121 )
V_57 -> time = F_23 ( V_17 , V_54 -> V_69 . V_96 . V_45 ) ;
memset ( & V_88 , 0 , sizeof( V_88 ) ) ;
V_88 . V_122 = V_104 ;
V_88 . V_43 = V_43 ;
V_88 . V_70 = V_70 ;
V_88 . time = V_57 -> time ;
V_88 . V_123 = V_54 -> V_76 . V_78 ;
V_8 = F_29 ( V_90 , V_80 , & V_88 , V_17 -> V_97 ) ;
if ( V_8 )
return V_8 ;
V_8 = F_21 ( V_17 , V_80 ) ;
if ( ! V_8 )
F_30 ( V_90 , V_80 , & V_88 , NULL , V_17 -> V_97 ) ;
return V_8 ;
}
static int F_32 ( struct V_16 * V_17 , union V_53 * V_54 )
{
void * V_125 ;
T_3 V_58 ;
if ( ! ( V_17 && V_54 ) )
return - 1 ;
V_58 = V_54 -> V_31 . V_42 - sizeof( V_54 -> V_62 ) ;
V_125 = malloc ( V_58 ) ;
if ( ! V_125 )
return - 1 ;
memcpy ( V_125 , & V_54 -> V_62 . V_64 , V_58 ) ;
V_17 -> V_101 = V_125 ;
V_17 -> V_7 = V_54 -> V_62 . V_63 ;
return 0 ;
}
static int
F_33 ( struct V_16 * V_17 )
{
union V_53 * V_54 ;
int V_8 ;
while ( ( V_54 = F_19 ( V_17 ) ) ) {
switch( V_54 -> V_31 . V_57 ) {
case V_68 :
V_8 = F_25 ( V_17 , V_54 ) ;
break;
case V_75 :
V_8 = F_31 ( V_17 , V_54 ) ;
break;
case V_61 :
V_8 = F_32 ( V_17 , V_54 ) ;
break;
default:
V_8 = 0 ;
continue;
}
}
return V_8 ;
}
static int
F_34 ( struct V_16 * V_17 , char * V_126 )
{
int V_8 ;
if ( V_10 > 0 )
fprintf ( V_11 , L_11 , V_126 ) ;
V_8 = F_11 ( V_17 , V_126 ) ;
if ( V_8 )
return - 1 ;
V_8 = F_33 ( V_17 ) ;
F_7 ( V_17 ) ;
if ( V_10 > 0 )
fprintf ( V_11 , L_12 , V_126 , V_8 ) ;
return 0 ;
}
static int
F_35 ( char * V_127 , T_7 V_43 )
{
char * V_96 ;
char * V_128 = NULL ;
T_7 V_129 ;
if ( V_10 > 2 )
fprintf ( V_11 , L_13 , V_127 ) ;
V_96 = strrchr ( V_127 , '/' ) ;
if ( ! V_96 )
return - 1 ;
if ( strncmp ( V_96 , L_14 , 5 ) )
return - 1 ;
V_96 += 5 ;
if ( ! isdigit ( * V_96 ) )
return - 1 ;
V_129 = ( int ) strtol ( V_96 , & V_128 , 10 ) ;
if ( ! V_128 )
return - 1 ;
if ( V_43 && V_129 != V_43 )
return - 1 ;
if ( strcmp ( V_128 , L_15 ) )
return - 1 ;
if ( V_10 > 0 )
fprintf ( V_11 , L_16 , V_127 ) ;
return 0 ;
}
int
F_36 ( struct V_19 * V_20 ,
struct V_130 * V_81 ,
struct V_97 * V_97 ,
char * V_1 ,
T_7 V_43 ,
T_9 * V_131 )
{
struct V_21 * V_132 ;
struct V_16 V_17 ;
int V_8 ;
if ( F_35 ( V_1 , V_43 ) )
return 0 ;
memset ( & V_17 , 0 , sizeof( V_17 ) ) ;
V_17 . V_20 = V_20 ;
V_17 . V_81 = V_81 ;
V_17 . V_97 = V_97 ;
V_132 = F_37 ( V_20 -> V_133 ) ;
V_17 . V_119 = V_132 -> V_23 . V_119 ;
* V_131 = 0 ;
V_8 = F_34 ( & V_17 , V_1 ) ;
if ( ! V_8 ) {
* V_131 = V_17 . V_82 ;
V_8 = 1 ;
}
return V_8 ;
}
