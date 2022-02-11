static void F_1 ( struct V_1 * V_2 ,
T_1 V_3 , struct V_4 * V_5 )
{
V_5 -> V_6 = 0 ;
V_5 -> V_7 = F_2 ( V_2 ) ;
V_5 -> V_8 = V_3 ;
V_5 -> V_9 = V_3 + 1ULL ;
}
static void F_3 ( struct V_1 * V_2 , T_1 V_3 ,
struct V_4 * V_5 )
{
V_5 -> V_6 = 1 ;
V_5 -> V_7 = F_2 ( V_2 ) ;
V_5 -> V_8 = V_3 ;
V_5 -> V_9 = V_3 + 1ULL ;
}
static void F_4 ( struct V_10 * V_11 )
{
F_5 ( & V_11 -> V_12 ) ;
V_11 -> V_13 = false ;
}
static void F_6 ( struct V_10 * V_11 )
{
V_11 -> V_14 = V_15 + V_16 ;
}
static void F_7 ( struct V_10 * V_11 )
{
if ( ! V_11 -> V_13 && V_15 > V_11 -> V_14 ) {
F_8 ( & V_11 -> V_12 ) ;
V_11 -> V_13 = true ;
}
}
static void F_9 ( struct V_10 * V_11 )
{
if ( V_11 -> V_13 ) {
V_11 -> V_13 = false ;
F_10 ( & V_11 -> V_12 ) ;
}
}
static void F_11 ( struct V_10 * V_11 )
{
F_12 ( & V_11 -> V_12 ) ;
}
static void F_13 ( struct V_10 * V_11 )
{
F_14 ( & V_11 -> V_12 ) ;
}
static void F_15 ( struct V_17 * V_17 )
{
F_16 ( V_17 -> V_18 , & V_17 -> V_19 ) ;
}
static int F_17 ( struct V_17 * V_17 , struct V_4 * V_5 , struct V_20 * V_20 ,
struct V_21 * * V_22 )
{
int V_23 ;
struct V_21 * V_24 ;
V_24 = F_18 ( V_17 -> V_25 , V_26 ) ;
V_23 = F_19 ( V_17 -> V_25 , V_5 , V_20 , V_24 , V_22 ) ;
if ( V_23 )
F_20 ( V_17 -> V_25 , V_24 ) ;
return V_23 ;
}
static void F_21 ( struct V_17 * V_17 ,
struct V_21 * V_27 ,
struct V_28 * V_29 )
{
F_22 ( V_17 -> V_25 , V_27 , V_29 ) ;
F_20 ( V_17 -> V_25 , V_27 ) ;
}
static void F_23 ( struct V_17 * V_17 ,
void (* F_24)( void * , struct V_21 * ) ,
void * V_30 ,
struct V_21 * V_27 )
{
F_25 ( V_17 -> V_25 , F_24 , V_30 , V_27 ) ;
F_20 ( V_17 -> V_25 , V_27 ) ;
}
static void F_26 ( struct V_17 * V_17 ,
struct V_21 * V_27 ,
struct V_28 * V_29 )
{
F_27 ( V_17 -> V_25 , V_27 , V_29 ) ;
F_20 ( V_17 -> V_25 , V_27 ) ;
}
static void F_28 ( struct V_17 * V_17 ,
struct V_21 * V_27 , int V_31 )
{
F_29 ( V_17 -> V_25 , V_27 , V_31 ) ;
F_20 ( V_17 -> V_25 , V_27 ) ;
}
static void F_30 ( struct V_17 * V_17 , struct V_21 * V_27 )
{
F_28 ( V_17 , V_27 , - V_32 ) ;
}
static void F_31 ( struct V_17 * V_17 , struct V_21 * V_27 )
{
F_28 ( V_17 , V_27 , 0 ) ;
}
static void F_32 ( struct V_17 * V_17 , struct V_21 * V_27 )
{
F_28 ( V_17 , V_27 , V_33 ) ;
}
static void F_33 ( void )
{
F_34 ( & V_34 . V_35 ) ;
F_35 ( & V_34 . V_36 ) ;
}
static void F_36 ( struct V_17 * V_17 )
{
F_37 ( ! F_38 ( & V_34 . V_35 ) ) ;
F_39 ( & V_17 -> V_37 , & V_34 . V_36 ) ;
}
static void F_40 ( struct V_17 * V_17 )
{
F_37 ( ! F_38 ( & V_34 . V_35 ) ) ;
F_41 ( & V_17 -> V_37 ) ;
}
static struct V_17 * F_42 ( struct V_38 * V_39 )
{
struct V_17 * V_17 = NULL , * V_40 ;
F_37 ( ! F_38 ( & V_34 . V_35 ) ) ;
F_43 (tmp, &dm_thin_pool_table.pools, list) {
if ( V_40 -> V_41 == V_39 ) {
V_17 = V_40 ;
break;
}
}
return V_17 ;
}
static struct V_17 * F_44 ( struct V_42 * V_43 )
{
struct V_17 * V_17 = NULL , * V_40 ;
F_37 ( ! F_38 ( & V_34 . V_35 ) ) ;
F_43 (tmp, &dm_thin_pool_table.pools, list) {
if ( V_40 -> V_43 == V_43 ) {
V_17 = V_40 ;
break;
}
}
return V_17 ;
}
static void F_45 ( struct V_28 * V_29 , struct V_28 * V_44 )
{
F_46 ( V_29 , V_44 ) ;
F_47 ( V_44 ) ;
}
static void F_48 ( struct V_28 * V_29 , int error )
{
struct V_20 * V_20 ;
while ( ( V_20 = F_49 ( V_29 ) ) )
F_50 ( V_20 , error ) ;
}
static void F_51 ( struct V_45 * V_46 , struct V_28 * V_44 , int error )
{
struct V_28 V_29 ;
unsigned long V_47 ;
F_47 ( & V_29 ) ;
F_52 ( & V_46 -> V_12 , V_47 ) ;
F_45 ( & V_29 , V_44 ) ;
F_53 ( & V_46 -> V_12 , V_47 ) ;
F_48 ( & V_29 , error ) ;
}
static void F_54 ( struct V_45 * V_46 )
{
struct V_17 * V_17 = V_46 -> V_17 ;
unsigned long V_47 ;
struct V_48 V_49 ;
struct V_21 * V_27 , * V_40 ;
F_35 ( & V_49 ) ;
F_52 ( & V_46 -> V_12 , V_47 ) ;
F_55 ( & V_46 -> V_50 , & V_49 ) ;
F_53 ( & V_46 -> V_12 , V_47 ) ;
F_56 (cell, tmp, &cells, user_list)
F_32 ( V_17 , V_27 ) ;
}
static void F_57 ( struct V_45 * V_46 )
{
struct V_28 V_29 ;
unsigned long V_47 ;
F_47 ( & V_29 ) ;
F_52 ( & V_46 -> V_12 , V_47 ) ;
F_45 ( & V_29 , & V_46 -> V_51 ) ;
F_45 ( & V_29 , & V_46 -> V_52 ) ;
F_53 ( & V_46 -> V_12 , V_47 ) ;
F_48 ( & V_29 , V_33 ) ;
F_54 ( V_46 ) ;
}
static void F_58 ( struct V_17 * V_17 )
{
struct V_45 * V_46 ;
F_59 () ;
F_60 (tc, &pool->active_thins, list)
F_51 ( V_46 , & V_46 -> V_52 , - V_32 ) ;
F_61 () ;
}
static bool F_62 ( struct V_17 * V_17 )
{
return V_17 -> V_53 >= 0 ;
}
static T_1 F_63 ( struct V_45 * V_46 , struct V_20 * V_20 )
{
struct V_17 * V_17 = V_46 -> V_17 ;
T_2 V_54 = V_20 -> V_55 . V_56 ;
if ( F_62 ( V_17 ) )
V_54 >>= V_17 -> V_53 ;
else
( void ) F_64 ( V_54 , V_17 -> V_57 ) ;
return V_54 ;
}
static void F_65 ( struct V_45 * V_46 , struct V_20 * V_20 , T_1 V_58 )
{
struct V_17 * V_17 = V_46 -> V_17 ;
T_2 V_56 = V_20 -> V_55 . V_56 ;
V_20 -> V_59 = V_46 -> V_60 -> V_61 ;
if ( F_62 ( V_17 ) )
V_20 -> V_55 . V_56 =
( V_58 << V_17 -> V_53 ) |
( V_56 & ( V_17 -> V_57 - 1 ) ) ;
else
V_20 -> V_55 . V_56 = ( V_58 * V_17 -> V_57 ) +
F_64 ( V_56 , V_17 -> V_57 ) ;
}
static void F_66 ( struct V_45 * V_46 , struct V_20 * V_20 )
{
V_20 -> V_59 = V_46 -> V_62 -> V_61 ;
}
static int F_67 ( struct V_45 * V_46 , struct V_20 * V_20 )
{
return ( V_20 -> V_63 & ( V_64 | V_65 ) ) &&
F_68 ( V_46 -> V_2 ) ;
}
static void F_69 ( struct V_17 * V_17 , struct V_20 * V_20 )
{
struct V_66 * V_67 ;
if ( V_20 -> V_63 & V_68 )
return;
V_67 = F_70 ( V_20 , sizeof( struct V_66 ) ) ;
V_67 -> V_69 = F_71 ( V_17 -> V_70 ) ;
}
static void F_72 ( struct V_45 * V_46 , struct V_20 * V_20 )
{
struct V_17 * V_17 = V_46 -> V_17 ;
unsigned long V_47 ;
if ( ! F_67 ( V_46 , V_20 ) ) {
F_73 ( V_20 ) ;
return;
}
if ( F_74 ( V_46 -> V_2 ) ) {
F_75 ( V_20 ) ;
return;
}
F_52 ( & V_17 -> V_12 , V_47 ) ;
F_76 ( & V_17 -> V_71 , V_20 ) ;
F_53 ( & V_17 -> V_12 , V_47 ) ;
}
static void F_77 ( struct V_45 * V_46 , struct V_20 * V_20 )
{
F_66 ( V_46 , V_20 ) ;
F_72 ( V_46 , V_20 ) ;
}
static void F_78 ( struct V_45 * V_46 , struct V_20 * V_20 ,
T_1 V_58 )
{
F_65 ( V_46 , V_20 , V_58 ) ;
F_72 ( V_46 , V_20 ) ;
}
static void F_79 ( struct V_72 * V_73 )
{
struct V_17 * V_17 = V_73 -> V_46 -> V_17 ;
if ( F_80 ( & V_73 -> V_74 ) ) {
F_81 ( & V_73 -> V_37 , & V_17 -> V_75 ) ;
F_15 ( V_17 ) ;
}
}
static void F_82 ( struct V_72 * V_73 )
{
unsigned long V_47 ;
struct V_17 * V_17 = V_73 -> V_46 -> V_17 ;
F_52 ( & V_17 -> V_12 , V_47 ) ;
F_79 ( V_73 ) ;
F_53 ( & V_17 -> V_12 , V_47 ) ;
}
static void F_83 ( int V_76 , unsigned long V_77 , void * V_30 )
{
struct V_72 * V_73 = V_30 ;
V_73 -> V_78 = V_76 || V_77 ? - V_32 : 0 ;
F_82 ( V_73 ) ;
}
static void F_84 ( struct V_20 * V_20 , int V_78 )
{
struct V_66 * V_67 = F_70 ( V_20 , sizeof( struct V_66 ) ) ;
struct V_72 * V_73 = V_67 -> V_79 ;
V_73 -> V_78 = V_78 ;
F_82 ( V_73 ) ;
}
static void F_85 ( struct V_45 * V_46 , struct V_21 * V_27 )
{
struct V_17 * V_17 = V_46 -> V_17 ;
unsigned long V_47 ;
F_52 ( & V_46 -> V_12 , V_47 ) ;
F_26 ( V_17 , V_27 , & V_46 -> V_51 ) ;
F_53 ( & V_46 -> V_12 , V_47 ) ;
F_15 ( V_17 ) ;
}
static void F_86 ( void * V_30 ,
struct V_21 * V_27 )
{
struct V_80 * V_81 = V_30 ;
struct V_20 * V_20 ;
while ( ( V_20 = F_49 ( & V_27 -> V_29 ) ) ) {
if ( V_20 -> V_63 & ( V_68 | V_64 | V_65 ) )
F_76 ( & V_81 -> V_82 , V_20 ) ;
else {
F_69 ( V_81 -> V_46 -> V_17 , V_20 ) ;
F_76 ( & V_81 -> V_83 , V_20 ) ;
}
}
}
static void F_87 ( struct V_45 * V_46 ,
struct V_21 * V_27 ,
T_1 V_58 )
{
struct V_20 * V_20 ;
struct V_80 V_81 ;
V_81 . V_46 = V_46 ;
F_47 ( & V_81 . V_82 ) ;
F_47 ( & V_81 . V_83 ) ;
F_23 ( V_46 -> V_17 , F_86 ,
& V_81 , V_27 ) ;
while ( ( V_20 = F_49 ( & V_81 . V_82 ) ) )
F_88 ( V_46 , V_20 ) ;
while ( ( V_20 = F_49 ( & V_81 . V_83 ) ) )
F_78 ( V_81 . V_46 , V_20 , V_58 ) ;
}
static void F_89 ( struct V_72 * V_73 )
{
if ( V_73 -> V_20 ) {
V_73 -> V_20 -> V_84 = V_73 -> V_85 ;
F_90 ( & V_73 -> V_20 -> V_86 ) ;
}
F_30 ( V_73 -> V_46 -> V_17 , V_73 -> V_27 ) ;
F_41 ( & V_73 -> V_37 ) ;
F_91 ( V_73 , V_73 -> V_46 -> V_17 -> V_87 ) ;
}
static void F_92 ( struct V_72 * V_73 )
{
struct V_45 * V_46 = V_73 -> V_46 ;
struct V_17 * V_17 = V_46 -> V_17 ;
struct V_20 * V_20 ;
int V_23 ;
V_20 = V_73 -> V_20 ;
if ( V_20 ) {
V_20 -> V_84 = V_73 -> V_85 ;
F_90 ( & V_20 -> V_86 ) ;
}
if ( V_73 -> V_78 ) {
F_30 ( V_17 , V_73 -> V_27 ) ;
goto V_88;
}
V_23 = F_93 ( V_46 -> V_2 , V_73 -> V_89 , V_73 -> V_90 ) ;
if ( V_23 ) {
F_94 ( V_17 , L_1 , V_23 ) ;
F_30 ( V_17 , V_73 -> V_27 ) ;
goto V_88;
}
if ( V_20 ) {
F_87 ( V_46 , V_73 -> V_27 , V_73 -> V_90 ) ;
F_50 ( V_20 , 0 ) ;
} else {
F_69 ( V_46 -> V_17 , V_73 -> V_27 -> V_91 ) ;
F_78 ( V_46 , V_73 -> V_27 -> V_91 , V_73 -> V_90 ) ;
F_87 ( V_46 , V_73 -> V_27 , V_73 -> V_90 ) ;
}
V_88:
F_41 ( & V_73 -> V_37 ) ;
F_91 ( V_73 , V_17 -> V_87 ) ;
}
static void F_95 ( struct V_72 * V_73 )
{
struct V_45 * V_46 = V_73 -> V_46 ;
F_75 ( V_73 -> V_20 ) ;
F_85 ( V_46 , V_73 -> V_27 ) ;
F_85 ( V_46 , V_73 -> V_92 ) ;
F_91 ( V_73 , V_46 -> V_17 -> V_87 ) ;
}
static void F_96 ( struct V_72 * V_73 )
{
struct V_45 * V_46 = V_73 -> V_46 ;
F_69 ( V_46 -> V_17 , V_73 -> V_20 ) ;
F_85 ( V_46 , V_73 -> V_27 ) ;
F_85 ( V_46 , V_73 -> V_92 ) ;
if ( V_73 -> V_93 )
if ( V_73 -> V_94 )
F_78 ( V_46 , V_73 -> V_20 , V_73 -> V_90 ) ;
else {
bool V_95 = false ;
if ( F_97 ( V_46 -> V_17 -> V_96 , V_73 -> V_90 , & V_95 ) || V_95 )
F_50 ( V_73 -> V_20 , 0 ) ;
else
F_78 ( V_46 , V_73 -> V_20 , V_73 -> V_90 ) ;
}
else
F_50 ( V_73 -> V_20 , 0 ) ;
F_91 ( V_73 , V_46 -> V_17 -> V_87 ) ;
}
static void F_98 ( struct V_72 * V_73 )
{
int V_23 ;
struct V_45 * V_46 = V_73 -> V_46 ;
V_23 = F_99 ( V_46 -> V_2 , V_73 -> V_89 ) ;
if ( V_23 )
F_100 ( L_2 ) ;
F_96 ( V_73 ) ;
}
static void F_101 ( struct V_17 * V_17 , struct V_48 * V_97 ,
T_3 * F_24 )
{
unsigned long V_47 ;
struct V_48 V_98 ;
struct V_72 * V_73 , * V_40 ;
F_35 ( & V_98 ) ;
F_52 ( & V_17 -> V_12 , V_47 ) ;
F_55 ( V_97 , & V_98 ) ;
F_53 ( & V_17 -> V_12 , V_47 ) ;
F_56 ( V_73 , V_40 , & V_98 , V_37 )
( * F_24 ) ( V_73 ) ;
}
static int F_102 ( struct V_17 * V_17 , struct V_20 * V_20 )
{
return V_20 -> V_55 . V_99 ==
( V_17 -> V_57 << V_100 ) ;
}
static int F_103 ( struct V_17 * V_17 , struct V_20 * V_20 )
{
return ( F_104 ( V_20 ) == V_101 ) &&
F_102 ( V_17 , V_20 ) ;
}
static void F_105 ( struct V_20 * V_20 , T_4 * * V_102 ,
T_4 * F_24 )
{
* V_102 = V_20 -> V_84 ;
V_20 -> V_84 = F_24 ;
}
static int F_106 ( struct V_17 * V_17 )
{
if ( V_17 -> V_103 )
return 0 ;
V_17 -> V_103 = F_107 ( V_17 -> V_87 , V_104 ) ;
return V_17 -> V_103 ? 0 : - V_105 ;
}
static struct V_72 * F_108 ( struct V_17 * V_17 )
{
struct V_72 * V_73 = V_17 -> V_103 ;
F_37 ( ! V_17 -> V_103 ) ;
memset ( V_73 , 0 , sizeof( struct V_72 ) ) ;
F_35 ( & V_73 -> V_37 ) ;
V_73 -> V_20 = NULL ;
V_17 -> V_103 = NULL ;
return V_73 ;
}
static void F_109 ( struct V_45 * V_46 , struct V_72 * V_73 ,
T_2 V_106 , T_2 V_107 )
{
int V_23 ;
struct V_108 V_109 ;
V_109 . V_61 = V_46 -> V_60 -> V_61 ;
V_109 . V_110 = V_106 ;
V_109 . V_111 = V_107 - V_106 ;
V_23 = F_110 ( V_46 -> V_17 -> V_112 , 1 , & V_109 , 0 , F_83 , V_73 ) ;
if ( V_23 < 0 ) {
F_100 ( L_3 ) ;
F_83 ( 1 , 1 , V_73 ) ;
}
}
static void F_111 ( struct V_45 * V_46 , struct V_20 * V_20 ,
T_1 V_90 ,
struct V_72 * V_73 )
{
struct V_17 * V_17 = V_46 -> V_17 ;
struct V_66 * V_67 = F_70 ( V_20 , sizeof( struct V_66 ) ) ;
V_67 -> V_79 = V_73 ;
V_73 -> V_20 = V_20 ;
F_105 ( V_20 , & V_73 -> V_85 , F_84 ) ;
F_69 ( V_17 , V_20 ) ;
F_78 ( V_46 , V_20 , V_90 ) ;
}
static void F_112 ( struct V_45 * V_46 , T_1 V_89 ,
struct V_113 * V_114 , T_1 V_115 ,
T_1 V_116 ,
struct V_21 * V_27 , struct V_20 * V_20 ,
T_2 V_117 )
{
int V_23 ;
struct V_17 * V_17 = V_46 -> V_17 ;
struct V_72 * V_73 = F_108 ( V_17 ) ;
V_73 -> V_46 = V_46 ;
V_73 -> V_89 = V_89 ;
V_73 -> V_90 = V_116 ;
V_73 -> V_27 = V_27 ;
F_113 ( & V_73 -> V_74 , 3 ) ;
if ( ! F_114 ( V_17 -> V_118 , & V_73 -> V_37 ) )
F_82 ( V_73 ) ;
if ( F_103 ( V_17 , V_20 ) )
F_111 ( V_46 , V_20 , V_116 , V_73 ) ;
else {
struct V_108 V_119 , V_109 ;
V_119 . V_61 = V_114 -> V_61 ;
V_119 . V_110 = V_115 * V_17 -> V_57 ;
V_119 . V_111 = V_117 ;
V_109 . V_61 = V_46 -> V_60 -> V_61 ;
V_109 . V_110 = V_116 * V_17 -> V_57 ;
V_109 . V_111 = V_117 ;
V_23 = F_115 ( V_17 -> V_112 , & V_119 , 1 , & V_109 ,
0 , F_83 , V_73 ) ;
if ( V_23 < 0 ) {
F_100 ( L_4 ) ;
F_83 ( 1 , 1 , V_73 ) ;
}
if ( V_117 < V_17 -> V_57 && V_17 -> V_120 . V_121 ) {
F_90 ( & V_73 -> V_74 ) ;
F_109 ( V_46 , V_73 ,
V_116 * V_17 -> V_57 + V_117 ,
( V_116 + 1 ) * V_17 -> V_57 ) ;
}
}
F_82 ( V_73 ) ;
}
static void F_116 ( struct V_45 * V_46 , T_1 V_89 ,
T_1 V_115 , T_1 V_116 ,
struct V_21 * V_27 , struct V_20 * V_20 )
{
F_112 ( V_46 , V_89 , V_46 -> V_60 ,
V_115 , V_116 , V_27 , V_20 ,
V_46 -> V_17 -> V_57 ) ;
}
static void F_117 ( struct V_45 * V_46 , T_1 V_89 ,
T_1 V_90 , struct V_21 * V_27 ,
struct V_20 * V_20 )
{
struct V_17 * V_17 = V_46 -> V_17 ;
struct V_72 * V_73 = F_108 ( V_17 ) ;
F_113 ( & V_73 -> V_74 , 1 ) ;
V_73 -> V_46 = V_46 ;
V_73 -> V_89 = V_89 ;
V_73 -> V_90 = V_90 ;
V_73 -> V_27 = V_27 ;
if ( ! V_17 -> V_120 . V_121 )
F_92 ( V_73 ) ;
else if ( F_103 ( V_17 , V_20 ) )
F_111 ( V_46 , V_20 , V_90 , V_73 ) ;
else
F_109 ( V_46 , V_73 ,
V_90 * V_17 -> V_57 ,
( V_90 + 1 ) * V_17 -> V_57 ) ;
}
static void F_118 ( struct V_45 * V_46 , T_1 V_89 ,
T_1 V_116 ,
struct V_21 * V_27 , struct V_20 * V_20 )
{
struct V_17 * V_17 = V_46 -> V_17 ;
T_2 V_122 = V_89 * V_17 -> V_57 ;
T_2 V_123 = ( V_89 + 1 ) * V_17 -> V_57 ;
if ( V_123 <= V_46 -> V_124 )
F_112 ( V_46 , V_89 , V_46 -> V_62 ,
V_89 , V_116 , V_27 , V_20 ,
V_17 -> V_57 ) ;
else if ( V_122 < V_46 -> V_124 )
F_112 ( V_46 , V_89 , V_46 -> V_62 ,
V_89 , V_116 , V_27 , V_20 ,
V_46 -> V_124 - V_122 ) ;
else
F_117 ( V_46 , V_89 , V_116 , V_27 , V_20 ) ;
}
static void F_119 ( struct V_17 * V_17 )
{
int V_23 ;
T_1 V_125 ;
if ( F_120 ( V_17 ) != V_126 )
return;
V_23 = F_121 ( V_17 -> V_96 , & V_125 ) ;
if ( V_23 )
return;
if ( V_125 )
F_122 ( V_17 , V_127 ) ;
}
static int F_123 ( struct V_17 * V_17 )
{
int V_23 ;
if ( F_120 ( V_17 ) >= V_128 )
return - V_129 ;
V_23 = F_124 ( V_17 -> V_96 ) ;
if ( V_23 )
F_94 ( V_17 , L_5 , V_23 ) ;
else
F_119 ( V_17 ) ;
return V_23 ;
}
static void F_125 ( struct V_17 * V_17 , T_1 V_130 )
{
unsigned long V_47 ;
if ( V_130 <= V_17 -> V_131 && ! V_17 -> V_132 ) {
F_126 ( L_6 ,
F_127 ( V_17 -> V_41 ) ) ;
F_52 ( & V_17 -> V_12 , V_47 ) ;
V_17 -> V_132 = true ;
F_53 ( & V_17 -> V_12 , V_47 ) ;
F_128 ( V_17 -> V_133 -> V_134 ) ;
}
}
static int F_129 ( struct V_45 * V_46 , T_1 * V_135 )
{
int V_23 ;
T_1 V_130 ;
struct V_17 * V_17 = V_46 -> V_17 ;
if ( F_130 ( F_120 ( V_17 ) != V_127 ) )
return - V_129 ;
V_23 = F_121 ( V_17 -> V_96 , & V_130 ) ;
if ( V_23 ) {
F_94 ( V_17 , L_7 , V_23 ) ;
return V_23 ;
}
F_125 ( V_17 , V_130 ) ;
if ( ! V_130 ) {
V_23 = F_123 ( V_17 ) ;
if ( V_23 )
return V_23 ;
V_23 = F_121 ( V_17 -> V_96 , & V_130 ) ;
if ( V_23 ) {
F_94 ( V_17 , L_7 , V_23 ) ;
return V_23 ;
}
if ( ! V_130 ) {
F_122 ( V_17 , V_126 ) ;
return - V_136 ;
}
}
V_23 = F_131 ( V_17 -> V_96 , V_135 ) ;
if ( V_23 ) {
F_94 ( V_17 , L_8 , V_23 ) ;
return V_23 ;
}
return 0 ;
}
static void F_132 ( struct V_20 * V_20 )
{
struct V_66 * V_67 = F_70 ( V_20 , sizeof( struct V_66 ) ) ;
struct V_45 * V_46 = V_67 -> V_46 ;
unsigned long V_47 ;
F_52 ( & V_46 -> V_12 , V_47 ) ;
F_76 ( & V_46 -> V_52 , V_20 ) ;
F_53 ( & V_46 -> V_12 , V_47 ) ;
}
static int F_133 ( struct V_17 * V_17 )
{
enum V_137 V_73 = F_120 ( V_17 ) ;
switch ( V_73 ) {
case V_127 :
F_100 ( L_9 ) ;
return - V_32 ;
case V_126 :
return V_17 -> V_120 . V_138 ? - V_136 : 0 ;
case V_128 :
case V_139 :
return - V_32 ;
default:
F_100 ( L_10 ) ;
return - V_32 ;
}
}
static void F_134 ( struct V_17 * V_17 , struct V_20 * V_20 )
{
int error = F_133 ( V_17 ) ;
if ( error )
F_50 ( V_20 , error ) ;
else
F_132 ( V_20 ) ;
}
static void F_135 ( struct V_17 * V_17 , struct V_21 * V_27 )
{
struct V_20 * V_20 ;
struct V_28 V_29 ;
int error ;
error = F_133 ( V_17 ) ;
if ( error ) {
F_28 ( V_17 , V_27 , error ) ;
return;
}
F_47 ( & V_29 ) ;
F_21 ( V_17 , V_27 , & V_29 ) ;
while ( ( V_20 = F_49 ( & V_29 ) ) )
F_132 ( V_20 ) ;
}
static void F_136 ( struct V_45 * V_46 , struct V_21 * V_27 )
{
int V_23 ;
struct V_20 * V_20 = V_27 -> V_91 ;
struct V_17 * V_17 = V_46 -> V_17 ;
struct V_21 * V_92 ;
struct V_4 V_140 ;
T_1 V_58 = F_63 ( V_46 , V_20 ) ;
struct V_141 V_142 ;
struct V_72 * V_73 ;
if ( V_46 -> V_143 ) {
F_32 ( V_17 , V_27 ) ;
return;
}
V_23 = F_137 ( V_46 -> V_2 , V_58 , 1 , & V_142 ) ;
switch ( V_23 ) {
case 0 :
F_1 ( V_46 -> V_2 , V_142 . V_58 , & V_140 ) ;
if ( F_17 ( V_46 -> V_17 , & V_140 , V_20 , & V_92 ) ) {
F_85 ( V_46 , V_27 ) ;
break;
}
if ( F_102 ( V_17 , V_20 ) ) {
V_73 = F_108 ( V_17 ) ;
V_73 -> V_46 = V_46 ;
V_73 -> V_93 = V_17 -> V_120 . V_144 ;
V_73 -> V_94 = ! V_142 . V_145 ;
V_73 -> V_89 = V_58 ;
V_73 -> V_90 = V_142 . V_58 ;
V_73 -> V_27 = V_27 ;
V_73 -> V_92 = V_92 ;
V_73 -> V_20 = V_20 ;
if ( ! F_114 ( V_17 -> V_70 , & V_73 -> V_37 ) )
V_17 -> F_98 ( V_73 ) ;
} else {
F_69 ( V_17 , V_20 ) ;
F_85 ( V_46 , V_27 ) ;
F_85 ( V_46 , V_92 ) ;
if ( ( ! V_142 . V_145 ) && V_17 -> V_120 . V_144 )
F_78 ( V_46 , V_20 , V_142 . V_58 ) ;
else
F_50 ( V_20 , 0 ) ;
}
break;
case - V_146 :
F_85 ( V_46 , V_27 ) ;
F_50 ( V_20 , 0 ) ;
break;
default:
F_100 ( L_11 ,
V_147 , V_23 ) ;
F_85 ( V_46 , V_27 ) ;
F_75 ( V_20 ) ;
break;
}
}
static void F_138 ( struct V_45 * V_46 , struct V_20 * V_20 )
{
struct V_21 * V_27 ;
struct V_4 V_5 ;
T_1 V_58 = F_63 ( V_46 , V_20 ) ;
F_3 ( V_46 -> V_2 , V_58 , & V_5 ) ;
if ( F_17 ( V_46 -> V_17 , & V_5 , V_20 , & V_27 ) )
return;
F_136 ( V_46 , V_27 ) ;
}
static void F_139 ( struct V_45 * V_46 , struct V_20 * V_20 , T_1 V_58 ,
struct V_4 * V_5 ,
struct V_141 * V_142 ,
struct V_21 * V_27 )
{
int V_23 ;
T_1 V_90 ;
struct V_17 * V_17 = V_46 -> V_17 ;
V_23 = F_129 ( V_46 , & V_90 ) ;
switch ( V_23 ) {
case 0 :
F_116 ( V_46 , V_58 , V_142 -> V_58 ,
V_90 , V_27 , V_20 ) ;
break;
case - V_136 :
F_135 ( V_17 , V_27 ) ;
break;
default:
F_100 ( L_12 ,
V_147 , V_23 ) ;
F_30 ( V_17 , V_27 ) ;
break;
}
}
static void F_140 ( void * V_30 ,
struct V_21 * V_27 )
{
struct V_80 * V_81 = V_30 ;
struct V_20 * V_20 ;
while ( ( V_20 = F_49 ( & V_27 -> V_29 ) ) ) {
if ( ( F_104 ( V_20 ) == V_101 ) ||
( V_20 -> V_63 & ( V_68 | V_64 | V_65 ) ) )
F_76 ( & V_81 -> V_82 , V_20 ) ;
else {
struct V_66 * V_67 = F_70 ( V_20 , sizeof( struct V_66 ) ) ; ;
V_67 -> V_148 = F_71 ( V_81 -> V_46 -> V_17 -> V_118 ) ;
F_69 ( V_81 -> V_46 -> V_17 , V_20 ) ;
F_76 ( & V_81 -> V_83 , V_20 ) ;
}
}
}
static void F_141 ( struct V_45 * V_46 ,
struct V_21 * V_27 ,
T_1 V_58 )
{
struct V_20 * V_20 ;
struct V_80 V_81 ;
V_81 . V_46 = V_46 ;
F_47 ( & V_81 . V_82 ) ;
F_47 ( & V_81 . V_83 ) ;
F_23 ( V_46 -> V_17 , F_140 ,
& V_81 , V_27 ) ;
while ( ( V_20 = F_49 ( & V_81 . V_82 ) ) )
F_88 ( V_46 , V_20 ) ;
while ( ( V_20 = F_49 ( & V_81 . V_83 ) ) )
F_78 ( V_46 , V_20 , V_58 ) ;
}
static void F_142 ( struct V_45 * V_46 , struct V_20 * V_20 ,
T_1 V_58 ,
struct V_141 * V_142 ,
struct V_21 * V_149 )
{
struct V_21 * V_150 ;
struct V_17 * V_17 = V_46 -> V_17 ;
struct V_4 V_5 ;
F_1 ( V_46 -> V_2 , V_142 -> V_58 , & V_5 ) ;
if ( F_17 ( V_17 , & V_5 , V_20 , & V_150 ) ) {
F_85 ( V_46 , V_149 ) ;
return;
}
if ( F_104 ( V_20 ) == V_101 && V_20 -> V_55 . V_99 ) {
F_139 ( V_46 , V_20 , V_58 , & V_5 , V_142 , V_150 ) ;
F_85 ( V_46 , V_149 ) ;
} else {
struct V_66 * V_67 = F_70 ( V_20 , sizeof( struct V_66 ) ) ;
V_67 -> V_148 = F_71 ( V_17 -> V_118 ) ;
F_69 ( V_17 , V_20 ) ;
F_78 ( V_46 , V_20 , V_142 -> V_58 ) ;
F_141 ( V_46 , V_150 , V_142 -> V_58 ) ;
F_141 ( V_46 , V_149 , V_142 -> V_58 ) ;
}
}
static void F_143 ( struct V_45 * V_46 , struct V_20 * V_20 , T_1 V_58 ,
struct V_21 * V_27 )
{
int V_23 ;
T_1 V_90 ;
struct V_17 * V_17 = V_46 -> V_17 ;
if ( ! V_20 -> V_55 . V_99 ) {
F_69 ( V_17 , V_20 ) ;
F_85 ( V_46 , V_27 ) ;
F_78 ( V_46 , V_20 , 0 ) ;
return;
}
if ( F_104 ( V_20 ) == V_151 ) {
F_144 ( V_20 ) ;
F_85 ( V_46 , V_27 ) ;
F_50 ( V_20 , 0 ) ;
return;
}
V_23 = F_129 ( V_46 , & V_90 ) ;
switch ( V_23 ) {
case 0 :
if ( V_46 -> V_62 )
F_118 ( V_46 , V_58 , V_90 , V_27 , V_20 ) ;
else
F_117 ( V_46 , V_58 , V_90 , V_27 , V_20 ) ;
break;
case - V_136 :
F_135 ( V_17 , V_27 ) ;
break;
default:
F_100 ( L_12 ,
V_147 , V_23 ) ;
F_30 ( V_17 , V_27 ) ;
break;
}
}
static void F_145 ( struct V_45 * V_46 , struct V_21 * V_27 )
{
int V_23 ;
struct V_17 * V_17 = V_46 -> V_17 ;
struct V_20 * V_20 = V_27 -> V_91 ;
T_1 V_58 = F_63 ( V_46 , V_20 ) ;
struct V_141 V_142 ;
if ( V_46 -> V_143 ) {
F_32 ( V_17 , V_27 ) ;
return;
}
V_23 = F_137 ( V_46 -> V_2 , V_58 , 1 , & V_142 ) ;
switch ( V_23 ) {
case 0 :
if ( V_142 . V_145 )
F_142 ( V_46 , V_20 , V_58 , & V_142 , V_27 ) ;
else {
F_69 ( V_17 , V_20 ) ;
F_78 ( V_46 , V_20 , V_142 . V_58 ) ;
F_87 ( V_46 , V_27 , V_142 . V_58 ) ;
}
break;
case - V_146 :
if ( F_104 ( V_20 ) == V_151 && V_46 -> V_62 ) {
F_69 ( V_17 , V_20 ) ;
F_85 ( V_46 , V_27 ) ;
if ( F_146 ( V_20 ) <= V_46 -> V_124 )
F_77 ( V_46 , V_20 ) ;
else if ( V_20 -> V_55 . V_56 < V_46 -> V_124 ) {
F_144 ( V_20 ) ;
V_20 -> V_55 . V_99 = ( V_46 -> V_124 - V_20 -> V_55 . V_56 ) << V_100 ;
F_77 ( V_46 , V_20 ) ;
} else {
F_144 ( V_20 ) ;
F_50 ( V_20 , 0 ) ;
}
} else
F_143 ( V_46 , V_20 , V_58 , V_27 ) ;
break;
default:
F_100 ( L_11 ,
V_147 , V_23 ) ;
F_85 ( V_46 , V_27 ) ;
F_75 ( V_20 ) ;
break;
}
}
static void F_147 ( struct V_45 * V_46 , struct V_20 * V_20 )
{
struct V_17 * V_17 = V_46 -> V_17 ;
T_1 V_58 = F_63 ( V_46 , V_20 ) ;
struct V_21 * V_27 ;
struct V_4 V_5 ;
F_3 ( V_46 -> V_2 , V_58 , & V_5 ) ;
if ( F_17 ( V_17 , & V_5 , V_20 , & V_27 ) )
return;
F_145 ( V_46 , V_27 ) ;
}
static void F_148 ( struct V_45 * V_46 , struct V_20 * V_20 ,
struct V_21 * V_27 )
{
int V_23 ;
int V_152 = F_104 ( V_20 ) ;
T_1 V_58 = F_63 ( V_46 , V_20 ) ;
struct V_141 V_142 ;
V_23 = F_137 ( V_46 -> V_2 , V_58 , 1 , & V_142 ) ;
switch ( V_23 ) {
case 0 :
if ( V_142 . V_145 && ( V_152 == V_101 ) && V_20 -> V_55 . V_99 ) {
F_134 ( V_46 -> V_17 , V_20 ) ;
if ( V_27 )
F_85 ( V_46 , V_27 ) ;
} else {
F_69 ( V_46 -> V_17 , V_20 ) ;
F_78 ( V_46 , V_20 , V_142 . V_58 ) ;
if ( V_27 )
F_87 ( V_46 , V_27 , V_142 . V_58 ) ;
}
break;
case - V_146 :
if ( V_27 )
F_85 ( V_46 , V_27 ) ;
if ( V_152 != V_151 ) {
F_134 ( V_46 -> V_17 , V_20 ) ;
break;
}
if ( V_46 -> V_62 ) {
F_69 ( V_46 -> V_17 , V_20 ) ;
F_77 ( V_46 , V_20 ) ;
break;
}
F_144 ( V_20 ) ;
F_50 ( V_20 , 0 ) ;
break;
default:
F_100 ( L_11 ,
V_147 , V_23 ) ;
if ( V_27 )
F_85 ( V_46 , V_27 ) ;
F_75 ( V_20 ) ;
break;
}
}
static void F_149 ( struct V_45 * V_46 , struct V_20 * V_20 )
{
F_148 ( V_46 , V_20 , NULL ) ;
}
static void F_150 ( struct V_45 * V_46 , struct V_21 * V_27 )
{
F_148 ( V_46 , V_27 -> V_91 , V_27 ) ;
}
static void F_151 ( struct V_45 * V_46 , struct V_20 * V_20 )
{
F_50 ( V_20 , 0 ) ;
}
static void F_152 ( struct V_45 * V_46 , struct V_20 * V_20 )
{
F_75 ( V_20 ) ;
}
static void F_153 ( struct V_45 * V_46 , struct V_21 * V_27 )
{
F_31 ( V_46 -> V_17 , V_27 ) ;
}
static void F_154 ( struct V_45 * V_46 , struct V_21 * V_27 )
{
F_30 ( V_46 -> V_17 , V_27 ) ;
}
static int F_155 ( struct V_17 * V_17 )
{
return ! F_156 ( V_15 , V_17 -> V_153 ,
V_17 -> V_153 + V_154 ) ;
}
static void F_157 ( struct V_45 * V_46 , struct V_20 * V_20 )
{
struct V_155 * * V_156 , * V_157 ;
struct V_66 * V_158 ;
T_2 V_56 = V_20 -> V_55 . V_56 ;
V_156 = & V_46 -> V_159 . V_155 ;
V_157 = NULL ;
while ( * V_156 ) {
V_157 = * V_156 ;
V_158 = F_158 ( V_157 ) ;
if ( V_56 < F_159 ( V_158 ) -> V_55 . V_56 )
V_156 = & ( * V_156 ) -> V_160 ;
else
V_156 = & ( * V_156 ) -> V_161 ;
}
V_158 = F_70 ( V_20 , sizeof( struct V_66 ) ) ;
F_160 ( & V_158 -> V_155 , V_157 , V_156 ) ;
F_161 ( & V_158 -> V_155 , & V_46 -> V_159 ) ;
}
static void F_162 ( struct V_45 * V_46 )
{
struct V_155 * V_162 ;
struct V_66 * V_158 ;
struct V_20 * V_20 ;
for ( V_162 = F_163 ( & V_46 -> V_159 ) ; V_162 ; V_162 = F_164 ( V_162 ) ) {
V_158 = F_158 ( V_162 ) ;
V_20 = F_159 ( V_158 ) ;
F_76 ( & V_46 -> V_51 , V_20 ) ;
F_165 ( & V_158 -> V_155 , & V_46 -> V_159 ) ;
}
F_130 ( ! F_166 ( & V_46 -> V_159 ) ) ;
}
static void F_167 ( struct V_45 * V_46 )
{
struct V_20 * V_20 ;
struct V_28 V_29 ;
F_47 ( & V_29 ) ;
F_46 ( & V_29 , & V_46 -> V_51 ) ;
F_47 ( & V_46 -> V_51 ) ;
while ( ( V_20 = F_49 ( & V_29 ) ) )
F_157 ( V_46 , V_20 ) ;
F_162 ( V_46 ) ;
}
static void F_168 ( struct V_45 * V_46 )
{
struct V_17 * V_17 = V_46 -> V_17 ;
unsigned long V_47 ;
struct V_20 * V_20 ;
struct V_28 V_29 ;
struct V_163 V_164 ;
unsigned V_111 = 0 ;
if ( V_46 -> V_143 ) {
F_51 ( V_46 , & V_46 -> V_51 , V_33 ) ;
return;
}
F_47 ( & V_29 ) ;
F_52 ( & V_46 -> V_12 , V_47 ) ;
if ( F_169 ( & V_46 -> V_51 ) ) {
F_53 ( & V_46 -> V_12 , V_47 ) ;
return;
}
F_167 ( V_46 ) ;
F_46 ( & V_29 , & V_46 -> V_51 ) ;
F_47 ( & V_46 -> V_51 ) ;
F_53 ( & V_46 -> V_12 , V_47 ) ;
F_170 ( & V_164 ) ;
while ( ( V_20 = F_49 ( & V_29 ) ) ) {
if ( F_106 ( V_17 ) ) {
F_52 ( & V_46 -> V_12 , V_47 ) ;
F_76 ( & V_46 -> V_51 , V_20 ) ;
F_46 ( & V_46 -> V_51 , & V_29 ) ;
F_53 ( & V_46 -> V_12 , V_47 ) ;
break;
}
if ( V_20 -> V_63 & V_68 )
V_17 -> V_165 ( V_46 , V_20 ) ;
else
V_17 -> F_147 ( V_46 , V_20 ) ;
if ( ( V_111 ++ & 127 ) == 0 ) {
F_7 ( & V_17 -> V_10 ) ;
F_171 ( V_17 -> V_96 ) ;
}
}
F_172 ( & V_164 ) ;
}
static int F_173 ( const void * V_166 , const void * V_167 )
{
struct V_21 * V_168 = * ( (struct V_21 * * ) V_166 ) ;
struct V_21 * V_169 = * ( (struct V_21 * * ) V_167 ) ;
F_37 ( ! V_168 -> V_91 ) ;
F_37 ( ! V_169 -> V_91 ) ;
if ( V_168 -> V_91 -> V_55 . V_56 < V_169 -> V_91 -> V_55 . V_56 )
return - 1 ;
if ( V_168 -> V_91 -> V_55 . V_56 > V_169 -> V_91 -> V_55 . V_56 )
return 1 ;
return 0 ;
}
static unsigned F_174 ( struct V_17 * V_17 , struct V_48 * V_49 )
{
unsigned V_111 = 0 ;
struct V_21 * V_27 , * V_40 ;
F_56 (cell, tmp, cells, user_list) {
if ( V_111 >= V_170 )
break;
V_17 -> V_171 [ V_111 ++ ] = V_27 ;
F_41 ( & V_27 -> V_172 ) ;
}
F_175 ( V_17 -> V_171 , V_111 , sizeof( V_27 ) , F_173 , NULL ) ;
return V_111 ;
}
static void F_176 ( struct V_45 * V_46 )
{
struct V_17 * V_17 = V_46 -> V_17 ;
unsigned long V_47 ;
struct V_48 V_49 ;
struct V_21 * V_27 ;
unsigned V_173 , V_174 , V_111 ;
F_35 ( & V_49 ) ;
F_52 ( & V_46 -> V_12 , V_47 ) ;
F_55 ( & V_46 -> V_50 , & V_49 ) ;
F_53 ( & V_46 -> V_12 , V_47 ) ;
if ( F_177 ( & V_49 ) )
return;
do {
V_111 = F_174 ( V_46 -> V_17 , & V_49 ) ;
for ( V_173 = 0 ; V_173 < V_111 ; V_173 ++ ) {
V_27 = V_17 -> V_171 [ V_173 ] ;
F_37 ( ! V_27 -> V_91 ) ;
if ( F_106 ( V_17 ) ) {
for ( V_174 = V_173 ; V_174 < V_111 ; V_174 ++ )
F_39 ( & V_17 -> V_171 [ V_174 ] -> V_172 , & V_49 ) ;
F_52 ( & V_46 -> V_12 , V_47 ) ;
F_178 ( & V_49 , & V_46 -> V_50 ) ;
F_53 ( & V_46 -> V_12 , V_47 ) ;
return;
}
if ( V_27 -> V_91 -> V_63 & V_68 )
V_17 -> F_136 ( V_46 , V_27 ) ;
else
V_17 -> F_145 ( V_46 , V_27 ) ;
}
} while ( ! F_177 ( & V_49 ) );
}
static struct V_45 * F_179 ( struct V_17 * V_17 )
{
struct V_45 * V_46 = NULL ;
F_59 () ;
if ( ! F_177 ( & V_17 -> V_175 ) ) {
V_46 = F_180 ( V_17 -> V_175 . V_176 , struct V_45 , V_37 ) ;
F_181 ( V_46 ) ;
}
F_61 () ;
return V_46 ;
}
static struct V_45 * F_182 ( struct V_17 * V_17 , struct V_45 * V_46 )
{
struct V_45 * V_177 = V_46 ;
F_59 () ;
F_183 (tc, &pool->active_thins, list) {
F_181 ( V_46 ) ;
F_184 ( V_177 ) ;
F_61 () ;
return V_46 ;
}
F_184 ( V_177 ) ;
F_61 () ;
return NULL ;
}
static void F_185 ( struct V_17 * V_17 )
{
unsigned long V_47 ;
struct V_20 * V_20 ;
struct V_28 V_29 ;
struct V_45 * V_46 ;
V_46 = F_179 ( V_17 ) ;
while ( V_46 ) {
F_176 ( V_46 ) ;
F_168 ( V_46 ) ;
V_46 = F_182 ( V_17 , V_46 ) ;
}
F_47 ( & V_29 ) ;
F_52 ( & V_17 -> V_12 , V_47 ) ;
F_46 ( & V_29 , & V_17 -> V_71 ) ;
F_47 ( & V_17 -> V_71 ) ;
F_53 ( & V_17 -> V_12 , V_47 ) ;
if ( F_169 ( & V_29 ) &&
! ( F_186 ( V_17 -> V_96 ) && F_155 ( V_17 ) ) )
return;
if ( F_123 ( V_17 ) ) {
while ( ( V_20 = F_49 ( & V_29 ) ) )
F_75 ( V_20 ) ;
return;
}
V_17 -> V_153 = V_15 ;
while ( ( V_20 = F_49 ( & V_29 ) ) )
F_73 ( V_20 ) ;
}
static void F_187 ( struct V_178 * V_179 )
{
struct V_17 * V_17 = F_188 ( V_179 , struct V_17 , V_19 ) ;
F_6 ( & V_17 -> V_10 ) ;
F_171 ( V_17 -> V_96 ) ;
F_7 ( & V_17 -> V_10 ) ;
F_101 ( V_17 , & V_17 -> V_75 , & V_17 -> F_92 ) ;
F_7 ( & V_17 -> V_10 ) ;
F_101 ( V_17 , & V_17 -> V_180 , & V_17 -> F_98 ) ;
F_7 ( & V_17 -> V_10 ) ;
F_185 ( V_17 ) ;
F_9 ( & V_17 -> V_10 ) ;
}
static void F_189 ( struct V_178 * V_179 )
{
struct V_17 * V_17 = F_188 ( F_190 ( V_179 ) , struct V_17 , V_181 ) ;
F_15 ( V_17 ) ;
F_191 ( V_17 -> V_18 , & V_17 -> V_181 , V_154 ) ;
}
static void F_192 ( struct V_178 * V_179 )
{
struct V_17 * V_17 = F_188 ( F_190 ( V_179 ) , struct V_17 ,
V_182 ) ;
if ( F_120 ( V_17 ) == V_126 && ! V_17 -> V_120 . V_138 )
F_122 ( V_17 , V_128 ) ;
}
static struct V_183 * F_193 ( struct V_178 * V_179 )
{
return F_188 ( V_179 , struct V_183 , V_19 ) ;
}
static void F_194 ( struct V_183 * V_184 )
{
F_195 ( & V_184 -> F_195 ) ;
}
static void F_196 ( struct V_183 * V_184 , struct V_17 * V_17 ,
void (* F_24)( struct V_178 * ) )
{
F_197 ( & V_184 -> V_19 , F_24 ) ;
F_198 ( & V_184 -> F_195 ) ;
F_16 ( V_17 -> V_18 , & V_184 -> V_19 ) ;
F_199 ( & V_184 -> F_195 ) ;
}
static struct V_185 * F_200 ( struct V_178 * V_179 )
{
return F_188 ( F_193 ( V_179 ) , struct V_185 , V_184 ) ;
}
static void F_201 ( struct V_178 * V_179 )
{
struct V_185 * V_186 = F_200 ( V_179 ) ;
V_186 -> V_46 -> V_143 = true ;
F_57 ( V_186 -> V_46 ) ;
F_194 ( & V_186 -> V_184 ) ;
}
static void F_202 ( struct V_178 * V_179 )
{
struct V_185 * V_186 = F_200 ( V_179 ) ;
V_186 -> V_46 -> V_143 = false ;
F_194 ( & V_186 -> V_184 ) ;
}
static void V_185 ( struct V_45 * V_46 , void (* F_24)( struct V_178 * ) )
{
struct V_185 V_186 ;
V_186 . V_46 = V_46 ;
F_196 ( & V_186 . V_184 , V_46 -> V_17 , F_24 ) ;
}
static enum V_137 F_120 ( struct V_17 * V_17 )
{
return V_17 -> V_120 . V_187 ;
}
static void F_203 ( struct V_17 * V_17 , const char * V_188 )
{
F_128 ( V_17 -> V_133 -> V_134 ) ;
F_204 ( L_13 ,
F_127 ( V_17 -> V_41 ) , V_188 ) ;
}
static void F_122 ( struct V_17 * V_17 , enum V_137 V_188 )
{
struct V_189 * V_190 = V_17 -> V_133 -> V_191 ;
bool V_192 = F_205 ( V_17 -> V_96 ) ;
enum V_137 V_193 = F_120 ( V_17 ) ;
unsigned long V_182 = F_206 ( V_194 ) * V_195 ;
if ( V_188 == V_127 && V_192 ) {
F_207 ( L_14 ,
F_127 ( V_17 -> V_41 ) ) ;
if ( V_193 != V_188 )
V_188 = V_193 ;
else
V_188 = V_128 ;
}
if ( V_193 == V_139 )
V_188 = V_193 ;
switch ( V_188 ) {
case V_139 :
if ( V_193 != V_188 )
F_203 ( V_17 , L_15 ) ;
F_208 ( V_17 -> V_96 ) ;
V_17 -> F_147 = F_152 ;
V_17 -> V_165 = F_152 ;
V_17 -> F_145 = F_154 ;
V_17 -> F_136 = F_154 ;
V_17 -> F_92 = F_89 ;
V_17 -> F_98 = F_95 ;
F_58 ( V_17 ) ;
break;
case V_128 :
if ( V_193 != V_188 )
F_203 ( V_17 , L_16 ) ;
F_208 ( V_17 -> V_96 ) ;
V_17 -> F_147 = F_149 ;
V_17 -> V_165 = F_151 ;
V_17 -> F_145 = F_150 ;
V_17 -> F_136 = F_153 ;
V_17 -> F_92 = F_89 ;
V_17 -> F_98 = F_96 ;
F_58 ( V_17 ) ;
break;
case V_126 :
if ( V_193 != V_188 )
F_203 ( V_17 , L_17 ) ;
V_17 -> F_147 = F_149 ;
V_17 -> V_165 = F_138 ;
V_17 -> F_145 = F_150 ;
V_17 -> F_136 = F_136 ;
V_17 -> F_92 = F_92 ;
V_17 -> F_98 = F_98 ;
if ( ! V_17 -> V_120 . V_138 && V_182 )
F_191 ( V_17 -> V_18 , & V_17 -> V_182 , V_182 ) ;
break;
case V_127 :
if ( V_193 != V_188 )
F_203 ( V_17 , L_18 ) ;
F_209 ( V_17 -> V_96 ) ;
V_17 -> F_147 = F_147 ;
V_17 -> V_165 = F_138 ;
V_17 -> F_145 = F_145 ;
V_17 -> F_136 = F_136 ;
V_17 -> F_92 = F_92 ;
V_17 -> F_98 = F_98 ;
break;
}
V_17 -> V_120 . V_187 = V_188 ;
V_190 -> V_196 . V_187 = V_188 ;
}
static void F_210 ( struct V_17 * V_17 )
{
const char * V_197 = F_127 ( V_17 -> V_41 ) ;
F_100 ( L_19 , V_197 ) ;
if ( F_211 ( V_17 -> V_96 ) ) {
F_207 ( L_20 , V_197 ) ;
F_122 ( V_17 , V_139 ) ;
}
if ( F_212 ( V_17 -> V_96 ) ) {
F_207 ( L_21 , V_197 ) ;
F_122 ( V_17 , V_139 ) ;
}
}
static void F_94 ( struct V_17 * V_17 , const char * V_198 , int V_23 )
{
F_100 ( L_22 ,
F_127 ( V_17 -> V_41 ) , V_198 , V_23 ) ;
F_210 ( V_17 ) ;
F_122 ( V_17 , V_128 ) ;
}
static void F_88 ( struct V_45 * V_46 , struct V_20 * V_20 )
{
unsigned long V_47 ;
struct V_17 * V_17 = V_46 -> V_17 ;
F_52 ( & V_46 -> V_12 , V_47 ) ;
F_76 ( & V_46 -> V_51 , V_20 ) ;
F_53 ( & V_46 -> V_12 , V_47 ) ;
F_15 ( V_17 ) ;
}
static void F_213 ( struct V_45 * V_46 , struct V_20 * V_20 )
{
struct V_17 * V_17 = V_46 -> V_17 ;
F_11 ( & V_17 -> V_10 ) ;
F_88 ( V_46 , V_20 ) ;
F_13 ( & V_17 -> V_10 ) ;
}
static void F_214 ( struct V_45 * V_46 , struct V_21 * V_27 )
{
unsigned long V_47 ;
struct V_17 * V_17 = V_46 -> V_17 ;
F_11 ( & V_17 -> V_10 ) ;
F_52 ( & V_46 -> V_12 , V_47 ) ;
F_81 ( & V_27 -> V_172 , & V_46 -> V_50 ) ;
F_53 ( & V_46 -> V_12 , V_47 ) ;
F_13 ( & V_17 -> V_10 ) ;
F_15 ( V_17 ) ;
}
static void F_215 ( struct V_45 * V_46 , struct V_20 * V_20 )
{
struct V_66 * V_67 = F_70 ( V_20 , sizeof( struct V_66 ) ) ;
V_67 -> V_46 = V_46 ;
V_67 -> V_148 = NULL ;
V_67 -> V_69 = NULL ;
V_67 -> V_79 = NULL ;
}
static int F_216 ( struct V_199 * V_133 , struct V_20 * V_20 )
{
int V_23 ;
struct V_45 * V_46 = V_133 -> V_191 ;
T_1 V_58 = F_63 ( V_46 , V_20 ) ;
struct V_1 * V_2 = V_46 -> V_2 ;
struct V_141 V_135 ;
struct V_21 * V_149 , * V_150 ;
struct V_4 V_5 ;
F_215 ( V_46 , V_20 ) ;
if ( V_46 -> V_143 ) {
F_50 ( V_20 , V_33 ) ;
return V_200 ;
}
if ( F_120 ( V_46 -> V_17 ) == V_139 ) {
F_75 ( V_20 ) ;
return V_200 ;
}
if ( V_20 -> V_63 & ( V_68 | V_64 | V_65 ) ) {
F_213 ( V_46 , V_20 ) ;
return V_200 ;
}
F_3 ( V_46 -> V_2 , V_58 , & V_5 ) ;
if ( F_17 ( V_46 -> V_17 , & V_5 , V_20 , & V_149 ) )
return V_200 ;
V_23 = F_137 ( V_2 , V_58 , 0 , & V_135 ) ;
switch ( V_23 ) {
case 0 :
if ( F_217 ( V_135 . V_145 ) ) {
F_214 ( V_46 , V_149 ) ;
return V_200 ;
}
F_1 ( V_46 -> V_2 , V_135 . V_58 , & V_5 ) ;
if ( F_17 ( V_46 -> V_17 , & V_5 , V_20 , & V_150 ) ) {
F_85 ( V_46 , V_149 ) ;
return V_200 ;
}
F_69 ( V_46 -> V_17 , V_20 ) ;
F_85 ( V_46 , V_150 ) ;
F_85 ( V_46 , V_149 ) ;
F_65 ( V_46 , V_20 , V_135 . V_58 ) ;
return V_201 ;
case - V_146 :
case - V_202 :
F_214 ( V_46 , V_149 ) ;
return V_200 ;
default:
F_75 ( V_20 ) ;
F_85 ( V_46 , V_149 ) ;
return V_200 ;
}
}
static int F_218 ( struct V_203 * V_204 , int V_205 )
{
struct V_189 * V_190 = F_188 ( V_204 , struct V_189 , V_206 ) ;
struct V_207 * V_208 ;
if ( F_120 ( V_190 -> V_17 ) == V_126 )
return 1 ;
V_208 = F_219 ( V_190 -> V_209 -> V_61 ) ;
return F_220 ( & V_208 -> V_210 , V_205 ) ;
}
static void F_221 ( struct V_17 * V_17 )
{
unsigned long V_47 ;
struct V_45 * V_46 ;
F_59 () ;
F_60 (tc, &pool->active_thins, list) {
F_52 ( & V_46 -> V_12 , V_47 ) ;
F_46 ( & V_46 -> V_51 , & V_46 -> V_52 ) ;
F_47 ( & V_46 -> V_52 ) ;
F_53 ( & V_46 -> V_12 , V_47 ) ;
}
F_61 () ;
}
static bool F_222 ( struct V_189 * V_190 )
{
struct V_207 * V_208 = F_219 ( V_190 -> V_209 -> V_61 ) ;
return V_208 && F_223 ( V_208 ) ;
}
static bool F_224 ( T_2 V_211 , T_5 V_212 )
{
return ! F_64 ( V_211 , V_212 ) ;
}
static void F_225 ( struct V_189 * V_190 )
{
struct V_17 * V_17 = V_190 -> V_17 ;
struct V_42 * V_213 = V_190 -> V_209 -> V_61 ;
struct V_214 * V_215 = & F_219 ( V_213 ) -> V_216 ;
T_2 V_211 = V_17 -> V_57 << V_100 ;
const char * V_217 = NULL ;
char V_218 [ V_219 ] ;
if ( ! V_190 -> V_196 . V_144 )
return;
if ( ! F_222 ( V_190 ) )
V_217 = L_23 ;
else if ( V_215 -> V_220 < V_17 -> V_57 )
V_217 = L_24 ;
else if ( V_215 -> V_221 > V_211 )
V_217 = L_25 ;
else if ( ! F_224 ( V_211 , V_215 -> V_221 ) )
V_217 = L_26 ;
if ( V_217 ) {
F_126 ( L_27 , F_226 ( V_213 , V_218 ) , V_217 ) ;
V_190 -> V_196 . V_144 = false ;
}
}
static int F_227 ( struct V_17 * V_17 , struct V_199 * V_133 )
{
struct V_189 * V_190 = V_133 -> V_191 ;
enum V_137 V_193 = F_120 ( V_17 ) ;
enum V_137 V_188 = V_190 -> V_196 . V_187 ;
V_190 -> V_196 . V_187 = V_193 ;
V_17 -> V_133 = V_133 ;
V_17 -> V_120 = V_190 -> V_196 ;
V_17 -> V_131 = V_190 -> V_131 ;
F_122 ( V_17 , V_188 ) ;
return 0 ;
}
static void F_228 ( struct V_17 * V_17 , struct V_199 * V_133 )
{
if ( V_17 -> V_133 == V_133 )
V_17 -> V_133 = NULL ;
}
static void F_229 ( struct V_222 * V_120 )
{
V_120 -> V_187 = V_127 ;
V_120 -> V_121 = true ;
V_120 -> V_223 = true ;
V_120 -> V_144 = true ;
V_120 -> V_138 = false ;
}
static void F_230 ( struct V_17 * V_17 )
{
F_40 ( V_17 ) ;
if ( F_231 ( V_17 -> V_96 ) < 0 )
F_126 ( L_28 , V_147 ) ;
F_232 ( V_17 -> V_25 ) ;
F_233 ( V_17 -> V_112 ) ;
if ( V_17 -> V_18 )
F_234 ( V_17 -> V_18 ) ;
if ( V_17 -> V_103 )
F_91 ( V_17 -> V_103 , V_17 -> V_87 ) ;
F_235 ( V_17 -> V_87 ) ;
F_236 ( V_17 -> V_118 ) ;
F_236 ( V_17 -> V_70 ) ;
F_237 ( V_17 ) ;
}
static struct V_17 * F_238 ( struct V_38 * V_41 ,
struct V_42 * V_224 ,
unsigned long V_211 ,
int V_225 , char * * error )
{
int V_23 ;
void * V_226 ;
struct V_17 * V_17 ;
struct V_227 * V_96 ;
bool V_228 = V_225 ? false : true ;
V_96 = F_239 ( V_224 , V_211 , V_228 ) ;
if ( F_240 ( V_96 ) ) {
* error = L_29 ;
return (struct V_17 * ) V_96 ;
}
V_17 = F_241 ( sizeof( * V_17 ) , V_229 ) ;
if ( ! V_17 ) {
* error = L_30 ;
V_226 = F_242 ( - V_105 ) ;
goto V_230;
}
V_17 -> V_96 = V_96 ;
V_17 -> V_57 = V_211 ;
if ( V_211 & ( V_211 - 1 ) )
V_17 -> V_53 = - 1 ;
else
V_17 -> V_53 = F_243 ( V_211 ) ;
V_17 -> V_131 = 0 ;
F_229 ( & V_17 -> V_120 ) ;
V_17 -> V_25 = F_244 () ;
if ( ! V_17 -> V_25 ) {
* error = L_31 ;
V_226 = F_242 ( - V_105 ) ;
goto V_231;
}
V_17 -> V_112 = F_245 ( & V_232 ) ;
if ( F_240 ( V_17 -> V_112 ) ) {
V_23 = F_246 ( V_17 -> V_112 ) ;
* error = L_32 ;
V_226 = F_242 ( V_23 ) ;
goto V_233;
}
V_17 -> V_18 = F_247 ( L_33 V_234 , V_235 ) ;
if ( ! V_17 -> V_18 ) {
* error = L_34 ;
V_226 = F_242 ( - V_105 ) ;
goto V_236;
}
F_4 ( & V_17 -> V_10 ) ;
F_248 ( & V_17 -> V_19 , F_187 ) ;
F_249 ( & V_17 -> V_181 , F_189 ) ;
F_249 ( & V_17 -> V_182 , F_192 ) ;
F_250 ( & V_17 -> V_12 ) ;
F_47 ( & V_17 -> V_71 ) ;
F_35 ( & V_17 -> V_75 ) ;
F_35 ( & V_17 -> V_180 ) ;
F_35 ( & V_17 -> V_175 ) ;
V_17 -> V_132 = false ;
V_17 -> V_237 = true ;
V_17 -> V_118 = F_251 () ;
if ( ! V_17 -> V_118 ) {
* error = L_35 ;
V_226 = F_242 ( - V_105 ) ;
goto V_238;
}
V_17 -> V_70 = F_251 () ;
if ( ! V_17 -> V_70 ) {
* error = L_36 ;
V_226 = F_242 ( - V_105 ) ;
goto V_239;
}
V_17 -> V_103 = NULL ;
V_17 -> V_87 = F_252 ( V_240 ,
V_241 ) ;
if ( ! V_17 -> V_87 ) {
* error = L_37 ;
V_226 = F_242 ( - V_105 ) ;
goto V_242;
}
V_17 -> V_243 = 1 ;
V_17 -> V_153 = V_15 ;
V_17 -> V_41 = V_41 ;
V_17 -> V_43 = V_224 ;
F_36 ( V_17 ) ;
return V_17 ;
V_242:
F_236 ( V_17 -> V_70 ) ;
V_239:
F_236 ( V_17 -> V_118 ) ;
V_238:
F_234 ( V_17 -> V_18 ) ;
V_236:
F_233 ( V_17 -> V_112 ) ;
V_233:
F_232 ( V_17 -> V_25 ) ;
V_231:
F_237 ( V_17 ) ;
V_230:
if ( F_231 ( V_96 ) )
F_126 ( L_28 , V_147 ) ;
return V_226 ;
}
static void F_253 ( struct V_17 * V_17 )
{
F_37 ( ! F_38 ( & V_34 . V_35 ) ) ;
V_17 -> V_243 ++ ;
}
static void F_254 ( struct V_17 * V_17 )
{
F_37 ( ! F_38 ( & V_34 . V_35 ) ) ;
F_37 ( ! V_17 -> V_243 ) ;
if ( ! -- V_17 -> V_243 )
F_230 ( V_17 ) ;
}
static struct V_17 * F_255 ( struct V_38 * V_41 ,
struct V_42 * V_224 ,
unsigned long V_211 , int V_225 ,
char * * error , int * V_244 )
{
struct V_17 * V_17 = F_44 ( V_224 ) ;
if ( V_17 ) {
if ( V_17 -> V_41 != V_41 ) {
* error = L_38 ;
return F_242 ( - V_245 ) ;
}
F_253 ( V_17 ) ;
} else {
V_17 = F_42 ( V_41 ) ;
if ( V_17 ) {
if ( V_17 -> V_43 != V_224 ) {
* error = L_39 ;
return F_242 ( - V_129 ) ;
}
F_253 ( V_17 ) ;
} else {
V_17 = F_238 ( V_41 , V_224 , V_211 , V_225 , error ) ;
* V_244 = 1 ;
}
}
return V_17 ;
}
static void F_256 ( struct V_199 * V_133 )
{
struct V_189 * V_190 = V_133 -> V_191 ;
F_257 ( & V_34 . V_35 ) ;
F_228 ( V_190 -> V_17 , V_133 ) ;
F_254 ( V_190 -> V_17 ) ;
F_258 ( V_133 , V_190 -> V_224 ) ;
F_258 ( V_133 , V_190 -> V_209 ) ;
F_237 ( V_190 ) ;
F_259 ( & V_34 . V_35 ) ;
}
static int F_260 ( struct V_246 * V_247 , struct V_222 * V_120 ,
struct V_199 * V_133 )
{
int V_23 ;
unsigned V_248 ;
const char * V_249 ;
static struct V_250 V_251 [] = {
{ 0 , 4 , L_40 } ,
} ;
if ( ! V_247 -> V_248 )
return 0 ;
V_23 = F_261 ( V_251 , V_247 , & V_248 , & V_133 -> error ) ;
if ( V_23 )
return - V_129 ;
while ( V_248 && ! V_23 ) {
V_249 = F_262 ( V_247 ) ;
V_248 -- ;
if ( ! strcasecmp ( V_249 , L_41 ) )
V_120 -> V_121 = false ;
else if ( ! strcasecmp ( V_249 , L_42 ) )
V_120 -> V_223 = false ;
else if ( ! strcasecmp ( V_249 , L_43 ) )
V_120 -> V_144 = false ;
else if ( ! strcasecmp ( V_249 , L_44 ) )
V_120 -> V_187 = V_128 ;
else if ( ! strcasecmp ( V_249 , L_45 ) )
V_120 -> V_138 = true ;
else {
V_133 -> error = L_46 ;
V_23 = - V_129 ;
break;
}
}
return V_23 ;
}
static void F_263 ( void * V_30 )
{
struct V_17 * V_17 = V_30 ;
F_126 ( L_47 ,
F_127 ( V_17 -> V_41 ) ) ;
F_128 ( V_17 -> V_133 -> V_134 ) ;
}
static T_2 F_264 ( struct V_42 * V_61 )
{
return F_265 ( V_61 -> V_252 ) >> V_100 ;
}
static void F_266 ( struct V_42 * V_61 )
{
T_2 V_253 = F_264 ( V_61 ) ;
char V_254 [ V_219 ] ;
if ( V_253 > V_255 )
F_126 ( L_48 ,
F_226 ( V_61 , V_254 ) , V_256 ) ;
}
static T_2 F_267 ( struct V_42 * V_61 )
{
T_2 V_253 = F_264 ( V_61 ) ;
if ( V_253 > V_256 )
V_253 = V_256 ;
return V_253 ;
}
static T_1 F_268 ( struct V_42 * V_61 )
{
T_2 V_253 = F_267 ( V_61 ) ;
F_64 ( V_253 , V_257 ) ;
return V_253 ;
}
static T_1 F_269 ( struct V_189 * V_190 )
{
T_1 V_258 = F_268 ( V_190 -> V_224 -> V_61 ) / 4 ;
return F_270 ( ( T_1 ) 1024ULL , V_258 ) ;
}
static int F_271 ( struct V_199 * V_133 , unsigned V_248 , char * * V_259 )
{
int V_23 , V_260 = 0 ;
struct V_189 * V_190 ;
struct V_17 * V_17 ;
struct V_222 V_120 ;
struct V_246 V_247 ;
struct V_113 * V_209 ;
unsigned long V_211 ;
T_1 V_131 ;
struct V_113 * V_224 ;
T_6 V_261 ;
F_257 ( & V_34 . V_35 ) ;
if ( V_248 < 4 ) {
V_133 -> error = L_49 ;
V_23 = - V_129 ;
goto V_262;
}
V_247 . V_248 = V_248 ;
V_247 . V_259 = V_259 ;
F_229 ( & V_120 ) ;
F_272 ( & V_247 , 4 ) ;
V_23 = F_260 ( & V_247 , & V_120 , V_133 ) ;
if ( V_23 )
goto V_262;
V_261 = V_263 | ( ( V_120 . V_187 == V_128 ) ? 0 : V_264 ) ;
V_23 = F_273 ( V_133 , V_259 [ 0 ] , V_261 , & V_224 ) ;
if ( V_23 ) {
V_133 -> error = L_50 ;
goto V_262;
}
F_266 ( V_224 -> V_61 ) ;
V_23 = F_273 ( V_133 , V_259 [ 1 ] , V_263 | V_264 , & V_209 ) ;
if ( V_23 ) {
V_133 -> error = L_51 ;
goto V_265;
}
if ( F_274 ( V_259 [ 2 ] , 10 , & V_211 ) || ! V_211 ||
V_211 < V_266 ||
V_211 > V_267 ||
V_211 & ( V_266 - 1 ) ) {
V_133 -> error = L_52 ;
V_23 = - V_129 ;
goto V_88;
}
if ( F_275 ( V_259 [ 3 ] , 10 , ( unsigned long long * ) & V_131 ) ) {
V_133 -> error = L_53 ;
V_23 = - V_129 ;
goto V_88;
}
V_190 = F_276 ( sizeof( * V_190 ) , V_229 ) ;
if ( ! V_190 ) {
V_23 = - V_105 ;
goto V_88;
}
V_17 = F_255 ( F_277 ( V_133 -> V_134 ) , V_224 -> V_61 ,
V_211 , V_120 . V_187 == V_128 , & V_133 -> error , & V_260 ) ;
if ( F_240 ( V_17 ) ) {
V_23 = F_246 ( V_17 ) ;
goto V_268;
}
if ( ! V_260 && V_120 . V_223 != V_17 -> V_120 . V_223 ) {
V_133 -> error = L_54 ;
V_23 = - V_129 ;
goto V_269;
}
V_190 -> V_17 = V_17 ;
V_190 -> V_133 = V_133 ;
V_190 -> V_224 = V_224 ;
V_190 -> V_209 = V_209 ;
V_190 -> V_131 = V_131 ;
V_190 -> V_196 = V_190 -> V_270 = V_120 ;
V_133 -> V_271 = 1 ;
V_133 -> V_272 = true ;
if ( V_120 . V_223 && V_120 . V_144 ) {
V_133 -> V_273 = 1 ;
V_133 -> V_274 = true ;
}
V_133 -> V_191 = V_190 ;
V_23 = F_278 ( V_190 -> V_17 -> V_96 ,
F_269 ( V_190 ) ,
F_263 ,
V_17 ) ;
if ( V_23 )
goto V_268;
V_190 -> V_206 . V_275 = F_218 ;
F_279 ( V_133 -> V_134 , & V_190 -> V_206 ) ;
F_259 ( & V_34 . V_35 ) ;
return 0 ;
V_269:
F_254 ( V_17 ) ;
V_268:
F_237 ( V_190 ) ;
V_88:
F_258 ( V_133 , V_209 ) ;
V_265:
F_258 ( V_133 , V_224 ) ;
V_262:
F_259 ( & V_34 . V_35 ) ;
return V_23 ;
}
static int F_280 ( struct V_199 * V_133 , struct V_20 * V_20 )
{
int V_23 ;
struct V_189 * V_190 = V_133 -> V_191 ;
struct V_17 * V_17 = V_190 -> V_17 ;
unsigned long V_47 ;
F_52 ( & V_17 -> V_12 , V_47 ) ;
V_20 -> V_59 = V_190 -> V_209 -> V_61 ;
V_23 = V_201 ;
F_53 ( & V_17 -> V_12 , V_47 ) ;
return V_23 ;
}
static int F_281 ( struct V_199 * V_133 , bool * V_276 )
{
int V_23 ;
struct V_189 * V_190 = V_133 -> V_191 ;
struct V_17 * V_17 = V_190 -> V_17 ;
T_2 V_277 = V_133 -> V_117 ;
T_1 V_278 ;
* V_276 = false ;
( void ) F_64 ( V_277 , V_17 -> V_57 ) ;
V_23 = F_282 ( V_17 -> V_96 , & V_278 ) ;
if ( V_23 ) {
F_207 ( L_55 ,
F_127 ( V_17 -> V_41 ) ) ;
return V_23 ;
}
if ( V_277 < V_278 ) {
F_207 ( L_56 ,
F_127 ( V_17 -> V_41 ) ,
( unsigned long long ) V_277 , V_278 ) ;
return - V_129 ;
} else if ( V_277 > V_278 ) {
if ( F_205 ( V_17 -> V_96 ) ) {
F_207 ( L_57 ,
F_127 ( V_17 -> V_41 ) ) ;
return 0 ;
}
if ( V_278 )
F_204 ( L_58 ,
F_127 ( V_17 -> V_41 ) ,
V_278 , ( unsigned long long ) V_277 ) ;
V_23 = F_283 ( V_17 -> V_96 , V_277 ) ;
if ( V_23 ) {
F_94 ( V_17 , L_59 , V_23 ) ;
return V_23 ;
}
* V_276 = true ;
}
return 0 ;
}
static int F_284 ( struct V_199 * V_133 , bool * V_276 )
{
int V_23 ;
struct V_189 * V_190 = V_133 -> V_191 ;
struct V_17 * V_17 = V_190 -> V_17 ;
T_1 V_253 , V_279 ;
* V_276 = false ;
V_253 = F_268 ( V_17 -> V_43 ) ;
V_23 = F_285 ( V_17 -> V_96 , & V_279 ) ;
if ( V_23 ) {
F_207 ( L_60 ,
F_127 ( V_17 -> V_41 ) ) ;
return V_23 ;
}
if ( V_253 < V_279 ) {
F_207 ( L_61 ,
F_127 ( V_17 -> V_41 ) ,
V_253 , V_279 ) ;
return - V_129 ;
} else if ( V_253 > V_279 ) {
if ( F_205 ( V_17 -> V_96 ) ) {
F_207 ( L_62 ,
F_127 ( V_17 -> V_41 ) ) ;
return 0 ;
}
F_266 ( V_17 -> V_43 ) ;
F_204 ( L_63 ,
F_127 ( V_17 -> V_41 ) ,
V_279 , V_253 ) ;
V_23 = F_286 ( V_17 -> V_96 , V_253 ) ;
if ( V_23 ) {
F_94 ( V_17 , L_64 , V_23 ) ;
return V_23 ;
}
* V_276 = true ;
}
return 0 ;
}
static int F_287 ( struct V_199 * V_133 )
{
int V_23 ;
bool V_280 , V_281 ;
struct V_189 * V_190 = V_133 -> V_191 ;
struct V_17 * V_17 = V_190 -> V_17 ;
V_23 = F_227 ( V_17 , V_133 ) ;
if ( V_23 )
return V_23 ;
V_23 = F_281 ( V_133 , & V_280 ) ;
if ( V_23 )
return V_23 ;
V_23 = F_284 ( V_133 , & V_281 ) ;
if ( V_23 )
return V_23 ;
if ( V_280 || V_281 )
( void ) F_123 ( V_17 ) ;
return 0 ;
}
static void F_288 ( struct V_17 * V_17 )
{
struct V_45 * V_46 ;
V_46 = F_179 ( V_17 ) ;
while ( V_46 ) {
F_289 ( V_46 -> V_282 ) ;
V_46 = F_182 ( V_17 , V_46 ) ;
}
}
static void F_290 ( struct V_17 * V_17 )
{
struct V_45 * V_46 ;
V_46 = F_179 ( V_17 ) ;
while ( V_46 ) {
F_291 ( V_46 -> V_282 ) ;
V_46 = F_182 ( V_17 , V_46 ) ;
}
}
static void F_292 ( struct V_199 * V_133 )
{
struct V_189 * V_190 = V_133 -> V_191 ;
struct V_17 * V_17 = V_190 -> V_17 ;
unsigned long V_47 ;
F_221 ( V_17 ) ;
F_290 ( V_17 ) ;
F_52 ( & V_17 -> V_12 , V_47 ) ;
V_17 -> V_132 = false ;
V_17 -> V_237 = false ;
F_53 ( & V_17 -> V_12 , V_47 ) ;
F_189 ( & V_17 -> V_181 . V_283 ) ;
}
static void F_293 ( struct V_199 * V_133 )
{
struct V_189 * V_190 = V_133 -> V_191 ;
struct V_17 * V_17 = V_190 -> V_17 ;
unsigned long V_47 ;
F_52 ( & V_17 -> V_12 , V_47 ) ;
V_17 -> V_237 = true ;
F_53 ( & V_17 -> V_12 , V_47 ) ;
F_288 ( V_17 ) ;
}
static void F_294 ( struct V_199 * V_133 )
{
struct V_189 * V_190 = V_133 -> V_191 ;
struct V_17 * V_17 = V_190 -> V_17 ;
unsigned long V_47 ;
F_290 ( V_17 ) ;
F_52 ( & V_17 -> V_12 , V_47 ) ;
V_17 -> V_237 = false ;
F_53 ( & V_17 -> V_12 , V_47 ) ;
}
static void F_295 ( struct V_199 * V_133 )
{
struct V_189 * V_190 = V_133 -> V_191 ;
struct V_17 * V_17 = V_190 -> V_17 ;
F_296 ( & V_17 -> V_181 ) ;
F_296 ( & V_17 -> V_182 ) ;
F_297 ( V_17 -> V_18 ) ;
( void ) F_123 ( V_17 ) ;
}
static int F_298 ( unsigned V_248 , unsigned V_284 )
{
if ( V_248 != V_284 ) {
F_126 ( L_65 ,
V_248 , V_284 ) ;
return - V_129 ;
}
return 0 ;
}
static int F_299 ( char * V_285 , T_7 * V_286 , int V_287 )
{
if ( ! F_275 ( V_285 , 10 , ( unsigned long long * ) V_286 ) &&
* V_286 <= V_288 )
return 0 ;
if ( V_287 )
F_126 ( L_66 , V_285 ) ;
return - V_129 ;
}
static int F_300 ( unsigned V_248 , char * * V_259 , struct V_17 * V_17 )
{
T_7 V_286 ;
int V_23 ;
V_23 = F_298 ( V_248 , 2 ) ;
if ( V_23 )
return V_23 ;
V_23 = F_299 ( V_259 [ 1 ] , & V_286 , 1 ) ;
if ( V_23 )
return V_23 ;
V_23 = F_301 ( V_17 -> V_96 , V_286 ) ;
if ( V_23 ) {
F_126 ( L_67 ,
V_259 [ 1 ] ) ;
return V_23 ;
}
return 0 ;
}
static int F_302 ( unsigned V_248 , char * * V_259 , struct V_17 * V_17 )
{
T_7 V_286 ;
T_7 V_289 ;
int V_23 ;
V_23 = F_298 ( V_248 , 3 ) ;
if ( V_23 )
return V_23 ;
V_23 = F_299 ( V_259 [ 1 ] , & V_286 , 1 ) ;
if ( V_23 )
return V_23 ;
V_23 = F_299 ( V_259 [ 2 ] , & V_289 , 1 ) ;
if ( V_23 )
return V_23 ;
V_23 = F_303 ( V_17 -> V_96 , V_286 , V_289 ) ;
if ( V_23 ) {
F_126 ( L_68 ,
V_259 [ 1 ] , V_259 [ 2 ] ) ;
return V_23 ;
}
return 0 ;
}
static int F_304 ( unsigned V_248 , char * * V_259 , struct V_17 * V_17 )
{
T_7 V_286 ;
int V_23 ;
V_23 = F_298 ( V_248 , 2 ) ;
if ( V_23 )
return V_23 ;
V_23 = F_299 ( V_259 [ 1 ] , & V_286 , 1 ) ;
if ( V_23 )
return V_23 ;
V_23 = F_305 ( V_17 -> V_96 , V_286 ) ;
if ( V_23 )
F_126 ( L_69 , V_259 [ 1 ] ) ;
return V_23 ;
}
static int F_306 ( unsigned V_248 , char * * V_259 , struct V_17 * V_17 )
{
T_7 V_290 , V_291 ;
int V_23 ;
V_23 = F_298 ( V_248 , 3 ) ;
if ( V_23 )
return V_23 ;
if ( F_275 ( V_259 [ 1 ] , 10 , ( unsigned long long * ) & V_290 ) ) {
F_126 ( L_70 , V_259 [ 1 ] ) ;
return - V_129 ;
}
if ( F_275 ( V_259 [ 2 ] , 10 , ( unsigned long long * ) & V_291 ) ) {
F_126 ( L_71 , V_259 [ 2 ] ) ;
return - V_129 ;
}
V_23 = F_307 ( V_17 -> V_96 , V_290 , V_291 ) ;
if ( V_23 ) {
F_126 ( L_72 ,
V_259 [ 1 ] , V_259 [ 2 ] ) ;
return V_23 ;
}
return 0 ;
}
static int F_308 ( unsigned V_248 , char * * V_259 , struct V_17 * V_17 )
{
int V_23 ;
V_23 = F_298 ( V_248 , 1 ) ;
if ( V_23 )
return V_23 ;
( void ) F_123 ( V_17 ) ;
V_23 = F_309 ( V_17 -> V_96 ) ;
if ( V_23 )
F_126 ( L_73 ) ;
return V_23 ;
}
static int F_310 ( unsigned V_248 , char * * V_259 , struct V_17 * V_17 )
{
int V_23 ;
V_23 = F_298 ( V_248 , 1 ) ;
if ( V_23 )
return V_23 ;
V_23 = F_311 ( V_17 -> V_96 ) ;
if ( V_23 )
F_126 ( L_74 ) ;
return V_23 ;
}
static int F_312 ( struct V_199 * V_133 , unsigned V_248 , char * * V_259 )
{
int V_23 = - V_129 ;
struct V_189 * V_190 = V_133 -> V_191 ;
struct V_17 * V_17 = V_190 -> V_17 ;
if ( F_120 ( V_17 ) >= V_128 ) {
F_207 ( L_75 ,
F_127 ( V_17 -> V_41 ) ) ;
return - V_129 ;
}
if ( ! strcasecmp ( V_259 [ 0 ] , L_76 ) )
V_23 = F_300 ( V_248 , V_259 , V_17 ) ;
else if ( ! strcasecmp ( V_259 [ 0 ] , L_77 ) )
V_23 = F_302 ( V_248 , V_259 , V_17 ) ;
else if ( ! strcasecmp ( V_259 [ 0 ] , L_78 ) )
V_23 = F_304 ( V_248 , V_259 , V_17 ) ;
else if ( ! strcasecmp ( V_259 [ 0 ] , L_79 ) )
V_23 = F_306 ( V_248 , V_259 , V_17 ) ;
else if ( ! strcasecmp ( V_259 [ 0 ] , L_80 ) )
V_23 = F_308 ( V_248 , V_259 , V_17 ) ;
else if ( ! strcasecmp ( V_259 [ 0 ] , L_81 ) )
V_23 = F_310 ( V_248 , V_259 , V_17 ) ;
else
F_126 ( L_82 , V_259 [ 0 ] ) ;
if ( ! V_23 )
( void ) F_123 ( V_17 ) ;
return V_23 ;
}
static void F_313 ( struct V_222 * V_120 , char * V_135 ,
unsigned V_292 , unsigned V_293 )
{
unsigned V_111 = ! V_120 -> V_121 + ! V_120 -> V_223 +
! V_120 -> V_144 + ( V_120 -> V_187 == V_128 ) +
V_120 -> V_138 ;
F_314 ( L_83 , V_111 ) ;
if ( ! V_120 -> V_121 )
F_314 ( L_84 ) ;
if ( ! V_120 -> V_223 )
F_314 ( L_85 ) ;
if ( ! V_120 -> V_144 )
F_314 ( L_86 ) ;
if ( V_120 -> V_187 == V_128 )
F_314 ( L_87 ) ;
if ( V_120 -> V_138 )
F_314 ( L_88 ) ;
}
static void F_315 ( struct V_199 * V_133 , T_8 type ,
unsigned V_294 , char * V_135 , unsigned V_293 )
{
int V_23 ;
unsigned V_292 = 0 ;
T_9 V_295 ;
T_1 V_296 ;
T_1 V_297 ;
T_1 V_298 ;
T_1 V_299 ;
T_1 V_300 ;
char V_218 [ V_219 ] ;
char V_301 [ V_219 ] ;
struct V_189 * V_190 = V_133 -> V_191 ;
struct V_17 * V_17 = V_190 -> V_17 ;
switch ( type ) {
case V_302 :
if ( F_120 ( V_17 ) == V_139 ) {
F_314 ( L_89 ) ;
break;
}
if ( ! ( V_294 & V_303 ) && ! F_316 ( V_133 ) )
( void ) F_123 ( V_17 ) ;
V_23 = F_317 ( V_17 -> V_96 , & V_295 ) ;
if ( V_23 ) {
F_207 ( L_90 ,
F_127 ( V_17 -> V_41 ) , V_23 ) ;
goto V_78;
}
V_23 = F_318 ( V_17 -> V_96 , & V_297 ) ;
if ( V_23 ) {
F_207 ( L_91 ,
F_127 ( V_17 -> V_41 ) , V_23 ) ;
goto V_78;
}
V_23 = F_285 ( V_17 -> V_96 , & V_299 ) ;
if ( V_23 ) {
F_207 ( L_92 ,
F_127 ( V_17 -> V_41 ) , V_23 ) ;
goto V_78;
}
V_23 = F_121 ( V_17 -> V_96 , & V_296 ) ;
if ( V_23 ) {
F_207 ( L_93 ,
F_127 ( V_17 -> V_41 ) , V_23 ) ;
goto V_78;
}
V_23 = F_282 ( V_17 -> V_96 , & V_298 ) ;
if ( V_23 ) {
F_207 ( L_94 ,
F_127 ( V_17 -> V_41 ) , V_23 ) ;
goto V_78;
}
V_23 = F_319 ( V_17 -> V_96 , & V_300 ) ;
if ( V_23 ) {
F_207 ( L_95 ,
F_127 ( V_17 -> V_41 ) , V_23 ) ;
goto V_78;
}
F_314 ( L_96 ,
( unsigned long long ) V_295 ,
( unsigned long long ) ( V_299 - V_297 ) ,
( unsigned long long ) V_299 ,
( unsigned long long ) ( V_298 - V_296 ) ,
( unsigned long long ) V_298 ) ;
if ( V_300 )
F_314 ( L_97 , V_300 ) ;
else
F_314 ( L_98 ) ;
if ( V_17 -> V_120 . V_187 == V_126 )
F_314 ( L_99 ) ;
else if ( V_17 -> V_120 . V_187 == V_128 )
F_314 ( L_100 ) ;
else
F_314 ( L_101 ) ;
if ( ! V_17 -> V_120 . V_223 )
F_314 ( L_85 ) ;
else if ( V_17 -> V_120 . V_144 )
F_314 ( L_102 ) ;
else
F_314 ( L_86 ) ;
if ( V_17 -> V_120 . V_138 )
F_314 ( L_88 ) ;
else
F_314 ( L_103 ) ;
break;
case V_304 :
F_314 ( L_104 ,
F_320 ( V_218 , V_190 -> V_224 -> V_61 -> V_305 ) ,
F_320 ( V_301 , V_190 -> V_209 -> V_61 -> V_305 ) ,
( unsigned long ) V_17 -> V_57 ,
( unsigned long long ) V_190 -> V_131 ) ;
F_313 ( & V_190 -> V_270 , V_135 , V_292 , V_293 ) ;
break;
}
return;
V_78:
F_314 ( L_105 ) ;
}
static int F_321 ( struct V_199 * V_133 ,
T_10 F_24 , void * V_306 )
{
struct V_189 * V_190 = V_133 -> V_191 ;
return F_24 ( V_133 , V_190 -> V_209 , 0 , V_133 -> V_117 , V_306 ) ;
}
static int F_322 ( struct V_199 * V_133 , struct V_307 * V_308 ,
struct V_309 * V_310 , int V_311 )
{
struct V_189 * V_190 = V_133 -> V_191 ;
struct V_207 * V_208 = F_219 ( V_190 -> V_209 -> V_61 ) ;
if ( ! V_208 -> V_312 )
return V_311 ;
V_308 -> V_59 = V_190 -> V_209 -> V_61 ;
return F_270 ( V_311 , V_208 -> V_312 ( V_208 , V_308 , V_310 ) ) ;
}
static void F_323 ( struct V_189 * V_190 , struct V_214 * V_216 )
{
struct V_17 * V_17 = V_190 -> V_17 ;
struct V_214 * V_215 ;
V_216 -> V_220 = V_17 -> V_57 ;
if ( V_190 -> V_196 . V_144 ) {
V_215 = & F_219 ( V_190 -> V_209 -> V_61 ) -> V_216 ;
V_216 -> V_221 = F_324 ( V_215 -> V_221 ,
V_17 -> V_57 << V_100 ) ;
} else
V_216 -> V_221 = V_17 -> V_57 << V_100 ;
}
static void F_325 ( struct V_199 * V_133 , struct V_214 * V_216 )
{
struct V_189 * V_190 = V_133 -> V_191 ;
struct V_17 * V_17 = V_190 -> V_17 ;
T_2 V_313 = V_216 -> V_314 >> V_100 ;
if ( V_216 -> V_315 < V_17 -> V_57 ) {
while ( ! F_224 ( V_17 -> V_57 , V_216 -> V_315 ) ) {
if ( ( V_216 -> V_315 & ( V_216 -> V_315 - 1 ) ) == 0 )
V_216 -> V_315 -- ;
V_216 -> V_315 = F_326 ( V_216 -> V_315 ) ;
}
}
if ( V_313 < V_17 -> V_57 ||
! F_224 ( V_313 , V_17 -> V_57 ) ) {
if ( F_224 ( V_17 -> V_57 , V_216 -> V_315 ) )
F_327 ( V_216 , V_216 -> V_315 << V_100 ) ;
else
F_327 ( V_216 , V_17 -> V_57 << V_100 ) ;
F_328 ( V_216 , V_17 -> V_57 << V_100 ) ;
}
if ( ! V_190 -> V_196 . V_223 ) {
V_216 -> V_221 = 0 ;
return;
}
F_225 ( V_190 ) ;
F_323 ( V_190 , V_216 ) ;
}
static void F_181 ( struct V_45 * V_46 )
{
F_90 ( & V_46 -> V_316 ) ;
}
static void F_184 ( struct V_45 * V_46 )
{
if ( F_80 ( & V_46 -> V_316 ) )
F_195 ( & V_46 -> V_317 ) ;
}
static void F_329 ( struct V_199 * V_133 )
{
struct V_45 * V_46 = V_133 -> V_191 ;
unsigned long V_47 ;
F_52 ( & V_46 -> V_17 -> V_12 , V_47 ) ;
F_330 ( & V_46 -> V_37 ) ;
F_53 ( & V_46 -> V_17 -> V_12 , V_47 ) ;
F_331 () ;
F_184 ( V_46 ) ;
F_199 ( & V_46 -> V_317 ) ;
F_257 ( & V_34 . V_35 ) ;
F_254 ( V_46 -> V_17 ) ;
F_332 ( V_46 -> V_2 ) ;
F_258 ( V_133 , V_46 -> V_60 ) ;
if ( V_46 -> V_62 )
F_258 ( V_133 , V_46 -> V_62 ) ;
F_237 ( V_46 ) ;
F_259 ( & V_34 . V_35 ) ;
}
static int F_333 ( struct V_199 * V_133 , unsigned V_248 , char * * V_259 )
{
int V_23 ;
struct V_45 * V_46 ;
struct V_113 * V_60 , * V_62 ;
struct V_38 * V_41 ;
unsigned long V_47 ;
F_257 ( & V_34 . V_35 ) ;
if ( V_248 != 2 && V_248 != 3 ) {
V_133 -> error = L_49 ;
V_23 = - V_129 ;
goto V_262;
}
V_46 = V_133 -> V_191 = F_276 ( sizeof( * V_46 ) , V_229 ) ;
if ( ! V_46 ) {
V_133 -> error = L_106 ;
V_23 = - V_105 ;
goto V_262;
}
V_46 -> V_282 = F_277 ( V_133 -> V_134 ) ;
F_250 ( & V_46 -> V_12 ) ;
F_35 ( & V_46 -> V_50 ) ;
F_47 ( & V_46 -> V_51 ) ;
F_47 ( & V_46 -> V_52 ) ;
V_46 -> V_159 = V_318 ;
if ( V_248 == 3 ) {
V_23 = F_273 ( V_133 , V_259 [ 2 ] , V_263 , & V_62 ) ;
if ( V_23 ) {
V_133 -> error = L_107 ;
goto V_319;
}
V_46 -> V_62 = V_62 ;
}
V_23 = F_273 ( V_133 , V_259 [ 0 ] , F_334 ( V_133 -> V_134 ) , & V_60 ) ;
if ( V_23 ) {
V_133 -> error = L_108 ;
goto V_320;
}
V_46 -> V_60 = V_60 ;
if ( F_299 ( V_259 [ 1 ] , ( unsigned long long * ) & V_46 -> V_286 , 0 ) ) {
V_133 -> error = L_109 ;
V_23 = - V_129 ;
goto V_321;
}
V_41 = F_335 ( V_46 -> V_60 -> V_61 -> V_305 ) ;
if ( ! V_41 ) {
V_133 -> error = L_110 ;
V_23 = - V_129 ;
goto V_321;
}
V_46 -> V_17 = F_42 ( V_41 ) ;
if ( ! V_46 -> V_17 ) {
V_133 -> error = L_111 ;
V_23 = - V_129 ;
goto V_322;
}
F_253 ( V_46 -> V_17 ) ;
if ( F_120 ( V_46 -> V_17 ) == V_139 ) {
V_133 -> error = L_112 ;
V_23 = - V_129 ;
goto V_230;
}
V_23 = F_336 ( V_46 -> V_17 -> V_96 , V_46 -> V_286 , & V_46 -> V_2 ) ;
if ( V_23 ) {
V_133 -> error = L_113 ;
goto V_230;
}
V_23 = F_337 ( V_133 , V_46 -> V_17 -> V_57 ) ;
if ( V_23 )
goto V_323;
V_133 -> V_271 = 1 ;
V_133 -> V_324 = true ;
V_133 -> V_325 = sizeof( struct V_66 ) ;
V_133 -> V_272 = true ;
if ( V_46 -> V_17 -> V_120 . V_223 ) {
V_133 -> V_274 = true ;
V_133 -> V_273 = 1 ;
V_133 -> V_326 = true ;
}
F_259 ( & V_34 . V_35 ) ;
F_52 ( & V_46 -> V_17 -> V_12 , V_47 ) ;
if ( V_46 -> V_17 -> V_237 ) {
F_53 ( & V_46 -> V_17 -> V_12 , V_47 ) ;
F_257 ( & V_34 . V_35 ) ;
V_133 -> error = L_114 ;
V_23 = - V_129 ;
goto V_323;
}
F_113 ( & V_46 -> V_316 , 1 ) ;
F_198 ( & V_46 -> V_317 ) ;
F_338 ( & V_46 -> V_37 , & V_46 -> V_17 -> V_175 ) ;
F_53 ( & V_46 -> V_17 -> V_12 , V_47 ) ;
F_331 () ;
F_339 ( V_41 ) ;
return 0 ;
V_323:
F_332 ( V_46 -> V_2 ) ;
V_230:
F_254 ( V_46 -> V_17 ) ;
V_322:
F_339 ( V_41 ) ;
V_321:
F_258 ( V_133 , V_46 -> V_60 ) ;
V_320:
if ( V_46 -> V_62 )
F_258 ( V_133 , V_46 -> V_62 ) ;
V_319:
F_237 ( V_46 ) ;
V_262:
F_259 ( & V_34 . V_35 ) ;
return V_23 ;
}
static int F_340 ( struct V_199 * V_133 , struct V_20 * V_20 )
{
V_20 -> V_55 . V_56 = F_341 ( V_133 , V_20 -> V_55 . V_56 ) ;
return F_216 ( V_133 , V_20 ) ;
}
static int F_342 ( struct V_199 * V_133 , struct V_20 * V_20 , int V_78 )
{
unsigned long V_47 ;
struct V_66 * V_67 = F_70 ( V_20 , sizeof( struct V_66 ) ) ;
struct V_48 V_283 ;
struct V_72 * V_73 , * V_40 ;
struct V_17 * V_17 = V_67 -> V_46 -> V_17 ;
if ( V_67 -> V_148 ) {
F_35 ( & V_283 ) ;
F_343 ( V_67 -> V_148 , & V_283 ) ;
F_52 ( & V_17 -> V_12 , V_47 ) ;
F_56 (m, tmp, &work, list) {
F_41 ( & V_73 -> V_37 ) ;
F_79 ( V_73 ) ;
}
F_53 ( & V_17 -> V_12 , V_47 ) ;
}
if ( V_67 -> V_69 ) {
F_35 ( & V_283 ) ;
F_343 ( V_67 -> V_69 , & V_283 ) ;
if ( ! F_177 ( & V_283 ) ) {
F_52 ( & V_17 -> V_12 , V_47 ) ;
F_56 (m, tmp, &work, list)
F_81 ( & V_73 -> V_37 , & V_17 -> V_180 ) ;
F_53 ( & V_17 -> V_12 , V_47 ) ;
F_15 ( V_17 ) ;
}
}
return 0 ;
}
static void F_344 ( struct V_199 * V_133 )
{
struct V_45 * V_46 = V_133 -> V_191 ;
if ( F_345 ( V_133 ) )
V_185 ( V_46 , F_201 ) ;
}
static void F_346 ( struct V_199 * V_133 )
{
struct V_45 * V_46 = V_133 -> V_191 ;
V_185 ( V_46 , F_202 ) ;
}
static int F_347 ( struct V_199 * V_133 )
{
struct V_45 * V_46 = V_133 -> V_191 ;
if ( V_46 -> V_62 )
V_46 -> V_124 = F_264 ( V_46 -> V_62 -> V_61 ) ;
return 0 ;
}
static void F_348 ( struct V_199 * V_133 , T_8 type ,
unsigned V_294 , char * V_135 , unsigned V_293 )
{
int V_23 ;
T_11 V_292 = 0 ;
T_1 V_327 , V_328 ;
char V_218 [ V_219 ] ;
struct V_45 * V_46 = V_133 -> V_191 ;
if ( F_120 ( V_46 -> V_17 ) == V_139 ) {
F_314 ( L_89 ) ;
return;
}
if ( ! V_46 -> V_2 )
F_314 ( L_115 ) ;
else {
switch ( type ) {
case V_302 :
V_23 = F_349 ( V_46 -> V_2 , & V_327 ) ;
if ( V_23 ) {
F_207 ( L_116 , V_23 ) ;
goto V_78;
}
V_23 = F_350 ( V_46 -> V_2 , & V_328 ) ;
if ( V_23 < 0 ) {
F_207 ( L_117 , V_23 ) ;
goto V_78;
}
F_314 ( L_97 , V_327 * V_46 -> V_17 -> V_57 ) ;
if ( V_23 )
F_314 ( L_118 , ( ( V_328 + 1 ) *
V_46 -> V_17 -> V_57 ) - 1 ) ;
else
F_314 ( L_115 ) ;
break;
case V_304 :
F_314 ( L_119 ,
F_320 ( V_218 , V_46 -> V_60 -> V_61 -> V_305 ) ,
( unsigned long ) V_46 -> V_286 ) ;
if ( V_46 -> V_62 )
F_314 ( L_120 , F_320 ( V_218 , V_46 -> V_62 -> V_61 -> V_305 ) ) ;
break;
}
}
return;
V_78:
F_314 ( L_105 ) ;
}
static int F_351 ( struct V_199 * V_133 , struct V_307 * V_308 ,
struct V_309 * V_310 , int V_311 )
{
struct V_45 * V_46 = V_133 -> V_191 ;
struct V_207 * V_208 = F_219 ( V_46 -> V_60 -> V_61 ) ;
if ( ! V_208 -> V_312 )
return V_311 ;
V_308 -> V_59 = V_46 -> V_60 -> V_61 ;
V_308 -> V_56 = F_341 ( V_133 , V_308 -> V_56 ) ;
return F_270 ( V_311 , V_208 -> V_312 ( V_208 , V_308 , V_310 ) ) ;
}
static int F_352 ( struct V_199 * V_133 ,
T_10 F_24 , void * V_306 )
{
T_2 V_329 ;
struct V_45 * V_46 = V_133 -> V_191 ;
struct V_17 * V_17 = V_46 -> V_17 ;
if ( ! V_17 -> V_133 )
return 0 ;
V_329 = V_17 -> V_133 -> V_117 ;
( void ) F_64 ( V_329 , V_17 -> V_57 ) ;
if ( V_329 )
return F_24 ( V_133 , V_46 -> V_60 , 0 , V_17 -> V_57 * V_329 , V_306 ) ;
return 0 ;
}
static int T_12 F_353 ( void )
{
int V_23 ;
F_33 () ;
V_23 = F_354 ( & V_330 ) ;
if ( V_23 )
return V_23 ;
V_23 = F_354 ( & V_331 ) ;
if ( V_23 )
goto V_332;
V_23 = - V_105 ;
V_241 = F_355 ( V_72 , 0 ) ;
if ( ! V_241 )
goto V_333;
return 0 ;
V_333:
F_356 ( & V_331 ) ;
V_332:
F_356 ( & V_330 ) ;
return V_23 ;
}
static void F_357 ( void )
{
F_356 ( & V_330 ) ;
F_356 ( & V_331 ) ;
F_358 ( V_241 ) ;
}
