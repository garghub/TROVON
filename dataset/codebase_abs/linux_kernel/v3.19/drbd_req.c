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
V_4 = F_7 ( V_13 , V_14 | V_15 ) ;
if ( ! V_4 )
return NULL ;
F_8 ( V_4 , V_12 ) ;
V_4 -> V_16 = F_3 ( V_12 ) == V_17 ? V_18 : 0 ;
V_4 -> V_2 = V_2 ;
V_4 -> V_5 = V_12 ;
V_4 -> V_19 = 0 ;
F_9 ( & V_4 -> V_6 ) ;
V_4 -> V_6 . V_20 = V_12 -> V_21 . V_22 ;
V_4 -> V_6 . V_7 = V_12 -> V_21 . V_23 ;
V_4 -> V_6 . V_24 = true ;
V_4 -> V_6 . V_25 = false ;
F_10 ( & V_4 -> V_26 ) ;
F_10 ( & V_4 -> V_27 . V_28 ) ;
F_10 ( & V_4 -> V_29 ) ;
F_10 ( & V_4 -> V_30 ) ;
F_11 ( & V_4 -> V_31 , 1 ) ;
F_12 ( & V_4 -> V_32 ) ;
return V_4 ;
}
static void F_13 ( struct V_33 * V_34 ,
struct V_3 * V_4 )
{
struct V_1 * V_2 = V_4 -> V_2 ;
struct V_35 * V_6 = & V_4 -> V_6 ;
F_14 ( V_34 , V_6 ) ;
if ( V_6 -> V_25 )
F_15 ( & V_2 -> V_36 ) ;
}
void F_16 ( struct V_32 * V_32 )
{
struct V_3 * V_4 = F_17 ( V_32 , struct V_3 , V_32 ) ;
struct V_1 * V_2 = V_4 -> V_2 ;
const unsigned V_37 = V_4 -> V_16 ;
if ( ( V_4 -> V_5 && ! ( V_37 & V_38 ) ) ||
F_18 ( & V_4 -> V_31 ) ||
( V_37 & V_39 ) ||
( ( V_37 & V_40 ) && ! ( V_37 & V_41 ) ) ) {
F_19 ( V_2 , L_1 ,
V_37 , F_18 ( & V_4 -> V_31 ) ) ;
return;
}
F_20 ( & V_4 -> V_26 ) ;
if ( ! F_21 ( & V_4 -> V_6 ) ) {
struct V_33 * V_34 ;
if ( V_37 & V_18 )
V_34 = & V_2 -> V_42 ;
else
V_34 = & V_2 -> V_43 ;
F_13 ( V_34 , V_4 ) ;
} else if ( V_37 & ( V_40 & ~ V_41 ) && V_4 -> V_6 . V_7 != 0 )
F_19 ( V_2 , L_2 ,
V_37 , ( unsigned long long ) V_4 -> V_6 . V_20 , V_4 -> V_6 . V_7 ) ;
if ( V_37 & V_18 ) {
if ( ( V_37 & ( V_38 | V_44 | V_40 ) ) != V_38 ) {
if ( ! ( V_37 & V_45 ) || ! ( V_37 & V_46 ) )
F_22 ( V_2 , V_4 -> V_6 . V_20 , V_4 -> V_6 . V_7 ) ;
if ( ( V_37 & V_45 ) && ( V_37 & V_46 ) && ( V_37 & V_47 ) )
F_23 ( V_2 , V_4 -> V_6 . V_20 , V_4 -> V_6 . V_7 ) ;
}
if ( V_37 & V_48 ) {
if ( F_24 ( V_2 , V_49 ) ) {
F_25 ( V_2 , & V_4 -> V_6 ) ;
F_26 ( V_2 ) ;
} else if ( F_27 ( & V_50 ) ) {
F_28 ( V_2 , L_3
L_4 ,
( unsigned long long ) V_4 -> V_6 . V_20 , V_4 -> V_6 . V_7 ) ;
}
}
}
F_29 ( V_4 , V_13 ) ;
}
static void F_30 ( struct V_51 * V_52 )
{
F_15 ( & V_52 -> V_53 . V_54 ) ;
}
void F_31 ( struct V_51 * V_52 )
{
if ( V_52 -> V_55 == 0 )
return;
V_52 -> V_55 = 0 ;
F_32 ( & V_52 -> V_56 ) ;
F_30 ( V_52 ) ;
}
void F_33 ( struct V_1 * V_2 ,
struct V_57 * V_58 )
{
F_34 ( V_58 -> V_11 , V_58 -> error ) ;
F_35 ( V_2 ) ;
}
static
void F_36 ( struct V_3 * V_4 , struct V_57 * V_58 )
{
const unsigned V_37 = V_4 -> V_16 ;
struct V_1 * V_2 = V_4 -> V_2 ;
int V_59 ;
int error , V_60 ;
if ( ( V_37 & V_39 && ! ( V_37 & V_61 ) ) ||
( V_37 & V_62 ) || ( V_37 & V_63 ) ||
( V_37 & V_64 ) ) {
F_19 ( V_2 , L_5 , V_37 ) ;
return;
}
if ( ! V_4 -> V_5 ) {
F_19 ( V_2 , L_6 ) ;
return;
}
V_59 = F_37 ( V_4 -> V_5 ) ;
V_60 = ( V_37 & V_46 ) || ( V_37 & V_45 ) ;
error = F_38 ( V_4 -> V_65 ) ;
if ( V_59 == V_17 &&
V_4 -> V_19 == F_18 ( & F_39 ( V_2 ) -> V_52 -> V_56 ) )
F_31 ( F_39 ( V_2 ) -> V_52 ) ;
F_4 ( V_2 , V_4 ) ;
if ( ! V_60 && V_59 == V_66 && ! F_40 ( & V_4 -> V_26 ) )
V_4 -> V_16 |= V_38 ;
if ( ! ( V_4 -> V_16 & V_38 ) ) {
V_58 -> error = V_60 ? 0 : ( error ? : - V_67 ) ;
V_58 -> V_11 = V_4 -> V_5 ;
V_4 -> V_5 = NULL ;
V_4 -> V_6 . V_68 = true ;
}
if ( V_4 -> V_6 . V_25 )
F_15 ( & V_2 -> V_36 ) ;
F_20 ( & V_4 -> V_29 ) ;
}
static int F_41 ( struct V_3 * V_4 , struct V_57 * V_58 , int V_69 )
{
struct V_1 * V_2 = V_4 -> V_2 ;
F_42 ( V_2 , V_58 || ( V_4 -> V_16 & V_38 ) ) ;
if ( ! F_43 ( V_69 , & V_4 -> V_31 ) )
return 0 ;
F_36 ( V_4 , V_58 ) ;
if ( V_4 -> V_16 & V_38 ) {
F_44 ( V_4 ) ;
return 0 ;
}
return 1 ;
}
static void F_45 ( struct V_70 * V_71 , struct V_3 * V_4 )
{
struct V_51 * V_52 = V_71 ? V_71 -> V_52 : NULL ;
if ( ! V_52 )
return;
if ( V_52 -> V_72 == NULL )
V_52 -> V_72 = V_4 ;
}
static void F_46 ( struct V_70 * V_71 , struct V_3 * V_4 )
{
struct V_51 * V_52 = V_71 ? V_71 -> V_52 : NULL ;
if ( ! V_52 )
return;
if ( V_52 -> V_72 != V_4 )
return;
F_47 (req, &connection->transfer_log, tl_requests) {
const unsigned V_37 = V_4 -> V_16 ;
if ( V_37 & V_62 )
break;
}
if ( & V_4 -> V_26 == & V_52 -> V_73 )
V_4 = NULL ;
V_52 -> V_72 = V_4 ;
}
static void F_48 ( struct V_70 * V_71 , struct V_3 * V_4 )
{
struct V_51 * V_52 = V_71 ? V_71 -> V_52 : NULL ;
if ( ! V_52 )
return;
if ( V_52 -> V_74 == NULL )
V_52 -> V_74 = V_4 ;
}
static void F_49 ( struct V_70 * V_71 , struct V_3 * V_4 )
{
struct V_51 * V_52 = V_71 ? V_71 -> V_52 : NULL ;
if ( ! V_52 )
return;
if ( V_52 -> V_74 != V_4 )
return;
F_47 (req, &connection->transfer_log, tl_requests) {
const unsigned V_37 = V_4 -> V_16 ;
if ( ( V_37 & V_75 ) && ( V_37 & V_63 ) )
break;
}
if ( & V_4 -> V_26 == & V_52 -> V_73 )
V_4 = NULL ;
V_52 -> V_74 = V_4 ;
}
static void F_50 ( struct V_70 * V_71 , struct V_3 * V_4 )
{
struct V_51 * V_52 = V_71 ? V_71 -> V_52 : NULL ;
if ( ! V_52 )
return;
if ( V_52 -> V_76 == NULL )
V_52 -> V_76 = V_4 ;
}
static void F_51 ( struct V_70 * V_71 , struct V_3 * V_4 )
{
struct V_51 * V_52 = V_71 ? V_71 -> V_52 : NULL ;
if ( ! V_52 )
return;
if ( V_52 -> V_76 != V_4 )
return;
F_47 (req, &connection->transfer_log, tl_requests) {
const unsigned V_37 = V_4 -> V_16 ;
if ( ( V_37 & V_75 ) && ! ( V_37 & V_41 ) )
break;
}
if ( & V_4 -> V_26 == & V_52 -> V_73 )
V_4 = NULL ;
V_52 -> V_76 = V_4 ;
}
static void F_52 ( struct V_3 * V_4 , struct V_57 * V_58 ,
int V_77 , int V_78 )
{
struct V_1 * V_2 = V_4 -> V_2 ;
struct V_70 * V_71 = F_39 ( V_2 ) ;
unsigned V_37 = V_4 -> V_16 ;
int V_79 = 0 ;
int V_80 = 0 ;
if ( F_53 ( V_2 ) && ! ( ( V_37 | V_77 ) & V_64 ) )
V_78 |= V_64 ;
V_4 -> V_16 &= ~ V_77 ;
V_4 -> V_16 |= V_78 ;
if ( V_4 -> V_16 == V_37 )
return;
if ( ! ( V_37 & V_39 ) && ( V_78 & V_39 ) )
F_32 ( & V_4 -> V_31 ) ;
if ( ! ( V_37 & V_63 ) && ( V_78 & V_63 ) ) {
F_54 ( V_2 ) ;
F_32 ( & V_4 -> V_31 ) ;
}
if ( ! ( V_37 & V_62 ) && ( V_78 & V_62 ) ) {
F_32 ( & V_4 -> V_31 ) ;
F_45 ( V_71 , V_4 ) ;
}
if ( ! ( V_37 & V_81 ) && ( V_78 & V_81 ) )
F_55 ( & V_4 -> V_32 ) ;
if ( ! ( V_37 & V_75 ) && ( V_78 & V_75 ) ) {
if ( ! ( V_37 & V_41 ) ) {
F_56 ( V_4 -> V_6 . V_7 >> 9 , & V_2 -> V_82 ) ;
F_50 ( V_71 , V_4 ) ;
}
if ( V_37 & V_63 )
F_48 ( V_71 , V_4 ) ;
}
if ( ! ( V_37 & V_64 ) && ( V_78 & V_64 ) )
F_32 ( & V_4 -> V_31 ) ;
if ( ( V_37 & V_64 ) && ( V_77 & V_64 ) )
++ V_79 ;
if ( ! ( V_37 & V_61 ) && ( V_78 & V_61 ) ) {
F_42 ( V_2 , V_4 -> V_16 & V_39 ) ;
F_55 ( & V_4 -> V_32 ) ;
++ V_79 ;
}
if ( ( V_37 & V_39 ) && ( V_77 & V_39 ) ) {
if ( V_4 -> V_16 & V_61 )
++ V_80 ;
else
++ V_79 ;
F_20 ( & V_4 -> V_30 ) ;
}
if ( ( V_37 & V_63 ) && ( V_77 & V_63 ) ) {
F_57 ( V_2 ) ;
++ V_79 ;
V_4 -> V_83 = V_84 ;
F_49 ( V_71 , V_4 ) ;
}
if ( ( V_37 & V_62 ) && ( V_77 & V_62 ) ) {
++ V_79 ;
F_46 ( V_71 , V_4 ) ;
}
if ( ! ( V_37 & V_41 ) && ( V_78 & V_41 ) ) {
if ( V_37 & V_75 )
F_58 ( V_4 -> V_6 . V_7 >> 9 , & V_2 -> V_82 ) ;
if ( V_37 & V_81 )
++ V_80 ;
V_4 -> V_85 = V_84 ;
F_46 ( V_71 , V_4 ) ;
F_49 ( V_71 , V_4 ) ;
F_51 ( V_71 , V_4 ) ;
}
if ( V_80 || V_79 ) {
int V_86 = V_80 + ! ! V_79 ;
int V_87 = F_18 ( & V_4 -> V_32 . V_87 ) ;
if ( V_87 < V_86 )
F_19 ( V_2 ,
L_7 ,
V_37 , V_4 -> V_16 , V_87 , V_86 ) ;
}
if ( V_4 -> V_6 . V_25 )
F_15 ( & V_2 -> V_36 ) ;
if ( V_79 )
V_80 += F_41 ( V_4 , V_58 , V_79 ) ;
if ( V_80 )
F_59 ( & V_4 -> V_32 , V_80 , F_16 ) ;
}
static void F_60 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
char V_88 [ V_89 ] ;
if ( ! F_27 ( & V_50 ) )
return;
F_28 ( V_2 , L_8 ,
( V_4 -> V_16 & V_18 ) ? L_9 : L_10 ,
( unsigned long long ) V_4 -> V_6 . V_20 ,
V_4 -> V_6 . V_7 >> 9 ,
F_61 ( V_2 -> V_90 -> V_91 , V_88 ) ) ;
}
static inline bool F_62 ( struct V_3 * V_4 )
{
return ( V_4 -> V_16 &
( V_18 | V_63 | V_92 | V_93 ) )
== ( V_18 | V_63 ) ;
}
int F_63 ( struct V_3 * V_4 , enum V_94 V_95 ,
struct V_57 * V_58 )
{
struct V_1 * const V_2 = V_4 -> V_2 ;
struct V_70 * const V_71 = F_39 ( V_2 ) ;
struct V_51 * const V_52 = V_71 ? V_71 -> V_52 : NULL ;
struct V_96 * V_97 ;
int V_98 , V_99 = 0 ;
if ( V_58 )
V_58 -> V_11 = NULL ;
switch ( V_95 ) {
default:
F_19 ( V_2 , L_11 , __FILE__ , __LINE__ ) ;
break;
case V_100 :
F_42 ( V_2 , ! ( V_4 -> V_16 & V_40 ) ) ;
F_64 () ;
V_97 = F_65 ( V_52 -> V_96 ) ;
V_98 = V_97 -> V_101 ;
F_66 () ;
V_4 -> V_16 |=
V_98 == V_102 ? V_92 :
V_98 == V_103 ? V_93 : 0 ;
F_52 ( V_4 , V_58 , 0 , V_63 ) ;
break;
case V_104 :
F_42 ( V_2 , ! ( V_4 -> V_16 & V_44 ) ) ;
F_52 ( V_4 , V_58 , 0 , V_39 ) ;
break;
case V_105 :
if ( V_4 -> V_16 & V_18 )
V_2 -> V_106 += V_4 -> V_6 . V_7 >> 9 ;
else
V_2 -> V_107 += V_4 -> V_6 . V_7 >> 9 ;
F_52 ( V_4 , V_58 , V_39 ,
V_108 | V_46 ) ;
break;
case V_109 :
F_52 ( V_4 , V_58 , 0 , V_61 ) ;
break;
case V_110 :
F_60 ( V_2 , V_4 ) ;
F_67 ( V_2 , V_111 ) ;
F_52 ( V_4 , V_58 , V_39 , V_108 ) ;
break;
case V_112 :
F_22 ( V_2 , V_4 -> V_6 . V_20 , V_4 -> V_6 . V_7 ) ;
F_60 ( V_2 , V_4 ) ;
F_67 ( V_2 , V_113 ) ;
case V_114 :
F_52 ( V_4 , V_58 , V_39 , V_108 ) ;
break;
case V_115 :
case V_116 :
F_52 ( V_4 , V_58 , V_39 , V_108 ) ;
break;
case V_117 :
F_42 ( V_2 , F_21 ( & V_4 -> V_6 ) ) ;
F_68 ( & V_2 -> V_43 , & V_4 -> V_6 ) ;
F_69 ( V_118 , & V_2 -> V_119 ) ;
F_42 ( V_2 , V_4 -> V_16 & V_63 ) ;
F_42 ( V_2 , ( V_4 -> V_16 & V_44 ) == 0 ) ;
F_52 ( V_4 , V_58 , 0 , V_62 ) ;
V_4 -> V_27 . V_120 = V_121 ;
F_70 ( & V_52 -> V_53 ,
& V_4 -> V_27 ) ;
break;
case V_122 :
F_42 ( V_2 , F_21 ( & V_4 -> V_6 ) ) ;
F_68 ( & V_2 -> V_42 , & V_4 -> V_6 ) ;
F_69 ( V_118 , & V_2 -> V_119 ) ;
F_42 ( V_2 , V_4 -> V_16 & V_63 ) ;
F_52 ( V_4 , V_58 , 0 , V_62 | V_81 ) ;
V_4 -> V_27 . V_120 = V_123 ;
F_70 ( & V_52 -> V_53 ,
& V_4 -> V_27 ) ;
F_64 () ;
V_97 = F_65 ( V_52 -> V_96 ) ;
V_98 = V_97 -> V_124 ;
F_66 () ;
if ( V_52 -> V_55 >= V_98 )
F_31 ( V_52 ) ;
break;
case V_125 :
F_52 ( V_4 , V_58 , 0 , V_62 ) ;
V_4 -> V_27 . V_120 = V_126 ;
F_70 ( & V_52 -> V_53 ,
& V_4 -> V_27 ) ;
break;
case V_127 :
case V_128 :
case V_129 :
F_52 ( V_4 , V_58 , V_62 , 0 ) ;
break;
case V_130 :
if ( F_62 ( V_4 ) )
F_52 ( V_4 , V_58 , V_62 | V_63 ,
V_75 | V_45 ) ;
else
F_52 ( V_4 , V_58 , V_62 , V_75 ) ;
break;
case V_131 :
F_52 ( V_4 , V_58 , V_62 , V_41 ) ;
break;
case V_132 :
F_52 ( V_4 , V_58 ,
V_45 | V_63 | V_64 ,
V_41 ) ;
break;
case V_133 :
F_42 ( V_2 , V_4 -> V_16 & V_63 ) ;
F_42 ( V_2 , V_4 -> V_16 & V_92 ) ;
F_52 ( V_4 , V_58 , V_63 , V_41 | V_45 ) ;
break;
case V_134 :
V_4 -> V_16 |= V_47 ;
case V_135 :
goto V_136;
case V_137 :
F_42 ( V_2 , V_4 -> V_16 & V_93 ) ;
V_136:
F_52 ( V_4 , V_58 , V_63 , V_45 ) ;
break;
case V_138 :
F_42 ( V_2 , V_4 -> V_16 & V_92 ) ;
F_42 ( V_2 , V_4 -> V_16 & V_63 ) ;
V_4 -> V_16 |= V_38 ;
if ( V_4 -> V_6 . V_25 )
F_15 ( & V_2 -> V_36 ) ;
break;
case V_139 :
F_52 ( V_4 , V_58 , V_45 | V_63 , 0 ) ;
break;
case V_140 :
if ( ! ( V_4 -> V_16 & V_108 ) )
break;
F_52 ( V_4 , V_58 , V_64 , 0 ) ;
break;
case V_141 :
if ( ! ( V_4 -> V_16 & V_108 ) )
break;
F_52 ( V_4 , V_58 ,
V_64 | V_108 ,
V_39 ) ;
V_99 = V_142 ;
if ( F_3 ( V_4 -> V_5 ) == V_17 )
V_99 = V_143 ;
F_71 ( V_2 ) ;
V_4 -> V_27 . V_120 = V_144 ;
F_70 ( & V_52 -> V_53 ,
& V_4 -> V_27 ) ;
break;
case V_145 :
if ( ! ( V_4 -> V_16 & V_18 ) && ! V_4 -> V_27 . V_120 ) {
F_52 ( V_4 , V_58 , V_64 , 0 ) ;
break;
}
if ( ! ( V_4 -> V_16 & V_45 ) ) {
F_52 ( V_4 , V_58 , V_64 , V_62 | V_63 ) ;
if ( V_4 -> V_27 . V_120 ) {
F_70 ( & V_52 -> V_53 ,
& V_4 -> V_27 ) ;
V_99 = V_4 -> V_16 & V_18 ? V_143 : V_142 ;
}
break;
}
case V_146 :
if ( ! ( V_4 -> V_16 & V_18 ) )
break;
if ( V_4 -> V_16 & V_63 ) {
F_19 ( V_2 , L_12 ) ;
}
F_52 ( V_4 , V_58 , V_64 ,
( V_4 -> V_16 & V_40 ) ? V_41 : 0 ) ;
break;
case V_147 :
F_42 ( V_2 , V_4 -> V_16 & V_63 ) ;
F_52 ( V_4 , V_58 , V_63 , V_45 | V_41 ) ;
break;
case V_148 :
F_31 ( V_52 ) ;
F_52 ( V_4 , V_58 , 0 , V_45 | V_41 ) ;
break;
} ;
return V_99 ;
}
static bool F_72 ( struct V_1 * V_2 , T_1 V_20 , int V_7 )
{
unsigned long V_149 , V_150 ;
T_1 V_151 , V_152 ;
if ( V_2 -> V_153 . V_154 == V_155 )
return true ;
if ( V_2 -> V_153 . V_154 != V_156 )
return false ;
V_151 = V_20 + ( V_7 >> 9 ) - 1 ;
V_152 = F_73 ( V_2 -> V_157 ) ;
F_42 ( V_2 , V_20 < V_152 ) ;
F_42 ( V_2 , V_151 < V_152 ) ;
V_149 = F_74 ( V_20 ) ;
V_150 = F_74 ( V_151 ) ;
return F_75 ( V_2 , V_149 , V_150 ) == 0 ;
}
static bool F_76 ( struct V_1 * V_2 , T_1 V_20 ,
enum V_158 V_159 )
{
struct V_160 * V_161 ;
int V_162 ;
switch ( V_159 ) {
case V_163 :
V_161 = & V_2 -> V_90 -> V_91 -> V_164 -> V_165 -> V_160 ;
return F_77 ( V_161 ) ;
case V_166 :
return F_18 ( & V_2 -> V_167 ) >
F_18 ( & V_2 -> V_168 ) + F_18 ( & V_2 -> V_169 ) ;
case V_170 :
case V_171 :
case V_172 :
case V_173 :
case V_174 :
case V_175 :
V_162 = ( V_159 - V_170 + 15 ) ;
return ( V_20 >> ( V_162 - 9 ) ) & 1 ;
case V_176 :
return F_78 ( V_177 , & V_2 -> V_119 ) ;
case V_178 :
return true ;
case V_179 :
default:
return false ;
}
}
static void F_79 ( struct V_3 * V_4 )
{
F_80 ( V_180 ) ;
struct V_1 * V_2 = V_4 -> V_2 ;
struct V_35 * V_6 ;
T_1 V_20 = V_4 -> V_6 . V_20 ;
int V_7 = V_4 -> V_6 . V_7 ;
V_6 = F_81 ( & V_2 -> V_42 , V_20 , V_7 ) ;
if ( ! V_6 )
return;
for (; ; ) {
F_82 ( & V_2 -> V_36 , & V_180 , V_181 ) ;
V_6 = F_81 ( & V_2 -> V_42 , V_20 , V_7 ) ;
if ( ! V_6 )
break;
V_6 -> V_25 = true ;
F_83 ( & V_2 -> V_182 -> V_183 ) ;
F_84 () ;
F_85 ( & V_2 -> V_182 -> V_183 ) ;
}
F_86 ( & V_2 -> V_36 , & V_180 ) ;
}
static void F_87 ( struct V_1 * V_2 )
{
struct V_51 * V_52 = F_39 ( V_2 ) -> V_52 ;
struct V_96 * V_97 ;
bool V_184 = false ;
enum V_185 V_186 ;
F_64 () ;
V_97 = F_65 ( V_52 -> V_96 ) ;
V_186 = V_97 ? V_97 -> V_186 : V_187 ;
F_66 () ;
if ( V_186 == V_187 ||
V_52 -> V_188 < 96 )
return;
if ( V_186 == V_189 && V_2 -> V_153 . V_190 == V_191 )
return;
if ( ! F_24 ( V_2 , V_155 ) )
return;
if ( V_97 -> V_192 &&
F_18 ( & V_2 -> V_82 ) >= V_97 -> V_192 ) {
F_88 ( V_2 , L_13 ) ;
V_184 = true ;
}
if ( V_2 -> V_193 -> V_194 >= V_97 -> V_195 ) {
F_88 ( V_2 , L_14 ) ;
V_184 = true ;
}
if ( V_184 ) {
F_31 ( F_39 ( V_2 ) -> V_52 ) ;
if ( V_186 == V_189 )
F_89 ( F_90 ( V_2 , V_190 , V_191 ) , 0 , NULL ) ;
else
F_89 ( F_90 ( V_2 , V_190 , V_196 ) , 0 , NULL ) ;
}
F_26 ( V_2 ) ;
}
static bool F_91 ( struct V_3 * V_4 )
{
struct V_1 * V_2 = V_4 -> V_2 ;
enum V_158 V_159 ;
if ( V_4 -> V_65 ) {
if ( ! F_72 ( V_2 ,
V_4 -> V_6 . V_20 , V_4 -> V_6 . V_7 ) ) {
F_92 ( V_4 -> V_65 ) ;
V_4 -> V_65 = NULL ;
F_26 ( V_2 ) ;
}
}
if ( V_2 -> V_153 . V_197 != V_155 )
return false ;
if ( V_4 -> V_65 == NULL )
return true ;
F_64 () ;
V_159 = F_65 ( V_2 -> V_90 -> V_198 ) -> V_199 ;
F_66 () ;
if ( V_159 == V_179 && V_4 -> V_65 )
return false ;
if ( F_76 ( V_2 , V_4 -> V_6 . V_20 , V_159 ) ) {
if ( V_4 -> V_65 ) {
F_92 ( V_4 -> V_65 ) ;
V_4 -> V_65 = NULL ;
F_26 ( V_2 ) ;
}
return true ;
}
return false ;
}
static int F_93 ( struct V_3 * V_4 )
{
struct V_1 * V_2 = V_4 -> V_2 ;
int V_200 , V_201 ;
V_200 = F_94 ( V_2 -> V_153 ) ;
V_201 = F_95 ( V_2 -> V_153 ) ;
if ( F_96 ( V_4 -> V_6 . V_7 == 0 ) ) {
F_42 ( V_2 , V_4 -> V_5 -> V_202 & V_203 ) ;
if ( V_200 )
F_97 ( V_4 , V_148 ) ;
return V_200 ;
}
if ( ! V_200 && ! V_201 )
return 0 ;
F_42 ( V_2 , ! ( V_200 && V_201 ) ) ;
if ( V_200 ) {
F_97 ( V_4 , V_100 ) ;
F_97 ( V_4 , V_122 ) ;
} else if ( F_22 ( V_2 , V_4 -> V_6 . V_20 , V_4 -> V_6 . V_7 ) )
F_97 ( V_4 , V_125 ) ;
return V_200 ;
}
static void
F_98 ( struct V_3 * V_4 )
{
struct V_1 * V_2 = V_4 -> V_2 ;
struct V_11 * V_11 = V_4 -> V_65 ;
const int V_59 = F_37 ( V_11 ) ;
V_11 -> V_204 = V_2 -> V_90 -> V_91 ;
if ( F_71 ( V_2 ) ) {
V_4 -> V_205 = V_84 ;
if ( F_99 ( V_2 ,
V_59 == V_17 ? V_206
: V_59 == V_66 ? V_207
: V_208 ) )
F_34 ( V_11 , - V_67 ) ;
else
F_100 ( V_11 ) ;
F_26 ( V_2 ) ;
} else
F_34 ( V_11 , - V_67 ) ;
}
static void F_101 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
F_85 ( & V_2 -> V_182 -> V_183 ) ;
F_102 ( & V_4 -> V_26 , & V_2 -> V_209 . V_210 ) ;
F_102 ( & V_4 -> V_29 ,
& V_2 -> V_211 [ 1 ] ) ;
F_83 ( & V_2 -> V_182 -> V_183 ) ;
F_103 ( V_2 -> V_209 . V_212 , & V_2 -> V_209 . V_213 ) ;
F_15 ( & V_2 -> V_214 ) ;
}
static struct V_3 *
F_104 ( struct V_1 * V_2 , struct V_11 * V_11 , unsigned long V_10 )
{
const int V_59 = F_3 ( V_11 ) ;
struct V_3 * V_4 ;
V_4 = F_6 ( V_2 , V_11 ) ;
if ( ! V_4 ) {
F_35 ( V_2 ) ;
F_19 ( V_2 , L_15 ) ;
F_34 ( V_11 , - V_215 ) ;
return F_105 ( - V_215 ) ;
}
V_4 -> V_10 = V_10 ;
if ( ! F_71 ( V_2 ) ) {
F_92 ( V_4 -> V_65 ) ;
V_4 -> V_65 = NULL ;
}
F_1 ( V_2 , V_4 ) ;
if ( V_59 == V_17 && V_4 -> V_65 && V_4 -> V_6 . V_7
&& ! F_106 ( V_216 , & V_2 -> V_119 ) ) {
if ( ! F_107 ( V_2 , & V_4 -> V_6 ) ) {
F_32 ( & V_2 -> V_217 ) ;
F_101 ( V_2 , V_4 ) ;
return NULL ;
}
V_4 -> V_16 |= V_48 ;
V_4 -> V_218 = V_84 ;
}
return V_4 ;
}
static void F_108 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_219 * V_182 = V_2 -> V_182 ;
const int V_59 = F_37 ( V_4 -> V_5 ) ;
struct V_57 V_58 = { NULL , } ;
bool V_220 = false ;
bool V_221 = false ;
F_85 ( & V_182 -> V_183 ) ;
if ( V_59 == V_17 ) {
F_79 ( V_4 ) ;
F_87 ( V_2 ) ;
}
if ( F_53 ( V_2 ) ) {
V_4 -> V_16 |= V_38 ;
if ( V_4 -> V_65 ) {
F_92 ( V_4 -> V_65 ) ;
V_4 -> V_65 = NULL ;
F_26 ( V_2 ) ;
}
goto V_222;
}
if ( V_59 != V_17 ) {
if ( ! F_91 ( V_4 ) && ! V_4 -> V_65 )
goto V_223;
}
V_4 -> V_19 = F_18 ( & F_39 ( V_2 ) -> V_52 -> V_56 ) ;
if ( F_109 ( V_4 -> V_6 . V_7 != 0 ) ) {
if ( V_59 == V_17 )
F_39 ( V_2 ) -> V_52 -> V_55 ++ ;
F_102 ( & V_4 -> V_26 , & F_39 ( V_2 ) -> V_52 -> V_73 ) ;
}
if ( V_59 == V_17 ) {
if ( ! F_93 ( V_4 ) )
V_220 = true ;
} else {
if ( V_4 -> V_65 == NULL ) {
F_97 ( V_4 , V_100 ) ;
F_97 ( V_4 , V_117 ) ;
} else
V_220 = true ;
}
if ( F_40 ( & V_4 -> V_29 ) )
F_102 ( & V_4 -> V_29 ,
& V_2 -> V_211 [ V_59 == V_17 ] ) ;
if ( V_4 -> V_65 ) {
F_102 ( & V_4 -> V_30 ,
& V_2 -> V_224 [ V_59 == V_17 ] ) ;
F_97 ( V_4 , V_104 ) ;
V_221 = true ;
} else if ( V_220 ) {
V_223:
if ( F_27 ( & V_50 ) )
F_19 ( V_2 , L_16 ,
( unsigned long long ) V_4 -> V_6 . V_20 , V_4 -> V_6 . V_7 >> 9 ) ;
}
V_222:
if ( F_41 ( V_4 , & V_58 , 1 ) )
F_110 ( & V_4 -> V_32 , F_16 ) ;
F_83 ( & V_182 -> V_183 ) ;
if ( V_221 )
F_98 ( V_4 ) ;
if ( V_58 . V_11 )
F_33 ( V_2 , & V_58 ) ;
}
void F_111 ( struct V_1 * V_2 , struct V_11 * V_11 , unsigned long V_10 )
{
struct V_3 * V_4 = F_104 ( V_2 , V_11 , V_10 ) ;
if ( F_112 ( V_4 ) )
return;
F_108 ( V_2 , V_4 ) ;
}
static void F_113 ( struct V_1 * V_2 , struct V_225 * V_226 )
{
struct V_3 * V_4 , * V_227 ;
F_114 (req, tmp, incoming, tl_requests) {
const int V_59 = F_3 ( V_4 -> V_5 ) ;
if ( V_59 == V_17
&& V_4 -> V_65 && V_4 -> V_6 . V_7
&& ! F_106 ( V_216 , & V_2 -> V_119 ) ) {
if ( ! F_107 ( V_2 , & V_4 -> V_6 ) )
continue;
V_4 -> V_16 |= V_48 ;
V_4 -> V_218 = V_84 ;
F_115 ( & V_2 -> V_217 ) ;
}
F_20 ( & V_4 -> V_26 ) ;
F_108 ( V_2 , V_4 ) ;
}
}
static bool F_116 ( struct V_1 * V_2 ,
struct V_225 * V_226 ,
struct V_225 * V_228 ,
struct V_225 * V_229 )
{
struct V_3 * V_4 , * V_227 ;
int V_230 = 0 ;
int V_231 ;
F_85 ( & V_2 -> V_232 ) ;
F_114 (req, tmp, incoming, tl_requests) {
V_231 = F_117 ( V_2 , & V_4 -> V_6 ) ;
if ( V_231 == - V_233 )
break;
if ( V_231 == - V_234 )
V_230 = 1 ;
if ( V_231 )
F_118 ( & V_4 -> V_26 , V_229 ) ;
else
F_118 ( & V_4 -> V_26 , V_228 ) ;
}
F_83 ( & V_2 -> V_232 ) ;
if ( V_230 )
F_15 ( & V_2 -> V_214 ) ;
return ! F_40 ( V_228 ) ;
}
void F_119 ( struct V_1 * V_2 , struct V_225 * V_228 )
{
struct V_3 * V_4 , * V_227 ;
F_114 (req, tmp, pending, tl_requests) {
V_4 -> V_16 |= V_48 ;
V_4 -> V_218 = V_84 ;
F_115 ( & V_2 -> V_217 ) ;
F_20 ( & V_4 -> V_26 ) ;
F_108 ( V_2 , V_4 ) ;
}
}
void F_120 ( struct V_235 * V_236 )
{
struct V_1 * V_2 = F_17 ( V_236 , struct V_1 , V_209 . V_213 ) ;
F_121 ( V_226 ) ;
F_121 ( V_228 ) ;
F_121 ( V_237 ) ;
F_85 ( & V_2 -> V_182 -> V_183 ) ;
F_122 ( & V_2 -> V_209 . V_210 , & V_226 ) ;
F_83 ( & V_2 -> V_182 -> V_183 ) ;
for (; ; ) {
F_80 ( V_180 ) ;
F_123 ( & V_237 , & V_226 ) ;
F_113 ( V_2 , & V_226 ) ;
if ( F_40 ( & V_226 ) )
break;
for (; ; ) {
F_82 ( & V_2 -> V_214 , & V_180 , V_181 ) ;
F_123 ( & V_237 , & V_226 ) ;
F_116 ( V_2 , & V_226 , & V_228 , & V_237 ) ;
if ( ! F_40 ( & V_228 ) )
break;
F_84 () ;
if ( ! F_40 ( & V_226 ) )
continue;
F_85 ( & V_2 -> V_182 -> V_183 ) ;
F_122 ( & V_2 -> V_209 . V_210 , & V_226 ) ;
F_83 ( & V_2 -> V_182 -> V_183 ) ;
}
F_86 ( & V_2 -> V_214 , & V_180 ) ;
while ( F_40 ( & V_226 ) ) {
F_121 ( V_238 ) ;
F_121 ( V_239 ) ;
bool V_240 ;
if ( F_40 ( & V_2 -> V_209 . V_210 ) )
break;
F_85 ( & V_2 -> V_182 -> V_183 ) ;
F_122 ( & V_2 -> V_209 . V_210 , & V_239 ) ;
F_83 ( & V_2 -> V_182 -> V_183 ) ;
if ( F_40 ( & V_239 ) )
break;
V_240 = F_116 ( V_2 , & V_239 , & V_238 , & V_237 ) ;
F_122 ( & V_238 , & V_228 ) ;
F_122 ( & V_239 , & V_226 ) ;
if ( ! V_240 )
break;
}
F_124 ( V_2 ) ;
F_119 ( V_2 , & V_228 ) ;
}
}
void F_125 ( struct V_241 * V_242 , struct V_11 * V_11 )
{
struct V_1 * V_2 = (struct V_1 * ) V_242 -> V_243 ;
unsigned long V_10 ;
V_10 = V_84 ;
F_42 ( V_2 , F_126 ( V_11 -> V_21 . V_23 , 512 ) ) ;
F_127 ( V_2 ) ;
F_111 ( V_2 , V_11 , V_10 ) ;
}
int F_128 ( struct V_241 * V_242 , struct V_244 * V_245 , struct V_246 * V_247 )
{
struct V_1 * V_2 = (struct V_1 * ) V_242 -> V_243 ;
unsigned int V_248 = V_245 -> V_23 ;
int V_249 = V_250 ;
int V_251 ;
if ( V_248 && F_71 ( V_2 ) ) {
unsigned int V_252 = F_129 ( V_242 ) ;
struct V_241 * const V_88 =
V_2 -> V_90 -> V_91 -> V_164 -> V_165 ;
if ( V_88 -> V_253 ) {
V_245 -> V_204 = V_2 -> V_90 -> V_91 ;
V_251 = V_88 -> V_253 ( V_88 , V_245 , V_247 ) ;
V_249 = F_130 ( V_249 , V_251 ) ;
}
F_26 ( V_2 ) ;
if ( ( V_249 >> 9 ) > V_252 )
V_249 = V_252 << 9 ;
}
return V_249 ;
}
void F_131 ( unsigned long V_254 )
{
struct V_1 * V_2 = (struct V_1 * ) V_254 ;
struct V_51 * V_52 = F_39 ( V_2 ) -> V_52 ;
struct V_3 * V_255 , * V_256 , * V_257 ;
struct V_96 * V_97 ;
unsigned long V_258 ;
unsigned long V_259 = 0 , V_260 = 0 , V_261 , V_262 ;
unsigned long V_263 ;
F_64 () ;
V_97 = F_65 ( V_52 -> V_96 ) ;
if ( V_97 && V_2 -> V_153 . V_190 >= V_264 )
V_259 = V_97 -> V_265 * V_266 / 10 * V_97 -> V_267 ;
if ( F_71 ( V_2 ) ) {
V_260 = F_65 ( V_2 -> V_90 -> V_198 ) -> V_268 * V_266 / 10 ;
F_26 ( V_2 ) ;
}
F_66 () ;
V_261 = F_132 ( V_260 , V_259 ) ;
if ( ! V_261 )
return;
V_263 = V_84 ;
V_262 = V_263 + V_261 ;
F_85 ( & V_2 -> V_182 -> V_183 ) ;
V_255 = F_133 ( & V_2 -> V_224 [ 0 ] , struct V_3 , V_30 ) ;
V_256 = F_133 ( & V_2 -> V_224 [ 1 ] , struct V_3 , V_30 ) ;
V_257 = V_52 -> V_76 ;
if ( ! V_257 && V_52 -> V_72 && V_52 -> V_72 -> V_269 )
V_257 = V_52 -> V_72 ;
if ( V_257 && V_257 -> V_2 != V_2 )
V_257 = NULL ;
if ( V_257 == NULL && V_256 == NULL && V_255 == NULL )
goto V_222;
V_258 =
( V_256 && V_255 )
? ( F_134 ( V_256 -> V_205 , V_255 -> V_205 )
? V_256 -> V_205 : V_255 -> V_205 )
: V_256 ? V_256 -> V_205
: V_255 ? V_255 -> V_205 : V_263 ;
if ( V_259 && V_257 &&
F_135 ( V_263 , V_257 -> V_269 + V_259 ) &&
! F_136 ( V_263 , V_52 -> V_270 , V_52 -> V_270 + V_259 ) ) {
F_28 ( V_2 , L_17 ) ;
F_137 ( V_52 , F_138 ( V_190 , V_271 ) , V_272 | V_273 ) ;
}
if ( V_260 && V_258 != V_263 &&
F_135 ( V_263 , V_258 + V_260 ) &&
! F_136 ( V_263 , V_2 -> V_274 , V_2 -> V_274 + V_260 ) ) {
F_28 ( V_2 , L_18 ) ;
F_67 ( V_2 , V_275 ) ;
}
V_259 = ( V_259 && V_257 && F_134 ( V_263 , V_257 -> V_269 + V_259 ) )
? V_257 -> V_269 + V_259 : V_263 + V_261 ;
V_260 = ( V_260 && V_258 != V_263 && F_134 ( V_263 , V_258 + V_260 ) )
? V_258 + V_260 : V_263 + V_261 ;
V_262 = F_134 ( V_259 , V_260 ) ? V_259 : V_260 ;
V_222:
F_83 ( & V_2 -> V_182 -> V_183 ) ;
F_139 ( & V_2 -> V_276 , V_262 ) ;
}
