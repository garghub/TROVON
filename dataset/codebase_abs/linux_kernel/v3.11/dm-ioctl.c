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
F_5 ( 0 ) ;
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
static void F_5 ( int V_31 )
{
int V_3 , V_32 ;
struct V_11 * V_12 ;
struct V_17 * V_14 ;
struct V_28 * V_33 ;
V_34:
V_32 = 0 ;
F_22 ( & V_24 ) ;
for ( V_3 = 0 ; V_3 < V_4 ; V_3 ++ ) {
F_8 (hc, _name_buckets + i, name_list) {
V_14 = V_12 -> V_14 ;
F_9 ( V_14 ) ;
if ( V_31 && F_33 ( V_14 ) ) {
F_15 ( V_14 ) ;
V_32 ++ ;
continue;
}
V_33 = F_29 ( V_12 ) ;
F_28 ( & V_24 ) ;
if ( V_33 ) {
F_34 ( V_14 ) ;
F_35 ( V_33 ) ;
}
F_15 ( V_14 ) ;
if ( F_36 ( V_31 ) )
F_37 ( V_14 ) ;
else
F_38 ( V_14 ) ;
goto V_34;
}
}
F_28 ( & V_24 ) ;
if ( V_32 )
F_39 ( L_1 , V_32 ) ;
}
static void F_40 ( struct V_11 * V_12 , char * V_35 )
{
F_25 ( & V_26 ) ;
V_12 -> V_15 = V_35 ;
F_27 ( & V_26 ) ;
F_23 ( & V_12 -> V_20 , V_6 + F_6 ( V_35 ) ) ;
}
static char * F_41 ( struct V_11 * V_12 , char * V_36 )
{
char * V_37 ;
F_24 ( & V_12 -> V_19 ) ;
V_37 = V_12 -> V_13 ;
F_25 ( & V_26 ) ;
V_12 -> V_13 = V_36 ;
F_27 ( & V_26 ) ;
F_23 ( & V_12 -> V_19 , V_5 + F_6 ( V_36 ) ) ;
return V_37 ;
}
static struct V_17 * F_42 ( struct V_38 * V_39 ,
const char * V_40 )
{
char * V_41 , * V_37 = NULL ;
struct V_11 * V_12 ;
struct V_28 * V_29 ;
struct V_17 * V_14 ;
unsigned V_42 = ( V_39 -> V_43 & V_44 ) ? 1 : 0 ;
int V_30 ;
V_41 = F_18 ( V_40 , V_18 ) ;
if ( ! V_41 )
return F_43 ( - V_23 ) ;
F_22 ( & V_24 ) ;
if ( V_42 )
V_12 = F_10 ( V_40 ) ;
else
V_12 = F_7 ( V_40 ) ;
if ( V_12 ) {
F_39 ( L_2
L_3 ,
V_42 ? L_4 : L_5 ,
V_39 -> V_13 , V_40 ) ;
F_15 ( V_12 -> V_14 ) ;
F_28 ( & V_24 ) ;
F_19 ( V_41 ) ;
return F_43 ( - V_27 ) ;
}
V_12 = F_7 ( V_39 -> V_13 ) ;
if ( ! V_12 ) {
F_39 ( L_6 ,
V_39 -> V_13 , V_42 ? L_7 : L_8 , V_40 ) ;
F_28 ( & V_24 ) ;
F_19 ( V_41 ) ;
return F_43 ( - V_45 ) ;
}
if ( V_42 && V_12 -> V_15 ) {
F_39 ( L_9
L_10 ,
V_39 -> V_13 , V_40 , V_12 -> V_15 ) ;
F_15 ( V_12 -> V_14 ) ;
F_28 ( & V_24 ) ;
F_19 ( V_41 ) ;
return F_43 ( - V_46 ) ;
}
if ( V_42 )
F_40 ( V_12 , V_41 ) ;
else
V_37 = F_41 ( V_12 , V_41 ) ;
V_29 = F_30 ( V_12 -> V_14 , & V_30 ) ;
if ( V_29 )
F_31 ( V_29 ) ;
F_32 ( V_12 -> V_14 , V_30 ) ;
if ( ! F_44 ( V_12 -> V_14 , V_47 , V_39 -> V_48 ) )
V_39 -> V_43 |= V_49 ;
V_14 = V_12 -> V_14 ;
F_28 ( & V_24 ) ;
F_19 ( V_37 ) ;
return V_14 ;
}
static int F_45 ( struct V_38 * V_39 , T_2 V_50 )
{
F_5 ( 1 ) ;
V_39 -> V_51 = 0 ;
return 0 ;
}
static inline void * F_46 ( void * V_52 )
{
return ( void * ) ( ( ( T_2 ) ( V_52 + V_53 ) ) & ~ V_53 ) ;
}
static void * F_47 ( struct V_38 * V_39 , T_2 V_50 ,
T_2 * V_54 )
{
V_39 -> V_55 = F_46 ( V_39 + 1 ) - ( void * ) V_39 ;
if ( V_39 -> V_55 < V_50 )
* V_54 = V_50 - V_39 -> V_55 ;
else
* V_54 = 0 ;
return ( ( void * ) V_39 ) + V_39 -> V_55 ;
}
static int F_48 ( struct V_38 * V_39 , T_2 V_50 )
{
unsigned int V_3 ;
struct V_11 * V_12 ;
T_2 V_54 , V_56 = 0 ;
struct V_57 * V_58 ;
struct V_59 * V_60 , * V_61 = NULL ;
F_22 ( & V_24 ) ;
for ( V_3 = 0 ; V_3 < V_4 ; V_3 ++ ) {
F_8 (hc, _name_buckets + i, name_list) {
V_56 += sizeof( struct V_59 ) ;
V_56 += strlen ( V_12 -> V_13 ) + 1 ;
V_56 += V_53 ;
}
}
V_60 = F_47 ( V_39 , V_50 , & V_54 ) ;
if ( V_54 < V_56 ) {
V_39 -> V_43 |= V_62 ;
goto V_63;
}
V_39 -> V_51 = V_39 -> V_55 + V_56 ;
V_60 -> V_16 = 0 ;
for ( V_3 = 0 ; V_3 < V_4 ; V_3 ++ ) {
F_8 (hc, _name_buckets + i, name_list) {
if ( V_61 )
V_61 -> V_64 = ( V_65 ) ( ( void * ) V_60 -
( void * ) V_61 ) ;
V_58 = F_49 ( V_12 -> V_14 ) ;
V_60 -> V_16 = F_50 ( F_51 ( V_58 ) ) ;
V_60 -> V_64 = 0 ;
strcpy ( V_60 -> V_13 , V_12 -> V_13 ) ;
V_61 = V_60 ;
V_60 = F_46 ( ( ( void * ) ++ V_60 ) + strlen ( V_12 -> V_13 ) + 1 ) ;
}
}
V_63:
F_28 ( & V_24 ) ;
return 0 ;
}
static void F_52 ( struct V_66 * V_67 , void * V_68 )
{
T_2 * V_56 = V_68 ;
* V_56 += sizeof( struct V_69 ) ;
* V_56 += strlen ( V_67 -> V_13 ) ;
* V_56 += V_53 ;
}
static void F_53 ( struct V_66 * V_67 , void * V_39 )
{
struct V_70 * V_71 = V_39 ;
if ( ( char * ) V_71 -> V_72 + sizeof( V_67 -> V_73 ) + strlen ( V_67 -> V_13 ) + 1 >
V_71 -> V_74 ) {
V_71 -> V_43 = V_62 ;
return;
}
if ( V_71 -> V_75 )
V_71 -> V_75 -> V_64 = ( V_65 ) ( ( void * ) V_71 -> V_72 -
( void * ) V_71 -> V_75 ) ;
V_71 -> V_72 -> V_73 [ 0 ] = V_67 -> V_73 [ 0 ] ;
V_71 -> V_72 -> V_73 [ 1 ] = V_67 -> V_73 [ 1 ] ;
V_71 -> V_72 -> V_73 [ 2 ] = V_67 -> V_73 [ 2 ] ;
V_71 -> V_72 -> V_64 = 0 ;
strcpy ( V_71 -> V_72 -> V_13 , V_67 -> V_13 ) ;
V_71 -> V_75 = V_71 -> V_72 ;
V_71 -> V_72 = F_46 ( ( ( void * ) ++ V_71 -> V_72 ) + strlen ( V_67 -> V_13 ) + 1 ) ;
}
static int F_54 ( struct V_38 * V_39 , T_2 V_50 )
{
T_2 V_54 , V_56 = 0 ;
struct V_69 * V_72 ;
struct V_70 V_76 ;
F_55 ( F_52 , & V_56 ) ;
V_72 = F_47 ( V_39 , V_50 , & V_54 ) ;
if ( V_54 < V_56 ) {
V_39 -> V_43 |= V_62 ;
goto V_63;
}
V_39 -> V_51 = V_39 -> V_55 + V_56 ;
V_76 . V_50 = V_50 ;
V_76 . V_75 = NULL ;
V_76 . V_72 = V_72 ;
V_76 . V_43 = 0 ;
V_76 . V_74 = ( char * ) V_72 + V_54 ;
F_55 ( F_53 , & V_76 ) ;
V_39 -> V_43 |= V_76 . V_43 ;
V_63:
return 0 ;
}
static int F_56 ( const char * V_13 )
{
if ( strchr ( V_13 , '/' ) ) {
F_39 ( L_11 ) ;
return - V_46 ;
}
return 0 ;
}
static struct V_28 * F_57 ( struct V_17 * V_14 , int * V_30 )
{
struct V_11 * V_12 ;
struct V_28 * V_29 = NULL ;
F_30 ( V_14 , V_30 ) ;
F_58 ( & V_24 ) ;
V_12 = F_14 ( V_14 ) ;
if ( ! V_12 || V_12 -> V_14 != V_14 ) {
F_39 ( L_12 ) ;
goto V_63;
}
V_29 = V_12 -> V_21 ;
V_63:
F_59 ( & V_24 ) ;
return V_29 ;
}
static struct V_28 * F_60 ( struct V_17 * V_14 ,
struct V_38 * V_39 ,
int * V_30 )
{
return ( V_39 -> V_43 & V_77 ) ?
F_57 ( V_14 , V_30 ) : F_30 ( V_14 , V_30 ) ;
}
static void F_61 ( struct V_17 * V_14 , struct V_38 * V_39 )
{
struct V_57 * V_58 = F_49 ( V_14 ) ;
struct V_28 * V_29 ;
int V_30 ;
V_39 -> V_43 &= ~ ( V_78 | V_79 |
V_80 ) ;
if ( F_62 ( V_14 ) )
V_39 -> V_43 |= V_78 ;
V_39 -> V_16 = F_50 ( F_51 ( V_58 ) ) ;
V_39 -> V_81 = F_63 ( V_14 ) ;
V_39 -> V_48 = F_64 ( V_14 ) ;
V_39 -> V_82 = 0 ;
V_29 = F_30 ( V_14 , & V_30 ) ;
if ( V_29 ) {
if ( ! ( V_39 -> V_43 & V_77 ) ) {
if ( F_65 ( V_58 ) )
V_39 -> V_43 |= V_79 ;
V_39 -> V_82 = F_66 ( V_29 ) ;
}
V_39 -> V_43 |= V_80 ;
}
F_32 ( V_14 , V_30 ) ;
if ( V_39 -> V_43 & V_77 ) {
int V_30 ;
V_29 = F_57 ( V_14 , & V_30 ) ;
if ( V_29 ) {
if ( ! ( F_67 ( V_29 ) & V_83 ) )
V_39 -> V_43 |= V_79 ;
V_39 -> V_82 = F_66 ( V_29 ) ;
}
F_32 ( V_14 , V_30 ) ;
}
}
static int F_68 ( struct V_38 * V_39 , T_2 V_50 )
{
int V_84 , V_85 = V_86 ;
struct V_17 * V_14 ;
V_84 = F_56 ( V_39 -> V_13 ) ;
if ( V_84 )
return V_84 ;
if ( V_39 -> V_43 & V_87 )
V_85 = F_69 ( F_13 ( V_39 -> V_16 ) ) ;
V_84 = F_70 ( V_85 , & V_14 ) ;
if ( V_84 )
return V_84 ;
V_84 = F_21 ( V_39 -> V_13 , * V_39 -> V_15 ? V_39 -> V_15 : NULL , V_14 ) ;
if ( V_84 ) {
F_15 ( V_14 ) ;
F_37 ( V_14 ) ;
return V_84 ;
}
V_39 -> V_43 &= ~ V_88 ;
F_61 ( V_14 , V_39 ) ;
F_15 ( V_14 ) ;
return 0 ;
}
static struct V_11 * F_71 ( struct V_38 * V_39 )
{
struct V_11 * V_12 = NULL ;
if ( * V_39 -> V_15 ) {
if ( * V_39 -> V_13 || V_39 -> V_16 )
return NULL ;
V_12 = F_10 ( V_39 -> V_15 ) ;
if ( ! V_12 )
return NULL ;
} else if ( * V_39 -> V_13 ) {
if ( V_39 -> V_16 )
return NULL ;
V_12 = F_7 ( V_39 -> V_13 ) ;
if ( ! V_12 )
return NULL ;
} else if ( V_39 -> V_16 ) {
V_12 = F_11 ( V_39 -> V_16 ) ;
if ( ! V_12 )
return NULL ;
} else
return NULL ;
F_72 ( V_39 -> V_13 , V_12 -> V_13 , sizeof( V_39 -> V_13 ) ) ;
if ( V_12 -> V_15 )
F_72 ( V_39 -> V_15 , V_12 -> V_15 , sizeof( V_39 -> V_15 ) ) ;
else
V_39 -> V_15 [ 0 ] = '\0' ;
if ( V_12 -> V_21 )
V_39 -> V_43 |= V_88 ;
else
V_39 -> V_43 &= ~ V_88 ;
return V_12 ;
}
static struct V_17 * F_73 ( struct V_38 * V_39 )
{
struct V_11 * V_12 ;
struct V_17 * V_14 = NULL ;
F_58 ( & V_24 ) ;
V_12 = F_71 ( V_39 ) ;
if ( V_12 )
V_14 = V_12 -> V_14 ;
F_59 ( & V_24 ) ;
return V_14 ;
}
static int F_74 ( struct V_38 * V_39 , T_2 V_50 )
{
struct V_11 * V_12 ;
struct V_17 * V_14 ;
int V_84 ;
struct V_28 * V_33 ;
F_22 ( & V_24 ) ;
V_12 = F_71 ( V_39 ) ;
if ( ! V_12 ) {
F_75 ( L_13 ) ;
F_28 ( & V_24 ) ;
return - V_45 ;
}
V_14 = V_12 -> V_14 ;
V_84 = F_33 ( V_14 ) ;
if ( V_84 ) {
F_75 ( L_14 , V_12 -> V_13 ) ;
F_28 ( & V_24 ) ;
F_15 ( V_14 ) ;
return V_84 ;
}
V_33 = F_29 ( V_12 ) ;
F_28 ( & V_24 ) ;
if ( V_33 ) {
F_34 ( V_14 ) ;
F_35 ( V_33 ) ;
}
if ( ! F_44 ( V_14 , V_89 , V_39 -> V_48 ) )
V_39 -> V_43 |= V_49 ;
F_15 ( V_14 ) ;
F_37 ( V_14 ) ;
return 0 ;
}
static int F_76 ( char * V_7 , void * V_74 )
{
while ( ( void * ) V_7 < V_74 )
if ( ! * V_7 ++ )
return 0 ;
return - V_46 ;
}
static int F_77 ( struct V_38 * V_39 , T_2 V_50 )
{
int V_84 ;
char * V_41 = ( char * ) V_39 + V_39 -> V_55 ;
struct V_17 * V_14 ;
unsigned V_42 = ( V_39 -> V_43 & V_44 ) ? 1 : 0 ;
if ( V_41 < V_39 -> V_90 ||
F_76 ( V_41, ( void * ) V_39 + V_50 ) ||
strlen ( V_41 ) > ( V_42 ? V_91 - 1 : V_92 - 1 ) ) {
F_39 ( L_15 ) ;
return - V_46 ;
}
if ( ! V_42 ) {
V_84 = F_56 ( V_41 ) ;
if ( V_84 )
return V_84 ;
}
V_14 = F_42 ( V_39 , V_41 ) ;
if ( F_78 ( V_14 ) )
return F_79 ( V_14 ) ;
F_61 ( V_14 , V_39 ) ;
F_15 ( V_14 ) ;
return 0 ;
}
static int F_80 ( struct V_38 * V_39 , T_2 V_50 )
{
int V_84 = - V_46 , V_93 ;
struct V_17 * V_14 ;
struct V_94 V_95 ;
unsigned long V_96 [ 4 ] ;
char * V_97 = ( char * ) V_39 + V_39 -> V_55 ;
char V_98 ;
V_14 = F_73 ( V_39 ) ;
if ( ! V_14 )
return - V_45 ;
if ( V_97 < V_39 -> V_90 ||
F_76 ( V_97 , ( void * ) V_39 + V_50 ) ) {
F_39 ( L_16 ) ;
goto V_63;
}
V_93 = sscanf ( V_97 , L_17 , V_96 ,
V_96 + 1 , V_96 + 2 , V_96 + 3 , & V_98 ) ;
if ( V_93 != 4 ) {
F_39 ( L_18 ) ;
goto V_63;
}
if ( V_96 [ 0 ] > 65535 || V_96 [ 1 ] > 255 ||
V_96 [ 2 ] > 255 || V_96 [ 3 ] > V_99 ) {
F_39 ( L_19 ) ;
goto V_63;
}
V_95 . V_100 = V_96 [ 0 ] ;
V_95 . V_101 = V_96 [ 1 ] ;
V_95 . V_102 = V_96 [ 2 ] ;
V_95 . V_103 = V_96 [ 3 ] ;
V_84 = F_81 ( V_14 , & V_95 ) ;
V_39 -> V_51 = 0 ;
V_63:
F_15 ( V_14 ) ;
return V_84 ;
}
static int F_82 ( struct V_38 * V_39 )
{
int V_84 = 0 ;
unsigned V_104 = V_105 ;
struct V_17 * V_14 ;
V_14 = F_73 ( V_39 ) ;
if ( ! V_14 )
return - V_45 ;
if ( V_39 -> V_43 & V_106 )
V_104 &= ~ V_105 ;
if ( V_39 -> V_43 & V_107 )
V_104 |= V_108 ;
if ( ! F_62 ( V_14 ) ) {
V_84 = F_83 ( V_14 , V_104 ) ;
if ( V_84 )
goto V_63;
}
F_61 ( V_14 , V_39 ) ;
V_63:
F_15 ( V_14 ) ;
return V_84 ;
}
static int F_84 ( struct V_38 * V_39 )
{
int V_84 = 0 ;
unsigned V_104 = V_105 ;
struct V_11 * V_12 ;
struct V_17 * V_14 ;
struct V_28 * V_21 , * V_109 = NULL ;
F_22 ( & V_24 ) ;
V_12 = F_71 ( V_39 ) ;
if ( ! V_12 ) {
F_75 ( L_13 ) ;
F_28 ( & V_24 ) ;
return - V_45 ;
}
V_14 = V_12 -> V_14 ;
V_21 = V_12 -> V_21 ;
V_12 -> V_21 = NULL ;
V_39 -> V_43 &= ~ V_88 ;
F_28 ( & V_24 ) ;
if ( V_21 ) {
if ( V_39 -> V_43 & V_106 )
V_104 &= ~ V_105 ;
if ( V_39 -> V_43 & V_107 )
V_104 |= V_108 ;
if ( ! F_62 ( V_14 ) )
F_83 ( V_14 , V_104 ) ;
V_109 = F_85 ( V_14 , V_21 ) ;
if ( F_78 ( V_109 ) ) {
F_34 ( V_14 ) ;
F_35 ( V_21 ) ;
F_15 ( V_14 ) ;
return F_79 ( V_109 ) ;
}
if ( F_67 ( V_21 ) & V_83 )
F_86 ( F_49 ( V_14 ) , 0 ) ;
else
F_86 ( F_49 ( V_14 ) , 1 ) ;
}
if ( F_62 ( V_14 ) ) {
V_84 = F_87 ( V_14 ) ;
if ( ! V_84 && ! F_44 ( V_14 , V_47 , V_39 -> V_48 ) )
V_39 -> V_43 |= V_49 ;
}
if ( V_109 )
F_35 ( V_109 ) ;
if ( ! V_84 )
F_61 ( V_14 , V_39 ) ;
F_15 ( V_14 ) ;
return V_84 ;
}
static int F_88 ( struct V_38 * V_39 , T_2 V_50 )
{
if ( V_39 -> V_43 & V_78 )
return F_82 ( V_39 ) ;
return F_84 ( V_39 ) ;
}
static int F_89 ( struct V_38 * V_39 , T_2 V_50 )
{
struct V_17 * V_14 ;
V_14 = F_73 ( V_39 ) ;
if ( ! V_14 )
return - V_45 ;
F_61 ( V_14 , V_39 ) ;
F_15 ( V_14 ) ;
return 0 ;
}
static void F_90 ( struct V_28 * V_29 ,
struct V_38 * V_39 , T_2 V_50 )
{
unsigned int V_3 , V_110 ;
struct V_111 * V_112 ;
char * V_113 , * V_114 ;
T_3 type ;
T_2 V_115 , V_54 , V_116 = 0 ;
unsigned V_117 = 0 ;
V_114 = V_113 = F_47 ( V_39 , V_50 , & V_54 ) ;
if ( V_39 -> V_43 & V_118 )
type = V_119 ;
else
type = V_120 ;
V_110 = F_66 ( V_29 ) ;
for ( V_3 = 0 ; V_3 < V_110 ; V_3 ++ ) {
struct V_121 * V_122 = F_91 ( V_29 , V_3 ) ;
T_2 V_123 ;
V_115 = V_54 - ( V_114 - V_113 ) ;
if ( V_115 <= sizeof( struct V_111 ) ) {
V_39 -> V_43 |= V_62 ;
break;
}
V_112 = (struct V_111 * ) V_114 ;
V_112 -> V_124 = 0 ;
V_112 -> V_125 = V_122 -> V_126 ;
V_112 -> V_127 = V_122 -> V_54 ;
strncpy ( V_112 -> V_66 , V_122 -> type -> V_13 ,
sizeof( V_112 -> V_66 ) ) ;
V_114 += sizeof( struct V_111 ) ;
V_115 = V_54 - ( V_114 - V_113 ) ;
if ( V_115 <= 0 ) {
V_39 -> V_43 |= V_62 ;
break;
}
if ( V_122 -> type -> V_124 ) {
if ( V_39 -> V_43 & V_107 )
V_117 |= V_128 ;
V_122 -> type -> V_124 ( V_122 , type , V_117 , V_114 , V_115 ) ;
} else
V_114 [ 0 ] = '\0' ;
V_123 = strlen ( V_114 ) + 1 ;
if ( V_123 == V_115 ) {
V_39 -> V_43 |= V_62 ;
break;
}
V_114 += V_123 ;
V_116 = V_39 -> V_55 + ( V_114 - V_113 ) ;
V_114 = F_46 ( V_114 ) ;
V_112 -> V_64 = V_114 - V_113 ;
}
if ( V_116 )
V_39 -> V_51 = V_116 ;
V_39 -> V_82 = V_110 ;
}
static int F_92 ( struct V_38 * V_39 , T_2 V_50 )
{
int V_84 = 0 ;
struct V_17 * V_14 ;
struct V_28 * V_29 ;
int V_30 ;
V_14 = F_73 ( V_39 ) ;
if ( ! V_14 )
return - V_45 ;
if ( F_93 ( V_14 , V_39 -> V_48 ) ) {
V_84 = - V_129 ;
goto V_63;
}
F_61 ( V_14 , V_39 ) ;
V_29 = F_60 ( V_14 , V_39 , & V_30 ) ;
if ( V_29 )
F_90 ( V_29 , V_39 , V_50 ) ;
F_32 ( V_14 , V_30 ) ;
V_63:
F_15 ( V_14 ) ;
return V_84 ;
}
static inline T_4 F_94 ( struct V_38 * V_39 )
{
T_4 V_130 = V_131 | V_83 ;
if ( V_39 -> V_43 & V_79 )
V_130 = V_131 ;
return V_130 ;
}
static int F_95 ( struct V_111 * V_132 , V_65 V_64 , void * V_74 ,
struct V_111 * * V_112 , char * * V_133 )
{
* V_112 = (struct V_111 * ) ( ( unsigned char * ) V_132 + V_64 ) ;
* V_133 = ( char * ) ( * V_112 + 1 ) ;
if ( * V_112 < ( V_132 + 1 ) )
return - V_46 ;
return F_76 ( * V_133 , V_74 ) ;
}
static int F_96 ( struct V_28 * V_29 ,
struct V_38 * V_39 , T_2 V_50 )
{
int V_84 ;
unsigned int V_3 = 0 ;
struct V_111 * V_112 = (struct V_111 * ) V_39 ;
V_65 V_64 = V_39 -> V_55 ;
void * V_74 = ( void * ) V_39 + V_50 ;
char * V_133 ;
if ( ! V_39 -> V_82 ) {
F_39 ( L_20 ) ;
return - V_46 ;
}
for ( V_3 = 0 ; V_3 < V_39 -> V_82 ; V_3 ++ ) {
V_84 = F_95 ( V_112 , V_64 , V_74 , & V_112 , & V_133 ) ;
if ( V_84 ) {
F_39 ( L_21 ) ;
return V_84 ;
}
V_84 = F_97 ( V_29 , V_112 -> V_66 ,
( V_134 ) V_112 -> V_125 ,
( V_134 ) V_112 -> V_127 ,
V_133 ) ;
if ( V_84 ) {
F_39 ( L_22 ) ;
return V_84 ;
}
V_64 = V_112 -> V_64 ;
}
return F_98 ( V_29 ) ;
}
static int F_99 ( struct V_38 * V_39 , T_2 V_50 )
{
int V_84 ;
struct V_11 * V_12 ;
struct V_28 * V_33 , * V_109 = NULL ;
struct V_17 * V_14 ;
struct V_66 * V_135 ;
V_14 = F_73 ( V_39 ) ;
if ( ! V_14 )
return - V_45 ;
V_84 = F_100 ( & V_33 , F_94 ( V_39 ) , V_39 -> V_82 , V_14 ) ;
if ( V_84 )
goto V_63;
V_84 = F_96 ( V_33 , V_39 , V_50 ) ;
if ( V_84 ) {
F_35 ( V_33 ) ;
goto V_63;
}
V_135 = F_101 ( V_14 ) ;
if ( V_135 &&
( V_135 != F_102 ( V_33 ) ) ) {
F_39 ( L_23 ,
V_135 -> V_13 ) ;
F_35 ( V_33 ) ;
V_84 = - V_46 ;
goto V_63;
}
F_103 ( V_14 ) ;
if ( F_104 ( V_14 ) == V_136 )
F_105 ( V_14 , F_106 ( V_33 ) ) ;
else if ( F_104 ( V_14 ) != F_106 ( V_33 ) ) {
F_39 ( L_24 ) ;
F_35 ( V_33 ) ;
F_107 ( V_14 ) ;
V_84 = - V_46 ;
goto V_63;
}
V_84 = F_108 ( V_14 ) ;
if ( V_84 ) {
F_39 ( L_25 ) ;
F_35 ( V_33 ) ;
F_107 ( V_14 ) ;
goto V_63;
}
F_107 ( V_14 ) ;
F_22 ( & V_24 ) ;
V_12 = F_14 ( V_14 ) ;
if ( ! V_12 || V_12 -> V_14 != V_14 ) {
F_39 ( L_12 ) ;
F_28 ( & V_24 ) ;
F_35 ( V_33 ) ;
V_84 = - V_45 ;
goto V_63;
}
if ( V_12 -> V_21 )
V_109 = V_12 -> V_21 ;
V_12 -> V_21 = V_33 ;
F_28 ( & V_24 ) ;
V_39 -> V_43 |= V_88 ;
F_61 ( V_14 , V_39 ) ;
V_63:
if ( V_109 ) {
F_34 ( V_14 ) ;
F_35 ( V_109 ) ;
}
F_15 ( V_14 ) ;
return V_84 ;
}
static int F_109 ( struct V_38 * V_39 , T_2 V_50 )
{
struct V_11 * V_12 ;
struct V_17 * V_14 ;
struct V_28 * V_109 = NULL ;
F_22 ( & V_24 ) ;
V_12 = F_71 ( V_39 ) ;
if ( ! V_12 ) {
F_75 ( L_13 ) ;
F_28 ( & V_24 ) ;
return - V_45 ;
}
if ( V_12 -> V_21 ) {
V_109 = V_12 -> V_21 ;
V_12 -> V_21 = NULL ;
}
V_39 -> V_43 &= ~ V_88 ;
F_61 ( V_12 -> V_14 , V_39 ) ;
V_14 = V_12 -> V_14 ;
F_28 ( & V_24 ) ;
if ( V_109 ) {
F_34 ( V_14 ) ;
F_35 ( V_109 ) ;
}
F_15 ( V_14 ) ;
return 0 ;
}
static void F_110 ( struct V_28 * V_29 ,
struct V_38 * V_39 , T_2 V_50 )
{
unsigned int V_137 = 0 ;
struct V_1 * V_138 ;
T_2 V_54 , V_56 ;
struct V_139 * V_140 ;
struct V_141 * V_142 ;
V_142 = F_47 ( V_39 , V_50 , & V_54 ) ;
F_111 (tmp, dm_table_get_devices(table))
V_137 ++ ;
V_56 = sizeof( * V_142 ) + ( sizeof( * V_142 -> V_16 ) * V_137 ) ;
if ( V_54 < V_56 ) {
V_39 -> V_43 |= V_62 ;
return;
}
V_142 -> V_137 = V_137 ;
V_137 = 0 ;
F_8 (dd, dm_table_get_devices(table), list)
V_142 -> V_16 [ V_137 ++ ] = F_50 ( V_140 -> V_143 . V_144 -> V_145 ) ;
V_39 -> V_51 = V_39 -> V_55 + V_56 ;
}
static int F_112 ( struct V_38 * V_39 , T_2 V_50 )
{
struct V_17 * V_14 ;
struct V_28 * V_29 ;
int V_30 ;
V_14 = F_73 ( V_39 ) ;
if ( ! V_14 )
return - V_45 ;
F_61 ( V_14 , V_39 ) ;
V_29 = F_60 ( V_14 , V_39 , & V_30 ) ;
if ( V_29 )
F_110 ( V_29 , V_39 , V_50 ) ;
F_32 ( V_14 , V_30 ) ;
F_15 ( V_14 ) ;
return 0 ;
}
static int F_113 ( struct V_38 * V_39 , T_2 V_50 )
{
struct V_17 * V_14 ;
struct V_28 * V_29 ;
int V_30 ;
V_14 = F_73 ( V_39 ) ;
if ( ! V_14 )
return - V_45 ;
F_61 ( V_14 , V_39 ) ;
V_29 = F_60 ( V_14 , V_39 , & V_30 ) ;
if ( V_29 )
F_90 ( V_29 , V_39 , V_50 ) ;
F_32 ( V_14 , V_30 ) ;
F_15 ( V_14 ) ;
return 0 ;
}
static bool F_114 ( char * V_146 , unsigned V_147 )
{
return ! V_147 || strlen ( V_146 ) + 1 >= V_147 ;
}
static int F_115 ( struct V_17 * V_14 , unsigned V_148 , char * * V_149 ,
char * V_146 , unsigned V_147 )
{
return 2 ;
}
static int F_116 ( struct V_38 * V_39 , T_2 V_50 )
{
int V_84 , V_148 ;
char * * V_149 ;
struct V_17 * V_14 ;
struct V_28 * V_29 ;
struct V_121 * V_122 ;
struct V_150 * V_151 = ( void * ) V_39 + V_39 -> V_55 ;
T_2 V_147 ;
char * V_146 = F_47 ( V_39 , V_50 , & V_147 ) ;
int V_30 ;
V_14 = F_73 ( V_39 ) ;
if ( ! V_14 )
return - V_45 ;
if ( V_151 < (struct V_150 * ) V_39 -> V_90 ||
F_76 ( V_151 -> V_152 , ( void * ) V_39 + V_50 ) ) {
F_39 ( L_26 ) ;
V_84 = - V_46 ;
goto V_63;
}
V_84 = F_117 ( & V_148 , & V_149 , V_151 -> V_152 ) ;
if ( V_84 ) {
F_39 ( L_27 ) ;
goto V_63;
}
if ( ! V_148 ) {
F_39 ( L_28 ) ;
goto V_153;
}
V_84 = F_115 ( V_14 , V_148 , V_149 , V_146 , V_147 ) ;
if ( V_84 <= 1 )
goto V_153;
V_29 = F_30 ( V_14 , & V_30 ) ;
if ( ! V_29 )
goto V_154;
if ( F_118 ( V_14 ) ) {
V_84 = - V_45 ;
goto V_154;
}
V_122 = F_119 ( V_29 , V_151 -> V_155 ) ;
if ( ! F_120 ( V_122 ) ) {
F_39 ( L_29 ) ;
V_84 = - V_46 ;
} else if ( V_122 -> type -> V_152 )
V_84 = V_122 -> type -> V_152 ( V_122 , V_148 , V_149 ) ;
else {
F_39 ( L_30 ) ;
V_84 = - V_46 ;
}
V_154:
F_32 ( V_14 , V_30 ) ;
V_153:
F_19 ( V_149 ) ;
V_63:
if ( V_84 >= 0 )
F_61 ( V_14 , V_39 ) ;
if ( V_84 == 1 ) {
V_39 -> V_43 |= V_156 ;
if ( F_114 ( V_146 , V_147 ) )
V_39 -> V_43 |= V_62 ;
else
V_39 -> V_51 = V_39 -> V_55 + strlen ( V_146 ) + 1 ;
V_84 = 0 ;
}
F_15 ( V_14 ) ;
return V_84 ;
}
static T_5 F_121 ( unsigned int V_157 , int * V_158 )
{
static struct {
int V_157 ;
int V_43 ;
T_5 V_159 ;
} V_160 [] = {
{ V_161 , 0 , NULL } ,
{ V_162 , V_163 , F_45 } ,
{ V_164 , 0 , F_48 } ,
{ V_165 , V_163 , F_68 } ,
{ V_166 , V_163 , F_74 } ,
{ V_167 , 0 , F_77 } ,
{ V_168 , V_163 , F_88 } ,
{ V_169 , V_163 , F_89 } ,
{ V_170 , 0 , F_92 } ,
{ V_171 , 0 , F_99 } ,
{ V_172 , V_163 , F_109 } ,
{ V_173 , 0 , F_112 } ,
{ V_174 , 0 , F_113 } ,
{ V_175 , 0 , F_54 } ,
{ V_176 , 0 , F_116 } ,
{ V_177 , 0 , F_80 }
} ;
if ( F_122 ( V_157 >= F_123 ( V_160 ) ) )
return NULL ;
* V_158 = V_160 [ V_157 ] . V_43 ;
return V_160 [ V_157 ] . V_159 ;
}
static int F_124 ( unsigned int V_157 , struct V_38 T_6 * V_178 )
{
V_65 V_73 [ 3 ] ;
int V_84 = 0 ;
if ( F_125 ( V_73 , V_178 -> V_73 , sizeof( V_73 ) ) )
return - V_179 ;
if ( ( V_180 != V_73 [ 0 ] ) ||
( V_181 < V_73 [ 1 ] ) ) {
F_39 ( L_31
L_32 ,
V_180 , V_181 ,
V_182 ,
V_73 [ 0 ] , V_73 [ 1 ] , V_73 [ 2 ] , V_157 ) ;
V_84 = - V_46 ;
}
V_73 [ 0 ] = V_180 ;
V_73 [ 1 ] = V_181 ;
V_73 [ 2 ] = V_182 ;
if ( F_126 ( V_178 -> V_73 , V_73 , sizeof( V_73 ) ) )
return - V_179 ;
return V_84 ;
}
static void F_127 ( struct V_38 * V_39 , T_2 V_50 , int V_183 )
{
if ( V_183 & V_184 )
memset ( V_39 , 0 , V_50 ) ;
if ( V_183 & V_185 )
F_19 ( V_39 ) ;
if ( V_183 & V_186 )
F_128 ( V_39 ) ;
}
static int F_129 ( struct V_38 T_6 * V_178 , struct V_38 * V_187 ,
int V_158 ,
struct V_38 * * V_39 , int * V_183 )
{
struct V_38 * V_188 ;
int V_189 ;
const T_2 V_190 = sizeof( * V_187 ) - sizeof( V_187 -> V_90 ) ;
if ( F_125 ( V_187 , V_178 , V_190 ) )
return - V_179 ;
if ( V_187 -> V_51 < V_190 )
return - V_46 ;
V_189 = V_187 -> V_43 & V_191 ;
* V_183 = V_189 ? V_184 : 0 ;
if ( V_158 & V_163 ) {
V_188 = V_187 ;
V_188 -> V_51 = V_190 ;
goto V_192;
}
V_188 = NULL ;
if ( V_187 -> V_51 <= V_193 ) {
V_188 = F_17 ( V_187 -> V_51 , V_194 | V_195 | V_196 | V_197 ) ;
if ( V_188 )
* V_183 |= V_185 ;
}
if ( ! V_188 ) {
unsigned V_198 ;
V_198 = F_130 () ;
V_188 = F_131 ( V_187 -> V_51 , V_194 | V_199 | V_200 | V_201 , V_202 ) ;
F_132 ( V_198 ) ;
if ( V_188 )
* V_183 |= V_186 ;
}
if ( ! V_188 ) {
if ( V_189 && F_133 ( V_178 , V_187 -> V_51 ) )
return - V_179 ;
return - V_23 ;
}
if ( F_125 ( V_188 , V_178 , V_187 -> V_51 ) )
goto V_25;
V_192:
if ( V_188 -> V_51 != V_187 -> V_51 ) {
F_134 ( L_33 ) ;
goto V_25;
}
if ( V_189 && F_133 ( V_178 , V_187 -> V_51 ) )
goto V_25;
* V_39 = V_188 ;
return 0 ;
V_25:
F_127 ( V_188 , V_187 -> V_51 , * V_183 ) ;
return - V_179 ;
}
static int F_135 ( T_7 V_157 , struct V_38 * V_39 )
{
V_39 -> V_43 &= ~ V_62 ;
V_39 -> V_43 &= ~ V_49 ;
V_39 -> V_43 &= ~ V_191 ;
V_39 -> V_43 &= ~ V_156 ;
if ( V_157 == V_162 ||
V_157 == V_164 ||
V_157 == V_175 )
return 0 ;
if ( ( V_157 == V_165 ) ) {
if ( ! * V_39 -> V_13 ) {
F_39 ( L_34 ) ;
return - V_46 ;
}
} else if ( ( * V_39 -> V_15 && * V_39 -> V_13 ) ) {
F_39 ( L_35 , V_157 ) ;
return - V_46 ;
}
V_39 -> V_13 [ V_92 - 1 ] = '\0' ;
V_39 -> V_15 [ V_91 - 1 ] = '\0' ;
return 0 ;
}
static int F_136 ( T_7 V_203 , struct V_38 T_6 * V_178 )
{
int V_84 = 0 ;
int V_158 ;
int V_183 ;
unsigned int V_157 ;
struct V_38 * V_204 ( V_39 ) ;
T_5 V_159 = NULL ;
T_2 V_205 ;
struct V_38 V_187 ;
if ( ! F_137 ( V_206 ) )
return - V_207 ;
if ( F_138 ( V_203 ) != V_208 )
return - V_209 ;
V_157 = F_139 ( V_203 ) ;
V_84 = F_124 ( V_157 , V_178 ) ;
if ( V_84 )
return V_84 ;
if ( V_157 == V_161 )
return 0 ;
V_159 = F_121 ( V_157 , & V_158 ) ;
if ( ! V_159 ) {
F_39 ( L_36 , V_203 ) ;
return - V_209 ;
}
V_84 = F_129 ( V_178 , & V_187 , V_158 , & V_39 , & V_183 ) ;
if ( V_84 )
return V_84 ;
V_205 = V_39 -> V_51 ;
V_84 = F_135 ( V_157 , V_39 ) ;
if ( V_84 )
goto V_63;
V_39 -> V_51 = sizeof( * V_39 ) ;
V_84 = V_159 ( V_39 , V_205 ) ;
if ( F_122 ( V_39 -> V_43 & V_62 ) &&
F_122 ( V_158 & V_163 ) )
F_134 ( L_37 , V_157 ) ;
if ( ! V_84 && F_126 ( V_178 , V_39 , V_39 -> V_51 ) )
V_84 = - V_179 ;
V_63:
F_127 ( V_39 , V_205 , V_183 ) ;
return V_84 ;
}
static long F_140 ( struct V_210 * V_210 , T_7 V_203 , T_8 V_211 )
{
return ( long ) F_136 ( V_203 , (struct V_38 T_6 * ) V_211 ) ;
}
static long F_141 ( struct V_210 * V_210 , T_7 V_203 , T_8 V_211 )
{
return ( long ) F_140 ( V_210 , V_203 , ( T_8 ) F_142 ( V_211 ) ) ;
}
int T_9 F_143 ( void )
{
int V_84 ;
V_84 = F_3 () ;
if ( V_84 )
return V_84 ;
V_84 = F_144 ( & V_212 ) ;
if ( V_84 ) {
F_134 ( L_38 ) ;
F_4 () ;
return V_84 ;
}
F_145 ( L_39 , V_180 ,
V_181 , V_182 , V_213 ,
V_214 ) ;
return 0 ;
}
void F_146 ( void )
{
if ( F_147 ( & V_212 ) < 0 )
F_134 ( L_40 ) ;
F_4 () ;
}
int F_148 ( struct V_17 * V_14 , char * V_13 , char * V_15 )
{
int V_84 = 0 ;
struct V_11 * V_12 ;
if ( ! V_14 )
return - V_45 ;
F_25 ( & V_26 ) ;
V_12 = F_14 ( V_14 ) ;
if ( ! V_12 || V_12 -> V_14 != V_14 ) {
V_84 = - V_45 ;
goto V_63;
}
if ( V_13 )
strcpy ( V_13 , V_12 -> V_13 ) ;
if ( V_15 )
strcpy ( V_15 , V_12 -> V_15 ? : L_8 ) ;
V_63:
F_27 ( & V_26 ) ;
return V_84 ;
}
