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
static struct V_11 * F_11 ( const char * V_13 , const char * V_15 ,
struct V_16 * V_14 )
{
struct V_11 * V_12 ;
V_12 = F_12 ( sizeof( * V_12 ) , V_17 ) ;
if ( ! V_12 )
return NULL ;
V_12 -> V_13 = F_13 ( V_13 , V_17 ) ;
if ( ! V_12 -> V_13 ) {
F_14 ( V_12 ) ;
return NULL ;
}
if ( ! V_15 )
V_12 -> V_15 = NULL ;
else {
V_12 -> V_15 = F_13 ( V_15 , V_17 ) ;
if ( ! V_12 -> V_15 ) {
F_14 ( V_12 -> V_13 ) ;
F_14 ( V_12 ) ;
return NULL ;
}
}
F_2 ( & V_12 -> V_18 ) ;
F_2 ( & V_12 -> V_19 ) ;
V_12 -> V_14 = V_14 ;
V_12 -> V_20 = NULL ;
return V_12 ;
}
static void F_15 ( struct V_11 * V_12 )
{
if ( V_12 ) {
F_14 ( V_12 -> V_13 ) ;
F_14 ( V_12 -> V_15 ) ;
F_14 ( V_12 ) ;
}
}
static int F_16 ( const char * V_13 , const char * V_15 , struct V_16 * V_14 )
{
struct V_11 * V_21 , * V_12 ;
V_21 = F_11 ( V_13 , V_15 , V_14 ) ;
if ( ! V_21 )
return - V_22 ;
F_17 ( & V_23 ) ;
V_12 = F_7 ( V_13 ) ;
if ( V_12 ) {
F_18 ( V_12 -> V_14 ) ;
goto V_24;
}
F_19 ( & V_21 -> V_18 , V_5 + F_6 ( V_13 ) ) ;
if ( V_15 ) {
V_12 = F_10 ( V_15 ) ;
if ( V_12 ) {
F_20 ( & V_21 -> V_18 ) ;
F_18 ( V_12 -> V_14 ) ;
goto V_24;
}
F_19 ( & V_21 -> V_19 , V_6 + F_6 ( V_15 ) ) ;
}
F_9 ( V_14 ) ;
F_21 ( & V_25 ) ;
F_22 ( V_14 , V_21 ) ;
F_23 ( & V_25 ) ;
F_24 ( & V_23 ) ;
return 0 ;
V_24:
F_24 ( & V_23 ) ;
F_15 ( V_21 ) ;
return - V_26 ;
}
static void F_25 ( struct V_11 * V_12 )
{
struct V_27 * V_28 ;
F_20 ( & V_12 -> V_19 ) ;
F_20 ( & V_12 -> V_18 ) ;
F_21 ( & V_25 ) ;
F_22 ( V_12 -> V_14 , NULL ) ;
F_23 ( & V_25 ) ;
V_28 = F_26 ( V_12 -> V_14 ) ;
if ( V_28 ) {
F_27 ( V_28 ) ;
F_28 ( V_28 ) ;
}
if ( V_12 -> V_20 )
F_29 ( V_12 -> V_20 ) ;
F_18 ( V_12 -> V_14 ) ;
F_15 ( V_12 ) ;
}
static void F_5 ( int V_29 )
{
int V_3 , V_30 ;
struct V_11 * V_12 ;
struct V_16 * V_14 ;
V_31:
V_30 = 0 ;
F_17 ( & V_23 ) ;
for ( V_3 = 0 ; V_3 < V_4 ; V_3 ++ ) {
F_8 (hc, _name_buckets + i, name_list) {
V_14 = V_12 -> V_14 ;
F_9 ( V_14 ) ;
if ( V_29 && F_30 ( V_14 ) ) {
F_18 ( V_14 ) ;
V_30 ++ ;
continue;
}
F_25 ( V_12 ) ;
F_24 ( & V_23 ) ;
F_18 ( V_14 ) ;
if ( F_31 ( V_29 ) )
F_32 ( V_14 ) ;
else
F_33 ( V_14 ) ;
goto V_31;
}
}
F_24 ( & V_23 ) ;
if ( V_30 )
F_34 ( L_1 , V_30 ) ;
}
static void F_35 ( struct V_11 * V_12 , char * V_32 )
{
F_21 ( & V_25 ) ;
V_12 -> V_15 = V_32 ;
F_23 ( & V_25 ) ;
F_19 ( & V_12 -> V_19 , V_6 + F_6 ( V_32 ) ) ;
}
static char * F_36 ( struct V_11 * V_12 , char * V_33 )
{
char * V_34 ;
F_20 ( & V_12 -> V_18 ) ;
V_34 = V_12 -> V_13 ;
F_21 ( & V_25 ) ;
V_12 -> V_13 = V_33 ;
F_23 ( & V_25 ) ;
F_19 ( & V_12 -> V_18 , V_5 + F_6 ( V_33 ) ) ;
return V_34 ;
}
static struct V_16 * F_37 ( struct V_35 * V_36 ,
const char * V_37 )
{
char * V_38 , * V_34 = NULL ;
struct V_11 * V_12 ;
struct V_27 * V_28 ;
struct V_16 * V_14 ;
unsigned V_39 = ( V_36 -> V_40 & V_41 ) ? 1 : 0 ;
V_38 = F_13 ( V_37 , V_17 ) ;
if ( ! V_38 )
return F_38 ( - V_22 ) ;
F_17 ( & V_23 ) ;
if ( V_39 )
V_12 = F_10 ( V_37 ) ;
else
V_12 = F_7 ( V_37 ) ;
if ( V_12 ) {
F_34 ( L_2
L_3 ,
V_39 ? L_4 : L_5 ,
V_36 -> V_13 , V_37 ) ;
F_18 ( V_12 -> V_14 ) ;
F_24 ( & V_23 ) ;
F_14 ( V_38 ) ;
return F_38 ( - V_26 ) ;
}
V_12 = F_7 ( V_36 -> V_13 ) ;
if ( ! V_12 ) {
F_34 ( L_6 ,
V_36 -> V_13 , V_39 ? L_7 : L_8 , V_37 ) ;
F_24 ( & V_23 ) ;
F_14 ( V_38 ) ;
return F_38 ( - V_42 ) ;
}
if ( V_39 && V_12 -> V_15 ) {
F_34 ( L_9
L_10 ,
V_36 -> V_13 , V_37 , V_12 -> V_15 ) ;
F_18 ( V_12 -> V_14 ) ;
F_24 ( & V_23 ) ;
F_14 ( V_38 ) ;
return F_38 ( - V_43 ) ;
}
if ( V_39 )
F_35 ( V_12 , V_38 ) ;
else
V_34 = F_36 ( V_12 , V_38 ) ;
V_28 = F_26 ( V_12 -> V_14 ) ;
if ( V_28 ) {
F_27 ( V_28 ) ;
F_28 ( V_28 ) ;
}
if ( ! F_39 ( V_12 -> V_14 , V_44 , V_36 -> V_45 ) )
V_36 -> V_40 |= V_46 ;
V_14 = V_12 -> V_14 ;
F_24 ( & V_23 ) ;
F_14 ( V_34 ) ;
return V_14 ;
}
static int F_40 ( struct V_35 * V_36 , T_1 V_47 )
{
F_5 ( 1 ) ;
V_36 -> V_48 = 0 ;
return 0 ;
}
static inline void * F_41 ( void * V_49 )
{
return ( void * ) ( ( ( T_1 ) ( V_49 + V_50 ) ) & ~ V_50 ) ;
}
static void * F_42 ( struct V_35 * V_36 , T_1 V_47 ,
T_1 * V_51 )
{
V_36 -> V_52 = F_41 ( V_36 + 1 ) - ( void * ) V_36 ;
if ( V_36 -> V_52 < V_47 )
* V_51 = V_47 - V_36 -> V_52 ;
else
* V_51 = 0 ;
return ( ( void * ) V_36 ) + V_36 -> V_52 ;
}
static int F_43 ( struct V_35 * V_36 , T_1 V_47 )
{
unsigned int V_3 ;
struct V_11 * V_12 ;
T_1 V_51 , V_53 = 0 ;
struct V_54 * V_55 ;
struct V_56 * V_57 , * V_58 = NULL ;
F_17 ( & V_23 ) ;
for ( V_3 = 0 ; V_3 < V_4 ; V_3 ++ ) {
F_8 (hc, _name_buckets + i, name_list) {
V_53 += sizeof( struct V_56 ) ;
V_53 += strlen ( V_12 -> V_13 ) + 1 ;
V_53 += V_50 ;
}
}
V_57 = F_42 ( V_36 , V_47 , & V_51 ) ;
if ( V_51 < V_53 ) {
V_36 -> V_40 |= V_59 ;
goto V_60;
}
V_36 -> V_48 = V_36 -> V_52 + V_53 ;
V_57 -> V_61 = 0 ;
for ( V_3 = 0 ; V_3 < V_4 ; V_3 ++ ) {
F_8 (hc, _name_buckets + i, name_list) {
if ( V_58 )
V_58 -> V_62 = ( V_63 ) ( ( void * ) V_57 -
( void * ) V_58 ) ;
V_55 = F_44 ( V_12 -> V_14 ) ;
V_57 -> V_61 = F_45 ( F_46 ( V_55 ) ) ;
V_57 -> V_62 = 0 ;
strcpy ( V_57 -> V_13 , V_12 -> V_13 ) ;
V_58 = V_57 ;
V_57 = F_41 ( ( ( void * ) ++ V_57 ) + strlen ( V_12 -> V_13 ) + 1 ) ;
}
}
V_60:
F_24 ( & V_23 ) ;
return 0 ;
}
static void F_47 ( struct V_64 * V_65 , void * V_66 )
{
T_1 * V_53 = V_66 ;
* V_53 += sizeof( struct V_67 ) ;
* V_53 += strlen ( V_65 -> V_13 ) ;
* V_53 += V_50 ;
}
static void F_48 ( struct V_64 * V_65 , void * V_36 )
{
struct V_68 * V_69 = V_36 ;
if ( ( char * ) V_69 -> V_70 + sizeof( V_65 -> V_71 ) + strlen ( V_65 -> V_13 ) + 1 >
V_69 -> V_72 ) {
V_69 -> V_40 = V_59 ;
return;
}
if ( V_69 -> V_73 )
V_69 -> V_73 -> V_62 = ( V_63 ) ( ( void * ) V_69 -> V_70 -
( void * ) V_69 -> V_73 ) ;
V_69 -> V_70 -> V_71 [ 0 ] = V_65 -> V_71 [ 0 ] ;
V_69 -> V_70 -> V_71 [ 1 ] = V_65 -> V_71 [ 1 ] ;
V_69 -> V_70 -> V_71 [ 2 ] = V_65 -> V_71 [ 2 ] ;
V_69 -> V_70 -> V_62 = 0 ;
strcpy ( V_69 -> V_70 -> V_13 , V_65 -> V_13 ) ;
V_69 -> V_73 = V_69 -> V_70 ;
V_69 -> V_70 = F_41 ( ( ( void * ) ++ V_69 -> V_70 ) + strlen ( V_65 -> V_13 ) + 1 ) ;
}
static int F_49 ( struct V_35 * V_36 , T_1 V_47 )
{
T_1 V_51 , V_53 = 0 ;
struct V_67 * V_70 ;
struct V_68 V_74 ;
F_50 ( F_47 , & V_53 ) ;
V_70 = F_42 ( V_36 , V_47 , & V_51 ) ;
if ( V_51 < V_53 ) {
V_36 -> V_40 |= V_59 ;
goto V_60;
}
V_36 -> V_48 = V_36 -> V_52 + V_53 ;
V_74 . V_47 = V_47 ;
V_74 . V_73 = NULL ;
V_74 . V_70 = V_70 ;
V_74 . V_40 = 0 ;
V_74 . V_72 = ( char * ) V_70 + V_51 ;
F_50 ( F_48 , & V_74 ) ;
V_36 -> V_40 |= V_74 . V_40 ;
V_60:
return 0 ;
}
static int F_51 ( const char * V_13 )
{
if ( strchr ( V_13 , '/' ) ) {
F_34 ( L_11 ) ;
return - V_43 ;
}
return 0 ;
}
static struct V_27 * F_52 ( struct V_16 * V_14 )
{
struct V_11 * V_12 ;
struct V_27 * V_28 = NULL ;
F_53 ( & V_23 ) ;
V_12 = F_54 ( V_14 ) ;
if ( ! V_12 || V_12 -> V_14 != V_14 ) {
F_34 ( L_12 ) ;
goto V_60;
}
V_28 = V_12 -> V_20 ;
if ( V_28 )
F_55 ( V_28 ) ;
V_60:
F_56 ( & V_23 ) ;
return V_28 ;
}
static struct V_27 * F_57 ( struct V_16 * V_14 ,
struct V_35 * V_36 )
{
return ( V_36 -> V_40 & V_75 ) ?
F_52 ( V_14 ) : F_26 ( V_14 ) ;
}
static void F_58 ( struct V_16 * V_14 , struct V_35 * V_36 )
{
struct V_54 * V_55 = F_44 ( V_14 ) ;
struct V_27 * V_28 ;
V_36 -> V_40 &= ~ ( V_76 | V_77 |
V_78 ) ;
if ( F_59 ( V_14 ) )
V_36 -> V_40 |= V_76 ;
V_36 -> V_61 = F_45 ( F_46 ( V_55 ) ) ;
V_36 -> V_79 = F_60 ( V_14 ) ;
V_36 -> V_45 = F_61 ( V_14 ) ;
V_36 -> V_80 = 0 ;
V_28 = F_26 ( V_14 ) ;
if ( V_28 ) {
if ( ! ( V_36 -> V_40 & V_75 ) ) {
if ( F_62 ( V_55 ) )
V_36 -> V_40 |= V_77 ;
V_36 -> V_80 = F_63 ( V_28 ) ;
}
F_28 ( V_28 ) ;
V_36 -> V_40 |= V_78 ;
}
if ( V_36 -> V_40 & V_75 ) {
V_28 = F_52 ( V_14 ) ;
if ( V_28 ) {
if ( ! ( F_64 ( V_28 ) & V_81 ) )
V_36 -> V_40 |= V_77 ;
V_36 -> V_80 = F_63 ( V_28 ) ;
F_28 ( V_28 ) ;
}
}
}
static int F_65 ( struct V_35 * V_36 , T_1 V_47 )
{
int V_82 , V_83 = V_84 ;
struct V_16 * V_14 ;
V_82 = F_51 ( V_36 -> V_13 ) ;
if ( V_82 )
return V_82 ;
if ( V_36 -> V_40 & V_85 )
V_83 = F_66 ( F_67 ( V_36 -> V_61 ) ) ;
V_82 = F_68 ( V_83 , & V_14 ) ;
if ( V_82 )
return V_82 ;
V_82 = F_16 ( V_36 -> V_13 , * V_36 -> V_15 ? V_36 -> V_15 : NULL , V_14 ) ;
if ( V_82 ) {
F_18 ( V_14 ) ;
F_32 ( V_14 ) ;
return V_82 ;
}
V_36 -> V_40 &= ~ V_86 ;
F_58 ( V_14 , V_36 ) ;
F_18 ( V_14 ) ;
return 0 ;
}
static struct V_11 * F_69 ( struct V_35 * V_36 )
{
struct V_16 * V_14 ;
void * V_87 = NULL ;
if ( * V_36 -> V_15 )
return F_10 ( V_36 -> V_15 ) ;
if ( * V_36 -> V_13 )
return F_7 ( V_36 -> V_13 ) ;
V_14 = F_70 ( F_67 ( V_36 -> V_61 ) ) ;
if ( ! V_14 )
goto V_60;
V_87 = F_54 ( V_14 ) ;
if ( ! V_87 )
F_18 ( V_14 ) ;
V_60:
return V_87 ;
}
static struct V_16 * F_71 ( struct V_35 * V_36 )
{
struct V_11 * V_12 ;
struct V_16 * V_14 = NULL ;
F_53 ( & V_23 ) ;
V_12 = F_69 ( V_36 ) ;
if ( V_12 ) {
V_14 = V_12 -> V_14 ;
F_72 ( V_36 -> V_13 , V_12 -> V_13 , sizeof( V_36 -> V_13 ) ) ;
if ( V_12 -> V_15 )
F_72 ( V_36 -> V_15 , V_12 -> V_15 , sizeof( V_36 -> V_15 ) ) ;
else
V_36 -> V_15 [ 0 ] = '\0' ;
if ( V_12 -> V_20 )
V_36 -> V_40 |= V_86 ;
else
V_36 -> V_40 &= ~ V_86 ;
}
F_56 ( & V_23 ) ;
return V_14 ;
}
static int F_73 ( struct V_35 * V_36 , T_1 V_47 )
{
struct V_11 * V_12 ;
struct V_16 * V_14 ;
int V_82 ;
F_17 ( & V_23 ) ;
V_12 = F_69 ( V_36 ) ;
if ( ! V_12 ) {
F_74 ( L_13 ) ;
F_24 ( & V_23 ) ;
return - V_42 ;
}
V_14 = V_12 -> V_14 ;
V_82 = F_30 ( V_14 ) ;
if ( V_82 ) {
F_74 ( L_14 , V_12 -> V_13 ) ;
F_24 ( & V_23 ) ;
F_18 ( V_14 ) ;
return V_82 ;
}
F_25 ( V_12 ) ;
F_24 ( & V_23 ) ;
if ( ! F_39 ( V_14 , V_88 , V_36 -> V_45 ) )
V_36 -> V_40 |= V_46 ;
F_18 ( V_14 ) ;
F_32 ( V_14 ) ;
return 0 ;
}
static int F_75 ( char * V_7 , void * V_72 )
{
while ( ( void * ) V_7 < V_72 )
if ( ! * V_7 ++ )
return 0 ;
return - V_43 ;
}
static int F_76 ( struct V_35 * V_36 , T_1 V_47 )
{
int V_82 ;
char * V_38 = ( char * ) V_36 + V_36 -> V_52 ;
struct V_16 * V_14 ;
unsigned V_39 = ( V_36 -> V_40 & V_41 ) ? 1 : 0 ;
if ( V_38 < V_36 -> V_89 ||
F_75 ( V_38, ( void * ) V_36 + V_47 ) ||
strlen ( V_38 ) > ( V_39 ? V_90 - 1 : V_91 - 1 ) ) {
F_34 ( L_15 ) ;
return - V_43 ;
}
if ( ! V_39 ) {
V_82 = F_51 ( V_38 ) ;
if ( V_82 )
return V_82 ;
}
V_14 = F_37 ( V_36 , V_38 ) ;
if ( F_77 ( V_14 ) )
return F_78 ( V_14 ) ;
F_58 ( V_14 , V_36 ) ;
F_18 ( V_14 ) ;
return 0 ;
}
static int F_79 ( struct V_35 * V_36 , T_1 V_47 )
{
int V_82 = - V_43 , V_92 ;
struct V_16 * V_14 ;
struct V_93 V_94 ;
unsigned long V_95 [ 4 ] ;
char * V_96 = ( char * ) V_36 + V_36 -> V_52 ;
V_14 = F_71 ( V_36 ) ;
if ( ! V_14 )
return - V_42 ;
if ( V_96 < V_36 -> V_89 ||
F_75 ( V_96 , ( void * ) V_36 + V_47 ) ) {
F_34 ( L_16 ) ;
goto V_60;
}
V_92 = sscanf ( V_96 , L_17 , V_95 ,
V_95 + 1 , V_95 + 2 , V_95 + 3 ) ;
if ( V_92 != 4 ) {
F_34 ( L_18 ) ;
goto V_60;
}
if ( V_95 [ 0 ] > 65535 || V_95 [ 1 ] > 255 ||
V_95 [ 2 ] > 255 || V_95 [ 3 ] > V_97 ) {
F_34 ( L_19 ) ;
goto V_60;
}
V_94 . V_98 = V_95 [ 0 ] ;
V_94 . V_99 = V_95 [ 1 ] ;
V_94 . V_100 = V_95 [ 2 ] ;
V_94 . V_101 = V_95 [ 3 ] ;
V_82 = F_80 ( V_14 , & V_94 ) ;
V_36 -> V_48 = 0 ;
V_60:
F_18 ( V_14 ) ;
return V_82 ;
}
static int F_81 ( struct V_35 * V_36 )
{
int V_82 = 0 ;
unsigned V_102 = V_103 ;
struct V_16 * V_14 ;
V_14 = F_71 ( V_36 ) ;
if ( ! V_14 )
return - V_42 ;
if ( V_36 -> V_40 & V_104 )
V_102 &= ~ V_103 ;
if ( V_36 -> V_40 & V_105 )
V_102 |= V_106 ;
if ( ! F_59 ( V_14 ) ) {
V_82 = F_82 ( V_14 , V_102 ) ;
if ( V_82 )
goto V_60;
}
F_58 ( V_14 , V_36 ) ;
V_60:
F_18 ( V_14 ) ;
return V_82 ;
}
static int F_83 ( struct V_35 * V_36 )
{
int V_82 = 0 ;
unsigned V_102 = V_103 ;
struct V_11 * V_12 ;
struct V_16 * V_14 ;
struct V_27 * V_20 , * V_107 = NULL ;
F_17 ( & V_23 ) ;
V_12 = F_69 ( V_36 ) ;
if ( ! V_12 ) {
F_74 ( L_13 ) ;
F_24 ( & V_23 ) ;
return - V_42 ;
}
V_14 = V_12 -> V_14 ;
V_20 = V_12 -> V_20 ;
V_12 -> V_20 = NULL ;
V_36 -> V_40 &= ~ V_86 ;
F_24 ( & V_23 ) ;
if ( V_20 ) {
if ( V_36 -> V_40 & V_104 )
V_102 &= ~ V_103 ;
if ( V_36 -> V_40 & V_105 )
V_102 |= V_106 ;
if ( ! F_59 ( V_14 ) )
F_82 ( V_14 , V_102 ) ;
V_107 = F_84 ( V_14 , V_20 ) ;
if ( F_77 ( V_107 ) ) {
F_29 ( V_20 ) ;
F_18 ( V_14 ) ;
return F_78 ( V_107 ) ;
}
if ( F_64 ( V_20 ) & V_81 )
F_85 ( F_44 ( V_14 ) , 0 ) ;
else
F_85 ( F_44 ( V_14 ) , 1 ) ;
}
if ( F_59 ( V_14 ) ) {
V_82 = F_86 ( V_14 ) ;
if ( ! V_82 && ! F_39 ( V_14 , V_44 , V_36 -> V_45 ) )
V_36 -> V_40 |= V_46 ;
}
if ( V_107 )
F_29 ( V_107 ) ;
if ( ! V_82 )
F_58 ( V_14 , V_36 ) ;
F_18 ( V_14 ) ;
return V_82 ;
}
static int F_87 ( struct V_35 * V_36 , T_1 V_47 )
{
if ( V_36 -> V_40 & V_76 )
return F_81 ( V_36 ) ;
return F_83 ( V_36 ) ;
}
static int F_88 ( struct V_35 * V_36 , T_1 V_47 )
{
struct V_16 * V_14 ;
V_14 = F_71 ( V_36 ) ;
if ( ! V_14 )
return - V_42 ;
F_58 ( V_14 , V_36 ) ;
F_18 ( V_14 ) ;
return 0 ;
}
static void F_89 ( struct V_27 * V_28 ,
struct V_35 * V_36 , T_1 V_47 )
{
unsigned int V_3 , V_108 ;
struct V_109 * V_110 ;
char * V_111 , * V_112 ;
T_2 type ;
T_1 V_113 , V_51 , V_114 = 0 ;
V_112 = V_111 = F_42 ( V_36 , V_47 , & V_51 ) ;
if ( V_36 -> V_40 & V_115 )
type = V_116 ;
else
type = V_117 ;
V_108 = F_63 ( V_28 ) ;
for ( V_3 = 0 ; V_3 < V_108 ; V_3 ++ ) {
struct V_118 * V_119 = F_90 ( V_28 , V_3 ) ;
V_113 = V_51 - ( V_112 - V_111 ) ;
if ( V_113 <= sizeof( struct V_109 ) ) {
V_36 -> V_40 |= V_59 ;
break;
}
V_110 = (struct V_109 * ) V_112 ;
V_110 -> V_120 = 0 ;
V_110 -> V_121 = V_119 -> V_122 ;
V_110 -> V_123 = V_119 -> V_51 ;
strncpy ( V_110 -> V_64 , V_119 -> type -> V_13 ,
sizeof( V_110 -> V_64 ) ) ;
V_112 += sizeof( struct V_109 ) ;
V_113 = V_51 - ( V_112 - V_111 ) ;
if ( V_113 <= 0 ) {
V_36 -> V_40 |= V_59 ;
break;
}
if ( V_119 -> type -> V_120 ) {
if ( V_119 -> type -> V_120 ( V_119 , type , V_112 , V_113 ) ) {
V_36 -> V_40 |= V_59 ;
break;
}
} else
V_112 [ 0 ] = '\0' ;
V_112 += strlen ( V_112 ) + 1 ;
V_114 = V_36 -> V_52 + ( V_112 - V_111 ) ;
V_112 = F_41 ( V_112 ) ;
V_110 -> V_62 = V_112 - V_111 ;
}
if ( V_114 )
V_36 -> V_48 = V_114 ;
V_36 -> V_80 = V_108 ;
}
static int F_91 ( struct V_35 * V_36 , T_1 V_47 )
{
int V_82 = 0 ;
struct V_16 * V_14 ;
struct V_27 * V_28 ;
V_14 = F_71 ( V_36 ) ;
if ( ! V_14 )
return - V_42 ;
if ( F_92 ( V_14 , V_36 -> V_45 ) ) {
V_82 = - V_124 ;
goto V_60;
}
F_58 ( V_14 , V_36 ) ;
V_28 = F_57 ( V_14 , V_36 ) ;
if ( V_28 ) {
F_89 ( V_28 , V_36 , V_47 ) ;
F_28 ( V_28 ) ;
}
V_60:
F_18 ( V_14 ) ;
return V_82 ;
}
static inline T_3 F_93 ( struct V_35 * V_36 )
{
T_3 V_125 = V_126 | V_81 ;
if ( V_36 -> V_40 & V_77 )
V_125 = V_126 ;
return V_125 ;
}
static int F_94 ( struct V_109 * V_127 , V_63 V_62 , void * V_72 ,
struct V_109 * * V_110 , char * * V_128 )
{
* V_110 = (struct V_109 * ) ( ( unsigned char * ) V_127 + V_62 ) ;
* V_128 = ( char * ) ( * V_110 + 1 ) ;
if ( * V_110 < ( V_127 + 1 ) )
return - V_43 ;
return F_75 ( * V_128 , V_72 ) ;
}
static int F_95 ( struct V_27 * V_28 ,
struct V_35 * V_36 , T_1 V_47 )
{
int V_82 ;
unsigned int V_3 = 0 ;
struct V_109 * V_110 = (struct V_109 * ) V_36 ;
V_63 V_62 = V_36 -> V_52 ;
void * V_72 = ( void * ) V_36 + V_47 ;
char * V_128 ;
if ( ! V_36 -> V_80 ) {
F_34 ( L_20 ) ;
return - V_43 ;
}
for ( V_3 = 0 ; V_3 < V_36 -> V_80 ; V_3 ++ ) {
V_82 = F_94 ( V_110 , V_62 , V_72 , & V_110 , & V_128 ) ;
if ( V_82 ) {
F_34 ( L_21 ) ;
return V_82 ;
}
V_82 = F_96 ( V_28 , V_110 -> V_64 ,
( V_129 ) V_110 -> V_121 ,
( V_129 ) V_110 -> V_123 ,
V_128 ) ;
if ( V_82 ) {
F_34 ( L_22 ) ;
return V_82 ;
}
V_62 = V_110 -> V_62 ;
}
return F_97 ( V_28 ) ;
}
static int F_98 ( struct V_35 * V_36 , T_1 V_47 )
{
int V_82 ;
struct V_11 * V_12 ;
struct V_27 * V_130 ;
struct V_16 * V_14 ;
V_14 = F_71 ( V_36 ) ;
if ( ! V_14 )
return - V_42 ;
V_82 = F_99 ( & V_130 , F_93 ( V_36 ) , V_36 -> V_80 , V_14 ) ;
if ( V_82 )
goto V_60;
V_82 = F_95 ( V_130 , V_36 , V_47 ) ;
if ( V_82 ) {
F_29 ( V_130 ) ;
goto V_60;
}
F_100 ( V_14 ) ;
if ( F_101 ( V_14 ) == V_131 )
F_102 ( V_14 , F_103 ( V_130 ) ) ;
else if ( F_101 ( V_14 ) != F_103 ( V_130 ) ) {
F_34 ( L_23 ) ;
F_29 ( V_130 ) ;
F_104 ( V_14 ) ;
V_82 = - V_43 ;
goto V_60;
}
V_82 = F_105 ( V_14 ) ;
if ( V_82 ) {
F_34 ( L_24 ) ;
F_29 ( V_130 ) ;
F_104 ( V_14 ) ;
goto V_60;
}
F_104 ( V_14 ) ;
F_17 ( & V_23 ) ;
V_12 = F_54 ( V_14 ) ;
if ( ! V_12 || V_12 -> V_14 != V_14 ) {
F_34 ( L_12 ) ;
F_29 ( V_130 ) ;
F_24 ( & V_23 ) ;
V_82 = - V_42 ;
goto V_60;
}
if ( V_12 -> V_20 )
F_29 ( V_12 -> V_20 ) ;
V_12 -> V_20 = V_130 ;
F_24 ( & V_23 ) ;
V_36 -> V_40 |= V_86 ;
F_58 ( V_14 , V_36 ) ;
V_60:
F_18 ( V_14 ) ;
return V_82 ;
}
static int F_106 ( struct V_35 * V_36 , T_1 V_47 )
{
struct V_11 * V_12 ;
struct V_16 * V_14 ;
F_17 ( & V_23 ) ;
V_12 = F_69 ( V_36 ) ;
if ( ! V_12 ) {
F_74 ( L_13 ) ;
F_24 ( & V_23 ) ;
return - V_42 ;
}
if ( V_12 -> V_20 ) {
F_29 ( V_12 -> V_20 ) ;
V_12 -> V_20 = NULL ;
}
V_36 -> V_40 &= ~ V_86 ;
F_58 ( V_12 -> V_14 , V_36 ) ;
V_14 = V_12 -> V_14 ;
F_24 ( & V_23 ) ;
F_18 ( V_14 ) ;
return 0 ;
}
static void F_107 ( struct V_27 * V_28 ,
struct V_35 * V_36 , T_1 V_47 )
{
unsigned int V_132 = 0 ;
struct V_1 * V_133 ;
T_1 V_51 , V_53 ;
struct V_134 * V_135 ;
struct V_136 * V_137 ;
V_137 = F_42 ( V_36 , V_47 , & V_51 ) ;
F_108 (tmp, dm_table_get_devices(table))
V_132 ++ ;
V_53 = sizeof( * V_137 ) + ( sizeof( * V_137 -> V_61 ) * V_132 ) ;
if ( V_51 < V_53 ) {
V_36 -> V_40 |= V_59 ;
return;
}
V_137 -> V_132 = V_132 ;
V_132 = 0 ;
F_8 (dd, dm_table_get_devices(table), list)
V_137 -> V_61 [ V_132 ++ ] = F_45 ( V_135 -> V_138 . V_139 -> V_140 ) ;
V_36 -> V_48 = V_36 -> V_52 + V_53 ;
}
static int F_109 ( struct V_35 * V_36 , T_1 V_47 )
{
struct V_16 * V_14 ;
struct V_27 * V_28 ;
V_14 = F_71 ( V_36 ) ;
if ( ! V_14 )
return - V_42 ;
F_58 ( V_14 , V_36 ) ;
V_28 = F_57 ( V_14 , V_36 ) ;
if ( V_28 ) {
F_107 ( V_28 , V_36 , V_47 ) ;
F_28 ( V_28 ) ;
}
F_18 ( V_14 ) ;
return 0 ;
}
static int F_110 ( struct V_35 * V_36 , T_1 V_47 )
{
struct V_16 * V_14 ;
struct V_27 * V_28 ;
V_14 = F_71 ( V_36 ) ;
if ( ! V_14 )
return - V_42 ;
F_58 ( V_14 , V_36 ) ;
V_28 = F_57 ( V_14 , V_36 ) ;
if ( V_28 ) {
F_89 ( V_28 , V_36 , V_47 ) ;
F_28 ( V_28 ) ;
}
F_18 ( V_14 ) ;
return 0 ;
}
static int F_111 ( struct V_35 * V_36 , T_1 V_47 )
{
int V_82 , V_141 ;
char * * V_142 ;
struct V_16 * V_14 ;
struct V_27 * V_28 ;
struct V_118 * V_119 ;
struct V_143 * V_144 = ( void * ) V_36 + V_36 -> V_52 ;
V_14 = F_71 ( V_36 ) ;
if ( ! V_14 )
return - V_42 ;
if ( V_144 < (struct V_143 * ) V_36 -> V_89 ||
F_75 ( V_144 -> V_145 , ( void * ) V_36 + V_47 ) ) {
F_34 ( L_25 ) ;
V_82 = - V_43 ;
goto V_60;
}
V_82 = F_112 ( & V_141 , & V_142 , V_144 -> V_145 ) ;
if ( V_82 ) {
F_34 ( L_26 ) ;
goto V_60;
}
V_28 = F_26 ( V_14 ) ;
if ( ! V_28 )
goto V_146;
if ( F_113 ( V_14 ) ) {
V_82 = - V_42 ;
goto V_147;
}
V_119 = F_114 ( V_28 , V_144 -> V_148 ) ;
if ( ! F_115 ( V_119 ) ) {
F_34 ( L_27 ) ;
V_82 = - V_43 ;
} else if ( V_119 -> type -> V_145 )
V_82 = V_119 -> type -> V_145 ( V_119 , V_141 , V_142 ) ;
else {
F_34 ( L_28 ) ;
V_82 = - V_43 ;
}
V_147:
F_28 ( V_28 ) ;
V_146:
F_14 ( V_142 ) ;
V_60:
V_36 -> V_48 = 0 ;
F_18 ( V_14 ) ;
return V_82 ;
}
static T_4 F_116 ( unsigned int V_149 )
{
static struct {
int V_149 ;
T_4 V_150 ;
} V_151 [] = {
{ V_152 , NULL } ,
{ V_153 , F_40 } ,
{ V_154 , F_43 } ,
{ V_155 , F_65 } ,
{ V_156 , F_73 } ,
{ V_157 , F_76 } ,
{ V_158 , F_87 } ,
{ V_159 , F_88 } ,
{ V_160 , F_91 } ,
{ V_161 , F_98 } ,
{ V_162 , F_106 } ,
{ V_163 , F_109 } ,
{ V_164 , F_110 } ,
{ V_165 , F_49 } ,
{ V_166 , F_111 } ,
{ V_167 , F_79 }
} ;
return ( V_149 >= F_117 ( V_151 ) ) ? NULL : V_151 [ V_149 ] . V_150 ;
}
static int F_118 ( unsigned int V_149 , struct V_35 T_5 * V_168 )
{
V_63 V_71 [ 3 ] ;
int V_82 = 0 ;
if ( F_119 ( V_71 , V_168 -> V_71 , sizeof( V_71 ) ) )
return - V_169 ;
if ( ( V_170 != V_71 [ 0 ] ) ||
( V_171 < V_71 [ 1 ] ) ) {
F_34 ( L_29
L_30 ,
V_170 , V_171 ,
V_172 ,
V_71 [ 0 ] , V_71 [ 1 ] , V_71 [ 2 ] , V_149 ) ;
V_82 = - V_43 ;
}
V_71 [ 0 ] = V_170 ;
V_71 [ 1 ] = V_171 ;
V_71 [ 2 ] = V_172 ;
if ( F_120 ( V_168 -> V_71 , V_71 , sizeof( V_71 ) ) )
return - V_169 ;
return V_82 ;
}
static int F_121 ( struct V_35 T_5 * V_168 , struct V_35 * * V_36 )
{
struct V_35 V_133 , * V_173 ;
int V_174 ;
if ( F_119 ( & V_133 , V_168 , sizeof( V_133 ) - sizeof( V_133 . V_89 ) ) )
return - V_169 ;
if ( V_133 . V_48 < ( sizeof( V_133 ) - sizeof( V_133 . V_89 ) ) )
return - V_43 ;
V_174 = V_133 . V_40 & V_175 ;
V_173 = F_122 ( V_133 . V_48 ) ;
if ( ! V_173 ) {
if ( V_174 && F_123 ( V_168 , V_133 . V_48 ) )
return - V_169 ;
return - V_22 ;
}
if ( F_119 ( V_173 , V_168 , V_133 . V_48 ) )
goto V_24;
if ( V_174 && F_123 ( V_168 , V_133 . V_48 ) )
goto V_24;
* V_36 = V_173 ;
return 0 ;
V_24:
if ( V_174 )
memset ( V_173 , 0 , V_133 . V_48 ) ;
F_124 ( V_173 ) ;
return - V_169 ;
}
static int F_125 ( T_6 V_149 , struct V_35 * V_36 )
{
V_36 -> V_40 &= ~ V_59 ;
V_36 -> V_40 &= ~ V_46 ;
V_36 -> V_40 &= ~ V_175 ;
if ( V_149 == V_153 ||
V_149 == V_154 ||
V_149 == V_165 )
return 0 ;
if ( ( V_149 == V_155 ) ) {
if ( ! * V_36 -> V_13 ) {
F_34 ( L_31 ) ;
return - V_43 ;
}
} else if ( ( * V_36 -> V_15 && * V_36 -> V_13 ) ) {
F_34 ( L_32 , V_149 ) ;
return - V_43 ;
}
V_36 -> V_13 [ V_91 - 1 ] = '\0' ;
V_36 -> V_15 [ V_90 - 1 ] = '\0' ;
return 0 ;
}
static int F_126 ( T_6 V_176 , struct V_35 T_5 * V_168 )
{
int V_82 = 0 ;
int V_177 ;
unsigned int V_149 ;
struct V_35 * V_178 ( V_36 ) ;
T_4 V_150 = NULL ;
T_1 V_179 ;
if ( ! F_127 ( V_180 ) )
return - V_181 ;
if ( F_128 ( V_176 ) != V_182 )
return - V_183 ;
V_149 = F_129 ( V_176 ) ;
V_82 = F_118 ( V_149 , V_168 ) ;
if ( V_82 )
return V_82 ;
if ( V_149 == V_152 )
return 0 ;
V_150 = F_116 ( V_149 ) ;
if ( ! V_150 ) {
F_34 ( L_33 , V_176 ) ;
return - V_183 ;
}
V_184 -> V_40 |= V_185 ;
V_82 = F_121 ( V_168 , & V_36 ) ;
V_184 -> V_40 &= ~ V_185 ;
if ( V_82 )
return V_82 ;
V_179 = V_36 -> V_48 ;
V_177 = V_36 -> V_40 & V_175 ;
V_82 = F_125 ( V_149 , V_36 ) ;
if ( V_82 )
goto V_60;
V_36 -> V_48 = sizeof( * V_36 ) ;
V_82 = V_150 ( V_36 , V_179 ) ;
if ( ! V_82 && F_120 ( V_168 , V_36 , V_36 -> V_48 ) )
V_82 = - V_169 ;
V_60:
if ( V_177 )
memset ( V_36 , 0 , V_179 ) ;
F_124 ( V_36 ) ;
return V_82 ;
}
static long F_130 ( struct V_186 * V_186 , T_6 V_176 , T_7 V_187 )
{
return ( long ) F_126 ( V_176 , (struct V_35 T_5 * ) V_187 ) ;
}
static long F_131 ( struct V_186 * V_186 , T_6 V_176 , T_7 V_187 )
{
return ( long ) F_130 ( V_186 , V_176 , ( T_7 ) F_132 ( V_187 ) ) ;
}
int T_8 F_133 ( void )
{
int V_82 ;
V_82 = F_3 () ;
if ( V_82 )
return V_82 ;
V_82 = F_134 ( & V_188 ) ;
if ( V_82 ) {
F_135 ( L_34 ) ;
F_4 () ;
return V_82 ;
}
F_136 ( L_35 , V_170 ,
V_171 , V_172 , V_189 ,
V_190 ) ;
return 0 ;
}
void F_137 ( void )
{
if ( F_138 ( & V_188 ) < 0 )
F_135 ( L_36 ) ;
F_4 () ;
}
int F_139 ( struct V_16 * V_14 , char * V_13 , char * V_15 )
{
int V_82 = 0 ;
struct V_11 * V_12 ;
if ( ! V_14 )
return - V_42 ;
F_21 ( & V_25 ) ;
V_12 = F_54 ( V_14 ) ;
if ( ! V_12 || V_12 -> V_14 != V_14 ) {
V_82 = - V_42 ;
goto V_60;
}
if ( V_13 )
strcpy ( V_13 , V_12 -> V_13 ) ;
if ( V_15 )
strcpy ( V_15 , V_12 -> V_15 ? : L_8 ) ;
V_60:
F_23 ( & V_25 ) ;
return V_82 ;
}
