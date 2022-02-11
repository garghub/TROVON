static void F_1 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
F_2 ( V_6 , F_3 ( V_4 -> V_8 ) ,
V_4 -> V_9 . V_10 >> 9 , & V_2 -> V_11 -> V_12 ) ;
}
static void F_4 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
F_5 ( V_6 , F_3 ( V_4 -> V_8 ) ,
& V_2 -> V_11 -> V_12 , V_4 -> V_13 ) ;
}
static struct V_3 * F_6 ( struct V_1 * V_2 , struct V_14 * V_15 )
{
struct V_3 * V_4 ;
V_4 = F_7 ( V_16 , V_17 ) ;
if ( ! V_4 )
return NULL ;
memset ( V_4 , 0 , sizeof( * V_4 ) ) ;
F_8 ( V_4 , V_15 ) ;
V_4 -> V_18 = ( F_3 ( V_15 ) == V_19 ? V_20 : 0 )
| ( F_9 ( V_15 ) == V_21 ? V_22 : 0 )
| ( F_9 ( V_15 ) == V_23 ? V_24 : 0 )
| ( F_9 ( V_15 ) == V_25 ? V_24 : 0 ) ;
V_4 -> V_2 = V_2 ;
V_4 -> V_8 = V_15 ;
V_4 -> V_26 = 0 ;
F_10 ( & V_4 -> V_9 ) ;
V_4 -> V_9 . V_27 = V_15 -> V_28 . V_29 ;
V_4 -> V_9 . V_10 = V_15 -> V_28 . V_30 ;
V_4 -> V_9 . V_31 = true ;
V_4 -> V_9 . V_32 = false ;
F_11 ( & V_4 -> V_33 ) ;
F_11 ( & V_4 -> V_34 . V_35 ) ;
F_11 ( & V_4 -> V_36 ) ;
F_11 ( & V_4 -> V_37 ) ;
F_12 ( & V_4 -> V_38 , 1 ) ;
F_13 ( & V_4 -> V_39 ) ;
return V_4 ;
}
static void F_14 ( struct V_40 * V_41 ,
struct V_3 * V_4 )
{
struct V_1 * V_2 = V_4 -> V_2 ;
struct V_42 * V_9 = & V_4 -> V_9 ;
F_15 ( V_41 , V_9 ) ;
if ( V_9 -> V_32 )
F_16 ( & V_2 -> V_43 ) ;
}
void F_17 ( struct V_39 * V_39 )
{
struct V_3 * V_4 = F_18 ( V_39 , struct V_3 , V_39 ) ;
struct V_1 * V_2 = V_4 -> V_2 ;
const unsigned V_44 = V_4 -> V_18 ;
if ( ( V_4 -> V_8 && ! ( V_44 & V_45 ) ) ||
F_19 ( & V_4 -> V_38 ) ||
( V_44 & V_46 ) ||
( ( V_44 & V_47 ) && ! ( V_44 & V_48 ) ) ) {
F_20 ( V_2 , L_1 ,
V_44 , F_19 ( & V_4 -> V_38 ) ) ;
return;
}
F_21 ( & V_4 -> V_33 ) ;
if ( ! F_22 ( & V_4 -> V_9 ) ) {
struct V_40 * V_41 ;
if ( V_44 & V_20 )
V_41 = & V_2 -> V_49 ;
else
V_41 = & V_2 -> V_50 ;
F_14 ( V_41 , V_4 ) ;
} else if ( V_44 & ( V_47 & ~ V_48 ) && V_4 -> V_9 . V_10 != 0 )
F_20 ( V_2 , L_2 ,
V_44 , ( unsigned long long ) V_4 -> V_9 . V_27 , V_4 -> V_9 . V_10 ) ;
if ( V_44 & V_20 ) {
if ( ( V_44 & ( V_45 | V_51 | V_47 ) ) != V_45 ) {
if ( ! ( V_44 & V_52 ) || ! ( V_44 & V_53 ) )
F_23 ( V_2 , V_4 -> V_9 . V_27 , V_4 -> V_9 . V_10 ) ;
if ( ( V_44 & V_52 ) && ( V_44 & V_53 ) && ( V_44 & V_54 ) )
F_24 ( V_2 , V_4 -> V_9 . V_27 , V_4 -> V_9 . V_10 ) ;
}
if ( V_44 & V_55 ) {
if ( F_25 ( V_2 , V_56 ) ) {
F_26 ( V_2 , & V_4 -> V_9 ) ;
F_27 ( V_2 ) ;
} else if ( F_28 ( & V_57 ) ) {
F_29 ( V_2 , L_3
L_4 ,
( unsigned long long ) V_4 -> V_9 . V_27 , V_4 -> V_9 . V_10 ) ;
}
}
}
F_30 ( V_4 , V_16 ) ;
}
static void F_31 ( struct V_58 * V_59 )
{
F_16 ( & V_59 -> V_60 . V_61 ) ;
}
void F_32 ( struct V_58 * V_59 )
{
if ( V_59 -> V_62 == 0 )
return;
V_59 -> V_62 = 0 ;
F_33 ( & V_59 -> V_63 ) ;
F_31 ( V_59 ) ;
}
void F_34 ( struct V_1 * V_2 ,
struct V_64 * V_65 )
{
V_65 -> V_14 -> V_66 = F_35 ( V_65 -> error ) ;
F_36 ( V_65 -> V_14 ) ;
F_37 ( V_2 ) ;
}
static
void F_38 ( struct V_3 * V_4 , struct V_64 * V_65 )
{
const unsigned V_44 = V_4 -> V_18 ;
struct V_1 * V_2 = V_4 -> V_2 ;
int error , V_67 ;
if ( ( V_44 & V_46 && ! ( V_44 & V_68 ) ) ||
( V_44 & V_69 ) || ( V_44 & V_70 ) ||
( V_44 & V_71 ) ) {
F_20 ( V_2 , L_5 , V_44 ) ;
return;
}
if ( ! V_4 -> V_8 ) {
F_20 ( V_2 , L_6 ) ;
return;
}
V_67 = ( V_44 & V_53 ) || ( V_44 & V_52 ) ;
error = F_39 ( V_4 -> V_72 ) ;
if ( F_40 ( F_9 ( V_4 -> V_8 ) ) &&
V_4 -> V_26 == F_19 ( & F_41 ( V_2 ) -> V_59 -> V_63 ) )
F_32 ( F_41 ( V_2 ) -> V_59 ) ;
F_4 ( V_2 , V_4 ) ;
if ( ! V_67 &&
F_9 ( V_4 -> V_8 ) == V_73 &&
! ( V_4 -> V_8 -> V_74 & V_75 ) &&
! F_42 ( & V_4 -> V_33 ) )
V_4 -> V_18 |= V_45 ;
if ( ! ( V_4 -> V_18 & V_45 ) ) {
V_65 -> error = V_67 ? 0 : ( error ? : - V_76 ) ;
V_65 -> V_14 = V_4 -> V_8 ;
V_4 -> V_8 = NULL ;
V_4 -> V_9 . V_77 = true ;
}
if ( V_4 -> V_9 . V_32 )
F_16 ( & V_2 -> V_43 ) ;
F_21 ( & V_4 -> V_36 ) ;
}
static void F_43 ( struct V_3 * V_4 , struct V_64 * V_65 , int V_78 )
{
struct V_1 * V_2 = V_4 -> V_2 ;
F_44 ( V_2 , V_65 || ( V_4 -> V_18 & V_45 ) ) ;
if ( ! V_78 )
return;
if ( ! F_45 ( V_78 , & V_4 -> V_38 ) )
return;
F_38 ( V_4 , V_65 ) ;
if ( V_4 -> V_18 & V_68 )
return;
if ( V_4 -> V_18 & V_45 ) {
F_46 ( V_4 ) ;
return;
}
F_47 ( & V_4 -> V_39 , F_17 ) ;
}
static void F_48 ( struct V_79 * V_80 , struct V_3 * V_4 )
{
struct V_58 * V_59 = V_80 ? V_80 -> V_59 : NULL ;
if ( ! V_59 )
return;
if ( V_59 -> V_81 == NULL )
V_59 -> V_81 = V_4 ;
}
static void F_49 ( struct V_79 * V_80 , struct V_3 * V_4 )
{
struct V_58 * V_59 = V_80 ? V_80 -> V_59 : NULL ;
if ( ! V_59 )
return;
if ( V_59 -> V_81 != V_4 )
return;
F_50 (req, &connection->transfer_log, tl_requests) {
const unsigned V_44 = V_4 -> V_18 ;
if ( V_44 & V_69 )
break;
}
if ( & V_4 -> V_33 == & V_59 -> V_82 )
V_4 = NULL ;
V_59 -> V_81 = V_4 ;
}
static void F_51 ( struct V_79 * V_80 , struct V_3 * V_4 )
{
struct V_58 * V_59 = V_80 ? V_80 -> V_59 : NULL ;
if ( ! V_59 )
return;
if ( V_59 -> V_83 == NULL )
V_59 -> V_83 = V_4 ;
}
static void F_52 ( struct V_79 * V_80 , struct V_3 * V_4 )
{
struct V_58 * V_59 = V_80 ? V_80 -> V_59 : NULL ;
if ( ! V_59 )
return;
if ( V_59 -> V_83 != V_4 )
return;
F_50 (req, &connection->transfer_log, tl_requests) {
const unsigned V_44 = V_4 -> V_18 ;
if ( ( V_44 & V_84 ) && ( V_44 & V_70 ) )
break;
}
if ( & V_4 -> V_33 == & V_59 -> V_82 )
V_4 = NULL ;
V_59 -> V_83 = V_4 ;
}
static void F_53 ( struct V_79 * V_80 , struct V_3 * V_4 )
{
struct V_58 * V_59 = V_80 ? V_80 -> V_59 : NULL ;
if ( ! V_59 )
return;
if ( V_59 -> V_85 == NULL )
V_59 -> V_85 = V_4 ;
}
static void F_54 ( struct V_79 * V_80 , struct V_3 * V_4 )
{
struct V_58 * V_59 = V_80 ? V_80 -> V_59 : NULL ;
if ( ! V_59 )
return;
if ( V_59 -> V_85 != V_4 )
return;
F_50 (req, &connection->transfer_log, tl_requests) {
const unsigned V_44 = V_4 -> V_18 ;
if ( ( V_44 & V_84 ) && ! ( V_44 & V_48 ) )
break;
}
if ( & V_4 -> V_33 == & V_59 -> V_82 )
V_4 = NULL ;
V_59 -> V_85 = V_4 ;
}
static void F_55 ( struct V_3 * V_4 , struct V_64 * V_65 ,
int V_86 , int V_87 )
{
struct V_1 * V_2 = V_4 -> V_2 ;
struct V_79 * V_80 = F_41 ( V_2 ) ;
unsigned V_44 = V_4 -> V_18 ;
int V_88 = 0 ;
if ( F_56 ( V_2 ) && ! ( ( V_44 | V_86 ) & V_71 ) )
V_87 |= V_71 ;
V_4 -> V_18 &= ~ V_86 ;
V_4 -> V_18 |= V_87 ;
if ( V_4 -> V_18 == V_44 )
return;
F_57 ( & V_4 -> V_39 ) ;
if ( ! ( V_44 & V_46 ) && ( V_87 & V_46 ) )
F_33 ( & V_4 -> V_38 ) ;
if ( ! ( V_44 & V_70 ) && ( V_87 & V_70 ) ) {
F_58 ( V_2 ) ;
F_33 ( & V_4 -> V_38 ) ;
}
if ( ! ( V_44 & V_69 ) && ( V_87 & V_69 ) ) {
F_33 ( & V_4 -> V_38 ) ;
F_48 ( V_80 , V_4 ) ;
}
if ( ! ( V_44 & V_89 ) && ( V_87 & V_89 ) )
F_57 ( & V_4 -> V_39 ) ;
if ( ! ( V_44 & V_84 ) && ( V_87 & V_84 ) ) {
if ( ! ( V_44 & V_48 ) ) {
F_59 ( V_4 -> V_9 . V_10 >> 9 , & V_2 -> V_90 ) ;
F_53 ( V_80 , V_4 ) ;
}
if ( V_4 -> V_18 & V_70 )
F_51 ( V_80 , V_4 ) ;
}
if ( ! ( V_44 & V_71 ) && ( V_87 & V_71 ) )
F_33 ( & V_4 -> V_38 ) ;
if ( ( V_44 & V_71 ) && ( V_86 & V_71 ) )
++ V_88 ;
if ( ! ( V_44 & V_68 ) && ( V_87 & V_68 ) ) {
F_44 ( V_2 , V_4 -> V_18 & V_46 ) ;
++ V_88 ;
}
if ( ( V_44 & V_46 ) && ( V_86 & V_46 ) ) {
if ( V_4 -> V_18 & V_68 )
F_47 ( & V_4 -> V_39 , F_17 ) ;
else
++ V_88 ;
F_21 ( & V_4 -> V_37 ) ;
}
if ( ( V_44 & V_70 ) && ( V_86 & V_70 ) ) {
F_60 ( V_2 ) ;
++ V_88 ;
V_4 -> V_91 = V_92 ;
F_52 ( V_80 , V_4 ) ;
}
if ( ( V_44 & V_69 ) && ( V_86 & V_69 ) ) {
++ V_88 ;
F_49 ( V_80 , V_4 ) ;
}
if ( ! ( V_44 & V_48 ) && ( V_87 & V_48 ) ) {
if ( V_44 & V_84 )
F_61 ( V_4 -> V_9 . V_10 >> 9 , & V_2 -> V_90 ) ;
if ( V_44 & V_89 )
F_47 ( & V_4 -> V_39 , F_17 ) ;
V_4 -> V_93 = V_92 ;
F_49 ( V_80 , V_4 ) ;
F_52 ( V_80 , V_4 ) ;
F_54 ( V_80 , V_4 ) ;
}
if ( V_4 -> V_9 . V_32 )
F_16 ( & V_2 -> V_43 ) ;
F_43 ( V_4 , V_65 , V_88 ) ;
F_47 ( & V_4 -> V_39 , F_17 ) ;
}
static void F_62 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
char V_94 [ V_95 ] ;
if ( ! F_28 ( & V_57 ) )
return;
F_29 ( V_2 , L_7 ,
( V_4 -> V_18 & V_20 ) ? L_8 : L_9 ,
( unsigned long long ) V_4 -> V_9 . V_27 ,
V_4 -> V_9 . V_10 >> 9 ,
F_63 ( V_2 -> V_96 -> V_97 , V_94 ) ) ;
}
static inline bool F_64 ( struct V_3 * V_4 )
{
return ( V_4 -> V_18 &
( V_20 | V_70 | V_98 | V_99 ) )
== ( V_20 | V_70 ) ;
}
int F_65 ( struct V_3 * V_4 , enum V_100 V_101 ,
struct V_64 * V_65 )
{
struct V_1 * const V_2 = V_4 -> V_2 ;
struct V_79 * const V_80 = F_41 ( V_2 ) ;
struct V_58 * const V_59 = V_80 ? V_80 -> V_59 : NULL ;
struct V_102 * V_103 ;
int V_104 , V_105 = 0 ;
if ( V_65 )
V_65 -> V_14 = NULL ;
switch ( V_101 ) {
default:
F_20 ( V_2 , L_10 , __FILE__ , __LINE__ ) ;
break;
case V_106 :
F_44 ( V_2 , ! ( V_4 -> V_18 & V_47 ) ) ;
F_66 () ;
V_103 = F_67 ( V_59 -> V_102 ) ;
V_104 = V_103 -> V_107 ;
F_68 () ;
V_4 -> V_18 |=
V_104 == V_108 ? V_98 :
V_104 == V_109 ? V_99 : 0 ;
F_55 ( V_4 , V_65 , 0 , V_70 ) ;
break;
case V_110 :
F_44 ( V_2 , ! ( V_4 -> V_18 & V_51 ) ) ;
F_55 ( V_4 , V_65 , 0 , V_46 ) ;
break;
case V_111 :
if ( V_4 -> V_18 & V_20 )
V_2 -> V_112 += V_4 -> V_9 . V_10 >> 9 ;
else
V_2 -> V_113 += V_4 -> V_9 . V_10 >> 9 ;
F_55 ( V_4 , V_65 , V_46 ,
V_114 | V_53 ) ;
break;
case V_115 :
F_55 ( V_4 , V_65 , 0 , V_68 ) ;
break;
case V_116 :
F_62 ( V_2 , V_4 ) ;
F_69 ( V_2 , V_117 ) ;
F_55 ( V_4 , V_65 , V_46 , V_114 ) ;
break;
case V_118 :
F_23 ( V_2 , V_4 -> V_9 . V_27 , V_4 -> V_9 . V_10 ) ;
F_62 ( V_2 , V_4 ) ;
F_69 ( V_2 , V_119 ) ;
case V_120 :
F_55 ( V_4 , V_65 , V_46 , V_114 ) ;
break;
case V_121 :
case V_122 :
F_55 ( V_4 , V_65 , V_46 , V_114 ) ;
break;
case V_123 :
F_44 ( V_2 , F_22 ( & V_4 -> V_9 ) ) ;
F_70 ( & V_2 -> V_50 , & V_4 -> V_9 ) ;
F_71 ( V_124 , & V_2 -> V_125 ) ;
F_44 ( V_2 , V_4 -> V_18 & V_70 ) ;
F_44 ( V_2 , ( V_4 -> V_18 & V_51 ) == 0 ) ;
F_55 ( V_4 , V_65 , 0 , V_69 ) ;
V_4 -> V_34 . V_126 = V_127 ;
F_72 ( & V_59 -> V_60 ,
& V_4 -> V_34 ) ;
break;
case V_128 :
F_44 ( V_2 , F_22 ( & V_4 -> V_9 ) ) ;
F_70 ( & V_2 -> V_49 , & V_4 -> V_9 ) ;
F_71 ( V_124 , & V_2 -> V_125 ) ;
F_44 ( V_2 , V_4 -> V_18 & V_70 ) ;
F_55 ( V_4 , V_65 , 0 , V_69 | V_89 ) ;
V_4 -> V_34 . V_126 = V_129 ;
F_72 ( & V_59 -> V_60 ,
& V_4 -> V_34 ) ;
F_66 () ;
V_103 = F_67 ( V_59 -> V_102 ) ;
V_104 = V_103 -> V_130 ;
F_68 () ;
if ( V_59 -> V_62 >= V_104 )
F_32 ( V_59 ) ;
break;
case V_131 :
F_55 ( V_4 , V_65 , 0 , V_69 ) ;
V_4 -> V_34 . V_126 = V_132 ;
F_72 ( & V_59 -> V_60 ,
& V_4 -> V_34 ) ;
break;
case V_133 :
case V_134 :
case V_135 :
F_55 ( V_4 , V_65 , V_69 , 0 ) ;
break;
case V_136 :
if ( F_64 ( V_4 ) )
F_55 ( V_4 , V_65 , V_69 | V_70 ,
V_84 | V_52 ) ;
else
F_55 ( V_4 , V_65 , V_69 , V_84 ) ;
break;
case V_137 :
F_55 ( V_4 , V_65 , V_69 , V_48 ) ;
break;
case V_138 :
F_55 ( V_4 , V_65 ,
V_52 | V_70 | V_71 ,
V_48 ) ;
break;
case V_139 :
F_44 ( V_2 , V_4 -> V_18 & V_70 ) ;
F_44 ( V_2 , V_4 -> V_18 & V_98 ) ;
F_55 ( V_4 , V_65 , V_70 , V_48 | V_52 ) ;
break;
case V_140 :
V_4 -> V_18 |= V_54 ;
case V_141 :
goto V_142;
case V_143 :
F_44 ( V_2 , V_4 -> V_18 & V_99 ) ;
V_142:
F_55 ( V_4 , V_65 , V_70 , V_52 ) ;
break;
case V_144 :
F_44 ( V_2 , V_4 -> V_18 & V_98 ) ;
F_44 ( V_2 , V_4 -> V_18 & V_70 ) ;
V_4 -> V_18 |= V_45 ;
if ( V_4 -> V_9 . V_32 )
F_16 ( & V_2 -> V_43 ) ;
break;
case V_145 :
F_55 ( V_4 , V_65 , V_52 | V_70 , 0 ) ;
break;
case V_146 :
if ( ! ( V_4 -> V_18 & V_114 ) )
break;
F_55 ( V_4 , V_65 , V_71 , 0 ) ;
break;
case V_147 :
if ( ! ( V_4 -> V_18 & V_114 ) )
break;
F_55 ( V_4 , V_65 ,
V_71 | V_114 ,
V_46 ) ;
V_105 = V_148 ;
if ( F_3 ( V_4 -> V_8 ) == V_19 )
V_105 = V_149 ;
F_73 ( V_2 ) ;
V_4 -> V_34 . V_126 = V_150 ;
F_72 ( & V_59 -> V_60 ,
& V_4 -> V_34 ) ;
break;
case V_151 :
if ( ! ( V_4 -> V_18 & V_20 ) && ! V_4 -> V_34 . V_126 ) {
F_55 ( V_4 , V_65 , V_71 , 0 ) ;
break;
}
if ( ! ( V_4 -> V_18 & V_52 ) ) {
F_55 ( V_4 , V_65 , V_71 , V_69 | V_70 ) ;
if ( V_4 -> V_34 . V_126 ) {
F_72 ( & V_59 -> V_60 ,
& V_4 -> V_34 ) ;
V_105 = V_4 -> V_18 & V_20 ? V_149 : V_148 ;
}
break;
}
case V_152 :
if ( ! ( V_4 -> V_18 & V_20 ) )
break;
if ( V_4 -> V_18 & V_70 ) {
F_20 ( V_2 , L_11 ) ;
}
F_55 ( V_4 , V_65 , V_71 ,
( V_4 -> V_18 & V_47 ) ? V_48 : 0 ) ;
break;
case V_153 :
F_44 ( V_2 , V_4 -> V_18 & V_70 ) ;
F_55 ( V_4 , V_65 , V_70 , V_52 | V_48 ) ;
break;
case V_154 :
F_32 ( V_59 ) ;
F_55 ( V_4 , V_65 , 0 , V_52 | V_48 ) ;
break;
} ;
return V_105 ;
}
static bool F_74 ( struct V_1 * V_2 , T_1 V_27 , int V_10 )
{
unsigned long V_155 , V_156 ;
T_1 V_157 , V_158 ;
if ( V_2 -> V_159 . V_160 == V_161 )
return true ;
if ( V_2 -> V_159 . V_160 != V_162 )
return false ;
V_157 = V_27 + ( V_10 >> 9 ) - 1 ;
V_158 = F_75 ( V_2 -> V_163 ) ;
F_44 ( V_2 , V_27 < V_158 ) ;
F_44 ( V_2 , V_157 < V_158 ) ;
V_155 = F_76 ( V_27 ) ;
V_156 = F_76 ( V_157 ) ;
return F_77 ( V_2 , V_155 , V_156 ) == 0 ;
}
static bool F_78 ( struct V_1 * V_2 , T_1 V_27 ,
enum V_164 V_165 )
{
struct V_166 * V_167 ;
int V_168 ;
switch ( V_165 ) {
case V_169 :
V_167 = V_2 -> V_96 -> V_97 -> V_170 -> V_171 -> V_166 ;
return F_79 ( V_167 ) ;
case V_172 :
return F_19 ( & V_2 -> V_173 ) >
F_19 ( & V_2 -> V_174 ) + F_19 ( & V_2 -> V_175 ) ;
case V_176 :
case V_177 :
case V_178 :
case V_179 :
case V_180 :
case V_181 :
V_168 = ( V_165 - V_176 + 15 ) ;
return ( V_27 >> ( V_168 - 9 ) ) & 1 ;
case V_182 :
return F_80 ( V_183 , & V_2 -> V_125 ) ;
case V_184 :
return true ;
case V_185 :
default:
return false ;
}
}
static void F_81 ( struct V_3 * V_4 )
{
F_82 ( V_186 ) ;
struct V_1 * V_2 = V_4 -> V_2 ;
struct V_42 * V_9 ;
T_1 V_27 = V_4 -> V_9 . V_27 ;
int V_10 = V_4 -> V_9 . V_10 ;
for (; ; ) {
F_83 (i, &device->write_requests, sector, size) {
if ( V_9 -> V_77 )
continue;
break;
}
if ( ! V_9 )
break;
F_84 ( & V_2 -> V_43 , & V_186 , V_187 ) ;
V_9 -> V_32 = true ;
F_85 ( & V_2 -> V_188 -> V_189 ) ;
F_86 () ;
F_87 ( & V_2 -> V_188 -> V_189 ) ;
}
F_88 ( & V_2 -> V_43 , & V_186 ) ;
}
static void F_89 ( struct V_1 * V_2 )
{
struct V_58 * V_59 = F_41 ( V_2 ) -> V_59 ;
struct V_102 * V_103 ;
bool V_190 = false ;
enum V_191 V_192 ;
F_66 () ;
V_103 = F_67 ( V_59 -> V_102 ) ;
V_192 = V_103 ? V_103 -> V_192 : V_193 ;
F_68 () ;
if ( V_192 == V_193 ||
V_59 -> V_194 < 96 )
return;
if ( V_192 == V_195 && V_2 -> V_159 . V_196 == V_197 )
return;
if ( ! F_25 ( V_2 , V_161 ) )
return;
if ( V_103 -> V_198 &&
F_19 ( & V_2 -> V_90 ) >= V_103 -> V_198 ) {
F_90 ( V_2 , L_12 ) ;
V_190 = true ;
}
if ( V_2 -> V_199 -> V_200 >= V_103 -> V_201 ) {
F_90 ( V_2 , L_13 ) ;
V_190 = true ;
}
if ( V_190 ) {
F_32 ( F_41 ( V_2 ) -> V_59 ) ;
if ( V_192 == V_195 )
F_91 ( F_92 ( V_2 , V_196 , V_197 ) , 0 , NULL ) ;
else
F_91 ( F_92 ( V_2 , V_196 , V_202 ) , 0 , NULL ) ;
}
F_27 ( V_2 ) ;
}
static bool F_93 ( struct V_3 * V_4 )
{
struct V_1 * V_2 = V_4 -> V_2 ;
enum V_164 V_165 ;
if ( V_4 -> V_72 ) {
if ( ! F_74 ( V_2 ,
V_4 -> V_9 . V_27 , V_4 -> V_9 . V_10 ) ) {
F_94 ( V_4 -> V_72 ) ;
V_4 -> V_72 = NULL ;
F_27 ( V_2 ) ;
}
}
if ( V_2 -> V_159 . V_203 != V_161 )
return false ;
if ( V_4 -> V_72 == NULL )
return true ;
F_66 () ;
V_165 = F_67 ( V_2 -> V_96 -> V_204 ) -> V_205 ;
F_68 () ;
if ( V_165 == V_185 && V_4 -> V_72 )
return false ;
if ( F_78 ( V_2 , V_4 -> V_9 . V_27 , V_165 ) ) {
if ( V_4 -> V_72 ) {
F_94 ( V_4 -> V_72 ) ;
V_4 -> V_72 = NULL ;
F_27 ( V_2 ) ;
}
return true ;
}
return false ;
}
bool F_95 ( union V_206 V_44 )
{
return V_44 . V_203 == V_161 ||
( V_44 . V_203 >= V_162 &&
V_44 . V_196 >= V_207 &&
V_44 . V_196 < V_197 ) ;
}
static bool F_96 ( union V_206 V_44 )
{
return V_44 . V_196 == V_197 || V_44 . V_196 == V_208 ;
}
static int F_97 ( struct V_3 * V_4 )
{
struct V_1 * V_2 = V_4 -> V_2 ;
int V_209 , V_210 ;
V_209 = F_95 ( V_2 -> V_159 ) ;
V_210 = F_96 ( V_2 -> V_159 ) ;
if ( F_98 ( V_4 -> V_9 . V_10 == 0 ) ) {
F_44 ( V_2 , V_4 -> V_8 -> V_74 & V_211 ) ;
if ( V_209 )
F_99 ( V_4 , V_154 ) ;
return V_209 ;
}
if ( ! V_209 && ! V_210 )
return 0 ;
F_44 ( V_2 , ! ( V_209 && V_210 ) ) ;
if ( V_209 ) {
F_99 ( V_4 , V_106 ) ;
F_99 ( V_4 , V_128 ) ;
} else if ( F_23 ( V_2 , V_4 -> V_9 . V_27 , V_4 -> V_9 . V_10 ) )
F_99 ( V_4 , V_131 ) ;
return V_209 ;
}
static void F_100 ( struct V_3 * V_4 )
{
struct V_212 * V_213 = V_4 -> V_2 -> V_96 -> V_97 ;
if ( F_101 ( V_213 , V_4 -> V_9 . V_27 , V_4 -> V_9 . V_10 >> 9 ,
V_17 , 0 ) )
V_4 -> V_72 -> V_66 = V_214 ;
F_36 ( V_4 -> V_72 ) ;
}
static void
F_102 ( struct V_3 * V_4 )
{
struct V_1 * V_2 = V_4 -> V_2 ;
struct V_14 * V_14 = V_4 -> V_72 ;
unsigned int type ;
if ( F_9 ( V_14 ) != V_73 )
type = V_215 ;
else if ( V_14 -> V_74 & V_75 )
type = V_216 ;
else
type = V_217 ;
F_103 ( V_14 , V_2 -> V_96 -> V_97 ) ;
if ( F_73 ( V_2 ) ) {
if ( F_104 ( V_2 , type ) )
F_105 ( V_14 ) ;
else if ( F_9 ( V_14 ) == V_23 ||
F_9 ( V_14 ) == V_25 )
F_100 ( V_4 ) ;
else
F_106 ( V_14 ) ;
F_27 ( V_2 ) ;
} else
F_105 ( V_14 ) ;
}
static void F_107 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
F_87 ( & V_2 -> V_188 -> V_189 ) ;
F_108 ( & V_4 -> V_33 , & V_2 -> V_218 . V_219 ) ;
F_108 ( & V_4 -> V_36 ,
& V_2 -> V_220 [ 1 ] ) ;
F_85 ( & V_2 -> V_188 -> V_189 ) ;
F_109 ( V_2 -> V_218 . V_221 , & V_2 -> V_218 . V_222 ) ;
F_16 ( & V_2 -> V_223 ) ;
}
static struct V_3 *
F_110 ( struct V_1 * V_2 , struct V_14 * V_14 , unsigned long V_13 )
{
const int V_224 = F_3 ( V_14 ) ;
struct V_3 * V_4 ;
V_4 = F_6 ( V_2 , V_14 ) ;
if ( ! V_4 ) {
F_37 ( V_2 ) ;
F_20 ( V_2 , L_14 ) ;
V_14 -> V_66 = V_225 ;
F_36 ( V_14 ) ;
return F_111 ( - V_226 ) ;
}
V_4 -> V_13 = V_13 ;
if ( ! F_73 ( V_2 ) ) {
F_94 ( V_4 -> V_72 ) ;
V_4 -> V_72 = NULL ;
}
F_1 ( V_2 , V_4 ) ;
if ( ( F_9 ( V_14 ) & V_23 ) ||
( F_9 ( V_14 ) & V_25 ) )
goto V_227;
if ( V_224 == V_19 && V_4 -> V_72 && V_4 -> V_9 . V_10
&& ! F_112 ( V_228 , & V_2 -> V_125 ) ) {
if ( ! F_113 ( V_2 , & V_4 -> V_9 ) )
goto V_227;
V_4 -> V_18 |= V_55 ;
V_4 -> V_229 = V_92 ;
}
return V_4 ;
V_227:
F_33 ( & V_2 -> V_230 ) ;
F_107 ( V_2 , V_4 ) ;
return NULL ;
}
static bool F_114 ( struct V_1 * V_2 )
{
const union V_206 V_44 = V_2 -> V_159 ;
return V_44 . V_160 == V_161 || V_44 . V_203 == V_161 ;
}
static void F_115 ( struct V_231 * V_126 , bool V_232 )
{
struct V_233 * V_234 = F_18 ( V_126 , struct V_233 , V_126 ) ;
struct V_235 * V_188 = V_234 -> V_126 . V_236 ;
struct V_3 * V_4 = V_234 -> V_237 ;
F_116 ( V_126 ) ;
if ( ! V_4 )
return;
F_87 ( & V_188 -> V_189 ) ;
V_4 -> V_18 |= V_238 ;
F_117 ( V_4 -> V_2 ) ;
F_47 ( & V_4 -> V_39 , F_17 ) ;
F_85 ( & V_188 -> V_189 ) ;
}
static struct V_233 * F_118 ( struct V_235 * V_188 )
{
struct V_233 * V_234 ;
struct V_231 * V_126 = F_119 ( F_115 , V_188 , sizeof( * V_234 ) ) ;
if ( V_126 )
V_234 = F_18 ( V_126 , struct V_233 , V_126 ) ;
else
V_234 = NULL ;
return V_234 ;
}
static void F_120 ( struct V_233 * V_234 , struct V_3 * V_4 )
{
struct V_3 * V_239 = V_234 -> V_237 ;
F_57 ( & V_4 -> V_39 ) ;
V_234 -> V_237 = V_4 ;
if ( V_239 )
F_47 ( & V_239 -> V_39 , F_17 ) ;
}
static void F_121 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_235 * V_188 = V_2 -> V_188 ;
const int V_224 = F_3 ( V_4 -> V_8 ) ;
struct V_64 V_65 = { NULL , } ;
bool V_240 = false ;
bool V_241 = false ;
F_87 ( & V_188 -> V_189 ) ;
if ( V_224 == V_19 ) {
F_81 ( V_4 ) ;
F_89 ( V_2 ) ;
}
if ( F_56 ( V_2 ) ) {
V_4 -> V_18 |= V_45 ;
if ( V_4 -> V_72 ) {
F_94 ( V_4 -> V_72 ) ;
V_4 -> V_72 = NULL ;
F_27 ( V_2 ) ;
}
goto V_242;
}
if ( V_224 != V_19 ) {
if ( ! F_93 ( V_4 ) && ! V_4 -> V_72 )
goto V_243;
}
V_4 -> V_26 = F_19 ( & F_41 ( V_2 ) -> V_59 -> V_63 ) ;
if ( F_122 ( V_4 -> V_9 . V_10 != 0 ) ) {
if ( V_224 == V_19 )
F_41 ( V_2 ) -> V_59 -> V_62 ++ ;
F_108 ( & V_4 -> V_33 , & F_41 ( V_2 ) -> V_59 -> V_82 ) ;
}
if ( V_224 == V_19 ) {
if ( V_4 -> V_72 && ! F_114 ( V_2 ) ) {
F_94 ( V_4 -> V_72 ) ;
V_4 -> V_72 = NULL ;
F_27 ( V_2 ) ;
goto V_243;
}
if ( ! F_97 ( V_4 ) )
V_240 = true ;
} else {
if ( V_4 -> V_72 == NULL ) {
F_99 ( V_4 , V_106 ) ;
F_99 ( V_4 , V_123 ) ;
} else
V_240 = true ;
}
if ( V_240 == false ) {
struct V_233 * V_234 = F_118 ( V_188 ) ;
if ( V_234 )
F_120 ( V_234 , V_4 ) ;
}
if ( F_42 ( & V_4 -> V_36 ) )
F_108 ( & V_4 -> V_36 ,
& V_2 -> V_220 [ V_224 == V_19 ] ) ;
if ( V_4 -> V_72 ) {
V_4 -> V_244 = V_92 ;
F_108 ( & V_4 -> V_37 ,
& V_2 -> V_245 [ V_224 == V_19 ] ) ;
F_99 ( V_4 , V_110 ) ;
V_241 = true ;
} else if ( V_240 ) {
V_243:
if ( F_28 ( & V_57 ) )
F_20 ( V_2 , L_15 ,
( unsigned long long ) V_4 -> V_9 . V_27 , V_4 -> V_9 . V_10 >> 9 ) ;
}
V_242:
F_43 ( V_4 , & V_65 , 1 ) ;
F_85 ( & V_188 -> V_189 ) ;
if ( V_241 )
F_102 ( V_4 ) ;
if ( V_65 . V_14 )
F_34 ( V_2 , & V_65 ) ;
}
void F_123 ( struct V_1 * V_2 , struct V_14 * V_14 , unsigned long V_13 )
{
struct V_3 * V_4 = F_110 ( V_2 , V_14 , V_13 ) ;
if ( F_124 ( V_4 ) )
return;
F_121 ( V_2 , V_4 ) ;
}
static void F_125 ( struct V_1 * V_2 , struct V_246 * V_247 )
{
struct V_248 V_234 ;
struct V_3 * V_4 , * V_239 ;
F_126 ( & V_234 ) ;
F_127 (req, tmp, incoming, tl_requests) {
const int V_224 = F_3 ( V_4 -> V_8 ) ;
if ( V_224 == V_19
&& V_4 -> V_72 && V_4 -> V_9 . V_10
&& ! F_112 ( V_228 , & V_2 -> V_125 ) ) {
if ( ! F_113 ( V_2 , & V_4 -> V_9 ) )
continue;
V_4 -> V_18 |= V_55 ;
V_4 -> V_229 = V_92 ;
F_128 ( & V_2 -> V_230 ) ;
}
F_21 ( & V_4 -> V_33 ) ;
F_121 ( V_2 , V_4 ) ;
}
F_129 ( & V_234 ) ;
}
static bool F_130 ( struct V_1 * V_2 ,
struct V_246 * V_247 ,
struct V_246 * V_249 ,
struct V_246 * V_250 )
{
struct V_3 * V_4 ;
int V_251 = 0 ;
int V_252 ;
F_87 ( & V_2 -> V_253 ) ;
while ( ( V_4 = F_131 ( V_247 , struct V_3 , V_33 ) ) ) {
V_252 = F_132 ( V_2 , & V_4 -> V_9 ) ;
if ( V_252 == - V_254 )
break;
if ( V_252 == - V_255 )
V_251 = 1 ;
if ( V_252 )
F_133 ( & V_4 -> V_33 , V_250 ) ;
else
F_133 ( & V_4 -> V_33 , V_249 ) ;
}
F_85 ( & V_2 -> V_253 ) ;
if ( V_251 )
F_16 ( & V_2 -> V_223 ) ;
return ! F_42 ( V_249 ) ;
}
static void F_134 ( struct V_1 * V_2 , struct V_246 * V_249 )
{
struct V_248 V_234 ;
struct V_3 * V_4 ;
F_126 ( & V_234 ) ;
while ( ( V_4 = F_131 ( V_249 , struct V_3 , V_33 ) ) ) {
V_4 -> V_18 |= V_55 ;
V_4 -> V_229 = V_92 ;
F_128 ( & V_2 -> V_230 ) ;
F_21 ( & V_4 -> V_33 ) ;
F_121 ( V_2 , V_4 ) ;
}
F_129 ( & V_234 ) ;
}
void F_135 ( struct V_256 * V_257 )
{
struct V_1 * V_2 = F_18 ( V_257 , struct V_1 , V_218 . V_222 ) ;
F_136 ( V_247 ) ;
F_136 ( V_249 ) ;
F_136 ( V_258 ) ;
F_87 ( & V_2 -> V_188 -> V_189 ) ;
F_137 ( & V_2 -> V_218 . V_219 , & V_247 ) ;
F_85 ( & V_2 -> V_188 -> V_189 ) ;
for (; ; ) {
F_82 ( V_186 ) ;
F_138 ( & V_258 , & V_247 ) ;
F_125 ( V_2 , & V_247 ) ;
if ( F_42 ( & V_247 ) )
break;
for (; ; ) {
F_84 ( & V_2 -> V_223 , & V_186 , V_187 ) ;
F_138 ( & V_258 , & V_247 ) ;
F_130 ( V_2 , & V_247 , & V_249 , & V_258 ) ;
if ( ! F_42 ( & V_249 ) )
break;
F_86 () ;
if ( ! F_42 ( & V_247 ) )
continue;
F_87 ( & V_2 -> V_188 -> V_189 ) ;
F_137 ( & V_2 -> V_218 . V_219 , & V_247 ) ;
F_85 ( & V_2 -> V_188 -> V_189 ) ;
}
F_88 ( & V_2 -> V_223 , & V_186 ) ;
while ( F_42 ( & V_247 ) ) {
F_136 ( V_259 ) ;
F_136 ( V_260 ) ;
bool V_261 ;
if ( F_42 ( & V_2 -> V_218 . V_219 ) )
break;
F_87 ( & V_2 -> V_188 -> V_189 ) ;
F_137 ( & V_2 -> V_218 . V_219 , & V_260 ) ;
F_85 ( & V_2 -> V_188 -> V_189 ) ;
if ( F_42 ( & V_260 ) )
break;
V_261 = F_130 ( V_2 , & V_260 , & V_259 , & V_258 ) ;
F_137 ( & V_259 , & V_249 ) ;
F_137 ( & V_260 , & V_247 ) ;
if ( ! V_261 )
break;
}
F_139 ( V_2 ) ;
F_134 ( V_2 , & V_249 ) ;
}
}
T_2 F_140 ( struct V_5 * V_6 , struct V_14 * V_14 )
{
struct V_1 * V_2 = (struct V_1 * ) V_6 -> V_262 ;
unsigned long V_13 ;
F_141 ( V_6 , & V_14 ) ;
V_13 = V_92 ;
F_44 ( V_2 , F_142 ( V_14 -> V_28 . V_30 , 512 ) ) ;
F_143 ( V_2 ) ;
F_123 ( V_2 , V_14 , V_13 ) ;
return V_263 ;
}
static bool F_144 ( struct V_3 * V_264 ,
struct V_58 * V_59 ,
unsigned long V_265 , unsigned long V_266 ,
unsigned int V_267 , unsigned int V_268 )
{
struct V_1 * V_2 = V_264 -> V_2 ;
if ( ! F_145 ( V_265 , V_264 -> V_269 + V_266 ) )
return false ;
if ( F_146 ( V_265 , V_59 -> V_270 , V_59 -> V_270 + V_266 ) )
return false ;
if ( V_264 -> V_18 & V_70 ) {
F_29 ( V_2 , L_16 ,
F_147 ( V_265 - V_264 -> V_269 ) , V_267 , V_268 ) ;
return true ;
}
if ( V_264 -> V_26 == V_59 -> V_271 . V_272 ) {
F_29 ( V_2 ,
L_17 ,
F_147 ( V_265 - V_264 -> V_269 ) , V_267 , V_268 ) ;
return false ;
}
if ( F_145 ( V_265 , V_59 -> V_271 . V_273 + V_266 ) ) {
F_29 ( V_2 , L_18 ,
V_59 -> V_271 . V_273 , V_265 ,
F_147 ( V_265 - V_59 -> V_271 . V_273 ) , V_267 , V_268 ) ;
return true ;
}
return false ;
}
void F_148 ( unsigned long V_236 )
{
struct V_1 * V_2 = (struct V_1 * ) V_236 ;
struct V_58 * V_59 = F_41 ( V_2 ) -> V_59 ;
struct V_3 * V_274 , * V_275 , * V_276 ;
struct V_102 * V_103 ;
unsigned long V_277 ;
unsigned long V_266 = 0 , V_278 = 0 , V_279 , V_280 ;
unsigned long V_265 ;
unsigned int V_267 = 0 , V_268 = 0 ;
F_66 () ;
V_103 = F_67 ( V_59 -> V_102 ) ;
if ( V_103 && V_2 -> V_159 . V_196 >= V_281 ) {
V_267 = V_103 -> V_267 ;
V_268 = V_103 -> V_268 ;
}
if ( F_73 ( V_2 ) ) {
V_278 = F_67 ( V_2 -> V_96 -> V_204 ) -> V_282 * V_283 / 10 ;
F_27 ( V_2 ) ;
}
F_68 () ;
V_266 = V_268 * V_283 / 10 * V_267 ;
V_279 = F_149 ( V_278 , V_266 ) ;
if ( ! V_279 )
return;
V_265 = V_92 ;
V_280 = V_265 + V_279 ;
F_87 ( & V_2 -> V_188 -> V_189 ) ;
V_274 = F_131 ( & V_2 -> V_245 [ 0 ] , struct V_3 , V_37 ) ;
V_275 = F_131 ( & V_2 -> V_245 [ 1 ] , struct V_3 , V_37 ) ;
V_276 = V_59 -> V_83 ;
if ( ! V_276 )
V_276 = V_59 -> V_85 ;
if ( V_276 && V_276 -> V_2 != V_2 )
V_276 = NULL ;
if ( V_276 == NULL && V_275 == NULL && V_274 == NULL )
goto V_242;
V_277 =
( V_275 && V_274 )
? ( F_150 ( V_275 -> V_244 , V_274 -> V_244 )
? V_275 -> V_244 : V_274 -> V_244 )
: V_275 ? V_275 -> V_244
: V_274 ? V_274 -> V_244 : V_265 ;
if ( V_266 && V_276 && F_144 ( V_276 , V_59 , V_265 , V_266 , V_267 , V_268 ) )
F_151 ( V_59 , F_152 ( V_196 , V_284 ) , V_285 | V_286 ) ;
if ( V_278 && V_277 != V_265 &&
F_145 ( V_265 , V_277 + V_278 ) &&
! F_146 ( V_265 , V_2 -> V_287 , V_2 -> V_287 + V_278 ) ) {
F_29 ( V_2 , L_19 ) ;
F_69 ( V_2 , V_288 ) ;
}
V_266 = ( V_266 && V_276 && F_150 ( V_265 , V_276 -> V_269 + V_266 ) )
? V_276 -> V_269 + V_266 : V_265 + V_279 ;
V_278 = ( V_278 && V_277 != V_265 && F_150 ( V_265 , V_277 + V_278 ) )
? V_277 + V_278 : V_265 + V_279 ;
V_280 = F_150 ( V_266 , V_278 ) ? V_266 : V_278 ;
V_242:
F_85 ( & V_2 -> V_188 -> V_189 ) ;
F_153 ( & V_2 -> V_289 , V_280 ) ;
}
