static void F_1 ( struct V_1 * V_2 , void * V_3 )
{
struct V_4 * V_5 = V_3 ;
if ( V_5 -> V_6 . V_7 . V_8 ) {
struct V_9 * V_10 = V_5 -> V_6 . V_7 . V_8 ;
F_2 ( V_2 , L_1 ) ;
F_3 ( V_2 , V_10 -> V_11 . V_12 ) ;
}
if ( V_5 -> V_6 . V_7 . V_13 )
F_2 ( V_2 , L_2 , V_5 -> V_6 . V_7 . V_13 ) ;
}
static int F_4 ( struct V_9 * V_14 , const char * V_10 ,
const char * V_15 , struct V_16 * V_17 , int error )
{
struct V_9 * V_18 = F_5 () ;
struct V_4 V_5 ;
F_6 ( & V_5 , V_19 ) ;
V_5 . V_6 . V_7 . V_13 = V_17 -> V_13 - V_17 -> V_20 ;
V_5 . V_6 . V_7 . V_8 = V_14 ;
V_5 . V_6 . V_10 = V_10 ;
V_5 . V_6 . V_15 = V_15 ;
V_5 . V_6 . error = error ;
return F_7 ( V_21 , V_18 , V_22 , & V_5 ,
F_1 ) ;
}
static bool F_8 ( struct V_16 * V_17 , T_1 V_23 )
{
return ( V_23 <= V_17 -> V_24 - V_17 -> V_13 ) ;
}
static T_1 F_9 ( struct V_16 * V_17 , char * * V_25 )
{
T_1 V_23 = 0 ;
if ( ! F_8 ( V_17 , sizeof( V_26 ) ) )
return 0 ;
V_23 = F_10 ( F_11 ( ( V_26 * ) V_17 -> V_13 ) ) ;
V_17 -> V_13 += sizeof( V_26 ) ;
if ( ! F_8 ( V_17 , V_23 ) )
return 0 ;
* V_25 = V_17 -> V_13 ;
V_17 -> V_13 += V_23 ;
return V_23 ;
}
static bool F_12 ( struct V_16 * V_17 , enum V_27 V_28 )
{
if ( ! F_8 ( V_17 , 1 ) )
return 0 ;
if ( * ( V_29 * ) V_17 -> V_13 != V_28 )
return 0 ;
V_17 -> V_13 ++ ;
return 1 ;
}
static bool F_13 ( struct V_16 * V_17 , enum V_27 V_28 , const char * V_10 )
{
void * V_13 = V_17 -> V_13 ;
if ( F_12 ( V_17 , V_30 ) ) {
char * V_31 = NULL ;
T_1 V_23 = F_9 ( V_17 , & V_31 ) ;
if ( V_10 && ( ! V_23 || strcmp ( V_10 , V_31 ) ) )
goto V_32;
} else if ( V_10 ) {
goto V_32;
}
if ( F_12 ( V_17 , V_28 ) )
return 1 ;
V_32:
V_17 -> V_13 = V_13 ;
return 0 ;
}
static bool F_14 ( struct V_16 * V_17 , T_2 * V_33 , const char * V_10 )
{
if ( F_13 ( V_17 , V_34 , V_10 ) ) {
if ( ! F_8 ( V_17 , sizeof( T_2 ) ) )
return 0 ;
if ( V_33 )
* V_33 = F_15 ( F_11 ( ( T_2 * ) V_17 -> V_13 ) ) ;
V_17 -> V_13 += sizeof( T_2 ) ;
return 1 ;
}
return 0 ;
}
static bool F_16 ( struct V_16 * V_17 , T_3 * V_33 , const char * V_10 )
{
if ( F_13 ( V_17 , V_35 , V_10 ) ) {
if ( ! F_8 ( V_17 , sizeof( T_3 ) ) )
return 0 ;
if ( V_33 )
* V_33 = F_17 ( F_11 ( ( T_3 * ) V_17 -> V_13 ) ) ;
V_17 -> V_13 += sizeof( T_3 ) ;
return 1 ;
}
return 0 ;
}
static T_1 F_18 ( struct V_16 * V_17 , const char * V_10 )
{
if ( F_13 ( V_17 , V_36 , V_10 ) ) {
int V_23 ;
if ( ! F_8 ( V_17 , sizeof( V_26 ) ) )
return 0 ;
V_23 = ( int ) F_10 ( F_11 ( ( V_26 * ) V_17 -> V_13 ) ) ;
V_17 -> V_13 += sizeof( V_26 ) ;
return V_23 ;
}
return 0 ;
}
static T_1 F_19 ( struct V_16 * V_17 , char * * V_37 , const char * V_10 )
{
if ( F_13 ( V_17 , V_38 , V_10 ) ) {
T_2 V_23 ;
if ( ! F_8 ( V_17 , sizeof( T_2 ) ) )
return 0 ;
V_23 = F_15 ( F_11 ( ( T_2 * ) V_17 -> V_13 ) ) ;
V_17 -> V_13 += sizeof( T_2 ) ;
if ( F_8 ( V_17 , ( T_1 ) V_23 ) ) {
* V_37 = V_17 -> V_13 ;
V_17 -> V_13 += V_23 ;
return V_23 ;
}
}
return 0 ;
}
static int F_20 ( struct V_16 * V_17 , const char * * string , const char * V_10 )
{
char * V_39 ;
T_1 V_23 = 0 ;
void * V_13 = V_17 -> V_13 ;
* string = NULL ;
if ( F_13 ( V_17 , V_40 , V_10 ) ) {
V_23 = F_9 ( V_17 , & V_39 ) ;
if ( V_23 ) {
if ( V_39 [ V_23 - 1 ] != 0 )
goto V_32;
* string = V_39 ;
}
}
return V_23 ;
V_32:
V_17 -> V_13 = V_13 ;
return 0 ;
}
static int F_21 ( struct V_16 * V_17 , char * * string , const char * V_10 )
{
const char * V_41 ;
void * V_13 = V_17 -> V_13 ;
int V_42 = F_20 ( V_17 , & V_41 , V_10 ) ;
* string = NULL ;
if ( ! V_42 )
return 0 ;
* string = F_22 ( V_41 , V_42 , V_22 ) ;
if ( ! * string ) {
V_17 -> V_13 = V_13 ;
return 0 ;
}
return V_42 ;
}
static bool F_23 ( struct V_43 * V_44 , int V_45 )
{
int V_46 ;
for ( V_46 = 0 ; V_46 < V_44 -> V_47 [ V_48 ] -> V_49 ; V_46 ++ ) {
int V_50 = F_24 ( V_44 ) [ V_46 ] ;
if ( V_50 & ~ V_51 )
return 0 ;
if ( F_25 ( V_44 ) [ V_46 ] & ~ V_52 )
return 0 ;
}
return 1 ;
}
static struct V_43 * F_26 ( struct V_16 * V_17 )
{
char * V_37 = NULL ;
T_1 V_23 ;
struct V_43 * V_44 = NULL ;
V_23 = F_19 ( V_17 , & V_37 , L_3 ) ;
if ( V_23 ) {
T_1 V_53 = V_37 - ( char * ) V_17 -> V_20 ;
T_1 V_54 = F_27 ( V_53 , 8 ) - V_53 ;
int V_45 = F_28 ( V_55 ) |
F_29 ( V_55 ) ;
if ( V_56 )
V_45 |= V_57 ;
V_44 = F_30 ( V_37 + V_54 , V_23 - V_54 , V_45 ) ;
if ( F_31 ( V_44 ) )
return V_44 ;
if ( ! F_23 ( V_44 , V_45 ) )
goto V_32;
}
return V_44 ;
V_32:
F_32 ( V_44 ) ;
return F_33 ( - V_58 ) ;
}
static bool F_34 ( struct V_16 * V_17 , struct V_9 * V_18 )
{
void * V_13 = V_17 -> V_13 ;
if ( F_13 ( V_17 , V_59 , L_4 ) ) {
int V_46 , V_23 ;
V_23 = F_18 ( V_17 , NULL ) ;
if ( V_23 > 16 - 4 )
goto V_32;
V_18 -> V_60 . V_61 . V_62 = F_35 ( sizeof( char * ) * V_23 ,
V_22 ) ;
if ( ! V_18 -> V_60 . V_61 . V_62 )
goto V_32;
V_18 -> V_60 . V_61 . V_23 = V_23 ;
for ( V_46 = 0 ; V_46 < V_23 ; V_46 ++ ) {
char * V_63 ;
int V_64 , V_65 , V_23 = F_21 ( V_17 , & V_63 , NULL ) ;
if ( ! V_23 )
goto V_32;
V_18 -> V_60 . V_61 . V_62 [ V_46 ] = V_63 ;
if ( isspace ( * V_63 ) )
goto V_32;
for ( V_64 = V_65 = 0 ; V_65 < V_23 - 2 ; V_65 ++ ) {
if ( ! V_63 [ V_65 ] )
V_64 ++ ;
}
if ( * V_63 == ':' ) {
if ( V_64 != 1 )
goto V_32;
if ( ! V_63 [ 1 ] )
goto V_32;
} else if ( V_64 )
goto V_32;
}
if ( ! F_13 ( V_17 , V_66 , NULL ) )
goto V_32;
if ( ! F_13 ( V_17 , V_67 , NULL ) )
goto V_32;
}
return 1 ;
V_32:
F_36 ( & V_18 -> V_60 . V_61 ) ;
V_17 -> V_13 = V_13 ;
return 0 ;
}
static bool F_37 ( struct V_16 * V_17 , struct V_9 * V_18 )
{
void * V_13 = V_17 -> V_13 ;
if ( F_13 ( V_17 , V_59 , L_5 ) ) {
int V_46 , V_23 ;
T_2 V_41 = 0 ;
if ( ! F_14 ( V_17 , & V_41 , NULL ) )
goto V_32;
V_18 -> V_68 . V_69 = V_41 ;
V_23 = F_18 ( V_17 , NULL ) ;
if ( V_23 > V_70 )
goto V_32;
for ( V_46 = 0 ; V_46 < V_23 ; V_46 ++ ) {
T_3 V_41 = 0 ;
int V_71 = F_38 ( V_46 ) ;
if ( ! F_16 ( V_17 , & V_41 , NULL ) )
goto V_32;
V_18 -> V_68 . V_72 [ V_71 ] . V_73 = V_41 ;
}
if ( ! F_13 ( V_17 , V_66 , NULL ) )
goto V_32;
if ( ! F_13 ( V_17 , V_67 , NULL ) )
goto V_32;
}
return 1 ;
V_32:
V_17 -> V_13 = V_13 ;
return 0 ;
}
static struct V_9 * F_39 ( struct V_16 * V_17 )
{
struct V_9 * V_18 = NULL ;
const char * V_10 = NULL ;
int error = - V_58 ;
T_4 V_74 ;
T_2 V_41 ;
if ( ! F_13 ( V_17 , V_59 , L_6 ) )
goto V_32;
if ( ! F_20 ( V_17 , & V_10 , NULL ) )
goto V_32;
V_18 = F_40 ( V_10 ) ;
if ( ! V_18 )
return F_33 ( - V_75 ) ;
( void ) F_20 ( V_17 , & V_18 -> rename , L_7 ) ;
V_18 -> V_76 = F_26 ( V_17 ) ;
if ( F_31 ( V_18 -> V_76 ) ) {
error = F_41 ( V_18 -> V_76 ) ;
V_18 -> V_76 = NULL ;
goto V_32;
}
if ( V_18 -> V_76 ) {
if ( ! F_14 ( V_17 , & V_41 , NULL ) )
goto V_32;
V_18 -> V_77 = V_41 ;
}
if ( ! F_13 ( V_17 , V_59 , L_8 ) )
goto V_32;
if ( ! F_14 ( V_17 , & V_41 , NULL ) )
goto V_32;
if ( V_41 )
V_18 -> V_45 |= V_78 ;
if ( ! F_14 ( V_17 , & V_41 , NULL ) )
goto V_32;
if ( V_41 )
V_18 -> V_50 = V_79 ;
if ( ! F_14 ( V_17 , & V_41 , NULL ) )
goto V_32;
if ( V_41 )
V_18 -> V_80 = V_81 ;
if ( ! F_13 ( V_17 , V_67 , NULL ) )
goto V_32;
if ( F_14 ( V_17 , & V_18 -> V_82 , L_9 ) )
V_18 -> V_82 |= V_18 -> V_45 & V_83 ;
else
V_18 -> V_82 = V_83 ;
if ( ! F_14 ( V_17 , & ( V_18 -> V_84 . V_85 . V_86 [ 0 ] ) , NULL ) )
goto V_32;
if ( ! F_14 ( V_17 , & ( V_18 -> V_84 . V_80 . V_86 [ 0 ] ) , NULL ) )
goto V_32;
if ( ! F_14 ( V_17 , & ( V_18 -> V_84 . V_87 . V_86 [ 0 ] ) , NULL ) )
goto V_32;
if ( ! F_14 ( V_17 , & V_74 . V_86 [ 0 ] , NULL ) )
goto V_32;
if ( F_13 ( V_17 , V_59 , L_10 ) ) {
if ( ! F_14 ( V_17 , & ( V_18 -> V_84 . V_85 . V_86 [ 1 ] ) , NULL ) )
goto V_32;
if ( ! F_14 ( V_17 , & ( V_18 -> V_84 . V_80 . V_86 [ 1 ] ) , NULL ) )
goto V_32;
if ( ! F_14 ( V_17 , & ( V_18 -> V_84 . V_87 . V_86 [ 1 ] ) , NULL ) )
goto V_32;
if ( ! F_14 ( V_17 , & ( V_74 . V_86 [ 1 ] ) , NULL ) )
goto V_32;
if ( ! F_13 ( V_17 , V_67 , NULL ) )
goto V_32;
}
if ( F_13 ( V_17 , V_59 , L_11 ) ) {
if ( ! F_14 ( V_17 , & ( V_18 -> V_84 . V_88 . V_86 [ 0 ] ) , NULL ) )
goto V_32;
if ( ! F_14 ( V_17 , & ( V_18 -> V_84 . V_88 . V_86 [ 1 ] ) , NULL ) )
goto V_32;
}
if ( ! F_37 ( V_17 , V_18 ) )
goto V_32;
V_18 -> V_60 . V_44 = F_26 ( V_17 ) ;
if ( F_31 ( V_18 -> V_60 . V_44 ) ) {
error = F_41 ( V_18 -> V_60 . V_44 ) ;
V_18 -> V_60 . V_44 = NULL ;
goto V_32;
}
if ( ! F_14 ( V_17 , & V_18 -> V_60 . V_20 , L_12 ) )
V_18 -> V_60 . V_20 = V_89 ;
if ( ! F_34 ( V_17 , V_18 ) )
goto V_32;
if ( ! F_13 ( V_17 , V_67 , NULL ) )
goto V_32;
return V_18 ;
V_32:
if ( V_18 )
V_10 = NULL ;
else if ( ! V_10 )
V_10 = L_13 ;
F_4 ( V_18 , V_10 , L_14 , V_17 , error ) ;
F_42 ( V_18 ) ;
return F_33 ( error ) ;
}
static int F_43 ( struct V_16 * V_17 , const char * * V_90 )
{
int error = - V_91 ;
if ( ! F_14 ( V_17 , & V_17 -> V_92 , L_15 ) ) {
F_4 ( NULL , NULL , L_16 , V_17 , error ) ;
return error ;
}
if ( V_17 -> V_92 != 5 ) {
F_4 ( NULL , NULL , L_17 , V_17 ,
error ) ;
return error ;
}
if ( ! F_20 ( V_17 , V_90 , L_18 ) )
* V_90 = NULL ;
return 0 ;
}
static bool F_44 ( int V_93 , int V_94 )
{
int V_95 , V_96 ;
V_96 = V_93 & V_97 ;
V_95 = V_93 & V_98 ;
if ( V_96 == V_99 && V_95 > V_94 )
return 0 ;
return 1 ;
}
static bool F_45 ( struct V_43 * V_44 , int V_94 )
{
int V_46 ;
for ( V_46 = 0 ; V_46 < V_44 -> V_47 [ V_48 ] -> V_49 ; V_46 ++ ) {
if ( ! F_44 ( F_46 ( V_44 , V_46 ) , V_94 ) )
return 0 ;
if ( ! F_44 ( F_47 ( V_44 , V_46 ) , V_94 ) )
return 0 ;
}
return 1 ;
}
static int F_48 ( struct V_9 * V_18 )
{
if ( V_56 ) {
if ( V_18 -> V_60 . V_44 &&
! F_45 ( V_18 -> V_60 . V_44 ,
V_18 -> V_60 . V_61 . V_23 ) ) {
F_4 ( V_18 , NULL , L_19 ,
NULL , - V_58 ) ;
return - V_58 ;
}
}
return 0 ;
}
struct V_9 * F_49 ( void * V_100 , T_1 V_23 , const char * * V_90 )
{
struct V_9 * V_18 = NULL ;
int error ;
struct V_16 V_17 = {
. V_20 = V_100 ,
. V_24 = V_100 + V_23 ,
. V_13 = V_100 ,
} ;
error = F_43 ( & V_17 , V_90 ) ;
if ( error )
return F_33 ( error ) ;
V_18 = F_39 ( & V_17 ) ;
if ( F_31 ( V_18 ) )
return V_18 ;
error = F_48 ( V_18 ) ;
if ( error ) {
F_42 ( V_18 ) ;
V_18 = F_33 ( error ) ;
}
return V_18 ;
}
