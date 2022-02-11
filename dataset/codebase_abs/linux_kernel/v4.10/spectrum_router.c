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
F_14 ( & V_12 -> V_18 , & V_10 -> V_19 ) ;
if ( V_10 -> V_20 [ V_8 ] ++ == 0 )
F_8 ( & V_10 -> V_6 , V_8 ) ;
return 0 ;
}
static void F_15 ( struct V_9 * V_10 ,
struct V_11 * V_12 )
{
unsigned char V_8 = V_12 -> V_13 . V_8 ;
if ( -- V_10 -> V_20 [ V_8 ] == 0 )
F_10 ( & V_10 -> V_6 , V_8 ) ;
F_16 ( & V_12 -> V_18 ) ;
F_17 ( & V_10 -> V_15 , & V_12 -> V_16 ,
V_17 ) ;
}
static struct V_11 *
F_18 ( struct V_9 * V_10 , const void * V_21 ,
T_1 V_22 , unsigned char V_8 ,
struct V_23 * V_24 )
{
struct V_11 * V_12 ;
V_12 = F_19 ( sizeof( * V_12 ) , V_25 ) ;
if ( ! V_12 )
return NULL ;
V_12 -> V_13 . V_24 = V_24 ;
memcpy ( V_12 -> V_13 . V_21 , V_21 , V_22 ) ;
V_12 -> V_13 . V_8 = V_8 ;
return V_12 ;
}
static void F_20 ( struct V_11 * V_12 )
{
F_21 ( V_12 ) ;
}
static struct V_11 *
F_22 ( struct V_9 * V_10 , const void * V_21 ,
T_1 V_22 , unsigned char V_8 ,
struct V_23 * V_24 )
{
struct V_26 V_13 ;
memset ( & V_13 , 0 , sizeof( V_13 ) ) ;
V_13 . V_24 = V_24 ;
memcpy ( V_13 . V_21 , V_21 , V_22 ) ;
V_13 . V_8 = V_8 ;
return F_23 ( & V_10 -> V_15 , & V_13 , V_17 ) ;
}
static struct V_9 * F_24 ( void )
{
struct V_9 * V_10 ;
int V_14 ;
V_10 = F_19 ( sizeof( * V_10 ) , V_25 ) ;
if ( ! V_10 )
return F_25 ( - V_27 ) ;
V_14 = F_26 ( & V_10 -> V_15 , & V_17 ) ;
if ( V_14 )
goto V_28;
F_27 ( & V_10 -> V_19 ) ;
return V_10 ;
V_28:
F_21 ( V_10 ) ;
return F_25 ( V_14 ) ;
}
static void F_28 ( struct V_9 * V_10 )
{
F_29 ( & V_10 -> V_15 ) ;
F_21 ( V_10 ) ;
}
static struct V_29 *
F_30 ( struct V_30 * V_30 , bool V_31 )
{
static struct V_29 * V_32 ;
int V_33 ;
for ( V_33 = 0 ; V_33 < V_34 ; V_33 ++ ) {
V_32 = & V_30 -> V_35 . V_36 [ V_33 ] ;
if ( V_32 -> V_37 == 0 ) {
if ( V_31 )
V_31 = false ;
else
return V_32 ;
}
}
return NULL ;
}
static int F_31 ( struct V_30 * V_30 ,
struct V_29 * V_32 )
{
char V_38 [ V_39 ] ;
F_32 ( V_38 , true ,
(enum V_40 ) V_32 -> V_41 ,
V_32 -> V_42 ) ;
return F_33 ( V_30 -> V_43 , F_34 ( V_44 ) , V_38 ) ;
}
static int F_35 ( struct V_30 * V_30 ,
struct V_29 * V_32 )
{
char V_38 [ V_39 ] ;
F_32 ( V_38 , false ,
(enum V_40 ) V_32 -> V_41 ,
V_32 -> V_42 ) ;
return F_33 ( V_30 -> V_43 , F_34 ( V_44 ) , V_38 ) ;
}
static int
F_36 ( struct V_30 * V_30 ,
struct V_1 * V_6 ,
struct V_29 * V_32 )
{
char V_45 [ V_46 ] ;
T_2 V_47 = 0 ;
T_2 V_4 ;
T_2 V_48 = V_49 ;
F_2 (prefix, prefix_usage)
V_47 = V_4 ;
F_37 ( V_45 , V_47 , V_32 -> V_42 ) ;
F_2 (prefix, prefix_usage) {
if ( V_4 == 0 )
continue;
F_38 ( V_45 , V_4 , V_48 ,
V_49 ) ;
V_48 = V_4 ;
}
return F_33 ( V_30 -> V_43 , F_34 ( V_50 ) , V_45 ) ;
}
static struct V_29 *
F_39 ( struct V_30 * V_30 ,
struct V_1 * V_6 ,
enum V_51 V_41 , bool V_31 )
{
struct V_29 * V_32 ;
int V_14 ;
V_32 = F_30 ( V_30 , V_31 ) ;
if ( ! V_32 )
return F_25 ( - V_52 ) ;
V_32 -> V_41 = V_41 ;
V_14 = F_31 ( V_30 , V_32 ) ;
if ( V_14 )
return F_25 ( V_14 ) ;
V_14 = F_36 ( V_30 , V_6 ,
V_32 ) ;
if ( V_14 )
goto V_53;
memcpy ( & V_32 -> V_6 , V_6 ,
sizeof( V_32 -> V_6 ) ) ;
return V_32 ;
V_53:
F_35 ( V_30 , V_32 ) ;
return F_25 ( V_14 ) ;
}
static int F_40 ( struct V_30 * V_30 ,
struct V_29 * V_32 )
{
return F_35 ( V_30 , V_32 ) ;
}
static struct V_29 *
F_41 ( struct V_30 * V_30 ,
struct V_1 * V_6 ,
enum V_51 V_41 , bool V_31 )
{
struct V_29 * V_32 ;
int V_33 ;
for ( V_33 = 0 ; V_33 < V_34 ; V_33 ++ ) {
V_32 = & V_30 -> V_35 . V_36 [ V_33 ] ;
if ( V_32 -> V_37 != 0 &&
V_32 -> V_41 == V_41 &&
F_4 ( & V_32 -> V_6 ,
V_6 ) )
goto V_54;
}
V_32 = F_39 ( V_30 , V_6 ,
V_41 , V_31 ) ;
if ( F_42 ( V_32 ) )
return V_32 ;
V_54:
V_32 -> V_37 ++ ;
return V_32 ;
}
static int F_43 ( struct V_30 * V_30 ,
struct V_29 * V_32 )
{
if ( -- V_32 -> V_37 == 0 )
return F_40 ( V_30 , V_32 ) ;
return 0 ;
}
static void F_44 ( struct V_30 * V_30 )
{
struct V_29 * V_32 ;
int V_33 ;
for ( V_33 = 0 ; V_33 < V_34 ; V_33 ++ ) {
V_32 = & V_30 -> V_35 . V_36 [ V_33 ] ;
V_32 -> V_42 = V_33 + V_55 ;
}
}
static struct V_56 * F_45 ( struct V_30 * V_30 )
{
struct V_56 * V_57 ;
int V_33 ;
for ( V_33 = 0 ; V_33 < F_46 ( V_30 -> V_43 , V_58 ) ; V_33 ++ ) {
V_57 = & V_30 -> V_35 . V_59 [ V_33 ] ;
if ( ! V_57 -> V_60 )
return V_57 ;
}
return NULL ;
}
static int F_47 ( struct V_30 * V_30 ,
struct V_56 * V_57 )
{
char V_61 [ V_62 ] ;
F_48 ( V_61 , V_57 -> V_42 ,
(enum V_40 ) V_57 -> V_41 ,
V_57 -> V_32 -> V_42 ) ;
return F_33 ( V_30 -> V_43 , F_34 ( V_63 ) , V_61 ) ;
}
static int F_49 ( struct V_30 * V_30 ,
struct V_56 * V_57 )
{
char V_61 [ V_62 ] ;
F_48 ( V_61 , V_57 -> V_42 ,
(enum V_40 ) V_57 -> V_41 , 0 ) ;
return F_33 ( V_30 -> V_43 , F_34 ( V_63 ) , V_61 ) ;
}
static T_3 F_50 ( T_3 V_64 )
{
if ( V_64 == V_65 )
V_64 = V_66 ;
return V_64 ;
}
static struct V_56 * F_51 ( struct V_30 * V_30 ,
T_3 V_64 ,
enum V_51 V_41 )
{
struct V_56 * V_57 ;
int V_33 ;
V_64 = F_50 ( V_64 ) ;
for ( V_33 = 0 ; V_33 < F_46 ( V_30 -> V_43 , V_58 ) ; V_33 ++ ) {
V_57 = & V_30 -> V_35 . V_59 [ V_33 ] ;
if ( V_57 -> V_60 && V_57 -> V_41 == V_41 && V_57 -> V_64 == V_64 )
return V_57 ;
}
return NULL ;
}
static struct V_56 * F_52 ( struct V_30 * V_30 ,
unsigned char V_8 ,
T_3 V_64 ,
enum V_51 V_41 )
{
struct V_1 V_67 ;
struct V_29 * V_32 ;
struct V_56 * V_57 ;
int V_14 ;
V_57 = F_45 ( V_30 ) ;
if ( ! V_57 )
return F_25 ( - V_52 ) ;
V_57 -> V_10 = F_24 () ;
if ( F_42 ( V_57 -> V_10 ) )
return F_53 ( V_57 -> V_10 ) ;
V_57 -> V_41 = V_41 ;
V_57 -> V_64 = V_64 ;
F_7 ( & V_67 ) ;
F_8 ( & V_67 , V_8 ) ;
V_32 = F_41 ( V_30 , & V_67 ,
V_41 , true ) ;
if ( F_42 ( V_32 ) ) {
V_14 = F_54 ( V_32 ) ;
goto V_68;
}
V_57 -> V_32 = V_32 ;
V_14 = F_47 ( V_30 , V_57 ) ;
if ( V_14 )
goto V_69;
V_57 -> V_60 = true ;
return V_57 ;
V_69:
F_43 ( V_30 , V_57 -> V_32 ) ;
V_68:
F_28 ( V_57 -> V_10 ) ;
return F_25 ( V_14 ) ;
}
static void F_55 ( struct V_30 * V_30 ,
struct V_56 * V_57 )
{
F_49 ( V_30 , V_57 ) ;
F_43 ( V_30 , V_57 -> V_32 ) ;
F_28 ( V_57 -> V_10 ) ;
V_57 -> V_60 = false ;
}
static int
F_56 ( struct V_30 * V_30 , struct V_56 * V_57 ,
struct V_1 * V_67 )
{
struct V_29 * V_32 ;
if ( F_4 ( V_67 ,
& V_57 -> V_32 -> V_6 ) )
return 0 ;
V_32 = F_41 ( V_30 , V_67 ,
V_57 -> V_41 , false ) ;
if ( F_42 ( V_32 ) ) {
if ( F_1 ( V_67 ,
& V_57 -> V_32 -> V_6 ) )
return 0 ;
return F_54 ( V_32 ) ;
}
F_49 ( V_30 , V_57 ) ;
F_43 ( V_30 , V_57 -> V_32 ) ;
V_57 -> V_32 = V_32 ;
return F_47 ( V_30 , V_57 ) ;
}
static struct V_56 * F_57 ( struct V_30 * V_30 ,
unsigned char V_8 ,
T_3 V_64 ,
enum V_51 V_41 )
{
struct V_56 * V_57 ;
int V_14 ;
V_64 = F_50 ( V_64 ) ;
V_57 = F_51 ( V_30 , V_64 , V_41 ) ;
if ( ! V_57 ) {
V_57 = F_52 ( V_30 , V_8 , V_64 , V_41 ) ;
if ( F_42 ( V_57 ) )
return V_57 ;
} else {
struct V_1 V_67 ;
F_6 ( & V_67 ,
& V_57 -> V_10 -> V_6 ) ;
F_8 ( & V_67 , V_8 ) ;
V_14 = F_56 ( V_30 , V_57 ,
& V_67 ) ;
if ( V_14 )
return F_25 ( V_14 ) ;
}
return V_57 ;
}
static void F_58 ( struct V_30 * V_30 , struct V_56 * V_57 )
{
if ( F_5 ( & V_57 -> V_10 -> V_6 ) )
F_55 ( V_30 , V_57 ) ;
else
F_56 ( V_30 , V_57 ,
& V_57 -> V_10 -> V_6 ) ;
}
static int F_59 ( struct V_30 * V_30 )
{
struct V_56 * V_57 ;
T_4 V_70 ;
int V_33 ;
if ( ! F_60 ( V_30 -> V_43 , V_58 ) )
return - V_71 ;
V_70 = F_46 ( V_30 -> V_43 , V_58 ) ;
V_30 -> V_35 . V_59 = F_61 ( V_70 , sizeof( struct V_56 ) ,
V_25 ) ;
if ( ! V_30 -> V_35 . V_59 )
return - V_27 ;
for ( V_33 = 0 ; V_33 < V_70 ; V_33 ++ ) {
V_57 = & V_30 -> V_35 . V_59 [ V_33 ] ;
V_57 -> V_42 = V_33 ;
}
return 0 ;
}
static void F_62 ( struct V_30 * V_30 )
{
F_63 () ;
F_64 ( V_30 ) ;
F_21 ( V_30 -> V_35 . V_59 ) ;
}
static int
F_65 ( struct V_30 * V_30 ,
struct V_72 * V_73 )
{
return F_13 ( & V_30 -> V_35 . V_74 ,
& V_73 -> V_16 ,
V_75 ) ;
}
static void
F_66 ( struct V_30 * V_30 ,
struct V_72 * V_73 )
{
F_17 ( & V_30 -> V_35 . V_74 ,
& V_73 -> V_16 ,
V_75 ) ;
}
static struct V_72 *
F_67 ( struct V_76 * V_77 , T_5 V_78 )
{
struct V_72 * V_73 ;
V_73 = F_19 ( sizeof( * V_73 ) , V_79 ) ;
if ( ! V_73 )
return NULL ;
V_73 -> V_13 . V_77 = V_77 ;
V_73 -> V_78 = V_78 ;
F_68 ( & V_73 -> V_80 , V_81 ) ;
F_27 ( & V_73 -> V_82 ) ;
return V_73 ;
}
static void
F_69 ( struct V_72 * V_73 )
{
F_21 ( V_73 ) ;
}
static struct V_72 *
F_70 ( struct V_30 * V_30 , struct V_76 * V_77 )
{
struct V_83 V_13 ;
V_13 . V_77 = V_77 ;
return F_23 ( & V_30 -> V_35 . V_74 ,
& V_13 , V_75 ) ;
}
int F_71 ( struct V_23 * V_24 ,
struct V_76 * V_77 )
{
struct V_84 * V_84 = F_72 ( V_24 ) ;
struct V_30 * V_30 = V_84 -> V_30 ;
struct V_72 * V_73 ;
struct V_85 * V_86 ;
int V_14 ;
if ( V_77 -> V_87 != & V_88 )
return 0 ;
V_73 = F_70 ( V_30 , V_77 ) ;
if ( V_73 )
return 0 ;
V_86 = F_73 ( V_30 , V_77 -> V_24 ) ;
if ( F_74 ( ! V_86 ) )
return - V_89 ;
V_73 = F_67 ( V_77 , V_86 -> V_78 ) ;
if ( ! V_73 )
return - V_27 ;
V_14 = F_65 ( V_30 , V_73 ) ;
if ( V_14 )
goto V_90;
return 0 ;
V_90:
F_69 ( V_73 ) ;
return V_14 ;
}
void F_75 ( struct V_23 * V_24 ,
struct V_76 * V_77 )
{
struct V_84 * V_84 = F_72 ( V_24 ) ;
struct V_30 * V_30 = V_84 -> V_30 ;
struct V_72 * V_73 ;
if ( V_77 -> V_87 != & V_88 )
return;
V_73 = F_70 ( V_30 , V_77 ) ;
if ( ! V_73 )
return;
F_66 ( V_30 , V_73 ) ;
F_69 ( V_73 ) ;
}
static void
F_76 ( struct V_30 * V_30 )
{
unsigned long V_91 = F_77 ( & V_88 . V_92 , V_93 ) ;
V_30 -> V_35 . V_94 . V_91 = F_78 ( V_91 ) ;
}
static void F_79 ( struct V_30 * V_30 ,
char * V_95 ,
int V_96 )
{
struct V_23 * V_24 ;
struct V_76 * V_77 ;
T_6 V_97 ;
T_3 V_98 ;
T_5 V_78 ;
F_80 ( V_95 , V_96 , & V_78 , & V_98 ) ;
if ( ! V_30 -> V_99 [ V_78 ] ) {
F_81 ( V_30 -> V_100 -> V_24 , L_1 ) ;
return;
}
V_97 = F_82 ( V_98 ) ;
V_24 = V_30 -> V_99 [ V_78 ] -> V_24 ;
V_77 = F_83 ( & V_88 , & V_97 , V_24 ) ;
if ( ! V_77 ) {
F_84 ( V_24 , L_2 ,
& V_98 ) ;
return;
}
F_85 ( V_24 , L_3 , & V_98 ) ;
F_86 ( V_77 , NULL ) ;
F_87 ( V_77 ) ;
}
static void F_88 ( struct V_30 * V_30 ,
char * V_95 ,
int V_101 )
{
T_2 V_102 ;
int V_33 ;
V_102 = F_89 ( V_95 ,
V_101 ) ;
V_102 ++ ;
for ( V_33 = 0 ; V_33 < V_102 ; V_33 ++ ) {
int V_96 ;
V_96 = V_101 * V_103 + V_33 ;
F_79 ( V_30 , V_95 ,
V_96 ) ;
}
}
static void F_90 ( struct V_30 * V_30 ,
char * V_95 , int V_101 )
{
switch ( F_91 ( V_95 , V_101 ) ) {
case V_104 :
F_88 ( V_30 , V_95 ,
V_101 ) ;
break;
case V_105 :
F_92 ( 1 ) ;
break;
}
}
static bool F_93 ( char * V_95 )
{
T_2 V_106 , V_107 , V_102 ;
V_106 = F_94 ( V_95 ) ;
V_107 = V_106 - 1 ;
if ( V_106 < V_108 )
return false ;
if ( F_91 ( V_95 , V_107 ) ==
V_105 )
return true ;
V_102 = F_89 ( V_95 ,
V_107 ) ;
if ( ++ V_102 == V_103 )
return true ;
return false ;
}
static int F_95 ( struct V_30 * V_30 )
{
char * V_95 ;
T_2 V_106 ;
int V_33 , V_14 ;
V_95 = F_96 ( V_109 , V_25 ) ;
if ( ! V_95 )
return - V_27 ;
F_97 () ;
do {
F_98 ( V_95 , V_104 ) ;
V_14 = F_99 ( V_30 -> V_43 , F_34 ( V_110 ) ,
V_95 ) ;
if ( V_14 ) {
F_81 ( V_30 -> V_100 -> V_24 , L_4 ) ;
break;
}
V_106 = F_94 ( V_95 ) ;
for ( V_33 = 0 ; V_33 < V_106 ; V_33 ++ )
F_90 ( V_30 , V_95 ,
V_33 ) ;
} while ( F_93 ( V_95 ) );
F_100 () ;
F_21 ( V_95 ) ;
return V_14 ;
}
static void F_101 ( struct V_30 * V_30 )
{
struct V_72 * V_73 ;
F_97 () ;
F_102 (neigh_entry, &mlxsw_sp->router.nexthop_neighs_list,
nexthop_neighs_list_node) {
if ( ! F_103 ( & V_73 -> V_82 ) )
F_86 ( V_73 -> V_13 . V_77 , NULL ) ;
}
F_100 () ;
}
static void
F_104 ( struct V_30 * V_30 )
{
unsigned long V_91 = V_30 -> V_35 . V_94 . V_91 ;
F_105 ( & V_30 -> V_35 . V_94 . V_80 ,
F_106 ( V_91 ) ) ;
}
static void F_107 ( struct V_111 * V_112 )
{
struct V_30 * V_30 = F_108 ( V_112 , struct V_30 ,
V_35 . V_94 . V_80 . V_112 ) ;
int V_14 ;
V_14 = F_95 ( V_30 ) ;
if ( V_14 )
F_109 ( V_30 -> V_100 -> V_24 , L_5 ) ;
F_101 ( V_30 ) ;
F_104 ( V_30 ) ;
}
static void F_110 ( struct V_111 * V_112 )
{
struct V_72 * V_73 ;
struct V_30 * V_30 = F_108 ( V_112 , struct V_30 ,
V_35 . V_113 . V_112 ) ;
F_97 () ;
F_102 (neigh_entry, &mlxsw_sp->router.nexthop_neighs_list,
nexthop_neighs_list_node) {
if ( ! ( V_73 -> V_13 . V_77 -> V_114 & V_115 ) &&
! F_103 ( & V_73 -> V_82 ) )
F_86 ( V_73 -> V_13 . V_77 , NULL ) ;
}
F_100 () ;
F_105 ( & V_30 -> V_35 . V_113 ,
V_116 ) ;
}
static void V_81 ( struct V_111 * V_112 )
{
struct V_72 * V_73 =
F_108 ( V_112 , struct V_72 , V_80 . V_112 ) ;
struct V_76 * V_77 = V_73 -> V_13 . V_77 ;
struct V_84 * V_84 = V_73 -> V_84 ;
struct V_30 * V_30 = V_84 -> V_30 ;
char V_117 [ V_118 ] ;
struct V_23 * V_24 ;
bool V_119 ;
T_2 V_114 , V_120 ;
bool V_121 ;
bool V_122 ;
bool V_123 ;
T_3 V_98 ;
int V_14 ;
F_111 ( & V_77 -> V_124 ) ;
V_98 = F_112 ( * ( ( T_6 * ) V_77 -> V_125 ) ) ;
memcpy ( V_73 -> V_126 , V_77 -> V_126 , sizeof( V_73 -> V_126 ) ) ;
V_114 = V_77 -> V_114 ;
V_120 = V_77 -> V_120 ;
V_24 = V_77 -> V_24 ;
F_113 ( & V_77 -> V_124 ) ;
V_119 = V_114 & V_115 && ! V_120 ;
V_123 = ( ! V_73 -> V_127 ) && V_119 ;
V_121 = V_73 -> V_127 && V_119 ;
V_122 = V_73 -> V_127 && ! V_119 ;
if ( V_123 || V_121 ) {
F_114 ( V_117 , V_128 ,
V_73 -> V_78 ,
V_73 -> V_126 , V_98 ) ;
V_14 = F_33 ( V_30 -> V_43 ,
F_34 ( V_129 ) , V_117 ) ;
if ( V_14 ) {
F_84 ( V_24 , L_6 , & V_98 ) ;
V_73 -> V_127 = false ;
} else {
V_73 -> V_127 = true ;
}
F_115 ( V_30 , V_73 , false ) ;
} else if ( V_122 ) {
F_114 ( V_117 , V_130 ,
V_73 -> V_78 ,
V_73 -> V_126 , V_98 ) ;
V_14 = F_33 ( V_30 -> V_43 , F_34 ( V_129 ) ,
V_117 ) ;
if ( V_14 ) {
F_84 ( V_24 , L_7 , & V_98 ) ;
V_73 -> V_127 = true ;
} else {
V_73 -> V_127 = false ;
}
F_115 ( V_30 , V_73 , true ) ;
}
F_87 ( V_77 ) ;
F_116 ( V_84 ) ;
}
int F_117 ( struct V_131 * V_132 ,
unsigned long V_133 , void * V_134 )
{
struct V_72 * V_73 ;
struct V_84 * V_84 ;
struct V_30 * V_30 ;
unsigned long V_91 ;
struct V_23 * V_24 ;
struct V_135 * V_136 ;
struct V_76 * V_77 ;
T_3 V_98 ;
switch ( V_133 ) {
case V_137 :
V_136 = V_134 ;
if ( ! V_136 -> V_24 || V_136 -> V_87 != & V_88 )
return V_138 ;
V_84 = F_118 ( V_136 -> V_24 ) ;
if ( ! V_84 )
return V_138 ;
V_30 = V_84 -> V_30 ;
V_91 = F_78 ( F_77 ( V_136 , V_93 ) ) ;
V_30 -> V_35 . V_94 . V_91 = V_91 ;
F_116 ( V_84 ) ;
break;
case V_139 :
V_77 = V_134 ;
V_24 = V_77 -> V_24 ;
if ( V_77 -> V_87 != & V_88 )
return V_138 ;
V_84 = F_118 ( V_24 ) ;
if ( ! V_84 )
return V_138 ;
V_30 = V_84 -> V_30 ;
V_98 = F_112 ( * ( ( T_6 * ) V_77 -> V_125 ) ) ;
V_73 = F_70 ( V_30 , V_77 ) ;
if ( F_74 ( ! V_73 ) ) {
F_116 ( V_84 ) ;
return V_138 ;
}
V_73 -> V_84 = V_84 ;
F_119 ( V_77 ) ;
if ( ! F_105 ( & V_73 -> V_80 , 0 ) ) {
F_87 ( V_77 ) ;
F_116 ( V_84 ) ;
}
break;
}
return V_138 ;
}
static int F_120 ( struct V_30 * V_30 )
{
int V_14 ;
V_14 = F_26 ( & V_30 -> V_35 . V_74 ,
& V_75 ) ;
if ( V_14 )
return V_14 ;
F_76 ( V_30 ) ;
F_68 ( & V_30 -> V_35 . V_94 . V_80 ,
F_107 ) ;
F_68 ( & V_30 -> V_35 . V_113 ,
F_110 ) ;
F_105 ( & V_30 -> V_35 . V_94 . V_80 , 0 ) ;
F_105 ( & V_30 -> V_35 . V_113 , 0 ) ;
return 0 ;
}
static void F_121 ( struct V_30 * V_30 )
{
F_122 ( & V_30 -> V_35 . V_94 . V_80 ) ;
F_122 ( & V_30 -> V_35 . V_113 ) ;
F_29 ( & V_30 -> V_35 . V_74 ) ;
}
static int F_123 ( struct V_30 * V_30 ,
struct V_56 * V_57 ,
T_3 V_140 , T_5 V_141 ,
T_3 V_142 ,
T_5 V_143 )
{
char V_144 [ V_145 ] ;
F_124 ( V_144 ,
(enum V_40 ) V_57 -> V_41 , V_57 -> V_42 ,
V_140 , V_141 , V_142 ,
V_143 ) ;
return F_33 ( V_30 -> V_43 , F_34 ( V_146 ) , V_144 ) ;
}
static int F_125 ( struct V_30 * V_30 ,
struct V_147 * V_148 ,
T_3 V_149 , T_5 V_150 )
{
struct V_11 * V_12 ;
struct V_56 * V_57 = NULL ;
int V_14 ;
F_102 (fib_entry, &nh_grp->fib_list, nexthop_group_node) {
if ( V_57 == V_12 -> V_57 )
continue;
V_57 = V_12 -> V_57 ;
V_14 = F_123 ( V_30 , V_57 ,
V_149 ,
V_150 ,
V_148 -> V_140 ,
V_148 -> V_141 ) ;
if ( V_14 )
return V_14 ;
}
return 0 ;
}
static int F_126 ( struct V_30 * V_30 , T_3 V_140 ,
struct V_151 * V_152 )
{
struct V_72 * V_73 = V_152 -> V_73 ;
char V_153 [ V_154 ] ;
F_127 ( V_153 , V_155 ,
true , V_140 , V_73 -> V_78 ) ;
F_128 ( V_153 , V_73 -> V_126 ) ;
return F_33 ( V_30 -> V_43 , F_34 ( V_156 ) , V_153 ) ;
}
static int
F_129 ( struct V_30 * V_30 ,
struct V_147 * V_148 ,
bool V_157 )
{
T_3 V_140 = V_148 -> V_140 ;
struct V_151 * V_152 ;
int V_33 ;
int V_14 ;
for ( V_33 = 0 ; V_33 < V_148 -> V_158 ; V_33 ++ ) {
V_152 = & V_148 -> V_159 [ V_33 ] ;
if ( ! V_152 -> V_160 ) {
V_152 -> V_127 = 0 ;
continue;
}
if ( V_152 -> V_161 || V_157 ) {
V_14 = F_126 ( V_30 ,
V_140 , V_152 ) ;
if ( V_14 )
return V_14 ;
V_152 -> V_161 = 0 ;
V_152 -> V_127 = 1 ;
}
V_140 ++ ;
}
return 0 ;
}
static int
F_130 ( struct V_30 * V_30 ,
struct V_147 * V_148 )
{
struct V_11 * V_12 ;
int V_14 ;
F_102 (fib_entry, &nh_grp->fib_list, nexthop_group_node) {
V_14 = F_131 ( V_30 , V_12 ) ;
if ( V_14 )
return V_14 ;
}
return 0 ;
}
static void
F_132 ( struct V_30 * V_30 ,
struct V_147 * V_148 )
{
struct V_151 * V_152 ;
bool V_162 = false ;
T_3 V_140 ;
T_5 V_141 = 0 ;
bool V_163 ;
T_3 V_149 ;
T_5 V_150 ;
int V_164 ;
int V_33 ;
int V_14 ;
for ( V_33 = 0 ; V_33 < V_148 -> V_158 ; V_33 ++ ) {
V_152 = & V_148 -> V_159 [ V_33 ] ;
if ( V_152 -> V_160 ^ V_152 -> V_127 ) {
V_162 = true ;
if ( V_152 -> V_160 )
V_152 -> V_161 = 1 ;
}
if ( V_152 -> V_160 )
V_141 ++ ;
}
if ( ! V_162 ) {
V_14 = F_129 ( V_30 , V_148 ,
false ) ;
if ( V_14 ) {
F_133 ( V_30 -> V_100 -> V_24 , L_8 ) ;
goto V_165;
}
return;
}
if ( ! V_141 )
goto V_165;
V_164 = F_134 ( V_30 , V_141 ) ;
if ( V_164 < 0 ) {
F_133 ( V_30 -> V_100 -> V_24 , L_9 ) ;
goto V_165;
}
V_140 = V_164 ;
V_163 = V_148 -> V_166 ;
V_149 = V_148 -> V_140 ;
V_150 = V_148 -> V_141 ;
V_148 -> V_166 = 1 ;
V_148 -> V_140 = V_140 ;
V_148 -> V_141 = V_141 ;
V_14 = F_129 ( V_30 , V_148 , true ) ;
if ( V_14 ) {
F_133 ( V_30 -> V_100 -> V_24 , L_8 ) ;
goto V_165;
}
if ( ! V_163 ) {
V_14 = F_130 ( V_30 , V_148 ) ;
if ( V_14 ) {
F_133 ( V_30 -> V_100 -> V_24 , L_10 ) ;
goto V_165;
}
return;
}
V_14 = F_125 ( V_30 , V_148 ,
V_149 , V_150 ) ;
F_135 ( V_30 , V_149 ) ;
if ( V_14 ) {
F_133 ( V_30 -> V_100 -> V_24 , L_11 ) ;
goto V_165;
}
return;
V_165:
V_163 = V_148 -> V_166 ;
V_148 -> V_166 = 0 ;
for ( V_33 = 0 ; V_33 < V_148 -> V_158 ; V_33 ++ ) {
V_152 = & V_148 -> V_159 [ V_33 ] ;
V_152 -> V_127 = 0 ;
}
V_14 = F_130 ( V_30 , V_148 ) ;
if ( V_14 )
F_133 ( V_30 -> V_100 -> V_24 , L_12 ) ;
if ( V_163 )
F_135 ( V_30 , V_148 -> V_140 ) ;
}
static void F_136 ( struct V_151 * V_152 ,
bool V_122 )
{
if ( ! V_122 && ! V_152 -> V_160 )
V_152 -> V_160 = 1 ;
else if ( V_122 && V_152 -> V_127 )
V_152 -> V_160 = 0 ;
V_152 -> V_161 = 1 ;
}
static void
F_115 ( struct V_30 * V_30 ,
struct V_72 * V_73 ,
bool V_122 )
{
struct V_151 * V_152 ;
F_97 () ;
F_102 (nh, &neigh_entry->nexthop_list,
neigh_list_node) {
F_136 ( V_152 , V_122 ) ;
F_132 ( V_30 , V_152 -> V_148 ) ;
}
F_100 () ;
}
static int F_137 ( struct V_30 * V_30 ,
struct V_147 * V_148 ,
struct V_151 * V_152 ,
struct V_167 * V_167 )
{
struct V_72 * V_73 ;
struct V_23 * V_24 = V_167 -> V_168 ;
struct V_76 * V_77 ;
T_2 V_114 , V_120 ;
V_77 = F_83 ( & V_88 , & V_167 -> V_169 , V_24 ) ;
if ( ! V_77 ) {
V_77 = F_138 ( & V_88 , & V_167 -> V_169 , V_24 ) ;
if ( F_42 ( V_77 ) )
return F_54 ( V_77 ) ;
F_86 ( V_77 , NULL ) ;
}
V_73 = F_70 ( V_30 , V_77 ) ;
if ( ! V_73 ) {
F_87 ( V_77 ) ;
return - V_89 ;
}
if ( F_103 ( & V_73 -> V_82 ) )
F_14 ( & V_73 -> V_170 ,
& V_30 -> V_35 . V_171 ) ;
V_152 -> V_148 = V_148 ;
V_152 -> V_73 = V_73 ;
F_14 ( & V_152 -> V_172 , & V_73 -> V_82 ) ;
F_111 ( & V_77 -> V_124 ) ;
V_114 = V_77 -> V_114 ;
V_120 = V_77 -> V_120 ;
F_113 ( & V_77 -> V_124 ) ;
F_136 ( V_152 , ! ( V_114 & V_115 && ! V_120 ) ) ;
return 0 ;
}
static void F_139 ( struct V_30 * V_30 ,
struct V_151 * V_152 )
{
struct V_72 * V_73 = V_152 -> V_73 ;
F_136 ( V_152 , true ) ;
F_16 ( & V_152 -> V_172 ) ;
if ( F_103 ( & V_152 -> V_73 -> V_82 ) )
F_16 ( & V_152 -> V_73 -> V_170 ) ;
F_87 ( V_73 -> V_13 . V_77 ) ;
}
static struct V_147 *
F_140 ( struct V_30 * V_30 , struct V_173 * V_174 )
{
struct V_147 * V_148 ;
struct V_151 * V_152 ;
struct V_167 * V_167 ;
T_1 V_175 ;
int V_33 ;
int V_14 ;
V_175 = sizeof( * V_148 ) +
V_174 -> V_176 * sizeof( struct V_151 ) ;
V_148 = F_19 ( V_175 , V_25 ) ;
if ( ! V_148 )
return F_25 ( - V_27 ) ;
F_27 ( & V_148 -> V_177 ) ;
V_148 -> V_158 = V_174 -> V_176 ;
for ( V_33 = 0 ; V_33 < V_148 -> V_158 ; V_33 ++ ) {
V_152 = & V_148 -> V_159 [ V_33 ] ;
V_167 = & V_174 -> V_167 [ V_33 ] ;
V_14 = F_137 ( V_30 , V_148 , V_152 , V_167 ) ;
if ( V_14 )
goto V_178;
}
F_14 ( & V_148 -> V_18 , & V_30 -> V_35 . V_179 ) ;
F_132 ( V_30 , V_148 ) ;
return V_148 ;
V_178:
for ( V_33 -- ; V_33 >= 0 ; V_33 -- )
F_139 ( V_30 , V_152 ) ;
F_21 ( V_148 ) ;
return F_25 ( V_14 ) ;
}
static void
F_141 ( struct V_30 * V_30 ,
struct V_147 * V_148 )
{
struct V_151 * V_152 ;
int V_33 ;
F_16 ( & V_148 -> V_18 ) ;
for ( V_33 = 0 ; V_33 < V_148 -> V_158 ; V_33 ++ ) {
V_152 = & V_148 -> V_159 [ V_33 ] ;
F_139 ( V_30 , V_152 ) ;
}
F_132 ( V_30 , V_148 ) ;
F_92 ( V_148 -> V_166 ) ;
F_21 ( V_148 ) ;
}
static bool F_142 ( struct V_151 * V_152 ,
struct V_173 * V_174 )
{
int V_33 ;
for ( V_33 = 0 ; V_33 < V_174 -> V_176 ; V_33 ++ ) {
struct V_167 * V_167 = & V_174 -> V_167 [ V_33 ] ;
struct V_76 * V_77 = V_152 -> V_73 -> V_13 . V_77 ;
if ( memcmp ( V_77 -> V_125 , & V_167 -> V_169 ,
sizeof( V_167 -> V_169 ) ) == 0 &&
V_77 -> V_24 == V_167 -> V_168 )
return true ;
}
return false ;
}
static bool F_143 ( struct V_147 * V_148 ,
struct V_173 * V_174 )
{
int V_33 ;
if ( V_148 -> V_158 != V_174 -> V_176 )
return false ;
for ( V_33 = 0 ; V_33 < V_148 -> V_158 ; V_33 ++ ) {
struct V_151 * V_152 = & V_148 -> V_159 [ V_33 ] ;
if ( ! F_142 ( V_152 , V_174 ) )
return false ;
}
return true ;
}
static struct V_147 *
F_144 ( struct V_30 * V_30 , struct V_173 * V_174 )
{
struct V_147 * V_148 ;
F_102 (nh_grp, &mlxsw_sp->router.nexthop_group_list,
list) {
if ( F_143 ( V_148 , V_174 ) )
return V_148 ;
}
return NULL ;
}
static int F_145 ( struct V_30 * V_30 ,
struct V_11 * V_12 ,
struct V_173 * V_174 )
{
struct V_147 * V_148 ;
V_148 = F_144 ( V_30 , V_174 ) ;
if ( ! V_148 ) {
V_148 = F_140 ( V_30 , V_174 ) ;
if ( F_42 ( V_148 ) )
return F_54 ( V_148 ) ;
}
F_14 ( & V_12 -> V_180 , & V_148 -> V_177 ) ;
V_12 -> V_181 = V_148 ;
return 0 ;
}
static void F_146 ( struct V_30 * V_30 ,
struct V_11 * V_12 )
{
struct V_147 * V_148 = V_12 -> V_181 ;
F_16 ( & V_12 -> V_180 ) ;
if ( ! F_103 ( & V_148 -> V_177 ) )
return;
F_141 ( V_30 , V_148 ) ;
}
static int F_147 ( struct V_30 * V_30 ,
struct V_11 * V_12 ,
enum V_182 V_183 )
{
char V_184 [ V_185 ] ;
T_3 * V_186 = ( T_3 * ) V_12 -> V_13 . V_21 ;
struct V_56 * V_57 = V_12 -> V_57 ;
enum V_187 V_188 ;
T_5 V_189 = 0 ;
T_3 V_190 = 0 ;
T_5 V_141 = 0 ;
if ( V_12 -> V_181 -> V_166 ) {
V_188 = V_191 ;
V_190 = V_12 -> V_181 -> V_140 ;
V_141 = V_12 -> V_181 -> V_141 ;
} else {
V_188 = V_192 ;
V_189 = V_193 ;
}
F_148 ( V_184 ,
(enum V_40 ) V_57 -> V_41 , V_183 ,
V_57 -> V_42 , V_12 -> V_13 . V_8 , * V_186 ) ;
F_149 ( V_184 , V_188 , V_189 ,
V_190 , V_141 ) ;
return F_33 ( V_30 -> V_43 , F_34 ( V_194 ) , V_184 ) ;
}
static int F_150 ( struct V_30 * V_30 ,
struct V_11 * V_12 ,
enum V_182 V_183 )
{
char V_184 [ V_185 ] ;
T_3 * V_186 = ( T_3 * ) V_12 -> V_13 . V_21 ;
struct V_56 * V_57 = V_12 -> V_57 ;
F_148 ( V_184 ,
(enum V_40 ) V_57 -> V_41 , V_183 ,
V_57 -> V_42 , V_12 -> V_13 . V_8 , * V_186 ) ;
F_151 ( V_184 ,
V_191 , 0 ,
V_12 -> V_78 ) ;
return F_33 ( V_30 -> V_43 , F_34 ( V_194 ) , V_184 ) ;
}
static int F_152 ( struct V_30 * V_30 ,
struct V_11 * V_12 ,
enum V_182 V_183 )
{
char V_184 [ V_185 ] ;
T_3 * V_186 = ( T_3 * ) V_12 -> V_13 . V_21 ;
struct V_56 * V_57 = V_12 -> V_57 ;
F_148 ( V_184 ,
(enum V_40 ) V_57 -> V_41 , V_183 ,
V_57 -> V_42 , V_12 -> V_13 . V_8 , * V_186 ) ;
F_153 ( V_184 ) ;
return F_33 ( V_30 -> V_43 , F_34 ( V_194 ) , V_184 ) ;
}
static int F_154 ( struct V_30 * V_30 ,
struct V_11 * V_12 ,
enum V_182 V_183 )
{
switch ( V_12 -> type ) {
case V_195 :
return F_147 ( V_30 , V_12 , V_183 ) ;
case V_196 :
return F_150 ( V_30 , V_12 , V_183 ) ;
case V_197 :
return F_152 ( V_30 , V_12 , V_183 ) ;
}
return - V_89 ;
}
static int F_155 ( struct V_30 * V_30 ,
struct V_11 * V_12 ,
enum V_182 V_183 )
{
switch ( V_12 -> V_57 -> V_41 ) {
case V_198 :
return F_154 ( V_30 , V_12 , V_183 ) ;
case V_199 :
return - V_89 ;
}
return - V_89 ;
}
static int F_131 ( struct V_30 * V_30 ,
struct V_11 * V_12 )
{
return F_155 ( V_30 , V_12 ,
V_200 ) ;
}
static int F_156 ( struct V_30 * V_30 ,
struct V_11 * V_12 )
{
return F_155 ( V_30 , V_12 ,
V_201 ) ;
}
static int
F_157 ( struct V_30 * V_30 ,
const struct V_202 * V_203 ,
struct V_11 * V_12 )
{
struct V_173 * V_174 = V_203 -> V_174 ;
struct V_85 * V_86 = NULL ;
int V_204 ;
int V_14 ;
if ( V_203 -> type == V_205 || V_203 -> type == V_206 ) {
V_12 -> type = V_197 ;
return 0 ;
}
if ( V_203 -> type != V_207 )
return - V_89 ;
for ( V_204 = 0 ; V_204 < V_174 -> V_176 ; V_204 ++ ) {
const struct V_167 * V_152 = & V_174 -> V_167 [ V_204 ] ;
if ( ! V_152 -> V_168 )
continue;
V_86 = F_73 ( V_30 , V_152 -> V_168 ) ;
if ( ! V_86 ) {
break;
}
}
if ( ! V_86 ) {
V_12 -> type = V_197 ;
return 0 ;
}
if ( V_174 -> V_208 != V_209 ) {
V_12 -> type = V_196 ;
V_12 -> V_78 = V_86 -> V_78 ;
} else {
V_12 -> type = V_195 ;
V_14 = F_145 ( V_30 , V_12 , V_174 ) ;
if ( V_14 )
return V_14 ;
}
F_158 ( V_203 -> V_174 ) ;
return 0 ;
}
static void
F_159 ( struct V_30 * V_30 ,
struct V_11 * V_12 )
{
if ( V_12 -> type != V_197 )
F_160 ( V_12 -> V_174 ) ;
if ( V_12 -> type == V_195 )
F_146 ( V_30 , V_12 ) ;
}
static struct V_11 *
F_161 ( struct V_30 * V_30 ,
const struct V_202 * V_203 )
{
struct V_11 * V_12 ;
struct V_173 * V_174 = V_203 -> V_174 ;
struct V_56 * V_57 ;
int V_14 ;
V_57 = F_57 ( V_30 , V_203 -> V_210 , V_203 -> V_64 ,
V_198 ) ;
if ( F_42 ( V_57 ) )
return F_53 ( V_57 ) ;
V_12 = F_22 ( V_57 -> V_10 , & V_203 -> V_211 ,
sizeof( V_203 -> V_211 ) ,
V_203 -> V_210 , V_174 -> V_212 ) ;
if ( V_12 ) {
V_12 -> V_37 ++ ;
return V_12 ;
}
V_12 = F_18 ( V_57 -> V_10 , & V_203 -> V_211 ,
sizeof( V_203 -> V_211 ) ,
V_203 -> V_210 , V_174 -> V_212 ) ;
if ( ! V_12 ) {
V_14 = - V_27 ;
goto V_213;
}
V_12 -> V_57 = V_57 ;
V_12 -> V_174 = V_174 ;
V_12 -> V_37 = 1 ;
V_14 = F_157 ( V_30 , V_203 , V_12 ) ;
if ( V_14 )
goto V_214;
return V_12 ;
V_214:
F_20 ( V_12 ) ;
V_213:
F_58 ( V_30 , V_57 ) ;
return F_25 ( V_14 ) ;
}
static struct V_11 *
F_162 ( struct V_30 * V_30 ,
const struct V_202 * V_203 )
{
struct V_56 * V_57 ;
V_57 = F_51 ( V_30 , V_203 -> V_64 ,
V_198 ) ;
if ( ! V_57 )
return NULL ;
return F_22 ( V_57 -> V_10 , & V_203 -> V_211 ,
sizeof( V_203 -> V_211 ) ,
V_203 -> V_210 ,
V_203 -> V_174 -> V_212 ) ;
}
static void F_163 ( struct V_30 * V_30 ,
struct V_11 * V_12 )
{
struct V_56 * V_57 = V_12 -> V_57 ;
if ( -- V_12 -> V_37 == 0 ) {
F_159 ( V_30 , V_12 ) ;
F_20 ( V_12 ) ;
}
F_58 ( V_30 , V_57 ) ;
}
static void F_164 ( struct V_30 * V_30 ,
struct V_11 * V_12 )
{
unsigned int V_215 ;
do {
V_215 = V_12 -> V_37 ;
F_163 ( V_30 , V_12 ) ;
} while ( V_215 != 1 );
}
static int F_165 ( struct V_30 * V_30 ,
struct V_202 * V_203 )
{
struct V_11 * V_12 ;
struct V_56 * V_57 ;
int V_14 ;
if ( V_30 -> V_35 . V_216 )
return 0 ;
V_12 = F_161 ( V_30 , V_203 ) ;
if ( F_42 ( V_12 ) ) {
F_133 ( V_30 -> V_100 -> V_24 , L_13 ) ;
return F_54 ( V_12 ) ;
}
if ( V_12 -> V_37 != 1 )
return 0 ;
V_57 = V_12 -> V_57 ;
V_14 = F_12 ( V_57 -> V_10 , V_12 ) ;
if ( V_14 ) {
F_133 ( V_30 -> V_100 -> V_24 , L_14 ) ;
goto V_217;
}
V_14 = F_131 ( V_30 , V_12 ) ;
if ( V_14 )
goto V_218;
return 0 ;
V_218:
F_15 ( V_57 -> V_10 , V_12 ) ;
V_217:
F_163 ( V_30 , V_12 ) ;
return V_14 ;
}
static void F_166 ( struct V_30 * V_30 ,
struct V_202 * V_203 )
{
struct V_11 * V_12 ;
if ( V_30 -> V_35 . V_216 )
return;
V_12 = F_162 ( V_30 , V_203 ) ;
if ( ! V_12 )
return;
if ( V_12 -> V_37 == 1 ) {
F_156 ( V_30 , V_12 ) ;
F_15 ( V_12 -> V_57 -> V_10 , V_12 ) ;
}
F_163 ( V_30 , V_12 ) ;
}
static int F_167 ( struct V_30 * V_30 )
{
char V_38 [ V_39 ] ;
char V_45 [ V_46 ] ;
char V_61 [ V_62 ] ;
char V_184 [ V_185 ] ;
int V_14 ;
F_32 ( V_38 , true , V_219 ,
V_55 ) ;
V_14 = F_33 ( V_30 -> V_43 , F_34 ( V_44 ) , V_38 ) ;
if ( V_14 )
return V_14 ;
F_37 ( V_45 , 0xff , V_55 ) ;
V_14 = F_33 ( V_30 -> V_43 , F_34 ( V_50 ) , V_45 ) ;
if ( V_14 )
return V_14 ;
F_48 ( V_61 , 0 , V_219 ,
V_55 ) ;
V_14 = F_33 ( V_30 -> V_43 , F_34 ( V_63 ) , V_61 ) ;
if ( V_14 )
return V_14 ;
F_148 ( V_184 , V_198 ,
V_200 , 0 , 0 , 0 ) ;
F_153 ( V_184 ) ;
return F_33 ( V_30 -> V_43 , F_34 ( V_194 ) , V_184 ) ;
}
static void F_64 ( struct V_30 * V_30 )
{
struct V_11 * V_12 ;
struct V_11 * V_220 ;
struct V_56 * V_57 ;
int V_33 ;
for ( V_33 = 0 ; V_33 < F_46 ( V_30 -> V_43 , V_58 ) ; V_33 ++ ) {
V_57 = & V_30 -> V_35 . V_59 [ V_33 ] ;
if ( ! V_57 -> V_60 )
continue;
F_168 (fib_entry, tmp,
&vr->fib->entry_list, list) {
bool V_221 = & V_220 -> V_18 == & V_57 -> V_10 -> V_19 ;
F_156 ( V_30 , V_12 ) ;
F_15 ( V_12 -> V_57 -> V_10 ,
V_12 ) ;
F_164 ( V_30 , V_12 ) ;
if ( V_221 )
break;
}
}
}
static void F_169 ( struct V_30 * V_30 )
{
int V_14 ;
if ( V_30 -> V_35 . V_216 )
return;
F_133 ( V_30 -> V_100 -> V_24 , L_15 ) ;
F_64 ( V_30 ) ;
V_30 -> V_35 . V_216 = true ;
V_14 = F_167 ( V_30 ) ;
if ( V_14 )
F_133 ( V_30 -> V_100 -> V_24 , L_16 ) ;
}
static int F_170 ( struct V_30 * V_30 )
{
char V_222 [ V_223 ] ;
T_4 V_224 ;
int V_14 ;
if ( ! F_60 ( V_30 -> V_43 , V_225 ) )
return - V_71 ;
V_224 = F_46 ( V_30 -> V_43 , V_225 ) ;
V_30 -> V_99 = F_61 ( V_224 , sizeof( struct V_85 * ) ,
V_25 ) ;
if ( ! V_30 -> V_99 )
return - V_27 ;
F_171 ( V_222 , true ) ;
F_172 ( V_222 , V_224 ) ;
V_14 = F_33 ( V_30 -> V_43 , F_34 ( V_226 ) , V_222 ) ;
if ( V_14 )
goto V_227;
return 0 ;
V_227:
F_21 ( V_30 -> V_99 ) ;
return V_14 ;
}
static void F_173 ( struct V_30 * V_30 )
{
char V_222 [ V_223 ] ;
int V_33 ;
F_171 ( V_222 , false ) ;
F_33 ( V_30 -> V_43 , F_34 ( V_226 ) , V_222 ) ;
for ( V_33 = 0 ; V_33 < F_46 ( V_30 -> V_43 , V_225 ) ; V_33 ++ )
F_92 ( V_30 -> V_99 [ V_33 ] ) ;
F_21 ( V_30 -> V_99 ) ;
}
static void F_174 ( struct V_111 * V_112 )
{
struct V_228 * V_229 =
F_108 ( V_112 , struct V_228 , V_80 . V_112 ) ;
struct V_30 * V_30 = V_229 -> V_30 ;
int V_14 ;
F_97 () ;
switch ( V_229 -> V_133 ) {
case V_230 :
V_14 = F_165 ( V_30 , & V_229 -> V_203 ) ;
if ( V_14 )
F_169 ( V_30 ) ;
F_175 ( V_229 -> V_203 . V_174 ) ;
break;
case V_231 :
F_166 ( V_30 , & V_229 -> V_203 ) ;
F_175 ( V_229 -> V_203 . V_174 ) ;
break;
case V_232 :
case V_233 :
F_169 ( V_30 ) ;
break;
}
F_100 () ;
F_21 ( V_229 ) ;
}
static int F_176 ( struct V_131 * V_234 ,
unsigned long V_133 , void * V_134 )
{
struct V_30 * V_30 = F_108 ( V_234 , struct V_30 , V_235 ) ;
struct V_228 * V_229 ;
struct V_236 * V_237 = V_134 ;
if ( ! F_177 ( V_237 -> V_238 , & V_239 ) )
return V_138 ;
V_229 = F_19 ( sizeof( * V_229 ) , V_79 ) ;
if ( F_74 ( ! V_229 ) )
return V_240 ;
F_68 ( & V_229 -> V_80 , F_174 ) ;
V_229 -> V_30 = V_30 ;
V_229 -> V_133 = V_133 ;
switch ( V_133 ) {
case V_230 :
case V_231 :
memcpy ( & V_229 -> V_203 , V_134 , sizeof( V_229 -> V_203 ) ) ;
F_178 ( V_229 -> V_203 . V_174 ) ;
break;
}
F_179 ( & V_229 -> V_80 , 0 ) ;
return V_138 ;
}
static void F_180 ( struct V_131 * V_234 )
{
struct V_30 * V_30 = F_108 ( V_234 , struct V_30 , V_235 ) ;
F_63 () ;
F_64 ( V_30 ) ;
}
int F_181 ( struct V_30 * V_30 )
{
int V_14 ;
F_27 ( & V_30 -> V_35 . V_171 ) ;
F_27 ( & V_30 -> V_35 . V_179 ) ;
V_14 = F_170 ( V_30 ) ;
if ( V_14 )
return V_14 ;
F_44 ( V_30 ) ;
V_14 = F_59 ( V_30 ) ;
if ( V_14 )
goto V_241;
V_14 = F_120 ( V_30 ) ;
if ( V_14 )
goto V_242;
V_30 -> V_235 . V_243 = F_176 ;
V_14 = F_182 ( & V_30 -> V_235 ,
F_180 ) ;
if ( V_14 )
goto V_244;
return 0 ;
V_244:
F_121 ( V_30 ) ;
V_242:
F_62 ( V_30 ) ;
V_241:
F_173 ( V_30 ) ;
return V_14 ;
}
void F_183 ( struct V_30 * V_30 )
{
F_184 ( & V_30 -> V_235 ) ;
F_121 ( V_30 ) ;
F_62 ( V_30 ) ;
F_173 ( V_30 ) ;
}
