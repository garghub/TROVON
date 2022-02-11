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
struct V_10 * V_16 = F_6 () ;
F_7 ( V_5 , V_17 , NULL ) ;
if ( V_15 )
F_2 ( & V_5 ) -> V_6 . V_9 = V_15 -> V_9 - V_15 -> V_18 ;
F_2 ( & V_5 ) -> V_6 . V_7 = V_12 ;
if ( V_11 )
F_2 ( & V_5 ) -> V_6 . V_8 = V_11 -> V_19 . V_20 ;
else
F_2 ( & V_5 ) -> V_6 . V_8 = V_8 ;
F_2 ( & V_5 ) -> V_13 = V_13 ;
F_2 ( & V_5 ) -> error = error ;
return F_8 ( V_21 , V_16 , & V_5 , F_1 ) ;
}
void F_9 ( struct V_22 * V_22 )
{
struct V_23 * V_24 = F_10 ( V_22 , struct V_23 , V_25 ) ;
if ( V_24 ) {
F_11 ( V_24 -> V_26 ) ;
F_12 ( V_24 ) ;
}
}
static bool F_13 ( struct V_14 * V_15 , T_1 V_27 )
{
return ( V_27 <= V_15 -> V_28 - V_15 -> V_9 ) ;
}
static T_1 F_14 ( struct V_14 * V_15 , char * * V_29 )
{
T_1 V_27 = 0 ;
if ( ! F_13 ( V_15 , sizeof( V_30 ) ) )
return 0 ;
V_27 = F_15 ( F_16 ( ( V_31 * ) V_15 -> V_9 ) ) ;
V_15 -> V_9 += sizeof( V_31 ) ;
if ( ! F_13 ( V_15 , V_27 ) )
return 0 ;
* V_29 = V_15 -> V_9 ;
V_15 -> V_9 += V_27 ;
return V_27 ;
}
static bool F_17 ( struct V_14 * V_15 , enum V_32 V_33 )
{
if ( ! F_13 ( V_15 , 1 ) )
return 0 ;
if ( * ( V_34 * ) V_15 -> V_9 != V_33 )
return 0 ;
V_15 -> V_9 ++ ;
return 1 ;
}
static bool F_18 ( struct V_14 * V_15 , enum V_32 V_33 , const char * V_8 )
{
void * V_9 = V_15 -> V_9 ;
if ( F_17 ( V_15 , V_35 ) ) {
char * V_36 = NULL ;
T_1 V_27 = F_14 ( V_15 , & V_36 ) ;
if ( V_8 && ( ! V_27 || strcmp ( V_8 , V_36 ) ) )
goto V_37;
} else if ( V_8 ) {
goto V_37;
}
if ( F_17 ( V_15 , V_33 ) )
return 1 ;
V_37:
V_15 -> V_9 = V_9 ;
return 0 ;
}
static bool F_19 ( struct V_14 * V_15 , T_2 * V_38 , const char * V_8 )
{
if ( F_18 ( V_15 , V_39 , V_8 ) ) {
if ( ! F_13 ( V_15 , sizeof( T_2 ) ) )
return 0 ;
if ( V_38 )
* V_38 = F_20 ( F_16 ( ( V_40 * ) V_15 -> V_9 ) ) ;
V_15 -> V_9 += sizeof( T_2 ) ;
return 1 ;
}
return 0 ;
}
static bool F_21 ( struct V_14 * V_15 , T_3 * V_38 , const char * V_8 )
{
if ( F_18 ( V_15 , V_41 , V_8 ) ) {
if ( ! F_13 ( V_15 , sizeof( T_3 ) ) )
return 0 ;
if ( V_38 )
* V_38 = F_22 ( F_16 ( ( V_42 * ) V_15 -> V_9 ) ) ;
V_15 -> V_9 += sizeof( T_3 ) ;
return 1 ;
}
return 0 ;
}
static T_1 F_23 ( struct V_14 * V_15 , const char * V_8 )
{
if ( F_18 ( V_15 , V_43 , V_8 ) ) {
int V_27 ;
if ( ! F_13 ( V_15 , sizeof( V_30 ) ) )
return 0 ;
V_27 = ( int ) F_15 ( F_16 ( ( V_31 * ) V_15 -> V_9 ) ) ;
V_15 -> V_9 += sizeof( V_30 ) ;
return V_27 ;
}
return 0 ;
}
static T_1 F_24 ( struct V_14 * V_15 , char * * V_44 , const char * V_8 )
{
if ( F_18 ( V_15 , V_45 , V_8 ) ) {
T_2 V_27 ;
if ( ! F_13 ( V_15 , sizeof( T_2 ) ) )
return 0 ;
V_27 = F_20 ( F_16 ( ( V_40 * ) V_15 -> V_9 ) ) ;
V_15 -> V_9 += sizeof( T_2 ) ;
if ( F_13 ( V_15 , ( T_1 ) V_27 ) ) {
* V_44 = V_15 -> V_9 ;
V_15 -> V_9 += V_27 ;
return V_27 ;
}
}
return 0 ;
}
static int F_25 ( struct V_14 * V_15 , const char * * string , const char * V_8 )
{
char * V_46 ;
T_1 V_27 = 0 ;
void * V_9 = V_15 -> V_9 ;
* string = NULL ;
if ( F_18 ( V_15 , V_47 , V_8 ) ) {
V_27 = F_14 ( V_15 , & V_46 ) ;
if ( V_27 ) {
if ( V_46 [ V_27 - 1 ] != 0 )
goto V_37;
* string = V_46 ;
}
}
return V_27 ;
V_37:
V_15 -> V_9 = V_9 ;
return 0 ;
}
static int F_26 ( struct V_14 * V_15 , char * * string , const char * V_8 )
{
const char * V_48 ;
void * V_9 = V_15 -> V_9 ;
int V_49 = F_25 ( V_15 , & V_48 , V_8 ) ;
* string = NULL ;
if ( ! V_49 )
return 0 ;
* string = F_27 ( V_48 , V_49 , V_50 ) ;
if ( ! * string ) {
V_15 -> V_9 = V_9 ;
return 0 ;
}
return V_49 ;
}
static bool F_28 ( struct V_51 * V_52 , int V_53 )
{
int V_54 ;
for ( V_54 = 0 ; V_54 < V_52 -> V_55 [ V_56 ] -> V_57 ; V_54 ++ ) {
int V_58 = F_29 ( V_52 ) [ V_54 ] ;
if ( V_58 & ~ V_59 )
return 0 ;
if ( F_30 ( V_52 ) [ V_54 ] & ~ V_60 )
return 0 ;
}
return 1 ;
}
static struct V_51 * F_31 ( struct V_14 * V_15 )
{
char * V_44 = NULL ;
T_1 V_27 ;
struct V_51 * V_52 = NULL ;
V_27 = F_24 ( V_15 , & V_44 , L_4 ) ;
if ( V_27 ) {
T_1 V_61 = V_44 - ( char * ) V_15 -> V_18 -
( ( V_15 -> V_9 - V_15 -> V_18 ) & 7 ) ;
T_1 V_62 = F_32 ( V_61 , 8 ) - V_61 ;
int V_53 = F_33 ( V_63 ) |
F_34 ( V_63 ) | V_64 ;
V_52 = F_35 ( V_44 + V_62 , V_27 - V_62 , V_53 ) ;
if ( F_36 ( V_52 ) )
return V_52 ;
if ( ! F_28 ( V_52 , V_53 ) )
goto V_37;
}
return V_52 ;
V_37:
F_37 ( V_52 ) ;
return F_38 ( - V_65 ) ;
}
static bool F_39 ( struct V_14 * V_15 , struct V_10 * V_16 )
{
void * V_9 = V_15 -> V_9 ;
if ( F_18 ( V_15 , V_66 , L_5 ) ) {
int V_54 , V_27 ;
V_27 = F_23 ( V_15 , NULL ) ;
if ( V_27 > 16 - 4 )
goto V_37;
V_16 -> V_67 . V_68 . V_69 = F_40 ( sizeof( char * ) * V_27 ,
V_50 ) ;
if ( ! V_16 -> V_67 . V_68 . V_69 )
goto V_37;
V_16 -> V_67 . V_68 . V_27 = V_27 ;
for ( V_54 = 0 ; V_54 < V_27 ; V_54 ++ ) {
char * V_70 ;
int V_71 , V_72 , V_73 = F_26 ( V_15 , & V_70 , NULL ) ;
if ( ! V_73 )
goto V_37;
V_16 -> V_67 . V_68 . V_69 [ V_54 ] = V_70 ;
if ( isspace ( * V_70 ) )
goto V_37;
for ( V_71 = V_72 = 0 ; V_72 < V_73 - 2 ; V_72 ++ ) {
if ( ! V_70 [ V_72 ] )
V_71 ++ ;
}
if ( * V_70 == ':' ) {
if ( V_71 != 1 )
goto V_37;
if ( ! V_70 [ 1 ] )
goto V_37;
} else if ( V_71 )
goto V_37;
}
if ( ! F_18 ( V_15 , V_74 , NULL ) )
goto V_37;
if ( ! F_18 ( V_15 , V_75 , NULL ) )
goto V_37;
}
return 1 ;
V_37:
F_41 ( & V_16 -> V_67 . V_68 ) ;
V_15 -> V_9 = V_9 ;
return 0 ;
}
static bool F_42 ( struct V_14 * V_15 , struct V_10 * V_16 )
{
void * V_9 = V_15 -> V_9 ;
if ( F_18 ( V_15 , V_66 , L_6 ) ) {
int V_54 , V_27 ;
T_2 V_48 = 0 ;
if ( ! F_19 ( V_15 , & V_48 , NULL ) )
goto V_37;
V_16 -> V_76 . V_77 = V_48 ;
V_27 = F_23 ( V_15 , NULL ) ;
if ( V_27 > V_78 )
goto V_37;
for ( V_54 = 0 ; V_54 < V_27 ; V_54 ++ ) {
T_3 V_79 = 0 ;
int V_80 = F_43 ( V_54 ) ;
if ( ! F_21 ( V_15 , & V_79 , NULL ) )
goto V_37;
V_16 -> V_76 . V_81 [ V_80 ] . V_82 = V_79 ;
}
if ( ! F_18 ( V_15 , V_74 , NULL ) )
goto V_37;
if ( ! F_18 ( V_15 , V_75 , NULL ) )
goto V_37;
}
return 1 ;
V_37:
V_15 -> V_9 = V_9 ;
return 0 ;
}
static void * F_44 ( const void * V_83 , T_1 V_84 )
{
void * V_85 = F_45 ( V_84 ) ;
if ( V_85 )
memcpy ( V_85 , V_83 , V_84 ) ;
return V_85 ;
}
static T_2 F_46 ( const void * V_38 , T_2 V_84 , T_2 V_86 )
{
const char * const * V_87 = V_38 ;
return F_47 ( * V_87 , strlen ( * V_87 ) , V_86 ) ;
}
static int F_48 ( struct V_88 * V_89 , const void * V_90 )
{
const struct V_91 * V_38 = V_90 ;
const char * const * V_87 = V_89 -> V_87 ;
return strcmp ( V_38 -> V_87 , * V_87 ) ;
}
static struct V_10 * F_49 ( struct V_14 * V_15 , char * * V_12 )
{
struct V_10 * V_16 = NULL ;
const char * V_92 , * V_93 = NULL , * V_8 = NULL ;
T_1 V_94 ;
struct V_95 V_96 = { 0 } ;
char * V_87 = NULL ;
struct V_91 * V_38 ;
int V_54 , error = - V_65 ;
T_4 V_97 ;
T_2 V_48 ;
* V_12 = NULL ;
if ( ! F_18 ( V_15 , V_66 , L_7 ) )
goto V_37;
if ( ! F_25 ( V_15 , & V_8 , NULL ) )
goto V_37;
if ( * V_8 == '\0' )
goto V_37;
V_92 = F_50 ( V_8 , strlen ( V_8 ) , & V_93 , & V_94 ) ;
if ( V_93 ) {
* V_12 = F_51 ( V_93 , V_94 , V_50 ) ;
if ( ! * V_12 )
goto V_37;
V_8 = V_92 ;
}
V_16 = F_52 ( V_8 , V_50 ) ;
if ( ! V_16 )
return F_38 ( - V_98 ) ;
( void ) F_25 ( V_15 , & V_16 -> rename , L_8 ) ;
( void ) F_25 ( V_15 , & V_16 -> V_99 , L_9 ) ;
V_16 -> V_100 = F_31 ( V_15 ) ;
if ( F_36 ( V_16 -> V_100 ) ) {
error = F_53 ( V_16 -> V_100 ) ;
V_16 -> V_100 = NULL ;
goto V_37;
}
if ( V_16 -> V_100 ) {
if ( ! F_19 ( V_15 , & V_48 , NULL ) )
goto V_37;
V_16 -> V_101 = V_48 ;
}
if ( ! F_18 ( V_15 , V_66 , L_10 ) )
goto V_37;
if ( ! F_19 ( V_15 , & V_48 , NULL ) )
goto V_37;
if ( V_48 & V_102 )
V_16 -> V_53 |= V_103 ;
if ( ! F_19 ( V_15 , & V_48 , NULL ) )
goto V_37;
if ( V_48 == V_104 || ( V_15 -> V_105 & V_106 ) )
V_16 -> V_58 = V_107 ;
else if ( V_48 == V_108 )
V_16 -> V_58 = V_109 ;
else if ( V_48 == V_110 )
V_16 -> V_58 = V_111 ;
if ( ! F_19 ( V_15 , & V_48 , NULL ) )
goto V_37;
if ( V_48 )
V_16 -> V_112 = V_113 ;
if ( ! F_18 ( V_15 , V_75 , NULL ) )
goto V_37;
if ( F_19 ( V_15 , & V_16 -> V_114 , L_11 ) )
V_16 -> V_114 |= V_16 -> V_53 & V_115 ;
else
V_16 -> V_114 = V_115 ;
if ( ! F_19 ( V_15 , & ( V_16 -> V_116 . V_117 . V_118 [ 0 ] ) , NULL ) )
goto V_37;
if ( ! F_19 ( V_15 , & ( V_16 -> V_116 . V_112 . V_118 [ 0 ] ) , NULL ) )
goto V_37;
if ( ! F_19 ( V_15 , & ( V_16 -> V_116 . V_119 . V_118 [ 0 ] ) , NULL ) )
goto V_37;
if ( ! F_19 ( V_15 , & V_97 . V_118 [ 0 ] , NULL ) )
goto V_37;
if ( F_18 ( V_15 , V_66 , L_12 ) ) {
if ( ! F_19 ( V_15 , & ( V_16 -> V_116 . V_117 . V_118 [ 1 ] ) , NULL ) )
goto V_37;
if ( ! F_19 ( V_15 , & ( V_16 -> V_116 . V_112 . V_118 [ 1 ] ) , NULL ) )
goto V_37;
if ( ! F_19 ( V_15 , & ( V_16 -> V_116 . V_119 . V_118 [ 1 ] ) , NULL ) )
goto V_37;
if ( ! F_19 ( V_15 , & ( V_97 . V_118 [ 1 ] ) , NULL ) )
goto V_37;
if ( ! F_18 ( V_15 , V_75 , NULL ) )
goto V_37;
}
if ( F_18 ( V_15 , V_66 , L_13 ) ) {
if ( ! F_19 ( V_15 , & ( V_16 -> V_116 . V_120 . V_118 [ 0 ] ) , NULL ) )
goto V_37;
if ( ! F_19 ( V_15 , & ( V_16 -> V_116 . V_120 . V_118 [ 1 ] ) , NULL ) )
goto V_37;
if ( ! F_18 ( V_15 , V_75 , NULL ) )
goto V_37;
}
if ( ! F_42 ( V_15 , V_16 ) )
goto V_37;
if ( F_18 ( V_15 , V_66 , L_14 ) ) {
V_16 -> V_121 . V_52 = F_31 ( V_15 ) ;
if ( F_36 ( V_16 -> V_121 . V_52 ) ) {
error = F_53 ( V_16 -> V_121 . V_52 ) ;
V_16 -> V_121 . V_52 = NULL ;
goto V_37;
} else if ( ! V_16 -> V_121 . V_52 ) {
error = - V_65 ;
goto V_37;
}
if ( ! F_19 ( V_15 , & V_16 -> V_121 . V_18 [ 0 ] , L_15 ) )
V_16 -> V_121 . V_18 [ 0 ] = V_122 ;
for ( V_54 = V_123 ; V_54 <= V_124 ; V_54 ++ ) {
V_16 -> V_121 . V_18 [ V_54 ] =
F_54 ( V_16 -> V_121 . V_52 ,
V_16 -> V_121 . V_18 [ 0 ] ,
V_54 ) ;
}
if ( ! F_18 ( V_15 , V_75 , NULL ) )
goto V_37;
} else
V_16 -> V_121 . V_52 = F_55 ( V_125 ) ;
V_16 -> V_67 . V_52 = F_31 ( V_15 ) ;
if ( F_36 ( V_16 -> V_67 . V_52 ) ) {
error = F_53 ( V_16 -> V_67 . V_52 ) ;
V_16 -> V_67 . V_52 = NULL ;
goto V_37;
} else if ( V_16 -> V_67 . V_52 ) {
if ( ! F_19 ( V_15 , & V_16 -> V_67 . V_18 , L_16 ) )
V_16 -> V_67 . V_18 = V_122 ;
} else if ( V_16 -> V_121 . V_52 &&
V_16 -> V_121 . V_18 [ V_123 ] ) {
V_16 -> V_67 . V_52 = F_55 ( V_16 -> V_121 . V_52 ) ;
V_16 -> V_67 . V_18 = V_16 -> V_121 . V_18 [ V_123 ] ;
} else
V_16 -> V_67 . V_52 = F_55 ( V_125 ) ;
if ( ! F_39 ( V_15 , V_16 ) )
goto V_37;
if ( F_18 ( V_15 , V_66 , L_17 ) ) {
V_16 -> V_38 = F_40 ( sizeof( * V_16 -> V_38 ) , V_50 ) ;
if ( ! V_16 -> V_38 )
goto V_37;
V_96 . V_126 = 3 ;
V_96 . V_127 = sizeof( void * ) ;
V_96 . V_128 = F_56 ( struct V_91 , V_87 ) ;
V_96 . V_129 = F_56 ( struct V_91 , V_130 ) ;
V_96 . V_131 = F_46 ;
V_96 . V_132 = F_48 ;
if ( F_57 ( V_16 -> V_38 , & V_96 ) )
goto V_37;
while ( F_26 ( V_15 , & V_87 , NULL ) ) {
V_38 = F_40 ( sizeof( * V_38 ) , V_50 ) ;
if ( ! V_38 ) {
F_11 ( V_87 ) ;
goto V_37;
}
V_38 -> V_87 = V_87 ;
V_38 -> V_27 = F_24 ( V_15 , & V_38 -> V_38 , NULL ) ;
V_38 -> V_38 = F_44 ( V_38 -> V_38 , V_38 -> V_27 ) ;
if ( V_38 -> V_27 && ! V_38 -> V_38 ) {
F_11 ( V_38 -> V_87 ) ;
F_11 ( V_38 ) ;
goto V_37;
}
F_58 ( V_16 -> V_38 , & V_38 -> V_130 ,
V_16 -> V_38 -> V_85 ) ;
}
if ( ! F_18 ( V_15 , V_75 , NULL ) )
goto V_37;
}
if ( ! F_18 ( V_15 , V_75 , NULL ) )
goto V_37;
return V_16 ;
V_37:
if ( V_16 )
V_8 = NULL ;
else if ( ! V_8 )
V_8 = L_18 ;
F_5 ( V_16 , NULL , V_8 , L_19 , V_15 ,
error ) ;
F_59 ( V_16 ) ;
return F_38 ( error ) ;
}
static int F_60 ( struct V_14 * V_15 , int V_133 , const char * * V_7 )
{
int error = - V_134 ;
const char * V_8 = NULL ;
* V_7 = NULL ;
if ( ! F_19 ( V_15 , & V_15 -> V_105 , L_20 ) ) {
if ( V_133 ) {
F_5 ( NULL , NULL , NULL , L_21 ,
V_15 , error ) ;
return error ;
}
}
if ( F_61 ( V_15 -> V_105 , V_135 ) && F_62 ( V_15 -> V_105 , V_136 ) ) {
F_5 ( NULL , NULL , NULL , L_22 ,
V_15 , error ) ;
return error ;
}
if ( F_25 ( V_15 , & V_8 , L_23 ) ) {
if ( * V_8 == '\0' ) {
F_5 ( NULL , NULL , NULL , L_24 ,
V_15 , error ) ;
return error ;
}
if ( * V_7 && strcmp ( * V_7 , V_8 ) )
F_5 ( NULL , NULL , NULL , L_25 , V_15 ,
error ) ;
else if ( ! * V_7 )
* V_7 = V_8 ;
}
return 0 ;
}
static bool F_63 ( int V_137 , int V_138 )
{
int V_139 , V_140 ;
V_140 = V_137 & V_141 ;
V_139 = V_137 & V_142 ;
if ( V_140 == V_143 && V_139 >= V_138 )
return 0 ;
return 1 ;
}
static bool F_64 ( struct V_51 * V_52 , int V_138 )
{
int V_54 ;
for ( V_54 = 0 ; V_54 < V_52 -> V_55 [ V_56 ] -> V_57 ; V_54 ++ ) {
if ( ! F_63 ( F_65 ( V_52 , V_54 ) , V_138 ) )
return 0 ;
if ( ! F_63 ( F_66 ( V_52 , V_54 ) , V_138 ) )
return 0 ;
}
return 1 ;
}
static int F_67 ( struct V_10 * V_16 )
{
if ( V_16 -> V_67 . V_52 &&
! F_64 ( V_16 -> V_67 . V_52 ,
V_16 -> V_67 . V_68 . V_27 ) ) {
F_5 ( V_16 , NULL , NULL , L_26 ,
NULL , - V_65 ) ;
return - V_65 ;
}
return 0 ;
}
void F_68 ( struct V_144 * V_145 )
{
if ( V_145 ) {
F_69 ( V_145 -> rename ) ;
F_69 ( V_145 -> V_146 ) ;
F_69 ( V_145 -> V_11 ) ;
F_70 ( V_145 -> V_12 ) ;
F_11 ( V_145 ) ;
}
}
struct V_144 * F_71 ( void )
{
struct V_144 * V_145 = F_40 ( sizeof( * V_145 ) , V_50 ) ;
if ( V_145 )
F_72 ( & V_145 -> V_147 ) ;
return V_145 ;
}
int F_73 ( struct V_23 * V_148 , struct V_149 * V_150 ,
const char * * V_7 )
{
struct V_144 * V_48 , * V_145 ;
struct V_10 * V_16 = NULL ;
int error ;
struct V_14 V_15 = {
. V_18 = V_148 -> V_38 ,
. V_28 = V_148 -> V_38 + V_148 -> V_27 ,
. V_9 = V_148 -> V_38 ,
} ;
* V_7 = NULL ;
while ( V_15 . V_9 < V_15 . V_28 ) {
char * V_12 = NULL ;
void * V_18 ;
error = F_60 ( & V_15 , V_15 . V_9 == V_15 . V_18 , V_7 ) ;
if ( error )
goto V_37;
V_18 = V_15 . V_9 ;
V_16 = F_49 ( & V_15 , & V_12 ) ;
if ( F_36 ( V_16 ) ) {
error = F_53 ( V_16 ) ;
goto V_37;
}
error = F_67 ( V_16 ) ;
if ( error )
goto V_151;
if ( V_152 )
error = F_74 ( V_16 , V_15 . V_105 , V_18 ,
V_15 . V_9 - V_18 ) ;
if ( error )
goto V_151;
V_145 = F_71 () ;
if ( ! V_145 ) {
error = - V_98 ;
goto V_151;
}
V_145 -> V_11 = V_16 ;
V_145 -> V_12 = V_12 ;
F_75 ( & V_145 -> V_147 , V_150 ) ;
}
V_148 -> V_153 = V_15 . V_105 & V_154 ;
if ( V_152 ) {
V_148 -> V_26 = F_76 ( V_148 -> V_38 , V_148 -> V_27 ) ;
if ( F_36 ( V_148 -> V_26 ) ) {
error = F_53 ( V_148 -> V_26 ) ;
V_148 -> V_26 = NULL ;
goto V_37;
}
}
return 0 ;
V_151:
F_69 ( V_16 ) ;
V_37:
F_77 (ent, tmp, lh, list) {
F_78 ( & V_145 -> V_147 ) ;
F_68 ( V_145 ) ;
}
return error ;
}
