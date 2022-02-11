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
V_62 -> V_11 -> V_63 = F_35 ( V_62 -> error ) ;
F_36 ( V_62 -> V_11 ) ;
F_37 ( V_2 ) ;
}
static
void F_38 ( struct V_3 * V_4 , struct V_61 * V_62 )
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
error = F_39 ( V_4 -> V_69 ) ;
if ( F_40 ( F_9 ( V_4 -> V_5 ) ) &&
V_4 -> V_23 == F_19 ( & F_41 ( V_2 ) -> V_56 -> V_60 ) )
F_32 ( F_41 ( V_2 ) -> V_56 ) ;
F_4 ( V_2 , V_4 ) ;
if ( ! V_64 &&
F_9 ( V_4 -> V_5 ) == V_70 &&
! ( V_4 -> V_5 -> V_71 & V_72 ) &&
! F_42 ( & V_4 -> V_30 ) )
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
static void F_43 ( struct V_3 * V_4 , struct V_61 * V_62 , int V_75 )
{
struct V_1 * V_2 = V_4 -> V_2 ;
F_44 ( V_2 , V_62 || ( V_4 -> V_15 & V_42 ) ) ;
if ( ! V_75 )
return;
if ( ! F_45 ( V_75 , & V_4 -> V_35 ) )
return;
F_38 ( V_4 , V_62 ) ;
if ( V_4 -> V_15 & V_65 )
return;
if ( V_4 -> V_15 & V_42 ) {
F_46 ( V_4 ) ;
return;
}
F_47 ( & V_4 -> V_36 , F_17 ) ;
}
static void F_48 ( struct V_76 * V_77 , struct V_3 * V_4 )
{
struct V_55 * V_56 = V_77 ? V_77 -> V_56 : NULL ;
if ( ! V_56 )
return;
if ( V_56 -> V_78 == NULL )
V_56 -> V_78 = V_4 ;
}
static void F_49 ( struct V_76 * V_77 , struct V_3 * V_4 )
{
struct V_55 * V_56 = V_77 ? V_77 -> V_56 : NULL ;
if ( ! V_56 )
return;
if ( V_56 -> V_78 != V_4 )
return;
F_50 (req, &connection->transfer_log, tl_requests) {
const unsigned V_41 = V_4 -> V_15 ;
if ( V_41 & V_66 )
break;
}
if ( & V_4 -> V_30 == & V_56 -> V_79 )
V_4 = NULL ;
V_56 -> V_78 = V_4 ;
}
static void F_51 ( struct V_76 * V_77 , struct V_3 * V_4 )
{
struct V_55 * V_56 = V_77 ? V_77 -> V_56 : NULL ;
if ( ! V_56 )
return;
if ( V_56 -> V_80 == NULL )
V_56 -> V_80 = V_4 ;
}
static void F_52 ( struct V_76 * V_77 , struct V_3 * V_4 )
{
struct V_55 * V_56 = V_77 ? V_77 -> V_56 : NULL ;
if ( ! V_56 )
return;
if ( V_56 -> V_80 != V_4 )
return;
F_50 (req, &connection->transfer_log, tl_requests) {
const unsigned V_41 = V_4 -> V_15 ;
if ( ( V_41 & V_81 ) && ( V_41 & V_67 ) )
break;
}
if ( & V_4 -> V_30 == & V_56 -> V_79 )
V_4 = NULL ;
V_56 -> V_80 = V_4 ;
}
static void F_53 ( struct V_76 * V_77 , struct V_3 * V_4 )
{
struct V_55 * V_56 = V_77 ? V_77 -> V_56 : NULL ;
if ( ! V_56 )
return;
if ( V_56 -> V_82 == NULL )
V_56 -> V_82 = V_4 ;
}
static void F_54 ( struct V_76 * V_77 , struct V_3 * V_4 )
{
struct V_55 * V_56 = V_77 ? V_77 -> V_56 : NULL ;
if ( ! V_56 )
return;
if ( V_56 -> V_82 != V_4 )
return;
F_50 (req, &connection->transfer_log, tl_requests) {
const unsigned V_41 = V_4 -> V_15 ;
if ( ( V_41 & V_81 ) && ! ( V_41 & V_45 ) )
break;
}
if ( & V_4 -> V_30 == & V_56 -> V_79 )
V_4 = NULL ;
V_56 -> V_82 = V_4 ;
}
static void F_55 ( struct V_3 * V_4 , struct V_61 * V_62 ,
int V_83 , int V_84 )
{
struct V_1 * V_2 = V_4 -> V_2 ;
struct V_76 * V_77 = F_41 ( V_2 ) ;
unsigned V_41 = V_4 -> V_15 ;
int V_85 = 0 ;
if ( F_56 ( V_2 ) && ! ( ( V_41 | V_83 ) & V_68 ) )
V_84 |= V_68 ;
V_4 -> V_15 &= ~ V_83 ;
V_4 -> V_15 |= V_84 ;
if ( V_4 -> V_15 == V_41 )
return;
F_57 ( & V_4 -> V_36 ) ;
if ( ! ( V_41 & V_43 ) && ( V_84 & V_43 ) )
F_33 ( & V_4 -> V_35 ) ;
if ( ! ( V_41 & V_67 ) && ( V_84 & V_67 ) ) {
F_58 ( V_2 ) ;
F_33 ( & V_4 -> V_35 ) ;
}
if ( ! ( V_41 & V_66 ) && ( V_84 & V_66 ) ) {
F_33 ( & V_4 -> V_35 ) ;
F_48 ( V_77 , V_4 ) ;
}
if ( ! ( V_41 & V_86 ) && ( V_84 & V_86 ) )
F_57 ( & V_4 -> V_36 ) ;
if ( ! ( V_41 & V_81 ) && ( V_84 & V_81 ) ) {
if ( ! ( V_41 & V_45 ) ) {
F_59 ( V_4 -> V_6 . V_7 >> 9 , & V_2 -> V_87 ) ;
F_53 ( V_77 , V_4 ) ;
}
if ( V_4 -> V_15 & V_67 )
F_51 ( V_77 , V_4 ) ;
}
if ( ! ( V_41 & V_68 ) && ( V_84 & V_68 ) )
F_33 ( & V_4 -> V_35 ) ;
if ( ( V_41 & V_68 ) && ( V_83 & V_68 ) )
++ V_85 ;
if ( ! ( V_41 & V_65 ) && ( V_84 & V_65 ) ) {
F_44 ( V_2 , V_4 -> V_15 & V_43 ) ;
++ V_85 ;
}
if ( ( V_41 & V_43 ) && ( V_83 & V_43 ) ) {
if ( V_4 -> V_15 & V_65 )
F_47 ( & V_4 -> V_36 , F_17 ) ;
else
++ V_85 ;
F_21 ( & V_4 -> V_34 ) ;
}
if ( ( V_41 & V_67 ) && ( V_83 & V_67 ) ) {
F_60 ( V_2 ) ;
++ V_85 ;
V_4 -> V_88 = V_89 ;
F_52 ( V_77 , V_4 ) ;
}
if ( ( V_41 & V_66 ) && ( V_83 & V_66 ) ) {
++ V_85 ;
F_49 ( V_77 , V_4 ) ;
}
if ( ! ( V_41 & V_45 ) && ( V_84 & V_45 ) ) {
if ( V_41 & V_81 )
F_61 ( V_4 -> V_6 . V_7 >> 9 , & V_2 -> V_87 ) ;
if ( V_41 & V_86 )
F_47 ( & V_4 -> V_36 , F_17 ) ;
V_4 -> V_90 = V_89 ;
F_49 ( V_77 , V_4 ) ;
F_52 ( V_77 , V_4 ) ;
F_54 ( V_77 , V_4 ) ;
}
if ( V_4 -> V_6 . V_29 )
F_16 ( & V_2 -> V_40 ) ;
F_43 ( V_4 , V_62 , V_85 ) ;
F_47 ( & V_4 -> V_36 , F_17 ) ;
}
static void F_62 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
char V_91 [ V_92 ] ;
if ( ! F_28 ( & V_54 ) )
return;
F_29 ( V_2 , L_7 ,
( V_4 -> V_15 & V_17 ) ? L_8 : L_9 ,
( unsigned long long ) V_4 -> V_6 . V_24 ,
V_4 -> V_6 . V_7 >> 9 ,
F_63 ( V_2 -> V_93 -> V_94 , V_91 ) ) ;
}
static inline bool F_64 ( struct V_3 * V_4 )
{
return ( V_4 -> V_15 &
( V_17 | V_67 | V_95 | V_96 ) )
== ( V_17 | V_67 ) ;
}
int F_65 ( struct V_3 * V_4 , enum V_97 V_98 ,
struct V_61 * V_62 )
{
struct V_1 * const V_2 = V_4 -> V_2 ;
struct V_76 * const V_77 = F_41 ( V_2 ) ;
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
F_44 ( V_2 , ! ( V_4 -> V_15 & V_44 ) ) ;
F_66 () ;
V_100 = F_67 ( V_56 -> V_99 ) ;
V_101 = V_100 -> V_104 ;
F_68 () ;
V_4 -> V_15 |=
V_101 == V_105 ? V_95 :
V_101 == V_106 ? V_96 : 0 ;
F_55 ( V_4 , V_62 , 0 , V_67 ) ;
break;
case V_107 :
F_44 ( V_2 , ! ( V_4 -> V_15 & V_48 ) ) ;
F_55 ( V_4 , V_62 , 0 , V_43 ) ;
break;
case V_108 :
if ( V_4 -> V_15 & V_17 )
V_2 -> V_109 += V_4 -> V_6 . V_7 >> 9 ;
else
V_2 -> V_110 += V_4 -> V_6 . V_7 >> 9 ;
F_55 ( V_4 , V_62 , V_43 ,
V_111 | V_50 ) ;
break;
case V_112 :
F_55 ( V_4 , V_62 , 0 , V_65 ) ;
break;
case V_113 :
F_62 ( V_2 , V_4 ) ;
F_69 ( V_2 , V_114 ) ;
F_55 ( V_4 , V_62 , V_43 , V_111 ) ;
break;
case V_115 :
F_23 ( V_2 , V_4 -> V_6 . V_24 , V_4 -> V_6 . V_7 ) ;
F_62 ( V_2 , V_4 ) ;
F_69 ( V_2 , V_116 ) ;
case V_117 :
F_55 ( V_4 , V_62 , V_43 , V_111 ) ;
break;
case V_118 :
case V_119 :
F_55 ( V_4 , V_62 , V_43 , V_111 ) ;
break;
case V_120 :
F_44 ( V_2 , F_22 ( & V_4 -> V_6 ) ) ;
F_70 ( & V_2 -> V_47 , & V_4 -> V_6 ) ;
F_71 ( V_121 , & V_2 -> V_122 ) ;
F_44 ( V_2 , V_4 -> V_15 & V_67 ) ;
F_44 ( V_2 , ( V_4 -> V_15 & V_48 ) == 0 ) ;
F_55 ( V_4 , V_62 , 0 , V_66 ) ;
V_4 -> V_31 . V_123 = V_124 ;
F_72 ( & V_56 -> V_57 ,
& V_4 -> V_31 ) ;
break;
case V_125 :
F_44 ( V_2 , F_22 ( & V_4 -> V_6 ) ) ;
F_70 ( & V_2 -> V_46 , & V_4 -> V_6 ) ;
F_71 ( V_121 , & V_2 -> V_122 ) ;
F_44 ( V_2 , V_4 -> V_15 & V_67 ) ;
F_55 ( V_4 , V_62 , 0 , V_66 | V_86 ) ;
V_4 -> V_31 . V_123 = V_126 ;
F_72 ( & V_56 -> V_57 ,
& V_4 -> V_31 ) ;
F_66 () ;
V_100 = F_67 ( V_56 -> V_99 ) ;
V_101 = V_100 -> V_127 ;
F_68 () ;
if ( V_56 -> V_59 >= V_101 )
F_32 ( V_56 ) ;
break;
case V_128 :
F_55 ( V_4 , V_62 , 0 , V_66 ) ;
V_4 -> V_31 . V_123 = V_129 ;
F_72 ( & V_56 -> V_57 ,
& V_4 -> V_31 ) ;
break;
case V_130 :
case V_131 :
case V_132 :
F_55 ( V_4 , V_62 , V_66 , 0 ) ;
break;
case V_133 :
if ( F_64 ( V_4 ) )
F_55 ( V_4 , V_62 , V_66 | V_67 ,
V_81 | V_49 ) ;
else
F_55 ( V_4 , V_62 , V_66 , V_81 ) ;
break;
case V_134 :
F_55 ( V_4 , V_62 , V_66 , V_45 ) ;
break;
case V_135 :
F_55 ( V_4 , V_62 ,
V_49 | V_67 | V_68 ,
V_45 ) ;
break;
case V_136 :
F_44 ( V_2 , V_4 -> V_15 & V_67 ) ;
F_44 ( V_2 , V_4 -> V_15 & V_95 ) ;
F_55 ( V_4 , V_62 , V_67 , V_45 | V_49 ) ;
break;
case V_137 :
V_4 -> V_15 |= V_51 ;
case V_138 :
goto V_139;
case V_140 :
F_44 ( V_2 , V_4 -> V_15 & V_96 ) ;
V_139:
F_55 ( V_4 , V_62 , V_67 , V_49 ) ;
break;
case V_141 :
F_44 ( V_2 , V_4 -> V_15 & V_95 ) ;
F_44 ( V_2 , V_4 -> V_15 & V_67 ) ;
V_4 -> V_15 |= V_42 ;
if ( V_4 -> V_6 . V_29 )
F_16 ( & V_2 -> V_40 ) ;
break;
case V_142 :
F_55 ( V_4 , V_62 , V_49 | V_67 , 0 ) ;
break;
case V_143 :
if ( ! ( V_4 -> V_15 & V_111 ) )
break;
F_55 ( V_4 , V_62 , V_68 , 0 ) ;
break;
case V_144 :
if ( ! ( V_4 -> V_15 & V_111 ) )
break;
F_55 ( V_4 , V_62 ,
V_68 | V_111 ,
V_43 ) ;
V_102 = V_145 ;
if ( F_3 ( V_4 -> V_5 ) == V_16 )
V_102 = V_146 ;
F_73 ( V_2 ) ;
V_4 -> V_31 . V_123 = V_147 ;
F_72 ( & V_56 -> V_57 ,
& V_4 -> V_31 ) ;
break;
case V_148 :
if ( ! ( V_4 -> V_15 & V_17 ) && ! V_4 -> V_31 . V_123 ) {
F_55 ( V_4 , V_62 , V_68 , 0 ) ;
break;
}
if ( ! ( V_4 -> V_15 & V_49 ) ) {
F_55 ( V_4 , V_62 , V_68 , V_66 | V_67 ) ;
if ( V_4 -> V_31 . V_123 ) {
F_72 ( & V_56 -> V_57 ,
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
F_55 ( V_4 , V_62 , V_68 ,
( V_4 -> V_15 & V_44 ) ? V_45 : 0 ) ;
break;
case V_150 :
F_44 ( V_2 , V_4 -> V_15 & V_67 ) ;
F_55 ( V_4 , V_62 , V_67 , V_49 | V_45 ) ;
break;
case V_151 :
F_32 ( V_56 ) ;
F_55 ( V_4 , V_62 , 0 , V_49 | V_45 ) ;
break;
} ;
return V_102 ;
}
static bool F_74 ( struct V_1 * V_2 , T_1 V_24 , int V_7 )
{
unsigned long V_152 , V_153 ;
T_1 V_154 , V_155 ;
if ( V_2 -> V_156 . V_157 == V_158 )
return true ;
if ( V_2 -> V_156 . V_157 != V_159 )
return false ;
V_154 = V_24 + ( V_7 >> 9 ) - 1 ;
V_155 = F_75 ( V_2 -> V_160 ) ;
F_44 ( V_2 , V_24 < V_155 ) ;
F_44 ( V_2 , V_154 < V_155 ) ;
V_152 = F_76 ( V_24 ) ;
V_153 = F_76 ( V_154 ) ;
return F_77 ( V_2 , V_152 , V_153 ) == 0 ;
}
static bool F_78 ( struct V_1 * V_2 , T_1 V_24 ,
enum V_161 V_162 )
{
struct V_163 * V_164 ;
int V_165 ;
switch ( V_162 ) {
case V_166 :
V_164 = V_2 -> V_93 -> V_94 -> V_167 -> V_168 -> V_163 ;
return F_79 ( V_164 ) ;
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
return F_80 ( V_180 , & V_2 -> V_122 ) ;
case V_181 :
return true ;
case V_182 :
default:
return false ;
}
}
static void F_81 ( struct V_3 * V_4 )
{
F_82 ( V_183 ) ;
struct V_1 * V_2 = V_4 -> V_2 ;
struct V_39 * V_6 ;
T_1 V_24 = V_4 -> V_6 . V_24 ;
int V_7 = V_4 -> V_6 . V_7 ;
for (; ; ) {
F_83 (i, &device->write_requests, sector, size) {
if ( V_6 -> V_74 )
continue;
break;
}
if ( ! V_6 )
break;
F_84 ( & V_2 -> V_40 , & V_183 , V_184 ) ;
V_6 -> V_29 = true ;
F_85 ( & V_2 -> V_185 -> V_186 ) ;
F_86 () ;
F_87 ( & V_2 -> V_185 -> V_186 ) ;
}
F_88 ( & V_2 -> V_40 , & V_183 ) ;
}
static void F_89 ( struct V_1 * V_2 )
{
struct V_55 * V_56 = F_41 ( V_2 ) -> V_56 ;
struct V_99 * V_100 ;
bool V_187 = false ;
enum V_188 V_189 ;
F_66 () ;
V_100 = F_67 ( V_56 -> V_99 ) ;
V_189 = V_100 ? V_100 -> V_189 : V_190 ;
F_68 () ;
if ( V_189 == V_190 ||
V_56 -> V_191 < 96 )
return;
if ( V_189 == V_192 && V_2 -> V_156 . V_193 == V_194 )
return;
if ( ! F_25 ( V_2 , V_158 ) )
return;
if ( V_100 -> V_195 &&
F_19 ( & V_2 -> V_87 ) >= V_100 -> V_195 ) {
F_90 ( V_2 , L_12 ) ;
V_187 = true ;
}
if ( V_2 -> V_196 -> V_197 >= V_100 -> V_198 ) {
F_90 ( V_2 , L_13 ) ;
V_187 = true ;
}
if ( V_187 ) {
F_32 ( F_41 ( V_2 ) -> V_56 ) ;
if ( V_189 == V_192 )
F_91 ( F_92 ( V_2 , V_193 , V_194 ) , 0 , NULL ) ;
else
F_91 ( F_92 ( V_2 , V_193 , V_199 ) , 0 , NULL ) ;
}
F_27 ( V_2 ) ;
}
static bool F_93 ( struct V_3 * V_4 )
{
struct V_1 * V_2 = V_4 -> V_2 ;
enum V_161 V_162 ;
if ( V_4 -> V_69 ) {
if ( ! F_74 ( V_2 ,
V_4 -> V_6 . V_24 , V_4 -> V_6 . V_7 ) ) {
F_94 ( V_4 -> V_69 ) ;
V_4 -> V_69 = NULL ;
F_27 ( V_2 ) ;
}
}
if ( V_2 -> V_156 . V_200 != V_158 )
return false ;
if ( V_4 -> V_69 == NULL )
return true ;
F_66 () ;
V_162 = F_67 ( V_2 -> V_93 -> V_201 ) -> V_202 ;
F_68 () ;
if ( V_162 == V_182 && V_4 -> V_69 )
return false ;
if ( F_78 ( V_2 , V_4 -> V_6 . V_24 , V_162 ) ) {
if ( V_4 -> V_69 ) {
F_94 ( V_4 -> V_69 ) ;
V_4 -> V_69 = NULL ;
F_27 ( V_2 ) ;
}
return true ;
}
return false ;
}
bool F_95 ( union V_203 V_41 )
{
return V_41 . V_200 == V_158 ||
( V_41 . V_200 >= V_159 &&
V_41 . V_193 >= V_204 &&
V_41 . V_193 < V_194 ) ;
}
static bool F_96 ( union V_203 V_41 )
{
return V_41 . V_193 == V_194 || V_41 . V_193 == V_205 ;
}
static int F_97 ( struct V_3 * V_4 )
{
struct V_1 * V_2 = V_4 -> V_2 ;
int V_206 , V_207 ;
V_206 = F_95 ( V_2 -> V_156 ) ;
V_207 = F_96 ( V_2 -> V_156 ) ;
if ( F_98 ( V_4 -> V_6 . V_7 == 0 ) ) {
F_44 ( V_2 , V_4 -> V_5 -> V_71 & V_208 ) ;
if ( V_206 )
F_99 ( V_4 , V_151 ) ;
return V_206 ;
}
if ( ! V_206 && ! V_207 )
return 0 ;
F_44 ( V_2 , ! ( V_206 && V_207 ) ) ;
if ( V_206 ) {
F_99 ( V_4 , V_103 ) ;
F_99 ( V_4 , V_125 ) ;
} else if ( F_23 ( V_2 , V_4 -> V_6 . V_24 , V_4 -> V_6 . V_7 ) )
F_99 ( V_4 , V_128 ) ;
return V_206 ;
}
static void F_100 ( struct V_3 * V_4 )
{
struct V_209 * V_210 = V_4 -> V_2 -> V_93 -> V_94 ;
if ( F_101 ( V_210 , V_4 -> V_6 . V_24 , V_4 -> V_6 . V_7 >> 9 ,
V_14 , 0 ) )
V_4 -> V_69 -> V_63 = V_211 ;
F_36 ( V_4 -> V_69 ) ;
}
static void
F_102 ( struct V_3 * V_4 )
{
struct V_1 * V_2 = V_4 -> V_2 ;
struct V_11 * V_11 = V_4 -> V_69 ;
unsigned int type ;
if ( F_9 ( V_11 ) != V_70 )
type = V_212 ;
else if ( V_11 -> V_71 & V_72 )
type = V_213 ;
else
type = V_214 ;
V_11 -> V_215 = V_2 -> V_93 -> V_94 ;
if ( F_73 ( V_2 ) ) {
if ( F_103 ( V_2 , type ) )
F_104 ( V_11 ) ;
else if ( F_9 ( V_11 ) == V_20 ||
F_9 ( V_11 ) == V_22 )
F_100 ( V_4 ) ;
else
F_105 ( V_11 ) ;
F_27 ( V_2 ) ;
} else
F_104 ( V_11 ) ;
}
static void F_106 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
F_87 ( & V_2 -> V_185 -> V_186 ) ;
F_107 ( & V_4 -> V_30 , & V_2 -> V_216 . V_217 ) ;
F_107 ( & V_4 -> V_33 ,
& V_2 -> V_218 [ 1 ] ) ;
F_85 ( & V_2 -> V_185 -> V_186 ) ;
F_108 ( V_2 -> V_216 . V_219 , & V_2 -> V_216 . V_220 ) ;
F_16 ( & V_2 -> V_221 ) ;
}
static struct V_3 *
F_109 ( struct V_1 * V_2 , struct V_11 * V_11 , unsigned long V_10 )
{
const int V_222 = F_3 ( V_11 ) ;
struct V_3 * V_4 ;
V_4 = F_6 ( V_2 , V_11 ) ;
if ( ! V_4 ) {
F_37 ( V_2 ) ;
F_20 ( V_2 , L_14 ) ;
V_11 -> V_63 = V_223 ;
F_36 ( V_11 ) ;
return F_110 ( - V_224 ) ;
}
V_4 -> V_10 = V_10 ;
if ( ! F_73 ( V_2 ) ) {
F_94 ( V_4 -> V_69 ) ;
V_4 -> V_69 = NULL ;
}
F_1 ( V_2 , V_4 ) ;
if ( ( F_9 ( V_11 ) & V_20 ) ||
( F_9 ( V_11 ) & V_22 ) )
goto V_225;
if ( V_222 == V_16 && V_4 -> V_69 && V_4 -> V_6 . V_7
&& ! F_111 ( V_226 , & V_2 -> V_122 ) ) {
if ( ! F_112 ( V_2 , & V_4 -> V_6 ) )
goto V_225;
V_4 -> V_15 |= V_52 ;
V_4 -> V_227 = V_89 ;
}
return V_4 ;
V_225:
F_33 ( & V_2 -> V_228 ) ;
F_106 ( V_2 , V_4 ) ;
return NULL ;
}
static bool F_113 ( struct V_1 * V_2 )
{
const union V_203 V_41 = V_2 -> V_156 ;
return V_41 . V_157 == V_158 || V_41 . V_200 == V_158 ;
}
static void F_114 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_229 * V_185 = V_2 -> V_185 ;
const int V_222 = F_3 ( V_4 -> V_5 ) ;
struct V_61 V_62 = { NULL , } ;
bool V_230 = false ;
bool V_231 = false ;
F_87 ( & V_185 -> V_186 ) ;
if ( V_222 == V_16 ) {
F_81 ( V_4 ) ;
F_89 ( V_2 ) ;
}
if ( F_56 ( V_2 ) ) {
V_4 -> V_15 |= V_42 ;
if ( V_4 -> V_69 ) {
F_94 ( V_4 -> V_69 ) ;
V_4 -> V_69 = NULL ;
F_27 ( V_2 ) ;
}
goto V_232;
}
if ( V_222 != V_16 ) {
if ( ! F_93 ( V_4 ) && ! V_4 -> V_69 )
goto V_233;
}
V_4 -> V_23 = F_19 ( & F_41 ( V_2 ) -> V_56 -> V_60 ) ;
if ( F_115 ( V_4 -> V_6 . V_7 != 0 ) ) {
if ( V_222 == V_16 )
F_41 ( V_2 ) -> V_56 -> V_59 ++ ;
F_107 ( & V_4 -> V_30 , & F_41 ( V_2 ) -> V_56 -> V_79 ) ;
}
if ( V_222 == V_16 ) {
if ( V_4 -> V_69 && ! F_113 ( V_2 ) ) {
F_94 ( V_4 -> V_69 ) ;
V_4 -> V_69 = NULL ;
F_27 ( V_2 ) ;
goto V_233;
}
if ( ! F_97 ( V_4 ) )
V_230 = true ;
} else {
if ( V_4 -> V_69 == NULL ) {
F_99 ( V_4 , V_103 ) ;
F_99 ( V_4 , V_120 ) ;
} else
V_230 = true ;
}
if ( F_42 ( & V_4 -> V_33 ) )
F_107 ( & V_4 -> V_33 ,
& V_2 -> V_218 [ V_222 == V_16 ] ) ;
if ( V_4 -> V_69 ) {
V_4 -> V_234 = V_89 ;
F_107 ( & V_4 -> V_34 ,
& V_2 -> V_235 [ V_222 == V_16 ] ) ;
F_99 ( V_4 , V_107 ) ;
V_231 = true ;
} else if ( V_230 ) {
V_233:
if ( F_28 ( & V_54 ) )
F_20 ( V_2 , L_15 ,
( unsigned long long ) V_4 -> V_6 . V_24 , V_4 -> V_6 . V_7 >> 9 ) ;
}
V_232:
F_43 ( V_4 , & V_62 , 1 ) ;
F_85 ( & V_185 -> V_186 ) ;
if ( V_231 )
F_102 ( V_4 ) ;
if ( V_62 . V_11 )
F_34 ( V_2 , & V_62 ) ;
}
void F_116 ( struct V_1 * V_2 , struct V_11 * V_11 , unsigned long V_10 )
{
struct V_3 * V_4 = F_109 ( V_2 , V_11 , V_10 ) ;
if ( F_117 ( V_4 ) )
return;
F_114 ( V_2 , V_4 ) ;
}
static void F_118 ( struct V_1 * V_2 , struct V_236 * V_237 )
{
struct V_3 * V_4 , * V_238 ;
F_119 (req, tmp, incoming, tl_requests) {
const int V_222 = F_3 ( V_4 -> V_5 ) ;
if ( V_222 == V_16
&& V_4 -> V_69 && V_4 -> V_6 . V_7
&& ! F_111 ( V_226 , & V_2 -> V_122 ) ) {
if ( ! F_112 ( V_2 , & V_4 -> V_6 ) )
continue;
V_4 -> V_15 |= V_52 ;
V_4 -> V_227 = V_89 ;
F_120 ( & V_2 -> V_228 ) ;
}
F_21 ( & V_4 -> V_30 ) ;
F_114 ( V_2 , V_4 ) ;
}
}
static bool F_121 ( struct V_1 * V_2 ,
struct V_236 * V_237 ,
struct V_236 * V_239 ,
struct V_236 * V_240 )
{
struct V_3 * V_4 , * V_238 ;
int V_241 = 0 ;
int V_242 ;
F_87 ( & V_2 -> V_243 ) ;
F_119 (req, tmp, incoming, tl_requests) {
V_242 = F_122 ( V_2 , & V_4 -> V_6 ) ;
if ( V_242 == - V_244 )
break;
if ( V_242 == - V_245 )
V_241 = 1 ;
if ( V_242 )
F_123 ( & V_4 -> V_30 , V_240 ) ;
else
F_123 ( & V_4 -> V_30 , V_239 ) ;
}
F_85 ( & V_2 -> V_243 ) ;
if ( V_241 )
F_16 ( & V_2 -> V_221 ) ;
return ! F_42 ( V_239 ) ;
}
void F_124 ( struct V_1 * V_2 , struct V_236 * V_239 )
{
struct V_3 * V_4 , * V_238 ;
F_119 (req, tmp, pending, tl_requests) {
V_4 -> V_15 |= V_52 ;
V_4 -> V_227 = V_89 ;
F_120 ( & V_2 -> V_228 ) ;
F_21 ( & V_4 -> V_30 ) ;
F_114 ( V_2 , V_4 ) ;
}
}
void F_125 ( struct V_246 * V_247 )
{
struct V_1 * V_2 = F_18 ( V_247 , struct V_1 , V_216 . V_220 ) ;
F_126 ( V_237 ) ;
F_126 ( V_239 ) ;
F_126 ( V_248 ) ;
F_87 ( & V_2 -> V_185 -> V_186 ) ;
F_127 ( & V_2 -> V_216 . V_217 , & V_237 ) ;
F_85 ( & V_2 -> V_185 -> V_186 ) ;
for (; ; ) {
F_82 ( V_183 ) ;
F_128 ( & V_248 , & V_237 ) ;
F_118 ( V_2 , & V_237 ) ;
if ( F_42 ( & V_237 ) )
break;
for (; ; ) {
F_84 ( & V_2 -> V_221 , & V_183 , V_184 ) ;
F_128 ( & V_248 , & V_237 ) ;
F_121 ( V_2 , & V_237 , & V_239 , & V_248 ) ;
if ( ! F_42 ( & V_239 ) )
break;
F_86 () ;
if ( ! F_42 ( & V_237 ) )
continue;
F_87 ( & V_2 -> V_185 -> V_186 ) ;
F_127 ( & V_2 -> V_216 . V_217 , & V_237 ) ;
F_85 ( & V_2 -> V_185 -> V_186 ) ;
}
F_88 ( & V_2 -> V_221 , & V_183 ) ;
while ( F_42 ( & V_237 ) ) {
F_126 ( V_249 ) ;
F_126 ( V_250 ) ;
bool V_251 ;
if ( F_42 ( & V_2 -> V_216 . V_217 ) )
break;
F_87 ( & V_2 -> V_185 -> V_186 ) ;
F_127 ( & V_2 -> V_216 . V_217 , & V_250 ) ;
F_85 ( & V_2 -> V_185 -> V_186 ) ;
if ( F_42 ( & V_250 ) )
break;
V_251 = F_121 ( V_2 , & V_250 , & V_249 , & V_248 ) ;
F_127 ( & V_249 , & V_239 ) ;
F_127 ( & V_250 , & V_237 ) ;
if ( ! V_251 )
break;
}
F_129 ( V_2 ) ;
F_124 ( V_2 , & V_239 ) ;
}
}
T_2 F_130 ( struct V_252 * V_253 , struct V_11 * V_11 )
{
struct V_1 * V_2 = (struct V_1 * ) V_253 -> V_254 ;
unsigned long V_10 ;
F_131 ( V_253 , & V_11 ) ;
V_10 = V_89 ;
F_44 ( V_2 , F_132 ( V_11 -> V_25 . V_27 , 512 ) ) ;
F_133 ( V_2 ) ;
F_116 ( V_2 , V_11 , V_10 ) ;
return V_255 ;
}
static bool F_134 ( struct V_3 * V_256 ,
struct V_55 * V_56 ,
unsigned long V_257 , unsigned long V_258 ,
unsigned int V_259 , unsigned int V_260 )
{
struct V_1 * V_2 = V_256 -> V_2 ;
if ( ! F_135 ( V_257 , V_256 -> V_261 + V_258 ) )
return false ;
if ( F_136 ( V_257 , V_56 -> V_262 , V_56 -> V_262 + V_258 ) )
return false ;
if ( V_256 -> V_15 & V_67 ) {
F_29 ( V_2 , L_16 ,
F_137 ( V_257 - V_256 -> V_261 ) , V_259 , V_260 ) ;
return true ;
}
if ( V_256 -> V_23 == V_56 -> V_263 . V_264 ) {
F_29 ( V_2 ,
L_17 ,
F_137 ( V_257 - V_256 -> V_261 ) , V_259 , V_260 ) ;
return false ;
}
if ( F_135 ( V_257 , V_56 -> V_263 . V_265 + V_258 ) ) {
F_29 ( V_2 , L_18 ,
V_56 -> V_263 . V_265 , V_257 ,
F_137 ( V_257 - V_56 -> V_263 . V_265 ) , V_259 , V_260 ) ;
return true ;
}
return false ;
}
void F_138 ( unsigned long V_266 )
{
struct V_1 * V_2 = (struct V_1 * ) V_266 ;
struct V_55 * V_56 = F_41 ( V_2 ) -> V_56 ;
struct V_3 * V_267 , * V_268 , * V_269 ;
struct V_99 * V_100 ;
unsigned long V_270 ;
unsigned long V_258 = 0 , V_271 = 0 , V_272 , V_273 ;
unsigned long V_257 ;
unsigned int V_259 = 0 , V_260 = 0 ;
F_66 () ;
V_100 = F_67 ( V_56 -> V_99 ) ;
if ( V_100 && V_2 -> V_156 . V_193 >= V_274 ) {
V_259 = V_100 -> V_259 ;
V_260 = V_100 -> V_260 ;
}
if ( F_73 ( V_2 ) ) {
V_271 = F_67 ( V_2 -> V_93 -> V_201 ) -> V_275 * V_276 / 10 ;
F_27 ( V_2 ) ;
}
F_68 () ;
V_258 = V_260 * V_276 / 10 * V_259 ;
V_272 = F_139 ( V_271 , V_258 ) ;
if ( ! V_272 )
return;
V_257 = V_89 ;
V_273 = V_257 + V_272 ;
F_87 ( & V_2 -> V_185 -> V_186 ) ;
V_267 = F_140 ( & V_2 -> V_235 [ 0 ] , struct V_3 , V_34 ) ;
V_268 = F_140 ( & V_2 -> V_235 [ 1 ] , struct V_3 , V_34 ) ;
V_269 = V_56 -> V_80 ;
if ( ! V_269 )
V_269 = V_56 -> V_82 ;
if ( V_269 && V_269 -> V_2 != V_2 )
V_269 = NULL ;
if ( V_269 == NULL && V_268 == NULL && V_267 == NULL )
goto V_232;
V_270 =
( V_268 && V_267 )
? ( F_141 ( V_268 -> V_234 , V_267 -> V_234 )
? V_268 -> V_234 : V_267 -> V_234 )
: V_268 ? V_268 -> V_234
: V_267 ? V_267 -> V_234 : V_257 ;
if ( V_258 && V_269 && F_134 ( V_269 , V_56 , V_257 , V_258 , V_259 , V_260 ) )
F_142 ( V_56 , F_143 ( V_193 , V_277 ) , V_278 | V_279 ) ;
if ( V_271 && V_270 != V_257 &&
F_135 ( V_257 , V_270 + V_271 ) &&
! F_136 ( V_257 , V_2 -> V_280 , V_2 -> V_280 + V_271 ) ) {
F_29 ( V_2 , L_19 ) ;
F_69 ( V_2 , V_281 ) ;
}
V_258 = ( V_258 && V_269 && F_141 ( V_257 , V_269 -> V_261 + V_258 ) )
? V_269 -> V_261 + V_258 : V_257 + V_272 ;
V_271 = ( V_271 && V_270 != V_257 && F_141 ( V_257 , V_270 + V_271 ) )
? V_270 + V_271 : V_257 + V_272 ;
V_273 = F_141 ( V_258 , V_271 ) ? V_258 : V_271 ;
V_232:
F_85 ( & V_2 -> V_185 -> V_186 ) ;
F_144 ( & V_2 -> V_282 , V_273 ) ;
}
