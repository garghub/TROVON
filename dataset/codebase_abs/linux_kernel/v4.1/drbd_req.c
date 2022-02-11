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
static struct V_3 * F_6 ( struct V_1 * V_2 ,
struct V_11 * V_12 )
{
struct V_3 * V_4 ;
V_4 = F_7 ( V_13 , V_14 ) ;
if ( ! V_4 )
return NULL ;
memset ( V_4 , 0 , sizeof( * V_4 ) ) ;
F_8 ( V_4 , V_12 ) ;
V_4 -> V_15 = F_3 ( V_12 ) == V_16 ? V_17 : 0 ;
V_4 -> V_2 = V_2 ;
V_4 -> V_5 = V_12 ;
V_4 -> V_18 = 0 ;
F_9 ( & V_4 -> V_6 ) ;
V_4 -> V_6 . V_19 = V_12 -> V_20 . V_21 ;
V_4 -> V_6 . V_7 = V_12 -> V_20 . V_22 ;
V_4 -> V_6 . V_23 = true ;
V_4 -> V_6 . V_24 = false ;
F_10 ( & V_4 -> V_25 ) ;
F_10 ( & V_4 -> V_26 . V_27 ) ;
F_10 ( & V_4 -> V_28 ) ;
F_10 ( & V_4 -> V_29 ) ;
F_11 ( & V_4 -> V_30 , 1 ) ;
F_12 ( & V_4 -> V_31 ) ;
return V_4 ;
}
static void F_13 ( struct V_32 * V_33 ,
struct V_3 * V_4 )
{
struct V_1 * V_2 = V_4 -> V_2 ;
struct V_34 * V_6 = & V_4 -> V_6 ;
F_14 ( V_33 , V_6 ) ;
if ( V_6 -> V_24 )
F_15 ( & V_2 -> V_35 ) ;
}
void F_16 ( struct V_31 * V_31 )
{
struct V_3 * V_4 = F_17 ( V_31 , struct V_3 , V_31 ) ;
struct V_1 * V_2 = V_4 -> V_2 ;
const unsigned V_36 = V_4 -> V_15 ;
if ( ( V_4 -> V_5 && ! ( V_36 & V_37 ) ) ||
F_18 ( & V_4 -> V_30 ) ||
( V_36 & V_38 ) ||
( ( V_36 & V_39 ) && ! ( V_36 & V_40 ) ) ) {
F_19 ( V_2 , L_1 ,
V_36 , F_18 ( & V_4 -> V_30 ) ) ;
return;
}
F_20 ( & V_4 -> V_25 ) ;
if ( ! F_21 ( & V_4 -> V_6 ) ) {
struct V_32 * V_33 ;
if ( V_36 & V_17 )
V_33 = & V_2 -> V_41 ;
else
V_33 = & V_2 -> V_42 ;
F_13 ( V_33 , V_4 ) ;
} else if ( V_36 & ( V_39 & ~ V_40 ) && V_4 -> V_6 . V_7 != 0 )
F_19 ( V_2 , L_2 ,
V_36 , ( unsigned long long ) V_4 -> V_6 . V_19 , V_4 -> V_6 . V_7 ) ;
if ( V_36 & V_17 ) {
if ( ( V_36 & ( V_37 | V_43 | V_39 ) ) != V_37 ) {
if ( ! ( V_36 & V_44 ) || ! ( V_36 & V_45 ) )
F_22 ( V_2 , V_4 -> V_6 . V_19 , V_4 -> V_6 . V_7 ) ;
if ( ( V_36 & V_44 ) && ( V_36 & V_45 ) && ( V_36 & V_46 ) )
F_23 ( V_2 , V_4 -> V_6 . V_19 , V_4 -> V_6 . V_7 ) ;
}
if ( V_36 & V_47 ) {
if ( F_24 ( V_2 , V_48 ) ) {
F_25 ( V_2 , & V_4 -> V_6 ) ;
F_26 ( V_2 ) ;
} else if ( F_27 ( & V_49 ) ) {
F_28 ( V_2 , L_3
L_4 ,
( unsigned long long ) V_4 -> V_6 . V_19 , V_4 -> V_6 . V_7 ) ;
}
}
}
F_29 ( V_4 , V_13 ) ;
}
static void F_30 ( struct V_50 * V_51 )
{
F_15 ( & V_51 -> V_52 . V_53 ) ;
}
void F_31 ( struct V_50 * V_51 )
{
if ( V_51 -> V_54 == 0 )
return;
V_51 -> V_54 = 0 ;
F_32 ( & V_51 -> V_55 ) ;
F_30 ( V_51 ) ;
}
void F_33 ( struct V_1 * V_2 ,
struct V_56 * V_57 )
{
F_34 ( V_57 -> V_11 , V_57 -> error ) ;
F_35 ( V_2 ) ;
}
static
void F_36 ( struct V_3 * V_4 , struct V_56 * V_57 )
{
const unsigned V_36 = V_4 -> V_15 ;
struct V_1 * V_2 = V_4 -> V_2 ;
int V_58 ;
int error , V_59 ;
if ( ( V_36 & V_38 && ! ( V_36 & V_60 ) ) ||
( V_36 & V_61 ) || ( V_36 & V_62 ) ||
( V_36 & V_63 ) ) {
F_19 ( V_2 , L_5 , V_36 ) ;
return;
}
if ( ! V_4 -> V_5 ) {
F_19 ( V_2 , L_6 ) ;
return;
}
V_58 = F_37 ( V_4 -> V_5 ) ;
V_59 = ( V_36 & V_45 ) || ( V_36 & V_44 ) ;
error = F_38 ( V_4 -> V_64 ) ;
if ( V_58 == V_16 &&
V_4 -> V_18 == F_18 ( & F_39 ( V_2 ) -> V_51 -> V_55 ) )
F_31 ( F_39 ( V_2 ) -> V_51 ) ;
F_4 ( V_2 , V_4 ) ;
if ( ! V_59 && V_58 == V_65 && ! F_40 ( & V_4 -> V_25 ) )
V_4 -> V_15 |= V_37 ;
if ( ! ( V_4 -> V_15 & V_37 ) ) {
V_57 -> error = V_59 ? 0 : ( error ? : - V_66 ) ;
V_57 -> V_11 = V_4 -> V_5 ;
V_4 -> V_5 = NULL ;
V_4 -> V_6 . V_67 = true ;
}
if ( V_4 -> V_6 . V_24 )
F_15 ( & V_2 -> V_35 ) ;
F_20 ( & V_4 -> V_28 ) ;
}
static int F_41 ( struct V_3 * V_4 , struct V_56 * V_57 , int V_68 )
{
struct V_1 * V_2 = V_4 -> V_2 ;
F_42 ( V_2 , V_57 || ( V_4 -> V_15 & V_37 ) ) ;
if ( ! F_43 ( V_68 , & V_4 -> V_30 ) )
return 0 ;
F_36 ( V_4 , V_57 ) ;
if ( V_4 -> V_15 & V_37 ) {
F_44 ( V_4 ) ;
return 0 ;
}
return 1 ;
}
static void F_45 ( struct V_69 * V_70 , struct V_3 * V_4 )
{
struct V_50 * V_51 = V_70 ? V_70 -> V_51 : NULL ;
if ( ! V_51 )
return;
if ( V_51 -> V_71 == NULL )
V_51 -> V_71 = V_4 ;
}
static void F_46 ( struct V_69 * V_70 , struct V_3 * V_4 )
{
struct V_50 * V_51 = V_70 ? V_70 -> V_51 : NULL ;
if ( ! V_51 )
return;
if ( V_51 -> V_71 != V_4 )
return;
F_47 (req, &connection->transfer_log, tl_requests) {
const unsigned V_36 = V_4 -> V_15 ;
if ( V_36 & V_61 )
break;
}
if ( & V_4 -> V_25 == & V_51 -> V_72 )
V_4 = NULL ;
V_51 -> V_71 = V_4 ;
}
static void F_48 ( struct V_69 * V_70 , struct V_3 * V_4 )
{
struct V_50 * V_51 = V_70 ? V_70 -> V_51 : NULL ;
if ( ! V_51 )
return;
if ( V_51 -> V_73 == NULL )
V_51 -> V_73 = V_4 ;
}
static void F_49 ( struct V_69 * V_70 , struct V_3 * V_4 )
{
struct V_50 * V_51 = V_70 ? V_70 -> V_51 : NULL ;
if ( ! V_51 )
return;
if ( V_51 -> V_73 != V_4 )
return;
F_47 (req, &connection->transfer_log, tl_requests) {
const unsigned V_36 = V_4 -> V_15 ;
if ( ( V_36 & V_74 ) && ( V_36 & V_62 ) )
break;
}
if ( & V_4 -> V_25 == & V_51 -> V_72 )
V_4 = NULL ;
V_51 -> V_73 = V_4 ;
}
static void F_50 ( struct V_69 * V_70 , struct V_3 * V_4 )
{
struct V_50 * V_51 = V_70 ? V_70 -> V_51 : NULL ;
if ( ! V_51 )
return;
if ( V_51 -> V_75 == NULL )
V_51 -> V_75 = V_4 ;
}
static void F_51 ( struct V_69 * V_70 , struct V_3 * V_4 )
{
struct V_50 * V_51 = V_70 ? V_70 -> V_51 : NULL ;
if ( ! V_51 )
return;
if ( V_51 -> V_75 != V_4 )
return;
F_47 (req, &connection->transfer_log, tl_requests) {
const unsigned V_36 = V_4 -> V_15 ;
if ( ( V_36 & V_74 ) && ! ( V_36 & V_40 ) )
break;
}
if ( & V_4 -> V_25 == & V_51 -> V_72 )
V_4 = NULL ;
V_51 -> V_75 = V_4 ;
}
static void F_52 ( struct V_3 * V_4 , struct V_56 * V_57 ,
int V_76 , int V_77 )
{
struct V_1 * V_2 = V_4 -> V_2 ;
struct V_69 * V_70 = F_39 ( V_2 ) ;
unsigned V_36 = V_4 -> V_15 ;
int V_78 = 0 ;
int V_79 = 0 ;
if ( F_53 ( V_2 ) && ! ( ( V_36 | V_76 ) & V_63 ) )
V_77 |= V_63 ;
V_4 -> V_15 &= ~ V_76 ;
V_4 -> V_15 |= V_77 ;
if ( V_4 -> V_15 == V_36 )
return;
if ( ! ( V_36 & V_38 ) && ( V_77 & V_38 ) )
F_32 ( & V_4 -> V_30 ) ;
if ( ! ( V_36 & V_62 ) && ( V_77 & V_62 ) ) {
F_54 ( V_2 ) ;
F_32 ( & V_4 -> V_30 ) ;
}
if ( ! ( V_36 & V_61 ) && ( V_77 & V_61 ) ) {
F_32 ( & V_4 -> V_30 ) ;
F_45 ( V_70 , V_4 ) ;
}
if ( ! ( V_36 & V_80 ) && ( V_77 & V_80 ) )
F_55 ( & V_4 -> V_31 ) ;
if ( ! ( V_36 & V_74 ) && ( V_77 & V_74 ) ) {
if ( ! ( V_36 & V_40 ) ) {
F_56 ( V_4 -> V_6 . V_7 >> 9 , & V_2 -> V_81 ) ;
F_50 ( V_70 , V_4 ) ;
}
if ( V_36 & V_62 )
F_48 ( V_70 , V_4 ) ;
}
if ( ! ( V_36 & V_63 ) && ( V_77 & V_63 ) )
F_32 ( & V_4 -> V_30 ) ;
if ( ( V_36 & V_63 ) && ( V_76 & V_63 ) )
++ V_78 ;
if ( ! ( V_36 & V_60 ) && ( V_77 & V_60 ) ) {
F_42 ( V_2 , V_4 -> V_15 & V_38 ) ;
F_55 ( & V_4 -> V_31 ) ;
++ V_78 ;
}
if ( ( V_36 & V_38 ) && ( V_76 & V_38 ) ) {
if ( V_4 -> V_15 & V_60 )
++ V_79 ;
else
++ V_78 ;
F_20 ( & V_4 -> V_29 ) ;
}
if ( ( V_36 & V_62 ) && ( V_76 & V_62 ) ) {
F_57 ( V_2 ) ;
++ V_78 ;
V_4 -> V_82 = V_83 ;
F_49 ( V_70 , V_4 ) ;
}
if ( ( V_36 & V_61 ) && ( V_76 & V_61 ) ) {
++ V_78 ;
F_46 ( V_70 , V_4 ) ;
}
if ( ! ( V_36 & V_40 ) && ( V_77 & V_40 ) ) {
if ( V_36 & V_74 )
F_58 ( V_4 -> V_6 . V_7 >> 9 , & V_2 -> V_81 ) ;
if ( V_36 & V_80 )
++ V_79 ;
V_4 -> V_84 = V_83 ;
F_46 ( V_70 , V_4 ) ;
F_49 ( V_70 , V_4 ) ;
F_51 ( V_70 , V_4 ) ;
}
if ( V_79 || V_78 ) {
int V_85 = V_79 + ! ! V_78 ;
int V_86 = F_18 ( & V_4 -> V_31 . V_86 ) ;
if ( V_86 < V_85 )
F_19 ( V_2 ,
L_7 ,
V_36 , V_4 -> V_15 , V_86 , V_85 ) ;
}
if ( V_4 -> V_6 . V_24 )
F_15 ( & V_2 -> V_35 ) ;
if ( V_78 )
V_79 += F_41 ( V_4 , V_57 , V_78 ) ;
if ( V_79 )
F_59 ( & V_4 -> V_31 , V_79 , F_16 ) ;
}
static void F_60 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
char V_87 [ V_88 ] ;
if ( ! F_27 ( & V_49 ) )
return;
F_28 ( V_2 , L_8 ,
( V_4 -> V_15 & V_17 ) ? L_9 : L_10 ,
( unsigned long long ) V_4 -> V_6 . V_19 ,
V_4 -> V_6 . V_7 >> 9 ,
F_61 ( V_2 -> V_89 -> V_90 , V_87 ) ) ;
}
static inline bool F_62 ( struct V_3 * V_4 )
{
return ( V_4 -> V_15 &
( V_17 | V_62 | V_91 | V_92 ) )
== ( V_17 | V_62 ) ;
}
int F_63 ( struct V_3 * V_4 , enum V_93 V_94 ,
struct V_56 * V_57 )
{
struct V_1 * const V_2 = V_4 -> V_2 ;
struct V_69 * const V_70 = F_39 ( V_2 ) ;
struct V_50 * const V_51 = V_70 ? V_70 -> V_51 : NULL ;
struct V_95 * V_96 ;
int V_97 , V_98 = 0 ;
if ( V_57 )
V_57 -> V_11 = NULL ;
switch ( V_94 ) {
default:
F_19 ( V_2 , L_11 , __FILE__ , __LINE__ ) ;
break;
case V_99 :
F_42 ( V_2 , ! ( V_4 -> V_15 & V_39 ) ) ;
F_64 () ;
V_96 = F_65 ( V_51 -> V_95 ) ;
V_97 = V_96 -> V_100 ;
F_66 () ;
V_4 -> V_15 |=
V_97 == V_101 ? V_91 :
V_97 == V_102 ? V_92 : 0 ;
F_52 ( V_4 , V_57 , 0 , V_62 ) ;
break;
case V_103 :
F_42 ( V_2 , ! ( V_4 -> V_15 & V_43 ) ) ;
F_52 ( V_4 , V_57 , 0 , V_38 ) ;
break;
case V_104 :
if ( V_4 -> V_15 & V_17 )
V_2 -> V_105 += V_4 -> V_6 . V_7 >> 9 ;
else
V_2 -> V_106 += V_4 -> V_6 . V_7 >> 9 ;
F_52 ( V_4 , V_57 , V_38 ,
V_107 | V_45 ) ;
break;
case V_108 :
F_52 ( V_4 , V_57 , 0 , V_60 ) ;
break;
case V_109 :
F_60 ( V_2 , V_4 ) ;
F_67 ( V_2 , V_110 ) ;
F_52 ( V_4 , V_57 , V_38 , V_107 ) ;
break;
case V_111 :
F_22 ( V_2 , V_4 -> V_6 . V_19 , V_4 -> V_6 . V_7 ) ;
F_60 ( V_2 , V_4 ) ;
F_67 ( V_2 , V_112 ) ;
case V_113 :
F_52 ( V_4 , V_57 , V_38 , V_107 ) ;
break;
case V_114 :
case V_115 :
F_52 ( V_4 , V_57 , V_38 , V_107 ) ;
break;
case V_116 :
F_42 ( V_2 , F_21 ( & V_4 -> V_6 ) ) ;
F_68 ( & V_2 -> V_42 , & V_4 -> V_6 ) ;
F_69 ( V_117 , & V_2 -> V_118 ) ;
F_42 ( V_2 , V_4 -> V_15 & V_62 ) ;
F_42 ( V_2 , ( V_4 -> V_15 & V_43 ) == 0 ) ;
F_52 ( V_4 , V_57 , 0 , V_61 ) ;
V_4 -> V_26 . V_119 = V_120 ;
F_70 ( & V_51 -> V_52 ,
& V_4 -> V_26 ) ;
break;
case V_121 :
F_42 ( V_2 , F_21 ( & V_4 -> V_6 ) ) ;
F_68 ( & V_2 -> V_41 , & V_4 -> V_6 ) ;
F_69 ( V_117 , & V_2 -> V_118 ) ;
F_42 ( V_2 , V_4 -> V_15 & V_62 ) ;
F_52 ( V_4 , V_57 , 0 , V_61 | V_80 ) ;
V_4 -> V_26 . V_119 = V_122 ;
F_70 ( & V_51 -> V_52 ,
& V_4 -> V_26 ) ;
F_64 () ;
V_96 = F_65 ( V_51 -> V_95 ) ;
V_97 = V_96 -> V_123 ;
F_66 () ;
if ( V_51 -> V_54 >= V_97 )
F_31 ( V_51 ) ;
break;
case V_124 :
F_52 ( V_4 , V_57 , 0 , V_61 ) ;
V_4 -> V_26 . V_119 = V_125 ;
F_70 ( & V_51 -> V_52 ,
& V_4 -> V_26 ) ;
break;
case V_126 :
case V_127 :
case V_128 :
F_52 ( V_4 , V_57 , V_61 , 0 ) ;
break;
case V_129 :
if ( F_62 ( V_4 ) )
F_52 ( V_4 , V_57 , V_61 | V_62 ,
V_74 | V_44 ) ;
else
F_52 ( V_4 , V_57 , V_61 , V_74 ) ;
break;
case V_130 :
F_52 ( V_4 , V_57 , V_61 , V_40 ) ;
break;
case V_131 :
F_52 ( V_4 , V_57 ,
V_44 | V_62 | V_63 ,
V_40 ) ;
break;
case V_132 :
F_42 ( V_2 , V_4 -> V_15 & V_62 ) ;
F_42 ( V_2 , V_4 -> V_15 & V_91 ) ;
F_52 ( V_4 , V_57 , V_62 , V_40 | V_44 ) ;
break;
case V_133 :
V_4 -> V_15 |= V_46 ;
case V_134 :
goto V_135;
case V_136 :
F_42 ( V_2 , V_4 -> V_15 & V_92 ) ;
V_135:
F_52 ( V_4 , V_57 , V_62 , V_44 ) ;
break;
case V_137 :
F_42 ( V_2 , V_4 -> V_15 & V_91 ) ;
F_42 ( V_2 , V_4 -> V_15 & V_62 ) ;
V_4 -> V_15 |= V_37 ;
if ( V_4 -> V_6 . V_24 )
F_15 ( & V_2 -> V_35 ) ;
break;
case V_138 :
F_52 ( V_4 , V_57 , V_44 | V_62 , 0 ) ;
break;
case V_139 :
if ( ! ( V_4 -> V_15 & V_107 ) )
break;
F_52 ( V_4 , V_57 , V_63 , 0 ) ;
break;
case V_140 :
if ( ! ( V_4 -> V_15 & V_107 ) )
break;
F_52 ( V_4 , V_57 ,
V_63 | V_107 ,
V_38 ) ;
V_98 = V_141 ;
if ( F_3 ( V_4 -> V_5 ) == V_16 )
V_98 = V_142 ;
F_71 ( V_2 ) ;
V_4 -> V_26 . V_119 = V_143 ;
F_70 ( & V_51 -> V_52 ,
& V_4 -> V_26 ) ;
break;
case V_144 :
if ( ! ( V_4 -> V_15 & V_17 ) && ! V_4 -> V_26 . V_119 ) {
F_52 ( V_4 , V_57 , V_63 , 0 ) ;
break;
}
if ( ! ( V_4 -> V_15 & V_44 ) ) {
F_52 ( V_4 , V_57 , V_63 , V_61 | V_62 ) ;
if ( V_4 -> V_26 . V_119 ) {
F_70 ( & V_51 -> V_52 ,
& V_4 -> V_26 ) ;
V_98 = V_4 -> V_15 & V_17 ? V_142 : V_141 ;
}
break;
}
case V_145 :
if ( ! ( V_4 -> V_15 & V_17 ) )
break;
if ( V_4 -> V_15 & V_62 ) {
F_19 ( V_2 , L_12 ) ;
}
F_52 ( V_4 , V_57 , V_63 ,
( V_4 -> V_15 & V_39 ) ? V_40 : 0 ) ;
break;
case V_146 :
F_42 ( V_2 , V_4 -> V_15 & V_62 ) ;
F_52 ( V_4 , V_57 , V_62 , V_44 | V_40 ) ;
break;
case V_147 :
F_31 ( V_51 ) ;
F_52 ( V_4 , V_57 , 0 , V_44 | V_40 ) ;
break;
} ;
return V_98 ;
}
static bool F_72 ( struct V_1 * V_2 , T_1 V_19 , int V_7 )
{
unsigned long V_148 , V_149 ;
T_1 V_150 , V_151 ;
if ( V_2 -> V_152 . V_153 == V_154 )
return true ;
if ( V_2 -> V_152 . V_153 != V_155 )
return false ;
V_150 = V_19 + ( V_7 >> 9 ) - 1 ;
V_151 = F_73 ( V_2 -> V_156 ) ;
F_42 ( V_2 , V_19 < V_151 ) ;
F_42 ( V_2 , V_150 < V_151 ) ;
V_148 = F_74 ( V_19 ) ;
V_149 = F_74 ( V_150 ) ;
return F_75 ( V_2 , V_148 , V_149 ) == 0 ;
}
static bool F_76 ( struct V_1 * V_2 , T_1 V_19 ,
enum V_157 V_158 )
{
struct V_159 * V_160 ;
int V_161 ;
switch ( V_158 ) {
case V_162 :
V_160 = & V_2 -> V_89 -> V_90 -> V_163 -> V_164 -> V_159 ;
return F_77 ( V_160 ) ;
case V_165 :
return F_18 ( & V_2 -> V_166 ) >
F_18 ( & V_2 -> V_167 ) + F_18 ( & V_2 -> V_168 ) ;
case V_169 :
case V_170 :
case V_171 :
case V_172 :
case V_173 :
case V_174 :
V_161 = ( V_158 - V_169 + 15 ) ;
return ( V_19 >> ( V_161 - 9 ) ) & 1 ;
case V_175 :
return F_78 ( V_176 , & V_2 -> V_118 ) ;
case V_177 :
return true ;
case V_178 :
default:
return false ;
}
}
static void F_79 ( struct V_3 * V_4 )
{
F_80 ( V_179 ) ;
struct V_1 * V_2 = V_4 -> V_2 ;
struct V_34 * V_6 ;
T_1 V_19 = V_4 -> V_6 . V_19 ;
int V_7 = V_4 -> V_6 . V_7 ;
V_6 = F_81 ( & V_2 -> V_41 , V_19 , V_7 ) ;
if ( ! V_6 )
return;
for (; ; ) {
F_82 ( & V_2 -> V_35 , & V_179 , V_180 ) ;
V_6 = F_81 ( & V_2 -> V_41 , V_19 , V_7 ) ;
if ( ! V_6 )
break;
V_6 -> V_24 = true ;
F_83 ( & V_2 -> V_181 -> V_182 ) ;
F_84 () ;
F_85 ( & V_2 -> V_181 -> V_182 ) ;
}
F_86 ( & V_2 -> V_35 , & V_179 ) ;
}
static void F_87 ( struct V_1 * V_2 )
{
struct V_50 * V_51 = F_39 ( V_2 ) -> V_51 ;
struct V_95 * V_96 ;
bool V_183 = false ;
enum V_184 V_185 ;
F_64 () ;
V_96 = F_65 ( V_51 -> V_95 ) ;
V_185 = V_96 ? V_96 -> V_185 : V_186 ;
F_66 () ;
if ( V_185 == V_186 ||
V_51 -> V_187 < 96 )
return;
if ( V_185 == V_188 && V_2 -> V_152 . V_189 == V_190 )
return;
if ( ! F_24 ( V_2 , V_154 ) )
return;
if ( V_96 -> V_191 &&
F_18 ( & V_2 -> V_81 ) >= V_96 -> V_191 ) {
F_88 ( V_2 , L_13 ) ;
V_183 = true ;
}
if ( V_2 -> V_192 -> V_193 >= V_96 -> V_194 ) {
F_88 ( V_2 , L_14 ) ;
V_183 = true ;
}
if ( V_183 ) {
F_31 ( F_39 ( V_2 ) -> V_51 ) ;
if ( V_185 == V_188 )
F_89 ( F_90 ( V_2 , V_189 , V_190 ) , 0 , NULL ) ;
else
F_89 ( F_90 ( V_2 , V_189 , V_195 ) , 0 , NULL ) ;
}
F_26 ( V_2 ) ;
}
static bool F_91 ( struct V_3 * V_4 )
{
struct V_1 * V_2 = V_4 -> V_2 ;
enum V_157 V_158 ;
if ( V_4 -> V_64 ) {
if ( ! F_72 ( V_2 ,
V_4 -> V_6 . V_19 , V_4 -> V_6 . V_7 ) ) {
F_92 ( V_4 -> V_64 ) ;
V_4 -> V_64 = NULL ;
F_26 ( V_2 ) ;
}
}
if ( V_2 -> V_152 . V_196 != V_154 )
return false ;
if ( V_4 -> V_64 == NULL )
return true ;
F_64 () ;
V_158 = F_65 ( V_2 -> V_89 -> V_197 ) -> V_198 ;
F_66 () ;
if ( V_158 == V_178 && V_4 -> V_64 )
return false ;
if ( F_76 ( V_2 , V_4 -> V_6 . V_19 , V_158 ) ) {
if ( V_4 -> V_64 ) {
F_92 ( V_4 -> V_64 ) ;
V_4 -> V_64 = NULL ;
F_26 ( V_2 ) ;
}
return true ;
}
return false ;
}
static int F_93 ( struct V_3 * V_4 )
{
struct V_1 * V_2 = V_4 -> V_2 ;
int V_199 , V_200 ;
V_199 = F_94 ( V_2 -> V_152 ) ;
V_200 = F_95 ( V_2 -> V_152 ) ;
if ( F_96 ( V_4 -> V_6 . V_7 == 0 ) ) {
F_42 ( V_2 , V_4 -> V_5 -> V_201 & V_202 ) ;
if ( V_199 )
F_97 ( V_4 , V_147 ) ;
return V_199 ;
}
if ( ! V_199 && ! V_200 )
return 0 ;
F_42 ( V_2 , ! ( V_199 && V_200 ) ) ;
if ( V_199 ) {
F_97 ( V_4 , V_99 ) ;
F_97 ( V_4 , V_121 ) ;
} else if ( F_22 ( V_2 , V_4 -> V_6 . V_19 , V_4 -> V_6 . V_7 ) )
F_97 ( V_4 , V_124 ) ;
return V_199 ;
}
static void
F_98 ( struct V_3 * V_4 )
{
struct V_1 * V_2 = V_4 -> V_2 ;
struct V_11 * V_11 = V_4 -> V_64 ;
const int V_58 = F_37 ( V_11 ) ;
V_11 -> V_203 = V_2 -> V_89 -> V_90 ;
if ( F_71 ( V_2 ) ) {
V_4 -> V_204 = V_83 ;
if ( F_99 ( V_2 ,
V_58 == V_16 ? V_205
: V_58 == V_65 ? V_206
: V_207 ) )
F_34 ( V_11 , - V_66 ) ;
else
F_100 ( V_11 ) ;
F_26 ( V_2 ) ;
} else
F_34 ( V_11 , - V_66 ) ;
}
static void F_101 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
F_85 ( & V_2 -> V_181 -> V_182 ) ;
F_102 ( & V_4 -> V_25 , & V_2 -> V_208 . V_209 ) ;
F_102 ( & V_4 -> V_28 ,
& V_2 -> V_210 [ 1 ] ) ;
F_83 ( & V_2 -> V_181 -> V_182 ) ;
F_103 ( V_2 -> V_208 . V_211 , & V_2 -> V_208 . V_212 ) ;
F_15 ( & V_2 -> V_213 ) ;
}
static struct V_3 *
F_104 ( struct V_1 * V_2 , struct V_11 * V_11 , unsigned long V_10 )
{
const int V_58 = F_3 ( V_11 ) ;
struct V_3 * V_4 ;
V_4 = F_6 ( V_2 , V_11 ) ;
if ( ! V_4 ) {
F_35 ( V_2 ) ;
F_19 ( V_2 , L_15 ) ;
F_34 ( V_11 , - V_214 ) ;
return F_105 ( - V_214 ) ;
}
V_4 -> V_10 = V_10 ;
if ( ! F_71 ( V_2 ) ) {
F_92 ( V_4 -> V_64 ) ;
V_4 -> V_64 = NULL ;
}
F_1 ( V_2 , V_4 ) ;
if ( V_58 == V_16 && V_4 -> V_64 && V_4 -> V_6 . V_7
&& ! F_106 ( V_215 , & V_2 -> V_118 ) ) {
if ( ! F_107 ( V_2 , & V_4 -> V_6 ) ) {
F_32 ( & V_2 -> V_216 ) ;
F_101 ( V_2 , V_4 ) ;
return NULL ;
}
V_4 -> V_15 |= V_47 ;
V_4 -> V_217 = V_83 ;
}
return V_4 ;
}
static void F_108 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_218 * V_181 = V_2 -> V_181 ;
const int V_58 = F_37 ( V_4 -> V_5 ) ;
struct V_56 V_57 = { NULL , } ;
bool V_219 = false ;
bool V_220 = false ;
F_85 ( & V_181 -> V_182 ) ;
if ( V_58 == V_16 ) {
F_79 ( V_4 ) ;
F_87 ( V_2 ) ;
}
if ( F_53 ( V_2 ) ) {
V_4 -> V_15 |= V_37 ;
if ( V_4 -> V_64 ) {
F_92 ( V_4 -> V_64 ) ;
V_4 -> V_64 = NULL ;
F_26 ( V_2 ) ;
}
goto V_221;
}
if ( V_58 != V_16 ) {
if ( ! F_91 ( V_4 ) && ! V_4 -> V_64 )
goto V_222;
}
V_4 -> V_18 = F_18 ( & F_39 ( V_2 ) -> V_51 -> V_55 ) ;
if ( F_109 ( V_4 -> V_6 . V_7 != 0 ) ) {
if ( V_58 == V_16 )
F_39 ( V_2 ) -> V_51 -> V_54 ++ ;
F_102 ( & V_4 -> V_25 , & F_39 ( V_2 ) -> V_51 -> V_72 ) ;
}
if ( V_58 == V_16 ) {
if ( ! F_93 ( V_4 ) )
V_219 = true ;
} else {
if ( V_4 -> V_64 == NULL ) {
F_97 ( V_4 , V_99 ) ;
F_97 ( V_4 , V_116 ) ;
} else
V_219 = true ;
}
if ( F_40 ( & V_4 -> V_28 ) )
F_102 ( & V_4 -> V_28 ,
& V_2 -> V_210 [ V_58 == V_16 ] ) ;
if ( V_4 -> V_64 ) {
F_102 ( & V_4 -> V_29 ,
& V_2 -> V_223 [ V_58 == V_16 ] ) ;
F_97 ( V_4 , V_103 ) ;
V_220 = true ;
} else if ( V_219 ) {
V_222:
if ( F_27 ( & V_49 ) )
F_19 ( V_2 , L_16 ,
( unsigned long long ) V_4 -> V_6 . V_19 , V_4 -> V_6 . V_7 >> 9 ) ;
}
V_221:
if ( F_41 ( V_4 , & V_57 , 1 ) )
F_110 ( & V_4 -> V_31 , F_16 ) ;
F_83 ( & V_181 -> V_182 ) ;
if ( V_220 )
F_98 ( V_4 ) ;
if ( V_57 . V_11 )
F_33 ( V_2 , & V_57 ) ;
}
void F_111 ( struct V_1 * V_2 , struct V_11 * V_11 , unsigned long V_10 )
{
struct V_3 * V_4 = F_104 ( V_2 , V_11 , V_10 ) ;
if ( F_112 ( V_4 ) )
return;
F_108 ( V_2 , V_4 ) ;
}
static void F_113 ( struct V_1 * V_2 , struct V_224 * V_225 )
{
struct V_3 * V_4 , * V_226 ;
F_114 (req, tmp, incoming, tl_requests) {
const int V_58 = F_3 ( V_4 -> V_5 ) ;
if ( V_58 == V_16
&& V_4 -> V_64 && V_4 -> V_6 . V_7
&& ! F_106 ( V_215 , & V_2 -> V_118 ) ) {
if ( ! F_107 ( V_2 , & V_4 -> V_6 ) )
continue;
V_4 -> V_15 |= V_47 ;
V_4 -> V_217 = V_83 ;
F_115 ( & V_2 -> V_216 ) ;
}
F_20 ( & V_4 -> V_25 ) ;
F_108 ( V_2 , V_4 ) ;
}
}
static bool F_116 ( struct V_1 * V_2 ,
struct V_224 * V_225 ,
struct V_224 * V_227 ,
struct V_224 * V_228 )
{
struct V_3 * V_4 , * V_226 ;
int V_229 = 0 ;
int V_230 ;
F_85 ( & V_2 -> V_231 ) ;
F_114 (req, tmp, incoming, tl_requests) {
V_230 = F_117 ( V_2 , & V_4 -> V_6 ) ;
if ( V_230 == - V_232 )
break;
if ( V_230 == - V_233 )
V_229 = 1 ;
if ( V_230 )
F_118 ( & V_4 -> V_25 , V_228 ) ;
else
F_118 ( & V_4 -> V_25 , V_227 ) ;
}
F_83 ( & V_2 -> V_231 ) ;
if ( V_229 )
F_15 ( & V_2 -> V_213 ) ;
return ! F_40 ( V_227 ) ;
}
void F_119 ( struct V_1 * V_2 , struct V_224 * V_227 )
{
struct V_3 * V_4 , * V_226 ;
F_114 (req, tmp, pending, tl_requests) {
V_4 -> V_15 |= V_47 ;
V_4 -> V_217 = V_83 ;
F_115 ( & V_2 -> V_216 ) ;
F_20 ( & V_4 -> V_25 ) ;
F_108 ( V_2 , V_4 ) ;
}
}
void F_120 ( struct V_234 * V_235 )
{
struct V_1 * V_2 = F_17 ( V_235 , struct V_1 , V_208 . V_212 ) ;
F_121 ( V_225 ) ;
F_121 ( V_227 ) ;
F_121 ( V_236 ) ;
F_85 ( & V_2 -> V_181 -> V_182 ) ;
F_122 ( & V_2 -> V_208 . V_209 , & V_225 ) ;
F_83 ( & V_2 -> V_181 -> V_182 ) ;
for (; ; ) {
F_80 ( V_179 ) ;
F_123 ( & V_236 , & V_225 ) ;
F_113 ( V_2 , & V_225 ) ;
if ( F_40 ( & V_225 ) )
break;
for (; ; ) {
F_82 ( & V_2 -> V_213 , & V_179 , V_180 ) ;
F_123 ( & V_236 , & V_225 ) ;
F_116 ( V_2 , & V_225 , & V_227 , & V_236 ) ;
if ( ! F_40 ( & V_227 ) )
break;
F_84 () ;
if ( ! F_40 ( & V_225 ) )
continue;
F_85 ( & V_2 -> V_181 -> V_182 ) ;
F_122 ( & V_2 -> V_208 . V_209 , & V_225 ) ;
F_83 ( & V_2 -> V_181 -> V_182 ) ;
}
F_86 ( & V_2 -> V_213 , & V_179 ) ;
while ( F_40 ( & V_225 ) ) {
F_121 ( V_237 ) ;
F_121 ( V_238 ) ;
bool V_239 ;
if ( F_40 ( & V_2 -> V_208 . V_209 ) )
break;
F_85 ( & V_2 -> V_181 -> V_182 ) ;
F_122 ( & V_2 -> V_208 . V_209 , & V_238 ) ;
F_83 ( & V_2 -> V_181 -> V_182 ) ;
if ( F_40 ( & V_238 ) )
break;
V_239 = F_116 ( V_2 , & V_238 , & V_237 , & V_236 ) ;
F_122 ( & V_237 , & V_227 ) ;
F_122 ( & V_238 , & V_225 ) ;
if ( ! V_239 )
break;
}
F_124 ( V_2 ) ;
F_119 ( V_2 , & V_227 ) ;
}
}
void F_125 ( struct V_240 * V_241 , struct V_11 * V_11 )
{
struct V_1 * V_2 = (struct V_1 * ) V_241 -> V_242 ;
unsigned long V_10 ;
V_10 = V_83 ;
F_42 ( V_2 , F_126 ( V_11 -> V_20 . V_22 , 512 ) ) ;
F_127 ( V_2 ) ;
F_111 ( V_2 , V_11 , V_10 ) ;
}
int F_128 ( struct V_240 * V_241 , struct V_243 * V_244 , struct V_245 * V_246 )
{
struct V_1 * V_2 = (struct V_1 * ) V_241 -> V_242 ;
unsigned int V_247 = V_244 -> V_22 ;
int V_248 = V_249 ;
int V_250 ;
if ( V_247 && F_71 ( V_2 ) ) {
unsigned int V_251 = F_129 ( V_241 ) ;
struct V_240 * const V_87 =
V_2 -> V_89 -> V_90 -> V_163 -> V_164 ;
if ( V_87 -> V_252 ) {
V_244 -> V_203 = V_2 -> V_89 -> V_90 ;
V_250 = V_87 -> V_252 ( V_87 , V_244 , V_246 ) ;
V_248 = F_130 ( V_248 , V_250 ) ;
}
F_26 ( V_2 ) ;
if ( ( V_248 >> 9 ) > V_251 )
V_248 = V_251 << 9 ;
}
return V_248 ;
}
void F_131 ( unsigned long V_253 )
{
struct V_1 * V_2 = (struct V_1 * ) V_253 ;
struct V_50 * V_51 = F_39 ( V_2 ) -> V_51 ;
struct V_3 * V_254 , * V_255 , * V_256 ;
struct V_95 * V_96 ;
unsigned long V_257 ;
unsigned long V_258 = 0 , V_259 = 0 , V_260 , V_261 ;
unsigned long V_262 ;
F_64 () ;
V_96 = F_65 ( V_51 -> V_95 ) ;
if ( V_96 && V_2 -> V_152 . V_189 >= V_263 )
V_258 = V_96 -> V_264 * V_265 / 10 * V_96 -> V_266 ;
if ( F_71 ( V_2 ) ) {
V_259 = F_65 ( V_2 -> V_89 -> V_197 ) -> V_267 * V_265 / 10 ;
F_26 ( V_2 ) ;
}
F_66 () ;
V_260 = F_132 ( V_259 , V_258 ) ;
if ( ! V_260 )
return;
V_262 = V_83 ;
V_261 = V_262 + V_260 ;
F_85 ( & V_2 -> V_181 -> V_182 ) ;
V_254 = F_133 ( & V_2 -> V_223 [ 0 ] , struct V_3 , V_29 ) ;
V_255 = F_133 ( & V_2 -> V_223 [ 1 ] , struct V_3 , V_29 ) ;
V_256 = V_51 -> V_75 ;
if ( ! V_256 && V_51 -> V_71 && V_51 -> V_71 -> V_268 )
V_256 = V_51 -> V_71 ;
if ( V_256 && V_256 -> V_2 != V_2 )
V_256 = NULL ;
if ( V_256 == NULL && V_255 == NULL && V_254 == NULL )
goto V_221;
V_257 =
( V_255 && V_254 )
? ( F_134 ( V_255 -> V_204 , V_254 -> V_204 )
? V_255 -> V_204 : V_254 -> V_204 )
: V_255 ? V_255 -> V_204
: V_254 ? V_254 -> V_204 : V_262 ;
if ( V_258 && V_256 &&
F_135 ( V_262 , V_256 -> V_268 + V_258 ) &&
! F_136 ( V_262 , V_51 -> V_269 , V_51 -> V_269 + V_258 ) ) {
F_28 ( V_2 , L_17 ) ;
F_137 ( V_51 , F_138 ( V_189 , V_270 ) , V_271 | V_272 ) ;
}
if ( V_259 && V_257 != V_262 &&
F_135 ( V_262 , V_257 + V_259 ) &&
! F_136 ( V_262 , V_2 -> V_273 , V_2 -> V_273 + V_259 ) ) {
F_28 ( V_2 , L_18 ) ;
F_67 ( V_2 , V_274 ) ;
}
V_258 = ( V_258 && V_256 && F_134 ( V_262 , V_256 -> V_268 + V_258 ) )
? V_256 -> V_268 + V_258 : V_262 + V_260 ;
V_259 = ( V_259 && V_257 != V_262 && F_134 ( V_262 , V_257 + V_259 ) )
? V_257 + V_259 : V_262 + V_260 ;
V_261 = F_134 ( V_258 , V_259 ) ? V_258 : V_259 ;
V_221:
F_83 ( & V_2 -> V_181 -> V_182 ) ;
F_139 ( & V_2 -> V_275 , V_261 ) ;
}
