static inline bool F_1 ( T_1 V_1 )
{
if ( ! V_1 || V_1 == V_2 )
return false ;
return true ;
}
static T_2 F_2 ( T_1 V_1 )
{
T_2 V_3 ;
F_3 ( V_4 , V_5 , V_1 ) ;
F_4 ( V_6 , V_3 ) ;
return V_3 ;
}
static inline struct V_7 * F_5 ( T_1 V_1 )
{
struct V_7 * V_8 ;
V_8 = V_9 [ V_1 ] ;
F_6 ( V_8 -> V_1 != V_1 ) ;
return V_8 ;
}
static T_1 F_7 ( void )
{
struct V_7 * V_8 ;
F_8 ( & V_10 ) ;
if ( F_9 ( & V_11 ) )
return V_2 ;
V_8 = F_10 ( & V_11 , struct V_7 , V_12 ) ;
F_11 ( & V_8 -> V_12 ) ;
return V_8 -> V_1 ;
}
static void F_12 ( T_1 V_1 )
{
struct V_7 * V_8 ;
F_8 ( & V_10 ) ;
F_6 ( ! F_1 ( V_1 ) ) ;
V_8 = F_5 ( V_1 ) ;
V_8 -> V_13 = V_14 ;
V_8 -> V_15 = V_16 ;
F_13 ( & V_8 -> V_12 , & V_17 ) ;
}
static void F_14 ( void )
{
int V_18 ;
if ( ! V_9 )
return;
for ( V_18 = 0 ; V_18 < V_19 ; V_18 ++ )
F_15 ( V_9 [ V_18 ] ) ;
F_15 ( V_9 ) ;
V_9 = NULL ;
V_20 = false ;
}
static int F_16 ( void )
{
struct V_7 * V_8 ;
unsigned int V_21 ;
int V_22 = 0 ;
V_21 = V_19 + 1 ;
V_9 = F_17 ( sizeof( struct V_7 * ) *
V_21 , V_23 ) ;
if ( ! V_9 )
return - V_24 ;
for (; V_22 <= V_19 ; V_22 ++ ) {
struct V_7 * V_8 ;
V_8 = F_18 ( sizeof( * V_8 ) , V_23 ) ;
if ( ! V_8 )
goto V_25;
F_19 ( & V_8 -> V_12 ) ;
V_8 -> V_1 = V_22 ;
V_9 [ V_22 ] = V_8 ;
F_13 ( & V_8 -> V_12 , & V_11 ) ;
}
V_8 = F_5 ( 0 ) ;
F_11 ( & V_8 -> V_12 ) ;
F_20 ( & V_10 ) ;
V_26 = F_7 () ;
F_21 ( & V_10 ) ;
return 0 ;
V_25:
F_14 () ;
return - V_24 ;
}
static bool F_22 ( struct V_27 * V_28 , struct V_27 * V_29 )
{
if ( ( V_28 -> V_30 & V_31 ) !=
( V_29 -> V_30 & V_31 ) )
return false ;
#ifdef F_23
if ( V_28 -> V_32 != V_29 -> V_32 )
return false ;
#endif
if ( ! ( V_29 -> V_30 & V_31 ) )
return true ;
if ( V_28 -> V_33 . V_34 == V_29 -> V_33 . V_34 ) {
V_29 -> V_33 . V_35 = true ;
return true ;
}
if ( V_29 -> V_36 == V_28 )
return true ;
return false ;
}
static inline struct V_37 * F_24 ( struct V_27 * V_38 )
{
if ( V_38 -> V_30 & V_31 )
return F_25 ( V_38 -> V_33 . V_34 , V_38 -> V_39 ) ;
return V_38 -> V_32 ;
}
static bool F_26 ( struct V_27 * V_28 , struct V_27 * V_29 )
{
#ifdef F_23
if ( V_28 -> V_32 && V_29 -> V_32 ) {
struct V_37 * V_40 = V_28 -> V_32 ;
struct V_37 * V_41 = V_29 -> V_32 ;
F_27 ( V_40 == V_41 ) ;
if ( F_28 ( V_40 -> V_42 . V_43 , V_41 -> V_42 . V_43 ) ||
F_28 ( V_41 -> V_42 . V_43 , V_40 -> V_42 . V_43 ) )
return true ;
return false ;
}
if ( V_28 -> V_32 || V_29 -> V_32 ) {
struct V_37 * V_40 , * V_41 ;
if ( ( V_28 -> V_32 && ! ( V_29 -> V_30 & V_31 ) ) ||
( V_29 -> V_32 && ! ( V_28 -> V_30 & V_31 ) ) )
return true ;
V_40 = F_24 ( V_28 ) ;
V_41 = F_24 ( V_29 ) ;
if ( V_40 == V_41 )
return true ;
if ( ! V_40 || ! V_41 )
return false ;
if ( F_28 ( V_40 -> V_42 . V_43 , V_41 -> V_42 . V_43 ) ||
F_28 ( V_41 -> V_42 . V_43 , V_40 -> V_42 . V_43 ) )
return true ;
return false ;
}
#endif
if ( ! ( V_28 -> V_30 & V_31 ) ||
! ( V_29 -> V_30 & V_31 ) )
return true ;
return false ;
}
static bool F_29 ( int V_44 )
{
return ( V_44 >= V_45 && V_44 <= V_46 ) ;
}
static void F_30 ( struct V_47 * V_48 )
{
if ( F_29 ( V_48 -> V_49 ) )
F_31 ( & V_50 , V_51 , V_48 , 1 ) ;
else
F_31 ( & V_50 , V_52 , V_48 , 1 ) ;
}
static T_1 F_32 ( struct V_27 * V_53 , T_1 V_1 )
{
struct V_27 * V_38 ;
struct V_54 * V_55 = & V_53 -> V_33 . V_56 ;
T_1 V_57 = V_53 -> V_33 . V_58 ;
F_8 ( & V_10 ) ;
if ( F_1 ( V_57 ) && ! F_1 ( V_1 ) ) {
struct V_47 V_48 = {
. V_1 = V_57 ,
. V_49 = V_53 -> V_59 . V_60 ,
. V_61 = F_33 ( 0 ) ,
} ;
F_30 ( & V_48 ) ;
F_34 ( & V_53 -> V_62 , F_35 ( & V_48 . V_61 ) ) ;
}
F_36 ( & V_63 ) ;
V_53 -> V_33 . V_58 = V_1 ;
F_37 (event, head, hw.cqm_group_entry)
V_38 -> V_33 . V_58 = V_1 ;
F_38 ( & V_63 ) ;
if ( F_1 ( V_1 ) ) {
V_38 = V_53 ;
if ( F_29 ( V_38 -> V_59 . V_60 ) )
F_39 ( V_1 , V_38 -> V_59 . V_60 ) ;
F_37 (event, head, hw.cqm_group_entry) {
if ( F_29 ( V_38 -> V_59 . V_60 ) )
F_39 ( V_1 , V_38 -> V_59 . V_60 ) ;
}
}
return V_57 ;
}
static void F_40 ( void * V_64 )
{
struct V_7 * V_8 ;
F_37 (entry, &cqm_rmid_limbo_lru, list) {
if ( V_8 -> V_15 != V_65 )
break;
if ( F_2 ( V_8 -> V_1 ) > V_66 )
V_8 -> V_15 = V_67 ;
}
}
static bool F_41 ( T_1 V_1 )
{
struct V_27 * V_68 , * V_38 ;
F_8 ( & V_10 ) ;
V_68 = F_10 ( & V_69 , struct V_27 ,
V_33 . V_70 ) ;
V_38 = V_68 ;
F_42 (event, &cache_groups,
hw.cqm_groups_entry) {
if ( F_1 ( V_38 -> V_33 . V_58 ) )
continue;
if ( F_26 ( V_38 , V_68 ) )
continue;
F_32 ( V_38 , V_1 ) ;
return true ;
}
return false ;
}
static bool F_43 ( unsigned int * V_71 )
{
struct V_7 * V_8 , * V_72 ;
F_8 ( & V_10 ) ;
* V_71 = 0 ;
F_37 (entry, &cqm_rmid_limbo_lru, list) {
unsigned long V_73 ;
unsigned long V_74 = V_14 ;
V_73 = V_8 -> V_13 +
F_44 ( V_75 ) ;
if ( F_45 ( V_73 , V_74 ) )
break;
V_8 -> V_15 = V_65 ;
( * V_71 ) ++ ;
}
if ( ! * V_71 )
return false ;
F_31 ( & V_50 , F_40 , NULL , true ) ;
F_46 (entry, tmp, &cqm_rmid_limbo_lru, list) {
if ( V_8 -> V_15 == V_16 )
break;
if ( V_8 -> V_15 == V_67 )
continue;
F_11 ( & V_8 -> V_12 ) ;
if ( ! F_1 ( V_26 ) ) {
V_26 = V_8 -> V_1 ;
continue;
}
if ( F_41 ( V_8 -> V_1 ) )
continue;
F_13 ( & V_8 -> V_12 , & V_11 ) ;
}
return F_1 ( V_26 ) ;
}
static void F_47 ( struct V_27 * V_76 )
{
struct V_27 * V_77 ;
T_1 V_1 ;
F_8 ( & V_10 ) ;
V_77 = F_10 ( & V_69 , struct V_27 ,
V_33 . V_70 ) ;
if ( V_76 == V_77 )
return;
V_1 = F_32 ( V_77 , V_2 ) ;
F_12 ( V_1 ) ;
F_48 ( & V_69 ) ;
}
static void F_49 ( struct V_27 * V_38 )
{
struct V_27 * V_53 , * V_78 ;
T_1 V_1 ;
F_8 ( & V_10 ) ;
F_46 (group, g, &cache_groups, hw.cqm_groups_entry) {
if ( V_53 == V_38 )
continue;
V_1 = V_53 -> V_33 . V_58 ;
if ( ! F_1 ( V_1 ) )
continue;
if ( ! F_26 ( V_53 , V_38 ) )
continue;
F_32 ( V_53 , V_2 ) ;
F_12 ( V_1 ) ;
}
}
static bool F_50 ( void )
{
struct V_27 * V_53 , * V_79 = NULL ;
unsigned int V_80 ;
unsigned int V_81 = 0 ;
unsigned int V_82 ;
bool V_83 = false ;
F_20 ( & V_10 ) ;
V_84:
if ( F_9 ( & V_69 ) && F_9 ( & V_17 ) )
goto V_85;
F_37 (group, &cache_groups, hw.cqm_groups_entry) {
if ( ! F_1 ( V_53 -> V_33 . V_58 ) ) {
if ( ! V_79 )
V_79 = V_53 ;
V_81 ++ ;
}
}
if ( ! V_81 && F_9 ( & V_17 ) )
goto V_85;
if ( ! V_81 )
goto V_86;
F_47 ( V_79 ) ;
if ( F_1 ( V_26 ) ) {
F_32 ( V_79 , V_26 ) ;
V_26 = F_7 () ;
F_49 ( V_79 ) ;
if ( V_66 )
V_66 -- ;
}
V_83 = true ;
V_86:
V_80 = V_87 / V_88 ;
while ( F_43 ( & V_82 ) &&
V_66 < V_80 ) {
unsigned int V_89 ;
if ( ! V_81 )
break;
V_89 = ( V_19 + 1 ) / 4 ;
if ( V_82 < V_89 )
goto V_84;
V_66 ++ ;
}
V_85:
F_21 ( & V_10 ) ;
return V_83 ;
}
static void F_51 ( struct V_90 * V_91 )
{
unsigned long V_92 ;
F_50 () ;
V_92 = F_44 ( V_93 . V_94 ) ;
F_52 ( & V_95 , V_92 ) ;
}
static T_2 F_53 ( unsigned int V_1 , T_1 V_49 , int V_96 )
{
struct V_97 * V_98 ;
T_1 V_99 = F_54 ( V_1 ) ;
T_2 V_3 , V_100 , V_101 ;
T_1 V_102 ;
if ( V_49 == V_46 ) {
V_98 = & V_103 [ V_99 ] ;
V_102 = V_46 ;
} else {
V_98 = & V_104 [ V_99 ] ;
V_102 = V_45 ;
}
F_3 ( V_4 , V_102 , V_1 ) ;
F_4 ( V_6 , V_3 ) ;
if ( V_3 & ( V_105 | V_106 ) )
return V_98 -> V_107 ;
if ( V_96 ) {
V_98 -> V_108 = V_3 ;
V_98 -> V_107 = 0 ;
return V_98 -> V_107 ;
}
V_101 = 64 - V_109 ;
V_100 = ( V_3 << V_101 ) - ( V_98 -> V_108 << V_101 ) ;
V_100 >>= V_101 ;
V_100 *= V_88 ;
V_98 -> V_107 += V_100 ;
V_98 -> V_108 = V_3 ;
return V_98 -> V_107 ;
}
static T_2 F_55 ( unsigned int V_1 , T_1 V_49 )
{
return F_53 ( V_1 , V_49 , 0 ) ;
}
static void F_56 ( void * V_110 )
{
struct V_47 * V_48 = V_110 ;
F_53 ( V_48 -> V_1 , V_48 -> V_49 , 1 ) ;
}
static void F_39 ( T_1 V_1 , T_1 V_49 )
{
struct V_47 V_48 = {
. V_1 = V_1 ,
. V_49 = V_49 ,
. V_61 = F_33 ( 0 ) ,
} ;
F_31 ( & V_50 , F_56 , & V_48 , 1 ) ;
}
static void F_57 ( struct V_27 * V_38 ,
struct V_27 * * V_53 )
{
struct V_27 * V_111 ;
bool V_112 = false ;
T_1 V_1 ;
V_38 -> V_33 . V_35 = false ;
F_37 (iter, &cache_groups, hw.cqm_groups_entry) {
V_1 = V_111 -> V_33 . V_58 ;
if ( F_22 ( V_111 , V_38 ) ) {
V_38 -> V_33 . V_58 = V_1 ;
* V_53 = V_111 ;
if ( F_29 ( V_38 -> V_59 . V_60 ) && F_1 ( V_1 ) )
F_39 ( V_1 , V_38 -> V_59 . V_60 ) ;
return;
}
if ( F_26 ( V_111 , V_38 ) && F_1 ( V_1 ) )
V_112 = true ;
}
if ( V_112 )
V_1 = V_2 ;
else
V_1 = F_7 () ;
if ( F_29 ( V_38 -> V_59 . V_60 ) && F_1 ( V_1 ) )
F_39 ( V_1 , V_38 -> V_59 . V_60 ) ;
V_38 -> V_33 . V_58 = V_1 ;
}
static void F_58 ( struct V_27 * V_38 )
{
unsigned long V_113 ;
T_1 V_1 ;
T_2 V_3 ;
if ( V_38 -> V_114 == - 1 )
return;
F_59 ( & V_63 , V_113 ) ;
V_1 = V_38 -> V_33 . V_58 ;
if ( ! F_1 ( V_1 ) )
goto V_85;
if ( F_29 ( V_38 -> V_59 . V_60 ) )
V_3 = F_55 ( V_1 , V_38 -> V_59 . V_60 ) ;
else
V_3 = F_2 ( V_1 ) ;
if ( V_3 & ( V_105 | V_106 ) )
goto V_85;
F_34 ( & V_38 -> V_62 , V_3 ) ;
V_85:
F_60 ( & V_63 , V_113 ) ;
}
static void V_52 ( void * V_110 )
{
struct V_47 * V_48 = V_110 ;
T_2 V_3 ;
V_3 = F_2 ( V_48 -> V_1 ) ;
if ( V_3 & ( V_105 | V_106 ) )
return;
F_61 ( V_3 , & V_48 -> V_61 ) ;
}
static inline bool F_62 ( struct V_27 * V_38 )
{
return ! F_9 ( & V_38 -> V_33 . V_70 ) ;
}
static void V_51 ( void * V_110 )
{
struct V_47 * V_48 = V_110 ;
T_2 V_3 ;
V_3 = F_55 ( V_48 -> V_1 , V_48 -> V_49 ) ;
if ( V_3 & ( V_105 | V_106 ) )
return;
F_61 ( V_3 , & V_48 -> V_61 ) ;
}
static enum V_115 F_63 ( struct V_116 * V_116 )
{
struct V_27 * V_111 , * V_117 ;
int V_118 = V_119 ;
struct V_54 * V_55 ;
unsigned long V_113 ;
T_1 V_120 ;
F_59 ( & V_63 , V_113 ) ;
if ( F_9 ( & V_69 ) ) {
V_118 = V_121 ;
goto V_85;
}
F_37 (iter, &cache_groups, hw.cqm_groups_entry) {
V_120 = V_111 -> V_33 . V_58 ;
if ( ! F_1 ( V_120 ) )
continue;
if ( F_29 ( V_111 -> V_59 . V_60 ) )
F_53 ( V_120 , V_111 -> V_59 . V_60 , 0 ) ;
V_55 = & V_111 -> V_33 . V_56 ;
if ( F_9 ( V_55 ) )
continue;
F_37 (iter1, head, hw.cqm_group_entry) {
if ( ! V_117 -> V_33 . V_35 )
break;
if ( F_29 ( V_117 -> V_59 . V_60 ) )
F_53 ( V_117 -> V_33 . V_58 ,
V_117 -> V_59 . V_60 , 0 ) ;
}
}
F_64 ( V_116 , F_65 ( V_122 ) ) ;
V_85:
F_60 ( & V_63 , V_113 ) ;
return V_118 ;
}
static void F_66 ( void * V_110 )
{
F_67 ( & V_123 [ V_124 ] , F_65 ( V_122 ) ,
V_125 ) ;
}
static void F_68 ( void * V_110 )
{
F_69 ( & V_123 [ V_124 ] ) ;
}
static void F_70 ( void )
{
F_31 ( & V_50 , F_66 , NULL , 1 ) ;
}
static void F_71 ( void )
{
F_31 ( & V_50 , F_68 , NULL , 1 ) ;
}
static void F_72 ( void )
{
struct V_116 * V_126 ;
int V_18 ;
for ( V_18 = 0 ; V_18 < V_127 ; V_18 ++ ) {
V_126 = & V_123 [ V_18 ] ;
F_73 ( V_126 , V_128 , V_129 ) ;
V_126 -> V_130 = F_63 ;
}
}
static T_2 F_74 ( struct V_27 * V_38 )
{
unsigned long V_113 ;
struct V_47 V_48 = {
. V_49 = V_38 -> V_59 . V_60 ,
. V_61 = F_33 ( 0 ) ,
} ;
if ( V_38 -> V_114 != - 1 )
return F_75 ( V_38 ) ;
if ( ! F_62 ( V_38 ) && ! V_38 -> V_33 . V_35 )
return 0 ;
if ( F_76 ( F_77 () ) )
goto V_85;
V_48 . V_1 = F_78 ( V_38 -> V_33 . V_58 ) ;
if ( ! F_1 ( V_48 . V_1 ) )
goto V_85;
F_30 ( & V_48 ) ;
F_59 ( & V_63 , V_113 ) ;
if ( V_38 -> V_33 . V_58 == V_48 . V_1 )
F_34 ( & V_38 -> V_62 , F_35 ( & V_48 . V_61 ) ) ;
F_60 ( & V_63 , V_113 ) ;
V_85:
return F_75 ( V_38 ) ;
}
static void F_79 ( struct V_27 * V_38 , int V_131 )
{
struct V_132 * V_15 = F_80 ( & V_133 ) ;
T_1 V_1 = V_38 -> V_33 . V_58 ;
if ( ! ( V_38 -> V_33 . V_134 & V_135 ) )
return;
V_38 -> V_33 . V_134 &= ~ V_135 ;
if ( V_15 -> V_136 ++ ) {
if ( ! F_27 ( V_15 -> V_1 != V_1 ) )
return;
} else {
F_27 ( V_15 -> V_1 ) ;
}
V_15 -> V_1 = V_1 ;
F_3 ( V_137 , V_1 , V_15 -> V_138 ) ;
}
static void F_81 ( struct V_27 * V_38 , int V_131 )
{
struct V_132 * V_15 = F_80 ( & V_133 ) ;
if ( V_38 -> V_33 . V_134 & V_135 )
return;
V_38 -> V_33 . V_134 |= V_135 ;
F_58 ( V_38 ) ;
if ( ! -- V_15 -> V_136 ) {
V_15 -> V_1 = 0 ;
F_3 ( V_137 , 0 , V_15 -> V_138 ) ;
} else {
F_27 ( ! V_15 -> V_1 ) ;
}
}
static int F_82 ( struct V_27 * V_38 , int V_131 )
{
unsigned long V_113 ;
T_1 V_1 ;
F_59 ( & V_63 , V_113 ) ;
V_38 -> V_33 . V_134 = V_135 ;
V_1 = V_38 -> V_33 . V_58 ;
if ( F_1 ( V_1 ) && ( V_131 & V_139 ) )
F_79 ( V_38 , V_131 ) ;
F_60 ( & V_63 , V_113 ) ;
return 0 ;
}
static void F_83 ( struct V_27 * V_38 )
{
struct V_27 * V_140 = NULL ;
unsigned long V_113 ;
F_20 ( & V_10 ) ;
F_59 ( & V_63 , V_113 ) ;
if ( ! F_9 ( & V_38 -> V_33 . V_56 ) ) {
V_140 = F_10 ( & V_38 -> V_33 . V_56 ,
struct V_27 ,
V_33 . V_56 ) ;
F_11 ( & V_38 -> V_33 . V_56 ) ;
}
if ( F_62 ( V_38 ) ) {
if ( V_140 ) {
F_84 ( & V_38 -> V_33 . V_70 ,
& V_140 -> V_33 . V_70 ) ;
} else {
T_1 V_1 = V_38 -> V_33 . V_58 ;
if ( F_1 ( V_1 ) )
F_12 ( V_1 ) ;
F_11 ( & V_38 -> V_33 . V_70 ) ;
}
}
F_60 ( & V_63 , V_113 ) ;
if ( V_141 && F_9 ( & V_69 ) )
F_71 () ;
F_21 ( & V_10 ) ;
}
static int F_85 ( struct V_27 * V_38 )
{
struct V_27 * V_53 = NULL ;
bool V_142 = false ;
unsigned long V_113 ;
if ( V_38 -> V_59 . type != V_93 . type )
return - V_143 ;
if ( ( V_38 -> V_59 . V_60 < V_5 ) ||
( V_38 -> V_59 . V_60 > V_46 ) )
return - V_144 ;
if ( V_38 -> V_59 . V_145 ||
V_38 -> V_59 . V_146 ||
V_38 -> V_59 . V_147 ||
V_38 -> V_59 . V_148 ||
V_38 -> V_59 . V_149 ||
V_38 -> V_59 . V_150 ||
V_38 -> V_59 . V_151 )
return - V_144 ;
F_19 ( & V_38 -> V_33 . V_56 ) ;
F_19 ( & V_38 -> V_33 . V_70 ) ;
V_38 -> V_152 = F_83 ;
F_20 ( & V_10 ) ;
if ( V_141 && F_9 ( & V_69 ) )
F_70 () ;
F_57 ( V_38 , & V_53 ) ;
F_59 ( & V_63 , V_113 ) ;
if ( V_53 ) {
F_13 ( & V_38 -> V_33 . V_56 ,
& V_53 -> V_33 . V_56 ) ;
} else {
F_13 ( & V_38 -> V_33 . V_70 ,
& V_69 ) ;
if ( ! F_1 ( V_38 -> V_33 . V_58 ) )
V_142 = true ;
}
F_60 ( & V_63 , V_113 ) ;
F_21 ( & V_10 ) ;
if ( V_142 )
F_52 ( & V_95 , 0 ) ;
return 0 ;
}
static T_3
F_86 ( struct V_153 * V_154 , struct V_155 * V_59 ,
char * V_156 )
{
T_3 V_157 ;
F_20 ( & V_10 ) ;
V_157 = snprintf ( V_156 , V_158 - 1 , L_1 , V_87 ) ;
F_21 ( & V_10 ) ;
return V_157 ;
}
static T_3
F_87 ( struct V_153 * V_154 ,
struct V_155 * V_59 ,
const char * V_159 , T_4 V_62 )
{
unsigned int V_100 , V_160 ;
int V_118 ;
V_118 = F_88 ( V_159 , 0 , & V_100 ) ;
if ( V_118 )
return V_118 ;
F_20 ( & V_10 ) ;
V_87 = V_100 ;
V_160 = V_100 / V_88 ;
if ( V_66 > V_160 )
V_66 = V_160 ;
F_21 ( & V_10 ) ;
return V_62 ;
}
static inline void F_89 ( int V_114 )
{
int V_161 ;
V_161 = F_90 ( & V_50 , F_91 ( V_114 ) ) ;
if ( V_161 >= V_162 )
F_92 ( V_114 , & V_50 ) ;
}
static void F_93 ( unsigned int V_114 )
{
struct V_132 * V_15 = & F_94 ( V_133 , V_114 ) ;
struct V_163 * V_164 = & F_95 ( V_114 ) ;
V_15 -> V_1 = 0 ;
V_15 -> V_138 = 0 ;
V_15 -> V_136 = 0 ;
F_6 ( V_164 -> V_165 != V_19 ) ;
F_6 ( V_164 -> V_166 != V_88 ) ;
}
static void F_96 ( unsigned int V_114 )
{
int V_34 ;
if ( ! F_97 ( V_114 , & V_50 ) )
return;
V_34 = F_98 ( F_91 ( V_114 ) , V_114 ) ;
if ( V_34 < V_162 )
F_92 ( V_34 , & V_50 ) ;
}
static int F_99 ( struct V_167 * V_168 ,
unsigned long V_169 , void * V_170 )
{
unsigned int V_114 = ( unsigned long ) V_170 ;
switch ( V_169 & ~ V_171 ) {
case V_172 :
F_96 ( V_114 ) ;
break;
case V_173 :
F_93 ( V_114 ) ;
F_89 ( V_114 ) ;
break;
}
return V_174 ;
}
static void F_100 ( void )
{
if ( ! V_141 )
return;
F_15 ( V_103 ) ;
F_15 ( V_104 ) ;
V_141 = false ;
}
static int F_101 ( void )
{
int V_118 = 0 , V_175 , V_176 = V_19 + 1 ;
V_127 = F_102 () ;
V_175 = sizeof( struct V_97 ) * V_176 * V_127 ;
V_103 = F_18 ( V_175 , V_23 ) ;
if ( ! V_103 )
return - V_24 ;
V_104 = F_18 ( V_175 , V_23 ) ;
if ( ! V_104 ) {
V_118 = - V_24 ;
goto V_85;
}
V_175 = sizeof( struct V_116 ) * V_127 ;
V_123 = F_18 ( V_175 , V_23 ) ;
if ( ! V_123 ) {
V_118 = - V_24 ;
goto V_85;
}
F_72 () ;
V_85:
if ( V_118 )
F_100 () ;
return V_118 ;
}
static int T_5 F_103 ( void )
{
char * V_177 = NULL , V_178 [ 20 ] ;
int V_18 , V_114 , V_118 ;
if ( F_104 ( V_179 ) )
V_20 = true ;
if ( F_104 ( V_180 ) &&
F_104 ( V_181 ) )
V_141 = true ;
if ( ! V_20 && ! V_141 )
return - V_182 ;
V_88 = V_183 . V_166 ;
F_105 () ;
F_106 (cpu) {
struct V_163 * V_164 = & F_95 ( V_114 ) ;
if ( V_164 -> V_165 < V_19 )
V_19 = V_164 -> V_165 ;
if ( V_164 -> V_166 != V_88 ) {
F_107 ( L_2 ) ;
V_118 = - V_144 ;
goto V_85;
}
}
V_87 =
V_183 . V_184 * 1024 / ( V_19 + 1 ) ;
snprintf ( V_178 , sizeof( V_178 ) , L_3 , V_88 ) ;
V_177 = F_108 ( V_178 , V_23 ) ;
if ( ! V_177 ) {
V_118 = - V_24 ;
goto V_85;
}
V_185 . V_186 = V_177 ;
V_118 = F_16 () ;
if ( V_118 )
goto V_85;
F_106 (i) {
F_93 ( V_18 ) ;
F_89 ( V_18 ) ;
}
if ( V_141 )
V_118 = F_101 () ;
if ( V_118 && ! V_20 )
goto V_85;
if ( V_20 && V_141 )
V_187 . V_188 = V_189 ;
else if ( ! V_20 && V_141 )
V_187 . V_188 = V_190 ;
else if ( V_20 && ! V_141 )
V_187 . V_188 = V_191 ;
V_118 = F_109 ( & V_93 , L_4 , - 1 ) ;
if ( V_118 ) {
F_107 ( L_5 , V_118 ) ;
goto V_85;
}
if ( V_20 )
F_110 ( L_6 ) ;
if ( V_141 )
F_110 ( L_7 ) ;
F_111 ( F_99 ) ;
V_85:
F_112 () ;
if ( V_118 ) {
F_15 ( V_177 ) ;
F_14 () ;
F_100 () ;
}
return V_118 ;
}
