const char *
F_1 ( const enum V_1 V_2 )
{
F_2 ( F_3 ( V_3 ) != V_4 ) ;
if ( V_2 >= 0 && V_2 < V_4 )
return V_3 [ V_2 ] ;
F_4 ( V_2 ) ;
return L_1 ;
}
static inline void
F_5 ( struct V_5 * V_6 ,
const struct V_7 * V_8 )
{
F_6 ( V_6 , V_8 -> V_9 , V_6 -> V_10 . V_11 ) ;
}
static inline void
F_7 ( struct V_7 * V_8 )
{
V_8 -> V_12 ++ ;
F_8 ( & V_8 -> V_13 ,
V_14 ,
V_14 ,
V_15 ) ;
}
static inline void
F_9 ( const struct V_5 * V_6 ,
const struct V_7 * V_8 )
{
if ( F_10 ( ( F_11 ( V_6 , V_8 -> V_16 ) &
V_17 ) == 0 ,
V_18 ) )
F_12 ( L_2 ,
F_1 ( V_8 -> V_2 ) ) ;
}
static inline void
F_13 ( struct V_5 * V_6 ,
const struct V_7 * V_8 )
{
F_6 ( V_6 , V_8 -> V_9 , V_6 -> V_10 . V_19 ) ;
}
static inline void
F_14 ( const struct V_5 * V_6 ,
const struct V_7 * V_8 )
{
if ( F_10 ( ( F_11 ( V_6 , V_8 -> V_16 ) &
V_17 ) ,
V_18 ) )
F_12 ( L_3 ,
F_1 ( V_8 -> V_2 ) ) ;
}
static inline void
F_15 ( const struct V_5 * V_6 ,
const struct V_7 * V_8 )
{
F_6 ( V_6 , V_8 -> V_9 , V_6 -> V_10 . V_20 ) ;
}
static void
F_16 ( struct V_5 * V_6 , enum V_21 V_22 )
{
struct V_7 * V_8 ;
unsigned int V_23 ;
F_17 ( V_22 & ~ V_6 -> V_10 . V_22 ) ;
F_18 (d, fw_domains, i915, tmp) {
F_9 ( V_6 , V_8 ) ;
F_13 ( V_6 , V_8 ) ;
}
F_18 (d, fw_domains, i915, tmp)
F_14 ( V_6 , V_8 ) ;
V_6 -> V_10 . V_24 |= V_22 ;
}
static void
F_19 ( struct V_5 * V_6 , enum V_21 V_22 )
{
struct V_7 * V_8 ;
unsigned int V_23 ;
F_17 ( V_22 & ~ V_6 -> V_10 . V_22 ) ;
F_18 (d, fw_domains, i915, tmp)
F_15 ( V_6 , V_8 ) ;
V_6 -> V_10 . V_24 &= ~ V_22 ;
}
static void
F_20 ( struct V_5 * V_6 ,
enum V_21 V_22 )
{
struct V_7 * V_8 ;
unsigned int V_23 ;
if ( ! V_22 )
return;
F_17 ( V_22 & ~ V_6 -> V_10 . V_22 ) ;
F_18 (d, fw_domains, i915, tmp)
F_5 ( V_6 , V_8 ) ;
}
static void F_21 ( struct V_5 * V_25 )
{
if ( F_22 ( ( F_11 ( V_25 , V_26 ) &
V_27 ) == 0 , 500 ) )
F_12 ( L_4 ) ;
}
static void F_23 ( struct V_5 * V_25 ,
enum V_21 V_22 )
{
F_16 ( V_25 , V_22 ) ;
F_21 ( V_25 ) ;
}
static void F_24 ( struct V_5 * V_25 )
{
T_1 V_28 ;
V_28 = F_11 ( V_25 , V_29 ) ;
if ( F_25 ( V_28 , L_5 , V_28 ) )
F_6 ( V_25 , V_29 , V_28 ) ;
}
static void F_26 ( struct V_5 * V_25 ,
enum V_21 V_22 )
{
F_19 ( V_25 , V_22 ) ;
F_24 ( V_25 ) ;
}
static inline T_1 F_27 ( struct V_5 * V_25 )
{
T_1 V_30 = F_11 ( V_25 , V_31 ) ;
return V_30 & V_32 ;
}
static int F_28 ( struct V_5 * V_25 )
{
int V_33 = 0 ;
if ( F_29 ( V_25 ) )
V_25 -> V_10 . V_34 = F_27 ( V_25 ) ;
if ( V_25 -> V_10 . V_34 < V_35 ) {
int V_36 = 500 ;
T_1 V_37 = F_27 ( V_25 ) ;
while ( V_37 <= V_35 && V_36 -- ) {
F_30 ( 10 ) ;
V_37 = F_27 ( V_25 ) ;
}
if ( F_4 ( V_36 < 0 && V_37 <= V_35 ) )
++ V_33 ;
V_25 -> V_10 . V_34 = V_37 ;
}
V_25 -> V_10 . V_34 -- ;
return V_33 ;
}
static enum V_38
F_31 ( struct V_39 * V_13 )
{
struct V_7 * V_40 =
F_32 ( V_13 , struct V_7 , V_13 ) ;
struct V_5 * V_25 =
F_32 ( V_40 , struct V_5 , V_10 . V_41 [ V_40 -> V_2 ] ) ;
unsigned long V_42 ;
F_33 ( V_25 ) ;
F_34 ( & V_25 -> V_10 . V_43 , V_42 ) ;
if ( F_4 ( V_40 -> V_12 == 0 ) )
V_40 -> V_12 ++ ;
if ( -- V_40 -> V_12 == 0 )
V_25 -> V_10 . V_44 . V_45 ( V_25 , V_40 -> V_46 ) ;
F_35 ( & V_25 -> V_10 . V_43 , V_42 ) ;
return V_47 ;
}
static void F_36 ( struct V_5 * V_25 ,
bool V_48 )
{
unsigned long V_42 ;
struct V_7 * V_40 ;
int V_49 = 100 ;
enum V_21 V_50 , V_51 ;
while ( 1 ) {
unsigned int V_23 ;
V_51 = 0 ;
F_37 (domain, dev_priv, tmp) {
if ( F_38 ( & V_40 -> V_13 ) == 0 )
continue;
F_31 ( & V_40 -> V_13 ) ;
}
F_34 ( & V_25 -> V_10 . V_43 , V_42 ) ;
F_37 (domain, dev_priv, tmp) {
if ( F_39 ( & V_40 -> V_13 ) )
V_51 |= V_40 -> V_46 ;
}
if ( V_51 == 0 )
break;
if ( -- V_49 == 0 ) {
F_12 ( L_6 ) ;
break;
}
F_35 ( & V_25 -> V_10 . V_43 , V_42 ) ;
F_40 () ;
}
F_4 ( V_51 ) ;
V_50 = V_25 -> V_10 . V_24 ;
if ( V_50 )
V_25 -> V_10 . V_44 . V_45 ( V_25 , V_50 ) ;
F_20 ( V_25 , V_25 -> V_10 . V_22 ) ;
if ( V_48 ) {
if ( V_50 )
V_25 -> V_10 . V_44 . V_52 ( V_25 , V_50 ) ;
if ( F_41 ( V_25 ) || F_42 ( V_25 ) )
V_25 -> V_10 . V_34 =
F_27 ( V_25 ) ;
}
if ( ! V_48 )
F_43 ( V_25 ) ;
F_35 ( & V_25 -> V_10 . V_43 , V_42 ) ;
}
static T_2 F_44 ( struct V_5 * V_25 )
{
const unsigned int V_53 [ 8 ] = { 4 , 8 , 12 , 16 , 16 , 16 , 16 , 16 } ;
const unsigned int V_54 [ 4 ] = { 1 , 1 , 2 , 2 } ;
const T_1 V_55 = V_25 -> V_56 ;
return F_45 ( V_55 ) *
V_53 [ F_46 ( V_55 ) ] *
V_54 [ F_47 ( V_55 ) ] *
1024 * 1024 ;
}
T_2 F_48 ( struct V_5 * V_25 )
{
if ( ! F_49 ( V_25 ) )
return 0 ;
if ( F_50 ( V_25 ) < 9 )
return 128 * 1024 * 1024 ;
return F_44 ( V_25 ) ;
}
static void F_51 ( struct V_5 * V_25 )
{
if ( F_52 ( V_25 ) ||
F_53 ( V_25 ) ||
F_50 ( V_25 ) >= 9 ) {
V_25 -> V_56 = F_11 ( V_25 ,
V_57 ) ;
} else {
V_25 -> V_56 = 0 ;
}
if ( F_49 ( V_25 ) )
F_54 ( L_7 ,
F_48 ( V_25 ) / ( 1024 * 1024 ) ) ;
}
static bool
F_55 ( struct V_5 * V_25 )
{
T_1 V_58 ;
V_58 = F_11 ( V_25 , V_59 ) ;
if ( F_56 ( ! ( V_58 & V_60 ) ) )
return false ;
F_6 ( V_25 , V_59 , V_60 ) ;
return true ;
}
static bool
F_57 ( struct V_5 * V_25 )
{
T_1 V_61 ;
V_61 = F_11 ( V_25 , V_62 ) ;
if ( F_56 ( ! ( V_61 & ( V_63 | V_64 ) ) ) )
return false ;
F_6 ( V_25 , V_62 , V_65 ) ;
return true ;
}
static bool
F_58 ( struct V_5 * V_25 )
{
if ( F_59 ( V_25 ) )
return F_55 ( V_25 ) ;
if ( F_29 ( V_25 ) || F_60 ( V_25 ) )
return F_57 ( V_25 ) ;
return false ;
}
static void F_61 ( struct V_5 * V_25 ,
bool V_66 )
{
struct V_67 * V_68 = F_62 ( V_25 ) ;
if ( F_58 ( V_25 ) )
F_63 ( L_8 ) ;
if ( F_41 ( V_25 ) || F_42 ( V_25 ) )
F_6 ( V_25 , V_29 ,
F_11 ( V_25 , V_29 ) ) ;
if ( F_60 ( V_25 ) ) {
F_6 ( V_25 , V_31 ,
F_11 ( V_25 , V_31 ) |
V_69 |
V_70 ) ;
}
if ( F_64 ( V_25 , 0 , V_71 ) )
V_68 -> V_72 = false ;
F_36 ( V_25 , V_66 ) ;
}
void F_65 ( struct V_5 * V_25 )
{
F_66 (
& V_25 -> V_10 . V_73 ) ;
F_36 ( V_25 , false ) ;
}
void F_67 ( struct V_5 * V_25 )
{
F_61 ( V_25 , true ) ;
F_68 (
& V_25 -> V_10 . V_73 ) ;
F_69 ( V_25 ) ;
}
void F_70 ( struct V_5 * V_25 )
{
V_6 . V_74 = F_71 ( V_25 , V_6 . V_74 ) ;
F_72 ( V_25 ) ;
}
static void F_73 ( struct V_5 * V_25 ,
enum V_21 V_22 )
{
struct V_7 * V_40 ;
unsigned int V_23 ;
V_22 &= V_25 -> V_10 . V_22 ;
F_18 (domain, fw_domains, dev_priv, tmp)
if ( V_40 -> V_12 ++ )
V_22 &= ~ V_40 -> V_46 ;
if ( V_22 )
V_25 -> V_10 . V_44 . V_52 ( V_25 , V_22 ) ;
}
void F_74 ( struct V_5 * V_25 ,
enum V_21 V_22 )
{
unsigned long V_42 ;
if ( ! V_25 -> V_10 . V_44 . V_52 )
return;
F_75 ( V_25 ) ;
F_34 ( & V_25 -> V_10 . V_43 , V_42 ) ;
F_73 ( V_25 , V_22 ) ;
F_35 ( & V_25 -> V_10 . V_43 , V_42 ) ;
}
void F_76 ( struct V_5 * V_25 ,
enum V_21 V_22 )
{
F_77 ( & V_25 -> V_10 . V_43 ) ;
if ( ! V_25 -> V_10 . V_44 . V_52 )
return;
F_73 ( V_25 , V_22 ) ;
}
static void F_78 ( struct V_5 * V_25 ,
enum V_21 V_22 )
{
struct V_7 * V_40 ;
unsigned int V_23 ;
V_22 &= V_25 -> V_10 . V_22 ;
F_18 (domain, fw_domains, dev_priv, tmp) {
if ( F_4 ( V_40 -> V_12 == 0 ) )
continue;
if ( -- V_40 -> V_12 )
continue;
F_7 ( V_40 ) ;
}
}
void F_79 ( struct V_5 * V_25 ,
enum V_21 V_22 )
{
unsigned long V_42 ;
if ( ! V_25 -> V_10 . V_44 . V_45 )
return;
F_34 ( & V_25 -> V_10 . V_43 , V_42 ) ;
F_78 ( V_25 , V_22 ) ;
F_35 ( & V_25 -> V_10 . V_43 , V_42 ) ;
}
void F_80 ( struct V_5 * V_25 ,
enum V_21 V_22 )
{
F_77 ( & V_25 -> V_10 . V_43 ) ;
if ( ! V_25 -> V_10 . V_44 . V_45 )
return;
F_78 ( V_25 , V_22 ) ;
}
void F_43 ( struct V_5 * V_25 )
{
if ( ! V_25 -> V_10 . V_44 . V_52 )
return;
F_4 ( V_25 -> V_10 . V_24 ) ;
}
static int F_81 ( T_1 V_75 , const struct V_76 * V_77 )
{
if ( V_75 < V_77 -> V_78 )
return - 1 ;
else if ( V_75 > V_77 -> V_79 )
return 1 ;
else
return 0 ;
}
static enum V_21
F_82 ( struct V_5 * V_25 , T_1 V_75 )
{
const struct V_76 * V_77 ;
V_77 = BSEARCH ( V_75 ,
V_25 -> V_10 . V_80 ,
V_25 -> V_10 . V_81 ,
F_81 ) ;
if ( ! V_77 )
return 0 ;
F_25 ( V_77 -> V_82 & ~ V_25 -> V_10 . V_22 ,
L_9 ,
V_77 -> V_82 & ~ V_25 -> V_10 . V_22 , V_75 ) ;
return V_77 -> V_82 ;
}
static int F_83 ( T_1 V_83 , const T_3 * V_84 )
{
T_1 V_75 = F_84 ( * V_84 ) ;
if ( V_83 < V_75 )
return - 1 ;
else if ( V_83 > V_75 )
return 1 ;
else
return 0 ;
}
static bool F_85 ( T_1 V_75 )
{
const T_3 * V_85 = V_86 ;
return BSEARCH ( V_75 , V_85 , F_3 ( V_86 ) ,
F_83 ) ;
}
static void
F_86 ( struct V_5 * V_25 )
{
F_6 ( V_25 , V_87 , 0 ) ;
}
static void
F_87 ( struct V_5 * V_25 ,
const T_3 V_84 ,
const bool V_88 ,
const bool V_89 )
{
if ( F_25 ( F_58 ( V_25 ) && ! V_89 ,
L_10 ,
V_88 ? L_11 : L_12 ,
F_84 ( V_84 ) ) )
V_6 . V_90 -- ;
}
static inline void
F_88 ( struct V_5 * V_25 ,
const T_3 V_84 ,
const bool V_88 ,
const bool V_89 )
{
if ( F_56 ( ! V_6 . V_90 ) )
return;
F_87 ( V_25 , V_84 , V_88 , V_89 ) ;
}
static void F_89 ( struct V_5 * V_25 ,
T_1 V_84 ,
enum V_21 V_41 ,
enum V_91 V_92 )
{
enum V_93 V_94 ;
T_1 V_95 = 0 ;
V_94 = V_96 [ V_41 - 1 ] ;
V_95 |= V_84 ;
V_95 |= ( V_92 << V_97 ) ;
V_95 |= ( V_94 << V_98 ) ;
V_95 |= V_99 ;
F_6 ( V_25 , V_100 , V_95 ) ;
if ( F_10 ( ( F_11 ( V_25 ,
V_100 ) &
V_99 ) == 0 ,
V_18 ) )
F_12 ( L_13 ) ;
}
static inline T_1
F_90 ( struct V_5 * V_25 ,
T_1 V_84 ,
enum V_21 V_41 )
{
F_89 ( V_25 , V_84 , V_41 ,
V_101 ) ;
return F_11 ( V_25 , V_102 ) ;
}
static inline void
F_91 ( struct V_5 * V_25 ,
T_1 V_84 , T_1 V_103 ,
enum V_21 V_41 )
{
F_6 ( V_25 , V_102 , V_103 ) ;
F_89 ( V_25 , V_84 , V_41 ,
V_104 ) ;
}
static T_4 void F_92 ( struct V_5 * V_25 ,
enum V_21 V_22 )
{
struct V_7 * V_40 ;
unsigned int V_23 ;
F_17 ( V_22 & ~ V_25 -> V_10 . V_22 ) ;
F_18 (domain, fw_domains, dev_priv, tmp)
F_7 ( V_40 ) ;
V_25 -> V_10 . V_44 . V_52 ( V_25 , V_22 ) ;
}
static inline void F_93 ( struct V_5 * V_25 ,
enum V_21 V_22 )
{
if ( F_4 ( ! V_22 ) )
return;
V_22 &= V_25 -> V_10 . V_22 ;
V_22 &= ~ V_25 -> V_10 . V_24 ;
if ( V_22 )
F_92 ( V_25 , V_22 ) ;
}
static void F_94 ( struct V_5 * V_25 ,
enum V_1 V_105 ,
T_3 V_9 ,
T_3 V_16 )
{
struct V_7 * V_8 ;
if ( F_4 ( V_105 >= V_4 ) )
return;
V_8 = & V_25 -> V_10 . V_41 [ V_105 ] ;
F_4 ( V_8 -> V_12 ) ;
F_4 ( ! F_95 ( V_9 ) ) ;
F_4 ( ! F_95 ( V_16 ) ) ;
V_8 -> V_12 = 0 ;
V_8 -> V_9 = V_9 ;
V_8 -> V_16 = V_16 ;
V_8 -> V_2 = V_105 ;
F_2 ( V_106 != ( 1 << V_107 ) ) ;
F_2 ( V_108 != ( 1 << V_109 ) ) ;
F_2 ( V_110 != ( 1 << V_111 ) ) ;
V_8 -> V_46 = F_96 ( V_105 ) ;
F_97 ( & V_8 -> V_13 , V_112 , V_15 ) ;
V_8 -> V_13 . V_113 = F_31 ;
V_25 -> V_10 . V_22 |= F_96 ( V_105 ) ;
F_5 ( V_25 , V_8 ) ;
}
static void F_98 ( struct V_5 * V_25 )
{
if ( F_50 ( V_25 ) <= 5 || F_99 ( V_25 ) )
return;
if ( F_41 ( V_25 ) ) {
V_25 -> V_10 . V_11 = 0 ;
V_25 -> V_10 . V_19 = V_17 ;
V_25 -> V_10 . V_20 = 0 ;
} else {
V_25 -> V_10 . V_11 = F_100 ( 0xffff ) ;
V_25 -> V_10 . V_19 = F_101 ( V_17 ) ;
V_25 -> V_10 . V_20 = F_100 ( V_17 ) ;
}
if ( F_102 ( V_25 ) ) {
V_25 -> V_10 . V_44 . V_52 = F_16 ;
V_25 -> V_10 . V_44 . V_45 = F_19 ;
F_94 ( V_25 , V_107 ,
V_114 ,
V_115 ) ;
F_94 ( V_25 , V_109 ,
V_116 ,
V_117 ) ;
F_94 ( V_25 , V_111 ,
V_118 , V_119 ) ;
} else if ( F_29 ( V_25 ) || F_60 ( V_25 ) ) {
V_25 -> V_10 . V_44 . V_52 = F_16 ;
if ( ! F_60 ( V_25 ) )
V_25 -> V_10 . V_44 . V_45 =
F_26 ;
else
V_25 -> V_10 . V_44 . V_45 = F_19 ;
F_94 ( V_25 , V_107 ,
V_120 , V_121 ) ;
F_94 ( V_25 , V_111 ,
V_122 , V_123 ) ;
} else if ( F_52 ( V_25 ) || F_53 ( V_25 ) ) {
V_25 -> V_10 . V_44 . V_52 =
F_23 ;
if ( F_52 ( V_25 ) )
V_25 -> V_10 . V_44 . V_45 =
F_26 ;
else
V_25 -> V_10 . V_44 . V_45 = F_19 ;
F_94 ( V_25 , V_107 ,
V_124 , V_125 ) ;
} else if ( F_103 ( V_25 ) ) {
T_1 V_126 ;
V_25 -> V_10 . V_44 . V_52 =
F_23 ;
V_25 -> V_10 . V_44 . V_45 =
F_26 ;
F_6 ( V_25 , V_127 , 0 ) ;
F_104 ( V_25 , V_128 ) ;
F_94 ( V_25 , V_107 ,
V_124 , V_129 ) ;
F_105 ( & V_25 -> V_10 . V_43 ) ;
F_23 ( V_25 , V_106 ) ;
V_126 = F_11 ( V_25 , V_128 ) ;
F_26 ( V_25 , V_106 ) ;
F_106 ( & V_25 -> V_10 . V_43 ) ;
if ( ! ( V_126 & V_130 ) ) {
F_54 ( L_14 ) ;
F_54 ( L_15 ) ;
F_94 ( V_25 , V_107 ,
V_127 , V_131 ) ;
}
} else if ( F_41 ( V_25 ) ) {
V_25 -> V_10 . V_44 . V_52 =
F_23 ;
V_25 -> V_10 . V_44 . V_45 =
F_26 ;
F_94 ( V_25 , V_107 ,
V_127 , V_131 ) ;
}
F_4 ( V_25 -> V_10 . V_22 == 0 ) ;
}
static int F_107 ( struct V_132 * V_133 ,
unsigned long V_134 , void * V_103 )
{
struct V_5 * V_25 = F_32 ( V_133 ,
struct V_5 , V_10 . V_73 ) ;
switch ( V_134 ) {
case V_135 :
F_74 ( V_25 , V_136 ) ;
break;
case V_137 :
F_79 ( V_25 , V_136 ) ;
break;
}
return V_138 ;
}
void F_108 ( struct V_5 * V_25 )
{
F_109 ( V_25 ) ;
F_51 ( V_25 ) ;
F_98 ( V_25 ) ;
F_61 ( V_25 , false ) ;
V_25 -> V_10 . V_139 = 1 ;
V_25 -> V_10 . V_73 . V_140 =
F_107 ;
if ( F_110 ( V_25 , 2 , 4 ) || F_99 ( V_25 ) ) {
F_111 ( V_141 ) ;
F_112 ( V_141 ) ;
} else if ( F_113 ( V_25 ) ) {
F_111 ( V_142 ) ;
F_112 ( V_142 ) ;
} else if ( F_110 ( V_25 , 6 , 7 ) ) {
F_111 ( V_143 ) ;
if ( F_29 ( V_25 ) ) {
F_114 ( V_144 ) ;
F_112 ( V_145 ) ;
} else {
F_112 ( V_143 ) ;
}
} else if ( F_115 ( V_25 ) ) {
if ( F_60 ( V_25 ) ) {
F_114 ( V_146 ) ;
F_111 ( V_145 ) ;
F_112 ( V_145 ) ;
} else {
F_111 ( V_147 ) ;
F_112 ( V_143 ) ;
}
} else {
F_114 ( V_148 ) ;
F_111 ( V_145 ) ;
F_112 ( V_145 ) ;
if ( F_116 ( V_25 ) ) {
V_25 -> V_10 . V_44 . V_149 =
V_150 ;
V_25 -> V_10 . V_44 . V_151 =
V_152 ;
V_25 -> V_10 . V_44 . V_153 =
V_154 ;
}
}
F_68 (
& V_25 -> V_10 . V_73 ) ;
F_69 ( V_25 ) ;
}
void F_117 ( struct V_5 * V_25 )
{
F_66 (
& V_25 -> V_10 . V_73 ) ;
F_70 ( V_25 ) ;
F_36 ( V_25 , false ) ;
}
int F_118 ( struct V_155 * V_156 ,
void * V_103 , struct V_157 * V_158 )
{
struct V_5 * V_25 = F_119 ( V_156 ) ;
struct V_159 * V_84 = V_103 ;
struct V_160 const * V_77 = V_161 ;
unsigned V_162 ;
T_3 V_163 , V_164 ;
int V_165 , V_33 = 0 ;
for ( V_165 = 0 ; V_165 < F_3 ( V_161 ) ; V_165 ++ , V_77 ++ ) {
if ( F_84 ( V_77 -> V_163 ) == ( V_84 -> V_75 & - V_77 -> V_162 ) &&
( F_120 ( V_25 ) -> V_166 & V_77 -> V_167 ) )
break;
}
if ( V_165 == F_3 ( V_161 ) )
return - V_168 ;
V_163 = V_77 -> V_163 ;
V_164 = V_77 -> V_164 ;
V_162 = V_77 -> V_162 ;
V_162 |= V_84 -> V_75 ^ F_84 ( V_163 ) ;
F_121 ( V_25 ) ;
switch ( V_162 ) {
case 8 | 1 :
V_84 -> V_169 = F_122 ( V_163 , V_164 ) ;
break;
case 8 :
V_84 -> V_169 = F_123 ( V_163 ) ;
break;
case 4 :
V_84 -> V_169 = F_124 ( V_163 ) ;
break;
case 2 :
V_84 -> V_169 = F_125 ( V_163 ) ;
break;
case 1 :
V_84 -> V_169 = F_126 ( V_163 ) ;
break;
default:
V_33 = - V_168 ;
goto V_170;
}
V_170:
F_127 ( V_25 ) ;
return V_33 ;
}
static int F_128 ( struct V_171 * V_172 )
{
T_5 V_173 ;
F_129 ( V_172 , V_174 , & V_173 ) ;
return ( V_173 & V_175 ) == 0 ;
}
static int F_130 ( struct V_5 * V_25 , unsigned V_176 )
{
struct V_171 * V_172 = V_25 -> V_177 . V_172 ;
F_131 ( V_172 , V_174 , V_178 ) ;
F_30 ( 20 ) ;
F_131 ( V_172 , V_174 , 0 ) ;
return F_132 ( F_128 ( V_172 ) , 500 ) ;
}
static int F_133 ( struct V_171 * V_172 )
{
T_5 V_173 ;
F_129 ( V_172 , V_174 , & V_173 ) ;
return ( V_173 & V_178 ) == 0 ;
}
static int F_134 ( struct V_5 * V_25 , unsigned V_176 )
{
struct V_171 * V_172 = V_25 -> V_177 . V_172 ;
F_131 ( V_172 , V_174 , V_178 ) ;
return F_132 ( F_133 ( V_172 ) , 500 ) ;
}
static int F_135 ( struct V_5 * V_25 , unsigned V_176 )
{
struct V_171 * V_172 = V_25 -> V_177 . V_172 ;
int V_33 ;
F_131 ( V_172 , V_174 ,
V_179 | V_178 ) ;
V_33 = F_132 ( F_133 ( V_172 ) , 500 ) ;
if ( V_33 )
return V_33 ;
F_136 ( V_180 , F_124 ( V_180 ) | V_181 ) ;
F_137 ( V_180 ) ;
F_131 ( V_172 , V_174 ,
V_182 | V_178 ) ;
V_33 = F_132 ( F_133 ( V_172 ) , 500 ) ;
if ( V_33 )
return V_33 ;
F_136 ( V_180 , F_124 ( V_180 ) & ~ V_181 ) ;
F_137 ( V_180 ) ;
F_131 ( V_172 , V_174 , 0 ) ;
return 0 ;
}
static int F_138 ( struct V_5 * V_25 ,
unsigned V_176 )
{
int V_33 ;
F_136 ( V_183 ,
V_184 | V_185 ) ;
V_33 = F_139 ( V_25 ,
V_183 , V_185 , 0 ,
500 ) ;
if ( V_33 )
return V_33 ;
F_136 ( V_183 ,
V_186 | V_185 ) ;
V_33 = F_139 ( V_25 ,
V_183 , V_185 , 0 ,
500 ) ;
if ( V_33 )
return V_33 ;
F_136 ( V_183 , 0 ) ;
return 0 ;
}
static int F_140 ( struct V_5 * V_25 ,
T_1 V_187 )
{
F_6 ( V_25 , V_188 , V_187 ) ;
return F_141 ( V_25 ,
V_188 , V_187 , 0 ,
500 ) ;
}
static int F_142 ( struct V_5 * V_25 ,
unsigned V_176 )
{
struct V_189 * V_190 ;
const T_1 V_191 [ V_192 ] = {
[ V_193 ] = V_194 ,
[ V_195 ] = V_196 ,
[ V_197 ] = V_198 ,
[ V_199 ] = V_200 ,
[ V_201 ] = V_202 ,
} ;
T_1 V_203 ;
int V_33 ;
if ( V_176 == V_204 ) {
V_203 = V_205 ;
} else {
unsigned int V_23 ;
V_203 = 0 ;
F_143 (engine, dev_priv, engine_mask, tmp)
V_203 |= V_191 [ V_190 -> V_2 ] ;
}
V_33 = F_140 ( V_25 , V_203 ) ;
F_36 ( V_25 , true ) ;
return V_33 ;
}
int F_141 ( struct V_5 * V_25 ,
T_3 V_84 ,
const T_1 V_46 ,
const T_1 V_206 ,
const unsigned long V_207 )
{
#define F_144 ((I915_READ_FW(reg) & mask) == value)
int V_33 = F_145 ( F_144 , 2 ) ;
if ( V_33 )
V_33 = F_132 ( F_144 , V_207 ) ;
return V_33 ;
#undef F_144
}
int F_139 ( struct V_5 * V_25 ,
T_3 V_84 ,
const T_1 V_46 ,
const T_1 V_206 ,
const unsigned long V_207 )
{
unsigned V_50 =
F_146 ( V_25 , V_84 , V_208 ) ;
int V_33 ;
F_74 ( V_25 , V_50 ) ;
V_33 = F_145 ( ( F_147 ( V_84 ) & V_46 ) == V_206 , 2 ) ;
F_79 ( V_25 , V_50 ) ;
if ( V_33 )
V_33 = F_132 ( ( F_148 ( V_84 ) & V_46 ) == V_206 ,
V_207 ) ;
return V_33 ;
}
static int F_149 ( struct V_189 * V_190 )
{
struct V_5 * V_25 = V_190 -> V_6 ;
int V_33 ;
F_150 ( F_151 ( V_190 -> V_209 ) ,
F_101 ( V_210 ) ) ;
V_33 = F_141 ( V_25 ,
F_151 ( V_190 -> V_209 ) ,
V_211 ,
V_211 ,
700 ) ;
if ( V_33 )
F_12 ( L_16 , V_190 -> V_212 ) ;
return V_33 ;
}
static void F_152 ( struct V_189 * V_190 )
{
struct V_5 * V_25 = V_190 -> V_6 ;
F_150 ( F_151 ( V_190 -> V_209 ) ,
F_100 ( V_210 ) ) ;
}
static int F_153 ( struct V_5 * V_25 ,
unsigned V_176 )
{
struct V_189 * V_190 ;
unsigned int V_23 ;
F_143 (engine, dev_priv, engine_mask, tmp)
if ( F_149 ( V_190 ) )
goto V_213;
return F_142 ( V_25 , V_176 ) ;
V_213:
F_143 (engine, dev_priv, engine_mask, tmp)
F_152 ( V_190 ) ;
return - V_214 ;
}
static T_6 F_154 ( struct V_5 * V_25 )
{
if ( ! V_6 . V_215 )
return NULL ;
if ( F_120 ( V_25 ) -> V_216 >= 8 )
return F_153 ;
else if ( F_120 ( V_25 ) -> V_216 >= 6 )
return F_142 ;
else if ( F_113 ( V_25 ) )
return F_138 ;
else if ( F_155 ( V_25 ) )
return F_135 ;
else if ( F_156 ( V_25 ) || F_157 ( V_25 ) )
return F_134 ;
else if ( F_120 ( V_25 ) -> V_216 >= 3 )
return F_130 ;
else
return NULL ;
}
int F_158 ( struct V_5 * V_25 , unsigned V_176 )
{
T_6 V_215 ;
int V_33 ;
V_215 = F_154 ( V_25 ) ;
if ( V_215 == NULL )
return - V_217 ;
F_74 ( V_25 , V_136 ) ;
V_33 = V_215 ( V_25 , V_176 ) ;
F_79 ( V_25 , V_136 ) ;
return V_33 ;
}
bool F_159 ( struct V_5 * V_25 )
{
return F_154 ( V_25 ) != NULL ;
}
int F_160 ( struct V_5 * V_25 )
{
int V_33 ;
unsigned long V_42 ;
if ( ! F_161 ( V_25 ) )
return - V_168 ;
F_74 ( V_25 , V_136 ) ;
F_34 ( & V_25 -> V_10 . V_43 , V_42 ) ;
V_33 = F_140 ( V_25 , V_218 ) ;
F_35 ( & V_25 -> V_10 . V_43 , V_42 ) ;
F_79 ( V_25 , V_136 ) ;
return V_33 ;
}
bool F_162 ( struct V_5 * V_25 )
{
return F_58 ( V_25 ) ;
}
bool
F_163 ( struct V_5 * V_25 )
{
if ( F_164 ( V_6 . V_90 ||
V_25 -> V_10 . V_139 <= 0 ) )
return false ;
if ( F_164 ( F_162 ( V_25 ) ) ) {
F_63 ( L_17
L_18
L_19 ) ;
V_6 . V_90 ++ ;
V_25 -> V_10 . V_139 -- ;
return true ;
}
return false ;
}
static enum V_21
F_165 ( struct V_5 * V_25 ,
T_3 V_84 )
{
T_1 V_75 = F_84 ( V_84 ) ;
enum V_21 V_22 ;
if ( F_166 ( V_25 ) ) {
V_22 = F_167 ( V_75 ) ;
} else if ( F_50 ( V_25 ) >= 6 ) {
V_22 = F_168 ( V_75 ) ;
} else {
F_4 ( ! F_110 ( V_25 , 2 , 5 ) ) ;
V_22 = 0 ;
}
F_4 ( V_22 & ~ V_25 -> V_10 . V_22 ) ;
return V_22 ;
}
static enum V_21
F_169 ( struct V_5 * V_25 ,
T_3 V_84 )
{
T_1 V_75 = F_84 ( V_84 ) ;
enum V_21 V_22 ;
if ( F_166 ( V_25 ) && ! F_29 ( V_25 ) ) {
V_22 = F_170 ( V_75 ) ;
} else if ( F_115 ( V_25 ) ) {
V_22 = F_171 ( V_75 ) ;
} else if ( F_110 ( V_25 , 6 , 7 ) ) {
V_22 = V_106 ;
} else {
F_4 ( ! F_110 ( V_25 , 2 , 5 ) ) ;
V_22 = 0 ;
}
F_4 ( V_22 & ~ V_25 -> V_10 . V_22 ) ;
return V_22 ;
}
enum V_21
F_146 ( struct V_5 * V_25 ,
T_3 V_84 , unsigned int V_219 )
{
enum V_21 V_22 = 0 ;
F_4 ( ! V_219 ) ;
if ( F_99 ( V_25 ) )
return 0 ;
if ( V_219 & V_208 )
V_22 = F_165 ( V_25 , V_84 ) ;
if ( V_219 & V_220 )
V_22 |= F_169 ( V_25 , V_84 ) ;
return V_22 ;
}
