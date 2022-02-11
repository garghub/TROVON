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
if ( V_107 == V_17 -> type )
return 0 ;
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
static int F_91 ( struct V_46 * V_56 , struct V_2 * V_2 ,
enum V_58 V_59 , T_1 V_60 ,
T_1 V_61 , int V_62 )
{
const struct V_130 * V_45 = V_2 -> V_45 ;
T_3 V_149 , V_150 ;
void * V_63 ;
int V_66 = 0 ;
T_2 V_151 ;
V_63 = F_42 ( V_56 , V_60 , V_61 , & V_64 , V_62 , V_59 ) ;
if ( ! V_63 )
return - V_57 ;
V_66 = F_39 ( V_56 , V_2 ) ;
if ( V_66 )
goto V_65;
if ( V_45 -> V_152 ) {
V_66 = V_45 -> V_152 ( V_2 , & V_151 ) ;
if ( V_66 )
goto V_65;
V_66 = F_52 ( V_56 , V_153 , V_151 ) ;
if ( V_66 )
goto V_65;
}
if ( V_45 -> V_154 ) {
V_66 = V_45 -> V_154 ( V_2 , & V_149 ) ;
if ( V_66 )
goto V_65;
V_66 = F_71 ( V_56 , V_155 ,
V_149 ) ;
if ( V_66 )
goto V_65;
}
if ( V_45 -> V_156 ) {
V_66 = V_45 -> V_156 ( V_2 , & V_150 ) ;
if ( V_66 )
goto V_65;
V_66 = F_71 ( V_56 , V_157 , V_150 ) ;
if ( V_66 )
goto V_65;
}
F_43 ( V_56 , V_63 ) ;
return 0 ;
V_65:
F_44 ( V_56 , V_63 ) ;
return V_66 ;
}
static int F_92 ( struct V_46 * V_47 ,
struct V_15 * V_16 )
{
struct V_2 * V_2 = V_16 -> V_51 [ 0 ] ;
const struct V_130 * V_45 = V_2 -> V_45 ;
struct V_46 * V_56 ;
int V_66 ;
if ( ! V_45 )
return - V_109 ;
V_56 = F_47 ( V_69 , V_70 ) ;
if ( ! V_56 )
return - V_93 ;
V_66 = F_91 ( V_56 , V_2 , V_158 ,
V_16 -> V_94 , V_16 -> V_95 , 0 ) ;
if ( V_66 ) {
F_48 ( V_56 ) ;
return V_66 ;
}
return F_55 ( V_56 , V_16 ) ;
}
static int F_93 ( struct V_46 * V_47 ,
struct V_15 * V_16 )
{
struct V_2 * V_2 = V_16 -> V_51 [ 0 ] ;
const struct V_130 * V_45 = V_2 -> V_45 ;
T_3 V_149 , V_150 ;
int V_66 = 0 ;
T_2 V_151 ;
if ( ! V_45 )
return - V_109 ;
if ( V_16 -> V_5 [ V_153 ] ) {
if ( ! V_45 -> V_159 )
return - V_109 ;
V_151 = F_24 ( V_16 -> V_5 [ V_153 ] ) ;
V_66 = V_45 -> V_159 ( V_2 , V_151 ) ;
if ( V_66 )
return V_66 ;
}
if ( V_16 -> V_5 [ V_155 ] ) {
if ( ! V_45 -> V_160 )
return - V_109 ;
V_149 = F_27 (
V_16 -> V_5 [ V_155 ] ) ;
V_66 = V_45 -> V_160 ( V_2 , V_149 ) ;
if ( V_66 )
return V_66 ;
}
if ( V_16 -> V_5 [ V_157 ] ) {
if ( ! V_45 -> V_161 )
return - V_109 ;
V_150 = F_27 ( V_16 -> V_5 [ V_157 ] ) ;
V_66 = V_45 -> V_161 ( V_2 , V_150 ) ;
if ( V_66 )
return V_66 ;
}
return 0 ;
}
int F_94 ( struct V_46 * V_47 ,
struct V_162 * V_163 )
{
struct V_164 * V_165 = V_163 -> V_165 ;
struct V_166 * V_167 = & V_165 -> V_168 [ V_163 -> V_169 ] ;
struct V_4 * V_170 ;
V_170 = F_95 ( V_47 , V_171 ) ;
if ( ! V_170 )
return - V_57 ;
if ( F_51 ( V_47 , V_172 , V_163 -> type ) ||
F_51 ( V_47 , V_173 , V_163 -> V_174 ) ||
F_51 ( V_47 , V_175 , V_165 -> V_176 ) ||
F_51 ( V_47 , V_177 , V_167 -> V_176 ) ||
F_71 ( V_47 , V_178 , V_165 -> V_179 ) )
goto V_65;
F_96 ( V_47 , V_170 ) ;
return 0 ;
V_65:
F_97 ( V_47 , V_170 ) ;
return - V_57 ;
}
static int F_98 ( struct V_180 * V_181 ,
struct V_46 * V_47 )
{
struct V_4 * V_182 ;
V_182 = F_95 ( V_47 , V_183 ) ;
if ( ! V_182 )
return - V_57 ;
if ( V_181 -> V_184 -> V_185 ( V_181 -> V_186 , V_47 ) )
goto V_65;
F_96 ( V_47 , V_182 ) ;
return 0 ;
V_65:
F_97 ( V_47 , V_182 ) ;
return - V_57 ;
}
int F_99 ( struct V_46 * V_47 ,
struct V_187 * V_188 )
{
struct V_164 * V_165 = V_188 -> V_165 ;
struct V_166 * V_167 = & V_165 -> V_168 [ V_188 -> V_169 ] ;
struct V_4 * V_189 ;
V_189 = F_95 ( V_47 , V_190 ) ;
if ( ! V_189 )
return - V_57 ;
if ( F_51 ( V_47 , V_191 , V_188 -> type ) ||
F_51 ( V_47 , V_173 , V_188 -> V_174 ) ||
F_51 ( V_47 , V_175 , V_165 -> V_176 ) ||
F_51 ( V_47 , V_177 , V_167 -> V_176 ) ||
F_71 ( V_47 , V_178 , V_165 -> V_179 ) )
goto V_65;
F_96 ( V_47 , V_189 ) ;
return 0 ;
V_65:
F_97 ( V_47 , V_189 ) ;
return - V_57 ;
}
static int F_100 ( struct V_180 * V_181 ,
struct V_46 * V_47 )
{
struct V_4 * V_192 ;
V_192 = F_95 ( V_47 , V_193 ) ;
if ( ! V_192 )
return - V_57 ;
if ( V_181 -> V_184 -> V_194 ( V_181 -> V_186 , V_47 ) )
goto V_65;
F_96 ( V_47 , V_192 ) ;
return 0 ;
V_65:
F_97 ( V_47 , V_192 ) ;
return - V_57 ;
}
static int F_101 ( struct V_46 * V_47 ,
struct V_180 * V_181 )
{
struct V_4 * V_195 ;
V_195 = F_95 ( V_47 , V_196 ) ;
if ( ! V_195 )
return - V_57 ;
if ( F_40 ( V_47 , V_197 , V_181 -> V_13 ) ||
F_102 ( V_47 , V_198 , V_181 -> V_115 ,
V_199 ) )
goto V_65;
if ( F_71 ( V_47 , V_200 ,
V_181 -> V_201 ) )
goto V_65;
if ( F_98 ( V_181 , V_47 ) )
goto V_65;
if ( F_100 ( V_181 , V_47 ) )
goto V_65;
F_96 ( V_47 , V_195 ) ;
return 0 ;
V_65:
F_97 ( V_47 , V_195 ) ;
return - V_57 ;
}
static int F_103 ( struct V_46 * * V_202 ,
struct V_15 * V_16 )
{
int V_66 ;
if ( * V_202 ) {
V_66 = F_55 ( * V_202 , V_16 ) ;
if ( V_66 )
return V_66 ;
}
* V_202 = F_104 ( V_203 , V_70 ) ;
if ( ! * V_202 )
return - V_93 ;
return 0 ;
}
static int F_105 ( struct V_15 * V_16 ,
enum V_58 V_59 , int V_62 ,
struct V_204 * V_205 ,
const char * V_206 )
{
struct V_2 * V_2 = V_16 -> V_51 [ 0 ] ;
struct V_180 * V_181 ;
struct V_4 * V_207 ;
struct V_46 * V_47 = NULL ;
struct V_208 * V_101 ;
bool V_209 ;
void * V_63 ;
int V_210 ;
int V_66 ;
V_181 = F_106 ( V_205 ,
struct V_180 , V_211 ) ;
V_212:
V_66 = F_103 ( & V_47 , V_16 ) ;
if ( V_66 )
return V_66 ;
V_63 = F_42 ( V_47 , V_16 -> V_94 , V_16 -> V_95 ,
& V_64 , V_103 , V_59 ) ;
if ( ! V_63 ) {
F_48 ( V_47 ) ;
return - V_57 ;
}
if ( F_39 ( V_47 , V_2 ) )
goto V_65;
V_207 = F_95 ( V_47 , V_213 ) ;
if ( ! V_207 )
goto V_65;
V_210 = 0 ;
V_209 = false ;
F_107 (table, dpipe_tables, list) {
if ( ! V_206 ) {
V_66 = F_101 ( V_47 , V_181 ) ;
if ( V_66 ) {
if ( ! V_210 )
goto V_214;
V_209 = true ;
break;
}
} else {
if ( ! strcmp ( V_181 -> V_13 , V_206 ) ) {
V_66 = F_101 ( V_47 , V_181 ) ;
if ( V_66 )
break;
}
}
V_210 ++ ;
}
F_96 ( V_47 , V_207 ) ;
F_43 ( V_47 , V_63 ) ;
if ( V_209 )
goto V_212;
V_215:
V_101 = F_108 ( V_47 , V_16 -> V_94 , V_16 -> V_95 ,
V_216 , 0 , V_62 | V_103 ) ;
if ( ! V_101 ) {
V_66 = F_103 ( & V_47 , V_16 ) ;
if ( V_66 )
goto V_217;
goto V_215;
}
return F_55 ( V_47 , V_16 ) ;
V_65:
V_66 = - V_57 ;
V_214:
V_217:
F_44 ( V_47 , V_63 ) ;
F_48 ( V_47 ) ;
return V_66 ;
}
static int F_109 ( struct V_46 * V_47 ,
struct V_15 * V_16 )
{
struct V_2 * V_2 = V_16 -> V_51 [ 0 ] ;
const char * V_206 = NULL ;
if ( V_16 -> V_5 [ V_197 ] )
V_206 = F_7 ( V_16 -> V_5 [ V_197 ] ) ;
return F_105 ( V_16 , V_218 , 0 ,
& V_2 -> V_219 ,
V_206 ) ;
}
static int F_110 ( struct V_46 * V_47 ,
struct V_220 * V_221 )
{
if ( F_111 ( V_47 , V_222 ,
V_221 -> V_223 , V_221 -> V_221 ) )
return - V_57 ;
if ( V_221 -> V_224 )
if ( F_111 ( V_47 , V_225 ,
V_221 -> V_223 , V_221 -> V_224 ) )
return - V_57 ;
if ( V_221 -> V_226 )
if ( F_51 ( V_47 , V_227 ,
V_221 -> V_228 ) )
return - V_57 ;
return 0 ;
}
static int F_112 ( struct V_46 * V_47 ,
struct V_220 * V_221 )
{
if ( ! V_221 -> V_188 )
return - V_10 ;
if ( F_99 ( V_47 , V_221 -> V_188 ) )
return - V_57 ;
if ( F_110 ( V_47 , V_221 ) )
return - V_57 ;
return 0 ;
}
static int F_113 ( struct V_46 * V_47 ,
struct V_220 * V_229 ,
unsigned int V_230 )
{
struct V_4 * V_189 ;
int V_210 ;
int V_66 ;
for ( V_210 = 0 ; V_210 < V_230 ; V_210 ++ ) {
V_189 = F_95 ( V_47 ,
V_231 ) ;
if ( ! V_189 )
return - V_57 ;
V_66 = F_112 ( V_47 , & V_229 [ V_210 ] ) ;
if ( V_66 )
goto V_232;
F_96 ( V_47 , V_189 ) ;
}
return 0 ;
V_232:
F_97 ( V_47 , V_189 ) ;
return V_66 ;
}
static int F_114 ( struct V_46 * V_47 ,
struct V_220 * V_221 )
{
if ( ! V_221 -> V_163 )
return - V_10 ;
if ( F_94 ( V_47 , V_221 -> V_163 ) )
return - V_57 ;
if ( F_110 ( V_47 , V_221 ) )
return - V_57 ;
return 0 ;
}
static int F_115 ( struct V_46 * V_47 ,
struct V_220 * V_229 ,
unsigned int V_230 )
{
struct V_4 * V_170 ;
int V_210 ;
int V_66 ;
for ( V_210 = 0 ; V_210 < V_230 ; V_210 ++ ) {
V_170 = F_95 ( V_47 ,
V_233 ) ;
if ( ! V_170 )
return - V_57 ;
V_66 = F_114 ( V_47 , & V_229 [ V_210 ] ) ;
if ( V_66 )
goto V_234;
F_96 ( V_47 , V_170 ) ;
}
return 0 ;
V_234:
F_97 ( V_47 , V_170 ) ;
return V_66 ;
}
static int F_116 ( struct V_46 * V_47 ,
struct V_235 * V_236 )
{
struct V_4 * V_237 , * V_182 , * V_192 ;
int V_66 ;
V_237 = F_95 ( V_47 , V_238 ) ;
if ( ! V_237 )
return - V_57 ;
if ( F_102 ( V_47 , V_239 , V_236 -> V_19 ,
V_199 ) )
goto V_65;
if ( V_236 -> V_240 )
if ( F_102 ( V_47 , V_241 ,
V_236 -> V_242 , V_199 ) )
goto V_65;
V_182 = F_95 ( V_47 ,
V_243 ) ;
if ( ! V_182 )
goto V_65;
V_66 = F_115 ( V_47 , V_236 -> V_244 ,
V_236 -> V_245 ) ;
if ( V_66 ) {
F_97 ( V_47 , V_182 ) ;
goto V_246;
}
F_96 ( V_47 , V_182 ) ;
V_192 = F_95 ( V_47 ,
V_247 ) ;
if ( ! V_192 )
goto V_65;
V_66 = F_113 ( V_47 , V_236 -> V_248 ,
V_236 -> V_249 ) ;
if ( V_66 ) {
F_97 ( V_47 , V_192 ) ;
goto V_250;
}
F_96 ( V_47 , V_192 ) ;
F_96 ( V_47 , V_237 ) ;
return 0 ;
V_65:
V_66 = - V_57 ;
V_246:
V_250:
F_97 ( V_47 , V_237 ) ;
return V_66 ;
}
static struct V_180 *
F_117 ( struct V_204 * V_205 ,
const char * V_206 )
{
struct V_180 * V_181 ;
F_118 (table, dpipe_tables, list) {
if ( ! strcmp ( V_181 -> V_13 , V_206 ) )
return V_181 ;
}
return NULL ;
}
int F_119 ( struct V_251 * V_252 )
{
struct V_2 * V_2 ;
int V_66 ;
V_66 = F_103 ( & V_252 -> V_47 ,
V_252 -> V_16 ) ;
if ( V_66 )
return V_66 ;
V_252 -> V_63 = F_42 ( V_252 -> V_47 ,
V_252 -> V_16 -> V_94 ,
V_252 -> V_16 -> V_95 ,
& V_64 , V_103 ,
V_252 -> V_59 ) ;
if ( ! V_252 -> V_63 )
goto V_65;
V_2 = V_252 -> V_16 -> V_51 [ 0 ] ;
if ( F_39 ( V_252 -> V_47 , V_2 ) )
goto V_65;
V_252 -> V_253 = F_95 ( V_252 -> V_47 ,
V_254 ) ;
if ( ! V_252 -> V_253 )
goto V_65;
return 0 ;
V_65:
F_44 ( V_252 -> V_47 , V_252 -> V_63 ) ;
F_48 ( V_252 -> V_47 ) ;
return - V_57 ;
}
int F_120 ( struct V_251 * V_252 ,
struct V_235 * V_236 )
{
return F_116 ( V_252 -> V_47 , V_236 ) ;
}
int F_121 ( struct V_251 * V_252 )
{
F_96 ( V_252 -> V_47 , V_252 -> V_253 ) ;
F_43 ( V_252 -> V_47 , V_252 -> V_63 ) ;
return 0 ;
}
static int F_122 ( struct V_15 * V_16 ,
enum V_58 V_59 , int V_62 ,
struct V_180 * V_181 )
{
struct V_251 V_252 ;
struct V_208 * V_101 ;
int V_66 ;
V_252 . V_47 = NULL ;
V_252 . V_59 = V_59 ;
V_252 . V_16 = V_16 ;
V_66 = V_181 -> V_184 -> V_255 ( V_181 -> V_186 ,
V_181 -> V_201 ,
& V_252 ) ;
if ( V_66 )
goto V_256;
V_215:
V_101 = F_108 ( V_252 . V_47 , V_16 -> V_94 , V_16 -> V_95 ,
V_216 , 0 , V_62 | V_103 ) ;
if ( ! V_101 ) {
V_66 = F_103 ( & V_252 . V_47 , V_16 ) ;
if ( V_66 )
goto V_217;
goto V_215;
}
return F_55 ( V_252 . V_47 , V_16 ) ;
V_256:
V_217:
F_44 ( V_252 . V_47 , V_252 . V_63 ) ;
F_48 ( V_252 . V_47 ) ;
return V_66 ;
}
static int F_123 ( struct V_46 * V_47 ,
struct V_15 * V_16 )
{
struct V_2 * V_2 = V_16 -> V_51 [ 0 ] ;
struct V_180 * V_181 ;
const char * V_206 ;
if ( ! V_16 -> V_5 [ V_197 ] )
return - V_10 ;
V_206 = F_7 ( V_16 -> V_5 [ V_197 ] ) ;
V_181 = F_117 ( & V_2 -> V_219 ,
V_206 ) ;
if ( ! V_181 )
return - V_10 ;
if ( ! V_181 -> V_184 -> V_255 )
return - V_10 ;
return F_122 ( V_16 , V_257 ,
0 , V_181 ) ;
}
static int F_124 ( struct V_46 * V_47 ,
const struct V_164 * V_165 )
{
struct V_166 * V_167 ;
struct V_4 * V_258 ;
int V_210 ;
for ( V_210 = 0 ; V_210 < V_165 -> V_259 ; V_210 ++ ) {
V_167 = & V_165 -> V_168 [ V_210 ] ;
V_258 = F_95 ( V_47 , V_260 ) ;
if ( ! V_258 )
return - V_57 ;
if ( F_40 ( V_47 , V_261 , V_167 -> V_13 ) ||
F_51 ( V_47 , V_177 , V_167 -> V_176 ) ||
F_51 ( V_47 , V_262 , V_167 -> V_263 ) ||
F_51 ( V_47 , V_264 , V_167 -> V_265 ) )
goto V_65;
F_96 ( V_47 , V_258 ) ;
}
return 0 ;
V_65:
F_97 ( V_47 , V_258 ) ;
return - V_57 ;
}
static int F_125 ( struct V_46 * V_47 ,
struct V_164 * V_165 )
{
struct V_4 * V_266 , * V_267 ;
int V_66 ;
V_267 = F_95 ( V_47 , V_268 ) ;
if ( ! V_267 )
return - V_57 ;
if ( F_40 ( V_47 , V_269 , V_165 -> V_13 ) ||
F_51 ( V_47 , V_175 , V_165 -> V_176 ) ||
F_71 ( V_47 , V_178 , V_165 -> V_179 ) )
goto V_65;
V_266 = F_95 ( V_47 , V_270 ) ;
if ( ! V_266 )
goto V_65;
V_66 = F_124 ( V_47 , V_165 ) ;
if ( V_66 ) {
F_97 ( V_47 , V_266 ) ;
goto V_65;
}
F_96 ( V_47 , V_266 ) ;
F_96 ( V_47 , V_267 ) ;
return 0 ;
V_65:
V_66 = - V_57 ;
F_97 ( V_47 , V_267 ) ;
return V_66 ;
}
static int F_126 ( struct V_15 * V_16 ,
enum V_58 V_59 , int V_62 ,
struct V_271 *
V_272 )
{
struct V_2 * V_2 = V_16 -> V_51 [ 0 ] ;
struct V_4 * V_273 ;
struct V_46 * V_47 = NULL ;
struct V_208 * V_101 ;
void * V_63 ;
int V_210 , V_274 ;
int V_66 ;
V_210 = 0 ;
V_212:
V_66 = F_103 ( & V_47 , V_16 ) ;
if ( V_66 )
return V_66 ;
V_63 = F_42 ( V_47 , V_16 -> V_94 , V_16 -> V_95 ,
& V_64 , V_103 , V_59 ) ;
if ( ! V_63 ) {
F_48 ( V_47 ) ;
return - V_57 ;
}
if ( F_39 ( V_47 , V_2 ) )
goto V_65;
V_273 = F_95 ( V_47 , V_275 ) ;
if ( ! V_273 )
goto V_65;
V_274 = 0 ;
for (; V_210 < V_272 -> V_276 ; V_210 ++ ) {
V_66 = F_125 ( V_47 , V_272 -> V_277 [ V_210 ] ) ;
if ( V_66 ) {
if ( ! V_274 )
goto V_214;
break;
}
V_274 ++ ;
}
F_96 ( V_47 , V_273 ) ;
F_43 ( V_47 , V_63 ) ;
if ( V_210 != V_272 -> V_276 )
goto V_212;
V_215:
V_101 = F_108 ( V_47 , V_16 -> V_94 , V_16 -> V_95 ,
V_216 , 0 , V_62 | V_103 ) ;
if ( ! V_101 ) {
V_66 = F_103 ( & V_47 , V_16 ) ;
if ( V_66 )
goto V_217;
goto V_215;
}
return F_55 ( V_47 , V_16 ) ;
V_65:
V_66 = - V_57 ;
V_214:
V_217:
F_44 ( V_47 , V_63 ) ;
F_48 ( V_47 ) ;
return V_66 ;
}
static int F_127 ( struct V_46 * V_47 ,
struct V_15 * V_16 )
{
struct V_2 * V_2 = V_16 -> V_51 [ 0 ] ;
if ( ! V_2 -> V_272 )
return - V_109 ;
return F_126 ( V_16 , V_278 ,
0 , V_2 -> V_272 ) ;
}
static int F_128 ( struct V_2 * V_2 ,
const char * V_206 ,
bool V_279 )
{
struct V_180 * V_181 ;
V_181 = F_117 ( & V_2 -> V_219 ,
V_206 ) ;
if ( ! V_181 )
return - V_10 ;
if ( V_181 -> V_280 )
return - V_109 ;
if ( ! ( V_181 -> V_201 ^ V_279 ) )
return 0 ;
V_181 -> V_201 = V_279 ;
if ( V_181 -> V_184 -> V_281 )
V_181 -> V_184 -> V_281 ( V_181 -> V_186 , V_279 ) ;
return 0 ;
}
static int F_129 ( struct V_46 * V_47 ,
struct V_15 * V_16 )
{
struct V_2 * V_2 = V_16 -> V_51 [ 0 ] ;
const char * V_206 ;
bool V_282 ;
if ( ! V_16 -> V_5 [ V_197 ] ||
! V_16 -> V_5 [ V_200 ] )
return - V_10 ;
V_206 = F_7 ( V_16 -> V_5 [ V_197 ] ) ;
V_282 = ! ! F_27 ( V_16 -> V_5 [ V_200 ] ) ;
return F_128 ( V_2 , V_206 ,
V_282 ) ;
}
struct V_2 * F_130 ( const struct V_130 * V_45 , T_4 V_283 )
{
struct V_2 * V_2 ;
V_2 = F_131 ( sizeof( * V_2 ) + V_283 , V_70 ) ;
if ( ! V_2 )
return NULL ;
V_2 -> V_45 = V_45 ;
F_3 ( V_2 , & V_284 ) ;
F_132 ( & V_2 -> V_285 ) ;
F_132 ( & V_2 -> V_286 ) ;
F_133 ( & V_2 -> V_219 ) ;
return V_2 ;
}
int F_134 ( struct V_2 * V_2 , struct V_287 * V_11 )
{
F_34 ( & V_48 ) ;
V_2 -> V_11 = V_11 ;
F_135 ( & V_2 -> V_211 , & V_288 ) ;
F_45 ( V_2 , V_67 ) ;
F_36 ( & V_48 ) ;
return 0 ;
}
void F_136 ( struct V_2 * V_2 )
{
F_34 ( & V_48 ) ;
F_45 ( V_2 , V_68 ) ;
F_137 ( & V_2 -> V_211 ) ;
F_36 ( & V_48 ) ;
}
void F_138 ( struct V_2 * V_2 )
{
F_139 ( V_2 ) ;
}
int F_140 ( struct V_2 * V_2 ,
struct V_17 * V_17 ,
unsigned int V_18 )
{
F_34 ( & V_53 ) ;
if ( F_14 ( V_2 , V_18 ) ) {
F_36 ( & V_53 ) ;
return - V_289 ;
}
V_17 -> V_2 = V_2 ;
V_17 -> V_19 = V_18 ;
V_17 -> V_90 = true ;
F_135 ( & V_17 -> V_211 , & V_2 -> V_285 ) ;
F_36 ( & V_53 ) ;
F_53 ( V_17 , V_91 ) ;
return 0 ;
}
void F_141 ( struct V_17 * V_17 )
{
F_53 ( V_17 , V_92 ) ;
F_34 ( & V_53 ) ;
F_137 ( & V_17 -> V_211 ) ;
F_36 ( & V_53 ) ;
}
static void F_142 ( struct V_17 * V_17 ,
enum V_106 type ,
void * V_79 )
{
V_17 -> type = type ;
V_17 -> V_79 = V_79 ;
F_53 ( V_17 , V_91 ) ;
}
void F_143 ( struct V_17 * V_17 ,
struct V_77 * V_78 )
{
return F_142 ( V_17 ,
V_76 , V_78 ) ;
}
void F_144 ( struct V_17 * V_17 ,
struct V_84 * V_85 )
{
return F_142 ( V_17 ,
V_83 , V_85 ) ;
}
void F_145 ( struct V_17 * V_17 )
{
return F_142 ( V_17 ,
V_74 , NULL ) ;
}
void F_146 ( struct V_17 * V_17 ,
T_1 V_89 )
{
V_17 -> V_87 = true ;
V_17 -> V_89 = V_89 ;
F_53 ( V_17 , V_91 ) ;
}
int F_147 ( struct V_2 * V_2 , unsigned int V_24 ,
T_1 V_115 , T_2 V_22 ,
T_2 V_23 , T_2 V_42 ,
T_2 V_43 )
{
struct V_21 * V_21 ;
int V_66 = 0 ;
F_34 ( & V_48 ) ;
if ( F_20 ( V_2 , V_24 ) ) {
V_66 = - V_289 ;
goto V_290;
}
V_21 = F_131 ( sizeof( * V_21 ) , V_70 ) ;
if ( ! V_21 ) {
V_66 = - V_93 ;
goto V_290;
}
V_21 -> V_19 = V_24 ;
V_21 -> V_115 = V_115 ;
V_21 -> V_22 = V_22 ;
V_21 -> V_23 = V_23 ;
V_21 -> V_42 = V_42 ;
V_21 -> V_43 = V_43 ;
F_135 ( & V_21 -> V_211 , & V_2 -> V_286 ) ;
V_290:
F_36 ( & V_48 ) ;
return V_66 ;
}
void F_148 ( struct V_2 * V_2 , unsigned int V_24 )
{
struct V_21 * V_21 ;
F_34 ( & V_48 ) ;
V_21 = F_19 ( V_2 , V_24 ) ;
F_46 ( ! V_21 ) ;
F_137 ( & V_21 -> V_211 ) ;
F_36 ( & V_48 ) ;
F_139 ( V_21 ) ;
}
int F_149 ( struct V_2 * V_2 ,
struct V_271 * V_272 )
{
F_34 ( & V_48 ) ;
V_2 -> V_272 = V_272 ;
F_36 ( & V_48 ) ;
return 0 ;
}
void F_150 ( struct V_2 * V_2 )
{
F_34 ( & V_48 ) ;
V_2 -> V_272 = NULL ;
F_36 ( & V_48 ) ;
}
bool F_151 ( struct V_2 * V_2 ,
const char * V_206 )
{
struct V_180 * V_181 ;
bool V_291 ;
F_152 () ;
V_181 = F_117 ( & V_2 -> V_219 ,
V_206 ) ;
V_291 = false ;
if ( V_181 )
V_291 = V_181 -> V_201 ;
F_153 () ;
return V_291 ;
}
int F_154 ( struct V_2 * V_2 ,
const char * V_206 ,
struct V_292 * V_184 ,
void * V_186 , T_5 V_115 ,
bool V_280 )
{
struct V_180 * V_181 ;
if ( F_117 ( & V_2 -> V_219 , V_206 ) )
return - V_289 ;
V_181 = F_131 ( sizeof( * V_181 ) , V_70 ) ;
if ( ! V_181 )
return - V_93 ;
V_181 -> V_13 = V_206 ;
V_181 -> V_184 = V_184 ;
V_181 -> V_186 = V_186 ;
V_181 -> V_115 = V_115 ;
V_181 -> V_280 = V_280 ;
F_34 ( & V_48 ) ;
F_155 ( & V_181 -> V_211 , & V_2 -> V_219 ) ;
F_36 ( & V_48 ) ;
return 0 ;
}
void F_156 ( struct V_2 * V_2 ,
const char * V_206 )
{
struct V_180 * V_181 ;
F_34 ( & V_48 ) ;
V_181 = F_117 ( & V_2 -> V_219 ,
V_206 ) ;
if ( ! V_181 )
goto V_290;
F_157 ( & V_181 -> V_211 ) ;
F_36 ( & V_48 ) ;
F_158 ( V_181 , V_293 ) ;
return;
V_290:
F_36 ( & V_48 ) ;
}
static int T_6 F_159 ( void )
{
return F_160 ( & V_64 ) ;
}
static void T_7 F_161 ( void )
{
F_162 ( & V_64 ) ;
}
