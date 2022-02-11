static struct V_1 * F_1 ( int V_2 )
{
struct V_1 * V_3 , * V_4 , * V_5 = NULL ;
if ( F_2 ( & V_6 ) )
return NULL ;
F_3 (entry, n, &xenconsoles, list) {
if ( V_3 -> V_2 == V_2 ) {
V_5 = V_3 ;
break;
}
}
return V_5 ;
}
static inline int F_4 ( int V_7 )
{
return V_7 + V_8 ;
}
static inline void F_5 ( struct V_1 * V_9 )
{
F_6 ( V_9 -> V_10 ) ;
}
static int F_7 ( struct V_1 * V_11 ,
const char * V_12 , int V_13 )
{
T_1 V_9 , V_14 ;
struct V_15 * V_16 = V_11 -> V_16 ;
int V_17 = 0 ;
V_9 = V_16 -> V_18 ;
V_14 = V_16 -> V_19 ;
F_8 () ;
F_9 ( ( V_14 - V_9 ) > sizeof( V_16 -> V_20 ) ) ;
while ( ( V_17 < V_13 ) && ( ( V_14 - V_9 ) < sizeof( V_16 -> V_20 ) ) )
V_16 -> V_20 [ F_10 ( V_14 ++ , V_16 -> V_20 ) ] = V_12 [ V_17 ++ ] ;
F_11 () ;
V_16 -> V_19 = V_14 ;
if ( V_17 )
F_5 ( V_11 ) ;
return V_17 ;
}
static int F_12 ( T_2 V_2 , const char * V_12 , int V_13 )
{
int V_5 = V_13 ;
struct V_1 * V_9 = F_1 ( V_2 ) ;
if ( V_9 == NULL )
return - V_21 ;
while ( V_13 ) {
int V_17 = F_7 ( V_9 , V_12 , V_13 ) ;
V_12 += V_17 ;
V_13 -= V_17 ;
if ( F_13 ( V_13 ) )
F_14 ( V_22 , NULL ) ;
}
return V_5 ;
}
static int F_15 ( T_2 V_2 , char * V_23 , int V_13 )
{
struct V_15 * V_16 ;
T_1 V_9 , V_14 ;
int V_24 = 0 ;
struct V_1 * V_11 = F_1 ( V_2 ) ;
if ( V_11 == NULL )
return - V_21 ;
V_16 = V_11 -> V_16 ;
V_9 = V_16 -> V_25 ;
V_14 = V_16 -> V_26 ;
F_8 () ;
F_9 ( ( V_14 - V_9 ) > sizeof( V_16 -> V_27 ) ) ;
while ( V_9 != V_14 && V_24 < V_13 )
V_23 [ V_24 ++ ] = V_16 -> V_27 [ F_10 ( V_9 ++ , V_16 -> V_27 ) ] ;
F_8 () ;
V_16 -> V_25 = V_9 ;
F_5 ( V_11 ) ;
return V_24 ;
}
static int F_16 ( T_2 V_2 , char * V_23 , int V_13 )
{
return F_17 ( V_28 , V_13 , V_23 ) ;
}
static int F_18 ( T_2 V_2 , const char * V_29 , int V_13 )
{
int V_30 = F_17 ( V_31 , V_13 , ( char * ) V_29 ) ;
if ( V_30 < 0 )
return V_30 ;
return V_13 ;
}
static int F_19 ( void )
{
int V_32 ;
T_3 V_33 = 0 ;
unsigned long V_34 ;
struct V_1 * V_35 ;
if ( ! F_20 () )
return - V_36 ;
V_35 = F_1 ( V_8 ) ;
if ( ! V_35 ) {
V_35 = F_21 ( sizeof( struct V_1 ) , V_37 ) ;
if ( ! V_35 )
return - V_38 ;
} else if ( V_35 -> V_16 != NULL ) {
return 0 ;
}
V_32 = F_22 ( V_39 , & V_33 ) ;
if ( V_32 < 0 || V_33 == 0 )
goto V_40;
V_35 -> V_10 = V_33 ;
V_33 = 0 ;
V_32 = F_22 ( V_41 , & V_33 ) ;
if ( V_32 < 0 || V_33 == 0 )
goto V_40;
V_34 = V_33 ;
V_35 -> V_16 = F_23 ( V_34 << V_42 , V_43 ) ;
if ( V_35 -> V_16 == NULL )
goto V_40;
V_35 -> V_2 = V_8 ;
F_24 ( & V_44 ) ;
F_25 ( & V_35 -> V_45 , & V_6 ) ;
F_26 ( & V_44 ) ;
return 0 ;
V_40:
F_27 ( V_35 ) ;
return - V_36 ;
}
static int F_28 ( struct V_1 * V_35 , int V_2 )
{
V_35 -> V_10 = V_46 -> V_47 . V_48 . V_10 ;
V_35 -> V_16 = F_29 ( V_46 -> V_47 . V_48 . V_49 ) ;
V_35 -> V_2 = V_2 ;
F_25 ( & V_35 -> V_45 , & V_6 ) ;
return 0 ;
}
static int F_30 ( void )
{
struct V_1 * V_35 ;
if ( ! F_31 () )
return - V_36 ;
if ( ! V_46 -> V_47 . V_48 . V_10 )
return - V_36 ;
V_35 = F_1 ( V_8 ) ;
if ( ! V_35 ) {
V_35 = F_21 ( sizeof( struct V_1 ) , V_37 ) ;
if ( ! V_35 )
return - V_38 ;
} else if ( V_35 -> V_16 != NULL ) {
return 0 ;
}
F_24 ( & V_44 ) ;
F_28 ( V_35 , V_8 ) ;
F_26 ( & V_44 ) ;
return 0 ;
}
static int F_32 ( void )
{
struct V_1 * V_35 ;
if ( ! F_33 () )
return - V_36 ;
V_35 = F_1 ( V_8 ) ;
if ( ! V_35 ) {
V_35 = F_21 ( sizeof( struct V_1 ) , V_37 ) ;
if ( ! V_35 )
return - V_38 ;
}
V_35 -> V_50 = F_34 ( V_51 , 0 , false ) ;
V_35 -> V_2 = V_8 ;
F_24 ( & V_44 ) ;
F_25 ( & V_35 -> V_45 , & V_6 ) ;
F_26 ( & V_44 ) ;
return 0 ;
}
static void F_35 ( struct V_1 * V_35 )
{
if ( F_20 () ) {
T_3 V_33 = 0 ;
int V_40 ;
V_40 = F_22 ( V_39 , & V_33 ) ;
if ( ! V_40 && V_33 )
V_35 -> V_10 = V_33 ;
} else
V_35 -> V_10 = V_46 -> V_47 . V_48 . V_10 ;
}
void F_36 ( void )
{
struct V_1 * V_35 = F_1 ( V_8 ) ;
if ( V_35 != NULL && V_35 -> V_50 ) {
if ( ! F_33 () )
F_35 ( V_35 ) ;
F_37 ( V_35 -> V_10 , V_35 -> V_50 ) ;
}
}
static void F_38 ( struct V_1 * V_35 )
{
if ( V_35 -> V_50 > 0 )
F_39 ( V_35 -> V_50 , NULL ) ;
V_35 -> V_50 = 0 ;
if ( V_35 -> V_10 > 0 )
F_40 ( V_35 -> V_52 , V_35 -> V_10 ) ;
V_35 -> V_10 = 0 ;
if ( V_35 -> V_53 > 0 )
F_41 ( V_35 -> V_53 ) ;
V_35 -> V_53 = 0 ;
if ( V_35 -> V_54 != NULL )
F_42 ( V_35 -> V_54 ) ;
V_35 -> V_54 = NULL ;
}
static void F_43 ( struct V_1 * V_35 )
{
F_44 ( ( unsigned long ) V_35 -> V_16 ) ;
V_35 -> V_16 = NULL ;
V_35 -> V_2 = 0 ;
F_27 ( V_35 ) ;
}
static int F_45 ( struct V_1 * V_35 )
{
F_38 ( V_35 ) ;
F_24 ( & V_44 ) ;
F_46 ( & V_35 -> V_45 ) ;
F_26 ( & V_44 ) ;
if ( V_35 -> V_52 != NULL )
F_43 ( V_35 ) ;
else {
if ( F_20 () )
F_47 ( V_35 -> V_16 ) ;
F_27 ( V_35 ) ;
}
return 0 ;
}
static int F_48 ( struct V_55 * V_56 )
{
return F_45 ( F_49 ( & V_56 -> V_56 ) ) ;
}
static int F_50 ( struct V_55 * V_56 ,
struct V_1 * V_35 )
{
int V_5 , V_10 , V_7 , V_57 , V_50 ;
struct V_58 V_59 ;
T_4 V_60 ;
V_5 = F_51 ( V_56 , & V_10 ) ;
if ( V_5 )
return V_5 ;
V_35 -> V_10 = V_10 ;
V_50 = F_52 ( V_10 ) ;
if ( V_50 < 0 )
return V_50 ;
V_35 -> V_50 = V_50 ;
V_7 = V_56 -> V_61 [ strlen ( V_56 -> V_61 ) - 1 ] - '0' ;
V_35 -> V_54 = F_53 ( F_4 ( V_7 ) ,
V_50 , & V_62 , 256 ) ;
if ( F_54 ( V_35 -> V_54 ) )
return F_55 ( V_35 -> V_54 ) ;
V_5 = F_56 ( 1 , & V_60 ) ;
if ( V_5 < 0 )
return V_5 ;
V_35 -> V_53 = V_60 ;
V_57 = F_57 ( & V_60 ) ;
if ( V_57 < 0 )
return V_57 ;
F_58 ( V_57 , V_35 -> V_52 -> V_63 ,
F_59 ( V_35 -> V_16 ) , 0 ) ;
V_64:
V_5 = F_60 ( & V_59 ) ;
if ( V_5 ) {
F_61 ( V_56 , V_5 , L_1 ) ;
return V_5 ;
}
V_5 = F_62 ( V_59 , V_56 -> V_61 , L_2 , L_3 , V_57 ) ;
if ( V_5 )
goto V_65;
V_5 = F_62 ( V_59 , V_56 -> V_61 , L_4 , L_5 ,
V_10 ) ;
if ( V_5 )
goto V_65;
V_5 = F_63 ( V_59 , 0 ) ;
if ( V_5 ) {
if ( V_5 == - V_66 )
goto V_64;
F_61 ( V_56 , V_5 , L_6 ) ;
return V_5 ;
}
F_64 ( V_56 , V_67 ) ;
return 0 ;
V_65:
F_63 ( V_59 , 1 ) ;
F_61 ( V_56 , V_5 , L_7 ) ;
return V_5 ;
}
static int F_65 ( struct V_55 * V_56 ,
const struct V_68 * V_69 )
{
int V_5 , V_7 ;
struct V_1 * V_35 ;
V_7 = V_56 -> V_61 [ strlen ( V_56 -> V_61 ) - 1 ] - '0' ;
if ( V_7 == 0 )
return - V_36 ;
V_35 = F_21 ( sizeof( struct V_1 ) , V_37 ) ;
if ( ! V_35 )
return - V_38 ;
F_66 ( & V_56 -> V_56 , V_35 ) ;
V_35 -> V_52 = V_56 ;
V_35 -> V_2 = F_4 ( V_7 ) ;
V_35 -> V_16 = ( void * ) F_67 ( V_37 | V_70 ) ;
if ( ! V_35 -> V_16 )
goto V_71;
V_5 = F_50 ( V_56 , V_35 ) ;
if ( V_5 < 0 )
goto error;
F_24 ( & V_44 ) ;
F_25 ( & V_35 -> V_45 , & V_6 ) ;
F_26 ( & V_44 ) ;
return 0 ;
V_71:
V_5 = - V_38 ;
F_61 ( V_56 , V_5 , L_8 ) ;
error:
F_38 ( V_35 ) ;
F_43 ( V_35 ) ;
return V_5 ;
}
static int F_68 ( struct V_55 * V_56 )
{
struct V_1 * V_35 = F_49 ( & V_56 -> V_56 ) ;
F_38 ( V_35 ) ;
memset ( V_35 -> V_16 , 0 , V_43 ) ;
return F_50 ( V_56 , V_35 ) ;
}
static void F_69 ( struct V_55 * V_56 ,
enum V_72 V_73 )
{
switch ( V_73 ) {
case V_74 :
case V_75 :
case V_76 :
case V_67 :
case V_77 :
break;
case V_78 :
break;
case V_79 :
F_64 ( V_56 , V_79 ) ;
break;
case V_80 :
if ( V_56 -> V_81 == V_80 )
break;
case V_82 :
F_70 ( V_56 ) ;
break;
}
}
static int T_5 F_71 ( void )
{
int V_32 ;
struct V_1 * V_35 ;
const struct V_83 * V_84 ;
if ( ! F_72 () )
return - V_36 ;
if ( F_33 () ) {
V_84 = & V_85 ;
V_32 = F_32 () ;
if ( V_32 < 0 )
return V_32 ;
V_35 = F_1 ( V_8 ) ;
} else {
V_84 = & V_62 ;
if ( F_20 () )
V_32 = F_19 () ;
else
V_32 = F_30 () ;
if ( V_32 < 0 )
return V_32 ;
V_35 = F_1 ( V_8 ) ;
V_35 -> V_50 = F_52 ( V_35 -> V_10 ) ;
}
if ( V_35 -> V_50 < 0 )
V_35 -> V_50 = 0 ;
else
F_73 ( V_35 -> V_50 ) ;
V_35 -> V_54 = F_53 ( V_8 , V_35 -> V_50 , V_84 , 256 ) ;
if ( F_54 ( V_35 -> V_54 ) ) {
V_32 = F_55 ( V_35 -> V_54 ) ;
F_24 ( & V_44 ) ;
F_46 ( & V_35 -> V_45 ) ;
F_26 ( & V_44 ) ;
if ( V_35 -> V_50 )
F_39 ( V_35 -> V_50 , NULL ) ;
F_27 ( V_35 ) ;
return V_32 ;
}
V_32 = 0 ;
#ifdef F_74
V_32 = F_75 ( & V_86 ) ;
#endif
return V_32 ;
}
static int F_76 ( void )
{
const struct V_83 * V_84 ;
if ( ! F_72 () )
return 0 ;
if ( F_33 () )
V_84 = & V_85 ;
else {
int V_32 ;
V_84 = & V_62 ;
if ( F_20 () )
V_32 = F_19 () ;
else
V_32 = F_30 () ;
if ( V_32 < 0 )
return V_32 ;
}
F_77 ( V_8 , 0 , V_84 ) ;
return 0 ;
}
static void F_78 ( T_2 V_2 , const char * V_29 , int V_13 )
{
if ( F_79 () )
F_80 ( 0xe9 , V_29 , V_13 ) ;
}
static void F_78 ( T_2 V_2 , const char * V_29 , int V_13 ) { }
static int T_5 F_81 ( struct V_47 * V_47 , char * string )
{
static struct V_1 V_87 ;
if ( F_33 () )
return 0 ;
if ( ! F_31 () )
return - V_36 ;
return F_28 ( & V_87 , 0 ) ;
}
static void F_82 ( struct V_47 * V_47 , const char * string ,
unsigned V_13 )
{
unsigned int V_88 , V_89 = 0 ;
const char * V_90 ;
if ( ! F_31 () ) {
F_78 ( 0 , string , V_13 ) ;
return;
}
F_18 ( 0 , string , V_13 ) ;
if ( F_33 () )
return;
F_12 ( 0 , L_9 , 8 ) ;
while ( V_89 < V_13 && NULL != ( V_90 = strchr ( string + V_89 , '\n' ) ) ) {
V_88 = V_90 - string + V_89 ;
if ( V_89 + V_88 > V_13 )
break;
F_12 ( 0 , string + V_89 , V_88 ) ;
F_12 ( 0 , L_10 , 2 ) ;
V_89 += V_88 + 1 ;
}
if ( V_89 < V_13 )
F_12 ( 0 , string + V_89 , V_13 - V_89 ) ;
}
void F_83 ( const char * V_29 )
{
T_6 V_13 = strlen ( V_29 ) ;
int V_30 = 0 ;
if ( F_72 () ) {
V_30 = F_18 ( 0 , V_29 , V_13 ) ;
if ( V_30 != - V_91 || ! F_20 () )
return;
}
F_78 ( 0 , V_29 , V_13 ) ;
}
void F_84 ( const char * V_92 , ... )
{
static char V_23 [ 512 ] ;
T_7 V_93 ;
va_start ( V_93 , V_92 ) ;
vsnprintf ( V_23 , sizeof( V_23 ) , V_92 , V_93 ) ;
va_end ( V_93 ) ;
F_83 ( V_23 ) ;
}
static void F_85 ( struct V_47 * V_47 ,
const char * string ,
unsigned V_13 )
{
F_18 ( 0 , string , V_13 ) ;
}
static int T_5 F_86 ( struct V_94 * V_95 ,
const char * V_96 )
{
V_95 -> V_97 -> V_98 = F_85 ;
return 0 ;
}
