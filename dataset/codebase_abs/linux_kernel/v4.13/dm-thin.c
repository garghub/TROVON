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
V_29 -> V_84 = V_28 -> V_37 -> V_38 ;
if ( F_16 ( V_22 ) )
V_29 -> V_77 . V_78 =
( V_83 << V_22 -> V_23 ) |
( V_78 & ( V_22 -> V_24 - 1 ) ) ;
else
V_29 -> V_77 . V_78 = ( V_83 * V_22 -> V_24 ) +
F_78 ( V_78 , V_22 -> V_24 ) ;
}
static void F_81 ( struct V_27 * V_28 , struct V_29 * V_29 )
{
V_29 -> V_84 = V_28 -> V_85 -> V_38 ;
}
static int F_82 ( struct V_27 * V_28 , struct V_29 * V_29 )
{
return F_83 ( V_29 -> V_86 ) &&
F_84 ( V_28 -> V_2 ) ;
}
static void F_85 ( struct V_22 * V_22 , struct V_29 * V_29 )
{
struct V_87 * V_88 ;
if ( F_86 ( V_29 ) == V_41 )
return;
V_88 = F_87 ( V_29 , sizeof( struct V_87 ) ) ;
V_88 -> V_89 = F_88 ( V_22 -> V_90 ) ;
}
static void F_89 ( struct V_27 * V_28 , struct V_29 * V_29 )
{
struct V_22 * V_22 = V_28 -> V_22 ;
unsigned long V_70 ;
if ( ! F_82 ( V_28 , V_29 ) ) {
F_90 ( V_29 ) ;
return;
}
if ( F_91 ( V_28 -> V_2 ) ) {
F_92 ( V_29 ) ;
return;
}
F_66 ( & V_22 -> V_17 , V_70 ) ;
F_93 ( & V_22 -> V_91 , V_29 ) ;
F_67 ( & V_22 -> V_17 , V_70 ) ;
}
static void F_94 ( struct V_27 * V_28 , struct V_29 * V_29 )
{
F_81 ( V_28 , V_29 ) ;
F_89 ( V_28 , V_29 ) ;
}
static void F_95 ( struct V_27 * V_28 , struct V_29 * V_29 ,
T_1 V_83 )
{
F_80 ( V_28 , V_29 , V_83 ) ;
F_89 ( V_28 , V_29 ) ;
}
static void F_96 ( struct V_92 * V_93 )
{
struct V_22 * V_22 = V_93 -> V_28 -> V_22 ;
if ( F_97 ( & V_93 -> V_94 ) ) {
F_98 ( & V_93 -> V_62 , & V_22 -> V_95 ) ;
F_30 ( V_22 ) ;
}
}
static void F_99 ( struct V_92 * V_93 )
{
unsigned long V_70 ;
struct V_22 * V_22 = V_93 -> V_28 -> V_22 ;
F_66 ( & V_22 -> V_17 , V_70 ) ;
F_96 ( V_93 ) ;
F_67 ( & V_22 -> V_17 , V_70 ) ;
}
static void F_100 ( int V_96 , unsigned long V_97 , void * V_53 )
{
struct V_92 * V_93 = V_53 ;
V_93 -> V_98 = V_96 || V_97 ? V_57 : 0 ;
F_99 ( V_93 ) ;
}
static void F_101 ( struct V_29 * V_29 )
{
struct V_87 * V_88 = F_87 ( V_29 , sizeof( struct V_87 ) ) ;
struct V_92 * V_93 = V_88 -> V_99 ;
V_29 -> V_100 = V_93 -> V_101 ;
V_93 -> V_98 = V_29 -> V_42 ;
F_99 ( V_93 ) ;
}
static void F_102 ( struct V_27 * V_28 , struct V_45 * V_50 )
{
struct V_22 * V_22 = V_28 -> V_22 ;
unsigned long V_70 ;
F_66 ( & V_28 -> V_17 , V_70 ) ;
F_41 ( V_22 , V_50 , & V_28 -> V_74 ) ;
F_67 ( & V_28 -> V_17 , V_70 ) ;
F_30 ( V_22 ) ;
}
static void F_103 ( void * V_53 ,
struct V_45 * V_50 )
{
struct V_102 * V_103 = V_53 ;
struct V_29 * V_29 ;
while ( ( V_29 = F_64 ( & V_50 -> V_52 ) ) ) {
if ( F_83 ( V_29 -> V_86 ) || F_86 ( V_29 ) == V_41 )
F_93 ( & V_103 -> V_104 , V_29 ) ;
else {
F_85 ( V_103 -> V_28 -> V_22 , V_29 ) ;
F_93 ( & V_103 -> V_105 , V_29 ) ;
}
}
}
static void F_104 ( struct V_27 * V_28 ,
struct V_45 * V_50 ,
T_1 V_83 )
{
struct V_29 * V_29 ;
struct V_102 V_103 ;
V_103 . V_28 = V_28 ;
F_62 ( & V_103 . V_104 ) ;
F_62 ( & V_103 . V_105 ) ;
F_38 ( V_28 -> V_22 , F_103 ,
& V_103 , V_50 ) ;
while ( ( V_29 = F_64 ( & V_103 . V_104 ) ) )
F_105 ( V_28 , V_29 ) ;
while ( ( V_29 = F_64 ( & V_103 . V_105 ) ) )
F_95 ( V_103 . V_28 , V_29 , V_83 ) ;
}
static void F_106 ( struct V_92 * V_93 )
{
F_46 ( V_93 -> V_28 -> V_22 , V_93 -> V_50 ) ;
F_56 ( & V_93 -> V_62 ) ;
F_107 ( V_93 , V_93 -> V_28 -> V_22 -> V_106 ) ;
}
static void F_108 ( struct V_92 * V_93 )
{
struct V_27 * V_28 = V_93 -> V_28 ;
struct V_22 * V_22 = V_28 -> V_22 ;
struct V_29 * V_29 = V_93 -> V_29 ;
int V_40 ;
if ( V_93 -> V_98 ) {
F_46 ( V_22 , V_93 -> V_50 ) ;
goto V_107;
}
V_40 = F_109 ( V_28 -> V_2 , V_93 -> V_108 , V_93 -> V_109 ) ;
if ( V_40 ) {
F_110 ( V_22 , L_1 , V_40 ) ;
F_46 ( V_22 , V_93 -> V_50 ) ;
goto V_107;
}
if ( V_29 ) {
F_104 ( V_28 , V_93 -> V_50 , V_93 -> V_109 ) ;
F_29 ( V_29 ) ;
} else {
F_85 ( V_28 -> V_22 , V_93 -> V_50 -> V_110 ) ;
F_95 ( V_28 , V_93 -> V_50 -> V_110 , V_93 -> V_109 ) ;
F_104 ( V_28 , V_93 -> V_50 , V_93 -> V_109 ) ;
}
V_107:
F_56 ( & V_93 -> V_62 ) ;
F_107 ( V_93 , V_22 -> V_106 ) ;
}
static void F_111 ( struct V_92 * V_93 )
{
struct V_27 * V_28 = V_93 -> V_28 ;
if ( V_93 -> V_50 )
F_102 ( V_28 , V_93 -> V_50 ) ;
F_107 ( V_93 , V_28 -> V_22 -> V_106 ) ;
}
static void F_112 ( struct V_92 * V_93 )
{
F_92 ( V_93 -> V_29 ) ;
F_111 ( V_93 ) ;
}
static void F_113 ( struct V_92 * V_93 )
{
F_29 ( V_93 -> V_29 ) ;
F_111 ( V_93 ) ;
}
static void F_114 ( struct V_92 * V_93 )
{
int V_40 ;
struct V_27 * V_28 = V_93 -> V_28 ;
V_40 = F_115 ( V_28 -> V_2 , V_93 -> V_50 -> V_8 . V_12 , V_93 -> V_50 -> V_8 . V_13 ) ;
if ( V_40 ) {
F_110 ( V_28 -> V_22 , L_2 , V_40 ) ;
F_92 ( V_93 -> V_29 ) ;
} else
F_29 ( V_93 -> V_29 ) ;
F_102 ( V_28 , V_93 -> V_50 ) ;
F_107 ( V_93 , V_28 -> V_22 -> V_106 ) ;
}
static void F_116 ( struct V_92 * V_93 ,
struct V_29 * V_111 )
{
int V_40 = 0 ;
bool V_112 = true ;
struct V_27 * V_28 = V_93 -> V_28 ;
struct V_22 * V_22 = V_28 -> V_22 ;
T_1 V_5 = V_93 -> V_109 , V_6 , V_80 = V_93 -> V_109 + V_93 -> V_113 - V_93 -> V_108 ;
struct V_25 V_26 ;
F_18 ( & V_26 , V_28 , V_111 ) ;
while ( V_5 != V_80 ) {
for (; V_5 < V_80 ; V_5 ++ ) {
V_40 = F_117 ( V_22 -> V_114 , V_5 , & V_112 ) ;
if ( V_40 )
goto V_107;
if ( ! V_112 )
break;
}
if ( V_5 == V_80 )
break;
for ( V_6 = V_5 + 1 ; V_6 != V_80 ; V_6 ++ ) {
V_40 = F_117 ( V_22 -> V_114 , V_6 , & V_112 ) ;
if ( V_40 )
goto V_107;
if ( V_112 )
break;
}
V_40 = F_21 ( & V_26 , V_5 , V_6 ) ;
if ( V_40 )
goto V_107;
V_5 = V_6 ;
}
V_107:
F_23 ( & V_26 , V_40 ) ;
}
static void F_118 ( struct V_92 * V_93 )
{
unsigned long V_70 ;
struct V_22 * V_22 = V_93 -> V_28 -> V_22 ;
F_66 ( & V_22 -> V_17 , V_70 ) ;
F_98 ( & V_93 -> V_62 , & V_22 -> V_115 ) ;
F_67 ( & V_22 -> V_17 , V_70 ) ;
F_30 ( V_22 ) ;
}
static void F_119 ( struct V_29 * V_29 )
{
F_118 ( V_29 -> V_116 ) ;
F_120 ( V_29 ) ;
}
static void F_121 ( struct V_92 * V_93 )
{
int V_40 ;
struct V_27 * V_28 = V_93 -> V_28 ;
struct V_22 * V_22 = V_28 -> V_22 ;
struct V_29 * V_111 ;
T_1 V_117 = V_93 -> V_109 + ( V_93 -> V_113 - V_93 -> V_108 ) ;
V_40 = F_115 ( V_28 -> V_2 , V_93 -> V_108 , V_93 -> V_113 ) ;
if ( V_40 ) {
F_110 ( V_22 , L_2 , V_40 ) ;
F_92 ( V_93 -> V_29 ) ;
F_102 ( V_28 , V_93 -> V_50 ) ;
F_107 ( V_93 , V_22 -> V_106 ) ;
return;
}
V_40 = F_122 ( V_22 -> V_114 , V_93 -> V_109 , V_117 ) ;
if ( V_40 ) {
F_110 ( V_22 , L_3 , V_40 ) ;
F_92 ( V_93 -> V_29 ) ;
F_102 ( V_28 , V_93 -> V_50 ) ;
F_107 ( V_93 , V_22 -> V_106 ) ;
return;
}
V_111 = F_123 ( V_49 , 1 ) ;
if ( ! V_111 ) {
F_124 ( L_4 ,
F_125 ( V_28 -> V_22 -> V_66 ) ) ;
F_118 ( V_93 ) ;
} else {
V_111 -> V_100 = F_119 ;
V_111 -> V_116 = V_93 ;
if ( V_93 -> V_118 )
F_116 ( V_93 , V_111 ) ;
else {
struct V_25 V_26 ;
F_18 ( & V_26 , V_28 , V_111 ) ;
V_40 = F_21 ( & V_26 , V_93 -> V_109 , V_117 ) ;
F_23 ( & V_26 , V_40 ) ;
}
}
}
static void F_126 ( struct V_92 * V_93 )
{
int V_40 ;
struct V_27 * V_28 = V_93 -> V_28 ;
struct V_22 * V_22 = V_28 -> V_22 ;
V_40 = F_127 ( V_22 -> V_114 , V_93 -> V_109 ,
V_93 -> V_109 + ( V_93 -> V_113 - V_93 -> V_108 ) ) ;
if ( V_40 ) {
F_110 ( V_22 , L_5 , V_40 ) ;
F_92 ( V_93 -> V_29 ) ;
} else
F_29 ( V_93 -> V_29 ) ;
F_102 ( V_28 , V_93 -> V_50 ) ;
F_107 ( V_93 , V_22 -> V_106 ) ;
}
static void F_128 ( struct V_22 * V_22 , struct V_71 * V_119 ,
T_4 * F_39 )
{
unsigned long V_70 ;
struct V_71 V_120 ;
struct V_92 * V_93 , * V_65 ;
F_51 ( & V_120 ) ;
F_66 ( & V_22 -> V_17 , V_70 ) ;
F_69 ( V_119 , & V_120 ) ;
F_67 ( & V_22 -> V_17 , V_70 ) ;
F_70 ( V_93 , V_65 , & V_120 , V_62 )
( * F_39 ) ( V_93 ) ;
}
static int F_129 ( struct V_22 * V_22 , struct V_29 * V_29 )
{
return V_29 -> V_77 . V_81 ==
( V_22 -> V_24 << V_82 ) ;
}
static int F_130 ( struct V_22 * V_22 , struct V_29 * V_29 )
{
return ( F_131 ( V_29 ) == V_121 ) &&
F_129 ( V_22 , V_29 ) ;
}
static void F_132 ( struct V_29 * V_29 , T_5 * * V_122 ,
T_5 * F_39 )
{
* V_122 = V_29 -> V_100 ;
V_29 -> V_100 = F_39 ;
}
static int F_133 ( struct V_22 * V_22 )
{
if ( V_22 -> V_123 )
return 0 ;
V_22 -> V_123 = F_134 ( V_22 -> V_106 , V_124 ) ;
return V_22 -> V_123 ? 0 : - V_125 ;
}
static struct V_92 * F_135 ( struct V_22 * V_22 )
{
struct V_92 * V_93 = V_22 -> V_123 ;
F_19 ( ! V_22 -> V_123 ) ;
memset ( V_93 , 0 , sizeof( struct V_92 ) ) ;
F_51 ( & V_93 -> V_62 ) ;
V_93 -> V_29 = NULL ;
V_22 -> V_123 = NULL ;
return V_93 ;
}
static void F_136 ( struct V_27 * V_28 , struct V_92 * V_93 ,
T_2 V_79 , T_2 V_80 )
{
int V_40 ;
struct V_126 V_127 ;
V_127 . V_38 = V_28 -> V_37 -> V_38 ;
V_127 . V_128 = V_79 ;
V_127 . V_129 = V_80 - V_79 ;
V_40 = F_137 ( V_28 -> V_22 -> V_130 , 1 , & V_127 , 0 , F_100 , V_93 ) ;
if ( V_40 < 0 ) {
F_138 ( L_6 ) ;
F_100 ( 1 , 1 , V_93 ) ;
}
}
static void F_139 ( struct V_27 * V_28 , struct V_29 * V_29 ,
T_1 V_131 ,
struct V_92 * V_93 )
{
struct V_22 * V_22 = V_28 -> V_22 ;
struct V_87 * V_88 = F_87 ( V_29 , sizeof( struct V_87 ) ) ;
V_88 -> V_99 = V_93 ;
V_93 -> V_29 = V_29 ;
F_132 ( V_29 , & V_93 -> V_101 , F_101 ) ;
F_85 ( V_22 , V_29 ) ;
F_95 ( V_28 , V_29 , V_131 ) ;
}
static void F_140 ( struct V_27 * V_28 , T_1 V_132 ,
struct V_133 * V_134 , T_1 V_135 ,
T_1 V_136 ,
struct V_45 * V_50 , struct V_29 * V_29 ,
T_2 V_36 )
{
int V_40 ;
struct V_22 * V_22 = V_28 -> V_22 ;
struct V_92 * V_93 = F_135 ( V_22 ) ;
V_93 -> V_28 = V_28 ;
V_93 -> V_108 = V_132 ;
V_93 -> V_113 = V_132 + 1u ;
V_93 -> V_109 = V_136 ;
V_93 -> V_50 = V_50 ;
F_141 ( & V_93 -> V_94 , 3 ) ;
if ( ! F_142 ( V_22 -> V_137 , & V_93 -> V_62 ) )
F_99 ( V_93 ) ;
if ( F_130 ( V_22 , V_29 ) )
F_139 ( V_28 , V_29 , V_136 , V_93 ) ;
else {
struct V_126 V_138 , V_127 ;
V_138 . V_38 = V_134 -> V_38 ;
V_138 . V_128 = V_135 * V_22 -> V_24 ;
V_138 . V_129 = V_36 ;
V_127 . V_38 = V_28 -> V_37 -> V_38 ;
V_127 . V_128 = V_136 * V_22 -> V_24 ;
V_127 . V_129 = V_36 ;
V_40 = F_143 ( V_22 -> V_130 , & V_138 , 1 , & V_127 ,
0 , F_100 , V_93 ) ;
if ( V_40 < 0 ) {
F_138 ( L_7 ) ;
F_100 ( 1 , 1 , V_93 ) ;
}
if ( V_36 < V_22 -> V_24 && V_22 -> V_139 . V_140 ) {
F_144 ( & V_93 -> V_94 ) ;
F_136 ( V_28 , V_93 ,
V_136 * V_22 -> V_24 + V_36 ,
( V_136 + 1 ) * V_22 -> V_24 ) ;
}
}
F_99 ( V_93 ) ;
}
static void F_145 ( struct V_27 * V_28 , T_1 V_132 ,
T_1 V_135 , T_1 V_136 ,
struct V_45 * V_50 , struct V_29 * V_29 )
{
F_140 ( V_28 , V_132 , V_28 -> V_37 ,
V_135 , V_136 , V_50 , V_29 ,
V_28 -> V_22 -> V_24 ) ;
}
static void F_146 ( struct V_27 * V_28 , T_1 V_132 ,
T_1 V_109 , struct V_45 * V_50 ,
struct V_29 * V_29 )
{
struct V_22 * V_22 = V_28 -> V_22 ;
struct V_92 * V_93 = F_135 ( V_22 ) ;
F_141 ( & V_93 -> V_94 , 1 ) ;
V_93 -> V_28 = V_28 ;
V_93 -> V_108 = V_132 ;
V_93 -> V_113 = V_132 + 1u ;
V_93 -> V_109 = V_109 ;
V_93 -> V_50 = V_50 ;
if ( V_22 -> V_139 . V_140 ) {
if ( F_130 ( V_22 , V_29 ) )
F_139 ( V_28 , V_29 , V_109 , V_93 ) ;
else
F_136 ( V_28 , V_93 , V_109 * V_22 -> V_24 ,
( V_109 + 1 ) * V_22 -> V_24 ) ;
} else
F_108 ( V_93 ) ;
}
static void F_147 ( struct V_27 * V_28 , T_1 V_132 ,
T_1 V_136 ,
struct V_45 * V_50 , struct V_29 * V_29 )
{
struct V_22 * V_22 = V_28 -> V_22 ;
T_2 V_141 = V_132 * V_22 -> V_24 ;
T_2 V_142 = ( V_132 + 1 ) * V_22 -> V_24 ;
if ( V_142 <= V_28 -> V_143 )
F_140 ( V_28 , V_132 , V_28 -> V_85 ,
V_132 , V_136 , V_50 , V_29 ,
V_22 -> V_24 ) ;
else if ( V_141 < V_28 -> V_143 )
F_140 ( V_28 , V_132 , V_28 -> V_85 ,
V_132 , V_136 , V_50 , V_29 ,
V_28 -> V_143 - V_141 ) ;
else
F_146 ( V_28 , V_132 , V_136 , V_50 , V_29 ) ;
}
static void F_148 ( struct V_22 * V_22 )
{
int V_40 ;
T_1 V_144 ;
if ( F_149 ( V_22 ) != V_145 )
return;
V_40 = F_150 ( V_22 -> V_114 , & V_144 ) ;
if ( V_40 )
return;
if ( V_144 )
F_151 ( V_22 , V_146 ) ;
}
static int F_152 ( struct V_22 * V_22 )
{
int V_40 ;
if ( F_149 ( V_22 ) >= V_147 )
return - V_148 ;
V_40 = F_153 ( V_22 -> V_114 ) ;
if ( V_40 )
F_110 ( V_22 , L_8 , V_40 ) ;
else
F_148 ( V_22 ) ;
return V_40 ;
}
static void F_154 ( struct V_22 * V_22 , T_1 V_149 )
{
unsigned long V_70 ;
if ( V_149 <= V_22 -> V_150 && ! V_22 -> V_151 ) {
F_124 ( L_9 ,
F_125 ( V_22 -> V_66 ) ) ;
F_66 ( & V_22 -> V_17 , V_70 ) ;
V_22 -> V_151 = true ;
F_67 ( & V_22 -> V_17 , V_70 ) ;
F_155 ( V_22 -> V_152 -> V_153 ) ;
}
}
static int F_156 ( struct V_27 * V_28 , T_1 * V_154 )
{
int V_40 ;
T_1 V_149 ;
struct V_22 * V_22 = V_28 -> V_22 ;
if ( F_157 ( F_149 ( V_22 ) != V_146 ) )
return - V_148 ;
V_40 = F_150 ( V_22 -> V_114 , & V_149 ) ;
if ( V_40 ) {
F_110 ( V_22 , L_10 , V_40 ) ;
return V_40 ;
}
F_154 ( V_22 , V_149 ) ;
if ( ! V_149 ) {
V_40 = F_152 ( V_22 ) ;
if ( V_40 )
return V_40 ;
V_40 = F_150 ( V_22 -> V_114 , & V_149 ) ;
if ( V_40 ) {
F_110 ( V_22 , L_10 , V_40 ) ;
return V_40 ;
}
if ( ! V_149 ) {
F_151 ( V_22 , V_145 ) ;
return - V_155 ;
}
}
V_40 = F_158 ( V_22 -> V_114 , V_154 ) ;
if ( V_40 ) {
F_110 ( V_22 , L_11 , V_40 ) ;
return V_40 ;
}
return 0 ;
}
static void F_159 ( struct V_29 * V_29 )
{
struct V_87 * V_88 = F_87 ( V_29 , sizeof( struct V_87 ) ) ;
struct V_27 * V_28 = V_88 -> V_28 ;
unsigned long V_70 ;
F_66 ( & V_28 -> V_17 , V_70 ) ;
F_93 ( & V_28 -> V_75 , V_29 ) ;
F_67 ( & V_28 -> V_17 , V_70 ) ;
}
static T_3 F_160 ( struct V_22 * V_22 )
{
enum V_156 V_93 = F_149 ( V_22 ) ;
switch ( V_93 ) {
case V_146 :
F_138 ( L_12 ) ;
return V_57 ;
case V_145 :
return V_22 -> V_139 . V_157 ? V_56 : 0 ;
case V_147 :
case V_158 :
return V_57 ;
default:
F_138 ( L_13 ) ;
return V_57 ;
}
}
static void F_161 ( struct V_22 * V_22 , struct V_29 * V_29 )
{
T_3 error = F_160 ( V_22 ) ;
if ( error ) {
V_29 -> V_42 = error ;
F_29 ( V_29 ) ;
} else
F_159 ( V_29 ) ;
}
static void F_162 ( struct V_22 * V_22 , struct V_45 * V_50 )
{
struct V_29 * V_29 ;
struct V_51 V_52 ;
T_3 error ;
error = F_160 ( V_22 ) ;
if ( error ) {
F_43 ( V_22 , V_50 , error ) ;
return;
}
F_62 ( & V_52 ) ;
F_36 ( V_22 , V_50 , & V_52 ) ;
while ( ( V_29 = F_64 ( & V_52 ) ) )
F_159 ( V_29 ) ;
}
static void F_163 ( struct V_27 * V_28 ,
struct V_45 * V_159 )
{
struct V_22 * V_22 = V_28 -> V_22 ;
struct V_92 * V_93 = F_135 ( V_22 ) ;
V_93 -> V_28 = V_28 ;
V_93 -> V_108 = V_159 -> V_8 . V_12 ;
V_93 -> V_113 = V_159 -> V_8 . V_13 ;
V_93 -> V_50 = V_159 ;
V_93 -> V_29 = V_159 -> V_110 ;
if ( ! F_142 ( V_22 -> V_90 , & V_93 -> V_62 ) )
V_22 -> V_160 ( V_93 ) ;
}
static void F_164 ( struct V_27 * V_28 , T_1 V_79 , T_1 V_80 ,
struct V_29 * V_29 )
{
struct V_22 * V_22 = V_28 -> V_22 ;
int V_40 ;
bool V_118 ;
struct V_7 V_161 ;
struct V_45 * V_162 ;
struct V_92 * V_93 ;
T_1 V_108 , V_113 , V_131 ;
while ( V_79 != V_80 ) {
V_40 = F_133 ( V_22 ) ;
if ( V_40 )
return;
V_40 = F_165 ( V_28 -> V_2 , V_79 , V_80 , & V_108 , & V_113 ,
& V_131 , & V_118 ) ;
if ( V_40 )
break;
F_1 ( V_28 -> V_2 , V_14 , V_131 , V_131 + ( V_113 - V_108 ) , & V_161 ) ;
if ( F_32 ( V_28 -> V_22 , & V_161 , NULL , & V_162 ) ) {
V_79 = V_113 ;
continue;
}
V_93 = F_135 ( V_22 ) ;
V_93 -> V_28 = V_28 ;
V_93 -> V_118 = V_118 ;
V_93 -> V_108 = V_108 ;
V_93 -> V_113 = V_113 ;
V_93 -> V_109 = V_131 ;
V_93 -> V_50 = V_162 ;
V_93 -> V_29 = V_29 ;
F_166 ( V_29 ) ;
if ( ! F_142 ( V_22 -> V_90 , & V_93 -> V_62 ) )
V_22 -> V_160 ( V_93 ) ;
V_79 = V_113 ;
}
}
static void F_167 ( struct V_27 * V_28 , struct V_45 * V_159 )
{
struct V_29 * V_29 = V_159 -> V_110 ;
struct V_87 * V_88 = F_87 ( V_29 , sizeof( struct V_87 ) ) ;
V_88 -> V_50 = V_159 ;
F_164 ( V_28 , V_159 -> V_8 . V_12 , V_159 -> V_8 . V_13 , V_29 ) ;
F_29 ( V_29 ) ;
}
static void F_168 ( struct V_27 * V_28 , struct V_29 * V_29 )
{
T_1 V_79 , V_80 ;
struct V_7 V_163 ;
struct V_45 * V_159 ;
F_79 ( V_28 , V_29 , & V_79 , & V_80 ) ;
if ( V_79 == V_80 ) {
F_29 ( V_29 ) ;
return;
}
F_1 ( V_28 -> V_2 , V_10 , V_79 , V_80 , & V_163 ) ;
if ( F_32 ( V_28 -> V_22 , & V_163 , V_29 , & V_159 ) )
return;
V_28 -> V_22 -> V_164 ( V_28 , V_159 ) ;
}
static void F_169 ( struct V_27 * V_28 , struct V_29 * V_29 , T_1 V_83 ,
struct V_7 * V_8 ,
struct V_165 * V_166 ,
struct V_45 * V_50 )
{
int V_40 ;
T_1 V_109 ;
struct V_22 * V_22 = V_28 -> V_22 ;
V_40 = F_156 ( V_28 , & V_109 ) ;
switch ( V_40 ) {
case 0 :
F_145 ( V_28 , V_83 , V_166 -> V_83 ,
V_109 , V_50 , V_29 ) ;
break;
case - V_155 :
F_162 ( V_22 , V_50 ) ;
break;
default:
F_138 ( L_14 ,
V_167 , V_40 ) ;
F_46 ( V_22 , V_50 ) ;
break;
}
}
static void F_170 ( void * V_53 ,
struct V_45 * V_50 )
{
struct V_102 * V_103 = V_53 ;
struct V_29 * V_29 ;
while ( ( V_29 = F_64 ( & V_50 -> V_52 ) ) ) {
if ( F_131 ( V_29 ) == V_121 || F_83 ( V_29 -> V_86 ) ||
F_86 ( V_29 ) == V_41 )
F_93 ( & V_103 -> V_104 , V_29 ) ;
else {
struct V_87 * V_88 = F_87 ( V_29 , sizeof( struct V_87 ) ) ; ;
V_88 -> V_168 = F_88 ( V_103 -> V_28 -> V_22 -> V_137 ) ;
F_85 ( V_103 -> V_28 -> V_22 , V_29 ) ;
F_93 ( & V_103 -> V_105 , V_29 ) ;
}
}
}
static void F_171 ( struct V_27 * V_28 ,
struct V_45 * V_50 ,
T_1 V_83 )
{
struct V_29 * V_29 ;
struct V_102 V_103 ;
V_103 . V_28 = V_28 ;
F_62 ( & V_103 . V_104 ) ;
F_62 ( & V_103 . V_105 ) ;
F_38 ( V_28 -> V_22 , F_170 ,
& V_103 , V_50 ) ;
while ( ( V_29 = F_64 ( & V_103 . V_104 ) ) )
F_105 ( V_28 , V_29 ) ;
while ( ( V_29 = F_64 ( & V_103 . V_105 ) ) )
F_95 ( V_28 , V_29 , V_83 ) ;
}
static void F_172 ( struct V_27 * V_28 , struct V_29 * V_29 ,
T_1 V_83 ,
struct V_165 * V_166 ,
struct V_45 * V_159 )
{
struct V_45 * V_162 ;
struct V_22 * V_22 = V_28 -> V_22 ;
struct V_7 V_8 ;
F_3 ( V_28 -> V_2 , V_166 -> V_83 , & V_8 ) ;
if ( F_32 ( V_22 , & V_8 , V_29 , & V_162 ) ) {
F_102 ( V_28 , V_159 ) ;
return;
}
if ( F_131 ( V_29 ) == V_121 && V_29 -> V_77 . V_81 ) {
F_169 ( V_28 , V_29 , V_83 , & V_8 , V_166 , V_162 ) ;
F_102 ( V_28 , V_159 ) ;
} else {
struct V_87 * V_88 = F_87 ( V_29 , sizeof( struct V_87 ) ) ;
V_88 -> V_168 = F_88 ( V_22 -> V_137 ) ;
F_85 ( V_22 , V_29 ) ;
F_95 ( V_28 , V_29 , V_166 -> V_83 ) ;
F_171 ( V_28 , V_162 , V_166 -> V_83 ) ;
F_171 ( V_28 , V_159 , V_166 -> V_83 ) ;
}
}
static void F_173 ( struct V_27 * V_28 , struct V_29 * V_29 , T_1 V_83 ,
struct V_45 * V_50 )
{
int V_40 ;
T_1 V_109 ;
struct V_22 * V_22 = V_28 -> V_22 ;
if ( ! V_29 -> V_77 . V_81 ) {
F_85 ( V_22 , V_29 ) ;
F_102 ( V_28 , V_50 ) ;
F_95 ( V_28 , V_29 , 0 ) ;
return;
}
if ( F_131 ( V_29 ) == V_169 ) {
F_174 ( V_29 ) ;
F_102 ( V_28 , V_50 ) ;
F_29 ( V_29 ) ;
return;
}
V_40 = F_156 ( V_28 , & V_109 ) ;
switch ( V_40 ) {
case 0 :
if ( V_28 -> V_85 )
F_147 ( V_28 , V_83 , V_109 , V_50 , V_29 ) ;
else
F_146 ( V_28 , V_83 , V_109 , V_50 , V_29 ) ;
break;
case - V_155 :
F_162 ( V_22 , V_50 ) ;
break;
default:
F_138 ( L_14 ,
V_167 , V_40 ) ;
F_46 ( V_22 , V_50 ) ;
break;
}
}
static void F_175 ( struct V_27 * V_28 , struct V_45 * V_50 )
{
int V_40 ;
struct V_22 * V_22 = V_28 -> V_22 ;
struct V_29 * V_29 = V_50 -> V_110 ;
T_1 V_83 = F_77 ( V_28 , V_29 ) ;
struct V_165 V_166 ;
if ( V_28 -> V_170 ) {
F_48 ( V_22 , V_50 ) ;
return;
}
V_40 = F_176 ( V_28 -> V_2 , V_83 , 1 , & V_166 ) ;
switch ( V_40 ) {
case 0 :
if ( V_166 . V_171 )
F_172 ( V_28 , V_29 , V_83 , & V_166 , V_50 ) ;
else {
F_85 ( V_22 , V_29 ) ;
F_95 ( V_28 , V_29 , V_166 . V_83 ) ;
F_104 ( V_28 , V_50 , V_166 . V_83 ) ;
}
break;
case - V_172 :
if ( F_131 ( V_29 ) == V_169 && V_28 -> V_85 ) {
F_85 ( V_22 , V_29 ) ;
F_102 ( V_28 , V_50 ) ;
if ( F_177 ( V_29 ) <= V_28 -> V_143 )
F_94 ( V_28 , V_29 ) ;
else if ( V_29 -> V_77 . V_78 < V_28 -> V_143 ) {
F_174 ( V_29 ) ;
V_29 -> V_77 . V_81 = ( V_28 -> V_143 - V_29 -> V_77 . V_78 ) << V_82 ;
F_94 ( V_28 , V_29 ) ;
} else {
F_174 ( V_29 ) ;
F_29 ( V_29 ) ;
}
} else
F_173 ( V_28 , V_29 , V_83 , V_50 ) ;
break;
default:
F_138 ( L_15 ,
V_167 , V_40 ) ;
F_102 ( V_28 , V_50 ) ;
F_92 ( V_29 ) ;
break;
}
}
static void F_178 ( struct V_27 * V_28 , struct V_29 * V_29 )
{
struct V_22 * V_22 = V_28 -> V_22 ;
T_1 V_83 = F_77 ( V_28 , V_29 ) ;
struct V_45 * V_50 ;
struct V_7 V_8 ;
F_4 ( V_28 -> V_2 , V_83 , & V_8 ) ;
if ( F_32 ( V_22 , & V_8 , V_29 , & V_50 ) )
return;
F_175 ( V_28 , V_50 ) ;
}
static void F_179 ( struct V_27 * V_28 , struct V_29 * V_29 ,
struct V_45 * V_50 )
{
int V_40 ;
int V_173 = F_131 ( V_29 ) ;
T_1 V_83 = F_77 ( V_28 , V_29 ) ;
struct V_165 V_166 ;
V_40 = F_176 ( V_28 -> V_2 , V_83 , 1 , & V_166 ) ;
switch ( V_40 ) {
case 0 :
if ( V_166 . V_171 && ( V_173 == V_121 ) && V_29 -> V_77 . V_81 ) {
F_161 ( V_28 -> V_22 , V_29 ) ;
if ( V_50 )
F_102 ( V_28 , V_50 ) ;
} else {
F_85 ( V_28 -> V_22 , V_29 ) ;
F_95 ( V_28 , V_29 , V_166 . V_83 ) ;
if ( V_50 )
F_104 ( V_28 , V_50 , V_166 . V_83 ) ;
}
break;
case - V_172 :
if ( V_50 )
F_102 ( V_28 , V_50 ) ;
if ( V_173 != V_169 ) {
F_161 ( V_28 -> V_22 , V_29 ) ;
break;
}
if ( V_28 -> V_85 ) {
F_85 ( V_28 -> V_22 , V_29 ) ;
F_94 ( V_28 , V_29 ) ;
break;
}
F_174 ( V_29 ) ;
F_29 ( V_29 ) ;
break;
default:
F_138 ( L_15 ,
V_167 , V_40 ) ;
if ( V_50 )
F_102 ( V_28 , V_50 ) ;
F_92 ( V_29 ) ;
break;
}
}
static void F_180 ( struct V_27 * V_28 , struct V_29 * V_29 )
{
F_179 ( V_28 , V_29 , NULL ) ;
}
static void F_181 ( struct V_27 * V_28 , struct V_45 * V_50 )
{
F_179 ( V_28 , V_50 -> V_110 , V_50 ) ;
}
static void F_182 ( struct V_27 * V_28 , struct V_29 * V_29 )
{
F_29 ( V_29 ) ;
}
static void F_183 ( struct V_27 * V_28 , struct V_29 * V_29 )
{
F_92 ( V_29 ) ;
}
static void F_184 ( struct V_27 * V_28 , struct V_45 * V_50 )
{
F_47 ( V_28 -> V_22 , V_50 ) ;
}
static void F_185 ( struct V_27 * V_28 , struct V_45 * V_50 )
{
F_46 ( V_28 -> V_22 , V_50 ) ;
}
static int F_186 ( struct V_22 * V_22 )
{
return ! F_187 ( V_20 , V_22 -> V_174 ,
V_22 -> V_174 + V_175 ) ;
}
static void F_188 ( struct V_27 * V_28 , struct V_29 * V_29 )
{
struct V_176 * * V_177 , * V_30 ;
struct V_87 * V_178 ;
T_2 V_78 = V_29 -> V_77 . V_78 ;
V_177 = & V_28 -> V_179 . V_176 ;
V_30 = NULL ;
while ( * V_177 ) {
V_30 = * V_177 ;
V_178 = F_189 ( V_30 ) ;
if ( V_78 < F_190 ( V_178 ) -> V_77 . V_78 )
V_177 = & ( * V_177 ) -> V_180 ;
else
V_177 = & ( * V_177 ) -> V_181 ;
}
V_178 = F_87 ( V_29 , sizeof( struct V_87 ) ) ;
F_191 ( & V_178 -> V_176 , V_30 , V_177 ) ;
F_192 ( & V_178 -> V_176 , & V_28 -> V_179 ) ;
}
static void F_193 ( struct V_27 * V_28 )
{
struct V_176 * V_182 ;
struct V_87 * V_178 ;
struct V_29 * V_29 ;
for ( V_182 = F_194 ( & V_28 -> V_179 ) ; V_182 ; V_182 = F_195 ( V_182 ) ) {
V_178 = F_189 ( V_182 ) ;
V_29 = F_190 ( V_178 ) ;
F_93 ( & V_28 -> V_74 , V_29 ) ;
F_196 ( & V_178 -> V_176 , & V_28 -> V_179 ) ;
}
F_157 ( ! F_197 ( & V_28 -> V_179 ) ) ;
}
static void F_198 ( struct V_27 * V_28 )
{
struct V_29 * V_29 ;
struct V_51 V_52 ;
F_62 ( & V_52 ) ;
F_61 ( & V_52 , & V_28 -> V_74 ) ;
F_62 ( & V_28 -> V_74 ) ;
while ( ( V_29 = F_64 ( & V_52 ) ) )
F_188 ( V_28 , V_29 ) ;
F_193 ( V_28 ) ;
}
static void F_199 ( struct V_27 * V_28 )
{
struct V_22 * V_22 = V_28 -> V_22 ;
unsigned long V_70 ;
struct V_29 * V_29 ;
struct V_51 V_52 ;
struct V_183 V_31 ;
unsigned V_129 = 0 ;
if ( V_28 -> V_170 ) {
F_65 ( V_28 , & V_28 -> V_74 ,
V_58 ) ;
return;
}
F_62 ( & V_52 ) ;
F_66 ( & V_28 -> V_17 , V_70 ) ;
if ( F_200 ( & V_28 -> V_74 ) ) {
F_67 ( & V_28 -> V_17 , V_70 ) ;
return;
}
F_198 ( V_28 ) ;
F_61 ( & V_52 , & V_28 -> V_74 ) ;
F_62 ( & V_28 -> V_74 ) ;
F_67 ( & V_28 -> V_17 , V_70 ) ;
F_20 ( & V_31 ) ;
while ( ( V_29 = F_64 ( & V_52 ) ) ) {
if ( F_133 ( V_22 ) ) {
F_66 ( & V_28 -> V_17 , V_70 ) ;
F_93 ( & V_28 -> V_74 , V_29 ) ;
F_61 ( & V_28 -> V_74 , & V_52 ) ;
F_67 ( & V_28 -> V_17 , V_70 ) ;
break;
}
if ( F_86 ( V_29 ) == V_41 )
V_22 -> V_184 ( V_28 , V_29 ) ;
else
V_22 -> F_178 ( V_28 , V_29 ) ;
if ( ( V_129 ++ & 127 ) == 0 ) {
F_8 ( & V_22 -> V_15 ) ;
F_201 ( V_22 -> V_114 ) ;
}
}
F_27 ( & V_31 ) ;
}
static int F_202 ( const void * V_185 , const void * V_186 )
{
struct V_45 * V_187 = * ( (struct V_45 * * ) V_185 ) ;
struct V_45 * V_188 = * ( (struct V_45 * * ) V_186 ) ;
F_19 ( ! V_187 -> V_110 ) ;
F_19 ( ! V_188 -> V_110 ) ;
if ( V_187 -> V_110 -> V_77 . V_78 < V_188 -> V_110 -> V_77 . V_78 )
return - 1 ;
if ( V_187 -> V_110 -> V_77 . V_78 > V_188 -> V_110 -> V_77 . V_78 )
return 1 ;
return 0 ;
}
static unsigned F_203 ( struct V_22 * V_22 , struct V_71 * V_72 )
{
unsigned V_129 = 0 ;
struct V_45 * V_50 , * V_65 ;
F_70 (cell, tmp, cells, user_list) {
if ( V_129 >= V_189 )
break;
V_22 -> V_190 [ V_129 ++ ] = V_50 ;
F_56 ( & V_50 -> V_191 ) ;
}
F_204 ( V_22 -> V_190 , V_129 , sizeof( V_50 ) , F_202 , NULL ) ;
return V_129 ;
}
static void F_205 ( struct V_27 * V_28 )
{
struct V_22 * V_22 = V_28 -> V_22 ;
unsigned long V_70 ;
struct V_71 V_72 ;
struct V_45 * V_50 ;
unsigned V_192 , V_193 , V_129 ;
F_51 ( & V_72 ) ;
F_66 ( & V_28 -> V_17 , V_70 ) ;
F_69 ( & V_28 -> V_73 , & V_72 ) ;
F_67 ( & V_28 -> V_17 , V_70 ) ;
if ( F_206 ( & V_72 ) )
return;
do {
V_129 = F_203 ( V_28 -> V_22 , & V_72 ) ;
for ( V_192 = 0 ; V_192 < V_129 ; V_192 ++ ) {
V_50 = V_22 -> V_190 [ V_192 ] ;
F_19 ( ! V_50 -> V_110 ) ;
if ( F_133 ( V_22 ) ) {
for ( V_193 = V_192 ; V_193 < V_129 ; V_193 ++ )
F_54 ( & V_22 -> V_190 [ V_193 ] -> V_191 , & V_72 ) ;
F_66 ( & V_28 -> V_17 , V_70 ) ;
F_207 ( & V_72 , & V_28 -> V_73 ) ;
F_67 ( & V_28 -> V_17 , V_70 ) ;
return;
}
if ( F_86 ( V_50 -> V_110 ) == V_41 )
V_22 -> V_164 ( V_28 , V_50 ) ;
else
V_22 -> F_175 ( V_28 , V_50 ) ;
}
} while ( ! F_206 ( & V_72 ) );
}
static struct V_27 * F_208 ( struct V_22 * V_22 )
{
struct V_27 * V_28 = NULL ;
F_73 () ;
if ( ! F_206 ( & V_22 -> V_194 ) ) {
V_28 = F_209 ( V_22 -> V_194 . V_195 , struct V_27 , V_62 ) ;
F_210 ( V_28 ) ;
}
F_75 () ;
return V_28 ;
}
static struct V_27 * F_211 ( struct V_22 * V_22 , struct V_27 * V_28 )
{
struct V_27 * V_196 = V_28 ;
F_73 () ;
F_212 (tc, &pool->active_thins, list) {
F_210 ( V_28 ) ;
F_213 ( V_196 ) ;
F_75 () ;
return V_28 ;
}
F_213 ( V_196 ) ;
F_75 () ;
return NULL ;
}
static void F_214 ( struct V_22 * V_22 )
{
unsigned long V_70 ;
struct V_29 * V_29 ;
struct V_51 V_52 ;
struct V_27 * V_28 ;
V_28 = F_208 ( V_22 ) ;
while ( V_28 ) {
F_205 ( V_28 ) ;
F_199 ( V_28 ) ;
V_28 = F_211 ( V_22 , V_28 ) ;
}
F_62 ( & V_52 ) ;
F_66 ( & V_22 -> V_17 , V_70 ) ;
F_61 ( & V_52 , & V_22 -> V_91 ) ;
F_62 ( & V_22 -> V_91 ) ;
F_67 ( & V_22 -> V_17 , V_70 ) ;
if ( F_200 ( & V_52 ) &&
! ( F_215 ( V_22 -> V_114 ) && F_186 ( V_22 ) ) )
return;
if ( F_152 ( V_22 ) ) {
while ( ( V_29 = F_64 ( & V_52 ) ) )
F_92 ( V_29 ) ;
return;
}
V_22 -> V_174 = V_20 ;
while ( ( V_29 = F_64 ( & V_52 ) ) )
F_90 ( V_29 ) ;
}
static void F_216 ( struct V_197 * V_198 )
{
struct V_22 * V_22 = F_217 ( V_198 , struct V_22 , V_44 ) ;
F_7 ( & V_22 -> V_15 ) ;
F_201 ( V_22 -> V_114 ) ;
F_8 ( & V_22 -> V_15 ) ;
F_128 ( V_22 , & V_22 -> V_95 , & V_22 -> F_108 ) ;
F_8 ( & V_22 -> V_15 ) ;
F_128 ( V_22 , & V_22 -> V_199 , & V_22 -> V_160 ) ;
F_8 ( & V_22 -> V_15 ) ;
F_128 ( V_22 , & V_22 -> V_115 , & V_22 -> V_200 ) ;
F_8 ( & V_22 -> V_15 ) ;
F_214 ( V_22 ) ;
F_10 ( & V_22 -> V_15 ) ;
}
static void F_218 ( struct V_197 * V_198 )
{
struct V_22 * V_22 = F_217 ( F_219 ( V_198 ) , struct V_22 , V_201 ) ;
F_30 ( V_22 ) ;
F_220 ( V_22 -> V_43 , & V_22 -> V_201 , V_175 ) ;
}
static void F_221 ( struct V_197 * V_198 )
{
struct V_22 * V_22 = F_217 ( F_219 ( V_198 ) , struct V_22 ,
V_202 ) ;
if ( F_149 ( V_22 ) == V_145 && ! V_22 -> V_139 . V_157 ) {
V_22 -> V_139 . V_157 = true ;
F_222 ( V_22 ) ;
F_72 ( V_22 , V_56 ) ;
}
}
static struct V_203 * F_223 ( struct V_197 * V_198 )
{
return F_217 ( V_198 , struct V_203 , V_44 ) ;
}
static void F_224 ( struct V_203 * V_204 )
{
F_225 ( & V_204 -> F_225 ) ;
}
static void F_226 ( struct V_203 * V_204 , struct V_22 * V_22 ,
void (* F_39)( struct V_197 * ) )
{
F_227 ( & V_204 -> V_44 , F_39 ) ;
F_228 ( & V_204 -> F_225 ) ;
F_31 ( V_22 -> V_43 , & V_204 -> V_44 ) ;
F_229 ( & V_204 -> F_225 ) ;
}
static struct V_205 * F_230 ( struct V_197 * V_198 )
{
return F_217 ( F_223 ( V_198 ) , struct V_205 , V_204 ) ;
}
static void F_231 ( struct V_197 * V_198 )
{
struct V_205 * V_206 = F_230 ( V_198 ) ;
V_206 -> V_28 -> V_170 = true ;
F_71 ( V_206 -> V_28 ) ;
F_224 ( & V_206 -> V_204 ) ;
}
static void F_232 ( struct V_197 * V_198 )
{
struct V_205 * V_206 = F_230 ( V_198 ) ;
V_206 -> V_28 -> V_170 = false ;
F_224 ( & V_206 -> V_204 ) ;
}
static void V_205 ( struct V_27 * V_28 , void (* F_39)( struct V_197 * ) )
{
struct V_205 V_206 ;
V_206 . V_28 = V_28 ;
F_226 ( & V_206 . V_204 , V_28 -> V_22 , F_39 ) ;
}
static enum V_156 F_149 ( struct V_22 * V_22 )
{
return V_22 -> V_139 . V_207 ;
}
static void F_233 ( struct V_22 * V_22 , const char * V_208 )
{
F_155 ( V_22 -> V_152 -> V_153 ) ;
F_234 ( L_16 ,
F_125 ( V_22 -> V_66 ) , V_208 ) ;
}
static void F_222 ( struct V_22 * V_22 )
{
if ( ! V_22 -> V_139 . V_157 )
F_233 ( V_22 , L_17 ) ;
else
F_233 ( V_22 , L_18 ) ;
}
static bool F_235 ( struct V_209 * V_210 )
{
return V_210 -> V_211 . V_212 ;
}
static void F_236 ( struct V_22 * V_22 )
{
struct V_209 * V_210 = V_22 -> V_152 -> V_213 ;
if ( F_235 ( V_210 ) ) {
V_22 -> V_164 = F_167 ;
V_22 -> V_160 = F_121 ;
V_22 -> V_200 = F_126 ;
} else {
V_22 -> V_164 = F_163 ;
V_22 -> V_160 = F_114 ;
}
}
static void F_151 ( struct V_22 * V_22 , enum V_156 V_208 )
{
struct V_209 * V_210 = V_22 -> V_152 -> V_213 ;
bool V_214 = F_237 ( V_22 -> V_114 ) ;
enum V_156 V_215 = F_149 ( V_22 ) ;
unsigned long V_202 = F_238 ( V_216 ) * V_217 ;
if ( V_208 == V_146 && V_214 ) {
F_239 ( L_19 ,
F_125 ( V_22 -> V_66 ) ) ;
if ( V_215 != V_208 )
V_208 = V_215 ;
else
V_208 = V_147 ;
}
if ( V_215 == V_158 )
V_208 = V_215 ;
switch ( V_208 ) {
case V_158 :
if ( V_215 != V_208 )
F_233 ( V_22 , L_20 ) ;
F_240 ( V_22 -> V_114 ) ;
V_22 -> F_178 = F_183 ;
V_22 -> V_184 = F_183 ;
V_22 -> F_175 = F_185 ;
V_22 -> V_164 = F_185 ;
V_22 -> F_108 = F_106 ;
V_22 -> V_160 = F_112 ;
F_76 ( V_22 ) ;
break;
case V_147 :
if ( V_215 != V_208 )
F_233 ( V_22 , L_21 ) ;
F_240 ( V_22 -> V_114 ) ;
V_22 -> F_178 = F_180 ;
V_22 -> V_184 = F_182 ;
V_22 -> F_175 = F_181 ;
V_22 -> V_164 = F_184 ;
V_22 -> F_108 = F_106 ;
V_22 -> V_160 = F_113 ;
F_76 ( V_22 ) ;
break;
case V_145 :
if ( V_215 != V_208 )
F_222 ( V_22 ) ;
V_22 -> V_55 = true ;
V_22 -> F_178 = F_180 ;
V_22 -> V_184 = F_168 ;
V_22 -> F_175 = F_181 ;
V_22 -> F_108 = F_108 ;
F_236 ( V_22 ) ;
if ( ! V_22 -> V_139 . V_157 && V_202 )
F_220 ( V_22 -> V_43 , & V_22 -> V_202 , V_202 ) ;
break;
case V_146 :
if ( V_215 != V_208 )
F_233 ( V_22 , L_22 ) ;
V_22 -> V_55 = false ;
V_22 -> V_139 . V_157 = V_210 -> V_218 . V_157 ;
F_241 ( V_22 -> V_114 ) ;
V_22 -> F_178 = F_178 ;
V_22 -> V_184 = F_168 ;
V_22 -> F_175 = F_175 ;
V_22 -> F_108 = F_108 ;
F_236 ( V_22 ) ;
break;
}
V_22 -> V_139 . V_207 = V_208 ;
V_210 -> V_211 . V_207 = V_208 ;
}
static void F_242 ( struct V_22 * V_22 )
{
const char * V_219 = F_125 ( V_22 -> V_66 ) ;
F_138 ( L_23 , V_219 ) ;
if ( F_243 ( V_22 -> V_114 ) ) {
F_239 ( L_24 , V_219 ) ;
F_151 ( V_22 , V_158 ) ;
}
if ( F_244 ( V_22 -> V_114 ) ) {
F_239 ( L_25 , V_219 ) ;
F_151 ( V_22 , V_158 ) ;
}
}
static void F_110 ( struct V_22 * V_22 , const char * V_26 , int V_40 )
{
F_138 ( L_26 ,
F_125 ( V_22 -> V_66 ) , V_26 , V_40 ) ;
F_242 ( V_22 ) ;
F_151 ( V_22 , V_147 ) ;
}
static void F_105 ( struct V_27 * V_28 , struct V_29 * V_29 )
{
unsigned long V_70 ;
struct V_22 * V_22 = V_28 -> V_22 ;
F_66 ( & V_28 -> V_17 , V_70 ) ;
F_93 ( & V_28 -> V_74 , V_29 ) ;
F_67 ( & V_28 -> V_17 , V_70 ) ;
F_30 ( V_22 ) ;
}
static void F_245 ( struct V_27 * V_28 , struct V_29 * V_29 )
{
struct V_22 * V_22 = V_28 -> V_22 ;
F_12 ( & V_22 -> V_15 ) ;
F_105 ( V_28 , V_29 ) ;
F_14 ( & V_22 -> V_15 ) ;
}
static void F_246 ( struct V_27 * V_28 , struct V_45 * V_50 )
{
unsigned long V_70 ;
struct V_22 * V_22 = V_28 -> V_22 ;
F_12 ( & V_22 -> V_15 ) ;
F_66 ( & V_28 -> V_17 , V_70 ) ;
F_98 ( & V_50 -> V_191 , & V_28 -> V_73 ) ;
F_67 ( & V_28 -> V_17 , V_70 ) ;
F_14 ( & V_22 -> V_15 ) ;
F_30 ( V_22 ) ;
}
static void F_247 ( struct V_27 * V_28 , struct V_29 * V_29 )
{
struct V_87 * V_88 = F_87 ( V_29 , sizeof( struct V_87 ) ) ;
V_88 -> V_28 = V_28 ;
V_88 -> V_168 = NULL ;
V_88 -> V_89 = NULL ;
V_88 -> V_99 = NULL ;
V_88 -> V_50 = NULL ;
}
static int F_248 ( struct V_220 * V_152 , struct V_29 * V_29 )
{
int V_40 ;
struct V_27 * V_28 = V_152 -> V_213 ;
T_1 V_83 = F_77 ( V_28 , V_29 ) ;
struct V_1 * V_2 = V_28 -> V_2 ;
struct V_165 V_154 ;
struct V_45 * V_159 , * V_162 ;
struct V_7 V_8 ;
F_247 ( V_28 , V_29 ) ;
if ( V_28 -> V_170 ) {
V_29 -> V_42 = V_58 ;
F_29 ( V_29 ) ;
return V_221 ;
}
if ( F_149 ( V_28 -> V_22 ) == V_158 ) {
F_92 ( V_29 ) ;
return V_221 ;
}
if ( F_83 ( V_29 -> V_86 ) || F_86 ( V_29 ) == V_41 ) {
F_245 ( V_28 , V_29 ) ;
return V_221 ;
}
F_4 ( V_28 -> V_2 , V_83 , & V_8 ) ;
if ( F_32 ( V_28 -> V_22 , & V_8 , V_29 , & V_159 ) )
return V_221 ;
V_40 = F_176 ( V_2 , V_83 , 0 , & V_154 ) ;
switch ( V_40 ) {
case 0 :
if ( F_249 ( V_154 . V_171 ) ) {
F_246 ( V_28 , V_159 ) ;
return V_221 ;
}
F_3 ( V_28 -> V_2 , V_154 . V_83 , & V_8 ) ;
if ( F_32 ( V_28 -> V_22 , & V_8 , V_29 , & V_162 ) ) {
F_102 ( V_28 , V_159 ) ;
return V_221 ;
}
F_85 ( V_28 -> V_22 , V_29 ) ;
F_102 ( V_28 , V_162 ) ;
F_102 ( V_28 , V_159 ) ;
F_80 ( V_28 , V_29 , V_154 . V_83 ) ;
return V_222 ;
case - V_172 :
case - V_223 :
F_246 ( V_28 , V_159 ) ;
return V_221 ;
default:
F_92 ( V_29 ) ;
F_102 ( V_28 , V_159 ) ;
return V_221 ;
}
}
static int F_250 ( struct V_224 * V_225 , int V_226 )
{
struct V_209 * V_210 = F_217 ( V_225 , struct V_209 , V_227 ) ;
struct V_228 * V_229 ;
if ( F_149 ( V_210 -> V_22 ) == V_145 )
return 1 ;
V_229 = F_251 ( V_210 -> V_230 -> V_38 ) ;
return F_252 ( V_229 -> V_231 , V_226 ) ;
}
static void F_253 ( struct V_22 * V_22 )
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
static bool F_254 ( struct V_209 * V_210 )
{
struct V_228 * V_229 = F_251 ( V_210 -> V_230 -> V_38 ) ;
return V_229 && F_255 ( V_229 ) ;
}
static bool F_256 ( T_2 V_232 , T_6 V_233 )
{
return ! F_78 ( V_232 , V_233 ) ;
}
static void F_257 ( struct V_209 * V_210 )
{
struct V_22 * V_22 = V_210 -> V_22 ;
struct V_67 * V_234 = V_210 -> V_230 -> V_38 ;
struct V_235 * V_236 = & F_251 ( V_234 ) -> V_237 ;
const char * V_238 = NULL ;
char V_239 [ V_240 ] ;
if ( ! V_210 -> V_211 . V_212 )
return;
if ( ! F_254 ( V_210 ) )
V_238 = L_27 ;
else if ( V_236 -> V_241 < V_22 -> V_24 )
V_238 = L_28 ;
if ( V_238 ) {
F_124 ( L_29 , F_258 ( V_234 , V_239 ) , V_238 ) ;
V_210 -> V_211 . V_212 = false ;
}
}
static int F_259 ( struct V_22 * V_22 , struct V_220 * V_152 )
{
struct V_209 * V_210 = V_152 -> V_213 ;
enum V_156 V_215 = F_149 ( V_22 ) ;
enum V_156 V_208 = V_210 -> V_211 . V_207 ;
V_210 -> V_211 . V_207 = V_215 ;
V_22 -> V_152 = V_152 ;
V_22 -> V_139 = V_210 -> V_211 ;
V_22 -> V_150 = V_210 -> V_150 ;
F_151 ( V_22 , V_208 ) ;
return 0 ;
}
static void F_260 ( struct V_22 * V_22 , struct V_220 * V_152 )
{
if ( V_22 -> V_152 == V_152 )
V_22 -> V_152 = NULL ;
}
static void F_261 ( struct V_242 * V_139 )
{
V_139 -> V_207 = V_146 ;
V_139 -> V_140 = true ;
V_139 -> V_243 = true ;
V_139 -> V_212 = true ;
V_139 -> V_157 = false ;
}
static void F_262 ( struct V_22 * V_22 )
{
F_55 ( V_22 ) ;
F_263 ( V_22 -> V_190 ) ;
if ( F_264 ( V_22 -> V_114 ) < 0 )
F_124 ( L_30 , V_167 ) ;
F_265 ( V_22 -> V_48 ) ;
F_266 ( V_22 -> V_130 ) ;
if ( V_22 -> V_43 )
F_267 ( V_22 -> V_43 ) ;
if ( V_22 -> V_123 )
F_107 ( V_22 -> V_123 , V_22 -> V_106 ) ;
F_268 ( V_22 -> V_106 ) ;
F_269 ( V_22 -> V_137 ) ;
F_269 ( V_22 -> V_90 ) ;
F_270 ( V_22 ) ;
}
static struct V_22 * F_271 ( struct V_63 * V_66 ,
struct V_67 * V_244 ,
unsigned long V_232 ,
int V_245 , char * * error )
{
int V_40 ;
void * V_246 ;
struct V_22 * V_22 ;
struct V_247 * V_114 ;
bool V_248 = V_245 ? false : true ;
V_114 = F_272 ( V_244 , V_232 , V_248 ) ;
if ( F_273 ( V_114 ) ) {
* error = L_31 ;
return (struct V_22 * ) V_114 ;
}
V_22 = F_274 ( sizeof( * V_22 ) , V_249 ) ;
if ( ! V_22 ) {
* error = L_32 ;
V_246 = F_275 ( - V_125 ) ;
goto V_250;
}
V_22 -> V_114 = V_114 ;
V_22 -> V_24 = V_232 ;
if ( V_232 & ( V_232 - 1 ) )
V_22 -> V_23 = - 1 ;
else
V_22 -> V_23 = F_276 ( V_232 ) ;
V_22 -> V_150 = 0 ;
F_261 ( & V_22 -> V_139 ) ;
V_22 -> V_48 = F_277 () ;
if ( ! V_22 -> V_48 ) {
* error = L_33 ;
V_246 = F_275 ( - V_125 ) ;
goto V_251;
}
V_22 -> V_130 = F_278 ( & V_252 ) ;
if ( F_273 ( V_22 -> V_130 ) ) {
V_40 = F_279 ( V_22 -> V_130 ) ;
* error = L_34 ;
V_246 = F_275 ( V_40 ) ;
goto V_253;
}
V_22 -> V_43 = F_280 ( L_35 V_254 , V_255 ) ;
if ( ! V_22 -> V_43 ) {
* error = L_36 ;
V_246 = F_275 ( - V_125 ) ;
goto V_256;
}
F_5 ( & V_22 -> V_15 ) ;
F_281 ( & V_22 -> V_44 , F_216 ) ;
F_282 ( & V_22 -> V_201 , F_218 ) ;
F_282 ( & V_22 -> V_202 , F_221 ) ;
F_283 ( & V_22 -> V_17 ) ;
F_62 ( & V_22 -> V_91 ) ;
F_51 ( & V_22 -> V_95 ) ;
F_51 ( & V_22 -> V_199 ) ;
F_51 ( & V_22 -> V_115 ) ;
F_51 ( & V_22 -> V_194 ) ;
V_22 -> V_151 = false ;
V_22 -> V_257 = true ;
V_22 -> V_55 = false ;
V_22 -> V_137 = F_284 () ;
if ( ! V_22 -> V_137 ) {
* error = L_37 ;
V_246 = F_275 ( - V_125 ) ;
goto V_258;
}
V_22 -> V_90 = F_284 () ;
if ( ! V_22 -> V_90 ) {
* error = L_38 ;
V_246 = F_275 ( - V_125 ) ;
goto V_259;
}
V_22 -> V_123 = NULL ;
V_22 -> V_106 = F_285 ( V_260 ,
V_261 ) ;
if ( ! V_22 -> V_106 ) {
* error = L_39 ;
V_246 = F_275 ( - V_125 ) ;
goto V_262;
}
V_22 -> V_190 = F_286 ( sizeof( * V_22 -> V_190 ) * V_189 ) ;
if ( ! V_22 -> V_190 ) {
* error = L_40 ;
V_246 = F_275 ( - V_125 ) ;
goto V_263;
}
V_22 -> V_264 = 1 ;
V_22 -> V_174 = V_20 ;
V_22 -> V_66 = V_66 ;
V_22 -> V_68 = V_244 ;
F_52 ( V_22 ) ;
return V_22 ;
V_263:
F_268 ( V_22 -> V_106 ) ;
V_262:
F_269 ( V_22 -> V_90 ) ;
V_259:
F_269 ( V_22 -> V_137 ) ;
V_258:
F_267 ( V_22 -> V_43 ) ;
V_256:
F_266 ( V_22 -> V_130 ) ;
V_253:
F_265 ( V_22 -> V_48 ) ;
V_251:
F_270 ( V_22 ) ;
V_250:
if ( F_264 ( V_114 ) )
F_124 ( L_30 , V_167 ) ;
return V_246 ;
}
static void F_287 ( struct V_22 * V_22 )
{
F_19 ( ! F_53 ( & V_59 . V_60 ) ) ;
V_22 -> V_264 ++ ;
}
static void F_288 ( struct V_22 * V_22 )
{
F_19 ( ! F_53 ( & V_59 . V_60 ) ) ;
F_19 ( ! V_22 -> V_264 ) ;
if ( ! -- V_22 -> V_264 )
F_262 ( V_22 ) ;
}
static struct V_22 * F_289 ( struct V_63 * V_66 ,
struct V_67 * V_244 ,
unsigned long V_232 , int V_245 ,
char * * error , int * V_265 )
{
struct V_22 * V_22 = F_59 ( V_244 ) ;
if ( V_22 ) {
if ( V_22 -> V_66 != V_66 ) {
* error = L_41 ;
return F_275 ( - V_266 ) ;
}
F_287 ( V_22 ) ;
} else {
V_22 = F_57 ( V_66 ) ;
if ( V_22 ) {
if ( V_22 -> V_68 != V_244 ) {
* error = L_42 ;
return F_275 ( - V_148 ) ;
}
F_287 ( V_22 ) ;
} else {
V_22 = F_271 ( V_66 , V_244 , V_232 , V_245 , error ) ;
* V_265 = 1 ;
}
}
return V_22 ;
}
static void F_290 ( struct V_220 * V_152 )
{
struct V_209 * V_210 = V_152 -> V_213 ;
F_291 ( & V_59 . V_60 ) ;
F_260 ( V_210 -> V_22 , V_152 ) ;
F_288 ( V_210 -> V_22 ) ;
F_292 ( V_152 , V_210 -> V_244 ) ;
F_292 ( V_152 , V_210 -> V_230 ) ;
F_270 ( V_210 ) ;
F_293 ( & V_59 . V_60 ) ;
}
static int F_294 ( struct V_267 * V_268 , struct V_242 * V_139 ,
struct V_220 * V_152 )
{
int V_40 ;
unsigned V_269 ;
const char * V_270 ;
static struct V_271 V_272 [] = {
{ 0 , 4 , L_43 } ,
} ;
if ( ! V_268 -> V_269 )
return 0 ;
V_40 = F_295 ( V_272 , V_268 , & V_269 , & V_152 -> error ) ;
if ( V_40 )
return - V_148 ;
while ( V_269 && ! V_40 ) {
V_270 = F_296 ( V_268 ) ;
V_269 -- ;
if ( ! strcasecmp ( V_270 , L_44 ) )
V_139 -> V_140 = false ;
else if ( ! strcasecmp ( V_270 , L_45 ) )
V_139 -> V_243 = false ;
else if ( ! strcasecmp ( V_270 , L_46 ) )
V_139 -> V_212 = false ;
else if ( ! strcasecmp ( V_270 , L_47 ) )
V_139 -> V_207 = V_147 ;
else if ( ! strcasecmp ( V_270 , L_48 ) )
V_139 -> V_157 = true ;
else {
V_152 -> error = L_49 ;
V_40 = - V_148 ;
break;
}
}
return V_40 ;
}
static void F_297 ( void * V_53 )
{
struct V_22 * V_22 = V_53 ;
F_124 ( L_50 ,
F_125 ( V_22 -> V_66 ) ) ;
F_155 ( V_22 -> V_152 -> V_153 ) ;
}
static T_2 F_298 ( struct V_67 * V_38 )
{
return F_299 ( V_38 -> V_273 ) >> V_82 ;
}
static void F_300 ( struct V_67 * V_38 )
{
T_2 V_274 = F_298 ( V_38 ) ;
char V_275 [ V_240 ] ;
if ( V_274 > V_276 )
F_124 ( L_51 ,
F_258 ( V_38 , V_275 ) , V_277 ) ;
}
static T_2 F_301 ( struct V_67 * V_38 )
{
T_2 V_274 = F_298 ( V_38 ) ;
if ( V_274 > V_277 )
V_274 = V_277 ;
return V_274 ;
}
static T_1 F_302 ( struct V_67 * V_38 )
{
T_2 V_274 = F_301 ( V_38 ) ;
F_78 ( V_274 , V_278 ) ;
return V_274 ;
}
static T_1 F_303 ( struct V_209 * V_210 )
{
T_1 V_279 = F_302 ( V_210 -> V_244 -> V_38 ) / 4 ;
return F_304 ( ( T_1 ) 1024ULL , V_279 ) ;
}
static int F_305 ( struct V_220 * V_152 , unsigned V_269 , char * * V_280 )
{
int V_40 , V_281 = 0 ;
struct V_209 * V_210 ;
struct V_22 * V_22 ;
struct V_242 V_139 ;
struct V_267 V_268 ;
struct V_133 * V_230 ;
unsigned long V_232 ;
T_1 V_150 ;
struct V_133 * V_244 ;
T_7 V_282 ;
F_291 ( & V_59 . V_60 ) ;
if ( V_269 < 4 ) {
V_152 -> error = L_52 ;
V_40 = - V_148 ;
goto V_283;
}
V_268 . V_269 = V_269 ;
V_268 . V_280 = V_280 ;
F_261 ( & V_139 ) ;
F_306 ( & V_268 , 4 ) ;
V_40 = F_294 ( & V_268 , & V_139 , V_152 ) ;
if ( V_40 )
goto V_283;
V_282 = V_284 | ( ( V_139 . V_207 == V_147 ) ? 0 : V_285 ) ;
V_40 = F_307 ( V_152 , V_280 [ 0 ] , V_282 , & V_244 ) ;
if ( V_40 ) {
V_152 -> error = L_53 ;
goto V_283;
}
F_300 ( V_244 -> V_38 ) ;
V_40 = F_307 ( V_152 , V_280 [ 1 ] , V_284 | V_285 , & V_230 ) ;
if ( V_40 ) {
V_152 -> error = L_54 ;
goto V_286;
}
if ( F_308 ( V_280 [ 2 ] , 10 , & V_232 ) || ! V_232 ||
V_232 < V_287 ||
V_232 > V_288 ||
V_232 & ( V_287 - 1 ) ) {
V_152 -> error = L_55 ;
V_40 = - V_148 ;
goto V_107;
}
if ( F_309 ( V_280 [ 3 ] , 10 , ( unsigned long long * ) & V_150 ) ) {
V_152 -> error = L_56 ;
V_40 = - V_148 ;
goto V_107;
}
V_210 = F_310 ( sizeof( * V_210 ) , V_249 ) ;
if ( ! V_210 ) {
V_40 = - V_125 ;
goto V_107;
}
V_22 = F_289 ( F_311 ( V_152 -> V_153 ) , V_244 -> V_38 ,
V_232 , V_139 . V_207 == V_147 , & V_152 -> error , & V_281 ) ;
if ( F_273 ( V_22 ) ) {
V_40 = F_279 ( V_22 ) ;
goto V_289;
}
if ( ! V_281 && V_139 . V_243 != V_22 -> V_139 . V_243 ) {
V_152 -> error = L_57 ;
V_40 = - V_148 ;
goto V_290;
}
V_210 -> V_22 = V_22 ;
V_210 -> V_152 = V_152 ;
V_210 -> V_244 = V_244 ;
V_210 -> V_230 = V_230 ;
V_210 -> V_150 = V_150 ;
V_210 -> V_211 = V_210 -> V_218 = V_139 ;
V_152 -> V_291 = 1 ;
if ( V_139 . V_243 && V_139 . V_212 ) {
V_152 -> V_292 = 1 ;
V_152 -> V_293 = true ;
}
V_152 -> V_213 = V_210 ;
V_40 = F_312 ( V_210 -> V_22 -> V_114 ,
F_303 ( V_210 ) ,
F_297 ,
V_22 ) ;
if ( V_40 )
goto V_290;
V_210 -> V_227 . V_294 = F_250 ;
F_313 ( V_152 -> V_153 , & V_210 -> V_227 ) ;
F_293 ( & V_59 . V_60 ) ;
return 0 ;
V_290:
F_288 ( V_22 ) ;
V_289:
F_270 ( V_210 ) ;
V_107:
F_292 ( V_152 , V_230 ) ;
V_286:
F_292 ( V_152 , V_244 ) ;
V_283:
F_293 ( & V_59 . V_60 ) ;
return V_40 ;
}
static int F_314 ( struct V_220 * V_152 , struct V_29 * V_29 )
{
int V_40 ;
struct V_209 * V_210 = V_152 -> V_213 ;
struct V_22 * V_22 = V_210 -> V_22 ;
unsigned long V_70 ;
F_66 ( & V_22 -> V_17 , V_70 ) ;
V_29 -> V_84 = V_210 -> V_230 -> V_38 ;
V_40 = V_222 ;
F_67 ( & V_22 -> V_17 , V_70 ) ;
return V_40 ;
}
static int F_315 ( struct V_220 * V_152 , bool * V_295 )
{
int V_40 ;
struct V_209 * V_210 = V_152 -> V_213 ;
struct V_22 * V_22 = V_210 -> V_22 ;
T_2 V_296 = V_152 -> V_36 ;
T_1 V_297 ;
* V_295 = false ;
( void ) F_78 ( V_296 , V_22 -> V_24 ) ;
V_40 = F_316 ( V_22 -> V_114 , & V_297 ) ;
if ( V_40 ) {
F_239 ( L_58 ,
F_125 ( V_22 -> V_66 ) ) ;
return V_40 ;
}
if ( V_296 < V_297 ) {
F_239 ( L_59 ,
F_125 ( V_22 -> V_66 ) ,
( unsigned long long ) V_296 , V_297 ) ;
return - V_148 ;
} else if ( V_296 > V_297 ) {
if ( F_237 ( V_22 -> V_114 ) ) {
F_239 ( L_60 ,
F_125 ( V_22 -> V_66 ) ) ;
return 0 ;
}
if ( V_297 )
F_234 ( L_61 ,
F_125 ( V_22 -> V_66 ) ,
V_297 , ( unsigned long long ) V_296 ) ;
V_40 = F_317 ( V_22 -> V_114 , V_296 ) ;
if ( V_40 ) {
F_110 ( V_22 , L_62 , V_40 ) ;
return V_40 ;
}
* V_295 = true ;
}
return 0 ;
}
static int F_318 ( struct V_220 * V_152 , bool * V_295 )
{
int V_40 ;
struct V_209 * V_210 = V_152 -> V_213 ;
struct V_22 * V_22 = V_210 -> V_22 ;
T_1 V_274 , V_298 ;
* V_295 = false ;
V_274 = F_302 ( V_22 -> V_68 ) ;
V_40 = F_319 ( V_22 -> V_114 , & V_298 ) ;
if ( V_40 ) {
F_239 ( L_63 ,
F_125 ( V_22 -> V_66 ) ) ;
return V_40 ;
}
if ( V_274 < V_298 ) {
F_239 ( L_64 ,
F_125 ( V_22 -> V_66 ) ,
V_274 , V_298 ) ;
return - V_148 ;
} else if ( V_274 > V_298 ) {
if ( F_237 ( V_22 -> V_114 ) ) {
F_239 ( L_65 ,
F_125 ( V_22 -> V_66 ) ) ;
return 0 ;
}
F_300 ( V_22 -> V_68 ) ;
F_234 ( L_66 ,
F_125 ( V_22 -> V_66 ) ,
V_298 , V_274 ) ;
V_40 = F_320 ( V_22 -> V_114 , V_274 ) ;
if ( V_40 ) {
F_110 ( V_22 , L_67 , V_40 ) ;
return V_40 ;
}
* V_295 = true ;
}
return 0 ;
}
static int F_321 ( struct V_220 * V_152 )
{
int V_40 ;
bool V_299 , V_300 ;
struct V_209 * V_210 = V_152 -> V_213 ;
struct V_22 * V_22 = V_210 -> V_22 ;
V_40 = F_259 ( V_22 , V_152 ) ;
if ( V_40 )
return V_40 ;
V_40 = F_315 ( V_152 , & V_299 ) ;
if ( V_40 )
return V_40 ;
V_40 = F_318 ( V_152 , & V_300 ) ;
if ( V_40 )
return V_40 ;
if ( V_299 || V_300 )
( void ) F_152 ( V_22 ) ;
return 0 ;
}
static void F_322 ( struct V_22 * V_22 )
{
struct V_27 * V_28 ;
V_28 = F_208 ( V_22 ) ;
while ( V_28 ) {
F_323 ( V_28 -> V_301 ) ;
V_28 = F_211 ( V_22 , V_28 ) ;
}
}
static void F_324 ( struct V_22 * V_22 )
{
struct V_27 * V_28 ;
V_28 = F_208 ( V_22 ) ;
while ( V_28 ) {
F_325 ( V_28 -> V_301 ) ;
V_28 = F_211 ( V_22 , V_28 ) ;
}
}
static void F_326 ( struct V_220 * V_152 )
{
struct V_209 * V_210 = V_152 -> V_213 ;
struct V_22 * V_22 = V_210 -> V_22 ;
unsigned long V_70 ;
F_253 ( V_22 ) ;
F_324 ( V_22 ) ;
F_66 ( & V_22 -> V_17 , V_70 ) ;
V_22 -> V_151 = false ;
V_22 -> V_257 = false ;
F_67 ( & V_22 -> V_17 , V_70 ) ;
F_218 ( & V_22 -> V_201 . V_302 ) ;
}
static void F_327 ( struct V_220 * V_152 )
{
struct V_209 * V_210 = V_152 -> V_213 ;
struct V_22 * V_22 = V_210 -> V_22 ;
unsigned long V_70 ;
F_66 ( & V_22 -> V_17 , V_70 ) ;
V_22 -> V_257 = true ;
F_67 ( & V_22 -> V_17 , V_70 ) ;
F_322 ( V_22 ) ;
}
static void F_328 ( struct V_220 * V_152 )
{
struct V_209 * V_210 = V_152 -> V_213 ;
struct V_22 * V_22 = V_210 -> V_22 ;
unsigned long V_70 ;
F_324 ( V_22 ) ;
F_66 ( & V_22 -> V_17 , V_70 ) ;
V_22 -> V_257 = false ;
F_67 ( & V_22 -> V_17 , V_70 ) ;
}
static void F_329 ( struct V_220 * V_152 )
{
struct V_209 * V_210 = V_152 -> V_213 ;
struct V_22 * V_22 = V_210 -> V_22 ;
F_330 ( & V_22 -> V_201 ) ;
F_330 ( & V_22 -> V_202 ) ;
F_331 ( V_22 -> V_43 ) ;
( void ) F_152 ( V_22 ) ;
}
static int F_332 ( unsigned V_269 , unsigned V_303 )
{
if ( V_269 != V_303 ) {
F_124 ( L_68 ,
V_269 , V_303 ) ;
return - V_148 ;
}
return 0 ;
}
static int F_333 ( char * V_304 , T_8 * V_305 , int V_306 )
{
if ( ! F_309 ( V_304 , 10 , ( unsigned long long * ) V_305 ) &&
* V_305 <= V_307 )
return 0 ;
if ( V_306 )
F_124 ( L_69 , V_304 ) ;
return - V_148 ;
}
static int F_334 ( unsigned V_269 , char * * V_280 , struct V_22 * V_22 )
{
T_8 V_305 ;
int V_40 ;
V_40 = F_332 ( V_269 , 2 ) ;
if ( V_40 )
return V_40 ;
V_40 = F_333 ( V_280 [ 1 ] , & V_305 , 1 ) ;
if ( V_40 )
return V_40 ;
V_40 = F_335 ( V_22 -> V_114 , V_305 ) ;
if ( V_40 ) {
F_124 ( L_70 ,
V_280 [ 1 ] ) ;
return V_40 ;
}
return 0 ;
}
static int F_336 ( unsigned V_269 , char * * V_280 , struct V_22 * V_22 )
{
T_8 V_305 ;
T_8 V_308 ;
int V_40 ;
V_40 = F_332 ( V_269 , 3 ) ;
if ( V_40 )
return V_40 ;
V_40 = F_333 ( V_280 [ 1 ] , & V_305 , 1 ) ;
if ( V_40 )
return V_40 ;
V_40 = F_333 ( V_280 [ 2 ] , & V_308 , 1 ) ;
if ( V_40 )
return V_40 ;
V_40 = F_337 ( V_22 -> V_114 , V_305 , V_308 ) ;
if ( V_40 ) {
F_124 ( L_71 ,
V_280 [ 1 ] , V_280 [ 2 ] ) ;
return V_40 ;
}
return 0 ;
}
static int F_338 ( unsigned V_269 , char * * V_280 , struct V_22 * V_22 )
{
T_8 V_305 ;
int V_40 ;
V_40 = F_332 ( V_269 , 2 ) ;
if ( V_40 )
return V_40 ;
V_40 = F_333 ( V_280 [ 1 ] , & V_305 , 1 ) ;
if ( V_40 )
return V_40 ;
V_40 = F_339 ( V_22 -> V_114 , V_305 ) ;
if ( V_40 )
F_124 ( L_72 , V_280 [ 1 ] ) ;
return V_40 ;
}
static int F_340 ( unsigned V_269 , char * * V_280 , struct V_22 * V_22 )
{
T_8 V_309 , V_310 ;
int V_40 ;
V_40 = F_332 ( V_269 , 3 ) ;
if ( V_40 )
return V_40 ;
if ( F_309 ( V_280 [ 1 ] , 10 , ( unsigned long long * ) & V_309 ) ) {
F_124 ( L_73 , V_280 [ 1 ] ) ;
return - V_148 ;
}
if ( F_309 ( V_280 [ 2 ] , 10 , ( unsigned long long * ) & V_310 ) ) {
F_124 ( L_74 , V_280 [ 2 ] ) ;
return - V_148 ;
}
V_40 = F_341 ( V_22 -> V_114 , V_309 , V_310 ) ;
if ( V_40 ) {
F_124 ( L_75 ,
V_280 [ 1 ] , V_280 [ 2 ] ) ;
return V_40 ;
}
return 0 ;
}
static int F_342 ( unsigned V_269 , char * * V_280 , struct V_22 * V_22 )
{
int V_40 ;
V_40 = F_332 ( V_269 , 1 ) ;
if ( V_40 )
return V_40 ;
( void ) F_152 ( V_22 ) ;
V_40 = F_343 ( V_22 -> V_114 ) ;
if ( V_40 )
F_124 ( L_76 ) ;
return V_40 ;
}
static int F_344 ( unsigned V_269 , char * * V_280 , struct V_22 * V_22 )
{
int V_40 ;
V_40 = F_332 ( V_269 , 1 ) ;
if ( V_40 )
return V_40 ;
V_40 = F_345 ( V_22 -> V_114 ) ;
if ( V_40 )
F_124 ( L_77 ) ;
return V_40 ;
}
static int F_346 ( struct V_220 * V_152 , unsigned V_269 , char * * V_280 )
{
int V_40 = - V_148 ;
struct V_209 * V_210 = V_152 -> V_213 ;
struct V_22 * V_22 = V_210 -> V_22 ;
if ( F_149 ( V_22 ) >= V_147 ) {
F_239 ( L_78 ,
F_125 ( V_22 -> V_66 ) ) ;
return - V_311 ;
}
if ( ! strcasecmp ( V_280 [ 0 ] , L_79 ) )
V_40 = F_334 ( V_269 , V_280 , V_22 ) ;
else if ( ! strcasecmp ( V_280 [ 0 ] , L_80 ) )
V_40 = F_336 ( V_269 , V_280 , V_22 ) ;
else if ( ! strcasecmp ( V_280 [ 0 ] , L_81 ) )
V_40 = F_338 ( V_269 , V_280 , V_22 ) ;
else if ( ! strcasecmp ( V_280 [ 0 ] , L_82 ) )
V_40 = F_340 ( V_269 , V_280 , V_22 ) ;
else if ( ! strcasecmp ( V_280 [ 0 ] , L_83 ) )
V_40 = F_342 ( V_269 , V_280 , V_22 ) ;
else if ( ! strcasecmp ( V_280 [ 0 ] , L_84 ) )
V_40 = F_344 ( V_269 , V_280 , V_22 ) ;
else
F_124 ( L_85 , V_280 [ 0 ] ) ;
if ( ! V_40 )
( void ) F_152 ( V_22 ) ;
return V_40 ;
}
static void F_347 ( struct V_242 * V_139 , char * V_154 ,
unsigned V_312 , unsigned V_313 )
{
unsigned V_129 = ! V_139 -> V_140 + ! V_139 -> V_243 +
! V_139 -> V_212 + ( V_139 -> V_207 == V_147 ) +
V_139 -> V_157 ;
F_348 ( L_86 , V_129 ) ;
if ( ! V_139 -> V_140 )
F_348 ( L_87 ) ;
if ( ! V_139 -> V_243 )
F_348 ( L_88 ) ;
if ( ! V_139 -> V_212 )
F_348 ( L_89 ) ;
if ( V_139 -> V_207 == V_147 )
F_348 ( L_90 ) ;
if ( V_139 -> V_157 )
F_348 ( L_91 ) ;
}
static void F_349 ( struct V_220 * V_152 , T_9 type ,
unsigned V_314 , char * V_154 , unsigned V_313 )
{
int V_40 ;
unsigned V_312 = 0 ;
T_10 V_315 ;
T_1 V_316 ;
T_1 V_317 ;
T_1 V_318 ;
T_1 V_319 ;
T_1 V_320 ;
char V_239 [ V_240 ] ;
char V_321 [ V_240 ] ;
struct V_209 * V_210 = V_152 -> V_213 ;
struct V_22 * V_22 = V_210 -> V_22 ;
switch ( type ) {
case V_322 :
if ( F_149 ( V_22 ) == V_158 ) {
F_348 ( L_92 ) ;
break;
}
if ( ! ( V_314 & V_323 ) && ! F_350 ( V_152 ) )
( void ) F_152 ( V_22 ) ;
V_40 = F_351 ( V_22 -> V_114 , & V_315 ) ;
if ( V_40 ) {
F_239 ( L_93 ,
F_125 ( V_22 -> V_66 ) , V_40 ) ;
goto V_324;
}
V_40 = F_352 ( V_22 -> V_114 , & V_317 ) ;
if ( V_40 ) {
F_239 ( L_94 ,
F_125 ( V_22 -> V_66 ) , V_40 ) ;
goto V_324;
}
V_40 = F_319 ( V_22 -> V_114 , & V_319 ) ;
if ( V_40 ) {
F_239 ( L_95 ,
F_125 ( V_22 -> V_66 ) , V_40 ) ;
goto V_324;
}
V_40 = F_150 ( V_22 -> V_114 , & V_316 ) ;
if ( V_40 ) {
F_239 ( L_96 ,
F_125 ( V_22 -> V_66 ) , V_40 ) ;
goto V_324;
}
V_40 = F_316 ( V_22 -> V_114 , & V_318 ) ;
if ( V_40 ) {
F_239 ( L_97 ,
F_125 ( V_22 -> V_66 ) , V_40 ) ;
goto V_324;
}
V_40 = F_353 ( V_22 -> V_114 , & V_320 ) ;
if ( V_40 ) {
F_239 ( L_98 ,
F_125 ( V_22 -> V_66 ) , V_40 ) ;
goto V_324;
}
F_348 ( L_99 ,
( unsigned long long ) V_315 ,
( unsigned long long ) ( V_319 - V_317 ) ,
( unsigned long long ) V_319 ,
( unsigned long long ) ( V_318 - V_316 ) ,
( unsigned long long ) V_318 ) ;
if ( V_320 )
F_348 ( L_100 , V_320 ) ;
else
F_348 ( L_101 ) ;
if ( V_22 -> V_139 . V_207 == V_145 )
F_348 ( L_102 ) ;
else if ( V_22 -> V_139 . V_207 == V_147 )
F_348 ( L_103 ) ;
else
F_348 ( L_104 ) ;
if ( ! V_22 -> V_139 . V_243 )
F_348 ( L_88 ) ;
else if ( V_22 -> V_139 . V_212 )
F_348 ( L_105 ) ;
else
F_348 ( L_89 ) ;
if ( V_22 -> V_139 . V_157 )
F_348 ( L_91 ) ;
else
F_348 ( L_106 ) ;
if ( F_237 ( V_22 -> V_114 ) )
F_348 ( L_107 ) ;
else
F_348 ( L_101 ) ;
break;
case V_325 :
F_348 ( L_108 ,
F_354 ( V_239 , V_210 -> V_244 -> V_38 -> V_326 ) ,
F_354 ( V_321 , V_210 -> V_230 -> V_38 -> V_326 ) ,
( unsigned long ) V_22 -> V_24 ,
( unsigned long long ) V_210 -> V_150 ) ;
F_347 ( & V_210 -> V_218 , V_154 , V_312 , V_313 ) ;
break;
}
return;
V_324:
F_348 ( L_109 ) ;
}
static int F_355 ( struct V_220 * V_152 ,
T_11 F_39 , void * V_327 )
{
struct V_209 * V_210 = V_152 -> V_213 ;
return F_39 ( V_152 , V_210 -> V_230 , 0 , V_152 -> V_36 , V_327 ) ;
}
static void F_356 ( struct V_220 * V_152 , struct V_235 * V_237 )
{
struct V_209 * V_210 = V_152 -> V_213 ;
struct V_22 * V_22 = V_210 -> V_22 ;
T_2 V_328 = V_237 -> V_329 >> V_82 ;
if ( V_237 -> V_330 < V_22 -> V_24 ) {
while ( ! F_256 ( V_22 -> V_24 , V_237 -> V_330 ) ) {
if ( ( V_237 -> V_330 & ( V_237 -> V_330 - 1 ) ) == 0 )
V_237 -> V_330 -- ;
V_237 -> V_330 = F_357 ( V_237 -> V_330 ) ;
}
}
if ( V_328 < V_22 -> V_24 ||
! F_256 ( V_328 , V_22 -> V_24 ) ) {
if ( F_256 ( V_22 -> V_24 , V_237 -> V_330 ) )
F_358 ( V_237 , V_237 -> V_330 << V_82 ) ;
else
F_358 ( V_237 , V_22 -> V_24 << V_82 ) ;
F_359 ( V_237 , V_22 -> V_24 << V_82 ) ;
}
if ( ! V_210 -> V_211 . V_243 ) {
V_237 -> V_331 = 0 ;
return;
}
F_257 ( V_210 ) ;
}
static void F_210 ( struct V_27 * V_28 )
{
F_144 ( & V_28 -> V_332 ) ;
}
static void F_213 ( struct V_27 * V_28 )
{
if ( F_97 ( & V_28 -> V_332 ) )
F_225 ( & V_28 -> V_333 ) ;
}
static void F_360 ( struct V_220 * V_152 )
{
struct V_27 * V_28 = V_152 -> V_213 ;
unsigned long V_70 ;
F_66 ( & V_28 -> V_22 -> V_17 , V_70 ) ;
F_361 ( & V_28 -> V_62 ) ;
F_67 ( & V_28 -> V_22 -> V_17 , V_70 ) ;
F_362 () ;
F_213 ( V_28 ) ;
F_229 ( & V_28 -> V_333 ) ;
F_291 ( & V_59 . V_60 ) ;
F_288 ( V_28 -> V_22 ) ;
F_363 ( V_28 -> V_2 ) ;
F_292 ( V_152 , V_28 -> V_37 ) ;
if ( V_28 -> V_85 )
F_292 ( V_152 , V_28 -> V_85 ) ;
F_270 ( V_28 ) ;
F_293 ( & V_59 . V_60 ) ;
}
static int F_364 ( struct V_220 * V_152 , unsigned V_269 , char * * V_280 )
{
int V_40 ;
struct V_27 * V_28 ;
struct V_133 * V_37 , * V_85 ;
struct V_63 * V_66 ;
unsigned long V_70 ;
F_291 ( & V_59 . V_60 ) ;
if ( V_269 != 2 && V_269 != 3 ) {
V_152 -> error = L_52 ;
V_40 = - V_148 ;
goto V_283;
}
V_28 = V_152 -> V_213 = F_310 ( sizeof( * V_28 ) , V_249 ) ;
if ( ! V_28 ) {
V_152 -> error = L_110 ;
V_40 = - V_125 ;
goto V_283;
}
V_28 -> V_301 = F_311 ( V_152 -> V_153 ) ;
F_283 ( & V_28 -> V_17 ) ;
F_51 ( & V_28 -> V_73 ) ;
F_62 ( & V_28 -> V_74 ) ;
F_62 ( & V_28 -> V_75 ) ;
V_28 -> V_179 = V_334 ;
if ( V_269 == 3 ) {
V_40 = F_307 ( V_152 , V_280 [ 2 ] , V_284 , & V_85 ) ;
if ( V_40 ) {
V_152 -> error = L_111 ;
goto V_335;
}
V_28 -> V_85 = V_85 ;
}
V_40 = F_307 ( V_152 , V_280 [ 0 ] , F_365 ( V_152 -> V_153 ) , & V_37 ) ;
if ( V_40 ) {
V_152 -> error = L_112 ;
goto V_336;
}
V_28 -> V_37 = V_37 ;
if ( F_333 ( V_280 [ 1 ] , ( unsigned long long * ) & V_28 -> V_305 , 0 ) ) {
V_152 -> error = L_113 ;
V_40 = - V_148 ;
goto V_337;
}
V_66 = F_366 ( V_28 -> V_37 -> V_38 -> V_326 ) ;
if ( ! V_66 ) {
V_152 -> error = L_114 ;
V_40 = - V_148 ;
goto V_337;
}
V_28 -> V_22 = F_57 ( V_66 ) ;
if ( ! V_28 -> V_22 ) {
V_152 -> error = L_115 ;
V_40 = - V_148 ;
goto V_338;
}
F_287 ( V_28 -> V_22 ) ;
if ( F_149 ( V_28 -> V_22 ) == V_158 ) {
V_152 -> error = L_116 ;
V_40 = - V_148 ;
goto V_250;
}
V_40 = F_367 ( V_28 -> V_22 -> V_114 , V_28 -> V_305 , & V_28 -> V_2 ) ;
if ( V_40 ) {
V_152 -> error = L_117 ;
goto V_250;
}
V_40 = F_368 ( V_152 , V_28 -> V_22 -> V_24 ) ;
if ( V_40 )
goto V_339;
V_152 -> V_291 = 1 ;
V_152 -> V_340 = true ;
V_152 -> V_341 = sizeof( struct V_87 ) ;
if ( V_28 -> V_22 -> V_139 . V_243 ) {
V_152 -> V_293 = true ;
V_152 -> V_292 = 1 ;
V_152 -> V_342 = false ;
}
F_293 ( & V_59 . V_60 ) ;
F_66 ( & V_28 -> V_22 -> V_17 , V_70 ) ;
if ( V_28 -> V_22 -> V_257 ) {
F_67 ( & V_28 -> V_22 -> V_17 , V_70 ) ;
F_291 ( & V_59 . V_60 ) ;
V_152 -> error = L_118 ;
V_40 = - V_148 ;
goto V_339;
}
F_141 ( & V_28 -> V_332 , 1 ) ;
F_228 ( & V_28 -> V_333 ) ;
F_369 ( & V_28 -> V_62 , & V_28 -> V_22 -> V_194 ) ;
F_67 ( & V_28 -> V_22 -> V_17 , V_70 ) ;
F_362 () ;
F_370 ( V_66 ) ;
return 0 ;
V_339:
F_363 ( V_28 -> V_2 ) ;
V_250:
F_288 ( V_28 -> V_22 ) ;
V_338:
F_370 ( V_66 ) ;
V_337:
F_292 ( V_152 , V_28 -> V_37 ) ;
V_336:
if ( V_28 -> V_85 )
F_292 ( V_152 , V_28 -> V_85 ) ;
V_335:
F_270 ( V_28 ) ;
V_283:
F_293 ( & V_59 . V_60 ) ;
return V_40 ;
}
static int F_371 ( struct V_220 * V_152 , struct V_29 * V_29 )
{
V_29 -> V_77 . V_78 = F_372 ( V_152 , V_29 -> V_77 . V_78 ) ;
return F_248 ( V_152 , V_29 ) ;
}
static int F_373 ( struct V_220 * V_152 , struct V_29 * V_29 ,
T_3 * V_324 )
{
unsigned long V_70 ;
struct V_87 * V_88 = F_87 ( V_29 , sizeof( struct V_87 ) ) ;
struct V_71 V_302 ;
struct V_92 * V_93 , * V_65 ;
struct V_22 * V_22 = V_88 -> V_28 -> V_22 ;
if ( V_88 -> V_168 ) {
F_51 ( & V_302 ) ;
F_374 ( V_88 -> V_168 , & V_302 ) ;
F_66 ( & V_22 -> V_17 , V_70 ) ;
F_70 (m, tmp, &work, list) {
F_56 ( & V_93 -> V_62 ) ;
F_96 ( V_93 ) ;
}
F_67 ( & V_22 -> V_17 , V_70 ) ;
}
if ( V_88 -> V_89 ) {
F_51 ( & V_302 ) ;
F_374 ( V_88 -> V_89 , & V_302 ) ;
if ( ! F_206 ( & V_302 ) ) {
F_66 ( & V_22 -> V_17 , V_70 ) ;
F_70 (m, tmp, &work, list)
F_98 ( & V_93 -> V_62 , & V_22 -> V_199 ) ;
F_67 ( & V_22 -> V_17 , V_70 ) ;
F_30 ( V_22 ) ;
}
}
if ( V_88 -> V_50 )
F_102 ( V_88 -> V_28 , V_88 -> V_50 ) ;
return V_343 ;
}
static void F_375 ( struct V_220 * V_152 )
{
struct V_27 * V_28 = V_152 -> V_213 ;
if ( F_376 ( V_152 ) )
V_205 ( V_28 , F_231 ) ;
}
static void F_377 ( struct V_220 * V_152 )
{
struct V_27 * V_28 = V_152 -> V_213 ;
V_205 ( V_28 , F_232 ) ;
}
static int F_378 ( struct V_220 * V_152 )
{
struct V_27 * V_28 = V_152 -> V_213 ;
if ( V_28 -> V_85 )
V_28 -> V_143 = F_298 ( V_28 -> V_85 -> V_38 ) ;
return 0 ;
}
static void F_379 ( struct V_220 * V_152 , T_9 type ,
unsigned V_314 , char * V_154 , unsigned V_313 )
{
int V_40 ;
T_12 V_312 = 0 ;
T_1 V_344 , V_345 ;
char V_239 [ V_240 ] ;
struct V_27 * V_28 = V_152 -> V_213 ;
if ( F_149 ( V_28 -> V_22 ) == V_158 ) {
F_348 ( L_92 ) ;
return;
}
if ( ! V_28 -> V_2 )
F_348 ( L_119 ) ;
else {
switch ( type ) {
case V_322 :
V_40 = F_380 ( V_28 -> V_2 , & V_344 ) ;
if ( V_40 ) {
F_239 ( L_120 , V_40 ) ;
goto V_324;
}
V_40 = F_381 ( V_28 -> V_2 , & V_345 ) ;
if ( V_40 < 0 ) {
F_239 ( L_121 , V_40 ) ;
goto V_324;
}
F_348 ( L_100 , V_344 * V_28 -> V_22 -> V_24 ) ;
if ( V_40 )
F_348 ( L_122 , ( ( V_345 + 1 ) *
V_28 -> V_22 -> V_24 ) - 1 ) ;
else
F_348 ( L_119 ) ;
break;
case V_325 :
F_348 ( L_123 ,
F_354 ( V_239 , V_28 -> V_37 -> V_38 -> V_326 ) ,
( unsigned long ) V_28 -> V_305 ) ;
if ( V_28 -> V_85 )
F_348 ( L_124 , F_354 ( V_239 , V_28 -> V_85 -> V_38 -> V_326 ) ) ;
break;
}
}
return;
V_324:
F_348 ( L_109 ) ;
}
static int F_382 ( struct V_220 * V_152 ,
T_11 F_39 , void * V_327 )
{
T_2 V_346 ;
struct V_27 * V_28 = V_152 -> V_213 ;
struct V_22 * V_22 = V_28 -> V_22 ;
if ( ! V_22 -> V_152 )
return 0 ;
V_346 = V_22 -> V_152 -> V_36 ;
( void ) F_78 ( V_346 , V_22 -> V_24 ) ;
if ( V_346 )
return F_39 ( V_152 , V_28 -> V_37 , 0 , V_22 -> V_24 * V_346 , V_327 ) ;
return 0 ;
}
static void F_383 ( struct V_220 * V_152 , struct V_235 * V_237 )
{
struct V_27 * V_28 = V_152 -> V_213 ;
struct V_22 * V_22 = V_28 -> V_22 ;
if ( ! V_22 -> V_139 . V_243 )
return;
V_237 -> V_331 = V_22 -> V_24 << V_82 ;
V_237 -> V_241 = 2048 * 1024 * 16 ;
}
static int T_13 F_384 ( void )
{
int V_40 ;
F_49 () ;
V_40 = F_385 ( & V_347 ) ;
if ( V_40 )
return V_40 ;
V_40 = F_385 ( & V_348 ) ;
if ( V_40 )
goto V_349;
V_40 = - V_125 ;
V_261 = F_386 ( V_92 , 0 ) ;
if ( ! V_261 )
goto V_350;
return 0 ;
V_350:
F_387 ( & V_348 ) ;
V_349:
F_387 ( & V_347 ) ;
return V_40 ;
}
static void F_388 ( void )
{
F_387 ( & V_347 ) ;
F_387 ( & V_348 ) ;
F_389 ( V_261 ) ;
}
