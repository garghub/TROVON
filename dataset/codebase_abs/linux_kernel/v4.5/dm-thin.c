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
static void F_41 ( struct V_43 * V_43 , struct V_56 * V_62 )
{
F_39 ( V_43 , V_62 , - V_67 ) ;
}
static void F_42 ( struct V_43 * V_43 , struct V_56 * V_62 )
{
F_39 ( V_43 , V_62 , 0 ) ;
}
static void F_43 ( struct V_43 * V_43 , struct V_56 * V_62 )
{
F_39 ( V_43 , V_62 , V_68 ) ;
}
static void F_44 ( void )
{
F_45 ( & V_69 . V_70 ) ;
F_46 ( & V_69 . V_71 ) ;
}
static void F_47 ( struct V_43 * V_43 )
{
F_48 ( ! F_49 ( & V_69 . V_70 ) ) ;
F_50 ( & V_43 -> V_72 , & V_69 . V_71 ) ;
}
static void F_51 ( struct V_43 * V_43 )
{
F_48 ( ! F_49 ( & V_69 . V_70 ) ) ;
F_52 ( & V_43 -> V_72 ) ;
}
static struct V_43 * F_53 ( struct V_73 * V_74 )
{
struct V_43 * V_43 = NULL , * V_75 ;
F_48 ( ! F_49 ( & V_69 . V_70 ) ) ;
F_54 (tmp, &dm_thin_pool_table.pools, list) {
if ( V_75 -> V_76 == V_74 ) {
V_43 = V_75 ;
break;
}
}
return V_43 ;
}
static struct V_43 * F_55 ( struct V_22 * V_77 )
{
struct V_43 * V_43 = NULL , * V_75 ;
F_48 ( ! F_49 ( & V_69 . V_70 ) ) ;
F_54 (tmp, &dm_thin_pool_table.pools, list) {
if ( V_75 -> V_77 == V_77 ) {
V_43 = V_75 ;
break;
}
}
return V_43 ;
}
static void F_56 ( struct V_63 * V_64 , struct V_63 * V_78 )
{
F_57 ( V_64 , V_78 ) ;
F_58 ( V_78 ) ;
}
static void F_59 ( struct V_63 * V_64 , int error )
{
struct V_28 * V_28 ;
while ( ( V_28 = F_60 ( V_64 ) ) ) {
V_28 -> V_79 = error ;
F_61 ( V_28 ) ;
}
}
static void F_62 ( struct V_46 * V_47 , struct V_63 * V_78 , int error )
{
struct V_63 V_64 ;
unsigned long V_27 ;
F_58 ( & V_64 ) ;
F_63 ( & V_47 -> V_17 , V_27 ) ;
F_56 ( & V_64 , V_78 ) ;
F_64 ( & V_47 -> V_17 , V_27 ) ;
F_59 ( & V_64 , error ) ;
}
static void F_65 ( struct V_46 * V_47 )
{
struct V_43 * V_43 = V_47 -> V_43 ;
unsigned long V_27 ;
struct V_80 V_81 ;
struct V_56 * V_62 , * V_75 ;
F_46 ( & V_81 ) ;
F_63 ( & V_47 -> V_17 , V_27 ) ;
F_66 ( & V_47 -> V_82 , & V_81 ) ;
F_64 ( & V_47 -> V_17 , V_27 ) ;
F_67 (cell, tmp, &cells, user_list)
F_43 ( V_43 , V_62 ) ;
}
static void F_68 ( struct V_46 * V_47 )
{
struct V_63 V_64 ;
unsigned long V_27 ;
F_58 ( & V_64 ) ;
F_63 ( & V_47 -> V_17 , V_27 ) ;
F_56 ( & V_64 , & V_47 -> V_83 ) ;
F_56 ( & V_64 , & V_47 -> V_84 ) ;
F_64 ( & V_47 -> V_17 , V_27 ) ;
F_59 ( & V_64 , V_68 ) ;
F_65 ( V_47 ) ;
}
static void F_69 ( struct V_43 * V_43 , int error )
{
struct V_46 * V_47 ;
F_70 () ;
F_71 (tc, &pool->active_thins, list)
F_62 ( V_47 , & V_47 -> V_84 , error ) ;
F_72 () ;
}
static void F_73 ( struct V_43 * V_43 )
{
return F_69 ( V_43 , - V_67 ) ;
}
static T_1 F_74 ( struct V_46 * V_47 , struct V_28 * V_28 )
{
struct V_43 * V_43 = V_47 -> V_43 ;
T_2 V_85 = V_28 -> V_39 . V_40 ;
if ( F_23 ( V_43 ) )
V_85 >>= V_43 -> V_44 ;
else
( void ) F_75 ( V_85 , V_43 -> V_45 ) ;
return V_85 ;
}
static void F_76 ( struct V_46 * V_47 , struct V_28 * V_28 ,
T_1 * V_86 , T_1 * V_87 )
{
struct V_43 * V_43 = V_47 -> V_43 ;
T_2 V_5 = V_28 -> V_39 . V_40 ;
T_2 V_6 = V_5 + ( V_28 -> V_39 . V_42 >> V_88 ) ;
V_5 += V_43 -> V_45 - 1ull ;
if ( F_23 ( V_43 ) ) {
V_5 >>= V_43 -> V_44 ;
V_6 >>= V_43 -> V_44 ;
} else {
( void ) F_75 ( V_5 , V_43 -> V_45 ) ;
( void ) F_75 ( V_6 , V_43 -> V_45 ) ;
}
if ( V_6 < V_5 )
V_6 = V_5 ;
* V_86 = V_5 ;
* V_87 = V_6 ;
}
static void F_77 ( struct V_46 * V_47 , struct V_28 * V_28 , T_1 V_89 )
{
struct V_43 * V_43 = V_47 -> V_43 ;
T_2 V_40 = V_28 -> V_39 . V_40 ;
V_28 -> V_41 = V_47 -> V_52 -> V_23 ;
if ( F_23 ( V_43 ) )
V_28 -> V_39 . V_40 =
( V_89 << V_43 -> V_44 ) |
( V_40 & ( V_43 -> V_45 - 1 ) ) ;
else
V_28 -> V_39 . V_40 = ( V_89 * V_43 -> V_45 ) +
F_75 ( V_40 , V_43 -> V_45 ) ;
}
static void F_78 ( struct V_46 * V_47 , struct V_28 * V_28 )
{
V_28 -> V_41 = V_47 -> V_90 -> V_23 ;
}
static int F_79 ( struct V_46 * V_47 , struct V_28 * V_28 )
{
return ( V_28 -> V_91 & ( V_92 | V_93 ) ) &&
F_80 ( V_47 -> V_2 ) ;
}
static void F_81 ( struct V_43 * V_43 , struct V_28 * V_28 )
{
struct V_94 * V_95 ;
if ( V_28 -> V_91 & V_33 )
return;
V_95 = F_82 ( V_28 , sizeof( struct V_94 ) ) ;
V_95 -> V_96 = F_83 ( V_43 -> V_97 ) ;
}
static void F_84 ( struct V_46 * V_47 , struct V_28 * V_28 )
{
struct V_43 * V_43 = V_47 -> V_43 ;
unsigned long V_27 ;
if ( ! F_79 ( V_47 , V_28 ) ) {
F_85 ( V_28 ) ;
return;
}
if ( F_86 ( V_47 -> V_2 ) ) {
F_87 ( V_28 ) ;
return;
}
F_63 ( & V_43 -> V_17 , V_27 ) ;
F_88 ( & V_43 -> V_98 , V_28 ) ;
F_64 ( & V_43 -> V_17 , V_27 ) ;
}
static void F_89 ( struct V_46 * V_47 , struct V_28 * V_28 )
{
F_78 ( V_47 , V_28 ) ;
F_84 ( V_47 , V_28 ) ;
}
static void F_90 ( struct V_46 * V_47 , struct V_28 * V_28 ,
T_1 V_89 )
{
F_77 ( V_47 , V_28 , V_89 ) ;
F_84 ( V_47 , V_28 ) ;
}
static void F_91 ( struct V_99 * V_100 )
{
struct V_43 * V_43 = V_100 -> V_47 -> V_43 ;
if ( F_92 ( & V_100 -> V_101 ) ) {
F_93 ( & V_100 -> V_72 , & V_43 -> V_102 ) ;
F_26 ( V_43 ) ;
}
}
static void F_94 ( struct V_99 * V_100 )
{
unsigned long V_27 ;
struct V_43 * V_43 = V_100 -> V_47 -> V_43 ;
F_63 ( & V_43 -> V_17 , V_27 ) ;
F_91 ( V_100 ) ;
F_64 ( & V_43 -> V_17 , V_27 ) ;
}
static void F_95 ( int V_103 , unsigned long V_104 , void * V_65 )
{
struct V_99 * V_100 = V_65 ;
V_100 -> V_105 = V_103 || V_104 ? - V_67 : 0 ;
F_94 ( V_100 ) ;
}
static void F_96 ( struct V_28 * V_28 )
{
struct V_94 * V_95 = F_82 ( V_28 , sizeof( struct V_94 ) ) ;
struct V_99 * V_100 = V_95 -> V_106 ;
V_28 -> V_107 = V_100 -> V_108 ;
V_100 -> V_105 = V_28 -> V_79 ;
F_94 ( V_100 ) ;
}
static void F_97 ( struct V_46 * V_47 , struct V_56 * V_62 )
{
struct V_43 * V_43 = V_47 -> V_43 ;
unsigned long V_27 ;
F_63 ( & V_47 -> V_17 , V_27 ) ;
F_37 ( V_43 , V_62 , & V_47 -> V_83 ) ;
F_64 ( & V_47 -> V_17 , V_27 ) ;
F_26 ( V_43 ) ;
}
static void F_98 ( void * V_65 ,
struct V_56 * V_62 )
{
struct V_109 * V_110 = V_65 ;
struct V_28 * V_28 ;
while ( ( V_28 = F_60 ( & V_62 -> V_64 ) ) ) {
if ( V_28 -> V_91 & ( V_33 | V_92 | V_93 ) )
F_88 ( & V_110 -> V_111 , V_28 ) ;
else {
F_81 ( V_110 -> V_47 -> V_43 , V_28 ) ;
F_88 ( & V_110 -> V_112 , V_28 ) ;
}
}
}
static void F_99 ( struct V_46 * V_47 ,
struct V_56 * V_62 ,
T_1 V_89 )
{
struct V_28 * V_28 ;
struct V_109 V_110 ;
V_110 . V_47 = V_47 ;
F_58 ( & V_110 . V_111 ) ;
F_58 ( & V_110 . V_112 ) ;
F_34 ( V_47 -> V_43 , F_98 ,
& V_110 , V_62 ) ;
while ( ( V_28 = F_60 ( & V_110 . V_111 ) ) )
F_100 ( V_47 , V_28 ) ;
while ( ( V_28 = F_60 ( & V_110 . V_112 ) ) )
F_90 ( V_110 . V_47 , V_28 , V_89 ) ;
}
static void F_101 ( struct V_99 * V_100 )
{
F_41 ( V_100 -> V_47 -> V_43 , V_100 -> V_62 ) ;
F_52 ( & V_100 -> V_72 ) ;
F_102 ( V_100 , V_100 -> V_47 -> V_43 -> V_113 ) ;
}
static void F_103 ( struct V_99 * V_100 )
{
struct V_46 * V_47 = V_100 -> V_47 ;
struct V_43 * V_43 = V_47 -> V_43 ;
struct V_28 * V_28 = V_100 -> V_28 ;
int V_58 ;
if ( V_100 -> V_105 ) {
F_41 ( V_43 , V_100 -> V_62 ) ;
goto V_114;
}
V_58 = F_104 ( V_47 -> V_2 , V_100 -> V_115 , V_100 -> V_116 ) ;
if ( V_58 ) {
F_105 ( V_43 , L_1 , V_58 ) ;
F_41 ( V_43 , V_100 -> V_62 ) ;
goto V_114;
}
if ( V_28 ) {
F_99 ( V_47 , V_100 -> V_62 , V_100 -> V_116 ) ;
F_61 ( V_28 ) ;
} else {
F_81 ( V_47 -> V_43 , V_100 -> V_62 -> V_117 ) ;
F_90 ( V_47 , V_100 -> V_62 -> V_117 , V_100 -> V_116 ) ;
F_99 ( V_47 , V_100 -> V_62 , V_100 -> V_116 ) ;
}
V_114:
F_52 ( & V_100 -> V_72 ) ;
F_102 ( V_100 , V_43 -> V_113 ) ;
}
static void F_106 ( struct V_99 * V_100 )
{
struct V_46 * V_47 = V_100 -> V_47 ;
if ( V_100 -> V_62 )
F_97 ( V_47 , V_100 -> V_62 ) ;
F_102 ( V_100 , V_47 -> V_43 -> V_113 ) ;
}
static void F_107 ( struct V_99 * V_100 )
{
F_87 ( V_100 -> V_28 ) ;
F_106 ( V_100 ) ;
}
static void F_108 ( struct V_99 * V_100 )
{
F_61 ( V_100 -> V_28 ) ;
F_106 ( V_100 ) ;
}
static void F_109 ( struct V_99 * V_100 )
{
int V_58 ;
struct V_46 * V_47 = V_100 -> V_47 ;
V_58 = F_110 ( V_47 -> V_2 , V_100 -> V_62 -> V_8 . V_12 , V_100 -> V_62 -> V_8 . V_13 ) ;
if ( V_58 ) {
F_105 ( V_47 -> V_43 , L_2 , V_58 ) ;
F_87 ( V_100 -> V_28 ) ;
} else
F_61 ( V_100 -> V_28 ) ;
F_97 ( V_47 , V_100 -> V_62 ) ;
F_102 ( V_100 , V_47 -> V_43 -> V_113 ) ;
}
static int F_111 ( struct V_99 * V_100 )
{
int V_58 ;
bool V_118 = true ;
struct V_46 * V_47 = V_100 -> V_47 ;
struct V_43 * V_43 = V_47 -> V_43 ;
T_1 V_5 = V_100 -> V_116 , V_6 , V_87 = V_100 -> V_116 + V_100 -> V_119 - V_100 -> V_115 ;
while ( V_5 != V_87 ) {
for (; V_5 < V_87 ; V_5 ++ ) {
V_58 = F_112 ( V_43 -> V_120 , V_5 , & V_118 ) ;
if ( V_58 )
return V_58 ;
if ( ! V_118 )
break;
}
if ( V_5 == V_87 )
break;
for ( V_6 = V_5 + 1 ; V_6 != V_87 ; V_6 ++ ) {
V_58 = F_112 ( V_43 -> V_120 , V_6 , & V_118 ) ;
if ( V_58 )
return V_58 ;
if ( V_118 )
break;
}
V_58 = F_25 ( V_47 , V_5 , V_6 , V_100 -> V_28 ) ;
if ( V_58 )
return V_58 ;
V_5 = V_6 ;
}
return 0 ;
}
static void F_113 ( struct V_99 * V_100 )
{
int V_58 ;
struct V_46 * V_47 = V_100 -> V_47 ;
struct V_43 * V_43 = V_47 -> V_43 ;
V_58 = F_110 ( V_47 -> V_2 , V_100 -> V_115 , V_100 -> V_119 ) ;
if ( V_58 )
F_105 ( V_43 , L_2 , V_58 ) ;
else if ( V_100 -> V_121 )
V_58 = F_111 ( V_100 ) ;
else
V_58 = F_25 ( V_47 , V_100 -> V_116 , V_100 -> V_116 + ( V_100 -> V_119 - V_100 -> V_115 ) , V_100 -> V_28 ) ;
V_100 -> V_28 -> V_79 = V_58 ;
F_61 ( V_100 -> V_28 ) ;
F_97 ( V_47 , V_100 -> V_62 ) ;
F_102 ( V_100 , V_43 -> V_113 ) ;
}
static void F_114 ( struct V_43 * V_43 , struct V_80 * V_122 ,
T_4 * F_35 )
{
unsigned long V_27 ;
struct V_80 V_123 ;
struct V_99 * V_100 , * V_75 ;
F_46 ( & V_123 ) ;
F_63 ( & V_43 -> V_17 , V_27 ) ;
F_66 ( V_122 , & V_123 ) ;
F_64 ( & V_43 -> V_17 , V_27 ) ;
F_67 ( V_100 , V_75 , & V_123 , V_72 )
( * F_35 ) ( V_100 ) ;
}
static int F_115 ( struct V_43 * V_43 , struct V_28 * V_28 )
{
return V_28 -> V_39 . V_42 ==
( V_43 -> V_45 << V_88 ) ;
}
static int F_116 ( struct V_43 * V_43 , struct V_28 * V_28 )
{
return ( F_117 ( V_28 ) == V_124 ) &&
F_115 ( V_43 , V_28 ) ;
}
static void F_118 ( struct V_28 * V_28 , T_5 * * V_125 ,
T_5 * F_35 )
{
* V_125 = V_28 -> V_107 ;
V_28 -> V_107 = F_35 ;
}
static int F_119 ( struct V_43 * V_43 )
{
if ( V_43 -> V_126 )
return 0 ;
V_43 -> V_126 = F_120 ( V_43 -> V_113 , V_127 ) ;
return V_43 -> V_126 ? 0 : - V_38 ;
}
static struct V_99 * F_121 ( struct V_43 * V_43 )
{
struct V_99 * V_100 = V_43 -> V_126 ;
F_48 ( ! V_43 -> V_126 ) ;
memset ( V_100 , 0 , sizeof( struct V_99 ) ) ;
F_46 ( & V_100 -> V_72 ) ;
V_100 -> V_28 = NULL ;
V_43 -> V_126 = NULL ;
return V_100 ;
}
static void F_122 ( struct V_46 * V_47 , struct V_99 * V_100 ,
T_2 V_86 , T_2 V_87 )
{
int V_58 ;
struct V_128 V_129 ;
V_129 . V_23 = V_47 -> V_52 -> V_23 ;
V_129 . V_24 = V_86 ;
V_129 . V_130 = V_87 - V_86 ;
V_58 = F_123 ( V_47 -> V_43 -> V_131 , 1 , & V_129 , 0 , F_95 , V_100 ) ;
if ( V_58 < 0 ) {
F_124 ( L_3 ) ;
F_95 ( 1 , 1 , V_100 ) ;
}
}
static void F_125 ( struct V_46 * V_47 , struct V_28 * V_28 ,
T_1 V_132 ,
struct V_99 * V_100 )
{
struct V_43 * V_43 = V_47 -> V_43 ;
struct V_94 * V_95 = F_82 ( V_28 , sizeof( struct V_94 ) ) ;
V_95 -> V_106 = V_100 ;
V_100 -> V_28 = V_28 ;
F_118 ( V_28 , & V_100 -> V_108 , F_96 ) ;
F_81 ( V_43 , V_28 ) ;
F_90 ( V_47 , V_28 , V_132 ) ;
}
static void F_126 ( struct V_46 * V_47 , T_1 V_133 ,
struct V_134 * V_135 , T_1 V_136 ,
T_1 V_137 ,
struct V_56 * V_62 , struct V_28 * V_28 ,
T_2 V_51 )
{
int V_58 ;
struct V_43 * V_43 = V_47 -> V_43 ;
struct V_99 * V_100 = F_121 ( V_43 ) ;
V_100 -> V_47 = V_47 ;
V_100 -> V_115 = V_133 ;
V_100 -> V_119 = V_133 + 1u ;
V_100 -> V_116 = V_137 ;
V_100 -> V_62 = V_62 ;
F_127 ( & V_100 -> V_101 , 3 ) ;
if ( ! F_128 ( V_43 -> V_138 , & V_100 -> V_72 ) )
F_94 ( V_100 ) ;
if ( F_116 ( V_43 , V_28 ) )
F_125 ( V_47 , V_28 , V_137 , V_100 ) ;
else {
struct V_128 V_139 , V_129 ;
V_139 . V_23 = V_135 -> V_23 ;
V_139 . V_24 = V_136 * V_43 -> V_45 ;
V_139 . V_130 = V_51 ;
V_129 . V_23 = V_47 -> V_52 -> V_23 ;
V_129 . V_24 = V_137 * V_43 -> V_45 ;
V_129 . V_130 = V_51 ;
V_58 = F_129 ( V_43 -> V_131 , & V_139 , 1 , & V_129 ,
0 , F_95 , V_100 ) ;
if ( V_58 < 0 ) {
F_124 ( L_4 ) ;
F_95 ( 1 , 1 , V_100 ) ;
}
if ( V_51 < V_43 -> V_45 && V_43 -> V_140 . V_141 ) {
F_130 ( & V_100 -> V_101 ) ;
F_122 ( V_47 , V_100 ,
V_137 * V_43 -> V_45 + V_51 ,
( V_137 + 1 ) * V_43 -> V_45 ) ;
}
}
F_94 ( V_100 ) ;
}
static void F_131 ( struct V_46 * V_47 , T_1 V_133 ,
T_1 V_136 , T_1 V_137 ,
struct V_56 * V_62 , struct V_28 * V_28 )
{
F_126 ( V_47 , V_133 , V_47 -> V_52 ,
V_136 , V_137 , V_62 , V_28 ,
V_47 -> V_43 -> V_45 ) ;
}
static void F_132 ( struct V_46 * V_47 , T_1 V_133 ,
T_1 V_116 , struct V_56 * V_62 ,
struct V_28 * V_28 )
{
struct V_43 * V_43 = V_47 -> V_43 ;
struct V_99 * V_100 = F_121 ( V_43 ) ;
F_127 ( & V_100 -> V_101 , 1 ) ;
V_100 -> V_47 = V_47 ;
V_100 -> V_115 = V_133 ;
V_100 -> V_119 = V_133 + 1u ;
V_100 -> V_116 = V_116 ;
V_100 -> V_62 = V_62 ;
if ( V_43 -> V_140 . V_141 ) {
if ( F_116 ( V_43 , V_28 ) )
F_125 ( V_47 , V_28 , V_116 , V_100 ) ;
else
F_122 ( V_47 , V_100 , V_116 * V_43 -> V_45 ,
( V_116 + 1 ) * V_43 -> V_45 ) ;
} else
F_103 ( V_100 ) ;
}
static void F_133 ( struct V_46 * V_47 , T_1 V_133 ,
T_1 V_137 ,
struct V_56 * V_62 , struct V_28 * V_28 )
{
struct V_43 * V_43 = V_47 -> V_43 ;
T_2 V_142 = V_133 * V_43 -> V_45 ;
T_2 V_143 = ( V_133 + 1 ) * V_43 -> V_45 ;
if ( V_143 <= V_47 -> V_144 )
F_126 ( V_47 , V_133 , V_47 -> V_90 ,
V_133 , V_137 , V_62 , V_28 ,
V_43 -> V_45 ) ;
else if ( V_142 < V_47 -> V_144 )
F_126 ( V_47 , V_133 , V_47 -> V_90 ,
V_133 , V_137 , V_62 , V_28 ,
V_47 -> V_144 - V_142 ) ;
else
F_132 ( V_47 , V_133 , V_137 , V_62 , V_28 ) ;
}
static void F_134 ( struct V_43 * V_43 )
{
int V_58 ;
T_1 V_145 ;
if ( F_135 ( V_43 ) != V_146 )
return;
V_58 = F_136 ( V_43 -> V_120 , & V_145 ) ;
if ( V_58 )
return;
if ( V_145 )
F_137 ( V_43 , V_147 ) ;
}
static int F_138 ( struct V_43 * V_43 )
{
int V_58 ;
if ( F_135 ( V_43 ) >= V_148 )
return - V_149 ;
V_58 = F_139 ( V_43 -> V_120 ) ;
if ( V_58 )
F_105 ( V_43 , L_5 , V_58 ) ;
else
F_134 ( V_43 ) ;
return V_58 ;
}
static void F_140 ( struct V_43 * V_43 , T_1 V_150 )
{
unsigned long V_27 ;
if ( V_150 <= V_43 -> V_151 && ! V_43 -> V_152 ) {
F_141 ( L_6 ,
F_142 ( V_43 -> V_76 ) ) ;
F_63 ( & V_43 -> V_17 , V_27 ) ;
V_43 -> V_152 = true ;
F_64 ( & V_43 -> V_17 , V_27 ) ;
F_143 ( V_43 -> V_153 -> V_154 ) ;
}
}
static int F_144 ( struct V_46 * V_47 , T_1 * V_155 )
{
int V_58 ;
T_1 V_150 ;
struct V_43 * V_43 = V_47 -> V_43 ;
if ( F_145 ( F_135 ( V_43 ) != V_147 ) )
return - V_149 ;
V_58 = F_136 ( V_43 -> V_120 , & V_150 ) ;
if ( V_58 ) {
F_105 ( V_43 , L_7 , V_58 ) ;
return V_58 ;
}
F_140 ( V_43 , V_150 ) ;
if ( ! V_150 ) {
V_58 = F_138 ( V_43 ) ;
if ( V_58 )
return V_58 ;
V_58 = F_136 ( V_43 -> V_120 , & V_150 ) ;
if ( V_58 ) {
F_105 ( V_43 , L_7 , V_58 ) ;
return V_58 ;
}
if ( ! V_150 ) {
F_137 ( V_43 , V_146 ) ;
return - V_156 ;
}
}
V_58 = F_146 ( V_43 -> V_120 , V_155 ) ;
if ( V_58 ) {
F_105 ( V_43 , L_8 , V_58 ) ;
return V_58 ;
}
return 0 ;
}
static void F_147 ( struct V_28 * V_28 )
{
struct V_94 * V_95 = F_82 ( V_28 , sizeof( struct V_94 ) ) ;
struct V_46 * V_47 = V_95 -> V_47 ;
unsigned long V_27 ;
F_63 ( & V_47 -> V_17 , V_27 ) ;
F_88 ( & V_47 -> V_84 , V_28 ) ;
F_64 ( & V_47 -> V_17 , V_27 ) ;
}
static int F_148 ( struct V_43 * V_43 )
{
enum V_157 V_100 = F_135 ( V_43 ) ;
switch ( V_100 ) {
case V_147 :
F_124 ( L_9 ) ;
return - V_67 ;
case V_146 :
return V_43 -> V_140 . V_158 ? - V_156 : 0 ;
case V_148 :
case V_159 :
return - V_67 ;
default:
F_124 ( L_10 ) ;
return - V_67 ;
}
}
static void F_149 ( struct V_43 * V_43 , struct V_28 * V_28 )
{
int error = F_148 ( V_43 ) ;
if ( error ) {
V_28 -> V_79 = error ;
F_61 ( V_28 ) ;
} else
F_147 ( V_28 ) ;
}
static void F_150 ( struct V_43 * V_43 , struct V_56 * V_62 )
{
struct V_28 * V_28 ;
struct V_63 V_64 ;
int error ;
error = F_148 ( V_43 ) ;
if ( error ) {
F_39 ( V_43 , V_62 , error ) ;
return;
}
F_58 ( & V_64 ) ;
F_32 ( V_43 , V_62 , & V_64 ) ;
while ( ( V_28 = F_60 ( & V_64 ) ) )
F_147 ( V_28 ) ;
}
static void F_151 ( struct V_46 * V_47 ,
struct V_56 * V_160 )
{
struct V_43 * V_43 = V_47 -> V_43 ;
struct V_99 * V_100 = F_121 ( V_43 ) ;
V_100 -> V_47 = V_47 ;
V_100 -> V_115 = V_160 -> V_8 . V_12 ;
V_100 -> V_119 = V_160 -> V_8 . V_13 ;
V_100 -> V_62 = V_160 ;
V_100 -> V_28 = V_160 -> V_117 ;
if ( ! F_128 ( V_43 -> V_97 , & V_100 -> V_72 ) )
V_43 -> V_161 ( V_100 ) ;
}
static inline void F_152 ( struct V_28 * V_28 )
{
V_28 -> V_162 |= ( 1 << V_163 ) ;
F_153 () ;
F_130 ( & V_28 -> V_164 ) ;
}
static void F_154 ( struct V_46 * V_47 , T_1 V_86 , T_1 V_87 ,
struct V_28 * V_28 )
{
struct V_43 * V_43 = V_47 -> V_43 ;
int V_58 ;
bool V_121 ;
struct V_7 V_165 ;
struct V_56 * V_166 ;
struct V_99 * V_100 ;
T_1 V_115 , V_119 , V_132 ;
while ( V_86 != V_87 ) {
V_58 = F_119 ( V_43 ) ;
if ( V_58 )
return;
V_58 = F_155 ( V_47 -> V_2 , V_86 , V_87 , & V_115 , & V_119 ,
& V_132 , & V_121 ) ;
if ( V_58 )
break;
F_1 ( V_47 -> V_2 , V_14 , V_132 , V_132 + ( V_119 - V_115 ) , & V_165 ) ;
if ( F_28 ( V_47 -> V_43 , & V_165 , NULL , & V_166 ) ) {
V_86 = V_119 ;
continue;
}
V_100 = F_121 ( V_43 ) ;
V_100 -> V_47 = V_47 ;
V_100 -> V_121 = V_121 ;
V_100 -> V_115 = V_115 ;
V_100 -> V_119 = V_119 ;
V_100 -> V_116 = V_132 ;
V_100 -> V_62 = V_166 ;
V_100 -> V_28 = V_28 ;
F_152 ( V_28 ) ;
if ( ! F_128 ( V_43 -> V_97 , & V_100 -> V_72 ) )
V_43 -> V_161 ( V_100 ) ;
V_86 = V_119 ;
}
}
static void F_156 ( struct V_46 * V_47 , struct V_56 * V_160 )
{
struct V_28 * V_28 = V_160 -> V_117 ;
struct V_94 * V_95 = F_82 ( V_28 , sizeof( struct V_94 ) ) ;
V_95 -> V_62 = V_160 ;
F_154 ( V_47 , V_160 -> V_8 . V_12 , V_160 -> V_8 . V_13 , V_28 ) ;
F_61 ( V_28 ) ;
}
static void F_157 ( struct V_46 * V_47 , struct V_28 * V_28 )
{
T_1 V_86 , V_87 ;
struct V_7 V_167 ;
struct V_56 * V_160 ;
F_76 ( V_47 , V_28 , & V_86 , & V_87 ) ;
if ( V_86 == V_87 ) {
F_61 ( V_28 ) ;
return;
}
F_1 ( V_47 -> V_2 , V_10 , V_86 , V_87 , & V_167 ) ;
if ( F_28 ( V_47 -> V_43 , & V_167 , V_28 , & V_160 ) )
return;
V_47 -> V_43 -> V_168 ( V_47 , V_160 ) ;
}
static void F_158 ( struct V_46 * V_47 , struct V_28 * V_28 , T_1 V_89 ,
struct V_7 * V_8 ,
struct V_169 * V_170 ,
struct V_56 * V_62 )
{
int V_58 ;
T_1 V_116 ;
struct V_43 * V_43 = V_47 -> V_43 ;
V_58 = F_144 ( V_47 , & V_116 ) ;
switch ( V_58 ) {
case 0 :
F_131 ( V_47 , V_89 , V_170 -> V_89 ,
V_116 , V_62 , V_28 ) ;
break;
case - V_156 :
F_150 ( V_43 , V_62 ) ;
break;
default:
F_124 ( L_11 ,
V_171 , V_58 ) ;
F_41 ( V_43 , V_62 ) ;
break;
}
}
static void F_159 ( void * V_65 ,
struct V_56 * V_62 )
{
struct V_109 * V_110 = V_65 ;
struct V_28 * V_28 ;
while ( ( V_28 = F_60 ( & V_62 -> V_64 ) ) ) {
if ( ( F_117 ( V_28 ) == V_124 ) ||
( V_28 -> V_91 & ( V_33 | V_92 | V_93 ) ) )
F_88 ( & V_110 -> V_111 , V_28 ) ;
else {
struct V_94 * V_95 = F_82 ( V_28 , sizeof( struct V_94 ) ) ; ;
V_95 -> V_172 = F_83 ( V_110 -> V_47 -> V_43 -> V_138 ) ;
F_81 ( V_110 -> V_47 -> V_43 , V_28 ) ;
F_88 ( & V_110 -> V_112 , V_28 ) ;
}
}
}
static void F_160 ( struct V_46 * V_47 ,
struct V_56 * V_62 ,
T_1 V_89 )
{
struct V_28 * V_28 ;
struct V_109 V_110 ;
V_110 . V_47 = V_47 ;
F_58 ( & V_110 . V_111 ) ;
F_58 ( & V_110 . V_112 ) ;
F_34 ( V_47 -> V_43 , F_159 ,
& V_110 , V_62 ) ;
while ( ( V_28 = F_60 ( & V_110 . V_111 ) ) )
F_100 ( V_47 , V_28 ) ;
while ( ( V_28 = F_60 ( & V_110 . V_112 ) ) )
F_90 ( V_47 , V_28 , V_89 ) ;
}
static void F_161 ( struct V_46 * V_47 , struct V_28 * V_28 ,
T_1 V_89 ,
struct V_169 * V_170 ,
struct V_56 * V_160 )
{
struct V_56 * V_166 ;
struct V_43 * V_43 = V_47 -> V_43 ;
struct V_7 V_8 ;
F_3 ( V_47 -> V_2 , V_170 -> V_89 , & V_8 ) ;
if ( F_28 ( V_43 , & V_8 , V_28 , & V_166 ) ) {
F_97 ( V_47 , V_160 ) ;
return;
}
if ( F_117 ( V_28 ) == V_124 && V_28 -> V_39 . V_42 ) {
F_158 ( V_47 , V_28 , V_89 , & V_8 , V_170 , V_166 ) ;
F_97 ( V_47 , V_160 ) ;
} else {
struct V_94 * V_95 = F_82 ( V_28 , sizeof( struct V_94 ) ) ;
V_95 -> V_172 = F_83 ( V_43 -> V_138 ) ;
F_81 ( V_43 , V_28 ) ;
F_90 ( V_47 , V_28 , V_170 -> V_89 ) ;
F_160 ( V_47 , V_166 , V_170 -> V_89 ) ;
F_160 ( V_47 , V_160 , V_170 -> V_89 ) ;
}
}
static void F_162 ( struct V_46 * V_47 , struct V_28 * V_28 , T_1 V_89 ,
struct V_56 * V_62 )
{
int V_58 ;
T_1 V_116 ;
struct V_43 * V_43 = V_47 -> V_43 ;
if ( ! V_28 -> V_39 . V_42 ) {
F_81 ( V_43 , V_28 ) ;
F_97 ( V_47 , V_62 ) ;
F_90 ( V_47 , V_28 , 0 ) ;
return;
}
if ( F_117 ( V_28 ) == V_173 ) {
F_163 ( V_28 ) ;
F_97 ( V_47 , V_62 ) ;
F_61 ( V_28 ) ;
return;
}
V_58 = F_144 ( V_47 , & V_116 ) ;
switch ( V_58 ) {
case 0 :
if ( V_47 -> V_90 )
F_133 ( V_47 , V_89 , V_116 , V_62 , V_28 ) ;
else
F_132 ( V_47 , V_89 , V_116 , V_62 , V_28 ) ;
break;
case - V_156 :
F_150 ( V_43 , V_62 ) ;
break;
default:
F_124 ( L_11 ,
V_171 , V_58 ) ;
F_41 ( V_43 , V_62 ) ;
break;
}
}
static void F_164 ( struct V_46 * V_47 , struct V_56 * V_62 )
{
int V_58 ;
struct V_43 * V_43 = V_47 -> V_43 ;
struct V_28 * V_28 = V_62 -> V_117 ;
T_1 V_89 = F_74 ( V_47 , V_28 ) ;
struct V_169 V_170 ;
if ( V_47 -> V_174 ) {
F_43 ( V_43 , V_62 ) ;
return;
}
V_58 = F_165 ( V_47 -> V_2 , V_89 , 1 , & V_170 ) ;
switch ( V_58 ) {
case 0 :
if ( V_170 . V_175 )
F_161 ( V_47 , V_28 , V_89 , & V_170 , V_62 ) ;
else {
F_81 ( V_43 , V_28 ) ;
F_90 ( V_47 , V_28 , V_170 . V_89 ) ;
F_99 ( V_47 , V_62 , V_170 . V_89 ) ;
}
break;
case - V_176 :
if ( F_117 ( V_28 ) == V_173 && V_47 -> V_90 ) {
F_81 ( V_43 , V_28 ) ;
F_97 ( V_47 , V_62 ) ;
if ( F_166 ( V_28 ) <= V_47 -> V_144 )
F_89 ( V_47 , V_28 ) ;
else if ( V_28 -> V_39 . V_40 < V_47 -> V_144 ) {
F_163 ( V_28 ) ;
V_28 -> V_39 . V_42 = ( V_47 -> V_144 - V_28 -> V_39 . V_40 ) << V_88 ;
F_89 ( V_47 , V_28 ) ;
} else {
F_163 ( V_28 ) ;
F_61 ( V_28 ) ;
}
} else
F_162 ( V_47 , V_28 , V_89 , V_62 ) ;
break;
default:
F_124 ( L_12 ,
V_171 , V_58 ) ;
F_97 ( V_47 , V_62 ) ;
F_87 ( V_28 ) ;
break;
}
}
static void F_167 ( struct V_46 * V_47 , struct V_28 * V_28 )
{
struct V_43 * V_43 = V_47 -> V_43 ;
T_1 V_89 = F_74 ( V_47 , V_28 ) ;
struct V_56 * V_62 ;
struct V_7 V_8 ;
F_4 ( V_47 -> V_2 , V_89 , & V_8 ) ;
if ( F_28 ( V_43 , & V_8 , V_28 , & V_62 ) )
return;
F_164 ( V_47 , V_62 ) ;
}
static void F_168 ( struct V_46 * V_47 , struct V_28 * V_28 ,
struct V_56 * V_62 )
{
int V_58 ;
int V_177 = F_117 ( V_28 ) ;
T_1 V_89 = F_74 ( V_47 , V_28 ) ;
struct V_169 V_170 ;
V_58 = F_165 ( V_47 -> V_2 , V_89 , 1 , & V_170 ) ;
switch ( V_58 ) {
case 0 :
if ( V_170 . V_175 && ( V_177 == V_124 ) && V_28 -> V_39 . V_42 ) {
F_149 ( V_47 -> V_43 , V_28 ) ;
if ( V_62 )
F_97 ( V_47 , V_62 ) ;
} else {
F_81 ( V_47 -> V_43 , V_28 ) ;
F_90 ( V_47 , V_28 , V_170 . V_89 ) ;
if ( V_62 )
F_99 ( V_47 , V_62 , V_170 . V_89 ) ;
}
break;
case - V_176 :
if ( V_62 )
F_97 ( V_47 , V_62 ) ;
if ( V_177 != V_173 ) {
F_149 ( V_47 -> V_43 , V_28 ) ;
break;
}
if ( V_47 -> V_90 ) {
F_81 ( V_47 -> V_43 , V_28 ) ;
F_89 ( V_47 , V_28 ) ;
break;
}
F_163 ( V_28 ) ;
F_61 ( V_28 ) ;
break;
default:
F_124 ( L_12 ,
V_171 , V_58 ) ;
if ( V_62 )
F_97 ( V_47 , V_62 ) ;
F_87 ( V_28 ) ;
break;
}
}
static void F_169 ( struct V_46 * V_47 , struct V_28 * V_28 )
{
F_168 ( V_47 , V_28 , NULL ) ;
}
static void F_170 ( struct V_46 * V_47 , struct V_56 * V_62 )
{
F_168 ( V_47 , V_62 -> V_117 , V_62 ) ;
}
static void F_171 ( struct V_46 * V_47 , struct V_28 * V_28 )
{
F_61 ( V_28 ) ;
}
static void F_172 ( struct V_46 * V_47 , struct V_28 * V_28 )
{
F_87 ( V_28 ) ;
}
static void F_173 ( struct V_46 * V_47 , struct V_56 * V_62 )
{
F_42 ( V_47 -> V_43 , V_62 ) ;
}
static void F_174 ( struct V_46 * V_47 , struct V_56 * V_62 )
{
F_41 ( V_47 -> V_43 , V_62 ) ;
}
static int F_175 ( struct V_43 * V_43 )
{
return ! F_176 ( V_20 , V_43 -> V_178 ,
V_43 -> V_178 + V_179 ) ;
}
static void F_177 ( struct V_46 * V_47 , struct V_28 * V_28 )
{
struct V_180 * * V_181 , * V_182 ;
struct V_94 * V_183 ;
T_2 V_40 = V_28 -> V_39 . V_40 ;
V_181 = & V_47 -> V_184 . V_180 ;
V_182 = NULL ;
while ( * V_181 ) {
V_182 = * V_181 ;
V_183 = F_178 ( V_182 ) ;
if ( V_40 < F_179 ( V_183 ) -> V_39 . V_40 )
V_181 = & ( * V_181 ) -> V_185 ;
else
V_181 = & ( * V_181 ) -> V_186 ;
}
V_183 = F_82 ( V_28 , sizeof( struct V_94 ) ) ;
F_180 ( & V_183 -> V_180 , V_182 , V_181 ) ;
F_181 ( & V_183 -> V_180 , & V_47 -> V_184 ) ;
}
static void F_182 ( struct V_46 * V_47 )
{
struct V_180 * V_187 ;
struct V_94 * V_183 ;
struct V_28 * V_28 ;
for ( V_187 = F_183 ( & V_47 -> V_184 ) ; V_187 ; V_187 = F_184 ( V_187 ) ) {
V_183 = F_178 ( V_187 ) ;
V_28 = F_179 ( V_183 ) ;
F_88 ( & V_47 -> V_83 , V_28 ) ;
F_185 ( & V_183 -> V_180 , & V_47 -> V_184 ) ;
}
F_145 ( ! F_186 ( & V_47 -> V_184 ) ) ;
}
static void F_187 ( struct V_46 * V_47 )
{
struct V_28 * V_28 ;
struct V_63 V_64 ;
F_58 ( & V_64 ) ;
F_57 ( & V_64 , & V_47 -> V_83 ) ;
F_58 ( & V_47 -> V_83 ) ;
while ( ( V_28 = F_60 ( & V_64 ) ) )
F_177 ( V_47 , V_28 ) ;
F_182 ( V_47 ) ;
}
static void F_188 ( struct V_46 * V_47 )
{
struct V_43 * V_43 = V_47 -> V_43 ;
unsigned long V_27 ;
struct V_28 * V_28 ;
struct V_63 V_64 ;
struct V_188 V_189 ;
unsigned V_130 = 0 ;
if ( V_47 -> V_174 ) {
F_62 ( V_47 , & V_47 -> V_83 , V_68 ) ;
return;
}
F_58 ( & V_64 ) ;
F_63 ( & V_47 -> V_17 , V_27 ) ;
if ( F_189 ( & V_47 -> V_83 ) ) {
F_64 ( & V_47 -> V_17 , V_27 ) ;
return;
}
F_187 ( V_47 ) ;
F_57 ( & V_64 , & V_47 -> V_83 ) ;
F_58 ( & V_47 -> V_83 ) ;
F_64 ( & V_47 -> V_17 , V_27 ) ;
F_190 ( & V_189 ) ;
while ( ( V_28 = F_60 ( & V_64 ) ) ) {
if ( F_119 ( V_43 ) ) {
F_63 ( & V_47 -> V_17 , V_27 ) ;
F_88 ( & V_47 -> V_83 , V_28 ) ;
F_57 ( & V_47 -> V_83 , & V_64 ) ;
F_64 ( & V_47 -> V_17 , V_27 ) ;
break;
}
if ( V_28 -> V_91 & V_33 )
V_43 -> V_190 ( V_47 , V_28 ) ;
else
V_43 -> F_167 ( V_47 , V_28 ) ;
if ( ( V_130 ++ & 127 ) == 0 ) {
F_8 ( & V_43 -> V_15 ) ;
F_191 ( V_43 -> V_120 ) ;
}
}
F_192 ( & V_189 ) ;
}
static int F_193 ( const void * V_191 , const void * V_192 )
{
struct V_56 * V_193 = * ( (struct V_56 * * ) V_191 ) ;
struct V_56 * V_194 = * ( (struct V_56 * * ) V_192 ) ;
F_48 ( ! V_193 -> V_117 ) ;
F_48 ( ! V_194 -> V_117 ) ;
if ( V_193 -> V_117 -> V_39 . V_40 < V_194 -> V_117 -> V_39 . V_40 )
return - 1 ;
if ( V_193 -> V_117 -> V_39 . V_40 > V_194 -> V_117 -> V_39 . V_40 )
return 1 ;
return 0 ;
}
static unsigned F_194 ( struct V_43 * V_43 , struct V_80 * V_81 )
{
unsigned V_130 = 0 ;
struct V_56 * V_62 , * V_75 ;
F_67 (cell, tmp, cells, user_list) {
if ( V_130 >= V_195 )
break;
V_43 -> V_196 [ V_130 ++ ] = V_62 ;
F_52 ( & V_62 -> V_197 ) ;
}
F_195 ( V_43 -> V_196 , V_130 , sizeof( V_62 ) , F_193 , NULL ) ;
return V_130 ;
}
static void F_196 ( struct V_46 * V_47 )
{
struct V_43 * V_43 = V_47 -> V_43 ;
unsigned long V_27 ;
struct V_80 V_81 ;
struct V_56 * V_62 ;
unsigned V_198 , V_199 , V_130 ;
F_46 ( & V_81 ) ;
F_63 ( & V_47 -> V_17 , V_27 ) ;
F_66 ( & V_47 -> V_82 , & V_81 ) ;
F_64 ( & V_47 -> V_17 , V_27 ) ;
if ( F_197 ( & V_81 ) )
return;
do {
V_130 = F_194 ( V_47 -> V_43 , & V_81 ) ;
for ( V_198 = 0 ; V_198 < V_130 ; V_198 ++ ) {
V_62 = V_43 -> V_196 [ V_198 ] ;
F_48 ( ! V_62 -> V_117 ) ;
if ( F_119 ( V_43 ) ) {
for ( V_199 = V_198 ; V_199 < V_130 ; V_199 ++ )
F_50 ( & V_43 -> V_196 [ V_199 ] -> V_197 , & V_81 ) ;
F_63 ( & V_47 -> V_17 , V_27 ) ;
F_198 ( & V_81 , & V_47 -> V_82 ) ;
F_64 ( & V_47 -> V_17 , V_27 ) ;
return;
}
if ( V_62 -> V_117 -> V_91 & V_33 )
V_43 -> V_168 ( V_47 , V_62 ) ;
else
V_43 -> F_164 ( V_47 , V_62 ) ;
}
} while ( ! F_197 ( & V_81 ) );
}
static struct V_46 * F_199 ( struct V_43 * V_43 )
{
struct V_46 * V_47 = NULL ;
F_70 () ;
if ( ! F_197 ( & V_43 -> V_200 ) ) {
V_47 = F_200 ( V_43 -> V_200 . V_201 , struct V_46 , V_72 ) ;
F_201 ( V_47 ) ;
}
F_72 () ;
return V_47 ;
}
static struct V_46 * F_202 ( struct V_43 * V_43 , struct V_46 * V_47 )
{
struct V_46 * V_202 = V_47 ;
F_70 () ;
F_203 (tc, &pool->active_thins, list) {
F_201 ( V_47 ) ;
F_204 ( V_202 ) ;
F_72 () ;
return V_47 ;
}
F_204 ( V_202 ) ;
F_72 () ;
return NULL ;
}
static void F_205 ( struct V_43 * V_43 )
{
unsigned long V_27 ;
struct V_28 * V_28 ;
struct V_63 V_64 ;
struct V_46 * V_47 ;
V_47 = F_199 ( V_43 ) ;
while ( V_47 ) {
F_196 ( V_47 ) ;
F_188 ( V_47 ) ;
V_47 = F_202 ( V_43 , V_47 ) ;
}
F_58 ( & V_64 ) ;
F_63 ( & V_43 -> V_17 , V_27 ) ;
F_57 ( & V_64 , & V_43 -> V_98 ) ;
F_58 ( & V_43 -> V_98 ) ;
F_64 ( & V_43 -> V_17 , V_27 ) ;
if ( F_189 ( & V_64 ) &&
! ( F_206 ( V_43 -> V_120 ) && F_175 ( V_43 ) ) )
return;
if ( F_138 ( V_43 ) ) {
while ( ( V_28 = F_60 ( & V_64 ) ) )
F_87 ( V_28 ) ;
return;
}
V_43 -> V_178 = V_20 ;
while ( ( V_28 = F_60 ( & V_64 ) ) )
F_85 ( V_28 ) ;
}
static void F_207 ( struct V_203 * V_204 )
{
struct V_43 * V_43 = F_208 ( V_204 , struct V_43 , V_55 ) ;
F_7 ( & V_43 -> V_15 ) ;
F_191 ( V_43 -> V_120 ) ;
F_8 ( & V_43 -> V_15 ) ;
F_114 ( V_43 , & V_43 -> V_102 , & V_43 -> F_103 ) ;
F_8 ( & V_43 -> V_15 ) ;
F_114 ( V_43 , & V_43 -> V_205 , & V_43 -> V_161 ) ;
F_8 ( & V_43 -> V_15 ) ;
F_205 ( V_43 ) ;
F_10 ( & V_43 -> V_15 ) ;
}
static void F_209 ( struct V_203 * V_204 )
{
struct V_43 * V_43 = F_208 ( F_210 ( V_204 ) , struct V_43 , V_206 ) ;
F_26 ( V_43 ) ;
F_211 ( V_43 -> V_54 , & V_43 -> V_206 , V_179 ) ;
}
static void F_212 ( struct V_203 * V_204 )
{
struct V_43 * V_43 = F_208 ( F_210 ( V_204 ) , struct V_43 ,
V_207 ) ;
if ( F_135 ( V_43 ) == V_146 && ! V_43 -> V_140 . V_158 ) {
V_43 -> V_140 . V_158 = true ;
F_213 ( V_43 ) ;
F_69 ( V_43 , - V_156 ) ;
}
}
static struct V_208 * F_214 ( struct V_203 * V_204 )
{
return F_208 ( V_204 , struct V_208 , V_55 ) ;
}
static void F_215 ( struct V_208 * V_209 )
{
F_216 ( & V_209 -> F_216 ) ;
}
static void F_217 ( struct V_208 * V_209 , struct V_43 * V_43 ,
void (* F_35)( struct V_203 * ) )
{
F_218 ( & V_209 -> V_55 , F_35 ) ;
F_219 ( & V_209 -> F_216 ) ;
F_27 ( V_43 -> V_54 , & V_209 -> V_55 ) ;
F_220 ( & V_209 -> F_216 ) ;
}
static struct V_210 * F_221 ( struct V_203 * V_204 )
{
return F_208 ( F_214 ( V_204 ) , struct V_210 , V_209 ) ;
}
static void F_222 ( struct V_203 * V_204 )
{
struct V_210 * V_211 = F_221 ( V_204 ) ;
V_211 -> V_47 -> V_174 = true ;
F_68 ( V_211 -> V_47 ) ;
F_215 ( & V_211 -> V_209 ) ;
}
static void F_223 ( struct V_203 * V_204 )
{
struct V_210 * V_211 = F_221 ( V_204 ) ;
V_211 -> V_47 -> V_174 = false ;
F_215 ( & V_211 -> V_209 ) ;
}
static void V_210 ( struct V_46 * V_47 , void (* F_35)( struct V_203 * ) )
{
struct V_210 V_211 ;
V_211 . V_47 = V_47 ;
F_217 ( & V_211 . V_209 , V_47 -> V_43 , F_35 ) ;
}
static enum V_157 F_135 ( struct V_43 * V_43 )
{
return V_43 -> V_140 . V_212 ;
}
static void F_224 ( struct V_43 * V_43 , const char * V_213 )
{
F_143 ( V_43 -> V_153 -> V_154 ) ;
F_225 ( L_13 ,
F_142 ( V_43 -> V_76 ) , V_213 ) ;
}
static void F_213 ( struct V_43 * V_43 )
{
if ( ! V_43 -> V_140 . V_158 )
F_224 ( V_43 , L_14 ) ;
else
F_224 ( V_43 , L_15 ) ;
}
static bool F_226 ( struct V_214 * V_215 )
{
return V_215 -> V_216 . V_217 ;
}
static void F_227 ( struct V_43 * V_43 )
{
struct V_214 * V_215 = V_43 -> V_153 -> V_218 ;
if ( F_226 ( V_215 ) ) {
V_43 -> V_168 = F_156 ;
V_43 -> V_161 = F_113 ;
} else {
V_43 -> V_168 = F_151 ;
V_43 -> V_161 = F_109 ;
}
}
static void F_137 ( struct V_43 * V_43 , enum V_157 V_213 )
{
struct V_214 * V_215 = V_43 -> V_153 -> V_218 ;
bool V_219 = F_228 ( V_43 -> V_120 ) ;
enum V_157 V_220 = F_135 ( V_43 ) ;
unsigned long V_207 = F_229 ( V_221 ) * V_222 ;
if ( V_213 == V_147 && V_219 ) {
F_230 ( L_16 ,
F_142 ( V_43 -> V_76 ) ) ;
if ( V_220 != V_213 )
V_213 = V_220 ;
else
V_213 = V_148 ;
}
if ( V_220 == V_159 )
V_213 = V_220 ;
switch ( V_213 ) {
case V_159 :
if ( V_220 != V_213 )
F_224 ( V_43 , L_17 ) ;
F_231 ( V_43 -> V_120 ) ;
V_43 -> F_167 = F_172 ;
V_43 -> V_190 = F_172 ;
V_43 -> F_164 = F_174 ;
V_43 -> V_168 = F_174 ;
V_43 -> F_103 = F_101 ;
V_43 -> V_161 = F_107 ;
F_73 ( V_43 ) ;
break;
case V_148 :
if ( V_220 != V_213 )
F_224 ( V_43 , L_18 ) ;
F_231 ( V_43 -> V_120 ) ;
V_43 -> F_167 = F_169 ;
V_43 -> V_190 = F_171 ;
V_43 -> F_164 = F_170 ;
V_43 -> V_168 = F_173 ;
V_43 -> F_103 = F_101 ;
V_43 -> V_161 = F_108 ;
F_73 ( V_43 ) ;
break;
case V_146 :
if ( V_220 != V_213 )
F_213 ( V_43 ) ;
V_43 -> F_167 = F_169 ;
V_43 -> V_190 = F_157 ;
V_43 -> F_164 = F_170 ;
V_43 -> F_103 = F_103 ;
F_227 ( V_43 ) ;
if ( ! V_43 -> V_140 . V_158 && V_207 )
F_211 ( V_43 -> V_54 , & V_43 -> V_207 , V_207 ) ;
break;
case V_147 :
if ( V_220 != V_213 )
F_224 ( V_43 , L_19 ) ;
V_43 -> V_140 . V_158 = V_215 -> V_223 . V_158 ;
F_232 ( V_43 -> V_120 ) ;
V_43 -> F_167 = F_167 ;
V_43 -> V_190 = F_157 ;
V_43 -> F_164 = F_164 ;
V_43 -> F_103 = F_103 ;
F_227 ( V_43 ) ;
break;
}
V_43 -> V_140 . V_212 = V_213 ;
V_215 -> V_216 . V_212 = V_213 ;
}
static void F_233 ( struct V_43 * V_43 )
{
const char * V_224 = F_142 ( V_43 -> V_76 ) ;
F_124 ( L_20 , V_224 ) ;
if ( F_234 ( V_43 -> V_120 ) ) {
F_230 ( L_21 , V_224 ) ;
F_137 ( V_43 , V_159 ) ;
}
if ( F_235 ( V_43 -> V_120 ) ) {
F_230 ( L_22 , V_224 ) ;
F_137 ( V_43 , V_159 ) ;
}
}
static void F_105 ( struct V_43 * V_43 , const char * V_225 , int V_58 )
{
F_124 ( L_23 ,
F_142 ( V_43 -> V_76 ) , V_225 , V_58 ) ;
F_233 ( V_43 ) ;
F_137 ( V_43 , V_148 ) ;
}
static void F_100 ( struct V_46 * V_47 , struct V_28 * V_28 )
{
unsigned long V_27 ;
struct V_43 * V_43 = V_47 -> V_43 ;
F_63 ( & V_47 -> V_17 , V_27 ) ;
F_88 ( & V_47 -> V_83 , V_28 ) ;
F_64 ( & V_47 -> V_17 , V_27 ) ;
F_26 ( V_43 ) ;
}
static void F_236 ( struct V_46 * V_47 , struct V_28 * V_28 )
{
struct V_43 * V_43 = V_47 -> V_43 ;
F_12 ( & V_43 -> V_15 ) ;
F_100 ( V_47 , V_28 ) ;
F_14 ( & V_43 -> V_15 ) ;
}
static void F_237 ( struct V_46 * V_47 , struct V_56 * V_62 )
{
unsigned long V_27 ;
struct V_43 * V_43 = V_47 -> V_43 ;
F_12 ( & V_43 -> V_15 ) ;
F_63 ( & V_47 -> V_17 , V_27 ) ;
F_93 ( & V_62 -> V_197 , & V_47 -> V_82 ) ;
F_64 ( & V_47 -> V_17 , V_27 ) ;
F_14 ( & V_43 -> V_15 ) ;
F_26 ( V_43 ) ;
}
static void F_238 ( struct V_46 * V_47 , struct V_28 * V_28 )
{
struct V_94 * V_95 = F_82 ( V_28 , sizeof( struct V_94 ) ) ;
V_95 -> V_47 = V_47 ;
V_95 -> V_172 = NULL ;
V_95 -> V_96 = NULL ;
V_95 -> V_106 = NULL ;
V_95 -> V_62 = NULL ;
}
static int F_239 ( struct V_226 * V_153 , struct V_28 * V_28 )
{
int V_58 ;
struct V_46 * V_47 = V_153 -> V_218 ;
T_1 V_89 = F_74 ( V_47 , V_28 ) ;
struct V_1 * V_2 = V_47 -> V_2 ;
struct V_169 V_155 ;
struct V_56 * V_160 , * V_166 ;
struct V_7 V_8 ;
F_238 ( V_47 , V_28 ) ;
if ( V_47 -> V_174 ) {
V_28 -> V_79 = V_68 ;
F_61 ( V_28 ) ;
return V_227 ;
}
if ( F_135 ( V_47 -> V_43 ) == V_159 ) {
F_87 ( V_28 ) ;
return V_227 ;
}
if ( V_28 -> V_91 & ( V_33 | V_92 | V_93 ) ) {
F_236 ( V_47 , V_28 ) ;
return V_227 ;
}
F_4 ( V_47 -> V_2 , V_89 , & V_8 ) ;
if ( F_28 ( V_47 -> V_43 , & V_8 , V_28 , & V_160 ) )
return V_227 ;
V_58 = F_165 ( V_2 , V_89 , 0 , & V_155 ) ;
switch ( V_58 ) {
case 0 :
if ( F_240 ( V_155 . V_175 ) ) {
F_237 ( V_47 , V_160 ) ;
return V_227 ;
}
F_3 ( V_47 -> V_2 , V_155 . V_89 , & V_8 ) ;
if ( F_28 ( V_47 -> V_43 , & V_8 , V_28 , & V_166 ) ) {
F_97 ( V_47 , V_160 ) ;
return V_227 ;
}
F_81 ( V_47 -> V_43 , V_28 ) ;
F_97 ( V_47 , V_166 ) ;
F_97 ( V_47 , V_160 ) ;
F_77 ( V_47 , V_28 , V_155 . V_89 ) ;
return V_228 ;
case - V_176 :
case - V_229 :
F_237 ( V_47 , V_160 ) ;
return V_227 ;
default:
F_87 ( V_28 ) ;
F_97 ( V_47 , V_160 ) ;
return V_227 ;
}
}
static int F_241 ( struct V_230 * V_231 , int V_232 )
{
struct V_214 * V_215 = F_208 ( V_231 , struct V_214 , V_233 ) ;
struct V_30 * V_31 ;
if ( F_135 ( V_215 -> V_43 ) == V_146 )
return 1 ;
V_31 = F_17 ( V_215 -> V_234 -> V_23 ) ;
return F_242 ( & V_31 -> V_235 , V_232 ) ;
}
static void F_243 ( struct V_43 * V_43 )
{
unsigned long V_27 ;
struct V_46 * V_47 ;
F_70 () ;
F_71 (tc, &pool->active_thins, list) {
F_63 ( & V_47 -> V_17 , V_27 ) ;
F_57 ( & V_47 -> V_83 , & V_47 -> V_84 ) ;
F_58 ( & V_47 -> V_84 ) ;
F_64 ( & V_47 -> V_17 , V_27 ) ;
}
F_72 () ;
}
static bool F_244 ( struct V_214 * V_215 )
{
struct V_30 * V_31 = F_17 ( V_215 -> V_234 -> V_23 ) ;
return V_31 && F_18 ( V_31 ) ;
}
static bool F_245 ( T_2 V_236 , T_6 V_237 )
{
return ! F_75 ( V_236 , V_237 ) ;
}
static void F_246 ( struct V_214 * V_215 )
{
struct V_43 * V_43 = V_215 -> V_43 ;
struct V_22 * V_238 = V_215 -> V_234 -> V_23 ;
struct V_239 * V_240 = & F_17 ( V_238 ) -> V_241 ;
const char * V_242 = NULL ;
char V_243 [ V_244 ] ;
if ( ! V_215 -> V_216 . V_217 )
return;
if ( ! F_244 ( V_215 ) )
V_242 = L_24 ;
else if ( V_240 -> V_245 < V_43 -> V_45 )
V_242 = L_25 ;
if ( V_242 ) {
F_141 ( L_26 , F_247 ( V_238 , V_243 ) , V_242 ) ;
V_215 -> V_216 . V_217 = false ;
}
}
static int F_248 ( struct V_43 * V_43 , struct V_226 * V_153 )
{
struct V_214 * V_215 = V_153 -> V_218 ;
enum V_157 V_220 = F_135 ( V_43 ) ;
enum V_157 V_213 = V_215 -> V_216 . V_212 ;
V_215 -> V_216 . V_212 = V_220 ;
V_43 -> V_153 = V_153 ;
V_43 -> V_140 = V_215 -> V_216 ;
V_43 -> V_151 = V_215 -> V_151 ;
F_137 ( V_43 , V_213 ) ;
return 0 ;
}
static void F_249 ( struct V_43 * V_43 , struct V_226 * V_153 )
{
if ( V_43 -> V_153 == V_153 )
V_43 -> V_153 = NULL ;
}
static void F_250 ( struct V_246 * V_140 )
{
V_140 -> V_212 = V_147 ;
V_140 -> V_141 = true ;
V_140 -> V_247 = true ;
V_140 -> V_217 = true ;
V_140 -> V_158 = false ;
}
static void F_251 ( struct V_43 * V_43 )
{
F_51 ( V_43 ) ;
F_252 ( V_43 -> V_196 ) ;
if ( F_253 ( V_43 -> V_120 ) < 0 )
F_141 ( L_27 , V_171 ) ;
F_254 ( V_43 -> V_60 ) ;
F_255 ( V_43 -> V_131 ) ;
if ( V_43 -> V_54 )
F_256 ( V_43 -> V_54 ) ;
if ( V_43 -> V_126 )
F_102 ( V_43 -> V_126 , V_43 -> V_113 ) ;
F_257 ( V_43 -> V_113 ) ;
F_258 ( V_43 -> V_138 ) ;
F_258 ( V_43 -> V_97 ) ;
F_259 ( V_43 ) ;
}
static struct V_43 * F_260 ( struct V_73 * V_76 ,
struct V_22 * V_248 ,
unsigned long V_236 ,
int V_249 , char * * error )
{
int V_58 ;
void * V_250 ;
struct V_43 * V_43 ;
struct V_251 * V_120 ;
bool V_252 = V_249 ? false : true ;
V_120 = F_261 ( V_248 , V_236 , V_252 ) ;
if ( F_262 ( V_120 ) ) {
* error = L_28 ;
return (struct V_43 * ) V_120 ;
}
V_43 = F_263 ( sizeof( * V_43 ) , V_253 ) ;
if ( ! V_43 ) {
* error = L_29 ;
V_250 = F_264 ( - V_38 ) ;
goto V_254;
}
V_43 -> V_120 = V_120 ;
V_43 -> V_45 = V_236 ;
if ( V_236 & ( V_236 - 1 ) )
V_43 -> V_44 = - 1 ;
else
V_43 -> V_44 = F_265 ( V_236 ) ;
V_43 -> V_151 = 0 ;
F_250 ( & V_43 -> V_140 ) ;
V_43 -> V_60 = F_266 () ;
if ( ! V_43 -> V_60 ) {
* error = L_30 ;
V_250 = F_264 ( - V_38 ) ;
goto V_255;
}
V_43 -> V_131 = F_267 ( & V_256 ) ;
if ( F_262 ( V_43 -> V_131 ) ) {
V_58 = F_268 ( V_43 -> V_131 ) ;
* error = L_31 ;
V_250 = F_264 ( V_58 ) ;
goto V_257;
}
V_43 -> V_54 = F_269 ( L_32 V_258 , V_259 ) ;
if ( ! V_43 -> V_54 ) {
* error = L_33 ;
V_250 = F_264 ( - V_38 ) ;
goto V_260;
}
F_5 ( & V_43 -> V_15 ) ;
F_270 ( & V_43 -> V_55 , F_207 ) ;
F_271 ( & V_43 -> V_206 , F_209 ) ;
F_271 ( & V_43 -> V_207 , F_212 ) ;
F_272 ( & V_43 -> V_17 ) ;
F_58 ( & V_43 -> V_98 ) ;
F_46 ( & V_43 -> V_102 ) ;
F_46 ( & V_43 -> V_205 ) ;
F_46 ( & V_43 -> V_200 ) ;
V_43 -> V_152 = false ;
V_43 -> V_261 = true ;
V_43 -> V_138 = F_273 () ;
if ( ! V_43 -> V_138 ) {
* error = L_34 ;
V_250 = F_264 ( - V_38 ) ;
goto V_262;
}
V_43 -> V_97 = F_273 () ;
if ( ! V_43 -> V_97 ) {
* error = L_35 ;
V_250 = F_264 ( - V_38 ) ;
goto V_263;
}
V_43 -> V_126 = NULL ;
V_43 -> V_113 = F_274 ( V_264 ,
V_265 ) ;
if ( ! V_43 -> V_113 ) {
* error = L_36 ;
V_250 = F_264 ( - V_38 ) ;
goto V_266;
}
V_43 -> V_196 = F_275 ( sizeof( * V_43 -> V_196 ) * V_195 ) ;
if ( ! V_43 -> V_196 ) {
* error = L_37 ;
V_250 = F_264 ( - V_38 ) ;
goto V_267;
}
V_43 -> V_268 = 1 ;
V_43 -> V_178 = V_20 ;
V_43 -> V_76 = V_76 ;
V_43 -> V_77 = V_248 ;
F_47 ( V_43 ) ;
return V_43 ;
V_267:
F_257 ( V_43 -> V_113 ) ;
V_266:
F_258 ( V_43 -> V_97 ) ;
V_263:
F_258 ( V_43 -> V_138 ) ;
V_262:
F_256 ( V_43 -> V_54 ) ;
V_260:
F_255 ( V_43 -> V_131 ) ;
V_257:
F_254 ( V_43 -> V_60 ) ;
V_255:
F_259 ( V_43 ) ;
V_254:
if ( F_253 ( V_120 ) )
F_141 ( L_27 , V_171 ) ;
return V_250 ;
}
static void F_276 ( struct V_43 * V_43 )
{
F_48 ( ! F_49 ( & V_69 . V_70 ) ) ;
V_43 -> V_268 ++ ;
}
static void F_277 ( struct V_43 * V_43 )
{
F_48 ( ! F_49 ( & V_69 . V_70 ) ) ;
F_48 ( ! V_43 -> V_268 ) ;
if ( ! -- V_43 -> V_268 )
F_251 ( V_43 ) ;
}
static struct V_43 * F_278 ( struct V_73 * V_76 ,
struct V_22 * V_248 ,
unsigned long V_236 , int V_249 ,
char * * error , int * V_269 )
{
struct V_43 * V_43 = F_55 ( V_248 ) ;
if ( V_43 ) {
if ( V_43 -> V_76 != V_76 ) {
* error = L_38 ;
return F_264 ( - V_270 ) ;
}
F_276 ( V_43 ) ;
} else {
V_43 = F_53 ( V_76 ) ;
if ( V_43 ) {
if ( V_43 -> V_77 != V_248 ) {
* error = L_39 ;
return F_264 ( - V_149 ) ;
}
F_276 ( V_43 ) ;
} else {
V_43 = F_260 ( V_76 , V_248 , V_236 , V_249 , error ) ;
* V_269 = 1 ;
}
}
return V_43 ;
}
static void F_279 ( struct V_226 * V_153 )
{
struct V_214 * V_215 = V_153 -> V_218 ;
F_280 ( & V_69 . V_70 ) ;
F_249 ( V_215 -> V_43 , V_153 ) ;
F_277 ( V_215 -> V_43 ) ;
F_281 ( V_153 , V_215 -> V_248 ) ;
F_281 ( V_153 , V_215 -> V_234 ) ;
F_259 ( V_215 ) ;
F_282 ( & V_69 . V_70 ) ;
}
static int F_283 ( struct V_271 * V_272 , struct V_246 * V_140 ,
struct V_226 * V_153 )
{
int V_58 ;
unsigned V_273 ;
const char * V_274 ;
static struct V_275 V_276 [] = {
{ 0 , 4 , L_40 } ,
} ;
if ( ! V_272 -> V_273 )
return 0 ;
V_58 = F_284 ( V_276 , V_272 , & V_273 , & V_153 -> error ) ;
if ( V_58 )
return - V_149 ;
while ( V_273 && ! V_58 ) {
V_274 = F_285 ( V_272 ) ;
V_273 -- ;
if ( ! strcasecmp ( V_274 , L_41 ) )
V_140 -> V_141 = false ;
else if ( ! strcasecmp ( V_274 , L_42 ) )
V_140 -> V_247 = false ;
else if ( ! strcasecmp ( V_274 , L_43 ) )
V_140 -> V_217 = false ;
else if ( ! strcasecmp ( V_274 , L_44 ) )
V_140 -> V_212 = V_148 ;
else if ( ! strcasecmp ( V_274 , L_45 ) )
V_140 -> V_158 = true ;
else {
V_153 -> error = L_46 ;
V_58 = - V_149 ;
break;
}
}
return V_58 ;
}
static void F_286 ( void * V_65 )
{
struct V_43 * V_43 = V_65 ;
F_141 ( L_47 ,
F_142 ( V_43 -> V_76 ) ) ;
F_143 ( V_43 -> V_153 -> V_154 ) ;
}
static T_2 F_287 ( struct V_22 * V_23 )
{
return F_288 ( V_23 -> V_277 ) >> V_88 ;
}
static void F_289 ( struct V_22 * V_23 )
{
T_2 V_278 = F_287 ( V_23 ) ;
char V_279 [ V_244 ] ;
if ( V_278 > V_280 )
F_141 ( L_48 ,
F_247 ( V_23 , V_279 ) , V_281 ) ;
}
static T_2 F_290 ( struct V_22 * V_23 )
{
T_2 V_278 = F_287 ( V_23 ) ;
if ( V_278 > V_281 )
V_278 = V_281 ;
return V_278 ;
}
static T_1 F_291 ( struct V_22 * V_23 )
{
T_2 V_278 = F_290 ( V_23 ) ;
F_75 ( V_278 , V_282 ) ;
return V_278 ;
}
static T_1 F_292 ( struct V_214 * V_215 )
{
T_1 V_283 = F_291 ( V_215 -> V_248 -> V_23 ) / 4 ;
return F_293 ( ( T_1 ) 1024ULL , V_283 ) ;
}
static int F_294 ( struct V_226 * V_153 , unsigned V_273 , char * * V_284 )
{
int V_58 , V_285 = 0 ;
struct V_214 * V_215 ;
struct V_43 * V_43 ;
struct V_246 V_140 ;
struct V_271 V_272 ;
struct V_134 * V_234 ;
unsigned long V_236 ;
T_1 V_151 ;
struct V_134 * V_248 ;
T_7 V_286 ;
F_280 ( & V_69 . V_70 ) ;
if ( V_273 < 4 ) {
V_153 -> error = L_49 ;
V_58 = - V_149 ;
goto V_287;
}
V_272 . V_273 = V_273 ;
V_272 . V_284 = V_284 ;
F_250 ( & V_140 ) ;
F_295 ( & V_272 , 4 ) ;
V_58 = F_283 ( & V_272 , & V_140 , V_153 ) ;
if ( V_58 )
goto V_287;
V_286 = V_288 | ( ( V_140 . V_212 == V_148 ) ? 0 : V_289 ) ;
V_58 = F_296 ( V_153 , V_284 [ 0 ] , V_286 , & V_248 ) ;
if ( V_58 ) {
V_153 -> error = L_50 ;
goto V_287;
}
F_289 ( V_248 -> V_23 ) ;
V_58 = F_296 ( V_153 , V_284 [ 1 ] , V_288 | V_289 , & V_234 ) ;
if ( V_58 ) {
V_153 -> error = L_51 ;
goto V_290;
}
if ( F_297 ( V_284 [ 2 ] , 10 , & V_236 ) || ! V_236 ||
V_236 < V_291 ||
V_236 > V_292 ||
V_236 & ( V_291 - 1 ) ) {
V_153 -> error = L_52 ;
V_58 = - V_149 ;
goto V_114;
}
if ( F_298 ( V_284 [ 3 ] , 10 , ( unsigned long long * ) & V_151 ) ) {
V_153 -> error = L_53 ;
V_58 = - V_149 ;
goto V_114;
}
V_215 = F_299 ( sizeof( * V_215 ) , V_253 ) ;
if ( ! V_215 ) {
V_58 = - V_38 ;
goto V_114;
}
V_43 = F_278 ( F_300 ( V_153 -> V_154 ) , V_248 -> V_23 ,
V_236 , V_140 . V_212 == V_148 , & V_153 -> error , & V_285 ) ;
if ( F_262 ( V_43 ) ) {
V_58 = F_268 ( V_43 ) ;
goto V_293;
}
if ( ! V_285 && V_140 . V_247 != V_43 -> V_140 . V_247 ) {
V_153 -> error = L_54 ;
V_58 = - V_149 ;
goto V_294;
}
V_215 -> V_43 = V_43 ;
V_215 -> V_153 = V_153 ;
V_215 -> V_248 = V_248 ;
V_215 -> V_234 = V_234 ;
V_215 -> V_151 = V_151 ;
V_215 -> V_216 = V_215 -> V_223 = V_140 ;
V_153 -> V_295 = 1 ;
V_153 -> V_296 = true ;
if ( V_140 . V_247 && V_140 . V_217 ) {
V_153 -> V_297 = 1 ;
V_153 -> V_298 = true ;
}
V_153 -> V_218 = V_215 ;
V_58 = F_301 ( V_215 -> V_43 -> V_120 ,
F_292 ( V_215 ) ,
F_286 ,
V_43 ) ;
if ( V_58 )
goto V_294;
V_215 -> V_233 . V_299 = F_241 ;
F_302 ( V_153 -> V_154 , & V_215 -> V_233 ) ;
F_282 ( & V_69 . V_70 ) ;
return 0 ;
V_294:
F_277 ( V_43 ) ;
V_293:
F_259 ( V_215 ) ;
V_114:
F_281 ( V_153 , V_234 ) ;
V_290:
F_281 ( V_153 , V_248 ) ;
V_287:
F_282 ( & V_69 . V_70 ) ;
return V_58 ;
}
static int F_303 ( struct V_226 * V_153 , struct V_28 * V_28 )
{
int V_58 ;
struct V_214 * V_215 = V_153 -> V_218 ;
struct V_43 * V_43 = V_215 -> V_43 ;
unsigned long V_27 ;
F_63 ( & V_43 -> V_17 , V_27 ) ;
V_28 -> V_41 = V_215 -> V_234 -> V_23 ;
V_58 = V_228 ;
F_64 ( & V_43 -> V_17 , V_27 ) ;
return V_58 ;
}
static int F_304 ( struct V_226 * V_153 , bool * V_300 )
{
int V_58 ;
struct V_214 * V_215 = V_153 -> V_218 ;
struct V_43 * V_43 = V_215 -> V_43 ;
T_2 V_301 = V_153 -> V_51 ;
T_1 V_302 ;
* V_300 = false ;
( void ) F_75 ( V_301 , V_43 -> V_45 ) ;
V_58 = F_305 ( V_43 -> V_120 , & V_302 ) ;
if ( V_58 ) {
F_230 ( L_55 ,
F_142 ( V_43 -> V_76 ) ) ;
return V_58 ;
}
if ( V_301 < V_302 ) {
F_230 ( L_56 ,
F_142 ( V_43 -> V_76 ) ,
( unsigned long long ) V_301 , V_302 ) ;
return - V_149 ;
} else if ( V_301 > V_302 ) {
if ( F_228 ( V_43 -> V_120 ) ) {
F_230 ( L_57 ,
F_142 ( V_43 -> V_76 ) ) ;
return 0 ;
}
if ( V_302 )
F_225 ( L_58 ,
F_142 ( V_43 -> V_76 ) ,
V_302 , ( unsigned long long ) V_301 ) ;
V_58 = F_306 ( V_43 -> V_120 , V_301 ) ;
if ( V_58 ) {
F_105 ( V_43 , L_59 , V_58 ) ;
return V_58 ;
}
* V_300 = true ;
}
return 0 ;
}
static int F_307 ( struct V_226 * V_153 , bool * V_300 )
{
int V_58 ;
struct V_214 * V_215 = V_153 -> V_218 ;
struct V_43 * V_43 = V_215 -> V_43 ;
T_1 V_278 , V_303 ;
* V_300 = false ;
V_278 = F_291 ( V_43 -> V_77 ) ;
V_58 = F_308 ( V_43 -> V_120 , & V_303 ) ;
if ( V_58 ) {
F_230 ( L_60 ,
F_142 ( V_43 -> V_76 ) ) ;
return V_58 ;
}
if ( V_278 < V_303 ) {
F_230 ( L_61 ,
F_142 ( V_43 -> V_76 ) ,
V_278 , V_303 ) ;
return - V_149 ;
} else if ( V_278 > V_303 ) {
if ( F_228 ( V_43 -> V_120 ) ) {
F_230 ( L_62 ,
F_142 ( V_43 -> V_76 ) ) ;
return 0 ;
}
F_289 ( V_43 -> V_77 ) ;
F_225 ( L_63 ,
F_142 ( V_43 -> V_76 ) ,
V_303 , V_278 ) ;
V_58 = F_309 ( V_43 -> V_120 , V_278 ) ;
if ( V_58 ) {
F_105 ( V_43 , L_64 , V_58 ) ;
return V_58 ;
}
* V_300 = true ;
}
return 0 ;
}
static int F_310 ( struct V_226 * V_153 )
{
int V_58 ;
bool V_304 , V_305 ;
struct V_214 * V_215 = V_153 -> V_218 ;
struct V_43 * V_43 = V_215 -> V_43 ;
V_58 = F_248 ( V_43 , V_153 ) ;
if ( V_58 )
return V_58 ;
V_58 = F_304 ( V_153 , & V_304 ) ;
if ( V_58 )
return V_58 ;
V_58 = F_307 ( V_153 , & V_305 ) ;
if ( V_58 )
return V_58 ;
if ( V_304 || V_305 )
( void ) F_138 ( V_43 ) ;
return 0 ;
}
static void F_311 ( struct V_43 * V_43 )
{
struct V_46 * V_47 ;
V_47 = F_199 ( V_43 ) ;
while ( V_47 ) {
F_312 ( V_47 -> V_306 ) ;
V_47 = F_202 ( V_43 , V_47 ) ;
}
}
static void F_313 ( struct V_43 * V_43 )
{
struct V_46 * V_47 ;
V_47 = F_199 ( V_43 ) ;
while ( V_47 ) {
F_314 ( V_47 -> V_306 ) ;
V_47 = F_202 ( V_43 , V_47 ) ;
}
}
static void F_315 ( struct V_226 * V_153 )
{
struct V_214 * V_215 = V_153 -> V_218 ;
struct V_43 * V_43 = V_215 -> V_43 ;
unsigned long V_27 ;
F_243 ( V_43 ) ;
F_313 ( V_43 ) ;
F_63 ( & V_43 -> V_17 , V_27 ) ;
V_43 -> V_152 = false ;
V_43 -> V_261 = false ;
F_64 ( & V_43 -> V_17 , V_27 ) ;
F_209 ( & V_43 -> V_206 . V_307 ) ;
}
static void F_316 ( struct V_226 * V_153 )
{
struct V_214 * V_215 = V_153 -> V_218 ;
struct V_43 * V_43 = V_215 -> V_43 ;
unsigned long V_27 ;
F_63 ( & V_43 -> V_17 , V_27 ) ;
V_43 -> V_261 = true ;
F_64 ( & V_43 -> V_17 , V_27 ) ;
F_311 ( V_43 ) ;
}
static void F_317 ( struct V_226 * V_153 )
{
struct V_214 * V_215 = V_153 -> V_218 ;
struct V_43 * V_43 = V_215 -> V_43 ;
unsigned long V_27 ;
F_313 ( V_43 ) ;
F_63 ( & V_43 -> V_17 , V_27 ) ;
V_43 -> V_261 = false ;
F_64 ( & V_43 -> V_17 , V_27 ) ;
}
static void F_318 ( struct V_226 * V_153 )
{
struct V_214 * V_215 = V_153 -> V_218 ;
struct V_43 * V_43 = V_215 -> V_43 ;
F_319 ( & V_43 -> V_206 ) ;
F_319 ( & V_43 -> V_207 ) ;
F_320 ( V_43 -> V_54 ) ;
( void ) F_138 ( V_43 ) ;
}
static int F_321 ( unsigned V_273 , unsigned V_308 )
{
if ( V_273 != V_308 ) {
F_141 ( L_65 ,
V_273 , V_308 ) ;
return - V_149 ;
}
return 0 ;
}
static int F_322 ( char * V_309 , T_8 * V_310 , int V_311 )
{
if ( ! F_298 ( V_309 , 10 , ( unsigned long long * ) V_310 ) &&
* V_310 <= V_312 )
return 0 ;
if ( V_311 )
F_141 ( L_66 , V_309 ) ;
return - V_149 ;
}
static int F_323 ( unsigned V_273 , char * * V_284 , struct V_43 * V_43 )
{
T_8 V_310 ;
int V_58 ;
V_58 = F_321 ( V_273 , 2 ) ;
if ( V_58 )
return V_58 ;
V_58 = F_322 ( V_284 [ 1 ] , & V_310 , 1 ) ;
if ( V_58 )
return V_58 ;
V_58 = F_324 ( V_43 -> V_120 , V_310 ) ;
if ( V_58 ) {
F_141 ( L_67 ,
V_284 [ 1 ] ) ;
return V_58 ;
}
return 0 ;
}
static int F_325 ( unsigned V_273 , char * * V_284 , struct V_43 * V_43 )
{
T_8 V_310 ;
T_8 V_313 ;
int V_58 ;
V_58 = F_321 ( V_273 , 3 ) ;
if ( V_58 )
return V_58 ;
V_58 = F_322 ( V_284 [ 1 ] , & V_310 , 1 ) ;
if ( V_58 )
return V_58 ;
V_58 = F_322 ( V_284 [ 2 ] , & V_313 , 1 ) ;
if ( V_58 )
return V_58 ;
V_58 = F_326 ( V_43 -> V_120 , V_310 , V_313 ) ;
if ( V_58 ) {
F_141 ( L_68 ,
V_284 [ 1 ] , V_284 [ 2 ] ) ;
return V_58 ;
}
return 0 ;
}
static int F_327 ( unsigned V_273 , char * * V_284 , struct V_43 * V_43 )
{
T_8 V_310 ;
int V_58 ;
V_58 = F_321 ( V_273 , 2 ) ;
if ( V_58 )
return V_58 ;
V_58 = F_322 ( V_284 [ 1 ] , & V_310 , 1 ) ;
if ( V_58 )
return V_58 ;
V_58 = F_328 ( V_43 -> V_120 , V_310 ) ;
if ( V_58 )
F_141 ( L_69 , V_284 [ 1 ] ) ;
return V_58 ;
}
static int F_329 ( unsigned V_273 , char * * V_284 , struct V_43 * V_43 )
{
T_8 V_314 , V_315 ;
int V_58 ;
V_58 = F_321 ( V_273 , 3 ) ;
if ( V_58 )
return V_58 ;
if ( F_298 ( V_284 [ 1 ] , 10 , ( unsigned long long * ) & V_314 ) ) {
F_141 ( L_70 , V_284 [ 1 ] ) ;
return - V_149 ;
}
if ( F_298 ( V_284 [ 2 ] , 10 , ( unsigned long long * ) & V_315 ) ) {
F_141 ( L_71 , V_284 [ 2 ] ) ;
return - V_149 ;
}
V_58 = F_330 ( V_43 -> V_120 , V_314 , V_315 ) ;
if ( V_58 ) {
F_141 ( L_72 ,
V_284 [ 1 ] , V_284 [ 2 ] ) ;
return V_58 ;
}
return 0 ;
}
static int F_331 ( unsigned V_273 , char * * V_284 , struct V_43 * V_43 )
{
int V_58 ;
V_58 = F_321 ( V_273 , 1 ) ;
if ( V_58 )
return V_58 ;
( void ) F_138 ( V_43 ) ;
V_58 = F_332 ( V_43 -> V_120 ) ;
if ( V_58 )
F_141 ( L_73 ) ;
return V_58 ;
}
static int F_333 ( unsigned V_273 , char * * V_284 , struct V_43 * V_43 )
{
int V_58 ;
V_58 = F_321 ( V_273 , 1 ) ;
if ( V_58 )
return V_58 ;
V_58 = F_334 ( V_43 -> V_120 ) ;
if ( V_58 )
F_141 ( L_74 ) ;
return V_58 ;
}
static int F_335 ( struct V_226 * V_153 , unsigned V_273 , char * * V_284 )
{
int V_58 = - V_149 ;
struct V_214 * V_215 = V_153 -> V_218 ;
struct V_43 * V_43 = V_215 -> V_43 ;
if ( F_135 ( V_43 ) >= V_148 ) {
F_230 ( L_75 ,
F_142 ( V_43 -> V_76 ) ) ;
return - V_35 ;
}
if ( ! strcasecmp ( V_284 [ 0 ] , L_76 ) )
V_58 = F_323 ( V_273 , V_284 , V_43 ) ;
else if ( ! strcasecmp ( V_284 [ 0 ] , L_77 ) )
V_58 = F_325 ( V_273 , V_284 , V_43 ) ;
else if ( ! strcasecmp ( V_284 [ 0 ] , L_78 ) )
V_58 = F_327 ( V_273 , V_284 , V_43 ) ;
else if ( ! strcasecmp ( V_284 [ 0 ] , L_79 ) )
V_58 = F_329 ( V_273 , V_284 , V_43 ) ;
else if ( ! strcasecmp ( V_284 [ 0 ] , L_80 ) )
V_58 = F_331 ( V_273 , V_284 , V_43 ) ;
else if ( ! strcasecmp ( V_284 [ 0 ] , L_81 ) )
V_58 = F_333 ( V_273 , V_284 , V_43 ) ;
else
F_141 ( L_82 , V_284 [ 0 ] ) ;
if ( ! V_58 )
( void ) F_138 ( V_43 ) ;
return V_58 ;
}
static void F_336 ( struct V_246 * V_140 , char * V_155 ,
unsigned V_316 , unsigned V_317 )
{
unsigned V_130 = ! V_140 -> V_141 + ! V_140 -> V_247 +
! V_140 -> V_217 + ( V_140 -> V_212 == V_148 ) +
V_140 -> V_158 ;
F_337 ( L_83 , V_130 ) ;
if ( ! V_140 -> V_141 )
F_337 ( L_84 ) ;
if ( ! V_140 -> V_247 )
F_337 ( L_85 ) ;
if ( ! V_140 -> V_217 )
F_337 ( L_86 ) ;
if ( V_140 -> V_212 == V_148 )
F_337 ( L_87 ) ;
if ( V_140 -> V_158 )
F_337 ( L_88 ) ;
}
static void F_338 ( struct V_226 * V_153 , T_9 type ,
unsigned V_318 , char * V_155 , unsigned V_317 )
{
int V_58 ;
unsigned V_316 = 0 ;
T_10 V_319 ;
T_1 V_320 ;
T_1 V_321 ;
T_1 V_322 ;
T_1 V_323 ;
T_1 V_324 ;
char V_243 [ V_244 ] ;
char V_325 [ V_244 ] ;
struct V_214 * V_215 = V_153 -> V_218 ;
struct V_43 * V_43 = V_215 -> V_43 ;
switch ( type ) {
case V_326 :
if ( F_135 ( V_43 ) == V_159 ) {
F_337 ( L_89 ) ;
break;
}
if ( ! ( V_318 & V_327 ) && ! F_339 ( V_153 ) )
( void ) F_138 ( V_43 ) ;
V_58 = F_340 ( V_43 -> V_120 , & V_319 ) ;
if ( V_58 ) {
F_230 ( L_90 ,
F_142 ( V_43 -> V_76 ) , V_58 ) ;
goto V_105;
}
V_58 = F_341 ( V_43 -> V_120 , & V_321 ) ;
if ( V_58 ) {
F_230 ( L_91 ,
F_142 ( V_43 -> V_76 ) , V_58 ) ;
goto V_105;
}
V_58 = F_308 ( V_43 -> V_120 , & V_323 ) ;
if ( V_58 ) {
F_230 ( L_92 ,
F_142 ( V_43 -> V_76 ) , V_58 ) ;
goto V_105;
}
V_58 = F_136 ( V_43 -> V_120 , & V_320 ) ;
if ( V_58 ) {
F_230 ( L_93 ,
F_142 ( V_43 -> V_76 ) , V_58 ) ;
goto V_105;
}
V_58 = F_305 ( V_43 -> V_120 , & V_322 ) ;
if ( V_58 ) {
F_230 ( L_94 ,
F_142 ( V_43 -> V_76 ) , V_58 ) ;
goto V_105;
}
V_58 = F_342 ( V_43 -> V_120 , & V_324 ) ;
if ( V_58 ) {
F_230 ( L_95 ,
F_142 ( V_43 -> V_76 ) , V_58 ) ;
goto V_105;
}
F_337 ( L_96 ,
( unsigned long long ) V_319 ,
( unsigned long long ) ( V_323 - V_321 ) ,
( unsigned long long ) V_323 ,
( unsigned long long ) ( V_322 - V_320 ) ,
( unsigned long long ) V_322 ) ;
if ( V_324 )
F_337 ( L_97 , V_324 ) ;
else
F_337 ( L_98 ) ;
if ( V_43 -> V_140 . V_212 == V_146 )
F_337 ( L_99 ) ;
else if ( V_43 -> V_140 . V_212 == V_148 )
F_337 ( L_100 ) ;
else
F_337 ( L_101 ) ;
if ( ! V_43 -> V_140 . V_247 )
F_337 ( L_85 ) ;
else if ( V_43 -> V_140 . V_217 )
F_337 ( L_102 ) ;
else
F_337 ( L_86 ) ;
if ( V_43 -> V_140 . V_158 )
F_337 ( L_88 ) ;
else
F_337 ( L_103 ) ;
if ( F_228 ( V_43 -> V_120 ) )
F_337 ( L_104 ) ;
else
F_337 ( L_98 ) ;
break;
case V_328 :
F_337 ( L_105 ,
F_343 ( V_243 , V_215 -> V_248 -> V_23 -> V_329 ) ,
F_343 ( V_325 , V_215 -> V_234 -> V_23 -> V_329 ) ,
( unsigned long ) V_43 -> V_45 ,
( unsigned long long ) V_215 -> V_151 ) ;
F_336 ( & V_215 -> V_223 , V_155 , V_316 , V_317 ) ;
break;
}
return;
V_105:
F_337 ( L_106 ) ;
}
static int F_344 ( struct V_226 * V_153 ,
T_11 F_35 , void * V_330 )
{
struct V_214 * V_215 = V_153 -> V_218 ;
return F_35 ( V_153 , V_215 -> V_234 , 0 , V_153 -> V_51 , V_330 ) ;
}
static void F_345 ( struct V_226 * V_153 , struct V_239 * V_241 )
{
struct V_214 * V_215 = V_153 -> V_218 ;
struct V_43 * V_43 = V_215 -> V_43 ;
T_2 V_331 = V_241 -> V_332 >> V_88 ;
if ( V_241 -> V_333 < V_43 -> V_45 ) {
while ( ! F_245 ( V_43 -> V_45 , V_241 -> V_333 ) ) {
if ( ( V_241 -> V_333 & ( V_241 -> V_333 - 1 ) ) == 0 )
V_241 -> V_333 -- ;
V_241 -> V_333 = F_346 ( V_241 -> V_333 ) ;
}
}
if ( V_331 < V_43 -> V_45 ||
! F_245 ( V_331 , V_43 -> V_45 ) ) {
if ( F_245 ( V_43 -> V_45 , V_241 -> V_333 ) )
F_347 ( V_241 , V_241 -> V_333 << V_88 ) ;
else
F_347 ( V_241 , V_43 -> V_45 << V_88 ) ;
F_348 ( V_241 , V_43 -> V_45 << V_88 ) ;
}
if ( ! V_215 -> V_216 . V_247 ) {
V_241 -> V_334 = 0 ;
return;
}
F_246 ( V_215 ) ;
}
static void F_201 ( struct V_46 * V_47 )
{
F_130 ( & V_47 -> V_335 ) ;
}
static void F_204 ( struct V_46 * V_47 )
{
if ( F_92 ( & V_47 -> V_335 ) )
F_216 ( & V_47 -> V_336 ) ;
}
static void F_349 ( struct V_226 * V_153 )
{
struct V_46 * V_47 = V_153 -> V_218 ;
unsigned long V_27 ;
F_63 ( & V_47 -> V_43 -> V_17 , V_27 ) ;
F_350 ( & V_47 -> V_72 ) ;
F_64 ( & V_47 -> V_43 -> V_17 , V_27 ) ;
F_351 () ;
F_204 ( V_47 ) ;
F_220 ( & V_47 -> V_336 ) ;
F_280 ( & V_69 . V_70 ) ;
F_277 ( V_47 -> V_43 ) ;
F_352 ( V_47 -> V_2 ) ;
F_281 ( V_153 , V_47 -> V_52 ) ;
if ( V_47 -> V_90 )
F_281 ( V_153 , V_47 -> V_90 ) ;
F_259 ( V_47 ) ;
F_282 ( & V_69 . V_70 ) ;
}
static int F_353 ( struct V_226 * V_153 , unsigned V_273 , char * * V_284 )
{
int V_58 ;
struct V_46 * V_47 ;
struct V_134 * V_52 , * V_90 ;
struct V_73 * V_76 ;
unsigned long V_27 ;
F_280 ( & V_69 . V_70 ) ;
if ( V_273 != 2 && V_273 != 3 ) {
V_153 -> error = L_49 ;
V_58 = - V_149 ;
goto V_287;
}
V_47 = V_153 -> V_218 = F_299 ( sizeof( * V_47 ) , V_253 ) ;
if ( ! V_47 ) {
V_153 -> error = L_107 ;
V_58 = - V_38 ;
goto V_287;
}
V_47 -> V_306 = F_300 ( V_153 -> V_154 ) ;
F_272 ( & V_47 -> V_17 ) ;
F_46 ( & V_47 -> V_82 ) ;
F_58 ( & V_47 -> V_83 ) ;
F_58 ( & V_47 -> V_84 ) ;
V_47 -> V_184 = V_337 ;
if ( V_273 == 3 ) {
V_58 = F_296 ( V_153 , V_284 [ 2 ] , V_288 , & V_90 ) ;
if ( V_58 ) {
V_153 -> error = L_108 ;
goto V_338;
}
V_47 -> V_90 = V_90 ;
}
V_58 = F_296 ( V_153 , V_284 [ 0 ] , F_354 ( V_153 -> V_154 ) , & V_52 ) ;
if ( V_58 ) {
V_153 -> error = L_109 ;
goto V_339;
}
V_47 -> V_52 = V_52 ;
if ( F_322 ( V_284 [ 1 ] , ( unsigned long long * ) & V_47 -> V_310 , 0 ) ) {
V_153 -> error = L_110 ;
V_58 = - V_149 ;
goto V_340;
}
V_76 = F_355 ( V_47 -> V_52 -> V_23 -> V_329 ) ;
if ( ! V_76 ) {
V_153 -> error = L_111 ;
V_58 = - V_149 ;
goto V_340;
}
V_47 -> V_43 = F_53 ( V_76 ) ;
if ( ! V_47 -> V_43 ) {
V_153 -> error = L_112 ;
V_58 = - V_149 ;
goto V_341;
}
F_276 ( V_47 -> V_43 ) ;
if ( F_135 ( V_47 -> V_43 ) == V_159 ) {
V_153 -> error = L_113 ;
V_58 = - V_149 ;
goto V_254;
}
V_58 = F_356 ( V_47 -> V_43 -> V_120 , V_47 -> V_310 , & V_47 -> V_2 ) ;
if ( V_58 ) {
V_153 -> error = L_114 ;
goto V_254;
}
V_58 = F_357 ( V_153 , V_47 -> V_43 -> V_45 ) ;
if ( V_58 )
goto V_342;
V_153 -> V_295 = 1 ;
V_153 -> V_343 = true ;
V_153 -> V_344 = sizeof( struct V_94 ) ;
V_153 -> V_296 = true ;
if ( V_47 -> V_43 -> V_140 . V_247 ) {
V_153 -> V_298 = true ;
V_153 -> V_297 = 1 ;
V_153 -> V_345 = false ;
}
F_282 ( & V_69 . V_70 ) ;
F_63 ( & V_47 -> V_43 -> V_17 , V_27 ) ;
if ( V_47 -> V_43 -> V_261 ) {
F_64 ( & V_47 -> V_43 -> V_17 , V_27 ) ;
F_280 ( & V_69 . V_70 ) ;
V_153 -> error = L_115 ;
V_58 = - V_149 ;
goto V_342;
}
F_127 ( & V_47 -> V_335 , 1 ) ;
F_219 ( & V_47 -> V_336 ) ;
F_358 ( & V_47 -> V_72 , & V_47 -> V_43 -> V_200 ) ;
F_64 ( & V_47 -> V_43 -> V_17 , V_27 ) ;
F_351 () ;
F_359 ( V_76 ) ;
return 0 ;
V_342:
F_352 ( V_47 -> V_2 ) ;
V_254:
F_277 ( V_47 -> V_43 ) ;
V_341:
F_359 ( V_76 ) ;
V_340:
F_281 ( V_153 , V_47 -> V_52 ) ;
V_339:
if ( V_47 -> V_90 )
F_281 ( V_153 , V_47 -> V_90 ) ;
V_338:
F_259 ( V_47 ) ;
V_287:
F_282 ( & V_69 . V_70 ) ;
return V_58 ;
}
static int F_360 ( struct V_226 * V_153 , struct V_28 * V_28 )
{
V_28 -> V_39 . V_40 = F_361 ( V_153 , V_28 -> V_39 . V_40 ) ;
return F_239 ( V_153 , V_28 ) ;
}
static int F_362 ( struct V_226 * V_153 , struct V_28 * V_28 , int V_105 )
{
unsigned long V_27 ;
struct V_94 * V_95 = F_82 ( V_28 , sizeof( struct V_94 ) ) ;
struct V_80 V_307 ;
struct V_99 * V_100 , * V_75 ;
struct V_43 * V_43 = V_95 -> V_47 -> V_43 ;
if ( V_95 -> V_172 ) {
F_46 ( & V_307 ) ;
F_363 ( V_95 -> V_172 , & V_307 ) ;
F_63 ( & V_43 -> V_17 , V_27 ) ;
F_67 (m, tmp, &work, list) {
F_52 ( & V_100 -> V_72 ) ;
F_91 ( V_100 ) ;
}
F_64 ( & V_43 -> V_17 , V_27 ) ;
}
if ( V_95 -> V_96 ) {
F_46 ( & V_307 ) ;
F_363 ( V_95 -> V_96 , & V_307 ) ;
if ( ! F_197 ( & V_307 ) ) {
F_63 ( & V_43 -> V_17 , V_27 ) ;
F_67 (m, tmp, &work, list)
F_93 ( & V_100 -> V_72 , & V_43 -> V_205 ) ;
F_64 ( & V_43 -> V_17 , V_27 ) ;
F_26 ( V_43 ) ;
}
}
if ( V_95 -> V_62 )
F_97 ( V_95 -> V_47 , V_95 -> V_62 ) ;
return 0 ;
}
static void F_364 ( struct V_226 * V_153 )
{
struct V_46 * V_47 = V_153 -> V_218 ;
if ( F_365 ( V_153 ) )
V_210 ( V_47 , F_222 ) ;
}
static void F_366 ( struct V_226 * V_153 )
{
struct V_46 * V_47 = V_153 -> V_218 ;
V_210 ( V_47 , F_223 ) ;
}
static int F_367 ( struct V_226 * V_153 )
{
struct V_46 * V_47 = V_153 -> V_218 ;
if ( V_47 -> V_90 )
V_47 -> V_144 = F_287 ( V_47 -> V_90 -> V_23 ) ;
return 0 ;
}
static void F_368 ( struct V_226 * V_153 , T_9 type ,
unsigned V_318 , char * V_155 , unsigned V_317 )
{
int V_58 ;
T_12 V_316 = 0 ;
T_1 V_346 , V_347 ;
char V_243 [ V_244 ] ;
struct V_46 * V_47 = V_153 -> V_218 ;
if ( F_135 ( V_47 -> V_43 ) == V_159 ) {
F_337 ( L_89 ) ;
return;
}
if ( ! V_47 -> V_2 )
F_337 ( L_116 ) ;
else {
switch ( type ) {
case V_326 :
V_58 = F_369 ( V_47 -> V_2 , & V_346 ) ;
if ( V_58 ) {
F_230 ( L_117 , V_58 ) ;
goto V_105;
}
V_58 = F_370 ( V_47 -> V_2 , & V_347 ) ;
if ( V_58 < 0 ) {
F_230 ( L_118 , V_58 ) ;
goto V_105;
}
F_337 ( L_97 , V_346 * V_47 -> V_43 -> V_45 ) ;
if ( V_58 )
F_337 ( L_119 , ( ( V_347 + 1 ) *
V_47 -> V_43 -> V_45 ) - 1 ) ;
else
F_337 ( L_116 ) ;
break;
case V_328 :
F_337 ( L_120 ,
F_343 ( V_243 , V_47 -> V_52 -> V_23 -> V_329 ) ,
( unsigned long ) V_47 -> V_310 ) ;
if ( V_47 -> V_90 )
F_337 ( L_121 , F_343 ( V_243 , V_47 -> V_90 -> V_23 -> V_329 ) ) ;
break;
}
}
return;
V_105:
F_337 ( L_106 ) ;
}
static int F_371 ( struct V_226 * V_153 ,
T_11 F_35 , void * V_330 )
{
T_2 V_348 ;
struct V_46 * V_47 = V_153 -> V_218 ;
struct V_43 * V_43 = V_47 -> V_43 ;
if ( ! V_43 -> V_153 )
return 0 ;
V_348 = V_43 -> V_153 -> V_51 ;
( void ) F_75 ( V_348 , V_43 -> V_45 ) ;
if ( V_348 )
return F_35 ( V_153 , V_47 -> V_52 , 0 , V_43 -> V_45 * V_348 , V_330 ) ;
return 0 ;
}
static void F_372 ( struct V_226 * V_153 , struct V_239 * V_241 )
{
struct V_46 * V_47 = V_153 -> V_218 ;
struct V_43 * V_43 = V_47 -> V_43 ;
if ( ! V_43 -> V_140 . V_247 )
return;
V_241 -> V_334 = V_43 -> V_45 << V_88 ;
V_241 -> V_245 = 2048 * 1024 * 16 ;
}
static int T_13 F_373 ( void )
{
int V_58 ;
F_44 () ;
V_58 = F_374 ( & V_349 ) ;
if ( V_58 )
return V_58 ;
V_58 = F_374 ( & V_350 ) ;
if ( V_58 )
goto V_351;
V_58 = - V_38 ;
V_265 = F_375 ( V_99 , 0 ) ;
if ( ! V_265 )
goto V_352;
return 0 ;
V_352:
F_376 ( & V_350 ) ;
V_351:
F_376 ( & V_349 ) ;
return V_58 ;
}
static void F_377 ( void )
{
F_376 ( & V_349 ) ;
F_376 ( & V_350 ) ;
F_378 ( V_265 ) ;
}
