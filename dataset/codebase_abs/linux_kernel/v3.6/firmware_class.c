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
static inline long F_3 ( void )
{
return V_10 > 0 ? V_10 * V_11 : V_12 ;
}
static struct V_13 * F_4 ( struct V_14 * V_15 )
{
return F_5 ( V_15 , struct V_13 , V_15 ) ;
}
static void F_6 ( struct V_13 * V_16 )
{
F_7 ( V_17 , & V_16 -> V_18 ) ;
F_8 () ;
F_9 ( & V_16 -> V_19 ) ;
}
static T_1 F_10 ( struct V_20 * V_20 ,
struct V_21 * V_22 ,
char * V_23 )
{
return sprintf ( V_23 , L_1 , V_10 ) ;
}
static T_1 F_11 ( struct V_20 * V_20 ,
struct V_21 * V_22 ,
const char * V_23 , T_2 V_24 )
{
V_10 = F_12 ( V_23 , NULL , 10 ) ;
if ( V_10 < 0 )
V_10 = 0 ;
return V_24 ;
}
static void F_13 ( struct V_14 * V_15 )
{
struct V_13 * V_16 = F_4 ( V_15 ) ;
int V_25 ;
for ( V_25 = 0 ; V_25 < V_16 -> V_26 ; V_25 ++ )
F_14 ( V_16 -> V_27 [ V_25 ] ) ;
F_15 ( V_16 -> V_27 ) ;
F_15 ( V_16 ) ;
F_16 ( V_28 ) ;
}
static int F_17 ( struct V_14 * V_15 , struct V_29 * V_30 )
{
struct V_13 * V_16 = F_4 ( V_15 ) ;
if ( F_18 ( V_30 , L_2 , V_16 -> V_31 ) )
return - V_32 ;
if ( F_18 ( V_30 , L_3 , V_10 ) )
return - V_32 ;
if ( F_18 ( V_30 , L_4 , V_16 -> V_33 ) )
return - V_32 ;
return 0 ;
}
static T_1 F_19 ( struct V_14 * V_15 ,
struct V_34 * V_22 , char * V_23 )
{
struct V_13 * V_16 = F_4 ( V_15 ) ;
int V_35 = F_20 ( V_36 , & V_16 -> V_18 ) ;
return sprintf ( V_23 , L_1 , V_35 ) ;
}
static void F_21 ( const struct V_1 * V_2 )
{
int V_25 ;
F_22 ( V_2 -> V_9 ) ;
if ( V_2 -> V_27 ) {
for ( V_25 = 0 ; V_25 < F_23 ( V_2 -> V_8 ) ; V_25 ++ )
F_14 ( V_2 -> V_27 [ V_25 ] ) ;
F_15 ( V_2 -> V_27 ) ;
}
}
static T_1 F_24 ( struct V_14 * V_15 ,
struct V_34 * V_22 ,
const char * V_23 , T_2 V_24 )
{
struct V_13 * V_16 = F_4 ( V_15 ) ;
int V_35 = F_12 ( V_23 , NULL , 10 ) ;
int V_25 ;
F_25 ( & V_37 ) ;
if ( ! V_16 -> V_2 )
goto V_38;
switch ( V_35 ) {
case 1 :
F_21 ( V_16 -> V_2 ) ;
memset ( V_16 -> V_2 , 0 , sizeof( struct V_1 ) ) ;
for ( V_25 = 0 ; V_25 < V_16 -> V_26 ; V_25 ++ )
F_14 ( V_16 -> V_27 [ V_25 ] ) ;
F_15 ( V_16 -> V_27 ) ;
V_16 -> V_27 = NULL ;
V_16 -> V_39 = 0 ;
V_16 -> V_26 = 0 ;
F_7 ( V_36 , & V_16 -> V_18 ) ;
break;
case 0 :
if ( F_20 ( V_36 , & V_16 -> V_18 ) ) {
F_22 ( V_16 -> V_2 -> V_9 ) ;
V_16 -> V_2 -> V_9 = F_26 ( V_16 -> V_27 ,
V_16 -> V_26 ,
0 , V_40 ) ;
if ( ! V_16 -> V_2 -> V_9 ) {
F_27 ( V_15 , L_5 , V_41 ) ;
goto V_42;
}
V_16 -> V_2 -> V_27 = V_16 -> V_27 ;
V_16 -> V_27 = NULL ;
V_16 -> V_39 = 0 ;
V_16 -> V_26 = 0 ;
F_9 ( & V_16 -> V_19 ) ;
F_28 ( V_36 , & V_16 -> V_18 ) ;
break;
}
default:
F_27 ( V_15 , L_6 , V_41 , V_35 ) ;
case - 1 :
V_42:
F_6 ( V_16 ) ;
break;
}
V_38:
F_29 ( & V_37 ) ;
return V_24 ;
}
static T_1 F_30 ( struct V_43 * V_44 , struct V_45 * V_46 ,
struct V_47 * V_48 ,
char * V_49 , T_3 V_50 , T_2 V_24 )
{
struct V_14 * V_15 = F_31 ( V_46 ) ;
struct V_13 * V_16 = F_4 ( V_15 ) ;
struct V_1 * V_2 ;
T_1 V_51 ;
F_25 ( & V_37 ) ;
V_2 = V_16 -> V_2 ;
if ( ! V_2 || F_20 ( V_52 , & V_16 -> V_18 ) ) {
V_51 = - V_53 ;
goto V_38;
}
if ( V_50 > V_2 -> V_8 ) {
V_51 = 0 ;
goto V_38;
}
if ( V_24 > V_2 -> V_8 - V_50 )
V_24 = V_2 -> V_8 - V_50 ;
V_51 = V_24 ;
while ( V_24 ) {
void * V_54 ;
int V_55 = V_50 >> V_56 ;
int V_57 = V_50 & ( V_58 - 1 ) ;
int V_59 = F_32 ( T_2 , V_58 - V_57 , V_24 ) ;
V_54 = F_33 ( V_16 -> V_27 [ V_55 ] ) ;
memcpy ( V_49 , V_54 + V_57 , V_59 ) ;
F_34 ( V_16 -> V_27 [ V_55 ] ) ;
V_49 += V_59 ;
V_50 += V_59 ;
V_24 -= V_59 ;
}
V_38:
F_29 ( & V_37 ) ;
return V_51 ;
}
static int F_35 ( struct V_13 * V_16 , int V_60 )
{
int V_61 = F_36 ( V_60 , V_58 ) >> V_56 ;
if ( V_16 -> V_39 < V_61 ) {
int V_62 = F_37 ( V_61 ,
V_16 -> V_39 * 2 ) ;
struct V_63 * * V_64 ;
V_64 = F_38 ( V_62 * sizeof( void * ) ,
V_65 ) ;
if ( ! V_64 ) {
F_6 ( V_16 ) ;
return - V_32 ;
}
memcpy ( V_64 , V_16 -> V_27 ,
V_16 -> V_39 * sizeof( void * ) ) ;
memset ( & V_64 [ V_16 -> V_39 ] , 0 , sizeof( void * ) *
( V_62 - V_16 -> V_39 ) ) ;
F_15 ( V_16 -> V_27 ) ;
V_16 -> V_27 = V_64 ;
V_16 -> V_39 = V_62 ;
}
while ( V_16 -> V_26 < V_61 ) {
V_16 -> V_27 [ V_16 -> V_26 ] =
F_39 ( V_65 | V_66 ) ;
if ( ! V_16 -> V_27 [ V_16 -> V_26 ] ) {
F_6 ( V_16 ) ;
return - V_32 ;
}
V_16 -> V_26 ++ ;
}
return 0 ;
}
static T_1 F_40 ( struct V_43 * V_44 , struct V_45 * V_46 ,
struct V_47 * V_48 ,
char * V_49 , T_3 V_50 , T_2 V_24 )
{
struct V_14 * V_15 = F_31 ( V_46 ) ;
struct V_13 * V_16 = F_4 ( V_15 ) ;
struct V_1 * V_2 ;
T_1 V_67 ;
if ( ! F_41 ( V_68 ) )
return - V_69 ;
F_25 ( & V_37 ) ;
V_2 = V_16 -> V_2 ;
if ( ! V_2 || F_20 ( V_52 , & V_16 -> V_18 ) ) {
V_67 = - V_53 ;
goto V_38;
}
V_67 = F_35 ( V_16 , V_50 + V_24 ) ;
if ( V_67 )
goto V_38;
V_67 = V_24 ;
while ( V_24 ) {
void * V_54 ;
int V_55 = V_50 >> V_56 ;
int V_57 = V_50 & ( V_58 - 1 ) ;
int V_59 = F_32 ( T_2 , V_58 - V_57 , V_24 ) ;
V_54 = F_33 ( V_16 -> V_27 [ V_55 ] ) ;
memcpy ( V_54 + V_57 , V_49 , V_59 ) ;
F_34 ( V_16 -> V_27 [ V_55 ] ) ;
V_49 += V_59 ;
V_50 += V_59 ;
V_24 -= V_59 ;
}
V_2 -> V_8 = F_42 ( T_2 , V_50 , V_2 -> V_8 ) ;
V_38:
F_29 ( & V_37 ) ;
return V_67 ;
}
static void F_43 ( T_4 V_9 )
{
struct V_13 * V_16 = (struct V_13 * ) V_9 ;
F_6 ( V_16 ) ;
}
static struct V_13 *
F_44 ( struct V_1 * V_1 , const char * V_70 ,
struct V_14 * V_14 , bool V_71 , bool V_33 )
{
struct V_13 * V_16 ;
struct V_14 * V_72 ;
V_16 = F_45 ( sizeof( * V_16 ) + strlen ( V_70 ) + 1 , V_65 ) ;
if ( ! V_16 ) {
F_27 ( V_14 , L_7 , V_41 ) ;
return F_46 ( - V_32 ) ;
}
V_16 -> V_2 = V_1 ;
V_16 -> V_33 = V_33 ;
strcpy ( V_16 -> V_31 , V_70 ) ;
F_47 ( & V_16 -> V_19 ) ;
F_48 ( & V_16 -> V_73 ,
F_43 , ( T_4 ) V_16 ) ;
V_72 = & V_16 -> V_15 ;
F_49 ( V_72 ) ;
F_50 ( V_72 , L_8 , F_51 ( V_14 ) ) ;
V_72 -> V_74 = V_14 ;
V_72 -> V_20 = & V_75 ;
return V_16 ;
}
static struct V_13 *
F_52 ( const struct V_1 * * V_76 , const char * V_3 ,
struct V_14 * V_14 , bool V_71 , bool V_33 )
{
struct V_1 * V_1 ;
struct V_13 * V_16 ;
if ( ! V_76 )
return F_46 ( - V_77 ) ;
* V_76 = V_1 = F_45 ( sizeof( * V_1 ) , V_65 ) ;
if ( ! V_1 ) {
F_27 ( V_14 , L_9 ,
V_41 ) ;
return F_46 ( - V_32 ) ;
}
if ( F_1 ( V_1 , V_3 ) ) {
F_53 ( V_14 , L_10 , V_3 ) ;
return NULL ;
}
V_16 = F_44 ( V_1 , V_3 , V_14 , V_71 , V_33 ) ;
if ( F_54 ( V_16 ) ) {
F_55 ( V_1 ) ;
* V_76 = NULL ;
}
return V_16 ;
}
static void F_56 ( const struct V_1 * * V_76 )
{
F_55 ( * V_76 ) ;
* V_76 = NULL ;
}
static int F_57 ( struct V_13 * V_16 , bool V_71 ,
long V_73 )
{
int V_67 = 0 ;
struct V_14 * V_72 = & V_16 -> V_15 ;
F_58 ( V_72 , true ) ;
F_59 ( V_28 ) ;
V_67 = F_60 ( V_72 ) ;
if ( V_67 ) {
F_27 ( V_72 , L_11 , V_41 ) ;
goto V_78;
}
V_67 = F_61 ( V_72 , & V_79 ) ;
if ( V_67 ) {
F_27 ( V_72 , L_12 , V_41 ) ;
goto V_80;
}
V_67 = F_62 ( V_72 , & V_81 ) ;
if ( V_67 ) {
F_27 ( V_72 , L_13 , V_41 ) ;
goto V_82;
}
if ( V_71 ) {
F_58 ( V_72 , false ) ;
F_53 ( V_72 , L_14 , V_16 -> V_31 ) ;
if ( V_73 != V_12 )
F_63 ( & V_16 -> V_73 ,
F_64 ( V_83 + V_73 ) ) ;
F_65 ( & V_16 -> V_15 . V_46 , V_84 ) ;
}
F_66 ( & V_16 -> V_19 ) ;
F_7 ( V_52 , & V_16 -> V_18 ) ;
F_67 ( & V_16 -> V_73 ) ;
F_25 ( & V_37 ) ;
if ( ! V_16 -> V_2 -> V_8 || F_20 ( V_17 , & V_16 -> V_18 ) )
V_67 = - V_85 ;
V_16 -> V_2 = NULL ;
F_29 ( & V_37 ) ;
F_68 ( V_72 , & V_81 ) ;
V_82:
F_69 ( V_72 , & V_79 ) ;
V_80:
F_70 ( V_72 ) ;
V_78:
F_71 ( V_72 ) ;
return V_67 ;
}
int
F_72 ( const struct V_1 * * V_76 , const char * V_3 ,
struct V_14 * V_14 )
{
struct V_13 * V_16 ;
int V_86 ;
V_16 = F_52 ( V_76 , V_3 , V_14 , true ,
false ) ;
if ( F_73 ( V_16 ) )
return F_74 ( V_16 ) ;
V_86 = F_75 () ;
if ( F_76 ( V_86 ) ) {
F_27 ( V_14 , L_15 , V_3 ) ;
} else {
V_86 = F_57 ( V_16 , true ,
F_3 () ) ;
F_77 () ;
}
if ( V_86 )
F_56 ( V_76 ) ;
return V_86 ;
}
void F_55 ( const struct V_1 * V_2 )
{
if ( V_2 ) {
if ( ! F_2 ( V_2 ) )
F_21 ( V_2 ) ;
F_15 ( V_2 ) ;
}
}
static void F_78 ( struct V_87 * V_88 )
{
struct V_89 * V_90 ;
const struct V_1 * V_2 ;
struct V_13 * V_16 ;
long V_73 ;
int V_86 ;
V_90 = F_5 ( V_88 , struct V_89 , V_88 ) ;
V_16 = F_52 ( & V_2 , V_90 -> V_3 , V_90 -> V_14 ,
V_90 -> V_71 , true ) ;
if ( F_73 ( V_16 ) ) {
V_86 = F_74 ( V_16 ) ;
goto V_38;
}
V_73 = F_79 ( F_3 () ) ;
if ( V_73 ) {
V_86 = F_57 ( V_16 , V_90 -> V_71 , V_73 ) ;
F_77 () ;
} else {
F_53 ( V_90 -> V_14 , L_16 ,
V_90 -> V_3 ) ;
V_86 = - V_91 ;
}
if ( V_86 )
F_56 ( & V_2 ) ;
V_38:
V_90 -> V_92 ( V_2 , V_90 -> V_93 ) ;
F_16 ( V_90 -> V_94 ) ;
F_15 ( V_90 ) ;
}
int
F_80 (
struct V_94 * V_94 , bool V_71 ,
const char * V_3 , struct V_14 * V_14 , T_5 V_95 , void * V_93 ,
void (* V_92)( const struct V_1 * V_2 , void * V_93 ) )
{
struct V_89 * V_90 ;
V_90 = F_45 ( sizeof ( struct V_89 ) , V_95 ) ;
if ( ! V_90 )
return - V_32 ;
V_90 -> V_94 = V_94 ;
V_90 -> V_3 = V_3 ;
V_90 -> V_14 = V_14 ;
V_90 -> V_93 = V_93 ;
V_90 -> V_92 = V_92 ;
V_90 -> V_71 = V_71 ;
if ( ! F_81 ( V_94 ) ) {
F_15 ( V_90 ) ;
return - V_96 ;
}
F_82 ( & V_90 -> V_88 , F_78 ) ;
F_83 ( & V_90 -> V_88 ) ;
return 0 ;
}
static int T_6 F_84 ( void )
{
return F_85 ( & V_75 ) ;
}
static void T_7 F_86 ( void )
{
F_87 ( & V_75 ) ;
}
