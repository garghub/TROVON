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
static int F_46 ( struct V_40 * V_41 , T_2 V_52 )
{
F_5 ( true , ! ! ( V_41 -> V_45 & V_53 ) , false ) ;
V_41 -> V_54 = 0 ;
return 0 ;
}
static inline void * F_47 ( void * V_55 )
{
return ( void * ) ( ( ( T_2 ) ( V_55 + V_56 ) ) & ~ V_56 ) ;
}
static void * F_48 ( struct V_40 * V_41 , T_2 V_52 ,
T_2 * V_57 )
{
V_41 -> V_58 = F_47 ( V_41 + 1 ) - ( void * ) V_41 ;
if ( V_41 -> V_58 < V_52 )
* V_57 = V_52 - V_41 -> V_58 ;
else
* V_57 = 0 ;
return ( ( void * ) V_41 ) + V_41 -> V_58 ;
}
static int F_49 ( struct V_40 * V_41 , T_2 V_52 )
{
unsigned int V_3 ;
struct V_11 * V_12 ;
T_2 V_57 , V_59 = 0 ;
struct V_60 * V_61 ;
struct V_62 * V_63 , * V_64 = NULL ;
F_22 ( & V_24 ) ;
for ( V_3 = 0 ; V_3 < V_4 ; V_3 ++ ) {
F_8 (hc, _name_buckets + i, name_list) {
V_59 += sizeof( struct V_62 ) ;
V_59 += strlen ( V_12 -> V_13 ) + 1 ;
V_59 += V_56 ;
}
}
V_63 = F_48 ( V_41 , V_52 , & V_57 ) ;
if ( V_57 < V_59 ) {
V_41 -> V_45 |= V_65 ;
goto V_66;
}
V_41 -> V_54 = V_41 -> V_58 + V_59 ;
V_63 -> V_16 = 0 ;
for ( V_3 = 0 ; V_3 < V_4 ; V_3 ++ ) {
F_8 (hc, _name_buckets + i, name_list) {
if ( V_64 )
V_64 -> V_67 = ( V_68 ) ( ( void * ) V_63 -
( void * ) V_64 ) ;
V_61 = F_50 ( V_12 -> V_14 ) ;
V_63 -> V_16 = F_51 ( F_52 ( V_61 ) ) ;
V_63 -> V_67 = 0 ;
strcpy ( V_63 -> V_13 , V_12 -> V_13 ) ;
V_64 = V_63 ;
V_63 = F_47 ( ( ( void * ) ++ V_63 ) + strlen ( V_12 -> V_13 ) + 1 ) ;
}
}
V_66:
F_28 ( & V_24 ) ;
return 0 ;
}
static void F_53 ( struct V_69 * V_70 , void * V_71 )
{
T_2 * V_59 = V_71 ;
* V_59 += sizeof( struct V_72 ) ;
* V_59 += strlen ( V_70 -> V_13 ) ;
* V_59 += V_56 ;
}
static void F_54 ( struct V_69 * V_70 , void * V_41 )
{
struct V_73 * V_74 = V_41 ;
if ( ( char * ) V_74 -> V_75 + sizeof( V_70 -> V_76 ) + strlen ( V_70 -> V_13 ) + 1 >
V_74 -> V_77 ) {
V_74 -> V_45 = V_65 ;
return;
}
if ( V_74 -> V_78 )
V_74 -> V_78 -> V_67 = ( V_68 ) ( ( void * ) V_74 -> V_75 -
( void * ) V_74 -> V_78 ) ;
V_74 -> V_75 -> V_76 [ 0 ] = V_70 -> V_76 [ 0 ] ;
V_74 -> V_75 -> V_76 [ 1 ] = V_70 -> V_76 [ 1 ] ;
V_74 -> V_75 -> V_76 [ 2 ] = V_70 -> V_76 [ 2 ] ;
V_74 -> V_75 -> V_67 = 0 ;
strcpy ( V_74 -> V_75 -> V_13 , V_70 -> V_13 ) ;
V_74 -> V_78 = V_74 -> V_75 ;
V_74 -> V_75 = F_47 ( ( ( void * ) ++ V_74 -> V_75 ) + strlen ( V_70 -> V_13 ) + 1 ) ;
}
static int F_55 ( struct V_40 * V_41 , T_2 V_52 )
{
T_2 V_57 , V_59 = 0 ;
struct V_72 * V_75 ;
struct V_73 V_79 ;
F_56 ( F_53 , & V_59 ) ;
V_75 = F_48 ( V_41 , V_52 , & V_57 ) ;
if ( V_57 < V_59 ) {
V_41 -> V_45 |= V_65 ;
goto V_66;
}
V_41 -> V_54 = V_41 -> V_58 + V_59 ;
V_79 . V_52 = V_52 ;
V_79 . V_78 = NULL ;
V_79 . V_75 = V_75 ;
V_79 . V_45 = 0 ;
V_79 . V_77 = ( char * ) V_75 + V_57 ;
F_56 ( F_54 , & V_79 ) ;
V_41 -> V_45 |= V_79 . V_45 ;
V_66:
return 0 ;
}
static int F_57 ( const char * V_13 )
{
if ( strchr ( V_13 , '/' ) ) {
F_39 ( L_11 ) ;
return - V_48 ;
}
return 0 ;
}
static struct V_28 * F_58 ( struct V_17 * V_14 , int * V_30 )
{
struct V_11 * V_12 ;
struct V_28 * V_29 = NULL ;
F_30 ( V_14 , V_30 ) ;
F_59 ( & V_24 ) ;
V_12 = F_14 ( V_14 ) ;
if ( ! V_12 || V_12 -> V_14 != V_14 ) {
F_39 ( L_12 ) ;
goto V_66;
}
V_29 = V_12 -> V_21 ;
V_66:
F_60 ( & V_24 ) ;
return V_29 ;
}
static struct V_28 * F_61 ( struct V_17 * V_14 ,
struct V_40 * V_41 ,
int * V_30 )
{
return ( V_41 -> V_45 & V_80 ) ?
F_58 ( V_14 , V_30 ) : F_30 ( V_14 , V_30 ) ;
}
static void F_62 ( struct V_17 * V_14 , struct V_40 * V_41 )
{
struct V_60 * V_61 = F_50 ( V_14 ) ;
struct V_28 * V_29 ;
int V_30 ;
V_41 -> V_45 &= ~ ( V_81 | V_82 |
V_83 | V_84 ) ;
if ( F_63 ( V_14 ) )
V_41 -> V_45 |= V_81 ;
if ( F_64 ( V_14 ) )
V_41 -> V_45 |= V_84 ;
if ( F_65 ( V_14 ) )
V_41 -> V_45 |= V_53 ;
V_41 -> V_16 = F_51 ( F_52 ( V_61 ) ) ;
V_41 -> V_85 = F_66 ( V_14 ) ;
V_41 -> V_50 = F_67 ( V_14 ) ;
V_41 -> V_86 = 0 ;
V_29 = F_30 ( V_14 , & V_30 ) ;
if ( V_29 ) {
if ( ! ( V_41 -> V_45 & V_80 ) ) {
if ( F_68 ( V_61 ) )
V_41 -> V_45 |= V_82 ;
V_41 -> V_86 = F_69 ( V_29 ) ;
}
V_41 -> V_45 |= V_83 ;
}
F_32 ( V_14 , V_30 ) ;
if ( V_41 -> V_45 & V_80 ) {
int V_30 ;
V_29 = F_58 ( V_14 , & V_30 ) ;
if ( V_29 ) {
if ( ! ( F_70 ( V_29 ) & V_87 ) )
V_41 -> V_45 |= V_82 ;
V_41 -> V_86 = F_69 ( V_29 ) ;
}
F_32 ( V_14 , V_30 ) ;
}
}
static int F_71 ( struct V_40 * V_41 , T_2 V_52 )
{
int V_88 , V_89 = V_90 ;
struct V_17 * V_14 ;
V_88 = F_57 ( V_41 -> V_13 ) ;
if ( V_88 )
return V_88 ;
if ( V_41 -> V_45 & V_91 )
V_89 = F_72 ( F_13 ( V_41 -> V_16 ) ) ;
V_88 = F_73 ( V_89 , & V_14 ) ;
if ( V_88 )
return V_88 ;
V_88 = F_21 ( V_41 -> V_13 , * V_41 -> V_15 ? V_41 -> V_15 : NULL , V_14 ) ;
if ( V_88 ) {
F_15 ( V_14 ) ;
F_37 ( V_14 ) ;
return V_88 ;
}
V_41 -> V_45 &= ~ V_92 ;
F_62 ( V_14 , V_41 ) ;
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
V_41 -> V_45 |= V_92 ;
else
V_41 -> V_45 &= ~ V_92 ;
return V_12 ;
}
static struct V_17 * F_76 ( struct V_40 * V_41 )
{
struct V_11 * V_12 ;
struct V_17 * V_14 = NULL ;
F_59 ( & V_24 ) ;
V_12 = F_74 ( V_41 ) ;
if ( V_12 )
V_14 = V_12 -> V_14 ;
F_60 ( & V_24 ) ;
return V_14 ;
}
static int F_77 ( struct V_40 * V_41 , T_2 V_52 )
{
struct V_11 * V_12 ;
struct V_17 * V_14 ;
int V_88 ;
struct V_28 * V_35 ;
F_22 ( & V_24 ) ;
V_12 = F_74 ( V_41 ) ;
if ( ! V_12 ) {
F_78 ( L_13 ) ;
F_28 ( & V_24 ) ;
return - V_47 ;
}
V_14 = V_12 -> V_14 ;
V_88 = F_33 ( V_14 , ! ! ( V_41 -> V_45 & V_53 ) , false ) ;
if ( V_88 ) {
if ( V_88 == - V_27 && V_41 -> V_45 & V_53 ) {
F_28 ( & V_24 ) ;
F_15 ( V_14 ) ;
return 0 ;
}
F_78 ( L_14 , V_12 -> V_13 ) ;
F_28 ( & V_24 ) ;
F_15 ( V_14 ) ;
return V_88 ;
}
V_35 = F_29 ( V_12 ) ;
F_28 ( & V_24 ) ;
if ( V_35 ) {
F_34 ( V_14 ) ;
F_35 ( V_35 ) ;
}
V_41 -> V_45 &= ~ V_53 ;
if ( ! F_44 ( V_14 , V_93 , V_41 -> V_50 ) )
V_41 -> V_45 |= V_51 ;
F_15 ( V_14 ) ;
F_37 ( V_14 ) ;
return 0 ;
}
static int F_79 ( char * V_7 , void * V_77 )
{
while ( ( void * ) V_7 < V_77 )
if ( ! * V_7 ++ )
return 0 ;
return - V_48 ;
}
static int F_80 ( struct V_40 * V_41 , T_2 V_52 )
{
int V_88 ;
char * V_43 = ( char * ) V_41 + V_41 -> V_58 ;
struct V_17 * V_14 ;
unsigned V_44 = ( V_41 -> V_45 & V_46 ) ? 1 : 0 ;
if ( V_43 < V_41 -> V_94 ||
F_79 ( V_43, ( void * ) V_41 + V_52 ) || ! * V_43 ||
strlen ( V_43 ) > ( V_44 ? V_95 - 1 : V_96 - 1 ) ) {
F_39 ( L_15 ) ;
return - V_48 ;
}
if ( ! V_44 ) {
V_88 = F_57 ( V_43 ) ;
if ( V_88 )
return V_88 ;
}
V_14 = F_42 ( V_41 , V_43 ) ;
if ( F_81 ( V_14 ) )
return F_82 ( V_14 ) ;
F_62 ( V_14 , V_41 ) ;
F_15 ( V_14 ) ;
return 0 ;
}
static int F_83 ( struct V_40 * V_41 , T_2 V_52 )
{
int V_88 = - V_48 , V_97 ;
struct V_17 * V_14 ;
struct V_98 V_99 ;
unsigned long V_100 [ 4 ] ;
char * V_101 = ( char * ) V_41 + V_41 -> V_58 ;
char V_102 ;
V_14 = F_76 ( V_41 ) ;
if ( ! V_14 )
return - V_47 ;
if ( V_101 < V_41 -> V_94 ||
F_79 ( V_101 , ( void * ) V_41 + V_52 ) ) {
F_39 ( L_16 ) ;
goto V_66;
}
V_97 = sscanf ( V_101 , L_17 , V_100 ,
V_100 + 1 , V_100 + 2 , V_100 + 3 , & V_102 ) ;
if ( V_97 != 4 ) {
F_39 ( L_18 ) ;
goto V_66;
}
if ( V_100 [ 0 ] > 65535 || V_100 [ 1 ] > 255 ||
V_100 [ 2 ] > 255 || V_100 [ 3 ] > V_103 ) {
F_39 ( L_19 ) ;
goto V_66;
}
V_99 . V_104 = V_100 [ 0 ] ;
V_99 . V_105 = V_100 [ 1 ] ;
V_99 . V_106 = V_100 [ 2 ] ;
V_99 . V_107 = V_100 [ 3 ] ;
V_88 = F_84 ( V_14 , & V_99 ) ;
V_41 -> V_54 = 0 ;
V_66:
F_15 ( V_14 ) ;
return V_88 ;
}
static int F_85 ( struct V_40 * V_41 )
{
int V_88 = 0 ;
unsigned V_108 = V_109 ;
struct V_17 * V_14 ;
V_14 = F_76 ( V_41 ) ;
if ( ! V_14 )
return - V_47 ;
if ( V_41 -> V_45 & V_110 )
V_108 &= ~ V_109 ;
if ( V_41 -> V_45 & V_111 )
V_108 |= V_112 ;
if ( ! F_63 ( V_14 ) ) {
V_88 = F_86 ( V_14 , V_108 ) ;
if ( V_88 )
goto V_66;
}
F_62 ( V_14 , V_41 ) ;
V_66:
F_15 ( V_14 ) ;
return V_88 ;
}
static int F_87 ( struct V_40 * V_41 )
{
int V_88 = 0 ;
unsigned V_108 = V_109 ;
struct V_11 * V_12 ;
struct V_17 * V_14 ;
struct V_28 * V_21 , * V_113 = NULL ;
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
V_41 -> V_45 &= ~ V_92 ;
F_28 ( & V_24 ) ;
if ( V_21 ) {
if ( V_41 -> V_45 & V_110 )
V_108 &= ~ V_109 ;
if ( V_41 -> V_45 & V_111 )
V_108 |= V_112 ;
if ( ! F_63 ( V_14 ) )
F_86 ( V_14 , V_108 ) ;
V_113 = F_88 ( V_14 , V_21 ) ;
if ( F_81 ( V_113 ) ) {
F_34 ( V_14 ) ;
F_35 ( V_21 ) ;
F_15 ( V_14 ) ;
return F_82 ( V_113 ) ;
}
if ( F_70 ( V_21 ) & V_87 )
F_89 ( F_50 ( V_14 ) , 0 ) ;
else
F_89 ( F_50 ( V_14 ) , 1 ) ;
}
if ( F_63 ( V_14 ) ) {
V_88 = F_90 ( V_14 ) ;
if ( ! V_88 && ! F_44 ( V_14 , V_49 , V_41 -> V_50 ) )
V_41 -> V_45 |= V_51 ;
}
if ( V_113 )
F_35 ( V_113 ) ;
if ( ! V_88 )
F_62 ( V_14 , V_41 ) ;
F_15 ( V_14 ) ;
return V_88 ;
}
static int F_91 ( struct V_40 * V_41 , T_2 V_52 )
{
if ( V_41 -> V_45 & V_81 )
return F_85 ( V_41 ) ;
return F_87 ( V_41 ) ;
}
static int F_92 ( struct V_40 * V_41 , T_2 V_52 )
{
struct V_17 * V_14 ;
V_14 = F_76 ( V_41 ) ;
if ( ! V_14 )
return - V_47 ;
F_62 ( V_14 , V_41 ) ;
F_15 ( V_14 ) ;
return 0 ;
}
static void F_93 ( struct V_28 * V_29 ,
struct V_40 * V_41 , T_2 V_52 )
{
unsigned int V_3 , V_114 ;
struct V_115 * V_116 ;
char * V_117 , * V_118 ;
T_3 type ;
T_2 V_119 , V_57 , V_120 = 0 ;
unsigned V_121 = 0 ;
V_118 = V_117 = F_48 ( V_41 , V_52 , & V_57 ) ;
if ( V_41 -> V_45 & V_122 )
type = V_123 ;
else
type = V_124 ;
V_114 = F_69 ( V_29 ) ;
for ( V_3 = 0 ; V_3 < V_114 ; V_3 ++ ) {
struct V_125 * V_126 = F_94 ( V_29 , V_3 ) ;
T_2 V_127 ;
V_119 = V_57 - ( V_118 - V_117 ) ;
if ( V_119 <= sizeof( struct V_115 ) ) {
V_41 -> V_45 |= V_65 ;
break;
}
V_116 = (struct V_115 * ) V_118 ;
V_116 -> V_128 = 0 ;
V_116 -> V_129 = V_126 -> V_130 ;
V_116 -> V_131 = V_126 -> V_57 ;
strncpy ( V_116 -> V_69 , V_126 -> type -> V_13 ,
sizeof( V_116 -> V_69 ) ) ;
V_118 += sizeof( struct V_115 ) ;
V_119 = V_57 - ( V_118 - V_117 ) ;
if ( V_119 <= 0 ) {
V_41 -> V_45 |= V_65 ;
break;
}
if ( V_126 -> type -> V_128 ) {
if ( V_41 -> V_45 & V_111 )
V_121 |= V_132 ;
V_126 -> type -> V_128 ( V_126 , type , V_121 , V_118 , V_119 ) ;
} else
V_118 [ 0 ] = '\0' ;
V_127 = strlen ( V_118 ) + 1 ;
if ( V_127 == V_119 ) {
V_41 -> V_45 |= V_65 ;
break;
}
V_118 += V_127 ;
V_120 = V_41 -> V_58 + ( V_118 - V_117 ) ;
V_118 = F_47 ( V_118 ) ;
V_116 -> V_67 = V_118 - V_117 ;
}
if ( V_120 )
V_41 -> V_54 = V_120 ;
V_41 -> V_86 = V_114 ;
}
static int F_95 ( struct V_40 * V_41 , T_2 V_52 )
{
int V_88 = 0 ;
struct V_17 * V_14 ;
struct V_28 * V_29 ;
int V_30 ;
V_14 = F_76 ( V_41 ) ;
if ( ! V_14 )
return - V_47 ;
if ( F_96 ( V_14 , V_41 -> V_50 ) ) {
V_88 = - V_133 ;
goto V_66;
}
F_62 ( V_14 , V_41 ) ;
V_29 = F_61 ( V_14 , V_41 , & V_30 ) ;
if ( V_29 )
F_93 ( V_29 , V_41 , V_52 ) ;
F_32 ( V_14 , V_30 ) ;
V_66:
F_15 ( V_14 ) ;
return V_88 ;
}
static inline T_4 F_97 ( struct V_40 * V_41 )
{
T_4 V_134 = V_135 | V_87 ;
if ( V_41 -> V_45 & V_82 )
V_134 = V_135 ;
return V_134 ;
}
static int F_98 ( struct V_115 * V_136 , V_68 V_67 , void * V_77 ,
struct V_115 * * V_116 , char * * V_137 )
{
* V_116 = (struct V_115 * ) ( ( unsigned char * ) V_136 + V_67 ) ;
* V_137 = ( char * ) ( * V_116 + 1 ) ;
if ( * V_116 < ( V_136 + 1 ) )
return - V_48 ;
return F_79 ( * V_137 , V_77 ) ;
}
static int F_99 ( struct V_28 * V_29 ,
struct V_40 * V_41 , T_2 V_52 )
{
int V_88 ;
unsigned int V_3 = 0 ;
struct V_115 * V_116 = (struct V_115 * ) V_41 ;
V_68 V_67 = V_41 -> V_58 ;
void * V_77 = ( void * ) V_41 + V_52 ;
char * V_137 ;
if ( ! V_41 -> V_86 ) {
F_39 ( L_20 ) ;
return - V_48 ;
}
for ( V_3 = 0 ; V_3 < V_41 -> V_86 ; V_3 ++ ) {
V_88 = F_98 ( V_116 , V_67 , V_77 , & V_116 , & V_137 ) ;
if ( V_88 ) {
F_39 ( L_21 ) ;
return V_88 ;
}
V_88 = F_100 ( V_29 , V_116 -> V_69 ,
( V_138 ) V_116 -> V_129 ,
( V_138 ) V_116 -> V_131 ,
V_137 ) ;
if ( V_88 ) {
F_39 ( L_22 ) ;
return V_88 ;
}
V_67 = V_116 -> V_67 ;
}
return F_101 ( V_29 ) ;
}
static int F_102 ( struct V_40 * V_41 , T_2 V_52 )
{
int V_88 ;
struct V_11 * V_12 ;
struct V_28 * V_35 , * V_113 = NULL ;
struct V_17 * V_14 ;
struct V_69 * V_139 ;
V_14 = F_76 ( V_41 ) ;
if ( ! V_14 )
return - V_47 ;
V_88 = F_103 ( & V_35 , F_97 ( V_41 ) , V_41 -> V_86 , V_14 ) ;
if ( V_88 )
goto V_140;
F_104 ( V_14 ) ;
V_88 = F_99 ( V_35 , V_41 , V_52 ) ;
if ( V_88 )
goto V_141;
V_139 = F_105 ( V_14 ) ;
if ( V_139 &&
( V_139 != F_106 ( V_35 ) ) ) {
F_39 ( L_23 ,
V_139 -> V_13 ) ;
V_88 = - V_48 ;
goto V_141;
}
if ( F_107 ( V_14 ) == V_142 ) {
F_108 ( V_14 , F_109 ( V_35 ) ) ;
V_88 = F_110 ( V_14 ) ;
if ( V_88 ) {
F_39 ( L_24 ) ;
goto V_141;
}
} else if ( F_107 ( V_14 ) != F_109 ( V_35 ) ) {
F_39 ( L_25 ) ;
V_88 = - V_48 ;
goto V_141;
}
F_111 ( V_14 ) ;
F_22 ( & V_24 ) ;
V_12 = F_14 ( V_14 ) ;
if ( ! V_12 || V_12 -> V_14 != V_14 ) {
F_39 ( L_12 ) ;
F_28 ( & V_24 ) ;
V_88 = - V_47 ;
goto V_143;
}
if ( V_12 -> V_21 )
V_113 = V_12 -> V_21 ;
V_12 -> V_21 = V_35 ;
F_28 ( & V_24 ) ;
V_41 -> V_45 |= V_92 ;
F_62 ( V_14 , V_41 ) ;
if ( V_113 ) {
F_34 ( V_14 ) ;
F_35 ( V_113 ) ;
}
F_15 ( V_14 ) ;
return 0 ;
V_141:
F_111 ( V_14 ) ;
V_143:
F_35 ( V_35 ) ;
V_140:
F_15 ( V_14 ) ;
return V_88 ;
}
static int F_112 ( struct V_40 * V_41 , T_2 V_52 )
{
struct V_11 * V_12 ;
struct V_17 * V_14 ;
struct V_28 * V_113 = NULL ;
F_22 ( & V_24 ) ;
V_12 = F_74 ( V_41 ) ;
if ( ! V_12 ) {
F_78 ( L_13 ) ;
F_28 ( & V_24 ) ;
return - V_47 ;
}
if ( V_12 -> V_21 ) {
V_113 = V_12 -> V_21 ;
V_12 -> V_21 = NULL ;
}
V_41 -> V_45 &= ~ V_92 ;
F_62 ( V_12 -> V_14 , V_41 ) ;
V_14 = V_12 -> V_14 ;
F_28 ( & V_24 ) ;
if ( V_113 ) {
F_34 ( V_14 ) ;
F_35 ( V_113 ) ;
}
F_15 ( V_14 ) ;
return 0 ;
}
static void F_113 ( struct V_28 * V_29 ,
struct V_40 * V_41 , T_2 V_52 )
{
unsigned int V_144 = 0 ;
struct V_1 * V_145 ;
T_2 V_57 , V_59 ;
struct V_146 * V_147 ;
struct V_148 * V_149 ;
V_149 = F_48 ( V_41 , V_52 , & V_57 ) ;
F_114 (tmp, dm_table_get_devices(table))
V_144 ++ ;
V_59 = sizeof( * V_149 ) + ( sizeof( * V_149 -> V_16 ) * V_144 ) ;
if ( V_57 < V_59 ) {
V_41 -> V_45 |= V_65 ;
return;
}
V_149 -> V_144 = V_144 ;
V_144 = 0 ;
F_8 (dd, dm_table_get_devices(table), list)
V_149 -> V_16 [ V_144 ++ ] = F_51 ( V_147 -> V_150 -> V_151 -> V_152 ) ;
V_41 -> V_54 = V_41 -> V_58 + V_59 ;
}
static int F_115 ( struct V_40 * V_41 , T_2 V_52 )
{
struct V_17 * V_14 ;
struct V_28 * V_29 ;
int V_30 ;
V_14 = F_76 ( V_41 ) ;
if ( ! V_14 )
return - V_47 ;
F_62 ( V_14 , V_41 ) ;
V_29 = F_61 ( V_14 , V_41 , & V_30 ) ;
if ( V_29 )
F_113 ( V_29 , V_41 , V_52 ) ;
F_32 ( V_14 , V_30 ) ;
F_15 ( V_14 ) ;
return 0 ;
}
static int F_116 ( struct V_40 * V_41 , T_2 V_52 )
{
struct V_17 * V_14 ;
struct V_28 * V_29 ;
int V_30 ;
V_14 = F_76 ( V_41 ) ;
if ( ! V_14 )
return - V_47 ;
F_62 ( V_14 , V_41 ) ;
V_29 = F_61 ( V_14 , V_41 , & V_30 ) ;
if ( V_29 )
F_93 ( V_29 , V_41 , V_52 ) ;
F_32 ( V_14 , V_30 ) ;
F_15 ( V_14 ) ;
return 0 ;
}
static int F_117 ( struct V_17 * V_14 , unsigned V_153 , char * * V_154 ,
char * V_155 , unsigned V_156 )
{
int V_88 ;
if ( * * V_154 != '@' )
return 2 ;
if ( ! strcasecmp ( V_154 [ 0 ] , L_26 ) ) {
if ( V_153 != 1 ) {
F_118 ( L_27 ) ;
return - V_48 ;
}
return F_119 ( V_14 ) ;
}
V_88 = F_120 ( V_14 , V_153 , V_154 , V_155 , V_156 ) ;
if ( V_88 < 2 )
return V_88 ;
F_118 ( L_28 , V_154 [ 0 ] ) ;
return - V_48 ;
}
static int F_121 ( struct V_40 * V_41 , T_2 V_52 )
{
int V_88 , V_153 ;
char * * V_154 ;
struct V_17 * V_14 ;
struct V_28 * V_29 ;
struct V_125 * V_126 ;
struct V_157 * V_158 = ( void * ) V_41 + V_41 -> V_58 ;
T_2 V_156 ;
char * V_155 = F_48 ( V_41 , V_52 , & V_156 ) ;
int V_30 ;
V_14 = F_76 ( V_41 ) ;
if ( ! V_14 )
return - V_47 ;
if ( V_158 < (struct V_157 * ) V_41 -> V_94 ||
F_79 ( V_158 -> V_159 , ( void * ) V_41 + V_52 ) ) {
F_39 ( L_29 ) ;
V_88 = - V_48 ;
goto V_66;
}
V_88 = F_122 ( & V_153 , & V_154 , V_158 -> V_159 ) ;
if ( V_88 ) {
F_39 ( L_30 ) ;
goto V_66;
}
if ( ! V_153 ) {
F_39 ( L_31 ) ;
goto V_160;
}
V_88 = F_117 ( V_14 , V_153 , V_154 , V_155 , V_156 ) ;
if ( V_88 <= 1 )
goto V_160;
V_29 = F_30 ( V_14 , & V_30 ) ;
if ( ! V_29 )
goto V_161;
if ( F_123 ( V_14 ) ) {
V_88 = - V_47 ;
goto V_161;
}
V_126 = F_124 ( V_29 , V_158 -> V_162 ) ;
if ( ! F_125 ( V_126 ) ) {
F_39 ( L_32 ) ;
V_88 = - V_48 ;
} else if ( V_126 -> type -> V_159 )
V_88 = V_126 -> type -> V_159 ( V_126 , V_153 , V_154 ) ;
else {
F_39 ( L_33 ) ;
V_88 = - V_48 ;
}
V_161:
F_32 ( V_14 , V_30 ) ;
V_160:
F_19 ( V_154 ) ;
V_66:
if ( V_88 >= 0 )
F_62 ( V_14 , V_41 ) ;
if ( V_88 == 1 ) {
V_41 -> V_45 |= V_163 ;
if ( F_126 ( V_155 , V_156 ) )
V_41 -> V_45 |= V_65 ;
else
V_41 -> V_54 = V_41 -> V_58 + strlen ( V_155 ) + 1 ;
V_88 = 0 ;
}
F_15 ( V_14 ) ;
return V_88 ;
}
static T_5 F_127 ( unsigned int V_164 , int * V_165 )
{
static struct {
int V_164 ;
int V_45 ;
T_5 V_166 ;
} V_167 [] = {
{ V_168 , 0 , NULL } ,
{ V_169 , V_170 , F_46 } ,
{ V_171 , 0 , F_49 } ,
{ V_172 , V_170 , F_71 } ,
{ V_173 , V_170 , F_77 } ,
{ V_174 , 0 , F_80 } ,
{ V_175 , V_170 , F_91 } ,
{ V_176 , V_170 , F_92 } ,
{ V_177 , 0 , F_95 } ,
{ V_178 , 0 , F_102 } ,
{ V_179 , V_170 , F_112 } ,
{ V_180 , 0 , F_115 } ,
{ V_181 , 0 , F_116 } ,
{ V_182 , 0 , F_55 } ,
{ V_183 , 0 , F_121 } ,
{ V_184 , 0 , F_83 }
} ;
if ( F_128 ( V_164 >= F_129 ( V_167 ) ) )
return NULL ;
* V_165 = V_167 [ V_164 ] . V_45 ;
return V_167 [ V_164 ] . V_166 ;
}
static int F_130 ( unsigned int V_164 , struct V_40 T_6 * V_185 )
{
V_68 V_76 [ 3 ] ;
int V_88 = 0 ;
if ( F_131 ( V_76 , V_185 -> V_76 , sizeof( V_76 ) ) )
return - V_186 ;
if ( ( V_187 != V_76 [ 0 ] ) ||
( V_188 < V_76 [ 1 ] ) ) {
F_39 ( L_34
L_35 ,
V_187 , V_188 ,
V_189 ,
V_76 [ 0 ] , V_76 [ 1 ] , V_76 [ 2 ] , V_164 ) ;
V_88 = - V_48 ;
}
V_76 [ 0 ] = V_187 ;
V_76 [ 1 ] = V_188 ;
V_76 [ 2 ] = V_189 ;
if ( F_132 ( V_185 -> V_76 , V_76 , sizeof( V_76 ) ) )
return - V_186 ;
return V_88 ;
}
static void F_133 ( struct V_40 * V_41 , T_2 V_52 , int V_190 )
{
if ( V_190 & V_191 )
memset ( V_41 , 0 , V_52 ) ;
if ( V_190 & V_192 )
F_19 ( V_41 ) ;
if ( V_190 & V_193 )
F_134 ( V_41 ) ;
}
static int F_135 ( struct V_40 T_6 * V_185 , struct V_40 * V_194 ,
int V_165 ,
struct V_40 * * V_41 , int * V_190 )
{
struct V_40 * V_195 ;
int V_196 ;
const T_2 V_197 = sizeof( * V_194 ) - sizeof( V_194 -> V_94 ) ;
if ( F_131 ( V_194 , V_185 , V_197 ) )
return - V_186 ;
if ( V_194 -> V_54 < V_197 )
return - V_48 ;
V_196 = V_194 -> V_45 & V_198 ;
* V_190 = V_196 ? V_191 : 0 ;
if ( V_165 & V_170 ) {
V_195 = V_194 ;
V_195 -> V_54 = V_197 ;
goto V_199;
}
V_195 = NULL ;
if ( V_194 -> V_54 <= V_200 ) {
V_195 = F_17 ( V_194 -> V_54 , V_201 | V_202 | V_203 | V_204 ) ;
if ( V_195 )
* V_190 |= V_192 ;
}
if ( ! V_195 ) {
unsigned V_205 ;
V_205 = F_136 () ;
V_195 = F_137 ( V_194 -> V_54 , V_201 | V_206 | V_207 | V_208 , V_209 ) ;
F_138 ( V_205 ) ;
if ( V_195 )
* V_190 |= V_193 ;
}
if ( ! V_195 ) {
if ( V_196 && F_139 ( V_185 , V_194 -> V_54 ) )
return - V_186 ;
return - V_23 ;
}
if ( F_131 ( V_195 , V_185 , V_194 -> V_54 ) )
goto V_25;
V_199:
if ( V_195 -> V_54 != V_194 -> V_54 ) {
F_118 ( L_36 ) ;
goto V_25;
}
if ( V_196 && F_139 ( V_185 , V_194 -> V_54 ) )
goto V_25;
* V_41 = V_195 ;
return 0 ;
V_25:
F_133 ( V_195 , V_194 -> V_54 , * V_190 ) ;
return - V_186 ;
}
static int F_140 ( T_7 V_164 , struct V_40 * V_41 )
{
V_41 -> V_45 &= ~ V_65 ;
V_41 -> V_45 &= ~ V_51 ;
V_41 -> V_45 &= ~ V_198 ;
V_41 -> V_45 &= ~ V_163 ;
if ( V_164 == V_169 ||
V_164 == V_171 ||
V_164 == V_182 )
return 0 ;
if ( ( V_164 == V_172 ) ) {
if ( ! * V_41 -> V_13 ) {
F_39 ( L_37 ) ;
return - V_48 ;
}
} else if ( ( * V_41 -> V_15 && * V_41 -> V_13 ) ) {
F_39 ( L_38 , V_164 ) ;
return - V_48 ;
}
V_41 -> V_13 [ V_96 - 1 ] = '\0' ;
V_41 -> V_15 [ V_95 - 1 ] = '\0' ;
return 0 ;
}
static int F_141 ( T_7 V_210 , struct V_40 T_6 * V_185 )
{
int V_88 = 0 ;
int V_165 ;
int V_190 ;
unsigned int V_164 ;
struct V_40 * V_211 ( V_41 ) ;
T_5 V_166 = NULL ;
T_2 V_212 ;
struct V_40 V_194 ;
if ( ! F_142 ( V_213 ) )
return - V_214 ;
if ( F_143 ( V_210 ) != V_215 )
return - V_216 ;
V_164 = F_144 ( V_210 ) ;
V_88 = F_130 ( V_164 , V_185 ) ;
if ( V_88 )
return V_88 ;
if ( V_164 == V_168 )
return 0 ;
V_166 = F_127 ( V_164 , & V_165 ) ;
if ( ! V_166 ) {
F_39 ( L_39 , V_210 ) ;
return - V_216 ;
}
V_88 = F_135 ( V_185 , & V_194 , V_165 , & V_41 , & V_190 ) ;
if ( V_88 )
return V_88 ;
V_212 = V_41 -> V_54 ;
V_88 = F_140 ( V_164 , V_41 ) ;
if ( V_88 )
goto V_66;
V_41 -> V_54 = sizeof( * V_41 ) ;
V_88 = V_166 ( V_41 , V_212 ) ;
if ( F_128 ( V_41 -> V_45 & V_65 ) &&
F_128 ( V_165 & V_170 ) )
F_118 ( L_40 , V_164 ) ;
if ( ! V_88 && F_132 ( V_185 , V_41 , V_41 -> V_54 ) )
V_88 = - V_186 ;
V_66:
F_133 ( V_41 , V_212 , V_190 ) ;
return V_88 ;
}
static long F_145 ( struct V_217 * V_217 , T_7 V_210 , T_8 V_218 )
{
return ( long ) F_141 ( V_210 , (struct V_40 T_6 * ) V_218 ) ;
}
static long F_146 ( struct V_217 * V_217 , T_7 V_210 , T_8 V_218 )
{
return ( long ) F_145 ( V_217 , V_210 , ( T_8 ) F_147 ( V_218 ) ) ;
}
int T_9 F_148 ( void )
{
int V_88 ;
V_88 = F_3 () ;
if ( V_88 )
return V_88 ;
V_88 = F_149 ( & V_219 ) ;
if ( V_88 ) {
F_118 ( L_41 ) ;
F_4 () ;
return V_88 ;
}
F_150 ( L_42 , V_187 ,
V_188 , V_189 , V_220 ,
V_221 ) ;
return 0 ;
}
void F_151 ( void )
{
if ( F_152 ( & V_219 ) < 0 )
F_118 ( L_43 ) ;
F_4 () ;
}
int F_153 ( struct V_17 * V_14 , char * V_13 , char * V_15 )
{
int V_88 = 0 ;
struct V_11 * V_12 ;
if ( ! V_14 )
return - V_47 ;
F_25 ( & V_26 ) ;
V_12 = F_14 ( V_14 ) ;
if ( ! V_12 || V_12 -> V_14 != V_14 ) {
V_88 = - V_47 ;
goto V_66;
}
if ( V_13 )
strcpy ( V_13 , V_12 -> V_13 ) ;
if ( V_15 )
strcpy ( V_15 , V_12 -> V_15 ? : L_8 ) ;
V_66:
F_27 ( & V_26 ) ;
return V_88 ;
}
