static void F_1 ( struct V_1 * V_2 )
{
unsigned int V_3 ;
for ( V_3 = 0 ; V_3 < V_4 ; V_3 ++ )
F_2 ( V_2 + V_3 ) ;
}
static int F_3 ( void )
{
F_1 ( V_5 ) ;
F_1 ( V_6 ) ;
return 0 ;
}
static void F_4 ( void )
{
F_5 ( false , false , false ) ;
}
static unsigned int F_6 ( const char * V_7 )
{
const unsigned int V_8 = 2654435387U ;
unsigned int V_9 = 0 ;
while ( * V_7 )
V_9 = ( V_9 + ( unsigned int ) * V_7 ++ ) * V_8 ;
return V_9 & V_10 ;
}
static struct V_11 * F_7 ( const char * V_7 )
{
struct V_11 * V_12 ;
unsigned int V_9 = F_6 ( V_7 ) ;
F_8 (hc, _name_buckets + h, name_list)
if ( ! strcmp ( V_12 -> V_13 , V_7 ) ) {
F_9 ( V_12 -> V_14 ) ;
return V_12 ;
}
return NULL ;
}
static struct V_11 * F_10 ( const char * V_7 )
{
struct V_11 * V_12 ;
unsigned int V_9 = F_6 ( V_7 ) ;
F_8 (hc, _uuid_buckets + h, uuid_list)
if ( ! strcmp ( V_12 -> V_15 , V_7 ) ) {
F_9 ( V_12 -> V_14 ) ;
return V_12 ;
}
return NULL ;
}
static struct V_11 * F_11 ( T_1 V_16 )
{
struct V_17 * V_14 ;
struct V_11 * V_12 ;
V_14 = F_12 ( F_13 ( V_16 ) ) ;
if ( ! V_14 )
return NULL ;
V_12 = F_14 ( V_14 ) ;
if ( ! V_12 ) {
F_15 ( V_14 ) ;
return NULL ;
}
return V_12 ;
}
static struct V_11 * F_16 ( const char * V_13 , const char * V_15 ,
struct V_17 * V_14 )
{
struct V_11 * V_12 ;
V_12 = F_17 ( sizeof( * V_12 ) , V_18 ) ;
if ( ! V_12 )
return NULL ;
V_12 -> V_13 = F_18 ( V_13 , V_18 ) ;
if ( ! V_12 -> V_13 ) {
F_19 ( V_12 ) ;
return NULL ;
}
if ( ! V_15 )
V_12 -> V_15 = NULL ;
else {
V_12 -> V_15 = F_18 ( V_15 , V_18 ) ;
if ( ! V_12 -> V_15 ) {
F_19 ( V_12 -> V_13 ) ;
F_19 ( V_12 ) ;
return NULL ;
}
}
F_2 ( & V_12 -> V_19 ) ;
F_2 ( & V_12 -> V_20 ) ;
V_12 -> V_14 = V_14 ;
V_12 -> V_21 = NULL ;
return V_12 ;
}
static void F_20 ( struct V_11 * V_12 )
{
if ( V_12 ) {
F_19 ( V_12 -> V_13 ) ;
F_19 ( V_12 -> V_15 ) ;
F_19 ( V_12 ) ;
}
}
static int F_21 ( const char * V_13 , const char * V_15 , struct V_17 * V_14 )
{
struct V_11 * V_22 , * V_12 ;
V_22 = F_16 ( V_13 , V_15 , V_14 ) ;
if ( ! V_22 )
return - V_23 ;
F_22 ( & V_24 ) ;
V_12 = F_7 ( V_13 ) ;
if ( V_12 ) {
F_15 ( V_12 -> V_14 ) ;
goto V_25;
}
F_23 ( & V_22 -> V_19 , V_5 + F_6 ( V_13 ) ) ;
if ( V_15 ) {
V_12 = F_10 ( V_15 ) ;
if ( V_12 ) {
F_24 ( & V_22 -> V_19 ) ;
F_15 ( V_12 -> V_14 ) ;
goto V_25;
}
F_23 ( & V_22 -> V_20 , V_6 + F_6 ( V_15 ) ) ;
}
F_9 ( V_14 ) ;
F_25 ( & V_26 ) ;
F_26 ( V_14 , V_22 ) ;
F_27 ( & V_26 ) ;
F_28 ( & V_24 ) ;
return 0 ;
V_25:
F_28 ( & V_24 ) ;
F_20 ( V_22 ) ;
return - V_27 ;
}
static struct V_28 * F_29 ( struct V_11 * V_12 )
{
struct V_28 * V_29 ;
int V_30 ;
F_24 ( & V_12 -> V_20 ) ;
F_24 ( & V_12 -> V_19 ) ;
F_25 ( & V_26 ) ;
F_26 ( V_12 -> V_14 , NULL ) ;
F_27 ( & V_26 ) ;
V_29 = F_30 ( V_12 -> V_14 , & V_30 ) ;
if ( V_29 )
F_31 ( V_29 ) ;
F_32 ( V_12 -> V_14 , V_30 ) ;
V_29 = NULL ;
if ( V_12 -> V_21 )
V_29 = V_12 -> V_21 ;
F_15 ( V_12 -> V_14 ) ;
F_20 ( V_12 ) ;
return V_29 ;
}
static void F_5 ( bool V_31 , bool V_32 , bool V_33 )
{
int V_3 , V_34 ;
struct V_11 * V_12 ;
struct V_17 * V_14 ;
struct V_28 * V_35 ;
V_36:
V_34 = 0 ;
F_22 ( & V_24 ) ;
for ( V_3 = 0 ; V_3 < V_4 ; V_3 ++ ) {
F_8 (hc, _name_buckets + i, name_list) {
V_14 = V_12 -> V_14 ;
F_9 ( V_14 ) ;
if ( V_31 &&
F_33 ( V_14 , V_32 , V_33 ) ) {
F_15 ( V_14 ) ;
V_34 ++ ;
continue;
}
V_35 = F_29 ( V_12 ) ;
F_28 ( & V_24 ) ;
if ( V_35 ) {
F_34 ( V_14 ) ;
F_35 ( V_35 ) ;
}
F_15 ( V_14 ) ;
if ( F_36 ( V_31 ) )
F_37 ( V_14 ) ;
else
F_38 ( V_14 ) ;
goto V_36;
}
}
F_28 ( & V_24 ) ;
if ( V_34 )
F_39 ( L_1 , V_34 ) ;
}
static void F_40 ( struct V_11 * V_12 , char * V_37 )
{
F_25 ( & V_26 ) ;
V_12 -> V_15 = V_37 ;
F_27 ( & V_26 ) ;
F_23 ( & V_12 -> V_20 , V_6 + F_6 ( V_37 ) ) ;
}
static char * F_41 ( struct V_11 * V_12 , char * V_38 )
{
char * V_39 ;
F_24 ( & V_12 -> V_19 ) ;
V_39 = V_12 -> V_13 ;
F_25 ( & V_26 ) ;
V_12 -> V_13 = V_38 ;
F_27 ( & V_26 ) ;
F_23 ( & V_12 -> V_19 , V_5 + F_6 ( V_38 ) ) ;
return V_39 ;
}
static struct V_17 * F_42 ( struct V_40 * V_41 ,
const char * V_42 )
{
char * V_43 , * V_39 = NULL ;
struct V_11 * V_12 ;
struct V_28 * V_29 ;
struct V_17 * V_14 ;
unsigned V_44 = ( V_41 -> V_45 & V_46 ) ? 1 : 0 ;
int V_30 ;
V_43 = F_18 ( V_42 , V_18 ) ;
if ( ! V_43 )
return F_43 ( - V_23 ) ;
F_22 ( & V_24 ) ;
if ( V_44 )
V_12 = F_10 ( V_42 ) ;
else
V_12 = F_7 ( V_42 ) ;
if ( V_12 ) {
F_39 ( L_2
L_3 ,
V_44 ? L_4 : L_5 ,
V_41 -> V_13 , V_42 ) ;
F_15 ( V_12 -> V_14 ) ;
F_28 ( & V_24 ) ;
F_19 ( V_43 ) ;
return F_43 ( - V_27 ) ;
}
V_12 = F_7 ( V_41 -> V_13 ) ;
if ( ! V_12 ) {
F_39 ( L_6 ,
V_41 -> V_13 , V_44 ? L_7 : L_8 , V_42 ) ;
F_28 ( & V_24 ) ;
F_19 ( V_43 ) ;
return F_43 ( - V_47 ) ;
}
if ( V_44 && V_12 -> V_15 ) {
F_39 ( L_9
L_10 ,
V_41 -> V_13 , V_42 , V_12 -> V_15 ) ;
F_15 ( V_12 -> V_14 ) ;
F_28 ( & V_24 ) ;
F_19 ( V_43 ) ;
return F_43 ( - V_48 ) ;
}
if ( V_44 )
F_40 ( V_12 , V_43 ) ;
else
V_39 = F_41 ( V_12 , V_43 ) ;
V_29 = F_30 ( V_12 -> V_14 , & V_30 ) ;
if ( V_29 )
F_31 ( V_29 ) ;
F_32 ( V_12 -> V_14 , V_30 ) ;
if ( ! F_44 ( V_12 -> V_14 , V_49 , V_41 -> V_50 ) )
V_41 -> V_45 |= V_51 ;
V_14 = V_12 -> V_14 ;
F_28 ( & V_24 ) ;
F_19 ( V_39 ) ;
return V_14 ;
}
void F_45 ( void )
{
F_5 ( true , false , true ) ;
}
static int F_46 ( struct V_52 * V_53 , struct V_40 * V_41 , T_2 V_54 )
{
F_5 ( true , ! ! ( V_41 -> V_45 & V_55 ) , false ) ;
V_41 -> V_56 = 0 ;
return 0 ;
}
static inline void * F_47 ( void * V_57 )
{
return ( void * ) ( ( ( T_2 ) ( V_57 + V_58 ) ) & ~ V_58 ) ;
}
static void * F_48 ( struct V_40 * V_41 , T_2 V_54 ,
T_2 * V_59 )
{
V_41 -> V_60 = F_47 ( V_41 + 1 ) - ( void * ) V_41 ;
if ( V_41 -> V_60 < V_54 )
* V_59 = V_54 - V_41 -> V_60 ;
else
* V_59 = 0 ;
return ( ( void * ) V_41 ) + V_41 -> V_60 ;
}
static int F_49 ( struct V_52 * V_53 , struct V_40 * V_41 , T_2 V_54 )
{
unsigned int V_3 ;
struct V_11 * V_12 ;
T_2 V_59 , V_61 = 0 ;
struct V_62 * V_63 ;
struct V_64 * V_65 , * V_66 = NULL ;
T_3 * V_50 ;
F_22 ( & V_24 ) ;
for ( V_3 = 0 ; V_3 < V_4 ; V_3 ++ ) {
F_8 (hc, _name_buckets + i, name_list) {
V_61 += sizeof( struct V_64 ) ;
V_61 += strlen ( V_12 -> V_13 ) + 1 ;
V_61 += V_58 ;
V_61 += ( sizeof( T_3 ) + V_58 ) & ~ V_58 ;
}
}
V_65 = F_48 ( V_41 , V_54 , & V_59 ) ;
if ( V_59 < V_61 ) {
V_41 -> V_45 |= V_67 ;
goto V_68;
}
V_41 -> V_56 = V_41 -> V_60 + V_61 ;
V_65 -> V_16 = 0 ;
for ( V_3 = 0 ; V_3 < V_4 ; V_3 ++ ) {
F_8 (hc, _name_buckets + i, name_list) {
if ( V_66 )
V_66 -> V_69 = ( T_3 ) ( ( void * ) V_65 -
( void * ) V_66 ) ;
V_63 = F_50 ( V_12 -> V_14 ) ;
V_65 -> V_16 = F_51 ( F_52 ( V_63 ) ) ;
V_65 -> V_69 = 0 ;
strcpy ( V_65 -> V_13 , V_12 -> V_13 ) ;
V_66 = V_65 ;
V_50 = F_47 ( ( ( void * ) ( V_65 + 1 ) ) + strlen ( V_12 -> V_13 ) + 1 ) ;
* V_50 = F_53 ( V_12 -> V_14 ) ;
V_65 = F_47 ( V_50 + 1 ) ;
}
}
V_68:
F_28 ( & V_24 ) ;
return 0 ;
}
static void F_54 ( struct V_70 * V_71 , void * V_72 )
{
T_2 * V_61 = V_72 ;
* V_61 += sizeof( struct V_73 ) ;
* V_61 += strlen ( V_71 -> V_13 ) ;
* V_61 += V_58 ;
}
static void F_55 ( struct V_70 * V_71 , void * V_41 )
{
struct V_74 * V_75 = V_41 ;
if ( ( char * ) V_75 -> V_76 + sizeof( V_71 -> V_77 ) + strlen ( V_71 -> V_13 ) + 1 >
V_75 -> V_78 ) {
V_75 -> V_45 = V_67 ;
return;
}
if ( V_75 -> V_79 )
V_75 -> V_79 -> V_69 = ( T_3 ) ( ( void * ) V_75 -> V_76 -
( void * ) V_75 -> V_79 ) ;
V_75 -> V_76 -> V_77 [ 0 ] = V_71 -> V_77 [ 0 ] ;
V_75 -> V_76 -> V_77 [ 1 ] = V_71 -> V_77 [ 1 ] ;
V_75 -> V_76 -> V_77 [ 2 ] = V_71 -> V_77 [ 2 ] ;
V_75 -> V_76 -> V_69 = 0 ;
strcpy ( V_75 -> V_76 -> V_13 , V_71 -> V_13 ) ;
V_75 -> V_79 = V_75 -> V_76 ;
V_75 -> V_76 = F_47 ( ( ( void * ) ++ V_75 -> V_76 ) + strlen ( V_71 -> V_13 ) + 1 ) ;
}
static int F_56 ( struct V_52 * V_53 , struct V_40 * V_41 , T_2 V_54 )
{
T_2 V_59 , V_61 = 0 ;
struct V_73 * V_76 ;
struct V_74 V_80 ;
F_57 ( F_54 , & V_61 ) ;
V_76 = F_48 ( V_41 , V_54 , & V_59 ) ;
if ( V_59 < V_61 ) {
V_41 -> V_45 |= V_67 ;
goto V_68;
}
V_41 -> V_56 = V_41 -> V_60 + V_61 ;
V_80 . V_54 = V_54 ;
V_80 . V_79 = NULL ;
V_80 . V_76 = V_76 ;
V_80 . V_45 = 0 ;
V_80 . V_78 = ( char * ) V_76 + V_59 ;
F_57 ( F_55 , & V_80 ) ;
V_41 -> V_45 |= V_80 . V_45 ;
V_68:
return 0 ;
}
static int F_58 ( const char * V_13 )
{
if ( strchr ( V_13 , '/' ) ) {
F_39 ( L_11 ) ;
return - V_48 ;
}
return 0 ;
}
static struct V_28 * F_59 ( struct V_17 * V_14 , int * V_30 )
{
struct V_11 * V_12 ;
struct V_28 * V_29 = NULL ;
F_30 ( V_14 , V_30 ) ;
F_60 ( & V_24 ) ;
V_12 = F_14 ( V_14 ) ;
if ( ! V_12 || V_12 -> V_14 != V_14 ) {
F_39 ( L_12 ) ;
goto V_68;
}
V_29 = V_12 -> V_21 ;
V_68:
F_61 ( & V_24 ) ;
return V_29 ;
}
static struct V_28 * F_62 ( struct V_17 * V_14 ,
struct V_40 * V_41 ,
int * V_30 )
{
return ( V_41 -> V_45 & V_81 ) ?
F_59 ( V_14 , V_30 ) : F_30 ( V_14 , V_30 ) ;
}
static void F_63 ( struct V_17 * V_14 , struct V_40 * V_41 )
{
struct V_62 * V_63 = F_50 ( V_14 ) ;
struct V_28 * V_29 ;
int V_30 ;
V_41 -> V_45 &= ~ ( V_82 | V_83 |
V_84 | V_85 ) ;
if ( F_64 ( V_14 ) )
V_41 -> V_45 |= V_82 ;
if ( F_65 ( V_14 ) )
V_41 -> V_45 |= V_85 ;
if ( F_66 ( V_14 ) )
V_41 -> V_45 |= V_55 ;
V_41 -> V_16 = F_51 ( F_52 ( V_63 ) ) ;
V_41 -> V_86 = F_67 ( V_14 ) ;
V_41 -> V_50 = F_53 ( V_14 ) ;
V_41 -> V_87 = 0 ;
V_29 = F_30 ( V_14 , & V_30 ) ;
if ( V_29 ) {
if ( ! ( V_41 -> V_45 & V_81 ) ) {
if ( F_68 ( V_63 ) )
V_41 -> V_45 |= V_83 ;
V_41 -> V_87 = F_69 ( V_29 ) ;
}
V_41 -> V_45 |= V_84 ;
}
F_32 ( V_14 , V_30 ) ;
if ( V_41 -> V_45 & V_81 ) {
int V_30 ;
V_29 = F_59 ( V_14 , & V_30 ) ;
if ( V_29 ) {
if ( ! ( F_70 ( V_29 ) & V_88 ) )
V_41 -> V_45 |= V_83 ;
V_41 -> V_87 = F_69 ( V_29 ) ;
}
F_32 ( V_14 , V_30 ) ;
}
}
static int F_71 ( struct V_52 * V_53 , struct V_40 * V_41 , T_2 V_54 )
{
int V_89 , V_90 = V_91 ;
struct V_17 * V_14 ;
V_89 = F_58 ( V_41 -> V_13 ) ;
if ( V_89 )
return V_89 ;
if ( V_41 -> V_45 & V_92 )
V_90 = F_72 ( F_13 ( V_41 -> V_16 ) ) ;
V_89 = F_73 ( V_90 , & V_14 ) ;
if ( V_89 )
return V_89 ;
V_89 = F_21 ( V_41 -> V_13 , * V_41 -> V_15 ? V_41 -> V_15 : NULL , V_14 ) ;
if ( V_89 ) {
F_15 ( V_14 ) ;
F_37 ( V_14 ) ;
return V_89 ;
}
V_41 -> V_45 &= ~ V_93 ;
F_63 ( V_14 , V_41 ) ;
F_15 ( V_14 ) ;
return 0 ;
}
static struct V_11 * F_74 ( struct V_40 * V_41 )
{
struct V_11 * V_12 = NULL ;
if ( * V_41 -> V_15 ) {
if ( * V_41 -> V_13 || V_41 -> V_16 )
return NULL ;
V_12 = F_10 ( V_41 -> V_15 ) ;
if ( ! V_12 )
return NULL ;
} else if ( * V_41 -> V_13 ) {
if ( V_41 -> V_16 )
return NULL ;
V_12 = F_7 ( V_41 -> V_13 ) ;
if ( ! V_12 )
return NULL ;
} else if ( V_41 -> V_16 ) {
V_12 = F_11 ( V_41 -> V_16 ) ;
if ( ! V_12 )
return NULL ;
} else
return NULL ;
F_75 ( V_41 -> V_13 , V_12 -> V_13 , sizeof( V_41 -> V_13 ) ) ;
if ( V_12 -> V_15 )
F_75 ( V_41 -> V_15 , V_12 -> V_15 , sizeof( V_41 -> V_15 ) ) ;
else
V_41 -> V_15 [ 0 ] = '\0' ;
if ( V_12 -> V_21 )
V_41 -> V_45 |= V_93 ;
else
V_41 -> V_45 &= ~ V_93 ;
return V_12 ;
}
static struct V_17 * F_76 ( struct V_40 * V_41 )
{
struct V_11 * V_12 ;
struct V_17 * V_14 = NULL ;
F_60 ( & V_24 ) ;
V_12 = F_74 ( V_41 ) ;
if ( V_12 )
V_14 = V_12 -> V_14 ;
F_61 ( & V_24 ) ;
return V_14 ;
}
static int F_77 ( struct V_52 * V_53 , struct V_40 * V_41 , T_2 V_54 )
{
struct V_11 * V_12 ;
struct V_17 * V_14 ;
int V_89 ;
struct V_28 * V_35 ;
F_22 ( & V_24 ) ;
V_12 = F_74 ( V_41 ) ;
if ( ! V_12 ) {
F_78 ( L_13 ) ;
F_28 ( & V_24 ) ;
return - V_47 ;
}
V_14 = V_12 -> V_14 ;
V_89 = F_33 ( V_14 , ! ! ( V_41 -> V_45 & V_55 ) , false ) ;
if ( V_89 ) {
if ( V_89 == - V_27 && V_41 -> V_45 & V_55 ) {
F_28 ( & V_24 ) ;
F_15 ( V_14 ) ;
return 0 ;
}
F_78 ( L_14 , V_12 -> V_13 ) ;
F_28 ( & V_24 ) ;
F_15 ( V_14 ) ;
return V_89 ;
}
V_35 = F_29 ( V_12 ) ;
F_28 ( & V_24 ) ;
if ( V_35 ) {
F_34 ( V_14 ) ;
F_35 ( V_35 ) ;
}
V_41 -> V_45 &= ~ V_55 ;
if ( ! F_44 ( V_14 , V_94 , V_41 -> V_50 ) )
V_41 -> V_45 |= V_51 ;
F_15 ( V_14 ) ;
F_37 ( V_14 ) ;
return 0 ;
}
static int F_79 ( char * V_7 , void * V_78 )
{
while ( ( void * ) V_7 < V_78 )
if ( ! * V_7 ++ )
return 0 ;
return - V_48 ;
}
static int F_80 ( struct V_52 * V_53 , struct V_40 * V_41 , T_2 V_54 )
{
int V_89 ;
char * V_43 = ( char * ) V_41 + V_41 -> V_60 ;
struct V_17 * V_14 ;
unsigned V_44 = ( V_41 -> V_45 & V_46 ) ? 1 : 0 ;
if ( V_43 < V_41 -> V_95 ||
F_79 ( V_43, ( void * ) V_41 + V_54 ) || ! * V_43 ||
strlen ( V_43 ) > ( V_44 ? V_96 - 1 : V_97 - 1 ) ) {
F_39 ( L_15 ) ;
return - V_48 ;
}
if ( ! V_44 ) {
V_89 = F_58 ( V_43 ) ;
if ( V_89 )
return V_89 ;
}
V_14 = F_42 ( V_41 , V_43 ) ;
if ( F_81 ( V_14 ) )
return F_82 ( V_14 ) ;
F_63 ( V_14 , V_41 ) ;
F_15 ( V_14 ) ;
return 0 ;
}
static int F_83 ( struct V_52 * V_53 , struct V_40 * V_41 , T_2 V_54 )
{
int V_89 = - V_48 , V_98 ;
struct V_17 * V_14 ;
struct V_99 V_100 ;
unsigned long V_101 [ 4 ] ;
char * V_102 = ( char * ) V_41 + V_41 -> V_60 ;
char V_103 ;
V_14 = F_76 ( V_41 ) ;
if ( ! V_14 )
return - V_47 ;
if ( V_102 < V_41 -> V_95 ||
F_79 ( V_102 , ( void * ) V_41 + V_54 ) ) {
F_39 ( L_16 ) ;
goto V_68;
}
V_98 = sscanf ( V_102 , L_17 , V_101 ,
V_101 + 1 , V_101 + 2 , V_101 + 3 , & V_103 ) ;
if ( V_98 != 4 ) {
F_39 ( L_18 ) ;
goto V_68;
}
if ( V_101 [ 0 ] > 65535 || V_101 [ 1 ] > 255 ||
V_101 [ 2 ] > 255 || V_101 [ 3 ] > V_104 ) {
F_39 ( L_19 ) ;
goto V_68;
}
V_100 . V_105 = V_101 [ 0 ] ;
V_100 . V_106 = V_101 [ 1 ] ;
V_100 . V_107 = V_101 [ 2 ] ;
V_100 . V_108 = V_101 [ 3 ] ;
V_89 = F_84 ( V_14 , & V_100 ) ;
V_41 -> V_56 = 0 ;
V_68:
F_15 ( V_14 ) ;
return V_89 ;
}
static int F_85 ( struct V_40 * V_41 )
{
int V_89 = 0 ;
unsigned V_109 = V_110 ;
struct V_17 * V_14 ;
V_14 = F_76 ( V_41 ) ;
if ( ! V_14 )
return - V_47 ;
if ( V_41 -> V_45 & V_111 )
V_109 &= ~ V_110 ;
if ( V_41 -> V_45 & V_112 )
V_109 |= V_113 ;
if ( ! F_64 ( V_14 ) ) {
V_89 = F_86 ( V_14 , V_109 ) ;
if ( V_89 )
goto V_68;
}
F_63 ( V_14 , V_41 ) ;
V_68:
F_15 ( V_14 ) ;
return V_89 ;
}
static int F_87 ( struct V_40 * V_41 )
{
int V_89 = 0 ;
unsigned V_109 = V_110 ;
struct V_11 * V_12 ;
struct V_17 * V_14 ;
struct V_28 * V_21 , * V_114 = NULL ;
F_22 ( & V_24 ) ;
V_12 = F_74 ( V_41 ) ;
if ( ! V_12 ) {
F_78 ( L_13 ) ;
F_28 ( & V_24 ) ;
return - V_47 ;
}
V_14 = V_12 -> V_14 ;
V_21 = V_12 -> V_21 ;
V_12 -> V_21 = NULL ;
V_41 -> V_45 &= ~ V_93 ;
F_28 ( & V_24 ) ;
if ( V_21 ) {
if ( V_41 -> V_45 & V_111 )
V_109 &= ~ V_110 ;
if ( V_41 -> V_45 & V_112 )
V_109 |= V_113 ;
if ( ! F_64 ( V_14 ) )
F_86 ( V_14 , V_109 ) ;
V_114 = F_88 ( V_14 , V_21 ) ;
if ( F_81 ( V_114 ) ) {
F_34 ( V_14 ) ;
F_35 ( V_21 ) ;
F_15 ( V_14 ) ;
return F_82 ( V_114 ) ;
}
if ( F_70 ( V_21 ) & V_88 )
F_89 ( F_50 ( V_14 ) , 0 ) ;
else
F_89 ( F_50 ( V_14 ) , 1 ) ;
}
if ( F_64 ( V_14 ) ) {
V_89 = F_90 ( V_14 ) ;
if ( ! V_89 && ! F_44 ( V_14 , V_49 , V_41 -> V_50 ) )
V_41 -> V_45 |= V_51 ;
}
if ( V_114 )
F_35 ( V_114 ) ;
if ( ! V_89 )
F_63 ( V_14 , V_41 ) ;
F_15 ( V_14 ) ;
return V_89 ;
}
static int F_91 ( struct V_52 * V_53 , struct V_40 * V_41 , T_2 V_54 )
{
if ( V_41 -> V_45 & V_82 )
return F_85 ( V_41 ) ;
return F_87 ( V_41 ) ;
}
static int F_92 ( struct V_52 * V_53 , struct V_40 * V_41 , T_2 V_54 )
{
struct V_17 * V_14 ;
V_14 = F_76 ( V_41 ) ;
if ( ! V_14 )
return - V_47 ;
F_63 ( V_14 , V_41 ) ;
F_15 ( V_14 ) ;
return 0 ;
}
static void F_93 ( struct V_28 * V_29 ,
struct V_40 * V_41 , T_2 V_54 )
{
unsigned int V_3 , V_115 ;
struct V_116 * V_117 ;
char * V_118 , * V_119 ;
T_4 type ;
T_2 V_120 , V_59 , V_121 = 0 ;
unsigned V_122 = 0 ;
V_119 = V_118 = F_48 ( V_41 , V_54 , & V_59 ) ;
if ( V_41 -> V_45 & V_123 )
type = V_124 ;
else
type = V_125 ;
V_115 = F_69 ( V_29 ) ;
for ( V_3 = 0 ; V_3 < V_115 ; V_3 ++ ) {
struct V_126 * V_127 = F_94 ( V_29 , V_3 ) ;
T_2 V_128 ;
V_120 = V_59 - ( V_119 - V_118 ) ;
if ( V_120 <= sizeof( struct V_116 ) ) {
V_41 -> V_45 |= V_67 ;
break;
}
V_117 = (struct V_116 * ) V_119 ;
V_117 -> V_129 = 0 ;
V_117 -> V_130 = V_127 -> V_131 ;
V_117 -> V_132 = V_127 -> V_59 ;
strncpy ( V_117 -> V_70 , V_127 -> type -> V_13 ,
sizeof( V_117 -> V_70 ) ) ;
V_119 += sizeof( struct V_116 ) ;
V_120 = V_59 - ( V_119 - V_118 ) ;
if ( V_120 <= 0 ) {
V_41 -> V_45 |= V_67 ;
break;
}
if ( V_127 -> type -> V_129 ) {
if ( V_41 -> V_45 & V_112 )
V_122 |= V_133 ;
V_127 -> type -> V_129 ( V_127 , type , V_122 , V_119 , V_120 ) ;
} else
V_119 [ 0 ] = '\0' ;
V_128 = strlen ( V_119 ) + 1 ;
if ( V_128 == V_120 ) {
V_41 -> V_45 |= V_67 ;
break;
}
V_119 += V_128 ;
V_121 = V_41 -> V_60 + ( V_119 - V_118 ) ;
V_119 = F_47 ( V_119 ) ;
V_117 -> V_69 = V_119 - V_118 ;
}
if ( V_121 )
V_41 -> V_56 = V_121 ;
V_41 -> V_87 = V_115 ;
}
static int F_95 ( struct V_52 * V_53 , struct V_40 * V_41 , T_2 V_54 )
{
int V_89 = 0 ;
struct V_17 * V_14 ;
struct V_28 * V_29 ;
int V_30 ;
V_14 = F_76 ( V_41 ) ;
if ( ! V_14 )
return - V_47 ;
if ( F_96 ( V_14 , V_41 -> V_50 ) ) {
V_89 = - V_134 ;
goto V_68;
}
F_63 ( V_14 , V_41 ) ;
V_29 = F_62 ( V_14 , V_41 , & V_30 ) ;
if ( V_29 )
F_93 ( V_29 , V_41 , V_54 ) ;
F_32 ( V_14 , V_30 ) ;
V_68:
F_15 ( V_14 ) ;
return V_89 ;
}
static int F_97 ( struct V_52 * V_53 , struct V_40 * V_41 , T_2 V_54 )
{
struct V_135 * V_136 = V_53 -> V_137 ;
V_136 -> V_138 = F_98 ( & V_139 ) ;
return 0 ;
}
static inline T_5 F_99 ( struct V_40 * V_41 )
{
T_5 V_140 = V_141 | V_88 ;
if ( V_41 -> V_45 & V_83 )
V_140 = V_141 ;
return V_140 ;
}
static int F_100 ( struct V_116 * V_142 , T_3 V_69 , void * V_78 ,
struct V_116 * * V_117 , char * * V_143 )
{
* V_117 = (struct V_116 * ) ( ( unsigned char * ) V_142 + V_69 ) ;
* V_143 = ( char * ) ( * V_117 + 1 ) ;
if ( * V_117 < ( V_142 + 1 ) )
return - V_48 ;
return F_79 ( * V_143 , V_78 ) ;
}
static int F_101 ( struct V_28 * V_29 ,
struct V_40 * V_41 , T_2 V_54 )
{
int V_89 ;
unsigned int V_3 = 0 ;
struct V_116 * V_117 = (struct V_116 * ) V_41 ;
T_3 V_69 = V_41 -> V_60 ;
void * V_78 = ( void * ) V_41 + V_54 ;
char * V_143 ;
if ( ! V_41 -> V_87 ) {
F_39 ( L_20 ) ;
return - V_48 ;
}
for ( V_3 = 0 ; V_3 < V_41 -> V_87 ; V_3 ++ ) {
V_89 = F_100 ( V_117 , V_69 , V_78 , & V_117 , & V_143 ) ;
if ( V_89 ) {
F_39 ( L_21 ) ;
return V_89 ;
}
V_89 = F_102 ( V_29 , V_117 -> V_70 ,
( V_144 ) V_117 -> V_130 ,
( V_144 ) V_117 -> V_132 ,
V_143 ) ;
if ( V_89 ) {
F_39 ( L_22 ) ;
return V_89 ;
}
V_69 = V_117 -> V_69 ;
}
return F_103 ( V_29 ) ;
}
static bool F_104 ( enum V_145 V_146 , enum V_145 V_42 )
{
if ( V_146 == V_42 ||
( V_146 == V_147 && V_42 == V_148 ) )
return true ;
return false ;
}
static int F_105 ( struct V_52 * V_53 , struct V_40 * V_41 , T_2 V_54 )
{
int V_89 ;
struct V_11 * V_12 ;
struct V_28 * V_35 , * V_114 = NULL ;
struct V_17 * V_14 ;
struct V_70 * V_149 ;
V_14 = F_76 ( V_41 ) ;
if ( ! V_14 )
return - V_47 ;
V_89 = F_106 ( & V_35 , F_99 ( V_41 ) , V_41 -> V_87 , V_14 ) ;
if ( V_89 )
goto V_150;
F_107 ( V_14 ) ;
V_89 = F_101 ( V_35 , V_41 , V_54 ) ;
if ( V_89 )
goto V_151;
V_149 = F_108 ( V_14 ) ;
if ( V_149 &&
( V_149 != F_109 ( V_35 ) ) &&
! F_110 ( V_35 ) ) {
F_39 ( L_23 ,
V_149 -> V_13 ) ;
V_89 = - V_48 ;
goto V_151;
}
if ( F_111 ( V_14 ) == V_152 ) {
F_112 ( V_14 , F_113 ( V_35 ) ) ;
V_89 = F_114 ( V_14 , V_35 ) ;
if ( V_89 ) {
F_39 ( L_24 ) ;
goto V_151;
}
} else if ( ! F_104 ( F_111 ( V_14 ) , F_113 ( V_35 ) ) ) {
F_39 ( L_25 ) ;
V_89 = - V_48 ;
goto V_151;
}
F_115 ( V_14 ) ;
F_22 ( & V_24 ) ;
V_12 = F_14 ( V_14 ) ;
if ( ! V_12 || V_12 -> V_14 != V_14 ) {
F_39 ( L_12 ) ;
F_28 ( & V_24 ) ;
V_89 = - V_47 ;
goto V_153;
}
if ( V_12 -> V_21 )
V_114 = V_12 -> V_21 ;
V_12 -> V_21 = V_35 ;
F_28 ( & V_24 ) ;
V_41 -> V_45 |= V_93 ;
F_63 ( V_14 , V_41 ) ;
if ( V_114 ) {
F_34 ( V_14 ) ;
F_35 ( V_114 ) ;
}
F_15 ( V_14 ) ;
return 0 ;
V_151:
F_115 ( V_14 ) ;
V_153:
F_35 ( V_35 ) ;
V_150:
F_15 ( V_14 ) ;
return V_89 ;
}
static int F_116 ( struct V_52 * V_53 , struct V_40 * V_41 , T_2 V_54 )
{
struct V_11 * V_12 ;
struct V_17 * V_14 ;
struct V_28 * V_114 = NULL ;
F_22 ( & V_24 ) ;
V_12 = F_74 ( V_41 ) ;
if ( ! V_12 ) {
F_78 ( L_13 ) ;
F_28 ( & V_24 ) ;
return - V_47 ;
}
if ( V_12 -> V_21 ) {
V_114 = V_12 -> V_21 ;
V_12 -> V_21 = NULL ;
}
V_41 -> V_45 &= ~ V_93 ;
F_63 ( V_12 -> V_14 , V_41 ) ;
V_14 = V_12 -> V_14 ;
F_28 ( & V_24 ) ;
if ( V_114 ) {
F_34 ( V_14 ) ;
F_35 ( V_114 ) ;
}
F_15 ( V_14 ) ;
return 0 ;
}
static void F_117 ( struct V_28 * V_29 ,
struct V_40 * V_41 , T_2 V_54 )
{
unsigned int V_154 = 0 ;
struct V_1 * V_155 ;
T_2 V_59 , V_61 ;
struct V_156 * V_157 ;
struct V_158 * V_159 ;
V_159 = F_48 ( V_41 , V_54 , & V_59 ) ;
F_118 (tmp, dm_table_get_devices(table))
V_154 ++ ;
V_61 = sizeof( * V_159 ) + ( sizeof( * V_159 -> V_16 ) * V_154 ) ;
if ( V_59 < V_61 ) {
V_41 -> V_45 |= V_67 ;
return;
}
V_159 -> V_154 = V_154 ;
V_154 = 0 ;
F_8 (dd, dm_table_get_devices(table), list)
V_159 -> V_16 [ V_154 ++ ] = F_51 ( V_157 -> V_160 -> V_161 -> V_162 ) ;
V_41 -> V_56 = V_41 -> V_60 + V_61 ;
}
static int F_119 ( struct V_52 * V_53 , struct V_40 * V_41 , T_2 V_54 )
{
struct V_17 * V_14 ;
struct V_28 * V_29 ;
int V_30 ;
V_14 = F_76 ( V_41 ) ;
if ( ! V_14 )
return - V_47 ;
F_63 ( V_14 , V_41 ) ;
V_29 = F_62 ( V_14 , V_41 , & V_30 ) ;
if ( V_29 )
F_117 ( V_29 , V_41 , V_54 ) ;
F_32 ( V_14 , V_30 ) ;
F_15 ( V_14 ) ;
return 0 ;
}
static int F_120 ( struct V_52 * V_53 , struct V_40 * V_41 , T_2 V_54 )
{
struct V_17 * V_14 ;
struct V_28 * V_29 ;
int V_30 ;
V_14 = F_76 ( V_41 ) ;
if ( ! V_14 )
return - V_47 ;
F_63 ( V_14 , V_41 ) ;
V_29 = F_62 ( V_14 , V_41 , & V_30 ) ;
if ( V_29 )
F_93 ( V_29 , V_41 , V_54 ) ;
F_32 ( V_14 , V_30 ) ;
F_15 ( V_14 ) ;
return 0 ;
}
static int F_121 ( struct V_17 * V_14 , unsigned V_163 , char * * V_164 ,
char * V_165 , unsigned V_166 )
{
int V_89 ;
if ( * * V_164 != '@' )
return 2 ;
if ( ! strcasecmp ( V_164 [ 0 ] , L_26 ) ) {
if ( V_163 != 1 ) {
F_122 ( L_27 ) ;
return - V_48 ;
}
return F_123 ( V_14 ) ;
}
V_89 = F_124 ( V_14 , V_163 , V_164 , V_165 , V_166 ) ;
if ( V_89 < 2 )
return V_89 ;
F_122 ( L_28 , V_164 [ 0 ] ) ;
return - V_48 ;
}
static int F_125 ( struct V_52 * V_53 , struct V_40 * V_41 , T_2 V_54 )
{
int V_89 , V_163 ;
char * * V_164 ;
struct V_17 * V_14 ;
struct V_28 * V_29 ;
struct V_126 * V_127 ;
struct V_167 * V_168 = ( void * ) V_41 + V_41 -> V_60 ;
T_2 V_166 ;
char * V_165 = F_48 ( V_41 , V_54 , & V_166 ) ;
int V_30 ;
V_14 = F_76 ( V_41 ) ;
if ( ! V_14 )
return - V_47 ;
if ( V_168 < (struct V_167 * ) V_41 -> V_95 ||
F_79 ( V_168 -> V_169 , ( void * ) V_41 + V_54 ) ) {
F_39 ( L_29 ) ;
V_89 = - V_48 ;
goto V_68;
}
V_89 = F_126 ( & V_163 , & V_164 , V_168 -> V_169 ) ;
if ( V_89 ) {
F_39 ( L_30 ) ;
goto V_68;
}
if ( ! V_163 ) {
F_39 ( L_31 ) ;
goto V_170;
}
V_89 = F_121 ( V_14 , V_163 , V_164 , V_165 , V_166 ) ;
if ( V_89 <= 1 )
goto V_170;
V_29 = F_30 ( V_14 , & V_30 ) ;
if ( ! V_29 )
goto V_171;
if ( F_127 ( V_14 ) ) {
V_89 = - V_47 ;
goto V_171;
}
V_127 = F_128 ( V_29 , V_168 -> V_172 ) ;
if ( ! F_129 ( V_127 ) ) {
F_39 ( L_32 ) ;
V_89 = - V_48 ;
} else if ( V_127 -> type -> V_169 )
V_89 = V_127 -> type -> V_169 ( V_127 , V_163 , V_164 ) ;
else {
F_39 ( L_33 ) ;
V_89 = - V_48 ;
}
V_171:
F_32 ( V_14 , V_30 ) ;
V_170:
F_19 ( V_164 ) ;
V_68:
if ( V_89 >= 0 )
F_63 ( V_14 , V_41 ) ;
if ( V_89 == 1 ) {
V_41 -> V_45 |= V_173 ;
if ( F_130 ( V_165 , V_166 ) )
V_41 -> V_45 |= V_67 ;
else
V_41 -> V_56 = V_41 -> V_60 + strlen ( V_165 ) + 1 ;
V_89 = 0 ;
}
F_15 ( V_14 ) ;
return V_89 ;
}
static T_6 F_131 ( unsigned int V_174 , int * V_175 )
{
static struct {
int V_174 ;
int V_45 ;
T_6 V_176 ;
} V_177 [] = {
{ V_178 , 0 , NULL } ,
{ V_179 , V_180 , F_46 } ,
{ V_181 , 0 , F_49 } ,
{ V_182 , V_180 , F_71 } ,
{ V_183 , V_180 , F_77 } ,
{ V_184 , 0 , F_80 } ,
{ V_185 , V_180 , F_91 } ,
{ V_186 , V_180 , F_92 } ,
{ V_187 , 0 , F_95 } ,
{ V_188 , 0 , F_105 } ,
{ V_189 , V_180 , F_116 } ,
{ V_190 , 0 , F_119 } ,
{ V_191 , 0 , F_120 } ,
{ V_192 , 0 , F_56 } ,
{ V_193 , 0 , F_125 } ,
{ V_194 , 0 , F_83 } ,
{ V_195 , V_180 , F_97 } ,
} ;
if ( F_132 ( V_174 >= F_133 ( V_177 ) ) )
return NULL ;
* V_175 = V_177 [ V_174 ] . V_45 ;
return V_177 [ V_174 ] . V_176 ;
}
static int F_134 ( unsigned int V_174 , struct V_40 T_7 * V_196 )
{
T_3 V_77 [ 3 ] ;
int V_89 = 0 ;
if ( F_135 ( V_77 , V_196 -> V_77 , sizeof( V_77 ) ) )
return - V_197 ;
if ( ( V_198 != V_77 [ 0 ] ) ||
( V_199 < V_77 [ 1 ] ) ) {
F_39 ( L_34
L_35 ,
V_198 , V_199 ,
V_200 ,
V_77 [ 0 ] , V_77 [ 1 ] , V_77 [ 2 ] , V_174 ) ;
V_89 = - V_48 ;
}
V_77 [ 0 ] = V_198 ;
V_77 [ 1 ] = V_199 ;
V_77 [ 2 ] = V_200 ;
if ( F_136 ( V_196 -> V_77 , V_77 , sizeof( V_77 ) ) )
return - V_197 ;
return V_89 ;
}
static void F_137 ( struct V_40 * V_41 , T_2 V_54 , int V_201 )
{
if ( V_201 & V_202 )
memset ( V_41 , 0 , V_54 ) ;
if ( V_201 & V_203 )
F_138 ( V_41 ) ;
}
static int F_139 ( struct V_40 T_7 * V_196 , struct V_40 * V_204 ,
int V_175 ,
struct V_40 * * V_41 , int * V_201 )
{
struct V_40 * V_205 ;
int V_206 ;
const T_2 V_207 = F_140 ( struct V_40 , V_95 ) ;
unsigned V_208 ;
if ( F_135 ( V_204 , V_196 , V_207 ) )
return - V_197 ;
if ( V_204 -> V_56 < V_207 )
return - V_48 ;
V_206 = V_204 -> V_45 & V_209 ;
* V_201 = V_206 ? V_202 : 0 ;
if ( V_175 & V_180 ) {
V_205 = V_204 ;
V_205 -> V_56 = V_207 ;
goto V_210;
}
V_205 = NULL ;
V_208 = F_141 () ;
V_205 = F_142 ( V_204 -> V_56 , V_18 | V_211 ) ;
F_143 ( V_208 ) ;
if ( ! V_205 ) {
if ( V_206 && F_144 ( V_196 , V_204 -> V_56 ) )
return - V_197 ;
return - V_23 ;
}
* V_201 |= V_203 ;
if ( F_135 ( V_205 , V_196 , V_204 -> V_56 ) )
goto V_25;
V_210:
if ( V_205 -> V_56 != V_204 -> V_56 ) {
F_122 ( L_36 ) ;
goto V_25;
}
if ( V_206 && F_144 ( V_196 , V_204 -> V_56 ) )
goto V_25;
* V_41 = V_205 ;
return 0 ;
V_25:
F_137 ( V_205 , V_204 -> V_56 , * V_201 ) ;
return - V_197 ;
}
static int F_145 ( T_8 V_174 , struct V_40 * V_41 )
{
V_41 -> V_45 &= ~ V_67 ;
V_41 -> V_45 &= ~ V_51 ;
V_41 -> V_45 &= ~ V_209 ;
V_41 -> V_45 &= ~ V_173 ;
if ( V_174 == V_179 ||
V_174 == V_181 ||
V_174 == V_192 )
return 0 ;
if ( V_174 == V_182 ) {
if ( ! * V_41 -> V_13 ) {
F_39 ( L_37 ) ;
return - V_48 ;
}
} else if ( * V_41 -> V_15 && * V_41 -> V_13 ) {
F_39 ( L_38 , V_174 ) ;
return - V_48 ;
}
V_41 -> V_13 [ V_97 - 1 ] = '\0' ;
V_41 -> V_15 [ V_96 - 1 ] = '\0' ;
return 0 ;
}
static int F_146 ( struct V_52 * V_52 , T_8 V_212 , struct V_40 T_7 * V_196 )
{
int V_89 = 0 ;
int V_175 ;
int V_201 ;
unsigned int V_174 ;
struct V_40 * V_213 ( V_41 ) ;
T_6 V_176 = NULL ;
T_2 V_214 ;
struct V_40 V_204 ;
if ( ! F_147 ( V_215 ) )
return - V_216 ;
if ( F_148 ( V_212 ) != V_217 )
return - V_218 ;
V_174 = F_149 ( V_212 ) ;
V_89 = F_134 ( V_174 , V_196 ) ;
if ( V_89 )
return V_89 ;
if ( V_174 == V_178 )
return 0 ;
V_176 = F_131 ( V_174 , & V_175 ) ;
if ( ! V_176 ) {
F_39 ( L_39 , V_212 ) ;
return - V_218 ;
}
V_89 = F_139 ( V_196 , & V_204 , V_175 , & V_41 , & V_201 ) ;
if ( V_89 )
return V_89 ;
V_214 = V_41 -> V_56 ;
V_89 = F_145 ( V_174 , V_41 ) ;
if ( V_89 )
goto V_68;
V_41 -> V_56 = F_140 ( struct V_40 , V_95 ) ;
V_89 = V_176 ( V_52 , V_41 , V_214 ) ;
if ( F_132 ( V_41 -> V_45 & V_67 ) &&
F_132 ( V_175 & V_180 ) )
F_122 ( L_40 , V_174 ) ;
if ( ! V_89 && F_136 ( V_196 , V_41 , V_41 -> V_56 ) )
V_89 = - V_197 ;
V_68:
F_137 ( V_41 , V_214 , V_201 ) ;
return V_89 ;
}
static long F_150 ( struct V_52 * V_52 , T_8 V_212 , T_9 V_219 )
{
return ( long ) F_146 ( V_52 , V_212 , (struct V_40 T_7 * ) V_219 ) ;
}
static long F_151 ( struct V_52 * V_52 , T_8 V_212 , T_9 V_219 )
{
return ( long ) F_150 ( V_52 , V_212 , ( T_9 ) F_152 ( V_219 ) ) ;
}
static int F_153 ( struct V_220 * V_220 , struct V_52 * V_53 )
{
int V_89 ;
struct V_135 * V_136 ;
V_89 = F_154 ( V_220 , V_53 ) ;
if ( F_132 ( V_89 ) )
return V_89 ;
V_136 = V_53 -> V_137 = F_17 ( sizeof( struct V_135 ) , V_18 ) ;
if ( ! V_136 )
return - V_23 ;
V_136 -> V_138 = F_98 ( & V_139 ) ;
return 0 ;
}
static int F_155 ( struct V_220 * V_220 , struct V_52 * V_53 )
{
F_19 ( V_53 -> V_137 ) ;
return 0 ;
}
static unsigned F_156 ( struct V_52 * V_53 , T_10 * V_221 )
{
struct V_135 * V_136 = V_53 -> V_137 ;
unsigned V_222 = 0 ;
F_157 ( V_53 , & V_223 , V_221 ) ;
if ( ( int ) ( F_98 ( & V_139 ) - V_136 -> V_138 ) > 0 )
V_222 |= V_224 ;
return V_222 ;
}
int T_11 F_158 ( void )
{
int V_89 ;
V_89 = F_3 () ;
if ( V_89 )
return V_89 ;
V_89 = F_159 ( & V_225 ) ;
if ( V_89 ) {
F_122 ( L_41 ) ;
F_4 () ;
return V_89 ;
}
F_160 ( L_42 , V_198 ,
V_199 , V_200 , V_226 ,
V_227 ) ;
return 0 ;
}
void F_161 ( void )
{
F_162 ( & V_225 ) ;
F_4 () ;
}
int F_163 ( struct V_17 * V_14 , char * V_13 , char * V_15 )
{
int V_89 = 0 ;
struct V_11 * V_12 ;
if ( ! V_14 )
return - V_47 ;
F_25 ( & V_26 ) ;
V_12 = F_14 ( V_14 ) ;
if ( ! V_12 || V_12 -> V_14 != V_14 ) {
V_89 = - V_47 ;
goto V_68;
}
if ( V_13 )
strcpy ( V_13 , V_12 -> V_13 ) ;
if ( V_15 )
strcpy ( V_15 , V_12 -> V_15 ? : L_8 ) ;
V_68:
F_27 ( & V_26 ) ;
return V_89 ;
}
