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
V_83 ) ;
if ( F_63 ( V_14 ) )
V_41 -> V_45 |= V_81 ;
if ( F_64 ( V_14 ) )
V_41 -> V_45 |= V_53 ;
V_41 -> V_16 = F_51 ( F_52 ( V_61 ) ) ;
V_41 -> V_84 = F_65 ( V_14 ) ;
V_41 -> V_50 = F_66 ( V_14 ) ;
V_41 -> V_85 = 0 ;
V_29 = F_30 ( V_14 , & V_30 ) ;
if ( V_29 ) {
if ( ! ( V_41 -> V_45 & V_80 ) ) {
if ( F_67 ( V_61 ) )
V_41 -> V_45 |= V_82 ;
V_41 -> V_85 = F_68 ( V_29 ) ;
}
V_41 -> V_45 |= V_83 ;
}
F_32 ( V_14 , V_30 ) ;
if ( V_41 -> V_45 & V_80 ) {
int V_30 ;
V_29 = F_58 ( V_14 , & V_30 ) ;
if ( V_29 ) {
if ( ! ( F_69 ( V_29 ) & V_86 ) )
V_41 -> V_45 |= V_82 ;
V_41 -> V_85 = F_68 ( V_29 ) ;
}
F_32 ( V_14 , V_30 ) ;
}
}
static int F_70 ( struct V_40 * V_41 , T_2 V_52 )
{
int V_87 , V_88 = V_89 ;
struct V_17 * V_14 ;
V_87 = F_57 ( V_41 -> V_13 ) ;
if ( V_87 )
return V_87 ;
if ( V_41 -> V_45 & V_90 )
V_88 = F_71 ( F_13 ( V_41 -> V_16 ) ) ;
V_87 = F_72 ( V_88 , & V_14 ) ;
if ( V_87 )
return V_87 ;
V_87 = F_21 ( V_41 -> V_13 , * V_41 -> V_15 ? V_41 -> V_15 : NULL , V_14 ) ;
if ( V_87 ) {
F_15 ( V_14 ) ;
F_37 ( V_14 ) ;
return V_87 ;
}
V_41 -> V_45 &= ~ V_91 ;
F_62 ( V_14 , V_41 ) ;
F_15 ( V_14 ) ;
return 0 ;
}
static struct V_11 * F_73 ( struct V_40 * V_41 )
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
F_74 ( V_41 -> V_13 , V_12 -> V_13 , sizeof( V_41 -> V_13 ) ) ;
if ( V_12 -> V_15 )
F_74 ( V_41 -> V_15 , V_12 -> V_15 , sizeof( V_41 -> V_15 ) ) ;
else
V_41 -> V_15 [ 0 ] = '\0' ;
if ( V_12 -> V_21 )
V_41 -> V_45 |= V_91 ;
else
V_41 -> V_45 &= ~ V_91 ;
return V_12 ;
}
static struct V_17 * F_75 ( struct V_40 * V_41 )
{
struct V_11 * V_12 ;
struct V_17 * V_14 = NULL ;
F_59 ( & V_24 ) ;
V_12 = F_73 ( V_41 ) ;
if ( V_12 )
V_14 = V_12 -> V_14 ;
F_60 ( & V_24 ) ;
return V_14 ;
}
static int F_76 ( struct V_40 * V_41 , T_2 V_52 )
{
struct V_11 * V_12 ;
struct V_17 * V_14 ;
int V_87 ;
struct V_28 * V_35 ;
F_22 ( & V_24 ) ;
V_12 = F_73 ( V_41 ) ;
if ( ! V_12 ) {
F_77 ( L_13 ) ;
F_28 ( & V_24 ) ;
return - V_47 ;
}
V_14 = V_12 -> V_14 ;
V_87 = F_33 ( V_14 , ! ! ( V_41 -> V_45 & V_53 ) , false ) ;
if ( V_87 ) {
if ( V_87 == - V_27 && V_41 -> V_45 & V_53 ) {
F_28 ( & V_24 ) ;
F_15 ( V_14 ) ;
return 0 ;
}
F_77 ( L_14 , V_12 -> V_13 ) ;
F_28 ( & V_24 ) ;
F_15 ( V_14 ) ;
return V_87 ;
}
V_35 = F_29 ( V_12 ) ;
F_28 ( & V_24 ) ;
if ( V_35 ) {
F_34 ( V_14 ) ;
F_35 ( V_35 ) ;
}
V_41 -> V_45 &= ~ V_53 ;
if ( ! F_44 ( V_14 , V_92 , V_41 -> V_50 ) )
V_41 -> V_45 |= V_51 ;
F_15 ( V_14 ) ;
F_37 ( V_14 ) ;
return 0 ;
}
static int F_78 ( char * V_7 , void * V_77 )
{
while ( ( void * ) V_7 < V_77 )
if ( ! * V_7 ++ )
return 0 ;
return - V_48 ;
}
static int F_79 ( struct V_40 * V_41 , T_2 V_52 )
{
int V_87 ;
char * V_43 = ( char * ) V_41 + V_41 -> V_58 ;
struct V_17 * V_14 ;
unsigned V_44 = ( V_41 -> V_45 & V_46 ) ? 1 : 0 ;
if ( V_43 < V_41 -> V_93 ||
F_78 ( V_43, ( void * ) V_41 + V_52 ) || ! * V_43 ||
strlen ( V_43 ) > ( V_44 ? V_94 - 1 : V_95 - 1 ) ) {
F_39 ( L_15 ) ;
return - V_48 ;
}
if ( ! V_44 ) {
V_87 = F_57 ( V_43 ) ;
if ( V_87 )
return V_87 ;
}
V_14 = F_42 ( V_41 , V_43 ) ;
if ( F_80 ( V_14 ) )
return F_81 ( V_14 ) ;
F_62 ( V_14 , V_41 ) ;
F_15 ( V_14 ) ;
return 0 ;
}
static int F_82 ( struct V_40 * V_41 , T_2 V_52 )
{
int V_87 = - V_48 , V_96 ;
struct V_17 * V_14 ;
struct V_97 V_98 ;
unsigned long V_99 [ 4 ] ;
char * V_100 = ( char * ) V_41 + V_41 -> V_58 ;
char V_101 ;
V_14 = F_75 ( V_41 ) ;
if ( ! V_14 )
return - V_47 ;
if ( V_100 < V_41 -> V_93 ||
F_78 ( V_100 , ( void * ) V_41 + V_52 ) ) {
F_39 ( L_16 ) ;
goto V_66;
}
V_96 = sscanf ( V_100 , L_17 , V_99 ,
V_99 + 1 , V_99 + 2 , V_99 + 3 , & V_101 ) ;
if ( V_96 != 4 ) {
F_39 ( L_18 ) ;
goto V_66;
}
if ( V_99 [ 0 ] > 65535 || V_99 [ 1 ] > 255 ||
V_99 [ 2 ] > 255 || V_99 [ 3 ] > V_102 ) {
F_39 ( L_19 ) ;
goto V_66;
}
V_98 . V_103 = V_99 [ 0 ] ;
V_98 . V_104 = V_99 [ 1 ] ;
V_98 . V_105 = V_99 [ 2 ] ;
V_98 . V_106 = V_99 [ 3 ] ;
V_87 = F_83 ( V_14 , & V_98 ) ;
V_41 -> V_54 = 0 ;
V_66:
F_15 ( V_14 ) ;
return V_87 ;
}
static int F_84 ( struct V_40 * V_41 )
{
int V_87 = 0 ;
unsigned V_107 = V_108 ;
struct V_17 * V_14 ;
V_14 = F_75 ( V_41 ) ;
if ( ! V_14 )
return - V_47 ;
if ( V_41 -> V_45 & V_109 )
V_107 &= ~ V_108 ;
if ( V_41 -> V_45 & V_110 )
V_107 |= V_111 ;
if ( ! F_63 ( V_14 ) ) {
V_87 = F_85 ( V_14 , V_107 ) ;
if ( V_87 )
goto V_66;
}
F_62 ( V_14 , V_41 ) ;
V_66:
F_15 ( V_14 ) ;
return V_87 ;
}
static int F_86 ( struct V_40 * V_41 )
{
int V_87 = 0 ;
unsigned V_107 = V_108 ;
struct V_11 * V_12 ;
struct V_17 * V_14 ;
struct V_28 * V_21 , * V_112 = NULL ;
F_22 ( & V_24 ) ;
V_12 = F_73 ( V_41 ) ;
if ( ! V_12 ) {
F_77 ( L_13 ) ;
F_28 ( & V_24 ) ;
return - V_47 ;
}
V_14 = V_12 -> V_14 ;
V_21 = V_12 -> V_21 ;
V_12 -> V_21 = NULL ;
V_41 -> V_45 &= ~ V_91 ;
F_28 ( & V_24 ) ;
if ( V_21 ) {
if ( V_41 -> V_45 & V_109 )
V_107 &= ~ V_108 ;
if ( V_41 -> V_45 & V_110 )
V_107 |= V_111 ;
if ( ! F_63 ( V_14 ) )
F_85 ( V_14 , V_107 ) ;
V_112 = F_87 ( V_14 , V_21 ) ;
if ( F_80 ( V_112 ) ) {
F_34 ( V_14 ) ;
F_35 ( V_21 ) ;
F_15 ( V_14 ) ;
return F_81 ( V_112 ) ;
}
if ( F_69 ( V_21 ) & V_86 )
F_88 ( F_50 ( V_14 ) , 0 ) ;
else
F_88 ( F_50 ( V_14 ) , 1 ) ;
}
if ( F_63 ( V_14 ) ) {
V_87 = F_89 ( V_14 ) ;
if ( ! V_87 && ! F_44 ( V_14 , V_49 , V_41 -> V_50 ) )
V_41 -> V_45 |= V_51 ;
}
if ( V_112 )
F_35 ( V_112 ) ;
if ( ! V_87 )
F_62 ( V_14 , V_41 ) ;
F_15 ( V_14 ) ;
return V_87 ;
}
static int F_90 ( struct V_40 * V_41 , T_2 V_52 )
{
if ( V_41 -> V_45 & V_81 )
return F_84 ( V_41 ) ;
return F_86 ( V_41 ) ;
}
static int F_91 ( struct V_40 * V_41 , T_2 V_52 )
{
struct V_17 * V_14 ;
V_14 = F_75 ( V_41 ) ;
if ( ! V_14 )
return - V_47 ;
F_62 ( V_14 , V_41 ) ;
F_15 ( V_14 ) ;
return 0 ;
}
static void F_92 ( struct V_28 * V_29 ,
struct V_40 * V_41 , T_2 V_52 )
{
unsigned int V_3 , V_113 ;
struct V_114 * V_115 ;
char * V_116 , * V_117 ;
T_3 type ;
T_2 V_118 , V_57 , V_119 = 0 ;
unsigned V_120 = 0 ;
V_117 = V_116 = F_48 ( V_41 , V_52 , & V_57 ) ;
if ( V_41 -> V_45 & V_121 )
type = V_122 ;
else
type = V_123 ;
V_113 = F_68 ( V_29 ) ;
for ( V_3 = 0 ; V_3 < V_113 ; V_3 ++ ) {
struct V_124 * V_125 = F_93 ( V_29 , V_3 ) ;
T_2 V_126 ;
V_118 = V_57 - ( V_117 - V_116 ) ;
if ( V_118 <= sizeof( struct V_114 ) ) {
V_41 -> V_45 |= V_65 ;
break;
}
V_115 = (struct V_114 * ) V_117 ;
V_115 -> V_127 = 0 ;
V_115 -> V_128 = V_125 -> V_129 ;
V_115 -> V_130 = V_125 -> V_57 ;
strncpy ( V_115 -> V_69 , V_125 -> type -> V_13 ,
sizeof( V_115 -> V_69 ) ) ;
V_117 += sizeof( struct V_114 ) ;
V_118 = V_57 - ( V_117 - V_116 ) ;
if ( V_118 <= 0 ) {
V_41 -> V_45 |= V_65 ;
break;
}
if ( V_125 -> type -> V_127 ) {
if ( V_41 -> V_45 & V_110 )
V_120 |= V_131 ;
V_125 -> type -> V_127 ( V_125 , type , V_120 , V_117 , V_118 ) ;
} else
V_117 [ 0 ] = '\0' ;
V_126 = strlen ( V_117 ) + 1 ;
if ( V_126 == V_118 ) {
V_41 -> V_45 |= V_65 ;
break;
}
V_117 += V_126 ;
V_119 = V_41 -> V_58 + ( V_117 - V_116 ) ;
V_117 = F_47 ( V_117 ) ;
V_115 -> V_67 = V_117 - V_116 ;
}
if ( V_119 )
V_41 -> V_54 = V_119 ;
V_41 -> V_85 = V_113 ;
}
static int F_94 ( struct V_40 * V_41 , T_2 V_52 )
{
int V_87 = 0 ;
struct V_17 * V_14 ;
struct V_28 * V_29 ;
int V_30 ;
V_14 = F_75 ( V_41 ) ;
if ( ! V_14 )
return - V_47 ;
if ( F_95 ( V_14 , V_41 -> V_50 ) ) {
V_87 = - V_132 ;
goto V_66;
}
F_62 ( V_14 , V_41 ) ;
V_29 = F_61 ( V_14 , V_41 , & V_30 ) ;
if ( V_29 )
F_92 ( V_29 , V_41 , V_52 ) ;
F_32 ( V_14 , V_30 ) ;
V_66:
F_15 ( V_14 ) ;
return V_87 ;
}
static inline T_4 F_96 ( struct V_40 * V_41 )
{
T_4 V_133 = V_134 | V_86 ;
if ( V_41 -> V_45 & V_82 )
V_133 = V_134 ;
return V_133 ;
}
static int F_97 ( struct V_114 * V_135 , V_68 V_67 , void * V_77 ,
struct V_114 * * V_115 , char * * V_136 )
{
* V_115 = (struct V_114 * ) ( ( unsigned char * ) V_135 + V_67 ) ;
* V_136 = ( char * ) ( * V_115 + 1 ) ;
if ( * V_115 < ( V_135 + 1 ) )
return - V_48 ;
return F_78 ( * V_136 , V_77 ) ;
}
static int F_98 ( struct V_28 * V_29 ,
struct V_40 * V_41 , T_2 V_52 )
{
int V_87 ;
unsigned int V_3 = 0 ;
struct V_114 * V_115 = (struct V_114 * ) V_41 ;
V_68 V_67 = V_41 -> V_58 ;
void * V_77 = ( void * ) V_41 + V_52 ;
char * V_136 ;
if ( ! V_41 -> V_85 ) {
F_39 ( L_20 ) ;
return - V_48 ;
}
for ( V_3 = 0 ; V_3 < V_41 -> V_85 ; V_3 ++ ) {
V_87 = F_97 ( V_115 , V_67 , V_77 , & V_115 , & V_136 ) ;
if ( V_87 ) {
F_39 ( L_21 ) ;
return V_87 ;
}
V_87 = F_99 ( V_29 , V_115 -> V_69 ,
( V_137 ) V_115 -> V_128 ,
( V_137 ) V_115 -> V_130 ,
V_136 ) ;
if ( V_87 ) {
F_39 ( L_22 ) ;
return V_87 ;
}
V_67 = V_115 -> V_67 ;
}
return F_100 ( V_29 ) ;
}
static int F_101 ( struct V_40 * V_41 , T_2 V_52 )
{
int V_87 ;
struct V_11 * V_12 ;
struct V_28 * V_35 , * V_112 = NULL ;
struct V_17 * V_14 ;
struct V_69 * V_138 ;
V_14 = F_75 ( V_41 ) ;
if ( ! V_14 )
return - V_47 ;
V_87 = F_102 ( & V_35 , F_96 ( V_41 ) , V_41 -> V_85 , V_14 ) ;
if ( V_87 )
goto V_139;
F_103 ( V_14 ) ;
V_87 = F_98 ( V_35 , V_41 , V_52 ) ;
if ( V_87 )
goto V_140;
V_138 = F_104 ( V_14 ) ;
if ( V_138 &&
( V_138 != F_105 ( V_35 ) ) ) {
F_39 ( L_23 ,
V_138 -> V_13 ) ;
V_87 = - V_48 ;
goto V_140;
}
if ( F_106 ( V_14 ) == V_141 )
F_107 ( V_14 , F_108 ( V_35 ) ) ;
else if ( F_106 ( V_14 ) != F_108 ( V_35 ) ) {
F_39 ( L_24 ) ;
V_87 = - V_48 ;
goto V_140;
}
V_87 = F_109 ( V_14 ) ;
if ( V_87 ) {
F_39 ( L_25 ) ;
goto V_140;
}
F_110 ( V_14 ) ;
F_22 ( & V_24 ) ;
V_12 = F_14 ( V_14 ) ;
if ( ! V_12 || V_12 -> V_14 != V_14 ) {
F_39 ( L_12 ) ;
F_28 ( & V_24 ) ;
V_87 = - V_47 ;
goto V_142;
}
if ( V_12 -> V_21 )
V_112 = V_12 -> V_21 ;
V_12 -> V_21 = V_35 ;
F_28 ( & V_24 ) ;
V_41 -> V_45 |= V_91 ;
F_62 ( V_14 , V_41 ) ;
if ( V_112 ) {
F_34 ( V_14 ) ;
F_35 ( V_112 ) ;
}
F_15 ( V_14 ) ;
return 0 ;
V_140:
F_110 ( V_14 ) ;
V_142:
F_35 ( V_35 ) ;
V_139:
F_15 ( V_14 ) ;
return V_87 ;
}
static int F_111 ( struct V_40 * V_41 , T_2 V_52 )
{
struct V_11 * V_12 ;
struct V_17 * V_14 ;
struct V_28 * V_112 = NULL ;
F_22 ( & V_24 ) ;
V_12 = F_73 ( V_41 ) ;
if ( ! V_12 ) {
F_77 ( L_13 ) ;
F_28 ( & V_24 ) ;
return - V_47 ;
}
if ( V_12 -> V_21 ) {
V_112 = V_12 -> V_21 ;
V_12 -> V_21 = NULL ;
}
V_41 -> V_45 &= ~ V_91 ;
F_62 ( V_12 -> V_14 , V_41 ) ;
V_14 = V_12 -> V_14 ;
F_28 ( & V_24 ) ;
if ( V_112 ) {
F_34 ( V_14 ) ;
F_35 ( V_112 ) ;
}
F_15 ( V_14 ) ;
return 0 ;
}
static void F_112 ( struct V_28 * V_29 ,
struct V_40 * V_41 , T_2 V_52 )
{
unsigned int V_143 = 0 ;
struct V_1 * V_144 ;
T_2 V_57 , V_59 ;
struct V_145 * V_146 ;
struct V_147 * V_148 ;
V_148 = F_48 ( V_41 , V_52 , & V_57 ) ;
F_113 (tmp, dm_table_get_devices(table))
V_143 ++ ;
V_59 = sizeof( * V_148 ) + ( sizeof( * V_148 -> V_16 ) * V_143 ) ;
if ( V_57 < V_59 ) {
V_41 -> V_45 |= V_65 ;
return;
}
V_148 -> V_143 = V_143 ;
V_143 = 0 ;
F_8 (dd, dm_table_get_devices(table), list)
V_148 -> V_16 [ V_143 ++ ] = F_51 ( V_146 -> V_149 -> V_150 -> V_151 ) ;
V_41 -> V_54 = V_41 -> V_58 + V_59 ;
}
static int F_114 ( struct V_40 * V_41 , T_2 V_52 )
{
struct V_17 * V_14 ;
struct V_28 * V_29 ;
int V_30 ;
V_14 = F_75 ( V_41 ) ;
if ( ! V_14 )
return - V_47 ;
F_62 ( V_14 , V_41 ) ;
V_29 = F_61 ( V_14 , V_41 , & V_30 ) ;
if ( V_29 )
F_112 ( V_29 , V_41 , V_52 ) ;
F_32 ( V_14 , V_30 ) ;
F_15 ( V_14 ) ;
return 0 ;
}
static int F_115 ( struct V_40 * V_41 , T_2 V_52 )
{
struct V_17 * V_14 ;
struct V_28 * V_29 ;
int V_30 ;
V_14 = F_75 ( V_41 ) ;
if ( ! V_14 )
return - V_47 ;
F_62 ( V_14 , V_41 ) ;
V_29 = F_61 ( V_14 , V_41 , & V_30 ) ;
if ( V_29 )
F_92 ( V_29 , V_41 , V_52 ) ;
F_32 ( V_14 , V_30 ) ;
F_15 ( V_14 ) ;
return 0 ;
}
static int F_116 ( struct V_17 * V_14 , unsigned V_152 , char * * V_153 ,
char * V_154 , unsigned V_155 )
{
int V_87 ;
if ( * * V_153 != '@' )
return 2 ;
if ( ! strcasecmp ( V_153 [ 0 ] , L_26 ) ) {
if ( V_152 != 1 ) {
F_117 ( L_27 ) ;
return - V_48 ;
}
return F_118 ( V_14 ) ;
}
V_87 = F_119 ( V_14 , V_152 , V_153 , V_154 , V_155 ) ;
if ( V_87 < 2 )
return V_87 ;
F_117 ( L_28 , V_153 [ 0 ] ) ;
return - V_48 ;
}
static int F_120 ( struct V_40 * V_41 , T_2 V_52 )
{
int V_87 , V_152 ;
char * * V_153 ;
struct V_17 * V_14 ;
struct V_28 * V_29 ;
struct V_124 * V_125 ;
struct V_156 * V_157 = ( void * ) V_41 + V_41 -> V_58 ;
T_2 V_155 ;
char * V_154 = F_48 ( V_41 , V_52 , & V_155 ) ;
int V_30 ;
V_14 = F_75 ( V_41 ) ;
if ( ! V_14 )
return - V_47 ;
if ( V_157 < (struct V_156 * ) V_41 -> V_93 ||
F_78 ( V_157 -> V_158 , ( void * ) V_41 + V_52 ) ) {
F_39 ( L_29 ) ;
V_87 = - V_48 ;
goto V_66;
}
V_87 = F_121 ( & V_152 , & V_153 , V_157 -> V_158 ) ;
if ( V_87 ) {
F_39 ( L_30 ) ;
goto V_66;
}
if ( ! V_152 ) {
F_39 ( L_31 ) ;
goto V_159;
}
V_87 = F_116 ( V_14 , V_152 , V_153 , V_154 , V_155 ) ;
if ( V_87 <= 1 )
goto V_159;
V_29 = F_30 ( V_14 , & V_30 ) ;
if ( ! V_29 )
goto V_160;
if ( F_122 ( V_14 ) ) {
V_87 = - V_47 ;
goto V_160;
}
V_125 = F_123 ( V_29 , V_157 -> V_161 ) ;
if ( ! F_124 ( V_125 ) ) {
F_39 ( L_32 ) ;
V_87 = - V_48 ;
} else if ( V_125 -> type -> V_158 )
V_87 = V_125 -> type -> V_158 ( V_125 , V_152 , V_153 ) ;
else {
F_39 ( L_33 ) ;
V_87 = - V_48 ;
}
V_160:
F_32 ( V_14 , V_30 ) ;
V_159:
F_19 ( V_153 ) ;
V_66:
if ( V_87 >= 0 )
F_62 ( V_14 , V_41 ) ;
if ( V_87 == 1 ) {
V_41 -> V_45 |= V_162 ;
if ( F_125 ( V_154 , V_155 ) )
V_41 -> V_45 |= V_65 ;
else
V_41 -> V_54 = V_41 -> V_58 + strlen ( V_154 ) + 1 ;
V_87 = 0 ;
}
F_15 ( V_14 ) ;
return V_87 ;
}
static T_5 F_126 ( unsigned int V_163 , int * V_164 )
{
static struct {
int V_163 ;
int V_45 ;
T_5 V_165 ;
} V_166 [] = {
{ V_167 , 0 , NULL } ,
{ V_168 , V_169 , F_46 } ,
{ V_170 , 0 , F_49 } ,
{ V_171 , V_169 , F_70 } ,
{ V_172 , V_169 , F_76 } ,
{ V_173 , 0 , F_79 } ,
{ V_174 , V_169 , F_90 } ,
{ V_175 , V_169 , F_91 } ,
{ V_176 , 0 , F_94 } ,
{ V_177 , 0 , F_101 } ,
{ V_178 , V_169 , F_111 } ,
{ V_179 , 0 , F_114 } ,
{ V_180 , 0 , F_115 } ,
{ V_181 , 0 , F_55 } ,
{ V_182 , 0 , F_120 } ,
{ V_183 , 0 , F_82 }
} ;
if ( F_127 ( V_163 >= F_128 ( V_166 ) ) )
return NULL ;
* V_164 = V_166 [ V_163 ] . V_45 ;
return V_166 [ V_163 ] . V_165 ;
}
static int F_129 ( unsigned int V_163 , struct V_40 T_6 * V_184 )
{
V_68 V_76 [ 3 ] ;
int V_87 = 0 ;
if ( F_130 ( V_76 , V_184 -> V_76 , sizeof( V_76 ) ) )
return - V_185 ;
if ( ( V_186 != V_76 [ 0 ] ) ||
( V_187 < V_76 [ 1 ] ) ) {
F_39 ( L_34
L_35 ,
V_186 , V_187 ,
V_188 ,
V_76 [ 0 ] , V_76 [ 1 ] , V_76 [ 2 ] , V_163 ) ;
V_87 = - V_48 ;
}
V_76 [ 0 ] = V_186 ;
V_76 [ 1 ] = V_187 ;
V_76 [ 2 ] = V_188 ;
if ( F_131 ( V_184 -> V_76 , V_76 , sizeof( V_76 ) ) )
return - V_185 ;
return V_87 ;
}
static void F_132 ( struct V_40 * V_41 , T_2 V_52 , int V_189 )
{
if ( V_189 & V_190 )
memset ( V_41 , 0 , V_52 ) ;
if ( V_189 & V_191 )
F_19 ( V_41 ) ;
if ( V_189 & V_192 )
F_133 ( V_41 ) ;
}
static int F_134 ( struct V_40 T_6 * V_184 , struct V_40 * V_193 ,
int V_164 ,
struct V_40 * * V_41 , int * V_189 )
{
struct V_40 * V_194 ;
int V_195 ;
const T_2 V_196 = sizeof( * V_193 ) - sizeof( V_193 -> V_93 ) ;
if ( F_130 ( V_193 , V_184 , V_196 ) )
return - V_185 ;
if ( V_193 -> V_54 < V_196 )
return - V_48 ;
V_195 = V_193 -> V_45 & V_197 ;
* V_189 = V_195 ? V_190 : 0 ;
if ( V_164 & V_169 ) {
V_194 = V_193 ;
V_194 -> V_54 = V_196 ;
goto V_198;
}
V_194 = NULL ;
if ( V_193 -> V_54 <= V_199 ) {
V_194 = F_17 ( V_193 -> V_54 , V_200 | V_201 | V_202 | V_203 ) ;
if ( V_194 )
* V_189 |= V_191 ;
}
if ( ! V_194 ) {
unsigned V_204 ;
V_204 = F_135 () ;
V_194 = F_136 ( V_193 -> V_54 , V_200 | V_205 | V_206 | V_207 , V_208 ) ;
F_137 ( V_204 ) ;
if ( V_194 )
* V_189 |= V_192 ;
}
if ( ! V_194 ) {
if ( V_195 && F_138 ( V_184 , V_193 -> V_54 ) )
return - V_185 ;
return - V_23 ;
}
if ( F_130 ( V_194 , V_184 , V_193 -> V_54 ) )
goto V_25;
V_198:
if ( V_194 -> V_54 != V_193 -> V_54 ) {
F_117 ( L_36 ) ;
goto V_25;
}
if ( V_195 && F_138 ( V_184 , V_193 -> V_54 ) )
goto V_25;
* V_41 = V_194 ;
return 0 ;
V_25:
F_132 ( V_194 , V_193 -> V_54 , * V_189 ) ;
return - V_185 ;
}
static int F_139 ( T_7 V_163 , struct V_40 * V_41 )
{
V_41 -> V_45 &= ~ V_65 ;
V_41 -> V_45 &= ~ V_51 ;
V_41 -> V_45 &= ~ V_197 ;
V_41 -> V_45 &= ~ V_162 ;
if ( V_163 == V_168 ||
V_163 == V_170 ||
V_163 == V_181 )
return 0 ;
if ( ( V_163 == V_171 ) ) {
if ( ! * V_41 -> V_13 ) {
F_39 ( L_37 ) ;
return - V_48 ;
}
} else if ( ( * V_41 -> V_15 && * V_41 -> V_13 ) ) {
F_39 ( L_38 , V_163 ) ;
return - V_48 ;
}
V_41 -> V_13 [ V_95 - 1 ] = '\0' ;
V_41 -> V_15 [ V_94 - 1 ] = '\0' ;
return 0 ;
}
static int F_140 ( T_7 V_209 , struct V_40 T_6 * V_184 )
{
int V_87 = 0 ;
int V_164 ;
int V_189 ;
unsigned int V_163 ;
struct V_40 * V_210 ( V_41 ) ;
T_5 V_165 = NULL ;
T_2 V_211 ;
struct V_40 V_193 ;
if ( ! F_141 ( V_212 ) )
return - V_213 ;
if ( F_142 ( V_209 ) != V_214 )
return - V_215 ;
V_163 = F_143 ( V_209 ) ;
V_87 = F_129 ( V_163 , V_184 ) ;
if ( V_87 )
return V_87 ;
if ( V_163 == V_167 )
return 0 ;
V_165 = F_126 ( V_163 , & V_164 ) ;
if ( ! V_165 ) {
F_39 ( L_39 , V_209 ) ;
return - V_215 ;
}
V_87 = F_134 ( V_184 , & V_193 , V_164 , & V_41 , & V_189 ) ;
if ( V_87 )
return V_87 ;
V_211 = V_41 -> V_54 ;
V_87 = F_139 ( V_163 , V_41 ) ;
if ( V_87 )
goto V_66;
V_41 -> V_54 = sizeof( * V_41 ) ;
V_87 = V_165 ( V_41 , V_211 ) ;
if ( F_127 ( V_41 -> V_45 & V_65 ) &&
F_127 ( V_164 & V_169 ) )
F_117 ( L_40 , V_163 ) ;
if ( ! V_87 && F_131 ( V_184 , V_41 , V_41 -> V_54 ) )
V_87 = - V_185 ;
V_66:
F_132 ( V_41 , V_211 , V_189 ) ;
return V_87 ;
}
static long F_144 ( struct V_216 * V_216 , T_7 V_209 , T_8 V_217 )
{
return ( long ) F_140 ( V_209 , (struct V_40 T_6 * ) V_217 ) ;
}
static long F_145 ( struct V_216 * V_216 , T_7 V_209 , T_8 V_217 )
{
return ( long ) F_144 ( V_216 , V_209 , ( T_8 ) F_146 ( V_217 ) ) ;
}
int T_9 F_147 ( void )
{
int V_87 ;
V_87 = F_3 () ;
if ( V_87 )
return V_87 ;
V_87 = F_148 ( & V_218 ) ;
if ( V_87 ) {
F_117 ( L_41 ) ;
F_4 () ;
return V_87 ;
}
F_149 ( L_42 , V_186 ,
V_187 , V_188 , V_219 ,
V_220 ) ;
return 0 ;
}
void F_150 ( void )
{
if ( F_151 ( & V_218 ) < 0 )
F_117 ( L_43 ) ;
F_4 () ;
}
int F_152 ( struct V_17 * V_14 , char * V_13 , char * V_15 )
{
int V_87 = 0 ;
struct V_11 * V_12 ;
if ( ! V_14 )
return - V_47 ;
F_25 ( & V_26 ) ;
V_12 = F_14 ( V_14 ) ;
if ( ! V_12 || V_12 -> V_14 != V_14 ) {
V_87 = - V_47 ;
goto V_66;
}
if ( V_13 )
strcpy ( V_13 , V_12 -> V_13 ) ;
if ( V_15 )
strcpy ( V_15 , V_12 -> V_15 ? : L_8 ) ;
V_66:
F_27 ( & V_26 ) ;
return V_87 ;
}
