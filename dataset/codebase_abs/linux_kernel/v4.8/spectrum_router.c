static bool
F_1 ( struct V_1 * V_2 ,
struct V_1 * V_3 )
{
unsigned char V_4 ;
F_2 (prefix, prefix_usage1) {
if ( ! F_3 ( V_4 , V_3 -> V_5 ) )
return false ;
}
return true ;
}
static bool
F_4 ( struct V_1 * V_2 ,
struct V_1 * V_3 )
{
return ! memcmp ( V_2 , V_3 , sizeof( * V_2 ) ) ;
}
static bool
F_5 ( struct V_1 * V_6 )
{
struct V_1 V_7 = { { 0 } } ;
return F_4 ( V_6 , & V_7 ) ;
}
static void
F_6 ( struct V_1 * V_2 ,
struct V_1 * V_3 )
{
memcpy ( V_2 , V_3 , sizeof( * V_2 ) ) ;
}
static void
F_7 ( struct V_1 * V_6 )
{
memset ( V_6 , 0 , sizeof( * V_6 ) ) ;
}
static void
F_8 ( struct V_1 * V_6 ,
unsigned char V_8 )
{
F_9 ( V_8 , V_6 -> V_5 ) ;
}
static void
F_10 ( struct V_1 * V_6 ,
unsigned char V_8 )
{
F_11 ( V_8 , V_6 -> V_5 ) ;
}
static int F_12 ( struct V_9 * V_10 ,
struct V_11 * V_12 )
{
unsigned char V_8 = V_12 -> V_13 . V_8 ;
int V_14 ;
V_14 = F_13 ( & V_10 -> V_15 , & V_12 -> V_16 ,
V_17 ) ;
if ( V_14 )
return V_14 ;
if ( V_10 -> V_18 [ V_8 ] ++ == 0 )
F_8 ( & V_10 -> V_6 , V_8 ) ;
return 0 ;
}
static void F_14 ( struct V_9 * V_10 ,
struct V_11 * V_12 )
{
unsigned char V_8 = V_12 -> V_13 . V_8 ;
if ( -- V_10 -> V_18 [ V_8 ] == 0 )
F_10 ( & V_10 -> V_6 , V_8 ) ;
F_15 ( & V_10 -> V_15 , & V_12 -> V_16 ,
V_17 ) ;
}
static struct V_11 *
F_16 ( struct V_9 * V_10 , const void * V_19 ,
T_1 V_20 , unsigned char V_8 ,
struct V_21 * V_22 )
{
struct V_11 * V_12 ;
V_12 = F_17 ( sizeof( * V_12 ) , V_23 ) ;
if ( ! V_12 )
return NULL ;
V_12 -> V_13 . V_22 = V_22 ;
memcpy ( V_12 -> V_13 . V_19 , V_19 , V_20 ) ;
V_12 -> V_13 . V_8 = V_8 ;
return V_12 ;
}
static void F_18 ( struct V_11 * V_12 )
{
F_19 ( V_12 ) ;
}
static struct V_11 *
F_20 ( struct V_9 * V_10 , const void * V_19 ,
T_1 V_20 , unsigned char V_8 ,
struct V_21 * V_22 )
{
struct V_24 V_13 ;
memset ( & V_13 , 0 , sizeof( V_13 ) ) ;
V_13 . V_22 = V_22 ;
memcpy ( V_13 . V_19 , V_19 , V_20 ) ;
V_13 . V_8 = V_8 ;
return F_21 ( & V_10 -> V_15 , & V_13 , V_17 ) ;
}
static struct V_9 * F_22 ( void )
{
struct V_9 * V_10 ;
int V_14 ;
V_10 = F_17 ( sizeof( * V_10 ) , V_23 ) ;
if ( ! V_10 )
return F_23 ( - V_25 ) ;
V_14 = F_24 ( & V_10 -> V_15 , & V_17 ) ;
if ( V_14 )
goto V_26;
return V_10 ;
V_26:
F_19 ( V_10 ) ;
return F_23 ( V_14 ) ;
}
static void F_25 ( struct V_9 * V_10 )
{
F_26 ( & V_10 -> V_15 ) ;
F_19 ( V_10 ) ;
}
static struct V_27 *
F_27 ( struct V_28 * V_28 , bool V_29 )
{
static struct V_27 * V_30 ;
int V_31 ;
for ( V_31 = 0 ; V_31 < V_32 ; V_31 ++ ) {
V_30 = & V_28 -> V_33 . V_34 [ V_31 ] ;
if ( V_30 -> V_35 == 0 ) {
if ( V_29 )
V_29 = false ;
else
return V_30 ;
}
}
return NULL ;
}
static int F_28 ( struct V_28 * V_28 ,
struct V_27 * V_30 )
{
char V_36 [ V_37 ] ;
F_29 ( V_36 , true , V_30 -> V_38 , V_30 -> V_39 ) ;
return F_30 ( V_28 -> V_40 , F_31 ( V_41 ) , V_36 ) ;
}
static int F_32 ( struct V_28 * V_28 ,
struct V_27 * V_30 )
{
char V_36 [ V_37 ] ;
F_29 ( V_36 , false , V_30 -> V_38 , V_30 -> V_39 ) ;
return F_30 ( V_28 -> V_40 , F_31 ( V_41 ) , V_36 ) ;
}
static int
F_33 ( struct V_28 * V_28 ,
struct V_1 * V_6 ,
struct V_27 * V_30 )
{
char V_42 [ V_43 ] ;
T_2 V_44 = 0 ;
T_2 V_4 ;
T_2 V_45 = V_46 ;
F_2 (prefix, prefix_usage)
V_44 = V_4 ;
F_34 ( V_42 , V_44 , V_30 -> V_39 ) ;
F_2 (prefix, prefix_usage) {
if ( V_4 == 0 )
continue;
F_35 ( V_42 , V_4 , V_45 ,
V_46 ) ;
V_45 = V_4 ;
}
return F_30 ( V_28 -> V_40 , F_31 ( V_47 ) , V_42 ) ;
}
static struct V_27 *
F_36 ( struct V_28 * V_28 ,
struct V_1 * V_6 ,
enum V_48 V_38 , bool V_29 )
{
struct V_27 * V_30 ;
int V_14 ;
V_30 = F_27 ( V_28 , V_29 ) ;
if ( ! V_30 )
return F_23 ( - V_49 ) ;
V_30 -> V_38 = V_38 ;
V_14 = F_28 ( V_28 , V_30 ) ;
if ( V_14 )
return F_23 ( V_14 ) ;
V_14 = F_33 ( V_28 , V_6 ,
V_30 ) ;
if ( V_14 )
goto V_50;
return V_30 ;
V_50:
F_32 ( V_28 , V_30 ) ;
return F_23 ( V_14 ) ;
}
static int F_37 ( struct V_28 * V_28 ,
struct V_27 * V_30 )
{
return F_32 ( V_28 , V_30 ) ;
}
static struct V_27 *
F_38 ( struct V_28 * V_28 ,
struct V_1 * V_6 ,
enum V_48 V_38 , bool V_29 )
{
struct V_27 * V_30 ;
int V_31 ;
for ( V_31 = 0 ; V_31 < V_32 ; V_31 ++ ) {
V_30 = & V_28 -> V_33 . V_34 [ V_31 ] ;
if ( V_30 -> V_38 == V_38 &&
F_4 ( & V_30 -> V_6 ,
V_6 ) )
goto V_51;
}
V_30 = F_36 ( V_28 , V_6 ,
V_38 , V_29 ) ;
if ( F_39 ( V_30 ) )
return V_30 ;
V_51:
V_30 -> V_35 ++ ;
return V_30 ;
}
static int F_40 ( struct V_28 * V_28 ,
struct V_27 * V_30 )
{
if ( -- V_30 -> V_35 == 0 )
return F_37 ( V_28 , V_30 ) ;
return 0 ;
}
static void F_41 ( struct V_28 * V_28 )
{
struct V_27 * V_30 ;
int V_31 ;
for ( V_31 = 0 ; V_31 < V_32 ; V_31 ++ ) {
V_30 = & V_28 -> V_33 . V_34 [ V_31 ] ;
V_30 -> V_39 = V_31 + V_52 ;
}
}
static struct V_53 * F_42 ( struct V_28 * V_28 )
{
struct V_53 * V_54 ;
int V_31 ;
for ( V_31 = 0 ; V_31 < V_55 ; V_31 ++ ) {
V_54 = & V_28 -> V_33 . V_56 [ V_31 ] ;
if ( ! V_54 -> V_57 )
return V_54 ;
}
return NULL ;
}
static int F_43 ( struct V_28 * V_28 ,
struct V_53 * V_54 )
{
char V_58 [ V_59 ] ;
F_44 ( V_58 , V_54 -> V_39 , V_54 -> V_38 , V_54 -> V_30 -> V_39 ) ;
return F_30 ( V_28 -> V_40 , F_31 ( V_60 ) , V_58 ) ;
}
static int F_45 ( struct V_28 * V_28 ,
struct V_53 * V_54 )
{
char V_58 [ V_59 ] ;
F_44 ( V_58 , V_54 -> V_39 , V_54 -> V_38 , 0 ) ;
return F_30 ( V_28 -> V_40 , F_31 ( V_60 ) , V_58 ) ;
}
static T_3 F_46 ( T_3 V_61 )
{
if ( V_61 == V_62 )
V_61 = V_63 ;
return V_61 ;
}
static struct V_53 * F_47 ( struct V_28 * V_28 ,
T_3 V_61 ,
enum V_48 V_38 )
{
struct V_53 * V_54 ;
int V_31 ;
V_61 = F_46 ( V_61 ) ;
for ( V_31 = 0 ; V_31 < V_55 ; V_31 ++ ) {
V_54 = & V_28 -> V_33 . V_56 [ V_31 ] ;
if ( V_54 -> V_57 && V_54 -> V_38 == V_38 && V_54 -> V_61 == V_61 )
return V_54 ;
}
return NULL ;
}
static struct V_53 * F_48 ( struct V_28 * V_28 ,
unsigned char V_8 ,
T_3 V_61 ,
enum V_48 V_38 )
{
struct V_1 V_64 ;
struct V_27 * V_30 ;
struct V_53 * V_54 ;
int V_14 ;
V_54 = F_42 ( V_28 ) ;
if ( ! V_54 )
return F_23 ( - V_49 ) ;
V_54 -> V_10 = F_22 () ;
if ( F_39 ( V_54 -> V_10 ) )
return F_49 ( V_54 -> V_10 ) ;
V_54 -> V_38 = V_38 ;
V_54 -> V_61 = V_61 ;
F_7 ( & V_64 ) ;
F_8 ( & V_64 , V_8 ) ;
V_30 = F_38 ( V_28 , & V_64 ,
V_38 , true ) ;
if ( F_39 ( V_30 ) ) {
V_14 = F_50 ( V_30 ) ;
goto V_65;
}
V_54 -> V_30 = V_30 ;
V_14 = F_43 ( V_28 , V_54 ) ;
if ( V_14 )
goto V_66;
V_54 -> V_57 = true ;
return V_54 ;
V_66:
F_40 ( V_28 , V_54 -> V_30 ) ;
V_65:
F_25 ( V_54 -> V_10 ) ;
return F_23 ( V_14 ) ;
}
static void F_51 ( struct V_28 * V_28 ,
struct V_53 * V_54 )
{
F_45 ( V_28 , V_54 ) ;
F_40 ( V_28 , V_54 -> V_30 ) ;
F_25 ( V_54 -> V_10 ) ;
V_54 -> V_57 = false ;
}
static int
F_52 ( struct V_28 * V_28 , struct V_53 * V_54 ,
struct V_1 * V_64 )
{
struct V_27 * V_30 ;
if ( F_4 ( V_64 ,
& V_54 -> V_30 -> V_6 ) )
return 0 ;
V_30 = F_38 ( V_28 , V_64 ,
V_54 -> V_38 , false ) ;
if ( F_39 ( V_30 ) ) {
if ( F_1 ( V_64 ,
& V_54 -> V_30 -> V_6 ) )
return 0 ;
return F_50 ( V_30 ) ;
}
F_45 ( V_28 , V_54 ) ;
F_40 ( V_28 , V_54 -> V_30 ) ;
V_54 -> V_30 = V_30 ;
return F_43 ( V_28 , V_54 ) ;
}
static struct V_53 * F_53 ( struct V_28 * V_28 ,
unsigned char V_8 ,
T_3 V_61 ,
enum V_48 V_38 )
{
struct V_53 * V_54 ;
int V_14 ;
V_61 = F_46 ( V_61 ) ;
V_54 = F_47 ( V_28 , V_61 , V_38 ) ;
if ( ! V_54 ) {
V_54 = F_48 ( V_28 , V_8 , V_61 , V_38 ) ;
if ( F_39 ( V_54 ) )
return V_54 ;
} else {
struct V_1 V_64 ;
F_6 ( & V_64 ,
& V_54 -> V_10 -> V_6 ) ;
F_8 ( & V_64 , V_8 ) ;
V_14 = F_52 ( V_28 , V_54 ,
& V_64 ) ;
if ( V_14 )
return F_23 ( V_14 ) ;
}
return V_54 ;
}
static void F_54 ( struct V_28 * V_28 , struct V_53 * V_54 )
{
if ( F_5 ( & V_54 -> V_10 -> V_6 ) )
F_51 ( V_28 , V_54 ) ;
else
F_52 ( V_28 , V_54 ,
& V_54 -> V_10 -> V_6 ) ;
}
static void F_55 ( struct V_28 * V_28 )
{
struct V_53 * V_54 ;
int V_31 ;
for ( V_31 = 0 ; V_31 < V_55 ; V_31 ++ ) {
V_54 = & V_28 -> V_33 . V_56 [ V_31 ] ;
V_54 -> V_39 = V_31 ;
}
}
static int
F_56 ( struct V_28 * V_28 ,
struct V_67 * V_68 )
{
return F_13 ( & V_28 -> V_33 . V_69 ,
& V_68 -> V_16 ,
V_70 ) ;
}
static void
F_57 ( struct V_28 * V_28 ,
struct V_67 * V_68 )
{
F_15 ( & V_28 -> V_33 . V_69 ,
& V_68 -> V_16 ,
V_70 ) ;
}
static struct V_67 *
F_58 ( const void * V_19 , T_1 V_20 ,
struct V_21 * V_22 , T_4 V_71 ,
struct V_72 * V_73 )
{
struct V_67 * V_68 ;
V_68 = F_17 ( sizeof( * V_68 ) , V_74 ) ;
if ( ! V_68 )
return NULL ;
memcpy ( V_68 -> V_13 . V_19 , V_19 , V_20 ) ;
V_68 -> V_13 . V_22 = V_22 ;
V_68 -> V_71 = V_71 ;
V_68 -> V_73 = V_73 ;
F_59 ( & V_68 -> V_75 , V_76 ) ;
F_60 ( & V_68 -> V_77 ) ;
return V_68 ;
}
static void
F_61 ( struct V_67 * V_68 )
{
F_19 ( V_68 ) ;
}
static struct V_67 *
F_62 ( struct V_28 * V_28 , const void * V_19 ,
T_1 V_20 , struct V_21 * V_22 )
{
struct V_78 V_13 = { { 0 } } ;
memcpy ( V_13 . V_19 , V_19 , V_20 ) ;
V_13 . V_22 = V_22 ;
return F_21 ( & V_28 -> V_33 . V_69 ,
& V_13 , V_70 ) ;
}
int F_63 ( struct V_21 * V_22 ,
struct V_72 * V_73 )
{
struct V_79 * V_79 = F_64 ( V_22 ) ;
struct V_28 * V_28 = V_79 -> V_28 ;
struct V_67 * V_68 ;
struct V_80 * V_81 ;
T_3 V_82 ;
int V_14 ;
if ( V_73 -> V_83 != & V_84 )
return 0 ;
V_82 = F_65 ( * ( ( V_85 * ) V_73 -> V_86 ) ) ;
V_68 = F_62 ( V_28 , & V_82 , sizeof( V_82 ) ,
V_73 -> V_22 ) ;
if ( V_68 ) {
F_66 ( V_68 -> V_73 != V_73 ) ;
return 0 ;
}
V_81 = F_67 ( V_28 , V_73 -> V_22 ) ;
if ( F_66 ( ! V_81 ) )
return - V_87 ;
V_68 = F_58 ( & V_82 , sizeof( V_82 ) , V_73 -> V_22 ,
V_81 -> V_71 , V_73 ) ;
if ( ! V_68 )
return - V_25 ;
V_14 = F_56 ( V_28 , V_68 ) ;
if ( V_14 )
goto V_88;
return 0 ;
V_88:
F_61 ( V_68 ) ;
return V_14 ;
}
void F_68 ( struct V_21 * V_22 ,
struct V_72 * V_73 )
{
struct V_79 * V_79 = F_64 ( V_22 ) ;
struct V_28 * V_28 = V_79 -> V_28 ;
struct V_67 * V_68 ;
T_3 V_82 ;
if ( V_73 -> V_83 != & V_84 )
return;
V_82 = F_65 ( * ( ( V_85 * ) V_73 -> V_86 ) ) ;
V_68 = F_62 ( V_28 , & V_82 , sizeof( V_82 ) ,
V_73 -> V_22 ) ;
if ( ! V_68 )
return;
F_57 ( V_28 , V_68 ) ;
F_61 ( V_68 ) ;
}
static void
F_69 ( struct V_28 * V_28 )
{
unsigned long V_89 = F_70 ( & V_84 . V_90 , V_91 ) ;
V_28 -> V_33 . V_92 . V_89 = F_71 ( V_89 ) ;
}
static void F_72 ( struct V_28 * V_28 ,
char * V_93 ,
int V_94 )
{
struct V_21 * V_22 ;
struct V_72 * V_73 ;
V_85 V_95 ;
T_3 V_82 ;
T_4 V_71 ;
F_73 ( V_93 , V_94 , & V_71 , & V_82 ) ;
if ( ! V_28 -> V_96 [ V_71 ] ) {
F_74 ( V_28 -> V_97 -> V_22 , L_1 ) ;
return;
}
V_95 = F_75 ( V_82 ) ;
V_22 = V_28 -> V_96 [ V_71 ] -> V_22 ;
V_73 = F_76 ( & V_84 , & V_95 , V_22 ) ;
if ( ! V_73 ) {
F_77 ( V_22 , L_2 ,
& V_82 ) ;
return;
}
F_78 ( V_22 , L_3 , & V_82 ) ;
F_79 ( V_73 , NULL ) ;
F_80 ( V_73 ) ;
}
static void F_81 ( struct V_28 * V_28 ,
char * V_93 ,
int V_98 )
{
T_2 V_99 ;
int V_31 ;
V_99 = F_82 ( V_93 ,
V_98 ) ;
V_99 ++ ;
for ( V_31 = 0 ; V_31 < V_99 ; V_31 ++ ) {
int V_94 ;
V_94 = V_98 * V_100 + V_31 ;
F_72 ( V_28 , V_93 ,
V_94 ) ;
}
}
static void F_83 ( struct V_28 * V_28 ,
char * V_93 , int V_98 )
{
switch ( F_84 ( V_93 , V_98 ) ) {
case V_101 :
F_81 ( V_28 , V_93 ,
V_98 ) ;
break;
case V_102 :
F_85 ( 1 ) ;
break;
}
}
static int F_86 ( struct V_28 * V_28 )
{
char * V_93 ;
T_2 V_103 ;
int V_31 , V_14 ;
V_93 = F_87 ( V_104 , V_23 ) ;
if ( ! V_93 )
return - V_25 ;
F_88 () ;
do {
F_89 ( V_93 , V_101 ) ;
V_14 = F_90 ( V_28 -> V_40 , F_31 ( V_105 ) ,
V_93 ) ;
if ( V_14 ) {
F_74 ( V_28 -> V_97 -> V_22 , L_4 ) ;
break;
}
V_103 = F_91 ( V_93 ) ;
for ( V_31 = 0 ; V_31 < V_103 ; V_31 ++ )
F_83 ( V_28 , V_93 ,
V_31 ) ;
} while ( V_103 );
F_92 () ;
F_19 ( V_93 ) ;
return V_14 ;
}
static void F_93 ( struct V_28 * V_28 )
{
struct V_67 * V_68 ;
F_88 () ;
F_94 (neigh_entry, &mlxsw_sp->router.nexthop_neighs_list,
nexthop_neighs_list_node) {
if ( ! F_95 ( & V_68 -> V_77 ) )
F_79 ( V_68 -> V_73 , NULL ) ;
}
F_92 () ;
}
static void
F_96 ( struct V_28 * V_28 )
{
unsigned long V_89 = V_28 -> V_33 . V_92 . V_89 ;
F_97 ( & V_28 -> V_33 . V_92 . V_75 ,
F_98 ( V_89 ) ) ;
}
static void F_99 ( struct V_106 * V_107 )
{
struct V_28 * V_28 = F_100 ( V_107 , struct V_28 ,
V_33 . V_92 . V_75 . V_107 ) ;
int V_14 ;
V_14 = F_86 ( V_28 ) ;
if ( V_14 )
F_101 ( V_28 -> V_97 -> V_22 , L_5 ) ;
F_93 ( V_28 ) ;
F_96 ( V_28 ) ;
}
static void F_102 ( struct V_106 * V_107 )
{
struct V_67 * V_68 ;
struct V_28 * V_28 = F_100 ( V_107 , struct V_28 ,
V_33 . V_108 . V_107 ) ;
F_88 () ;
F_94 (neigh_entry, &mlxsw_sp->router.nexthop_neighs_list,
nexthop_neighs_list_node) {
if ( ! ( V_68 -> V_73 -> V_109 & V_110 ) &&
! F_95 ( & V_68 -> V_77 ) )
F_79 ( V_68 -> V_73 , NULL ) ;
}
F_92 () ;
F_97 ( & V_28 -> V_33 . V_108 ,
V_111 ) ;
}
static void V_76 ( struct V_106 * V_107 )
{
struct V_67 * V_68 =
F_100 ( V_107 , struct V_67 , V_75 . V_107 ) ;
struct V_72 * V_73 = V_68 -> V_73 ;
struct V_79 * V_79 = V_68 -> V_79 ;
struct V_28 * V_28 = V_79 -> V_28 ;
char V_112 [ V_113 ] ;
struct V_21 * V_22 ;
bool V_114 ;
T_2 V_109 ;
bool V_115 ;
bool V_116 ;
bool V_117 ;
T_3 V_82 ;
int V_14 ;
F_103 ( & V_73 -> V_118 ) ;
V_82 = F_65 ( * ( ( V_85 * ) V_73 -> V_86 ) ) ;
memcpy ( V_68 -> V_119 , V_73 -> V_119 , sizeof( V_68 -> V_119 ) ) ;
V_109 = V_73 -> V_109 ;
V_22 = V_73 -> V_22 ;
F_104 ( & V_73 -> V_118 ) ;
V_114 = V_109 & V_110 ;
V_117 = ( ! V_68 -> V_120 ) && V_114 ;
V_115 = V_68 -> V_120 && V_114 ;
V_116 = V_68 -> V_120 && ! V_114 ;
if ( V_117 || V_115 ) {
F_105 ( V_112 , V_121 ,
V_68 -> V_71 ,
V_68 -> V_119 , V_82 ) ;
V_14 = F_30 ( V_28 -> V_40 ,
F_31 ( V_122 ) , V_112 ) ;
if ( V_14 ) {
F_77 ( V_22 , L_6 , & V_82 ) ;
V_68 -> V_120 = false ;
} else {
V_68 -> V_120 = true ;
}
F_106 ( V_28 , V_68 , false ) ;
} else if ( V_116 ) {
F_105 ( V_112 , V_123 ,
V_68 -> V_71 ,
V_68 -> V_119 , V_82 ) ;
V_14 = F_30 ( V_28 -> V_40 , F_31 ( V_122 ) ,
V_112 ) ;
if ( V_14 ) {
F_77 ( V_22 , L_7 , & V_82 ) ;
V_68 -> V_120 = true ;
} else {
V_68 -> V_120 = false ;
}
F_106 ( V_28 , V_68 , true ) ;
}
F_80 ( V_73 ) ;
F_107 ( V_79 ) ;
}
int F_108 ( struct V_124 * V_125 ,
unsigned long V_126 , void * V_127 )
{
struct V_67 * V_68 ;
struct V_79 * V_79 ;
struct V_28 * V_28 ;
unsigned long V_89 ;
struct V_21 * V_22 ;
struct V_128 * V_129 ;
struct V_72 * V_73 ;
T_3 V_82 ;
switch ( V_126 ) {
case V_130 :
V_129 = V_127 ;
if ( ! V_129 -> V_22 || V_129 -> V_83 != & V_84 )
return V_131 ;
V_79 = F_109 ( V_129 -> V_22 ) ;
if ( ! V_79 )
return V_131 ;
V_28 = V_79 -> V_28 ;
V_89 = F_71 ( F_70 ( V_129 , V_91 ) ) ;
V_28 -> V_33 . V_92 . V_89 = V_89 ;
F_107 ( V_79 ) ;
break;
case V_132 :
V_73 = V_127 ;
V_22 = V_73 -> V_22 ;
if ( V_73 -> V_83 != & V_84 )
return V_131 ;
V_79 = F_109 ( V_22 ) ;
if ( ! V_79 )
return V_131 ;
V_28 = V_79 -> V_28 ;
V_82 = F_65 ( * ( ( V_85 * ) V_73 -> V_86 ) ) ;
V_68 = F_62 ( V_28 ,
& V_82 ,
sizeof( V_85 ) ,
V_22 ) ;
if ( F_66 ( ! V_68 ) || F_66 ( V_68 -> V_73 != V_73 ) ) {
F_107 ( V_79 ) ;
return V_131 ;
}
V_68 -> V_79 = V_79 ;
F_110 ( V_73 ) ;
if ( ! F_97 ( & V_68 -> V_75 , 0 ) ) {
F_80 ( V_73 ) ;
F_107 ( V_79 ) ;
}
break;
}
return V_131 ;
}
static int F_111 ( struct V_28 * V_28 )
{
int V_14 ;
V_14 = F_24 ( & V_28 -> V_33 . V_69 ,
& V_70 ) ;
if ( V_14 )
return V_14 ;
F_69 ( V_28 ) ;
F_59 ( & V_28 -> V_33 . V_92 . V_75 ,
F_99 ) ;
F_59 ( & V_28 -> V_33 . V_108 ,
F_102 ) ;
F_97 ( & V_28 -> V_33 . V_92 . V_75 , 0 ) ;
F_97 ( & V_28 -> V_33 . V_108 , 0 ) ;
return 0 ;
}
static void F_112 ( struct V_28 * V_28 )
{
F_113 ( & V_28 -> V_33 . V_92 . V_75 ) ;
F_113 ( & V_28 -> V_33 . V_108 ) ;
F_26 ( & V_28 -> V_33 . V_69 ) ;
}
static int F_114 ( struct V_28 * V_28 ,
struct V_53 * V_54 ,
T_3 V_133 , T_4 V_134 ,
T_3 V_135 ,
T_4 V_136 )
{
char V_137 [ V_138 ] ;
F_115 ( V_137 , V_54 -> V_38 , V_54 -> V_39 ,
V_133 , V_134 ,
V_135 , V_136 ) ;
return F_30 ( V_28 -> V_40 , F_31 ( V_139 ) , V_137 ) ;
}
static int F_116 ( struct V_28 * V_28 ,
struct V_140 * V_141 ,
T_3 V_142 , T_4 V_143 )
{
struct V_11 * V_12 ;
struct V_53 * V_54 = NULL ;
int V_14 ;
F_94 (fib_entry, &nh_grp->fib_list, nexthop_group_node) {
if ( V_54 == V_12 -> V_54 )
continue;
V_54 = V_12 -> V_54 ;
V_14 = F_114 ( V_28 , V_54 ,
V_142 ,
V_143 ,
V_141 -> V_133 ,
V_141 -> V_134 ) ;
if ( V_14 )
return V_14 ;
}
return 0 ;
}
static int F_117 ( struct V_28 * V_28 , T_3 V_133 ,
struct V_144 * V_145 )
{
struct V_67 * V_68 = V_145 -> V_68 ;
char V_146 [ V_147 ] ;
F_118 ( V_146 , V_148 ,
true , V_133 , V_68 -> V_71 ) ;
F_119 ( V_146 , V_68 -> V_119 ) ;
return F_30 ( V_28 -> V_40 , F_31 ( V_149 ) , V_146 ) ;
}
static int
F_120 ( struct V_28 * V_28 ,
struct V_140 * V_141 )
{
T_3 V_133 = V_141 -> V_133 ;
struct V_144 * V_145 ;
int V_31 ;
int V_14 ;
for ( V_31 = 0 ; V_31 < V_141 -> V_150 ; V_31 ++ ) {
V_145 = & V_141 -> V_151 [ V_31 ] ;
if ( ! V_145 -> V_152 ) {
V_145 -> V_120 = 0 ;
continue;
}
if ( V_145 -> V_153 ) {
V_14 = F_117 ( V_28 ,
V_133 , V_145 ) ;
if ( V_14 )
return V_14 ;
V_145 -> V_153 = 0 ;
V_145 -> V_120 = 1 ;
}
V_133 ++ ;
}
return 0 ;
}
static int
F_121 ( struct V_28 * V_28 ,
struct V_140 * V_141 )
{
struct V_11 * V_12 ;
int V_14 ;
F_94 (fib_entry, &nh_grp->fib_list, nexthop_group_node) {
V_14 = F_122 ( V_28 , V_12 ) ;
if ( V_14 )
return V_14 ;
}
return 0 ;
}
static void
F_123 ( struct V_28 * V_28 ,
struct V_140 * V_141 )
{
struct V_144 * V_145 ;
bool V_154 = false ;
T_3 V_133 ;
T_4 V_134 = 0 ;
bool V_155 ;
T_3 V_142 ;
T_4 V_143 ;
int V_156 ;
int V_31 ;
int V_14 ;
for ( V_31 = 0 ; V_31 < V_141 -> V_150 ; V_31 ++ ) {
V_145 = & V_141 -> V_151 [ V_31 ] ;
if ( V_145 -> V_152 ^ V_145 -> V_120 ) {
V_154 = true ;
if ( V_145 -> V_152 )
V_145 -> V_153 = 1 ;
}
if ( V_145 -> V_152 )
V_134 ++ ;
}
if ( ! V_154 ) {
V_14 = F_120 ( V_28 , V_141 ) ;
if ( V_14 ) {
F_124 ( V_28 -> V_97 -> V_22 , L_8 ) ;
goto V_157;
}
return;
}
if ( ! V_134 )
goto V_157;
V_156 = F_125 ( V_28 , V_134 ) ;
if ( V_156 < 0 ) {
F_124 ( V_28 -> V_97 -> V_22 , L_9 ) ;
goto V_157;
}
V_133 = V_156 ;
V_155 = V_141 -> V_158 ;
V_142 = V_141 -> V_133 ;
V_143 = V_141 -> V_134 ;
V_141 -> V_158 = 1 ;
V_141 -> V_133 = V_133 ;
V_141 -> V_134 = V_134 ;
V_14 = F_120 ( V_28 , V_141 ) ;
if ( V_14 ) {
F_124 ( V_28 -> V_97 -> V_22 , L_8 ) ;
goto V_157;
}
if ( ! V_155 ) {
V_14 = F_121 ( V_28 , V_141 ) ;
if ( V_14 ) {
F_124 ( V_28 -> V_97 -> V_22 , L_10 ) ;
goto V_157;
}
return;
}
V_14 = F_116 ( V_28 , V_141 ,
V_142 , V_143 ) ;
F_126 ( V_28 , V_142 ) ;
if ( V_14 ) {
F_124 ( V_28 -> V_97 -> V_22 , L_11 ) ;
goto V_157;
}
return;
V_157:
V_155 = V_141 -> V_158 ;
V_141 -> V_158 = 0 ;
for ( V_31 = 0 ; V_31 < V_141 -> V_150 ; V_31 ++ ) {
V_145 = & V_141 -> V_151 [ V_31 ] ;
V_145 -> V_120 = 0 ;
}
V_14 = F_121 ( V_28 , V_141 ) ;
if ( V_14 )
F_124 ( V_28 -> V_97 -> V_22 , L_12 ) ;
if ( V_155 )
F_126 ( V_28 , V_141 -> V_133 ) ;
}
static void F_127 ( struct V_144 * V_145 ,
bool V_116 )
{
if ( ! V_116 && ! V_145 -> V_152 )
V_145 -> V_152 = 1 ;
else if ( V_116 && V_145 -> V_120 )
V_145 -> V_152 = 0 ;
V_145 -> V_153 = 1 ;
}
static void
F_106 ( struct V_28 * V_28 ,
struct V_67 * V_68 ,
bool V_116 )
{
struct V_144 * V_145 ;
F_88 () ;
F_94 (nh, &neigh_entry->nexthop_list,
neigh_list_node) {
F_127 ( V_145 , V_116 ) ;
F_123 ( V_28 , V_145 -> V_141 ) ;
}
F_92 () ;
}
static int F_128 ( struct V_28 * V_28 ,
struct V_140 * V_141 ,
struct V_144 * V_145 ,
struct V_159 * V_159 )
{
struct V_67 * V_68 ;
T_3 V_160 = F_65 ( V_159 -> V_161 ) ;
struct V_21 * V_22 = V_159 -> V_162 ;
struct V_72 * V_73 ;
T_2 V_109 ;
V_68 = F_62 ( V_28 , & V_160 ,
sizeof( V_160 ) , V_22 ) ;
if ( ! V_68 ) {
V_85 V_163 = F_75 ( V_160 ) ;
V_73 = F_129 ( & V_84 , & V_163 , V_22 ) ;
if ( F_39 ( V_73 ) )
return F_50 ( V_73 ) ;
F_79 ( V_73 , NULL ) ;
V_68 = F_62 ( V_28 , & V_160 ,
sizeof( V_160 ) , V_22 ) ;
if ( ! V_68 ) {
F_80 ( V_73 ) ;
return - V_87 ;
}
} else {
V_73 = V_68 -> V_73 ;
F_110 ( V_73 ) ;
}
if ( F_95 ( & V_68 -> V_77 ) )
F_130 ( & V_68 -> V_164 ,
& V_28 -> V_33 . V_165 ) ;
V_145 -> V_141 = V_141 ;
V_145 -> V_68 = V_68 ;
F_130 ( & V_145 -> V_166 , & V_68 -> V_77 ) ;
F_103 ( & V_73 -> V_118 ) ;
V_109 = V_73 -> V_109 ;
F_104 ( & V_73 -> V_118 ) ;
F_127 ( V_145 , ! ( V_109 & V_110 ) ) ;
return 0 ;
}
static void F_131 ( struct V_28 * V_28 ,
struct V_144 * V_145 )
{
struct V_67 * V_68 = V_145 -> V_68 ;
F_132 ( & V_145 -> V_166 ) ;
if ( F_95 ( & V_145 -> V_68 -> V_77 ) )
F_132 ( & V_145 -> V_68 -> V_164 ) ;
F_80 ( V_68 -> V_73 ) ;
}
static struct V_140 *
F_133 ( struct V_28 * V_28 , struct V_167 * V_168 )
{
struct V_140 * V_141 ;
struct V_144 * V_145 ;
struct V_159 * V_159 ;
T_1 V_169 ;
int V_31 ;
int V_14 ;
V_169 = sizeof( * V_141 ) +
V_168 -> V_170 * sizeof( struct V_144 ) ;
V_141 = F_17 ( V_169 , V_23 ) ;
if ( ! V_141 )
return F_23 ( - V_25 ) ;
F_60 ( & V_141 -> V_171 ) ;
V_141 -> V_150 = V_168 -> V_170 ;
for ( V_31 = 0 ; V_31 < V_141 -> V_150 ; V_31 ++ ) {
V_145 = & V_141 -> V_151 [ V_31 ] ;
V_159 = & V_168 -> V_159 [ V_31 ] ;
V_14 = F_128 ( V_28 , V_141 , V_145 , V_159 ) ;
if ( V_14 )
goto V_172;
}
F_130 ( & V_141 -> V_173 , & V_28 -> V_33 . V_174 ) ;
F_123 ( V_28 , V_141 ) ;
return V_141 ;
V_172:
for ( V_31 -- ; V_31 >= 0 ; V_31 -- )
F_131 ( V_28 , V_145 ) ;
F_19 ( V_141 ) ;
return F_23 ( V_14 ) ;
}
static void
F_134 ( struct V_28 * V_28 ,
struct V_140 * V_141 )
{
struct V_144 * V_145 ;
int V_31 ;
F_132 ( & V_141 -> V_173 ) ;
for ( V_31 = 0 ; V_31 < V_141 -> V_150 ; V_31 ++ ) {
V_145 = & V_141 -> V_151 [ V_31 ] ;
F_131 ( V_28 , V_145 ) ;
}
F_19 ( V_141 ) ;
}
static bool F_135 ( struct V_144 * V_145 ,
struct V_167 * V_168 )
{
int V_31 ;
for ( V_31 = 0 ; V_31 < V_168 -> V_170 ; V_31 ++ ) {
struct V_159 * V_159 = & V_168 -> V_159 [ V_31 ] ;
T_3 V_160 = F_65 ( V_159 -> V_161 ) ;
if ( memcmp ( V_145 -> V_68 -> V_13 . V_19 ,
& V_160 , sizeof( T_3 ) ) == 0 &&
V_145 -> V_68 -> V_13 . V_22 == V_159 -> V_162 )
return true ;
}
return false ;
}
static bool F_136 ( struct V_140 * V_141 ,
struct V_167 * V_168 )
{
int V_31 ;
if ( V_141 -> V_150 != V_168 -> V_170 )
return false ;
for ( V_31 = 0 ; V_31 < V_141 -> V_150 ; V_31 ++ ) {
struct V_144 * V_145 = & V_141 -> V_151 [ V_31 ] ;
if ( ! F_135 ( V_145 , V_168 ) )
return false ;
}
return true ;
}
static struct V_140 *
F_137 ( struct V_28 * V_28 , struct V_167 * V_168 )
{
struct V_140 * V_141 ;
F_94 (nh_grp, &mlxsw_sp->router.nexthop_group_list,
list) {
if ( F_136 ( V_141 , V_168 ) )
return V_141 ;
}
return NULL ;
}
static int F_138 ( struct V_28 * V_28 ,
struct V_11 * V_12 ,
struct V_167 * V_168 )
{
struct V_140 * V_141 ;
V_141 = F_137 ( V_28 , V_168 ) ;
if ( ! V_141 ) {
V_141 = F_133 ( V_28 , V_168 ) ;
if ( F_39 ( V_141 ) )
return F_50 ( V_141 ) ;
}
F_130 ( & V_12 -> V_175 , & V_141 -> V_171 ) ;
V_12 -> V_176 = V_141 ;
return 0 ;
}
static void F_139 ( struct V_28 * V_28 ,
struct V_11 * V_12 )
{
struct V_140 * V_141 = V_12 -> V_176 ;
F_132 ( & V_12 -> V_175 ) ;
if ( ! F_95 ( & V_141 -> V_171 ) )
return;
F_134 ( V_28 , V_141 ) ;
}
static int F_140 ( struct V_28 * V_28 )
{
char V_177 [ V_178 ] ;
F_141 ( V_177 , true ) ;
F_142 ( V_177 , V_179 ) ;
return F_30 ( V_28 -> V_40 , F_31 ( V_180 ) , V_177 ) ;
}
static void F_143 ( struct V_28 * V_28 )
{
char V_177 [ V_178 ] ;
F_141 ( V_177 , false ) ;
F_30 ( V_28 -> V_40 , F_31 ( V_180 ) , V_177 ) ;
}
int F_144 ( struct V_28 * V_28 )
{
int V_14 ;
F_60 ( & V_28 -> V_33 . V_165 ) ;
F_60 ( & V_28 -> V_33 . V_174 ) ;
V_14 = F_140 ( V_28 ) ;
if ( V_14 )
return V_14 ;
F_41 ( V_28 ) ;
F_55 ( V_28 ) ;
V_14 = F_111 ( V_28 ) ;
if ( V_14 )
goto V_181;
return 0 ;
V_181:
F_143 ( V_28 ) ;
return V_14 ;
}
void F_145 ( struct V_28 * V_28 )
{
F_112 ( V_28 ) ;
F_143 ( V_28 ) ;
}
static int F_146 ( struct V_28 * V_28 ,
struct V_11 * V_12 ,
enum V_182 V_183 )
{
char V_184 [ V_185 ] ;
T_3 * V_186 = ( T_3 * ) V_12 -> V_13 . V_19 ;
struct V_53 * V_54 = V_12 -> V_54 ;
enum V_187 V_188 ;
T_4 V_189 = 0 ;
T_3 V_190 = 0 ;
T_4 V_134 = 0 ;
if ( V_12 -> V_176 -> V_158 ) {
V_188 = V_191 ;
V_190 = V_12 -> V_176 -> V_133 ;
V_134 = V_12 -> V_176 -> V_134 ;
} else {
V_188 = V_192 ;
V_189 = V_193 ;
}
F_147 ( V_184 , V_54 -> V_38 , V_183 , V_54 -> V_39 ,
V_12 -> V_13 . V_8 , * V_186 ) ;
F_148 ( V_184 , V_188 , V_189 ,
V_190 , V_134 ) ;
return F_30 ( V_28 -> V_40 , F_31 ( V_194 ) , V_184 ) ;
}
static int F_149 ( struct V_28 * V_28 ,
struct V_11 * V_12 ,
enum V_182 V_183 )
{
char V_184 [ V_185 ] ;
T_3 * V_186 = ( T_3 * ) V_12 -> V_13 . V_19 ;
struct V_53 * V_54 = V_12 -> V_54 ;
F_147 ( V_184 , V_54 -> V_38 , V_183 , V_54 -> V_39 ,
V_12 -> V_13 . V_8 , * V_186 ) ;
F_150 ( V_184 ,
V_191 , 0 ,
V_12 -> V_71 ) ;
return F_30 ( V_28 -> V_40 , F_31 ( V_194 ) , V_184 ) ;
}
static int F_151 ( struct V_28 * V_28 ,
struct V_11 * V_12 ,
enum V_182 V_183 )
{
char V_184 [ V_185 ] ;
T_3 * V_186 = ( T_3 * ) V_12 -> V_13 . V_19 ;
struct V_53 * V_54 = V_12 -> V_54 ;
F_147 ( V_184 , V_54 -> V_38 , V_183 , V_54 -> V_39 ,
V_12 -> V_13 . V_8 , * V_186 ) ;
F_152 ( V_184 ) ;
return F_30 ( V_28 -> V_40 , F_31 ( V_194 ) , V_184 ) ;
}
static int F_153 ( struct V_28 * V_28 ,
struct V_11 * V_12 ,
enum V_182 V_183 )
{
switch ( V_12 -> type ) {
case V_195 :
return F_146 ( V_28 , V_12 , V_183 ) ;
case V_196 :
return F_149 ( V_28 , V_12 , V_183 ) ;
case V_197 :
return F_151 ( V_28 , V_12 , V_183 ) ;
}
return - V_87 ;
}
static int F_154 ( struct V_28 * V_28 ,
struct V_11 * V_12 ,
enum V_182 V_183 )
{
switch ( V_12 -> V_54 -> V_38 ) {
case V_198 :
return F_153 ( V_28 , V_12 , V_183 ) ;
case V_199 :
return - V_87 ;
}
return - V_87 ;
}
static int F_122 ( struct V_28 * V_28 ,
struct V_11 * V_12 )
{
return F_154 ( V_28 , V_12 ,
V_200 ) ;
}
static int F_155 ( struct V_28 * V_28 ,
struct V_11 * V_12 )
{
return F_154 ( V_28 , V_12 ,
V_201 ) ;
}
static void F_156 ( void const * V_202 )
{
const struct V_203 * V_204 = V_202 ;
struct V_11 * V_12 = V_204 -> V_12 ;
struct V_28 * V_28 = V_204 -> V_28 ;
struct V_53 * V_54 = V_12 -> V_54 ;
F_18 ( V_12 ) ;
F_54 ( V_28 , V_54 ) ;
F_19 ( V_204 ) ;
}
static int
F_157 ( struct V_28 * V_28 ,
const struct V_205 * V_206 ,
struct V_11 * V_12 )
{
struct V_167 * V_168 = V_206 -> V_168 ;
if ( V_206 -> type == V_207 || V_206 -> type == V_208 ) {
V_12 -> type = V_197 ;
return 0 ;
}
if ( V_206 -> type != V_209 )
return - V_87 ;
if ( V_168 -> V_210 != V_211 ) {
struct V_80 * V_81 ;
V_12 -> type = V_196 ;
V_81 = F_67 ( V_28 , V_168 -> V_212 ) ;
if ( ! V_81 )
return - V_87 ;
V_12 -> V_71 = V_81 -> V_71 ;
return 0 ;
}
V_12 -> type = V_195 ;
return F_138 ( V_28 , V_12 , V_168 ) ;
}
static void
F_158 ( struct V_28 * V_28 ,
struct V_11 * V_12 )
{
if ( V_12 -> type != V_195 )
return;
F_139 ( V_28 , V_12 ) ;
}
static struct V_11 *
F_159 ( struct V_28 * V_28 ,
const struct V_205 * V_206 )
{
struct V_11 * V_12 ;
struct V_167 * V_168 = V_206 -> V_168 ;
struct V_53 * V_54 ;
int V_14 ;
V_54 = F_53 ( V_28 , V_206 -> V_213 , V_206 -> V_61 ,
V_198 ) ;
if ( F_39 ( V_54 ) )
return F_49 ( V_54 ) ;
V_12 = F_20 ( V_54 -> V_10 , & V_206 -> V_214 ,
sizeof( V_206 -> V_214 ) ,
V_206 -> V_213 , V_168 -> V_212 ) ;
if ( V_12 ) {
V_12 -> V_35 ++ ;
return V_12 ;
}
V_12 = F_16 ( V_54 -> V_10 , & V_206 -> V_214 ,
sizeof( V_206 -> V_214 ) ,
V_206 -> V_213 , V_168 -> V_212 ) ;
if ( ! V_12 ) {
V_14 = - V_25 ;
goto V_215;
}
V_12 -> V_54 = V_54 ;
V_12 -> V_35 = 1 ;
V_14 = F_157 ( V_28 , V_206 , V_12 ) ;
if ( V_14 )
goto V_216;
return V_12 ;
V_216:
F_18 ( V_12 ) ;
V_215:
F_54 ( V_28 , V_54 ) ;
return F_23 ( V_14 ) ;
}
static struct V_11 *
F_160 ( struct V_28 * V_28 ,
const struct V_205 * V_206 )
{
struct V_53 * V_54 ;
V_54 = F_47 ( V_28 , V_206 -> V_61 , V_198 ) ;
if ( ! V_54 )
return NULL ;
return F_20 ( V_54 -> V_10 , & V_206 -> V_214 ,
sizeof( V_206 -> V_214 ) , V_206 -> V_213 ,
V_206 -> V_168 -> V_212 ) ;
}
void F_161 ( struct V_28 * V_28 ,
struct V_11 * V_12 )
{
struct V_53 * V_54 = V_12 -> V_54 ;
if ( -- V_12 -> V_35 == 0 ) {
F_158 ( V_28 , V_12 ) ;
F_18 ( V_12 ) ;
}
F_54 ( V_28 , V_54 ) ;
}
static int
F_162 ( struct V_79 * V_79 ,
const struct V_205 * V_206 ,
struct V_217 * V_218 )
{
struct V_28 * V_28 = V_79 -> V_28 ;
struct V_203 * V_204 ;
struct V_11 * V_12 ;
int V_14 ;
V_12 = F_159 ( V_28 , V_206 ) ;
if ( F_39 ( V_12 ) )
return F_50 ( V_12 ) ;
V_204 = F_87 ( sizeof( * V_204 ) , V_23 ) ;
if ( ! V_204 ) {
V_14 = - V_25 ;
goto V_219;
}
V_204 -> V_28 = V_28 ;
V_204 -> V_12 = V_12 ;
F_163 ( V_218 , V_204 ,
F_156 ,
& V_204 -> V_220 ) ;
return 0 ;
V_219:
F_161 ( V_28 , V_12 ) ;
return V_14 ;
}
static int
F_164 ( struct V_79 * V_79 ,
const struct V_205 * V_206 ,
struct V_217 * V_218 )
{
struct V_28 * V_28 = V_79 -> V_28 ;
struct V_203 * V_204 ;
struct V_11 * V_12 ;
struct V_53 * V_54 ;
int V_14 ;
V_204 = F_165 ( V_218 ) ;
V_12 = V_204 -> V_12 ;
F_19 ( V_204 ) ;
if ( V_12 -> V_35 != 1 )
return 0 ;
V_54 = V_12 -> V_54 ;
V_14 = F_12 ( V_54 -> V_10 , V_12 ) ;
if ( V_14 )
goto V_221;
V_14 = F_122 ( V_79 -> V_28 , V_12 ) ;
if ( V_14 )
goto V_222;
return 0 ;
V_222:
F_14 ( V_54 -> V_10 , V_12 ) ;
V_221:
F_161 ( V_28 , V_12 ) ;
return V_14 ;
}
int F_166 ( struct V_79 * V_79 ,
const struct V_205 * V_206 ,
struct V_217 * V_218 )
{
if ( F_167 ( V_218 ) )
return F_162 ( V_79 ,
V_206 , V_218 ) ;
return F_164 ( V_79 ,
V_206 , V_218 ) ;
}
int F_168 ( struct V_79 * V_79 ,
const struct V_205 * V_206 )
{
struct V_28 * V_28 = V_79 -> V_28 ;
struct V_11 * V_12 ;
V_12 = F_160 ( V_28 , V_206 ) ;
if ( ! V_12 ) {
F_124 ( V_28 -> V_97 -> V_22 , L_13 ) ;
return - V_223 ;
}
if ( V_12 -> V_35 == 1 ) {
F_155 ( V_28 , V_12 ) ;
F_14 ( V_12 -> V_54 -> V_10 , V_12 ) ;
}
F_161 ( V_28 , V_12 ) ;
return 0 ;
}
