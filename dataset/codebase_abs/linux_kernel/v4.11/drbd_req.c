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
if ( F_54 ( V_2 ) && ! ( ( V_40 | V_82 ) & V_67 ) )
V_83 |= V_67 ;
V_4 -> V_15 &= ~ V_82 ;
V_4 -> V_15 |= V_83 ;
if ( V_4 -> V_15 == V_40 )
return;
F_55 ( & V_4 -> V_35 ) ;
if ( ! ( V_40 & V_42 ) && ( V_83 & V_42 ) )
F_33 ( & V_4 -> V_34 ) ;
if ( ! ( V_40 & V_66 ) && ( V_83 & V_66 ) ) {
F_56 ( V_2 ) ;
F_33 ( & V_4 -> V_34 ) ;
}
if ( ! ( V_40 & V_65 ) && ( V_83 & V_65 ) ) {
F_33 ( & V_4 -> V_34 ) ;
F_46 ( V_76 , V_4 ) ;
}
if ( ! ( V_40 & V_85 ) && ( V_83 & V_85 ) )
F_55 ( & V_4 -> V_35 ) ;
if ( ! ( V_40 & V_80 ) && ( V_83 & V_80 ) ) {
if ( ! ( V_40 & V_44 ) ) {
F_57 ( V_4 -> V_6 . V_7 >> 9 , & V_2 -> V_86 ) ;
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
++ V_84 ;
}
if ( ( V_40 & V_42 ) && ( V_82 & V_42 ) ) {
if ( V_4 -> V_15 & V_64 )
F_58 ( & V_4 -> V_35 , F_17 ) ;
else
++ V_84 ;
F_21 ( & V_4 -> V_33 ) ;
}
if ( ( V_40 & V_66 ) && ( V_82 & V_66 ) ) {
F_59 ( V_2 ) ;
++ V_84 ;
V_4 -> V_87 = V_88 ;
F_50 ( V_76 , V_4 ) ;
}
if ( ( V_40 & V_65 ) && ( V_82 & V_65 ) ) {
++ V_84 ;
F_47 ( V_76 , V_4 ) ;
}
if ( ! ( V_40 & V_44 ) && ( V_83 & V_44 ) ) {
if ( V_40 & V_80 )
F_60 ( V_4 -> V_6 . V_7 >> 9 , & V_2 -> V_86 ) ;
if ( V_40 & V_85 )
F_58 ( & V_4 -> V_35 , F_17 ) ;
V_4 -> V_89 = V_88 ;
F_47 ( V_76 , V_4 ) ;
F_50 ( V_76 , V_4 ) ;
F_52 ( V_76 , V_4 ) ;
}
if ( V_4 -> V_6 . V_28 )
F_16 ( & V_2 -> V_39 ) ;
if ( V_84 ) {
if ( F_42 ( V_4 , V_61 , V_84 ) )
F_58 ( & V_4 -> V_35 , F_17 ) ;
} else {
F_58 ( & V_4 -> V_35 , F_17 ) ;
}
}
static void F_61 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
char V_90 [ V_91 ] ;
if ( ! F_28 ( & V_53 ) )
return;
F_29 ( V_2 , L_7 ,
( V_4 -> V_15 & V_17 ) ? L_8 : L_9 ,
( unsigned long long ) V_4 -> V_6 . V_23 ,
V_4 -> V_6 . V_7 >> 9 ,
F_62 ( V_2 -> V_92 -> V_93 , V_90 ) ) ;
}
static inline bool F_63 ( struct V_3 * V_4 )
{
return ( V_4 -> V_15 &
( V_17 | V_66 | V_94 | V_95 ) )
== ( V_17 | V_66 ) ;
}
int F_64 ( struct V_3 * V_4 , enum V_96 V_97 ,
struct V_60 * V_61 )
{
struct V_1 * const V_2 = V_4 -> V_2 ;
struct V_75 * const V_76 = F_40 ( V_2 ) ;
struct V_54 * const V_55 = V_76 ? V_76 -> V_55 : NULL ;
struct V_98 * V_99 ;
int V_100 , V_101 = 0 ;
if ( V_61 )
V_61 -> V_11 = NULL ;
switch ( V_97 ) {
default:
F_20 ( V_2 , L_10 , __FILE__ , __LINE__ ) ;
break;
case V_102 :
F_43 ( V_2 , ! ( V_4 -> V_15 & V_43 ) ) ;
F_65 () ;
V_99 = F_66 ( V_55 -> V_98 ) ;
V_100 = V_99 -> V_103 ;
F_67 () ;
V_4 -> V_15 |=
V_100 == V_104 ? V_94 :
V_100 == V_105 ? V_95 : 0 ;
F_53 ( V_4 , V_61 , 0 , V_66 ) ;
break;
case V_106 :
F_43 ( V_2 , ! ( V_4 -> V_15 & V_47 ) ) ;
F_53 ( V_4 , V_61 , 0 , V_42 ) ;
break;
case V_107 :
if ( V_4 -> V_15 & V_17 )
V_2 -> V_108 += V_4 -> V_6 . V_7 >> 9 ;
else
V_2 -> V_109 += V_4 -> V_6 . V_7 >> 9 ;
F_53 ( V_4 , V_61 , V_42 ,
V_110 | V_49 ) ;
break;
case V_111 :
F_53 ( V_4 , V_61 , 0 , V_64 ) ;
break;
case V_112 :
F_61 ( V_2 , V_4 ) ;
F_68 ( V_2 , V_113 ) ;
F_53 ( V_4 , V_61 , V_42 , V_110 ) ;
break;
case V_114 :
F_23 ( V_2 , V_4 -> V_6 . V_23 , V_4 -> V_6 . V_7 ) ;
F_61 ( V_2 , V_4 ) ;
F_68 ( V_2 , V_115 ) ;
case V_116 :
F_53 ( V_4 , V_61 , V_42 , V_110 ) ;
break;
case V_117 :
case V_118 :
F_53 ( V_4 , V_61 , V_42 , V_110 ) ;
break;
case V_119 :
F_43 ( V_2 , F_22 ( & V_4 -> V_6 ) ) ;
F_69 ( & V_2 -> V_46 , & V_4 -> V_6 ) ;
F_70 ( V_120 , & V_2 -> V_121 ) ;
F_43 ( V_2 , V_4 -> V_15 & V_66 ) ;
F_43 ( V_2 , ( V_4 -> V_15 & V_47 ) == 0 ) ;
F_53 ( V_4 , V_61 , 0 , V_65 ) ;
V_4 -> V_30 . V_122 = V_123 ;
F_71 ( & V_55 -> V_56 ,
& V_4 -> V_30 ) ;
break;
case V_124 :
F_43 ( V_2 , F_22 ( & V_4 -> V_6 ) ) ;
F_69 ( & V_2 -> V_45 , & V_4 -> V_6 ) ;
F_70 ( V_120 , & V_2 -> V_121 ) ;
F_43 ( V_2 , V_4 -> V_15 & V_66 ) ;
F_53 ( V_4 , V_61 , 0 , V_65 | V_85 ) ;
V_4 -> V_30 . V_122 = V_125 ;
F_71 ( & V_55 -> V_56 ,
& V_4 -> V_30 ) ;
F_65 () ;
V_99 = F_66 ( V_55 -> V_98 ) ;
V_100 = V_99 -> V_126 ;
F_67 () ;
if ( V_55 -> V_58 >= V_100 )
F_32 ( V_55 ) ;
break;
case V_127 :
F_53 ( V_4 , V_61 , 0 , V_65 ) ;
V_4 -> V_30 . V_122 = V_128 ;
F_71 ( & V_55 -> V_56 ,
& V_4 -> V_30 ) ;
break;
case V_129 :
case V_130 :
case V_131 :
F_53 ( V_4 , V_61 , V_65 , 0 ) ;
break;
case V_132 :
if ( F_63 ( V_4 ) )
F_53 ( V_4 , V_61 , V_65 | V_66 ,
V_80 | V_48 ) ;
else
F_53 ( V_4 , V_61 , V_65 , V_80 ) ;
break;
case V_133 :
F_53 ( V_4 , V_61 , V_65 , V_44 ) ;
break;
case V_134 :
F_53 ( V_4 , V_61 ,
V_48 | V_66 | V_67 ,
V_44 ) ;
break;
case V_135 :
F_43 ( V_2 , V_4 -> V_15 & V_66 ) ;
F_43 ( V_2 , V_4 -> V_15 & V_94 ) ;
F_53 ( V_4 , V_61 , V_66 , V_44 | V_48 ) ;
break;
case V_136 :
V_4 -> V_15 |= V_50 ;
case V_137 :
goto V_138;
case V_139 :
F_43 ( V_2 , V_4 -> V_15 & V_95 ) ;
V_138:
F_53 ( V_4 , V_61 , V_66 , V_48 ) ;
break;
case V_140 :
F_43 ( V_2 , V_4 -> V_15 & V_94 ) ;
F_43 ( V_2 , V_4 -> V_15 & V_66 ) ;
V_4 -> V_15 |= V_41 ;
if ( V_4 -> V_6 . V_28 )
F_16 ( & V_2 -> V_39 ) ;
break;
case V_141 :
F_53 ( V_4 , V_61 , V_48 | V_66 , 0 ) ;
break;
case V_142 :
if ( ! ( V_4 -> V_15 & V_110 ) )
break;
F_53 ( V_4 , V_61 , V_67 , 0 ) ;
break;
case V_143 :
if ( ! ( V_4 -> V_15 & V_110 ) )
break;
F_53 ( V_4 , V_61 ,
V_67 | V_110 ,
V_42 ) ;
V_101 = V_144 ;
if ( F_3 ( V_4 -> V_5 ) == V_16 )
V_101 = V_145 ;
F_72 ( V_2 ) ;
V_4 -> V_30 . V_122 = V_146 ;
F_71 ( & V_55 -> V_56 ,
& V_4 -> V_30 ) ;
break;
case V_147 :
if ( ! ( V_4 -> V_15 & V_17 ) && ! V_4 -> V_30 . V_122 ) {
F_53 ( V_4 , V_61 , V_67 , 0 ) ;
break;
}
if ( ! ( V_4 -> V_15 & V_48 ) ) {
F_53 ( V_4 , V_61 , V_67 , V_65 | V_66 ) ;
if ( V_4 -> V_30 . V_122 ) {
F_71 ( & V_55 -> V_56 ,
& V_4 -> V_30 ) ;
V_101 = V_4 -> V_15 & V_17 ? V_145 : V_144 ;
}
break;
}
case V_148 :
if ( ! ( V_4 -> V_15 & V_17 ) )
break;
if ( V_4 -> V_15 & V_66 ) {
F_20 ( V_2 , L_11 ) ;
}
F_53 ( V_4 , V_61 , V_67 ,
( V_4 -> V_15 & V_43 ) ? V_44 : 0 ) ;
break;
case V_149 :
F_43 ( V_2 , V_4 -> V_15 & V_66 ) ;
F_53 ( V_4 , V_61 , V_66 , V_48 | V_44 ) ;
break;
case V_150 :
F_32 ( V_55 ) ;
F_53 ( V_4 , V_61 , 0 , V_48 | V_44 ) ;
break;
} ;
return V_101 ;
}
static bool F_73 ( struct V_1 * V_2 , T_1 V_23 , int V_7 )
{
unsigned long V_151 , V_152 ;
T_1 V_153 , V_154 ;
if ( V_2 -> V_155 . V_156 == V_157 )
return true ;
if ( V_2 -> V_155 . V_156 != V_158 )
return false ;
V_153 = V_23 + ( V_7 >> 9 ) - 1 ;
V_154 = F_74 ( V_2 -> V_159 ) ;
F_43 ( V_2 , V_23 < V_154 ) ;
F_43 ( V_2 , V_153 < V_154 ) ;
V_151 = F_75 ( V_23 ) ;
V_152 = F_75 ( V_153 ) ;
return F_76 ( V_2 , V_151 , V_152 ) == 0 ;
}
static bool F_77 ( struct V_1 * V_2 , T_1 V_23 ,
enum V_160 V_161 )
{
struct V_162 * V_163 ;
int V_164 ;
switch ( V_161 ) {
case V_165 :
V_163 = V_2 -> V_92 -> V_93 -> V_166 -> V_167 -> V_162 ;
return F_78 ( V_163 ) ;
case V_168 :
return F_19 ( & V_2 -> V_169 ) >
F_19 ( & V_2 -> V_170 ) + F_19 ( & V_2 -> V_171 ) ;
case V_172 :
case V_173 :
case V_174 :
case V_175 :
case V_176 :
case V_177 :
V_164 = ( V_161 - V_172 + 15 ) ;
return ( V_23 >> ( V_164 - 9 ) ) & 1 ;
case V_178 :
return F_79 ( V_179 , & V_2 -> V_121 ) ;
case V_180 :
return true ;
case V_181 :
default:
return false ;
}
}
static void F_80 ( struct V_3 * V_4 )
{
F_81 ( V_182 ) ;
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
F_83 ( & V_2 -> V_39 , & V_182 , V_183 ) ;
V_6 -> V_28 = true ;
F_84 ( & V_2 -> V_184 -> V_185 ) ;
F_85 () ;
F_86 ( & V_2 -> V_184 -> V_185 ) ;
}
F_87 ( & V_2 -> V_39 , & V_182 ) ;
}
static void F_88 ( struct V_1 * V_2 )
{
struct V_54 * V_55 = F_40 ( V_2 ) -> V_55 ;
struct V_98 * V_99 ;
bool V_186 = false ;
enum V_187 V_188 ;
F_65 () ;
V_99 = F_66 ( V_55 -> V_98 ) ;
V_188 = V_99 ? V_99 -> V_188 : V_189 ;
F_67 () ;
if ( V_188 == V_189 ||
V_55 -> V_190 < 96 )
return;
if ( V_188 == V_191 && V_2 -> V_155 . V_192 == V_193 )
return;
if ( ! F_25 ( V_2 , V_157 ) )
return;
if ( V_99 -> V_194 &&
F_19 ( & V_2 -> V_86 ) >= V_99 -> V_194 ) {
F_89 ( V_2 , L_12 ) ;
V_186 = true ;
}
if ( V_2 -> V_195 -> V_196 >= V_99 -> V_197 ) {
F_89 ( V_2 , L_13 ) ;
V_186 = true ;
}
if ( V_186 ) {
F_32 ( F_40 ( V_2 ) -> V_55 ) ;
if ( V_188 == V_191 )
F_90 ( F_91 ( V_2 , V_192 , V_193 ) , 0 , NULL ) ;
else
F_90 ( F_91 ( V_2 , V_192 , V_198 ) , 0 , NULL ) ;
}
F_27 ( V_2 ) ;
}
static bool F_92 ( struct V_3 * V_4 )
{
struct V_1 * V_2 = V_4 -> V_2 ;
enum V_160 V_161 ;
if ( V_4 -> V_68 ) {
if ( ! F_73 ( V_2 ,
V_4 -> V_6 . V_23 , V_4 -> V_6 . V_7 ) ) {
F_93 ( V_4 -> V_68 ) ;
V_4 -> V_68 = NULL ;
F_27 ( V_2 ) ;
}
}
if ( V_2 -> V_155 . V_199 != V_157 )
return false ;
if ( V_4 -> V_68 == NULL )
return true ;
F_65 () ;
V_161 = F_66 ( V_2 -> V_92 -> V_200 ) -> V_201 ;
F_67 () ;
if ( V_161 == V_181 && V_4 -> V_68 )
return false ;
if ( F_77 ( V_2 , V_4 -> V_6 . V_23 , V_161 ) ) {
if ( V_4 -> V_68 ) {
F_93 ( V_4 -> V_68 ) ;
V_4 -> V_68 = NULL ;
F_27 ( V_2 ) ;
}
return true ;
}
return false ;
}
bool F_94 ( union V_202 V_40 )
{
return V_40 . V_199 == V_157 ||
( V_40 . V_199 >= V_158 &&
V_40 . V_192 >= V_203 &&
V_40 . V_192 < V_193 ) ;
}
static bool F_95 ( union V_202 V_40 )
{
return V_40 . V_192 == V_193 || V_40 . V_192 == V_204 ;
}
static int F_96 ( struct V_3 * V_4 )
{
struct V_1 * V_2 = V_4 -> V_2 ;
int V_205 , V_206 ;
V_205 = F_94 ( V_2 -> V_155 ) ;
V_206 = F_95 ( V_2 -> V_155 ) ;
if ( F_97 ( V_4 -> V_6 . V_7 == 0 ) ) {
F_43 ( V_2 , V_4 -> V_5 -> V_70 & V_207 ) ;
if ( V_205 )
F_98 ( V_4 , V_150 ) ;
return V_205 ;
}
if ( ! V_205 && ! V_206 )
return 0 ;
F_43 ( V_2 , ! ( V_205 && V_206 ) ) ;
if ( V_205 ) {
F_98 ( V_4 , V_102 ) ;
F_98 ( V_4 , V_124 ) ;
} else if ( F_23 ( V_2 , V_4 -> V_6 . V_23 , V_4 -> V_6 . V_7 ) )
F_98 ( V_4 , V_127 ) ;
return V_205 ;
}
static void F_99 ( struct V_3 * V_4 )
{
int V_208 = F_100 ( V_4 -> V_2 ,
V_4 -> V_6 . V_23 , V_4 -> V_6 . V_7 >> 9 , true ) ;
if ( V_208 )
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
type = V_209 ;
else if ( V_11 -> V_70 & V_71 )
type = V_210 ;
else
type = V_211 ;
V_11 -> V_212 = V_2 -> V_92 -> V_93 ;
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
F_86 ( & V_2 -> V_184 -> V_185 ) ;
F_106 ( & V_4 -> V_29 , & V_2 -> V_213 . V_214 ) ;
F_106 ( & V_4 -> V_32 ,
& V_2 -> V_215 [ 1 ] ) ;
F_84 ( & V_2 -> V_184 -> V_185 ) ;
F_107 ( V_2 -> V_213 . V_216 , & V_2 -> V_213 . V_217 ) ;
F_16 ( & V_2 -> V_218 ) ;
}
static struct V_3 *
F_108 ( struct V_1 * V_2 , struct V_11 * V_11 , unsigned long V_10 )
{
const int V_219 = F_3 ( V_11 ) ;
struct V_3 * V_4 ;
V_4 = F_6 ( V_2 , V_11 ) ;
if ( ! V_4 ) {
F_36 ( V_2 ) ;
F_20 ( V_2 , L_14 ) ;
V_11 -> V_62 = - V_220 ;
F_35 ( V_11 ) ;
return F_109 ( - V_220 ) ;
}
V_4 -> V_10 = V_10 ;
if ( ! F_72 ( V_2 ) ) {
F_93 ( V_4 -> V_68 ) ;
V_4 -> V_68 = NULL ;
}
F_1 ( V_2 , V_4 ) ;
if ( F_9 ( V_11 ) & V_20 )
goto V_221;
if ( V_219 == V_16 && V_4 -> V_68 && V_4 -> V_6 . V_7
&& ! F_110 ( V_222 , & V_2 -> V_121 ) ) {
if ( ! F_111 ( V_2 , & V_4 -> V_6 ) )
goto V_221;
V_4 -> V_15 |= V_51 ;
V_4 -> V_223 = V_88 ;
}
return V_4 ;
V_221:
F_33 ( & V_2 -> V_224 ) ;
F_105 ( V_2 , V_4 ) ;
return NULL ;
}
static bool F_112 ( struct V_1 * V_2 )
{
const union V_202 V_40 = V_2 -> V_155 ;
return V_40 . V_156 == V_157 || V_40 . V_199 == V_157 ;
}
static void F_113 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_225 * V_184 = V_2 -> V_184 ;
const int V_219 = F_3 ( V_4 -> V_5 ) ;
struct V_60 V_61 = { NULL , } ;
bool V_226 = false ;
bool V_227 = false ;
F_86 ( & V_184 -> V_185 ) ;
if ( V_219 == V_16 ) {
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
goto V_228;
}
if ( V_219 != V_16 ) {
if ( ! F_92 ( V_4 ) && ! V_4 -> V_68 )
goto V_229;
}
V_4 -> V_22 = F_19 ( & F_40 ( V_2 ) -> V_55 -> V_59 ) ;
if ( F_114 ( V_4 -> V_6 . V_7 != 0 ) ) {
if ( V_219 == V_16 )
F_40 ( V_2 ) -> V_55 -> V_58 ++ ;
F_106 ( & V_4 -> V_29 , & F_40 ( V_2 ) -> V_55 -> V_78 ) ;
}
if ( V_219 == V_16 ) {
if ( V_4 -> V_68 && ! F_112 ( V_2 ) ) {
F_93 ( V_4 -> V_68 ) ;
V_4 -> V_68 = NULL ;
F_27 ( V_2 ) ;
goto V_229;
}
if ( ! F_96 ( V_4 ) )
V_226 = true ;
} else {
if ( V_4 -> V_68 == NULL ) {
F_98 ( V_4 , V_102 ) ;
F_98 ( V_4 , V_119 ) ;
} else
V_226 = true ;
}
if ( F_41 ( & V_4 -> V_32 ) )
F_106 ( & V_4 -> V_32 ,
& V_2 -> V_215 [ V_219 == V_16 ] ) ;
if ( V_4 -> V_68 ) {
V_4 -> V_230 = V_88 ;
F_106 ( & V_4 -> V_33 ,
& V_2 -> V_231 [ V_219 == V_16 ] ) ;
F_98 ( V_4 , V_106 ) ;
V_227 = true ;
} else if ( V_226 ) {
V_229:
if ( F_28 ( & V_53 ) )
F_20 ( V_2 , L_15 ,
( unsigned long long ) V_4 -> V_6 . V_23 , V_4 -> V_6 . V_7 >> 9 ) ;
}
V_228:
if ( F_42 ( V_4 , & V_61 , 1 ) )
F_58 ( & V_4 -> V_35 , F_17 ) ;
F_84 ( & V_184 -> V_185 ) ;
if ( V_227 )
F_101 ( V_4 ) ;
if ( V_61 . V_11 )
F_34 ( V_2 , & V_61 ) ;
}
void F_115 ( struct V_1 * V_2 , struct V_11 * V_11 , unsigned long V_10 )
{
struct V_3 * V_4 = F_108 ( V_2 , V_11 , V_10 ) ;
if ( F_116 ( V_4 ) )
return;
F_113 ( V_2 , V_4 ) ;
}
static void F_117 ( struct V_1 * V_2 , struct V_232 * V_233 )
{
struct V_3 * V_4 , * V_234 ;
F_118 (req, tmp, incoming, tl_requests) {
const int V_219 = F_3 ( V_4 -> V_5 ) ;
if ( V_219 == V_16
&& V_4 -> V_68 && V_4 -> V_6 . V_7
&& ! F_110 ( V_222 , & V_2 -> V_121 ) ) {
if ( ! F_111 ( V_2 , & V_4 -> V_6 ) )
continue;
V_4 -> V_15 |= V_51 ;
V_4 -> V_223 = V_88 ;
F_119 ( & V_2 -> V_224 ) ;
}
F_21 ( & V_4 -> V_29 ) ;
F_113 ( V_2 , V_4 ) ;
}
}
static bool F_120 ( struct V_1 * V_2 ,
struct V_232 * V_233 ,
struct V_232 * V_235 ,
struct V_232 * V_236 )
{
struct V_3 * V_4 , * V_234 ;
int V_237 = 0 ;
int V_208 ;
F_86 ( & V_2 -> V_238 ) ;
F_118 (req, tmp, incoming, tl_requests) {
V_208 = F_121 ( V_2 , & V_4 -> V_6 ) ;
if ( V_208 == - V_239 )
break;
if ( V_208 == - V_240 )
V_237 = 1 ;
if ( V_208 )
F_122 ( & V_4 -> V_29 , V_236 ) ;
else
F_122 ( & V_4 -> V_29 , V_235 ) ;
}
F_84 ( & V_2 -> V_238 ) ;
if ( V_237 )
F_16 ( & V_2 -> V_218 ) ;
return ! F_41 ( V_235 ) ;
}
void F_123 ( struct V_1 * V_2 , struct V_232 * V_235 )
{
struct V_3 * V_4 , * V_234 ;
F_118 (req, tmp, pending, tl_requests) {
V_4 -> V_15 |= V_51 ;
V_4 -> V_223 = V_88 ;
F_119 ( & V_2 -> V_224 ) ;
F_21 ( & V_4 -> V_29 ) ;
F_113 ( V_2 , V_4 ) ;
}
}
void F_124 ( struct V_241 * V_242 )
{
struct V_1 * V_2 = F_18 ( V_242 , struct V_1 , V_213 . V_217 ) ;
F_125 ( V_233 ) ;
F_125 ( V_235 ) ;
F_125 ( V_243 ) ;
F_86 ( & V_2 -> V_184 -> V_185 ) ;
F_126 ( & V_2 -> V_213 . V_214 , & V_233 ) ;
F_84 ( & V_2 -> V_184 -> V_185 ) ;
for (; ; ) {
F_81 ( V_182 ) ;
F_127 ( & V_243 , & V_233 ) ;
F_117 ( V_2 , & V_233 ) ;
if ( F_41 ( & V_233 ) )
break;
for (; ; ) {
F_83 ( & V_2 -> V_218 , & V_182 , V_183 ) ;
F_127 ( & V_243 , & V_233 ) ;
F_120 ( V_2 , & V_233 , & V_235 , & V_243 ) ;
if ( ! F_41 ( & V_235 ) )
break;
F_85 () ;
if ( ! F_41 ( & V_233 ) )
continue;
F_86 ( & V_2 -> V_184 -> V_185 ) ;
F_126 ( & V_2 -> V_213 . V_214 , & V_233 ) ;
F_84 ( & V_2 -> V_184 -> V_185 ) ;
}
F_87 ( & V_2 -> V_218 , & V_182 ) ;
while ( F_41 ( & V_233 ) ) {
F_125 ( V_244 ) ;
F_125 ( V_245 ) ;
bool V_246 ;
if ( F_41 ( & V_2 -> V_213 . V_214 ) )
break;
F_86 ( & V_2 -> V_184 -> V_185 ) ;
F_126 ( & V_2 -> V_213 . V_214 , & V_245 ) ;
F_84 ( & V_2 -> V_184 -> V_185 ) ;
if ( F_41 ( & V_245 ) )
break;
V_246 = F_120 ( V_2 , & V_245 , & V_244 , & V_243 ) ;
F_126 ( & V_244 , & V_235 ) ;
F_126 ( & V_245 , & V_233 ) ;
if ( ! V_246 )
break;
}
F_128 ( V_2 ) ;
F_123 ( V_2 , & V_235 ) ;
}
}
T_2 F_129 ( struct V_247 * V_248 , struct V_11 * V_11 )
{
struct V_1 * V_2 = (struct V_1 * ) V_248 -> V_249 ;
unsigned long V_10 ;
F_130 ( V_248 , & V_11 , V_248 -> V_250 ) ;
V_10 = V_88 ;
F_43 ( V_2 , F_131 ( V_11 -> V_24 . V_26 , 512 ) ) ;
F_132 ( V_2 ) ;
F_115 ( V_2 , V_11 , V_10 ) ;
return V_251 ;
}
static bool F_133 ( struct V_3 * V_252 ,
struct V_54 * V_55 ,
unsigned long V_253 , unsigned long V_254 ,
unsigned int V_255 , unsigned int V_256 )
{
struct V_1 * V_2 = V_252 -> V_2 ;
if ( ! F_134 ( V_253 , V_252 -> V_257 + V_254 ) )
return false ;
if ( F_135 ( V_253 , V_55 -> V_258 , V_55 -> V_258 + V_254 ) )
return false ;
if ( V_252 -> V_15 & V_66 ) {
F_29 ( V_2 , L_16 ,
F_136 ( V_253 - V_252 -> V_257 ) , V_255 , V_256 ) ;
return true ;
}
if ( V_252 -> V_22 == V_55 -> V_259 . V_260 ) {
F_29 ( V_2 ,
L_17 ,
F_136 ( V_253 - V_252 -> V_257 ) , V_255 , V_256 ) ;
return false ;
}
if ( F_134 ( V_253 , V_55 -> V_259 . V_261 + V_254 ) ) {
F_29 ( V_2 , L_18 ,
V_55 -> V_259 . V_261 , V_253 ,
F_136 ( V_253 - V_55 -> V_259 . V_261 ) , V_255 , V_256 ) ;
return true ;
}
return false ;
}
void F_137 ( unsigned long V_262 )
{
struct V_1 * V_2 = (struct V_1 * ) V_262 ;
struct V_54 * V_55 = F_40 ( V_2 ) -> V_55 ;
struct V_3 * V_263 , * V_264 , * V_265 ;
struct V_98 * V_99 ;
unsigned long V_266 ;
unsigned long V_254 = 0 , V_267 = 0 , V_268 , V_269 ;
unsigned long V_253 ;
unsigned int V_255 = 0 , V_256 = 0 ;
F_65 () ;
V_99 = F_66 ( V_55 -> V_98 ) ;
if ( V_99 && V_2 -> V_155 . V_192 >= V_270 ) {
V_255 = V_99 -> V_255 ;
V_256 = V_99 -> V_256 ;
}
if ( F_72 ( V_2 ) ) {
V_267 = F_66 ( V_2 -> V_92 -> V_200 ) -> V_271 * V_272 / 10 ;
F_27 ( V_2 ) ;
}
F_67 () ;
V_254 = V_256 * V_272 / 10 * V_255 ;
V_268 = F_138 ( V_267 , V_254 ) ;
if ( ! V_268 )
return;
V_253 = V_88 ;
V_269 = V_253 + V_268 ;
F_86 ( & V_2 -> V_184 -> V_185 ) ;
V_263 = F_139 ( & V_2 -> V_231 [ 0 ] , struct V_3 , V_33 ) ;
V_264 = F_139 ( & V_2 -> V_231 [ 1 ] , struct V_3 , V_33 ) ;
V_265 = V_55 -> V_79 ;
if ( ! V_265 )
V_265 = V_55 -> V_81 ;
if ( V_265 && V_265 -> V_2 != V_2 )
V_265 = NULL ;
if ( V_265 == NULL && V_264 == NULL && V_263 == NULL )
goto V_228;
V_266 =
( V_264 && V_263 )
? ( F_140 ( V_264 -> V_230 , V_263 -> V_230 )
? V_264 -> V_230 : V_263 -> V_230 )
: V_264 ? V_264 -> V_230
: V_263 ? V_263 -> V_230 : V_253 ;
if ( V_254 && V_265 && F_133 ( V_265 , V_55 , V_253 , V_254 , V_255 , V_256 ) )
F_141 ( V_55 , F_142 ( V_192 , V_273 ) , V_274 | V_275 ) ;
if ( V_267 && V_266 != V_253 &&
F_134 ( V_253 , V_266 + V_267 ) &&
! F_135 ( V_253 , V_2 -> V_276 , V_2 -> V_276 + V_267 ) ) {
F_29 ( V_2 , L_19 ) ;
F_68 ( V_2 , V_277 ) ;
}
V_254 = ( V_254 && V_265 && F_140 ( V_253 , V_265 -> V_257 + V_254 ) )
? V_265 -> V_257 + V_254 : V_253 + V_268 ;
V_267 = ( V_267 && V_266 != V_253 && F_140 ( V_253 , V_266 + V_267 ) )
? V_266 + V_267 : V_253 + V_268 ;
V_269 = F_140 ( V_254 , V_267 ) ? V_254 : V_267 ;
V_228:
F_84 ( & V_2 -> V_184 -> V_185 ) ;
F_143 ( & V_2 -> V_278 , V_269 ) ;
}
