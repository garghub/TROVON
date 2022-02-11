static void F_1 ( struct V_1 * V_2 , enum V_3 V_4 ,
T_1 V_5 , T_1 V_6 , struct V_7 * V_8 )
{
V_8 -> V_9 = ( V_4 == V_10 ) ;
V_8 -> V_11 = F_2 ( V_2 ) ;
V_8 -> V_12 = V_5 ;
V_8 -> V_13 = V_6 ;
}
static void F_3 ( struct V_1 * V_2 , T_1 V_5 ,
struct V_7 * V_8 )
{
F_1 ( V_2 , V_14 , V_5 , V_5 + 1llu , V_8 ) ;
}
static void F_4 ( struct V_1 * V_2 , T_1 V_5 ,
struct V_7 * V_8 )
{
F_1 ( V_2 , V_10 , V_5 , V_5 + 1llu , V_8 ) ;
}
static void F_5 ( struct V_15 * V_16 )
{
F_6 ( & V_16 -> V_17 ) ;
V_16 -> V_18 = false ;
}
static void F_7 ( struct V_15 * V_16 )
{
V_16 -> V_19 = V_20 + V_21 ;
}
static void F_8 ( struct V_15 * V_16 )
{
if ( ! V_16 -> V_18 && V_20 > V_16 -> V_19 ) {
F_9 ( & V_16 -> V_17 ) ;
V_16 -> V_18 = true ;
}
}
static void F_10 ( struct V_15 * V_16 )
{
if ( V_16 -> V_18 ) {
V_16 -> V_18 = false ;
F_11 ( & V_16 -> V_17 ) ;
}
}
static void F_12 ( struct V_15 * V_16 )
{
F_13 ( & V_16 -> V_17 ) ;
}
static void F_14 ( struct V_15 * V_16 )
{
F_15 ( & V_16 -> V_17 ) ;
}
static int F_16 ( struct V_22 * V_23 , T_2 V_24 ,
T_2 V_25 , T_3 V_26 , unsigned long V_27 ,
struct V_28 * V_29 )
{
struct V_30 * V_31 = F_17 ( V_23 ) ;
int type = V_32 | V_33 ;
struct V_28 * V_28 ;
if ( ! V_31 || ! V_25 )
return - V_34 ;
if ( ! F_18 ( V_31 ) )
return - V_35 ;
if ( V_27 & V_36 ) {
if ( ! F_19 ( V_31 ) )
return - V_35 ;
type |= V_37 ;
}
V_28 = F_20 ( V_26 , 1 ) ;
if ( ! V_28 )
return - V_38 ;
F_21 ( V_28 , V_29 ) ;
V_28 -> V_39 . V_40 = V_24 ;
V_28 -> V_41 = V_23 ;
V_28 -> V_39 . V_42 = V_25 << 9 ;
F_22 ( type , V_28 ) ;
return 0 ;
}
static bool F_23 ( struct V_43 * V_43 )
{
return V_43 -> V_44 >= 0 ;
}
static T_2 F_24 ( struct V_43 * V_43 , T_1 V_5 )
{
return F_23 ( V_43 ) ?
( V_5 << V_43 -> V_44 ) :
( V_5 * V_43 -> V_45 ) ;
}
static int F_25 ( struct V_46 * V_47 , T_1 V_48 , T_1 V_49 ,
struct V_28 * V_29 )
{
T_2 V_50 = F_24 ( V_47 -> V_43 , V_48 ) ;
T_2 V_51 = F_24 ( V_47 -> V_43 , V_49 - V_48 ) ;
return F_16 ( V_47 -> V_52 -> V_23 , V_50 , V_51 ,
V_53 , 0 , V_29 ) ;
}
static void F_26 ( struct V_43 * V_43 )
{
F_27 ( V_43 -> V_54 , & V_43 -> V_55 ) ;
}
static int F_28 ( struct V_43 * V_43 , struct V_7 * V_8 , struct V_28 * V_28 ,
struct V_56 * * V_57 )
{
int V_58 ;
struct V_56 * V_59 ;
V_59 = F_29 ( V_43 -> V_60 , V_61 ) ;
V_58 = F_30 ( V_43 -> V_60 , V_8 , V_28 , V_59 , V_57 ) ;
if ( V_58 )
F_31 ( V_43 -> V_60 , V_59 ) ;
return V_58 ;
}
static void F_32 ( struct V_43 * V_43 ,
struct V_56 * V_62 ,
struct V_63 * V_64 )
{
F_33 ( V_43 -> V_60 , V_62 , V_64 ) ;
F_31 ( V_43 -> V_60 , V_62 ) ;
}
static void F_34 ( struct V_43 * V_43 ,
void (* F_35)( void * , struct V_56 * ) ,
void * V_65 ,
struct V_56 * V_62 )
{
F_36 ( V_43 -> V_60 , F_35 , V_65 , V_62 ) ;
F_31 ( V_43 -> V_60 , V_62 ) ;
}
static void F_37 ( struct V_43 * V_43 ,
struct V_56 * V_62 ,
struct V_63 * V_64 )
{
F_38 ( V_43 -> V_60 , V_62 , V_64 ) ;
F_31 ( V_43 -> V_60 , V_62 ) ;
}
static void F_39 ( struct V_43 * V_43 ,
struct V_56 * V_62 , int V_66 )
{
F_40 ( V_43 -> V_60 , V_62 , V_66 ) ;
F_31 ( V_43 -> V_60 , V_62 ) ;
}
static int F_41 ( struct V_43 * V_43 )
{
return V_43 -> V_67 ? - V_68 : - V_69 ;
}
static void F_42 ( struct V_43 * V_43 , struct V_56 * V_62 )
{
int error = F_41 ( V_43 ) ;
F_39 ( V_43 , V_62 , error ) ;
}
static void F_43 ( struct V_43 * V_43 , struct V_56 * V_62 )
{
F_39 ( V_43 , V_62 , 0 ) ;
}
static void F_44 ( struct V_43 * V_43 , struct V_56 * V_62 )
{
F_39 ( V_43 , V_62 , V_70 ) ;
}
static void F_45 ( void )
{
F_46 ( & V_71 . V_72 ) ;
F_47 ( & V_71 . V_73 ) ;
}
static void F_48 ( struct V_43 * V_43 )
{
F_49 ( ! F_50 ( & V_71 . V_72 ) ) ;
F_51 ( & V_43 -> V_74 , & V_71 . V_73 ) ;
}
static void F_52 ( struct V_43 * V_43 )
{
F_49 ( ! F_50 ( & V_71 . V_72 ) ) ;
F_53 ( & V_43 -> V_74 ) ;
}
static struct V_43 * F_54 ( struct V_75 * V_76 )
{
struct V_43 * V_43 = NULL , * V_77 ;
F_49 ( ! F_50 ( & V_71 . V_72 ) ) ;
F_55 (tmp, &dm_thin_pool_table.pools, list) {
if ( V_77 -> V_78 == V_76 ) {
V_43 = V_77 ;
break;
}
}
return V_43 ;
}
static struct V_43 * F_56 ( struct V_22 * V_79 )
{
struct V_43 * V_43 = NULL , * V_77 ;
F_49 ( ! F_50 ( & V_71 . V_72 ) ) ;
F_55 (tmp, &dm_thin_pool_table.pools, list) {
if ( V_77 -> V_79 == V_79 ) {
V_43 = V_77 ;
break;
}
}
return V_43 ;
}
static void F_57 ( struct V_63 * V_64 , struct V_63 * V_80 )
{
F_58 ( V_64 , V_80 ) ;
F_59 ( V_80 ) ;
}
static void F_60 ( struct V_63 * V_64 , int error )
{
struct V_28 * V_28 ;
while ( ( V_28 = F_61 ( V_64 ) ) ) {
V_28 -> V_81 = error ;
F_62 ( V_28 ) ;
}
}
static void F_63 ( struct V_46 * V_47 , struct V_63 * V_80 , int error )
{
struct V_63 V_64 ;
unsigned long V_27 ;
F_59 ( & V_64 ) ;
F_64 ( & V_47 -> V_17 , V_27 ) ;
F_57 ( & V_64 , V_80 ) ;
F_65 ( & V_47 -> V_17 , V_27 ) ;
F_60 ( & V_64 , error ) ;
}
static void F_66 ( struct V_46 * V_47 )
{
struct V_43 * V_43 = V_47 -> V_43 ;
unsigned long V_27 ;
struct V_82 V_83 ;
struct V_56 * V_62 , * V_77 ;
F_47 ( & V_83 ) ;
F_64 ( & V_47 -> V_17 , V_27 ) ;
F_67 ( & V_47 -> V_84 , & V_83 ) ;
F_65 ( & V_47 -> V_17 , V_27 ) ;
F_68 (cell, tmp, &cells, user_list)
F_44 ( V_43 , V_62 ) ;
}
static void F_69 ( struct V_46 * V_47 )
{
struct V_63 V_64 ;
unsigned long V_27 ;
F_59 ( & V_64 ) ;
F_64 ( & V_47 -> V_17 , V_27 ) ;
F_57 ( & V_64 , & V_47 -> V_85 ) ;
F_57 ( & V_64 , & V_47 -> V_86 ) ;
F_65 ( & V_47 -> V_17 , V_27 ) ;
F_60 ( & V_64 , V_70 ) ;
F_66 ( V_47 ) ;
}
static void F_70 ( struct V_43 * V_43 , int error )
{
struct V_46 * V_47 ;
F_71 () ;
F_72 (tc, &pool->active_thins, list)
F_63 ( V_47 , & V_47 -> V_86 , error ) ;
F_73 () ;
}
static void F_74 ( struct V_43 * V_43 )
{
int error = F_41 ( V_43 ) ;
return F_70 ( V_43 , error ) ;
}
static T_1 F_75 ( struct V_46 * V_47 , struct V_28 * V_28 )
{
struct V_43 * V_43 = V_47 -> V_43 ;
T_2 V_87 = V_28 -> V_39 . V_40 ;
if ( F_23 ( V_43 ) )
V_87 >>= V_43 -> V_44 ;
else
( void ) F_76 ( V_87 , V_43 -> V_45 ) ;
return V_87 ;
}
static void F_77 ( struct V_46 * V_47 , struct V_28 * V_28 ,
T_1 * V_88 , T_1 * V_89 )
{
struct V_43 * V_43 = V_47 -> V_43 ;
T_2 V_5 = V_28 -> V_39 . V_40 ;
T_2 V_6 = V_5 + ( V_28 -> V_39 . V_42 >> V_90 ) ;
V_5 += V_43 -> V_45 - 1ull ;
if ( F_23 ( V_43 ) ) {
V_5 >>= V_43 -> V_44 ;
V_6 >>= V_43 -> V_44 ;
} else {
( void ) F_76 ( V_5 , V_43 -> V_45 ) ;
( void ) F_76 ( V_6 , V_43 -> V_45 ) ;
}
if ( V_6 < V_5 )
V_6 = V_5 ;
* V_88 = V_5 ;
* V_89 = V_6 ;
}
static void F_78 ( struct V_46 * V_47 , struct V_28 * V_28 , T_1 V_91 )
{
struct V_43 * V_43 = V_47 -> V_43 ;
T_2 V_40 = V_28 -> V_39 . V_40 ;
V_28 -> V_41 = V_47 -> V_52 -> V_23 ;
if ( F_23 ( V_43 ) )
V_28 -> V_39 . V_40 =
( V_91 << V_43 -> V_44 ) |
( V_40 & ( V_43 -> V_45 - 1 ) ) ;
else
V_28 -> V_39 . V_40 = ( V_91 * V_43 -> V_45 ) +
F_76 ( V_40 , V_43 -> V_45 ) ;
}
static void F_79 ( struct V_46 * V_47 , struct V_28 * V_28 )
{
V_28 -> V_41 = V_47 -> V_92 -> V_23 ;
}
static int F_80 ( struct V_46 * V_47 , struct V_28 * V_28 )
{
return ( V_28 -> V_93 & ( V_94 | V_95 ) ) &&
F_81 ( V_47 -> V_2 ) ;
}
static void F_82 ( struct V_43 * V_43 , struct V_28 * V_28 )
{
struct V_96 * V_97 ;
if ( V_28 -> V_93 & V_33 )
return;
V_97 = F_83 ( V_28 , sizeof( struct V_96 ) ) ;
V_97 -> V_98 = F_84 ( V_43 -> V_99 ) ;
}
static void F_85 ( struct V_46 * V_47 , struct V_28 * V_28 )
{
struct V_43 * V_43 = V_47 -> V_43 ;
unsigned long V_27 ;
if ( ! F_80 ( V_47 , V_28 ) ) {
F_86 ( V_28 ) ;
return;
}
if ( F_87 ( V_47 -> V_2 ) ) {
F_88 ( V_28 ) ;
return;
}
F_64 ( & V_43 -> V_17 , V_27 ) ;
F_89 ( & V_43 -> V_100 , V_28 ) ;
F_65 ( & V_43 -> V_17 , V_27 ) ;
}
static void F_90 ( struct V_46 * V_47 , struct V_28 * V_28 )
{
F_79 ( V_47 , V_28 ) ;
F_85 ( V_47 , V_28 ) ;
}
static void F_91 ( struct V_46 * V_47 , struct V_28 * V_28 ,
T_1 V_91 )
{
F_78 ( V_47 , V_28 , V_91 ) ;
F_85 ( V_47 , V_28 ) ;
}
static void F_92 ( struct V_101 * V_102 )
{
struct V_43 * V_43 = V_102 -> V_47 -> V_43 ;
if ( F_93 ( & V_102 -> V_103 ) ) {
F_94 ( & V_102 -> V_74 , & V_43 -> V_104 ) ;
F_26 ( V_43 ) ;
}
}
static void F_95 ( struct V_101 * V_102 )
{
unsigned long V_27 ;
struct V_43 * V_43 = V_102 -> V_47 -> V_43 ;
F_64 ( & V_43 -> V_17 , V_27 ) ;
F_92 ( V_102 ) ;
F_65 ( & V_43 -> V_17 , V_27 ) ;
}
static void F_96 ( int V_105 , unsigned long V_106 , void * V_65 )
{
struct V_101 * V_102 = V_65 ;
V_102 -> V_107 = V_105 || V_106 ? - V_69 : 0 ;
F_95 ( V_102 ) ;
}
static void F_97 ( struct V_28 * V_28 )
{
struct V_96 * V_97 = F_83 ( V_28 , sizeof( struct V_96 ) ) ;
struct V_101 * V_102 = V_97 -> V_108 ;
V_28 -> V_109 = V_102 -> V_110 ;
V_102 -> V_107 = V_28 -> V_81 ;
F_95 ( V_102 ) ;
}
static void F_98 ( struct V_46 * V_47 , struct V_56 * V_62 )
{
struct V_43 * V_43 = V_47 -> V_43 ;
unsigned long V_27 ;
F_64 ( & V_47 -> V_17 , V_27 ) ;
F_37 ( V_43 , V_62 , & V_47 -> V_85 ) ;
F_65 ( & V_47 -> V_17 , V_27 ) ;
F_26 ( V_43 ) ;
}
static void F_99 ( void * V_65 ,
struct V_56 * V_62 )
{
struct V_111 * V_112 = V_65 ;
struct V_28 * V_28 ;
while ( ( V_28 = F_61 ( & V_62 -> V_64 ) ) ) {
if ( V_28 -> V_93 & ( V_33 | V_94 | V_95 ) )
F_89 ( & V_112 -> V_113 , V_28 ) ;
else {
F_82 ( V_112 -> V_47 -> V_43 , V_28 ) ;
F_89 ( & V_112 -> V_114 , V_28 ) ;
}
}
}
static void F_100 ( struct V_46 * V_47 ,
struct V_56 * V_62 ,
T_1 V_91 )
{
struct V_28 * V_28 ;
struct V_111 V_112 ;
V_112 . V_47 = V_47 ;
F_59 ( & V_112 . V_113 ) ;
F_59 ( & V_112 . V_114 ) ;
F_34 ( V_47 -> V_43 , F_99 ,
& V_112 , V_62 ) ;
while ( ( V_28 = F_61 ( & V_112 . V_113 ) ) )
F_101 ( V_47 , V_28 ) ;
while ( ( V_28 = F_61 ( & V_112 . V_114 ) ) )
F_91 ( V_112 . V_47 , V_28 , V_91 ) ;
}
static void F_102 ( struct V_101 * V_102 )
{
F_42 ( V_102 -> V_47 -> V_43 , V_102 -> V_62 ) ;
F_53 ( & V_102 -> V_74 ) ;
F_103 ( V_102 , V_102 -> V_47 -> V_43 -> V_115 ) ;
}
static void F_104 ( struct V_101 * V_102 )
{
struct V_46 * V_47 = V_102 -> V_47 ;
struct V_43 * V_43 = V_47 -> V_43 ;
struct V_28 * V_28 = V_102 -> V_28 ;
int V_58 ;
if ( V_102 -> V_107 ) {
F_42 ( V_43 , V_102 -> V_62 ) ;
goto V_116;
}
V_58 = F_105 ( V_47 -> V_2 , V_102 -> V_117 , V_102 -> V_118 ) ;
if ( V_58 ) {
F_106 ( V_43 , L_1 , V_58 ) ;
F_42 ( V_43 , V_102 -> V_62 ) ;
goto V_116;
}
if ( V_28 ) {
F_100 ( V_47 , V_102 -> V_62 , V_102 -> V_118 ) ;
F_62 ( V_28 ) ;
} else {
F_82 ( V_47 -> V_43 , V_102 -> V_62 -> V_119 ) ;
F_91 ( V_47 , V_102 -> V_62 -> V_119 , V_102 -> V_118 ) ;
F_100 ( V_47 , V_102 -> V_62 , V_102 -> V_118 ) ;
}
V_116:
F_53 ( & V_102 -> V_74 ) ;
F_103 ( V_102 , V_43 -> V_115 ) ;
}
static void F_107 ( struct V_101 * V_102 )
{
struct V_46 * V_47 = V_102 -> V_47 ;
if ( V_102 -> V_62 )
F_98 ( V_47 , V_102 -> V_62 ) ;
F_103 ( V_102 , V_47 -> V_43 -> V_115 ) ;
}
static void F_108 ( struct V_101 * V_102 )
{
F_88 ( V_102 -> V_28 ) ;
F_107 ( V_102 ) ;
}
static void F_109 ( struct V_101 * V_102 )
{
F_62 ( V_102 -> V_28 ) ;
F_107 ( V_102 ) ;
}
static void F_110 ( struct V_101 * V_102 )
{
int V_58 ;
struct V_46 * V_47 = V_102 -> V_47 ;
V_58 = F_111 ( V_47 -> V_2 , V_102 -> V_62 -> V_8 . V_12 , V_102 -> V_62 -> V_8 . V_13 ) ;
if ( V_58 ) {
F_106 ( V_47 -> V_43 , L_2 , V_58 ) ;
F_88 ( V_102 -> V_28 ) ;
} else
F_62 ( V_102 -> V_28 ) ;
F_98 ( V_47 , V_102 -> V_62 ) ;
F_103 ( V_102 , V_47 -> V_43 -> V_115 ) ;
}
static int F_112 ( struct V_101 * V_102 )
{
int V_58 ;
bool V_120 = true ;
struct V_46 * V_47 = V_102 -> V_47 ;
struct V_43 * V_43 = V_47 -> V_43 ;
T_1 V_5 = V_102 -> V_118 , V_6 , V_89 = V_102 -> V_118 + V_102 -> V_121 - V_102 -> V_117 ;
while ( V_5 != V_89 ) {
for (; V_5 < V_89 ; V_5 ++ ) {
V_58 = F_113 ( V_43 -> V_122 , V_5 , & V_120 ) ;
if ( V_58 )
return V_58 ;
if ( ! V_120 )
break;
}
if ( V_5 == V_89 )
break;
for ( V_6 = V_5 + 1 ; V_6 != V_89 ; V_6 ++ ) {
V_58 = F_113 ( V_43 -> V_122 , V_6 , & V_120 ) ;
if ( V_58 )
return V_58 ;
if ( V_120 )
break;
}
V_58 = F_25 ( V_47 , V_5 , V_6 , V_102 -> V_28 ) ;
if ( V_58 )
return V_58 ;
V_5 = V_6 ;
}
return 0 ;
}
static void F_114 ( struct V_101 * V_102 )
{
int V_58 ;
struct V_46 * V_47 = V_102 -> V_47 ;
struct V_43 * V_43 = V_47 -> V_43 ;
V_58 = F_111 ( V_47 -> V_2 , V_102 -> V_117 , V_102 -> V_121 ) ;
if ( V_58 )
F_106 ( V_43 , L_2 , V_58 ) ;
else if ( V_102 -> V_123 )
V_58 = F_112 ( V_102 ) ;
else
V_58 = F_25 ( V_47 , V_102 -> V_118 , V_102 -> V_118 + ( V_102 -> V_121 - V_102 -> V_117 ) , V_102 -> V_28 ) ;
V_102 -> V_28 -> V_81 = V_58 ;
F_62 ( V_102 -> V_28 ) ;
F_98 ( V_47 , V_102 -> V_62 ) ;
F_103 ( V_102 , V_43 -> V_115 ) ;
}
static void F_115 ( struct V_43 * V_43 , struct V_82 * V_124 ,
T_4 * F_35 )
{
unsigned long V_27 ;
struct V_82 V_125 ;
struct V_101 * V_102 , * V_77 ;
F_47 ( & V_125 ) ;
F_64 ( & V_43 -> V_17 , V_27 ) ;
F_67 ( V_124 , & V_125 ) ;
F_65 ( & V_43 -> V_17 , V_27 ) ;
F_68 ( V_102 , V_77 , & V_125 , V_74 )
( * F_35 ) ( V_102 ) ;
}
static int F_116 ( struct V_43 * V_43 , struct V_28 * V_28 )
{
return V_28 -> V_39 . V_42 ==
( V_43 -> V_45 << V_90 ) ;
}
static int F_117 ( struct V_43 * V_43 , struct V_28 * V_28 )
{
return ( F_118 ( V_28 ) == V_126 ) &&
F_116 ( V_43 , V_28 ) ;
}
static void F_119 ( struct V_28 * V_28 , T_5 * * V_127 ,
T_5 * F_35 )
{
* V_127 = V_28 -> V_109 ;
V_28 -> V_109 = F_35 ;
}
static int F_120 ( struct V_43 * V_43 )
{
if ( V_43 -> V_128 )
return 0 ;
V_43 -> V_128 = F_121 ( V_43 -> V_115 , V_129 ) ;
return V_43 -> V_128 ? 0 : - V_38 ;
}
static struct V_101 * F_122 ( struct V_43 * V_43 )
{
struct V_101 * V_102 = V_43 -> V_128 ;
F_49 ( ! V_43 -> V_128 ) ;
memset ( V_102 , 0 , sizeof( struct V_101 ) ) ;
F_47 ( & V_102 -> V_74 ) ;
V_102 -> V_28 = NULL ;
V_43 -> V_128 = NULL ;
return V_102 ;
}
static void F_123 ( struct V_46 * V_47 , struct V_101 * V_102 ,
T_2 V_88 , T_2 V_89 )
{
int V_58 ;
struct V_130 V_131 ;
V_131 . V_23 = V_47 -> V_52 -> V_23 ;
V_131 . V_24 = V_88 ;
V_131 . V_132 = V_89 - V_88 ;
V_58 = F_124 ( V_47 -> V_43 -> V_133 , 1 , & V_131 , 0 , F_96 , V_102 ) ;
if ( V_58 < 0 ) {
F_125 ( L_3 ) ;
F_96 ( 1 , 1 , V_102 ) ;
}
}
static void F_126 ( struct V_46 * V_47 , struct V_28 * V_28 ,
T_1 V_134 ,
struct V_101 * V_102 )
{
struct V_43 * V_43 = V_47 -> V_43 ;
struct V_96 * V_97 = F_83 ( V_28 , sizeof( struct V_96 ) ) ;
V_97 -> V_108 = V_102 ;
V_102 -> V_28 = V_28 ;
F_119 ( V_28 , & V_102 -> V_110 , F_97 ) ;
F_82 ( V_43 , V_28 ) ;
F_91 ( V_47 , V_28 , V_134 ) ;
}
static void F_127 ( struct V_46 * V_47 , T_1 V_135 ,
struct V_136 * V_137 , T_1 V_138 ,
T_1 V_139 ,
struct V_56 * V_62 , struct V_28 * V_28 ,
T_2 V_51 )
{
int V_58 ;
struct V_43 * V_43 = V_47 -> V_43 ;
struct V_101 * V_102 = F_122 ( V_43 ) ;
V_102 -> V_47 = V_47 ;
V_102 -> V_117 = V_135 ;
V_102 -> V_121 = V_135 + 1u ;
V_102 -> V_118 = V_139 ;
V_102 -> V_62 = V_62 ;
F_128 ( & V_102 -> V_103 , 3 ) ;
if ( ! F_129 ( V_43 -> V_140 , & V_102 -> V_74 ) )
F_95 ( V_102 ) ;
if ( F_117 ( V_43 , V_28 ) )
F_126 ( V_47 , V_28 , V_139 , V_102 ) ;
else {
struct V_130 V_141 , V_131 ;
V_141 . V_23 = V_137 -> V_23 ;
V_141 . V_24 = V_138 * V_43 -> V_45 ;
V_141 . V_132 = V_51 ;
V_131 . V_23 = V_47 -> V_52 -> V_23 ;
V_131 . V_24 = V_139 * V_43 -> V_45 ;
V_131 . V_132 = V_51 ;
V_58 = F_130 ( V_43 -> V_133 , & V_141 , 1 , & V_131 ,
0 , F_96 , V_102 ) ;
if ( V_58 < 0 ) {
F_125 ( L_4 ) ;
F_96 ( 1 , 1 , V_102 ) ;
}
if ( V_51 < V_43 -> V_45 && V_43 -> V_142 . V_143 ) {
F_131 ( & V_102 -> V_103 ) ;
F_123 ( V_47 , V_102 ,
V_139 * V_43 -> V_45 + V_51 ,
( V_139 + 1 ) * V_43 -> V_45 ) ;
}
}
F_95 ( V_102 ) ;
}
static void F_132 ( struct V_46 * V_47 , T_1 V_135 ,
T_1 V_138 , T_1 V_139 ,
struct V_56 * V_62 , struct V_28 * V_28 )
{
F_127 ( V_47 , V_135 , V_47 -> V_52 ,
V_138 , V_139 , V_62 , V_28 ,
V_47 -> V_43 -> V_45 ) ;
}
static void F_133 ( struct V_46 * V_47 , T_1 V_135 ,
T_1 V_118 , struct V_56 * V_62 ,
struct V_28 * V_28 )
{
struct V_43 * V_43 = V_47 -> V_43 ;
struct V_101 * V_102 = F_122 ( V_43 ) ;
F_128 ( & V_102 -> V_103 , 1 ) ;
V_102 -> V_47 = V_47 ;
V_102 -> V_117 = V_135 ;
V_102 -> V_121 = V_135 + 1u ;
V_102 -> V_118 = V_118 ;
V_102 -> V_62 = V_62 ;
if ( V_43 -> V_142 . V_143 ) {
if ( F_117 ( V_43 , V_28 ) )
F_126 ( V_47 , V_28 , V_118 , V_102 ) ;
else
F_123 ( V_47 , V_102 , V_118 * V_43 -> V_45 ,
( V_118 + 1 ) * V_43 -> V_45 ) ;
} else
F_104 ( V_102 ) ;
}
static void F_134 ( struct V_46 * V_47 , T_1 V_135 ,
T_1 V_139 ,
struct V_56 * V_62 , struct V_28 * V_28 )
{
struct V_43 * V_43 = V_47 -> V_43 ;
T_2 V_144 = V_135 * V_43 -> V_45 ;
T_2 V_145 = ( V_135 + 1 ) * V_43 -> V_45 ;
if ( V_145 <= V_47 -> V_146 )
F_127 ( V_47 , V_135 , V_47 -> V_92 ,
V_135 , V_139 , V_62 , V_28 ,
V_43 -> V_45 ) ;
else if ( V_144 < V_47 -> V_146 )
F_127 ( V_47 , V_135 , V_47 -> V_92 ,
V_135 , V_139 , V_62 , V_28 ,
V_47 -> V_146 - V_144 ) ;
else
F_133 ( V_47 , V_135 , V_139 , V_62 , V_28 ) ;
}
static void F_135 ( struct V_43 * V_43 )
{
int V_58 ;
T_1 V_147 ;
if ( F_136 ( V_43 ) != V_148 )
return;
V_58 = F_137 ( V_43 -> V_122 , & V_147 ) ;
if ( V_58 )
return;
if ( V_147 )
F_138 ( V_43 , V_149 ) ;
}
static int F_139 ( struct V_43 * V_43 )
{
int V_58 ;
if ( F_136 ( V_43 ) >= V_150 )
return - V_151 ;
V_58 = F_140 ( V_43 -> V_122 ) ;
if ( V_58 )
F_106 ( V_43 , L_5 , V_58 ) ;
else
F_135 ( V_43 ) ;
return V_58 ;
}
static void F_141 ( struct V_43 * V_43 , T_1 V_152 )
{
unsigned long V_27 ;
if ( V_152 <= V_43 -> V_153 && ! V_43 -> V_154 ) {
F_142 ( L_6 ,
F_143 ( V_43 -> V_78 ) ) ;
F_64 ( & V_43 -> V_17 , V_27 ) ;
V_43 -> V_154 = true ;
F_65 ( & V_43 -> V_17 , V_27 ) ;
F_144 ( V_43 -> V_155 -> V_156 ) ;
}
}
static int F_145 ( struct V_46 * V_47 , T_1 * V_157 )
{
int V_58 ;
T_1 V_152 ;
struct V_43 * V_43 = V_47 -> V_43 ;
if ( F_146 ( F_136 ( V_43 ) != V_149 ) )
return - V_151 ;
V_58 = F_137 ( V_43 -> V_122 , & V_152 ) ;
if ( V_58 ) {
F_106 ( V_43 , L_7 , V_58 ) ;
return V_58 ;
}
F_141 ( V_43 , V_152 ) ;
if ( ! V_152 ) {
V_58 = F_139 ( V_43 ) ;
if ( V_58 )
return V_58 ;
V_58 = F_137 ( V_43 -> V_122 , & V_152 ) ;
if ( V_58 ) {
F_106 ( V_43 , L_7 , V_58 ) ;
return V_58 ;
}
if ( ! V_152 ) {
F_138 ( V_43 , V_148 ) ;
return - V_68 ;
}
}
V_58 = F_147 ( V_43 -> V_122 , V_157 ) ;
if ( V_58 ) {
F_106 ( V_43 , L_8 , V_58 ) ;
return V_58 ;
}
return 0 ;
}
static void F_148 ( struct V_28 * V_28 )
{
struct V_96 * V_97 = F_83 ( V_28 , sizeof( struct V_96 ) ) ;
struct V_46 * V_47 = V_97 -> V_47 ;
unsigned long V_27 ;
F_64 ( & V_47 -> V_17 , V_27 ) ;
F_89 ( & V_47 -> V_86 , V_28 ) ;
F_65 ( & V_47 -> V_17 , V_27 ) ;
}
static int F_149 ( struct V_43 * V_43 )
{
enum V_158 V_102 = F_136 ( V_43 ) ;
switch ( V_102 ) {
case V_149 :
F_125 ( L_9 ) ;
return - V_69 ;
case V_148 :
return V_43 -> V_142 . V_159 ? - V_68 : 0 ;
case V_150 :
case V_160 :
return - V_69 ;
default:
F_125 ( L_10 ) ;
return - V_69 ;
}
}
static void F_150 ( struct V_43 * V_43 , struct V_28 * V_28 )
{
int error = F_149 ( V_43 ) ;
if ( error ) {
V_28 -> V_81 = error ;
F_62 ( V_28 ) ;
} else
F_148 ( V_28 ) ;
}
static void F_151 ( struct V_43 * V_43 , struct V_56 * V_62 )
{
struct V_28 * V_28 ;
struct V_63 V_64 ;
int error ;
error = F_149 ( V_43 ) ;
if ( error ) {
F_39 ( V_43 , V_62 , error ) ;
return;
}
F_59 ( & V_64 ) ;
F_32 ( V_43 , V_62 , & V_64 ) ;
while ( ( V_28 = F_61 ( & V_64 ) ) )
F_148 ( V_28 ) ;
}
static void F_152 ( struct V_46 * V_47 ,
struct V_56 * V_161 )
{
struct V_43 * V_43 = V_47 -> V_43 ;
struct V_101 * V_102 = F_122 ( V_43 ) ;
V_102 -> V_47 = V_47 ;
V_102 -> V_117 = V_161 -> V_8 . V_12 ;
V_102 -> V_121 = V_161 -> V_8 . V_13 ;
V_102 -> V_62 = V_161 ;
V_102 -> V_28 = V_161 -> V_119 ;
if ( ! F_129 ( V_43 -> V_99 , & V_102 -> V_74 ) )
V_43 -> V_162 ( V_102 ) ;
}
static inline void F_153 ( struct V_28 * V_28 )
{
V_28 -> V_163 |= ( 1 << V_164 ) ;
F_154 () ;
F_131 ( & V_28 -> V_165 ) ;
}
static void F_155 ( struct V_46 * V_47 , T_1 V_88 , T_1 V_89 ,
struct V_28 * V_28 )
{
struct V_43 * V_43 = V_47 -> V_43 ;
int V_58 ;
bool V_123 ;
struct V_7 V_166 ;
struct V_56 * V_167 ;
struct V_101 * V_102 ;
T_1 V_117 , V_121 , V_134 ;
while ( V_88 != V_89 ) {
V_58 = F_120 ( V_43 ) ;
if ( V_58 )
return;
V_58 = F_156 ( V_47 -> V_2 , V_88 , V_89 , & V_117 , & V_121 ,
& V_134 , & V_123 ) ;
if ( V_58 )
break;
F_1 ( V_47 -> V_2 , V_14 , V_134 , V_134 + ( V_121 - V_117 ) , & V_166 ) ;
if ( F_28 ( V_47 -> V_43 , & V_166 , NULL , & V_167 ) ) {
V_88 = V_121 ;
continue;
}
V_102 = F_122 ( V_43 ) ;
V_102 -> V_47 = V_47 ;
V_102 -> V_123 = V_123 ;
V_102 -> V_117 = V_117 ;
V_102 -> V_121 = V_121 ;
V_102 -> V_118 = V_134 ;
V_102 -> V_62 = V_167 ;
V_102 -> V_28 = V_28 ;
F_153 ( V_28 ) ;
if ( ! F_129 ( V_43 -> V_99 , & V_102 -> V_74 ) )
V_43 -> V_162 ( V_102 ) ;
V_88 = V_121 ;
}
}
static void F_157 ( struct V_46 * V_47 , struct V_56 * V_161 )
{
struct V_28 * V_28 = V_161 -> V_119 ;
struct V_96 * V_97 = F_83 ( V_28 , sizeof( struct V_96 ) ) ;
V_97 -> V_62 = V_161 ;
F_155 ( V_47 , V_161 -> V_8 . V_12 , V_161 -> V_8 . V_13 , V_28 ) ;
F_62 ( V_28 ) ;
}
static void F_158 ( struct V_46 * V_47 , struct V_28 * V_28 )
{
T_1 V_88 , V_89 ;
struct V_7 V_168 ;
struct V_56 * V_161 ;
F_77 ( V_47 , V_28 , & V_88 , & V_89 ) ;
if ( V_88 == V_89 ) {
F_62 ( V_28 ) ;
return;
}
F_1 ( V_47 -> V_2 , V_10 , V_88 , V_89 , & V_168 ) ;
if ( F_28 ( V_47 -> V_43 , & V_168 , V_28 , & V_161 ) )
return;
V_47 -> V_43 -> V_169 ( V_47 , V_161 ) ;
}
static void F_159 ( struct V_46 * V_47 , struct V_28 * V_28 , T_1 V_91 ,
struct V_7 * V_8 ,
struct V_170 * V_171 ,
struct V_56 * V_62 )
{
int V_58 ;
T_1 V_118 ;
struct V_43 * V_43 = V_47 -> V_43 ;
V_58 = F_145 ( V_47 , & V_118 ) ;
switch ( V_58 ) {
case 0 :
F_132 ( V_47 , V_91 , V_171 -> V_91 ,
V_118 , V_62 , V_28 ) ;
break;
case - V_68 :
F_151 ( V_43 , V_62 ) ;
break;
default:
F_125 ( L_11 ,
V_172 , V_58 ) ;
F_42 ( V_43 , V_62 ) ;
break;
}
}
static void F_160 ( void * V_65 ,
struct V_56 * V_62 )
{
struct V_111 * V_112 = V_65 ;
struct V_28 * V_28 ;
while ( ( V_28 = F_61 ( & V_62 -> V_64 ) ) ) {
if ( ( F_118 ( V_28 ) == V_126 ) ||
( V_28 -> V_93 & ( V_33 | V_94 | V_95 ) ) )
F_89 ( & V_112 -> V_113 , V_28 ) ;
else {
struct V_96 * V_97 = F_83 ( V_28 , sizeof( struct V_96 ) ) ; ;
V_97 -> V_173 = F_84 ( V_112 -> V_47 -> V_43 -> V_140 ) ;
F_82 ( V_112 -> V_47 -> V_43 , V_28 ) ;
F_89 ( & V_112 -> V_114 , V_28 ) ;
}
}
}
static void F_161 ( struct V_46 * V_47 ,
struct V_56 * V_62 ,
T_1 V_91 )
{
struct V_28 * V_28 ;
struct V_111 V_112 ;
V_112 . V_47 = V_47 ;
F_59 ( & V_112 . V_113 ) ;
F_59 ( & V_112 . V_114 ) ;
F_34 ( V_47 -> V_43 , F_160 ,
& V_112 , V_62 ) ;
while ( ( V_28 = F_61 ( & V_112 . V_113 ) ) )
F_101 ( V_47 , V_28 ) ;
while ( ( V_28 = F_61 ( & V_112 . V_114 ) ) )
F_91 ( V_47 , V_28 , V_91 ) ;
}
static void F_162 ( struct V_46 * V_47 , struct V_28 * V_28 ,
T_1 V_91 ,
struct V_170 * V_171 ,
struct V_56 * V_161 )
{
struct V_56 * V_167 ;
struct V_43 * V_43 = V_47 -> V_43 ;
struct V_7 V_8 ;
F_3 ( V_47 -> V_2 , V_171 -> V_91 , & V_8 ) ;
if ( F_28 ( V_43 , & V_8 , V_28 , & V_167 ) ) {
F_98 ( V_47 , V_161 ) ;
return;
}
if ( F_118 ( V_28 ) == V_126 && V_28 -> V_39 . V_42 ) {
F_159 ( V_47 , V_28 , V_91 , & V_8 , V_171 , V_167 ) ;
F_98 ( V_47 , V_161 ) ;
} else {
struct V_96 * V_97 = F_83 ( V_28 , sizeof( struct V_96 ) ) ;
V_97 -> V_173 = F_84 ( V_43 -> V_140 ) ;
F_82 ( V_43 , V_28 ) ;
F_91 ( V_47 , V_28 , V_171 -> V_91 ) ;
F_161 ( V_47 , V_167 , V_171 -> V_91 ) ;
F_161 ( V_47 , V_161 , V_171 -> V_91 ) ;
}
}
static void F_163 ( struct V_46 * V_47 , struct V_28 * V_28 , T_1 V_91 ,
struct V_56 * V_62 )
{
int V_58 ;
T_1 V_118 ;
struct V_43 * V_43 = V_47 -> V_43 ;
if ( ! V_28 -> V_39 . V_42 ) {
F_82 ( V_43 , V_28 ) ;
F_98 ( V_47 , V_62 ) ;
F_91 ( V_47 , V_28 , 0 ) ;
return;
}
if ( F_118 ( V_28 ) == V_174 ) {
F_164 ( V_28 ) ;
F_98 ( V_47 , V_62 ) ;
F_62 ( V_28 ) ;
return;
}
V_58 = F_145 ( V_47 , & V_118 ) ;
switch ( V_58 ) {
case 0 :
if ( V_47 -> V_92 )
F_134 ( V_47 , V_91 , V_118 , V_62 , V_28 ) ;
else
F_133 ( V_47 , V_91 , V_118 , V_62 , V_28 ) ;
break;
case - V_68 :
F_151 ( V_43 , V_62 ) ;
break;
default:
F_125 ( L_11 ,
V_172 , V_58 ) ;
F_42 ( V_43 , V_62 ) ;
break;
}
}
static void F_165 ( struct V_46 * V_47 , struct V_56 * V_62 )
{
int V_58 ;
struct V_43 * V_43 = V_47 -> V_43 ;
struct V_28 * V_28 = V_62 -> V_119 ;
T_1 V_91 = F_75 ( V_47 , V_28 ) ;
struct V_170 V_171 ;
if ( V_47 -> V_175 ) {
F_44 ( V_43 , V_62 ) ;
return;
}
V_58 = F_166 ( V_47 -> V_2 , V_91 , 1 , & V_171 ) ;
switch ( V_58 ) {
case 0 :
if ( V_171 . V_176 )
F_162 ( V_47 , V_28 , V_91 , & V_171 , V_62 ) ;
else {
F_82 ( V_43 , V_28 ) ;
F_91 ( V_47 , V_28 , V_171 . V_91 ) ;
F_100 ( V_47 , V_62 , V_171 . V_91 ) ;
}
break;
case - V_177 :
if ( F_118 ( V_28 ) == V_174 && V_47 -> V_92 ) {
F_82 ( V_43 , V_28 ) ;
F_98 ( V_47 , V_62 ) ;
if ( F_167 ( V_28 ) <= V_47 -> V_146 )
F_90 ( V_47 , V_28 ) ;
else if ( V_28 -> V_39 . V_40 < V_47 -> V_146 ) {
F_164 ( V_28 ) ;
V_28 -> V_39 . V_42 = ( V_47 -> V_146 - V_28 -> V_39 . V_40 ) << V_90 ;
F_90 ( V_47 , V_28 ) ;
} else {
F_164 ( V_28 ) ;
F_62 ( V_28 ) ;
}
} else
F_163 ( V_47 , V_28 , V_91 , V_62 ) ;
break;
default:
F_125 ( L_12 ,
V_172 , V_58 ) ;
F_98 ( V_47 , V_62 ) ;
F_88 ( V_28 ) ;
break;
}
}
static void F_168 ( struct V_46 * V_47 , struct V_28 * V_28 )
{
struct V_43 * V_43 = V_47 -> V_43 ;
T_1 V_91 = F_75 ( V_47 , V_28 ) ;
struct V_56 * V_62 ;
struct V_7 V_8 ;
F_4 ( V_47 -> V_2 , V_91 , & V_8 ) ;
if ( F_28 ( V_43 , & V_8 , V_28 , & V_62 ) )
return;
F_165 ( V_47 , V_62 ) ;
}
static void F_169 ( struct V_46 * V_47 , struct V_28 * V_28 ,
struct V_56 * V_62 )
{
int V_58 ;
int V_178 = F_118 ( V_28 ) ;
T_1 V_91 = F_75 ( V_47 , V_28 ) ;
struct V_170 V_171 ;
V_58 = F_166 ( V_47 -> V_2 , V_91 , 1 , & V_171 ) ;
switch ( V_58 ) {
case 0 :
if ( V_171 . V_176 && ( V_178 == V_126 ) && V_28 -> V_39 . V_42 ) {
F_150 ( V_47 -> V_43 , V_28 ) ;
if ( V_62 )
F_98 ( V_47 , V_62 ) ;
} else {
F_82 ( V_47 -> V_43 , V_28 ) ;
F_91 ( V_47 , V_28 , V_171 . V_91 ) ;
if ( V_62 )
F_100 ( V_47 , V_62 , V_171 . V_91 ) ;
}
break;
case - V_177 :
if ( V_62 )
F_98 ( V_47 , V_62 ) ;
if ( V_178 != V_174 ) {
F_150 ( V_47 -> V_43 , V_28 ) ;
break;
}
if ( V_47 -> V_92 ) {
F_82 ( V_47 -> V_43 , V_28 ) ;
F_90 ( V_47 , V_28 ) ;
break;
}
F_164 ( V_28 ) ;
F_62 ( V_28 ) ;
break;
default:
F_125 ( L_12 ,
V_172 , V_58 ) ;
if ( V_62 )
F_98 ( V_47 , V_62 ) ;
F_88 ( V_28 ) ;
break;
}
}
static void F_170 ( struct V_46 * V_47 , struct V_28 * V_28 )
{
F_169 ( V_47 , V_28 , NULL ) ;
}
static void F_171 ( struct V_46 * V_47 , struct V_56 * V_62 )
{
F_169 ( V_47 , V_62 -> V_119 , V_62 ) ;
}
static void F_172 ( struct V_46 * V_47 , struct V_28 * V_28 )
{
F_62 ( V_28 ) ;
}
static void F_173 ( struct V_46 * V_47 , struct V_28 * V_28 )
{
F_88 ( V_28 ) ;
}
static void F_174 ( struct V_46 * V_47 , struct V_56 * V_62 )
{
F_43 ( V_47 -> V_43 , V_62 ) ;
}
static void F_175 ( struct V_46 * V_47 , struct V_56 * V_62 )
{
F_42 ( V_47 -> V_43 , V_62 ) ;
}
static int F_176 ( struct V_43 * V_43 )
{
return ! F_177 ( V_20 , V_43 -> V_179 ,
V_43 -> V_179 + V_180 ) ;
}
static void F_178 ( struct V_46 * V_47 , struct V_28 * V_28 )
{
struct V_181 * * V_182 , * V_183 ;
struct V_96 * V_184 ;
T_2 V_40 = V_28 -> V_39 . V_40 ;
V_182 = & V_47 -> V_185 . V_181 ;
V_183 = NULL ;
while ( * V_182 ) {
V_183 = * V_182 ;
V_184 = F_179 ( V_183 ) ;
if ( V_40 < F_180 ( V_184 ) -> V_39 . V_40 )
V_182 = & ( * V_182 ) -> V_186 ;
else
V_182 = & ( * V_182 ) -> V_187 ;
}
V_184 = F_83 ( V_28 , sizeof( struct V_96 ) ) ;
F_181 ( & V_184 -> V_181 , V_183 , V_182 ) ;
F_182 ( & V_184 -> V_181 , & V_47 -> V_185 ) ;
}
static void F_183 ( struct V_46 * V_47 )
{
struct V_181 * V_188 ;
struct V_96 * V_184 ;
struct V_28 * V_28 ;
for ( V_188 = F_184 ( & V_47 -> V_185 ) ; V_188 ; V_188 = F_185 ( V_188 ) ) {
V_184 = F_179 ( V_188 ) ;
V_28 = F_180 ( V_184 ) ;
F_89 ( & V_47 -> V_85 , V_28 ) ;
F_186 ( & V_184 -> V_181 , & V_47 -> V_185 ) ;
}
F_146 ( ! F_187 ( & V_47 -> V_185 ) ) ;
}
static void F_188 ( struct V_46 * V_47 )
{
struct V_28 * V_28 ;
struct V_63 V_64 ;
F_59 ( & V_64 ) ;
F_58 ( & V_64 , & V_47 -> V_85 ) ;
F_59 ( & V_47 -> V_85 ) ;
while ( ( V_28 = F_61 ( & V_64 ) ) )
F_178 ( V_47 , V_28 ) ;
F_183 ( V_47 ) ;
}
static void F_189 ( struct V_46 * V_47 )
{
struct V_43 * V_43 = V_47 -> V_43 ;
unsigned long V_27 ;
struct V_28 * V_28 ;
struct V_63 V_64 ;
struct V_189 V_190 ;
unsigned V_132 = 0 ;
if ( V_47 -> V_175 ) {
F_63 ( V_47 , & V_47 -> V_85 , V_70 ) ;
return;
}
F_59 ( & V_64 ) ;
F_64 ( & V_47 -> V_17 , V_27 ) ;
if ( F_190 ( & V_47 -> V_85 ) ) {
F_65 ( & V_47 -> V_17 , V_27 ) ;
return;
}
F_188 ( V_47 ) ;
F_58 ( & V_64 , & V_47 -> V_85 ) ;
F_59 ( & V_47 -> V_85 ) ;
F_65 ( & V_47 -> V_17 , V_27 ) ;
F_191 ( & V_190 ) ;
while ( ( V_28 = F_61 ( & V_64 ) ) ) {
if ( F_120 ( V_43 ) ) {
F_64 ( & V_47 -> V_17 , V_27 ) ;
F_89 ( & V_47 -> V_85 , V_28 ) ;
F_58 ( & V_47 -> V_85 , & V_64 ) ;
F_65 ( & V_47 -> V_17 , V_27 ) ;
break;
}
if ( V_28 -> V_93 & V_33 )
V_43 -> V_191 ( V_47 , V_28 ) ;
else
V_43 -> F_168 ( V_47 , V_28 ) ;
if ( ( V_132 ++ & 127 ) == 0 ) {
F_8 ( & V_43 -> V_15 ) ;
F_192 ( V_43 -> V_122 ) ;
}
}
F_193 ( & V_190 ) ;
}
static int F_194 ( const void * V_192 , const void * V_193 )
{
struct V_56 * V_194 = * ( (struct V_56 * * ) V_192 ) ;
struct V_56 * V_195 = * ( (struct V_56 * * ) V_193 ) ;
F_49 ( ! V_194 -> V_119 ) ;
F_49 ( ! V_195 -> V_119 ) ;
if ( V_194 -> V_119 -> V_39 . V_40 < V_195 -> V_119 -> V_39 . V_40 )
return - 1 ;
if ( V_194 -> V_119 -> V_39 . V_40 > V_195 -> V_119 -> V_39 . V_40 )
return 1 ;
return 0 ;
}
static unsigned F_195 ( struct V_43 * V_43 , struct V_82 * V_83 )
{
unsigned V_132 = 0 ;
struct V_56 * V_62 , * V_77 ;
F_68 (cell, tmp, cells, user_list) {
if ( V_132 >= V_196 )
break;
V_43 -> V_197 [ V_132 ++ ] = V_62 ;
F_53 ( & V_62 -> V_198 ) ;
}
F_196 ( V_43 -> V_197 , V_132 , sizeof( V_62 ) , F_194 , NULL ) ;
return V_132 ;
}
static void F_197 ( struct V_46 * V_47 )
{
struct V_43 * V_43 = V_47 -> V_43 ;
unsigned long V_27 ;
struct V_82 V_83 ;
struct V_56 * V_62 ;
unsigned V_199 , V_200 , V_132 ;
F_47 ( & V_83 ) ;
F_64 ( & V_47 -> V_17 , V_27 ) ;
F_67 ( & V_47 -> V_84 , & V_83 ) ;
F_65 ( & V_47 -> V_17 , V_27 ) ;
if ( F_198 ( & V_83 ) )
return;
do {
V_132 = F_195 ( V_47 -> V_43 , & V_83 ) ;
for ( V_199 = 0 ; V_199 < V_132 ; V_199 ++ ) {
V_62 = V_43 -> V_197 [ V_199 ] ;
F_49 ( ! V_62 -> V_119 ) ;
if ( F_120 ( V_43 ) ) {
for ( V_200 = V_199 ; V_200 < V_132 ; V_200 ++ )
F_51 ( & V_43 -> V_197 [ V_200 ] -> V_198 , & V_83 ) ;
F_64 ( & V_47 -> V_17 , V_27 ) ;
F_199 ( & V_83 , & V_47 -> V_84 ) ;
F_65 ( & V_47 -> V_17 , V_27 ) ;
return;
}
if ( V_62 -> V_119 -> V_93 & V_33 )
V_43 -> V_169 ( V_47 , V_62 ) ;
else
V_43 -> F_165 ( V_47 , V_62 ) ;
}
} while ( ! F_198 ( & V_83 ) );
}
static struct V_46 * F_200 ( struct V_43 * V_43 )
{
struct V_46 * V_47 = NULL ;
F_71 () ;
if ( ! F_198 ( & V_43 -> V_201 ) ) {
V_47 = F_201 ( V_43 -> V_201 . V_202 , struct V_46 , V_74 ) ;
F_202 ( V_47 ) ;
}
F_73 () ;
return V_47 ;
}
static struct V_46 * F_203 ( struct V_43 * V_43 , struct V_46 * V_47 )
{
struct V_46 * V_203 = V_47 ;
F_71 () ;
F_204 (tc, &pool->active_thins, list) {
F_202 ( V_47 ) ;
F_205 ( V_203 ) ;
F_73 () ;
return V_47 ;
}
F_205 ( V_203 ) ;
F_73 () ;
return NULL ;
}
static void F_206 ( struct V_43 * V_43 )
{
unsigned long V_27 ;
struct V_28 * V_28 ;
struct V_63 V_64 ;
struct V_46 * V_47 ;
V_47 = F_200 ( V_43 ) ;
while ( V_47 ) {
F_197 ( V_47 ) ;
F_189 ( V_47 ) ;
V_47 = F_203 ( V_43 , V_47 ) ;
}
F_59 ( & V_64 ) ;
F_64 ( & V_43 -> V_17 , V_27 ) ;
F_58 ( & V_64 , & V_43 -> V_100 ) ;
F_59 ( & V_43 -> V_100 ) ;
F_65 ( & V_43 -> V_17 , V_27 ) ;
if ( F_190 ( & V_64 ) &&
! ( F_207 ( V_43 -> V_122 ) && F_176 ( V_43 ) ) )
return;
if ( F_139 ( V_43 ) ) {
while ( ( V_28 = F_61 ( & V_64 ) ) )
F_88 ( V_28 ) ;
return;
}
V_43 -> V_179 = V_20 ;
while ( ( V_28 = F_61 ( & V_64 ) ) )
F_86 ( V_28 ) ;
}
static void F_208 ( struct V_204 * V_205 )
{
struct V_43 * V_43 = F_209 ( V_205 , struct V_43 , V_55 ) ;
F_7 ( & V_43 -> V_15 ) ;
F_192 ( V_43 -> V_122 ) ;
F_8 ( & V_43 -> V_15 ) ;
F_115 ( V_43 , & V_43 -> V_104 , & V_43 -> F_104 ) ;
F_8 ( & V_43 -> V_15 ) ;
F_115 ( V_43 , & V_43 -> V_206 , & V_43 -> V_162 ) ;
F_8 ( & V_43 -> V_15 ) ;
F_206 ( V_43 ) ;
F_10 ( & V_43 -> V_15 ) ;
}
static void F_210 ( struct V_204 * V_205 )
{
struct V_43 * V_43 = F_209 ( F_211 ( V_205 ) , struct V_43 , V_207 ) ;
F_26 ( V_43 ) ;
F_212 ( V_43 -> V_54 , & V_43 -> V_207 , V_180 ) ;
}
static void F_213 ( struct V_204 * V_205 )
{
struct V_43 * V_43 = F_209 ( F_211 ( V_205 ) , struct V_43 ,
V_208 ) ;
if ( F_136 ( V_43 ) == V_148 && ! V_43 -> V_142 . V_159 ) {
V_43 -> V_142 . V_159 = true ;
F_214 ( V_43 ) ;
F_70 ( V_43 , - V_68 ) ;
}
}
static struct V_209 * F_215 ( struct V_204 * V_205 )
{
return F_209 ( V_205 , struct V_209 , V_55 ) ;
}
static void F_216 ( struct V_209 * V_210 )
{
F_217 ( & V_210 -> F_217 ) ;
}
static void F_218 ( struct V_209 * V_210 , struct V_43 * V_43 ,
void (* F_35)( struct V_204 * ) )
{
F_219 ( & V_210 -> V_55 , F_35 ) ;
F_220 ( & V_210 -> F_217 ) ;
F_27 ( V_43 -> V_54 , & V_210 -> V_55 ) ;
F_221 ( & V_210 -> F_217 ) ;
}
static struct V_211 * F_222 ( struct V_204 * V_205 )
{
return F_209 ( F_215 ( V_205 ) , struct V_211 , V_210 ) ;
}
static void F_223 ( struct V_204 * V_205 )
{
struct V_211 * V_212 = F_222 ( V_205 ) ;
V_212 -> V_47 -> V_175 = true ;
F_69 ( V_212 -> V_47 ) ;
F_216 ( & V_212 -> V_210 ) ;
}
static void F_224 ( struct V_204 * V_205 )
{
struct V_211 * V_212 = F_222 ( V_205 ) ;
V_212 -> V_47 -> V_175 = false ;
F_216 ( & V_212 -> V_210 ) ;
}
static void V_211 ( struct V_46 * V_47 , void (* F_35)( struct V_204 * ) )
{
struct V_211 V_212 ;
V_212 . V_47 = V_47 ;
F_218 ( & V_212 . V_210 , V_47 -> V_43 , F_35 ) ;
}
static enum V_158 F_136 ( struct V_43 * V_43 )
{
return V_43 -> V_142 . V_213 ;
}
static void F_225 ( struct V_43 * V_43 , const char * V_214 )
{
F_144 ( V_43 -> V_155 -> V_156 ) ;
F_226 ( L_13 ,
F_143 ( V_43 -> V_78 ) , V_214 ) ;
}
static void F_214 ( struct V_43 * V_43 )
{
if ( ! V_43 -> V_142 . V_159 )
F_225 ( V_43 , L_14 ) ;
else
F_225 ( V_43 , L_15 ) ;
}
static bool F_227 ( struct V_215 * V_216 )
{
return V_216 -> V_217 . V_218 ;
}
static void F_228 ( struct V_43 * V_43 )
{
struct V_215 * V_216 = V_43 -> V_155 -> V_219 ;
if ( F_227 ( V_216 ) ) {
V_43 -> V_169 = F_157 ;
V_43 -> V_162 = F_114 ;
} else {
V_43 -> V_169 = F_152 ;
V_43 -> V_162 = F_110 ;
}
}
static void F_138 ( struct V_43 * V_43 , enum V_158 V_214 )
{
struct V_215 * V_216 = V_43 -> V_155 -> V_219 ;
bool V_220 = F_229 ( V_43 -> V_122 ) ;
enum V_158 V_221 = F_136 ( V_43 ) ;
unsigned long V_208 = F_230 ( V_222 ) * V_223 ;
if ( V_214 == V_149 && V_220 ) {
F_231 ( L_16 ,
F_143 ( V_43 -> V_78 ) ) ;
if ( V_221 != V_214 )
V_214 = V_221 ;
else
V_214 = V_150 ;
}
if ( V_221 == V_160 )
V_214 = V_221 ;
switch ( V_214 ) {
case V_160 :
if ( V_221 != V_214 )
F_225 ( V_43 , L_17 ) ;
F_232 ( V_43 -> V_122 ) ;
V_43 -> F_168 = F_173 ;
V_43 -> V_191 = F_173 ;
V_43 -> F_165 = F_175 ;
V_43 -> V_169 = F_175 ;
V_43 -> F_104 = F_102 ;
V_43 -> V_162 = F_108 ;
F_74 ( V_43 ) ;
break;
case V_150 :
if ( V_221 != V_214 )
F_225 ( V_43 , L_18 ) ;
F_232 ( V_43 -> V_122 ) ;
V_43 -> F_168 = F_170 ;
V_43 -> V_191 = F_172 ;
V_43 -> F_165 = F_171 ;
V_43 -> V_169 = F_174 ;
V_43 -> F_104 = F_102 ;
V_43 -> V_162 = F_109 ;
F_74 ( V_43 ) ;
break;
case V_148 :
if ( V_221 != V_214 )
F_214 ( V_43 ) ;
V_43 -> V_67 = true ;
V_43 -> F_168 = F_170 ;
V_43 -> V_191 = F_158 ;
V_43 -> F_165 = F_171 ;
V_43 -> F_104 = F_104 ;
F_228 ( V_43 ) ;
if ( ! V_43 -> V_142 . V_159 && V_208 )
F_212 ( V_43 -> V_54 , & V_43 -> V_208 , V_208 ) ;
break;
case V_149 :
if ( V_221 != V_214 )
F_225 ( V_43 , L_19 ) ;
V_43 -> V_67 = false ;
V_43 -> V_142 . V_159 = V_216 -> V_224 . V_159 ;
F_233 ( V_43 -> V_122 ) ;
V_43 -> F_168 = F_168 ;
V_43 -> V_191 = F_158 ;
V_43 -> F_165 = F_165 ;
V_43 -> F_104 = F_104 ;
F_228 ( V_43 ) ;
break;
}
V_43 -> V_142 . V_213 = V_214 ;
V_216 -> V_217 . V_213 = V_214 ;
}
static void F_234 ( struct V_43 * V_43 )
{
const char * V_225 = F_143 ( V_43 -> V_78 ) ;
F_125 ( L_20 , V_225 ) ;
if ( F_235 ( V_43 -> V_122 ) ) {
F_231 ( L_21 , V_225 ) ;
F_138 ( V_43 , V_160 ) ;
}
if ( F_236 ( V_43 -> V_122 ) ) {
F_231 ( L_22 , V_225 ) ;
F_138 ( V_43 , V_160 ) ;
}
}
static void F_106 ( struct V_43 * V_43 , const char * V_226 , int V_58 )
{
F_125 ( L_23 ,
F_143 ( V_43 -> V_78 ) , V_226 , V_58 ) ;
F_234 ( V_43 ) ;
F_138 ( V_43 , V_150 ) ;
}
static void F_101 ( struct V_46 * V_47 , struct V_28 * V_28 )
{
unsigned long V_27 ;
struct V_43 * V_43 = V_47 -> V_43 ;
F_64 ( & V_47 -> V_17 , V_27 ) ;
F_89 ( & V_47 -> V_85 , V_28 ) ;
F_65 ( & V_47 -> V_17 , V_27 ) ;
F_26 ( V_43 ) ;
}
static void F_237 ( struct V_46 * V_47 , struct V_28 * V_28 )
{
struct V_43 * V_43 = V_47 -> V_43 ;
F_12 ( & V_43 -> V_15 ) ;
F_101 ( V_47 , V_28 ) ;
F_14 ( & V_43 -> V_15 ) ;
}
static void F_238 ( struct V_46 * V_47 , struct V_56 * V_62 )
{
unsigned long V_27 ;
struct V_43 * V_43 = V_47 -> V_43 ;
F_12 ( & V_43 -> V_15 ) ;
F_64 ( & V_47 -> V_17 , V_27 ) ;
F_94 ( & V_62 -> V_198 , & V_47 -> V_84 ) ;
F_65 ( & V_47 -> V_17 , V_27 ) ;
F_14 ( & V_43 -> V_15 ) ;
F_26 ( V_43 ) ;
}
static void F_239 ( struct V_46 * V_47 , struct V_28 * V_28 )
{
struct V_96 * V_97 = F_83 ( V_28 , sizeof( struct V_96 ) ) ;
V_97 -> V_47 = V_47 ;
V_97 -> V_173 = NULL ;
V_97 -> V_98 = NULL ;
V_97 -> V_108 = NULL ;
V_97 -> V_62 = NULL ;
}
static int F_240 ( struct V_227 * V_155 , struct V_28 * V_28 )
{
int V_58 ;
struct V_46 * V_47 = V_155 -> V_219 ;
T_1 V_91 = F_75 ( V_47 , V_28 ) ;
struct V_1 * V_2 = V_47 -> V_2 ;
struct V_170 V_157 ;
struct V_56 * V_161 , * V_167 ;
struct V_7 V_8 ;
F_239 ( V_47 , V_28 ) ;
if ( V_47 -> V_175 ) {
V_28 -> V_81 = V_70 ;
F_62 ( V_28 ) ;
return V_228 ;
}
if ( F_136 ( V_47 -> V_43 ) == V_160 ) {
F_88 ( V_28 ) ;
return V_228 ;
}
if ( V_28 -> V_93 & ( V_33 | V_94 | V_95 ) ) {
F_237 ( V_47 , V_28 ) ;
return V_228 ;
}
F_4 ( V_47 -> V_2 , V_91 , & V_8 ) ;
if ( F_28 ( V_47 -> V_43 , & V_8 , V_28 , & V_161 ) )
return V_228 ;
V_58 = F_166 ( V_2 , V_91 , 0 , & V_157 ) ;
switch ( V_58 ) {
case 0 :
if ( F_241 ( V_157 . V_176 ) ) {
F_238 ( V_47 , V_161 ) ;
return V_228 ;
}
F_3 ( V_47 -> V_2 , V_157 . V_91 , & V_8 ) ;
if ( F_28 ( V_47 -> V_43 , & V_8 , V_28 , & V_167 ) ) {
F_98 ( V_47 , V_161 ) ;
return V_228 ;
}
F_82 ( V_47 -> V_43 , V_28 ) ;
F_98 ( V_47 , V_167 ) ;
F_98 ( V_47 , V_161 ) ;
F_78 ( V_47 , V_28 , V_157 . V_91 ) ;
return V_229 ;
case - V_177 :
case - V_230 :
F_238 ( V_47 , V_161 ) ;
return V_228 ;
default:
F_88 ( V_28 ) ;
F_98 ( V_47 , V_161 ) ;
return V_228 ;
}
}
static int F_242 ( struct V_231 * V_232 , int V_233 )
{
struct V_215 * V_216 = F_209 ( V_232 , struct V_215 , V_234 ) ;
struct V_30 * V_31 ;
if ( F_136 ( V_216 -> V_43 ) == V_148 )
return 1 ;
V_31 = F_17 ( V_216 -> V_235 -> V_23 ) ;
return F_243 ( & V_31 -> V_236 , V_233 ) ;
}
static void F_244 ( struct V_43 * V_43 )
{
unsigned long V_27 ;
struct V_46 * V_47 ;
F_71 () ;
F_72 (tc, &pool->active_thins, list) {
F_64 ( & V_47 -> V_17 , V_27 ) ;
F_58 ( & V_47 -> V_85 , & V_47 -> V_86 ) ;
F_59 ( & V_47 -> V_86 ) ;
F_65 ( & V_47 -> V_17 , V_27 ) ;
}
F_73 () ;
}
static bool F_245 ( struct V_215 * V_216 )
{
struct V_30 * V_31 = F_17 ( V_216 -> V_235 -> V_23 ) ;
return V_31 && F_18 ( V_31 ) ;
}
static bool F_246 ( T_2 V_237 , T_6 V_238 )
{
return ! F_76 ( V_237 , V_238 ) ;
}
static void F_247 ( struct V_215 * V_216 )
{
struct V_43 * V_43 = V_216 -> V_43 ;
struct V_22 * V_239 = V_216 -> V_235 -> V_23 ;
struct V_240 * V_241 = & F_17 ( V_239 ) -> V_242 ;
const char * V_243 = NULL ;
char V_244 [ V_245 ] ;
if ( ! V_216 -> V_217 . V_218 )
return;
if ( ! F_245 ( V_216 ) )
V_243 = L_24 ;
else if ( V_241 -> V_246 < V_43 -> V_45 )
V_243 = L_25 ;
if ( V_243 ) {
F_142 ( L_26 , F_248 ( V_239 , V_244 ) , V_243 ) ;
V_216 -> V_217 . V_218 = false ;
}
}
static int F_249 ( struct V_43 * V_43 , struct V_227 * V_155 )
{
struct V_215 * V_216 = V_155 -> V_219 ;
enum V_158 V_221 = F_136 ( V_43 ) ;
enum V_158 V_214 = V_216 -> V_217 . V_213 ;
V_216 -> V_217 . V_213 = V_221 ;
V_43 -> V_155 = V_155 ;
V_43 -> V_142 = V_216 -> V_217 ;
V_43 -> V_153 = V_216 -> V_153 ;
F_138 ( V_43 , V_214 ) ;
return 0 ;
}
static void F_250 ( struct V_43 * V_43 , struct V_227 * V_155 )
{
if ( V_43 -> V_155 == V_155 )
V_43 -> V_155 = NULL ;
}
static void F_251 ( struct V_247 * V_142 )
{
V_142 -> V_213 = V_149 ;
V_142 -> V_143 = true ;
V_142 -> V_248 = true ;
V_142 -> V_218 = true ;
V_142 -> V_159 = false ;
}
static void F_252 ( struct V_43 * V_43 )
{
F_52 ( V_43 ) ;
F_253 ( V_43 -> V_197 ) ;
if ( F_254 ( V_43 -> V_122 ) < 0 )
F_142 ( L_27 , V_172 ) ;
F_255 ( V_43 -> V_60 ) ;
F_256 ( V_43 -> V_133 ) ;
if ( V_43 -> V_54 )
F_257 ( V_43 -> V_54 ) ;
if ( V_43 -> V_128 )
F_103 ( V_43 -> V_128 , V_43 -> V_115 ) ;
F_258 ( V_43 -> V_115 ) ;
F_259 ( V_43 -> V_140 ) ;
F_259 ( V_43 -> V_99 ) ;
F_260 ( V_43 ) ;
}
static struct V_43 * F_261 ( struct V_75 * V_78 ,
struct V_22 * V_249 ,
unsigned long V_237 ,
int V_250 , char * * error )
{
int V_58 ;
void * V_251 ;
struct V_43 * V_43 ;
struct V_252 * V_122 ;
bool V_253 = V_250 ? false : true ;
V_122 = F_262 ( V_249 , V_237 , V_253 ) ;
if ( F_263 ( V_122 ) ) {
* error = L_28 ;
return (struct V_43 * ) V_122 ;
}
V_43 = F_264 ( sizeof( * V_43 ) , V_254 ) ;
if ( ! V_43 ) {
* error = L_29 ;
V_251 = F_265 ( - V_38 ) ;
goto V_255;
}
V_43 -> V_122 = V_122 ;
V_43 -> V_45 = V_237 ;
if ( V_237 & ( V_237 - 1 ) )
V_43 -> V_44 = - 1 ;
else
V_43 -> V_44 = F_266 ( V_237 ) ;
V_43 -> V_153 = 0 ;
F_251 ( & V_43 -> V_142 ) ;
V_43 -> V_60 = F_267 () ;
if ( ! V_43 -> V_60 ) {
* error = L_30 ;
V_251 = F_265 ( - V_38 ) ;
goto V_256;
}
V_43 -> V_133 = F_268 ( & V_257 ) ;
if ( F_263 ( V_43 -> V_133 ) ) {
V_58 = F_269 ( V_43 -> V_133 ) ;
* error = L_31 ;
V_251 = F_265 ( V_58 ) ;
goto V_258;
}
V_43 -> V_54 = F_270 ( L_32 V_259 , V_260 ) ;
if ( ! V_43 -> V_54 ) {
* error = L_33 ;
V_251 = F_265 ( - V_38 ) ;
goto V_261;
}
F_5 ( & V_43 -> V_15 ) ;
F_271 ( & V_43 -> V_55 , F_208 ) ;
F_272 ( & V_43 -> V_207 , F_210 ) ;
F_272 ( & V_43 -> V_208 , F_213 ) ;
F_273 ( & V_43 -> V_17 ) ;
F_59 ( & V_43 -> V_100 ) ;
F_47 ( & V_43 -> V_104 ) ;
F_47 ( & V_43 -> V_206 ) ;
F_47 ( & V_43 -> V_201 ) ;
V_43 -> V_154 = false ;
V_43 -> V_262 = true ;
V_43 -> V_67 = false ;
V_43 -> V_140 = F_274 () ;
if ( ! V_43 -> V_140 ) {
* error = L_34 ;
V_251 = F_265 ( - V_38 ) ;
goto V_263;
}
V_43 -> V_99 = F_274 () ;
if ( ! V_43 -> V_99 ) {
* error = L_35 ;
V_251 = F_265 ( - V_38 ) ;
goto V_264;
}
V_43 -> V_128 = NULL ;
V_43 -> V_115 = F_275 ( V_265 ,
V_266 ) ;
if ( ! V_43 -> V_115 ) {
* error = L_36 ;
V_251 = F_265 ( - V_38 ) ;
goto V_267;
}
V_43 -> V_197 = F_276 ( sizeof( * V_43 -> V_197 ) * V_196 ) ;
if ( ! V_43 -> V_197 ) {
* error = L_37 ;
V_251 = F_265 ( - V_38 ) ;
goto V_268;
}
V_43 -> V_269 = 1 ;
V_43 -> V_179 = V_20 ;
V_43 -> V_78 = V_78 ;
V_43 -> V_79 = V_249 ;
F_48 ( V_43 ) ;
return V_43 ;
V_268:
F_258 ( V_43 -> V_115 ) ;
V_267:
F_259 ( V_43 -> V_99 ) ;
V_264:
F_259 ( V_43 -> V_140 ) ;
V_263:
F_257 ( V_43 -> V_54 ) ;
V_261:
F_256 ( V_43 -> V_133 ) ;
V_258:
F_255 ( V_43 -> V_60 ) ;
V_256:
F_260 ( V_43 ) ;
V_255:
if ( F_254 ( V_122 ) )
F_142 ( L_27 , V_172 ) ;
return V_251 ;
}
static void F_277 ( struct V_43 * V_43 )
{
F_49 ( ! F_50 ( & V_71 . V_72 ) ) ;
V_43 -> V_269 ++ ;
}
static void F_278 ( struct V_43 * V_43 )
{
F_49 ( ! F_50 ( & V_71 . V_72 ) ) ;
F_49 ( ! V_43 -> V_269 ) ;
if ( ! -- V_43 -> V_269 )
F_252 ( V_43 ) ;
}
static struct V_43 * F_279 ( struct V_75 * V_78 ,
struct V_22 * V_249 ,
unsigned long V_237 , int V_250 ,
char * * error , int * V_270 )
{
struct V_43 * V_43 = F_56 ( V_249 ) ;
if ( V_43 ) {
if ( V_43 -> V_78 != V_78 ) {
* error = L_38 ;
return F_265 ( - V_271 ) ;
}
F_277 ( V_43 ) ;
} else {
V_43 = F_54 ( V_78 ) ;
if ( V_43 ) {
if ( V_43 -> V_79 != V_249 ) {
* error = L_39 ;
return F_265 ( - V_151 ) ;
}
F_277 ( V_43 ) ;
} else {
V_43 = F_261 ( V_78 , V_249 , V_237 , V_250 , error ) ;
* V_270 = 1 ;
}
}
return V_43 ;
}
static void F_280 ( struct V_227 * V_155 )
{
struct V_215 * V_216 = V_155 -> V_219 ;
F_281 ( & V_71 . V_72 ) ;
F_250 ( V_216 -> V_43 , V_155 ) ;
F_278 ( V_216 -> V_43 ) ;
F_282 ( V_155 , V_216 -> V_249 ) ;
F_282 ( V_155 , V_216 -> V_235 ) ;
F_260 ( V_216 ) ;
F_283 ( & V_71 . V_72 ) ;
}
static int F_284 ( struct V_272 * V_273 , struct V_247 * V_142 ,
struct V_227 * V_155 )
{
int V_58 ;
unsigned V_274 ;
const char * V_275 ;
static struct V_276 V_277 [] = {
{ 0 , 4 , L_40 } ,
} ;
if ( ! V_273 -> V_274 )
return 0 ;
V_58 = F_285 ( V_277 , V_273 , & V_274 , & V_155 -> error ) ;
if ( V_58 )
return - V_151 ;
while ( V_274 && ! V_58 ) {
V_275 = F_286 ( V_273 ) ;
V_274 -- ;
if ( ! strcasecmp ( V_275 , L_41 ) )
V_142 -> V_143 = false ;
else if ( ! strcasecmp ( V_275 , L_42 ) )
V_142 -> V_248 = false ;
else if ( ! strcasecmp ( V_275 , L_43 ) )
V_142 -> V_218 = false ;
else if ( ! strcasecmp ( V_275 , L_44 ) )
V_142 -> V_213 = V_150 ;
else if ( ! strcasecmp ( V_275 , L_45 ) )
V_142 -> V_159 = true ;
else {
V_155 -> error = L_46 ;
V_58 = - V_151 ;
break;
}
}
return V_58 ;
}
static void F_287 ( void * V_65 )
{
struct V_43 * V_43 = V_65 ;
F_142 ( L_47 ,
F_143 ( V_43 -> V_78 ) ) ;
F_144 ( V_43 -> V_155 -> V_156 ) ;
}
static T_2 F_288 ( struct V_22 * V_23 )
{
return F_289 ( V_23 -> V_278 ) >> V_90 ;
}
static void F_290 ( struct V_22 * V_23 )
{
T_2 V_279 = F_288 ( V_23 ) ;
char V_280 [ V_245 ] ;
if ( V_279 > V_281 )
F_142 ( L_48 ,
F_248 ( V_23 , V_280 ) , V_282 ) ;
}
static T_2 F_291 ( struct V_22 * V_23 )
{
T_2 V_279 = F_288 ( V_23 ) ;
if ( V_279 > V_282 )
V_279 = V_282 ;
return V_279 ;
}
static T_1 F_292 ( struct V_22 * V_23 )
{
T_2 V_279 = F_291 ( V_23 ) ;
F_76 ( V_279 , V_283 ) ;
return V_279 ;
}
static T_1 F_293 ( struct V_215 * V_216 )
{
T_1 V_284 = F_292 ( V_216 -> V_249 -> V_23 ) / 4 ;
return F_294 ( ( T_1 ) 1024ULL , V_284 ) ;
}
static int F_295 ( struct V_227 * V_155 , unsigned V_274 , char * * V_285 )
{
int V_58 , V_286 = 0 ;
struct V_215 * V_216 ;
struct V_43 * V_43 ;
struct V_247 V_142 ;
struct V_272 V_273 ;
struct V_136 * V_235 ;
unsigned long V_237 ;
T_1 V_153 ;
struct V_136 * V_249 ;
T_7 V_287 ;
F_281 ( & V_71 . V_72 ) ;
if ( V_274 < 4 ) {
V_155 -> error = L_49 ;
V_58 = - V_151 ;
goto V_288;
}
V_273 . V_274 = V_274 ;
V_273 . V_285 = V_285 ;
F_251 ( & V_142 ) ;
F_296 ( & V_273 , 4 ) ;
V_58 = F_284 ( & V_273 , & V_142 , V_155 ) ;
if ( V_58 )
goto V_288;
V_287 = V_289 | ( ( V_142 . V_213 == V_150 ) ? 0 : V_290 ) ;
V_58 = F_297 ( V_155 , V_285 [ 0 ] , V_287 , & V_249 ) ;
if ( V_58 ) {
V_155 -> error = L_50 ;
goto V_288;
}
F_290 ( V_249 -> V_23 ) ;
V_58 = F_297 ( V_155 , V_285 [ 1 ] , V_289 | V_290 , & V_235 ) ;
if ( V_58 ) {
V_155 -> error = L_51 ;
goto V_291;
}
if ( F_298 ( V_285 [ 2 ] , 10 , & V_237 ) || ! V_237 ||
V_237 < V_292 ||
V_237 > V_293 ||
V_237 & ( V_292 - 1 ) ) {
V_155 -> error = L_52 ;
V_58 = - V_151 ;
goto V_116;
}
if ( F_299 ( V_285 [ 3 ] , 10 , ( unsigned long long * ) & V_153 ) ) {
V_155 -> error = L_53 ;
V_58 = - V_151 ;
goto V_116;
}
V_216 = F_300 ( sizeof( * V_216 ) , V_254 ) ;
if ( ! V_216 ) {
V_58 = - V_38 ;
goto V_116;
}
V_43 = F_279 ( F_301 ( V_155 -> V_156 ) , V_249 -> V_23 ,
V_237 , V_142 . V_213 == V_150 , & V_155 -> error , & V_286 ) ;
if ( F_263 ( V_43 ) ) {
V_58 = F_269 ( V_43 ) ;
goto V_294;
}
if ( ! V_286 && V_142 . V_248 != V_43 -> V_142 . V_248 ) {
V_155 -> error = L_54 ;
V_58 = - V_151 ;
goto V_295;
}
V_216 -> V_43 = V_43 ;
V_216 -> V_155 = V_155 ;
V_216 -> V_249 = V_249 ;
V_216 -> V_235 = V_235 ;
V_216 -> V_153 = V_153 ;
V_216 -> V_217 = V_216 -> V_224 = V_142 ;
V_155 -> V_296 = 1 ;
V_155 -> V_297 = true ;
if ( V_142 . V_248 && V_142 . V_218 ) {
V_155 -> V_298 = 1 ;
V_155 -> V_299 = true ;
}
V_155 -> V_219 = V_216 ;
V_58 = F_302 ( V_216 -> V_43 -> V_122 ,
F_293 ( V_216 ) ,
F_287 ,
V_43 ) ;
if ( V_58 )
goto V_295;
V_216 -> V_234 . V_300 = F_242 ;
F_303 ( V_155 -> V_156 , & V_216 -> V_234 ) ;
F_283 ( & V_71 . V_72 ) ;
return 0 ;
V_295:
F_278 ( V_43 ) ;
V_294:
F_260 ( V_216 ) ;
V_116:
F_282 ( V_155 , V_235 ) ;
V_291:
F_282 ( V_155 , V_249 ) ;
V_288:
F_283 ( & V_71 . V_72 ) ;
return V_58 ;
}
static int F_304 ( struct V_227 * V_155 , struct V_28 * V_28 )
{
int V_58 ;
struct V_215 * V_216 = V_155 -> V_219 ;
struct V_43 * V_43 = V_216 -> V_43 ;
unsigned long V_27 ;
F_64 ( & V_43 -> V_17 , V_27 ) ;
V_28 -> V_41 = V_216 -> V_235 -> V_23 ;
V_58 = V_229 ;
F_65 ( & V_43 -> V_17 , V_27 ) ;
return V_58 ;
}
static int F_305 ( struct V_227 * V_155 , bool * V_301 )
{
int V_58 ;
struct V_215 * V_216 = V_155 -> V_219 ;
struct V_43 * V_43 = V_216 -> V_43 ;
T_2 V_302 = V_155 -> V_51 ;
T_1 V_303 ;
* V_301 = false ;
( void ) F_76 ( V_302 , V_43 -> V_45 ) ;
V_58 = F_306 ( V_43 -> V_122 , & V_303 ) ;
if ( V_58 ) {
F_231 ( L_55 ,
F_143 ( V_43 -> V_78 ) ) ;
return V_58 ;
}
if ( V_302 < V_303 ) {
F_231 ( L_56 ,
F_143 ( V_43 -> V_78 ) ,
( unsigned long long ) V_302 , V_303 ) ;
return - V_151 ;
} else if ( V_302 > V_303 ) {
if ( F_229 ( V_43 -> V_122 ) ) {
F_231 ( L_57 ,
F_143 ( V_43 -> V_78 ) ) ;
return 0 ;
}
if ( V_303 )
F_226 ( L_58 ,
F_143 ( V_43 -> V_78 ) ,
V_303 , ( unsigned long long ) V_302 ) ;
V_58 = F_307 ( V_43 -> V_122 , V_302 ) ;
if ( V_58 ) {
F_106 ( V_43 , L_59 , V_58 ) ;
return V_58 ;
}
* V_301 = true ;
}
return 0 ;
}
static int F_308 ( struct V_227 * V_155 , bool * V_301 )
{
int V_58 ;
struct V_215 * V_216 = V_155 -> V_219 ;
struct V_43 * V_43 = V_216 -> V_43 ;
T_1 V_279 , V_304 ;
* V_301 = false ;
V_279 = F_292 ( V_43 -> V_79 ) ;
V_58 = F_309 ( V_43 -> V_122 , & V_304 ) ;
if ( V_58 ) {
F_231 ( L_60 ,
F_143 ( V_43 -> V_78 ) ) ;
return V_58 ;
}
if ( V_279 < V_304 ) {
F_231 ( L_61 ,
F_143 ( V_43 -> V_78 ) ,
V_279 , V_304 ) ;
return - V_151 ;
} else if ( V_279 > V_304 ) {
if ( F_229 ( V_43 -> V_122 ) ) {
F_231 ( L_62 ,
F_143 ( V_43 -> V_78 ) ) ;
return 0 ;
}
F_290 ( V_43 -> V_79 ) ;
F_226 ( L_63 ,
F_143 ( V_43 -> V_78 ) ,
V_304 , V_279 ) ;
V_58 = F_310 ( V_43 -> V_122 , V_279 ) ;
if ( V_58 ) {
F_106 ( V_43 , L_64 , V_58 ) ;
return V_58 ;
}
* V_301 = true ;
}
return 0 ;
}
static int F_311 ( struct V_227 * V_155 )
{
int V_58 ;
bool V_305 , V_306 ;
struct V_215 * V_216 = V_155 -> V_219 ;
struct V_43 * V_43 = V_216 -> V_43 ;
V_58 = F_249 ( V_43 , V_155 ) ;
if ( V_58 )
return V_58 ;
V_58 = F_305 ( V_155 , & V_305 ) ;
if ( V_58 )
return V_58 ;
V_58 = F_308 ( V_155 , & V_306 ) ;
if ( V_58 )
return V_58 ;
if ( V_305 || V_306 )
( void ) F_139 ( V_43 ) ;
return 0 ;
}
static void F_312 ( struct V_43 * V_43 )
{
struct V_46 * V_47 ;
V_47 = F_200 ( V_43 ) ;
while ( V_47 ) {
F_313 ( V_47 -> V_307 ) ;
V_47 = F_203 ( V_43 , V_47 ) ;
}
}
static void F_314 ( struct V_43 * V_43 )
{
struct V_46 * V_47 ;
V_47 = F_200 ( V_43 ) ;
while ( V_47 ) {
F_315 ( V_47 -> V_307 ) ;
V_47 = F_203 ( V_43 , V_47 ) ;
}
}
static void F_316 ( struct V_227 * V_155 )
{
struct V_215 * V_216 = V_155 -> V_219 ;
struct V_43 * V_43 = V_216 -> V_43 ;
unsigned long V_27 ;
F_244 ( V_43 ) ;
F_314 ( V_43 ) ;
F_64 ( & V_43 -> V_17 , V_27 ) ;
V_43 -> V_154 = false ;
V_43 -> V_262 = false ;
F_65 ( & V_43 -> V_17 , V_27 ) ;
F_210 ( & V_43 -> V_207 . V_308 ) ;
}
static void F_317 ( struct V_227 * V_155 )
{
struct V_215 * V_216 = V_155 -> V_219 ;
struct V_43 * V_43 = V_216 -> V_43 ;
unsigned long V_27 ;
F_64 ( & V_43 -> V_17 , V_27 ) ;
V_43 -> V_262 = true ;
F_65 ( & V_43 -> V_17 , V_27 ) ;
F_312 ( V_43 ) ;
}
static void F_318 ( struct V_227 * V_155 )
{
struct V_215 * V_216 = V_155 -> V_219 ;
struct V_43 * V_43 = V_216 -> V_43 ;
unsigned long V_27 ;
F_314 ( V_43 ) ;
F_64 ( & V_43 -> V_17 , V_27 ) ;
V_43 -> V_262 = false ;
F_65 ( & V_43 -> V_17 , V_27 ) ;
}
static void F_319 ( struct V_227 * V_155 )
{
struct V_215 * V_216 = V_155 -> V_219 ;
struct V_43 * V_43 = V_216 -> V_43 ;
F_320 ( & V_43 -> V_207 ) ;
F_320 ( & V_43 -> V_208 ) ;
F_321 ( V_43 -> V_54 ) ;
( void ) F_139 ( V_43 ) ;
}
static int F_322 ( unsigned V_274 , unsigned V_309 )
{
if ( V_274 != V_309 ) {
F_142 ( L_65 ,
V_274 , V_309 ) ;
return - V_151 ;
}
return 0 ;
}
static int F_323 ( char * V_310 , T_8 * V_311 , int V_312 )
{
if ( ! F_299 ( V_310 , 10 , ( unsigned long long * ) V_311 ) &&
* V_311 <= V_313 )
return 0 ;
if ( V_312 )
F_142 ( L_66 , V_310 ) ;
return - V_151 ;
}
static int F_324 ( unsigned V_274 , char * * V_285 , struct V_43 * V_43 )
{
T_8 V_311 ;
int V_58 ;
V_58 = F_322 ( V_274 , 2 ) ;
if ( V_58 )
return V_58 ;
V_58 = F_323 ( V_285 [ 1 ] , & V_311 , 1 ) ;
if ( V_58 )
return V_58 ;
V_58 = F_325 ( V_43 -> V_122 , V_311 ) ;
if ( V_58 ) {
F_142 ( L_67 ,
V_285 [ 1 ] ) ;
return V_58 ;
}
return 0 ;
}
static int F_326 ( unsigned V_274 , char * * V_285 , struct V_43 * V_43 )
{
T_8 V_311 ;
T_8 V_314 ;
int V_58 ;
V_58 = F_322 ( V_274 , 3 ) ;
if ( V_58 )
return V_58 ;
V_58 = F_323 ( V_285 [ 1 ] , & V_311 , 1 ) ;
if ( V_58 )
return V_58 ;
V_58 = F_323 ( V_285 [ 2 ] , & V_314 , 1 ) ;
if ( V_58 )
return V_58 ;
V_58 = F_327 ( V_43 -> V_122 , V_311 , V_314 ) ;
if ( V_58 ) {
F_142 ( L_68 ,
V_285 [ 1 ] , V_285 [ 2 ] ) ;
return V_58 ;
}
return 0 ;
}
static int F_328 ( unsigned V_274 , char * * V_285 , struct V_43 * V_43 )
{
T_8 V_311 ;
int V_58 ;
V_58 = F_322 ( V_274 , 2 ) ;
if ( V_58 )
return V_58 ;
V_58 = F_323 ( V_285 [ 1 ] , & V_311 , 1 ) ;
if ( V_58 )
return V_58 ;
V_58 = F_329 ( V_43 -> V_122 , V_311 ) ;
if ( V_58 )
F_142 ( L_69 , V_285 [ 1 ] ) ;
return V_58 ;
}
static int F_330 ( unsigned V_274 , char * * V_285 , struct V_43 * V_43 )
{
T_8 V_315 , V_316 ;
int V_58 ;
V_58 = F_322 ( V_274 , 3 ) ;
if ( V_58 )
return V_58 ;
if ( F_299 ( V_285 [ 1 ] , 10 , ( unsigned long long * ) & V_315 ) ) {
F_142 ( L_70 , V_285 [ 1 ] ) ;
return - V_151 ;
}
if ( F_299 ( V_285 [ 2 ] , 10 , ( unsigned long long * ) & V_316 ) ) {
F_142 ( L_71 , V_285 [ 2 ] ) ;
return - V_151 ;
}
V_58 = F_331 ( V_43 -> V_122 , V_315 , V_316 ) ;
if ( V_58 ) {
F_142 ( L_72 ,
V_285 [ 1 ] , V_285 [ 2 ] ) ;
return V_58 ;
}
return 0 ;
}
static int F_332 ( unsigned V_274 , char * * V_285 , struct V_43 * V_43 )
{
int V_58 ;
V_58 = F_322 ( V_274 , 1 ) ;
if ( V_58 )
return V_58 ;
( void ) F_139 ( V_43 ) ;
V_58 = F_333 ( V_43 -> V_122 ) ;
if ( V_58 )
F_142 ( L_73 ) ;
return V_58 ;
}
static int F_334 ( unsigned V_274 , char * * V_285 , struct V_43 * V_43 )
{
int V_58 ;
V_58 = F_322 ( V_274 , 1 ) ;
if ( V_58 )
return V_58 ;
V_58 = F_335 ( V_43 -> V_122 ) ;
if ( V_58 )
F_142 ( L_74 ) ;
return V_58 ;
}
static int F_336 ( struct V_227 * V_155 , unsigned V_274 , char * * V_285 )
{
int V_58 = - V_151 ;
struct V_215 * V_216 = V_155 -> V_219 ;
struct V_43 * V_43 = V_216 -> V_43 ;
if ( F_136 ( V_43 ) >= V_150 ) {
F_231 ( L_75 ,
F_143 ( V_43 -> V_78 ) ) ;
return - V_35 ;
}
if ( ! strcasecmp ( V_285 [ 0 ] , L_76 ) )
V_58 = F_324 ( V_274 , V_285 , V_43 ) ;
else if ( ! strcasecmp ( V_285 [ 0 ] , L_77 ) )
V_58 = F_326 ( V_274 , V_285 , V_43 ) ;
else if ( ! strcasecmp ( V_285 [ 0 ] , L_78 ) )
V_58 = F_328 ( V_274 , V_285 , V_43 ) ;
else if ( ! strcasecmp ( V_285 [ 0 ] , L_79 ) )
V_58 = F_330 ( V_274 , V_285 , V_43 ) ;
else if ( ! strcasecmp ( V_285 [ 0 ] , L_80 ) )
V_58 = F_332 ( V_274 , V_285 , V_43 ) ;
else if ( ! strcasecmp ( V_285 [ 0 ] , L_81 ) )
V_58 = F_334 ( V_274 , V_285 , V_43 ) ;
else
F_142 ( L_82 , V_285 [ 0 ] ) ;
if ( ! V_58 )
( void ) F_139 ( V_43 ) ;
return V_58 ;
}
static void F_337 ( struct V_247 * V_142 , char * V_157 ,
unsigned V_317 , unsigned V_318 )
{
unsigned V_132 = ! V_142 -> V_143 + ! V_142 -> V_248 +
! V_142 -> V_218 + ( V_142 -> V_213 == V_150 ) +
V_142 -> V_159 ;
F_338 ( L_83 , V_132 ) ;
if ( ! V_142 -> V_143 )
F_338 ( L_84 ) ;
if ( ! V_142 -> V_248 )
F_338 ( L_85 ) ;
if ( ! V_142 -> V_218 )
F_338 ( L_86 ) ;
if ( V_142 -> V_213 == V_150 )
F_338 ( L_87 ) ;
if ( V_142 -> V_159 )
F_338 ( L_88 ) ;
}
static void F_339 ( struct V_227 * V_155 , T_9 type ,
unsigned V_319 , char * V_157 , unsigned V_318 )
{
int V_58 ;
unsigned V_317 = 0 ;
T_10 V_320 ;
T_1 V_321 ;
T_1 V_322 ;
T_1 V_323 ;
T_1 V_324 ;
T_1 V_325 ;
char V_244 [ V_245 ] ;
char V_326 [ V_245 ] ;
struct V_215 * V_216 = V_155 -> V_219 ;
struct V_43 * V_43 = V_216 -> V_43 ;
switch ( type ) {
case V_327 :
if ( F_136 ( V_43 ) == V_160 ) {
F_338 ( L_89 ) ;
break;
}
if ( ! ( V_319 & V_328 ) && ! F_340 ( V_155 ) )
( void ) F_139 ( V_43 ) ;
V_58 = F_341 ( V_43 -> V_122 , & V_320 ) ;
if ( V_58 ) {
F_231 ( L_90 ,
F_143 ( V_43 -> V_78 ) , V_58 ) ;
goto V_107;
}
V_58 = F_342 ( V_43 -> V_122 , & V_322 ) ;
if ( V_58 ) {
F_231 ( L_91 ,
F_143 ( V_43 -> V_78 ) , V_58 ) ;
goto V_107;
}
V_58 = F_309 ( V_43 -> V_122 , & V_324 ) ;
if ( V_58 ) {
F_231 ( L_92 ,
F_143 ( V_43 -> V_78 ) , V_58 ) ;
goto V_107;
}
V_58 = F_137 ( V_43 -> V_122 , & V_321 ) ;
if ( V_58 ) {
F_231 ( L_93 ,
F_143 ( V_43 -> V_78 ) , V_58 ) ;
goto V_107;
}
V_58 = F_306 ( V_43 -> V_122 , & V_323 ) ;
if ( V_58 ) {
F_231 ( L_94 ,
F_143 ( V_43 -> V_78 ) , V_58 ) ;
goto V_107;
}
V_58 = F_343 ( V_43 -> V_122 , & V_325 ) ;
if ( V_58 ) {
F_231 ( L_95 ,
F_143 ( V_43 -> V_78 ) , V_58 ) ;
goto V_107;
}
F_338 ( L_96 ,
( unsigned long long ) V_320 ,
( unsigned long long ) ( V_324 - V_322 ) ,
( unsigned long long ) V_324 ,
( unsigned long long ) ( V_323 - V_321 ) ,
( unsigned long long ) V_323 ) ;
if ( V_325 )
F_338 ( L_97 , V_325 ) ;
else
F_338 ( L_98 ) ;
if ( V_43 -> V_142 . V_213 == V_148 )
F_338 ( L_99 ) ;
else if ( V_43 -> V_142 . V_213 == V_150 )
F_338 ( L_100 ) ;
else
F_338 ( L_101 ) ;
if ( ! V_43 -> V_142 . V_248 )
F_338 ( L_85 ) ;
else if ( V_43 -> V_142 . V_218 )
F_338 ( L_102 ) ;
else
F_338 ( L_86 ) ;
if ( V_43 -> V_142 . V_159 )
F_338 ( L_88 ) ;
else
F_338 ( L_103 ) ;
if ( F_229 ( V_43 -> V_122 ) )
F_338 ( L_104 ) ;
else
F_338 ( L_98 ) ;
break;
case V_329 :
F_338 ( L_105 ,
F_344 ( V_244 , V_216 -> V_249 -> V_23 -> V_330 ) ,
F_344 ( V_326 , V_216 -> V_235 -> V_23 -> V_330 ) ,
( unsigned long ) V_43 -> V_45 ,
( unsigned long long ) V_216 -> V_153 ) ;
F_337 ( & V_216 -> V_224 , V_157 , V_317 , V_318 ) ;
break;
}
return;
V_107:
F_338 ( L_106 ) ;
}
static int F_345 ( struct V_227 * V_155 ,
T_11 F_35 , void * V_331 )
{
struct V_215 * V_216 = V_155 -> V_219 ;
return F_35 ( V_155 , V_216 -> V_235 , 0 , V_155 -> V_51 , V_331 ) ;
}
static void F_346 ( struct V_227 * V_155 , struct V_240 * V_242 )
{
struct V_215 * V_216 = V_155 -> V_219 ;
struct V_43 * V_43 = V_216 -> V_43 ;
T_2 V_332 = V_242 -> V_333 >> V_90 ;
if ( V_242 -> V_334 < V_43 -> V_45 ) {
while ( ! F_246 ( V_43 -> V_45 , V_242 -> V_334 ) ) {
if ( ( V_242 -> V_334 & ( V_242 -> V_334 - 1 ) ) == 0 )
V_242 -> V_334 -- ;
V_242 -> V_334 = F_347 ( V_242 -> V_334 ) ;
}
}
if ( V_332 < V_43 -> V_45 ||
! F_246 ( V_332 , V_43 -> V_45 ) ) {
if ( F_246 ( V_43 -> V_45 , V_242 -> V_334 ) )
F_348 ( V_242 , V_242 -> V_334 << V_90 ) ;
else
F_348 ( V_242 , V_43 -> V_45 << V_90 ) ;
F_349 ( V_242 , V_43 -> V_45 << V_90 ) ;
}
if ( ! V_216 -> V_217 . V_248 ) {
V_242 -> V_335 = 0 ;
return;
}
F_247 ( V_216 ) ;
}
static void F_202 ( struct V_46 * V_47 )
{
F_131 ( & V_47 -> V_336 ) ;
}
static void F_205 ( struct V_46 * V_47 )
{
if ( F_93 ( & V_47 -> V_336 ) )
F_217 ( & V_47 -> V_337 ) ;
}
static void F_350 ( struct V_227 * V_155 )
{
struct V_46 * V_47 = V_155 -> V_219 ;
unsigned long V_27 ;
F_64 ( & V_47 -> V_43 -> V_17 , V_27 ) ;
F_351 ( & V_47 -> V_74 ) ;
F_65 ( & V_47 -> V_43 -> V_17 , V_27 ) ;
F_352 () ;
F_205 ( V_47 ) ;
F_221 ( & V_47 -> V_337 ) ;
F_281 ( & V_71 . V_72 ) ;
F_278 ( V_47 -> V_43 ) ;
F_353 ( V_47 -> V_2 ) ;
F_282 ( V_155 , V_47 -> V_52 ) ;
if ( V_47 -> V_92 )
F_282 ( V_155 , V_47 -> V_92 ) ;
F_260 ( V_47 ) ;
F_283 ( & V_71 . V_72 ) ;
}
static int F_354 ( struct V_227 * V_155 , unsigned V_274 , char * * V_285 )
{
int V_58 ;
struct V_46 * V_47 ;
struct V_136 * V_52 , * V_92 ;
struct V_75 * V_78 ;
unsigned long V_27 ;
F_281 ( & V_71 . V_72 ) ;
if ( V_274 != 2 && V_274 != 3 ) {
V_155 -> error = L_49 ;
V_58 = - V_151 ;
goto V_288;
}
V_47 = V_155 -> V_219 = F_300 ( sizeof( * V_47 ) , V_254 ) ;
if ( ! V_47 ) {
V_155 -> error = L_107 ;
V_58 = - V_38 ;
goto V_288;
}
V_47 -> V_307 = F_301 ( V_155 -> V_156 ) ;
F_273 ( & V_47 -> V_17 ) ;
F_47 ( & V_47 -> V_84 ) ;
F_59 ( & V_47 -> V_85 ) ;
F_59 ( & V_47 -> V_86 ) ;
V_47 -> V_185 = V_338 ;
if ( V_274 == 3 ) {
V_58 = F_297 ( V_155 , V_285 [ 2 ] , V_289 , & V_92 ) ;
if ( V_58 ) {
V_155 -> error = L_108 ;
goto V_339;
}
V_47 -> V_92 = V_92 ;
}
V_58 = F_297 ( V_155 , V_285 [ 0 ] , F_355 ( V_155 -> V_156 ) , & V_52 ) ;
if ( V_58 ) {
V_155 -> error = L_109 ;
goto V_340;
}
V_47 -> V_52 = V_52 ;
if ( F_323 ( V_285 [ 1 ] , ( unsigned long long * ) & V_47 -> V_311 , 0 ) ) {
V_155 -> error = L_110 ;
V_58 = - V_151 ;
goto V_341;
}
V_78 = F_356 ( V_47 -> V_52 -> V_23 -> V_330 ) ;
if ( ! V_78 ) {
V_155 -> error = L_111 ;
V_58 = - V_151 ;
goto V_341;
}
V_47 -> V_43 = F_54 ( V_78 ) ;
if ( ! V_47 -> V_43 ) {
V_155 -> error = L_112 ;
V_58 = - V_151 ;
goto V_342;
}
F_277 ( V_47 -> V_43 ) ;
if ( F_136 ( V_47 -> V_43 ) == V_160 ) {
V_155 -> error = L_113 ;
V_58 = - V_151 ;
goto V_255;
}
V_58 = F_357 ( V_47 -> V_43 -> V_122 , V_47 -> V_311 , & V_47 -> V_2 ) ;
if ( V_58 ) {
V_155 -> error = L_114 ;
goto V_255;
}
V_58 = F_358 ( V_155 , V_47 -> V_43 -> V_45 ) ;
if ( V_58 )
goto V_343;
V_155 -> V_296 = 1 ;
V_155 -> V_344 = true ;
V_155 -> V_345 = sizeof( struct V_96 ) ;
V_155 -> V_297 = true ;
if ( V_47 -> V_43 -> V_142 . V_248 ) {
V_155 -> V_299 = true ;
V_155 -> V_298 = 1 ;
V_155 -> V_346 = false ;
}
F_283 ( & V_71 . V_72 ) ;
F_64 ( & V_47 -> V_43 -> V_17 , V_27 ) ;
if ( V_47 -> V_43 -> V_262 ) {
F_65 ( & V_47 -> V_43 -> V_17 , V_27 ) ;
F_281 ( & V_71 . V_72 ) ;
V_155 -> error = L_115 ;
V_58 = - V_151 ;
goto V_343;
}
F_128 ( & V_47 -> V_336 , 1 ) ;
F_220 ( & V_47 -> V_337 ) ;
F_359 ( & V_47 -> V_74 , & V_47 -> V_43 -> V_201 ) ;
F_65 ( & V_47 -> V_43 -> V_17 , V_27 ) ;
F_352 () ;
F_360 ( V_78 ) ;
return 0 ;
V_343:
F_353 ( V_47 -> V_2 ) ;
V_255:
F_278 ( V_47 -> V_43 ) ;
V_342:
F_360 ( V_78 ) ;
V_341:
F_282 ( V_155 , V_47 -> V_52 ) ;
V_340:
if ( V_47 -> V_92 )
F_282 ( V_155 , V_47 -> V_92 ) ;
V_339:
F_260 ( V_47 ) ;
V_288:
F_283 ( & V_71 . V_72 ) ;
return V_58 ;
}
static int F_361 ( struct V_227 * V_155 , struct V_28 * V_28 )
{
V_28 -> V_39 . V_40 = F_362 ( V_155 , V_28 -> V_39 . V_40 ) ;
return F_240 ( V_155 , V_28 ) ;
}
static int F_363 ( struct V_227 * V_155 , struct V_28 * V_28 , int V_107 )
{
unsigned long V_27 ;
struct V_96 * V_97 = F_83 ( V_28 , sizeof( struct V_96 ) ) ;
struct V_82 V_308 ;
struct V_101 * V_102 , * V_77 ;
struct V_43 * V_43 = V_97 -> V_47 -> V_43 ;
if ( V_97 -> V_173 ) {
F_47 ( & V_308 ) ;
F_364 ( V_97 -> V_173 , & V_308 ) ;
F_64 ( & V_43 -> V_17 , V_27 ) ;
F_68 (m, tmp, &work, list) {
F_53 ( & V_102 -> V_74 ) ;
F_92 ( V_102 ) ;
}
F_65 ( & V_43 -> V_17 , V_27 ) ;
}
if ( V_97 -> V_98 ) {
F_47 ( & V_308 ) ;
F_364 ( V_97 -> V_98 , & V_308 ) ;
if ( ! F_198 ( & V_308 ) ) {
F_64 ( & V_43 -> V_17 , V_27 ) ;
F_68 (m, tmp, &work, list)
F_94 ( & V_102 -> V_74 , & V_43 -> V_206 ) ;
F_65 ( & V_43 -> V_17 , V_27 ) ;
F_26 ( V_43 ) ;
}
}
if ( V_97 -> V_62 )
F_98 ( V_97 -> V_47 , V_97 -> V_62 ) ;
return 0 ;
}
static void F_365 ( struct V_227 * V_155 )
{
struct V_46 * V_47 = V_155 -> V_219 ;
if ( F_366 ( V_155 ) )
V_211 ( V_47 , F_223 ) ;
}
static void F_367 ( struct V_227 * V_155 )
{
struct V_46 * V_47 = V_155 -> V_219 ;
V_211 ( V_47 , F_224 ) ;
}
static int F_368 ( struct V_227 * V_155 )
{
struct V_46 * V_47 = V_155 -> V_219 ;
if ( V_47 -> V_92 )
V_47 -> V_146 = F_288 ( V_47 -> V_92 -> V_23 ) ;
return 0 ;
}
static void F_369 ( struct V_227 * V_155 , T_9 type ,
unsigned V_319 , char * V_157 , unsigned V_318 )
{
int V_58 ;
T_12 V_317 = 0 ;
T_1 V_347 , V_348 ;
char V_244 [ V_245 ] ;
struct V_46 * V_47 = V_155 -> V_219 ;
if ( F_136 ( V_47 -> V_43 ) == V_160 ) {
F_338 ( L_89 ) ;
return;
}
if ( ! V_47 -> V_2 )
F_338 ( L_116 ) ;
else {
switch ( type ) {
case V_327 :
V_58 = F_370 ( V_47 -> V_2 , & V_347 ) ;
if ( V_58 ) {
F_231 ( L_117 , V_58 ) ;
goto V_107;
}
V_58 = F_371 ( V_47 -> V_2 , & V_348 ) ;
if ( V_58 < 0 ) {
F_231 ( L_118 , V_58 ) ;
goto V_107;
}
F_338 ( L_97 , V_347 * V_47 -> V_43 -> V_45 ) ;
if ( V_58 )
F_338 ( L_119 , ( ( V_348 + 1 ) *
V_47 -> V_43 -> V_45 ) - 1 ) ;
else
F_338 ( L_116 ) ;
break;
case V_329 :
F_338 ( L_120 ,
F_344 ( V_244 , V_47 -> V_52 -> V_23 -> V_330 ) ,
( unsigned long ) V_47 -> V_311 ) ;
if ( V_47 -> V_92 )
F_338 ( L_121 , F_344 ( V_244 , V_47 -> V_92 -> V_23 -> V_330 ) ) ;
break;
}
}
return;
V_107:
F_338 ( L_106 ) ;
}
static int F_372 ( struct V_227 * V_155 ,
T_11 F_35 , void * V_331 )
{
T_2 V_349 ;
struct V_46 * V_47 = V_155 -> V_219 ;
struct V_43 * V_43 = V_47 -> V_43 ;
if ( ! V_43 -> V_155 )
return 0 ;
V_349 = V_43 -> V_155 -> V_51 ;
( void ) F_76 ( V_349 , V_43 -> V_45 ) ;
if ( V_349 )
return F_35 ( V_155 , V_47 -> V_52 , 0 , V_43 -> V_45 * V_349 , V_331 ) ;
return 0 ;
}
static void F_373 ( struct V_227 * V_155 , struct V_240 * V_242 )
{
struct V_46 * V_47 = V_155 -> V_219 ;
struct V_43 * V_43 = V_47 -> V_43 ;
if ( ! V_43 -> V_142 . V_248 )
return;
V_242 -> V_335 = V_43 -> V_45 << V_90 ;
V_242 -> V_246 = 2048 * 1024 * 16 ;
}
static int T_13 F_374 ( void )
{
int V_58 ;
F_45 () ;
V_58 = F_375 ( & V_350 ) ;
if ( V_58 )
return V_58 ;
V_58 = F_375 ( & V_351 ) ;
if ( V_58 )
goto V_352;
V_58 = - V_38 ;
V_266 = F_376 ( V_101 , 0 ) ;
if ( ! V_266 )
goto V_353;
return 0 ;
V_353:
F_377 ( & V_351 ) ;
V_352:
F_377 ( & V_350 ) ;
return V_58 ;
}
static void F_378 ( void )
{
F_377 ( & V_350 ) ;
F_377 ( & V_351 ) ;
F_379 ( V_266 ) ;
}
