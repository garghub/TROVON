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
static void F_29 ( struct V_11 * V_12 )
{
struct V_28 * V_29 ;
F_24 ( & V_12 -> V_20 ) ;
F_24 ( & V_12 -> V_19 ) ;
F_25 ( & V_26 ) ;
F_26 ( V_12 -> V_14 , NULL ) ;
F_27 ( & V_26 ) ;
V_29 = F_30 ( V_12 -> V_14 ) ;
if ( V_29 ) {
F_31 ( V_29 ) ;
F_32 ( V_29 ) ;
}
if ( V_12 -> V_21 )
F_33 ( V_12 -> V_21 ) ;
F_15 ( V_12 -> V_14 ) ;
F_20 ( V_12 ) ;
}
static void F_5 ( int V_30 )
{
int V_3 , V_31 ;
struct V_11 * V_12 ;
struct V_17 * V_14 ;
V_32:
V_31 = 0 ;
F_22 ( & V_24 ) ;
for ( V_3 = 0 ; V_3 < V_4 ; V_3 ++ ) {
F_8 (hc, _name_buckets + i, name_list) {
V_14 = V_12 -> V_14 ;
F_9 ( V_14 ) ;
if ( V_30 && F_34 ( V_14 ) ) {
F_15 ( V_14 ) ;
V_31 ++ ;
continue;
}
F_29 ( V_12 ) ;
F_28 ( & V_24 ) ;
F_15 ( V_14 ) ;
if ( F_35 ( V_30 ) )
F_36 ( V_14 ) ;
else
F_37 ( V_14 ) ;
goto V_32;
}
}
F_28 ( & V_24 ) ;
if ( V_31 )
F_38 ( L_1 , V_31 ) ;
}
static void F_39 ( struct V_11 * V_12 , char * V_33 )
{
F_25 ( & V_26 ) ;
V_12 -> V_15 = V_33 ;
F_27 ( & V_26 ) ;
F_23 ( & V_12 -> V_20 , V_6 + F_6 ( V_33 ) ) ;
}
static char * F_40 ( struct V_11 * V_12 , char * V_34 )
{
char * V_35 ;
F_24 ( & V_12 -> V_19 ) ;
V_35 = V_12 -> V_13 ;
F_25 ( & V_26 ) ;
V_12 -> V_13 = V_34 ;
F_27 ( & V_26 ) ;
F_23 ( & V_12 -> V_19 , V_5 + F_6 ( V_34 ) ) ;
return V_35 ;
}
static struct V_17 * F_41 ( struct V_36 * V_37 ,
const char * V_38 )
{
char * V_39 , * V_35 = NULL ;
struct V_11 * V_12 ;
struct V_28 * V_29 ;
struct V_17 * V_14 ;
unsigned V_40 = ( V_37 -> V_41 & V_42 ) ? 1 : 0 ;
V_39 = F_18 ( V_38 , V_18 ) ;
if ( ! V_39 )
return F_42 ( - V_23 ) ;
F_22 ( & V_24 ) ;
if ( V_40 )
V_12 = F_10 ( V_38 ) ;
else
V_12 = F_7 ( V_38 ) ;
if ( V_12 ) {
F_38 ( L_2
L_3 ,
V_40 ? L_4 : L_5 ,
V_37 -> V_13 , V_38 ) ;
F_15 ( V_12 -> V_14 ) ;
F_28 ( & V_24 ) ;
F_19 ( V_39 ) ;
return F_42 ( - V_27 ) ;
}
V_12 = F_7 ( V_37 -> V_13 ) ;
if ( ! V_12 ) {
F_38 ( L_6 ,
V_37 -> V_13 , V_40 ? L_7 : L_8 , V_38 ) ;
F_28 ( & V_24 ) ;
F_19 ( V_39 ) ;
return F_42 ( - V_43 ) ;
}
if ( V_40 && V_12 -> V_15 ) {
F_38 ( L_9
L_10 ,
V_37 -> V_13 , V_38 , V_12 -> V_15 ) ;
F_15 ( V_12 -> V_14 ) ;
F_28 ( & V_24 ) ;
F_19 ( V_39 ) ;
return F_42 ( - V_44 ) ;
}
if ( V_40 )
F_39 ( V_12 , V_39 ) ;
else
V_35 = F_40 ( V_12 , V_39 ) ;
V_29 = F_30 ( V_12 -> V_14 ) ;
if ( V_29 ) {
F_31 ( V_29 ) ;
F_32 ( V_29 ) ;
}
if ( ! F_43 ( V_12 -> V_14 , V_45 , V_37 -> V_46 ) )
V_37 -> V_41 |= V_47 ;
V_14 = V_12 -> V_14 ;
F_28 ( & V_24 ) ;
F_19 ( V_35 ) ;
return V_14 ;
}
static int F_44 ( struct V_36 * V_37 , T_2 V_48 )
{
F_5 ( 1 ) ;
V_37 -> V_49 = 0 ;
return 0 ;
}
static inline void * F_45 ( void * V_50 )
{
return ( void * ) ( ( ( T_2 ) ( V_50 + V_51 ) ) & ~ V_51 ) ;
}
static void * F_46 ( struct V_36 * V_37 , T_2 V_48 ,
T_2 * V_52 )
{
V_37 -> V_53 = F_45 ( V_37 + 1 ) - ( void * ) V_37 ;
if ( V_37 -> V_53 < V_48 )
* V_52 = V_48 - V_37 -> V_53 ;
else
* V_52 = 0 ;
return ( ( void * ) V_37 ) + V_37 -> V_53 ;
}
static int F_47 ( struct V_36 * V_37 , T_2 V_48 )
{
unsigned int V_3 ;
struct V_11 * V_12 ;
T_2 V_52 , V_54 = 0 ;
struct V_55 * V_56 ;
struct V_57 * V_58 , * V_59 = NULL ;
F_22 ( & V_24 ) ;
for ( V_3 = 0 ; V_3 < V_4 ; V_3 ++ ) {
F_8 (hc, _name_buckets + i, name_list) {
V_54 += sizeof( struct V_57 ) ;
V_54 += strlen ( V_12 -> V_13 ) + 1 ;
V_54 += V_51 ;
}
}
V_58 = F_46 ( V_37 , V_48 , & V_52 ) ;
if ( V_52 < V_54 ) {
V_37 -> V_41 |= V_60 ;
goto V_61;
}
V_37 -> V_49 = V_37 -> V_53 + V_54 ;
V_58 -> V_16 = 0 ;
for ( V_3 = 0 ; V_3 < V_4 ; V_3 ++ ) {
F_8 (hc, _name_buckets + i, name_list) {
if ( V_59 )
V_59 -> V_62 = ( V_63 ) ( ( void * ) V_58 -
( void * ) V_59 ) ;
V_56 = F_48 ( V_12 -> V_14 ) ;
V_58 -> V_16 = F_49 ( F_50 ( V_56 ) ) ;
V_58 -> V_62 = 0 ;
strcpy ( V_58 -> V_13 , V_12 -> V_13 ) ;
V_59 = V_58 ;
V_58 = F_45 ( ( ( void * ) ++ V_58 ) + strlen ( V_12 -> V_13 ) + 1 ) ;
}
}
V_61:
F_28 ( & V_24 ) ;
return 0 ;
}
static void F_51 ( struct V_64 * V_65 , void * V_66 )
{
T_2 * V_54 = V_66 ;
* V_54 += sizeof( struct V_67 ) ;
* V_54 += strlen ( V_65 -> V_13 ) ;
* V_54 += V_51 ;
}
static void F_52 ( struct V_64 * V_65 , void * V_37 )
{
struct V_68 * V_69 = V_37 ;
if ( ( char * ) V_69 -> V_70 + sizeof( V_65 -> V_71 ) + strlen ( V_65 -> V_13 ) + 1 >
V_69 -> V_72 ) {
V_69 -> V_41 = V_60 ;
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
V_69 -> V_70 = F_45 ( ( ( void * ) ++ V_69 -> V_70 ) + strlen ( V_65 -> V_13 ) + 1 ) ;
}
static int F_53 ( struct V_36 * V_37 , T_2 V_48 )
{
T_2 V_52 , V_54 = 0 ;
struct V_67 * V_70 ;
struct V_68 V_74 ;
F_54 ( F_51 , & V_54 ) ;
V_70 = F_46 ( V_37 , V_48 , & V_52 ) ;
if ( V_52 < V_54 ) {
V_37 -> V_41 |= V_60 ;
goto V_61;
}
V_37 -> V_49 = V_37 -> V_53 + V_54 ;
V_74 . V_48 = V_48 ;
V_74 . V_73 = NULL ;
V_74 . V_70 = V_70 ;
V_74 . V_41 = 0 ;
V_74 . V_72 = ( char * ) V_70 + V_52 ;
F_54 ( F_52 , & V_74 ) ;
V_37 -> V_41 |= V_74 . V_41 ;
V_61:
return 0 ;
}
static int F_55 ( const char * V_13 )
{
if ( strchr ( V_13 , '/' ) ) {
F_38 ( L_11 ) ;
return - V_44 ;
}
return 0 ;
}
static struct V_28 * F_56 ( struct V_17 * V_14 )
{
struct V_11 * V_12 ;
struct V_28 * V_29 = NULL ;
F_57 ( & V_24 ) ;
V_12 = F_14 ( V_14 ) ;
if ( ! V_12 || V_12 -> V_14 != V_14 ) {
F_38 ( L_12 ) ;
goto V_61;
}
V_29 = V_12 -> V_21 ;
if ( V_29 )
F_58 ( V_29 ) ;
V_61:
F_59 ( & V_24 ) ;
return V_29 ;
}
static struct V_28 * F_60 ( struct V_17 * V_14 ,
struct V_36 * V_37 )
{
return ( V_37 -> V_41 & V_75 ) ?
F_56 ( V_14 ) : F_30 ( V_14 ) ;
}
static void F_61 ( struct V_17 * V_14 , struct V_36 * V_37 )
{
struct V_55 * V_56 = F_48 ( V_14 ) ;
struct V_28 * V_29 ;
V_37 -> V_41 &= ~ ( V_76 | V_77 |
V_78 ) ;
if ( F_62 ( V_14 ) )
V_37 -> V_41 |= V_76 ;
V_37 -> V_16 = F_49 ( F_50 ( V_56 ) ) ;
V_37 -> V_79 = F_63 ( V_14 ) ;
V_37 -> V_46 = F_64 ( V_14 ) ;
V_37 -> V_80 = 0 ;
V_29 = F_30 ( V_14 ) ;
if ( V_29 ) {
if ( ! ( V_37 -> V_41 & V_75 ) ) {
if ( F_65 ( V_56 ) )
V_37 -> V_41 |= V_77 ;
V_37 -> V_80 = F_66 ( V_29 ) ;
}
F_32 ( V_29 ) ;
V_37 -> V_41 |= V_78 ;
}
if ( V_37 -> V_41 & V_75 ) {
V_29 = F_56 ( V_14 ) ;
if ( V_29 ) {
if ( ! ( F_67 ( V_29 ) & V_81 ) )
V_37 -> V_41 |= V_77 ;
V_37 -> V_80 = F_66 ( V_29 ) ;
F_32 ( V_29 ) ;
}
}
}
static int F_68 ( struct V_36 * V_37 , T_2 V_48 )
{
int V_82 , V_83 = V_84 ;
struct V_17 * V_14 ;
V_82 = F_55 ( V_37 -> V_13 ) ;
if ( V_82 )
return V_82 ;
if ( V_37 -> V_41 & V_85 )
V_83 = F_69 ( F_13 ( V_37 -> V_16 ) ) ;
V_82 = F_70 ( V_83 , & V_14 ) ;
if ( V_82 )
return V_82 ;
V_82 = F_21 ( V_37 -> V_13 , * V_37 -> V_15 ? V_37 -> V_15 : NULL , V_14 ) ;
if ( V_82 ) {
F_15 ( V_14 ) ;
F_36 ( V_14 ) ;
return V_82 ;
}
V_37 -> V_41 &= ~ V_86 ;
F_61 ( V_14 , V_37 ) ;
F_15 ( V_14 ) ;
return 0 ;
}
static struct V_11 * F_71 ( struct V_36 * V_37 )
{
struct V_11 * V_12 = NULL ;
if ( * V_37 -> V_15 ) {
if ( * V_37 -> V_13 || V_37 -> V_16 )
return NULL ;
V_12 = F_10 ( V_37 -> V_15 ) ;
if ( ! V_12 )
return NULL ;
} else if ( * V_37 -> V_13 ) {
if ( V_37 -> V_16 )
return NULL ;
V_12 = F_7 ( V_37 -> V_13 ) ;
if ( ! V_12 )
return NULL ;
} else if ( V_37 -> V_16 ) {
V_12 = F_11 ( V_37 -> V_16 ) ;
if ( ! V_12 )
return NULL ;
} else
return NULL ;
F_72 ( V_37 -> V_13 , V_12 -> V_13 , sizeof( V_37 -> V_13 ) ) ;
if ( V_12 -> V_15 )
F_72 ( V_37 -> V_15 , V_12 -> V_15 , sizeof( V_37 -> V_15 ) ) ;
else
V_37 -> V_15 [ 0 ] = '\0' ;
if ( V_12 -> V_21 )
V_37 -> V_41 |= V_86 ;
else
V_37 -> V_41 &= ~ V_86 ;
return V_12 ;
}
static struct V_17 * F_73 ( struct V_36 * V_37 )
{
struct V_11 * V_12 ;
struct V_17 * V_14 = NULL ;
F_57 ( & V_24 ) ;
V_12 = F_71 ( V_37 ) ;
if ( V_12 )
V_14 = V_12 -> V_14 ;
F_59 ( & V_24 ) ;
return V_14 ;
}
static int F_74 ( struct V_36 * V_37 , T_2 V_48 )
{
struct V_11 * V_12 ;
struct V_17 * V_14 ;
int V_82 ;
F_22 ( & V_24 ) ;
V_12 = F_71 ( V_37 ) ;
if ( ! V_12 ) {
F_75 ( L_13 ) ;
F_28 ( & V_24 ) ;
return - V_43 ;
}
V_14 = V_12 -> V_14 ;
V_82 = F_34 ( V_14 ) ;
if ( V_82 ) {
F_75 ( L_14 , V_12 -> V_13 ) ;
F_28 ( & V_24 ) ;
F_15 ( V_14 ) ;
return V_82 ;
}
F_29 ( V_12 ) ;
F_28 ( & V_24 ) ;
if ( ! F_43 ( V_14 , V_87 , V_37 -> V_46 ) )
V_37 -> V_41 |= V_47 ;
F_15 ( V_14 ) ;
F_36 ( V_14 ) ;
return 0 ;
}
static int F_76 ( char * V_7 , void * V_72 )
{
while ( ( void * ) V_7 < V_72 )
if ( ! * V_7 ++ )
return 0 ;
return - V_44 ;
}
static int F_77 ( struct V_36 * V_37 , T_2 V_48 )
{
int V_82 ;
char * V_39 = ( char * ) V_37 + V_37 -> V_53 ;
struct V_17 * V_14 ;
unsigned V_40 = ( V_37 -> V_41 & V_42 ) ? 1 : 0 ;
if ( V_39 < V_37 -> V_88 ||
F_76 ( V_39, ( void * ) V_37 + V_48 ) ||
strlen ( V_39 ) > ( V_40 ? V_89 - 1 : V_90 - 1 ) ) {
F_38 ( L_15 ) ;
return - V_44 ;
}
if ( ! V_40 ) {
V_82 = F_55 ( V_39 ) ;
if ( V_82 )
return V_82 ;
}
V_14 = F_41 ( V_37 , V_39 ) ;
if ( F_78 ( V_14 ) )
return F_79 ( V_14 ) ;
F_61 ( V_14 , V_37 ) ;
F_15 ( V_14 ) ;
return 0 ;
}
static int F_80 ( struct V_36 * V_37 , T_2 V_48 )
{
int V_82 = - V_44 , V_91 ;
struct V_17 * V_14 ;
struct V_92 V_93 ;
unsigned long V_94 [ 4 ] ;
char * V_95 = ( char * ) V_37 + V_37 -> V_53 ;
char V_96 ;
V_14 = F_73 ( V_37 ) ;
if ( ! V_14 )
return - V_43 ;
if ( V_95 < V_37 -> V_88 ||
F_76 ( V_95 , ( void * ) V_37 + V_48 ) ) {
F_38 ( L_16 ) ;
goto V_61;
}
V_91 = sscanf ( V_95 , L_17 , V_94 ,
V_94 + 1 , V_94 + 2 , V_94 + 3 , & V_96 ) ;
if ( V_91 != 4 ) {
F_38 ( L_18 ) ;
goto V_61;
}
if ( V_94 [ 0 ] > 65535 || V_94 [ 1 ] > 255 ||
V_94 [ 2 ] > 255 || V_94 [ 3 ] > V_97 ) {
F_38 ( L_19 ) ;
goto V_61;
}
V_93 . V_98 = V_94 [ 0 ] ;
V_93 . V_99 = V_94 [ 1 ] ;
V_93 . V_100 = V_94 [ 2 ] ;
V_93 . V_101 = V_94 [ 3 ] ;
V_82 = F_81 ( V_14 , & V_93 ) ;
V_37 -> V_49 = 0 ;
V_61:
F_15 ( V_14 ) ;
return V_82 ;
}
static int F_82 ( struct V_36 * V_37 )
{
int V_82 = 0 ;
unsigned V_102 = V_103 ;
struct V_17 * V_14 ;
V_14 = F_73 ( V_37 ) ;
if ( ! V_14 )
return - V_43 ;
if ( V_37 -> V_41 & V_104 )
V_102 &= ~ V_103 ;
if ( V_37 -> V_41 & V_105 )
V_102 |= V_106 ;
if ( ! F_62 ( V_14 ) ) {
V_82 = F_83 ( V_14 , V_102 ) ;
if ( V_82 )
goto V_61;
}
F_61 ( V_14 , V_37 ) ;
V_61:
F_15 ( V_14 ) ;
return V_82 ;
}
static int F_84 ( struct V_36 * V_37 )
{
int V_82 = 0 ;
unsigned V_102 = V_103 ;
struct V_11 * V_12 ;
struct V_17 * V_14 ;
struct V_28 * V_21 , * V_107 = NULL ;
F_22 ( & V_24 ) ;
V_12 = F_71 ( V_37 ) ;
if ( ! V_12 ) {
F_75 ( L_13 ) ;
F_28 ( & V_24 ) ;
return - V_43 ;
}
V_14 = V_12 -> V_14 ;
V_21 = V_12 -> V_21 ;
V_12 -> V_21 = NULL ;
V_37 -> V_41 &= ~ V_86 ;
F_28 ( & V_24 ) ;
if ( V_21 ) {
if ( V_37 -> V_41 & V_104 )
V_102 &= ~ V_103 ;
if ( V_37 -> V_41 & V_105 )
V_102 |= V_106 ;
if ( ! F_62 ( V_14 ) )
F_83 ( V_14 , V_102 ) ;
V_107 = F_85 ( V_14 , V_21 ) ;
if ( F_78 ( V_107 ) ) {
F_33 ( V_21 ) ;
F_15 ( V_14 ) ;
return F_79 ( V_107 ) ;
}
if ( F_67 ( V_21 ) & V_81 )
F_86 ( F_48 ( V_14 ) , 0 ) ;
else
F_86 ( F_48 ( V_14 ) , 1 ) ;
}
if ( F_62 ( V_14 ) ) {
V_82 = F_87 ( V_14 ) ;
if ( ! V_82 && ! F_43 ( V_14 , V_45 , V_37 -> V_46 ) )
V_37 -> V_41 |= V_47 ;
}
if ( V_107 )
F_33 ( V_107 ) ;
if ( ! V_82 )
F_61 ( V_14 , V_37 ) ;
F_15 ( V_14 ) ;
return V_82 ;
}
static int F_88 ( struct V_36 * V_37 , T_2 V_48 )
{
if ( V_37 -> V_41 & V_76 )
return F_82 ( V_37 ) ;
return F_84 ( V_37 ) ;
}
static int F_89 ( struct V_36 * V_37 , T_2 V_48 )
{
struct V_17 * V_14 ;
V_14 = F_73 ( V_37 ) ;
if ( ! V_14 )
return - V_43 ;
F_61 ( V_14 , V_37 ) ;
F_15 ( V_14 ) ;
return 0 ;
}
static void F_90 ( struct V_28 * V_29 ,
struct V_36 * V_37 , T_2 V_48 )
{
unsigned int V_3 , V_108 ;
struct V_109 * V_110 ;
char * V_111 , * V_112 ;
T_3 type ;
T_2 V_113 , V_52 , V_114 = 0 ;
unsigned V_115 = 0 ;
V_112 = V_111 = F_46 ( V_37 , V_48 , & V_52 ) ;
if ( V_37 -> V_41 & V_116 )
type = V_117 ;
else
type = V_118 ;
V_108 = F_66 ( V_29 ) ;
for ( V_3 = 0 ; V_3 < V_108 ; V_3 ++ ) {
struct V_119 * V_120 = F_91 ( V_29 , V_3 ) ;
T_2 V_121 ;
V_113 = V_52 - ( V_112 - V_111 ) ;
if ( V_113 <= sizeof( struct V_109 ) ) {
V_37 -> V_41 |= V_60 ;
break;
}
V_110 = (struct V_109 * ) V_112 ;
V_110 -> V_122 = 0 ;
V_110 -> V_123 = V_120 -> V_124 ;
V_110 -> V_125 = V_120 -> V_52 ;
strncpy ( V_110 -> V_64 , V_120 -> type -> V_13 ,
sizeof( V_110 -> V_64 ) ) ;
V_112 += sizeof( struct V_109 ) ;
V_113 = V_52 - ( V_112 - V_111 ) ;
if ( V_113 <= 0 ) {
V_37 -> V_41 |= V_60 ;
break;
}
if ( V_120 -> type -> V_122 ) {
if ( V_37 -> V_41 & V_105 )
V_115 |= V_126 ;
V_120 -> type -> V_122 ( V_120 , type , V_115 , V_112 , V_113 ) ;
} else
V_112 [ 0 ] = '\0' ;
V_121 = strlen ( V_112 ) + 1 ;
if ( V_121 == V_113 ) {
V_37 -> V_41 |= V_60 ;
break;
}
V_112 += V_121 ;
V_114 = V_37 -> V_53 + ( V_112 - V_111 ) ;
V_112 = F_45 ( V_112 ) ;
V_110 -> V_62 = V_112 - V_111 ;
}
if ( V_114 )
V_37 -> V_49 = V_114 ;
V_37 -> V_80 = V_108 ;
}
static int F_92 ( struct V_36 * V_37 , T_2 V_48 )
{
int V_82 = 0 ;
struct V_17 * V_14 ;
struct V_28 * V_29 ;
V_14 = F_73 ( V_37 ) ;
if ( ! V_14 )
return - V_43 ;
if ( F_93 ( V_14 , V_37 -> V_46 ) ) {
V_82 = - V_127 ;
goto V_61;
}
F_61 ( V_14 , V_37 ) ;
V_29 = F_60 ( V_14 , V_37 ) ;
if ( V_29 ) {
F_90 ( V_29 , V_37 , V_48 ) ;
F_32 ( V_29 ) ;
}
V_61:
F_15 ( V_14 ) ;
return V_82 ;
}
static inline T_4 F_94 ( struct V_36 * V_37 )
{
T_4 V_128 = V_129 | V_81 ;
if ( V_37 -> V_41 & V_77 )
V_128 = V_129 ;
return V_128 ;
}
static int F_95 ( struct V_109 * V_130 , V_63 V_62 , void * V_72 ,
struct V_109 * * V_110 , char * * V_131 )
{
* V_110 = (struct V_109 * ) ( ( unsigned char * ) V_130 + V_62 ) ;
* V_131 = ( char * ) ( * V_110 + 1 ) ;
if ( * V_110 < ( V_130 + 1 ) )
return - V_44 ;
return F_76 ( * V_131 , V_72 ) ;
}
static int F_96 ( struct V_28 * V_29 ,
struct V_36 * V_37 , T_2 V_48 )
{
int V_82 ;
unsigned int V_3 = 0 ;
struct V_109 * V_110 = (struct V_109 * ) V_37 ;
V_63 V_62 = V_37 -> V_53 ;
void * V_72 = ( void * ) V_37 + V_48 ;
char * V_131 ;
if ( ! V_37 -> V_80 ) {
F_38 ( L_20 ) ;
return - V_44 ;
}
for ( V_3 = 0 ; V_3 < V_37 -> V_80 ; V_3 ++ ) {
V_82 = F_95 ( V_110 , V_62 , V_72 , & V_110 , & V_131 ) ;
if ( V_82 ) {
F_38 ( L_21 ) ;
return V_82 ;
}
V_82 = F_97 ( V_29 , V_110 -> V_64 ,
( V_132 ) V_110 -> V_123 ,
( V_132 ) V_110 -> V_125 ,
V_131 ) ;
if ( V_82 ) {
F_38 ( L_22 ) ;
return V_82 ;
}
V_62 = V_110 -> V_62 ;
}
return F_98 ( V_29 ) ;
}
static int F_99 ( struct V_36 * V_37 , T_2 V_48 )
{
int V_82 ;
struct V_11 * V_12 ;
struct V_28 * V_133 ;
struct V_17 * V_14 ;
struct V_64 * V_134 ;
V_14 = F_73 ( V_37 ) ;
if ( ! V_14 )
return - V_43 ;
V_82 = F_100 ( & V_133 , F_94 ( V_37 ) , V_37 -> V_80 , V_14 ) ;
if ( V_82 )
goto V_61;
V_82 = F_96 ( V_133 , V_37 , V_48 ) ;
if ( V_82 ) {
F_33 ( V_133 ) ;
goto V_61;
}
V_134 = F_101 ( V_14 ) ;
if ( V_134 &&
( V_134 != F_102 ( V_133 ) ) ) {
F_38 ( L_23 ,
V_134 -> V_13 ) ;
F_33 ( V_133 ) ;
V_82 = - V_44 ;
goto V_61;
}
F_103 ( V_14 ) ;
if ( F_104 ( V_14 ) == V_135 )
F_105 ( V_14 , F_106 ( V_133 ) ) ;
else if ( F_104 ( V_14 ) != F_106 ( V_133 ) ) {
F_38 ( L_24 ) ;
F_33 ( V_133 ) ;
F_107 ( V_14 ) ;
V_82 = - V_44 ;
goto V_61;
}
V_82 = F_108 ( V_14 ) ;
if ( V_82 ) {
F_38 ( L_25 ) ;
F_33 ( V_133 ) ;
F_107 ( V_14 ) ;
goto V_61;
}
F_107 ( V_14 ) ;
F_22 ( & V_24 ) ;
V_12 = F_14 ( V_14 ) ;
if ( ! V_12 || V_12 -> V_14 != V_14 ) {
F_38 ( L_12 ) ;
F_33 ( V_133 ) ;
F_28 ( & V_24 ) ;
V_82 = - V_43 ;
goto V_61;
}
if ( V_12 -> V_21 )
F_33 ( V_12 -> V_21 ) ;
V_12 -> V_21 = V_133 ;
F_28 ( & V_24 ) ;
V_37 -> V_41 |= V_86 ;
F_61 ( V_14 , V_37 ) ;
V_61:
F_15 ( V_14 ) ;
return V_82 ;
}
static int F_109 ( struct V_36 * V_37 , T_2 V_48 )
{
struct V_11 * V_12 ;
struct V_17 * V_14 ;
F_22 ( & V_24 ) ;
V_12 = F_71 ( V_37 ) ;
if ( ! V_12 ) {
F_75 ( L_13 ) ;
F_28 ( & V_24 ) ;
return - V_43 ;
}
if ( V_12 -> V_21 ) {
F_33 ( V_12 -> V_21 ) ;
V_12 -> V_21 = NULL ;
}
V_37 -> V_41 &= ~ V_86 ;
F_61 ( V_12 -> V_14 , V_37 ) ;
V_14 = V_12 -> V_14 ;
F_28 ( & V_24 ) ;
F_15 ( V_14 ) ;
return 0 ;
}
static void F_110 ( struct V_28 * V_29 ,
struct V_36 * V_37 , T_2 V_48 )
{
unsigned int V_136 = 0 ;
struct V_1 * V_137 ;
T_2 V_52 , V_54 ;
struct V_138 * V_139 ;
struct V_140 * V_141 ;
V_141 = F_46 ( V_37 , V_48 , & V_52 ) ;
F_111 (tmp, dm_table_get_devices(table))
V_136 ++ ;
V_54 = sizeof( * V_141 ) + ( sizeof( * V_141 -> V_16 ) * V_136 ) ;
if ( V_52 < V_54 ) {
V_37 -> V_41 |= V_60 ;
return;
}
V_141 -> V_136 = V_136 ;
V_136 = 0 ;
F_8 (dd, dm_table_get_devices(table), list)
V_141 -> V_16 [ V_136 ++ ] = F_49 ( V_139 -> V_142 . V_143 -> V_144 ) ;
V_37 -> V_49 = V_37 -> V_53 + V_54 ;
}
static int F_112 ( struct V_36 * V_37 , T_2 V_48 )
{
struct V_17 * V_14 ;
struct V_28 * V_29 ;
V_14 = F_73 ( V_37 ) ;
if ( ! V_14 )
return - V_43 ;
F_61 ( V_14 , V_37 ) ;
V_29 = F_60 ( V_14 , V_37 ) ;
if ( V_29 ) {
F_110 ( V_29 , V_37 , V_48 ) ;
F_32 ( V_29 ) ;
}
F_15 ( V_14 ) ;
return 0 ;
}
static int F_113 ( struct V_36 * V_37 , T_2 V_48 )
{
struct V_17 * V_14 ;
struct V_28 * V_29 ;
V_14 = F_73 ( V_37 ) ;
if ( ! V_14 )
return - V_43 ;
F_61 ( V_14 , V_37 ) ;
V_29 = F_60 ( V_14 , V_37 ) ;
if ( V_29 ) {
F_90 ( V_29 , V_37 , V_48 ) ;
F_32 ( V_29 ) ;
}
F_15 ( V_14 ) ;
return 0 ;
}
static bool F_114 ( char * V_145 , unsigned V_146 )
{
return ! V_146 || strlen ( V_145 ) + 1 >= V_146 ;
}
static int F_115 ( struct V_17 * V_14 , unsigned V_147 , char * * V_148 ,
char * V_145 , unsigned V_146 )
{
return 2 ;
}
static int F_116 ( struct V_36 * V_37 , T_2 V_48 )
{
int V_82 , V_147 ;
char * * V_148 ;
struct V_17 * V_14 ;
struct V_28 * V_29 ;
struct V_119 * V_120 ;
struct V_149 * V_150 = ( void * ) V_37 + V_37 -> V_53 ;
T_2 V_146 ;
char * V_145 = F_46 ( V_37 , V_48 , & V_146 ) ;
V_14 = F_73 ( V_37 ) ;
if ( ! V_14 )
return - V_43 ;
if ( V_150 < (struct V_149 * ) V_37 -> V_88 ||
F_76 ( V_150 -> V_151 , ( void * ) V_37 + V_48 ) ) {
F_38 ( L_26 ) ;
V_82 = - V_44 ;
goto V_61;
}
V_82 = F_117 ( & V_147 , & V_148 , V_150 -> V_151 ) ;
if ( V_82 ) {
F_38 ( L_27 ) ;
goto V_61;
}
if ( ! V_147 ) {
F_38 ( L_28 ) ;
goto V_152;
}
V_82 = F_115 ( V_14 , V_147 , V_148 , V_145 , V_146 ) ;
if ( V_82 <= 1 )
goto V_152;
V_29 = F_30 ( V_14 ) ;
if ( ! V_29 )
goto V_152;
if ( F_118 ( V_14 ) ) {
V_82 = - V_43 ;
goto V_153;
}
V_120 = F_119 ( V_29 , V_150 -> V_154 ) ;
if ( ! F_120 ( V_120 ) ) {
F_38 ( L_29 ) ;
V_82 = - V_44 ;
} else if ( V_120 -> type -> V_151 )
V_82 = V_120 -> type -> V_151 ( V_120 , V_147 , V_148 ) ;
else {
F_38 ( L_30 ) ;
V_82 = - V_44 ;
}
V_153:
F_32 ( V_29 ) ;
V_152:
F_19 ( V_148 ) ;
V_61:
if ( V_82 >= 0 )
F_61 ( V_14 , V_37 ) ;
if ( V_82 == 1 ) {
V_37 -> V_41 |= V_155 ;
if ( F_114 ( V_145 , V_146 ) )
V_37 -> V_41 |= V_60 ;
else
V_37 -> V_49 = V_37 -> V_53 + strlen ( V_145 ) + 1 ;
V_82 = 0 ;
}
F_15 ( V_14 ) ;
return V_82 ;
}
static T_5 F_121 ( unsigned int V_156 , int * V_157 )
{
static struct {
int V_156 ;
int V_41 ;
T_5 V_158 ;
} V_159 [] = {
{ V_160 , 0 , NULL } ,
{ V_161 , V_162 , F_44 } ,
{ V_163 , 0 , F_47 } ,
{ V_164 , V_162 , F_68 } ,
{ V_165 , V_162 , F_74 } ,
{ V_166 , 0 , F_77 } ,
{ V_167 , V_162 , F_88 } ,
{ V_168 , V_162 , F_89 } ,
{ V_169 , 0 , F_92 } ,
{ V_170 , 0 , F_99 } ,
{ V_171 , V_162 , F_109 } ,
{ V_172 , 0 , F_112 } ,
{ V_173 , 0 , F_113 } ,
{ V_174 , 0 , F_53 } ,
{ V_175 , 0 , F_116 } ,
{ V_176 , 0 , F_80 }
} ;
if ( F_122 ( V_156 >= F_123 ( V_159 ) ) )
return NULL ;
* V_157 = V_159 [ V_156 ] . V_41 ;
return V_159 [ V_156 ] . V_158 ;
}
static int F_124 ( unsigned int V_156 , struct V_36 T_6 * V_177 )
{
V_63 V_71 [ 3 ] ;
int V_82 = 0 ;
if ( F_125 ( V_71 , V_177 -> V_71 , sizeof( V_71 ) ) )
return - V_178 ;
if ( ( V_179 != V_71 [ 0 ] ) ||
( V_180 < V_71 [ 1 ] ) ) {
F_38 ( L_31
L_32 ,
V_179 , V_180 ,
V_181 ,
V_71 [ 0 ] , V_71 [ 1 ] , V_71 [ 2 ] , V_156 ) ;
V_82 = - V_44 ;
}
V_71 [ 0 ] = V_179 ;
V_71 [ 1 ] = V_180 ;
V_71 [ 2 ] = V_181 ;
if ( F_126 ( V_177 -> V_71 , V_71 , sizeof( V_71 ) ) )
return - V_178 ;
return V_82 ;
}
static void F_127 ( struct V_36 * V_37 , T_2 V_48 , int V_182 )
{
if ( V_182 & V_183 )
memset ( V_37 , 0 , V_48 ) ;
if ( V_182 & V_184 )
F_19 ( V_37 ) ;
if ( V_182 & V_185 )
F_128 ( V_37 ) ;
}
static int F_129 ( struct V_36 T_6 * V_177 , struct V_36 * V_186 ,
int V_157 ,
struct V_36 * * V_37 , int * V_182 )
{
struct V_36 * V_187 ;
int V_188 ;
const T_2 V_189 = sizeof( * V_186 ) - sizeof( V_186 -> V_88 ) ;
if ( F_125 ( V_186 , V_177 , V_189 ) )
return - V_178 ;
if ( V_186 -> V_49 < V_189 )
return - V_44 ;
V_188 = V_186 -> V_41 & V_190 ;
* V_182 = V_188 ? V_183 : 0 ;
if ( V_157 & V_162 ) {
V_187 = V_186 ;
V_187 -> V_49 = V_189 ;
goto V_191;
}
V_187 = NULL ;
if ( V_186 -> V_49 <= V_192 ) {
V_187 = F_17 ( V_186 -> V_49 , V_193 | V_194 | V_195 | V_196 ) ;
if ( V_187 )
* V_182 |= V_184 ;
}
if ( ! V_187 ) {
V_187 = F_130 ( V_186 -> V_49 , V_193 | V_197 | V_198 , V_199 ) ;
if ( V_187 )
* V_182 |= V_185 ;
}
if ( ! V_187 ) {
if ( V_188 && F_131 ( V_177 , V_186 -> V_49 ) )
return - V_178 ;
return - V_23 ;
}
if ( F_125 ( V_187 , V_177 , V_186 -> V_49 ) )
goto V_25;
V_191:
if ( V_187 -> V_49 != V_186 -> V_49 ) {
F_132 ( L_33 ) ;
goto V_25;
}
if ( V_188 && F_131 ( V_177 , V_186 -> V_49 ) )
goto V_25;
* V_37 = V_187 ;
return 0 ;
V_25:
F_127 ( V_187 , V_186 -> V_49 , * V_182 ) ;
return - V_178 ;
}
static int F_133 ( T_7 V_156 , struct V_36 * V_37 )
{
V_37 -> V_41 &= ~ V_60 ;
V_37 -> V_41 &= ~ V_47 ;
V_37 -> V_41 &= ~ V_190 ;
V_37 -> V_41 &= ~ V_155 ;
if ( V_156 == V_161 ||
V_156 == V_163 ||
V_156 == V_174 )
return 0 ;
if ( ( V_156 == V_164 ) ) {
if ( ! * V_37 -> V_13 ) {
F_38 ( L_34 ) ;
return - V_44 ;
}
} else if ( ( * V_37 -> V_15 && * V_37 -> V_13 ) ) {
F_38 ( L_35 , V_156 ) ;
return - V_44 ;
}
V_37 -> V_13 [ V_90 - 1 ] = '\0' ;
V_37 -> V_15 [ V_89 - 1 ] = '\0' ;
return 0 ;
}
static int F_134 ( T_7 V_200 , struct V_36 T_6 * V_177 )
{
int V_82 = 0 ;
int V_157 ;
int V_182 ;
unsigned int V_156 ;
struct V_36 * V_201 ( V_37 ) ;
T_5 V_158 = NULL ;
T_2 V_202 ;
struct V_36 V_186 ;
if ( ! F_135 ( V_203 ) )
return - V_204 ;
if ( F_136 ( V_200 ) != V_205 )
return - V_206 ;
V_156 = F_137 ( V_200 ) ;
V_82 = F_124 ( V_156 , V_177 ) ;
if ( V_82 )
return V_82 ;
if ( V_156 == V_160 )
return 0 ;
V_158 = F_121 ( V_156 , & V_157 ) ;
if ( ! V_158 ) {
F_38 ( L_36 , V_200 ) ;
return - V_206 ;
}
V_82 = F_129 ( V_177 , & V_186 , V_157 , & V_37 , & V_182 ) ;
if ( V_82 )
return V_82 ;
V_202 = V_37 -> V_49 ;
V_82 = F_133 ( V_156 , V_37 ) ;
if ( V_82 )
goto V_61;
V_37 -> V_49 = sizeof( * V_37 ) ;
V_82 = V_158 ( V_37 , V_202 ) ;
if ( F_122 ( V_37 -> V_41 & V_60 ) &&
F_122 ( V_157 & V_162 ) )
F_132 ( L_37 , V_156 ) ;
if ( ! V_82 && F_126 ( V_177 , V_37 , V_37 -> V_49 ) )
V_82 = - V_178 ;
V_61:
F_127 ( V_37 , V_202 , V_182 ) ;
return V_82 ;
}
static long F_138 ( struct V_207 * V_207 , T_7 V_200 , T_8 V_208 )
{
return ( long ) F_134 ( V_200 , (struct V_36 T_6 * ) V_208 ) ;
}
static long F_139 ( struct V_207 * V_207 , T_7 V_200 , T_8 V_208 )
{
return ( long ) F_138 ( V_207 , V_200 , ( T_8 ) F_140 ( V_208 ) ) ;
}
int T_9 F_141 ( void )
{
int V_82 ;
V_82 = F_3 () ;
if ( V_82 )
return V_82 ;
V_82 = F_142 ( & V_209 ) ;
if ( V_82 ) {
F_132 ( L_38 ) ;
F_4 () ;
return V_82 ;
}
F_143 ( L_39 , V_179 ,
V_180 , V_181 , V_210 ,
V_211 ) ;
return 0 ;
}
void F_144 ( void )
{
if ( F_145 ( & V_209 ) < 0 )
F_132 ( L_40 ) ;
F_4 () ;
}
int F_146 ( struct V_17 * V_14 , char * V_13 , char * V_15 )
{
int V_82 = 0 ;
struct V_11 * V_12 ;
if ( ! V_14 )
return - V_43 ;
F_25 ( & V_26 ) ;
V_12 = F_14 ( V_14 ) ;
if ( ! V_12 || V_12 -> V_14 != V_14 ) {
V_82 = - V_43 ;
goto V_61;
}
if ( V_13 )
strcpy ( V_13 , V_12 -> V_13 ) ;
if ( V_15 )
strcpy ( V_15 , V_12 -> V_15 ? : L_8 ) ;
V_61:
F_27 ( & V_26 ) ;
return V_82 ;
}
