static int
F_1 ( char * V_1 ,
const char * V_2 ,
T_1 V_3 ,
const void * V_4 ,
int V_5 ,
void * V_6 ,
int V_7 ,
void * V_8 ,
T_2 V_9 ,
T_2 V_10 )
{
int V_11 , V_12 ;
if ( V_13 > 0 )
fprintf ( V_14 , L_1 , V_1 ) ;
V_12 = F_2 ( V_1 , V_15 | V_16 | V_17 , 0644 ) ;
if ( V_12 == - 1 ) {
F_3 ( L_2 , V_1 , strerror ( V_18 ) ) ;
return - 1 ;
}
V_11 = F_4 ( V_12 , V_3 , V_2 , ( const void * ) V_4 , V_5 , V_6 , V_7 ,
V_8 , V_9 , V_10 ) ;
F_5 ( V_12 ) ;
if ( V_11 )
F_6 ( V_1 ) ;
return V_11 ;
}
static void
F_7 ( struct V_19 * V_20 )
{
if ( ! ( V_20 && V_20 -> V_21 ) )
return;
F_8 ( V_20 -> V_21 ) ;
fclose ( V_20 -> V_21 ) ;
V_20 -> V_21 = NULL ;
}
static int
F_9 ( struct V_22 * V_23 )
{
struct V_24 * V_25 ;
F_10 (session->evlist, evsel) {
if ( V_25 -> V_26 . V_27 == 0 || V_25 -> V_26 . V_28 != V_29 )
return - 1 ;
}
return 0 ;
}
static int
F_11 ( struct V_19 * V_20 , const char * V_30 )
{
struct V_31 V_32 ;
struct V_33 * V_34 ;
T_3 V_35 , V_36 = 0 ;
void * V_37 , * V_38 = NULL ;
int V_11 , V_39 = - 1 ;
V_20 -> V_21 = fopen ( V_30 , L_3 ) ;
if ( ! V_20 -> V_21 )
return - 1 ;
V_36 = F_12 ( sizeof( V_32 ) , sizeof( * V_34 ) ) ;
V_38 = malloc ( V_36 ) ;
if ( ! V_38 )
goto error;
F_13 ( V_20 -> V_21 ) ;
V_11 = fread ( V_38 , sizeof( V_32 ) , 1 , V_20 -> V_21 ) ;
if ( V_11 != 1 )
goto error;
memcpy ( & V_32 , V_38 , sizeof( V_32 ) ) ;
if ( V_32 . V_40 != V_41 ) {
if ( V_32 . V_40 != V_42 )
goto error;
V_20 -> V_43 = true ;
}
if ( V_20 -> V_43 ) {
V_32 . V_44 = F_14 ( V_32 . V_44 ) ;
V_32 . V_45 = F_14 ( V_32 . V_45 ) ;
V_32 . V_46 = F_14 ( V_32 . V_46 ) ;
V_32 . V_47 = F_14 ( V_32 . V_47 ) ;
V_32 . V_48 = F_15 ( V_32 . V_48 ) ;
V_32 . V_49 = F_15 ( V_32 . V_49 ) ;
}
V_20 -> V_50 = V_32 . V_49 & V_51 ;
if ( V_13 > 2 )
F_16 ( L_4 ,
V_32 . V_44 ,
V_32 . V_45 ,
( unsigned long long ) V_32 . V_48 ,
V_32 . V_46 ,
V_32 . V_47 ,
V_20 -> V_50 ) ;
if ( V_32 . V_44 > V_52 ) {
F_17 ( L_5 F_18 ( V_52 ) ,
V_32 . V_44 ) ;
goto error;
}
if ( V_32 . V_49 & V_53 ) {
F_17 ( L_6 ,
( unsigned long long ) V_32 . V_49 & V_53 ) ;
goto error;
}
if ( V_20 -> V_50 && ! V_20 -> V_23 -> V_54 . V_55 ) {
F_17 ( L_7 ) ;
goto error;
}
if ( ! V_20 -> V_50 && F_9 ( V_20 -> V_23 ) ) {
F_17 ( L_8 ) ;
goto error;
}
V_35 = V_32 . V_45 - sizeof( V_32 ) ;
if ( V_35 > V_36 ) {
V_37 = realloc ( V_38 , V_35 ) ;
if ( ! V_37 )
goto error;
V_36 = V_35 ;
V_38 = V_37 ;
V_11 = fread ( V_38 , V_35 - V_36 , 1 , V_20 -> V_21 ) ;
if ( V_11 != 1 )
goto error;
}
strcpy ( V_20 -> V_56 , V_30 ) ;
F_19 ( V_20 -> V_56 ) ;
return 0 ;
error:
F_8 ( V_20 -> V_21 ) ;
fclose ( V_20 -> V_21 ) ;
return V_39 ;
}
static union V_57 *
F_20 ( struct V_19 * V_20 )
{
struct V_33 * V_34 ;
union V_57 * V_58 ;
void * V_59 ;
T_4 V_35 , V_60 ;
int V_61 , V_11 ;
if ( ! ( V_20 && V_20 -> V_21 ) )
return NULL ;
if ( V_20 -> V_38 == NULL ) {
T_4 V_62 = F_21 () ;
if ( V_62 < sizeof( * V_34 ) )
V_62 = sizeof( * V_34 ) ;
V_20 -> V_38 = malloc ( V_62 ) ;
if ( V_20 -> V_38 == NULL )
return NULL ;
V_20 -> V_63 = V_62 ;
}
V_34 = V_20 -> V_38 ;
V_11 = fread ( V_34 , sizeof( * V_34 ) , 1 , V_20 -> V_21 ) ;
if ( V_11 != 1 )
return NULL ;
if ( V_20 -> V_43 ) {
V_34 -> V_61 = F_14 ( V_34 -> V_61 ) ;
V_34 -> V_45 = F_14 ( V_34 -> V_45 ) ;
V_34 -> V_48 = F_15 ( V_34 -> V_48 ) ;
}
V_61 = V_34 -> V_61 ;
V_60 = V_34 -> V_45 ;
V_35 = ( T_4 ) V_60 ;
if ( V_35 < sizeof( * V_34 ) )
return NULL ;
if ( V_61 >= V_64 ) {
F_3 ( L_9 , V_61 ) ;
}
if ( V_35 > V_20 -> V_63 ) {
void * V_37 ;
V_37 = realloc ( V_20 -> V_38 , V_35 ) ;
if ( ! V_37 )
return NULL ;
V_20 -> V_38 = V_37 ;
V_20 -> V_63 = V_35 ;
}
V_59 = ( ( void * ) V_20 -> V_38 ) + sizeof( * V_34 ) ;
V_11 = fread ( V_59 , V_35 - sizeof( * V_34 ) , 1 , V_20 -> V_21 ) ;
if ( V_11 != 1 )
return NULL ;
V_58 = (union V_57 * ) V_20 -> V_38 ;
switch( V_61 ) {
case V_65 :
if ( V_20 -> V_43 ) {
T_1 V_37 ;
V_58 -> V_66 . V_3 = F_15 ( V_58 -> V_66 . V_3 ) ;
V_58 -> V_66 . V_67 = F_15 ( V_58 -> V_66 . V_67 ) ;
for ( V_37 = 0 ; V_37 < V_58 -> V_66 . V_67 ; V_37 ++ ) {
V_58 -> V_66 . V_68 [ V_37 ] . V_59 = F_15 ( V_58 -> V_66 . V_68 [ V_37 ] . V_59 ) ;
V_58 -> V_66 . V_68 [ V_37 ] . V_69 = F_14 ( V_58 -> V_66 . V_68 [ V_37 ] . V_69 ) ;
V_58 -> V_66 . V_68 [ V_37 ] . V_70 = F_14 ( V_58 -> V_66 . V_68 [ V_37 ] . V_70 ) ;
}
}
break;
case V_71 :
if ( V_20 -> V_43 ) {
V_58 -> V_8 . V_10 = F_15 ( V_58 -> V_8 . V_10 ) ;
V_58 -> V_8 . V_72 = F_15 ( V_58 -> V_8 . V_72 ) ;
V_58 -> V_8 . V_73 = F_15 ( V_58 -> V_8 . V_73 ) ;
}
break;
case V_74 :
break;
case V_75 :
if ( V_20 -> V_43 ) {
V_58 -> V_76 . V_46 = F_14 ( V_58 -> V_76 . V_46 ) ;
V_58 -> V_76 . V_77 = F_14 ( V_58 -> V_76 . V_77 ) ;
V_58 -> V_76 . V_78 = F_15 ( V_58 -> V_76 . V_78 ) ;
V_58 -> V_76 . V_3 = F_15 ( V_58 -> V_76 . V_3 ) ;
V_58 -> V_76 . V_79 = F_15 ( V_58 -> V_76 . V_79 ) ;
V_58 -> V_76 . V_80 = F_15 ( V_58 -> V_76 . V_80 ) ;
}
V_20 -> V_81 ++ ;
break;
case V_82 :
if ( V_20 -> V_43 ) {
V_58 -> V_83 . V_46 = F_14 ( V_58 -> V_83 . V_46 ) ;
V_58 -> V_83 . V_77 = F_14 ( V_58 -> V_83 . V_77 ) ;
V_58 -> V_83 . V_78 = F_15 ( V_58 -> V_83 . V_78 ) ;
V_58 -> V_83 . V_84 = F_15 ( V_58 -> V_83 . V_84 ) ;
V_58 -> V_83 . V_85 = F_15 ( V_58 -> V_83 . V_85 ) ;
V_58 -> V_83 . V_79 = F_15 ( V_58 -> V_83 . V_79 ) ;
V_58 -> V_83 . V_80 = F_15 ( V_58 -> V_83 . V_80 ) ;
}
break;
case V_64 :
default:
break;
}
return V_58 ;
}
static int
F_22 ( struct V_19 * V_20 , union V_86 * V_87 )
{
T_3 V_60 ;
V_60 = F_23 ( V_20 -> V_88 , V_87 , V_87 -> V_32 . V_60 ) ;
if ( V_60 < 0 )
return - 1 ;
V_20 -> V_89 += V_60 ;
return 0 ;
}
static T_1 F_24 ( struct V_19 * V_20 , T_1 V_48 )
{
struct V_90 V_91 ;
if ( ! V_20 -> V_50 )
return V_48 ;
V_91 . V_92 = V_20 -> V_23 -> V_54 . V_92 ;
V_91 . V_55 = V_20 -> V_23 -> V_54 . V_55 ;
V_91 . V_93 = V_20 -> V_23 -> V_54 . V_93 ;
if ( ! V_91 . V_55 )
return 0 ;
return F_25 ( V_48 , & V_91 ) ;
}
static int F_26 ( struct V_19 * V_20 , union V_57 * V_58 )
{
struct V_94 V_95 ;
union V_86 * V_87 ;
struct V_96 * V_97 = V_20 -> V_23 -> V_97 ;
T_1 V_4 , V_59 ;
T_5 V_98 ;
char * V_1 ;
struct V_99 V_100 ;
T_4 V_60 ;
T_6 V_101 ;
const char * V_2 ;
T_2 V_102 ;
int V_11 , V_5 , V_103 ;
T_7 V_46 , V_77 ;
struct {
T_8 V_46 , V_77 ;
T_9 time ;
} * V_61 ;
V_46 = V_58 -> V_76 . V_46 ;
V_77 = V_58 -> V_76 . V_77 ;
V_5 = V_58 -> V_76 . V_79 ;
V_103 = V_20 -> V_104 ;
V_59 = V_58 -> V_76 . V_3 ;
V_2 = ( void * ) ( ( unsigned long ) V_58 + sizeof( V_58 -> V_76 ) ) ;
V_4 = ( unsigned long ) V_58 + V_58 -> V_76 . V_105 . V_45 - V_5 ;
V_102 = V_58 -> V_76 . V_80 ;
V_101 = V_20 -> V_106 -> V_107 ;
V_87 = calloc ( 1 , sizeof( * V_87 ) + V_101 ) ;
if ( ! V_87 )
return - 1 ;
V_1 = V_87 -> V_108 . V_1 ;
V_60 = snprintf ( V_1 , V_109 , L_10 ,
V_20 -> V_56 ,
V_46 ,
V_102 ) ;
V_60 ++ ;
V_60 = F_27 ( V_60 , sizeof( T_9 ) ) ;
V_98 = ( T_5 ) V_4 ;
V_11 = F_1 ( V_1 , V_2 , V_59 , ( const void * ) V_98 , V_5 , V_20 -> V_110 , V_20 -> V_7 ,
V_20 -> V_111 , V_20 -> V_72 , V_20 -> V_10 ) ;
if ( V_20 -> V_110 && V_20 -> V_7 ) {
free ( V_20 -> V_110 ) ;
V_20 -> V_110 = NULL ;
V_20 -> V_7 = 0 ;
}
if ( V_20 -> V_111 && V_20 -> V_72 ) {
free ( V_20 -> V_111 ) ;
V_20 -> V_111 = NULL ;
V_20 -> V_72 = 0 ;
V_20 -> V_104 = 0 ;
V_20 -> V_10 = 0 ;
}
if ( V_11 ) {
free ( V_87 ) ;
return - 1 ;
}
if ( V_99 ( V_1 , & V_100 ) )
memset ( & V_100 , 0 , sizeof( V_100 ) ) ;
V_87 -> V_108 . V_32 . type = V_112 ;
V_87 -> V_108 . V_32 . V_113 = V_114 ;
V_87 -> V_108 . V_32 . V_60 = ( sizeof( V_87 -> V_108 ) -
( sizeof( V_87 -> V_108 . V_1 ) - V_60 ) + V_101 ) ;
V_87 -> V_108 . V_115 = V_116 ;
V_87 -> V_108 . V_117 = V_59 ;
V_87 -> V_108 . V_118 = V_103 ? F_28 ( V_5 ) + V_103 : V_5 ;
V_87 -> V_108 . V_46 = V_46 ;
V_87 -> V_108 . V_77 = V_77 ;
V_87 -> V_108 . V_119 = V_100 . V_120 ;
V_87 -> V_108 . V_121 = F_29 ( V_100 . V_122 ) ;
V_87 -> V_108 . V_123 = F_30 ( V_100 . V_122 ) ;
V_87 -> V_108 . V_124 = V_100 . V_125 ;
V_87 -> V_108 . V_49 = V_126 ;
V_87 -> V_108 . V_127 = 1 ;
V_61 = ( void * ) ( ( unsigned long ) V_87 + V_87 -> V_128 . V_32 . V_60 - V_101 ) ;
if ( V_20 -> V_129 & V_130 ) {
V_61 -> V_46 = V_46 ;
V_61 -> V_77 = V_77 ;
}
if ( V_20 -> V_129 & V_131 )
V_61 -> time = F_24 ( V_20 , V_58 -> V_76 . V_105 . V_48 ) ;
memset ( & V_95 , 0 , sizeof( V_95 ) ) ;
V_95 . V_132 = V_114 ;
V_95 . V_46 = V_46 ;
V_95 . V_77 = V_77 ;
V_95 . time = V_61 -> time ;
V_95 . V_133 = V_59 ;
V_11 = F_31 ( V_97 , V_87 , & V_95 , V_20 -> V_106 ) ;
if ( V_11 )
return V_11 ;
V_11 = F_22 ( V_20 , V_87 ) ;
if ( ! V_11 )
F_32 ( V_97 , V_87 , & V_95 , NULL , V_20 -> V_106 ) ;
return V_11 ;
}
static int F_33 ( struct V_19 * V_20 , union V_57 * V_58 )
{
struct V_94 V_95 ;
union V_86 * V_87 ;
struct V_96 * V_97 = V_20 -> V_23 -> V_97 ;
char * V_1 ;
T_4 V_60 ;
struct V_99 V_100 ;
int V_103 ;
T_6 V_101 ;
int V_11 ;
T_7 V_46 , V_77 ;
struct {
T_8 V_46 , V_77 ;
T_9 time ;
} * V_61 ;
V_46 = V_58 -> V_83 . V_46 ;
V_77 = V_58 -> V_83 . V_77 ;
V_103 = V_20 -> V_104 ;
V_101 = V_20 -> V_106 -> V_107 ;
V_87 = calloc ( 1 , sizeof( * V_87 ) + 16 ) ;
if ( ! V_87 )
return - 1 ;
V_1 = V_87 -> V_108 . V_1 ;
V_60 = snprintf ( V_1 , V_109 , L_11 V_134 ,
V_20 -> V_56 ,
V_46 ,
V_58 -> V_83 . V_80 ) ;
V_60 ++ ;
if ( V_99 ( V_1 , & V_100 ) )
memset ( & V_100 , 0 , sizeof( V_100 ) ) ;
V_60 = F_27 ( V_60 , sizeof( T_9 ) ) ;
V_87 -> V_108 . V_32 . type = V_112 ;
V_87 -> V_108 . V_32 . V_113 = V_114 ;
V_87 -> V_108 . V_32 . V_60 = ( sizeof( V_87 -> V_108 ) -
( sizeof( V_87 -> V_108 . V_1 ) - V_60 ) + V_101 ) ;
V_87 -> V_108 . V_115 = V_116 ;
V_87 -> V_108 . V_117 = V_58 -> V_83 . V_85 ;
V_87 -> V_108 . V_118 = V_103 ? F_28 ( V_58 -> V_83 . V_79 ) + V_103
: V_58 -> V_83 . V_79 ;
V_87 -> V_108 . V_46 = V_46 ;
V_87 -> V_108 . V_77 = V_77 ;
V_87 -> V_108 . V_119 = V_100 . V_120 ;
V_87 -> V_108 . V_121 = F_29 ( V_100 . V_122 ) ;
V_87 -> V_108 . V_123 = F_30 ( V_100 . V_122 ) ;
V_87 -> V_108 . V_124 = V_100 . V_125 ;
V_87 -> V_108 . V_49 = V_126 ;
V_87 -> V_108 . V_127 = 1 ;
V_61 = ( void * ) ( ( unsigned long ) V_87 + V_87 -> V_128 . V_32 . V_60 - V_101 ) ;
if ( V_20 -> V_129 & V_130 ) {
V_61 -> V_46 = V_46 ;
V_61 -> V_77 = V_77 ;
}
if ( V_20 -> V_129 & V_131 )
V_61 -> time = F_24 ( V_20 , V_58 -> V_76 . V_105 . V_48 ) ;
memset ( & V_95 , 0 , sizeof( V_95 ) ) ;
V_95 . V_132 = V_114 ;
V_95 . V_46 = V_46 ;
V_95 . V_77 = V_77 ;
V_95 . time = V_61 -> time ;
V_95 . V_133 = V_58 -> V_83 . V_85 ;
V_11 = F_31 ( V_97 , V_87 , & V_95 , V_20 -> V_106 ) ;
if ( V_11 )
return V_11 ;
V_11 = F_22 ( V_20 , V_87 ) ;
if ( ! V_11 )
F_32 ( V_97 , V_87 , & V_95 , NULL , V_20 -> V_106 ) ;
return V_11 ;
}
static int F_34 ( struct V_19 * V_20 , union V_57 * V_58 )
{
void * V_135 ;
T_4 V_62 ;
if ( ! ( V_20 && V_58 ) )
return - 1 ;
V_62 = V_58 -> V_34 . V_45 - sizeof( V_58 -> V_66 ) ;
V_135 = malloc ( V_62 ) ;
if ( ! V_135 )
return - 1 ;
memcpy ( V_135 , & V_58 -> V_66 . V_68 , V_62 ) ;
V_20 -> V_110 = V_135 ;
V_20 -> V_7 = V_58 -> V_66 . V_67 ;
return 0 ;
}
static int
F_35 ( struct V_19 * V_20 , union V_57 * V_58 )
{
void * V_111 ;
T_2 V_136 ;
if ( ! ( V_20 && V_58 ) )
return - 1 ;
V_136 = V_58 -> V_34 . V_45 - sizeof( V_58 -> V_8 ) ;
V_111 = malloc ( V_136 ) ;
if ( ! V_111 )
return - 1 ;
memcpy ( V_111 , & V_58 -> V_8 . V_111 ,
V_136 ) ;
V_20 -> V_72 = V_58 -> V_8 . V_72 ;
V_20 -> V_10 = V_58 -> V_8 . V_10 ;
V_20 -> V_104 = V_58 -> V_8 . V_73 ;
V_20 -> V_111 = V_111 ;
return 0 ;
}
static int
F_36 ( struct V_19 * V_20 )
{
union V_57 * V_58 ;
int V_11 = 0 ;
while ( ( V_58 = F_20 ( V_20 ) ) ) {
switch( V_58 -> V_34 . V_61 ) {
case V_75 :
V_11 = F_26 ( V_20 , V_58 ) ;
break;
case V_82 :
V_11 = F_33 ( V_20 , V_58 ) ;
break;
case V_65 :
V_11 = F_34 ( V_20 , V_58 ) ;
break;
case V_71 :
V_11 = F_35 ( V_20 , V_58 ) ;
break;
default:
V_11 = 0 ;
continue;
}
}
return V_11 ;
}
static int
F_37 ( struct V_19 * V_20 , char * V_137 )
{
int V_11 ;
if ( V_13 > 0 )
fprintf ( V_14 , L_12 , V_137 ) ;
V_11 = F_11 ( V_20 , V_137 ) ;
if ( V_11 )
return - 1 ;
V_11 = F_36 ( V_20 ) ;
F_7 ( V_20 ) ;
if ( V_13 > 0 )
fprintf ( V_14 , L_13 , V_137 , V_11 ) ;
return 0 ;
}
static int
F_38 ( char * V_138 , T_7 V_46 )
{
char * V_105 ;
char * V_139 = NULL ;
T_7 V_140 ;
if ( V_13 > 2 )
fprintf ( V_14 , L_14 , V_138 ) ;
V_105 = strrchr ( V_138 , '/' ) ;
if ( ! V_105 )
return - 1 ;
if ( strncmp ( V_105 , L_15 , 5 ) )
return - 1 ;
V_105 += 5 ;
if ( ! isdigit ( * V_105 ) )
return - 1 ;
V_140 = ( int ) strtol ( V_105 , & V_139 , 10 ) ;
if ( ! V_139 )
return - 1 ;
if ( V_46 && V_140 != V_46 )
return - 1 ;
if ( strcmp ( V_139 , L_16 ) )
return - 1 ;
if ( V_13 > 0 )
fprintf ( V_14 , L_17 , V_138 ) ;
return 0 ;
}
int
F_39 ( struct V_22 * V_23 ,
struct V_141 * V_88 ,
struct V_106 * V_106 ,
char * V_1 ,
T_7 V_46 ,
T_9 * V_142 )
{
struct V_24 * V_143 ;
struct V_19 V_20 ;
int V_11 ;
if ( F_38 ( V_1 , V_46 ) )
return 0 ;
memset ( & V_20 , 0 , sizeof( V_20 ) ) ;
V_20 . V_23 = V_23 ;
V_20 . V_88 = V_88 ;
V_20 . V_106 = V_106 ;
V_143 = F_40 ( V_23 -> V_144 ) ;
V_20 . V_129 = V_143 -> V_26 . V_129 ;
* V_142 = 0 ;
V_11 = F_37 ( & V_20 , V_1 ) ;
if ( ! V_11 ) {
* V_142 = V_20 . V_89 ;
V_11 = 1 ;
}
return V_11 ;
}
