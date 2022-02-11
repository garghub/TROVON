static void F_1 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
F_2 ( F_3 ( V_4 -> V_5 ) , V_4 -> V_6 . V_7 >> 9 ,
& V_2 -> V_8 -> V_9 ) ;
}
static void F_4 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
F_5 ( F_3 ( V_4 -> V_5 ) ,
& V_2 -> V_8 -> V_9 , V_4 -> V_10 ) ;
}
static struct V_3 * F_6 ( struct V_1 * V_2 , struct V_11 * V_12 )
{
struct V_3 * V_4 ;
V_4 = F_7 ( V_13 , V_14 ) ;
if ( ! V_4 )
return NULL ;
memset ( V_4 , 0 , sizeof( * V_4 ) ) ;
F_8 ( V_4 , V_12 ) ;
V_4 -> V_15 = ( F_3 ( V_12 ) == V_16 ? V_17 : 0 )
| ( F_9 ( V_12 ) == V_18 ? V_19 : 0 )
| ( F_9 ( V_12 ) == V_20 ? V_21 : 0 ) ;
V_4 -> V_2 = V_2 ;
V_4 -> V_5 = V_12 ;
V_4 -> V_22 = 0 ;
F_10 ( & V_4 -> V_6 ) ;
V_4 -> V_6 . V_23 = V_12 -> V_24 . V_25 ;
V_4 -> V_6 . V_7 = V_12 -> V_24 . V_26 ;
V_4 -> V_6 . V_27 = true ;
V_4 -> V_6 . V_28 = false ;
F_11 ( & V_4 -> V_29 ) ;
F_11 ( & V_4 -> V_30 . V_31 ) ;
F_11 ( & V_4 -> V_32 ) ;
F_11 ( & V_4 -> V_33 ) ;
F_12 ( & V_4 -> V_34 , 1 ) ;
F_13 ( & V_4 -> V_35 ) ;
return V_4 ;
}
static void F_14 ( struct V_36 * V_37 ,
struct V_3 * V_4 )
{
struct V_1 * V_2 = V_4 -> V_2 ;
struct V_38 * V_6 = & V_4 -> V_6 ;
F_15 ( V_37 , V_6 ) ;
if ( V_6 -> V_28 )
F_16 ( & V_2 -> V_39 ) ;
}
void F_17 ( struct V_35 * V_35 )
{
struct V_3 * V_4 = F_18 ( V_35 , struct V_3 , V_35 ) ;
struct V_1 * V_2 = V_4 -> V_2 ;
const unsigned V_40 = V_4 -> V_15 ;
if ( ( V_4 -> V_5 && ! ( V_40 & V_41 ) ) ||
F_19 ( & V_4 -> V_34 ) ||
( V_40 & V_42 ) ||
( ( V_40 & V_43 ) && ! ( V_40 & V_44 ) ) ) {
F_20 ( V_2 , L_1 ,
V_40 , F_19 ( & V_4 -> V_34 ) ) ;
return;
}
F_21 ( & V_4 -> V_29 ) ;
if ( ! F_22 ( & V_4 -> V_6 ) ) {
struct V_36 * V_37 ;
if ( V_40 & V_17 )
V_37 = & V_2 -> V_45 ;
else
V_37 = & V_2 -> V_46 ;
F_14 ( V_37 , V_4 ) ;
} else if ( V_40 & ( V_43 & ~ V_44 ) && V_4 -> V_6 . V_7 != 0 )
F_20 ( V_2 , L_2 ,
V_40 , ( unsigned long long ) V_4 -> V_6 . V_23 , V_4 -> V_6 . V_7 ) ;
if ( V_40 & V_17 ) {
if ( ( V_40 & ( V_41 | V_47 | V_43 ) ) != V_41 ) {
if ( ! ( V_40 & V_48 ) || ! ( V_40 & V_49 ) )
F_23 ( V_2 , V_4 -> V_6 . V_23 , V_4 -> V_6 . V_7 ) ;
if ( ( V_40 & V_48 ) && ( V_40 & V_49 ) && ( V_40 & V_50 ) )
F_24 ( V_2 , V_4 -> V_6 . V_23 , V_4 -> V_6 . V_7 ) ;
}
if ( V_40 & V_51 ) {
if ( F_25 ( V_2 , V_52 ) ) {
F_26 ( V_2 , & V_4 -> V_6 ) ;
F_27 ( V_2 ) ;
} else if ( F_28 ( & V_53 ) ) {
F_29 ( V_2 , L_3
L_4 ,
( unsigned long long ) V_4 -> V_6 . V_23 , V_4 -> V_6 . V_7 ) ;
}
}
}
F_30 ( V_4 , V_13 ) ;
}
static void F_31 ( struct V_54 * V_55 )
{
F_16 ( & V_55 -> V_56 . V_57 ) ;
}
void F_32 ( struct V_54 * V_55 )
{
if ( V_55 -> V_58 == 0 )
return;
V_55 -> V_58 = 0 ;
F_33 ( & V_55 -> V_59 ) ;
F_31 ( V_55 ) ;
}
void F_34 ( struct V_1 * V_2 ,
struct V_60 * V_61 )
{
V_61 -> V_11 -> V_62 = V_61 -> error ;
F_35 ( V_61 -> V_11 ) ;
F_36 ( V_2 ) ;
}
static
void F_37 ( struct V_3 * V_4 , struct V_60 * V_61 )
{
const unsigned V_40 = V_4 -> V_15 ;
struct V_1 * V_2 = V_4 -> V_2 ;
int error , V_63 ;
if ( ( V_40 & V_42 && ! ( V_40 & V_64 ) ) ||
( V_40 & V_65 ) || ( V_40 & V_66 ) ||
( V_40 & V_67 ) ) {
F_20 ( V_2 , L_5 , V_40 ) ;
return;
}
if ( ! V_4 -> V_5 ) {
F_20 ( V_2 , L_6 ) ;
return;
}
V_63 = ( V_40 & V_49 ) || ( V_40 & V_48 ) ;
error = F_38 ( V_4 -> V_68 ) ;
if ( F_39 ( F_9 ( V_4 -> V_5 ) ) &&
V_4 -> V_22 == F_19 ( & F_40 ( V_2 ) -> V_55 -> V_59 ) )
F_32 ( F_40 ( V_2 ) -> V_55 ) ;
F_4 ( V_2 , V_4 ) ;
if ( ! V_63 &&
F_9 ( V_4 -> V_5 ) == V_69 &&
! ( V_4 -> V_5 -> V_70 & V_71 ) &&
! F_41 ( & V_4 -> V_29 ) )
V_4 -> V_15 |= V_41 ;
if ( ! ( V_4 -> V_15 & V_41 ) ) {
V_61 -> error = V_63 ? 0 : ( error ? : - V_72 ) ;
V_61 -> V_11 = V_4 -> V_5 ;
V_4 -> V_5 = NULL ;
V_4 -> V_6 . V_73 = true ;
}
if ( V_4 -> V_6 . V_28 )
F_16 ( & V_2 -> V_39 ) ;
F_21 ( & V_4 -> V_32 ) ;
}
static int F_42 ( struct V_3 * V_4 , struct V_60 * V_61 , int V_74 )
{
struct V_1 * V_2 = V_4 -> V_2 ;
F_43 ( V_2 , V_61 || ( V_4 -> V_15 & V_41 ) ) ;
if ( ! F_44 ( V_74 , & V_4 -> V_34 ) )
return 0 ;
F_37 ( V_4 , V_61 ) ;
if ( V_4 -> V_15 & V_41 ) {
F_45 ( V_4 ) ;
return 0 ;
}
return 1 ;
}
static void F_46 ( struct V_75 * V_76 , struct V_3 * V_4 )
{
struct V_54 * V_55 = V_76 ? V_76 -> V_55 : NULL ;
if ( ! V_55 )
return;
if ( V_55 -> V_77 == NULL )
V_55 -> V_77 = V_4 ;
}
static void F_47 ( struct V_75 * V_76 , struct V_3 * V_4 )
{
struct V_54 * V_55 = V_76 ? V_76 -> V_55 : NULL ;
if ( ! V_55 )
return;
if ( V_55 -> V_77 != V_4 )
return;
F_48 (req, &connection->transfer_log, tl_requests) {
const unsigned V_40 = V_4 -> V_15 ;
if ( V_40 & V_65 )
break;
}
if ( & V_4 -> V_29 == & V_55 -> V_78 )
V_4 = NULL ;
V_55 -> V_77 = V_4 ;
}
static void F_49 ( struct V_75 * V_76 , struct V_3 * V_4 )
{
struct V_54 * V_55 = V_76 ? V_76 -> V_55 : NULL ;
if ( ! V_55 )
return;
if ( V_55 -> V_79 == NULL )
V_55 -> V_79 = V_4 ;
}
static void F_50 ( struct V_75 * V_76 , struct V_3 * V_4 )
{
struct V_54 * V_55 = V_76 ? V_76 -> V_55 : NULL ;
if ( ! V_55 )
return;
if ( V_55 -> V_79 != V_4 )
return;
F_48 (req, &connection->transfer_log, tl_requests) {
const unsigned V_40 = V_4 -> V_15 ;
if ( ( V_40 & V_80 ) && ( V_40 & V_66 ) )
break;
}
if ( & V_4 -> V_29 == & V_55 -> V_78 )
V_4 = NULL ;
V_55 -> V_79 = V_4 ;
}
static void F_51 ( struct V_75 * V_76 , struct V_3 * V_4 )
{
struct V_54 * V_55 = V_76 ? V_76 -> V_55 : NULL ;
if ( ! V_55 )
return;
if ( V_55 -> V_81 == NULL )
V_55 -> V_81 = V_4 ;
}
static void F_52 ( struct V_75 * V_76 , struct V_3 * V_4 )
{
struct V_54 * V_55 = V_76 ? V_76 -> V_55 : NULL ;
if ( ! V_55 )
return;
if ( V_55 -> V_81 != V_4 )
return;
F_48 (req, &connection->transfer_log, tl_requests) {
const unsigned V_40 = V_4 -> V_15 ;
if ( ( V_40 & V_80 ) && ! ( V_40 & V_44 ) )
break;
}
if ( & V_4 -> V_29 == & V_55 -> V_78 )
V_4 = NULL ;
V_55 -> V_81 = V_4 ;
}
static void F_53 ( struct V_3 * V_4 , struct V_60 * V_61 ,
int V_82 , int V_83 )
{
struct V_1 * V_2 = V_4 -> V_2 ;
struct V_75 * V_76 = F_40 ( V_2 ) ;
unsigned V_40 = V_4 -> V_15 ;
int V_84 = 0 ;
int V_85 = 0 ;
if ( F_54 ( V_2 ) && ! ( ( V_40 | V_82 ) & V_67 ) )
V_83 |= V_67 ;
V_4 -> V_15 &= ~ V_82 ;
V_4 -> V_15 |= V_83 ;
if ( V_4 -> V_15 == V_40 )
return;
if ( ! ( V_40 & V_42 ) && ( V_83 & V_42 ) )
F_33 ( & V_4 -> V_34 ) ;
if ( ! ( V_40 & V_66 ) && ( V_83 & V_66 ) ) {
F_55 ( V_2 ) ;
F_33 ( & V_4 -> V_34 ) ;
}
if ( ! ( V_40 & V_65 ) && ( V_83 & V_65 ) ) {
F_33 ( & V_4 -> V_34 ) ;
F_46 ( V_76 , V_4 ) ;
}
if ( ! ( V_40 & V_86 ) && ( V_83 & V_86 ) )
F_56 ( & V_4 -> V_35 ) ;
if ( ! ( V_40 & V_80 ) && ( V_83 & V_80 ) ) {
if ( ! ( V_40 & V_44 ) ) {
F_57 ( V_4 -> V_6 . V_7 >> 9 , & V_2 -> V_87 ) ;
F_51 ( V_76 , V_4 ) ;
}
if ( V_4 -> V_15 & V_66 )
F_49 ( V_76 , V_4 ) ;
}
if ( ! ( V_40 & V_67 ) && ( V_83 & V_67 ) )
F_33 ( & V_4 -> V_34 ) ;
if ( ( V_40 & V_67 ) && ( V_82 & V_67 ) )
++ V_84 ;
if ( ! ( V_40 & V_64 ) && ( V_83 & V_64 ) ) {
F_43 ( V_2 , V_4 -> V_15 & V_42 ) ;
F_56 ( & V_4 -> V_35 ) ;
++ V_84 ;
}
if ( ( V_40 & V_42 ) && ( V_82 & V_42 ) ) {
if ( V_4 -> V_15 & V_64 )
++ V_85 ;
else
++ V_84 ;
F_21 ( & V_4 -> V_33 ) ;
}
if ( ( V_40 & V_66 ) && ( V_82 & V_66 ) ) {
F_58 ( V_2 ) ;
++ V_84 ;
V_4 -> V_88 = V_89 ;
F_50 ( V_76 , V_4 ) ;
}
if ( ( V_40 & V_65 ) && ( V_82 & V_65 ) ) {
++ V_84 ;
F_47 ( V_76 , V_4 ) ;
}
if ( ! ( V_40 & V_44 ) && ( V_83 & V_44 ) ) {
if ( V_40 & V_80 )
F_59 ( V_4 -> V_6 . V_7 >> 9 , & V_2 -> V_87 ) ;
if ( V_40 & V_86 )
++ V_85 ;
V_4 -> V_90 = V_89 ;
F_47 ( V_76 , V_4 ) ;
F_50 ( V_76 , V_4 ) ;
F_52 ( V_76 , V_4 ) ;
}
if ( V_85 || V_84 ) {
int V_91 = V_85 + ! ! V_84 ;
int V_92 = F_19 ( & V_4 -> V_35 . V_92 ) ;
if ( V_92 < V_91 )
F_20 ( V_2 ,
L_7 ,
V_40 , V_4 -> V_15 , V_92 , V_91 ) ;
}
if ( V_4 -> V_6 . V_28 )
F_16 ( & V_2 -> V_39 ) ;
if ( V_84 )
V_85 += F_42 ( V_4 , V_61 , V_84 ) ;
if ( V_85 )
F_60 ( & V_4 -> V_35 , V_85 , F_17 ) ;
}
static void F_61 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
char V_93 [ V_94 ] ;
if ( ! F_28 ( & V_53 ) )
return;
F_29 ( V_2 , L_8 ,
( V_4 -> V_15 & V_17 ) ? L_9 : L_10 ,
( unsigned long long ) V_4 -> V_6 . V_23 ,
V_4 -> V_6 . V_7 >> 9 ,
F_62 ( V_2 -> V_95 -> V_96 , V_93 ) ) ;
}
static inline bool F_63 ( struct V_3 * V_4 )
{
return ( V_4 -> V_15 &
( V_17 | V_66 | V_97 | V_98 ) )
== ( V_17 | V_66 ) ;
}
int F_64 ( struct V_3 * V_4 , enum V_99 V_100 ,
struct V_60 * V_61 )
{
struct V_1 * const V_2 = V_4 -> V_2 ;
struct V_75 * const V_76 = F_40 ( V_2 ) ;
struct V_54 * const V_55 = V_76 ? V_76 -> V_55 : NULL ;
struct V_101 * V_102 ;
int V_103 , V_104 = 0 ;
if ( V_61 )
V_61 -> V_11 = NULL ;
switch ( V_100 ) {
default:
F_20 ( V_2 , L_11 , __FILE__ , __LINE__ ) ;
break;
case V_105 :
F_43 ( V_2 , ! ( V_4 -> V_15 & V_43 ) ) ;
F_65 () ;
V_102 = F_66 ( V_55 -> V_101 ) ;
V_103 = V_102 -> V_106 ;
F_67 () ;
V_4 -> V_15 |=
V_103 == V_107 ? V_97 :
V_103 == V_108 ? V_98 : 0 ;
F_53 ( V_4 , V_61 , 0 , V_66 ) ;
break;
case V_109 :
F_43 ( V_2 , ! ( V_4 -> V_15 & V_47 ) ) ;
F_53 ( V_4 , V_61 , 0 , V_42 ) ;
break;
case V_110 :
if ( V_4 -> V_15 & V_17 )
V_2 -> V_111 += V_4 -> V_6 . V_7 >> 9 ;
else
V_2 -> V_112 += V_4 -> V_6 . V_7 >> 9 ;
F_53 ( V_4 , V_61 , V_42 ,
V_113 | V_49 ) ;
break;
case V_114 :
F_53 ( V_4 , V_61 , 0 , V_64 ) ;
break;
case V_115 :
F_61 ( V_2 , V_4 ) ;
F_68 ( V_2 , V_116 ) ;
F_53 ( V_4 , V_61 , V_42 , V_113 ) ;
break;
case V_117 :
F_23 ( V_2 , V_4 -> V_6 . V_23 , V_4 -> V_6 . V_7 ) ;
F_61 ( V_2 , V_4 ) ;
F_68 ( V_2 , V_118 ) ;
case V_119 :
F_53 ( V_4 , V_61 , V_42 , V_113 ) ;
break;
case V_120 :
case V_121 :
F_53 ( V_4 , V_61 , V_42 , V_113 ) ;
break;
case V_122 :
F_43 ( V_2 , F_22 ( & V_4 -> V_6 ) ) ;
F_69 ( & V_2 -> V_46 , & V_4 -> V_6 ) ;
F_70 ( V_123 , & V_2 -> V_124 ) ;
F_43 ( V_2 , V_4 -> V_15 & V_66 ) ;
F_43 ( V_2 , ( V_4 -> V_15 & V_47 ) == 0 ) ;
F_53 ( V_4 , V_61 , 0 , V_65 ) ;
V_4 -> V_30 . V_125 = V_126 ;
F_71 ( & V_55 -> V_56 ,
& V_4 -> V_30 ) ;
break;
case V_127 :
F_43 ( V_2 , F_22 ( & V_4 -> V_6 ) ) ;
F_69 ( & V_2 -> V_45 , & V_4 -> V_6 ) ;
F_70 ( V_123 , & V_2 -> V_124 ) ;
F_43 ( V_2 , V_4 -> V_15 & V_66 ) ;
F_53 ( V_4 , V_61 , 0 , V_65 | V_86 ) ;
V_4 -> V_30 . V_125 = V_128 ;
F_71 ( & V_55 -> V_56 ,
& V_4 -> V_30 ) ;
F_65 () ;
V_102 = F_66 ( V_55 -> V_101 ) ;
V_103 = V_102 -> V_129 ;
F_67 () ;
if ( V_55 -> V_58 >= V_103 )
F_32 ( V_55 ) ;
break;
case V_130 :
F_53 ( V_4 , V_61 , 0 , V_65 ) ;
V_4 -> V_30 . V_125 = V_131 ;
F_71 ( & V_55 -> V_56 ,
& V_4 -> V_30 ) ;
break;
case V_132 :
case V_133 :
case V_134 :
F_53 ( V_4 , V_61 , V_65 , 0 ) ;
break;
case V_135 :
if ( F_63 ( V_4 ) )
F_53 ( V_4 , V_61 , V_65 | V_66 ,
V_80 | V_48 ) ;
else
F_53 ( V_4 , V_61 , V_65 , V_80 ) ;
break;
case V_136 :
F_53 ( V_4 , V_61 , V_65 , V_44 ) ;
break;
case V_137 :
F_53 ( V_4 , V_61 ,
V_48 | V_66 | V_67 ,
V_44 ) ;
break;
case V_138 :
F_43 ( V_2 , V_4 -> V_15 & V_66 ) ;
F_43 ( V_2 , V_4 -> V_15 & V_97 ) ;
F_53 ( V_4 , V_61 , V_66 , V_44 | V_48 ) ;
break;
case V_139 :
V_4 -> V_15 |= V_50 ;
case V_140 :
goto V_141;
case V_142 :
F_43 ( V_2 , V_4 -> V_15 & V_98 ) ;
V_141:
F_53 ( V_4 , V_61 , V_66 , V_48 ) ;
break;
case V_143 :
F_43 ( V_2 , V_4 -> V_15 & V_97 ) ;
F_43 ( V_2 , V_4 -> V_15 & V_66 ) ;
V_4 -> V_15 |= V_41 ;
if ( V_4 -> V_6 . V_28 )
F_16 ( & V_2 -> V_39 ) ;
break;
case V_144 :
F_53 ( V_4 , V_61 , V_48 | V_66 , 0 ) ;
break;
case V_145 :
if ( ! ( V_4 -> V_15 & V_113 ) )
break;
F_53 ( V_4 , V_61 , V_67 , 0 ) ;
break;
case V_146 :
if ( ! ( V_4 -> V_15 & V_113 ) )
break;
F_53 ( V_4 , V_61 ,
V_67 | V_113 ,
V_42 ) ;
V_104 = V_147 ;
if ( F_3 ( V_4 -> V_5 ) == V_16 )
V_104 = V_148 ;
F_72 ( V_2 ) ;
V_4 -> V_30 . V_125 = V_149 ;
F_71 ( & V_55 -> V_56 ,
& V_4 -> V_30 ) ;
break;
case V_150 :
if ( ! ( V_4 -> V_15 & V_17 ) && ! V_4 -> V_30 . V_125 ) {
F_53 ( V_4 , V_61 , V_67 , 0 ) ;
break;
}
if ( ! ( V_4 -> V_15 & V_48 ) ) {
F_53 ( V_4 , V_61 , V_67 , V_65 | V_66 ) ;
if ( V_4 -> V_30 . V_125 ) {
F_71 ( & V_55 -> V_56 ,
& V_4 -> V_30 ) ;
V_104 = V_4 -> V_15 & V_17 ? V_148 : V_147 ;
}
break;
}
case V_151 :
if ( ! ( V_4 -> V_15 & V_17 ) )
break;
if ( V_4 -> V_15 & V_66 ) {
F_20 ( V_2 , L_12 ) ;
}
F_53 ( V_4 , V_61 , V_67 ,
( V_4 -> V_15 & V_43 ) ? V_44 : 0 ) ;
break;
case V_152 :
F_43 ( V_2 , V_4 -> V_15 & V_66 ) ;
F_53 ( V_4 , V_61 , V_66 , V_48 | V_44 ) ;
break;
case V_153 :
F_32 ( V_55 ) ;
F_53 ( V_4 , V_61 , 0 , V_48 | V_44 ) ;
break;
} ;
return V_104 ;
}
static bool F_73 ( struct V_1 * V_2 , T_1 V_23 , int V_7 )
{
unsigned long V_154 , V_155 ;
T_1 V_156 , V_157 ;
if ( V_2 -> V_158 . V_159 == V_160 )
return true ;
if ( V_2 -> V_158 . V_159 != V_161 )
return false ;
V_156 = V_23 + ( V_7 >> 9 ) - 1 ;
V_157 = F_74 ( V_2 -> V_162 ) ;
F_43 ( V_2 , V_23 < V_157 ) ;
F_43 ( V_2 , V_156 < V_157 ) ;
V_154 = F_75 ( V_23 ) ;
V_155 = F_75 ( V_156 ) ;
return F_76 ( V_2 , V_154 , V_155 ) == 0 ;
}
static bool F_77 ( struct V_1 * V_2 , T_1 V_23 ,
enum V_163 V_164 )
{
struct V_165 * V_166 ;
int V_167 ;
switch ( V_164 ) {
case V_168 :
V_166 = & V_2 -> V_95 -> V_96 -> V_169 -> V_170 -> V_165 ;
return F_78 ( V_166 ) ;
case V_171 :
return F_19 ( & V_2 -> V_172 ) >
F_19 ( & V_2 -> V_173 ) + F_19 ( & V_2 -> V_174 ) ;
case V_175 :
case V_176 :
case V_177 :
case V_178 :
case V_179 :
case V_180 :
V_167 = ( V_164 - V_175 + 15 ) ;
return ( V_23 >> ( V_167 - 9 ) ) & 1 ;
case V_181 :
return F_79 ( V_182 , & V_2 -> V_124 ) ;
case V_183 :
return true ;
case V_184 :
default:
return false ;
}
}
static void F_80 ( struct V_3 * V_4 )
{
F_81 ( V_185 ) ;
struct V_1 * V_2 = V_4 -> V_2 ;
struct V_38 * V_6 ;
T_1 V_23 = V_4 -> V_6 . V_23 ;
int V_7 = V_4 -> V_6 . V_7 ;
for (; ; ) {
F_82 (i, &device->write_requests, sector, size) {
if ( V_6 -> V_73 )
continue;
break;
}
if ( ! V_6 )
break;
F_83 ( & V_2 -> V_39 , & V_185 , V_186 ) ;
V_6 -> V_28 = true ;
F_84 ( & V_2 -> V_187 -> V_188 ) ;
F_85 () ;
F_86 ( & V_2 -> V_187 -> V_188 ) ;
}
F_87 ( & V_2 -> V_39 , & V_185 ) ;
}
static void F_88 ( struct V_1 * V_2 )
{
struct V_54 * V_55 = F_40 ( V_2 ) -> V_55 ;
struct V_101 * V_102 ;
bool V_189 = false ;
enum V_190 V_191 ;
F_65 () ;
V_102 = F_66 ( V_55 -> V_101 ) ;
V_191 = V_102 ? V_102 -> V_191 : V_192 ;
F_67 () ;
if ( V_191 == V_192 ||
V_55 -> V_193 < 96 )
return;
if ( V_191 == V_194 && V_2 -> V_158 . V_195 == V_196 )
return;
if ( ! F_25 ( V_2 , V_160 ) )
return;
if ( V_102 -> V_197 &&
F_19 ( & V_2 -> V_87 ) >= V_102 -> V_197 ) {
F_89 ( V_2 , L_13 ) ;
V_189 = true ;
}
if ( V_2 -> V_198 -> V_199 >= V_102 -> V_200 ) {
F_89 ( V_2 , L_14 ) ;
V_189 = true ;
}
if ( V_189 ) {
F_32 ( F_40 ( V_2 ) -> V_55 ) ;
if ( V_191 == V_194 )
F_90 ( F_91 ( V_2 , V_195 , V_196 ) , 0 , NULL ) ;
else
F_90 ( F_91 ( V_2 , V_195 , V_201 ) , 0 , NULL ) ;
}
F_27 ( V_2 ) ;
}
static bool F_92 ( struct V_3 * V_4 )
{
struct V_1 * V_2 = V_4 -> V_2 ;
enum V_163 V_164 ;
if ( V_4 -> V_68 ) {
if ( ! F_73 ( V_2 ,
V_4 -> V_6 . V_23 , V_4 -> V_6 . V_7 ) ) {
F_93 ( V_4 -> V_68 ) ;
V_4 -> V_68 = NULL ;
F_27 ( V_2 ) ;
}
}
if ( V_2 -> V_158 . V_202 != V_160 )
return false ;
if ( V_4 -> V_68 == NULL )
return true ;
F_65 () ;
V_164 = F_66 ( V_2 -> V_95 -> V_203 ) -> V_204 ;
F_67 () ;
if ( V_164 == V_184 && V_4 -> V_68 )
return false ;
if ( F_77 ( V_2 , V_4 -> V_6 . V_23 , V_164 ) ) {
if ( V_4 -> V_68 ) {
F_93 ( V_4 -> V_68 ) ;
V_4 -> V_68 = NULL ;
F_27 ( V_2 ) ;
}
return true ;
}
return false ;
}
bool F_94 ( union V_205 V_40 )
{
return V_40 . V_202 == V_160 ||
( V_40 . V_202 >= V_161 &&
V_40 . V_195 >= V_206 &&
V_40 . V_195 < V_196 ) ;
}
static bool F_95 ( union V_205 V_40 )
{
return V_40 . V_195 == V_196 || V_40 . V_195 == V_207 ;
}
static int F_96 ( struct V_3 * V_4 )
{
struct V_1 * V_2 = V_4 -> V_2 ;
int V_208 , V_209 ;
V_208 = F_94 ( V_2 -> V_158 ) ;
V_209 = F_95 ( V_2 -> V_158 ) ;
if ( F_97 ( V_4 -> V_6 . V_7 == 0 ) ) {
F_43 ( V_2 , V_4 -> V_5 -> V_70 & V_210 ) ;
if ( V_208 )
F_98 ( V_4 , V_153 ) ;
return V_208 ;
}
if ( ! V_208 && ! V_209 )
return 0 ;
F_43 ( V_2 , ! ( V_208 && V_209 ) ) ;
if ( V_208 ) {
F_98 ( V_4 , V_105 ) ;
F_98 ( V_4 , V_127 ) ;
} else if ( F_23 ( V_2 , V_4 -> V_6 . V_23 , V_4 -> V_6 . V_7 ) )
F_98 ( V_4 , V_130 ) ;
return V_208 ;
}
static void F_99 ( struct V_3 * V_4 )
{
int V_211 = F_100 ( V_4 -> V_2 ,
V_4 -> V_6 . V_23 , V_4 -> V_6 . V_7 >> 9 , true ) ;
if ( V_211 )
V_4 -> V_68 -> V_62 = - V_72 ;
F_35 ( V_4 -> V_68 ) ;
}
static void
F_101 ( struct V_3 * V_4 )
{
struct V_1 * V_2 = V_4 -> V_2 ;
struct V_11 * V_11 = V_4 -> V_68 ;
unsigned int type ;
if ( F_9 ( V_11 ) != V_69 )
type = V_212 ;
else if ( V_11 -> V_70 & V_71 )
type = V_213 ;
else
type = V_214 ;
V_11 -> V_215 = V_2 -> V_95 -> V_96 ;
if ( F_72 ( V_2 ) ) {
if ( F_102 ( V_2 , type ) )
F_103 ( V_11 ) ;
else if ( F_9 ( V_11 ) == V_20 )
F_99 ( V_4 ) ;
else
F_104 ( V_11 ) ;
F_27 ( V_2 ) ;
} else
F_103 ( V_11 ) ;
}
static void F_105 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
F_86 ( & V_2 -> V_187 -> V_188 ) ;
F_106 ( & V_4 -> V_29 , & V_2 -> V_216 . V_217 ) ;
F_106 ( & V_4 -> V_32 ,
& V_2 -> V_218 [ 1 ] ) ;
F_84 ( & V_2 -> V_187 -> V_188 ) ;
F_107 ( V_2 -> V_216 . V_219 , & V_2 -> V_216 . V_220 ) ;
F_16 ( & V_2 -> V_221 ) ;
}
static struct V_3 *
F_108 ( struct V_1 * V_2 , struct V_11 * V_11 , unsigned long V_10 )
{
const int V_222 = F_3 ( V_11 ) ;
struct V_3 * V_4 ;
V_4 = F_6 ( V_2 , V_11 ) ;
if ( ! V_4 ) {
F_36 ( V_2 ) ;
F_20 ( V_2 , L_15 ) ;
V_11 -> V_62 = - V_223 ;
F_35 ( V_11 ) ;
return F_109 ( - V_223 ) ;
}
V_4 -> V_10 = V_10 ;
if ( ! F_72 ( V_2 ) ) {
F_93 ( V_4 -> V_68 ) ;
V_4 -> V_68 = NULL ;
}
F_1 ( V_2 , V_4 ) ;
if ( F_9 ( V_11 ) & V_20 )
goto V_224;
if ( V_222 == V_16 && V_4 -> V_68 && V_4 -> V_6 . V_7
&& ! F_110 ( V_225 , & V_2 -> V_124 ) ) {
if ( ! F_111 ( V_2 , & V_4 -> V_6 ) )
goto V_224;
V_4 -> V_15 |= V_51 ;
V_4 -> V_226 = V_89 ;
}
return V_4 ;
V_224:
F_33 ( & V_2 -> V_227 ) ;
F_105 ( V_2 , V_4 ) ;
return NULL ;
}
static bool F_112 ( struct V_1 * V_2 )
{
const union V_205 V_40 = V_2 -> V_158 ;
return V_40 . V_159 == V_160 || V_40 . V_202 == V_160 ;
}
static void F_113 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_228 * V_187 = V_2 -> V_187 ;
const int V_222 = F_3 ( V_4 -> V_5 ) ;
struct V_60 V_61 = { NULL , } ;
bool V_229 = false ;
bool V_230 = false ;
F_86 ( & V_187 -> V_188 ) ;
if ( V_222 == V_16 ) {
F_80 ( V_4 ) ;
F_88 ( V_2 ) ;
}
if ( F_54 ( V_2 ) ) {
V_4 -> V_15 |= V_41 ;
if ( V_4 -> V_68 ) {
F_93 ( V_4 -> V_68 ) ;
V_4 -> V_68 = NULL ;
F_27 ( V_2 ) ;
}
goto V_231;
}
if ( V_222 != V_16 ) {
if ( ! F_92 ( V_4 ) && ! V_4 -> V_68 )
goto V_232;
}
V_4 -> V_22 = F_19 ( & F_40 ( V_2 ) -> V_55 -> V_59 ) ;
if ( F_114 ( V_4 -> V_6 . V_7 != 0 ) ) {
if ( V_222 == V_16 )
F_40 ( V_2 ) -> V_55 -> V_58 ++ ;
F_106 ( & V_4 -> V_29 , & F_40 ( V_2 ) -> V_55 -> V_78 ) ;
}
if ( V_222 == V_16 ) {
if ( V_4 -> V_68 && ! F_112 ( V_2 ) ) {
F_93 ( V_4 -> V_68 ) ;
V_4 -> V_68 = NULL ;
F_27 ( V_2 ) ;
goto V_232;
}
if ( ! F_96 ( V_4 ) )
V_229 = true ;
} else {
if ( V_4 -> V_68 == NULL ) {
F_98 ( V_4 , V_105 ) ;
F_98 ( V_4 , V_122 ) ;
} else
V_229 = true ;
}
if ( F_41 ( & V_4 -> V_32 ) )
F_106 ( & V_4 -> V_32 ,
& V_2 -> V_218 [ V_222 == V_16 ] ) ;
if ( V_4 -> V_68 ) {
V_4 -> V_233 = V_89 ;
F_106 ( & V_4 -> V_33 ,
& V_2 -> V_234 [ V_222 == V_16 ] ) ;
F_98 ( V_4 , V_109 ) ;
V_230 = true ;
} else if ( V_229 ) {
V_232:
if ( F_28 ( & V_53 ) )
F_20 ( V_2 , L_16 ,
( unsigned long long ) V_4 -> V_6 . V_23 , V_4 -> V_6 . V_7 >> 9 ) ;
}
V_231:
if ( F_42 ( V_4 , & V_61 , 1 ) )
F_115 ( & V_4 -> V_35 , F_17 ) ;
F_84 ( & V_187 -> V_188 ) ;
if ( V_230 )
F_101 ( V_4 ) ;
if ( V_61 . V_11 )
F_34 ( V_2 , & V_61 ) ;
}
void F_116 ( struct V_1 * V_2 , struct V_11 * V_11 , unsigned long V_10 )
{
struct V_3 * V_4 = F_108 ( V_2 , V_11 , V_10 ) ;
if ( F_117 ( V_4 ) )
return;
F_113 ( V_2 , V_4 ) ;
}
static void F_118 ( struct V_1 * V_2 , struct V_235 * V_236 )
{
struct V_3 * V_4 , * V_237 ;
F_119 (req, tmp, incoming, tl_requests) {
const int V_222 = F_3 ( V_4 -> V_5 ) ;
if ( V_222 == V_16
&& V_4 -> V_68 && V_4 -> V_6 . V_7
&& ! F_110 ( V_225 , & V_2 -> V_124 ) ) {
if ( ! F_111 ( V_2 , & V_4 -> V_6 ) )
continue;
V_4 -> V_15 |= V_51 ;
V_4 -> V_226 = V_89 ;
F_120 ( & V_2 -> V_227 ) ;
}
F_21 ( & V_4 -> V_29 ) ;
F_113 ( V_2 , V_4 ) ;
}
}
static bool F_121 ( struct V_1 * V_2 ,
struct V_235 * V_236 ,
struct V_235 * V_238 ,
struct V_235 * V_239 )
{
struct V_3 * V_4 , * V_237 ;
int V_240 = 0 ;
int V_211 ;
F_86 ( & V_2 -> V_241 ) ;
F_119 (req, tmp, incoming, tl_requests) {
V_211 = F_122 ( V_2 , & V_4 -> V_6 ) ;
if ( V_211 == - V_242 )
break;
if ( V_211 == - V_243 )
V_240 = 1 ;
if ( V_211 )
F_123 ( & V_4 -> V_29 , V_239 ) ;
else
F_123 ( & V_4 -> V_29 , V_238 ) ;
}
F_84 ( & V_2 -> V_241 ) ;
if ( V_240 )
F_16 ( & V_2 -> V_221 ) ;
return ! F_41 ( V_238 ) ;
}
void F_124 ( struct V_1 * V_2 , struct V_235 * V_238 )
{
struct V_3 * V_4 , * V_237 ;
F_119 (req, tmp, pending, tl_requests) {
V_4 -> V_15 |= V_51 ;
V_4 -> V_226 = V_89 ;
F_120 ( & V_2 -> V_227 ) ;
F_21 ( & V_4 -> V_29 ) ;
F_113 ( V_2 , V_4 ) ;
}
}
void F_125 ( struct V_244 * V_245 )
{
struct V_1 * V_2 = F_18 ( V_245 , struct V_1 , V_216 . V_220 ) ;
F_126 ( V_236 ) ;
F_126 ( V_238 ) ;
F_126 ( V_246 ) ;
F_86 ( & V_2 -> V_187 -> V_188 ) ;
F_127 ( & V_2 -> V_216 . V_217 , & V_236 ) ;
F_84 ( & V_2 -> V_187 -> V_188 ) ;
for (; ; ) {
F_81 ( V_185 ) ;
F_128 ( & V_246 , & V_236 ) ;
F_118 ( V_2 , & V_236 ) ;
if ( F_41 ( & V_236 ) )
break;
for (; ; ) {
F_83 ( & V_2 -> V_221 , & V_185 , V_186 ) ;
F_128 ( & V_246 , & V_236 ) ;
F_121 ( V_2 , & V_236 , & V_238 , & V_246 ) ;
if ( ! F_41 ( & V_238 ) )
break;
F_85 () ;
if ( ! F_41 ( & V_236 ) )
continue;
F_86 ( & V_2 -> V_187 -> V_188 ) ;
F_127 ( & V_2 -> V_216 . V_217 , & V_236 ) ;
F_84 ( & V_2 -> V_187 -> V_188 ) ;
}
F_87 ( & V_2 -> V_221 , & V_185 ) ;
while ( F_41 ( & V_236 ) ) {
F_126 ( V_247 ) ;
F_126 ( V_248 ) ;
bool V_249 ;
if ( F_41 ( & V_2 -> V_216 . V_217 ) )
break;
F_86 ( & V_2 -> V_187 -> V_188 ) ;
F_127 ( & V_2 -> V_216 . V_217 , & V_248 ) ;
F_84 ( & V_2 -> V_187 -> V_188 ) ;
if ( F_41 ( & V_248 ) )
break;
V_249 = F_121 ( V_2 , & V_248 , & V_247 , & V_246 ) ;
F_127 ( & V_247 , & V_238 ) ;
F_127 ( & V_248 , & V_236 ) ;
if ( ! V_249 )
break;
}
F_129 ( V_2 ) ;
F_124 ( V_2 , & V_238 ) ;
}
}
T_2 F_130 ( struct V_250 * V_251 , struct V_11 * V_11 )
{
struct V_1 * V_2 = (struct V_1 * ) V_251 -> V_252 ;
unsigned long V_10 ;
F_131 ( V_251 , & V_11 , V_251 -> V_253 ) ;
V_10 = V_89 ;
F_43 ( V_2 , F_132 ( V_11 -> V_24 . V_26 , 512 ) ) ;
F_133 ( V_2 ) ;
F_116 ( V_2 , V_11 , V_10 ) ;
return V_254 ;
}
static bool F_134 ( struct V_3 * V_255 ,
struct V_54 * V_55 ,
unsigned long V_256 , unsigned long V_257 ,
unsigned int V_258 , unsigned int V_259 )
{
struct V_1 * V_2 = V_255 -> V_2 ;
if ( ! F_135 ( V_256 , V_255 -> V_260 + V_257 ) )
return false ;
if ( F_136 ( V_256 , V_55 -> V_261 , V_55 -> V_261 + V_257 ) )
return false ;
if ( V_255 -> V_15 & V_66 ) {
F_29 ( V_2 , L_17 ,
F_137 ( V_256 - V_255 -> V_260 ) , V_258 , V_259 ) ;
return true ;
}
if ( V_255 -> V_22 == V_55 -> V_262 . V_263 ) {
F_29 ( V_2 ,
L_18 ,
F_137 ( V_256 - V_255 -> V_260 ) , V_258 , V_259 ) ;
return false ;
}
if ( F_135 ( V_256 , V_55 -> V_262 . V_264 + V_257 ) ) {
F_29 ( V_2 , L_19 ,
V_55 -> V_262 . V_264 , V_256 ,
F_137 ( V_256 - V_55 -> V_262 . V_264 ) , V_258 , V_259 ) ;
return true ;
}
return false ;
}
void F_138 ( unsigned long V_265 )
{
struct V_1 * V_2 = (struct V_1 * ) V_265 ;
struct V_54 * V_55 = F_40 ( V_2 ) -> V_55 ;
struct V_3 * V_266 , * V_267 , * V_268 ;
struct V_101 * V_102 ;
unsigned long V_269 ;
unsigned long V_257 = 0 , V_270 = 0 , V_271 , V_272 ;
unsigned long V_256 ;
unsigned int V_258 = 0 , V_259 = 0 ;
F_65 () ;
V_102 = F_66 ( V_55 -> V_101 ) ;
if ( V_102 && V_2 -> V_158 . V_195 >= V_273 ) {
V_258 = V_102 -> V_258 ;
V_259 = V_102 -> V_259 ;
}
if ( F_72 ( V_2 ) ) {
V_270 = F_66 ( V_2 -> V_95 -> V_203 ) -> V_274 * V_275 / 10 ;
F_27 ( V_2 ) ;
}
F_67 () ;
V_257 = V_259 * V_275 / 10 * V_258 ;
V_271 = F_139 ( V_270 , V_257 ) ;
if ( ! V_271 )
return;
V_256 = V_89 ;
V_272 = V_256 + V_271 ;
F_86 ( & V_2 -> V_187 -> V_188 ) ;
V_266 = F_140 ( & V_2 -> V_234 [ 0 ] , struct V_3 , V_33 ) ;
V_267 = F_140 ( & V_2 -> V_234 [ 1 ] , struct V_3 , V_33 ) ;
V_268 = V_55 -> V_79 ;
if ( ! V_268 )
V_268 = V_55 -> V_81 ;
if ( V_268 && V_268 -> V_2 != V_2 )
V_268 = NULL ;
if ( V_268 == NULL && V_267 == NULL && V_266 == NULL )
goto V_231;
V_269 =
( V_267 && V_266 )
? ( F_141 ( V_267 -> V_233 , V_266 -> V_233 )
? V_267 -> V_233 : V_266 -> V_233 )
: V_267 ? V_267 -> V_233
: V_266 ? V_266 -> V_233 : V_256 ;
if ( V_257 && V_268 && F_134 ( V_268 , V_55 , V_256 , V_257 , V_258 , V_259 ) )
F_142 ( V_55 , F_143 ( V_195 , V_276 ) , V_277 | V_278 ) ;
if ( V_270 && V_269 != V_256 &&
F_135 ( V_256 , V_269 + V_270 ) &&
! F_136 ( V_256 , V_2 -> V_279 , V_2 -> V_279 + V_270 ) ) {
F_29 ( V_2 , L_20 ) ;
F_68 ( V_2 , V_280 ) ;
}
V_257 = ( V_257 && V_268 && F_141 ( V_256 , V_268 -> V_260 + V_257 ) )
? V_268 -> V_260 + V_257 : V_256 + V_271 ;
V_270 = ( V_270 && V_269 != V_256 && F_141 ( V_256 , V_269 + V_270 ) )
? V_269 + V_270 : V_256 + V_271 ;
V_272 = F_141 ( V_257 , V_270 ) ? V_257 : V_270 ;
V_231:
F_84 ( & V_2 -> V_187 -> V_188 ) ;
F_144 ( & V_2 -> V_281 , V_272 ) ;
}
