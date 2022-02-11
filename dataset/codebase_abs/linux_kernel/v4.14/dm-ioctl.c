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
static inline T_2 F_47 ( T_2 V_57 )
{
return ( V_57 + V_58 ) & ~ V_58 ;
}
static inline void * F_48 ( void * V_59 )
{
return ( void * ) F_47 ( ( T_2 ) V_59 ) ;
}
static void * F_49 ( struct V_40 * V_41 , T_2 V_54 ,
T_2 * V_60 )
{
V_41 -> V_61 = F_48 ( V_41 + 1 ) - ( void * ) V_41 ;
if ( V_41 -> V_61 < V_54 )
* V_60 = V_54 - V_41 -> V_61 ;
else
* V_60 = 0 ;
return ( ( void * ) V_41 ) + V_41 -> V_61 ;
}
static int F_50 ( struct V_52 * V_53 , struct V_40 * V_41 , T_2 V_54 )
{
unsigned int V_3 ;
struct V_11 * V_12 ;
T_2 V_60 , V_62 = 0 ;
struct V_63 * V_64 ;
struct V_65 * V_66 , * V_67 , * V_68 = NULL ;
T_3 * V_50 ;
F_22 ( & V_24 ) ;
for ( V_3 = 0 ; V_3 < V_4 ; V_3 ++ ) {
F_8 (hc, _name_buckets + i, name_list) {
V_62 += F_47 ( F_51 ( struct V_65 , V_13 ) + strlen ( V_12 -> V_13 ) + 1 ) ;
V_62 += F_47 ( sizeof( T_3 ) ) ;
}
}
V_67 = V_66 = F_49 ( V_41 , V_54 , & V_60 ) ;
if ( V_60 < V_62 ) {
V_41 -> V_45 |= V_69 ;
goto V_70;
}
V_41 -> V_56 = V_41 -> V_61 + V_62 ;
V_67 -> V_16 = 0 ;
for ( V_3 = 0 ; V_3 < V_4 ; V_3 ++ ) {
F_8 (hc, _name_buckets + i, name_list) {
if ( V_68 )
V_68 -> V_71 = ( T_3 ) ( ( void * ) V_67 -
( void * ) V_68 ) ;
V_64 = F_52 ( V_12 -> V_14 ) ;
V_67 -> V_16 = F_53 ( F_54 ( V_64 ) ) ;
V_67 -> V_71 = 0 ;
strcpy ( V_67 -> V_13 , V_12 -> V_13 ) ;
V_68 = V_67 ;
V_50 = F_48 ( V_67 -> V_13 + strlen ( V_12 -> V_13 ) + 1 ) ;
* V_50 = F_55 ( V_12 -> V_14 ) ;
V_67 = F_48 ( V_50 + 1 ) ;
}
}
F_56 ( ( char * ) V_67 - ( char * ) V_66 != V_62 ) ;
V_70:
F_28 ( & V_24 ) ;
return 0 ;
}
static void F_57 ( struct V_72 * V_73 , void * V_74 )
{
T_2 * V_62 = V_74 ;
* V_62 += sizeof( struct V_75 ) ;
* V_62 += strlen ( V_73 -> V_13 ) ;
* V_62 += V_58 ;
}
static void F_58 ( struct V_72 * V_73 , void * V_41 )
{
struct V_76 * V_77 = V_41 ;
if ( ( char * ) V_77 -> V_78 + sizeof( V_73 -> V_79 ) + strlen ( V_73 -> V_13 ) + 1 >
V_77 -> V_80 ) {
V_77 -> V_45 = V_69 ;
return;
}
if ( V_77 -> V_81 )
V_77 -> V_81 -> V_71 = ( T_3 ) ( ( void * ) V_77 -> V_78 -
( void * ) V_77 -> V_81 ) ;
V_77 -> V_78 -> V_79 [ 0 ] = V_73 -> V_79 [ 0 ] ;
V_77 -> V_78 -> V_79 [ 1 ] = V_73 -> V_79 [ 1 ] ;
V_77 -> V_78 -> V_79 [ 2 ] = V_73 -> V_79 [ 2 ] ;
V_77 -> V_78 -> V_71 = 0 ;
strcpy ( V_77 -> V_78 -> V_13 , V_73 -> V_13 ) ;
V_77 -> V_81 = V_77 -> V_78 ;
V_77 -> V_78 = F_48 ( ( ( void * ) ++ V_77 -> V_78 ) + strlen ( V_73 -> V_13 ) + 1 ) ;
}
static int F_59 ( struct V_52 * V_53 , struct V_40 * V_41 , T_2 V_54 )
{
T_2 V_60 , V_62 = 0 ;
struct V_75 * V_78 ;
struct V_76 V_82 ;
F_60 ( F_57 , & V_62 ) ;
V_78 = F_49 ( V_41 , V_54 , & V_60 ) ;
if ( V_60 < V_62 ) {
V_41 -> V_45 |= V_69 ;
goto V_70;
}
V_41 -> V_56 = V_41 -> V_61 + V_62 ;
V_82 . V_54 = V_54 ;
V_82 . V_81 = NULL ;
V_82 . V_78 = V_78 ;
V_82 . V_45 = 0 ;
V_82 . V_80 = ( char * ) V_78 + V_60 ;
F_60 ( F_58 , & V_82 ) ;
V_41 -> V_45 |= V_82 . V_45 ;
V_70:
return 0 ;
}
static int F_61 ( const char * V_13 )
{
if ( strchr ( V_13 , '/' ) ) {
F_39 ( L_11 ) ;
return - V_48 ;
}
return 0 ;
}
static struct V_28 * F_62 ( struct V_17 * V_14 , int * V_30 )
{
struct V_11 * V_12 ;
struct V_28 * V_29 = NULL ;
F_30 ( V_14 , V_30 ) ;
F_63 ( & V_24 ) ;
V_12 = F_14 ( V_14 ) ;
if ( ! V_12 || V_12 -> V_14 != V_14 ) {
F_39 ( L_12 ) ;
goto V_70;
}
V_29 = V_12 -> V_21 ;
V_70:
F_64 ( & V_24 ) ;
return V_29 ;
}
static struct V_28 * F_65 ( struct V_17 * V_14 ,
struct V_40 * V_41 ,
int * V_30 )
{
return ( V_41 -> V_45 & V_83 ) ?
F_62 ( V_14 , V_30 ) : F_30 ( V_14 , V_30 ) ;
}
static void F_66 ( struct V_17 * V_14 , struct V_40 * V_41 )
{
struct V_63 * V_64 = F_52 ( V_14 ) ;
struct V_28 * V_29 ;
int V_30 ;
V_41 -> V_45 &= ~ ( V_84 | V_85 |
V_86 | V_87 ) ;
if ( F_67 ( V_14 ) )
V_41 -> V_45 |= V_84 ;
if ( F_68 ( V_14 ) )
V_41 -> V_45 |= V_87 ;
if ( F_69 ( V_14 ) )
V_41 -> V_45 |= V_55 ;
V_41 -> V_16 = F_53 ( F_54 ( V_64 ) ) ;
V_41 -> V_88 = F_70 ( V_14 ) ;
V_41 -> V_50 = F_55 ( V_14 ) ;
V_41 -> V_89 = 0 ;
V_29 = F_30 ( V_14 , & V_30 ) ;
if ( V_29 ) {
if ( ! ( V_41 -> V_45 & V_83 ) ) {
if ( F_71 ( V_64 ) )
V_41 -> V_45 |= V_85 ;
V_41 -> V_89 = F_72 ( V_29 ) ;
}
V_41 -> V_45 |= V_86 ;
}
F_32 ( V_14 , V_30 ) ;
if ( V_41 -> V_45 & V_83 ) {
int V_30 ;
V_29 = F_62 ( V_14 , & V_30 ) ;
if ( V_29 ) {
if ( ! ( F_73 ( V_29 ) & V_90 ) )
V_41 -> V_45 |= V_85 ;
V_41 -> V_89 = F_72 ( V_29 ) ;
}
F_32 ( V_14 , V_30 ) ;
}
}
static int F_74 ( struct V_52 * V_53 , struct V_40 * V_41 , T_2 V_54 )
{
int V_91 , V_92 = V_93 ;
struct V_17 * V_14 ;
V_91 = F_61 ( V_41 -> V_13 ) ;
if ( V_91 )
return V_91 ;
if ( V_41 -> V_45 & V_94 )
V_92 = F_75 ( F_13 ( V_41 -> V_16 ) ) ;
V_91 = F_76 ( V_92 , & V_14 ) ;
if ( V_91 )
return V_91 ;
V_91 = F_21 ( V_41 -> V_13 , * V_41 -> V_15 ? V_41 -> V_15 : NULL , V_14 ) ;
if ( V_91 ) {
F_15 ( V_14 ) ;
F_37 ( V_14 ) ;
return V_91 ;
}
V_41 -> V_45 &= ~ V_95 ;
F_66 ( V_14 , V_41 ) ;
F_15 ( V_14 ) ;
return 0 ;
}
static struct V_11 * F_77 ( struct V_40 * V_41 )
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
F_78 ( V_41 -> V_13 , V_12 -> V_13 , sizeof( V_41 -> V_13 ) ) ;
if ( V_12 -> V_15 )
F_78 ( V_41 -> V_15 , V_12 -> V_15 , sizeof( V_41 -> V_15 ) ) ;
else
V_41 -> V_15 [ 0 ] = '\0' ;
if ( V_12 -> V_21 )
V_41 -> V_45 |= V_95 ;
else
V_41 -> V_45 &= ~ V_95 ;
return V_12 ;
}
static struct V_17 * F_79 ( struct V_40 * V_41 )
{
struct V_11 * V_12 ;
struct V_17 * V_14 = NULL ;
F_63 ( & V_24 ) ;
V_12 = F_77 ( V_41 ) ;
if ( V_12 )
V_14 = V_12 -> V_14 ;
F_64 ( & V_24 ) ;
return V_14 ;
}
static int F_80 ( struct V_52 * V_53 , struct V_40 * V_41 , T_2 V_54 )
{
struct V_11 * V_12 ;
struct V_17 * V_14 ;
int V_91 ;
struct V_28 * V_35 ;
F_22 ( & V_24 ) ;
V_12 = F_77 ( V_41 ) ;
if ( ! V_12 ) {
F_81 ( L_13 ) ;
F_28 ( & V_24 ) ;
return - V_47 ;
}
V_14 = V_12 -> V_14 ;
V_91 = F_33 ( V_14 , ! ! ( V_41 -> V_45 & V_55 ) , false ) ;
if ( V_91 ) {
if ( V_91 == - V_27 && V_41 -> V_45 & V_55 ) {
F_28 ( & V_24 ) ;
F_15 ( V_14 ) ;
return 0 ;
}
F_81 ( L_14 , V_12 -> V_13 ) ;
F_28 ( & V_24 ) ;
F_15 ( V_14 ) ;
return V_91 ;
}
V_35 = F_29 ( V_12 ) ;
F_28 ( & V_24 ) ;
if ( V_35 ) {
F_34 ( V_14 ) ;
F_35 ( V_35 ) ;
}
V_41 -> V_45 &= ~ V_55 ;
if ( ! F_44 ( V_14 , V_96 , V_41 -> V_50 ) )
V_41 -> V_45 |= V_51 ;
F_15 ( V_14 ) ;
F_37 ( V_14 ) ;
return 0 ;
}
static int F_82 ( char * V_7 , void * V_80 )
{
while ( ( void * ) V_7 < V_80 )
if ( ! * V_7 ++ )
return 0 ;
return - V_48 ;
}
static int F_83 ( struct V_52 * V_53 , struct V_40 * V_41 , T_2 V_54 )
{
int V_91 ;
char * V_43 = ( char * ) V_41 + V_41 -> V_61 ;
struct V_17 * V_14 ;
unsigned V_44 = ( V_41 -> V_45 & V_46 ) ? 1 : 0 ;
if ( V_43 < V_41 -> V_97 ||
F_82 ( V_43, ( void * ) V_41 + V_54 ) || ! * V_43 ||
strlen ( V_43 ) > ( V_44 ? V_98 - 1 : V_99 - 1 ) ) {
F_39 ( L_15 ) ;
return - V_48 ;
}
if ( ! V_44 ) {
V_91 = F_61 ( V_43 ) ;
if ( V_91 )
return V_91 ;
}
V_14 = F_42 ( V_41 , V_43 ) ;
if ( F_84 ( V_14 ) )
return F_85 ( V_14 ) ;
F_66 ( V_14 , V_41 ) ;
F_15 ( V_14 ) ;
return 0 ;
}
static int F_86 ( struct V_52 * V_53 , struct V_40 * V_41 , T_2 V_54 )
{
int V_91 = - V_48 , V_100 ;
struct V_17 * V_14 ;
struct V_101 V_102 ;
unsigned long V_103 [ 4 ] ;
char * V_104 = ( char * ) V_41 + V_41 -> V_61 ;
char V_105 ;
V_14 = F_79 ( V_41 ) ;
if ( ! V_14 )
return - V_47 ;
if ( V_104 < V_41 -> V_97 ||
F_82 ( V_104 , ( void * ) V_41 + V_54 ) ) {
F_39 ( L_16 ) ;
goto V_70;
}
V_100 = sscanf ( V_104 , L_17 , V_103 ,
V_103 + 1 , V_103 + 2 , V_103 + 3 , & V_105 ) ;
if ( V_100 != 4 ) {
F_39 ( L_18 ) ;
goto V_70;
}
if ( V_103 [ 0 ] > 65535 || V_103 [ 1 ] > 255 ||
V_103 [ 2 ] > 255 || V_103 [ 3 ] > V_106 ) {
F_39 ( L_19 ) ;
goto V_70;
}
V_102 . V_107 = V_103 [ 0 ] ;
V_102 . V_108 = V_103 [ 1 ] ;
V_102 . V_109 = V_103 [ 2 ] ;
V_102 . V_110 = V_103 [ 3 ] ;
V_91 = F_87 ( V_14 , & V_102 ) ;
V_41 -> V_56 = 0 ;
V_70:
F_15 ( V_14 ) ;
return V_91 ;
}
static int F_88 ( struct V_40 * V_41 )
{
int V_91 = 0 ;
unsigned V_111 = V_112 ;
struct V_17 * V_14 ;
V_14 = F_79 ( V_41 ) ;
if ( ! V_14 )
return - V_47 ;
if ( V_41 -> V_45 & V_113 )
V_111 &= ~ V_112 ;
if ( V_41 -> V_45 & V_114 )
V_111 |= V_115 ;
if ( ! F_67 ( V_14 ) ) {
V_91 = F_89 ( V_14 , V_111 ) ;
if ( V_91 )
goto V_70;
}
F_66 ( V_14 , V_41 ) ;
V_70:
F_15 ( V_14 ) ;
return V_91 ;
}
static int F_90 ( struct V_40 * V_41 )
{
int V_91 = 0 ;
unsigned V_111 = V_112 ;
struct V_11 * V_12 ;
struct V_17 * V_14 ;
struct V_28 * V_21 , * V_116 = NULL ;
F_22 ( & V_24 ) ;
V_12 = F_77 ( V_41 ) ;
if ( ! V_12 ) {
F_81 ( L_13 ) ;
F_28 ( & V_24 ) ;
return - V_47 ;
}
V_14 = V_12 -> V_14 ;
V_21 = V_12 -> V_21 ;
V_12 -> V_21 = NULL ;
V_41 -> V_45 &= ~ V_95 ;
F_28 ( & V_24 ) ;
if ( V_21 ) {
if ( V_41 -> V_45 & V_113 )
V_111 &= ~ V_112 ;
if ( V_41 -> V_45 & V_114 )
V_111 |= V_115 ;
if ( ! F_67 ( V_14 ) )
F_89 ( V_14 , V_111 ) ;
V_116 = F_91 ( V_14 , V_21 ) ;
if ( F_84 ( V_116 ) ) {
F_34 ( V_14 ) ;
F_35 ( V_21 ) ;
F_15 ( V_14 ) ;
return F_85 ( V_116 ) ;
}
if ( F_73 ( V_21 ) & V_90 )
F_92 ( F_52 ( V_14 ) , 0 ) ;
else
F_92 ( F_52 ( V_14 ) , 1 ) ;
}
if ( F_67 ( V_14 ) ) {
V_91 = F_93 ( V_14 ) ;
if ( ! V_91 && ! F_44 ( V_14 , V_49 , V_41 -> V_50 ) )
V_41 -> V_45 |= V_51 ;
}
if ( V_116 )
F_35 ( V_116 ) ;
if ( ! V_91 )
F_66 ( V_14 , V_41 ) ;
F_15 ( V_14 ) ;
return V_91 ;
}
static int F_94 ( struct V_52 * V_53 , struct V_40 * V_41 , T_2 V_54 )
{
if ( V_41 -> V_45 & V_84 )
return F_88 ( V_41 ) ;
return F_90 ( V_41 ) ;
}
static int F_95 ( struct V_52 * V_53 , struct V_40 * V_41 , T_2 V_54 )
{
struct V_17 * V_14 ;
V_14 = F_79 ( V_41 ) ;
if ( ! V_14 )
return - V_47 ;
F_66 ( V_14 , V_41 ) ;
F_15 ( V_14 ) ;
return 0 ;
}
static void F_96 ( struct V_28 * V_29 ,
struct V_40 * V_41 , T_2 V_54 )
{
unsigned int V_3 , V_117 ;
struct V_118 * V_119 ;
char * V_120 , * V_121 ;
T_4 type ;
T_2 V_122 , V_60 , V_123 = 0 ;
unsigned V_124 = 0 ;
V_121 = V_120 = F_49 ( V_41 , V_54 , & V_60 ) ;
if ( V_41 -> V_45 & V_125 )
type = V_126 ;
else
type = V_127 ;
V_117 = F_72 ( V_29 ) ;
for ( V_3 = 0 ; V_3 < V_117 ; V_3 ++ ) {
struct V_128 * V_129 = F_97 ( V_29 , V_3 ) ;
T_2 V_130 ;
V_122 = V_60 - ( V_121 - V_120 ) ;
if ( V_122 <= sizeof( struct V_118 ) ) {
V_41 -> V_45 |= V_69 ;
break;
}
V_119 = (struct V_118 * ) V_121 ;
V_119 -> V_131 = 0 ;
V_119 -> V_132 = V_129 -> V_133 ;
V_119 -> V_134 = V_129 -> V_60 ;
strncpy ( V_119 -> V_72 , V_129 -> type -> V_13 ,
sizeof( V_119 -> V_72 ) ) ;
V_121 += sizeof( struct V_118 ) ;
V_122 = V_60 - ( V_121 - V_120 ) ;
if ( V_122 <= 0 ) {
V_41 -> V_45 |= V_69 ;
break;
}
if ( V_129 -> type -> V_131 ) {
if ( V_41 -> V_45 & V_114 )
V_124 |= V_135 ;
V_129 -> type -> V_131 ( V_129 , type , V_124 , V_121 , V_122 ) ;
} else
V_121 [ 0 ] = '\0' ;
V_130 = strlen ( V_121 ) + 1 ;
if ( V_130 == V_122 ) {
V_41 -> V_45 |= V_69 ;
break;
}
V_121 += V_130 ;
V_123 = V_41 -> V_61 + ( V_121 - V_120 ) ;
V_121 = F_48 ( V_121 ) ;
V_119 -> V_71 = V_121 - V_120 ;
}
if ( V_123 )
V_41 -> V_56 = V_123 ;
V_41 -> V_89 = V_117 ;
}
static int F_98 ( struct V_52 * V_53 , struct V_40 * V_41 , T_2 V_54 )
{
int V_91 = 0 ;
struct V_17 * V_14 ;
struct V_28 * V_29 ;
int V_30 ;
V_14 = F_79 ( V_41 ) ;
if ( ! V_14 )
return - V_47 ;
if ( F_99 ( V_14 , V_41 -> V_50 ) ) {
V_91 = - V_136 ;
goto V_70;
}
F_66 ( V_14 , V_41 ) ;
V_29 = F_65 ( V_14 , V_41 , & V_30 ) ;
if ( V_29 )
F_96 ( V_29 , V_41 , V_54 ) ;
F_32 ( V_14 , V_30 ) ;
V_70:
F_15 ( V_14 ) ;
return V_91 ;
}
static int F_100 ( struct V_52 * V_53 , struct V_40 * V_41 , T_2 V_54 )
{
struct V_137 * V_138 = V_53 -> V_139 ;
V_138 -> V_140 = F_101 ( & V_141 ) ;
return 0 ;
}
static inline T_5 F_102 ( struct V_40 * V_41 )
{
T_5 V_142 = V_143 | V_90 ;
if ( V_41 -> V_45 & V_85 )
V_142 = V_143 ;
return V_142 ;
}
static int F_103 ( struct V_118 * V_144 , T_3 V_71 , void * V_80 ,
struct V_118 * * V_119 , char * * V_145 )
{
* V_119 = (struct V_118 * ) ( ( unsigned char * ) V_144 + V_71 ) ;
* V_145 = ( char * ) ( * V_119 + 1 ) ;
if ( * V_119 < ( V_144 + 1 ) )
return - V_48 ;
return F_82 ( * V_145 , V_80 ) ;
}
static int F_104 ( struct V_28 * V_29 ,
struct V_40 * V_41 , T_2 V_54 )
{
int V_91 ;
unsigned int V_3 = 0 ;
struct V_118 * V_119 = (struct V_118 * ) V_41 ;
T_3 V_71 = V_41 -> V_61 ;
void * V_80 = ( void * ) V_41 + V_54 ;
char * V_145 ;
if ( ! V_41 -> V_89 ) {
F_39 ( L_20 ) ;
return - V_48 ;
}
for ( V_3 = 0 ; V_3 < V_41 -> V_89 ; V_3 ++ ) {
V_91 = F_103 ( V_119 , V_71 , V_80 , & V_119 , & V_145 ) ;
if ( V_91 ) {
F_39 ( L_21 ) ;
return V_91 ;
}
V_91 = F_105 ( V_29 , V_119 -> V_72 ,
( V_146 ) V_119 -> V_132 ,
( V_146 ) V_119 -> V_134 ,
V_145 ) ;
if ( V_91 ) {
F_39 ( L_22 ) ;
return V_91 ;
}
V_71 = V_119 -> V_71 ;
}
return F_106 ( V_29 ) ;
}
static bool F_107 ( enum V_147 V_148 , enum V_147 V_42 )
{
if ( V_148 == V_42 ||
( V_148 == V_149 && V_42 == V_150 ) )
return true ;
return false ;
}
static int F_108 ( struct V_52 * V_53 , struct V_40 * V_41 , T_2 V_54 )
{
int V_91 ;
struct V_11 * V_12 ;
struct V_28 * V_35 , * V_116 = NULL ;
struct V_17 * V_14 ;
struct V_72 * V_151 ;
V_14 = F_79 ( V_41 ) ;
if ( ! V_14 )
return - V_47 ;
V_91 = F_109 ( & V_35 , F_102 ( V_41 ) , V_41 -> V_89 , V_14 ) ;
if ( V_91 )
goto V_152;
F_110 ( V_14 ) ;
V_91 = F_104 ( V_35 , V_41 , V_54 ) ;
if ( V_91 )
goto V_153;
V_151 = F_111 ( V_14 ) ;
if ( V_151 &&
( V_151 != F_112 ( V_35 ) ) &&
! F_113 ( V_35 ) ) {
F_39 ( L_23 ,
V_151 -> V_13 ) ;
V_91 = - V_48 ;
goto V_153;
}
if ( F_114 ( V_14 ) == V_154 ) {
F_115 ( V_14 , F_116 ( V_35 ) ) ;
V_91 = F_117 ( V_14 , V_35 ) ;
if ( V_91 ) {
F_39 ( L_24 ) ;
goto V_153;
}
} else if ( ! F_107 ( F_114 ( V_14 ) , F_116 ( V_35 ) ) ) {
F_39 ( L_25 ) ;
V_91 = - V_48 ;
goto V_153;
}
F_118 ( V_14 ) ;
F_22 ( & V_24 ) ;
V_12 = F_14 ( V_14 ) ;
if ( ! V_12 || V_12 -> V_14 != V_14 ) {
F_39 ( L_12 ) ;
F_28 ( & V_24 ) ;
V_91 = - V_47 ;
goto V_155;
}
if ( V_12 -> V_21 )
V_116 = V_12 -> V_21 ;
V_12 -> V_21 = V_35 ;
F_28 ( & V_24 ) ;
V_41 -> V_45 |= V_95 ;
F_66 ( V_14 , V_41 ) ;
if ( V_116 ) {
F_34 ( V_14 ) ;
F_35 ( V_116 ) ;
}
F_15 ( V_14 ) ;
return 0 ;
V_153:
F_118 ( V_14 ) ;
V_155:
F_35 ( V_35 ) ;
V_152:
F_15 ( V_14 ) ;
return V_91 ;
}
static int F_119 ( struct V_52 * V_53 , struct V_40 * V_41 , T_2 V_54 )
{
struct V_11 * V_12 ;
struct V_17 * V_14 ;
struct V_28 * V_116 = NULL ;
F_22 ( & V_24 ) ;
V_12 = F_77 ( V_41 ) ;
if ( ! V_12 ) {
F_81 ( L_13 ) ;
F_28 ( & V_24 ) ;
return - V_47 ;
}
if ( V_12 -> V_21 ) {
V_116 = V_12 -> V_21 ;
V_12 -> V_21 = NULL ;
}
V_41 -> V_45 &= ~ V_95 ;
F_66 ( V_12 -> V_14 , V_41 ) ;
V_14 = V_12 -> V_14 ;
F_28 ( & V_24 ) ;
if ( V_116 ) {
F_34 ( V_14 ) ;
F_35 ( V_116 ) ;
}
F_15 ( V_14 ) ;
return 0 ;
}
static void F_120 ( struct V_28 * V_29 ,
struct V_40 * V_41 , T_2 V_54 )
{
unsigned int V_156 = 0 ;
struct V_1 * V_157 ;
T_2 V_60 , V_62 ;
struct V_158 * V_159 ;
struct V_160 * V_161 ;
V_161 = F_49 ( V_41 , V_54 , & V_60 ) ;
F_121 (tmp, dm_table_get_devices(table))
V_156 ++ ;
V_62 = sizeof( * V_161 ) + ( sizeof( * V_161 -> V_16 ) * V_156 ) ;
if ( V_60 < V_62 ) {
V_41 -> V_45 |= V_69 ;
return;
}
V_161 -> V_156 = V_156 ;
V_156 = 0 ;
F_8 (dd, dm_table_get_devices(table), list)
V_161 -> V_16 [ V_156 ++ ] = F_53 ( V_159 -> V_162 -> V_163 -> V_164 ) ;
V_41 -> V_56 = V_41 -> V_61 + V_62 ;
}
static int F_122 ( struct V_52 * V_53 , struct V_40 * V_41 , T_2 V_54 )
{
struct V_17 * V_14 ;
struct V_28 * V_29 ;
int V_30 ;
V_14 = F_79 ( V_41 ) ;
if ( ! V_14 )
return - V_47 ;
F_66 ( V_14 , V_41 ) ;
V_29 = F_65 ( V_14 , V_41 , & V_30 ) ;
if ( V_29 )
F_120 ( V_29 , V_41 , V_54 ) ;
F_32 ( V_14 , V_30 ) ;
F_15 ( V_14 ) ;
return 0 ;
}
static int F_123 ( struct V_52 * V_53 , struct V_40 * V_41 , T_2 V_54 )
{
struct V_17 * V_14 ;
struct V_28 * V_29 ;
int V_30 ;
V_14 = F_79 ( V_41 ) ;
if ( ! V_14 )
return - V_47 ;
F_66 ( V_14 , V_41 ) ;
V_29 = F_65 ( V_14 , V_41 , & V_30 ) ;
if ( V_29 )
F_96 ( V_29 , V_41 , V_54 ) ;
F_32 ( V_14 , V_30 ) ;
F_15 ( V_14 ) ;
return 0 ;
}
static int F_124 ( struct V_17 * V_14 , unsigned V_165 , char * * V_166 ,
char * V_167 , unsigned V_168 )
{
int V_91 ;
if ( * * V_166 != '@' )
return 2 ;
if ( ! strcasecmp ( V_166 [ 0 ] , L_26 ) ) {
if ( V_165 != 1 ) {
F_125 ( L_27 ) ;
return - V_48 ;
}
return F_126 ( V_14 ) ;
}
V_91 = F_127 ( V_14 , V_165 , V_166 , V_167 , V_168 ) ;
if ( V_91 < 2 )
return V_91 ;
F_125 ( L_28 , V_166 [ 0 ] ) ;
return - V_48 ;
}
static int F_128 ( struct V_52 * V_53 , struct V_40 * V_41 , T_2 V_54 )
{
int V_91 , V_165 ;
char * * V_166 ;
struct V_17 * V_14 ;
struct V_28 * V_29 ;
struct V_128 * V_129 ;
struct V_169 * V_170 = ( void * ) V_41 + V_41 -> V_61 ;
T_2 V_168 ;
char * V_167 = F_49 ( V_41 , V_54 , & V_168 ) ;
int V_30 ;
V_14 = F_79 ( V_41 ) ;
if ( ! V_14 )
return - V_47 ;
if ( V_170 < (struct V_169 * ) V_41 -> V_97 ||
F_82 ( V_170 -> V_171 , ( void * ) V_41 + V_54 ) ) {
F_39 ( L_29 ) ;
V_91 = - V_48 ;
goto V_70;
}
V_91 = F_129 ( & V_165 , & V_166 , V_170 -> V_171 ) ;
if ( V_91 ) {
F_39 ( L_30 ) ;
goto V_70;
}
if ( ! V_165 ) {
F_39 ( L_31 ) ;
goto V_172;
}
V_91 = F_124 ( V_14 , V_165 , V_166 , V_167 , V_168 ) ;
if ( V_91 <= 1 )
goto V_172;
V_29 = F_30 ( V_14 , & V_30 ) ;
if ( ! V_29 )
goto V_173;
if ( F_130 ( V_14 ) ) {
V_91 = - V_47 ;
goto V_173;
}
V_129 = F_131 ( V_29 , V_170 -> V_174 ) ;
if ( ! F_132 ( V_129 ) ) {
F_39 ( L_32 ) ;
V_91 = - V_48 ;
} else if ( V_129 -> type -> V_171 )
V_91 = V_129 -> type -> V_171 ( V_129 , V_165 , V_166 ) ;
else {
F_39 ( L_33 ) ;
V_91 = - V_48 ;
}
V_173:
F_32 ( V_14 , V_30 ) ;
V_172:
F_19 ( V_166 ) ;
V_70:
if ( V_91 >= 0 )
F_66 ( V_14 , V_41 ) ;
if ( V_91 == 1 ) {
V_41 -> V_45 |= V_175 ;
if ( F_133 ( V_167 , V_168 ) )
V_41 -> V_45 |= V_69 ;
else
V_41 -> V_56 = V_41 -> V_61 + strlen ( V_167 ) + 1 ;
V_91 = 0 ;
}
F_15 ( V_14 ) ;
return V_91 ;
}
static T_6 F_134 ( unsigned int V_176 , int * V_177 )
{
static const struct {
int V_176 ;
int V_45 ;
T_6 V_178 ;
} V_179 [] = {
{ V_180 , 0 , NULL } ,
{ V_181 , V_182 | V_183 , F_46 } ,
{ V_184 , 0 , F_50 } ,
{ V_185 , V_182 | V_183 , F_74 } ,
{ V_186 , V_182 | V_183 , F_80 } ,
{ V_187 , V_183 , F_83 } ,
{ V_188 , V_182 , F_94 } ,
{ V_189 , V_182 , F_95 } ,
{ V_190 , 0 , F_98 } ,
{ V_191 , 0 , F_108 } ,
{ V_192 , V_182 , F_119 } ,
{ V_193 , 0 , F_122 } ,
{ V_194 , 0 , F_123 } ,
{ V_195 , 0 , F_59 } ,
{ V_196 , 0 , F_128 } ,
{ V_197 , 0 , F_86 } ,
{ V_198 , V_182 , F_100 } ,
} ;
if ( F_135 ( V_176 >= F_136 ( V_179 ) ) )
return NULL ;
* V_177 = V_179 [ V_176 ] . V_45 ;
return V_179 [ V_176 ] . V_178 ;
}
static int F_137 ( unsigned int V_176 , struct V_40 T_7 * V_199 )
{
T_3 V_79 [ 3 ] ;
int V_91 = 0 ;
if ( F_138 ( V_79 , V_199 -> V_79 , sizeof( V_79 ) ) )
return - V_200 ;
if ( ( V_201 != V_79 [ 0 ] ) ||
( V_202 < V_79 [ 1 ] ) ) {
F_39 ( L_34
L_35 ,
V_201 , V_202 ,
V_203 ,
V_79 [ 0 ] , V_79 [ 1 ] , V_79 [ 2 ] , V_176 ) ;
V_91 = - V_48 ;
}
V_79 [ 0 ] = V_201 ;
V_79 [ 1 ] = V_202 ;
V_79 [ 2 ] = V_203 ;
if ( F_139 ( V_199 -> V_79 , V_79 , sizeof( V_79 ) ) )
return - V_200 ;
return V_91 ;
}
static void F_140 ( struct V_40 * V_41 , T_2 V_54 , int V_204 )
{
if ( V_204 & V_205 )
memset ( V_41 , 0 , V_54 ) ;
if ( V_204 & V_206 )
F_141 ( V_41 ) ;
}
static int F_142 ( struct V_40 T_7 * V_199 , struct V_40 * V_207 ,
int V_177 ,
struct V_40 * * V_41 , int * V_204 )
{
struct V_40 * V_208 ;
int V_209 ;
const T_2 V_210 = F_51 ( struct V_40 , V_97 ) ;
unsigned V_211 ;
if ( F_138 ( V_207 , V_199 , V_210 ) )
return - V_200 ;
if ( V_207 -> V_56 < V_210 )
return - V_48 ;
V_209 = V_207 -> V_45 & V_212 ;
* V_204 = V_209 ? V_205 : 0 ;
if ( V_177 & V_182 ) {
V_208 = V_207 ;
V_208 -> V_56 = V_210 ;
goto V_213;
}
V_208 = NULL ;
V_211 = F_143 () ;
V_208 = F_144 ( V_207 -> V_56 , V_18 | V_214 ) ;
F_145 ( V_211 ) ;
if ( ! V_208 ) {
if ( V_209 && F_146 ( V_199 , V_207 -> V_56 ) )
return - V_200 ;
return - V_23 ;
}
* V_204 |= V_206 ;
if ( F_138 ( V_208 , V_199 , V_207 -> V_56 ) )
goto V_25;
V_213:
if ( V_208 -> V_56 != V_207 -> V_56 ) {
F_125 ( L_36 ) ;
goto V_25;
}
if ( V_209 && F_146 ( V_199 , V_207 -> V_56 ) )
goto V_25;
* V_41 = V_208 ;
return 0 ;
V_25:
F_140 ( V_208 , V_207 -> V_56 , * V_204 ) ;
return - V_200 ;
}
static int F_147 ( T_8 V_176 , struct V_40 * V_41 )
{
V_41 -> V_45 &= ~ V_69 ;
V_41 -> V_45 &= ~ V_51 ;
V_41 -> V_45 &= ~ V_212 ;
V_41 -> V_45 &= ~ V_175 ;
if ( V_176 == V_181 ||
V_176 == V_184 ||
V_176 == V_195 )
return 0 ;
if ( V_176 == V_185 ) {
if ( ! * V_41 -> V_13 ) {
F_39 ( L_37 ) ;
return - V_48 ;
}
} else if ( * V_41 -> V_15 && * V_41 -> V_13 ) {
F_39 ( L_38 , V_176 ) ;
return - V_48 ;
}
V_41 -> V_13 [ V_99 - 1 ] = '\0' ;
V_41 -> V_15 [ V_98 - 1 ] = '\0' ;
return 0 ;
}
static int F_148 ( struct V_52 * V_52 , T_8 V_215 , struct V_40 T_7 * V_199 )
{
int V_91 = 0 ;
int V_177 ;
int V_204 ;
unsigned int V_176 ;
struct V_40 * V_216 ( V_41 ) ;
T_6 V_178 = NULL ;
T_2 V_217 ;
struct V_40 V_207 ;
if ( ! F_149 ( V_218 ) )
return - V_219 ;
if ( F_150 ( V_215 ) != V_220 )
return - V_221 ;
V_176 = F_151 ( V_215 ) ;
V_91 = F_137 ( V_176 , V_199 ) ;
if ( V_91 )
return V_91 ;
if ( V_176 == V_180 )
return 0 ;
V_178 = F_134 ( V_176 , & V_177 ) ;
if ( ! V_178 ) {
F_39 ( L_39 , V_215 ) ;
return - V_221 ;
}
V_91 = F_142 ( V_199 , & V_207 , V_177 , & V_41 , & V_204 ) ;
if ( V_91 )
return V_91 ;
V_217 = V_41 -> V_56 ;
V_91 = F_147 ( V_176 , V_41 ) ;
if ( V_91 )
goto V_70;
V_41 -> V_56 = F_51 ( struct V_40 , V_97 ) ;
V_91 = V_178 ( V_52 , V_41 , V_217 ) ;
if ( F_135 ( V_41 -> V_45 & V_69 ) &&
F_135 ( V_177 & V_182 ) )
F_125 ( L_40 , V_176 ) ;
if ( ! V_91 && V_177 & V_183 )
F_152 () ;
if ( ! V_91 && F_139 ( V_199 , V_41 , V_41 -> V_56 ) )
V_91 = - V_200 ;
V_70:
F_140 ( V_41 , V_217 , V_204 ) ;
return V_91 ;
}
static long F_153 ( struct V_52 * V_52 , T_8 V_215 , T_9 V_222 )
{
return ( long ) F_148 ( V_52 , V_215 , (struct V_40 T_7 * ) V_222 ) ;
}
static long F_154 ( struct V_52 * V_52 , T_8 V_215 , T_9 V_222 )
{
return ( long ) F_153 ( V_52 , V_215 , ( T_9 ) F_155 ( V_222 ) ) ;
}
static int F_156 ( struct V_223 * V_223 , struct V_52 * V_53 )
{
int V_91 ;
struct V_137 * V_138 ;
V_91 = F_157 ( V_223 , V_53 ) ;
if ( F_135 ( V_91 ) )
return V_91 ;
V_138 = V_53 -> V_139 = F_17 ( sizeof( struct V_137 ) , V_18 ) ;
if ( ! V_138 )
return - V_23 ;
V_138 -> V_140 = F_101 ( & V_141 ) ;
return 0 ;
}
static int F_158 ( struct V_223 * V_223 , struct V_52 * V_53 )
{
F_19 ( V_53 -> V_139 ) ;
return 0 ;
}
static unsigned F_159 ( struct V_52 * V_53 , T_10 * V_224 )
{
struct V_137 * V_138 = V_53 -> V_139 ;
unsigned V_225 = 0 ;
F_160 ( V_53 , & V_226 , V_224 ) ;
if ( ( int ) ( F_101 ( & V_141 ) - V_138 -> V_140 ) > 0 )
V_225 |= V_227 ;
return V_225 ;
}
int T_11 F_161 ( void )
{
int V_91 ;
V_91 = F_3 () ;
if ( V_91 )
return V_91 ;
V_91 = F_162 ( & V_228 ) ;
if ( V_91 ) {
F_125 ( L_41 ) ;
F_4 () ;
return V_91 ;
}
F_163 ( L_42 , V_201 ,
V_202 , V_203 , V_229 ,
V_230 ) ;
return 0 ;
}
void F_164 ( void )
{
F_165 ( & V_228 ) ;
F_4 () ;
}
int F_166 ( struct V_17 * V_14 , char * V_13 , char * V_15 )
{
int V_91 = 0 ;
struct V_11 * V_12 ;
if ( ! V_14 )
return - V_47 ;
F_25 ( & V_26 ) ;
V_12 = F_14 ( V_14 ) ;
if ( ! V_12 || V_12 -> V_14 != V_14 ) {
V_91 = - V_47 ;
goto V_70;
}
if ( V_13 )
strcpy ( V_13 , V_12 -> V_13 ) ;
if ( V_15 )
strcpy ( V_15 , V_12 -> V_15 ? : L_8 ) ;
V_70:
F_27 ( & V_26 ) ;
return V_91 ;
}
