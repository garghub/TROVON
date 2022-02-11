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
static bool F_16 ( struct V_22 * V_22 )
{
return V_22 -> V_23 >= 0 ;
}
static T_2 F_17 ( struct V_22 * V_22 , T_1 V_5 )
{
return F_16 ( V_22 ) ?
( V_5 << V_22 -> V_23 ) :
( V_5 * V_22 -> V_24 ) ;
}
static void F_18 ( struct V_25 * V_26 , struct V_27 * V_28 , struct V_29 * V_30 )
{
F_19 ( ! V_30 ) ;
V_26 -> V_28 = V_28 ;
F_20 ( & V_26 -> V_31 ) ;
V_26 -> V_32 = V_30 ;
V_26 -> V_29 = NULL ;
}
static int F_21 ( struct V_25 * V_26 , T_1 V_33 , T_1 V_34 )
{
struct V_27 * V_28 = V_26 -> V_28 ;
T_2 V_35 = F_17 ( V_28 -> V_22 , V_33 ) ;
T_2 V_36 = F_17 ( V_28 -> V_22 , V_34 - V_33 ) ;
return F_22 ( V_28 -> V_37 -> V_38 , V_35 , V_36 ,
V_39 , 0 , & V_26 -> V_29 ) ;
}
static void F_23 ( struct V_25 * V_26 , int V_40 )
{
if ( V_26 -> V_29 ) {
F_24 ( V_26 -> V_29 , V_26 -> V_32 ) ;
F_25 ( V_26 -> V_29 , V_41 , 0 ) ;
F_26 ( V_26 -> V_29 ) ;
}
F_27 ( & V_26 -> V_31 ) ;
if ( V_40 && ! V_26 -> V_32 -> V_42 )
V_26 -> V_32 -> V_42 = V_40 ;
F_28 ( V_26 -> V_32 ) ;
}
static void F_29 ( struct V_22 * V_22 )
{
F_30 ( V_22 -> V_43 , & V_22 -> V_44 ) ;
}
static int F_31 ( struct V_22 * V_22 , struct V_7 * V_8 , struct V_29 * V_29 ,
struct V_45 * * V_46 )
{
int V_40 ;
struct V_45 * V_47 ;
V_47 = F_32 ( V_22 -> V_48 , V_49 ) ;
V_40 = F_33 ( V_22 -> V_48 , V_8 , V_29 , V_47 , V_46 ) ;
if ( V_40 )
F_34 ( V_22 -> V_48 , V_47 ) ;
return V_40 ;
}
static void F_35 ( struct V_22 * V_22 ,
struct V_45 * V_50 ,
struct V_51 * V_52 )
{
F_36 ( V_22 -> V_48 , V_50 , V_52 ) ;
F_34 ( V_22 -> V_48 , V_50 ) ;
}
static void F_37 ( struct V_22 * V_22 ,
void (* F_38)( void * , struct V_45 * ) ,
void * V_53 ,
struct V_45 * V_50 )
{
F_39 ( V_22 -> V_48 , F_38 , V_53 , V_50 ) ;
F_34 ( V_22 -> V_48 , V_50 ) ;
}
static void F_40 ( struct V_22 * V_22 ,
struct V_45 * V_50 ,
struct V_51 * V_52 )
{
F_41 ( V_22 -> V_48 , V_50 , V_52 ) ;
F_34 ( V_22 -> V_48 , V_50 ) ;
}
static void F_42 ( struct V_22 * V_22 ,
struct V_45 * V_50 , int V_54 )
{
F_43 ( V_22 -> V_48 , V_50 , V_54 ) ;
F_34 ( V_22 -> V_48 , V_50 ) ;
}
static int F_44 ( struct V_22 * V_22 )
{
return V_22 -> V_55 ? - V_56 : - V_57 ;
}
static void F_45 ( struct V_22 * V_22 , struct V_45 * V_50 )
{
int error = F_44 ( V_22 ) ;
F_42 ( V_22 , V_50 , error ) ;
}
static void F_46 ( struct V_22 * V_22 , struct V_45 * V_50 )
{
F_42 ( V_22 , V_50 , 0 ) ;
}
static void F_47 ( struct V_22 * V_22 , struct V_45 * V_50 )
{
F_42 ( V_22 , V_50 , V_58 ) ;
}
static void F_48 ( void )
{
F_49 ( & V_59 . V_60 ) ;
F_50 ( & V_59 . V_61 ) ;
}
static void F_51 ( struct V_22 * V_22 )
{
F_19 ( ! F_52 ( & V_59 . V_60 ) ) ;
F_53 ( & V_22 -> V_62 , & V_59 . V_61 ) ;
}
static void F_54 ( struct V_22 * V_22 )
{
F_19 ( ! F_52 ( & V_59 . V_60 ) ) ;
F_55 ( & V_22 -> V_62 ) ;
}
static struct V_22 * F_56 ( struct V_63 * V_64 )
{
struct V_22 * V_22 = NULL , * V_65 ;
F_19 ( ! F_52 ( & V_59 . V_60 ) ) ;
F_57 (tmp, &dm_thin_pool_table.pools, list) {
if ( V_65 -> V_66 == V_64 ) {
V_22 = V_65 ;
break;
}
}
return V_22 ;
}
static struct V_22 * F_58 ( struct V_67 * V_68 )
{
struct V_22 * V_22 = NULL , * V_65 ;
F_19 ( ! F_52 ( & V_59 . V_60 ) ) ;
F_57 (tmp, &dm_thin_pool_table.pools, list) {
if ( V_65 -> V_68 == V_68 ) {
V_22 = V_65 ;
break;
}
}
return V_22 ;
}
static void F_59 ( struct V_51 * V_52 , struct V_51 * V_69 )
{
F_60 ( V_52 , V_69 ) ;
F_61 ( V_69 ) ;
}
static void F_62 ( struct V_51 * V_52 , int error )
{
struct V_29 * V_29 ;
while ( ( V_29 = F_63 ( V_52 ) ) ) {
V_29 -> V_42 = error ;
F_28 ( V_29 ) ;
}
}
static void F_64 ( struct V_27 * V_28 , struct V_51 * V_69 , int error )
{
struct V_51 V_52 ;
unsigned long V_70 ;
F_61 ( & V_52 ) ;
F_65 ( & V_28 -> V_17 , V_70 ) ;
F_59 ( & V_52 , V_69 ) ;
F_66 ( & V_28 -> V_17 , V_70 ) ;
F_62 ( & V_52 , error ) ;
}
static void F_67 ( struct V_27 * V_28 )
{
struct V_22 * V_22 = V_28 -> V_22 ;
unsigned long V_70 ;
struct V_71 V_72 ;
struct V_45 * V_50 , * V_65 ;
F_50 ( & V_72 ) ;
F_65 ( & V_28 -> V_17 , V_70 ) ;
F_68 ( & V_28 -> V_73 , & V_72 ) ;
F_66 ( & V_28 -> V_17 , V_70 ) ;
F_69 (cell, tmp, &cells, user_list)
F_47 ( V_22 , V_50 ) ;
}
static void F_70 ( struct V_27 * V_28 )
{
struct V_51 V_52 ;
unsigned long V_70 ;
F_61 ( & V_52 ) ;
F_65 ( & V_28 -> V_17 , V_70 ) ;
F_59 ( & V_52 , & V_28 -> V_74 ) ;
F_59 ( & V_52 , & V_28 -> V_75 ) ;
F_66 ( & V_28 -> V_17 , V_70 ) ;
F_62 ( & V_52 , V_58 ) ;
F_67 ( V_28 ) ;
}
static void F_71 ( struct V_22 * V_22 , int error )
{
struct V_27 * V_28 ;
F_72 () ;
F_73 (tc, &pool->active_thins, list)
F_64 ( V_28 , & V_28 -> V_75 , error ) ;
F_74 () ;
}
static void F_75 ( struct V_22 * V_22 )
{
int error = F_44 ( V_22 ) ;
F_71 ( V_22 , error ) ;
}
static T_1 F_76 ( struct V_27 * V_28 , struct V_29 * V_29 )
{
struct V_22 * V_22 = V_28 -> V_22 ;
T_2 V_76 = V_29 -> V_77 . V_78 ;
if ( F_16 ( V_22 ) )
V_76 >>= V_22 -> V_23 ;
else
( void ) F_77 ( V_76 , V_22 -> V_24 ) ;
return V_76 ;
}
static void F_78 ( struct V_27 * V_28 , struct V_29 * V_29 ,
T_1 * V_79 , T_1 * V_80 )
{
struct V_22 * V_22 = V_28 -> V_22 ;
T_2 V_5 = V_29 -> V_77 . V_78 ;
T_2 V_6 = V_5 + ( V_29 -> V_77 . V_81 >> V_82 ) ;
V_5 += V_22 -> V_24 - 1ull ;
if ( F_16 ( V_22 ) ) {
V_5 >>= V_22 -> V_23 ;
V_6 >>= V_22 -> V_23 ;
} else {
( void ) F_77 ( V_5 , V_22 -> V_24 ) ;
( void ) F_77 ( V_6 , V_22 -> V_24 ) ;
}
if ( V_6 < V_5 )
V_6 = V_5 ;
* V_79 = V_5 ;
* V_80 = V_6 ;
}
static void F_79 ( struct V_27 * V_28 , struct V_29 * V_29 , T_1 V_83 )
{
struct V_22 * V_22 = V_28 -> V_22 ;
T_2 V_78 = V_29 -> V_77 . V_78 ;
V_29 -> V_84 = V_28 -> V_37 -> V_38 ;
if ( F_16 ( V_22 ) )
V_29 -> V_77 . V_78 =
( V_83 << V_22 -> V_23 ) |
( V_78 & ( V_22 -> V_24 - 1 ) ) ;
else
V_29 -> V_77 . V_78 = ( V_83 * V_22 -> V_24 ) +
F_77 ( V_78 , V_22 -> V_24 ) ;
}
static void F_80 ( struct V_27 * V_28 , struct V_29 * V_29 )
{
V_29 -> V_84 = V_28 -> V_85 -> V_38 ;
}
static int F_81 ( struct V_27 * V_28 , struct V_29 * V_29 )
{
return ( V_29 -> V_86 & ( V_87 | V_88 ) ) &&
F_82 ( V_28 -> V_2 ) ;
}
static void F_83 ( struct V_22 * V_22 , struct V_29 * V_29 )
{
struct V_89 * V_90 ;
if ( F_84 ( V_29 ) == V_41 )
return;
V_90 = F_85 ( V_29 , sizeof( struct V_89 ) ) ;
V_90 -> V_91 = F_86 ( V_22 -> V_92 ) ;
}
static void F_87 ( struct V_27 * V_28 , struct V_29 * V_29 )
{
struct V_22 * V_22 = V_28 -> V_22 ;
unsigned long V_70 ;
if ( ! F_81 ( V_28 , V_29 ) ) {
F_88 ( V_29 ) ;
return;
}
if ( F_89 ( V_28 -> V_2 ) ) {
F_90 ( V_29 ) ;
return;
}
F_65 ( & V_22 -> V_17 , V_70 ) ;
F_91 ( & V_22 -> V_93 , V_29 ) ;
F_66 ( & V_22 -> V_17 , V_70 ) ;
}
static void F_92 ( struct V_27 * V_28 , struct V_29 * V_29 )
{
F_80 ( V_28 , V_29 ) ;
F_87 ( V_28 , V_29 ) ;
}
static void F_93 ( struct V_27 * V_28 , struct V_29 * V_29 ,
T_1 V_83 )
{
F_79 ( V_28 , V_29 , V_83 ) ;
F_87 ( V_28 , V_29 ) ;
}
static void F_94 ( struct V_94 * V_95 )
{
struct V_22 * V_22 = V_95 -> V_28 -> V_22 ;
if ( F_95 ( & V_95 -> V_96 ) ) {
F_96 ( & V_95 -> V_62 , & V_22 -> V_97 ) ;
F_29 ( V_22 ) ;
}
}
static void F_97 ( struct V_94 * V_95 )
{
unsigned long V_70 ;
struct V_22 * V_22 = V_95 -> V_28 -> V_22 ;
F_65 ( & V_22 -> V_17 , V_70 ) ;
F_94 ( V_95 ) ;
F_66 ( & V_22 -> V_17 , V_70 ) ;
}
static void F_98 ( int V_98 , unsigned long V_99 , void * V_53 )
{
struct V_94 * V_95 = V_53 ;
V_95 -> V_100 = V_98 || V_99 ? - V_57 : 0 ;
F_97 ( V_95 ) ;
}
static void F_99 ( struct V_29 * V_29 )
{
struct V_89 * V_90 = F_85 ( V_29 , sizeof( struct V_89 ) ) ;
struct V_94 * V_95 = V_90 -> V_101 ;
V_29 -> V_102 = V_95 -> V_103 ;
V_95 -> V_100 = V_29 -> V_42 ;
F_97 ( V_95 ) ;
}
static void F_100 ( struct V_27 * V_28 , struct V_45 * V_50 )
{
struct V_22 * V_22 = V_28 -> V_22 ;
unsigned long V_70 ;
F_65 ( & V_28 -> V_17 , V_70 ) ;
F_40 ( V_22 , V_50 , & V_28 -> V_74 ) ;
F_66 ( & V_28 -> V_17 , V_70 ) ;
F_29 ( V_22 ) ;
}
static void F_101 ( void * V_53 ,
struct V_45 * V_50 )
{
struct V_104 * V_105 = V_53 ;
struct V_29 * V_29 ;
while ( ( V_29 = F_63 ( & V_50 -> V_52 ) ) ) {
if ( V_29 -> V_86 & ( V_87 | V_88 ) ||
F_84 ( V_29 ) == V_41 )
F_91 ( & V_105 -> V_106 , V_29 ) ;
else {
F_83 ( V_105 -> V_28 -> V_22 , V_29 ) ;
F_91 ( & V_105 -> V_107 , V_29 ) ;
}
}
}
static void F_102 ( struct V_27 * V_28 ,
struct V_45 * V_50 ,
T_1 V_83 )
{
struct V_29 * V_29 ;
struct V_104 V_105 ;
V_105 . V_28 = V_28 ;
F_61 ( & V_105 . V_106 ) ;
F_61 ( & V_105 . V_107 ) ;
F_37 ( V_28 -> V_22 , F_101 ,
& V_105 , V_50 ) ;
while ( ( V_29 = F_63 ( & V_105 . V_106 ) ) )
F_103 ( V_28 , V_29 ) ;
while ( ( V_29 = F_63 ( & V_105 . V_107 ) ) )
F_93 ( V_105 . V_28 , V_29 , V_83 ) ;
}
static void F_104 ( struct V_94 * V_95 )
{
F_45 ( V_95 -> V_28 -> V_22 , V_95 -> V_50 ) ;
F_55 ( & V_95 -> V_62 ) ;
F_105 ( V_95 , V_95 -> V_28 -> V_22 -> V_108 ) ;
}
static void F_106 ( struct V_94 * V_95 )
{
struct V_27 * V_28 = V_95 -> V_28 ;
struct V_22 * V_22 = V_28 -> V_22 ;
struct V_29 * V_29 = V_95 -> V_29 ;
int V_40 ;
if ( V_95 -> V_100 ) {
F_45 ( V_22 , V_95 -> V_50 ) ;
goto V_109;
}
V_40 = F_107 ( V_28 -> V_2 , V_95 -> V_110 , V_95 -> V_111 ) ;
if ( V_40 ) {
F_108 ( V_22 , L_1 , V_40 ) ;
F_45 ( V_22 , V_95 -> V_50 ) ;
goto V_109;
}
if ( V_29 ) {
F_102 ( V_28 , V_95 -> V_50 , V_95 -> V_111 ) ;
F_28 ( V_29 ) ;
} else {
F_83 ( V_28 -> V_22 , V_95 -> V_50 -> V_112 ) ;
F_93 ( V_28 , V_95 -> V_50 -> V_112 , V_95 -> V_111 ) ;
F_102 ( V_28 , V_95 -> V_50 , V_95 -> V_111 ) ;
}
V_109:
F_55 ( & V_95 -> V_62 ) ;
F_105 ( V_95 , V_22 -> V_108 ) ;
}
static void F_109 ( struct V_94 * V_95 )
{
struct V_27 * V_28 = V_95 -> V_28 ;
if ( V_95 -> V_50 )
F_100 ( V_28 , V_95 -> V_50 ) ;
F_105 ( V_95 , V_28 -> V_22 -> V_108 ) ;
}
static void F_110 ( struct V_94 * V_95 )
{
F_90 ( V_95 -> V_29 ) ;
F_109 ( V_95 ) ;
}
static void F_111 ( struct V_94 * V_95 )
{
F_28 ( V_95 -> V_29 ) ;
F_109 ( V_95 ) ;
}
static void F_112 ( struct V_94 * V_95 )
{
int V_40 ;
struct V_27 * V_28 = V_95 -> V_28 ;
V_40 = F_113 ( V_28 -> V_2 , V_95 -> V_50 -> V_8 . V_12 , V_95 -> V_50 -> V_8 . V_13 ) ;
if ( V_40 ) {
F_108 ( V_28 -> V_22 , L_2 , V_40 ) ;
F_90 ( V_95 -> V_29 ) ;
} else
F_28 ( V_95 -> V_29 ) ;
F_100 ( V_28 , V_95 -> V_50 ) ;
F_105 ( V_95 , V_28 -> V_22 -> V_108 ) ;
}
static void F_114 ( struct V_94 * V_95 ,
struct V_29 * V_113 )
{
int V_40 = 0 ;
bool V_114 = true ;
struct V_27 * V_28 = V_95 -> V_28 ;
struct V_22 * V_22 = V_28 -> V_22 ;
T_1 V_5 = V_95 -> V_111 , V_6 , V_80 = V_95 -> V_111 + V_95 -> V_115 - V_95 -> V_110 ;
struct V_25 V_26 ;
F_18 ( & V_26 , V_28 , V_113 ) ;
while ( V_5 != V_80 ) {
for (; V_5 < V_80 ; V_5 ++ ) {
V_40 = F_115 ( V_22 -> V_116 , V_5 , & V_114 ) ;
if ( V_40 )
goto V_109;
if ( ! V_114 )
break;
}
if ( V_5 == V_80 )
break;
for ( V_6 = V_5 + 1 ; V_6 != V_80 ; V_6 ++ ) {
V_40 = F_115 ( V_22 -> V_116 , V_6 , & V_114 ) ;
if ( V_40 )
goto V_109;
if ( V_114 )
break;
}
V_40 = F_21 ( & V_26 , V_5 , V_6 ) ;
if ( V_40 )
goto V_109;
V_5 = V_6 ;
}
V_109:
F_23 ( & V_26 , V_40 ) ;
}
static void F_116 ( struct V_94 * V_95 )
{
unsigned long V_70 ;
struct V_22 * V_22 = V_95 -> V_28 -> V_22 ;
F_65 ( & V_22 -> V_17 , V_70 ) ;
F_96 ( & V_95 -> V_62 , & V_22 -> V_117 ) ;
F_66 ( & V_22 -> V_17 , V_70 ) ;
F_29 ( V_22 ) ;
}
static void F_117 ( struct V_29 * V_29 )
{
F_116 ( V_29 -> V_118 ) ;
}
static void F_118 ( struct V_94 * V_95 )
{
int V_40 ;
struct V_27 * V_28 = V_95 -> V_28 ;
struct V_22 * V_22 = V_28 -> V_22 ;
struct V_29 * V_113 ;
T_1 V_119 = V_95 -> V_111 + ( V_95 -> V_115 - V_95 -> V_110 ) ;
V_40 = F_113 ( V_28 -> V_2 , V_95 -> V_110 , V_95 -> V_115 ) ;
if ( V_40 ) {
F_108 ( V_22 , L_2 , V_40 ) ;
F_90 ( V_95 -> V_29 ) ;
F_100 ( V_28 , V_95 -> V_50 ) ;
F_105 ( V_95 , V_22 -> V_108 ) ;
return;
}
V_113 = F_119 ( V_49 , 1 ) ;
if ( ! V_113 ) {
F_120 ( L_3 ,
F_121 ( V_28 -> V_22 -> V_66 ) ) ;
F_116 ( V_95 ) ;
} else {
V_113 -> V_102 = F_117 ;
V_113 -> V_118 = V_95 ;
if ( V_95 -> V_120 )
F_114 ( V_95 , V_113 ) ;
else {
struct V_25 V_26 ;
F_18 ( & V_26 , V_28 , V_113 ) ;
V_40 = F_21 ( & V_26 , V_95 -> V_111 , V_119 ) ;
F_23 ( & V_26 , V_40 ) ;
}
}
V_40 = F_122 ( V_22 -> V_116 , V_95 -> V_111 , V_119 ) ;
if ( V_40 ) {
F_108 ( V_22 , L_4 , V_40 ) ;
F_90 ( V_95 -> V_29 ) ;
F_100 ( V_28 , V_95 -> V_50 ) ;
F_105 ( V_95 , V_22 -> V_108 ) ;
return;
}
}
static void F_123 ( struct V_94 * V_95 )
{
int V_40 ;
struct V_27 * V_28 = V_95 -> V_28 ;
struct V_22 * V_22 = V_28 -> V_22 ;
V_40 = F_124 ( V_22 -> V_116 , V_95 -> V_111 ,
V_95 -> V_111 + ( V_95 -> V_115 - V_95 -> V_110 ) ) ;
if ( V_40 ) {
F_108 ( V_22 , L_5 , V_40 ) ;
F_90 ( V_95 -> V_29 ) ;
} else
F_28 ( V_95 -> V_29 ) ;
F_100 ( V_28 , V_95 -> V_50 ) ;
F_105 ( V_95 , V_22 -> V_108 ) ;
}
static void F_125 ( struct V_22 * V_22 , struct V_71 * V_121 ,
T_3 * F_38 )
{
unsigned long V_70 ;
struct V_71 V_122 ;
struct V_94 * V_95 , * V_65 ;
F_50 ( & V_122 ) ;
F_65 ( & V_22 -> V_17 , V_70 ) ;
F_68 ( V_121 , & V_122 ) ;
F_66 ( & V_22 -> V_17 , V_70 ) ;
F_69 ( V_95 , V_65 , & V_122 , V_62 )
( * F_38 ) ( V_95 ) ;
}
static int F_126 ( struct V_22 * V_22 , struct V_29 * V_29 )
{
return V_29 -> V_77 . V_81 ==
( V_22 -> V_24 << V_82 ) ;
}
static int F_127 ( struct V_22 * V_22 , struct V_29 * V_29 )
{
return ( F_128 ( V_29 ) == V_123 ) &&
F_126 ( V_22 , V_29 ) ;
}
static void F_129 ( struct V_29 * V_29 , T_4 * * V_124 ,
T_4 * F_38 )
{
* V_124 = V_29 -> V_102 ;
V_29 -> V_102 = F_38 ;
}
static int F_130 ( struct V_22 * V_22 )
{
if ( V_22 -> V_125 )
return 0 ;
V_22 -> V_125 = F_131 ( V_22 -> V_108 , V_126 ) ;
return V_22 -> V_125 ? 0 : - V_127 ;
}
static struct V_94 * F_132 ( struct V_22 * V_22 )
{
struct V_94 * V_95 = V_22 -> V_125 ;
F_19 ( ! V_22 -> V_125 ) ;
memset ( V_95 , 0 , sizeof( struct V_94 ) ) ;
F_50 ( & V_95 -> V_62 ) ;
V_95 -> V_29 = NULL ;
V_22 -> V_125 = NULL ;
return V_95 ;
}
static void F_133 ( struct V_27 * V_28 , struct V_94 * V_95 ,
T_2 V_79 , T_2 V_80 )
{
int V_40 ;
struct V_128 V_129 ;
V_129 . V_38 = V_28 -> V_37 -> V_38 ;
V_129 . V_130 = V_79 ;
V_129 . V_131 = V_80 - V_79 ;
V_40 = F_134 ( V_28 -> V_22 -> V_132 , 1 , & V_129 , 0 , F_98 , V_95 ) ;
if ( V_40 < 0 ) {
F_135 ( L_6 ) ;
F_98 ( 1 , 1 , V_95 ) ;
}
}
static void F_136 ( struct V_27 * V_28 , struct V_29 * V_29 ,
T_1 V_133 ,
struct V_94 * V_95 )
{
struct V_22 * V_22 = V_28 -> V_22 ;
struct V_89 * V_90 = F_85 ( V_29 , sizeof( struct V_89 ) ) ;
V_90 -> V_101 = V_95 ;
V_95 -> V_29 = V_29 ;
F_129 ( V_29 , & V_95 -> V_103 , F_99 ) ;
F_83 ( V_22 , V_29 ) ;
F_93 ( V_28 , V_29 , V_133 ) ;
}
static void F_137 ( struct V_27 * V_28 , T_1 V_134 ,
struct V_135 * V_136 , T_1 V_137 ,
T_1 V_138 ,
struct V_45 * V_50 , struct V_29 * V_29 ,
T_2 V_36 )
{
int V_40 ;
struct V_22 * V_22 = V_28 -> V_22 ;
struct V_94 * V_95 = F_132 ( V_22 ) ;
V_95 -> V_28 = V_28 ;
V_95 -> V_110 = V_134 ;
V_95 -> V_115 = V_134 + 1u ;
V_95 -> V_111 = V_138 ;
V_95 -> V_50 = V_50 ;
F_138 ( & V_95 -> V_96 , 3 ) ;
if ( ! F_139 ( V_22 -> V_139 , & V_95 -> V_62 ) )
F_97 ( V_95 ) ;
if ( F_127 ( V_22 , V_29 ) )
F_136 ( V_28 , V_29 , V_138 , V_95 ) ;
else {
struct V_128 V_140 , V_129 ;
V_140 . V_38 = V_136 -> V_38 ;
V_140 . V_130 = V_137 * V_22 -> V_24 ;
V_140 . V_131 = V_36 ;
V_129 . V_38 = V_28 -> V_37 -> V_38 ;
V_129 . V_130 = V_138 * V_22 -> V_24 ;
V_129 . V_131 = V_36 ;
V_40 = F_140 ( V_22 -> V_132 , & V_140 , 1 , & V_129 ,
0 , F_98 , V_95 ) ;
if ( V_40 < 0 ) {
F_135 ( L_7 ) ;
F_98 ( 1 , 1 , V_95 ) ;
}
if ( V_36 < V_22 -> V_24 && V_22 -> V_141 . V_142 ) {
F_141 ( & V_95 -> V_96 ) ;
F_133 ( V_28 , V_95 ,
V_138 * V_22 -> V_24 + V_36 ,
( V_138 + 1 ) * V_22 -> V_24 ) ;
}
}
F_97 ( V_95 ) ;
}
static void F_142 ( struct V_27 * V_28 , T_1 V_134 ,
T_1 V_137 , T_1 V_138 ,
struct V_45 * V_50 , struct V_29 * V_29 )
{
F_137 ( V_28 , V_134 , V_28 -> V_37 ,
V_137 , V_138 , V_50 , V_29 ,
V_28 -> V_22 -> V_24 ) ;
}
static void F_143 ( struct V_27 * V_28 , T_1 V_134 ,
T_1 V_111 , struct V_45 * V_50 ,
struct V_29 * V_29 )
{
struct V_22 * V_22 = V_28 -> V_22 ;
struct V_94 * V_95 = F_132 ( V_22 ) ;
F_138 ( & V_95 -> V_96 , 1 ) ;
V_95 -> V_28 = V_28 ;
V_95 -> V_110 = V_134 ;
V_95 -> V_115 = V_134 + 1u ;
V_95 -> V_111 = V_111 ;
V_95 -> V_50 = V_50 ;
if ( V_22 -> V_141 . V_142 ) {
if ( F_127 ( V_22 , V_29 ) )
F_136 ( V_28 , V_29 , V_111 , V_95 ) ;
else
F_133 ( V_28 , V_95 , V_111 * V_22 -> V_24 ,
( V_111 + 1 ) * V_22 -> V_24 ) ;
} else
F_106 ( V_95 ) ;
}
static void F_144 ( struct V_27 * V_28 , T_1 V_134 ,
T_1 V_138 ,
struct V_45 * V_50 , struct V_29 * V_29 )
{
struct V_22 * V_22 = V_28 -> V_22 ;
T_2 V_143 = V_134 * V_22 -> V_24 ;
T_2 V_144 = ( V_134 + 1 ) * V_22 -> V_24 ;
if ( V_144 <= V_28 -> V_145 )
F_137 ( V_28 , V_134 , V_28 -> V_85 ,
V_134 , V_138 , V_50 , V_29 ,
V_22 -> V_24 ) ;
else if ( V_143 < V_28 -> V_145 )
F_137 ( V_28 , V_134 , V_28 -> V_85 ,
V_134 , V_138 , V_50 , V_29 ,
V_28 -> V_145 - V_143 ) ;
else
F_143 ( V_28 , V_134 , V_138 , V_50 , V_29 ) ;
}
static void F_145 ( struct V_22 * V_22 )
{
int V_40 ;
T_1 V_146 ;
if ( F_146 ( V_22 ) != V_147 )
return;
V_40 = F_147 ( V_22 -> V_116 , & V_146 ) ;
if ( V_40 )
return;
if ( V_146 )
F_148 ( V_22 , V_148 ) ;
}
static int F_149 ( struct V_22 * V_22 )
{
int V_40 ;
if ( F_146 ( V_22 ) >= V_149 )
return - V_150 ;
V_40 = F_150 ( V_22 -> V_116 ) ;
if ( V_40 )
F_108 ( V_22 , L_8 , V_40 ) ;
else
F_145 ( V_22 ) ;
return V_40 ;
}
static void F_151 ( struct V_22 * V_22 , T_1 V_151 )
{
unsigned long V_70 ;
if ( V_151 <= V_22 -> V_152 && ! V_22 -> V_153 ) {
F_120 ( L_9 ,
F_121 ( V_22 -> V_66 ) ) ;
F_65 ( & V_22 -> V_17 , V_70 ) ;
V_22 -> V_153 = true ;
F_66 ( & V_22 -> V_17 , V_70 ) ;
F_152 ( V_22 -> V_154 -> V_155 ) ;
}
}
static int F_153 ( struct V_27 * V_28 , T_1 * V_156 )
{
int V_40 ;
T_1 V_151 ;
struct V_22 * V_22 = V_28 -> V_22 ;
if ( F_154 ( F_146 ( V_22 ) != V_148 ) )
return - V_150 ;
V_40 = F_147 ( V_22 -> V_116 , & V_151 ) ;
if ( V_40 ) {
F_108 ( V_22 , L_10 , V_40 ) ;
return V_40 ;
}
F_151 ( V_22 , V_151 ) ;
if ( ! V_151 ) {
V_40 = F_149 ( V_22 ) ;
if ( V_40 )
return V_40 ;
V_40 = F_147 ( V_22 -> V_116 , & V_151 ) ;
if ( V_40 ) {
F_108 ( V_22 , L_10 , V_40 ) ;
return V_40 ;
}
if ( ! V_151 ) {
F_148 ( V_22 , V_147 ) ;
return - V_56 ;
}
}
V_40 = F_155 ( V_22 -> V_116 , V_156 ) ;
if ( V_40 ) {
F_108 ( V_22 , L_11 , V_40 ) ;
return V_40 ;
}
return 0 ;
}
static void F_156 ( struct V_29 * V_29 )
{
struct V_89 * V_90 = F_85 ( V_29 , sizeof( struct V_89 ) ) ;
struct V_27 * V_28 = V_90 -> V_28 ;
unsigned long V_70 ;
F_65 ( & V_28 -> V_17 , V_70 ) ;
F_91 ( & V_28 -> V_75 , V_29 ) ;
F_66 ( & V_28 -> V_17 , V_70 ) ;
}
static int F_157 ( struct V_22 * V_22 )
{
enum V_157 V_95 = F_146 ( V_22 ) ;
switch ( V_95 ) {
case V_148 :
F_135 ( L_12 ) ;
return - V_57 ;
case V_147 :
return V_22 -> V_141 . V_158 ? - V_56 : 0 ;
case V_149 :
case V_159 :
return - V_57 ;
default:
F_135 ( L_13 ) ;
return - V_57 ;
}
}
static void F_158 ( struct V_22 * V_22 , struct V_29 * V_29 )
{
int error = F_157 ( V_22 ) ;
if ( error ) {
V_29 -> V_42 = error ;
F_28 ( V_29 ) ;
} else
F_156 ( V_29 ) ;
}
static void F_159 ( struct V_22 * V_22 , struct V_45 * V_50 )
{
struct V_29 * V_29 ;
struct V_51 V_52 ;
int error ;
error = F_157 ( V_22 ) ;
if ( error ) {
F_42 ( V_22 , V_50 , error ) ;
return;
}
F_61 ( & V_52 ) ;
F_35 ( V_22 , V_50 , & V_52 ) ;
while ( ( V_29 = F_63 ( & V_52 ) ) )
F_156 ( V_29 ) ;
}
static void F_160 ( struct V_27 * V_28 ,
struct V_45 * V_160 )
{
struct V_22 * V_22 = V_28 -> V_22 ;
struct V_94 * V_95 = F_132 ( V_22 ) ;
V_95 -> V_28 = V_28 ;
V_95 -> V_110 = V_160 -> V_8 . V_12 ;
V_95 -> V_115 = V_160 -> V_8 . V_13 ;
V_95 -> V_50 = V_160 ;
V_95 -> V_29 = V_160 -> V_112 ;
if ( ! F_139 ( V_22 -> V_92 , & V_95 -> V_62 ) )
V_22 -> V_161 ( V_95 ) ;
}
static void F_161 ( struct V_27 * V_28 , T_1 V_79 , T_1 V_80 ,
struct V_29 * V_29 )
{
struct V_22 * V_22 = V_28 -> V_22 ;
int V_40 ;
bool V_120 ;
struct V_7 V_162 ;
struct V_45 * V_163 ;
struct V_94 * V_95 ;
T_1 V_110 , V_115 , V_133 ;
while ( V_79 != V_80 ) {
V_40 = F_130 ( V_22 ) ;
if ( V_40 )
return;
V_40 = F_162 ( V_28 -> V_2 , V_79 , V_80 , & V_110 , & V_115 ,
& V_133 , & V_120 ) ;
if ( V_40 )
break;
F_1 ( V_28 -> V_2 , V_14 , V_133 , V_133 + ( V_115 - V_110 ) , & V_162 ) ;
if ( F_31 ( V_28 -> V_22 , & V_162 , NULL , & V_163 ) ) {
V_79 = V_115 ;
continue;
}
V_95 = F_132 ( V_22 ) ;
V_95 -> V_28 = V_28 ;
V_95 -> V_120 = V_120 ;
V_95 -> V_110 = V_110 ;
V_95 -> V_115 = V_115 ;
V_95 -> V_111 = V_133 ;
V_95 -> V_50 = V_163 ;
V_95 -> V_29 = V_29 ;
F_163 ( V_29 ) ;
if ( ! F_139 ( V_22 -> V_92 , & V_95 -> V_62 ) )
V_22 -> V_161 ( V_95 ) ;
V_79 = V_115 ;
}
}
static void F_164 ( struct V_27 * V_28 , struct V_45 * V_160 )
{
struct V_29 * V_29 = V_160 -> V_112 ;
struct V_89 * V_90 = F_85 ( V_29 , sizeof( struct V_89 ) ) ;
V_90 -> V_50 = V_160 ;
F_161 ( V_28 , V_160 -> V_8 . V_12 , V_160 -> V_8 . V_13 , V_29 ) ;
F_28 ( V_29 ) ;
}
static void F_165 ( struct V_27 * V_28 , struct V_29 * V_29 )
{
T_1 V_79 , V_80 ;
struct V_7 V_164 ;
struct V_45 * V_160 ;
F_78 ( V_28 , V_29 , & V_79 , & V_80 ) ;
if ( V_79 == V_80 ) {
F_28 ( V_29 ) ;
return;
}
F_1 ( V_28 -> V_2 , V_10 , V_79 , V_80 , & V_164 ) ;
if ( F_31 ( V_28 -> V_22 , & V_164 , V_29 , & V_160 ) )
return;
V_28 -> V_22 -> V_165 ( V_28 , V_160 ) ;
}
static void F_166 ( struct V_27 * V_28 , struct V_29 * V_29 , T_1 V_83 ,
struct V_7 * V_8 ,
struct V_166 * V_167 ,
struct V_45 * V_50 )
{
int V_40 ;
T_1 V_111 ;
struct V_22 * V_22 = V_28 -> V_22 ;
V_40 = F_153 ( V_28 , & V_111 ) ;
switch ( V_40 ) {
case 0 :
F_142 ( V_28 , V_83 , V_167 -> V_83 ,
V_111 , V_50 , V_29 ) ;
break;
case - V_56 :
F_159 ( V_22 , V_50 ) ;
break;
default:
F_135 ( L_14 ,
V_168 , V_40 ) ;
F_45 ( V_22 , V_50 ) ;
break;
}
}
static void F_167 ( void * V_53 ,
struct V_45 * V_50 )
{
struct V_104 * V_105 = V_53 ;
struct V_29 * V_29 ;
while ( ( V_29 = F_63 ( & V_50 -> V_52 ) ) ) {
if ( ( F_128 ( V_29 ) == V_123 ) ||
( V_29 -> V_86 & ( V_87 | V_88 ) ||
F_84 ( V_29 ) == V_41 ) )
F_91 ( & V_105 -> V_106 , V_29 ) ;
else {
struct V_89 * V_90 = F_85 ( V_29 , sizeof( struct V_89 ) ) ; ;
V_90 -> V_169 = F_86 ( V_105 -> V_28 -> V_22 -> V_139 ) ;
F_83 ( V_105 -> V_28 -> V_22 , V_29 ) ;
F_91 ( & V_105 -> V_107 , V_29 ) ;
}
}
}
static void F_168 ( struct V_27 * V_28 ,
struct V_45 * V_50 ,
T_1 V_83 )
{
struct V_29 * V_29 ;
struct V_104 V_105 ;
V_105 . V_28 = V_28 ;
F_61 ( & V_105 . V_106 ) ;
F_61 ( & V_105 . V_107 ) ;
F_37 ( V_28 -> V_22 , F_167 ,
& V_105 , V_50 ) ;
while ( ( V_29 = F_63 ( & V_105 . V_106 ) ) )
F_103 ( V_28 , V_29 ) ;
while ( ( V_29 = F_63 ( & V_105 . V_107 ) ) )
F_93 ( V_28 , V_29 , V_83 ) ;
}
static void F_169 ( struct V_27 * V_28 , struct V_29 * V_29 ,
T_1 V_83 ,
struct V_166 * V_167 ,
struct V_45 * V_160 )
{
struct V_45 * V_163 ;
struct V_22 * V_22 = V_28 -> V_22 ;
struct V_7 V_8 ;
F_3 ( V_28 -> V_2 , V_167 -> V_83 , & V_8 ) ;
if ( F_31 ( V_22 , & V_8 , V_29 , & V_163 ) ) {
F_100 ( V_28 , V_160 ) ;
return;
}
if ( F_128 ( V_29 ) == V_123 && V_29 -> V_77 . V_81 ) {
F_166 ( V_28 , V_29 , V_83 , & V_8 , V_167 , V_163 ) ;
F_100 ( V_28 , V_160 ) ;
} else {
struct V_89 * V_90 = F_85 ( V_29 , sizeof( struct V_89 ) ) ;
V_90 -> V_169 = F_86 ( V_22 -> V_139 ) ;
F_83 ( V_22 , V_29 ) ;
F_93 ( V_28 , V_29 , V_167 -> V_83 ) ;
F_168 ( V_28 , V_163 , V_167 -> V_83 ) ;
F_168 ( V_28 , V_160 , V_167 -> V_83 ) ;
}
}
static void F_170 ( struct V_27 * V_28 , struct V_29 * V_29 , T_1 V_83 ,
struct V_45 * V_50 )
{
int V_40 ;
T_1 V_111 ;
struct V_22 * V_22 = V_28 -> V_22 ;
if ( ! V_29 -> V_77 . V_81 ) {
F_83 ( V_22 , V_29 ) ;
F_100 ( V_28 , V_50 ) ;
F_93 ( V_28 , V_29 , 0 ) ;
return;
}
if ( F_128 ( V_29 ) == V_170 ) {
F_171 ( V_29 ) ;
F_100 ( V_28 , V_50 ) ;
F_28 ( V_29 ) ;
return;
}
V_40 = F_153 ( V_28 , & V_111 ) ;
switch ( V_40 ) {
case 0 :
if ( V_28 -> V_85 )
F_144 ( V_28 , V_83 , V_111 , V_50 , V_29 ) ;
else
F_143 ( V_28 , V_83 , V_111 , V_50 , V_29 ) ;
break;
case - V_56 :
F_159 ( V_22 , V_50 ) ;
break;
default:
F_135 ( L_14 ,
V_168 , V_40 ) ;
F_45 ( V_22 , V_50 ) ;
break;
}
}
static void F_172 ( struct V_27 * V_28 , struct V_45 * V_50 )
{
int V_40 ;
struct V_22 * V_22 = V_28 -> V_22 ;
struct V_29 * V_29 = V_50 -> V_112 ;
T_1 V_83 = F_76 ( V_28 , V_29 ) ;
struct V_166 V_167 ;
if ( V_28 -> V_171 ) {
F_47 ( V_22 , V_50 ) ;
return;
}
V_40 = F_173 ( V_28 -> V_2 , V_83 , 1 , & V_167 ) ;
switch ( V_40 ) {
case 0 :
if ( V_167 . V_172 )
F_169 ( V_28 , V_29 , V_83 , & V_167 , V_50 ) ;
else {
F_83 ( V_22 , V_29 ) ;
F_93 ( V_28 , V_29 , V_167 . V_83 ) ;
F_102 ( V_28 , V_50 , V_167 . V_83 ) ;
}
break;
case - V_173 :
if ( F_128 ( V_29 ) == V_170 && V_28 -> V_85 ) {
F_83 ( V_22 , V_29 ) ;
F_100 ( V_28 , V_50 ) ;
if ( F_174 ( V_29 ) <= V_28 -> V_145 )
F_92 ( V_28 , V_29 ) ;
else if ( V_29 -> V_77 . V_78 < V_28 -> V_145 ) {
F_171 ( V_29 ) ;
V_29 -> V_77 . V_81 = ( V_28 -> V_145 - V_29 -> V_77 . V_78 ) << V_82 ;
F_92 ( V_28 , V_29 ) ;
} else {
F_171 ( V_29 ) ;
F_28 ( V_29 ) ;
}
} else
F_170 ( V_28 , V_29 , V_83 , V_50 ) ;
break;
default:
F_135 ( L_15 ,
V_168 , V_40 ) ;
F_100 ( V_28 , V_50 ) ;
F_90 ( V_29 ) ;
break;
}
}
static void F_175 ( struct V_27 * V_28 , struct V_29 * V_29 )
{
struct V_22 * V_22 = V_28 -> V_22 ;
T_1 V_83 = F_76 ( V_28 , V_29 ) ;
struct V_45 * V_50 ;
struct V_7 V_8 ;
F_4 ( V_28 -> V_2 , V_83 , & V_8 ) ;
if ( F_31 ( V_22 , & V_8 , V_29 , & V_50 ) )
return;
F_172 ( V_28 , V_50 ) ;
}
static void F_176 ( struct V_27 * V_28 , struct V_29 * V_29 ,
struct V_45 * V_50 )
{
int V_40 ;
int V_174 = F_128 ( V_29 ) ;
T_1 V_83 = F_76 ( V_28 , V_29 ) ;
struct V_166 V_167 ;
V_40 = F_173 ( V_28 -> V_2 , V_83 , 1 , & V_167 ) ;
switch ( V_40 ) {
case 0 :
if ( V_167 . V_172 && ( V_174 == V_123 ) && V_29 -> V_77 . V_81 ) {
F_158 ( V_28 -> V_22 , V_29 ) ;
if ( V_50 )
F_100 ( V_28 , V_50 ) ;
} else {
F_83 ( V_28 -> V_22 , V_29 ) ;
F_93 ( V_28 , V_29 , V_167 . V_83 ) ;
if ( V_50 )
F_102 ( V_28 , V_50 , V_167 . V_83 ) ;
}
break;
case - V_173 :
if ( V_50 )
F_100 ( V_28 , V_50 ) ;
if ( V_174 != V_170 ) {
F_158 ( V_28 -> V_22 , V_29 ) ;
break;
}
if ( V_28 -> V_85 ) {
F_83 ( V_28 -> V_22 , V_29 ) ;
F_92 ( V_28 , V_29 ) ;
break;
}
F_171 ( V_29 ) ;
F_28 ( V_29 ) ;
break;
default:
F_135 ( L_15 ,
V_168 , V_40 ) ;
if ( V_50 )
F_100 ( V_28 , V_50 ) ;
F_90 ( V_29 ) ;
break;
}
}
static void F_177 ( struct V_27 * V_28 , struct V_29 * V_29 )
{
F_176 ( V_28 , V_29 , NULL ) ;
}
static void F_178 ( struct V_27 * V_28 , struct V_45 * V_50 )
{
F_176 ( V_28 , V_50 -> V_112 , V_50 ) ;
}
static void F_179 ( struct V_27 * V_28 , struct V_29 * V_29 )
{
F_28 ( V_29 ) ;
}
static void F_180 ( struct V_27 * V_28 , struct V_29 * V_29 )
{
F_90 ( V_29 ) ;
}
static void F_181 ( struct V_27 * V_28 , struct V_45 * V_50 )
{
F_46 ( V_28 -> V_22 , V_50 ) ;
}
static void F_182 ( struct V_27 * V_28 , struct V_45 * V_50 )
{
F_45 ( V_28 -> V_22 , V_50 ) ;
}
static int F_183 ( struct V_22 * V_22 )
{
return ! F_184 ( V_20 , V_22 -> V_175 ,
V_22 -> V_175 + V_176 ) ;
}
static void F_185 ( struct V_27 * V_28 , struct V_29 * V_29 )
{
struct V_177 * * V_178 , * V_30 ;
struct V_89 * V_179 ;
T_2 V_78 = V_29 -> V_77 . V_78 ;
V_178 = & V_28 -> V_180 . V_177 ;
V_30 = NULL ;
while ( * V_178 ) {
V_30 = * V_178 ;
V_179 = F_186 ( V_30 ) ;
if ( V_78 < F_187 ( V_179 ) -> V_77 . V_78 )
V_178 = & ( * V_178 ) -> V_181 ;
else
V_178 = & ( * V_178 ) -> V_182 ;
}
V_179 = F_85 ( V_29 , sizeof( struct V_89 ) ) ;
F_188 ( & V_179 -> V_177 , V_30 , V_178 ) ;
F_189 ( & V_179 -> V_177 , & V_28 -> V_180 ) ;
}
static void F_190 ( struct V_27 * V_28 )
{
struct V_177 * V_183 ;
struct V_89 * V_179 ;
struct V_29 * V_29 ;
for ( V_183 = F_191 ( & V_28 -> V_180 ) ; V_183 ; V_183 = F_192 ( V_183 ) ) {
V_179 = F_186 ( V_183 ) ;
V_29 = F_187 ( V_179 ) ;
F_91 ( & V_28 -> V_74 , V_29 ) ;
F_193 ( & V_179 -> V_177 , & V_28 -> V_180 ) ;
}
F_154 ( ! F_194 ( & V_28 -> V_180 ) ) ;
}
static void F_195 ( struct V_27 * V_28 )
{
struct V_29 * V_29 ;
struct V_51 V_52 ;
F_61 ( & V_52 ) ;
F_60 ( & V_52 , & V_28 -> V_74 ) ;
F_61 ( & V_28 -> V_74 ) ;
while ( ( V_29 = F_63 ( & V_52 ) ) )
F_185 ( V_28 , V_29 ) ;
F_190 ( V_28 ) ;
}
static void F_196 ( struct V_27 * V_28 )
{
struct V_22 * V_22 = V_28 -> V_22 ;
unsigned long V_70 ;
struct V_29 * V_29 ;
struct V_51 V_52 ;
struct V_184 V_31 ;
unsigned V_131 = 0 ;
if ( V_28 -> V_171 ) {
F_64 ( V_28 , & V_28 -> V_74 , V_58 ) ;
return;
}
F_61 ( & V_52 ) ;
F_65 ( & V_28 -> V_17 , V_70 ) ;
if ( F_197 ( & V_28 -> V_74 ) ) {
F_66 ( & V_28 -> V_17 , V_70 ) ;
return;
}
F_195 ( V_28 ) ;
F_60 ( & V_52 , & V_28 -> V_74 ) ;
F_61 ( & V_28 -> V_74 ) ;
F_66 ( & V_28 -> V_17 , V_70 ) ;
F_20 ( & V_31 ) ;
while ( ( V_29 = F_63 ( & V_52 ) ) ) {
if ( F_130 ( V_22 ) ) {
F_65 ( & V_28 -> V_17 , V_70 ) ;
F_91 ( & V_28 -> V_74 , V_29 ) ;
F_60 ( & V_28 -> V_74 , & V_52 ) ;
F_66 ( & V_28 -> V_17 , V_70 ) ;
break;
}
if ( F_84 ( V_29 ) == V_41 )
V_22 -> V_185 ( V_28 , V_29 ) ;
else
V_22 -> F_175 ( V_28 , V_29 ) ;
if ( ( V_131 ++ & 127 ) == 0 ) {
F_8 ( & V_22 -> V_15 ) ;
F_198 ( V_22 -> V_116 ) ;
}
}
F_27 ( & V_31 ) ;
}
static int F_199 ( const void * V_186 , const void * V_187 )
{
struct V_45 * V_188 = * ( (struct V_45 * * ) V_186 ) ;
struct V_45 * V_189 = * ( (struct V_45 * * ) V_187 ) ;
F_19 ( ! V_188 -> V_112 ) ;
F_19 ( ! V_189 -> V_112 ) ;
if ( V_188 -> V_112 -> V_77 . V_78 < V_189 -> V_112 -> V_77 . V_78 )
return - 1 ;
if ( V_188 -> V_112 -> V_77 . V_78 > V_189 -> V_112 -> V_77 . V_78 )
return 1 ;
return 0 ;
}
static unsigned F_200 ( struct V_22 * V_22 , struct V_71 * V_72 )
{
unsigned V_131 = 0 ;
struct V_45 * V_50 , * V_65 ;
F_69 (cell, tmp, cells, user_list) {
if ( V_131 >= V_190 )
break;
V_22 -> V_191 [ V_131 ++ ] = V_50 ;
F_55 ( & V_50 -> V_192 ) ;
}
F_201 ( V_22 -> V_191 , V_131 , sizeof( V_50 ) , F_199 , NULL ) ;
return V_131 ;
}
static void F_202 ( struct V_27 * V_28 )
{
struct V_22 * V_22 = V_28 -> V_22 ;
unsigned long V_70 ;
struct V_71 V_72 ;
struct V_45 * V_50 ;
unsigned V_193 , V_194 , V_131 ;
F_50 ( & V_72 ) ;
F_65 ( & V_28 -> V_17 , V_70 ) ;
F_68 ( & V_28 -> V_73 , & V_72 ) ;
F_66 ( & V_28 -> V_17 , V_70 ) ;
if ( F_203 ( & V_72 ) )
return;
do {
V_131 = F_200 ( V_28 -> V_22 , & V_72 ) ;
for ( V_193 = 0 ; V_193 < V_131 ; V_193 ++ ) {
V_50 = V_22 -> V_191 [ V_193 ] ;
F_19 ( ! V_50 -> V_112 ) ;
if ( F_130 ( V_22 ) ) {
for ( V_194 = V_193 ; V_194 < V_131 ; V_194 ++ )
F_53 ( & V_22 -> V_191 [ V_194 ] -> V_192 , & V_72 ) ;
F_65 ( & V_28 -> V_17 , V_70 ) ;
F_204 ( & V_72 , & V_28 -> V_73 ) ;
F_66 ( & V_28 -> V_17 , V_70 ) ;
return;
}
if ( F_84 ( V_50 -> V_112 ) == V_41 )
V_22 -> V_165 ( V_28 , V_50 ) ;
else
V_22 -> F_172 ( V_28 , V_50 ) ;
}
} while ( ! F_203 ( & V_72 ) );
}
static struct V_27 * F_205 ( struct V_22 * V_22 )
{
struct V_27 * V_28 = NULL ;
F_72 () ;
if ( ! F_203 ( & V_22 -> V_195 ) ) {
V_28 = F_206 ( V_22 -> V_195 . V_196 , struct V_27 , V_62 ) ;
F_207 ( V_28 ) ;
}
F_74 () ;
return V_28 ;
}
static struct V_27 * F_208 ( struct V_22 * V_22 , struct V_27 * V_28 )
{
struct V_27 * V_197 = V_28 ;
F_72 () ;
F_209 (tc, &pool->active_thins, list) {
F_207 ( V_28 ) ;
F_210 ( V_197 ) ;
F_74 () ;
return V_28 ;
}
F_210 ( V_197 ) ;
F_74 () ;
return NULL ;
}
static void F_211 ( struct V_22 * V_22 )
{
unsigned long V_70 ;
struct V_29 * V_29 ;
struct V_51 V_52 ;
struct V_27 * V_28 ;
V_28 = F_205 ( V_22 ) ;
while ( V_28 ) {
F_202 ( V_28 ) ;
F_196 ( V_28 ) ;
V_28 = F_208 ( V_22 , V_28 ) ;
}
F_61 ( & V_52 ) ;
F_65 ( & V_22 -> V_17 , V_70 ) ;
F_60 ( & V_52 , & V_22 -> V_93 ) ;
F_61 ( & V_22 -> V_93 ) ;
F_66 ( & V_22 -> V_17 , V_70 ) ;
if ( F_197 ( & V_52 ) &&
! ( F_212 ( V_22 -> V_116 ) && F_183 ( V_22 ) ) )
return;
if ( F_149 ( V_22 ) ) {
while ( ( V_29 = F_63 ( & V_52 ) ) )
F_90 ( V_29 ) ;
return;
}
V_22 -> V_175 = V_20 ;
while ( ( V_29 = F_63 ( & V_52 ) ) )
F_88 ( V_29 ) ;
}
static void F_213 ( struct V_198 * V_199 )
{
struct V_22 * V_22 = F_214 ( V_199 , struct V_22 , V_44 ) ;
F_7 ( & V_22 -> V_15 ) ;
F_198 ( V_22 -> V_116 ) ;
F_8 ( & V_22 -> V_15 ) ;
F_125 ( V_22 , & V_22 -> V_97 , & V_22 -> F_106 ) ;
F_8 ( & V_22 -> V_15 ) ;
F_125 ( V_22 , & V_22 -> V_200 , & V_22 -> V_161 ) ;
F_8 ( & V_22 -> V_15 ) ;
F_125 ( V_22 , & V_22 -> V_117 , & V_22 -> V_201 ) ;
F_8 ( & V_22 -> V_15 ) ;
F_211 ( V_22 ) ;
F_10 ( & V_22 -> V_15 ) ;
}
static void F_215 ( struct V_198 * V_199 )
{
struct V_22 * V_22 = F_214 ( F_216 ( V_199 ) , struct V_22 , V_202 ) ;
F_29 ( V_22 ) ;
F_217 ( V_22 -> V_43 , & V_22 -> V_202 , V_176 ) ;
}
static void F_218 ( struct V_198 * V_199 )
{
struct V_22 * V_22 = F_214 ( F_216 ( V_199 ) , struct V_22 ,
V_203 ) ;
if ( F_146 ( V_22 ) == V_147 && ! V_22 -> V_141 . V_158 ) {
V_22 -> V_141 . V_158 = true ;
F_219 ( V_22 ) ;
F_71 ( V_22 , - V_56 ) ;
}
}
static struct V_204 * F_220 ( struct V_198 * V_199 )
{
return F_214 ( V_199 , struct V_204 , V_44 ) ;
}
static void F_221 ( struct V_204 * V_205 )
{
F_222 ( & V_205 -> F_222 ) ;
}
static void F_223 ( struct V_204 * V_205 , struct V_22 * V_22 ,
void (* F_38)( struct V_198 * ) )
{
F_224 ( & V_205 -> V_44 , F_38 ) ;
F_225 ( & V_205 -> F_222 ) ;
F_30 ( V_22 -> V_43 , & V_205 -> V_44 ) ;
F_226 ( & V_205 -> F_222 ) ;
}
static struct V_206 * F_227 ( struct V_198 * V_199 )
{
return F_214 ( F_220 ( V_199 ) , struct V_206 , V_205 ) ;
}
static void F_228 ( struct V_198 * V_199 )
{
struct V_206 * V_207 = F_227 ( V_199 ) ;
V_207 -> V_28 -> V_171 = true ;
F_70 ( V_207 -> V_28 ) ;
F_221 ( & V_207 -> V_205 ) ;
}
static void F_229 ( struct V_198 * V_199 )
{
struct V_206 * V_207 = F_227 ( V_199 ) ;
V_207 -> V_28 -> V_171 = false ;
F_221 ( & V_207 -> V_205 ) ;
}
static void V_206 ( struct V_27 * V_28 , void (* F_38)( struct V_198 * ) )
{
struct V_206 V_207 ;
V_207 . V_28 = V_28 ;
F_223 ( & V_207 . V_205 , V_28 -> V_22 , F_38 ) ;
}
static enum V_157 F_146 ( struct V_22 * V_22 )
{
return V_22 -> V_141 . V_208 ;
}
static void F_230 ( struct V_22 * V_22 , const char * V_209 )
{
F_152 ( V_22 -> V_154 -> V_155 ) ;
F_231 ( L_16 ,
F_121 ( V_22 -> V_66 ) , V_209 ) ;
}
static void F_219 ( struct V_22 * V_22 )
{
if ( ! V_22 -> V_141 . V_158 )
F_230 ( V_22 , L_17 ) ;
else
F_230 ( V_22 , L_18 ) ;
}
static bool F_232 ( struct V_210 * V_211 )
{
return V_211 -> V_212 . V_213 ;
}
static void F_233 ( struct V_22 * V_22 )
{
struct V_210 * V_211 = V_22 -> V_154 -> V_214 ;
if ( F_232 ( V_211 ) ) {
V_22 -> V_165 = F_164 ;
V_22 -> V_161 = F_118 ;
V_22 -> V_201 = F_123 ;
} else {
V_22 -> V_165 = F_160 ;
V_22 -> V_161 = F_112 ;
}
}
static void F_148 ( struct V_22 * V_22 , enum V_157 V_209 )
{
struct V_210 * V_211 = V_22 -> V_154 -> V_214 ;
bool V_215 = F_234 ( V_22 -> V_116 ) ;
enum V_157 V_216 = F_146 ( V_22 ) ;
unsigned long V_203 = F_235 ( V_217 ) * V_218 ;
if ( V_209 == V_148 && V_215 ) {
F_236 ( L_19 ,
F_121 ( V_22 -> V_66 ) ) ;
if ( V_216 != V_209 )
V_209 = V_216 ;
else
V_209 = V_149 ;
}
if ( V_216 == V_159 )
V_209 = V_216 ;
switch ( V_209 ) {
case V_159 :
if ( V_216 != V_209 )
F_230 ( V_22 , L_20 ) ;
F_237 ( V_22 -> V_116 ) ;
V_22 -> F_175 = F_180 ;
V_22 -> V_185 = F_180 ;
V_22 -> F_172 = F_182 ;
V_22 -> V_165 = F_182 ;
V_22 -> F_106 = F_104 ;
V_22 -> V_161 = F_110 ;
F_75 ( V_22 ) ;
break;
case V_149 :
if ( V_216 != V_209 )
F_230 ( V_22 , L_21 ) ;
F_237 ( V_22 -> V_116 ) ;
V_22 -> F_175 = F_177 ;
V_22 -> V_185 = F_179 ;
V_22 -> F_172 = F_178 ;
V_22 -> V_165 = F_181 ;
V_22 -> F_106 = F_104 ;
V_22 -> V_161 = F_111 ;
F_75 ( V_22 ) ;
break;
case V_147 :
if ( V_216 != V_209 )
F_219 ( V_22 ) ;
V_22 -> V_55 = true ;
V_22 -> F_175 = F_177 ;
V_22 -> V_185 = F_165 ;
V_22 -> F_172 = F_178 ;
V_22 -> F_106 = F_106 ;
F_233 ( V_22 ) ;
if ( ! V_22 -> V_141 . V_158 && V_203 )
F_217 ( V_22 -> V_43 , & V_22 -> V_203 , V_203 ) ;
break;
case V_148 :
if ( V_216 != V_209 )
F_230 ( V_22 , L_22 ) ;
V_22 -> V_55 = false ;
V_22 -> V_141 . V_158 = V_211 -> V_219 . V_158 ;
F_238 ( V_22 -> V_116 ) ;
V_22 -> F_175 = F_175 ;
V_22 -> V_185 = F_165 ;
V_22 -> F_172 = F_172 ;
V_22 -> F_106 = F_106 ;
F_233 ( V_22 ) ;
break;
}
V_22 -> V_141 . V_208 = V_209 ;
V_211 -> V_212 . V_208 = V_209 ;
}
static void F_239 ( struct V_22 * V_22 )
{
const char * V_220 = F_121 ( V_22 -> V_66 ) ;
F_135 ( L_23 , V_220 ) ;
if ( F_240 ( V_22 -> V_116 ) ) {
F_236 ( L_24 , V_220 ) ;
F_148 ( V_22 , V_159 ) ;
}
if ( F_241 ( V_22 -> V_116 ) ) {
F_236 ( L_25 , V_220 ) ;
F_148 ( V_22 , V_159 ) ;
}
}
static void F_108 ( struct V_22 * V_22 , const char * V_26 , int V_40 )
{
F_135 ( L_26 ,
F_121 ( V_22 -> V_66 ) , V_26 , V_40 ) ;
F_239 ( V_22 ) ;
F_148 ( V_22 , V_149 ) ;
}
static void F_103 ( struct V_27 * V_28 , struct V_29 * V_29 )
{
unsigned long V_70 ;
struct V_22 * V_22 = V_28 -> V_22 ;
F_65 ( & V_28 -> V_17 , V_70 ) ;
F_91 ( & V_28 -> V_74 , V_29 ) ;
F_66 ( & V_28 -> V_17 , V_70 ) ;
F_29 ( V_22 ) ;
}
static void F_242 ( struct V_27 * V_28 , struct V_29 * V_29 )
{
struct V_22 * V_22 = V_28 -> V_22 ;
F_12 ( & V_22 -> V_15 ) ;
F_103 ( V_28 , V_29 ) ;
F_14 ( & V_22 -> V_15 ) ;
}
static void F_243 ( struct V_27 * V_28 , struct V_45 * V_50 )
{
unsigned long V_70 ;
struct V_22 * V_22 = V_28 -> V_22 ;
F_12 ( & V_22 -> V_15 ) ;
F_65 ( & V_28 -> V_17 , V_70 ) ;
F_96 ( & V_50 -> V_192 , & V_28 -> V_73 ) ;
F_66 ( & V_28 -> V_17 , V_70 ) ;
F_14 ( & V_22 -> V_15 ) ;
F_29 ( V_22 ) ;
}
static void F_244 ( struct V_27 * V_28 , struct V_29 * V_29 )
{
struct V_89 * V_90 = F_85 ( V_29 , sizeof( struct V_89 ) ) ;
V_90 -> V_28 = V_28 ;
V_90 -> V_169 = NULL ;
V_90 -> V_91 = NULL ;
V_90 -> V_101 = NULL ;
V_90 -> V_50 = NULL ;
}
static int F_245 ( struct V_221 * V_154 , struct V_29 * V_29 )
{
int V_40 ;
struct V_27 * V_28 = V_154 -> V_214 ;
T_1 V_83 = F_76 ( V_28 , V_29 ) ;
struct V_1 * V_2 = V_28 -> V_2 ;
struct V_166 V_156 ;
struct V_45 * V_160 , * V_163 ;
struct V_7 V_8 ;
F_244 ( V_28 , V_29 ) ;
if ( V_28 -> V_171 ) {
V_29 -> V_42 = V_58 ;
F_28 ( V_29 ) ;
return V_222 ;
}
if ( F_146 ( V_28 -> V_22 ) == V_159 ) {
F_90 ( V_29 ) ;
return V_222 ;
}
if ( V_29 -> V_86 & ( V_87 | V_88 ) ||
F_84 ( V_29 ) == V_41 ) {
F_242 ( V_28 , V_29 ) ;
return V_222 ;
}
F_4 ( V_28 -> V_2 , V_83 , & V_8 ) ;
if ( F_31 ( V_28 -> V_22 , & V_8 , V_29 , & V_160 ) )
return V_222 ;
V_40 = F_173 ( V_2 , V_83 , 0 , & V_156 ) ;
switch ( V_40 ) {
case 0 :
if ( F_246 ( V_156 . V_172 ) ) {
F_243 ( V_28 , V_160 ) ;
return V_222 ;
}
F_3 ( V_28 -> V_2 , V_156 . V_83 , & V_8 ) ;
if ( F_31 ( V_28 -> V_22 , & V_8 , V_29 , & V_163 ) ) {
F_100 ( V_28 , V_160 ) ;
return V_222 ;
}
F_83 ( V_28 -> V_22 , V_29 ) ;
F_100 ( V_28 , V_163 ) ;
F_100 ( V_28 , V_160 ) ;
F_79 ( V_28 , V_29 , V_156 . V_83 ) ;
return V_223 ;
case - V_173 :
case - V_224 :
F_243 ( V_28 , V_160 ) ;
return V_222 ;
default:
F_90 ( V_29 ) ;
F_100 ( V_28 , V_160 ) ;
return V_222 ;
}
}
static int F_247 ( struct V_225 * V_226 , int V_227 )
{
struct V_210 * V_211 = F_214 ( V_226 , struct V_210 , V_228 ) ;
struct V_229 * V_230 ;
if ( F_146 ( V_211 -> V_22 ) == V_147 )
return 1 ;
V_230 = F_248 ( V_211 -> V_231 -> V_38 ) ;
return F_249 ( & V_230 -> V_232 , V_227 ) ;
}
static void F_250 ( struct V_22 * V_22 )
{
unsigned long V_70 ;
struct V_27 * V_28 ;
F_72 () ;
F_73 (tc, &pool->active_thins, list) {
F_65 ( & V_28 -> V_17 , V_70 ) ;
F_60 ( & V_28 -> V_74 , & V_28 -> V_75 ) ;
F_61 ( & V_28 -> V_75 ) ;
F_66 ( & V_28 -> V_17 , V_70 ) ;
}
F_74 () ;
}
static bool F_251 ( struct V_210 * V_211 )
{
struct V_229 * V_230 = F_248 ( V_211 -> V_231 -> V_38 ) ;
return V_230 && F_252 ( V_230 ) ;
}
static bool F_253 ( T_2 V_233 , T_5 V_234 )
{
return ! F_77 ( V_233 , V_234 ) ;
}
static void F_254 ( struct V_210 * V_211 )
{
struct V_22 * V_22 = V_211 -> V_22 ;
struct V_67 * V_235 = V_211 -> V_231 -> V_38 ;
struct V_236 * V_237 = & F_248 ( V_235 ) -> V_238 ;
const char * V_239 = NULL ;
char V_240 [ V_241 ] ;
if ( ! V_211 -> V_212 . V_213 )
return;
if ( ! F_251 ( V_211 ) )
V_239 = L_27 ;
else if ( V_237 -> V_242 < V_22 -> V_24 )
V_239 = L_28 ;
if ( V_239 ) {
F_120 ( L_29 , F_255 ( V_235 , V_240 ) , V_239 ) ;
V_211 -> V_212 . V_213 = false ;
}
}
static int F_256 ( struct V_22 * V_22 , struct V_221 * V_154 )
{
struct V_210 * V_211 = V_154 -> V_214 ;
enum V_157 V_216 = F_146 ( V_22 ) ;
enum V_157 V_209 = V_211 -> V_212 . V_208 ;
V_211 -> V_212 . V_208 = V_216 ;
V_22 -> V_154 = V_154 ;
V_22 -> V_141 = V_211 -> V_212 ;
V_22 -> V_152 = V_211 -> V_152 ;
F_148 ( V_22 , V_209 ) ;
return 0 ;
}
static void F_257 ( struct V_22 * V_22 , struct V_221 * V_154 )
{
if ( V_22 -> V_154 == V_154 )
V_22 -> V_154 = NULL ;
}
static void F_258 ( struct V_243 * V_141 )
{
V_141 -> V_208 = V_148 ;
V_141 -> V_142 = true ;
V_141 -> V_244 = true ;
V_141 -> V_213 = true ;
V_141 -> V_158 = false ;
}
static void F_259 ( struct V_22 * V_22 )
{
F_54 ( V_22 ) ;
F_260 ( V_22 -> V_191 ) ;
if ( F_261 ( V_22 -> V_116 ) < 0 )
F_120 ( L_30 , V_168 ) ;
F_262 ( V_22 -> V_48 ) ;
F_263 ( V_22 -> V_132 ) ;
if ( V_22 -> V_43 )
F_264 ( V_22 -> V_43 ) ;
if ( V_22 -> V_125 )
F_105 ( V_22 -> V_125 , V_22 -> V_108 ) ;
F_265 ( V_22 -> V_108 ) ;
F_266 ( V_22 -> V_139 ) ;
F_266 ( V_22 -> V_92 ) ;
F_267 ( V_22 ) ;
}
static struct V_22 * F_268 ( struct V_63 * V_66 ,
struct V_67 * V_245 ,
unsigned long V_233 ,
int V_246 , char * * error )
{
int V_40 ;
void * V_247 ;
struct V_22 * V_22 ;
struct V_248 * V_116 ;
bool V_249 = V_246 ? false : true ;
V_116 = F_269 ( V_245 , V_233 , V_249 ) ;
if ( F_270 ( V_116 ) ) {
* error = L_31 ;
return (struct V_22 * ) V_116 ;
}
V_22 = F_271 ( sizeof( * V_22 ) , V_250 ) ;
if ( ! V_22 ) {
* error = L_32 ;
V_247 = F_272 ( - V_127 ) ;
goto V_251;
}
V_22 -> V_116 = V_116 ;
V_22 -> V_24 = V_233 ;
if ( V_233 & ( V_233 - 1 ) )
V_22 -> V_23 = - 1 ;
else
V_22 -> V_23 = F_273 ( V_233 ) ;
V_22 -> V_152 = 0 ;
F_258 ( & V_22 -> V_141 ) ;
V_22 -> V_48 = F_274 () ;
if ( ! V_22 -> V_48 ) {
* error = L_33 ;
V_247 = F_272 ( - V_127 ) ;
goto V_252;
}
V_22 -> V_132 = F_275 ( & V_253 ) ;
if ( F_270 ( V_22 -> V_132 ) ) {
V_40 = F_276 ( V_22 -> V_132 ) ;
* error = L_34 ;
V_247 = F_272 ( V_40 ) ;
goto V_254;
}
V_22 -> V_43 = F_277 ( L_35 V_255 , V_256 ) ;
if ( ! V_22 -> V_43 ) {
* error = L_36 ;
V_247 = F_272 ( - V_127 ) ;
goto V_257;
}
F_5 ( & V_22 -> V_15 ) ;
F_278 ( & V_22 -> V_44 , F_213 ) ;
F_279 ( & V_22 -> V_202 , F_215 ) ;
F_279 ( & V_22 -> V_203 , F_218 ) ;
F_280 ( & V_22 -> V_17 ) ;
F_61 ( & V_22 -> V_93 ) ;
F_50 ( & V_22 -> V_97 ) ;
F_50 ( & V_22 -> V_200 ) ;
F_50 ( & V_22 -> V_117 ) ;
F_50 ( & V_22 -> V_195 ) ;
V_22 -> V_153 = false ;
V_22 -> V_258 = true ;
V_22 -> V_55 = false ;
V_22 -> V_139 = F_281 () ;
if ( ! V_22 -> V_139 ) {
* error = L_37 ;
V_247 = F_272 ( - V_127 ) ;
goto V_259;
}
V_22 -> V_92 = F_281 () ;
if ( ! V_22 -> V_92 ) {
* error = L_38 ;
V_247 = F_272 ( - V_127 ) ;
goto V_260;
}
V_22 -> V_125 = NULL ;
V_22 -> V_108 = F_282 ( V_261 ,
V_262 ) ;
if ( ! V_22 -> V_108 ) {
* error = L_39 ;
V_247 = F_272 ( - V_127 ) ;
goto V_263;
}
V_22 -> V_191 = F_283 ( sizeof( * V_22 -> V_191 ) * V_190 ) ;
if ( ! V_22 -> V_191 ) {
* error = L_40 ;
V_247 = F_272 ( - V_127 ) ;
goto V_264;
}
V_22 -> V_265 = 1 ;
V_22 -> V_175 = V_20 ;
V_22 -> V_66 = V_66 ;
V_22 -> V_68 = V_245 ;
F_51 ( V_22 ) ;
return V_22 ;
V_264:
F_265 ( V_22 -> V_108 ) ;
V_263:
F_266 ( V_22 -> V_92 ) ;
V_260:
F_266 ( V_22 -> V_139 ) ;
V_259:
F_264 ( V_22 -> V_43 ) ;
V_257:
F_263 ( V_22 -> V_132 ) ;
V_254:
F_262 ( V_22 -> V_48 ) ;
V_252:
F_267 ( V_22 ) ;
V_251:
if ( F_261 ( V_116 ) )
F_120 ( L_30 , V_168 ) ;
return V_247 ;
}
static void F_284 ( struct V_22 * V_22 )
{
F_19 ( ! F_52 ( & V_59 . V_60 ) ) ;
V_22 -> V_265 ++ ;
}
static void F_285 ( struct V_22 * V_22 )
{
F_19 ( ! F_52 ( & V_59 . V_60 ) ) ;
F_19 ( ! V_22 -> V_265 ) ;
if ( ! -- V_22 -> V_265 )
F_259 ( V_22 ) ;
}
static struct V_22 * F_286 ( struct V_63 * V_66 ,
struct V_67 * V_245 ,
unsigned long V_233 , int V_246 ,
char * * error , int * V_266 )
{
struct V_22 * V_22 = F_58 ( V_245 ) ;
if ( V_22 ) {
if ( V_22 -> V_66 != V_66 ) {
* error = L_41 ;
return F_272 ( - V_267 ) ;
}
F_284 ( V_22 ) ;
} else {
V_22 = F_56 ( V_66 ) ;
if ( V_22 ) {
if ( V_22 -> V_68 != V_245 ) {
* error = L_42 ;
return F_272 ( - V_150 ) ;
}
F_284 ( V_22 ) ;
} else {
V_22 = F_268 ( V_66 , V_245 , V_233 , V_246 , error ) ;
* V_266 = 1 ;
}
}
return V_22 ;
}
static void F_287 ( struct V_221 * V_154 )
{
struct V_210 * V_211 = V_154 -> V_214 ;
F_288 ( & V_59 . V_60 ) ;
F_257 ( V_211 -> V_22 , V_154 ) ;
F_285 ( V_211 -> V_22 ) ;
F_289 ( V_154 , V_211 -> V_245 ) ;
F_289 ( V_154 , V_211 -> V_231 ) ;
F_267 ( V_211 ) ;
F_290 ( & V_59 . V_60 ) ;
}
static int F_291 ( struct V_268 * V_269 , struct V_243 * V_141 ,
struct V_221 * V_154 )
{
int V_40 ;
unsigned V_270 ;
const char * V_271 ;
static struct V_272 V_273 [] = {
{ 0 , 4 , L_43 } ,
} ;
if ( ! V_269 -> V_270 )
return 0 ;
V_40 = F_292 ( V_273 , V_269 , & V_270 , & V_154 -> error ) ;
if ( V_40 )
return - V_150 ;
while ( V_270 && ! V_40 ) {
V_271 = F_293 ( V_269 ) ;
V_270 -- ;
if ( ! strcasecmp ( V_271 , L_44 ) )
V_141 -> V_142 = false ;
else if ( ! strcasecmp ( V_271 , L_45 ) )
V_141 -> V_244 = false ;
else if ( ! strcasecmp ( V_271 , L_46 ) )
V_141 -> V_213 = false ;
else if ( ! strcasecmp ( V_271 , L_47 ) )
V_141 -> V_208 = V_149 ;
else if ( ! strcasecmp ( V_271 , L_48 ) )
V_141 -> V_158 = true ;
else {
V_154 -> error = L_49 ;
V_40 = - V_150 ;
break;
}
}
return V_40 ;
}
static void F_294 ( void * V_53 )
{
struct V_22 * V_22 = V_53 ;
F_120 ( L_50 ,
F_121 ( V_22 -> V_66 ) ) ;
F_152 ( V_22 -> V_154 -> V_155 ) ;
}
static T_2 F_295 ( struct V_67 * V_38 )
{
return F_296 ( V_38 -> V_274 ) >> V_82 ;
}
static void F_297 ( struct V_67 * V_38 )
{
T_2 V_275 = F_295 ( V_38 ) ;
char V_276 [ V_241 ] ;
if ( V_275 > V_277 )
F_120 ( L_51 ,
F_255 ( V_38 , V_276 ) , V_278 ) ;
}
static T_2 F_298 ( struct V_67 * V_38 )
{
T_2 V_275 = F_295 ( V_38 ) ;
if ( V_275 > V_278 )
V_275 = V_278 ;
return V_275 ;
}
static T_1 F_299 ( struct V_67 * V_38 )
{
T_2 V_275 = F_298 ( V_38 ) ;
F_77 ( V_275 , V_279 ) ;
return V_275 ;
}
static T_1 F_300 ( struct V_210 * V_211 )
{
T_1 V_280 = F_299 ( V_211 -> V_245 -> V_38 ) / 4 ;
return F_301 ( ( T_1 ) 1024ULL , V_280 ) ;
}
static int F_302 ( struct V_221 * V_154 , unsigned V_270 , char * * V_281 )
{
int V_40 , V_282 = 0 ;
struct V_210 * V_211 ;
struct V_22 * V_22 ;
struct V_243 V_141 ;
struct V_268 V_269 ;
struct V_135 * V_231 ;
unsigned long V_233 ;
T_1 V_152 ;
struct V_135 * V_245 ;
T_6 V_283 ;
F_288 ( & V_59 . V_60 ) ;
if ( V_270 < 4 ) {
V_154 -> error = L_52 ;
V_40 = - V_150 ;
goto V_284;
}
V_269 . V_270 = V_270 ;
V_269 . V_281 = V_281 ;
F_258 ( & V_141 ) ;
F_303 ( & V_269 , 4 ) ;
V_40 = F_291 ( & V_269 , & V_141 , V_154 ) ;
if ( V_40 )
goto V_284;
V_283 = V_285 | ( ( V_141 . V_208 == V_149 ) ? 0 : V_286 ) ;
V_40 = F_304 ( V_154 , V_281 [ 0 ] , V_283 , & V_245 ) ;
if ( V_40 ) {
V_154 -> error = L_53 ;
goto V_284;
}
F_297 ( V_245 -> V_38 ) ;
V_40 = F_304 ( V_154 , V_281 [ 1 ] , V_285 | V_286 , & V_231 ) ;
if ( V_40 ) {
V_154 -> error = L_54 ;
goto V_287;
}
if ( F_305 ( V_281 [ 2 ] , 10 , & V_233 ) || ! V_233 ||
V_233 < V_288 ||
V_233 > V_289 ||
V_233 & ( V_288 - 1 ) ) {
V_154 -> error = L_55 ;
V_40 = - V_150 ;
goto V_109;
}
if ( F_306 ( V_281 [ 3 ] , 10 , ( unsigned long long * ) & V_152 ) ) {
V_154 -> error = L_56 ;
V_40 = - V_150 ;
goto V_109;
}
V_211 = F_307 ( sizeof( * V_211 ) , V_250 ) ;
if ( ! V_211 ) {
V_40 = - V_127 ;
goto V_109;
}
V_22 = F_286 ( F_308 ( V_154 -> V_155 ) , V_245 -> V_38 ,
V_233 , V_141 . V_208 == V_149 , & V_154 -> error , & V_282 ) ;
if ( F_270 ( V_22 ) ) {
V_40 = F_276 ( V_22 ) ;
goto V_290;
}
if ( ! V_282 && V_141 . V_244 != V_22 -> V_141 . V_244 ) {
V_154 -> error = L_57 ;
V_40 = - V_150 ;
goto V_291;
}
V_211 -> V_22 = V_22 ;
V_211 -> V_154 = V_154 ;
V_211 -> V_245 = V_245 ;
V_211 -> V_231 = V_231 ;
V_211 -> V_152 = V_152 ;
V_211 -> V_212 = V_211 -> V_219 = V_141 ;
V_154 -> V_292 = 1 ;
V_154 -> V_293 = true ;
if ( V_141 . V_244 && V_141 . V_213 ) {
V_154 -> V_294 = 1 ;
V_154 -> V_295 = true ;
}
V_154 -> V_214 = V_211 ;
V_40 = F_309 ( V_211 -> V_22 -> V_116 ,
F_300 ( V_211 ) ,
F_294 ,
V_22 ) ;
if ( V_40 )
goto V_291;
V_211 -> V_228 . V_296 = F_247 ;
F_310 ( V_154 -> V_155 , & V_211 -> V_228 ) ;
F_290 ( & V_59 . V_60 ) ;
return 0 ;
V_291:
F_285 ( V_22 ) ;
V_290:
F_267 ( V_211 ) ;
V_109:
F_289 ( V_154 , V_231 ) ;
V_287:
F_289 ( V_154 , V_245 ) ;
V_284:
F_290 ( & V_59 . V_60 ) ;
return V_40 ;
}
static int F_311 ( struct V_221 * V_154 , struct V_29 * V_29 )
{
int V_40 ;
struct V_210 * V_211 = V_154 -> V_214 ;
struct V_22 * V_22 = V_211 -> V_22 ;
unsigned long V_70 ;
F_65 ( & V_22 -> V_17 , V_70 ) ;
V_29 -> V_84 = V_211 -> V_231 -> V_38 ;
V_40 = V_223 ;
F_66 ( & V_22 -> V_17 , V_70 ) ;
return V_40 ;
}
static int F_312 ( struct V_221 * V_154 , bool * V_297 )
{
int V_40 ;
struct V_210 * V_211 = V_154 -> V_214 ;
struct V_22 * V_22 = V_211 -> V_22 ;
T_2 V_298 = V_154 -> V_36 ;
T_1 V_299 ;
* V_297 = false ;
( void ) F_77 ( V_298 , V_22 -> V_24 ) ;
V_40 = F_313 ( V_22 -> V_116 , & V_299 ) ;
if ( V_40 ) {
F_236 ( L_58 ,
F_121 ( V_22 -> V_66 ) ) ;
return V_40 ;
}
if ( V_298 < V_299 ) {
F_236 ( L_59 ,
F_121 ( V_22 -> V_66 ) ,
( unsigned long long ) V_298 , V_299 ) ;
return - V_150 ;
} else if ( V_298 > V_299 ) {
if ( F_234 ( V_22 -> V_116 ) ) {
F_236 ( L_60 ,
F_121 ( V_22 -> V_66 ) ) ;
return 0 ;
}
if ( V_299 )
F_231 ( L_61 ,
F_121 ( V_22 -> V_66 ) ,
V_299 , ( unsigned long long ) V_298 ) ;
V_40 = F_314 ( V_22 -> V_116 , V_298 ) ;
if ( V_40 ) {
F_108 ( V_22 , L_62 , V_40 ) ;
return V_40 ;
}
* V_297 = true ;
}
return 0 ;
}
static int F_315 ( struct V_221 * V_154 , bool * V_297 )
{
int V_40 ;
struct V_210 * V_211 = V_154 -> V_214 ;
struct V_22 * V_22 = V_211 -> V_22 ;
T_1 V_275 , V_300 ;
* V_297 = false ;
V_275 = F_299 ( V_22 -> V_68 ) ;
V_40 = F_316 ( V_22 -> V_116 , & V_300 ) ;
if ( V_40 ) {
F_236 ( L_63 ,
F_121 ( V_22 -> V_66 ) ) ;
return V_40 ;
}
if ( V_275 < V_300 ) {
F_236 ( L_64 ,
F_121 ( V_22 -> V_66 ) ,
V_275 , V_300 ) ;
return - V_150 ;
} else if ( V_275 > V_300 ) {
if ( F_234 ( V_22 -> V_116 ) ) {
F_236 ( L_65 ,
F_121 ( V_22 -> V_66 ) ) ;
return 0 ;
}
F_297 ( V_22 -> V_68 ) ;
F_231 ( L_66 ,
F_121 ( V_22 -> V_66 ) ,
V_300 , V_275 ) ;
V_40 = F_317 ( V_22 -> V_116 , V_275 ) ;
if ( V_40 ) {
F_108 ( V_22 , L_67 , V_40 ) ;
return V_40 ;
}
* V_297 = true ;
}
return 0 ;
}
static int F_318 ( struct V_221 * V_154 )
{
int V_40 ;
bool V_301 , V_302 ;
struct V_210 * V_211 = V_154 -> V_214 ;
struct V_22 * V_22 = V_211 -> V_22 ;
V_40 = F_256 ( V_22 , V_154 ) ;
if ( V_40 )
return V_40 ;
V_40 = F_312 ( V_154 , & V_301 ) ;
if ( V_40 )
return V_40 ;
V_40 = F_315 ( V_154 , & V_302 ) ;
if ( V_40 )
return V_40 ;
if ( V_301 || V_302 )
( void ) F_149 ( V_22 ) ;
return 0 ;
}
static void F_319 ( struct V_22 * V_22 )
{
struct V_27 * V_28 ;
V_28 = F_205 ( V_22 ) ;
while ( V_28 ) {
F_320 ( V_28 -> V_303 ) ;
V_28 = F_208 ( V_22 , V_28 ) ;
}
}
static void F_321 ( struct V_22 * V_22 )
{
struct V_27 * V_28 ;
V_28 = F_205 ( V_22 ) ;
while ( V_28 ) {
F_322 ( V_28 -> V_303 ) ;
V_28 = F_208 ( V_22 , V_28 ) ;
}
}
static void F_323 ( struct V_221 * V_154 )
{
struct V_210 * V_211 = V_154 -> V_214 ;
struct V_22 * V_22 = V_211 -> V_22 ;
unsigned long V_70 ;
F_250 ( V_22 ) ;
F_321 ( V_22 ) ;
F_65 ( & V_22 -> V_17 , V_70 ) ;
V_22 -> V_153 = false ;
V_22 -> V_258 = false ;
F_66 ( & V_22 -> V_17 , V_70 ) ;
F_215 ( & V_22 -> V_202 . V_304 ) ;
}
static void F_324 ( struct V_221 * V_154 )
{
struct V_210 * V_211 = V_154 -> V_214 ;
struct V_22 * V_22 = V_211 -> V_22 ;
unsigned long V_70 ;
F_65 ( & V_22 -> V_17 , V_70 ) ;
V_22 -> V_258 = true ;
F_66 ( & V_22 -> V_17 , V_70 ) ;
F_319 ( V_22 ) ;
}
static void F_325 ( struct V_221 * V_154 )
{
struct V_210 * V_211 = V_154 -> V_214 ;
struct V_22 * V_22 = V_211 -> V_22 ;
unsigned long V_70 ;
F_321 ( V_22 ) ;
F_65 ( & V_22 -> V_17 , V_70 ) ;
V_22 -> V_258 = false ;
F_66 ( & V_22 -> V_17 , V_70 ) ;
}
static void F_326 ( struct V_221 * V_154 )
{
struct V_210 * V_211 = V_154 -> V_214 ;
struct V_22 * V_22 = V_211 -> V_22 ;
F_327 ( & V_22 -> V_202 ) ;
F_327 ( & V_22 -> V_203 ) ;
F_328 ( V_22 -> V_43 ) ;
( void ) F_149 ( V_22 ) ;
}
static int F_329 ( unsigned V_270 , unsigned V_305 )
{
if ( V_270 != V_305 ) {
F_120 ( L_68 ,
V_270 , V_305 ) ;
return - V_150 ;
}
return 0 ;
}
static int F_330 ( char * V_306 , T_7 * V_307 , int V_308 )
{
if ( ! F_306 ( V_306 , 10 , ( unsigned long long * ) V_307 ) &&
* V_307 <= V_309 )
return 0 ;
if ( V_308 )
F_120 ( L_69 , V_306 ) ;
return - V_150 ;
}
static int F_331 ( unsigned V_270 , char * * V_281 , struct V_22 * V_22 )
{
T_7 V_307 ;
int V_40 ;
V_40 = F_329 ( V_270 , 2 ) ;
if ( V_40 )
return V_40 ;
V_40 = F_330 ( V_281 [ 1 ] , & V_307 , 1 ) ;
if ( V_40 )
return V_40 ;
V_40 = F_332 ( V_22 -> V_116 , V_307 ) ;
if ( V_40 ) {
F_120 ( L_70 ,
V_281 [ 1 ] ) ;
return V_40 ;
}
return 0 ;
}
static int F_333 ( unsigned V_270 , char * * V_281 , struct V_22 * V_22 )
{
T_7 V_307 ;
T_7 V_310 ;
int V_40 ;
V_40 = F_329 ( V_270 , 3 ) ;
if ( V_40 )
return V_40 ;
V_40 = F_330 ( V_281 [ 1 ] , & V_307 , 1 ) ;
if ( V_40 )
return V_40 ;
V_40 = F_330 ( V_281 [ 2 ] , & V_310 , 1 ) ;
if ( V_40 )
return V_40 ;
V_40 = F_334 ( V_22 -> V_116 , V_307 , V_310 ) ;
if ( V_40 ) {
F_120 ( L_71 ,
V_281 [ 1 ] , V_281 [ 2 ] ) ;
return V_40 ;
}
return 0 ;
}
static int F_335 ( unsigned V_270 , char * * V_281 , struct V_22 * V_22 )
{
T_7 V_307 ;
int V_40 ;
V_40 = F_329 ( V_270 , 2 ) ;
if ( V_40 )
return V_40 ;
V_40 = F_330 ( V_281 [ 1 ] , & V_307 , 1 ) ;
if ( V_40 )
return V_40 ;
V_40 = F_336 ( V_22 -> V_116 , V_307 ) ;
if ( V_40 )
F_120 ( L_72 , V_281 [ 1 ] ) ;
return V_40 ;
}
static int F_337 ( unsigned V_270 , char * * V_281 , struct V_22 * V_22 )
{
T_7 V_311 , V_312 ;
int V_40 ;
V_40 = F_329 ( V_270 , 3 ) ;
if ( V_40 )
return V_40 ;
if ( F_306 ( V_281 [ 1 ] , 10 , ( unsigned long long * ) & V_311 ) ) {
F_120 ( L_73 , V_281 [ 1 ] ) ;
return - V_150 ;
}
if ( F_306 ( V_281 [ 2 ] , 10 , ( unsigned long long * ) & V_312 ) ) {
F_120 ( L_74 , V_281 [ 2 ] ) ;
return - V_150 ;
}
V_40 = F_338 ( V_22 -> V_116 , V_311 , V_312 ) ;
if ( V_40 ) {
F_120 ( L_75 ,
V_281 [ 1 ] , V_281 [ 2 ] ) ;
return V_40 ;
}
return 0 ;
}
static int F_339 ( unsigned V_270 , char * * V_281 , struct V_22 * V_22 )
{
int V_40 ;
V_40 = F_329 ( V_270 , 1 ) ;
if ( V_40 )
return V_40 ;
( void ) F_149 ( V_22 ) ;
V_40 = F_340 ( V_22 -> V_116 ) ;
if ( V_40 )
F_120 ( L_76 ) ;
return V_40 ;
}
static int F_341 ( unsigned V_270 , char * * V_281 , struct V_22 * V_22 )
{
int V_40 ;
V_40 = F_329 ( V_270 , 1 ) ;
if ( V_40 )
return V_40 ;
V_40 = F_342 ( V_22 -> V_116 ) ;
if ( V_40 )
F_120 ( L_77 ) ;
return V_40 ;
}
static int F_343 ( struct V_221 * V_154 , unsigned V_270 , char * * V_281 )
{
int V_40 = - V_150 ;
struct V_210 * V_211 = V_154 -> V_214 ;
struct V_22 * V_22 = V_211 -> V_22 ;
if ( F_146 ( V_22 ) >= V_149 ) {
F_236 ( L_78 ,
F_121 ( V_22 -> V_66 ) ) ;
return - V_313 ;
}
if ( ! strcasecmp ( V_281 [ 0 ] , L_79 ) )
V_40 = F_331 ( V_270 , V_281 , V_22 ) ;
else if ( ! strcasecmp ( V_281 [ 0 ] , L_80 ) )
V_40 = F_333 ( V_270 , V_281 , V_22 ) ;
else if ( ! strcasecmp ( V_281 [ 0 ] , L_81 ) )
V_40 = F_335 ( V_270 , V_281 , V_22 ) ;
else if ( ! strcasecmp ( V_281 [ 0 ] , L_82 ) )
V_40 = F_337 ( V_270 , V_281 , V_22 ) ;
else if ( ! strcasecmp ( V_281 [ 0 ] , L_83 ) )
V_40 = F_339 ( V_270 , V_281 , V_22 ) ;
else if ( ! strcasecmp ( V_281 [ 0 ] , L_84 ) )
V_40 = F_341 ( V_270 , V_281 , V_22 ) ;
else
F_120 ( L_85 , V_281 [ 0 ] ) ;
if ( ! V_40 )
( void ) F_149 ( V_22 ) ;
return V_40 ;
}
static void F_344 ( struct V_243 * V_141 , char * V_156 ,
unsigned V_314 , unsigned V_315 )
{
unsigned V_131 = ! V_141 -> V_142 + ! V_141 -> V_244 +
! V_141 -> V_213 + ( V_141 -> V_208 == V_149 ) +
V_141 -> V_158 ;
F_345 ( L_86 , V_131 ) ;
if ( ! V_141 -> V_142 )
F_345 ( L_87 ) ;
if ( ! V_141 -> V_244 )
F_345 ( L_88 ) ;
if ( ! V_141 -> V_213 )
F_345 ( L_89 ) ;
if ( V_141 -> V_208 == V_149 )
F_345 ( L_90 ) ;
if ( V_141 -> V_158 )
F_345 ( L_91 ) ;
}
static void F_346 ( struct V_221 * V_154 , T_8 type ,
unsigned V_316 , char * V_156 , unsigned V_315 )
{
int V_40 ;
unsigned V_314 = 0 ;
T_9 V_317 ;
T_1 V_318 ;
T_1 V_319 ;
T_1 V_320 ;
T_1 V_321 ;
T_1 V_322 ;
char V_240 [ V_241 ] ;
char V_323 [ V_241 ] ;
struct V_210 * V_211 = V_154 -> V_214 ;
struct V_22 * V_22 = V_211 -> V_22 ;
switch ( type ) {
case V_324 :
if ( F_146 ( V_22 ) == V_159 ) {
F_345 ( L_92 ) ;
break;
}
if ( ! ( V_316 & V_325 ) && ! F_347 ( V_154 ) )
( void ) F_149 ( V_22 ) ;
V_40 = F_348 ( V_22 -> V_116 , & V_317 ) ;
if ( V_40 ) {
F_236 ( L_93 ,
F_121 ( V_22 -> V_66 ) , V_40 ) ;
goto V_100;
}
V_40 = F_349 ( V_22 -> V_116 , & V_319 ) ;
if ( V_40 ) {
F_236 ( L_94 ,
F_121 ( V_22 -> V_66 ) , V_40 ) ;
goto V_100;
}
V_40 = F_316 ( V_22 -> V_116 , & V_321 ) ;
if ( V_40 ) {
F_236 ( L_95 ,
F_121 ( V_22 -> V_66 ) , V_40 ) ;
goto V_100;
}
V_40 = F_147 ( V_22 -> V_116 , & V_318 ) ;
if ( V_40 ) {
F_236 ( L_96 ,
F_121 ( V_22 -> V_66 ) , V_40 ) ;
goto V_100;
}
V_40 = F_313 ( V_22 -> V_116 , & V_320 ) ;
if ( V_40 ) {
F_236 ( L_97 ,
F_121 ( V_22 -> V_66 ) , V_40 ) ;
goto V_100;
}
V_40 = F_350 ( V_22 -> V_116 , & V_322 ) ;
if ( V_40 ) {
F_236 ( L_98 ,
F_121 ( V_22 -> V_66 ) , V_40 ) ;
goto V_100;
}
F_345 ( L_99 ,
( unsigned long long ) V_317 ,
( unsigned long long ) ( V_321 - V_319 ) ,
( unsigned long long ) V_321 ,
( unsigned long long ) ( V_320 - V_318 ) ,
( unsigned long long ) V_320 ) ;
if ( V_322 )
F_345 ( L_100 , V_322 ) ;
else
F_345 ( L_101 ) ;
if ( V_22 -> V_141 . V_208 == V_147 )
F_345 ( L_102 ) ;
else if ( V_22 -> V_141 . V_208 == V_149 )
F_345 ( L_103 ) ;
else
F_345 ( L_104 ) ;
if ( ! V_22 -> V_141 . V_244 )
F_345 ( L_88 ) ;
else if ( V_22 -> V_141 . V_213 )
F_345 ( L_105 ) ;
else
F_345 ( L_89 ) ;
if ( V_22 -> V_141 . V_158 )
F_345 ( L_91 ) ;
else
F_345 ( L_106 ) ;
if ( F_234 ( V_22 -> V_116 ) )
F_345 ( L_107 ) ;
else
F_345 ( L_101 ) ;
break;
case V_326 :
F_345 ( L_108 ,
F_351 ( V_240 , V_211 -> V_245 -> V_38 -> V_327 ) ,
F_351 ( V_323 , V_211 -> V_231 -> V_38 -> V_327 ) ,
( unsigned long ) V_22 -> V_24 ,
( unsigned long long ) V_211 -> V_152 ) ;
F_344 ( & V_211 -> V_219 , V_156 , V_314 , V_315 ) ;
break;
}
return;
V_100:
F_345 ( L_109 ) ;
}
static int F_352 ( struct V_221 * V_154 ,
T_10 F_38 , void * V_328 )
{
struct V_210 * V_211 = V_154 -> V_214 ;
return F_38 ( V_154 , V_211 -> V_231 , 0 , V_154 -> V_36 , V_328 ) ;
}
static void F_353 ( struct V_221 * V_154 , struct V_236 * V_238 )
{
struct V_210 * V_211 = V_154 -> V_214 ;
struct V_22 * V_22 = V_211 -> V_22 ;
T_2 V_329 = V_238 -> V_330 >> V_82 ;
if ( V_238 -> V_331 < V_22 -> V_24 ) {
while ( ! F_253 ( V_22 -> V_24 , V_238 -> V_331 ) ) {
if ( ( V_238 -> V_331 & ( V_238 -> V_331 - 1 ) ) == 0 )
V_238 -> V_331 -- ;
V_238 -> V_331 = F_354 ( V_238 -> V_331 ) ;
}
}
if ( V_329 < V_22 -> V_24 ||
! F_253 ( V_329 , V_22 -> V_24 ) ) {
if ( F_253 ( V_22 -> V_24 , V_238 -> V_331 ) )
F_355 ( V_238 , V_238 -> V_331 << V_82 ) ;
else
F_355 ( V_238 , V_22 -> V_24 << V_82 ) ;
F_356 ( V_238 , V_22 -> V_24 << V_82 ) ;
}
if ( ! V_211 -> V_212 . V_244 ) {
V_238 -> V_332 = 0 ;
return;
}
F_254 ( V_211 ) ;
}
static void F_207 ( struct V_27 * V_28 )
{
F_141 ( & V_28 -> V_333 ) ;
}
static void F_210 ( struct V_27 * V_28 )
{
if ( F_95 ( & V_28 -> V_333 ) )
F_222 ( & V_28 -> V_334 ) ;
}
static void F_357 ( struct V_221 * V_154 )
{
struct V_27 * V_28 = V_154 -> V_214 ;
unsigned long V_70 ;
F_65 ( & V_28 -> V_22 -> V_17 , V_70 ) ;
F_358 ( & V_28 -> V_62 ) ;
F_66 ( & V_28 -> V_22 -> V_17 , V_70 ) ;
F_359 () ;
F_210 ( V_28 ) ;
F_226 ( & V_28 -> V_334 ) ;
F_288 ( & V_59 . V_60 ) ;
F_285 ( V_28 -> V_22 ) ;
F_360 ( V_28 -> V_2 ) ;
F_289 ( V_154 , V_28 -> V_37 ) ;
if ( V_28 -> V_85 )
F_289 ( V_154 , V_28 -> V_85 ) ;
F_267 ( V_28 ) ;
F_290 ( & V_59 . V_60 ) ;
}
static int F_361 ( struct V_221 * V_154 , unsigned V_270 , char * * V_281 )
{
int V_40 ;
struct V_27 * V_28 ;
struct V_135 * V_37 , * V_85 ;
struct V_63 * V_66 ;
unsigned long V_70 ;
F_288 ( & V_59 . V_60 ) ;
if ( V_270 != 2 && V_270 != 3 ) {
V_154 -> error = L_52 ;
V_40 = - V_150 ;
goto V_284;
}
V_28 = V_154 -> V_214 = F_307 ( sizeof( * V_28 ) , V_250 ) ;
if ( ! V_28 ) {
V_154 -> error = L_110 ;
V_40 = - V_127 ;
goto V_284;
}
V_28 -> V_303 = F_308 ( V_154 -> V_155 ) ;
F_280 ( & V_28 -> V_17 ) ;
F_50 ( & V_28 -> V_73 ) ;
F_61 ( & V_28 -> V_74 ) ;
F_61 ( & V_28 -> V_75 ) ;
V_28 -> V_180 = V_335 ;
if ( V_270 == 3 ) {
V_40 = F_304 ( V_154 , V_281 [ 2 ] , V_285 , & V_85 ) ;
if ( V_40 ) {
V_154 -> error = L_111 ;
goto V_336;
}
V_28 -> V_85 = V_85 ;
}
V_40 = F_304 ( V_154 , V_281 [ 0 ] , F_362 ( V_154 -> V_155 ) , & V_37 ) ;
if ( V_40 ) {
V_154 -> error = L_112 ;
goto V_337;
}
V_28 -> V_37 = V_37 ;
if ( F_330 ( V_281 [ 1 ] , ( unsigned long long * ) & V_28 -> V_307 , 0 ) ) {
V_154 -> error = L_113 ;
V_40 = - V_150 ;
goto V_338;
}
V_66 = F_363 ( V_28 -> V_37 -> V_38 -> V_327 ) ;
if ( ! V_66 ) {
V_154 -> error = L_114 ;
V_40 = - V_150 ;
goto V_338;
}
V_28 -> V_22 = F_56 ( V_66 ) ;
if ( ! V_28 -> V_22 ) {
V_154 -> error = L_115 ;
V_40 = - V_150 ;
goto V_339;
}
F_284 ( V_28 -> V_22 ) ;
if ( F_146 ( V_28 -> V_22 ) == V_159 ) {
V_154 -> error = L_116 ;
V_40 = - V_150 ;
goto V_251;
}
V_40 = F_364 ( V_28 -> V_22 -> V_116 , V_28 -> V_307 , & V_28 -> V_2 ) ;
if ( V_40 ) {
V_154 -> error = L_117 ;
goto V_251;
}
V_40 = F_365 ( V_154 , V_28 -> V_22 -> V_24 ) ;
if ( V_40 )
goto V_340;
V_154 -> V_292 = 1 ;
V_154 -> V_341 = true ;
V_154 -> V_342 = sizeof( struct V_89 ) ;
V_154 -> V_293 = true ;
if ( V_28 -> V_22 -> V_141 . V_244 ) {
V_154 -> V_295 = true ;
V_154 -> V_294 = 1 ;
V_154 -> V_343 = false ;
}
F_290 ( & V_59 . V_60 ) ;
F_65 ( & V_28 -> V_22 -> V_17 , V_70 ) ;
if ( V_28 -> V_22 -> V_258 ) {
F_66 ( & V_28 -> V_22 -> V_17 , V_70 ) ;
F_288 ( & V_59 . V_60 ) ;
V_154 -> error = L_118 ;
V_40 = - V_150 ;
goto V_340;
}
F_138 ( & V_28 -> V_333 , 1 ) ;
F_225 ( & V_28 -> V_334 ) ;
F_366 ( & V_28 -> V_62 , & V_28 -> V_22 -> V_195 ) ;
F_66 ( & V_28 -> V_22 -> V_17 , V_70 ) ;
F_359 () ;
F_367 ( V_66 ) ;
return 0 ;
V_340:
F_360 ( V_28 -> V_2 ) ;
V_251:
F_285 ( V_28 -> V_22 ) ;
V_339:
F_367 ( V_66 ) ;
V_338:
F_289 ( V_154 , V_28 -> V_37 ) ;
V_337:
if ( V_28 -> V_85 )
F_289 ( V_154 , V_28 -> V_85 ) ;
V_336:
F_267 ( V_28 ) ;
V_284:
F_290 ( & V_59 . V_60 ) ;
return V_40 ;
}
static int F_368 ( struct V_221 * V_154 , struct V_29 * V_29 )
{
V_29 -> V_77 . V_78 = F_369 ( V_154 , V_29 -> V_77 . V_78 ) ;
return F_245 ( V_154 , V_29 ) ;
}
static int F_370 ( struct V_221 * V_154 , struct V_29 * V_29 , int V_100 )
{
unsigned long V_70 ;
struct V_89 * V_90 = F_85 ( V_29 , sizeof( struct V_89 ) ) ;
struct V_71 V_304 ;
struct V_94 * V_95 , * V_65 ;
struct V_22 * V_22 = V_90 -> V_28 -> V_22 ;
if ( V_90 -> V_169 ) {
F_50 ( & V_304 ) ;
F_371 ( V_90 -> V_169 , & V_304 ) ;
F_65 ( & V_22 -> V_17 , V_70 ) ;
F_69 (m, tmp, &work, list) {
F_55 ( & V_95 -> V_62 ) ;
F_94 ( V_95 ) ;
}
F_66 ( & V_22 -> V_17 , V_70 ) ;
}
if ( V_90 -> V_91 ) {
F_50 ( & V_304 ) ;
F_371 ( V_90 -> V_91 , & V_304 ) ;
if ( ! F_203 ( & V_304 ) ) {
F_65 ( & V_22 -> V_17 , V_70 ) ;
F_69 (m, tmp, &work, list)
F_96 ( & V_95 -> V_62 , & V_22 -> V_200 ) ;
F_66 ( & V_22 -> V_17 , V_70 ) ;
F_29 ( V_22 ) ;
}
}
if ( V_90 -> V_50 )
F_100 ( V_90 -> V_28 , V_90 -> V_50 ) ;
return 0 ;
}
static void F_372 ( struct V_221 * V_154 )
{
struct V_27 * V_28 = V_154 -> V_214 ;
if ( F_373 ( V_154 ) )
V_206 ( V_28 , F_228 ) ;
}
static void F_374 ( struct V_221 * V_154 )
{
struct V_27 * V_28 = V_154 -> V_214 ;
V_206 ( V_28 , F_229 ) ;
}
static int F_375 ( struct V_221 * V_154 )
{
struct V_27 * V_28 = V_154 -> V_214 ;
if ( V_28 -> V_85 )
V_28 -> V_145 = F_295 ( V_28 -> V_85 -> V_38 ) ;
return 0 ;
}
static void F_376 ( struct V_221 * V_154 , T_8 type ,
unsigned V_316 , char * V_156 , unsigned V_315 )
{
int V_40 ;
T_11 V_314 = 0 ;
T_1 V_344 , V_345 ;
char V_240 [ V_241 ] ;
struct V_27 * V_28 = V_154 -> V_214 ;
if ( F_146 ( V_28 -> V_22 ) == V_159 ) {
F_345 ( L_92 ) ;
return;
}
if ( ! V_28 -> V_2 )
F_345 ( L_119 ) ;
else {
switch ( type ) {
case V_324 :
V_40 = F_377 ( V_28 -> V_2 , & V_344 ) ;
if ( V_40 ) {
F_236 ( L_120 , V_40 ) ;
goto V_100;
}
V_40 = F_378 ( V_28 -> V_2 , & V_345 ) ;
if ( V_40 < 0 ) {
F_236 ( L_121 , V_40 ) ;
goto V_100;
}
F_345 ( L_100 , V_344 * V_28 -> V_22 -> V_24 ) ;
if ( V_40 )
F_345 ( L_122 , ( ( V_345 + 1 ) *
V_28 -> V_22 -> V_24 ) - 1 ) ;
else
F_345 ( L_119 ) ;
break;
case V_326 :
F_345 ( L_123 ,
F_351 ( V_240 , V_28 -> V_37 -> V_38 -> V_327 ) ,
( unsigned long ) V_28 -> V_307 ) ;
if ( V_28 -> V_85 )
F_345 ( L_124 , F_351 ( V_240 , V_28 -> V_85 -> V_38 -> V_327 ) ) ;
break;
}
}
return;
V_100:
F_345 ( L_109 ) ;
}
static int F_379 ( struct V_221 * V_154 ,
T_10 F_38 , void * V_328 )
{
T_2 V_346 ;
struct V_27 * V_28 = V_154 -> V_214 ;
struct V_22 * V_22 = V_28 -> V_22 ;
if ( ! V_22 -> V_154 )
return 0 ;
V_346 = V_22 -> V_154 -> V_36 ;
( void ) F_77 ( V_346 , V_22 -> V_24 ) ;
if ( V_346 )
return F_38 ( V_154 , V_28 -> V_37 , 0 , V_22 -> V_24 * V_346 , V_328 ) ;
return 0 ;
}
static void F_380 ( struct V_221 * V_154 , struct V_236 * V_238 )
{
struct V_27 * V_28 = V_154 -> V_214 ;
struct V_22 * V_22 = V_28 -> V_22 ;
if ( ! V_22 -> V_141 . V_244 )
return;
V_238 -> V_332 = V_22 -> V_24 << V_82 ;
V_238 -> V_242 = 2048 * 1024 * 16 ;
}
static int T_12 F_381 ( void )
{
int V_40 ;
F_48 () ;
V_40 = F_382 ( & V_347 ) ;
if ( V_40 )
return V_40 ;
V_40 = F_382 ( & V_348 ) ;
if ( V_40 )
goto V_349;
V_40 = - V_127 ;
V_262 = F_383 ( V_94 , 0 ) ;
if ( ! V_262 )
goto V_350;
return 0 ;
V_350:
F_384 ( & V_348 ) ;
V_349:
F_384 ( & V_347 ) ;
return V_40 ;
}
static void F_385 ( void )
{
F_384 ( & V_347 ) ;
F_384 ( & V_348 ) ;
F_386 ( V_262 ) ;
}
