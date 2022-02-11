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
V_39 , V_40 | V_41 , & V_26 -> V_29 ) ;
}
static void F_23 ( struct V_25 * V_26 , int V_42 )
{
if ( V_26 -> V_29 ) {
F_24 ( V_26 -> V_29 , V_26 -> V_32 ) ;
F_25 ( V_40 | V_41 , V_26 -> V_29 ) ;
}
F_26 ( & V_26 -> V_31 ) ;
if ( V_42 && ! V_26 -> V_32 -> V_43 )
V_26 -> V_32 -> V_43 = V_42 ;
F_27 ( V_26 -> V_32 ) ;
}
static void F_28 ( struct V_22 * V_22 )
{
F_29 ( V_22 -> V_44 , & V_22 -> V_45 ) ;
}
static int F_30 ( struct V_22 * V_22 , struct V_7 * V_8 , struct V_29 * V_29 ,
struct V_46 * * V_47 )
{
int V_42 ;
struct V_46 * V_48 ;
V_48 = F_31 ( V_22 -> V_49 , V_50 ) ;
V_42 = F_32 ( V_22 -> V_49 , V_8 , V_29 , V_48 , V_47 ) ;
if ( V_42 )
F_33 ( V_22 -> V_49 , V_48 ) ;
return V_42 ;
}
static void F_34 ( struct V_22 * V_22 ,
struct V_46 * V_51 ,
struct V_52 * V_53 )
{
F_35 ( V_22 -> V_49 , V_51 , V_53 ) ;
F_33 ( V_22 -> V_49 , V_51 ) ;
}
static void F_36 ( struct V_22 * V_22 ,
void (* F_37)( void * , struct V_46 * ) ,
void * V_54 ,
struct V_46 * V_51 )
{
F_38 ( V_22 -> V_49 , F_37 , V_54 , V_51 ) ;
F_33 ( V_22 -> V_49 , V_51 ) ;
}
static void F_39 ( struct V_22 * V_22 ,
struct V_46 * V_51 ,
struct V_52 * V_53 )
{
F_40 ( V_22 -> V_49 , V_51 , V_53 ) ;
F_33 ( V_22 -> V_49 , V_51 ) ;
}
static void F_41 ( struct V_22 * V_22 ,
struct V_46 * V_51 , int V_55 )
{
F_42 ( V_22 -> V_49 , V_51 , V_55 ) ;
F_33 ( V_22 -> V_49 , V_51 ) ;
}
static int F_43 ( struct V_22 * V_22 )
{
return V_22 -> V_56 ? - V_57 : - V_58 ;
}
static void F_44 ( struct V_22 * V_22 , struct V_46 * V_51 )
{
int error = F_43 ( V_22 ) ;
F_41 ( V_22 , V_51 , error ) ;
}
static void F_45 ( struct V_22 * V_22 , struct V_46 * V_51 )
{
F_41 ( V_22 , V_51 , 0 ) ;
}
static void F_46 ( struct V_22 * V_22 , struct V_46 * V_51 )
{
F_41 ( V_22 , V_51 , V_59 ) ;
}
static void F_47 ( void )
{
F_48 ( & V_60 . V_61 ) ;
F_49 ( & V_60 . V_62 ) ;
}
static void F_50 ( struct V_22 * V_22 )
{
F_19 ( ! F_51 ( & V_60 . V_61 ) ) ;
F_52 ( & V_22 -> V_63 , & V_60 . V_62 ) ;
}
static void F_53 ( struct V_22 * V_22 )
{
F_19 ( ! F_51 ( & V_60 . V_61 ) ) ;
F_54 ( & V_22 -> V_63 ) ;
}
static struct V_22 * F_55 ( struct V_64 * V_65 )
{
struct V_22 * V_22 = NULL , * V_66 ;
F_19 ( ! F_51 ( & V_60 . V_61 ) ) ;
F_56 (tmp, &dm_thin_pool_table.pools, list) {
if ( V_66 -> V_67 == V_65 ) {
V_22 = V_66 ;
break;
}
}
return V_22 ;
}
static struct V_22 * F_57 ( struct V_68 * V_69 )
{
struct V_22 * V_22 = NULL , * V_66 ;
F_19 ( ! F_51 ( & V_60 . V_61 ) ) ;
F_56 (tmp, &dm_thin_pool_table.pools, list) {
if ( V_66 -> V_69 == V_69 ) {
V_22 = V_66 ;
break;
}
}
return V_22 ;
}
static void F_58 ( struct V_52 * V_53 , struct V_52 * V_70 )
{
F_59 ( V_53 , V_70 ) ;
F_60 ( V_70 ) ;
}
static void F_61 ( struct V_52 * V_53 , int error )
{
struct V_29 * V_29 ;
while ( ( V_29 = F_62 ( V_53 ) ) ) {
V_29 -> V_43 = error ;
F_27 ( V_29 ) ;
}
}
static void F_63 ( struct V_27 * V_28 , struct V_52 * V_70 , int error )
{
struct V_52 V_53 ;
unsigned long V_71 ;
F_60 ( & V_53 ) ;
F_64 ( & V_28 -> V_17 , V_71 ) ;
F_58 ( & V_53 , V_70 ) ;
F_65 ( & V_28 -> V_17 , V_71 ) ;
F_61 ( & V_53 , error ) ;
}
static void F_66 ( struct V_27 * V_28 )
{
struct V_22 * V_22 = V_28 -> V_22 ;
unsigned long V_71 ;
struct V_72 V_73 ;
struct V_46 * V_51 , * V_66 ;
F_49 ( & V_73 ) ;
F_64 ( & V_28 -> V_17 , V_71 ) ;
F_67 ( & V_28 -> V_74 , & V_73 ) ;
F_65 ( & V_28 -> V_17 , V_71 ) ;
F_68 (cell, tmp, &cells, user_list)
F_46 ( V_22 , V_51 ) ;
}
static void F_69 ( struct V_27 * V_28 )
{
struct V_52 V_53 ;
unsigned long V_71 ;
F_60 ( & V_53 ) ;
F_64 ( & V_28 -> V_17 , V_71 ) ;
F_58 ( & V_53 , & V_28 -> V_75 ) ;
F_58 ( & V_53 , & V_28 -> V_76 ) ;
F_65 ( & V_28 -> V_17 , V_71 ) ;
F_61 ( & V_53 , V_59 ) ;
F_66 ( V_28 ) ;
}
static void F_70 ( struct V_22 * V_22 , int error )
{
struct V_27 * V_28 ;
F_71 () ;
F_72 (tc, &pool->active_thins, list)
F_63 ( V_28 , & V_28 -> V_76 , error ) ;
F_73 () ;
}
static void F_74 ( struct V_22 * V_22 )
{
int error = F_43 ( V_22 ) ;
F_70 ( V_22 , error ) ;
}
static T_1 F_75 ( struct V_27 * V_28 , struct V_29 * V_29 )
{
struct V_22 * V_22 = V_28 -> V_22 ;
T_2 V_77 = V_29 -> V_78 . V_79 ;
if ( F_16 ( V_22 ) )
V_77 >>= V_22 -> V_23 ;
else
( void ) F_76 ( V_77 , V_22 -> V_24 ) ;
return V_77 ;
}
static void F_77 ( struct V_27 * V_28 , struct V_29 * V_29 ,
T_1 * V_80 , T_1 * V_81 )
{
struct V_22 * V_22 = V_28 -> V_22 ;
T_2 V_5 = V_29 -> V_78 . V_79 ;
T_2 V_6 = V_5 + ( V_29 -> V_78 . V_82 >> V_83 ) ;
V_5 += V_22 -> V_24 - 1ull ;
if ( F_16 ( V_22 ) ) {
V_5 >>= V_22 -> V_23 ;
V_6 >>= V_22 -> V_23 ;
} else {
( void ) F_76 ( V_5 , V_22 -> V_24 ) ;
( void ) F_76 ( V_6 , V_22 -> V_24 ) ;
}
if ( V_6 < V_5 )
V_6 = V_5 ;
* V_80 = V_5 ;
* V_81 = V_6 ;
}
static void F_78 ( struct V_27 * V_28 , struct V_29 * V_29 , T_1 V_84 )
{
struct V_22 * V_22 = V_28 -> V_22 ;
T_2 V_79 = V_29 -> V_78 . V_79 ;
V_29 -> V_85 = V_28 -> V_37 -> V_38 ;
if ( F_16 ( V_22 ) )
V_29 -> V_78 . V_79 =
( V_84 << V_22 -> V_23 ) |
( V_79 & ( V_22 -> V_24 - 1 ) ) ;
else
V_29 -> V_78 . V_79 = ( V_84 * V_22 -> V_24 ) +
F_76 ( V_79 , V_22 -> V_24 ) ;
}
static void F_79 ( struct V_27 * V_28 , struct V_29 * V_29 )
{
V_29 -> V_85 = V_28 -> V_86 -> V_38 ;
}
static int F_80 ( struct V_27 * V_28 , struct V_29 * V_29 )
{
return ( V_29 -> V_87 & ( V_88 | V_89 ) ) &&
F_81 ( V_28 -> V_2 ) ;
}
static void F_82 ( struct V_22 * V_22 , struct V_29 * V_29 )
{
struct V_90 * V_91 ;
if ( V_29 -> V_87 & V_41 )
return;
V_91 = F_83 ( V_29 , sizeof( struct V_90 ) ) ;
V_91 -> V_92 = F_84 ( V_22 -> V_93 ) ;
}
static void F_85 ( struct V_27 * V_28 , struct V_29 * V_29 )
{
struct V_22 * V_22 = V_28 -> V_22 ;
unsigned long V_71 ;
if ( ! F_80 ( V_28 , V_29 ) ) {
F_86 ( V_29 ) ;
return;
}
if ( F_87 ( V_28 -> V_2 ) ) {
F_88 ( V_29 ) ;
return;
}
F_64 ( & V_22 -> V_17 , V_71 ) ;
F_89 ( & V_22 -> V_94 , V_29 ) ;
F_65 ( & V_22 -> V_17 , V_71 ) ;
}
static void F_90 ( struct V_27 * V_28 , struct V_29 * V_29 )
{
F_79 ( V_28 , V_29 ) ;
F_85 ( V_28 , V_29 ) ;
}
static void F_91 ( struct V_27 * V_28 , struct V_29 * V_29 ,
T_1 V_84 )
{
F_78 ( V_28 , V_29 , V_84 ) ;
F_85 ( V_28 , V_29 ) ;
}
static void F_92 ( struct V_95 * V_96 )
{
struct V_22 * V_22 = V_96 -> V_28 -> V_22 ;
if ( F_93 ( & V_96 -> V_97 ) ) {
F_94 ( & V_96 -> V_63 , & V_22 -> V_98 ) ;
F_28 ( V_22 ) ;
}
}
static void F_95 ( struct V_95 * V_96 )
{
unsigned long V_71 ;
struct V_22 * V_22 = V_96 -> V_28 -> V_22 ;
F_64 ( & V_22 -> V_17 , V_71 ) ;
F_92 ( V_96 ) ;
F_65 ( & V_22 -> V_17 , V_71 ) ;
}
static void F_96 ( int V_99 , unsigned long V_100 , void * V_54 )
{
struct V_95 * V_96 = V_54 ;
V_96 -> V_101 = V_99 || V_100 ? - V_58 : 0 ;
F_95 ( V_96 ) ;
}
static void F_97 ( struct V_29 * V_29 )
{
struct V_90 * V_91 = F_83 ( V_29 , sizeof( struct V_90 ) ) ;
struct V_95 * V_96 = V_91 -> V_102 ;
V_29 -> V_103 = V_96 -> V_104 ;
V_96 -> V_101 = V_29 -> V_43 ;
F_95 ( V_96 ) ;
}
static void F_98 ( struct V_27 * V_28 , struct V_46 * V_51 )
{
struct V_22 * V_22 = V_28 -> V_22 ;
unsigned long V_71 ;
F_64 ( & V_28 -> V_17 , V_71 ) ;
F_39 ( V_22 , V_51 , & V_28 -> V_75 ) ;
F_65 ( & V_28 -> V_17 , V_71 ) ;
F_28 ( V_22 ) ;
}
static void F_99 ( void * V_54 ,
struct V_46 * V_51 )
{
struct V_105 * V_106 = V_54 ;
struct V_29 * V_29 ;
while ( ( V_29 = F_62 ( & V_51 -> V_53 ) ) ) {
if ( V_29 -> V_87 & ( V_41 | V_88 | V_89 ) )
F_89 ( & V_106 -> V_107 , V_29 ) ;
else {
F_82 ( V_106 -> V_28 -> V_22 , V_29 ) ;
F_89 ( & V_106 -> V_108 , V_29 ) ;
}
}
}
static void F_100 ( struct V_27 * V_28 ,
struct V_46 * V_51 ,
T_1 V_84 )
{
struct V_29 * V_29 ;
struct V_105 V_106 ;
V_106 . V_28 = V_28 ;
F_60 ( & V_106 . V_107 ) ;
F_60 ( & V_106 . V_108 ) ;
F_36 ( V_28 -> V_22 , F_99 ,
& V_106 , V_51 ) ;
while ( ( V_29 = F_62 ( & V_106 . V_107 ) ) )
F_101 ( V_28 , V_29 ) ;
while ( ( V_29 = F_62 ( & V_106 . V_108 ) ) )
F_91 ( V_106 . V_28 , V_29 , V_84 ) ;
}
static void F_102 ( struct V_95 * V_96 )
{
F_44 ( V_96 -> V_28 -> V_22 , V_96 -> V_51 ) ;
F_54 ( & V_96 -> V_63 ) ;
F_103 ( V_96 , V_96 -> V_28 -> V_22 -> V_109 ) ;
}
static void F_104 ( struct V_95 * V_96 )
{
struct V_27 * V_28 = V_96 -> V_28 ;
struct V_22 * V_22 = V_28 -> V_22 ;
struct V_29 * V_29 = V_96 -> V_29 ;
int V_42 ;
if ( V_96 -> V_101 ) {
F_44 ( V_22 , V_96 -> V_51 ) ;
goto V_110;
}
V_42 = F_105 ( V_28 -> V_2 , V_96 -> V_111 , V_96 -> V_112 ) ;
if ( V_42 ) {
F_106 ( V_22 , L_1 , V_42 ) ;
F_44 ( V_22 , V_96 -> V_51 ) ;
goto V_110;
}
if ( V_29 ) {
F_100 ( V_28 , V_96 -> V_51 , V_96 -> V_112 ) ;
F_27 ( V_29 ) ;
} else {
F_82 ( V_28 -> V_22 , V_96 -> V_51 -> V_113 ) ;
F_91 ( V_28 , V_96 -> V_51 -> V_113 , V_96 -> V_112 ) ;
F_100 ( V_28 , V_96 -> V_51 , V_96 -> V_112 ) ;
}
V_110:
F_54 ( & V_96 -> V_63 ) ;
F_103 ( V_96 , V_22 -> V_109 ) ;
}
static void F_107 ( struct V_95 * V_96 )
{
struct V_27 * V_28 = V_96 -> V_28 ;
if ( V_96 -> V_51 )
F_98 ( V_28 , V_96 -> V_51 ) ;
F_103 ( V_96 , V_28 -> V_22 -> V_109 ) ;
}
static void F_108 ( struct V_95 * V_96 )
{
F_88 ( V_96 -> V_29 ) ;
F_107 ( V_96 ) ;
}
static void F_109 ( struct V_95 * V_96 )
{
F_27 ( V_96 -> V_29 ) ;
F_107 ( V_96 ) ;
}
static void F_110 ( struct V_95 * V_96 )
{
int V_42 ;
struct V_27 * V_28 = V_96 -> V_28 ;
V_42 = F_111 ( V_28 -> V_2 , V_96 -> V_51 -> V_8 . V_12 , V_96 -> V_51 -> V_8 . V_13 ) ;
if ( V_42 ) {
F_106 ( V_28 -> V_22 , L_2 , V_42 ) ;
F_88 ( V_96 -> V_29 ) ;
} else
F_27 ( V_96 -> V_29 ) ;
F_98 ( V_28 , V_96 -> V_51 ) ;
F_103 ( V_96 , V_28 -> V_22 -> V_109 ) ;
}
static void F_112 ( struct V_95 * V_96 )
{
int V_42 = 0 ;
bool V_114 = true ;
struct V_27 * V_28 = V_96 -> V_28 ;
struct V_22 * V_22 = V_28 -> V_22 ;
T_1 V_5 = V_96 -> V_112 , V_6 , V_81 = V_96 -> V_112 + V_96 -> V_115 - V_96 -> V_111 ;
struct V_25 V_26 ;
F_18 ( & V_26 , V_28 , V_96 -> V_29 ) ;
while ( V_5 != V_81 ) {
for (; V_5 < V_81 ; V_5 ++ ) {
V_42 = F_113 ( V_22 -> V_116 , V_5 , & V_114 ) ;
if ( V_42 )
goto V_110;
if ( ! V_114 )
break;
}
if ( V_5 == V_81 )
break;
for ( V_6 = V_5 + 1 ; V_6 != V_81 ; V_6 ++ ) {
V_42 = F_113 ( V_22 -> V_116 , V_6 , & V_114 ) ;
if ( V_42 )
goto V_110;
if ( V_114 )
break;
}
V_42 = F_21 ( & V_26 , V_5 , V_6 ) ;
if ( V_42 )
goto V_110;
V_5 = V_6 ;
}
V_110:
F_23 ( & V_26 , V_42 ) ;
}
static void F_114 ( struct V_95 * V_96 )
{
int V_42 ;
struct V_27 * V_28 = V_96 -> V_28 ;
struct V_22 * V_22 = V_28 -> V_22 ;
V_42 = F_111 ( V_28 -> V_2 , V_96 -> V_111 , V_96 -> V_115 ) ;
if ( V_42 ) {
F_106 ( V_22 , L_2 , V_42 ) ;
F_88 ( V_96 -> V_29 ) ;
} else if ( V_96 -> V_117 ) {
F_112 ( V_96 ) ;
} else {
struct V_25 V_26 ;
F_18 ( & V_26 , V_28 , V_96 -> V_29 ) ;
V_42 = F_21 ( & V_26 , V_96 -> V_112 ,
V_96 -> V_112 + ( V_96 -> V_115 - V_96 -> V_111 ) ) ;
F_23 ( & V_26 , V_42 ) ;
}
F_98 ( V_28 , V_96 -> V_51 ) ;
F_103 ( V_96 , V_22 -> V_109 ) ;
}
static void F_115 ( struct V_22 * V_22 , struct V_72 * V_118 ,
T_3 * F_37 )
{
unsigned long V_71 ;
struct V_72 V_119 ;
struct V_95 * V_96 , * V_66 ;
F_49 ( & V_119 ) ;
F_64 ( & V_22 -> V_17 , V_71 ) ;
F_67 ( V_118 , & V_119 ) ;
F_65 ( & V_22 -> V_17 , V_71 ) ;
F_68 ( V_96 , V_66 , & V_119 , V_63 )
( * F_37 ) ( V_96 ) ;
}
static int F_116 ( struct V_22 * V_22 , struct V_29 * V_29 )
{
return V_29 -> V_78 . V_82 ==
( V_22 -> V_24 << V_83 ) ;
}
static int F_117 ( struct V_22 * V_22 , struct V_29 * V_29 )
{
return ( F_118 ( V_29 ) == V_120 ) &&
F_116 ( V_22 , V_29 ) ;
}
static void F_119 ( struct V_29 * V_29 , T_4 * * V_121 ,
T_4 * F_37 )
{
* V_121 = V_29 -> V_103 ;
V_29 -> V_103 = F_37 ;
}
static int F_120 ( struct V_22 * V_22 )
{
if ( V_22 -> V_122 )
return 0 ;
V_22 -> V_122 = F_121 ( V_22 -> V_109 , V_123 ) ;
return V_22 -> V_122 ? 0 : - V_124 ;
}
static struct V_95 * F_122 ( struct V_22 * V_22 )
{
struct V_95 * V_96 = V_22 -> V_122 ;
F_19 ( ! V_22 -> V_122 ) ;
memset ( V_96 , 0 , sizeof( struct V_95 ) ) ;
F_49 ( & V_96 -> V_63 ) ;
V_96 -> V_29 = NULL ;
V_22 -> V_122 = NULL ;
return V_96 ;
}
static void F_123 ( struct V_27 * V_28 , struct V_95 * V_96 ,
T_2 V_80 , T_2 V_81 )
{
int V_42 ;
struct V_125 V_126 ;
V_126 . V_38 = V_28 -> V_37 -> V_38 ;
V_126 . V_127 = V_80 ;
V_126 . V_128 = V_81 - V_80 ;
V_42 = F_124 ( V_28 -> V_22 -> V_129 , 1 , & V_126 , 0 , F_96 , V_96 ) ;
if ( V_42 < 0 ) {
F_125 ( L_3 ) ;
F_96 ( 1 , 1 , V_96 ) ;
}
}
static void F_126 ( struct V_27 * V_28 , struct V_29 * V_29 ,
T_1 V_130 ,
struct V_95 * V_96 )
{
struct V_22 * V_22 = V_28 -> V_22 ;
struct V_90 * V_91 = F_83 ( V_29 , sizeof( struct V_90 ) ) ;
V_91 -> V_102 = V_96 ;
V_96 -> V_29 = V_29 ;
F_119 ( V_29 , & V_96 -> V_104 , F_97 ) ;
F_82 ( V_22 , V_29 ) ;
F_91 ( V_28 , V_29 , V_130 ) ;
}
static void F_127 ( struct V_27 * V_28 , T_1 V_131 ,
struct V_132 * V_133 , T_1 V_134 ,
T_1 V_135 ,
struct V_46 * V_51 , struct V_29 * V_29 ,
T_2 V_36 )
{
int V_42 ;
struct V_22 * V_22 = V_28 -> V_22 ;
struct V_95 * V_96 = F_122 ( V_22 ) ;
V_96 -> V_28 = V_28 ;
V_96 -> V_111 = V_131 ;
V_96 -> V_115 = V_131 + 1u ;
V_96 -> V_112 = V_135 ;
V_96 -> V_51 = V_51 ;
F_128 ( & V_96 -> V_97 , 3 ) ;
if ( ! F_129 ( V_22 -> V_136 , & V_96 -> V_63 ) )
F_95 ( V_96 ) ;
if ( F_117 ( V_22 , V_29 ) )
F_126 ( V_28 , V_29 , V_135 , V_96 ) ;
else {
struct V_125 V_137 , V_126 ;
V_137 . V_38 = V_133 -> V_38 ;
V_137 . V_127 = V_134 * V_22 -> V_24 ;
V_137 . V_128 = V_36 ;
V_126 . V_38 = V_28 -> V_37 -> V_38 ;
V_126 . V_127 = V_135 * V_22 -> V_24 ;
V_126 . V_128 = V_36 ;
V_42 = F_130 ( V_22 -> V_129 , & V_137 , 1 , & V_126 ,
0 , F_96 , V_96 ) ;
if ( V_42 < 0 ) {
F_125 ( L_4 ) ;
F_96 ( 1 , 1 , V_96 ) ;
}
if ( V_36 < V_22 -> V_24 && V_22 -> V_138 . V_139 ) {
F_131 ( & V_96 -> V_97 ) ;
F_123 ( V_28 , V_96 ,
V_135 * V_22 -> V_24 + V_36 ,
( V_135 + 1 ) * V_22 -> V_24 ) ;
}
}
F_95 ( V_96 ) ;
}
static void F_132 ( struct V_27 * V_28 , T_1 V_131 ,
T_1 V_134 , T_1 V_135 ,
struct V_46 * V_51 , struct V_29 * V_29 )
{
F_127 ( V_28 , V_131 , V_28 -> V_37 ,
V_134 , V_135 , V_51 , V_29 ,
V_28 -> V_22 -> V_24 ) ;
}
static void F_133 ( struct V_27 * V_28 , T_1 V_131 ,
T_1 V_112 , struct V_46 * V_51 ,
struct V_29 * V_29 )
{
struct V_22 * V_22 = V_28 -> V_22 ;
struct V_95 * V_96 = F_122 ( V_22 ) ;
F_128 ( & V_96 -> V_97 , 1 ) ;
V_96 -> V_28 = V_28 ;
V_96 -> V_111 = V_131 ;
V_96 -> V_115 = V_131 + 1u ;
V_96 -> V_112 = V_112 ;
V_96 -> V_51 = V_51 ;
if ( V_22 -> V_138 . V_139 ) {
if ( F_117 ( V_22 , V_29 ) )
F_126 ( V_28 , V_29 , V_112 , V_96 ) ;
else
F_123 ( V_28 , V_96 , V_112 * V_22 -> V_24 ,
( V_112 + 1 ) * V_22 -> V_24 ) ;
} else
F_104 ( V_96 ) ;
}
static void F_134 ( struct V_27 * V_28 , T_1 V_131 ,
T_1 V_135 ,
struct V_46 * V_51 , struct V_29 * V_29 )
{
struct V_22 * V_22 = V_28 -> V_22 ;
T_2 V_140 = V_131 * V_22 -> V_24 ;
T_2 V_141 = ( V_131 + 1 ) * V_22 -> V_24 ;
if ( V_141 <= V_28 -> V_142 )
F_127 ( V_28 , V_131 , V_28 -> V_86 ,
V_131 , V_135 , V_51 , V_29 ,
V_22 -> V_24 ) ;
else if ( V_140 < V_28 -> V_142 )
F_127 ( V_28 , V_131 , V_28 -> V_86 ,
V_131 , V_135 , V_51 , V_29 ,
V_28 -> V_142 - V_140 ) ;
else
F_133 ( V_28 , V_131 , V_135 , V_51 , V_29 ) ;
}
static void F_135 ( struct V_22 * V_22 )
{
int V_42 ;
T_1 V_143 ;
if ( F_136 ( V_22 ) != V_144 )
return;
V_42 = F_137 ( V_22 -> V_116 , & V_143 ) ;
if ( V_42 )
return;
if ( V_143 )
F_138 ( V_22 , V_145 ) ;
}
static int F_139 ( struct V_22 * V_22 )
{
int V_42 ;
if ( F_136 ( V_22 ) >= V_146 )
return - V_147 ;
V_42 = F_140 ( V_22 -> V_116 ) ;
if ( V_42 )
F_106 ( V_22 , L_5 , V_42 ) ;
else
F_135 ( V_22 ) ;
return V_42 ;
}
static void F_141 ( struct V_22 * V_22 , T_1 V_148 )
{
unsigned long V_71 ;
if ( V_148 <= V_22 -> V_149 && ! V_22 -> V_150 ) {
F_142 ( L_6 ,
F_143 ( V_22 -> V_67 ) ) ;
F_64 ( & V_22 -> V_17 , V_71 ) ;
V_22 -> V_150 = true ;
F_65 ( & V_22 -> V_17 , V_71 ) ;
F_144 ( V_22 -> V_151 -> V_152 ) ;
}
}
static int F_145 ( struct V_27 * V_28 , T_1 * V_153 )
{
int V_42 ;
T_1 V_148 ;
struct V_22 * V_22 = V_28 -> V_22 ;
if ( F_146 ( F_136 ( V_22 ) != V_145 ) )
return - V_147 ;
V_42 = F_137 ( V_22 -> V_116 , & V_148 ) ;
if ( V_42 ) {
F_106 ( V_22 , L_7 , V_42 ) ;
return V_42 ;
}
F_141 ( V_22 , V_148 ) ;
if ( ! V_148 ) {
V_42 = F_139 ( V_22 ) ;
if ( V_42 )
return V_42 ;
V_42 = F_137 ( V_22 -> V_116 , & V_148 ) ;
if ( V_42 ) {
F_106 ( V_22 , L_7 , V_42 ) ;
return V_42 ;
}
if ( ! V_148 ) {
F_138 ( V_22 , V_144 ) ;
return - V_57 ;
}
}
V_42 = F_147 ( V_22 -> V_116 , V_153 ) ;
if ( V_42 ) {
F_106 ( V_22 , L_8 , V_42 ) ;
return V_42 ;
}
return 0 ;
}
static void F_148 ( struct V_29 * V_29 )
{
struct V_90 * V_91 = F_83 ( V_29 , sizeof( struct V_90 ) ) ;
struct V_27 * V_28 = V_91 -> V_28 ;
unsigned long V_71 ;
F_64 ( & V_28 -> V_17 , V_71 ) ;
F_89 ( & V_28 -> V_76 , V_29 ) ;
F_65 ( & V_28 -> V_17 , V_71 ) ;
}
static int F_149 ( struct V_22 * V_22 )
{
enum V_154 V_96 = F_136 ( V_22 ) ;
switch ( V_96 ) {
case V_145 :
F_125 ( L_9 ) ;
return - V_58 ;
case V_144 :
return V_22 -> V_138 . V_155 ? - V_57 : 0 ;
case V_146 :
case V_156 :
return - V_58 ;
default:
F_125 ( L_10 ) ;
return - V_58 ;
}
}
static void F_150 ( struct V_22 * V_22 , struct V_29 * V_29 )
{
int error = F_149 ( V_22 ) ;
if ( error ) {
V_29 -> V_43 = error ;
F_27 ( V_29 ) ;
} else
F_148 ( V_29 ) ;
}
static void F_151 ( struct V_22 * V_22 , struct V_46 * V_51 )
{
struct V_29 * V_29 ;
struct V_52 V_53 ;
int error ;
error = F_149 ( V_22 ) ;
if ( error ) {
F_41 ( V_22 , V_51 , error ) ;
return;
}
F_60 ( & V_53 ) ;
F_34 ( V_22 , V_51 , & V_53 ) ;
while ( ( V_29 = F_62 ( & V_53 ) ) )
F_148 ( V_29 ) ;
}
static void F_152 ( struct V_27 * V_28 ,
struct V_46 * V_157 )
{
struct V_22 * V_22 = V_28 -> V_22 ;
struct V_95 * V_96 = F_122 ( V_22 ) ;
V_96 -> V_28 = V_28 ;
V_96 -> V_111 = V_157 -> V_8 . V_12 ;
V_96 -> V_115 = V_157 -> V_8 . V_13 ;
V_96 -> V_51 = V_157 ;
V_96 -> V_29 = V_157 -> V_113 ;
if ( ! F_129 ( V_22 -> V_93 , & V_96 -> V_63 ) )
V_22 -> V_158 ( V_96 ) ;
}
static void F_153 ( struct V_27 * V_28 , T_1 V_80 , T_1 V_81 ,
struct V_29 * V_29 )
{
struct V_22 * V_22 = V_28 -> V_22 ;
int V_42 ;
bool V_117 ;
struct V_7 V_159 ;
struct V_46 * V_160 ;
struct V_95 * V_96 ;
T_1 V_111 , V_115 , V_130 ;
while ( V_80 != V_81 ) {
V_42 = F_120 ( V_22 ) ;
if ( V_42 )
return;
V_42 = F_154 ( V_28 -> V_2 , V_80 , V_81 , & V_111 , & V_115 ,
& V_130 , & V_117 ) ;
if ( V_42 )
break;
F_1 ( V_28 -> V_2 , V_14 , V_130 , V_130 + ( V_115 - V_111 ) , & V_159 ) ;
if ( F_30 ( V_28 -> V_22 , & V_159 , NULL , & V_160 ) ) {
V_80 = V_115 ;
continue;
}
V_96 = F_122 ( V_22 ) ;
V_96 -> V_28 = V_28 ;
V_96 -> V_117 = V_117 ;
V_96 -> V_111 = V_111 ;
V_96 -> V_115 = V_115 ;
V_96 -> V_112 = V_130 ;
V_96 -> V_51 = V_160 ;
V_96 -> V_29 = V_29 ;
F_155 ( V_29 ) ;
if ( ! F_129 ( V_22 -> V_93 , & V_96 -> V_63 ) )
V_22 -> V_158 ( V_96 ) ;
V_80 = V_115 ;
}
}
static void F_156 ( struct V_27 * V_28 , struct V_46 * V_157 )
{
struct V_29 * V_29 = V_157 -> V_113 ;
struct V_90 * V_91 = F_83 ( V_29 , sizeof( struct V_90 ) ) ;
V_91 -> V_51 = V_157 ;
F_153 ( V_28 , V_157 -> V_8 . V_12 , V_157 -> V_8 . V_13 , V_29 ) ;
F_27 ( V_29 ) ;
}
static void F_157 ( struct V_27 * V_28 , struct V_29 * V_29 )
{
T_1 V_80 , V_81 ;
struct V_7 V_161 ;
struct V_46 * V_157 ;
F_77 ( V_28 , V_29 , & V_80 , & V_81 ) ;
if ( V_80 == V_81 ) {
F_27 ( V_29 ) ;
return;
}
F_1 ( V_28 -> V_2 , V_10 , V_80 , V_81 , & V_161 ) ;
if ( F_30 ( V_28 -> V_22 , & V_161 , V_29 , & V_157 ) )
return;
V_28 -> V_22 -> V_162 ( V_28 , V_157 ) ;
}
static void F_158 ( struct V_27 * V_28 , struct V_29 * V_29 , T_1 V_84 ,
struct V_7 * V_8 ,
struct V_163 * V_164 ,
struct V_46 * V_51 )
{
int V_42 ;
T_1 V_112 ;
struct V_22 * V_22 = V_28 -> V_22 ;
V_42 = F_145 ( V_28 , & V_112 ) ;
switch ( V_42 ) {
case 0 :
F_132 ( V_28 , V_84 , V_164 -> V_84 ,
V_112 , V_51 , V_29 ) ;
break;
case - V_57 :
F_151 ( V_22 , V_51 ) ;
break;
default:
F_125 ( L_11 ,
V_165 , V_42 ) ;
F_44 ( V_22 , V_51 ) ;
break;
}
}
static void F_159 ( void * V_54 ,
struct V_46 * V_51 )
{
struct V_105 * V_106 = V_54 ;
struct V_29 * V_29 ;
while ( ( V_29 = F_62 ( & V_51 -> V_53 ) ) ) {
if ( ( F_118 ( V_29 ) == V_120 ) ||
( V_29 -> V_87 & ( V_41 | V_88 | V_89 ) ) )
F_89 ( & V_106 -> V_107 , V_29 ) ;
else {
struct V_90 * V_91 = F_83 ( V_29 , sizeof( struct V_90 ) ) ; ;
V_91 -> V_166 = F_84 ( V_106 -> V_28 -> V_22 -> V_136 ) ;
F_82 ( V_106 -> V_28 -> V_22 , V_29 ) ;
F_89 ( & V_106 -> V_108 , V_29 ) ;
}
}
}
static void F_160 ( struct V_27 * V_28 ,
struct V_46 * V_51 ,
T_1 V_84 )
{
struct V_29 * V_29 ;
struct V_105 V_106 ;
V_106 . V_28 = V_28 ;
F_60 ( & V_106 . V_107 ) ;
F_60 ( & V_106 . V_108 ) ;
F_36 ( V_28 -> V_22 , F_159 ,
& V_106 , V_51 ) ;
while ( ( V_29 = F_62 ( & V_106 . V_107 ) ) )
F_101 ( V_28 , V_29 ) ;
while ( ( V_29 = F_62 ( & V_106 . V_108 ) ) )
F_91 ( V_28 , V_29 , V_84 ) ;
}
static void F_161 ( struct V_27 * V_28 , struct V_29 * V_29 ,
T_1 V_84 ,
struct V_163 * V_164 ,
struct V_46 * V_157 )
{
struct V_46 * V_160 ;
struct V_22 * V_22 = V_28 -> V_22 ;
struct V_7 V_8 ;
F_3 ( V_28 -> V_2 , V_164 -> V_84 , & V_8 ) ;
if ( F_30 ( V_22 , & V_8 , V_29 , & V_160 ) ) {
F_98 ( V_28 , V_157 ) ;
return;
}
if ( F_118 ( V_29 ) == V_120 && V_29 -> V_78 . V_82 ) {
F_158 ( V_28 , V_29 , V_84 , & V_8 , V_164 , V_160 ) ;
F_98 ( V_28 , V_157 ) ;
} else {
struct V_90 * V_91 = F_83 ( V_29 , sizeof( struct V_90 ) ) ;
V_91 -> V_166 = F_84 ( V_22 -> V_136 ) ;
F_82 ( V_22 , V_29 ) ;
F_91 ( V_28 , V_29 , V_164 -> V_84 ) ;
F_160 ( V_28 , V_160 , V_164 -> V_84 ) ;
F_160 ( V_28 , V_157 , V_164 -> V_84 ) ;
}
}
static void F_162 ( struct V_27 * V_28 , struct V_29 * V_29 , T_1 V_84 ,
struct V_46 * V_51 )
{
int V_42 ;
T_1 V_112 ;
struct V_22 * V_22 = V_28 -> V_22 ;
if ( ! V_29 -> V_78 . V_82 ) {
F_82 ( V_22 , V_29 ) ;
F_98 ( V_28 , V_51 ) ;
F_91 ( V_28 , V_29 , 0 ) ;
return;
}
if ( F_118 ( V_29 ) == V_167 ) {
F_163 ( V_29 ) ;
F_98 ( V_28 , V_51 ) ;
F_27 ( V_29 ) ;
return;
}
V_42 = F_145 ( V_28 , & V_112 ) ;
switch ( V_42 ) {
case 0 :
if ( V_28 -> V_86 )
F_134 ( V_28 , V_84 , V_112 , V_51 , V_29 ) ;
else
F_133 ( V_28 , V_84 , V_112 , V_51 , V_29 ) ;
break;
case - V_57 :
F_151 ( V_22 , V_51 ) ;
break;
default:
F_125 ( L_11 ,
V_165 , V_42 ) ;
F_44 ( V_22 , V_51 ) ;
break;
}
}
static void F_164 ( struct V_27 * V_28 , struct V_46 * V_51 )
{
int V_42 ;
struct V_22 * V_22 = V_28 -> V_22 ;
struct V_29 * V_29 = V_51 -> V_113 ;
T_1 V_84 = F_75 ( V_28 , V_29 ) ;
struct V_163 V_164 ;
if ( V_28 -> V_168 ) {
F_46 ( V_22 , V_51 ) ;
return;
}
V_42 = F_165 ( V_28 -> V_2 , V_84 , 1 , & V_164 ) ;
switch ( V_42 ) {
case 0 :
if ( V_164 . V_169 )
F_161 ( V_28 , V_29 , V_84 , & V_164 , V_51 ) ;
else {
F_82 ( V_22 , V_29 ) ;
F_91 ( V_28 , V_29 , V_164 . V_84 ) ;
F_100 ( V_28 , V_51 , V_164 . V_84 ) ;
}
break;
case - V_170 :
if ( F_118 ( V_29 ) == V_167 && V_28 -> V_86 ) {
F_82 ( V_22 , V_29 ) ;
F_98 ( V_28 , V_51 ) ;
if ( F_166 ( V_29 ) <= V_28 -> V_142 )
F_90 ( V_28 , V_29 ) ;
else if ( V_29 -> V_78 . V_79 < V_28 -> V_142 ) {
F_163 ( V_29 ) ;
V_29 -> V_78 . V_82 = ( V_28 -> V_142 - V_29 -> V_78 . V_79 ) << V_83 ;
F_90 ( V_28 , V_29 ) ;
} else {
F_163 ( V_29 ) ;
F_27 ( V_29 ) ;
}
} else
F_162 ( V_28 , V_29 , V_84 , V_51 ) ;
break;
default:
F_125 ( L_12 ,
V_165 , V_42 ) ;
F_98 ( V_28 , V_51 ) ;
F_88 ( V_29 ) ;
break;
}
}
static void F_167 ( struct V_27 * V_28 , struct V_29 * V_29 )
{
struct V_22 * V_22 = V_28 -> V_22 ;
T_1 V_84 = F_75 ( V_28 , V_29 ) ;
struct V_46 * V_51 ;
struct V_7 V_8 ;
F_4 ( V_28 -> V_2 , V_84 , & V_8 ) ;
if ( F_30 ( V_22 , & V_8 , V_29 , & V_51 ) )
return;
F_164 ( V_28 , V_51 ) ;
}
static void F_168 ( struct V_27 * V_28 , struct V_29 * V_29 ,
struct V_46 * V_51 )
{
int V_42 ;
int V_171 = F_118 ( V_29 ) ;
T_1 V_84 = F_75 ( V_28 , V_29 ) ;
struct V_163 V_164 ;
V_42 = F_165 ( V_28 -> V_2 , V_84 , 1 , & V_164 ) ;
switch ( V_42 ) {
case 0 :
if ( V_164 . V_169 && ( V_171 == V_120 ) && V_29 -> V_78 . V_82 ) {
F_150 ( V_28 -> V_22 , V_29 ) ;
if ( V_51 )
F_98 ( V_28 , V_51 ) ;
} else {
F_82 ( V_28 -> V_22 , V_29 ) ;
F_91 ( V_28 , V_29 , V_164 . V_84 ) ;
if ( V_51 )
F_100 ( V_28 , V_51 , V_164 . V_84 ) ;
}
break;
case - V_170 :
if ( V_51 )
F_98 ( V_28 , V_51 ) ;
if ( V_171 != V_167 ) {
F_150 ( V_28 -> V_22 , V_29 ) ;
break;
}
if ( V_28 -> V_86 ) {
F_82 ( V_28 -> V_22 , V_29 ) ;
F_90 ( V_28 , V_29 ) ;
break;
}
F_163 ( V_29 ) ;
F_27 ( V_29 ) ;
break;
default:
F_125 ( L_12 ,
V_165 , V_42 ) ;
if ( V_51 )
F_98 ( V_28 , V_51 ) ;
F_88 ( V_29 ) ;
break;
}
}
static void F_169 ( struct V_27 * V_28 , struct V_29 * V_29 )
{
F_168 ( V_28 , V_29 , NULL ) ;
}
static void F_170 ( struct V_27 * V_28 , struct V_46 * V_51 )
{
F_168 ( V_28 , V_51 -> V_113 , V_51 ) ;
}
static void F_171 ( struct V_27 * V_28 , struct V_29 * V_29 )
{
F_27 ( V_29 ) ;
}
static void F_172 ( struct V_27 * V_28 , struct V_29 * V_29 )
{
F_88 ( V_29 ) ;
}
static void F_173 ( struct V_27 * V_28 , struct V_46 * V_51 )
{
F_45 ( V_28 -> V_22 , V_51 ) ;
}
static void F_174 ( struct V_27 * V_28 , struct V_46 * V_51 )
{
F_44 ( V_28 -> V_22 , V_51 ) ;
}
static int F_175 ( struct V_22 * V_22 )
{
return ! F_176 ( V_20 , V_22 -> V_172 ,
V_22 -> V_172 + V_173 ) ;
}
static void F_177 ( struct V_27 * V_28 , struct V_29 * V_29 )
{
struct V_174 * * V_175 , * V_30 ;
struct V_90 * V_176 ;
T_2 V_79 = V_29 -> V_78 . V_79 ;
V_175 = & V_28 -> V_177 . V_174 ;
V_30 = NULL ;
while ( * V_175 ) {
V_30 = * V_175 ;
V_176 = F_178 ( V_30 ) ;
if ( V_79 < F_179 ( V_176 ) -> V_78 . V_79 )
V_175 = & ( * V_175 ) -> V_178 ;
else
V_175 = & ( * V_175 ) -> V_179 ;
}
V_176 = F_83 ( V_29 , sizeof( struct V_90 ) ) ;
F_180 ( & V_176 -> V_174 , V_30 , V_175 ) ;
F_181 ( & V_176 -> V_174 , & V_28 -> V_177 ) ;
}
static void F_182 ( struct V_27 * V_28 )
{
struct V_174 * V_180 ;
struct V_90 * V_176 ;
struct V_29 * V_29 ;
for ( V_180 = F_183 ( & V_28 -> V_177 ) ; V_180 ; V_180 = F_184 ( V_180 ) ) {
V_176 = F_178 ( V_180 ) ;
V_29 = F_179 ( V_176 ) ;
F_89 ( & V_28 -> V_75 , V_29 ) ;
F_185 ( & V_176 -> V_174 , & V_28 -> V_177 ) ;
}
F_146 ( ! F_186 ( & V_28 -> V_177 ) ) ;
}
static void F_187 ( struct V_27 * V_28 )
{
struct V_29 * V_29 ;
struct V_52 V_53 ;
F_60 ( & V_53 ) ;
F_59 ( & V_53 , & V_28 -> V_75 ) ;
F_60 ( & V_28 -> V_75 ) ;
while ( ( V_29 = F_62 ( & V_53 ) ) )
F_177 ( V_28 , V_29 ) ;
F_182 ( V_28 ) ;
}
static void F_188 ( struct V_27 * V_28 )
{
struct V_22 * V_22 = V_28 -> V_22 ;
unsigned long V_71 ;
struct V_29 * V_29 ;
struct V_52 V_53 ;
struct V_181 V_31 ;
unsigned V_128 = 0 ;
if ( V_28 -> V_168 ) {
F_63 ( V_28 , & V_28 -> V_75 , V_59 ) ;
return;
}
F_60 ( & V_53 ) ;
F_64 ( & V_28 -> V_17 , V_71 ) ;
if ( F_189 ( & V_28 -> V_75 ) ) {
F_65 ( & V_28 -> V_17 , V_71 ) ;
return;
}
F_187 ( V_28 ) ;
F_59 ( & V_53 , & V_28 -> V_75 ) ;
F_60 ( & V_28 -> V_75 ) ;
F_65 ( & V_28 -> V_17 , V_71 ) ;
F_20 ( & V_31 ) ;
while ( ( V_29 = F_62 ( & V_53 ) ) ) {
if ( F_120 ( V_22 ) ) {
F_64 ( & V_28 -> V_17 , V_71 ) ;
F_89 ( & V_28 -> V_75 , V_29 ) ;
F_59 ( & V_28 -> V_75 , & V_53 ) ;
F_65 ( & V_28 -> V_17 , V_71 ) ;
break;
}
if ( V_29 -> V_87 & V_41 )
V_22 -> V_182 ( V_28 , V_29 ) ;
else
V_22 -> F_167 ( V_28 , V_29 ) ;
if ( ( V_128 ++ & 127 ) == 0 ) {
F_8 ( & V_22 -> V_15 ) ;
F_190 ( V_22 -> V_116 ) ;
}
}
F_26 ( & V_31 ) ;
}
static int F_191 ( const void * V_183 , const void * V_184 )
{
struct V_46 * V_185 = * ( (struct V_46 * * ) V_183 ) ;
struct V_46 * V_186 = * ( (struct V_46 * * ) V_184 ) ;
F_19 ( ! V_185 -> V_113 ) ;
F_19 ( ! V_186 -> V_113 ) ;
if ( V_185 -> V_113 -> V_78 . V_79 < V_186 -> V_113 -> V_78 . V_79 )
return - 1 ;
if ( V_185 -> V_113 -> V_78 . V_79 > V_186 -> V_113 -> V_78 . V_79 )
return 1 ;
return 0 ;
}
static unsigned F_192 ( struct V_22 * V_22 , struct V_72 * V_73 )
{
unsigned V_128 = 0 ;
struct V_46 * V_51 , * V_66 ;
F_68 (cell, tmp, cells, user_list) {
if ( V_128 >= V_187 )
break;
V_22 -> V_188 [ V_128 ++ ] = V_51 ;
F_54 ( & V_51 -> V_189 ) ;
}
F_193 ( V_22 -> V_188 , V_128 , sizeof( V_51 ) , F_191 , NULL ) ;
return V_128 ;
}
static void F_194 ( struct V_27 * V_28 )
{
struct V_22 * V_22 = V_28 -> V_22 ;
unsigned long V_71 ;
struct V_72 V_73 ;
struct V_46 * V_51 ;
unsigned V_190 , V_191 , V_128 ;
F_49 ( & V_73 ) ;
F_64 ( & V_28 -> V_17 , V_71 ) ;
F_67 ( & V_28 -> V_74 , & V_73 ) ;
F_65 ( & V_28 -> V_17 , V_71 ) ;
if ( F_195 ( & V_73 ) )
return;
do {
V_128 = F_192 ( V_28 -> V_22 , & V_73 ) ;
for ( V_190 = 0 ; V_190 < V_128 ; V_190 ++ ) {
V_51 = V_22 -> V_188 [ V_190 ] ;
F_19 ( ! V_51 -> V_113 ) ;
if ( F_120 ( V_22 ) ) {
for ( V_191 = V_190 ; V_191 < V_128 ; V_191 ++ )
F_52 ( & V_22 -> V_188 [ V_191 ] -> V_189 , & V_73 ) ;
F_64 ( & V_28 -> V_17 , V_71 ) ;
F_196 ( & V_73 , & V_28 -> V_74 ) ;
F_65 ( & V_28 -> V_17 , V_71 ) ;
return;
}
if ( V_51 -> V_113 -> V_87 & V_41 )
V_22 -> V_162 ( V_28 , V_51 ) ;
else
V_22 -> F_164 ( V_28 , V_51 ) ;
}
} while ( ! F_195 ( & V_73 ) );
}
static struct V_27 * F_197 ( struct V_22 * V_22 )
{
struct V_27 * V_28 = NULL ;
F_71 () ;
if ( ! F_195 ( & V_22 -> V_192 ) ) {
V_28 = F_198 ( V_22 -> V_192 . V_193 , struct V_27 , V_63 ) ;
F_199 ( V_28 ) ;
}
F_73 () ;
return V_28 ;
}
static struct V_27 * F_200 ( struct V_22 * V_22 , struct V_27 * V_28 )
{
struct V_27 * V_194 = V_28 ;
F_71 () ;
F_201 (tc, &pool->active_thins, list) {
F_199 ( V_28 ) ;
F_202 ( V_194 ) ;
F_73 () ;
return V_28 ;
}
F_202 ( V_194 ) ;
F_73 () ;
return NULL ;
}
static void F_203 ( struct V_22 * V_22 )
{
unsigned long V_71 ;
struct V_29 * V_29 ;
struct V_52 V_53 ;
struct V_27 * V_28 ;
V_28 = F_197 ( V_22 ) ;
while ( V_28 ) {
F_194 ( V_28 ) ;
F_188 ( V_28 ) ;
V_28 = F_200 ( V_22 , V_28 ) ;
}
F_60 ( & V_53 ) ;
F_64 ( & V_22 -> V_17 , V_71 ) ;
F_59 ( & V_53 , & V_22 -> V_94 ) ;
F_60 ( & V_22 -> V_94 ) ;
F_65 ( & V_22 -> V_17 , V_71 ) ;
if ( F_189 ( & V_53 ) &&
! ( F_204 ( V_22 -> V_116 ) && F_175 ( V_22 ) ) )
return;
if ( F_139 ( V_22 ) ) {
while ( ( V_29 = F_62 ( & V_53 ) ) )
F_88 ( V_29 ) ;
return;
}
V_22 -> V_172 = V_20 ;
while ( ( V_29 = F_62 ( & V_53 ) ) )
F_86 ( V_29 ) ;
}
static void F_205 ( struct V_195 * V_196 )
{
struct V_22 * V_22 = F_206 ( V_196 , struct V_22 , V_45 ) ;
F_7 ( & V_22 -> V_15 ) ;
F_190 ( V_22 -> V_116 ) ;
F_8 ( & V_22 -> V_15 ) ;
F_115 ( V_22 , & V_22 -> V_98 , & V_22 -> F_104 ) ;
F_8 ( & V_22 -> V_15 ) ;
F_115 ( V_22 , & V_22 -> V_197 , & V_22 -> V_158 ) ;
F_8 ( & V_22 -> V_15 ) ;
F_203 ( V_22 ) ;
F_10 ( & V_22 -> V_15 ) ;
}
static void F_207 ( struct V_195 * V_196 )
{
struct V_22 * V_22 = F_206 ( F_208 ( V_196 ) , struct V_22 , V_198 ) ;
F_28 ( V_22 ) ;
F_209 ( V_22 -> V_44 , & V_22 -> V_198 , V_173 ) ;
}
static void F_210 ( struct V_195 * V_196 )
{
struct V_22 * V_22 = F_206 ( F_208 ( V_196 ) , struct V_22 ,
V_199 ) ;
if ( F_136 ( V_22 ) == V_144 && ! V_22 -> V_138 . V_155 ) {
V_22 -> V_138 . V_155 = true ;
F_211 ( V_22 ) ;
F_70 ( V_22 , - V_57 ) ;
}
}
static struct V_200 * F_212 ( struct V_195 * V_196 )
{
return F_206 ( V_196 , struct V_200 , V_45 ) ;
}
static void F_213 ( struct V_200 * V_201 )
{
F_214 ( & V_201 -> F_214 ) ;
}
static void F_215 ( struct V_200 * V_201 , struct V_22 * V_22 ,
void (* F_37)( struct V_195 * ) )
{
F_216 ( & V_201 -> V_45 , F_37 ) ;
F_217 ( & V_201 -> F_214 ) ;
F_29 ( V_22 -> V_44 , & V_201 -> V_45 ) ;
F_218 ( & V_201 -> F_214 ) ;
}
static struct V_202 * F_219 ( struct V_195 * V_196 )
{
return F_206 ( F_212 ( V_196 ) , struct V_202 , V_201 ) ;
}
static void F_220 ( struct V_195 * V_196 )
{
struct V_202 * V_203 = F_219 ( V_196 ) ;
V_203 -> V_28 -> V_168 = true ;
F_69 ( V_203 -> V_28 ) ;
F_213 ( & V_203 -> V_201 ) ;
}
static void F_221 ( struct V_195 * V_196 )
{
struct V_202 * V_203 = F_219 ( V_196 ) ;
V_203 -> V_28 -> V_168 = false ;
F_213 ( & V_203 -> V_201 ) ;
}
static void V_202 ( struct V_27 * V_28 , void (* F_37)( struct V_195 * ) )
{
struct V_202 V_203 ;
V_203 . V_28 = V_28 ;
F_215 ( & V_203 . V_201 , V_28 -> V_22 , F_37 ) ;
}
static enum V_154 F_136 ( struct V_22 * V_22 )
{
return V_22 -> V_138 . V_204 ;
}
static void F_222 ( struct V_22 * V_22 , const char * V_205 )
{
F_144 ( V_22 -> V_151 -> V_152 ) ;
F_223 ( L_13 ,
F_143 ( V_22 -> V_67 ) , V_205 ) ;
}
static void F_211 ( struct V_22 * V_22 )
{
if ( ! V_22 -> V_138 . V_155 )
F_222 ( V_22 , L_14 ) ;
else
F_222 ( V_22 , L_15 ) ;
}
static bool F_224 ( struct V_206 * V_207 )
{
return V_207 -> V_208 . V_209 ;
}
static void F_225 ( struct V_22 * V_22 )
{
struct V_206 * V_207 = V_22 -> V_151 -> V_210 ;
if ( F_224 ( V_207 ) ) {
V_22 -> V_162 = F_156 ;
V_22 -> V_158 = F_114 ;
} else {
V_22 -> V_162 = F_152 ;
V_22 -> V_158 = F_110 ;
}
}
static void F_138 ( struct V_22 * V_22 , enum V_154 V_205 )
{
struct V_206 * V_207 = V_22 -> V_151 -> V_210 ;
bool V_211 = F_226 ( V_22 -> V_116 ) ;
enum V_154 V_212 = F_136 ( V_22 ) ;
unsigned long V_199 = F_227 ( V_213 ) * V_214 ;
if ( V_205 == V_145 && V_211 ) {
F_228 ( L_16 ,
F_143 ( V_22 -> V_67 ) ) ;
if ( V_212 != V_205 )
V_205 = V_212 ;
else
V_205 = V_146 ;
}
if ( V_212 == V_156 )
V_205 = V_212 ;
switch ( V_205 ) {
case V_156 :
if ( V_212 != V_205 )
F_222 ( V_22 , L_17 ) ;
F_229 ( V_22 -> V_116 ) ;
V_22 -> F_167 = F_172 ;
V_22 -> V_182 = F_172 ;
V_22 -> F_164 = F_174 ;
V_22 -> V_162 = F_174 ;
V_22 -> F_104 = F_102 ;
V_22 -> V_158 = F_108 ;
F_74 ( V_22 ) ;
break;
case V_146 :
if ( V_212 != V_205 )
F_222 ( V_22 , L_18 ) ;
F_229 ( V_22 -> V_116 ) ;
V_22 -> F_167 = F_169 ;
V_22 -> V_182 = F_171 ;
V_22 -> F_164 = F_170 ;
V_22 -> V_162 = F_173 ;
V_22 -> F_104 = F_102 ;
V_22 -> V_158 = F_109 ;
F_74 ( V_22 ) ;
break;
case V_144 :
if ( V_212 != V_205 )
F_211 ( V_22 ) ;
V_22 -> V_56 = true ;
V_22 -> F_167 = F_169 ;
V_22 -> V_182 = F_157 ;
V_22 -> F_164 = F_170 ;
V_22 -> F_104 = F_104 ;
F_225 ( V_22 ) ;
if ( ! V_22 -> V_138 . V_155 && V_199 )
F_209 ( V_22 -> V_44 , & V_22 -> V_199 , V_199 ) ;
break;
case V_145 :
if ( V_212 != V_205 )
F_222 ( V_22 , L_19 ) ;
V_22 -> V_56 = false ;
V_22 -> V_138 . V_155 = V_207 -> V_215 . V_155 ;
F_230 ( V_22 -> V_116 ) ;
V_22 -> F_167 = F_167 ;
V_22 -> V_182 = F_157 ;
V_22 -> F_164 = F_164 ;
V_22 -> F_104 = F_104 ;
F_225 ( V_22 ) ;
break;
}
V_22 -> V_138 . V_204 = V_205 ;
V_207 -> V_208 . V_204 = V_205 ;
}
static void F_231 ( struct V_22 * V_22 )
{
const char * V_216 = F_143 ( V_22 -> V_67 ) ;
F_125 ( L_20 , V_216 ) ;
if ( F_232 ( V_22 -> V_116 ) ) {
F_228 ( L_21 , V_216 ) ;
F_138 ( V_22 , V_156 ) ;
}
if ( F_233 ( V_22 -> V_116 ) ) {
F_228 ( L_22 , V_216 ) ;
F_138 ( V_22 , V_156 ) ;
}
}
static void F_106 ( struct V_22 * V_22 , const char * V_26 , int V_42 )
{
F_125 ( L_23 ,
F_143 ( V_22 -> V_67 ) , V_26 , V_42 ) ;
F_231 ( V_22 ) ;
F_138 ( V_22 , V_146 ) ;
}
static void F_101 ( struct V_27 * V_28 , struct V_29 * V_29 )
{
unsigned long V_71 ;
struct V_22 * V_22 = V_28 -> V_22 ;
F_64 ( & V_28 -> V_17 , V_71 ) ;
F_89 ( & V_28 -> V_75 , V_29 ) ;
F_65 ( & V_28 -> V_17 , V_71 ) ;
F_28 ( V_22 ) ;
}
static void F_234 ( struct V_27 * V_28 , struct V_29 * V_29 )
{
struct V_22 * V_22 = V_28 -> V_22 ;
F_12 ( & V_22 -> V_15 ) ;
F_101 ( V_28 , V_29 ) ;
F_14 ( & V_22 -> V_15 ) ;
}
static void F_235 ( struct V_27 * V_28 , struct V_46 * V_51 )
{
unsigned long V_71 ;
struct V_22 * V_22 = V_28 -> V_22 ;
F_12 ( & V_22 -> V_15 ) ;
F_64 ( & V_28 -> V_17 , V_71 ) ;
F_94 ( & V_51 -> V_189 , & V_28 -> V_74 ) ;
F_65 ( & V_28 -> V_17 , V_71 ) ;
F_14 ( & V_22 -> V_15 ) ;
F_28 ( V_22 ) ;
}
static void F_236 ( struct V_27 * V_28 , struct V_29 * V_29 )
{
struct V_90 * V_91 = F_83 ( V_29 , sizeof( struct V_90 ) ) ;
V_91 -> V_28 = V_28 ;
V_91 -> V_166 = NULL ;
V_91 -> V_92 = NULL ;
V_91 -> V_102 = NULL ;
V_91 -> V_51 = NULL ;
}
static int F_237 ( struct V_217 * V_151 , struct V_29 * V_29 )
{
int V_42 ;
struct V_27 * V_28 = V_151 -> V_210 ;
T_1 V_84 = F_75 ( V_28 , V_29 ) ;
struct V_1 * V_2 = V_28 -> V_2 ;
struct V_163 V_153 ;
struct V_46 * V_157 , * V_160 ;
struct V_7 V_8 ;
F_236 ( V_28 , V_29 ) ;
if ( V_28 -> V_168 ) {
V_29 -> V_43 = V_59 ;
F_27 ( V_29 ) ;
return V_218 ;
}
if ( F_136 ( V_28 -> V_22 ) == V_156 ) {
F_88 ( V_29 ) ;
return V_218 ;
}
if ( V_29 -> V_87 & ( V_41 | V_88 | V_89 ) ) {
F_234 ( V_28 , V_29 ) ;
return V_218 ;
}
F_4 ( V_28 -> V_2 , V_84 , & V_8 ) ;
if ( F_30 ( V_28 -> V_22 , & V_8 , V_29 , & V_157 ) )
return V_218 ;
V_42 = F_165 ( V_2 , V_84 , 0 , & V_153 ) ;
switch ( V_42 ) {
case 0 :
if ( F_238 ( V_153 . V_169 ) ) {
F_235 ( V_28 , V_157 ) ;
return V_218 ;
}
F_3 ( V_28 -> V_2 , V_153 . V_84 , & V_8 ) ;
if ( F_30 ( V_28 -> V_22 , & V_8 , V_29 , & V_160 ) ) {
F_98 ( V_28 , V_157 ) ;
return V_218 ;
}
F_82 ( V_28 -> V_22 , V_29 ) ;
F_98 ( V_28 , V_160 ) ;
F_98 ( V_28 , V_157 ) ;
F_78 ( V_28 , V_29 , V_153 . V_84 ) ;
return V_219 ;
case - V_170 :
case - V_220 :
F_235 ( V_28 , V_157 ) ;
return V_218 ;
default:
F_88 ( V_29 ) ;
F_98 ( V_28 , V_157 ) ;
return V_218 ;
}
}
static int F_239 ( struct V_221 * V_222 , int V_223 )
{
struct V_206 * V_207 = F_206 ( V_222 , struct V_206 , V_224 ) ;
struct V_225 * V_226 ;
if ( F_136 ( V_207 -> V_22 ) == V_144 )
return 1 ;
V_226 = F_240 ( V_207 -> V_227 -> V_38 ) ;
return F_241 ( & V_226 -> V_228 , V_223 ) ;
}
static void F_242 ( struct V_22 * V_22 )
{
unsigned long V_71 ;
struct V_27 * V_28 ;
F_71 () ;
F_72 (tc, &pool->active_thins, list) {
F_64 ( & V_28 -> V_17 , V_71 ) ;
F_59 ( & V_28 -> V_75 , & V_28 -> V_76 ) ;
F_60 ( & V_28 -> V_76 ) ;
F_65 ( & V_28 -> V_17 , V_71 ) ;
}
F_73 () ;
}
static bool F_243 ( struct V_206 * V_207 )
{
struct V_225 * V_226 = F_240 ( V_207 -> V_227 -> V_38 ) ;
return V_226 && F_244 ( V_226 ) ;
}
static bool F_245 ( T_2 V_229 , T_5 V_230 )
{
return ! F_76 ( V_229 , V_230 ) ;
}
static void F_246 ( struct V_206 * V_207 )
{
struct V_22 * V_22 = V_207 -> V_22 ;
struct V_68 * V_231 = V_207 -> V_227 -> V_38 ;
struct V_232 * V_233 = & F_240 ( V_231 ) -> V_234 ;
const char * V_235 = NULL ;
char V_236 [ V_237 ] ;
if ( ! V_207 -> V_208 . V_209 )
return;
if ( ! F_243 ( V_207 ) )
V_235 = L_24 ;
else if ( V_233 -> V_238 < V_22 -> V_24 )
V_235 = L_25 ;
if ( V_235 ) {
F_142 ( L_26 , F_247 ( V_231 , V_236 ) , V_235 ) ;
V_207 -> V_208 . V_209 = false ;
}
}
static int F_248 ( struct V_22 * V_22 , struct V_217 * V_151 )
{
struct V_206 * V_207 = V_151 -> V_210 ;
enum V_154 V_212 = F_136 ( V_22 ) ;
enum V_154 V_205 = V_207 -> V_208 . V_204 ;
V_207 -> V_208 . V_204 = V_212 ;
V_22 -> V_151 = V_151 ;
V_22 -> V_138 = V_207 -> V_208 ;
V_22 -> V_149 = V_207 -> V_149 ;
F_138 ( V_22 , V_205 ) ;
return 0 ;
}
static void F_249 ( struct V_22 * V_22 , struct V_217 * V_151 )
{
if ( V_22 -> V_151 == V_151 )
V_22 -> V_151 = NULL ;
}
static void F_250 ( struct V_239 * V_138 )
{
V_138 -> V_204 = V_145 ;
V_138 -> V_139 = true ;
V_138 -> V_240 = true ;
V_138 -> V_209 = true ;
V_138 -> V_155 = false ;
}
static void F_251 ( struct V_22 * V_22 )
{
F_53 ( V_22 ) ;
F_252 ( V_22 -> V_188 ) ;
if ( F_253 ( V_22 -> V_116 ) < 0 )
F_142 ( L_27 , V_165 ) ;
F_254 ( V_22 -> V_49 ) ;
F_255 ( V_22 -> V_129 ) ;
if ( V_22 -> V_44 )
F_256 ( V_22 -> V_44 ) ;
if ( V_22 -> V_122 )
F_103 ( V_22 -> V_122 , V_22 -> V_109 ) ;
F_257 ( V_22 -> V_109 ) ;
F_258 ( V_22 -> V_136 ) ;
F_258 ( V_22 -> V_93 ) ;
F_259 ( V_22 ) ;
}
static struct V_22 * F_260 ( struct V_64 * V_67 ,
struct V_68 * V_241 ,
unsigned long V_229 ,
int V_242 , char * * error )
{
int V_42 ;
void * V_243 ;
struct V_22 * V_22 ;
struct V_244 * V_116 ;
bool V_245 = V_242 ? false : true ;
V_116 = F_261 ( V_241 , V_229 , V_245 ) ;
if ( F_262 ( V_116 ) ) {
* error = L_28 ;
return (struct V_22 * ) V_116 ;
}
V_22 = F_263 ( sizeof( * V_22 ) , V_246 ) ;
if ( ! V_22 ) {
* error = L_29 ;
V_243 = F_264 ( - V_124 ) ;
goto V_247;
}
V_22 -> V_116 = V_116 ;
V_22 -> V_24 = V_229 ;
if ( V_229 & ( V_229 - 1 ) )
V_22 -> V_23 = - 1 ;
else
V_22 -> V_23 = F_265 ( V_229 ) ;
V_22 -> V_149 = 0 ;
F_250 ( & V_22 -> V_138 ) ;
V_22 -> V_49 = F_266 () ;
if ( ! V_22 -> V_49 ) {
* error = L_30 ;
V_243 = F_264 ( - V_124 ) ;
goto V_248;
}
V_22 -> V_129 = F_267 ( & V_249 ) ;
if ( F_262 ( V_22 -> V_129 ) ) {
V_42 = F_268 ( V_22 -> V_129 ) ;
* error = L_31 ;
V_243 = F_264 ( V_42 ) ;
goto V_250;
}
V_22 -> V_44 = F_269 ( L_32 V_251 , V_252 ) ;
if ( ! V_22 -> V_44 ) {
* error = L_33 ;
V_243 = F_264 ( - V_124 ) ;
goto V_253;
}
F_5 ( & V_22 -> V_15 ) ;
F_270 ( & V_22 -> V_45 , F_205 ) ;
F_271 ( & V_22 -> V_198 , F_207 ) ;
F_271 ( & V_22 -> V_199 , F_210 ) ;
F_272 ( & V_22 -> V_17 ) ;
F_60 ( & V_22 -> V_94 ) ;
F_49 ( & V_22 -> V_98 ) ;
F_49 ( & V_22 -> V_197 ) ;
F_49 ( & V_22 -> V_192 ) ;
V_22 -> V_150 = false ;
V_22 -> V_254 = true ;
V_22 -> V_56 = false ;
V_22 -> V_136 = F_273 () ;
if ( ! V_22 -> V_136 ) {
* error = L_34 ;
V_243 = F_264 ( - V_124 ) ;
goto V_255;
}
V_22 -> V_93 = F_273 () ;
if ( ! V_22 -> V_93 ) {
* error = L_35 ;
V_243 = F_264 ( - V_124 ) ;
goto V_256;
}
V_22 -> V_122 = NULL ;
V_22 -> V_109 = F_274 ( V_257 ,
V_258 ) ;
if ( ! V_22 -> V_109 ) {
* error = L_36 ;
V_243 = F_264 ( - V_124 ) ;
goto V_259;
}
V_22 -> V_188 = F_275 ( sizeof( * V_22 -> V_188 ) * V_187 ) ;
if ( ! V_22 -> V_188 ) {
* error = L_37 ;
V_243 = F_264 ( - V_124 ) ;
goto V_260;
}
V_22 -> V_261 = 1 ;
V_22 -> V_172 = V_20 ;
V_22 -> V_67 = V_67 ;
V_22 -> V_69 = V_241 ;
F_50 ( V_22 ) ;
return V_22 ;
V_260:
F_257 ( V_22 -> V_109 ) ;
V_259:
F_258 ( V_22 -> V_93 ) ;
V_256:
F_258 ( V_22 -> V_136 ) ;
V_255:
F_256 ( V_22 -> V_44 ) ;
V_253:
F_255 ( V_22 -> V_129 ) ;
V_250:
F_254 ( V_22 -> V_49 ) ;
V_248:
F_259 ( V_22 ) ;
V_247:
if ( F_253 ( V_116 ) )
F_142 ( L_27 , V_165 ) ;
return V_243 ;
}
static void F_276 ( struct V_22 * V_22 )
{
F_19 ( ! F_51 ( & V_60 . V_61 ) ) ;
V_22 -> V_261 ++ ;
}
static void F_277 ( struct V_22 * V_22 )
{
F_19 ( ! F_51 ( & V_60 . V_61 ) ) ;
F_19 ( ! V_22 -> V_261 ) ;
if ( ! -- V_22 -> V_261 )
F_251 ( V_22 ) ;
}
static struct V_22 * F_278 ( struct V_64 * V_67 ,
struct V_68 * V_241 ,
unsigned long V_229 , int V_242 ,
char * * error , int * V_262 )
{
struct V_22 * V_22 = F_57 ( V_241 ) ;
if ( V_22 ) {
if ( V_22 -> V_67 != V_67 ) {
* error = L_38 ;
return F_264 ( - V_263 ) ;
}
F_276 ( V_22 ) ;
} else {
V_22 = F_55 ( V_67 ) ;
if ( V_22 ) {
if ( V_22 -> V_69 != V_241 ) {
* error = L_39 ;
return F_264 ( - V_147 ) ;
}
F_276 ( V_22 ) ;
} else {
V_22 = F_260 ( V_67 , V_241 , V_229 , V_242 , error ) ;
* V_262 = 1 ;
}
}
return V_22 ;
}
static void F_279 ( struct V_217 * V_151 )
{
struct V_206 * V_207 = V_151 -> V_210 ;
F_280 ( & V_60 . V_61 ) ;
F_249 ( V_207 -> V_22 , V_151 ) ;
F_277 ( V_207 -> V_22 ) ;
F_281 ( V_151 , V_207 -> V_241 ) ;
F_281 ( V_151 , V_207 -> V_227 ) ;
F_259 ( V_207 ) ;
F_282 ( & V_60 . V_61 ) ;
}
static int F_283 ( struct V_264 * V_265 , struct V_239 * V_138 ,
struct V_217 * V_151 )
{
int V_42 ;
unsigned V_266 ;
const char * V_267 ;
static struct V_268 V_269 [] = {
{ 0 , 4 , L_40 } ,
} ;
if ( ! V_265 -> V_266 )
return 0 ;
V_42 = F_284 ( V_269 , V_265 , & V_266 , & V_151 -> error ) ;
if ( V_42 )
return - V_147 ;
while ( V_266 && ! V_42 ) {
V_267 = F_285 ( V_265 ) ;
V_266 -- ;
if ( ! strcasecmp ( V_267 , L_41 ) )
V_138 -> V_139 = false ;
else if ( ! strcasecmp ( V_267 , L_42 ) )
V_138 -> V_240 = false ;
else if ( ! strcasecmp ( V_267 , L_43 ) )
V_138 -> V_209 = false ;
else if ( ! strcasecmp ( V_267 , L_44 ) )
V_138 -> V_204 = V_146 ;
else if ( ! strcasecmp ( V_267 , L_45 ) )
V_138 -> V_155 = true ;
else {
V_151 -> error = L_46 ;
V_42 = - V_147 ;
break;
}
}
return V_42 ;
}
static void F_286 ( void * V_54 )
{
struct V_22 * V_22 = V_54 ;
F_142 ( L_47 ,
F_143 ( V_22 -> V_67 ) ) ;
F_144 ( V_22 -> V_151 -> V_152 ) ;
}
static T_2 F_287 ( struct V_68 * V_38 )
{
return F_288 ( V_38 -> V_270 ) >> V_83 ;
}
static void F_289 ( struct V_68 * V_38 )
{
T_2 V_271 = F_287 ( V_38 ) ;
char V_272 [ V_237 ] ;
if ( V_271 > V_273 )
F_142 ( L_48 ,
F_247 ( V_38 , V_272 ) , V_274 ) ;
}
static T_2 F_290 ( struct V_68 * V_38 )
{
T_2 V_271 = F_287 ( V_38 ) ;
if ( V_271 > V_274 )
V_271 = V_274 ;
return V_271 ;
}
static T_1 F_291 ( struct V_68 * V_38 )
{
T_2 V_271 = F_290 ( V_38 ) ;
F_76 ( V_271 , V_275 ) ;
return V_271 ;
}
static T_1 F_292 ( struct V_206 * V_207 )
{
T_1 V_276 = F_291 ( V_207 -> V_241 -> V_38 ) / 4 ;
return F_293 ( ( T_1 ) 1024ULL , V_276 ) ;
}
static int F_294 ( struct V_217 * V_151 , unsigned V_266 , char * * V_277 )
{
int V_42 , V_278 = 0 ;
struct V_206 * V_207 ;
struct V_22 * V_22 ;
struct V_239 V_138 ;
struct V_264 V_265 ;
struct V_132 * V_227 ;
unsigned long V_229 ;
T_1 V_149 ;
struct V_132 * V_241 ;
T_6 V_279 ;
F_280 ( & V_60 . V_61 ) ;
if ( V_266 < 4 ) {
V_151 -> error = L_49 ;
V_42 = - V_147 ;
goto V_280;
}
V_265 . V_266 = V_266 ;
V_265 . V_277 = V_277 ;
F_250 ( & V_138 ) ;
F_295 ( & V_265 , 4 ) ;
V_42 = F_283 ( & V_265 , & V_138 , V_151 ) ;
if ( V_42 )
goto V_280;
V_279 = V_281 | ( ( V_138 . V_204 == V_146 ) ? 0 : V_282 ) ;
V_42 = F_296 ( V_151 , V_277 [ 0 ] , V_279 , & V_241 ) ;
if ( V_42 ) {
V_151 -> error = L_50 ;
goto V_280;
}
F_289 ( V_241 -> V_38 ) ;
V_42 = F_296 ( V_151 , V_277 [ 1 ] , V_281 | V_282 , & V_227 ) ;
if ( V_42 ) {
V_151 -> error = L_51 ;
goto V_283;
}
if ( F_297 ( V_277 [ 2 ] , 10 , & V_229 ) || ! V_229 ||
V_229 < V_284 ||
V_229 > V_285 ||
V_229 & ( V_284 - 1 ) ) {
V_151 -> error = L_52 ;
V_42 = - V_147 ;
goto V_110;
}
if ( F_298 ( V_277 [ 3 ] , 10 , ( unsigned long long * ) & V_149 ) ) {
V_151 -> error = L_53 ;
V_42 = - V_147 ;
goto V_110;
}
V_207 = F_299 ( sizeof( * V_207 ) , V_246 ) ;
if ( ! V_207 ) {
V_42 = - V_124 ;
goto V_110;
}
V_22 = F_278 ( F_300 ( V_151 -> V_152 ) , V_241 -> V_38 ,
V_229 , V_138 . V_204 == V_146 , & V_151 -> error , & V_278 ) ;
if ( F_262 ( V_22 ) ) {
V_42 = F_268 ( V_22 ) ;
goto V_286;
}
if ( ! V_278 && V_138 . V_240 != V_22 -> V_138 . V_240 ) {
V_151 -> error = L_54 ;
V_42 = - V_147 ;
goto V_287;
}
V_207 -> V_22 = V_22 ;
V_207 -> V_151 = V_151 ;
V_207 -> V_241 = V_241 ;
V_207 -> V_227 = V_227 ;
V_207 -> V_149 = V_149 ;
V_207 -> V_208 = V_207 -> V_215 = V_138 ;
V_151 -> V_288 = 1 ;
V_151 -> V_289 = true ;
if ( V_138 . V_240 && V_138 . V_209 ) {
V_151 -> V_290 = 1 ;
V_151 -> V_291 = true ;
}
V_151 -> V_210 = V_207 ;
V_42 = F_301 ( V_207 -> V_22 -> V_116 ,
F_292 ( V_207 ) ,
F_286 ,
V_22 ) ;
if ( V_42 )
goto V_287;
V_207 -> V_224 . V_292 = F_239 ;
F_302 ( V_151 -> V_152 , & V_207 -> V_224 ) ;
F_282 ( & V_60 . V_61 ) ;
return 0 ;
V_287:
F_277 ( V_22 ) ;
V_286:
F_259 ( V_207 ) ;
V_110:
F_281 ( V_151 , V_227 ) ;
V_283:
F_281 ( V_151 , V_241 ) ;
V_280:
F_282 ( & V_60 . V_61 ) ;
return V_42 ;
}
static int F_303 ( struct V_217 * V_151 , struct V_29 * V_29 )
{
int V_42 ;
struct V_206 * V_207 = V_151 -> V_210 ;
struct V_22 * V_22 = V_207 -> V_22 ;
unsigned long V_71 ;
F_64 ( & V_22 -> V_17 , V_71 ) ;
V_29 -> V_85 = V_207 -> V_227 -> V_38 ;
V_42 = V_219 ;
F_65 ( & V_22 -> V_17 , V_71 ) ;
return V_42 ;
}
static int F_304 ( struct V_217 * V_151 , bool * V_293 )
{
int V_42 ;
struct V_206 * V_207 = V_151 -> V_210 ;
struct V_22 * V_22 = V_207 -> V_22 ;
T_2 V_294 = V_151 -> V_36 ;
T_1 V_295 ;
* V_293 = false ;
( void ) F_76 ( V_294 , V_22 -> V_24 ) ;
V_42 = F_305 ( V_22 -> V_116 , & V_295 ) ;
if ( V_42 ) {
F_228 ( L_55 ,
F_143 ( V_22 -> V_67 ) ) ;
return V_42 ;
}
if ( V_294 < V_295 ) {
F_228 ( L_56 ,
F_143 ( V_22 -> V_67 ) ,
( unsigned long long ) V_294 , V_295 ) ;
return - V_147 ;
} else if ( V_294 > V_295 ) {
if ( F_226 ( V_22 -> V_116 ) ) {
F_228 ( L_57 ,
F_143 ( V_22 -> V_67 ) ) ;
return 0 ;
}
if ( V_295 )
F_223 ( L_58 ,
F_143 ( V_22 -> V_67 ) ,
V_295 , ( unsigned long long ) V_294 ) ;
V_42 = F_306 ( V_22 -> V_116 , V_294 ) ;
if ( V_42 ) {
F_106 ( V_22 , L_59 , V_42 ) ;
return V_42 ;
}
* V_293 = true ;
}
return 0 ;
}
static int F_307 ( struct V_217 * V_151 , bool * V_293 )
{
int V_42 ;
struct V_206 * V_207 = V_151 -> V_210 ;
struct V_22 * V_22 = V_207 -> V_22 ;
T_1 V_271 , V_296 ;
* V_293 = false ;
V_271 = F_291 ( V_22 -> V_69 ) ;
V_42 = F_308 ( V_22 -> V_116 , & V_296 ) ;
if ( V_42 ) {
F_228 ( L_60 ,
F_143 ( V_22 -> V_67 ) ) ;
return V_42 ;
}
if ( V_271 < V_296 ) {
F_228 ( L_61 ,
F_143 ( V_22 -> V_67 ) ,
V_271 , V_296 ) ;
return - V_147 ;
} else if ( V_271 > V_296 ) {
if ( F_226 ( V_22 -> V_116 ) ) {
F_228 ( L_62 ,
F_143 ( V_22 -> V_67 ) ) ;
return 0 ;
}
F_289 ( V_22 -> V_69 ) ;
F_223 ( L_63 ,
F_143 ( V_22 -> V_67 ) ,
V_296 , V_271 ) ;
V_42 = F_309 ( V_22 -> V_116 , V_271 ) ;
if ( V_42 ) {
F_106 ( V_22 , L_64 , V_42 ) ;
return V_42 ;
}
* V_293 = true ;
}
return 0 ;
}
static int F_310 ( struct V_217 * V_151 )
{
int V_42 ;
bool V_297 , V_298 ;
struct V_206 * V_207 = V_151 -> V_210 ;
struct V_22 * V_22 = V_207 -> V_22 ;
V_42 = F_248 ( V_22 , V_151 ) ;
if ( V_42 )
return V_42 ;
V_42 = F_304 ( V_151 , & V_297 ) ;
if ( V_42 )
return V_42 ;
V_42 = F_307 ( V_151 , & V_298 ) ;
if ( V_42 )
return V_42 ;
if ( V_297 || V_298 )
( void ) F_139 ( V_22 ) ;
return 0 ;
}
static void F_311 ( struct V_22 * V_22 )
{
struct V_27 * V_28 ;
V_28 = F_197 ( V_22 ) ;
while ( V_28 ) {
F_312 ( V_28 -> V_299 ) ;
V_28 = F_200 ( V_22 , V_28 ) ;
}
}
static void F_313 ( struct V_22 * V_22 )
{
struct V_27 * V_28 ;
V_28 = F_197 ( V_22 ) ;
while ( V_28 ) {
F_314 ( V_28 -> V_299 ) ;
V_28 = F_200 ( V_22 , V_28 ) ;
}
}
static void F_315 ( struct V_217 * V_151 )
{
struct V_206 * V_207 = V_151 -> V_210 ;
struct V_22 * V_22 = V_207 -> V_22 ;
unsigned long V_71 ;
F_242 ( V_22 ) ;
F_313 ( V_22 ) ;
F_64 ( & V_22 -> V_17 , V_71 ) ;
V_22 -> V_150 = false ;
V_22 -> V_254 = false ;
F_65 ( & V_22 -> V_17 , V_71 ) ;
F_207 ( & V_22 -> V_198 . V_300 ) ;
}
static void F_316 ( struct V_217 * V_151 )
{
struct V_206 * V_207 = V_151 -> V_210 ;
struct V_22 * V_22 = V_207 -> V_22 ;
unsigned long V_71 ;
F_64 ( & V_22 -> V_17 , V_71 ) ;
V_22 -> V_254 = true ;
F_65 ( & V_22 -> V_17 , V_71 ) ;
F_311 ( V_22 ) ;
}
static void F_317 ( struct V_217 * V_151 )
{
struct V_206 * V_207 = V_151 -> V_210 ;
struct V_22 * V_22 = V_207 -> V_22 ;
unsigned long V_71 ;
F_313 ( V_22 ) ;
F_64 ( & V_22 -> V_17 , V_71 ) ;
V_22 -> V_254 = false ;
F_65 ( & V_22 -> V_17 , V_71 ) ;
}
static void F_318 ( struct V_217 * V_151 )
{
struct V_206 * V_207 = V_151 -> V_210 ;
struct V_22 * V_22 = V_207 -> V_22 ;
F_319 ( & V_22 -> V_198 ) ;
F_319 ( & V_22 -> V_199 ) ;
F_320 ( V_22 -> V_44 ) ;
( void ) F_139 ( V_22 ) ;
}
static int F_321 ( unsigned V_266 , unsigned V_301 )
{
if ( V_266 != V_301 ) {
F_142 ( L_65 ,
V_266 , V_301 ) ;
return - V_147 ;
}
return 0 ;
}
static int F_322 ( char * V_302 , T_7 * V_303 , int V_304 )
{
if ( ! F_298 ( V_302 , 10 , ( unsigned long long * ) V_303 ) &&
* V_303 <= V_305 )
return 0 ;
if ( V_304 )
F_142 ( L_66 , V_302 ) ;
return - V_147 ;
}
static int F_323 ( unsigned V_266 , char * * V_277 , struct V_22 * V_22 )
{
T_7 V_303 ;
int V_42 ;
V_42 = F_321 ( V_266 , 2 ) ;
if ( V_42 )
return V_42 ;
V_42 = F_322 ( V_277 [ 1 ] , & V_303 , 1 ) ;
if ( V_42 )
return V_42 ;
V_42 = F_324 ( V_22 -> V_116 , V_303 ) ;
if ( V_42 ) {
F_142 ( L_67 ,
V_277 [ 1 ] ) ;
return V_42 ;
}
return 0 ;
}
static int F_325 ( unsigned V_266 , char * * V_277 , struct V_22 * V_22 )
{
T_7 V_303 ;
T_7 V_306 ;
int V_42 ;
V_42 = F_321 ( V_266 , 3 ) ;
if ( V_42 )
return V_42 ;
V_42 = F_322 ( V_277 [ 1 ] , & V_303 , 1 ) ;
if ( V_42 )
return V_42 ;
V_42 = F_322 ( V_277 [ 2 ] , & V_306 , 1 ) ;
if ( V_42 )
return V_42 ;
V_42 = F_326 ( V_22 -> V_116 , V_303 , V_306 ) ;
if ( V_42 ) {
F_142 ( L_68 ,
V_277 [ 1 ] , V_277 [ 2 ] ) ;
return V_42 ;
}
return 0 ;
}
static int F_327 ( unsigned V_266 , char * * V_277 , struct V_22 * V_22 )
{
T_7 V_303 ;
int V_42 ;
V_42 = F_321 ( V_266 , 2 ) ;
if ( V_42 )
return V_42 ;
V_42 = F_322 ( V_277 [ 1 ] , & V_303 , 1 ) ;
if ( V_42 )
return V_42 ;
V_42 = F_328 ( V_22 -> V_116 , V_303 ) ;
if ( V_42 )
F_142 ( L_69 , V_277 [ 1 ] ) ;
return V_42 ;
}
static int F_329 ( unsigned V_266 , char * * V_277 , struct V_22 * V_22 )
{
T_7 V_307 , V_308 ;
int V_42 ;
V_42 = F_321 ( V_266 , 3 ) ;
if ( V_42 )
return V_42 ;
if ( F_298 ( V_277 [ 1 ] , 10 , ( unsigned long long * ) & V_307 ) ) {
F_142 ( L_70 , V_277 [ 1 ] ) ;
return - V_147 ;
}
if ( F_298 ( V_277 [ 2 ] , 10 , ( unsigned long long * ) & V_308 ) ) {
F_142 ( L_71 , V_277 [ 2 ] ) ;
return - V_147 ;
}
V_42 = F_330 ( V_22 -> V_116 , V_307 , V_308 ) ;
if ( V_42 ) {
F_142 ( L_72 ,
V_277 [ 1 ] , V_277 [ 2 ] ) ;
return V_42 ;
}
return 0 ;
}
static int F_331 ( unsigned V_266 , char * * V_277 , struct V_22 * V_22 )
{
int V_42 ;
V_42 = F_321 ( V_266 , 1 ) ;
if ( V_42 )
return V_42 ;
( void ) F_139 ( V_22 ) ;
V_42 = F_332 ( V_22 -> V_116 ) ;
if ( V_42 )
F_142 ( L_73 ) ;
return V_42 ;
}
static int F_333 ( unsigned V_266 , char * * V_277 , struct V_22 * V_22 )
{
int V_42 ;
V_42 = F_321 ( V_266 , 1 ) ;
if ( V_42 )
return V_42 ;
V_42 = F_334 ( V_22 -> V_116 ) ;
if ( V_42 )
F_142 ( L_74 ) ;
return V_42 ;
}
static int F_335 ( struct V_217 * V_151 , unsigned V_266 , char * * V_277 )
{
int V_42 = - V_147 ;
struct V_206 * V_207 = V_151 -> V_210 ;
struct V_22 * V_22 = V_207 -> V_22 ;
if ( F_136 ( V_22 ) >= V_146 ) {
F_228 ( L_75 ,
F_143 ( V_22 -> V_67 ) ) ;
return - V_309 ;
}
if ( ! strcasecmp ( V_277 [ 0 ] , L_76 ) )
V_42 = F_323 ( V_266 , V_277 , V_22 ) ;
else if ( ! strcasecmp ( V_277 [ 0 ] , L_77 ) )
V_42 = F_325 ( V_266 , V_277 , V_22 ) ;
else if ( ! strcasecmp ( V_277 [ 0 ] , L_78 ) )
V_42 = F_327 ( V_266 , V_277 , V_22 ) ;
else if ( ! strcasecmp ( V_277 [ 0 ] , L_79 ) )
V_42 = F_329 ( V_266 , V_277 , V_22 ) ;
else if ( ! strcasecmp ( V_277 [ 0 ] , L_80 ) )
V_42 = F_331 ( V_266 , V_277 , V_22 ) ;
else if ( ! strcasecmp ( V_277 [ 0 ] , L_81 ) )
V_42 = F_333 ( V_266 , V_277 , V_22 ) ;
else
F_142 ( L_82 , V_277 [ 0 ] ) ;
if ( ! V_42 )
( void ) F_139 ( V_22 ) ;
return V_42 ;
}
static void F_336 ( struct V_239 * V_138 , char * V_153 ,
unsigned V_310 , unsigned V_311 )
{
unsigned V_128 = ! V_138 -> V_139 + ! V_138 -> V_240 +
! V_138 -> V_209 + ( V_138 -> V_204 == V_146 ) +
V_138 -> V_155 ;
F_337 ( L_83 , V_128 ) ;
if ( ! V_138 -> V_139 )
F_337 ( L_84 ) ;
if ( ! V_138 -> V_240 )
F_337 ( L_85 ) ;
if ( ! V_138 -> V_209 )
F_337 ( L_86 ) ;
if ( V_138 -> V_204 == V_146 )
F_337 ( L_87 ) ;
if ( V_138 -> V_155 )
F_337 ( L_88 ) ;
}
static void F_338 ( struct V_217 * V_151 , T_8 type ,
unsigned V_312 , char * V_153 , unsigned V_311 )
{
int V_42 ;
unsigned V_310 = 0 ;
T_9 V_313 ;
T_1 V_314 ;
T_1 V_315 ;
T_1 V_316 ;
T_1 V_317 ;
T_1 V_318 ;
char V_236 [ V_237 ] ;
char V_319 [ V_237 ] ;
struct V_206 * V_207 = V_151 -> V_210 ;
struct V_22 * V_22 = V_207 -> V_22 ;
switch ( type ) {
case V_320 :
if ( F_136 ( V_22 ) == V_156 ) {
F_337 ( L_89 ) ;
break;
}
if ( ! ( V_312 & V_321 ) && ! F_339 ( V_151 ) )
( void ) F_139 ( V_22 ) ;
V_42 = F_340 ( V_22 -> V_116 , & V_313 ) ;
if ( V_42 ) {
F_228 ( L_90 ,
F_143 ( V_22 -> V_67 ) , V_42 ) ;
goto V_101;
}
V_42 = F_341 ( V_22 -> V_116 , & V_315 ) ;
if ( V_42 ) {
F_228 ( L_91 ,
F_143 ( V_22 -> V_67 ) , V_42 ) ;
goto V_101;
}
V_42 = F_308 ( V_22 -> V_116 , & V_317 ) ;
if ( V_42 ) {
F_228 ( L_92 ,
F_143 ( V_22 -> V_67 ) , V_42 ) ;
goto V_101;
}
V_42 = F_137 ( V_22 -> V_116 , & V_314 ) ;
if ( V_42 ) {
F_228 ( L_93 ,
F_143 ( V_22 -> V_67 ) , V_42 ) ;
goto V_101;
}
V_42 = F_305 ( V_22 -> V_116 , & V_316 ) ;
if ( V_42 ) {
F_228 ( L_94 ,
F_143 ( V_22 -> V_67 ) , V_42 ) ;
goto V_101;
}
V_42 = F_342 ( V_22 -> V_116 , & V_318 ) ;
if ( V_42 ) {
F_228 ( L_95 ,
F_143 ( V_22 -> V_67 ) , V_42 ) ;
goto V_101;
}
F_337 ( L_96 ,
( unsigned long long ) V_313 ,
( unsigned long long ) ( V_317 - V_315 ) ,
( unsigned long long ) V_317 ,
( unsigned long long ) ( V_316 - V_314 ) ,
( unsigned long long ) V_316 ) ;
if ( V_318 )
F_337 ( L_97 , V_318 ) ;
else
F_337 ( L_98 ) ;
if ( V_22 -> V_138 . V_204 == V_144 )
F_337 ( L_99 ) ;
else if ( V_22 -> V_138 . V_204 == V_146 )
F_337 ( L_100 ) ;
else
F_337 ( L_101 ) ;
if ( ! V_22 -> V_138 . V_240 )
F_337 ( L_85 ) ;
else if ( V_22 -> V_138 . V_209 )
F_337 ( L_102 ) ;
else
F_337 ( L_86 ) ;
if ( V_22 -> V_138 . V_155 )
F_337 ( L_88 ) ;
else
F_337 ( L_103 ) ;
if ( F_226 ( V_22 -> V_116 ) )
F_337 ( L_104 ) ;
else
F_337 ( L_98 ) ;
break;
case V_322 :
F_337 ( L_105 ,
F_343 ( V_236 , V_207 -> V_241 -> V_38 -> V_323 ) ,
F_343 ( V_319 , V_207 -> V_227 -> V_38 -> V_323 ) ,
( unsigned long ) V_22 -> V_24 ,
( unsigned long long ) V_207 -> V_149 ) ;
F_336 ( & V_207 -> V_215 , V_153 , V_310 , V_311 ) ;
break;
}
return;
V_101:
F_337 ( L_106 ) ;
}
static int F_344 ( struct V_217 * V_151 ,
T_10 F_37 , void * V_324 )
{
struct V_206 * V_207 = V_151 -> V_210 ;
return F_37 ( V_151 , V_207 -> V_227 , 0 , V_151 -> V_36 , V_324 ) ;
}
static void F_345 ( struct V_217 * V_151 , struct V_232 * V_234 )
{
struct V_206 * V_207 = V_151 -> V_210 ;
struct V_22 * V_22 = V_207 -> V_22 ;
T_2 V_325 = V_234 -> V_326 >> V_83 ;
if ( V_234 -> V_327 < V_22 -> V_24 ) {
while ( ! F_245 ( V_22 -> V_24 , V_234 -> V_327 ) ) {
if ( ( V_234 -> V_327 & ( V_234 -> V_327 - 1 ) ) == 0 )
V_234 -> V_327 -- ;
V_234 -> V_327 = F_346 ( V_234 -> V_327 ) ;
}
}
if ( V_325 < V_22 -> V_24 ||
! F_245 ( V_325 , V_22 -> V_24 ) ) {
if ( F_245 ( V_22 -> V_24 , V_234 -> V_327 ) )
F_347 ( V_234 , V_234 -> V_327 << V_83 ) ;
else
F_347 ( V_234 , V_22 -> V_24 << V_83 ) ;
F_348 ( V_234 , V_22 -> V_24 << V_83 ) ;
}
if ( ! V_207 -> V_208 . V_240 ) {
V_234 -> V_328 = 0 ;
return;
}
F_246 ( V_207 ) ;
}
static void F_199 ( struct V_27 * V_28 )
{
F_131 ( & V_28 -> V_329 ) ;
}
static void F_202 ( struct V_27 * V_28 )
{
if ( F_93 ( & V_28 -> V_329 ) )
F_214 ( & V_28 -> V_330 ) ;
}
static void F_349 ( struct V_217 * V_151 )
{
struct V_27 * V_28 = V_151 -> V_210 ;
unsigned long V_71 ;
F_64 ( & V_28 -> V_22 -> V_17 , V_71 ) ;
F_350 ( & V_28 -> V_63 ) ;
F_65 ( & V_28 -> V_22 -> V_17 , V_71 ) ;
F_351 () ;
F_202 ( V_28 ) ;
F_218 ( & V_28 -> V_330 ) ;
F_280 ( & V_60 . V_61 ) ;
F_277 ( V_28 -> V_22 ) ;
F_352 ( V_28 -> V_2 ) ;
F_281 ( V_151 , V_28 -> V_37 ) ;
if ( V_28 -> V_86 )
F_281 ( V_151 , V_28 -> V_86 ) ;
F_259 ( V_28 ) ;
F_282 ( & V_60 . V_61 ) ;
}
static int F_353 ( struct V_217 * V_151 , unsigned V_266 , char * * V_277 )
{
int V_42 ;
struct V_27 * V_28 ;
struct V_132 * V_37 , * V_86 ;
struct V_64 * V_67 ;
unsigned long V_71 ;
F_280 ( & V_60 . V_61 ) ;
if ( V_266 != 2 && V_266 != 3 ) {
V_151 -> error = L_49 ;
V_42 = - V_147 ;
goto V_280;
}
V_28 = V_151 -> V_210 = F_299 ( sizeof( * V_28 ) , V_246 ) ;
if ( ! V_28 ) {
V_151 -> error = L_107 ;
V_42 = - V_124 ;
goto V_280;
}
V_28 -> V_299 = F_300 ( V_151 -> V_152 ) ;
F_272 ( & V_28 -> V_17 ) ;
F_49 ( & V_28 -> V_74 ) ;
F_60 ( & V_28 -> V_75 ) ;
F_60 ( & V_28 -> V_76 ) ;
V_28 -> V_177 = V_331 ;
if ( V_266 == 3 ) {
V_42 = F_296 ( V_151 , V_277 [ 2 ] , V_281 , & V_86 ) ;
if ( V_42 ) {
V_151 -> error = L_108 ;
goto V_332;
}
V_28 -> V_86 = V_86 ;
}
V_42 = F_296 ( V_151 , V_277 [ 0 ] , F_354 ( V_151 -> V_152 ) , & V_37 ) ;
if ( V_42 ) {
V_151 -> error = L_109 ;
goto V_333;
}
V_28 -> V_37 = V_37 ;
if ( F_322 ( V_277 [ 1 ] , ( unsigned long long * ) & V_28 -> V_303 , 0 ) ) {
V_151 -> error = L_110 ;
V_42 = - V_147 ;
goto V_334;
}
V_67 = F_355 ( V_28 -> V_37 -> V_38 -> V_323 ) ;
if ( ! V_67 ) {
V_151 -> error = L_111 ;
V_42 = - V_147 ;
goto V_334;
}
V_28 -> V_22 = F_55 ( V_67 ) ;
if ( ! V_28 -> V_22 ) {
V_151 -> error = L_112 ;
V_42 = - V_147 ;
goto V_335;
}
F_276 ( V_28 -> V_22 ) ;
if ( F_136 ( V_28 -> V_22 ) == V_156 ) {
V_151 -> error = L_113 ;
V_42 = - V_147 ;
goto V_247;
}
V_42 = F_356 ( V_28 -> V_22 -> V_116 , V_28 -> V_303 , & V_28 -> V_2 ) ;
if ( V_42 ) {
V_151 -> error = L_114 ;
goto V_247;
}
V_42 = F_357 ( V_151 , V_28 -> V_22 -> V_24 ) ;
if ( V_42 )
goto V_336;
V_151 -> V_288 = 1 ;
V_151 -> V_337 = true ;
V_151 -> V_338 = sizeof( struct V_90 ) ;
V_151 -> V_289 = true ;
if ( V_28 -> V_22 -> V_138 . V_240 ) {
V_151 -> V_291 = true ;
V_151 -> V_290 = 1 ;
V_151 -> V_339 = false ;
}
F_282 ( & V_60 . V_61 ) ;
F_64 ( & V_28 -> V_22 -> V_17 , V_71 ) ;
if ( V_28 -> V_22 -> V_254 ) {
F_65 ( & V_28 -> V_22 -> V_17 , V_71 ) ;
F_280 ( & V_60 . V_61 ) ;
V_151 -> error = L_115 ;
V_42 = - V_147 ;
goto V_336;
}
F_128 ( & V_28 -> V_329 , 1 ) ;
F_217 ( & V_28 -> V_330 ) ;
F_358 ( & V_28 -> V_63 , & V_28 -> V_22 -> V_192 ) ;
F_65 ( & V_28 -> V_22 -> V_17 , V_71 ) ;
F_351 () ;
F_359 ( V_67 ) ;
return 0 ;
V_336:
F_352 ( V_28 -> V_2 ) ;
V_247:
F_277 ( V_28 -> V_22 ) ;
V_335:
F_359 ( V_67 ) ;
V_334:
F_281 ( V_151 , V_28 -> V_37 ) ;
V_333:
if ( V_28 -> V_86 )
F_281 ( V_151 , V_28 -> V_86 ) ;
V_332:
F_259 ( V_28 ) ;
V_280:
F_282 ( & V_60 . V_61 ) ;
return V_42 ;
}
static int F_360 ( struct V_217 * V_151 , struct V_29 * V_29 )
{
V_29 -> V_78 . V_79 = F_361 ( V_151 , V_29 -> V_78 . V_79 ) ;
return F_237 ( V_151 , V_29 ) ;
}
static int F_362 ( struct V_217 * V_151 , struct V_29 * V_29 , int V_101 )
{
unsigned long V_71 ;
struct V_90 * V_91 = F_83 ( V_29 , sizeof( struct V_90 ) ) ;
struct V_72 V_300 ;
struct V_95 * V_96 , * V_66 ;
struct V_22 * V_22 = V_91 -> V_28 -> V_22 ;
if ( V_91 -> V_166 ) {
F_49 ( & V_300 ) ;
F_363 ( V_91 -> V_166 , & V_300 ) ;
F_64 ( & V_22 -> V_17 , V_71 ) ;
F_68 (m, tmp, &work, list) {
F_54 ( & V_96 -> V_63 ) ;
F_92 ( V_96 ) ;
}
F_65 ( & V_22 -> V_17 , V_71 ) ;
}
if ( V_91 -> V_92 ) {
F_49 ( & V_300 ) ;
F_363 ( V_91 -> V_92 , & V_300 ) ;
if ( ! F_195 ( & V_300 ) ) {
F_64 ( & V_22 -> V_17 , V_71 ) ;
F_68 (m, tmp, &work, list)
F_94 ( & V_96 -> V_63 , & V_22 -> V_197 ) ;
F_65 ( & V_22 -> V_17 , V_71 ) ;
F_28 ( V_22 ) ;
}
}
if ( V_91 -> V_51 )
F_98 ( V_91 -> V_28 , V_91 -> V_51 ) ;
return 0 ;
}
static void F_364 ( struct V_217 * V_151 )
{
struct V_27 * V_28 = V_151 -> V_210 ;
if ( F_365 ( V_151 ) )
V_202 ( V_28 , F_220 ) ;
}
static void F_366 ( struct V_217 * V_151 )
{
struct V_27 * V_28 = V_151 -> V_210 ;
V_202 ( V_28 , F_221 ) ;
}
static int F_367 ( struct V_217 * V_151 )
{
struct V_27 * V_28 = V_151 -> V_210 ;
if ( V_28 -> V_86 )
V_28 -> V_142 = F_287 ( V_28 -> V_86 -> V_38 ) ;
return 0 ;
}
static void F_368 ( struct V_217 * V_151 , T_8 type ,
unsigned V_312 , char * V_153 , unsigned V_311 )
{
int V_42 ;
T_11 V_310 = 0 ;
T_1 V_340 , V_341 ;
char V_236 [ V_237 ] ;
struct V_27 * V_28 = V_151 -> V_210 ;
if ( F_136 ( V_28 -> V_22 ) == V_156 ) {
F_337 ( L_89 ) ;
return;
}
if ( ! V_28 -> V_2 )
F_337 ( L_116 ) ;
else {
switch ( type ) {
case V_320 :
V_42 = F_369 ( V_28 -> V_2 , & V_340 ) ;
if ( V_42 ) {
F_228 ( L_117 , V_42 ) ;
goto V_101;
}
V_42 = F_370 ( V_28 -> V_2 , & V_341 ) ;
if ( V_42 < 0 ) {
F_228 ( L_118 , V_42 ) ;
goto V_101;
}
F_337 ( L_97 , V_340 * V_28 -> V_22 -> V_24 ) ;
if ( V_42 )
F_337 ( L_119 , ( ( V_341 + 1 ) *
V_28 -> V_22 -> V_24 ) - 1 ) ;
else
F_337 ( L_116 ) ;
break;
case V_322 :
F_337 ( L_120 ,
F_343 ( V_236 , V_28 -> V_37 -> V_38 -> V_323 ) ,
( unsigned long ) V_28 -> V_303 ) ;
if ( V_28 -> V_86 )
F_337 ( L_121 , F_343 ( V_236 , V_28 -> V_86 -> V_38 -> V_323 ) ) ;
break;
}
}
return;
V_101:
F_337 ( L_106 ) ;
}
static int F_371 ( struct V_217 * V_151 ,
T_10 F_37 , void * V_324 )
{
T_2 V_342 ;
struct V_27 * V_28 = V_151 -> V_210 ;
struct V_22 * V_22 = V_28 -> V_22 ;
if ( ! V_22 -> V_151 )
return 0 ;
V_342 = V_22 -> V_151 -> V_36 ;
( void ) F_76 ( V_342 , V_22 -> V_24 ) ;
if ( V_342 )
return F_37 ( V_151 , V_28 -> V_37 , 0 , V_22 -> V_24 * V_342 , V_324 ) ;
return 0 ;
}
static void F_372 ( struct V_217 * V_151 , struct V_232 * V_234 )
{
struct V_27 * V_28 = V_151 -> V_210 ;
struct V_22 * V_22 = V_28 -> V_22 ;
if ( ! V_22 -> V_138 . V_240 )
return;
V_234 -> V_328 = V_22 -> V_24 << V_83 ;
V_234 -> V_238 = 2048 * 1024 * 16 ;
}
static int T_12 F_373 ( void )
{
int V_42 ;
F_47 () ;
V_42 = F_374 ( & V_343 ) ;
if ( V_42 )
return V_42 ;
V_42 = F_374 ( & V_344 ) ;
if ( V_42 )
goto V_345;
V_42 = - V_124 ;
V_258 = F_375 ( V_95 , 0 ) ;
if ( ! V_258 )
goto V_346;
return 0 ;
V_346:
F_376 ( & V_344 ) ;
V_345:
F_376 ( & V_343 ) ;
return V_42 ;
}
static void F_377 ( void )
{
F_376 ( & V_343 ) ;
F_376 ( & V_344 ) ;
F_378 ( V_258 ) ;
}
