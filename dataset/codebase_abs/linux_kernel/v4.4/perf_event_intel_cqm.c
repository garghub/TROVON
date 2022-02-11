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
static int F_14 ( void )
{
struct V_7 * V_8 ;
unsigned int V_18 ;
int V_19 = 0 ;
V_18 = V_20 + 1 ;
V_9 = F_15 ( sizeof( struct V_7 * ) *
V_18 , V_21 ) ;
if ( ! V_9 )
return - V_22 ;
for (; V_19 <= V_20 ; V_19 ++ ) {
struct V_7 * V_8 ;
V_8 = F_15 ( sizeof( * V_8 ) , V_21 ) ;
if ( ! V_8 )
goto V_23;
F_16 ( & V_8 -> V_12 ) ;
V_8 -> V_1 = V_19 ;
V_9 [ V_19 ] = V_8 ;
F_13 ( & V_8 -> V_12 , & V_11 ) ;
}
V_8 = F_5 ( 0 ) ;
F_11 ( & V_8 -> V_12 ) ;
F_17 ( & V_10 ) ;
V_24 = F_7 () ;
F_18 ( & V_10 ) ;
return 0 ;
V_23:
while ( V_19 -- )
F_19 ( V_9 [ V_19 ] ) ;
F_19 ( V_9 ) ;
return - V_22 ;
}
static bool F_20 ( struct V_25 * V_26 , struct V_25 * V_27 )
{
if ( ( V_26 -> V_28 & V_29 ) !=
( V_27 -> V_28 & V_29 ) )
return false ;
#ifdef F_21
if ( V_26 -> V_30 != V_27 -> V_30 )
return false ;
#endif
if ( ! ( V_27 -> V_28 & V_29 ) )
return true ;
if ( V_26 -> V_31 . V_32 == V_27 -> V_31 . V_32 )
return true ;
if ( V_27 -> V_33 == V_26 )
return true ;
return false ;
}
static inline struct V_34 * F_22 ( struct V_25 * V_35 )
{
if ( V_35 -> V_28 & V_29 )
return F_23 ( V_35 -> V_31 . V_32 , V_35 -> V_36 ) ;
return V_35 -> V_30 ;
}
static bool F_24 ( struct V_25 * V_26 , struct V_25 * V_27 )
{
#ifdef F_21
if ( V_26 -> V_30 && V_27 -> V_30 ) {
struct V_34 * V_37 = V_26 -> V_30 ;
struct V_34 * V_38 = V_27 -> V_30 ;
F_25 ( V_37 == V_38 ) ;
if ( F_26 ( V_37 -> V_39 . V_40 , V_38 -> V_39 . V_40 ) ||
F_26 ( V_38 -> V_39 . V_40 , V_37 -> V_39 . V_40 ) )
return true ;
return false ;
}
if ( V_26 -> V_30 || V_27 -> V_30 ) {
struct V_34 * V_37 , * V_38 ;
if ( ( V_26 -> V_30 && ! ( V_27 -> V_28 & V_29 ) ) ||
( V_27 -> V_30 && ! ( V_26 -> V_28 & V_29 ) ) )
return true ;
V_37 = F_22 ( V_26 ) ;
V_38 = F_22 ( V_27 ) ;
if ( V_37 == V_38 )
return true ;
if ( ! V_37 || ! V_38 )
return false ;
if ( F_26 ( V_37 -> V_39 . V_40 , V_38 -> V_39 . V_40 ) ||
F_26 ( V_38 -> V_39 . V_40 , V_37 -> V_39 . V_40 ) )
return true ;
return false ;
}
#endif
if ( ! ( V_26 -> V_28 & V_29 ) ||
! ( V_27 -> V_28 & V_29 ) )
return true ;
return false ;
}
static T_1 F_27 ( struct V_25 * V_41 , T_1 V_1 )
{
struct V_25 * V_35 ;
struct V_42 * V_43 = & V_41 -> V_31 . V_44 ;
T_1 V_45 = V_41 -> V_31 . V_46 ;
F_8 ( & V_10 ) ;
if ( F_1 ( V_45 ) && ! F_1 ( V_1 ) ) {
struct V_47 V_48 = {
. V_49 = F_28 ( 0 ) ,
. V_1 = V_45 ,
} ;
F_29 ( & V_50 , V_51 ,
& V_48 , 1 ) ;
F_30 ( & V_41 -> V_52 , F_31 ( & V_48 . V_49 ) ) ;
}
F_32 ( & V_53 ) ;
V_41 -> V_31 . V_46 = V_1 ;
F_33 (event, head, hw.cqm_group_entry)
V_35 -> V_31 . V_46 = V_1 ;
F_34 ( & V_53 ) ;
return V_45 ;
}
static void F_35 ( void * V_54 )
{
struct V_7 * V_8 ;
F_33 (entry, &cqm_rmid_limbo_lru, list) {
if ( V_8 -> V_15 != V_55 )
break;
if ( F_2 ( V_8 -> V_1 ) > V_56 )
V_8 -> V_15 = V_57 ;
}
}
static bool F_36 ( T_1 V_1 )
{
struct V_25 * V_58 , * V_35 ;
F_8 ( & V_10 ) ;
V_58 = F_10 ( & V_59 , struct V_25 ,
V_31 . V_60 ) ;
V_35 = V_58 ;
F_37 (event, &cache_groups,
hw.cqm_groups_entry) {
if ( F_1 ( V_35 -> V_31 . V_46 ) )
continue;
if ( F_24 ( V_35 , V_58 ) )
continue;
F_27 ( V_35 , V_1 ) ;
return true ;
}
return false ;
}
static bool F_38 ( unsigned int * V_61 )
{
struct V_7 * V_8 , * V_62 ;
F_8 ( & V_10 ) ;
* V_61 = 0 ;
F_33 (entry, &cqm_rmid_limbo_lru, list) {
unsigned long V_63 ;
unsigned long V_64 = V_14 ;
V_63 = V_8 -> V_13 +
F_39 ( V_65 ) ;
if ( F_40 ( V_63 , V_64 ) )
break;
V_8 -> V_15 = V_55 ;
( * V_61 ) ++ ;
}
if ( ! * V_61 )
return false ;
F_29 ( & V_50 , F_35 , NULL , true ) ;
F_41 (entry, tmp, &cqm_rmid_limbo_lru, list) {
if ( V_8 -> V_15 == V_16 )
break;
if ( V_8 -> V_15 == V_57 )
continue;
F_11 ( & V_8 -> V_12 ) ;
if ( ! F_1 ( V_24 ) ) {
V_24 = V_8 -> V_1 ;
continue;
}
if ( F_36 ( V_8 -> V_1 ) )
continue;
F_13 ( & V_8 -> V_12 , & V_11 ) ;
}
return F_1 ( V_24 ) ;
}
static void F_42 ( struct V_25 * V_66 )
{
struct V_25 * V_67 ;
T_1 V_1 ;
F_8 ( & V_10 ) ;
V_67 = F_10 ( & V_59 , struct V_25 ,
V_31 . V_60 ) ;
if ( V_66 == V_67 )
return;
V_1 = F_27 ( V_67 , V_2 ) ;
F_12 ( V_1 ) ;
F_43 ( & V_59 ) ;
}
static void F_44 ( struct V_25 * V_35 )
{
struct V_25 * V_41 , * V_68 ;
T_1 V_1 ;
F_8 ( & V_10 ) ;
F_41 (group, g, &cache_groups, hw.cqm_groups_entry) {
if ( V_41 == V_35 )
continue;
V_1 = V_41 -> V_31 . V_46 ;
if ( ! F_1 ( V_1 ) )
continue;
if ( ! F_24 ( V_41 , V_35 ) )
continue;
F_27 ( V_41 , V_2 ) ;
F_12 ( V_1 ) ;
}
}
static bool F_45 ( void )
{
struct V_25 * V_41 , * V_69 = NULL ;
unsigned int V_70 ;
unsigned int V_71 = 0 ;
unsigned int V_72 ;
bool V_73 = false ;
F_17 ( & V_10 ) ;
V_74:
if ( F_9 ( & V_59 ) && F_9 ( & V_17 ) )
goto V_75;
F_33 (group, &cache_groups, hw.cqm_groups_entry) {
if ( ! F_1 ( V_41 -> V_31 . V_46 ) ) {
if ( ! V_69 )
V_69 = V_41 ;
V_71 ++ ;
}
}
if ( ! V_71 && F_9 ( & V_17 ) )
goto V_75;
if ( ! V_71 )
goto V_76;
F_42 ( V_69 ) ;
if ( F_1 ( V_24 ) ) {
F_27 ( V_69 , V_24 ) ;
V_24 = F_7 () ;
F_44 ( V_69 ) ;
if ( V_56 )
V_56 -- ;
}
V_73 = true ;
V_76:
V_70 = V_77 / V_78 ;
while ( F_38 ( & V_72 ) &&
V_56 < V_70 ) {
unsigned int V_79 ;
if ( ! V_71 )
break;
V_79 = ( V_20 + 1 ) / 4 ;
if ( V_72 < V_79 )
goto V_74;
V_56 ++ ;
}
V_75:
F_18 ( & V_10 ) ;
return V_73 ;
}
static void F_46 ( struct V_80 * V_81 )
{
unsigned long V_82 ;
F_45 () ;
V_82 = F_39 ( V_83 . V_84 ) ;
F_47 ( & V_85 , V_82 ) ;
}
static void F_48 ( struct V_25 * V_35 ,
struct V_25 * * V_41 )
{
struct V_25 * V_86 ;
bool V_87 = false ;
T_1 V_1 ;
F_33 (iter, &cache_groups, hw.cqm_groups_entry) {
V_1 = V_86 -> V_31 . V_46 ;
if ( F_20 ( V_86 , V_35 ) ) {
V_35 -> V_31 . V_46 = V_1 ;
* V_41 = V_86 ;
return;
}
if ( F_24 ( V_86 , V_35 ) && F_1 ( V_1 ) )
V_87 = true ;
}
if ( V_87 )
V_1 = V_2 ;
else
V_1 = F_7 () ;
V_35 -> V_31 . V_46 = V_1 ;
}
static void F_49 ( struct V_25 * V_35 )
{
unsigned long V_88 ;
T_1 V_1 ;
T_2 V_3 ;
if ( V_35 -> V_89 == - 1 )
return;
F_50 ( & V_53 , V_88 ) ;
V_1 = V_35 -> V_31 . V_46 ;
if ( ! F_1 ( V_1 ) )
goto V_75;
V_3 = F_2 ( V_1 ) ;
if ( V_3 & ( V_90 | V_91 ) )
goto V_75;
F_30 ( & V_35 -> V_52 , V_3 ) ;
V_75:
F_51 ( & V_53 , V_88 ) ;
}
static void V_51 ( void * V_92 )
{
struct V_47 * V_48 = V_92 ;
T_2 V_3 ;
V_3 = F_2 ( V_48 -> V_1 ) ;
if ( V_3 & ( V_90 | V_91 ) )
return;
F_52 ( V_3 , & V_48 -> V_49 ) ;
}
static inline bool F_53 ( struct V_25 * V_35 )
{
return ! F_9 ( & V_35 -> V_31 . V_60 ) ;
}
static T_2 F_54 ( struct V_25 * V_35 )
{
unsigned long V_88 ;
struct V_47 V_48 = {
. V_49 = F_28 ( 0 ) ,
} ;
if ( V_35 -> V_89 != - 1 )
return F_55 ( V_35 ) ;
if ( ! F_53 ( V_35 ) )
return 0 ;
if ( F_56 ( F_57 () ) )
goto V_75;
V_48 . V_1 = F_58 ( V_35 -> V_31 . V_46 ) ;
if ( ! F_1 ( V_48 . V_1 ) )
goto V_75;
F_29 ( & V_50 , V_51 , & V_48 , 1 ) ;
F_50 ( & V_53 , V_88 ) ;
if ( V_35 -> V_31 . V_46 == V_48 . V_1 )
F_30 ( & V_35 -> V_52 , F_31 ( & V_48 . V_49 ) ) ;
F_51 ( & V_53 , V_88 ) ;
V_75:
return F_55 ( V_35 ) ;
}
static void F_59 ( struct V_25 * V_35 , int V_93 )
{
struct V_94 * V_15 = F_60 ( & V_95 ) ;
T_1 V_1 = V_35 -> V_31 . V_46 ;
if ( ! ( V_35 -> V_31 . V_96 & V_97 ) )
return;
V_35 -> V_31 . V_96 &= ~ V_97 ;
if ( V_15 -> V_98 ++ ) {
if ( ! F_25 ( V_15 -> V_1 != V_1 ) )
return;
} else {
F_25 ( V_15 -> V_1 ) ;
}
V_15 -> V_1 = V_1 ;
F_3 ( V_99 , V_1 , V_15 -> V_100 ) ;
}
static void F_61 ( struct V_25 * V_35 , int V_93 )
{
struct V_94 * V_15 = F_60 ( & V_95 ) ;
if ( V_35 -> V_31 . V_96 & V_97 )
return;
V_35 -> V_31 . V_96 |= V_97 ;
F_49 ( V_35 ) ;
if ( ! -- V_15 -> V_98 ) {
V_15 -> V_1 = 0 ;
F_3 ( V_99 , 0 , V_15 -> V_100 ) ;
} else {
F_25 ( ! V_15 -> V_1 ) ;
}
}
static int F_62 ( struct V_25 * V_35 , int V_93 )
{
unsigned long V_88 ;
T_1 V_1 ;
F_50 ( & V_53 , V_88 ) ;
V_35 -> V_31 . V_96 = V_97 ;
V_1 = V_35 -> V_31 . V_46 ;
if ( F_1 ( V_1 ) && ( V_93 & V_101 ) )
F_59 ( V_35 , V_93 ) ;
F_51 ( & V_53 , V_88 ) ;
return 0 ;
}
static void F_63 ( struct V_25 * V_35 )
{
struct V_25 * V_102 = NULL ;
F_17 ( & V_10 ) ;
if ( ! F_9 ( & V_35 -> V_31 . V_44 ) ) {
V_102 = F_10 ( & V_35 -> V_31 . V_44 ,
struct V_25 ,
V_31 . V_44 ) ;
F_11 ( & V_35 -> V_31 . V_44 ) ;
}
if ( F_53 ( V_35 ) ) {
if ( V_102 ) {
F_64 ( & V_35 -> V_31 . V_60 ,
& V_102 -> V_31 . V_60 ) ;
} else {
T_1 V_1 = V_35 -> V_31 . V_46 ;
if ( F_1 ( V_1 ) )
F_12 ( V_1 ) ;
F_11 ( & V_35 -> V_31 . V_60 ) ;
}
}
F_18 ( & V_10 ) ;
}
static int F_65 ( struct V_25 * V_35 )
{
struct V_25 * V_41 = NULL ;
bool V_103 = false ;
if ( V_35 -> V_104 . type != V_83 . type )
return - V_105 ;
if ( V_35 -> V_104 . V_106 & ~ V_107 )
return - V_108 ;
if ( V_35 -> V_104 . V_109 ||
V_35 -> V_104 . V_110 ||
V_35 -> V_104 . V_111 ||
V_35 -> V_104 . V_112 ||
V_35 -> V_104 . V_113 ||
V_35 -> V_104 . V_114 ||
V_35 -> V_104 . V_115 )
return - V_108 ;
F_16 ( & V_35 -> V_31 . V_44 ) ;
F_16 ( & V_35 -> V_31 . V_60 ) ;
V_35 -> V_116 = F_63 ;
F_17 ( & V_10 ) ;
F_48 ( V_35 , & V_41 ) ;
if ( V_41 ) {
F_13 ( & V_35 -> V_31 . V_44 ,
& V_41 -> V_31 . V_44 ) ;
} else {
F_13 ( & V_35 -> V_31 . V_60 ,
& V_59 ) ;
if ( ! F_1 ( V_35 -> V_31 . V_46 ) )
V_103 = true ;
}
F_18 ( & V_10 ) ;
if ( V_103 )
F_47 ( & V_85 , 0 ) ;
return 0 ;
}
static T_3
F_66 ( struct V_117 * V_118 , struct V_119 * V_104 ,
char * V_120 )
{
T_3 V_121 ;
F_17 ( & V_10 ) ;
V_121 = snprintf ( V_120 , V_122 - 1 , L_1 , V_77 ) ;
F_18 ( & V_10 ) ;
return V_121 ;
}
static T_3
F_67 ( struct V_117 * V_118 ,
struct V_119 * V_104 ,
const char * V_123 , T_4 V_52 )
{
unsigned int V_124 , V_125 ;
int V_126 ;
V_126 = F_68 ( V_123 , 0 , & V_124 ) ;
if ( V_126 )
return V_126 ;
F_17 ( & V_10 ) ;
V_77 = V_124 ;
V_125 = V_124 / V_78 ;
if ( V_56 > V_125 )
V_56 = V_125 ;
F_18 ( & V_10 ) ;
return V_52 ;
}
static inline void F_69 ( int V_89 )
{
int V_127 = F_70 ( V_89 ) ;
int V_128 ;
F_71 (i, &cqm_cpumask) {
if ( V_127 == F_70 ( V_128 ) )
return;
}
F_72 ( V_89 , & V_50 ) ;
}
static void F_73 ( unsigned int V_89 )
{
struct V_94 * V_15 = & F_74 ( V_95 , V_89 ) ;
struct V_129 * V_130 = & F_75 ( V_89 ) ;
V_15 -> V_1 = 0 ;
V_15 -> V_100 = 0 ;
V_15 -> V_98 = 0 ;
F_6 ( V_130 -> V_131 != V_20 ) ;
F_6 ( V_130 -> V_132 != V_78 ) ;
}
static void F_76 ( unsigned int V_89 )
{
int V_127 = F_70 ( V_89 ) ;
int V_128 ;
if ( ! F_77 ( V_89 , & V_50 ) )
return;
F_78 (i) {
if ( V_128 == V_89 )
continue;
if ( V_127 == F_70 ( V_128 ) ) {
F_72 ( V_128 , & V_50 ) ;
break;
}
}
}
static int F_79 ( struct V_133 * V_134 ,
unsigned long V_135 , void * V_136 )
{
unsigned int V_89 = ( unsigned long ) V_136 ;
switch ( V_135 & ~ V_137 ) {
case V_138 :
F_76 ( V_89 ) ;
break;
case V_139 :
F_73 ( V_89 ) ;
F_69 ( V_89 ) ;
break;
}
return V_140 ;
}
static int T_5 F_80 ( void )
{
char * V_141 , V_142 [ 20 ] ;
int V_128 , V_89 , V_126 ;
if ( ! F_81 ( V_143 ) )
return - V_144 ;
V_78 = V_145 . V_132 ;
F_82 () ;
F_78 (cpu) {
struct V_129 * V_130 = & F_75 ( V_89 ) ;
if ( V_130 -> V_131 < V_20 )
V_20 = V_130 -> V_131 ;
if ( V_130 -> V_132 != V_78 ) {
F_83 ( L_2 ) ;
V_126 = - V_108 ;
goto V_75;
}
}
V_77 =
V_145 . V_146 * 1024 / ( V_20 + 1 ) ;
snprintf ( V_142 , sizeof( V_142 ) , L_3 , V_78 ) ;
V_141 = F_84 ( V_142 , V_21 ) ;
if ( ! V_141 ) {
V_126 = - V_22 ;
goto V_75;
}
V_147 . V_148 = V_141 ;
V_126 = F_14 () ;
if ( V_126 )
goto V_75;
F_78 (i) {
F_73 ( V_128 ) ;
F_69 ( V_128 ) ;
}
F_85 ( F_79 ) ;
V_126 = F_86 ( & V_83 , L_4 , - 1 ) ;
if ( V_126 )
F_83 ( L_5 , V_126 ) ;
else
F_87 ( L_6 ) ;
V_75:
F_88 () ;
return V_126 ;
}
