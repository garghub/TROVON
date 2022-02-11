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
static int F_28 ( void )
{
struct V_1 * V_35 ;
if ( ! F_29 () )
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
V_35 -> V_10 = V_46 -> V_47 . V_48 . V_10 ;
V_35 -> V_16 = F_30 ( V_46 -> V_47 . V_48 . V_34 ) ;
V_35 -> V_2 = V_8 ;
F_24 ( & V_44 ) ;
F_25 ( & V_35 -> V_45 , & V_6 ) ;
F_26 ( & V_44 ) ;
return 0 ;
}
static int F_31 ( void )
{
struct V_1 * V_35 ;
if ( ! F_32 () )
return - V_36 ;
V_35 = F_1 ( V_8 ) ;
if ( ! V_35 ) {
V_35 = F_21 ( sizeof( struct V_1 ) , V_37 ) ;
if ( ! V_35 )
return - V_38 ;
}
V_35 -> V_49 = F_33 ( V_50 , 0 ) ;
V_35 -> V_2 = V_8 ;
F_24 ( & V_44 ) ;
F_25 ( & V_35 -> V_45 , & V_6 ) ;
F_26 ( & V_44 ) ;
return 0 ;
}
void F_34 ( void )
{
struct V_1 * V_35 = F_1 ( V_8 ) ;
if ( V_35 != NULL && V_35 -> V_49 )
F_35 ( V_35 -> V_10 , V_35 -> V_49 ) ;
}
static void F_36 ( struct V_1 * V_35 )
{
if ( V_35 -> V_49 > 0 )
F_37 ( V_35 -> V_49 , NULL ) ;
V_35 -> V_49 = 0 ;
if ( V_35 -> V_10 > 0 )
F_38 ( V_35 -> V_51 , V_35 -> V_10 ) ;
V_35 -> V_10 = 0 ;
if ( V_35 -> V_52 > 0 )
F_39 ( V_35 -> V_52 ) ;
V_35 -> V_52 = 0 ;
if ( V_35 -> V_53 != NULL )
F_40 ( V_35 -> V_53 ) ;
V_35 -> V_53 = NULL ;
}
static void F_41 ( struct V_1 * V_35 )
{
F_42 ( ( unsigned long ) V_35 -> V_16 ) ;
V_35 -> V_16 = NULL ;
V_35 -> V_2 = 0 ;
F_27 ( V_35 ) ;
}
static int F_43 ( struct V_1 * V_35 )
{
F_36 ( V_35 ) ;
F_24 ( & V_44 ) ;
F_44 ( & V_35 -> V_45 ) ;
F_26 ( & V_44 ) ;
if ( V_35 -> V_51 != NULL )
F_41 ( V_35 ) ;
else {
if ( F_20 () )
F_45 ( V_35 -> V_16 ) ;
F_27 ( V_35 ) ;
}
return 0 ;
}
static int F_46 ( struct V_54 * V_55 )
{
return F_43 ( F_47 ( & V_55 -> V_55 ) ) ;
}
static int F_48 ( struct V_54 * V_55 ,
struct V_1 * V_35 )
{
int V_5 , V_10 , V_7 , V_56 , V_49 ;
struct V_57 V_58 ;
T_4 V_59 ;
unsigned long V_34 ;
V_5 = F_49 ( V_55 , & V_10 ) ;
if ( V_5 )
return V_5 ;
V_35 -> V_10 = V_10 ;
V_49 = F_50 ( V_10 ) ;
if ( V_49 < 0 )
return V_49 ;
V_35 -> V_49 = V_49 ;
V_7 = V_55 -> V_60 [ strlen ( V_55 -> V_60 ) - 1 ] - '0' ;
V_35 -> V_53 = F_51 ( F_4 ( V_7 ) ,
V_49 , & V_61 , 256 ) ;
if ( F_52 ( V_35 -> V_53 ) )
return F_53 ( V_35 -> V_53 ) ;
if ( F_29 () )
V_34 = F_54 ( V_35 -> V_16 ) ;
else
V_34 = F_55 ( V_35 -> V_16 ) >> V_42 ;
V_5 = F_56 ( 1 , & V_59 ) ;
if ( V_5 < 0 )
return V_5 ;
V_35 -> V_52 = V_59 ;
V_56 = F_57 ( & V_59 ) ;
if ( V_56 < 0 )
return V_56 ;
F_58 ( V_56 , V_35 -> V_51 -> V_62 ,
V_34 , 0 ) ;
V_63:
V_5 = F_59 ( & V_58 ) ;
if ( V_5 ) {
F_60 ( V_55 , V_5 , L_1 ) ;
return V_5 ;
}
V_5 = F_61 ( V_58 , V_55 -> V_60 , L_2 , L_3 , V_56 ) ;
if ( V_5 )
goto V_64;
V_5 = F_61 ( V_58 , V_55 -> V_60 , L_4 , L_5 ,
V_10 ) ;
if ( V_5 )
goto V_64;
V_5 = F_62 ( V_58 , 0 ) ;
if ( V_5 ) {
if ( V_5 == - V_65 )
goto V_63;
F_60 ( V_55 , V_5 , L_6 ) ;
return V_5 ;
}
F_63 ( V_55 , V_66 ) ;
return 0 ;
V_64:
F_62 ( V_58 , 1 ) ;
F_60 ( V_55 , V_5 , L_7 ) ;
return V_5 ;
}
static int F_64 ( struct V_54 * V_55 ,
const struct V_67 * V_68 )
{
int V_5 , V_7 ;
struct V_1 * V_35 ;
V_7 = V_55 -> V_60 [ strlen ( V_55 -> V_60 ) - 1 ] - '0' ;
if ( V_7 == 0 )
return - V_36 ;
V_35 = F_21 ( sizeof( struct V_1 ) , V_37 ) ;
if ( ! V_35 )
return - V_38 ;
F_65 ( & V_55 -> V_55 , V_35 ) ;
V_35 -> V_51 = V_55 ;
V_35 -> V_2 = F_4 ( V_7 ) ;
V_35 -> V_16 = ( void * ) F_66 ( V_37 | V_69 ) ;
if ( ! V_35 -> V_16 )
goto V_70;
V_5 = F_48 ( V_55 , V_35 ) ;
if ( V_5 < 0 )
goto error;
F_24 ( & V_44 ) ;
F_25 ( & V_35 -> V_45 , & V_6 ) ;
F_26 ( & V_44 ) ;
return 0 ;
V_70:
V_5 = - V_38 ;
F_60 ( V_55 , V_5 , L_8 ) ;
error:
F_36 ( V_35 ) ;
F_41 ( V_35 ) ;
return V_5 ;
}
static int F_67 ( struct V_54 * V_55 )
{
struct V_1 * V_35 = F_47 ( & V_55 -> V_55 ) ;
F_36 ( V_35 ) ;
memset ( V_35 -> V_16 , 0 , V_43 ) ;
return F_48 ( V_55 , V_35 ) ;
}
static void F_68 ( struct V_54 * V_55 ,
enum V_71 V_72 )
{
switch ( V_72 ) {
case V_73 :
case V_74 :
case V_75 :
case V_66 :
case V_76 :
break;
case V_77 :
break;
case V_78 :
F_63 ( V_55 , V_78 ) ;
break;
case V_79 :
if ( V_55 -> V_80 == V_79 )
break;
case V_81 :
F_69 ( V_55 ) ;
break;
}
}
static int T_5 F_70 ( void )
{
int V_32 ;
struct V_1 * V_35 ;
const struct V_82 * V_83 ;
if ( ! F_71 () )
return - V_36 ;
if ( F_32 () ) {
V_83 = & V_84 ;
V_32 = F_31 () ;
if ( V_32 < 0 )
return V_32 ;
V_35 = F_1 ( V_8 ) ;
} else {
V_83 = & V_61 ;
if ( F_20 () )
V_32 = F_19 () ;
else
V_32 = F_28 () ;
if ( V_32 < 0 )
return V_32 ;
V_35 = F_1 ( V_8 ) ;
V_35 -> V_49 = F_50 ( V_35 -> V_10 ) ;
}
if ( V_35 -> V_49 < 0 )
V_35 -> V_49 = 0 ;
else
F_72 ( V_35 -> V_49 ) ;
V_35 -> V_53 = F_51 ( V_8 , V_35 -> V_49 , V_83 , 256 ) ;
if ( F_52 ( V_35 -> V_53 ) ) {
V_32 = F_53 ( V_35 -> V_53 ) ;
F_24 ( & V_44 ) ;
F_44 ( & V_35 -> V_45 ) ;
F_26 ( & V_44 ) ;
if ( V_35 -> V_49 )
F_37 ( V_35 -> V_49 , NULL ) ;
F_27 ( V_35 ) ;
return V_32 ;
}
V_32 = 0 ;
#ifdef F_73
V_32 = F_74 ( & V_85 ) ;
#endif
return V_32 ;
}
static int F_75 ( void )
{
const struct V_82 * V_83 ;
if ( ! F_71 () )
return 0 ;
if ( F_32 () )
V_83 = & V_84 ;
else {
int V_32 ;
V_83 = & V_61 ;
if ( F_20 () )
V_32 = F_19 () ;
else
V_32 = F_28 () ;
if ( V_32 < 0 )
return V_32 ;
}
F_76 ( V_8 , 0 , V_83 ) ;
return 0 ;
}
static void F_77 ( struct V_47 * V_47 , const char * string ,
unsigned V_13 )
{
unsigned int V_86 , V_87 = 0 ;
const char * V_88 ;
if ( ! F_29 () )
return;
F_18 ( 0 , string , V_13 ) ;
if ( F_32 () )
return;
F_12 ( 0 , L_9 , 8 ) ;
while ( V_87 < V_13 && NULL != ( V_88 = strchr ( string + V_87 , '\n' ) ) ) {
V_86 = V_88 - string + V_87 ;
if ( V_87 + V_86 > V_13 )
break;
F_12 ( 0 , string + V_87 , V_86 ) ;
F_12 ( 0 , L_10 , 2 ) ;
V_87 += V_86 + 1 ;
}
if ( V_87 < V_13 )
F_12 ( 0 , string + V_87 , V_13 - V_87 ) ;
}
void F_78 ( const char * V_29 )
{
T_6 V_13 = strlen ( V_29 ) ;
int V_30 = 0 ;
if ( F_71 () ) {
V_30 = F_18 ( 0 , V_29 , V_13 ) ;
#ifdef F_79
if ( V_30 == - V_89 && F_20 () )
goto V_90;
} else if ( F_80 () ) {
int V_91 ;
V_90:
for ( V_91 = 0 ; V_91 < V_13 ; V_91 ++ )
F_81 ( V_29 [ V_91 ] , 0xe9 ) ;
#endif
}
}
void F_82 ( const char * V_92 , ... )
{
static char V_23 [ 512 ] ;
T_7 V_93 ;
va_start ( V_93 , V_92 ) ;
vsnprintf ( V_23 , sizeof( V_23 ) , V_92 , V_93 ) ;
va_end ( V_93 ) ;
F_78 ( V_23 ) ;
}
