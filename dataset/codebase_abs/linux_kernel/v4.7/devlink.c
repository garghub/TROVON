static struct V_1 * F_1 ( const struct V_2 * V_2 )
{
return F_2 ( & V_2 -> V_3 ) ;
}
static void F_3 ( struct V_2 * V_2 , struct V_1 * V_1 )
{
F_4 ( & V_2 -> V_3 , V_1 ) ;
}
static struct V_2 * F_5 ( struct V_1 * V_1 ,
struct V_4 * * V_5 )
{
struct V_2 * V_2 ;
char * V_6 ;
char * V_7 ;
if ( ! V_5 [ V_8 ] || ! V_5 [ V_9 ] )
return F_6 ( - V_10 ) ;
V_6 = F_7 ( V_5 [ V_8 ] ) ;
V_7 = F_7 ( V_5 [ V_9 ] ) ;
F_8 (devlink, &devlink_list, list) {
if ( strcmp ( V_2 -> V_11 -> V_12 -> V_13 , V_6 ) == 0 &&
strcmp ( F_9 ( V_2 -> V_11 ) , V_7 ) == 0 &&
F_10 ( F_1 ( V_2 ) , V_1 ) )
return V_2 ;
}
return F_6 ( - V_14 ) ;
}
static struct V_2 * F_11 ( struct V_15 * V_16 )
{
return F_5 ( F_12 ( V_16 ) , V_16 -> V_5 ) ;
}
static struct V_17 * F_13 ( struct V_2 * V_2 ,
int V_18 )
{
struct V_17 * V_17 ;
F_8 (devlink_port, &devlink->port_list, list) {
if ( V_17 -> V_19 == V_18 )
return V_17 ;
}
return NULL ;
}
static bool F_14 ( struct V_2 * V_2 , int V_18 )
{
return F_13 ( V_2 , V_18 ) ;
}
static struct V_17 * F_15 ( struct V_2 * V_2 ,
struct V_4 * * V_5 )
{
if ( V_5 [ V_20 ] ) {
T_1 V_18 = F_16 ( V_5 [ V_20 ] ) ;
struct V_17 * V_17 ;
V_17 = F_13 ( V_2 , V_18 ) ;
if ( ! V_17 )
return F_6 ( - V_14 ) ;
return V_17 ;
}
return F_6 ( - V_10 ) ;
}
static struct V_17 * F_17 ( struct V_2 * V_2 ,
struct V_15 * V_16 )
{
return F_15 ( V_2 , V_16 -> V_5 ) ;
}
static T_2 F_18 ( struct V_21 * V_21 )
{
return V_21 -> V_22 + V_21 -> V_23 ;
}
static struct V_21 * F_19 ( struct V_2 * V_2 ,
unsigned int V_24 )
{
struct V_21 * V_21 ;
F_8 (devlink_sb, &devlink->sb_list, list) {
if ( V_21 -> V_19 == V_24 )
return V_21 ;
}
return NULL ;
}
static bool F_20 ( struct V_2 * V_2 ,
unsigned int V_24 )
{
return F_19 ( V_2 , V_24 ) ;
}
static struct V_21 * F_21 ( struct V_2 * V_2 ,
struct V_4 * * V_5 )
{
if ( V_5 [ V_25 ] ) {
T_1 V_24 = F_16 ( V_5 [ V_25 ] ) ;
struct V_21 * V_21 ;
V_21 = F_19 ( V_2 , V_24 ) ;
if ( ! V_21 )
return F_6 ( - V_14 ) ;
return V_21 ;
}
return F_6 ( - V_10 ) ;
}
static struct V_21 * F_22 ( struct V_2 * V_2 ,
struct V_15 * V_16 )
{
return F_21 ( V_2 , V_16 -> V_5 ) ;
}
static int F_23 ( struct V_21 * V_21 ,
struct V_4 * * V_5 ,
T_2 * V_26 )
{
T_2 V_27 ;
if ( ! V_5 [ V_28 ] )
return - V_10 ;
V_27 = F_24 ( V_5 [ V_28 ] ) ;
if ( V_27 >= F_18 ( V_21 ) )
return - V_10 ;
* V_26 = V_27 ;
return 0 ;
}
static int F_25 ( struct V_21 * V_21 ,
struct V_15 * V_16 ,
T_2 * V_26 )
{
return F_23 ( V_21 , V_16 -> V_5 ,
V_26 ) ;
}
static int
F_26 ( struct V_4 * * V_5 ,
enum V_29 * V_30 )
{
T_3 V_27 ;
if ( ! V_5 [ V_31 ] )
return - V_10 ;
V_27 = F_27 ( V_5 [ V_31 ] ) ;
if ( V_27 != V_32 &&
V_27 != V_33 )
return - V_10 ;
* V_30 = V_27 ;
return 0 ;
}
static int
F_28 ( struct V_15 * V_16 ,
enum V_29 * V_30 )
{
return F_26 ( V_16 -> V_5 , V_30 ) ;
}
static int
F_29 ( struct V_4 * * V_5 ,
enum V_34 * V_35 )
{
T_3 V_27 ;
if ( ! V_5 [ V_36 ] )
return - V_10 ;
V_27 = F_27 ( V_5 [ V_36 ] ) ;
if ( V_27 != V_37 &&
V_27 != V_38 )
return - V_10 ;
* V_35 = V_27 ;
return 0 ;
}
static int
F_30 ( struct V_15 * V_16 ,
enum V_34 * V_35 )
{
return F_29 ( V_16 -> V_5 , V_35 ) ;
}
static int
F_31 ( struct V_21 * V_21 ,
struct V_4 * * V_5 ,
enum V_29 V_39 ,
T_2 * V_40 )
{
T_2 V_27 ;
if ( ! V_5 [ V_41 ] )
return - V_10 ;
V_27 = F_24 ( V_5 [ V_41 ] ) ;
if ( V_39 == V_32 &&
V_27 >= V_21 -> V_42 )
return - V_10 ;
if ( V_39 == V_33 &&
V_27 >= V_21 -> V_43 )
return - V_10 ;
* V_40 = V_27 ;
return 0 ;
}
static int
F_32 ( struct V_21 * V_21 ,
struct V_15 * V_16 ,
enum V_29 V_39 ,
T_2 * V_40 )
{
return F_31 ( V_21 , V_16 -> V_5 ,
V_39 , V_40 ) ;
}
static int F_33 ( const struct V_44 * V_45 ,
struct V_46 * V_47 , struct V_15 * V_16 )
{
struct V_2 * V_2 ;
F_34 ( & V_48 ) ;
V_2 = F_11 ( V_16 ) ;
if ( F_35 ( V_2 ) ) {
F_36 ( & V_48 ) ;
return F_37 ( V_2 ) ;
}
if ( V_45 -> V_49 & V_50 ) {
V_16 -> V_51 [ 0 ] = V_2 ;
} else if ( V_45 -> V_49 & V_52 ) {
struct V_17 * V_17 ;
F_34 ( & V_53 ) ;
V_17 = F_17 ( V_2 , V_16 ) ;
if ( F_35 ( V_17 ) ) {
F_36 ( & V_53 ) ;
F_36 ( & V_48 ) ;
return F_37 ( V_17 ) ;
}
V_16 -> V_51 [ 0 ] = V_17 ;
}
if ( V_45 -> V_49 & V_54 ) {
F_34 ( & V_53 ) ;
}
if ( V_45 -> V_49 & V_55 ) {
struct V_21 * V_21 ;
V_21 = F_22 ( V_2 , V_16 ) ;
if ( F_35 ( V_21 ) ) {
if ( V_45 -> V_49 & V_52 )
F_36 ( & V_53 ) ;
F_36 ( & V_48 ) ;
return F_37 ( V_21 ) ;
}
V_16 -> V_51 [ 1 ] = V_21 ;
}
return 0 ;
}
static void F_38 ( const struct V_44 * V_45 ,
struct V_46 * V_47 , struct V_15 * V_16 )
{
if ( V_45 -> V_49 & V_52 ||
V_45 -> V_49 & V_54 )
F_36 ( & V_53 ) ;
F_36 ( & V_48 ) ;
}
static int F_39 ( struct V_46 * V_56 , struct V_2 * V_2 )
{
if ( F_40 ( V_56 , V_8 , V_2 -> V_11 -> V_12 -> V_13 ) )
return - V_57 ;
if ( F_40 ( V_56 , V_9 , F_9 ( V_2 -> V_11 ) ) )
return - V_57 ;
return 0 ;
}
static int F_41 ( struct V_46 * V_56 , struct V_2 * V_2 ,
enum V_58 V_59 , T_1 V_60 ,
T_1 V_61 , int V_62 )
{
void * V_63 ;
V_63 = F_42 ( V_56 , V_60 , V_61 , & V_64 , V_62 , V_59 ) ;
if ( ! V_63 )
return - V_57 ;
if ( F_39 ( V_56 , V_2 ) )
goto V_65;
F_43 ( V_56 , V_63 ) ;
return 0 ;
V_65:
F_44 ( V_56 , V_63 ) ;
return - V_57 ;
}
static void F_45 ( struct V_2 * V_2 , enum V_58 V_59 )
{
struct V_46 * V_56 ;
int V_66 ;
F_46 ( V_59 != V_67 && V_59 != V_68 ) ;
V_56 = F_47 ( V_69 , V_70 ) ;
if ( ! V_56 )
return;
V_66 = F_41 ( V_56 , V_2 , V_59 , 0 , 0 , 0 ) ;
if ( V_66 ) {
F_48 ( V_56 ) ;
return;
}
F_49 ( & V_64 , F_1 ( V_2 ) ,
V_56 , 0 , V_71 , V_70 ) ;
}
static int F_50 ( struct V_46 * V_56 , struct V_2 * V_2 ,
struct V_17 * V_17 ,
enum V_58 V_59 , T_1 V_60 ,
T_1 V_61 , int V_62 )
{
void * V_63 ;
V_63 = F_42 ( V_56 , V_60 , V_61 , & V_64 , V_62 , V_59 ) ;
if ( ! V_63 )
return - V_57 ;
if ( F_39 ( V_56 , V_2 ) )
goto V_65;
if ( F_51 ( V_56 , V_20 , V_17 -> V_19 ) )
goto V_65;
if ( F_52 ( V_56 , V_72 , V_17 -> type ) )
goto V_65;
if ( V_17 -> V_73 != V_74 &&
F_52 ( V_56 , V_75 ,
V_17 -> V_73 ) )
goto V_65;
if ( V_17 -> type == V_76 ) {
struct V_77 * V_78 = V_17 -> V_79 ;
if ( V_78 &&
( F_51 ( V_56 , V_80 ,
V_78 -> V_81 ) ||
F_40 ( V_56 , V_82 ,
V_78 -> V_13 ) ) )
goto V_65;
}
if ( V_17 -> type == V_83 ) {
struct V_84 * V_85 = V_17 -> V_79 ;
if ( V_85 &&
F_40 ( V_56 , V_86 ,
V_85 -> V_13 ) )
goto V_65;
}
if ( V_17 -> V_87 &&
F_51 ( V_56 , V_88 ,
V_17 -> V_89 ) )
goto V_65;
F_43 ( V_56 , V_63 ) ;
return 0 ;
V_65:
F_44 ( V_56 , V_63 ) ;
return - V_57 ;
}
static void F_53 ( struct V_17 * V_17 ,
enum V_58 V_59 )
{
struct V_2 * V_2 = V_17 -> V_2 ;
struct V_46 * V_56 ;
int V_66 ;
if ( ! V_17 -> V_90 )
return;
F_46 ( V_59 != V_91 && V_59 != V_92 ) ;
V_56 = F_47 ( V_69 , V_70 ) ;
if ( ! V_56 )
return;
V_66 = F_50 ( V_56 , V_2 , V_17 , V_59 , 0 , 0 , 0 ) ;
if ( V_66 ) {
F_48 ( V_56 ) ;
return;
}
F_49 ( & V_64 , F_1 ( V_2 ) ,
V_56 , 0 , V_71 , V_70 ) ;
}
static int F_54 ( struct V_46 * V_47 , struct V_15 * V_16 )
{
struct V_2 * V_2 = V_16 -> V_51 [ 0 ] ;
struct V_46 * V_56 ;
int V_66 ;
V_56 = F_47 ( V_69 , V_70 ) ;
if ( ! V_56 )
return - V_93 ;
V_66 = F_41 ( V_56 , V_2 , V_67 ,
V_16 -> V_94 , V_16 -> V_95 , 0 ) ;
if ( V_66 ) {
F_48 ( V_56 ) ;
return V_66 ;
}
return F_55 ( V_56 , V_16 ) ;
}
static int F_56 ( struct V_46 * V_56 ,
struct V_96 * V_97 )
{
struct V_2 * V_2 ;
int V_98 = V_97 -> args [ 0 ] ;
int V_99 = 0 ;
int V_66 ;
F_34 ( & V_48 ) ;
F_8 (devlink, &devlink_list, list) {
if ( ! F_10 ( F_1 ( V_2 ) , F_57 ( V_56 -> V_100 ) ) )
continue;
if ( V_99 < V_98 ) {
V_99 ++ ;
continue;
}
V_66 = F_41 ( V_56 , V_2 , V_67 ,
F_58 ( V_97 -> V_47 ) . V_60 ,
V_97 -> V_101 -> V_102 , V_103 ) ;
if ( V_66 )
goto V_104;
V_99 ++ ;
}
V_104:
F_36 ( & V_48 ) ;
V_97 -> args [ 0 ] = V_99 ;
return V_56 -> V_105 ;
}
static int F_59 ( struct V_46 * V_47 ,
struct V_15 * V_16 )
{
struct V_17 * V_17 = V_16 -> V_51 [ 0 ] ;
struct V_2 * V_2 = V_17 -> V_2 ;
struct V_46 * V_56 ;
int V_66 ;
V_56 = F_47 ( V_69 , V_70 ) ;
if ( ! V_56 )
return - V_93 ;
V_66 = F_50 ( V_56 , V_2 , V_17 ,
V_91 ,
V_16 -> V_94 , V_16 -> V_95 , 0 ) ;
if ( V_66 ) {
F_48 ( V_56 ) ;
return V_66 ;
}
return F_55 ( V_56 , V_16 ) ;
}
static int F_60 ( struct V_46 * V_56 ,
struct V_96 * V_97 )
{
struct V_2 * V_2 ;
struct V_17 * V_17 ;
int V_98 = V_97 -> args [ 0 ] ;
int V_99 = 0 ;
int V_66 ;
F_34 ( & V_48 ) ;
F_34 ( & V_53 ) ;
F_8 (devlink, &devlink_list, list) {
if ( ! F_10 ( F_1 ( V_2 ) , F_57 ( V_56 -> V_100 ) ) )
continue;
F_8 (devlink_port, &devlink->port_list, list) {
if ( V_99 < V_98 ) {
V_99 ++ ;
continue;
}
V_66 = F_50 ( V_56 , V_2 , V_17 ,
V_67 ,
F_58 ( V_97 -> V_47 ) . V_60 ,
V_97 -> V_101 -> V_102 ,
V_103 ) ;
if ( V_66 )
goto V_104;
V_99 ++ ;
}
}
V_104:
F_36 ( & V_53 ) ;
F_36 ( & V_48 ) ;
V_97 -> args [ 0 ] = V_99 ;
return V_56 -> V_105 ;
}
static int F_61 ( struct V_2 * V_2 ,
struct V_17 * V_17 ,
enum V_106 V_107 )
{
int V_66 ;
if ( V_2 -> V_45 && V_2 -> V_45 -> V_108 ) {
if ( V_107 == V_74 )
return - V_10 ;
V_66 = V_2 -> V_45 -> V_108 ( V_17 , V_107 ) ;
if ( V_66 )
return V_66 ;
V_17 -> V_73 = V_107 ;
F_53 ( V_17 , V_91 ) ;
return 0 ;
}
return - V_109 ;
}
static int F_62 ( struct V_46 * V_47 ,
struct V_15 * V_16 )
{
struct V_17 * V_17 = V_16 -> V_51 [ 0 ] ;
struct V_2 * V_2 = V_17 -> V_2 ;
int V_66 ;
if ( V_16 -> V_5 [ V_72 ] ) {
enum V_106 V_107 ;
V_107 = F_24 ( V_16 -> V_5 [ V_72 ] ) ;
V_66 = F_61 ( V_2 , V_17 , V_107 ) ;
if ( V_66 )
return V_66 ;
}
return 0 ;
}
static int F_63 ( struct V_2 * V_2 ,
T_1 V_18 , T_1 V_110 )
{
if ( V_2 -> V_45 && V_2 -> V_45 -> V_111 )
return V_2 -> V_45 -> V_111 ( V_2 , V_18 , V_110 ) ;
return - V_109 ;
}
static int F_64 ( struct V_46 * V_47 ,
struct V_15 * V_16 )
{
struct V_2 * V_2 = V_16 -> V_51 [ 0 ] ;
T_1 V_18 ;
T_1 V_110 ;
if ( ! V_16 -> V_5 [ V_20 ] ||
! V_16 -> V_5 [ V_112 ] )
return - V_10 ;
V_18 = F_16 ( V_16 -> V_5 [ V_20 ] ) ;
V_110 = F_16 ( V_16 -> V_5 [ V_112 ] ) ;
return F_63 ( V_2 , V_18 , V_110 ) ;
}
static int F_65 ( struct V_2 * V_2 , T_1 V_18 )
{
if ( V_2 -> V_45 && V_2 -> V_45 -> V_113 )
return V_2 -> V_45 -> V_113 ( V_2 , V_18 ) ;
return - V_109 ;
}
static int F_66 ( struct V_46 * V_47 ,
struct V_15 * V_16 )
{
struct V_2 * V_2 = V_16 -> V_51 [ 0 ] ;
T_1 V_18 ;
if ( ! V_16 -> V_5 [ V_20 ] )
return - V_10 ;
V_18 = F_16 ( V_16 -> V_5 [ V_20 ] ) ;
return F_65 ( V_2 , V_18 ) ;
}
static int F_67 ( struct V_46 * V_56 , struct V_2 * V_2 ,
struct V_21 * V_21 ,
enum V_58 V_59 , T_1 V_60 ,
T_1 V_61 , int V_62 )
{
void * V_63 ;
V_63 = F_42 ( V_56 , V_60 , V_61 , & V_64 , V_62 , V_59 ) ;
if ( ! V_63 )
return - V_57 ;
if ( F_39 ( V_56 , V_2 ) )
goto V_65;
if ( F_51 ( V_56 , V_25 , V_21 -> V_19 ) )
goto V_65;
if ( F_51 ( V_56 , V_114 , V_21 -> V_115 ) )
goto V_65;
if ( F_52 ( V_56 , V_116 ,
V_21 -> V_22 ) )
goto V_65;
if ( F_52 ( V_56 , V_117 ,
V_21 -> V_23 ) )
goto V_65;
if ( F_52 ( V_56 , V_118 ,
V_21 -> V_42 ) )
goto V_65;
if ( F_52 ( V_56 , V_119 ,
V_21 -> V_43 ) )
goto V_65;
F_43 ( V_56 , V_63 ) ;
return 0 ;
V_65:
F_44 ( V_56 , V_63 ) ;
return - V_57 ;
}
static int F_68 ( struct V_46 * V_47 ,
struct V_15 * V_16 )
{
struct V_2 * V_2 = V_16 -> V_51 [ 0 ] ;
struct V_21 * V_21 = V_16 -> V_51 [ 1 ] ;
struct V_46 * V_56 ;
int V_66 ;
V_56 = F_47 ( V_69 , V_70 ) ;
if ( ! V_56 )
return - V_93 ;
V_66 = F_67 ( V_56 , V_2 , V_21 ,
V_120 ,
V_16 -> V_94 , V_16 -> V_95 , 0 ) ;
if ( V_66 ) {
F_48 ( V_56 ) ;
return V_66 ;
}
return F_55 ( V_56 , V_16 ) ;
}
static int F_69 ( struct V_46 * V_56 ,
struct V_96 * V_97 )
{
struct V_2 * V_2 ;
struct V_21 * V_21 ;
int V_98 = V_97 -> args [ 0 ] ;
int V_99 = 0 ;
int V_66 ;
F_34 ( & V_48 ) ;
F_8 (devlink, &devlink_list, list) {
if ( ! F_10 ( F_1 ( V_2 ) , F_57 ( V_56 -> V_100 ) ) )
continue;
F_8 (devlink_sb, &devlink->sb_list, list) {
if ( V_99 < V_98 ) {
V_99 ++ ;
continue;
}
V_66 = F_67 ( V_56 , V_2 , V_21 ,
V_120 ,
F_58 ( V_97 -> V_47 ) . V_60 ,
V_97 -> V_101 -> V_102 ,
V_103 ) ;
if ( V_66 )
goto V_104;
V_99 ++ ;
}
}
V_104:
F_36 ( & V_48 ) ;
V_97 -> args [ 0 ] = V_99 ;
return V_56 -> V_105 ;
}
static int F_70 ( struct V_46 * V_56 , struct V_2 * V_2 ,
struct V_21 * V_21 ,
T_2 V_121 , enum V_58 V_59 ,
T_1 V_60 , T_1 V_61 , int V_62 )
{
struct V_122 V_123 ;
void * V_63 ;
int V_66 ;
V_66 = V_2 -> V_45 -> V_124 ( V_2 , V_21 -> V_19 ,
V_121 , & V_123 ) ;
if ( V_66 )
return V_66 ;
V_63 = F_42 ( V_56 , V_60 , V_61 , & V_64 , V_62 , V_59 ) ;
if ( ! V_63 )
return - V_57 ;
if ( F_39 ( V_56 , V_2 ) )
goto V_65;
if ( F_51 ( V_56 , V_25 , V_21 -> V_19 ) )
goto V_65;
if ( F_52 ( V_56 , V_28 , V_121 ) )
goto V_65;
if ( F_71 ( V_56 , V_31 , V_123 . V_39 ) )
goto V_65;
if ( F_51 ( V_56 , V_125 , V_123 . V_115 ) )
goto V_65;
if ( F_71 ( V_56 , V_36 ,
V_123 . V_126 ) )
goto V_65;
F_43 ( V_56 , V_63 ) ;
return 0 ;
V_65:
F_44 ( V_56 , V_63 ) ;
return - V_57 ;
}
static int F_72 ( struct V_46 * V_47 ,
struct V_15 * V_16 )
{
struct V_2 * V_2 = V_16 -> V_51 [ 0 ] ;
struct V_21 * V_21 = V_16 -> V_51 [ 1 ] ;
struct V_46 * V_56 ;
T_2 V_121 ;
int V_66 ;
V_66 = F_25 ( V_21 , V_16 ,
& V_121 ) ;
if ( V_66 )
return V_66 ;
if ( ! V_2 -> V_45 || ! V_2 -> V_45 -> V_124 )
return - V_109 ;
V_56 = F_47 ( V_69 , V_70 ) ;
if ( ! V_56 )
return - V_93 ;
V_66 = F_70 ( V_56 , V_2 , V_21 , V_121 ,
V_127 ,
V_16 -> V_94 , V_16 -> V_95 , 0 ) ;
if ( V_66 ) {
F_48 ( V_56 ) ;
return V_66 ;
}
return F_55 ( V_56 , V_16 ) ;
}
static int F_73 ( struct V_46 * V_56 , int V_98 , int * V_128 ,
struct V_2 * V_2 ,
struct V_21 * V_21 ,
T_1 V_60 , T_1 V_61 )
{
T_2 V_129 = F_18 ( V_21 ) ;
T_2 V_121 ;
int V_66 ;
for ( V_121 = 0 ; V_121 < V_129 ; V_121 ++ ) {
if ( * V_128 < V_98 ) {
( * V_128 ) ++ ;
continue;
}
V_66 = F_70 ( V_56 , V_2 ,
V_21 ,
V_121 ,
V_127 ,
V_60 , V_61 , V_103 ) ;
if ( V_66 )
return V_66 ;
( * V_128 ) ++ ;
}
return 0 ;
}
static int F_74 ( struct V_46 * V_56 ,
struct V_96 * V_97 )
{
struct V_2 * V_2 ;
struct V_21 * V_21 ;
int V_98 = V_97 -> args [ 0 ] ;
int V_99 = 0 ;
int V_66 ;
F_34 ( & V_48 ) ;
F_8 (devlink, &devlink_list, list) {
if ( ! F_10 ( F_1 ( V_2 ) , F_57 ( V_56 -> V_100 ) ) ||
! V_2 -> V_45 || ! V_2 -> V_45 -> V_124 )
continue;
F_8 (devlink_sb, &devlink->sb_list, list) {
V_66 = F_73 ( V_56 , V_98 , & V_99 , V_2 ,
V_21 ,
F_58 ( V_97 -> V_47 ) . V_60 ,
V_97 -> V_101 -> V_102 ) ;
if ( V_66 && V_66 != - V_109 )
goto V_104;
}
}
V_104:
F_36 ( & V_48 ) ;
V_97 -> args [ 0 ] = V_99 ;
return V_56 -> V_105 ;
}
static int F_75 ( struct V_2 * V_2 , unsigned int V_24 ,
T_2 V_121 , T_1 V_115 ,
enum V_34 V_126 )
{
const struct V_130 * V_45 = V_2 -> V_45 ;
if ( V_45 && V_45 -> V_131 )
return V_45 -> V_131 ( V_2 , V_24 , V_121 ,
V_115 , V_126 ) ;
return - V_109 ;
}
static int F_76 ( struct V_46 * V_47 ,
struct V_15 * V_16 )
{
struct V_2 * V_2 = V_16 -> V_51 [ 0 ] ;
struct V_21 * V_21 = V_16 -> V_51 [ 1 ] ;
enum V_34 V_126 ;
T_2 V_121 ;
T_1 V_115 ;
int V_66 ;
V_66 = F_25 ( V_21 , V_16 ,
& V_121 ) ;
if ( V_66 )
return V_66 ;
V_66 = F_30 ( V_16 , & V_126 ) ;
if ( V_66 )
return V_66 ;
if ( ! V_16 -> V_5 [ V_125 ] )
return - V_10 ;
V_115 = F_16 ( V_16 -> V_5 [ V_125 ] ) ;
return F_75 ( V_2 , V_21 -> V_19 ,
V_121 , V_115 , V_126 ) ;
}
static int F_77 ( struct V_46 * V_56 ,
struct V_2 * V_2 ,
struct V_17 * V_17 ,
struct V_21 * V_21 ,
T_2 V_121 ,
enum V_58 V_59 ,
T_1 V_60 , T_1 V_61 , int V_62 )
{
const struct V_130 * V_45 = V_2 -> V_45 ;
T_1 V_132 ;
void * V_63 ;
int V_66 ;
V_66 = V_45 -> V_133 ( V_17 , V_21 -> V_19 ,
V_121 , & V_132 ) ;
if ( V_66 )
return V_66 ;
V_63 = F_42 ( V_56 , V_60 , V_61 , & V_64 , V_62 , V_59 ) ;
if ( ! V_63 )
return - V_57 ;
if ( F_39 ( V_56 , V_2 ) )
goto V_65;
if ( F_51 ( V_56 , V_20 , V_17 -> V_19 ) )
goto V_65;
if ( F_51 ( V_56 , V_25 , V_21 -> V_19 ) )
goto V_65;
if ( F_52 ( V_56 , V_28 , V_121 ) )
goto V_65;
if ( F_51 ( V_56 , V_134 , V_132 ) )
goto V_65;
if ( V_45 -> V_135 ) {
T_1 V_136 ;
T_1 V_137 ;
V_66 = V_45 -> V_135 ( V_17 , V_21 -> V_19 ,
V_121 , & V_136 , & V_137 ) ;
if ( V_66 && V_66 != - V_109 )
return V_66 ;
if ( ! V_66 ) {
if ( F_51 ( V_56 , V_138 , V_136 ) )
goto V_65;
if ( F_51 ( V_56 , V_139 , V_137 ) )
goto V_65;
}
}
F_43 ( V_56 , V_63 ) ;
return 0 ;
V_65:
F_44 ( V_56 , V_63 ) ;
return - V_57 ;
}
static int F_78 ( struct V_46 * V_47 ,
struct V_15 * V_16 )
{
struct V_17 * V_17 = V_16 -> V_51 [ 0 ] ;
struct V_2 * V_2 = V_17 -> V_2 ;
struct V_21 * V_21 = V_16 -> V_51 [ 1 ] ;
struct V_46 * V_56 ;
T_2 V_121 ;
int V_66 ;
V_66 = F_25 ( V_21 , V_16 ,
& V_121 ) ;
if ( V_66 )
return V_66 ;
if ( ! V_2 -> V_45 || ! V_2 -> V_45 -> V_133 )
return - V_109 ;
V_56 = F_47 ( V_69 , V_70 ) ;
if ( ! V_56 )
return - V_93 ;
V_66 = F_77 ( V_56 , V_2 , V_17 ,
V_21 , V_121 ,
V_140 ,
V_16 -> V_94 , V_16 -> V_95 , 0 ) ;
if ( V_66 ) {
F_48 ( V_56 ) ;
return V_66 ;
}
return F_55 ( V_56 , V_16 ) ;
}
static int F_79 ( struct V_46 * V_56 , int V_98 , int * V_128 ,
struct V_2 * V_2 ,
struct V_21 * V_21 ,
T_1 V_60 , T_1 V_61 )
{
struct V_17 * V_17 ;
T_2 V_129 = F_18 ( V_21 ) ;
T_2 V_121 ;
int V_66 ;
F_8 (devlink_port, &devlink->port_list, list) {
for ( V_121 = 0 ; V_121 < V_129 ; V_121 ++ ) {
if ( * V_128 < V_98 ) {
( * V_128 ) ++ ;
continue;
}
V_66 = F_77 ( V_56 , V_2 ,
V_17 ,
V_21 ,
V_121 ,
V_140 ,
V_60 , V_61 ,
V_103 ) ;
if ( V_66 )
return V_66 ;
( * V_128 ) ++ ;
}
}
return 0 ;
}
static int F_80 ( struct V_46 * V_56 ,
struct V_96 * V_97 )
{
struct V_2 * V_2 ;
struct V_21 * V_21 ;
int V_98 = V_97 -> args [ 0 ] ;
int V_99 = 0 ;
int V_66 ;
F_34 ( & V_48 ) ;
F_34 ( & V_53 ) ;
F_8 (devlink, &devlink_list, list) {
if ( ! F_10 ( F_1 ( V_2 ) , F_57 ( V_56 -> V_100 ) ) ||
! V_2 -> V_45 || ! V_2 -> V_45 -> V_133 )
continue;
F_8 (devlink_sb, &devlink->sb_list, list) {
V_66 = F_79 ( V_56 , V_98 , & V_99 ,
V_2 , V_21 ,
F_58 ( V_97 -> V_47 ) . V_60 ,
V_97 -> V_101 -> V_102 ) ;
if ( V_66 && V_66 != - V_109 )
goto V_104;
}
}
V_104:
F_36 ( & V_53 ) ;
F_36 ( & V_48 ) ;
V_97 -> args [ 0 ] = V_99 ;
return V_56 -> V_105 ;
}
static int F_81 ( struct V_17 * V_17 ,
unsigned int V_24 , T_2 V_121 ,
T_1 V_132 )
{
const struct V_130 * V_45 = V_17 -> V_2 -> V_45 ;
if ( V_45 && V_45 -> V_141 )
return V_45 -> V_141 ( V_17 , V_24 ,
V_121 , V_132 ) ;
return - V_109 ;
}
static int F_82 ( struct V_46 * V_47 ,
struct V_15 * V_16 )
{
struct V_17 * V_17 = V_16 -> V_51 [ 0 ] ;
struct V_21 * V_21 = V_16 -> V_51 [ 1 ] ;
T_2 V_121 ;
T_1 V_132 ;
int V_66 ;
V_66 = F_25 ( V_21 , V_16 ,
& V_121 ) ;
if ( V_66 )
return V_66 ;
if ( ! V_16 -> V_5 [ V_134 ] )
return - V_10 ;
V_132 = F_16 ( V_16 -> V_5 [ V_134 ] ) ;
return F_81 ( V_17 , V_21 -> V_19 ,
V_121 , V_132 ) ;
}
static int
F_83 ( struct V_46 * V_56 , struct V_2 * V_2 ,
struct V_17 * V_17 ,
struct V_21 * V_21 , T_2 V_142 ,
enum V_29 V_39 ,
enum V_58 V_59 ,
T_1 V_60 , T_1 V_61 , int V_62 )
{
const struct V_130 * V_45 = V_2 -> V_45 ;
T_2 V_121 ;
T_1 V_132 ;
void * V_63 ;
int V_66 ;
V_66 = V_45 -> V_143 ( V_17 , V_21 -> V_19 ,
V_142 , V_39 ,
& V_121 , & V_132 ) ;
if ( V_66 )
return V_66 ;
V_63 = F_42 ( V_56 , V_60 , V_61 , & V_64 , V_62 , V_59 ) ;
if ( ! V_63 )
return - V_57 ;
if ( F_39 ( V_56 , V_2 ) )
goto V_65;
if ( F_51 ( V_56 , V_20 , V_17 -> V_19 ) )
goto V_65;
if ( F_51 ( V_56 , V_25 , V_21 -> V_19 ) )
goto V_65;
if ( F_52 ( V_56 , V_41 , V_142 ) )
goto V_65;
if ( F_71 ( V_56 , V_31 , V_39 ) )
goto V_65;
if ( F_52 ( V_56 , V_28 , V_121 ) )
goto V_65;
if ( F_51 ( V_56 , V_134 , V_132 ) )
goto V_65;
if ( V_45 -> V_144 ) {
T_1 V_136 ;
T_1 V_137 ;
V_66 = V_45 -> V_144 ( V_17 ,
V_21 -> V_19 ,
V_142 , V_39 ,
& V_136 , & V_137 ) ;
if ( V_66 && V_66 != - V_109 )
return V_66 ;
if ( ! V_66 ) {
if ( F_51 ( V_56 , V_138 , V_136 ) )
goto V_65;
if ( F_51 ( V_56 , V_139 , V_137 ) )
goto V_65;
}
}
F_43 ( V_56 , V_63 ) ;
return 0 ;
V_65:
F_44 ( V_56 , V_63 ) ;
return - V_57 ;
}
static int F_84 ( struct V_46 * V_47 ,
struct V_15 * V_16 )
{
struct V_17 * V_17 = V_16 -> V_51 [ 0 ] ;
struct V_2 * V_2 = V_17 -> V_2 ;
struct V_21 * V_21 = V_16 -> V_51 [ 1 ] ;
struct V_46 * V_56 ;
enum V_29 V_39 ;
T_2 V_142 ;
int V_66 ;
V_66 = F_28 ( V_16 , & V_39 ) ;
if ( V_66 )
return V_66 ;
V_66 = F_32 ( V_21 , V_16 ,
V_39 , & V_142 ) ;
if ( V_66 )
return V_66 ;
if ( ! V_2 -> V_45 || ! V_2 -> V_45 -> V_143 )
return - V_109 ;
V_56 = F_47 ( V_69 , V_70 ) ;
if ( ! V_56 )
return - V_93 ;
V_66 = F_83 ( V_56 , V_2 , V_17 ,
V_21 , V_142 , V_39 ,
V_145 ,
V_16 -> V_94 ,
V_16 -> V_95 , 0 ) ;
if ( V_66 ) {
F_48 ( V_56 ) ;
return V_66 ;
}
return F_55 ( V_56 , V_16 ) ;
}
static int F_85 ( struct V_46 * V_56 ,
int V_98 , int * V_128 ,
struct V_2 * V_2 ,
struct V_21 * V_21 ,
T_1 V_60 , T_1 V_61 )
{
struct V_17 * V_17 ;
T_2 V_142 ;
int V_66 ;
F_8 (devlink_port, &devlink->port_list, list) {
for ( V_142 = 0 ;
V_142 < V_21 -> V_42 ; V_142 ++ ) {
if ( * V_128 < V_98 ) {
( * V_128 ) ++ ;
continue;
}
V_66 = F_83 ( V_56 , V_2 ,
V_17 ,
V_21 ,
V_142 ,
V_32 ,
V_145 ,
V_60 , V_61 ,
V_103 ) ;
if ( V_66 )
return V_66 ;
( * V_128 ) ++ ;
}
for ( V_142 = 0 ;
V_142 < V_21 -> V_43 ; V_142 ++ ) {
if ( * V_128 < V_98 ) {
( * V_128 ) ++ ;
continue;
}
V_66 = F_83 ( V_56 , V_2 ,
V_17 ,
V_21 ,
V_142 ,
V_33 ,
V_145 ,
V_60 , V_61 ,
V_103 ) ;
if ( V_66 )
return V_66 ;
( * V_128 ) ++ ;
}
}
return 0 ;
}
static int
F_86 ( struct V_46 * V_56 ,
struct V_96 * V_97 )
{
struct V_2 * V_2 ;
struct V_21 * V_21 ;
int V_98 = V_97 -> args [ 0 ] ;
int V_99 = 0 ;
int V_66 ;
F_34 ( & V_48 ) ;
F_34 ( & V_53 ) ;
F_8 (devlink, &devlink_list, list) {
if ( ! F_10 ( F_1 ( V_2 ) , F_57 ( V_56 -> V_100 ) ) ||
! V_2 -> V_45 || ! V_2 -> V_45 -> V_143 )
continue;
F_8 (devlink_sb, &devlink->sb_list, list) {
V_66 = F_85 ( V_56 , V_98 , & V_99 ,
V_2 ,
V_21 ,
F_58 ( V_97 -> V_47 ) . V_60 ,
V_97 -> V_101 -> V_102 ) ;
if ( V_66 && V_66 != - V_109 )
goto V_104;
}
}
V_104:
F_36 ( & V_53 ) ;
F_36 ( & V_48 ) ;
V_97 -> args [ 0 ] = V_99 ;
return V_56 -> V_105 ;
}
static int F_87 ( struct V_17 * V_17 ,
unsigned int V_24 , T_2 V_142 ,
enum V_29 V_39 ,
T_2 V_121 , T_1 V_132 )
{
const struct V_130 * V_45 = V_17 -> V_2 -> V_45 ;
if ( V_45 && V_45 -> V_146 )
return V_45 -> V_146 ( V_17 , V_24 ,
V_142 , V_39 ,
V_121 , V_132 ) ;
return - V_109 ;
}
static int F_88 ( struct V_46 * V_47 ,
struct V_15 * V_16 )
{
struct V_17 * V_17 = V_16 -> V_51 [ 0 ] ;
struct V_21 * V_21 = V_16 -> V_51 [ 1 ] ;
enum V_29 V_39 ;
T_2 V_142 ;
T_2 V_121 ;
T_1 V_132 ;
int V_66 ;
V_66 = F_28 ( V_16 , & V_39 ) ;
if ( V_66 )
return V_66 ;
V_66 = F_32 ( V_21 , V_16 ,
V_39 , & V_142 ) ;
if ( V_66 )
return V_66 ;
V_66 = F_25 ( V_21 , V_16 ,
& V_121 ) ;
if ( V_66 )
return V_66 ;
if ( ! V_16 -> V_5 [ V_134 ] )
return - V_10 ;
V_132 = F_16 ( V_16 -> V_5 [ V_134 ] ) ;
return F_87 ( V_17 , V_21 -> V_19 ,
V_142 , V_39 ,
V_121 , V_132 ) ;
}
static int F_89 ( struct V_46 * V_47 ,
struct V_15 * V_16 )
{
struct V_2 * V_2 = V_16 -> V_51 [ 0 ] ;
struct V_21 * V_21 = V_16 -> V_51 [ 1 ] ;
const struct V_130 * V_45 = V_2 -> V_45 ;
if ( V_45 && V_45 -> V_147 )
return V_45 -> V_147 ( V_2 , V_21 -> V_19 ) ;
return - V_109 ;
}
static int F_90 ( struct V_46 * V_47 ,
struct V_15 * V_16 )
{
struct V_2 * V_2 = V_16 -> V_51 [ 0 ] ;
struct V_21 * V_21 = V_16 -> V_51 [ 1 ] ;
const struct V_130 * V_45 = V_2 -> V_45 ;
if ( V_45 && V_45 -> V_148 )
return V_45 -> V_148 ( V_2 , V_21 -> V_19 ) ;
return - V_109 ;
}
struct V_2 * F_91 ( const struct V_130 * V_45 , T_4 V_149 )
{
struct V_2 * V_2 ;
V_2 = F_92 ( sizeof( * V_2 ) + V_149 , V_70 ) ;
if ( ! V_2 )
return NULL ;
V_2 -> V_45 = V_45 ;
F_3 ( V_2 , & V_150 ) ;
F_93 ( & V_2 -> V_151 ) ;
F_93 ( & V_2 -> V_152 ) ;
return V_2 ;
}
int F_94 ( struct V_2 * V_2 , struct V_153 * V_11 )
{
F_34 ( & V_48 ) ;
V_2 -> V_11 = V_11 ;
F_95 ( & V_2 -> V_154 , & V_155 ) ;
F_45 ( V_2 , V_67 ) ;
F_36 ( & V_48 ) ;
return 0 ;
}
void F_96 ( struct V_2 * V_2 )
{
F_34 ( & V_48 ) ;
F_45 ( V_2 , V_68 ) ;
F_97 ( & V_2 -> V_154 ) ;
F_36 ( & V_48 ) ;
}
void F_98 ( struct V_2 * V_2 )
{
F_99 ( V_2 ) ;
}
int F_100 ( struct V_2 * V_2 ,
struct V_17 * V_17 ,
unsigned int V_18 )
{
F_34 ( & V_53 ) ;
if ( F_14 ( V_2 , V_18 ) ) {
F_36 ( & V_53 ) ;
return - V_156 ;
}
V_17 -> V_2 = V_2 ;
V_17 -> V_19 = V_18 ;
V_17 -> V_90 = true ;
F_95 ( & V_17 -> V_154 , & V_2 -> V_151 ) ;
F_36 ( & V_53 ) ;
F_53 ( V_17 , V_91 ) ;
return 0 ;
}
void F_101 ( struct V_17 * V_17 )
{
F_53 ( V_17 , V_92 ) ;
F_34 ( & V_53 ) ;
F_97 ( & V_17 -> V_154 ) ;
F_36 ( & V_53 ) ;
}
static void F_102 ( struct V_17 * V_17 ,
enum V_106 type ,
void * V_79 )
{
V_17 -> type = type ;
V_17 -> V_79 = V_79 ;
F_53 ( V_17 , V_91 ) ;
}
void F_103 ( struct V_17 * V_17 ,
struct V_77 * V_78 )
{
return F_102 ( V_17 ,
V_76 , V_78 ) ;
}
void F_104 ( struct V_17 * V_17 ,
struct V_84 * V_85 )
{
return F_102 ( V_17 ,
V_83 , V_85 ) ;
}
void F_105 ( struct V_17 * V_17 )
{
return F_102 ( V_17 ,
V_74 , NULL ) ;
}
void F_106 ( struct V_17 * V_17 ,
T_1 V_89 )
{
V_17 -> V_87 = true ;
V_17 -> V_89 = V_89 ;
F_53 ( V_17 , V_91 ) ;
}
int F_107 ( struct V_2 * V_2 , unsigned int V_24 ,
T_1 V_115 , T_2 V_22 ,
T_2 V_23 , T_2 V_42 ,
T_2 V_43 )
{
struct V_21 * V_21 ;
int V_66 = 0 ;
F_34 ( & V_48 ) ;
if ( F_20 ( V_2 , V_24 ) ) {
V_66 = - V_156 ;
goto V_157;
}
V_21 = F_92 ( sizeof( * V_21 ) , V_70 ) ;
if ( ! V_21 ) {
V_66 = - V_93 ;
goto V_157;
}
V_21 -> V_19 = V_24 ;
V_21 -> V_115 = V_115 ;
V_21 -> V_22 = V_22 ;
V_21 -> V_23 = V_23 ;
V_21 -> V_42 = V_42 ;
V_21 -> V_43 = V_43 ;
F_95 ( & V_21 -> V_154 , & V_2 -> V_152 ) ;
V_157:
F_36 ( & V_48 ) ;
return V_66 ;
}
void F_108 ( struct V_2 * V_2 , unsigned int V_24 )
{
struct V_21 * V_21 ;
F_34 ( & V_48 ) ;
V_21 = F_19 ( V_2 , V_24 ) ;
F_46 ( ! V_21 ) ;
F_97 ( & V_21 -> V_154 ) ;
F_36 ( & V_48 ) ;
F_99 ( V_21 ) ;
}
static int T_5 F_109 ( void )
{
return F_110 ( & V_64 ,
V_158 ,
V_159 ) ;
}
static void T_6 F_111 ( void )
{
F_112 ( & V_64 ) ;
}
