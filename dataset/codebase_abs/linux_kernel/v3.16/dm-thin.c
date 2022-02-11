static void F_1 ( struct V_1 * V_2 ,
T_1 V_3 , struct V_4 * V_5 )
{
V_5 -> V_6 = 0 ;
V_5 -> V_7 = F_2 ( V_2 ) ;
V_5 -> V_8 = V_3 ;
}
static void F_3 ( struct V_1 * V_2 , T_1 V_3 ,
struct V_4 * V_5 )
{
V_5 -> V_6 = 1 ;
V_5 -> V_7 = F_2 ( V_2 ) ;
V_5 -> V_8 = V_3 ;
}
static void F_4 ( struct V_9 * V_9 )
{
F_5 ( V_9 -> V_10 , & V_9 -> V_11 ) ;
}
static int F_6 ( struct V_9 * V_9 , struct V_4 * V_5 , struct V_12 * V_12 ,
struct V_13 * * V_14 )
{
int V_15 ;
struct V_13 * V_16 ;
V_16 = F_7 ( V_9 -> V_17 , V_18 ) ;
V_15 = F_8 ( V_9 -> V_17 , V_5 , V_12 , V_16 , V_14 ) ;
if ( V_15 )
F_9 ( V_9 -> V_17 , V_16 ) ;
return V_15 ;
}
static void F_10 ( struct V_9 * V_9 ,
struct V_13 * V_19 ,
struct V_20 * V_21 )
{
F_11 ( V_9 -> V_17 , V_19 , V_21 ) ;
F_9 ( V_9 -> V_17 , V_19 ) ;
}
static void F_12 ( struct V_9 * V_9 ,
struct V_13 * V_19 ,
struct V_20 * V_21 )
{
F_13 ( V_9 -> V_17 , V_19 , V_21 ) ;
F_9 ( V_9 -> V_17 , V_19 ) ;
}
static void F_14 ( struct V_22 * V_23 ,
struct V_13 * V_19 )
{
struct V_9 * V_9 = V_23 -> V_9 ;
unsigned long V_24 ;
F_15 ( & V_23 -> V_25 , V_24 ) ;
F_13 ( V_9 -> V_17 , V_19 , & V_23 -> V_26 ) ;
F_16 ( & V_23 -> V_25 , V_24 ) ;
F_4 ( V_9 ) ;
}
static void F_17 ( struct V_9 * V_9 ,
struct V_13 * V_19 , int V_27 )
{
F_18 ( V_9 -> V_17 , V_19 , V_27 ) ;
F_9 ( V_9 -> V_17 , V_19 ) ;
}
static void F_19 ( struct V_9 * V_9 , struct V_13 * V_19 )
{
F_17 ( V_9 , V_19 , - V_28 ) ;
}
static void F_20 ( void )
{
F_21 ( & V_29 . V_30 ) ;
F_22 ( & V_29 . V_31 ) ;
}
static void F_23 ( struct V_9 * V_9 )
{
F_24 ( ! F_25 ( & V_29 . V_30 ) ) ;
F_26 ( & V_9 -> V_32 , & V_29 . V_31 ) ;
}
static void F_27 ( struct V_9 * V_9 )
{
F_24 ( ! F_25 ( & V_29 . V_30 ) ) ;
F_28 ( & V_9 -> V_32 ) ;
}
static struct V_9 * F_29 ( struct V_33 * V_34 )
{
struct V_9 * V_9 = NULL , * V_35 ;
F_24 ( ! F_25 ( & V_29 . V_30 ) ) ;
F_30 (tmp, &dm_thin_pool_table.pools, list) {
if ( V_35 -> V_36 == V_34 ) {
V_9 = V_35 ;
break;
}
}
return V_9 ;
}
static struct V_9 * F_31 ( struct V_37 * V_38 )
{
struct V_9 * V_9 = NULL , * V_35 ;
F_24 ( ! F_25 ( & V_29 . V_30 ) ) ;
F_30 (tmp, &dm_thin_pool_table.pools, list) {
if ( V_35 -> V_38 == V_38 ) {
V_9 = V_35 ;
break;
}
}
return V_9 ;
}
static void F_32 ( struct V_22 * V_23 , struct V_20 * V_39 )
{
struct V_12 * V_12 ;
struct V_20 V_21 ;
unsigned long V_24 ;
F_33 ( & V_21 ) ;
F_15 ( & V_23 -> V_25 , V_24 ) ;
F_34 ( & V_21 , V_39 ) ;
F_33 ( V_39 ) ;
F_16 ( & V_23 -> V_25 , V_24 ) ;
while ( ( V_12 = F_35 ( & V_21 ) ) )
F_36 ( V_12 , V_40 ) ;
}
static void F_37 ( struct V_22 * V_23 )
{
F_32 ( V_23 , & V_23 -> V_26 ) ;
F_32 ( V_23 , & V_23 -> V_41 ) ;
}
static void F_38 ( struct V_22 * V_23 )
{
struct V_12 * V_12 ;
unsigned long V_24 ;
struct V_20 V_21 ;
F_33 ( & V_21 ) ;
F_15 ( & V_23 -> V_25 , V_24 ) ;
F_34 ( & V_21 , & V_23 -> V_41 ) ;
F_33 ( & V_23 -> V_41 ) ;
F_16 ( & V_23 -> V_25 , V_24 ) ;
while ( ( V_12 = F_35 ( & V_21 ) ) )
F_39 ( V_12 ) ;
}
static void F_40 ( struct V_9 * V_9 )
{
struct V_22 * V_23 ;
F_41 () ;
F_42 (tc, &pool->active_thins, list)
F_38 ( V_23 ) ;
F_43 () ;
}
static bool F_44 ( struct V_9 * V_9 )
{
return V_9 -> V_42 >= 0 ;
}
static T_1 F_45 ( struct V_22 * V_23 , struct V_12 * V_12 )
{
struct V_9 * V_9 = V_23 -> V_9 ;
T_2 V_43 = V_12 -> V_44 . V_45 ;
if ( F_44 ( V_9 ) )
V_43 >>= V_9 -> V_42 ;
else
( void ) F_46 ( V_43 , V_9 -> V_46 ) ;
return V_43 ;
}
static void F_47 ( struct V_22 * V_23 , struct V_12 * V_12 , T_1 V_8 )
{
struct V_9 * V_9 = V_23 -> V_9 ;
T_2 V_45 = V_12 -> V_44 . V_45 ;
V_12 -> V_47 = V_23 -> V_48 -> V_49 ;
if ( F_44 ( V_9 ) )
V_12 -> V_44 . V_45 =
( V_8 << V_9 -> V_42 ) |
( V_45 & ( V_9 -> V_46 - 1 ) ) ;
else
V_12 -> V_44 . V_45 = ( V_8 * V_9 -> V_46 ) +
F_46 ( V_45 , V_9 -> V_46 ) ;
}
static void F_48 ( struct V_22 * V_23 , struct V_12 * V_12 )
{
V_12 -> V_47 = V_23 -> V_50 -> V_49 ;
}
static int F_49 ( struct V_22 * V_23 , struct V_12 * V_12 )
{
return ( V_12 -> V_51 & ( V_52 | V_53 ) ) &&
F_50 ( V_23 -> V_2 ) ;
}
static void F_51 ( struct V_9 * V_9 , struct V_12 * V_12 )
{
struct V_54 * V_55 ;
if ( V_12 -> V_51 & V_56 )
return;
V_55 = F_52 ( V_12 , sizeof( struct V_54 ) ) ;
V_55 -> V_57 = F_53 ( V_9 -> V_58 ) ;
}
static void F_54 ( struct V_22 * V_23 , struct V_12 * V_12 )
{
struct V_9 * V_9 = V_23 -> V_9 ;
unsigned long V_24 ;
if ( ! F_49 ( V_23 , V_12 ) ) {
F_55 ( V_12 ) ;
return;
}
if ( F_56 ( V_23 -> V_2 ) ) {
F_39 ( V_12 ) ;
return;
}
F_15 ( & V_9 -> V_25 , V_24 ) ;
F_57 ( & V_9 -> V_59 , V_12 ) ;
F_16 ( & V_9 -> V_25 , V_24 ) ;
}
static void F_58 ( struct V_22 * V_23 , struct V_12 * V_12 )
{
F_48 ( V_23 , V_12 ) ;
F_54 ( V_23 , V_12 ) ;
}
static void F_59 ( struct V_22 * V_23 , struct V_12 * V_12 ,
T_1 V_8 )
{
F_47 ( V_23 , V_12 , V_8 ) ;
F_54 ( V_23 , V_12 ) ;
}
static void F_60 ( struct V_60 * V_61 )
{
struct V_9 * V_9 = V_61 -> V_23 -> V_9 ;
if ( V_61 -> V_62 && V_61 -> V_63 ) {
F_61 ( & V_61 -> V_32 , & V_9 -> V_64 ) ;
F_4 ( V_9 ) ;
}
}
static void F_62 ( int V_65 , unsigned long V_66 , void * V_67 )
{
unsigned long V_24 ;
struct V_60 * V_61 = V_67 ;
struct V_9 * V_9 = V_61 -> V_23 -> V_9 ;
V_61 -> V_68 = V_65 || V_66 ? - V_28 : 0 ;
F_15 ( & V_9 -> V_25 , V_24 ) ;
V_61 -> V_63 = true ;
F_60 ( V_61 ) ;
F_16 ( & V_9 -> V_25 , V_24 ) ;
}
static void F_63 ( struct V_12 * V_12 , int V_68 )
{
unsigned long V_24 ;
struct V_54 * V_55 = F_52 ( V_12 , sizeof( struct V_54 ) ) ;
struct V_60 * V_61 = V_55 -> V_69 ;
struct V_9 * V_9 = V_61 -> V_23 -> V_9 ;
V_61 -> V_68 = V_68 ;
F_15 ( & V_9 -> V_25 , V_24 ) ;
V_61 -> V_63 = true ;
F_60 ( V_61 ) ;
F_16 ( & V_9 -> V_25 , V_24 ) ;
}
static void F_64 ( struct V_22 * V_23 , struct V_13 * V_19 )
{
struct V_9 * V_9 = V_23 -> V_9 ;
unsigned long V_24 ;
F_15 ( & V_23 -> V_25 , V_24 ) ;
F_10 ( V_9 , V_19 , & V_23 -> V_26 ) ;
F_16 ( & V_23 -> V_25 , V_24 ) ;
F_4 ( V_9 ) ;
}
static void F_65 ( struct V_22 * V_23 , struct V_13 * V_19 )
{
struct V_9 * V_9 = V_23 -> V_9 ;
unsigned long V_24 ;
F_15 ( & V_23 -> V_25 , V_24 ) ;
F_12 ( V_9 , V_19 , & V_23 -> V_26 ) ;
F_16 ( & V_23 -> V_25 , V_24 ) ;
F_4 ( V_9 ) ;
}
static void F_66 ( struct V_60 * V_61 )
{
if ( V_61 -> V_12 ) {
V_61 -> V_12 -> V_70 = V_61 -> V_71 ;
F_67 ( & V_61 -> V_12 -> V_72 ) ;
}
F_19 ( V_61 -> V_23 -> V_9 , V_61 -> V_19 ) ;
F_28 ( & V_61 -> V_32 ) ;
F_68 ( V_61 , V_61 -> V_23 -> V_9 -> V_73 ) ;
}
static void F_69 ( struct V_60 * V_61 )
{
struct V_22 * V_23 = V_61 -> V_23 ;
struct V_9 * V_9 = V_23 -> V_9 ;
struct V_12 * V_12 ;
int V_15 ;
V_12 = V_61 -> V_12 ;
if ( V_12 ) {
V_12 -> V_70 = V_61 -> V_71 ;
F_67 ( & V_12 -> V_72 ) ;
}
if ( V_61 -> V_68 ) {
F_19 ( V_9 , V_61 -> V_19 ) ;
goto V_74;
}
V_15 = F_70 ( V_23 -> V_2 , V_61 -> V_75 , V_61 -> V_76 ) ;
if ( V_15 ) {
F_71 ( V_9 , L_1 , V_15 ) ;
F_19 ( V_9 , V_61 -> V_19 ) ;
goto V_74;
}
if ( V_12 ) {
F_65 ( V_23 , V_61 -> V_19 ) ;
F_36 ( V_12 , 0 ) ;
} else
F_64 ( V_23 , V_61 -> V_19 ) ;
V_74:
F_28 ( & V_61 -> V_32 ) ;
F_68 ( V_61 , V_9 -> V_73 ) ;
}
static void F_72 ( struct V_60 * V_61 )
{
struct V_22 * V_23 = V_61 -> V_23 ;
F_39 ( V_61 -> V_12 ) ;
F_65 ( V_23 , V_61 -> V_19 ) ;
F_65 ( V_23 , V_61 -> V_77 ) ;
F_68 ( V_61 , V_23 -> V_9 -> V_73 ) ;
}
static void F_73 ( struct V_60 * V_61 )
{
struct V_22 * V_23 = V_61 -> V_23 ;
F_51 ( V_23 -> V_9 , V_61 -> V_12 ) ;
F_65 ( V_23 , V_61 -> V_19 ) ;
F_65 ( V_23 , V_61 -> V_77 ) ;
if ( V_61 -> V_78 )
if ( V_61 -> V_79 )
F_59 ( V_23 , V_61 -> V_12 , V_61 -> V_76 ) ;
else {
bool V_80 = false ;
if ( F_74 ( V_23 -> V_9 -> V_81 , V_61 -> V_76 , & V_80 ) || V_80 )
F_36 ( V_61 -> V_12 , 0 ) ;
else
F_59 ( V_23 , V_61 -> V_12 , V_61 -> V_76 ) ;
}
else
F_36 ( V_61 -> V_12 , 0 ) ;
F_68 ( V_61 , V_23 -> V_9 -> V_73 ) ;
}
static void F_75 ( struct V_60 * V_61 )
{
int V_15 ;
struct V_22 * V_23 = V_61 -> V_23 ;
V_15 = F_76 ( V_23 -> V_2 , V_61 -> V_75 ) ;
if ( V_15 )
F_77 ( L_2 ) ;
F_73 ( V_61 ) ;
}
static void F_78 ( struct V_9 * V_9 , struct V_82 * V_83 ,
T_3 * V_84 )
{
unsigned long V_24 ;
struct V_82 V_85 ;
struct V_60 * V_61 , * V_35 ;
F_22 ( & V_85 ) ;
F_15 ( & V_9 -> V_25 , V_24 ) ;
F_79 ( V_83 , & V_85 ) ;
F_16 ( & V_9 -> V_25 , V_24 ) ;
F_80 ( V_61 , V_35 , & V_85 , V_32 )
( * V_84 ) ( V_61 ) ;
}
static int F_81 ( struct V_9 * V_9 , struct V_12 * V_12 )
{
return V_12 -> V_44 . V_86 ==
( V_9 -> V_46 << V_87 ) ;
}
static int F_82 ( struct V_9 * V_9 , struct V_12 * V_12 )
{
return ( F_83 ( V_12 ) == V_88 ) &&
F_81 ( V_9 , V_12 ) ;
}
static void F_84 ( struct V_12 * V_12 , T_4 * * V_89 ,
T_4 * V_84 )
{
* V_89 = V_12 -> V_70 ;
V_12 -> V_70 = V_84 ;
}
static int F_85 ( struct V_9 * V_9 )
{
if ( V_9 -> V_90 )
return 0 ;
V_9 -> V_90 = F_86 ( V_9 -> V_73 , V_91 ) ;
return V_9 -> V_90 ? 0 : - V_92 ;
}
static struct V_60 * F_87 ( struct V_9 * V_9 )
{
struct V_60 * V_61 = V_9 -> V_90 ;
F_24 ( ! V_9 -> V_90 ) ;
memset ( V_61 , 0 , sizeof( struct V_60 ) ) ;
F_22 ( & V_61 -> V_32 ) ;
V_61 -> V_12 = NULL ;
V_9 -> V_90 = NULL ;
return V_61 ;
}
static void F_88 ( struct V_22 * V_23 , T_1 V_75 ,
struct V_93 * V_94 , T_1 V_95 ,
T_1 V_96 ,
struct V_13 * V_19 , struct V_12 * V_12 )
{
int V_15 ;
struct V_9 * V_9 = V_23 -> V_9 ;
struct V_60 * V_61 = F_87 ( V_9 ) ;
V_61 -> V_23 = V_23 ;
V_61 -> V_75 = V_75 ;
V_61 -> V_76 = V_96 ;
V_61 -> V_19 = V_19 ;
if ( ! F_89 ( V_9 -> V_97 , & V_61 -> V_32 ) )
V_61 -> V_62 = true ;
if ( F_82 ( V_9 , V_12 ) ) {
struct V_54 * V_55 = F_52 ( V_12 , sizeof( struct V_54 ) ) ;
V_55 -> V_69 = V_61 ;
V_61 -> V_12 = V_12 ;
F_84 ( V_12 , & V_61 -> V_71 , F_63 ) ;
F_51 ( V_9 , V_12 ) ;
F_59 ( V_23 , V_12 , V_96 ) ;
} else {
struct V_98 V_99 , V_100 ;
V_99 . V_49 = V_94 -> V_49 ;
V_99 . V_101 = V_95 * V_9 -> V_46 ;
V_99 . V_102 = V_9 -> V_46 ;
V_100 . V_49 = V_23 -> V_48 -> V_49 ;
V_100 . V_101 = V_96 * V_9 -> V_46 ;
V_100 . V_102 = V_9 -> V_46 ;
V_15 = F_90 ( V_9 -> V_103 , & V_99 , 1 , & V_100 ,
0 , F_62 , V_61 ) ;
if ( V_15 < 0 ) {
F_68 ( V_61 , V_9 -> V_73 ) ;
F_77 ( L_3 ) ;
F_19 ( V_9 , V_19 ) ;
}
}
}
static void F_91 ( struct V_22 * V_23 , T_1 V_75 ,
T_1 V_95 , T_1 V_96 ,
struct V_13 * V_19 , struct V_12 * V_12 )
{
F_88 ( V_23 , V_75 , V_23 -> V_48 ,
V_95 , V_96 , V_19 , V_12 ) ;
}
static void F_92 ( struct V_22 * V_23 , T_1 V_75 ,
T_1 V_96 ,
struct V_13 * V_19 , struct V_12 * V_12 )
{
F_88 ( V_23 , V_75 , V_23 -> V_50 ,
V_75 , V_96 , V_19 , V_12 ) ;
}
static void F_93 ( struct V_22 * V_23 , T_1 V_75 ,
T_1 V_76 , struct V_13 * V_19 ,
struct V_12 * V_12 )
{
struct V_9 * V_9 = V_23 -> V_9 ;
struct V_60 * V_61 = F_87 ( V_9 ) ;
V_61 -> V_62 = true ;
V_61 -> V_63 = false ;
V_61 -> V_23 = V_23 ;
V_61 -> V_75 = V_75 ;
V_61 -> V_76 = V_76 ;
V_61 -> V_19 = V_19 ;
if ( ! V_9 -> V_104 . V_105 )
F_69 ( V_61 ) ;
else if ( F_82 ( V_9 , V_12 ) ) {
struct V_54 * V_55 = F_52 ( V_12 , sizeof( struct V_54 ) ) ;
V_55 -> V_69 = V_61 ;
V_61 -> V_12 = V_12 ;
F_84 ( V_12 , & V_61 -> V_71 , F_63 ) ;
F_51 ( V_9 , V_12 ) ;
F_59 ( V_23 , V_12 , V_76 ) ;
} else {
int V_15 ;
struct V_98 V_100 ;
V_100 . V_49 = V_23 -> V_48 -> V_49 ;
V_100 . V_101 = V_76 * V_9 -> V_46 ;
V_100 . V_102 = V_9 -> V_46 ;
V_15 = F_94 ( V_9 -> V_103 , 1 , & V_100 , 0 , F_62 , V_61 ) ;
if ( V_15 < 0 ) {
F_68 ( V_61 , V_9 -> V_73 ) ;
F_77 ( L_4 ) ;
F_19 ( V_9 , V_19 ) ;
}
}
}
static int F_95 ( struct V_9 * V_9 )
{
int V_15 ;
if ( F_96 ( V_9 ) >= V_106 )
return - V_107 ;
V_15 = F_97 ( V_9 -> V_81 ) ;
if ( V_15 )
F_71 ( V_9 , L_5 , V_15 ) ;
return V_15 ;
}
static void F_98 ( struct V_9 * V_9 , T_1 V_108 )
{
unsigned long V_24 ;
if ( V_108 <= V_9 -> V_109 && ! V_9 -> V_110 ) {
F_99 ( L_6 ,
F_100 ( V_9 -> V_36 ) ) ;
F_15 ( & V_9 -> V_25 , V_24 ) ;
V_9 -> V_110 = true ;
F_16 ( & V_9 -> V_25 , V_24 ) ;
F_101 ( V_9 -> V_111 -> V_112 ) ;
}
}
static int F_102 ( struct V_22 * V_23 , T_1 * V_113 )
{
int V_15 ;
T_1 V_108 ;
struct V_9 * V_9 = V_23 -> V_9 ;
if ( F_103 ( F_96 ( V_9 ) != V_114 ) )
return - V_107 ;
V_15 = F_104 ( V_9 -> V_81 , & V_108 ) ;
if ( V_15 ) {
F_71 ( V_9 , L_7 , V_15 ) ;
return V_15 ;
}
F_98 ( V_9 , V_108 ) ;
if ( ! V_108 ) {
V_15 = F_95 ( V_9 ) ;
if ( V_15 )
return V_15 ;
V_15 = F_104 ( V_9 -> V_81 , & V_108 ) ;
if ( V_15 ) {
F_71 ( V_9 , L_7 , V_15 ) ;
return V_15 ;
}
if ( ! V_108 ) {
F_105 ( V_9 , V_115 ) ;
return - V_116 ;
}
}
V_15 = F_106 ( V_9 -> V_81 , V_113 ) ;
if ( V_15 ) {
F_71 ( V_9 , L_8 , V_15 ) ;
return V_15 ;
}
return 0 ;
}
static void F_107 ( struct V_12 * V_12 )
{
struct V_54 * V_55 = F_52 ( V_12 , sizeof( struct V_54 ) ) ;
struct V_22 * V_23 = V_55 -> V_23 ;
unsigned long V_24 ;
F_15 ( & V_23 -> V_25 , V_24 ) ;
F_57 ( & V_23 -> V_41 , V_12 ) ;
F_16 ( & V_23 -> V_25 , V_24 ) ;
}
static int F_108 ( struct V_9 * V_9 )
{
enum V_117 V_61 = F_96 ( V_9 ) ;
switch ( V_61 ) {
case V_114 :
F_77 ( L_9 ) ;
return - V_28 ;
case V_115 :
return V_9 -> V_104 . V_118 ? - V_116 : 0 ;
case V_106 :
case V_119 :
return - V_28 ;
default:
F_77 ( L_10 ) ;
return - V_28 ;
}
}
static void F_109 ( struct V_9 * V_9 , struct V_12 * V_12 )
{
int error = F_108 ( V_9 ) ;
if ( error )
F_36 ( V_12 , error ) ;
else
F_107 ( V_12 ) ;
}
static void F_110 ( struct V_9 * V_9 , struct V_13 * V_19 )
{
struct V_12 * V_12 ;
struct V_20 V_21 ;
int error ;
error = F_108 ( V_9 ) ;
if ( error ) {
F_17 ( V_9 , V_19 , error ) ;
return;
}
F_33 ( & V_21 ) ;
F_10 ( V_9 , V_19 , & V_21 ) ;
error = F_108 ( V_9 ) ;
if ( error )
while ( ( V_12 = F_35 ( & V_21 ) ) )
F_36 ( V_12 , error ) ;
else
while ( ( V_12 = F_35 ( & V_21 ) ) )
F_107 ( V_12 ) ;
}
static void F_111 ( struct V_22 * V_23 , struct V_12 * V_12 )
{
int V_15 ;
unsigned long V_24 ;
struct V_9 * V_9 = V_23 -> V_9 ;
struct V_13 * V_19 , * V_77 ;
struct V_4 V_5 , V_120 ;
T_1 V_8 = F_45 ( V_23 , V_12 ) ;
struct V_121 V_122 ;
struct V_60 * V_61 ;
F_3 ( V_23 -> V_2 , V_8 , & V_5 ) ;
if ( F_6 ( V_23 -> V_9 , & V_5 , V_12 , & V_19 ) )
return;
V_15 = F_112 ( V_23 -> V_2 , V_8 , 1 , & V_122 ) ;
switch ( V_15 ) {
case 0 :
F_1 ( V_23 -> V_2 , V_122 . V_8 , & V_120 ) ;
if ( F_6 ( V_23 -> V_9 , & V_120 , V_12 , & V_77 ) ) {
F_65 ( V_23 , V_19 ) ;
break;
}
if ( F_81 ( V_9 , V_12 ) ) {
V_61 = F_87 ( V_9 ) ;
V_61 -> V_23 = V_23 ;
V_61 -> V_78 = V_9 -> V_104 . V_123 ;
V_61 -> V_79 = ! V_122 . V_124 ;
V_61 -> V_75 = V_8 ;
V_61 -> V_76 = V_122 . V_8 ;
V_61 -> V_19 = V_19 ;
V_61 -> V_77 = V_77 ;
V_61 -> V_12 = V_12 ;
if ( ! F_89 ( V_9 -> V_58 , & V_61 -> V_32 ) ) {
F_15 ( & V_9 -> V_25 , V_24 ) ;
F_61 ( & V_61 -> V_32 , & V_9 -> V_125 ) ;
F_16 ( & V_9 -> V_25 , V_24 ) ;
F_4 ( V_9 ) ;
}
} else {
F_51 ( V_9 , V_12 ) ;
F_65 ( V_23 , V_19 ) ;
F_65 ( V_23 , V_77 ) ;
if ( ( ! V_122 . V_124 ) && V_9 -> V_104 . V_123 )
F_59 ( V_23 , V_12 , V_122 . V_8 ) ;
else
F_36 ( V_12 , 0 ) ;
}
break;
case - V_126 :
F_65 ( V_23 , V_19 ) ;
F_36 ( V_12 , 0 ) ;
break;
default:
F_77 ( L_11 ,
V_127 , V_15 ) ;
F_65 ( V_23 , V_19 ) ;
F_39 ( V_12 ) ;
break;
}
}
static void F_113 ( struct V_22 * V_23 , struct V_12 * V_12 , T_1 V_8 ,
struct V_4 * V_5 ,
struct V_121 * V_122 ,
struct V_13 * V_19 )
{
int V_15 ;
T_1 V_76 ;
struct V_9 * V_9 = V_23 -> V_9 ;
V_15 = F_102 ( V_23 , & V_76 ) ;
switch ( V_15 ) {
case 0 :
F_91 ( V_23 , V_8 , V_122 -> V_8 ,
V_76 , V_19 , V_12 ) ;
break;
case - V_116 :
F_110 ( V_9 , V_19 ) ;
break;
default:
F_77 ( L_12 ,
V_127 , V_15 ) ;
F_19 ( V_9 , V_19 ) ;
break;
}
}
static void F_114 ( struct V_22 * V_23 , struct V_12 * V_12 ,
T_1 V_8 ,
struct V_121 * V_122 )
{
struct V_13 * V_19 ;
struct V_9 * V_9 = V_23 -> V_9 ;
struct V_4 V_5 ;
F_1 ( V_23 -> V_2 , V_122 -> V_8 , & V_5 ) ;
if ( F_6 ( V_9 , & V_5 , V_12 , & V_19 ) )
return;
if ( F_83 ( V_12 ) == V_88 && V_12 -> V_44 . V_86 )
F_113 ( V_23 , V_12 , V_8 , & V_5 , V_122 , V_19 ) ;
else {
struct V_54 * V_55 = F_52 ( V_12 , sizeof( struct V_54 ) ) ;
V_55 -> V_128 = F_53 ( V_9 -> V_97 ) ;
F_51 ( V_9 , V_12 ) ;
F_65 ( V_23 , V_19 ) ;
F_59 ( V_23 , V_12 , V_122 -> V_8 ) ;
}
}
static void F_115 ( struct V_22 * V_23 , struct V_12 * V_12 , T_1 V_8 ,
struct V_13 * V_19 )
{
int V_15 ;
T_1 V_76 ;
struct V_9 * V_9 = V_23 -> V_9 ;
if ( ! V_12 -> V_44 . V_86 ) {
F_51 ( V_9 , V_12 ) ;
F_65 ( V_23 , V_19 ) ;
F_59 ( V_23 , V_12 , 0 ) ;
return;
}
if ( F_83 ( V_12 ) == V_129 ) {
F_116 ( V_12 ) ;
F_65 ( V_23 , V_19 ) ;
F_36 ( V_12 , 0 ) ;
return;
}
V_15 = F_102 ( V_23 , & V_76 ) ;
switch ( V_15 ) {
case 0 :
if ( V_23 -> V_50 )
F_92 ( V_23 , V_8 , V_76 , V_19 , V_12 ) ;
else
F_93 ( V_23 , V_8 , V_76 , V_19 , V_12 ) ;
break;
case - V_116 :
F_110 ( V_9 , V_19 ) ;
break;
default:
F_77 ( L_12 ,
V_127 , V_15 ) ;
F_19 ( V_9 , V_19 ) ;
break;
}
}
static void F_117 ( struct V_22 * V_23 , struct V_12 * V_12 )
{
int V_15 ;
struct V_9 * V_9 = V_23 -> V_9 ;
T_1 V_8 = F_45 ( V_23 , V_12 ) ;
struct V_13 * V_19 ;
struct V_4 V_5 ;
struct V_121 V_122 ;
F_3 ( V_23 -> V_2 , V_8 , & V_5 ) ;
if ( F_6 ( V_9 , & V_5 , V_12 , & V_19 ) )
return;
V_15 = F_112 ( V_23 -> V_2 , V_8 , 1 , & V_122 ) ;
switch ( V_15 ) {
case 0 :
if ( V_122 . V_124 ) {
F_114 ( V_23 , V_12 , V_8 , & V_122 ) ;
F_65 ( V_23 , V_19 ) ;
} else {
F_51 ( V_9 , V_12 ) ;
F_65 ( V_23 , V_19 ) ;
F_59 ( V_23 , V_12 , V_122 . V_8 ) ;
}
break;
case - V_126 :
if ( F_83 ( V_12 ) == V_129 && V_23 -> V_50 ) {
F_51 ( V_9 , V_12 ) ;
F_65 ( V_23 , V_19 ) ;
F_58 ( V_23 , V_12 ) ;
} else
F_115 ( V_23 , V_12 , V_8 , V_19 ) ;
break;
default:
F_77 ( L_11 ,
V_127 , V_15 ) ;
F_65 ( V_23 , V_19 ) ;
F_39 ( V_12 ) ;
break;
}
}
static void F_118 ( struct V_22 * V_23 , struct V_12 * V_12 )
{
int V_15 ;
int V_130 = F_83 ( V_12 ) ;
T_1 V_8 = F_45 ( V_23 , V_12 ) ;
struct V_121 V_122 ;
V_15 = F_112 ( V_23 -> V_2 , V_8 , 1 , & V_122 ) ;
switch ( V_15 ) {
case 0 :
if ( V_122 . V_124 && ( V_130 == V_88 ) && V_12 -> V_44 . V_86 )
F_109 ( V_23 -> V_9 , V_12 ) ;
else {
F_51 ( V_23 -> V_9 , V_12 ) ;
F_59 ( V_23 , V_12 , V_122 . V_8 ) ;
}
break;
case - V_126 :
if ( V_130 != V_129 ) {
F_109 ( V_23 -> V_9 , V_12 ) ;
break;
}
if ( V_23 -> V_50 ) {
F_51 ( V_23 -> V_9 , V_12 ) ;
F_58 ( V_23 , V_12 ) ;
break;
}
F_116 ( V_12 ) ;
F_36 ( V_12 , 0 ) ;
break;
default:
F_77 ( L_11 ,
V_127 , V_15 ) ;
F_39 ( V_12 ) ;
break;
}
}
static void F_119 ( struct V_22 * V_23 , struct V_12 * V_12 )
{
F_36 ( V_12 , 0 ) ;
}
static void F_120 ( struct V_22 * V_23 , struct V_12 * V_12 )
{
F_39 ( V_12 ) ;
}
static int F_121 ( struct V_9 * V_9 )
{
return V_131 < V_9 -> V_132 ||
V_131 > V_9 -> V_132 + V_133 ;
}
static void F_122 ( struct V_22 * V_23 , struct V_12 * V_12 )
{
struct V_134 * * V_135 , * V_136 ;
struct V_54 * V_137 ;
T_2 V_45 = V_12 -> V_44 . V_45 ;
V_135 = & V_23 -> V_138 . V_134 ;
V_136 = NULL ;
while ( * V_135 ) {
V_136 = * V_135 ;
V_137 = F_123 ( V_136 ) ;
if ( V_45 < F_124 ( V_137 ) -> V_44 . V_45 )
V_135 = & ( * V_135 ) -> V_139 ;
else
V_135 = & ( * V_135 ) -> V_140 ;
}
V_137 = F_52 ( V_12 , sizeof( struct V_54 ) ) ;
F_125 ( & V_137 -> V_134 , V_136 , V_135 ) ;
F_126 ( & V_137 -> V_134 , & V_23 -> V_138 ) ;
}
static void F_127 ( struct V_22 * V_23 )
{
struct V_134 * V_141 ;
struct V_54 * V_137 ;
struct V_12 * V_12 ;
for ( V_141 = F_128 ( & V_23 -> V_138 ) ; V_141 ; V_141 = F_129 ( V_141 ) ) {
V_137 = F_123 ( V_141 ) ;
V_12 = F_124 ( V_137 ) ;
F_57 ( & V_23 -> V_26 , V_12 ) ;
F_130 ( & V_137 -> V_134 , & V_23 -> V_138 ) ;
}
F_103 ( ! F_131 ( & V_23 -> V_138 ) ) ;
}
static void F_132 ( struct V_22 * V_23 )
{
struct V_12 * V_12 ;
struct V_20 V_21 ;
F_33 ( & V_21 ) ;
F_34 ( & V_21 , & V_23 -> V_26 ) ;
F_33 ( & V_23 -> V_26 ) ;
while ( ( V_12 = F_35 ( & V_21 ) ) )
F_122 ( V_23 , V_12 ) ;
F_127 ( V_23 ) ;
}
static void F_133 ( struct V_22 * V_23 )
{
struct V_9 * V_9 = V_23 -> V_9 ;
unsigned long V_24 ;
struct V_12 * V_12 ;
struct V_20 V_21 ;
struct V_142 V_143 ;
if ( V_23 -> V_144 ) {
F_32 ( V_23 , & V_23 -> V_26 ) ;
return;
}
F_33 ( & V_21 ) ;
F_15 ( & V_23 -> V_25 , V_24 ) ;
if ( F_134 ( & V_23 -> V_26 ) ) {
F_16 ( & V_23 -> V_25 , V_24 ) ;
return;
}
F_132 ( V_23 ) ;
F_34 ( & V_21 , & V_23 -> V_26 ) ;
F_33 ( & V_23 -> V_26 ) ;
F_16 ( & V_23 -> V_25 , V_24 ) ;
F_135 ( & V_143 ) ;
while ( ( V_12 = F_35 ( & V_21 ) ) ) {
if ( F_85 ( V_9 ) ) {
F_15 ( & V_23 -> V_25 , V_24 ) ;
F_57 ( & V_23 -> V_26 , V_12 ) ;
F_34 ( & V_23 -> V_26 , & V_21 ) ;
F_16 ( & V_23 -> V_25 , V_24 ) ;
break;
}
if ( V_12 -> V_51 & V_56 )
V_9 -> F_111 ( V_23 , V_12 ) ;
else
V_9 -> F_117 ( V_23 , V_12 ) ;
}
F_136 ( & V_143 ) ;
}
static struct V_22 * F_137 ( struct V_9 * V_9 )
{
struct V_22 * V_23 = NULL ;
F_41 () ;
if ( ! F_138 ( & V_9 -> V_145 ) ) {
V_23 = F_139 ( V_9 -> V_145 . V_146 , struct V_22 , V_32 ) ;
F_140 ( V_23 ) ;
}
F_43 () ;
return V_23 ;
}
static struct V_22 * F_141 ( struct V_9 * V_9 , struct V_22 * V_23 )
{
struct V_22 * V_147 = V_23 ;
F_41 () ;
F_142 (tc, &pool->active_thins, list) {
F_140 ( V_23 ) ;
F_143 ( V_147 ) ;
F_43 () ;
return V_23 ;
}
F_143 ( V_147 ) ;
F_43 () ;
return NULL ;
}
static void F_144 ( struct V_9 * V_9 )
{
unsigned long V_24 ;
struct V_12 * V_12 ;
struct V_20 V_21 ;
struct V_22 * V_23 ;
V_23 = F_137 ( V_9 ) ;
while ( V_23 ) {
F_133 ( V_23 ) ;
V_23 = F_141 ( V_9 , V_23 ) ;
}
F_33 ( & V_21 ) ;
F_15 ( & V_9 -> V_25 , V_24 ) ;
F_34 ( & V_21 , & V_9 -> V_59 ) ;
F_33 ( & V_9 -> V_59 ) ;
F_16 ( & V_9 -> V_25 , V_24 ) ;
if ( F_134 ( & V_21 ) &&
! ( F_145 ( V_9 -> V_81 ) && F_121 ( V_9 ) ) )
return;
if ( F_95 ( V_9 ) ) {
while ( ( V_12 = F_35 ( & V_21 ) ) )
F_39 ( V_12 ) ;
return;
}
V_9 -> V_132 = V_131 ;
while ( ( V_12 = F_35 ( & V_21 ) ) )
F_55 ( V_12 ) ;
}
static void F_146 ( struct V_148 * V_149 )
{
struct V_9 * V_9 = F_147 ( V_149 , struct V_9 , V_11 ) ;
F_78 ( V_9 , & V_9 -> V_64 , & V_9 -> F_69 ) ;
F_78 ( V_9 , & V_9 -> V_125 , & V_9 -> F_75 ) ;
F_144 ( V_9 ) ;
}
static void F_148 ( struct V_148 * V_149 )
{
struct V_9 * V_9 = F_147 ( F_149 ( V_149 ) , struct V_9 , V_150 ) ;
F_4 ( V_9 ) ;
F_150 ( V_9 -> V_10 , & V_9 -> V_150 , V_133 ) ;
}
static void F_151 ( struct V_148 * V_149 )
{
struct V_9 * V_9 = F_147 ( F_149 ( V_149 ) , struct V_9 ,
V_151 ) ;
if ( F_96 ( V_9 ) == V_115 && ! V_9 -> V_104 . V_118 )
F_105 ( V_9 , V_106 ) ;
}
static struct V_152 * F_152 ( struct V_148 * V_149 )
{
return F_147 ( V_149 , struct V_152 , V_11 ) ;
}
static void F_153 ( struct V_152 * V_153 )
{
F_154 ( & V_153 -> F_154 ) ;
}
static void F_155 ( struct V_152 * V_153 , struct V_9 * V_9 ,
void (* V_84)( struct V_148 * ) )
{
F_156 ( & V_153 -> V_11 , V_84 ) ;
F_157 ( & V_153 -> F_154 ) ;
F_5 ( V_9 -> V_10 , & V_153 -> V_11 ) ;
F_158 ( & V_153 -> F_154 ) ;
}
static struct V_154 * F_159 ( struct V_148 * V_149 )
{
return F_147 ( F_152 ( V_149 ) , struct V_154 , V_153 ) ;
}
static void F_160 ( struct V_148 * V_149 )
{
struct V_154 * V_155 = F_159 ( V_149 ) ;
V_155 -> V_23 -> V_144 = true ;
F_37 ( V_155 -> V_23 ) ;
F_153 ( & V_155 -> V_153 ) ;
}
static void F_161 ( struct V_148 * V_149 )
{
struct V_154 * V_155 = F_159 ( V_149 ) ;
V_155 -> V_23 -> V_144 = false ;
F_153 ( & V_155 -> V_153 ) ;
}
static void V_154 ( struct V_22 * V_23 , void (* V_84)( struct V_148 * ) )
{
struct V_154 V_155 ;
V_155 . V_23 = V_23 ;
F_155 ( & V_155 . V_153 , V_23 -> V_9 , V_84 ) ;
}
static enum V_117 F_96 ( struct V_9 * V_9 )
{
return V_9 -> V_104 . V_156 ;
}
static void F_162 ( struct V_9 * V_9 , const char * V_157 )
{
F_101 ( V_9 -> V_111 -> V_112 ) ;
F_163 ( L_13 ,
F_100 ( V_9 -> V_36 ) , V_157 ) ;
}
static void F_105 ( struct V_9 * V_9 , enum V_117 V_157 )
{
struct V_158 * V_159 = V_9 -> V_111 -> V_160 ;
bool V_161 = F_164 ( V_9 -> V_81 ) ;
enum V_117 V_162 = F_96 ( V_9 ) ;
unsigned long V_151 = F_165 ( V_163 ) * V_164 ;
if ( V_157 == V_114 && V_161 ) {
F_166 ( L_14 ,
F_100 ( V_9 -> V_36 ) ) ;
if ( V_162 != V_157 )
V_157 = V_162 ;
else
V_157 = V_106 ;
}
if ( V_162 == V_119 )
V_157 = V_162 ;
switch ( V_157 ) {
case V_119 :
if ( V_162 != V_157 )
F_162 ( V_9 , L_15 ) ;
F_167 ( V_9 -> V_81 ) ;
V_9 -> F_117 = F_120 ;
V_9 -> F_111 = F_120 ;
V_9 -> F_69 = F_66 ;
V_9 -> F_75 = F_72 ;
F_40 ( V_9 ) ;
break;
case V_106 :
if ( V_162 != V_157 )
F_162 ( V_9 , L_16 ) ;
F_167 ( V_9 -> V_81 ) ;
V_9 -> F_117 = F_118 ;
V_9 -> F_111 = F_119 ;
V_9 -> F_69 = F_66 ;
V_9 -> F_75 = F_73 ;
F_40 ( V_9 ) ;
break;
case V_115 :
if ( V_162 != V_157 )
F_162 ( V_9 , L_17 ) ;
V_9 -> F_117 = F_118 ;
V_9 -> F_111 = F_111 ;
V_9 -> F_69 = F_69 ;
V_9 -> F_75 = F_73 ;
if ( ! V_9 -> V_104 . V_118 && V_151 )
F_150 ( V_9 -> V_10 , & V_9 -> V_151 , V_151 ) ;
break;
case V_114 :
if ( V_162 != V_157 )
F_162 ( V_9 , L_18 ) ;
F_168 ( V_9 -> V_81 ) ;
V_9 -> F_117 = F_117 ;
V_9 -> F_111 = F_111 ;
V_9 -> F_69 = F_69 ;
V_9 -> F_75 = F_75 ;
break;
}
V_9 -> V_104 . V_156 = V_157 ;
V_159 -> V_165 . V_156 = V_157 ;
}
static void F_169 ( struct V_9 * V_9 )
{
const char * V_166 = F_100 ( V_9 -> V_36 ) ;
F_77 ( L_19 , V_166 ) ;
if ( F_170 ( V_9 -> V_81 ) ) {
F_166 ( L_20 , V_166 ) ;
F_105 ( V_9 , V_119 ) ;
}
if ( F_171 ( V_9 -> V_81 ) ) {
F_166 ( L_21 , V_166 ) ;
F_105 ( V_9 , V_119 ) ;
}
}
static void F_71 ( struct V_9 * V_9 , const char * V_167 , int V_15 )
{
F_77 ( L_22 ,
F_100 ( V_9 -> V_36 ) , V_167 , V_15 ) ;
F_169 ( V_9 ) ;
F_105 ( V_9 , V_106 ) ;
}
static void F_172 ( struct V_22 * V_23 , struct V_12 * V_12 )
{
unsigned long V_24 ;
struct V_9 * V_9 = V_23 -> V_9 ;
F_15 ( & V_23 -> V_25 , V_24 ) ;
F_57 ( & V_23 -> V_26 , V_12 ) ;
F_16 ( & V_23 -> V_25 , V_24 ) ;
F_4 ( V_9 ) ;
}
static void F_173 ( struct V_22 * V_23 , struct V_12 * V_12 )
{
struct V_54 * V_55 = F_52 ( V_12 , sizeof( struct V_54 ) ) ;
V_55 -> V_23 = V_23 ;
V_55 -> V_128 = NULL ;
V_55 -> V_57 = NULL ;
V_55 -> V_69 = NULL ;
}
static int F_174 ( struct V_168 * V_111 , struct V_12 * V_12 )
{
int V_15 ;
struct V_22 * V_23 = V_111 -> V_160 ;
T_1 V_8 = F_45 ( V_23 , V_12 ) ;
struct V_1 * V_2 = V_23 -> V_2 ;
struct V_121 V_113 ;
struct V_13 V_169 , V_77 ;
struct V_13 * V_14 ;
struct V_4 V_5 ;
F_173 ( V_23 , V_12 ) ;
if ( V_23 -> V_144 ) {
F_36 ( V_12 , V_40 ) ;
return V_170 ;
}
if ( F_96 ( V_23 -> V_9 ) == V_119 ) {
F_39 ( V_12 ) ;
return V_170 ;
}
if ( V_12 -> V_51 & ( V_56 | V_52 | V_53 ) ) {
F_172 ( V_23 , V_12 ) ;
return V_170 ;
}
V_15 = F_112 ( V_2 , V_8 , 0 , & V_113 ) ;
switch ( V_15 ) {
case 0 :
if ( F_175 ( V_113 . V_124 ) ) {
F_172 ( V_23 , V_12 ) ;
return V_170 ;
}
F_3 ( V_23 -> V_2 , V_8 , & V_5 ) ;
if ( F_8 ( V_23 -> V_9 -> V_17 , & V_5 , V_12 , & V_169 , & V_14 ) )
return V_170 ;
F_1 ( V_23 -> V_2 , V_113 . V_8 , & V_5 ) ;
if ( F_8 ( V_23 -> V_9 -> V_17 , & V_5 , V_12 , & V_77 , & V_14 ) ) {
F_14 ( V_23 , & V_169 ) ;
return V_170 ;
}
F_51 ( V_23 -> V_9 , V_12 ) ;
F_14 ( V_23 , & V_77 ) ;
F_14 ( V_23 , & V_169 ) ;
F_47 ( V_23 , V_12 , V_113 . V_8 ) ;
return V_171 ;
case - V_126 :
if ( F_96 ( V_23 -> V_9 ) == V_106 ) {
F_109 ( V_23 -> V_9 , V_12 ) ;
return V_170 ;
}
case - V_172 :
F_172 ( V_23 , V_12 ) ;
return V_170 ;
default:
F_39 ( V_12 ) ;
return V_170 ;
}
}
static int F_176 ( struct V_173 * V_174 , int V_175 )
{
struct V_158 * V_159 = F_147 ( V_174 , struct V_158 , V_176 ) ;
struct V_177 * V_178 ;
if ( F_96 ( V_159 -> V_9 ) == V_115 )
return 1 ;
V_178 = F_177 ( V_159 -> V_179 -> V_49 ) ;
return F_178 ( & V_178 -> V_180 , V_175 ) ;
}
static void F_179 ( struct V_9 * V_9 )
{
unsigned long V_24 ;
struct V_22 * V_23 ;
F_41 () ;
F_42 (tc, &pool->active_thins, list) {
F_15 ( & V_23 -> V_25 , V_24 ) ;
F_34 ( & V_23 -> V_26 , & V_23 -> V_41 ) ;
F_33 ( & V_23 -> V_41 ) ;
F_16 ( & V_23 -> V_25 , V_24 ) ;
}
F_43 () ;
}
static bool F_180 ( struct V_158 * V_159 )
{
struct V_177 * V_178 = F_177 ( V_159 -> V_179 -> V_49 ) ;
return V_178 && F_181 ( V_178 ) ;
}
static bool F_182 ( T_2 V_181 , T_5 V_182 )
{
return ! F_46 ( V_181 , V_182 ) ;
}
static void F_183 ( struct V_158 * V_159 )
{
struct V_9 * V_9 = V_159 -> V_9 ;
struct V_37 * V_183 = V_159 -> V_179 -> V_49 ;
struct V_184 * V_185 = & F_177 ( V_183 ) -> V_186 ;
T_2 V_181 = V_9 -> V_46 << V_87 ;
const char * V_187 = NULL ;
char V_188 [ V_189 ] ;
if ( ! V_159 -> V_165 . V_123 )
return;
if ( ! F_180 ( V_159 ) )
V_187 = L_23 ;
else if ( V_185 -> V_190 < V_9 -> V_46 )
V_187 = L_24 ;
else if ( V_185 -> V_191 > V_181 )
V_187 = L_25 ;
else if ( ! F_182 ( V_181 , V_185 -> V_191 ) )
V_187 = L_26 ;
if ( V_187 ) {
F_99 ( L_27 , F_184 ( V_183 , V_188 ) , V_187 ) ;
V_159 -> V_165 . V_123 = false ;
}
}
static int F_185 ( struct V_9 * V_9 , struct V_168 * V_111 )
{
struct V_158 * V_159 = V_111 -> V_160 ;
enum V_117 V_162 = F_96 ( V_9 ) ;
enum V_117 V_157 = V_159 -> V_165 . V_156 ;
V_159 -> V_165 . V_156 = V_162 ;
V_9 -> V_111 = V_111 ;
V_9 -> V_104 = V_159 -> V_165 ;
V_9 -> V_109 = V_159 -> V_109 ;
F_105 ( V_9 , V_157 ) ;
return 0 ;
}
static void F_186 ( struct V_9 * V_9 , struct V_168 * V_111 )
{
if ( V_9 -> V_111 == V_111 )
V_9 -> V_111 = NULL ;
}
static void F_187 ( struct V_192 * V_104 )
{
V_104 -> V_156 = V_114 ;
V_104 -> V_105 = true ;
V_104 -> V_193 = true ;
V_104 -> V_123 = true ;
V_104 -> V_118 = false ;
}
static void F_188 ( struct V_9 * V_9 )
{
F_27 ( V_9 ) ;
if ( F_189 ( V_9 -> V_81 ) < 0 )
F_99 ( L_28 , V_127 ) ;
F_190 ( V_9 -> V_17 ) ;
F_191 ( V_9 -> V_103 ) ;
if ( V_9 -> V_10 )
F_192 ( V_9 -> V_10 ) ;
if ( V_9 -> V_90 )
F_68 ( V_9 -> V_90 , V_9 -> V_73 ) ;
F_193 ( V_9 -> V_73 ) ;
F_194 ( V_9 -> V_97 ) ;
F_194 ( V_9 -> V_58 ) ;
F_195 ( V_9 ) ;
}
static struct V_9 * F_196 ( struct V_33 * V_36 ,
struct V_37 * V_194 ,
unsigned long V_181 ,
int V_195 , char * * error )
{
int V_15 ;
void * V_196 ;
struct V_9 * V_9 ;
struct V_197 * V_81 ;
bool V_198 = V_195 ? false : true ;
V_81 = F_197 ( V_194 , V_181 , V_198 ) ;
if ( F_198 ( V_81 ) ) {
* error = L_29 ;
return (struct V_9 * ) V_81 ;
}
V_9 = F_199 ( sizeof( * V_9 ) , V_199 ) ;
if ( ! V_9 ) {
* error = L_30 ;
V_196 = F_200 ( - V_92 ) ;
goto V_200;
}
V_9 -> V_81 = V_81 ;
V_9 -> V_46 = V_181 ;
if ( V_181 & ( V_181 - 1 ) )
V_9 -> V_42 = - 1 ;
else
V_9 -> V_42 = F_201 ( V_181 ) ;
V_9 -> V_109 = 0 ;
F_187 ( & V_9 -> V_104 ) ;
V_9 -> V_17 = F_202 ( V_201 ) ;
if ( ! V_9 -> V_17 ) {
* error = L_31 ;
V_196 = F_200 ( - V_92 ) ;
goto V_202;
}
V_9 -> V_103 = F_203 ( & V_203 ) ;
if ( F_198 ( V_9 -> V_103 ) ) {
V_15 = F_204 ( V_9 -> V_103 ) ;
* error = L_32 ;
V_196 = F_200 ( V_15 ) ;
goto V_204;
}
V_9 -> V_10 = F_205 ( L_33 V_205 , V_206 ) ;
if ( ! V_9 -> V_10 ) {
* error = L_34 ;
V_196 = F_200 ( - V_92 ) ;
goto V_207;
}
F_206 ( & V_9 -> V_11 , F_146 ) ;
F_207 ( & V_9 -> V_150 , F_148 ) ;
F_207 ( & V_9 -> V_151 , F_151 ) ;
F_208 ( & V_9 -> V_25 ) ;
F_33 ( & V_9 -> V_59 ) ;
F_22 ( & V_9 -> V_64 ) ;
F_22 ( & V_9 -> V_125 ) ;
F_22 ( & V_9 -> V_145 ) ;
V_9 -> V_110 = false ;
V_9 -> V_97 = F_209 () ;
if ( ! V_9 -> V_97 ) {
* error = L_35 ;
V_196 = F_200 ( - V_92 ) ;
goto V_208;
}
V_9 -> V_58 = F_209 () ;
if ( ! V_9 -> V_58 ) {
* error = L_36 ;
V_196 = F_200 ( - V_92 ) ;
goto V_209;
}
V_9 -> V_90 = NULL ;
V_9 -> V_73 = F_210 ( V_210 ,
V_211 ) ;
if ( ! V_9 -> V_73 ) {
* error = L_37 ;
V_196 = F_200 ( - V_92 ) ;
goto V_212;
}
V_9 -> V_213 = 1 ;
V_9 -> V_132 = V_131 ;
V_9 -> V_36 = V_36 ;
V_9 -> V_38 = V_194 ;
F_23 ( V_9 ) ;
return V_9 ;
V_212:
F_194 ( V_9 -> V_58 ) ;
V_209:
F_194 ( V_9 -> V_97 ) ;
V_208:
F_192 ( V_9 -> V_10 ) ;
V_207:
F_191 ( V_9 -> V_103 ) ;
V_204:
F_190 ( V_9 -> V_17 ) ;
V_202:
F_195 ( V_9 ) ;
V_200:
if ( F_189 ( V_81 ) )
F_99 ( L_28 , V_127 ) ;
return V_196 ;
}
static void F_211 ( struct V_9 * V_9 )
{
F_24 ( ! F_25 ( & V_29 . V_30 ) ) ;
V_9 -> V_213 ++ ;
}
static void F_212 ( struct V_9 * V_9 )
{
F_24 ( ! F_25 ( & V_29 . V_30 ) ) ;
F_24 ( ! V_9 -> V_213 ) ;
if ( ! -- V_9 -> V_213 )
F_188 ( V_9 ) ;
}
static struct V_9 * F_213 ( struct V_33 * V_36 ,
struct V_37 * V_194 ,
unsigned long V_181 , int V_195 ,
char * * error , int * V_214 )
{
struct V_9 * V_9 = F_31 ( V_194 ) ;
if ( V_9 ) {
if ( V_9 -> V_36 != V_36 ) {
* error = L_38 ;
return F_200 ( - V_215 ) ;
}
F_211 ( V_9 ) ;
} else {
V_9 = F_29 ( V_36 ) ;
if ( V_9 ) {
if ( V_9 -> V_38 != V_194 ) {
* error = L_39 ;
return F_200 ( - V_107 ) ;
}
F_211 ( V_9 ) ;
} else {
V_9 = F_196 ( V_36 , V_194 , V_181 , V_195 , error ) ;
* V_214 = 1 ;
}
}
return V_9 ;
}
static void F_214 ( struct V_168 * V_111 )
{
struct V_158 * V_159 = V_111 -> V_160 ;
F_215 ( & V_29 . V_30 ) ;
F_186 ( V_159 -> V_9 , V_111 ) ;
F_212 ( V_159 -> V_9 ) ;
F_216 ( V_111 , V_159 -> V_194 ) ;
F_216 ( V_111 , V_159 -> V_179 ) ;
F_195 ( V_159 ) ;
F_217 ( & V_29 . V_30 ) ;
}
static int F_218 ( struct V_216 * V_217 , struct V_192 * V_104 ,
struct V_168 * V_111 )
{
int V_15 ;
unsigned V_218 ;
const char * V_219 ;
static struct V_220 V_221 [] = {
{ 0 , 4 , L_40 } ,
} ;
if ( ! V_217 -> V_218 )
return 0 ;
V_15 = F_219 ( V_221 , V_217 , & V_218 , & V_111 -> error ) ;
if ( V_15 )
return - V_107 ;
while ( V_218 && ! V_15 ) {
V_219 = F_220 ( V_217 ) ;
V_218 -- ;
if ( ! strcasecmp ( V_219 , L_41 ) )
V_104 -> V_105 = false ;
else if ( ! strcasecmp ( V_219 , L_42 ) )
V_104 -> V_193 = false ;
else if ( ! strcasecmp ( V_219 , L_43 ) )
V_104 -> V_123 = false ;
else if ( ! strcasecmp ( V_219 , L_44 ) )
V_104 -> V_156 = V_106 ;
else if ( ! strcasecmp ( V_219 , L_45 ) )
V_104 -> V_118 = true ;
else {
V_111 -> error = L_46 ;
V_15 = - V_107 ;
break;
}
}
return V_15 ;
}
static void F_221 ( void * V_67 )
{
struct V_9 * V_9 = V_67 ;
F_99 ( L_47 ,
F_100 ( V_9 -> V_36 ) ) ;
F_101 ( V_9 -> V_111 -> V_112 ) ;
}
static T_2 F_222 ( struct V_37 * V_49 )
{
return F_223 ( V_49 -> V_222 ) >> V_87 ;
}
static void F_224 ( struct V_37 * V_49 )
{
T_2 V_223 = F_222 ( V_49 ) ;
char V_224 [ V_189 ] ;
if ( V_223 > V_225 )
F_99 ( L_48 ,
F_184 ( V_49 , V_224 ) , V_226 ) ;
}
static T_2 F_225 ( struct V_37 * V_49 )
{
T_2 V_223 = F_222 ( V_49 ) ;
if ( V_223 > V_226 )
V_223 = V_226 ;
return V_223 ;
}
static T_1 F_226 ( struct V_37 * V_49 )
{
T_2 V_223 = F_225 ( V_49 ) ;
F_46 ( V_223 , V_227 ) ;
return V_223 ;
}
static T_1 F_227 ( struct V_158 * V_159 )
{
T_1 V_228 = F_226 ( V_159 -> V_194 -> V_49 ) / 4 ;
return F_228 ( ( T_1 ) 1024ULL , V_228 ) ;
}
static int F_229 ( struct V_168 * V_111 , unsigned V_218 , char * * V_229 )
{
int V_15 , V_230 = 0 ;
struct V_158 * V_159 ;
struct V_9 * V_9 ;
struct V_192 V_104 ;
struct V_216 V_217 ;
struct V_93 * V_179 ;
unsigned long V_181 ;
T_1 V_109 ;
struct V_93 * V_194 ;
T_6 V_231 ;
F_215 ( & V_29 . V_30 ) ;
if ( V_218 < 4 ) {
V_111 -> error = L_49 ;
V_15 = - V_107 ;
goto V_232;
}
V_217 . V_218 = V_218 ;
V_217 . V_229 = V_229 ;
F_187 ( & V_104 ) ;
F_230 ( & V_217 , 4 ) ;
V_15 = F_218 ( & V_217 , & V_104 , V_111 ) ;
if ( V_15 )
goto V_232;
V_231 = V_233 | ( ( V_104 . V_156 == V_106 ) ? 0 : V_234 ) ;
V_15 = F_231 ( V_111 , V_229 [ 0 ] , V_231 , & V_194 ) ;
if ( V_15 ) {
V_111 -> error = L_50 ;
goto V_232;
}
F_224 ( V_194 -> V_49 ) ;
V_15 = F_231 ( V_111 , V_229 [ 1 ] , V_233 | V_234 , & V_179 ) ;
if ( V_15 ) {
V_111 -> error = L_51 ;
goto V_235;
}
if ( F_232 ( V_229 [ 2 ] , 10 , & V_181 ) || ! V_181 ||
V_181 < V_236 ||
V_181 > V_237 ||
V_181 & ( V_236 - 1 ) ) {
V_111 -> error = L_52 ;
V_15 = - V_107 ;
goto V_74;
}
if ( F_233 ( V_229 [ 3 ] , 10 , ( unsigned long long * ) & V_109 ) ) {
V_111 -> error = L_53 ;
V_15 = - V_107 ;
goto V_74;
}
V_159 = F_234 ( sizeof( * V_159 ) , V_199 ) ;
if ( ! V_159 ) {
V_15 = - V_92 ;
goto V_74;
}
V_9 = F_213 ( F_235 ( V_111 -> V_112 ) , V_194 -> V_49 ,
V_181 , V_104 . V_156 == V_106 , & V_111 -> error , & V_230 ) ;
if ( F_198 ( V_9 ) ) {
V_15 = F_204 ( V_9 ) ;
goto V_238;
}
if ( ! V_230 && V_104 . V_193 != V_9 -> V_104 . V_193 ) {
V_111 -> error = L_54 ;
V_15 = - V_107 ;
goto V_239;
}
V_159 -> V_9 = V_9 ;
V_159 -> V_111 = V_111 ;
V_159 -> V_194 = V_194 ;
V_159 -> V_179 = V_179 ;
V_159 -> V_109 = V_109 ;
V_159 -> V_165 = V_159 -> V_240 = V_104 ;
V_111 -> V_241 = 1 ;
V_111 -> V_242 = true ;
if ( V_104 . V_193 && V_104 . V_123 ) {
V_111 -> V_243 = 1 ;
V_111 -> V_244 = true ;
}
V_111 -> V_160 = V_159 ;
V_15 = F_236 ( V_159 -> V_9 -> V_81 ,
F_227 ( V_159 ) ,
F_221 ,
V_9 ) ;
if ( V_15 )
goto V_238;
V_159 -> V_176 . V_245 = F_176 ;
F_237 ( V_111 -> V_112 , & V_159 -> V_176 ) ;
F_217 ( & V_29 . V_30 ) ;
return 0 ;
V_239:
F_212 ( V_9 ) ;
V_238:
F_195 ( V_159 ) ;
V_74:
F_216 ( V_111 , V_179 ) ;
V_235:
F_216 ( V_111 , V_194 ) ;
V_232:
F_217 ( & V_29 . V_30 ) ;
return V_15 ;
}
static int F_238 ( struct V_168 * V_111 , struct V_12 * V_12 )
{
int V_15 ;
struct V_158 * V_159 = V_111 -> V_160 ;
struct V_9 * V_9 = V_159 -> V_9 ;
unsigned long V_24 ;
F_15 ( & V_9 -> V_25 , V_24 ) ;
V_12 -> V_47 = V_159 -> V_179 -> V_49 ;
V_15 = V_171 ;
F_16 ( & V_9 -> V_25 , V_24 ) ;
return V_15 ;
}
static int F_239 ( struct V_168 * V_111 , bool * V_246 )
{
int V_15 ;
struct V_158 * V_159 = V_111 -> V_160 ;
struct V_9 * V_9 = V_159 -> V_9 ;
T_2 V_247 = V_111 -> V_248 ;
T_1 V_249 ;
* V_246 = false ;
( void ) F_46 ( V_247 , V_9 -> V_46 ) ;
V_15 = F_240 ( V_9 -> V_81 , & V_249 ) ;
if ( V_15 ) {
F_166 ( L_55 ,
F_100 ( V_9 -> V_36 ) ) ;
return V_15 ;
}
if ( V_247 < V_249 ) {
F_166 ( L_56 ,
F_100 ( V_9 -> V_36 ) ,
( unsigned long long ) V_247 , V_249 ) ;
return - V_107 ;
} else if ( V_247 > V_249 ) {
if ( F_164 ( V_9 -> V_81 ) ) {
F_166 ( L_57 ,
F_100 ( V_9 -> V_36 ) ) ;
return 0 ;
}
if ( V_249 )
F_163 ( L_58 ,
F_100 ( V_9 -> V_36 ) ,
V_249 , ( unsigned long long ) V_247 ) ;
V_15 = F_241 ( V_9 -> V_81 , V_247 ) ;
if ( V_15 ) {
F_71 ( V_9 , L_59 , V_15 ) ;
return V_15 ;
}
* V_246 = true ;
}
return 0 ;
}
static int F_242 ( struct V_168 * V_111 , bool * V_246 )
{
int V_15 ;
struct V_158 * V_159 = V_111 -> V_160 ;
struct V_9 * V_9 = V_159 -> V_9 ;
T_1 V_223 , V_250 ;
* V_246 = false ;
V_223 = F_226 ( V_9 -> V_38 ) ;
V_15 = F_243 ( V_9 -> V_81 , & V_250 ) ;
if ( V_15 ) {
F_166 ( L_60 ,
F_100 ( V_9 -> V_36 ) ) ;
return V_15 ;
}
if ( V_223 < V_250 ) {
F_166 ( L_61 ,
F_100 ( V_9 -> V_36 ) ,
V_223 , V_250 ) ;
return - V_107 ;
} else if ( V_223 > V_250 ) {
if ( F_164 ( V_9 -> V_81 ) ) {
F_166 ( L_62 ,
F_100 ( V_9 -> V_36 ) ) ;
return 0 ;
}
F_224 ( V_9 -> V_38 ) ;
F_163 ( L_63 ,
F_100 ( V_9 -> V_36 ) ,
V_250 , V_223 ) ;
V_15 = F_244 ( V_9 -> V_81 , V_223 ) ;
if ( V_15 ) {
F_71 ( V_9 , L_64 , V_15 ) ;
return V_15 ;
}
* V_246 = true ;
}
return 0 ;
}
static int F_245 ( struct V_168 * V_111 )
{
int V_15 ;
bool V_251 , V_252 ;
struct V_158 * V_159 = V_111 -> V_160 ;
struct V_9 * V_9 = V_159 -> V_9 ;
V_15 = F_185 ( V_9 , V_111 ) ;
if ( V_15 )
return V_15 ;
V_15 = F_239 ( V_111 , & V_251 ) ;
if ( V_15 )
return V_15 ;
V_15 = F_242 ( V_111 , & V_252 ) ;
if ( V_15 )
return V_15 ;
if ( V_251 || V_252 )
( void ) F_95 ( V_9 ) ;
return 0 ;
}
static void F_246 ( struct V_168 * V_111 )
{
struct V_158 * V_159 = V_111 -> V_160 ;
struct V_9 * V_9 = V_159 -> V_9 ;
unsigned long V_24 ;
F_15 ( & V_9 -> V_25 , V_24 ) ;
V_9 -> V_110 = false ;
F_16 ( & V_9 -> V_25 , V_24 ) ;
F_179 ( V_9 ) ;
F_148 ( & V_9 -> V_150 . V_253 ) ;
}
static void F_247 ( struct V_168 * V_111 )
{
struct V_158 * V_159 = V_111 -> V_160 ;
struct V_9 * V_9 = V_159 -> V_9 ;
F_248 ( & V_9 -> V_150 ) ;
F_248 ( & V_9 -> V_151 ) ;
F_249 ( V_9 -> V_10 ) ;
( void ) F_95 ( V_9 ) ;
}
static int F_250 ( unsigned V_218 , unsigned V_254 )
{
if ( V_218 != V_254 ) {
F_99 ( L_65 ,
V_218 , V_254 ) ;
return - V_107 ;
}
return 0 ;
}
static int F_251 ( char * V_255 , T_7 * V_256 , int V_257 )
{
if ( ! F_233 ( V_255 , 10 , ( unsigned long long * ) V_256 ) &&
* V_256 <= V_258 )
return 0 ;
if ( V_257 )
F_99 ( L_66 , V_255 ) ;
return - V_107 ;
}
static int F_252 ( unsigned V_218 , char * * V_229 , struct V_9 * V_9 )
{
T_7 V_256 ;
int V_15 ;
V_15 = F_250 ( V_218 , 2 ) ;
if ( V_15 )
return V_15 ;
V_15 = F_251 ( V_229 [ 1 ] , & V_256 , 1 ) ;
if ( V_15 )
return V_15 ;
V_15 = F_253 ( V_9 -> V_81 , V_256 ) ;
if ( V_15 ) {
F_99 ( L_67 ,
V_229 [ 1 ] ) ;
return V_15 ;
}
return 0 ;
}
static int F_254 ( unsigned V_218 , char * * V_229 , struct V_9 * V_9 )
{
T_7 V_256 ;
T_7 V_259 ;
int V_15 ;
V_15 = F_250 ( V_218 , 3 ) ;
if ( V_15 )
return V_15 ;
V_15 = F_251 ( V_229 [ 1 ] , & V_256 , 1 ) ;
if ( V_15 )
return V_15 ;
V_15 = F_251 ( V_229 [ 2 ] , & V_259 , 1 ) ;
if ( V_15 )
return V_15 ;
V_15 = F_255 ( V_9 -> V_81 , V_256 , V_259 ) ;
if ( V_15 ) {
F_99 ( L_68 ,
V_229 [ 1 ] , V_229 [ 2 ] ) ;
return V_15 ;
}
return 0 ;
}
static int F_256 ( unsigned V_218 , char * * V_229 , struct V_9 * V_9 )
{
T_7 V_256 ;
int V_15 ;
V_15 = F_250 ( V_218 , 2 ) ;
if ( V_15 )
return V_15 ;
V_15 = F_251 ( V_229 [ 1 ] , & V_256 , 1 ) ;
if ( V_15 )
return V_15 ;
V_15 = F_257 ( V_9 -> V_81 , V_256 ) ;
if ( V_15 )
F_99 ( L_69 , V_229 [ 1 ] ) ;
return V_15 ;
}
static int F_258 ( unsigned V_218 , char * * V_229 , struct V_9 * V_9 )
{
T_7 V_260 , V_261 ;
int V_15 ;
V_15 = F_250 ( V_218 , 3 ) ;
if ( V_15 )
return V_15 ;
if ( F_233 ( V_229 [ 1 ] , 10 , ( unsigned long long * ) & V_260 ) ) {
F_99 ( L_70 , V_229 [ 1 ] ) ;
return - V_107 ;
}
if ( F_233 ( V_229 [ 2 ] , 10 , ( unsigned long long * ) & V_261 ) ) {
F_99 ( L_71 , V_229 [ 2 ] ) ;
return - V_107 ;
}
V_15 = F_259 ( V_9 -> V_81 , V_260 , V_261 ) ;
if ( V_15 ) {
F_99 ( L_72 ,
V_229 [ 1 ] , V_229 [ 2 ] ) ;
return V_15 ;
}
return 0 ;
}
static int F_260 ( unsigned V_218 , char * * V_229 , struct V_9 * V_9 )
{
int V_15 ;
V_15 = F_250 ( V_218 , 1 ) ;
if ( V_15 )
return V_15 ;
( void ) F_95 ( V_9 ) ;
V_15 = F_261 ( V_9 -> V_81 ) ;
if ( V_15 )
F_99 ( L_73 ) ;
return V_15 ;
}
static int F_262 ( unsigned V_218 , char * * V_229 , struct V_9 * V_9 )
{
int V_15 ;
V_15 = F_250 ( V_218 , 1 ) ;
if ( V_15 )
return V_15 ;
V_15 = F_263 ( V_9 -> V_81 ) ;
if ( V_15 )
F_99 ( L_74 ) ;
return V_15 ;
}
static int F_264 ( struct V_168 * V_111 , unsigned V_218 , char * * V_229 )
{
int V_15 = - V_107 ;
struct V_158 * V_159 = V_111 -> V_160 ;
struct V_9 * V_9 = V_159 -> V_9 ;
if ( ! strcasecmp ( V_229 [ 0 ] , L_75 ) )
V_15 = F_252 ( V_218 , V_229 , V_9 ) ;
else if ( ! strcasecmp ( V_229 [ 0 ] , L_76 ) )
V_15 = F_254 ( V_218 , V_229 , V_9 ) ;
else if ( ! strcasecmp ( V_229 [ 0 ] , L_77 ) )
V_15 = F_256 ( V_218 , V_229 , V_9 ) ;
else if ( ! strcasecmp ( V_229 [ 0 ] , L_78 ) )
V_15 = F_258 ( V_218 , V_229 , V_9 ) ;
else if ( ! strcasecmp ( V_229 [ 0 ] , L_79 ) )
V_15 = F_260 ( V_218 , V_229 , V_9 ) ;
else if ( ! strcasecmp ( V_229 [ 0 ] , L_80 ) )
V_15 = F_262 ( V_218 , V_229 , V_9 ) ;
else
F_99 ( L_81 , V_229 [ 0 ] ) ;
if ( ! V_15 )
( void ) F_95 ( V_9 ) ;
return V_15 ;
}
static void F_265 ( struct V_192 * V_104 , char * V_113 ,
unsigned V_262 , unsigned V_263 )
{
unsigned V_102 = ! V_104 -> V_105 + ! V_104 -> V_193 +
! V_104 -> V_123 + ( V_104 -> V_156 == V_106 ) +
V_104 -> V_118 ;
F_266 ( L_82 , V_102 ) ;
if ( ! V_104 -> V_105 )
F_266 ( L_83 ) ;
if ( ! V_104 -> V_193 )
F_266 ( L_84 ) ;
if ( ! V_104 -> V_123 )
F_266 ( L_85 ) ;
if ( V_104 -> V_156 == V_106 )
F_266 ( L_86 ) ;
if ( V_104 -> V_118 )
F_266 ( L_87 ) ;
}
static void F_267 ( struct V_168 * V_111 , T_8 type ,
unsigned V_264 , char * V_113 , unsigned V_263 )
{
int V_15 ;
unsigned V_262 = 0 ;
T_9 V_265 ;
T_1 V_266 ;
T_1 V_267 ;
T_1 V_268 ;
T_1 V_269 ;
T_1 V_270 ;
char V_188 [ V_189 ] ;
char V_271 [ V_189 ] ;
struct V_158 * V_159 = V_111 -> V_160 ;
struct V_9 * V_9 = V_159 -> V_9 ;
switch ( type ) {
case V_272 :
if ( F_96 ( V_9 ) == V_119 ) {
F_266 ( L_88 ) ;
break;
}
if ( ! ( V_264 & V_273 ) && ! F_268 ( V_111 ) )
( void ) F_95 ( V_9 ) ;
V_15 = F_269 ( V_9 -> V_81 , & V_265 ) ;
if ( V_15 ) {
F_166 ( L_89 ,
F_100 ( V_9 -> V_36 ) , V_15 ) ;
goto V_68;
}
V_15 = F_270 ( V_9 -> V_81 , & V_267 ) ;
if ( V_15 ) {
F_166 ( L_90 ,
F_100 ( V_9 -> V_36 ) , V_15 ) ;
goto V_68;
}
V_15 = F_243 ( V_9 -> V_81 , & V_269 ) ;
if ( V_15 ) {
F_166 ( L_91 ,
F_100 ( V_9 -> V_36 ) , V_15 ) ;
goto V_68;
}
V_15 = F_104 ( V_9 -> V_81 , & V_266 ) ;
if ( V_15 ) {
F_166 ( L_92 ,
F_100 ( V_9 -> V_36 ) , V_15 ) ;
goto V_68;
}
V_15 = F_240 ( V_9 -> V_81 , & V_268 ) ;
if ( V_15 ) {
F_166 ( L_93 ,
F_100 ( V_9 -> V_36 ) , V_15 ) ;
goto V_68;
}
V_15 = F_271 ( V_9 -> V_81 , & V_270 ) ;
if ( V_15 ) {
F_166 ( L_94 ,
F_100 ( V_9 -> V_36 ) , V_15 ) ;
goto V_68;
}
F_266 ( L_95 ,
( unsigned long long ) V_265 ,
( unsigned long long ) ( V_269 - V_267 ) ,
( unsigned long long ) V_269 ,
( unsigned long long ) ( V_268 - V_266 ) ,
( unsigned long long ) V_268 ) ;
if ( V_270 )
F_266 ( L_96 , V_270 ) ;
else
F_266 ( L_97 ) ;
if ( V_9 -> V_104 . V_156 == V_115 )
F_266 ( L_98 ) ;
else if ( V_9 -> V_104 . V_156 == V_106 )
F_266 ( L_99 ) ;
else
F_266 ( L_100 ) ;
if ( ! V_9 -> V_104 . V_193 )
F_266 ( L_84 ) ;
else if ( V_9 -> V_104 . V_123 )
F_266 ( L_101 ) ;
else
F_266 ( L_85 ) ;
if ( V_9 -> V_104 . V_118 )
F_266 ( L_87 ) ;
else
F_266 ( L_102 ) ;
break;
case V_274 :
F_266 ( L_103 ,
F_272 ( V_188 , V_159 -> V_194 -> V_49 -> V_275 ) ,
F_272 ( V_271 , V_159 -> V_179 -> V_49 -> V_275 ) ,
( unsigned long ) V_9 -> V_46 ,
( unsigned long long ) V_159 -> V_109 ) ;
F_265 ( & V_159 -> V_240 , V_113 , V_262 , V_263 ) ;
break;
}
return;
V_68:
F_266 ( L_104 ) ;
}
static int F_273 ( struct V_168 * V_111 ,
T_10 V_84 , void * V_276 )
{
struct V_158 * V_159 = V_111 -> V_160 ;
return V_84 ( V_111 , V_159 -> V_179 , 0 , V_111 -> V_248 , V_276 ) ;
}
static int F_274 ( struct V_168 * V_111 , struct V_277 * V_278 ,
struct V_279 * V_280 , int V_281 )
{
struct V_158 * V_159 = V_111 -> V_160 ;
struct V_177 * V_178 = F_177 ( V_159 -> V_179 -> V_49 ) ;
if ( ! V_178 -> V_282 )
return V_281 ;
V_278 -> V_47 = V_159 -> V_179 -> V_49 ;
return F_228 ( V_281 , V_178 -> V_282 ( V_178 , V_278 , V_280 ) ) ;
}
static void F_275 ( struct V_158 * V_159 , struct V_184 * V_186 )
{
struct V_9 * V_9 = V_159 -> V_9 ;
struct V_184 * V_185 ;
V_186 -> V_190 = V_9 -> V_46 ;
if ( V_159 -> V_165 . V_123 ) {
V_185 = & F_177 ( V_159 -> V_179 -> V_49 ) -> V_186 ;
V_186 -> V_191 = F_276 ( V_185 -> V_191 ,
V_9 -> V_46 << V_87 ) ;
} else
V_186 -> V_191 = V_9 -> V_46 << V_87 ;
}
static void F_277 ( struct V_168 * V_111 , struct V_184 * V_186 )
{
struct V_158 * V_159 = V_111 -> V_160 ;
struct V_9 * V_9 = V_159 -> V_9 ;
T_9 V_283 = V_186 -> V_284 >> V_87 ;
if ( V_283 < V_9 -> V_46 ||
F_278 ( V_283 , V_9 -> V_46 ) ) {
F_279 ( V_186 , 0 ) ;
F_280 ( V_186 , V_9 -> V_46 << V_87 ) ;
}
if ( ! V_159 -> V_165 . V_193 ) {
V_186 -> V_191 = 0 ;
return;
}
F_183 ( V_159 ) ;
F_275 ( V_159 , V_186 ) ;
}
static void F_140 ( struct V_22 * V_23 )
{
F_67 ( & V_23 -> V_285 ) ;
}
static void F_143 ( struct V_22 * V_23 )
{
if ( F_281 ( & V_23 -> V_285 ) )
F_154 ( & V_23 -> V_286 ) ;
}
static void F_282 ( struct V_168 * V_111 )
{
struct V_22 * V_23 = V_111 -> V_160 ;
unsigned long V_24 ;
F_143 ( V_23 ) ;
F_158 ( & V_23 -> V_286 ) ;
F_15 ( & V_23 -> V_9 -> V_25 , V_24 ) ;
F_283 ( & V_23 -> V_32 ) ;
F_16 ( & V_23 -> V_9 -> V_25 , V_24 ) ;
F_284 () ;
F_215 ( & V_29 . V_30 ) ;
F_212 ( V_23 -> V_9 ) ;
F_285 ( V_23 -> V_2 ) ;
F_216 ( V_111 , V_23 -> V_48 ) ;
if ( V_23 -> V_50 )
F_216 ( V_111 , V_23 -> V_50 ) ;
F_195 ( V_23 ) ;
F_217 ( & V_29 . V_30 ) ;
}
static int F_286 ( struct V_168 * V_111 , unsigned V_218 , char * * V_229 )
{
int V_15 ;
struct V_22 * V_23 ;
struct V_93 * V_48 , * V_50 ;
struct V_33 * V_36 ;
unsigned long V_24 ;
F_215 ( & V_29 . V_30 ) ;
if ( V_218 != 2 && V_218 != 3 ) {
V_111 -> error = L_49 ;
V_15 = - V_107 ;
goto V_232;
}
V_23 = V_111 -> V_160 = F_234 ( sizeof( * V_23 ) , V_199 ) ;
if ( ! V_23 ) {
V_111 -> error = L_105 ;
V_15 = - V_92 ;
goto V_232;
}
F_208 ( & V_23 -> V_25 ) ;
F_33 ( & V_23 -> V_26 ) ;
F_33 ( & V_23 -> V_41 ) ;
V_23 -> V_138 = V_287 ;
if ( V_218 == 3 ) {
V_15 = F_231 ( V_111 , V_229 [ 2 ] , V_233 , & V_50 ) ;
if ( V_15 ) {
V_111 -> error = L_106 ;
goto V_288;
}
V_23 -> V_50 = V_50 ;
}
V_15 = F_231 ( V_111 , V_229 [ 0 ] , F_287 ( V_111 -> V_112 ) , & V_48 ) ;
if ( V_15 ) {
V_111 -> error = L_107 ;
goto V_289;
}
V_23 -> V_48 = V_48 ;
if ( F_251 ( V_229 [ 1 ] , ( unsigned long long * ) & V_23 -> V_256 , 0 ) ) {
V_111 -> error = L_108 ;
V_15 = - V_107 ;
goto V_290;
}
V_36 = F_288 ( V_23 -> V_48 -> V_49 -> V_275 ) ;
if ( ! V_36 ) {
V_111 -> error = L_109 ;
V_15 = - V_107 ;
goto V_290;
}
V_23 -> V_9 = F_29 ( V_36 ) ;
if ( ! V_23 -> V_9 ) {
V_111 -> error = L_110 ;
V_15 = - V_107 ;
goto V_291;
}
F_211 ( V_23 -> V_9 ) ;
if ( F_96 ( V_23 -> V_9 ) == V_119 ) {
V_111 -> error = L_111 ;
V_15 = - V_107 ;
goto V_292;
}
V_15 = F_289 ( V_23 -> V_9 -> V_81 , V_23 -> V_256 , & V_23 -> V_2 ) ;
if ( V_15 ) {
V_111 -> error = L_112 ;
goto V_292;
}
V_15 = F_290 ( V_111 , V_23 -> V_9 -> V_46 ) ;
if ( V_15 )
goto V_293;
V_111 -> V_241 = 1 ;
V_111 -> V_294 = true ;
V_111 -> V_295 = sizeof( struct V_54 ) ;
V_111 -> V_242 = true ;
if ( V_23 -> V_9 -> V_104 . V_193 ) {
V_111 -> V_244 = true ;
V_111 -> V_243 = 1 ;
V_111 -> V_296 = true ;
}
F_291 ( V_36 ) ;
F_217 ( & V_29 . V_30 ) ;
F_292 ( & V_23 -> V_285 , 1 ) ;
F_157 ( & V_23 -> V_286 ) ;
F_15 ( & V_23 -> V_9 -> V_25 , V_24 ) ;
F_293 ( & V_23 -> V_32 , & V_23 -> V_9 -> V_145 ) ;
F_16 ( & V_23 -> V_9 -> V_25 , V_24 ) ;
F_284 () ;
return 0 ;
V_293:
F_285 ( V_23 -> V_2 ) ;
V_292:
F_212 ( V_23 -> V_9 ) ;
V_291:
F_291 ( V_36 ) ;
V_290:
F_216 ( V_111 , V_23 -> V_48 ) ;
V_289:
if ( V_23 -> V_50 )
F_216 ( V_111 , V_23 -> V_50 ) ;
V_288:
F_195 ( V_23 ) ;
V_232:
F_217 ( & V_29 . V_30 ) ;
return V_15 ;
}
static int F_294 ( struct V_168 * V_111 , struct V_12 * V_12 )
{
V_12 -> V_44 . V_45 = F_295 ( V_111 , V_12 -> V_44 . V_45 ) ;
return F_174 ( V_111 , V_12 ) ;
}
static int F_296 ( struct V_168 * V_111 , struct V_12 * V_12 , int V_68 )
{
unsigned long V_24 ;
struct V_54 * V_55 = F_52 ( V_12 , sizeof( struct V_54 ) ) ;
struct V_82 V_253 ;
struct V_60 * V_61 , * V_35 ;
struct V_9 * V_9 = V_55 -> V_23 -> V_9 ;
if ( V_55 -> V_128 ) {
F_22 ( & V_253 ) ;
F_297 ( V_55 -> V_128 , & V_253 ) ;
F_15 ( & V_9 -> V_25 , V_24 ) ;
F_80 (m, tmp, &work, list) {
F_28 ( & V_61 -> V_32 ) ;
V_61 -> V_62 = true ;
F_60 ( V_61 ) ;
}
F_16 ( & V_9 -> V_25 , V_24 ) ;
}
if ( V_55 -> V_57 ) {
F_22 ( & V_253 ) ;
F_297 ( V_55 -> V_57 , & V_253 ) ;
if ( ! F_138 ( & V_253 ) ) {
F_15 ( & V_9 -> V_25 , V_24 ) ;
F_80 (m, tmp, &work, list)
F_61 ( & V_61 -> V_32 , & V_9 -> V_125 ) ;
F_16 ( & V_9 -> V_25 , V_24 ) ;
F_4 ( V_9 ) ;
}
}
return 0 ;
}
static void F_298 ( struct V_168 * V_111 )
{
struct V_22 * V_23 = V_111 -> V_160 ;
if ( F_299 ( V_111 ) )
V_154 ( V_23 , F_160 ) ;
}
static void F_300 ( struct V_168 * V_111 )
{
struct V_22 * V_23 = V_111 -> V_160 ;
V_154 ( V_23 , F_161 ) ;
}
static void F_301 ( struct V_168 * V_111 , T_8 type ,
unsigned V_264 , char * V_113 , unsigned V_263 )
{
int V_15 ;
T_11 V_262 = 0 ;
T_1 V_297 , V_298 ;
char V_188 [ V_189 ] ;
struct V_22 * V_23 = V_111 -> V_160 ;
if ( F_96 ( V_23 -> V_9 ) == V_119 ) {
F_266 ( L_88 ) ;
return;
}
if ( ! V_23 -> V_2 )
F_266 ( L_113 ) ;
else {
switch ( type ) {
case V_272 :
V_15 = F_302 ( V_23 -> V_2 , & V_297 ) ;
if ( V_15 ) {
F_166 ( L_114 , V_15 ) ;
goto V_68;
}
V_15 = F_303 ( V_23 -> V_2 , & V_298 ) ;
if ( V_15 < 0 ) {
F_166 ( L_115 , V_15 ) ;
goto V_68;
}
F_266 ( L_96 , V_297 * V_23 -> V_9 -> V_46 ) ;
if ( V_15 )
F_266 ( L_116 , ( ( V_298 + 1 ) *
V_23 -> V_9 -> V_46 ) - 1 ) ;
else
F_266 ( L_113 ) ;
break;
case V_274 :
F_266 ( L_117 ,
F_272 ( V_188 , V_23 -> V_48 -> V_49 -> V_275 ) ,
( unsigned long ) V_23 -> V_256 ) ;
if ( V_23 -> V_50 )
F_266 ( L_118 , F_272 ( V_188 , V_23 -> V_50 -> V_49 -> V_275 ) ) ;
break;
}
}
return;
V_68:
F_266 ( L_104 ) ;
}
static int F_304 ( struct V_168 * V_111 ,
T_10 V_84 , void * V_276 )
{
T_2 V_299 ;
struct V_22 * V_23 = V_111 -> V_160 ;
struct V_9 * V_9 = V_23 -> V_9 ;
if ( ! V_9 -> V_111 )
return 0 ;
V_299 = V_9 -> V_111 -> V_248 ;
( void ) F_46 ( V_299 , V_9 -> V_46 ) ;
if ( V_299 )
return V_84 ( V_111 , V_23 -> V_48 , 0 , V_9 -> V_46 * V_299 , V_276 ) ;
return 0 ;
}
static int T_12 F_305 ( void )
{
int V_15 ;
F_20 () ;
V_15 = F_306 ( & V_300 ) ;
if ( V_15 )
return V_15 ;
V_15 = F_306 ( & V_301 ) ;
if ( V_15 )
goto V_302;
V_15 = - V_92 ;
V_211 = F_307 ( V_60 , 0 ) ;
if ( ! V_211 )
goto V_303;
return 0 ;
V_303:
F_308 ( & V_301 ) ;
V_302:
F_308 ( & V_300 ) ;
return V_15 ;
}
static void F_309 ( void )
{
F_308 ( & V_300 ) ;
F_308 ( & V_301 ) ;
F_310 ( V_211 ) ;
}
