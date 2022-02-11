static T_1 F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 , char * V_5 )
{
struct V_6 * V_7 = F_2 ( V_4 ,
struct V_6 , V_4 ) ;
return snprintf ( V_5 , V_8 , L_1 , ( unsigned long ) V_7 -> V_9 ) ;
}
static int F_3 ( struct V_10 * V_10 ,
struct V_11 * V_12 ,
unsigned long V_13 )
{
int V_14 ;
if ( V_13 == V_15 ) {
if ( F_4 ( V_16 , V_12 -> V_17 ) )
return - V_18 ;
return V_16 ;
}
for ( V_14 = V_19 ; V_14 <= F_5 ( V_10 ) ; ++ V_14 )
if ( ! F_4 ( V_14 , V_12 -> V_17 ) )
return V_14 ;
return - V_18 ;
}
static int F_6 ( struct V_10 * V_10 , unsigned long V_20 )
{
T_2 V_21 = F_7 ( V_20 ) ;
T_2 V_22 = F_8 ( V_20 ) ;
int V_23 ;
if ( V_20 & ~ V_24 )
return - V_25 ;
if ( V_20 == V_15 )
return V_20 ;
switch ( V_21 ) {
case V_26 :
case V_27 :
case V_28 :
case V_29 :
case V_30 :
V_23 = V_31 ;
break;
case V_32 :
case V_33 :
case V_34 :
V_23 = V_35 ;
break;
default:
return - V_25 ;
}
if ( V_22 >= V_10 -> V_36 -> V_37 [ V_23 ] . V_38 &&
V_22 <= V_10 -> V_36 -> V_37 [ V_23 ] . V_39 )
return V_20 ;
return - V_25 ;
}
static int F_9 ( void )
{
int V_40 ;
V_40 = F_10 ( V_41 + V_42 ) & V_43 ;
V_40 >>= V_44 ;
if ( V_40 < V_45 )
return V_46 ;
else
return V_47 ;
}
static const struct V_48 * F_11 ( struct V_49 * V_50 )
{
if ( F_12 () )
return & V_51 [ F_9 () ] ;
return NULL ;
}
static inline struct V_48 * F_11 ( struct V_49 * V_50 )
{
return NULL ;
}
static T_1 F_13 ( struct V_1 * V_2 ,
struct V_3 * V_4 , char * V_5 )
{
struct V_6 * V_7 = F_2 ( V_4 ,
struct V_6 , V_4 ) ;
return snprintf ( V_5 , V_8 , L_2 ,
( unsigned long ) V_7 -> V_9 , V_52 ) ;
}
static int F_14 ( struct V_10 * V_10 ,
unsigned long V_20 )
{
T_3 V_21 = F_15 ( V_20 ) ;
T_3 V_22 = F_16 ( V_20 ) ;
int V_23 ;
if ( V_20 & ~ V_53 )
return - V_25 ;
switch ( V_21 ) {
case V_54 :
case V_55 :
case V_56 :
case V_57 :
case V_58 :
case V_59 :
case V_60 :
V_23 = V_31 ;
break;
case V_61 :
case V_62 :
case V_63 :
case V_64 :
case V_65 :
case V_66 :
V_23 = V_35 ;
break;
case V_52 :
V_23 = V_67 ;
break;
default:
return - V_25 ;
}
if ( V_22 >= V_10 -> V_36 -> V_37 [ V_23 ] . V_38 &&
V_22 <= V_10 -> V_36 -> V_37 [ V_23 ] . V_39 )
return V_20 ;
return - V_25 ;
}
static int F_17 ( struct V_10 * V_10 ,
unsigned long V_20 )
{
T_3 V_21 = F_15 ( V_20 ) ;
T_3 V_22 = F_16 ( V_20 ) ;
int V_23 ;
if ( V_20 & ~ V_53 )
return - V_25 ;
switch ( V_21 ) {
case V_54 :
case V_55 :
case V_56 :
case V_57 :
case V_58 :
case V_59 :
case V_60 :
V_23 = V_31 ;
break;
case V_61 :
case V_62 :
case V_63 :
case V_64 :
case V_65 :
case V_66 :
case V_68 :
V_23 = V_35 ;
break;
case V_52 :
V_23 = V_67 ;
break;
default:
return - V_25 ;
}
if ( V_22 >= V_10 -> V_36 -> V_37 [ V_23 ] . V_38 &&
V_22 <= V_10 -> V_36 -> V_37 [ V_23 ] . V_39 )
return V_20 ;
return - V_25 ;
}
static void F_18 ( struct V_10 * V_10 )
{
int V_69 ;
struct V_11 * V_70 = & V_10 -> V_71 ;
F_19 ( V_72 , V_10 -> V_73 ) ;
F_20 ( V_72 , V_10 -> V_73 ) ;
F_21 (i, cci_pmu->hw_events.used_mask, cci_pmu->num_cntrs) {
struct V_74 * V_75 = V_70 -> V_76 [ V_69 ] ;
if ( F_22 ( ! V_75 ) )
continue;
if ( V_75 -> V_12 . V_77 & V_78 )
continue;
if ( V_75 -> V_12 . V_77 & V_79 ) {
F_23 ( V_69 , V_72 ) ;
V_75 -> V_12 . V_77 &= ~ V_79 ;
}
}
F_24 ( V_10 , V_72 ) ;
}
static void F_25 ( struct V_10 * V_10 )
{
T_3 V_80 ;
V_80 = F_10 ( V_41 + V_81 ) | V_82 ;
F_26 ( V_80 , V_41 + V_81 ) ;
}
static void F_27 ( struct V_10 * V_10 )
{
F_18 ( V_10 ) ;
F_25 ( V_10 ) ;
}
static void F_28 ( void )
{
T_3 V_80 ;
V_80 = F_10 ( V_41 + V_81 ) & ~ V_82 ;
F_26 ( V_80 , V_41 + V_81 ) ;
}
static T_1 F_29 ( struct V_1 * V_2 ,
struct V_3 * V_4 , char * V_5 )
{
struct V_6 * V_7 = F_2 ( V_4 ,
struct V_6 , V_4 ) ;
return snprintf ( V_5 , V_8 , L_3 , ( char * ) V_7 -> V_9 ) ;
}
static T_1 F_30 ( struct V_1 * V_2 ,
struct V_3 * V_4 , char * V_5 )
{
struct V_6 * V_7 = F_2 ( V_4 ,
struct V_6 , V_4 ) ;
return snprintf ( V_5 , V_8 , L_4 ,
( unsigned long ) V_7 -> V_9 ) ;
}
static int F_31 ( struct V_10 * V_10 , int V_14 )
{
return 0 <= V_14 && V_14 <= F_5 ( V_10 ) ;
}
static T_3 F_32 ( struct V_10 * V_10 , int V_14 , unsigned int V_83 )
{
return F_10 ( V_10 -> V_84 +
F_33 ( V_10 -> V_36 , V_14 ) + V_83 ) ;
}
static void F_34 ( struct V_10 * V_10 , T_3 V_85 ,
int V_14 , unsigned int V_83 )
{
F_35 ( V_85 , V_10 -> V_84 +
F_33 ( V_10 -> V_36 , V_14 ) + V_83 ) ;
}
static void F_36 ( struct V_10 * V_10 , int V_14 )
{
F_34 ( V_10 , 0 , V_14 , V_86 ) ;
}
static void F_37 ( struct V_10 * V_10 , int V_14 )
{
F_34 ( V_10 , 1 , V_14 , V_86 ) ;
}
static bool T_4
F_38 ( struct V_10 * V_10 , int V_14 )
{
return ( F_32 ( V_10 , V_14 , V_86 ) & 0x1 ) != 0 ;
}
static void F_39 ( struct V_10 * V_10 , int V_14 , unsigned long V_75 )
{
F_34 ( V_10 , V_75 , V_14 , V_87 ) ;
}
static void T_4
F_40 ( struct V_10 * V_10 , unsigned long * V_72 )
{
int V_69 ;
for ( V_69 = 0 ; V_69 < V_10 -> V_73 ; V_69 ++ ) {
if ( F_38 ( V_10 , V_69 ) ) {
F_23 ( V_69 , V_72 ) ;
F_36 ( V_10 , V_69 ) ;
}
}
}
static void T_4
F_41 ( struct V_10 * V_10 , unsigned long * V_72 )
{
int V_69 ;
F_21 (i, mask, cci_pmu->num_cntrs)
F_37 ( V_10 , V_69 ) ;
}
static T_3 F_42 ( void )
{
return ( F_10 ( V_41 + V_81 ) &
V_88 ) >> V_89 ;
}
static int F_43 ( struct V_11 * V_12 , struct V_74 * V_75 )
{
struct V_10 * V_10 = F_44 ( V_75 -> V_90 ) ;
unsigned long V_13 = V_75 -> V_12 . V_91 ;
int V_14 ;
if ( V_10 -> V_36 -> V_92 )
return V_10 -> V_36 -> V_92 ( V_10 , V_12 , V_13 ) ;
for( V_14 = 0 ; V_14 <= F_5 ( V_10 ) ; V_14 ++ )
if ( ! F_4 ( V_14 , V_12 -> V_17 ) )
return V_14 ;
return - V_18 ;
}
static int F_45 ( struct V_74 * V_75 )
{
struct V_10 * V_10 = F_44 ( V_75 -> V_90 ) ;
if ( V_75 -> V_4 . type < V_93 ||
! V_10 -> V_36 -> V_94 )
return - V_25 ;
return V_10 -> V_36 -> V_94 ( V_10 , V_75 -> V_4 . V_95 ) ;
}
static int F_46 ( struct V_10 * V_10 , T_5 V_96 )
{
int V_69 ;
struct V_49 * V_97 = V_10 -> V_98 ;
if ( F_47 ( ! V_97 ) )
return - V_99 ;
if ( V_10 -> V_100 < 1 ) {
F_48 ( & V_97 -> V_2 , L_5 ) ;
return - V_99 ;
}
for ( V_69 = 0 ; V_69 < V_10 -> V_100 ; V_69 ++ ) {
int V_101 = F_49 ( V_10 -> V_102 [ V_69 ] , V_96 , V_103 ,
L_6 , V_10 ) ;
if ( V_101 ) {
F_48 ( & V_97 -> V_2 , L_7 ,
V_10 -> V_102 [ V_69 ] ) ;
return V_101 ;
}
F_23 ( V_69 , & V_10 -> V_104 ) ;
}
return 0 ;
}
static void F_50 ( struct V_10 * V_10 )
{
int V_69 ;
for ( V_69 = 0 ; V_69 < V_10 -> V_100 ; V_69 ++ ) {
if ( ! F_51 ( V_69 , & V_10 -> V_104 ) )
continue;
F_52 ( V_10 -> V_102 [ V_69 ] , V_10 ) ;
}
}
static T_3 F_53 ( struct V_74 * V_75 )
{
struct V_10 * V_10 = F_44 ( V_75 -> V_90 ) ;
struct V_105 * V_106 = & V_75 -> V_12 ;
int V_14 = V_106 -> V_14 ;
T_3 V_85 ;
if ( F_47 ( ! F_31 ( V_10 , V_14 ) ) ) {
F_48 ( & V_10 -> V_98 -> V_2 , L_8 , V_14 ) ;
return 0 ;
}
V_85 = F_32 ( V_10 , V_14 , V_107 ) ;
return V_85 ;
}
static void F_54 ( struct V_10 * V_10 , T_3 V_85 , int V_14 )
{
F_34 ( V_10 , V_85 , V_14 , V_107 ) ;
}
static void F_55 ( struct V_10 * V_10 , unsigned long * V_72 )
{
int V_69 ;
struct V_11 * V_70 = & V_10 -> V_71 ;
F_21 (i, mask, cci_pmu->num_cntrs) {
struct V_74 * V_75 = V_70 -> V_76 [ V_69 ] ;
if ( F_22 ( ! V_75 ) )
continue;
F_54 ( V_10 , F_56 ( & V_75 -> V_12 . V_108 ) , V_69 ) ;
}
}
static void F_24 ( struct V_10 * V_10 , unsigned long * V_72 )
{
if ( V_10 -> V_36 -> V_109 )
V_10 -> V_36 -> V_109 ( V_10 , V_72 ) ;
else
F_55 ( V_10 , V_72 ) ;
}
static void F_57 ( struct V_10 * V_10 , unsigned long * V_72 )
{
int V_69 ;
F_19 ( V_110 , V_10 -> V_73 ) ;
F_20 ( V_110 , V_10 -> V_73 ) ;
F_40 ( V_10 , V_110 ) ;
F_25 ( V_10 ) ;
F_21 (i, mask, cci_pmu->num_cntrs) {
struct V_74 * V_75 = V_10 -> V_71 . V_76 [ V_69 ] ;
if ( F_22 ( ! V_75 ) )
continue;
F_39 ( V_10 , V_69 , V_111 ) ;
F_37 ( V_10 , V_69 ) ;
F_54 ( V_10 , F_56 ( & V_75 -> V_12 . V_108 ) , V_69 ) ;
F_36 ( V_10 , V_69 ) ;
F_39 ( V_10 , V_69 , V_75 -> V_12 . V_91 ) ;
}
F_28 () ;
F_41 ( V_10 , V_110 ) ;
}
static T_6 F_58 ( struct V_74 * V_75 )
{
struct V_105 * V_112 = & V_75 -> V_12 ;
T_6 V_113 , V_114 , V_115 ;
do {
V_114 = F_56 ( & V_112 -> V_108 ) ;
V_115 = F_53 ( V_75 ) ;
} while ( F_59 ( & V_112 -> V_108 , V_114 ,
V_115 ) != V_114 );
V_113 = ( V_115 - V_114 ) & V_116 ;
F_60 ( V_113 , & V_75 -> V_117 ) ;
return V_115 ;
}
static void F_61 ( struct V_74 * V_75 )
{
F_58 ( V_75 ) ;
}
static void F_62 ( struct V_74 * V_75 )
{
struct V_105 * V_112 = & V_75 -> V_12 ;
T_6 V_80 = 1ULL << 31 ;
F_63 ( & V_112 -> V_108 , V_80 ) ;
V_112 -> V_77 |= V_79 ;
}
static T_7 F_64 ( int V_118 , void * V_2 )
{
unsigned long V_119 ;
struct V_10 * V_10 = V_2 ;
struct V_11 * V_76 = & V_10 -> V_71 ;
int V_14 , V_120 = V_121 ;
F_65 ( & V_76 -> V_122 , V_119 ) ;
F_28 () ;
for ( V_14 = 0 ; V_14 <= F_5 ( V_10 ) ; V_14 ++ ) {
struct V_74 * V_75 = V_76 -> V_76 [ V_14 ] ;
if ( ! V_75 )
continue;
if ( ! ( F_32 ( V_10 , V_14 , V_123 ) &
V_124 ) )
continue;
F_34 ( V_10 , V_124 , V_14 ,
V_123 ) ;
F_58 ( V_75 ) ;
F_62 ( V_75 ) ;
V_120 = V_125 ;
}
F_27 ( V_10 ) ;
F_66 ( & V_76 -> V_122 , V_119 ) ;
return F_67 ( V_120 ) ;
}
static int F_68 ( struct V_10 * V_10 )
{
int V_126 = F_46 ( V_10 , F_64 ) ;
if ( V_126 ) {
F_50 ( V_10 ) ;
return V_126 ;
}
return 0 ;
}
static void F_69 ( struct V_10 * V_10 )
{
F_50 ( V_10 ) ;
}
static void F_70 ( struct V_74 * V_75 )
{
struct V_10 * V_10 = F_44 ( V_75 -> V_90 ) ;
T_8 * V_127 = & V_10 -> V_127 ;
struct V_128 * V_129 = & V_10 -> V_129 ;
if ( F_71 ( V_127 , V_129 ) ) {
F_69 ( V_10 ) ;
F_72 ( V_129 ) ;
}
}
static void F_73 ( struct V_90 * V_90 )
{
struct V_10 * V_10 = F_44 ( V_90 ) ;
struct V_11 * V_71 = & V_10 -> V_71 ;
int V_130 = F_74 ( V_71 -> V_17 , V_10 -> V_73 ) ;
unsigned long V_119 ;
if ( ! V_130 )
return;
F_65 ( & V_71 -> V_122 , V_119 ) ;
F_27 ( V_10 ) ;
F_66 ( & V_71 -> V_122 , V_119 ) ;
}
static void F_75 ( struct V_90 * V_90 )
{
struct V_10 * V_10 = F_44 ( V_90 ) ;
struct V_11 * V_71 = & V_10 -> V_71 ;
unsigned long V_119 ;
F_65 ( & V_71 -> V_122 , V_119 ) ;
F_28 () ;
F_66 ( & V_71 -> V_122 , V_119 ) ;
}
static bool F_76 ( struct V_10 * V_10 , int V_14 )
{
return ( V_14 >= 0 ) && ( V_14 < V_10 -> V_36 -> V_131 ) ;
}
static void F_77 ( struct V_74 * V_75 , int V_132 )
{
struct V_10 * V_10 = F_44 ( V_75 -> V_90 ) ;
struct V_11 * V_71 = & V_10 -> V_71 ;
struct V_105 * V_112 = & V_75 -> V_12 ;
int V_14 = V_112 -> V_14 ;
unsigned long V_119 ;
if ( V_132 & V_133 )
F_78 ( ! ( V_112 -> V_77 & V_134 ) ) ;
V_112 -> V_77 = 0 ;
if ( F_47 ( ! F_31 ( V_10 , V_14 ) ) ) {
F_48 ( & V_10 -> V_98 -> V_2 , L_8 , V_14 ) ;
return;
}
F_65 ( & V_71 -> V_122 , V_119 ) ;
if ( ! F_76 ( V_10 , V_14 ) )
F_39 ( V_10 , V_14 , V_112 -> V_91 ) ;
F_62 ( V_75 ) ;
F_37 ( V_10 , V_14 ) ;
F_66 ( & V_71 -> V_122 , V_119 ) ;
}
static void F_79 ( struct V_74 * V_75 , int V_132 )
{
struct V_10 * V_10 = F_44 ( V_75 -> V_90 ) ;
struct V_105 * V_112 = & V_75 -> V_12 ;
int V_14 = V_112 -> V_14 ;
if ( V_112 -> V_77 & V_78 )
return;
if ( F_47 ( ! F_31 ( V_10 , V_14 ) ) ) {
F_48 ( & V_10 -> V_98 -> V_2 , L_8 , V_14 ) ;
return;
}
F_36 ( V_10 , V_14 ) ;
F_58 ( V_75 ) ;
V_112 -> V_77 |= V_78 | V_134 ;
}
static int F_80 ( struct V_74 * V_75 , int V_119 )
{
struct V_10 * V_10 = F_44 ( V_75 -> V_90 ) ;
struct V_11 * V_71 = & V_10 -> V_71 ;
struct V_105 * V_112 = & V_75 -> V_12 ;
int V_14 ;
int V_101 = 0 ;
F_81 ( V_75 -> V_90 ) ;
V_14 = F_43 ( V_71 , V_75 ) ;
if ( V_14 < 0 ) {
V_101 = V_14 ;
goto V_135;
}
V_75 -> V_12 . V_14 = V_14 ;
V_71 -> V_76 [ V_14 ] = V_75 ;
V_112 -> V_77 = V_78 | V_134 ;
if ( V_119 & V_136 )
F_77 ( V_75 , V_133 ) ;
F_82 ( V_75 ) ;
V_135:
F_83 ( V_75 -> V_90 ) ;
return V_101 ;
}
static void F_84 ( struct V_74 * V_75 , int V_119 )
{
struct V_10 * V_10 = F_44 ( V_75 -> V_90 ) ;
struct V_11 * V_71 = & V_10 -> V_71 ;
struct V_105 * V_112 = & V_75 -> V_12 ;
int V_14 = V_112 -> V_14 ;
F_79 ( V_75 , V_137 ) ;
V_71 -> V_76 [ V_14 ] = NULL ;
F_85 ( V_14 , V_71 -> V_17 ) ;
F_82 ( V_75 ) ;
}
static int
F_86 ( struct V_90 * V_10 ,
struct V_11 * V_71 ,
struct V_74 * V_75 )
{
if ( F_87 ( V_75 ) )
return 1 ;
if ( V_75 -> V_90 != V_10 )
return 0 ;
if ( V_75 -> V_77 < V_138 )
return 1 ;
if ( V_75 -> V_77 == V_138 && ! V_75 -> V_4 . V_139 )
return 1 ;
return F_43 ( V_71 , V_75 ) >= 0 ;
}
static int
F_88 ( struct V_74 * V_75 )
{
struct V_74 * V_140 , * V_141 = V_75 -> V_142 ;
struct V_10 * V_10 = F_44 ( V_75 -> V_90 ) ;
unsigned long V_72 [ F_89 ( V_10 -> V_73 ) ] ;
struct V_11 V_143 = {
. V_17 = V_72 ,
} ;
memset ( V_72 , 0 , F_89 ( V_10 -> V_73 ) * sizeof( unsigned long ) ) ;
if ( ! F_86 ( V_75 -> V_90 , & V_143 , V_141 ) )
return - V_144 ;
F_90 (sibling, &leader->sibling_list, group_entry) {
if ( ! F_86 ( V_75 -> V_90 , & V_143 , V_140 ) )
return - V_144 ;
}
if ( ! F_86 ( V_75 -> V_90 , & V_143 , V_75 ) )
return - V_144 ;
return 0 ;
}
static int
F_91 ( struct V_74 * V_75 )
{
struct V_105 * V_112 = & V_75 -> V_12 ;
int V_145 ;
V_145 = F_45 ( V_75 ) ;
if ( V_145 < 0 ) {
F_92 ( L_9 , V_75 -> V_4 . type ,
V_75 -> V_4 . V_95 ) ;
return V_145 ;
}
V_112 -> V_14 = - 1 ;
V_112 -> V_91 = 0 ;
V_112 -> V_95 = 0 ;
V_112 -> V_146 = 0 ;
V_112 -> V_91 |= ( unsigned long ) V_145 ;
V_112 -> V_147 = V_116 >> 1 ;
V_112 -> V_148 = V_112 -> V_147 ;
F_63 ( & V_112 -> V_149 , V_112 -> V_147 ) ;
if ( V_75 -> V_142 != V_75 ) {
if ( F_88 ( V_75 ) != 0 )
return - V_144 ;
}
return 0 ;
}
static int F_93 ( struct V_74 * V_75 )
{
struct V_10 * V_10 = F_44 ( V_75 -> V_90 ) ;
T_8 * V_127 = & V_10 -> V_127 ;
int V_101 = 0 ;
int V_150 ;
if ( V_75 -> V_4 . type != V_75 -> V_90 -> type )
return - V_25 ;
if ( F_94 ( V_75 ) || V_75 -> V_151 & V_152 )
return - V_153 ;
if ( V_75 -> V_4 . V_154 ||
V_75 -> V_4 . V_155 ||
V_75 -> V_4 . V_156 ||
V_75 -> V_4 . V_157 ||
V_75 -> V_4 . V_158 ||
V_75 -> V_4 . V_159 )
return - V_144 ;
V_150 = F_95 ( & V_10 -> V_160 ) ;
if ( V_75 -> V_150 < 0 || V_150 < 0 )
return - V_144 ;
V_75 -> V_150 = V_150 ;
V_75 -> V_161 = F_70 ;
if ( ! F_96 ( V_127 ) ) {
F_97 ( & V_10 -> V_129 ) ;
if ( F_98 ( V_127 ) == 0 )
V_101 = F_68 ( V_10 ) ;
if ( ! V_101 )
F_99 ( V_127 ) ;
F_72 ( & V_10 -> V_129 ) ;
}
if ( V_101 )
return V_101 ;
V_101 = F_91 ( V_75 ) ;
if ( V_101 )
F_70 ( V_75 ) ;
return V_101 ;
}
static T_1 F_100 ( struct V_1 * V_2 ,
struct V_3 * V_4 , char * V_5 )
{
struct V_90 * V_90 = F_101 ( V_2 ) ;
struct V_10 * V_10 = F_44 ( V_90 ) ;
int V_162 = F_102 ( V_5 , V_8 - 1 , L_10 ,
F_103 ( & V_10 -> V_160 ) ) ;
V_5 [ V_162 ++ ] = '\n' ;
V_5 [ V_162 ] = '\0' ;
return V_162 ;
}
static int F_104 ( struct V_10 * V_10 , struct V_49 * V_50 )
{
const struct V_48 * V_36 = V_10 -> V_36 ;
char * V_163 = V_36 -> V_163 ;
T_3 V_73 ;
V_164 . V_165 = V_36 -> V_166 ;
V_167 . V_165 = V_36 -> V_168 ;
V_10 -> V_90 = (struct V_90 ) {
. V_163 = V_10 -> V_36 -> V_163 ,
. V_169 = V_170 ,
. V_171 = F_73 ,
. V_172 = F_75 ,
. V_173 = F_93 ,
. V_174 = F_80 ,
. V_175 = F_84 ,
. V_176 = F_77 ,
. V_177 = F_79 ,
. V_178 = F_61 ,
. V_179 = V_180 ,
} ;
V_10 -> V_98 = V_50 ;
V_73 = F_42 () ;
if ( V_73 > V_10 -> V_36 -> V_181 ) {
F_105 ( & V_50 -> V_2 ,
L_11
L_12 ,
V_73 , V_10 -> V_36 -> V_181 ) ;
V_73 = V_10 -> V_36 -> V_181 ;
}
V_10 -> V_73 = V_73 + V_10 -> V_36 -> V_131 ;
return F_106 ( & V_10 -> V_90 , V_163 , - 1 ) ;
}
static int F_107 ( unsigned int V_150 , struct V_182 * V_183 )
{
struct V_10 * V_10 = F_108 ( V_183 , struct V_10 , V_183 ) ;
unsigned int V_184 ;
if ( ! F_109 ( V_150 , & V_10 -> V_160 ) )
return 0 ;
V_184 = F_110 ( V_185 , V_150 ) ;
if ( V_184 >= V_186 )
return 0 ;
F_111 ( V_184 , & V_10 -> V_160 ) ;
return 0 ;
}
static inline const struct V_48 * F_112 ( struct V_49 * V_50 )
{
const struct V_187 * V_188 = F_113 ( V_189 ,
V_50 -> V_2 . V_190 ) ;
if ( ! V_188 )
return NULL ;
if ( V_188 -> V_191 )
return V_188 -> V_191 ;
F_105 ( & V_50 -> V_2 , L_13
L_14 ) ;
return F_11 ( V_50 ) ;
}
static bool F_114 ( int V_192 , int * V_102 , int V_100 )
{
int V_69 ;
for ( V_69 = 0 ; V_69 < V_100 ; V_69 ++ )
if ( V_192 == V_102 [ V_69 ] )
return true ;
return false ;
}
static struct V_10 * F_115 ( struct V_49 * V_50 )
{
struct V_10 * V_10 ;
const struct V_48 * V_36 ;
V_36 = F_112 ( V_50 ) ;
if ( ! V_36 ) {
F_105 ( & V_50 -> V_2 , L_15 ) ;
return F_116 ( - V_99 ) ;
}
V_10 = F_117 ( & V_50 -> V_2 , sizeof( * V_10 ) , V_193 ) ;
if ( ! V_10 )
return F_116 ( - V_194 ) ;
V_10 -> V_36 = V_36 ;
V_10 -> V_102 = F_118 ( & V_50 -> V_2 , F_119 ( V_36 ) ,
sizeof( * V_10 -> V_102 ) , V_193 ) ;
if ( ! V_10 -> V_102 )
return F_116 ( - V_194 ) ;
V_10 -> V_71 . V_76 = F_118 ( & V_50 -> V_2 ,
F_119 ( V_36 ) ,
sizeof( * V_10 -> V_71 . V_76 ) ,
V_193 ) ;
if ( ! V_10 -> V_71 . V_76 )
return F_116 ( - V_194 ) ;
V_10 -> V_71 . V_17 = F_118 ( & V_50 -> V_2 ,
F_89 ( F_119 ( V_36 ) ) ,
sizeof( * V_10 -> V_71 . V_17 ) ,
V_193 ) ;
if ( ! V_10 -> V_71 . V_17 )
return F_116 ( - V_194 ) ;
return V_10 ;
}
static int F_120 ( struct V_49 * V_50 )
{
struct V_195 * V_196 ;
struct V_10 * V_10 ;
int V_69 , V_126 , V_192 ;
V_10 = F_115 ( V_50 ) ;
if ( F_121 ( V_10 ) )
return F_122 ( V_10 ) ;
V_196 = F_123 ( V_50 , V_197 , 0 ) ;
V_10 -> V_84 = F_124 ( & V_50 -> V_2 , V_196 ) ;
if ( F_121 ( V_10 -> V_84 ) )
return - V_194 ;
V_10 -> V_100 = 0 ;
for ( V_69 = 0 ; V_69 < F_119 ( V_10 -> V_36 ) ; V_69 ++ ) {
V_192 = F_125 ( V_50 , V_69 ) ;
if ( V_192 < 0 )
break;
if ( F_114 ( V_192 , V_10 -> V_102 , V_10 -> V_100 ) )
continue;
V_10 -> V_102 [ V_10 -> V_100 ++ ] = V_192 ;
}
if ( V_69 < F_119 ( V_10 -> V_36 ) ) {
F_105 ( & V_50 -> V_2 , L_16 ,
V_69 , F_119 ( V_10 -> V_36 ) ) ;
return - V_144 ;
}
F_126 ( & V_10 -> V_71 . V_122 ) ;
F_127 ( & V_10 -> V_129 ) ;
F_128 ( & V_10 -> V_127 , 0 ) ;
F_111 ( F_129 () , & V_10 -> V_160 ) ;
V_126 = F_104 ( V_10 , V_50 ) ;
if ( V_126 )
return V_126 ;
F_130 ( V_198 ,
& V_10 -> V_183 ) ;
F_131 ( L_17 , V_10 -> V_36 -> V_163 ) ;
return 0 ;
}
static int F_132 ( struct V_49 * V_50 )
{
if ( ! F_133 () )
return - V_99 ;
return F_134 ( V_50 -> V_2 . V_190 , NULL , NULL , & V_50 -> V_2 ) ;
}
static int T_9 F_135 ( void )
{
int V_126 ;
V_126 = F_136 ( V_198 ,
L_18 , NULL ,
F_107 ) ;
if ( V_126 )
return V_126 ;
V_126 = F_137 ( & V_199 ) ;
if ( V_126 )
return V_126 ;
return F_137 ( & V_200 ) ;
}
static int T_9 F_135 ( void )
{
return 0 ;
}
static inline void F_138 ( struct V_201 * V_202 , T_3 V_203 , T_6 V_204 )
{
V_202 -> V_202 = V_205 | V_203 ;
V_202 -> V_204 = V_204 ;
}
static inline bool F_139 ( struct V_201 * V_202 )
{
return ! ! ( V_202 -> V_202 & V_205 ) ;
}
static inline bool F_140 ( struct V_201 * V_202 , T_6 V_204 )
{
return V_202 -> V_204 == ( V_204 & V_206 ) ;
}
static int F_141 ( struct V_207 * V_208 , int type )
{
int V_69 ;
bool V_209 ;
struct V_207 * V_210 ;
V_210 = F_142 ( V_208 , L_19 , 0 ) ;
for ( V_69 = 0 ; V_69 < V_211 ; V_69 ++ ) {
V_209 = V_212 [ V_69 ] . type == type ;
if ( V_209 && V_210 == V_212 [ V_69 ] . V_208 )
return V_69 ;
}
return - V_99 ;
}
int F_143 ( struct V_207 * V_208 )
{
return F_141 ( V_208 , V_213 ) ;
}
static void F_144 ( void )
{
int V_202 , V_150 ;
struct V_207 * V_214 ;
F_145 (cpu) {
V_214 = F_146 ( V_150 , NULL ) ;
if ( F_147 ( ! V_214 , L_20 ) )
continue;
V_202 = F_141 ( V_214 , V_215 ) ;
if ( V_202 < 0 )
continue;
F_138 ( & V_201 [ V_150 ] , V_202 , F_148 ( V_150 ) ) ;
}
F_145 (cpu) {
F_147 ( ! F_139 ( & V_201 [ V_150 ] ) ,
L_21 ,
V_150 ) ;
}
}
static void T_10 F_149 ( unsigned int V_202 , bool V_216 )
{
void T_11 * V_84 = V_212 [ V_202 ] . V_84 ;
F_35 ( V_216 ? V_217 : 0 , V_84 + V_218 ) ;
while ( F_10 ( V_41 + V_219 ) & 0x1 )
;
}
int T_10 F_150 ( T_6 V_204 )
{
int V_150 ;
bool V_220 ;
for ( V_150 = 0 ; V_150 < V_186 ; V_150 ++ ) {
V_220 = F_139 ( & V_201 [ V_150 ] ) ;
if ( V_220 && F_140 ( & V_201 [ V_150 ] , V_204 ) ) {
F_149 ( V_201 [ V_150 ] . V_202 , false ) ;
return 0 ;
}
}
return - V_99 ;
}
T_12 void T_13 F_151 ( void )
{
asm volatile ("\n"
" .arch armv7-a\n"
" mrc p15, 0, r0, c0, c0, 5 @ get MPIDR value \n"
" and r0, r0, #"__stringify(MPIDR_HWID_BITMASK)" \n"
" adr r1, 5f \n"
" ldr r2, [r1] \n"
" add r1, r1, r2 @ &cpu_port \n"
" add ip, r1, %[sizeof_cpu_port] \n"
"1: ldr r2, [r1, %[offsetof_cpu_port_mpidr_lsb]] \n"
" cmp r2, r0 @ compare MPIDR \n"
" bne 2f \n"
" ldr r3, [r1, %[offsetof_cpu_port_port]] \n"
" tst r3, #"__stringify(PORT_VALID)" \n"
" bne 3f \n"
"2: add r1, r1, %[sizeof_struct_cpu_port] \n"
" cmp r1, ip @ done? \n"
" blo 1b \n"
"cci_port_not_found: \n"
" wfi \n"
" wfe \n"
" b cci_port_not_found \n"
"3: bic r3, r3, #"__stringify(PORT_VALID)" \n"
" adr r0, 6f \n"
" ldmia r0, {r1, r2} \n"
" sub r1, r1, r0 @ virt - phys \n"
" ldr r0, [r0, r2] @ *(&ports) \n"
" mov r2, %[sizeof_struct_ace_port] \n"
" mla r0, r2, r3, r0 @ &ports[index] \n"
" sub r0, r0, r1 @ virt_to_phys() \n"
" ldr r0, [r0, %[offsetof_port_phys]] \n"
" mov r3, %[cci_enable_req]\n"
" str r3, [r0, #"__stringify(CCI_PORT_CTRL)"] \n"
" adr r1, 7f \n"
" ldr r0, [r1] \n"
" ldr r0, [r0, r1] @ cci_ctrl_base \n"
"4: ldr r1, [r0, #"__stringify(CCI_CTRL_STATUS)"] \n"
" tst r1, %[cci_control_status_bits] \n"
" bne 4b \n"
" mov r0, #0 \n"
" bx lr \n"
" .align 2 \n"
"5: .word cpu_port - . \n"
"6: .word . \n"
" .word ports - 6b \n"
"7: .word cci_ctrl_phys - . \n"
: :
[sizeof_cpu_port] "i" (sizeof(cpu_port)),
[cci_enable_req] "i" cpu_to_le32(CCI_ENABLE_REQ),
[cci_control_status_bits] "i" cpu_to_le32(1),
#ifndef F_152
[offsetof_cpu_port_mpidr_lsb] "i" (offsetof(struct cpu_port, mpidr)),
#else
[offsetof_cpu_port_mpidr_lsb] "i" (offsetof(struct cpu_port, mpidr)+4),
#endif
[offsetof_cpu_port_port] "i" (offsetof(struct cpu_port, port)),
[sizeof_struct_cpu_port] "i" (sizeof(struct cpu_port)),
[sizeof_struct_ace_port] "i" (sizeof(struct cci_ace_port)),
[offsetof_port_phys] "i" (offsetof(struct cci_ace_port, phys)) );
F_153 () ;
}
int T_10 F_154 ( struct V_207 * V_208 , bool V_216 )
{
int V_202 ;
if ( ! V_208 )
return - V_99 ;
V_202 = F_141 ( V_208 , V_213 ) ;
if ( F_155 ( V_202 < 0 , L_22 ,
V_208 -> V_221 ) )
return - V_99 ;
F_149 ( V_202 , V_216 ) ;
return 0 ;
}
int T_10 F_156 ( T_3 V_202 , bool V_216 )
{
if ( V_202 >= V_211 || V_212 [ V_202 ] . type == V_222 )
return - V_99 ;
if ( V_212 [ V_202 ] . type == V_215 )
return - V_223 ;
F_149 ( V_202 , V_216 ) ;
return 0 ;
}
static int F_157 ( struct V_207 * V_224 )
{
struct V_225 const * V_226 ;
int V_126 , V_69 , V_227 = 0 , V_228 = 0 ;
struct V_207 * V_229 ;
struct V_195 V_196 ;
const char * V_230 ;
bool V_231 ;
V_226 = F_113 ( V_232 , V_224 ) -> V_191 ;
if ( ! V_226 )
return - V_99 ;
V_211 = V_226 -> V_227 + V_226 -> V_228 ;
V_212 = F_158 ( V_211 , sizeof( * V_212 ) , V_193 ) ;
if ( ! V_212 )
return - V_194 ;
F_159 (np, cp) {
if ( ! F_113 ( V_233 , V_229 ) )
continue;
V_69 = V_227 + V_228 ;
if ( V_69 >= V_211 )
break;
if ( F_160 ( V_229 , L_23 ,
& V_230 ) ) {
F_147 ( 1 , L_24 ,
V_229 -> V_221 ) ;
continue;
}
V_231 = strcmp ( V_230 , L_25 ) == 0 ;
if ( ! V_231 && strcmp ( V_230 , L_26 ) ) {
F_147 ( 1 , L_27 ,
V_229 -> V_221 ) ;
continue;
}
V_126 = F_161 ( V_229 , 0 , & V_196 ) ;
if ( ! V_126 ) {
V_212 [ V_69 ] . V_84 = F_162 ( V_196 . V_176 , F_163 ( & V_196 ) ) ;
V_212 [ V_69 ] . V_234 = V_196 . V_176 ;
}
if ( V_126 || ! V_212 [ V_69 ] . V_84 ) {
F_147 ( 1 , L_28 , V_69 ) ;
continue;
}
if ( V_231 ) {
if ( F_22 ( V_227 >= V_226 -> V_227 ) )
continue;
V_212 [ V_69 ] . type = V_215 ;
++ V_227 ;
} else {
if ( F_22 ( V_228 >= V_226 -> V_228 ) )
continue;
V_212 [ V_69 ] . type = V_213 ;
++ V_228 ;
}
V_212 [ V_69 ] . V_208 = V_229 ;
}
F_144 () ;
F_164 ( & V_41 ) ;
F_164 ( & V_235 ) ;
F_164 ( & V_212 ) ;
F_164 ( & V_201 ) ;
F_165 ( V_212 , sizeof( * V_212 ) * V_211 ) ;
F_131 ( L_29 ) ;
return 0 ;
}
static inline int F_157 ( struct V_207 * V_224 )
{
return 0 ;
}
static int F_166 ( void )
{
int V_126 ;
struct V_207 * V_224 ;
struct V_195 V_196 ;
V_224 = F_167 ( NULL , V_232 ) ;
if( ! V_224 || ! F_168 ( V_224 ) )
return - V_99 ;
V_126 = F_161 ( V_224 , 0 , & V_196 ) ;
if ( ! V_126 ) {
V_41 = F_162 ( V_196 . V_176 , F_163 ( & V_196 ) ) ;
V_235 = V_196 . V_176 ;
}
if ( V_126 || ! V_41 ) {
F_147 ( 1 , L_30 ) ;
return - V_236 ;
}
return F_157 ( V_224 ) ;
}
static int F_169 ( void )
{
if ( V_237 != - V_18 )
return V_237 ;
F_97 ( & V_238 ) ;
if ( V_237 == - V_18 )
V_237 = F_166 () ;
F_72 ( & V_238 ) ;
return V_237 ;
}
bool F_133 ( void )
{
return F_169 () == 0 ;
}
