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
V_26 -> V_32 -> V_42 = F_28 ( V_40 ) ;
F_29 ( V_26 -> V_32 ) ;
}
static void F_30 ( struct V_22 * V_22 )
{
F_31 ( V_22 -> V_43 , & V_22 -> V_44 ) ;
}
static int F_32 ( struct V_22 * V_22 , struct V_7 * V_8 , struct V_29 * V_29 ,
struct V_45 * * V_46 )
{
int V_40 ;
struct V_45 * V_47 ;
V_47 = F_33 ( V_22 -> V_48 , V_49 ) ;
V_40 = F_34 ( V_22 -> V_48 , V_8 , V_29 , V_47 , V_46 ) ;
if ( V_40 )
F_35 ( V_22 -> V_48 , V_47 ) ;
return V_40 ;
}
static void F_36 ( struct V_22 * V_22 ,
struct V_45 * V_50 ,
struct V_51 * V_52 )
{
F_37 ( V_22 -> V_48 , V_50 , V_52 ) ;
F_35 ( V_22 -> V_48 , V_50 ) ;
}
static void F_38 ( struct V_22 * V_22 ,
void (* F_39)( void * , struct V_45 * ) ,
void * V_53 ,
struct V_45 * V_50 )
{
F_40 ( V_22 -> V_48 , F_39 , V_53 , V_50 ) ;
F_35 ( V_22 -> V_48 , V_50 ) ;
}
static void F_41 ( struct V_22 * V_22 ,
struct V_45 * V_50 ,
struct V_51 * V_52 )
{
F_42 ( V_22 -> V_48 , V_50 , V_52 ) ;
F_35 ( V_22 -> V_48 , V_50 ) ;
}
static void F_43 ( struct V_22 * V_22 ,
struct V_45 * V_50 , T_3 V_54 )
{
F_44 ( V_22 -> V_48 , V_50 , V_54 ) ;
F_35 ( V_22 -> V_48 , V_50 ) ;
}
static T_3 F_45 ( struct V_22 * V_22 )
{
return V_22 -> V_55 ? V_56 : V_57 ;
}
static void F_46 ( struct V_22 * V_22 , struct V_45 * V_50 )
{
F_43 ( V_22 , V_50 , F_45 ( V_22 ) ) ;
}
static void F_47 ( struct V_22 * V_22 , struct V_45 * V_50 )
{
F_43 ( V_22 , V_50 , 0 ) ;
}
static void F_48 ( struct V_22 * V_22 , struct V_45 * V_50 )
{
F_43 ( V_22 , V_50 , V_58 ) ;
}
static void F_49 ( void )
{
F_50 ( & V_59 . V_60 ) ;
F_51 ( & V_59 . V_61 ) ;
}
static void F_52 ( struct V_22 * V_22 )
{
F_19 ( ! F_53 ( & V_59 . V_60 ) ) ;
F_54 ( & V_22 -> V_62 , & V_59 . V_61 ) ;
}
static void F_55 ( struct V_22 * V_22 )
{
F_19 ( ! F_53 ( & V_59 . V_60 ) ) ;
F_56 ( & V_22 -> V_62 ) ;
}
static struct V_22 * F_57 ( struct V_63 * V_64 )
{
struct V_22 * V_22 = NULL , * V_65 ;
F_19 ( ! F_53 ( & V_59 . V_60 ) ) ;
F_58 (tmp, &dm_thin_pool_table.pools, list) {
if ( V_65 -> V_66 == V_64 ) {
V_22 = V_65 ;
break;
}
}
return V_22 ;
}
static struct V_22 * F_59 ( struct V_67 * V_68 )
{
struct V_22 * V_22 = NULL , * V_65 ;
F_19 ( ! F_53 ( & V_59 . V_60 ) ) ;
F_58 (tmp, &dm_thin_pool_table.pools, list) {
if ( V_65 -> V_68 == V_68 ) {
V_22 = V_65 ;
break;
}
}
return V_22 ;
}
static void F_60 ( struct V_51 * V_52 , struct V_51 * V_69 )
{
F_61 ( V_52 , V_69 ) ;
F_62 ( V_69 ) ;
}
static void F_63 ( struct V_51 * V_52 , T_3 error )
{
struct V_29 * V_29 ;
while ( ( V_29 = F_64 ( V_52 ) ) ) {
V_29 -> V_42 = error ;
F_29 ( V_29 ) ;
}
}
static void F_65 ( struct V_27 * V_28 , struct V_51 * V_69 ,
T_3 error )
{
struct V_51 V_52 ;
unsigned long V_70 ;
F_62 ( & V_52 ) ;
F_66 ( & V_28 -> V_17 , V_70 ) ;
F_60 ( & V_52 , V_69 ) ;
F_67 ( & V_28 -> V_17 , V_70 ) ;
F_63 ( & V_52 , error ) ;
}
static void F_68 ( struct V_27 * V_28 )
{
struct V_22 * V_22 = V_28 -> V_22 ;
unsigned long V_70 ;
struct V_71 V_72 ;
struct V_45 * V_50 , * V_65 ;
F_51 ( & V_72 ) ;
F_66 ( & V_28 -> V_17 , V_70 ) ;
F_69 ( & V_28 -> V_73 , & V_72 ) ;
F_67 ( & V_28 -> V_17 , V_70 ) ;
F_70 (cell, tmp, &cells, user_list)
F_48 ( V_22 , V_50 ) ;
}
static void F_71 ( struct V_27 * V_28 )
{
struct V_51 V_52 ;
unsigned long V_70 ;
F_62 ( & V_52 ) ;
F_66 ( & V_28 -> V_17 , V_70 ) ;
F_60 ( & V_52 , & V_28 -> V_74 ) ;
F_60 ( & V_52 , & V_28 -> V_75 ) ;
F_67 ( & V_28 -> V_17 , V_70 ) ;
F_63 ( & V_52 , V_58 ) ;
F_68 ( V_28 ) ;
}
static void F_72 ( struct V_22 * V_22 , T_3 error )
{
struct V_27 * V_28 ;
F_73 () ;
F_74 (tc, &pool->active_thins, list)
F_65 ( V_28 , & V_28 -> V_75 , error ) ;
F_75 () ;
}
static void F_76 ( struct V_22 * V_22 )
{
F_72 ( V_22 , F_45 ( V_22 ) ) ;
}
static T_1 F_77 ( struct V_27 * V_28 , struct V_29 * V_29 )
{
struct V_22 * V_22 = V_28 -> V_22 ;
T_2 V_76 = V_29 -> V_77 . V_78 ;
if ( F_16 ( V_22 ) )
V_76 >>= V_22 -> V_23 ;
else
( void ) F_78 ( V_76 , V_22 -> V_24 ) ;
return V_76 ;
}
static void F_79 ( struct V_27 * V_28 , struct V_29 * V_29 ,
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
( void ) F_78 ( V_5 , V_22 -> V_24 ) ;
( void ) F_78 ( V_6 , V_22 -> V_24 ) ;
}
if ( V_6 < V_5 )
V_6 = V_5 ;
* V_79 = V_5 ;
* V_80 = V_6 ;
}
static void F_80 ( struct V_27 * V_28 , struct V_29 * V_29 , T_1 V_83 )
{
struct V_22 * V_22 = V_28 -> V_22 ;
T_2 V_78 = V_29 -> V_77 . V_78 ;
F_81 ( V_29 , V_28 -> V_37 -> V_38 ) ;
if ( F_16 ( V_22 ) )
V_29 -> V_77 . V_78 =
( V_83 << V_22 -> V_23 ) |
( V_78 & ( V_22 -> V_24 - 1 ) ) ;
else
V_29 -> V_77 . V_78 = ( V_83 * V_22 -> V_24 ) +
F_78 ( V_78 , V_22 -> V_24 ) ;
}
static void F_82 ( struct V_27 * V_28 , struct V_29 * V_29 )
{
F_81 ( V_29 , V_28 -> V_84 -> V_38 ) ;
}
static int F_83 ( struct V_27 * V_28 , struct V_29 * V_29 )
{
return F_84 ( V_29 -> V_85 ) &&
F_85 ( V_28 -> V_2 ) ;
}
static void F_86 ( struct V_22 * V_22 , struct V_29 * V_29 )
{
struct V_86 * V_87 ;
if ( F_87 ( V_29 ) == V_41 )
return;
V_87 = F_88 ( V_29 , sizeof( struct V_86 ) ) ;
V_87 -> V_88 = F_89 ( V_22 -> V_89 ) ;
}
static void F_90 ( struct V_27 * V_28 , struct V_29 * V_29 )
{
struct V_22 * V_22 = V_28 -> V_22 ;
unsigned long V_70 ;
if ( ! F_83 ( V_28 , V_29 ) ) {
F_91 ( V_29 ) ;
return;
}
if ( F_92 ( V_28 -> V_2 ) ) {
F_93 ( V_29 ) ;
return;
}
F_66 ( & V_22 -> V_17 , V_70 ) ;
F_94 ( & V_22 -> V_90 , V_29 ) ;
F_67 ( & V_22 -> V_17 , V_70 ) ;
}
static void F_95 ( struct V_27 * V_28 , struct V_29 * V_29 )
{
F_82 ( V_28 , V_29 ) ;
F_90 ( V_28 , V_29 ) ;
}
static void F_96 ( struct V_27 * V_28 , struct V_29 * V_29 ,
T_1 V_83 )
{
F_80 ( V_28 , V_29 , V_83 ) ;
F_90 ( V_28 , V_29 ) ;
}
static void F_97 ( struct V_91 * V_92 )
{
struct V_22 * V_22 = V_92 -> V_28 -> V_22 ;
if ( F_98 ( & V_92 -> V_93 ) ) {
F_99 ( & V_92 -> V_62 , & V_22 -> V_94 ) ;
F_30 ( V_22 ) ;
}
}
static void F_100 ( struct V_91 * V_92 )
{
unsigned long V_70 ;
struct V_22 * V_22 = V_92 -> V_28 -> V_22 ;
F_66 ( & V_22 -> V_17 , V_70 ) ;
F_97 ( V_92 ) ;
F_67 ( & V_22 -> V_17 , V_70 ) ;
}
static void F_101 ( int V_95 , unsigned long V_96 , void * V_53 )
{
struct V_91 * V_92 = V_53 ;
V_92 -> V_97 = V_95 || V_96 ? V_57 : 0 ;
F_100 ( V_92 ) ;
}
static void F_102 ( struct V_29 * V_29 )
{
struct V_86 * V_87 = F_88 ( V_29 , sizeof( struct V_86 ) ) ;
struct V_91 * V_92 = V_87 -> V_98 ;
V_29 -> V_99 = V_92 -> V_100 ;
V_92 -> V_97 = V_29 -> V_42 ;
F_100 ( V_92 ) ;
}
static void F_103 ( struct V_27 * V_28 , struct V_45 * V_50 )
{
struct V_22 * V_22 = V_28 -> V_22 ;
unsigned long V_70 ;
F_66 ( & V_28 -> V_17 , V_70 ) ;
F_41 ( V_22 , V_50 , & V_28 -> V_74 ) ;
F_67 ( & V_28 -> V_17 , V_70 ) ;
F_30 ( V_22 ) ;
}
static void F_104 ( void * V_53 ,
struct V_45 * V_50 )
{
struct V_101 * V_102 = V_53 ;
struct V_29 * V_29 ;
while ( ( V_29 = F_64 ( & V_50 -> V_52 ) ) ) {
if ( F_84 ( V_29 -> V_85 ) || F_87 ( V_29 ) == V_41 )
F_94 ( & V_102 -> V_103 , V_29 ) ;
else {
F_86 ( V_102 -> V_28 -> V_22 , V_29 ) ;
F_94 ( & V_102 -> V_104 , V_29 ) ;
}
}
}
static void F_105 ( struct V_27 * V_28 ,
struct V_45 * V_50 ,
T_1 V_83 )
{
struct V_29 * V_29 ;
struct V_101 V_102 ;
V_102 . V_28 = V_28 ;
F_62 ( & V_102 . V_103 ) ;
F_62 ( & V_102 . V_104 ) ;
F_38 ( V_28 -> V_22 , F_104 ,
& V_102 , V_50 ) ;
while ( ( V_29 = F_64 ( & V_102 . V_103 ) ) )
F_106 ( V_28 , V_29 ) ;
while ( ( V_29 = F_64 ( & V_102 . V_104 ) ) )
F_96 ( V_102 . V_28 , V_29 , V_83 ) ;
}
static void F_107 ( struct V_91 * V_92 )
{
F_46 ( V_92 -> V_28 -> V_22 , V_92 -> V_50 ) ;
F_56 ( & V_92 -> V_62 ) ;
F_108 ( V_92 , V_92 -> V_28 -> V_22 -> V_105 ) ;
}
static void F_109 ( struct V_91 * V_92 )
{
struct V_27 * V_28 = V_92 -> V_28 ;
struct V_22 * V_22 = V_28 -> V_22 ;
struct V_29 * V_29 = V_92 -> V_29 ;
int V_40 ;
if ( V_92 -> V_97 ) {
F_46 ( V_22 , V_92 -> V_50 ) ;
goto V_106;
}
V_40 = F_110 ( V_28 -> V_2 , V_92 -> V_107 , V_92 -> V_108 ) ;
if ( V_40 ) {
F_111 ( V_22 , L_1 , V_40 ) ;
F_46 ( V_22 , V_92 -> V_50 ) ;
goto V_106;
}
if ( V_29 ) {
F_105 ( V_28 , V_92 -> V_50 , V_92 -> V_108 ) ;
F_29 ( V_29 ) ;
} else {
F_86 ( V_28 -> V_22 , V_92 -> V_50 -> V_109 ) ;
F_96 ( V_28 , V_92 -> V_50 -> V_109 , V_92 -> V_108 ) ;
F_105 ( V_28 , V_92 -> V_50 , V_92 -> V_108 ) ;
}
V_106:
F_56 ( & V_92 -> V_62 ) ;
F_108 ( V_92 , V_22 -> V_105 ) ;
}
static void F_112 ( struct V_91 * V_92 )
{
struct V_27 * V_28 = V_92 -> V_28 ;
if ( V_92 -> V_50 )
F_103 ( V_28 , V_92 -> V_50 ) ;
F_108 ( V_92 , V_28 -> V_22 -> V_105 ) ;
}
static void F_113 ( struct V_91 * V_92 )
{
F_93 ( V_92 -> V_29 ) ;
F_112 ( V_92 ) ;
}
static void F_114 ( struct V_91 * V_92 )
{
F_29 ( V_92 -> V_29 ) ;
F_112 ( V_92 ) ;
}
static void F_115 ( struct V_91 * V_92 )
{
int V_40 ;
struct V_27 * V_28 = V_92 -> V_28 ;
V_40 = F_116 ( V_28 -> V_2 , V_92 -> V_50 -> V_8 . V_12 , V_92 -> V_50 -> V_8 . V_13 ) ;
if ( V_40 ) {
F_111 ( V_28 -> V_22 , L_2 , V_40 ) ;
F_93 ( V_92 -> V_29 ) ;
} else
F_29 ( V_92 -> V_29 ) ;
F_103 ( V_28 , V_92 -> V_50 ) ;
F_108 ( V_92 , V_28 -> V_22 -> V_105 ) ;
}
static void F_117 ( struct V_91 * V_92 ,
struct V_29 * V_110 )
{
int V_40 = 0 ;
bool V_111 = true ;
struct V_27 * V_28 = V_92 -> V_28 ;
struct V_22 * V_22 = V_28 -> V_22 ;
T_1 V_5 = V_92 -> V_108 , V_6 , V_80 = V_92 -> V_108 + V_92 -> V_112 - V_92 -> V_107 ;
struct V_25 V_26 ;
F_18 ( & V_26 , V_28 , V_110 ) ;
while ( V_5 != V_80 ) {
for (; V_5 < V_80 ; V_5 ++ ) {
V_40 = F_118 ( V_22 -> V_113 , V_5 , & V_111 ) ;
if ( V_40 )
goto V_106;
if ( ! V_111 )
break;
}
if ( V_5 == V_80 )
break;
for ( V_6 = V_5 + 1 ; V_6 != V_80 ; V_6 ++ ) {
V_40 = F_118 ( V_22 -> V_113 , V_6 , & V_111 ) ;
if ( V_40 )
goto V_106;
if ( V_111 )
break;
}
V_40 = F_21 ( & V_26 , V_5 , V_6 ) ;
if ( V_40 )
goto V_106;
V_5 = V_6 ;
}
V_106:
F_23 ( & V_26 , V_40 ) ;
}
static void F_119 ( struct V_91 * V_92 )
{
unsigned long V_70 ;
struct V_22 * V_22 = V_92 -> V_28 -> V_22 ;
F_66 ( & V_22 -> V_17 , V_70 ) ;
F_99 ( & V_92 -> V_62 , & V_22 -> V_114 ) ;
F_67 ( & V_22 -> V_17 , V_70 ) ;
F_30 ( V_22 ) ;
}
static void F_120 ( struct V_29 * V_29 )
{
F_119 ( V_29 -> V_115 ) ;
F_121 ( V_29 ) ;
}
static void F_122 ( struct V_91 * V_92 )
{
int V_40 ;
struct V_27 * V_28 = V_92 -> V_28 ;
struct V_22 * V_22 = V_28 -> V_22 ;
struct V_29 * V_110 ;
T_1 V_116 = V_92 -> V_108 + ( V_92 -> V_112 - V_92 -> V_107 ) ;
V_40 = F_116 ( V_28 -> V_2 , V_92 -> V_107 , V_92 -> V_112 ) ;
if ( V_40 ) {
F_111 ( V_22 , L_2 , V_40 ) ;
F_93 ( V_92 -> V_29 ) ;
F_103 ( V_28 , V_92 -> V_50 ) ;
F_108 ( V_92 , V_22 -> V_105 ) ;
return;
}
V_40 = F_123 ( V_22 -> V_113 , V_92 -> V_108 , V_116 ) ;
if ( V_40 ) {
F_111 ( V_22 , L_3 , V_40 ) ;
F_93 ( V_92 -> V_29 ) ;
F_103 ( V_28 , V_92 -> V_50 ) ;
F_108 ( V_92 , V_22 -> V_105 ) ;
return;
}
V_110 = F_124 ( V_49 , 1 ) ;
if ( ! V_110 ) {
F_125 ( L_4 ,
F_126 ( V_28 -> V_22 -> V_66 ) ) ;
F_119 ( V_92 ) ;
} else {
V_110 -> V_99 = F_120 ;
V_110 -> V_115 = V_92 ;
if ( V_92 -> V_117 )
F_117 ( V_92 , V_110 ) ;
else {
struct V_25 V_26 ;
F_18 ( & V_26 , V_28 , V_110 ) ;
V_40 = F_21 ( & V_26 , V_92 -> V_108 , V_116 ) ;
F_23 ( & V_26 , V_40 ) ;
}
}
}
static void F_127 ( struct V_91 * V_92 )
{
int V_40 ;
struct V_27 * V_28 = V_92 -> V_28 ;
struct V_22 * V_22 = V_28 -> V_22 ;
V_40 = F_128 ( V_22 -> V_113 , V_92 -> V_108 ,
V_92 -> V_108 + ( V_92 -> V_112 - V_92 -> V_107 ) ) ;
if ( V_40 ) {
F_111 ( V_22 , L_5 , V_40 ) ;
F_93 ( V_92 -> V_29 ) ;
} else
F_29 ( V_92 -> V_29 ) ;
F_103 ( V_28 , V_92 -> V_50 ) ;
F_108 ( V_92 , V_22 -> V_105 ) ;
}
static void F_129 ( struct V_22 * V_22 , struct V_71 * V_118 ,
T_4 * F_39 )
{
unsigned long V_70 ;
struct V_71 V_119 ;
struct V_91 * V_92 , * V_65 ;
F_51 ( & V_119 ) ;
F_66 ( & V_22 -> V_17 , V_70 ) ;
F_69 ( V_118 , & V_119 ) ;
F_67 ( & V_22 -> V_17 , V_70 ) ;
F_70 ( V_92 , V_65 , & V_119 , V_62 )
( * F_39 ) ( V_92 ) ;
}
static int F_130 ( struct V_22 * V_22 , struct V_29 * V_29 )
{
return V_29 -> V_77 . V_81 ==
( V_22 -> V_24 << V_82 ) ;
}
static int F_131 ( struct V_22 * V_22 , struct V_29 * V_29 )
{
return ( F_132 ( V_29 ) == V_120 ) &&
F_130 ( V_22 , V_29 ) ;
}
static void F_133 ( struct V_29 * V_29 , T_5 * * V_121 ,
T_5 * F_39 )
{
* V_121 = V_29 -> V_99 ;
V_29 -> V_99 = F_39 ;
}
static int F_134 ( struct V_22 * V_22 )
{
if ( V_22 -> V_122 )
return 0 ;
V_22 -> V_122 = F_135 ( V_22 -> V_105 , V_123 ) ;
return V_22 -> V_122 ? 0 : - V_124 ;
}
static struct V_91 * F_136 ( struct V_22 * V_22 )
{
struct V_91 * V_92 = V_22 -> V_122 ;
F_19 ( ! V_22 -> V_122 ) ;
memset ( V_92 , 0 , sizeof( struct V_91 ) ) ;
F_51 ( & V_92 -> V_62 ) ;
V_92 -> V_29 = NULL ;
V_22 -> V_122 = NULL ;
return V_92 ;
}
static void F_137 ( struct V_27 * V_28 , struct V_91 * V_92 ,
T_2 V_79 , T_2 V_80 )
{
int V_40 ;
struct V_125 V_126 ;
V_126 . V_38 = V_28 -> V_37 -> V_38 ;
V_126 . V_127 = V_79 ;
V_126 . V_128 = V_80 - V_79 ;
V_40 = F_138 ( V_28 -> V_22 -> V_129 , 1 , & V_126 , 0 , F_101 , V_92 ) ;
if ( V_40 < 0 ) {
F_139 ( L_6 ) ;
F_101 ( 1 , 1 , V_92 ) ;
}
}
static void F_140 ( struct V_27 * V_28 , struct V_29 * V_29 ,
T_1 V_130 ,
struct V_91 * V_92 )
{
struct V_22 * V_22 = V_28 -> V_22 ;
struct V_86 * V_87 = F_88 ( V_29 , sizeof( struct V_86 ) ) ;
V_87 -> V_98 = V_92 ;
V_92 -> V_29 = V_29 ;
F_133 ( V_29 , & V_92 -> V_100 , F_102 ) ;
F_86 ( V_22 , V_29 ) ;
F_96 ( V_28 , V_29 , V_130 ) ;
}
static void F_141 ( struct V_27 * V_28 , T_1 V_131 ,
struct V_132 * V_133 , T_1 V_134 ,
T_1 V_135 ,
struct V_45 * V_50 , struct V_29 * V_29 ,
T_2 V_36 )
{
int V_40 ;
struct V_22 * V_22 = V_28 -> V_22 ;
struct V_91 * V_92 = F_136 ( V_22 ) ;
V_92 -> V_28 = V_28 ;
V_92 -> V_107 = V_131 ;
V_92 -> V_112 = V_131 + 1u ;
V_92 -> V_108 = V_135 ;
V_92 -> V_50 = V_50 ;
F_142 ( & V_92 -> V_93 , 3 ) ;
if ( ! F_143 ( V_22 -> V_136 , & V_92 -> V_62 ) )
F_100 ( V_92 ) ;
if ( F_131 ( V_22 , V_29 ) )
F_140 ( V_28 , V_29 , V_135 , V_92 ) ;
else {
struct V_125 V_137 , V_126 ;
V_137 . V_38 = V_133 -> V_38 ;
V_137 . V_127 = V_134 * V_22 -> V_24 ;
V_137 . V_128 = V_36 ;
V_126 . V_38 = V_28 -> V_37 -> V_38 ;
V_126 . V_127 = V_135 * V_22 -> V_24 ;
V_126 . V_128 = V_36 ;
V_40 = F_144 ( V_22 -> V_129 , & V_137 , 1 , & V_126 ,
0 , F_101 , V_92 ) ;
if ( V_40 < 0 ) {
F_139 ( L_7 ) ;
F_101 ( 1 , 1 , V_92 ) ;
}
if ( V_36 < V_22 -> V_24 && V_22 -> V_138 . V_139 ) {
F_145 ( & V_92 -> V_93 ) ;
F_137 ( V_28 , V_92 ,
V_135 * V_22 -> V_24 + V_36 ,
( V_135 + 1 ) * V_22 -> V_24 ) ;
}
}
F_100 ( V_92 ) ;
}
static void F_146 ( struct V_27 * V_28 , T_1 V_131 ,
T_1 V_134 , T_1 V_135 ,
struct V_45 * V_50 , struct V_29 * V_29 )
{
F_141 ( V_28 , V_131 , V_28 -> V_37 ,
V_134 , V_135 , V_50 , V_29 ,
V_28 -> V_22 -> V_24 ) ;
}
static void F_147 ( struct V_27 * V_28 , T_1 V_131 ,
T_1 V_108 , struct V_45 * V_50 ,
struct V_29 * V_29 )
{
struct V_22 * V_22 = V_28 -> V_22 ;
struct V_91 * V_92 = F_136 ( V_22 ) ;
F_142 ( & V_92 -> V_93 , 1 ) ;
V_92 -> V_28 = V_28 ;
V_92 -> V_107 = V_131 ;
V_92 -> V_112 = V_131 + 1u ;
V_92 -> V_108 = V_108 ;
V_92 -> V_50 = V_50 ;
if ( V_22 -> V_138 . V_139 ) {
if ( F_131 ( V_22 , V_29 ) )
F_140 ( V_28 , V_29 , V_108 , V_92 ) ;
else
F_137 ( V_28 , V_92 , V_108 * V_22 -> V_24 ,
( V_108 + 1 ) * V_22 -> V_24 ) ;
} else
F_109 ( V_92 ) ;
}
static void F_148 ( struct V_27 * V_28 , T_1 V_131 ,
T_1 V_135 ,
struct V_45 * V_50 , struct V_29 * V_29 )
{
struct V_22 * V_22 = V_28 -> V_22 ;
T_2 V_140 = V_131 * V_22 -> V_24 ;
T_2 V_141 = ( V_131 + 1 ) * V_22 -> V_24 ;
if ( V_141 <= V_28 -> V_142 )
F_141 ( V_28 , V_131 , V_28 -> V_84 ,
V_131 , V_135 , V_50 , V_29 ,
V_22 -> V_24 ) ;
else if ( V_140 < V_28 -> V_142 )
F_141 ( V_28 , V_131 , V_28 -> V_84 ,
V_131 , V_135 , V_50 , V_29 ,
V_28 -> V_142 - V_140 ) ;
else
F_147 ( V_28 , V_131 , V_135 , V_50 , V_29 ) ;
}
static void F_149 ( struct V_22 * V_22 )
{
int V_40 ;
T_1 V_143 ;
if ( F_150 ( V_22 ) != V_144 )
return;
V_40 = F_151 ( V_22 -> V_113 , & V_143 ) ;
if ( V_40 )
return;
if ( V_143 )
F_152 ( V_22 , V_145 ) ;
}
static int F_153 ( struct V_22 * V_22 )
{
int V_40 ;
if ( F_150 ( V_22 ) >= V_146 )
return - V_147 ;
V_40 = F_154 ( V_22 -> V_113 ) ;
if ( V_40 )
F_111 ( V_22 , L_8 , V_40 ) ;
else
F_149 ( V_22 ) ;
return V_40 ;
}
static void F_155 ( struct V_22 * V_22 , T_1 V_148 )
{
unsigned long V_70 ;
if ( V_148 <= V_22 -> V_149 && ! V_22 -> V_150 ) {
F_125 ( L_9 ,
F_126 ( V_22 -> V_66 ) ) ;
F_66 ( & V_22 -> V_17 , V_70 ) ;
V_22 -> V_150 = true ;
F_67 ( & V_22 -> V_17 , V_70 ) ;
F_156 ( V_22 -> V_151 -> V_152 ) ;
}
}
static int F_157 ( struct V_27 * V_28 , T_1 * V_153 )
{
int V_40 ;
T_1 V_148 ;
struct V_22 * V_22 = V_28 -> V_22 ;
if ( F_158 ( F_150 ( V_22 ) != V_145 ) )
return - V_147 ;
V_40 = F_151 ( V_22 -> V_113 , & V_148 ) ;
if ( V_40 ) {
F_111 ( V_22 , L_10 , V_40 ) ;
return V_40 ;
}
F_155 ( V_22 , V_148 ) ;
if ( ! V_148 ) {
V_40 = F_153 ( V_22 ) ;
if ( V_40 )
return V_40 ;
V_40 = F_151 ( V_22 -> V_113 , & V_148 ) ;
if ( V_40 ) {
F_111 ( V_22 , L_10 , V_40 ) ;
return V_40 ;
}
if ( ! V_148 ) {
F_152 ( V_22 , V_144 ) ;
return - V_154 ;
}
}
V_40 = F_159 ( V_22 -> V_113 , V_153 ) ;
if ( V_40 ) {
F_111 ( V_22 , L_11 , V_40 ) ;
return V_40 ;
}
return 0 ;
}
static void F_160 ( struct V_29 * V_29 )
{
struct V_86 * V_87 = F_88 ( V_29 , sizeof( struct V_86 ) ) ;
struct V_27 * V_28 = V_87 -> V_28 ;
unsigned long V_70 ;
F_66 ( & V_28 -> V_17 , V_70 ) ;
F_94 ( & V_28 -> V_75 , V_29 ) ;
F_67 ( & V_28 -> V_17 , V_70 ) ;
}
static T_3 F_161 ( struct V_22 * V_22 )
{
enum V_155 V_92 = F_150 ( V_22 ) ;
switch ( V_92 ) {
case V_145 :
F_139 ( L_12 ) ;
return V_57 ;
case V_144 :
return V_22 -> V_138 . V_156 ? V_56 : 0 ;
case V_146 :
case V_157 :
return V_57 ;
default:
F_139 ( L_13 ) ;
return V_57 ;
}
}
static void F_162 ( struct V_22 * V_22 , struct V_29 * V_29 )
{
T_3 error = F_161 ( V_22 ) ;
if ( error ) {
V_29 -> V_42 = error ;
F_29 ( V_29 ) ;
} else
F_160 ( V_29 ) ;
}
static void F_163 ( struct V_22 * V_22 , struct V_45 * V_50 )
{
struct V_29 * V_29 ;
struct V_51 V_52 ;
T_3 error ;
error = F_161 ( V_22 ) ;
if ( error ) {
F_43 ( V_22 , V_50 , error ) ;
return;
}
F_62 ( & V_52 ) ;
F_36 ( V_22 , V_50 , & V_52 ) ;
while ( ( V_29 = F_64 ( & V_52 ) ) )
F_160 ( V_29 ) ;
}
static void F_164 ( struct V_27 * V_28 ,
struct V_45 * V_158 )
{
struct V_22 * V_22 = V_28 -> V_22 ;
struct V_91 * V_92 = F_136 ( V_22 ) ;
V_92 -> V_28 = V_28 ;
V_92 -> V_107 = V_158 -> V_8 . V_12 ;
V_92 -> V_112 = V_158 -> V_8 . V_13 ;
V_92 -> V_50 = V_158 ;
V_92 -> V_29 = V_158 -> V_109 ;
if ( ! F_143 ( V_22 -> V_89 , & V_92 -> V_62 ) )
V_22 -> V_159 ( V_92 ) ;
}
static void F_165 ( struct V_27 * V_28 , T_1 V_79 , T_1 V_80 ,
struct V_29 * V_29 )
{
struct V_22 * V_22 = V_28 -> V_22 ;
int V_40 ;
bool V_117 ;
struct V_7 V_160 ;
struct V_45 * V_161 ;
struct V_91 * V_92 ;
T_1 V_107 , V_112 , V_130 ;
while ( V_79 != V_80 ) {
V_40 = F_134 ( V_22 ) ;
if ( V_40 )
return;
V_40 = F_166 ( V_28 -> V_2 , V_79 , V_80 , & V_107 , & V_112 ,
& V_130 , & V_117 ) ;
if ( V_40 )
break;
F_1 ( V_28 -> V_2 , V_14 , V_130 , V_130 + ( V_112 - V_107 ) , & V_160 ) ;
if ( F_32 ( V_28 -> V_22 , & V_160 , NULL , & V_161 ) ) {
V_79 = V_112 ;
continue;
}
V_92 = F_136 ( V_22 ) ;
V_92 -> V_28 = V_28 ;
V_92 -> V_117 = V_117 ;
V_92 -> V_107 = V_107 ;
V_92 -> V_112 = V_112 ;
V_92 -> V_108 = V_130 ;
V_92 -> V_50 = V_161 ;
V_92 -> V_29 = V_29 ;
F_167 ( V_29 ) ;
if ( ! F_143 ( V_22 -> V_89 , & V_92 -> V_62 ) )
V_22 -> V_159 ( V_92 ) ;
V_79 = V_112 ;
}
}
static void F_168 ( struct V_27 * V_28 , struct V_45 * V_158 )
{
struct V_29 * V_29 = V_158 -> V_109 ;
struct V_86 * V_87 = F_88 ( V_29 , sizeof( struct V_86 ) ) ;
V_87 -> V_50 = V_158 ;
F_165 ( V_28 , V_158 -> V_8 . V_12 , V_158 -> V_8 . V_13 , V_29 ) ;
F_29 ( V_29 ) ;
}
static void F_169 ( struct V_27 * V_28 , struct V_29 * V_29 )
{
T_1 V_79 , V_80 ;
struct V_7 V_162 ;
struct V_45 * V_158 ;
F_79 ( V_28 , V_29 , & V_79 , & V_80 ) ;
if ( V_79 == V_80 ) {
F_29 ( V_29 ) ;
return;
}
F_1 ( V_28 -> V_2 , V_10 , V_79 , V_80 , & V_162 ) ;
if ( F_32 ( V_28 -> V_22 , & V_162 , V_29 , & V_158 ) )
return;
V_28 -> V_22 -> V_163 ( V_28 , V_158 ) ;
}
static void F_170 ( struct V_27 * V_28 , struct V_29 * V_29 , T_1 V_83 ,
struct V_7 * V_8 ,
struct V_164 * V_165 ,
struct V_45 * V_50 )
{
int V_40 ;
T_1 V_108 ;
struct V_22 * V_22 = V_28 -> V_22 ;
V_40 = F_157 ( V_28 , & V_108 ) ;
switch ( V_40 ) {
case 0 :
F_146 ( V_28 , V_83 , V_165 -> V_83 ,
V_108 , V_50 , V_29 ) ;
break;
case - V_154 :
F_163 ( V_22 , V_50 ) ;
break;
default:
F_139 ( L_14 ,
V_166 , V_40 ) ;
F_46 ( V_22 , V_50 ) ;
break;
}
}
static void F_171 ( void * V_53 ,
struct V_45 * V_50 )
{
struct V_101 * V_102 = V_53 ;
struct V_29 * V_29 ;
while ( ( V_29 = F_64 ( & V_50 -> V_52 ) ) ) {
if ( F_132 ( V_29 ) == V_120 || F_84 ( V_29 -> V_85 ) ||
F_87 ( V_29 ) == V_41 )
F_94 ( & V_102 -> V_103 , V_29 ) ;
else {
struct V_86 * V_87 = F_88 ( V_29 , sizeof( struct V_86 ) ) ; ;
V_87 -> V_167 = F_89 ( V_102 -> V_28 -> V_22 -> V_136 ) ;
F_86 ( V_102 -> V_28 -> V_22 , V_29 ) ;
F_94 ( & V_102 -> V_104 , V_29 ) ;
}
}
}
static void F_172 ( struct V_27 * V_28 ,
struct V_45 * V_50 ,
T_1 V_83 )
{
struct V_29 * V_29 ;
struct V_101 V_102 ;
V_102 . V_28 = V_28 ;
F_62 ( & V_102 . V_103 ) ;
F_62 ( & V_102 . V_104 ) ;
F_38 ( V_28 -> V_22 , F_171 ,
& V_102 , V_50 ) ;
while ( ( V_29 = F_64 ( & V_102 . V_103 ) ) )
F_106 ( V_28 , V_29 ) ;
while ( ( V_29 = F_64 ( & V_102 . V_104 ) ) )
F_96 ( V_28 , V_29 , V_83 ) ;
}
static void F_173 ( struct V_27 * V_28 , struct V_29 * V_29 ,
T_1 V_83 ,
struct V_164 * V_165 ,
struct V_45 * V_158 )
{
struct V_45 * V_161 ;
struct V_22 * V_22 = V_28 -> V_22 ;
struct V_7 V_8 ;
F_3 ( V_28 -> V_2 , V_165 -> V_83 , & V_8 ) ;
if ( F_32 ( V_22 , & V_8 , V_29 , & V_161 ) ) {
F_103 ( V_28 , V_158 ) ;
return;
}
if ( F_132 ( V_29 ) == V_120 && V_29 -> V_77 . V_81 ) {
F_170 ( V_28 , V_29 , V_83 , & V_8 , V_165 , V_161 ) ;
F_103 ( V_28 , V_158 ) ;
} else {
struct V_86 * V_87 = F_88 ( V_29 , sizeof( struct V_86 ) ) ;
V_87 -> V_167 = F_89 ( V_22 -> V_136 ) ;
F_86 ( V_22 , V_29 ) ;
F_96 ( V_28 , V_29 , V_165 -> V_83 ) ;
F_172 ( V_28 , V_161 , V_165 -> V_83 ) ;
F_172 ( V_28 , V_158 , V_165 -> V_83 ) ;
}
}
static void F_174 ( struct V_27 * V_28 , struct V_29 * V_29 , T_1 V_83 ,
struct V_45 * V_50 )
{
int V_40 ;
T_1 V_108 ;
struct V_22 * V_22 = V_28 -> V_22 ;
if ( ! V_29 -> V_77 . V_81 ) {
F_86 ( V_22 , V_29 ) ;
F_103 ( V_28 , V_50 ) ;
F_96 ( V_28 , V_29 , 0 ) ;
return;
}
if ( F_132 ( V_29 ) == V_168 ) {
F_175 ( V_29 ) ;
F_103 ( V_28 , V_50 ) ;
F_29 ( V_29 ) ;
return;
}
V_40 = F_157 ( V_28 , & V_108 ) ;
switch ( V_40 ) {
case 0 :
if ( V_28 -> V_84 )
F_148 ( V_28 , V_83 , V_108 , V_50 , V_29 ) ;
else
F_147 ( V_28 , V_83 , V_108 , V_50 , V_29 ) ;
break;
case - V_154 :
F_163 ( V_22 , V_50 ) ;
break;
default:
F_139 ( L_14 ,
V_166 , V_40 ) ;
F_46 ( V_22 , V_50 ) ;
break;
}
}
static void F_176 ( struct V_27 * V_28 , struct V_45 * V_50 )
{
int V_40 ;
struct V_22 * V_22 = V_28 -> V_22 ;
struct V_29 * V_29 = V_50 -> V_109 ;
T_1 V_83 = F_77 ( V_28 , V_29 ) ;
struct V_164 V_165 ;
if ( V_28 -> V_169 ) {
F_48 ( V_22 , V_50 ) ;
return;
}
V_40 = F_177 ( V_28 -> V_2 , V_83 , 1 , & V_165 ) ;
switch ( V_40 ) {
case 0 :
if ( V_165 . V_170 )
F_173 ( V_28 , V_29 , V_83 , & V_165 , V_50 ) ;
else {
F_86 ( V_22 , V_29 ) ;
F_96 ( V_28 , V_29 , V_165 . V_83 ) ;
F_105 ( V_28 , V_50 , V_165 . V_83 ) ;
}
break;
case - V_171 :
if ( F_132 ( V_29 ) == V_168 && V_28 -> V_84 ) {
F_86 ( V_22 , V_29 ) ;
F_103 ( V_28 , V_50 ) ;
if ( F_178 ( V_29 ) <= V_28 -> V_142 )
F_95 ( V_28 , V_29 ) ;
else if ( V_29 -> V_77 . V_78 < V_28 -> V_142 ) {
F_175 ( V_29 ) ;
V_29 -> V_77 . V_81 = ( V_28 -> V_142 - V_29 -> V_77 . V_78 ) << V_82 ;
F_95 ( V_28 , V_29 ) ;
} else {
F_175 ( V_29 ) ;
F_29 ( V_29 ) ;
}
} else
F_174 ( V_28 , V_29 , V_83 , V_50 ) ;
break;
default:
F_139 ( L_15 ,
V_166 , V_40 ) ;
F_103 ( V_28 , V_50 ) ;
F_93 ( V_29 ) ;
break;
}
}
static void F_179 ( struct V_27 * V_28 , struct V_29 * V_29 )
{
struct V_22 * V_22 = V_28 -> V_22 ;
T_1 V_83 = F_77 ( V_28 , V_29 ) ;
struct V_45 * V_50 ;
struct V_7 V_8 ;
F_4 ( V_28 -> V_2 , V_83 , & V_8 ) ;
if ( F_32 ( V_22 , & V_8 , V_29 , & V_50 ) )
return;
F_176 ( V_28 , V_50 ) ;
}
static void F_180 ( struct V_27 * V_28 , struct V_29 * V_29 ,
struct V_45 * V_50 )
{
int V_40 ;
int V_172 = F_132 ( V_29 ) ;
T_1 V_83 = F_77 ( V_28 , V_29 ) ;
struct V_164 V_165 ;
V_40 = F_177 ( V_28 -> V_2 , V_83 , 1 , & V_165 ) ;
switch ( V_40 ) {
case 0 :
if ( V_165 . V_170 && ( V_172 == V_120 ) && V_29 -> V_77 . V_81 ) {
F_162 ( V_28 -> V_22 , V_29 ) ;
if ( V_50 )
F_103 ( V_28 , V_50 ) ;
} else {
F_86 ( V_28 -> V_22 , V_29 ) ;
F_96 ( V_28 , V_29 , V_165 . V_83 ) ;
if ( V_50 )
F_105 ( V_28 , V_50 , V_165 . V_83 ) ;
}
break;
case - V_171 :
if ( V_50 )
F_103 ( V_28 , V_50 ) ;
if ( V_172 != V_168 ) {
F_162 ( V_28 -> V_22 , V_29 ) ;
break;
}
if ( V_28 -> V_84 ) {
F_86 ( V_28 -> V_22 , V_29 ) ;
F_95 ( V_28 , V_29 ) ;
break;
}
F_175 ( V_29 ) ;
F_29 ( V_29 ) ;
break;
default:
F_139 ( L_15 ,
V_166 , V_40 ) ;
if ( V_50 )
F_103 ( V_28 , V_50 ) ;
F_93 ( V_29 ) ;
break;
}
}
static void F_181 ( struct V_27 * V_28 , struct V_29 * V_29 )
{
F_180 ( V_28 , V_29 , NULL ) ;
}
static void F_182 ( struct V_27 * V_28 , struct V_45 * V_50 )
{
F_180 ( V_28 , V_50 -> V_109 , V_50 ) ;
}
static void F_183 ( struct V_27 * V_28 , struct V_29 * V_29 )
{
F_29 ( V_29 ) ;
}
static void F_184 ( struct V_27 * V_28 , struct V_29 * V_29 )
{
F_93 ( V_29 ) ;
}
static void F_185 ( struct V_27 * V_28 , struct V_45 * V_50 )
{
F_47 ( V_28 -> V_22 , V_50 ) ;
}
static void F_186 ( struct V_27 * V_28 , struct V_45 * V_50 )
{
F_46 ( V_28 -> V_22 , V_50 ) ;
}
static int F_187 ( struct V_22 * V_22 )
{
return ! F_188 ( V_20 , V_22 -> V_173 ,
V_22 -> V_173 + V_174 ) ;
}
static void F_189 ( struct V_27 * V_28 , struct V_29 * V_29 )
{
struct V_175 * * V_176 , * V_30 ;
struct V_86 * V_177 ;
T_2 V_78 = V_29 -> V_77 . V_78 ;
V_176 = & V_28 -> V_178 . V_175 ;
V_30 = NULL ;
while ( * V_176 ) {
V_30 = * V_176 ;
V_177 = F_190 ( V_30 ) ;
if ( V_78 < F_191 ( V_177 ) -> V_77 . V_78 )
V_176 = & ( * V_176 ) -> V_179 ;
else
V_176 = & ( * V_176 ) -> V_180 ;
}
V_177 = F_88 ( V_29 , sizeof( struct V_86 ) ) ;
F_192 ( & V_177 -> V_175 , V_30 , V_176 ) ;
F_193 ( & V_177 -> V_175 , & V_28 -> V_178 ) ;
}
static void F_194 ( struct V_27 * V_28 )
{
struct V_175 * V_181 ;
struct V_86 * V_177 ;
struct V_29 * V_29 ;
for ( V_181 = F_195 ( & V_28 -> V_178 ) ; V_181 ; V_181 = F_196 ( V_181 ) ) {
V_177 = F_190 ( V_181 ) ;
V_29 = F_191 ( V_177 ) ;
F_94 ( & V_28 -> V_74 , V_29 ) ;
F_197 ( & V_177 -> V_175 , & V_28 -> V_178 ) ;
}
F_158 ( ! F_198 ( & V_28 -> V_178 ) ) ;
}
static void F_199 ( struct V_27 * V_28 )
{
struct V_29 * V_29 ;
struct V_51 V_52 ;
F_62 ( & V_52 ) ;
F_61 ( & V_52 , & V_28 -> V_74 ) ;
F_62 ( & V_28 -> V_74 ) ;
while ( ( V_29 = F_64 ( & V_52 ) ) )
F_189 ( V_28 , V_29 ) ;
F_194 ( V_28 ) ;
}
static void F_200 ( struct V_27 * V_28 )
{
struct V_22 * V_22 = V_28 -> V_22 ;
unsigned long V_70 ;
struct V_29 * V_29 ;
struct V_51 V_52 ;
struct V_182 V_31 ;
unsigned V_128 = 0 ;
if ( V_28 -> V_169 ) {
F_65 ( V_28 , & V_28 -> V_74 ,
V_58 ) ;
return;
}
F_62 ( & V_52 ) ;
F_66 ( & V_28 -> V_17 , V_70 ) ;
if ( F_201 ( & V_28 -> V_74 ) ) {
F_67 ( & V_28 -> V_17 , V_70 ) ;
return;
}
F_199 ( V_28 ) ;
F_61 ( & V_52 , & V_28 -> V_74 ) ;
F_62 ( & V_28 -> V_74 ) ;
F_67 ( & V_28 -> V_17 , V_70 ) ;
F_20 ( & V_31 ) ;
while ( ( V_29 = F_64 ( & V_52 ) ) ) {
if ( F_134 ( V_22 ) ) {
F_66 ( & V_28 -> V_17 , V_70 ) ;
F_94 ( & V_28 -> V_74 , V_29 ) ;
F_61 ( & V_28 -> V_74 , & V_52 ) ;
F_67 ( & V_28 -> V_17 , V_70 ) ;
break;
}
if ( F_87 ( V_29 ) == V_41 )
V_22 -> V_183 ( V_28 , V_29 ) ;
else
V_22 -> F_179 ( V_28 , V_29 ) ;
if ( ( V_128 ++ & 127 ) == 0 ) {
F_8 ( & V_22 -> V_15 ) ;
F_202 ( V_22 -> V_113 ) ;
}
}
F_27 ( & V_31 ) ;
}
static int F_203 ( const void * V_184 , const void * V_185 )
{
struct V_45 * V_186 = * ( (struct V_45 * * ) V_184 ) ;
struct V_45 * V_187 = * ( (struct V_45 * * ) V_185 ) ;
F_19 ( ! V_186 -> V_109 ) ;
F_19 ( ! V_187 -> V_109 ) ;
if ( V_186 -> V_109 -> V_77 . V_78 < V_187 -> V_109 -> V_77 . V_78 )
return - 1 ;
if ( V_186 -> V_109 -> V_77 . V_78 > V_187 -> V_109 -> V_77 . V_78 )
return 1 ;
return 0 ;
}
static unsigned F_204 ( struct V_22 * V_22 , struct V_71 * V_72 )
{
unsigned V_128 = 0 ;
struct V_45 * V_50 , * V_65 ;
F_70 (cell, tmp, cells, user_list) {
if ( V_128 >= V_188 )
break;
V_22 -> V_189 [ V_128 ++ ] = V_50 ;
F_56 ( & V_50 -> V_190 ) ;
}
F_205 ( V_22 -> V_189 , V_128 , sizeof( V_50 ) , F_203 , NULL ) ;
return V_128 ;
}
static void F_206 ( struct V_27 * V_28 )
{
struct V_22 * V_22 = V_28 -> V_22 ;
unsigned long V_70 ;
struct V_71 V_72 ;
struct V_45 * V_50 ;
unsigned V_191 , V_192 , V_128 ;
F_51 ( & V_72 ) ;
F_66 ( & V_28 -> V_17 , V_70 ) ;
F_69 ( & V_28 -> V_73 , & V_72 ) ;
F_67 ( & V_28 -> V_17 , V_70 ) ;
if ( F_207 ( & V_72 ) )
return;
do {
V_128 = F_204 ( V_28 -> V_22 , & V_72 ) ;
for ( V_191 = 0 ; V_191 < V_128 ; V_191 ++ ) {
V_50 = V_22 -> V_189 [ V_191 ] ;
F_19 ( ! V_50 -> V_109 ) ;
if ( F_134 ( V_22 ) ) {
for ( V_192 = V_191 ; V_192 < V_128 ; V_192 ++ )
F_54 ( & V_22 -> V_189 [ V_192 ] -> V_190 , & V_72 ) ;
F_66 ( & V_28 -> V_17 , V_70 ) ;
F_208 ( & V_72 , & V_28 -> V_73 ) ;
F_67 ( & V_28 -> V_17 , V_70 ) ;
return;
}
if ( F_87 ( V_50 -> V_109 ) == V_41 )
V_22 -> V_163 ( V_28 , V_50 ) ;
else
V_22 -> F_176 ( V_28 , V_50 ) ;
}
} while ( ! F_207 ( & V_72 ) );
}
static struct V_27 * F_209 ( struct V_22 * V_22 )
{
struct V_27 * V_28 = NULL ;
F_73 () ;
if ( ! F_207 ( & V_22 -> V_193 ) ) {
V_28 = F_210 ( V_22 -> V_193 . V_194 , struct V_27 , V_62 ) ;
F_211 ( V_28 ) ;
}
F_75 () ;
return V_28 ;
}
static struct V_27 * F_212 ( struct V_22 * V_22 , struct V_27 * V_28 )
{
struct V_27 * V_195 = V_28 ;
F_73 () ;
F_213 (tc, &pool->active_thins, list) {
F_211 ( V_28 ) ;
F_214 ( V_195 ) ;
F_75 () ;
return V_28 ;
}
F_214 ( V_195 ) ;
F_75 () ;
return NULL ;
}
static void F_215 ( struct V_22 * V_22 )
{
unsigned long V_70 ;
struct V_29 * V_29 ;
struct V_51 V_52 ;
struct V_27 * V_28 ;
V_28 = F_209 ( V_22 ) ;
while ( V_28 ) {
F_206 ( V_28 ) ;
F_200 ( V_28 ) ;
V_28 = F_212 ( V_22 , V_28 ) ;
}
F_62 ( & V_52 ) ;
F_66 ( & V_22 -> V_17 , V_70 ) ;
F_61 ( & V_52 , & V_22 -> V_90 ) ;
F_62 ( & V_22 -> V_90 ) ;
F_67 ( & V_22 -> V_17 , V_70 ) ;
if ( F_201 ( & V_52 ) &&
! ( F_216 ( V_22 -> V_113 ) && F_187 ( V_22 ) ) )
return;
if ( F_153 ( V_22 ) ) {
while ( ( V_29 = F_64 ( & V_52 ) ) )
F_93 ( V_29 ) ;
return;
}
V_22 -> V_173 = V_20 ;
while ( ( V_29 = F_64 ( & V_52 ) ) )
F_91 ( V_29 ) ;
}
static void F_217 ( struct V_196 * V_197 )
{
struct V_22 * V_22 = F_218 ( V_197 , struct V_22 , V_44 ) ;
F_7 ( & V_22 -> V_15 ) ;
F_202 ( V_22 -> V_113 ) ;
F_8 ( & V_22 -> V_15 ) ;
F_129 ( V_22 , & V_22 -> V_94 , & V_22 -> F_109 ) ;
F_8 ( & V_22 -> V_15 ) ;
F_129 ( V_22 , & V_22 -> V_198 , & V_22 -> V_159 ) ;
F_8 ( & V_22 -> V_15 ) ;
F_129 ( V_22 , & V_22 -> V_114 , & V_22 -> V_199 ) ;
F_8 ( & V_22 -> V_15 ) ;
F_215 ( V_22 ) ;
F_10 ( & V_22 -> V_15 ) ;
}
static void F_219 ( struct V_196 * V_197 )
{
struct V_22 * V_22 = F_218 ( F_220 ( V_197 ) , struct V_22 , V_200 ) ;
F_30 ( V_22 ) ;
F_221 ( V_22 -> V_43 , & V_22 -> V_200 , V_174 ) ;
}
static void F_222 ( struct V_196 * V_197 )
{
struct V_22 * V_22 = F_218 ( F_220 ( V_197 ) , struct V_22 ,
V_201 ) ;
if ( F_150 ( V_22 ) == V_144 && ! V_22 -> V_138 . V_156 ) {
V_22 -> V_138 . V_156 = true ;
F_223 ( V_22 ) ;
F_72 ( V_22 , V_56 ) ;
}
}
static struct V_202 * F_224 ( struct V_196 * V_197 )
{
return F_218 ( V_197 , struct V_202 , V_44 ) ;
}
static void F_225 ( struct V_202 * V_203 )
{
F_226 ( & V_203 -> F_226 ) ;
}
static void F_227 ( struct V_202 * V_203 , struct V_22 * V_22 ,
void (* F_39)( struct V_196 * ) )
{
F_228 ( & V_203 -> V_44 , F_39 ) ;
F_229 ( & V_203 -> F_226 ) ;
F_31 ( V_22 -> V_43 , & V_203 -> V_44 ) ;
F_230 ( & V_203 -> F_226 ) ;
}
static struct V_204 * F_231 ( struct V_196 * V_197 )
{
return F_218 ( F_224 ( V_197 ) , struct V_204 , V_203 ) ;
}
static void F_232 ( struct V_196 * V_197 )
{
struct V_204 * V_205 = F_231 ( V_197 ) ;
V_205 -> V_28 -> V_169 = true ;
F_71 ( V_205 -> V_28 ) ;
F_225 ( & V_205 -> V_203 ) ;
}
static void F_233 ( struct V_196 * V_197 )
{
struct V_204 * V_205 = F_231 ( V_197 ) ;
V_205 -> V_28 -> V_169 = false ;
F_225 ( & V_205 -> V_203 ) ;
}
static void V_204 ( struct V_27 * V_28 , void (* F_39)( struct V_196 * ) )
{
struct V_204 V_205 ;
V_205 . V_28 = V_28 ;
F_227 ( & V_205 . V_203 , V_28 -> V_22 , F_39 ) ;
}
static enum V_155 F_150 ( struct V_22 * V_22 )
{
return V_22 -> V_138 . V_206 ;
}
static void F_234 ( struct V_22 * V_22 , const char * V_207 )
{
F_156 ( V_22 -> V_151 -> V_152 ) ;
F_235 ( L_16 ,
F_126 ( V_22 -> V_66 ) , V_207 ) ;
}
static void F_223 ( struct V_22 * V_22 )
{
if ( ! V_22 -> V_138 . V_156 )
F_234 ( V_22 , L_17 ) ;
else
F_234 ( V_22 , L_18 ) ;
}
static bool F_236 ( struct V_208 * V_209 )
{
return V_209 -> V_210 . V_211 ;
}
static void F_237 ( struct V_22 * V_22 )
{
struct V_208 * V_209 = V_22 -> V_151 -> V_212 ;
if ( F_236 ( V_209 ) ) {
V_22 -> V_163 = F_168 ;
V_22 -> V_159 = F_122 ;
V_22 -> V_199 = F_127 ;
} else {
V_22 -> V_163 = F_164 ;
V_22 -> V_159 = F_115 ;
}
}
static void F_152 ( struct V_22 * V_22 , enum V_155 V_207 )
{
struct V_208 * V_209 = V_22 -> V_151 -> V_212 ;
bool V_213 = F_238 ( V_22 -> V_113 ) ;
enum V_155 V_214 = F_150 ( V_22 ) ;
unsigned long V_201 = F_239 ( V_215 ) * V_216 ;
if ( V_207 == V_145 && V_213 ) {
F_240 ( L_19 ,
F_126 ( V_22 -> V_66 ) ) ;
if ( V_214 != V_207 )
V_207 = V_214 ;
else
V_207 = V_146 ;
}
if ( V_214 == V_157 )
V_207 = V_214 ;
switch ( V_207 ) {
case V_157 :
if ( V_214 != V_207 )
F_234 ( V_22 , L_20 ) ;
F_241 ( V_22 -> V_113 ) ;
V_22 -> F_179 = F_184 ;
V_22 -> V_183 = F_184 ;
V_22 -> F_176 = F_186 ;
V_22 -> V_163 = F_186 ;
V_22 -> F_109 = F_107 ;
V_22 -> V_159 = F_113 ;
F_76 ( V_22 ) ;
break;
case V_146 :
if ( V_214 != V_207 )
F_234 ( V_22 , L_21 ) ;
F_241 ( V_22 -> V_113 ) ;
V_22 -> F_179 = F_181 ;
V_22 -> V_183 = F_183 ;
V_22 -> F_176 = F_182 ;
V_22 -> V_163 = F_185 ;
V_22 -> F_109 = F_107 ;
V_22 -> V_159 = F_114 ;
F_76 ( V_22 ) ;
break;
case V_144 :
if ( V_214 != V_207 )
F_223 ( V_22 ) ;
V_22 -> V_55 = true ;
V_22 -> F_179 = F_181 ;
V_22 -> V_183 = F_169 ;
V_22 -> F_176 = F_182 ;
V_22 -> F_109 = F_109 ;
F_237 ( V_22 ) ;
if ( ! V_22 -> V_138 . V_156 && V_201 )
F_221 ( V_22 -> V_43 , & V_22 -> V_201 , V_201 ) ;
break;
case V_145 :
if ( V_214 != V_207 )
F_234 ( V_22 , L_22 ) ;
V_22 -> V_55 = false ;
V_22 -> V_138 . V_156 = V_209 -> V_217 . V_156 ;
F_242 ( V_22 -> V_113 ) ;
V_22 -> F_179 = F_179 ;
V_22 -> V_183 = F_169 ;
V_22 -> F_176 = F_176 ;
V_22 -> F_109 = F_109 ;
F_237 ( V_22 ) ;
break;
}
V_22 -> V_138 . V_206 = V_207 ;
V_209 -> V_210 . V_206 = V_207 ;
}
static void F_243 ( struct V_22 * V_22 )
{
const char * V_218 = F_126 ( V_22 -> V_66 ) ;
F_139 ( L_23 , V_218 ) ;
if ( F_244 ( V_22 -> V_113 ) ) {
F_240 ( L_24 , V_218 ) ;
F_152 ( V_22 , V_157 ) ;
}
if ( F_245 ( V_22 -> V_113 ) ) {
F_240 ( L_25 , V_218 ) ;
F_152 ( V_22 , V_157 ) ;
}
}
static void F_111 ( struct V_22 * V_22 , const char * V_26 , int V_40 )
{
F_139 ( L_26 ,
F_126 ( V_22 -> V_66 ) , V_26 , V_40 ) ;
F_243 ( V_22 ) ;
F_152 ( V_22 , V_146 ) ;
}
static void F_106 ( struct V_27 * V_28 , struct V_29 * V_29 )
{
unsigned long V_70 ;
struct V_22 * V_22 = V_28 -> V_22 ;
F_66 ( & V_28 -> V_17 , V_70 ) ;
F_94 ( & V_28 -> V_74 , V_29 ) ;
F_67 ( & V_28 -> V_17 , V_70 ) ;
F_30 ( V_22 ) ;
}
static void F_246 ( struct V_27 * V_28 , struct V_29 * V_29 )
{
struct V_22 * V_22 = V_28 -> V_22 ;
F_12 ( & V_22 -> V_15 ) ;
F_106 ( V_28 , V_29 ) ;
F_14 ( & V_22 -> V_15 ) ;
}
static void F_247 ( struct V_27 * V_28 , struct V_45 * V_50 )
{
unsigned long V_70 ;
struct V_22 * V_22 = V_28 -> V_22 ;
F_12 ( & V_22 -> V_15 ) ;
F_66 ( & V_28 -> V_17 , V_70 ) ;
F_99 ( & V_50 -> V_190 , & V_28 -> V_73 ) ;
F_67 ( & V_28 -> V_17 , V_70 ) ;
F_14 ( & V_22 -> V_15 ) ;
F_30 ( V_22 ) ;
}
static void F_248 ( struct V_27 * V_28 , struct V_29 * V_29 )
{
struct V_86 * V_87 = F_88 ( V_29 , sizeof( struct V_86 ) ) ;
V_87 -> V_28 = V_28 ;
V_87 -> V_167 = NULL ;
V_87 -> V_88 = NULL ;
V_87 -> V_98 = NULL ;
V_87 -> V_50 = NULL ;
}
static int F_249 ( struct V_219 * V_151 , struct V_29 * V_29 )
{
int V_40 ;
struct V_27 * V_28 = V_151 -> V_212 ;
T_1 V_83 = F_77 ( V_28 , V_29 ) ;
struct V_1 * V_2 = V_28 -> V_2 ;
struct V_164 V_153 ;
struct V_45 * V_158 , * V_161 ;
struct V_7 V_8 ;
F_248 ( V_28 , V_29 ) ;
if ( V_28 -> V_169 ) {
V_29 -> V_42 = V_58 ;
F_29 ( V_29 ) ;
return V_220 ;
}
if ( F_150 ( V_28 -> V_22 ) == V_157 ) {
F_93 ( V_29 ) ;
return V_220 ;
}
if ( F_84 ( V_29 -> V_85 ) || F_87 ( V_29 ) == V_41 ) {
F_246 ( V_28 , V_29 ) ;
return V_220 ;
}
F_4 ( V_28 -> V_2 , V_83 , & V_8 ) ;
if ( F_32 ( V_28 -> V_22 , & V_8 , V_29 , & V_158 ) )
return V_220 ;
V_40 = F_177 ( V_2 , V_83 , 0 , & V_153 ) ;
switch ( V_40 ) {
case 0 :
if ( F_250 ( V_153 . V_170 ) ) {
F_247 ( V_28 , V_158 ) ;
return V_220 ;
}
F_3 ( V_28 -> V_2 , V_153 . V_83 , & V_8 ) ;
if ( F_32 ( V_28 -> V_22 , & V_8 , V_29 , & V_161 ) ) {
F_103 ( V_28 , V_158 ) ;
return V_220 ;
}
F_86 ( V_28 -> V_22 , V_29 ) ;
F_103 ( V_28 , V_161 ) ;
F_103 ( V_28 , V_158 ) ;
F_80 ( V_28 , V_29 , V_153 . V_83 ) ;
return V_221 ;
case - V_171 :
case - V_222 :
F_247 ( V_28 , V_158 ) ;
return V_220 ;
default:
F_93 ( V_29 ) ;
F_103 ( V_28 , V_158 ) ;
return V_220 ;
}
}
static int F_251 ( struct V_223 * V_224 , int V_225 )
{
struct V_208 * V_209 = F_218 ( V_224 , struct V_208 , V_226 ) ;
struct V_227 * V_228 ;
if ( F_150 ( V_209 -> V_22 ) == V_144 )
return 1 ;
V_228 = F_252 ( V_209 -> V_229 -> V_38 ) ;
return F_253 ( V_228 -> V_230 , V_225 ) ;
}
static void F_254 ( struct V_22 * V_22 )
{
unsigned long V_70 ;
struct V_27 * V_28 ;
F_73 () ;
F_74 (tc, &pool->active_thins, list) {
F_66 ( & V_28 -> V_17 , V_70 ) ;
F_61 ( & V_28 -> V_74 , & V_28 -> V_75 ) ;
F_62 ( & V_28 -> V_75 ) ;
F_67 ( & V_28 -> V_17 , V_70 ) ;
}
F_75 () ;
}
static bool F_255 ( struct V_208 * V_209 )
{
struct V_227 * V_228 = F_252 ( V_209 -> V_229 -> V_38 ) ;
return V_228 && F_256 ( V_228 ) ;
}
static bool F_257 ( T_2 V_231 , T_6 V_232 )
{
return ! F_78 ( V_231 , V_232 ) ;
}
static void F_258 ( struct V_208 * V_209 )
{
struct V_22 * V_22 = V_209 -> V_22 ;
struct V_67 * V_233 = V_209 -> V_229 -> V_38 ;
struct V_234 * V_235 = & F_252 ( V_233 ) -> V_236 ;
const char * V_237 = NULL ;
char V_238 [ V_239 ] ;
if ( ! V_209 -> V_210 . V_211 )
return;
if ( ! F_255 ( V_209 ) )
V_237 = L_27 ;
else if ( V_235 -> V_240 < V_22 -> V_24 )
V_237 = L_28 ;
if ( V_237 ) {
F_125 ( L_29 , F_259 ( V_233 , V_238 ) , V_237 ) ;
V_209 -> V_210 . V_211 = false ;
}
}
static int F_260 ( struct V_22 * V_22 , struct V_219 * V_151 )
{
struct V_208 * V_209 = V_151 -> V_212 ;
enum V_155 V_214 = F_150 ( V_22 ) ;
enum V_155 V_207 = V_209 -> V_210 . V_206 ;
V_209 -> V_210 . V_206 = V_214 ;
V_22 -> V_151 = V_151 ;
V_22 -> V_138 = V_209 -> V_210 ;
V_22 -> V_149 = V_209 -> V_149 ;
F_152 ( V_22 , V_207 ) ;
return 0 ;
}
static void F_261 ( struct V_22 * V_22 , struct V_219 * V_151 )
{
if ( V_22 -> V_151 == V_151 )
V_22 -> V_151 = NULL ;
}
static void F_262 ( struct V_241 * V_138 )
{
V_138 -> V_206 = V_145 ;
V_138 -> V_139 = true ;
V_138 -> V_242 = true ;
V_138 -> V_211 = true ;
V_138 -> V_156 = false ;
}
static void F_263 ( struct V_22 * V_22 )
{
F_55 ( V_22 ) ;
F_264 ( V_22 -> V_189 ) ;
if ( F_265 ( V_22 -> V_113 ) < 0 )
F_125 ( L_30 , V_166 ) ;
F_266 ( V_22 -> V_48 ) ;
F_267 ( V_22 -> V_129 ) ;
if ( V_22 -> V_43 )
F_268 ( V_22 -> V_43 ) ;
if ( V_22 -> V_122 )
F_108 ( V_22 -> V_122 , V_22 -> V_105 ) ;
F_269 ( V_22 -> V_105 ) ;
F_270 ( V_22 -> V_136 ) ;
F_270 ( V_22 -> V_89 ) ;
F_271 ( V_22 ) ;
}
static struct V_22 * F_272 ( struct V_63 * V_66 ,
struct V_67 * V_243 ,
unsigned long V_231 ,
int V_244 , char * * error )
{
int V_40 ;
void * V_245 ;
struct V_22 * V_22 ;
struct V_246 * V_113 ;
bool V_247 = V_244 ? false : true ;
V_113 = F_273 ( V_243 , V_231 , V_247 ) ;
if ( F_274 ( V_113 ) ) {
* error = L_31 ;
return (struct V_22 * ) V_113 ;
}
V_22 = F_275 ( sizeof( * V_22 ) , V_248 ) ;
if ( ! V_22 ) {
* error = L_32 ;
V_245 = F_276 ( - V_124 ) ;
goto V_249;
}
V_22 -> V_113 = V_113 ;
V_22 -> V_24 = V_231 ;
if ( V_231 & ( V_231 - 1 ) )
V_22 -> V_23 = - 1 ;
else
V_22 -> V_23 = F_277 ( V_231 ) ;
V_22 -> V_149 = 0 ;
F_262 ( & V_22 -> V_138 ) ;
V_22 -> V_48 = F_278 () ;
if ( ! V_22 -> V_48 ) {
* error = L_33 ;
V_245 = F_276 ( - V_124 ) ;
goto V_250;
}
V_22 -> V_129 = F_279 ( & V_251 ) ;
if ( F_274 ( V_22 -> V_129 ) ) {
V_40 = F_280 ( V_22 -> V_129 ) ;
* error = L_34 ;
V_245 = F_276 ( V_40 ) ;
goto V_252;
}
V_22 -> V_43 = F_281 ( L_35 V_253 , V_254 ) ;
if ( ! V_22 -> V_43 ) {
* error = L_36 ;
V_245 = F_276 ( - V_124 ) ;
goto V_255;
}
F_5 ( & V_22 -> V_15 ) ;
F_282 ( & V_22 -> V_44 , F_217 ) ;
F_283 ( & V_22 -> V_200 , F_219 ) ;
F_283 ( & V_22 -> V_201 , F_222 ) ;
F_284 ( & V_22 -> V_17 ) ;
F_62 ( & V_22 -> V_90 ) ;
F_51 ( & V_22 -> V_94 ) ;
F_51 ( & V_22 -> V_198 ) ;
F_51 ( & V_22 -> V_114 ) ;
F_51 ( & V_22 -> V_193 ) ;
V_22 -> V_150 = false ;
V_22 -> V_256 = true ;
V_22 -> V_55 = false ;
V_22 -> V_136 = F_285 () ;
if ( ! V_22 -> V_136 ) {
* error = L_37 ;
V_245 = F_276 ( - V_124 ) ;
goto V_257;
}
V_22 -> V_89 = F_285 () ;
if ( ! V_22 -> V_89 ) {
* error = L_38 ;
V_245 = F_276 ( - V_124 ) ;
goto V_258;
}
V_22 -> V_122 = NULL ;
V_22 -> V_105 = F_286 ( V_259 ,
V_260 ) ;
if ( ! V_22 -> V_105 ) {
* error = L_39 ;
V_245 = F_276 ( - V_124 ) ;
goto V_261;
}
V_22 -> V_189 = F_287 ( sizeof( * V_22 -> V_189 ) * V_188 ) ;
if ( ! V_22 -> V_189 ) {
* error = L_40 ;
V_245 = F_276 ( - V_124 ) ;
goto V_262;
}
V_22 -> V_263 = 1 ;
V_22 -> V_173 = V_20 ;
V_22 -> V_66 = V_66 ;
V_22 -> V_68 = V_243 ;
F_52 ( V_22 ) ;
return V_22 ;
V_262:
F_269 ( V_22 -> V_105 ) ;
V_261:
F_270 ( V_22 -> V_89 ) ;
V_258:
F_270 ( V_22 -> V_136 ) ;
V_257:
F_268 ( V_22 -> V_43 ) ;
V_255:
F_267 ( V_22 -> V_129 ) ;
V_252:
F_266 ( V_22 -> V_48 ) ;
V_250:
F_271 ( V_22 ) ;
V_249:
if ( F_265 ( V_113 ) )
F_125 ( L_30 , V_166 ) ;
return V_245 ;
}
static void F_288 ( struct V_22 * V_22 )
{
F_19 ( ! F_53 ( & V_59 . V_60 ) ) ;
V_22 -> V_263 ++ ;
}
static void F_289 ( struct V_22 * V_22 )
{
F_19 ( ! F_53 ( & V_59 . V_60 ) ) ;
F_19 ( ! V_22 -> V_263 ) ;
if ( ! -- V_22 -> V_263 )
F_263 ( V_22 ) ;
}
static struct V_22 * F_290 ( struct V_63 * V_66 ,
struct V_67 * V_243 ,
unsigned long V_231 , int V_244 ,
char * * error , int * V_264 )
{
struct V_22 * V_22 = F_59 ( V_243 ) ;
if ( V_22 ) {
if ( V_22 -> V_66 != V_66 ) {
* error = L_41 ;
return F_276 ( - V_265 ) ;
}
F_288 ( V_22 ) ;
} else {
V_22 = F_57 ( V_66 ) ;
if ( V_22 ) {
if ( V_22 -> V_68 != V_243 ) {
* error = L_42 ;
return F_276 ( - V_147 ) ;
}
F_288 ( V_22 ) ;
} else {
V_22 = F_272 ( V_66 , V_243 , V_231 , V_244 , error ) ;
* V_264 = 1 ;
}
}
return V_22 ;
}
static void F_291 ( struct V_219 * V_151 )
{
struct V_208 * V_209 = V_151 -> V_212 ;
F_292 ( & V_59 . V_60 ) ;
F_261 ( V_209 -> V_22 , V_151 ) ;
F_289 ( V_209 -> V_22 ) ;
F_293 ( V_151 , V_209 -> V_243 ) ;
F_293 ( V_151 , V_209 -> V_229 ) ;
F_271 ( V_209 ) ;
F_294 ( & V_59 . V_60 ) ;
}
static int F_295 ( struct V_266 * V_267 , struct V_241 * V_138 ,
struct V_219 * V_151 )
{
int V_40 ;
unsigned V_268 ;
const char * V_269 ;
static const struct V_270 V_271 [] = {
{ 0 , 4 , L_43 } ,
} ;
if ( ! V_267 -> V_268 )
return 0 ;
V_40 = F_296 ( V_271 , V_267 , & V_268 , & V_151 -> error ) ;
if ( V_40 )
return - V_147 ;
while ( V_268 && ! V_40 ) {
V_269 = F_297 ( V_267 ) ;
V_268 -- ;
if ( ! strcasecmp ( V_269 , L_44 ) )
V_138 -> V_139 = false ;
else if ( ! strcasecmp ( V_269 , L_45 ) )
V_138 -> V_242 = false ;
else if ( ! strcasecmp ( V_269 , L_46 ) )
V_138 -> V_211 = false ;
else if ( ! strcasecmp ( V_269 , L_47 ) )
V_138 -> V_206 = V_146 ;
else if ( ! strcasecmp ( V_269 , L_48 ) )
V_138 -> V_156 = true ;
else {
V_151 -> error = L_49 ;
V_40 = - V_147 ;
break;
}
}
return V_40 ;
}
static void F_298 ( void * V_53 )
{
struct V_22 * V_22 = V_53 ;
F_125 ( L_50 ,
F_126 ( V_22 -> V_66 ) ) ;
F_156 ( V_22 -> V_151 -> V_152 ) ;
}
static T_2 F_299 ( struct V_67 * V_38 )
{
return F_300 ( V_38 -> V_272 ) >> V_82 ;
}
static void F_301 ( struct V_67 * V_38 )
{
T_2 V_273 = F_299 ( V_38 ) ;
char V_274 [ V_239 ] ;
if ( V_273 > V_275 )
F_125 ( L_51 ,
F_259 ( V_38 , V_274 ) , V_276 ) ;
}
static T_2 F_302 ( struct V_67 * V_38 )
{
T_2 V_273 = F_299 ( V_38 ) ;
if ( V_273 > V_276 )
V_273 = V_276 ;
return V_273 ;
}
static T_1 F_303 ( struct V_67 * V_38 )
{
T_2 V_273 = F_302 ( V_38 ) ;
F_78 ( V_273 , V_277 ) ;
return V_273 ;
}
static T_1 F_304 ( struct V_208 * V_209 )
{
T_1 V_278 = F_303 ( V_209 -> V_243 -> V_38 ) / 4 ;
return F_305 ( ( T_1 ) 1024ULL , V_278 ) ;
}
static int F_306 ( struct V_219 * V_151 , unsigned V_268 , char * * V_279 )
{
int V_40 , V_280 = 0 ;
struct V_208 * V_209 ;
struct V_22 * V_22 ;
struct V_241 V_138 ;
struct V_266 V_267 ;
struct V_132 * V_229 ;
unsigned long V_231 ;
T_1 V_149 ;
struct V_132 * V_243 ;
T_7 V_281 ;
F_292 ( & V_59 . V_60 ) ;
if ( V_268 < 4 ) {
V_151 -> error = L_52 ;
V_40 = - V_147 ;
goto V_282;
}
V_267 . V_268 = V_268 ;
V_267 . V_279 = V_279 ;
F_262 ( & V_138 ) ;
F_307 ( & V_267 , 4 ) ;
V_40 = F_295 ( & V_267 , & V_138 , V_151 ) ;
if ( V_40 )
goto V_282;
V_281 = V_283 | ( ( V_138 . V_206 == V_146 ) ? 0 : V_284 ) ;
V_40 = F_308 ( V_151 , V_279 [ 0 ] , V_281 , & V_243 ) ;
if ( V_40 ) {
V_151 -> error = L_53 ;
goto V_282;
}
F_301 ( V_243 -> V_38 ) ;
V_40 = F_308 ( V_151 , V_279 [ 1 ] , V_283 | V_284 , & V_229 ) ;
if ( V_40 ) {
V_151 -> error = L_54 ;
goto V_285;
}
if ( F_309 ( V_279 [ 2 ] , 10 , & V_231 ) || ! V_231 ||
V_231 < V_286 ||
V_231 > V_287 ||
V_231 & ( V_286 - 1 ) ) {
V_151 -> error = L_55 ;
V_40 = - V_147 ;
goto V_106;
}
if ( F_310 ( V_279 [ 3 ] , 10 , ( unsigned long long * ) & V_149 ) ) {
V_151 -> error = L_56 ;
V_40 = - V_147 ;
goto V_106;
}
V_209 = F_311 ( sizeof( * V_209 ) , V_248 ) ;
if ( ! V_209 ) {
V_40 = - V_124 ;
goto V_106;
}
V_22 = F_290 ( F_312 ( V_151 -> V_152 ) , V_243 -> V_38 ,
V_231 , V_138 . V_206 == V_146 , & V_151 -> error , & V_280 ) ;
if ( F_274 ( V_22 ) ) {
V_40 = F_280 ( V_22 ) ;
goto V_288;
}
if ( ! V_280 && V_138 . V_242 != V_22 -> V_138 . V_242 ) {
V_151 -> error = L_57 ;
V_40 = - V_147 ;
goto V_289;
}
V_209 -> V_22 = V_22 ;
V_209 -> V_151 = V_151 ;
V_209 -> V_243 = V_243 ;
V_209 -> V_229 = V_229 ;
V_209 -> V_149 = V_149 ;
V_209 -> V_210 = V_209 -> V_217 = V_138 ;
V_151 -> V_290 = 1 ;
if ( V_138 . V_242 && V_138 . V_211 ) {
V_151 -> V_291 = 1 ;
V_151 -> V_292 = true ;
}
V_151 -> V_212 = V_209 ;
V_40 = F_313 ( V_209 -> V_22 -> V_113 ,
F_304 ( V_209 ) ,
F_298 ,
V_22 ) ;
if ( V_40 )
goto V_289;
V_209 -> V_226 . V_293 = F_251 ;
F_314 ( V_151 -> V_152 , & V_209 -> V_226 ) ;
F_294 ( & V_59 . V_60 ) ;
return 0 ;
V_289:
F_289 ( V_22 ) ;
V_288:
F_271 ( V_209 ) ;
V_106:
F_293 ( V_151 , V_229 ) ;
V_285:
F_293 ( V_151 , V_243 ) ;
V_282:
F_294 ( & V_59 . V_60 ) ;
return V_40 ;
}
static int F_315 ( struct V_219 * V_151 , struct V_29 * V_29 )
{
int V_40 ;
struct V_208 * V_209 = V_151 -> V_212 ;
struct V_22 * V_22 = V_209 -> V_22 ;
unsigned long V_70 ;
F_66 ( & V_22 -> V_17 , V_70 ) ;
F_81 ( V_29 , V_209 -> V_229 -> V_38 ) ;
V_40 = V_221 ;
F_67 ( & V_22 -> V_17 , V_70 ) ;
return V_40 ;
}
static int F_316 ( struct V_219 * V_151 , bool * V_294 )
{
int V_40 ;
struct V_208 * V_209 = V_151 -> V_212 ;
struct V_22 * V_22 = V_209 -> V_22 ;
T_2 V_295 = V_151 -> V_36 ;
T_1 V_296 ;
* V_294 = false ;
( void ) F_78 ( V_295 , V_22 -> V_24 ) ;
V_40 = F_317 ( V_22 -> V_113 , & V_296 ) ;
if ( V_40 ) {
F_240 ( L_58 ,
F_126 ( V_22 -> V_66 ) ) ;
return V_40 ;
}
if ( V_295 < V_296 ) {
F_240 ( L_59 ,
F_126 ( V_22 -> V_66 ) ,
( unsigned long long ) V_295 , V_296 ) ;
return - V_147 ;
} else if ( V_295 > V_296 ) {
if ( F_238 ( V_22 -> V_113 ) ) {
F_240 ( L_60 ,
F_126 ( V_22 -> V_66 ) ) ;
return 0 ;
}
if ( V_296 )
F_235 ( L_61 ,
F_126 ( V_22 -> V_66 ) ,
V_296 , ( unsigned long long ) V_295 ) ;
V_40 = F_318 ( V_22 -> V_113 , V_295 ) ;
if ( V_40 ) {
F_111 ( V_22 , L_62 , V_40 ) ;
return V_40 ;
}
* V_294 = true ;
}
return 0 ;
}
static int F_319 ( struct V_219 * V_151 , bool * V_294 )
{
int V_40 ;
struct V_208 * V_209 = V_151 -> V_212 ;
struct V_22 * V_22 = V_209 -> V_22 ;
T_1 V_273 , V_297 ;
* V_294 = false ;
V_273 = F_303 ( V_22 -> V_68 ) ;
V_40 = F_320 ( V_22 -> V_113 , & V_297 ) ;
if ( V_40 ) {
F_240 ( L_63 ,
F_126 ( V_22 -> V_66 ) ) ;
return V_40 ;
}
if ( V_273 < V_297 ) {
F_240 ( L_64 ,
F_126 ( V_22 -> V_66 ) ,
V_273 , V_297 ) ;
return - V_147 ;
} else if ( V_273 > V_297 ) {
if ( F_238 ( V_22 -> V_113 ) ) {
F_240 ( L_65 ,
F_126 ( V_22 -> V_66 ) ) ;
return 0 ;
}
F_301 ( V_22 -> V_68 ) ;
F_235 ( L_66 ,
F_126 ( V_22 -> V_66 ) ,
V_297 , V_273 ) ;
V_40 = F_321 ( V_22 -> V_113 , V_273 ) ;
if ( V_40 ) {
F_111 ( V_22 , L_67 , V_40 ) ;
return V_40 ;
}
* V_294 = true ;
}
return 0 ;
}
static int F_322 ( struct V_219 * V_151 )
{
int V_40 ;
bool V_298 , V_299 ;
struct V_208 * V_209 = V_151 -> V_212 ;
struct V_22 * V_22 = V_209 -> V_22 ;
V_40 = F_260 ( V_22 , V_151 ) ;
if ( V_40 )
return V_40 ;
V_40 = F_316 ( V_151 , & V_298 ) ;
if ( V_40 )
return V_40 ;
V_40 = F_319 ( V_151 , & V_299 ) ;
if ( V_40 )
return V_40 ;
if ( V_298 || V_299 )
( void ) F_153 ( V_22 ) ;
return 0 ;
}
static void F_323 ( struct V_22 * V_22 )
{
struct V_27 * V_28 ;
V_28 = F_209 ( V_22 ) ;
while ( V_28 ) {
F_324 ( V_28 -> V_300 ) ;
V_28 = F_212 ( V_22 , V_28 ) ;
}
}
static void F_325 ( struct V_22 * V_22 )
{
struct V_27 * V_28 ;
V_28 = F_209 ( V_22 ) ;
while ( V_28 ) {
F_326 ( V_28 -> V_300 ) ;
V_28 = F_212 ( V_22 , V_28 ) ;
}
}
static void F_327 ( struct V_219 * V_151 )
{
struct V_208 * V_209 = V_151 -> V_212 ;
struct V_22 * V_22 = V_209 -> V_22 ;
unsigned long V_70 ;
F_254 ( V_22 ) ;
F_325 ( V_22 ) ;
F_66 ( & V_22 -> V_17 , V_70 ) ;
V_22 -> V_150 = false ;
V_22 -> V_256 = false ;
F_67 ( & V_22 -> V_17 , V_70 ) ;
F_219 ( & V_22 -> V_200 . V_301 ) ;
}
static void F_328 ( struct V_219 * V_151 )
{
struct V_208 * V_209 = V_151 -> V_212 ;
struct V_22 * V_22 = V_209 -> V_22 ;
unsigned long V_70 ;
F_66 ( & V_22 -> V_17 , V_70 ) ;
V_22 -> V_256 = true ;
F_67 ( & V_22 -> V_17 , V_70 ) ;
F_323 ( V_22 ) ;
}
static void F_329 ( struct V_219 * V_151 )
{
struct V_208 * V_209 = V_151 -> V_212 ;
struct V_22 * V_22 = V_209 -> V_22 ;
unsigned long V_70 ;
F_325 ( V_22 ) ;
F_66 ( & V_22 -> V_17 , V_70 ) ;
V_22 -> V_256 = false ;
F_67 ( & V_22 -> V_17 , V_70 ) ;
}
static void F_330 ( struct V_219 * V_151 )
{
struct V_208 * V_209 = V_151 -> V_212 ;
struct V_22 * V_22 = V_209 -> V_22 ;
F_331 ( & V_22 -> V_200 ) ;
F_331 ( & V_22 -> V_201 ) ;
F_332 ( V_22 -> V_43 ) ;
( void ) F_153 ( V_22 ) ;
}
static int F_333 ( unsigned V_268 , unsigned V_302 )
{
if ( V_268 != V_302 ) {
F_125 ( L_68 ,
V_268 , V_302 ) ;
return - V_147 ;
}
return 0 ;
}
static int F_334 ( char * V_303 , T_8 * V_304 , int V_305 )
{
if ( ! F_310 ( V_303 , 10 , ( unsigned long long * ) V_304 ) &&
* V_304 <= V_306 )
return 0 ;
if ( V_305 )
F_125 ( L_69 , V_303 ) ;
return - V_147 ;
}
static int F_335 ( unsigned V_268 , char * * V_279 , struct V_22 * V_22 )
{
T_8 V_304 ;
int V_40 ;
V_40 = F_333 ( V_268 , 2 ) ;
if ( V_40 )
return V_40 ;
V_40 = F_334 ( V_279 [ 1 ] , & V_304 , 1 ) ;
if ( V_40 )
return V_40 ;
V_40 = F_336 ( V_22 -> V_113 , V_304 ) ;
if ( V_40 ) {
F_125 ( L_70 ,
V_279 [ 1 ] ) ;
return V_40 ;
}
return 0 ;
}
static int F_337 ( unsigned V_268 , char * * V_279 , struct V_22 * V_22 )
{
T_8 V_304 ;
T_8 V_307 ;
int V_40 ;
V_40 = F_333 ( V_268 , 3 ) ;
if ( V_40 )
return V_40 ;
V_40 = F_334 ( V_279 [ 1 ] , & V_304 , 1 ) ;
if ( V_40 )
return V_40 ;
V_40 = F_334 ( V_279 [ 2 ] , & V_307 , 1 ) ;
if ( V_40 )
return V_40 ;
V_40 = F_338 ( V_22 -> V_113 , V_304 , V_307 ) ;
if ( V_40 ) {
F_125 ( L_71 ,
V_279 [ 1 ] , V_279 [ 2 ] ) ;
return V_40 ;
}
return 0 ;
}
static int F_339 ( unsigned V_268 , char * * V_279 , struct V_22 * V_22 )
{
T_8 V_304 ;
int V_40 ;
V_40 = F_333 ( V_268 , 2 ) ;
if ( V_40 )
return V_40 ;
V_40 = F_334 ( V_279 [ 1 ] , & V_304 , 1 ) ;
if ( V_40 )
return V_40 ;
V_40 = F_340 ( V_22 -> V_113 , V_304 ) ;
if ( V_40 )
F_125 ( L_72 , V_279 [ 1 ] ) ;
return V_40 ;
}
static int F_341 ( unsigned V_268 , char * * V_279 , struct V_22 * V_22 )
{
T_8 V_308 , V_309 ;
int V_40 ;
V_40 = F_333 ( V_268 , 3 ) ;
if ( V_40 )
return V_40 ;
if ( F_310 ( V_279 [ 1 ] , 10 , ( unsigned long long * ) & V_308 ) ) {
F_125 ( L_73 , V_279 [ 1 ] ) ;
return - V_147 ;
}
if ( F_310 ( V_279 [ 2 ] , 10 , ( unsigned long long * ) & V_309 ) ) {
F_125 ( L_74 , V_279 [ 2 ] ) ;
return - V_147 ;
}
V_40 = F_342 ( V_22 -> V_113 , V_308 , V_309 ) ;
if ( V_40 ) {
F_125 ( L_75 ,
V_279 [ 1 ] , V_279 [ 2 ] ) ;
return V_40 ;
}
return 0 ;
}
static int F_343 ( unsigned V_268 , char * * V_279 , struct V_22 * V_22 )
{
int V_40 ;
V_40 = F_333 ( V_268 , 1 ) ;
if ( V_40 )
return V_40 ;
( void ) F_153 ( V_22 ) ;
V_40 = F_344 ( V_22 -> V_113 ) ;
if ( V_40 )
F_125 ( L_76 ) ;
return V_40 ;
}
static int F_345 ( unsigned V_268 , char * * V_279 , struct V_22 * V_22 )
{
int V_40 ;
V_40 = F_333 ( V_268 , 1 ) ;
if ( V_40 )
return V_40 ;
V_40 = F_346 ( V_22 -> V_113 ) ;
if ( V_40 )
F_125 ( L_77 ) ;
return V_40 ;
}
static int F_347 ( struct V_219 * V_151 , unsigned V_268 , char * * V_279 )
{
int V_40 = - V_147 ;
struct V_208 * V_209 = V_151 -> V_212 ;
struct V_22 * V_22 = V_209 -> V_22 ;
if ( F_150 ( V_22 ) >= V_146 ) {
F_240 ( L_78 ,
F_126 ( V_22 -> V_66 ) ) ;
return - V_310 ;
}
if ( ! strcasecmp ( V_279 [ 0 ] , L_79 ) )
V_40 = F_335 ( V_268 , V_279 , V_22 ) ;
else if ( ! strcasecmp ( V_279 [ 0 ] , L_80 ) )
V_40 = F_337 ( V_268 , V_279 , V_22 ) ;
else if ( ! strcasecmp ( V_279 [ 0 ] , L_81 ) )
V_40 = F_339 ( V_268 , V_279 , V_22 ) ;
else if ( ! strcasecmp ( V_279 [ 0 ] , L_82 ) )
V_40 = F_341 ( V_268 , V_279 , V_22 ) ;
else if ( ! strcasecmp ( V_279 [ 0 ] , L_83 ) )
V_40 = F_343 ( V_268 , V_279 , V_22 ) ;
else if ( ! strcasecmp ( V_279 [ 0 ] , L_84 ) )
V_40 = F_345 ( V_268 , V_279 , V_22 ) ;
else
F_125 ( L_85 , V_279 [ 0 ] ) ;
if ( ! V_40 )
( void ) F_153 ( V_22 ) ;
return V_40 ;
}
static void F_348 ( struct V_241 * V_138 , char * V_153 ,
unsigned V_311 , unsigned V_312 )
{
unsigned V_128 = ! V_138 -> V_139 + ! V_138 -> V_242 +
! V_138 -> V_211 + ( V_138 -> V_206 == V_146 ) +
V_138 -> V_156 ;
F_349 ( L_86 , V_128 ) ;
if ( ! V_138 -> V_139 )
F_349 ( L_87 ) ;
if ( ! V_138 -> V_242 )
F_349 ( L_88 ) ;
if ( ! V_138 -> V_211 )
F_349 ( L_89 ) ;
if ( V_138 -> V_206 == V_146 )
F_349 ( L_90 ) ;
if ( V_138 -> V_156 )
F_349 ( L_91 ) ;
}
static void F_350 ( struct V_219 * V_151 , T_9 type ,
unsigned V_313 , char * V_153 , unsigned V_312 )
{
int V_40 ;
unsigned V_311 = 0 ;
T_10 V_314 ;
T_1 V_315 ;
T_1 V_316 ;
T_1 V_317 ;
T_1 V_318 ;
T_1 V_319 ;
char V_238 [ V_239 ] ;
char V_320 [ V_239 ] ;
struct V_208 * V_209 = V_151 -> V_212 ;
struct V_22 * V_22 = V_209 -> V_22 ;
switch ( type ) {
case V_321 :
if ( F_150 ( V_22 ) == V_157 ) {
F_349 ( L_92 ) ;
break;
}
if ( ! ( V_313 & V_322 ) && ! F_351 ( V_151 ) )
( void ) F_153 ( V_22 ) ;
V_40 = F_352 ( V_22 -> V_113 , & V_314 ) ;
if ( V_40 ) {
F_240 ( L_93 ,
F_126 ( V_22 -> V_66 ) , V_40 ) ;
goto V_323;
}
V_40 = F_353 ( V_22 -> V_113 , & V_316 ) ;
if ( V_40 ) {
F_240 ( L_94 ,
F_126 ( V_22 -> V_66 ) , V_40 ) ;
goto V_323;
}
V_40 = F_320 ( V_22 -> V_113 , & V_318 ) ;
if ( V_40 ) {
F_240 ( L_95 ,
F_126 ( V_22 -> V_66 ) , V_40 ) ;
goto V_323;
}
V_40 = F_151 ( V_22 -> V_113 , & V_315 ) ;
if ( V_40 ) {
F_240 ( L_96 ,
F_126 ( V_22 -> V_66 ) , V_40 ) ;
goto V_323;
}
V_40 = F_317 ( V_22 -> V_113 , & V_317 ) ;
if ( V_40 ) {
F_240 ( L_97 ,
F_126 ( V_22 -> V_66 ) , V_40 ) ;
goto V_323;
}
V_40 = F_354 ( V_22 -> V_113 , & V_319 ) ;
if ( V_40 ) {
F_240 ( L_98 ,
F_126 ( V_22 -> V_66 ) , V_40 ) ;
goto V_323;
}
F_349 ( L_99 ,
( unsigned long long ) V_314 ,
( unsigned long long ) ( V_318 - V_316 ) ,
( unsigned long long ) V_318 ,
( unsigned long long ) ( V_317 - V_315 ) ,
( unsigned long long ) V_317 ) ;
if ( V_319 )
F_349 ( L_100 , V_319 ) ;
else
F_349 ( L_101 ) ;
if ( V_22 -> V_138 . V_206 == V_144 )
F_349 ( L_102 ) ;
else if ( V_22 -> V_138 . V_206 == V_146 )
F_349 ( L_103 ) ;
else
F_349 ( L_104 ) ;
if ( ! V_22 -> V_138 . V_242 )
F_349 ( L_88 ) ;
else if ( V_22 -> V_138 . V_211 )
F_349 ( L_105 ) ;
else
F_349 ( L_89 ) ;
if ( V_22 -> V_138 . V_156 )
F_349 ( L_91 ) ;
else
F_349 ( L_106 ) ;
if ( F_238 ( V_22 -> V_113 ) )
F_349 ( L_107 ) ;
else
F_349 ( L_101 ) ;
break;
case V_324 :
F_349 ( L_108 ,
F_355 ( V_238 , V_209 -> V_243 -> V_38 -> V_325 ) ,
F_355 ( V_320 , V_209 -> V_229 -> V_38 -> V_325 ) ,
( unsigned long ) V_22 -> V_24 ,
( unsigned long long ) V_209 -> V_149 ) ;
F_348 ( & V_209 -> V_217 , V_153 , V_311 , V_312 ) ;
break;
}
return;
V_323:
F_349 ( L_109 ) ;
}
static int F_356 ( struct V_219 * V_151 ,
T_11 F_39 , void * V_326 )
{
struct V_208 * V_209 = V_151 -> V_212 ;
return F_39 ( V_151 , V_209 -> V_229 , 0 , V_151 -> V_36 , V_326 ) ;
}
static void F_357 ( struct V_219 * V_151 , struct V_234 * V_236 )
{
struct V_208 * V_209 = V_151 -> V_212 ;
struct V_22 * V_22 = V_209 -> V_22 ;
T_2 V_327 = V_236 -> V_328 >> V_82 ;
if ( V_236 -> V_329 < V_22 -> V_24 ) {
while ( ! F_257 ( V_22 -> V_24 , V_236 -> V_329 ) ) {
if ( ( V_236 -> V_329 & ( V_236 -> V_329 - 1 ) ) == 0 )
V_236 -> V_329 -- ;
V_236 -> V_329 = F_358 ( V_236 -> V_329 ) ;
}
}
if ( V_327 < V_22 -> V_24 ||
! F_257 ( V_327 , V_22 -> V_24 ) ) {
if ( F_257 ( V_22 -> V_24 , V_236 -> V_329 ) )
F_359 ( V_236 , V_236 -> V_329 << V_82 ) ;
else
F_359 ( V_236 , V_22 -> V_24 << V_82 ) ;
F_360 ( V_236 , V_22 -> V_24 << V_82 ) ;
}
if ( ! V_209 -> V_210 . V_242 ) {
V_236 -> V_330 = 0 ;
return;
}
F_258 ( V_209 ) ;
}
static void F_211 ( struct V_27 * V_28 )
{
F_145 ( & V_28 -> V_331 ) ;
}
static void F_214 ( struct V_27 * V_28 )
{
if ( F_98 ( & V_28 -> V_331 ) )
F_226 ( & V_28 -> V_332 ) ;
}
static void F_361 ( struct V_219 * V_151 )
{
struct V_27 * V_28 = V_151 -> V_212 ;
unsigned long V_70 ;
F_66 ( & V_28 -> V_22 -> V_17 , V_70 ) ;
F_362 ( & V_28 -> V_62 ) ;
F_67 ( & V_28 -> V_22 -> V_17 , V_70 ) ;
F_363 () ;
F_214 ( V_28 ) ;
F_230 ( & V_28 -> V_332 ) ;
F_292 ( & V_59 . V_60 ) ;
F_289 ( V_28 -> V_22 ) ;
F_364 ( V_28 -> V_2 ) ;
F_293 ( V_151 , V_28 -> V_37 ) ;
if ( V_28 -> V_84 )
F_293 ( V_151 , V_28 -> V_84 ) ;
F_271 ( V_28 ) ;
F_294 ( & V_59 . V_60 ) ;
}
static int F_365 ( struct V_219 * V_151 , unsigned V_268 , char * * V_279 )
{
int V_40 ;
struct V_27 * V_28 ;
struct V_132 * V_37 , * V_84 ;
struct V_63 * V_66 ;
unsigned long V_70 ;
F_292 ( & V_59 . V_60 ) ;
if ( V_268 != 2 && V_268 != 3 ) {
V_151 -> error = L_52 ;
V_40 = - V_147 ;
goto V_282;
}
V_28 = V_151 -> V_212 = F_311 ( sizeof( * V_28 ) , V_248 ) ;
if ( ! V_28 ) {
V_151 -> error = L_110 ;
V_40 = - V_124 ;
goto V_282;
}
V_28 -> V_300 = F_312 ( V_151 -> V_152 ) ;
F_284 ( & V_28 -> V_17 ) ;
F_51 ( & V_28 -> V_73 ) ;
F_62 ( & V_28 -> V_74 ) ;
F_62 ( & V_28 -> V_75 ) ;
V_28 -> V_178 = V_333 ;
if ( V_268 == 3 ) {
V_40 = F_308 ( V_151 , V_279 [ 2 ] , V_283 , & V_84 ) ;
if ( V_40 ) {
V_151 -> error = L_111 ;
goto V_334;
}
V_28 -> V_84 = V_84 ;
}
V_40 = F_308 ( V_151 , V_279 [ 0 ] , F_366 ( V_151 -> V_152 ) , & V_37 ) ;
if ( V_40 ) {
V_151 -> error = L_112 ;
goto V_335;
}
V_28 -> V_37 = V_37 ;
if ( F_334 ( V_279 [ 1 ] , ( unsigned long long * ) & V_28 -> V_304 , 0 ) ) {
V_151 -> error = L_113 ;
V_40 = - V_147 ;
goto V_336;
}
V_66 = F_367 ( V_28 -> V_37 -> V_38 -> V_325 ) ;
if ( ! V_66 ) {
V_151 -> error = L_114 ;
V_40 = - V_147 ;
goto V_336;
}
V_28 -> V_22 = F_57 ( V_66 ) ;
if ( ! V_28 -> V_22 ) {
V_151 -> error = L_115 ;
V_40 = - V_147 ;
goto V_337;
}
F_288 ( V_28 -> V_22 ) ;
if ( F_150 ( V_28 -> V_22 ) == V_157 ) {
V_151 -> error = L_116 ;
V_40 = - V_147 ;
goto V_249;
}
V_40 = F_368 ( V_28 -> V_22 -> V_113 , V_28 -> V_304 , & V_28 -> V_2 ) ;
if ( V_40 ) {
V_151 -> error = L_117 ;
goto V_249;
}
V_40 = F_369 ( V_151 , V_28 -> V_22 -> V_24 ) ;
if ( V_40 )
goto V_338;
V_151 -> V_290 = 1 ;
V_151 -> V_339 = true ;
V_151 -> V_340 = sizeof( struct V_86 ) ;
if ( V_28 -> V_22 -> V_138 . V_242 ) {
V_151 -> V_292 = true ;
V_151 -> V_291 = 1 ;
V_151 -> V_341 = false ;
}
F_294 ( & V_59 . V_60 ) ;
F_66 ( & V_28 -> V_22 -> V_17 , V_70 ) ;
if ( V_28 -> V_22 -> V_256 ) {
F_67 ( & V_28 -> V_22 -> V_17 , V_70 ) ;
F_292 ( & V_59 . V_60 ) ;
V_151 -> error = L_118 ;
V_40 = - V_147 ;
goto V_338;
}
F_142 ( & V_28 -> V_331 , 1 ) ;
F_229 ( & V_28 -> V_332 ) ;
F_370 ( & V_28 -> V_62 , & V_28 -> V_22 -> V_193 ) ;
F_67 ( & V_28 -> V_22 -> V_17 , V_70 ) ;
F_363 () ;
F_371 ( V_66 ) ;
return 0 ;
V_338:
F_364 ( V_28 -> V_2 ) ;
V_249:
F_289 ( V_28 -> V_22 ) ;
V_337:
F_371 ( V_66 ) ;
V_336:
F_293 ( V_151 , V_28 -> V_37 ) ;
V_335:
if ( V_28 -> V_84 )
F_293 ( V_151 , V_28 -> V_84 ) ;
V_334:
F_271 ( V_28 ) ;
V_282:
F_294 ( & V_59 . V_60 ) ;
return V_40 ;
}
static int F_372 ( struct V_219 * V_151 , struct V_29 * V_29 )
{
V_29 -> V_77 . V_78 = F_373 ( V_151 , V_29 -> V_77 . V_78 ) ;
return F_249 ( V_151 , V_29 ) ;
}
static int F_374 ( struct V_219 * V_151 , struct V_29 * V_29 ,
T_3 * V_323 )
{
unsigned long V_70 ;
struct V_86 * V_87 = F_88 ( V_29 , sizeof( struct V_86 ) ) ;
struct V_71 V_301 ;
struct V_91 * V_92 , * V_65 ;
struct V_22 * V_22 = V_87 -> V_28 -> V_22 ;
if ( V_87 -> V_167 ) {
F_51 ( & V_301 ) ;
F_375 ( V_87 -> V_167 , & V_301 ) ;
F_66 ( & V_22 -> V_17 , V_70 ) ;
F_70 (m, tmp, &work, list) {
F_56 ( & V_92 -> V_62 ) ;
F_97 ( V_92 ) ;
}
F_67 ( & V_22 -> V_17 , V_70 ) ;
}
if ( V_87 -> V_88 ) {
F_51 ( & V_301 ) ;
F_375 ( V_87 -> V_88 , & V_301 ) ;
if ( ! F_207 ( & V_301 ) ) {
F_66 ( & V_22 -> V_17 , V_70 ) ;
F_70 (m, tmp, &work, list)
F_99 ( & V_92 -> V_62 , & V_22 -> V_198 ) ;
F_67 ( & V_22 -> V_17 , V_70 ) ;
F_30 ( V_22 ) ;
}
}
if ( V_87 -> V_50 )
F_103 ( V_87 -> V_28 , V_87 -> V_50 ) ;
return V_342 ;
}
static void F_376 ( struct V_219 * V_151 )
{
struct V_27 * V_28 = V_151 -> V_212 ;
if ( F_377 ( V_151 ) )
V_204 ( V_28 , F_232 ) ;
}
static void F_378 ( struct V_219 * V_151 )
{
struct V_27 * V_28 = V_151 -> V_212 ;
V_204 ( V_28 , F_233 ) ;
}
static int F_379 ( struct V_219 * V_151 )
{
struct V_27 * V_28 = V_151 -> V_212 ;
if ( V_28 -> V_84 )
V_28 -> V_142 = F_299 ( V_28 -> V_84 -> V_38 ) ;
return 0 ;
}
static void F_380 ( struct V_219 * V_151 , T_9 type ,
unsigned V_313 , char * V_153 , unsigned V_312 )
{
int V_40 ;
T_12 V_311 = 0 ;
T_1 V_343 , V_344 ;
char V_238 [ V_239 ] ;
struct V_27 * V_28 = V_151 -> V_212 ;
if ( F_150 ( V_28 -> V_22 ) == V_157 ) {
F_349 ( L_92 ) ;
return;
}
if ( ! V_28 -> V_2 )
F_349 ( L_119 ) ;
else {
switch ( type ) {
case V_321 :
V_40 = F_381 ( V_28 -> V_2 , & V_343 ) ;
if ( V_40 ) {
F_240 ( L_120 , V_40 ) ;
goto V_323;
}
V_40 = F_382 ( V_28 -> V_2 , & V_344 ) ;
if ( V_40 < 0 ) {
F_240 ( L_121 , V_40 ) ;
goto V_323;
}
F_349 ( L_100 , V_343 * V_28 -> V_22 -> V_24 ) ;
if ( V_40 )
F_349 ( L_122 , ( ( V_344 + 1 ) *
V_28 -> V_22 -> V_24 ) - 1 ) ;
else
F_349 ( L_119 ) ;
break;
case V_324 :
F_349 ( L_123 ,
F_355 ( V_238 , V_28 -> V_37 -> V_38 -> V_325 ) ,
( unsigned long ) V_28 -> V_304 ) ;
if ( V_28 -> V_84 )
F_349 ( L_124 , F_355 ( V_238 , V_28 -> V_84 -> V_38 -> V_325 ) ) ;
break;
}
}
return;
V_323:
F_349 ( L_109 ) ;
}
static int F_383 ( struct V_219 * V_151 ,
T_11 F_39 , void * V_326 )
{
T_2 V_345 ;
struct V_27 * V_28 = V_151 -> V_212 ;
struct V_22 * V_22 = V_28 -> V_22 ;
if ( ! V_22 -> V_151 )
return 0 ;
V_345 = V_22 -> V_151 -> V_36 ;
( void ) F_78 ( V_345 , V_22 -> V_24 ) ;
if ( V_345 )
return F_39 ( V_151 , V_28 -> V_37 , 0 , V_22 -> V_24 * V_345 , V_326 ) ;
return 0 ;
}
static void F_384 ( struct V_219 * V_151 , struct V_234 * V_236 )
{
struct V_27 * V_28 = V_151 -> V_212 ;
struct V_22 * V_22 = V_28 -> V_22 ;
if ( ! V_22 -> V_138 . V_242 )
return;
V_236 -> V_330 = V_22 -> V_24 << V_82 ;
V_236 -> V_240 = 2048 * 1024 * 16 ;
}
static int T_13 F_385 ( void )
{
int V_40 ;
F_49 () ;
V_40 = F_386 ( & V_346 ) ;
if ( V_40 )
return V_40 ;
V_40 = F_386 ( & V_347 ) ;
if ( V_40 )
goto V_348;
V_40 = - V_124 ;
V_260 = F_387 ( V_91 , 0 ) ;
if ( ! V_260 )
goto V_349;
return 0 ;
V_349:
F_388 ( & V_347 ) ;
V_348:
F_388 ( & V_346 ) ;
return V_40 ;
}
static void F_389 ( void )
{
F_388 ( & V_346 ) ;
F_388 ( & V_347 ) ;
F_390 ( V_260 ) ;
}
