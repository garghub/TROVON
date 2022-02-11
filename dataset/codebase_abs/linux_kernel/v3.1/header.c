int F_1 ( T_1 V_1 , const char * V_2 )
{
if ( strlen ( V_2 ) > V_3 )
F_2 ( L_1 , V_2 ) ;
if ( ! V_4 ) {
V_4 = malloc ( sizeof( struct V_5 ) ) ;
if ( V_4 == NULL )
return - V_6 ;
} else {
struct V_5 * V_7 ;
V_7 = realloc ( V_4 , ( V_8 + 1 ) * sizeof( * V_4 ) ) ;
if ( V_7 == NULL )
return - V_6 ;
V_4 = V_7 ;
}
memset ( & V_4 [ V_8 ] , 0 , sizeof( struct V_5 ) ) ;
V_4 [ V_8 ] . V_9 = V_1 ;
strncpy ( V_4 [ V_8 ] . V_2 , V_2 , V_3 - 1 ) ;
V_8 ++ ;
return 0 ;
}
char * F_3 ( T_1 V_1 )
{
int V_10 ;
for ( V_10 = 0 ; V_10 < V_8 ; V_10 ++ ) {
if ( V_4 [ V_10 ] . V_9 == V_1 )
return V_4 [ V_10 ] . V_2 ;
}
return NULL ;
}
void F_4 ( struct V_11 * V_12 , int V_13 )
{
F_5 ( V_13 , V_12 -> V_14 ) ;
}
void F_6 ( struct V_11 * V_12 , int V_13 )
{
F_7 ( V_13 , V_12 -> V_14 ) ;
}
bool F_8 ( const struct V_11 * V_12 , int V_13 )
{
return F_9 ( V_13 , V_12 -> V_14 ) ;
}
static int F_10 ( int V_15 , const void * V_16 , T_2 V_17 )
{
while ( V_17 ) {
int V_18 = F_11 ( V_15 , V_16 , V_17 ) ;
if ( V_18 < 0 )
return - V_19 ;
V_17 -= V_18 ;
V_16 += V_18 ;
}
return 0 ;
}
static int F_12 ( int V_15 , const void * V_20 , T_2 V_21 ,
T_2 V_22 )
{
static const char V_23 [ V_24 ] ;
int V_25 = F_10 ( V_15 , V_20 , V_21 ) ;
if ( ! V_25 )
V_25 = F_10 ( V_15 , V_23 , V_22 - V_21 ) ;
return V_25 ;
}
static int F_13 ( struct V_26 * V_27 , T_3 V_28 ,
T_4 V_29 , int V_15 )
{
struct V_30 * V_31 ;
F_14 (pos, head) {
int V_25 ;
struct V_32 V_33 ;
T_2 V_34 ;
if ( ! V_31 -> V_35 )
continue;
V_34 = V_31 -> V_36 + 1 ;
V_34 = F_15 ( V_34 , V_24 ) ;
memset ( & V_33 , 0 , sizeof( V_33 ) ) ;
memcpy ( & V_33 . V_37 , V_31 -> V_37 , sizeof( V_31 -> V_37 ) ) ;
V_33 . V_28 = V_28 ;
V_33 . V_12 . V_29 = V_29 ;
V_33 . V_12 . V_17 = sizeof( V_33 ) + V_34 ;
V_25 = F_10 ( V_15 , & V_33 , sizeof( V_33 ) ) ;
if ( V_25 < 0 )
return V_25 ;
V_25 = F_12 ( V_15 , V_31 -> V_38 ,
V_31 -> V_36 + 1 , V_34 ) ;
if ( V_25 < 0 )
return V_25 ;
}
return 0 ;
}
static int F_16 ( struct V_39 * V_39 , int V_15 )
{
int V_25 ;
T_4 V_40 = V_41 ,
V_42 = V_43 ;
if ( ! F_17 ( V_39 ) ) {
V_40 = V_44 ;
V_42 = V_45 ;
}
V_25 = F_13 ( & V_39 -> V_46 , V_39 -> V_28 ,
V_40 , V_15 ) ;
if ( V_25 == 0 )
V_25 = F_13 ( & V_39 -> V_47 ,
V_39 -> V_28 , V_42 , V_15 ) ;
return V_25 ;
}
static int F_18 ( struct V_11 * V_12 , int V_15 )
{
struct V_48 * V_49 = F_19 ( V_12 ,
struct V_48 , V_12 ) ;
struct V_50 * V_51 ;
int V_25 = F_16 ( & V_49 -> V_52 , V_15 ) ;
if ( V_25 )
return V_25 ;
for ( V_51 = F_20 ( & V_49 -> V_53 ) ; V_51 ; V_51 = F_21 ( V_51 ) ) {
struct V_39 * V_31 = F_22 ( V_51 , struct V_39 , V_50 ) ;
V_25 = F_16 ( V_31 , V_15 ) ;
if ( V_25 )
break;
}
return V_25 ;
}
int F_23 ( const char * V_54 , const char * V_55 ,
const char * V_2 , bool V_56 )
{
const T_2 V_17 = V_57 ;
char * V_58 , * V_59 = F_24 ( V_17 ) ,
* V_60 = F_24 ( V_17 ) , * V_61 ;
int V_34 , V_25 = - 1 ;
if ( V_56 ) {
if ( V_62 . V_63 ) {
F_25 ( L_2 ) ;
return 0 ;
}
V_58 = ( char * ) V_2 ;
} else
V_58 = F_26 ( V_2 , NULL ) ;
if ( V_58 == NULL || V_59 == NULL || V_60 == NULL )
goto V_64;
V_34 = snprintf ( V_59 , V_17 , L_3 ,
V_55 , V_56 ? L_4 : L_5 , V_58 ) ;
if ( F_27 ( V_59 , 0755 ) )
goto V_64;
snprintf ( V_59 + V_34 , sizeof( V_59 ) - V_34 , L_6 , V_54 ) ;
if ( F_28 ( V_59 , V_65 ) ) {
if ( V_56 ) {
if ( F_29 ( L_7 , V_59 ) )
goto V_64;
} else if ( F_30 ( V_58 , V_59 ) && F_29 ( V_2 , V_59 ) )
goto V_64;
}
V_34 = snprintf ( V_60 , V_17 , L_8 ,
V_55 , V_54 ) ;
if ( F_28 ( V_60 , V_66 ) && F_27 ( V_60 , 0755 ) )
goto V_64;
snprintf ( V_60 + V_34 , V_17 - V_34 , L_6 , V_54 + 2 ) ;
V_61 = V_59 + strlen ( V_55 ) - 5 ;
memcpy ( V_61 , L_9 , 5 ) ;
if ( F_31 ( V_61 , V_60 ) == 0 )
V_25 = 0 ;
V_64:
if ( ! V_56 )
free ( V_58 ) ;
free ( V_59 ) ;
free ( V_60 ) ;
return V_25 ;
}
static int F_32 ( const T_5 * V_37 , T_2 V_67 ,
const char * V_2 , const char * V_55 ,
bool V_56 )
{
char V_54 [ V_68 * 2 + 1 ] ;
F_33 ( V_37 , V_67 , V_54 ) ;
return F_23 ( V_54 , V_55 , V_2 , V_56 ) ;
}
int F_34 ( const char * V_54 , const char * V_55 )
{
const T_2 V_17 = V_57 ;
char * V_59 = F_24 ( V_17 ) ,
* V_60 = F_24 ( V_17 ) ;
int V_25 = - 1 ;
if ( V_59 == NULL || V_60 == NULL )
goto V_64;
snprintf ( V_60 , V_17 , L_10 ,
V_55 , V_54 , V_54 + 2 ) ;
if ( F_28 ( V_60 , V_65 ) )
goto V_64;
if ( F_35 ( V_60 , V_59 , V_17 ) < 0 )
goto V_64;
if ( F_36 ( V_60 ) )
goto V_64;
snprintf ( V_60 , V_17 , L_10 ,
V_55 , V_54 , V_59 ) ;
if ( F_36 ( V_60 ) )
goto V_64;
V_25 = 0 ;
V_64:
free ( V_59 ) ;
free ( V_60 ) ;
return V_25 ;
}
static int F_37 ( struct V_30 * V_30 , const char * V_55 )
{
bool V_56 = V_30 -> V_69 && V_30 -> V_38 [ 0 ] != '/' ;
return F_32 ( V_30 -> V_37 , sizeof( V_30 -> V_37 ) ,
V_30 -> V_38 , V_55 , V_56 ) ;
}
static int F_38 ( struct V_26 * V_27 , const char * V_55 )
{
struct V_30 * V_31 ;
int V_25 = 0 ;
F_14 (pos, head)
if ( F_37 ( V_31 , V_55 ) )
V_25 = - 1 ;
return V_25 ;
}
static int F_39 ( struct V_39 * V_39 , const char * V_55 )
{
int V_18 = F_38 ( & V_39 -> V_46 , V_55 ) ;
V_18 |= F_38 ( & V_39 -> V_47 , V_55 ) ;
return V_18 ;
}
static int F_40 ( struct V_48 * V_49 )
{
struct V_50 * V_51 ;
int V_18 ;
char V_55 [ V_57 ] ;
snprintf ( V_55 , sizeof( V_55 ) , L_11 , V_70 ) ;
if ( F_41 ( V_55 , 0755 ) != 0 && V_19 != V_71 )
return - 1 ;
V_18 = F_39 ( & V_49 -> V_52 , V_55 ) ;
for ( V_51 = F_20 ( & V_49 -> V_53 ) ; V_51 ; V_51 = F_21 ( V_51 ) ) {
struct V_39 * V_31 = F_22 ( V_51 , struct V_39 , V_50 ) ;
V_18 |= F_39 ( V_31 , V_55 ) ;
}
return V_18 ? - 1 : 0 ;
}
static bool F_42 ( struct V_39 * V_39 , bool V_72 )
{
bool V_18 = F_43 ( & V_39 -> V_46 , V_72 ) ;
V_18 |= F_43 ( & V_39 -> V_47 , V_72 ) ;
return V_18 ;
}
static bool F_44 ( struct V_48 * V_49 , bool V_72 )
{
struct V_50 * V_51 ;
bool V_18 = F_42 ( & V_49 -> V_52 , V_72 ) ;
for ( V_51 = F_20 ( & V_49 -> V_53 ) ; V_51 ; V_51 = F_21 ( V_51 ) ) {
struct V_39 * V_31 = F_22 ( V_51 , struct V_39 , V_50 ) ;
V_18 |= F_42 ( V_31 , V_72 ) ;
}
return V_18 ;
}
static int F_45 ( struct V_11 * V_12 ,
struct V_73 * V_74 , int V_15 )
{
int V_75 ;
struct V_48 * V_49 ;
struct V_76 * V_77 ;
int V_78 ;
T_1 V_79 ;
int V_80 = 0 , V_25 ;
V_49 = F_19 ( V_12 , struct V_48 , V_12 ) ;
if ( F_8 ( V_12 , V_81 &&
! F_44 ( V_49 , true ) ) )
F_6 ( V_12 , V_81 ) ;
V_75 = F_46 ( V_12 -> V_14 , V_82 ) ;
if ( ! V_75 )
return 0 ;
V_77 = calloc ( sizeof( * V_77 ) , V_75 ) ;
if ( V_77 == NULL )
return - V_6 ;
V_78 = sizeof( * V_77 ) * V_75 ;
V_79 = V_12 -> V_83 + V_12 -> V_84 ;
F_47 ( V_15 , V_79 + V_78 , V_85 ) ;
if ( F_8 ( V_12 , V_86 ) ) {
struct V_76 * V_87 ;
V_87 = & V_77 [ V_80 ++ ] ;
V_87 -> V_88 = F_47 ( V_15 , 0 , V_89 ) ;
F_48 ( V_15 , & V_74 -> V_90 ) ;
V_87 -> V_17 = F_47 ( V_15 , 0 , V_89 ) - V_87 -> V_88 ;
}
if ( F_8 ( V_12 , V_81 ) ) {
struct V_76 * V_91 ;
V_91 = & V_77 [ V_80 ++ ] ;
V_91 -> V_88 = F_47 ( V_15 , 0 , V_89 ) ;
V_25 = F_18 ( V_12 , V_15 ) ;
if ( V_25 < 0 ) {
F_25 ( L_12 ) ;
goto V_64;
}
V_91 -> V_17 = F_47 ( V_15 , 0 , V_89 ) -
V_91 -> V_88 ;
if ( ! V_92 )
F_40 ( V_49 ) ;
}
F_47 ( V_15 , V_79 , V_85 ) ;
V_25 = F_10 ( V_15 , V_77 , V_78 ) ;
if ( V_25 < 0 )
F_25 ( L_13 ) ;
V_64:
free ( V_77 ) ;
return V_25 ;
}
int F_49 ( int V_15 )
{
struct V_93 V_94 ;
int V_25 ;
V_94 = (struct V_93 ) {
. V_95 = V_96 ,
. V_17 = sizeof( V_94 ) ,
} ;
V_25 = F_10 ( V_15 , & V_94 , sizeof( V_94 ) ) ;
if ( V_25 < 0 ) {
F_25 ( L_14 ) ;
return V_25 ;
}
return 0 ;
}
int F_50 ( struct V_48 * V_49 ,
struct V_73 * V_74 ,
int V_15 , bool V_97 )
{
struct V_98 V_94 ;
struct V_99 V_100 ;
struct V_11 * V_12 = & V_49 -> V_12 ;
struct V_101 * V_102 , * V_103 = NULL ;
int V_25 ;
F_47 ( V_15 , sizeof( V_94 ) , V_85 ) ;
if ( V_49 -> V_74 != V_74 )
V_103 = F_51 ( V_49 -> V_74 -> V_90 . V_104 , struct V_101 , V_105 ) ;
F_52 (attr, &evlist->entries, node) {
V_102 -> V_106 = F_47 ( V_15 , 0 , V_89 ) ;
V_25 = F_10 ( V_15 , V_102 -> V_1 , V_102 -> V_107 * sizeof( T_1 ) ) ;
if ( V_25 < 0 ) {
V_108:
F_25 ( L_15 ) ;
return V_25 ;
}
if ( V_49 -> V_74 != V_74 ) {
V_25 = F_10 ( V_15 , V_103 -> V_1 , V_103 -> V_107 * sizeof( T_1 ) ) ;
if ( V_25 < 0 )
goto V_108;
V_102 -> V_107 += V_103 -> V_107 ;
V_103 = F_51 ( V_103 -> V_105 . V_104 , struct V_101 , V_105 ) ;
}
}
V_12 -> V_109 = F_47 ( V_15 , 0 , V_89 ) ;
F_52 (attr, &evlist->entries, node) {
V_100 = (struct V_99 ) {
. V_102 = V_102 -> V_102 ,
. V_107 = {
. V_88 = V_102 -> V_106 ,
. V_17 = V_102 -> V_107 * sizeof( T_1 ) ,
}
} ;
V_25 = F_10 ( V_15 , & V_100 , sizeof( V_100 ) ) ;
if ( V_25 < 0 ) {
F_25 ( L_16 ) ;
return V_25 ;
}
}
V_12 -> V_110 = F_47 ( V_15 , 0 , V_89 ) ;
V_12 -> V_111 = V_8 * sizeof( struct V_5 ) ;
if ( V_4 ) {
V_25 = F_10 ( V_15 , V_4 , V_12 -> V_111 ) ;
if ( V_25 < 0 ) {
F_25 ( L_17 ) ;
return V_25 ;
}
}
V_12 -> V_83 = F_47 ( V_15 , 0 , V_89 ) ;
if ( V_97 ) {
V_25 = F_45 ( V_12 , V_74 , V_15 ) ;
if ( V_25 < 0 )
return V_25 ;
}
V_94 = (struct V_98 ) {
. V_95 = V_96 ,
. V_17 = sizeof( V_94 ) ,
. V_112 = sizeof( V_100 ) ,
. V_113 = {
. V_88 = V_12 -> V_109 ,
. V_17 = V_74 -> V_114 * sizeof( V_100 ) ,
} ,
. V_115 = {
. V_88 = V_12 -> V_83 ,
. V_17 = V_12 -> V_84 ,
} ,
. V_116 = {
. V_88 = V_12 -> V_110 ,
. V_17 = V_12 -> V_111 ,
} ,
} ;
memcpy ( & V_94 . V_14 , & V_12 -> V_14 , sizeof( V_12 -> V_14 ) ) ;
F_47 ( V_15 , 0 , V_85 ) ;
V_25 = F_10 ( V_15 , & V_94 , sizeof( V_94 ) ) ;
if ( V_25 < 0 ) {
F_25 ( L_15 ) ;
return V_25 ;
}
F_47 ( V_15 , V_12 -> V_83 + V_12 -> V_84 , V_85 ) ;
V_12 -> V_117 = 1 ;
return 0 ;
}
static int F_53 ( struct V_11 * V_12 ,
int V_15 , void * V_16 , T_2 V_17 )
{
if ( F_54 ( V_15 , V_16 , V_17 ) <= 0 )
return - 1 ;
if ( V_12 -> V_118 )
F_55 ( V_16 , V_17 ) ;
return 0 ;
}
int F_56 ( struct V_11 * V_12 , int V_15 ,
int (* F_57)( struct V_76 * V_119 ,
struct V_11 * V_120 ,
int V_13 , int V_15 ) )
{
struct V_76 * V_77 ;
int V_75 ;
int V_78 ;
int V_80 = 0 ;
int V_25 = - 1 , V_13 = 1 ;
V_75 = F_46 ( V_12 -> V_14 , V_82 ) ;
if ( ! V_75 )
return 0 ;
V_77 = calloc ( sizeof( * V_77 ) , V_75 ) ;
if ( ! V_77 )
return - 1 ;
V_78 = sizeof( * V_77 ) * V_75 ;
F_47 ( V_15 , V_12 -> V_83 + V_12 -> V_84 , V_85 ) ;
if ( F_53 ( V_12 , V_15 , V_77 , V_78 ) )
goto V_64;
V_25 = 0 ;
while ( V_80 < V_75 && V_13 < V_121 ) {
if ( F_8 ( V_12 , V_13 ) ) {
struct V_76 * V_122 = & V_77 [ V_80 ++ ] ;
V_25 = F_57 ( V_122 , V_12 , V_13 , V_15 ) ;
if ( V_25 < 0 )
break;
}
++ V_13 ;
}
V_64:
free ( V_77 ) ;
return V_25 ;
}
int F_58 ( struct V_98 * V_12 ,
struct V_11 * V_120 , int V_15 )
{
F_47 ( V_15 , 0 , V_85 ) ;
if ( F_54 ( V_15 , V_12 , sizeof( * V_12 ) ) <= 0 ||
memcmp ( & V_12 -> V_95 , V_123 , sizeof( V_12 -> V_95 ) ) )
return - 1 ;
if ( V_12 -> V_112 != sizeof( struct V_99 ) ) {
T_1 V_112 = F_59 ( V_12 -> V_112 ) ;
if ( V_112 != sizeof( struct V_99 ) )
return - 1 ;
F_55 ( V_12 , F_60 ( struct V_98 ,
V_14 ) ) ;
V_120 -> V_118 = true ;
}
if ( V_12 -> V_17 != sizeof( * V_12 ) ) {
if ( V_12 -> V_17 == F_60 ( F_61 ( * V_12 ) , V_14 ) )
F_62 ( V_12 -> V_14 , V_82 ) ;
else
return - 1 ;
}
memcpy ( & V_120 -> V_14 , & V_12 -> V_14 ,
sizeof( V_120 -> V_14 ) ) ;
if ( V_120 -> V_118 ) {
memset ( & V_120 -> V_14 , 0 , sizeof( V_120 -> V_14 ) ) ;
F_4 ( V_120 , V_81 ) ;
}
V_120 -> V_110 = V_12 -> V_116 . V_88 ;
V_120 -> V_111 = V_12 -> V_116 . V_17 ;
V_120 -> V_83 = V_12 -> V_115 . V_88 ;
V_120 -> V_84 = V_12 -> V_115 . V_17 ;
return 0 ;
}
static int F_63 ( struct V_32 * V_124 ,
char * V_59 ,
struct V_48 * V_49 )
{
int V_25 = - 1 ;
struct V_26 * V_27 ;
struct V_39 * V_39 ;
T_4 V_29 ;
struct V_30 * V_30 ;
enum V_125 V_126 ;
V_39 = F_64 ( V_49 , V_124 -> V_28 ) ;
if ( ! V_39 )
goto V_127;
V_29 = V_124 -> V_12 . V_29 & V_128 ;
switch ( V_29 ) {
case V_41 :
V_126 = V_129 ;
V_27 = & V_39 -> V_46 ;
break;
case V_44 :
V_126 = V_130 ;
V_27 = & V_39 -> V_46 ;
break;
case V_43 :
case V_45 :
V_126 = V_131 ;
V_27 = & V_39 -> V_47 ;
break;
default:
goto V_127;
}
V_30 = F_65 ( V_27 , V_59 ) ;
if ( V_30 != NULL ) {
char V_54 [ V_68 * 2 + 1 ] ;
F_66 ( V_30 , & V_124 -> V_37 ) ;
if ( V_59 [ 0 ] == '[' )
V_30 -> V_69 = V_126 ;
F_33 ( V_30 -> V_37 , sizeof( V_30 -> V_37 ) ,
V_54 ) ;
F_25 ( L_18 ,
V_30 -> V_38 , V_54 ) ;
}
V_25 = 0 ;
V_127:
return V_25 ;
}
static int F_67 ( struct V_11 * V_12 ,
int V_132 , T_1 V_88 , T_1 V_17 )
{
struct V_48 * V_49 = F_19 ( V_12 , struct V_48 , V_12 ) ;
struct {
struct V_133 V_12 ;
T_5 V_37 [ F_15 ( V_68 , sizeof( T_1 ) ) ] ;
char V_59 [ 0 ] ;
} V_134 ;
struct V_32 V_124 ;
char V_59 [ V_57 ] ;
T_1 V_135 = V_88 + V_17 ;
while ( V_88 < V_135 ) {
T_6 V_34 ;
if ( F_68 ( V_132 , & V_134 , sizeof( V_134 ) ) != sizeof( V_134 ) )
return - 1 ;
if ( V_12 -> V_118 )
F_69 ( & V_134 . V_12 ) ;
V_34 = V_134 . V_12 . V_17 - sizeof( V_134 ) ;
if ( F_68 ( V_132 , V_59 , V_34 ) != V_34 )
return - 1 ;
V_124 . V_12 = V_134 . V_12 ;
V_124 . V_28 = V_136 ;
if ( V_124 . V_12 . V_29 == V_45 ||
V_124 . V_12 . V_29 == V_44 )
V_124 . V_28 = V_137 ;
memcpy ( V_124 . V_37 , V_134 . V_37 , sizeof( V_124 . V_37 ) ) ;
F_63 ( & V_124 , V_59 , V_49 ) ;
V_88 += V_124 . V_12 . V_17 ;
}
return 0 ;
}
static int F_70 ( struct V_11 * V_12 ,
int V_132 , T_1 V_88 , T_1 V_17 )
{
struct V_48 * V_49 = F_19 ( V_12 , struct V_48 , V_12 ) ;
struct V_32 V_124 ;
char V_59 [ V_57 ] ;
T_1 V_135 = V_88 + V_17 , V_138 = V_88 ;
int V_25 = - 1 ;
while ( V_88 < V_135 ) {
T_6 V_34 ;
if ( F_68 ( V_132 , & V_124 , sizeof( V_124 ) ) != sizeof( V_124 ) )
goto V_127;
if ( V_12 -> V_118 )
F_69 ( & V_124 . V_12 ) ;
V_34 = V_124 . V_12 . V_17 - sizeof( V_124 ) ;
if ( F_68 ( V_132 , V_59 , V_34 ) != V_34 )
goto V_127;
if ( memcmp ( V_59 , L_19 , 13 ) == 0 ) {
if ( F_47 ( V_132 , V_138 , V_85 ) == ( V_139 ) - 1 )
return - 1 ;
return F_67 ( V_12 , V_132 , V_88 , V_17 ) ;
}
F_63 ( & V_124 , V_59 , V_49 ) ;
V_88 += V_124 . V_12 . V_17 ;
}
V_25 = 0 ;
V_127:
return V_25 ;
}
static int F_71 ( struct V_76 * V_119 ,
struct V_11 * V_120 ,
int V_13 , int V_15 )
{
if ( F_47 ( V_15 , V_119 -> V_88 , V_85 ) == ( V_139 ) - 1 ) {
F_25 ( L_20 V_140 L_21
L_22 , V_119 -> V_88 , V_13 ) ;
return 0 ;
}
switch ( V_13 ) {
case V_86 :
F_72 ( V_15 , false ) ;
break;
case V_81 :
if ( F_70 ( V_120 , V_15 , V_119 -> V_88 , V_119 -> V_17 ) )
F_25 ( L_23 ) ;
break;
default:
F_25 ( L_24 , V_13 ) ;
}
return 0 ;
}
static int F_73 ( struct V_93 * V_12 ,
struct V_11 * V_120 , int V_15 ,
bool V_141 )
{
if ( F_54 ( V_15 , V_12 , sizeof( * V_12 ) ) <= 0 ||
memcmp ( & V_12 -> V_95 , V_123 , sizeof( V_12 -> V_95 ) ) )
return - 1 ;
if ( V_141 && F_10 ( V_142 , V_12 , sizeof( * V_12 ) ) < 0 )
return - 1 ;
if ( V_12 -> V_17 != sizeof( * V_12 ) ) {
T_1 V_17 = F_59 ( V_12 -> V_17 ) ;
if ( V_17 != sizeof( * V_12 ) )
return - 1 ;
V_120 -> V_118 = true ;
}
return 0 ;
}
static int F_74 ( struct V_48 * V_49 , int V_15 )
{
struct V_11 * V_12 = & V_49 -> V_12 ;
struct V_93 V_94 ;
if ( F_73 ( & V_94 , V_12 , V_15 ,
V_49 -> V_141 ) < 0 ) {
F_25 ( L_25 ) ;
return - V_143 ;
}
V_49 -> V_15 = V_15 ;
return 0 ;
}
int F_75 ( struct V_48 * V_49 , int V_15 )
{
struct V_11 * V_12 = & V_49 -> V_12 ;
struct V_98 V_94 ;
struct V_99 V_100 ;
T_1 V_144 ;
int V_145 , V_146 , V_10 , V_147 ;
V_49 -> V_74 = F_76 ( NULL , NULL ) ;
if ( V_49 -> V_74 == NULL )
return - V_6 ;
if ( V_49 -> V_148 )
return F_74 ( V_49 , V_15 ) ;
if ( F_58 ( & V_94 , V_12 , V_15 ) < 0 ) {
F_25 ( L_25 ) ;
return - V_143 ;
}
V_145 = V_94 . V_113 . V_17 / sizeof( V_100 ) ;
F_47 ( V_15 , V_94 . V_113 . V_88 , V_85 ) ;
for ( V_10 = 0 ; V_10 < V_145 ; V_10 ++ ) {
struct V_101 * V_149 ;
V_139 V_150 ;
if ( F_54 ( V_15 , & V_100 , sizeof( V_100 ) ) <= 0 )
goto V_151;
if ( V_12 -> V_118 )
F_77 ( & V_100 . V_102 ) ;
V_150 = F_47 ( V_15 , 0 , V_89 ) ;
V_149 = F_78 ( & V_100 . V_102 , V_10 ) ;
if ( V_149 == NULL )
goto V_152;
F_79 ( V_49 -> V_74 , V_149 ) ;
V_146 = V_100 . V_107 . V_17 / sizeof( T_1 ) ;
if ( F_80 ( V_149 , 1 , V_146 ) )
goto V_152;
F_47 ( V_15 , V_100 . V_107 . V_88 , V_85 ) ;
for ( V_147 = 0 ; V_147 < V_146 ; V_147 ++ ) {
if ( F_53 ( V_12 , V_15 , & V_144 , sizeof( V_144 ) ) )
goto V_151;
F_81 ( V_49 -> V_74 , V_149 , 0 , V_147 , V_144 ) ;
}
F_47 ( V_15 , V_150 , V_85 ) ;
}
if ( V_94 . V_116 . V_17 ) {
F_47 ( V_15 , V_94 . V_116 . V_88 , V_85 ) ;
V_4 = malloc ( V_94 . V_116 . V_17 ) ;
if ( V_4 == NULL )
return - V_6 ;
if ( F_53 ( V_12 , V_15 , V_4 ,
V_94 . V_116 . V_17 ) )
goto V_151;
V_8 = V_94 . V_116 . V_17 / sizeof( struct V_5 ) ;
}
F_56 ( V_12 , V_15 , F_71 ) ;
F_47 ( V_15 , V_12 -> V_83 , V_85 ) ;
V_12 -> V_117 = 1 ;
return 0 ;
V_151:
return - V_19 ;
V_152:
F_82 ( V_49 -> V_74 ) ;
V_49 -> V_74 = NULL ;
return - V_6 ;
}
int F_83 ( struct V_153 * V_102 , T_4 V_107 , T_1 * V_1 ,
T_7 F_57 ,
struct V_48 * V_49 )
{
union V_154 * V_155 ;
T_2 V_17 ;
int V_25 ;
V_17 = sizeof( struct V_153 ) ;
V_17 = F_15 ( V_17 , sizeof( T_1 ) ) ;
V_17 += sizeof( struct V_133 ) ;
V_17 += V_107 * sizeof( T_1 ) ;
V_155 = malloc ( V_17 ) ;
if ( V_155 == NULL )
return - V_6 ;
V_155 -> V_102 . V_102 = * V_102 ;
memcpy ( V_155 -> V_102 . V_1 , V_1 , V_107 * sizeof( T_1 ) ) ;
V_155 -> V_102 . V_12 . type = V_156 ;
V_155 -> V_102 . V_12 . V_17 = V_17 ;
V_25 = F_57 ( V_155 , NULL , V_49 ) ;
free ( V_155 ) ;
return V_25 ;
}
int F_84 ( struct V_48 * V_49 ,
T_7 F_57 )
{
struct V_101 * V_102 ;
int V_25 = 0 ;
F_52 (attr, &session->evlist->entries, node) {
V_25 = F_83 ( & V_102 -> V_102 , V_102 -> V_107 ,
V_102 -> V_1 , F_57 , V_49 ) ;
if ( V_25 ) {
F_25 ( L_26 ) ;
return V_25 ;
}
}
return V_25 ;
}
int F_85 ( union V_154 * V_157 ,
struct V_48 * V_49 )
{
unsigned int V_10 , V_107 , V_158 ;
struct V_101 * V_149 ;
if ( V_49 -> V_74 == NULL ) {
V_49 -> V_74 = F_76 ( NULL , NULL ) ;
if ( V_49 -> V_74 == NULL )
return - V_6 ;
}
V_149 = F_78 ( & V_157 -> V_102 . V_102 ,
V_49 -> V_74 -> V_114 ) ;
if ( V_149 == NULL )
return - V_6 ;
F_79 ( V_49 -> V_74 , V_149 ) ;
V_107 = V_157 -> V_12 . V_17 ;
V_107 -= ( void * ) & V_157 -> V_102 . V_1 - ( void * ) V_157 ;
V_158 = V_107 / sizeof( T_1 ) ;
if ( F_80 ( V_149 , 1 , V_158 ) )
return - V_6 ;
for ( V_10 = 0 ; V_10 < V_158 ; V_10 ++ ) {
F_81 ( V_49 -> V_74 , V_149 , 0 , V_10 ,
V_157 -> V_102 . V_1 [ V_10 ] ) ;
}
F_86 ( V_49 ) ;
return 0 ;
}
int F_87 ( T_1 V_9 , char * V_2 ,
T_7 F_57 ,
struct V_48 * V_49 )
{
union V_154 V_155 ;
T_2 V_17 = 0 ;
int V_25 = 0 ;
memset ( & V_155 , 0 , sizeof( V_155 ) ) ;
V_155 . V_159 . V_159 . V_9 = V_9 ;
memset ( V_155 . V_159 . V_159 . V_2 , 0 , V_3 ) ;
strncpy ( V_155 . V_159 . V_159 . V_2 , V_2 , V_3 - 1 ) ;
V_155 . V_159 . V_12 . type = V_160 ;
V_17 = strlen ( V_2 ) ;
V_17 = F_15 ( V_17 , sizeof( T_1 ) ) ;
V_155 . V_159 . V_12 . V_17 = sizeof( V_155 . V_159 ) -
( sizeof( V_155 . V_159 . V_159 . V_2 ) - V_17 ) ;
V_25 = F_57 ( & V_155 , NULL , V_49 ) ;
return V_25 ;
}
int F_88 ( T_7 F_57 ,
struct V_48 * V_49 )
{
struct V_5 * type ;
int V_10 , V_25 = 0 ;
for ( V_10 = 0 ; V_10 < V_8 ; V_10 ++ ) {
type = & V_4 [ V_10 ] ;
V_25 = F_87 ( type -> V_9 ,
type -> V_2 , F_57 ,
V_49 ) ;
if ( V_25 ) {
F_25 ( L_27 ) ;
return V_25 ;
}
}
return V_25 ;
}
int F_89 ( union V_154 * V_157 ,
struct V_48 * V_49 V_161 )
{
if ( F_1 ( V_157 -> V_159 . V_159 . V_9 ,
V_157 -> V_159 . V_159 . V_2 ) < 0 )
return - V_6 ;
return 0 ;
}
int F_90 ( int V_15 , struct V_73 * V_74 ,
T_7 F_57 ,
struct V_48 * V_49 V_161 )
{
union V_154 V_155 ;
T_6 V_17 = 0 , V_162 = 0 , V_163 ;
int V_25 V_164 = 0 ;
memset ( & V_155 , 0 , sizeof( V_155 ) ) ;
V_155 . V_165 . V_12 . type = V_166 ;
V_17 = F_91 ( V_15 , & V_74 -> V_90 ) ;
if ( V_17 <= 0 )
return V_17 ;
V_162 = F_15 ( V_17 , sizeof( T_1 ) ) ;
V_163 = V_162 - V_17 ;
V_155 . V_165 . V_12 . V_17 = sizeof( V_155 . V_165 ) ;
V_155 . V_165 . V_17 = V_162 ;
F_57 ( & V_155 , NULL , V_49 ) ;
V_25 = F_48 ( V_15 , & V_74 -> V_90 ) ;
F_12 ( V_15 , NULL , 0 , V_163 ) ;
return V_162 ;
}
int F_92 ( union V_154 * V_157 ,
struct V_48 * V_49 )
{
T_6 V_167 , V_163 , V_17 = V_157 -> V_165 . V_17 ;
V_139 V_88 = F_47 ( V_49 -> V_15 , 0 , V_89 ) ;
char V_16 [ V_168 ] ;
F_47 ( V_49 -> V_15 , V_88 + sizeof( struct V_169 ) ,
V_85 ) ;
V_167 = F_72 ( V_49 -> V_15 , V_49 -> V_141 ) ;
V_163 = F_15 ( V_167 , sizeof( T_1 ) ) - V_167 ;
if ( F_68 ( V_49 -> V_15 , V_16 , V_163 ) < 0 )
F_93 ( L_28 ) ;
if ( V_49 -> V_141 ) {
int V_170 = F_11 ( V_142 , V_16 , V_163 ) ;
if ( V_170 <= 0 || V_170 != V_163 )
F_93 ( L_29 ) ;
}
if ( V_167 + V_163 != V_17 )
F_93 ( L_30 ) ;
return V_167 + V_163 ;
}
int F_94 ( struct V_30 * V_31 , T_4 V_29 ,
T_7 F_57 ,
struct V_39 * V_39 ,
struct V_48 * V_49 )
{
union V_154 V_155 ;
T_2 V_34 ;
int V_25 = 0 ;
if ( ! V_31 -> V_35 )
return V_25 ;
memset ( & V_155 , 0 , sizeof( V_155 ) ) ;
V_34 = V_31 -> V_36 + 1 ;
V_34 = F_15 ( V_34 , V_24 ) ;
memcpy ( & V_155 . V_37 . V_37 , V_31 -> V_37 , sizeof( V_31 -> V_37 ) ) ;
V_155 . V_37 . V_12 . type = V_171 ;
V_155 . V_37 . V_12 . V_29 = V_29 ;
V_155 . V_37 . V_28 = V_39 -> V_28 ;
V_155 . V_37 . V_12 . V_17 = sizeof( V_155 . V_37 ) + V_34 ;
memcpy ( & V_155 . V_37 . V_59 , V_31 -> V_38 , V_31 -> V_36 ) ;
V_25 = F_57 ( & V_155 , NULL , V_49 ) ;
return V_25 ;
}
int F_95 ( union V_154 * V_157 ,
struct V_48 * V_49 )
{
F_63 ( & V_157 -> V_37 ,
V_157 -> V_37 . V_59 ,
V_49 ) ;
return 0 ;
}
void F_96 ( void )
{
V_92 = true ;
}
