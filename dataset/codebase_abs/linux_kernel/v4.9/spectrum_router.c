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
struct V_57 * V_58 ;
struct V_56 * V_59 ;
int V_33 ;
V_58 = F_46 ( V_30 -> V_43 ) ;
for ( V_33 = 0 ; V_33 < V_58 -> V_60 ; V_33 ++ ) {
V_59 = & V_30 -> V_35 . V_61 [ V_33 ] ;
if ( ! V_59 -> V_62 )
return V_59 ;
}
return NULL ;
}
static int F_47 ( struct V_30 * V_30 ,
struct V_56 * V_59 )
{
char V_63 [ V_64 ] ;
F_48 ( V_63 , V_59 -> V_42 ,
(enum V_40 ) V_59 -> V_41 ,
V_59 -> V_32 -> V_42 ) ;
return F_33 ( V_30 -> V_43 , F_34 ( V_65 ) , V_63 ) ;
}
static int F_49 ( struct V_30 * V_30 ,
struct V_56 * V_59 )
{
char V_63 [ V_64 ] ;
F_48 ( V_63 , V_59 -> V_42 ,
(enum V_40 ) V_59 -> V_41 , 0 ) ;
return F_33 ( V_30 -> V_43 , F_34 ( V_65 ) , V_63 ) ;
}
static T_3 F_50 ( T_3 V_66 )
{
if ( V_66 == V_67 )
V_66 = V_68 ;
return V_66 ;
}
static struct V_56 * F_51 ( struct V_30 * V_30 ,
T_3 V_66 ,
enum V_51 V_41 )
{
struct V_57 * V_58 ;
struct V_56 * V_59 ;
int V_33 ;
V_66 = F_50 ( V_66 ) ;
V_58 = F_46 ( V_30 -> V_43 ) ;
for ( V_33 = 0 ; V_33 < V_58 -> V_60 ; V_33 ++ ) {
V_59 = & V_30 -> V_35 . V_61 [ V_33 ] ;
if ( V_59 -> V_62 && V_59 -> V_41 == V_41 && V_59 -> V_66 == V_66 )
return V_59 ;
}
return NULL ;
}
static struct V_56 * F_52 ( struct V_30 * V_30 ,
unsigned char V_8 ,
T_3 V_66 ,
enum V_51 V_41 )
{
struct V_1 V_69 ;
struct V_29 * V_32 ;
struct V_56 * V_59 ;
int V_14 ;
V_59 = F_45 ( V_30 ) ;
if ( ! V_59 )
return F_25 ( - V_52 ) ;
V_59 -> V_10 = F_24 () ;
if ( F_42 ( V_59 -> V_10 ) )
return F_53 ( V_59 -> V_10 ) ;
V_59 -> V_41 = V_41 ;
V_59 -> V_66 = V_66 ;
F_7 ( & V_69 ) ;
F_8 ( & V_69 , V_8 ) ;
V_32 = F_41 ( V_30 , & V_69 ,
V_41 , true ) ;
if ( F_42 ( V_32 ) ) {
V_14 = F_54 ( V_32 ) ;
goto V_70;
}
V_59 -> V_32 = V_32 ;
V_14 = F_47 ( V_30 , V_59 ) ;
if ( V_14 )
goto V_71;
V_59 -> V_62 = true ;
return V_59 ;
V_71:
F_43 ( V_30 , V_59 -> V_32 ) ;
V_70:
F_28 ( V_59 -> V_10 ) ;
return F_25 ( V_14 ) ;
}
static void F_55 ( struct V_30 * V_30 ,
struct V_56 * V_59 )
{
F_49 ( V_30 , V_59 ) ;
F_43 ( V_30 , V_59 -> V_32 ) ;
F_28 ( V_59 -> V_10 ) ;
V_59 -> V_62 = false ;
}
static int
F_56 ( struct V_30 * V_30 , struct V_56 * V_59 ,
struct V_1 * V_69 )
{
struct V_29 * V_32 ;
if ( F_4 ( V_69 ,
& V_59 -> V_32 -> V_6 ) )
return 0 ;
V_32 = F_41 ( V_30 , V_69 ,
V_59 -> V_41 , false ) ;
if ( F_42 ( V_32 ) ) {
if ( F_1 ( V_69 ,
& V_59 -> V_32 -> V_6 ) )
return 0 ;
return F_54 ( V_32 ) ;
}
F_49 ( V_30 , V_59 ) ;
F_43 ( V_30 , V_59 -> V_32 ) ;
V_59 -> V_32 = V_32 ;
return F_47 ( V_30 , V_59 ) ;
}
static struct V_56 * F_57 ( struct V_30 * V_30 ,
unsigned char V_8 ,
T_3 V_66 ,
enum V_51 V_41 )
{
struct V_56 * V_59 ;
int V_14 ;
V_66 = F_50 ( V_66 ) ;
V_59 = F_51 ( V_30 , V_66 , V_41 ) ;
if ( ! V_59 ) {
V_59 = F_52 ( V_30 , V_8 , V_66 , V_41 ) ;
if ( F_42 ( V_59 ) )
return V_59 ;
} else {
struct V_1 V_69 ;
F_6 ( & V_69 ,
& V_59 -> V_10 -> V_6 ) ;
F_8 ( & V_69 , V_8 ) ;
V_14 = F_56 ( V_30 , V_59 ,
& V_69 ) ;
if ( V_14 )
return F_25 ( V_14 ) ;
}
return V_59 ;
}
static void F_58 ( struct V_30 * V_30 , struct V_56 * V_59 )
{
if ( F_5 ( & V_59 -> V_10 -> V_6 ) )
F_55 ( V_30 , V_59 ) ;
else
F_56 ( V_30 , V_59 ,
& V_59 -> V_10 -> V_6 ) ;
}
static int F_59 ( struct V_30 * V_30 )
{
struct V_57 * V_58 ;
struct V_56 * V_59 ;
int V_33 ;
V_58 = F_46 ( V_30 -> V_43 ) ;
if ( ! V_58 -> V_72 )
return - V_73 ;
V_30 -> V_35 . V_61 = F_60 ( V_58 -> V_60 ,
sizeof( struct V_56 ) ,
V_25 ) ;
if ( ! V_30 -> V_35 . V_61 )
return - V_27 ;
for ( V_33 = 0 ; V_33 < V_58 -> V_60 ; V_33 ++ ) {
V_59 = & V_30 -> V_35 . V_61 [ V_33 ] ;
V_59 -> V_42 = V_33 ;
}
return 0 ;
}
static void F_61 ( struct V_30 * V_30 )
{
F_62 ( V_30 ) ;
F_21 ( V_30 -> V_35 . V_61 ) ;
}
static int
F_63 ( struct V_30 * V_30 ,
struct V_74 * V_75 )
{
return F_13 ( & V_30 -> V_35 . V_76 ,
& V_75 -> V_16 ,
V_77 ) ;
}
static void
F_64 ( struct V_30 * V_30 ,
struct V_74 * V_75 )
{
F_17 ( & V_30 -> V_35 . V_76 ,
& V_75 -> V_16 ,
V_77 ) ;
}
static struct V_74 *
F_65 ( struct V_78 * V_79 , T_4 V_80 )
{
struct V_74 * V_75 ;
V_75 = F_19 ( sizeof( * V_75 ) , V_81 ) ;
if ( ! V_75 )
return NULL ;
V_75 -> V_13 . V_79 = V_79 ;
V_75 -> V_80 = V_80 ;
F_66 ( & V_75 -> V_82 , V_83 ) ;
F_27 ( & V_75 -> V_84 ) ;
return V_75 ;
}
static void
F_67 ( struct V_74 * V_75 )
{
F_21 ( V_75 ) ;
}
static struct V_74 *
F_68 ( struct V_30 * V_30 , struct V_78 * V_79 )
{
struct V_85 V_13 ;
V_13 . V_79 = V_79 ;
return F_23 ( & V_30 -> V_35 . V_76 ,
& V_13 , V_77 ) ;
}
int F_69 ( struct V_23 * V_24 ,
struct V_78 * V_79 )
{
struct V_86 * V_86 = F_70 ( V_24 ) ;
struct V_30 * V_30 = V_86 -> V_30 ;
struct V_74 * V_75 ;
struct V_87 * V_88 ;
int V_14 ;
if ( V_79 -> V_89 != & V_90 )
return 0 ;
V_75 = F_68 ( V_30 , V_79 ) ;
if ( V_75 )
return 0 ;
V_88 = F_71 ( V_30 , V_79 -> V_24 ) ;
if ( F_72 ( ! V_88 ) )
return - V_91 ;
V_75 = F_65 ( V_79 , V_88 -> V_80 ) ;
if ( ! V_75 )
return - V_27 ;
V_14 = F_63 ( V_30 , V_75 ) ;
if ( V_14 )
goto V_92;
return 0 ;
V_92:
F_67 ( V_75 ) ;
return V_14 ;
}
void F_73 ( struct V_23 * V_24 ,
struct V_78 * V_79 )
{
struct V_86 * V_86 = F_70 ( V_24 ) ;
struct V_30 * V_30 = V_86 -> V_30 ;
struct V_74 * V_75 ;
if ( V_79 -> V_89 != & V_90 )
return;
V_75 = F_68 ( V_30 , V_79 ) ;
if ( ! V_75 )
return;
F_64 ( V_30 , V_75 ) ;
F_67 ( V_75 ) ;
}
static void
F_74 ( struct V_30 * V_30 )
{
unsigned long V_93 = F_75 ( & V_90 . V_94 , V_95 ) ;
V_30 -> V_35 . V_96 . V_93 = F_76 ( V_93 ) ;
}
static void F_77 ( struct V_30 * V_30 ,
char * V_97 ,
int V_98 )
{
struct V_23 * V_24 ;
struct V_78 * V_79 ;
T_5 V_99 ;
T_3 V_100 ;
T_4 V_80 ;
F_78 ( V_97 , V_98 , & V_80 , & V_100 ) ;
if ( ! V_30 -> V_101 [ V_80 ] ) {
F_79 ( V_30 -> V_102 -> V_24 , L_1 ) ;
return;
}
V_99 = F_80 ( V_100 ) ;
V_24 = V_30 -> V_101 [ V_80 ] -> V_24 ;
V_79 = F_81 ( & V_90 , & V_99 , V_24 ) ;
if ( ! V_79 ) {
F_82 ( V_24 , L_2 ,
& V_100 ) ;
return;
}
F_83 ( V_24 , L_3 , & V_100 ) ;
F_84 ( V_79 , NULL ) ;
F_85 ( V_79 ) ;
}
static void F_86 ( struct V_30 * V_30 ,
char * V_97 ,
int V_103 )
{
T_2 V_104 ;
int V_33 ;
V_104 = F_87 ( V_97 ,
V_103 ) ;
V_104 ++ ;
for ( V_33 = 0 ; V_33 < V_104 ; V_33 ++ ) {
int V_98 ;
V_98 = V_103 * V_105 + V_33 ;
F_77 ( V_30 , V_97 ,
V_98 ) ;
}
}
static void F_88 ( struct V_30 * V_30 ,
char * V_97 , int V_103 )
{
switch ( F_89 ( V_97 , V_103 ) ) {
case V_106 :
F_86 ( V_30 , V_97 ,
V_103 ) ;
break;
case V_107 :
F_90 ( 1 ) ;
break;
}
}
static bool F_91 ( char * V_97 )
{
T_2 V_108 , V_109 , V_104 ;
V_108 = F_92 ( V_97 ) ;
V_109 = V_108 - 1 ;
if ( V_108 < V_110 )
return false ;
if ( F_89 ( V_97 , V_109 ) ==
V_107 )
return true ;
V_104 = F_87 ( V_97 ,
V_109 ) ;
if ( ++ V_104 == V_105 )
return true ;
return false ;
}
static int F_93 ( struct V_30 * V_30 )
{
char * V_97 ;
T_2 V_108 ;
int V_33 , V_14 ;
V_97 = F_94 ( V_111 , V_25 ) ;
if ( ! V_97 )
return - V_27 ;
F_95 () ;
do {
F_96 ( V_97 , V_106 ) ;
V_14 = F_97 ( V_30 -> V_43 , F_34 ( V_112 ) ,
V_97 ) ;
if ( V_14 ) {
F_79 ( V_30 -> V_102 -> V_24 , L_4 ) ;
break;
}
V_108 = F_92 ( V_97 ) ;
for ( V_33 = 0 ; V_33 < V_108 ; V_33 ++ )
F_88 ( V_30 , V_97 ,
V_33 ) ;
} while ( F_91 ( V_97 ) );
F_98 () ;
F_21 ( V_97 ) ;
return V_14 ;
}
static void F_99 ( struct V_30 * V_30 )
{
struct V_74 * V_75 ;
F_95 () ;
F_100 (neigh_entry, &mlxsw_sp->router.nexthop_neighs_list,
nexthop_neighs_list_node) {
if ( ! F_101 ( & V_75 -> V_84 ) )
F_84 ( V_75 -> V_13 . V_79 , NULL ) ;
}
F_98 () ;
}
static void
F_102 ( struct V_30 * V_30 )
{
unsigned long V_93 = V_30 -> V_35 . V_96 . V_93 ;
F_103 ( & V_30 -> V_35 . V_96 . V_82 ,
F_104 ( V_93 ) ) ;
}
static void F_105 ( struct V_113 * V_114 )
{
struct V_30 * V_30 = F_106 ( V_114 , struct V_30 ,
V_35 . V_96 . V_82 . V_114 ) ;
int V_14 ;
V_14 = F_93 ( V_30 ) ;
if ( V_14 )
F_107 ( V_30 -> V_102 -> V_24 , L_5 ) ;
F_99 ( V_30 ) ;
F_102 ( V_30 ) ;
}
static void F_108 ( struct V_113 * V_114 )
{
struct V_74 * V_75 ;
struct V_30 * V_30 = F_106 ( V_114 , struct V_30 ,
V_35 . V_115 . V_114 ) ;
F_95 () ;
F_100 (neigh_entry, &mlxsw_sp->router.nexthop_neighs_list,
nexthop_neighs_list_node) {
if ( ! ( V_75 -> V_13 . V_79 -> V_116 & V_117 ) &&
! F_101 ( & V_75 -> V_84 ) )
F_84 ( V_75 -> V_13 . V_79 , NULL ) ;
}
F_98 () ;
F_103 ( & V_30 -> V_35 . V_115 ,
V_118 ) ;
}
static void V_83 ( struct V_113 * V_114 )
{
struct V_74 * V_75 =
F_106 ( V_114 , struct V_74 , V_82 . V_114 ) ;
struct V_78 * V_79 = V_75 -> V_13 . V_79 ;
struct V_86 * V_86 = V_75 -> V_86 ;
struct V_30 * V_30 = V_86 -> V_30 ;
char V_119 [ V_120 ] ;
struct V_23 * V_24 ;
bool V_121 ;
T_2 V_116 ;
bool V_122 ;
bool V_123 ;
bool V_124 ;
T_3 V_100 ;
int V_14 ;
F_109 ( & V_79 -> V_125 ) ;
V_100 = F_110 ( * ( ( T_5 * ) V_79 -> V_126 ) ) ;
memcpy ( V_75 -> V_127 , V_79 -> V_127 , sizeof( V_75 -> V_127 ) ) ;
V_116 = V_79 -> V_116 ;
V_24 = V_79 -> V_24 ;
F_111 ( & V_79 -> V_125 ) ;
V_121 = V_116 & V_117 ;
V_124 = ( ! V_75 -> V_128 ) && V_121 ;
V_122 = V_75 -> V_128 && V_121 ;
V_123 = V_75 -> V_128 && ! V_121 ;
if ( V_124 || V_122 ) {
F_112 ( V_119 , V_129 ,
V_75 -> V_80 ,
V_75 -> V_127 , V_100 ) ;
V_14 = F_33 ( V_30 -> V_43 ,
F_34 ( V_130 ) , V_119 ) ;
if ( V_14 ) {
F_82 ( V_24 , L_6 , & V_100 ) ;
V_75 -> V_128 = false ;
} else {
V_75 -> V_128 = true ;
}
F_113 ( V_30 , V_75 , false ) ;
} else if ( V_123 ) {
F_112 ( V_119 , V_131 ,
V_75 -> V_80 ,
V_75 -> V_127 , V_100 ) ;
V_14 = F_33 ( V_30 -> V_43 , F_34 ( V_130 ) ,
V_119 ) ;
if ( V_14 ) {
F_82 ( V_24 , L_7 , & V_100 ) ;
V_75 -> V_128 = true ;
} else {
V_75 -> V_128 = false ;
}
F_113 ( V_30 , V_75 , true ) ;
}
F_85 ( V_79 ) ;
F_114 ( V_86 ) ;
}
int F_115 ( struct V_132 * V_133 ,
unsigned long V_134 , void * V_135 )
{
struct V_74 * V_75 ;
struct V_86 * V_86 ;
struct V_30 * V_30 ;
unsigned long V_93 ;
struct V_23 * V_24 ;
struct V_136 * V_137 ;
struct V_78 * V_79 ;
T_3 V_100 ;
switch ( V_134 ) {
case V_138 :
V_137 = V_135 ;
if ( ! V_137 -> V_24 || V_137 -> V_89 != & V_90 )
return V_139 ;
V_86 = F_116 ( V_137 -> V_24 ) ;
if ( ! V_86 )
return V_139 ;
V_30 = V_86 -> V_30 ;
V_93 = F_76 ( F_75 ( V_137 , V_95 ) ) ;
V_30 -> V_35 . V_96 . V_93 = V_93 ;
F_114 ( V_86 ) ;
break;
case V_140 :
V_79 = V_135 ;
V_24 = V_79 -> V_24 ;
if ( V_79 -> V_89 != & V_90 )
return V_139 ;
V_86 = F_116 ( V_24 ) ;
if ( ! V_86 )
return V_139 ;
V_30 = V_86 -> V_30 ;
V_100 = F_110 ( * ( ( T_5 * ) V_79 -> V_126 ) ) ;
V_75 = F_68 ( V_30 , V_79 ) ;
if ( F_72 ( ! V_75 ) ) {
F_114 ( V_86 ) ;
return V_139 ;
}
V_75 -> V_86 = V_86 ;
F_117 ( V_79 ) ;
if ( ! F_103 ( & V_75 -> V_82 , 0 ) ) {
F_85 ( V_79 ) ;
F_114 ( V_86 ) ;
}
break;
}
return V_139 ;
}
static int F_118 ( struct V_30 * V_30 )
{
int V_14 ;
V_14 = F_26 ( & V_30 -> V_35 . V_76 ,
& V_77 ) ;
if ( V_14 )
return V_14 ;
F_74 ( V_30 ) ;
F_66 ( & V_30 -> V_35 . V_96 . V_82 ,
F_105 ) ;
F_66 ( & V_30 -> V_35 . V_115 ,
F_108 ) ;
F_103 ( & V_30 -> V_35 . V_96 . V_82 , 0 ) ;
F_103 ( & V_30 -> V_35 . V_115 , 0 ) ;
return 0 ;
}
static void F_119 ( struct V_30 * V_30 )
{
F_120 ( & V_30 -> V_35 . V_96 . V_82 ) ;
F_120 ( & V_30 -> V_35 . V_115 ) ;
F_29 ( & V_30 -> V_35 . V_76 ) ;
}
static int F_121 ( struct V_30 * V_30 ,
struct V_56 * V_59 ,
T_3 V_141 , T_4 V_142 ,
T_3 V_143 ,
T_4 V_144 )
{
char V_145 [ V_146 ] ;
F_122 ( V_145 ,
(enum V_40 ) V_59 -> V_41 , V_59 -> V_42 ,
V_141 , V_142 , V_143 ,
V_144 ) ;
return F_33 ( V_30 -> V_43 , F_34 ( V_147 ) , V_145 ) ;
}
static int F_123 ( struct V_30 * V_30 ,
struct V_148 * V_149 ,
T_3 V_150 , T_4 V_151 )
{
struct V_11 * V_12 ;
struct V_56 * V_59 = NULL ;
int V_14 ;
F_100 (fib_entry, &nh_grp->fib_list, nexthop_group_node) {
if ( V_59 == V_12 -> V_59 )
continue;
V_59 = V_12 -> V_59 ;
V_14 = F_121 ( V_30 , V_59 ,
V_150 ,
V_151 ,
V_149 -> V_141 ,
V_149 -> V_142 ) ;
if ( V_14 )
return V_14 ;
}
return 0 ;
}
static int F_124 ( struct V_30 * V_30 , T_3 V_141 ,
struct V_152 * V_153 )
{
struct V_74 * V_75 = V_153 -> V_75 ;
char V_154 [ V_155 ] ;
F_125 ( V_154 , V_156 ,
true , V_141 , V_75 -> V_80 ) ;
F_126 ( V_154 , V_75 -> V_127 ) ;
return F_33 ( V_30 -> V_43 , F_34 ( V_157 ) , V_154 ) ;
}
static int
F_127 ( struct V_30 * V_30 ,
struct V_148 * V_149 )
{
T_3 V_141 = V_149 -> V_141 ;
struct V_152 * V_153 ;
int V_33 ;
int V_14 ;
for ( V_33 = 0 ; V_33 < V_149 -> V_158 ; V_33 ++ ) {
V_153 = & V_149 -> V_159 [ V_33 ] ;
if ( ! V_153 -> V_160 ) {
V_153 -> V_128 = 0 ;
continue;
}
if ( V_153 -> V_161 ) {
V_14 = F_124 ( V_30 ,
V_141 , V_153 ) ;
if ( V_14 )
return V_14 ;
V_153 -> V_161 = 0 ;
V_153 -> V_128 = 1 ;
}
V_141 ++ ;
}
return 0 ;
}
static int
F_128 ( struct V_30 * V_30 ,
struct V_148 * V_149 )
{
struct V_11 * V_12 ;
int V_14 ;
F_100 (fib_entry, &nh_grp->fib_list, nexthop_group_node) {
V_14 = F_129 ( V_30 , V_12 ) ;
if ( V_14 )
return V_14 ;
}
return 0 ;
}
static void
F_130 ( struct V_30 * V_30 ,
struct V_148 * V_149 )
{
struct V_152 * V_153 ;
bool V_162 = false ;
T_3 V_141 ;
T_4 V_142 = 0 ;
bool V_163 ;
T_3 V_150 ;
T_4 V_151 ;
int V_164 ;
int V_33 ;
int V_14 ;
for ( V_33 = 0 ; V_33 < V_149 -> V_158 ; V_33 ++ ) {
V_153 = & V_149 -> V_159 [ V_33 ] ;
if ( V_153 -> V_160 ^ V_153 -> V_128 ) {
V_162 = true ;
if ( V_153 -> V_160 )
V_153 -> V_161 = 1 ;
}
if ( V_153 -> V_160 )
V_142 ++ ;
}
if ( ! V_162 ) {
V_14 = F_127 ( V_30 , V_149 ) ;
if ( V_14 ) {
F_131 ( V_30 -> V_102 -> V_24 , L_8 ) ;
goto V_165;
}
return;
}
if ( ! V_142 )
goto V_165;
V_164 = F_132 ( V_30 , V_142 ) ;
if ( V_164 < 0 ) {
F_131 ( V_30 -> V_102 -> V_24 , L_9 ) ;
goto V_165;
}
V_141 = V_164 ;
V_163 = V_149 -> V_166 ;
V_150 = V_149 -> V_141 ;
V_151 = V_149 -> V_142 ;
V_149 -> V_166 = 1 ;
V_149 -> V_141 = V_141 ;
V_149 -> V_142 = V_142 ;
V_14 = F_127 ( V_30 , V_149 ) ;
if ( V_14 ) {
F_131 ( V_30 -> V_102 -> V_24 , L_8 ) ;
goto V_165;
}
if ( ! V_163 ) {
V_14 = F_128 ( V_30 , V_149 ) ;
if ( V_14 ) {
F_131 ( V_30 -> V_102 -> V_24 , L_10 ) ;
goto V_165;
}
return;
}
V_14 = F_123 ( V_30 , V_149 ,
V_150 , V_151 ) ;
F_133 ( V_30 , V_150 ) ;
if ( V_14 ) {
F_131 ( V_30 -> V_102 -> V_24 , L_11 ) ;
goto V_165;
}
return;
V_165:
V_163 = V_149 -> V_166 ;
V_149 -> V_166 = 0 ;
for ( V_33 = 0 ; V_33 < V_149 -> V_158 ; V_33 ++ ) {
V_153 = & V_149 -> V_159 [ V_33 ] ;
V_153 -> V_128 = 0 ;
}
V_14 = F_128 ( V_30 , V_149 ) ;
if ( V_14 )
F_131 ( V_30 -> V_102 -> V_24 , L_12 ) ;
if ( V_163 )
F_133 ( V_30 , V_149 -> V_141 ) ;
}
static void F_134 ( struct V_152 * V_153 ,
bool V_123 )
{
if ( ! V_123 && ! V_153 -> V_160 )
V_153 -> V_160 = 1 ;
else if ( V_123 && V_153 -> V_128 )
V_153 -> V_160 = 0 ;
V_153 -> V_161 = 1 ;
}
static void
F_113 ( struct V_30 * V_30 ,
struct V_74 * V_75 ,
bool V_123 )
{
struct V_152 * V_153 ;
F_95 () ;
F_100 (nh, &neigh_entry->nexthop_list,
neigh_list_node) {
F_134 ( V_153 , V_123 ) ;
F_130 ( V_30 , V_153 -> V_149 ) ;
}
F_98 () ;
}
static int F_135 ( struct V_30 * V_30 ,
struct V_148 * V_149 ,
struct V_152 * V_153 ,
struct V_167 * V_167 )
{
struct V_74 * V_75 ;
struct V_23 * V_24 = V_167 -> V_168 ;
struct V_78 * V_79 ;
T_2 V_116 ;
V_79 = F_81 ( & V_90 , & V_167 -> V_169 , V_24 ) ;
if ( ! V_79 ) {
V_79 = F_136 ( & V_90 , & V_167 -> V_169 , V_24 ) ;
if ( F_42 ( V_79 ) )
return F_54 ( V_79 ) ;
F_84 ( V_79 , NULL ) ;
}
V_75 = F_68 ( V_30 , V_79 ) ;
if ( ! V_75 ) {
F_85 ( V_79 ) ;
return - V_91 ;
}
if ( F_101 ( & V_75 -> V_84 ) )
F_14 ( & V_75 -> V_170 ,
& V_30 -> V_35 . V_171 ) ;
V_153 -> V_149 = V_149 ;
V_153 -> V_75 = V_75 ;
F_14 ( & V_153 -> V_172 , & V_75 -> V_84 ) ;
F_109 ( & V_79 -> V_125 ) ;
V_116 = V_79 -> V_116 ;
F_111 ( & V_79 -> V_125 ) ;
F_134 ( V_153 , ! ( V_116 & V_117 ) ) ;
return 0 ;
}
static void F_137 ( struct V_30 * V_30 ,
struct V_152 * V_153 )
{
struct V_74 * V_75 = V_153 -> V_75 ;
F_16 ( & V_153 -> V_172 ) ;
if ( F_101 ( & V_153 -> V_75 -> V_84 ) )
F_16 ( & V_153 -> V_75 -> V_170 ) ;
F_85 ( V_75 -> V_13 . V_79 ) ;
}
static struct V_148 *
F_138 ( struct V_30 * V_30 , struct V_173 * V_174 )
{
struct V_148 * V_149 ;
struct V_152 * V_153 ;
struct V_167 * V_167 ;
T_1 V_175 ;
int V_33 ;
int V_14 ;
V_175 = sizeof( * V_149 ) +
V_174 -> V_176 * sizeof( struct V_152 ) ;
V_149 = F_19 ( V_175 , V_25 ) ;
if ( ! V_149 )
return F_25 ( - V_27 ) ;
F_27 ( & V_149 -> V_177 ) ;
V_149 -> V_158 = V_174 -> V_176 ;
for ( V_33 = 0 ; V_33 < V_149 -> V_158 ; V_33 ++ ) {
V_153 = & V_149 -> V_159 [ V_33 ] ;
V_167 = & V_174 -> V_167 [ V_33 ] ;
V_14 = F_135 ( V_30 , V_149 , V_153 , V_167 ) ;
if ( V_14 )
goto V_178;
}
F_14 ( & V_149 -> V_18 , & V_30 -> V_35 . V_179 ) ;
F_130 ( V_30 , V_149 ) ;
return V_149 ;
V_178:
for ( V_33 -- ; V_33 >= 0 ; V_33 -- )
F_137 ( V_30 , V_153 ) ;
F_21 ( V_149 ) ;
return F_25 ( V_14 ) ;
}
static void
F_139 ( struct V_30 * V_30 ,
struct V_148 * V_149 )
{
struct V_152 * V_153 ;
int V_33 ;
F_16 ( & V_149 -> V_18 ) ;
for ( V_33 = 0 ; V_33 < V_149 -> V_158 ; V_33 ++ ) {
V_153 = & V_149 -> V_159 [ V_33 ] ;
F_137 ( V_30 , V_153 ) ;
}
F_21 ( V_149 ) ;
}
static bool F_140 ( struct V_152 * V_153 ,
struct V_173 * V_174 )
{
int V_33 ;
for ( V_33 = 0 ; V_33 < V_174 -> V_176 ; V_33 ++ ) {
struct V_167 * V_167 = & V_174 -> V_167 [ V_33 ] ;
struct V_78 * V_79 = V_153 -> V_75 -> V_13 . V_79 ;
if ( memcmp ( V_79 -> V_126 , & V_167 -> V_169 ,
sizeof( V_167 -> V_169 ) ) == 0 &&
V_79 -> V_24 == V_167 -> V_168 )
return true ;
}
return false ;
}
static bool F_141 ( struct V_148 * V_149 ,
struct V_173 * V_174 )
{
int V_33 ;
if ( V_149 -> V_158 != V_174 -> V_176 )
return false ;
for ( V_33 = 0 ; V_33 < V_149 -> V_158 ; V_33 ++ ) {
struct V_152 * V_153 = & V_149 -> V_159 [ V_33 ] ;
if ( ! F_140 ( V_153 , V_174 ) )
return false ;
}
return true ;
}
static struct V_148 *
F_142 ( struct V_30 * V_30 , struct V_173 * V_174 )
{
struct V_148 * V_149 ;
F_100 (nh_grp, &mlxsw_sp->router.nexthop_group_list,
list) {
if ( F_141 ( V_149 , V_174 ) )
return V_149 ;
}
return NULL ;
}
static int F_143 ( struct V_30 * V_30 ,
struct V_11 * V_12 ,
struct V_173 * V_174 )
{
struct V_148 * V_149 ;
V_149 = F_142 ( V_30 , V_174 ) ;
if ( ! V_149 ) {
V_149 = F_138 ( V_30 , V_174 ) ;
if ( F_42 ( V_149 ) )
return F_54 ( V_149 ) ;
}
F_14 ( & V_12 -> V_180 , & V_149 -> V_177 ) ;
V_12 -> V_181 = V_149 ;
return 0 ;
}
static void F_144 ( struct V_30 * V_30 ,
struct V_11 * V_12 )
{
struct V_148 * V_149 = V_12 -> V_181 ;
F_16 ( & V_12 -> V_180 ) ;
if ( ! F_101 ( & V_149 -> V_177 ) )
return;
F_139 ( V_30 , V_149 ) ;
}
static int F_145 ( struct V_30 * V_30 ,
struct V_11 * V_12 ,
enum V_182 V_183 )
{
char V_184 [ V_185 ] ;
T_3 * V_186 = ( T_3 * ) V_12 -> V_13 . V_21 ;
struct V_56 * V_59 = V_12 -> V_59 ;
enum V_187 V_188 ;
T_4 V_189 = 0 ;
T_3 V_190 = 0 ;
T_4 V_142 = 0 ;
if ( V_12 -> V_181 -> V_166 ) {
V_188 = V_191 ;
V_190 = V_12 -> V_181 -> V_141 ;
V_142 = V_12 -> V_181 -> V_142 ;
} else {
V_188 = V_192 ;
V_189 = V_193 ;
}
F_146 ( V_184 ,
(enum V_40 ) V_59 -> V_41 , V_183 ,
V_59 -> V_42 , V_12 -> V_13 . V_8 , * V_186 ) ;
F_147 ( V_184 , V_188 , V_189 ,
V_190 , V_142 ) ;
return F_33 ( V_30 -> V_43 , F_34 ( V_194 ) , V_184 ) ;
}
static int F_148 ( struct V_30 * V_30 ,
struct V_11 * V_12 ,
enum V_182 V_183 )
{
char V_184 [ V_185 ] ;
T_3 * V_186 = ( T_3 * ) V_12 -> V_13 . V_21 ;
struct V_56 * V_59 = V_12 -> V_59 ;
F_146 ( V_184 ,
(enum V_40 ) V_59 -> V_41 , V_183 ,
V_59 -> V_42 , V_12 -> V_13 . V_8 , * V_186 ) ;
F_149 ( V_184 ,
V_191 , 0 ,
V_12 -> V_80 ) ;
return F_33 ( V_30 -> V_43 , F_34 ( V_194 ) , V_184 ) ;
}
static int F_150 ( struct V_30 * V_30 ,
struct V_11 * V_12 ,
enum V_182 V_183 )
{
char V_184 [ V_185 ] ;
T_3 * V_186 = ( T_3 * ) V_12 -> V_13 . V_21 ;
struct V_56 * V_59 = V_12 -> V_59 ;
F_146 ( V_184 ,
(enum V_40 ) V_59 -> V_41 , V_183 ,
V_59 -> V_42 , V_12 -> V_13 . V_8 , * V_186 ) ;
F_151 ( V_184 ) ;
return F_33 ( V_30 -> V_43 , F_34 ( V_194 ) , V_184 ) ;
}
static int F_152 ( struct V_30 * V_30 ,
struct V_11 * V_12 ,
enum V_182 V_183 )
{
switch ( V_12 -> type ) {
case V_195 :
return F_145 ( V_30 , V_12 , V_183 ) ;
case V_196 :
return F_148 ( V_30 , V_12 , V_183 ) ;
case V_197 :
return F_150 ( V_30 , V_12 , V_183 ) ;
}
return - V_91 ;
}
static int F_153 ( struct V_30 * V_30 ,
struct V_11 * V_12 ,
enum V_182 V_183 )
{
switch ( V_12 -> V_59 -> V_41 ) {
case V_198 :
return F_152 ( V_30 , V_12 , V_183 ) ;
case V_199 :
return - V_91 ;
}
return - V_91 ;
}
static int F_129 ( struct V_30 * V_30 ,
struct V_11 * V_12 )
{
return F_153 ( V_30 , V_12 ,
V_200 ) ;
}
static int F_154 ( struct V_30 * V_30 ,
struct V_11 * V_12 )
{
return F_153 ( V_30 , V_12 ,
V_201 ) ;
}
static int
F_155 ( struct V_30 * V_30 ,
const struct V_202 * V_203 ,
struct V_11 * V_12 )
{
struct V_173 * V_174 = V_203 -> V_174 ;
struct V_87 * V_88 = NULL ;
int V_204 ;
int V_14 ;
if ( V_203 -> type == V_205 || V_203 -> type == V_206 ) {
V_12 -> type = V_197 ;
return 0 ;
}
if ( V_203 -> type != V_207 )
return - V_91 ;
for ( V_204 = 0 ; V_204 < V_174 -> V_176 ; V_204 ++ ) {
const struct V_167 * V_153 = & V_174 -> V_167 [ V_204 ] ;
if ( ! V_153 -> V_168 )
continue;
V_88 = F_71 ( V_30 , V_153 -> V_168 ) ;
if ( ! V_88 ) {
break;
}
}
if ( ! V_88 ) {
V_12 -> type = V_197 ;
return 0 ;
}
if ( V_174 -> V_208 != V_209 ) {
V_12 -> type = V_196 ;
V_12 -> V_80 = V_88 -> V_80 ;
} else {
V_12 -> type = V_195 ;
V_14 = F_143 ( V_30 , V_12 , V_174 ) ;
if ( V_14 )
return V_14 ;
}
F_156 ( V_203 -> V_174 ) ;
return 0 ;
}
static void
F_157 ( struct V_30 * V_30 ,
struct V_11 * V_12 )
{
if ( V_12 -> type != V_197 )
F_158 ( V_12 -> V_174 ) ;
if ( V_12 -> type == V_195 )
F_144 ( V_30 , V_12 ) ;
}
static struct V_11 *
F_159 ( struct V_30 * V_30 ,
const struct V_202 * V_203 )
{
struct V_11 * V_12 ;
struct V_173 * V_174 = V_203 -> V_174 ;
struct V_56 * V_59 ;
int V_14 ;
V_59 = F_57 ( V_30 , V_203 -> V_210 , V_203 -> V_66 ,
V_198 ) ;
if ( F_42 ( V_59 ) )
return F_53 ( V_59 ) ;
V_12 = F_22 ( V_59 -> V_10 , & V_203 -> V_211 ,
sizeof( V_203 -> V_211 ) ,
V_203 -> V_210 , V_174 -> V_212 ) ;
if ( V_12 ) {
V_12 -> V_37 ++ ;
return V_12 ;
}
V_12 = F_18 ( V_59 -> V_10 , & V_203 -> V_211 ,
sizeof( V_203 -> V_211 ) ,
V_203 -> V_210 , V_174 -> V_212 ) ;
if ( ! V_12 ) {
V_14 = - V_27 ;
goto V_213;
}
V_12 -> V_59 = V_59 ;
V_12 -> V_174 = V_174 ;
V_12 -> V_37 = 1 ;
V_14 = F_155 ( V_30 , V_203 , V_12 ) ;
if ( V_14 )
goto V_214;
return V_12 ;
V_214:
F_20 ( V_12 ) ;
V_213:
F_58 ( V_30 , V_59 ) ;
return F_25 ( V_14 ) ;
}
static struct V_11 *
F_160 ( struct V_30 * V_30 ,
const struct V_202 * V_203 )
{
struct V_56 * V_59 ;
V_59 = F_51 ( V_30 , V_203 -> V_66 ,
V_198 ) ;
if ( ! V_59 )
return NULL ;
return F_22 ( V_59 -> V_10 , & V_203 -> V_211 ,
sizeof( V_203 -> V_211 ) ,
V_203 -> V_210 ,
V_203 -> V_174 -> V_212 ) ;
}
static void F_161 ( struct V_30 * V_30 ,
struct V_11 * V_12 )
{
struct V_56 * V_59 = V_12 -> V_59 ;
if ( -- V_12 -> V_37 == 0 ) {
F_157 ( V_30 , V_12 ) ;
F_20 ( V_12 ) ;
}
F_58 ( V_30 , V_59 ) ;
}
static void F_162 ( struct V_30 * V_30 ,
struct V_11 * V_12 )
{
unsigned int V_215 ;
do {
V_215 = V_12 -> V_37 ;
F_161 ( V_30 , V_12 ) ;
} while ( V_215 != 1 );
}
static int F_163 ( struct V_30 * V_30 ,
struct V_202 * V_203 )
{
struct V_11 * V_12 ;
struct V_56 * V_59 ;
int V_14 ;
if ( V_30 -> V_35 . V_216 )
return 0 ;
V_12 = F_159 ( V_30 , V_203 ) ;
if ( F_42 ( V_12 ) ) {
F_131 ( V_30 -> V_102 -> V_24 , L_13 ) ;
return F_54 ( V_12 ) ;
}
if ( V_12 -> V_37 != 1 )
return 0 ;
V_59 = V_12 -> V_59 ;
V_14 = F_12 ( V_59 -> V_10 , V_12 ) ;
if ( V_14 ) {
F_131 ( V_30 -> V_102 -> V_24 , L_14 ) ;
goto V_217;
}
V_14 = F_129 ( V_30 , V_12 ) ;
if ( V_14 )
goto V_218;
return 0 ;
V_218:
F_15 ( V_59 -> V_10 , V_12 ) ;
V_217:
F_161 ( V_30 , V_12 ) ;
return V_14 ;
}
static void F_164 ( struct V_30 * V_30 ,
struct V_202 * V_203 )
{
struct V_11 * V_12 ;
if ( V_30 -> V_35 . V_216 )
return;
V_12 = F_160 ( V_30 , V_203 ) ;
if ( ! V_12 )
return;
if ( V_12 -> V_37 == 1 ) {
F_154 ( V_30 , V_12 ) ;
F_15 ( V_12 -> V_59 -> V_10 , V_12 ) ;
}
F_161 ( V_30 , V_12 ) ;
}
static int F_165 ( struct V_30 * V_30 )
{
char V_38 [ V_39 ] ;
char V_45 [ V_46 ] ;
char V_63 [ V_64 ] ;
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
F_48 ( V_63 , 0 , V_219 ,
V_55 ) ;
V_14 = F_33 ( V_30 -> V_43 , F_34 ( V_65 ) , V_63 ) ;
if ( V_14 )
return V_14 ;
F_146 ( V_184 , V_198 ,
V_200 , 0 , 0 , 0 ) ;
F_151 ( V_184 ) ;
return F_33 ( V_30 -> V_43 , F_34 ( V_194 ) , V_184 ) ;
}
static void F_62 ( struct V_30 * V_30 )
{
struct V_57 * V_58 ;
struct V_11 * V_12 ;
struct V_11 * V_220 ;
struct V_56 * V_59 ;
int V_33 ;
V_58 = F_46 ( V_30 -> V_43 ) ;
for ( V_33 = 0 ; V_33 < V_58 -> V_60 ; V_33 ++ ) {
V_59 = & V_30 -> V_35 . V_61 [ V_33 ] ;
if ( ! V_59 -> V_62 )
continue;
F_166 (fib_entry, tmp,
&vr->fib->entry_list, list) {
bool V_221 = & V_220 -> V_18 == & V_59 -> V_10 -> V_19 ;
F_154 ( V_30 , V_12 ) ;
F_15 ( V_12 -> V_59 -> V_10 ,
V_12 ) ;
F_162 ( V_30 , V_12 ) ;
if ( V_221 )
break;
}
}
}
static void F_167 ( struct V_30 * V_30 )
{
int V_14 ;
F_62 ( V_30 ) ;
V_30 -> V_35 . V_216 = true ;
V_14 = F_165 ( V_30 ) ;
if ( V_14 )
F_131 ( V_30 -> V_102 -> V_24 , L_15 ) ;
}
static int F_168 ( struct V_30 * V_30 )
{
struct V_57 * V_58 ;
char V_222 [ V_223 ] ;
int V_14 ;
V_58 = F_46 ( V_30 -> V_43 ) ;
if ( ! V_58 -> V_224 )
return - V_73 ;
V_30 -> V_101 = F_60 ( V_58 -> V_225 ,
sizeof( struct V_87 * ) , V_25 ) ;
if ( ! V_30 -> V_101 )
return - V_27 ;
F_169 ( V_222 , true ) ;
F_170 ( V_222 , V_58 -> V_225 ) ;
V_14 = F_33 ( V_30 -> V_43 , F_34 ( V_226 ) , V_222 ) ;
if ( V_14 )
goto V_227;
return 0 ;
V_227:
F_21 ( V_30 -> V_101 ) ;
return V_14 ;
}
static void F_171 ( struct V_30 * V_30 )
{
struct V_57 * V_58 ;
char V_222 [ V_223 ] ;
int V_33 ;
F_169 ( V_222 , false ) ;
F_33 ( V_30 -> V_43 , F_34 ( V_226 ) , V_222 ) ;
V_58 = F_46 ( V_30 -> V_43 ) ;
for ( V_33 = 0 ; V_33 < V_58 -> V_225 ; V_33 ++ )
F_90 ( V_30 -> V_101 [ V_33 ] ) ;
F_21 ( V_30 -> V_101 ) ;
}
static int F_172 ( struct V_132 * V_228 ,
unsigned long V_134 , void * V_135 )
{
struct V_30 * V_30 = F_106 ( V_228 , struct V_30 , V_229 ) ;
struct V_202 * V_203 = V_135 ;
int V_14 ;
if ( ! F_173 ( V_203 -> V_230 . V_231 , & V_232 ) )
return V_139 ;
switch ( V_134 ) {
case V_233 :
V_14 = F_163 ( V_30 , V_203 ) ;
if ( V_14 )
F_167 ( V_30 ) ;
break;
case V_234 :
F_164 ( V_30 , V_203 ) ;
break;
case V_235 :
case V_236 :
F_167 ( V_30 ) ;
break;
}
return V_139 ;
}
int F_174 ( struct V_30 * V_30 )
{
int V_14 ;
F_27 ( & V_30 -> V_35 . V_171 ) ;
F_27 ( & V_30 -> V_35 . V_179 ) ;
V_14 = F_168 ( V_30 ) ;
if ( V_14 )
return V_14 ;
F_44 ( V_30 ) ;
V_14 = F_59 ( V_30 ) ;
if ( V_14 )
goto V_237;
V_14 = F_118 ( V_30 ) ;
if ( V_14 )
goto V_238;
V_30 -> V_229 . V_239 = F_172 ;
F_175 ( & V_30 -> V_229 ) ;
return 0 ;
V_238:
F_61 ( V_30 ) ;
V_237:
F_171 ( V_30 ) ;
return V_14 ;
}
void F_176 ( struct V_30 * V_30 )
{
F_177 ( & V_30 -> V_229 ) ;
F_119 ( V_30 ) ;
F_61 ( V_30 ) ;
F_171 ( V_30 ) ;
}
