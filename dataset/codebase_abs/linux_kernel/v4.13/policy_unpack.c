static void F_1 ( struct V_1 * V_2 , void * V_3 )
{
struct V_4 * V_5 = V_3 ;
if ( F_2 ( V_5 ) -> V_6 . V_7 ) {
F_3 ( V_2 , L_1 ) ;
F_4 ( V_2 , F_2 ( V_5 ) -> V_6 . V_7 ) ;
}
if ( F_2 ( V_5 ) -> V_6 . V_8 ) {
F_3 ( V_2 , L_2 ) ;
F_4 ( V_2 , F_2 ( V_5 ) -> V_6 . V_8 ) ;
}
if ( F_2 ( V_5 ) -> V_6 . V_9 )
F_3 ( V_2 , L_3 , F_2 ( V_5 ) -> V_6 . V_9 ) ;
}
static int F_5 ( struct V_10 * V_11 , const char * V_12 ,
const char * V_8 , const char * V_13 , struct V_14 * V_15 ,
int error )
{
struct V_10 * V_16 = F_6 ( F_7 () ) ;
F_8 ( V_5 , V_17 , NULL ) ;
if ( V_15 )
F_2 ( & V_5 ) -> V_6 . V_9 = V_15 -> V_9 - V_15 -> V_18 ;
F_2 ( & V_5 ) -> V_6 . V_7 = V_12 ;
if ( V_11 )
F_2 ( & V_5 ) -> V_6 . V_8 = V_11 -> V_19 . V_20 ;
else
F_2 ( & V_5 ) -> V_6 . V_8 = V_8 ;
F_2 ( & V_5 ) -> V_13 = V_13 ;
F_2 ( & V_5 ) -> error = error ;
return F_9 ( V_21 , V_16 , & V_5 , F_1 ) ;
}
void F_10 ( struct V_22 * V_23 , long V_24 )
{
F_11 ( ! V_23 ) ;
F_11 ( ! V_23 -> V_7 ) ;
F_11 ( ! V_23 -> V_25 [ V_26 ] ) ;
F_11 ( ! F_12 ( & V_23 -> V_7 -> V_27 ) ) ;
F_11 ( V_23 -> V_24 > V_24 ) ;
V_23 -> V_24 = V_24 ;
F_13 ( V_23 -> V_25 [ V_28 ] ) -> V_29 =
F_14 ( F_13 ( V_23 -> V_25 [ V_28 ] ) ) ;
F_13 ( V_23 -> V_25 [ V_26 ] ) -> V_29 =
F_14 ( F_13 ( V_23 -> V_25 [ V_26 ] ) ) ;
}
bool F_15 ( struct V_22 * V_30 , struct V_22 * V_31 )
{
if ( V_30 -> V_32 != V_31 -> V_32 )
return false ;
if ( V_33 && memcmp ( V_30 -> V_34 , V_31 -> V_34 , F_16 () ) != 0 )
return false ;
return memcmp ( V_30 -> V_23 , V_31 -> V_23 , V_31 -> V_32 ) == 0 ;
}
static void F_17 ( struct V_35 * V_36 )
{
struct V_22 * V_37 = F_18 ( V_36 , struct V_22 , V_36 ) ;
struct V_38 * V_7 = F_19 ( V_37 -> V_7 ) ;
if ( V_7 ) {
F_20 ( & V_7 -> V_27 ) ;
F_21 ( V_37 ) ;
F_22 ( & V_7 -> V_27 ) ;
F_23 ( V_7 ) ;
}
F_24 ( V_37 -> V_34 ) ;
F_25 ( V_37 -> V_8 ) ;
F_26 ( V_37 ) ;
}
void F_27 ( struct V_39 * V_39 )
{
struct V_22 * V_37 = F_18 ( V_39 , struct V_22 , V_40 ) ;
if ( V_37 ) {
F_28 ( & V_37 -> V_36 , F_17 ) ;
F_29 ( & V_37 -> V_36 ) ;
}
}
struct V_22 * F_30 ( T_1 V_32 )
{
struct V_22 * V_37 = F_31 ( sizeof( * V_37 ) + V_32 , V_41 ) ;
if ( V_37 == NULL )
return F_32 ( - V_42 ) ;
F_33 ( & V_37 -> V_40 ) ;
F_34 ( & V_37 -> V_43 ) ;
return V_37 ;
}
static bool F_35 ( struct V_14 * V_15 , T_1 V_32 )
{
return ( V_32 <= V_15 -> V_44 - V_15 -> V_9 ) ;
}
static T_1 F_36 ( struct V_14 * V_15 , char * * V_45 )
{
T_1 V_32 = 0 ;
if ( ! F_35 ( V_15 , sizeof( V_46 ) ) )
return 0 ;
V_32 = F_37 ( F_38 ( ( V_47 * ) V_15 -> V_9 ) ) ;
V_15 -> V_9 += sizeof( V_47 ) ;
if ( ! F_35 ( V_15 , V_32 ) )
return 0 ;
* V_45 = V_15 -> V_9 ;
V_15 -> V_9 += V_32 ;
return V_32 ;
}
static bool F_39 ( struct V_14 * V_15 , enum V_48 V_49 )
{
if ( ! F_35 ( V_15 , 1 ) )
return 0 ;
if ( * ( V_50 * ) V_15 -> V_9 != V_49 )
return 0 ;
V_15 -> V_9 ++ ;
return 1 ;
}
static bool F_40 ( struct V_14 * V_15 , enum V_48 V_49 , const char * V_8 )
{
void * V_9 = V_15 -> V_9 ;
if ( F_39 ( V_15 , V_51 ) ) {
char * V_52 = NULL ;
T_1 V_32 = F_36 ( V_15 , & V_52 ) ;
if ( V_8 && ( ! V_32 || strcmp ( V_8 , V_52 ) ) )
goto V_53;
} else if ( V_8 ) {
goto V_53;
}
if ( F_39 ( V_15 , V_49 ) )
return 1 ;
V_53:
V_15 -> V_9 = V_9 ;
return 0 ;
}
static bool F_41 ( struct V_14 * V_15 , T_2 * V_23 , const char * V_8 )
{
if ( F_40 ( V_15 , V_54 , V_8 ) ) {
if ( ! F_35 ( V_15 , sizeof( T_2 ) ) )
return 0 ;
if ( V_23 )
* V_23 = F_42 ( F_38 ( ( V_55 * ) V_15 -> V_9 ) ) ;
V_15 -> V_9 += sizeof( T_2 ) ;
return 1 ;
}
return 0 ;
}
static bool F_43 ( struct V_14 * V_15 , T_3 * V_23 , const char * V_8 )
{
if ( F_40 ( V_15 , V_56 , V_8 ) ) {
if ( ! F_35 ( V_15 , sizeof( T_3 ) ) )
return 0 ;
if ( V_23 )
* V_23 = F_44 ( F_38 ( ( V_57 * ) V_15 -> V_9 ) ) ;
V_15 -> V_9 += sizeof( T_3 ) ;
return 1 ;
}
return 0 ;
}
static T_1 F_45 ( struct V_14 * V_15 , const char * V_8 )
{
if ( F_40 ( V_15 , V_58 , V_8 ) ) {
int V_32 ;
if ( ! F_35 ( V_15 , sizeof( V_46 ) ) )
return 0 ;
V_32 = ( int ) F_37 ( F_38 ( ( V_47 * ) V_15 -> V_9 ) ) ;
V_15 -> V_9 += sizeof( V_46 ) ;
return V_32 ;
}
return 0 ;
}
static T_1 F_46 ( struct V_14 * V_15 , char * * V_59 , const char * V_8 )
{
if ( F_40 ( V_15 , V_60 , V_8 ) ) {
T_2 V_32 ;
if ( ! F_35 ( V_15 , sizeof( T_2 ) ) )
return 0 ;
V_32 = F_42 ( F_38 ( ( V_55 * ) V_15 -> V_9 ) ) ;
V_15 -> V_9 += sizeof( T_2 ) ;
if ( F_35 ( V_15 , ( T_1 ) V_32 ) ) {
* V_59 = V_15 -> V_9 ;
V_15 -> V_9 += V_32 ;
return V_32 ;
}
}
return 0 ;
}
static int F_47 ( struct V_14 * V_15 , const char * * string , const char * V_8 )
{
char * V_61 ;
T_1 V_32 = 0 ;
void * V_9 = V_15 -> V_9 ;
* string = NULL ;
if ( F_40 ( V_15 , V_62 , V_8 ) ) {
V_32 = F_36 ( V_15 , & V_61 ) ;
if ( V_32 ) {
if ( V_61 [ V_32 - 1 ] != 0 )
goto V_53;
* string = V_61 ;
}
}
return V_32 ;
V_53:
V_15 -> V_9 = V_9 ;
return 0 ;
}
static int F_48 ( struct V_14 * V_15 , char * * string , const char * V_8 )
{
const char * V_63 ;
void * V_9 = V_15 -> V_9 ;
int V_64 = F_47 ( V_15 , & V_63 , V_8 ) ;
* string = NULL ;
if ( ! V_64 )
return 0 ;
* string = F_49 ( V_63 , V_64 , V_41 ) ;
if ( ! * string ) {
V_15 -> V_9 = V_9 ;
return 0 ;
}
return V_64 ;
}
static bool F_50 ( struct V_65 * V_66 , int V_67 )
{
int V_68 ;
for ( V_68 = 0 ; V_68 < V_66 -> V_69 [ V_70 ] -> V_71 ; V_68 ++ ) {
int V_72 = F_51 ( V_66 ) [ V_68 ] ;
if ( V_72 & ~ V_73 )
return 0 ;
if ( F_52 ( V_66 ) [ V_68 ] & ~ V_74 )
return 0 ;
}
return 1 ;
}
static struct V_65 * F_53 ( struct V_14 * V_15 )
{
char * V_59 = NULL ;
T_1 V_32 ;
struct V_65 * V_66 = NULL ;
V_32 = F_46 ( V_15 , & V_59 , L_4 ) ;
if ( V_32 ) {
T_1 V_75 = V_59 - ( char * ) V_15 -> V_18 -
( ( V_15 -> V_9 - V_15 -> V_18 ) & 7 ) ;
T_1 V_76 = F_54 ( V_75 , 8 ) - V_75 ;
int V_67 = F_55 ( V_77 ) |
F_56 ( V_77 ) | V_78 ;
V_66 = F_57 ( V_59 + V_76 , V_32 - V_76 , V_67 ) ;
if ( F_58 ( V_66 ) )
return V_66 ;
if ( ! F_50 ( V_66 , V_67 ) )
goto V_53;
}
return V_66 ;
V_53:
F_59 ( V_66 ) ;
return F_32 ( - V_79 ) ;
}
static bool F_60 ( struct V_14 * V_15 , struct V_10 * V_16 )
{
void * V_9 = V_15 -> V_9 ;
if ( F_40 ( V_15 , V_80 , L_5 ) ) {
int V_68 , V_32 ;
V_32 = F_45 ( V_15 , NULL ) ;
if ( V_32 > 16 - 4 )
goto V_53;
V_16 -> V_81 . V_82 . V_83 = F_61 ( sizeof( char * ) * V_32 ,
V_41 ) ;
if ( ! V_16 -> V_81 . V_82 . V_83 )
goto V_53;
V_16 -> V_81 . V_82 . V_32 = V_32 ;
for ( V_68 = 0 ; V_68 < V_32 ; V_68 ++ ) {
char * V_84 ;
int V_85 , V_86 , V_9 , V_87 = F_48 ( V_15 , & V_84 , NULL ) ;
if ( ! V_87 )
goto V_53;
V_16 -> V_81 . V_82 . V_83 [ V_68 ] = V_84 ;
if ( isspace ( * V_84 ) )
goto V_53;
for ( V_85 = V_86 = 0 ; V_86 < V_87 - 1 ; V_86 ++ ) {
if ( ! V_84 [ V_86 ] ) {
V_9 = V_86 ;
V_85 ++ ;
}
}
if ( * V_84 == ':' ) {
if ( ! V_84 [ 1 ] )
goto V_53;
if ( V_85 == 1 )
V_84 [ V_9 ] = ':' ;
else if ( V_85 > 1 )
goto V_53;
} else if ( V_85 )
goto V_53;
}
if ( ! F_40 ( V_15 , V_88 , NULL ) )
goto V_53;
if ( ! F_40 ( V_15 , V_89 , NULL ) )
goto V_53;
}
return 1 ;
V_53:
F_62 ( & V_16 -> V_81 . V_82 ) ;
V_15 -> V_9 = V_9 ;
return 0 ;
}
static bool F_63 ( struct V_14 * V_15 , struct V_10 * V_16 )
{
void * V_9 = V_15 -> V_9 ;
if ( F_40 ( V_15 , V_80 , L_6 ) ) {
int V_68 , V_32 ;
T_2 V_63 = 0 ;
if ( ! F_41 ( V_15 , & V_63 , NULL ) )
goto V_53;
V_16 -> V_90 . V_91 = V_63 ;
V_32 = F_45 ( V_15 , NULL ) ;
if ( V_32 > V_92 )
goto V_53;
for ( V_68 = 0 ; V_68 < V_32 ; V_68 ++ ) {
T_3 V_93 = 0 ;
int V_94 = F_64 ( V_68 ) ;
if ( ! F_43 ( V_15 , & V_93 , NULL ) )
goto V_53;
V_16 -> V_90 . V_95 [ V_94 ] . V_96 = V_93 ;
}
if ( ! F_40 ( V_15 , V_88 , NULL ) )
goto V_53;
if ( ! F_40 ( V_15 , V_89 , NULL ) )
goto V_53;
}
return 1 ;
V_53:
V_15 -> V_9 = V_9 ;
return 0 ;
}
static void * F_65 ( const void * V_97 , T_1 V_98 )
{
void * V_99 = F_66 ( V_98 , V_41 ) ;
if ( V_99 )
memcpy ( V_99 , V_97 , V_98 ) ;
return V_99 ;
}
static T_2 F_67 ( const void * V_23 , T_2 V_98 , T_2 V_100 )
{
const char * const * V_101 = V_23 ;
return F_68 ( * V_101 , strlen ( * V_101 ) , V_100 ) ;
}
static int F_69 ( struct V_102 * V_103 , const void * V_104 )
{
const struct V_105 * V_23 = V_104 ;
const char * const * V_101 = V_103 -> V_101 ;
return strcmp ( V_23 -> V_101 , * V_101 ) ;
}
static struct V_10 * F_70 ( struct V_14 * V_15 , char * * V_12 )
{
struct V_10 * V_16 = NULL ;
const char * V_106 , * V_107 = NULL , * V_8 = NULL ;
T_1 V_108 ;
struct V_109 V_110 = { 0 } ;
char * V_101 = NULL ;
struct V_105 * V_23 ;
int V_68 , error = - V_79 ;
T_4 V_111 ;
T_2 V_63 ;
* V_12 = NULL ;
if ( ! F_40 ( V_15 , V_80 , L_7 ) )
goto V_53;
if ( ! F_47 ( V_15 , & V_8 , NULL ) )
goto V_53;
if ( * V_8 == '\0' )
goto V_53;
V_106 = F_71 ( V_8 , strlen ( V_8 ) , & V_107 , & V_108 ) ;
if ( V_107 ) {
* V_12 = F_72 ( V_107 , V_108 , V_41 ) ;
if ( ! * V_12 )
goto V_53;
V_8 = V_106 ;
}
V_16 = F_73 ( V_8 , NULL , V_41 ) ;
if ( ! V_16 )
return F_32 ( - V_42 ) ;
( void ) F_47 ( V_15 , & V_16 -> rename , L_8 ) ;
( void ) F_47 ( V_15 , & V_16 -> V_112 , L_9 ) ;
V_16 -> V_113 = F_53 ( V_15 ) ;
if ( F_58 ( V_16 -> V_113 ) ) {
error = F_74 ( V_16 -> V_113 ) ;
V_16 -> V_113 = NULL ;
goto V_53;
}
if ( V_16 -> V_113 ) {
if ( ! F_41 ( V_15 , & V_63 , NULL ) )
goto V_53;
V_16 -> V_114 = V_63 ;
}
( void ) F_47 ( V_15 , & V_16 -> V_115 , L_10 ) ;
if ( ! F_40 ( V_15 , V_80 , L_11 ) )
goto V_53;
if ( ! F_41 ( V_15 , & V_63 , NULL ) )
goto V_53;
if ( V_63 & V_116 )
V_16 -> V_117 . V_67 |= V_118 ;
if ( ! F_41 ( V_15 , & V_63 , NULL ) )
goto V_53;
if ( V_63 == V_119 || ( V_15 -> V_120 & V_121 ) )
V_16 -> V_72 = V_122 ;
else if ( V_63 == V_123 )
V_16 -> V_72 = V_124 ;
else if ( V_63 == V_125 )
V_16 -> V_72 = V_126 ;
if ( ! F_41 ( V_15 , & V_63 , NULL ) )
goto V_53;
if ( V_63 )
V_16 -> V_127 = V_128 ;
if ( ! F_40 ( V_15 , V_89 , NULL ) )
goto V_53;
if ( F_41 ( V_15 , & V_16 -> V_129 , L_12 ) )
V_16 -> V_129 |= V_16 -> V_117 . V_67 &
V_130 ;
else
V_16 -> V_129 = V_130 ;
if ( ! F_41 ( V_15 , & ( V_16 -> V_131 . V_132 . V_133 [ 0 ] ) , NULL ) )
goto V_53;
if ( ! F_41 ( V_15 , & ( V_16 -> V_131 . V_127 . V_133 [ 0 ] ) , NULL ) )
goto V_53;
if ( ! F_41 ( V_15 , & ( V_16 -> V_131 . V_134 . V_133 [ 0 ] ) , NULL ) )
goto V_53;
if ( ! F_41 ( V_15 , & V_111 . V_133 [ 0 ] , NULL ) )
goto V_53;
if ( F_40 ( V_15 , V_80 , L_13 ) ) {
if ( ! F_41 ( V_15 , & ( V_16 -> V_131 . V_132 . V_133 [ 1 ] ) , NULL ) )
goto V_53;
if ( ! F_41 ( V_15 , & ( V_16 -> V_131 . V_127 . V_133 [ 1 ] ) , NULL ) )
goto V_53;
if ( ! F_41 ( V_15 , & ( V_16 -> V_131 . V_134 . V_133 [ 1 ] ) , NULL ) )
goto V_53;
if ( ! F_41 ( V_15 , & ( V_111 . V_133 [ 1 ] ) , NULL ) )
goto V_53;
if ( ! F_40 ( V_15 , V_89 , NULL ) )
goto V_53;
}
if ( F_40 ( V_15 , V_80 , L_14 ) ) {
if ( ! F_41 ( V_15 , & ( V_16 -> V_131 . V_135 . V_133 [ 0 ] ) , NULL ) )
goto V_53;
if ( ! F_41 ( V_15 , & ( V_16 -> V_131 . V_135 . V_133 [ 1 ] ) , NULL ) )
goto V_53;
if ( ! F_40 ( V_15 , V_89 , NULL ) )
goto V_53;
}
if ( ! F_63 ( V_15 , V_16 ) )
goto V_53;
if ( F_40 ( V_15 , V_80 , L_15 ) ) {
V_16 -> V_136 . V_66 = F_53 ( V_15 ) ;
if ( F_58 ( V_16 -> V_136 . V_66 ) ) {
error = F_74 ( V_16 -> V_136 . V_66 ) ;
V_16 -> V_136 . V_66 = NULL ;
goto V_53;
} else if ( ! V_16 -> V_136 . V_66 ) {
error = - V_79 ;
goto V_53;
}
if ( ! F_41 ( V_15 , & V_16 -> V_136 . V_18 [ 0 ] , L_16 ) )
V_16 -> V_136 . V_18 [ 0 ] = V_137 ;
for ( V_68 = V_138 ; V_68 <= V_139 ; V_68 ++ ) {
V_16 -> V_136 . V_18 [ V_68 ] =
F_75 ( V_16 -> V_136 . V_66 ,
V_16 -> V_136 . V_18 [ 0 ] ,
V_68 ) ;
}
if ( ! F_40 ( V_15 , V_89 , NULL ) )
goto V_53;
} else
V_16 -> V_136 . V_66 = F_76 ( V_140 ) ;
V_16 -> V_81 . V_66 = F_53 ( V_15 ) ;
if ( F_58 ( V_16 -> V_81 . V_66 ) ) {
error = F_74 ( V_16 -> V_81 . V_66 ) ;
V_16 -> V_81 . V_66 = NULL ;
goto V_53;
} else if ( V_16 -> V_81 . V_66 ) {
if ( ! F_41 ( V_15 , & V_16 -> V_81 . V_18 , L_17 ) )
V_16 -> V_81 . V_18 = V_137 ;
} else if ( V_16 -> V_136 . V_66 &&
V_16 -> V_136 . V_18 [ V_138 ] ) {
V_16 -> V_81 . V_66 = F_76 ( V_16 -> V_136 . V_66 ) ;
V_16 -> V_81 . V_18 = V_16 -> V_136 . V_18 [ V_138 ] ;
} else
V_16 -> V_81 . V_66 = F_76 ( V_140 ) ;
if ( ! F_60 ( V_15 , V_16 ) )
goto V_53;
if ( F_40 ( V_15 , V_80 , L_18 ) ) {
V_16 -> V_23 = F_61 ( sizeof( * V_16 -> V_23 ) , V_41 ) ;
if ( ! V_16 -> V_23 )
goto V_53;
V_110 . V_141 = 3 ;
V_110 . V_142 = sizeof( void * ) ;
V_110 . V_143 = F_77 ( struct V_105 , V_101 ) ;
V_110 . V_144 = F_77 ( struct V_105 , V_145 ) ;
V_110 . V_146 = F_67 ;
V_110 . V_147 = F_69 ;
if ( F_78 ( V_16 -> V_23 , & V_110 ) )
goto V_53;
while ( F_48 ( V_15 , & V_101 , NULL ) ) {
V_23 = F_61 ( sizeof( * V_23 ) , V_41 ) ;
if ( ! V_23 ) {
F_24 ( V_101 ) ;
goto V_53;
}
V_23 -> V_101 = V_101 ;
V_23 -> V_32 = F_46 ( V_15 , & V_23 -> V_23 , NULL ) ;
V_23 -> V_23 = F_65 ( V_23 -> V_23 , V_23 -> V_32 ) ;
if ( V_23 -> V_32 && ! V_23 -> V_23 ) {
F_24 ( V_23 -> V_101 ) ;
F_24 ( V_23 ) ;
goto V_53;
}
F_79 ( V_16 -> V_23 , & V_23 -> V_145 ,
V_16 -> V_23 -> V_99 ) ;
}
if ( ! F_40 ( V_15 , V_89 , NULL ) )
goto V_53;
}
if ( ! F_40 ( V_15 , V_89 , NULL ) )
goto V_53;
return V_16 ;
V_53:
if ( V_16 )
V_8 = NULL ;
else if ( ! V_8 )
V_8 = L_19 ;
F_5 ( V_16 , NULL , V_8 , L_20 , V_15 ,
error ) ;
F_80 ( V_16 ) ;
return F_32 ( error ) ;
}
static int F_81 ( struct V_14 * V_15 , int V_148 , const char * * V_7 )
{
int error = - V_149 ;
const char * V_8 = NULL ;
* V_7 = NULL ;
if ( ! F_41 ( V_15 , & V_15 -> V_120 , L_21 ) ) {
if ( V_148 ) {
F_5 ( NULL , NULL , NULL , L_22 ,
V_15 , error ) ;
return error ;
}
}
if ( F_82 ( V_15 -> V_120 , V_150 ) && F_83 ( V_15 -> V_120 , V_151 ) ) {
F_5 ( NULL , NULL , NULL , L_23 ,
V_15 , error ) ;
return error ;
}
if ( F_47 ( V_15 , & V_8 , L_24 ) ) {
if ( * V_8 == '\0' ) {
F_5 ( NULL , NULL , NULL , L_25 ,
V_15 , error ) ;
return error ;
}
if ( * V_7 && strcmp ( * V_7 , V_8 ) )
F_5 ( NULL , NULL , NULL , L_26 , V_15 ,
error ) ;
else if ( ! * V_7 )
* V_7 = V_8 ;
}
return 0 ;
}
static bool F_84 ( int V_152 , int V_153 )
{
int V_154 , V_155 ;
V_155 = V_152 & V_156 ;
V_154 = V_152 & V_157 ;
if ( V_155 == V_158 && V_154 >= V_153 )
return 0 ;
return 1 ;
}
static bool F_85 ( struct V_65 * V_66 , int V_153 )
{
int V_68 ;
for ( V_68 = 0 ; V_68 < V_66 -> V_69 [ V_70 ] -> V_71 ; V_68 ++ ) {
if ( ! F_84 ( F_86 ( V_66 , V_68 ) , V_153 ) )
return 0 ;
if ( ! F_84 ( F_87 ( V_66 , V_68 ) , V_153 ) )
return 0 ;
}
return 1 ;
}
static int F_88 ( struct V_10 * V_16 )
{
if ( V_16 -> V_81 . V_66 &&
! F_85 ( V_16 -> V_81 . V_66 ,
V_16 -> V_81 . V_82 . V_32 ) ) {
F_5 ( V_16 , NULL , NULL , L_27 ,
NULL , - V_79 ) ;
return - V_79 ;
}
return 0 ;
}
void F_89 ( struct V_159 * V_160 )
{
if ( V_160 ) {
F_90 ( V_160 -> rename ) ;
F_90 ( V_160 -> V_161 ) ;
F_90 ( V_160 -> V_11 ) ;
F_25 ( V_160 -> V_12 ) ;
F_24 ( V_160 ) ;
}
}
struct V_159 * F_91 ( void )
{
struct V_159 * V_160 = F_61 ( sizeof( * V_160 ) , V_41 ) ;
if ( V_160 )
F_34 ( & V_160 -> V_43 ) ;
return V_160 ;
}
int F_92 ( struct V_22 * V_162 , struct V_163 * V_164 ,
const char * * V_7 )
{
struct V_159 * V_63 , * V_160 ;
struct V_10 * V_16 = NULL ;
int error ;
struct V_14 V_15 = {
. V_18 = V_162 -> V_23 ,
. V_44 = V_162 -> V_23 + V_162 -> V_32 ,
. V_9 = V_162 -> V_23 ,
} ;
* V_7 = NULL ;
while ( V_15 . V_9 < V_15 . V_44 ) {
char * V_12 = NULL ;
void * V_18 ;
error = F_81 ( & V_15 , V_15 . V_9 == V_15 . V_18 , V_7 ) ;
if ( error )
goto V_53;
V_18 = V_15 . V_9 ;
V_16 = F_70 ( & V_15 , & V_12 ) ;
if ( F_58 ( V_16 ) ) {
error = F_74 ( V_16 ) ;
goto V_53;
}
error = F_88 ( V_16 ) ;
if ( error )
goto V_165;
if ( V_33 )
error = F_93 ( V_16 , V_15 . V_120 , V_18 ,
V_15 . V_9 - V_18 ) ;
if ( error )
goto V_165;
V_160 = F_91 () ;
if ( ! V_160 ) {
error = - V_42 ;
goto V_165;
}
V_160 -> V_11 = V_16 ;
V_160 -> V_12 = V_12 ;
F_94 ( & V_160 -> V_43 , V_164 ) ;
}
V_162 -> V_166 = V_15 . V_120 & V_167 ;
if ( V_33 ) {
V_162 -> V_34 = F_95 ( V_162 -> V_23 , V_162 -> V_32 ) ;
if ( F_58 ( V_162 -> V_34 ) ) {
error = F_74 ( V_162 -> V_34 ) ;
V_162 -> V_34 = NULL ;
goto V_53;
}
}
return 0 ;
V_165:
F_90 ( V_16 ) ;
V_53:
F_96 (ent, tmp, lh, list) {
F_97 ( & V_160 -> V_43 ) ;
F_89 ( V_160 ) ;
}
return error ;
}
