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
if ( F_61 ( & V_61 -> V_62 ) ) {
F_62 ( & V_61 -> V_32 , & V_9 -> V_63 ) ;
F_4 ( V_9 ) ;
}
}
static void F_63 ( struct V_60 * V_61 )
{
unsigned long V_24 ;
struct V_9 * V_9 = V_61 -> V_23 -> V_9 ;
F_15 ( & V_9 -> V_25 , V_24 ) ;
F_60 ( V_61 ) ;
F_16 ( & V_9 -> V_25 , V_24 ) ;
}
static void F_64 ( int V_64 , unsigned long V_65 , void * V_66 )
{
struct V_60 * V_61 = V_66 ;
V_61 -> V_67 = V_64 || V_65 ? - V_28 : 0 ;
F_63 ( V_61 ) ;
}
static void F_65 ( struct V_12 * V_12 , int V_67 )
{
struct V_54 * V_55 = F_52 ( V_12 , sizeof( struct V_54 ) ) ;
struct V_60 * V_61 = V_55 -> V_68 ;
V_61 -> V_67 = V_67 ;
F_63 ( V_61 ) ;
}
static void F_66 ( struct V_22 * V_23 , struct V_13 * V_19 )
{
struct V_9 * V_9 = V_23 -> V_9 ;
unsigned long V_24 ;
F_15 ( & V_23 -> V_25 , V_24 ) ;
F_10 ( V_9 , V_19 , & V_23 -> V_26 ) ;
F_16 ( & V_23 -> V_25 , V_24 ) ;
F_4 ( V_9 ) ;
}
static void F_67 ( struct V_22 * V_23 , struct V_13 * V_19 )
{
struct V_9 * V_9 = V_23 -> V_9 ;
unsigned long V_24 ;
F_15 ( & V_23 -> V_25 , V_24 ) ;
F_12 ( V_9 , V_19 , & V_23 -> V_26 ) ;
F_16 ( & V_23 -> V_25 , V_24 ) ;
F_4 ( V_9 ) ;
}
static void F_68 ( struct V_60 * V_61 )
{
if ( V_61 -> V_12 ) {
V_61 -> V_12 -> V_69 = V_61 -> V_70 ;
F_69 ( & V_61 -> V_12 -> V_71 ) ;
}
F_19 ( V_61 -> V_23 -> V_9 , V_61 -> V_19 ) ;
F_28 ( & V_61 -> V_32 ) ;
F_70 ( V_61 , V_61 -> V_23 -> V_9 -> V_72 ) ;
}
static void F_71 ( struct V_60 * V_61 )
{
struct V_22 * V_23 = V_61 -> V_23 ;
struct V_9 * V_9 = V_23 -> V_9 ;
struct V_12 * V_12 ;
int V_15 ;
V_12 = V_61 -> V_12 ;
if ( V_12 ) {
V_12 -> V_69 = V_61 -> V_70 ;
F_69 ( & V_12 -> V_71 ) ;
}
if ( V_61 -> V_67 ) {
F_19 ( V_9 , V_61 -> V_19 ) ;
goto V_73;
}
V_15 = F_72 ( V_23 -> V_2 , V_61 -> V_74 , V_61 -> V_75 ) ;
if ( V_15 ) {
F_73 ( V_9 , L_1 , V_15 ) ;
F_19 ( V_9 , V_61 -> V_19 ) ;
goto V_73;
}
if ( V_12 ) {
F_67 ( V_23 , V_61 -> V_19 ) ;
F_36 ( V_12 , 0 ) ;
} else
F_66 ( V_23 , V_61 -> V_19 ) ;
V_73:
F_28 ( & V_61 -> V_32 ) ;
F_70 ( V_61 , V_9 -> V_72 ) ;
}
static void F_74 ( struct V_60 * V_61 )
{
struct V_22 * V_23 = V_61 -> V_23 ;
F_39 ( V_61 -> V_12 ) ;
F_67 ( V_23 , V_61 -> V_19 ) ;
F_67 ( V_23 , V_61 -> V_76 ) ;
F_70 ( V_61 , V_23 -> V_9 -> V_72 ) ;
}
static void F_75 ( struct V_60 * V_61 )
{
struct V_22 * V_23 = V_61 -> V_23 ;
F_51 ( V_23 -> V_9 , V_61 -> V_12 ) ;
F_67 ( V_23 , V_61 -> V_19 ) ;
F_67 ( V_23 , V_61 -> V_76 ) ;
if ( V_61 -> V_77 )
if ( V_61 -> V_78 )
F_59 ( V_23 , V_61 -> V_12 , V_61 -> V_75 ) ;
else {
bool V_79 = false ;
if ( F_76 ( V_23 -> V_9 -> V_80 , V_61 -> V_75 , & V_79 ) || V_79 )
F_36 ( V_61 -> V_12 , 0 ) ;
else
F_59 ( V_23 , V_61 -> V_12 , V_61 -> V_75 ) ;
}
else
F_36 ( V_61 -> V_12 , 0 ) ;
F_70 ( V_61 , V_23 -> V_9 -> V_72 ) ;
}
static void F_77 ( struct V_60 * V_61 )
{
int V_15 ;
struct V_22 * V_23 = V_61 -> V_23 ;
V_15 = F_78 ( V_23 -> V_2 , V_61 -> V_74 ) ;
if ( V_15 )
F_79 ( L_2 ) ;
F_75 ( V_61 ) ;
}
static void F_80 ( struct V_9 * V_9 , struct V_81 * V_82 ,
T_3 * V_83 )
{
unsigned long V_24 ;
struct V_81 V_84 ;
struct V_60 * V_61 , * V_35 ;
F_22 ( & V_84 ) ;
F_15 ( & V_9 -> V_25 , V_24 ) ;
F_81 ( V_82 , & V_84 ) ;
F_16 ( & V_9 -> V_25 , V_24 ) ;
F_82 ( V_61 , V_35 , & V_84 , V_32 )
( * V_83 ) ( V_61 ) ;
}
static int F_83 ( struct V_9 * V_9 , struct V_12 * V_12 )
{
return V_12 -> V_44 . V_85 ==
( V_9 -> V_46 << V_86 ) ;
}
static int F_84 ( struct V_9 * V_9 , struct V_12 * V_12 )
{
return ( F_85 ( V_12 ) == V_87 ) &&
F_83 ( V_9 , V_12 ) ;
}
static void F_86 ( struct V_12 * V_12 , T_4 * * V_88 ,
T_4 * V_83 )
{
* V_88 = V_12 -> V_69 ;
V_12 -> V_69 = V_83 ;
}
static int F_87 ( struct V_9 * V_9 )
{
if ( V_9 -> V_89 )
return 0 ;
V_9 -> V_89 = F_88 ( V_9 -> V_72 , V_90 ) ;
return V_9 -> V_89 ? 0 : - V_91 ;
}
static struct V_60 * F_89 ( struct V_9 * V_9 )
{
struct V_60 * V_61 = V_9 -> V_89 ;
F_24 ( ! V_9 -> V_89 ) ;
memset ( V_61 , 0 , sizeof( struct V_60 ) ) ;
F_22 ( & V_61 -> V_32 ) ;
V_61 -> V_12 = NULL ;
V_9 -> V_89 = NULL ;
return V_61 ;
}
static void F_90 ( struct V_22 * V_23 , struct V_60 * V_61 ,
T_2 V_92 , T_2 V_93 )
{
int V_15 ;
struct V_94 V_95 ;
V_95 . V_49 = V_23 -> V_48 -> V_49 ;
V_95 . V_96 = V_92 ;
V_95 . V_97 = V_93 - V_92 ;
V_15 = F_91 ( V_23 -> V_9 -> V_98 , 1 , & V_95 , 0 , F_64 , V_61 ) ;
if ( V_15 < 0 ) {
F_79 ( L_3 ) ;
F_64 ( 1 , 1 , V_61 ) ;
}
}
static void F_92 ( struct V_22 * V_23 , T_1 V_74 ,
struct V_99 * V_100 , T_1 V_101 ,
T_1 V_102 ,
struct V_13 * V_19 , struct V_12 * V_12 ,
T_2 V_103 )
{
int V_15 ;
struct V_9 * V_9 = V_23 -> V_9 ;
struct V_60 * V_61 = F_89 ( V_9 ) ;
V_61 -> V_23 = V_23 ;
V_61 -> V_74 = V_74 ;
V_61 -> V_75 = V_102 ;
V_61 -> V_19 = V_19 ;
F_93 ( & V_61 -> V_62 , 3 ) ;
if ( ! F_94 ( V_9 -> V_104 , & V_61 -> V_32 ) )
F_63 ( V_61 ) ;
if ( F_84 ( V_9 , V_12 ) ) {
struct V_54 * V_55 = F_52 ( V_12 , sizeof( struct V_54 ) ) ;
V_55 -> V_68 = V_61 ;
V_61 -> V_12 = V_12 ;
F_86 ( V_12 , & V_61 -> V_70 , F_65 ) ;
F_51 ( V_9 , V_12 ) ;
F_59 ( V_23 , V_12 , V_102 ) ;
} else {
struct V_94 V_105 , V_95 ;
V_105 . V_49 = V_100 -> V_49 ;
V_105 . V_96 = V_101 * V_9 -> V_46 ;
V_105 . V_97 = V_103 ;
V_95 . V_49 = V_23 -> V_48 -> V_49 ;
V_95 . V_96 = V_102 * V_9 -> V_46 ;
V_95 . V_97 = V_103 ;
V_15 = F_95 ( V_9 -> V_98 , & V_105 , 1 , & V_95 ,
0 , F_64 , V_61 ) ;
if ( V_15 < 0 ) {
F_79 ( L_4 ) ;
F_64 ( 1 , 1 , V_61 ) ;
}
if ( V_103 < V_9 -> V_46 && V_9 -> V_106 . V_107 ) {
F_69 ( & V_61 -> V_62 ) ;
F_90 ( V_23 , V_61 ,
V_102 * V_9 -> V_46 + V_103 ,
( V_102 + 1 ) * V_9 -> V_46 ) ;
}
}
F_63 ( V_61 ) ;
}
static void F_96 ( struct V_22 * V_23 , T_1 V_74 ,
T_1 V_101 , T_1 V_102 ,
struct V_13 * V_19 , struct V_12 * V_12 )
{
F_92 ( V_23 , V_74 , V_23 -> V_48 ,
V_101 , V_102 , V_19 , V_12 ,
V_23 -> V_9 -> V_46 ) ;
}
static void F_97 ( struct V_22 * V_23 , T_1 V_74 ,
T_1 V_75 , struct V_13 * V_19 ,
struct V_12 * V_12 )
{
struct V_9 * V_9 = V_23 -> V_9 ;
struct V_60 * V_61 = F_89 ( V_9 ) ;
F_93 ( & V_61 -> V_62 , 1 ) ;
V_61 -> V_23 = V_23 ;
V_61 -> V_74 = V_74 ;
V_61 -> V_75 = V_75 ;
V_61 -> V_19 = V_19 ;
if ( ! V_9 -> V_106 . V_107 )
F_71 ( V_61 ) ;
else if ( F_84 ( V_9 , V_12 ) ) {
struct V_54 * V_55 = F_52 ( V_12 , sizeof( struct V_54 ) ) ;
V_55 -> V_68 = V_61 ;
V_61 -> V_12 = V_12 ;
F_86 ( V_12 , & V_61 -> V_70 , F_65 ) ;
F_51 ( V_9 , V_12 ) ;
F_59 ( V_23 , V_12 , V_75 ) ;
} else
F_90 ( V_23 , V_61 ,
V_75 * V_9 -> V_46 ,
( V_75 + 1 ) * V_9 -> V_46 ) ;
}
static void F_98 ( struct V_22 * V_23 , T_1 V_74 ,
T_1 V_102 ,
struct V_13 * V_19 , struct V_12 * V_12 )
{
struct V_9 * V_9 = V_23 -> V_9 ;
T_2 V_108 = V_74 * V_9 -> V_46 ;
T_2 V_109 = ( V_74 + 1 ) * V_9 -> V_46 ;
if ( V_109 <= V_23 -> V_110 )
F_92 ( V_23 , V_74 , V_23 -> V_50 ,
V_74 , V_102 , V_19 , V_12 ,
V_9 -> V_46 ) ;
else if ( V_108 < V_23 -> V_110 )
F_92 ( V_23 , V_74 , V_23 -> V_50 ,
V_74 , V_102 , V_19 , V_12 ,
V_23 -> V_110 - V_108 ) ;
else
F_97 ( V_23 , V_74 , V_102 , V_19 , V_12 ) ;
}
static int F_99 ( struct V_9 * V_9 )
{
int V_15 ;
if ( F_100 ( V_9 ) >= V_111 )
return - V_112 ;
V_15 = F_101 ( V_9 -> V_80 ) ;
if ( V_15 )
F_73 ( V_9 , L_5 , V_15 ) ;
return V_15 ;
}
static void F_102 ( struct V_9 * V_9 , T_1 V_113 )
{
unsigned long V_24 ;
if ( V_113 <= V_9 -> V_114 && ! V_9 -> V_115 ) {
F_103 ( L_6 ,
F_104 ( V_9 -> V_36 ) ) ;
F_15 ( & V_9 -> V_25 , V_24 ) ;
V_9 -> V_115 = true ;
F_16 ( & V_9 -> V_25 , V_24 ) ;
F_105 ( V_9 -> V_116 -> V_117 ) ;
}
}
static int F_106 ( struct V_22 * V_23 , T_1 * V_118 )
{
int V_15 ;
T_1 V_113 ;
struct V_9 * V_9 = V_23 -> V_9 ;
if ( F_107 ( F_100 ( V_9 ) != V_119 ) )
return - V_112 ;
V_15 = F_108 ( V_9 -> V_80 , & V_113 ) ;
if ( V_15 ) {
F_73 ( V_9 , L_7 , V_15 ) ;
return V_15 ;
}
F_102 ( V_9 , V_113 ) ;
if ( ! V_113 ) {
V_15 = F_99 ( V_9 ) ;
if ( V_15 )
return V_15 ;
V_15 = F_108 ( V_9 -> V_80 , & V_113 ) ;
if ( V_15 ) {
F_73 ( V_9 , L_7 , V_15 ) ;
return V_15 ;
}
if ( ! V_113 ) {
F_109 ( V_9 , V_120 ) ;
return - V_121 ;
}
}
V_15 = F_110 ( V_9 -> V_80 , V_118 ) ;
if ( V_15 ) {
F_73 ( V_9 , L_8 , V_15 ) ;
return V_15 ;
}
return 0 ;
}
static void F_111 ( struct V_12 * V_12 )
{
struct V_54 * V_55 = F_52 ( V_12 , sizeof( struct V_54 ) ) ;
struct V_22 * V_23 = V_55 -> V_23 ;
unsigned long V_24 ;
F_15 ( & V_23 -> V_25 , V_24 ) ;
F_57 ( & V_23 -> V_41 , V_12 ) ;
F_16 ( & V_23 -> V_25 , V_24 ) ;
}
static int F_112 ( struct V_9 * V_9 )
{
enum V_122 V_61 = F_100 ( V_9 ) ;
switch ( V_61 ) {
case V_119 :
F_79 ( L_9 ) ;
return - V_28 ;
case V_120 :
return V_9 -> V_106 . V_123 ? - V_121 : 0 ;
case V_111 :
case V_124 :
return - V_28 ;
default:
F_79 ( L_10 ) ;
return - V_28 ;
}
}
static void F_113 ( struct V_9 * V_9 , struct V_12 * V_12 )
{
int error = F_112 ( V_9 ) ;
if ( error )
F_36 ( V_12 , error ) ;
else
F_111 ( V_12 ) ;
}
static void F_114 ( struct V_9 * V_9 , struct V_13 * V_19 )
{
struct V_12 * V_12 ;
struct V_20 V_21 ;
int error ;
error = F_112 ( V_9 ) ;
if ( error ) {
F_17 ( V_9 , V_19 , error ) ;
return;
}
F_33 ( & V_21 ) ;
F_10 ( V_9 , V_19 , & V_21 ) ;
error = F_112 ( V_9 ) ;
if ( error )
while ( ( V_12 = F_35 ( & V_21 ) ) )
F_36 ( V_12 , error ) ;
else
while ( ( V_12 = F_35 ( & V_21 ) ) )
F_111 ( V_12 ) ;
}
static void F_115 ( struct V_22 * V_23 , struct V_12 * V_12 )
{
int V_15 ;
unsigned long V_24 ;
struct V_9 * V_9 = V_23 -> V_9 ;
struct V_13 * V_19 , * V_76 ;
struct V_4 V_5 , V_125 ;
T_1 V_8 = F_45 ( V_23 , V_12 ) ;
struct V_126 V_127 ;
struct V_60 * V_61 ;
F_3 ( V_23 -> V_2 , V_8 , & V_5 ) ;
if ( F_6 ( V_23 -> V_9 , & V_5 , V_12 , & V_19 ) )
return;
V_15 = F_116 ( V_23 -> V_2 , V_8 , 1 , & V_127 ) ;
switch ( V_15 ) {
case 0 :
F_1 ( V_23 -> V_2 , V_127 . V_8 , & V_125 ) ;
if ( F_6 ( V_23 -> V_9 , & V_125 , V_12 , & V_76 ) ) {
F_67 ( V_23 , V_19 ) ;
break;
}
if ( F_83 ( V_9 , V_12 ) ) {
V_61 = F_89 ( V_9 ) ;
V_61 -> V_23 = V_23 ;
V_61 -> V_77 = V_9 -> V_106 . V_128 ;
V_61 -> V_78 = ! V_127 . V_129 ;
V_61 -> V_74 = V_8 ;
V_61 -> V_75 = V_127 . V_8 ;
V_61 -> V_19 = V_19 ;
V_61 -> V_76 = V_76 ;
V_61 -> V_12 = V_12 ;
if ( ! F_94 ( V_9 -> V_58 , & V_61 -> V_32 ) ) {
F_15 ( & V_9 -> V_25 , V_24 ) ;
F_62 ( & V_61 -> V_32 , & V_9 -> V_130 ) ;
F_16 ( & V_9 -> V_25 , V_24 ) ;
F_4 ( V_9 ) ;
}
} else {
F_51 ( V_9 , V_12 ) ;
F_67 ( V_23 , V_19 ) ;
F_67 ( V_23 , V_76 ) ;
if ( ( ! V_127 . V_129 ) && V_9 -> V_106 . V_128 )
F_59 ( V_23 , V_12 , V_127 . V_8 ) ;
else
F_36 ( V_12 , 0 ) ;
}
break;
case - V_131 :
F_67 ( V_23 , V_19 ) ;
F_36 ( V_12 , 0 ) ;
break;
default:
F_79 ( L_11 ,
V_132 , V_15 ) ;
F_67 ( V_23 , V_19 ) ;
F_39 ( V_12 ) ;
break;
}
}
static void F_117 ( struct V_22 * V_23 , struct V_12 * V_12 , T_1 V_8 ,
struct V_4 * V_5 ,
struct V_126 * V_127 ,
struct V_13 * V_19 )
{
int V_15 ;
T_1 V_75 ;
struct V_9 * V_9 = V_23 -> V_9 ;
V_15 = F_106 ( V_23 , & V_75 ) ;
switch ( V_15 ) {
case 0 :
F_96 ( V_23 , V_8 , V_127 -> V_8 ,
V_75 , V_19 , V_12 ) ;
break;
case - V_121 :
F_114 ( V_9 , V_19 ) ;
break;
default:
F_79 ( L_12 ,
V_132 , V_15 ) ;
F_19 ( V_9 , V_19 ) ;
break;
}
}
static void F_118 ( struct V_22 * V_23 , struct V_12 * V_12 ,
T_1 V_8 ,
struct V_126 * V_127 )
{
struct V_13 * V_19 ;
struct V_9 * V_9 = V_23 -> V_9 ;
struct V_4 V_5 ;
F_1 ( V_23 -> V_2 , V_127 -> V_8 , & V_5 ) ;
if ( F_6 ( V_9 , & V_5 , V_12 , & V_19 ) )
return;
if ( F_85 ( V_12 ) == V_87 && V_12 -> V_44 . V_85 )
F_117 ( V_23 , V_12 , V_8 , & V_5 , V_127 , V_19 ) ;
else {
struct V_54 * V_55 = F_52 ( V_12 , sizeof( struct V_54 ) ) ;
V_55 -> V_133 = F_53 ( V_9 -> V_104 ) ;
F_51 ( V_9 , V_12 ) ;
F_67 ( V_23 , V_19 ) ;
F_59 ( V_23 , V_12 , V_127 -> V_8 ) ;
}
}
static void F_119 ( struct V_22 * V_23 , struct V_12 * V_12 , T_1 V_8 ,
struct V_13 * V_19 )
{
int V_15 ;
T_1 V_75 ;
struct V_9 * V_9 = V_23 -> V_9 ;
if ( ! V_12 -> V_44 . V_85 ) {
F_51 ( V_9 , V_12 ) ;
F_67 ( V_23 , V_19 ) ;
F_59 ( V_23 , V_12 , 0 ) ;
return;
}
if ( F_85 ( V_12 ) == V_134 ) {
F_120 ( V_12 ) ;
F_67 ( V_23 , V_19 ) ;
F_36 ( V_12 , 0 ) ;
return;
}
V_15 = F_106 ( V_23 , & V_75 ) ;
switch ( V_15 ) {
case 0 :
if ( V_23 -> V_50 )
F_98 ( V_23 , V_8 , V_75 , V_19 , V_12 ) ;
else
F_97 ( V_23 , V_8 , V_75 , V_19 , V_12 ) ;
break;
case - V_121 :
F_114 ( V_9 , V_19 ) ;
break;
default:
F_79 ( L_12 ,
V_132 , V_15 ) ;
F_19 ( V_9 , V_19 ) ;
break;
}
}
static void F_121 ( struct V_22 * V_23 , struct V_12 * V_12 )
{
int V_15 ;
struct V_9 * V_9 = V_23 -> V_9 ;
T_1 V_8 = F_45 ( V_23 , V_12 ) ;
struct V_13 * V_19 ;
struct V_4 V_5 ;
struct V_126 V_127 ;
F_3 ( V_23 -> V_2 , V_8 , & V_5 ) ;
if ( F_6 ( V_9 , & V_5 , V_12 , & V_19 ) )
return;
V_15 = F_116 ( V_23 -> V_2 , V_8 , 1 , & V_127 ) ;
switch ( V_15 ) {
case 0 :
if ( V_127 . V_129 ) {
F_118 ( V_23 , V_12 , V_8 , & V_127 ) ;
F_67 ( V_23 , V_19 ) ;
} else {
F_51 ( V_9 , V_12 ) ;
F_67 ( V_23 , V_19 ) ;
F_59 ( V_23 , V_12 , V_127 . V_8 ) ;
}
break;
case - V_131 :
if ( F_85 ( V_12 ) == V_134 && V_23 -> V_50 ) {
F_51 ( V_9 , V_12 ) ;
F_67 ( V_23 , V_19 ) ;
if ( F_122 ( V_12 ) <= V_23 -> V_110 )
F_58 ( V_23 , V_12 ) ;
else if ( V_12 -> V_44 . V_45 < V_23 -> V_110 ) {
F_120 ( V_12 ) ;
V_12 -> V_44 . V_85 = ( V_23 -> V_110 - V_12 -> V_44 . V_45 ) << V_86 ;
F_58 ( V_23 , V_12 ) ;
} else {
F_120 ( V_12 ) ;
F_36 ( V_12 , 0 ) ;
}
} else
F_119 ( V_23 , V_12 , V_8 , V_19 ) ;
break;
default:
F_79 ( L_11 ,
V_132 , V_15 ) ;
F_67 ( V_23 , V_19 ) ;
F_39 ( V_12 ) ;
break;
}
}
static void F_123 ( struct V_22 * V_23 , struct V_12 * V_12 )
{
int V_15 ;
int V_135 = F_85 ( V_12 ) ;
T_1 V_8 = F_45 ( V_23 , V_12 ) ;
struct V_126 V_127 ;
V_15 = F_116 ( V_23 -> V_2 , V_8 , 1 , & V_127 ) ;
switch ( V_15 ) {
case 0 :
if ( V_127 . V_129 && ( V_135 == V_87 ) && V_12 -> V_44 . V_85 )
F_113 ( V_23 -> V_9 , V_12 ) ;
else {
F_51 ( V_23 -> V_9 , V_12 ) ;
F_59 ( V_23 , V_12 , V_127 . V_8 ) ;
}
break;
case - V_131 :
if ( V_135 != V_134 ) {
F_113 ( V_23 -> V_9 , V_12 ) ;
break;
}
if ( V_23 -> V_50 ) {
F_51 ( V_23 -> V_9 , V_12 ) ;
F_58 ( V_23 , V_12 ) ;
break;
}
F_120 ( V_12 ) ;
F_36 ( V_12 , 0 ) ;
break;
default:
F_79 ( L_11 ,
V_132 , V_15 ) ;
F_39 ( V_12 ) ;
break;
}
}
static void F_124 ( struct V_22 * V_23 , struct V_12 * V_12 )
{
F_36 ( V_12 , 0 ) ;
}
static void F_125 ( struct V_22 * V_23 , struct V_12 * V_12 )
{
F_39 ( V_12 ) ;
}
static int F_126 ( struct V_9 * V_9 )
{
return V_136 < V_9 -> V_137 ||
V_136 > V_9 -> V_137 + V_138 ;
}
static void F_127 ( struct V_22 * V_23 , struct V_12 * V_12 )
{
struct V_139 * * V_140 , * V_141 ;
struct V_54 * V_142 ;
T_2 V_45 = V_12 -> V_44 . V_45 ;
V_140 = & V_23 -> V_143 . V_139 ;
V_141 = NULL ;
while ( * V_140 ) {
V_141 = * V_140 ;
V_142 = F_128 ( V_141 ) ;
if ( V_45 < F_129 ( V_142 ) -> V_44 . V_45 )
V_140 = & ( * V_140 ) -> V_144 ;
else
V_140 = & ( * V_140 ) -> V_145 ;
}
V_142 = F_52 ( V_12 , sizeof( struct V_54 ) ) ;
F_130 ( & V_142 -> V_139 , V_141 , V_140 ) ;
F_131 ( & V_142 -> V_139 , & V_23 -> V_143 ) ;
}
static void F_132 ( struct V_22 * V_23 )
{
struct V_139 * V_146 ;
struct V_54 * V_142 ;
struct V_12 * V_12 ;
for ( V_146 = F_133 ( & V_23 -> V_143 ) ; V_146 ; V_146 = F_134 ( V_146 ) ) {
V_142 = F_128 ( V_146 ) ;
V_12 = F_129 ( V_142 ) ;
F_57 ( & V_23 -> V_26 , V_12 ) ;
F_135 ( & V_142 -> V_139 , & V_23 -> V_143 ) ;
}
F_107 ( ! F_136 ( & V_23 -> V_143 ) ) ;
}
static void F_137 ( struct V_22 * V_23 )
{
struct V_12 * V_12 ;
struct V_20 V_21 ;
F_33 ( & V_21 ) ;
F_34 ( & V_21 , & V_23 -> V_26 ) ;
F_33 ( & V_23 -> V_26 ) ;
while ( ( V_12 = F_35 ( & V_21 ) ) )
F_127 ( V_23 , V_12 ) ;
F_132 ( V_23 ) ;
}
static void F_138 ( struct V_22 * V_23 )
{
struct V_9 * V_9 = V_23 -> V_9 ;
unsigned long V_24 ;
struct V_12 * V_12 ;
struct V_20 V_21 ;
struct V_147 V_148 ;
if ( V_23 -> V_149 ) {
F_32 ( V_23 , & V_23 -> V_26 ) ;
return;
}
F_33 ( & V_21 ) ;
F_15 ( & V_23 -> V_25 , V_24 ) ;
if ( F_139 ( & V_23 -> V_26 ) ) {
F_16 ( & V_23 -> V_25 , V_24 ) ;
return;
}
F_137 ( V_23 ) ;
F_34 ( & V_21 , & V_23 -> V_26 ) ;
F_33 ( & V_23 -> V_26 ) ;
F_16 ( & V_23 -> V_25 , V_24 ) ;
F_140 ( & V_148 ) ;
while ( ( V_12 = F_35 ( & V_21 ) ) ) {
if ( F_87 ( V_9 ) ) {
F_15 ( & V_23 -> V_25 , V_24 ) ;
F_57 ( & V_23 -> V_26 , V_12 ) ;
F_34 ( & V_23 -> V_26 , & V_21 ) ;
F_16 ( & V_23 -> V_25 , V_24 ) ;
break;
}
if ( V_12 -> V_51 & V_56 )
V_9 -> F_115 ( V_23 , V_12 ) ;
else
V_9 -> F_121 ( V_23 , V_12 ) ;
}
F_141 ( & V_148 ) ;
}
static struct V_22 * F_142 ( struct V_9 * V_9 )
{
struct V_22 * V_23 = NULL ;
F_41 () ;
if ( ! F_143 ( & V_9 -> V_150 ) ) {
V_23 = F_144 ( V_9 -> V_150 . V_151 , struct V_22 , V_32 ) ;
F_145 ( V_23 ) ;
}
F_43 () ;
return V_23 ;
}
static struct V_22 * F_146 ( struct V_9 * V_9 , struct V_22 * V_23 )
{
struct V_22 * V_152 = V_23 ;
F_41 () ;
F_147 (tc, &pool->active_thins, list) {
F_145 ( V_23 ) ;
F_148 ( V_152 ) ;
F_43 () ;
return V_23 ;
}
F_148 ( V_152 ) ;
F_43 () ;
return NULL ;
}
static void F_149 ( struct V_9 * V_9 )
{
unsigned long V_24 ;
struct V_12 * V_12 ;
struct V_20 V_21 ;
struct V_22 * V_23 ;
V_23 = F_142 ( V_9 ) ;
while ( V_23 ) {
F_138 ( V_23 ) ;
V_23 = F_146 ( V_9 , V_23 ) ;
}
F_33 ( & V_21 ) ;
F_15 ( & V_9 -> V_25 , V_24 ) ;
F_34 ( & V_21 , & V_9 -> V_59 ) ;
F_33 ( & V_9 -> V_59 ) ;
F_16 ( & V_9 -> V_25 , V_24 ) ;
if ( F_139 ( & V_21 ) &&
! ( F_150 ( V_9 -> V_80 ) && F_126 ( V_9 ) ) )
return;
if ( F_99 ( V_9 ) ) {
while ( ( V_12 = F_35 ( & V_21 ) ) )
F_39 ( V_12 ) ;
return;
}
V_9 -> V_137 = V_136 ;
while ( ( V_12 = F_35 ( & V_21 ) ) )
F_55 ( V_12 ) ;
}
static void F_151 ( struct V_153 * V_154 )
{
struct V_9 * V_9 = F_152 ( V_154 , struct V_9 , V_11 ) ;
F_80 ( V_9 , & V_9 -> V_63 , & V_9 -> F_71 ) ;
F_80 ( V_9 , & V_9 -> V_130 , & V_9 -> F_77 ) ;
F_149 ( V_9 ) ;
}
static void F_153 ( struct V_153 * V_154 )
{
struct V_9 * V_9 = F_152 ( F_154 ( V_154 ) , struct V_9 , V_155 ) ;
F_4 ( V_9 ) ;
F_155 ( V_9 -> V_10 , & V_9 -> V_155 , V_138 ) ;
}
static void F_156 ( struct V_153 * V_154 )
{
struct V_9 * V_9 = F_152 ( F_154 ( V_154 ) , struct V_9 ,
V_156 ) ;
if ( F_100 ( V_9 ) == V_120 && ! V_9 -> V_106 . V_123 )
F_109 ( V_9 , V_111 ) ;
}
static struct V_157 * F_157 ( struct V_153 * V_154 )
{
return F_152 ( V_154 , struct V_157 , V_11 ) ;
}
static void F_158 ( struct V_157 * V_158 )
{
F_159 ( & V_158 -> F_159 ) ;
}
static void F_160 ( struct V_157 * V_158 , struct V_9 * V_9 ,
void (* V_83)( struct V_153 * ) )
{
F_161 ( & V_158 -> V_11 , V_83 ) ;
F_162 ( & V_158 -> F_159 ) ;
F_5 ( V_9 -> V_10 , & V_158 -> V_11 ) ;
F_163 ( & V_158 -> F_159 ) ;
}
static struct V_159 * F_164 ( struct V_153 * V_154 )
{
return F_152 ( F_157 ( V_154 ) , struct V_159 , V_158 ) ;
}
static void F_165 ( struct V_153 * V_154 )
{
struct V_159 * V_160 = F_164 ( V_154 ) ;
V_160 -> V_23 -> V_149 = true ;
F_37 ( V_160 -> V_23 ) ;
F_158 ( & V_160 -> V_158 ) ;
}
static void F_166 ( struct V_153 * V_154 )
{
struct V_159 * V_160 = F_164 ( V_154 ) ;
V_160 -> V_23 -> V_149 = false ;
F_158 ( & V_160 -> V_158 ) ;
}
static void V_159 ( struct V_22 * V_23 , void (* V_83)( struct V_153 * ) )
{
struct V_159 V_160 ;
V_160 . V_23 = V_23 ;
F_160 ( & V_160 . V_158 , V_23 -> V_9 , V_83 ) ;
}
static enum V_122 F_100 ( struct V_9 * V_9 )
{
return V_9 -> V_106 . V_161 ;
}
static void F_167 ( struct V_9 * V_9 , const char * V_162 )
{
F_105 ( V_9 -> V_116 -> V_117 ) ;
F_168 ( L_13 ,
F_104 ( V_9 -> V_36 ) , V_162 ) ;
}
static void F_109 ( struct V_9 * V_9 , enum V_122 V_162 )
{
struct V_163 * V_164 = V_9 -> V_116 -> V_165 ;
bool V_166 = F_169 ( V_9 -> V_80 ) ;
enum V_122 V_167 = F_100 ( V_9 ) ;
unsigned long V_156 = F_170 ( V_168 ) * V_169 ;
if ( V_162 == V_119 && V_166 ) {
F_171 ( L_14 ,
F_104 ( V_9 -> V_36 ) ) ;
if ( V_167 != V_162 )
V_162 = V_167 ;
else
V_162 = V_111 ;
}
if ( V_167 == V_124 )
V_162 = V_167 ;
switch ( V_162 ) {
case V_124 :
if ( V_167 != V_162 )
F_167 ( V_9 , L_15 ) ;
F_172 ( V_9 -> V_80 ) ;
V_9 -> F_121 = F_125 ;
V_9 -> F_115 = F_125 ;
V_9 -> F_71 = F_68 ;
V_9 -> F_77 = F_74 ;
F_40 ( V_9 ) ;
break;
case V_111 :
if ( V_167 != V_162 )
F_167 ( V_9 , L_16 ) ;
F_172 ( V_9 -> V_80 ) ;
V_9 -> F_121 = F_123 ;
V_9 -> F_115 = F_124 ;
V_9 -> F_71 = F_68 ;
V_9 -> F_77 = F_75 ;
F_40 ( V_9 ) ;
break;
case V_120 :
if ( V_167 != V_162 )
F_167 ( V_9 , L_17 ) ;
V_9 -> F_121 = F_123 ;
V_9 -> F_115 = F_115 ;
V_9 -> F_71 = F_71 ;
V_9 -> F_77 = F_75 ;
if ( ! V_9 -> V_106 . V_123 && V_156 )
F_155 ( V_9 -> V_10 , & V_9 -> V_156 , V_156 ) ;
break;
case V_119 :
if ( V_167 != V_162 )
F_167 ( V_9 , L_18 ) ;
F_173 ( V_9 -> V_80 ) ;
V_9 -> F_121 = F_121 ;
V_9 -> F_115 = F_115 ;
V_9 -> F_71 = F_71 ;
V_9 -> F_77 = F_77 ;
break;
}
V_9 -> V_106 . V_161 = V_162 ;
V_164 -> V_170 . V_161 = V_162 ;
}
static void F_174 ( struct V_9 * V_9 )
{
const char * V_171 = F_104 ( V_9 -> V_36 ) ;
F_79 ( L_19 , V_171 ) ;
if ( F_175 ( V_9 -> V_80 ) ) {
F_171 ( L_20 , V_171 ) ;
F_109 ( V_9 , V_124 ) ;
}
if ( F_176 ( V_9 -> V_80 ) ) {
F_171 ( L_21 , V_171 ) ;
F_109 ( V_9 , V_124 ) ;
}
}
static void F_73 ( struct V_9 * V_9 , const char * V_172 , int V_15 )
{
F_79 ( L_22 ,
F_104 ( V_9 -> V_36 ) , V_172 , V_15 ) ;
F_174 ( V_9 ) ;
F_109 ( V_9 , V_111 ) ;
}
static void F_177 ( struct V_22 * V_23 , struct V_12 * V_12 )
{
unsigned long V_24 ;
struct V_9 * V_9 = V_23 -> V_9 ;
F_15 ( & V_23 -> V_25 , V_24 ) ;
F_57 ( & V_23 -> V_26 , V_12 ) ;
F_16 ( & V_23 -> V_25 , V_24 ) ;
F_4 ( V_9 ) ;
}
static void F_178 ( struct V_22 * V_23 , struct V_12 * V_12 )
{
struct V_54 * V_55 = F_52 ( V_12 , sizeof( struct V_54 ) ) ;
V_55 -> V_23 = V_23 ;
V_55 -> V_133 = NULL ;
V_55 -> V_57 = NULL ;
V_55 -> V_68 = NULL ;
}
static int F_179 ( struct V_173 * V_116 , struct V_12 * V_12 )
{
int V_15 ;
struct V_22 * V_23 = V_116 -> V_165 ;
T_1 V_8 = F_45 ( V_23 , V_12 ) ;
struct V_1 * V_2 = V_23 -> V_2 ;
struct V_126 V_118 ;
struct V_13 V_174 , V_76 ;
struct V_13 * V_14 ;
struct V_4 V_5 ;
F_178 ( V_23 , V_12 ) ;
if ( V_23 -> V_149 ) {
F_36 ( V_12 , V_40 ) ;
return V_175 ;
}
if ( F_100 ( V_23 -> V_9 ) == V_124 ) {
F_39 ( V_12 ) ;
return V_175 ;
}
if ( V_12 -> V_51 & ( V_56 | V_52 | V_53 ) ) {
F_177 ( V_23 , V_12 ) ;
return V_175 ;
}
V_15 = F_116 ( V_2 , V_8 , 0 , & V_118 ) ;
switch ( V_15 ) {
case 0 :
if ( F_180 ( V_118 . V_129 ) ) {
F_177 ( V_23 , V_12 ) ;
return V_175 ;
}
F_3 ( V_23 -> V_2 , V_8 , & V_5 ) ;
if ( F_8 ( V_23 -> V_9 -> V_17 , & V_5 , V_12 , & V_174 , & V_14 ) )
return V_175 ;
F_1 ( V_23 -> V_2 , V_118 . V_8 , & V_5 ) ;
if ( F_8 ( V_23 -> V_9 -> V_17 , & V_5 , V_12 , & V_76 , & V_14 ) ) {
F_14 ( V_23 , & V_174 ) ;
return V_175 ;
}
F_51 ( V_23 -> V_9 , V_12 ) ;
F_14 ( V_23 , & V_76 ) ;
F_14 ( V_23 , & V_174 ) ;
F_47 ( V_23 , V_12 , V_118 . V_8 ) ;
return V_176 ;
case - V_131 :
if ( F_100 ( V_23 -> V_9 ) == V_111 ) {
F_113 ( V_23 -> V_9 , V_12 ) ;
return V_175 ;
}
case - V_177 :
F_177 ( V_23 , V_12 ) ;
return V_175 ;
default:
F_39 ( V_12 ) ;
return V_175 ;
}
}
static int F_181 ( struct V_178 * V_179 , int V_180 )
{
struct V_163 * V_164 = F_152 ( V_179 , struct V_163 , V_181 ) ;
struct V_182 * V_183 ;
if ( F_100 ( V_164 -> V_9 ) == V_120 )
return 1 ;
V_183 = F_182 ( V_164 -> V_184 -> V_49 ) ;
return F_183 ( & V_183 -> V_185 , V_180 ) ;
}
static void F_184 ( struct V_9 * V_9 )
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
static bool F_185 ( struct V_163 * V_164 )
{
struct V_182 * V_183 = F_182 ( V_164 -> V_184 -> V_49 ) ;
return V_183 && F_186 ( V_183 ) ;
}
static bool F_187 ( T_2 V_186 , T_5 V_187 )
{
return ! F_46 ( V_186 , V_187 ) ;
}
static void F_188 ( struct V_163 * V_164 )
{
struct V_9 * V_9 = V_164 -> V_9 ;
struct V_37 * V_188 = V_164 -> V_184 -> V_49 ;
struct V_189 * V_190 = & F_182 ( V_188 ) -> V_191 ;
T_2 V_186 = V_9 -> V_46 << V_86 ;
const char * V_192 = NULL ;
char V_193 [ V_194 ] ;
if ( ! V_164 -> V_170 . V_128 )
return;
if ( ! F_185 ( V_164 ) )
V_192 = L_23 ;
else if ( V_190 -> V_195 < V_9 -> V_46 )
V_192 = L_24 ;
else if ( V_190 -> V_196 > V_186 )
V_192 = L_25 ;
else if ( ! F_187 ( V_186 , V_190 -> V_196 ) )
V_192 = L_26 ;
if ( V_192 ) {
F_103 ( L_27 , F_189 ( V_188 , V_193 ) , V_192 ) ;
V_164 -> V_170 . V_128 = false ;
}
}
static int F_190 ( struct V_9 * V_9 , struct V_173 * V_116 )
{
struct V_163 * V_164 = V_116 -> V_165 ;
enum V_122 V_167 = F_100 ( V_9 ) ;
enum V_122 V_162 = V_164 -> V_170 . V_161 ;
V_164 -> V_170 . V_161 = V_167 ;
V_9 -> V_116 = V_116 ;
V_9 -> V_106 = V_164 -> V_170 ;
V_9 -> V_114 = V_164 -> V_114 ;
F_109 ( V_9 , V_162 ) ;
return 0 ;
}
static void F_191 ( struct V_9 * V_9 , struct V_173 * V_116 )
{
if ( V_9 -> V_116 == V_116 )
V_9 -> V_116 = NULL ;
}
static void F_192 ( struct V_197 * V_106 )
{
V_106 -> V_161 = V_119 ;
V_106 -> V_107 = true ;
V_106 -> V_198 = true ;
V_106 -> V_128 = true ;
V_106 -> V_123 = false ;
}
static void F_193 ( struct V_9 * V_9 )
{
F_27 ( V_9 ) ;
if ( F_194 ( V_9 -> V_80 ) < 0 )
F_103 ( L_28 , V_132 ) ;
F_195 ( V_9 -> V_17 ) ;
F_196 ( V_9 -> V_98 ) ;
if ( V_9 -> V_10 )
F_197 ( V_9 -> V_10 ) ;
if ( V_9 -> V_89 )
F_70 ( V_9 -> V_89 , V_9 -> V_72 ) ;
F_198 ( V_9 -> V_72 ) ;
F_199 ( V_9 -> V_104 ) ;
F_199 ( V_9 -> V_58 ) ;
F_200 ( V_9 ) ;
}
static struct V_9 * F_201 ( struct V_33 * V_36 ,
struct V_37 * V_199 ,
unsigned long V_186 ,
int V_200 , char * * error )
{
int V_15 ;
void * V_201 ;
struct V_9 * V_9 ;
struct V_202 * V_80 ;
bool V_203 = V_200 ? false : true ;
V_80 = F_202 ( V_199 , V_186 , V_203 ) ;
if ( F_203 ( V_80 ) ) {
* error = L_29 ;
return (struct V_9 * ) V_80 ;
}
V_9 = F_204 ( sizeof( * V_9 ) , V_204 ) ;
if ( ! V_9 ) {
* error = L_30 ;
V_201 = F_205 ( - V_91 ) ;
goto V_205;
}
V_9 -> V_80 = V_80 ;
V_9 -> V_46 = V_186 ;
if ( V_186 & ( V_186 - 1 ) )
V_9 -> V_42 = - 1 ;
else
V_9 -> V_42 = F_206 ( V_186 ) ;
V_9 -> V_114 = 0 ;
F_192 ( & V_9 -> V_106 ) ;
V_9 -> V_17 = F_207 ( V_206 ) ;
if ( ! V_9 -> V_17 ) {
* error = L_31 ;
V_201 = F_205 ( - V_91 ) ;
goto V_207;
}
V_9 -> V_98 = F_208 ( & V_208 ) ;
if ( F_203 ( V_9 -> V_98 ) ) {
V_15 = F_209 ( V_9 -> V_98 ) ;
* error = L_32 ;
V_201 = F_205 ( V_15 ) ;
goto V_209;
}
V_9 -> V_10 = F_210 ( L_33 V_210 , V_211 ) ;
if ( ! V_9 -> V_10 ) {
* error = L_34 ;
V_201 = F_205 ( - V_91 ) ;
goto V_212;
}
F_211 ( & V_9 -> V_11 , F_151 ) ;
F_212 ( & V_9 -> V_155 , F_153 ) ;
F_212 ( & V_9 -> V_156 , F_156 ) ;
F_213 ( & V_9 -> V_25 ) ;
F_33 ( & V_9 -> V_59 ) ;
F_22 ( & V_9 -> V_63 ) ;
F_22 ( & V_9 -> V_130 ) ;
F_22 ( & V_9 -> V_150 ) ;
V_9 -> V_115 = false ;
V_9 -> V_104 = F_214 () ;
if ( ! V_9 -> V_104 ) {
* error = L_35 ;
V_201 = F_205 ( - V_91 ) ;
goto V_213;
}
V_9 -> V_58 = F_214 () ;
if ( ! V_9 -> V_58 ) {
* error = L_36 ;
V_201 = F_205 ( - V_91 ) ;
goto V_214;
}
V_9 -> V_89 = NULL ;
V_9 -> V_72 = F_215 ( V_215 ,
V_216 ) ;
if ( ! V_9 -> V_72 ) {
* error = L_37 ;
V_201 = F_205 ( - V_91 ) ;
goto V_217;
}
V_9 -> V_218 = 1 ;
V_9 -> V_137 = V_136 ;
V_9 -> V_36 = V_36 ;
V_9 -> V_38 = V_199 ;
F_23 ( V_9 ) ;
return V_9 ;
V_217:
F_199 ( V_9 -> V_58 ) ;
V_214:
F_199 ( V_9 -> V_104 ) ;
V_213:
F_197 ( V_9 -> V_10 ) ;
V_212:
F_196 ( V_9 -> V_98 ) ;
V_209:
F_195 ( V_9 -> V_17 ) ;
V_207:
F_200 ( V_9 ) ;
V_205:
if ( F_194 ( V_80 ) )
F_103 ( L_28 , V_132 ) ;
return V_201 ;
}
static void F_216 ( struct V_9 * V_9 )
{
F_24 ( ! F_25 ( & V_29 . V_30 ) ) ;
V_9 -> V_218 ++ ;
}
static void F_217 ( struct V_9 * V_9 )
{
F_24 ( ! F_25 ( & V_29 . V_30 ) ) ;
F_24 ( ! V_9 -> V_218 ) ;
if ( ! -- V_9 -> V_218 )
F_193 ( V_9 ) ;
}
static struct V_9 * F_218 ( struct V_33 * V_36 ,
struct V_37 * V_199 ,
unsigned long V_186 , int V_200 ,
char * * error , int * V_219 )
{
struct V_9 * V_9 = F_31 ( V_199 ) ;
if ( V_9 ) {
if ( V_9 -> V_36 != V_36 ) {
* error = L_38 ;
return F_205 ( - V_220 ) ;
}
F_216 ( V_9 ) ;
} else {
V_9 = F_29 ( V_36 ) ;
if ( V_9 ) {
if ( V_9 -> V_38 != V_199 ) {
* error = L_39 ;
return F_205 ( - V_112 ) ;
}
F_216 ( V_9 ) ;
} else {
V_9 = F_201 ( V_36 , V_199 , V_186 , V_200 , error ) ;
* V_219 = 1 ;
}
}
return V_9 ;
}
static void F_219 ( struct V_173 * V_116 )
{
struct V_163 * V_164 = V_116 -> V_165 ;
F_220 ( & V_29 . V_30 ) ;
F_191 ( V_164 -> V_9 , V_116 ) ;
F_217 ( V_164 -> V_9 ) ;
F_221 ( V_116 , V_164 -> V_199 ) ;
F_221 ( V_116 , V_164 -> V_184 ) ;
F_200 ( V_164 ) ;
F_222 ( & V_29 . V_30 ) ;
}
static int F_223 ( struct V_221 * V_222 , struct V_197 * V_106 ,
struct V_173 * V_116 )
{
int V_15 ;
unsigned V_223 ;
const char * V_224 ;
static struct V_225 V_226 [] = {
{ 0 , 4 , L_40 } ,
} ;
if ( ! V_222 -> V_223 )
return 0 ;
V_15 = F_224 ( V_226 , V_222 , & V_223 , & V_116 -> error ) ;
if ( V_15 )
return - V_112 ;
while ( V_223 && ! V_15 ) {
V_224 = F_225 ( V_222 ) ;
V_223 -- ;
if ( ! strcasecmp ( V_224 , L_41 ) )
V_106 -> V_107 = false ;
else if ( ! strcasecmp ( V_224 , L_42 ) )
V_106 -> V_198 = false ;
else if ( ! strcasecmp ( V_224 , L_43 ) )
V_106 -> V_128 = false ;
else if ( ! strcasecmp ( V_224 , L_44 ) )
V_106 -> V_161 = V_111 ;
else if ( ! strcasecmp ( V_224 , L_45 ) )
V_106 -> V_123 = true ;
else {
V_116 -> error = L_46 ;
V_15 = - V_112 ;
break;
}
}
return V_15 ;
}
static void F_226 ( void * V_66 )
{
struct V_9 * V_9 = V_66 ;
F_103 ( L_47 ,
F_104 ( V_9 -> V_36 ) ) ;
F_105 ( V_9 -> V_116 -> V_117 ) ;
}
static T_2 F_227 ( struct V_37 * V_49 )
{
return F_228 ( V_49 -> V_227 ) >> V_86 ;
}
static void F_229 ( struct V_37 * V_49 )
{
T_2 V_228 = F_227 ( V_49 ) ;
char V_229 [ V_194 ] ;
if ( V_228 > V_230 )
F_103 ( L_48 ,
F_189 ( V_49 , V_229 ) , V_231 ) ;
}
static T_2 F_230 ( struct V_37 * V_49 )
{
T_2 V_228 = F_227 ( V_49 ) ;
if ( V_228 > V_231 )
V_228 = V_231 ;
return V_228 ;
}
static T_1 F_231 ( struct V_37 * V_49 )
{
T_2 V_228 = F_230 ( V_49 ) ;
F_46 ( V_228 , V_232 ) ;
return V_228 ;
}
static T_1 F_232 ( struct V_163 * V_164 )
{
T_1 V_233 = F_231 ( V_164 -> V_199 -> V_49 ) / 4 ;
return F_233 ( ( T_1 ) 1024ULL , V_233 ) ;
}
static int F_234 ( struct V_173 * V_116 , unsigned V_223 , char * * V_234 )
{
int V_15 , V_235 = 0 ;
struct V_163 * V_164 ;
struct V_9 * V_9 ;
struct V_197 V_106 ;
struct V_221 V_222 ;
struct V_99 * V_184 ;
unsigned long V_186 ;
T_1 V_114 ;
struct V_99 * V_199 ;
T_6 V_236 ;
F_220 ( & V_29 . V_30 ) ;
if ( V_223 < 4 ) {
V_116 -> error = L_49 ;
V_15 = - V_112 ;
goto V_237;
}
V_222 . V_223 = V_223 ;
V_222 . V_234 = V_234 ;
F_192 ( & V_106 ) ;
F_235 ( & V_222 , 4 ) ;
V_15 = F_223 ( & V_222 , & V_106 , V_116 ) ;
if ( V_15 )
goto V_237;
V_236 = V_238 | ( ( V_106 . V_161 == V_111 ) ? 0 : V_239 ) ;
V_15 = F_236 ( V_116 , V_234 [ 0 ] , V_236 , & V_199 ) ;
if ( V_15 ) {
V_116 -> error = L_50 ;
goto V_237;
}
F_229 ( V_199 -> V_49 ) ;
V_15 = F_236 ( V_116 , V_234 [ 1 ] , V_238 | V_239 , & V_184 ) ;
if ( V_15 ) {
V_116 -> error = L_51 ;
goto V_240;
}
if ( F_237 ( V_234 [ 2 ] , 10 , & V_186 ) || ! V_186 ||
V_186 < V_241 ||
V_186 > V_242 ||
V_186 & ( V_241 - 1 ) ) {
V_116 -> error = L_52 ;
V_15 = - V_112 ;
goto V_73;
}
if ( F_238 ( V_234 [ 3 ] , 10 , ( unsigned long long * ) & V_114 ) ) {
V_116 -> error = L_53 ;
V_15 = - V_112 ;
goto V_73;
}
V_164 = F_239 ( sizeof( * V_164 ) , V_204 ) ;
if ( ! V_164 ) {
V_15 = - V_91 ;
goto V_73;
}
V_9 = F_218 ( F_240 ( V_116 -> V_117 ) , V_199 -> V_49 ,
V_186 , V_106 . V_161 == V_111 , & V_116 -> error , & V_235 ) ;
if ( F_203 ( V_9 ) ) {
V_15 = F_209 ( V_9 ) ;
goto V_243;
}
if ( ! V_235 && V_106 . V_198 != V_9 -> V_106 . V_198 ) {
V_116 -> error = L_54 ;
V_15 = - V_112 ;
goto V_244;
}
V_164 -> V_9 = V_9 ;
V_164 -> V_116 = V_116 ;
V_164 -> V_199 = V_199 ;
V_164 -> V_184 = V_184 ;
V_164 -> V_114 = V_114 ;
V_164 -> V_170 = V_164 -> V_245 = V_106 ;
V_116 -> V_246 = 1 ;
V_116 -> V_247 = true ;
if ( V_106 . V_198 && V_106 . V_128 ) {
V_116 -> V_248 = 1 ;
V_116 -> V_249 = true ;
}
V_116 -> V_165 = V_164 ;
V_15 = F_241 ( V_164 -> V_9 -> V_80 ,
F_232 ( V_164 ) ,
F_226 ,
V_9 ) ;
if ( V_15 )
goto V_243;
V_164 -> V_181 . V_250 = F_181 ;
F_242 ( V_116 -> V_117 , & V_164 -> V_181 ) ;
F_222 ( & V_29 . V_30 ) ;
return 0 ;
V_244:
F_217 ( V_9 ) ;
V_243:
F_200 ( V_164 ) ;
V_73:
F_221 ( V_116 , V_184 ) ;
V_240:
F_221 ( V_116 , V_199 ) ;
V_237:
F_222 ( & V_29 . V_30 ) ;
return V_15 ;
}
static int F_243 ( struct V_173 * V_116 , struct V_12 * V_12 )
{
int V_15 ;
struct V_163 * V_164 = V_116 -> V_165 ;
struct V_9 * V_9 = V_164 -> V_9 ;
unsigned long V_24 ;
F_15 ( & V_9 -> V_25 , V_24 ) ;
V_12 -> V_47 = V_164 -> V_184 -> V_49 ;
V_15 = V_176 ;
F_16 ( & V_9 -> V_25 , V_24 ) ;
return V_15 ;
}
static int F_244 ( struct V_173 * V_116 , bool * V_251 )
{
int V_15 ;
struct V_163 * V_164 = V_116 -> V_165 ;
struct V_9 * V_9 = V_164 -> V_9 ;
T_2 V_252 = V_116 -> V_103 ;
T_1 V_253 ;
* V_251 = false ;
( void ) F_46 ( V_252 , V_9 -> V_46 ) ;
V_15 = F_245 ( V_9 -> V_80 , & V_253 ) ;
if ( V_15 ) {
F_171 ( L_55 ,
F_104 ( V_9 -> V_36 ) ) ;
return V_15 ;
}
if ( V_252 < V_253 ) {
F_171 ( L_56 ,
F_104 ( V_9 -> V_36 ) ,
( unsigned long long ) V_252 , V_253 ) ;
return - V_112 ;
} else if ( V_252 > V_253 ) {
if ( F_169 ( V_9 -> V_80 ) ) {
F_171 ( L_57 ,
F_104 ( V_9 -> V_36 ) ) ;
return 0 ;
}
if ( V_253 )
F_168 ( L_58 ,
F_104 ( V_9 -> V_36 ) ,
V_253 , ( unsigned long long ) V_252 ) ;
V_15 = F_246 ( V_9 -> V_80 , V_252 ) ;
if ( V_15 ) {
F_73 ( V_9 , L_59 , V_15 ) ;
return V_15 ;
}
* V_251 = true ;
}
return 0 ;
}
static int F_247 ( struct V_173 * V_116 , bool * V_251 )
{
int V_15 ;
struct V_163 * V_164 = V_116 -> V_165 ;
struct V_9 * V_9 = V_164 -> V_9 ;
T_1 V_228 , V_254 ;
* V_251 = false ;
V_228 = F_231 ( V_9 -> V_38 ) ;
V_15 = F_248 ( V_9 -> V_80 , & V_254 ) ;
if ( V_15 ) {
F_171 ( L_60 ,
F_104 ( V_9 -> V_36 ) ) ;
return V_15 ;
}
if ( V_228 < V_254 ) {
F_171 ( L_61 ,
F_104 ( V_9 -> V_36 ) ,
V_228 , V_254 ) ;
return - V_112 ;
} else if ( V_228 > V_254 ) {
if ( F_169 ( V_9 -> V_80 ) ) {
F_171 ( L_62 ,
F_104 ( V_9 -> V_36 ) ) ;
return 0 ;
}
F_229 ( V_9 -> V_38 ) ;
F_168 ( L_63 ,
F_104 ( V_9 -> V_36 ) ,
V_254 , V_228 ) ;
V_15 = F_249 ( V_9 -> V_80 , V_228 ) ;
if ( V_15 ) {
F_73 ( V_9 , L_64 , V_15 ) ;
return V_15 ;
}
* V_251 = true ;
}
return 0 ;
}
static int F_250 ( struct V_173 * V_116 )
{
int V_15 ;
bool V_255 , V_256 ;
struct V_163 * V_164 = V_116 -> V_165 ;
struct V_9 * V_9 = V_164 -> V_9 ;
V_15 = F_190 ( V_9 , V_116 ) ;
if ( V_15 )
return V_15 ;
V_15 = F_244 ( V_116 , & V_255 ) ;
if ( V_15 )
return V_15 ;
V_15 = F_247 ( V_116 , & V_256 ) ;
if ( V_15 )
return V_15 ;
if ( V_255 || V_256 )
( void ) F_99 ( V_9 ) ;
return 0 ;
}
static void F_251 ( struct V_173 * V_116 )
{
struct V_163 * V_164 = V_116 -> V_165 ;
struct V_9 * V_9 = V_164 -> V_9 ;
unsigned long V_24 ;
F_15 ( & V_9 -> V_25 , V_24 ) ;
V_9 -> V_115 = false ;
F_16 ( & V_9 -> V_25 , V_24 ) ;
F_184 ( V_9 ) ;
F_153 ( & V_9 -> V_155 . V_257 ) ;
}
static void F_252 ( struct V_173 * V_116 )
{
struct V_163 * V_164 = V_116 -> V_165 ;
struct V_9 * V_9 = V_164 -> V_9 ;
F_253 ( & V_9 -> V_155 ) ;
F_253 ( & V_9 -> V_156 ) ;
F_254 ( V_9 -> V_10 ) ;
( void ) F_99 ( V_9 ) ;
}
static int F_255 ( unsigned V_223 , unsigned V_258 )
{
if ( V_223 != V_258 ) {
F_103 ( L_65 ,
V_223 , V_258 ) ;
return - V_112 ;
}
return 0 ;
}
static int F_256 ( char * V_259 , T_7 * V_260 , int V_261 )
{
if ( ! F_238 ( V_259 , 10 , ( unsigned long long * ) V_260 ) &&
* V_260 <= V_262 )
return 0 ;
if ( V_261 )
F_103 ( L_66 , V_259 ) ;
return - V_112 ;
}
static int F_257 ( unsigned V_223 , char * * V_234 , struct V_9 * V_9 )
{
T_7 V_260 ;
int V_15 ;
V_15 = F_255 ( V_223 , 2 ) ;
if ( V_15 )
return V_15 ;
V_15 = F_256 ( V_234 [ 1 ] , & V_260 , 1 ) ;
if ( V_15 )
return V_15 ;
V_15 = F_258 ( V_9 -> V_80 , V_260 ) ;
if ( V_15 ) {
F_103 ( L_67 ,
V_234 [ 1 ] ) ;
return V_15 ;
}
return 0 ;
}
static int F_259 ( unsigned V_223 , char * * V_234 , struct V_9 * V_9 )
{
T_7 V_260 ;
T_7 V_263 ;
int V_15 ;
V_15 = F_255 ( V_223 , 3 ) ;
if ( V_15 )
return V_15 ;
V_15 = F_256 ( V_234 [ 1 ] , & V_260 , 1 ) ;
if ( V_15 )
return V_15 ;
V_15 = F_256 ( V_234 [ 2 ] , & V_263 , 1 ) ;
if ( V_15 )
return V_15 ;
V_15 = F_260 ( V_9 -> V_80 , V_260 , V_263 ) ;
if ( V_15 ) {
F_103 ( L_68 ,
V_234 [ 1 ] , V_234 [ 2 ] ) ;
return V_15 ;
}
return 0 ;
}
static int F_261 ( unsigned V_223 , char * * V_234 , struct V_9 * V_9 )
{
T_7 V_260 ;
int V_15 ;
V_15 = F_255 ( V_223 , 2 ) ;
if ( V_15 )
return V_15 ;
V_15 = F_256 ( V_234 [ 1 ] , & V_260 , 1 ) ;
if ( V_15 )
return V_15 ;
V_15 = F_262 ( V_9 -> V_80 , V_260 ) ;
if ( V_15 )
F_103 ( L_69 , V_234 [ 1 ] ) ;
return V_15 ;
}
static int F_263 ( unsigned V_223 , char * * V_234 , struct V_9 * V_9 )
{
T_7 V_264 , V_265 ;
int V_15 ;
V_15 = F_255 ( V_223 , 3 ) ;
if ( V_15 )
return V_15 ;
if ( F_238 ( V_234 [ 1 ] , 10 , ( unsigned long long * ) & V_264 ) ) {
F_103 ( L_70 , V_234 [ 1 ] ) ;
return - V_112 ;
}
if ( F_238 ( V_234 [ 2 ] , 10 , ( unsigned long long * ) & V_265 ) ) {
F_103 ( L_71 , V_234 [ 2 ] ) ;
return - V_112 ;
}
V_15 = F_264 ( V_9 -> V_80 , V_264 , V_265 ) ;
if ( V_15 ) {
F_103 ( L_72 ,
V_234 [ 1 ] , V_234 [ 2 ] ) ;
return V_15 ;
}
return 0 ;
}
static int F_265 ( unsigned V_223 , char * * V_234 , struct V_9 * V_9 )
{
int V_15 ;
V_15 = F_255 ( V_223 , 1 ) ;
if ( V_15 )
return V_15 ;
( void ) F_99 ( V_9 ) ;
V_15 = F_266 ( V_9 -> V_80 ) ;
if ( V_15 )
F_103 ( L_73 ) ;
return V_15 ;
}
static int F_267 ( unsigned V_223 , char * * V_234 , struct V_9 * V_9 )
{
int V_15 ;
V_15 = F_255 ( V_223 , 1 ) ;
if ( V_15 )
return V_15 ;
V_15 = F_268 ( V_9 -> V_80 ) ;
if ( V_15 )
F_103 ( L_74 ) ;
return V_15 ;
}
static int F_269 ( struct V_173 * V_116 , unsigned V_223 , char * * V_234 )
{
int V_15 = - V_112 ;
struct V_163 * V_164 = V_116 -> V_165 ;
struct V_9 * V_9 = V_164 -> V_9 ;
if ( ! strcasecmp ( V_234 [ 0 ] , L_75 ) )
V_15 = F_257 ( V_223 , V_234 , V_9 ) ;
else if ( ! strcasecmp ( V_234 [ 0 ] , L_76 ) )
V_15 = F_259 ( V_223 , V_234 , V_9 ) ;
else if ( ! strcasecmp ( V_234 [ 0 ] , L_77 ) )
V_15 = F_261 ( V_223 , V_234 , V_9 ) ;
else if ( ! strcasecmp ( V_234 [ 0 ] , L_78 ) )
V_15 = F_263 ( V_223 , V_234 , V_9 ) ;
else if ( ! strcasecmp ( V_234 [ 0 ] , L_79 ) )
V_15 = F_265 ( V_223 , V_234 , V_9 ) ;
else if ( ! strcasecmp ( V_234 [ 0 ] , L_80 ) )
V_15 = F_267 ( V_223 , V_234 , V_9 ) ;
else
F_103 ( L_81 , V_234 [ 0 ] ) ;
if ( ! V_15 )
( void ) F_99 ( V_9 ) ;
return V_15 ;
}
static void F_270 ( struct V_197 * V_106 , char * V_118 ,
unsigned V_266 , unsigned V_267 )
{
unsigned V_97 = ! V_106 -> V_107 + ! V_106 -> V_198 +
! V_106 -> V_128 + ( V_106 -> V_161 == V_111 ) +
V_106 -> V_123 ;
F_271 ( L_82 , V_97 ) ;
if ( ! V_106 -> V_107 )
F_271 ( L_83 ) ;
if ( ! V_106 -> V_198 )
F_271 ( L_84 ) ;
if ( ! V_106 -> V_128 )
F_271 ( L_85 ) ;
if ( V_106 -> V_161 == V_111 )
F_271 ( L_86 ) ;
if ( V_106 -> V_123 )
F_271 ( L_87 ) ;
}
static void F_272 ( struct V_173 * V_116 , T_8 type ,
unsigned V_268 , char * V_118 , unsigned V_267 )
{
int V_15 ;
unsigned V_266 = 0 ;
T_9 V_269 ;
T_1 V_270 ;
T_1 V_271 ;
T_1 V_272 ;
T_1 V_273 ;
T_1 V_274 ;
char V_193 [ V_194 ] ;
char V_275 [ V_194 ] ;
struct V_163 * V_164 = V_116 -> V_165 ;
struct V_9 * V_9 = V_164 -> V_9 ;
switch ( type ) {
case V_276 :
if ( F_100 ( V_9 ) == V_124 ) {
F_271 ( L_88 ) ;
break;
}
if ( ! ( V_268 & V_277 ) && ! F_273 ( V_116 ) )
( void ) F_99 ( V_9 ) ;
V_15 = F_274 ( V_9 -> V_80 , & V_269 ) ;
if ( V_15 ) {
F_171 ( L_89 ,
F_104 ( V_9 -> V_36 ) , V_15 ) ;
goto V_67;
}
V_15 = F_275 ( V_9 -> V_80 , & V_271 ) ;
if ( V_15 ) {
F_171 ( L_90 ,
F_104 ( V_9 -> V_36 ) , V_15 ) ;
goto V_67;
}
V_15 = F_248 ( V_9 -> V_80 , & V_273 ) ;
if ( V_15 ) {
F_171 ( L_91 ,
F_104 ( V_9 -> V_36 ) , V_15 ) ;
goto V_67;
}
V_15 = F_108 ( V_9 -> V_80 , & V_270 ) ;
if ( V_15 ) {
F_171 ( L_92 ,
F_104 ( V_9 -> V_36 ) , V_15 ) ;
goto V_67;
}
V_15 = F_245 ( V_9 -> V_80 , & V_272 ) ;
if ( V_15 ) {
F_171 ( L_93 ,
F_104 ( V_9 -> V_36 ) , V_15 ) ;
goto V_67;
}
V_15 = F_276 ( V_9 -> V_80 , & V_274 ) ;
if ( V_15 ) {
F_171 ( L_94 ,
F_104 ( V_9 -> V_36 ) , V_15 ) ;
goto V_67;
}
F_271 ( L_95 ,
( unsigned long long ) V_269 ,
( unsigned long long ) ( V_273 - V_271 ) ,
( unsigned long long ) V_273 ,
( unsigned long long ) ( V_272 - V_270 ) ,
( unsigned long long ) V_272 ) ;
if ( V_274 )
F_271 ( L_96 , V_274 ) ;
else
F_271 ( L_97 ) ;
if ( V_9 -> V_106 . V_161 == V_120 )
F_271 ( L_98 ) ;
else if ( V_9 -> V_106 . V_161 == V_111 )
F_271 ( L_99 ) ;
else
F_271 ( L_100 ) ;
if ( ! V_9 -> V_106 . V_198 )
F_271 ( L_84 ) ;
else if ( V_9 -> V_106 . V_128 )
F_271 ( L_101 ) ;
else
F_271 ( L_85 ) ;
if ( V_9 -> V_106 . V_123 )
F_271 ( L_87 ) ;
else
F_271 ( L_102 ) ;
break;
case V_278 :
F_271 ( L_103 ,
F_277 ( V_193 , V_164 -> V_199 -> V_49 -> V_279 ) ,
F_277 ( V_275 , V_164 -> V_184 -> V_49 -> V_279 ) ,
( unsigned long ) V_9 -> V_46 ,
( unsigned long long ) V_164 -> V_114 ) ;
F_270 ( & V_164 -> V_245 , V_118 , V_266 , V_267 ) ;
break;
}
return;
V_67:
F_271 ( L_104 ) ;
}
static int F_278 ( struct V_173 * V_116 ,
T_10 V_83 , void * V_280 )
{
struct V_163 * V_164 = V_116 -> V_165 ;
return V_83 ( V_116 , V_164 -> V_184 , 0 , V_116 -> V_103 , V_280 ) ;
}
static int F_279 ( struct V_173 * V_116 , struct V_281 * V_282 ,
struct V_283 * V_284 , int V_285 )
{
struct V_163 * V_164 = V_116 -> V_165 ;
struct V_182 * V_183 = F_182 ( V_164 -> V_184 -> V_49 ) ;
if ( ! V_183 -> V_286 )
return V_285 ;
V_282 -> V_47 = V_164 -> V_184 -> V_49 ;
return F_233 ( V_285 , V_183 -> V_286 ( V_183 , V_282 , V_284 ) ) ;
}
static void F_280 ( struct V_163 * V_164 , struct V_189 * V_191 )
{
struct V_9 * V_9 = V_164 -> V_9 ;
struct V_189 * V_190 ;
V_191 -> V_195 = V_9 -> V_46 ;
if ( V_164 -> V_170 . V_128 ) {
V_190 = & F_182 ( V_164 -> V_184 -> V_49 ) -> V_191 ;
V_191 -> V_196 = F_281 ( V_190 -> V_196 ,
V_9 -> V_46 << V_86 ) ;
} else
V_191 -> V_196 = V_9 -> V_46 << V_86 ;
}
static void F_282 ( struct V_173 * V_116 , struct V_189 * V_191 )
{
struct V_163 * V_164 = V_116 -> V_165 ;
struct V_9 * V_9 = V_164 -> V_9 ;
T_9 V_287 = V_191 -> V_288 >> V_86 ;
if ( V_287 < V_9 -> V_46 ||
F_283 ( V_287 , V_9 -> V_46 ) ) {
F_284 ( V_191 , V_9 -> V_46 << V_86 ) ;
F_285 ( V_191 , V_9 -> V_46 << V_86 ) ;
}
if ( ! V_164 -> V_170 . V_198 ) {
V_191 -> V_196 = 0 ;
return;
}
F_188 ( V_164 ) ;
F_280 ( V_164 , V_191 ) ;
}
static void F_145 ( struct V_22 * V_23 )
{
F_69 ( & V_23 -> V_289 ) ;
}
static void F_148 ( struct V_22 * V_23 )
{
if ( F_61 ( & V_23 -> V_289 ) )
F_159 ( & V_23 -> V_290 ) ;
}
static void F_286 ( struct V_173 * V_116 )
{
struct V_22 * V_23 = V_116 -> V_165 ;
unsigned long V_24 ;
F_148 ( V_23 ) ;
F_163 ( & V_23 -> V_290 ) ;
F_15 ( & V_23 -> V_9 -> V_25 , V_24 ) ;
F_287 ( & V_23 -> V_32 ) ;
F_16 ( & V_23 -> V_9 -> V_25 , V_24 ) ;
F_288 () ;
F_220 ( & V_29 . V_30 ) ;
F_217 ( V_23 -> V_9 ) ;
F_289 ( V_23 -> V_2 ) ;
F_221 ( V_116 , V_23 -> V_48 ) ;
if ( V_23 -> V_50 )
F_221 ( V_116 , V_23 -> V_50 ) ;
F_200 ( V_23 ) ;
F_222 ( & V_29 . V_30 ) ;
}
static int F_290 ( struct V_173 * V_116 , unsigned V_223 , char * * V_234 )
{
int V_15 ;
struct V_22 * V_23 ;
struct V_99 * V_48 , * V_50 ;
struct V_33 * V_36 ;
unsigned long V_24 ;
F_220 ( & V_29 . V_30 ) ;
if ( V_223 != 2 && V_223 != 3 ) {
V_116 -> error = L_49 ;
V_15 = - V_112 ;
goto V_237;
}
V_23 = V_116 -> V_165 = F_239 ( sizeof( * V_23 ) , V_204 ) ;
if ( ! V_23 ) {
V_116 -> error = L_105 ;
V_15 = - V_91 ;
goto V_237;
}
F_213 ( & V_23 -> V_25 ) ;
F_33 ( & V_23 -> V_26 ) ;
F_33 ( & V_23 -> V_41 ) ;
V_23 -> V_143 = V_291 ;
if ( V_223 == 3 ) {
V_15 = F_236 ( V_116 , V_234 [ 2 ] , V_238 , & V_50 ) ;
if ( V_15 ) {
V_116 -> error = L_106 ;
goto V_292;
}
V_23 -> V_50 = V_50 ;
}
V_15 = F_236 ( V_116 , V_234 [ 0 ] , F_291 ( V_116 -> V_117 ) , & V_48 ) ;
if ( V_15 ) {
V_116 -> error = L_107 ;
goto V_293;
}
V_23 -> V_48 = V_48 ;
if ( F_256 ( V_234 [ 1 ] , ( unsigned long long * ) & V_23 -> V_260 , 0 ) ) {
V_116 -> error = L_108 ;
V_15 = - V_112 ;
goto V_294;
}
V_36 = F_292 ( V_23 -> V_48 -> V_49 -> V_279 ) ;
if ( ! V_36 ) {
V_116 -> error = L_109 ;
V_15 = - V_112 ;
goto V_294;
}
V_23 -> V_9 = F_29 ( V_36 ) ;
if ( ! V_23 -> V_9 ) {
V_116 -> error = L_110 ;
V_15 = - V_112 ;
goto V_295;
}
F_216 ( V_23 -> V_9 ) ;
if ( F_100 ( V_23 -> V_9 ) == V_124 ) {
V_116 -> error = L_111 ;
V_15 = - V_112 ;
goto V_296;
}
V_15 = F_293 ( V_23 -> V_9 -> V_80 , V_23 -> V_260 , & V_23 -> V_2 ) ;
if ( V_15 ) {
V_116 -> error = L_112 ;
goto V_296;
}
V_15 = F_294 ( V_116 , V_23 -> V_9 -> V_46 ) ;
if ( V_15 )
goto V_297;
V_116 -> V_246 = 1 ;
V_116 -> V_298 = true ;
V_116 -> V_299 = sizeof( struct V_54 ) ;
V_116 -> V_247 = true ;
if ( V_23 -> V_9 -> V_106 . V_198 ) {
V_116 -> V_249 = true ;
V_116 -> V_248 = 1 ;
V_116 -> V_300 = true ;
}
F_295 ( V_36 ) ;
F_222 ( & V_29 . V_30 ) ;
F_93 ( & V_23 -> V_289 , 1 ) ;
F_162 ( & V_23 -> V_290 ) ;
F_15 ( & V_23 -> V_9 -> V_25 , V_24 ) ;
F_296 ( & V_23 -> V_32 , & V_23 -> V_9 -> V_150 ) ;
F_16 ( & V_23 -> V_9 -> V_25 , V_24 ) ;
F_288 () ;
return 0 ;
V_297:
F_289 ( V_23 -> V_2 ) ;
V_296:
F_217 ( V_23 -> V_9 ) ;
V_295:
F_295 ( V_36 ) ;
V_294:
F_221 ( V_116 , V_23 -> V_48 ) ;
V_293:
if ( V_23 -> V_50 )
F_221 ( V_116 , V_23 -> V_50 ) ;
V_292:
F_200 ( V_23 ) ;
V_237:
F_222 ( & V_29 . V_30 ) ;
return V_15 ;
}
static int F_297 ( struct V_173 * V_116 , struct V_12 * V_12 )
{
V_12 -> V_44 . V_45 = F_298 ( V_116 , V_12 -> V_44 . V_45 ) ;
return F_179 ( V_116 , V_12 ) ;
}
static int F_299 ( struct V_173 * V_116 , struct V_12 * V_12 , int V_67 )
{
unsigned long V_24 ;
struct V_54 * V_55 = F_52 ( V_12 , sizeof( struct V_54 ) ) ;
struct V_81 V_257 ;
struct V_60 * V_61 , * V_35 ;
struct V_9 * V_9 = V_55 -> V_23 -> V_9 ;
if ( V_55 -> V_133 ) {
F_22 ( & V_257 ) ;
F_300 ( V_55 -> V_133 , & V_257 ) ;
F_15 ( & V_9 -> V_25 , V_24 ) ;
F_82 (m, tmp, &work, list) {
F_28 ( & V_61 -> V_32 ) ;
F_60 ( V_61 ) ;
}
F_16 ( & V_9 -> V_25 , V_24 ) ;
}
if ( V_55 -> V_57 ) {
F_22 ( & V_257 ) ;
F_300 ( V_55 -> V_57 , & V_257 ) ;
if ( ! F_143 ( & V_257 ) ) {
F_15 ( & V_9 -> V_25 , V_24 ) ;
F_82 (m, tmp, &work, list)
F_62 ( & V_61 -> V_32 , & V_9 -> V_130 ) ;
F_16 ( & V_9 -> V_25 , V_24 ) ;
F_4 ( V_9 ) ;
}
}
return 0 ;
}
static void F_301 ( struct V_173 * V_116 )
{
struct V_22 * V_23 = V_116 -> V_165 ;
if ( F_302 ( V_116 ) )
V_159 ( V_23 , F_165 ) ;
}
static void F_303 ( struct V_173 * V_116 )
{
struct V_22 * V_23 = V_116 -> V_165 ;
V_159 ( V_23 , F_166 ) ;
}
static int F_304 ( struct V_173 * V_116 )
{
struct V_22 * V_23 = V_116 -> V_165 ;
if ( V_23 -> V_50 )
V_23 -> V_110 = F_227 ( V_23 -> V_50 -> V_49 ) ;
return 0 ;
}
static void F_305 ( struct V_173 * V_116 , T_8 type ,
unsigned V_268 , char * V_118 , unsigned V_267 )
{
int V_15 ;
T_11 V_266 = 0 ;
T_1 V_301 , V_302 ;
char V_193 [ V_194 ] ;
struct V_22 * V_23 = V_116 -> V_165 ;
if ( F_100 ( V_23 -> V_9 ) == V_124 ) {
F_271 ( L_88 ) ;
return;
}
if ( ! V_23 -> V_2 )
F_271 ( L_113 ) ;
else {
switch ( type ) {
case V_276 :
V_15 = F_306 ( V_23 -> V_2 , & V_301 ) ;
if ( V_15 ) {
F_171 ( L_114 , V_15 ) ;
goto V_67;
}
V_15 = F_307 ( V_23 -> V_2 , & V_302 ) ;
if ( V_15 < 0 ) {
F_171 ( L_115 , V_15 ) ;
goto V_67;
}
F_271 ( L_96 , V_301 * V_23 -> V_9 -> V_46 ) ;
if ( V_15 )
F_271 ( L_116 , ( ( V_302 + 1 ) *
V_23 -> V_9 -> V_46 ) - 1 ) ;
else
F_271 ( L_113 ) ;
break;
case V_278 :
F_271 ( L_117 ,
F_277 ( V_193 , V_23 -> V_48 -> V_49 -> V_279 ) ,
( unsigned long ) V_23 -> V_260 ) ;
if ( V_23 -> V_50 )
F_271 ( L_118 , F_277 ( V_193 , V_23 -> V_50 -> V_49 -> V_279 ) ) ;
break;
}
}
return;
V_67:
F_271 ( L_104 ) ;
}
static int F_308 ( struct V_173 * V_116 ,
T_10 V_83 , void * V_280 )
{
T_2 V_303 ;
struct V_22 * V_23 = V_116 -> V_165 ;
struct V_9 * V_9 = V_23 -> V_9 ;
if ( ! V_9 -> V_116 )
return 0 ;
V_303 = V_9 -> V_116 -> V_103 ;
( void ) F_46 ( V_303 , V_9 -> V_46 ) ;
if ( V_303 )
return V_83 ( V_116 , V_23 -> V_48 , 0 , V_9 -> V_46 * V_303 , V_280 ) ;
return 0 ;
}
static int T_12 F_309 ( void )
{
int V_15 ;
F_20 () ;
V_15 = F_310 ( & V_304 ) ;
if ( V_15 )
return V_15 ;
V_15 = F_310 ( & V_305 ) ;
if ( V_15 )
goto V_306;
V_15 = - V_91 ;
V_216 = F_311 ( V_60 , 0 ) ;
if ( ! V_216 )
goto V_307;
return 0 ;
V_307:
F_312 ( & V_305 ) ;
V_306:
F_312 ( & V_304 ) ;
return V_15 ;
}
static void F_313 ( void )
{
F_312 ( & V_304 ) ;
F_312 ( & V_305 ) ;
F_314 ( V_216 ) ;
}
