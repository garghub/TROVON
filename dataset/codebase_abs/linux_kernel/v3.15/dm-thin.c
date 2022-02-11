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
struct V_13 * V_19 )
{
F_18 ( V_9 -> V_17 , V_19 ) ;
F_9 ( V_9 -> V_17 , V_19 ) ;
}
static void F_19 ( void )
{
F_20 ( & V_27 . V_28 ) ;
F_21 ( & V_27 . V_29 ) ;
}
static void F_22 ( struct V_9 * V_9 )
{
F_23 ( ! F_24 ( & V_27 . V_28 ) ) ;
F_25 ( & V_9 -> V_30 , & V_27 . V_29 ) ;
}
static void F_26 ( struct V_9 * V_9 )
{
F_23 ( ! F_24 ( & V_27 . V_28 ) ) ;
F_27 ( & V_9 -> V_30 ) ;
}
static struct V_9 * F_28 ( struct V_31 * V_32 )
{
struct V_9 * V_9 = NULL , * V_33 ;
F_23 ( ! F_24 ( & V_27 . V_28 ) ) ;
F_29 (tmp, &dm_thin_pool_table.pools, list) {
if ( V_33 -> V_34 == V_32 ) {
V_9 = V_33 ;
break;
}
}
return V_9 ;
}
static struct V_9 * F_30 ( struct V_35 * V_36 )
{
struct V_9 * V_9 = NULL , * V_33 ;
F_23 ( ! F_24 ( & V_27 . V_28 ) ) ;
F_29 (tmp, &dm_thin_pool_table.pools, list) {
if ( V_33 -> V_36 == V_36 ) {
V_9 = V_33 ;
break;
}
}
return V_9 ;
}
static void F_31 ( struct V_22 * V_23 , struct V_20 * V_37 )
{
struct V_12 * V_12 ;
struct V_20 V_21 ;
unsigned long V_24 ;
F_32 ( & V_21 ) ;
F_15 ( & V_23 -> V_25 , V_24 ) ;
F_33 ( & V_21 , V_37 ) ;
F_32 ( V_37 ) ;
F_16 ( & V_23 -> V_25 , V_24 ) ;
while ( ( V_12 = F_34 ( & V_21 ) ) )
F_35 ( V_12 , V_38 ) ;
}
static void F_36 ( struct V_22 * V_23 )
{
F_31 ( V_23 , & V_23 -> V_26 ) ;
F_31 ( V_23 , & V_23 -> V_39 ) ;
}
static void F_37 ( struct V_22 * V_23 )
{
struct V_12 * V_12 ;
unsigned long V_24 ;
struct V_20 V_21 ;
F_32 ( & V_21 ) ;
F_15 ( & V_23 -> V_25 , V_24 ) ;
F_33 ( & V_21 , & V_23 -> V_39 ) ;
F_32 ( & V_23 -> V_39 ) ;
F_16 ( & V_23 -> V_25 , V_24 ) ;
while ( ( V_12 = F_34 ( & V_21 ) ) )
F_38 ( V_12 ) ;
}
static void F_39 ( struct V_9 * V_9 )
{
struct V_22 * V_23 ;
F_40 () ;
F_41 (tc, &pool->active_thins, list)
F_37 ( V_23 ) ;
F_42 () ;
}
static bool F_43 ( struct V_9 * V_9 )
{
return V_9 -> V_40 >= 0 ;
}
static T_1 F_44 ( struct V_22 * V_23 , struct V_12 * V_12 )
{
struct V_9 * V_9 = V_23 -> V_9 ;
T_2 V_41 = V_12 -> V_42 . V_43 ;
if ( F_43 ( V_9 ) )
V_41 >>= V_9 -> V_40 ;
else
( void ) F_45 ( V_41 , V_9 -> V_44 ) ;
return V_41 ;
}
static void F_46 ( struct V_22 * V_23 , struct V_12 * V_12 , T_1 V_8 )
{
struct V_9 * V_9 = V_23 -> V_9 ;
T_2 V_43 = V_12 -> V_42 . V_43 ;
V_12 -> V_45 = V_23 -> V_46 -> V_47 ;
if ( F_43 ( V_9 ) )
V_12 -> V_42 . V_43 =
( V_8 << V_9 -> V_40 ) |
( V_43 & ( V_9 -> V_44 - 1 ) ) ;
else
V_12 -> V_42 . V_43 = ( V_8 * V_9 -> V_44 ) +
F_45 ( V_43 , V_9 -> V_44 ) ;
}
static void F_47 ( struct V_22 * V_23 , struct V_12 * V_12 )
{
V_12 -> V_45 = V_23 -> V_48 -> V_47 ;
}
static int F_48 ( struct V_22 * V_23 , struct V_12 * V_12 )
{
return ( V_12 -> V_49 & ( V_50 | V_51 ) ) &&
F_49 ( V_23 -> V_2 ) ;
}
static void F_50 ( struct V_9 * V_9 , struct V_12 * V_12 )
{
struct V_52 * V_53 ;
if ( V_12 -> V_49 & V_54 )
return;
V_53 = F_51 ( V_12 , sizeof( struct V_52 ) ) ;
V_53 -> V_55 = F_52 ( V_9 -> V_56 ) ;
}
static void F_53 ( struct V_22 * V_23 , struct V_12 * V_12 )
{
struct V_9 * V_9 = V_23 -> V_9 ;
unsigned long V_24 ;
if ( ! F_48 ( V_23 , V_12 ) ) {
F_54 ( V_12 ) ;
return;
}
if ( F_55 ( V_23 -> V_2 ) ) {
F_38 ( V_12 ) ;
return;
}
F_15 ( & V_9 -> V_25 , V_24 ) ;
F_56 ( & V_9 -> V_57 , V_12 ) ;
F_16 ( & V_9 -> V_25 , V_24 ) ;
}
static void F_57 ( struct V_22 * V_23 , struct V_12 * V_12 )
{
F_47 ( V_23 , V_12 ) ;
F_53 ( V_23 , V_12 ) ;
}
static void F_58 ( struct V_22 * V_23 , struct V_12 * V_12 ,
T_1 V_8 )
{
F_46 ( V_23 , V_12 , V_8 ) ;
F_53 ( V_23 , V_12 ) ;
}
static void F_59 ( struct V_58 * V_59 )
{
struct V_9 * V_9 = V_59 -> V_23 -> V_9 ;
if ( V_59 -> V_60 && V_59 -> V_61 ) {
F_60 ( & V_59 -> V_30 , & V_9 -> V_62 ) ;
F_4 ( V_9 ) ;
}
}
static void F_61 ( int V_63 , unsigned long V_64 , void * V_65 )
{
unsigned long V_24 ;
struct V_58 * V_59 = V_65 ;
struct V_9 * V_9 = V_59 -> V_23 -> V_9 ;
V_59 -> V_66 = V_63 || V_64 ? - V_67 : 0 ;
F_15 ( & V_9 -> V_25 , V_24 ) ;
V_59 -> V_61 = true ;
F_59 ( V_59 ) ;
F_16 ( & V_9 -> V_25 , V_24 ) ;
}
static void F_62 ( struct V_12 * V_12 , int V_66 )
{
unsigned long V_24 ;
struct V_52 * V_53 = F_51 ( V_12 , sizeof( struct V_52 ) ) ;
struct V_58 * V_59 = V_53 -> V_68 ;
struct V_9 * V_9 = V_59 -> V_23 -> V_9 ;
V_59 -> V_66 = V_66 ;
F_15 ( & V_9 -> V_25 , V_24 ) ;
V_59 -> V_61 = true ;
F_59 ( V_59 ) ;
F_16 ( & V_9 -> V_25 , V_24 ) ;
}
static void F_63 ( struct V_22 * V_23 , struct V_13 * V_19 )
{
struct V_9 * V_9 = V_23 -> V_9 ;
unsigned long V_24 ;
F_15 ( & V_23 -> V_25 , V_24 ) ;
F_10 ( V_9 , V_19 , & V_23 -> V_26 ) ;
F_16 ( & V_23 -> V_25 , V_24 ) ;
F_4 ( V_9 ) ;
}
static void F_64 ( struct V_22 * V_23 , struct V_13 * V_19 )
{
struct V_9 * V_9 = V_23 -> V_9 ;
unsigned long V_24 ;
F_15 ( & V_23 -> V_25 , V_24 ) ;
F_12 ( V_9 , V_19 , & V_23 -> V_26 ) ;
F_16 ( & V_23 -> V_25 , V_24 ) ;
F_4 ( V_9 ) ;
}
static void F_65 ( struct V_58 * V_59 )
{
if ( V_59 -> V_12 ) {
V_59 -> V_12 -> V_69 = V_59 -> V_70 ;
F_66 ( & V_59 -> V_12 -> V_71 ) ;
}
F_17 ( V_59 -> V_23 -> V_9 , V_59 -> V_19 ) ;
F_27 ( & V_59 -> V_30 ) ;
F_67 ( V_59 , V_59 -> V_23 -> V_9 -> V_72 ) ;
}
static void F_68 ( struct V_58 * V_59 )
{
struct V_22 * V_23 = V_59 -> V_23 ;
struct V_9 * V_9 = V_23 -> V_9 ;
struct V_12 * V_12 ;
int V_15 ;
V_12 = V_59 -> V_12 ;
if ( V_12 ) {
V_12 -> V_69 = V_59 -> V_70 ;
F_66 ( & V_12 -> V_71 ) ;
}
if ( V_59 -> V_66 ) {
F_17 ( V_9 , V_59 -> V_19 ) ;
goto V_73;
}
V_15 = F_69 ( V_23 -> V_2 , V_59 -> V_74 , V_59 -> V_75 ) ;
if ( V_15 ) {
F_70 ( V_9 , L_1 , V_15 ) ;
F_17 ( V_9 , V_59 -> V_19 ) ;
goto V_73;
}
if ( V_12 ) {
F_64 ( V_23 , V_59 -> V_19 ) ;
F_35 ( V_12 , 0 ) ;
} else
F_63 ( V_23 , V_59 -> V_19 ) ;
V_73:
F_27 ( & V_59 -> V_30 ) ;
F_67 ( V_59 , V_9 -> V_72 ) ;
}
static void F_71 ( struct V_58 * V_59 )
{
struct V_22 * V_23 = V_59 -> V_23 ;
F_38 ( V_59 -> V_12 ) ;
F_64 ( V_23 , V_59 -> V_19 ) ;
F_64 ( V_23 , V_59 -> V_76 ) ;
F_67 ( V_59 , V_23 -> V_9 -> V_72 ) ;
}
static void F_72 ( struct V_58 * V_59 )
{
struct V_22 * V_23 = V_59 -> V_23 ;
F_50 ( V_23 -> V_9 , V_59 -> V_12 ) ;
F_64 ( V_23 , V_59 -> V_19 ) ;
F_64 ( V_23 , V_59 -> V_76 ) ;
if ( V_59 -> V_77 )
if ( V_59 -> V_78 )
F_58 ( V_23 , V_59 -> V_12 , V_59 -> V_75 ) ;
else {
bool V_79 = false ;
if ( F_73 ( V_23 -> V_9 -> V_80 , V_59 -> V_75 , & V_79 ) || V_79 )
F_35 ( V_59 -> V_12 , 0 ) ;
else
F_58 ( V_23 , V_59 -> V_12 , V_59 -> V_75 ) ;
}
else
F_35 ( V_59 -> V_12 , 0 ) ;
F_67 ( V_59 , V_23 -> V_9 -> V_72 ) ;
}
static void F_74 ( struct V_58 * V_59 )
{
int V_15 ;
struct V_22 * V_23 = V_59 -> V_23 ;
V_15 = F_75 ( V_23 -> V_2 , V_59 -> V_74 ) ;
if ( V_15 )
F_76 ( L_2 ) ;
F_72 ( V_59 ) ;
}
static void F_77 ( struct V_9 * V_9 , struct V_81 * V_82 ,
T_3 * V_83 )
{
unsigned long V_24 ;
struct V_81 V_84 ;
struct V_58 * V_59 , * V_33 ;
F_21 ( & V_84 ) ;
F_15 ( & V_9 -> V_25 , V_24 ) ;
F_78 ( V_82 , & V_84 ) ;
F_16 ( & V_9 -> V_25 , V_24 ) ;
F_79 ( V_59 , V_33 , & V_84 , V_30 )
( * V_83 ) ( V_59 ) ;
}
static int F_80 ( struct V_9 * V_9 , struct V_12 * V_12 )
{
return V_12 -> V_42 . V_85 ==
( V_9 -> V_44 << V_86 ) ;
}
static int F_81 ( struct V_9 * V_9 , struct V_12 * V_12 )
{
return ( F_82 ( V_12 ) == V_87 ) &&
F_80 ( V_9 , V_12 ) ;
}
static void F_83 ( struct V_12 * V_12 , T_4 * * V_88 ,
T_4 * V_83 )
{
* V_88 = V_12 -> V_69 ;
V_12 -> V_69 = V_83 ;
}
static int F_84 ( struct V_9 * V_9 )
{
if ( V_9 -> V_89 )
return 0 ;
V_9 -> V_89 = F_85 ( V_9 -> V_72 , V_90 ) ;
return V_9 -> V_89 ? 0 : - V_91 ;
}
static struct V_58 * F_86 ( struct V_9 * V_9 )
{
struct V_58 * V_59 = V_9 -> V_89 ;
F_23 ( ! V_9 -> V_89 ) ;
memset ( V_59 , 0 , sizeof( struct V_58 ) ) ;
F_21 ( & V_59 -> V_30 ) ;
V_59 -> V_12 = NULL ;
V_9 -> V_89 = NULL ;
return V_59 ;
}
static void F_87 ( struct V_22 * V_23 , T_1 V_74 ,
struct V_92 * V_93 , T_1 V_94 ,
T_1 V_95 ,
struct V_13 * V_19 , struct V_12 * V_12 )
{
int V_15 ;
struct V_9 * V_9 = V_23 -> V_9 ;
struct V_58 * V_59 = F_86 ( V_9 ) ;
V_59 -> V_23 = V_23 ;
V_59 -> V_74 = V_74 ;
V_59 -> V_75 = V_95 ;
V_59 -> V_19 = V_19 ;
if ( ! F_88 ( V_9 -> V_96 , & V_59 -> V_30 ) )
V_59 -> V_60 = true ;
if ( F_81 ( V_9 , V_12 ) ) {
struct V_52 * V_53 = F_51 ( V_12 , sizeof( struct V_52 ) ) ;
V_53 -> V_68 = V_59 ;
V_59 -> V_12 = V_12 ;
F_83 ( V_12 , & V_59 -> V_70 , F_62 ) ;
F_50 ( V_9 , V_12 ) ;
F_58 ( V_23 , V_12 , V_95 ) ;
} else {
struct V_97 V_98 , V_99 ;
V_98 . V_47 = V_93 -> V_47 ;
V_98 . V_100 = V_94 * V_9 -> V_44 ;
V_98 . V_101 = V_9 -> V_44 ;
V_99 . V_47 = V_23 -> V_46 -> V_47 ;
V_99 . V_100 = V_95 * V_9 -> V_44 ;
V_99 . V_101 = V_9 -> V_44 ;
V_15 = F_89 ( V_9 -> V_102 , & V_98 , 1 , & V_99 ,
0 , F_61 , V_59 ) ;
if ( V_15 < 0 ) {
F_67 ( V_59 , V_9 -> V_72 ) ;
F_76 ( L_3 ) ;
F_17 ( V_9 , V_19 ) ;
}
}
}
static void F_90 ( struct V_22 * V_23 , T_1 V_74 ,
T_1 V_94 , T_1 V_95 ,
struct V_13 * V_19 , struct V_12 * V_12 )
{
F_87 ( V_23 , V_74 , V_23 -> V_46 ,
V_94 , V_95 , V_19 , V_12 ) ;
}
static void F_91 ( struct V_22 * V_23 , T_1 V_74 ,
T_1 V_95 ,
struct V_13 * V_19 , struct V_12 * V_12 )
{
F_87 ( V_23 , V_74 , V_23 -> V_48 ,
V_74 , V_95 , V_19 , V_12 ) ;
}
static void F_92 ( struct V_22 * V_23 , T_1 V_74 ,
T_1 V_75 , struct V_13 * V_19 ,
struct V_12 * V_12 )
{
struct V_9 * V_9 = V_23 -> V_9 ;
struct V_58 * V_59 = F_86 ( V_9 ) ;
V_59 -> V_60 = true ;
V_59 -> V_61 = false ;
V_59 -> V_23 = V_23 ;
V_59 -> V_74 = V_74 ;
V_59 -> V_75 = V_75 ;
V_59 -> V_19 = V_19 ;
if ( ! V_9 -> V_103 . V_104 )
F_68 ( V_59 ) ;
else if ( F_81 ( V_9 , V_12 ) ) {
struct V_52 * V_53 = F_51 ( V_12 , sizeof( struct V_52 ) ) ;
V_53 -> V_68 = V_59 ;
V_59 -> V_12 = V_12 ;
F_83 ( V_12 , & V_59 -> V_70 , F_62 ) ;
F_50 ( V_9 , V_12 ) ;
F_58 ( V_23 , V_12 , V_75 ) ;
} else {
int V_15 ;
struct V_97 V_99 ;
V_99 . V_47 = V_23 -> V_46 -> V_47 ;
V_99 . V_100 = V_75 * V_9 -> V_44 ;
V_99 . V_101 = V_9 -> V_44 ;
V_15 = F_93 ( V_9 -> V_102 , 1 , & V_99 , 0 , F_61 , V_59 ) ;
if ( V_15 < 0 ) {
F_67 ( V_59 , V_9 -> V_72 ) ;
F_76 ( L_4 ) ;
F_17 ( V_9 , V_19 ) ;
}
}
}
static int F_94 ( struct V_9 * V_9 )
{
int V_15 ;
if ( F_95 ( V_9 ) >= V_105 )
return - V_106 ;
V_15 = F_96 ( V_9 -> V_80 ) ;
if ( V_15 )
F_70 ( V_9 , L_5 , V_15 ) ;
return V_15 ;
}
static void F_97 ( struct V_9 * V_9 , T_1 V_107 )
{
unsigned long V_24 ;
if ( V_107 <= V_9 -> V_108 && ! V_9 -> V_109 ) {
F_98 ( L_6 ,
F_99 ( V_9 -> V_34 ) ) ;
F_15 ( & V_9 -> V_25 , V_24 ) ;
V_9 -> V_109 = true ;
F_16 ( & V_9 -> V_25 , V_24 ) ;
F_100 ( V_9 -> V_110 -> V_111 ) ;
}
}
static int F_101 ( struct V_22 * V_23 , T_1 * V_112 )
{
int V_15 ;
T_1 V_107 ;
struct V_9 * V_9 = V_23 -> V_9 ;
if ( F_102 ( F_95 ( V_9 ) != V_113 ) )
return - V_106 ;
V_15 = F_103 ( V_9 -> V_80 , & V_107 ) ;
if ( V_15 ) {
F_70 ( V_9 , L_7 , V_15 ) ;
return V_15 ;
}
F_97 ( V_9 , V_107 ) ;
if ( ! V_107 ) {
V_15 = F_94 ( V_9 ) ;
if ( V_15 )
return V_15 ;
V_15 = F_103 ( V_9 -> V_80 , & V_107 ) ;
if ( V_15 ) {
F_70 ( V_9 , L_7 , V_15 ) ;
return V_15 ;
}
if ( ! V_107 ) {
F_104 ( V_9 , V_114 ) ;
return - V_115 ;
}
}
V_15 = F_105 ( V_9 -> V_80 , V_112 ) ;
if ( V_15 ) {
F_70 ( V_9 , L_8 , V_15 ) ;
return V_15 ;
}
return 0 ;
}
static void F_106 ( struct V_12 * V_12 )
{
struct V_52 * V_53 = F_51 ( V_12 , sizeof( struct V_52 ) ) ;
struct V_22 * V_23 = V_53 -> V_23 ;
unsigned long V_24 ;
F_15 ( & V_23 -> V_25 , V_24 ) ;
F_56 ( & V_23 -> V_39 , V_12 ) ;
F_16 ( & V_23 -> V_25 , V_24 ) ;
}
static bool F_107 ( struct V_9 * V_9 )
{
enum V_116 V_59 = F_95 ( V_9 ) ;
switch ( V_59 ) {
case V_113 :
F_76 ( L_9 ) ;
return true ;
case V_114 :
return V_9 -> V_103 . V_117 ;
case V_105 :
case V_118 :
return true ;
default:
F_76 ( L_10 ) ;
return true ;
}
}
static void F_108 ( struct V_9 * V_9 , struct V_12 * V_12 )
{
if ( F_107 ( V_9 ) )
F_38 ( V_12 ) ;
else
F_106 ( V_12 ) ;
}
static void F_109 ( struct V_9 * V_9 , struct V_13 * V_19 )
{
struct V_12 * V_12 ;
struct V_20 V_21 ;
if ( F_107 ( V_9 ) ) {
F_17 ( V_9 , V_19 ) ;
return;
}
F_32 ( & V_21 ) ;
F_10 ( V_9 , V_19 , & V_21 ) ;
if ( F_107 ( V_9 ) )
while ( ( V_12 = F_34 ( & V_21 ) ) )
F_38 ( V_12 ) ;
else
while ( ( V_12 = F_34 ( & V_21 ) ) )
F_106 ( V_12 ) ;
}
static void F_110 ( struct V_22 * V_23 , struct V_12 * V_12 )
{
int V_15 ;
unsigned long V_24 ;
struct V_9 * V_9 = V_23 -> V_9 ;
struct V_13 * V_19 , * V_76 ;
struct V_4 V_5 , V_119 ;
T_1 V_8 = F_44 ( V_23 , V_12 ) ;
struct V_120 V_121 ;
struct V_58 * V_59 ;
F_3 ( V_23 -> V_2 , V_8 , & V_5 ) ;
if ( F_6 ( V_23 -> V_9 , & V_5 , V_12 , & V_19 ) )
return;
V_15 = F_111 ( V_23 -> V_2 , V_8 , 1 , & V_121 ) ;
switch ( V_15 ) {
case 0 :
F_1 ( V_23 -> V_2 , V_121 . V_8 , & V_119 ) ;
if ( F_6 ( V_23 -> V_9 , & V_119 , V_12 , & V_76 ) ) {
F_64 ( V_23 , V_19 ) ;
break;
}
if ( F_80 ( V_9 , V_12 ) ) {
V_59 = F_86 ( V_9 ) ;
V_59 -> V_23 = V_23 ;
V_59 -> V_77 = V_9 -> V_103 . V_122 ;
V_59 -> V_78 = ! V_121 . V_123 ;
V_59 -> V_74 = V_8 ;
V_59 -> V_75 = V_121 . V_8 ;
V_59 -> V_19 = V_19 ;
V_59 -> V_76 = V_76 ;
V_59 -> V_12 = V_12 ;
if ( ! F_88 ( V_9 -> V_56 , & V_59 -> V_30 ) ) {
F_15 ( & V_9 -> V_25 , V_24 ) ;
F_60 ( & V_59 -> V_30 , & V_9 -> V_124 ) ;
F_16 ( & V_9 -> V_25 , V_24 ) ;
F_4 ( V_9 ) ;
}
} else {
F_50 ( V_9 , V_12 ) ;
F_64 ( V_23 , V_19 ) ;
F_64 ( V_23 , V_76 ) ;
if ( ( ! V_121 . V_123 ) && V_9 -> V_103 . V_122 )
F_58 ( V_23 , V_12 , V_121 . V_8 ) ;
else
F_35 ( V_12 , 0 ) ;
}
break;
case - V_125 :
F_64 ( V_23 , V_19 ) ;
F_35 ( V_12 , 0 ) ;
break;
default:
F_76 ( L_11 ,
V_126 , V_15 ) ;
F_64 ( V_23 , V_19 ) ;
F_38 ( V_12 ) ;
break;
}
}
static void F_112 ( struct V_22 * V_23 , struct V_12 * V_12 , T_1 V_8 ,
struct V_4 * V_5 ,
struct V_120 * V_121 ,
struct V_13 * V_19 )
{
int V_15 ;
T_1 V_75 ;
struct V_9 * V_9 = V_23 -> V_9 ;
V_15 = F_101 ( V_23 , & V_75 ) ;
switch ( V_15 ) {
case 0 :
F_90 ( V_23 , V_8 , V_121 -> V_8 ,
V_75 , V_19 , V_12 ) ;
break;
case - V_115 :
F_109 ( V_9 , V_19 ) ;
break;
default:
F_76 ( L_12 ,
V_126 , V_15 ) ;
F_17 ( V_9 , V_19 ) ;
break;
}
}
static void F_113 ( struct V_22 * V_23 , struct V_12 * V_12 ,
T_1 V_8 ,
struct V_120 * V_121 )
{
struct V_13 * V_19 ;
struct V_9 * V_9 = V_23 -> V_9 ;
struct V_4 V_5 ;
F_1 ( V_23 -> V_2 , V_121 -> V_8 , & V_5 ) ;
if ( F_6 ( V_9 , & V_5 , V_12 , & V_19 ) )
return;
if ( F_82 ( V_12 ) == V_87 && V_12 -> V_42 . V_85 )
F_112 ( V_23 , V_12 , V_8 , & V_5 , V_121 , V_19 ) ;
else {
struct V_52 * V_53 = F_51 ( V_12 , sizeof( struct V_52 ) ) ;
V_53 -> V_127 = F_52 ( V_9 -> V_96 ) ;
F_50 ( V_9 , V_12 ) ;
F_64 ( V_23 , V_19 ) ;
F_58 ( V_23 , V_12 , V_121 -> V_8 ) ;
}
}
static void F_114 ( struct V_22 * V_23 , struct V_12 * V_12 , T_1 V_8 ,
struct V_13 * V_19 )
{
int V_15 ;
T_1 V_75 ;
struct V_9 * V_9 = V_23 -> V_9 ;
if ( ! V_12 -> V_42 . V_85 ) {
F_50 ( V_9 , V_12 ) ;
F_64 ( V_23 , V_19 ) ;
F_58 ( V_23 , V_12 , 0 ) ;
return;
}
if ( F_82 ( V_12 ) == V_128 ) {
F_115 ( V_12 ) ;
F_64 ( V_23 , V_19 ) ;
F_35 ( V_12 , 0 ) ;
return;
}
V_15 = F_101 ( V_23 , & V_75 ) ;
switch ( V_15 ) {
case 0 :
if ( V_23 -> V_48 )
F_91 ( V_23 , V_8 , V_75 , V_19 , V_12 ) ;
else
F_92 ( V_23 , V_8 , V_75 , V_19 , V_12 ) ;
break;
case - V_115 :
F_109 ( V_9 , V_19 ) ;
break;
default:
F_76 ( L_12 ,
V_126 , V_15 ) ;
F_17 ( V_9 , V_19 ) ;
break;
}
}
static void F_116 ( struct V_22 * V_23 , struct V_12 * V_12 )
{
int V_15 ;
struct V_9 * V_9 = V_23 -> V_9 ;
T_1 V_8 = F_44 ( V_23 , V_12 ) ;
struct V_13 * V_19 ;
struct V_4 V_5 ;
struct V_120 V_121 ;
F_3 ( V_23 -> V_2 , V_8 , & V_5 ) ;
if ( F_6 ( V_9 , & V_5 , V_12 , & V_19 ) )
return;
V_15 = F_111 ( V_23 -> V_2 , V_8 , 1 , & V_121 ) ;
switch ( V_15 ) {
case 0 :
if ( V_121 . V_123 ) {
F_113 ( V_23 , V_12 , V_8 , & V_121 ) ;
F_64 ( V_23 , V_19 ) ;
} else {
F_50 ( V_9 , V_12 ) ;
F_64 ( V_23 , V_19 ) ;
F_58 ( V_23 , V_12 , V_121 . V_8 ) ;
}
break;
case - V_125 :
if ( F_82 ( V_12 ) == V_128 && V_23 -> V_48 ) {
F_50 ( V_9 , V_12 ) ;
F_64 ( V_23 , V_19 ) ;
F_57 ( V_23 , V_12 ) ;
} else
F_114 ( V_23 , V_12 , V_8 , V_19 ) ;
break;
default:
F_76 ( L_11 ,
V_126 , V_15 ) ;
F_64 ( V_23 , V_19 ) ;
F_38 ( V_12 ) ;
break;
}
}
static void F_117 ( struct V_22 * V_23 , struct V_12 * V_12 )
{
int V_15 ;
int V_129 = F_82 ( V_12 ) ;
T_1 V_8 = F_44 ( V_23 , V_12 ) ;
struct V_120 V_121 ;
V_15 = F_111 ( V_23 -> V_2 , V_8 , 1 , & V_121 ) ;
switch ( V_15 ) {
case 0 :
if ( V_121 . V_123 && ( V_129 == V_87 ) && V_12 -> V_42 . V_85 )
F_108 ( V_23 -> V_9 , V_12 ) ;
else {
F_50 ( V_23 -> V_9 , V_12 ) ;
F_58 ( V_23 , V_12 , V_121 . V_8 ) ;
}
break;
case - V_125 :
if ( V_129 != V_128 ) {
F_108 ( V_23 -> V_9 , V_12 ) ;
break;
}
if ( V_23 -> V_48 ) {
F_50 ( V_23 -> V_9 , V_12 ) ;
F_57 ( V_23 , V_12 ) ;
break;
}
F_115 ( V_12 ) ;
F_35 ( V_12 , 0 ) ;
break;
default:
F_76 ( L_11 ,
V_126 , V_15 ) ;
F_38 ( V_12 ) ;
break;
}
}
static void F_118 ( struct V_22 * V_23 , struct V_12 * V_12 )
{
F_35 ( V_12 , 0 ) ;
}
static void F_119 ( struct V_22 * V_23 , struct V_12 * V_12 )
{
F_38 ( V_12 ) ;
}
static int F_120 ( struct V_9 * V_9 )
{
return V_130 < V_9 -> V_131 ||
V_130 > V_9 -> V_131 + V_132 ;
}
static void F_121 ( struct V_22 * V_23 , struct V_12 * V_12 )
{
struct V_133 * * V_134 , * V_135 ;
struct V_52 * V_136 ;
T_2 V_43 = V_12 -> V_42 . V_43 ;
V_134 = & V_23 -> V_137 . V_133 ;
V_135 = NULL ;
while ( * V_134 ) {
V_135 = * V_134 ;
V_136 = F_122 ( V_135 ) ;
if ( V_43 < F_123 ( V_136 ) -> V_42 . V_43 )
V_134 = & ( * V_134 ) -> V_138 ;
else
V_134 = & ( * V_134 ) -> V_139 ;
}
V_136 = F_51 ( V_12 , sizeof( struct V_52 ) ) ;
F_124 ( & V_136 -> V_133 , V_135 , V_134 ) ;
F_125 ( & V_136 -> V_133 , & V_23 -> V_137 ) ;
}
static void F_126 ( struct V_22 * V_23 )
{
struct V_133 * V_140 ;
struct V_52 * V_136 ;
struct V_12 * V_12 ;
for ( V_140 = F_127 ( & V_23 -> V_137 ) ; V_140 ; V_140 = F_128 ( V_140 ) ) {
V_136 = F_122 ( V_140 ) ;
V_12 = F_123 ( V_136 ) ;
F_56 ( & V_23 -> V_26 , V_12 ) ;
F_129 ( & V_136 -> V_133 , & V_23 -> V_137 ) ;
}
F_102 ( ! F_130 ( & V_23 -> V_137 ) ) ;
}
static void F_131 ( struct V_22 * V_23 )
{
struct V_12 * V_12 ;
struct V_20 V_21 ;
F_32 ( & V_21 ) ;
F_33 ( & V_21 , & V_23 -> V_26 ) ;
F_32 ( & V_23 -> V_26 ) ;
while ( ( V_12 = F_34 ( & V_21 ) ) )
F_121 ( V_23 , V_12 ) ;
F_126 ( V_23 ) ;
}
static void F_132 ( struct V_22 * V_23 )
{
struct V_9 * V_9 = V_23 -> V_9 ;
unsigned long V_24 ;
struct V_12 * V_12 ;
struct V_20 V_21 ;
struct V_141 V_142 ;
if ( V_23 -> V_143 ) {
F_31 ( V_23 , & V_23 -> V_26 ) ;
return;
}
F_32 ( & V_21 ) ;
F_15 ( & V_23 -> V_25 , V_24 ) ;
if ( F_133 ( & V_23 -> V_26 ) ) {
F_16 ( & V_23 -> V_25 , V_24 ) ;
return;
}
F_131 ( V_23 ) ;
F_33 ( & V_21 , & V_23 -> V_26 ) ;
F_32 ( & V_23 -> V_26 ) ;
F_16 ( & V_23 -> V_25 , V_24 ) ;
F_134 ( & V_142 ) ;
while ( ( V_12 = F_34 ( & V_21 ) ) ) {
if ( F_84 ( V_9 ) ) {
F_15 ( & V_23 -> V_25 , V_24 ) ;
F_56 ( & V_23 -> V_26 , V_12 ) ;
F_33 ( & V_23 -> V_26 , & V_21 ) ;
F_16 ( & V_23 -> V_25 , V_24 ) ;
break;
}
if ( V_12 -> V_49 & V_54 )
V_9 -> F_110 ( V_23 , V_12 ) ;
else
V_9 -> F_116 ( V_23 , V_12 ) ;
}
F_135 ( & V_142 ) ;
}
static struct V_22 * F_136 ( struct V_9 * V_9 )
{
struct V_22 * V_23 = NULL ;
F_40 () ;
if ( ! F_137 ( & V_9 -> V_144 ) ) {
V_23 = F_138 ( V_9 -> V_144 . V_145 , struct V_22 , V_30 ) ;
F_139 ( V_23 ) ;
}
F_42 () ;
return V_23 ;
}
static struct V_22 * F_140 ( struct V_9 * V_9 , struct V_22 * V_23 )
{
struct V_22 * V_146 = V_23 ;
F_40 () ;
F_141 (tc, &pool->active_thins, list) {
F_139 ( V_23 ) ;
F_142 ( V_146 ) ;
F_42 () ;
return V_23 ;
}
F_142 ( V_146 ) ;
F_42 () ;
return NULL ;
}
static void F_143 ( struct V_9 * V_9 )
{
unsigned long V_24 ;
struct V_12 * V_12 ;
struct V_20 V_21 ;
struct V_22 * V_23 ;
V_23 = F_136 ( V_9 ) ;
while ( V_23 ) {
F_132 ( V_23 ) ;
V_23 = F_140 ( V_9 , V_23 ) ;
}
F_32 ( & V_21 ) ;
F_15 ( & V_9 -> V_25 , V_24 ) ;
F_33 ( & V_21 , & V_9 -> V_57 ) ;
F_32 ( & V_9 -> V_57 ) ;
F_16 ( & V_9 -> V_25 , V_24 ) ;
if ( F_133 ( & V_21 ) &&
! ( F_144 ( V_9 -> V_80 ) && F_120 ( V_9 ) ) )
return;
if ( F_94 ( V_9 ) ) {
while ( ( V_12 = F_34 ( & V_21 ) ) )
F_38 ( V_12 ) ;
return;
}
V_9 -> V_131 = V_130 ;
while ( ( V_12 = F_34 ( & V_21 ) ) )
F_54 ( V_12 ) ;
}
static void F_145 ( struct V_147 * V_148 )
{
struct V_9 * V_9 = F_146 ( V_148 , struct V_9 , V_11 ) ;
F_77 ( V_9 , & V_9 -> V_62 , & V_9 -> F_68 ) ;
F_77 ( V_9 , & V_9 -> V_124 , & V_9 -> F_74 ) ;
F_143 ( V_9 ) ;
}
static void F_147 ( struct V_147 * V_148 )
{
struct V_9 * V_9 = F_146 ( F_148 ( V_148 ) , struct V_9 , V_149 ) ;
F_4 ( V_9 ) ;
F_149 ( V_9 -> V_10 , & V_9 -> V_149 , V_132 ) ;
}
static void F_150 ( struct V_147 * V_148 )
{
struct V_9 * V_9 = F_146 ( F_148 ( V_148 ) , struct V_9 ,
V_150 ) ;
if ( F_95 ( V_9 ) == V_114 && ! V_9 -> V_103 . V_117 )
F_104 ( V_9 , V_105 ) ;
}
static void F_151 ( struct V_151 * V_152 )
{
F_152 ( & V_152 -> V_153 , 1 ) ;
F_153 ( & V_152 -> V_154 ) ;
}
static void F_154 ( struct V_147 * V_148 )
{
struct V_151 * V_152 = F_146 ( V_148 , struct V_151 , V_11 ) ;
V_152 -> V_23 -> V_143 = true ;
F_36 ( V_152 -> V_23 ) ;
F_151 ( V_152 ) ;
}
static void F_155 ( struct V_147 * V_148 )
{
struct V_151 * V_152 = F_146 ( V_148 , struct V_151 , V_11 ) ;
V_152 -> V_23 -> V_143 = false ;
F_151 ( V_152 ) ;
}
static void V_151 ( struct V_22 * V_23 , void (* V_83)( struct V_147 * ) )
{
struct V_151 V_152 ;
F_156 ( & V_152 . V_11 , V_83 ) ;
V_152 . V_23 = V_23 ;
F_152 ( & V_152 . V_153 , 0 ) ;
F_157 ( & V_152 . V_154 ) ;
F_5 ( V_23 -> V_9 -> V_10 , & V_152 . V_11 ) ;
F_158 ( V_152 . V_154 , F_159 ( & V_152 . V_153 ) ) ;
}
static enum V_116 F_95 ( struct V_9 * V_9 )
{
return V_9 -> V_103 . V_155 ;
}
static void F_160 ( struct V_9 * V_9 , const char * V_156 )
{
F_100 ( V_9 -> V_110 -> V_111 ) ;
F_161 ( L_13 ,
F_99 ( V_9 -> V_34 ) , V_156 ) ;
}
static void F_104 ( struct V_9 * V_9 , enum V_116 V_156 )
{
struct V_157 * V_158 = V_9 -> V_110 -> V_159 ;
bool V_160 = F_162 ( V_9 -> V_80 ) ;
enum V_116 V_161 = F_95 ( V_9 ) ;
unsigned long V_150 = F_163 ( V_162 ) * V_163 ;
if ( V_156 == V_113 && V_160 ) {
F_164 ( L_14 ,
F_99 ( V_9 -> V_34 ) ) ;
if ( V_161 != V_156 )
V_156 = V_161 ;
else
V_156 = V_105 ;
}
if ( V_161 == V_118 )
V_156 = V_161 ;
switch ( V_156 ) {
case V_118 :
if ( V_161 != V_156 )
F_160 ( V_9 , L_15 ) ;
F_165 ( V_9 -> V_80 ) ;
V_9 -> F_116 = F_119 ;
V_9 -> F_110 = F_119 ;
V_9 -> F_68 = F_65 ;
V_9 -> F_74 = F_71 ;
F_39 ( V_9 ) ;
break;
case V_105 :
if ( V_161 != V_156 )
F_160 ( V_9 , L_16 ) ;
F_165 ( V_9 -> V_80 ) ;
V_9 -> F_116 = F_117 ;
V_9 -> F_110 = F_118 ;
V_9 -> F_68 = F_65 ;
V_9 -> F_74 = F_72 ;
F_39 ( V_9 ) ;
break;
case V_114 :
if ( V_161 != V_156 )
F_160 ( V_9 , L_17 ) ;
V_9 -> F_116 = F_117 ;
V_9 -> F_110 = F_110 ;
V_9 -> F_68 = F_68 ;
V_9 -> F_74 = F_72 ;
if ( ! V_9 -> V_103 . V_117 && V_150 )
F_149 ( V_9 -> V_10 , & V_9 -> V_150 , V_150 ) ;
break;
case V_113 :
if ( V_161 != V_156 )
F_160 ( V_9 , L_18 ) ;
F_166 ( V_9 -> V_80 ) ;
V_9 -> F_116 = F_116 ;
V_9 -> F_110 = F_110 ;
V_9 -> F_68 = F_68 ;
V_9 -> F_74 = F_74 ;
break;
}
V_9 -> V_103 . V_155 = V_156 ;
V_158 -> V_164 . V_155 = V_156 ;
}
static void F_167 ( struct V_9 * V_9 )
{
const char * V_165 = F_99 ( V_9 -> V_34 ) ;
F_76 ( L_19 , V_165 ) ;
if ( F_168 ( V_9 -> V_80 ) ) {
F_164 ( L_20 , V_165 ) ;
F_104 ( V_9 , V_118 ) ;
}
if ( F_169 ( V_9 -> V_80 ) ) {
F_164 ( L_21 , V_165 ) ;
F_104 ( V_9 , V_118 ) ;
}
}
static void F_70 ( struct V_9 * V_9 , const char * V_166 , int V_15 )
{
F_76 ( L_22 ,
F_99 ( V_9 -> V_34 ) , V_166 , V_15 ) ;
F_167 ( V_9 ) ;
F_104 ( V_9 , V_105 ) ;
}
static void F_170 ( struct V_22 * V_23 , struct V_12 * V_12 )
{
unsigned long V_24 ;
struct V_9 * V_9 = V_23 -> V_9 ;
F_15 ( & V_23 -> V_25 , V_24 ) ;
F_56 ( & V_23 -> V_26 , V_12 ) ;
F_16 ( & V_23 -> V_25 , V_24 ) ;
F_4 ( V_9 ) ;
}
static void F_171 ( struct V_22 * V_23 , struct V_12 * V_12 )
{
struct V_52 * V_53 = F_51 ( V_12 , sizeof( struct V_52 ) ) ;
V_53 -> V_23 = V_23 ;
V_53 -> V_127 = NULL ;
V_53 -> V_55 = NULL ;
V_53 -> V_68 = NULL ;
}
static int F_172 ( struct V_167 * V_110 , struct V_12 * V_12 )
{
int V_15 ;
struct V_22 * V_23 = V_110 -> V_159 ;
T_1 V_8 = F_44 ( V_23 , V_12 ) ;
struct V_1 * V_2 = V_23 -> V_2 ;
struct V_120 V_112 ;
struct V_13 V_168 , V_76 ;
struct V_13 * V_14 ;
struct V_4 V_5 ;
F_171 ( V_23 , V_12 ) ;
if ( V_23 -> V_143 ) {
F_35 ( V_12 , V_38 ) ;
return V_169 ;
}
if ( F_95 ( V_23 -> V_9 ) == V_118 ) {
F_38 ( V_12 ) ;
return V_169 ;
}
if ( V_12 -> V_49 & ( V_54 | V_50 | V_51 ) ) {
F_170 ( V_23 , V_12 ) ;
return V_169 ;
}
V_15 = F_111 ( V_2 , V_8 , 0 , & V_112 ) ;
switch ( V_15 ) {
case 0 :
if ( F_173 ( V_112 . V_123 ) ) {
F_170 ( V_23 , V_12 ) ;
return V_169 ;
}
F_3 ( V_23 -> V_2 , V_8 , & V_5 ) ;
if ( F_8 ( V_23 -> V_9 -> V_17 , & V_5 , V_12 , & V_168 , & V_14 ) )
return V_169 ;
F_1 ( V_23 -> V_2 , V_112 . V_8 , & V_5 ) ;
if ( F_8 ( V_23 -> V_9 -> V_17 , & V_5 , V_12 , & V_76 , & V_14 ) ) {
F_14 ( V_23 , & V_168 ) ;
return V_169 ;
}
F_50 ( V_23 -> V_9 , V_12 ) ;
F_14 ( V_23 , & V_76 ) ;
F_14 ( V_23 , & V_168 ) ;
F_46 ( V_23 , V_12 , V_112 . V_8 ) ;
return V_170 ;
case - V_125 :
if ( F_95 ( V_23 -> V_9 ) == V_105 ) {
F_108 ( V_23 -> V_9 , V_12 ) ;
return V_169 ;
}
case - V_171 :
F_170 ( V_23 , V_12 ) ;
return V_169 ;
default:
F_38 ( V_12 ) ;
return V_169 ;
}
}
static int F_174 ( struct V_172 * V_173 , int V_174 )
{
struct V_157 * V_158 = F_146 ( V_173 , struct V_157 , V_175 ) ;
struct V_176 * V_177 ;
if ( F_95 ( V_158 -> V_9 ) == V_114 )
return 1 ;
V_177 = F_175 ( V_158 -> V_178 -> V_47 ) ;
return F_176 ( & V_177 -> V_179 , V_174 ) ;
}
static void F_177 ( struct V_9 * V_9 )
{
unsigned long V_24 ;
struct V_22 * V_23 ;
F_40 () ;
F_41 (tc, &pool->active_thins, list) {
F_15 ( & V_23 -> V_25 , V_24 ) ;
F_33 ( & V_23 -> V_26 , & V_23 -> V_39 ) ;
F_32 ( & V_23 -> V_39 ) ;
F_16 ( & V_23 -> V_25 , V_24 ) ;
}
F_42 () ;
}
static bool F_178 ( struct V_157 * V_158 )
{
struct V_176 * V_177 = F_175 ( V_158 -> V_178 -> V_47 ) ;
return V_177 && F_179 ( V_177 ) ;
}
static bool F_180 ( T_2 V_180 , T_5 V_181 )
{
return ! F_45 ( V_180 , V_181 ) ;
}
static void F_181 ( struct V_157 * V_158 )
{
struct V_9 * V_9 = V_158 -> V_9 ;
struct V_35 * V_182 = V_158 -> V_178 -> V_47 ;
struct V_183 * V_184 = & F_175 ( V_182 ) -> V_185 ;
T_2 V_180 = V_9 -> V_44 << V_86 ;
const char * V_186 = NULL ;
char V_187 [ V_188 ] ;
if ( ! V_158 -> V_164 . V_122 )
return;
if ( ! F_178 ( V_158 ) )
V_186 = L_23 ;
else if ( V_184 -> V_189 < V_9 -> V_44 )
V_186 = L_24 ;
else if ( V_184 -> V_190 > V_180 )
V_186 = L_25 ;
else if ( ! F_180 ( V_180 , V_184 -> V_190 ) )
V_186 = L_26 ;
if ( V_186 ) {
F_98 ( L_27 , F_182 ( V_182 , V_187 ) , V_186 ) ;
V_158 -> V_164 . V_122 = false ;
}
}
static int F_183 ( struct V_9 * V_9 , struct V_167 * V_110 )
{
struct V_157 * V_158 = V_110 -> V_159 ;
enum V_116 V_161 = F_95 ( V_9 ) ;
enum V_116 V_156 = V_158 -> V_164 . V_155 ;
V_158 -> V_164 . V_155 = V_161 ;
V_9 -> V_110 = V_110 ;
V_9 -> V_103 = V_158 -> V_164 ;
V_9 -> V_108 = V_158 -> V_108 ;
F_104 ( V_9 , V_156 ) ;
return 0 ;
}
static void F_184 ( struct V_9 * V_9 , struct V_167 * V_110 )
{
if ( V_9 -> V_110 == V_110 )
V_9 -> V_110 = NULL ;
}
static void F_185 ( struct V_191 * V_103 )
{
V_103 -> V_155 = V_113 ;
V_103 -> V_104 = true ;
V_103 -> V_192 = true ;
V_103 -> V_122 = true ;
V_103 -> V_117 = false ;
}
static void F_186 ( struct V_9 * V_9 )
{
F_26 ( V_9 ) ;
if ( F_187 ( V_9 -> V_80 ) < 0 )
F_98 ( L_28 , V_126 ) ;
F_188 ( V_9 -> V_17 ) ;
F_189 ( V_9 -> V_102 ) ;
if ( V_9 -> V_10 )
F_190 ( V_9 -> V_10 ) ;
if ( V_9 -> V_89 )
F_67 ( V_9 -> V_89 , V_9 -> V_72 ) ;
F_191 ( V_9 -> V_72 ) ;
F_192 ( V_9 -> V_96 ) ;
F_192 ( V_9 -> V_56 ) ;
F_193 ( V_9 ) ;
}
static struct V_9 * F_194 ( struct V_31 * V_34 ,
struct V_35 * V_193 ,
unsigned long V_180 ,
int V_194 , char * * error )
{
int V_15 ;
void * V_195 ;
struct V_9 * V_9 ;
struct V_196 * V_80 ;
bool V_197 = V_194 ? false : true ;
V_80 = F_195 ( V_193 , V_180 , V_197 ) ;
if ( F_196 ( V_80 ) ) {
* error = L_29 ;
return (struct V_9 * ) V_80 ;
}
V_9 = F_197 ( sizeof( * V_9 ) , V_198 ) ;
if ( ! V_9 ) {
* error = L_30 ;
V_195 = F_198 ( - V_91 ) ;
goto V_199;
}
V_9 -> V_80 = V_80 ;
V_9 -> V_44 = V_180 ;
if ( V_180 & ( V_180 - 1 ) )
V_9 -> V_40 = - 1 ;
else
V_9 -> V_40 = F_199 ( V_180 ) ;
V_9 -> V_108 = 0 ;
F_185 ( & V_9 -> V_103 ) ;
V_9 -> V_17 = F_200 ( V_200 ) ;
if ( ! V_9 -> V_17 ) {
* error = L_31 ;
V_195 = F_198 ( - V_91 ) ;
goto V_201;
}
V_9 -> V_102 = F_201 ( & V_202 ) ;
if ( F_196 ( V_9 -> V_102 ) ) {
V_15 = F_202 ( V_9 -> V_102 ) ;
* error = L_32 ;
V_195 = F_198 ( V_15 ) ;
goto V_203;
}
V_9 -> V_10 = F_203 ( L_33 V_204 , V_205 ) ;
if ( ! V_9 -> V_10 ) {
* error = L_34 ;
V_195 = F_198 ( - V_91 ) ;
goto V_206;
}
F_204 ( & V_9 -> V_11 , F_145 ) ;
F_205 ( & V_9 -> V_149 , F_147 ) ;
F_205 ( & V_9 -> V_150 , F_150 ) ;
F_206 ( & V_9 -> V_25 ) ;
F_32 ( & V_9 -> V_57 ) ;
F_21 ( & V_9 -> V_62 ) ;
F_21 ( & V_9 -> V_124 ) ;
F_21 ( & V_9 -> V_144 ) ;
V_9 -> V_109 = false ;
V_9 -> V_96 = F_207 () ;
if ( ! V_9 -> V_96 ) {
* error = L_35 ;
V_195 = F_198 ( - V_91 ) ;
goto V_207;
}
V_9 -> V_56 = F_207 () ;
if ( ! V_9 -> V_56 ) {
* error = L_36 ;
V_195 = F_198 ( - V_91 ) ;
goto V_208;
}
V_9 -> V_89 = NULL ;
V_9 -> V_72 = F_208 ( V_209 ,
V_210 ) ;
if ( ! V_9 -> V_72 ) {
* error = L_37 ;
V_195 = F_198 ( - V_91 ) ;
goto V_211;
}
V_9 -> V_212 = 1 ;
V_9 -> V_131 = V_130 ;
V_9 -> V_34 = V_34 ;
V_9 -> V_36 = V_193 ;
F_22 ( V_9 ) ;
return V_9 ;
V_211:
F_192 ( V_9 -> V_56 ) ;
V_208:
F_192 ( V_9 -> V_96 ) ;
V_207:
F_190 ( V_9 -> V_10 ) ;
V_206:
F_189 ( V_9 -> V_102 ) ;
V_203:
F_188 ( V_9 -> V_17 ) ;
V_201:
F_193 ( V_9 ) ;
V_199:
if ( F_187 ( V_80 ) )
F_98 ( L_28 , V_126 ) ;
return V_195 ;
}
static void F_209 ( struct V_9 * V_9 )
{
F_23 ( ! F_24 ( & V_27 . V_28 ) ) ;
V_9 -> V_212 ++ ;
}
static void F_210 ( struct V_9 * V_9 )
{
F_23 ( ! F_24 ( & V_27 . V_28 ) ) ;
F_23 ( ! V_9 -> V_212 ) ;
if ( ! -- V_9 -> V_212 )
F_186 ( V_9 ) ;
}
static struct V_9 * F_211 ( struct V_31 * V_34 ,
struct V_35 * V_193 ,
unsigned long V_180 , int V_194 ,
char * * error , int * V_213 )
{
struct V_9 * V_9 = F_30 ( V_193 ) ;
if ( V_9 ) {
if ( V_9 -> V_34 != V_34 ) {
* error = L_38 ;
return F_198 ( - V_214 ) ;
}
F_209 ( V_9 ) ;
} else {
V_9 = F_28 ( V_34 ) ;
if ( V_9 ) {
if ( V_9 -> V_36 != V_193 ) {
* error = L_39 ;
return F_198 ( - V_106 ) ;
}
F_209 ( V_9 ) ;
} else {
V_9 = F_194 ( V_34 , V_193 , V_180 , V_194 , error ) ;
* V_213 = 1 ;
}
}
return V_9 ;
}
static void F_212 ( struct V_167 * V_110 )
{
struct V_157 * V_158 = V_110 -> V_159 ;
F_213 ( & V_27 . V_28 ) ;
F_184 ( V_158 -> V_9 , V_110 ) ;
F_210 ( V_158 -> V_9 ) ;
F_214 ( V_110 , V_158 -> V_193 ) ;
F_214 ( V_110 , V_158 -> V_178 ) ;
F_193 ( V_158 ) ;
F_215 ( & V_27 . V_28 ) ;
}
static int F_216 ( struct V_215 * V_216 , struct V_191 * V_103 ,
struct V_167 * V_110 )
{
int V_15 ;
unsigned V_217 ;
const char * V_218 ;
static struct V_219 V_220 [] = {
{ 0 , 4 , L_40 } ,
} ;
if ( ! V_216 -> V_217 )
return 0 ;
V_15 = F_217 ( V_220 , V_216 , & V_217 , & V_110 -> error ) ;
if ( V_15 )
return - V_106 ;
while ( V_217 && ! V_15 ) {
V_218 = F_218 ( V_216 ) ;
V_217 -- ;
if ( ! strcasecmp ( V_218 , L_41 ) )
V_103 -> V_104 = false ;
else if ( ! strcasecmp ( V_218 , L_42 ) )
V_103 -> V_192 = false ;
else if ( ! strcasecmp ( V_218 , L_43 ) )
V_103 -> V_122 = false ;
else if ( ! strcasecmp ( V_218 , L_44 ) )
V_103 -> V_155 = V_105 ;
else if ( ! strcasecmp ( V_218 , L_45 ) )
V_103 -> V_117 = true ;
else {
V_110 -> error = L_46 ;
V_15 = - V_106 ;
break;
}
}
return V_15 ;
}
static void F_219 ( void * V_65 )
{
struct V_9 * V_9 = V_65 ;
F_98 ( L_47 ,
F_99 ( V_9 -> V_34 ) ) ;
F_100 ( V_9 -> V_110 -> V_111 ) ;
}
static T_2 F_220 ( struct V_35 * V_47 )
{
return F_221 ( V_47 -> V_221 ) >> V_86 ;
}
static void F_222 ( struct V_35 * V_47 )
{
T_2 V_222 = F_220 ( V_47 ) ;
char V_223 [ V_188 ] ;
if ( V_222 > V_224 )
F_98 ( L_48 ,
F_182 ( V_47 , V_223 ) , V_225 ) ;
}
static T_2 F_223 ( struct V_35 * V_47 )
{
T_2 V_222 = F_220 ( V_47 ) ;
if ( V_222 > V_225 )
V_222 = V_225 ;
return V_222 ;
}
static T_1 F_224 ( struct V_35 * V_47 )
{
T_2 V_222 = F_223 ( V_47 ) ;
F_45 ( V_222 , V_226 ) ;
return V_222 ;
}
static T_1 F_225 ( struct V_157 * V_158 )
{
T_1 V_227 = F_224 ( V_158 -> V_193 -> V_47 ) / 4 ;
return F_226 ( ( T_1 ) 1024ULL , V_227 ) ;
}
static int F_227 ( struct V_167 * V_110 , unsigned V_217 , char * * V_228 )
{
int V_15 , V_229 = 0 ;
struct V_157 * V_158 ;
struct V_9 * V_9 ;
struct V_191 V_103 ;
struct V_215 V_216 ;
struct V_92 * V_178 ;
unsigned long V_180 ;
T_1 V_108 ;
struct V_92 * V_193 ;
T_6 V_230 ;
F_213 ( & V_27 . V_28 ) ;
if ( V_217 < 4 ) {
V_110 -> error = L_49 ;
V_15 = - V_106 ;
goto V_231;
}
V_216 . V_217 = V_217 ;
V_216 . V_228 = V_228 ;
F_185 ( & V_103 ) ;
F_228 ( & V_216 , 4 ) ;
V_15 = F_216 ( & V_216 , & V_103 , V_110 ) ;
if ( V_15 )
goto V_231;
V_230 = V_232 | ( ( V_103 . V_155 == V_105 ) ? 0 : V_233 ) ;
V_15 = F_229 ( V_110 , V_228 [ 0 ] , V_230 , & V_193 ) ;
if ( V_15 ) {
V_110 -> error = L_50 ;
goto V_231;
}
F_222 ( V_193 -> V_47 ) ;
V_15 = F_229 ( V_110 , V_228 [ 1 ] , V_232 | V_233 , & V_178 ) ;
if ( V_15 ) {
V_110 -> error = L_51 ;
goto V_234;
}
if ( F_230 ( V_228 [ 2 ] , 10 , & V_180 ) || ! V_180 ||
V_180 < V_235 ||
V_180 > V_236 ||
V_180 & ( V_235 - 1 ) ) {
V_110 -> error = L_52 ;
V_15 = - V_106 ;
goto V_73;
}
if ( F_231 ( V_228 [ 3 ] , 10 , ( unsigned long long * ) & V_108 ) ) {
V_110 -> error = L_53 ;
V_15 = - V_106 ;
goto V_73;
}
V_158 = F_232 ( sizeof( * V_158 ) , V_198 ) ;
if ( ! V_158 ) {
V_15 = - V_91 ;
goto V_73;
}
V_9 = F_211 ( F_233 ( V_110 -> V_111 ) , V_193 -> V_47 ,
V_180 , V_103 . V_155 == V_105 , & V_110 -> error , & V_229 ) ;
if ( F_196 ( V_9 ) ) {
V_15 = F_202 ( V_9 ) ;
goto V_237;
}
if ( ! V_229 && V_103 . V_192 != V_9 -> V_103 . V_192 ) {
V_110 -> error = L_54 ;
V_15 = - V_106 ;
goto V_238;
}
V_158 -> V_9 = V_9 ;
V_158 -> V_110 = V_110 ;
V_158 -> V_193 = V_193 ;
V_158 -> V_178 = V_178 ;
V_158 -> V_108 = V_108 ;
V_158 -> V_164 = V_158 -> V_239 = V_103 ;
V_110 -> V_240 = 1 ;
V_110 -> V_241 = true ;
if ( V_103 . V_192 && V_103 . V_122 ) {
V_110 -> V_242 = 1 ;
V_110 -> V_243 = true ;
}
V_110 -> V_159 = V_158 ;
V_15 = F_234 ( V_158 -> V_9 -> V_80 ,
F_225 ( V_158 ) ,
F_219 ,
V_9 ) ;
if ( V_15 )
goto V_237;
V_158 -> V_175 . V_244 = F_174 ;
F_235 ( V_110 -> V_111 , & V_158 -> V_175 ) ;
F_215 ( & V_27 . V_28 ) ;
return 0 ;
V_238:
F_210 ( V_9 ) ;
V_237:
F_193 ( V_158 ) ;
V_73:
F_214 ( V_110 , V_178 ) ;
V_234:
F_214 ( V_110 , V_193 ) ;
V_231:
F_215 ( & V_27 . V_28 ) ;
return V_15 ;
}
static int F_236 ( struct V_167 * V_110 , struct V_12 * V_12 )
{
int V_15 ;
struct V_157 * V_158 = V_110 -> V_159 ;
struct V_9 * V_9 = V_158 -> V_9 ;
unsigned long V_24 ;
F_15 ( & V_9 -> V_25 , V_24 ) ;
V_12 -> V_45 = V_158 -> V_178 -> V_47 ;
V_15 = V_170 ;
F_16 ( & V_9 -> V_25 , V_24 ) ;
return V_15 ;
}
static int F_237 ( struct V_167 * V_110 , bool * V_245 )
{
int V_15 ;
struct V_157 * V_158 = V_110 -> V_159 ;
struct V_9 * V_9 = V_158 -> V_9 ;
T_2 V_246 = V_110 -> V_247 ;
T_1 V_248 ;
* V_245 = false ;
( void ) F_45 ( V_246 , V_9 -> V_44 ) ;
V_15 = F_238 ( V_9 -> V_80 , & V_248 ) ;
if ( V_15 ) {
F_164 ( L_55 ,
F_99 ( V_9 -> V_34 ) ) ;
return V_15 ;
}
if ( V_246 < V_248 ) {
F_164 ( L_56 ,
F_99 ( V_9 -> V_34 ) ,
( unsigned long long ) V_246 , V_248 ) ;
return - V_106 ;
} else if ( V_246 > V_248 ) {
if ( F_162 ( V_9 -> V_80 ) ) {
F_164 ( L_57 ,
F_99 ( V_9 -> V_34 ) ) ;
return 0 ;
}
if ( V_248 )
F_161 ( L_58 ,
F_99 ( V_9 -> V_34 ) ,
V_248 , ( unsigned long long ) V_246 ) ;
V_15 = F_239 ( V_9 -> V_80 , V_246 ) ;
if ( V_15 ) {
F_70 ( V_9 , L_59 , V_15 ) ;
return V_15 ;
}
* V_245 = true ;
}
return 0 ;
}
static int F_240 ( struct V_167 * V_110 , bool * V_245 )
{
int V_15 ;
struct V_157 * V_158 = V_110 -> V_159 ;
struct V_9 * V_9 = V_158 -> V_9 ;
T_1 V_222 , V_249 ;
* V_245 = false ;
V_222 = F_224 ( V_9 -> V_36 ) ;
V_15 = F_241 ( V_9 -> V_80 , & V_249 ) ;
if ( V_15 ) {
F_164 ( L_60 ,
F_99 ( V_9 -> V_34 ) ) ;
return V_15 ;
}
if ( V_222 < V_249 ) {
F_164 ( L_61 ,
F_99 ( V_9 -> V_34 ) ,
V_222 , V_249 ) ;
return - V_106 ;
} else if ( V_222 > V_249 ) {
if ( F_162 ( V_9 -> V_80 ) ) {
F_164 ( L_62 ,
F_99 ( V_9 -> V_34 ) ) ;
return 0 ;
}
F_222 ( V_9 -> V_36 ) ;
F_161 ( L_63 ,
F_99 ( V_9 -> V_34 ) ,
V_249 , V_222 ) ;
V_15 = F_242 ( V_9 -> V_80 , V_222 ) ;
if ( V_15 ) {
F_70 ( V_9 , L_64 , V_15 ) ;
return V_15 ;
}
* V_245 = true ;
}
return 0 ;
}
static int F_243 ( struct V_167 * V_110 )
{
int V_15 ;
bool V_250 , V_251 ;
struct V_157 * V_158 = V_110 -> V_159 ;
struct V_9 * V_9 = V_158 -> V_9 ;
V_15 = F_183 ( V_9 , V_110 ) ;
if ( V_15 )
return V_15 ;
V_15 = F_237 ( V_110 , & V_250 ) ;
if ( V_15 )
return V_15 ;
V_15 = F_240 ( V_110 , & V_251 ) ;
if ( V_15 )
return V_15 ;
if ( V_250 || V_251 )
( void ) F_94 ( V_9 ) ;
return 0 ;
}
static void F_244 ( struct V_167 * V_110 )
{
struct V_157 * V_158 = V_110 -> V_159 ;
struct V_9 * V_9 = V_158 -> V_9 ;
unsigned long V_24 ;
F_15 ( & V_9 -> V_25 , V_24 ) ;
V_9 -> V_109 = false ;
F_16 ( & V_9 -> V_25 , V_24 ) ;
F_177 ( V_9 ) ;
F_147 ( & V_9 -> V_149 . V_252 ) ;
}
static void F_245 ( struct V_167 * V_110 )
{
struct V_157 * V_158 = V_110 -> V_159 ;
struct V_9 * V_9 = V_158 -> V_9 ;
F_246 ( & V_9 -> V_149 ) ;
F_246 ( & V_9 -> V_150 ) ;
F_247 ( V_9 -> V_10 ) ;
( void ) F_94 ( V_9 ) ;
}
static int F_248 ( unsigned V_217 , unsigned V_253 )
{
if ( V_217 != V_253 ) {
F_98 ( L_65 ,
V_217 , V_253 ) ;
return - V_106 ;
}
return 0 ;
}
static int F_249 ( char * V_254 , T_7 * V_255 , int V_256 )
{
if ( ! F_231 ( V_254 , 10 , ( unsigned long long * ) V_255 ) &&
* V_255 <= V_257 )
return 0 ;
if ( V_256 )
F_98 ( L_66 , V_254 ) ;
return - V_106 ;
}
static int F_250 ( unsigned V_217 , char * * V_228 , struct V_9 * V_9 )
{
T_7 V_255 ;
int V_15 ;
V_15 = F_248 ( V_217 , 2 ) ;
if ( V_15 )
return V_15 ;
V_15 = F_249 ( V_228 [ 1 ] , & V_255 , 1 ) ;
if ( V_15 )
return V_15 ;
V_15 = F_251 ( V_9 -> V_80 , V_255 ) ;
if ( V_15 ) {
F_98 ( L_67 ,
V_228 [ 1 ] ) ;
return V_15 ;
}
return 0 ;
}
static int F_252 ( unsigned V_217 , char * * V_228 , struct V_9 * V_9 )
{
T_7 V_255 ;
T_7 V_258 ;
int V_15 ;
V_15 = F_248 ( V_217 , 3 ) ;
if ( V_15 )
return V_15 ;
V_15 = F_249 ( V_228 [ 1 ] , & V_255 , 1 ) ;
if ( V_15 )
return V_15 ;
V_15 = F_249 ( V_228 [ 2 ] , & V_258 , 1 ) ;
if ( V_15 )
return V_15 ;
V_15 = F_253 ( V_9 -> V_80 , V_255 , V_258 ) ;
if ( V_15 ) {
F_98 ( L_68 ,
V_228 [ 1 ] , V_228 [ 2 ] ) ;
return V_15 ;
}
return 0 ;
}
static int F_254 ( unsigned V_217 , char * * V_228 , struct V_9 * V_9 )
{
T_7 V_255 ;
int V_15 ;
V_15 = F_248 ( V_217 , 2 ) ;
if ( V_15 )
return V_15 ;
V_15 = F_249 ( V_228 [ 1 ] , & V_255 , 1 ) ;
if ( V_15 )
return V_15 ;
V_15 = F_255 ( V_9 -> V_80 , V_255 ) ;
if ( V_15 )
F_98 ( L_69 , V_228 [ 1 ] ) ;
return V_15 ;
}
static int F_256 ( unsigned V_217 , char * * V_228 , struct V_9 * V_9 )
{
T_7 V_259 , V_260 ;
int V_15 ;
V_15 = F_248 ( V_217 , 3 ) ;
if ( V_15 )
return V_15 ;
if ( F_231 ( V_228 [ 1 ] , 10 , ( unsigned long long * ) & V_259 ) ) {
F_98 ( L_70 , V_228 [ 1 ] ) ;
return - V_106 ;
}
if ( F_231 ( V_228 [ 2 ] , 10 , ( unsigned long long * ) & V_260 ) ) {
F_98 ( L_71 , V_228 [ 2 ] ) ;
return - V_106 ;
}
V_15 = F_257 ( V_9 -> V_80 , V_259 , V_260 ) ;
if ( V_15 ) {
F_98 ( L_72 ,
V_228 [ 1 ] , V_228 [ 2 ] ) ;
return V_15 ;
}
return 0 ;
}
static int F_258 ( unsigned V_217 , char * * V_228 , struct V_9 * V_9 )
{
int V_15 ;
V_15 = F_248 ( V_217 , 1 ) ;
if ( V_15 )
return V_15 ;
( void ) F_94 ( V_9 ) ;
V_15 = F_259 ( V_9 -> V_80 ) ;
if ( V_15 )
F_98 ( L_73 ) ;
return V_15 ;
}
static int F_260 ( unsigned V_217 , char * * V_228 , struct V_9 * V_9 )
{
int V_15 ;
V_15 = F_248 ( V_217 , 1 ) ;
if ( V_15 )
return V_15 ;
V_15 = F_261 ( V_9 -> V_80 ) ;
if ( V_15 )
F_98 ( L_74 ) ;
return V_15 ;
}
static int F_262 ( struct V_167 * V_110 , unsigned V_217 , char * * V_228 )
{
int V_15 = - V_106 ;
struct V_157 * V_158 = V_110 -> V_159 ;
struct V_9 * V_9 = V_158 -> V_9 ;
if ( ! strcasecmp ( V_228 [ 0 ] , L_75 ) )
V_15 = F_250 ( V_217 , V_228 , V_9 ) ;
else if ( ! strcasecmp ( V_228 [ 0 ] , L_76 ) )
V_15 = F_252 ( V_217 , V_228 , V_9 ) ;
else if ( ! strcasecmp ( V_228 [ 0 ] , L_77 ) )
V_15 = F_254 ( V_217 , V_228 , V_9 ) ;
else if ( ! strcasecmp ( V_228 [ 0 ] , L_78 ) )
V_15 = F_256 ( V_217 , V_228 , V_9 ) ;
else if ( ! strcasecmp ( V_228 [ 0 ] , L_79 ) )
V_15 = F_258 ( V_217 , V_228 , V_9 ) ;
else if ( ! strcasecmp ( V_228 [ 0 ] , L_80 ) )
V_15 = F_260 ( V_217 , V_228 , V_9 ) ;
else
F_98 ( L_81 , V_228 [ 0 ] ) ;
if ( ! V_15 )
( void ) F_94 ( V_9 ) ;
return V_15 ;
}
static void F_263 ( struct V_191 * V_103 , char * V_112 ,
unsigned V_261 , unsigned V_262 )
{
unsigned V_101 = ! V_103 -> V_104 + ! V_103 -> V_192 +
! V_103 -> V_122 + ( V_103 -> V_155 == V_105 ) +
V_103 -> V_117 ;
F_264 ( L_82 , V_101 ) ;
if ( ! V_103 -> V_104 )
F_264 ( L_83 ) ;
if ( ! V_103 -> V_192 )
F_264 ( L_84 ) ;
if ( ! V_103 -> V_122 )
F_264 ( L_85 ) ;
if ( V_103 -> V_155 == V_105 )
F_264 ( L_86 ) ;
if ( V_103 -> V_117 )
F_264 ( L_87 ) ;
}
static void F_265 ( struct V_167 * V_110 , T_8 type ,
unsigned V_263 , char * V_112 , unsigned V_262 )
{
int V_15 ;
unsigned V_261 = 0 ;
T_9 V_264 ;
T_1 V_265 ;
T_1 V_266 ;
T_1 V_267 ;
T_1 V_268 ;
T_1 V_269 ;
char V_187 [ V_188 ] ;
char V_270 [ V_188 ] ;
struct V_157 * V_158 = V_110 -> V_159 ;
struct V_9 * V_9 = V_158 -> V_9 ;
switch ( type ) {
case V_271 :
if ( F_95 ( V_9 ) == V_118 ) {
F_264 ( L_88 ) ;
break;
}
if ( ! ( V_263 & V_272 ) && ! F_266 ( V_110 ) )
( void ) F_94 ( V_9 ) ;
V_15 = F_267 ( V_9 -> V_80 , & V_264 ) ;
if ( V_15 ) {
F_164 ( L_89 ,
F_99 ( V_9 -> V_34 ) , V_15 ) ;
goto V_66;
}
V_15 = F_268 ( V_9 -> V_80 , & V_266 ) ;
if ( V_15 ) {
F_164 ( L_90 ,
F_99 ( V_9 -> V_34 ) , V_15 ) ;
goto V_66;
}
V_15 = F_241 ( V_9 -> V_80 , & V_268 ) ;
if ( V_15 ) {
F_164 ( L_91 ,
F_99 ( V_9 -> V_34 ) , V_15 ) ;
goto V_66;
}
V_15 = F_103 ( V_9 -> V_80 , & V_265 ) ;
if ( V_15 ) {
F_164 ( L_92 ,
F_99 ( V_9 -> V_34 ) , V_15 ) ;
goto V_66;
}
V_15 = F_238 ( V_9 -> V_80 , & V_267 ) ;
if ( V_15 ) {
F_164 ( L_93 ,
F_99 ( V_9 -> V_34 ) , V_15 ) ;
goto V_66;
}
V_15 = F_269 ( V_9 -> V_80 , & V_269 ) ;
if ( V_15 ) {
F_164 ( L_94 ,
F_99 ( V_9 -> V_34 ) , V_15 ) ;
goto V_66;
}
F_264 ( L_95 ,
( unsigned long long ) V_264 ,
( unsigned long long ) ( V_268 - V_266 ) ,
( unsigned long long ) V_268 ,
( unsigned long long ) ( V_267 - V_265 ) ,
( unsigned long long ) V_267 ) ;
if ( V_269 )
F_264 ( L_96 , V_269 ) ;
else
F_264 ( L_97 ) ;
if ( V_9 -> V_103 . V_155 == V_114 )
F_264 ( L_98 ) ;
else if ( V_9 -> V_103 . V_155 == V_105 )
F_264 ( L_99 ) ;
else
F_264 ( L_100 ) ;
if ( ! V_9 -> V_103 . V_192 )
F_264 ( L_84 ) ;
else if ( V_9 -> V_103 . V_122 )
F_264 ( L_101 ) ;
else
F_264 ( L_85 ) ;
if ( V_9 -> V_103 . V_117 )
F_264 ( L_87 ) ;
else
F_264 ( L_102 ) ;
break;
case V_273 :
F_264 ( L_103 ,
F_270 ( V_187 , V_158 -> V_193 -> V_47 -> V_274 ) ,
F_270 ( V_270 , V_158 -> V_178 -> V_47 -> V_274 ) ,
( unsigned long ) V_9 -> V_44 ,
( unsigned long long ) V_158 -> V_108 ) ;
F_263 ( & V_158 -> V_239 , V_112 , V_261 , V_262 ) ;
break;
}
return;
V_66:
F_264 ( L_104 ) ;
}
static int F_271 ( struct V_167 * V_110 ,
T_10 V_83 , void * V_275 )
{
struct V_157 * V_158 = V_110 -> V_159 ;
return V_83 ( V_110 , V_158 -> V_178 , 0 , V_110 -> V_247 , V_275 ) ;
}
static int F_272 ( struct V_167 * V_110 , struct V_276 * V_277 ,
struct V_278 * V_279 , int V_280 )
{
struct V_157 * V_158 = V_110 -> V_159 ;
struct V_176 * V_177 = F_175 ( V_158 -> V_178 -> V_47 ) ;
if ( ! V_177 -> V_281 )
return V_280 ;
V_277 -> V_45 = V_158 -> V_178 -> V_47 ;
return F_226 ( V_280 , V_177 -> V_281 ( V_177 , V_277 , V_279 ) ) ;
}
static void F_273 ( struct V_157 * V_158 , struct V_183 * V_185 )
{
struct V_9 * V_9 = V_158 -> V_9 ;
struct V_183 * V_184 ;
V_185 -> V_189 = V_9 -> V_44 ;
if ( V_158 -> V_164 . V_122 ) {
V_184 = & F_175 ( V_158 -> V_178 -> V_47 ) -> V_185 ;
V_185 -> V_190 = V_184 -> V_190 ;
} else
V_185 -> V_190 = V_9 -> V_44 << V_86 ;
}
static void F_274 ( struct V_167 * V_110 , struct V_183 * V_185 )
{
struct V_157 * V_158 = V_110 -> V_159 ;
struct V_9 * V_9 = V_158 -> V_9 ;
T_9 V_282 = V_185 -> V_283 >> V_86 ;
if ( V_282 < V_9 -> V_44 ||
F_275 ( V_282 , V_9 -> V_44 ) ) {
F_276 ( V_185 , 0 ) ;
F_277 ( V_185 , V_9 -> V_44 << V_86 ) ;
}
if ( ! V_158 -> V_164 . V_192 ) {
V_185 -> V_190 = 0 ;
return;
}
F_181 ( V_158 ) ;
F_273 ( V_158 , V_185 ) ;
}
static void F_139 ( struct V_22 * V_23 )
{
F_66 ( & V_23 -> V_284 ) ;
}
static void F_142 ( struct V_22 * V_23 )
{
if ( F_278 ( & V_23 -> V_284 ) )
V_153 ( & V_23 -> V_285 ) ;
}
static void F_279 ( struct V_167 * V_110 )
{
struct V_22 * V_23 = V_110 -> V_159 ;
unsigned long V_24 ;
F_142 ( V_23 ) ;
F_280 ( & V_23 -> V_285 ) ;
F_15 ( & V_23 -> V_9 -> V_25 , V_24 ) ;
F_281 ( & V_23 -> V_30 ) ;
F_16 ( & V_23 -> V_9 -> V_25 , V_24 ) ;
F_282 () ;
F_213 ( & V_27 . V_28 ) ;
F_210 ( V_23 -> V_9 ) ;
F_283 ( V_23 -> V_2 ) ;
F_214 ( V_110 , V_23 -> V_46 ) ;
if ( V_23 -> V_48 )
F_214 ( V_110 , V_23 -> V_48 ) ;
F_193 ( V_23 ) ;
F_215 ( & V_27 . V_28 ) ;
}
static int F_284 ( struct V_167 * V_110 , unsigned V_217 , char * * V_228 )
{
int V_15 ;
struct V_22 * V_23 ;
struct V_92 * V_46 , * V_48 ;
struct V_31 * V_34 ;
unsigned long V_24 ;
F_213 ( & V_27 . V_28 ) ;
if ( V_217 != 2 && V_217 != 3 ) {
V_110 -> error = L_49 ;
V_15 = - V_106 ;
goto V_231;
}
V_23 = V_110 -> V_159 = F_232 ( sizeof( * V_23 ) , V_198 ) ;
if ( ! V_23 ) {
V_110 -> error = L_105 ;
V_15 = - V_91 ;
goto V_231;
}
F_206 ( & V_23 -> V_25 ) ;
F_32 ( & V_23 -> V_26 ) ;
F_32 ( & V_23 -> V_39 ) ;
V_23 -> V_137 = V_286 ;
if ( V_217 == 3 ) {
V_15 = F_229 ( V_110 , V_228 [ 2 ] , V_232 , & V_48 ) ;
if ( V_15 ) {
V_110 -> error = L_106 ;
goto V_287;
}
V_23 -> V_48 = V_48 ;
}
V_15 = F_229 ( V_110 , V_228 [ 0 ] , F_285 ( V_110 -> V_111 ) , & V_46 ) ;
if ( V_15 ) {
V_110 -> error = L_107 ;
goto V_288;
}
V_23 -> V_46 = V_46 ;
if ( F_249 ( V_228 [ 1 ] , ( unsigned long long * ) & V_23 -> V_255 , 0 ) ) {
V_110 -> error = L_108 ;
V_15 = - V_106 ;
goto V_289;
}
V_34 = F_286 ( V_23 -> V_46 -> V_47 -> V_274 ) ;
if ( ! V_34 ) {
V_110 -> error = L_109 ;
V_15 = - V_106 ;
goto V_289;
}
V_23 -> V_9 = F_28 ( V_34 ) ;
if ( ! V_23 -> V_9 ) {
V_110 -> error = L_110 ;
V_15 = - V_106 ;
goto V_290;
}
F_209 ( V_23 -> V_9 ) ;
if ( F_95 ( V_23 -> V_9 ) == V_118 ) {
V_110 -> error = L_111 ;
V_15 = - V_106 ;
goto V_291;
}
V_15 = F_287 ( V_23 -> V_9 -> V_80 , V_23 -> V_255 , & V_23 -> V_2 ) ;
if ( V_15 ) {
V_110 -> error = L_112 ;
goto V_291;
}
V_15 = F_288 ( V_110 , V_23 -> V_9 -> V_44 ) ;
if ( V_15 )
goto V_292;
V_110 -> V_240 = 1 ;
V_110 -> V_293 = true ;
V_110 -> V_294 = sizeof( struct V_52 ) ;
V_110 -> V_241 = true ;
if ( V_23 -> V_9 -> V_103 . V_192 ) {
V_110 -> V_243 = true ;
V_110 -> V_242 = 1 ;
V_110 -> V_295 = true ;
}
F_289 ( V_34 ) ;
F_215 ( & V_27 . V_28 ) ;
F_152 ( & V_23 -> V_284 , 1 ) ;
F_290 ( & V_23 -> V_285 ) ;
F_15 ( & V_23 -> V_9 -> V_25 , V_24 ) ;
F_291 ( & V_23 -> V_30 , & V_23 -> V_9 -> V_144 ) ;
F_16 ( & V_23 -> V_9 -> V_25 , V_24 ) ;
F_282 () ;
return 0 ;
V_292:
F_283 ( V_23 -> V_2 ) ;
V_291:
F_210 ( V_23 -> V_9 ) ;
V_290:
F_289 ( V_34 ) ;
V_289:
F_214 ( V_110 , V_23 -> V_46 ) ;
V_288:
if ( V_23 -> V_48 )
F_214 ( V_110 , V_23 -> V_48 ) ;
V_287:
F_193 ( V_23 ) ;
V_231:
F_215 ( & V_27 . V_28 ) ;
return V_15 ;
}
static int F_292 ( struct V_167 * V_110 , struct V_12 * V_12 )
{
V_12 -> V_42 . V_43 = F_293 ( V_110 , V_12 -> V_42 . V_43 ) ;
return F_172 ( V_110 , V_12 ) ;
}
static int F_294 ( struct V_167 * V_110 , struct V_12 * V_12 , int V_66 )
{
unsigned long V_24 ;
struct V_52 * V_53 = F_51 ( V_12 , sizeof( struct V_52 ) ) ;
struct V_81 V_252 ;
struct V_58 * V_59 , * V_33 ;
struct V_9 * V_9 = V_53 -> V_23 -> V_9 ;
if ( V_53 -> V_127 ) {
F_21 ( & V_252 ) ;
F_295 ( V_53 -> V_127 , & V_252 ) ;
F_15 ( & V_9 -> V_25 , V_24 ) ;
F_79 (m, tmp, &work, list) {
F_27 ( & V_59 -> V_30 ) ;
V_59 -> V_60 = true ;
F_59 ( V_59 ) ;
}
F_16 ( & V_9 -> V_25 , V_24 ) ;
}
if ( V_53 -> V_55 ) {
F_21 ( & V_252 ) ;
F_295 ( V_53 -> V_55 , & V_252 ) ;
if ( ! F_137 ( & V_252 ) ) {
F_15 ( & V_9 -> V_25 , V_24 ) ;
F_79 (m, tmp, &work, list)
F_60 ( & V_59 -> V_30 , & V_9 -> V_124 ) ;
F_16 ( & V_9 -> V_25 , V_24 ) ;
F_4 ( V_9 ) ;
}
}
return 0 ;
}
static void F_296 ( struct V_167 * V_110 )
{
struct V_22 * V_23 = V_110 -> V_159 ;
if ( F_297 ( V_110 ) )
V_151 ( V_23 , F_154 ) ;
}
static void F_298 ( struct V_167 * V_110 )
{
struct V_22 * V_23 = V_110 -> V_159 ;
V_151 ( V_23 , F_155 ) ;
}
static void F_299 ( struct V_167 * V_110 , T_8 type ,
unsigned V_263 , char * V_112 , unsigned V_262 )
{
int V_15 ;
T_11 V_261 = 0 ;
T_1 V_296 , V_297 ;
char V_187 [ V_188 ] ;
struct V_22 * V_23 = V_110 -> V_159 ;
if ( F_95 ( V_23 -> V_9 ) == V_118 ) {
F_264 ( L_88 ) ;
return;
}
if ( ! V_23 -> V_2 )
F_264 ( L_113 ) ;
else {
switch ( type ) {
case V_271 :
V_15 = F_300 ( V_23 -> V_2 , & V_296 ) ;
if ( V_15 ) {
F_164 ( L_114 , V_15 ) ;
goto V_66;
}
V_15 = F_301 ( V_23 -> V_2 , & V_297 ) ;
if ( V_15 < 0 ) {
F_164 ( L_115 , V_15 ) ;
goto V_66;
}
F_264 ( L_96 , V_296 * V_23 -> V_9 -> V_44 ) ;
if ( V_15 )
F_264 ( L_116 , ( ( V_297 + 1 ) *
V_23 -> V_9 -> V_44 ) - 1 ) ;
else
F_264 ( L_113 ) ;
break;
case V_273 :
F_264 ( L_117 ,
F_270 ( V_187 , V_23 -> V_46 -> V_47 -> V_274 ) ,
( unsigned long ) V_23 -> V_255 ) ;
if ( V_23 -> V_48 )
F_264 ( L_118 , F_270 ( V_187 , V_23 -> V_48 -> V_47 -> V_274 ) ) ;
break;
}
}
return;
V_66:
F_264 ( L_104 ) ;
}
static int F_302 ( struct V_167 * V_110 ,
T_10 V_83 , void * V_275 )
{
T_2 V_298 ;
struct V_22 * V_23 = V_110 -> V_159 ;
struct V_9 * V_9 = V_23 -> V_9 ;
if ( ! V_9 -> V_110 )
return 0 ;
V_298 = V_9 -> V_110 -> V_247 ;
( void ) F_45 ( V_298 , V_9 -> V_44 ) ;
if ( V_298 )
return V_83 ( V_110 , V_23 -> V_46 , 0 , V_9 -> V_44 * V_298 , V_275 ) ;
return 0 ;
}
static int T_12 F_303 ( void )
{
int V_15 ;
F_19 () ;
V_15 = F_304 ( & V_299 ) ;
if ( V_15 )
return V_15 ;
V_15 = F_304 ( & V_300 ) ;
if ( V_15 )
goto V_301;
V_15 = - V_91 ;
V_210 = F_305 ( V_58 , 0 ) ;
if ( ! V_210 )
goto V_302;
return 0 ;
V_302:
F_306 ( & V_300 ) ;
V_301:
F_306 ( & V_299 ) ;
return V_15 ;
}
static void F_307 ( void )
{
F_306 ( & V_299 ) ;
F_306 ( & V_300 ) ;
F_308 ( V_210 ) ;
}
