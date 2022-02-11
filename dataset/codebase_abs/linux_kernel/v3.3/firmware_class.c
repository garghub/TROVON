static bool F_1 ( struct V_1 * V_2 , const char * V_3 )
{
struct V_4 * V_5 ;
for ( V_5 = V_6 ; V_5 != V_7 ; V_5 ++ ) {
if ( strcmp ( V_3 , V_5 -> V_3 ) == 0 ) {
V_2 -> V_8 = V_5 -> V_8 ;
V_2 -> V_9 = V_5 -> V_9 ;
return true ;
}
}
return false ;
}
static bool F_2 ( const struct V_1 * V_2 )
{
struct V_4 * V_5 ;
for ( V_5 = V_6 ; V_5 != V_7 ; V_5 ++ )
if ( V_2 -> V_9 == V_5 -> V_9 )
return true ;
return false ;
}
static inline bool F_1 ( struct V_1 * V_2 , const char * V_3 )
{
return false ;
}
static inline bool F_2 ( const struct V_1 * V_2 )
{
return false ;
}
static struct V_10 * F_3 ( struct V_11 * V_12 )
{
return F_4 ( V_12 , struct V_10 , V_12 ) ;
}
static void F_5 ( struct V_10 * V_13 )
{
F_6 ( V_14 , & V_13 -> V_15 ) ;
F_7 () ;
F_8 ( & V_13 -> V_16 ) ;
}
static T_1 F_9 ( struct V_17 * V_17 ,
struct V_18 * V_19 ,
char * V_20 )
{
return sprintf ( V_20 , L_1 , V_21 ) ;
}
static T_1 F_10 ( struct V_17 * V_17 ,
struct V_18 * V_19 ,
const char * V_20 , T_2 V_22 )
{
V_21 = F_11 ( V_20 , NULL , 10 ) ;
if ( V_21 < 0 )
V_21 = 0 ;
return V_22 ;
}
static void F_12 ( struct V_11 * V_12 )
{
struct V_10 * V_13 = F_3 ( V_12 ) ;
int V_23 ;
for ( V_23 = 0 ; V_23 < V_13 -> V_24 ; V_23 ++ )
F_13 ( V_13 -> V_25 [ V_23 ] ) ;
F_14 ( V_13 -> V_25 ) ;
F_14 ( V_13 ) ;
F_15 ( V_26 ) ;
}
static int F_16 ( struct V_11 * V_12 , struct V_27 * V_28 )
{
struct V_10 * V_13 = F_3 ( V_12 ) ;
if ( F_17 ( V_28 , L_2 , V_13 -> V_29 ) )
return - V_30 ;
if ( F_17 ( V_28 , L_3 , V_21 ) )
return - V_30 ;
if ( F_17 ( V_28 , L_4 , V_13 -> V_31 ) )
return - V_30 ;
return 0 ;
}
static T_1 F_18 ( struct V_11 * V_12 ,
struct V_32 * V_19 , char * V_20 )
{
struct V_10 * V_13 = F_3 ( V_12 ) ;
int V_33 = F_19 ( V_34 , & V_13 -> V_15 ) ;
return sprintf ( V_20 , L_1 , V_33 ) ;
}
static void F_20 ( const struct V_1 * V_2 )
{
int V_23 ;
F_21 ( V_2 -> V_9 ) ;
if ( V_2 -> V_25 ) {
for ( V_23 = 0 ; V_23 < F_22 ( V_2 -> V_8 ) ; V_23 ++ )
F_13 ( V_2 -> V_25 [ V_23 ] ) ;
F_14 ( V_2 -> V_25 ) ;
}
}
static T_1 F_23 ( struct V_11 * V_12 ,
struct V_32 * V_19 ,
const char * V_20 , T_2 V_22 )
{
struct V_10 * V_13 = F_3 ( V_12 ) ;
int V_33 = F_11 ( V_20 , NULL , 10 ) ;
int V_23 ;
F_24 ( & V_35 ) ;
if ( ! V_13 -> V_2 )
goto V_36;
switch ( V_33 ) {
case 1 :
F_20 ( V_13 -> V_2 ) ;
memset ( V_13 -> V_2 , 0 , sizeof( struct V_1 ) ) ;
for ( V_23 = 0 ; V_23 < V_13 -> V_24 ; V_23 ++ )
F_13 ( V_13 -> V_25 [ V_23 ] ) ;
F_14 ( V_13 -> V_25 ) ;
V_13 -> V_25 = NULL ;
V_13 -> V_37 = 0 ;
V_13 -> V_24 = 0 ;
F_6 ( V_34 , & V_13 -> V_15 ) ;
break;
case 0 :
if ( F_19 ( V_34 , & V_13 -> V_15 ) ) {
F_21 ( V_13 -> V_2 -> V_9 ) ;
V_13 -> V_2 -> V_9 = F_25 ( V_13 -> V_25 ,
V_13 -> V_24 ,
0 , V_38 ) ;
if ( ! V_13 -> V_2 -> V_9 ) {
F_26 ( V_12 , L_5 , V_39 ) ;
goto V_40;
}
V_13 -> V_2 -> V_25 = V_13 -> V_25 ;
V_13 -> V_25 = NULL ;
V_13 -> V_37 = 0 ;
V_13 -> V_24 = 0 ;
F_8 ( & V_13 -> V_16 ) ;
F_27 ( V_34 , & V_13 -> V_15 ) ;
break;
}
default:
F_26 ( V_12 , L_6 , V_39 , V_33 ) ;
case - 1 :
V_40:
F_5 ( V_13 ) ;
break;
}
V_36:
F_28 ( & V_35 ) ;
return V_22 ;
}
static T_1 F_29 ( struct V_41 * V_42 , struct V_43 * V_44 ,
struct V_45 * V_46 ,
char * V_47 , T_3 V_48 , T_2 V_22 )
{
struct V_11 * V_12 = F_30 ( V_44 ) ;
struct V_10 * V_13 = F_3 ( V_12 ) ;
struct V_1 * V_2 ;
T_1 V_49 ;
F_24 ( & V_35 ) ;
V_2 = V_13 -> V_2 ;
if ( ! V_2 || F_19 ( V_50 , & V_13 -> V_15 ) ) {
V_49 = - V_51 ;
goto V_36;
}
if ( V_48 > V_2 -> V_8 ) {
V_49 = 0 ;
goto V_36;
}
if ( V_22 > V_2 -> V_8 - V_48 )
V_22 = V_2 -> V_8 - V_48 ;
V_49 = V_22 ;
while ( V_22 ) {
void * V_52 ;
int V_53 = V_48 >> V_54 ;
int V_55 = V_48 & ( V_56 - 1 ) ;
int V_57 = F_31 ( T_2 , V_56 - V_55 , V_22 ) ;
V_52 = F_32 ( V_13 -> V_25 [ V_53 ] ) ;
memcpy ( V_47 , V_52 + V_55 , V_57 ) ;
F_33 ( V_13 -> V_25 [ V_53 ] ) ;
V_47 += V_57 ;
V_48 += V_57 ;
V_22 -= V_57 ;
}
V_36:
F_28 ( & V_35 ) ;
return V_49 ;
}
static int F_34 ( struct V_10 * V_13 , int V_58 )
{
int V_59 = F_35 ( V_58 , V_56 ) >> V_54 ;
if ( V_13 -> V_37 < V_59 ) {
int V_60 = F_36 ( V_59 ,
V_13 -> V_37 * 2 ) ;
struct V_61 * * V_62 ;
V_62 = F_37 ( V_60 * sizeof( void * ) ,
V_63 ) ;
if ( ! V_62 ) {
F_5 ( V_13 ) ;
return - V_30 ;
}
memcpy ( V_62 , V_13 -> V_25 ,
V_13 -> V_37 * sizeof( void * ) ) ;
memset ( & V_62 [ V_13 -> V_37 ] , 0 , sizeof( void * ) *
( V_60 - V_13 -> V_37 ) ) ;
F_14 ( V_13 -> V_25 ) ;
V_13 -> V_25 = V_62 ;
V_13 -> V_37 = V_60 ;
}
while ( V_13 -> V_24 < V_59 ) {
V_13 -> V_25 [ V_13 -> V_24 ] =
F_38 ( V_63 | V_64 ) ;
if ( ! V_13 -> V_25 [ V_13 -> V_24 ] ) {
F_5 ( V_13 ) ;
return - V_30 ;
}
V_13 -> V_24 ++ ;
}
return 0 ;
}
static T_1 F_39 ( struct V_41 * V_42 , struct V_43 * V_44 ,
struct V_45 * V_46 ,
char * V_47 , T_3 V_48 , T_2 V_22 )
{
struct V_11 * V_12 = F_30 ( V_44 ) ;
struct V_10 * V_13 = F_3 ( V_12 ) ;
struct V_1 * V_2 ;
T_1 V_65 ;
if ( ! F_40 ( V_66 ) )
return - V_67 ;
F_24 ( & V_35 ) ;
V_2 = V_13 -> V_2 ;
if ( ! V_2 || F_19 ( V_50 , & V_13 -> V_15 ) ) {
V_65 = - V_51 ;
goto V_36;
}
V_65 = F_34 ( V_13 , V_48 + V_22 ) ;
if ( V_65 )
goto V_36;
V_65 = V_22 ;
while ( V_22 ) {
void * V_52 ;
int V_53 = V_48 >> V_54 ;
int V_55 = V_48 & ( V_56 - 1 ) ;
int V_57 = F_31 ( T_2 , V_56 - V_55 , V_22 ) ;
V_52 = F_32 ( V_13 -> V_25 [ V_53 ] ) ;
memcpy ( V_52 + V_55 , V_47 , V_57 ) ;
F_33 ( V_13 -> V_25 [ V_53 ] ) ;
V_47 += V_57 ;
V_48 += V_57 ;
V_22 -= V_57 ;
}
V_2 -> V_8 = F_41 ( T_2 , V_48 , V_2 -> V_8 ) ;
V_36:
F_28 ( & V_35 ) ;
return V_65 ;
}
static void F_42 ( T_4 V_9 )
{
struct V_10 * V_13 = (struct V_10 * ) V_9 ;
F_5 ( V_13 ) ;
}
static struct V_10 *
F_43 ( struct V_1 * V_1 , const char * V_68 ,
struct V_11 * V_11 , bool V_69 , bool V_31 )
{
struct V_10 * V_13 ;
struct V_11 * V_70 ;
int error ;
V_13 = F_44 ( sizeof( * V_13 ) + strlen ( V_68 ) + 1 , V_63 ) ;
if ( ! V_13 ) {
F_26 ( V_11 , L_7 , V_39 ) ;
error = - V_30 ;
goto V_71;
}
V_13 -> V_2 = V_1 ;
V_13 -> V_31 = V_31 ;
strcpy ( V_13 -> V_29 , V_68 ) ;
F_45 ( & V_13 -> V_16 ) ;
F_46 ( & V_13 -> V_72 ,
F_42 , ( T_4 ) V_13 ) ;
V_70 = & V_13 -> V_12 ;
F_47 ( V_70 ) ;
F_48 ( V_70 , L_8 , F_49 ( V_11 ) ) ;
V_70 -> V_73 = V_11 ;
V_70 -> V_17 = & V_74 ;
F_50 ( V_70 , true ) ;
F_51 ( V_26 ) ;
error = F_52 ( V_70 ) ;
if ( error ) {
F_26 ( V_11 , L_9 , V_39 ) ;
goto V_75;
}
error = F_53 ( V_70 , & V_76 ) ;
if ( error ) {
F_26 ( V_11 , L_10 , V_39 ) ;
goto V_77;
}
error = F_54 ( V_70 , & V_78 ) ;
if ( error ) {
F_26 ( V_11 , L_11 , V_39 ) ;
goto V_79;
}
if ( V_69 )
F_50 ( V_70 , false ) ;
return V_13 ;
V_79:
F_55 ( V_70 , & V_76 ) ;
V_77:
F_56 ( V_70 ) ;
V_75:
F_57 ( V_70 ) ;
V_71:
return F_58 ( error ) ;
}
static void F_59 ( struct V_10 * V_13 )
{
struct V_11 * V_70 = & V_13 -> V_12 ;
F_60 ( V_70 , & V_78 ) ;
F_55 ( V_70 , & V_76 ) ;
F_61 ( V_70 ) ;
}
static int F_62 ( const struct V_1 * * V_80 ,
const char * V_3 , struct V_11 * V_11 ,
bool V_69 , bool V_31 )
{
struct V_10 * V_13 ;
struct V_1 * V_1 ;
int V_65 = 0 ;
if ( ! V_80 )
return - V_81 ;
* V_80 = V_1 = F_44 ( sizeof( * V_1 ) , V_63 ) ;
if ( ! V_1 ) {
F_26 ( V_11 , L_12 ,
V_39 ) ;
return - V_30 ;
}
if ( F_1 ( V_1 , V_3 ) ) {
F_63 ( V_11 , L_13 , V_3 ) ;
return 0 ;
}
F_64 () ;
if ( F_65 ( F_66 () ) ) {
F_26 ( V_11 , L_14 , V_3 ) ;
V_65 = - V_82 ;
goto V_36;
}
if ( V_69 )
F_63 ( V_11 , L_15 , V_3 ) ;
V_13 = F_43 ( V_1 , V_3 , V_11 , V_69 , V_31 ) ;
if ( F_67 ( V_13 ) ) {
V_65 = F_68 ( V_13 ) ;
goto V_36;
}
if ( V_69 ) {
if ( V_21 > 0 )
F_69 ( & V_13 -> V_72 ,
F_70 ( V_83 +
V_21 * V_84 ) ) ;
F_71 ( & V_13 -> V_12 . V_44 , V_85 ) ;
}
F_72 ( & V_13 -> V_16 ) ;
F_6 ( V_50 , & V_13 -> V_15 ) ;
F_73 ( & V_13 -> V_72 ) ;
F_24 ( & V_35 ) ;
if ( ! V_13 -> V_2 -> V_8 || F_19 ( V_14 , & V_13 -> V_15 ) )
V_65 = - V_86 ;
V_13 -> V_2 = NULL ;
F_28 ( & V_35 ) ;
F_59 ( V_13 ) ;
V_36:
F_74 () ;
if ( V_65 ) {
F_75 ( V_1 ) ;
* V_80 = NULL ;
}
return V_65 ;
}
int
F_76 ( const struct V_1 * * V_80 , const char * V_3 ,
struct V_11 * V_11 )
{
return F_62 ( V_80 , V_3 , V_11 , true , false ) ;
}
void F_75 ( const struct V_1 * V_2 )
{
if ( V_2 ) {
if ( ! F_2 ( V_2 ) )
F_20 ( V_2 ) ;
F_14 ( V_2 ) ;
}
}
static int F_77 ( void * V_87 )
{
struct V_88 * V_89 = V_87 ;
const struct V_1 * V_2 ;
int V_90 ;
if ( ! V_87 ) {
F_65 ( 1 ) ;
return 0 ;
}
V_90 = F_62 ( & V_2 , V_89 -> V_3 , V_89 -> V_11 ,
V_89 -> V_69 , true ) ;
V_89 -> V_91 ( V_2 , V_89 -> V_92 ) ;
F_15 ( V_89 -> V_93 ) ;
F_14 ( V_89 ) ;
return V_90 ;
}
int
F_78 (
struct V_93 * V_93 , bool V_69 ,
const char * V_3 , struct V_11 * V_11 , T_5 V_94 , void * V_92 ,
void (* V_91)( const struct V_1 * V_2 , void * V_92 ) )
{
struct V_95 * V_96 ;
struct V_88 * V_89 ;
V_89 = F_44 ( sizeof ( struct V_88 ) , V_94 ) ;
if ( ! V_89 )
return - V_30 ;
V_89 -> V_93 = V_93 ;
V_89 -> V_3 = V_3 ;
V_89 -> V_11 = V_11 ;
V_89 -> V_92 = V_92 ;
V_89 -> V_91 = V_91 ;
V_89 -> V_69 = V_69 ;
if ( ! F_79 ( V_93 ) ) {
F_14 ( V_89 ) ;
return - V_97 ;
}
V_96 = F_80 ( F_77 , V_89 ,
L_16 , V_3 ) ;
if ( F_67 ( V_96 ) ) {
V_89 -> V_91 ( NULL , V_89 -> V_92 ) ;
F_15 ( V_89 -> V_93 ) ;
F_14 ( V_89 ) ;
return F_68 ( V_96 ) ;
}
return 0 ;
}
static int T_6 F_81 ( void )
{
return F_82 ( & V_74 ) ;
}
static void T_7 F_83 ( void )
{
F_84 ( & V_74 ) ;
}
