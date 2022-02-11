static void F_1 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
const int V_5 = F_2 ( V_4 -> V_6 ) ;
int V_7 ;
V_7 = F_3 () ;
F_4 ( V_7 , & V_2 -> V_8 -> V_9 ) ;
F_5 ( V_7 , & V_2 -> V_8 -> V_9 , V_10 [ V_5 ] ) ;
F_6 ( V_7 , & V_2 -> V_8 -> V_9 , V_11 [ V_5 ] , V_4 -> V_12 . V_13 >> 9 ) ;
( void ) V_7 ;
F_7 ( & V_2 -> V_8 -> V_9 , V_5 ) ;
F_8 () ;
}
static void F_9 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
int V_5 = F_2 ( V_4 -> V_6 ) ;
unsigned long V_14 = V_15 - V_4 -> V_16 ;
int V_7 ;
V_7 = F_3 () ;
F_6 ( V_7 , & V_2 -> V_8 -> V_9 , V_17 [ V_5 ] , V_14 ) ;
F_4 ( V_7 , & V_2 -> V_8 -> V_9 ) ;
F_10 ( & V_2 -> V_8 -> V_9 , V_5 ) ;
F_8 () ;
}
static struct V_3 * F_11 ( struct V_1 * V_2 ,
struct V_18 * V_19 )
{
struct V_3 * V_4 ;
V_4 = F_12 ( V_20 , V_21 | V_22 ) ;
if ( ! V_4 )
return NULL ;
F_13 ( V_4 , V_19 ) ;
V_4 -> V_23 = F_2 ( V_19 ) == V_24 ? V_25 : 0 ;
V_4 -> V_2 = V_2 ;
V_4 -> V_6 = V_19 ;
V_4 -> V_26 = 0 ;
F_14 ( & V_4 -> V_12 ) ;
V_4 -> V_12 . V_27 = V_19 -> V_28 . V_29 ;
V_4 -> V_12 . V_13 = V_19 -> V_28 . V_30 ;
V_4 -> V_12 . V_31 = true ;
V_4 -> V_12 . V_32 = false ;
F_15 ( & V_4 -> V_33 ) ;
F_15 ( & V_4 -> V_34 . V_35 ) ;
F_15 ( & V_4 -> V_36 ) ;
F_15 ( & V_4 -> V_37 ) ;
F_16 ( & V_4 -> V_38 , 1 ) ;
F_17 ( & V_4 -> V_39 ) ;
return V_4 ;
}
static void F_18 ( struct V_40 * V_41 ,
struct V_3 * V_4 )
{
struct V_1 * V_2 = V_4 -> V_2 ;
struct V_42 * V_12 = & V_4 -> V_12 ;
F_19 ( V_41 , V_12 ) ;
if ( V_12 -> V_32 )
F_20 ( & V_2 -> V_43 ) ;
}
void F_21 ( struct V_39 * V_39 )
{
struct V_3 * V_4 = F_22 ( V_39 , struct V_3 , V_39 ) ;
struct V_1 * V_2 = V_4 -> V_2 ;
const unsigned V_44 = V_4 -> V_23 ;
if ( ( V_4 -> V_6 && ! ( V_44 & V_45 ) ) ||
F_23 ( & V_4 -> V_38 ) ||
( V_44 & V_46 ) ||
( ( V_44 & V_47 ) && ! ( V_44 & V_48 ) ) ) {
F_24 ( V_2 , L_1 ,
V_44 , F_23 ( & V_4 -> V_38 ) ) ;
return;
}
F_25 ( & V_4 -> V_33 ) ;
if ( ! F_26 ( & V_4 -> V_12 ) ) {
struct V_40 * V_41 ;
if ( V_44 & V_25 )
V_41 = & V_2 -> V_49 ;
else
V_41 = & V_2 -> V_50 ;
F_18 ( V_41 , V_4 ) ;
} else if ( V_44 & ( V_47 & ~ V_48 ) && V_4 -> V_12 . V_13 != 0 )
F_24 ( V_2 , L_2 ,
V_44 , ( unsigned long long ) V_4 -> V_12 . V_27 , V_4 -> V_12 . V_13 ) ;
if ( V_44 & V_25 ) {
if ( ( V_44 & ( V_45 | V_51 | V_47 ) ) != V_45 ) {
if ( ! ( V_44 & V_52 ) || ! ( V_44 & V_53 ) )
F_27 ( V_2 , V_4 -> V_12 . V_27 , V_4 -> V_12 . V_13 ) ;
if ( ( V_44 & V_52 ) && ( V_44 & V_53 ) && ( V_44 & V_54 ) )
F_28 ( V_2 , V_4 -> V_12 . V_27 , V_4 -> V_12 . V_13 ) ;
}
if ( V_44 & V_55 ) {
if ( F_29 ( V_2 , V_56 ) ) {
F_30 ( V_2 , & V_4 -> V_12 ) ;
F_31 ( V_2 ) ;
} else if ( F_32 ( & V_57 ) ) {
F_33 ( V_2 , L_3
L_4 ,
( unsigned long long ) V_4 -> V_12 . V_27 , V_4 -> V_12 . V_13 ) ;
}
}
}
F_34 ( V_4 , V_20 ) ;
}
static void F_35 ( struct V_58 * V_59 )
{
F_20 ( & V_59 -> V_60 . V_61 ) ;
}
void F_36 ( struct V_58 * V_59 )
{
if ( V_59 -> V_62 == 0 )
return;
V_59 -> V_62 = 0 ;
F_37 ( & V_59 -> V_63 ) ;
F_35 ( V_59 ) ;
}
void F_38 ( struct V_1 * V_2 ,
struct V_64 * V_65 )
{
F_39 ( V_65 -> V_18 , V_65 -> error ) ;
F_40 ( V_2 ) ;
}
static
void F_41 ( struct V_3 * V_4 , struct V_64 * V_65 )
{
const unsigned V_44 = V_4 -> V_23 ;
struct V_1 * V_2 = V_4 -> V_2 ;
int V_5 ;
int error , V_66 ;
if ( ( V_44 & V_46 && ! ( V_44 & V_67 ) ) ||
( V_44 & V_68 ) || ( V_44 & V_69 ) ||
( V_44 & V_70 ) ) {
F_24 ( V_2 , L_5 , V_44 ) ;
return;
}
if ( ! V_4 -> V_6 ) {
F_24 ( V_2 , L_6 ) ;
return;
}
V_5 = F_42 ( V_4 -> V_6 ) ;
V_66 = ( V_44 & V_53 ) || ( V_44 & V_52 ) ;
error = F_43 ( V_4 -> V_71 ) ;
if ( V_5 == V_24 &&
V_4 -> V_26 == F_23 ( & F_44 ( V_2 ) -> V_59 -> V_63 ) )
F_36 ( F_44 ( V_2 ) -> V_59 ) ;
F_9 ( V_2 , V_4 ) ;
if ( ! V_66 && V_5 == V_72 && ! F_45 ( & V_4 -> V_33 ) )
V_4 -> V_23 |= V_45 ;
if ( ! ( V_4 -> V_23 & V_45 ) ) {
V_65 -> error = V_66 ? 0 : ( error ? : - V_73 ) ;
V_65 -> V_18 = V_4 -> V_6 ;
V_4 -> V_6 = NULL ;
V_4 -> V_12 . V_74 = true ;
}
if ( V_4 -> V_12 . V_32 )
F_20 ( & V_2 -> V_43 ) ;
F_25 ( & V_4 -> V_36 ) ;
}
static int F_46 ( struct V_3 * V_4 , struct V_64 * V_65 , int V_75 )
{
struct V_1 * V_2 = V_4 -> V_2 ;
F_47 ( V_2 , V_65 || ( V_4 -> V_23 & V_45 ) ) ;
if ( ! F_48 ( V_75 , & V_4 -> V_38 ) )
return 0 ;
F_41 ( V_4 , V_65 ) ;
if ( V_4 -> V_23 & V_45 ) {
F_49 ( V_4 ) ;
return 0 ;
}
return 1 ;
}
static void F_50 ( struct V_76 * V_77 , struct V_3 * V_4 )
{
struct V_58 * V_59 = V_77 ? V_77 -> V_59 : NULL ;
if ( ! V_59 )
return;
if ( V_59 -> V_78 == NULL )
V_59 -> V_78 = V_4 ;
}
static void F_51 ( struct V_76 * V_77 , struct V_3 * V_4 )
{
struct V_58 * V_59 = V_77 ? V_77 -> V_59 : NULL ;
if ( ! V_59 )
return;
if ( V_59 -> V_78 != V_4 )
return;
F_52 (req, &connection->transfer_log, tl_requests) {
const unsigned V_44 = V_4 -> V_23 ;
if ( V_44 & V_68 )
break;
}
if ( & V_4 -> V_33 == & V_59 -> V_79 )
V_4 = NULL ;
V_59 -> V_78 = V_4 ;
}
static void F_53 ( struct V_76 * V_77 , struct V_3 * V_4 )
{
struct V_58 * V_59 = V_77 ? V_77 -> V_59 : NULL ;
if ( ! V_59 )
return;
if ( V_59 -> V_80 == NULL )
V_59 -> V_80 = V_4 ;
}
static void F_54 ( struct V_76 * V_77 , struct V_3 * V_4 )
{
struct V_58 * V_59 = V_77 ? V_77 -> V_59 : NULL ;
if ( ! V_59 )
return;
if ( V_59 -> V_80 != V_4 )
return;
F_52 (req, &connection->transfer_log, tl_requests) {
const unsigned V_44 = V_4 -> V_23 ;
if ( ( V_44 & V_81 ) && ( V_44 & V_69 ) )
break;
}
if ( & V_4 -> V_33 == & V_59 -> V_79 )
V_4 = NULL ;
V_59 -> V_80 = V_4 ;
}
static void F_55 ( struct V_76 * V_77 , struct V_3 * V_4 )
{
struct V_58 * V_59 = V_77 ? V_77 -> V_59 : NULL ;
if ( ! V_59 )
return;
if ( V_59 -> V_82 == NULL )
V_59 -> V_82 = V_4 ;
}
static void F_56 ( struct V_76 * V_77 , struct V_3 * V_4 )
{
struct V_58 * V_59 = V_77 ? V_77 -> V_59 : NULL ;
if ( ! V_59 )
return;
if ( V_59 -> V_82 != V_4 )
return;
F_52 (req, &connection->transfer_log, tl_requests) {
const unsigned V_44 = V_4 -> V_23 ;
if ( ( V_44 & V_81 ) && ! ( V_44 & V_48 ) )
break;
}
if ( & V_4 -> V_33 == & V_59 -> V_79 )
V_4 = NULL ;
V_59 -> V_82 = V_4 ;
}
static void F_57 ( struct V_3 * V_4 , struct V_64 * V_65 ,
int V_83 , int V_84 )
{
struct V_1 * V_2 = V_4 -> V_2 ;
struct V_76 * V_77 = F_44 ( V_2 ) ;
unsigned V_44 = V_4 -> V_23 ;
int V_85 = 0 ;
int V_86 = 0 ;
if ( F_58 ( V_2 ) && ! ( ( V_44 | V_83 ) & V_70 ) )
V_84 |= V_70 ;
V_4 -> V_23 &= ~ V_83 ;
V_4 -> V_23 |= V_84 ;
if ( V_4 -> V_23 == V_44 )
return;
if ( ! ( V_44 & V_46 ) && ( V_84 & V_46 ) )
F_37 ( & V_4 -> V_38 ) ;
if ( ! ( V_44 & V_69 ) && ( V_84 & V_69 ) ) {
F_59 ( V_2 ) ;
F_37 ( & V_4 -> V_38 ) ;
}
if ( ! ( V_44 & V_68 ) && ( V_84 & V_68 ) ) {
F_37 ( & V_4 -> V_38 ) ;
F_50 ( V_77 , V_4 ) ;
}
if ( ! ( V_44 & V_87 ) && ( V_84 & V_87 ) )
F_60 ( & V_4 -> V_39 ) ;
if ( ! ( V_44 & V_81 ) && ( V_84 & V_81 ) ) {
if ( ! ( V_44 & V_48 ) ) {
F_61 ( V_4 -> V_12 . V_13 >> 9 , & V_2 -> V_88 ) ;
F_55 ( V_77 , V_4 ) ;
}
if ( V_44 & V_69 )
F_53 ( V_77 , V_4 ) ;
}
if ( ! ( V_44 & V_70 ) && ( V_84 & V_70 ) )
F_37 ( & V_4 -> V_38 ) ;
if ( ( V_44 & V_70 ) && ( V_83 & V_70 ) )
++ V_85 ;
if ( ! ( V_44 & V_67 ) && ( V_84 & V_67 ) ) {
F_47 ( V_2 , V_4 -> V_23 & V_46 ) ;
F_60 ( & V_4 -> V_39 ) ;
++ V_85 ;
}
if ( ( V_44 & V_46 ) && ( V_83 & V_46 ) ) {
if ( V_4 -> V_23 & V_67 )
++ V_86 ;
else
++ V_85 ;
F_25 ( & V_4 -> V_37 ) ;
}
if ( ( V_44 & V_69 ) && ( V_83 & V_69 ) ) {
F_62 ( V_2 ) ;
++ V_85 ;
V_4 -> V_89 = V_15 ;
F_54 ( V_77 , V_4 ) ;
}
if ( ( V_44 & V_68 ) && ( V_83 & V_68 ) ) {
++ V_85 ;
F_51 ( V_77 , V_4 ) ;
}
if ( ! ( V_44 & V_48 ) && ( V_84 & V_48 ) ) {
if ( V_44 & V_81 )
F_63 ( V_4 -> V_12 . V_13 >> 9 , & V_2 -> V_88 ) ;
if ( V_44 & V_87 )
++ V_86 ;
V_4 -> V_90 = V_15 ;
F_51 ( V_77 , V_4 ) ;
F_54 ( V_77 , V_4 ) ;
F_56 ( V_77 , V_4 ) ;
}
if ( V_86 || V_85 ) {
int V_91 = V_86 + ! ! V_85 ;
int V_92 = F_23 ( & V_4 -> V_39 . V_92 ) ;
if ( V_92 < V_91 )
F_24 ( V_2 ,
L_7 ,
V_44 , V_4 -> V_23 , V_92 , V_91 ) ;
}
if ( V_4 -> V_12 . V_32 )
F_20 ( & V_2 -> V_43 ) ;
if ( V_85 )
V_86 += F_46 ( V_4 , V_65 , V_85 ) ;
if ( V_86 )
F_64 ( & V_4 -> V_39 , V_86 , F_21 ) ;
}
static void F_65 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
char V_93 [ V_94 ] ;
if ( ! F_32 ( & V_57 ) )
return;
F_33 ( V_2 , L_8 ,
( V_4 -> V_23 & V_25 ) ? L_9 : L_10 ,
( unsigned long long ) V_4 -> V_12 . V_27 ,
V_4 -> V_12 . V_13 >> 9 ,
F_66 ( V_2 -> V_95 -> V_96 , V_93 ) ) ;
}
static inline bool F_67 ( struct V_3 * V_4 )
{
return ( V_4 -> V_23 &
( V_25 | V_69 | V_97 | V_98 ) )
== ( V_25 | V_69 ) ;
}
int F_68 ( struct V_3 * V_4 , enum V_99 V_100 ,
struct V_64 * V_65 )
{
struct V_1 * const V_2 = V_4 -> V_2 ;
struct V_76 * const V_77 = F_44 ( V_2 ) ;
struct V_58 * const V_59 = V_77 ? V_77 -> V_59 : NULL ;
struct V_101 * V_102 ;
int V_103 , V_104 = 0 ;
if ( V_65 )
V_65 -> V_18 = NULL ;
switch ( V_100 ) {
default:
F_24 ( V_2 , L_11 , __FILE__ , __LINE__ ) ;
break;
case V_105 :
F_47 ( V_2 , ! ( V_4 -> V_23 & V_47 ) ) ;
F_69 () ;
V_102 = F_70 ( V_59 -> V_101 ) ;
V_103 = V_102 -> V_106 ;
F_71 () ;
V_4 -> V_23 |=
V_103 == V_107 ? V_97 :
V_103 == V_108 ? V_98 : 0 ;
F_57 ( V_4 , V_65 , 0 , V_69 ) ;
break;
case V_109 :
F_47 ( V_2 , ! ( V_4 -> V_23 & V_51 ) ) ;
F_57 ( V_4 , V_65 , 0 , V_46 ) ;
break;
case V_110 :
if ( V_4 -> V_23 & V_25 )
V_2 -> V_111 += V_4 -> V_12 . V_13 >> 9 ;
else
V_2 -> V_112 += V_4 -> V_12 . V_13 >> 9 ;
F_57 ( V_4 , V_65 , V_46 ,
V_113 | V_53 ) ;
break;
case V_114 :
F_57 ( V_4 , V_65 , 0 , V_67 ) ;
break;
case V_115 :
F_65 ( V_2 , V_4 ) ;
F_72 ( V_2 , V_116 ) ;
F_57 ( V_4 , V_65 , V_46 , V_113 ) ;
break;
case V_117 :
F_27 ( V_2 , V_4 -> V_12 . V_27 , V_4 -> V_12 . V_13 ) ;
F_65 ( V_2 , V_4 ) ;
F_72 ( V_2 , V_118 ) ;
case V_119 :
F_57 ( V_4 , V_65 , V_46 , V_113 ) ;
break;
case V_120 :
case V_121 :
F_57 ( V_4 , V_65 , V_46 , V_113 ) ;
break;
case V_122 :
F_47 ( V_2 , F_26 ( & V_4 -> V_12 ) ) ;
F_73 ( & V_2 -> V_50 , & V_4 -> V_12 ) ;
F_74 ( V_123 , & V_2 -> V_124 ) ;
F_47 ( V_2 , V_4 -> V_23 & V_69 ) ;
F_47 ( V_2 , ( V_4 -> V_23 & V_51 ) == 0 ) ;
F_57 ( V_4 , V_65 , 0 , V_68 ) ;
V_4 -> V_34 . V_125 = V_126 ;
F_75 ( & V_59 -> V_60 ,
& V_4 -> V_34 ) ;
break;
case V_127 :
F_47 ( V_2 , F_26 ( & V_4 -> V_12 ) ) ;
F_73 ( & V_2 -> V_49 , & V_4 -> V_12 ) ;
F_74 ( V_123 , & V_2 -> V_124 ) ;
F_47 ( V_2 , V_4 -> V_23 & V_69 ) ;
F_57 ( V_4 , V_65 , 0 , V_68 | V_87 ) ;
V_4 -> V_34 . V_125 = V_128 ;
F_75 ( & V_59 -> V_60 ,
& V_4 -> V_34 ) ;
F_69 () ;
V_102 = F_70 ( V_59 -> V_101 ) ;
V_103 = V_102 -> V_129 ;
F_71 () ;
if ( V_59 -> V_62 >= V_103 )
F_36 ( V_59 ) ;
break;
case V_130 :
F_57 ( V_4 , V_65 , 0 , V_68 ) ;
V_4 -> V_34 . V_125 = V_131 ;
F_75 ( & V_59 -> V_60 ,
& V_4 -> V_34 ) ;
break;
case V_132 :
case V_133 :
case V_134 :
F_57 ( V_4 , V_65 , V_68 , 0 ) ;
break;
case V_135 :
if ( F_67 ( V_4 ) )
F_57 ( V_4 , V_65 , V_68 | V_69 ,
V_81 | V_52 ) ;
else
F_57 ( V_4 , V_65 , V_68 , V_81 ) ;
break;
case V_136 :
F_57 ( V_4 , V_65 , V_68 , V_48 ) ;
break;
case V_137 :
F_57 ( V_4 , V_65 ,
V_52 | V_69 | V_70 ,
V_48 ) ;
break;
case V_138 :
F_47 ( V_2 , V_4 -> V_23 & V_69 ) ;
F_47 ( V_2 , V_4 -> V_23 & V_97 ) ;
F_57 ( V_4 , V_65 , V_69 , V_48 | V_52 ) ;
break;
case V_139 :
V_4 -> V_23 |= V_54 ;
case V_140 :
goto V_141;
case V_142 :
F_47 ( V_2 , V_4 -> V_23 & V_98 ) ;
V_141:
F_57 ( V_4 , V_65 , V_69 , V_52 ) ;
break;
case V_143 :
F_47 ( V_2 , V_4 -> V_23 & V_97 ) ;
F_47 ( V_2 , V_4 -> V_23 & V_69 ) ;
V_4 -> V_23 |= V_45 ;
if ( V_4 -> V_12 . V_32 )
F_20 ( & V_2 -> V_43 ) ;
break;
case V_144 :
F_57 ( V_4 , V_65 , V_52 | V_69 , 0 ) ;
break;
case V_145 :
if ( ! ( V_4 -> V_23 & V_113 ) )
break;
F_57 ( V_4 , V_65 , V_70 , 0 ) ;
break;
case V_146 :
if ( ! ( V_4 -> V_23 & V_113 ) )
break;
F_57 ( V_4 , V_65 ,
V_70 | V_113 ,
V_46 ) ;
V_104 = V_147 ;
if ( F_2 ( V_4 -> V_6 ) == V_24 )
V_104 = V_148 ;
F_76 ( V_2 ) ;
V_4 -> V_34 . V_125 = V_149 ;
F_75 ( & V_59 -> V_60 ,
& V_4 -> V_34 ) ;
break;
case V_150 :
if ( ! ( V_4 -> V_23 & V_25 ) && ! V_4 -> V_34 . V_125 ) {
F_57 ( V_4 , V_65 , V_70 , 0 ) ;
break;
}
if ( ! ( V_4 -> V_23 & V_52 ) ) {
F_57 ( V_4 , V_65 , V_70 , V_68 | V_69 ) ;
if ( V_4 -> V_34 . V_125 ) {
F_75 ( & V_59 -> V_60 ,
& V_4 -> V_34 ) ;
V_104 = V_4 -> V_23 & V_25 ? V_148 : V_147 ;
}
break;
}
case V_151 :
if ( ! ( V_4 -> V_23 & V_25 ) )
break;
if ( V_4 -> V_23 & V_69 ) {
F_24 ( V_2 , L_12 ) ;
}
F_57 ( V_4 , V_65 , V_70 ,
( V_4 -> V_23 & V_47 ) ? V_48 : 0 ) ;
break;
case V_152 :
F_47 ( V_2 , V_4 -> V_23 & V_69 ) ;
F_57 ( V_4 , V_65 , V_69 , V_52 | V_48 ) ;
break;
case V_153 :
F_36 ( V_59 ) ;
F_57 ( V_4 , V_65 , 0 , V_52 | V_48 ) ;
break;
} ;
return V_104 ;
}
static bool F_77 ( struct V_1 * V_2 , T_1 V_27 , int V_13 )
{
unsigned long V_154 , V_155 ;
T_1 V_156 , V_157 ;
if ( V_2 -> V_158 . V_159 == V_160 )
return true ;
if ( V_2 -> V_158 . V_159 != V_161 )
return false ;
V_156 = V_27 + ( V_13 >> 9 ) - 1 ;
V_157 = F_78 ( V_2 -> V_162 ) ;
F_47 ( V_2 , V_27 < V_157 ) ;
F_47 ( V_2 , V_156 < V_157 ) ;
V_154 = F_79 ( V_27 ) ;
V_155 = F_79 ( V_156 ) ;
return F_80 ( V_2 , V_154 , V_155 ) == 0 ;
}
static bool F_81 ( struct V_1 * V_2 , T_1 V_27 ,
enum V_163 V_164 )
{
struct V_165 * V_166 ;
int V_167 ;
switch ( V_164 ) {
case V_168 :
V_166 = & V_2 -> V_95 -> V_96 -> V_169 -> V_170 -> V_165 ;
return F_82 ( V_166 ) ;
case V_171 :
return F_23 ( & V_2 -> V_172 ) >
F_23 ( & V_2 -> V_173 ) + F_23 ( & V_2 -> V_174 ) ;
case V_175 :
case V_176 :
case V_177 :
case V_178 :
case V_179 :
case V_180 :
V_167 = ( V_164 - V_175 + 15 ) ;
return ( V_27 >> ( V_167 - 9 ) ) & 1 ;
case V_181 :
return F_83 ( V_182 , & V_2 -> V_124 ) ;
case V_183 :
return true ;
case V_184 :
default:
return false ;
}
}
static void F_84 ( struct V_3 * V_4 )
{
F_85 ( V_185 ) ;
struct V_1 * V_2 = V_4 -> V_2 ;
struct V_42 * V_12 ;
T_1 V_27 = V_4 -> V_12 . V_27 ;
int V_13 = V_4 -> V_12 . V_13 ;
V_12 = F_86 ( & V_2 -> V_49 , V_27 , V_13 ) ;
if ( ! V_12 )
return;
for (; ; ) {
F_87 ( & V_2 -> V_43 , & V_185 , V_186 ) ;
V_12 = F_86 ( & V_2 -> V_49 , V_27 , V_13 ) ;
if ( ! V_12 )
break;
V_12 -> V_32 = true ;
F_88 ( & V_2 -> V_187 -> V_188 ) ;
F_89 () ;
F_90 ( & V_2 -> V_187 -> V_188 ) ;
}
F_91 ( & V_2 -> V_43 , & V_185 ) ;
}
static void F_92 ( struct V_1 * V_2 )
{
struct V_58 * V_59 = F_44 ( V_2 ) -> V_59 ;
struct V_101 * V_102 ;
bool V_189 = false ;
enum V_190 V_191 ;
F_69 () ;
V_102 = F_70 ( V_59 -> V_101 ) ;
V_191 = V_102 ? V_102 -> V_191 : V_192 ;
F_71 () ;
if ( V_191 == V_192 ||
V_59 -> V_193 < 96 )
return;
if ( V_191 == V_194 && V_2 -> V_158 . V_195 == V_196 )
return;
if ( ! F_29 ( V_2 , V_160 ) )
return;
if ( V_102 -> V_197 &&
F_23 ( & V_2 -> V_88 ) >= V_102 -> V_197 ) {
F_93 ( V_2 , L_13 ) ;
V_189 = true ;
}
if ( V_2 -> V_198 -> V_199 >= V_102 -> V_200 ) {
F_93 ( V_2 , L_14 ) ;
V_189 = true ;
}
if ( V_189 ) {
F_36 ( F_44 ( V_2 ) -> V_59 ) ;
if ( V_191 == V_194 )
F_94 ( F_95 ( V_2 , V_195 , V_196 ) , 0 , NULL ) ;
else
F_94 ( F_95 ( V_2 , V_195 , V_201 ) , 0 , NULL ) ;
}
F_31 ( V_2 ) ;
}
static bool F_96 ( struct V_3 * V_4 )
{
struct V_1 * V_2 = V_4 -> V_2 ;
enum V_163 V_164 ;
if ( V_4 -> V_71 ) {
if ( ! F_77 ( V_2 ,
V_4 -> V_12 . V_27 , V_4 -> V_12 . V_13 ) ) {
F_97 ( V_4 -> V_71 ) ;
V_4 -> V_71 = NULL ;
F_31 ( V_2 ) ;
}
}
if ( V_2 -> V_158 . V_202 != V_160 )
return false ;
if ( V_4 -> V_71 == NULL )
return true ;
F_69 () ;
V_164 = F_70 ( V_2 -> V_95 -> V_203 ) -> V_204 ;
F_71 () ;
if ( V_164 == V_184 && V_4 -> V_71 )
return false ;
if ( F_81 ( V_2 , V_4 -> V_12 . V_27 , V_164 ) ) {
if ( V_4 -> V_71 ) {
F_97 ( V_4 -> V_71 ) ;
V_4 -> V_71 = NULL ;
F_31 ( V_2 ) ;
}
return true ;
}
return false ;
}
static int F_98 ( struct V_3 * V_4 )
{
struct V_1 * V_2 = V_4 -> V_2 ;
int V_205 , V_206 ;
V_205 = F_99 ( V_2 -> V_158 ) ;
V_206 = F_100 ( V_2 -> V_158 ) ;
if ( F_101 ( V_4 -> V_12 . V_13 == 0 ) ) {
F_47 ( V_2 , V_4 -> V_6 -> V_207 & V_208 ) ;
if ( V_205 )
F_102 ( V_4 , V_153 ) ;
return V_205 ;
}
if ( ! V_205 && ! V_206 )
return 0 ;
F_47 ( V_2 , ! ( V_205 && V_206 ) ) ;
if ( V_205 ) {
F_102 ( V_4 , V_105 ) ;
F_102 ( V_4 , V_127 ) ;
} else if ( F_27 ( V_2 , V_4 -> V_12 . V_27 , V_4 -> V_12 . V_13 ) )
F_102 ( V_4 , V_130 ) ;
return V_205 ;
}
static void
F_103 ( struct V_3 * V_4 )
{
struct V_1 * V_2 = V_4 -> V_2 ;
struct V_18 * V_18 = V_4 -> V_71 ;
const int V_5 = F_42 ( V_18 ) ;
V_18 -> V_209 = V_2 -> V_95 -> V_96 ;
if ( F_76 ( V_2 ) ) {
V_4 -> V_210 = V_15 ;
if ( F_104 ( V_2 ,
V_5 == V_24 ? V_211
: V_5 == V_72 ? V_212
: V_213 ) )
F_39 ( V_18 , - V_73 ) ;
else
F_105 ( V_18 ) ;
F_31 ( V_2 ) ;
} else
F_39 ( V_18 , - V_73 ) ;
}
static void F_106 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
F_90 ( & V_2 -> V_187 -> V_188 ) ;
F_107 ( & V_4 -> V_33 , & V_2 -> V_214 . V_215 ) ;
F_107 ( & V_4 -> V_36 ,
& V_2 -> V_216 [ 1 ] ) ;
F_88 ( & V_2 -> V_187 -> V_188 ) ;
F_108 ( V_2 -> V_214 . V_217 , & V_2 -> V_214 . V_218 ) ;
F_20 ( & V_2 -> V_219 ) ;
}
static struct V_3 *
F_109 ( struct V_1 * V_2 , struct V_18 * V_18 , unsigned long V_16 )
{
const int V_5 = F_2 ( V_18 ) ;
struct V_3 * V_4 ;
V_4 = F_11 ( V_2 , V_18 ) ;
if ( ! V_4 ) {
F_40 ( V_2 ) ;
F_24 ( V_2 , L_15 ) ;
F_39 ( V_18 , - V_220 ) ;
return F_110 ( - V_220 ) ;
}
V_4 -> V_16 = V_16 ;
if ( ! F_76 ( V_2 ) ) {
F_97 ( V_4 -> V_71 ) ;
V_4 -> V_71 = NULL ;
}
F_1 ( V_2 , V_4 ) ;
if ( V_5 == V_24 && V_4 -> V_71 && V_4 -> V_12 . V_13
&& ! F_111 ( V_221 , & V_2 -> V_124 ) ) {
if ( ! F_112 ( V_2 , & V_4 -> V_12 ) ) {
F_37 ( & V_2 -> V_222 ) ;
F_106 ( V_2 , V_4 ) ;
return NULL ;
}
V_4 -> V_23 |= V_55 ;
V_4 -> V_223 = V_15 ;
}
return V_4 ;
}
static void F_113 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_224 * V_187 = V_2 -> V_187 ;
const int V_5 = F_42 ( V_4 -> V_6 ) ;
struct V_64 V_65 = { NULL , } ;
bool V_225 = false ;
bool V_226 = false ;
F_90 ( & V_187 -> V_188 ) ;
if ( V_5 == V_24 ) {
F_84 ( V_4 ) ;
F_92 ( V_2 ) ;
}
if ( F_58 ( V_2 ) ) {
V_4 -> V_23 |= V_45 ;
if ( V_4 -> V_71 ) {
F_97 ( V_4 -> V_71 ) ;
V_4 -> V_71 = NULL ;
F_31 ( V_2 ) ;
}
goto V_227;
}
if ( V_5 != V_24 ) {
if ( ! F_96 ( V_4 ) && ! V_4 -> V_71 )
goto V_228;
}
V_4 -> V_26 = F_23 ( & F_44 ( V_2 ) -> V_59 -> V_63 ) ;
if ( F_114 ( V_4 -> V_12 . V_13 != 0 ) ) {
if ( V_5 == V_24 )
F_44 ( V_2 ) -> V_59 -> V_62 ++ ;
F_107 ( & V_4 -> V_33 , & F_44 ( V_2 ) -> V_59 -> V_79 ) ;
}
if ( V_5 == V_24 ) {
if ( ! F_98 ( V_4 ) )
V_225 = true ;
} else {
if ( V_4 -> V_71 == NULL ) {
F_102 ( V_4 , V_105 ) ;
F_102 ( V_4 , V_122 ) ;
} else
V_225 = true ;
}
if ( F_45 ( & V_4 -> V_36 ) )
F_107 ( & V_4 -> V_36 ,
& V_2 -> V_216 [ V_5 == V_24 ] ) ;
if ( V_4 -> V_71 ) {
F_107 ( & V_4 -> V_37 ,
& V_2 -> V_229 [ V_5 == V_24 ] ) ;
F_102 ( V_4 , V_109 ) ;
V_226 = true ;
} else if ( V_225 ) {
V_228:
if ( F_32 ( & V_57 ) )
F_24 ( V_2 , L_16 ,
( unsigned long long ) V_4 -> V_12 . V_27 , V_4 -> V_12 . V_13 >> 9 ) ;
}
V_227:
if ( F_46 ( V_4 , & V_65 , 1 ) )
F_115 ( & V_4 -> V_39 , F_21 ) ;
F_88 ( & V_187 -> V_188 ) ;
if ( V_226 )
F_103 ( V_4 ) ;
if ( V_65 . V_18 )
F_38 ( V_2 , & V_65 ) ;
}
void F_116 ( struct V_1 * V_2 , struct V_18 * V_18 , unsigned long V_16 )
{
struct V_3 * V_4 = F_109 ( V_2 , V_18 , V_16 ) ;
if ( F_117 ( V_4 ) )
return;
F_113 ( V_2 , V_4 ) ;
}
static void F_118 ( struct V_1 * V_2 , struct V_230 * V_231 )
{
struct V_3 * V_4 , * V_232 ;
F_119 (req, tmp, incoming, tl_requests) {
const int V_5 = F_2 ( V_4 -> V_6 ) ;
if ( V_5 == V_24
&& V_4 -> V_71 && V_4 -> V_12 . V_13
&& ! F_111 ( V_221 , & V_2 -> V_124 ) ) {
if ( ! F_112 ( V_2 , & V_4 -> V_12 ) )
continue;
V_4 -> V_23 |= V_55 ;
V_4 -> V_223 = V_15 ;
F_120 ( & V_2 -> V_222 ) ;
}
F_25 ( & V_4 -> V_33 ) ;
F_113 ( V_2 , V_4 ) ;
}
}
static bool F_121 ( struct V_1 * V_2 ,
struct V_230 * V_231 ,
struct V_230 * V_233 ,
struct V_230 * V_234 )
{
struct V_3 * V_4 , * V_232 ;
int V_235 = 0 ;
int V_236 ;
F_90 ( & V_2 -> V_237 ) ;
F_119 (req, tmp, incoming, tl_requests) {
V_236 = F_122 ( V_2 , & V_4 -> V_12 ) ;
if ( V_236 == - V_238 )
break;
if ( V_236 == - V_239 )
V_235 = 1 ;
if ( V_236 )
F_123 ( & V_4 -> V_33 , V_234 ) ;
else
F_123 ( & V_4 -> V_33 , V_233 ) ;
}
F_88 ( & V_2 -> V_237 ) ;
if ( V_235 )
F_20 ( & V_2 -> V_219 ) ;
return ! F_45 ( V_233 ) ;
}
void F_124 ( struct V_1 * V_2 , struct V_230 * V_233 )
{
struct V_3 * V_4 , * V_232 ;
F_119 (req, tmp, pending, tl_requests) {
V_4 -> V_23 |= V_55 ;
V_4 -> V_223 = V_15 ;
F_120 ( & V_2 -> V_222 ) ;
F_25 ( & V_4 -> V_33 ) ;
F_113 ( V_2 , V_4 ) ;
}
}
void F_125 ( struct V_240 * V_241 )
{
struct V_1 * V_2 = F_22 ( V_241 , struct V_1 , V_214 . V_218 ) ;
F_126 ( V_231 ) ;
F_126 ( V_233 ) ;
F_126 ( V_242 ) ;
F_90 ( & V_2 -> V_187 -> V_188 ) ;
F_127 ( & V_2 -> V_214 . V_215 , & V_231 ) ;
F_88 ( & V_2 -> V_187 -> V_188 ) ;
for (; ; ) {
F_85 ( V_185 ) ;
F_128 ( & V_242 , & V_231 ) ;
F_118 ( V_2 , & V_231 ) ;
if ( F_45 ( & V_231 ) )
break;
for (; ; ) {
F_87 ( & V_2 -> V_219 , & V_185 , V_186 ) ;
F_128 ( & V_242 , & V_231 ) ;
F_121 ( V_2 , & V_231 , & V_233 , & V_242 ) ;
if ( ! F_45 ( & V_233 ) )
break;
F_89 () ;
if ( ! F_45 ( & V_231 ) )
continue;
F_90 ( & V_2 -> V_187 -> V_188 ) ;
F_127 ( & V_2 -> V_214 . V_215 , & V_231 ) ;
F_88 ( & V_2 -> V_187 -> V_188 ) ;
}
F_91 ( & V_2 -> V_219 , & V_185 ) ;
while ( F_45 ( & V_231 ) ) {
F_126 ( V_243 ) ;
F_126 ( V_244 ) ;
bool V_245 ;
if ( F_45 ( & V_2 -> V_214 . V_215 ) )
break;
F_90 ( & V_2 -> V_187 -> V_188 ) ;
F_127 ( & V_2 -> V_214 . V_215 , & V_244 ) ;
F_88 ( & V_2 -> V_187 -> V_188 ) ;
if ( F_45 ( & V_244 ) )
break;
V_245 = F_121 ( V_2 , & V_244 , & V_243 , & V_242 ) ;
F_127 ( & V_243 , & V_233 ) ;
F_127 ( & V_244 , & V_231 ) ;
if ( ! V_245 )
break;
}
F_129 ( V_2 ) ;
F_124 ( V_2 , & V_233 ) ;
}
}
void F_130 ( struct V_246 * V_247 , struct V_18 * V_18 )
{
struct V_1 * V_2 = (struct V_1 * ) V_247 -> V_248 ;
unsigned long V_16 ;
V_16 = V_15 ;
F_47 ( V_2 , F_131 ( V_18 -> V_28 . V_30 , 512 ) ) ;
F_132 ( V_2 ) ;
F_116 ( V_2 , V_18 , V_16 ) ;
}
int F_133 ( struct V_246 * V_247 , struct V_249 * V_250 , struct V_251 * V_252 )
{
struct V_1 * V_2 = (struct V_1 * ) V_247 -> V_248 ;
unsigned int V_253 = V_250 -> V_30 ;
int V_254 = V_255 ;
int V_256 ;
if ( V_253 && F_76 ( V_2 ) ) {
unsigned int V_257 = F_134 ( V_247 ) ;
struct V_246 * const V_93 =
V_2 -> V_95 -> V_96 -> V_169 -> V_170 ;
if ( V_93 -> V_258 ) {
V_256 = V_93 -> V_258 ( V_93 , V_250 , V_252 ) ;
V_254 = F_135 ( V_254 , V_256 ) ;
}
F_31 ( V_2 ) ;
if ( ( V_254 >> 9 ) > V_257 )
V_254 = V_257 << 9 ;
}
return V_254 ;
}
void F_136 ( unsigned long V_259 )
{
struct V_1 * V_2 = (struct V_1 * ) V_259 ;
struct V_58 * V_59 = F_44 ( V_2 ) -> V_59 ;
struct V_3 * V_260 , * V_261 , * V_262 ;
struct V_101 * V_102 ;
unsigned long V_263 ;
unsigned long V_264 = 0 , V_265 = 0 , V_266 , V_267 ;
unsigned long V_268 ;
F_69 () ;
V_102 = F_70 ( V_59 -> V_101 ) ;
if ( V_102 && V_2 -> V_158 . V_195 >= V_269 )
V_264 = V_102 -> V_270 * V_271 / 10 * V_102 -> V_272 ;
if ( F_76 ( V_2 ) ) {
V_265 = F_70 ( V_2 -> V_95 -> V_203 ) -> V_273 * V_271 / 10 ;
F_31 ( V_2 ) ;
}
F_71 () ;
V_266 = F_137 ( V_265 , V_264 ) ;
if ( ! V_266 )
return;
V_268 = V_15 ;
V_267 = V_268 + V_266 ;
F_90 ( & V_2 -> V_187 -> V_188 ) ;
V_260 = F_138 ( & V_2 -> V_229 [ 0 ] , struct V_3 , V_37 ) ;
V_261 = F_138 ( & V_2 -> V_229 [ 1 ] , struct V_3 , V_37 ) ;
V_262 = V_59 -> V_82 ;
if ( ! V_262 && V_59 -> V_78 && V_59 -> V_78 -> V_274 )
V_262 = V_59 -> V_78 ;
if ( V_262 && V_262 -> V_2 != V_2 )
V_262 = NULL ;
if ( V_262 == NULL && V_261 == NULL && V_260 == NULL )
goto V_227;
V_263 =
( V_261 && V_260 )
? ( F_139 ( V_261 -> V_210 , V_260 -> V_210 )
? V_261 -> V_210 : V_260 -> V_210 )
: V_261 ? V_261 -> V_210
: V_260 ? V_260 -> V_210 : V_268 ;
if ( V_264 && V_262 &&
F_140 ( V_268 , V_262 -> V_274 + V_264 ) &&
! F_141 ( V_268 , V_59 -> V_275 , V_59 -> V_275 + V_264 ) ) {
F_33 ( V_2 , L_17 ) ;
F_94 ( F_95 ( V_2 , V_195 , V_276 ) , V_277 | V_278 , NULL ) ;
}
if ( V_265 && V_263 != V_268 &&
F_140 ( V_268 , V_263 + V_265 ) &&
! F_141 ( V_268 , V_2 -> V_279 , V_2 -> V_279 + V_265 ) ) {
F_33 ( V_2 , L_18 ) ;
F_72 ( V_2 , V_280 ) ;
}
V_264 = ( V_264 && V_262 && F_139 ( V_268 , V_262 -> V_274 + V_264 ) )
? V_262 -> V_274 + V_264 : V_268 + V_266 ;
V_265 = ( V_265 && V_263 != V_268 && F_139 ( V_268 , V_263 + V_265 ) )
? V_263 + V_265 : V_268 + V_266 ;
V_267 = F_139 ( V_264 , V_265 ) ? V_264 : V_265 ;
V_227:
F_88 ( & V_2 -> V_187 -> V_188 ) ;
F_142 ( & V_2 -> V_281 , V_267 ) ;
}
