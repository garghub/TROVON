static struct V_1 * F_1 ( const char * V_2 )
{
struct V_1 * V_3 ;
F_2 (log_type, &_log_types, list)
if ( ! strcmp ( V_2 , V_3 -> V_2 ) )
return V_3 ;
return NULL ;
}
static struct V_1 * F_3 ( const char * V_2 )
{
struct V_1 * V_3 ;
F_4 ( & V_4 ) ;
V_3 = F_1 ( V_2 ) ;
if ( V_3 && ! F_5 ( V_3 -> V_5 ) )
V_3 = NULL ;
F_6 ( & V_4 ) ;
return V_3 ;
}
static struct V_1 * F_7 ( const char * V_6 )
{
char * V_7 , * V_8 ;
struct V_1 * V_3 ;
if ( ! V_6 )
return NULL ;
V_3 = F_3 ( V_6 ) ;
if ( V_3 )
return V_3 ;
V_8 = F_8 ( V_6 , V_9 ) ;
if ( ! V_8 ) {
F_9 ( L_1 ,
V_6 ) ;
return NULL ;
}
while ( F_10 ( L_2 , V_8 ) ||
! ( V_3 = F_3 ( V_6 ) ) ) {
V_7 = strrchr ( V_8 , '-' ) ;
if ( ! V_7 )
break;
V_7 [ 0 ] = '\0' ;
}
if ( ! V_3 )
F_9 ( L_3 , V_6 ) ;
F_11 ( V_8 ) ;
return V_3 ;
}
static void F_12 ( struct V_1 * type )
{
if ( ! type )
return;
F_4 ( & V_4 ) ;
if ( ! F_1 ( type -> V_2 ) )
goto V_10;
F_13 ( type -> V_5 ) ;
V_10:
F_6 ( & V_4 ) ;
}
int F_14 ( struct V_1 * type )
{
int V_11 = 0 ;
F_4 ( & V_4 ) ;
if ( ! F_1 ( type -> V_2 ) )
F_15 ( & type -> V_12 , & V_13 ) ;
else
V_11 = - V_14 ;
F_6 ( & V_4 ) ;
return V_11 ;
}
int F_16 ( struct V_1 * type )
{
F_4 ( & V_4 ) ;
if ( ! F_1 ( type -> V_2 ) ) {
F_6 ( & V_4 ) ;
return - V_15 ;
}
F_17 ( & type -> V_12 ) ;
F_6 ( & V_4 ) ;
return 0 ;
}
struct V_16 * F_18 ( const char * V_6 ,
struct V_17 * V_18 ,
int (* F_19)( struct V_17 * V_18 ) ,
unsigned int V_19 , char * * V_20 )
{
struct V_1 * type ;
struct V_16 * log ;
log = F_20 ( sizeof( * log ) , V_9 ) ;
if ( ! log )
return NULL ;
type = F_7 ( V_6 ) ;
if ( ! type ) {
F_11 ( log ) ;
return NULL ;
}
log -> F_19 = F_19 ;
log -> type = type ;
if ( type -> V_21 ( log , V_18 , V_19 , V_20 ) ) {
F_11 ( log ) ;
F_12 ( type ) ;
return NULL ;
}
return log ;
}
void F_21 ( struct V_16 * log )
{
log -> type -> V_22 ( log ) ;
F_12 ( log -> type ) ;
F_11 ( log ) ;
}
static inline int F_22 ( T_1 * V_23 , unsigned V_24 )
{
return F_23 ( V_24 , ( unsigned long * ) V_23 ) ? 1 : 0 ;
}
static inline void F_24 ( struct V_25 * V_26 ,
T_1 * V_23 , unsigned V_24 )
{
F_25 ( V_24 , ( unsigned long * ) V_23 ) ;
V_26 -> V_27 = 1 ;
}
static inline void F_26 ( struct V_25 * V_26 ,
T_1 * V_23 , unsigned V_24 )
{
F_27 ( V_24 , ( unsigned long * ) V_23 ) ;
V_26 -> V_28 = 1 ;
}
static void F_28 ( struct V_29 * V_30 , struct V_29 * V_31 )
{
V_31 -> V_32 = F_29 ( V_30 -> V_32 ) ;
V_31 -> V_33 = F_29 ( V_30 -> V_33 ) ;
V_31 -> V_34 = F_30 ( V_30 -> V_34 ) ;
}
static void F_31 ( struct V_29 * V_30 , struct V_29 * V_31 )
{
V_30 -> V_32 = F_32 ( V_31 -> V_32 ) ;
V_30 -> V_33 = F_32 ( V_31 -> V_33 ) ;
V_30 -> V_34 = F_33 ( V_31 -> V_34 ) ;
}
static int F_34 ( struct V_25 * V_35 , int V_36 )
{
V_35 -> V_37 . V_38 = V_36 ;
return F_35 ( & V_35 -> V_37 , 1 , & V_35 -> V_39 , NULL ) ;
}
static int F_36 ( struct V_25 * V_35 )
{
struct V_40 V_41 = {
. V_42 = V_35 -> V_39 . V_42 ,
. V_43 = 0 ,
. V_44 = 0 ,
} ;
V_35 -> V_37 . V_38 = V_45 ;
return F_35 ( & V_35 -> V_37 , 1 , & V_41 , NULL ) ;
}
static int F_37 ( struct V_25 * log )
{
int V_11 ;
V_11 = F_34 ( log , V_46 ) ;
if ( V_11 )
return V_11 ;
F_31 ( & log -> V_47 , log -> V_48 ) ;
if ( log -> V_49 != V_50 || log -> V_47 . V_32 != V_51 ) {
log -> V_47 . V_32 = V_51 ;
log -> V_47 . V_33 = V_52 ;
log -> V_47 . V_34 = 0 ;
}
#ifdef F_38
if ( log -> V_47 . V_33 == 1 )
log -> V_47 . V_33 = 2 ;
#endif
if ( log -> V_47 . V_33 != V_52 ) {
F_9 ( L_4 ) ;
return - V_15 ;
}
return 0 ;
}
static int F_39 ( struct V_17 * V_18 , T_1 V_53 )
{
if ( V_53 < 2 || V_53 > V_18 -> V_54 )
return 0 ;
if ( ! F_40 ( V_53 ) )
return 0 ;
return 1 ;
}
static int F_41 ( struct V_16 * log , struct V_17 * V_18 ,
unsigned int V_19 , char * * V_20 ,
struct V_55 * V_56 )
{
enum V_49 V_49 = V_50 ;
struct V_25 * V_35 ;
T_1 V_53 ;
unsigned int V_57 ;
T_2 V_58 , V_59 ;
int V_11 ;
if ( V_19 < 1 || V_19 > 2 ) {
F_9 ( L_5 ) ;
return - V_15 ;
}
if ( V_19 > 1 ) {
if ( ! strcmp ( V_20 [ 1 ] , L_6 ) )
V_49 = V_60 ;
else if ( ! strcmp ( V_20 [ 1 ] , L_7 ) )
V_49 = V_61 ;
else {
F_9 ( L_8
L_9 , V_20 [ 1 ] ) ;
return - V_15 ;
}
}
if ( sscanf ( V_20 [ 0 ] , L_10 , & V_53 ) != 1 ||
! F_39 ( V_18 , V_53 ) ) {
F_9 ( L_11 , V_20 [ 0 ] ) ;
return - V_15 ;
}
V_57 = F_42 ( V_18 -> V_54 , V_53 ) ;
V_35 = F_20 ( sizeof( * V_35 ) , V_9 ) ;
if ( ! V_35 ) {
F_9 ( L_12 ) ;
return - V_62 ;
}
V_35 -> V_18 = V_18 ;
V_35 -> V_28 = 0 ;
V_35 -> V_27 = 0 ;
V_35 -> V_63 = 0 ;
V_35 -> V_53 = V_53 ;
V_35 -> V_57 = V_57 ;
V_35 -> V_49 = V_49 ;
V_58 = F_43 ( V_57 ,
sizeof( * V_35 -> V_64 ) << V_65 ) ;
V_58 >>= V_65 ;
V_35 -> V_66 = V_58 / sizeof( * V_35 -> V_64 ) ;
if ( ! V_56 ) {
V_35 -> V_64 = F_44 ( V_58 ) ;
if ( ! V_35 -> V_64 ) {
F_9 ( L_13 ) ;
F_11 ( V_35 ) ;
return - V_62 ;
}
V_35 -> V_48 = NULL ;
} else {
V_35 -> V_67 = V_56 ;
V_35 -> V_68 = 0 ;
V_35 -> V_69 = 0 ;
V_35 -> V_39 . V_42 = V_35 -> V_67 -> V_42 ;
V_35 -> V_39 . V_43 = 0 ;
V_59 =
F_43 ( ( V_70 << V_71 ) + V_58 ,
F_45 ( V_35 -> V_39 .
V_42 ) ) ;
if ( V_59 > F_46 ( V_56 -> V_42 -> V_72 ) ) {
F_9 ( L_14 ,
V_56 -> V_2 , ( unsigned long long ) V_59 ) ;
F_11 ( V_35 ) ;
return - V_15 ;
}
V_35 -> V_39 . V_44 = V_59 >> V_71 ;
V_35 -> V_37 . V_73 . type = V_74 ;
V_35 -> V_37 . V_75 . V_76 = NULL ;
V_35 -> V_37 . V_77 = F_47 () ;
if ( F_48 ( V_35 -> V_37 . V_77 ) ) {
V_11 = F_49 ( V_35 -> V_37 . V_77 ) ;
F_9 ( L_15 ) ;
F_11 ( V_35 ) ;
return V_11 ;
}
V_35 -> V_48 = F_44 ( V_59 ) ;
if ( ! V_35 -> V_48 ) {
F_9 ( L_16 ) ;
F_50 ( V_35 -> V_37 . V_77 ) ;
F_11 ( V_35 ) ;
return - V_62 ;
}
V_35 -> V_37 . V_73 . V_78 . V_79 = V_35 -> V_48 ;
V_35 -> V_64 = ( void * ) V_35 -> V_48 +
( V_70 << V_71 ) ;
}
memset ( V_35 -> V_64 , - 1 , V_58 ) ;
V_35 -> V_80 = F_44 ( V_58 ) ;
if ( ! V_35 -> V_80 ) {
F_9 ( L_17 ) ;
if ( ! V_56 )
F_51 ( V_35 -> V_64 ) ;
else
F_50 ( V_35 -> V_37 . V_77 ) ;
F_51 ( V_35 -> V_48 ) ;
F_11 ( V_35 ) ;
return - V_62 ;
}
memset ( V_35 -> V_80 , ( V_49 == V_61 ) ? - 1 : 0 , V_58 ) ;
V_35 -> V_81 = ( V_49 == V_61 ) ? V_57 : 0 ;
V_35 -> V_82 = F_44 ( V_58 ) ;
if ( ! V_35 -> V_82 ) {
F_9 ( L_17 ) ;
F_51 ( V_35 -> V_80 ) ;
if ( ! V_56 )
F_51 ( V_35 -> V_64 ) ;
else
F_50 ( V_35 -> V_37 . V_77 ) ;
F_51 ( V_35 -> V_48 ) ;
F_11 ( V_35 ) ;
return - V_62 ;
}
memset ( V_35 -> V_82 , 0 , V_58 ) ;
V_35 -> V_83 = 0 ;
log -> V_84 = V_35 ;
return 0 ;
}
static int F_52 ( struct V_16 * log , struct V_17 * V_18 ,
unsigned int V_19 , char * * V_20 )
{
return F_41 ( log , V_18 , V_19 , V_20 , NULL ) ;
}
static void F_53 ( struct V_25 * V_35 )
{
F_51 ( V_35 -> V_80 ) ;
F_51 ( V_35 -> V_82 ) ;
F_11 ( V_35 ) ;
}
static void F_54 ( struct V_16 * log )
{
struct V_25 * V_35 = (struct V_25 * ) log -> V_84 ;
F_51 ( V_35 -> V_64 ) ;
F_53 ( V_35 ) ;
}
static int F_55 ( struct V_16 * log , struct V_17 * V_18 ,
unsigned int V_19 , char * * V_20 )
{
int V_11 ;
struct V_55 * V_56 ;
if ( V_19 < 2 || V_19 > 3 ) {
F_9 ( L_18 ) ;
return - V_15 ;
}
V_11 = F_56 ( V_18 , V_20 [ 0 ] , F_57 ( V_18 -> V_85 ) , & V_56 ) ;
if ( V_11 )
return V_11 ;
V_11 = F_41 ( log , V_18 , V_19 - 1 , V_20 + 1 , V_56 ) ;
if ( V_11 ) {
F_58 ( V_18 , V_56 ) ;
return V_11 ;
}
return 0 ;
}
static void F_59 ( struct V_16 * log )
{
struct V_25 * V_35 = (struct V_25 * ) log -> V_84 ;
F_58 ( V_35 -> V_18 , V_35 -> V_67 ) ;
F_51 ( V_35 -> V_48 ) ;
F_50 ( V_35 -> V_37 . V_77 ) ;
F_53 ( V_35 ) ;
}
static int F_60 ( T_1 * V_86 , unsigned V_87 )
{
int V_44 = 0 , V_88 ;
for ( V_88 = 0 ; V_88 < V_87 ; V_88 ++ ) {
V_44 += F_61 ( * ( V_86 + V_88 ) ) ;
}
return V_44 ;
}
static void F_62 ( struct V_25 * V_35 )
{
if ( V_35 -> V_68 )
return;
V_35 -> V_68 = 1 ;
F_63 ( V_35 -> V_18 -> V_85 ) ;
}
static int F_64 ( struct V_16 * log )
{
int V_11 ;
unsigned V_88 ;
struct V_25 * V_35 = (struct V_25 * ) log -> V_84 ;
T_2 V_87 = V_35 -> V_66 * sizeof( T_1 ) ;
V_11 = F_37 ( V_35 ) ;
if ( V_11 ) {
F_9 ( L_19 ,
V_35 -> V_67 -> V_2 ) ;
F_62 ( V_35 ) ;
V_35 -> V_47 . V_34 = 0 ;
}
if ( V_35 -> V_49 == V_61 )
for ( V_88 = V_35 -> V_47 . V_34 ; V_88 < V_35 -> V_57 ; V_88 ++ )
F_24 ( V_35 , V_35 -> V_64 , V_88 ) ;
else
for ( V_88 = V_35 -> V_47 . V_34 ; V_88 < V_35 -> V_57 ; V_88 ++ )
F_26 ( V_35 , V_35 -> V_64 , V_88 ) ;
for ( V_88 = V_35 -> V_57 ; V_88 % ( sizeof( * V_35 -> V_64 ) << V_65 ) ; V_88 ++ )
F_26 ( V_35 , V_35 -> V_64 , V_88 ) ;
memcpy ( V_35 -> V_80 , V_35 -> V_64 , V_87 ) ;
V_35 -> V_81 = F_60 ( V_35 -> V_64 , V_35 -> V_66 ) ;
V_35 -> V_83 = 0 ;
V_35 -> V_47 . V_34 = V_35 -> V_57 ;
F_28 ( & V_35 -> V_47 , V_35 -> V_48 ) ;
V_11 = F_34 ( V_35 , V_89 ) ;
if ( ! V_11 ) {
V_11 = F_36 ( V_35 ) ;
if ( V_11 )
V_35 -> V_69 = 1 ;
}
if ( V_11 ) {
F_9 ( L_20 ,
V_35 -> V_67 -> V_2 ) ;
F_62 ( V_35 ) ;
}
return V_11 ;
}
static T_1 F_65 ( struct V_16 * log )
{
struct V_25 * V_35 = (struct V_25 * ) log -> V_84 ;
return V_35 -> V_53 ;
}
static int F_66 ( struct V_16 * log )
{
struct V_25 * V_35 = (struct V_25 * ) log -> V_84 ;
V_35 -> V_83 = 0 ;
return 0 ;
}
static int F_67 ( struct V_16 * log , T_3 V_90 )
{
struct V_25 * V_35 = (struct V_25 * ) log -> V_84 ;
return F_22 ( V_35 -> V_64 , V_90 ) ;
}
static int F_68 ( struct V_16 * log , T_3 V_90 , int V_91 )
{
struct V_25 * V_35 = (struct V_25 * ) log -> V_84 ;
return F_22 ( V_35 -> V_80 , V_90 ) ;
}
static int F_69 ( struct V_16 * log )
{
return 0 ;
}
static int F_70 ( struct V_16 * log )
{
int V_11 , V_88 ;
struct V_25 * V_35 = log -> V_84 ;
if ( ! V_35 -> V_27 && ! V_35 -> V_28 )
return 0 ;
if ( V_35 -> V_27 && log -> F_19 &&
log -> F_19 ( V_35 -> V_18 ) ) {
V_35 -> V_63 = 1 ;
for ( V_88 = 0 ; V_88 < V_35 -> V_57 ; V_88 ++ )
F_26 ( V_35 , V_35 -> V_64 , V_88 ) ;
}
V_11 = F_34 ( V_35 , V_89 ) ;
if ( V_11 )
F_62 ( V_35 ) ;
else {
if ( V_35 -> V_28 ) {
V_11 = F_36 ( V_35 ) ;
if ( V_11 ) {
V_35 -> V_69 = 1 ;
F_62 ( V_35 ) ;
} else
V_35 -> V_28 = 0 ;
}
V_35 -> V_27 = 0 ;
}
return V_11 ;
}
static void F_71 ( struct V_16 * log , T_3 V_90 )
{
struct V_25 * V_35 = (struct V_25 * ) log -> V_84 ;
F_26 ( V_35 , V_35 -> V_64 , V_90 ) ;
}
static void F_72 ( struct V_16 * log , T_3 V_90 )
{
struct V_25 * V_35 = (struct V_25 * ) log -> V_84 ;
if ( F_73 ( ! V_35 -> V_63 ) )
F_24 ( V_35 , V_35 -> V_64 , V_90 ) ;
}
static int F_74 ( struct V_16 * log , T_3 * V_90 )
{
struct V_25 * V_35 = (struct V_25 * ) log -> V_84 ;
if ( V_35 -> V_83 >= V_35 -> V_57 )
return 0 ;
do {
* V_90 = F_75 (
( unsigned long * ) V_35 -> V_80 ,
V_35 -> V_57 ,
V_35 -> V_83 ) ;
V_35 -> V_83 = * V_90 + 1 ;
if ( * V_90 >= V_35 -> V_57 )
return 0 ;
} while ( F_22 ( V_35 -> V_82 , * V_90 ) );
F_24 ( V_35 , V_35 -> V_82 , * V_90 ) ;
return 1 ;
}
static void F_76 ( struct V_16 * log , T_3 V_90 ,
int V_92 )
{
struct V_25 * V_35 = (struct V_25 * ) log -> V_84 ;
F_26 ( V_35 , V_35 -> V_82 , V_90 ) ;
if ( V_92 ) {
F_24 ( V_35 , V_35 -> V_80 , V_90 ) ;
V_35 -> V_81 ++ ;
} else if ( F_22 ( V_35 -> V_80 , V_90 ) ) {
V_35 -> V_81 -- ;
F_26 ( V_35 , V_35 -> V_80 , V_90 ) ;
}
}
static T_3 F_77 ( struct V_16 * log )
{
struct V_25 * V_35 = (struct V_25 * ) log -> V_84 ;
return V_35 -> V_81 ;
}
static int F_78 ( struct V_16 * log , T_4 V_93 ,
char * V_94 , unsigned int V_95 )
{
int V_96 = 0 ;
struct V_25 * V_35 = log -> V_84 ;
switch( V_93 ) {
case V_97 :
F_79 ( L_21 , log -> type -> V_2 ) ;
break;
case V_98 :
F_79 ( L_22 , log -> type -> V_2 ,
V_35 -> V_49 == V_50 ? 1 : 2 , V_35 -> V_53 ) ;
V_99 ;
}
return V_96 ;
}
static int F_80 ( struct V_16 * log , T_4 V_93 ,
char * V_94 , unsigned int V_95 )
{
int V_96 = 0 ;
struct V_25 * V_35 = log -> V_84 ;
switch( V_93 ) {
case V_97 :
F_79 ( L_23 , log -> type -> V_2 , V_35 -> V_67 -> V_2 ,
V_35 -> V_69 ? 'F' :
V_35 -> V_68 ? 'D' :
'A' ) ;
break;
case V_98 :
F_79 ( L_24 , log -> type -> V_2 ,
V_35 -> V_49 == V_50 ? 2 : 3 , V_35 -> V_67 -> V_2 ,
V_35 -> V_53 ) ;
V_99 ;
}
return V_96 ;
}
static int T_5 F_81 ( void )
{
int V_11 ;
V_11 = F_14 ( & V_100 ) ;
if ( V_11 )
F_9 ( L_25 ) ;
V_11 = F_14 ( & V_101 ) ;
if ( V_11 ) {
F_9 ( L_26 ) ;
F_16 ( & V_100 ) ;
}
return V_11 ;
}
static void T_6 F_82 ( void )
{
F_16 ( & V_101 ) ;
F_16 ( & V_100 ) ;
}
