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
| ( F_9 ( V_12 ) == V_20 ? V_21 : 0 )
| ( F_9 ( V_12 ) == V_22 ? V_21 : 0 ) ;
V_4 -> V_2 = V_2 ;
V_4 -> V_5 = V_12 ;
V_4 -> V_23 = 0 ;
F_10 ( & V_4 -> V_6 ) ;
V_4 -> V_6 . V_24 = V_12 -> V_25 . V_26 ;
V_4 -> V_6 . V_7 = V_12 -> V_25 . V_27 ;
V_4 -> V_6 . V_28 = true ;
V_4 -> V_6 . V_29 = false ;
F_11 ( & V_4 -> V_30 ) ;
F_11 ( & V_4 -> V_31 . V_32 ) ;
F_11 ( & V_4 -> V_33 ) ;
F_11 ( & V_4 -> V_34 ) ;
F_12 ( & V_4 -> V_35 , 1 ) ;
F_13 ( & V_4 -> V_36 ) ;
return V_4 ;
}
static void F_14 ( struct V_37 * V_38 ,
struct V_3 * V_4 )
{
struct V_1 * V_2 = V_4 -> V_2 ;
struct V_39 * V_6 = & V_4 -> V_6 ;
F_15 ( V_38 , V_6 ) ;
if ( V_6 -> V_29 )
F_16 ( & V_2 -> V_40 ) ;
}
void F_17 ( struct V_36 * V_36 )
{
struct V_3 * V_4 = F_18 ( V_36 , struct V_3 , V_36 ) ;
struct V_1 * V_2 = V_4 -> V_2 ;
const unsigned V_41 = V_4 -> V_15 ;
if ( ( V_4 -> V_5 && ! ( V_41 & V_42 ) ) ||
F_19 ( & V_4 -> V_35 ) ||
( V_41 & V_43 ) ||
( ( V_41 & V_44 ) && ! ( V_41 & V_45 ) ) ) {
F_20 ( V_2 , L_1 ,
V_41 , F_19 ( & V_4 -> V_35 ) ) ;
return;
}
F_21 ( & V_4 -> V_30 ) ;
if ( ! F_22 ( & V_4 -> V_6 ) ) {
struct V_37 * V_38 ;
if ( V_41 & V_17 )
V_38 = & V_2 -> V_46 ;
else
V_38 = & V_2 -> V_47 ;
F_14 ( V_38 , V_4 ) ;
} else if ( V_41 & ( V_44 & ~ V_45 ) && V_4 -> V_6 . V_7 != 0 )
F_20 ( V_2 , L_2 ,
V_41 , ( unsigned long long ) V_4 -> V_6 . V_24 , V_4 -> V_6 . V_7 ) ;
if ( V_41 & V_17 ) {
if ( ( V_41 & ( V_42 | V_48 | V_44 ) ) != V_42 ) {
if ( ! ( V_41 & V_49 ) || ! ( V_41 & V_50 ) )
F_23 ( V_2 , V_4 -> V_6 . V_24 , V_4 -> V_6 . V_7 ) ;
if ( ( V_41 & V_49 ) && ( V_41 & V_50 ) && ( V_41 & V_51 ) )
F_24 ( V_2 , V_4 -> V_6 . V_24 , V_4 -> V_6 . V_7 ) ;
}
if ( V_41 & V_52 ) {
if ( F_25 ( V_2 , V_53 ) ) {
F_26 ( V_2 , & V_4 -> V_6 ) ;
F_27 ( V_2 ) ;
} else if ( F_28 ( & V_54 ) ) {
F_29 ( V_2 , L_3
L_4 ,
( unsigned long long ) V_4 -> V_6 . V_24 , V_4 -> V_6 . V_7 ) ;
}
}
}
F_30 ( V_4 , V_13 ) ;
}
static void F_31 ( struct V_55 * V_56 )
{
F_16 ( & V_56 -> V_57 . V_58 ) ;
}
void F_32 ( struct V_55 * V_56 )
{
if ( V_56 -> V_59 == 0 )
return;
V_56 -> V_59 = 0 ;
F_33 ( & V_56 -> V_60 ) ;
F_31 ( V_56 ) ;
}
void F_34 ( struct V_1 * V_2 ,
struct V_61 * V_62 )
{
V_62 -> V_11 -> V_63 = V_62 -> error ;
F_35 ( V_62 -> V_11 ) ;
F_36 ( V_2 ) ;
}
static
void F_37 ( struct V_3 * V_4 , struct V_61 * V_62 )
{
const unsigned V_41 = V_4 -> V_15 ;
struct V_1 * V_2 = V_4 -> V_2 ;
int error , V_64 ;
if ( ( V_41 & V_43 && ! ( V_41 & V_65 ) ) ||
( V_41 & V_66 ) || ( V_41 & V_67 ) ||
( V_41 & V_68 ) ) {
F_20 ( V_2 , L_5 , V_41 ) ;
return;
}
if ( ! V_4 -> V_5 ) {
F_20 ( V_2 , L_6 ) ;
return;
}
V_64 = ( V_41 & V_50 ) || ( V_41 & V_49 ) ;
error = F_38 ( V_4 -> V_69 ) ;
if ( F_39 ( F_9 ( V_4 -> V_5 ) ) &&
V_4 -> V_23 == F_19 ( & F_40 ( V_2 ) -> V_56 -> V_60 ) )
F_32 ( F_40 ( V_2 ) -> V_56 ) ;
F_4 ( V_2 , V_4 ) ;
if ( ! V_64 &&
F_9 ( V_4 -> V_5 ) == V_70 &&
! ( V_4 -> V_5 -> V_71 & V_72 ) &&
! F_41 ( & V_4 -> V_30 ) )
V_4 -> V_15 |= V_42 ;
if ( ! ( V_4 -> V_15 & V_42 ) ) {
V_62 -> error = V_64 ? 0 : ( error ? : - V_73 ) ;
V_62 -> V_11 = V_4 -> V_5 ;
V_4 -> V_5 = NULL ;
V_4 -> V_6 . V_74 = true ;
}
if ( V_4 -> V_6 . V_29 )
F_16 ( & V_2 -> V_40 ) ;
F_21 ( & V_4 -> V_33 ) ;
}
static void F_42 ( struct V_3 * V_4 , struct V_61 * V_62 , int V_75 )
{
struct V_1 * V_2 = V_4 -> V_2 ;
F_43 ( V_2 , V_62 || ( V_4 -> V_15 & V_42 ) ) ;
if ( ! V_75 )
return;
if ( ! F_44 ( V_75 , & V_4 -> V_35 ) )
return;
F_37 ( V_4 , V_62 ) ;
if ( V_4 -> V_15 & V_65 )
return;
if ( V_4 -> V_15 & V_42 ) {
F_45 ( V_4 ) ;
return;
}
F_46 ( & V_4 -> V_36 , F_17 ) ;
}
static void F_47 ( struct V_76 * V_77 , struct V_3 * V_4 )
{
struct V_55 * V_56 = V_77 ? V_77 -> V_56 : NULL ;
if ( ! V_56 )
return;
if ( V_56 -> V_78 == NULL )
V_56 -> V_78 = V_4 ;
}
static void F_48 ( struct V_76 * V_77 , struct V_3 * V_4 )
{
struct V_55 * V_56 = V_77 ? V_77 -> V_56 : NULL ;
if ( ! V_56 )
return;
if ( V_56 -> V_78 != V_4 )
return;
F_49 (req, &connection->transfer_log, tl_requests) {
const unsigned V_41 = V_4 -> V_15 ;
if ( V_41 & V_66 )
break;
}
if ( & V_4 -> V_30 == & V_56 -> V_79 )
V_4 = NULL ;
V_56 -> V_78 = V_4 ;
}
static void F_50 ( struct V_76 * V_77 , struct V_3 * V_4 )
{
struct V_55 * V_56 = V_77 ? V_77 -> V_56 : NULL ;
if ( ! V_56 )
return;
if ( V_56 -> V_80 == NULL )
V_56 -> V_80 = V_4 ;
}
static void F_51 ( struct V_76 * V_77 , struct V_3 * V_4 )
{
struct V_55 * V_56 = V_77 ? V_77 -> V_56 : NULL ;
if ( ! V_56 )
return;
if ( V_56 -> V_80 != V_4 )
return;
F_49 (req, &connection->transfer_log, tl_requests) {
const unsigned V_41 = V_4 -> V_15 ;
if ( ( V_41 & V_81 ) && ( V_41 & V_67 ) )
break;
}
if ( & V_4 -> V_30 == & V_56 -> V_79 )
V_4 = NULL ;
V_56 -> V_80 = V_4 ;
}
static void F_52 ( struct V_76 * V_77 , struct V_3 * V_4 )
{
struct V_55 * V_56 = V_77 ? V_77 -> V_56 : NULL ;
if ( ! V_56 )
return;
if ( V_56 -> V_82 == NULL )
V_56 -> V_82 = V_4 ;
}
static void F_53 ( struct V_76 * V_77 , struct V_3 * V_4 )
{
struct V_55 * V_56 = V_77 ? V_77 -> V_56 : NULL ;
if ( ! V_56 )
return;
if ( V_56 -> V_82 != V_4 )
return;
F_49 (req, &connection->transfer_log, tl_requests) {
const unsigned V_41 = V_4 -> V_15 ;
if ( ( V_41 & V_81 ) && ! ( V_41 & V_45 ) )
break;
}
if ( & V_4 -> V_30 == & V_56 -> V_79 )
V_4 = NULL ;
V_56 -> V_82 = V_4 ;
}
static void F_54 ( struct V_3 * V_4 , struct V_61 * V_62 ,
int V_83 , int V_84 )
{
struct V_1 * V_2 = V_4 -> V_2 ;
struct V_76 * V_77 = F_40 ( V_2 ) ;
unsigned V_41 = V_4 -> V_15 ;
int V_85 = 0 ;
if ( F_55 ( V_2 ) && ! ( ( V_41 | V_83 ) & V_68 ) )
V_84 |= V_68 ;
V_4 -> V_15 &= ~ V_83 ;
V_4 -> V_15 |= V_84 ;
if ( V_4 -> V_15 == V_41 )
return;
F_56 ( & V_4 -> V_36 ) ;
if ( ! ( V_41 & V_43 ) && ( V_84 & V_43 ) )
F_33 ( & V_4 -> V_35 ) ;
if ( ! ( V_41 & V_67 ) && ( V_84 & V_67 ) ) {
F_57 ( V_2 ) ;
F_33 ( & V_4 -> V_35 ) ;
}
if ( ! ( V_41 & V_66 ) && ( V_84 & V_66 ) ) {
F_33 ( & V_4 -> V_35 ) ;
F_47 ( V_77 , V_4 ) ;
}
if ( ! ( V_41 & V_86 ) && ( V_84 & V_86 ) )
F_56 ( & V_4 -> V_36 ) ;
if ( ! ( V_41 & V_81 ) && ( V_84 & V_81 ) ) {
if ( ! ( V_41 & V_45 ) ) {
F_58 ( V_4 -> V_6 . V_7 >> 9 , & V_2 -> V_87 ) ;
F_52 ( V_77 , V_4 ) ;
}
if ( V_4 -> V_15 & V_67 )
F_50 ( V_77 , V_4 ) ;
}
if ( ! ( V_41 & V_68 ) && ( V_84 & V_68 ) )
F_33 ( & V_4 -> V_35 ) ;
if ( ( V_41 & V_68 ) && ( V_83 & V_68 ) )
++ V_85 ;
if ( ! ( V_41 & V_65 ) && ( V_84 & V_65 ) ) {
F_43 ( V_2 , V_4 -> V_15 & V_43 ) ;
++ V_85 ;
}
if ( ( V_41 & V_43 ) && ( V_83 & V_43 ) ) {
if ( V_4 -> V_15 & V_65 )
F_46 ( & V_4 -> V_36 , F_17 ) ;
else
++ V_85 ;
F_21 ( & V_4 -> V_34 ) ;
}
if ( ( V_41 & V_67 ) && ( V_83 & V_67 ) ) {
F_59 ( V_2 ) ;
++ V_85 ;
V_4 -> V_88 = V_89 ;
F_51 ( V_77 , V_4 ) ;
}
if ( ( V_41 & V_66 ) && ( V_83 & V_66 ) ) {
++ V_85 ;
F_48 ( V_77 , V_4 ) ;
}
if ( ! ( V_41 & V_45 ) && ( V_84 & V_45 ) ) {
if ( V_41 & V_81 )
F_60 ( V_4 -> V_6 . V_7 >> 9 , & V_2 -> V_87 ) ;
if ( V_41 & V_86 )
F_46 ( & V_4 -> V_36 , F_17 ) ;
V_4 -> V_90 = V_89 ;
F_48 ( V_77 , V_4 ) ;
F_51 ( V_77 , V_4 ) ;
F_53 ( V_77 , V_4 ) ;
}
if ( V_4 -> V_6 . V_29 )
F_16 ( & V_2 -> V_40 ) ;
F_42 ( V_4 , V_62 , V_85 ) ;
F_46 ( & V_4 -> V_36 , F_17 ) ;
}
static void F_61 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
char V_91 [ V_92 ] ;
if ( ! F_28 ( & V_54 ) )
return;
F_29 ( V_2 , L_7 ,
( V_4 -> V_15 & V_17 ) ? L_8 : L_9 ,
( unsigned long long ) V_4 -> V_6 . V_24 ,
V_4 -> V_6 . V_7 >> 9 ,
F_62 ( V_2 -> V_93 -> V_94 , V_91 ) ) ;
}
static inline bool F_63 ( struct V_3 * V_4 )
{
return ( V_4 -> V_15 &
( V_17 | V_67 | V_95 | V_96 ) )
== ( V_17 | V_67 ) ;
}
int F_64 ( struct V_3 * V_4 , enum V_97 V_98 ,
struct V_61 * V_62 )
{
struct V_1 * const V_2 = V_4 -> V_2 ;
struct V_76 * const V_77 = F_40 ( V_2 ) ;
struct V_55 * const V_56 = V_77 ? V_77 -> V_56 : NULL ;
struct V_99 * V_100 ;
int V_101 , V_102 = 0 ;
if ( V_62 )
V_62 -> V_11 = NULL ;
switch ( V_98 ) {
default:
F_20 ( V_2 , L_10 , __FILE__ , __LINE__ ) ;
break;
case V_103 :
F_43 ( V_2 , ! ( V_4 -> V_15 & V_44 ) ) ;
F_65 () ;
V_100 = F_66 ( V_56 -> V_99 ) ;
V_101 = V_100 -> V_104 ;
F_67 () ;
V_4 -> V_15 |=
V_101 == V_105 ? V_95 :
V_101 == V_106 ? V_96 : 0 ;
F_54 ( V_4 , V_62 , 0 , V_67 ) ;
break;
case V_107 :
F_43 ( V_2 , ! ( V_4 -> V_15 & V_48 ) ) ;
F_54 ( V_4 , V_62 , 0 , V_43 ) ;
break;
case V_108 :
if ( V_4 -> V_15 & V_17 )
V_2 -> V_109 += V_4 -> V_6 . V_7 >> 9 ;
else
V_2 -> V_110 += V_4 -> V_6 . V_7 >> 9 ;
F_54 ( V_4 , V_62 , V_43 ,
V_111 | V_50 ) ;
break;
case V_112 :
F_54 ( V_4 , V_62 , 0 , V_65 ) ;
break;
case V_113 :
F_61 ( V_2 , V_4 ) ;
F_68 ( V_2 , V_114 ) ;
F_54 ( V_4 , V_62 , V_43 , V_111 ) ;
break;
case V_115 :
F_23 ( V_2 , V_4 -> V_6 . V_24 , V_4 -> V_6 . V_7 ) ;
F_61 ( V_2 , V_4 ) ;
F_68 ( V_2 , V_116 ) ;
case V_117 :
F_54 ( V_4 , V_62 , V_43 , V_111 ) ;
break;
case V_118 :
case V_119 :
F_54 ( V_4 , V_62 , V_43 , V_111 ) ;
break;
case V_120 :
F_43 ( V_2 , F_22 ( & V_4 -> V_6 ) ) ;
F_69 ( & V_2 -> V_47 , & V_4 -> V_6 ) ;
F_70 ( V_121 , & V_2 -> V_122 ) ;
F_43 ( V_2 , V_4 -> V_15 & V_67 ) ;
F_43 ( V_2 , ( V_4 -> V_15 & V_48 ) == 0 ) ;
F_54 ( V_4 , V_62 , 0 , V_66 ) ;
V_4 -> V_31 . V_123 = V_124 ;
F_71 ( & V_56 -> V_57 ,
& V_4 -> V_31 ) ;
break;
case V_125 :
F_43 ( V_2 , F_22 ( & V_4 -> V_6 ) ) ;
F_69 ( & V_2 -> V_46 , & V_4 -> V_6 ) ;
F_70 ( V_121 , & V_2 -> V_122 ) ;
F_43 ( V_2 , V_4 -> V_15 & V_67 ) ;
F_54 ( V_4 , V_62 , 0 , V_66 | V_86 ) ;
V_4 -> V_31 . V_123 = V_126 ;
F_71 ( & V_56 -> V_57 ,
& V_4 -> V_31 ) ;
F_65 () ;
V_100 = F_66 ( V_56 -> V_99 ) ;
V_101 = V_100 -> V_127 ;
F_67 () ;
if ( V_56 -> V_59 >= V_101 )
F_32 ( V_56 ) ;
break;
case V_128 :
F_54 ( V_4 , V_62 , 0 , V_66 ) ;
V_4 -> V_31 . V_123 = V_129 ;
F_71 ( & V_56 -> V_57 ,
& V_4 -> V_31 ) ;
break;
case V_130 :
case V_131 :
case V_132 :
F_54 ( V_4 , V_62 , V_66 , 0 ) ;
break;
case V_133 :
if ( F_63 ( V_4 ) )
F_54 ( V_4 , V_62 , V_66 | V_67 ,
V_81 | V_49 ) ;
else
F_54 ( V_4 , V_62 , V_66 , V_81 ) ;
break;
case V_134 :
F_54 ( V_4 , V_62 , V_66 , V_45 ) ;
break;
case V_135 :
F_54 ( V_4 , V_62 ,
V_49 | V_67 | V_68 ,
V_45 ) ;
break;
case V_136 :
F_43 ( V_2 , V_4 -> V_15 & V_67 ) ;
F_43 ( V_2 , V_4 -> V_15 & V_95 ) ;
F_54 ( V_4 , V_62 , V_67 , V_45 | V_49 ) ;
break;
case V_137 :
V_4 -> V_15 |= V_51 ;
case V_138 :
goto V_139;
case V_140 :
F_43 ( V_2 , V_4 -> V_15 & V_96 ) ;
V_139:
F_54 ( V_4 , V_62 , V_67 , V_49 ) ;
break;
case V_141 :
F_43 ( V_2 , V_4 -> V_15 & V_95 ) ;
F_43 ( V_2 , V_4 -> V_15 & V_67 ) ;
V_4 -> V_15 |= V_42 ;
if ( V_4 -> V_6 . V_29 )
F_16 ( & V_2 -> V_40 ) ;
break;
case V_142 :
F_54 ( V_4 , V_62 , V_49 | V_67 , 0 ) ;
break;
case V_143 :
if ( ! ( V_4 -> V_15 & V_111 ) )
break;
F_54 ( V_4 , V_62 , V_68 , 0 ) ;
break;
case V_144 :
if ( ! ( V_4 -> V_15 & V_111 ) )
break;
F_54 ( V_4 , V_62 ,
V_68 | V_111 ,
V_43 ) ;
V_102 = V_145 ;
if ( F_3 ( V_4 -> V_5 ) == V_16 )
V_102 = V_146 ;
F_72 ( V_2 ) ;
V_4 -> V_31 . V_123 = V_147 ;
F_71 ( & V_56 -> V_57 ,
& V_4 -> V_31 ) ;
break;
case V_148 :
if ( ! ( V_4 -> V_15 & V_17 ) && ! V_4 -> V_31 . V_123 ) {
F_54 ( V_4 , V_62 , V_68 , 0 ) ;
break;
}
if ( ! ( V_4 -> V_15 & V_49 ) ) {
F_54 ( V_4 , V_62 , V_68 , V_66 | V_67 ) ;
if ( V_4 -> V_31 . V_123 ) {
F_71 ( & V_56 -> V_57 ,
& V_4 -> V_31 ) ;
V_102 = V_4 -> V_15 & V_17 ? V_146 : V_145 ;
}
break;
}
case V_149 :
if ( ! ( V_4 -> V_15 & V_17 ) )
break;
if ( V_4 -> V_15 & V_67 ) {
F_20 ( V_2 , L_11 ) ;
}
F_54 ( V_4 , V_62 , V_68 ,
( V_4 -> V_15 & V_44 ) ? V_45 : 0 ) ;
break;
case V_150 :
F_43 ( V_2 , V_4 -> V_15 & V_67 ) ;
F_54 ( V_4 , V_62 , V_67 , V_49 | V_45 ) ;
break;
case V_151 :
F_32 ( V_56 ) ;
F_54 ( V_4 , V_62 , 0 , V_49 | V_45 ) ;
break;
} ;
return V_102 ;
}
static bool F_73 ( struct V_1 * V_2 , T_1 V_24 , int V_7 )
{
unsigned long V_152 , V_153 ;
T_1 V_154 , V_155 ;
if ( V_2 -> V_156 . V_157 == V_158 )
return true ;
if ( V_2 -> V_156 . V_157 != V_159 )
return false ;
V_154 = V_24 + ( V_7 >> 9 ) - 1 ;
V_155 = F_74 ( V_2 -> V_160 ) ;
F_43 ( V_2 , V_24 < V_155 ) ;
F_43 ( V_2 , V_154 < V_155 ) ;
V_152 = F_75 ( V_24 ) ;
V_153 = F_75 ( V_154 ) ;
return F_76 ( V_2 , V_152 , V_153 ) == 0 ;
}
static bool F_77 ( struct V_1 * V_2 , T_1 V_24 ,
enum V_161 V_162 )
{
struct V_163 * V_164 ;
int V_165 ;
switch ( V_162 ) {
case V_166 :
V_164 = V_2 -> V_93 -> V_94 -> V_167 -> V_168 -> V_163 ;
return F_78 ( V_164 ) ;
case V_169 :
return F_19 ( & V_2 -> V_170 ) >
F_19 ( & V_2 -> V_171 ) + F_19 ( & V_2 -> V_172 ) ;
case V_173 :
case V_174 :
case V_175 :
case V_176 :
case V_177 :
case V_178 :
V_165 = ( V_162 - V_173 + 15 ) ;
return ( V_24 >> ( V_165 - 9 ) ) & 1 ;
case V_179 :
return F_79 ( V_180 , & V_2 -> V_122 ) ;
case V_181 :
return true ;
case V_182 :
default:
return false ;
}
}
static void F_80 ( struct V_3 * V_4 )
{
F_81 ( V_183 ) ;
struct V_1 * V_2 = V_4 -> V_2 ;
struct V_39 * V_6 ;
T_1 V_24 = V_4 -> V_6 . V_24 ;
int V_7 = V_4 -> V_6 . V_7 ;
for (; ; ) {
F_82 (i, &device->write_requests, sector, size) {
if ( V_6 -> V_74 )
continue;
break;
}
if ( ! V_6 )
break;
F_83 ( & V_2 -> V_40 , & V_183 , V_184 ) ;
V_6 -> V_29 = true ;
F_84 ( & V_2 -> V_185 -> V_186 ) ;
F_85 () ;
F_86 ( & V_2 -> V_185 -> V_186 ) ;
}
F_87 ( & V_2 -> V_40 , & V_183 ) ;
}
static void F_88 ( struct V_1 * V_2 )
{
struct V_55 * V_56 = F_40 ( V_2 ) -> V_56 ;
struct V_99 * V_100 ;
bool V_187 = false ;
enum V_188 V_189 ;
F_65 () ;
V_100 = F_66 ( V_56 -> V_99 ) ;
V_189 = V_100 ? V_100 -> V_189 : V_190 ;
F_67 () ;
if ( V_189 == V_190 ||
V_56 -> V_191 < 96 )
return;
if ( V_189 == V_192 && V_2 -> V_156 . V_193 == V_194 )
return;
if ( ! F_25 ( V_2 , V_158 ) )
return;
if ( V_100 -> V_195 &&
F_19 ( & V_2 -> V_87 ) >= V_100 -> V_195 ) {
F_89 ( V_2 , L_12 ) ;
V_187 = true ;
}
if ( V_2 -> V_196 -> V_197 >= V_100 -> V_198 ) {
F_89 ( V_2 , L_13 ) ;
V_187 = true ;
}
if ( V_187 ) {
F_32 ( F_40 ( V_2 ) -> V_56 ) ;
if ( V_189 == V_192 )
F_90 ( F_91 ( V_2 , V_193 , V_194 ) , 0 , NULL ) ;
else
F_90 ( F_91 ( V_2 , V_193 , V_199 ) , 0 , NULL ) ;
}
F_27 ( V_2 ) ;
}
static bool F_92 ( struct V_3 * V_4 )
{
struct V_1 * V_2 = V_4 -> V_2 ;
enum V_161 V_162 ;
if ( V_4 -> V_69 ) {
if ( ! F_73 ( V_2 ,
V_4 -> V_6 . V_24 , V_4 -> V_6 . V_7 ) ) {
F_93 ( V_4 -> V_69 ) ;
V_4 -> V_69 = NULL ;
F_27 ( V_2 ) ;
}
}
if ( V_2 -> V_156 . V_200 != V_158 )
return false ;
if ( V_4 -> V_69 == NULL )
return true ;
F_65 () ;
V_162 = F_66 ( V_2 -> V_93 -> V_201 ) -> V_202 ;
F_67 () ;
if ( V_162 == V_182 && V_4 -> V_69 )
return false ;
if ( F_77 ( V_2 , V_4 -> V_6 . V_24 , V_162 ) ) {
if ( V_4 -> V_69 ) {
F_93 ( V_4 -> V_69 ) ;
V_4 -> V_69 = NULL ;
F_27 ( V_2 ) ;
}
return true ;
}
return false ;
}
bool F_94 ( union V_203 V_41 )
{
return V_41 . V_200 == V_158 ||
( V_41 . V_200 >= V_159 &&
V_41 . V_193 >= V_204 &&
V_41 . V_193 < V_194 ) ;
}
static bool F_95 ( union V_203 V_41 )
{
return V_41 . V_193 == V_194 || V_41 . V_193 == V_205 ;
}
static int F_96 ( struct V_3 * V_4 )
{
struct V_1 * V_2 = V_4 -> V_2 ;
int V_206 , V_207 ;
V_206 = F_94 ( V_2 -> V_156 ) ;
V_207 = F_95 ( V_2 -> V_156 ) ;
if ( F_97 ( V_4 -> V_6 . V_7 == 0 ) ) {
F_43 ( V_2 , V_4 -> V_5 -> V_71 & V_208 ) ;
if ( V_206 )
F_98 ( V_4 , V_151 ) ;
return V_206 ;
}
if ( ! V_206 && ! V_207 )
return 0 ;
F_43 ( V_2 , ! ( V_206 && V_207 ) ) ;
if ( V_206 ) {
F_98 ( V_4 , V_103 ) ;
F_98 ( V_4 , V_125 ) ;
} else if ( F_23 ( V_2 , V_4 -> V_6 . V_24 , V_4 -> V_6 . V_7 ) )
F_98 ( V_4 , V_128 ) ;
return V_206 ;
}
static void F_99 ( struct V_3 * V_4 )
{
struct V_209 * V_210 = V_4 -> V_2 -> V_93 -> V_94 ;
if ( F_100 ( V_210 , V_4 -> V_6 . V_24 , V_4 -> V_6 . V_7 >> 9 ,
V_14 , 0 ) )
V_4 -> V_69 -> V_63 = - V_73 ;
F_35 ( V_4 -> V_69 ) ;
}
static void
F_101 ( struct V_3 * V_4 )
{
struct V_1 * V_2 = V_4 -> V_2 ;
struct V_11 * V_11 = V_4 -> V_69 ;
unsigned int type ;
if ( F_9 ( V_11 ) != V_70 )
type = V_211 ;
else if ( V_11 -> V_71 & V_72 )
type = V_212 ;
else
type = V_213 ;
V_11 -> V_214 = V_2 -> V_93 -> V_94 ;
if ( F_72 ( V_2 ) ) {
if ( F_102 ( V_2 , type ) )
F_103 ( V_11 ) ;
else if ( F_9 ( V_11 ) == V_20 ||
F_9 ( V_11 ) == V_22 )
F_99 ( V_4 ) ;
else
F_104 ( V_11 ) ;
F_27 ( V_2 ) ;
} else
F_103 ( V_11 ) ;
}
static void F_105 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
F_86 ( & V_2 -> V_185 -> V_186 ) ;
F_106 ( & V_4 -> V_30 , & V_2 -> V_215 . V_216 ) ;
F_106 ( & V_4 -> V_33 ,
& V_2 -> V_217 [ 1 ] ) ;
F_84 ( & V_2 -> V_185 -> V_186 ) ;
F_107 ( V_2 -> V_215 . V_218 , & V_2 -> V_215 . V_219 ) ;
F_16 ( & V_2 -> V_220 ) ;
}
static struct V_3 *
F_108 ( struct V_1 * V_2 , struct V_11 * V_11 , unsigned long V_10 )
{
const int V_221 = F_3 ( V_11 ) ;
struct V_3 * V_4 ;
V_4 = F_6 ( V_2 , V_11 ) ;
if ( ! V_4 ) {
F_36 ( V_2 ) ;
F_20 ( V_2 , L_14 ) ;
V_11 -> V_63 = - V_222 ;
F_35 ( V_11 ) ;
return F_109 ( - V_222 ) ;
}
V_4 -> V_10 = V_10 ;
if ( ! F_72 ( V_2 ) ) {
F_93 ( V_4 -> V_69 ) ;
V_4 -> V_69 = NULL ;
}
F_1 ( V_2 , V_4 ) ;
if ( ( F_9 ( V_11 ) & V_20 ) ||
( F_9 ( V_11 ) & V_22 ) )
goto V_223;
if ( V_221 == V_16 && V_4 -> V_69 && V_4 -> V_6 . V_7
&& ! F_110 ( V_224 , & V_2 -> V_122 ) ) {
if ( ! F_111 ( V_2 , & V_4 -> V_6 ) )
goto V_223;
V_4 -> V_15 |= V_52 ;
V_4 -> V_225 = V_89 ;
}
return V_4 ;
V_223:
F_33 ( & V_2 -> V_226 ) ;
F_105 ( V_2 , V_4 ) ;
return NULL ;
}
static bool F_112 ( struct V_1 * V_2 )
{
const union V_203 V_41 = V_2 -> V_156 ;
return V_41 . V_157 == V_158 || V_41 . V_200 == V_158 ;
}
static void F_113 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_227 * V_185 = V_2 -> V_185 ;
const int V_221 = F_3 ( V_4 -> V_5 ) ;
struct V_61 V_62 = { NULL , } ;
bool V_228 = false ;
bool V_229 = false ;
F_86 ( & V_185 -> V_186 ) ;
if ( V_221 == V_16 ) {
F_80 ( V_4 ) ;
F_88 ( V_2 ) ;
}
if ( F_55 ( V_2 ) ) {
V_4 -> V_15 |= V_42 ;
if ( V_4 -> V_69 ) {
F_93 ( V_4 -> V_69 ) ;
V_4 -> V_69 = NULL ;
F_27 ( V_2 ) ;
}
goto V_230;
}
if ( V_221 != V_16 ) {
if ( ! F_92 ( V_4 ) && ! V_4 -> V_69 )
goto V_231;
}
V_4 -> V_23 = F_19 ( & F_40 ( V_2 ) -> V_56 -> V_60 ) ;
if ( F_114 ( V_4 -> V_6 . V_7 != 0 ) ) {
if ( V_221 == V_16 )
F_40 ( V_2 ) -> V_56 -> V_59 ++ ;
F_106 ( & V_4 -> V_30 , & F_40 ( V_2 ) -> V_56 -> V_79 ) ;
}
if ( V_221 == V_16 ) {
if ( V_4 -> V_69 && ! F_112 ( V_2 ) ) {
F_93 ( V_4 -> V_69 ) ;
V_4 -> V_69 = NULL ;
F_27 ( V_2 ) ;
goto V_231;
}
if ( ! F_96 ( V_4 ) )
V_228 = true ;
} else {
if ( V_4 -> V_69 == NULL ) {
F_98 ( V_4 , V_103 ) ;
F_98 ( V_4 , V_120 ) ;
} else
V_228 = true ;
}
if ( F_41 ( & V_4 -> V_33 ) )
F_106 ( & V_4 -> V_33 ,
& V_2 -> V_217 [ V_221 == V_16 ] ) ;
if ( V_4 -> V_69 ) {
V_4 -> V_232 = V_89 ;
F_106 ( & V_4 -> V_34 ,
& V_2 -> V_233 [ V_221 == V_16 ] ) ;
F_98 ( V_4 , V_107 ) ;
V_229 = true ;
} else if ( V_228 ) {
V_231:
if ( F_28 ( & V_54 ) )
F_20 ( V_2 , L_15 ,
( unsigned long long ) V_4 -> V_6 . V_24 , V_4 -> V_6 . V_7 >> 9 ) ;
}
V_230:
F_42 ( V_4 , & V_62 , 1 ) ;
F_84 ( & V_185 -> V_186 ) ;
if ( V_229 )
F_101 ( V_4 ) ;
if ( V_62 . V_11 )
F_34 ( V_2 , & V_62 ) ;
}
void F_115 ( struct V_1 * V_2 , struct V_11 * V_11 , unsigned long V_10 )
{
struct V_3 * V_4 = F_108 ( V_2 , V_11 , V_10 ) ;
if ( F_116 ( V_4 ) )
return;
F_113 ( V_2 , V_4 ) ;
}
static void F_117 ( struct V_1 * V_2 , struct V_234 * V_235 )
{
struct V_3 * V_4 , * V_236 ;
F_118 (req, tmp, incoming, tl_requests) {
const int V_221 = F_3 ( V_4 -> V_5 ) ;
if ( V_221 == V_16
&& V_4 -> V_69 && V_4 -> V_6 . V_7
&& ! F_110 ( V_224 , & V_2 -> V_122 ) ) {
if ( ! F_111 ( V_2 , & V_4 -> V_6 ) )
continue;
V_4 -> V_15 |= V_52 ;
V_4 -> V_225 = V_89 ;
F_119 ( & V_2 -> V_226 ) ;
}
F_21 ( & V_4 -> V_30 ) ;
F_113 ( V_2 , V_4 ) ;
}
}
static bool F_120 ( struct V_1 * V_2 ,
struct V_234 * V_235 ,
struct V_234 * V_237 ,
struct V_234 * V_238 )
{
struct V_3 * V_4 , * V_236 ;
int V_239 = 0 ;
int V_240 ;
F_86 ( & V_2 -> V_241 ) ;
F_118 (req, tmp, incoming, tl_requests) {
V_240 = F_121 ( V_2 , & V_4 -> V_6 ) ;
if ( V_240 == - V_242 )
break;
if ( V_240 == - V_243 )
V_239 = 1 ;
if ( V_240 )
F_122 ( & V_4 -> V_30 , V_238 ) ;
else
F_122 ( & V_4 -> V_30 , V_237 ) ;
}
F_84 ( & V_2 -> V_241 ) ;
if ( V_239 )
F_16 ( & V_2 -> V_220 ) ;
return ! F_41 ( V_237 ) ;
}
void F_123 ( struct V_1 * V_2 , struct V_234 * V_237 )
{
struct V_3 * V_4 , * V_236 ;
F_118 (req, tmp, pending, tl_requests) {
V_4 -> V_15 |= V_52 ;
V_4 -> V_225 = V_89 ;
F_119 ( & V_2 -> V_226 ) ;
F_21 ( & V_4 -> V_30 ) ;
F_113 ( V_2 , V_4 ) ;
}
}
void F_124 ( struct V_244 * V_245 )
{
struct V_1 * V_2 = F_18 ( V_245 , struct V_1 , V_215 . V_219 ) ;
F_125 ( V_235 ) ;
F_125 ( V_237 ) ;
F_125 ( V_246 ) ;
F_86 ( & V_2 -> V_185 -> V_186 ) ;
F_126 ( & V_2 -> V_215 . V_216 , & V_235 ) ;
F_84 ( & V_2 -> V_185 -> V_186 ) ;
for (; ; ) {
F_81 ( V_183 ) ;
F_127 ( & V_246 , & V_235 ) ;
F_117 ( V_2 , & V_235 ) ;
if ( F_41 ( & V_235 ) )
break;
for (; ; ) {
F_83 ( & V_2 -> V_220 , & V_183 , V_184 ) ;
F_127 ( & V_246 , & V_235 ) ;
F_120 ( V_2 , & V_235 , & V_237 , & V_246 ) ;
if ( ! F_41 ( & V_237 ) )
break;
F_85 () ;
if ( ! F_41 ( & V_235 ) )
continue;
F_86 ( & V_2 -> V_185 -> V_186 ) ;
F_126 ( & V_2 -> V_215 . V_216 , & V_235 ) ;
F_84 ( & V_2 -> V_185 -> V_186 ) ;
}
F_87 ( & V_2 -> V_220 , & V_183 ) ;
while ( F_41 ( & V_235 ) ) {
F_125 ( V_247 ) ;
F_125 ( V_248 ) ;
bool V_249 ;
if ( F_41 ( & V_2 -> V_215 . V_216 ) )
break;
F_86 ( & V_2 -> V_185 -> V_186 ) ;
F_126 ( & V_2 -> V_215 . V_216 , & V_248 ) ;
F_84 ( & V_2 -> V_185 -> V_186 ) ;
if ( F_41 ( & V_248 ) )
break;
V_249 = F_120 ( V_2 , & V_248 , & V_247 , & V_246 ) ;
F_126 ( & V_247 , & V_237 ) ;
F_126 ( & V_248 , & V_235 ) ;
if ( ! V_249 )
break;
}
F_128 ( V_2 ) ;
F_123 ( V_2 , & V_237 ) ;
}
}
T_2 F_129 ( struct V_250 * V_251 , struct V_11 * V_11 )
{
struct V_1 * V_2 = (struct V_1 * ) V_251 -> V_252 ;
unsigned long V_10 ;
F_130 ( V_251 , & V_11 , V_251 -> V_253 ) ;
V_10 = V_89 ;
F_43 ( V_2 , F_131 ( V_11 -> V_25 . V_27 , 512 ) ) ;
F_132 ( V_2 ) ;
F_115 ( V_2 , V_11 , V_10 ) ;
return V_254 ;
}
static bool F_133 ( struct V_3 * V_255 ,
struct V_55 * V_56 ,
unsigned long V_256 , unsigned long V_257 ,
unsigned int V_258 , unsigned int V_259 )
{
struct V_1 * V_2 = V_255 -> V_2 ;
if ( ! F_134 ( V_256 , V_255 -> V_260 + V_257 ) )
return false ;
if ( F_135 ( V_256 , V_56 -> V_261 , V_56 -> V_261 + V_257 ) )
return false ;
if ( V_255 -> V_15 & V_67 ) {
F_29 ( V_2 , L_16 ,
F_136 ( V_256 - V_255 -> V_260 ) , V_258 , V_259 ) ;
return true ;
}
if ( V_255 -> V_23 == V_56 -> V_262 . V_263 ) {
F_29 ( V_2 ,
L_17 ,
F_136 ( V_256 - V_255 -> V_260 ) , V_258 , V_259 ) ;
return false ;
}
if ( F_134 ( V_256 , V_56 -> V_262 . V_264 + V_257 ) ) {
F_29 ( V_2 , L_18 ,
V_56 -> V_262 . V_264 , V_256 ,
F_136 ( V_256 - V_56 -> V_262 . V_264 ) , V_258 , V_259 ) ;
return true ;
}
return false ;
}
void F_137 ( unsigned long V_265 )
{
struct V_1 * V_2 = (struct V_1 * ) V_265 ;
struct V_55 * V_56 = F_40 ( V_2 ) -> V_56 ;
struct V_3 * V_266 , * V_267 , * V_268 ;
struct V_99 * V_100 ;
unsigned long V_269 ;
unsigned long V_257 = 0 , V_270 = 0 , V_271 , V_272 ;
unsigned long V_256 ;
unsigned int V_258 = 0 , V_259 = 0 ;
F_65 () ;
V_100 = F_66 ( V_56 -> V_99 ) ;
if ( V_100 && V_2 -> V_156 . V_193 >= V_273 ) {
V_258 = V_100 -> V_258 ;
V_259 = V_100 -> V_259 ;
}
if ( F_72 ( V_2 ) ) {
V_270 = F_66 ( V_2 -> V_93 -> V_201 ) -> V_274 * V_275 / 10 ;
F_27 ( V_2 ) ;
}
F_67 () ;
V_257 = V_259 * V_275 / 10 * V_258 ;
V_271 = F_138 ( V_270 , V_257 ) ;
if ( ! V_271 )
return;
V_256 = V_89 ;
V_272 = V_256 + V_271 ;
F_86 ( & V_2 -> V_185 -> V_186 ) ;
V_266 = F_139 ( & V_2 -> V_233 [ 0 ] , struct V_3 , V_34 ) ;
V_267 = F_139 ( & V_2 -> V_233 [ 1 ] , struct V_3 , V_34 ) ;
V_268 = V_56 -> V_80 ;
if ( ! V_268 )
V_268 = V_56 -> V_82 ;
if ( V_268 && V_268 -> V_2 != V_2 )
V_268 = NULL ;
if ( V_268 == NULL && V_267 == NULL && V_266 == NULL )
goto V_230;
V_269 =
( V_267 && V_266 )
? ( F_140 ( V_267 -> V_232 , V_266 -> V_232 )
? V_267 -> V_232 : V_266 -> V_232 )
: V_267 ? V_267 -> V_232
: V_266 ? V_266 -> V_232 : V_256 ;
if ( V_257 && V_268 && F_133 ( V_268 , V_56 , V_256 , V_257 , V_258 , V_259 ) )
F_141 ( V_56 , F_142 ( V_193 , V_276 ) , V_277 | V_278 ) ;
if ( V_270 && V_269 != V_256 &&
F_134 ( V_256 , V_269 + V_270 ) &&
! F_135 ( V_256 , V_2 -> V_279 , V_2 -> V_279 + V_270 ) ) {
F_29 ( V_2 , L_19 ) ;
F_68 ( V_2 , V_280 ) ;
}
V_257 = ( V_257 && V_268 && F_140 ( V_256 , V_268 -> V_260 + V_257 ) )
? V_268 -> V_260 + V_257 : V_256 + V_271 ;
V_270 = ( V_270 && V_269 != V_256 && F_140 ( V_256 , V_269 + V_270 ) )
? V_269 + V_270 : V_256 + V_271 ;
V_272 = F_140 ( V_257 , V_270 ) ? V_257 : V_270 ;
V_230:
F_84 ( & V_2 -> V_185 -> V_186 ) ;
F_143 ( & V_2 -> V_281 , V_272 ) ;
}
