static inline bool F_1 ( unsigned int V_1 )
{
if ( ! V_1 || V_1 == V_2 )
return false ;
return true ;
}
static T_1 F_2 ( unsigned int V_1 )
{
T_1 V_3 ;
F_3 ( V_4 , V_5 , V_1 ) ;
F_4 ( V_6 , V_3 ) ;
return V_3 ;
}
static inline struct V_7 * F_5 ( int V_1 )
{
struct V_7 * V_8 ;
V_8 = V_9 [ V_1 ] ;
F_6 ( V_8 -> V_1 != V_1 ) ;
return V_8 ;
}
static int F_7 ( void )
{
struct V_7 * V_8 ;
F_8 ( & V_10 ) ;
if ( F_9 ( & V_11 ) )
return V_2 ;
V_8 = F_10 ( & V_11 , struct V_7 , V_12 ) ;
F_11 ( & V_8 -> V_12 ) ;
return V_8 -> V_1 ;
}
static void F_12 ( unsigned int V_1 )
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
return F_23 ( V_35 -> V_31 . V_32 ) ;
return V_35 -> V_30 ;
}
static bool F_24 ( struct V_25 * V_26 , struct V_25 * V_27 )
{
#ifdef F_21
if ( V_26 -> V_30 && V_27 -> V_30 ) {
struct V_34 * V_36 = V_26 -> V_30 ;
struct V_34 * V_37 = V_27 -> V_30 ;
F_25 ( V_36 == V_37 ) ;
if ( F_26 ( V_36 -> V_38 . V_39 , V_37 -> V_38 . V_39 ) ||
F_26 ( V_37 -> V_38 . V_39 , V_36 -> V_38 . V_39 ) )
return true ;
return false ;
}
if ( V_26 -> V_30 || V_27 -> V_30 ) {
struct V_34 * V_36 , * V_37 ;
if ( ( V_26 -> V_30 && ! ( V_27 -> V_28 & V_29 ) ) ||
( V_27 -> V_30 && ! ( V_26 -> V_28 & V_29 ) ) )
return true ;
V_36 = F_22 ( V_26 ) ;
V_37 = F_22 ( V_27 ) ;
if ( V_36 == V_37 )
return true ;
if ( ! V_36 || ! V_37 )
return false ;
if ( F_26 ( V_36 -> V_38 . V_39 , V_37 -> V_38 . V_39 ) ||
F_26 ( V_37 -> V_38 . V_39 , V_36 -> V_38 . V_39 ) )
return true ;
return false ;
}
#endif
if ( ! ( V_26 -> V_28 & V_29 ) ||
! ( V_27 -> V_28 & V_29 ) )
return true ;
return false ;
}
static unsigned int
F_27 ( struct V_25 * V_40 , unsigned int V_1 )
{
struct V_25 * V_35 ;
unsigned int V_41 = V_40 -> V_31 . V_42 ;
struct V_43 * V_44 = & V_40 -> V_31 . V_45 ;
F_8 ( & V_10 ) ;
if ( F_1 ( V_41 ) && ! F_1 ( V_1 ) ) {
struct V_46 V_47 = {
. V_48 = F_28 ( 0 ) ,
. V_1 = V_41 ,
} ;
F_29 ( & V_49 , V_50 ,
& V_47 , 1 ) ;
F_30 ( & V_40 -> V_51 , F_31 ( & V_47 . V_48 ) ) ;
}
F_32 ( & V_52 ) ;
V_40 -> V_31 . V_42 = V_1 ;
F_33 (event, head, hw.cqm_group_entry)
V_35 -> V_31 . V_42 = V_1 ;
F_34 ( & V_52 ) ;
return V_41 ;
}
static void F_35 ( void * V_53 )
{
struct V_7 * V_8 ;
F_33 (entry, &cqm_rmid_limbo_lru, list) {
if ( V_8 -> V_15 != V_54 )
break;
if ( F_2 ( V_8 -> V_1 ) > V_55 )
V_8 -> V_15 = V_56 ;
}
}
static bool F_36 ( unsigned int V_1 )
{
struct V_25 * V_57 , * V_35 ;
F_8 ( & V_10 ) ;
V_57 = F_10 ( & V_58 , struct V_25 ,
V_31 . V_59 ) ;
V_35 = V_57 ;
F_37 (event, &cache_groups,
hw.cqm_groups_entry) {
if ( F_1 ( V_35 -> V_31 . V_42 ) )
continue;
if ( F_24 ( V_35 , V_57 ) )
continue;
F_27 ( V_35 , V_1 ) ;
return true ;
}
return false ;
}
static bool F_38 ( unsigned int * V_60 )
{
struct V_7 * V_8 , * V_61 ;
F_8 ( & V_10 ) ;
* V_60 = 0 ;
F_33 (entry, &cqm_rmid_limbo_lru, list) {
unsigned long V_62 ;
unsigned long V_63 = V_14 ;
V_62 = V_8 -> V_13 +
F_39 ( V_64 ) ;
if ( F_40 ( V_62 , V_63 ) )
break;
V_8 -> V_15 = V_54 ;
( * V_60 ) ++ ;
}
if ( ! * V_60 )
return false ;
F_29 ( & V_49 , F_35 , NULL , true ) ;
F_41 (entry, tmp, &cqm_rmid_limbo_lru, list) {
if ( V_8 -> V_15 == V_16 )
break;
if ( V_8 -> V_15 == V_56 )
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
static void F_42 ( struct V_25 * V_65 )
{
struct V_25 * V_66 ;
unsigned int V_1 ;
F_8 ( & V_10 ) ;
V_66 = F_10 ( & V_58 , struct V_25 ,
V_31 . V_59 ) ;
if ( V_65 == V_66 )
return;
V_1 = F_27 ( V_66 , V_2 ) ;
F_12 ( V_1 ) ;
F_43 ( & V_58 ) ;
}
static void F_44 ( struct V_25 * V_35 )
{
struct V_25 * V_40 , * V_67 ;
unsigned int V_1 ;
F_8 ( & V_10 ) ;
F_41 (group, g, &cache_groups, hw.cqm_groups_entry) {
if ( V_40 == V_35 )
continue;
V_1 = V_40 -> V_31 . V_42 ;
if ( ! F_1 ( V_1 ) )
continue;
if ( ! F_24 ( V_40 , V_35 ) )
continue;
F_27 ( V_40 , V_2 ) ;
F_12 ( V_1 ) ;
}
}
static bool F_45 ( void )
{
struct V_25 * V_40 , * V_68 = NULL ;
unsigned int V_69 ;
unsigned int V_70 = 0 ;
unsigned int V_71 ;
bool V_72 = false ;
F_17 ( & V_10 ) ;
V_73:
if ( F_9 ( & V_58 ) && F_9 ( & V_17 ) )
goto V_74;
F_33 (group, &cache_groups, hw.cqm_groups_entry) {
if ( ! F_1 ( V_40 -> V_31 . V_42 ) ) {
if ( ! V_68 )
V_68 = V_40 ;
V_70 ++ ;
}
}
if ( ! V_70 && F_9 ( & V_17 ) )
goto V_74;
if ( ! V_70 )
goto V_75;
F_42 ( V_68 ) ;
if ( F_1 ( V_24 ) ) {
F_27 ( V_68 , V_24 ) ;
V_24 = F_7 () ;
F_44 ( V_68 ) ;
if ( V_55 )
V_55 -- ;
}
V_72 = true ;
V_75:
V_69 = V_76 / V_77 ;
while ( F_38 ( & V_71 ) &&
V_55 < V_69 ) {
unsigned int V_78 ;
if ( ! V_70 )
break;
V_78 = ( V_20 + 1 ) / 4 ;
if ( V_71 < V_78 )
goto V_73;
V_55 ++ ;
}
V_74:
F_18 ( & V_10 ) ;
return V_72 ;
}
static void F_46 ( struct V_79 * V_80 )
{
unsigned long V_81 ;
F_45 () ;
V_81 = F_39 ( V_82 . V_83 ) ;
F_47 ( & V_84 , V_81 ) ;
}
static void F_48 ( struct V_25 * V_35 ,
struct V_25 * * V_40 )
{
struct V_25 * V_85 ;
unsigned int V_1 ;
bool V_86 = false ;
F_33 (iter, &cache_groups, hw.cqm_groups_entry) {
V_1 = V_85 -> V_31 . V_42 ;
if ( F_20 ( V_85 , V_35 ) ) {
V_35 -> V_31 . V_42 = V_1 ;
* V_40 = V_85 ;
return;
}
if ( F_24 ( V_85 , V_35 ) && F_1 ( V_1 ) )
V_86 = true ;
}
if ( V_86 )
V_1 = V_2 ;
else
V_1 = F_7 () ;
V_35 -> V_31 . V_42 = V_1 ;
}
static void F_49 ( struct V_25 * V_35 )
{
unsigned long V_87 ;
unsigned int V_1 ;
T_1 V_3 ;
if ( V_35 -> V_88 == - 1 )
return;
F_50 ( & V_52 , V_87 ) ;
V_1 = V_35 -> V_31 . V_42 ;
if ( ! F_1 ( V_1 ) )
goto V_74;
V_3 = F_2 ( V_1 ) ;
if ( V_3 & ( V_89 | V_90 ) )
goto V_74;
F_30 ( & V_35 -> V_51 , V_3 ) ;
V_74:
F_51 ( & V_52 , V_87 ) ;
}
static void V_50 ( void * V_91 )
{
struct V_46 * V_47 = V_91 ;
T_1 V_3 ;
V_3 = F_2 ( V_47 -> V_1 ) ;
if ( V_3 & ( V_89 | V_90 ) )
return;
F_52 ( V_3 , & V_47 -> V_48 ) ;
}
static inline bool F_53 ( struct V_25 * V_35 )
{
return ! F_9 ( & V_35 -> V_31 . V_59 ) ;
}
static T_1 F_54 ( struct V_25 * V_35 )
{
unsigned long V_87 ;
struct V_46 V_47 = {
. V_48 = F_28 ( 0 ) ,
} ;
if ( V_35 -> V_88 != - 1 )
return F_55 ( V_35 ) ;
if ( ! F_53 ( V_35 ) )
return 0 ;
V_47 . V_1 = F_56 ( V_35 -> V_31 . V_42 ) ;
if ( ! F_1 ( V_47 . V_1 ) )
goto V_74;
F_29 ( & V_49 , V_50 , & V_47 , 1 ) ;
F_50 ( & V_52 , V_87 ) ;
if ( V_35 -> V_31 . V_42 == V_47 . V_1 )
F_30 ( & V_35 -> V_51 , F_31 ( & V_47 . V_48 ) ) ;
F_51 ( & V_52 , V_87 ) ;
V_74:
return F_55 ( V_35 ) ;
}
static void F_57 ( struct V_25 * V_35 , int V_92 )
{
struct V_93 * V_15 = F_58 ( & V_94 ) ;
unsigned int V_1 = V_35 -> V_31 . V_42 ;
unsigned long V_87 ;
if ( ! ( V_35 -> V_31 . V_94 & V_95 ) )
return;
V_35 -> V_31 . V_94 &= ~ V_95 ;
F_50 ( & V_15 -> V_96 , V_87 ) ;
if ( V_15 -> V_97 ++ )
F_25 ( V_15 -> V_1 != V_1 ) ;
else
F_25 ( V_15 -> V_1 ) ;
V_15 -> V_1 = V_1 ;
F_59 ( V_98 , V_15 -> V_1 ) ;
F_51 ( & V_15 -> V_96 , V_87 ) ;
}
static void F_60 ( struct V_25 * V_35 , int V_92 )
{
struct V_93 * V_15 = F_58 ( & V_94 ) ;
unsigned long V_87 ;
if ( V_35 -> V_31 . V_94 & V_95 )
return;
V_35 -> V_31 . V_94 |= V_95 ;
F_50 ( & V_15 -> V_96 , V_87 ) ;
F_49 ( V_35 ) ;
if ( ! -- V_15 -> V_97 ) {
V_15 -> V_1 = 0 ;
F_59 ( V_98 , 0 ) ;
} else {
F_25 ( ! V_15 -> V_1 ) ;
}
F_51 ( & V_15 -> V_96 , V_87 ) ;
}
static int F_61 ( struct V_25 * V_35 , int V_92 )
{
unsigned long V_87 ;
unsigned int V_1 ;
F_50 ( & V_52 , V_87 ) ;
V_35 -> V_31 . V_94 = V_95 ;
V_1 = V_35 -> V_31 . V_42 ;
if ( F_1 ( V_1 ) && ( V_92 & V_99 ) )
F_57 ( V_35 , V_92 ) ;
F_51 ( & V_52 , V_87 ) ;
return 0 ;
}
static void F_62 ( struct V_25 * V_35 , int V_92 )
{
F_60 ( V_35 , V_92 ) ;
}
static void F_63 ( struct V_25 * V_35 )
{
struct V_25 * V_100 = NULL ;
F_17 ( & V_10 ) ;
if ( ! F_9 ( & V_35 -> V_31 . V_45 ) ) {
V_100 = F_10 ( & V_35 -> V_31 . V_45 ,
struct V_25 ,
V_31 . V_45 ) ;
F_11 ( & V_35 -> V_31 . V_45 ) ;
}
if ( F_53 ( V_35 ) ) {
if ( V_100 ) {
F_64 ( & V_35 -> V_31 . V_59 ,
& V_100 -> V_31 . V_59 ) ;
} else {
unsigned int V_1 = V_35 -> V_31 . V_42 ;
if ( F_1 ( V_1 ) )
F_12 ( V_1 ) ;
F_11 ( & V_35 -> V_31 . V_59 ) ;
}
}
F_18 ( & V_10 ) ;
}
static int F_65 ( struct V_25 * V_35 )
{
struct V_25 * V_40 = NULL ;
bool V_101 = false ;
if ( V_35 -> V_102 . type != V_82 . type )
return - V_103 ;
if ( V_35 -> V_102 . V_104 & ~ V_105 )
return - V_106 ;
if ( V_35 -> V_102 . V_107 ||
V_35 -> V_102 . V_108 ||
V_35 -> V_102 . V_109 ||
V_35 -> V_102 . V_110 ||
V_35 -> V_102 . V_111 ||
V_35 -> V_102 . V_112 ||
V_35 -> V_102 . V_113 )
return - V_106 ;
F_16 ( & V_35 -> V_31 . V_45 ) ;
F_16 ( & V_35 -> V_31 . V_59 ) ;
V_35 -> V_114 = F_63 ;
F_17 ( & V_10 ) ;
F_48 ( V_35 , & V_40 ) ;
if ( V_40 ) {
F_13 ( & V_35 -> V_31 . V_45 ,
& V_40 -> V_31 . V_45 ) ;
} else {
F_13 ( & V_35 -> V_31 . V_59 ,
& V_58 ) ;
if ( ! F_1 ( V_35 -> V_31 . V_42 ) )
V_101 = true ;
}
F_18 ( & V_10 ) ;
if ( V_101 )
F_47 ( & V_84 , 0 ) ;
return 0 ;
}
static T_2
F_66 ( struct V_115 * V_116 , struct V_117 * V_102 ,
char * V_118 )
{
T_2 V_119 ;
F_17 ( & V_10 ) ;
V_119 = snprintf ( V_118 , V_120 - 1 , L_1 , V_76 ) ;
F_18 ( & V_10 ) ;
return V_119 ;
}
static T_2
F_67 ( struct V_115 * V_116 ,
struct V_117 * V_102 ,
const char * V_121 , T_3 V_51 )
{
unsigned int V_122 , V_123 ;
int V_124 ;
V_124 = F_68 ( V_121 , 0 , & V_122 ) ;
if ( V_124 )
return V_124 ;
F_17 ( & V_10 ) ;
V_76 = V_122 ;
V_123 = V_122 / V_77 ;
if ( V_55 > V_123 )
V_55 = V_123 ;
F_18 ( & V_10 ) ;
return V_51 ;
}
static inline void F_69 ( int V_88 )
{
int V_125 = F_70 ( V_88 ) ;
int V_126 ;
F_71 (i, &cqm_cpumask) {
if ( V_125 == F_70 ( V_126 ) )
return;
}
F_72 ( V_88 , & V_49 ) ;
}
static void F_73 ( unsigned int V_88 )
{
struct V_93 * V_15 = & F_74 ( V_94 , V_88 ) ;
struct V_127 * V_128 = & F_75 ( V_88 ) ;
F_76 ( & V_15 -> V_96 ) ;
V_15 -> V_1 = 0 ;
V_15 -> V_97 = 0 ;
F_6 ( V_128 -> V_129 != V_20 ) ;
F_6 ( V_128 -> V_130 != V_77 ) ;
}
static void F_77 ( unsigned int V_88 )
{
int V_125 = F_70 ( V_88 ) ;
int V_126 ;
if ( ! F_78 ( V_88 , & V_49 ) )
return;
F_79 (i) {
if ( V_126 == V_88 )
continue;
if ( V_125 == F_70 ( V_126 ) ) {
F_72 ( V_126 , & V_49 ) ;
break;
}
}
}
static int F_80 ( struct V_131 * V_132 ,
unsigned long V_133 , void * V_134 )
{
unsigned int V_88 = ( unsigned long ) V_134 ;
switch ( V_133 & ~ V_135 ) {
case V_136 :
F_73 ( V_88 ) ;
break;
case V_137 :
F_77 ( V_88 ) ;
break;
case V_138 :
F_69 ( V_88 ) ;
break;
}
return V_139 ;
}
static int T_4 F_81 ( void )
{
char * V_140 , V_141 [ 20 ] ;
int V_126 , V_88 , V_124 ;
if ( ! F_82 ( V_142 ) )
return - V_143 ;
V_77 = V_144 . V_130 ;
F_83 () ;
F_79 (cpu) {
struct V_127 * V_128 = & F_75 ( V_88 ) ;
if ( V_128 -> V_129 < V_20 )
V_20 = V_128 -> V_129 ;
if ( V_128 -> V_130 != V_77 ) {
F_84 ( L_2 ) ;
V_124 = - V_106 ;
goto V_74;
}
}
V_76 =
V_144 . V_145 * 1024 / ( V_20 + 1 ) ;
snprintf ( V_141 , sizeof( V_141 ) , L_3 , V_77 ) ;
V_140 = F_85 ( V_141 , V_21 ) ;
if ( ! V_140 ) {
V_124 = - V_22 ;
goto V_74;
}
V_146 . V_147 = V_140 ;
V_124 = F_14 () ;
if ( V_124 )
goto V_74;
F_79 (i) {
F_73 ( V_126 ) ;
F_69 ( V_126 ) ;
}
F_86 ( F_80 ) ;
V_124 = F_87 ( & V_82 , L_4 , - 1 ) ;
if ( V_124 )
F_84 ( L_5 , V_124 ) ;
else
F_88 ( L_6 ) ;
V_74:
F_89 () ;
return V_124 ;
}
