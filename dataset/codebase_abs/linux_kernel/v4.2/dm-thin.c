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
unsigned int V_34 , V_35 ;
int V_36 ;
struct V_28 * V_28 ;
int V_37 = 0 ;
struct V_38 V_39 ;
if ( ! V_31 )
return - V_40 ;
if ( ! F_18 ( V_31 ) )
return - V_41 ;
V_35 = F_19 ( V_31 -> V_42 . V_43 >> 9 , 1U ) ;
V_36 = ( F_20 ( V_23 ) >> 9 ) % V_35 ;
V_34 = F_21 ( V_31 -> V_42 . V_34 , V_44 >> 9 ) ;
V_34 -= V_34 % V_35 ;
if ( F_22 ( ! V_34 ) ) {
return - V_41 ;
}
if ( V_27 & V_45 ) {
if ( ! F_23 ( V_31 ) )
return - V_41 ;
type |= V_46 ;
}
F_24 ( & V_39 ) ;
while ( V_25 ) {
unsigned int V_47 ;
T_2 V_48 , V_49 ;
V_28 = F_25 ( V_26 , 1 ) ;
if ( ! V_28 ) {
V_37 = - V_50 ;
break;
}
V_47 = F_26 ( T_2 , V_25 , V_34 ) ;
V_48 = V_24 + V_47 ;
V_49 = V_48 ;
if ( V_47 < V_25 &&
F_27 ( V_49 , V_35 ) != V_36 ) {
V_48 = V_48 - V_36 ;
F_27 ( V_48 , V_35 ) ;
V_48 = V_48 * V_35 + V_36 ;
V_47 = V_48 - V_24 ;
}
F_28 ( V_28 , V_29 ) ;
V_28 -> V_51 . V_52 = V_24 ;
V_28 -> V_53 = V_23 ;
V_28 -> V_51 . V_54 = V_47 << 9 ;
V_25 -= V_47 ;
V_24 = V_48 ;
F_29 ( type , V_28 ) ;
F_30 () ;
}
F_31 ( & V_39 ) ;
return V_37 ;
}
static bool F_32 ( struct V_55 * V_55 )
{
return V_55 -> V_56 >= 0 ;
}
static T_2 F_33 ( struct V_55 * V_55 , T_1 V_5 )
{
return F_32 ( V_55 ) ?
( V_5 << V_55 -> V_56 ) :
( V_5 * V_55 -> V_57 ) ;
}
static int F_34 ( struct V_58 * V_59 , T_1 V_60 , T_1 V_61 ,
struct V_28 * V_29 )
{
T_2 V_62 = F_33 ( V_59 -> V_55 , V_60 ) ;
T_2 V_63 = F_33 ( V_59 -> V_55 , V_61 - V_60 ) ;
return F_16 ( V_59 -> V_64 -> V_23 , V_62 , V_63 ,
V_65 , 0 , V_29 ) ;
}
static void F_35 ( struct V_55 * V_55 )
{
F_36 ( V_55 -> V_66 , & V_55 -> V_67 ) ;
}
static int F_37 ( struct V_55 * V_55 , struct V_7 * V_8 , struct V_28 * V_28 ,
struct V_68 * * V_69 )
{
int V_70 ;
struct V_68 * V_71 ;
V_71 = F_38 ( V_55 -> V_72 , V_73 ) ;
V_70 = F_39 ( V_55 -> V_72 , V_8 , V_28 , V_71 , V_69 ) ;
if ( V_70 )
F_40 ( V_55 -> V_72 , V_71 ) ;
return V_70 ;
}
static void F_41 ( struct V_55 * V_55 ,
struct V_68 * V_74 ,
struct V_75 * V_76 )
{
F_42 ( V_55 -> V_72 , V_74 , V_76 ) ;
F_40 ( V_55 -> V_72 , V_74 ) ;
}
static void F_43 ( struct V_55 * V_55 ,
void (* F_44)( void * , struct V_68 * ) ,
void * V_77 ,
struct V_68 * V_74 )
{
F_45 ( V_55 -> V_72 , F_44 , V_77 , V_74 ) ;
F_40 ( V_55 -> V_72 , V_74 ) ;
}
static void F_46 ( struct V_55 * V_55 ,
struct V_68 * V_74 ,
struct V_75 * V_76 )
{
F_47 ( V_55 -> V_72 , V_74 , V_76 ) ;
F_40 ( V_55 -> V_72 , V_74 ) ;
}
static void F_48 ( struct V_55 * V_55 ,
struct V_68 * V_74 , int V_78 )
{
F_49 ( V_55 -> V_72 , V_74 , V_78 ) ;
F_40 ( V_55 -> V_72 , V_74 ) ;
}
static void F_50 ( struct V_55 * V_55 , struct V_68 * V_74 )
{
F_48 ( V_55 , V_74 , - V_79 ) ;
}
static void F_51 ( struct V_55 * V_55 , struct V_68 * V_74 )
{
F_48 ( V_55 , V_74 , 0 ) ;
}
static void F_52 ( struct V_55 * V_55 , struct V_68 * V_74 )
{
F_48 ( V_55 , V_74 , V_80 ) ;
}
static void F_53 ( void )
{
F_54 ( & V_81 . V_82 ) ;
F_55 ( & V_81 . V_83 ) ;
}
static void F_56 ( struct V_55 * V_55 )
{
F_57 ( ! F_58 ( & V_81 . V_82 ) ) ;
F_59 ( & V_55 -> V_84 , & V_81 . V_83 ) ;
}
static void F_60 ( struct V_55 * V_55 )
{
F_57 ( ! F_58 ( & V_81 . V_82 ) ) ;
F_61 ( & V_55 -> V_84 ) ;
}
static struct V_55 * F_62 ( struct V_85 * V_86 )
{
struct V_55 * V_55 = NULL , * V_49 ;
F_57 ( ! F_58 ( & V_81 . V_82 ) ) ;
F_63 (tmp, &dm_thin_pool_table.pools, list) {
if ( V_49 -> V_87 == V_86 ) {
V_55 = V_49 ;
break;
}
}
return V_55 ;
}
static struct V_55 * F_64 ( struct V_22 * V_88 )
{
struct V_55 * V_55 = NULL , * V_49 ;
F_57 ( ! F_58 ( & V_81 . V_82 ) ) ;
F_63 (tmp, &dm_thin_pool_table.pools, list) {
if ( V_49 -> V_88 == V_88 ) {
V_55 = V_49 ;
break;
}
}
return V_55 ;
}
static void F_65 ( struct V_75 * V_76 , struct V_75 * V_89 )
{
F_66 ( V_76 , V_89 ) ;
F_67 ( V_89 ) ;
}
static void F_68 ( struct V_75 * V_76 , int error )
{
struct V_28 * V_28 ;
while ( ( V_28 = F_69 ( V_76 ) ) )
F_70 ( V_28 , error ) ;
}
static void F_71 ( struct V_58 * V_59 , struct V_75 * V_89 , int error )
{
struct V_75 V_76 ;
unsigned long V_27 ;
F_67 ( & V_76 ) ;
F_72 ( & V_59 -> V_17 , V_27 ) ;
F_65 ( & V_76 , V_89 ) ;
F_73 ( & V_59 -> V_17 , V_27 ) ;
F_68 ( & V_76 , error ) ;
}
static void F_74 ( struct V_58 * V_59 )
{
struct V_55 * V_55 = V_59 -> V_55 ;
unsigned long V_27 ;
struct V_90 V_91 ;
struct V_68 * V_74 , * V_49 ;
F_55 ( & V_91 ) ;
F_72 ( & V_59 -> V_17 , V_27 ) ;
F_75 ( & V_59 -> V_92 , & V_91 ) ;
F_73 ( & V_59 -> V_17 , V_27 ) ;
F_76 (cell, tmp, &cells, user_list)
F_52 ( V_55 , V_74 ) ;
}
static void F_77 ( struct V_58 * V_59 )
{
struct V_75 V_76 ;
unsigned long V_27 ;
F_67 ( & V_76 ) ;
F_72 ( & V_59 -> V_17 , V_27 ) ;
F_65 ( & V_76 , & V_59 -> V_93 ) ;
F_65 ( & V_76 , & V_59 -> V_94 ) ;
F_73 ( & V_59 -> V_17 , V_27 ) ;
F_68 ( & V_76 , V_80 ) ;
F_74 ( V_59 ) ;
}
static void F_78 ( struct V_55 * V_55 , int error )
{
struct V_58 * V_59 ;
F_79 () ;
F_80 (tc, &pool->active_thins, list)
F_71 ( V_59 , & V_59 -> V_94 , error ) ;
F_81 () ;
}
static void F_82 ( struct V_55 * V_55 )
{
return F_78 ( V_55 , - V_79 ) ;
}
static T_1 F_83 ( struct V_58 * V_59 , struct V_28 * V_28 )
{
struct V_55 * V_55 = V_59 -> V_55 ;
T_2 V_95 = V_28 -> V_51 . V_52 ;
if ( F_32 ( V_55 ) )
V_95 >>= V_55 -> V_56 ;
else
( void ) F_27 ( V_95 , V_55 -> V_57 ) ;
return V_95 ;
}
static void F_84 ( struct V_58 * V_59 , struct V_28 * V_28 ,
T_1 * V_96 , T_1 * V_97 )
{
struct V_55 * V_55 = V_59 -> V_55 ;
T_2 V_5 = V_28 -> V_51 . V_52 ;
T_2 V_6 = V_5 + ( V_28 -> V_51 . V_54 >> V_98 ) ;
V_5 += V_55 -> V_57 - 1ull ;
if ( F_32 ( V_55 ) ) {
V_5 >>= V_55 -> V_56 ;
V_6 >>= V_55 -> V_56 ;
} else {
( void ) F_27 ( V_5 , V_55 -> V_57 ) ;
( void ) F_27 ( V_6 , V_55 -> V_57 ) ;
}
if ( V_6 < V_5 )
V_6 = V_5 ;
* V_96 = V_5 ;
* V_97 = V_6 ;
}
static void F_85 ( struct V_58 * V_59 , struct V_28 * V_28 , T_1 V_99 )
{
struct V_55 * V_55 = V_59 -> V_55 ;
T_2 V_52 = V_28 -> V_51 . V_52 ;
V_28 -> V_53 = V_59 -> V_64 -> V_23 ;
if ( F_32 ( V_55 ) )
V_28 -> V_51 . V_52 =
( V_99 << V_55 -> V_56 ) |
( V_52 & ( V_55 -> V_57 - 1 ) ) ;
else
V_28 -> V_51 . V_52 = ( V_99 * V_55 -> V_57 ) +
F_27 ( V_52 , V_55 -> V_57 ) ;
}
static void F_86 ( struct V_58 * V_59 , struct V_28 * V_28 )
{
V_28 -> V_53 = V_59 -> V_100 -> V_23 ;
}
static int F_87 ( struct V_58 * V_59 , struct V_28 * V_28 )
{
return ( V_28 -> V_101 & ( V_102 | V_103 ) ) &&
F_88 ( V_59 -> V_2 ) ;
}
static void F_89 ( struct V_55 * V_55 , struct V_28 * V_28 )
{
struct V_104 * V_105 ;
if ( V_28 -> V_101 & V_33 )
return;
V_105 = F_90 ( V_28 , sizeof( struct V_104 ) ) ;
V_105 -> V_106 = F_91 ( V_55 -> V_107 ) ;
}
static void F_92 ( struct V_58 * V_59 , struct V_28 * V_28 )
{
struct V_55 * V_55 = V_59 -> V_55 ;
unsigned long V_27 ;
if ( ! F_87 ( V_59 , V_28 ) ) {
F_93 ( V_28 ) ;
return;
}
if ( F_94 ( V_59 -> V_2 ) ) {
F_95 ( V_28 ) ;
return;
}
F_72 ( & V_55 -> V_17 , V_27 ) ;
F_96 ( & V_55 -> V_108 , V_28 ) ;
F_73 ( & V_55 -> V_17 , V_27 ) ;
}
static void F_97 ( struct V_58 * V_59 , struct V_28 * V_28 )
{
F_86 ( V_59 , V_28 ) ;
F_92 ( V_59 , V_28 ) ;
}
static void F_98 ( struct V_58 * V_59 , struct V_28 * V_28 ,
T_1 V_99 )
{
F_85 ( V_59 , V_28 , V_99 ) ;
F_92 ( V_59 , V_28 ) ;
}
static void F_99 ( struct V_109 * V_110 )
{
struct V_55 * V_55 = V_110 -> V_59 -> V_55 ;
if ( F_100 ( & V_110 -> V_111 ) ) {
F_101 ( & V_110 -> V_84 , & V_55 -> V_112 ) ;
F_35 ( V_55 ) ;
}
}
static void F_102 ( struct V_109 * V_110 )
{
unsigned long V_27 ;
struct V_55 * V_55 = V_110 -> V_59 -> V_55 ;
F_72 ( & V_55 -> V_17 , V_27 ) ;
F_99 ( V_110 ) ;
F_73 ( & V_55 -> V_17 , V_27 ) ;
}
static void F_103 ( int V_113 , unsigned long V_114 , void * V_77 )
{
struct V_109 * V_110 = V_77 ;
V_110 -> V_115 = V_113 || V_114 ? - V_79 : 0 ;
F_102 ( V_110 ) ;
}
static void F_104 ( struct V_28 * V_28 , int V_115 )
{
struct V_104 * V_105 = F_90 ( V_28 , sizeof( struct V_104 ) ) ;
struct V_109 * V_110 = V_105 -> V_116 ;
V_28 -> V_117 = V_110 -> V_118 ;
V_110 -> V_115 = V_115 ;
F_102 ( V_110 ) ;
}
static void F_105 ( struct V_58 * V_59 , struct V_68 * V_74 )
{
struct V_55 * V_55 = V_59 -> V_55 ;
unsigned long V_27 ;
F_72 ( & V_59 -> V_17 , V_27 ) ;
F_46 ( V_55 , V_74 , & V_59 -> V_93 ) ;
F_73 ( & V_59 -> V_17 , V_27 ) ;
F_35 ( V_55 ) ;
}
static void F_106 ( void * V_77 ,
struct V_68 * V_74 )
{
struct V_119 * V_120 = V_77 ;
struct V_28 * V_28 ;
while ( ( V_28 = F_69 ( & V_74 -> V_76 ) ) ) {
if ( V_28 -> V_101 & ( V_33 | V_102 | V_103 ) )
F_96 ( & V_120 -> V_121 , V_28 ) ;
else {
F_89 ( V_120 -> V_59 -> V_55 , V_28 ) ;
F_96 ( & V_120 -> V_122 , V_28 ) ;
}
}
}
static void F_107 ( struct V_58 * V_59 ,
struct V_68 * V_74 ,
T_1 V_99 )
{
struct V_28 * V_28 ;
struct V_119 V_120 ;
V_120 . V_59 = V_59 ;
F_67 ( & V_120 . V_121 ) ;
F_67 ( & V_120 . V_122 ) ;
F_43 ( V_59 -> V_55 , F_106 ,
& V_120 , V_74 ) ;
while ( ( V_28 = F_69 ( & V_120 . V_121 ) ) )
F_108 ( V_59 , V_28 ) ;
while ( ( V_28 = F_69 ( & V_120 . V_122 ) ) )
F_98 ( V_120 . V_59 , V_28 , V_99 ) ;
}
static void F_109 ( struct V_109 * V_110 )
{
F_50 ( V_110 -> V_59 -> V_55 , V_110 -> V_74 ) ;
F_61 ( & V_110 -> V_84 ) ;
F_110 ( V_110 , V_110 -> V_59 -> V_55 -> V_123 ) ;
}
static void F_111 ( struct V_109 * V_110 )
{
struct V_58 * V_59 = V_110 -> V_59 ;
struct V_55 * V_55 = V_59 -> V_55 ;
struct V_28 * V_28 = V_110 -> V_28 ;
int V_70 ;
if ( V_110 -> V_115 ) {
F_50 ( V_55 , V_110 -> V_74 ) ;
goto V_124;
}
V_70 = F_112 ( V_59 -> V_2 , V_110 -> V_125 , V_110 -> V_126 ) ;
if ( V_70 ) {
F_113 ( V_55 , L_1 , V_70 ) ;
F_50 ( V_55 , V_110 -> V_74 ) ;
goto V_124;
}
if ( V_28 ) {
F_107 ( V_59 , V_110 -> V_74 , V_110 -> V_126 ) ;
F_70 ( V_28 , 0 ) ;
} else {
F_89 ( V_59 -> V_55 , V_110 -> V_74 -> V_127 ) ;
F_98 ( V_59 , V_110 -> V_74 -> V_127 , V_110 -> V_126 ) ;
F_107 ( V_59 , V_110 -> V_74 , V_110 -> V_126 ) ;
}
V_124:
F_61 ( & V_110 -> V_84 ) ;
F_110 ( V_110 , V_55 -> V_123 ) ;
}
static void F_114 ( struct V_109 * V_110 )
{
struct V_58 * V_59 = V_110 -> V_59 ;
if ( V_110 -> V_74 )
F_105 ( V_59 , V_110 -> V_74 ) ;
F_110 ( V_110 , V_59 -> V_55 -> V_123 ) ;
}
static void F_115 ( struct V_109 * V_110 )
{
F_95 ( V_110 -> V_28 ) ;
F_114 ( V_110 ) ;
}
static void F_116 ( struct V_109 * V_110 )
{
F_70 ( V_110 -> V_28 , 0 ) ;
F_114 ( V_110 ) ;
}
static void F_117 ( struct V_109 * V_110 )
{
int V_70 ;
struct V_58 * V_59 = V_110 -> V_59 ;
V_70 = F_118 ( V_59 -> V_2 , V_110 -> V_74 -> V_8 . V_12 , V_110 -> V_74 -> V_8 . V_13 ) ;
if ( V_70 ) {
F_113 ( V_59 -> V_55 , L_2 , V_70 ) ;
F_95 ( V_110 -> V_28 ) ;
} else
F_70 ( V_110 -> V_28 , 0 ) ;
F_105 ( V_59 , V_110 -> V_74 ) ;
F_110 ( V_110 , V_59 -> V_55 -> V_123 ) ;
}
static int F_119 ( struct V_109 * V_110 )
{
int V_70 ;
bool V_128 = true ;
struct V_58 * V_59 = V_110 -> V_59 ;
struct V_55 * V_55 = V_59 -> V_55 ;
T_1 V_5 = V_110 -> V_126 , V_6 , V_97 = V_110 -> V_126 + V_110 -> V_129 - V_110 -> V_125 ;
while ( V_5 != V_97 ) {
for (; V_5 < V_97 ; V_5 ++ ) {
V_70 = F_120 ( V_55 -> V_130 , V_5 , & V_128 ) ;
if ( V_70 )
return V_70 ;
if ( ! V_128 )
break;
}
if ( V_5 == V_97 )
break;
for ( V_6 = V_5 + 1 ; V_6 != V_97 ; V_6 ++ ) {
V_70 = F_120 ( V_55 -> V_130 , V_6 , & V_128 ) ;
if ( V_70 )
return V_70 ;
if ( V_128 )
break;
}
V_70 = F_34 ( V_59 , V_5 , V_6 , V_110 -> V_28 ) ;
if ( V_70 )
return V_70 ;
V_5 = V_6 ;
}
return 0 ;
}
static void F_121 ( struct V_109 * V_110 )
{
int V_70 ;
struct V_58 * V_59 = V_110 -> V_59 ;
struct V_55 * V_55 = V_59 -> V_55 ;
V_70 = F_118 ( V_59 -> V_2 , V_110 -> V_125 , V_110 -> V_129 ) ;
if ( V_70 )
F_113 ( V_55 , L_2 , V_70 ) ;
else if ( V_110 -> V_131 )
V_70 = F_119 ( V_110 ) ;
else
V_70 = F_34 ( V_59 , V_110 -> V_126 , V_110 -> V_126 + ( V_110 -> V_129 - V_110 -> V_125 ) , V_110 -> V_28 ) ;
F_70 ( V_110 -> V_28 , V_70 ) ;
F_105 ( V_59 , V_110 -> V_74 ) ;
F_110 ( V_110 , V_55 -> V_123 ) ;
}
static void F_122 ( struct V_55 * V_55 , struct V_90 * V_132 ,
T_4 * F_44 )
{
unsigned long V_27 ;
struct V_90 V_133 ;
struct V_109 * V_110 , * V_49 ;
F_55 ( & V_133 ) ;
F_72 ( & V_55 -> V_17 , V_27 ) ;
F_75 ( V_132 , & V_133 ) ;
F_73 ( & V_55 -> V_17 , V_27 ) ;
F_76 ( V_110 , V_49 , & V_133 , V_84 )
( * F_44 ) ( V_110 ) ;
}
static int F_123 ( struct V_55 * V_55 , struct V_28 * V_28 )
{
return V_28 -> V_51 . V_54 ==
( V_55 -> V_57 << V_98 ) ;
}
static int F_124 ( struct V_55 * V_55 , struct V_28 * V_28 )
{
return ( F_125 ( V_28 ) == V_134 ) &&
F_123 ( V_55 , V_28 ) ;
}
static void F_126 ( struct V_28 * V_28 , T_5 * * V_135 ,
T_5 * F_44 )
{
* V_135 = V_28 -> V_117 ;
V_28 -> V_117 = F_44 ;
}
static int F_127 ( struct V_55 * V_55 )
{
if ( V_55 -> V_136 )
return 0 ;
V_55 -> V_136 = F_128 ( V_55 -> V_123 , V_137 ) ;
return V_55 -> V_136 ? 0 : - V_50 ;
}
static struct V_109 * F_129 ( struct V_55 * V_55 )
{
struct V_109 * V_110 = V_55 -> V_136 ;
F_57 ( ! V_55 -> V_136 ) ;
memset ( V_110 , 0 , sizeof( struct V_109 ) ) ;
F_55 ( & V_110 -> V_84 ) ;
V_110 -> V_28 = NULL ;
V_55 -> V_136 = NULL ;
return V_110 ;
}
static void F_130 ( struct V_58 * V_59 , struct V_109 * V_110 ,
T_2 V_96 , T_2 V_97 )
{
int V_70 ;
struct V_138 V_139 ;
V_139 . V_23 = V_59 -> V_64 -> V_23 ;
V_139 . V_24 = V_96 ;
V_139 . V_140 = V_97 - V_96 ;
V_70 = F_131 ( V_59 -> V_55 -> V_141 , 1 , & V_139 , 0 , F_103 , V_110 ) ;
if ( V_70 < 0 ) {
F_132 ( L_3 ) ;
F_103 ( 1 , 1 , V_110 ) ;
}
}
static void F_133 ( struct V_58 * V_59 , struct V_28 * V_28 ,
T_1 V_142 ,
struct V_109 * V_110 )
{
struct V_55 * V_55 = V_59 -> V_55 ;
struct V_104 * V_105 = F_90 ( V_28 , sizeof( struct V_104 ) ) ;
V_105 -> V_116 = V_110 ;
V_110 -> V_28 = V_28 ;
F_126 ( V_28 , & V_110 -> V_118 , F_104 ) ;
F_89 ( V_55 , V_28 ) ;
F_98 ( V_59 , V_28 , V_142 ) ;
}
static void F_134 ( struct V_58 * V_59 , T_1 V_143 ,
struct V_144 * V_145 , T_1 V_146 ,
T_1 V_147 ,
struct V_68 * V_74 , struct V_28 * V_28 ,
T_2 V_63 )
{
int V_70 ;
struct V_55 * V_55 = V_59 -> V_55 ;
struct V_109 * V_110 = F_129 ( V_55 ) ;
V_110 -> V_59 = V_59 ;
V_110 -> V_125 = V_143 ;
V_110 -> V_129 = V_143 + 1u ;
V_110 -> V_126 = V_147 ;
V_110 -> V_74 = V_74 ;
F_135 ( & V_110 -> V_111 , 3 ) ;
if ( ! F_136 ( V_55 -> V_148 , & V_110 -> V_84 ) )
F_102 ( V_110 ) ;
if ( F_124 ( V_55 , V_28 ) )
F_133 ( V_59 , V_28 , V_147 , V_110 ) ;
else {
struct V_138 V_149 , V_139 ;
V_149 . V_23 = V_145 -> V_23 ;
V_149 . V_24 = V_146 * V_55 -> V_57 ;
V_149 . V_140 = V_63 ;
V_139 . V_23 = V_59 -> V_64 -> V_23 ;
V_139 . V_24 = V_147 * V_55 -> V_57 ;
V_139 . V_140 = V_63 ;
V_70 = F_137 ( V_55 -> V_141 , & V_149 , 1 , & V_139 ,
0 , F_103 , V_110 ) ;
if ( V_70 < 0 ) {
F_132 ( L_4 ) ;
F_103 ( 1 , 1 , V_110 ) ;
}
if ( V_63 < V_55 -> V_57 && V_55 -> V_150 . V_151 ) {
F_138 ( & V_110 -> V_111 ) ;
F_130 ( V_59 , V_110 ,
V_147 * V_55 -> V_57 + V_63 ,
( V_147 + 1 ) * V_55 -> V_57 ) ;
}
}
F_102 ( V_110 ) ;
}
static void F_139 ( struct V_58 * V_59 , T_1 V_143 ,
T_1 V_146 , T_1 V_147 ,
struct V_68 * V_74 , struct V_28 * V_28 )
{
F_134 ( V_59 , V_143 , V_59 -> V_64 ,
V_146 , V_147 , V_74 , V_28 ,
V_59 -> V_55 -> V_57 ) ;
}
static void F_140 ( struct V_58 * V_59 , T_1 V_143 ,
T_1 V_126 , struct V_68 * V_74 ,
struct V_28 * V_28 )
{
struct V_55 * V_55 = V_59 -> V_55 ;
struct V_109 * V_110 = F_129 ( V_55 ) ;
F_135 ( & V_110 -> V_111 , 1 ) ;
V_110 -> V_59 = V_59 ;
V_110 -> V_125 = V_143 ;
V_110 -> V_129 = V_143 + 1u ;
V_110 -> V_126 = V_126 ;
V_110 -> V_74 = V_74 ;
if ( V_55 -> V_150 . V_151 ) {
if ( F_124 ( V_55 , V_28 ) )
F_133 ( V_59 , V_28 , V_126 , V_110 ) ;
else
F_130 ( V_59 , V_110 , V_126 * V_55 -> V_57 ,
( V_126 + 1 ) * V_55 -> V_57 ) ;
} else
F_111 ( V_110 ) ;
}
static void F_141 ( struct V_58 * V_59 , T_1 V_143 ,
T_1 V_147 ,
struct V_68 * V_74 , struct V_28 * V_28 )
{
struct V_55 * V_55 = V_59 -> V_55 ;
T_2 V_152 = V_143 * V_55 -> V_57 ;
T_2 V_153 = ( V_143 + 1 ) * V_55 -> V_57 ;
if ( V_153 <= V_59 -> V_154 )
F_134 ( V_59 , V_143 , V_59 -> V_100 ,
V_143 , V_147 , V_74 , V_28 ,
V_55 -> V_57 ) ;
else if ( V_152 < V_59 -> V_154 )
F_134 ( V_59 , V_143 , V_59 -> V_100 ,
V_143 , V_147 , V_74 , V_28 ,
V_59 -> V_154 - V_152 ) ;
else
F_140 ( V_59 , V_143 , V_147 , V_74 , V_28 ) ;
}
static void F_142 ( struct V_55 * V_55 )
{
int V_70 ;
T_1 V_155 ;
if ( F_143 ( V_55 ) != V_156 )
return;
V_70 = F_144 ( V_55 -> V_130 , & V_155 ) ;
if ( V_70 )
return;
if ( V_155 )
F_145 ( V_55 , V_157 ) ;
}
static int F_146 ( struct V_55 * V_55 )
{
int V_70 ;
if ( F_143 ( V_55 ) >= V_158 )
return - V_159 ;
V_70 = F_147 ( V_55 -> V_130 ) ;
if ( V_70 )
F_113 ( V_55 , L_5 , V_70 ) ;
else
F_142 ( V_55 ) ;
return V_70 ;
}
static void F_148 ( struct V_55 * V_55 , T_1 V_160 )
{
unsigned long V_27 ;
if ( V_160 <= V_55 -> V_161 && ! V_55 -> V_162 ) {
F_149 ( L_6 ,
F_150 ( V_55 -> V_87 ) ) ;
F_72 ( & V_55 -> V_17 , V_27 ) ;
V_55 -> V_162 = true ;
F_73 ( & V_55 -> V_17 , V_27 ) ;
F_151 ( V_55 -> V_163 -> V_164 ) ;
}
}
static int F_152 ( struct V_58 * V_59 , T_1 * V_165 )
{
int V_70 ;
T_1 V_160 ;
struct V_55 * V_55 = V_59 -> V_55 ;
if ( F_153 ( F_143 ( V_55 ) != V_157 ) )
return - V_159 ;
V_70 = F_144 ( V_55 -> V_130 , & V_160 ) ;
if ( V_70 ) {
F_113 ( V_55 , L_7 , V_70 ) ;
return V_70 ;
}
F_148 ( V_55 , V_160 ) ;
if ( ! V_160 ) {
V_70 = F_146 ( V_55 ) ;
if ( V_70 )
return V_70 ;
V_70 = F_144 ( V_55 -> V_130 , & V_160 ) ;
if ( V_70 ) {
F_113 ( V_55 , L_7 , V_70 ) ;
return V_70 ;
}
if ( ! V_160 ) {
F_145 ( V_55 , V_156 ) ;
return - V_166 ;
}
}
V_70 = F_154 ( V_55 -> V_130 , V_165 ) ;
if ( V_70 ) {
F_113 ( V_55 , L_8 , V_70 ) ;
return V_70 ;
}
return 0 ;
}
static void F_155 ( struct V_28 * V_28 )
{
struct V_104 * V_105 = F_90 ( V_28 , sizeof( struct V_104 ) ) ;
struct V_58 * V_59 = V_105 -> V_59 ;
unsigned long V_27 ;
F_72 ( & V_59 -> V_17 , V_27 ) ;
F_96 ( & V_59 -> V_94 , V_28 ) ;
F_73 ( & V_59 -> V_17 , V_27 ) ;
}
static int F_156 ( struct V_55 * V_55 )
{
enum V_167 V_110 = F_143 ( V_55 ) ;
switch ( V_110 ) {
case V_157 :
F_132 ( L_9 ) ;
return - V_79 ;
case V_156 :
return V_55 -> V_150 . V_168 ? - V_166 : 0 ;
case V_158 :
case V_169 :
return - V_79 ;
default:
F_132 ( L_10 ) ;
return - V_79 ;
}
}
static void F_157 ( struct V_55 * V_55 , struct V_28 * V_28 )
{
int error = F_156 ( V_55 ) ;
if ( error )
F_70 ( V_28 , error ) ;
else
F_155 ( V_28 ) ;
}
static void F_158 ( struct V_55 * V_55 , struct V_68 * V_74 )
{
struct V_28 * V_28 ;
struct V_75 V_76 ;
int error ;
error = F_156 ( V_55 ) ;
if ( error ) {
F_48 ( V_55 , V_74 , error ) ;
return;
}
F_67 ( & V_76 ) ;
F_41 ( V_55 , V_74 , & V_76 ) ;
while ( ( V_28 = F_69 ( & V_76 ) ) )
F_155 ( V_28 ) ;
}
static void F_159 ( struct V_58 * V_59 ,
struct V_68 * V_170 )
{
struct V_55 * V_55 = V_59 -> V_55 ;
struct V_109 * V_110 = F_129 ( V_55 ) ;
V_110 -> V_59 = V_59 ;
V_110 -> V_125 = V_170 -> V_8 . V_12 ;
V_110 -> V_129 = V_170 -> V_8 . V_13 ;
V_110 -> V_74 = V_170 ;
V_110 -> V_28 = V_170 -> V_127 ;
if ( ! F_136 ( V_55 -> V_107 , & V_110 -> V_84 ) )
V_55 -> V_171 ( V_110 ) ;
}
static inline void F_160 ( struct V_28 * V_28 )
{
V_28 -> V_172 |= ( 1 << V_173 ) ;
F_161 () ;
F_138 ( & V_28 -> V_174 ) ;
}
static void F_162 ( struct V_58 * V_59 , T_1 V_96 , T_1 V_97 ,
struct V_28 * V_28 )
{
struct V_55 * V_55 = V_59 -> V_55 ;
int V_70 ;
bool V_131 ;
struct V_7 V_175 ;
struct V_68 * V_176 ;
struct V_109 * V_110 ;
T_1 V_125 , V_129 , V_142 ;
while ( V_96 != V_97 ) {
V_70 = F_127 ( V_55 ) ;
if ( V_70 )
return;
V_70 = F_163 ( V_59 -> V_2 , V_96 , V_97 , & V_125 , & V_129 ,
& V_142 , & V_131 ) ;
if ( V_70 )
break;
F_1 ( V_59 -> V_2 , V_14 , V_142 , V_142 + ( V_129 - V_125 ) , & V_175 ) ;
if ( F_37 ( V_59 -> V_55 , & V_175 , NULL , & V_176 ) ) {
V_96 = V_129 ;
continue;
}
V_110 = F_129 ( V_55 ) ;
V_110 -> V_59 = V_59 ;
V_110 -> V_131 = V_131 ;
V_110 -> V_125 = V_125 ;
V_110 -> V_129 = V_129 ;
V_110 -> V_126 = V_142 ;
V_110 -> V_74 = V_176 ;
V_110 -> V_28 = V_28 ;
F_160 ( V_28 ) ;
if ( ! F_136 ( V_55 -> V_107 , & V_110 -> V_84 ) )
V_55 -> V_171 ( V_110 ) ;
V_96 = V_129 ;
}
}
static void F_164 ( struct V_58 * V_59 , struct V_68 * V_170 )
{
struct V_28 * V_28 = V_170 -> V_127 ;
struct V_104 * V_105 = F_90 ( V_28 , sizeof( struct V_104 ) ) ;
V_105 -> V_74 = V_170 ;
F_162 ( V_59 , V_170 -> V_8 . V_12 , V_170 -> V_8 . V_13 , V_28 ) ;
F_70 ( V_28 , 0 ) ;
}
static void F_165 ( struct V_58 * V_59 , struct V_28 * V_28 )
{
T_1 V_96 , V_97 ;
struct V_7 V_177 ;
struct V_68 * V_170 ;
F_84 ( V_59 , V_28 , & V_96 , & V_97 ) ;
if ( V_96 == V_97 ) {
F_70 ( V_28 , 0 ) ;
return;
}
F_1 ( V_59 -> V_2 , V_10 , V_96 , V_97 , & V_177 ) ;
if ( F_37 ( V_59 -> V_55 , & V_177 , V_28 , & V_170 ) )
return;
V_59 -> V_55 -> V_178 ( V_59 , V_170 ) ;
}
static void F_166 ( struct V_58 * V_59 , struct V_28 * V_28 , T_1 V_99 ,
struct V_7 * V_8 ,
struct V_179 * V_180 ,
struct V_68 * V_74 )
{
int V_70 ;
T_1 V_126 ;
struct V_55 * V_55 = V_59 -> V_55 ;
V_70 = F_152 ( V_59 , & V_126 ) ;
switch ( V_70 ) {
case 0 :
F_139 ( V_59 , V_99 , V_180 -> V_99 ,
V_126 , V_74 , V_28 ) ;
break;
case - V_166 :
F_158 ( V_55 , V_74 ) ;
break;
default:
F_132 ( L_11 ,
V_181 , V_70 ) ;
F_50 ( V_55 , V_74 ) ;
break;
}
}
static void F_167 ( void * V_77 ,
struct V_68 * V_74 )
{
struct V_119 * V_120 = V_77 ;
struct V_28 * V_28 ;
while ( ( V_28 = F_69 ( & V_74 -> V_76 ) ) ) {
if ( ( F_125 ( V_28 ) == V_134 ) ||
( V_28 -> V_101 & ( V_33 | V_102 | V_103 ) ) )
F_96 ( & V_120 -> V_121 , V_28 ) ;
else {
struct V_104 * V_105 = F_90 ( V_28 , sizeof( struct V_104 ) ) ; ;
V_105 -> V_182 = F_91 ( V_120 -> V_59 -> V_55 -> V_148 ) ;
F_89 ( V_120 -> V_59 -> V_55 , V_28 ) ;
F_96 ( & V_120 -> V_122 , V_28 ) ;
}
}
}
static void F_168 ( struct V_58 * V_59 ,
struct V_68 * V_74 ,
T_1 V_99 )
{
struct V_28 * V_28 ;
struct V_119 V_120 ;
V_120 . V_59 = V_59 ;
F_67 ( & V_120 . V_121 ) ;
F_67 ( & V_120 . V_122 ) ;
F_43 ( V_59 -> V_55 , F_167 ,
& V_120 , V_74 ) ;
while ( ( V_28 = F_69 ( & V_120 . V_121 ) ) )
F_108 ( V_59 , V_28 ) ;
while ( ( V_28 = F_69 ( & V_120 . V_122 ) ) )
F_98 ( V_59 , V_28 , V_99 ) ;
}
static void F_169 ( struct V_58 * V_59 , struct V_28 * V_28 ,
T_1 V_99 ,
struct V_179 * V_180 ,
struct V_68 * V_170 )
{
struct V_68 * V_176 ;
struct V_55 * V_55 = V_59 -> V_55 ;
struct V_7 V_8 ;
F_3 ( V_59 -> V_2 , V_180 -> V_99 , & V_8 ) ;
if ( F_37 ( V_55 , & V_8 , V_28 , & V_176 ) ) {
F_105 ( V_59 , V_170 ) ;
return;
}
if ( F_125 ( V_28 ) == V_134 && V_28 -> V_51 . V_54 ) {
F_166 ( V_59 , V_28 , V_99 , & V_8 , V_180 , V_176 ) ;
F_105 ( V_59 , V_170 ) ;
} else {
struct V_104 * V_105 = F_90 ( V_28 , sizeof( struct V_104 ) ) ;
V_105 -> V_182 = F_91 ( V_55 -> V_148 ) ;
F_89 ( V_55 , V_28 ) ;
F_98 ( V_59 , V_28 , V_180 -> V_99 ) ;
F_168 ( V_59 , V_176 , V_180 -> V_99 ) ;
F_168 ( V_59 , V_170 , V_180 -> V_99 ) ;
}
}
static void F_170 ( struct V_58 * V_59 , struct V_28 * V_28 , T_1 V_99 ,
struct V_68 * V_74 )
{
int V_70 ;
T_1 V_126 ;
struct V_55 * V_55 = V_59 -> V_55 ;
if ( ! V_28 -> V_51 . V_54 ) {
F_89 ( V_55 , V_28 ) ;
F_105 ( V_59 , V_74 ) ;
F_98 ( V_59 , V_28 , 0 ) ;
return;
}
if ( F_125 ( V_28 ) == V_183 ) {
F_171 ( V_28 ) ;
F_105 ( V_59 , V_74 ) ;
F_70 ( V_28 , 0 ) ;
return;
}
V_70 = F_152 ( V_59 , & V_126 ) ;
switch ( V_70 ) {
case 0 :
if ( V_59 -> V_100 )
F_141 ( V_59 , V_99 , V_126 , V_74 , V_28 ) ;
else
F_140 ( V_59 , V_99 , V_126 , V_74 , V_28 ) ;
break;
case - V_166 :
F_158 ( V_55 , V_74 ) ;
break;
default:
F_132 ( L_11 ,
V_181 , V_70 ) ;
F_50 ( V_55 , V_74 ) ;
break;
}
}
static void F_172 ( struct V_58 * V_59 , struct V_68 * V_74 )
{
int V_70 ;
struct V_55 * V_55 = V_59 -> V_55 ;
struct V_28 * V_28 = V_74 -> V_127 ;
T_1 V_99 = F_83 ( V_59 , V_28 ) ;
struct V_179 V_180 ;
if ( V_59 -> V_184 ) {
F_52 ( V_55 , V_74 ) ;
return;
}
V_70 = F_173 ( V_59 -> V_2 , V_99 , 1 , & V_180 ) ;
switch ( V_70 ) {
case 0 :
if ( V_180 . V_185 )
F_169 ( V_59 , V_28 , V_99 , & V_180 , V_74 ) ;
else {
F_89 ( V_55 , V_28 ) ;
F_98 ( V_59 , V_28 , V_180 . V_99 ) ;
F_107 ( V_59 , V_74 , V_180 . V_99 ) ;
}
break;
case - V_186 :
if ( F_125 ( V_28 ) == V_183 && V_59 -> V_100 ) {
F_89 ( V_55 , V_28 ) ;
F_105 ( V_59 , V_74 ) ;
if ( F_174 ( V_28 ) <= V_59 -> V_154 )
F_97 ( V_59 , V_28 ) ;
else if ( V_28 -> V_51 . V_52 < V_59 -> V_154 ) {
F_171 ( V_28 ) ;
V_28 -> V_51 . V_54 = ( V_59 -> V_154 - V_28 -> V_51 . V_52 ) << V_98 ;
F_97 ( V_59 , V_28 ) ;
} else {
F_171 ( V_28 ) ;
F_70 ( V_28 , 0 ) ;
}
} else
F_170 ( V_59 , V_28 , V_99 , V_74 ) ;
break;
default:
F_132 ( L_12 ,
V_181 , V_70 ) ;
F_105 ( V_59 , V_74 ) ;
F_95 ( V_28 ) ;
break;
}
}
static void F_175 ( struct V_58 * V_59 , struct V_28 * V_28 )
{
struct V_55 * V_55 = V_59 -> V_55 ;
T_1 V_99 = F_83 ( V_59 , V_28 ) ;
struct V_68 * V_74 ;
struct V_7 V_8 ;
F_4 ( V_59 -> V_2 , V_99 , & V_8 ) ;
if ( F_37 ( V_55 , & V_8 , V_28 , & V_74 ) )
return;
F_172 ( V_59 , V_74 ) ;
}
static void F_176 ( struct V_58 * V_59 , struct V_28 * V_28 ,
struct V_68 * V_74 )
{
int V_70 ;
int V_187 = F_125 ( V_28 ) ;
T_1 V_99 = F_83 ( V_59 , V_28 ) ;
struct V_179 V_180 ;
V_70 = F_173 ( V_59 -> V_2 , V_99 , 1 , & V_180 ) ;
switch ( V_70 ) {
case 0 :
if ( V_180 . V_185 && ( V_187 == V_134 ) && V_28 -> V_51 . V_54 ) {
F_157 ( V_59 -> V_55 , V_28 ) ;
if ( V_74 )
F_105 ( V_59 , V_74 ) ;
} else {
F_89 ( V_59 -> V_55 , V_28 ) ;
F_98 ( V_59 , V_28 , V_180 . V_99 ) ;
if ( V_74 )
F_107 ( V_59 , V_74 , V_180 . V_99 ) ;
}
break;
case - V_186 :
if ( V_74 )
F_105 ( V_59 , V_74 ) ;
if ( V_187 != V_183 ) {
F_157 ( V_59 -> V_55 , V_28 ) ;
break;
}
if ( V_59 -> V_100 ) {
F_89 ( V_59 -> V_55 , V_28 ) ;
F_97 ( V_59 , V_28 ) ;
break;
}
F_171 ( V_28 ) ;
F_70 ( V_28 , 0 ) ;
break;
default:
F_132 ( L_12 ,
V_181 , V_70 ) ;
if ( V_74 )
F_105 ( V_59 , V_74 ) ;
F_95 ( V_28 ) ;
break;
}
}
static void F_177 ( struct V_58 * V_59 , struct V_28 * V_28 )
{
F_176 ( V_59 , V_28 , NULL ) ;
}
static void F_178 ( struct V_58 * V_59 , struct V_68 * V_74 )
{
F_176 ( V_59 , V_74 -> V_127 , V_74 ) ;
}
static void F_179 ( struct V_58 * V_59 , struct V_28 * V_28 )
{
F_70 ( V_28 , 0 ) ;
}
static void F_180 ( struct V_58 * V_59 , struct V_28 * V_28 )
{
F_95 ( V_28 ) ;
}
static void F_181 ( struct V_58 * V_59 , struct V_68 * V_74 )
{
F_51 ( V_59 -> V_55 , V_74 ) ;
}
static void F_182 ( struct V_58 * V_59 , struct V_68 * V_74 )
{
F_50 ( V_59 -> V_55 , V_74 ) ;
}
static int F_183 ( struct V_55 * V_55 )
{
return ! F_184 ( V_20 , V_55 -> V_188 ,
V_55 -> V_188 + V_189 ) ;
}
static void F_185 ( struct V_58 * V_59 , struct V_28 * V_28 )
{
struct V_190 * * V_191 , * V_192 ;
struct V_104 * V_193 ;
T_2 V_52 = V_28 -> V_51 . V_52 ;
V_191 = & V_59 -> V_194 . V_190 ;
V_192 = NULL ;
while ( * V_191 ) {
V_192 = * V_191 ;
V_193 = F_186 ( V_192 ) ;
if ( V_52 < F_187 ( V_193 ) -> V_51 . V_52 )
V_191 = & ( * V_191 ) -> V_195 ;
else
V_191 = & ( * V_191 ) -> V_196 ;
}
V_193 = F_90 ( V_28 , sizeof( struct V_104 ) ) ;
F_188 ( & V_193 -> V_190 , V_192 , V_191 ) ;
F_189 ( & V_193 -> V_190 , & V_59 -> V_194 ) ;
}
static void F_190 ( struct V_58 * V_59 )
{
struct V_190 * V_197 ;
struct V_104 * V_193 ;
struct V_28 * V_28 ;
for ( V_197 = F_191 ( & V_59 -> V_194 ) ; V_197 ; V_197 = F_192 ( V_197 ) ) {
V_193 = F_186 ( V_197 ) ;
V_28 = F_187 ( V_193 ) ;
F_96 ( & V_59 -> V_93 , V_28 ) ;
F_193 ( & V_193 -> V_190 , & V_59 -> V_194 ) ;
}
F_153 ( ! F_194 ( & V_59 -> V_194 ) ) ;
}
static void F_195 ( struct V_58 * V_59 )
{
struct V_28 * V_28 ;
struct V_75 V_76 ;
F_67 ( & V_76 ) ;
F_66 ( & V_76 , & V_59 -> V_93 ) ;
F_67 ( & V_59 -> V_93 ) ;
while ( ( V_28 = F_69 ( & V_76 ) ) )
F_185 ( V_59 , V_28 ) ;
F_190 ( V_59 ) ;
}
static void F_196 ( struct V_58 * V_59 )
{
struct V_55 * V_55 = V_59 -> V_55 ;
unsigned long V_27 ;
struct V_28 * V_28 ;
struct V_75 V_76 ;
struct V_38 V_39 ;
unsigned V_140 = 0 ;
if ( V_59 -> V_184 ) {
F_71 ( V_59 , & V_59 -> V_93 , V_80 ) ;
return;
}
F_67 ( & V_76 ) ;
F_72 ( & V_59 -> V_17 , V_27 ) ;
if ( F_197 ( & V_59 -> V_93 ) ) {
F_73 ( & V_59 -> V_17 , V_27 ) ;
return;
}
F_195 ( V_59 ) ;
F_66 ( & V_76 , & V_59 -> V_93 ) ;
F_67 ( & V_59 -> V_93 ) ;
F_73 ( & V_59 -> V_17 , V_27 ) ;
F_24 ( & V_39 ) ;
while ( ( V_28 = F_69 ( & V_76 ) ) ) {
if ( F_127 ( V_55 ) ) {
F_72 ( & V_59 -> V_17 , V_27 ) ;
F_96 ( & V_59 -> V_93 , V_28 ) ;
F_66 ( & V_59 -> V_93 , & V_76 ) ;
F_73 ( & V_59 -> V_17 , V_27 ) ;
break;
}
if ( V_28 -> V_101 & V_33 )
V_55 -> V_198 ( V_59 , V_28 ) ;
else
V_55 -> F_175 ( V_59 , V_28 ) ;
if ( ( V_140 ++ & 127 ) == 0 ) {
F_8 ( & V_55 -> V_15 ) ;
F_198 ( V_55 -> V_130 ) ;
}
}
F_31 ( & V_39 ) ;
}
static int F_199 ( const void * V_199 , const void * V_200 )
{
struct V_68 * V_201 = * ( (struct V_68 * * ) V_199 ) ;
struct V_68 * V_202 = * ( (struct V_68 * * ) V_200 ) ;
F_57 ( ! V_201 -> V_127 ) ;
F_57 ( ! V_202 -> V_127 ) ;
if ( V_201 -> V_127 -> V_51 . V_52 < V_202 -> V_127 -> V_51 . V_52 )
return - 1 ;
if ( V_201 -> V_127 -> V_51 . V_52 > V_202 -> V_127 -> V_51 . V_52 )
return 1 ;
return 0 ;
}
static unsigned F_200 ( struct V_55 * V_55 , struct V_90 * V_91 )
{
unsigned V_140 = 0 ;
struct V_68 * V_74 , * V_49 ;
F_76 (cell, tmp, cells, user_list) {
if ( V_140 >= V_203 )
break;
V_55 -> V_204 [ V_140 ++ ] = V_74 ;
F_61 ( & V_74 -> V_205 ) ;
}
F_201 ( V_55 -> V_204 , V_140 , sizeof( V_74 ) , F_199 , NULL ) ;
return V_140 ;
}
static void F_202 ( struct V_58 * V_59 )
{
struct V_55 * V_55 = V_59 -> V_55 ;
unsigned long V_27 ;
struct V_90 V_91 ;
struct V_68 * V_74 ;
unsigned V_206 , V_207 , V_140 ;
F_55 ( & V_91 ) ;
F_72 ( & V_59 -> V_17 , V_27 ) ;
F_75 ( & V_59 -> V_92 , & V_91 ) ;
F_73 ( & V_59 -> V_17 , V_27 ) ;
if ( F_203 ( & V_91 ) )
return;
do {
V_140 = F_200 ( V_59 -> V_55 , & V_91 ) ;
for ( V_206 = 0 ; V_206 < V_140 ; V_206 ++ ) {
V_74 = V_55 -> V_204 [ V_206 ] ;
F_57 ( ! V_74 -> V_127 ) ;
if ( F_127 ( V_55 ) ) {
for ( V_207 = V_206 ; V_207 < V_140 ; V_207 ++ )
F_59 ( & V_55 -> V_204 [ V_207 ] -> V_205 , & V_91 ) ;
F_72 ( & V_59 -> V_17 , V_27 ) ;
F_204 ( & V_91 , & V_59 -> V_92 ) ;
F_73 ( & V_59 -> V_17 , V_27 ) ;
return;
}
if ( V_74 -> V_127 -> V_101 & V_33 )
V_55 -> V_178 ( V_59 , V_74 ) ;
else
V_55 -> F_172 ( V_59 , V_74 ) ;
}
} while ( ! F_203 ( & V_91 ) );
}
static struct V_58 * F_205 ( struct V_55 * V_55 )
{
struct V_58 * V_59 = NULL ;
F_79 () ;
if ( ! F_203 ( & V_55 -> V_208 ) ) {
V_59 = F_206 ( V_55 -> V_208 . V_209 , struct V_58 , V_84 ) ;
F_207 ( V_59 ) ;
}
F_81 () ;
return V_59 ;
}
static struct V_58 * F_208 ( struct V_55 * V_55 , struct V_58 * V_59 )
{
struct V_58 * V_210 = V_59 ;
F_79 () ;
F_209 (tc, &pool->active_thins, list) {
F_207 ( V_59 ) ;
F_210 ( V_210 ) ;
F_81 () ;
return V_59 ;
}
F_210 ( V_210 ) ;
F_81 () ;
return NULL ;
}
static void F_211 ( struct V_55 * V_55 )
{
unsigned long V_27 ;
struct V_28 * V_28 ;
struct V_75 V_76 ;
struct V_58 * V_59 ;
V_59 = F_205 ( V_55 ) ;
while ( V_59 ) {
F_202 ( V_59 ) ;
F_196 ( V_59 ) ;
V_59 = F_208 ( V_55 , V_59 ) ;
}
F_67 ( & V_76 ) ;
F_72 ( & V_55 -> V_17 , V_27 ) ;
F_66 ( & V_76 , & V_55 -> V_108 ) ;
F_67 ( & V_55 -> V_108 ) ;
F_73 ( & V_55 -> V_17 , V_27 ) ;
if ( F_197 ( & V_76 ) &&
! ( F_212 ( V_55 -> V_130 ) && F_183 ( V_55 ) ) )
return;
if ( F_146 ( V_55 ) ) {
while ( ( V_28 = F_69 ( & V_76 ) ) )
F_95 ( V_28 ) ;
return;
}
V_55 -> V_188 = V_20 ;
while ( ( V_28 = F_69 ( & V_76 ) ) )
F_93 ( V_28 ) ;
}
static void F_213 ( struct V_211 * V_212 )
{
struct V_55 * V_55 = F_214 ( V_212 , struct V_55 , V_67 ) ;
F_7 ( & V_55 -> V_15 ) ;
F_198 ( V_55 -> V_130 ) ;
F_8 ( & V_55 -> V_15 ) ;
F_122 ( V_55 , & V_55 -> V_112 , & V_55 -> F_111 ) ;
F_8 ( & V_55 -> V_15 ) ;
F_122 ( V_55 , & V_55 -> V_213 , & V_55 -> V_171 ) ;
F_8 ( & V_55 -> V_15 ) ;
F_211 ( V_55 ) ;
F_10 ( & V_55 -> V_15 ) ;
}
static void F_215 ( struct V_211 * V_212 )
{
struct V_55 * V_55 = F_214 ( F_216 ( V_212 ) , struct V_55 , V_214 ) ;
F_35 ( V_55 ) ;
F_217 ( V_55 -> V_66 , & V_55 -> V_214 , V_189 ) ;
}
static void F_218 ( struct V_211 * V_212 )
{
struct V_55 * V_55 = F_214 ( F_216 ( V_212 ) , struct V_55 ,
V_215 ) ;
if ( F_143 ( V_55 ) == V_156 && ! V_55 -> V_150 . V_168 ) {
V_55 -> V_150 . V_168 = true ;
F_219 ( V_55 ) ;
F_78 ( V_55 , - V_166 ) ;
}
}
static struct V_216 * F_220 ( struct V_211 * V_212 )
{
return F_214 ( V_212 , struct V_216 , V_67 ) ;
}
static void F_221 ( struct V_216 * V_217 )
{
F_222 ( & V_217 -> F_222 ) ;
}
static void F_223 ( struct V_216 * V_217 , struct V_55 * V_55 ,
void (* F_44)( struct V_211 * ) )
{
F_224 ( & V_217 -> V_67 , F_44 ) ;
F_225 ( & V_217 -> F_222 ) ;
F_36 ( V_55 -> V_66 , & V_217 -> V_67 ) ;
F_226 ( & V_217 -> F_222 ) ;
}
static struct V_218 * F_227 ( struct V_211 * V_212 )
{
return F_214 ( F_220 ( V_212 ) , struct V_218 , V_217 ) ;
}
static void F_228 ( struct V_211 * V_212 )
{
struct V_218 * V_219 = F_227 ( V_212 ) ;
V_219 -> V_59 -> V_184 = true ;
F_77 ( V_219 -> V_59 ) ;
F_221 ( & V_219 -> V_217 ) ;
}
static void F_229 ( struct V_211 * V_212 )
{
struct V_218 * V_219 = F_227 ( V_212 ) ;
V_219 -> V_59 -> V_184 = false ;
F_221 ( & V_219 -> V_217 ) ;
}
static void V_218 ( struct V_58 * V_59 , void (* F_44)( struct V_211 * ) )
{
struct V_218 V_219 ;
V_219 . V_59 = V_59 ;
F_223 ( & V_219 . V_217 , V_59 -> V_55 , F_44 ) ;
}
static enum V_167 F_143 ( struct V_55 * V_55 )
{
return V_55 -> V_150 . V_220 ;
}
static void F_230 ( struct V_55 * V_55 , const char * V_221 )
{
F_151 ( V_55 -> V_163 -> V_164 ) ;
F_231 ( L_13 ,
F_150 ( V_55 -> V_87 ) , V_221 ) ;
}
static void F_219 ( struct V_55 * V_55 )
{
if ( ! V_55 -> V_150 . V_168 )
F_230 ( V_55 , L_14 ) ;
else
F_230 ( V_55 , L_15 ) ;
}
static bool F_232 ( struct V_222 * V_223 )
{
return V_223 -> V_224 . V_225 ;
}
static void F_233 ( struct V_55 * V_55 )
{
struct V_222 * V_223 = V_55 -> V_163 -> V_226 ;
if ( F_232 ( V_223 ) ) {
V_55 -> V_178 = F_164 ;
V_55 -> V_171 = F_121 ;
} else {
V_55 -> V_178 = F_159 ;
V_55 -> V_171 = F_117 ;
}
}
static void F_145 ( struct V_55 * V_55 , enum V_167 V_221 )
{
struct V_222 * V_223 = V_55 -> V_163 -> V_226 ;
bool V_227 = F_234 ( V_55 -> V_130 ) ;
enum V_167 V_228 = F_143 ( V_55 ) ;
unsigned long V_215 = F_235 ( V_229 ) * V_230 ;
if ( V_221 == V_157 && V_227 ) {
F_236 ( L_16 ,
F_150 ( V_55 -> V_87 ) ) ;
if ( V_228 != V_221 )
V_221 = V_228 ;
else
V_221 = V_158 ;
}
if ( V_228 == V_169 )
V_221 = V_228 ;
switch ( V_221 ) {
case V_169 :
if ( V_228 != V_221 )
F_230 ( V_55 , L_17 ) ;
F_237 ( V_55 -> V_130 ) ;
V_55 -> F_175 = F_180 ;
V_55 -> V_198 = F_180 ;
V_55 -> F_172 = F_182 ;
V_55 -> V_178 = F_182 ;
V_55 -> F_111 = F_109 ;
V_55 -> V_171 = F_115 ;
F_82 ( V_55 ) ;
break;
case V_158 :
if ( V_228 != V_221 )
F_230 ( V_55 , L_18 ) ;
F_237 ( V_55 -> V_130 ) ;
V_55 -> F_175 = F_177 ;
V_55 -> V_198 = F_179 ;
V_55 -> F_172 = F_178 ;
V_55 -> V_178 = F_181 ;
V_55 -> F_111 = F_109 ;
V_55 -> V_171 = F_116 ;
F_82 ( V_55 ) ;
break;
case V_156 :
if ( V_228 != V_221 )
F_219 ( V_55 ) ;
V_55 -> F_175 = F_177 ;
V_55 -> V_198 = F_165 ;
V_55 -> F_172 = F_178 ;
V_55 -> F_111 = F_111 ;
F_233 ( V_55 ) ;
if ( ! V_55 -> V_150 . V_168 && V_215 )
F_217 ( V_55 -> V_66 , & V_55 -> V_215 , V_215 ) ;
break;
case V_157 :
if ( V_228 != V_221 )
F_230 ( V_55 , L_19 ) ;
F_238 ( V_55 -> V_130 ) ;
V_55 -> F_175 = F_175 ;
V_55 -> V_198 = F_165 ;
V_55 -> F_172 = F_172 ;
V_55 -> F_111 = F_111 ;
F_233 ( V_55 ) ;
break;
}
V_55 -> V_150 . V_220 = V_221 ;
V_223 -> V_224 . V_220 = V_221 ;
}
static void F_239 ( struct V_55 * V_55 )
{
const char * V_231 = F_150 ( V_55 -> V_87 ) ;
F_132 ( L_20 , V_231 ) ;
if ( F_240 ( V_55 -> V_130 ) ) {
F_236 ( L_21 , V_231 ) ;
F_145 ( V_55 , V_169 ) ;
}
if ( F_241 ( V_55 -> V_130 ) ) {
F_236 ( L_22 , V_231 ) ;
F_145 ( V_55 , V_169 ) ;
}
}
static void F_113 ( struct V_55 * V_55 , const char * V_232 , int V_70 )
{
F_132 ( L_23 ,
F_150 ( V_55 -> V_87 ) , V_232 , V_70 ) ;
F_239 ( V_55 ) ;
F_145 ( V_55 , V_158 ) ;
}
static void F_108 ( struct V_58 * V_59 , struct V_28 * V_28 )
{
unsigned long V_27 ;
struct V_55 * V_55 = V_59 -> V_55 ;
F_72 ( & V_59 -> V_17 , V_27 ) ;
F_96 ( & V_59 -> V_93 , V_28 ) ;
F_73 ( & V_59 -> V_17 , V_27 ) ;
F_35 ( V_55 ) ;
}
static void F_242 ( struct V_58 * V_59 , struct V_28 * V_28 )
{
struct V_55 * V_55 = V_59 -> V_55 ;
F_12 ( & V_55 -> V_15 ) ;
F_108 ( V_59 , V_28 ) ;
F_14 ( & V_55 -> V_15 ) ;
}
static void F_243 ( struct V_58 * V_59 , struct V_68 * V_74 )
{
unsigned long V_27 ;
struct V_55 * V_55 = V_59 -> V_55 ;
F_12 ( & V_55 -> V_15 ) ;
F_72 ( & V_59 -> V_17 , V_27 ) ;
F_101 ( & V_74 -> V_205 , & V_59 -> V_92 ) ;
F_73 ( & V_59 -> V_17 , V_27 ) ;
F_14 ( & V_55 -> V_15 ) ;
F_35 ( V_55 ) ;
}
static void F_244 ( struct V_58 * V_59 , struct V_28 * V_28 )
{
struct V_104 * V_105 = F_90 ( V_28 , sizeof( struct V_104 ) ) ;
V_105 -> V_59 = V_59 ;
V_105 -> V_182 = NULL ;
V_105 -> V_106 = NULL ;
V_105 -> V_116 = NULL ;
V_105 -> V_74 = NULL ;
}
static int F_245 ( struct V_233 * V_163 , struct V_28 * V_28 )
{
int V_70 ;
struct V_58 * V_59 = V_163 -> V_226 ;
T_1 V_99 = F_83 ( V_59 , V_28 ) ;
struct V_1 * V_2 = V_59 -> V_2 ;
struct V_179 V_165 ;
struct V_68 * V_170 , * V_176 ;
struct V_7 V_8 ;
F_244 ( V_59 , V_28 ) ;
if ( V_59 -> V_184 ) {
F_70 ( V_28 , V_80 ) ;
return V_234 ;
}
if ( F_143 ( V_59 -> V_55 ) == V_169 ) {
F_95 ( V_28 ) ;
return V_234 ;
}
if ( V_28 -> V_101 & ( V_33 | V_102 | V_103 ) ) {
F_242 ( V_59 , V_28 ) ;
return V_234 ;
}
F_4 ( V_59 -> V_2 , V_99 , & V_8 ) ;
if ( F_37 ( V_59 -> V_55 , & V_8 , V_28 , & V_170 ) )
return V_234 ;
V_70 = F_173 ( V_2 , V_99 , 0 , & V_165 ) ;
switch ( V_70 ) {
case 0 :
if ( F_22 ( V_165 . V_185 ) ) {
F_243 ( V_59 , V_170 ) ;
return V_234 ;
}
F_3 ( V_59 -> V_2 , V_165 . V_99 , & V_8 ) ;
if ( F_37 ( V_59 -> V_55 , & V_8 , V_28 , & V_176 ) ) {
F_105 ( V_59 , V_170 ) ;
return V_234 ;
}
F_89 ( V_59 -> V_55 , V_28 ) ;
F_105 ( V_59 , V_176 ) ;
F_105 ( V_59 , V_170 ) ;
F_85 ( V_59 , V_28 , V_165 . V_99 ) ;
return V_235 ;
case - V_186 :
case - V_236 :
F_243 ( V_59 , V_170 ) ;
return V_234 ;
default:
F_95 ( V_28 ) ;
F_105 ( V_59 , V_170 ) ;
return V_234 ;
}
}
static int F_246 ( struct V_237 * V_238 , int V_239 )
{
struct V_222 * V_223 = F_214 ( V_238 , struct V_222 , V_240 ) ;
struct V_30 * V_31 ;
if ( F_143 ( V_223 -> V_55 ) == V_156 )
return 1 ;
V_31 = F_17 ( V_223 -> V_241 -> V_23 ) ;
return F_247 ( & V_31 -> V_242 , V_239 ) ;
}
static void F_248 ( struct V_55 * V_55 )
{
unsigned long V_27 ;
struct V_58 * V_59 ;
F_79 () ;
F_80 (tc, &pool->active_thins, list) {
F_72 ( & V_59 -> V_17 , V_27 ) ;
F_66 ( & V_59 -> V_93 , & V_59 -> V_94 ) ;
F_67 ( & V_59 -> V_94 ) ;
F_73 ( & V_59 -> V_17 , V_27 ) ;
}
F_81 () ;
}
static bool F_249 ( struct V_222 * V_223 )
{
struct V_30 * V_31 = F_17 ( V_223 -> V_241 -> V_23 ) ;
return V_31 && F_18 ( V_31 ) ;
}
static bool F_250 ( T_2 V_243 , T_6 V_244 )
{
return ! F_27 ( V_243 , V_244 ) ;
}
static void F_251 ( struct V_222 * V_223 )
{
struct V_55 * V_55 = V_223 -> V_55 ;
struct V_22 * V_245 = V_223 -> V_241 -> V_23 ;
struct V_246 * V_247 = & F_17 ( V_245 ) -> V_42 ;
const char * V_248 = NULL ;
char V_249 [ V_250 ] ;
if ( ! V_223 -> V_224 . V_225 )
return;
if ( ! F_249 ( V_223 ) )
V_248 = L_24 ;
else if ( V_247 -> V_34 < V_55 -> V_57 )
V_248 = L_25 ;
if ( V_248 ) {
F_149 ( L_26 , F_252 ( V_245 , V_249 ) , V_248 ) ;
V_223 -> V_224 . V_225 = false ;
}
}
static int F_253 ( struct V_55 * V_55 , struct V_233 * V_163 )
{
struct V_222 * V_223 = V_163 -> V_226 ;
enum V_167 V_228 = F_143 ( V_55 ) ;
enum V_167 V_221 = V_223 -> V_224 . V_220 ;
V_223 -> V_224 . V_220 = V_228 ;
V_55 -> V_163 = V_163 ;
V_55 -> V_150 = V_223 -> V_224 ;
V_55 -> V_161 = V_223 -> V_161 ;
F_145 ( V_55 , V_221 ) ;
return 0 ;
}
static void F_254 ( struct V_55 * V_55 , struct V_233 * V_163 )
{
if ( V_55 -> V_163 == V_163 )
V_55 -> V_163 = NULL ;
}
static void F_255 ( struct V_251 * V_150 )
{
V_150 -> V_220 = V_157 ;
V_150 -> V_151 = true ;
V_150 -> V_252 = true ;
V_150 -> V_225 = true ;
V_150 -> V_168 = false ;
}
static void F_256 ( struct V_55 * V_55 )
{
F_60 ( V_55 ) ;
F_257 ( V_55 -> V_204 ) ;
if ( F_258 ( V_55 -> V_130 ) < 0 )
F_149 ( L_27 , V_181 ) ;
F_259 ( V_55 -> V_72 ) ;
F_260 ( V_55 -> V_141 ) ;
if ( V_55 -> V_66 )
F_261 ( V_55 -> V_66 ) ;
if ( V_55 -> V_136 )
F_110 ( V_55 -> V_136 , V_55 -> V_123 ) ;
F_262 ( V_55 -> V_123 ) ;
F_263 ( V_55 -> V_148 ) ;
F_263 ( V_55 -> V_107 ) ;
F_264 ( V_55 ) ;
}
static struct V_55 * F_265 ( struct V_85 * V_87 ,
struct V_22 * V_253 ,
unsigned long V_243 ,
int V_254 , char * * error )
{
int V_70 ;
void * V_255 ;
struct V_55 * V_55 ;
struct V_256 * V_130 ;
bool V_257 = V_254 ? false : true ;
V_130 = F_266 ( V_253 , V_243 , V_257 ) ;
if ( F_267 ( V_130 ) ) {
* error = L_28 ;
return (struct V_55 * ) V_130 ;
}
V_55 = F_268 ( sizeof( * V_55 ) , V_258 ) ;
if ( ! V_55 ) {
* error = L_29 ;
V_255 = F_269 ( - V_50 ) ;
goto V_259;
}
V_55 -> V_130 = V_130 ;
V_55 -> V_57 = V_243 ;
if ( V_243 & ( V_243 - 1 ) )
V_55 -> V_56 = - 1 ;
else
V_55 -> V_56 = F_270 ( V_243 ) ;
V_55 -> V_161 = 0 ;
F_255 ( & V_55 -> V_150 ) ;
V_55 -> V_72 = F_271 () ;
if ( ! V_55 -> V_72 ) {
* error = L_30 ;
V_255 = F_269 ( - V_50 ) ;
goto V_260;
}
V_55 -> V_141 = F_272 ( & V_261 ) ;
if ( F_267 ( V_55 -> V_141 ) ) {
V_70 = F_273 ( V_55 -> V_141 ) ;
* error = L_31 ;
V_255 = F_269 ( V_70 ) ;
goto V_262;
}
V_55 -> V_66 = F_274 ( L_32 V_263 , V_264 ) ;
if ( ! V_55 -> V_66 ) {
* error = L_33 ;
V_255 = F_269 ( - V_50 ) ;
goto V_265;
}
F_5 ( & V_55 -> V_15 ) ;
F_275 ( & V_55 -> V_67 , F_213 ) ;
F_276 ( & V_55 -> V_214 , F_215 ) ;
F_276 ( & V_55 -> V_215 , F_218 ) ;
F_277 ( & V_55 -> V_17 ) ;
F_67 ( & V_55 -> V_108 ) ;
F_55 ( & V_55 -> V_112 ) ;
F_55 ( & V_55 -> V_213 ) ;
F_55 ( & V_55 -> V_208 ) ;
V_55 -> V_162 = false ;
V_55 -> V_266 = true ;
V_55 -> V_148 = F_278 () ;
if ( ! V_55 -> V_148 ) {
* error = L_34 ;
V_255 = F_269 ( - V_50 ) ;
goto V_267;
}
V_55 -> V_107 = F_278 () ;
if ( ! V_55 -> V_107 ) {
* error = L_35 ;
V_255 = F_269 ( - V_50 ) ;
goto V_268;
}
V_55 -> V_136 = NULL ;
V_55 -> V_123 = F_279 ( V_269 ,
V_270 ) ;
if ( ! V_55 -> V_123 ) {
* error = L_36 ;
V_255 = F_269 ( - V_50 ) ;
goto V_271;
}
V_55 -> V_204 = F_280 ( sizeof( * V_55 -> V_204 ) * V_203 ) ;
if ( ! V_55 -> V_204 ) {
* error = L_37 ;
V_255 = F_269 ( - V_50 ) ;
goto V_272;
}
V_55 -> V_273 = 1 ;
V_55 -> V_188 = V_20 ;
V_55 -> V_87 = V_87 ;
V_55 -> V_88 = V_253 ;
F_56 ( V_55 ) ;
return V_55 ;
V_272:
F_262 ( V_55 -> V_123 ) ;
V_271:
F_263 ( V_55 -> V_107 ) ;
V_268:
F_263 ( V_55 -> V_148 ) ;
V_267:
F_261 ( V_55 -> V_66 ) ;
V_265:
F_260 ( V_55 -> V_141 ) ;
V_262:
F_259 ( V_55 -> V_72 ) ;
V_260:
F_264 ( V_55 ) ;
V_259:
if ( F_258 ( V_130 ) )
F_149 ( L_27 , V_181 ) ;
return V_255 ;
}
static void F_281 ( struct V_55 * V_55 )
{
F_57 ( ! F_58 ( & V_81 . V_82 ) ) ;
V_55 -> V_273 ++ ;
}
static void F_282 ( struct V_55 * V_55 )
{
F_57 ( ! F_58 ( & V_81 . V_82 ) ) ;
F_57 ( ! V_55 -> V_273 ) ;
if ( ! -- V_55 -> V_273 )
F_256 ( V_55 ) ;
}
static struct V_55 * F_283 ( struct V_85 * V_87 ,
struct V_22 * V_253 ,
unsigned long V_243 , int V_254 ,
char * * error , int * V_274 )
{
struct V_55 * V_55 = F_64 ( V_253 ) ;
if ( V_55 ) {
if ( V_55 -> V_87 != V_87 ) {
* error = L_38 ;
return F_269 ( - V_275 ) ;
}
F_281 ( V_55 ) ;
} else {
V_55 = F_62 ( V_87 ) ;
if ( V_55 ) {
if ( V_55 -> V_88 != V_253 ) {
* error = L_39 ;
return F_269 ( - V_159 ) ;
}
F_281 ( V_55 ) ;
} else {
V_55 = F_265 ( V_87 , V_253 , V_243 , V_254 , error ) ;
* V_274 = 1 ;
}
}
return V_55 ;
}
static void F_284 ( struct V_233 * V_163 )
{
struct V_222 * V_223 = V_163 -> V_226 ;
F_285 ( & V_81 . V_82 ) ;
F_254 ( V_223 -> V_55 , V_163 ) ;
F_282 ( V_223 -> V_55 ) ;
F_286 ( V_163 , V_223 -> V_253 ) ;
F_286 ( V_163 , V_223 -> V_241 ) ;
F_264 ( V_223 ) ;
F_287 ( & V_81 . V_82 ) ;
}
static int F_288 ( struct V_276 * V_277 , struct V_251 * V_150 ,
struct V_233 * V_163 )
{
int V_70 ;
unsigned V_278 ;
const char * V_279 ;
static struct V_280 V_281 [] = {
{ 0 , 4 , L_40 } ,
} ;
if ( ! V_277 -> V_278 )
return 0 ;
V_70 = F_289 ( V_281 , V_277 , & V_278 , & V_163 -> error ) ;
if ( V_70 )
return - V_159 ;
while ( V_278 && ! V_70 ) {
V_279 = F_290 ( V_277 ) ;
V_278 -- ;
if ( ! strcasecmp ( V_279 , L_41 ) )
V_150 -> V_151 = false ;
else if ( ! strcasecmp ( V_279 , L_42 ) )
V_150 -> V_252 = false ;
else if ( ! strcasecmp ( V_279 , L_43 ) )
V_150 -> V_225 = false ;
else if ( ! strcasecmp ( V_279 , L_44 ) )
V_150 -> V_220 = V_158 ;
else if ( ! strcasecmp ( V_279 , L_45 ) )
V_150 -> V_168 = true ;
else {
V_163 -> error = L_46 ;
V_70 = - V_159 ;
break;
}
}
return V_70 ;
}
static void F_291 ( void * V_77 )
{
struct V_55 * V_55 = V_77 ;
F_149 ( L_47 ,
F_150 ( V_55 -> V_87 ) ) ;
F_151 ( V_55 -> V_163 -> V_164 ) ;
}
static T_2 F_292 ( struct V_22 * V_23 )
{
return F_293 ( V_23 -> V_282 ) >> V_98 ;
}
static void F_294 ( struct V_22 * V_23 )
{
T_2 V_283 = F_292 ( V_23 ) ;
char V_284 [ V_250 ] ;
if ( V_283 > V_285 )
F_149 ( L_48 ,
F_252 ( V_23 , V_284 ) , V_286 ) ;
}
static T_2 F_295 ( struct V_22 * V_23 )
{
T_2 V_283 = F_292 ( V_23 ) ;
if ( V_283 > V_286 )
V_283 = V_286 ;
return V_283 ;
}
static T_1 F_296 ( struct V_22 * V_23 )
{
T_2 V_283 = F_295 ( V_23 ) ;
F_27 ( V_283 , V_287 ) ;
return V_283 ;
}
static T_1 F_297 ( struct V_222 * V_223 )
{
T_1 V_288 = F_296 ( V_223 -> V_253 -> V_23 ) / 4 ;
return F_21 ( ( T_1 ) 1024ULL , V_288 ) ;
}
static int F_298 ( struct V_233 * V_163 , unsigned V_278 , char * * V_289 )
{
int V_70 , V_290 = 0 ;
struct V_222 * V_223 ;
struct V_55 * V_55 ;
struct V_251 V_150 ;
struct V_276 V_277 ;
struct V_144 * V_241 ;
unsigned long V_243 ;
T_1 V_161 ;
struct V_144 * V_253 ;
T_7 V_291 ;
F_285 ( & V_81 . V_82 ) ;
if ( V_278 < 4 ) {
V_163 -> error = L_49 ;
V_70 = - V_159 ;
goto V_292;
}
V_277 . V_278 = V_278 ;
V_277 . V_289 = V_289 ;
F_255 ( & V_150 ) ;
F_299 ( & V_277 , 4 ) ;
V_70 = F_288 ( & V_277 , & V_150 , V_163 ) ;
if ( V_70 )
goto V_292;
V_291 = V_293 | ( ( V_150 . V_220 == V_158 ) ? 0 : V_294 ) ;
V_70 = F_300 ( V_163 , V_289 [ 0 ] , V_291 , & V_253 ) ;
if ( V_70 ) {
V_163 -> error = L_50 ;
goto V_292;
}
F_294 ( V_253 -> V_23 ) ;
V_70 = F_300 ( V_163 , V_289 [ 1 ] , V_293 | V_294 , & V_241 ) ;
if ( V_70 ) {
V_163 -> error = L_51 ;
goto V_295;
}
if ( F_301 ( V_289 [ 2 ] , 10 , & V_243 ) || ! V_243 ||
V_243 < V_296 ||
V_243 > V_297 ||
V_243 & ( V_296 - 1 ) ) {
V_163 -> error = L_52 ;
V_70 = - V_159 ;
goto V_124;
}
if ( F_302 ( V_289 [ 3 ] , 10 , ( unsigned long long * ) & V_161 ) ) {
V_163 -> error = L_53 ;
V_70 = - V_159 ;
goto V_124;
}
V_223 = F_303 ( sizeof( * V_223 ) , V_258 ) ;
if ( ! V_223 ) {
V_70 = - V_50 ;
goto V_124;
}
V_55 = F_283 ( F_304 ( V_163 -> V_164 ) , V_253 -> V_23 ,
V_243 , V_150 . V_220 == V_158 , & V_163 -> error , & V_290 ) ;
if ( F_267 ( V_55 ) ) {
V_70 = F_273 ( V_55 ) ;
goto V_298;
}
if ( ! V_290 && V_150 . V_252 != V_55 -> V_150 . V_252 ) {
V_163 -> error = L_54 ;
V_70 = - V_159 ;
goto V_299;
}
V_223 -> V_55 = V_55 ;
V_223 -> V_163 = V_163 ;
V_223 -> V_253 = V_253 ;
V_223 -> V_241 = V_241 ;
V_223 -> V_161 = V_161 ;
V_223 -> V_224 = V_223 -> V_300 = V_150 ;
V_163 -> V_301 = 1 ;
V_163 -> V_302 = true ;
if ( V_150 . V_252 && V_150 . V_225 ) {
V_163 -> V_303 = 1 ;
V_163 -> V_304 = true ;
}
V_163 -> V_226 = V_223 ;
V_70 = F_305 ( V_223 -> V_55 -> V_130 ,
F_297 ( V_223 ) ,
F_291 ,
V_55 ) ;
if ( V_70 )
goto V_298;
V_223 -> V_240 . V_305 = F_246 ;
F_306 ( V_163 -> V_164 , & V_223 -> V_240 ) ;
F_287 ( & V_81 . V_82 ) ;
return 0 ;
V_299:
F_282 ( V_55 ) ;
V_298:
F_264 ( V_223 ) ;
V_124:
F_286 ( V_163 , V_241 ) ;
V_295:
F_286 ( V_163 , V_253 ) ;
V_292:
F_287 ( & V_81 . V_82 ) ;
return V_70 ;
}
static int F_307 ( struct V_233 * V_163 , struct V_28 * V_28 )
{
int V_70 ;
struct V_222 * V_223 = V_163 -> V_226 ;
struct V_55 * V_55 = V_223 -> V_55 ;
unsigned long V_27 ;
F_72 ( & V_55 -> V_17 , V_27 ) ;
V_28 -> V_53 = V_223 -> V_241 -> V_23 ;
V_70 = V_235 ;
F_73 ( & V_55 -> V_17 , V_27 ) ;
return V_70 ;
}
static int F_308 ( struct V_233 * V_163 , bool * V_306 )
{
int V_70 ;
struct V_222 * V_223 = V_163 -> V_226 ;
struct V_55 * V_55 = V_223 -> V_55 ;
T_2 V_307 = V_163 -> V_63 ;
T_1 V_308 ;
* V_306 = false ;
( void ) F_27 ( V_307 , V_55 -> V_57 ) ;
V_70 = F_309 ( V_55 -> V_130 , & V_308 ) ;
if ( V_70 ) {
F_236 ( L_55 ,
F_150 ( V_55 -> V_87 ) ) ;
return V_70 ;
}
if ( V_307 < V_308 ) {
F_236 ( L_56 ,
F_150 ( V_55 -> V_87 ) ,
( unsigned long long ) V_307 , V_308 ) ;
return - V_159 ;
} else if ( V_307 > V_308 ) {
if ( F_234 ( V_55 -> V_130 ) ) {
F_236 ( L_57 ,
F_150 ( V_55 -> V_87 ) ) ;
return 0 ;
}
if ( V_308 )
F_231 ( L_58 ,
F_150 ( V_55 -> V_87 ) ,
V_308 , ( unsigned long long ) V_307 ) ;
V_70 = F_310 ( V_55 -> V_130 , V_307 ) ;
if ( V_70 ) {
F_113 ( V_55 , L_59 , V_70 ) ;
return V_70 ;
}
* V_306 = true ;
}
return 0 ;
}
static int F_311 ( struct V_233 * V_163 , bool * V_306 )
{
int V_70 ;
struct V_222 * V_223 = V_163 -> V_226 ;
struct V_55 * V_55 = V_223 -> V_55 ;
T_1 V_283 , V_309 ;
* V_306 = false ;
V_283 = F_296 ( V_55 -> V_88 ) ;
V_70 = F_312 ( V_55 -> V_130 , & V_309 ) ;
if ( V_70 ) {
F_236 ( L_60 ,
F_150 ( V_55 -> V_87 ) ) ;
return V_70 ;
}
if ( V_283 < V_309 ) {
F_236 ( L_61 ,
F_150 ( V_55 -> V_87 ) ,
V_283 , V_309 ) ;
return - V_159 ;
} else if ( V_283 > V_309 ) {
if ( F_234 ( V_55 -> V_130 ) ) {
F_236 ( L_62 ,
F_150 ( V_55 -> V_87 ) ) ;
return 0 ;
}
F_294 ( V_55 -> V_88 ) ;
F_231 ( L_63 ,
F_150 ( V_55 -> V_87 ) ,
V_309 , V_283 ) ;
V_70 = F_313 ( V_55 -> V_130 , V_283 ) ;
if ( V_70 ) {
F_113 ( V_55 , L_64 , V_70 ) ;
return V_70 ;
}
* V_306 = true ;
}
return 0 ;
}
static int F_314 ( struct V_233 * V_163 )
{
int V_70 ;
bool V_310 , V_311 ;
struct V_222 * V_223 = V_163 -> V_226 ;
struct V_55 * V_55 = V_223 -> V_55 ;
V_70 = F_253 ( V_55 , V_163 ) ;
if ( V_70 )
return V_70 ;
V_70 = F_308 ( V_163 , & V_310 ) ;
if ( V_70 )
return V_70 ;
V_70 = F_311 ( V_163 , & V_311 ) ;
if ( V_70 )
return V_70 ;
if ( V_310 || V_311 )
( void ) F_146 ( V_55 ) ;
return 0 ;
}
static void F_315 ( struct V_55 * V_55 )
{
struct V_58 * V_59 ;
V_59 = F_205 ( V_55 ) ;
while ( V_59 ) {
F_316 ( V_59 -> V_312 ) ;
V_59 = F_208 ( V_55 , V_59 ) ;
}
}
static void F_317 ( struct V_55 * V_55 )
{
struct V_58 * V_59 ;
V_59 = F_205 ( V_55 ) ;
while ( V_59 ) {
F_318 ( V_59 -> V_312 ) ;
V_59 = F_208 ( V_55 , V_59 ) ;
}
}
static void F_319 ( struct V_233 * V_163 )
{
struct V_222 * V_223 = V_163 -> V_226 ;
struct V_55 * V_55 = V_223 -> V_55 ;
unsigned long V_27 ;
F_248 ( V_55 ) ;
F_317 ( V_55 ) ;
F_72 ( & V_55 -> V_17 , V_27 ) ;
V_55 -> V_162 = false ;
V_55 -> V_266 = false ;
F_73 ( & V_55 -> V_17 , V_27 ) ;
F_215 ( & V_55 -> V_214 . V_313 ) ;
}
static void F_320 ( struct V_233 * V_163 )
{
struct V_222 * V_223 = V_163 -> V_226 ;
struct V_55 * V_55 = V_223 -> V_55 ;
unsigned long V_27 ;
F_72 ( & V_55 -> V_17 , V_27 ) ;
V_55 -> V_266 = true ;
F_73 ( & V_55 -> V_17 , V_27 ) ;
F_315 ( V_55 ) ;
}
static void F_321 ( struct V_233 * V_163 )
{
struct V_222 * V_223 = V_163 -> V_226 ;
struct V_55 * V_55 = V_223 -> V_55 ;
unsigned long V_27 ;
F_317 ( V_55 ) ;
F_72 ( & V_55 -> V_17 , V_27 ) ;
V_55 -> V_266 = false ;
F_73 ( & V_55 -> V_17 , V_27 ) ;
}
static void F_322 ( struct V_233 * V_163 )
{
struct V_222 * V_223 = V_163 -> V_226 ;
struct V_55 * V_55 = V_223 -> V_55 ;
F_323 ( & V_55 -> V_214 ) ;
F_323 ( & V_55 -> V_215 ) ;
F_324 ( V_55 -> V_66 ) ;
( void ) F_146 ( V_55 ) ;
}
static int F_325 ( unsigned V_278 , unsigned V_314 )
{
if ( V_278 != V_314 ) {
F_149 ( L_65 ,
V_278 , V_314 ) ;
return - V_159 ;
}
return 0 ;
}
static int F_326 ( char * V_315 , T_8 * V_316 , int V_317 )
{
if ( ! F_302 ( V_315 , 10 , ( unsigned long long * ) V_316 ) &&
* V_316 <= V_318 )
return 0 ;
if ( V_317 )
F_149 ( L_66 , V_315 ) ;
return - V_159 ;
}
static int F_327 ( unsigned V_278 , char * * V_289 , struct V_55 * V_55 )
{
T_8 V_316 ;
int V_70 ;
V_70 = F_325 ( V_278 , 2 ) ;
if ( V_70 )
return V_70 ;
V_70 = F_326 ( V_289 [ 1 ] , & V_316 , 1 ) ;
if ( V_70 )
return V_70 ;
V_70 = F_328 ( V_55 -> V_130 , V_316 ) ;
if ( V_70 ) {
F_149 ( L_67 ,
V_289 [ 1 ] ) ;
return V_70 ;
}
return 0 ;
}
static int F_329 ( unsigned V_278 , char * * V_289 , struct V_55 * V_55 )
{
T_8 V_316 ;
T_8 V_319 ;
int V_70 ;
V_70 = F_325 ( V_278 , 3 ) ;
if ( V_70 )
return V_70 ;
V_70 = F_326 ( V_289 [ 1 ] , & V_316 , 1 ) ;
if ( V_70 )
return V_70 ;
V_70 = F_326 ( V_289 [ 2 ] , & V_319 , 1 ) ;
if ( V_70 )
return V_70 ;
V_70 = F_330 ( V_55 -> V_130 , V_316 , V_319 ) ;
if ( V_70 ) {
F_149 ( L_68 ,
V_289 [ 1 ] , V_289 [ 2 ] ) ;
return V_70 ;
}
return 0 ;
}
static int F_331 ( unsigned V_278 , char * * V_289 , struct V_55 * V_55 )
{
T_8 V_316 ;
int V_70 ;
V_70 = F_325 ( V_278 , 2 ) ;
if ( V_70 )
return V_70 ;
V_70 = F_326 ( V_289 [ 1 ] , & V_316 , 1 ) ;
if ( V_70 )
return V_70 ;
V_70 = F_332 ( V_55 -> V_130 , V_316 ) ;
if ( V_70 )
F_149 ( L_69 , V_289 [ 1 ] ) ;
return V_70 ;
}
static int F_333 ( unsigned V_278 , char * * V_289 , struct V_55 * V_55 )
{
T_8 V_320 , V_321 ;
int V_70 ;
V_70 = F_325 ( V_278 , 3 ) ;
if ( V_70 )
return V_70 ;
if ( F_302 ( V_289 [ 1 ] , 10 , ( unsigned long long * ) & V_320 ) ) {
F_149 ( L_70 , V_289 [ 1 ] ) ;
return - V_159 ;
}
if ( F_302 ( V_289 [ 2 ] , 10 , ( unsigned long long * ) & V_321 ) ) {
F_149 ( L_71 , V_289 [ 2 ] ) ;
return - V_159 ;
}
V_70 = F_334 ( V_55 -> V_130 , V_320 , V_321 ) ;
if ( V_70 ) {
F_149 ( L_72 ,
V_289 [ 1 ] , V_289 [ 2 ] ) ;
return V_70 ;
}
return 0 ;
}
static int F_335 ( unsigned V_278 , char * * V_289 , struct V_55 * V_55 )
{
int V_70 ;
V_70 = F_325 ( V_278 , 1 ) ;
if ( V_70 )
return V_70 ;
( void ) F_146 ( V_55 ) ;
V_70 = F_336 ( V_55 -> V_130 ) ;
if ( V_70 )
F_149 ( L_73 ) ;
return V_70 ;
}
static int F_337 ( unsigned V_278 , char * * V_289 , struct V_55 * V_55 )
{
int V_70 ;
V_70 = F_325 ( V_278 , 1 ) ;
if ( V_70 )
return V_70 ;
V_70 = F_338 ( V_55 -> V_130 ) ;
if ( V_70 )
F_149 ( L_74 ) ;
return V_70 ;
}
static int F_339 ( struct V_233 * V_163 , unsigned V_278 , char * * V_289 )
{
int V_70 = - V_159 ;
struct V_222 * V_223 = V_163 -> V_226 ;
struct V_55 * V_55 = V_223 -> V_55 ;
if ( F_143 ( V_55 ) >= V_158 ) {
F_236 ( L_75 ,
F_150 ( V_55 -> V_87 ) ) ;
return - V_41 ;
}
if ( ! strcasecmp ( V_289 [ 0 ] , L_76 ) )
V_70 = F_327 ( V_278 , V_289 , V_55 ) ;
else if ( ! strcasecmp ( V_289 [ 0 ] , L_77 ) )
V_70 = F_329 ( V_278 , V_289 , V_55 ) ;
else if ( ! strcasecmp ( V_289 [ 0 ] , L_78 ) )
V_70 = F_331 ( V_278 , V_289 , V_55 ) ;
else if ( ! strcasecmp ( V_289 [ 0 ] , L_79 ) )
V_70 = F_333 ( V_278 , V_289 , V_55 ) ;
else if ( ! strcasecmp ( V_289 [ 0 ] , L_80 ) )
V_70 = F_335 ( V_278 , V_289 , V_55 ) ;
else if ( ! strcasecmp ( V_289 [ 0 ] , L_81 ) )
V_70 = F_337 ( V_278 , V_289 , V_55 ) ;
else
F_149 ( L_82 , V_289 [ 0 ] ) ;
if ( ! V_70 )
( void ) F_146 ( V_55 ) ;
return V_70 ;
}
static void F_340 ( struct V_251 * V_150 , char * V_165 ,
unsigned V_322 , unsigned V_323 )
{
unsigned V_140 = ! V_150 -> V_151 + ! V_150 -> V_252 +
! V_150 -> V_225 + ( V_150 -> V_220 == V_158 ) +
V_150 -> V_168 ;
F_341 ( L_83 , V_140 ) ;
if ( ! V_150 -> V_151 )
F_341 ( L_84 ) ;
if ( ! V_150 -> V_252 )
F_341 ( L_85 ) ;
if ( ! V_150 -> V_225 )
F_341 ( L_86 ) ;
if ( V_150 -> V_220 == V_158 )
F_341 ( L_87 ) ;
if ( V_150 -> V_168 )
F_341 ( L_88 ) ;
}
static void F_342 ( struct V_233 * V_163 , T_9 type ,
unsigned V_324 , char * V_165 , unsigned V_323 )
{
int V_70 ;
unsigned V_322 = 0 ;
T_10 V_325 ;
T_1 V_326 ;
T_1 V_327 ;
T_1 V_328 ;
T_1 V_329 ;
T_1 V_330 ;
char V_249 [ V_250 ] ;
char V_331 [ V_250 ] ;
struct V_222 * V_223 = V_163 -> V_226 ;
struct V_55 * V_55 = V_223 -> V_55 ;
switch ( type ) {
case V_332 :
if ( F_143 ( V_55 ) == V_169 ) {
F_341 ( L_89 ) ;
break;
}
if ( ! ( V_324 & V_333 ) && ! F_343 ( V_163 ) )
( void ) F_146 ( V_55 ) ;
V_70 = F_344 ( V_55 -> V_130 , & V_325 ) ;
if ( V_70 ) {
F_236 ( L_90 ,
F_150 ( V_55 -> V_87 ) , V_70 ) ;
goto V_115;
}
V_70 = F_345 ( V_55 -> V_130 , & V_327 ) ;
if ( V_70 ) {
F_236 ( L_91 ,
F_150 ( V_55 -> V_87 ) , V_70 ) ;
goto V_115;
}
V_70 = F_312 ( V_55 -> V_130 , & V_329 ) ;
if ( V_70 ) {
F_236 ( L_92 ,
F_150 ( V_55 -> V_87 ) , V_70 ) ;
goto V_115;
}
V_70 = F_144 ( V_55 -> V_130 , & V_326 ) ;
if ( V_70 ) {
F_236 ( L_93 ,
F_150 ( V_55 -> V_87 ) , V_70 ) ;
goto V_115;
}
V_70 = F_309 ( V_55 -> V_130 , & V_328 ) ;
if ( V_70 ) {
F_236 ( L_94 ,
F_150 ( V_55 -> V_87 ) , V_70 ) ;
goto V_115;
}
V_70 = F_346 ( V_55 -> V_130 , & V_330 ) ;
if ( V_70 ) {
F_236 ( L_95 ,
F_150 ( V_55 -> V_87 ) , V_70 ) ;
goto V_115;
}
F_341 ( L_96 ,
( unsigned long long ) V_325 ,
( unsigned long long ) ( V_329 - V_327 ) ,
( unsigned long long ) V_329 ,
( unsigned long long ) ( V_328 - V_326 ) ,
( unsigned long long ) V_328 ) ;
if ( V_330 )
F_341 ( L_97 , V_330 ) ;
else
F_341 ( L_98 ) ;
if ( V_55 -> V_150 . V_220 == V_156 )
F_341 ( L_99 ) ;
else if ( V_55 -> V_150 . V_220 == V_158 )
F_341 ( L_100 ) ;
else
F_341 ( L_101 ) ;
if ( ! V_55 -> V_150 . V_252 )
F_341 ( L_85 ) ;
else if ( V_55 -> V_150 . V_225 )
F_341 ( L_102 ) ;
else
F_341 ( L_86 ) ;
if ( V_55 -> V_150 . V_168 )
F_341 ( L_88 ) ;
else
F_341 ( L_103 ) ;
if ( F_234 ( V_55 -> V_130 ) )
F_341 ( L_104 ) ;
else
F_341 ( L_98 ) ;
break;
case V_334 :
F_341 ( L_105 ,
F_347 ( V_249 , V_223 -> V_253 -> V_23 -> V_335 ) ,
F_347 ( V_331 , V_223 -> V_241 -> V_23 -> V_335 ) ,
( unsigned long ) V_55 -> V_57 ,
( unsigned long long ) V_223 -> V_161 ) ;
F_340 ( & V_223 -> V_300 , V_165 , V_322 , V_323 ) ;
break;
}
return;
V_115:
F_341 ( L_106 ) ;
}
static int F_348 ( struct V_233 * V_163 ,
T_11 F_44 , void * V_336 )
{
struct V_222 * V_223 = V_163 -> V_226 ;
return F_44 ( V_163 , V_223 -> V_241 , 0 , V_163 -> V_63 , V_336 ) ;
}
static int F_349 ( struct V_233 * V_163 , struct V_337 * V_338 ,
struct V_339 * V_340 , int V_341 )
{
struct V_222 * V_223 = V_163 -> V_226 ;
struct V_30 * V_31 = F_17 ( V_223 -> V_241 -> V_23 ) ;
if ( ! V_31 -> V_342 )
return V_341 ;
V_338 -> V_53 = V_223 -> V_241 -> V_23 ;
return F_21 ( V_341 , V_31 -> V_342 ( V_31 , V_338 , V_340 ) ) ;
}
static void F_350 ( struct V_233 * V_163 , struct V_246 * V_42 )
{
struct V_222 * V_223 = V_163 -> V_226 ;
struct V_55 * V_55 = V_223 -> V_55 ;
T_2 V_343 = V_42 -> V_344 >> V_98 ;
if ( V_42 -> V_345 < V_55 -> V_57 ) {
while ( ! F_250 ( V_55 -> V_57 , V_42 -> V_345 ) ) {
if ( ( V_42 -> V_345 & ( V_42 -> V_345 - 1 ) ) == 0 )
V_42 -> V_345 -- ;
V_42 -> V_345 = F_351 ( V_42 -> V_345 ) ;
}
}
if ( V_343 < V_55 -> V_57 ||
! F_250 ( V_343 , V_55 -> V_57 ) ) {
if ( F_250 ( V_55 -> V_57 , V_42 -> V_345 ) )
F_352 ( V_42 , V_42 -> V_345 << V_98 ) ;
else
F_352 ( V_42 , V_55 -> V_57 << V_98 ) ;
F_353 ( V_42 , V_55 -> V_57 << V_98 ) ;
}
if ( ! V_223 -> V_224 . V_252 ) {
V_42 -> V_43 = 0 ;
return;
}
F_251 ( V_223 ) ;
}
static void F_207 ( struct V_58 * V_59 )
{
F_138 ( & V_59 -> V_346 ) ;
}
static void F_210 ( struct V_58 * V_59 )
{
if ( F_100 ( & V_59 -> V_346 ) )
F_222 ( & V_59 -> V_347 ) ;
}
static void F_354 ( struct V_233 * V_163 )
{
struct V_58 * V_59 = V_163 -> V_226 ;
unsigned long V_27 ;
F_72 ( & V_59 -> V_55 -> V_17 , V_27 ) ;
F_355 ( & V_59 -> V_84 ) ;
F_73 ( & V_59 -> V_55 -> V_17 , V_27 ) ;
F_356 () ;
F_210 ( V_59 ) ;
F_226 ( & V_59 -> V_347 ) ;
F_285 ( & V_81 . V_82 ) ;
F_282 ( V_59 -> V_55 ) ;
F_357 ( V_59 -> V_2 ) ;
F_286 ( V_163 , V_59 -> V_64 ) ;
if ( V_59 -> V_100 )
F_286 ( V_163 , V_59 -> V_100 ) ;
F_264 ( V_59 ) ;
F_287 ( & V_81 . V_82 ) ;
}
static int F_358 ( struct V_233 * V_163 , unsigned V_278 , char * * V_289 )
{
int V_70 ;
struct V_58 * V_59 ;
struct V_144 * V_64 , * V_100 ;
struct V_85 * V_87 ;
unsigned long V_27 ;
F_285 ( & V_81 . V_82 ) ;
if ( V_278 != 2 && V_278 != 3 ) {
V_163 -> error = L_49 ;
V_70 = - V_159 ;
goto V_292;
}
V_59 = V_163 -> V_226 = F_303 ( sizeof( * V_59 ) , V_258 ) ;
if ( ! V_59 ) {
V_163 -> error = L_107 ;
V_70 = - V_50 ;
goto V_292;
}
V_59 -> V_312 = F_304 ( V_163 -> V_164 ) ;
F_277 ( & V_59 -> V_17 ) ;
F_55 ( & V_59 -> V_92 ) ;
F_67 ( & V_59 -> V_93 ) ;
F_67 ( & V_59 -> V_94 ) ;
V_59 -> V_194 = V_348 ;
if ( V_278 == 3 ) {
V_70 = F_300 ( V_163 , V_289 [ 2 ] , V_293 , & V_100 ) ;
if ( V_70 ) {
V_163 -> error = L_108 ;
goto V_349;
}
V_59 -> V_100 = V_100 ;
}
V_70 = F_300 ( V_163 , V_289 [ 0 ] , F_359 ( V_163 -> V_164 ) , & V_64 ) ;
if ( V_70 ) {
V_163 -> error = L_109 ;
goto V_350;
}
V_59 -> V_64 = V_64 ;
if ( F_326 ( V_289 [ 1 ] , ( unsigned long long * ) & V_59 -> V_316 , 0 ) ) {
V_163 -> error = L_110 ;
V_70 = - V_159 ;
goto V_351;
}
V_87 = F_360 ( V_59 -> V_64 -> V_23 -> V_335 ) ;
if ( ! V_87 ) {
V_163 -> error = L_111 ;
V_70 = - V_159 ;
goto V_351;
}
V_59 -> V_55 = F_62 ( V_87 ) ;
if ( ! V_59 -> V_55 ) {
V_163 -> error = L_112 ;
V_70 = - V_159 ;
goto V_352;
}
F_281 ( V_59 -> V_55 ) ;
if ( F_143 ( V_59 -> V_55 ) == V_169 ) {
V_163 -> error = L_113 ;
V_70 = - V_159 ;
goto V_259;
}
V_70 = F_361 ( V_59 -> V_55 -> V_130 , V_59 -> V_316 , & V_59 -> V_2 ) ;
if ( V_70 ) {
V_163 -> error = L_114 ;
goto V_259;
}
V_70 = F_362 ( V_163 , V_59 -> V_55 -> V_57 ) ;
if ( V_70 )
goto V_353;
V_163 -> V_301 = 1 ;
V_163 -> V_354 = true ;
V_163 -> V_355 = sizeof( struct V_104 ) ;
V_163 -> V_302 = true ;
if ( V_59 -> V_55 -> V_150 . V_252 ) {
V_163 -> V_304 = true ;
V_163 -> V_303 = 1 ;
V_163 -> V_356 = false ;
}
F_287 ( & V_81 . V_82 ) ;
F_72 ( & V_59 -> V_55 -> V_17 , V_27 ) ;
if ( V_59 -> V_55 -> V_266 ) {
F_73 ( & V_59 -> V_55 -> V_17 , V_27 ) ;
F_285 ( & V_81 . V_82 ) ;
V_163 -> error = L_115 ;
V_70 = - V_159 ;
goto V_353;
}
F_135 ( & V_59 -> V_346 , 1 ) ;
F_225 ( & V_59 -> V_347 ) ;
F_363 ( & V_59 -> V_84 , & V_59 -> V_55 -> V_208 ) ;
F_73 ( & V_59 -> V_55 -> V_17 , V_27 ) ;
F_356 () ;
F_364 ( V_87 ) ;
return 0 ;
V_353:
F_357 ( V_59 -> V_2 ) ;
V_259:
F_282 ( V_59 -> V_55 ) ;
V_352:
F_364 ( V_87 ) ;
V_351:
F_286 ( V_163 , V_59 -> V_64 ) ;
V_350:
if ( V_59 -> V_100 )
F_286 ( V_163 , V_59 -> V_100 ) ;
V_349:
F_264 ( V_59 ) ;
V_292:
F_287 ( & V_81 . V_82 ) ;
return V_70 ;
}
static int F_365 ( struct V_233 * V_163 , struct V_28 * V_28 )
{
V_28 -> V_51 . V_52 = F_366 ( V_163 , V_28 -> V_51 . V_52 ) ;
return F_245 ( V_163 , V_28 ) ;
}
static int F_367 ( struct V_233 * V_163 , struct V_28 * V_28 , int V_115 )
{
unsigned long V_27 ;
struct V_104 * V_105 = F_90 ( V_28 , sizeof( struct V_104 ) ) ;
struct V_90 V_313 ;
struct V_109 * V_110 , * V_49 ;
struct V_55 * V_55 = V_105 -> V_59 -> V_55 ;
if ( V_105 -> V_182 ) {
F_55 ( & V_313 ) ;
F_368 ( V_105 -> V_182 , & V_313 ) ;
F_72 ( & V_55 -> V_17 , V_27 ) ;
F_76 (m, tmp, &work, list) {
F_61 ( & V_110 -> V_84 ) ;
F_99 ( V_110 ) ;
}
F_73 ( & V_55 -> V_17 , V_27 ) ;
}
if ( V_105 -> V_106 ) {
F_55 ( & V_313 ) ;
F_368 ( V_105 -> V_106 , & V_313 ) ;
if ( ! F_203 ( & V_313 ) ) {
F_72 ( & V_55 -> V_17 , V_27 ) ;
F_76 (m, tmp, &work, list)
F_101 ( & V_110 -> V_84 , & V_55 -> V_213 ) ;
F_73 ( & V_55 -> V_17 , V_27 ) ;
F_35 ( V_55 ) ;
}
}
if ( V_105 -> V_74 )
F_105 ( V_105 -> V_59 , V_105 -> V_74 ) ;
return 0 ;
}
static void F_369 ( struct V_233 * V_163 )
{
struct V_58 * V_59 = V_163 -> V_226 ;
if ( F_370 ( V_163 ) )
V_218 ( V_59 , F_228 ) ;
}
static void F_371 ( struct V_233 * V_163 )
{
struct V_58 * V_59 = V_163 -> V_226 ;
V_218 ( V_59 , F_229 ) ;
}
static int F_372 ( struct V_233 * V_163 )
{
struct V_58 * V_59 = V_163 -> V_226 ;
if ( V_59 -> V_100 )
V_59 -> V_154 = F_292 ( V_59 -> V_100 -> V_23 ) ;
return 0 ;
}
static void F_373 ( struct V_233 * V_163 , T_9 type ,
unsigned V_324 , char * V_165 , unsigned V_323 )
{
int V_70 ;
T_12 V_322 = 0 ;
T_1 V_357 , V_358 ;
char V_249 [ V_250 ] ;
struct V_58 * V_59 = V_163 -> V_226 ;
if ( F_143 ( V_59 -> V_55 ) == V_169 ) {
F_341 ( L_89 ) ;
return;
}
if ( ! V_59 -> V_2 )
F_341 ( L_116 ) ;
else {
switch ( type ) {
case V_332 :
V_70 = F_374 ( V_59 -> V_2 , & V_357 ) ;
if ( V_70 ) {
F_236 ( L_117 , V_70 ) ;
goto V_115;
}
V_70 = F_375 ( V_59 -> V_2 , & V_358 ) ;
if ( V_70 < 0 ) {
F_236 ( L_118 , V_70 ) ;
goto V_115;
}
F_341 ( L_97 , V_357 * V_59 -> V_55 -> V_57 ) ;
if ( V_70 )
F_341 ( L_119 , ( ( V_358 + 1 ) *
V_59 -> V_55 -> V_57 ) - 1 ) ;
else
F_341 ( L_116 ) ;
break;
case V_334 :
F_341 ( L_120 ,
F_347 ( V_249 , V_59 -> V_64 -> V_23 -> V_335 ) ,
( unsigned long ) V_59 -> V_316 ) ;
if ( V_59 -> V_100 )
F_341 ( L_121 , F_347 ( V_249 , V_59 -> V_100 -> V_23 -> V_335 ) ) ;
break;
}
}
return;
V_115:
F_341 ( L_106 ) ;
}
static int F_376 ( struct V_233 * V_163 , struct V_337 * V_338 ,
struct V_339 * V_340 , int V_341 )
{
struct V_58 * V_59 = V_163 -> V_226 ;
struct V_30 * V_31 = F_17 ( V_59 -> V_64 -> V_23 ) ;
if ( ! V_31 -> V_342 )
return V_341 ;
V_338 -> V_53 = V_59 -> V_64 -> V_23 ;
V_338 -> V_52 = F_366 ( V_163 , V_338 -> V_52 ) ;
return F_21 ( V_341 , V_31 -> V_342 ( V_31 , V_338 , V_340 ) ) ;
}
static int F_377 ( struct V_233 * V_163 ,
T_11 F_44 , void * V_336 )
{
T_2 V_359 ;
struct V_58 * V_59 = V_163 -> V_226 ;
struct V_55 * V_55 = V_59 -> V_55 ;
if ( ! V_55 -> V_163 )
return 0 ;
V_359 = V_55 -> V_163 -> V_63 ;
( void ) F_27 ( V_359 , V_55 -> V_57 ) ;
if ( V_359 )
return F_44 ( V_163 , V_59 -> V_64 , 0 , V_55 -> V_57 * V_359 , V_336 ) ;
return 0 ;
}
static void F_378 ( struct V_233 * V_163 , struct V_246 * V_42 )
{
struct V_58 * V_59 = V_163 -> V_226 ;
struct V_55 * V_55 = V_59 -> V_55 ;
V_42 -> V_43 = V_55 -> V_57 << V_98 ;
V_42 -> V_34 = 2048 * 1024 * 16 ;
}
static int T_13 F_379 ( void )
{
int V_70 ;
F_53 () ;
V_70 = F_380 ( & V_360 ) ;
if ( V_70 )
return V_70 ;
V_70 = F_380 ( & V_361 ) ;
if ( V_70 )
goto V_362;
V_70 = - V_50 ;
V_270 = F_381 ( V_109 , 0 ) ;
if ( ! V_270 )
goto V_363;
return 0 ;
V_363:
F_382 ( & V_361 ) ;
V_362:
F_382 ( & V_360 ) ;
return V_70 ;
}
static void F_383 ( void )
{
F_382 ( & V_360 ) ;
F_382 ( & V_361 ) ;
F_384 ( V_270 ) ;
}
