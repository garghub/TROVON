static void F_1 ( struct V_1 * V_2 , void * V_3 )
{
struct V_4 * V_5 = V_3 ;
if ( V_5 -> V_6 -> V_7 . V_8 ) {
struct V_9 * V_10 = V_5 -> V_6 -> V_7 . V_8 ;
F_2 ( V_2 , L_1 ) ;
F_3 ( V_2 , V_10 -> V_11 . V_12 ) ;
}
if ( V_5 -> V_6 -> V_7 . V_13 )
F_2 ( V_2 , L_2 , V_5 -> V_6 -> V_7 . V_13 ) ;
}
static int F_4 ( struct V_9 * V_14 , const char * V_10 ,
const char * V_15 , struct V_16 * V_17 , int error )
{
struct V_9 * V_18 = F_5 () ;
struct V_4 V_5 ;
struct V_19 V_6 = { 0 ,} ;
F_6 ( & V_5 , V_20 ) ;
V_5 . V_6 = & V_6 ;
if ( V_17 )
V_6 . V_7 . V_13 = V_17 -> V_13 - V_17 -> V_21 ;
V_6 . V_7 . V_8 = V_14 ;
V_6 . V_10 = V_10 ;
V_6 . V_15 = V_15 ;
V_6 . error = error ;
return F_7 ( V_22 , V_18 , V_23 , & V_5 ,
F_1 ) ;
}
static bool F_8 ( struct V_16 * V_17 , T_1 V_24 )
{
return ( V_24 <= V_17 -> V_25 - V_17 -> V_13 ) ;
}
static T_1 F_9 ( struct V_16 * V_17 , char * * V_26 )
{
T_1 V_24 = 0 ;
if ( ! F_8 ( V_17 , sizeof( V_27 ) ) )
return 0 ;
V_24 = F_10 ( F_11 ( ( V_27 * ) V_17 -> V_13 ) ) ;
V_17 -> V_13 += sizeof( V_27 ) ;
if ( ! F_8 ( V_17 , V_24 ) )
return 0 ;
* V_26 = V_17 -> V_13 ;
V_17 -> V_13 += V_24 ;
return V_24 ;
}
static bool F_12 ( struct V_16 * V_17 , enum V_28 V_29 )
{
if ( ! F_8 ( V_17 , 1 ) )
return 0 ;
if ( * ( V_30 * ) V_17 -> V_13 != V_29 )
return 0 ;
V_17 -> V_13 ++ ;
return 1 ;
}
static bool F_13 ( struct V_16 * V_17 , enum V_28 V_29 , const char * V_10 )
{
void * V_13 = V_17 -> V_13 ;
if ( F_12 ( V_17 , V_31 ) ) {
char * V_32 = NULL ;
T_1 V_24 = F_9 ( V_17 , & V_32 ) ;
if ( V_10 && ( ! V_24 || strcmp ( V_10 , V_32 ) ) )
goto V_33;
} else if ( V_10 ) {
goto V_33;
}
if ( F_12 ( V_17 , V_29 ) )
return 1 ;
V_33:
V_17 -> V_13 = V_13 ;
return 0 ;
}
static bool F_14 ( struct V_16 * V_17 , T_2 * V_34 , const char * V_10 )
{
if ( F_13 ( V_17 , V_35 , V_10 ) ) {
if ( ! F_8 ( V_17 , sizeof( T_2 ) ) )
return 0 ;
if ( V_34 )
* V_34 = F_15 ( F_11 ( ( T_2 * ) V_17 -> V_13 ) ) ;
V_17 -> V_13 += sizeof( T_2 ) ;
return 1 ;
}
return 0 ;
}
static bool F_16 ( struct V_16 * V_17 , T_3 * V_34 , const char * V_10 )
{
if ( F_13 ( V_17 , V_36 , V_10 ) ) {
if ( ! F_8 ( V_17 , sizeof( T_3 ) ) )
return 0 ;
if ( V_34 )
* V_34 = F_17 ( F_11 ( ( T_3 * ) V_17 -> V_13 ) ) ;
V_17 -> V_13 += sizeof( T_3 ) ;
return 1 ;
}
return 0 ;
}
static T_1 F_18 ( struct V_16 * V_17 , const char * V_10 )
{
if ( F_13 ( V_17 , V_37 , V_10 ) ) {
int V_24 ;
if ( ! F_8 ( V_17 , sizeof( V_27 ) ) )
return 0 ;
V_24 = ( int ) F_10 ( F_11 ( ( V_27 * ) V_17 -> V_13 ) ) ;
V_17 -> V_13 += sizeof( V_27 ) ;
return V_24 ;
}
return 0 ;
}
static T_1 F_19 ( struct V_16 * V_17 , char * * V_38 , const char * V_10 )
{
if ( F_13 ( V_17 , V_39 , V_10 ) ) {
T_2 V_24 ;
if ( ! F_8 ( V_17 , sizeof( T_2 ) ) )
return 0 ;
V_24 = F_15 ( F_11 ( ( T_2 * ) V_17 -> V_13 ) ) ;
V_17 -> V_13 += sizeof( T_2 ) ;
if ( F_8 ( V_17 , ( T_1 ) V_24 ) ) {
* V_38 = V_17 -> V_13 ;
V_17 -> V_13 += V_24 ;
return V_24 ;
}
}
return 0 ;
}
static int F_20 ( struct V_16 * V_17 , const char * * string , const char * V_10 )
{
char * V_40 ;
T_1 V_24 = 0 ;
void * V_13 = V_17 -> V_13 ;
* string = NULL ;
if ( F_13 ( V_17 , V_41 , V_10 ) ) {
V_24 = F_9 ( V_17 , & V_40 ) ;
if ( V_24 ) {
if ( V_40 [ V_24 - 1 ] != 0 )
goto V_33;
* string = V_40 ;
}
}
return V_24 ;
V_33:
V_17 -> V_13 = V_13 ;
return 0 ;
}
static int F_21 ( struct V_16 * V_17 , char * * string , const char * V_10 )
{
const char * V_42 ;
void * V_13 = V_17 -> V_13 ;
int V_43 = F_20 ( V_17 , & V_42 , V_10 ) ;
* string = NULL ;
if ( ! V_43 )
return 0 ;
* string = F_22 ( V_42 , V_43 , V_23 ) ;
if ( ! * string ) {
V_17 -> V_13 = V_13 ;
return 0 ;
}
return V_43 ;
}
static bool F_23 ( struct V_44 * V_45 , int V_46 )
{
int V_47 ;
for ( V_47 = 0 ; V_47 < V_45 -> V_48 [ V_49 ] -> V_50 ; V_47 ++ ) {
int V_51 = F_24 ( V_45 ) [ V_47 ] ;
if ( V_51 & ~ V_52 )
return 0 ;
if ( F_25 ( V_45 ) [ V_47 ] & ~ V_53 )
return 0 ;
}
return 1 ;
}
static struct V_44 * F_26 ( struct V_16 * V_17 )
{
char * V_38 = NULL ;
T_1 V_24 ;
struct V_44 * V_45 = NULL ;
V_24 = F_19 ( V_17 , & V_38 , L_3 ) ;
if ( V_24 ) {
T_1 V_54 = V_38 - ( char * ) V_17 -> V_21 ;
T_1 V_55 = F_27 ( V_54 , 8 ) - V_54 ;
int V_46 = F_28 ( V_56 ) |
F_29 ( V_56 ) ;
if ( V_57 )
V_46 |= V_58 ;
V_45 = F_30 ( V_38 + V_55 , V_24 - V_55 , V_46 ) ;
if ( F_31 ( V_45 ) )
return V_45 ;
if ( ! F_23 ( V_45 , V_46 ) )
goto V_33;
}
return V_45 ;
V_33:
F_32 ( V_45 ) ;
return F_33 ( - V_59 ) ;
}
static bool F_34 ( struct V_16 * V_17 , struct V_9 * V_18 )
{
void * V_13 = V_17 -> V_13 ;
if ( F_13 ( V_17 , V_60 , L_4 ) ) {
int V_47 , V_24 ;
V_24 = F_18 ( V_17 , NULL ) ;
if ( V_24 > 16 - 4 )
goto V_33;
V_18 -> V_61 . V_62 . V_63 = F_35 ( sizeof( char * ) * V_24 ,
V_23 ) ;
if ( ! V_18 -> V_61 . V_62 . V_63 )
goto V_33;
V_18 -> V_61 . V_62 . V_24 = V_24 ;
for ( V_47 = 0 ; V_47 < V_24 ; V_47 ++ ) {
char * V_64 ;
int V_65 , V_66 , V_67 = F_21 ( V_17 , & V_64 , NULL ) ;
if ( ! V_67 )
goto V_33;
V_18 -> V_61 . V_62 . V_63 [ V_47 ] = V_64 ;
if ( isspace ( * V_64 ) )
goto V_33;
for ( V_65 = V_66 = 0 ; V_66 < V_67 - 2 ; V_66 ++ ) {
if ( ! V_64 [ V_66 ] )
V_65 ++ ;
}
if ( * V_64 == ':' ) {
if ( V_65 != 1 )
goto V_33;
if ( ! V_64 [ 1 ] )
goto V_33;
} else if ( V_65 )
goto V_33;
}
if ( ! F_13 ( V_17 , V_68 , NULL ) )
goto V_33;
if ( ! F_13 ( V_17 , V_69 , NULL ) )
goto V_33;
}
return 1 ;
V_33:
F_36 ( & V_18 -> V_61 . V_62 ) ;
V_17 -> V_13 = V_13 ;
return 0 ;
}
static bool F_37 ( struct V_16 * V_17 , struct V_9 * V_18 )
{
void * V_13 = V_17 -> V_13 ;
if ( F_13 ( V_17 , V_60 , L_5 ) ) {
int V_47 , V_24 ;
T_2 V_42 = 0 ;
if ( ! F_14 ( V_17 , & V_42 , NULL ) )
goto V_33;
V_18 -> V_70 . V_71 = V_42 ;
V_24 = F_18 ( V_17 , NULL ) ;
if ( V_24 > V_72 )
goto V_33;
for ( V_47 = 0 ; V_47 < V_24 ; V_47 ++ ) {
T_3 V_73 = 0 ;
int V_74 = F_38 ( V_47 ) ;
if ( ! F_16 ( V_17 , & V_73 , NULL ) )
goto V_33;
V_18 -> V_70 . V_75 [ V_74 ] . V_76 = V_73 ;
}
if ( ! F_13 ( V_17 , V_68 , NULL ) )
goto V_33;
if ( ! F_13 ( V_17 , V_69 , NULL ) )
goto V_33;
}
return 1 ;
V_33:
V_17 -> V_13 = V_13 ;
return 0 ;
}
static struct V_9 * F_39 ( struct V_16 * V_17 )
{
struct V_9 * V_18 = NULL ;
const char * V_10 = NULL ;
int V_47 , error = - V_59 ;
T_4 V_77 ;
T_2 V_42 ;
if ( ! F_13 ( V_17 , V_60 , L_6 ) )
goto V_33;
if ( ! F_20 ( V_17 , & V_10 , NULL ) )
goto V_33;
V_18 = F_40 ( V_10 ) ;
if ( ! V_18 )
return F_33 ( - V_78 ) ;
( void ) F_20 ( V_17 , & V_18 -> rename , L_7 ) ;
V_18 -> V_79 = F_26 ( V_17 ) ;
if ( F_31 ( V_18 -> V_79 ) ) {
error = F_41 ( V_18 -> V_79 ) ;
V_18 -> V_79 = NULL ;
goto V_33;
}
if ( V_18 -> V_79 ) {
if ( ! F_14 ( V_17 , & V_42 , NULL ) )
goto V_33;
V_18 -> V_80 = V_42 ;
}
if ( ! F_13 ( V_17 , V_60 , L_8 ) )
goto V_33;
if ( ! F_14 ( V_17 , & V_42 , NULL ) )
goto V_33;
if ( V_42 )
V_18 -> V_46 |= V_81 ;
if ( ! F_14 ( V_17 , & V_42 , NULL ) )
goto V_33;
if ( V_42 )
V_18 -> V_51 = V_82 ;
if ( ! F_14 ( V_17 , & V_42 , NULL ) )
goto V_33;
if ( V_42 )
V_18 -> V_83 = V_84 ;
if ( ! F_13 ( V_17 , V_69 , NULL ) )
goto V_33;
if ( F_14 ( V_17 , & V_18 -> V_85 , L_9 ) )
V_18 -> V_85 |= V_18 -> V_46 & V_86 ;
else
V_18 -> V_85 = V_86 ;
if ( ! F_14 ( V_17 , & ( V_18 -> V_87 . V_88 . V_89 [ 0 ] ) , NULL ) )
goto V_33;
if ( ! F_14 ( V_17 , & ( V_18 -> V_87 . V_83 . V_89 [ 0 ] ) , NULL ) )
goto V_33;
if ( ! F_14 ( V_17 , & ( V_18 -> V_87 . V_90 . V_89 [ 0 ] ) , NULL ) )
goto V_33;
if ( ! F_14 ( V_17 , & V_77 . V_89 [ 0 ] , NULL ) )
goto V_33;
if ( F_13 ( V_17 , V_60 , L_10 ) ) {
if ( ! F_14 ( V_17 , & ( V_18 -> V_87 . V_88 . V_89 [ 1 ] ) , NULL ) )
goto V_33;
if ( ! F_14 ( V_17 , & ( V_18 -> V_87 . V_83 . V_89 [ 1 ] ) , NULL ) )
goto V_33;
if ( ! F_14 ( V_17 , & ( V_18 -> V_87 . V_90 . V_89 [ 1 ] ) , NULL ) )
goto V_33;
if ( ! F_14 ( V_17 , & ( V_77 . V_89 [ 1 ] ) , NULL ) )
goto V_33;
if ( ! F_13 ( V_17 , V_69 , NULL ) )
goto V_33;
}
if ( F_13 ( V_17 , V_60 , L_11 ) ) {
if ( ! F_14 ( V_17 , & ( V_18 -> V_87 . V_91 . V_89 [ 0 ] ) , NULL ) )
goto V_33;
if ( ! F_14 ( V_17 , & ( V_18 -> V_87 . V_91 . V_89 [ 1 ] ) , NULL ) )
goto V_33;
if ( ! F_13 ( V_17 , V_69 , NULL ) )
goto V_33;
}
if ( ! F_37 ( V_17 , V_18 ) )
goto V_33;
if ( F_13 ( V_17 , V_60 , L_12 ) ) {
V_18 -> V_92 . V_45 = F_26 ( V_17 ) ;
if ( F_31 ( V_18 -> V_92 . V_45 ) ) {
error = F_41 ( V_18 -> V_92 . V_45 ) ;
V_18 -> V_92 . V_45 = NULL ;
goto V_33;
}
if ( ! F_14 ( V_17 , & V_18 -> V_92 . V_21 [ 0 ] , L_13 ) )
V_18 -> V_92 . V_21 [ 0 ] = V_93 ;
for ( V_47 = V_94 ; V_47 <= V_95 ; V_47 ++ ) {
V_18 -> V_92 . V_21 [ V_47 ] =
F_42 ( V_18 -> V_92 . V_45 ,
V_18 -> V_92 . V_21 [ 0 ] ,
V_47 ) ;
}
if ( ! F_13 ( V_17 , V_69 , NULL ) )
goto V_33;
}
V_18 -> V_61 . V_45 = F_26 ( V_17 ) ;
if ( F_31 ( V_18 -> V_61 . V_45 ) ) {
error = F_41 ( V_18 -> V_61 . V_45 ) ;
V_18 -> V_61 . V_45 = NULL ;
goto V_33;
}
if ( ! F_14 ( V_17 , & V_18 -> V_61 . V_21 , L_14 ) )
V_18 -> V_61 . V_21 = V_93 ;
if ( ! F_34 ( V_17 , V_18 ) )
goto V_33;
if ( ! F_13 ( V_17 , V_69 , NULL ) )
goto V_33;
return V_18 ;
V_33:
if ( V_18 )
V_10 = NULL ;
else if ( ! V_10 )
V_10 = L_15 ;
F_4 ( V_18 , V_10 , L_16 , V_17 , error ) ;
F_43 ( V_18 ) ;
return F_33 ( error ) ;
}
static int F_44 ( struct V_16 * V_17 , const char * * V_96 )
{
int error = - V_97 ;
if ( ! F_14 ( V_17 , & V_17 -> V_98 , L_17 ) ) {
F_4 ( NULL , NULL , L_18 , V_17 , error ) ;
return error ;
}
if ( V_17 -> V_98 != 5 ) {
F_4 ( NULL , NULL , L_19 , V_17 ,
error ) ;
return error ;
}
if ( ! F_20 ( V_17 , V_96 , L_20 ) )
* V_96 = NULL ;
return 0 ;
}
static bool F_45 ( int V_99 , int V_100 )
{
int V_101 , V_102 ;
V_102 = V_99 & V_103 ;
V_101 = V_99 & V_104 ;
if ( V_102 == V_105 && V_101 > V_100 )
return 0 ;
return 1 ;
}
static bool F_46 ( struct V_44 * V_45 , int V_100 )
{
int V_47 ;
for ( V_47 = 0 ; V_47 < V_45 -> V_48 [ V_49 ] -> V_50 ; V_47 ++ ) {
if ( ! F_45 ( F_47 ( V_45 , V_47 ) , V_100 ) )
return 0 ;
if ( ! F_45 ( F_48 ( V_45 , V_47 ) , V_100 ) )
return 0 ;
}
return 1 ;
}
static int F_49 ( struct V_9 * V_18 )
{
if ( V_57 ) {
if ( V_18 -> V_61 . V_45 &&
! F_46 ( V_18 -> V_61 . V_45 ,
V_18 -> V_61 . V_62 . V_24 ) ) {
F_4 ( V_18 , NULL , L_21 ,
NULL , - V_59 ) ;
return - V_59 ;
}
}
return 0 ;
}
struct V_9 * F_50 ( void * V_106 , T_1 V_24 , const char * * V_96 )
{
struct V_9 * V_18 = NULL ;
int error ;
struct V_16 V_17 = {
. V_21 = V_106 ,
. V_25 = V_106 + V_24 ,
. V_13 = V_106 ,
} ;
error = F_44 ( & V_17 , V_96 ) ;
if ( error )
return F_33 ( error ) ;
V_18 = F_39 ( & V_17 ) ;
if ( F_31 ( V_18 ) )
return V_18 ;
error = F_49 ( V_18 ) ;
if ( error ) {
F_43 ( V_18 ) ;
V_18 = F_33 ( error ) ;
}
return V_18 ;
}
