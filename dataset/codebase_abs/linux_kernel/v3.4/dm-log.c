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
return F_23 ( V_24 , V_23 ) ? 1 : 0 ;
}
static inline void F_24 ( struct V_25 * V_26 ,
T_1 * V_23 , unsigned V_24 )
{
F_25 ( V_24 , V_23 ) ;
V_26 -> V_27 = 1 ;
}
static inline void F_26 ( struct V_25 * V_26 ,
T_1 * V_23 , unsigned V_24 )
{
F_27 ( V_24 , V_23 ) ;
V_26 -> V_28 = 1 ;
}
static void F_28 ( struct V_29 * V_30 , struct V_31 * V_32 )
{
V_32 -> V_33 = F_29 ( V_30 -> V_33 ) ;
V_32 -> V_34 = F_29 ( V_30 -> V_34 ) ;
V_32 -> V_35 = F_30 ( V_30 -> V_35 ) ;
}
static void F_31 ( struct V_29 * V_30 , struct V_31 * V_32 )
{
V_30 -> V_33 = F_32 ( V_32 -> V_33 ) ;
V_30 -> V_34 = F_32 ( V_32 -> V_34 ) ;
V_30 -> V_35 = F_33 ( V_32 -> V_35 ) ;
}
static int F_34 ( struct V_25 * V_36 , int V_37 )
{
V_36 -> V_38 . V_39 = V_37 ;
return F_35 ( & V_36 -> V_38 , 1 , & V_36 -> V_40 , NULL ) ;
}
static int F_36 ( struct V_25 * V_36 )
{
struct V_41 V_42 = {
. V_43 = V_36 -> V_40 . V_43 ,
. V_44 = 0 ,
. V_45 = 0 ,
} ;
V_36 -> V_38 . V_39 = V_46 ;
return F_35 ( & V_36 -> V_38 , 1 , & V_42 , NULL ) ;
}
static int F_37 ( struct V_25 * log )
{
int V_11 ;
V_11 = F_34 ( log , V_47 ) ;
if ( V_11 )
return V_11 ;
F_31 ( & log -> V_48 , log -> V_49 ) ;
if ( log -> V_50 != V_51 || log -> V_48 . V_33 != V_52 ) {
log -> V_48 . V_33 = V_52 ;
log -> V_48 . V_34 = V_53 ;
log -> V_48 . V_35 = 0 ;
}
#ifdef F_38
if ( log -> V_48 . V_34 == 1 )
log -> V_48 . V_34 = 2 ;
#endif
if ( log -> V_48 . V_34 != V_53 ) {
F_9 ( L_4 ) ;
return - V_15 ;
}
return 0 ;
}
static int F_39 ( struct V_17 * V_18 , T_1 V_54 )
{
if ( V_54 < 2 || V_54 > V_18 -> V_55 )
return 0 ;
if ( ! F_40 ( V_54 ) )
return 0 ;
return 1 ;
}
static int F_41 ( struct V_16 * log , struct V_17 * V_18 ,
unsigned int V_19 , char * * V_20 ,
struct V_56 * V_57 )
{
enum V_50 V_50 = V_51 ;
struct V_25 * V_36 ;
T_1 V_54 ;
unsigned int V_58 ;
T_2 V_59 , V_60 ;
int V_11 ;
char V_61 ;
if ( V_19 < 1 || V_19 > 2 ) {
F_9 ( L_5 ) ;
return - V_15 ;
}
if ( V_19 > 1 ) {
if ( ! strcmp ( V_20 [ 1 ] , L_6 ) )
V_50 = V_62 ;
else if ( ! strcmp ( V_20 [ 1 ] , L_7 ) )
V_50 = V_63 ;
else {
F_9 ( L_8
L_9 , V_20 [ 1 ] ) ;
return - V_15 ;
}
}
if ( sscanf ( V_20 [ 0 ] , L_10 , & V_54 , & V_61 ) != 1 ||
! F_39 ( V_18 , V_54 ) ) {
F_9 ( L_11 , V_20 [ 0 ] ) ;
return - V_15 ;
}
V_58 = F_42 ( V_18 -> V_55 , V_54 ) ;
V_36 = F_20 ( sizeof( * V_36 ) , V_9 ) ;
if ( ! V_36 ) {
F_9 ( L_12 ) ;
return - V_64 ;
}
V_36 -> V_18 = V_18 ;
V_36 -> V_28 = 0 ;
V_36 -> V_27 = 0 ;
V_36 -> V_65 = 0 ;
V_36 -> V_54 = V_54 ;
V_36 -> V_58 = V_58 ;
V_36 -> V_50 = V_50 ;
V_59 = F_43 ( V_58 ,
sizeof( * V_36 -> V_66 ) << V_67 ) ;
V_59 >>= V_67 ;
V_36 -> V_68 = V_59 / sizeof( * V_36 -> V_66 ) ;
if ( ! V_57 ) {
V_36 -> V_66 = F_44 ( V_59 ) ;
if ( ! V_36 -> V_66 ) {
F_9 ( L_13 ) ;
F_11 ( V_36 ) ;
return - V_64 ;
}
V_36 -> V_49 = NULL ;
} else {
V_36 -> V_69 = V_57 ;
V_36 -> V_70 = 0 ;
V_36 -> V_71 = 0 ;
V_36 -> V_40 . V_43 = V_36 -> V_69 -> V_43 ;
V_36 -> V_40 . V_44 = 0 ;
V_60 =
F_43 ( ( V_72 << V_73 ) + V_59 ,
F_45 ( V_36 -> V_40 .
V_43 ) ) ;
if ( V_60 > F_46 ( V_57 -> V_43 -> V_74 ) ) {
F_9 ( L_14 ,
V_57 -> V_2 , ( unsigned long long ) V_60 ) ;
F_11 ( V_36 ) ;
return - V_15 ;
}
V_36 -> V_40 . V_45 = V_60 >> V_73 ;
V_36 -> V_38 . V_75 . type = V_76 ;
V_36 -> V_38 . V_77 . V_78 = NULL ;
V_36 -> V_38 . V_79 = F_47 () ;
if ( F_48 ( V_36 -> V_38 . V_79 ) ) {
V_11 = F_49 ( V_36 -> V_38 . V_79 ) ;
F_9 ( L_15 ) ;
F_11 ( V_36 ) ;
return V_11 ;
}
V_36 -> V_49 = F_44 ( V_60 ) ;
if ( ! V_36 -> V_49 ) {
F_9 ( L_16 ) ;
F_50 ( V_36 -> V_38 . V_79 ) ;
F_11 ( V_36 ) ;
return - V_64 ;
}
V_36 -> V_38 . V_75 . V_80 . V_81 = V_36 -> V_49 ;
V_36 -> V_66 = ( void * ) V_36 -> V_49 +
( V_72 << V_73 ) ;
}
memset ( V_36 -> V_66 , - 1 , V_59 ) ;
V_36 -> V_82 = F_44 ( V_59 ) ;
if ( ! V_36 -> V_82 ) {
F_9 ( L_17 ) ;
if ( ! V_57 )
F_51 ( V_36 -> V_66 ) ;
else
F_50 ( V_36 -> V_38 . V_79 ) ;
F_51 ( V_36 -> V_49 ) ;
F_11 ( V_36 ) ;
return - V_64 ;
}
memset ( V_36 -> V_82 , ( V_50 == V_63 ) ? - 1 : 0 , V_59 ) ;
V_36 -> V_83 = ( V_50 == V_63 ) ? V_58 : 0 ;
V_36 -> V_84 = F_52 ( V_59 ) ;
if ( ! V_36 -> V_84 ) {
F_9 ( L_17 ) ;
F_51 ( V_36 -> V_82 ) ;
if ( ! V_57 )
F_51 ( V_36 -> V_66 ) ;
else
F_50 ( V_36 -> V_38 . V_79 ) ;
F_51 ( V_36 -> V_49 ) ;
F_11 ( V_36 ) ;
return - V_64 ;
}
V_36 -> V_85 = 0 ;
log -> V_86 = V_36 ;
return 0 ;
}
static int F_53 ( struct V_16 * log , struct V_17 * V_18 ,
unsigned int V_19 , char * * V_20 )
{
return F_41 ( log , V_18 , V_19 , V_20 , NULL ) ;
}
static void F_54 ( struct V_25 * V_36 )
{
F_51 ( V_36 -> V_82 ) ;
F_51 ( V_36 -> V_84 ) ;
F_11 ( V_36 ) ;
}
static void F_55 ( struct V_16 * log )
{
struct V_25 * V_36 = (struct V_25 * ) log -> V_86 ;
F_51 ( V_36 -> V_66 ) ;
F_54 ( V_36 ) ;
}
static int F_56 ( struct V_16 * log , struct V_17 * V_18 ,
unsigned int V_19 , char * * V_20 )
{
int V_11 ;
struct V_56 * V_57 ;
if ( V_19 < 2 || V_19 > 3 ) {
F_9 ( L_18 ) ;
return - V_15 ;
}
V_11 = F_57 ( V_18 , V_20 [ 0 ] , F_58 ( V_18 -> V_87 ) , & V_57 ) ;
if ( V_11 )
return V_11 ;
V_11 = F_41 ( log , V_18 , V_19 - 1 , V_20 + 1 , V_57 ) ;
if ( V_11 ) {
F_59 ( V_18 , V_57 ) ;
return V_11 ;
}
return 0 ;
}
static void F_60 ( struct V_16 * log )
{
struct V_25 * V_36 = (struct V_25 * ) log -> V_86 ;
F_59 ( V_36 -> V_18 , V_36 -> V_69 ) ;
F_51 ( V_36 -> V_49 ) ;
F_50 ( V_36 -> V_38 . V_79 ) ;
F_54 ( V_36 ) ;
}
static int F_61 ( T_1 * V_88 , unsigned V_89 )
{
int V_45 = 0 , V_90 ;
for ( V_90 = 0 ; V_90 < V_89 ; V_90 ++ ) {
V_45 += F_62 ( * ( V_88 + V_90 ) ) ;
}
return V_45 ;
}
static void F_63 ( struct V_25 * V_36 )
{
if ( V_36 -> V_70 )
return;
V_36 -> V_70 = 1 ;
F_64 ( V_36 -> V_18 -> V_87 ) ;
}
static int F_65 ( struct V_16 * log )
{
int V_11 ;
unsigned V_90 ;
struct V_25 * V_36 = (struct V_25 * ) log -> V_86 ;
T_2 V_89 = V_36 -> V_68 * sizeof( T_1 ) ;
V_11 = F_37 ( V_36 ) ;
if ( V_11 ) {
F_9 ( L_19 ,
V_36 -> V_69 -> V_2 ) ;
F_63 ( V_36 ) ;
V_36 -> V_48 . V_35 = 0 ;
}
if ( V_36 -> V_50 == V_63 )
for ( V_90 = V_36 -> V_48 . V_35 ; V_90 < V_36 -> V_58 ; V_90 ++ )
F_24 ( V_36 , V_36 -> V_66 , V_90 ) ;
else
for ( V_90 = V_36 -> V_48 . V_35 ; V_90 < V_36 -> V_58 ; V_90 ++ )
F_26 ( V_36 , V_36 -> V_66 , V_90 ) ;
for ( V_90 = V_36 -> V_58 ; V_90 % ( sizeof( * V_36 -> V_66 ) << V_67 ) ; V_90 ++ )
F_26 ( V_36 , V_36 -> V_66 , V_90 ) ;
memcpy ( V_36 -> V_82 , V_36 -> V_66 , V_89 ) ;
V_36 -> V_83 = F_61 ( V_36 -> V_66 , V_36 -> V_68 ) ;
V_36 -> V_85 = 0 ;
V_36 -> V_48 . V_35 = V_36 -> V_58 ;
F_28 ( & V_36 -> V_48 , V_36 -> V_49 ) ;
V_11 = F_34 ( V_36 , V_91 ) ;
if ( ! V_11 ) {
V_11 = F_36 ( V_36 ) ;
if ( V_11 )
V_36 -> V_71 = 1 ;
}
if ( V_11 ) {
F_9 ( L_20 ,
V_36 -> V_69 -> V_2 ) ;
F_63 ( V_36 ) ;
}
return V_11 ;
}
static T_1 F_66 ( struct V_16 * log )
{
struct V_25 * V_36 = (struct V_25 * ) log -> V_86 ;
return V_36 -> V_54 ;
}
static int F_67 ( struct V_16 * log )
{
struct V_25 * V_36 = (struct V_25 * ) log -> V_86 ;
V_36 -> V_85 = 0 ;
return 0 ;
}
static int F_68 ( struct V_16 * log , T_3 V_92 )
{
struct V_25 * V_36 = (struct V_25 * ) log -> V_86 ;
return F_22 ( V_36 -> V_66 , V_92 ) ;
}
static int F_69 ( struct V_16 * log , T_3 V_92 , int V_93 )
{
struct V_25 * V_36 = (struct V_25 * ) log -> V_86 ;
return F_22 ( V_36 -> V_82 , V_92 ) ;
}
static int F_70 ( struct V_16 * log )
{
return 0 ;
}
static int F_71 ( struct V_16 * log )
{
int V_11 , V_90 ;
struct V_25 * V_36 = log -> V_86 ;
if ( ! V_36 -> V_27 && ! V_36 -> V_28 )
return 0 ;
if ( V_36 -> V_27 && log -> F_19 &&
log -> F_19 ( V_36 -> V_18 ) ) {
V_36 -> V_65 = 1 ;
for ( V_90 = 0 ; V_90 < V_36 -> V_58 ; V_90 ++ )
F_26 ( V_36 , V_36 -> V_66 , V_90 ) ;
}
V_11 = F_34 ( V_36 , V_91 ) ;
if ( V_11 )
F_63 ( V_36 ) ;
else {
if ( V_36 -> V_28 ) {
V_11 = F_36 ( V_36 ) ;
if ( V_11 ) {
V_36 -> V_71 = 1 ;
F_63 ( V_36 ) ;
} else
V_36 -> V_28 = 0 ;
}
V_36 -> V_27 = 0 ;
}
return V_11 ;
}
static void F_72 ( struct V_16 * log , T_3 V_92 )
{
struct V_25 * V_36 = (struct V_25 * ) log -> V_86 ;
F_26 ( V_36 , V_36 -> V_66 , V_92 ) ;
}
static void F_73 ( struct V_16 * log , T_3 V_92 )
{
struct V_25 * V_36 = (struct V_25 * ) log -> V_86 ;
if ( F_74 ( ! V_36 -> V_65 ) )
F_24 ( V_36 , V_36 -> V_66 , V_92 ) ;
}
static int F_75 ( struct V_16 * log , T_3 * V_92 )
{
struct V_25 * V_36 = (struct V_25 * ) log -> V_86 ;
if ( V_36 -> V_85 >= V_36 -> V_58 )
return 0 ;
do {
* V_92 = F_76 ( V_36 -> V_82 ,
V_36 -> V_58 ,
V_36 -> V_85 ) ;
V_36 -> V_85 = * V_92 + 1 ;
if ( * V_92 >= V_36 -> V_58 )
return 0 ;
} while ( F_22 ( V_36 -> V_84 , * V_92 ) );
F_24 ( V_36 , V_36 -> V_84 , * V_92 ) ;
return 1 ;
}
static void F_77 ( struct V_16 * log , T_3 V_92 ,
int V_94 )
{
struct V_25 * V_36 = (struct V_25 * ) log -> V_86 ;
F_26 ( V_36 , V_36 -> V_84 , V_92 ) ;
if ( V_94 ) {
F_24 ( V_36 , V_36 -> V_82 , V_92 ) ;
V_36 -> V_83 ++ ;
} else if ( F_22 ( V_36 -> V_82 , V_92 ) ) {
V_36 -> V_83 -- ;
F_26 ( V_36 , V_36 -> V_82 , V_92 ) ;
}
}
static T_3 F_78 ( struct V_16 * log )
{
struct V_25 * V_36 = (struct V_25 * ) log -> V_86 ;
return V_36 -> V_83 ;
}
static int F_79 ( struct V_16 * log , T_4 V_95 ,
char * V_96 , unsigned int V_97 )
{
int V_98 = 0 ;
struct V_25 * V_36 = log -> V_86 ;
switch( V_95 ) {
case V_99 :
F_80 ( L_21 , log -> type -> V_2 ) ;
break;
case V_100 :
F_80 ( L_22 , log -> type -> V_2 ,
V_36 -> V_50 == V_51 ? 1 : 2 , V_36 -> V_54 ) ;
V_101 ;
}
return V_98 ;
}
static int F_81 ( struct V_16 * log , T_4 V_95 ,
char * V_96 , unsigned int V_97 )
{
int V_98 = 0 ;
struct V_25 * V_36 = log -> V_86 ;
switch( V_95 ) {
case V_99 :
F_80 ( L_23 , log -> type -> V_2 , V_36 -> V_69 -> V_2 ,
V_36 -> V_71 ? 'F' :
V_36 -> V_70 ? 'D' :
'A' ) ;
break;
case V_100 :
F_80 ( L_24 , log -> type -> V_2 ,
V_36 -> V_50 == V_51 ? 2 : 3 , V_36 -> V_69 -> V_2 ,
V_36 -> V_54 ) ;
V_101 ;
}
return V_98 ;
}
static int T_5 F_82 ( void )
{
int V_11 ;
V_11 = F_14 ( & V_102 ) ;
if ( V_11 )
F_9 ( L_25 ) ;
V_11 = F_14 ( & V_103 ) ;
if ( V_11 ) {
F_9 ( L_26 ) ;
F_16 ( & V_102 ) ;
}
return V_11 ;
}
static void T_6 F_83 ( void )
{
F_16 ( & V_103 ) ;
F_16 ( & V_102 ) ;
}
