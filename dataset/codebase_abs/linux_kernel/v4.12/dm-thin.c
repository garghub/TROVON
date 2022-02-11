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
return F_82 ( V_29 -> V_86 ) &&
F_83 ( V_28 -> V_2 ) ;
}
static void F_84 ( struct V_22 * V_22 , struct V_29 * V_29 )
{
struct V_87 * V_88 ;
if ( F_85 ( V_29 ) == V_41 )
return;
V_88 = F_86 ( V_29 , sizeof( struct V_87 ) ) ;
V_88 -> V_89 = F_87 ( V_22 -> V_90 ) ;
}
static void F_88 ( struct V_27 * V_28 , struct V_29 * V_29 )
{
struct V_22 * V_22 = V_28 -> V_22 ;
unsigned long V_70 ;
if ( ! F_81 ( V_28 , V_29 ) ) {
F_89 ( V_29 ) ;
return;
}
if ( F_90 ( V_28 -> V_2 ) ) {
F_91 ( V_29 ) ;
return;
}
F_65 ( & V_22 -> V_17 , V_70 ) ;
F_92 ( & V_22 -> V_91 , V_29 ) ;
F_66 ( & V_22 -> V_17 , V_70 ) ;
}
static void F_93 ( struct V_27 * V_28 , struct V_29 * V_29 )
{
F_80 ( V_28 , V_29 ) ;
F_88 ( V_28 , V_29 ) ;
}
static void F_94 ( struct V_27 * V_28 , struct V_29 * V_29 ,
T_1 V_83 )
{
F_79 ( V_28 , V_29 , V_83 ) ;
F_88 ( V_28 , V_29 ) ;
}
static void F_95 ( struct V_92 * V_93 )
{
struct V_22 * V_22 = V_93 -> V_28 -> V_22 ;
if ( F_96 ( & V_93 -> V_94 ) ) {
F_97 ( & V_93 -> V_62 , & V_22 -> V_95 ) ;
F_29 ( V_22 ) ;
}
}
static void F_98 ( struct V_92 * V_93 )
{
unsigned long V_70 ;
struct V_22 * V_22 = V_93 -> V_28 -> V_22 ;
F_65 ( & V_22 -> V_17 , V_70 ) ;
F_95 ( V_93 ) ;
F_66 ( & V_22 -> V_17 , V_70 ) ;
}
static void F_99 ( int V_96 , unsigned long V_97 , void * V_53 )
{
struct V_92 * V_93 = V_53 ;
V_93 -> V_98 = V_96 || V_97 ? - V_57 : 0 ;
F_98 ( V_93 ) ;
}
static void F_100 ( struct V_29 * V_29 )
{
struct V_87 * V_88 = F_86 ( V_29 , sizeof( struct V_87 ) ) ;
struct V_92 * V_93 = V_88 -> V_99 ;
V_29 -> V_100 = V_93 -> V_101 ;
V_93 -> V_98 = V_29 -> V_42 ;
F_98 ( V_93 ) ;
}
static void F_101 ( struct V_27 * V_28 , struct V_45 * V_50 )
{
struct V_22 * V_22 = V_28 -> V_22 ;
unsigned long V_70 ;
F_65 ( & V_28 -> V_17 , V_70 ) ;
F_40 ( V_22 , V_50 , & V_28 -> V_74 ) ;
F_66 ( & V_28 -> V_17 , V_70 ) ;
F_29 ( V_22 ) ;
}
static void F_102 ( void * V_53 ,
struct V_45 * V_50 )
{
struct V_102 * V_103 = V_53 ;
struct V_29 * V_29 ;
while ( ( V_29 = F_63 ( & V_50 -> V_52 ) ) ) {
if ( F_82 ( V_29 -> V_86 ) || F_85 ( V_29 ) == V_41 )
F_92 ( & V_103 -> V_104 , V_29 ) ;
else {
F_84 ( V_103 -> V_28 -> V_22 , V_29 ) ;
F_92 ( & V_103 -> V_105 , V_29 ) ;
}
}
}
static void F_103 ( struct V_27 * V_28 ,
struct V_45 * V_50 ,
T_1 V_83 )
{
struct V_29 * V_29 ;
struct V_102 V_103 ;
V_103 . V_28 = V_28 ;
F_61 ( & V_103 . V_104 ) ;
F_61 ( & V_103 . V_105 ) ;
F_37 ( V_28 -> V_22 , F_102 ,
& V_103 , V_50 ) ;
while ( ( V_29 = F_63 ( & V_103 . V_104 ) ) )
F_104 ( V_28 , V_29 ) ;
while ( ( V_29 = F_63 ( & V_103 . V_105 ) ) )
F_94 ( V_103 . V_28 , V_29 , V_83 ) ;
}
static void F_105 ( struct V_92 * V_93 )
{
F_45 ( V_93 -> V_28 -> V_22 , V_93 -> V_50 ) ;
F_55 ( & V_93 -> V_62 ) ;
F_106 ( V_93 , V_93 -> V_28 -> V_22 -> V_106 ) ;
}
static void F_107 ( struct V_92 * V_93 )
{
struct V_27 * V_28 = V_93 -> V_28 ;
struct V_22 * V_22 = V_28 -> V_22 ;
struct V_29 * V_29 = V_93 -> V_29 ;
int V_40 ;
if ( V_93 -> V_98 ) {
F_45 ( V_22 , V_93 -> V_50 ) ;
goto V_107;
}
V_40 = F_108 ( V_28 -> V_2 , V_93 -> V_108 , V_93 -> V_109 ) ;
if ( V_40 ) {
F_109 ( V_22 , L_1 , V_40 ) ;
F_45 ( V_22 , V_93 -> V_50 ) ;
goto V_107;
}
if ( V_29 ) {
F_103 ( V_28 , V_93 -> V_50 , V_93 -> V_109 ) ;
F_28 ( V_29 ) ;
} else {
F_84 ( V_28 -> V_22 , V_93 -> V_50 -> V_110 ) ;
F_94 ( V_28 , V_93 -> V_50 -> V_110 , V_93 -> V_109 ) ;
F_103 ( V_28 , V_93 -> V_50 , V_93 -> V_109 ) ;
}
V_107:
F_55 ( & V_93 -> V_62 ) ;
F_106 ( V_93 , V_22 -> V_106 ) ;
}
static void F_110 ( struct V_92 * V_93 )
{
struct V_27 * V_28 = V_93 -> V_28 ;
if ( V_93 -> V_50 )
F_101 ( V_28 , V_93 -> V_50 ) ;
F_106 ( V_93 , V_28 -> V_22 -> V_106 ) ;
}
static void F_111 ( struct V_92 * V_93 )
{
F_91 ( V_93 -> V_29 ) ;
F_110 ( V_93 ) ;
}
static void F_112 ( struct V_92 * V_93 )
{
F_28 ( V_93 -> V_29 ) ;
F_110 ( V_93 ) ;
}
static void F_113 ( struct V_92 * V_93 )
{
int V_40 ;
struct V_27 * V_28 = V_93 -> V_28 ;
V_40 = F_114 ( V_28 -> V_2 , V_93 -> V_50 -> V_8 . V_12 , V_93 -> V_50 -> V_8 . V_13 ) ;
if ( V_40 ) {
F_109 ( V_28 -> V_22 , L_2 , V_40 ) ;
F_91 ( V_93 -> V_29 ) ;
} else
F_28 ( V_93 -> V_29 ) ;
F_101 ( V_28 , V_93 -> V_50 ) ;
F_106 ( V_93 , V_28 -> V_22 -> V_106 ) ;
}
static void F_115 ( struct V_92 * V_93 ,
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
V_40 = F_116 ( V_22 -> V_114 , V_5 , & V_112 ) ;
if ( V_40 )
goto V_107;
if ( ! V_112 )
break;
}
if ( V_5 == V_80 )
break;
for ( V_6 = V_5 + 1 ; V_6 != V_80 ; V_6 ++ ) {
V_40 = F_116 ( V_22 -> V_114 , V_6 , & V_112 ) ;
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
static void F_117 ( struct V_92 * V_93 )
{
unsigned long V_70 ;
struct V_22 * V_22 = V_93 -> V_28 -> V_22 ;
F_65 ( & V_22 -> V_17 , V_70 ) ;
F_97 ( & V_93 -> V_62 , & V_22 -> V_115 ) ;
F_66 ( & V_22 -> V_17 , V_70 ) ;
F_29 ( V_22 ) ;
}
static void F_118 ( struct V_29 * V_29 )
{
F_117 ( V_29 -> V_116 ) ;
F_119 ( V_29 ) ;
}
static void F_120 ( struct V_92 * V_93 )
{
int V_40 ;
struct V_27 * V_28 = V_93 -> V_28 ;
struct V_22 * V_22 = V_28 -> V_22 ;
struct V_29 * V_111 ;
T_1 V_117 = V_93 -> V_109 + ( V_93 -> V_113 - V_93 -> V_108 ) ;
V_40 = F_114 ( V_28 -> V_2 , V_93 -> V_108 , V_93 -> V_113 ) ;
if ( V_40 ) {
F_109 ( V_22 , L_2 , V_40 ) ;
F_91 ( V_93 -> V_29 ) ;
F_101 ( V_28 , V_93 -> V_50 ) ;
F_106 ( V_93 , V_22 -> V_106 ) ;
return;
}
V_40 = F_121 ( V_22 -> V_114 , V_93 -> V_109 , V_117 ) ;
if ( V_40 ) {
F_109 ( V_22 , L_3 , V_40 ) ;
F_91 ( V_93 -> V_29 ) ;
F_101 ( V_28 , V_93 -> V_50 ) ;
F_106 ( V_93 , V_22 -> V_106 ) ;
return;
}
V_111 = F_122 ( V_49 , 1 ) ;
if ( ! V_111 ) {
F_123 ( L_4 ,
F_124 ( V_28 -> V_22 -> V_66 ) ) ;
F_117 ( V_93 ) ;
} else {
V_111 -> V_100 = F_118 ;
V_111 -> V_116 = V_93 ;
if ( V_93 -> V_118 )
F_115 ( V_93 , V_111 ) ;
else {
struct V_25 V_26 ;
F_18 ( & V_26 , V_28 , V_111 ) ;
V_40 = F_21 ( & V_26 , V_93 -> V_109 , V_117 ) ;
F_23 ( & V_26 , V_40 ) ;
}
}
}
static void F_125 ( struct V_92 * V_93 )
{
int V_40 ;
struct V_27 * V_28 = V_93 -> V_28 ;
struct V_22 * V_22 = V_28 -> V_22 ;
V_40 = F_126 ( V_22 -> V_114 , V_93 -> V_109 ,
V_93 -> V_109 + ( V_93 -> V_113 - V_93 -> V_108 ) ) ;
if ( V_40 ) {
F_109 ( V_22 , L_5 , V_40 ) ;
F_91 ( V_93 -> V_29 ) ;
} else
F_28 ( V_93 -> V_29 ) ;
F_101 ( V_28 , V_93 -> V_50 ) ;
F_106 ( V_93 , V_22 -> V_106 ) ;
}
static void F_127 ( struct V_22 * V_22 , struct V_71 * V_119 ,
T_3 * F_38 )
{
unsigned long V_70 ;
struct V_71 V_120 ;
struct V_92 * V_93 , * V_65 ;
F_50 ( & V_120 ) ;
F_65 ( & V_22 -> V_17 , V_70 ) ;
F_68 ( V_119 , & V_120 ) ;
F_66 ( & V_22 -> V_17 , V_70 ) ;
F_69 ( V_93 , V_65 , & V_120 , V_62 )
( * F_38 ) ( V_93 ) ;
}
static int F_128 ( struct V_22 * V_22 , struct V_29 * V_29 )
{
return V_29 -> V_77 . V_81 ==
( V_22 -> V_24 << V_82 ) ;
}
static int F_129 ( struct V_22 * V_22 , struct V_29 * V_29 )
{
return ( F_130 ( V_29 ) == V_121 ) &&
F_128 ( V_22 , V_29 ) ;
}
static void F_131 ( struct V_29 * V_29 , T_4 * * V_122 ,
T_4 * F_38 )
{
* V_122 = V_29 -> V_100 ;
V_29 -> V_100 = F_38 ;
}
static int F_132 ( struct V_22 * V_22 )
{
if ( V_22 -> V_123 )
return 0 ;
V_22 -> V_123 = F_133 ( V_22 -> V_106 , V_124 ) ;
return V_22 -> V_123 ? 0 : - V_125 ;
}
static struct V_92 * F_134 ( struct V_22 * V_22 )
{
struct V_92 * V_93 = V_22 -> V_123 ;
F_19 ( ! V_22 -> V_123 ) ;
memset ( V_93 , 0 , sizeof( struct V_92 ) ) ;
F_50 ( & V_93 -> V_62 ) ;
V_93 -> V_29 = NULL ;
V_22 -> V_123 = NULL ;
return V_93 ;
}
static void F_135 ( struct V_27 * V_28 , struct V_92 * V_93 ,
T_2 V_79 , T_2 V_80 )
{
int V_40 ;
struct V_126 V_127 ;
V_127 . V_38 = V_28 -> V_37 -> V_38 ;
V_127 . V_128 = V_79 ;
V_127 . V_129 = V_80 - V_79 ;
V_40 = F_136 ( V_28 -> V_22 -> V_130 , 1 , & V_127 , 0 , F_99 , V_93 ) ;
if ( V_40 < 0 ) {
F_137 ( L_6 ) ;
F_99 ( 1 , 1 , V_93 ) ;
}
}
static void F_138 ( struct V_27 * V_28 , struct V_29 * V_29 ,
T_1 V_131 ,
struct V_92 * V_93 )
{
struct V_22 * V_22 = V_28 -> V_22 ;
struct V_87 * V_88 = F_86 ( V_29 , sizeof( struct V_87 ) ) ;
V_88 -> V_99 = V_93 ;
V_93 -> V_29 = V_29 ;
F_131 ( V_29 , & V_93 -> V_101 , F_100 ) ;
F_84 ( V_22 , V_29 ) ;
F_94 ( V_28 , V_29 , V_131 ) ;
}
static void F_139 ( struct V_27 * V_28 , T_1 V_132 ,
struct V_133 * V_134 , T_1 V_135 ,
T_1 V_136 ,
struct V_45 * V_50 , struct V_29 * V_29 ,
T_2 V_36 )
{
int V_40 ;
struct V_22 * V_22 = V_28 -> V_22 ;
struct V_92 * V_93 = F_134 ( V_22 ) ;
V_93 -> V_28 = V_28 ;
V_93 -> V_108 = V_132 ;
V_93 -> V_113 = V_132 + 1u ;
V_93 -> V_109 = V_136 ;
V_93 -> V_50 = V_50 ;
F_140 ( & V_93 -> V_94 , 3 ) ;
if ( ! F_141 ( V_22 -> V_137 , & V_93 -> V_62 ) )
F_98 ( V_93 ) ;
if ( F_129 ( V_22 , V_29 ) )
F_138 ( V_28 , V_29 , V_136 , V_93 ) ;
else {
struct V_126 V_138 , V_127 ;
V_138 . V_38 = V_134 -> V_38 ;
V_138 . V_128 = V_135 * V_22 -> V_24 ;
V_138 . V_129 = V_36 ;
V_127 . V_38 = V_28 -> V_37 -> V_38 ;
V_127 . V_128 = V_136 * V_22 -> V_24 ;
V_127 . V_129 = V_36 ;
V_40 = F_142 ( V_22 -> V_130 , & V_138 , 1 , & V_127 ,
0 , F_99 , V_93 ) ;
if ( V_40 < 0 ) {
F_137 ( L_7 ) ;
F_99 ( 1 , 1 , V_93 ) ;
}
if ( V_36 < V_22 -> V_24 && V_22 -> V_139 . V_140 ) {
F_143 ( & V_93 -> V_94 ) ;
F_135 ( V_28 , V_93 ,
V_136 * V_22 -> V_24 + V_36 ,
( V_136 + 1 ) * V_22 -> V_24 ) ;
}
}
F_98 ( V_93 ) ;
}
static void F_144 ( struct V_27 * V_28 , T_1 V_132 ,
T_1 V_135 , T_1 V_136 ,
struct V_45 * V_50 , struct V_29 * V_29 )
{
F_139 ( V_28 , V_132 , V_28 -> V_37 ,
V_135 , V_136 , V_50 , V_29 ,
V_28 -> V_22 -> V_24 ) ;
}
static void F_145 ( struct V_27 * V_28 , T_1 V_132 ,
T_1 V_109 , struct V_45 * V_50 ,
struct V_29 * V_29 )
{
struct V_22 * V_22 = V_28 -> V_22 ;
struct V_92 * V_93 = F_134 ( V_22 ) ;
F_140 ( & V_93 -> V_94 , 1 ) ;
V_93 -> V_28 = V_28 ;
V_93 -> V_108 = V_132 ;
V_93 -> V_113 = V_132 + 1u ;
V_93 -> V_109 = V_109 ;
V_93 -> V_50 = V_50 ;
if ( V_22 -> V_139 . V_140 ) {
if ( F_129 ( V_22 , V_29 ) )
F_138 ( V_28 , V_29 , V_109 , V_93 ) ;
else
F_135 ( V_28 , V_93 , V_109 * V_22 -> V_24 ,
( V_109 + 1 ) * V_22 -> V_24 ) ;
} else
F_107 ( V_93 ) ;
}
static void F_146 ( struct V_27 * V_28 , T_1 V_132 ,
T_1 V_136 ,
struct V_45 * V_50 , struct V_29 * V_29 )
{
struct V_22 * V_22 = V_28 -> V_22 ;
T_2 V_141 = V_132 * V_22 -> V_24 ;
T_2 V_142 = ( V_132 + 1 ) * V_22 -> V_24 ;
if ( V_142 <= V_28 -> V_143 )
F_139 ( V_28 , V_132 , V_28 -> V_85 ,
V_132 , V_136 , V_50 , V_29 ,
V_22 -> V_24 ) ;
else if ( V_141 < V_28 -> V_143 )
F_139 ( V_28 , V_132 , V_28 -> V_85 ,
V_132 , V_136 , V_50 , V_29 ,
V_28 -> V_143 - V_141 ) ;
else
F_145 ( V_28 , V_132 , V_136 , V_50 , V_29 ) ;
}
static void F_147 ( struct V_22 * V_22 )
{
int V_40 ;
T_1 V_144 ;
if ( F_148 ( V_22 ) != V_145 )
return;
V_40 = F_149 ( V_22 -> V_114 , & V_144 ) ;
if ( V_40 )
return;
if ( V_144 )
F_150 ( V_22 , V_146 ) ;
}
static int F_151 ( struct V_22 * V_22 )
{
int V_40 ;
if ( F_148 ( V_22 ) >= V_147 )
return - V_148 ;
V_40 = F_152 ( V_22 -> V_114 ) ;
if ( V_40 )
F_109 ( V_22 , L_8 , V_40 ) ;
else
F_147 ( V_22 ) ;
return V_40 ;
}
static void F_153 ( struct V_22 * V_22 , T_1 V_149 )
{
unsigned long V_70 ;
if ( V_149 <= V_22 -> V_150 && ! V_22 -> V_151 ) {
F_123 ( L_9 ,
F_124 ( V_22 -> V_66 ) ) ;
F_65 ( & V_22 -> V_17 , V_70 ) ;
V_22 -> V_151 = true ;
F_66 ( & V_22 -> V_17 , V_70 ) ;
F_154 ( V_22 -> V_152 -> V_153 ) ;
}
}
static int F_155 ( struct V_27 * V_28 , T_1 * V_154 )
{
int V_40 ;
T_1 V_149 ;
struct V_22 * V_22 = V_28 -> V_22 ;
if ( F_156 ( F_148 ( V_22 ) != V_146 ) )
return - V_148 ;
V_40 = F_149 ( V_22 -> V_114 , & V_149 ) ;
if ( V_40 ) {
F_109 ( V_22 , L_10 , V_40 ) ;
return V_40 ;
}
F_153 ( V_22 , V_149 ) ;
if ( ! V_149 ) {
V_40 = F_151 ( V_22 ) ;
if ( V_40 )
return V_40 ;
V_40 = F_149 ( V_22 -> V_114 , & V_149 ) ;
if ( V_40 ) {
F_109 ( V_22 , L_10 , V_40 ) ;
return V_40 ;
}
if ( ! V_149 ) {
F_150 ( V_22 , V_145 ) ;
return - V_56 ;
}
}
V_40 = F_157 ( V_22 -> V_114 , V_154 ) ;
if ( V_40 ) {
F_109 ( V_22 , L_11 , V_40 ) ;
return V_40 ;
}
return 0 ;
}
static void F_158 ( struct V_29 * V_29 )
{
struct V_87 * V_88 = F_86 ( V_29 , sizeof( struct V_87 ) ) ;
struct V_27 * V_28 = V_88 -> V_28 ;
unsigned long V_70 ;
F_65 ( & V_28 -> V_17 , V_70 ) ;
F_92 ( & V_28 -> V_75 , V_29 ) ;
F_66 ( & V_28 -> V_17 , V_70 ) ;
}
static int F_159 ( struct V_22 * V_22 )
{
enum V_155 V_93 = F_148 ( V_22 ) ;
switch ( V_93 ) {
case V_146 :
F_137 ( L_12 ) ;
return - V_57 ;
case V_145 :
return V_22 -> V_139 . V_156 ? - V_56 : 0 ;
case V_147 :
case V_157 :
return - V_57 ;
default:
F_137 ( L_13 ) ;
return - V_57 ;
}
}
static void F_160 ( struct V_22 * V_22 , struct V_29 * V_29 )
{
int error = F_159 ( V_22 ) ;
if ( error ) {
V_29 -> V_42 = error ;
F_28 ( V_29 ) ;
} else
F_158 ( V_29 ) ;
}
static void F_161 ( struct V_22 * V_22 , struct V_45 * V_50 )
{
struct V_29 * V_29 ;
struct V_51 V_52 ;
int error ;
error = F_159 ( V_22 ) ;
if ( error ) {
F_42 ( V_22 , V_50 , error ) ;
return;
}
F_61 ( & V_52 ) ;
F_35 ( V_22 , V_50 , & V_52 ) ;
while ( ( V_29 = F_63 ( & V_52 ) ) )
F_158 ( V_29 ) ;
}
static void F_162 ( struct V_27 * V_28 ,
struct V_45 * V_158 )
{
struct V_22 * V_22 = V_28 -> V_22 ;
struct V_92 * V_93 = F_134 ( V_22 ) ;
V_93 -> V_28 = V_28 ;
V_93 -> V_108 = V_158 -> V_8 . V_12 ;
V_93 -> V_113 = V_158 -> V_8 . V_13 ;
V_93 -> V_50 = V_158 ;
V_93 -> V_29 = V_158 -> V_110 ;
if ( ! F_141 ( V_22 -> V_90 , & V_93 -> V_62 ) )
V_22 -> V_159 ( V_93 ) ;
}
static void F_163 ( struct V_27 * V_28 , T_1 V_79 , T_1 V_80 ,
struct V_29 * V_29 )
{
struct V_22 * V_22 = V_28 -> V_22 ;
int V_40 ;
bool V_118 ;
struct V_7 V_160 ;
struct V_45 * V_161 ;
struct V_92 * V_93 ;
T_1 V_108 , V_113 , V_131 ;
while ( V_79 != V_80 ) {
V_40 = F_132 ( V_22 ) ;
if ( V_40 )
return;
V_40 = F_164 ( V_28 -> V_2 , V_79 , V_80 , & V_108 , & V_113 ,
& V_131 , & V_118 ) ;
if ( V_40 )
break;
F_1 ( V_28 -> V_2 , V_14 , V_131 , V_131 + ( V_113 - V_108 ) , & V_160 ) ;
if ( F_31 ( V_28 -> V_22 , & V_160 , NULL , & V_161 ) ) {
V_79 = V_113 ;
continue;
}
V_93 = F_134 ( V_22 ) ;
V_93 -> V_28 = V_28 ;
V_93 -> V_118 = V_118 ;
V_93 -> V_108 = V_108 ;
V_93 -> V_113 = V_113 ;
V_93 -> V_109 = V_131 ;
V_93 -> V_50 = V_161 ;
V_93 -> V_29 = V_29 ;
F_165 ( V_29 ) ;
if ( ! F_141 ( V_22 -> V_90 , & V_93 -> V_62 ) )
V_22 -> V_159 ( V_93 ) ;
V_79 = V_113 ;
}
}
static void F_166 ( struct V_27 * V_28 , struct V_45 * V_158 )
{
struct V_29 * V_29 = V_158 -> V_110 ;
struct V_87 * V_88 = F_86 ( V_29 , sizeof( struct V_87 ) ) ;
V_88 -> V_50 = V_158 ;
F_163 ( V_28 , V_158 -> V_8 . V_12 , V_158 -> V_8 . V_13 , V_29 ) ;
F_28 ( V_29 ) ;
}
static void F_167 ( struct V_27 * V_28 , struct V_29 * V_29 )
{
T_1 V_79 , V_80 ;
struct V_7 V_162 ;
struct V_45 * V_158 ;
F_78 ( V_28 , V_29 , & V_79 , & V_80 ) ;
if ( V_79 == V_80 ) {
F_28 ( V_29 ) ;
return;
}
F_1 ( V_28 -> V_2 , V_10 , V_79 , V_80 , & V_162 ) ;
if ( F_31 ( V_28 -> V_22 , & V_162 , V_29 , & V_158 ) )
return;
V_28 -> V_22 -> V_163 ( V_28 , V_158 ) ;
}
static void F_168 ( struct V_27 * V_28 , struct V_29 * V_29 , T_1 V_83 ,
struct V_7 * V_8 ,
struct V_164 * V_165 ,
struct V_45 * V_50 )
{
int V_40 ;
T_1 V_109 ;
struct V_22 * V_22 = V_28 -> V_22 ;
V_40 = F_155 ( V_28 , & V_109 ) ;
switch ( V_40 ) {
case 0 :
F_144 ( V_28 , V_83 , V_165 -> V_83 ,
V_109 , V_50 , V_29 ) ;
break;
case - V_56 :
F_161 ( V_22 , V_50 ) ;
break;
default:
F_137 ( L_14 ,
V_166 , V_40 ) ;
F_45 ( V_22 , V_50 ) ;
break;
}
}
static void F_169 ( void * V_53 ,
struct V_45 * V_50 )
{
struct V_102 * V_103 = V_53 ;
struct V_29 * V_29 ;
while ( ( V_29 = F_63 ( & V_50 -> V_52 ) ) ) {
if ( F_130 ( V_29 ) == V_121 || F_82 ( V_29 -> V_86 ) ||
F_85 ( V_29 ) == V_41 )
F_92 ( & V_103 -> V_104 , V_29 ) ;
else {
struct V_87 * V_88 = F_86 ( V_29 , sizeof( struct V_87 ) ) ; ;
V_88 -> V_167 = F_87 ( V_103 -> V_28 -> V_22 -> V_137 ) ;
F_84 ( V_103 -> V_28 -> V_22 , V_29 ) ;
F_92 ( & V_103 -> V_105 , V_29 ) ;
}
}
}
static void F_170 ( struct V_27 * V_28 ,
struct V_45 * V_50 ,
T_1 V_83 )
{
struct V_29 * V_29 ;
struct V_102 V_103 ;
V_103 . V_28 = V_28 ;
F_61 ( & V_103 . V_104 ) ;
F_61 ( & V_103 . V_105 ) ;
F_37 ( V_28 -> V_22 , F_169 ,
& V_103 , V_50 ) ;
while ( ( V_29 = F_63 ( & V_103 . V_104 ) ) )
F_104 ( V_28 , V_29 ) ;
while ( ( V_29 = F_63 ( & V_103 . V_105 ) ) )
F_94 ( V_28 , V_29 , V_83 ) ;
}
static void F_171 ( struct V_27 * V_28 , struct V_29 * V_29 ,
T_1 V_83 ,
struct V_164 * V_165 ,
struct V_45 * V_158 )
{
struct V_45 * V_161 ;
struct V_22 * V_22 = V_28 -> V_22 ;
struct V_7 V_8 ;
F_3 ( V_28 -> V_2 , V_165 -> V_83 , & V_8 ) ;
if ( F_31 ( V_22 , & V_8 , V_29 , & V_161 ) ) {
F_101 ( V_28 , V_158 ) ;
return;
}
if ( F_130 ( V_29 ) == V_121 && V_29 -> V_77 . V_81 ) {
F_168 ( V_28 , V_29 , V_83 , & V_8 , V_165 , V_161 ) ;
F_101 ( V_28 , V_158 ) ;
} else {
struct V_87 * V_88 = F_86 ( V_29 , sizeof( struct V_87 ) ) ;
V_88 -> V_167 = F_87 ( V_22 -> V_137 ) ;
F_84 ( V_22 , V_29 ) ;
F_94 ( V_28 , V_29 , V_165 -> V_83 ) ;
F_170 ( V_28 , V_161 , V_165 -> V_83 ) ;
F_170 ( V_28 , V_158 , V_165 -> V_83 ) ;
}
}
static void F_172 ( struct V_27 * V_28 , struct V_29 * V_29 , T_1 V_83 ,
struct V_45 * V_50 )
{
int V_40 ;
T_1 V_109 ;
struct V_22 * V_22 = V_28 -> V_22 ;
if ( ! V_29 -> V_77 . V_81 ) {
F_84 ( V_22 , V_29 ) ;
F_101 ( V_28 , V_50 ) ;
F_94 ( V_28 , V_29 , 0 ) ;
return;
}
if ( F_130 ( V_29 ) == V_168 ) {
F_173 ( V_29 ) ;
F_101 ( V_28 , V_50 ) ;
F_28 ( V_29 ) ;
return;
}
V_40 = F_155 ( V_28 , & V_109 ) ;
switch ( V_40 ) {
case 0 :
if ( V_28 -> V_85 )
F_146 ( V_28 , V_83 , V_109 , V_50 , V_29 ) ;
else
F_145 ( V_28 , V_83 , V_109 , V_50 , V_29 ) ;
break;
case - V_56 :
F_161 ( V_22 , V_50 ) ;
break;
default:
F_137 ( L_14 ,
V_166 , V_40 ) ;
F_45 ( V_22 , V_50 ) ;
break;
}
}
static void F_174 ( struct V_27 * V_28 , struct V_45 * V_50 )
{
int V_40 ;
struct V_22 * V_22 = V_28 -> V_22 ;
struct V_29 * V_29 = V_50 -> V_110 ;
T_1 V_83 = F_76 ( V_28 , V_29 ) ;
struct V_164 V_165 ;
if ( V_28 -> V_169 ) {
F_47 ( V_22 , V_50 ) ;
return;
}
V_40 = F_175 ( V_28 -> V_2 , V_83 , 1 , & V_165 ) ;
switch ( V_40 ) {
case 0 :
if ( V_165 . V_170 )
F_171 ( V_28 , V_29 , V_83 , & V_165 , V_50 ) ;
else {
F_84 ( V_22 , V_29 ) ;
F_94 ( V_28 , V_29 , V_165 . V_83 ) ;
F_103 ( V_28 , V_50 , V_165 . V_83 ) ;
}
break;
case - V_171 :
if ( F_130 ( V_29 ) == V_168 && V_28 -> V_85 ) {
F_84 ( V_22 , V_29 ) ;
F_101 ( V_28 , V_50 ) ;
if ( F_176 ( V_29 ) <= V_28 -> V_143 )
F_93 ( V_28 , V_29 ) ;
else if ( V_29 -> V_77 . V_78 < V_28 -> V_143 ) {
F_173 ( V_29 ) ;
V_29 -> V_77 . V_81 = ( V_28 -> V_143 - V_29 -> V_77 . V_78 ) << V_82 ;
F_93 ( V_28 , V_29 ) ;
} else {
F_173 ( V_29 ) ;
F_28 ( V_29 ) ;
}
} else
F_172 ( V_28 , V_29 , V_83 , V_50 ) ;
break;
default:
F_137 ( L_15 ,
V_166 , V_40 ) ;
F_101 ( V_28 , V_50 ) ;
F_91 ( V_29 ) ;
break;
}
}
static void F_177 ( struct V_27 * V_28 , struct V_29 * V_29 )
{
struct V_22 * V_22 = V_28 -> V_22 ;
T_1 V_83 = F_76 ( V_28 , V_29 ) ;
struct V_45 * V_50 ;
struct V_7 V_8 ;
F_4 ( V_28 -> V_2 , V_83 , & V_8 ) ;
if ( F_31 ( V_22 , & V_8 , V_29 , & V_50 ) )
return;
F_174 ( V_28 , V_50 ) ;
}
static void F_178 ( struct V_27 * V_28 , struct V_29 * V_29 ,
struct V_45 * V_50 )
{
int V_40 ;
int V_172 = F_130 ( V_29 ) ;
T_1 V_83 = F_76 ( V_28 , V_29 ) ;
struct V_164 V_165 ;
V_40 = F_175 ( V_28 -> V_2 , V_83 , 1 , & V_165 ) ;
switch ( V_40 ) {
case 0 :
if ( V_165 . V_170 && ( V_172 == V_121 ) && V_29 -> V_77 . V_81 ) {
F_160 ( V_28 -> V_22 , V_29 ) ;
if ( V_50 )
F_101 ( V_28 , V_50 ) ;
} else {
F_84 ( V_28 -> V_22 , V_29 ) ;
F_94 ( V_28 , V_29 , V_165 . V_83 ) ;
if ( V_50 )
F_103 ( V_28 , V_50 , V_165 . V_83 ) ;
}
break;
case - V_171 :
if ( V_50 )
F_101 ( V_28 , V_50 ) ;
if ( V_172 != V_168 ) {
F_160 ( V_28 -> V_22 , V_29 ) ;
break;
}
if ( V_28 -> V_85 ) {
F_84 ( V_28 -> V_22 , V_29 ) ;
F_93 ( V_28 , V_29 ) ;
break;
}
F_173 ( V_29 ) ;
F_28 ( V_29 ) ;
break;
default:
F_137 ( L_15 ,
V_166 , V_40 ) ;
if ( V_50 )
F_101 ( V_28 , V_50 ) ;
F_91 ( V_29 ) ;
break;
}
}
static void F_179 ( struct V_27 * V_28 , struct V_29 * V_29 )
{
F_178 ( V_28 , V_29 , NULL ) ;
}
static void F_180 ( struct V_27 * V_28 , struct V_45 * V_50 )
{
F_178 ( V_28 , V_50 -> V_110 , V_50 ) ;
}
static void F_181 ( struct V_27 * V_28 , struct V_29 * V_29 )
{
F_28 ( V_29 ) ;
}
static void F_182 ( struct V_27 * V_28 , struct V_29 * V_29 )
{
F_91 ( V_29 ) ;
}
static void F_183 ( struct V_27 * V_28 , struct V_45 * V_50 )
{
F_46 ( V_28 -> V_22 , V_50 ) ;
}
static void F_184 ( struct V_27 * V_28 , struct V_45 * V_50 )
{
F_45 ( V_28 -> V_22 , V_50 ) ;
}
static int F_185 ( struct V_22 * V_22 )
{
return ! F_186 ( V_20 , V_22 -> V_173 ,
V_22 -> V_173 + V_174 ) ;
}
static void F_187 ( struct V_27 * V_28 , struct V_29 * V_29 )
{
struct V_175 * * V_176 , * V_30 ;
struct V_87 * V_177 ;
T_2 V_78 = V_29 -> V_77 . V_78 ;
V_176 = & V_28 -> V_178 . V_175 ;
V_30 = NULL ;
while ( * V_176 ) {
V_30 = * V_176 ;
V_177 = F_188 ( V_30 ) ;
if ( V_78 < F_189 ( V_177 ) -> V_77 . V_78 )
V_176 = & ( * V_176 ) -> V_179 ;
else
V_176 = & ( * V_176 ) -> V_180 ;
}
V_177 = F_86 ( V_29 , sizeof( struct V_87 ) ) ;
F_190 ( & V_177 -> V_175 , V_30 , V_176 ) ;
F_191 ( & V_177 -> V_175 , & V_28 -> V_178 ) ;
}
static void F_192 ( struct V_27 * V_28 )
{
struct V_175 * V_181 ;
struct V_87 * V_177 ;
struct V_29 * V_29 ;
for ( V_181 = F_193 ( & V_28 -> V_178 ) ; V_181 ; V_181 = F_194 ( V_181 ) ) {
V_177 = F_188 ( V_181 ) ;
V_29 = F_189 ( V_177 ) ;
F_92 ( & V_28 -> V_74 , V_29 ) ;
F_195 ( & V_177 -> V_175 , & V_28 -> V_178 ) ;
}
F_156 ( ! F_196 ( & V_28 -> V_178 ) ) ;
}
static void F_197 ( struct V_27 * V_28 )
{
struct V_29 * V_29 ;
struct V_51 V_52 ;
F_61 ( & V_52 ) ;
F_60 ( & V_52 , & V_28 -> V_74 ) ;
F_61 ( & V_28 -> V_74 ) ;
while ( ( V_29 = F_63 ( & V_52 ) ) )
F_187 ( V_28 , V_29 ) ;
F_192 ( V_28 ) ;
}
static void F_198 ( struct V_27 * V_28 )
{
struct V_22 * V_22 = V_28 -> V_22 ;
unsigned long V_70 ;
struct V_29 * V_29 ;
struct V_51 V_52 ;
struct V_182 V_31 ;
unsigned V_129 = 0 ;
if ( V_28 -> V_169 ) {
F_64 ( V_28 , & V_28 -> V_74 , V_58 ) ;
return;
}
F_61 ( & V_52 ) ;
F_65 ( & V_28 -> V_17 , V_70 ) ;
if ( F_199 ( & V_28 -> V_74 ) ) {
F_66 ( & V_28 -> V_17 , V_70 ) ;
return;
}
F_197 ( V_28 ) ;
F_60 ( & V_52 , & V_28 -> V_74 ) ;
F_61 ( & V_28 -> V_74 ) ;
F_66 ( & V_28 -> V_17 , V_70 ) ;
F_20 ( & V_31 ) ;
while ( ( V_29 = F_63 ( & V_52 ) ) ) {
if ( F_132 ( V_22 ) ) {
F_65 ( & V_28 -> V_17 , V_70 ) ;
F_92 ( & V_28 -> V_74 , V_29 ) ;
F_60 ( & V_28 -> V_74 , & V_52 ) ;
F_66 ( & V_28 -> V_17 , V_70 ) ;
break;
}
if ( F_85 ( V_29 ) == V_41 )
V_22 -> V_183 ( V_28 , V_29 ) ;
else
V_22 -> F_177 ( V_28 , V_29 ) ;
if ( ( V_129 ++ & 127 ) == 0 ) {
F_8 ( & V_22 -> V_15 ) ;
F_200 ( V_22 -> V_114 ) ;
}
}
F_27 ( & V_31 ) ;
}
static int F_201 ( const void * V_184 , const void * V_185 )
{
struct V_45 * V_186 = * ( (struct V_45 * * ) V_184 ) ;
struct V_45 * V_187 = * ( (struct V_45 * * ) V_185 ) ;
F_19 ( ! V_186 -> V_110 ) ;
F_19 ( ! V_187 -> V_110 ) ;
if ( V_186 -> V_110 -> V_77 . V_78 < V_187 -> V_110 -> V_77 . V_78 )
return - 1 ;
if ( V_186 -> V_110 -> V_77 . V_78 > V_187 -> V_110 -> V_77 . V_78 )
return 1 ;
return 0 ;
}
static unsigned F_202 ( struct V_22 * V_22 , struct V_71 * V_72 )
{
unsigned V_129 = 0 ;
struct V_45 * V_50 , * V_65 ;
F_69 (cell, tmp, cells, user_list) {
if ( V_129 >= V_188 )
break;
V_22 -> V_189 [ V_129 ++ ] = V_50 ;
F_55 ( & V_50 -> V_190 ) ;
}
F_203 ( V_22 -> V_189 , V_129 , sizeof( V_50 ) , F_201 , NULL ) ;
return V_129 ;
}
static void F_204 ( struct V_27 * V_28 )
{
struct V_22 * V_22 = V_28 -> V_22 ;
unsigned long V_70 ;
struct V_71 V_72 ;
struct V_45 * V_50 ;
unsigned V_191 , V_192 , V_129 ;
F_50 ( & V_72 ) ;
F_65 ( & V_28 -> V_17 , V_70 ) ;
F_68 ( & V_28 -> V_73 , & V_72 ) ;
F_66 ( & V_28 -> V_17 , V_70 ) ;
if ( F_205 ( & V_72 ) )
return;
do {
V_129 = F_202 ( V_28 -> V_22 , & V_72 ) ;
for ( V_191 = 0 ; V_191 < V_129 ; V_191 ++ ) {
V_50 = V_22 -> V_189 [ V_191 ] ;
F_19 ( ! V_50 -> V_110 ) ;
if ( F_132 ( V_22 ) ) {
for ( V_192 = V_191 ; V_192 < V_129 ; V_192 ++ )
F_53 ( & V_22 -> V_189 [ V_192 ] -> V_190 , & V_72 ) ;
F_65 ( & V_28 -> V_17 , V_70 ) ;
F_206 ( & V_72 , & V_28 -> V_73 ) ;
F_66 ( & V_28 -> V_17 , V_70 ) ;
return;
}
if ( F_85 ( V_50 -> V_110 ) == V_41 )
V_22 -> V_163 ( V_28 , V_50 ) ;
else
V_22 -> F_174 ( V_28 , V_50 ) ;
}
} while ( ! F_205 ( & V_72 ) );
}
static struct V_27 * F_207 ( struct V_22 * V_22 )
{
struct V_27 * V_28 = NULL ;
F_72 () ;
if ( ! F_205 ( & V_22 -> V_193 ) ) {
V_28 = F_208 ( V_22 -> V_193 . V_194 , struct V_27 , V_62 ) ;
F_209 ( V_28 ) ;
}
F_74 () ;
return V_28 ;
}
static struct V_27 * F_210 ( struct V_22 * V_22 , struct V_27 * V_28 )
{
struct V_27 * V_195 = V_28 ;
F_72 () ;
F_211 (tc, &pool->active_thins, list) {
F_209 ( V_28 ) ;
F_212 ( V_195 ) ;
F_74 () ;
return V_28 ;
}
F_212 ( V_195 ) ;
F_74 () ;
return NULL ;
}
static void F_213 ( struct V_22 * V_22 )
{
unsigned long V_70 ;
struct V_29 * V_29 ;
struct V_51 V_52 ;
struct V_27 * V_28 ;
V_28 = F_207 ( V_22 ) ;
while ( V_28 ) {
F_204 ( V_28 ) ;
F_198 ( V_28 ) ;
V_28 = F_210 ( V_22 , V_28 ) ;
}
F_61 ( & V_52 ) ;
F_65 ( & V_22 -> V_17 , V_70 ) ;
F_60 ( & V_52 , & V_22 -> V_91 ) ;
F_61 ( & V_22 -> V_91 ) ;
F_66 ( & V_22 -> V_17 , V_70 ) ;
if ( F_199 ( & V_52 ) &&
! ( F_214 ( V_22 -> V_114 ) && F_185 ( V_22 ) ) )
return;
if ( F_151 ( V_22 ) ) {
while ( ( V_29 = F_63 ( & V_52 ) ) )
F_91 ( V_29 ) ;
return;
}
V_22 -> V_173 = V_20 ;
while ( ( V_29 = F_63 ( & V_52 ) ) )
F_89 ( V_29 ) ;
}
static void F_215 ( struct V_196 * V_197 )
{
struct V_22 * V_22 = F_216 ( V_197 , struct V_22 , V_44 ) ;
F_7 ( & V_22 -> V_15 ) ;
F_200 ( V_22 -> V_114 ) ;
F_8 ( & V_22 -> V_15 ) ;
F_127 ( V_22 , & V_22 -> V_95 , & V_22 -> F_107 ) ;
F_8 ( & V_22 -> V_15 ) ;
F_127 ( V_22 , & V_22 -> V_198 , & V_22 -> V_159 ) ;
F_8 ( & V_22 -> V_15 ) ;
F_127 ( V_22 , & V_22 -> V_115 , & V_22 -> V_199 ) ;
F_8 ( & V_22 -> V_15 ) ;
F_213 ( V_22 ) ;
F_10 ( & V_22 -> V_15 ) ;
}
static void F_217 ( struct V_196 * V_197 )
{
struct V_22 * V_22 = F_216 ( F_218 ( V_197 ) , struct V_22 , V_200 ) ;
F_29 ( V_22 ) ;
F_219 ( V_22 -> V_43 , & V_22 -> V_200 , V_174 ) ;
}
static void F_220 ( struct V_196 * V_197 )
{
struct V_22 * V_22 = F_216 ( F_218 ( V_197 ) , struct V_22 ,
V_201 ) ;
if ( F_148 ( V_22 ) == V_145 && ! V_22 -> V_139 . V_156 ) {
V_22 -> V_139 . V_156 = true ;
F_221 ( V_22 ) ;
F_71 ( V_22 , - V_56 ) ;
}
}
static struct V_202 * F_222 ( struct V_196 * V_197 )
{
return F_216 ( V_197 , struct V_202 , V_44 ) ;
}
static void F_223 ( struct V_202 * V_203 )
{
F_224 ( & V_203 -> F_224 ) ;
}
static void F_225 ( struct V_202 * V_203 , struct V_22 * V_22 ,
void (* F_38)( struct V_196 * ) )
{
F_226 ( & V_203 -> V_44 , F_38 ) ;
F_227 ( & V_203 -> F_224 ) ;
F_30 ( V_22 -> V_43 , & V_203 -> V_44 ) ;
F_228 ( & V_203 -> F_224 ) ;
}
static struct V_204 * F_229 ( struct V_196 * V_197 )
{
return F_216 ( F_222 ( V_197 ) , struct V_204 , V_203 ) ;
}
static void F_230 ( struct V_196 * V_197 )
{
struct V_204 * V_205 = F_229 ( V_197 ) ;
V_205 -> V_28 -> V_169 = true ;
F_70 ( V_205 -> V_28 ) ;
F_223 ( & V_205 -> V_203 ) ;
}
static void F_231 ( struct V_196 * V_197 )
{
struct V_204 * V_205 = F_229 ( V_197 ) ;
V_205 -> V_28 -> V_169 = false ;
F_223 ( & V_205 -> V_203 ) ;
}
static void V_204 ( struct V_27 * V_28 , void (* F_38)( struct V_196 * ) )
{
struct V_204 V_205 ;
V_205 . V_28 = V_28 ;
F_225 ( & V_205 . V_203 , V_28 -> V_22 , F_38 ) ;
}
static enum V_155 F_148 ( struct V_22 * V_22 )
{
return V_22 -> V_139 . V_206 ;
}
static void F_232 ( struct V_22 * V_22 , const char * V_207 )
{
F_154 ( V_22 -> V_152 -> V_153 ) ;
F_233 ( L_16 ,
F_124 ( V_22 -> V_66 ) , V_207 ) ;
}
static void F_221 ( struct V_22 * V_22 )
{
if ( ! V_22 -> V_139 . V_156 )
F_232 ( V_22 , L_17 ) ;
else
F_232 ( V_22 , L_18 ) ;
}
static bool F_234 ( struct V_208 * V_209 )
{
return V_209 -> V_210 . V_211 ;
}
static void F_235 ( struct V_22 * V_22 )
{
struct V_208 * V_209 = V_22 -> V_152 -> V_212 ;
if ( F_234 ( V_209 ) ) {
V_22 -> V_163 = F_166 ;
V_22 -> V_159 = F_120 ;
V_22 -> V_199 = F_125 ;
} else {
V_22 -> V_163 = F_162 ;
V_22 -> V_159 = F_113 ;
}
}
static void F_150 ( struct V_22 * V_22 , enum V_155 V_207 )
{
struct V_208 * V_209 = V_22 -> V_152 -> V_212 ;
bool V_213 = F_236 ( V_22 -> V_114 ) ;
enum V_155 V_214 = F_148 ( V_22 ) ;
unsigned long V_201 = F_237 ( V_215 ) * V_216 ;
if ( V_207 == V_146 && V_213 ) {
F_238 ( L_19 ,
F_124 ( V_22 -> V_66 ) ) ;
if ( V_214 != V_207 )
V_207 = V_214 ;
else
V_207 = V_147 ;
}
if ( V_214 == V_157 )
V_207 = V_214 ;
switch ( V_207 ) {
case V_157 :
if ( V_214 != V_207 )
F_232 ( V_22 , L_20 ) ;
F_239 ( V_22 -> V_114 ) ;
V_22 -> F_177 = F_182 ;
V_22 -> V_183 = F_182 ;
V_22 -> F_174 = F_184 ;
V_22 -> V_163 = F_184 ;
V_22 -> F_107 = F_105 ;
V_22 -> V_159 = F_111 ;
F_75 ( V_22 ) ;
break;
case V_147 :
if ( V_214 != V_207 )
F_232 ( V_22 , L_21 ) ;
F_239 ( V_22 -> V_114 ) ;
V_22 -> F_177 = F_179 ;
V_22 -> V_183 = F_181 ;
V_22 -> F_174 = F_180 ;
V_22 -> V_163 = F_183 ;
V_22 -> F_107 = F_105 ;
V_22 -> V_159 = F_112 ;
F_75 ( V_22 ) ;
break;
case V_145 :
if ( V_214 != V_207 )
F_221 ( V_22 ) ;
V_22 -> V_55 = true ;
V_22 -> F_177 = F_179 ;
V_22 -> V_183 = F_167 ;
V_22 -> F_174 = F_180 ;
V_22 -> F_107 = F_107 ;
F_235 ( V_22 ) ;
if ( ! V_22 -> V_139 . V_156 && V_201 )
F_219 ( V_22 -> V_43 , & V_22 -> V_201 , V_201 ) ;
break;
case V_146 :
if ( V_214 != V_207 )
F_232 ( V_22 , L_22 ) ;
V_22 -> V_55 = false ;
V_22 -> V_139 . V_156 = V_209 -> V_217 . V_156 ;
F_240 ( V_22 -> V_114 ) ;
V_22 -> F_177 = F_177 ;
V_22 -> V_183 = F_167 ;
V_22 -> F_174 = F_174 ;
V_22 -> F_107 = F_107 ;
F_235 ( V_22 ) ;
break;
}
V_22 -> V_139 . V_206 = V_207 ;
V_209 -> V_210 . V_206 = V_207 ;
}
static void F_241 ( struct V_22 * V_22 )
{
const char * V_218 = F_124 ( V_22 -> V_66 ) ;
F_137 ( L_23 , V_218 ) ;
if ( F_242 ( V_22 -> V_114 ) ) {
F_238 ( L_24 , V_218 ) ;
F_150 ( V_22 , V_157 ) ;
}
if ( F_243 ( V_22 -> V_114 ) ) {
F_238 ( L_25 , V_218 ) ;
F_150 ( V_22 , V_157 ) ;
}
}
static void F_109 ( struct V_22 * V_22 , const char * V_26 , int V_40 )
{
F_137 ( L_26 ,
F_124 ( V_22 -> V_66 ) , V_26 , V_40 ) ;
F_241 ( V_22 ) ;
F_150 ( V_22 , V_147 ) ;
}
static void F_104 ( struct V_27 * V_28 , struct V_29 * V_29 )
{
unsigned long V_70 ;
struct V_22 * V_22 = V_28 -> V_22 ;
F_65 ( & V_28 -> V_17 , V_70 ) ;
F_92 ( & V_28 -> V_74 , V_29 ) ;
F_66 ( & V_28 -> V_17 , V_70 ) ;
F_29 ( V_22 ) ;
}
static void F_244 ( struct V_27 * V_28 , struct V_29 * V_29 )
{
struct V_22 * V_22 = V_28 -> V_22 ;
F_12 ( & V_22 -> V_15 ) ;
F_104 ( V_28 , V_29 ) ;
F_14 ( & V_22 -> V_15 ) ;
}
static void F_245 ( struct V_27 * V_28 , struct V_45 * V_50 )
{
unsigned long V_70 ;
struct V_22 * V_22 = V_28 -> V_22 ;
F_12 ( & V_22 -> V_15 ) ;
F_65 ( & V_28 -> V_17 , V_70 ) ;
F_97 ( & V_50 -> V_190 , & V_28 -> V_73 ) ;
F_66 ( & V_28 -> V_17 , V_70 ) ;
F_14 ( & V_22 -> V_15 ) ;
F_29 ( V_22 ) ;
}
static void F_246 ( struct V_27 * V_28 , struct V_29 * V_29 )
{
struct V_87 * V_88 = F_86 ( V_29 , sizeof( struct V_87 ) ) ;
V_88 -> V_28 = V_28 ;
V_88 -> V_167 = NULL ;
V_88 -> V_89 = NULL ;
V_88 -> V_99 = NULL ;
V_88 -> V_50 = NULL ;
}
static int F_247 ( struct V_219 * V_152 , struct V_29 * V_29 )
{
int V_40 ;
struct V_27 * V_28 = V_152 -> V_212 ;
T_1 V_83 = F_76 ( V_28 , V_29 ) ;
struct V_1 * V_2 = V_28 -> V_2 ;
struct V_164 V_154 ;
struct V_45 * V_158 , * V_161 ;
struct V_7 V_8 ;
F_246 ( V_28 , V_29 ) ;
if ( V_28 -> V_169 ) {
V_29 -> V_42 = V_58 ;
F_28 ( V_29 ) ;
return V_220 ;
}
if ( F_148 ( V_28 -> V_22 ) == V_157 ) {
F_91 ( V_29 ) ;
return V_220 ;
}
if ( F_82 ( V_29 -> V_86 ) || F_85 ( V_29 ) == V_41 ) {
F_244 ( V_28 , V_29 ) ;
return V_220 ;
}
F_4 ( V_28 -> V_2 , V_83 , & V_8 ) ;
if ( F_31 ( V_28 -> V_22 , & V_8 , V_29 , & V_158 ) )
return V_220 ;
V_40 = F_175 ( V_2 , V_83 , 0 , & V_154 ) ;
switch ( V_40 ) {
case 0 :
if ( F_248 ( V_154 . V_170 ) ) {
F_245 ( V_28 , V_158 ) ;
return V_220 ;
}
F_3 ( V_28 -> V_2 , V_154 . V_83 , & V_8 ) ;
if ( F_31 ( V_28 -> V_22 , & V_8 , V_29 , & V_161 ) ) {
F_101 ( V_28 , V_158 ) ;
return V_220 ;
}
F_84 ( V_28 -> V_22 , V_29 ) ;
F_101 ( V_28 , V_161 ) ;
F_101 ( V_28 , V_158 ) ;
F_79 ( V_28 , V_29 , V_154 . V_83 ) ;
return V_221 ;
case - V_171 :
case - V_222 :
F_245 ( V_28 , V_158 ) ;
return V_220 ;
default:
F_91 ( V_29 ) ;
F_101 ( V_28 , V_158 ) ;
return V_220 ;
}
}
static int F_249 ( struct V_223 * V_224 , int V_225 )
{
struct V_208 * V_209 = F_216 ( V_224 , struct V_208 , V_226 ) ;
struct V_227 * V_228 ;
if ( F_148 ( V_209 -> V_22 ) == V_145 )
return 1 ;
V_228 = F_250 ( V_209 -> V_229 -> V_38 ) ;
return F_251 ( V_228 -> V_230 , V_225 ) ;
}
static void F_252 ( struct V_22 * V_22 )
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
static bool F_253 ( struct V_208 * V_209 )
{
struct V_227 * V_228 = F_250 ( V_209 -> V_229 -> V_38 ) ;
return V_228 && F_254 ( V_228 ) ;
}
static bool F_255 ( T_2 V_231 , T_5 V_232 )
{
return ! F_77 ( V_231 , V_232 ) ;
}
static void F_256 ( struct V_208 * V_209 )
{
struct V_22 * V_22 = V_209 -> V_22 ;
struct V_67 * V_233 = V_209 -> V_229 -> V_38 ;
struct V_234 * V_235 = & F_250 ( V_233 ) -> V_236 ;
const char * V_237 = NULL ;
char V_238 [ V_239 ] ;
if ( ! V_209 -> V_210 . V_211 )
return;
if ( ! F_253 ( V_209 ) )
V_237 = L_27 ;
else if ( V_235 -> V_240 < V_22 -> V_24 )
V_237 = L_28 ;
if ( V_237 ) {
F_123 ( L_29 , F_257 ( V_233 , V_238 ) , V_237 ) ;
V_209 -> V_210 . V_211 = false ;
}
}
static int F_258 ( struct V_22 * V_22 , struct V_219 * V_152 )
{
struct V_208 * V_209 = V_152 -> V_212 ;
enum V_155 V_214 = F_148 ( V_22 ) ;
enum V_155 V_207 = V_209 -> V_210 . V_206 ;
V_209 -> V_210 . V_206 = V_214 ;
V_22 -> V_152 = V_152 ;
V_22 -> V_139 = V_209 -> V_210 ;
V_22 -> V_150 = V_209 -> V_150 ;
F_150 ( V_22 , V_207 ) ;
return 0 ;
}
static void F_259 ( struct V_22 * V_22 , struct V_219 * V_152 )
{
if ( V_22 -> V_152 == V_152 )
V_22 -> V_152 = NULL ;
}
static void F_260 ( struct V_241 * V_139 )
{
V_139 -> V_206 = V_146 ;
V_139 -> V_140 = true ;
V_139 -> V_242 = true ;
V_139 -> V_211 = true ;
V_139 -> V_156 = false ;
}
static void F_261 ( struct V_22 * V_22 )
{
F_54 ( V_22 ) ;
F_262 ( V_22 -> V_189 ) ;
if ( F_263 ( V_22 -> V_114 ) < 0 )
F_123 ( L_30 , V_166 ) ;
F_264 ( V_22 -> V_48 ) ;
F_265 ( V_22 -> V_130 ) ;
if ( V_22 -> V_43 )
F_266 ( V_22 -> V_43 ) ;
if ( V_22 -> V_123 )
F_106 ( V_22 -> V_123 , V_22 -> V_106 ) ;
F_267 ( V_22 -> V_106 ) ;
F_268 ( V_22 -> V_137 ) ;
F_268 ( V_22 -> V_90 ) ;
F_269 ( V_22 ) ;
}
static struct V_22 * F_270 ( struct V_63 * V_66 ,
struct V_67 * V_243 ,
unsigned long V_231 ,
int V_244 , char * * error )
{
int V_40 ;
void * V_245 ;
struct V_22 * V_22 ;
struct V_246 * V_114 ;
bool V_247 = V_244 ? false : true ;
V_114 = F_271 ( V_243 , V_231 , V_247 ) ;
if ( F_272 ( V_114 ) ) {
* error = L_31 ;
return (struct V_22 * ) V_114 ;
}
V_22 = F_273 ( sizeof( * V_22 ) , V_248 ) ;
if ( ! V_22 ) {
* error = L_32 ;
V_245 = F_274 ( - V_125 ) ;
goto V_249;
}
V_22 -> V_114 = V_114 ;
V_22 -> V_24 = V_231 ;
if ( V_231 & ( V_231 - 1 ) )
V_22 -> V_23 = - 1 ;
else
V_22 -> V_23 = F_275 ( V_231 ) ;
V_22 -> V_150 = 0 ;
F_260 ( & V_22 -> V_139 ) ;
V_22 -> V_48 = F_276 () ;
if ( ! V_22 -> V_48 ) {
* error = L_33 ;
V_245 = F_274 ( - V_125 ) ;
goto V_250;
}
V_22 -> V_130 = F_277 ( & V_251 ) ;
if ( F_272 ( V_22 -> V_130 ) ) {
V_40 = F_278 ( V_22 -> V_130 ) ;
* error = L_34 ;
V_245 = F_274 ( V_40 ) ;
goto V_252;
}
V_22 -> V_43 = F_279 ( L_35 V_253 , V_254 ) ;
if ( ! V_22 -> V_43 ) {
* error = L_36 ;
V_245 = F_274 ( - V_125 ) ;
goto V_255;
}
F_5 ( & V_22 -> V_15 ) ;
F_280 ( & V_22 -> V_44 , F_215 ) ;
F_281 ( & V_22 -> V_200 , F_217 ) ;
F_281 ( & V_22 -> V_201 , F_220 ) ;
F_282 ( & V_22 -> V_17 ) ;
F_61 ( & V_22 -> V_91 ) ;
F_50 ( & V_22 -> V_95 ) ;
F_50 ( & V_22 -> V_198 ) ;
F_50 ( & V_22 -> V_115 ) ;
F_50 ( & V_22 -> V_193 ) ;
V_22 -> V_151 = false ;
V_22 -> V_256 = true ;
V_22 -> V_55 = false ;
V_22 -> V_137 = F_283 () ;
if ( ! V_22 -> V_137 ) {
* error = L_37 ;
V_245 = F_274 ( - V_125 ) ;
goto V_257;
}
V_22 -> V_90 = F_283 () ;
if ( ! V_22 -> V_90 ) {
* error = L_38 ;
V_245 = F_274 ( - V_125 ) ;
goto V_258;
}
V_22 -> V_123 = NULL ;
V_22 -> V_106 = F_284 ( V_259 ,
V_260 ) ;
if ( ! V_22 -> V_106 ) {
* error = L_39 ;
V_245 = F_274 ( - V_125 ) ;
goto V_261;
}
V_22 -> V_189 = F_285 ( sizeof( * V_22 -> V_189 ) * V_188 ) ;
if ( ! V_22 -> V_189 ) {
* error = L_40 ;
V_245 = F_274 ( - V_125 ) ;
goto V_262;
}
V_22 -> V_263 = 1 ;
V_22 -> V_173 = V_20 ;
V_22 -> V_66 = V_66 ;
V_22 -> V_68 = V_243 ;
F_51 ( V_22 ) ;
return V_22 ;
V_262:
F_267 ( V_22 -> V_106 ) ;
V_261:
F_268 ( V_22 -> V_90 ) ;
V_258:
F_268 ( V_22 -> V_137 ) ;
V_257:
F_266 ( V_22 -> V_43 ) ;
V_255:
F_265 ( V_22 -> V_130 ) ;
V_252:
F_264 ( V_22 -> V_48 ) ;
V_250:
F_269 ( V_22 ) ;
V_249:
if ( F_263 ( V_114 ) )
F_123 ( L_30 , V_166 ) ;
return V_245 ;
}
static void F_286 ( struct V_22 * V_22 )
{
F_19 ( ! F_52 ( & V_59 . V_60 ) ) ;
V_22 -> V_263 ++ ;
}
static void F_287 ( struct V_22 * V_22 )
{
F_19 ( ! F_52 ( & V_59 . V_60 ) ) ;
F_19 ( ! V_22 -> V_263 ) ;
if ( ! -- V_22 -> V_263 )
F_261 ( V_22 ) ;
}
static struct V_22 * F_288 ( struct V_63 * V_66 ,
struct V_67 * V_243 ,
unsigned long V_231 , int V_244 ,
char * * error , int * V_264 )
{
struct V_22 * V_22 = F_58 ( V_243 ) ;
if ( V_22 ) {
if ( V_22 -> V_66 != V_66 ) {
* error = L_41 ;
return F_274 ( - V_265 ) ;
}
F_286 ( V_22 ) ;
} else {
V_22 = F_56 ( V_66 ) ;
if ( V_22 ) {
if ( V_22 -> V_68 != V_243 ) {
* error = L_42 ;
return F_274 ( - V_148 ) ;
}
F_286 ( V_22 ) ;
} else {
V_22 = F_270 ( V_66 , V_243 , V_231 , V_244 , error ) ;
* V_264 = 1 ;
}
}
return V_22 ;
}
static void F_289 ( struct V_219 * V_152 )
{
struct V_208 * V_209 = V_152 -> V_212 ;
F_290 ( & V_59 . V_60 ) ;
F_259 ( V_209 -> V_22 , V_152 ) ;
F_287 ( V_209 -> V_22 ) ;
F_291 ( V_152 , V_209 -> V_243 ) ;
F_291 ( V_152 , V_209 -> V_229 ) ;
F_269 ( V_209 ) ;
F_292 ( & V_59 . V_60 ) ;
}
static int F_293 ( struct V_266 * V_267 , struct V_241 * V_139 ,
struct V_219 * V_152 )
{
int V_40 ;
unsigned V_268 ;
const char * V_269 ;
static struct V_270 V_271 [] = {
{ 0 , 4 , L_43 } ,
} ;
if ( ! V_267 -> V_268 )
return 0 ;
V_40 = F_294 ( V_271 , V_267 , & V_268 , & V_152 -> error ) ;
if ( V_40 )
return - V_148 ;
while ( V_268 && ! V_40 ) {
V_269 = F_295 ( V_267 ) ;
V_268 -- ;
if ( ! strcasecmp ( V_269 , L_44 ) )
V_139 -> V_140 = false ;
else if ( ! strcasecmp ( V_269 , L_45 ) )
V_139 -> V_242 = false ;
else if ( ! strcasecmp ( V_269 , L_46 ) )
V_139 -> V_211 = false ;
else if ( ! strcasecmp ( V_269 , L_47 ) )
V_139 -> V_206 = V_147 ;
else if ( ! strcasecmp ( V_269 , L_48 ) )
V_139 -> V_156 = true ;
else {
V_152 -> error = L_49 ;
V_40 = - V_148 ;
break;
}
}
return V_40 ;
}
static void F_296 ( void * V_53 )
{
struct V_22 * V_22 = V_53 ;
F_123 ( L_50 ,
F_124 ( V_22 -> V_66 ) ) ;
F_154 ( V_22 -> V_152 -> V_153 ) ;
}
static T_2 F_297 ( struct V_67 * V_38 )
{
return F_298 ( V_38 -> V_272 ) >> V_82 ;
}
static void F_299 ( struct V_67 * V_38 )
{
T_2 V_273 = F_297 ( V_38 ) ;
char V_274 [ V_239 ] ;
if ( V_273 > V_275 )
F_123 ( L_51 ,
F_257 ( V_38 , V_274 ) , V_276 ) ;
}
static T_2 F_300 ( struct V_67 * V_38 )
{
T_2 V_273 = F_297 ( V_38 ) ;
if ( V_273 > V_276 )
V_273 = V_276 ;
return V_273 ;
}
static T_1 F_301 ( struct V_67 * V_38 )
{
T_2 V_273 = F_300 ( V_38 ) ;
F_77 ( V_273 , V_277 ) ;
return V_273 ;
}
static T_1 F_302 ( struct V_208 * V_209 )
{
T_1 V_278 = F_301 ( V_209 -> V_243 -> V_38 ) / 4 ;
return F_303 ( ( T_1 ) 1024ULL , V_278 ) ;
}
static int F_304 ( struct V_219 * V_152 , unsigned V_268 , char * * V_279 )
{
int V_40 , V_280 = 0 ;
struct V_208 * V_209 ;
struct V_22 * V_22 ;
struct V_241 V_139 ;
struct V_266 V_267 ;
struct V_133 * V_229 ;
unsigned long V_231 ;
T_1 V_150 ;
struct V_133 * V_243 ;
T_6 V_281 ;
F_290 ( & V_59 . V_60 ) ;
if ( V_268 < 4 ) {
V_152 -> error = L_52 ;
V_40 = - V_148 ;
goto V_282;
}
V_267 . V_268 = V_268 ;
V_267 . V_279 = V_279 ;
F_260 ( & V_139 ) ;
F_305 ( & V_267 , 4 ) ;
V_40 = F_293 ( & V_267 , & V_139 , V_152 ) ;
if ( V_40 )
goto V_282;
V_281 = V_283 | ( ( V_139 . V_206 == V_147 ) ? 0 : V_284 ) ;
V_40 = F_306 ( V_152 , V_279 [ 0 ] , V_281 , & V_243 ) ;
if ( V_40 ) {
V_152 -> error = L_53 ;
goto V_282;
}
F_299 ( V_243 -> V_38 ) ;
V_40 = F_306 ( V_152 , V_279 [ 1 ] , V_283 | V_284 , & V_229 ) ;
if ( V_40 ) {
V_152 -> error = L_54 ;
goto V_285;
}
if ( F_307 ( V_279 [ 2 ] , 10 , & V_231 ) || ! V_231 ||
V_231 < V_286 ||
V_231 > V_287 ||
V_231 & ( V_286 - 1 ) ) {
V_152 -> error = L_55 ;
V_40 = - V_148 ;
goto V_107;
}
if ( F_308 ( V_279 [ 3 ] , 10 , ( unsigned long long * ) & V_150 ) ) {
V_152 -> error = L_56 ;
V_40 = - V_148 ;
goto V_107;
}
V_209 = F_309 ( sizeof( * V_209 ) , V_248 ) ;
if ( ! V_209 ) {
V_40 = - V_125 ;
goto V_107;
}
V_22 = F_288 ( F_310 ( V_152 -> V_153 ) , V_243 -> V_38 ,
V_231 , V_139 . V_206 == V_147 , & V_152 -> error , & V_280 ) ;
if ( F_272 ( V_22 ) ) {
V_40 = F_278 ( V_22 ) ;
goto V_288;
}
if ( ! V_280 && V_139 . V_242 != V_22 -> V_139 . V_242 ) {
V_152 -> error = L_57 ;
V_40 = - V_148 ;
goto V_289;
}
V_209 -> V_22 = V_22 ;
V_209 -> V_152 = V_152 ;
V_209 -> V_243 = V_243 ;
V_209 -> V_229 = V_229 ;
V_209 -> V_150 = V_150 ;
V_209 -> V_210 = V_209 -> V_217 = V_139 ;
V_152 -> V_290 = 1 ;
if ( V_139 . V_242 && V_139 . V_211 ) {
V_152 -> V_291 = 1 ;
V_152 -> V_292 = true ;
}
V_152 -> V_212 = V_209 ;
V_40 = F_311 ( V_209 -> V_22 -> V_114 ,
F_302 ( V_209 ) ,
F_296 ,
V_22 ) ;
if ( V_40 )
goto V_289;
V_209 -> V_226 . V_293 = F_249 ;
F_312 ( V_152 -> V_153 , & V_209 -> V_226 ) ;
F_292 ( & V_59 . V_60 ) ;
return 0 ;
V_289:
F_287 ( V_22 ) ;
V_288:
F_269 ( V_209 ) ;
V_107:
F_291 ( V_152 , V_229 ) ;
V_285:
F_291 ( V_152 , V_243 ) ;
V_282:
F_292 ( & V_59 . V_60 ) ;
return V_40 ;
}
static int F_313 ( struct V_219 * V_152 , struct V_29 * V_29 )
{
int V_40 ;
struct V_208 * V_209 = V_152 -> V_212 ;
struct V_22 * V_22 = V_209 -> V_22 ;
unsigned long V_70 ;
F_65 ( & V_22 -> V_17 , V_70 ) ;
V_29 -> V_84 = V_209 -> V_229 -> V_38 ;
V_40 = V_221 ;
F_66 ( & V_22 -> V_17 , V_70 ) ;
return V_40 ;
}
static int F_314 ( struct V_219 * V_152 , bool * V_294 )
{
int V_40 ;
struct V_208 * V_209 = V_152 -> V_212 ;
struct V_22 * V_22 = V_209 -> V_22 ;
T_2 V_295 = V_152 -> V_36 ;
T_1 V_296 ;
* V_294 = false ;
( void ) F_77 ( V_295 , V_22 -> V_24 ) ;
V_40 = F_315 ( V_22 -> V_114 , & V_296 ) ;
if ( V_40 ) {
F_238 ( L_58 ,
F_124 ( V_22 -> V_66 ) ) ;
return V_40 ;
}
if ( V_295 < V_296 ) {
F_238 ( L_59 ,
F_124 ( V_22 -> V_66 ) ,
( unsigned long long ) V_295 , V_296 ) ;
return - V_148 ;
} else if ( V_295 > V_296 ) {
if ( F_236 ( V_22 -> V_114 ) ) {
F_238 ( L_60 ,
F_124 ( V_22 -> V_66 ) ) ;
return 0 ;
}
if ( V_296 )
F_233 ( L_61 ,
F_124 ( V_22 -> V_66 ) ,
V_296 , ( unsigned long long ) V_295 ) ;
V_40 = F_316 ( V_22 -> V_114 , V_295 ) ;
if ( V_40 ) {
F_109 ( V_22 , L_62 , V_40 ) ;
return V_40 ;
}
* V_294 = true ;
}
return 0 ;
}
static int F_317 ( struct V_219 * V_152 , bool * V_294 )
{
int V_40 ;
struct V_208 * V_209 = V_152 -> V_212 ;
struct V_22 * V_22 = V_209 -> V_22 ;
T_1 V_273 , V_297 ;
* V_294 = false ;
V_273 = F_301 ( V_22 -> V_68 ) ;
V_40 = F_318 ( V_22 -> V_114 , & V_297 ) ;
if ( V_40 ) {
F_238 ( L_63 ,
F_124 ( V_22 -> V_66 ) ) ;
return V_40 ;
}
if ( V_273 < V_297 ) {
F_238 ( L_64 ,
F_124 ( V_22 -> V_66 ) ,
V_273 , V_297 ) ;
return - V_148 ;
} else if ( V_273 > V_297 ) {
if ( F_236 ( V_22 -> V_114 ) ) {
F_238 ( L_65 ,
F_124 ( V_22 -> V_66 ) ) ;
return 0 ;
}
F_299 ( V_22 -> V_68 ) ;
F_233 ( L_66 ,
F_124 ( V_22 -> V_66 ) ,
V_297 , V_273 ) ;
V_40 = F_319 ( V_22 -> V_114 , V_273 ) ;
if ( V_40 ) {
F_109 ( V_22 , L_67 , V_40 ) ;
return V_40 ;
}
* V_294 = true ;
}
return 0 ;
}
static int F_320 ( struct V_219 * V_152 )
{
int V_40 ;
bool V_298 , V_299 ;
struct V_208 * V_209 = V_152 -> V_212 ;
struct V_22 * V_22 = V_209 -> V_22 ;
V_40 = F_258 ( V_22 , V_152 ) ;
if ( V_40 )
return V_40 ;
V_40 = F_314 ( V_152 , & V_298 ) ;
if ( V_40 )
return V_40 ;
V_40 = F_317 ( V_152 , & V_299 ) ;
if ( V_40 )
return V_40 ;
if ( V_298 || V_299 )
( void ) F_151 ( V_22 ) ;
return 0 ;
}
static void F_321 ( struct V_22 * V_22 )
{
struct V_27 * V_28 ;
V_28 = F_207 ( V_22 ) ;
while ( V_28 ) {
F_322 ( V_28 -> V_300 ) ;
V_28 = F_210 ( V_22 , V_28 ) ;
}
}
static void F_323 ( struct V_22 * V_22 )
{
struct V_27 * V_28 ;
V_28 = F_207 ( V_22 ) ;
while ( V_28 ) {
F_324 ( V_28 -> V_300 ) ;
V_28 = F_210 ( V_22 , V_28 ) ;
}
}
static void F_325 ( struct V_219 * V_152 )
{
struct V_208 * V_209 = V_152 -> V_212 ;
struct V_22 * V_22 = V_209 -> V_22 ;
unsigned long V_70 ;
F_252 ( V_22 ) ;
F_323 ( V_22 ) ;
F_65 ( & V_22 -> V_17 , V_70 ) ;
V_22 -> V_151 = false ;
V_22 -> V_256 = false ;
F_66 ( & V_22 -> V_17 , V_70 ) ;
F_217 ( & V_22 -> V_200 . V_301 ) ;
}
static void F_326 ( struct V_219 * V_152 )
{
struct V_208 * V_209 = V_152 -> V_212 ;
struct V_22 * V_22 = V_209 -> V_22 ;
unsigned long V_70 ;
F_65 ( & V_22 -> V_17 , V_70 ) ;
V_22 -> V_256 = true ;
F_66 ( & V_22 -> V_17 , V_70 ) ;
F_321 ( V_22 ) ;
}
static void F_327 ( struct V_219 * V_152 )
{
struct V_208 * V_209 = V_152 -> V_212 ;
struct V_22 * V_22 = V_209 -> V_22 ;
unsigned long V_70 ;
F_323 ( V_22 ) ;
F_65 ( & V_22 -> V_17 , V_70 ) ;
V_22 -> V_256 = false ;
F_66 ( & V_22 -> V_17 , V_70 ) ;
}
static void F_328 ( struct V_219 * V_152 )
{
struct V_208 * V_209 = V_152 -> V_212 ;
struct V_22 * V_22 = V_209 -> V_22 ;
F_329 ( & V_22 -> V_200 ) ;
F_329 ( & V_22 -> V_201 ) ;
F_330 ( V_22 -> V_43 ) ;
( void ) F_151 ( V_22 ) ;
}
static int F_331 ( unsigned V_268 , unsigned V_302 )
{
if ( V_268 != V_302 ) {
F_123 ( L_68 ,
V_268 , V_302 ) ;
return - V_148 ;
}
return 0 ;
}
static int F_332 ( char * V_303 , T_7 * V_304 , int V_305 )
{
if ( ! F_308 ( V_303 , 10 , ( unsigned long long * ) V_304 ) &&
* V_304 <= V_306 )
return 0 ;
if ( V_305 )
F_123 ( L_69 , V_303 ) ;
return - V_148 ;
}
static int F_333 ( unsigned V_268 , char * * V_279 , struct V_22 * V_22 )
{
T_7 V_304 ;
int V_40 ;
V_40 = F_331 ( V_268 , 2 ) ;
if ( V_40 )
return V_40 ;
V_40 = F_332 ( V_279 [ 1 ] , & V_304 , 1 ) ;
if ( V_40 )
return V_40 ;
V_40 = F_334 ( V_22 -> V_114 , V_304 ) ;
if ( V_40 ) {
F_123 ( L_70 ,
V_279 [ 1 ] ) ;
return V_40 ;
}
return 0 ;
}
static int F_335 ( unsigned V_268 , char * * V_279 , struct V_22 * V_22 )
{
T_7 V_304 ;
T_7 V_307 ;
int V_40 ;
V_40 = F_331 ( V_268 , 3 ) ;
if ( V_40 )
return V_40 ;
V_40 = F_332 ( V_279 [ 1 ] , & V_304 , 1 ) ;
if ( V_40 )
return V_40 ;
V_40 = F_332 ( V_279 [ 2 ] , & V_307 , 1 ) ;
if ( V_40 )
return V_40 ;
V_40 = F_336 ( V_22 -> V_114 , V_304 , V_307 ) ;
if ( V_40 ) {
F_123 ( L_71 ,
V_279 [ 1 ] , V_279 [ 2 ] ) ;
return V_40 ;
}
return 0 ;
}
static int F_337 ( unsigned V_268 , char * * V_279 , struct V_22 * V_22 )
{
T_7 V_304 ;
int V_40 ;
V_40 = F_331 ( V_268 , 2 ) ;
if ( V_40 )
return V_40 ;
V_40 = F_332 ( V_279 [ 1 ] , & V_304 , 1 ) ;
if ( V_40 )
return V_40 ;
V_40 = F_338 ( V_22 -> V_114 , V_304 ) ;
if ( V_40 )
F_123 ( L_72 , V_279 [ 1 ] ) ;
return V_40 ;
}
static int F_339 ( unsigned V_268 , char * * V_279 , struct V_22 * V_22 )
{
T_7 V_308 , V_309 ;
int V_40 ;
V_40 = F_331 ( V_268 , 3 ) ;
if ( V_40 )
return V_40 ;
if ( F_308 ( V_279 [ 1 ] , 10 , ( unsigned long long * ) & V_308 ) ) {
F_123 ( L_73 , V_279 [ 1 ] ) ;
return - V_148 ;
}
if ( F_308 ( V_279 [ 2 ] , 10 , ( unsigned long long * ) & V_309 ) ) {
F_123 ( L_74 , V_279 [ 2 ] ) ;
return - V_148 ;
}
V_40 = F_340 ( V_22 -> V_114 , V_308 , V_309 ) ;
if ( V_40 ) {
F_123 ( L_75 ,
V_279 [ 1 ] , V_279 [ 2 ] ) ;
return V_40 ;
}
return 0 ;
}
static int F_341 ( unsigned V_268 , char * * V_279 , struct V_22 * V_22 )
{
int V_40 ;
V_40 = F_331 ( V_268 , 1 ) ;
if ( V_40 )
return V_40 ;
( void ) F_151 ( V_22 ) ;
V_40 = F_342 ( V_22 -> V_114 ) ;
if ( V_40 )
F_123 ( L_76 ) ;
return V_40 ;
}
static int F_343 ( unsigned V_268 , char * * V_279 , struct V_22 * V_22 )
{
int V_40 ;
V_40 = F_331 ( V_268 , 1 ) ;
if ( V_40 )
return V_40 ;
V_40 = F_344 ( V_22 -> V_114 ) ;
if ( V_40 )
F_123 ( L_77 ) ;
return V_40 ;
}
static int F_345 ( struct V_219 * V_152 , unsigned V_268 , char * * V_279 )
{
int V_40 = - V_148 ;
struct V_208 * V_209 = V_152 -> V_212 ;
struct V_22 * V_22 = V_209 -> V_22 ;
if ( F_148 ( V_22 ) >= V_147 ) {
F_238 ( L_78 ,
F_124 ( V_22 -> V_66 ) ) ;
return - V_310 ;
}
if ( ! strcasecmp ( V_279 [ 0 ] , L_79 ) )
V_40 = F_333 ( V_268 , V_279 , V_22 ) ;
else if ( ! strcasecmp ( V_279 [ 0 ] , L_80 ) )
V_40 = F_335 ( V_268 , V_279 , V_22 ) ;
else if ( ! strcasecmp ( V_279 [ 0 ] , L_81 ) )
V_40 = F_337 ( V_268 , V_279 , V_22 ) ;
else if ( ! strcasecmp ( V_279 [ 0 ] , L_82 ) )
V_40 = F_339 ( V_268 , V_279 , V_22 ) ;
else if ( ! strcasecmp ( V_279 [ 0 ] , L_83 ) )
V_40 = F_341 ( V_268 , V_279 , V_22 ) ;
else if ( ! strcasecmp ( V_279 [ 0 ] , L_84 ) )
V_40 = F_343 ( V_268 , V_279 , V_22 ) ;
else
F_123 ( L_85 , V_279 [ 0 ] ) ;
if ( ! V_40 )
( void ) F_151 ( V_22 ) ;
return V_40 ;
}
static void F_346 ( struct V_241 * V_139 , char * V_154 ,
unsigned V_311 , unsigned V_312 )
{
unsigned V_129 = ! V_139 -> V_140 + ! V_139 -> V_242 +
! V_139 -> V_211 + ( V_139 -> V_206 == V_147 ) +
V_139 -> V_156 ;
F_347 ( L_86 , V_129 ) ;
if ( ! V_139 -> V_140 )
F_347 ( L_87 ) ;
if ( ! V_139 -> V_242 )
F_347 ( L_88 ) ;
if ( ! V_139 -> V_211 )
F_347 ( L_89 ) ;
if ( V_139 -> V_206 == V_147 )
F_347 ( L_90 ) ;
if ( V_139 -> V_156 )
F_347 ( L_91 ) ;
}
static void F_348 ( struct V_219 * V_152 , T_8 type ,
unsigned V_313 , char * V_154 , unsigned V_312 )
{
int V_40 ;
unsigned V_311 = 0 ;
T_9 V_314 ;
T_1 V_315 ;
T_1 V_316 ;
T_1 V_317 ;
T_1 V_318 ;
T_1 V_319 ;
char V_238 [ V_239 ] ;
char V_320 [ V_239 ] ;
struct V_208 * V_209 = V_152 -> V_212 ;
struct V_22 * V_22 = V_209 -> V_22 ;
switch ( type ) {
case V_321 :
if ( F_148 ( V_22 ) == V_157 ) {
F_347 ( L_92 ) ;
break;
}
if ( ! ( V_313 & V_322 ) && ! F_349 ( V_152 ) )
( void ) F_151 ( V_22 ) ;
V_40 = F_350 ( V_22 -> V_114 , & V_314 ) ;
if ( V_40 ) {
F_238 ( L_93 ,
F_124 ( V_22 -> V_66 ) , V_40 ) ;
goto V_98;
}
V_40 = F_351 ( V_22 -> V_114 , & V_316 ) ;
if ( V_40 ) {
F_238 ( L_94 ,
F_124 ( V_22 -> V_66 ) , V_40 ) ;
goto V_98;
}
V_40 = F_318 ( V_22 -> V_114 , & V_318 ) ;
if ( V_40 ) {
F_238 ( L_95 ,
F_124 ( V_22 -> V_66 ) , V_40 ) ;
goto V_98;
}
V_40 = F_149 ( V_22 -> V_114 , & V_315 ) ;
if ( V_40 ) {
F_238 ( L_96 ,
F_124 ( V_22 -> V_66 ) , V_40 ) ;
goto V_98;
}
V_40 = F_315 ( V_22 -> V_114 , & V_317 ) ;
if ( V_40 ) {
F_238 ( L_97 ,
F_124 ( V_22 -> V_66 ) , V_40 ) ;
goto V_98;
}
V_40 = F_352 ( V_22 -> V_114 , & V_319 ) ;
if ( V_40 ) {
F_238 ( L_98 ,
F_124 ( V_22 -> V_66 ) , V_40 ) ;
goto V_98;
}
F_347 ( L_99 ,
( unsigned long long ) V_314 ,
( unsigned long long ) ( V_318 - V_316 ) ,
( unsigned long long ) V_318 ,
( unsigned long long ) ( V_317 - V_315 ) ,
( unsigned long long ) V_317 ) ;
if ( V_319 )
F_347 ( L_100 , V_319 ) ;
else
F_347 ( L_101 ) ;
if ( V_22 -> V_139 . V_206 == V_145 )
F_347 ( L_102 ) ;
else if ( V_22 -> V_139 . V_206 == V_147 )
F_347 ( L_103 ) ;
else
F_347 ( L_104 ) ;
if ( ! V_22 -> V_139 . V_242 )
F_347 ( L_88 ) ;
else if ( V_22 -> V_139 . V_211 )
F_347 ( L_105 ) ;
else
F_347 ( L_89 ) ;
if ( V_22 -> V_139 . V_156 )
F_347 ( L_91 ) ;
else
F_347 ( L_106 ) ;
if ( F_236 ( V_22 -> V_114 ) )
F_347 ( L_107 ) ;
else
F_347 ( L_101 ) ;
break;
case V_323 :
F_347 ( L_108 ,
F_353 ( V_238 , V_209 -> V_243 -> V_38 -> V_324 ) ,
F_353 ( V_320 , V_209 -> V_229 -> V_38 -> V_324 ) ,
( unsigned long ) V_22 -> V_24 ,
( unsigned long long ) V_209 -> V_150 ) ;
F_346 ( & V_209 -> V_217 , V_154 , V_311 , V_312 ) ;
break;
}
return;
V_98:
F_347 ( L_109 ) ;
}
static int F_354 ( struct V_219 * V_152 ,
T_10 F_38 , void * V_325 )
{
struct V_208 * V_209 = V_152 -> V_212 ;
return F_38 ( V_152 , V_209 -> V_229 , 0 , V_152 -> V_36 , V_325 ) ;
}
static void F_355 ( struct V_219 * V_152 , struct V_234 * V_236 )
{
struct V_208 * V_209 = V_152 -> V_212 ;
struct V_22 * V_22 = V_209 -> V_22 ;
T_2 V_326 = V_236 -> V_327 >> V_82 ;
if ( V_236 -> V_328 < V_22 -> V_24 ) {
while ( ! F_255 ( V_22 -> V_24 , V_236 -> V_328 ) ) {
if ( ( V_236 -> V_328 & ( V_236 -> V_328 - 1 ) ) == 0 )
V_236 -> V_328 -- ;
V_236 -> V_328 = F_356 ( V_236 -> V_328 ) ;
}
}
if ( V_326 < V_22 -> V_24 ||
! F_255 ( V_326 , V_22 -> V_24 ) ) {
if ( F_255 ( V_22 -> V_24 , V_236 -> V_328 ) )
F_357 ( V_236 , V_236 -> V_328 << V_82 ) ;
else
F_357 ( V_236 , V_22 -> V_24 << V_82 ) ;
F_358 ( V_236 , V_22 -> V_24 << V_82 ) ;
}
if ( ! V_209 -> V_210 . V_242 ) {
V_236 -> V_329 = 0 ;
return;
}
F_256 ( V_209 ) ;
}
static void F_209 ( struct V_27 * V_28 )
{
F_143 ( & V_28 -> V_330 ) ;
}
static void F_212 ( struct V_27 * V_28 )
{
if ( F_96 ( & V_28 -> V_330 ) )
F_224 ( & V_28 -> V_331 ) ;
}
static void F_359 ( struct V_219 * V_152 )
{
struct V_27 * V_28 = V_152 -> V_212 ;
unsigned long V_70 ;
F_65 ( & V_28 -> V_22 -> V_17 , V_70 ) ;
F_360 ( & V_28 -> V_62 ) ;
F_66 ( & V_28 -> V_22 -> V_17 , V_70 ) ;
F_361 () ;
F_212 ( V_28 ) ;
F_228 ( & V_28 -> V_331 ) ;
F_290 ( & V_59 . V_60 ) ;
F_287 ( V_28 -> V_22 ) ;
F_362 ( V_28 -> V_2 ) ;
F_291 ( V_152 , V_28 -> V_37 ) ;
if ( V_28 -> V_85 )
F_291 ( V_152 , V_28 -> V_85 ) ;
F_269 ( V_28 ) ;
F_292 ( & V_59 . V_60 ) ;
}
static int F_363 ( struct V_219 * V_152 , unsigned V_268 , char * * V_279 )
{
int V_40 ;
struct V_27 * V_28 ;
struct V_133 * V_37 , * V_85 ;
struct V_63 * V_66 ;
unsigned long V_70 ;
F_290 ( & V_59 . V_60 ) ;
if ( V_268 != 2 && V_268 != 3 ) {
V_152 -> error = L_52 ;
V_40 = - V_148 ;
goto V_282;
}
V_28 = V_152 -> V_212 = F_309 ( sizeof( * V_28 ) , V_248 ) ;
if ( ! V_28 ) {
V_152 -> error = L_110 ;
V_40 = - V_125 ;
goto V_282;
}
V_28 -> V_300 = F_310 ( V_152 -> V_153 ) ;
F_282 ( & V_28 -> V_17 ) ;
F_50 ( & V_28 -> V_73 ) ;
F_61 ( & V_28 -> V_74 ) ;
F_61 ( & V_28 -> V_75 ) ;
V_28 -> V_178 = V_332 ;
if ( V_268 == 3 ) {
V_40 = F_306 ( V_152 , V_279 [ 2 ] , V_283 , & V_85 ) ;
if ( V_40 ) {
V_152 -> error = L_111 ;
goto V_333;
}
V_28 -> V_85 = V_85 ;
}
V_40 = F_306 ( V_152 , V_279 [ 0 ] , F_364 ( V_152 -> V_153 ) , & V_37 ) ;
if ( V_40 ) {
V_152 -> error = L_112 ;
goto V_334;
}
V_28 -> V_37 = V_37 ;
if ( F_332 ( V_279 [ 1 ] , ( unsigned long long * ) & V_28 -> V_304 , 0 ) ) {
V_152 -> error = L_113 ;
V_40 = - V_148 ;
goto V_335;
}
V_66 = F_365 ( V_28 -> V_37 -> V_38 -> V_324 ) ;
if ( ! V_66 ) {
V_152 -> error = L_114 ;
V_40 = - V_148 ;
goto V_335;
}
V_28 -> V_22 = F_56 ( V_66 ) ;
if ( ! V_28 -> V_22 ) {
V_152 -> error = L_115 ;
V_40 = - V_148 ;
goto V_336;
}
F_286 ( V_28 -> V_22 ) ;
if ( F_148 ( V_28 -> V_22 ) == V_157 ) {
V_152 -> error = L_116 ;
V_40 = - V_148 ;
goto V_249;
}
V_40 = F_366 ( V_28 -> V_22 -> V_114 , V_28 -> V_304 , & V_28 -> V_2 ) ;
if ( V_40 ) {
V_152 -> error = L_117 ;
goto V_249;
}
V_40 = F_367 ( V_152 , V_28 -> V_22 -> V_24 ) ;
if ( V_40 )
goto V_337;
V_152 -> V_290 = 1 ;
V_152 -> V_338 = true ;
V_152 -> V_339 = sizeof( struct V_87 ) ;
if ( V_28 -> V_22 -> V_139 . V_242 ) {
V_152 -> V_292 = true ;
V_152 -> V_291 = 1 ;
V_152 -> V_340 = false ;
}
F_292 ( & V_59 . V_60 ) ;
F_65 ( & V_28 -> V_22 -> V_17 , V_70 ) ;
if ( V_28 -> V_22 -> V_256 ) {
F_66 ( & V_28 -> V_22 -> V_17 , V_70 ) ;
F_290 ( & V_59 . V_60 ) ;
V_152 -> error = L_118 ;
V_40 = - V_148 ;
goto V_337;
}
F_140 ( & V_28 -> V_330 , 1 ) ;
F_227 ( & V_28 -> V_331 ) ;
F_368 ( & V_28 -> V_62 , & V_28 -> V_22 -> V_193 ) ;
F_66 ( & V_28 -> V_22 -> V_17 , V_70 ) ;
F_361 () ;
F_369 ( V_66 ) ;
return 0 ;
V_337:
F_362 ( V_28 -> V_2 ) ;
V_249:
F_287 ( V_28 -> V_22 ) ;
V_336:
F_369 ( V_66 ) ;
V_335:
F_291 ( V_152 , V_28 -> V_37 ) ;
V_334:
if ( V_28 -> V_85 )
F_291 ( V_152 , V_28 -> V_85 ) ;
V_333:
F_269 ( V_28 ) ;
V_282:
F_292 ( & V_59 . V_60 ) ;
return V_40 ;
}
static int F_370 ( struct V_219 * V_152 , struct V_29 * V_29 )
{
V_29 -> V_77 . V_78 = F_371 ( V_152 , V_29 -> V_77 . V_78 ) ;
return F_247 ( V_152 , V_29 ) ;
}
static int F_372 ( struct V_219 * V_152 , struct V_29 * V_29 , int V_98 )
{
unsigned long V_70 ;
struct V_87 * V_88 = F_86 ( V_29 , sizeof( struct V_87 ) ) ;
struct V_71 V_301 ;
struct V_92 * V_93 , * V_65 ;
struct V_22 * V_22 = V_88 -> V_28 -> V_22 ;
if ( V_88 -> V_167 ) {
F_50 ( & V_301 ) ;
F_373 ( V_88 -> V_167 , & V_301 ) ;
F_65 ( & V_22 -> V_17 , V_70 ) ;
F_69 (m, tmp, &work, list) {
F_55 ( & V_93 -> V_62 ) ;
F_95 ( V_93 ) ;
}
F_66 ( & V_22 -> V_17 , V_70 ) ;
}
if ( V_88 -> V_89 ) {
F_50 ( & V_301 ) ;
F_373 ( V_88 -> V_89 , & V_301 ) ;
if ( ! F_205 ( & V_301 ) ) {
F_65 ( & V_22 -> V_17 , V_70 ) ;
F_69 (m, tmp, &work, list)
F_97 ( & V_93 -> V_62 , & V_22 -> V_198 ) ;
F_66 ( & V_22 -> V_17 , V_70 ) ;
F_29 ( V_22 ) ;
}
}
if ( V_88 -> V_50 )
F_101 ( V_88 -> V_28 , V_88 -> V_50 ) ;
return 0 ;
}
static void F_374 ( struct V_219 * V_152 )
{
struct V_27 * V_28 = V_152 -> V_212 ;
if ( F_375 ( V_152 ) )
V_204 ( V_28 , F_230 ) ;
}
static void F_376 ( struct V_219 * V_152 )
{
struct V_27 * V_28 = V_152 -> V_212 ;
V_204 ( V_28 , F_231 ) ;
}
static int F_377 ( struct V_219 * V_152 )
{
struct V_27 * V_28 = V_152 -> V_212 ;
if ( V_28 -> V_85 )
V_28 -> V_143 = F_297 ( V_28 -> V_85 -> V_38 ) ;
return 0 ;
}
static void F_378 ( struct V_219 * V_152 , T_8 type ,
unsigned V_313 , char * V_154 , unsigned V_312 )
{
int V_40 ;
T_11 V_311 = 0 ;
T_1 V_341 , V_342 ;
char V_238 [ V_239 ] ;
struct V_27 * V_28 = V_152 -> V_212 ;
if ( F_148 ( V_28 -> V_22 ) == V_157 ) {
F_347 ( L_92 ) ;
return;
}
if ( ! V_28 -> V_2 )
F_347 ( L_119 ) ;
else {
switch ( type ) {
case V_321 :
V_40 = F_379 ( V_28 -> V_2 , & V_341 ) ;
if ( V_40 ) {
F_238 ( L_120 , V_40 ) ;
goto V_98;
}
V_40 = F_380 ( V_28 -> V_2 , & V_342 ) ;
if ( V_40 < 0 ) {
F_238 ( L_121 , V_40 ) ;
goto V_98;
}
F_347 ( L_100 , V_341 * V_28 -> V_22 -> V_24 ) ;
if ( V_40 )
F_347 ( L_122 , ( ( V_342 + 1 ) *
V_28 -> V_22 -> V_24 ) - 1 ) ;
else
F_347 ( L_119 ) ;
break;
case V_323 :
F_347 ( L_123 ,
F_353 ( V_238 , V_28 -> V_37 -> V_38 -> V_324 ) ,
( unsigned long ) V_28 -> V_304 ) ;
if ( V_28 -> V_85 )
F_347 ( L_124 , F_353 ( V_238 , V_28 -> V_85 -> V_38 -> V_324 ) ) ;
break;
}
}
return;
V_98:
F_347 ( L_109 ) ;
}
static int F_381 ( struct V_219 * V_152 ,
T_10 F_38 , void * V_325 )
{
T_2 V_343 ;
struct V_27 * V_28 = V_152 -> V_212 ;
struct V_22 * V_22 = V_28 -> V_22 ;
if ( ! V_22 -> V_152 )
return 0 ;
V_343 = V_22 -> V_152 -> V_36 ;
( void ) F_77 ( V_343 , V_22 -> V_24 ) ;
if ( V_343 )
return F_38 ( V_152 , V_28 -> V_37 , 0 , V_22 -> V_24 * V_343 , V_325 ) ;
return 0 ;
}
static void F_382 ( struct V_219 * V_152 , struct V_234 * V_236 )
{
struct V_27 * V_28 = V_152 -> V_212 ;
struct V_22 * V_22 = V_28 -> V_22 ;
if ( ! V_22 -> V_139 . V_242 )
return;
V_236 -> V_329 = V_22 -> V_24 << V_82 ;
V_236 -> V_240 = 2048 * 1024 * 16 ;
}
static int T_12 F_383 ( void )
{
int V_40 ;
F_48 () ;
V_40 = F_384 ( & V_344 ) ;
if ( V_40 )
return V_40 ;
V_40 = F_384 ( & V_345 ) ;
if ( V_40 )
goto V_346;
V_40 = - V_125 ;
V_260 = F_385 ( V_92 , 0 ) ;
if ( ! V_260 )
goto V_347;
return 0 ;
V_347:
F_386 ( & V_345 ) ;
V_346:
F_386 ( & V_344 ) ;
return V_40 ;
}
static void F_387 ( void )
{
F_386 ( & V_344 ) ;
F_386 ( & V_345 ) ;
F_388 ( V_260 ) ;
}
